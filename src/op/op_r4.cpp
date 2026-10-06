// op_r4: functions in 0x6fe000-0x828000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <ostream>
#include <ctype.h>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

class OpY5_Item	// NOTE: placeholder name
{
public:
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
	OpY5_Item *operator->() const;	// 0x9b65b0
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
	Point(const Point &p);	// 0x46ca50
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor (0x46ca50)
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

int opY5_distance(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)

class OpY5_AI	// NOTE: placeholder name
{
public:
	void unknown5b5220();	// NOTE: placeholder name
};

class OpY5_Entity	// NOTE: placeholder name
{
public:
	const Point &getPosition();	// 0x45a4a0
	int getSize();	// 0x45a360
	bool isPlayer();	// 0x5c7600
	OpY5_AI *getAI();	// 0x45b590
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
};

class OpY5_HEntity	// NOTE: placeholder name
{
public:
	int ID;
	OpY5_HEntity();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
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
	bool canPlaceEntity(int size);	// 0x66ad20
	bool fitsProp(void *propData);	// NOTE: placeholder name (0x45d570)
	OpY5_HPropP getProp();	// 0x45d550
	void unknown45e110(bool a, bool b, OpY5_HProp c);	// NOTE: placeholder name
};

class OpY5_Cells	// NOTE: placeholder name (0xcfd44c)
{
public:
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
extern bool opR4_dijkstraFlag_cefc9d;	// NOTE: placeholder name (0xcefc9d)
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

class OpY5_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	int unknown714b50();	// NOTE: placeholder name
	bool findRandomPlaceable(const Point &center, int radius, int size, Point &out, bool checkEntrance);	// NOTE: placeholder name (0x71c300)
	OpY5_HEntity spawn6c5dc0(const string &name, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);	// NOTE: placeholder name (0x6c5dc0)
	bool findPropSpotNear(const Point &p, Point &out, void *propData);	// NOTE: placeholder name (0x71c3c0)
	bool isReachable(int range, const Point &from, const Point &to);	// NOTE: placeholder name (0x465230)
	OpY5_HEntity getEntity671();	// NOTE: placeholder name (0x463110)
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name
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
// op_r4 functions
//==================================================================

class OpR4_TwoVecs	// NOTE: placeholder name
{
public:
	vector<unsigned int> a;
	vector<unsigned int> b;

	~OpR4_TwoVecs();	// 0x700dd0
};

OpR4_TwoVecs::~OpR4_TwoVecs()
{
}

bool OpY5_World::findRandomPlaceable(const Point &center, int radius, int size, Point &out, bool checkEntrance)
{
	OpY5_Area area;
	opY5_cells.getArea(center,radius,area);
	for (int i = 0; i < 20; i++)
	{
		Point pos = area.randomPointRet();
		if (opY5_cells(pos)->canPlaceEntity(size))
		{
			if (!(checkEntrance && opR4_isEntrance(pos)) && isReachable(5,pos,center))
			{
				out = pos;
				return true;
			}
		}
	}
	return false;
}

bool OpY5_World::findPropSpotNear(const Point &p, Point &out, void *propData)
{
	if (!opY5_cells(p)->fitsProp(propData))
	{
		clearDijkstraResults();
		opY5_dijkstra.run(p,12,&opR4_dijkstraCost_d39714,propData);
		if (opY5_dijkstraCells.empty())
			return false;
		else
		{
			findFirstDijkstraRange();
			out = opY5_dijkstraCells[rng.rangeInt(opY5_dijkstraRangeStart,opY5_dijkstraRangeEnd)];
			return true;
		}
	}
	else
	{
		out = p;
		return true;
	}
}

class HExplosive	// NOTE: placeholder name
{
	int ID;
};

class OpR4_ExplosiveVecs	// NOTE: placeholder name
{
public:
	vector<HExplosive> explosives;
	vector<unsigned int> unknown10;	// NOTE: placeholder name

	~OpR4_ExplosiveVecs();	// 0x787710
};

OpR4_ExplosiveVecs::~OpR4_ExplosiveVecs()
{
}

extern bool opR4_flag_d1e880;	// NOTE: placeholder name
extern bool opR4_flag_d28d09;	// NOTE: placeholder name

class OpR4_Obj7784b0	// NOTE: placeholder name
{
public:
	char pad0[0x1a8];
	int unknown1a8;	// NOTE: placeholder name

