#!/usr/bin/env python3
"""Stage and launch a native Windows Cogmind with the external SDL shim.

The owned retail installation is copied, never modified. Use separate stage and
profile directories for the retail baseline and rebuilt executable.
"""
import argparse
import json
import os
from pathlib import Path
import shutil
import subprocess
import ctypes
import time

from compare_gameplay_windows import rpc


# Retail Beta 17.1, GM::initialize (0x789c30) access-token success store.
# This unlocks the console gate, NOT the run's wizard flags or counters.
WIZARD_GATE = 0xCEFACC
WIZARD_GATE_ANCHOR = 0x78B037
WIZARD_GATE_BYTES = bytes.fromhex('c605ccface0001')
DEBUG_KEY = {'keysym': 100, 'ctrl': True, 'alt': True}
WIZARD_COMMANDS = {
    'COORDS': 'toggle coordinate display',
    'GOTO': 'load an existing world node by map name and optional final depth digit (0 means 10)',
    'EVOLVE': 'load a world node through the evolution UI',
    'GIVE': 'give an item by name, initials, or substring',
    'ATTACH': 'create and attach an item, expanding slots up to the game limit',
    'PRESENCE': 'set numeric Complex presence, or toggle presence display without an argument',
    'HIGH_SECURITY': 'trigger high security',
    'ACCESS_LOCKDOWN': 'trigger access lockdown',
    'I': 'restore core integrity, or set a numeric value',
    'M': 'restore matter, or set a numeric value',
    'E': 'restore energy, or set a numeric value',
    'C': 'set corruption (default 99)',
    'H': 'set heat (default 500)',
    'TURN': 'set the map clock; bookkeeping only, not simulated actions',
    'PASS_TURNS': 'advance the map clock; bookkeeping only, not simulated actions',
    'NO_AI': 'toggle no_ai, with game debug message',
    'DESTROY_UNSEEN_FAR': 'destroy entities farther than the given range (default 10)',
}


def validate_wizard_command(command):
    if not command.strip() or len(command.encode('ascii')) > 64 or any(ord(c) < 32 for c in command):
        raise ValueError('wizard commands must be printable ASCII, at most 64 bytes')
    name = command.replace('=', ' ', 1).split()[0].upper()
    if name not in WIZARD_COMMANDS:
        raise ValueError('unsupported wizard command: ' + name)
    if name in ('GOTO', 'EVOLVE', 'GIVE', 'ATTACH', 'TURN', 'PASS_TURNS') and len(command.replace('=', ' ', 1).split()) < 2:
        raise ValueError(name + ' requires an argument')
    return command


def unlock_wizard_gate(proc, value=1):
    """Override/restore only the dev gate of an owned, fingerprinted Popen child."""
    if proc.poll() is not None:
        raise RuntimeError('private game exited before wizard activation')
    kernel = ctypes.WinDLL('kernel32', use_last_error=True)
    kernel.ReadProcessMemory.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_size_t, ctypes.POINTER(ctypes.c_size_t)]
    kernel.WriteProcessMemory.argtypes = kernel.ReadProcessMemory.argtypes
    handle = ctypes.c_void_p(int(proc._handle))
    anchor = ctypes.create_string_buffer(len(WIZARD_GATE_BYTES))
    count = ctypes.c_size_t()
    if not kernel.ReadProcessMemory(handle, WIZARD_GATE_ANCHOR, anchor, len(anchor), ctypes.byref(count)):
        raise ctypes.WinError(ctypes.get_last_error())
    if count.value != len(anchor) or anchor.raw != WIZARD_GATE_BYTES:
        raise RuntimeError('unsupported executable: Beta 17.1 wizard gate fingerprint differs')
    previous = ctypes.c_ubyte()
    if not kernel.ReadProcessMemory(handle, WIZARD_GATE, ctypes.byref(previous), 1, ctypes.byref(count)) or count.value != 1:
        raise ctypes.WinError(ctypes.get_last_error())
    if value not in (0, 1) or previous.value not in (0, 1):
        raise RuntimeError('invalid wizard dev-gate value')
    gate = ctypes.c_ubyte(value)
    if not kernel.WriteProcessMemory(handle, WIZARD_GATE, ctypes.byref(gate), 1, ctypes.byref(count)) or count.value != 1:
        raise ctypes.WinError(ctypes.get_last_error())
    return previous.value


