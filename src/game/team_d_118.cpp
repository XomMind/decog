// team_d_118: Entity member 0x642940 (callers EntityAI::takeTurn, Entity::takeDamage, CInventory::attemptEquip and
// many more): drops an item from a robot. Storage items first give back the matter/energy they held, special
// items update trackers and stats, then the item is destroyed (if it cannot exist on the floor or no free cell
// is found nearby) or placed on the ground, bumping a displaced item to a further free cell; the info panel
// is refreshed. Returns the global at 0xb95fc0.
// NOTE: class layouts are partial; names other than Entity are placeholders. Local names follow the
// stack-slot hash order.
#include <string>
#include <vector>
using namespace std;

int OpX5_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)

struct Pos
{
	int x;
	int y;

	Pos(int v);	// 0x409990
};

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
};

class Entity;

class HEntity
{
public:
	int ID;
	HEntity();
	Entity *operator->() const;
};

class HProp
{
public:
	int ID;
	HProp();
};

struct ItemData118	// NOTE: placeholder name and layout
{
	char	pad000[0x1ac];
	bool	unknown1ac;
};

struct ItemEffect;

class Item
{
public:
	int unknown457f90();	// NOTE: placeholder name
	int unknown457fb0();	// NOTE: placeholder name (stored amount)
	void setAmount118(int value);	// NOTE: placeholder name (folded setter, 0x44fc60)
	bool unknown457ff0();	// NOTE: placeholder name
	bool unknown457cf0();	// NOTE: placeholder name
	int getField118();		// NOTE: placeholder name (folded getter, 0x45cb30)
	void unknown57bff0(int id, bool flag);	// NOTE: placeholder name
	int getType();
	ItemData118 *getData118();	// NOTE: placeholder name (folded getter, +0x08)
	ItemEffect *getEffect(int type);
	void unknown57dbe0(bool a, int b, int c, int d);	// NOTE: placeholder name
	string unknown571db0(bool a, bool b);	// NOTE: placeholder name
	void unknown57a0f0(const Point *p, int a, bool b);	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	Item *operator->() const;	// NOTE: OpC_Handle::get224
};

class Cell
{
public:
	vector<HItem> *unknown463950();	// NOTE: placeholder name
};

class CellGrid118	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(Point &p);	// NOTE: folded (OpX5_Array2D<int>::atPoint)
};
extern CellGrid118 cells118_cfd44c;	// NOTE: placeholder name

class BS
{
public:
	bool unknown71bc10(const Point &p, Point &out);	// NOTE: placeholder name
	void unknown464840(HItem item);	// NOTE: placeholder name
};
extern BS *world118_cefc4c;	// NOTE: placeholder name

class SpawnTracker118	// NOTE: placeholder name (OpU5_SpawnTracker)
{
public:
	void spawn(int type, bool flag, string text);
};

struct ItemRec118	// NOTE: placeholder name and layout (OpS1f_ItemRec at *0xcf4ac8)
{
	char			pad00[0xc];
	bool			unknown0c;
	char			pad0d[0x30 - 0xd];
	SpawnTracker118	*tracker;	// +0x30

	void increase48b8c0(int value);	// NOTE: placeholder name
};
extern ItemRec118 *itemRec118_cf4ac8;	// NOTE: placeholder name
extern int value118_bbca5c;	// NOTE: placeholder name
extern int result118_b95fc0;	// NOTE: placeholder name

class PlayerData118	// NOTE: placeholder name (PlayerData at 0xcf45d8)
{
public:
	bool hasCompanion();
};
extern PlayerData118 playerData118_cf45d8;	// NOTE: placeholder name

class CPart118	// NOTE: placeholder name
{
public:
	void setField118(int value);	// NOTE: placeholder name (folded setter Sweep_450570::setField)
};

class CParts
{
public:
	CPart118 *unknown894e70(HItem item);	// NOTE: placeholder name
};
extern CParts *parts118_cec088;	// NOTE: placeholder name

class CInventory
{
public:
	void reopen(int mode, HProp prop);
};
extern CInventory *inventory118_cec08c;	// NOTE: placeholder name

class CInfo
{
public:
	bool isHidden();
	void unknown8b4500(HEntity a, HProp b, HEntity c, Pos *pos, int mode, bool e);	// NOTE: placeholder name
};
extern CInfo *info118_cec118;	// NOTE: placeholder name

class ConsoleA118	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA118 *consoleA118_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs118_cec0b4;	// NOTE: placeholder name

