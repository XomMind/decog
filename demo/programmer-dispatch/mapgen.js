/* DF map generator ("tunnelers + room builders + cleanup passes") of COGMIND.exe Beta 17.1, ported to JS.

   Settings: the Beta 17.1 map records in data/messages.bin (mapgen-params.js; read with the field order of
   OpW7_GenSettings::load 0x4bf380 as C065_Rec517960 0x517960 loads it). Field meaning follows A2SSettings::read
   0x4bd340 (src/util/alpha2_09.cpp), the text-config parser for the same struct. Access has two records, 300x150 and
   150x300; BS::initilize (0x7026b0) picks one per location like any multi-record map type.

   Control flow follows functions this repo has matched byte-for-byte (names are the repo's placeholders):
     A2IGenerator::init               0x4bf610  src/util/alpha2_10.cpp   variant pick, feature groups, prefab/area paint
     OpW7_Generator::placeTunnelers   0x4c15a0  src/op/op_w7_df.cpp      [TUNNELER] starts
     A2GGenerator::generate           0x4c1880  src/util/alpha2_07.cpp   builder turns, cleanup stages, validation
     OpW7_Tunneler::measure/dig       0x4b9a30 / 0x4b9ca0
     OpW7_Tunneler::build/spawn       0x4b9f20 / 0x4bb040
     OpW7_Roomie::measure/build       0x4bc630 / 0x4bcb80
     OpW7_WallThinner::thinWalls      0x4c36c0  (OpW7_getWallFacing 0x4c3400)
     OpW7_Generator::findCaves        0x4c3b20  (OpW7_fillArea 0x4c39c0, OpW7_isFloor 0x4c3950, OpW7_removeCorridorAt 0x4c37f0)
     OpW7_FloorFiller::fillCorners    0x4c42e0  (OpW7_getFloorCorner 0x4c4020)
     OpW7_FloorFiller::fillWideCorners 0x4c47d0 (OpW7_getWideFloorCorner 0x4c4410)
     OpW7_Generator::fitCaves         0x4c52a0  (measureWallEdges 0x4c4a00, measureWallInset 0x4c4cd0, findOpenSides 0x4c4f60,
                                                 largestRemainder 0x4c50c0)
     OpW7_Generator::removeBlockedDoors 0x4c6b00
     OpW7_Generator::addRoomCorridors 0x4c6c50  (OpW7_digCorridor 0x4c6500, OpW7_isClearSides 0x4c6440)
     OpW7_Generator::checkStarts      0x4c7100
   The retry loop is BS::initilize (0x7026b0, src/util/echo_03.cpp): init + placeTunnelers + generate until the
   map passes validation, without reseeding. Stages 5/6 (widenUnknown9c 0x4c61c0, growUnknown9c 0x4c6260) run on a
   list nothing in the DF path fills, so they are no-ops and are not ported; traceRooms (0x4c7950) and
   finalizeWalls (0x4c7420) only run for Garrison/Scraptown and one special mode. The final terrain conversion
   (generator cell 0-3 -> earth, 10/11 door, 12/13 shortcut, 14/15 phase wall, rest floor) is echo_03.cpp:1009.

   NOT from the decomp: prefab content. Prefab art (.xp layers) is not embedded. Each prefab feature is replaced by a
   stand-in carved at the game's chosen position and rotation with the prefab's real size: a 1-cell border of
   permanent wall (generator cell 0) around room floor (cell 7, registered as a type-3 "prefab room" like the game's
   flood fill of prefab floor). The real prefab marks its exits in layer 1 and the generator starts a [LINKER]
   tunneler outward from each; the stand-in opens one side per side letter of the prefab's name (S, EW, NS...; read
   from the older text configs, since Beta 17 stores no prefab names; unknown = every side, none = south), rotated
   with the prefab, 3 wide on sides of 7+ cells else 1, at the spot with the deepest solid rock ahead, and starts the
   same [LINKER] tunneler there. Exact RNG call order is not reproduced. DOM-free; node can require() it. */
