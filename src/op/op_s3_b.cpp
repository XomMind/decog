// op_s3_b: Entity helpers and movement callbacks in 0x633000-0x653000 (COGMIND.exe Beta 17.1).
// NOTE: class layouts are partial; names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
#include "../game/penetrationrollpool.h"
using namespace std;

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(const Point &p) throw();	// 0x46ca50
	Point &operator=(const Point &p) throw();	// 0x46ca50
	bool operator!=(const Point &p) const;	// 0x409bd0
	Point operator+(const Point &other) const;	// 0x409b60
};

class OpR5h_Grid	// NOTE: placeholder name (Array2D)
{
public:
	int width;
	int height;

	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
};

extern OpR5h_Grid opS3b_cells;	// NOTE: placeholder name (0xcfd44c)

struct OpS3b_MapData	// NOTE: placeholder name
{
	char pad00[0x164];
	bool unknown164;	// NOTE: placeholder name
};

void OpR3_f6513f0(Point &from, Point &to, vector<Point> &out);	// NOTE: placeholder name

void OpS3b_f651590(OpS3b_MapData *data, Point &from, Point &to, vector<Point> &fromOut, vector<Point> &toOut)	// NOTE: placeholder name
{
	fromOut.push_back(from);
	toOut.push_back(to);
	if (!data->unknown164)
	{
		return;
	}
	vector<Point> offsets;
	OpR3_f6513f0(from,to,offsets);
	for (unsigned int i = 0; i < offsets.size(); i++)
	{
		fromOut.push_back(from + offsets[i]);
		if (!opS3b_cells.contains(fromOut.back()))
		{
			fromOut.pop_back();
		}
		else
		{
			toOut.push_back(to + offsets[i]);
		}
	}
}

struct OpS3b_Line	// NOTE: placeholder name
{
	Point a;
	Point b;

	OpS3b_Line(const Point &a_, const Point &b_);	// 0x40b160
};

template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name

class OpS3b_LineTracker	// NOTE: placeholder name
{
public:
	char pad00[0x20];
	Point end;				// NOTE: placeholder name
	char pad28[0x2c - 0x28];
	vector<OpS3b_Line> lines;	// NOTE: placeholder name

	void addPoint(Point &p);	// NOTE: placeholder name (0x64faa0)
};

void OpS3b_LineTracker::addPoint(Point &p)
{
	if (!lines.empty())
	{
		if (lines.back().a != p)
		{
			lines.push_back(OpS3b_Line(p,end));
		}
		p = lines.front().a;
		end = lines.front().b;
		OpQ5_eraseAt(lines,0);
	}
}

struct OpS3b_EffectData	// NOTE: placeholder name
{
	char pad00[0x62];
	bool unknown62;	// NOTE: placeholder name
};

struct OpS3b_Effect	// NOTE: placeholder name
{
	OpS3b_EffectData *data;

	OpS3b_EffectData *getData();	// NOTE: placeholder name (0x9fcd80)
};

class OpS3b_EffectList	// NOTE: placeholder name
{
public:
	~OpS3b_EffectList();	// 0x4563c0

	vector<OpS3b_Effect*> *getList();	// NOTE: placeholder name (0x9c0790)
};

template <class T> void OpS3b_eraseAtIndex(vector<T> *v, unsigned int *i);	// NOTE: placeholder name (0x9de640, steps i back)

class OpS3b_Item	// NOTE: placeholder name
{
public:
	char pad00[0xec];
	OpS3b_EffectList *effects;	// NOTE: placeholder name

	void removeEffectsA(bool onlyInactive);	// NOTE: placeholder name (0x639730)
};

void OpS3b_Item::removeEffectsA(bool onlyInactive)
{
	if (effects)
	{
		if (onlyInactive)
		{
			vector<OpS3b_Effect*> *list = effects->getList();
			for (unsigned int i = 0; i < list->size(); i++)
			{
				if (!(*list)[i]->getData()->unknown62)
				{
					OpS3b_eraseAtIndex(list,&i);
				}
			}
			if (!list->empty())
			{
				return;
			}
		}
		delete effects;
		effects = NULL;
	}
}

class OpS3b_Entity;
class OpS3b_Prop;

