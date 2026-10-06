// op_s5: functions in 0x718000-0x7ed000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <ostream>
#include <ctype.h>
#include "../util/rng.h"
using namespace std;

class OpY5_HEntity;
class OpY5_HGroup;

extern RNG rng;	// 0xd30908

class OpY5_Item	// NOTE: placeholder name
{
public:
	bool unknown457cf0();	// NOTE: placeholder name
	int unknown457fb0();	// NOTE: placeholder name
	bool unknown4579d0();	// NOTE: placeholder name
	void unknown458700(const string &text);	// NOTE: placeholder name
	int unknown4578a0();	// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown57bff0(int type, bool flag);	// NOTE: placeholder name
};

class OpY5_HItem	// NOTE: placeholder name
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
	OpY5_Item *operator->() const;	// 0x9b65b0
	OpY5_Item *get() const;	// NOTE: placeholder name (folded with operator->)
};

class OpY5_WeightedStrings	// NOTE: placeholder name
{
public:
	OpY5_WeightedStrings();	// 0x9b9ee0
	~OpY5_WeightedStrings();	// 0x55c900
	void add(string value, int weight);	// NOTE: placeholder name (0x9b9f50)
	const string &pick();	// NOTE: placeholder name (0x9b9fd0)

	int pad0, pad4, pad8, padc, pad10, pad14, pad18, pad1c, pad20;
};

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(int v);	// 0x409990
	Point(int x_, int y_);	// 0x46ca20
	bool operator==(const Point &p) const;	// 0x409b90
	bool adjacent(const Point &p) const;	// NOTE: placeholder name (0x409dd0)
	Point(const Point &p);	// 0x46ca50
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor (0x46ca50)
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();	// 0x411d40
	XColor(const XColor &color) throw();	// 0x411e30
	XColor &operator=(XColor color);	// 0x411f10
};

struct OpY5_Range	// NOTE: placeholder name
{
	int min;
	int max;

	OpY5_Range(const OpY5_Range &r);	// 0x46ca50
	void shift(int amount);	// NOTE: placeholder name (0x40bf50)
	bool contains(int value);	// NOTE: placeholder name (0x40c190)
};

struct OpY5_Area	// NOTE: placeholder name
{
	Point a;
	Point b;

	OpY5_Area();	// 0x40b100
	Point randomPointRet();	// NOTE: placeholder name (0x40be90)
	void randomPoint(Point *p);	// NOTE: placeholder name (0x40be30)
};

int opS5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
template <class T> void opS5_eraseStep(vector<T> &v, unsigned int &index);	// NOTE: placeholder name
int opS5_randomElement(vector<int> *v);	// NOTE: placeholder name (0x9d5d00)
template <class T> void opS5_eraseRange(vector<T> &v, int from, int to);	// NOTE: placeholder name
template <class T> void opS5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name
struct OpS5_MapRecord	// NOTE: placeholder name
{
	char pad0[0x28];
	int unknown28;	// NOTE: placeholder name
};
extern vector<OpS5_MapRecord *> opS5_records_cfd2cc;	// NOTE: placeholder name
int opY5_distance(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)

class OpY5_AI	// NOTE: placeholder name
{
public:
	void unknown5b5220();	// NOTE: placeholder name
	bool unknown458fb0(OpY5_HEntity e);	// NOTE: placeholder name
};

class OpY5_Entity	// NOTE: placeholder name
{
public:
	const Point &getPosition();	// 0x45a4a0
	int getSize();	// 0x45a360
	bool isPlayer();	// 0x5c7600
	OpY5_AI *getAI();	// 0x45b590
	int unknown45a540(const Point &p);	// NOTE: placeholder name
	const XColor &unknown5c7630();	// NOTE: placeholder name
	Point getPositionCopy();	// NOTE: placeholder name (0x45a4c0)
	bool unknown5cb680(OpY5_HGroup g);	// NOTE: placeholder name
	void unknown5ddac0(const Point &p, bool flag);	// NOTE: placeholder name
	void changePos(const Point &p, bool flag);	// NOTE: placeholder signature (0x5dccb0)
	const string &getNameAt0c();	// NOTE: placeholder name (folded getter 0x416f40)
	const string &getName();	// 0x45a280
	int getFaction();	// 0x45a2c0
	vector<Point> *getFootprint();	// NOTE: placeholder name (0x45d1a0)
	void *getEffect(int type);	// NOTE: placeholder name (0x45ac40)
	int unknown5cccc0();	// NOTE: placeholder name
	bool isXomCandidate();	// 0x5d51a0
	vector<OpY5_HItem> *getInventoryList();	// 0x45ab00
	int unknown448fe0(int type);	// NOTE: placeholder name
	void unknown64da50(OpY5_HItem item);	// NOTE: placeholder name
};

