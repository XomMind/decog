// op_x4a: map generation helpers (Builder / Xom) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
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
	int unknown4578c0();	// NOTE: placeholder name
	void *getEffect(int type);	// NOTE: placeholder name (0x457b70)
	int unknown457f90();	// NOTE: placeholder name
	int unknown457820();	// NOTE: placeholder name
	string unknown571db0(bool a, bool b);	// NOTE: placeholder name
	int unknown9fcd80();	// NOTE: placeholder name (folded getter of the first field)
};

class OpY5_HItem	// NOTE: placeholder name
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
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
	OpY5_Area(int x1, int y1, int x2, int y2);	// NOTE: placeholder signature (0x40b1e0)
	bool contains(const Point &p);	// NOTE: placeholder name (0x40b750)
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
	int unknown5c92e0(int slot);	// NOTE: placeholder name
	unsigned int unknown5cb8b0(vector<OpY5_HItem> *out);	// NOTE: placeholder name
	void unknown642940(OpY5_HItem item, int a, int b, int c, int d);	// NOTE: placeholder name
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
	OpY5_HPropP getProp();	// 0x45d550
	void unknown45e110(bool a, bool b, OpY5_HProp c);	// NOTE: placeholder name
};

class OpY5_Cells	// NOTE: placeholder name (0xcfd44c)
{
public:
	OpY5_Cell *&operator()(int x, int y);	// 0x9ceda0
	OpY5_Cell *&operator()(const Point &p);	// 0x9ced70
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
void clearDijkstraResults();
void findFirstDijkstraRange();

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

struct OpQ5_U9d7a40	// NOTE: placeholder name
{
	char pad0[0x44];
	int unknown44;	// NOTE: placeholder name
	char pad48[0x4c - 0x48];
	int unknown4c;	// NOTE: placeholder name
	char pad50[0x234 - 0x50];
	int unknown234;	// NOTE: placeholder name
};
extern vector<OpQ5_U9d7a40 *> opY5_itemTypes;	// NOTE: placeholder name (0xd2d1c4)
extern int opY5_table_ba3acc[];	// NOTE: placeholder name
bool opY5_inVector(vector<int> &v, int value);	// NOTE: placeholder name (0x9db330)
int opY5_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)

class OpY5_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	int unknown714b50();	// NOTE: placeholder name
	OpY5_HEntity getEntity671();	// NOTE: placeholder name (0x463110)
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name
	OpY5_HEntity getPlayer();	// 0x4630f0
	OpY5_HGroup getGroup(int type);	// NOTE: placeholder name (0x463890)
	OpY5_HItem unknown6c51d0(OpQ5_U9d7a40 *type, OpY5_HEntity e, bool a, bool b);	// NOTE: placeholder name
	void unknown71cf70();	// NOTE: placeholder name
	void unknown734560(OpY5_HEntity e, int a, bool b);	// NOTE: placeholder name
	bool isVisible(const Point &p);	// 0x4631c0
	vector<OpY5_HEntity> *getEntities();	// NOTE: placeholder name (0x4636f0)
	bool unknown4631f0(OpY5_HEntity e);	// NOTE: placeholder name
	bool findPlaceableNearWide(const Point &p, Point &out, int size);	// NOTE: placeholder name (0x71c200)
	int unknown726600(const Point &p);	// NOTE: placeholder name
	const Point &unknown4184d0();	// NOTE: placeholder name (trivial getter)
	bool unknown716940(const Point &from, const Point &to, void *e, unsigned int *length);	// NOTE: placeholder name
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

class OpY5_MapConsole	// NOTE: placeholder name (object at 0xcec054)
{
public:
	void unknown49adc0(int time);	// NOTE: placeholder name
	void unknown8119c0(OpY5_HItem item, int a, int b, int c);	// NOTE: placeholder name
};
extern OpY5_MapConsole *opY5_mapConsole;	// NOTE: placeholder name

string intToString(int value);
extern string gameStrings_d206a0[];

struct OpY5_GameState	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	int depth;	// NOTE: placeholder name
};

class OpY5_HGameState	// NOTE: placeholder name
{
public:
	int ID;
	OpY5_GameState *operator->() const;	// 0x9b7910
};
extern OpY5_HGameState opY5_gameState;	// NOTE: placeholder name (0xd1e888)


bool opY5_logMessage(int id, const string &text, const string *b, int c, OpY5_HEntity d, OpY5_HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)

