// team_b_05: game-logic helpers (0x500000-0x9affff) matched against COGMIND.exe (Beta 17.1), batch 3.
// NOTE: class layouts are partial; TeamB_* classes and unknownXXXXXX members are placeholder names.
#include <string>
#include <vector>
using namespace std;

//==================================================================
// Overmind: next assault turn
//==================================================================

class RNG { public: int rangeInt(float a, float b); };
extern RNG rng;	// 0xd30908
class OpR3c_GameData { public: int unknown46f4e0(); };	// NOTE: placeholder name
extern OpR3c_GameData opr3c_gameData;	// NOTE: placeholder name (0xd1e860)
class BS { public: int getTurn(); int unknown463ba0(); };	// NOTE: placeholder name
extern BS *teamb_world;	// NOTE: placeholder name (0xcefc4c)
extern const int opr3c_resistTable2[];	// NOTE: placeholder name (0xb989b4)
extern const int opr3c_ranges[][5];	// NOTE: placeholder name (0xb93790)
extern vector<int> opr3c_mapObjects;	// NOTE: placeholder name (0xcf4a04)
class OpR3c_IntGrid { int width; int height; int *data; public: void fill(int value); };	// NOTE: placeholder name (0x9cf020)

class TeamB_Overmind	// NOTE: placeholder name (OpR3c_Overmind in src/op/op_r3c.cpp)
{
public:
	char pad[0x60];
	OpR3c_IntGrid grid;
	char pad6c[4];
	int nextTurn;
	void scheduleNext684c40();
};

void TeamB_Overmind::scheduleNext684c40()	// 0x684c40
{
	nextTurn = teamb_world->getTurn() + ((opr3c_mapObjects[9] ? opr3c_resistTable2[opr3c_mapObjects[9]] : 0) + rng.rangeInt((float)opr3c_ranges[opr3c_gameData.unknown46f4e0()][0],(float)opr3c_ranges[opr3c_gameData.unknown46f4e0()][1])) + teamb_world->unknown463ba0() * 75;
	grid.fill(0);
}

//==================================================================
// remembered target position, name lookups, fine-map timers
//==================================================================

class Entity;
struct TeamB_Val { int v; };	// NOTE: placeholder name
struct TeamB_PropData { int f0; int f4; TeamB_Val f8; int fC; int f10; int f14; };	// NOTE: placeholder layout
struct Point;
class Prop	// NOTE: partial
{
public:
	bool isPassableFor(class HEntity e);
	int getValue9b8f00() throw();	// NOTE: placeholder name (ICF'd getter at +4)
	const Point &getPosition() throw();	// NOTE: placeholder name (0x4184d0)
	TeamB_PropData *getData() throw();	// NOTE: placeholder name (ICF'd getter)
};
class HEntity { public: int ID; HEntity(); bool operator!=(HEntity other) const; void clear() throw(); };
class HProp { public: int ID; HProp() throw(); Prop *operator->() const throw(); void clear() throw(); };
struct Point { int x; int y; Point &operator=(const Point &p) throw(); };
struct Pos { int x; int y; };
class Cell { public: bool unknown45d1e0(); HProp getProp(); };
struct TeamB_CellGrid { Cell **at(Point &p); };
extern TeamB_CellGrid teamb_cells_cfd44c;
class Map { public: int getTurn(); HEntity getPlayer(); };
extern Map *endObjA;	// 0xcefc4c

struct TeamB_TargetMemory
{
	char pad[0x30];
	HEntity entity;
	int groupValue;
	bool flag;
	Point pos;
	HProp prop;
	int turn;
	void setPos873ad0(const Point &p);
};
void TeamB_TargetMemory::setPos873ad0(const Point &p)
{
	pos = p;
	prop.clear();
	if ((*teamb_cells_cfd44c.at(pos))->unknown45d1e0() && !(*teamb_cells_cfd44c.at(pos))->getProp()->isPassableFor(HEntity()))
		prop = (*teamb_cells_cfd44c.at(pos))->getProp();
	entity.clear();
	turn = endObjA->getTurn();
}

