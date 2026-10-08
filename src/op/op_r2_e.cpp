// op_r2_e: EntityAI (0x5b0000-0x600000), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// NOTE: placeholder name (0xd30908)

//==================================================================
// shared declarations
//==================================================================

struct Point
{
	int x;
	int y;

	Point();
	Point(int v);
	Point(int x_, int y_);
	Point(const Point &p);
	Point(const Point &p, int dx, int dy);
	Point &operator=(const Point &p);
	bool operator!=(const Point &p) const;
	void set(int x_, int y_);	// 0x40a010
	bool operator==(const Point &p) const;	// 0x409b90
};

struct OpR2_Area;

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(int x, int y);
	T &operator()(const Point &p);
	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
	void randomPos(Point &p);	// NOTE: placeholder name (0x9cf0c0)
	void getArea(const Point &center, int radius, OpR2_Area &area);	// NOTE: placeholder name (0x9b4430)
};

class Entity;
class OpR2_AI57f6a0;
class Item;
class Prop;
class Group;
class HItem;
class HEntity;
class HProp;

class Cell
{
public:
	void unknown45de40();				// NOTE: placeholder name
	HItem getItem();					// 0x45d8f0
	bool unknown66b1c0(int type, bool unpowered);
	bool isPassableFor(HEntity e);		// 0x66ab30	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool operator==(HEntity other) const;
	bool operator!=(HEntity other) const;
	bool isValid() const;
	Entity *operator->() const;
};

class HItem
{
	int	ID;
public:
	HItem();
	bool isValid() const;
	Item *operator->() const;
};

class HProp
{
	int	ID;
public:
	HProp();
	bool isValid() const;
	Prop *operator->() const;
};

class HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	Group *operator->() const;	// 0x9b7250
};

class Group	// NOTE: placeholder name
{
public:
	vector<HEntity> *getMembers();	// NOTE: placeholder name (0x416f40)
	void unknown671f00(HEntity source, HEntity target);	// NOTE: placeholder name
};

struct OpR2_EntityData	// NOTE: placeholder name
{
	char pad00[0xac];
	int unknownAC;
};

struct OpR2_EntityEffect	// NOTE: placeholder name
{
	int unknown0;
	int duration;
};

class Item
{
public:
	bool unknown457cf0();	// NOTE: placeholder name
	int unknown44aec0();	// NOTE: placeholder name
};

class Entity
{
public:
	char pad00[0x28];
	HGroup group;						// +0x28, NOTE: partial layout
	bool isPlayer();					// 0x5c7600
	int getFaction();					// 0x45a2c0
	int getTarget();					// 0x45a760
	bool unknown45aaa0(HEntity e);		// NOTE: placeholder name
	int unknown5dc440(HItem item);		// NOTE: placeholder name
	bool unknown5cd220(HItem item);		// NOTE: placeholder name
	void unknown64da50(HItem item);		// NOTE: placeholder name
	bool unknown5c7f70();				// NOTE: placeholder name
	OpR2_EntityData *unknown9b4350();	// NOTE: placeholder name (trivial getter)
	const Point &getPosition();			// 0x45a4a0
	int unknown5d1390();				// NOTE: placeholder name
	bool unknown5cb680(HGroup g);		// NOTE: placeholder name
	void unknown64ecf0(OpR2_AI57f6a0 *ai);	// NOTE: placeholder name
	void die(bool a, int cause, HEntity killer, bool b, int c, int d, int e, int f);	// 0x633790
	int unknown5d15a0(bool notify);		// NOTE: placeholder name
	int unknown5df740(int mode);		// NOTE: placeholder name
	int unknown45acb0(int a);			// NOTE: placeholder name
	OpR2_EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	class EntityAI *getAI();			// NOTE: placeholder name (0x45b590)
	int unknown5cc190(int slot);		// NOTE: placeholder name
	HItem unknown5cc460(int slot, int maxSize);	// NOTE: placeholder name
};

class Map
{
public:
	int getTurn();	// 0x464270
	HGroup unknown463890(int i);	// NOTE: placeholder name
	int unknown464410(const Point &p);
	bool unknown463160(const Point &p);
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name	// NOTE: placeholder name	// NOTE: placeholder name
	bool isReachable(int range, const Point &from, const Point &to);	// 0x465230
};

int OpR2_minIndex(vector<unsigned int> &v);	// NOTE: placeholder name (0x9d9270)
int OpR2_distanceCeil(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)

extern Map *world;	// NOTE: placeholder name (0xcefc4c)
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

class EntityPart4588f0	// NOTE: placeholder name
{
public:
	int unknown458950(int id);	// NOTE: placeholder name
};

