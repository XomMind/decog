// team_d_19: EntityAI members (0x5b5830 part activation, 0x5b6130 marker target, 0x5b6a60 cell interaction,
// 0x5b6d40 prop placement, 0x5ba870 attack choice).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p) throw();	// 0x46ca50
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor (0x46ca50)
	int distanceTo(const Point &p) const;	// NOTE: placeholder name (PushGeometry::distanceTo)
	bool operator!=(const Point &p) const;	// NOTE: placeholder name (0x409bd0)
};

class HEntity;

class Item
{
public:
	bool unknown457d10();		// NOTE: placeholder name
	bool unknown577530();		// NOTE: placeholder name
	int unknown44fa50();		// NOTE: placeholder name (trivial getter)
	int unknown457c80();		// NOTE: placeholder name
	bool unknown5773d0(int a, int b);	// NOTE: placeholder name
	int unknown44aec0();		// NOTE: placeholder name (trivial getter)
	bool unknown457d70();		// NOTE: placeholder name
	int unknown457880();		// NOTE: placeholder name (Sweep_457880::getNestedField)
	void setActive(bool active);
	bool unknown457cf0();		// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class HItem
{
	int	ID;
public:
	HItem();
	bool isNull() const;
	bool isValid() const;
	Item *operator->() const;
};

struct XColor;

class Prop	// NOTE: placeholder layout
{
public:
	void unknown45cc50(const Point &p);		// NOTE: placeholder name
	void unknown45cc70(const XColor &c);	// NOTE: placeholder name
	void unknown4a0fc0(int value);			// NOTE: placeholder name (setter)
	int *unknown9c3a90();					// NOTE: placeholder name (trivial getter)
};

class HProp
{
	int ID;
public:
	HProp();
	bool isValid() const;
	bool isNull() const;
	Prop *operator->() const;
};

class Cell
{
public:
	HItem getItem();
	void *getEffect(int type);
	void unknown45dfb0(int type);	// NOTE: placeholder name
	void unknown66a050(int a, int b, int c);	// NOTE: placeholder name
	int unknown45d140();	// NOTE: placeholder name
	int getWidth();			// NOTE: placeholder name (folded with Array2D<Cell*>::getWidth)
	bool getField4550b0();	// NOTE: placeholder name
	HProp getProp();
	bool unknown45dcf0();	// NOTE: placeholder name
	void removeProp(bool keepTerrain, int cause);	// 0x66c100
	void setProp(HProp prop);	// NOTE: placeholder name (0x45df50)
	void unknown66b700(int a, int b);	// NOTE: placeholder name
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(const Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
	Cell **at(int x, int y);			// NOTE: folded with OpX5_Array2D<int>::at
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

class Entity
{
public:
	char pad[0x40];
	int unknown40;	// NOTE: placeholder name

	Point &getPosition();	// 0x45a4a0
	void changePos(const Point &p, int a);
	void unknown45b0b0();	// NOTE: placeholder name
	void unknown64da50(HItem item);	// NOTE: placeholder name
	bool isPlayer();		// 0x5c7600
	int getFaction();		// 0x45a2c0
	int getTarget();		// 0x45a760
	int unknown490840();	// NOTE: placeholder name (trivial getter)
	int unknown5ca260();	// NOTE: placeholder name

	char pad44[0x134 - 0x44];
	vector<HItem> parts;	// +0x134, NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	bool operator!=(HEntity other) const;
	Entity *operator->() const;
};

class BS
{
public:
	bool unknown71ec60(const Point &p, vector<Point> points);	// NOTE: placeholder name
	bool unknown7168e0(const Point &from, const Point &to, Entity *entity, vector<Point> *path);	// NOTE: placeholder name
	void unknown464780();	// NOTE: placeholder name
	HEntity getEntity671();	// NOTE: placeholder name
	void unknown71ef30(const Point &p, int a);	// NOTE: placeholder name
};
extern BS *world;

struct Rec_cf0fa8 { char pad[8]; int index; };		// NOTE: placeholder name
struct Rec_cfb844 { char pad[0x58]; bool flag; };	// NOTE: placeholder name
extern vector<Rec_cf0fa8 *> list_cf0fa8;	// NOTE: placeholder name
extern vector<Rec_cfb844 *> list_cfb844;	// NOTE: placeholder name
extern int index_ce9ff4;					// NOTE: placeholder name

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
bool logMessageI_5111e0(int id, int a, int b, int c, HEntity e, HProp d, int f, int g);	// NOTE: placeholder name (0x5111e0)

class EntityAI
{
public:
	HEntity self;
	char pad04[0xcc - 0x04];
	int unknowncc;	// NOTE: placeholder name
	int unknownd0;	// NOTE: placeholder name

	void unknown5b7340(const Point &p);	// NOTE: placeholder name
	int unknown5b6a60(const Point &p, Point *dest);	// NOTE: placeholder name
	void unknown5b5830(bool preferHigh);	// NOTE: placeholder name
	bool unknown5b6130(Point *out);	// NOTE: placeholder name
	int unknown5ba750(HEntity e);	// NOTE: placeholder name
	int unknown5ba870(HEntity target, HItem *outItem, int *outType);	// NOTE: placeholder name
	int unknown5b6d40(const Point &p, Point *dest);	// NOTE: placeholder name


};

int EntityAI::unknown5b6a60(const Point &p, Point *dest)
{
	if (!list_cfb844[list_cf0fa8[index_ce9ff4]->index]->flag && (*cells_cfd44c.atPoint(p))->getItem().isValid())
	{
		vector<Point> points(1,p);
		if (!world->unknown71ec60(p,points))
			(*cells_cfd44c.atPoint(p))->getItem()->unknown57dbe0(0,0,1,1);
	}
	if ((*cells_cfd44c.atPoint(p))->getEffect(6))
	{
		(*cells_cfd44c.atPoint(p))->unknown45dfb0(6);
		do { if (logMessageI_5111e0(0x254,0,0,0,self,HProp(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
	}
	else
	{
		(*cells_cfd44c.atPoint(p))->unknown66a050(list_cf0fa8[index_ce9ff4]->index,1,0);
		do { if (logMessageI_5111e0(0x253,(*cells_cfd44c.atPoint(p))->getWidth() + 0x90,(*cells_cfd44c.atPoint(p))->unknown45d140(),0,self,HProp(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
	}
	unknown5b7340(Point(p));
	if (*dest != self->getPosition())
		self->changePos(*dest,1);
	do
	{
		self->unknown40++;
		self->unknown45b0b0();
		return ((*cells_cfd44c.atPoint(p))->getField4550b0() ? 1 : 4) * 100;
	}
	while (0);
	return 0;
}

void EntityAI::unknown5b5830(bool preferHigh)
{
	vector<HItem> tags;
	vector<HItem> allies;
	for (unsigned int i = 0; i < self->parts.size(); i++)
	{
		if (self->parts[i]->unknown44aec0() == 3 && self->parts[i]->unknown457d70())
		{
			if (self->parts[i]->unknown457880() >= 0x1a)
				tags.push_back(self->parts[i]);
			else
				allies.push_back(self->parts[i]);
		}
	}
	if (tags.empty() && allies.empty())
		return;
	bool found = false;
	bool first = false;
	if (tags.empty() || allies.empty())
	{
		found = !tags.empty();
		first = !allies.empty();
	}
	else if (preferHigh)
	{
		found = true;
		first = false;
	}
	else
	{
		found = false;
		first = true;
	}
	for (unsigned int j = 0; j < tags.size(); j++)
	{
		if (!found)
			tags[j]->setActive(false);
		else if (!tags[j]->unknown457cf0())
			self->unknown64da50(tags[j]);
	}
	for (unsigned int k = 0; k < allies.size(); k++)
	{
		if (!first)
			allies[k]->setActive(false);
		else if (!allies[k]->unknown457cf0())
			self->unknown64da50(allies[k]);
	}
}

struct MarkerData37	// NOTE: placeholder name
{
	char pad[0x140];
	int unknown140;	// NOTE: placeholder name
};

class Marker37	// NOTE: placeholder name
{
public:
	MarkerData37 *getData();	// NOTE: placeholder name (trivial getter)
	Point &getPosition();		// NOTE: placeholder name (0x4184d0)
};

class HMarker37	// NOTE: placeholder name
{
	int ID;
public:
	Marker37 *operator->() const;
};
extern vector<vector<HMarker37> > markerLists_d20248;	// NOTE: placeholder name

bool EntityAI::unknown5b6130(Point *out)
{
	int current = -1;
	int minDistance;
	for (int pass = 0; pass < 2 && current == -1; pass++)
	{
		for (unsigned int i = 0; i < markerLists_d20248.size(); i++)
		{
			if (!markerLists_d20248[i].empty() && markerLists_d20248[i].front()->getData()->unknown140 == 0xe
				&& (current == -1 || self->getPosition().distanceTo(markerLists_d20248[i].front()->getPosition()) < minDistance))
			{
				if (pass == 0)
				{
					Point p(markerLists_d20248[i].front()->getPosition());
					if (!(((*cells_cfd44c.at(p.x - 1,p.y))->getField4550b0() || (*cells_cfd44c.at(p.x + 1,p.y))->getField4550b0())
						&& ((*cells_cfd44c.at(p.x,p.y - 1))->getField4550b0() || (*cells_cfd44c.at(p.x,p.y + 1))->getField4550b0())))
						continue;
				}
				current = i;
				minDistance = self->getPosition().distanceTo(markerLists_d20248[i].front()->getPosition());
			}
		}
	}
	vector<Point> path;
	if (current == -1 || (self->getPosition() != markerLists_d20248[current].front()->getPosition()
		&& !world->unknown7168e0(self->getPosition(),markerLists_d20248[current].front()->getPosition(),self.operator->(),&path)))
	{
		world->unknown464780();
		return false;
	}
	else
	{
		*out = markerLists_d20248[current].front()->getPosition();
		return true;
	}
}

extern int gameMode_cf462c;		// NOTE: placeholder name
extern int flag_cf4700;			// NOTE: placeholder name
extern float multiplier_bba1dc;	// NOTE: placeholder name
extern float multiplier_bba054;	// NOTE: placeholder name

int EntityAI::unknown5ba870(HEntity target, HItem *outItem, int *outType)
{
	if (gameMode_cf462c == 0xb && target->isPlayer() && !flag_cf4700)
		return 0;
	if (target->getFaction() == 0 && !target->isPlayer())
		return 0;
	if (target->getTarget() >= 6)
		return 0;
	if (unknownd0 > 0 && !target->isPlayer() && target != world->getEntity671() && target->unknown490840() < (int)(target->unknown5ca260() * multiplier_bba1dc))
		return 1;
	if (target->isPlayer())
	{
		for (unsigned int i = 0; i < target->parts.size(); i++)
		{
			if (target->parts[i]->unknown44aec0() <= 3 && target->parts[i]->unknown457d10() && target->parts[i]->unknown577530())
			{
				if (outItem)
					*outItem = target->parts[i];
				return 2;
			}
		}
	}
	int type = unknown5ba750(target);
	if (type != 4)
	{
		if (outType)
			*outType = type;
		return 3;
	}
	if (unknownd0 > 0)
	{
		HItem best;
		for (unsigned int j = 0; j < target->parts.size(); j++)
		{
			if (target->parts[j]->unknown44aec0() <= 3 && target->parts[j]->unknown44fa50() < (int)(target->parts[j]->unknown457c80() * multiplier_bba054)
				&& (best.isNull() || target->parts[j]->unknown44fa50() < best->unknown44fa50()) && target->parts[j]->unknown5773d0(0,0))
				best = target->parts[j];
		}
		if (best.isValid())
		{
			if (outItem)
				*outItem = best;
			return 4;
		}
	}
	return 0;
}

#define TURN_COST(cost) do { self->unknown40++; self->unknown45b0b0(); return (cost); } while (0)	// NOTE: placeholder macro

class PropFactory	// NOTE: placeholder name (0xcefaa8)
{
public:
	HProp createE(int *data);
};
extern PropFactory *propFactory_cefaa8;	// NOTE: placeholder name
extern int *propData_cefbd4;			// NOTE: placeholder name
extern XColor &ptr_d1d46c;				// NOTE: placeholder name
extern int value_d2d284;				// NOTE: placeholder name

struct Rec_cf44b0	// NOTE: placeholder name
{
	int				index;		// NOTE: placeholder name
	bool			unknown04;	// NOTE: placeholder name
	char			pad05[0xc - 0x5];
	vector<Point>	points;		// +0xc, NOTE: placeholder name
	vector<int>		values;		// +0x1c, NOTE: placeholder name
};
extern vector<Rec_cf44b0 *> list_cf44b0;	// NOTE: placeholder name

struct Rec_cf35b0	// NOTE: placeholder name
{
	char pad[0x20];
	string name;	// +0x20, NOTE: placeholder name
};
extern vector<Rec_cf35b0 *> list_cf35b0;	// NOTE: placeholder name
extern vector<int> list_d2a520;				// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
	int rangeInt(float a, float b);
};
extern RNG rng;

int OpU8a_indexOfPoint(vector<Point> &v, Point p);	// NOTE: placeholder name
void sweepGetSurroundingCells(const Point &point, vector<Point> &adjacent);	// 0x4faaf0
template <class T> void OpV4c_shuffle(vector<T> &v);	// NOTE: placeholder name
bool logMessageS_5111e0(int id, string *text, int b, int c, HEntity e, HProp d, int f, int g);	// NOTE: placeholder name (0x5111e0)

int EntityAI::unknown5b6d40(const Point &p, Point *dest)
{
	if ((*cells_cfd44c.atPoint(p))->getProp().isValid())
	{
		if ((*cells_cfd44c.atPoint(p))->unknown45dcf0())
		{
			(*cells_cfd44c.atPoint(p))->removeProp(true,4);
			TURN_COST(100);
		}
		else
			TURN_COST(500);
	}
	if ((*cells_cfd44c.atPoint(p))->getItem().isValid())
		world->unknown71ef30(p,1);
	HProp prop = propFactory_cefaa8->createE(propData_cefbd4);
	(*cells_cfd44c.atPoint(p))->setProp(prop);
	prop->unknown45cc50(p);
	prop->unknown45cc70(ptr_d1d46c);
	Rec_cf44b0 *rec = list_cf44b0[unknowncc];
	vector<Point> *elements = &rec->points;
	prop->unknown4a0fc0(rec->values[OpU8a_indexOfPoint(*elements,p)]);
	if (rng.chance(50))
	{
		vector<Point> around;
		sweepGetSurroundingCells(p,around);
		OpV4c_shuffle(around);
		for (unsigned int i = 0; i < around.size(); i++)
		{
			if ((*cells_cfd44c.atPoint(around[i]))->getProp().isNull())
			{
				(*cells_cfd44c.atPoint(around[i]))->unknown66b700(rng.rangeInt(1,18) - 1,value_d2d284);
				break;
			}
		}
	}
	for (unsigned int j = 0; j < elements->size(); j++)
	{
		if ((*cells_cfd44c.atPoint((*elements)[j]))->getProp().isNull() || (*cells_cfd44c.atPoint((*elements)[j]))->getProp()->unknown9c3a90() != propData_cefbd4)
		{
			do { if (logMessageS_5111e0(0x255,&list_cf35b0[rec->index]->name,0,0,self,HProp(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
			goto moved;
		}
	}
	do { if (logMessageS_5111e0(0x256,&list_cf35b0[rec->index]->name,0,0,self,HProp(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
	list_cf44b0[unknowncc]->unknown04 = true;
	list_d2a520.push_back(unknowncc);
	unknowncc = -1;
moved:
	if (*dest != self->getPosition())
		self->changePos(*dest,1);
	TURN_COST(500);
	return 0;
}
