// op_y5: map generation helpers in 0x6a0000-0x7b0000 matched against COGMIND.exe (Beta 17.1).
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

class OpY5_MapConsole	// NOTE: placeholder name (object at 0xcec054)
{
public:
	void unknown49adc0(int time);	// NOTE: placeholder name
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

class OpY5_Builder	// NOTE: placeholder name (map generation)
{
public:
	char pad0[0x1c1];
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
};

int OpY5_Builder::getDepthTier(int &depth)
{
	int tier;
	depth = opY5_world->unknown714b50();
	if (depth == 0)
		tier = 1;
	else if (depth <= 9)
		tier = 2;
	else if (depth <= 19)
		tier = 3;
	else if (depth <= 29)
		tier = 4;
	else
		tier = 5;
	return tier;
}

void OpY5_Builder::renameJunkItem(OpY5_HItem item)
{
	if (rng.chance(7) && !item->unknown4579d0())
	{
		OpY5_WeightedStrings names;
		names.add("junk",100);
		names.add("trash",100);
		names.add("Recycler bait",100);
		names.add("of trash",100);
		names.add("of uselessness",100);
		names.add("slightly used",100);
		names.add("previously owned",100);
		names.add("former owner didn't need it",100);
		names.add("lost and found",100);
		names.add("you don't need this",100);
		names.add("leave here for good luck",100);
		names.add("of dropping",100);
		names.add("of corruption",100);
		names.add("definitely not a mimic",10);
		item->unknown458700(names.pick());
	}
}

bool OpY5_Builder::placeEntityNear(const OpY5_Range &rangeIn, Point *pos, OpY5_HEntity e, bool a, bool b)
{
	Point loc;
	if (pos != NULL)
		loc = *pos;
	else
	{
		OpY5_Range distance(rangeIn);
		Point start(e->getPosition());
		OpY5_Area area;
		opY5_cells.getArea(start,distance.max,area);
		bool found = false;
		const int attempts = 500;
	retry:
		for (int i = 0; i < 500; i++)
		{
			area.randomPoint(&loc);
			if (distance.contains(opY5_distance(start,loc)) && opY5_cells(loc)->canPlaceEntity(e->getSize()))
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			distance.shift(-10);
			if (distance.min < 1)
				return false;
			goto retry;
		}
	}
	e->unknown5ddac0(loc,true);
	if (e->isPlayer())
	{
		if (opY5_world->getEntity671().isValid() && opY5_distance(e->getPosition(),opY5_world->getEntity671()->getPosition()) > 20)
		{
			Point p(-1);
			if (opY5_world->findPlaceableNear(loc,p,opY5_world->getEntity671()->getSize()))
				opY5_world->getEntity671()->changePos(p,true);
		}
		opY5_world->unknown71cf70();
	}
	if (a && e->getAI() != NULL)
		e->getAI()->unknown5b5220();
	if (b)
	{
		opY5_world->unknown734560(e,-2,false);
		if (e->isPlayer() && opY5_world->getEntity671().isValid())
			opY5_world->unknown734560(opY5_world->getEntity671(),-2,false);
	}
	return true;
}

bool OpY5_World::findPlaceableNear(const Point &p, Point &out, int size)
{
	if (!opY5_cells(p)->canPlaceEntity(size))
	{
		clearDijkstraResults();
		opY5_dijkstra.run(p,12,&opY5_dijkstraCost_d1e1dc,&size);
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

void OpY5_Builder::showShift(const Point &pos, OpY5_HEntity e)
{
	if (opY5_world->isVisible(pos))
	{
		string text = e->isPlayer() ? string("Form shifts and blurs.") : e->getNameAt0c() + " form shifts and blurs.";
		OPY5_LOG(800,text);
		int effectID;
		if (findEffectID("Xom_Disappear",&effectID))
			opY5_effectMgr->create()->init(opY5_effectMgr,effectID,pos,opY5_effectOrigin,0,0,0,9,0);
	}
	if (opY5_world->unknown4631f0(e))
	{
		string text = e->isPlayer() ? string("Form resolidifies at new position.") : e->getNameAt0c() + " form resolidifies at new position.";
		OPY5_LOG(800,text);
		int effectID;
		if (findEffectID("Xom_Appear",&effectID))
			opY5_effectMgr->create()->init(opY5_effectMgr,effectID,e->getPosition(),opY5_effectOrigin,0,0,0,9,0);
	}
}

void OpY5_Builder::showXomAct(bool good, OpY5_HEntity e, const Point *pos)
{
	int effectID;
	if (findEffectID(good ? "Xom_Act_Good" : "Xom_Act_Bad",&effectID))
	{
		if (pos != NULL)
			opY5_effectMgr->create()->init(opY5_effectMgr,effectID,*pos,opY5_effectOrigin,0,0,0,9,0);
		else
		{
			vector<Point> *footprint = e->getFootprint();
			for (unsigned int i = 0; i < footprint->size(); i++)
				opY5_effectMgr->create()->init(opY5_effectMgr,effectID,(*footprint)[i],opY5_effectOrigin,0,0,0,9,0);
		}
	}
	if (e.isValid() && e->isPlayer())
		opY5_cec138->unknown9666d0();
}

bool OpY5_Builder::findXomTargets(vector<OpY5_HEntity> &targets)
{
	vector<OpY5_HEntity> *entities = opY5_world->getEntities();
	if (entities->empty())
		return false;
	vector<int> scores;
	for (unsigned int i = 0; i < entities->size(); i++)
	{
		if ((*entities)[i].get() != NULL && (*entities)[i]->getEffect(0x3a) == NULL)
		{
			int value = (*entities)[i]->unknown5cccc0();
			if (targets.empty() || value < scores.back())
			{
				targets.push_back((*entities)[i]);
				scores.push_back(value);
			}
			else
			{
				for (unsigned int j = 0; j < targets.size(); j++)
				{
					if (value >= scores[j])
					{
						opY5_insertAt(targets,j,(*entities)[i]);
						opY5_insertAt(scores,j,value);
						break;
					}
				}
			}
		}
	}
	for (int i = targets.size() - 2; i >= 0; i--)
	{
		if (!targets[i]->isXomCandidate())
		{
			opY5_moveTo(targets,i,targets.size() - 1);
			opY5_moveTo(scores,i,scores.size() - 1);
		}
	}
	return targets.size();
}

void OpY5_Builder::pokeWall()
{
	if (wallPoked)
		return;
	wallPoked = true;
	if (rng.chance(50))
		return;
	if (opY5_cells(9,20)->getProp().isValid())
		opY5_cells(9,20)->getProp()->unknown45ce10(true,false,true,OpY5_HProp());
	if (opY5_cells(9,30)->getProp().isValid())
		opY5_cells(9,30)->getProp()->unknown45ce10(true,false,true,OpY5_HProp());
	for (int y = 21; y <= 29; y++)
	{
		if (opY5_cells(8,y)->getProp().isValid())
			opY5_cells(8,y)->getProp()->unknown45ce10(true,false,true,OpY5_HProp());
		opY5_cells(8,y)->unknown45e110(true,true,OpY5_HProp());
	}
	OPY5_LOG_AT(0x2b9,string("X0-1V1 pokes a wall."),&opY5_world->getPlayer()->getPosition());
	do { opY5_unknown5141b0(0xc4,0,0,0,OpY5_HProp(),0); } while (0);
	opY5_mapConsole->unknown49adc0(1000);
}

OpY5_HEntity OpY5_Builder::findXom()
{
	vector<OpY5_HEntity> *members = opY5_world->getGroup(2)->getMembers();
	for (unsigned int i = 0; i < members->size(); i++)
	{
		if ((*members)[i]->getFaction() == 0x42 && (*members)[i]->getEffect(0x3a) != NULL && ((*members)[i]->getName()[0] == 'C' || (*members)[i]->getName()[0] == 'G'))
			return (*members)[i];
	}
	return OpY5_HEntity();
}

void OpY5_Builder::giveXomItems(OpY5_HEntity e)
{
	for (unsigned int i = 0; i < e->getInventoryList()->size(); i++)
	{
		if ((*e->getInventoryList())[i]->unknown4578a0() == 3)
		{
			(*e->getInventoryList())[i]->unknown57dbe0(0,0,1,1);
			i--;
		}
	}
	OpY5_WeightedList<int> category;
	category.add(0,25);
	category.add(1,70);
	category.add(2,5);
	vector<int> slots;
	switch (category.pick())
	{
		case 0:
			slots.push_back(20);
			slots.push_back(22);
			break;
		case 1:
			slots.push_back(21);
			slots.push_back(23);
			break;
		case 2:
			slots.push_back(24);
			break;
	}
	OpY5_WeightedList<int> itemTypes;
	for (unsigned int i = 0; i < opY5_itemTypes.size(); i++)
	{
		if (opY5_itemTypes[i]->unknown234 != 0 && opY5_inVector(slots,opY5_itemTypes[i]->unknown44))
			itemTypes.addUnique((int)opY5_itemTypes[i],opY5_table_ba3acc[opY5_itemTypes[i]->unknown234]);
	}
	OpY5_ItemType *type = (OpY5_ItemType *)itemTypes.pick();
	int value = e->unknown448fe0(3);
	int quantity = opY5_minInt(3,value / type->unknown4c);
	for (int i = 0; i < quantity; i++)
	{
		OpY5_HItem item = opY5_world->unknown6c51d0(type,e,true,false);
		item->unknown57bff0(0x6d,true);
		e->unknown64da50(item);
	}
}

string opY5_getIntelLabel(int index)	// NOTE: placeholder name
{
	switch (index)
	{
		case 13:
			return string(gameStrings_d206a0[index] + intToString(opY5_gameState->depth));
		case 14:
			return string(gameStrings_d206a0[index] + intToString(opY5_gameState->depth - 1));
	}
	return gameStrings_d206a0[index];
}