def wizard_state(proc):
    """Read actual PlayerData +0x50 and GM +0x10 folded wizard getters."""
    kernel = ctypes.WinDLL('kernel32', use_last_error=True)
    kernel.ReadProcessMemory.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_size_t, ctypes.POINTER(ctypes.c_size_t)]
    handle = ctypes.c_void_p(int(proc._handle))

    def read(address, size):
        buffer = ctypes.create_string_buffer(size)
        count = ctypes.c_size_t()
        if not kernel.ReadProcessMemory(handle, address, buffer, size, ctypes.byref(count)) or count.value != size:
            raise ctypes.WinError(ctypes.get_last_error())
        return buffer.raw

    gm = int.from_bytes(read(0xCEFAA8, 4), 'little')
    if not gm:
        raise RuntimeError('GM not initialized')
    return {'player_data_wizard': read(0xCF45D8 + 0x50, 1)[0],
            'gm_wizard': read(gm + 0x10, 1)[0]}


def wizard_controls(binary, proc, stage, commands=(), reveal=False, wait_actions=0, timeout=120):
    """Activate through normal game input, then run supported console controls.

    PASS_TURNS/TURN change clocks only. wait_actions sends normal KP5 wait
    actions instead, so the engine actually runs. Delivery is not a turn-count
    assertion: inspect the returned game-produced stat dump for progression.
    """
    commands = [validate_wizard_command(command) for command in commands]
    deadline = time.monotonic() + timeout
    last_error = None
    next_start = time.monotonic() + 5
    while time.monotonic() < deadline:
        if proc.poll() is not None:
            raise RuntimeError('private game exited while waiting for gameplay')
        try:
            state = rpc(binary, proc.pid, [('luigi_raw', {})])[0]
            if state.get('map_width', 0) > 0:
                dump = rpc(binary, proc.pid, [('stat_dump', {})])[0]
                document = json.loads(Path(dump['returned']).with_suffix('.json').read_text())
                if any('@' in row for row in document.get('map', {}).get('lines', [])):
                    break
        except (RuntimeError, OSError, ValueError, KeyError) as error:
            last_error = str(error)
        if time.monotonic() >= next_start:
            # Same startup/menu dismissal used by the gameplay comparison.
            rpc(binary, proc.pid, [('key', {'keysym': 13, 'unicode': 13})])
            next_start = time.monotonic() + 5
        time.sleep(0.5)
    else:
        raise RuntimeError(f'gameplay not ready for wizard activation: {last_error}')
    previous_gate = unlock_wizard_gate(proc)
    log = stage / 'run.log'
    try:
        # One mailbox transaction delivers both keystrokes on the game thread,
        # safely inside CMap::input's 2000 ms activation window.
        rpc(binary, proc.pid, [('key', {**DEBUG_KEY, 'repeat': 2})])
        while time.monotonic() < deadline:
            if proc.poll() is not None:
                raise RuntimeError('private game exited during wizard activation')
            state = wizard_state(proc)
            if (state['player_data_wizard'] == state['gm_wizard'] == 1 and log.exists()
                    and 'Activating wizard mode for current run' in log.read_text(errors='replace')):
                break
            time.sleep(0.1)
        else:
            raise RuntimeError('wizard activation not confirmed by run.log and PlayerData/GM; no controls sent')
    except Exception:
        if proc.poll() is None:
            unlock_wizard_gate(proc, previous_gate)
        raise
    replies = []
    for command in commands:
        rpc(binary, proc.pid, [('key', DEBUG_KEY)])
        time.sleep(0.1)
        reply = rpc(binary, proc.pid, [('text', {'text': command}), ('key', {'keysym': 13, 'unicode': 13})])
        replies.append({'command': command, 'delivery': reply})
        time.sleep(0.5)
    if reveal:
        rpc(binary, proc.pid, [('key', {'keysym': 107, 'ctrl': True, 'shift': True, 'alt': True})])
    for _ in range(wait_actions):
        rpc(binary, proc.pid, [('key', {'keysym': 261})])
    dump = rpc(binary, proc.pid, [('stat_dump', {})])[0]
    return {'label': 'PRIVATE WIZARD RUN — NOT SCORE ELIGIBLE', 'activation_log': str(log),
            'dev_gate_override': {'address': '0xCEFACC', 'previous': previous_gate, 'value': 1,
                                  'method': 'owned-child WriteProcessMemory, dev access gate only',
                                  'teardown': 'restored on failed activation; successful gate exists only in child memory'},
            'activation_state': state,
            'commands': replies, 'reveal': reveal, 'wait_actions_delivered': wait_actions,
            'stat_dump': dump}


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--game', type=Path, help='complete owned retail installation')
    p.add_argument('--stage', type=Path, help='new private game directory')
    p.add_argument('--profile', type=Path, help='isolated benchmark profile')
    p.add_argument('--sdl', type=Path, help='built patched Win32 SDL.dll')
    p.add_argument('--exe', type=Path, help='optional rebuilt executable to install in the private copy')
    p.add_argument('--headless', action='store_true', help='SDL dummy video/audio backends')
    p.add_argument('--seed', default='DECOGWINDOWS1', help='seed for a fresh profile')
    p.add_argument('--difficulty', type=int, choices=(0, 1, 2), default=0)
    p.add_argument('--wizard', action='store_true', help='explicit owned-child dev-gate byte override (not a private access key); activate normal double-command wizard run')
    p.add_argument('--statmind', type=Path, help='native Windows StatMind executable; required for wizard controls')
    p.add_argument('--wizard-command', action='append', default=[], metavar='COMMAND', help='repeatable supported console command; see --list-wizard-commands')
    p.add_argument('--wizard-reveal', action='store_true', help='fill the known map through the normal wizard key binding')
    p.add_argument('--wizard-wait', type=int, default=0, metavar='ACTIONS', help='deliver normal KP5 waits after console commands (runs engine, unlike PASS_TURNS)')
    p.add_argument('--list-wizard-commands', action='store_true', help='print supported parser command semantics and exit')
    args = p.parse_args()
    if args.list_wizard_commands:
        print(json.dumps(WIZARD_COMMANDS, indent=2))
        return
    for name in ('game', 'stage', 'profile', 'sdl'):
        if getattr(args, name) is None:
            p.error('--' + name + ' is required')
    if (args.wizard_command or args.wizard_reveal or args.wizard_wait) and not args.wizard:
        p.error('wizard controls require --wizard')
    if args.wizard and not args.statmind:
        p.error('--wizard requires --statmind')
    if args.wizard_wait < 0:
        p.error('--wizard-wait must be nonnegative')
    try:
        for command in args.wizard_command:
            validate_wizard_command(command)
    except (ValueError, UnicodeError) as error:
        p.error(str(error))
    if not args.seed.isalnum():
        p.error('seed must contain only letters and numbers')
    game, stage, profile = (path.resolve() for path in (args.game, args.stage, args.profile))
    if stage == game or stage in game.parents or game in stage.parents:
        p.error('stage must be separate from the original installation')
    if stage.exists():
        p.error('stage already exists; choose a new directory to preserve existing runs')
    if profile == game or profile in game.parents or game in profile.parents:
        p.error('profile must be separate from the original installation')
    if profile.exists() and any(profile.iterdir()):
        p.error('profile already contains files; choose a fresh directory for a seeded run')
    shutil.copytree(game, stage)
    shutil.copy2(args.sdl, stage / 'SDL.dll')
    if args.exe:
        shutil.copy2(args.exe, stage / 'COGMIND.exe')
    for folder in ('user', 'scores', 'screenshots', 'dumps'):
        (profile / folder).mkdir(parents=True, exist_ok=True)
    if not (profile / 'user/options.cfg').exists():
        (profile / 'user/options.cfg').write_text(f'playerName="decog"\nworldSeed="{args.seed}"\nuploadScores=0\nnewsUpdates=0\nreportErrors=0\nshowIntro=0\nshowTutorial=0\ndifficultyMode={args.difficulty}\n')
        (profile / 'user/advanced.cfg').write_text('jsonScoresheet=1\njsonStatDump=1\nquickStart=1\nanimateMapIntro=0\nwarnOnCaveinMove=0\nwarnOnMoveOutsideMapView=0\nignoreAscendConfirmation=1\nnoQuitDeleteSave=1\n')
        (profile / 'user/system.cfg').write_text('fullscreen=0\nborderless=0\nfontSet="AUTO"\nnoAudio=1\n')
    env = os.environ.copy()
    env['SDL_VIDEODRIVER'] = 'dummy' if args.headless else 'windib'
    env['SDL_AUDIODRIVER'] = 'dummy' if args.headless else 'waveout'
    log = stage / 'harness-launch.log'
    with log.open('wb') as output:
        proc = subprocess.Popen([str(stage / 'COGMIND.exe'), '-luigiAi', '-customFilePath:' + str(profile)], cwd=stage, env=env, stdout=output, stderr=output, creationflags=subprocess.CREATE_NO_WINDOW)
    session = {'pid': proc.pid, 'stage': str(stage), 'profile': str(profile), 'log': str(log), 'headless': args.headless}
    if args.wizard:
        try:
            session['wizard'] = wizard_controls(args.statmind.resolve(), proc, stage,
                                                args.wizard_command, args.wizard_reveal, args.wizard_wait)
        except Exception:
            # Only the child created above; never attach/kill by process name.
            if proc.poll() is None:
                proc.terminate()
                proc.wait()
            raise
    (stage / 'harness-session.json').write_text(json.dumps(session, indent=2))
    print(json.dumps(session, indent=2))


if __name__ == '__main__':
    main()