class OpY5_HProp	// NOTE: placeholder name
{
public:
	int ID;
	OpY5_HProp();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
};

class OpY5_HEntity	// NOTE: placeholder name
{
public:
	int ID;
	OpY5_HEntity();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	bool operator==(OpY5_HEntity other) const;	// NOTE: placeholder name
	OpY5_Entity *operator->() const;	// 0x9b6570
	OpY5_Entity *get() const;	// NOTE: placeholder name (folded with operator-> 0x9b6570)
};

class OpY5_Prop	// NOTE: placeholder name
{
public:
	void unknown45ce10(bool a, bool b, bool c, OpY5_HProp d);	// NOTE: placeholder name
};

class OpY5_HPropP	// NOTE: placeholder name (HProp with accessor)
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
	OpY5_Prop *operator->() const;	// 0x9b64f0
};

class OpY5_Group	// NOTE: placeholder name
{
public:
	vector<OpY5_HEntity> *getMembers();	// NOTE: placeholder name (folded getter 0x416f40)
};

class OpY5_HGroup	// NOTE: placeholder name
{
public:
	int ID;
	OpY5_Group *operator->() const;	// 0x9b7250
};

class OpY5_Cell	// NOTE: placeholder name
{
public:
	bool hasBlockingObject();	// NOTE: placeholder name (0x45d7b0)
	OpY5_HItem getItem();	// NOTE: placeholder name (0x45d8f0)
	OpY5_HEntity getEntity();	// NOTE: placeholder name (0x45d250)
	bool canPlaceEntity(int size);	// 0x66ad20
	bool isPassableFor(OpY5_HEntity e);	// NOTE: placeholder name (0x66ab30)
	bool fitsProp(void *propData);	// NOTE: placeholder name (0x45d570)
	OpY5_HPropP getProp();	// 0x45d550
	void unknown45e110(bool a, bool b, OpY5_HProp c);	// NOTE: placeholder name
};

class OpY5_Cells	// NOTE: placeholder name (0xcfd44c)
{
public:
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
	int getWidth();	// NOTE: placeholder name (0x9fcd80)
	int getHeight();	// NOTE: placeholder name (0x9b8f00)
	OpY5_Cell *&operator()(int x, int y);	// 0x9ceda0
	OpY5_Cell *&operator()(const Point &p);	// 0x9ced70
	void randomPos(Point &p);	// NOTE: placeholder name (0x9cf0c0)
	void getArea(const Point &center, int radius, OpY5_Area &area);	// NOTE: placeholder name (0x9b4430)
};
extern OpY5_Cells opY5_cells;	// NOTE: placeholder name

class OpY5_Dijkstra	// NOTE: placeholder name (0xcfe568)
{
public:
	void run(const Point &start, int range, void *cost, void *data);	// 0x40ca20
};
extern OpY5_Dijkstra opY5_dijkstra;	// NOTE: placeholder name
struct OpY5_DijkstraCost	// NOTE: placeholder name
{
	int pad0, pad4, pad8, padc;
};
extern OpY5_DijkstraCost opY5_dijkstraCost_d1e1dc;	// NOTE: placeholder name
extern vector<Point> opY5_dijkstraCells;	// NOTE: placeholder name (0xd15e58)
extern int opY5_dijkstraRangeEnd;	// NOTE: placeholder name (0xced284)
extern int opY5_dijkstraRangeStart;	// NOTE: placeholder name (0xcef678)
extern bool opS5_dijkstraFlag_cefc9d;	// NOTE: placeholder name (0xcefc9d)
extern OpY5_DijkstraCost opR4_dijkstraCost_d39714;	// NOTE: placeholder name
bool opR4_isEntrance(const Point &p);	// NOTE: placeholder name (0x448b80)
void clearDijkstraResults();
void findFirstDijkstraRange();
bool findNextDijkstraRange();

