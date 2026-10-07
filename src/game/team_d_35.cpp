// team_d_35: map generation corridor digger 0x6cc2b0 (dig a winding corridor from a room exit).
// NOTE: names and layouts are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p) throw();		// 0x46ca50
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor (0x46ca50)
};

struct Pos	// NOTE: placeholder layout (an 8-byte value range)
{
	int a;
	int b;

	Pos(int a_, int b_);
	int randomInRange();	// NOTE: folded with Point::randomInRange_40c130
};

struct Rect35	// NOTE: placeholder name
{
	int x;
	int y;
	int width;
	int height;

	bool containsPos(const Point &p);	// NOTE: placeholder name (0x40aa00)
};

struct Room35	// NOTE: placeholder name (DF::Room, 0x6c bytes)
{
	int				type;
	Rect35			rect;
	vector<int>		unknown14;
	int				unknown24;
	vector<Point>	doors;
	vector<int>		doorDirs;
	vector<int>		corridors;
	int				unknown58;
	vector<int>		unknown5c;
	~Room35() throw();	// 0x4bd140
};
extern vector<Room35> rooms35_cf13e8;	// NOTE: placeholder name

struct Corridor35	// NOTE: placeholder name
{
	vector<Point>	path;
	vector<int>		rooms;

	Corridor35();	// NOTE: placeholder name (0x4cd540)
	~Corridor35();
};
extern vector<Corridor35> corridors35_cf65c4;	// NOTE: placeholder name

class HEntity
{
	int ID;
public:
	HEntity();
};

class Cell
{
public:
	bool unknown66a630();	// NOTE: placeholder name
	int *getTerrainRec();	// NOTE: placeholder name (folded getter)
	bool isPassableFor(HEntity e);
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	bool inBounds(int x, int y);	// NOTE: placeholder name (0x9b45c0)
	Cell **atPoint(const Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
	Cell **at(int x, int y);		// NOTE: folded with OpX5_Array2D<int>::at
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

class Grid35	// NOTE: placeholder name (0xcf1964)
{
public:
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
};
extern Grid35 grid35_cf1964;	// NOTE: placeholder name

class IntMap35	// NOTE: placeholder name (0xcf447c)
{
public:
	int *atPoint(const Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
};
extern IntMap35 cellTypes35_cf447c;	// NOTE: placeholder name

class Entity;

class Map35	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	const Point &unknown4184d0();	// NOTE: placeholder name (trivial getter)
	bool unknown716940(const Point &from, const Point &to, Entity *e, unsigned int *length);	// NOTE: placeholder name
};
extern Map35 *world35;	// NOTE: placeholder name (0xcefc4c)

class RNG
{
public:
	int rangeInt(float low, float high);
};
extern RNG rng;

extern int *p_cefb9c;	// NOTE: placeholder name
extern int opposites35_bb8360[4];	// NOTE: placeholder name (opposite direction)
extern vector<int> segmentDirs35_d2e224;	// NOTE: placeholder name
extern vector<int> segmentLengths35_cfb678;	// NOTE: placeholder name

void OpB_translateRotated(Point *pos, int rotation, int dx, int dy);	// NOTE: placeholder name
bool opt4_isLinePassable6cc1e0(const Point &p, int dir, int clearance);	// NOTE: placeholder name
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name

bool OpD_digCorridor_6cc2b0(int roomIndex, const Point &start, int dir)	// NOTE: placeholder name
{
	int flags = 1;
	Pos mode(3,8);
	int count = 3;
	int tail = 0;
	int old = opposites35_bb8360[dir];
	int amount = count;
	Point cur(start);
	int key;
	int next;
	int total;
	segmentDirs35_d2e224[tail] = dir;
	segmentLengths35_cfb678[tail] = 0;
	while (amount != 0)
	{
		amount--;
		key = mode.randomInRange();
		while (key != 0)
		{
			key--;
			OpB_translateRotated(&cur,dir,0,1);
			segmentLengths35_cfb678[tail]++;
			if (!grid35_cf1964.contains(cur))
				return false;
			if ((*cells_cfd44c.atPoint(cur))->getTerrainRec() == p_cefb9c)
			{
				if (!(*cells_cfd44c.atPoint(cur))->isPassableFor(HEntity()) || !world35->unknown716940(cur,world35->unknown4184d0(),NULL,NULL))
					return false;
				Corridor35 data;
				corridors35_cf65c4.push_back(data);
				vector<Point> &path = corridors35_cf65c4.back().path;
				cur = start;
				path.push_back(cur);
				for (int s = 0; s <= tail; s++)
				{
					for (int k = 0; k < segmentLengths35_cfb678[s]; k++)
					{
						OpB_translateRotated(&cur,segmentDirs35_d2e224[s],0,1);
						path.push_back(cur);
					}
				}
				total = -1;
				cur = path.back();
				for (unsigned int r = 0; r < rooms35_cf13e8.size(); r++)
				{
					if (rooms35_cf13e8[r].rect.containsPos(cur))
					{
						total = r;
						break;
					}
				}
				if (path.size() == 4)
				{
					corridors35_cf65c4.pop_back();
					return false;
				}
				else
				{
					corridors35_cf65c4.back().rooms.push_back(roomIndex);
					rooms35_cf13e8[roomIndex].corridors.push_back(corridors35_cf65c4.size() - 1);
					if (total != -1)
					{
						corridors35_cf65c4.back().rooms.push_back(total);
						rooms35_cf13e8[total].corridors.push_back(corridors35_cf65c4.size() - 1);
					}
					OpQ5_eraseAt(path,0);
					path.pop_back();
					for (unsigned int m = 0; m < path.size(); m++)
						*cellTypes35_cf447c.atPoint(path[m]) = 5;
					return true;
				}
			}
			if (!opt4_isLinePassable6cc1e0(cur,dir,flags))
				return false;
		}
		next = opposites35_bb8360[dir];
		do
		{
			dir = rng.rangeInt(0.0f,3.0f);
		}
		while (dir == old || dir == next);
		if (opposites35_bb8360[dir] != next)
		{
			Point q(cur);
			if (!cells_cfd44c.inBounds(cur.x - 1,cur.y - 1) || !(*cells_cfd44c.at(cur.x - 1,cur.y - 1))->unknown66a630()
				|| !cells_cfd44c.inBounds(cur.x + 1,cur.y - 1) || !(*cells_cfd44c.at(cur.x + 1,cur.y - 1))->unknown66a630()
				|| !cells_cfd44c.inBounds(cur.x - 1,cur.y + 1) || !(*cells_cfd44c.at(cur.x - 1,cur.y + 1))->unknown66a630()
				|| !cells_cfd44c.inBounds(cur.x + 1,cur.y + 1) || !(*cells_cfd44c.at(cur.x + 1,cur.y + 1))->unknown66a630())
				return false;
		}
		tail++;
		segmentDirs35_d2e224[tail] = dir;
		segmentLengths35_cfb678[tail] = 0;
	}
	return false;
}