class OpX4a_Parts	// NOTE: placeholder name (object at 0xcec088)
{
public:
	bool isLinked4a9b10(OpY5_HItem item);	// NOTE: placeholder name
	void *unknown894e70(OpY5_HItem item);	// NOTE: placeholder name
	void unknown8993e0(void *part, int a);	// NOTE: placeholder name
};
extern OpX4a_Parts *opx4a_parts;	// NOTE: placeholder name (0xcec088)

class OpX4a_GM	// NOTE: placeholder name (object at 0xd25628)
{
public:
	void addItemAttachCount(int itemID, int count, bool force);	// 0x778560
};
extern OpX4a_GM opx4a_gm;	// NOTE: placeholder name (0xd25628)
extern vector<int> opx4a_cf47cc;	// NOTE: placeholder name

template <class T> bool opx4a_findByName(vector<T*> &v, const string &name, T *&result);	// NOTE: placeholder name (0x9d7a40)
void opx4a_eraseStep(vector<OpY5_HItem> &v, unsigned int &index);	// NOTE: placeholder name (0x9d6440)
void opx4a_shuffle(vector<OpY5_HItem> &v);	// NOTE: placeholder name (0x9d9fc0)
void opx4a_moveElement(vector<OpY5_HItem> &v, unsigned int from, unsigned int to);	// NOTE: placeholder name (0x9da1f0)

class OpY5_Builder	// NOTE: placeholder name (map generation)
{
public:
	char pad0[0x158];
	bool unknown158;	// NOTE: placeholder name
	char pad159[0x1c1 - 0x159];
	bool wallPoked;	// NOTE: placeholder name

	int getDepthTier(int &depth);	// NOTE: placeholder name
	void renameJunkItem(OpY5_HItem item);	// NOTE: placeholder name
	void showShift(const Point &pos, OpY5_HEntity e);	// NOTE: placeholder name
	void showXomAct(bool good, OpY5_HEntity e, const Point *pos);	// NOTE: placeholder name
	bool findXomTargets(vector<OpY5_HEntity> &targets);	// NOTE: placeholder name
	void pokeWall();	// NOTE: placeholder name
	OpY5_HEntity findXom();	// NOTE: placeholder name
	void giveXomItems(OpY5_HEntity e);	// NOTE: placeholder name
	bool placeEntityNear(const OpY5_Range &rangeIn, Point *pos, OpY5_HEntity e, bool a, bool b);	// NOTE: placeholder name
	bool unknown69f580(Point &out, const OpY5_Range &rangeIn, int step);	// NOTE: placeholder name
	bool unknown69f810(Point &out, const OpY5_Range &rangeIn, int step, int minValue, int divisor);	// NOTE: placeholder name
	bool unknown69fa80(Point *pos);	// NOTE: placeholder name
	bool unknown69fc60(bool flag, string *outName);	// NOTE: placeholder name
};

extern OpY5_Range opY5_range_d20858;	// NOTE: placeholder name

bool OpY5_Builder::unknown69f580(Point &out, const OpY5_Range &rangeIn, int step)
{
	OpY5_Range range(rangeIn);
	Point origin(opY5_world->getPlayer()->getPosition());
	int startCost = opY5_world->unknown726600(origin);
	if (startCost == 0)
		return false;
	OpY5_Area zone;
	opY5_cells.getArea(origin,range.max,zone);
	bool found = false;
	const int attempts = 500;
	vector<OpY5_Area> regions;
	if (opY5_gameState->unknown4 == 0x22)
	{
		regions.push_back(OpY5_Area(0x8d,0xc,0xad,0x2f));
		regions.push_back(OpY5_Area(0x8d,0x66,0xad,0x89));
	}
retry:
	for (int i = 0; i < 500; i++)
	{
		zone.randomPoint(&out);
		if (range.contains(opY5_distance(origin,out)) && opY5_cells(out)->canPlaceEntity(1))
		{
			for (unsigned int index = 0; index < regions.size(); index++)
			{
				if (regions[index].contains(out))
					goto next;
			}
			{
				int cost = opY5_world->unknown726600(out);
				if (cost == 0 || (i >= 250 && cost < startCost))
				{
					if (opY5_world->unknown716940(out,opY5_world->unknown4184d0(),NULL,NULL))
					{
						found = true;
						break;
					}
				}
			}
		}
	next:;
	}
	if (!found)
	{
		range.shift(-step);
		if (range.min < step)
			return false;
		goto retry;
	}
	else
		return true;
}

