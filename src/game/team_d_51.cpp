// team_d_51: Cell member 0x66ce10 (trigger the trap in a cell).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;
};

class Entity;

class HEntity
{
	int ID;
public:
	bool isValid() const;
	Entity *operator->() const;
};

class HProp
{
	int ID;
public:
	HProp();
};

class Entity
{
public:
	bool isPlayer();				// 0x5c7600
	bool unknown45aaa0(HEntity e);	// NOTE: placeholder name
	bool isHostileTo(HEntity e);
	const string &getName();		// NOTE: placeholder name (folded getter 0x416f40)
};

struct TrapData51	// NOTE: placeholder name and layout
{
	char	pad000[0x8c];
	int		unknown8c;	// NOTE: placeholder name
	char	pad090[0x140 - 0x90];
	int		type;		// +0x140
};

struct TrapState51	// NOTE: placeholder name and layout
{
	char	pad00[4];
	int		unknown04;	// NOTE: placeholder name
	char	pad08[0x0c - 0x08];
	HEntity	owner;		// +0x0c
	char	pad10[0x1c - 0x10];
	int		unknown1c;	// NOTE: placeholder name
};

class Prop
{
public:
	const string &getName();
	TrapData51 *getData();			// NOTE: placeholder name (folded getter)
	TrapState51 *getState();		// NOTE: placeholder name (folded getter 0x44b020)
	int unknown45c9b0();			// NOTE: placeholder name (folded getter)
	const Point &getPos();			// NOTE: placeholder name (0x4184d0)
};

class TeamB_HTrapProp	// NOTE: HProp under the name team_b_05.cpp uses for the STrapTrigger constructor
{
public:
	int ID;
	Prop *operator->() const;
};

class STrapTrigger	// NOTE: placeholder layout (constructor defined in team_b_05.cpp; it must be linked in, so LTCG proves the new cannot throw)
{
public:
	STrapTrigger(TeamB_HTrapProp trap, bool a, bool b, bool c);
	char pad[0x34];
};

class HRecord51	// NOTE: placeholder name
{
	int ID;
};

class Factory51	// NOTE: placeholder name (OpU5s2_Factory at 0xcefaa8)
{
public:
	HRecord51 createA(STrapTrigger *action);	// NOTE: placeholder name
};
extern Factory51 *factory_cefaa8;	// NOTE: placeholder name

class Map51	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	HEntity getPlayer();
	HRecord51 addRecord(HRecord51 record);	// NOTE: placeholder name (OpU5_Level::addRecord)
};
extern Map51 *world51;	// NOTE: placeholder name (0xcefc4c)

class Stats51	// NOTE: placeholder name (0xd2c658)
{
public:
	vector<int> *counts;	// NOTE: placeholder name

	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
};
extern Stats51 stats51_d2c658;	// NOTE: placeholder name

class PlayerData51	// NOTE: placeholder name (0xcf45d8)
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern PlayerData51 playerData_cf45d8;	// NOTE: placeholder name

class Cell
{
public:
	char				pad00[0x30];
	Point				pos;		// +0x30
	char				pad38[0x44 - 0x38];
	TeamB_HTrapProp		trap;		// +0x44
	HEntity				entity;		// +0x48

	bool unknown45dcf0();			// NOTE: placeholder name
	void removeProp(bool keepTerrain, int cause);	// 0x66c100
	void unknown66ce10(bool announce, bool a, bool b, bool c);	// NOTE: placeholder name
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(const Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

extern int int_d28d18;	// NOTE: placeholder name
extern string log51_d1f3d4;	// NOTE: placeholder name
extern vector<vector<TeamB_HTrapProp> > traps51_d20248;	// NOTE: placeholder name
extern bool removable51_b96a68[];	// NOTE: placeholder name

class ConsoleA	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA *consoleA_cec058;	// NOTE: placeholder name
class CLogMsgs
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern CLogMsgs *logMsgs_cec0b4;	// NOTE: placeholder name
extern CLogMsgs *logMsgs51_cec0c4;	// NOTE: placeholder name
bool logMessageP_5111e0(int id, const string &text, int a, int b, HEntity e, HProp d, const Point &pos, int g);	// NOTE: placeholder name (0x5111e0)
bool logMessagePP_5111e0(int id, const string &text, int a, int b, HProp e, HProp d, const Point &pos, int g);	// NOTE: placeholder name (0x5111e0)
bool OpS1c_unknown4569a0(int type, HProp a, HProp b, TeamB_HTrapProp c, HProp d, int e, int f, int g, HProp h, TeamB_HTrapProp i, HProp j, int k);	// NOTE: placeholder name

void Cell::unknown66ce10(bool announce, bool a, bool b, bool c)
{
	if (unknown45dcf0())
	{
		if (announce && entity.isValid())
			do { if (logMessageP_5111e0(entity->isPlayer() ? 0x21b : (entity->unknown45aaa0(world51->getPlayer()) ? 0x21c : 0x21d),trap->getName(),0,0,entity,HProp(),pos,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
		if (int_d28d18 >= 0)
		{
			string msg = trap->getName() + " triggered";
			if (entity.isValid() && !entity->isPlayer())
				msg += " by " + entity->getName();
			do { if (logMessagePP_5111e0(entity.isValid() && entity->unknown45aaa0(world51->getPlayer()) ? 0x2ce : 0x2cf,msg,0,0,HProp(),HProp(),pos,1)) consoleA_cec058->unknown8758d0(false); logMsgs51_cec0c4->scrollToEnd(); } while (0);
		}
		if (entity.isValid())
		{
			if (entity->isPlayer())
				stats51_d2c658.add4729d0(0x249,1,"",-1);
			else if (entity->isHostileTo(world51->getPlayer()) && trap->getState()->owner.operator->() && trap->getState()->owner->isPlayer())
			{
				stats51_d2c658.add4729d0(0x24f,1,"",-1);
				if ((*stats51_d2c658.counts)[0x24f] == 0x1e)
					playerData_cf45d8.unknown77fbc0(0x9b);
			}
		}
		if (trap->getData()->unknown8c)
			trap->getState()->unknown1c = 1;
		log51_d1f3d4 += '\t';
		OpS1c_unknown4569a0(4,HProp(),HProp(),trap,HProp(),0,0,trap->unknown45c9b0(),HProp(),trap,HProp(),0);
		vector<TeamB_HTrapProp> *list = trap->getData()->type == 0xc ? &traps51_d20248[trap->getState()->unknown04] : NULL;
		world51->addRecord(factory_cefaa8->createA(new STrapTrigger(trap,a,b,c)));
		if (list)
		{
			for (int i = list->size() - 1; i >= 0; i--)
				(*cells_cfd44c.atPoint(list->at(i)->getPos()))->removeProp(false,3);
		}
		else if (trap.operator->() && removable51_b96a68[trap->getData()->type])
			removeProp(false,3);
	}
}
