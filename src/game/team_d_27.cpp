// team_d_27: EntityAI member 0x5b9860 (choose a random reachable destination near the leader).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p) throw();	// 0x46ca50
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor (0x46ca50)
	bool operator==(const Point &p) const;	// 0x409b90
};

class Entity;
class EntityAI;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	Entity *operator->() const;
	void reset();	// 0x9b7270
};

class Entity
{
public:
	int getSize();
	bool isPlayer();		// 0x5c7600
	Point unknown45a4c0();	// NOTE: placeholder name
	EntityAI *getAI();		// 0x45b590
	Point &getPosition();	// 0x45a4a0
};

class Cell
{
public:
	bool isPassableFor(HEntity e);
	bool canCaveIn();
	bool unknown66b3d0(Entity *e);	// NOTE: placeholder name
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(const Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

class Map	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	void unknown71cc70(HEntity e, Point &p);	// NOTE: placeholder name
	bool unknown4631f0(HEntity e);				// NOTE: placeholder name
	bool unknown4633c0(const Point &p);			// NOTE: placeholder name
};
extern Map *world;	// NOTE: placeholder name (0xcefc4c)

class Cartographer2DMoveCost;

class Cartographer2D	// NOTE: placeholder layout (global at 0xcfe568)
{
public:
	void unknown40ca20(const Point &start, int range, void *cost, int *data);	// NOTE: placeholder name (Dijkstra fill)
	bool findPath(const Point &start, const Point &goal, Cartographer2DMoveCost *cost, void *data, vector<Point> &path);
};
extern Cartographer2D cartographer_cfe568;	// NOTE: placeholder name

struct DijkstraCost27 { int unknown00; };	// NOTE: placeholder name
extern DijkstraCost27 dijkstraCost_cefd1c;	// NOTE: placeholder name
extern DijkstraCost27 dijkstraCost_d1e1dc;	// NOTE: placeholder name
extern vector<Point> dijkstraCells_d15e58;	// NOTE: placeholder name
extern vector<Point> vec_d2d4f4;	// NOTE: placeholder name (a copy of the Dijkstra cells)
extern bool flag_cefb15;	// NOTE: placeholder name
extern Cartographer2DMoveCost *moveCost_cefc30;	// NOTE: placeholder name

void clearDijkstraResults();
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);
int OpX5_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)
template <class T> int OpQ5_randomIndex(vector<T> &v);	// NOTE: placeholder name
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name

class EntityAI
{
public:
	HEntity self;						// +0
	char pad04[0x10 - 0x04];
	Point unknown10;					// NOTE: placeholder name
	char pad18[0x24 - 0x18];
	vector<Point> unknown24;			// NOTE: placeholder name (path)
	char pad34[0x58 - 0x34];
	HEntity unknown58;					// NOTE: placeholder name (leader)
	bool unknown5c;						// NOTE: placeholder name
	int unknown60;						// NOTE: placeholder name
	int unknown64;						// NOTE: placeholder name
	int unknown68;						// NOTE: placeholder name

	bool findPathToGoal();				// 0x5b8d20
	bool unknown5b9860();				// NOTE: placeholder name
};

bool EntityAI::unknown5b9860()
{
	clearDijkstraResults();
	int maxRange = self->getSize();
	bool player = unknown58->isPlayer();
	int tries = player ? 1 : 0;
	Point loc = unknown58->unknown45a4c0();
	if (player)
		world->unknown71cc70(self,loc);
	else if (unknown5c && unknown58->getAI()->unknown10.x != -1 && !unknown58->getAI()->unknown24.empty() && unknown58->getAI()->unknown24.back() == unknown58->getAI()->unknown10)
		loc = unknown58->getAI()->unknown24[OpX5_minInt(8,unknown58->getAI()->unknown24.size() - 1)];
	bool done = player && OpQ1_distanceCeil_40a3f0(self->getPosition(),loc) > 10 && !world->unknown4631f0(self);
	bool result = false;
	do
	{
		if (player)
		{
			cartographer_cfe568.unknown40ca20(loc,(unknown60 ? 3 : 3) * 2 + 2,&dijkstraCost_cefd1c,&maxRange);
			if (flag_cefb15)
				vec_d2d4f4 = dijkstraCells_d15e58;
		}
		else
			cartographer_cfe568.unknown40ca20(loc,(unknown60 ? 3 : 3) * 2 + 2,&dijkstraCost_d1e1dc,&maxRange);
		while (!dijkstraCells_d15e58.empty())
		{
			int index = OpQ5_randomIndex(dijkstraCells_d15e58);
			unknown10 = dijkstraCells_d15e58[index];
			if ((*cells_cfd44c.atPoint(unknown10))->isPassableFor(self) && (!tries || !(*cells_cfd44c.atPoint(unknown10))->canCaveIn())
				&& (!player || !(*cells_cfd44c.atPoint(unknown10))->unknown66b3d0(self.operator->()))
				&& (!unknown60 || !player || world->unknown4633c0(unknown10)))
			{
				if (findPathToGoal())
				{
					unknown64 = 0;
					unknown68 = unknown60 ? 8 : 8;
					return true;
				}
				else
					result = true;
			}
			OpQ5_eraseAt(dijkstraCells_d15e58,index);
			if (done)
				break;
		}
	}
	while (--tries >= 0);
	unknown10.x = -1;
	if (!player && result)
	{
		unknown64++;
		if (unknown64 >= 2)
		{
			vector<Point> path;
			if (!cartographer_cfe568.findPath(self->getPosition(),loc,moveCost_cefc30,NULL,path))
				unknown58.reset();
		}
	}
	return false;
}