	bool unknown7784b0();	// NOTE: placeholder name
};

bool OpR4_Obj7784b0::unknown7784b0()
{
	return opR4_flag_d1e880 && opR4_flag_d28d09 && unknown1a8 <= 3;
}

bool opR4_startsWithDoubleDash(const string &s)	// NOTE: placeholder name (0x78fa80)
{
	return s.size() >= 2 && s[0] == '-' && s[1] == '-';
}

bool opR4_inRange(int low, int value, int high);	// NOTE: placeholder name (0x9daf80)

bool opR4_isPrintableNoBacktick(char c)	// NOTE: placeholder name (0x78fb40)
{
	return opR4_inRange(' ',c,'~') && c != '`';
}

bool opR4_startsWithSpaceAlnum(const string &s)	// NOTE: placeholder name (0x78fad0)
{
	return s.size() >= 2 && s[0] == ' ' && (isalpha(s[1]) || isdigit(s[1]));
}

class OpR4_HEntity	// NOTE: placeholder name
{
public:
	bool operator==(OpR4_HEntity other) const;	// 0x45a390
	int ID;
};

class OpR4_ListHolder	// NOTE: placeholder name
{
public:
	char pad0[0x10];
	vector<OpR4_HEntity *> entities;

	bool contains(OpR4_HEntity e);	// NOTE: placeholder name (0x7ac010)
};

bool OpR4_ListHolder::contains(OpR4_HEntity e)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (*entities[i] == e)
			return true;
	}
	return false;
}

void opR4_shuffle(vector<int> &v);	// NOTE: placeholder name (0x9d8f80, template instance)

void opR4_fillShuffled32(vector<int> &v)	// NOTE: placeholder name (0x7ac540)
{
	for (int i = 0; i < 32; i++)
	{
		int value = i;
		v.push_back(value);
	}
	opR4_shuffle(v);
}

class OpR4_Shell	// NOTE: placeholder name (CShell at 0xcec100)
{
public:
	void addPointA8(const vector<Point> &p);	// NOTE: placeholder name (0x4b0e20)
	void addPointB8(const vector<Point> &p);	// NOTE: placeholder name (0x4b0e50)
};
extern OpR4_Shell *opR4_cec100;	// NOTE: placeholder name

class OpR4_MapConsole	// NOTE: placeholder name (object at 0xcec054)
{
public:
	void unknown80e3a0(int type, const Point &p);	// NOTE: placeholder name
};
extern OpR4_MapConsole *opR4_cec054;	// NOTE: placeholder name

void opR4_showPointsA(vector<Point> &points)	// NOTE: placeholder name (0x7949f0)
{
	if (!points.empty())
	{
		if (opR4_cec100 != NULL)
			opR4_cec100->addPointA8(points);
		else
		{
			for (unsigned int i = 0; i < points.size(); i++)
				opR4_cec054->unknown80e3a0(1,points[i]);
		}
	}
}

void opR4_showPointsB(vector<Point> &points)	// NOTE: placeholder name (0x794bd0)
{
	if (!points.empty())
	{
		if (opR4_cec100 != NULL)
			opR4_cec100->addPointB8(points);
		else
		{
			for (unsigned int i = 0; i < points.size(); i++)
				opR4_cec054->unknown80e3a0(1,points[i]);
		}
	}
}

template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0
extern int opR4_default_caf178;	// NOTE: placeholder name (0xcaf178)

class OpR4_Queue	// NOTE: placeholder name
{
public:
	char pad0[0x14];
	vector<int> values;

	int popFront();	// NOTE: placeholder name (0x793090)
};

int OpR4_Queue::popFront()
{
	if (values.empty())
		return opR4_default_caf178;
	int value = values.front();
	removeVectorElement(values,0);
	return value;
}

bool opR4_inVectorPoint(vector<Point> &v, Point p);	// NOTE: placeholder name (0x9d0ce0)

bool opR4_anyContainsPoint(vector<vector<Point> > &lists, const Point &p)	// NOTE: placeholder name (0x6ff530)
{
	for (unsigned int i = 0; i < lists.size(); i++)
	{
		if (opR4_inVectorPoint(lists[i],p))
			return true;
	}
	return false;
}

struct OpR4_ElemA	// NOTE: placeholder name
{
	int value;
};

class OpR4_PointsStrings	// NOTE: placeholder name
{
public:
	int unknown0, unknown4, unknown8;	// NOTE: placeholder names
	vector<Point> points;
	vector<unsigned int> unknown1c;	// NOTE: placeholder name
	vector<OpR4_ElemA> unknown2c;	// NOTE: placeholder name
	vector<OpR4_ElemA> unknown3c;	// NOTE: placeholder name

	~OpR4_PointsStrings();	// 0x7732b0
};

OpR4_PointsStrings::~OpR4_PointsStrings()
{
}

void opR4_spawnRandom(const string &name, int count, int groupIndex)	// NOTE: placeholder name (0x702600)
{
	OpY5_HEntity entity;
	Point p;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			opY5_cells.randomPos(p);
			if (opY5_world->findPlaceableNear(p,p,1))
			{
				entity = opY5_world->spawn6c5dc0(name,p,groupIndex,true,34,14,false);
				break;
			}
		}
	}
}
