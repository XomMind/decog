"""Prepare private VS2010 STL copies whose runtime bodies remain opaque declarations.

These headers are for the experimental retail-backed hybrid only. They must not
be used for the byte-matching build or a standalone/native port.
"""
from pathlib import Path
from tree_sitter import Language, Parser
import tree_sitter_cpp
import json
import re


STL_HEADERS = ('algorithm allocators array bitset complex deque exception forward_list fstream '
               'functional hash_map hash_set iomanip iostream iterator limits list locale map '
               'memory new numeric queue random regex set sstream stack stdexcept streambuf '
               'string strstream system_error tuple type_traits typeindex typeinfo unordered_map '
               'unordered_set utility valarray vector').split()


def _leaf_declarator(node):
    declarator = node.child_by_field_name('declarator')
    while declarator:
        child = declarator.child_by_field_name('declarator')
        if not child:
            return declarator
        declarator = child
    return None


def _parser_source(raw):
    # Keep byte offsets intact while exposing MSVC's constructor/namespace grammar.
    replacements = {b'_STD_BEGIN': b'namespace{', b'_STD_END': b'}',
                    b'_STDEXT_BEGIN': b'namespace{', b'_STDEXT_END': b'}',
                    b'_ALLOCATOR': b'allocator', b'_THROW0()': b'throw()',
                    b'_TRY_IO_BEGIN': b'{', b'_CATCH_IO_END': b'}',
                    b'_TRY_BEGIN': b'{', b'_CATCH_ALL': b'}{', b'_CATCH_END': b'}'}
    for token, replacement in replacements.items():
        raw = raw.replace(token, replacement.ljust(len(token)))
    raw = re.sub(rb'\b(?:__CLR_OR_THIS_CALL|__CLRCALL_OR_CDECL|__CLRCALL_PURE_OR_CDECL|'
                 rb'__CLRCALL_OR_CDECL|_CRTIMP\w*|_MRTIMP\w*|_PURE_APPDOMAIN_GLOBAL|'
                 rb'__PURE_APPDOMAIN_GLOBAL)\b', lambda match: b' ' * len(match[0]), raw)
    return raw


