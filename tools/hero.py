"""Cogmind-themed hero art. `python tools/hero.py` writes docs/hero.svg (the README banner, committed).
   progress.py reuses logo_svg() and font_face_css() for docs/progress.html.
   Palette: noemica/cog-minder "Cogmind" theme. Fonts: docs/assets/fonts (PlasticHeart's cogfont, MIT).
   The logo is the XomMind GitHub org icon rebuilt as vector: the 400 px avatar is an 11x10 pixel-art
   sprite that was bilinear-upscaled, so each cell is read back once and redrawn crisp at any size."""
import os, base64

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FONTS = os.path.join(REPO, 'docs', 'assets', 'fonts')

BG, PANEL, LINE, LABEL, TITLE, TEXT, DIM = '#080808', '#080808', '#006200', '#162416', '#00cc00', '#9da9af', '#747e83'

# '.' transparent; R/M/K/B = bright red, mid red, dark red, near-black (sampled from the avatar)
LOGO = ['....MMKK...',
        '.RRMMRMRRMM',
        '.RRRRRRRRMM',
        '.MMKK..RRMM',
        'RRRKRM.....',
        'RRRBK......',
        '.MMBB..RRMM',
        '.RRRRRRRRMM',
        '.RRMMRMRRMM',
        '....MMKK...']
LOGO_W, LOGO_H = len(LOGO[0]), len(LOGO)
PAL = {'R': '#ff000f', 'M': '#770007', 'K': '#2e0102', 'B': '#050001'}

def font_uri(name):
    with open(os.path.join(FONTS, name), 'rb') as f:
        return 'data:font/woff2;base64,' + base64.b64encode(f.read()).decode()

def font_face_css():
    """@font-face rules as Cog-Minder declares them (size-adjust included), fonts inlined as data URIs"""
    return ('@font-face{font-family:smallcaps-mono;size-adjust:80%%;src:url(%s) format("woff2")}'
            '@font-face{font-family:cog-mono;src:url(%s) format("woff2")}'
            '@font-face{font-family:courier-new-adjusted;src:local("Courier New");size-adjust:125%%}'
            % (font_uri('Cogmind-Smallcaps-mono.woff2'), font_uri('Cogmind-Cog.woff2')))

MONO = 'smallcaps-mono,courier-new-adjusted,monospace'
TITLE_FONT = 'cog-mono,smallcaps-mono,courier-new-adjusted,monospace'

def logo_paths():
    """one <path> per colour; horizontal runs merged, unit cells (scale with a transform)"""
    d = {k: [] for k in PAL}
    for y, row in enumerate(LOGO):
        x = 0
        while x < len(row):
            c = row[x]
            if c == '.': x += 1; continue
            e = x
            while e < len(row) and row[e] == c: e += 1
            d[c].append('M%d %dh%dv1h-%dz' % (x, y, e - x, e - x))
            x = e
    return ''.join('<path fill="%s" d="%s"/>' % (PAL[k], ''.join(v)) for k, v in d.items() if v)

def logo_svg(attrs=''):
    return '<svg viewBox="0 0 %d %d" shape-rendering="crispEdges" role="img" aria-label="Cogmind" %s>%s</svg>' % (LOGO_W, LOGO_H, attrs, logo_paths())

# x/y are text positions; lx/ly place the logo; t/s/m/d are font sizes (title, subtitle, tagline, spec);
# bar is the label bar height. README banner: logo anchored top-right (W - 24 - logo width).
BANNER = dict(W=1200, H=340, CELL=28, bar=30, lx=868, ly=48, label=18, lby=23, tx=40, ty=156, t=84,
              sx=44, sy=206, s=34, mx=44, my=258, m=22, dx=44, dy=288, d=18, cx=44, cy=302, cw=14, ch=20)
# 1280x640 (GitHub social preview, 2:1): same as the banner but the logo is mirrored to the top-left and the title is
# lifted so its cap-height (0.755 * t, glyphs sit on the baseline) is centred on the logo (centre y = ly + 5 * CELL = 226).
SOCIAL = dict(W=1280, H=640, CELL=26, bar=44, lx=24, ly=96, label=24, lby=31, tx=337, ty=273, t=124,
              sx=62, sy=430, s=50, mx=62, my=508, m=32, dx=62, dy=556, d=26, cx=62, cy=584, cw=20, ch=30)

