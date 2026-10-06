#!/bin/sh
# One-time native-wine setup (replaces the Docker image/volumes). Needs: msitools (brew), a wine
# engine tarball (Sikarugir's WS12WineCX*.tar.xz works), installers in dls/.
set -e
REPO=$(cd "$(dirname "$0")/.." && pwd)
H=${COGMIND_WINE_HOME:-$HOME/.cogmind-wine}
ENGINE_TAR=${ENGINE_TAR:-$(ls "$HOME"/Library/Application\ Support/Sikarugir/Engines/WS12WineCX*.tar.xz | tail -1)}
mkdir -p "$H/engine" "$H/msvc/vc" "$H/msvc/sdk"
[ -x "$H/engine/wswine.bundle/bin/wine" ] || tar -C "$H/engine" -xf "$ENGINE_TAR"
[ -d "$H/engine/frameworks" ] || { mkdir -p "$H/engine/frameworks"; cp -a "$HOME/Library/Application Support/Sikarugir/Template/"*/Contents/Frameworks/. "$H/engine/frameworks/"; }
[ -d "$H/msvc/vc/Program Files" ] || (cd "$H/msvc/vc" && msiextract -C . "$REPO/dls/sp1/vc_stdx86.msi")
[ -d "$H/msvc/sdk/Program Files" ] || (cd "$H/msvc/sdk" && msiextract -C . "$REPO/dls/sdk71/WinSDKBuild/WinSDKBuild_x86.msi")
export DYLD_FALLBACK_LIBRARY_PATH="$H/engine/frameworks:$H/engine/wswine.bundle/lib"
export WINEPREFIX="$H/prefix" WINEDEBUG=-all
W="$H/engine/wswine.bundle/bin/wine"
"$W" wineboot -i
"$W" regsvr32 rsaenh.dll   # cl.exe temp files need CryptAcquireContext (else D8037)
C="$WINEPREFIX/dosdevices/c:/_/_RL"
mkdir -p "$C/COGMIND" "$C/Protobuffer"
ln -sfn "$REPO" "$C/COGMIND/_cogmind"
ln -sfn "$REPO/3rdparty/protobuf-3.5.1" "$C/Protobuffer/protobuf-3.5.1"
