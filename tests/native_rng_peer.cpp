#include "../src/util/rngc.h"

int peerCrtDraw()
{
	RNGC rng;
	return rng.rangeInt(0, 32766);
}
