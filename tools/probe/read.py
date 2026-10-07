import sys, re, pefile, capstone
sys.path.insert(0,'tools'); import lverify
d=sys.argv[1]
lverify.DLL, lverify.MAP = d+'/match.dll', d+'/match.map'
mp = lverify.load_map()
pe = pefile.PE(lverify.DLL)
base = pe.OPTIONAL_HEADER.ImageBase
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
def offsets(fn, n):
    va = mp[fn]; code = pe.get_data(va - base, 4000)
    offs = []
    for i in md.disasm(code, va):
        m = re.match(r'(?:lea|mov) \w+, \[ebp - (0x[0-9a-f]+|\d+)\]', i.mnemonic + ' ' + i.op_str)
        if i.mnemonic == 'lea' and m: offs.append(int(m.group(1), 0))
        if i.mnemonic == 'ret': break
    return offs[:n]
names=[l.strip() for l in open(sys.argv[2])]
for fn in sys.argv[3:]:
    o = offsets(fn, len(names))
    print(fn, sorted(zip(o, names)))
