#!/usr/bin/env python3
"""Prepare external XomMind harness checkouts for native Windows operation.

Only modifies the explicitly supplied external checkouts; never game files.
"""
import argparse
from pathlib import Path
import re
import subprocess
import xml.etree.ElementTree as ET


def replace_file(path, before, after):
    text = path.read_text(encoding="utf-8")
    if after and after in text:
        return
    if not after and before not in text:
        return
    if before not in text:
        raise RuntimeError(f"Upstream changed: missing patch anchor in {path}: {before[:80]}")
    path.write_text(text.replace(before, after), encoding="utf-8")


def prepare(statmind, cogbench, sdl):
    cargo = statmind / "Cargo.toml"
    text = cargo.read_text()
    marker = '[target.\'cfg(target_os = "windows")\'.dependencies]'
    if marker not in text:
        text = text.replace('mach = "0.3.2"\n', '')
        text = text.replace('[target.\'cfg(target_os = "macos")\'.dependencies]', marker + '\nwinapi = { version = "0.3.9", features = ["memoryapi", "winnt"] }\n\n[target.\'cfg(target_os = "macos")\'.dependencies]\nmach = "0.3.2"')
        cargo.write_text(text)
    common = statmind / "src/common.rs"
    replace_file(common, '#[cfg(not(any(target_os = "macos", target_os = "linux")))]',
                 '#[cfg(not(any(target_os = "macos", target_os = "linux", target_os = "windows")))]')
    text = common.read_text(encoding="utf-8")
    marker = '// BEGIN decog native Windows adapter'
    text = text.split(marker)[0].rstrip()
    common.write_text(text + '\n' + marker + '\n' + Path(__file__).with_name('windows_harness_common.rs').read_text(), encoding="utf-8")
    scan = statmind / 'src/scan.rs'
    replace_file(scan, '#[cfg(not(target_os = "macos"))]', '#[cfg(not(any(target_os = "macos", target_os = "windows")))]')
    text = scan.read_text()
    marker = '// BEGIN decog Windows region enumeration'
    text = text.split(marker)[0].rstrip()
    scan.write_text(text + '\n' + marker + '\n#[cfg(target_os = "windows")]\nfn writable_regions(handle: &ProcessHandle) -> Result<Vec<(u64, u64)>> { crate::common::windows_writable_regions(handle) }\n')
    # Only bytes through the last decoded u32 at +0xA0 are required. Reading
    # 0xC0 can straddle an inaccessible page after an otherwise valid Cell.
    replace_file(statmind / 'src/cells.rs', 'pub const CELL_READ_LEN: usize = 0xC0;', 'pub const CELL_READ_LEN: usize = 0xA4;')
    main = statmind / "src/main.rs"
    replace_file(main, '    mcp: bool,', '    mcp: bool,\n    #[arg(long)]\n    pid: Option<u32>,')
    replace_file(main, '    let process = native_process.or(wine_process);',
                 '    let process = if let Some(pid) = args.pid { sys.process(sysinfo::Pid::from_u32(pid)) } else { native_process.or(wine_process) };')
    replace_file(main, '        error!("No process found...");', '        return Err(anyhow!("No matching game process found; pass --pid for a specific instance"));')
    replace_file(main, '#[cfg(not(target_os = "macos"))]\n        let task_port = pid as u32;',
                 '#[cfg(target_os = "linux")]\n        let task_port = pid as u32;\n        #[cfg(target_os = "windows")]\n        let task_port = {\n            use process_memory::TryIntoProcessHandle;\n            (pid as u32).try_into_process_handle()?.0\n        };')
    # The upstream daemon uses Unix sockets. Loopback TCP works in Windows Python.
    cb = cogbench / "cogbench.py"
    replace_file(cb, 'SOCK = os.environ.get("COGBENCH_SOCK", "/tmp/cogbench.sock")',
                 'TCP = os.name == "nt" or bool(os.environ.get("COGBENCH_TCP"))\nSOCK = ("127.0.0.1", int(os.environ.get("COGBENCH_PORT", "31725"))) if TCP else os.environ.get("COGBENCH_SOCK", "/tmp/cogbench.sock")')
    replace_file(cb, 'socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)', 'socket.socket(socket.AF_INET if TCP else socket.AF_UNIX, socket.SOCK_STREAM)')
    replace_file(cb, 'if os.path.exists(SOCK):', 'if not TCP and os.path.exists(SOCK):')
    replace_file(cb, 'os.path.exists(SOCK) and os.unlink(SOCK)', '(not TCP) and os.path.exists(SOCK) and os.unlink(SOCK)')
    replace_file(cb, '[binary, "--mcp"],', '[binary, "--mcp"] + (["--pid", os.environ["STATMIND_PID"]] if os.environ.get("STATMIND_PID") else []),')
    replace_file(cogbench / 'statdump.py', '    p = p.replace("\\\\", "/")', '    if os.name == "nt":\n        return os.path.normpath(p)\n    p = p.replace("\\\\", "/")')
    # No legacy DirectX SDK is needed: WINDIB + waveOut + dummy backends remain.
    cfg = sdl / "include/SDL_config_win32.h"
    (sdl / 'include/SDL_config.h').write_text((sdl / 'include/SDL_config.h.default').read_text())
    for feature in ('SDL_VIDEO_DRIVER_DDRAW', 'SDL_AUDIO_DRIVER_DSOUND', 'SDL_ASSEMBLY_ROUTINES'):
        text = cfg.read_text()
        text = re.sub(r'^#define ' + feature + r'\s+1$', '// disabled by decog native build: ' + feature, text, flags=re.M)
        cfg.write_text(text)
    # SDL's stock dummy backend advertises a 0x0 desktop, which makes Cogmind's
    # font fitting fail before gameplay. Supply a configurable virtual desktop.
    replace_file(sdl / 'src/video/dummy/SDL_nullvideo.c', '\tvformat->BitsPerPixel = 8;', '\tthis->info.current_w = SDL_getenv("STATMIND_DUMMY_WIDTH") ? SDL_atoi(SDL_getenv("STATMIND_DUMMY_WIDTH")) : 1920;\n\tthis->info.current_h = SDL_getenv("STATMIND_DUMMY_HEIGHT") ? SDL_atoi(SDL_getenv("STATMIND_DUMMY_HEIGHT")) : 1080;\n\tvformat->BitsPerPixel = 8;')
    for path in (sdl / 'src').glob('statmind*.h'):
        text = path.read_text()
        text = text.replace('__attribute__((dllexport))', '__declspec(dllexport)').replace('__attribute__((used))', '')
        if '__asm__ __volatile__(' in text:
            start = text.index('    __asm__ __volatile__(')
            end = text.index('    (void)ecx;', start)
            text = text[:start] + '''    __asm {
        mov ecx, self
        push a2
        push a1
        call fn
        mov ret, eax
    }
''' + text[end:]
        if 'static void *Statmind_ThisCall2' in text:
            start = text.index('static void *Statmind_ThisCall2')
            end = text.index('static int Statmind_ResolveScoresheet', start)
            text = text[:start] + re.sub(r'\bret\b', 'result', text[start:end]) + text[end:]
        path.write_text(text)


