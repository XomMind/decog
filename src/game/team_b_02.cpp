// team_b_02: Cartographer2DMoveCost callback constructors (GM::initialize allocates these) matched against COGMIND.exe.
// NOTE: written as user-declared empty ctors; class declarations mirror src/op/op_r2_f.cpp and src/op/op_r2_b.cpp.
#include "../pathing/cartographer2d.h"

class EntityMovementCallback : public Cartographer2DMoveCost
{
public:
	EntityMovementCallback();
	bool isPassableAt(int x, int y, Entity *e);
	virtual bool isPassable(int x, int y, void *data);
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost);
};
EntityMovementCallback::EntityMovementCallback() {}

class PathCheckCallback : public Cartographer2DMoveCost
{
public:
	PathCheckCallback();
	virtual bool isPassable(int x, int y, void *data);
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost);
};
PathCheckCallback::PathCheckCallback() {}

class DesirePathCheckCallback : public Cartographer2DMoveCost
{
public:
	DesirePathCheckCallback();
	virtual bool isPassable(int x, int y, void *data);
};
DesirePathCheckCallback::DesirePathCheckCallback() {}

class NearestDamagedMachineCallback : public Cartographer2DMoveCost
{
public:
	NearestDamagedMachineCallback();
	virtual bool isPassable(int x, int y, void *data);
};
NearestDamagedMachineCallback::NearestDamagedMachineCallback() {}

class CaveForcePathCallback : public Cartographer2DMoveCost
{
public:
	CaveForcePathCallback();
	virtual bool isPassable(int x, int y, void *data);
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost);
};
CaveForcePathCallback::CaveForcePathCallback() {}

class CaveinForcedPathCallback : public Cartographer2DMoveCost
{
public:
	CaveinForcedPathCallback();
	virtual bool isPassable(int x, int y, void *data);
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost);
};
CaveinForcedPathCallback::CaveinForcedPathCallback() {}

class SubEntranceForcePathCallback : public Cartographer2DMoveCost
{
public:
	SubEntranceForcePathCallback();
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost);
};
SubEntranceForcePathCallback::SubEntranceForcePathCallback() {}

class SoundPathCallback : public Cartographer2DMoveCost
{
public:
	SoundPathCallback();
	virtual bool isPassable(int x, int y, void *data);
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost);
};
SoundPathCallback::SoundPathCallback() {}