struct OpR2_Target	// NOTE: placeholder name
{
	HEntity entity;
	int unknown04;
	int score;
};
template <class T> void OpR2_clearObjects(vector<T *> &v);	// NOTE: placeholder name
template <class T> void OpR2_eraseAtIndex(vector<T> *v, unsigned int *i);	// NOTE: placeholder name (0x9de640, steps i back)
template <class T> void OpR2_eraseAt(vector<T> &v, unsigned int index);	// NOTE: placeholder name (0x9d8f20)
template <class T> bool OpR2_erase(vector<T> &v, T e);	// NOTE: placeholder name (0x9d2f00)
template <class T> bool OpR2_addUnique(vector<T> &v, T e);	// NOTE: placeholder name (0x9d30e0)

void sweepGetSurroundingCells(const Point &point, vector<Point> &adjacent);	// 0x4faaf0
bool OpR2_unknown6c1080(const Point &p);	// NOTE: placeholder name
void OpR2_eraseItemAt(vector<HItem> &v, int index);	// NOTE: placeholder name (0x9da940)
int OpR2_findItemIndex(vector<HItem> &v, HItem item);	// NOTE: placeholder name (0x9d3110)
extern vector<HItem> opr2_mapItems;	// NOTE: placeholder name (0xd33d74)

bool OpR2_unknown5111e0(int id, const string *a, const string *b, int c, HEntity d, HProp e, const Point *f, int g);	// NOTE: placeholder name (0x5111e0)
class OpR2_ConsoleA	// NOTE: placeholder name
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpR2_ConsoleA *opr2_consoleA;	// NOTE: placeholder name (0xcec058)
class OpR2_LogMsgs	// NOTE: placeholder name
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpR2_LogMsgs *opr2_logMsgs;	// NOTE: placeholder name (0xcec0b4)
extern bool opr2_groupTable_b94510[];	// NOTE: placeholder name (0xb94510)

class OpR2_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name
};
class OpR2_AI57f6a0	// NOTE: placeholder name
{
public:
	OpR2_AI57f6a0(HEntity e, int a, int b);	// NOTE: placeholder name (0x57f6a0)
	char pad[0x130];
};

extern bool opr2_flags_caf1ec[];	// NOTE: placeholder name (0xcaf1ec)

//==================================================================
// EntityAI
//==================================================================

struct OpR2_Rect	// NOTE: placeholder name
{
	int x;
	int y;
	int width;
	int height;
};

struct OpR2_Area	// NOTE: placeholder name
{
	Point min;
	Point max;
	Point randomPoint_40be90();		// NOTE: placeholder name
	void unknown40b3a0(const OpR2_Rect &rect);	// NOTE: placeholder name (0x40b3a0)
};
extern OpR2_Rect opr2_cf4da4;	// NOTE: placeholder name (0xcf4da4)
Point OpR2_randomPoint(vector<Point> &v);	// NOTE: placeholder name (0x9d5350)

class EntityAI
{
public:
	HEntity self;						// +0
	int state;							// +4, NOTE: placeholder name
	char pad08[0x10 - 0x08];
	Point unknown10;					// NOTE: placeholder name
	char pad18[0x56 - 0x18];
	bool preserveMemory;
	char pad57[0x80 - 0x57];
	OpR2_Area area;						// +0x80, NOTE: placeholder name
	vector<Point> candidates;			// +0x90, NOTE: placeholder name
	int unknownA0;						// NOTE: placeholder name
	char pada4[0xdc - 0xa4];
	vector<HEntity> remembered;			// +0xdc
	int rememberedTurn;					// +0xec
	vector<OpR2_Target *> targets;		// +0xf0
	char pad100[0x104 - 0x100];
	int unknown104;						// NOTE: placeholder name
	int targetCounter;					// +0x108
	char pad10c[0x11c - 0x10c];
	EntityPart4588f0 *part;				// +0x11c

