#!/bin/bash
# Build privately on the owner's x86 Kubernetes BuildKit node, then verify locally.
set -euo pipefail
cd "$(dirname "$0")/../.."
task_context=build/match_push/native_context
mkdir -p "$task_context"
if [ ! -s "$task_context/toolchain.tar.gz" ]; then
	if [ -s build/match_sweep/native_context/toolchain.tar.gz ]; then
		cp build/match_sweep/native_context/toolchain.tar.gz "$task_context/toolchain.tar.gz"
	else
	docker run --rm --platform linux/386 -v cogmind_vs2010:/prefix:ro -v cogmindwine:/root:ro msvc-wine-i386 tar -C / -cf - prefix root/.wine | gzip > "$task_context/toolchain.tar.gz.tmp"
	mv "$task_context/toolchain.tar.gz.tmp" "$task_context/toolchain.tar.gz"
	fi
fi
python3 - "$task_context" <<'PY'
import pathlib, shutil, sys
root = pathlib.Path(sys.argv[1]) / 'project'
if root.exists():
    shutil.rmtree(root)
for name in ('src', 'harness', 'include', 'config', 'tools', '3rdparty/protobuf-3.5.1', 'build/implib'):
    shutil.copytree(name, root / name, ignore=shutil.ignore_patterns('__pycache__'))
(root / 'resources').mkdir()
shutil.copy2('resources/COGMIND.exe', root / 'resources/COGMIND.exe')
(root / 'tools/cl.sh').write_text("#!/bin/sh\nexport WINEDEBUG=-all\nexec wine 'C:\\_\\_RL\\COGMIND\\_cogmind\\tools\\cogmindrun.bat' \"$@\"\n")
(root / 'tools/cl.sh').chmod(0o755)
PY
cp src/match_push/native.Dockerfile "$task_context/Dockerfile"
docker buildx build --builder slacker --platform linux/386 --progress plain --output type=local,dest=build/match_push/native "$task_context"
.venv/bin/python tools/lverify.py --dir build/match_push/native
