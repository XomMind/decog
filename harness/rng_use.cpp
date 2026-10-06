// Not game code: references header-inline members so they get emitted for matching
// until their real callers are decompiled.
#include "../src/util/rng.h"

void harness_rng()
{
	RNG r;
	r.chance(50);
	r.chance(50.0f);
	r.seed();
	r.seed(1);
	r.rangeInt(0,1);
	r.rangeFloat(0,1);
}

#include "../src/util/rngc.h"

void harness_rngc()
{
	RNGC r;
	r.seed(1);
	r.rangeInt(0,1);
}
