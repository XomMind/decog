#ifndef LUIGIAI_H
#define LUIGIAI_H

#include <stddef.h>
#include <new>

// Layout names cross-checked against ../refs/luigiai/luigiai.h (Beta 13).
// Initialization and cleanup reconstructed from Beta 17.1 at 0x434be0-0x434e4c.
// ID and enum fields use int until their complete game types are recovered.
extern const int NO_CELL;

struct LuigiMachineHacking
{
	int actionReady;
	int detectChance;
	int traceProgress;
	bool lastHackSuccess;

	LuigiMachineHacking(int detectChance_, int traceProgress_)
		: actionReady(0)
		, detectChance(detectChance_)
		, traceProgress(traceProgress_)
		, lastHackSuccess(false)
	{};
};

struct LuigiProp
{
	int ID;
	bool interactivePiece;
};

struct LuigiItem
{
	int ID;
	int integrity;
	bool equipped;
};

struct LuigiEntity
{
	int ID;
	int integrity;
	int relation;
	int activeState;
	int exposure;
	int energy;
	int matter;
	int heat;
	int systemCorruption;
	int speed;
	int inventorySize;
	LuigiItem *inventory;
};

struct LuigiTile
{
	int lastAction;
	int lastFov;
	int cell;
	bool doorOpen;
	LuigiProp *prop;
	LuigiEntity *entity;
	LuigiItem *item;

	LuigiTile()
		: lastAction(0)
		, lastFov(0)
		, cell(NO_CELL)
		, doorOpen(false)
		, prop(NULL)
		, entity(NULL)
		, item(NULL)
	{};

	~LuigiTile()
	{
		delete prop;
		delete entity;
		delete item;
	};
};

struct LuigiAi
{
	int magic1;
	int magic2;
	int actionReady;
	int mapWidth;
	int mapHeight;
	int locationDepth;
	int locationMap;
	LuigiTile *mapData;
	int mapCursorIndex;
	LuigiEntity *player;
	LuigiMachineHacking *machineHacking;

	void initialize()
	{
		magic1 = 1689123404;
		magic2 = 2035498713;
		actionReady = 0;
		mapWidth = 0;
		mapHeight = 0;
		locationDepth = -11;
		locationMap = 1; // MAP_JUNKYARD
		mapData = NULL;
		mapCursorIndex = -1;
		player = NULL;
		machineHacking = NULL;
	};

	void cleanup()
	{
		delete [] mapData;	mapData = NULL;
		delete player;		player = NULL;
		delete machineHacking;	machineHacking = NULL;
	};
};

#endif
