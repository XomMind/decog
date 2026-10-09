// team_d_30: Entity members (0x603280 part breakage, 0x63c340 attack-move action).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p) throw();	// 0x46ca50
};

struct D30PathStep	// NOTE: placeholder name; element type of the retail action path vector (ctor 0x9b8e80, ~vector 0x9b50a0). File-private so the template instances pair only here (a shared ~vector<D30PathStep> pairs elsewhere)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

class Entity;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	bool operator==(HEntity other) const;
	Entity *operator->() const;
};

class HProp
{
	int ID;
public:
	HProp();
};

struct ItemData30	// NOTE: placeholder name and layout
{
	char	pad000[0x9c];
	int		unknown9c;	// NOTE: placeholder name (breakage chance)
};

class Item
{
public:
	bool unknown457d10();			// NOTE: placeholder name
	ItemData30 *getData();			// NOTE: placeholder name (folded getter 0x9b4350)
	int unknown457f90();			// NOTE: placeholder name
	int getType();
	bool unknown457d70();			// NOTE: placeholder name
	int turnsLeft();				// NOTE: placeholder name (0x577ad0)
	string unknown571db0(int a, int b);	// NOTE: placeholder name (item name)
	int unknown457880();			// NOTE: placeholder name (folded getter)
	int unknown5788e0();			// NOTE: placeholder name
	int unknown5789c0();			// NOTE: placeholder name
	void setBroken(int a, bool b);
};

class HItem
{
	int	ID;
public:
	Item *operator->() const;
	bool isValid() const;
	bool isNull() const;
};

class Entity
{
public:
	char pad00[4];
	HEntity self;
	char pad08[0x134 - 0x08];
	vector<HItem> parts;	// +0x134, NOTE: placeholder name

	int getFaction();		// 0x45a2c0
	bool isPlayer();		// 0x5c7600
	bool unknown603280(HItem item);	// NOTE: placeholder name
	bool unknown63c340(HEntity target);	// NOTE: placeholder name

	int getTarget();		// 0x45a760
	bool isHostileTo(HEntity e);
	bool unknown5c8820(HEntity e);	// NOTE: placeholder name
	int unknown5cad50();			// NOTE: placeholder name
	HItem unknown5d2380(int slot);	// NOTE: placeholder name
	HItem unknown5d5d40();			// NOTE: placeholder name
	int unknown45a8d0();			// NOTE: placeholder name
	int unknown45a920();			// NOTE: placeholder name
	Point unknown45a4c0();			// NOTE: placeholder name
	Point unknown5c80f0(const Point &p);	// NOTE: placeholder name
	bool unknown45aaa0(HEntity e);	// NOTE: placeholder name
	const string &name416f40();		// NOTE: placeholder name (folded getter 0x416f40, not Entity::getName 0x45a280)
};

class Map30	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	HEntity getEntity671();	// NOTE: placeholder name
	HEntity getPlayer();
	class HRecord30 addRecord(class HRecord30 record);	// NOTE: placeholder name (OpU5_Level::addRecord)
};
extern Map30 *world30;	// NOTE: placeholder name (0xcefc4c)

class RNG
{
public:
	bool chance(float percent);
};
extern RNG rng;

class RolledValues30	// NOTE: placeholder name (OpW5_RolledValues, object at 0xcefb48)
{
public:
	bool say(int ID, bool force, string name);
};
extern RolledValues30 *rolledValues_cefb48;	// NOTE: placeholder name
extern int int_cf462c;	// NOTE: placeholder name

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
bool logMessageS_5111e0(int id, const string &text, int a, int b, HEntity e, HProp d, int f, int g);	// NOTE: placeholder name (0x5111e0)
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name

class HRecord30	// NOTE: placeholder name
{
	int ID;
public:
};

class Action64fb40	// NOTE: placeholder name (0x7c-byte object, constructor 0x64fb40)
{
public:
	Action64fb40(HEntity e, int a, const Point &target, Point *origin, int *delay, vector<D30PathStep> *path, int b, HProp prop);
	char pad[0x7c];
};

class Factory30	// NOTE: placeholder name (OpU5s2_Factory at 0xcefaa8)
{
public:
	HRecord30 createA(Action64fb40 *action);	// NOTE: placeholder name
};
extern Factory30 *factory_cefaa8;	// NOTE: placeholder name

class Stats30	// NOTE: placeholder name (0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
	int unknown472c70(unsigned int id);	// NOTE: placeholder name
};
extern Stats30 stats_d2c658;	// NOTE: placeholder name

class PlayerData30	// NOTE: placeholder name (0xcf45d8)
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern PlayerData30 playerData_cf45d8;	// NOTE: placeholder name

class TurnQueue30	// NOTE: placeholder name (0xd225a0)
{
public:
	void unknown672b80(HEntity e, int delay);	// NOTE: placeholder name
};
extern TurnQueue30 turnQueue_d225a0;	// NOTE: placeholder name

extern int int_cefb38;	// NOTE: placeholder name
extern bool flag_cefc8b;	// NOTE: placeholder name
extern Point point_d2e20c;	// NOTE: placeholder name
bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (in range)

bool Entity::unknown603280(HItem item)
{
	if (item->unknown457d10())
		return false;
	if (item->getData()->unknown9c && (getFaction() == 0 || getFaction() == 0x30) && rng.chance((float)item->getData()->unknown9c))
	{
		for (int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown457f90() == 0xa1 && parts[i]->getType() <= 3 && parts[i]->unknown457d70() && parts[i]->turnsLeft() < 0)
				return false;
		}
		do { if (logMessageS_5111e0(isPlayer() ? 0x183 : 0x184,item->unknown571db0(0,0),0,0,self,HProp(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
		item->setBroken(-1,true);
		if (isPlayer())
			opR1d_4541b0(0x5f,0,0);
		if (int_cf462c == 7 && self == world30->getEntity671() && rolledValues_cefb48)
			rolledValues_cefb48->say(0x23,false,item->unknown571db0(0,0));
		return true;
	}
	return false;
}

bool Entity::unknown63c340(HEntity target)
{
	if (getTarget() == 0 && isHostileTo(target) && unknown5c8820(target) && ((unknown5cad50() == 2 && int_cefb38 == 3) || unknown5d2380(0x5b).isValid()))
	{
		HItem item = unknown5d5d40();
		if (item.isNull())
			return false;
		else if (!OpT8b_Fn9daf80(0x1a,item->unknown457880(),0x1c))
			return false;
		if (item->unknown5788e0() > unknown45a8d0() || item->unknown5789c0() > unknown45a920())
			return false;
		flag_cefc8b = true;
		int t;
		vector<D30PathStep> path;
		world30->addRecord(factory_cefaa8->createA(new Action64fb40(self,0,target->unknown5c80f0(unknown45a4c0()),&point_d2e20c,&t,&path,0,HProp())));
		do { if (logMessageS_5111e0(isPlayer() ? 0xae : (unknown45aaa0(world30->getPlayer()) ? 0xaf : 0xb0),target->name416f40(),0,0,self,HProp(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
		if (isPlayer())
		{
			stats_d2c658.add4729d0(0x1b0,1,"",-1);
			if (stats_d2c658.unknown472c70(0x1b0) == 0xf)
				playerData_cf45d8.unknown77fbc0(0xa0);
		}
		turnQueue_d225a0.unknown672b80(self,t);
		return true;
	}
	return false;
}
