"""Shorten Ghidra C output of the exe for reading: STL template spellings -> short names, drop the long
local-variable declaration block (kept as a count), join split call lines.
   usage: simplify.py in.c > out.c"""
import sys, re

SUBS = [
    (r'std::basic_string<char,std::char_traits<char>,std::allocator<char>_>', 'string'),
    (r'basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>', 'string'),
    (r'basic_string<char,std::char_traits<char>,std::allocator<char>_>', 'string'),
    (r'class_std::string_', 'string'),
    (r'std::operator\+<char,std::char_traits<char>,std::allocator<char>_>', 'operator+'),
    (r'std::operator==<char,std::char_traits<char>,std::allocator<char>_>', 'operator=='),
    (r'string::string<char,std::char_traits<char>,std::allocator<char>_>', 'string::string'),
    (r'string::~string<char,std::char_traits<char>,std::allocator<char>_>', 'string::~string'),
    (r'std::vector<([\w:* ]+?),std::allocator<\1>_>', r'vector<\1>'),
    (r'vector<([\w:* ]+?),std::allocator<\1>_>', r'vector<\1>'),
    (r'std::allocator<[^<>]*>_', 'alloc'),
]

def main(path):
    text = open(path).read()
    for a, b in SUBS: text = re.sub(a, b, text)
    # join continuation lines of calls split by the printer
    text = re.sub(r'::\n\s+', '::', text)
    text = re.sub(r'\(\s*\n\s+', '(', text)
    text = re.sub(r',\s*\n\s+', ',', text)
    text = re.sub(r'\n\s+(\*\)|\)|"[^"\n]*"\))', r'\1', text)
    out = []; decls = 0; inbody = False
    for line in text.splitlines():
        if line.startswith('{'): inbody = True; out.append(line); continue
        if inbody and decls >= 0 and re.match(r'^  [A-Za-z_][\w<>,:* ]*\s\*?\w+( \[\d+\])?;$', line):
            decls += 1; continue
        if inbody and decls > 0 and line.strip() == '':
            out.append('  /* %d locals */' % decls); decls = -1; continue
        out.append(line)
    print('\n'.join(out))

if __name__ == '__main__':
    main(sys.argv[1])
