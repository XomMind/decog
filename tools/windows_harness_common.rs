// Windows implementation inserted into the external StatMind checkout.
#[cfg(target_os = "windows")]
fn scan_windows_magic(handle: &ProcessHandle, magic: u32, check: u32, writable: bool) -> anyhow::Result<usize> {
    use winapi::um::{memoryapi::VirtualQueryEx, winnt::{MEMORY_BASIC_INFORMATION, MEM_COMMIT, PAGE_GUARD, PAGE_NOACCESS, PAGE_READWRITE, PAGE_WRITECOPY, PAGE_EXECUTE_READWRITE, PAGE_EXECUTE_WRITECOPY}};
    let needle = [magic.to_le_bytes(), check.to_le_bytes()].concat();
    let mut address = 0usize;
    while address < 0x1_0000_0000usize {
        let mut region: MEMORY_BASIC_INFORMATION = unsafe { mem::zeroed() };
        if unsafe { VirtualQueryEx(handle.0, address as _, &mut region, mem::size_of_val(&region)) } == 0 { break; }
        let start = region.BaseAddress as usize;
        let end = start.saturating_add(region.RegionSize).min(0x1_0000_0000usize);
        let can_write = region.Protect & (PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY) != 0;
        if region.State == MEM_COMMIT && region.Protect & (PAGE_GUARD | PAGE_NOACCESS) == 0 && (!writable || can_write) {
            let mut current = start;
            while current < end {
                let size = (64 * 1024).min(end - current);
                if let Ok(bytes) = copy_address(current, size, handle) {
                    if let Some(offset) = bytes.windows(8).position(|bytes| bytes == needle.as_slice()) { return Ok(current + offset); }
                }
                if size <= 8 { break; }
                current += size - 8;
            }
        }
        if end <= address { break; }
        address = end;
    }
    Err(anyhow!("memory magic 0x{magic:08X}/0x{check:08X} not found"))
}

#[cfg(target_os = "windows")]
pub fn set_memory_writable(handle: &ProcessHandle, address: usize, size: usize) -> anyhow::Result<(), Error> {
    // Mailbox storage is already writable. Check it rather than changing page protections.
    use winapi::um::{memoryapi::VirtualQueryEx, winnt::{MEMORY_BASIC_INFORMATION, MEM_COMMIT, PAGE_GUARD, PAGE_READWRITE, PAGE_WRITECOPY, PAGE_EXECUTE_READWRITE, PAGE_EXECUTE_WRITECOPY}};
    let mut region: MEMORY_BASIC_INFORMATION = unsafe { mem::zeroed() };
    let end = address.checked_add(size).ok_or_else(|| anyhow!("address overflow"))?;
    let found = unsafe { VirtualQueryEx(handle.0, address as _, &mut region, mem::size_of_val(&region)) };
    if found != 0 && region.State == MEM_COMMIT && region.Protect & PAGE_GUARD == 0 && region.Protect & (PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY) != 0 && end <= (region.BaseAddress as usize).saturating_add(region.RegionSize) { Ok(()) }
    else { Err(anyhow!("mailbox range is not writable")) }
}

#[cfg(target_os = "windows")]
fn cached_windows_magic(handle: &ProcessHandle, cache: &Mutex<Option<usize>>, magic: u32, check: u32, writable: bool) -> anyhow::Result<usize> {
    let mut cached = cache.lock().unwrap();
    if let Some(address) = *cached { return Ok(address); }
    let address = scan_windows_magic(handle, magic, check, writable)?;
    *cached = Some(address);
    Ok(address)
}

#[cfg(target_os = "windows")]
pub fn get_base_address(handle: &ProcessHandle) -> anyhow::Result<usize, Error> { cached_windows_magic(handle, get_base_cache(), 0x64AD_FA4C, 0x7953_3ED9, false) }
#[cfg(target_os = "windows")]
pub fn get_mailbox_address(handle: &ProcessHandle) -> anyhow::Result<usize, Error> { cached_windows_magic(handle, get_mailbox_cache(), 0x64AD_FA4D, 0x7953_3ED8, true) }
#[cfg(target_os = "windows")]
pub fn check_ipc_thread_status(handle: &ProcessHandle) -> anyhow::Result<bool, Error> {
    let address = scan_windows_magic(handle, 0xBADB_EEF1, 0x7953_3ED9, false)? + 8;
    let bytes = copy_address(address, 4, handle)?;
    Ok(i32::from_le_bytes(bytes.try_into().map_err(|_| anyhow!("short status read"))?) == 1)
}
#[cfg(target_os = "windows")]
fn scan_magic(handle: &ProcessHandle, magic: u32, check: u32, writable: bool) -> anyhow::Result<usize> { scan_windows_magic(handle, magic, check, writable) }

#[cfg(target_os = "windows")]
pub fn windows_writable_regions(handle: &ProcessHandle) -> anyhow::Result<Vec<(u64, u64)>> {
    use winapi::um::{memoryapi::VirtualQueryEx, winnt::{MEMORY_BASIC_INFORMATION, MEM_COMMIT, PAGE_GUARD, PAGE_READWRITE, PAGE_WRITECOPY, PAGE_EXECUTE_READWRITE, PAGE_EXECUTE_WRITECOPY}};
    let mut regions = Vec::new();
    let mut address = 0usize;
    while address < 0x1_0000_0000usize {
        let mut region: MEMORY_BASIC_INFORMATION = unsafe { mem::zeroed() };
        if unsafe { VirtualQueryEx(handle.0, address as _, &mut region, mem::size_of_val(&region)) } == 0 { break; }
        let start = region.BaseAddress as usize;
        let end = start.saturating_add(region.RegionSize).min(0x1_0000_0000usize);
        if region.State == MEM_COMMIT && region.Protect & PAGE_GUARD == 0 && region.Protect & (PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY) != 0 {
            regions.push((start as u64, end as u64));
        }
        if end <= address { break; }
        address = end;
    }
    Ok(regions)
}

#[cfg(all(test, target_os = "windows", target_pointer_width = "64"))]
mod windows_tests {
    use super::*;
    use process_memory::{Architecture, TryIntoProcessHandle};
    use winapi::um::{memoryapi::{VirtualAlloc, VirtualFree}, winnt::{MEM_RESERVE, MEM_COMMIT, MEM_RELEASE, PAGE_READWRITE}};

    #[test]
    fn discovers_magic_across_chunk_boundary_and_checks_writable_memory() {
        let memory = unsafe { VirtualAlloc(0x20000000usize as _, 128 * 1024, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE) };
        assert!(!memory.is_null(), "low-address fixture allocation failed");
        let address = memory as usize + 65532;
        let handle = (std::process::id()).try_into_process_handle().unwrap();
        let handle = (handle.0, Architecture::Arch32Bit);
        handle.put_address(address, &[0x21, 0x43, 0x65, 0x87, 0x98, 0xBA, 0xDC, 0xFE]).unwrap();
        assert_eq!(scan_windows_magic(&handle, 0x87654321, 0xFEDCBA98, true).unwrap(), address);
        set_memory_writable(&handle, address, 8).unwrap();
        assert!(set_memory_writable(&handle, address, usize::MAX).is_err());
        unsafe { VirtualFree(memory, 0, MEM_RELEASE); }
    }
}
