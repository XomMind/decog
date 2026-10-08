// team_d_124: Overmind member 0x683b60 (callers three unnamed spawn routines): spawns a robot of the given
// spawn type - at a random free cell, near the player's arrival points (announcing it), or at a placement
// found by the Overmind's position search. Returns the new robot, or a null handle.
// NOTE: class layouts are partial; names are placeholders. The helpers called while the local point list is
// alive are declared throw() under file-unique names (the exe gives that list no EH state); local names
// follow the stack-slot hash order.
#include <vector>
using namespace std;

struct Point124	// NOTE: placeholder name (Point)
{
	int x;
	int y;

	Point124() throw();							// 0x453b40
	Point124(const Point124 &p) throw();		// 0x46ca50
	Point124 &operator=(const Point124 &p) throw();	// NOTE: folded with the copy constructor
};

struct Pos124	// NOTE: placeholder name (Pos)
{
	int x;
	int y;

	Pos124(int v);	// 0x409990
};

Point124 OpU8a_randomPoint124(vector<Point124> &v) throw();	// NOTE: placeholder name (OpU8a_randomPoint)
template <class T> void OpQ5_eraseStep124(vector<T> &list, int &index) throw();	// NOTE: placeholder name (OpQ5_eraseStep)
bool terrainFlagB_448b80(const Point124 &p);	// NOTE: placeholder name
void opR1d_454260(const Point124 &p, int id);	// NOTE: placeholder name

class Entity124;	// NOTE: placeholder name

class HEntity124	// NOTE: placeholder name (HEntity)
{
public:
	int ID;
	HEntity124();
	Entity124 *operator->() const;
	bool isValid() const;	// NOTE: folded with HItem::isValid
};

class HProp
{
public:
	int ID;
	HProp();
};

struct PropData124	// NOTE: placeholder name and layout
{
	char	pad00[0x28];
	int		unknown28;	// +0x28
	char	pad2c[0x38 - 0x2c];
	int		unknown38;	// +0x38
};

class Prop124	// NOTE: placeholder name (Prop)
{
public:
	PropData124 *getData124() throw();	// NOTE: placeholder name (folded getter, 0x45cb30)
};

class HProp124	// NOTE: placeholder name (HProp)
{
public:
	int ID;
	HProp124();
	Prop124 *operator->() const throw();	// NOTE: OpC_Handle::get22c
};

class Cell124	// NOTE: placeholder name (Cell)
{
public:
	bool canPlaceEntity(int size);
	HProp124 getProp124() throw();	// NOTE: placeholder name (Cell::getProp)
};

class CellGrid124	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell124 **atPoint(Point124 &p) throw();	// NOTE: folded (OpX5_Array2D<int>::atPoint)
	void getRandom_9cf0c0(Point124 *out);	// NOTE: placeholder name
};
extern CellGrid124 cells124_cfd44c;	// NOTE: placeholder name

class Entity124
{
public:
	void *getName124();	// NOTE: placeholder name (folded getter XCell::getFore, +0x0c)
};

struct EntityRecord124	// NOTE: placeholder name and layout
{
	char	pad00[0x9c];
	int		size;	// +0x9c
};

class World124	// NOTE: placeholder name (BS at 0xcefc4c)
{
public:
	EntityRecord124 *unknown6c5600(int a, int b, bool c, bool d);	// NOTE: placeholder name
	vector< vector<Point124> > *unknown459070();	// NOTE: placeholder name
	HEntity124 placeEntity(EntityRecord124 *record, const Point124 &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
};
extern World124 *world124_cefc4c;	// NOTE: placeholder name
extern int spawnTypes124_caf1cc[];	// NOTE: placeholder name

class ConsoleA124	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA124 *consoleA124_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs124_cec0b4;	// NOTE: placeholder name

bool showMessage124(int id, const void *text, const void *b, int c, HProp d, HProp e, const Point124 *at, int flag);	// NOTE: placeholder name (0x5111e0)

class Overmind124	// NOTE: placeholder name (Overmind)
{
public:
	bool unknown683500(Point124 &pos, int a, int b, int c, Pos124 *p, int *d, int e, int f);	// NOTE: placeholder name
	HEntity124 unknown683b60(int type, bool random, bool *nearPlayer);	// NOTE: placeholder name
};

HEntity124 Overmind124::unknown683b60(int type, bool random, bool *nearPlayer)
{
	EntityRecord124 *first = world124_cefc4c->unknown6c5600(1,spawnTypes124_caf1cc[type],false,false);
	if (!first)
		return HEntity124();
	Point124 pt;
	int n = 0;
	bool visible = false;
	if (random)
	{
		for (int i = 0; i < 100; i++)
		{
			cells124_cfd44c.getRandom_9cf0c0(&pt);
			if ((*cells124_cfd44c.atPoint(pt))->canPlaceEntity(first->size) && !terrainFlagB_448b80(pt))
			{
				visible = true;
				break;
			}
		}
	}
	else
	{
		if (nearPlayer && *nearPlayer)
		{
			vector<Point124> pts((*world124_cefc4c->unknown459070())[1]);
			for (int j = 0; j < pts.size(); j++)
			{
				if ((*cells124_cfd44c.atPoint(pts[j]))->getProp124()->getData124()->unknown38 != 0 || (*cells124_cfd44c.atPoint(pts[j]))->getProp124()->getData124()->unknown28 == -2)
					OpQ5_eraseStep124(pts,j);
			}
			if (!pts.empty())
			{
				pt = OpU8a_randomPoint124(pts);
				visible = true;
				*nearPlayer = true;
			}
			else
				*nearPlayer = false;
		}
		if (!visible && unknown683500(pt,0,0,0,&Pos124(-1),&n,0,0))
			visible = true;
	}
	if (visible)
	{
		HEntity124 e = world124_cefc4c->placeEntity(first,pt,4,random,0x22,0xe,false);
		if (e.isValid() && nearPlayer && *nearPlayer)
		{
			do
			{
				if (showMessage124(0x1c3,e->getName124(),0,0,HProp(),HProp(),&pt,0))
					consoleA124_cec058->unknown8758d0(true);
				logMsgs124_cec0b4->scrollToEnd();
			} while (0);
			opR1d_454260(pt,0x86);
		}
		return e;
	}
	else
		return HEntity124();
}
