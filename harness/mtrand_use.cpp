// Not game code: references header-inline members so they get emitted for matching
// until their real callers are decompiled.
#include "../src/lib/mtrand.h"

void harness_mtrand() {
  MTRand_open r;
  r();
  delete new MTRand_open;
  delete new MTRand_int32;
}