bool OpY5_Builder::unknown69f810(Point &out, const OpY5_Range &rangeIn, int step, int minValue, int divisor)
{
	int widenings = 0;
	OpY5_Range range(rangeIn);
	Point origin(opY5_world->getPlayer()->getPosition());
	OpY5_Area zone;
	opY5_cells.getArea(origin,range.max,zone);
	bool found = false;
	const int attempts = 500;
	vector<OpY5_Area> regions;
	if (opY5_gameState->unknown4 == 0x22)
	{
		regions.push_back(OpY5_Area(0x8d,0xc,0xad,0x39));
		regions.push_back(OpY5_Area(0x8d,0x5c,0xad,0x89));
	}
retry:
	for (int i = 0; i < 500; i++)
	{
		zone.randomPoint(&out);
		if (range.contains(opY5_distance(origin,out)) && opY5_cells(out)->canPlaceEntity(1))
		{
			for (unsigned int index = 0; index < regions.size(); index++)
			{
				if (regions[index].contains(out))
					goto next;
			}
			{
				int cost = opY5_world->unknown726600(out) / divisor;
				if (cost >= minValue)
				{
					if (opY5_world->unknown716940(out,opY5_world->unknown4184d0(),NULL,NULL))
					{
						found = true;
						break;
					}
				}
			}
		}
	next:;
	}
	if (!found)
	{
		range.shift(step);
		widenings++;
		if (widenings > 3)
			return false;
		goto retry;
	}
	else
		return true;
}

bool OpY5_Builder::unknown69fa80(Point *pos)
{
	OpY5_HEntity cogmind = opY5_world->getPlayer();
	Point loc;
	if (pos != NULL)
		loc = *pos;
	else if (!unknown69f580(loc,opY5_range_d20858,10))
		return false;
	cogmind->unknown5ddac0(loc,true);
	if (opY5_world->getEntity671().isValid())
	{
		Point p(-1);
		if (opY5_world->findPlaceableNear(loc,p,opY5_world->getEntity671()->getSize()))
			opY5_world->getEntity671()->changePos(p,true);
	}
	OpY5_HEntity xom = findXom();
	if (xom.isValid())
	{
		Point p(-1);
		if (opY5_world->findPlaceableNear(loc,p,xom->getSize()) || opY5_world->findPlaceableNearWide(loc,p,xom->getSize()))
			xom->changePos(p,true);
	}
	opY5_world->unknown71cf70();
	opY5_world->unknown734560(cogmind,-2,false);
	if (opY5_world->getEntity671().isValid())
		opY5_world->unknown734560(opY5_world->getEntity671(),-2,false);
	return true;
}

bool OpY5_Builder::unknown69fc60(bool flag, string *outName)
{
	OpQ5_U9d7a40 *type;
	opx4a_findByName(opY5_itemTypes,"Sfc. Transmogrifier",type);
	OpY5_HEntity player = opY5_world->getPlayer();
	if (player->unknown5c92e0(2) == 0)
	{
		vector<OpY5_HItem> items;
		player->unknown5cb8b0(&items);
		for (unsigned int i = 0; i < items.size(); i++)
		{
			if (items[i]->unknown4578a0() != 2 || items[i]->getEffect(0x6c) != NULL || (items[i]->unknown457f90() == 7 && !flag) || items[i]->unknown457f90() == 0xb7 || items[i]->unknown457f90() == 0xd6 || opx4a_parts->isLinked4a9b10(items[i]))
				opx4a_eraseStep(items,i);
		}
		if (items.empty())
			return false;
		opx4a_shuffle(items);
		for (int j = items.size() - 2; j >= 0; j--)
		{
			if (items[j]->unknown4578c0() > 1 || items[j]->unknown457f90() == 7)
				opx4a_moveElement(items,j,items[j]->unknown4578c0() - 1);
		}
		opY5_mapConsole->unknown8119c0(items.front(),1,0,1);
		if (!flag)
		{
			do
			{
				if (opY5_logMessage(0x2bb,items.front()->unknown571db0(false,false),0,0,player,OpY5_HProp(),0,0))
					opY5_cec058->unknown8758d0(true);
				opY5_logMsgs->scrollToEnd();
			} while (false);
		}
		renameJunkItem(items.front());
		player->unknown642940(items.front(),1,1,0,0);
	}
	OpY5_HItem item = opY5_world->unknown6c51d0(type,player,true,false);
	if (item.isValid())
	{
		opx4a_cf47cc.push_back(item->unknown9fcd80());
		opx4a_gm.addItemAttachCount(item->unknown457820(),1,false);
		void *part = opx4a_parts->unknown894e70(item);
		if (part != NULL)
			opx4a_parts->unknown8993e0(part,0);
		if (outName != NULL)
			*outName = "X0-1V1: \"Let's take things to the next level.\"";
		do { opY5_unknown5141b0(0x9d,0,0,0,OpY5_HProp(),0); } while (0);
		unknown158 = true;
		return true;
	}
	else
		return false;
}
