"""Verify compiler-generated string-array EH cleanup using the original unwind maps.
Run with .venv/bin/python src/game/verify_generated_cleanup.py build/game-integrated.
Only exact matches are appended to game_codex.csv. No shared build/tools are changed.
"""
import contextlib
import io
from pathlib import Path
import re
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
import common
import lverify
import pefile


def info(image, handler):
    insns = common.disasm(image.read(handler, 64), handler)
    pointer = next(int(i.op_str.split(', ')[1], 16) for i in insns
                   if i.mnemonic == 'mov' and i.op_str.startswith('eax, 0x'))
    end = next(i.address + i.size for i in insns if i.mnemonic == 'jmp')
    return struct.unpack('<9I', image.read(pointer, 36)), end - handler


def main(directory):
    directory = Path(directory)
    lverify.MAP = str(directory / 'match.map')
    symbols = lverify.load_map()
    ours = lverify.Image(pefile.PE(str(directory / 'match.dll')), lverify.map_names(symbols))
    theirs = lverify.Image(pefile.PE(common.EXE, fast_load=True), lverify.exe_names())
    source = (ROOT / 'src/game/global_string_arrays.cpp').read_text()
    arrays = re.findall(r'// Initializer (0x[\da-f]+), array (0x[\da-f]+), (\d+) x[^\n]*\nstd::string (\w+)', source)
    rows, failed = [], []
    for initializer, original_base, count, name in arrays:
        initializer, original_base, count = int(initializer, 16), int(original_base, 16), int(count)
        header = common.disasm(theirs.read(initializer, 16), initializer)
        original_handler = int(header[3].op_str, 16)
        handler_name = '__ehhandler$??__E' + name + '@@YAXXZ'
        our_handler = symbols[handler_name]
        ti, ts = info(theirs, original_handler)
        oi, os = info(ours, our_handler)
        # Verify all FuncInfo fields, including the full state count/EH flags.
        assert ti[0] == 0x19930522 and ti[1] == count - 1
        assert oi[:2] == ti[:2] and oi[3:] == ti[3:] and os == ts
        our_base = symbols[next(n for n in symbols if n.startswith('?' + name + '@@'))]
        candidates = [(handler_name, original_handler, our_handler, ts)]
        for index in range(count - 1):
            tstate, tfunc = struct.unpack('<iI', theirs.read(ti[2] + index * 8, 8))
            ostate, ofunc = struct.unpack('<iI', ours.read(oi[2] + index * 8, 8))
            assert tstate == ostate == index - 1
            n = '__unwindfunclet$??__E' + name + '@@YAXXZ$' + str(index)
            assert symbols[n] == ofunc
            # The two-instruction cleanup must address the SAME array element.
            tins = common.disasm(theirs.read(tfunc, 10), tfunc)
            oins = common.disasm(ours.read(ofunc, 10), ofunc)
            assert len(tins) == len(oins) == 2
            assert tins[0].mnemonic == oins[0].mnemonic == 'mov'
            assert tins[0].op_str == 'ecx, %#x' % (original_base + index * 28)
            assert oins[0].op_str == 'ecx, %#x' % (our_base + index * 28)
            assert tins[1].mnemonic == oins[1].mnemonic == 'jmp'
            candidates.append((n, tfunc, ofunc, 10))
        for n, tva, ova, size in candidates:
            with contextlib.redirect_stdout(io.StringIO()):
                ok = lverify.compare(n, theirs, tva, ours, ova, size, False)
            (rows if ok else failed).append((n, tva, size))
    path = ROOT / 'config/mapping.d/game_codex.csv'
    existing = {r[0] for r in common.load_csv('mapping.d/game_codex.csv')}
    added = [r for r in rows if r[0] not in existing]
    with path.open('a') as output:
        output.write('# Generated EH handlers/funclets: exact bytes plus unwind-state/element checks.\n')
        for n, va, size in added:
            output.write('%s,%#x,%#x\n' % (n, va, size))
    print('Generated cleanup: %d matched / %d, %d bytes; %d new mappings' %
          (len(rows), len(rows) + len(failed), sum(r[2] for r in rows), len(added)))
    if failed:
        print('Unrecorded failures:', failed[:5])


if __name__ == '__main__':
    main(sys.argv[1])
