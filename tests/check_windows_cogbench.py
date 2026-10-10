#!/usr/bin/env python3
"""Opt-in native integration: owned game -> SDL -> StatMind -> TCP cogbench.

Creates a private game/profile, proves a dump and movement advance game counters,
then closes all processes it launched. No model endpoint is used.
"""
import argparse
import ctypes
import json
import os
from pathlib import Path
import socket
import subprocess
import sys
import time


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('game', 'sdl', 'statmind', 'cogbench', 'output'):
        parser.add_argument('--' + name, required=True, type=Path)
    parser.add_argument('--port', type=int, default=31726)
    args = parser.parse_args()
    # Refuse an occupied port before launching anything: do not accidentally
    # send test commands to another person's existing daemon.
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as reservation:
        reservation.bind(('127.0.0.1', args.port))
    root = Path(__file__).resolve().parents[1]
    args.output.mkdir(parents=True, exist_ok=True)
    launch = subprocess.run([sys.executable, str(root / 'tools/cogmind_harness_windows.py'), '--game', str(args.game), '--sdl', str(args.sdl), '--stage', str(args.output / 'game'), '--profile', str(args.output / 'profile'), '--headless'], capture_output=True, text=True, check=True)
    session = json.loads(launch.stdout)
    kernel = ctypes.WinDLL('kernel32', use_last_error=True)
    kernel.OpenProcess.argtypes = [ctypes.c_uint32, ctypes.c_int, ctypes.c_uint32]
    kernel.OpenProcess.restype = ctypes.c_void_p
    kernel.WaitForSingleObject.argtypes = [ctypes.c_void_p, ctypes.c_uint32]
    kernel.TerminateProcess.argtypes = [ctypes.c_void_p, ctypes.c_uint32]
    kernel.CloseHandle.argtypes = [ctypes.c_void_p]
    game = kernel.OpenProcess(0x100001, False, session['pid'])
    if not game:
        raise OSError(ctypes.get_last_error(), 'game handle unavailable')
    env = os.environ.copy()
    env.update(STATMIND_PID=str(session['pid']), COGBENCH_PORT=str(args.port), PYTHONIOENCODING='utf-8')
    script = args.cogbench.resolve() / 'cogbench.py'
    daemon = None

    def command(*words):
        reply = subprocess.run([sys.executable, str(script), *words], env=env, capture_output=True, text=True, encoding='utf-8', timeout=30, check=True)
        return reply.stdout

    with (args.output / 'daemon.log').open('w', encoding='utf-8') as log:
        try:
            daemon = subprocess.Popen([sys.executable, str(script), '--statmind', str(args.statmind.resolve()), 'daemon'], env=env, stdout=log, stderr=log)
            deadline = time.monotonic() + 30
            while time.monotonic() < deadline:
                if daemon.poll() is not None:
                    raise RuntimeError('daemon exited during startup; inspect daemon.log')
                try:
                    with socket.create_connection(('127.0.0.1', args.port), timeout=1):
                        break
                except OSError:
                    time.sleep(0.2)
            else:
                raise RuntimeError('TCP daemon did not become ready')
            for attempt in range(30):
                command('key', '46')
                time.sleep(0.5)
                try:
                    before = json.loads(command('dump'))
                    if before['turns']['actions'].get('overall', 0) > 0:
                        break
                except (ValueError, KeyError):
                    pass
            else:
                raise RuntimeError('no gameplay wait advanced through the daemon')
            movement = command('move', 'e')
            time.sleep(0.5)
            after = json.loads(command('dump'))
            assert after['turns']['spaces_moved'] > before['turns']['spaces_moved'], 'movement did not advance a space'
            assert after['turns']['actions']['overall'] > before['turns']['actions']['overall'], 'movement did not advance an action'
            report = {'session': session, 'movement_reply': movement, 'before': before, 'after': after, 'passed': True}
            (args.output / 'tcp-proof.json').write_text(json.dumps(report, indent=2))
            print(json.dumps({'passed': True, 'before': before['turns'], 'after': after['turns'], 'report': str(args.output / 'tcp-proof.json')}, indent=2))
        finally:
            if daemon:
                try:
                    command('key', '285', 'alt')
                except Exception:
                    pass
                daemon.terminate()
                daemon.wait(timeout=5)
            if kernel.WaitForSingleObject(game, 3000) == 258:
                kernel.TerminateProcess(game, 1)
            kernel.CloseHandle(game)


if __name__ == '__main__':
    main()
