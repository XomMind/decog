// team_d_60: Entity member 0x64d660 (detach a power/matter storage part: move its stored contents back or spill them).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct Pos
{
	int x;
	int y;

	Pos(int v);	// NOTE: placeholder name (0x409990: sets both coordinates)
};

class HEntity
{
	int ID;
public:
	HEntity();
};

class HProp
{
	int ID;
public:
	HProp();
};

struct ItemData60	// NOTE: placeholder name and layout
{
	char	pad000[0x1ac];
	bool	unknown1ac;	// NOTE: placeholder name
};

class Item
{
public:
	int unknown457f90();				// NOTE: placeholder name
	int unknown457fb0();				// NOTE: placeholder name (stored amount)
	void unknown44fc60(int value);		// NOTE: placeholder name (sets the stored amount)
	bool unknown457ff0();				// NOTE: placeholder name
	bool unknown457cf0();				// NOTE: placeholder name
	void setActive(bool active);
	ItemData60 *getData();				// NOTE: placeholder name (folded getter 0x9b4350)
	void *getEffect(int type);
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown57a190(HEntity e, int a, int b, int c);	// NOTE: placeholder name
};

class HItem
{
	int ID;
public:
	bool isValid() const;
	Item *operator->() const;
};

class HRecord60	// NOTE: placeholder name
{
	int ID;
};

class Map60	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	HRecord60 unknown71e7c0(const Point &p, int amount, int a);	// NOTE: placeholder name
	bool unknown464350();	// NOTE: placeholder name
};
extern Map60 *world60;	// NOTE: placeholder name (0xcefc4c)

class SpawnTracker60	// NOTE: placeholder name (OpU5_SpawnTracker)
{
public:
	void spawn(int type, int a, string name);
};

struct CompanionRec60	// NOTE: placeholder name and layout (object behind 0xcf4ac8)
{
	char			pad00[0x0c];
	bool			unknown0c;	// NOTE: placeholder name
	char			pad0d[0x30 - 0x0d];
	SpawnTracker60	*tracker;	// +0x30

	void increase48b8c0(int amount);	// NOTE: placeholder name
};
extern CompanionRec60 *companion60_cf4ac8;	// NOTE: placeholder name
extern const int amount60_bbca58;	// NOTE: placeholder name
extern const int cost60_b95fb8;		// NOTE: placeholder name

class PlayerData60	// NOTE: placeholder name (0xcf45d8)
{
public:
	bool hasCompanion();
};
extern PlayerData60 playerData_cf45d8;	// NOTE: placeholder name

class CInfo	// NOTE: placeholder layout
{
public:
	bool isHidden();
	void unknown8b4500(HEntity e, HProp p, HEntity e2, Pos *pos, int a, bool b);
};
extern CInfo *info60_cec118;	// NOTE: placeholder name

int OpX5_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)

class Entity
{
public:
	char	pad00[4];
	HEntity	self;		// +0x04
	char	pad08[0x90 - 0x08];
	int		energy;		// +0x90, NOTE: placeholder name
	int		matter;		// +0x94, NOTE: placeholder name

	int unknown5ca400();			// NOTE: placeholder name (energy capacity)
	int unknown5ca670();			// NOTE: placeholder name (matter capacity)
	Point &getPosition();
	int unknown5cb7f0();			// NOTE: placeholder name
	void unknown45b1b0(int value);	// NOTE: placeholder name
	bool isPlayer();				// 0x5c7600
	int unknown64d660(HItem item, HItem by, bool keep, int extra);	// NOTE: placeholder name
};

int Entity::unknown64d660(HItem item, HItem by, bool keep, int extra)
{
	int found;
	int value;
	int flags;
	if (keep)
	{
		switch (item->unknown457f90())
		{
		case 8:
			found = OpX5_minInt(energy,item->unknown457fb0());
			item->unknown44fc60(found);
			energy -= found;
			break;
		case 9:
			found = OpX5_minInt(matter,item->unknown457fb0());
			item->unknown44fc60(found);
			matter -= found;
			break;
		}
	}
	if (item->unknown457ff0() && item->unknown457cf0())
	{
		switch (item->unknown457f90())
		{
		case 8:
			flags = energy - (unknown5ca400() - item->unknown457fb0()) - extra;
			if (flags > 0)
			{
				if (!keep)
				{
					value = OpX5_minInt(flags,item->unknown457fb0());
					item->unknown44fc60(value);
					energy -= value;
					flags -= value;
				}
				if (flags != 0)
					world60->unknown71e7c0(getPosition(),flags,0);
			}
			break;
		case 9:
			flags = matter - (unknown5ca670() - item->unknown457fb0()) - extra;
			if (flags > 0 && !keep)
			{
				value = OpX5_minInt(flags,item->unknown457fb0());
				item->unknown44fc60(value);
				matter -= value;
				flags -= value;
			}
			break;
		}
	}
	if (!world60->unknown464350())
		unknown45b1b0(unknown5cb7f0());
	if (item->unknown457f90() == 0xd6 && companion60_cf4ac8 && !companion60_cf4ac8->unknown0c && isPlayer())
	{
		companion60_cf4ac8->increase48b8c0(amount60_bbca58);
		if (playerData_cf45d8.hasCompanion())
			companion60_cf4ac8->tracker->spawn(7,0,"");
	}
	item->setActive(false);
	if (item->getData()->unknown1ac || item->getEffect(0x6e))
		item->unknown57dbe0(1,0,3,1);
	else
		item->unknown57a190(self,4,1,by.isValid());
	if (!info60_cec118->isHidden())
		info60_cec118->unknown8b4500(self,HProp(),HEntity(),&Pos(-1),0,false);
	return cost60_b95fb8;
}
