/* Canvas renderer: Cogmind-style ASCII or tiles (robot sprites from noemica/cog-minder) for full-size maps with a
   zoomable, pannable camera; zone grid, squad search areas, and the dispatch-timer chart. Reads Sim state only. */
(function (root) {
'use strict';

const D = root.Dispatch;
const C = 12;		// world pixels per cell (the cog-minder sprites are 12x12)
const GLYPH = 16;	// cogfont's glyphs sit small in their em box; 16 px fills a 12 px cell like Cogmind's square map font

const COL = {
	bg: '#000000',
	wall: ['#262c26', '#4a534a', '#98a298'],		// unknown (observer view) / remembered / in view
	wallBg: ['#0c0f0c', '#121712', '#1c231c'],
	floor: ['#141a14', '#26302a', '#4d5f4d'],
	floorBg: ['#030403', '#050705', '#081008'],
	door: ['#3a3020', '#6e5a2c', '#d8b04c'],
	machine: ['#1b1d22', '#2b3140', '#56627e'],
	machineEdge: ['#262a32', '#46506a', '#8c9cc4'],
	interactive: '#7fd0ff',
	cogmind: '#d8ffd8',
	P: '#c45cff',
	Q: '#ff9a2e',
	exitOpen: '#f0c850',
	exitSeen: '#7d6a2c',
	exitCave: '#8a6a44',
	garrison: '#e2e24c',
	garrisonOff: '#8a3030',
	zoneFill: 'rgba(0, 204, 0, 0.09)',
	zoneLine: 'rgba(0, 150, 0, 0.5)',
	zoneLabel: 'rgba(0, 204, 0, 0.6)',
	zoneHere: '#00cc00',
	phase: ['#ffd84a', '#ff8a3a', '#ff4646'],
	trail: 'rgba(196, 92, 255, 0.6)',
	travel: '#00cc00',
	chartLine: '#00cc00',
	chartGrid: '#162416',
	chartText: '#747e83',
};

const MACHINE_LETTER = { 'Terminal': 'T', 'Fabricator': 'F', 'Repair Station': 'R', 'Recycling Unit': 'Y', 'Scanalyzer': 'S', 'Garrison Access': 'G', 'DSF Access': 'D' };

const phaseOf = p => (p.f10 > 0 ? 0 : p.f10 < 0 ? 1 : 2);

class Renderer
{
	constructor(canvas, chart)
	{
		this.canvas = canvas;
		this.ctx = canvas.getContext('2d');
		this.chart = chart;
		this.cctx = chart.getContext('2d');
		this.opts = { tiles: false, observer: false, zones: true, areas: false };
		this.base = document.createElement('canvas');
		this.baseKey = '';
		this.sprites = null;
		this.flashes = [];
		this.cam = { x: 0, y: 0, scale: 1, fitted: '' };	// x, y: world-pixel point at the viewport centre
		this.dpr = 1;
	}

	async loadSprites(dir)
	{
		const load = name => new Promise((resolve, reject) =>
		{
			const img = new Image();
			img.onload = () => resolve(img);
			img.onerror = reject;
			img.src = dir + name;
		});
		try
		{
			const [cog, p, q] = await Promise.all([load('cogmind.png'), load('programmer.png'), load('q-series.png')]);
			this.sprites = { cog: this.tint(cog, COL.cogmind), P: this.tint(p, COL.P), Q: this.tint(q, COL.Q) };
		}
		catch (e)
		{
			this.sprites = null;
		}
		return !!this.sprites;
	}

	// sprites are white on black: multiply by the colour, then draw with 'lighter' so black stays transparent
	tint(img, color)
	{
		const c = document.createElement('canvas');
		c.width = c.height = C;
		const g = c.getContext('2d');
		g.drawImage(img, 0, 0, C, C);
		g.globalCompositeOperation = 'multiply';
		g.fillStyle = color;
		g.fillRect(0, 0, C, C);
		return c;
	}

	// ---- camera ----
	resize()
	{
		const r = this.canvas.getBoundingClientRect();
		this.dpr = window.devicePixelRatio || 1;
		const w = Math.max(1, Math.round(r.width * this.dpr)), h = Math.max(1, Math.round(r.height * this.dpr));
		if (this.canvas.width !== w || this.canvas.height !== h)
		{
			this.canvas.width = w;
			this.canvas.height = h;
		}
	}

	fitScale(sim)
	{
		return Math.min(this.canvas.width / (sim.w * C), this.canvas.height / (sim.h * C));
	}

	fit(sim)
	{
		this.resize();
		this.cam.scale = this.fitScale(sim);
		this.cam.x = sim.w * C / 2;
		this.cam.y = sim.h * C / 2;
		this.cam.fitted = `${sim.mapId}`;
	}

	clampCam(sim)
	{
		const min = this.fitScale(sim) * 0.8, max = 4 * this.dpr;
		this.cam.scale = Math.max(min, Math.min(max, this.cam.scale));
		const hw = this.canvas.width / 2 / this.cam.scale, hh = this.canvas.height / 2 / this.cam.scale;
		const W = sim.w * C, H = sim.h * C;
		this.cam.x = hw * 2 >= W ? W / 2 : Math.max(hw, Math.min(W - hw, this.cam.x));
		this.cam.y = hh * 2 >= H ? H / 2 : Math.max(hh, Math.min(H - hh, this.cam.y));
	}

	// zoom by factor keeping the world point under (clientX, clientY) fixed
	zoomAt(sim, clientX, clientY, factor)
	{
		const r = this.canvas.getBoundingClientRect();
		const sx = (clientX - r.left) * this.dpr, sy = (clientY - r.top) * this.dpr;
		const wx = this.cam.x + (sx - this.canvas.width / 2) / this.cam.scale;
		const wy = this.cam.y + (sy - this.canvas.height / 2) / this.cam.scale;
		this.cam.scale *= factor;
		this.clampCam(sim);
		this.cam.x = wx - (sx - this.canvas.width / 2) / this.cam.scale;
		this.cam.y = wy - (sy - this.canvas.height / 2) / this.cam.scale;
		this.clampCam(sim);
	}

	panBy(sim, dxClient, dyClient)
	{
		this.cam.x -= dxClient * this.dpr / this.cam.scale;
		this.cam.y -= dyClient * this.dpr / this.cam.scale;
		this.clampCam(sim);
	}

	centerOn(sim, x, y)
	{
		this.cam.x = (x + 0.5) * C;
		this.cam.y = (y + 0.5) * C;
		this.clampCam(sim);
	}

	cellAt(sim, clientX, clientY)
	{
		const r = this.canvas.getBoundingClientRect();
		const sx = (clientX - r.left) * this.dpr, sy = (clientY - r.top) * this.dpr;
		const x = Math.floor((this.cam.x + (sx - this.canvas.width / 2) / this.cam.scale) / C);
		const y = Math.floor((this.cam.y + (sy - this.canvas.height / 2) / this.cam.scale) / C);
		return x >= 0 && y >= 0 && x < sim.w && y < sim.h ? { x, y } : null;
	}

	flash(x, y, color)
	{
		this.flashes.push({ x, y, color, t0: performance.now() });
	}

	setFont(g, px)
	{
		g.font = `${px}px cog-mono, "Courier New", monospace`;
		g.textAlign = 'center';
		g.textBaseline = 'middle';
	}

	glyph(g, ch, x, y, color)
	{
		g.fillStyle = color;
		g.fillText(ch, x * C + C / 2, y * C + C / 2 + 1);
	}

	// ---- base layer: terrain and machines at 12 px per cell, redrawn per cell as visibility changes ----
	syncBase(sim)
	{
		const key = `${sim.mapId}:${this.opts.tiles}:${this.opts.observer}`;
		const dirty = sim.takeDirty();
		if (key !== this.baseKey)
		{
			this.baseKey = key;
			this.base.width = sim.w * C;
			this.base.height = sim.h * C;
			this.edge = new Uint8Array(sim.w * sim.h);
			for (let y = 0; y < sim.h; y++)
				for (let x = 0; x < sim.w; x++)
					if (sim.cells[y * sim.w + x] === D.WALL && this.touchesOpen(sim, x, y))
						this.edge[y * sim.w + x] = 1;
			const g = this.base.getContext('2d');
			g.fillStyle = COL.bg;
			g.fillRect(0, 0, this.base.width, this.base.height);
			this.setFont(g, GLYPH);
			for (let i = 0, n = sim.w * sim.h; i < n; i++)
				this.drawCell(g, sim, i, false);
			return;
		}
		if (!dirty.length)
			return;
		const g = this.base.getContext('2d');
		this.setFont(g, GLYPH);
		for (const i of dirty)
			this.drawCell(g, sim, i, true);
	}

	touchesOpen(sim, x, y)
	{
		for (let dy = -1; dy <= 1; dy++)
			for (let dx = -1; dx <= 1; dx++)
			{
				const nx = x + dx, ny = y + dy;
				if (nx >= 0 && ny >= 0 && nx < sim.w && ny < sim.h && sim.cells[ny * sim.w + nx] !== D.WALL)
					return true;
			}
		return false;
	}

	drawCell(g, sim, i, clear)
	{
		const x = i % sim.w, y = (i / sim.w) | 0, px = x * C, py = y * C;
		const cell = sim.cells[i];
		const lvl = sim.vis[i] ? 2 : sim.seen[i] ? 1 : 0;
		if (clear)
		{
			g.fillStyle = COL.bg;
			g.fillRect(px, py, C, C);
		}
		if (lvl === 0 && !this.opts.observer)
			return;
		if (cell === D.WALL)
		{
			if (!this.edge[i])
				return;
			if (this.opts.tiles)
			{
				g.fillStyle = COL.wall[lvl];
				g.fillRect(px, py, C, C);
				g.fillStyle = COL.wallBg[lvl];
				g.fillRect(px + 1, py + 1, C - 2, C - 2);
				g.fillStyle = COL.wall[lvl];
				g.fillRect(px + 3, py + 3, C - 6, C - 6);
			}
			else
			{
				g.fillStyle = COL.wallBg[lvl];
				g.fillRect(px, py, C, C);
				this.glyph(g, '#', x, y, COL.wall[lvl]);
			}
		}
		else if (cell === D.MACHINE)
		{
			g.fillStyle = COL.machineEdge[lvl];
			g.fillRect(px, py, C, C);
			g.fillStyle = COL.machine[lvl];
			g.fillRect(px + 1, py + 1, C - 2, C - 2);
		}
		else if (cell === D.DOOR)
		{
			g.fillStyle = COL.floorBg[lvl];
			g.fillRect(px, py, C, C);
			if (this.opts.tiles)
			{
				g.fillStyle = COL.door[lvl];
				g.fillRect(px + 2, py + 2, C - 4, C - 4);
			}
			else
				this.glyph(g, '+', x, y, COL.door[lvl]);
		}
		else
		{
			g.fillStyle = COL.floorBg[lvl];
			g.fillRect(px, py, C, C);
			if (this.opts.tiles)
			{
				g.fillStyle = COL.floor[lvl];
				g.fillRect(px + 5, py + 5, 2, 2);
			}
			else
				this.glyph(g, '.', x, y, COL.floor[lvl]);
		}
	}

	// ---- frame ----
	draw(sim, hover)
	{
		this.resize();
		if (this.cam.fitted !== `${sim.mapId}`)
		{
			// new map: start on Cogmind at about the game's view width (60 cells), zoom out to see the whole map
			this.fit(sim);
			this.cam.scale = Math.max(this.cam.scale, this.canvas.width / (60 * C));
			this.centerOn(sim, sim.player.x, sim.player.y);
		}
		this.syncBase(sim);
		const g = this.ctx;
		g.setTransform(1, 0, 0, 1, 0, 0);
		g.globalCompositeOperation = 'source-over';
		g.globalAlpha = 1;
		g.fillStyle = '#000';
		g.fillRect(0, 0, this.canvas.width, this.canvas.height);
		const s = this.cam.scale;
		g.setTransform(s, 0, 0, s, this.canvas.width / 2 - this.cam.x * s, this.canvas.height / 2 - this.cam.y * s);
		g.imageSmoothingEnabled = s < 1;
		g.drawImage(this.base, 0, 0);
		this.px = 1 / s;	// one screen pixel in world units
		if (this.opts.zones && sim.blocks)
			this.drawZones(g, sim);
		this.drawMachines(g, sim);
		this.drawExits(g, sim);
		if (this.opts.areas)
			this.drawAreas(g, sim);
		this.drawRobots(g, sim);
		this.drawFlashes(g);
		if (hover)
		{
			g.strokeStyle = 'rgba(255,255,255,0.6)';
			g.lineWidth = this.px;
			g.strokeRect(hover.x * C, hover.y * C, C, C);
		}
		g.setTransform(1, 0, 0, 1, 0, 0);
	}

	visibleCells(sim)
	{
		const s = this.cam.scale, hw = this.canvas.width / 2 / s, hh = this.canvas.height / 2 / s;
		return {
			x1: Math.max(0, Math.floor((this.cam.x - hw) / C)), y1: Math.max(0, Math.floor((this.cam.y - hh) / C)),
			x2: Math.min(sim.w - 1, Math.ceil((this.cam.x + hw) / C)), y2: Math.min(sim.h - 1, Math.ceil((this.cam.y + hh) / C)),
		};
	}

	drawZones(g, sim)
	{
		const size = sim.blocks.size, credit = sim.blocks.credit, s = size * C;
		const W = sim.w * C, H = sim.h * C;
		const px = (sim.player.x / size) | 0, py = (sim.player.y / size) | 0;
		const labels = this.cam.scale * s > 60;
		g.save();
		g.font = `${Math.max(10, 11 * this.px)}px smallcaps-mono, "Courier New", monospace`;
		g.textAlign = 'left';
		g.textBaseline = 'top';
		for (let by = 0; by < sim.bh; by++)
		{
			for (let bx = 0; bx < sim.bw; bx++)
			{
				const k = by * sim.bw + bx;
				if (sim.explored[k])
				{
					g.fillStyle = COL.zoneFill;
					g.fillRect(bx * s, by * s, Math.min(s, W - bx * s), Math.min(s, H - by * s));
				}
				else if (labels && sim.enterable[k])
				{
					g.fillStyle = COL.zoneLabel;
					g.fillText(`-${credit}t`, bx * s + 4 * this.px, by * s + 4 * this.px);
				}
			}
		}
		g.strokeStyle = COL.zoneLine;
		g.lineWidth = this.px;
		g.setLineDash([4 * this.px, 4 * this.px]);
		g.beginPath();
		for (let bx = 1; bx < sim.bw; bx++) { g.moveTo(bx * s, 0); g.lineTo(bx * s, H); }
		for (let by = 1; by < sim.bh; by++) { g.moveTo(0, by * s); g.lineTo(W, by * s); }
		g.stroke();
		g.setLineDash([]);
		g.strokeStyle = COL.zoneHere;
		g.lineWidth = 1.5 * this.px;
		g.strokeRect(px * s, py * s, Math.min(s, W - px * s), Math.min(s, H - py * s));
		g.restore();
	}

	drawMachines(g, sim)
	{
		const big = this.cam.scale * C >= 6;
		this.setFont(g, GLYPH);
		for (const m of sim.machines)
		{
			if (!m.interactive || m.name === 'Garrison Access' || m.name === 'DSF Access')
				continue;
			const i = m.y * sim.w + m.x;
			if (!this.opts.observer && !sim.seen[i])
				continue;
			g.strokeStyle = COL.interactive;
			g.globalAlpha = sim.vis[i] ? 1 : 0.6;
			g.lineWidth = Math.max(this.px, 1);
			g.strokeRect(m.x * C + 1, m.y * C + 1, m.w * C - 2, m.h * C - 2);
			if (big)
			{
				const cx = m.x + (m.w - 1) / 2, cy = m.y + (m.h - 1) / 2;
				this.glyph(g, MACHINE_LETTER[m.name] || '?', cx, cy, COL.interactive);
			}
		}
		g.globalAlpha = 1;
	}

	drawExits(g, sim)
	{
		const minPx = 4 * this.px;
		this.setFont(g, GLYPH);
		for (const e of sim.exits)
		{
			const x = e.mx, y = e.my, i = y * sim.w + x;
			if (!this.opts.observer && !sim.seen[i] && !sim.seen[e.idx])
				continue;
			let color, ch;
			if (e.kind === 'garrison' || e.kind === 'dsf')
			{
				const m = sim.machines[e.machine];
				const off = e.kind === 'garrison' && e.prop.disabled;
				color = e.kind === 'dsf' ? COL.interactive : off ? COL.garrisonOff : COL.garrison;
				ch = e.kind === 'dsf' ? 'D' : off ? 'x' : 'G';
				if (m)
				{
					g.strokeStyle = color;
					g.lineWidth = Math.max(this.px, 1);
					g.strokeRect(m.x * C + 1, m.y * C + 1, m.w * C - 2, m.h * C - 2);
				}
				g.fillStyle = off ? '#2a0e0e' : e.kind === 'dsf' ? '#0c1a24' : '#2c2c0c';
			}
			else
			{
				color = e.flag !== 1 ? COL.exitCave : sim.vis[e.idx] ? COL.exitSeen : COL.exitOpen;
				ch = '>';
				g.fillStyle = '#000';
			}
			const sz = Math.max(C, minPx), pad = (sz - C) / 2;
			g.fillRect(x * C - pad, y * C - pad, sz, sz);
			if (this.cam.scale * C >= 6)
				this.glyph(g, ch, x, y, color);
			else
			{
				g.fillStyle = color;
				g.fillRect(x * C - pad, y * C - pad, sz, sz);
			}
		}
	}

	drawAreas(g, sim)
	{
		g.save();
		for (const p of sim.parties)
		{
			const a = p.area, color = COL.phase[phaseOf(p)];
			const x = a.x1 * C, y = a.y1 * C, w = (a.x2 - a.x1 + 1) * C, h = (a.y2 - a.y1 + 1) * C;
			g.globalAlpha = 0.07;
			g.fillStyle = color;
			g.fillRect(x, y, w, h);
			g.globalAlpha = 0.9;
			g.strokeStyle = color;
			g.lineWidth = 1.5 * this.px;
			g.setLineDash([6 * this.px, 4 * this.px]);
			g.strokeRect(x, y, w, h);
			g.setLineDash([]);
			// dispatch trail from the entry point to the area centre, fading over 150 turns
			const age = sim.turn - p.spawnTurn;
			if (age < 150)
			{
				g.globalAlpha = 1 - age / 150;
				g.strokeStyle = COL.trail;
				g.beginPath();
				g.moveTo(p.origin.x * C + C / 2, p.origin.y * C + C / 2);
				g.lineTo((a.x1 + a.x2 + 1) * C / 2, (a.y1 + a.y2 + 1) * C / 2);
				g.stroke();
			}
		}
		g.restore();
	}

	drawActor(g, x, y, sprite, glyph, color, alpha)
	{
		const cellPx = this.cam.scale * C;
		g.globalAlpha = alpha;
		if (cellPx < 7)
		{
			// zoomed out: a solid dot at least 4 screen pixels wide
			const sz = Math.max(C, 4 * this.px), off = (sz - C) / 2;
			g.fillStyle = color;
			g.fillRect(x * C - off, y * C - off, sz, sz);
			return;
		}
		g.fillStyle = '#000';
		g.fillRect(x * C, y * C, C, C);
		if (this.opts.tiles && this.sprites)
		{
			g.globalCompositeOperation = 'lighter';
			g.drawImage(sprite, x * C, y * C);
			g.globalCompositeOperation = 'source-over';
		}
		else
			this.glyph(g, glyph, x, y, color);
	}

	drawRobots(g, sim)
	{
		this.setFont(g, GLYPH);
		for (const b of sim.bots)
		{
			const inView = !!sim.vis[b.y * sim.w + b.x];
			if (!inView && !this.opts.observer)
				continue;
			this.drawActor(g, b.x, b.y, this.sprites && this.sprites[b.cls], D.ROBOT_CLASS[b.cls].glyph, COL[b.cls], inView ? 1 : 0.55);
			if (b.party && b.party.leader === b && b.party.sees && this.cam.scale * C >= 7)
			{
				g.fillStyle = '#ff4646';
				g.fillRect(b.x * C + C - 3, b.y * C, 3, 3);
			}
		}
		const p = sim.player;
		this.drawActor(g, p.x, p.y, this.sprites && this.sprites.cog, '@', COL.cogmind, 1);
		if (this.cam.scale * C < 7)
		{
			// keep Cogmind findable when zoomed out
			g.strokeStyle = COL.cogmind;
			g.lineWidth = 1.5 * this.px;
			g.beginPath();
			g.arc(p.x * C + C / 2, p.y * C + C / 2, 9 * this.px, 0, Math.PI * 2);
			g.stroke();
		}
		g.globalAlpha = 1;
		if (sim.travel >= 0)
		{
			const tx = sim.travel % sim.w, ty = (sim.travel / sim.w) | 0;
			g.strokeStyle = COL.travel;
			g.lineWidth = Math.max(this.px, 1);
			g.beginPath();
			g.moveTo(tx * C + 2, ty * C + 2); g.lineTo(tx * C + C - 2, ty * C + C - 2);
			g.moveTo(tx * C + C - 2, ty * C + 2); g.lineTo(tx * C + 2, ty * C + C - 2);
			g.stroke();
		}
	}

	drawFlashes(g)
	{
		const now = performance.now();
		this.flashes = this.flashes.filter(f => now - f.t0 < 1600);
		g.save();
		for (const f of this.flashes)
		{
			const t = (now - f.t0) / 1600;
			g.globalAlpha = 1 - t;
			g.strokeStyle = f.color;
			g.lineWidth = 2 * this.px;
			g.beginPath();
			g.arc(f.x * C + C / 2, f.y * C + C / 2, (6 + t * 60) * this.px, 0, Math.PI * 2);
			g.stroke();
		}
		g.restore();
	}

	// turns until the timer is due, last chart-width turns; vertical marks for dispatches and skipped cycles
	drawChart(sim)
	{
		const g = this.cctx;
		const r = this.chart.getBoundingClientRect();
		const dpr = window.devicePixelRatio || 1;
		const cw = Math.max(1, Math.round(r.width * dpr)), ch = Math.max(1, Math.round(r.height * dpr));
		if (this.chart.width !== cw || this.chart.height !== ch)
		{
			this.chart.width = cw;
			this.chart.height = ch;
		}
		g.setTransform(dpr, 0, 0, dpr, 0, 0);
		const W = r.width, H = r.height, pad = 18;
		g.fillStyle = '#050805';
		g.fillRect(0, 0, W, H);
		const span = Math.max(200, Math.round(W - 40));
		const hist = sim.history;
		const t1 = sim.turn, t0 = t1 - span;
		const visible = hist.filter(h => h.turn >= t0);
		let max = 100;
		for (const h of visible) max = Math.max(max, h.remaining);
		max = Math.ceil(max / 100) * 100;
		const X = t => 40 + (t - t0) * (W - 40) / span;
		const Y = v => H - pad - (Math.max(0, v) / max) * (H - pad - 8);
		g.font = '10px smallcaps-mono, "Courier New", monospace';
		g.textBaseline = 'middle';
		g.textAlign = 'right';
		g.lineWidth = 1;
		for (let v = 0; v <= max; v += max > 600 ? 200 : 100)
		{
			g.strokeStyle = COL.chartGrid;
			g.beginPath(); g.moveTo(40, Y(v) + 0.5); g.lineTo(W, Y(v) + 0.5); g.stroke();
			g.fillStyle = COL.chartText;
			g.fillText(String(v), 34, Y(v));
		}
		g.textAlign = 'left';
		g.textBaseline = 'bottom';
		const step = span > 800 ? 250 : 100;
		for (let t = Math.ceil(Math.max(0, t0) / step) * step; t <= t1; t += step)
		{
			g.fillStyle = COL.chartText;
			g.fillText(`T${t}`, X(t) + 2, H - 2);
			g.strokeStyle = COL.chartGrid;
			g.beginPath(); g.moveTo(X(t) + 0.5, 8); g.lineTo(X(t) + 0.5, H - pad); g.stroke();
		}
		for (const e of sim.events)
		{
			if (e.turn < t0)
				continue;
			const x = X(e.turn) + 0.5;
			if (e.kind === 'dispatch' || e.kind === 'skip' || e.kind === 'fail')
			{
				g.strokeStyle = e.kind === 'dispatch' ? COL.P : '#5a5a5a';
				g.setLineDash(e.kind === 'dispatch' ? [] : [2, 2]);
				g.beginPath(); g.moveTo(x, 6); g.lineTo(x, H - pad); g.stroke();
				g.setLineDash([]);
			}
			else if (e.kind === 'garrison')
			{
				g.fillStyle = COL.garrison;
				g.fillRect(x - 2, 4, 4, 4);
			}
			else if (e.kind === 'spotted')
			{
				g.fillStyle = '#ff4646';
				g.fillRect(x - 1.5, H - pad - 4, 3, 3);
			}
		}
		g.strokeStyle = COL.chartLine;
		g.lineWidth = 1.5;
		g.beginPath();
		let first = true;
		for (const h of visible)
		{
			const x = X(h.turn), y = Y(h.remaining);
			if (first) { g.moveTo(x, y); first = false; } else g.lineTo(x, y);
		}
		g.stroke();
		g.lineWidth = 1;
	}
}

root.Renderer = Renderer;
root.RENDER_COLORS = COL;
})(globalThis);
