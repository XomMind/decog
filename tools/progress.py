"""Progress report: docs/progress.svg (README badge), docs/progress.html (treemap),
   build/progress.json. Needs build/match.dll (run tools/build.sh first).
   Counts every indexed function in .text, including statically linked libraries
   (CRT, protobuf) until those are classified in config/library.csv."""
import sys, os, json, html, collections, datetime
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import common, funcindex, lverify
from fnsize import fn_size

DATA = {}

def collect():
    st = funcindex.starts()
    functions = common.functions()
    matched = {}
    if os.path.exists(lverify.DLL):
        res = lverify.verify_all(quiet=True)
        DATA.update(lverify.data_stats())
        for name, ok in res.items():
            if ok: matched[functions[name][0]] = name
    named = {}
    for r in common.load_csv('names.csv'): named[int(r[0], 16)] = r[1]
    for name, (va, _) in functions.items(): named.setdefault(va, name)
    lib = {int(r[1], 16) for r in common.load_csv('library.csv')}
    ranges = [(int(r[0], 16), int(r[1], 16)) for r in common.load_csv('library_ranges.csv')]
    funcs = []
    for i, va in enumerate(st):
        end = st[i + 1] if i + 1 < len(st) else va + fn_size(va)
        size = len(common.read_va(va, end - va).rstrip(b'\xcc')) if i + 1 < len(st) else end - va
        state = 'library' if va in lib or any(lo <= va < hi for lo, hi in ranges) else 'matched' if va in matched else 'named' if va in named else 'unknown'
        funcs.append((va, size, state, matched.get(va) or named.get(va) or ''))
    return funcs

def data_sizes():
    """exe bytes the data metric is measured against: .rdata + the initialized part of .data (.bss is not countable)"""
    p = common.pe()
    return sum(s.Misc_VirtualSize if s.Name.rstrip(b'\0') == b'.rdata' else s.SizeOfRawData for s in p.sections if s.Name.rstrip(b'\0') in (b'.rdata', b'.data'))

def is_funclet(name): return name.startswith(('__unwindfunclet$', '__ehhandler$', '__catch$'))

def stats(funcs):
    game = [f for f in funcs if f[2] != 'library']
    fl = [f for f in game if is_funclet(f[3])]
    libs = [f for f in funcs if f[2] == 'library']
    tot_b = sum(f[1] for f in game)
    real = [f for f in game if not is_funclet(f[3])]           # function counts exclude EH funclets
    tot_n = len(real)
    m = [f for f in real if f[2] == 'matched']; nm = [f for f in real if f[2] in ('matched', 'named')]
    mb = sum(f[1] for f in game if f[2] == 'matched')
    return dict(date=datetime.date.today().isoformat(),
                code_bytes=tot_b, code_matched=mb,
                funclets=len(fl), funclets_matched=sum(1 for f in fl if f[2] == 'matched'),
                funcs=tot_n, funcs_matched=len(m), funcs_named=len(nm),
                data_bytes=data_sizes(), data_matched=DATA.get('total', 0), data_detail=DATA,
                lib_funcs=len(libs), lib_bytes=sum(f[1] for f in libs))

def pct(a, b): return 100.0 * a / b if b else 0.0

def badge(s):
    rows = [('Code', pct(s['code_matched'], s['code_bytes']), '%s / %s bytes' % (f"{s['code_matched']:,}", f"{s['code_bytes']:,}")),
            ('Functions', pct(s['funcs_matched'], s['funcs']), '%d / %d' % (s['funcs_matched'], s['funcs'])),
            ('Data', pct(s['data_matched'], s['data_bytes']), '%s / %s bytes' % (f"{s['data_matched']:,}", f"{s['data_bytes']:,}"))]
    W, bar = 420, 300
    out = ['<svg xmlns="http://www.w3.org/2000/svg" width="%d" height="%d" font-family="-apple-system,Segoe UI,Helvetica,Arial,sans-serif">' % (W, 112 + 46 * len(rows)),
           '<style>.fg{fill:#1f2328}.mut{fill:#59636e}.trk{fill:#d1d9e0}.bar{fill:#1a7f37}'
           '@media (prefers-color-scheme: dark){.fg{fill:#f0f6fc}.mut{fill:#9198a1}.trk{fill:#3d444d}.bar{fill:#3fb950}}</style>',
           '<text x="20" y="38" font-size="24" font-weight="700" class="fg">COGMIND.EXE</text>',
           '<text x="20" y="60" font-size="13" class="mut">Beta 17.1 (260906) · %s</text>' % s['date'],
           '<text x="%d" y="44" font-size="34" font-weight="700" text-anchor="end" class="fg">%.2f%%</text>' % (W - 20, rows[0][1]),
           '<text x="%d" y="62" font-size="12" text-anchor="end" class="mut">matched code</text>' % (W - 20)]
    y = 96
    for label, p, detail in rows:
        w = max(0, min(bar, bar * p / 100.0)); w = 2 if 0 < w < 2 else w
        out += ['<text x="20" y="%d" font-size="13" font-weight="600" class="fg">%s</text>' % (y, label),
                '<text x="%d" y="%d" font-size="12" text-anchor="end" class="mut">%.3f%% · %s</text>' % (W - 20, y, p, detail),
                '<rect x="20" y="%d" width="%d" height="12" rx="6" class="trk"/>' % (y + 8, W - 40),
                '<rect x="20" y="%d" width="%.1f" height="12" rx="6" class="bar"/>' % (y + 8, w * (W - 40) / bar)]
        y += 46
    out.append('</svg>')
    return '\n'.join(out)

