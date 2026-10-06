// Emit header-inline functions until their game callers are reconstructed.
#include "../src/game/luigiai.h"

void harness_luigiai()
{
	LuigiMachineHacking hacking(10,20);
	LuigiTile tile;
	LuigiAi ai;
	ai.initialize();
	ai.cleanup();
}
