/* Canvas renderer: Cogmind-style ASCII or tiles (robot sprites from noemica/cog-minder), zone grid, squad search
   areas, and the dispatch-timer chart. Reads Sim state only. */
(function (root) {
'use strict';

const D = root.Dispatch;
const C = 12;	// cell size in pixels (the cog-minder sprites are 12x12)
const GLYPH = 16;	// cogfont's glyphs sit small in their em box; 16 px fills a 12 px cell like Cogmind's square map font

const COL = {
	bg: '#000000',
	wall: ['#1a1f1a', '#3f473f', '#8c968c'],		// unknown / remembered / in view
	floor: ['#0d110d', '#1c241c', '#3e4d3e'],
	tileWall: ['#141814', '#2c332c', '#566056'],
	tileWallEdge: ['#1f251f', '#40493f', '#7d897d'],
	cogmind: '#d8ffd8',
	P: '#c45cff',
	Q: '#ff9a2e',
	exitOpen: '#f0c850',
	exitSeen: '#7d6a2c',
	exitCave: '#8a6a44',
	garrison: '#e2e24c',
	garrisonOff: '#8a3030',
	zoneFill: 'rgba(0, 204, 0, 0.08)',
	zoneLine: 'rgba(0, 150, 0, 0.45)',
	zoneLabel: 'rgba(0, 204, 0, 0.55)',
	zoneHere: '#00cc00',
	phase: ['#ffd84a', '#ff8a3a', '#ff4646'],
	trail: 'rgba(196, 92, 255, 0.55)',
	travel: '#00cc00',
	chartLine: '#00cc00',
	chartGrid: '#162416',
	chartText: '#747e83',
};

const phaseOf = p => (p.f10 > 0 ? 0 : p.f10 < 0 ? 1 : 2);

class Renderer
{
	constructor(canvas, chart)
	{
		this.canvas = canvas;
		this.ctx = canvas.getContext('2d');
		this.chart = chart;
		this.cctx = chart.getContext('2d');
		this.opts = { tiles: false, observer: true, zones: true, areas: true };
		this.base = document.createElement('canvas');
		this.baseKey = '';
		this.sprites = null;
		this.flashes = [];
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

	resize(sim)
	{
		const w = sim.w * C, h = sim.h * C;
		if (this.canvas.width !== w || this.canvas.height !== h)
		{
			this.canvas.width = w;
			this.canvas.height = h;
		}
		if (this.base.width !== w || this.base.height !== h)
		{
			this.base.width = w;
			this.base.height = h;
		}
	}

	cellAt(sim, clientX, clientY)
	{
		const r = this.canvas.getBoundingClientRect();
		const x = Math.floor((clientX - r.left) / r.width * sim.w);
		const y = Math.floor((clientY - r.top) / r.height * sim.h);
		return x >= 0 && y >= 0 && x < sim.w && y < sim.h ? { x, y } : null;
	}

	flash(x, y, color)
	{
		this.flashes.push({ x, y, color, t0: performance.now() });
	}

	glyph(g, ch, x, y, color)
	{
		g.fillStyle = color;
		g.fillText(ch, x * C + C / 2, y * C + C / 2 + 1);
	}

	setFont(g, px)
	{
		g.font = `${px}px cog-mono, "Courier New", monospace`;
		g.textAlign = 'center';
		g.textBaseline = 'middle';
	}

	drawBase(sim)
	{
		const key = `${sim.seed}:${sim.mapType}:${sim.fovVersion}:${this.opts.tiles}:${this.opts.observer}`;
		if (key === this.baseKey)
			return;
		this.baseKey = key;
		const g = this.base.getContext('2d');
		g.fillStyle = COL.bg;
		g.fillRect(0, 0, this.base.width, this.base.height);
		this.setFont(g, GLYPH);
		for (let y = 0; y < sim.h; y++)
		{
			for (let x = 0; x < sim.w; x++)
			{
				const i = y * sim.w + x;
				const cell = sim.cells[i];
				if (cell === D.MACHINE)
					continue;
				const lvl = sim.vis[i] ? 2 : sim.seen[i] ? 1 : 0;
				if (lvl === 0 && !this.opts.observer)
					continue;
				if (cell === D.WALL)
				{
					// only draw walls that touch floor, like a dug-out complex
					if (!this.touchesFloor(sim, x, y))
						continue;
					if (this.opts.tiles)
					{
						g.fillStyle = COL.tileWallEdge[lvl];
						g.fillRect(x * C, y * C, C, C);
						g.fillStyle = COL.tileWall[lvl];
						g.fillRect(x * C + 1, y * C + 1, C - 2, C - 2);
					}
					else
						this.glyph(g, '#', x, y, COL.wall[lvl]);
				}
				else if (this.opts.tiles)
				{
					g.fillStyle = COL.floor[lvl];
					g.fillRect(x * C + 5, y * C + 5, 2, 2);
				}
				else
					this.glyph(g, '.', x, y, COL.floor[lvl]);
			}
		}
	}

	touchesFloor(sim, x, y)
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

	draw(sim, hover)
	{
		this.resize(sim);
		this.drawBase(sim);
		const g = this.ctx;
		g.globalCompositeOperation = 'source-over';
		g.drawImage(this.base, 0, 0);
		if (this.opts.zones && sim.blocks)
			this.drawZones(g, sim);
		this.drawExits(g, sim);
		if (this.opts.areas)
			this.drawAreas(g, sim);
		this.drawRobots(g, sim);
		this.drawFlashes(g);
		if (hover)
		{
			g.strokeStyle = 'rgba(255,255,255,0.5)';
			g.lineWidth = 1;
			g.strokeRect(hover.x * C + 0.5, hover.y * C + 0.5, C - 1, C - 1);
		}
	}

	drawZones(g, sim)
	{
		const size = sim.blocks.size, credit = sim.blocks.credit, s = size * C;
		const px = (sim.player.x / size) | 0, py = (sim.player.y / size) | 0;
		g.save();
		for (let by = 0; by < sim.bh; by++)
		{
			for (let bx = 0; bx < sim.bw; bx++)
			{
				const k = by * sim.bw + bx;
				if (sim.explored[k])
				{
					g.fillStyle = COL.zoneFill;
					g.fillRect(bx * s, by * s, s, s);
				}
				else if (sim.enterable[k])
				{
					g.font = '10px smallcaps-mono, "Courier New", monospace';
					g.textAlign = 'left';
					g.textBaseline = 'top';
					g.fillStyle = COL.zoneLabel;
					g.fillText(`-${credit}t`, bx * s + 3, by * s + 3);
				}
			}
		}
		g.strokeStyle = COL.zoneLine;
		g.lineWidth = 1;
		g.setLineDash([3, 3]);
		g.beginPath();
		for (let bx = 1; bx < sim.bw; bx++) { g.moveTo(bx * s + 0.5, 0); g.lineTo(bx * s + 0.5, sim.h * C); }
		for (let by = 1; by < sim.bh; by++) { g.moveTo(0, by * s + 0.5); g.lineTo(sim.w * C, by * s + 0.5); }
		g.stroke();
		g.setLineDash([]);
		g.strokeStyle = COL.zoneHere;
		g.strokeRect(px * s + 0.5, py * s + 0.5, Math.min(s, sim.w * C - px * s) - 1, Math.min(s, sim.h * C - py * s) - 1);
		g.restore();
	}

	drawExits(g, sim)
	{
		this.setFont(g, GLYPH);
		for (const e of sim.exits)
		{
			if (!this.opts.observer && !sim.seen[e.idx])
				continue;
			if (e.kind === 'garrison')
			{
				g.fillStyle = e.prop.disabled ? '#2a0e0e' : '#2c2c0c';
				g.fillRect(e.x * C, e.y * C, C, C);
				this.glyph(g, e.prop.disabled ? 'x' : 'G', e.x, e.y, e.prop.disabled ? COL.garrisonOff : COL.garrison);
			}
			else
			{
				const color = e.flag !== 1 ? COL.exitCave : sim.vis[e.idx] ? COL.exitSeen : COL.exitOpen;
				g.fillStyle = '#000';
				g.fillRect(e.x * C, e.y * C, C, C);
				this.glyph(g, '>', e.x, e.y, color);
			}
		}
	}

	drawAreas(g, sim)
	{
		g.save();
		g.lineWidth = 1;
		for (const p of sim.parties)
		{
			const a = p.area, color = COL.phase[phaseOf(p)];
			const x = a.x1 * C, y = a.y1 * C, w = (a.x2 - a.x1 + 1) * C, h = (a.y2 - a.y1 + 1) * C;
			g.globalAlpha = 0.06;
			g.fillStyle = color;
			g.fillRect(x, y, w, h);
			g.globalAlpha = 0.85;
			g.strokeStyle = color;
			g.setLineDash([6, 4]);
			g.strokeRect(x + 0.5, y + 0.5, w - 1, h - 1);
			g.setLineDash([]);
			// dispatch trail from the entry point to the area centre, fading over 120 turns
			const age = sim.turn - p.spawnTurn;
			if (age < 120)
			{
				g.globalAlpha = 1 - age / 120;
				g.strokeStyle = COL.trail;
				g.beginPath();
				g.moveTo(p.origin.x * C + C / 2, p.origin.y * C + C / 2);
				g.lineTo((a.x1 + a.x2 + 1) * C / 2, (a.y1 + a.y2 + 1) * C / 2);
				g.stroke();
			}
		}
		g.restore();
	}

	drawRobots(g, sim)
	{
		this.setFont(g, GLYPH);
		const tiles = this.opts.tiles && this.sprites;
		for (const b of sim.bots)
		{
			const i = b.y * sim.w + b.x, inView = !!sim.vis[i];
			if (!inView && !this.opts.observer)
				continue;
			g.globalAlpha = inView ? 1 : 0.55;
			g.fillStyle = '#000';
			g.fillRect(b.x * C, b.y * C, C, C);
			if (tiles)
			{
				g.globalCompositeOperation = 'lighter';
				g.drawImage(this.sprites[b.cls], b.x * C, b.y * C);
				g.globalCompositeOperation = 'source-over';
			}
			else
				this.glyph(g, D.ROBOT_CLASS[b.cls].glyph, b.x, b.y, COL[b.cls]);
			if (b.party && b.party.leader === b && b.party.sees)
			{
				g.fillStyle = '#ff4646';
				g.fillRect(b.x * C + C - 3, b.y * C, 3, 3);
			}
		}
		g.globalAlpha = 1;
		const p = sim.player;
		g.fillStyle = '#000';
		g.fillRect(p.x * C, p.y * C, C, C);
		if (tiles)
		{
			g.globalCompositeOperation = 'lighter';
			g.drawImage(this.sprites.cog, p.x * C, p.y * C);
			g.globalCompositeOperation = 'source-over';
		}
		else
			this.glyph(g, '@', p.x, p.y, COL.cogmind);
		if (sim.travel >= 0)
		{
			const tx = sim.travel % sim.w, ty = (sim.travel / sim.w) | 0;
			g.strokeStyle = COL.travel;
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
			g.lineWidth = 2;
			g.beginPath();
			g.arc(f.x * C + C / 2, f.y * C + C / 2, 4 + t * 40, 0, Math.PI * 2);
			g.stroke();
		}
		g.restore();
	}

	// turns until the timer is due, last chart-width turns; vertical marks for dispatches and skipped cycles
	drawChart(sim)
	{
		const g = this.cctx, W = this.chart.width, H = this.chart.height, pad = 18;
		g.fillStyle = '#050805';
		g.fillRect(0, 0, W, H);
		const hist = sim.history;
		const t1 = sim.turn, t0 = t1 - W + 40;
		const visible = hist.filter(h => h.turn >= t0);
		let max = 100;
		for (const h of visible) max = Math.max(max, h.remaining);
		max = Math.ceil(max / 100) * 100;
		const X = t => 40 + (t - t0);
		const Y = v => H - pad - (Math.max(0, v) / max) * (H - pad - 8);
		g.font = '10px smallcaps-mono, "Courier New", monospace';
		g.textBaseline = 'middle';
		g.textAlign = 'right';
		for (let v = 0; v <= max; v += max > 600 ? 200 : 100)
		{
			g.strokeStyle = COL.chartGrid;
			g.beginPath(); g.moveTo(40, Y(v) + 0.5); g.lineTo(W, Y(v) + 0.5); g.stroke();
			g.fillStyle = COL.chartText;
			g.fillText(String(v), 34, Y(v));
		}
		g.textAlign = 'left';
		g.textBaseline = 'bottom';
		for (let t = Math.ceil(t0 / 250) * 250; t <= t1; t += 250)
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