(function (root) {
'use strict';

const PARAMS = root.MAPGEN_PARAMS || (typeof require === 'function' ? require('./mapgen-params.js') : null);

// cell codes of the returned map (shared with sim.js / props.js)
const CELL = { WALL: 0, FLOOR: 1, DOOR: 2, MACHINE: 3 };

// zone short names, string table filled at 0xb27788 (index = map type)
const ZONES = ['SAN', 'YRD', 'MAT', 'FAC', 'RES', 'ACC', 'SUR', 'MIN', 'EXI', 'STO', 'REC', 'SCR', 'WAS', 'GAR', 'DSF',
	'SUB', 'LOW', 'UPP', 'PRO', 'DEE', 'ZIO', 'DAT', 'ZHI', 'WAR', 'EXT', 'CET', 'ARC', 'HUB', 'ARM', 'LAB', 'QUA',
	'TES', 'SEC', 'FRG', 'COM', 'AC0', 'LAI', 'TOW'];

// generator cell values (Array2D<int> 0xcf1964)
const G_BLOCKED = 0;	// permanent wall (BLOCKED features, stand-in prefab walls)
const G_SOLID = 3;		// undug, diggable
const G_TUNNEL = 4;
const G_JUNCTION = 5;
const G_HALL = 6;
const G_ROOM = 7;

// direction tables: left 0xbb8350, right 0xbb8340, back 0xbb8360; OpB_translateRotated (0x446dd0) axes
const LEFT = [3, 0, 1, 2], RIGHT = [1, 2, 3, 0], BACK = [2, 3, 0, 1];
const LX = [1, 0, -1, 0], LY = [0, 1, 0, -1];	// lateral (+ = right of facing)
const FX = [0, 1, 0, -1], FY = [-1, 0, 1, 0];	// forward
const ROTATIONS = [2, 3, 0, 1];	// 0xbb8370: clockwise quarter turns for a prefab facing N/E/S/W
const SPAWN_TYPES = ['enter', 'exit', 'either', 'neither'];

const trunc = Math.trunc;
const tr = (p, dir, lat, fwd) => ({ x: p.x + LX[dir] * lat + FX[dir] * fwd, y: p.y + LY[dir] * lat + FY[dir] * fwd });
const at = (arr, i) => arr[i < arr.length ? i : arr.length - 1];

// Rect helpers (0x40a9a0 contains, 0x40ad80 onOutline, 0x40ae20 distance, 0x40aa70 containsRect, 0x40ab30 intersect)
const rContains = (r, x, y) => x >= r.x && x < r.x + r.w && y >= r.y && y < r.y + r.h;
const rOnOutline = (r, x, y) => ((x === r.x - 1 || x === r.x + r.w) && y >= r.y && y < r.y + r.h)
	|| ((y === r.y - 1 || y === r.y + r.h) && x >= r.x && x < r.x + r.w);
function rDistance(a, b)
{
	let d = 0;
	const gx = Math.max(a.x, b.x) - Math.min(a.x + a.w - 1, b.x + b.w - 1);
	if (gx > 0)
		d += gx;
	const gy = Math.max(a.y, b.y) - Math.min(a.y + a.h - 1, b.y + b.h - 1);
	if (gy > 0)
		d += gy;
	return d;
}
const rContainsRect = (a, b) => rContains(a, b.x, b.y) && rContains(a, b.x + b.w - 1, b.y)
	&& rContains(a, b.x, b.y + b.h - 1) && rContains(a, b.x + b.w - 1, b.y + b.h - 1);
function rIntersect(a, b)
{
	const x = Math.max(a.x, b.x), y = Math.max(a.y, b.y);
	return { x, y, w: Math.min(a.x + a.w - 1, b.x + b.w - 1) - x + 1, h: Math.min(a.y + a.h - 1, b.y + b.h - 1) - y + 1 };
}
const rArea = r => r.w * r.h;
const rEquals = (a, b) => a.x === b.x && a.y === b.y && a.w === b.w && a.h === b.h;

// ---------------------------------------------------------------------------------------------------------------
// Generator state (DF::Generator 0xd31580 and the DF globals)
// ---------------------------------------------------------------------------------------------------------------

class Generator
{
	constructor(P, rng)
	{
		this.P = P;
		this.rng = rng;
		this.w = P.w;
		this.h = P.h;
		this.grid = new Int8Array(P.w * P.h);
		// template tunneler at settings+0x58 (Tunneler::load 0x447fc0): width, segment, turn, branch on straight,
		// branch on turn, room left, room right; the spawn/linker children copy it
		const t = P.template;
		this.T = { width: t[0], p24: t[1], p28: t[2], p2C: t[3], p30: t[4], p34: t[5], p38: t[6] };
	}

	inb(x, y) { return x >= 0 && y >= 0 && x < this.w && y < this.h; }
	// out-of-bounds reads answer "solid": the exe never reads there for valid maps
	get(x, y) { return x >= 0 && y >= 0 && x < this.w && y < this.h ? this.grid[y * this.w + x] : G_SOLID; }
	set(x, y, v) { if (x >= 0 && y >= 0 && x < this.w && y < this.h) this.grid[y * this.w + x] = v; }

	// RNG helpers with the exe's semantics
	range(r) { return r[0] === r[1] ? r[1] : this.rng.rangeInt(r[0], r[1]); }	// randomInRange_40c130
	vary(v) { const m = this.P.mutationVariance; return Math.max(0, this.rng.rangeInt(-m, m) + v); }	// 0x4489a0
	pickWeight(weights)	// WeightTable::pick 0x4481f0: returns an index
	{
		let total = 0;
		for (const w of weights)
			total += w;
		if (total <= 0)
			return 0;
		const roll = this.rng.rangeInt(1, total);
		let sum = 1;
		for (let i = 0; i < weights.length; i++)
		{
			sum += weights[i];
			if (sum > roll)
				return i;
		}
		return 0;
	}
	pickIndex(flags, value)	// 0x9d4b30: random index whose flag equals value
	{
		const m = [];
		for (let i = 0; i < flags.length; i++)
			if (flags[i] === value)
				m.push(i);
		return m.length ? this.rng.pick(m) : 0;
	}

	// ---- A2IGenerator::init (0x4bf610) ----
	init(branches)
	{
		const P = this.P, rng = this.rng;
		this.grid.fill(G_SOLID);
		this.rooms = [];
		this.corridors = [];	// 0xd1f31c: junction rects dug with cell 5
		this.caves = [];		// generator +0x8c
		this.boxes = [];		// 0xd222f0: halls
		this.blobs = [];		// 0xcf65c4: shortcut corridors
		this.reserved = [];
		this.turn = 0;
		this.builders = [];
		this.exits = [];
		this.roomCounts = [0, 0, 0];
		const spawnOn = P.tunnelers.map(() => true);
		this.spawnOn = spawnOn;
		const featOn = P.features.map(() => true);
		let found = false;
		P.tunnelers.forEach((s, i) =>
		{
			if (s.chance !== -1 && s.chance < 100 && !rng.chance(s.chance))
				spawnOn[i] = false;
			else
				found = true;
		});
		P.features.forEach((f, i) =>
		{
			if (f.chance !== -1 && f.chance < 100 && !rng.chance(f.chance))
				featOn[i] = false;
		});
		// variant ("level") pick
		const levels = [], weights = [];
		const list = found ? P.tunnelers : P.features;
		list.forEach((s, i) =>
		{
			if ((found ? spawnOn[i] : featOn[i]) && s.level && !levels.includes(s.level))
			{
				levels.push(s.level);
				weights.push(found ? s.weight : 100);
			}
		});
		this.level = levels.length ? levels[this.pickWeight(weights)] : 0;
		const lv = f => f.level === this.level || f.level === 0;
		// one record survives per feature group
		const groups = [];
		let ok;
		do
		{
			ok = false;
			for (let i = 0; i < P.features.length; i++)
			{
				const f = P.features[i];
				if (featOn[i] && lv(f) && f.group && !groups.includes(f.group))
				{
					ok = true;
					const vec = [i];
					for (let j = i + 1; j < P.features.length; j++)
						if (featOn[j] && lv(P.features[j]) && P.features[j].group === f.group)
							vec.push(j);
					vec.splice(rng.rangeInt(0, vec.length - 1), 1);
					for (const k of vec)
						featOn[k] = false;
					groups.push(f.group);
				}
			}
		}
		while (ok);
		// chance -1 records are kept only while the location still needs an exit with that suffix (0xcf123c,
		// filled in BS::initilize from the location's branch links)
		const current = [];
		P.features.forEach((f, i) => { if (featOn[i] && f.chance === -1 && lv(f)) current.push(i); });
		rng.shuffle(current);
		const suffix = f => f.kind === 'branch-exit' ? ZONES[f.dest] : f.tag || f.kind;
		let parts;
		if (branches)
			parts = branches.map(b => typeof b === 'number' ? ZONES[b] : b);
		else
		{
			parts = [];
			for (const i of current)
				if (!parts.includes(suffix(P.features[i])))
					parts.push(suffix(P.features[i]));
		}
		for (let i = 0; i < current.length; i++)
		{
			const k = parts.indexOf(suffix(P.features[current[i]]));
			if (k !== -1)
			{
				parts.splice(k, 1);
				current.splice(i, 1);
				i--;
			}
		}
		for (const i of current)
			featOn[i] = false;
		// paint areas and prefabs
		const prefabs = [];
		P.features.forEach((f, i) =>
		{
			if (!featOn[i] || !lv(f))
				return;
			if (f.cell !== undefined)	// area record (type < 21)
			{
				const a = { x: this.range(f.x), y: this.range(f.y), w: this.range(f.w), h: this.range(f.h) };
				if (a.x < 1)
				{
					a.w -= 1 - a.x;
					a.x = 1;
				}
				if (a.y < 1)
				{
					a.h -= 1 - a.y;
					a.y = 1;
				}
				if (a.x + a.w >= this.w - 1)
					a.w = this.w - 2 - a.x;
				if (a.y + a.h >= this.h - 1)
					a.h = this.h - 2 - a.y;
				const v = f.cell;	// A2IGenerator::init paints the record type as the cell value
				for (let x = a.x; x < a.x + a.w; x++)
					for (let y = a.y; y < a.y + a.h; y++)
						this.set(x, y, v);
				if (f.kind === 'blocked')
					this.reserved.push({ x: a.x, y: a.y, w: a.w, h: a.h, kind: 'blocked', dest: -1 });
			}
			else
				prefabs.push(this.paintPrefab(f));
		});
		for (const p of prefabs)
			this.openPrefab(p);
	}

	// stand-in for a prefab image: real size and rotation, wall border, room floor inside
	paintPrefab(f)
	{
		const rotation = this.rng.pick(f.dirs);
		const turns = ROTATIONS[rotation];
		let w = f.w[0], h = f.h[0];
		if (turns & 1)
		{
			const t = w;
			w = h;
			h = t;
		}
		const x0 = this.range(f.x), y0 = this.range(f.y);
		const r = { x: Math.max(0, x0), y: Math.max(0, y0) };
		r.w = Math.min(this.w, x0 + w) - r.x;
		r.h = Math.min(this.h, y0 + h) - r.y;
		const room = { type: 3, x: -1, y: -1, w: 0, h: 0, cells: [], doors: [], doorDirs: [], corridors: [], bbox: r };
		for (let x = r.x; x < r.x + r.w; x++)
		{
			for (let y = r.y; y < r.y + r.h; y++)
			{
				const edge = x === r.x || y === r.y || x === r.x + r.w - 1 || y === r.y + r.h - 1;
				this.set(x, y, edge ? G_BLOCKED : G_ROOM);
				if (!edge)
					room.cells.push([x, y]);
			}
		}
		this.rooms.push(room);
		const sides = (f.sides || 'S').split('').map(c => ('NESW'.indexOf(c) + turns) % 4);
		const entry = { x: r.x, y: r.y, w: r.w, h: r.h, kind: f.kind, dest: f.dest, sealed: !!f.sealed, openings: [] };
		if (f.tag)
			entry.tag = f.tag;
		this.reserved.push(entry);
		return { r, room, sides, entry };
	}

	// openings + [LINKER] tunnelers (the exe does this per exit cell of prefab layer 1)
	openPrefab({ r, room, sides, entry })
	{
		// One opening per side letter. Tunneler::build stops without digging when the free length ahead is under
		// two segments, so an opening needs that much solid rock ahead (the real prefabs place their exits facing
		// open rock); a side without it falls back to an unused side, and a prefab that fits nowhere takes the
		// deepest spot it has.
		const need = 2 * this.P.linker[1][1] + 2;
		let missing = 0;
		for (const d of sides)
			if (!this.openSide(r, room, entry, d, need))
				missing++;
		for (let d = 0; d < 4 && missing > 0; d++)
			if (!sides.includes(d) && this.openSide(r, room, entry, d, need))
				missing--;
		if (!entry.openings.length)
			for (let d = 0; d < 4 && !entry.openings.length; d++)
				this.openSide(r, room, entry, d, 2);
	}

	openSide(r, room, entry, d, minDepth)
	{
		const len = d === 0 || d === 2 ? r.w : r.h;
		const ow = len - 2 >= 7 ? 3 : 1;
		const L = this.P.linker;
		const need = 2 * L[1][1] + 2;
		const cands = [];
		let best = minDepth;
		for (let t = 1; t + ow <= len - 1; t++)
		{
			// border cell at index t along the side; the opening runs along the outward tunneler's lateral axis
			let target;
			switch (d)
			{
				case 0: target = { x: r.x + t, y: r.y }; break;
				case 1: target = { x: r.x + r.w - 1, y: r.y + t }; break;
				case 2: target = { x: r.x + r.w - 1 - t, y: r.y + r.h - 1 }; break;
				case 3: target = { x: r.x, y: r.y + r.h - 1 - t }; break;
			}
			let depth = 0;
			depth:
			for (let k = 1; k <= need; k++)
			{
				for (let i = -1; i <= ow; i++)
				{
					const o = tr(target, d, i, k);
					if (o.x < 1 || o.y < 1 || o.x >= this.w - 1 || o.y >= this.h - 1 || this.get(o.x, o.y) !== G_SOLID)
						break depth;
				}
				depth = k;
			}
			if (depth < best)
				continue;
			if (depth > best)
			{
				best = depth;
				cands.length = 0;
			}
			cands.push(target);
		}
		if (!cands.length)
			return false;
		const target = this.rng.pick(cands);
		for (let i = 0; i < ow; i++)
		{
			const c = tr(target, d, i, 0);
			this.set(c.x, c.y, G_ROOM);
			room.cells.push([c.x, c.y]);
			entry.openings.push([c.x, c.y]);
		}
		this.builders.push(new Tunneler(this, 0, d, target, this.range(L[0]), ow, this.range(L[1]), this.range(L[2]),
			this.range(L[3]), this.range(L[4]), this.range(L[5]), this.range(L[6]), this.range(L[7]), true));
		this.exits.push(tr(target, d, 0, 1));
		return true;
	}

	// ---- OpW7_Generator::placeTunnelers (0x4c15a0) ----
	placeTunnelers()
	{
		this.starts = [];
		this.P.tunnelers.forEach((s, i) =>
		{
			if (this.spawnOn[i] && (s.level === this.level || s.level === 0))
			{
				let tries = 0;
				do
				{
					const pos = { x: this.range(s.x), y: this.range(s.y) };
					if (this.get(pos.x, pos.y) === G_SOLID)
					{
						const p = s.p.map(r => this.range(r));
						this.builders.push(new Tunneler(this, this.range(s.delay), this.rng.pick(s.dirs), pos, p[0], p[1], p[2], p[3],
							p[4], p[5], p[6], p[7], p[8], false));
						this.starts.push(pos);
						break;
					}
					else if (s.x[0] === s.x[1] && s.y[0] === s.y[1])
					{
						this.starts.push(null);
						break;
					}
				}
				while (++tries < 1000);
				if (tries === 1000)
					this.starts.push(null);
			}
			else
				this.starts.push(null);
		});
	}

	// ---- A2GGenerator::generate (0x4c1880), run to completion; returns 12 on success like the exe's result code ----
	generate()
	{
		while (this.builders.length)
		{
			let paused = true;
			while (paused)
			{
				paused = false;
				for (let i = 0; i < this.builders.length; i++)
				{
					switch (this.builders[i].build())
					{
						case 0:
							this.builders.splice(i, 1);
							i--;
							break;
						case 2:
							paused = true;
							break;
					}
				}
			}
			this.turn++;
		}
		this.assignDoors();
		if (!this.P.skipCleanup)
		{
			this.thinWalls();
			this.findCaves();
			this.fillCorners();
			this.fillWideCorners();
			this.fillCorners();
			this.fitCaves();
			this.removeBlockedDoors();
			this.addRoomCorridors();
		}
		return this.validate();
	}

	// stage -1: doors next to rooms
	assignDoors()
	{
		for (let x = 1; x < this.w - 1; x++)
		{
			for (let y = 1; y < this.h - 1; y++)
			{
				const c = this.get(x, y);
				if (c !== 10 && c !== 11)
					continue;
				for (const room of this.rooms)
				{
					let adjacent = false;
					if (room.x !== -1)
						adjacent = rOnOutline(room, x, y);
					else if (x >= room.bbox.x - 1 && y >= room.bbox.y - 1 && x <= room.bbox.x + room.bbox.w && y <= room.bbox.y + room.bbox.h)
						adjacent = room.cells.some(([cx, cy]) => Math.abs(cx - x) + Math.abs(cy - y) === 1);
					if (adjacent)
					{
						room.doors.push([x, y]);
						if (this.get(x - 1, y) === G_ROOM)
							room.doorDirs.push(1);
						else if (this.get(x + 1, y) === G_ROOM)
							room.doorDirs.push(3);
						else if (this.get(x, y - 1) === G_ROOM)
							room.doorDirs.push(2);
						else if (this.get(x, y + 1) === G_ROOM)
							room.doorDirs.push(0);
					}
				}
			}
		}
	}

	// ---- OpW7_WallThinner::thinWalls (0x4c36c0): undig 1-wide dead-end tunnel tips ----
	wallFacing(x, y)
	{
		const g = (a, b) => this.get(a, b);
		if (g(x, y) !== G_TUNNEL)
			return 4;
		if (g(x - 1, y) <= 3 && g(x + 1, y) <= 3 && g(x - 1, y + 1) <= 3 && g(x, y + 1) <= 3 && g(x + 1, y + 1) <= 3)
			return 0;
		if (g(x - 1, y - 1) <= 3 && g(x, y - 1) <= 3 && g(x - 1, y) <= 3 && g(x - 1, y + 1) <= 3 && g(x, y + 1) <= 3)
			return 1;
		if (g(x - 1, y - 1) <= 3 && g(x, y - 1) <= 3 && g(x + 1, y - 1) <= 3 && g(x - 1, y) <= 3 && g(x + 1, y) <= 3)
			return 2;
		if (g(x, y - 1) <= 3 && g(x + 1, y - 1) <= 3 && g(x + 1, y) <= 3 && g(x, y + 1) <= 3 && g(x + 1, y + 1) <= 3)
			return 3;
		return 4;
	}
	thinWalls()
	{
		for (let x = 1; x < this.w - 1; x++)
		{
			for (let y = 1; y < this.h - 1; y++)
			{
				if (this.get(x, y) !== G_TUNNEL)
					continue;
				let facing = this.wallFacing(x, y), tx = x, ty = y;
				while (facing !== 4)
				{
					this.set(tx, ty, G_SOLID);
					switch (facing)
					{
						case 0: ty--; break;
						case 1: tx++; break;
						case 2: ty++; break;
						case 3: tx--; break;
					}
					facing = this.wallFacing(tx, ty);
				}
			}
		}
	}

	// ---- OpW7_removeCorridorAt (0x4c37f0) ----
	removeCorridorAt(x, y)
	{
		if (this.get(x, y) !== G_JUNCTION)
			return;
		for (let i = 0; i < this.corridors.length; i++)
		{
			const c = this.corridors[i];
			if (rContains(c, x, y))
			{
				for (let cx = c.x; cx < c.x + c.w; cx++)
					for (let cy = c.y; cy < c.y + c.h; cy++)
						this.set(cx, cy, G_TUNNEL);
				this.corridors.splice(i, 1);
				break;
			}
		}
	}

	// ---- OpW7_Generator::findCaves (0x4c3b20): dig out small solid pockets enclosed by tunnels ----
	// OpW7_fillArea gives up past [FLOODFILL_AREA_MAX] cells, so a pocket qualifies exactly when its whole
	// 4-connected solid component is that small and touches no room/door/hall (OpW7_isFloor's door flag).
	findCaves()
	{
		const P = this.P, W = this.w, H = this.h;
		const visited = new Uint8Array(W * H);
		const stack = [];
		for (let x = 1; x < W - 1; x++)
		{
			for (let y = 1; y < H - 1; y++)
			{
				if (this.grid[y * W + x] !== G_SOLID || visited[y * W + x])
					continue;
				const cells = [];
				let door = false;
				visited[y * W + x] = 1;
				stack.push(y * W + x);
				while (stack.length)
				{
					const i = stack.pop(), cx = i % W, cy = (i - cx) / W;
					cells.push(i);
					const nb = [[cx - 1, cy], [cx + 1, cy], [cx, cy - 1], [cx, cy + 1]];
					for (const [nx, ny] of nb)
					{
						if (!this.inb(nx, ny))
							continue;
						const j = ny * W + nx, v = this.grid[j];
						if (v === G_SOLID)
						{
							if (!visited[j])
							{
								visited[j] = 1;
								stack.push(j);
							}
						}
						else if (v > G_JUNCTION)
							door = true;
					}
				}
				if (door || cells.length > P.floodfillAreaMax)
					continue;
				// the exe keeps its scan order: the first cell is the seed and stays solid
				cells.sort((a, b) => (a % W) - (b % W) || a - b);
				const fx = cells[0] % W, fy = (cells[0] - fx) / W;
				const cave = { x: fx, y: fy, w: fx, h: fy };
				for (let k = 1; k < cells.length; k++)
				{
					const px = cells[k] % W, py = (cells[k] - px) / W;
					this.grid[cells[k]] = G_TUNNEL;
					this.removeCorridorAt(px - 1, py);
					this.removeCorridorAt(px + 1, py);
					this.removeCorridorAt(px, py - 1);
					this.removeCorridorAt(px, py + 1);
					if (px < cave.x)
						cave.x = px;
					else if (px > cave.w)
						cave.w = px;
					if (py < cave.y)
						cave.y = py;
					else if (py > cave.h)
						cave.h = py;
				}
				cave.w = cave.w - cave.x + 1;
				cave.h = cave.h - cave.y + 1;
				this.caves.push(cave);
			}
		}
		const caves = this.caves;
		for (let i = 0; i < caves.length; i++)
		{
			for (let j = i + 1; j < caves.length; j++)
			{
				if (rDistance(caves[i], caves[j]) <= P.floodfillMergeRange)
				{
					const l = Math.min(caves[i].x, caves[j].x), t = Math.min(caves[i].y, caves[j].y);
					const r = Math.max(caves[i].x + caves[i].w - 1, caves[j].x + caves[j].w - 1);
					const b = Math.max(caves[i].y + caves[i].h - 1, caves[j].y + caves[j].h - 1);
					caves[i] = { x: l, y: t, w: r - l + 1, h: b - t + 1 };
					caves.splice(j, 1);
					j--;
				}
			}
		}
	}

	// ---- OpW7_FloorFiller::fillCorners (0x4c42e0) / fillWideCorners (0x4c47d0) ----
	floorCorner(x, y)
	{
		const g = (a, b) => this.get(a, b) === G_TUNNEL;
		if (this.get(x, y) !== G_SOLID)
			return 4;
		if (g(x - 1, y) && g(x + 1, y) && g(x - 1, y + 1) && g(x, y + 1) && g(x + 1, y + 1))
			return 0;
		if (g(x - 1, y - 1) && g(x, y - 1) && g(x - 1, y) && g(x - 1, y + 1) && g(x, y + 1))
			return 1;
		if (g(x - 1, y - 1) && g(x, y - 1) && g(x + 1, y - 1) && g(x - 1, y) && g(x + 1, y))
			return 2;
		if (g(x, y - 1) && g(x + 1, y - 1) && g(x + 1, y) && g(x, y + 1) && g(x + 1, y + 1))
			return 3;
		return 4;
	}
	fillCorners()
	{
		for (let x = 1; x < this.w - 1; x++)
		{
			for (let y = 1; y < this.h - 1; y++)
			{
				if (this.get(x, y) !== G_SOLID)
					continue;
				let facing = this.floorCorner(x, y), tx = x, ty = y;
				while (facing !== 4)
				{
					this.set(tx, ty, G_TUNNEL);
					switch (facing)
					{
						case 0: ty--; break;
						case 1: tx++; break;
						case 2: ty++; break;
						case 3: tx--; break;
					}
					facing = this.floorCorner(tx, ty);
				}
			}
		}
	}
	wideFloorCorner(x, y)
	{
		const s = (a, b) => this.get(a, b) === G_SOLID, g = (a, b) => this.get(a, b) === G_TUNNEL;
		if (!s(x, y))
			return 4;
		if (s(x + 1, y) && g(x + 1, y + 1) && g(x - 1, y) && g(x + 2, y) && g(x - 1, y + 1) && g(x, y + 1) && g(x + 2, y + 1))
			return 0;
		if (s(x, y + 1) && g(x - 1, y + 1) && g(x - 1, y - 1) && g(x, y - 1) && g(x - 1, y) && g(x - 1, y + 2) && g(x, y + 2))
			return 1;
		if (s(x - 1, y) && g(x - 1, y - 1) && g(x - 2, y - 1) && g(x, y - 1) && g(x + 1, y - 1) && g(x - 2, y) && g(x + 1, y))
			return 2;
		if (s(x, y - 1) && g(x + 1, y - 1) && g(x, y - 2) && g(x + 1, y - 2) && g(x + 1, y) && g(x, y + 1) && g(x + 1, y + 1))
			return 3;
		return 4;
	}
	fillWideCorners()
	{
		for (let x = 1; x < this.w - 1; x++)
		{
			for (let y = 1; y < this.h - 1; y++)
			{
				if (this.get(x, y) !== G_SOLID)
					continue;
				let facing = this.wideFloorCorner(x, y), tx = x, ty = y;
				while (facing !== 4)
				{
					this.set(tx, ty, G_TUNNEL);
					switch (facing)
					{
						case 0: this.set(tx + 1, ty, G_TUNNEL); ty--; break;
						case 1: this.set(tx, ty + 1, G_TUNNEL); tx++; break;
						case 2: this.set(tx - 1, ty, G_TUNNEL); ty++; break;
						case 3: this.set(tx, ty - 1, G_TUNNEL); tx--; break;
					}
					facing = this.wideFloorCorner(tx, ty);
				}
			}
		}
	}

	// ---- OpW7_Generator::fitCaves (0x4c52a0): turn the dug pockets into rectangular halls (cell 6) ----
	rowFull(x0, x1, y) { for (let x = x0; x < x1; x++) if (this.get(x, y) !== G_TUNNEL) return false; return true; }
	colFull(y0, y1, x) { for (let y = y0; y < y1; y++) if (this.get(x, y) !== G_TUNNEL) return false; return true; }
	measureWallEdges(r, depth, area)	// 0x4c4a00
	{
		let i;
		for (i = 0; i < r.h && !this.rowFull(r.x, r.x + r.w, r.y + i); i++);
		depth[0] = i;
		area[0] = i === 0 ? 0 : (r.h - i) * r.w;
		for (i = 0; i < r.h && !this.rowFull(r.x, r.x + r.w, r.y + r.h - 1 - i); i++);
		depth[2] = i;
		area[2] = i === 0 ? 0 : (r.h - i) * r.w;
		for (i = 0; i < r.w && !this.colFull(r.y, r.y + r.h, r.x + i); i++);
		depth[3] = i;
		area[3] = i === 0 ? 0 : (r.w - i) * r.h;
		for (i = 0; i < r.w && !this.colFull(r.y, r.y + r.h, r.x + r.w - 1 - i); i++);
		depth[1] = i;
		area[1] = i === 0 ? 0 : (r.w - i) * r.h;
		return depth.some(d => d !== 0);
	}
	measureWallInset(r, depth, area)	// 0x4c4cd0
	{
		const scan = (n, full) =>
		{
			let i;
			for (i = 1; i < n; i++)
			{
				if (!full(i))
				{
					i--;
					break;
				}
			}
			return i;
		};
		depth[0] = scan(r.h, i => this.rowFull(r.x, r.x + r.w, r.y + r.h - 1 - i));
		area[0] = (depth[0] + 1) * r.w;
		depth[2] = scan(r.h, i => this.rowFull(r.x, r.x + r.w, r.y + i));
		area[2] = (depth[2] + 1) * r.w;
		depth[3] = scan(r.w, i => this.colFull(r.y, r.y + r.h, r.x + r.w - 1 - i));
		area[3] = (depth[3] + 1) * r.h;
		depth[1] = scan(r.w, i => this.colFull(r.y, r.y + r.h, r.x + i));
		area[1] = (depth[1] + 1) * r.h;
	}
	findOpenSides(r, open)	// 0x4c4f60
	{
		open[0] = this.rowFull(r.x, r.x + r.w, r.y - 1);
		open[2] = this.rowFull(r.x, r.x + r.w, r.y + r.h);
		open[3] = this.colFull(r.y, r.y + r.h, r.x - 1);
		open[1] = this.colFull(r.y, r.y + r.h, r.x + r.w);
		return open.some(o => o);
	}
	hasNonWall(r)	// 0x4c4980
	{
		for (let x = r.x; x < r.x + r.w; x++)
			for (let y = r.y; y < r.y + r.h; y++)
				if (this.get(x, y) !== G_TUNNEL)
					return true;
		return false;
	}
	fitCaves()
	{
		const caves = this.caves, depths = [0, 0, 0, 0], area = [0, 0, 0, 0], inset = [0, 0, 0, 0], open = [0, 0, 0, 0];
		const maxIndex = a => { let m = 0; for (let i = 1; i < a.length; i++) if (a[i] > a[m]) m = i; return m; };	// 0x9d50c0
		for (let i = 0; i < caves.length; i++)
		{
			const cave = caves[i];
			let tries = 0;
			while (this.measureWallEdges(cave, depths, area))
			{
				const d = maxIndex(area);
				switch (d)
				{
					case 0: cave.y += depths[d]; cave.h -= depths[d]; break;
					case 2: cave.h -= depths[d]; break;
					case 3: cave.x += depths[d]; cave.w -= depths[d]; break;
					case 1: cave.w -= depths[d]; break;
				}
				if (++tries > 1000)
					break;
			}
			if (cave.w === 0 || cave.h === 0 || tries > 1000)
			{
				caves.splice(i, 1);
				i--;
				continue;
			}
			if (this.hasNonWall(cave))
			{
				this.measureWallInset(cave, inset, area);
				const d = maxIndex(area);
				switch (d)
				{
					case 0: cave.y = cave.y + cave.h - 1 - inset[d]; cave.h = inset[d] + 1; break;
					case 2: cave.h = inset[d] + 1; break;
					case 3: cave.x = cave.x + cave.w - 1 - inset[d]; cave.w = inset[d] + 1; break;
					case 1: cave.w = inset[d] + 1; break;
				}
			}
			while (this.findOpenSides(cave, open))
			{
				switch (this.pickIndex(open, true))
				{
					case 0: cave.y--; cave.h++; break;
					case 2: cave.h++; break;
					case 3: cave.x--; cave.w++; break;
					case 1: cave.w++; break;
				}
			}
		}
		const min = this.P.hallDimensionMin;
		for (let i = 0; i < caves.length; i++)
		{
			if (caves[i].w < min || caves[i].h < min)
			{
				caves.splice(i, 1);
				i--;
			}
		}
		this.rng.shuffle(caves);	// OpX5_shufflePoints 0x9d5110
		const largestRemainder = (outer, inner) =>	// 0x4c50c0
		{
			let best = { x: -1, y: -1, w: -1, h: -1 };
			const consider = r => { if (rArea(r) > rArea(best)) best = r; };
			if (inner.y > outer.y)
				consider({ x: outer.x, y: outer.y, w: outer.w, h: inner.y - outer.y });
			if (inner.y + inner.h < outer.y + outer.h)
				consider({ x: outer.x, y: inner.y + inner.h, w: outer.w, h: outer.y + outer.h - (inner.y + inner.h) });
			if (inner.x > outer.x)
				consider({ x: outer.x, y: outer.y, w: inner.x - outer.x, h: outer.h });
			if (inner.x + inner.w < outer.x + outer.w)
				consider({ x: inner.x + inner.w, y: outer.y, w: outer.x + outer.w - (inner.x + inner.w), h: outer.h });
			return best;
		};
		outer1:
		for (let i = 0; i < caves.length; i++)
		{
			for (let j = i + 1; j < caves.length; j++)
			{
				if (rDistance(caves[i], caves[j]) !== 0)
					continue;
				if (rEquals(caves[i], caves[j]))
				{
					caves.splice(j, 1);
					j--;
				}
				else if (rArea(caves[i]) > rArea(caves[j]))
				{
					if (rContainsRect(caves[i], caves[j]))
					{
						caves.splice(j, 1);
						j--;
					}
					else
						caves[j] = largestRemainder(caves[j], rIntersect(caves[i], caves[j]));
				}
				else
				{
					if (rContainsRect(caves[j], caves[i]))
					{
						caves.splice(i, 1);
						i--;
						continue outer1;
					}
					else
						caves[i] = largestRemainder(caves[i], rIntersect(caves[j], caves[i]));
				}
			}
		}
		outer2:
		for (let i = 0; i < caves.length; i++)
		{
			for (let j = i + 1; j < caves.length; j++)
			{
				if (rContainsRect(caves[i], caves[j]))
				{
					caves.splice(j, 1);
					j--;
				}
				else if (rContainsRect(caves[j], caves[i]))
				{
					caves.splice(i, 1);
					i--;
					continue outer2;
				}
			}
		}
		for (const c of caves)
		{
			if (c.w >= min && c.h >= min)
			{
				this.boxes.push({ x: c.x, y: c.y, w: c.w, h: c.h });
				for (let x = c.x; x < c.x + c.w; x++)
					for (let y = c.y; y < c.y + c.h; y++)
						this.set(x, y, G_HALL);
			}
		}
	}

	// ---- OpW7_Generator::removeBlockedDoors (0x4c6b00) ----
	removeBlockedDoors()
	{
		for (const room of this.rooms)
		{
			for (let j = 0; j < room.doors.length; j++)
			{
				const [x, y] = room.doors[j], d = room.doorDirs[j];
				if (d === undefined)
					continue;
				if (this.get(x + FX[d], y + FY[d]) === G_SOLID)
				{
					this.set(x, y, G_SOLID);
					room.doors.splice(j, 1);
					room.doorDirs.splice(j, 1);
					j--;
				}
			}
		}
	}

	// ---- OpW7_Generator::addRoomCorridors (0x4c6c50) / OpW7_digCorridor (0x4c6500): hidden shortcut doors ----
	isClearSides(p, dir, length)	// 0x4c6440
	{
		for (let side = 0; side < 2; side++)
		{
			let q = p;
			for (let i = 0; i < length; i++)
			{
				q = tr(q, side ? LEFT[dir] : RIGHT[dir], 0, 1);
				if (!this.inb(q.x, q.y) || this.get(q.x, q.y) !== G_SOLID)
					return false;
			}
		}
		return true;
	}
	digCorridor(roomIndex, start, dir)
	{
		const S = this.P.rooms[this.rooms[roomIndex].type];
		const back = BACK[dir];
		const segDirs = [dir], segLens = [0];
		let seg = 0, turns = S.shortcutTurns, p = start;
		while (turns !== 0)
		{
			turns--;
			let len = this.range(S.shortcutStep);
			while (len !== 0)
			{
				len--;
				p = tr(p, dir, 0, 1);
				segLens[seg]++;
				if (!this.inb(p.x, p.y))
					return false;
				const c = this.get(p.x, p.y);
				if (c >= G_TUNNEL)
				{
					if (c !== G_ROOM)
						return false;
					const path = [start];
					let q = start;
					for (let s = 0; s <= seg; s++)
					{
						for (let k = 0; k < segLens[s]; k++)
						{
							q = tr(q, segDirs[s], 0, 1);
							path.push(q);
						}
					}
					const end = path[path.length - 1];
					const target = this.rooms.findIndex(r => r.x !== -1 && rContains(r, end.x, end.y));
					if (target === -1 || path.length === 4)
						return false;
					this.rooms[roomIndex].corridors.push(this.blobs.length);
					this.rooms[target].corridors.push(this.blobs.length);
					this.blobs.push({ path: path.slice(1, -1), rooms: [roomIndex, target] });
					return true;
				}
				if (!this.isClearSides(p, dir, S.shortcutPadding))
					return false;
			}
			const back2 = BACK[dir];
			do
				dir = this.rng.rangeInt(0, 3);
			while (dir === back || dir === back2);
			if (BACK[dir] !== back2)
			{
				for (const [dx, dy] of [[-1, -1], [1, -1], [-1, 1], [1, 1]])
					if (!this.inb(p.x + dx, p.y + dy) || this.get(p.x + dx, p.y + dy) !== G_SOLID)
						return false;
			}
			seg++;
			segDirs[seg] = dir;
			segLens[seg] = 0;
		}
		return false;
	}
	addRoomCorridors()
	{
		if (!this.P.rooms.some(r => r.shortcutChance !== 0))
			return;
		for (let i = 0; i < this.rooms.length; i++)
		{
			const room = this.rooms[i];
			if (room.type === 3 || !this.rng.chance(this.P.rooms[room.type].shortcutChance) || room.w < 3 || room.h < 3)
				continue;
			const dirs = [0, 1, 2, 3].filter(d => !room.doorDirs.includes(d));
			if (!dirs.length)
				continue;
			let tries = this.P.rooms[room.type].shortcutAttempts;
			do
			{
				const d = this.rng.pick(dirs);
				let p;
				switch (d)
				{
					case 0: p = { x: this.rng.rangeInt(1, room.w - 2) + room.x, y: room.y }; break;
					case 1: p = { x: room.x + room.w - 1, y: this.rng.rangeInt(0, room.h - 1) + room.y }; break;
					case 2: p = { x: this.rng.rangeInt(1, room.w - 2) + room.x, y: room.y + room.h - 1 }; break;
					case 3: p = { x: room.x, y: this.rng.rangeInt(1, room.h - 2) + room.y }; break;
				}
				if (this.digCorridor(i, p, d))
				{
					const path = this.blobs[this.blobs.length - 1].path;
					const door = q => this.get(q.x, q.y - 1) === G_ROOM || this.get(q.x, q.y + 1) === G_ROOM ? 13 : 12;
					const a = path[0], b = path[path.length - 1];
					this.set(a.x, a.y, door(a));
					this.set(b.x, b.y, door(b));
					for (let k = 1; k < path.length - 1; k++)
						this.set(path[k].x, path[k].y, G_TUNNEL);
					break;
				}
			}
			while (--tries > 0);
		}
	}

	// ---- OpW7_Generator::checkStarts (0x4c7100): move each start onto its dug tunnel ----
	checkStarts()
	{
		const spawns = this.P.tunnelers;
		for (let i = 0; i < this.starts.length; i++)
		{
			const s = spawns[i];
			if (!this.starts[i] || s.type === 3)
				continue;
			const dirs = this.rng.shuffle([0, 1, 2, 3]);
			if (s.dirs.length === 1)
			{
				dirs.splice(dirs.indexOf(s.dirs[0]), 1);
				dirs.unshift(s.dirs[0]);
			}
			const w = s.p[1][0];
			let p = null;
			for (const d of dirs)
			{
				const q = tr(this.starts[i], d, trunc(w / 2), trunc(w / 2) + 1);
				if (this.get(q.x, q.y) === G_TUNNEL)
				{
					p = q;
					break;
				}
			}
			if (!p)
				return false;
			this.starts[i] = p;
			if (w >= 3)
			{
				for (let dx = -1; dx <= 1; dx++)
				{
					for (let dy = -1; dy <= 1; dy++)
					{
						const c = this.get(p.x + dx, p.y + dy);
						if ((dx || dy) && c !== G_TUNNEL && c !== G_HALL)
							return false;
					}
				}
			}
		}
		return true;
	}

	// ---- validation tail of A2GGenerator::generate: result 12 = success ----
	validate()
	{
		const P = this.P, W = this.w, H = this.h, area = W * H;
		// [OPEN_PERCENT] like the exe: every cell >= 4 counts, so the stand-ins' floor counts as the prefab's floor
		let open = 0;
		for (let i = 0; i < area; i++)
			if (this.grid[i] >= G_TUNNEL)
				open++;
		this.openPercent = trunc(open * 100 / area);
		this.maxHallArea = this.boxes.reduce((m, b) => Math.max(m, rArea(b)), 0);
		if (open === 0)
			return 1;
		if (this.openPercent < P.openPercent[0] || this.openPercent > P.openPercent[1])
			return this.openPercent < P.openPercent[0] ? 1 : 2;
		for (let t = 0; t < 3; t++)
			if (this.roomCounts[t] < P.roomCountMin[t])
				return 3;
		if (this.rooms.length < P.roomTotalMin)
			return 4;
		if (this.boxes.length < P.hallCountMin)
			return 5;
		if (this.maxHallArea > P.hallAreaMax)
			return 6;
		if (!this.checkStarts())
			return 7;
		// the exe paths between all marker-group members (prefab markers + enter/exit/either starts), then from the
		// neither starts, prefab exits and room doors to that network, with each shortcut corridor blocked at its
		// first cell; that is one connected component (Cartographer2D moves in 8 directions, cells >= 4 passable)
		const members = [], targets = [];
		this.starts.forEach((s, i) => { if (s) (P.tunnelers[i].type === 3 ? targets : members).push(s); });
		if (!members.length)
			return 8;
		const saved = this.blobs.map(b => { const p = b.path[0], v = this.get(p.x, p.y); this.set(p.x, p.y, 0); return v; });
		const reach = new Uint8Array(area), queue = [members[0].y * W + members[0].x];
		reach[queue[0]] = 1;
		for (let qi = 0; qi < queue.length; qi++)
		{
			const i = queue[qi], x = i % W, y = (i - x) / W;
			for (let dy = -1; dy <= 1; dy++)
			{
				for (let dx = -1; dx <= 1; dx++)
				{
					const nx = x + dx, ny = y + dy;
					if (!this.inb(nx, ny))
						continue;
					const j = ny * W + nx;
					if (!reach[j] && this.grid[j] >= G_TUNNEL)
					{
						reach[j] = 1;
						queue.push(j);
					}
				}
			}
		}
		this.blobs.forEach((b, k) => this.set(b.path[0].x, b.path[0].y, saved[k]));
		const ok = p => reach[p.y * W + p.x] === 1;
		// neither starts are raw tunneler origins (a tunneler never digs its own cell): Cartographer2D::findPath
		// starts there, so one reachable neighbour is enough
		const near = p =>
		{
			for (let dy = -1; dy <= 1; dy++)
				for (let dx = -1; dx <= 1; dx++)
					if (this.inb(p.x + dx, p.y + dy) && reach[(p.y + dy) * W + p.x + dx] === 1)
						return true;
			return false;
		};
		if (!members.every(ok))
			return 8;
		if (!targets.every(near))
			return 9;
		if (!this.exits.every(e => this.get(e.x, e.y) >= G_TUNNEL && ok(e)))
			return 10;
		for (const room of this.rooms)
			if (room.x !== -1 && !room.doors.every(([x, y]) => reach[y * W + x] === 1))
				return 11;
		return 12;
	}

	// generator grid -> demo cells (echo_03.cpp:1009)
	toMap(mapType, attempts)
	{
		const W = this.w, H = this.h, cells = new Uint8Array(W * H);
		for (let i = 0; i < W * H; i++)
		{
			const v = this.grid[i];
			cells[i] = v <= G_SOLID ? CELL.WALL : v >= 10 && v <= 15 ? CELL.DOOR : CELL.FLOOR;
		}
		const rooms = this.rooms.map(r =>
		{
			const b = r.x === -1 ? r.bbox : r;
			return { x: b.x, y: b.y, w: b.w, h: b.h, type: r.type, doors: r.doors.map(d => d.slice()) };
		});
		const starts = [];
		this.starts.forEach((s, i) => { if (s) starts.push({ x: s.x, y: s.y, type: SPAWN_TYPES[this.P.tunnelers[i].type] }); });
		return {
			w: W, h: H, mapType, variant: this.level, cells, rooms, reserved: this.reserved, starts,
			corridors: this.corridors.map(c => ({ x: c.x, y: c.y, w: c.w, h: c.h })), halls: this.boxes,
			shortcuts: this.blobs.map(b => ({ path: b.path.map(p => [p.x, p.y]), rooms: b.rooms })),
			raw: this.grid, openPercent: this.openPercent, attempts,
		};
	}
}

// ---------------------------------------------------------------------------------------------------------------
// Builders (DF::Builder subclasses, src/dungeon/df.h)
// ---------------------------------------------------------------------------------------------------------------

class Tunneler
{
	constructor(gen, delay, dir, pos, p1C, width, p24, p28, p2C, p30, p34, p38, p3C, linker)
	{
		this.g = gen;
		this.delay = delay;
		this.age = 0;
		this.dir = dir;
		this.startDir = dir;
		this.pos = { x: pos.x, y: pos.y };
		this.p1C = p1C;			// age limit
		this.width = width;
		this.p24 = p24;			// segment length
		this.p28 = p28;			// turn chance
		this.p2C = p2C;			// branch chance on straight
		this.p30 = p30;			// branch chance on turn
		this.p34 = p34;			// side room chance, left
		this.p38 = p38;			// side room chance, right
		this.p3C = p3C;			// dying-tunnel join chance
		this.linker = linker;
	}

	// OpW7_Tunneler::measure (0x4b9a30): free length ahead of `start` for this tunneler's width
	measure(start, dir, margin, extra, look)
	{
		const g = this.g, W = g.w, H = g.h, grid = g.grid, w = this.width;
		const lx = LX[dir], ly = LY[dir], fx = FX[dir], fy = FY[dir];
		const lo = -extra - margin, hi = w + margin + extra;
		if (margin)
		{
			for (let i = lo; i < hi; i++)
			{
				const x = start.x + lx * i, y = start.y + ly * i;
				if ((i <= -margin || i >= w) && (x < 0 || y < 0 || x >= W || y >= H || grid[y * W + x] > 3))
					return 0;
			}
		}
		let result = -1, length = 0;
		while (result === -1)
		{
			length++;
			for (let j = lo; j < hi; j++)
			{
				const x = start.x + lx * j + fx * length, y = start.y + ly * j + fy * length;
				let stop = x < 0 || y < 0 || x >= W || y >= H;
				if (!stop)
				{
					const c = grid[y * W + x];
					stop = (j < -margin || j >= w + margin) ? c > 3 : c !== 3;
				}
				if (stop)
				{
					result = length - 1;
					if (result > 0)
					{
						look:
						for (let k = 1; k <= look; k++)
						{
							for (let m = lo; m < hi; m++)
							{
								const ax = start.x + lx * m + fx * (result + k), ay = start.y + ly * m + fy * (result + k);
								if (ax < 0 || ay < 0 || ax >= W || ay >= H || grid[ay * W + ax] > 3)
								{
									result -= look - k + 1;
									break look;
								}
							}
						}
					}
					break;
				}
			}
		}
		return result;
	}

	// OpW7_Tunneler::dig (0x4b9ca0)
	dig(type, length, margin, extra, look)
	{
		if (this.measure(this.pos, this.dir, margin, extra, look) < length)
			return false;
		const g = this.g, d = this.dir;
		for (let i = 1; i <= length; i++)
		{
			for (let j = -margin; j < this.width + margin; j++)
			{
				const c = tr(this.pos, d, j, i);
				g.set(c.x, c.y, type);
			}
		}
		if (type === G_JUNCTION)
		{
			const c = tr(this.pos, d, -margin, 1), w = this.width + margin * 2;
			switch (d)
			{
				case 0: g.corridors.push({ x: c.x, y: c.y - length + 1, w, h: length }); break;
				case 1: g.corridors.push({ x: c.x, y: c.y, w: length, h: w }); break;
				case 2: g.corridors.push({ x: c.x - w + 1, y: c.y, w, h: length }); break;
				case 3: g.corridors.push({ x: c.x - length + 1, y: c.y - w + 1, w: length, h: w }); break;
			}
		}
		return true;
	}

	newChild(delay, dir, pos, roll)
	{
		const T = this.g.T;
		return new Tunneler(this.g, delay, dir, pos, this.p1C, T.width, T.p24, T.p28, T.p2C, T.p30, T.p34, T.p38, roll, false);
	}

	differs()
	{
		const T = this.g.T;
		return this.p28 !== T.p28 || this.p2C !== T.p2C || this.p30 !== T.p30 || this.p34 !== T.p34 || this.p38 !== T.p38;
	}

	// OpW7_Tunneler::build (0x4b9f20): 0 = finished, 1 = waiting for its turn, 2 = worked
	build()
	{
		const g = this.g, P = g.P, rng = g.rng, pad = P.tunnelPadding;
		if (this.delay > g.turn)
			return 1;
		this.age++;
		if (this.age > this.p1C)
			return 0;
		const pickA = g.pickWeight(P.rooms.map(r => at(r.branchChance, this.width)));
		const pickB = g.pickWeight(P.rooms.map(r => at(r.sideChance, this.width)));
		const roomDelay = g.turn + g.pickWeight(P.childDelayRoom);
		const lengths = this.measure(this.pos, this.dir, 0, pad, pad);
		if (lengths === 0)
		{
			if (this.measure(this.pos, this.dir, 0, pad, 0) > 0)
				this.spawn(pickA);
			return 0;
		}
		if (lengths < this.p24 * 2 || this.age === this.p1C - 1)
		{
			this.spawn(pickA);
			return 0;
		}
		this.dig(G_TUNNEL, this.p24, 0, pad, pad);
		const half = trunc(this.p24 / 2);
		if (half - 1 >= 1)
		{
			if (rng.chance(this.p34))
				g.builders.push(new Roomie(g, roomDelay, LEFT[this.dir], tr(this.pos, this.dir, 0, half + 1), pickB, half - 1));
			if (rng.chance(this.p38))
				g.builders.push(new Roomie(g, roomDelay, RIGHT[this.dir], tr(this.pos, this.dir, this.width - 1, half + 1), pickB, half - 1));
		}
		this.pos = tr(this.pos, this.dir, 0, this.p24);
		const canWiden = this.measure(this.pos, this.dir, 1, pad, pad) > this.width * 2 + 5;
		const wide2 = this.measure(this.pos, this.dir, 2, pad, pad) > this.width * 2 + 7;
		const elem = at(P.levels, this.delay);	// [MAX_AGE, NARROW_CHANCE, WIDEN_CHANCE] by generation
		let mode = 0;
		const roll = rng.rangeInt(1, 100);
		if (roll <= elem[1])
		{
			if (this.width >= 3)
				mode = -2;
		}
		else if (roll <= elem[1] + elem[2])
		{
			if (P.widthMax === 0 || this.width + 2 <= P.widthMax)
				mode = 2;
		}
		if (mode > 0 && !wide2)
			return 2;
		const turn = rng.chance(this.p28);
		const branch = rng.chance(turn ? this.p30 : this.p2C);
		if (!turn && !branch)
			return 2;
		const room = branch && !rng.chance(P.roomPatience);
		const newDelay = this.delay + (mode <= 0 ? g.pickWeight(P.childDelayTunnel) : g.pickWeight(P.childDelayTunnelWide));
		const v28 = g.vary(this.p28), v2C = g.vary(this.p2C), v30 = g.vary(this.p30);
		const v34 = g.vary(this.p34), v38 = g.vary(this.p38), v3C = g.vary(this.p3C);
		const starts = [this.pos, this.pos, this.pos];
		const dirs = [this.dir, LEFT[this.dir], RIGHT[this.dir]];
		const used = [false, false, false];
		let dug = false;
		const junction = at(P.junctionChance, this.width);
		const tryJunction = extra =>
		{
			const len = this.width + extra * 2;
			dug = this.dig(G_JUNCTION, len, extra, pad, pad);
			starts[0] = tr(starts[0], this.dir, 0, len);
			starts[1] = tr(starts[1], this.dir, -extra, extra + 1);
			starts[2] = tr(starts[2], this.dir, this.width + extra - 1, len - extra);
		};
		if (mode > 0)
		{
			if (branch || rng.chance(junction))
				tryJunction(2);
		}
		else if (canWiden)
		{
			if (rng.chance(junction))
				tryJunction(1);
		}
		if (!dug)
		{
			starts[1] = tr(starts[1], this.dir, 0, -this.width + 1);
			starts[2] = tr(starts[2], this.dir, this.width - 1, 0);
			if (g.get(starts[1].x, starts[1].y) !== G_TUNNEL || g.get(starts[2].x, starts[2].y) !== G_TUNNEL)
				return 2;
		}
		const cur = this.dir;
		if (turn)
		{
			const lenL = this.measure(starts[1], LEFT[cur], 0, pad, pad);
			const lenR = this.measure(starts[2], RIGHT[cur], 0, pad, pad);
			let choice = 0;
			if (cur !== this.startDir)
				choice = LEFT[cur] === this.startDir ? 1 : 2;
			else if (branch && mode > 0)
			{
				if (lenL < lenR || (lenL === lenR && rng.chance(50)))
				{
					if (lenL > 0)
						choice = 1;
				}
				else if (lenR > 0)
					choice = 2;
			}
			else
			{
				if (lenL > lenR || (lenL === lenR && rng.chance(50)))
				{
					if (lenL > 0)
						choice = 1;
				}
				else if (lenR > 0)
					choice = 2;
			}
			this.pos = { x: starts[choice].x, y: starts[choice].y };
			this.dir = dirs[choice];
			used[choice] = true;
		}
		if (branch)
		{
			const which = rng.rangeInt(0, 1);
			for (let i = 0; i < 2; i++)
			{
				const idx = g.pickIndex(used, false);
				used[idx] = true;
				if (room && which === i)
				{
					const p = tr(starts[idx], dirs[idx], trunc(this.width / 2), 0);
					const rdelay = dug ? roomDelay + trunc((roomDelay - g.turn) / P.junctionAcceleration) : roomDelay;
					g.builders.push(new Roomie(g, rdelay, dirs[idx], p, pickA, this.width * 2));
				}
				else
				{
					const ws = this.width + mode;
					let len = this.p24;
					if (mode > 0)
						len += 2;
					else if (mode < 0)
						len = Math.max(len - 2, 3);
					const p = mode !== 0 ? tr(starts[idx], dirs[idx], trunc(-mode / 2), 0) : starts[idx];
					g.builders.push(new Tunneler(g, newDelay, dirs[idx], p, elem[0], ws, len, v28, v2C, v30, v34, v38, v3C, false));
				}
			}
		}
		return 2;
	}

	// OpW7_Tunneler::spawn (0x4bb040): end of a tunnel: join, door into a room, end room, continuation
	spawn(roomType)
	{
		const g = this.g, P = g.P, rng = g.rng, pad = P.tunnelPadding, gd = P.generationDelay;
		const roll = rng.rangeInt(1, 10) * 10;
		const length = this.measure(this.pos, this.dir, 0, pad, 0);
		let blocked = false, hitRoom = false, hitTunnel = false;
		const hits = [];
		for (let i = 0; i < this.width; i++)
		{
			const p = tr(this.pos, this.dir, i, length + 1);
			if (!g.inb(p.x, p.y))
				blocked = true;
			else
			{
				const c = g.get(p.x, p.y);
				if (c === G_TUNNEL || c === G_JUNCTION)
				{
					hitTunnel = true;
					hits.push(i);
				}
				else if (c === G_ROOM)
					hitRoom = true;
			}
		}
		if (length < 5 || (rng.chance(this.p3C) && (this.age < this.p1C - 1 || length <= P.dyingTunnelJoinLimit)))
		{
			if (hits.length === this.width)
			{
				this.dig(G_TUNNEL, length, 0, pad, 0);
				return;
			}
			if (hitTunnel)
			{
				this.width = 1;
				this.pos = tr(this.pos, this.dir, rng.pick(hits), 0);
				this.dig(G_TUNNEL, length, 0, pad, 0);
				return;
			}
			if (hitRoom && this.width === 1)
			{
				if (length > 1)
					this.dig(G_TUNNEL, length - 1, 0, pad, 0);
				const door = tr(this.pos, this.dir, 0, length);
				g.set(door.x, door.y, this.dir !== 0 && this.dir !== 2 ? 11 : 10);
				return;
			}
			if (blocked && this.width === 1)
			{
				if (roll !== 100 || this.differs())
				{
					const lenL = this.measure(this.pos, LEFT[this.dir], 0, pad, pad);
					const lenR = this.measure(this.pos, RIGHT[this.dir], 0, pad, pad);
					const d = lenL > lenR || (lenL === lenR && rng.chance(50)) ? LEFT[this.dir] : RIGHT[this.dir];
					g.builders.push(this.newChild(this.delay + 1, d, this.pos, roll));
				}
				return;
			}
		}
		if (g.roomCounts[roomType] < P.rooms[roomType].limit)
			g.builders.push(new Roomie(g, this.delay, this.dir, tr(this.pos, this.dir, trunc(this.width / 2), 0), roomType, this.width * 2));
		if (roll === 100 && !this.differs())
			return;
		const d = this.dir, e0 = this.pos;
		const e1 = tr(e0, d, 0, -this.width + 1);
		const lenL = this.measure(e1, LEFT[d], 0, pad, pad);
		const e2 = tr(e0, d, this.width - 1, 0);
		const lenR = this.measure(e2, RIGHT[d], 0, pad, pad);
		const e3 = tr(e0, d, this.width - 1, 0);
		const lenB = this.measure(e3, BACK[d], 0, pad, pad);
		const later = this.delay + gd;
		if (this.width > 1)
		{
			if (blocked)
			{
				g.builders.push(this.newChild(later, LEFT[d], e1, roll));
				g.builders.push(this.newChild(later, RIGHT[d], e2, roll));
			}
			else if (hitRoom)
			{
				g.builders.push(this.newChild(later, d, tr(e0, d, trunc(this.width / 2), 0), roll));
				if (rng.chance(50))
					g.builders.push(this.newChild(later, LEFT[d], e1, roll));
				else
					g.builders.push(this.newChild(later, RIGHT[d], e2, roll));
			}
			else
			{
				const left = rng.chance(50);
				g.builders.push(this.newChild(later, left ? LEFT[d] : d, e0, roll));
				g.builders.push(this.newChild(later, left ? d : RIGHT[d], tr(e0, d, this.width - 1, 0), roll));
			}
		}
		else if (!this.differs())
		{
			if (length >= lenL && length >= lenR && length >= lenB)
				g.builders.push(this.newChild(this.delay + 1, d, e0, roll));
			else if (lenB >= lenL && lenB >= lenR)
				g.builders.push(this.newChild(later, BACK[d], e3, roll));
			else if (lenR > lenL || (lenR === lenL && rng.chance(50)))
				g.builders.push(this.newChild(later, RIGHT[d], e2, roll));
			else
				g.builders.push(this.newChild(later, LEFT[d], e1, roll));
		}
		else
			g.builders.push(this.newChild(later, d, e0, roll));
	}
}

class Roomie
{
	constructor(gen, delay, dir, pos, roomType, width)
	{
		this.g = gen;
		this.delay = delay;
		this.age = 0;
		this.dir = dir;
		this.pos = { x: pos.x, y: pos.y };
		this.roomType = roomType;
		this.p1C = width;
	}

	// OpW7_Roomie::measure (0x4bc630): depth ahead and free space to the left/right
	measure(origin, width, margin)
	{
		const g = this.g, d = this.dir, half = trunc(width / 2);
		const from = tr(origin, d, 0, 1);
		const blockedAt = (lat, fwd) => { const p = tr(from, d, lat, fwd); return !g.inb(p.x, p.y) ? null : g.get(p.x, p.y); };
		const hard = (lat, fwd) => { const c = blockedAt(lat, fwd); return c === null || c > 3; };
		let result = -1, length = -1, left = -1, right = -1;
		while (result === -1)
		{
			length++;
			for (let i = -margin - half; i < half + margin; i++)
			{
				const c = blockedAt(i, length);
				if (c === null || ((i < -half || i >= half) && c > 3) || (i >= -half && i < half && c !== 3))
				{
					if ((result = length - 1) < 0)
						return { result: 0, left, right };
					if (result > 0)
					{
						look:
						for (let k = 1; k <= margin; k++)
						{
							for (let m = -margin - half; m <= half + margin; m++)
							{
								if (hard(m, result + k))
								{
									result -= margin - k + 1;
									break look;
								}
							}
						}
					}
					if (result > 0)
					{
						const side = sign =>
						{
							let n = 0;
							for (;;)
							{
								n++;
								for (let a = 0; a <= result + margin; a++)
								{
									const c2 = blockedAt(sign * n, a);
									if (c2 === null || (a > result && c2 > 3) || (a <= result && c2 !== 3))
									{
										let s = n - 1;
										if (s >= 0)
										{
											look2:
											for (let b = 1; b <= margin; b++)
											{
												for (let cc = 0; cc <= result + margin; cc++)
												{
													if (hard(sign * (s + b), cc))
													{
														s -= margin - b + 1;
														break look2;
													}
												}
											}
										}
										return s;
									}
								}
							}
						};
						left = side(-1);
						right = side(1);
					}
					break;
				}
			}
		}
		return { result, left, right };
	}

	// OpW7_Roomie::build (0x4bcb80)
	build()
	{
		const g = this.g, P = g.P, S = P.rooms[this.roomType], ratio = Math.fround(P.roomAspectMin);
		if (g.roomCounts[this.roomType] >= S.limit)
			return 0;
		if (this.delay > g.turn)
			return 1;
		this.age++;
		let w = this.p1C, W, H;
		do
		{
			const m = this.measure(this.pos, w, P.roomPadding);
			if (m.result < 4 || m.left < 0 || m.right < 0)
				return 0;
			H = m.result;
			W = m.left + m.right;
			if (Math.fround(W / H) < ratio)
				H = trunc(W / ratio);
			else if (Math.fround(H / W) < ratio)
				W = trunc(H / ratio);
			while (W * H > S.area[1])
			{
				if (W > H)
					W--;
				else if (H > W)
					H--;
				else if (g.rng.chance(50))
					W--;
				else
					H--;
			}
			if (W * H >= S.area[0])
			{
				const d = this.dir, margin = P.roomPadding;
				let rp;
				if (m.left <= m.right)
					rp = m.left * 2 - margin > W ? tr(this.pos, d, -trunc(W / 2), 2) : tr(this.pos, d, Math.max(-m.left, -W + 1), 2);
				else
					rp = m.right * 2 - margin > W ? tr(this.pos, d, -trunc(W / 2), 2) : tr(this.pos, d, m.right - W + 1, 2);
				let r;
				switch (d)
				{
					case 0: r = { x: rp.x, y: rp.y - H + 1, w: W, h: H }; break;
					case 1: r = { x: rp.x, y: rp.y, w: H, h: W }; break;
					case 2: r = { x: rp.x - W + 1, y: rp.y, w: W, h: H }; break;
					case 3: r = { x: rp.x - H + 1, y: rp.y - W + 1, w: H, h: W }; break;
				}
				g.rooms.push({ type: this.roomType, x: r.x, y: r.y, w: r.w, h: r.h, doors: [], doorDirs: [], corridors: [] });
				for (let x = r.x; x < r.x + r.w; x++)
					for (let y = r.y; y < r.y + r.h; y++)
						g.set(x, y, G_ROOM);
				const door = tr(this.pos, d, 0, 1);
				g.set(door.x, door.y, d === 0 || d === 2 ? 10 : 11);
				g.roomCounts[this.roomType]++;
				return 0;
			}
			w += 2;
		}
		while (H >= (2.0 * W + 1.0) * ratio);
		return 0;
	}
}

// ---------------------------------------------------------------------------------------------------------------
// API
// ---------------------------------------------------------------------------------------------------------------

const MAX_ATTEMPTS = 1000;

// opts.branches: map types (or zone codes) of the branch exits this location still needs, one entry per exit
// (the exe's 0xcf123c list). Default: one of each branch the chosen variant offers.
function generate(mapType, rng, opts)
{
	const list = PARAMS && PARAMS[mapType];
	if (!list || !list.length)
		throw new Error('MapGen: no generator parameters for map type ' + mapType);
	// BS::initilize picks one map record for the location (weighted pool), then retries generation with it
	let P = list[0];
	if (list.length > 1)
	{
		let total = 0;
		for (const c of list)
			total += c.weight;
		let roll = rng.rangeInt(1, total);
		for (const c of list)
		{
			if ((roll -= c.weight) <= 0)
			{
				P = c;
				break;
			}
		}
	}
	const gen = new Generator(P, rng);
	const failures = [];
	for (let attempt = 1; attempt <= MAX_ATTEMPTS; attempt++)
	{
		gen.init(opts && opts.branches);
		gen.placeTunnelers();
		const result = gen.generate();
		if (result === 12)
		{
			const map = gen.toMap(mapType, attempt);
			map.failures = failures;
			return map;
		}
		failures.push(result);
	}
	const counts = {};
	for (const f of failures)
		counts[f] = (counts[f] || 0) + 1;
	throw new Error('MapGen: map type ' + mapType + ' failed validation ' + MAX_ATTEMPTS + ' times ' + JSON.stringify(counts));
}

// ASCII view of a generated map: '#' wall, '.' tunnel, ',' junction, ':' hall, '_' room, '+' door, '*' shortcut,
// 'X' permanent wall (BLOCKED / prefab stand-in border), '%' machine (after Props.populate)
function toAscii(map)
{
	const glyph = v => v <= 2 ? 'X' : v === 3 ? '#' : v === 4 ? '.' : v === 5 ? ',' : v === 6 ? ':' : v === 7 ? '_'
		: v === 10 || v === 11 ? '+' : v === 12 || v === 13 ? '*' : '?';
	const lines = [];
	for (let y = 0; y < map.h; y++)
	{
		let s = '';
		for (let x = 0; x < map.w; x++)
		{
			const i = y * map.w + x;
			s += map.cells[i] === CELL.MACHINE ? '%' : glyph(map.raw[i]);
		}
		lines.push(s);
	}
	return lines.join('\n');
}

const API = { generate, toAscii, CELL, PARAMS, ZONES };

if (typeof module === 'object' && module.exports)
	module.exports = API;
else
	root.MapGen = API;
})(typeof globalThis !== 'undefined' ? globalThis : this);
