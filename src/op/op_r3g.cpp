// op_r3g: map generation functions in 0x6d0000-0x6fe000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(const Point &p);	// 0x46ca50
	Point(int x_, int y_);	// 0x46ca20
	Point(const Point &p, int dx, int dy);	// 0x4099c0
	Point &operator=(const Point &p);
};

int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
bool OpR3g_addUnique_9d3020(vector<Point> &v, Point p);	// NOTE: placeholder name (0x9d3020)
bool OpR3g_contains_9d0ce0(vector<Point> &v, Point p);	// NOTE: placeholder name (0x9d0ce0)
Point OpR3g_randomPoint_9d5350(vector<Point> &v);	// NOTE: placeholder name (0x9d5350)

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	T &operator()(int x, int y);	// 0x9ceda0
	bool contains(int x, int y);	// NOTE: placeholder name (0x9b45c0)
	Point unknown9cf050();	// NOTE: placeholder name (random point)
	int getWidth();	// NOTE: placeholder name (0x9fcd80)
	int getHeight();	// NOTE: placeholder name (0x9b8f00)
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
	bool isNull() const;
	class Entity *operator->() const;	// 0x9b6570
};

class EntityAI
{
public:
	void setFollowEntity(HEntity followEntity_, int followParam_);	// 0x5b2f80
};

class Entity
{
public:
	const Point &getPosition();	// 0x45a4a0
	EntityAI *getAI();	// NOTE: placeholder name (0x45b590)
};

class HProp
{
	int	ID;
public:
	bool isNull() const;
	class OpR3g_Prop *operator->() const;	// 0x9b64f0
};

class OpR3g_Prop	// NOTE: placeholder name
{
public:
	const Point &unknown4184d0();	// NOTE: placeholder name (trivial getter)
};

struct OpR3g_ItemData	// NOTE: placeholder name
{
	char pad00[0x128];
	int unknown128;	// NOTE: placeholder name
};

class Item
{
public:
	int unknown457880();	// NOTE: placeholder name (ICF'd getter)
	OpR3g_ItemData *unknown9b4350();	// NOTE: placeholder name (ICF'd getter)
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown450460(int value);	// NOTE: placeholder name (ICF'd trivial setter)
};

class HItem
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
	Item *operator->() const throw();	// 0x9b65b0
};

class ItemDef;

class OpR3g_Cell	// NOTE: placeholder name
{
public:
	HItem getItem();	// 0x45d8f0
	bool isOpen();	// NOTE: placeholder name (0x4550b0)
	int unknown9fcd80();	// NOTE: placeholder name (folded getter)
	HProp getProp();	// 0x45d550
};
extern Array2D<OpR3g_Cell *> opr3g_cells;	// NOTE: placeholder name (0xcfd44c)
extern int opr3g_terrainCefb84;	// NOTE: placeholder name (0xcefb84)

struct OpR3g_MapRecord	// NOTE: placeholder name
{
	char pad00[0xa8];
	int unknownA8;	// NOTE: placeholder name
};
extern vector<OpR3g_MapRecord *> opr3g_mapRecords;	// NOTE: placeholder name (0xd21afc)
extern int opr3g_tableB9fce0[][3];	// NOTE: placeholder name (0xb9fce0)

class BS	// NOTE: placeholder name (the object behind the global at 0xcefc4c)
{
public:
	bool unknown6dd0e0(const Point &p, int type);	// NOTE: placeholder name
	bool unknown6c6b90(const Point &p, const string &type, int a, int b);	// NOTE: placeholder name
	HEntity unknown6c5dc0(const string &name, const Point &pos, int a, int b, int c, int d, int e);	// NOTE: placeholder name
	void unknown6c65a0(HEntity e, const string &text, int value);	// NOTE: placeholder name
	void unknown6dfc00(int unused);	// NOTE: placeholder name
	ItemDef *selectRandomItem(int chanceType, int rating, int category);	// 0x6c3bc0
	HItem unknown6c5400(ItemDef *type, const Point &p);	// NOTE: placeholder name
	void unknown6e2b40();	// NOTE: placeholder name
	void unknown6e9480();	// NOTE: placeholder name
	void unknown6ed450();	// NOTE: placeholder name
	bool unknown71bc10(const Point &p, Point &out);	// NOTE: placeholder name

	char pad00[0x66c];
	HEntity player;	// NOTE: placeholder name
	char pad670[0xa90 - 0x670];
	vector<Point> unknownA90;	// NOTE: placeholder name
	vector<int> unknownAA0;	// NOTE: placeholder name
	vector<int> unknownAB0;	// NOTE: placeholder name
};
extern BS *opr3g_world;	// NOTE: placeholder name (0xcefc4c)
extern vector<vector<HProp> > opr3g_trapsByD20248;	// NOTE: placeholder name (0xd20248)

bool OpR3g_unknown6d4b80(const Point &p)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < opr3g_trapsByD20248.size(); i++)
	{
		if (OpQ1_distanceCeil_40a3f0(p,opr3g_trapsByD20248[i].front()->unknown4184d0()) < 20)
		{
			if (rng.chance(90))
				return true;
		}
	}
	return false;
}

