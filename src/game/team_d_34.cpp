// team_d_34: map generation helper 0x6cc8a0 (dig an exit corridor from a room).
// NOTE: names and layouts are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();							// NOTE: placeholder name (0x453b40)
	Point(const Point &p) throw();		// 0x46ca50
	void set(int x_, int y_);			// NOTE: placeholder name (0x40a010)
};

struct Room34	// NOTE: placeholder name (DF::Room, 0x6c bytes)
{
	int				type;
	int				x;
	int				y;
	int				width;
	int				height;
	vector<int>		unknown14;
	int				unknown24;
	vector<Point>	doors;
	vector<int>		doorDirs;
	vector<int>		corridors;
	int				unknown58;
	vector<int>		unknown5c;
	~Room34() throw();	// 0x4bd140
};
extern vector<Room34> rooms34_cf13e8;	// NOTE: placeholder name

struct Corridor34	// NOTE: placeholder name and layout
{
	vector<Point>	path;
	char			pad10[0x10];
};
extern vector<Corridor34> corridors34_cf65c4;	// NOTE: placeholder name

class Cell
{
public:
	bool unknown66a630();	// NOTE: placeholder name
	int getTerrain();		// NOTE: placeholder name (folded getter)
	void unknown66a050(int terrainID, int cause, int flag);	// NOTE: placeholder name
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(const Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

class RNG
{
public:
	int rangeInt(float low, float high);
};
extern RNG rng;

extern int TERRAIN_CAVE_WALL;	// NOTE: placeholder (0xcefba0)
extern int *p_cefb9c;	// NOTE: placeholder name
extern int *p_cefba8;	// NOTE: placeholder name

bool OpS8b_Fn9d51d0(vector<int> &v, int value);	// NOTE: placeholder name (remove value)
int OpU8a_randomRec(vector<unsigned int> &v);	// NOTE: placeholder name (0x9d5d00)
void OpB_translateRotated(Point *pos, int rotation, int dx, int dy);	// NOTE: placeholder name
bool OpD_digCorridor_6cc2b0(int roomIndex, const Point &start, int dir);	// NOTE: placeholder name (0x6cc2b0)

bool OpD_digRoomExit_6cc8a0(int roomIndex, int tries, bool cave)	// NOTE: placeholder name
{
	Point x2;
	Room34 &current = rooms34_cf13e8[roomIndex];
	int value;
	if (current.width >= 3 && current.height >= 3)
	{
	vector<unsigned int> options;
	for (int i = 0; i < 4; i++)
		options.push_back((unsigned int)i);
	for (unsigned int j = 0; j < current.doorDirs.size(); j++)
		OpS8b_Fn9d51d0((vector<int> &)options,current.doorDirs[j]);
	if (!options.empty())
	{
		do
		{
			tries--;
			value = OpU8a_randomRec(options);
			switch (value)
			{
			case 0:
				x2.set(rng.rangeInt(1.0f,(float)(current.width - 2)) + current.x,current.y);
				break;
			case 1:
				x2.set(current.x + current.width - 1,rng.rangeInt(0.0f,(float)(current.height - 1)) + current.y);
				break;
			case 2:
				x2.set(rng.rangeInt(1.0f,(float)(current.width - 2)) + current.x,current.y + current.height - 1);
				break;
			case 3:
				x2.set(current.x,rng.rangeInt(1.0f,(float)(current.height - 2)) + current.y);
				break;
			}
			Point pt(x2);
			OpB_translateRotated(&pt,value,0,1);
			if (!(*cells_cfd44c.atPoint(pt))->unknown66a630())
				continue;
			if (OpD_digCorridor_6cc2b0(roomIndex,x2,value))
			{
				vector<Point> &list = corridors34_cf65c4.back().path;
				if (!cave && list.size() == 1 && (*cells_cfd44c.atPoint(list.back()))->getTerrain() == TERRAIN_CAVE_WALL)
					cave = true;
				(*cells_cfd44c.atPoint(list.front()))->unknown66a050(cave ? *p_cefba8 : *p_cefb9c,2,0);
				if (list.size() > 1)
					(*cells_cfd44c.atPoint(list.back()))->unknown66a050((*cells_cfd44c.atPoint(list.back()))->getTerrain() == TERRAIN_CAVE_WALL ? *p_cefba8 : *p_cefb9c,2,0);
				for (unsigned int k = 1; k < list.size() - 1; k++)
					(*cells_cfd44c.atPoint(list[k]))->unknown66a050(*p_cefb9c,2,0);
				return true;
			}
		}
		while (tries > 0);
	}
	}
	return false;
}
