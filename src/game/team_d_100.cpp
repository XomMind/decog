// team_d_100: member 0x658a70 of the shot state (caller SEntityShoot::update; +0x10 is the shooter): picks the
// actual impact cell of an inaccurate shot. For the player the target first snaps to the first blocking cell on
// the line of fire; then a random offset within a radius that grows with distance is drawn, rejecting offsets
// that are zero, unlikely axis-aligned, outside the radius, on the origin, or (for up to 1000 tries) on the line.
// NOTE: class layouts are partial; member and method names are placeholders.
// NOTE: local names (and the declaration order of the function-scope ones) follow the stack-slot hash order;
// the empty-bodied radius searches are written as for(;;) with an explicit break to get the exe's jump shape.
// The called helpers are declared throw() because the exe gives the first line stepper no EH state.
// NOTE: the point, stepper, cell, world and handle classes carry file-unique names (Point100 etc.) so the full
// build links stubs rather than real definitions that LTCG cannot prove nothrow.
#include <vector>
using namespace std;

struct Point100
{
	int x;
	int y;

	Point100() throw();								// 0x453b40
	Point100(const Point100 &p) throw();					// 0x46ca50
	Point100(const Point100 &a, const Point100 &b) throw();	// NOTE: placeholder (0x4099f0, a + b)
	Point100 &operator=(const Point100 &p) throw();		// NOTE: folded with the copy constructor
	bool operator==(const Point100 &p) const throw();	// 0x409b90
	bool operator!=(const Point100 &p) const throw();	// 0x409bd0
	void set(int x_, int y_) throw();				// NOTE: placeholder name (0x40a010)
};
extern Point100 effectOrigin100;	// NOTE: placeholder name (0xd2e20c)

class Stepper100
{
protected:
	int	errorX;
	int	errorY;
	int	deltaX2;
	int	deltaY2;
	int	stepX;
	int	stepY;
	int	deltaX;
	int	deltaY;
	int	x;
	int	y;

public:
	virtual ~Stepper100() {};
};

class StepperSub100 : public Stepper100
{
	int	subcells;

public:
	StepperSub100(const Point100 &fromCell, const Point100 &fromSubcell, const Point100 &toCell, const Point100 &toSubcell, int subcells_);
	virtual ~StepperSub100();
	bool next(Point100 &cell, Point100 &subcell) throw();	// NOTE: placeholder name
};

int halfProduct_406460(int a, int b, int c);	// NOTE: placeholder name
int opw8_distance(int x1, int y1, int x2, int y2);	// NOTE: placeholder name (0x406480)
int OpQ1_distanceCeil_40a3f0(const Point100 &a, const Point100 &b) throw();	// NOTE: placeholder name
bool OpV4c_Fn9d0ce0_100(vector<Point100> &list, Point100 p);	// NOTE: placeholder name

class Entity100;

class HEntity100
{
public:
	int ID;
	HEntity100();
	Entity100 *operator->() const throw();
	bool isNull100() const throw();		// NOTE: placeholder name (0x9b65d0)
	bool isValid100() const throw();	// NOTE: placeholder name (0x9b7230)
};

class Entity100
{
public:
	bool isPlayer();
};

class Cell100
{
public:
	HEntity100 getEntity() throw();
	bool unknown4550b0() throw();	// NOTE: placeholder name (folded getter Sweep_4550b0::getField)
	bool unknown45d480() throw();	// NOTE: placeholder name
};

class CellGrid100	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell100 **atPoint(const Point100 &p) throw();	// NOTE: folded (OpX5_Array2D<int>::atPoint)
	bool contains(const Point100 &p) throw();	// NOTE: folded (OpR5h_Grid::contains)
};
extern CellGrid100 cells100_cfd44c;	// NOTE: placeholder name

class World100
{
public:
	bool unknown7170a0(HEntity100 e, const Point100 &p, vector<Point100> &path, vector<int> &hits, vector<int> &blocks, Point100 &last, const Point100 *at, int atMode, bool f1, bool f2);
	bool isVisible(const Point100 &p) throw();
};
extern World100 *world100_cefc4c;	// NOTE: placeholder name

