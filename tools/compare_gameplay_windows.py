#!/usr/bin/env python3
"""Replay identical SDL mailbox actions against two isolated seeded game runs.

Compares game-produced action/turn/resource counters, player-centered known maps,
and initial static terrain. All alphabetic known-map glyphs and entity occupancy
are excluded from the fuzzy verdict and retained in exact observations. This is
a bounded smoke check, with the broad glyph exclusion documented in the report.
"""
import argparse
import ctypes
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import time


def rpc(binary, pid, calls):
    requests = [{'jsonrpc': '2.0', 'id': 1, 'method': 'initialize', 'params': {}}]
    requests += [{'jsonrpc': '2.0', 'id': n + 10, 'method': 'tools/call', 'params': {'name': tool, 'arguments': args}} for n, (tool, args) in enumerate(calls)]
    result = subprocess.run([str(binary), '--mcp', '--pid', str(pid)], input=''.join(json.dumps(x) + '\n' for x in requests), capture_output=True, text=True, timeout=45)
    if result.returncode:
        raise RuntimeError(result.stderr[-3000:])
    replies = {}
    for line in result.stdout.splitlines():
        try:
            data = json.loads(line)
        except ValueError:
            continue
        if data.get('id', 0) >= 10:
            if 'error' in data:
                raise RuntimeError(data['error'])
            text = data['result']['content'][0]['text']
            try:
                replies[data['id'] - 10] = json.loads(text)
            except ValueError:
                replies[data['id'] - 10] = text
    return [replies[n] for n in range(len(calls))]


def observation(binary, pid, previous=None):
    luigi = rpc(binary, pid, [('luigi_raw', {})])[0]
    if luigi.get('map_width', 0) <= 0:
        raise RuntimeError('game map is not loaded yet')
    dump = rpc(binary, pid, [('stat_dump', {})])[0]
    document = json.loads(Path(dump['returned']).with_suffix('.json').read_text())
    known_map = document.get('map', {}).get('lines', [])
    if not any('@' in row for row in known_map):
        raise RuntimeError('player is not placed on a playable map yet')
    # The upstream player record remains (-1,-1) on this native build even in
    # active gameplay. Use the game's serialized player-centered map instead.
    if previous and document.get('cogmind', {}).get('location') == previous.get('cogmind', {}).get('location'):
        terrain, cells = previous, previous['cells']
    else:
        terrain = rpc(binary, pid, [('get_map', {})])[0]
        fields = ('x', 'y', 'cell_id', 'passable', 'transparent')
        cells = [{**{key: cell[key] for key in fields}, 'prop': bool(cell['prop']), 'entity': bool(cell['entity'])} for cell in terrain['cells']]
        cells.sort(key=lambda cell: (cell['y'], cell['x']))
    stats = document.get('stats', {})
    # Game-generated counters prove actions advanced, while wall-clock/session
    # metadata must not make otherwise deterministic runs differ.
    return {'known_map': known_map, 'width': terrain['width'], 'height': terrain['height'], 'cells': cells, 'actions': stats.get('actions'), 'exploration': stats.get('exploration'), 'cogmind': document.get('cogmind')}


def run(args, label, executable):
    stage, profile = args.output / label, args.output / (label + '-profile')
    command = [sys.executable, str(Path(__file__).with_name('cogmind_harness_windows.py')), '--game', str(args.game), '--stage', str(stage), '--profile', str(profile), '--sdl', str(args.sdl), '--seed', args.seed]
    if args.headless:
        command.append('--headless')
    if executable:
        command += ['--exe', str(executable)]
    result = subprocess.run(command, capture_output=True, text=True, check=True)
    session = json.loads(result.stdout)
    pid = session['pid']
    kernel = ctypes.WinDLL('kernel32', use_last_error=True)
    kernel.OpenProcess.argtypes = [ctypes.c_uint32, ctypes.c_int, ctypes.c_uint32]
    kernel.OpenProcess.restype = ctypes.c_void_p
    kernel.WaitForSingleObject.argtypes = [ctypes.c_void_p, ctypes.c_uint32]
    kernel.TerminateProcess.argtypes = [ctypes.c_void_p, ctypes.c_uint32]
    kernel.CloseHandle.argtypes = [ctypes.c_void_p]
    process = kernel.OpenProcess(0x100001, False, pid)  # SYNCHRONIZE | PROCESS_TERMINATE
    if not process:
        raise OSError(ctypes.get_last_error(), 'could not retain launched game handle')
    try:
        return play(args, label, stage, pid)
    finally:
        # Only terminate the PID created for this private stage, including when
        # verification fails. Ask the game to save/exit before fallback cleanup.
        try:
            rpc(args.statmind, pid, [('key', {'keysym': 285, 'alt': True})])
            time.sleep(1)
        except Exception:
            pass
        if kernel.WaitForSingleObject(process, 3000) == 258:
            kernel.TerminateProcess(process, 1)
        kernel.CloseHandle(process)


