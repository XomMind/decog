/* Programmer (extermination) squad dispatch, COGMIND.exe Beta 17.1.

   Dispatch logic, timer and squad search areas follow functions this repo has matched byte-for-byte:
     BS::playerActionFinish           0x774390  src/game/team_d_127.cpp     zone credit per action
     OpR3c_Overmind::resetSurgicalTimer 0x684c40  src/op/op_r3c.cpp         timer roll
     Overmind::turnUpdate             0x675100  src/util/echo_02.cpp        due check, squad areas
     Overmind::spawnSurgicalParty     0x685a10  src/op/op_overmind_surgical.cpp
     Overmind::findDispatchExit       0x683500  src/game/team_d_16.cpp
     BS::onGarrisonAccessDisabled     0x727370  src/op/op_w3.cpp
     OpX4b_World::selectRobotOfClass  0x6c5600  src/op/op_x4b_c.cpp
     OpV1_GameData::generateID        0x46f890  src/op/op_v1.cpp
   Table values were read from the exe at the addresses given next to each table.

   NOT from the decomp: map generation, movement, pathing, field of view and spotting. They are simple stand-ins
   so the dispatch logic has something to react to. Robot speed, sight, memory and spot % come from
   cog-minder's bot data. DOM-free; ui.js drives it in the browser, and node can require() it. */
