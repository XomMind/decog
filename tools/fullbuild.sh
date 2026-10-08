#!/bin/sh
# Run at utility QoS + nice 10 so builds yield to the user's apps (-b background starved builds: 4 min -> 70+ min).
[ -n "$CM_BG" ] || exec env CM_BG=1 taskpolicy -c utility nice -n 10 "$0" "$@"
# Machine-wide serialized full build: only ONE full LTCG build runs at a time (each one is many wine cl.exe
# processes plus a whole-program link; several at once exhausted 48 GB). Waits for the lock and for free memory.
#   tools/fullbuild.sh <outdir> [lverify args...]     build all sources into <outdir>, then lverify --dir <outdir>
#   tools/fullbuild.sh --run <cmd...>                 run any command under the same lock (used by the integration loop)
# Env: JOBS (default 4) compile parallelism; FULLBUILD_MIN_FREE_GB (default 12) memory needed before starting.
REPO=$(cd "$(dirname "$0")/.." && pwd); cd "$REPO" || exit 1
LOCK=$REPO/build/.fullbuild.lock
mkdir -p "$REPO/build"
free_gb() { vm_stat | awk '/page size of/ {ps=$8} /Pages free/ {f=$3} /Pages inactive/ {i=$3} /Pages speculative/ {s=$3}
                     END {gsub(/\./,"",f); gsub(/\./,"",i); gsub(/\./,"",s); printf "%d", (f+i+s)*ps/1073741824}'; }
PRIO=$REPO/build/.fullbuild.priority   # the integration loop waits with priority: others yield to it
[ "$FULLBUILD_WHO" = integration ] && { echo $$ > "$PRIO"; trap 'rm -f "$PRIO"' EXIT INT TERM; }
waited=0
while { [ "$FULLBUILD_WHO" != integration ] && [ -e "$PRIO" ] && kill -0 "$(cat "$PRIO" 2>/dev/null)" 2>/dev/null; } || ! mkdir "$LOCK" 2>/dev/null; do
  pid=$(cat "$LOCK/pid" 2>/dev/null)
  if [ -n "$pid" ] && ! kill -0 "$pid" 2>/dev/null; then rm -rf "$LOCK"; continue; fi   # stale lock
  [ $waited -eq 0 ] && echo "fullbuild: waiting for lock held by $(cat "$LOCK/who" 2>/dev/null) (pid $pid)" >&2
  waited=1; sleep 15
done
echo $$ > "$LOCK/pid"; echo "${FULLBUILD_WHO:-$1} $(date +%H:%M)" > "$LOCK/who"
[ "$FULLBUILD_WHO" = integration ] && rm -f "$PRIO"
trap 'rm -rf "$LOCK"' EXIT INT TERM
need=${FULLBUILD_MIN_FREE_GB:-12}
while [ "$(free_gb)" -lt "$need" ]; do echo "fullbuild: waiting for ${need} GB free (now $(free_gb) GB)" >&2; sleep 30; done
export JOBS=${JOBS:-4}
if [ "$1" = "--run" ]; then shift; "$@"; exit $?; fi
out=$1; shift
.venv/bin/python tools/ltcg.py "$out" $(.venv/bin/python tools/sources.py) || exit 1
.venv/bin/python tools/lverify.py --dir "$out" "$@"
