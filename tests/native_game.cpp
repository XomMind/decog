#include <cassert>
#include <cstdio>
#include <string>
#include "../src/game/penetrationrollpool.h"
#include "../src/game/luigiai.h"
#include "../src/game/seedcodec.h"
#include "../src/util/rng.h"

RNG rng;
static int errors = 0;
void logError(std::string location, std::string message)
{
	assert(location == "PenetrationRollPool::peekValue()");
	assert(message == "Peeking too far ahead (25), PENETRATION_ROLL_POOL_SIZE too small?");
	++errors;
}

int main()
{
	rng.seed(17);
	RNG reference;
	reference.seed(17);
	int rolls[125];
	for (int &roll : rolls) roll = reference.rangeInt(1,100);
	PenetrationRollPool pool;
	pool.initialize();
	for (unsigned int i = 0; i < 25; ++i) assert(pool.peekValue(i) == rolls[i]);
	assert(pool.peekValue(25) == 0 && errors == 1);
	for (int i = 0; i < 100; ++i)
	{
		assert(pool.nextValue() == rolls[i]);
		assert(pool.peekValue(24) == rolls[i + 25]);
	}
	std::string text = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-!";
	const std::string original = text;
	rotateSeedText(text);
	assert(text == "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm5678901234-!");
	rotateSeedText(text);
	assert(text == original);
	LuigiMachineHacking hacking(23,45);
	assert(hacking.actionReady == 0 && hacking.detectChance == 23 && hacking.traceProgress == 45 && !hacking.lastHackSuccess);
	LuigiAi ai;
	ai.initialize();
	assert(ai.magic1 == 1689123404 && ai.magic2 == 2035498713);
	assert(ai.actionReady == 0 && ai.mapWidth == 0 && ai.mapHeight == 0);
	assert(ai.locationDepth == -11 && ai.locationMap == 1 && ai.mapCursorIndex == -1);
	ai.mapData = new LuigiTile[2];
	assert(ai.mapData[0].cell == -1 && !ai.mapData[0].doorOpen);
	ai.mapData[0].prop = new LuigiProp();
	ai.mapData[0].entity = new LuigiEntity();
	ai.mapData[0].item = new LuigiItem();
	ai.player = new LuigiEntity();
	ai.machineHacking = new LuigiMachineHacking(1,2);
	ai.cleanup();
	assert(!ai.mapData && !ai.player && !ai.machineHacking);
	ai.cleanup();
	std::puts("Native game PASS: queued penetration rolls, error path, seed transform, LuigiAI lifecycle");
}
