// team_d_37: map generation placement helper 0x6cbb40 (find a wall-side strip for a room of a given terrain type).
// NOTE: names and layouts are placeholders.
#include <vector>
#include <stdlib.h>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();							// NOTE: placeholder name (0x453b40)
	Point(const Point &p) throw();		// 0x46ca50
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor (0x46ca50)
};

struct Area37	// NOTE: placeholder name (OpS8c_Area)
{
	int x;
	int y;
	int width;
	int height;

	Area37(const Area37 &a) throw();
};

struct Rect37	// NOTE: placeholder name
{
	int x;
	int y;
	int width;
	int height;

	Rect37(const Area37 &a) throw();	// NOTE: placeholder name (0x40a720)
	Point topLeft() const;				// NOTE: placeholder name (PushBounds::topLeft)
	void randomPos(Point *out) const;	// NOTE: placeholder name (0x40b000)
};

struct Room37	// NOTE: placeholder name (DF::Room, 0x6c bytes)
{
	int				type;
	Area37			rect;
	vector<int>		unknown14;
	int				unknown24;
	vector<Point>	doors;
	vector<int>		doorDirs;
	vector<int>		corridors;
	int				unknown58;
	vector<int>		unknown5c;
	~Room37() throw();	// 0x4bd140
};
extern vector<Room37> rooms37_cf13e8;	// NOTE: placeholder name
extern vector<Area37> boxes37_d222f0;	// NOTE: placeholder name

class HItem
{
	int ID;
public:
	bool isValid() const;
};

struct Marker37	// NOTE: placeholder name and layout
{
	Point	pos;
	char	pad08[0x18 - 0x08];
	HItem	item;	// +0x18
};

class Cell
{
public:
	int unknown45d0e0();	// NOTE: placeholder name (terrain id)
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	void getRandom(Point *out);		// NOTE: placeholder name (0x9cf0c0)
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
	Cell **atPoint(const Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

class IntMap37	// NOTE: placeholder name (0xcf1964)
{
public:
	int *atPoint(const Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
};
extern IntMap37 cellTypes37_cf1964;	// NOTE: placeholder name

class Map37	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	const Point &unknown4184d0();			// NOTE: placeholder name (trivial getter)
	vector<vector<Point> > *unknown459070();	// NOTE: placeholder name (trivial getter)
	vector<Marker37 *> *unknown462e10();	// NOTE: placeholder name (trivial getter)
};
extern Map37 *world37;	// NOTE: placeholder name (0xcefc4c)

class RNG
{
public:
	int rangeInt(float low, float high);
};
extern RNG rng;

extern int *TERRAIN_CAVE_WALL;	// NOTE: placeholder (0xcefba0)

int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);
int OpX5_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)
bool terrainFlagC_448ba0(const Point &p);	// NOTE: placeholder name
Area37 OpS8c_randomArea(vector<Area37> &v);	// NOTE: placeholder name
Room37 OpX5_randomElem(vector<Room37> &v);	// NOTE: placeholder name
void OpB_translateRotated(Point *pos, int rotation, int dx, int dy);	// NOTE: placeholder name
bool opt4_isRingFree6cb8c0(Rect37 *r, Rect37 *inner);	// NOTE: placeholder name

bool OpD_findWallStrip_6cbb40(int length, int depth, int type, Rect37 *strip, Rect37 *room, int *outDir, int minDistance, bool avoidMarkers, bool avoidItems)	// NOTE: placeholder name
{
	Point pt;
	Point pick;
	Point point;
	Point dest;
	Point vec;
	for (int i = 0; i < 100; i++)
	{
		switch (type)
		{
		case 4:
			cells_cfd44c.getRandom(&pt);
			if (*cellTypes37_cf1964.atPoint(pt) != type)
				continue;
			break;
		case 6:
			{
				if (boxes37_d222f0.empty())
				{
					type = 4;
					continue;
				}
				const Rect37 &box = OpS8c_randomArea(boxes37_d222f0);
				if (terrainFlagC_448ba0(box.topLeft()))
					continue;
				box.randomPos(&pt);
			}
			break;
		case 7:
			{
				if (rooms37_cf13e8.empty())
				{
					type = 4;
					continue;
				}
				const Rect37 &area = OpX5_randomElem(rooms37_cf13e8).rect;
				if (area.x == -1 || terrainFlagC_448ba0(area.topLeft()))
					continue;
				area.randomPos(&pt);
			}
			break;
		}
		if (minDistance && OpQ1_distanceCeil_40a3f0(pt,world37->unknown4184d0()) <= minDistance)
			continue;
		if (avoidMarkers)
		{
			bool found = false;
			vector<Point> &distances = (*world37->unknown459070())[5];
			for (unsigned int j = 0; j < distances.size(); j++)
			{
				if (OpQ1_distanceCeil_40a3f0(pt,distances[j]) <= 0x32)
				{
					found = true;
					break;
				}
			}
			if (found)
				continue;
		}
		if (avoidItems)
		{
			bool hits = false;
			vector<Marker37 *> *enemies = world37->unknown462e10();
			for (unsigned int k = 0; k < enemies->size(); k++)
			{
				if ((*enemies)[k]->item.isValid() && OpQ1_distanceCeil_40a3f0(pt,(*enemies)[k]->pos) <= 0x28)
				{
					hits = true;
					break;
				}
			}
			if (hits)
				continue;
		}
		for (int d = 0; d < 4; d++)
		{
			pick = pt;
			for (int s = 0; s < 5; s++)
			{
				OpB_translateRotated(&pick,d,0,1);
				if (!cells_cfd44c.contains(pick))
					break;
				if ((*cells_cfd44c.atPoint(pick))->unknown45d0e0() == *TERRAIN_CAVE_WALL)
				{
					point = pick;
					OpB_translateRotated(&point,d,0,-1);
					int width = rng.rangeInt(0.0f,(float)(length + 2));
					int len2 = length + 2 - width;
					bool done = true;
					dest = point;
					for (int m = 0; m < width; m++)
					{
						OpB_translateRotated(&dest,d,-1,0);
						if (!cells_cfd44c.contains(dest) || *cellTypes37_cf1964.atPoint(dest) != type)
						{
							done = false;
							break;
						}
					}
					if (done)
					{
						vec = point;
						for (int n = 0; n < len2; n++)
						{
							OpB_translateRotated(&vec,d,1,0);
							if (!cells_cfd44c.contains(vec) || *cellTypes37_cf1964.atPoint(vec) != type)
							{
								done = false;
								break;
							}
						}
					}
					if (done)
					{
						strip->x = OpX5_minInt(dest.x,vec.x);
						strip->y = OpX5_minInt(dest.y,vec.y);
						strip->width = (d == 1 || d == 3) ? 1 : abs(vec.x - dest.x) + 1;
						strip->height = (d == 0 || d == 2) ? 1 : abs(vec.y - dest.y) + 1;
						switch (d)
						{
						case 0:
							room->x = strip->x + 1;
							room->y = strip->y - depth;
							break;
						case 1:
							room->x = strip->x + 1;
							room->y = strip->y + 1;
							break;
						case 2:
							room->x = strip->x + 1;
							room->y = strip->y + 1;
							break;
						case 3:
							room->x = strip->x - depth;
							room->y = strip->y + 1;
							break;
						}
						room->width = (d == 0 || d == 2) ? length : depth;
						room->height = (d == 1 || d == 3) ? length : depth;
						if (opt4_isRingFree6cb8c0(room,strip))
						{
							*outDir = d;
							return true;
						}
					}
					break;
				}
			}
		}
	}
	return false;
}