template <class T>
class OpY5_WeightedList	// NOTE: placeholder name
{
public:
	vector<T> values;	// NOTE: placeholder name
	vector<int> weights;	// NOTE: placeholder name
	int total;	// NOTE: placeholder name

	OpY5_WeightedList();	// 0x9bab50
	void add(T value, int weight);	// NOTE: placeholder name (0x9ba310 for int)
	void addUnique(T value, int weight);	// NOTE: placeholder name (0x9b6e10 for pointers)
	T &pick();	// NOTE: placeholder name (0x9ba470)
};

struct OpY5_ItemType	// NOTE: placeholder name
{
	char pad0[0x44];
	int unknown44;	// NOTE: placeholder name
	char pad48[0x4c - 0x48];
	int unknown4c;	// NOTE: placeholder name
	char pad50[0x234 - 0x50];
	int unknown234;	// NOTE: placeholder name
};
extern vector<OpY5_ItemType *> opY5_itemTypes;	// NOTE: placeholder name (0xd2d1c4)
extern int opY5_table_ba3acc[];	// NOTE: placeholder name
bool opY5_inVector(vector<int> &v, int value);	// NOTE: placeholder name (0x9db330)
int opY5_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)

class OpS5_IntGrid	// NOTE: placeholder name (Array2D<int>)
{
	int width;
	int height;
	int *data;
public:
	int &operator()(const Point &p);	// 0x9ced70 (ICF)
};

struct OpS5_Rec	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	OpY5_HEntity entity;
	int unknownc;
	XColor color;
};

class OpS5_RecGrid	// NOTE: placeholder name (Array2D<OpS5_Rec>)
{
	int width;
	int height;
	OpS5_Rec *data;
public:
	OpS5_Rec &operator()(const Point &p);	// 0x9d2930
};

