/* Map population for the 0b10 map types: stairs, Garrison Accesses, DSF Accesses, interactive and static machines,
   arrival point. Rules follow functions this repo has matched byte-for-byte; machine art and footprints are not
   in the exe (they come from the game's data files), so every machine is a plain rectangle stand-in.

   From the matched code:
     BS::initilize               0x7026b0  src/util/echo_03.cpp:1247-1424
       stairs: the next main map gets 0xb904a8[map type] exits, taken from marker groups 0x13, 0x12 ('exit' tunneler
       starts), 0x10 ('either' starts); every other link gets 0xd2d348[dest type] (min..max) exits from groups 0x14
       (prefab marker, matched by zone name), 0x12, 0x10; anything left over goes through BS::unknown6c2230.
       Arrival: a random 'enter' start (group 0x11), else an 'either' start, else BS::unknown6c2230.
     BS::unknown6c2230           0x6c2230  src/game/team_d_80.cpp
       random spot: centre of an unused corridor rect at least (w+h)/2/4 from exits to the same map and (w+h)/2/6 from
       other exits (40% per close exit to retry among rooms), else an unused room centre, else any open cell.
     BS::populate6d4c00          0x6d4c00  src/util/golf_03.cpp
       interactive machine counts per kind: 0xb9efc0[depth index] on main maps (types 1-6), 0xb9ea68[type] elsewhere;
       size bucket per kind 0xb9f270 (0 = room wall, 1 = hall wall, 2 = corridor centre); security tier 0xb9f530
       (Garrison Access forced to tier 0 at depth 8 and below); halls/rooms get a content type from 0xb91278/0xb91608
       (interactive machine, static machine grid, both, nothing); margins and grid spacing 0xb9f5c0; corridor rects
       sorted by score (width/2 + rooms*2 + open sides*3) get a centred Terminal (50%) or a TF Node
       (w*h/4000 of them where 0xb90c40[type]); machines that found no room go into wall alcoves; 0xb90098[type]
       DSF Accesses go into 2x1 wall alcoves.
     OpD_placeWallProp_6ca780    0x6ca780  src/game/team_d_38.cpp   machine against a room wall, in a corner,
                                                                       Garrison Accesses kept > 50 apart
     lb12_layout_6cadf0          0x6cadf0  src/util/loop_bravo_12_layout.cpp  static machine grid (padding, spacing)
     OpD_findWallStrip_6cbb40    0x6cbb40  src/game/team_d_37.cpp   wall alcove next to a floor strip
     BS::placeMachine            0x6c70a0  src/util/bravo2_16.cpp   type 5 (Garrison Access) adds an exit record to
                                                                       Garrison (13); "DSF Access" adds one to DSF (14)
   Stand-ins (not from the exe): machine footprints and anchors, static machine set, the item-stockpile and robot
   placements populate also does (skipped), the corridor rects when mapgen.js does not supply them (derived from the
   floor mask), and the run-dependent choices of the world builder (0x784410) that BRANCHES fixes or rolls per map.
   The arrival point is not an exit record in the game (it is BS+0x8); it is listed with dest -1 so findDispatchExit
   never picks it, and `from` names the map Cogmind came from.
   DOM-free; node can require() it. */