	bool unknown5b4690(HEntity e);		// NOTE: placeholder name
	void unknown5b39b0(HEntity e);		// NOTE: placeholder name
	void unknown5b5220();				// NOTE: placeholder name
	int unknown5b4710(HEntity e, int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown5b51b0(HEntity e);		// NOTE: placeholder name
	bool unknown5b3890(HEntity e, int maxValue);	// NOTE: placeholder name
	int unknown5ba750(HEntity e);		// NOTE: placeholder name
	void unknown5bb6f0();				// NOTE: placeholder name
	bool unknown5bd240(HEntity e);		// NOTE: placeholder name
	bool unknown5bd350(HEntity e);		// NOTE: placeholder name
	void unknown5bd680();				// NOTE: placeholder name
	void unknown5b7220();				// NOTE: placeholder name
	Point unknown5ba650(int type, bool flag);	// NOTE: placeholder name
	bool unknown5b93a0();				// NOTE: placeholder name
	bool findPathToGoal();				// 0x5b8d20
	bool unknown5b91e0();				// NOTE: placeholder name
	int unknown459570(HEntity e);		// NOTE: placeholder name
	void unknown5b64d0();				// NOTE: placeholder name
	bool unknown5b66c0(Point &out);		// NOTE: placeholder name
	void unknown5b9cb0(int value);		// NOTE: placeholder name
	void unknown5b4530();				// NOTE: placeholder name
	void unknown5b7340(const Point &p);	// NOTE: placeholder name
	bool unknown5b57a0(HItem item, bool flag);	// NOTE: placeholder name
};

bool EntityAI::unknown5b4690(HEntity e)
{
	if (part)
	{
		if ((part->unknown458950(0x3e) && e->isPlayer()) || (self->getFaction() == 0x1d && part->unknown458950(0x2d)))
			return true;
	}
	return false;
}

void EntityAI::unknown5b39b0(HEntity e)
{
	if (e->unknown45aaa0(self))
		return;
	if (opr2_flags_caf1ec[self->getTarget()])
		return;
	OpR2_addUnique(remembered,e);
	rememberedTurn = world->getTurn();
}

void EntityAI::unknown5b5220()
{
	remembered.clear();
	targetCounter = 0;
	OpR2_clearObjects(targets);
}

void EntityAI::unknown5b51b0(HEntity e)
{
	unsigned int i;
	for (i = 0; i < targets.size(); i++)
		e->getAI()->unknown5b4710(targets[i]->entity,1,0,0,0);
}

bool EntityAI::unknown5b3890(HEntity e, int maxValue)
{
	bool found = false;
	unsigned int i;
	if (OpR2_erase(remembered,e))
		found = true;
	if (e->isPlayer())
		unknown104 = 0;
	for (i = 0; i < targets.size(); i++)
	{
		if (targets[i]->entity == e)
		{
			if (maxValue && targets[i]->unknown04 <= maxValue)
				return found;
			if (e->isPlayer())
				targetCounter = 0;
			OpR2_eraseAt(targets,i);
			found = true;
			return found;
		}
	}
	return found;
}

int EntityAI::unknown5ba750(HEntity e)
{
	return self->unknown5cc460(3,e->unknown5cc190(3)).isValid() ? 3 :
		self->unknown5cc460(0,e->unknown5cc190(0)).isValid() ? 0 :
		self->unknown5cc460(1,e->unknown5cc190(1)).isValid() ? 1 :
		self->unknown5cc460(2,e->unknown5cc190(2)).isValid() ? 2 : 4;
}

void EntityAI::unknown5b4530()
{
	unsigned int i;
	for (i = 0; i < remembered.size(); i++)
	{
		if (remembered[i].operator->())
		{
			if (!self->unknown45aaa0(remembered[i]))
			{
				unknown5b9cb0(unknown5b4710(remembered[i],2,6,0,0));
				if (self->unknown5c7f70())
				{
					world->unknown463890(0)->unknown671f00(self,remembered[i]);
					world->unknown463890(1)->unknown671f00(self,remembered[i]);
				}
			}
		}
	}
	remembered.clear();
}

void EntityAI::unknown5b7340(const Point &p)
{
	vector<HEntity> *members = self->group->getMembers();
	for (unsigned int i = 0; i < members->size(); i++)
	{
		if ((*members)[i]->getAI())
		{
			if ((*members)[i]->getAI()->unknown10 == p)
				(*members)[i]->getAI()->unknown10.x = -1;
		}
	}
}

bool EntityAI::unknown5b57a0(HItem item, bool flag)
{
	if (!item->unknown457cf0() && item->unknown44aec0() <= 3 && !self->unknown5dc440(item) && (flag || !self->unknown5cd220(item)))
	{
		self->unknown64da50(item);
		return true;
	}
	else
		return false;
}

void EntityAI::unknown5bb6f0()
{
	state = 3;
	area.min.set(0,0);
	area.max.set(cells.getWidth() - 1,cells.getHeight() - 1);
	candidates.clear();
}

bool EntityAI::unknown5bd240(HEntity e)
{
	return e->unknown9b4350()->unknownAC == 0 && e->getTarget() == 0 && OpR2_distanceCeil(self->getPosition(),e->getPosition()) <= 15 && world->isReachable(15,self->getPosition(),e->getPosition())
		&& !e->unknown45acb0(0x19) && !e->unknown45acb0(0x1a) && !e->unknown45acb0(0x1b) && !e->unknown45acb0(0x39);
}

bool EntityAI::unknown5bd350(HEntity e)
{
	return e->unknown9b4350()->unknownAC == 0 && (e->getTarget() == 3 || e->getTarget() == 4) && world->isReachable(9999,self->getPosition(),e->getPosition())
		&& !e->unknown45acb0(0x19) && !e->unknown45acb0(0x1a) && !e->unknown45acb0(0x1b) && !e->unknown45ac40(0x39);
}

void EntityAI::unknown5bd680()
{
	vector<unsigned int> values(7,9999999);
	int current = self->unknown5d1390();
	values[current] = self->unknown5d15a0(false);
	int last = current;
	for (int i = 0; i < 7; i++)
	{
		if (i != current && i != 5 && (i != 6 || self->getFaction() == 0x49) && self->unknown5df740(i) != 5)
		{
			values[i] = self->unknown5d15a0(false);
			last = i;
		}
	}
	int lowest = OpR2_minIndex(values);
	if (lowest != last)
		self->unknown5df740(lowest);
}

Point EntityAI::unknown5ba650(int type, bool flag)
{
	Point result(-1);
	vector<Point> adjacent;
	sweepGetSurroundingCells(self->getPosition(),adjacent);
	for (unsigned int i = 0; i < adjacent.size(); i++)
	{
		if (cells(adjacent[i])->unknown66b1c0(type,flag))
		{
			result = adjacent[i];
			break;
		}
	}
	return result;
}

void EntityAI::unknown5b7220()
{
	if (preserveMemory)
		return;
	switch (state)
	{
	case 4:
		cells(unknown10)->unknown45de40();
		break;
	case 5:
		if (OpR2_unknown6c1080(unknown10))
			unknown5b7340(unknown10);
		break;
	case 7:
	case 8:
		if (cells(unknown10)->getItem().isValid())
		{
			int index = OpR2_findItemIndex(opr2_mapItems,cells(unknown10)->getItem());
			if (index != -1)
			{
				OpR2_eraseItemAt(opr2_mapItems,index);
				unknown5b7340(unknown10);
			}
		}
		break;
	}
}

bool EntityAI::unknown5b93a0()
{
	for (int i = 0; i < 200; i++)
	{
		unknown10 = candidates.empty() ? area.randomPoint_40be90() : OpR2_randomPoint(candidates);
		do {} while (0);
		if (cells(unknown10)->isPassableFor(self) && !world->unknown464410(unknown10) && findPathToGoal())
		{
			do {} while (0);
			return true;
		}
	}
	if (area.min.x == 0)
	{
		area.unknown40b3a0(opr2_cf4da4);
		return unknown5b93a0();
	}
	unknown10.x = -1;
	return false;
}

bool EntityAI::unknown5b91e0()
{
	if (unknownA0 && candidates.empty() && rng.chance(unknownA0))
	{
		for (int i = 0; i < 100; i++)
		{
			unknown10 = area.randomPoint_40be90();
			do {} while (0);
			if (!world->unknown463160(unknown10) && cells(unknown10)->isPassableFor(self) && findPathToGoal())
			{
				do {} while (0);
				return true;
			}
		}
	}
	for (int j = 0; j < 15; j++)
	{
		unknown10 = candidates.empty() ? area.randomPoint_40be90() : OpR2_randomPoint(candidates);
		do {} while (0);
		if (cells(unknown10)->isPassableFor(self) && findPathToGoal())
		{
			do {} while (0);
			return true;
		}
	}
	unknown10.x = -1;
	return false;
}

void EntityAI::unknown5b64d0()
{
	for (int i = 0; i < 15; i++)
	{
		if (opr2_groupTable_b94510[i] && self->unknown5cb680(world->unknown463890(i)))
		{
			vector<HEntity> *members = world->unknown463890(i)->getMembers();
			for (unsigned int j = 0; j < members->size(); j++)
			{
				if ((*members)[j]->getAI()->unknown459570(self))
				{
					vector<OpR2_Target *> *targets = &(*members)[j]->getAI()->targets;
					for (unsigned int k = 0; k < targets->size(); k++)
					{
						if ((*targets)[k]->entity->unknown45aaa0(self) && (*targets)[k]->score != -2)
							OpR2_eraseAtIndex(targets,&k);
					}
				}
			}
		}
	}
	do
	{
		if (OpR2_unknown5111e0(0x285,NULL,NULL,0,self,HProp(),NULL,0))
			opr2_consoleA->unknown8758d0(true);
		opr2_logMsgs->scrollToEnd();
	} while (0);
	self->die(false,10,HEntity(),true,0,0,0,0);
}

bool EntityAI::unknown5b66c0(Point &out)
{
	int radius = 10;
	int dist = 20;
	Point pos;
	for (int i = 0; i < 100; i++)
	{
		cells.randomPos(pos);
		if (world->findPlaceableNear(pos,pos,1))
		{
			for (unsigned int j = 0; j < targets.size(); j++)
			{
				if (OpR2_distanceCeil(pos,targets[j]->entity->getPosition()) <= dist)
					goto nextAttempt;
			}
			cells.getArea(pos,radius,area);
			out = pos;
			return true;
		}
		nextAttempt:;
	}
	do {} while (0);
	self->unknown64ecf0(new OpR2_AI57f6a0(self,0x17,4));
	return false;
}