class OpY5_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	char pad0[0x4c];
	vector<OpY5_HGroup> groups4c;	// NOTE: placeholder name
	char pad5c[0x4e0 - 0x5c];
	vector<OpY5_HItem> items4e0;	// NOTE: placeholder name
	char pad4f0[0x66c - 0x4f0];
	OpY5_HEntity entity66c;	// NOTE: placeholder name
	char pad670[0x69c - 0x670];
	OpS5_IntGrid grid69c;	// NOTE: placeholder name
	char pad6a8[0x740 - 0x6a8];
	OpS5_RecGrid grid740;	// NOTE: placeholder name
	int unknown74c;	// NOTE: placeholder name
	int pad750;
	vector<Point> points754;	// NOTE: placeholder name
	char pad764[0x830 - 0x764];
	vector<Point> points830;	// NOTE: placeholder name
	vector<Point> points840;	// NOTE: placeholder name
	char pad850[0xb94 - 0x850];
	vector<int> ints_b94;	// NOTE: placeholder name
	int pickRecordBelow71cbf0(int limit);	// NOTE: placeholder name
	void addTrailPoint71ce30(const Point &p);	// NOTE: placeholder name
	void unknown71fef0(OpY5_HEntity e);	// NOTE: placeholder name
	void opw3_unknown72a0b0(OpY5_HEntity e);	// NOTE: placeholder name
	int getMaxItemRange71c930();	// NOTE: placeholder name
	bool isEntityInRange71ca20(OpY5_HEntity e);	// NOTE: placeholder name
	bool isEntityInGroupWithAI71cb10(OpY5_HEntity e);	// NOTE: placeholder name
	bool unknown465200(const Point &a, const Point &b);	// NOTE: placeholder name
	int unknown714b50();	// NOTE: placeholder name
	bool findRandomPlaceable(const Point &center, int radius, int size, Point &out, bool checkEntrance);	// NOTE: placeholder name (0x71c300)
	OpY5_HEntity spawn6c5dc0(const string &name, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);	// NOTE: placeholder name (0x6c5dc0)
	bool findPropSpotNear(const Point &p, Point &out, void *propData);	// NOTE: placeholder name (0x71c3c0)
	bool isReachable(int range, const Point &from, const Point &to);	// NOTE: placeholder name (0x465230)
	OpY5_HEntity getEntity671();	// NOTE: placeholder name (0x463110)
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name
	void addEntitiesAround(OpY5_HEntity entity, vector<OpY5_HEntity> *out);	// NOTE: placeholder name (0x71c550)
	void addPropsAround(OpY5_HEntity entity, vector<OpY5_HPropP> *out);	// NOTE: placeholder name (0x71c6d0)
	bool findItemSpotNear(const Point &p, Point &out);	// NOTE: placeholder name (0x71bcc0)
	bool findPlaceableNearWide(const Point &p, Point &out, int size);	// NOTE: placeholder name (0x71c200)
	OpY5_HEntity getPlayer();	// 0x4630f0
	OpY5_HGroup getGroup(int type);	// NOTE: placeholder name (0x463890)
	OpY5_HItem unknown6c51d0(OpY5_ItemType *type, OpY5_HEntity e, bool a, bool b);	// NOTE: placeholder name
	void unknown71cf70();	// NOTE: placeholder name
	void unknown734560(OpY5_HEntity e, int a, bool b);	// NOTE: placeholder name
	bool isVisible(const Point &p);	// 0x4631c0
	vector<OpY5_HEntity> *getEntities();	// NOTE: placeholder name (0x4636f0)
	bool unknown4631f0(OpY5_HEntity e);	// NOTE: placeholder name
};
extern OpY5_World *opY5_world;	// NOTE: placeholder name

bool opY5_logMessage(int id, const string &text, const string *b, int c, OpY5_HProp d, OpY5_HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)

class OpY5_MsgConsole	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpY5_MsgConsole *opY5_cec058;	// NOTE: placeholder name

class OpY5_LogMsgs	// NOTE: placeholder name (CLogMsgs)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpY5_LogMsgs *opY5_logMsgs;	// NOTE: placeholder name (0xcec0b4)

#define OPY5_LOG_AT(id,text,at) do { if (opY5_logMessage(id,text,0,0,OpY5_HProp(),OpY5_HProp(),at,0)) opY5_cec058->unknown8758d0(true); opY5_logMsgs->scrollToEnd(); } while (0)	// NOTE: placeholder macro
#define OPY5_LOG(id,text) do { if (opY5_logMessage(id,text,0,0,OpY5_HProp(),OpY5_HProp(),0,0)) opY5_cec058->unknown8758d0(true); opY5_logMsgs->scrollToEnd(); } while (0)	// NOTE: placeholder macro

bool findEffectID(const string &name, int *id);	// NOTE: placeholder name (0x9d7980)

class OpY5_Effect	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class OpY5_EffectMgr	// NOTE: placeholder name
{
public:
	OpY5_Effect *create();	// NOTE: placeholder name (0x508610)
};
extern OpY5_EffectMgr *opY5_effectMgr;	// NOTE: placeholder name (0xcefc50)
extern Point opY5_effectOrigin;	// NOTE: placeholder name (0xd2e20c)

class OpY5_Obj_cec138	// NOTE: placeholder name (object at 0xcec138)
{
public:
	void unknown9666d0();	// NOTE: placeholder name
};
extern OpY5_Obj_cec138 *opY5_cec138;	// NOTE: placeholder name

void opY5_insertAt(vector<OpY5_HEntity> &v, int index, OpY5_HEntity value);	// NOTE: placeholder name (0x9d8fc0)
void opY5_insertAt(vector<int> &v, int index, int value);	// NOTE: placeholder name (0x9dbdc0)
void opY5_moveTo(vector<OpY5_HEntity> &v, int from, int to);	// NOTE: placeholder name (0x9da1f0)
void opY5_moveTo(vector<int> &v, int from, int to);	// NOTE: placeholder name (0x9e2ce0)