bool showMessage118(int id, const string *text, const void *b, int c, HEntity d, HProp e, const void *at, int flag);	// NOTE: placeholder name (0x5111e0)

class Entity	// NOTE: placeholder layout
{
public:
	char			pad00[4];
	HEntity			self;		// +0x04
	char			pad08[0x30 - 8];
	vector<Point>	positions;	// +0x30
	char			pad40[0x90 - 0x40];
	int				matter;		// +0x90
	int				energy;		// +0x94

	bool isPlayer();
	int unknown5ca400();	// NOTE: placeholder name
	int unknown5ca670();	// NOTE: placeholder name
	void unknown64e7e0(HItem item);	// NOTE: placeholder name (OpS3b_ItemOwner)
	int unknown642940(HItem item, bool quiet, bool b, bool c, int d);	// NOTE: placeholder name
};

int Entity::unknown642940(HItem item, bool quiet, bool b, bool c, int d)
{
	if (c)
	{
		int amount;
		switch (item->unknown457f90())
		{
		case 8:
			amount = OpX5_minInt(matter,item->unknown457fb0());
			item->setAmount118(amount);
			matter -= amount;
			break;
		case 9:
			amount = OpX5_minInt(energy,item->unknown457fb0());
			item->setAmount118(amount);
			energy -= amount;
			break;
		}
	}
	else if (b && item->unknown457ff0() && item->unknown457cf0())
	{
		int n;
		int excess;
		switch (item->unknown457f90())
		{
		case 8:
			excess = matter - (unknown5ca400() - item->unknown457fb0());
			if (excess > 0)
			{
				n = OpX5_minInt(excess,item->unknown457fb0());
				item->setAmount118(n);
				matter -= n;
			}
			break;
		case 9:
			excess = energy - (unknown5ca670() - item->unknown457fb0());
			if (excess > 0)
			{
				n = OpX5_minInt(excess,item->unknown457fb0());
				item->setAmount118(n);
				energy -= n;
			}
			break;
		}
	}
	if (item->unknown457f90() == 0xd6 && itemRec118_cf4ac8 && !itemRec118_cf4ac8->unknown0c && isPlayer())
	{
		itemRec118_cf4ac8->increase48b8c0(value118_bbca5c);
		if (playerData118_cf45d8.hasCompanion())
			itemRec118_cf4ac8->tracker->spawn(8,false,"");
	}
	if (item->unknown457ff0() && item->getField118() && isPlayer())
		item->unknown57bff0(0x83,true);
	if (item->unknown457cf0())
		unknown64e7e0(item);
	bool x = item->getType() != 4;
	Point point;
	if (x && (item->getData118()->unknown1ac || item->getEffect(0x6e)))
		item->unknown57dbe0(quiet,0,3,1);
	else if (!world118_cefc4c->unknown71bc10(positions[0],point))
	{
		if (isPlayer())
		{
			do
			{
				if (showMessage118(0x11,&item->unknown571db0(false,false),0,0,self,HProp(),0,0))
					consoleA118_cec058->unknown8758d0(true);
				logMsgs118_cec0b4->scrollToEnd();
			} while (0);
		}
		item->unknown57dbe0(quiet,0,1,1);
	}
	else
	{
		world118_cefc4c->unknown464840(item);
		if (d && x && isPlayer())
		{
			CPart118 *part = parts118_cec088->unknown894e70(item);
			if (part)
				part->setField118(2);
		}
		item->unknown57a0f0(&point,1,quiet);
		if (quiet && !b)
			inventory118_cec08c->reopen(4,HProp());
		if ((*cells118_cfd44c.atPoint(point))->unknown463950()->size() > 1)
		{
			HItem other = (*(*cells118_cfd44c.atPoint(point))->unknown463950())[1];
			if (!world118_cefc4c->unknown71bc10(point,point))
			{
				if (isPlayer())
				{
					do
					{
						if (showMessage118(0x11,&other->unknown571db0(false,false),0,0,self,HProp(),0,0))
							consoleA118_cec058->unknown8758d0(true);
						logMsgs118_cec0b4->scrollToEnd();
					} while (0);
				}
				other->unknown57dbe0(quiet,0,1,1);
			}
			else
			{
				world118_cefc4c->unknown464840(item);
				other->unknown57a0f0(&point,1,false);
			}
		}
	}
	if (!info118_cec118->isHidden())
		info118_cec118->unknown8b4500(self,HProp(),HEntity(),&Pos(-1),0,false);
	return result118_b95fc0;
}