def hero(L=BANNER):
    W, H, CELL = L['W'], L['H'], L['CELL']
    lx = L['lx']
    bar = L['bar']
    return '''<svg xmlns="http://www.w3.org/2000/svg" width="%(W)d" height="%(H)d" viewBox="0 0 %(W)d %(H)d" role="img" aria-label="COGMIND.EXE decompilation">
<style>%(fonts)s
.t{font-family:%(title)s;fill:%(tc)s}.m{font-family:%(mono)s}</style>
<defs><pattern id="scan" width="4" height="4" patternUnits="userSpaceOnUse"><rect width="4" height="1" y="3" fill="#000" fill-opacity=".35"/></pattern></defs>
<rect width="%(W)d" height="%(H)d" fill="%(bg)s"/>
<rect x="1" y="1" width="%(w2)d" height="%(h2)d" fill="none" stroke="%(line)s" stroke-width="2"/>
<rect x="2" y="2" width="%(w4)d" height="%(bar)d" fill="%(label)s"/><rect x="2" y="%(bar2)d" width="%(w4)d" height="1" fill="%(line)s"/>
<text class="m" x="18" y="%(lby)d" font-size="%(lfs)d" fill="%(tc)s">COGMIND.EXE  |  BETA 17.1 (260906)  |  DECOMPILATION</text>
<text class="t" x="%(tx)d" y="%(ty)d" font-size="%(t)d">COGMIND.EXE</text>
<text class="t" x="%(sx)d" y="%(sy)d" font-size="%(s)d" style="fill:%(text)s">LU-1G1's BORING DECOMP</text>
<text class="m" x="%(mx)d" y="%(my)d" font-size="%(m)d" fill="%(text)s">We dug so you don't have to!</text>
<text class="m" x="%(dx)d" y="%(dy)d" font-size="%(d)d" fill="%(dim)s">VS2010 SP1  |  /Od /GL  |  LTCG link</text>
<rect x="%(cx)d" y="%(cy)d" width="%(cw)d" height="%(ch)d" fill="%(tc)s"/>
<g transform="translate(%(lx)d %(ly)d) scale(%(cell)d)" shape-rendering="crispEdges">%(logo)s</g>
<rect x="2" y="%(bar3)d" width="%(w4)d" height="%(hs)d" fill="url(#scan)" pointer-events="none"/>
</svg>
''' % dict(W=W, H=H, w2=W - 2, h2=H - 2, w4=W - 4, bar=bar, bar2=bar + 2, bar3=bar + 3, hs=H - bar - 5, fonts=font_face_css(),
           title=TITLE_FONT, mono=MONO, tc=TITLE, text=TEXT, dim=DIM, bg=BG, line=LINE, label=LABEL, lx=lx, ly=L['ly'],
           cell=CELL, logo=logo_paths(), lby=L['lby'], lfs=L['label'], tx=L['tx'], ty=L['ty'], t=L['t'], sx=L['sx'], sy=L['sy'],
           s=L['s'], mx=L['mx'], my=L['my'], m=L['m'], dx=L['dx'], dy=L['dy'], d=L['d'], cx=L['cx'], cy=L['cy'], cw=L['cw'], ch=L['ch'])

if __name__ == '__main__':
    import sys
    if sys.argv[1:2] == ['social']:      # `hero.py social [out.svg]`: 1280x640 layout for the GitHub social preview (rasterize to PNG)
        out = sys.argv[2] if len(sys.argv) > 2 else os.path.join(REPO, 'docs', 'social.svg')
        open(out, 'w').write(hero(SOCIAL))
    else:
        out = os.path.join(REPO, 'docs', 'hero.svg')
        open(out, 'w').write(hero())
    print('-> %s (%d bytes)' % (os.path.relpath(out, REPO), os.path.getsize(out)))
