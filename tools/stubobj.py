"""Write a COFF object defining each given symbol as a distinct 16-byte slot in .data.
   Used to satisfy references to not-yet-reconstructed functions/globals so an LTCG link
   succeeds; the map then names every call/data target, which is all lverify needs."""
import struct

def write(path, names):
    names = sorted(set(names))
    secdata = b'\0' * (16 * len(names))
    strtab = bytearray(b'\0\0\0\0')
    syms = bytearray()
    def symname(n):
        b = n.encode('latin1')
        if len(b) <= 8: return b.ljust(8, b'\0')
        off = len(strtab); strtab.extend(b + b'\0'); return struct.pack('<II', 0, off)
    # section symbol + aux
    syms += b'.data\0\0\0' + struct.pack('<IhHBB', 0, 1, 0, 3, 1)
    syms += struct.pack('<IHHIHBB', len(secdata), 0, 0, 0, 0, 0, 0) + b'\0' * 2
    for i, n in enumerate(names):
        syms += symname(n) + struct.pack('<IhHBB', 16 * i, 1, 0, 2, 0)
    nsyms = 2 + len(names)
    hdr_size = 20 + 40
    sec_ptr = hdr_size
    sym_ptr = sec_ptr + len(secdata)
    out = struct.pack('<HHIIIHH', 0x14c, 1, 0, sym_ptr, nsyms, 0, 0)
    out += b'.data\0\0\0' + struct.pack('<IIIIIIHHI', 0, 0, len(secdata), sec_ptr, 0, 0, 0, 0, 0xC0300040)
    struct.pack_into('<I', strtab, 0, len(strtab))
    open(path, 'wb').write(out + secdata + bytes(syms) + bytes(strtab))
