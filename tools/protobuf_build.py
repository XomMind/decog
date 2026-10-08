#!/usr/bin/env python3
"""Build the vendored protobuf 3.5.1 runtime with VS2010 SP1, without LTCG.

Usage: .venv/bin/python tools/protobuf_build.py build/protobuf_o2 --profile o2 --jobs 2

The two upstream CMake runtime source lists are authoritative. Compile static-library
style objects (no PROTOBUF_USE_DLLS), archive protobuf.lib, and link all objects into
a /NOENTRY DLL for inspection, not execution: C++ static initializers are not run.
No dependency stubs, generated sources, zlib, or existing full-build outputs are used.
The MSVC upstream default is zlib off; gzip_stream.cc is still in the source list.
All commands, diagnostics and input hashes are recorded in the private output directory.
"""

import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys


REPO = Path(__file__).resolve().parent.parent
PROTOBUF = REPO / "3rdparty" / "protobuf-3.5.1"
WIN_REPO = r"C:\_\_RL\COGMIND\_cogmind"
WIN_PROTOBUF = r"C:\_\_RL\Protobuffer\protobuf-3.5.1"
PROFILES = {"o2": ["/O2"], "o2-fp": ["/O2", "/Oy-"], "o1": ["/O1"]}
LIBRARIES = ["msvcprt.lib", "msvcrt.lib", "kernel32.lib"]


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def quote(value):
    # cl.sh forwards through Wine's batch %*: keep command paths unquoted.
    # Quoted arguments arrive with literal quotes; reject unsafe spellings.
    if any(char.isspace() or char in '"%&|<>^!()' for char in value):
        raise ValueError("unsupported character in Windows argument: " + repr(value))
    return value


def win_path(path):
    return WIN_REPO + "\\" + path.relative_to(REPO).as_posix().replace("/", "\\")


def runtime_sources():
    sources = []
    lists = []
    for name, variable in (("libprotobuf-lite.cmake", "libprotobuf_lite_files"),
                           ("libprotobuf.cmake", "libprotobuf_files")):
        path = PROTOBUF / "cmake" / name
        text = path.read_text()
        match = re.search(r"\bset\(\s*" + re.escape(variable) + r"\s+(.*?)\)", text, re.S)
        if not match:
            raise ValueError("cannot find CMake source list " + variable + " in " + str(path))
        entries = re.sub(r"#[^\n]*", "", match.group(1)).split()
        if not entries:
            raise ValueError("empty CMake source list: " + str(path))
        for entry in entries:
            prefix = "${protobuf_source_dir}/src/"
            if not entry.startswith(prefix) or not entry.endswith(".cc"):
                raise ValueError("unsupported runtime source-list entry: " + entry)
            source = entry[len(prefix):]
            relative = Path(source)
            if relative.is_absolute() or ".." in relative.parts:
                raise ValueError("unsafe runtime source-list entry: " + entry)
            if source in sources:
                raise ValueError("duplicate runtime source: " + source)
            if not (PROTOBUF / "src" / relative).is_file():
                raise ValueError("missing runtime source: " + str(PROTOBUF / "src" / relative))
            sources.append(source)
        lists.append({"path": str(path), "variable": variable, "sha256": digest(path)})
    return sources, lists


def run(command, log):
    argv = [str(REPO / "tools" / "cl.sh"), "cmd", "/c", command]
    try:
        result = subprocess.run(argv, cwd=REPO, capture_output=True,
                                text=True, errors="replace")
        rc = result.returncode
        output = (result.stdout + result.stderr).replace("\r", "")
    except OSError as error:
        rc = None
        output = "could not launch compiler wrapper: " + str(error) + "\n"
    log.write_text(output)
    return rc, output


def save_manifest(outdir, manifest):
    temporary = outdir / "manifest.json.tmp"
    temporary.write_text(json.dumps(manifest, indent=2) + "\n")
    temporary.replace(outdir / "manifest.json")


