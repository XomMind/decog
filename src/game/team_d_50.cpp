// team_d_50: Cell member 0x66d580 (cave-in at a cell).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;
};

class Entity;

class HEntity
{
	int ID;
public:
	bool isValid() const;
	bool isNull() const;
	Entity *operator->() const;
};

class HProp
{
	int ID;
public:
	HProp();
};

class Entity
{
public:
	int unknown45acb0(int type);	// NOTE: placeholder name
	bool isPlayer();				// 0x5c7600
	void unknown5fd5c0();			// NOTE: placeholder name
	int getSize();
	void changePos(const Point &p, int a);
};

class Item
{
public:
	string unknown571db0(int a, int b);	// NOTE: placeholder name (item name)
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class HItem
{
	int ID;
public:
	Item *operator->() const;
};

struct TerrainRec50	// NOTE: placeholder name and layout
{
	int		ID;
	char	pad04[0x44 - 0x04];
	int		unknown44;	// NOTE: placeholder name
};

class Cell
{
public:
	TerrainRec50	*terrain;	// +0x00
	char			pad04[0x30 - 0x04];
	Point			pos;		// +0x30
	bool			caveIn;		// +0x38, NOTE: placeholder name
	char			pad39[0x48 - 0x39];
	HEntity			entity;		// +0x48
	vector<HItem>	items;		// +0x4c

	bool isPassableFor(HEntity e);
	HEntity getEntity();
	bool unknown4550b0();			// NOTE: placeholder name (folded getter)
	void *unknown45d180();			// NOTE: placeholder name
	void unknown66a050(int terrainID, int cause, int flag);	// NOTE: placeholder name
	void unknown66b700(int a, void *b);	// NOTE: placeholder name
	void unknown66d580(bool silent);	// NOTE: placeholder name
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(const Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

class Effect50	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class EffectMgr50	// NOTE: placeholder name (0xcefc50)
{
public:
	Effect50 *create();	// NOTE: placeholder name (0x508610)
};
extern EffectMgr50 *effectMgr50_cefc50;	// NOTE: placeholder name
extern Point point_d2e20c;	// NOTE: placeholder name
extern int *terrain50_cefb84;	// NOTE: placeholder name
extern int *TERRAIN_EARTH;	// NOTE: placeholder

class RNG
{
public:
	int rangeInt(float low, float high);
};
extern RNG rng;

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
bool logMessageP_5111e0(int id, int a, int b, int c, HProp d, HProp e, const Point &pos, int g);	// NOTE: placeholder name (0x5111e0)
bool logMessageSP_5111e0(int id, const string &text, int b, int c, HProp d, HProp e, const Point &pos, int g);	// NOTE: placeholder name (0x5111e0)
int opR1d_4542a0(const Point &pos, int sound, int volume);	// NOTE: placeholder name
bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980)
void sweepGetSurroundingCells(const Point &point, vector<Point> &adjacent);
template <class T> void OpV4c_shuffle(vector<T> &v);	// NOTE: placeholder name

void Cell::unknown66d580(bool silent)
{
	if (!caveIn)
		return;
	if (!silent)
		do { if (logMessageP_5111e0(0x22a,0,0,0,HProp(),HProp(),pos,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
	bool heard = opR1d_4542a0(pos,0xab,0x14);
	if (entity.isValid())
	{
		if (!entity->unknown45acb0(0x1d) && (!silent || !entity->isPlayer()))
			entity->unknown5fd5c0();
		if (heard)
		{
			int anim;
			OpU8a_lookup2("CMap_Cavein_Hit_E",&anim);
			if (anim)
				effectMgr50_cefc50->create()->init(effectMgr50_cefc50,anim,pos,point_d2e20c,NULL,NULL,NULL,9,0);
		}
		if (!silent && entity.operator->() && entity->getSize() == 1)
		{
			vector<Point> adj;
			sweepGetSurroundingCells(pos,adj);
			OpV4c_shuffle(adj);
			while (!adj.empty())
			{
				if ((*cells_cfd44c.atPoint(adj.back()))->isPassableFor(entity) && (*cells_cfd44c.atPoint(adj.back()))->getEntity().isNull())
				{
					entity->changePos(adj.back(),1);
					break;
				}
				else
					adj.pop_back();
			}
		}
	}
	if (entity.isNull())
	{
		if (silent)
			unknown66a050(*terrain50_cefb84,6,0);
		else
			unknown66a050(*TERRAIN_EARTH,6,0);
		while (!items.empty())
		{
			do { if (logMessageSP_5111e0(0x22b,items.front()->unknown571db0(0,0),0,0,HProp(),HProp(),pos,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
			items.front()->unknown57dbe0(0,1,1,1);
		}
	}
	if (caveIn)
	{
		unknown66b700(0,&terrain->unknown44);
	}
	else
	{
		vector<Point> list;
		sweepGetSurroundingCells(pos,list);
		OpV4c_shuffle(list);
		int total = rng.rangeInt(1.0f,3.0f);
		do
		{
			while (!list.empty() && !(*cells_cfd44c.atPoint(list.back()))->unknown4550b0())
				list.pop_back();
			if (list.empty())
				break;
			else
			{
				(*cells_cfd44c.atPoint(list.back()))->unknown66b700(0,(*cells_cfd44c.atPoint(list.back()))->unknown45d180());
				list.pop_back();
			}
		}
		while (--total && !list.empty());
	}
}