void opY5_unknown5141b0(int id, int a, int b, int c, OpY5_HProp e, int d);	// NOTE: placeholder name (0x5141b0)


//==================================================================
// op_s5 additions to the shared declarations
//==================================================================

extern OpY5_DijkstraCost opS5_dijkstraCost_d35394;	// NOTE: placeholder name
extern int opS5_itemTypeMatter;	// NOTE: placeholder name (0xcefbe4)

//==================================================================
// 0x71bcc0-0x71c600
//==================================================================

bool OpY5_World::findItemSpotNear(const Point &p, Point &out)
{
	if (opY5_cells(p)->hasBlockingObject() || (opY5_cells(p)->getItem().isValid() && opY5_cells(p)->getItem()->unknown4578a0() == opS5_itemTypeMatter && rng.chance(50)))
	{
		out = p;
		return true;
	}
	else
	{
		clearDijkstraResults();
		opY5_dijkstra.run(p,12,&opS5_dijkstraCost_d35394,(void *)opS5_itemTypeMatter);
		if (opY5_dijkstraCells.empty())
			return false;
		else
		{
			findFirstDijkstraRange();
			out = opY5_dijkstraCells[rng.rangeInt(opY5_dijkstraRangeStart,opY5_dijkstraRangeEnd)];
			return true;
		}
	}
}

bool OpY5_World::findPlaceableNearWide(const Point &p, Point &out, int size)
{
	if (!opY5_cells(p)->canPlaceEntity(size))
	{
		clearDijkstraResults();
		opS5_dijkstraFlag_cefc9d = true;
		opY5_dijkstra.run(p,32,&opY5_dijkstraCost_d1e1dc,&size);
		opS5_dijkstraFlag_cefc9d = false;
		if (opY5_dijkstraCells.empty())
			return false;
		else
		{
			findFirstDijkstraRange();
			while (rng.chance(80))
			{
				if (!findNextDijkstraRange())
					goto fallback;
			}
			out = opY5_dijkstraCells[rng.rangeInt(opY5_dijkstraRangeStart,opY5_dijkstraRangeEnd)];
			return true;
fallback:
			return findPlaceableNear(p,out,size);
		}
	}
	else
	{
		out = p;
		return true;
	}
}

void opS5_addEntityAt(const Point &p, vector<OpY5_HEntity> *out)	// NOTE: placeholder name
{
	if (opY5_cells.contains(p))
	{
		if (opY5_cells(p)->getEntity().isValid())
			out->push_back(opY5_cells(p)->getEntity());
	}
}

void opS5_addPropAt(const Point &p, vector<OpY5_HPropP> *out)	// NOTE: placeholder name
{
	if (opY5_cells.contains(p))
	{
		if (opY5_cells(p)->getProp().isValid())
			out->push_back(opY5_cells(p)->getProp());
	}
}

void OpY5_World::addEntitiesAround(OpY5_HEntity entity, vector<OpY5_HEntity> *out)
{
	Point pos = entity->getPosition();
	int size = entity->getSize();
	if (pos.y > 0)
	{
		for (int i = -1; i < size + 1; i++)
			opS5_addEntityAt(Point(pos.x + i,pos.y - 1),out);
	}
	if (pos.y + size < opY5_cells.getHeight())
	{
		for (int i = -1; i < size + 1; i++)
			opS5_addEntityAt(Point(pos.x + i,pos.y + 1),out);
	}
	if (pos.x > 0)
	{
		for (int i = 0; i < size; i++)
			opS5_addEntityAt(Point(pos.x - 1,pos.y + i),out);
	}
	if (pos.x + size < opY5_cells.getWidth())
	{
		for (int i = 0; i < size; i++)
			opS5_addEntityAt(Point(pos.x + 1,pos.y + i),out);
	}
}