class OpS3b_HEntity	// NOTE: placeholder layout
{
	int ID;
public:
	OpS3b_HEntity() throw();	// 0x9b6590
	bool operator==(OpS3b_HEntity other) const;	// 0x9b78e0
};

class OpS3b_HProp	// NOTE: placeholder layout
{
	int ID;
public:
	OpS3b_HProp() throw();	// 0x9b6590
};

struct OpS3b_Pair	// NOTE: placeholder name
{
	OpS3b_Pair(int value);	// 0x409990
	int x;
	int y;
};

struct OpS3b_ItemData	// NOTE: placeholder name
{
	char pad00[0x1a0];
	int unknown1a0;	// NOTE: placeholder name
};

class OpS3b_Item2	// NOTE: placeholder name
{
public:
	void setActive(bool active);	// 0x5791a0
	int unknown457f90();	// NOTE: placeholder name
	OpS3b_ItemData *getData();	// NOTE: placeholder name (folded getter 0x9b4350)
};

class OpS3b_HItem	// NOTE: placeholder layout
{
	int ID;
public:
	OpS3b_Item2 *operator->() const throw();	// 0x9b65b0
};

class OpS3b_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	OpS3b_HEntity getPlayer();	// NOTE: placeholder name (0x4630f0)
};

class OpS3b_Console	// NOTE: placeholder name (0xcec118)
{
public:
	bool isHidden();	// 0x4175f0
	void unknown8b4500(OpS3b_HEntity entity, OpS3b_HProp a, OpS3b_HProp b, const OpS3b_Pair &c, int d, int e);	// NOTE: placeholder name
};

class OpS3b_ItemUI	// NOTE: placeholder name (0xcec11c)
{
public:
	void unknown4aee10(OpS3b_HItem item);	// NOTE: placeholder name
};

class OpS3b_MapView	// NOTE: placeholder name (0xcec054)
{
public:
	void updatePredictedExplosion();	// 0x808320
	void unknown8142d0(int a, int b);	// NOTE: placeholder name
};

extern OpS3b_World *opS3b_world;	// NOTE: placeholder name (0xcefc4c)
extern OpS3b_Console *opS3b_console;	// NOTE: placeholder name (0xcec118)
extern OpS3b_ItemUI *opS3b_itemUI;	// NOTE: placeholder name (0xcec11c)
extern OpS3b_MapView *opS3b_mapView;	// NOTE: placeholder name (0xcec054)

class OpS3b_ItemOwner	// NOTE: placeholder name
{
public:
	char pad00[4];
	OpS3b_HEntity entity;	// NOTE: placeholder name

	void unknown64e7e0(OpS3b_HItem item);	// NOTE: placeholder name (0x64e7e0)
};

void OpS3b_ItemOwner::unknown64e7e0(OpS3b_HItem item)
{
	item->setActive(false);
	if (opS3b_world->getPlayer() == entity)
	{
		if (!opS3b_console->isHidden())
		{
			opS3b_console->unknown8b4500(entity,OpS3b_HProp(),OpS3b_HProp(),OpS3b_Pair(-1),0,0);
		}
		opS3b_itemUI->unknown4aee10(item);
		if (item->getData()->unknown1a0)
		{
			opS3b_mapView->updatePredictedExplosion();
		}
		switch (item->unknown457f90())
		{
		case 0x17:
			opS3b_mapView->unknown8142d0(0x10,1);
			break;
		case 0xd2:
			opS3b_mapView->unknown8142d0(0x11,1);
			break;
		}
	}
}

//==================================================================
// Entity
//==================================================================

class OpS3b_Item3;

struct OpS3b_ItemInfo	// NOTE: placeholder name
{
	char pad00[0x70];
	int unknown70;	// NOTE: placeholder name
};