(function (root) {
'use strict';

// ---------------------------------------------------------------------------------------------------------------
// Exe data
// ---------------------------------------------------------------------------------------------------------------

// 0xcfaca0 (mapNames_cfaca0, src/game/global_string_arrays.cpp); index = location map type
const MAP_NAMES = ['Sandbox', 'Scrapyard', 'Materials', 'Factory', 'Research', 'Access', 'Surface', 'Mines', 'Exiles',
	'Storage', 'Recycling', 'Scraptown', 'Waste', 'Garrison', 'DSF', 'Subcaves', 'Lower Caves', 'Upper Caves',
	'Proximity Caves', 'Deep Caves', 'Zion', 'Data Miner', 'Zhirov', 'Warlord', 'Extension', 'Cetus', 'Archives',
	'Hub_04(d)', 'Armory', 'Lab', 'Quarantine', 'Testing', 'Section 7', 'Protoforge', 'Command', 'Access_0', 'Lair',
	'Wartown'];

// Map types whose 6-byte record at 0xb90180 has byte 0 set (they get timed extermination squads), with their
// zone size and timer credit from 0xb90290 ({int size; int timerCredit;} per map type).
const SURGICAL_BLOCKS = {
	3: { size: 20, credit: 20 },	// Factory
	4: { size: 20, credit: 25 },	// Research
	5: { size: 20, credit: 25 },	// Access
	6: { size: 100, credit: 100 },	// Surface
	9: { size: 15, credit: 20 },	// Storage
	27: { size: 15, credit: 20 },	// Hub_04(d)
	28: { size: 15, credit: 20 },	// Armory
	30: { size: 15, credit: 20 },	// Quarantine
	31: { size: 15, credit: 20 },	// Testing
	32: { size: 20, credit: 20 },	// Section 7
	33: { size: 20, credit: 15 },	// Protoforge
	34: { size: 15, credit: 20 },	// Command
};
// Map types the demo offers. Surface sits outside the depth tables; at Command spawnSurgicalParty pulls the squad
// from robots already on the map (type == 0x22) instead of an exit.
const DEMO_MAP_TYPES = [3, 4, 5, 9, 27, 28, 30, 31, 32, 33];

// 0xb90000: per destination map type, 1 = 0b10-controlled (findDispatchExit accepts it), 2 = caves/outsiders
const EXIT_FLAGS = [1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1,
	1, 1, 1, 2];

// getDepthIndex() = 11 - depth (0x46ed20), so -7 -> 4 ... -1 -> 10.
const depthIndexOf = depth => 11 - depth;

// 0xb93790, 20-byte rows by depth index: [0] min, [1] max turns between dispatches (0 = no squads at this depth)
const INTERVALS = [[0, 0], [0, 0], [0, 0], [0, 0], [300, 1000], [300, 1000], [300, 1000], [300, 850], [300, 850],
	[300, 700], [300, 700]];
// 0xb93738 by depth index: weights of [Programmer, Q-Series] leaders
const LEADER_WEIGHTS = [[0, 0], [0, 0], [0, 0], [0, 0], [100, 0], [100, 0], [100, 0], [100, 0], [80, 20], [70, 30],
	[50, 50]];
// 0xd29310 (surgicalPartySizes_d29310, src/game/team_c_02.cpp) by depth index: [Programmer, Q-Series] {min, max}
// squad size, leader included
const PARTY_SIZES = [[[0, 0], [0, 0]], [[0, 0], [0, 0]], [[0, 0], [0, 0]], [[0, 0], [0, 0]], [[1, 1], [0, 0]],
	[[1, 1], [0, 0]], [[2, 2], [0, 0]], [[2, 2], [0, 0]], [[2, 3], [1, 1]], [[2, 3], [1, 2]], [[2, 3], [2, 2]]];

const ZONE_CLOAK_DELAY = [0, 75, 150];	// 0xb989b4 by RIF Zone Cloak level (max 2, 0xb98958[9]); level 0 adds nothing
const GARRISON_DELAY = 75;			// per disabled Garrison Access (0x684c40 imul 0x4b, BS::onGarrisonAccessDisabled)
const DISPATCH_COOLDOWN = 25;		// turn < lastDispatchTurn + 25: shared with intercept and other dispatches
const MAX_EXTERMINATION = 10;		// countParties(5) >= 10
const TARGET_RADIUS = 15;			// 0xb91df4[0]
const TRACK_TURNS = 150;			// 0xb91e00: phase 1 length, restarted while the leader knows where you are
const WIDEN_DELAY = 200;			// 0xb91e0c: phase 2 length
const WIDEN = [15, 15];				// 0xb91dfc, 0xb91e08: area growth entering phase 2, phase 3
const PARTY_EXTERMINATION = 5;		// partyTypeNames_d2f350[5] = "extermination"

// selectRobotOfClass picks the highest variant whose tier (record +0x68) <= depth index.
// Tiers, speeds (time units per move), sight, memory and spot % from cog-minder bots.json.
const ROBOTS = {
	P: [{ name: 'P-60 Hacker', tier: 4, speed: 56 }, { name: 'P-70 Sage', tier: 6, speed: 56 },
		{ name: 'P-80 Master', tier: 8, speed: 52 }],
	Q: [{ name: 'Q-Series', tier: 8, speed: 110 }],
};
const ROBOT_CLASS = {
	P: { label: 'Programmers', glyph: 'p', sight: 16, memory: 80, spot: 30 },
	Q: { label: 'Q-Series', glyph: 'Q', sight: 16, memory: 60, spot: 50 },
};
const COGMIND_SIGHT = 16;

function selectRobotOfClass(cls, depthIndex)
{
	const list = ROBOTS[cls];
	for (let k = list.length - 1; k >= 0; k--)
		if (list[k].tier <= depthIndex)
			return list[k];
	return null;
}

// ---------------------------------------------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------------------------------------------

function makeRng(seed)
{
	let s = seed >>> 0;
	const next = () =>
	{
		s = (s + 0x6d2b79f5) >>> 0;
		let t = s;
		t = Math.imul(t ^ (t >>> 15), t | 1);
		t ^= t + Math.imul(t ^ (t >>> 7), t | 61);
		return ((t ^ (t >>> 14)) >>> 0) / 4294967296;
	};
	const rng = {
		next,
		// inclusive, like RNG::rangeInt (0x406d70)
		rangeInt(lo, hi) { if (lo > hi) { const t = lo; lo = hi; hi = t; } return lo + Math.floor(next() * (hi - lo + 1)); },
		chance(p) { return rng.rangeInt(0, 99) < p; },
		pick(a) { return a[Math.floor(next() * a.length)]; },
		shuffle(a) { for (let i = a.length - 1; i > 0; i--) { const j = Math.floor(next() * (i + 1)); const t = a[i]; a[i] = a[j]; a[j] = t; } return a; },
		weighted(weights) { let sum = 0; for (const w of weights) sum += w; let r = next() * sum; for (let i = 0; i < weights.length; i++) { if ((r -= weights[i]) < 0) return i; } return weights.length - 1; },
	};
	return rng;
}

const WALL = 0, FLOOR = 1, MACHINE = 2;
const MAP_W = 100, MAP_H = 64;
const DIRS = [[1, 0], [-1, 0], [0, 1], [0, -1], [1, 1], [1, -1], [-1, 1], [-1, -1]];
const cheb = (ax, ay, bx, by) => Math.max(Math.abs(ax - bx), Math.abs(ay - by));

// getRect (0x9b4430): square of radius r around p, clipped to the map
function getRect(x, y, r, w, h)
{
	return { x1: Math.max(0, x - r), y1: Math.max(0, y - r), x2: Math.min(w - 1, x + r), y2: Math.min(h - 1, y + r) };
}

// ---------------------------------------------------------------------------------------------------------------
// Stand-in 0b10 map: a grid of rooms joined by corridors, exits on the edges, two Garrison Accesses
// ---------------------------------------------------------------------------------------------------------------

const COMPLEX_DESTS = [3, 4, 9, 10, 12, 2, 7];	// Factory, Research, Storage, Recycling, Waste, Materials, Mines
const CAVE_DESTS = [16, 17, 8, 20];				// Lower Caves, Upper Caves, Exiles, Zion

function generateMap(rng, mapType)
{
	const w = MAP_W, h = MAP_H;
	const cells = new Uint8Array(w * h);
	const set = (x, y) => { if (x > 0 && y > 0 && x < w - 1 && y < h - 1 && cells[y * w + x] === WALL) cells[y * w + x] = FLOOR; };
	const COLS = 7, ROWS = 5, sw = Math.floor((w - 2) / COLS), sh = Math.floor((h - 2) / ROWS);
	const rooms = [];
	for (let r = 0; r < ROWS; r++)
	{
		for (let c = 0; c < COLS; c++)
		{
			const hall = rng.chance(18);
			const rw = hall ? rng.rangeInt(2, 3) : rng.rangeInt(5, sw - 3);
			const rh = hall ? rng.rangeInt(2, 3) : rng.rangeInt(4, sh - 3);
			const rx = 1 + c * sw + 1 + rng.rangeInt(0, sw - 2 - rw);
			const ry = 1 + r * sh + 1 + rng.rangeInt(0, sh - 2 - rh);
			for (let y = ry; y < ry + rh; y++)
				for (let x = rx; x < rx + rw; x++)
					set(x, y);
			rooms.push({ c, r, x: rx, y: ry, w: rw, h: rh, cx: rx + (rw >> 1), cy: ry + (rh >> 1), hall });
		}
	}
	const at = (c, r) => rooms[r * COLS + c];
	const corridor = (a, b) =>
	{
		const wide = rng.chance(30);
		const dig = (x, y) => { set(x, y); if (wide) { set(x + 1, y); set(x, y + 1); } };
		let x = a.cx, y = a.cy;
		const horizontalFirst = rng.chance(50);
		const stepX = () => { while (x !== b.cx) { x += Math.sign(b.cx - x); dig(x, y); } };
		const stepY = () => { while (y !== b.cy) { y += Math.sign(b.cy - y); dig(x, y); } };
		if (horizontalFirst) { stepX(); stepY(); } else { stepY(); stepX(); }
	};
	// spanning tree over the sector grid, then a few loops
	const visited = new Set([0]);
	const stack = [rooms[0]];
	while (stack.length)
	{
		const cur = stack[stack.length - 1];
		const next = rng.shuffle([[1, 0], [-1, 0], [0, 1], [0, -1]])
			.map(([dc, dr]) => [cur.c + dc, cur.r + dr])
			.filter(([c, r]) => c >= 0 && r >= 0 && c < COLS && r < ROWS && !visited.has(r * COLS + c));
		if (!next.length) { stack.pop(); continue; }
		const n = at(next[0][0], next[0][1]);
		visited.add(n.r * COLS + n.c);
		corridor(cur, n);
		stack.push(n);
	}
	for (let k = 0; k < 9; k++)
	{
		const a = rng.pick(rooms);
		const [dc, dr] = rng.pick([[1, 0], [0, 1]]);
		if (a.c + dc < COLS && a.r + dr < ROWS)
			corridor(a, at(a.c + dc, a.r + dr));
	}

	// exits: short corridors from edge rooms to the map border
	const exits = [];
	const edgeRooms = rng.shuffle(rooms.filter(m => !m.hall && (m.c === 0 || m.r === 0 || m.c === COLS - 1 || m.r === ROWS - 1)));
	const exitPlan = ['arrival', 'complex', 'complex', 'complex', 'cave', 'complex'];
	const usedDest = new Set([mapType]);
	for (let k = 0; k < exitPlan.length && k < edgeRooms.length; k++)
	{
		const m = edgeRooms[k];
		const sides = [];
		if (m.c === 0) sides.push('W');
		if (m.c === COLS - 1) sides.push('E');
		if (m.r === 0) sides.push('N');
		if (m.r === ROWS - 1) sides.push('S');
		const side = rng.pick(sides);
		let x = m.cx, y = m.cy;
		if (side === 'W') { y = m.y + rng.rangeInt(0, m.h - 1); for (x = m.x; x > 1; x--) set(x - 1, y); x = 1; }
		if (side === 'E') { y = m.y + rng.rangeInt(0, m.h - 1); for (x = m.x + m.w - 1; x < w - 2; x++) set(x + 1, y); x = w - 2; }
		if (side === 'N') { x = m.x + rng.rangeInt(0, m.w - 1); for (y = m.y; y > 1; y--) set(x, y - 1); y = 1; }
		if (side === 'S') { x = m.x + rng.rangeInt(0, m.w - 1); for (y = m.y + m.h - 1; y < h - 2; y++) set(x, y + 1); y = h - 2; }
		const kind = exitPlan[k];
		let dest;
		if (kind === 'arrival')
			dest = mapType === 3 ? 2 : 3;	// came down/up from a neighbouring 0b10 level
		else
		{
			const pool = (kind === 'cave' ? CAVE_DESTS : COMPLEX_DESTS).filter(d => !usedDest.has(d));
			dest = rng.pick(pool.length ? pool : (kind === 'cave' ? CAVE_DESTS : COMPLEX_DESTS));
		}
		usedDest.add(dest);
		exits.push({ x, y, idx: y * w + x, kind: 'stairs', dest, flag: EXIT_FLAGS[dest], arrival: kind === 'arrival', prop: null });
	}

	// Garrison Accesses: machines set into a room's top wall, dispatch spot just inside the room
	const garrisonRooms = rng.shuffle(rooms.filter(m => !m.hall && m.w >= 5 && m.y > 2 && !edgeRooms.slice(0, exitPlan.length).includes(m)));
	for (let k = 0; k < 2 && k < garrisonRooms.length; k++)
	{
		const m = garrisonRooms[k];
		const x = m.x + 1 + rng.rangeInt(0, m.w - 3), y = m.y - 1;
		if (cells[y * w + x] !== WALL)
			continue;
		cells[y * w + x] = MACHINE;
		exits.push({ x, y, idx: y * w + x, kind: 'garrison', dest: 13, flag: EXIT_FLAGS[13], arrival: false, prop: { disabled: false } });
	}
	return { w, h, cells, exits, rooms };
}

// ---------------------------------------------------------------------------------------------------------------
// Simulation
// ---------------------------------------------------------------------------------------------------------------

class Sim
{
	constructor(opts = {})
	{
		this.mapType = opts.mapType ?? 3;
		this.depth = opts.depth ?? 5;
		this.zoneCloak = opts.zoneCloak ?? 0;
		this.analysis = opts.analysis ?? true;	// Overmind+0x90 build analysis exists (needed for Q-Series)
		this.mode = opts.mode ?? 'frontier';	// frontier | zones | wander | hold | manual
		this.playerCost = opts.playerCost ?? 75;
		this.newMap(opts.seed ?? 1);
	}

	get depthIndex() { return depthIndexOf(this.depth); }
	get blocks() { return SURGICAL_BLOCKS[this.mapType] || null; }
	get interval() { return INTERVALS[this.depthIndex] || [0, 0]; }
	get dispatchEnabled() { return !!this.blocks && this.interval[0] !== 0; }
	get remaining() { return this.surgicalTimer - this.turn; }
	countParties(type) { let n = 0; for (const p of this.parties) if (p.type === type) n++; return n; }

	newMap(seed)
	{
		this.seed = seed >>> 0;
		const mapRng = makeRng(this.seed);
		this.rng = makeRng(this.seed ^ 0x9e3779b9);
		const m = generateMap(mapRng, this.mapType);
		this.w = m.w; this.h = m.h; this.cells = m.cells; this.exits = m.exits;
		const n = this.w * this.h;
		this.vis = new Uint8Array(n);
		this.seen = new Uint8Array(n);
		this.occ = new Int32Array(n);
		this.walked = new Uint8Array(n);
		this._prev = new Int32Array(n);
		this._q = new Int32Array(n);
		this.floorCount = 0;
		for (let i = 0; i < n; i++) if (this.cells[i] === FLOOR) this.floorCount++;
		this.seenFloor = 0;
		this.turn = 0;
		this.mapTurn = 0;						// Map+0x324: turns on this map
		this.lastDispatchTurn = -1000;			// Overmind+0x6c
		this.disabledGarrisonAccesses = 0;		// BS counter, 75 turns each
		this.failedDispatches = 0;				// Overmind+0x128
		this.recentIDs = [];
		this.dispatchCount = 0;
		this.f74 = 0;							// Overmind+0x74: Factory derelict warning turn
		this.warned = false;					// 0xd257d7
		this.parties = [];
		this.bots = [];
		this.nextId = 2;
		this.log = [];
		this.events = [];
		this.history = [];
		this.trace = {};
		this.travel = -1;
		this.playerPath = [];
		const start = this.exits.find(e => e.arrival) || this.exits[0];
		this.player = { x: start.x, y: start.y, energy: 100 };
		this.occ[start.idx] = 1;
		this.walked[start.idx] = 1;
		this.applyBlocks();
		this.computeFov();
		this.say(`Entered -${this.depth}/${MAP_NAMES[this.mapType]}.`, 'info');
		this.resetSurgicalTimer();	// on map load (src/util/delta2_12.cpp)
		this.recordHistory();
	}

	applyBlocks()
	{
		const size = this.blocks ? this.blocks.size : 20;
		this.bw = Math.ceil(this.w / size);
		this.bh = Math.ceil(this.h / size);
		this.explored = new Uint8Array(this.bw * this.bh);	// Overmind+0x60, cleared on every timer reset
		this.everEntered = new Uint8Array(this.bw * this.bh);
		this.enterable = new Uint8Array(this.bw * this.bh);
		for (let y = 0; y < this.h; y++)
			for (let x = 0; x < this.w; x++)
				if (this.cells[y * this.w + x] === FLOOR)
					this.enterable[((y / size) | 0) * this.bw + ((x / size) | 0)] = 1;
		this.enterableCount = this.enterable.reduce((a, b) => a + b, 0);
	}

	// change location rules in place (same layout, fresh timer, like arriving there)
	setLocation(mapType, depth)
	{
		this.mapType = mapType;
		this.depth = depth;
		this.newMap(this.seed);
	}

	hit(key) { this.trace[key] = (this.trace[key] || 0) + 1; }

	say(text, cls)
	{
		this.log.push({ turn: this.turn, text, cls });
		if (this.log.length > 300) this.log.splice(0, this.log.length - 300);
	}

	event(kind, extra)
	{
		this.events.push(Object.assign({ turn: this.turn, kind }, extra));
		if (this.events.length > 600) this.events.splice(0, this.events.length - 600);
	}

	// ---- OpR3c_Overmind::resetSurgicalTimer (0x684c40) ----
	resetSurgicalTimer()
	{
		const [lo, hi] = this.interval;
		const cloak = this.zoneCloak ? ZONE_CLOAK_DELAY[this.zoneCloak] : 0;
		const roll = this.rng.rangeInt(lo, hi);
		const garrison = this.disabledGarrisonAccesses * GARRISON_DELAY;
		this.surgicalTimer = this.turn + (cloak + roll) + garrison;
		this.explored.fill(0);
		this.cycle = { start: this.turn, lo, hi, roll, cloak, garrison, credits: 0, zones: 0, garrisonLater: 0 };
		this.hit('rst');
	}

	// ---- BS::playerActionFinish (0x774390), the zone part: runs after every action Cogmind takes ----
	playerActionFinish()
	{
		const b = this.blocks;
		if (!b)
			return;
		const k = ((this.player.y / b.size) | 0) * this.bw + ((this.player.x / b.size) | 0);
		this.everEntered[k] = 1;
		if (this.explored[k] === 0)
		{
			this.explored[k] = 1;
			this.surgicalTimer -= b.credit;
			this.cycle.credits += b.credit;
			this.cycle.zones++;
			this.hit('paf.credit');
			this.event('credit', { amount: b.credit });
		}
	}

	// ---- BS::onGarrisonAccessDisabled (0x727370) ----
	disableGarrison(exit)
	{
		const g = exit || this.exits.find(e => e.kind === 'garrison' && !e.prop.disabled);
		if (!g || g.prop.disabled)
			return false;
		g.prop.disabled = true;
		this.disabledGarrisonAccesses++;
		this.surgicalTimer += GARRISON_DELAY;
		this.cycle.garrisonLater += GARRISON_DELAY;
		this.hit('gar');
		this.event('garrison');
		this.say(`Garrison Access at (${g.x},${g.y}) disabled: timer +${GARRISON_DELAY}, and +${GARRISON_DELAY} on every re-roll from now on.`, 'info');
		return true;
	}

	// intercept, search-patrol and assault dispatches write the same lastDispatchTurn (Overmind::turnUpdate)
	otherDispatch()
	{
		this.lastDispatchTurn = this.turn;
		this.say('Another timed 0b10 squad was dispatched this turn (shared 25-turn cooldown).', 'dim');
	}

	// ---- OpV1_GameData::generateID: digit 1-9 + letter, never one of the last 10 ----
	generateID()
	{
		let id;
		do id = this.rng.pick('123456789') + this.rng.pick('ABCDEFGHIJKLMNOPQRSTUVWXYZ');
		while (this.recentIDs.includes(id));
		this.recentIDs.push(id);
		if (this.recentIDs.length >= 10) this.recentIDs.shift();
		return id;
	}

	// ---- Overmind::turnUpdate (0x675100), extermination parts, in source order ----
	overmindTurnUpdate()
	{
		const turn = this.turn, px = this.player.x, py = this.player.y;
		const hunting = p => p.flagC && (p.type === 5 || p.type === 7) && p.value8 !== -2;	// 0x45e7d0
		const knows = p => p.aware > 0;	// leader has Cogmind in its AI target list (EntityAI+0xf0); stand-in: memory
		if (turn % 10 === 0)
		{
			for (const p of this.parties)
			{
				if (hunting(p) && knows(p))
				{
					p.f10 = turn + TRACK_TURNS;
					p.area = getRect(px, py, TARGET_RADIUS, this.w, this.h);
					this.hit('sq.aware');
				}
			}
		}
		if (this.mapTurn % 100 === 0)
		{
			for (const p of this.parties)
			{
				if (hunting(p) && p.f14 !== -1 && !knows(p))
				{
					let r = TARGET_RADIUS;
					if (p.f10 < 0) r += WIDEN[0];
					else if (p.f10 === 0) r += WIDEN[0] + WIDEN[1];
					p.area = getRect(px, py, r, this.w, this.h);
					p.target = -1;
					this.hit('sq.recenter');
					this.event('recenter');
				}
			}
		}
		for (const p of this.parties)
		{
			if (hunting(p) && p.f10 !== 0 && turn === Math.abs(p.f10))
			{
				const late = p.f10 <= 0 ? 1 : 0;
				p.f10 = late ? 0 : -(turn + WIDEN_DELAY);
				if (!knows(p))	// leader AI in area-search mode (mode 3)
				{
					const a = p.area;
					a.x1 = Math.max(0, a.x1 - WIDEN[late]); a.y1 = Math.max(0, a.y1 - WIDEN[late]);
					a.x2 = Math.min(this.w - 1, a.x2 + WIDEN[late]); a.y2 = Math.min(this.h - 1, a.y2 + WIDEN[late]);
				}
				this.hit('sq.phase');
			}
		}

		// the timed extermination dispatch
		if (this.dispatchEnabled && turn >= this.surgicalTimer)	// && !sterilization engaged (Overmind+0x195)
		{
			this.hit('tu.due');
			this.resetSurgicalTimer();
			if (turn < this.lastDispatchTurn + DISPATCH_COOLDOWN || this.countParties(PARTY_EXTERMINATION) >= MAX_EXTERMINATION)
			{
				this.hit('tu.gate');
				const why = turn < this.lastDispatchTurn + DISPATCH_COOLDOWN
					? `a squad was dispatched ${turn - this.lastDispatchTurn} turns ago (< ${DISPATCH_COOLDOWN})`
					: `${MAX_EXTERMINATION} extermination squads already active`;
				this.say(`Timer due, nobody sent: ${why}. The timer has already re-rolled; this cycle is lost.`, 'dim');
				this.event('skip');
			}
			else
			{
				const sent = this.spawnSurgicalParty();
				if (sent)
				{
					this.lastDispatchTurn = turn;
					this.dispatchCount++;
					const party = this.parties[this.parties.length - 1];
					const who = ROBOT_CLASS[party.cls].label;
					this.say(`ALERT: Potential suspicious activity detected, ${who} report to ${MAP_NAMES[this.mapType]} Zone ${this.generateID()}.`, 'alert');
					this.hit('tu.alert');
					this.event('dispatch', { party: party.id });
					if (!this.warned && this.mapType === 3)
						this.f74 = turn + 10;
				}
			}
			// Factory derelict warning: only evaluated inside this branch, i.e. on a turn the timer is due
			if (this.f74 !== 0 && this.f74 === turn)
			{
				const p = this.parties.find(q => q.type === PARTY_EXTERMINATION);
				if (p && p.path.length >= 20)
				{
					this.warned = true;
					this.say('A derelict Thug appears nearby to warn you about the extermination squad.', 'info');
				}
				this.f74 = 0;
			}
		}
	}

	// ---- Overmind::spawnSurgicalParty (0x685a10) ----
	spawnSurgicalParty()
	{
		const di = this.depthIndex;
		let tag;
		do tag = this.rng.weighted(LEADER_WEIGHTS[di]);
		while (tag === 1 && !this.analysis);
		this.hit('sp.pick');
		const cls = tag === 1 ? 'Q' : 'P';
		let followers = this.rng.rangeInt(PARTY_SIZES[di][tag][0], PARTY_SIZES[di][tag][1]) - 1;
		const record = selectRobotOfClass(cls, di);
		if (!record)
			return 0;
		const found = this.findDispatchExit(true, false);
		if (!found)
		{
			this.failedDispatches++;
			this.hit('sp.fail');
			this.say('Timer due, nobody sent: no usable 0b10 exit (failed dispatch).', 'dim');
			this.event('fail');
			return 0;
		}
		this.failedDispatches = Math.max(0, this.failedDispatches - 1);
		this.hit('sp.exit');
		const leader = this.placeBot(record, cls, found.spot);
		if (!leader)
			return 0;
		const party = {
			id: leader.id, type: PARTY_EXTERMINATION, cls, name: record.name, leader, members: [leader],
			value8: -1, flagC: true, f10: this.turn + TRACK_TURNS, f14: 0,	// Party(5, leader, -1, isPlayer, turn + 150)
			area: getRect(this.player.x, this.player.y, TARGET_RADIUS, this.w, this.h),
			exit: found.exit, spawnTurn: this.turn, origin: { x: found.spot % this.w, y: (found.spot / this.w) | 0 },
			aware: 0, memory: ROBOT_CLASS[cls].memory, lastKnown: -1, target: -1, goal: -1, path: [], blocked: 0,
		};
		leader.party = party;
		this.hit('sp.area');
		while (followers)
		{
			const f = this.placeBot(record, cls, found.spot);
			if (!f)
				break;
			f.party = party;
			party.members.push(f);
			followers--;
		}
		this.parties.push(party);
		return party.members.length;
	}

	// ---- Overmind::findDispatchExit (0x683500) as spawnSurgicalParty calls it ----
	// (allowVisible, minDistance 0, ignoreProps, from = -1 so the order is shuffled, no prop preference)
	findDispatchExit(allowVisible, ignoreUsed)
	{
		const candidates = [];
		for (const e of this.exits)
		{
			if (e.flag !== 1)
				continue;
			if (e.prop && e.prop.disabled)
				continue;
			if (allowVisible && !e.prop && this.vis[e.idx])
				continue;
			candidates.push(e);
		}
		if (!candidates.length)
			return allowVisible ? this.findDispatchExit(false, true) : null;
		for (const e of this.rng.shuffle(candidates))
		{
			const spot = this.findPlaceableNear(e.x, e.y, 1);
			if (spot >= 0)
				return { exit: e, spot };
		}
		return null;
	}

	findPlaceableNear(x, y, radius)
	{
		for (let r = 0; r <= radius; r++)
			for (let dy = -r; dy <= r; dy++)
				for (let dx = -r; dx <= r; dx++)
				{
					if (Math.max(Math.abs(dx), Math.abs(dy)) !== r)
						continue;
					const nx = x + dx, ny = y + dy;
					if (nx < 0 || ny < 0 || nx >= this.w || ny >= this.h)
						continue;
					const i = ny * this.w + nx;
					if (this.cells[i] === FLOOR && !this.occ[i])
						return i;
				}
		return -1;
	}

	placeBot(record, cls, near)
	{
		const i = this.findPlaceableNear(near % this.w, (near / this.w) | 0, 4);
		if (i < 0)
			return null;
		const b = { id: this.nextId++, cls, name: record.name, cost: record.speed, sight: ROBOT_CLASS[cls].sight,
			spot: ROBOT_CLASS[cls].spot, x: i % this.w, y: (i / this.w) | 0, energy: 0, party: null };
		this.occ[i] = b.id;
		this.bots.push(b);
		return b;
	}

	destroyParty(p)
	{
		for (const b of p.members)
		{
			this.occ[b.y * this.w + b.x] = 0;
			this.bots.splice(this.bots.indexOf(b), 1);
		}
		this.parties.splice(this.parties.indexOf(p), 1);
		this.say(`Destroyed a ${p.name} squad (${this.countParties(PARTY_EXTERMINATION)} extermination squads left).`, 'info');
	}

	destroyAllSquads()
	{
		while (this.parties.length)
			this.destroyParty(this.parties[0]);
	}

	partyAt(x, y)
	{
		const id = this.occ[y * this.w + x];
		if (id < 2)
			return null;
		const b = this.bots.find(q => q.id === id);
		return b ? b.party : null;
	}

	// ---------------------------------------------------------------------------------------------------------
	// Turn loop (stand-in scheduler: 100 time units per turn, an actor acts while its energy is positive)
	// ---------------------------------------------------------------------------------------------------------

	stepTurn()
	{
		const p = this.player;
		p.energy += 100;
		if (this.mode !== 'manual')
		{
			while (p.energy > 0)
			{
				p.energy -= this.autopilotAct();
				this.playerActionFinish();
			}
		}
		for (const b of this.bots.slice())
		{
			b.energy += 100;
			while (b.energy > 0 && b.party)
			{
				if (b === b.party.leader) this.leaderAct(b.party, b);
				else this.followerAct(b.party, b);
				b.energy -= b.cost;
			}
		}
		this.turn++;
		this.mapTurn++;
		this.updateAwareness();
		this.overmindTurnUpdate();
		this.recordHistory();
	}

	// one keyboard action in manual mode; dx = dy = 0 waits
	manualAct(dx, dy)
	{
		const p = this.player;
		while (p.energy <= 0)
			this.stepTurn();
		let cost = 100;
		if (dx || dy)
		{
			const nx = p.x + dx, ny = p.y + dy;
			if (nx < 0 || ny < 0 || nx >= this.w || ny >= this.h || this.cells[ny * this.w + nx] !== FLOOR || this.occ[ny * this.w + nx])
				return false;
			this.movePlayer(ny * this.w + nx);
			cost = this.playerCost;
		}
		p.energy -= cost;
		this.playerActionFinish();
		return true;
	}

	runUntil(pred, maxTurns)
	{
		for (let k = 0; k < maxTurns; k++)
		{
			this.stepTurn();
			if (pred())
				return true;
		}
		return false;
	}

	recordHistory()
	{
		this.history.push({ turn: this.turn, remaining: this.surgicalTimer - this.turn, squads: this.parties.length });
		if (this.history.length > 4000) this.history.splice(0, this.history.length - 4000);
	}

	// ---- Cogmind autopilot (stand-in) ----
	movePlayer(i)
	{
		const p = this.player;
		this.occ[p.y * this.w + p.x] = 0;
		p.x = i % this.w; p.y = (i / this.w) | 0;
		this.occ[i] = 1;
		this.walked[i] = 1;
		this.computeFov();
	}

	autopilotAct()
	{
		const p = this.player, here = p.y * this.w + p.x;
		if (this.travel >= 0 && this.travel === here)
			this.travel = -1;
		let path = null;
		if (this.travel >= 0)
		{
			const goal = this.travel;
			path = this.bfs(here, i => i === goal);
			if (!path) this.travel = -1;
		}
		if (!path)
		{
			const size = this.blocks ? this.blocks.size : 20;
			const blockOf = i => (((i / this.w) | 0) / size | 0) * this.bw + ((i % this.w) / size | 0);
			switch (this.mode)
			{
			case 'hold':
				return 100;
			case 'zones':
				path = this.bfs(here, i => this.explored[blockOf(i)] === 0);
				break;
			case 'frontier':
				path = this.bfs(here, i => this.seen[i] === 0);
				break;
			}
			if (!path)
			{
				if (this.playerPath.length === 0 || this.occ[this.playerPath[0]])
				{
					const goal = this.randomFloor();
					this.playerPath = this.bfs(here, i => i === goal) || [];
				}
				path = this.playerPath;
			}
			else
				this.playerPath = [];
		}
		if (!path || !path.length)
			return 100;
		const next = path[0];
		if (this.occ[next])
			return 100;
		this.movePlayer(next);
		if (path === this.playerPath)
			path.shift();
		return this.playerCost;
	}

	randomFloor()
	{
		for (;;)
		{
			const i = Math.floor(this.rng.next() * this.w * this.h);
			if (this.cells[i] === FLOOR)
				return i;
		}
	}

	randomFloorIn(a)
	{
		for (let k = 0; k < 80; k++)
		{
			const x = this.rng.rangeInt(a.x1, a.x2), y = this.rng.rangeInt(a.y1, a.y2);
			const i = y * this.w + x;
			if (this.cells[i] === FLOOR)
				return i;
		}
		return -1;
	}

	// ---- squad movement (stand-in): the leader searches its area or chases, followers stay close ----
	leaderAct(party, b)
	{
		const here = b.y * this.w + b.x;
		let goal;
		if (party.aware > 0)
		{
			// chase the last known position; once there without sight of Cogmind, poke around it
			const lk = party.lastKnown, lx = lk % this.w, ly = (lk / this.w) | 0;
			const there = cheb(b.x, b.y, lx, ly) <= 1;
			if (there && party.sees)
				return;
			if (party.target < 0 && !there)
				goal = lk;
			else
			{
				if (party.target < 0 || party.target === here)
					party.target = this.randomFloorIn(getRect(lx, ly, 6, this.w, this.h));
				goal = party.target;
			}
		}
		else
		{
			const a = party.area;
			const inside = i => { const x = i % this.w, y = (i / this.w) | 0; return x >= a.x1 && x <= a.x2 && y >= a.y1 && y <= a.y2; };
			if (party.target < 0 || party.target === here || !inside(party.target))
				party.target = this.randomFloorIn(a);
			goal = party.target;
		}
		if (goal < 0)
			return;
		if (party.goal !== goal || !party.path.length)
		{
			party.goal = goal;
			party.path = this.bfs(here, i => i === goal) || [];
		}
		if (!party.path.length)
		{
			party.target = -1;
			return;
		}
		if (this.moveBot(b, party.path[0]))
		{
			party.path.shift();
			party.blocked = 0;
		}
		else if (++party.blocked > 2)
		{
			party.path = [];
			party.target = -1;
			party.blocked = 0;
		}
	}

	followerAct(party, b)
	{
		const L = party.leader;
		const d = cheb(b.x, b.y, L.x, L.y);
		if (d <= 2)
			return;
		let best = -1, bestD = d;
		for (const [dx, dy] of DIRS)
		{
			const nx = b.x + dx, ny = b.y + dy;
			if (nx < 0 || ny < 0 || nx >= this.w || ny >= this.h)
				continue;
			const i = ny * this.w + nx;
			if (this.cells[i] !== FLOOR || this.occ[i])
				continue;
			const nd = cheb(nx, ny, L.x, L.y);
			if (nd < bestD)
			{
				bestD = nd;
				best = i;
			}
		}
		if (best < 0)
		{
			const path = this.bfs(b.y * this.w + b.x, i => cheb(i % this.w, (i / this.w) | 0, L.x, L.y) <= 1 && !this.occ[i]);
			if (path && path.length)
				best = path[0];
		}
		if (best >= 0)
			this.moveBot(b, best);
	}

	moveBot(b, i)
	{
		if (this.occ[i] || this.cells[i] !== FLOOR)
			return false;
		this.occ[b.y * this.w + b.x] = 0;
		b.x = i % this.w; b.y = (i / this.w) | 0;
		this.occ[i] = b.id;
		return true;
	}

	// spotting (stand-in): a member with line of sight rolls its spot % each turn; the leader then remembers
	// Cogmind's position for its memory stat in turns
	updateAwareness()
	{
		const px = this.player.x, py = this.player.y;
		for (const p of this.parties)
		{
			let sees = false;
			for (const m of p.members)
			{
				const dx = m.x - px, dy = m.y - py;
				if (dx * dx + dy * dy <= m.sight * m.sight && this.lineClear(m.x, m.y, px, py) && (p.aware > 0 || this.rng.chance(m.spot)))
				{
					sees = true;
					break;
				}
			}
			p.sees = sees;
			if (sees)
			{
				if (p.aware <= 0)
				{
					this.say(`${p.name} squad has spotted Cogmind.`, 'warn');
					this.event('spotted');
				}
				p.aware = p.memory;
				p.lastKnown = py * this.w + px;
				p.target = -1;
			}
			else if (p.aware > 0 && --p.aware === 0)
			{
				this.say(`${p.name} squad lost track of Cogmind.`, 'dim');
				p.target = -1;
			}
		}
	}

	// ---- geometry ----
	lineClear(x0, y0, x1, y1)
	{
		const dx = Math.abs(x1 - x0), dy = -Math.abs(y1 - y0), sx = x0 < x1 ? 1 : -1, sy = y0 < y1 ? 1 : -1;
		let err = dx + dy, x = x0, y = y0;
		for (;;)
		{
			if (x === x1 && y === y1)
				return true;
			const e2 = 2 * err;
			if (e2 >= dy) { err += dy; x += sx; }
			if (e2 <= dx) { err += dx; y += sy; }
			if ((x !== x1 || y !== y1) && this.cells[y * this.w + x] === WALL)
				return false;
		}
	}

	computeFov()
	{
		const R = COGMIND_SIGHT, R2 = R * R + R, px = this.player.x, py = this.player.y;
		this.vis.fill(0);
		for (let dy = -R; dy <= R; dy++)
		{
			const y = py + dy;
			if (y < 0 || y >= this.h)
				continue;
			for (let dx = -R; dx <= R; dx++)
			{
				const x = px + dx;
				if (x < 0 || x >= this.w || dx * dx + dy * dy > R2)
					continue;
				if (!this.lineClear(px, py, x, y))
					continue;
				const i = y * this.w + x;
				this.vis[i] = 1;
				if (!this.seen[i])
				{
					this.seen[i] = 1;
					if (this.cells[i] === FLOOR) this.seenFloor++;
				}
			}
		}
		this.fovVersion = (this.fovVersion || 0) + 1;
	}

	// 8-way BFS over floor; returns the steps after start up to the first goal cell, or null
	bfs(start, isGoal)
	{
		const prev = this._prev, q = this._q, w = this.w, h = this.h, cells = this.cells;
		prev.fill(-1);
		let head = 0, tail = 0;
		q[tail++] = start;
		prev[start] = start;
		while (head < tail)
		{
			const i = q[head++];
			if (i !== start && isGoal(i))
			{
				const path = [];
				for (let k = i; k !== start; k = prev[k])
					path.push(k);
				return path.reverse();
			}
			const x = i % w, y = (i / w) | 0;
			for (let d = 0; d < 8; d++)
			{
				const nx = x + DIRS[d][0], ny = y + DIRS[d][1];
				if (nx < 0 || ny < 0 || nx >= w || ny >= h)
					continue;
				const j = ny * w + nx;
				if (prev[j] !== -1 || cells[j] !== FLOOR)
					continue;
				prev[j] = i;
				q[tail++] = j;
			}
		}
		return null;
	}
}

const API = {
	Sim, makeRng, generateMap, selectRobotOfClass, getRect, depthIndexOf,
	MAP_NAMES, SURGICAL_BLOCKS, DEMO_MAP_TYPES, EXIT_FLAGS, INTERVALS, LEADER_WEIGHTS, PARTY_SIZES, ROBOTS, ROBOT_CLASS,
	ZONE_CLOAK_DELAY, GARRISON_DELAY, DISPATCH_COOLDOWN, MAX_EXTERMINATION, TARGET_RADIUS, TRACK_TURNS, WIDEN_DELAY, WIDEN,
	WALL, FLOOR, MACHINE, MAP_W, MAP_H,
};
if (typeof module === 'object' && module.exports)
	module.exports = API;
else
	root.Dispatch = API;
})(typeof globalThis !== 'undefined' ? globalThis : this);