struct MapRecord;
extern vector<MapRecord*> teamb_vec_cf4844;
extern vector<MapRecord*> teamb_vec_cf4888;
extern int opw8_caf160;
extern int opw8_caf164;
string teamb_name8f8820(int a, int b);
int teamb_find8f8930(const string &name)
{
	for (unsigned int i = 0; i < teamb_vec_cf4844.size(); i++)
	{
		if (teamb_name8f8820(i,opw8_caf160) == name)
			return i;
	}
	return opw8_caf164;
}
int teamb_find8f89f0(const string &name)
{
	for (unsigned int i = 0; i < teamb_vec_cf4888.size(); i++)
	{
		if (teamb_name8f8820(opw8_caf164,i) == name)
			return i;
	}
	return opw8_caf164;
}

class XConsole { public: virtual ~XConsole(); Pos getPos(); void setPos(int x, int y); void setHidden(bool hidden); };
class Item { public: HEntity getOwner(); };
class HItem { public: int ID; Item *operator->() const throw(); };
struct OpW5_FineTimer;
class CMapFine { public: void removeTimer(OpW5_FineTimer *timer); };
extern CMapFine *teamb_mapFine_cec058;
extern int opx5e_cefc90;
extern unsigned int teamb_tickCount;	// 0xcaed20
struct OpW5_FineTimer
{
	XConsole *console;
	HItem item;
	unsigned int expire;
	bool update8767a0(int y);
};
bool OpW5_FineTimer::update8767a0(int y)
{
	if ((expire && teamb_tickCount >= expire) || !item.operator->() || item->getOwner() != endObjA->getPlayer())
	{
		teamb_mapFine_cec058->removeTimer(this);
		return true;
	}
	console->setHidden(opx5e_cefc90 != 1);
	console->setPos(console->getPos().x,y);
	return false;
}

//==================================================================
// STrapTrigger
//==================================================================


// NOTE: every callee below is declared under a name unique to this file (they are stubs paired by address):
// LTCG treats a stub as throwing if any translation unit declares it without throw(), and that would add an
// EH frame the exe does not have.
struct TeamB_TrapPoint { int x; int y; TeamB_TrapPoint &operator=(const TeamB_TrapPoint &p) throw(); };	// 0x46ca50
class TeamB_TrapProp	// NOTE: placeholder name (Prop)
{
public:
	int trapValue_9b8f00() throw();	// NOTE: placeholder name (ICF'd getter at +4)
	const TeamB_TrapPoint &trapPosition_4184d0() throw();	// NOTE: placeholder name
	TeamB_PropData *trapData_44b020() throw();	// NOTE: placeholder name (ICF'd getter)
};
class TeamB_HTrapProp { public: int ID; TeamB_TrapProp *operator->() const throw(); };	// NOTE: HProp (0x9b64f0)
class TeamB_BattleState	// NOTE: placeholder name for BattleState
{
public:
	TeamB_BattleState() throw();	// 0x453bc0
	virtual ~TeamB_BattleState();
	virtual int getType();
	virtual bool update();
	virtual void unknown3() = 0;
	int prop4;
	int unknown8;
	int unknownC;
};
class STrapTrigger : public TeamB_BattleState
{
public:
	STrapTrigger(TeamB_HTrapProp trap, bool a, bool b, bool c);
	~STrapTrigger();
	virtual int getType();
	virtual bool update();

	int value10;
	TeamB_TrapPoint position;
	int value1c;
	TeamB_Val value20;
	int value24;
	int value28;
	int value2c;
	bool flag30;
	bool flag31;
	bool flag32;
	bool flag33;
};
STrapTrigger::STrapTrigger(TeamB_HTrapProp trap, bool a, bool b, bool c)	// 0x665d70
{
	value10 = trap->trapValue_9b8f00();
	position = trap->trapPosition_4184d0();
	value1c = trap->trapData_44b020()->f4;
	value20 = trap->trapData_44b020()->f8;
	value24 = trap->trapData_44b020()->f10;
	value28 = trap->trapData_44b020()->f14;
	value2c = 0;
	flag30 = false;
	flag31 = a;
	flag32 = b;
	flag33 = c;
}
