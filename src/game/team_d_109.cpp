// team_d_109: Entity member 0x5e3310 (caller BS::opw3_unknown7278e0): a hostile, untargeted robot within 3
// cells of a trap/device position may trigger it - plays the trigger effect along the path, logs the item
// message and the robot's reaction message, and records the stat when the robot is the player.
// NOTE: class layouts are partial; names are placeholders.
// NOTE: written as if (...) { ...; return true; } else return false; to get the exe's shared failure exit;
// the locals walls/last follow the stack-slot hash order and the divisor is an extern const float.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();								// 0x453b40
	bool operator!=(const Point &p) const;	// 0x409bd0
};
extern Point effectOrigin109_d2e20c;	// NOTE: placeholder name

int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name

class Entity;

class HEntity
{
public:
	int ID;
	HEntity();
	Entity *operator->() const;
	bool isValid() const;	// NOTE: folded with HItem::isValid
};

class HProp
{
public:
	int ID;
	HProp();
};

struct ItemData109	// NOTE: placeholder name and layout
{
	char	pad000[0x190];
	int		effect;		// +0x190
};

class Item
{
public:
	bool unknown457cf0();	// NOTE: placeholder name
	int unknown457fb0();	// NOTE: placeholder name
	ItemData109 *getData109();	// NOTE: placeholder name (folded getter, +0x08)
	string unknown571db0(bool a, bool b);	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	Item *operator->() const;	// NOTE: OpC_Handle::get224
};

struct Trap109	// NOTE: placeholder name and layout
{
	char	pad000[0x174];
	string	name;		// +0x174
	char	pad190[0x19c - 0x190];
	int		effect;		// +0x19c
};

class EffectObj109	// NOTE: placeholder name (object initialized by 0x503b20)
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name
};

class EndObjB
{
public:
	EffectObj109 *unknown508610();	// NOTE: placeholder name
};
extern EndObjB *endObj109_cefc50;	// NOTE: placeholder name

class BS
{
public:
	HEntity getPlayer();
	bool isVisible(const Point &p);
	bool unknown465200(const Point &a, const Point &b);	// NOTE: placeholder name
	bool unknown7170a0(HEntity e, const Point &p, vector<Point> &path, vector<int> &hits, vector<int> &blocks, Point &last, const Point *at, int atMode, bool f1, bool f2);
};
extern BS *world109_cefc4c;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(float percent);
};
extern RNG rng;
extern const float divisor109_ba09e0;	// NOTE: placeholder name (10.0)

class ConsoleA109	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA109 *consoleA109_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs109_cec0b4;		// NOTE: placeholder name
extern CLogMsgs *logMsgs109_cec0c4;		// NOTE: placeholder name
extern int messageLevel109_d28d18;		// NOTE: placeholder name

bool showMessage109(int id, const string *text, const void *b, int c, HEntity d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)

class Stats109	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern Stats109 stats109_d2c658;	// NOTE: placeholder name

class PlayerData109	// NOTE: placeholder name (PlayerData at 0xcf45d8)
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern PlayerData109 playerData109_cf45d8;	// NOTE: placeholder name

class Entity	// NOTE: placeholder layout
{
public:
	char	pad00[4];
	HEntity	self;	// +0x04

	bool isHostileTo(HEntity e);
	int getTarget();
	const Point &getPosition();
	Point unknown5c80f0(const Point &p);	// NOTE: placeholder name
	bool isPlayer();
	int unknown5c7fc0(HEntity e);	// NOTE: placeholder name
	bool unknown5e3310(HEntity e, Trap109 *trap, const Point &pos, HItem item);	// NOTE: placeholder name
};

bool Entity::unknown5e3310(HEntity e, Trap109 *trap, const Point &pos, HItem item)
{
	if (item->unknown457cf0() && isHostileTo(e) && !getTarget() && OpQ1_distanceCeil_40a3f0(getPosition(),pos) <= 3 && world109_cefc4c->unknown465200(getPosition(),pos) && rng.chance(item->unknown457fb0() / divisor109_ba09e0))
	{
		if (world109_cefc4c->isVisible(pos))
			endObj109_cefc50->unknown508610()->init(endObj109_cefc50,trap->effect,pos,effectOrigin109_d2e20c,0,0,0,9,0);
		Point dest = unknown5c80f0(pos);
		if (dest != pos)
		{
			vector<Point> path;
			vector<int> hits;
			vector<int> walls;
			Point last;
			world109_cefc4c->unknown7170a0(self,pos,path,hits,walls,last,0,4,true,true);
			for (unsigned int i = 1; i < path.size() - 1; i++)
			{
				if (world109_cefc4c->isVisible(path[i]))
					endObj109_cefc50->unknown508610()->init(endObj109_cefc50,item->getData109()->effect,path[i],effectOrigin109_d2e20c,0,0,0,walls[i],0);
			}
		}
		if (messageLevel109_d28d18 >= 0)
		{
			do
			{
				if (showMessage109(0x2d5,&item->unknown571db0(false,false),0,0,HEntity(),HProp(),&pos,1))
					consoleA109_cec058->unknown8758d0(false);
				logMsgs109_cec0c4->scrollToEnd();
			} while (0);
		}
		if (world109_cefc4c->getPlayer().isValid())
		{
			do
			{
				if (showMessage109(isPlayer() ? 0x36 : (unknown5c7fc0(world109_cefc4c->getPlayer()) == 2 ? 0x37 : 0x38),&trap->name,0,0,self,HProp(),&pos,0))
					consoleA109_cec058->unknown8758d0(true);
				logMsgs109_cec0b4->scrollToEnd();
			} while (0);
			if (isPlayer())
			{
				stats109_d2c658.add4729d0(0x167,1,"",-1);
				playerData109_cf45d8.unknown77fbc0(0x36);
			}
		}
		return true;
	}
	else
		return false;
}