(function (root) {
'use strict';

const CELL = { WALL: 0, FLOOR: 1, DOOR: 2, MACHINE: 3 };
const { WALL, FLOOR, DOOR, MACHINE } = CELL;

// ---------------------------------------------------------------------------------------------------------------
// Exe data
// ---------------------------------------------------------------------------------------------------------------

// 0xd3a280: machine type names (prop def +0xf8); kinds 6-8 (Derelict/Architect Terminal, Archives) never appear here
const KIND_NAMES = ['Terminal', 'Fabricator', 'Repair Station', 'Recycling Unit', 'Scanalyzer', 'Garrison Access'];
const GARRISON = 5;
// 0xb9efc0, by depth index (11 - depth): interactive machines per kind on main maps
const COUNTS_BY_DEPTH = [[0, 0, 0, 0, 0, 0], [8, 0, 1, 2, 0, 0], [12, 0, 2, 2, 2, 0], [12, 0, 2, 2, 2, 1],
	[20, 6, 6, 6, 4, 4], [20, 6, 6, 8, 4, 4], [20, 6, 6, 8, 4, 4], [20, 6, 6, 8, 4, 4], [20, 4, 4, 5, 6, 4],
	[20, 4, 4, 5, 6, 4], [20, 4, 4, 4, 4, 6]];
// 0xb9ea68, by map type: the same for maps outside the main range
const COUNTS_BY_TYPE = { 9: [8, 0, 2, 2, 0, 1], 27: [16, 0, 0, 0, 0, 2], 28: [12, 8, 2, 2, 0, 0],
	30: [12, 0, 2, 0, 3, 1], 31: [10, 2, 2, 0, 3, 1], 32: [16, 0, 2, 0, 3, 1], 33: [16, 0, 2, 0, 4, 0] };
// 0xb9f270, by kind: weights of size bucket 0 (room wall), 1 (hall wall), 2 (corridor centre)
const SIZE_WEIGHTS = [[60, 20, 20], [50, 50, 0], [90, 10, 0], [80, 20, 0], [100, 0, 0], [70, 30, 0]];
// 0xb9f530, by depth index: weights of security tier 0-2 (prop def +0x10c)
const TIER_WEIGHTS = [[100, 0, 0], [85, 15, 0], [85, 15, 0], [85, 15, 0], [35, 50, 15], [35, 50, 15], [35, 50, 15],
	[35, 50, 15], [15, 35, 50], [15, 35, 50], [0, 15, 85]];
// 0xb9f5c0, by map type: {room spacing, room margin, hall spacing, hall margin, -, corridor margin}
const SPACING = { 3: [1, 1, 1, 2, 1, 1], 4: [2, 2, 3, 3, 1, 1], 5: [2, 2, 3, 3, 1, 1], 9: [1, 1, 2, 2, 1, 1],
	27: [1, 1, 2, 2, 1, 1], 28: [1, 1, 2, 2, 1, 1], 30: [1, 1, 1, 2, 1, 1], 31: [1, 1, 1, 2, 1, 1],
	32: [1, 1, 1, 2, 1, 1], 33: [1, 1, 1, 2, 1, 1] };
// 0xb91278 (halls) and 0xb91608 (rooms), by map type: weights of content types 0-5
//   0 interactive + statics (+ stockpile), 1 interactive + statics, 2 statics (+ stockpile), 3 statics,
//   4 stockpile only, 5 nothing; halls never roll 4 or 5. (Rooms: interactive on 0/1, statics on 0-3.)
const HALL_CONTENT = { 3: [20, 40, 20, 20, 0, 0], 28: [30, 30, 30, 10, 0, 0] };
const HALL_CONTENT_DEFAULT = [20, 40, 20, 20, 0, 0];
const ROOM_CONTENT = { 3: [8, 36, 8, 30, 4, 16], 4: [8, 36, 8, 30, 4, 16], 5: [10, 34, 10, 32, 6, 10],
	9: [6, 6, 2, 35, 2, 49], 27: [8, 32, 8, 30, 2, 20], 28: [10, 15, 10, 15, 0, 50], 30: [8, 22, 8, 20, 2, 40],
	31: [8, 22, 8, 20, 2, 40], 32: [8, 27, 8, 25, 2, 30], 33: [8, 27, 8, 25, 2, 30] };
// 0xb9f150 [static category 1-7][0 room / 1 hall]: % chance a static grid mixes in other machines (same for all)
const MIX_CHANCE = [25, 50];
// 0xb904a8, by map type: stairs to the next main map
const MAIN_EXITS = [0, 1, 3, 4, 3, 1, 0, 2, 0, 1, 1, 2, 1, 0, 0, 2, 1, 1, 1, 0, 0, 0, 0, 0, 2, 2, 1, 4, 2, 1, 1, 1, 1,
	1, 2, 1, 0, 0];
// point_d2d348 (src/game/team_c_02.cpp:95), by destination map type: {min, max} stairs to a branch
const BRANCH_EXITS = [[0, 0], [0, 0], [0, 0], [0, 0], [0, 0], [0, 0], [0, 0], [1, 2], [1, 1], [1, 2], [1, 1], [1, 1],
	[0, 0], [0, 0], [0, 0], [1, 1], [2, 2], [2, 2], [1, 1], [1, 1], [1, 1], [1, 1], [1, 1], [1, 1], [2, 2], [1, 1],
	[1, 1], [2, 2], [1, 1], [1, 1], [2, 2], [2, 2], [1, 1], [0, 0], [1, 1], [1, 1], [0, 0], [0, 0]];
// 0xb90098, by map type: DSF Accesses
const DSF_ACCESSES = { 3: 6, 4: 4 };
// 0xb90c40, by map type: nonzero = w*h/4000 TF Nodes
const TF_NODE_TYPES = [3, 4, 5, 9, 27, 30, 31, 32, 33];
const GARRISON_SPACING = 0x32;		// OpD_placeWallProp_6ca780 / OpD_findWallStrip_6cbb40: > 50 between accesses
const DSF_SPACING = 0x28;			// OpD_findWallStrip_6cbb40 avoidItems: > 40 between DSF Access exits
const WALL_STRIP_AREA = [7, 6, 4];	// populate: leftover bucket i searches room (7), hall (6), corridor (4) cells
const DSF_STRIP_AREAS = [4, 6, 7];

const isMainType = type => type >= 1 && type <= 6;	// Location_46ecb0::inRange (type in [1, 6])
const depthIndexOf = depth => 11 - depth;			// Push_46ed20::operate
// main map at each depth (positive depth)
const MAIN_BY_DEPTH = { 10: 2, 9: 2, 8: 2, 7: 3, 6: 3, 5: 3, 4: 3, 3: 4, 2: 4, 1: 5, 0: 6 };

// ---------------------------------------------------------------------------------------------------------------
// Stand-ins
// ---------------------------------------------------------------------------------------------------------------

// Interactive machine footprints [length along the wall, depth from the wall] by kind and tier. Invented.
const KIND_SIZE = [
	[[3, 2], [3, 2], [4, 2]],		// Terminal
	[[4, 3], [5, 3], [5, 4]],		// Fabricator
	[[3, 3], [3, 3], [4, 3]],		// Repair Station
	[[4, 3], [4, 3], [5, 3]],		// Recycling Unit
	[[3, 2], [3, 3], [3, 3]],		// Scanalyzer
	[[3, 2], [3, 2], [3, 2]],		// Garrison Access
];
// Static (non-interactive) machines: [w, h, weight, category]. Invented; the real set is per map in the data files.
const STATICS = [[2, 2, 30, 1], [3, 2, 25, 2], [3, 3, 15, 3], [4, 2, 10, 4], [2, 1, 15, 5], [5, 3, 5, 6]];
const TF_NODE_SIZE = [1, 1];
const DSF_SIZE = [2, 1];	// OpD_findWallStrip_6cbb40(2, 1, ...) in populate: exact

// World links: branch destinations (map types) by host map type and positive depth, from the matched world builder
// (0x784410, src/op/op_gm_784410.cpp:368-606). Garrison (13) and DSF (14) are reached through Garrison/DSF
// Accesses and Wastes (12) has no stairs (0xd2d348[12] = 0), so none of them is listed. Entries that are arrays of
// alternatives are run-dependent in the game (Quarantine or Testing at -3, the other at -2; Section 7 hangs off
// whichever of Quarantine/Testing is the open node): the demo picks one / includes it with 50%.
// Branches the game places at one of several depths (Storage, Extension, Armory) are always included at each.
const BRANCHES = {
	3: { 7: [16, 9], 6: [16, 24], 5: [17, 24], 4: [17, 24, 28] },
	4: { 3: [28, [30, 31]], 2: [[30, 31]] },
	5: { 1: [34] },
	9: { 9: [10], 8: [10], 7: [10] },
	27: {},
	28: { 4: [29], 3: [29] },
	30: { 3: [[32, -1]], 2: [[32, -1]] },
	31: { 3: [[32, -1]], 2: [[32, -1]] },
	32: {},
	33: {},
};

// links in BS::initilize order: the next main map first, then branches
function linksFor(type, depth, rng)
{
	const links = [];
	const next = MAIN_BY_DEPTH[depth - 1];
	if (next !== undefined)
		links.push(next);
	for (const b of (BRANCHES[type] || {})[depth] || [])
	{
		const dest = Array.isArray(b) ? rng.pick(b) : b;
		if (dest >= 0)
			links.push(dest);
	}
	return links;
}

// ---------------------------------------------------------------------------------------------------------------
// Populate
// ---------------------------------------------------------------------------------------------------------------

const DIR = [[0, -1], [1, 0], [0, 1], [-1, 0]];	// N E S W (OpB_translateRotated)
const DIRS8 = [[1, 0], [-1, 0], [0, 1], [0, -1], [1, 1], [1, -1], [-1, 1], [-1, -1]];
const distCeil = (ax, ay, bx, by) => Math.ceil(Math.sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)) - 0.0001);

