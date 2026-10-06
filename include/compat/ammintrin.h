// Stub. VS2010 SP1's <intrin.h> includes <ammintrin.h> (AMD SSE4a/XOP intrinsics),
// but the official "VC++ 2010 SP1 Compiler Update for the Windows SDK 7.1"
// (KB2519277) forgets to ship it. Cogmind never uses those intrinsics, so an empty
// header is codegen-neutral. Replace with the real file from the VS2010 SP1 ISO if needed.
#pragma once