class OpS3b_Item3	// NOTE: placeholder name
{
public:
	OpS3b_ItemInfo *getData();	// NOTE: placeholder name (folded getter 0x9b4350)
	void *getEffect(int type);	// NOTE: placeholder name (0x457b70)
	int getField9b6bf0();	// NOTE: placeholder name (folded getter)
	void unknown458310(int amount);	// NOTE: placeholder name
	void setActive(bool active);	// 0x5791a0
	void unknown57a0f0(const Point &p, bool a, bool b);	// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class OpS3b_HItem3	// NOTE: placeholder layout
{
	int ID;
public:
	OpS3b_Item3 *operator->() const throw();	// 0x9b65b0
};

class Entity;

class OpS3b_World3	// NOTE: placeholder name (0xcefc4c)
{
public:
	bool unknown71bc10(const Point &p, Point &out);	// NOTE: placeholder name
};

extern OpS3b_World3 *opS3b_world3;	// NOTE: placeholder name (0xcefc4c)
extern bool opS3b_itemTable_b9651c[];	// NOTE: placeholder name (0xb9651c)
extern int opS3b_cf462c;	// NOTE: placeholder name (0xcf462c)
extern RNG rng;

struct OpS3b_EntityData	// NOTE: placeholder name
{
	char pad00[0x1dc];
	int unknown1dc;	// NOTE: placeholder name
};

struct OpS3b_Actor	// NOTE: placeholder name
{
	char pad00[0x174];
	string name;
};

bool OpS3b_logMessage(int id, const string *a, const string *b, int c, OpS3b_HEntity d, OpS3b_HEntity e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)

class OpS3b_MsgConsole	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};

class OpS3b_LogMsgs	// NOTE: placeholder name (CLogMsgs)
{
public:
	void scrollToEnd();	// 0x7b4f10
};

extern OpS3b_MsgConsole *opS3b_msgConsole;	// NOTE: placeholder name (0xcec058)
extern OpS3b_LogMsgs *opS3b_logMsgs;	// NOTE: placeholder name (0xcec0b4)
extern OpS3b_LogMsgs *opS3b_logMsgs2;	// NOTE: placeholder name (0xcec0c4)
extern PenetrationRollPool opS3b_rollPool;	// NOTE: placeholder name (0xd2c41c)
extern int opS3b_debugLevel;	// NOTE: placeholder name (0xd28d18)

class Entity
{
public:
	char pad00[8];
	OpS3b_EntityData *data;	// NOTE: placeholder name
	char pad0c[0xc0 - 0xc];
	bool unknownC0;	// NOTE: placeholder name
	char padC1[0x134 - 0xc1];
	vector<OpS3b_HItem3> items;	// NOTE: placeholder name

	bool isPlayer();	// 0x5c7600
	Point unknown45a4c0();	// NOTE: placeholder name
	const string *unknown416f40();	// NOTE: placeholder name (folded getter)
	void unknown6335e0();	// NOTE: placeholder name (0x6335e0)
	bool unknown637da0(int a, int b, OpS3b_Actor *actor, const Point *at);	// NOTE: placeholder name (0x637da0)
};

void Entity::unknown6335e0()
{
	Point p;
	while (!items.empty())
	{
		if (opS3b_itemTable_b9651c[items.front()->getData()->unknown70]
			&& !items.front()->getEffect(0x6d)
			&& !unknownC0
			&& opS3b_world3->unknown71bc10(unknown45a4c0(),p)
			&& (opS3b_cf462c != 2 || isPlayer()))
		{
			items.front()->unknown458310(items.front()->getField9b6bf0() * rng.rangeInt(25.0f,75.0f) / 100);
			items.front()->setActive(false);
			items.front()->unknown57a0f0(p,true,false);
		}
		else
		{
			items.front()->unknown57dbe0(0,1,1,1);
		}
	}
}

bool Entity::unknown637da0(int a, int b, OpS3b_Actor *actor, const Point *at)
{
	if (data->unknown1dc == -1)
	{
		return false;
	}
	if (b == -1 || (a == -1 ? opS3b_rollPool.nextValue() : opS3b_rollPool.peekValue(a)) <= b)
	{
		if (a == -1)
		{
			do
			{
				if (OpS3b_logMessage(0x195 + !!isPlayer(),&actor->name,unknown416f40(),0,OpS3b_HEntity(),OpS3b_HEntity(),at,0))
				{
					opS3b_msgConsole->unknown8758d0(true);
				}
				opS3b_logMsgs->scrollToEnd();
			} while (0);
			if (opS3b_debugLevel >= 0)
			{
				do
				{
					if (OpS3b_logMessage(0x2d3 + !!isPlayer(),&actor->name,unknown416f40(),0,OpS3b_HEntity(),OpS3b_HEntity(),at,1))
					{
						opS3b_msgConsole->unknown8758d0(false);
					}
					opS3b_logMsgs2->scrollToEnd();
				} while (0);
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
