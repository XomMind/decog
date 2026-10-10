"""Stage the verified rebuild beside owned Beta 17.1 assets and launch it.

Never modifies the supplied installation or reuses an existing stage/save folder.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--game', type=Path, required=True)
    parser.add_argument('--exe', type=Path, default=Path('build/windows/COGMIND-rebuilt.exe'))
    parser.add_argument('--stage', type=Path, default=Path('build/windows/game'))
    parser.add_argument('--stage-only', action='store_true')
    args = parser.parse_args()
    game, exe, stage = (p.resolve() for p in (args.game, args.exe, args.stage))
    if stage == game or stage in game.parents or game in stage.parents:
        parser.error('Stage must be separate from the owned game installation')
    if stage.exists():
        parser.error('Stage exists; choose a fresh --stage to preserve saves')
    manifest = json.loads(exe.with_suffix('.json').read_text())
    coverage = manifest['coverage']
    if coverage['code_matched'] != coverage['code_bytes'] or coverage['funcs_matched'] != coverage['funcs']:
        parser.error('Playable launch requires complete strict game coverage; partial development builds are refused')
    if hashlib.sha256(exe.read_bytes()).hexdigest() != manifest['output_sha256']:
        parser.error('Executable differs from its reconstruction manifest')
    if hashlib.sha256((game / 'COGMIND.exe').read_bytes()).hexdigest() != manifest['reference_sha256']:
        parser.error('Game installation is not the reference Beta 17.1 release')
    for item in ('SDL.dll', 'SDL_image.dll', 'SDL_mixer.dll', 'SDL_net.dll', 'physfs.dll',
                 'zlib1.dll', 'libsodium.dll', 'data', 'rex', 'cogmind.x'):
        if not (game / item).exists():
            parser.error('Missing game asset/runtime: ' + item)
    shutil.copytree(game, stage)
    shutil.copy2(exe, stage / 'COGMIND-rebuilt.exe')
    shutil.copy2(exe.with_suffix('.json'), stage / 'reconstruction.json')
    # Copy retains the original executable for comparison; launch explicit rebuilt filename.
    if args.stage_only:
        print(stage / 'COGMIND-rebuilt.exe')
        return
    proc = subprocess.Popen([str(stage / 'COGMIND-rebuilt.exe')], cwd=stage)
    (stage / 'play-session.json').write_text(json.dumps({'pid': proc.pid,
        'exe': str(stage / 'COGMIND-rebuilt.exe'), 'cwd': str(stage),
        'sha256': manifest['output_sha256']}, indent=2))
    print('Cogmind rebuild running: PID %d, %s' % (proc.pid, stage))


if __name__ == '__main__':
    main()