def play(args, label, stage, pid):
    deadline = time.monotonic() + 90
    last_error = None
    attempts = 0
    while time.monotonic() < deadline:
        try:
            initial = observation(args.statmind, pid)
            if initial['width'] > 0:
                break
        except Exception as error:
            last_error = str(error)
            attempts += 1
            if attempts >= 5 and 'not placed' in last_error:
                # Upstream bot.wake uses RETURN to advance opening dialogue.
                # SPACE opens a command panel once the game becomes playable.
                rpc(args.statmind, pid, [('key', {'keysym': 13, 'unicode': 13})])
        time.sleep(1)
    else:
        raise RuntimeError(f'{label} did not reach gameplay: {last_error}; inspect {stage}')
    # A serialized map can exist while opening consoles still initialize. Prove
    # the base screen accepts gameplay with one identical warm-up wait per run.
    for attempt in range(20):
        rpc(args.statmind, pid, [('key', {'keysym': 46, 'unicode': 46})])
        time.sleep(0.5)
        ready = observation(args.statmind, pid, initial)
        if ready['actions'] != initial['actions']:
            initial = ready
            break
    else:
        raise RuntimeError('game map loaded but no warm-up wait advanced gameplay')
    snapshots = [initial]
    (stage / 'observations.json').write_text(json.dumps(snapshots, indent=2))
    for action in args.actions:
        reply = rpc(args.statmind, pid, [(action['tool'], action.get('arguments', {}))])[0]
        time.sleep(args.settle)
        snapshots.append(observation(args.statmind, pid, snapshots[-1]))
        if snapshots[-1]['actions'] == snapshots[-2]['actions'] and snapshots[-1]['exploration'] == snapshots[-2]['exploration']:
            raise RuntimeError(f'action delivered but no game progression observed: {action}; {reply}')
        (stage / 'last-action.json').write_text(json.dumps({'action': action, 'reply': reply}, indent=2))
        (stage / 'observations.json').write_text(json.dumps(snapshots, indent=2))
    (stage / 'observations.json').write_text(json.dumps(snapshots, indent=2))
    return snapshots


def core(snapshot):
    """Static terrain and authoritative player/counter observations.

    Ambient actors can choose different paths even in repeated retail runs;
    retain those in exact observations and report them separately.
    """
    value = dict(snapshot)
    value['cells'] = [{k: v for k, v in cell.items() if k != 'entity'} for cell in value['cells']]
    value['known_map'] = [''.join(' ' if char.isalpha() else char for char in row) for row in value['known_map']]
    return value


def equivalent(left, right):
    a, b = core(left), core(right)
    ac = {(cell['x'], cell['y']): cell for cell in a.pop('cells')}
    bc = {(cell['x'], cell['y']): cell for cell in b.pop('cells')}
    # The upstream reader may skip a single inaccessible table entry. Compare
    # all jointly observed cells and report coverage; larger gaps fail.
    complete = left['width'] * left['height']
    if len(ac) < complete - 1 or len(bc) < complete - 1:
        return False
    return a == b and all(ac[key] == bc[key] for key in ac.keys() & bc.keys())


def comparison_details(left, right):
    a, b = core(left), core(right)
    ac = {(cell['x'], cell['y']): cell for cell in a['cells']}
    bc = {(cell['x'], cell['y']): cell for cell in b['cells']}
    common = ac.keys() & bc.keys()
    return {
        'common_terrain_cells': len(common),
        'missing_from_left': sorted(bc.keys() - ac.keys()),
        'missing_from_right': sorted(ac.keys() - bc.keys()),
        'differing_common_terrain_cells': sum(ac[key] != bc[key] for key in common),
        'differing_known_map_glyphs': sum(x != y for lrow, rrow in zip(left['known_map'], right['known_map']) for x, y in zip(lrow, rrow)),
        'action_counters_match': left['actions'] == right['actions'],
        'exploration_counters_match': left['exploration'] == right['exploration'],
        'resources_match': left['cogmind'] == right['cogmind'],
    }


def main():
    p = argparse.ArgumentParser(description=__doc__)
    for name in ('game', 'sdl', 'statmind', 'output'):
        p.add_argument('--' + name, type=Path, required=True)
    p.add_argument('--left', type=Path, help='default: retail executable')
    p.add_argument('--right', type=Path, help='default: repeat retail baseline')
    p.add_argument('--seed', default='DECOGWINDOWS1')
    p.add_argument('--actions', type=Path, help='JSON list of {tool, arguments}; default: wait, move east, wait')
    p.add_argument('--headless', action='store_true')
    p.add_argument('--settle', type=float, default=0.5)
    args = p.parse_args()
    args.actions = json.loads(args.actions.read_text()) if args.actions else [{'tool': 'key', 'arguments': {'keysym': key}} for key in (46, 275, 46)]
    args.output.mkdir(parents=True, exist_ok=True)
    left, right = run(args, 'left', args.left), run(args, 'right', args.right)
    differences = [n for n, (a, b) in enumerate(zip(left, right)) if not equivalent(a, b)]
    exact = [n for n, (a, b) in enumerate(zip(left, right)) if a != b]
    report = {'seed': args.seed, 'warmup': 'one wait advancing gameplay before initial observation', 'actions': args.actions, 'snapshots': len(left), 'matching': not differences, 'comparison': 'initial static terrain, player-centered map, resources and action/turn/movement counters; entity occupancy and all alphabetic known-map glyphs excluded (including any alphabetic non-actor features); up to one unreadable terrain entry tolerated', 'exact_matching': not exact, 'different_steps': differences, 'exact_different_steps': exact, 'terrain_coverage': [[len(x['cells']) for x in run] for run in (left, right)], 'fingerprints': [[hashlib.sha256(json.dumps(core(x), sort_keys=True).encode()).hexdigest() for x in run] for run in (left, right)]}
    report['executable_sha256'] = [hashlib.sha256(path.read_bytes()).hexdigest() for path in (args.left or args.game / 'COGMIND.exe', args.right or args.game / 'COGMIND.exe')]
    report['sdl_sha256'] = hashlib.sha256(args.sdl.read_bytes()).hexdigest()
    report['statmind_sha256'] = hashlib.sha256(args.statmind.read_bytes()).hexdigest()
    report['snapshot_comparisons'] = [comparison_details(a, b) for a, b in zip(left, right)]
    (args.output / 'comparison.json').write_text(json.dumps(report, indent=2))
    print(json.dumps(report, indent=2))
    return 1 if differences else 0


if __name__ == '__main__':
    sys.exit(main())