function wpick(rng, weights)
{
	let sum = 0;
	for (const w of weights) sum += w;
	if (sum <= 0)
		return -1;
	let r = rng.next() * sum;
	for (let i = 0; i < weights.length; i++)
		if ((r -= weights[i]) < 0)
			return i;
	return weights.length - 1;
}

function populate(map, depth, rng, opts)
{
	opts = opts || {};
	const W = map.w, H = map.h, cells = map.cells, type = map.mapType;
	const N = W * H;
	const di = depthIndexOf(depth);
	const main = isMainType(type);
	const spacing = SPACING[type] || [1, 1, 1, 2, 1, 1];
	const inb = (x, y) => x >= 0 && y >= 0 && x < W && y < H;

	// ---- area grid (cellTypes 0xcf1964 as the populate helpers read it): 7 room, 6 hall, 4 other floor ----
	const area = new Uint8Array(N);
	const flagged = new Uint8Array(N);		// prefab areas (terrain flags A/C stop population there)
	const guard = new Uint8Array(N);		// exits and their neighbours stay clear of machines
	for (let i = 0; i < N; i++)
		if (cells[i] === FLOOR)
			area[i] = 4;
	for (const r of map.reserved || [])
		for (let y = r.y; y < r.y + r.h; y++)
			for (let x = r.x; x < r.x + r.w; x++)
				if (inb(x, y))
					flagged[y * W + x] = 1;
	const rooms = (map.rooms || []).filter(r => !flagged[r.y * W + r.x]);
	const halls = (map.halls || []).filter(r => !flagged[r.y * W + r.x]);
	const markRect = (r, v) =>
	{
		for (let y = r.y; y < r.y + r.h; y++)
			for (let x = r.x; x < r.x + r.w; x++)
				if (inb(x, y) && cells[y * W + x] === FLOOR)
					area[y * W + x] = v;
	};
	rooms.forEach(r => markRect(r, 7));
	halls.forEach(r => markRect(r, 6));
	const corridors = (map.corridors || deriveCorridors()).filter(r => !flagged[r.y * W + r.x]);
	const areaCells = { 4: [], 6: [], 7: [] };
	for (let i = 0; i < N; i++)
		if (area[i] && !flagged[i])
			areaCells[area[i]].push(i);

	// greedy rectangles over corridor floor (stand-in for the 0xd1f31c dig rects when mapgen.js has none)
	function deriveCorridors()
	{
		const used = new Uint8Array(N);
		const ok = i => area[i] === 4 && !flagged[i] && !used[i];
		const out = [];
		for (let y = 0; y < H; y++)
			for (let x = 0; x < W; x++)
			{
				if (!ok(y * W + x))
					continue;
				let w = 0;
				while (x + w < W && ok(y * W + x + w)) w++;
				let h = 1;
				for (; y + h < H; h++)
				{
					let full = true;
					for (let k = 0; k < w && full; k++) full = ok((y + h) * W + x + k);
					if (!full) break;
				}
				// a tall thin run is a vertical corridor: re-measure it column-first
				if (w < h)
				{
					let w2 = 1;
					for (; x + w2 < W; w2++)
					{
						let full = true;
						for (let k = 0; k < h && full; k++) full = ok((y + k) * W + x + w2);
						if (!full) break;
					}
					w = Math.min(w, w2);
				}
				for (let yy = y; yy < y + h; yy++)
					for (let xx = x; xx < x + w; xx++)
						used[yy * W + xx] = 1;
				if (Math.max(w, h) >= 5)
					out.push({ x, y, w, h });
			}
		return out;
	}

	// ---- exits (BS::initilize) ----
	const exits = [];
	const markers = [];		// exit positions with destination, for BS::unknown6c2230's spacing
	const usedCorr = new Set(), usedRooms = new Set();
	const amount = ((W + H) / 2 / 4) | 0, first = ((W + H) / 2 / 6) | 0;
	const groups = { 0x10: [], 0x11: [], 0x12: [], 0x13: [], 0x14: [] };
	for (const s of map.starts || [])
	{
		const g = s.type === 'enter' ? 0x11 : s.type === 'exit' ? 0x12 : s.type === 'either' ? 0x10 : 0;
		if (g && inb(s.x, s.y) && cells[s.y * W + s.x] === FLOOR && !flagged[s.y * W + s.x])
			groups[g].push({ x: s.x, y: s.y });
	}
	// prefab exit markers: one per branch-exit stand-in, named by destination
	for (const r of map.reserved || [])
		if (r.kind === 'branch-exit' && r.dest >= 0 && !r.sealed)
		{
			const p = floorNear(r.x + (r.w >> 1), r.y + (r.h >> 1), r);
			if (p)
				groups[0x14].push({ x: p.x, y: p.y, dest: r.dest });
		}

	function floorNear(cx, cy, rect)
	{
		let best = null, bd = 1e9;
		for (let y = rect.y; y < rect.y + rect.h; y++)
			for (let x = rect.x; x < rect.x + rect.w; x++)
				if (inb(x, y) && cells[y * W + x] === FLOOR)
				{
					const d = (x - cx) * (x - cx) + (y - cy) * (y - cy);
					if (d < bd) { bd = d; best = { x, y }; }
				}
		return best;
	}
	const popRandom = list => list.splice(Math.floor(rng.next() * list.length), 1)[0];
	const near = (x, y, level) => markers.filter(m => distCeil(x, y, m.x, m.y) <= (m.dest === level ? amount : first)).length;

	// BS::unknown6c2230
	function randomSpot(level)
	{
		let pool = corridors.map((r, k) => k).filter(k => !usedCorr.has(k));
		if (pool.length)
		{
			const far = pool.filter(k => !near(cx(corridors[k]), cy(corridors[k]), level));
			const k = rng.pick(far.length ? far : pool);
			const time = near(cx(corridors[k]), cy(corridors[k]), level) * 40;
			if (!(time && rng.chance(time)))
			{
				usedCorr.add(k);
				return centreFloor(corridors[k]);
			}
		}
		pool = rooms.map((r, k) => k).filter(k => !usedRooms.has(k));
		if (pool.length)
		{
			const far = pool.filter(k => !near(cx(rooms[k]), cy(rooms[k]), level));
			const k = rng.pick(far.length ? far : pool);
			usedRooms.add(k);
			return centreFloor(rooms[k]);
		}
		for (let tries = 0; tries < 100000; tries++)
		{
			const x = rng.rangeInt(1, W - 2), y = rng.rangeInt(1, H - 2);
			if (cells[y * W + x] !== FLOOR || flagged[y * W + x])
				continue;
			if (DIRS8.every(([dx, dy]) => cells[(y + dy) * W + x + dx] === FLOOR))
				return { x, y };
		}
		return null;
	}
	function cx(r) { return r.x + (r.w >> 1); }
	function cy(r) { return r.y + (r.h >> 1); }
	function centreFloor(r)
	{
		const x = cx(r), y = cy(r);
		if (cells[y * W + x] === FLOOR && !guard[y * W + x])
			return { x, y };
		return floorNear(x, y, r) || { x, y };
	}

	function addStairs(p, dest)
	{
		if (!p || cells[p.y * W + p.x] !== FLOOR)
			return;
		exits.push({ x: p.x, y: p.y, kind: 'stairs', dest, arrival: false });
		markers.push({ x: p.x, y: p.y, dest });
		guardAround(p.x, p.y);
	}
	function guardAround(x, y)
	{
		for (let dy = -1; dy <= 1; dy++)
			for (let dx = -1; dx <= 1; dx++)
				if (inb(x + dx, y + dy))
					guard[(y + dy) * W + x + dx] = 1;
	}

	const links = opts.links || linksFor(type, depth, rng);
	const mainNext = main ? links.find(isMainType) : undefined;
	if (mainNext !== undefined)
	{
		let remaining = MAIN_EXITS[type];
		for (const g of [0x13, 0x12, 0x10])
			while (remaining && groups[g].length)
			{
				addStairs(popRandom(groups[g]), mainNext);
				remaining--;
			}
		while (remaining--)
			addStairs(randomSpot(mainNext), mainNext);
	}
	for (const dest of links)
	{
		if (dest === mainNext)
			continue;
		const order = isMainType(dest) ? [0x13, 0x12, 0x10] : [0x14, 0x12, 0x10];
		const range = BRANCH_EXITS[dest];
		let count = isMainType(dest) ? MAIN_EXITS[type] : rng.rangeInt(range[0], range[1]);
		while (count--)
		{
			let p = null;
			for (const g of order)
			{
				if (g === 0x14)
				{
					const named = groups[g].filter(m => m.dest === dest);
					if (!named.length)
						continue;
					p = named[Math.floor(rng.next() * named.length)];
					groups[g].splice(groups[g].indexOf(p), 1);
				}
				else if (groups[g].length)
					p = popRandom(groups[g]);
				if (p)
					break;
			}
			addStairs(p || randomSpot(dest), dest);
		}
	}
	// arrival (BS+0x8): an 'enter' start, else an 'either' start, else BS::unknown6c2230(0x27)
	const arrival = groups[0x11].length ? popRandom(groups[0x11]) : groups[0x10].length ? popRandom(groups[0x10]) :
		randomSpot(0x27);
	exits.push({ x: arrival.x, y: arrival.y, kind: 'stairs', dest: -1, arrival: true,
		from: main ? MAIN_BY_DEPTH[depth + 1] : type === 27 ? 26 : MAIN_BY_DEPTH[depth] });
	guardAround(arrival.x, arrival.y);
	const start = { x: arrival.x, y: arrival.y };
	const startIdx = start.y * W + start.x;

	// ---- connectivity bookkeeping ----
	const mark = new Uint32Array(N), queue = new Int32Array(N);
	let gen = 0;
	const passable = c => c === FLOOR || c === DOOR;
	function reach()
	{
		gen++;
		let head = 0, tail = 0, n = 0;
		queue[tail++] = startIdx;
		mark[startIdx] = gen;
		while (head < tail)
		{
			const i = queue[head++];
			n++;
			const x = i % W, y = (i / W) | 0;
			for (const [dx, dy] of DIRS8)
			{
				const nx = x + dx, ny = y + dy;
				if (nx < 0 || ny < 0 || nx >= W || ny >= H)
					continue;
				const j = ny * W + nx;
				if (mark[j] !== gen && passable(cells[j]))
				{
					mark[j] = gen;
					queue[tail++] = j;
				}
			}
		}
		return n;
	}
	let reachable = reach();
	const reachable0 = new Uint8Array(N);
	for (let i = 0; i < N; i++)
		if (mark[i] === gen)
			reachable0[i] = 1;

	// ---- machines ----
	const machines = [];
	const gaPos = [];		// origins[5]: Garrison Access anchors
	const dsfExits = [];
	const facingSize = (len, dep, facing) => (facing === 0 || facing === 2) ? [len, dep] : [dep, len];

	// floor footprint check (opt4_isAreaEmpty-like): every cell open floor, nothing machine/door within `pad`
	function areaEmpty(x, y, w, h, pad)
	{
		for (let yy = y - pad; yy < y + h + pad; yy++)
			for (let xx = x - pad; xx < x + w + pad; xx++)
			{
				if (!inb(xx, yy))
					return false;
				const i = yy * W + xx, inside = xx >= x && yy >= y && xx < x + w && yy < y + h;
				if (inside && (cells[i] !== FLOOR || flagged[i] || guard[i]))
					return false;
				if (!inside && (cells[i] === MACHINE || cells[i] === DOOR))
					return false;
			}
		return true;
	}
	function stamp(m)
	{
		let lost = 0;
		for (let y = m.y; y < m.y + m.h; y++)
			for (let x = m.x; x < m.x + m.w; x++)
			{
				const i = y * W + x;
				if (reachable0[i] && passable(cells[i]))
					lost++;
				cells[i] = MACHINE;
			}
		return lost;
	}
	function unstamp(m, prev)
	{
		let k = 0;
		for (let y = m.y; y < m.y + m.h; y++)
			for (let x = m.x; x < m.x + m.w; x++)
				cells[y * W + x] = prev[k++];
	}
	// place a batch of floor-standing machines; revert all if any reachable floor gets cut off
	function commit(batch)
	{
		const saved = batch.map(m =>
		{
			const prev = [];
			for (let y = m.y; y < m.y + m.h; y++)
				for (let x = m.x; x < m.x + m.w; x++)
					prev.push(cells[y * W + x]);
			return prev;
		});
		let lost = 0;
		for (const m of batch)
			lost += stamp(m);
		if (lost)
		{
			const now = reach();
			if (now !== reachable - lost)
			{
				for (let k = batch.length - 1; k >= 0; k--)
					unstamp(batch[k], saved[k]);
				return false;
			}
			reachable = now;
		}
		for (const m of batch)
			machines.push(m);
		return true;
	}

	function interactive(kind, tier, x, y, facing, len, dep)
	{
		const [w, h] = facingSize(len, dep, facing);
		// anchor: front-centre cell; door: the cell in front of it
		let ax, ay;
		switch (facing)
		{
		case 0: ax = x + (w >> 1); ay = y; break;
		case 1: ax = x + w - 1; ay = y + (h >> 1); break;
		case 2: ax = x + (w >> 1); ay = y + h - 1; break;
		default: ax = x; ay = y + (h >> 1); break;
		}
		return { x, y, w, h, name: KIND_NAMES[kind], interactive: true, kind, tier: tier + 1,
			anchor: { x: ax, y: ay }, door: { x: ax + DIR[facing][0], y: ay + DIR[facing][1] } };
	}
	function doorOpen(m)
	{
		const { x, y } = m.door;
		return inb(x, y) && cells[y * W + x] === FLOOR;
	}
	function onPlaced(m)
	{
		if (m.kind === GARRISON)
		{
			gaPos.push(m.anchor);
			exits.push({ x: m.anchor.x, y: m.anchor.y, kind: 'garrison', dest: 13, arrival: false, door: m.door,
				machine: machines.length - 1 });
		}
		else if (m.name === 'DSF Access')
		{
			dsfExits.push(m.anchor);
			exits.push({ x: m.anchor.x, y: m.anchor.y, kind: 'dsf', dest: 14, arrival: false, door: m.door,
				machine: machines.length - 1 });
		}
	}

	// interactive machine lists by size bucket (closestDist[0..2])
	const buckets = [[], [], []];
	const counts = main ? COUNTS_BY_DEPTH[di] || COUNTS_BY_DEPTH[0] : COUNTS_BY_TYPE[type] || [0, 0, 0, 0, 0, 0];
	for (let kind = 0; kind < KIND_NAMES.length; kind++)
		for (let n = counts[kind]; n > 0; n--)
		{
			const size = wpick(rng, SIZE_WEIGHTS[kind]);
			const tier = kind === GARRISON && depth >= 8 ? 0 : wpick(rng, TIER_WEIGHTS[di] || TIER_WEIGHTS[0]);
			buckets[size].push({ kind, tier });
		}
	const planned = buckets.reduce((s, b) => s + b.length, 0);

	// OpD_placeWallProp_6ca780: one machine from bucket `mode` against a wall of rect r (mode 2: centred)
	function placeWallProp(mode, r, margin)
	{
		const list = buckets[mode];
		let k = 0;
		for (let i = 0; i < 50; i++)
		{
			k = Math.floor(rng.next() * list.length);
			if (list[k].kind !== GARRISON ||
				!gaPos.some(p => distCeil(cx(r), cy(r), p.x, p.y) <= GARRISON_SPACING))
				break;
		}
		const { kind, tier } = list[k];
		const [len, dep] = KIND_SIZE[kind][tier];
		const open = [];
		if (r.w >= len + margin * 2 && r.h >= dep + margin * 2)
			open.push(0, 2);
		if (r.w >= dep + margin * 2 && r.h >= len + margin * 2)
			open.push(1, 3);
		if (!open.length)
			return false;
		const side = rng.pick(open);
		// side 0 bottom wall (faces N), 1 left (faces E), 2 top (faces S), 3 right (faces W)
		const facing = side;
		const [w, h] = facingSize(len, dep, facing);
		let x, y;
		if (mode === 2)
		{
			x = cx(r) - (w >> 1);
			y = cy(r) - (h >> 1);
		}
		else
		{
			const alongX = () => rng.chance(50) ? r.x + margin : Math.max(r.x + margin, r.x + r.w - margin - w);
			const alongY = () => rng.chance(50) ? r.y + margin : Math.max(r.y + margin, r.y + r.h - margin - h);
			switch (side)
			{
			case 0: x = alongX(); y = r.y + r.h - margin - h; break;
			case 1: x = r.x + margin; y = alongY(); break;
			case 2: x = alongX(); y = r.y + margin; break;
			default: x = r.x + r.w - margin - w; y = alongY(); break;
			}
		}
		const m = interactive(kind, tier, x, y, facing, len, dep);
		if (!areaEmpty(x, y, w, h, 1) || !doorOpen(m) || !commit([m]))
			return false;
		list.splice(k, 1);
		onPlaced(m);
		return true;
	}

	// lb12_layout_6cadf0: grid of static machines inside rect r
	function layout(mode, r, pad, gap)
	{
		const weights = STATICS.map(s => s[2]);
		const def = STATICS[wpick(rng, weights)];
		const [sw, sh] = def;
		const open = [];
		if (r.w >= sw + pad * 2 && r.h >= sh + pad * 2)
			open.push(0, 2);
		if (r.w >= sh + pad * 2 && r.h >= sw + pad * 2)
			open.push(1, 3);
		if (!open.length)
			return false;
		const rot = rng.pick(open) & 1;
		const w = rot ? sh : sw, h = rot ? sw : sh;
		const cols = ((r.w - pad * 2 - w) / (w + gap) | 0) + 1;
		const rows = ((r.h - pad * 2 - h) / (h + gap) | 0) + 1;
		const ox = r.x + pad + rng.rangeInt(0, r.w - pad * 2 - cols * w - (cols - 1) * gap);
		const oy = r.y + pad + rng.rangeInt(0, r.h - pad * 2 - rows * h - (rows - 1) * gap);
		const grid = [];
		for (let gx = 0; gx < cols; gx++)
			for (let gy = 0; gy < rows; gy++)
			{
				const x = ox + gx * (w + gap), y = oy + gy * (h + gap);
				if (areaEmpty(x, y, w, h, gap))
					grid.push({ x, y, w, h, name: 'Machine', interactive: false });
			}
		if (!grid.length)
			return false;
		// mixing: up to half the slots take another, smaller-or-equal static (0xb9f150 odds)
		if (rng.chance(MIX_CHANCE[mode]))
			for (let n = rng.rangeInt(0, grid.length >> 1); n > 0; n--)
			{
				const slot = grid[Math.floor(rng.next() * grid.length)];
				const other = STATICS[wpick(rng, weights)];
				if (other[0] <= slot.w && other[1] <= slot.h) { slot.w = other[0]; slot.h = other[1]; }
				else if (other[1] <= slot.w && other[0] <= slot.h) { slot.w = other[1]; slot.h = other[0]; }
			}
		return commit(grid);
	}

	// halls (0xd222f0), largest first
	const hallContent = HALL_CONTENT[type] || HALL_CONTENT_DEFAULT;
	for (const r of halls.slice().sort((a, b) => b.w * b.h - a.w * a.h))
	{
		const t = wpick(rng, hallContent);
		const machine = t === 0 || t === 1, statics = t <= 3;
		if (t === 5)
			continue;
		if (machine && buckets[1].length)
			for (let tries = 0; tries < 5 && !placeWallProp(1, r, spacing[3]); tries++);
		if (statics)
			for (let tries = 0; tries < 10 && !layout(1, r, spacing[3], spacing[2]); tries++);
	}
	// rooms (0xcf13e8), shuffled
	const roomContent = ROOM_CONTENT[type] || ROOM_CONTENT[3];
	for (const r of rng.shuffle(rooms.slice()))
	{
		const t = wpick(rng, roomContent);
		if (t >= 4)
			continue;
		if (t <= 1 && buckets[0].length)
			for (let tries = 0; tries < 5 && !placeWallProp(0, r, spacing[1]); tries++);
		for (let tries = 0; tries < 10 && !layout(0, r, spacing[1], spacing[0]); tries++);
	}
	// corridor rects (0xcf3a00), best score first: centred Terminal (50%) or TF Node
	const roomAt = new Int32Array(N).fill(-1);
	rooms.forEach((r, k) =>
	{
		for (let y = r.y; y < r.y + r.h; y++)
			for (let x = r.x; x < r.x + r.w; x++)
				if (inb(x, y)) roomAt[y * W + x] = k;
	});
	const score = r =>
	{
		const touching = new Set();
		let sides = 0;
		const edge = (pts) =>
		{
			let open = false;
			for (const [x, y] of pts)
			{
				if (!inb(x, y))
					continue;
				const i = y * W + x;
				if (roomAt[i] >= 0) touching.add(roomAt[i]);
				else if (area[i] === 4) open = true;
			}
			if (open) sides++;
		};
		const top = [], bottom = [], left = [], right = [];
		for (let x = r.x; x < r.x + r.w; x++) { top.push([x, r.y - 1]); bottom.push([x, r.y + r.h]); }
		for (let y = r.y; y < r.y + r.h; y++) { left.push([r.x - 1, y]); right.push([r.x + r.w, y]); }
		[top, bottom, left, right].forEach(edge);
		return (r.w >> 1) + touching.size * 2 + sides * 3;
	};
	let tfNodes = TF_NODE_TYPES.includes(type) ? (W * H / 4000) | 0 : 0;
	const records = corridors.map(r => ({ r, s: score(r) })).sort((a, b) => b.s - a.s);
	for (const { r } of records)
	{
		if (!buckets[2].length && !tfNodes)
			break;
		if (buckets[2].length && rng.chance(50))
		{
			for (let tries = 0; tries < 5 && !placeWallProp(2, r, spacing[5]); tries++);
			continue;
		}
		if (!tfNodes)
			continue;
		let x = cx(r), y = cy(r);
		if (!(r.w & 1) && rng.chance(50)) x--;
		if (!(r.h & 1) && rng.chance(50)) y--;
		const m = { x, y, w: TF_NODE_SIZE[0], h: TF_NODE_SIZE[1], name: 'TF Node', interactive: false };
		if (areaEmpty(x, y, m.w, m.h, 1) && commit([m]))
			tfNodes--;
	}

	// OpD_findWallStrip_6cbb40: alcove of len x dep wall cells behind a floor strip of `areaType` cells
	function findWallStrip(len, dep, areaType, avoidGarrison, avoidDsf)
	{
		for (let i = 0; i < 100; i++)
		{
			let pt;
			if (areaType === 6 && !halls.length)
				areaType = 4;
			if (areaType === 7 && !rooms.length)
				areaType = 4;
			if (areaType === 4)
			{
				if (!areaCells[4].length)
					return null;
				pt = areaCells[4][Math.floor(rng.next() * areaCells[4].length)];
			}
			else
			{
				const r = rng.pick(areaType === 6 ? halls : rooms);
				pt = rng.rangeInt(r.y, r.y + r.h - 1) * W + rng.rangeInt(r.x, r.x + r.w - 1);
			}
			const px = pt % W, py = (pt / W) | 0;
			if (avoidGarrison && gaPos.some(p => distCeil(px, py, p.x, p.y) <= GARRISON_SPACING))
				continue;
			if (avoidDsf && dsfExits.some(p => distCeil(px, py, p.x, p.y) <= DSF_SPACING))
				continue;
			for (let d = 0; d < 4; d++)
			{
				const [fx, fy] = DIR[d], sx = -fy, sy = fx;	// forward, and the strip direction
				let x = px, y = py;
				for (let s = 0; s < 5; s++)
				{
					x += fx; y += fy;
					if (!inb(x, y))
						break;
					if (cells[y * W + x] !== WALL)
						continue;
					const bx = x - fx, by = y - fy;		// last floor cell before the wall
					const left = rng.rangeInt(0, len + 2), right = len + 2 - left;
					let ok = true;
					for (let k = -left; k <= right && ok; k++)
					{
						const qx = bx + sx * k, qy = by + sy * k;
						ok = inb(qx, qy) && area[qy * W + qx] === areaType && cells[qy * W + qx] === FLOOR &&
							!flagged[qy * W + qx];
					}
					if (ok)
					{
						// alcove: strip cells -left+1 .. -left+len, `dep` deep into the wall
						const ax0 = bx + sx * (-left + 1) + fx, ay0 = by + sy * (-left + 1) + fy;
						const ax1 = ax0 + sx * (len - 1) + fx * (dep - 1), ay1 = ay0 + sy * (len - 1) + fy * (dep - 1);
						const rx = Math.min(ax0, ax1), ry = Math.min(ay0, ay1);
						const rw = Math.abs(ax1 - ax0) + 1, rh = Math.abs(ay1 - ay0) + 1;
						if (ringFree(rx, ry, rw, rh, d))
							return { x: rx, y: ry, w: rw, h: rh, facing: (d + 2) & 3 };
					}
					break;
				}
			}
		}
		return null;
	}
	// opt4_isRingFree6cb8c0: alcove and its ring solid, except the side facing the strip
	function ringFree(x, y, w, h, d)
	{
		if (x < 1 || y < 1 || x + w > W - 1 || y + h > H - 1)
			return false;
		for (let yy = y - 1; yy <= y + h; yy++)
			for (let xx = x - 1; xx <= x + w; xx++)
			{
				const front = (d === 0 && yy === y + h) || (d === 2 && yy === y - 1) ||
					(d === 1 && xx === x - 1) || (d === 3 && xx === x + w);
				if (front)
					continue;
				if (cells[yy * W + xx] !== WALL || flagged[yy * W + xx])
					return false;
			}
		return true;
	}
	function placeInWall(m)
	{
		for (let y = m.y; y < m.y + m.h; y++)
			for (let x = m.x; x < m.x + m.w; x++)
				cells[y * W + x] = MACHINE;
		machines.push(m);
		onPlaced(m);
	}

	// leftovers go into wall alcoves near rooms / halls / corridors
	for (let b = 0; b < 3; b++)
		for (const { kind, tier } of buckets[b].splice(0))
		{
			const [len, dep] = KIND_SIZE[kind][tier];
			const a = findWallStrip(len, dep, WALL_STRIP_AREA[b], kind === GARRISON, false);
			if (a)
				placeInWall(interactive(kind, tier, a.x, a.y, a.facing, len, dep));
		}
	// DSF Accesses: 2x1 alcoves, kept 40 apart
	for (let n = DSF_ACCESSES[type] || 0; n > 0; n--)
		for (const t of DSF_STRIP_AREAS)
		{
			const a = findWallStrip(DSF_SIZE[0], DSF_SIZE[1], t, false, true);
			if (a)
			{
				const m = interactive(0, 0, a.x, a.y, a.facing, DSF_SIZE[0], DSF_SIZE[1]);
				m.name = 'DSF Access';
				delete m.kind;
				placeInWall(m);
				break;
			}
		}

	for (const m of machines)
	{
		delete m.anchor;
		if (!m.interactive || m.name === 'TF Node')
			delete m.door;
	}
	return { exits, machines, start, links, planned };
}

const API = { populate, linksFor, CELL, KIND_NAMES, COUNTS_BY_DEPTH, COUNTS_BY_TYPE, MAIN_EXITS, BRANCH_EXITS,
	DSF_ACCESSES, BRANCHES, MAIN_BY_DEPTH };
if (typeof module === 'object' && module.exports)
	module.exports = API;
else
	root.Props = API;
})(typeof globalThis !== 'undefined' ? globalThis : this);
