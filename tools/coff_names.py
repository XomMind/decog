import struct
def names(path):
    d = open(path, 'rb').read()
    symptr, nsym = struct.unpack_from('<II', d, 8)
    strtab = symptr + 18 * nsym
    out, i = [], 0
    while i < nsym:
        b = d[symptr + 18 * i: symptr + 18 * (i + 1)]
        if b[:4] == b'\0\0\0\0':
            o = struct.unpack_from('<I', b, 4)[0]; n = d[strtab + o: d.index(b'\0', strtab + o)].decode('latin1')
        else: n = b[:8].rstrip(b'\0').decode('latin1')
        if b[16] == 2 and struct.unpack_from('<h', b, 12)[0] > 0: out.append(n)
        i += 1 + b[17]
    return out