bool OpR3g_unknown6ddec0(int x, int y)	// NOTE: placeholder name
{
	if (opr3g_cells.contains(x,y - 1) && opr3g_cells(x,y - 1)->isOpen())
		return false;
	if (opr3g_cells.contains(x,y + 1) && opr3g_cells(x,y + 1)->isOpen())
		return false;
	if (opr3g_cells.contains(x - 1,y) && opr3g_cells(x - 1,y)->isOpen())
		return false;
	if (opr3g_cells.contains(x + 1,y) && opr3g_cells(x + 1,y)->isOpen())
		return false;
	return true;
}

bool OpR3g_unknown6ddfe0(int x, int y)	// NOTE: placeholder name
{
	if (!OpR3g_unknown6ddec0(x,y))
		return false;
	if (opr3g_cells.contains(x - 1,y - 1) && opr3g_cells(x - 1,y - 1)->isOpen())
		return false;
	if (opr3g_cells.contains(x - 1,y + 1) && opr3g_cells(x - 1,y + 1)->isOpen())
		return false;
	if (opr3g_cells.contains(x + 1,y - 1) && opr3g_cells(x + 1,y - 1)->isOpen())
		return false;
	if (opr3g_cells.contains(x + 1,y + 1) && opr3g_cells(x + 1,y + 1)->isOpen())
		return false;
	return true;
}

bool BS::unknown6dd0e0(const Point &p, int type)
{
	if (OpR3g_contains_9d0ce0(unknownA90,p))
		return false;
	unknownA90.push_back(p);
	unknownAA0.push_back(opr3g_tableB9fce0[type][0]);
	unknownAB0.push_back(type);
	return true;
}

void OpR3g_unknown6de130(Point &p, vector<Point> &out)	// NOTE: placeholder name
{
	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			if (dx != 0 || dy != 0)
			{
				if (opr3g_cells(p.x + dx,p.y + dy)->unknown9fcd80() != opr3g_terrainCefb84 && OpR3g_unknown6ddfe0(p.x + dx,p.y + dy))
					OpR3g_addUnique_9d3020(out,Point(p,dx,dy));
			}
		}
	}
}

bool OpR3g_unknown6de200(vector<Point> &candidates, int index)	// NOTE: placeholder name
{
	if (opr3g_mapRecords[index]->unknownA8 == 0)
	{
	}
	else
	{
		int i = 0;
		do
		{
			Point p = OpR3g_randomPoint_9d5350(candidates);
			if (opr3g_cells(p)->isOpen() && opr3g_cells(p)->getProp().isNull())
			{
				opr3g_world->unknown6c6b90(p,"",opr3g_mapRecords[index]->unknownA8,-1);
				return true;
			}
			i++;
		} while (i < 10);
	}
	return false;
}

extern bool opr3g_flagD1e880;	// NOTE: placeholder name
extern bool opr3g_flagD257e8;	// NOTE: placeholder name
extern bool opr3g_flagD1eaac;	// NOTE: placeholder name

void BS::unknown6dfc00(int unused)
{
	if (opr3g_flagD1e880 && (!opr3g_flagD257e8 || rng.chance(5)) && !opr3g_flagD1eaac)
	{
		HEntity e = unknown6c5dc0("Guerilla_7",player->getPosition(),9,1,0x22,0xe,0);
		if (e.isValid())
		{
			e->getAI()->setFollowEntity(player,0);
			unknown6c65a0(e,"SUB_Entrance_Dialogue",0);
			if (!opr3g_flagD257e8 || rng.chance(50))
			{
				unknown6c6b90(Point(0,0),"SUB_Entrance_Battle",0,-1);
			}
			opr3g_flagD257e8 = true;
		}
	}
}

extern int opr3g_gameModeCf462c;	// NOTE: placeholder name (0xcf462c)

void BS::unknown6e2b40()
{
	if (opr3g_gameModeCf462c == 4)
	{
		for (int x = 0; x < opr3g_cells.getWidth(); x++)
		{
			for (int y = 0; y < opr3g_cells.getHeight(); y++)
			{
				if (opr3g_cells(x,y)->getItem().isValid() && opr3g_cells(x,y)->getItem()->unknown457880() == 20 && opr3g_cells(x,y)->getItem()->unknown9b4350()->unknown128 == 3)
				{
					ItemDef *item = selectRandomItem(0,0x16,0x12);
					if (item)
					{
						opr3g_cells(x,y)->getItem()->unknown57dbe0(0,1,1,1);
						unknown6c5400(item,Point(x,y));
					}
				}
			}
		}
	}
}

void BS::unknown6e9480()
{
	if (opr3g_gameModeCf462c == 8)
	{
		HEntity e = unknown6c5dc0("Tinkerer",Point(59,48),8,1,1,14,0);
		if (e.isNull())
			return;
		unknown6c65a0(e,"FL_Dialogue_CET_Hist",0);
	}
}

void BS::unknown6ed450()
{
	Point p;
	for (int i = 0; i < 300; i++)
	{
		ItemDef *item = selectRandomItem(0,0x1f,0x12);
		if (item == NULL)
			continue;
		for (int j = 0; j < 50; j++)
		{
			if (unknown71bc10(opr3g_cells.unknown9cf050(),p))
			{
				HItem it = unknown6c5400(item,p);
				if (it.isValid())
				{
					if (it->unknown457880() == 0)
						it->unknown450460(rng.rangeInt(50,200));
					break;
				}
			}
		}
	}
}