void OpY5_World::addPropsAround(OpY5_HEntity entity, vector<OpY5_HPropP> *out)
{
	Point pos = entity->getPosition();
	int size = entity->getSize();
	if (pos.y > 0)
	{
		for (int i = -1; i < size + 1; i++)
			opS5_addPropAt(Point(pos.x + i,pos.y - 1),out);
	}
	if (pos.y + size < opY5_cells.getHeight())
	{
		for (int i = -1; i < size + 1; i++)
			opS5_addPropAt(Point(pos.x + i,pos.y + 1),out);
	}
	if (pos.x > 0)
	{
		for (int i = 0; i < size; i++)
			opS5_addPropAt(Point(pos.x - 1,pos.y + i),out);
	}
	if (pos.x + size < opY5_cells.getWidth())
	{
		for (int i = 0; i < size; i++)
			opS5_addPropAt(Point(pos.x + 1,pos.y + i),out);
	}
}

void opS5_getAdjacentCells(const Point &p, vector<Point> &adjacent);	// NOTE: placeholder name (0x4fab80)

int OpY5_World::getMaxItemRange71c930()
{
	if (items4e0.empty())
		return 0;
	int result = 0;
	for (unsigned int i = 0; i < items4e0.size(); i++)
	{
		if (items4e0[i].get() && items4e0[i]->unknown457cf0())
			result = opS5_maxInt(result,items4e0[i]->unknown457fb0());
		else
			opS5_eraseStep(items4e0,i);
	}
	return result;
}

bool OpY5_World::isEntityInRange71ca20(OpY5_HEntity e)
{
	if (e == entity66c)
		return false;
	int range = getMaxItemRange71c930();
	return (range != 0 && unknown4631f0(e) && unknown465200(entity66c->getPositionCopy(),e->getPositionCopy()) && opY5_distance(entity66c->getPositionCopy(),e->getPositionCopy()) <= range);
}

bool OpY5_World::isEntityInGroupWithAI71cb10(OpY5_HEntity e)
{
	for (unsigned int i = 0; i < groups4c.size(); i++)
	{
		if (e->unknown5cb680(groups4c[i]))
		{
			vector<OpY5_HEntity> *members = groups4c[i]->getMembers();
			for (unsigned int j = 0; j < members->size(); j++)
			{
				if ((*members)[j]->getAI()->unknown458fb0(e))
					return true;
			}
		}
	}
	return false;
}

int OpY5_World::pickRecordBelow71cbf0(int limit)
{
	int index;
	if (!ints_b94.empty())
	{
		for (int i = 0; i < 500; i++)
		{
			index = opS5_randomElement(&ints_b94);
			if (opS5_records_cfd2cc[index]->unknown28 <= limit)
				return index;
		}
	}
	return 0;
}

void OpY5_World::addTrailPoint71ce30(const Point &p)
{
	for (int i = 0; i < 2; i++)
	{
		vector<Point> &list = i == 0 ? points830 : points840;
		int maxSize = 10 + (i != 0) * 2;
		if (!list.empty())
		{
			for (int j = list.size() - 1; j >= 0; j--)
			{
				if (list[j] == p || (list[j].adjacent(p) && j != list.size() - 1))
				{
					opS5_eraseRange(list,j,list.size() - 1);
					goto nextList;
				}
			}
		}
		list.push_back(p);
		if (list.size() > maxSize)
			opS5_eraseAt(list,0);
nextList:;
	}
}

void OpY5_World::unknown71fef0(OpY5_HEntity e)
{
	vector<Point> *footprint = e->getFootprint();
	for (unsigned int i = 0; i < footprint->size(); i++)
	{
		if (grid69c((*footprint)[i]) == 0)
		{
			grid740((*footprint)[i]).unknown0 = unknown74c;
			grid740((*footprint)[i]).unknown4 = 5;
			grid740((*footprint)[i]).entity = e;
			grid740((*footprint)[i]).unknownc = e->unknown45a540((*footprint)[i]);
			grid740((*footprint)[i]).color = e->unknown5c7630();
			points754.push_back((*footprint)[i]);
		}
	}
	opw3_unknown72a0b0(e);
}