def build_sdl(sdl, output, vcvars):
    output.mkdir(parents=True, exist_ok=True)
    project = sdl / 'VisualC/SDL/SDL.vcproj'
    sources = []
    for elem in ET.parse(project).iter('File'):
        name = elem.attrib.get('RelativePath', '')
        if name.endswith('.c') and not any(part in name.lower() for part in ('\\directx\\', '\\windx5\\', '\\windx', '\\dx5\\')):
            sources.append((project.parent / name.replace('\\', '/')).resolve())
    rsp = output / 'sdl.rsp'
    args = ['/nologo', '/LD', '/O2', '/MT', '/FIwindows.h', '/D_CRT_SECURE_NO_WARNINGS', '/D_WIN32_WINNT=0x0601', '/D_WINDOWS', '/DNDEBUG', '/D_SDL_BUILDING_LIBRARY',
            f'/I"{sdl / "include"}"']
    args += ['"' + str(path) + '"' for path in sources]
    args += ['/link', f'/OUT:"{output / "SDL.dll"}"', 'user32.lib', 'gdi32.lib', 'winmm.lib', 'advapi32.lib', '/MACHINE:X86']
    rsp.write_text(' '.join(args), encoding='utf-8')
    batch = output / 'build-sdl.cmd'
    batch.write_text(f'@echo off\ncall "{vcvars}" x86\nif errorlevel 1 exit /b %errorlevel%\ncl @"{rsp}"\n', encoding='utf-8')
    subprocess.run(['cmd', '/d', '/c', str(batch)], cwd=output, check=True)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--statmind', type=Path, required=True)
    p.add_argument('--cogbench', type=Path, required=True)
    p.add_argument('--sdl', type=Path, required=True)
    p.add_argument('--build-statmind', action='store_true')
    p.add_argument('--build-sdl', type=Path, metavar='OUTPUT')
    p.add_argument('--vcvars', type=Path, default=Path('C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Auxiliary/Build/vcvarsall.bat'))
    args = p.parse_args()
    prepare(args.statmind.resolve(), args.cogbench.resolve(), args.sdl.resolve())
    if args.build_statmind:
        subprocess.run(['cargo', 'build', '--release'], cwd=args.statmind, check=True)
    if args.build_sdl:
        build_sdl(args.sdl.resolve(), args.build_sdl.resolve(), args.vcvars)


if __name__ == '__main__':
    main()
