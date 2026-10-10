"""Reconstruct a runnable Beta 17.1 PE using strictly matched compiler output.

This is an address-preserving reconstruction, NOT a standalone source link.
PE headers, imports, runtime/library functions and global data come from retail.
Every installed body must pass the existing strict verifier AND become byte-exact
after rebasing its validated instruction operands and internal switch tables.
No verification stub is installed. Inputs, coverage and retained bytes are audited.
"""
import argparse
import contextlib
import hashlib
import json
from pathlib import Path
import struct

import capstone
import common
import lverify
import pefile


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def relocate_body(ours, ova, theirs, tva, size):
    """Only patch operands already proved by lverify; never copy retail opcodes."""
    compiled = bytearray(ours.read(ova, size))
    reference = theirs.read(tva, size)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ti = list(md.disasm(reference, tva))
    oi = list(md.disasm(compiled, ova))
    tables = lverify.inline_table_offset(ti, tva, size) or []
    code_size = tables[0][0] if tables else size
    ti = [i for i in ti if i.address < tva + code_size]
    oi = [i for i in oi if i.address < ova + code_size]
    if len(ti) != len(oi) or not ti or ti[-1].address + ti[-1].size != tva + code_size:
        raise ValueError('Incomplete or different instruction extents')
    for a, b in zip(ti, oi):
        if a.size != b.size or a.mnemonic != b.mnemonic:
            raise ValueError('Instruction mismatch')
        af, bf = lverify.operand_fields(a), lverify.operand_fields(b)
        if len(af) != len(bf):
            raise ValueError('Operand count differs')
        for (offset, width, value, relative), (bo, bw, bv, br) in zip(af, bf):
            if (offset, width, relative) != (bo, bw, br):
                raise ValueError('Operand encoding differs')
            # Strict compare has validated identity or literal contents for this operand.
            # Re-encode at the destination address, preserving all non-address bytes.
            if relative:
                value = (value - (a.address + a.size)) & 0xffffffff
            compiled[a.address - tva + offset:a.address - tva + offset + width] = value.to_bytes(width, 'little')
    for start, end, dwords in tables:
        if dwords:
            for offset in range(start, end, 4):
                target = struct.unpack_from('<I', compiled, offset)[0]
                if not ova <= target < ova + code_size:
                    raise ValueError('Switch target outside compiled body')
                struct.pack_into('<I', compiled, offset, target - ova + tva)
    if compiled != reference:
        raise ValueError('Relocated compiler output is not byte-identical')
    return bytes(compiled)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build', type=Path, default=Path('build/full_windows'))
    parser.add_argument('--out', type=Path, default=Path('build/windows/COGMIND-rebuilt.exe'))
    parser.add_argument('--allow-partial', action='store_true', help='Development only: retain unproved game bodies')
    args = parser.parse_args()
    if digest(common.EXE) != common.EXE_SHA256:
        parser.error('Wrong Beta 17.1 reference SHA256')
    if common.mapping_conflicts():
        parser.error('Conflicting mapping identities')
    args.out.parent.mkdir(parents=True, exist_ok=True)
    lverify.DLL, lverify.MAP = str(args.build / 'match.dll'), str(args.build / 'match.map')
    print('Strictly verifying compiler output; diagnostics: ' + str(args.out.parent / 'strict-verify.log'), flush=True)
    with (args.out.parent / 'strict-verify.log').open('w') as log, contextlib.redirect_stdout(log):
        results = lverify.verify_all()
    print('%d/%d mapping rows MATCH; installing proved bodies' % (sum(results.values()), len(results)), flush=True)
    mp, ours, theirs = lverify.CTX['v']
    names = lverify.code_names(mp, ours)
    functions = common.functions()
    installed, failures = {}, []
    raw = bytearray(Path(common.EXE).read_bytes())
    for name, ok in results.items():
        if not ok:
            failures.append(name)
            continue
        tva, size = functions[name]
        if tva in installed:
            continue
        ova = names[name]
        if lverify.is_stub(ours, ova):
            raise RuntimeError('Refusing to install a dependency stub')
        body = relocate_body(ours, ova, theirs, tva, size)
        offset = theirs.pe.get_offset_from_rva(tva - theirs.base)
        raw[offset:offset + size] = body
        installed[tva] = {'name': name, 'va': hex(tva), 'size': size, 'compiled_va': hex(ova),
                          'body_sha256': hashlib.sha256(body).hexdigest()}
        if len(installed) % 5000 == 0:
            print('Relocated and byte-checked %d unique compiled bodies' % len(installed), flush=True)
    # Use the same coverage definition as the strict target audit.
    from classify_targets import coverage
    stats = coverage(results)
    report = {
        'format': 'address-preserving-compiled-body-reconstruction-v1',
        'standalone_source_link': False,
        'retained': 'Retail PE/CRT/vendor libraries/global data and unmatched functions; no match.dll stubs',
        'reference_sha256': digest(common.EXE), 'match_dll_sha256': digest(lverify.DLL),
        'match_map_sha256': digest(lverify.MAP),
        'config_sha256': {str(p.relative_to(Path(common.REPO))): digest(p)
                          for p in sorted((Path(common.REPO) / 'config').rglob('*.csv'))},
        'matched_rows': sum(results.values()), 'diff_rows': len(failures),
        'installed_functions': len(installed), 'installed_bytes': sum(x['size'] for x in installed.values()),
        'coverage': stats, 'functions': list(installed.values()),
        'unmatched_rows': failures, 'output_sha256': hashlib.sha256(raw).hexdigest(),
    }
    report_path = args.out.with_suffix('.json')
    report_path.write_text(json.dumps(report, indent=2))
    # Fail closed on game coverage; surplus alias rows may legitimately DIFF.
    missing = stats['funcs'] - stats['funcs_matched']
    if stats['code_matched'] != stats['code_bytes'] and not args.allow_partial:
        parser.error('Incomplete strict game code-byte coverage; see ' + str(report_path))
    if missing and not args.allow_partial:
        parser.error('%d game functions lack strict compiled-body proof; see %s' % (missing, report_path))
    if not installed:
        parser.error('No compiled bodies available')
    args.out.write_bytes(raw)
    pe = pefile.PE(str(args.out))
    if pe.FILE_HEADER.Machine != 0x14c or pe.OPTIONAL_HEADER.AddressOfEntryPoint != theirs.pe.OPTIONAL_HEADER.AddressOfEntryPoint:
        raise RuntimeError('Invalid Windows x86 executable')
    print(json.dumps({k: report[k] for k in ('installed_functions', 'installed_bytes', 'matched_rows',
                                           'diff_rows', 'coverage', 'output_sha256')}, indent=2))
    print('Reconstructed executable: ' + str(args.out.resolve()))


if __name__ == '__main__':
    main()
