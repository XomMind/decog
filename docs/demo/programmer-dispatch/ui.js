/* Page wiring: controls, side panels, live source trace, map interaction. */
(function () {
'use strict';

const D = Dispatch;
const $ = id => document.getElementById(id);
const esc = s => String(s).replace(/[&<>]/g, c => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;' }[c]));

// ---------------------------------------------------------------------------------------------------------------
// condensed source; each line lists the trace keys (Sim.hit) that light it up
// ---------------------------------------------------------------------------------------------------------------
const SRC = [
	['', '// BS::playerActionFinish  0x774390  - after every action Cogmind takes, waiting included', 1],
	['', 'if (mapFlags_b90180[mapType].surgicalParties) {'],
	['', '    Point zone(pos.x / blocks_b90290[mapType].size, pos.y / blocks_b90290[mapType].size);'],
	['paf.credit', '    if (surgicalExplored[zone] == 0) {'],
	['paf.credit', '        surgicalExplored[zone] = 1;'],
	['paf.credit', '        surgicalTimer -= blocks_b90290[mapType].timerCredit;'],
	['', '    }'],
	['', '}'],
	['', ''],
	['', '// Overmind::turnUpdate  0x675100  - once per turn, squad search areas first', 1],
	['sq.aware', 'if (turn % 10 == 0)  for (squad hunting Cogmind whose leader knows where it is)'],
	['sq.aware', '    squad->f10 = turn + 150,  area = getRect(cogmind->pos, 15);'],
	['sq.recenter', 'if (mapTurns % 100 == 0)  for (squad hunting Cogmind that does not, f14 != -1)'],
	['sq.recenter', '    area = getRect(cogmind->pos, 15 + (f10 < 0 ? 15 : f10 == 0 ? 15 + 15 : 0));'],
	['sq.phase', 'if (turn == abs(squad->f10)) {                // 150 turns, then 200 more'],
	['sq.phase', '    squad->f10 = squad->f10 > 0 ? -(turn + 200) : 0;'],
	['sq.phase', '    area.grow(15), area.clip(map);'],
	['', '}'],
	['tu.due', 'if (surgicalMaps_b90180[mapType] && surgicalIntervals_b93790[depth].min'],
	['tu.due', '        && !sterilizationEngaged && turn >= surgicalTimer) {'],
	['tu.due', '    resetSurgicalTimer();'],
	['tu.gate', '    if (turn < lastDispatchTurn + 25 || countParties(EXTERMINATION) >= 10)'],
	['tu.gate', '        ;                                     // nobody sent, the new roll stands'],
	['tu.alert', '    else if (spawnSurgicalParty(cogmind, NULL)) {'],
	['tu.alert', '        lastDispatchTurn = turn;'],
	['tu.alert', '        ALERT("Potential suspicious activity detected, " + who + " report to "'],
	['tu.alert', '              + mapNames[mapType] + " Zone " + generateID() + ".");'],
	['', '    }'],
	['', '}'],
	['', ''],
	['', '// OpR3c_Overmind::resetSurgicalTimer  0x684c40', 1],
	['rst', 'surgicalTimer = turn + (rif[ZONE_CLOAK] ? zoneCloakDelay_b989b4[rif[ZONE_CLOAK]] : 0)'],
	['rst', '              + rng.rangeInt(surgicalIntervals_b93790[depth].min, surgicalIntervals_b93790[depth].max)'],
	['rst', '              + disabledGarrisonAccesses * 75;'],
	['rst', 'surgicalExplored.fill(0);'],
	['', ''],
	['', '// BS::onGarrisonAccessDisabled  0x727370', 1],
	['gar', 'disabledGarrisonAccesses++,  surgicalTimer += 75;'],
	['', ''],
	['', '// Overmind::spawnSurgicalParty  0x685a10', 1],
	['sp.pick', 'do tag = leaderWeights_b93738[depth].pick();             // Programmer or Q-Series'],
	['sp.pick', 'while (tag == QSERIES && (!buildAnalysis || mapType == COMMAND));'],
	['sp.pick', 'followers = partySizes_d29310[depth][tag].random() - 1;'],
	['sp.exit sp.fail', 'if (!findDispatchExit(&spot, true /* skip exits in view */, ...)) { failedDispatches++; return 0; }'],
	['sp.area', 'leader->ai->setArea(getRect(cogmind->pos, 15));'],
	['sp.area', 'addParty(new Party(EXTERMINATION, leader, -1 /* no recall */, true, turn + 150));'],
];

function buildSource()
{
	const pre = $('src');
	pre.innerHTML = SRC.map(([keys, text, comment]) =>
		`<span class="ln${comment ? ' c' : ''}" data-k="${keys}">${esc(text) || ' '}</span>`).join('');
	return [...pre.querySelectorAll('.ln')];
}

// ---------------------------------------------------------------------------------------------------------------
// state
// ---------------------------------------------------------------------------------------------------------------
const hash = new URLSearchParams(location.hash.slice(1));
const ui = {
	playing: true, speed: 15, acc: 0, last: performance.now(), lastPanels: 0, hover: null,
	trace: {}, dispatches: 0, logKey: '',
};
let sim = new D.Sim({
	seed: +hash.get('seed') || 1 + Math.floor(Math.random() * 99999),
	mapType: D.DEMO_MAP_TYPES.includes(+hash.get('map')) ? +hash.get('map') : 3,
	depth: +hash.get('depth') >= 1 && +hash.get('depth') <= 10 ? +hash.get('depth') : 5,
});
const renderer = new Renderer($('map'), $('chart'));
const lines = buildSource();

function writeHash()
{
	history.replaceState(null, '', `#map=${sim.mapType}&depth=${sim.depth}&seed=${sim.seed}`);
}

function rebuild(seed)
{
	const keep = { mode: sim.mode, playerCost: sim.playerCost, zoneCloak: sim.zoneCloak, analysis: sim.analysis };
	sim = new D.Sim(Object.assign(keep, { seed, mapType: +$('mapType').value, depth: +$('depth').value }));
	ui.dispatches = 0;
	ui.trace = {};
	ui.logKey = '';
	$('seed').value = sim.seed;
	writeHash();
	buildTables();
	updatePanels(true);
}

// ---------------------------------------------------------------------------------------------------------------
// controls
// ---------------------------------------------------------------------------------------------------------------
function initControls()
{
	for (const t of D.DEMO_MAP_TYPES)
	{
		const b = D.SURGICAL_BLOCKS[t];
		$('mapType').add(new Option(`${D.MAP_NAMES[t]}  (zones ${b.size}x${b.size}, -${b.credit} turns)`, t));
	}
	for (let d = 10; d >= 1; d--)
	{
		const iv = D.INTERVALS[D.depthIndexOf(d)];
		$('depth').add(new Option(`-${d}${iv[0] ? `  (${iv[0]}-${iv[1]} turns)` : '  (no timed squads)'}`, d));
	}
	$('mapType').value = sim.mapType;
	$('depth').value = sim.depth;
	$('seed').value = sim.seed;
	$('mode').value = sim.mode;
	$('pcost').value = sim.playerCost;
	$('mapType').onchange = $('depth').onchange = () => rebuild(sim.seed);
	$('newMap').onclick = () => rebuild(1 + Math.floor(Math.random() * 99999));
	$('seed').onchange = () => rebuild(Math.max(1, +$('seed').value | 0));
	$('mode').onchange = () => { sim.mode = $('mode').value; sim.travel = -1; updatePanels(true); };
	$('pcost').onchange = () => { sim.playerCost = +$('pcost').value; };
	$('cloak').onchange = () =>
	{
		sim.zoneCloak = +$('cloak').value;
		sim.say(`Zone Cloak set to level ${sim.zoneCloak}: applies from the next re-roll.`, 'dim');
		updatePanels(true);
	};
	$('analysis').onchange = () => { sim.analysis = $('analysis').checked; updatePanels(true); };
	$('garrison').onclick = () => { if (!sim.disableGarrison()) sim.say('No working Garrison Access left on this map.', 'dim'); updatePanels(true); };
	$('other').onclick = () => { sim.otherDispatch(); updatePanels(true); };
	$('kill').onclick = () => { sim.destroyAllSquads(); updatePanels(true); };
	$('play').onclick = togglePlay;
	$('step').onclick = () => { advance(1); updatePanels(true); };
	$('skip').onclick = () =>
	{
		if (!sim.dispatchEnabled)
			return;
		const n = sim.dispatchCount;
		const auto = sim.mode === 'manual';
		if (auto) sim.mode = 'hold';
		sim.runUntil(() => sim.dispatchCount > n, 30000);
		if (auto) sim.mode = 'manual';
		noticeDispatches();
		updatePanels(true);
	};
	$('speed').onchange = () => { ui.speed = +$('speed').value; };
	const toggle = (id, key) =>
	{
		$(id).onclick = () => { renderer.opts[key] = !renderer.opts[key]; $(id).classList.toggle('on', renderer.opts[key]); };
	};
	toggle('vTiles', 'tiles');
	toggle('vObserver', 'observer');
	toggle('vZones', 'zones');
	toggle('vAreas', 'areas');

	const canvas = $('map');
	canvas.addEventListener('mousemove', ev => { ui.hover = renderer.cellAt(sim, ev.clientX, ev.clientY); showTip(ev); });
	canvas.addEventListener('mouseleave', () => { ui.hover = null; $('tip').style.display = 'none'; });
	canvas.addEventListener('click', ev =>
	{
		const c = renderer.cellAt(sim, ev.clientX, ev.clientY);
		if (!c)
			return;
		const party = sim.partyAt(c.x, c.y);
		const exit = sim.exits.find(e => e.x === c.x && e.y === c.y);
		if (party)
			sim.destroyParty(party);
		else if (exit && exit.kind === 'garrison')
			sim.disableGarrison(exit);
		else if (sim.cells[c.y * sim.w + c.x] === D.FLOOR && sim.mode !== 'manual')
			sim.travel = c.y * sim.w + c.x;
		updatePanels(true);
	});
	$('squads').addEventListener('click', ev =>
	{
		const id = ev.target.dataset && ev.target.dataset.kill;
		const p = id && sim.parties.find(q => q.id === +id);
		if (p) { sim.destroyParty(p); updatePanels(true); }
	});

	const keys = {
		ArrowLeft: [-1, 0], ArrowRight: [1, 0], ArrowUp: [0, -1], ArrowDown: [0, 1],
		h: [-1, 0], l: [1, 0], k: [0, -1], j: [0, 1], y: [-1, -1], u: [1, -1], b: [-1, 1], n: [1, 1],
		Numpad4: [-1, 0], Numpad6: [1, 0], Numpad8: [0, -1], Numpad2: [0, 1], Numpad7: [-1, -1], Numpad9: [1, -1], Numpad1: [-1, 1], Numpad3: [1, 1],
	};
	document.addEventListener('keydown', ev =>
	{
		if (ev.target.tagName === 'INPUT' || ev.target.tagName === 'SELECT' || ev.metaKey || ev.ctrlKey)
			return;
		if (sim.mode === 'manual')
		{
			const d = keys[ev.code.startsWith('Numpad') ? ev.code : ev.key];
			if (d) { sim.manualAct(d[0], d[1]); ev.preventDefault(); }
			else if (ev.key === '.' || ev.key === ' ' || ev.code === 'Numpad5') { sim.manualAct(0, 0); ev.preventDefault(); }
			else return;
			noticeDispatches();
			updatePanels(true);
			return;
		}
		if (ev.key === ' ') { togglePlay(); ev.preventDefault(); }
		else if (ev.key === 'n' || ev.key === 'N') { advance(1); updatePanels(true); }
	});
}

function togglePlay()
{
	ui.playing = !ui.playing;
	$('play').textContent = ui.playing ? 'Pause' : 'Play';
	$('play').classList.toggle('on', !ui.playing);
}

function advance(n)
{
	for (let k = 0; k < n; k++)
	{
		sim.stepTurn();
		if (noticeDispatches() && $('pauseOnDispatch').checked)
		{
			if (ui.playing) togglePlay();
			return;
		}
	}
}

function noticeDispatches()
{
	if (sim.dispatchCount === ui.dispatches)
		return false;
	ui.dispatches = sim.dispatchCount;
	const p = sim.parties[sim.parties.length - 1];
	if (p)
	{
		renderer.flash(p.origin.x, p.origin.y, RENDER_COLORS[p.cls]);
		renderer.flash((p.area.x1 + p.area.x2) >> 1, (p.area.y1 + p.area.y2) >> 1, RENDER_COLORS.phase[0]);
	}
	return true;
}

// ---------------------------------------------------------------------------------------------------------------
// panels
// ---------------------------------------------------------------------------------------------------------------
const row = (k, v, cls) => `<div class="row"><span class="k">${k}</span><span class="v${cls ? ' ' + cls : ''}">${v}</span></div>`;
const gate = (state, text) => `<div class="gate ${state}"><span class="m">${state === 'ok' ? '&#10003;' : state === 'no' ? '&#10007;' : '&middot;'}</span><span>${text}</span></div>`;
const phaseText = p => p.f10 > 0 ? `phase 1 &middot; widens at T${p.f10}` : p.f10 < 0 ? `phase 2 &middot; widens at T${-p.f10}` : 'phase 3 &middot; final size';

function updatePanels(force)
{
	const now = performance.now();
	if (!force && now - ui.lastPanels < 120)
		return;
	ui.lastPanels = now;
	const c = sim.cycle, b = sim.blocks, name = D.MAP_NAMES[sim.mapType];
	$('turnLabel').textContent = `turn ${sim.turn} \u00b7 ${sim.mapTurn} on this map`;

	// timer
	if (!sim.dispatchEnabled)
	{
		$('remaining').textContent = '--';
		$('dueAt').textContent = `no timed squads at -${sim.depth} (interval 0 in 0xb93790)`;
		$('bar').style.width = '0';
	}
	else
	{
		$('remaining').textContent = `${sim.remaining} turns`;
		$('dueAt').textContent = `due at turn ${sim.surgicalTimer}`;
		const total = c.roll + c.cloak + c.garrison;
		$('bar').style.width = `${Math.max(0, Math.min(100, 100 * (1 - sim.remaining / total)))}%`;
	}
	$('calc').innerHTML = [
		`<tr><td>rolled at turn ${c.start}: rangeInt(${c.lo}, ${c.hi})</td><td class="n">${c.roll}</td></tr>`,
		`<tr><td>+ Zone Cloak level ${sim.zoneCloak}${c.cloak !== D.ZONE_CLOAK_DELAY[sim.zoneCloak] ? ' (at roll time)' : ''}</td><td class="n">+${c.cloak}</td></tr>`,
		`<tr><td>+ Garrison Accesses disabled before the roll x75</td><td class="n">+${c.garrison}</td></tr>`,
		`<tr><td>&minus; zones entered since the roll: ${c.zones} x ${b ? b.credit : 0}</td><td class="n">&minus;${c.credits}</td></tr>`,
		`<tr><td>+ Garrison Accesses disabled since</td><td class="n">+${c.garrisonLater}</td></tr>`,
		`<tr class="sum"><td>= surgicalTimer (turn ${c.start} + total)</td><td class="n">T${sim.surgicalTimer}</td></tr>`,
	].join('');

	// zones
	const ever = sim.everEntered.reduce((a, v) => a + v, 0);
	$('zones').innerHTML = b ? [
		row('zone size (0xb90290)', `${b.size} x ${b.size} cells, &minus;${b.credit} turns each`),
		row('entered since the last roll', `<span style="color:var(--title)">${c.zones}</span> of ${sim.enterableCount} zones (${Math.round(100 * c.zones / sim.enterableCount)}%)`),
		row('timer pulled forward by', `${c.credits} turns`),
		row('entered at least once on this map', `${ever} of ${sim.enterableCount}`),
		row('map seen (exploration %)', `${(100 * sim.seenFloor / sim.floorCount).toFixed(0)}%`),
		`<div class="note" style="margin-top:4px">Seeing a zone does nothing; standing in it does. Every roll clears the zone grid, so the next action credits the zone you are standing in again.</div>`,
	].join('') : row('zones', 'this map type has no zone timer');

	// conditions
	const iv = sim.interval;
	const cooldownEnd = sim.lastDispatchTurn + D.DISPATCH_COOLDOWN;
	const n = sim.countParties(5);
	const hidden = sim.exits.filter(e => e.kind === 'stairs' && e.flag === 1 && !sim.vis[e.idx]).length;
	const garrisons = sim.exits.filter(e => e.kind === 'garrison' && !e.prop.disabled).length;
	const qw = D.LEADER_WEIGHTS[sim.depthIndex];
	const qChance = qw[0] + qw[1] ? Math.round(100 * qw[1] / (qw[0] + qw[1])) : 0;
	$('gates').innerHTML = [
		gate(b ? 'ok' : 'no', `${name} gets timed extermination squads (0xb90180)`),
		gate(iv[0] ? 'ok' : 'no', iv[0] ? `-${sim.depth} interval ${iv[0]}&ndash;${iv[1]} turns (0xb93790)` : `-${sim.depth}: interval 0, nothing is ever sent`),
		gate(sim.turn >= cooldownEnd ? 'ok' : 'no', sim.lastDispatchTurn < 0 ? 'no timed dispatch yet on this map (25-turn cooldown clear)'
			: sim.turn >= cooldownEnd ? `last timed dispatch T${sim.lastDispatchTurn}, cooldown clear` : `last timed dispatch T${sim.lastDispatchTurn}: blocked until T${cooldownEnd}`),
		gate(n < D.MAX_EXTERMINATION ? 'ok' : 'no', `${n} / ${D.MAX_EXTERMINATION} extermination squads on the map`),
		gate(hidden + garrisons ? 'ok' : 'info', `entry points now: ${hidden} 0b10 exit${hidden === 1 ? '' : 's'} out of view, ${garrisons} working Garrison Access${garrisons === 1 ? '' : 'es'}${hidden + garrisons ? '' : ' (falls back to any 0b10 exit)'}`),
		gate('info', qChance ? `Q-Series ${qChance}% of squads here${sim.analysis ? '' : ', but no build analysis yet: always Programmers'}` : 'Q-Series: never at this depth'),
		gate('info', `next squad: ${D.selectRobotOfClass('P', sim.depthIndex) ? `${D.PARTY_SIZES[sim.depthIndex][0].join('&ndash;')} x ${D.selectRobotOfClass('P', sim.depthIndex).name}` : '&ndash;'}`),
		sim.mapType === 3 ? gate('info', `Factory derelict warning: ${sim.warned ? 'given' : sim.f74 ? `armed for T${sim.f74}, but only checked on a turn the timer is due` : 'not armed'}`) : '',
	].join('');

	// squads
	$('squadCount').textContent = `${n} / ${D.MAX_EXTERMINATION}`;
	$('squads').innerHTML = sim.parties.length ? sim.parties.map(p =>
	{
		const a = p.area;
		const exit = p.exit.kind === 'garrison' ? 'a Garrison Access' : `the ${D.MAP_NAMES[p.exit.dest]} exit`;
		const ph = p.f10 > 0 ? 0 : p.f10 < 0 ? 1 : 2;
		const mind = p.aware > 0 ? `<span style="color:var(--bad)">${p.sees ? 'sees you' : `remembers you ${p.aware}t`}</span>` : 'searching';
		return `<div class="sq ${p.cls}"><div><span style="color:var(--${p.cls.toLowerCase()})">${D.ROBOT_CLASS[p.cls].glyph} x${p.members.length}</span> ${esc(p.name)}
			<span class="ph${ph}">${phaseText(p)}</span><br><span class="k">sent T${p.spawnTurn} via ${exit} &middot; box ${a.x2 - a.x1 + 1}x${a.y2 - a.y1 + 1} &middot; ${mind}</span></div>
			<button data-kill="${p.id}" title="destroy this squad">x</button></div>`;
	}).join('') : '<span class="k">none yet</span>';

	// log
	const key = `${sim.log.length}:${sim.log.length ? sim.log[sim.log.length - 1].turn : 0}:${sim.log.length ? sim.log[sim.log.length - 1].text : ''}`;
	if (key !== ui.logKey)
	{
		ui.logKey = key;
		const el = $('log');
		const stick = el.scrollTop + el.clientHeight >= el.scrollHeight - 20;
		el.innerHTML = sim.log.slice(-120).map(l => `<div class="${l.cls}"><span class="t">T${l.turn}</span>${esc(l.text)}</div>`).join('');
		if (stick) el.scrollTop = el.scrollHeight;
	}

	// live source
	for (const ln of lines)
	{
		const ks = ln.dataset.k;
		if (!ks)
			continue;
		let fired = false;
		for (const k of ks.split(' '))
			if ((sim.trace[k] || 0) !== (ui.trace[k] || 0))
				fired = true;
		if (fired)
		{
			ln.classList.remove('hot');
			void ln.offsetWidth;
			ln.classList.add('hot');
		}
	}
	ui.trace = Object.assign({}, sim.trace);

	// current rows in the tables
	for (const tr of document.querySelectorAll('#depthTable tr[data-d]'))
		tr.classList.toggle('cur', +tr.dataset.d === sim.depth);
	for (const tr of document.querySelectorAll('#mapTable tr[data-t]'))
		tr.classList.toggle('cur', +tr.dataset.t === sim.mapType);
}

function buildTables()
{
	const rows = ['<tr><th>depth</th><th>interval</th><th>P : Q</th><th>Programmers</th><th>Q-Series</th><th>variant</th></tr>'];
	for (let d = 10; d >= 1; d--)
	{
		const di = D.depthIndexOf(d), iv = D.INTERVALS[di], w = D.LEADER_WEIGHTS[di], s = D.PARTY_SIZES[di];
		const v = D.selectRobotOfClass('P', di);
		const range = r => r[1] ? (r[0] === r[1] ? `${r[0]}` : `${r[0]}&ndash;${r[1]}`) : '&ndash;';
		rows.push(`<tr data-d="${d}" class="${iv[0] ? '' : 'off'}"><td>-${d}</td><td>${iv[0] ? `${iv[0]}&ndash;${iv[1]}` : '&ndash;'}</td>
			<td>${iv[0] ? `${w[0]} : ${w[1]}` : '&ndash;'}</td><td>${range(s[0])}</td><td>${range(s[1])}</td><td>${iv[0] && v ? v.name : '&ndash;'}</td></tr>`);
	}
	$('depthTable').innerHTML = rows.join('') +
		'<tr><td colspan="6" class="note" style="text-align:left;white-space:normal">0xb93790 interval &middot; 0xb93738 leader weights &middot; 0xd29310 squad sizes (leader included) &middot; variant = highest Programmer tier &le; depth index (selectRobotOfClass)</td></tr>';
	const mrows = ['<tr><th>map</th><th>zone</th><th>credit</th><th></th></tr>'];
	for (const t of [...D.DEMO_MAP_TYPES, 6, 34])
	{
		const b = D.SURGICAL_BLOCKS[t];
		const note = t === 6 ? 'outside the depth tables' : t === 34 ? 'squad taken from robots already there' : '';
		mrows.push(`<tr data-t="${t}"><td>${D.MAP_NAMES[t]}</td><td>${b.size}x${b.size}</td><td>&minus;${b.credit}t</td><td class="note">${note}</td></tr>`);
	}
	$('mapTable').innerHTML = mrows.join('') +
		'<tr><td colspan="4" class="note" style="text-align:left;white-space:normal">0xb90180 byte 0 &middot; 0xb90290 {size, timerCredit}. Every other map type has no extermination timer.</td></tr>';
	$('quirk').innerHTML = 'Found while reading the matched code: after a Factory dispatch the game arms a one-time derelict warning for 10 turns later (Overmind+0x74), '
		+ 'but the check sits inside the "timer is due" branch, so it only runs on a turn the timer comes due. The timer re-rolls to at least 300 turns at every dispatch, so in Beta 17.1 the warning practically never fires.';
}

function showTip(ev)
{
	const tip = $('tip'), c = ui.hover;
	if (!c)
	{
		tip.style.display = 'none';
		return;
	}
	const i = c.y * sim.w + c.x;
	const out = [`(${c.x}, ${c.y})`];
	if (sim.blocks)
	{
		const s = sim.blocks.size, bx = (c.x / s) | 0, by = (c.y / s) | 0, k = by * sim.bw + bx;
		out[0] += `  zone ${bx},${by}: ${sim.explored[k] ? 'entered since the last roll' : sim.enterable[k] ? `entering it pulls the timer ${sim.blocks.credit} turns closer` : 'no floor'}`;
	}
	const exit = sim.exits.find(e => e.idx === i);
	if (exit && exit.kind === 'garrison')
		out.push(exit.prop.disabled ? 'Garrison Access (disabled): no longer a dispatch point' : 'Garrison Access: squads can enter here even while you watch. Click to disable it (+75 turns).');
	else if (exit)
		out.push(`Exit to ${D.MAP_NAMES[exit.dest]}${exit.arrival ? ' (you arrived here)' : ''}: ` + (exit.flag === 1
			? (sim.vis[i] ? 'a 0b10 exit, but in your view: skipped while another entry point qualifies' : 'a 0b10 exit out of your view: squads can enter here')
			: 'leads outside 0b10 control (flag 2): never used for dispatch'));
	const id = sim.occ[i];
	if (id === 1)
		out.push('Cogmind');
	else if (id > 1)
	{
		const bot = sim.bots.find(q => q.id === id);
		if (bot)
		{
			const p = bot.party;
			out.push(`${bot.name}${p.leader === bot ? ' (squad leader)' : ''}. ${p.aware > 0 ? (p.sees ? 'Sees you.' : `Remembers your position for ${p.aware} more turns.`) : 'Searching its area.'} Click to destroy the squad.`);
		}
	}
	tip.textContent = out.join('\n');
	const wrap = tip.parentElement.getBoundingClientRect();
	let x = ev.clientX - wrap.left + 14, y = ev.clientY - wrap.top + 14;
	tip.style.display = 'block';
	if (x + tip.offsetWidth > wrap.width) x -= tip.offsetWidth + 28;
	if (y + tip.offsetHeight > wrap.height) y -= tip.offsetHeight + 28;
	tip.style.left = `${x}px`;
	tip.style.top = `${y}px`;
}

// ---------------------------------------------------------------------------------------------------------------
// loop
// ---------------------------------------------------------------------------------------------------------------
function frame(now)
{
	const dt = Math.min(0.25, (now - ui.last) / 1000);
	ui.last = now;
	if (ui.playing && sim.mode !== 'manual')
	{
		ui.acc += dt * ui.speed;
		const n = Math.min(400, Math.floor(ui.acc));
		ui.acc -= n;
		if (n)
			advance(n);
	}
	renderer.draw(sim, ui.hover);
	renderer.drawChart(sim);
	updatePanels(false);
	requestAnimationFrame(frame);
}

initControls();
buildTables();
writeHash();
renderer.loadSprites('tiles/').then(ok => { if (!ok) { $('vTiles').disabled = true; $('vTiles').title = 'tiles failed to load'; } });
updatePanels(true);
requestAnimationFrame(frame);
})();
