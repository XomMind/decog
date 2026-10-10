// Win32 profiler for a privately staged child. No injected code or register writes.
#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

static unsigned __int64 ticks(const FILETIME &value) {
    return ((unsigned __int64)value.dwHighDateTime << 32) | value.dwLowDateTime;
}
static std::string quote(const char *value) {
    std::string result = "\"";
    unsigned slashes = 0;
    for (const char *p = value; ; ++p) {
        if (*p == '\\') { ++slashes; continue; }
        if (!*p || *p == '"') result.append(slashes * 2, '\\');
        else result.append(slashes, '\\');
        slashes = 0;
        if (!*p) break;
        if (*p == '"') result += '\\';
        result += *p;
    }
    return result + '"';
}
static void modules(DWORD pid, FILE *output) {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
    if (snapshot == INVALID_HANDLE_VALUE) return;
    MODULEENTRY32 entry = {sizeof(entry)};
    for (BOOL ok = Module32First(snapshot, &entry); ok; ok = Module32Next(snapshot, &entry))
        fprintf(output, "module,%08lx,%lu,%s\n", (DWORD)entry.modBaseAddr,
                entry.modBaseSize, entry.szModule);
    CloseHandle(snapshot);
}
int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "runtime_sample.exe EXE OUTPUT.csv DURATION_MS INTERVAL_MS [game args...]\n");
        return 2;
    }
    const DWORD duration = strtoul(argv[3], NULL, 10), interval = strtoul(argv[4], NULL, 10);
    if (!duration || !interval) return 2;
    FILE *output = fopen(argv[2], "wb");
    if (!output) { perror("profile output"); return 2; }
    std::string command = quote(argv[1]);
    for (int i = 5; i < argc; ++i) command += " " + quote(argv[i]);
    STARTUPINFO startup = {sizeof(startup)};
    PROCESS_INFORMATION process = {0};
    LARGE_INTEGER frequency, start, now;
    if (!QueryPerformanceFrequency(&frequency) || !QueryPerformanceCounter(&start)) {
        fclose(output); return 2;
    }
    if (!CreateProcessA(argv[1], &command[0], NULL, NULL, FALSE, CREATE_SUSPENDED,
                        NULL, NULL, &startup, &process)) {
        fprintf(stderr, "CreateProcess failed: %lu\n", GetLastError());
        fclose(output); return 2;
    }
    char actual[MAX_PATH] = {0}; DWORD length = sizeof(actual);
    if (!QueryFullProcessImageNameA(process.hProcess, 0, actual, &length)) {
        fprintf(stderr, "Cannot identify owned executable: %lu\n", GetLastError());
        TerminateProcess(process.hProcess, 2); WaitForSingleObject(process.hProcess, 5000);
        CloseHandle(process.hThread); CloseHandle(process.hProcess); fclose(output); return 2;
    }
    fprintf(output, "owned,%lu,%s\n", process.dwProcessId, actual);
    fprintf(output, "interval_ms,%lu\n", interval);
    if (ResumeThread(process.hThread) == (DWORD)-1) {
        TerminateProcess(process.hProcess, 2); WaitForSingleObject(process.hProcess, 5000);
        CloseHandle(process.hThread); CloseHandle(process.hProcess); fclose(output); return 2;
    }
    DWORD samples = 0, failures = 0, status = STILL_ACTIVE;
    unsigned __int64 elapsed = 0, next = 0, overhead = 0;
    bool deadline = false;
    while (WaitForSingleObject(process.hProcess, 0) == WAIT_TIMEOUT) {
        QueryPerformanceCounter(&now);
        elapsed = (now.QuadPart - start.QuadPart) * 1000 / frequency.QuadPart;
        if (elapsed >= duration) { deadline = true; break; }
        if (elapsed < next) { Sleep((DWORD)(next - elapsed)); continue; }
        next = elapsed + interval;
        LARGE_INTEGER before, after; QueryPerformanceCounter(&before);
        if (SuspendThread(process.hThread) == (DWORD)-1) { ++failures; continue; }
        CONTEXT context = {0}; context.ContextFlags = CONTEXT_CONTROL;
        const BOOL got = GetThreadContext(process.hThread, &context);
        DWORD frames[12] = {0}; unsigned count = 0;
        if (got) {
            DWORD frame = context.Ebp, words[1024]; SIZE_T bytes = 0;
            const DWORD start = frame, limit = 0x1000 - (frame & 0xfff);
            if (frame >= context.Esp && frame - context.Esp < 0x100000
                && ReadProcessMemory(process.hProcess, (void*)start, words, limit, &bytes)) {
                // One page-bounded read avoids a Wine server roundtrip per caller.
                while (frame >= start && frame - start + 8 <= bytes
                       && count < sizeof(frames) / sizeof(frames[0])) {
                    const DWORD offset = (frame - start) / sizeof(DWORD);
                    frames[count++] = words[offset + 1];
                    if (words[offset] <= frame || (words[offset] & 3)) break;
                    frame = words[offset];
                }
            }
        }
        if (ResumeThread(process.hThread) == (DWORD)-1) {
            fprintf(stderr, "Cannot resume owned main thread: %lu\n", GetLastError());
            TerminateProcess(process.hProcess, 1);
            WaitForSingleObject(process.hProcess, 5000);
            failures++; break;
        }
        QueryPerformanceCounter(&after); overhead += after.QuadPart - before.QuadPart;
        if (!got) { ++failures; continue; }
        fprintf(output, "sample,%I64u,%08lx,%08lx,%08lx", elapsed, context.Eip,
                context.Esp, context.Ebp);
        for (unsigned i = 0; i < count; ++i) fprintf(output, ",%08lx", frames[i]);
        fputc('\n', output); ++samples;
    }
    modules(process.dwProcessId, output);
    FILETIME created, exited, kernel, user;
    if (GetProcessTimes(process.hProcess, &created, &exited, &kernel, &user))
        fprintf(output, "cpu_100ns,%I64u,%I64u\n", ticks(user), ticks(kernel));
    fprintf(output, "sampling_overhead_us,%I64u\n", overhead * 1000000 / frequency.QuadPart);
    fprintf(output, "summary,%I64u,%lu,%lu,%d\n", elapsed, samples, failures, deadline);
    if (deadline) {
        // Bounded profiling owns this process handle, never a process-name lookup.
        TerminateProcess(process.hProcess, 0); WaitForSingleObject(process.hProcess, 5000);
    }
    GetExitCodeProcess(process.hProcess, &status);
    fprintf(output, "exit,%lu\n", status);
    fclose(output); CloseHandle(process.hThread); CloseHandle(process.hProcess);
    printf("Owned pid=%lu elapsed=%I64u ms samples=%lu failures=%lu deadline=%d exit=%lu\n",
           process.dwProcessId, elapsed, samples, failures, deadline, status);
    return failures || (!deadline && status) ? 1 : 0;
}