def prepare_stl_headers(destination, compiler_home, preprocessed):
    include = Path(compiler_home) / 'msvc/vc/Program Files/Microsoft Visual Studio 10.0/VC/include'
    destination = Path(destination)
    destination.mkdir(parents=True, exist_ok=True)
    parser = Parser(Language(tree_sitter_cpp.language()))
    expanded = Path(preprocessed).read_bytes()
    locations = []
    filename, line = None, 0
    for physical in expanded.splitlines():
        directive = re.match(rb'\s*#line (\d+) "(.+)"', physical)
        if directive:
            filename = json.loads('"' + directive[2].decode('latin1') + '"').replace('\\', '/')
            line = int(directive[1])
            locations.append(None)
        else:
            locations.append((filename, line))
            line += 1
    tree = parser.parse(expanded)
    stack = [tree.root_node]
    originals, raw_trees, raw_functions, edits = {}, {}, {}, {}
    skipped = {}
    while stack:
        node = stack.pop()
        stack.extend(node.children)
        if node.type != 'function_definition':
            continue
        declarator = _leaf_declarator(node)
        if not declarator:
            continue
        location = locations[declarator.start_point.row]
        if not location:
            continue
        filename, line = location
        if not filename or not filename.lower().rsplit('/', 1)[0].endswith('/vc/include'):
            continue
        name = filename.rsplit('/', 1)[1]
        if '.' in name:
            continue  # C runtime/intrinsic wrappers do not use placeholder template payloads.
        if name not in originals:
            originals[name] = (include / name).read_bytes()
            raw_trees[name] = parser.parse(_parser_source(originals[name]))
            pending = [raw_trees[name].root_node]
            raw_functions[name] = []
            while pending:
                raw_node = pending.pop()
                pending.extend(raw_node.children)
                body = raw_node.child_by_field_name('body')
                if raw_node.type == 'function_definition' and body and body.type == 'compound_statement':
                    raw_functions[name].append(raw_node)
        spelling = re.sub(rb'\s+', b'', declarator.text)
        candidates = []
        for raw_node in raw_functions[name]:
            body = raw_node.child_by_field_name('body')
            if raw_node.start_point.row <= line - 1 <= body.start_point.row:
                raw_declarator = _leaf_declarator(raw_node)
                if raw_declarator and spelling == re.sub(rb'\s+', b'', raw_declarator.text):
                    candidates.append(raw_node)
        if node.has_error or len(candidates) != 1 or candidates[0].has_error:
            skipped[(name, line)] = {'header': name, 'line': line,
                                    'reason': 'unparsed or macro-expanded definition'}
            continue
        raw_node = candidates[0]
        raw_declarator = _leaf_declarator(raw_node)
        body = raw_node.child_by_field_name('body')
        expanded_body = node.child_by_field_name('body')
        end_location = locations[expanded_body.end_point.row] if expanded_body else None
        source_lines = originals[name].splitlines(keepends=True)
        if not end_location or end_location[0] != filename or not 0 < end_location[1] <= len(source_lines):
            skipped[(name, line)] = {'header': name, 'line': line, 'reason': 'unmapped compiler body end'}
            continue
        end_row = end_location[1] - 1
        if body.end_point.row != end_row:
            skipped[(name, line)] = {'header': name, 'line': line, 'reason': 'parser/compiler body span disagreement'}
            continue
        closing = source_lines[end_row].rfind(b'}')
        if closing < 0:
            skipped[(name, line)] = {'header': name, 'line': line, 'reason': 'macro-generated closing brace'}
            continue
        body_end = sum(map(len, source_lines[:end_row])) + closing + 1
        if body_end <= body.start_byte:
            raise ValueError('Compiler function span does not contain raw body: %s:%d' % (name, line))
        if raw_declarator and raw_declarator.type == 'qualified_identifier':
            # Existing member declaration remains; do not emit an illegal out-of-class redeclaration.
            outer = raw_node
            while outer.parent and outer.parent.type == 'template_declaration':
                outer = outer.parent
            begin, end, replacement = outer.start_byte, body_end, b''
        else:
            initializer = next((child for child in raw_node.children
                                if child.type == 'field_initializer_list'), None)
            begin, end = (initializer.start_byte if initializer else body.start_byte), body_end
            replacement = b';'
        edits.setdefault(name, {})[(begin, end)] = replacement
    report = []
    for name, raw in sorted(originals.items()):
        intervals = []
        for interval, replacement in sorted(edits.get(name, {}).items(), key=lambda row: (row[0][0], -row[0][1])):
            begin, end = interval
            if intervals and begin < intervals[-1][0][1]:
                if end <= intervals[-1][0][1]:
                    continue  # Removing an outer function also removes its nested local definitions.
                raise ValueError('Partially overlapping structural declarations in %s' % name)
            intervals.append((interval, replacement))
        for (begin, end), replacement in reversed(intervals):
            raw = raw[:begin] + replacement + raw[end:]
        (destination / name).write_bytes(raw)
        report.append({'header': name, 'functions': len(intervals)})
    if not report:
        raise ValueError('No VS2010 STL source locations found in %s' % preprocessed)
    return {'headers': report, 'skipped': list(skipped.values())}


if __name__ == '__main__':
    import argparse
    import json
    import os
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('destination')
    parser.add_argument('preprocessed')
    parser.add_argument('--compiler-home', default=os.environ.get('COGMIND_WINE_HOME', str(Path.home() / '.cogmind-wine')))
    arguments = parser.parse_args()
    report = prepare_stl_headers(arguments.destination, arguments.compiler_home, arguments.preprocessed)
    (Path(arguments.destination) / 'opaque-report.json').write_text(json.dumps(report, indent=2))
    print('Headers=%d declarations=%d skipped=%d' %
          (len(report['headers']), sum(row['functions'] for row in report['headers']), len(report['skipped'])))