class RNG
{
public:
	int rangeInt(float lo, float hi);
};
extern RNG rng;

class Shot100	// NOTE: placeholder name and layout
{
public:
	char	pad00[0x10];
	HEntity100	shooter;	// +0x10

	Point100 unknown658a70(const Point100 &origin, Point100 target, float spread);	// NOTE: placeholder name
};

Point100 Shot100::unknown658a70(const Point100 &origin, Point100 target, float spread)
{
	if (shooter->isPlayer())
	{
		bool selected = false;
		vector<Point100> path;
		vector<int> hits;
		vector<int> walls;
		Point100 last;
		world100_cefc4c->unknown7170a0(shooter,target,path,hits,walls,last,0,4,true,true);
		if (path.size() >= 2)
		{
			for (unsigned int i = 0; i < path.size() - 1; i++)
			{
				if (hits[i] != 0)
				{
					target = path[i];
					selected = true;
					break;
				}
			}
		}
		if (!selected && (*cells100_cfd44c.atPoint(target))->getEntity().isNull100() && world100_cefc4c->isVisible(target) && (*cells100_cfd44c.atPoint(target))->unknown4550b0())
		{
			Point100 temp;
			Point100 prev;
			Point100 cur;
			StepperSub100 step(origin,effectOrigin100,target,effectOrigin100,9);
			prev = origin;
			step.next(cur,temp);
			while (cur == origin)
				step.next(cur,temp);
			while (!step.next(cur,temp))
			{
				if (prev != cur)
				{
					if (!cells100_cfd44c.contains(cur))
					{
						cur.x = -1;
						break;
					}
					if ((*cells100_cfd44c.atPoint(cur))->getEntity().isValid100() || (*cells100_cfd44c.atPoint(cur))->unknown45d480() || !world100_cefc4c->isVisible(cur))
					{
						target = cur;
						break;
					}
					prev = cur;
				}
			}
		}
	}
	int yy;
	int max;
	vector<Point100> tiles;
	int weightSum;
	int choice;
	int tries;
	int maxRange = 25;
	Point100 head;
	Point100 back;
	Point100 end;
	StepperSub100 edge(origin,effectOrigin100,target,effectOrigin100,9);
	back = origin;
	edge.next(end,head);
	while (end == origin)
		edge.next(end,head);
	while (!edge.next(end,head))
	{
		if (back != end)
		{
			if (!cells100_cfd44c.contains(end))
			{
				end.x = -1;
				break;
			}
			tiles.push_back(end);
			if (OpQ1_distanceCeil_40a3f0(origin,end) >= maxRange)
				break;
			back = end;
		}
	}
	int dist = OpQ1_distanceCeil_40a3f0(origin,target);
	int radius = (int)(dist * spread + 1.0);
	int step;
	Point100 pick;
	int ox;
	weightSum = halfProduct_406460(1,radius + 1,radius + 1);
	max = radius * radius;
	tries = 0;
	do
	{
		choice = rng.rangeInt(0.0f,(float)(weightSum - 1));
		for (ox = 1; ; ox++, choice -= step)
		{
			step = radius - ox + 2;
			if (choice < step)
				break;
		}
		choice = rng.rangeInt(0.0f,(float)(weightSum - 1));
		for (yy = 1; ; yy++, choice -= step)
		{
			step = radius - yy + 2;
			if (choice < step)
				break;
		}
		ox--;
		yy--;
		ox *= rng.rangeInt(0.0f,1.0f) ? -1 : 1;
		yy *= rng.rangeInt(0.0f,1.0f) ? -1 : 1;
		pick.set(ox,yy);
		tries++;
	} while ((pick.x == 0 && pick.y == 0) || ((pick.x == 0 || pick.y == 0) && rng.rangeInt(1.0f,5.0f) <= 2) || opw8_distance(0,0,pick.x,pick.y) > max || Point100(target,pick) == origin || (OpV4c_Fn9d0ce0_100(tiles,Point100(target,pick)) && tries < 1000));
	return Point100(target,pick);
}
