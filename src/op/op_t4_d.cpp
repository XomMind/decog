// op_t4_d: map cell area checks (0x6c9000-0x6cc000) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(const Point &p);	// 0x46ca50
	Point(int x_, int y_);	// 0x46ca20
	Point &operator=(const Point &p);	// 0x46ca50
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	T &operator()(int x, int y);	// 0x9ceda0
	bool contains(int x, int y);	// NOTE: placeholder name (0x9b45c0)
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
};

class HProp
{
	int ID;
public:
	bool isValid() const;
};

class HItem
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
};

class HEntity
{
public:
	int ID;
	bool isValid() const;
};

struct CellTerrainRecord	// NOTE: partial record
{
	int ID;
};

class OpT4_Cell	// NOTE: placeholder name
{
public:
	char pad00[0x70];
	OpT4_Cell(CellTerrainRecord *terrain);	// NOTE: placeholder name
	~OpT4_Cell();
	void unknown45dea0(int x, int y);	// NOTE: placeholder name
	HItem getItem();	// 0x45d8f0
	HProp getProp();	// 0x45d550
	HEntity getEntity();
	bool isMachinePart();
	bool isOpen();	// 0x4550b0
	bool unknown45db70();	// NOTE: placeholder name
	bool unknown66a630();	// NOTE: placeholder name
	int unknown45d0e0();	// NOTE: placeholder name
	int getTerrain();	// 0x9fcd80
	bool isEdge();
};
extern Array2D<OpT4_Cell *> opt4_cells;	// NOTE: placeholder name (0xcfd44c)
extern Array2D<int> opt4_entranceMap;	// NOTE: placeholder name (0xcf447c)
extern CellTerrainRecord *opt4_terrainCefb9c;	// NOTE: placeholder name (0xcefb9c)
extern CellTerrainRecord *caveinThirdTerrain;	// NOTE: placeholder type (0xcefba4)
extern int TERRAIN_EARTH;	// NOTE: placeholder (0xcefb80)
extern int TERRAIN_CAVE_WALL;	// NOTE: placeholder (0xcefba0)

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	bool contains(int x_, int y_) const;	// 0x40a9a0
};

extern Array2D<int> originalTerrain;	// NOTE: placeholder type (0xd378c0)

OpT4_Cell *opt4_setTerrain(int x, int y, CellTerrainRecord *terrain)	// NOTE: placeholder name (0x6c9b40)
{
	delete opt4_cells(x,y);
	opt4_cells(x,y) = new OpT4_Cell(terrain);
	opt4_cells(x,y)->unknown45dea0(x,y);
	originalTerrain(x,y) = terrain->ID;
	return opt4_cells(x,y);
}

bool opt4_isAreaEmpty6c9f10(const Point &p, int w, int h, int border)	// NOTE: placeholder name
{
	for (int x = p.x - border; x < p.x + w + border; x++)
	{
		for (int y = p.y - border; y < p.y + h + border; y++)
		{
			if (!opt4_cells.contains(x,y) || opt4_cells(x,y)->getProp().isValid() || opt4_cells(x,y)->getItem().isValid() || opt4_cells(x,y)->isMachinePart() || opt4_cells(x,y)->getEntity().isValid())
				return false;
		}
	}
	return true;
}

bool opt4_isAreaEmpty6ca040(const Point &p, int w, int h, int border)	// NOTE: placeholder name
{
	for (int x = p.x - border; x < p.x + w + border; x++)
	{
		for (int y = p.y - border; y < p.y + h + border; y++)
		{
			if (!opt4_cells.contains(x,y) || opt4_cells(x,y)->getProp().isValid() || opt4_cells(x,y)->getItem().isValid() || (opt4_cells(x,y)->unknown45db70() && !opt4_cells(x,y)->isEdge()))
				return false;
		}
	}
	return true;
}

bool opt4_isRingFree6cb8c0(Rect *r, Rect *inner)	// NOTE: placeholder name
{
	for (int x = r->x - 1; x < r->x + r->width + 1; x++)
	{
		for (int y = r->y - 1; y < r->y + r->height + 1; y++)
		{
			if (!opt4_cells.contains(x,y) || (opt4_cells(x,y)->isOpen() && !inner->contains(x,y)) || opt4_cells(x,y)->unknown45db70() || opt4_cells(x,y)->getProp().isValid() || opt4_cells(x,y)->unknown45d0e0() == caveinThirdTerrain->ID)
				return false;
		}
	}
	return true;
}

void opt4_fillRing6cba00(Rect *r, Rect *inner, int entrance, CellTerrainRecord *wall, bool caveWalls)	// NOTE: placeholder name
{
	for (int x = r->x - 1; x < r->x + r->width + 1; x++)
	{
		for (int y = r->y - 1; y < r->y + r->height + 1; y++)
		{
			if (!inner->contains(x,y))
			{
				if (r->contains(x,y))
				{
					opt4_setTerrain(x,y,opt4_terrainCefb9c);
					opt4_entranceMap(x,y) = entrance;
				}
				else
				{
					if (opt4_cells(x,y)->getTerrain() == TERRAIN_EARTH || (caveWalls && opt4_cells(x,y)->getTerrain() == TERRAIN_CAVE_WALL))
						opt4_setTerrain(x,y,wall);
				}
			}
		}
	}
}

bool opt4_isEdgeClear6c9cb0(int side, Point *pos, int length, int margin, Rect *r)	// NOTE: placeholder name
{
	switch (side)
	{
	case 0:
		{
			pos->y = r->y + r->height - margin;
			int x = pos->x;
			int y = pos->y + margin;
			for (; x < pos->x + length; x++)
			{
				if (opt4_cells(x,y)->isOpen() || opt4_cells(x,y)->unknown45db70())
					return false;
			}
			break;
		}
	case 1:
		{
			pos->x = r->x;
			int y = pos->y;
			int x = pos->x - 1;
			for (; y < pos->y + length; y++)
			{
				if (opt4_cells(x,y)->isOpen() || opt4_cells(x,y)->unknown45db70())
					return false;
			}
			break;
		}
	case 2:
		{
			pos->y = r->y;
			int x = pos->x;
			int y = pos->y - 1;
			for (; x < pos->x + length; x++)
			{
				if (opt4_cells(x,y)->isOpen() || opt4_cells(x,y)->unknown45db70())
					return false;
			}
			break;
		}
	case 3:
		{
			pos->x = r->x + r->width - margin;
			int y = pos->y;
			int x = pos->x + margin;
			for (; y < pos->y + length; y++)
			{
				if (opt4_cells(x,y)->isOpen() || opt4_cells(x,y)->unknown45db70())
					return false;
			}
			break;
		}
	}
	return true;
}

extern int opt4_bb8340[4];	// NOTE: placeholder name
extern int opt4_bb8350[4];	// NOTE: placeholder name
void opt4_translateRotated(Point *pos, int rotation, int dx, int dy);	// NOTE: placeholder name (OpB_translateRotated)

bool opt4_isLinePassable6cc1e0(const Point &start, int dir, int length)	// NOTE: placeholder name
{
	Point pos;
	for (int side = 0; side < 2; side++)
	{
		pos = start;
		for (int i = 0; i < length; i++)
		{
			int rotation;
			if (side)
				rotation = opt4_bb8350[dir];
			else
				rotation = opt4_bb8340[dir];
			opt4_translateRotated(&pos,rotation,0,1);
			if (!opt4_cells.contains(pos) || !opt4_cells(pos)->unknown66a630())
				return false;
		}
	}
	return true;
}
