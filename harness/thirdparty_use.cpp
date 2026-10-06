// Not game code: references header-inline members so they get emitted for matching
// until their real callers are decompiled.
#include "../src/thirdparty/zfstream.h"

void harness_zfstream()
{
	gzifstream in("a");
	in.is_open();
	gzofstream out("b");
	out.is_open();
}
