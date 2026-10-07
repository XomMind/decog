"""Write a COFF object defining each given symbol as a distinct zero-filled slot (STUB_SLOT bytes, in .bss).
   Used to satisfy references to not-yet-reconstructed functions/globals so an LTCG link
   succeeds; the map then names every call/data target, which is all lverify needs."""
import struct, os

# Slot size per stub. With the old 16-byte slots, an access like [sym+0x30] in our code landed on (or inside) a
# DIFFERENT stub, which lverify then paired (or zero-compared) as if the source had named it. 4 KiB slots give every
# stub room for its field offsets, and lverify pairs [stub+k] with the exe address k bytes after the stub's partner
# (stub_interior). The slots are .bss, so they cost no file space. STUB_SLOT=16 (env) restores the old layout.
SLOT = int(os.environ.get('STUB_SLOT', '4096'), 0)

def write(path, names):
    names = sorted(set(names))
    size = SLOT * len(names)
    secdata = b''   # uninitialized: the slots take no file space, the loader (and lverify's Image.read) zero-fills
    strtab = bytearray(b'\0\0\0\0')
    syms = bytearray()
    def symname(n):
        b = n.encode('latin1')
        if len(b) <= 8: return b.ljust(8, b'\0')
        off = len(strtab); strtab.extend(b + b'\0'); return struct.pack('<II', 0, off)
    # section symbol + aux
    syms += b'.bss\0\0\0\0' + struct.pack('<IhHBB', 0, 1, 0, 3, 1)
    syms += struct.pack('<IHHIHBB', size, 0, 0, 0, 0, 0, 0) + b'\0' * 2
    for i, n in enumerate(names):
        syms += symname(n) + struct.pack('<IhHBB', SLOT * i, 1, 0, 2, 0)
    nsyms = 2 + len(names)
    hdr_size = 20 + 40
    sec_ptr = hdr_size
    sym_ptr = sec_ptr + len(secdata)
    out = struct.pack('<HHIIIHH', 0x14c, 1, 0, sym_ptr, nsyms, 0, 0)
    out += b'.bss\0\0\0\0' + struct.pack('<IIIIIIHHI', 0, 0, size, 0, 0, 0, 0, 0, 0xC0300080)
    struct.pack_into('<I', strtab, 0, len(strtab))
    open(path, 'wb').write(out + secdata + bytes(syms) + bytes(strtab))