def build(args):
    outdir = Path(args.outdir).resolve()
    # Only private artifact trees are accepted, including when symlinks are involved.
    # In particular, neither build/full nor its parents can be used accidentally.
    try:
        relative = outdir.relative_to(REPO)
    except ValueError:
        raise ValueError("outdir must be inside the repository's private artifact trees")
    parts = relative.parts
    allowed = (len(parts) >= 2 and parts[0] == "build" and parts[1].startswith("protobuf_"))
    allowed |= (len(parts) >= 2 and parts[:2] == ("scratch", "protobuf_bulk"))
    if not allowed:
        raise ValueError("outdir must be build/protobuf_* or scratch/protobuf_bulk[/...]; build/full is protected")
    # Validate command encoding before creating or removing any outputs.
    quote(win_path(outdir))
    sources, lists = runtime_sources()
    outdir.mkdir(parents=True, exist_ok=True)
    lock = outdir / ".build.lock"
    try:
        descriptor = os.open(lock, os.O_CREAT | os.O_EXCL | os.O_WRONLY, 0o600)
    except FileExistsError:
        raise ValueError("build directory is locked: " + str(lock) +
                         "; remove only if its previous builder is no longer running")
    os.close(descriptor)
    manifest = {
        "schema_version": 1,
        "status": "preparing",
        "profile": args.profile,
        "jobs": args.jobs,
        "outdir": str(outdir),
        "source_root": str(PROTOBUF / "src"),
        "compile_cwd": WIN_PROTOBUF,
        "host_cwd": str(REPO),
        "compiler_wrapper": str(REPO / "tools" / "cl.sh"),
        "toolchain": "VS2010 SP1 x86 via tools/cl.sh",
        "source_lists": lists,
        "zlib": False,
        "ltcg": False,
        "sources": [],
        "artifacts": {"image": "match.dll", "map": "match.map"},
    }
    try:
        wine_home = Path(os.environ.get("COGMIND_WINE_HOME", str(Path.home() / ".cogmind-wine")))
        manifest["wine_home"] = str(wine_home.resolve())
        tools = wine_home / "msvc" / "vc" / "Program Files" / "Microsoft Visual Studio 10.0" / "VC" / "bin"
        manifest["toolchain_files"] = [{"path": str(tools / name),
                                         "sha256": digest(tools / name) if (tools / name).is_file() else None}
                                        for name in ("cl.exe", "c1xx.dll", "c2.dll", "link.exe", "lib.exe")]
        flags = ["/nologo", "/c"] + PROFILES[args.profile] + [
            "/MD", "/EHsc", "/GS", "/DNDEBUG", "/DWIN32", "/D_WINDOWS", "/W3", "/bigobj"]
        flags.append("/I" + quote(WIN_PROTOBUF + "\\src"))
        manifest["compile_flags"] = flags
        objects = set()
        for source in sources:
            obj = Path("objects") / Path(source).with_suffix(".obj")
            if obj.as_posix().casefold() in objects:
                raise ValueError("case-insensitive object collision: " + str(obj))
            objects.add(obj.as_posix().casefold())
            log = Path("logs") / Path(source).with_suffix(".log")
            (outdir / obj).parent.mkdir(parents=True, exist_ok=True)
            (outdir / log).parent.mkdir(parents=True, exist_ok=True)
            # Retail __FILE__ strings use this exact relative spelling. Changing
            # drive/cwd first bypasses cl.sh's repository-relative cwd mapping.
            compile_source = "..\\protobuf-3.5.1\\src\\" + source.replace("/", "\\")
            command = ("cd /d " + quote(WIN_PROTOBUF) + " && cl " + " ".join(flags) +
                       " /Fo" + quote(win_path(outdir / obj)) + " " + quote(compile_source))
            manifest["sources"].append({"source": source, "compile_source": compile_source,
                                         "sha256": digest(PROTOBUF / "src" / source),
                                         "object": obj.as_posix(), "log": log.as_posix(),
                                         "command": command})
        stale = ["match.dll", "match.map", "match.lib", "match.exp", "match.ilk", "link.rsp", "link.log",
                 "protobuf.lib", "archive.rsp", "archive.log"]
        stale += [entry["object"] for entry in manifest["sources"]]
        for name in stale:
            path = outdir / name
            if path.exists():
                path.unlink()
        manifest["status"] = "compiling"
        save_manifest(outdir, manifest)

        def compile_one(entry):
            rc, output = run(entry["command"], outdir / entry["log"])
            return rc, output, (outdir / entry["object"]).is_file() and (outdir / entry["object"]).stat().st_size > 0

        failed = []
        with ThreadPoolExecutor(max_workers=args.jobs) as pool:
            for entry, (rc, output, exists) in zip(manifest["sources"], pool.map(compile_one, manifest["sources"])):
                entry["returncode"] = rc
                entry["object_present"] = exists
                if rc != 0 or not exists:
                    failed.append(entry["source"])
                    print("Compile failed: " + entry["source"] + " (exit " + str(rc) +
                          ", object present: " + str(exists) + ")", file=sys.stderr)
                    print(output, file=sys.stderr, end="" if output.endswith("\n") else "\n")
        if failed:
            manifest["status"] = "compile_failed"
            manifest["failed_sources"] = failed
            save_manifest(outdir, manifest)
            print("No partial link; see " + str(outdir / "manifest.json"), file=sys.stderr)
            return 1
        archive_flags = ["/nologo", "/MACHINE:X86", "/OUT:" + quote(win_path(outdir / "protobuf.lib"))]
        archive_response = outdir / "archive.rsp"
        archive_response.write_text("\n".join(archive_flags +
                                   [quote(win_path(outdir / entry["object"])) for entry in manifest["sources"]]) + "\n")
        archive_command = "lib @" + quote(win_path(archive_response))
        manifest["archive"] = {"flags": archive_flags, "response": "archive.rsp", "command": archive_command,
                                "log": "archive.log", "output": "protobuf.lib"}
        manifest["artifacts"]["library"] = "protobuf.lib"
        manifest["status"] = "archiving"
        save_manifest(outdir, manifest)
        rc, output = run(archive_command, outdir / "archive.log")
        archive = outdir / "protobuf.lib"
        present = archive.is_file() and archive.stat().st_size > 0
        manifest["archive"]["returncode"] = rc
        manifest["archive"]["artifact_present"] = present
        if rc != 0 or not present:
            manifest["status"] = "archive_failed"
            save_manifest(outdir, manifest)
            if archive.exists():
                archive.unlink()
            print("Archive failed (exit " + str(rc) + ", artifact present: " + str(present) + ")", file=sys.stderr)
            print(output, file=sys.stderr, end="" if output.endswith("\n") else "\n")
            return 1
        link_flags = ["/nologo", "/DLL", "/MACHINE:X86", "/NOENTRY", "/INCREMENTAL:NO",
                      "/OPT:NOREF", "/OPT:NOICF", "/MAPINFO:EXPORTS",
                      "/MAP:" + quote(win_path(outdir / "match.map")),
                      "/OUT:" + quote(win_path(outdir / "match.dll")),
                      "/IMPLIB:" + quote(win_path(outdir / "match.lib"))]
        response = outdir / "link.rsp"
        arguments = link_flags + [quote(win_path(outdir / entry["object"])) for entry in manifest["sources"]] + LIBRARIES
        response.write_text("\n".join(arguments) + "\n")
        command = "link @" + quote(win_path(response))
        manifest["link"] = {"flags": link_flags, "libraries": LIBRARIES, "response": "link.rsp",
                             "command": command, "log": "link.log"}
        manifest["status"] = "linking"
        save_manifest(outdir, manifest)
        rc, output = run(command, outdir / "link.log")
        manifest["link"]["returncode"] = rc
        present = all((outdir / name).is_file() and (outdir / name).stat().st_size > 0
                      for name in ("match.dll", "match.map"))
        manifest["link"]["artifacts_present"] = present
        if rc != 0 or not present:
            manifest["status"] = "link_failed"
            save_manifest(outdir, manifest)
            # A linker can leave partial output despite failure; do not expose it
            # as a usable discovery input.
            for name in ("match.dll", "match.map", "match.lib", "match.exp", "match.ilk"):
                path = outdir / name
                if path.exists():
                    path.unlink()
            print("Link failed (exit " + str(rc) + ", artifacts present: " + str(present) + ")", file=sys.stderr)
            print(output, file=sys.stderr, end="" if output.endswith("\n") else "\n")
            return 1
        manifest["status"] = "success"
        manifest["artifact_sha256"] = {name: digest(outdir / name) for name in ("match.dll", "match.map", "protobuf.lib")}
        save_manifest(outdir, manifest)
        print("Built " + str(outdir / "match.dll") + " from " + str(len(sources)) + " real protobuf runtime sources")
        return 0
    except Exception as error:
        manifest["status"] = "failed"
        manifest["error"] = str(error)
        save_manifest(outdir, manifest)
        raise
    finally:
        lock.unlink()


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("outdir")
    parser.add_argument("--profile", choices=PROFILES, required=True)
    parser.add_argument("--jobs", type=int, default=2, help="concurrent compiler processes (1..32; default: 2)")
    args = parser.parse_args()
    if not 1 <= args.jobs <= 32:
        parser.error("--jobs must be between 1 and 32")
    try:
        return build(args)
    except (OSError, ValueError) as error:
        print("protobuf build failed: " + str(error), file=sys.stderr)
        return 1


if __name__ == "__main__":
    sys.exit(main())
