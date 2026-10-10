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


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--game', type=Path, required=True, help='complete owned retail installation')
    p.add_argument('--stage', type=Path, required=True, help='new private game directory')
    p.add_argument('--profile', type=Path, required=True, help='isolated benchmark profile')
    p.add_argument('--sdl', type=Path, required=True, help='built patched Win32 SDL.dll')
    p.add_argument('--exe', type=Path, help='optional rebuilt executable to install in the private copy')
    p.add_argument('--headless', action='store_true', help='SDL dummy video/audio backends')
    p.add_argument('--seed', default='DECOGWINDOWS1', help='seed for a fresh profile')
    p.add_argument('--difficulty', type=int, choices=(0, 1, 2), default=0)
    args = p.parse_args()
    if not args.seed.isalnum():
        p.error('seed must contain only letters and numbers')
    game, stage, profile = (path.resolve() for path in (args.game, args.stage, args.profile))
    if stage == game or stage in game.parents or game in stage.parents:
        p.error('stage must be separate from the original installation')
    if stage.exists():
        p.error('stage already exists; choose a new directory to preserve existing runs')
    if profile == game or game in profile.parents:
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
    (stage / 'harness-session.json').write_text(json.dumps(session, indent=2))
    print(json.dumps(session, indent=2))


if __name__ == '__main__':
    main()