def squarify(items, x, y, w, h):
    """items: [(size, payload)] sorted desc -> [(x, y, w, h, payload)] (Bruls et al.)"""
    out = []; items = [i for i in items if i[0] > 0]
    total = float(sum(s for s, _ in items))
    if not items or w <= 0 or h <= 0: return out
    scale = w * h / total
    rest = [(s * scale, p) for s, p in items]
    while rest:
        short = min(w, h); row = []; best = None
        for it in rest:
            trial = row + [it]; area = sum(a for a, _ in trial)
            worst = max(max(short * short * a / (area * area), area * area / (short * short * a)) for a, _ in trial)
            if best is not None and worst > best: break
            row, best = trial, worst
        rest = rest[len(row):]; area = sum(a for a, _ in row)
        if w >= h:
            cw = area / h; cy = y
            for a, p in row: out.append((x, cy, cw, a / cw, p)); cy += a / cw
            x += cw; w -= cw
        else:
            ch = area / w; cx = x
            for a, p in row: out.append((cx, y, a / ch, ch, p)); cx += a / ch
            y += ch; h -= ch
    return out

COLORS = {'matched': '#2da44e', 'named': '#d4a72c', 'unknown': '#8c959f', 'library': '#6e7781'}

def treemap(funcs, s):
    groups = collections.defaultdict(list)
    for va, size, state, name in funcs:
        if state == 'library': g = 'library'
        elif name and '::' in name: g = name.split('::')[0]
        elif name: g = '(free functions)'
        else: g = '%06Xxxxx' % (va >> 16 << 4 >> 4) if False else 'region %X0000' % (va >> 16)
        groups[g].append((size, (va, size, state, name)))
    gitems = sorted(((sum(sz for sz, _ in v), g) for g, v in groups.items()), reverse=True)
    W, H = 1600, 900
    rects = []
    for gx, gy, gw, gh, g in squarify(gitems, 0, 0, W, H):
        inner = squarify(sorted(groups[g], key=lambda t: -t[0]), gx + 1, gy + 1, gw - 2, gh - 2)
        rects.append(('g', gx, gy, gw, gh, g))
        for x, y, w, h, f in inner: rects.append(('f', x, y, w, h, f))
    parts = []
    for r in rects:
        if r[0] == 'g':
            _, x, y, w, h, g = r
            parts.append('<rect x="%.1f" y="%.1f" width="%.1f" height="%.1f" class="grp"/>' % (x, y, w, h))
        else:
            _, x, y, w, h, (va, size, state, name) = r
            tip = '%s%s · %#x · %s bytes · %s' % (html.escape(name), '' if name else 'sub_%x' % va, va, f'{size:,}', state)
            if name: tip = tip.replace(html.escape(name), html.escape(name), 1)
            parts.append('<rect x="%.2f" y="%.2f" width="%.2f" height="%.2f" fill="%s"><title>%s</title></rect>' % (x, y, w, h, COLORS[state], tip))
    labels = []
    for r in rects:
        if r[0] == 'g' and r[3] > 70 and r[4] > 18:
            _, x, y, w, h, g = r
            labels.append('<text x="%.1f" y="%.1f" class="lbl">%s</text>' % (x + 4, y + 13, html.escape(g)))
    cp, fp = pct(s['code_matched'], s['code_bytes']), pct(s['funcs_matched'], s['funcs'])
    legend = ''.join('<span><i style="background:%s"></i>%s</span>' % (c, k) for k, c in COLORS.items() if k != 'library')
    return '''<!doctype html><html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>Cogmind Decomp Progress</title><style>
:root{--bg:#ffffff;--fg:#1f2328;--mut:#59636e;--line:#d1d9e0;--trk:#d1d9e0;--bar:#1a7f37}
@media (prefers-color-scheme: dark){:root:not([data-theme="light"]){--bg:#0d1117;--fg:#f0f6fc;--mut:#9198a1;--line:#3d444d;--trk:#3d444d;--bar:#3fb950}}
:root[data-theme="dark"]{--bg:#0d1117;--fg:#f0f6fc;--mut:#9198a1;--line:#3d444d;--trk:#3d444d;--bar:#3fb950}
body{margin:0;background:var(--bg);color:var(--fg);font:14px/1.45 -apple-system,"Segoe UI",Helvetica,Arial,sans-serif}
main{max-width:1640px;margin:0 auto;padding:24px 16px}
h1{font-size:22px;margin:0 0 4px} .mut{color:var(--mut)}
.stats{display:grid;grid-template-columns:repeat(auto-fit,minmax(240px,1fr));gap:16px;margin:20px 0}
.stat b{font-size:28px;display:block;font-variant-numeric:tabular-nums}
.trk{height:10px;border-radius:5px;background:var(--trk);overflow:hidden;margin-top:6px}.trk i{display:block;height:100%%;background:var(--bar);min-width:2px}
.legend{display:flex;gap:16px;flex-wrap:wrap;margin:8px 0}.legend i{display:inline-block;width:12px;height:12px;border-radius:2px;margin-right:6px;vertical-align:-1px}
.map{overflow:auto;border:1px solid var(--line);border-radius:6px}
svg{display:block;width:100%%;height:auto;min-width:800px}.grp{fill:none;stroke:var(--bg);stroke-width:2}
.lbl{font-size:11px;fill:#fff;paint-order:stroke;stroke:#0008;stroke-width:3px;pointer-events:none}
rect[fill]:hover{fill-opacity:.7}
</style></head><body><main>
<h1>COGMIND.EXE decomp</h1><div class="mut">Beta 17.1 (260906) · generated %s · game code only: %s library functions (%s bytes, protobuf/CRT) excluded · code bytes include compiler-generated EH funclets, function counts don't</div>
<div class="stats">
<div class="stat"><span class="mut">Code matched</span><b>%.3f%%</b><span class="mut">%s / %s bytes</span><div class="trk"><i style="width:%.4f%%"></i></div></div>
<div class="stat"><span class="mut">Functions matched</span><b>%d / %d</b><span class="mut">%.3f%%</span><div class="trk"><i style="width:%.4f%%"></i></div></div>
<div class="stat"><span class="mut">Functions named</span><b>%d</b><span class="mut">%.2f%% of all functions</span><div class="trk"><i style="width:%.4f%%"></i></div></div>
<div class="stat"><span class="mut">Data matched</span><b>%.2f%%</b><span class="mut">%s / %s bytes of .rdata + initialized .data (all of it, library data included) · %s string/float constants · %s vtable bytes (%d/%d vtables) · %s initialized globals · %d zero-init globals paired (not counted)</span><div class="trk"><i style="width:%.4f%%"></i></div></div>
</div>
<div class="legend">%s<span class="mut">rectangle area = function size · hover for name/address</span></div>
<div class="map"><svg viewBox="0 0 %d %d" xmlns="http://www.w3.org/2000/svg">%s%s</svg></div>
</main></body></html>''' % (s['date'], f"{s['lib_funcs']:,}", f"{s['lib_bytes']:,}", cp, f"{s['code_matched']:,}", f"{s['code_bytes']:,}", cp,
        s['funcs_matched'], s['funcs'], fp, fp, s['funcs_named'], pct(s['funcs_named'], s['funcs']), pct(s['funcs_named'], s['funcs']),
        pct(s['data_matched'], s['data_bytes']), f"{s['data_matched']:,}", f"{s['data_bytes']:,}", f"{s['data_detail'].get('literals', 0):,}", f"{s['data_detail'].get('vtables', 0):,}",
        s['data_detail'].get('vtables_ok', 0), s['data_detail'].get('vtables_all', 0), f"{s['data_detail'].get('globals', 0):,}", s['data_detail'].get('zero_globals', 0), pct(s['data_matched'], s['data_bytes']),
        legend, W, H, ''.join(parts), ''.join(labels))

def main():
    funcs = collect(); s = stats(funcs)
    os.makedirs(os.path.join(common.REPO, 'docs'), exist_ok=True)
    json.dump(s, open(os.path.join(common.REPO, 'build', 'progress.json'), 'w'), indent=1)
    open(os.path.join(common.REPO, 'docs', 'progress.svg'), 'w').write(badge(s))
    open(os.path.join(common.REPO, 'docs', 'progress.html'), 'w').write(treemap(funcs, s))
    print("code %.3f%%  functions %d/%d  named %d  -> docs/progress.svg, docs/progress.html" % (
        pct(s['code_matched'], s['code_bytes']), s['funcs_matched'], s['funcs'], s['funcs_named']))

if __name__ == '__main__':
    main()
