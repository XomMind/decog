// team_d_80: BS member 0x6c2230 (called from BS::initilize): picks a spawn point away from the map's
// markers, preferring unused finished rooms, then unused junctions, then any non-wall open cell.
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p) throw();			// 0x46ca50
	Point &operator=(const Point &p);		// NOTE: folded with the copy constructor (0x46ca50)
};

struct Pos : public Point
{
	Pos(int v);	// 0x409990
	Pos &operator=(const Point &p);	// NOTE: folded with Point's copy constructor (0x46ca50)
};

struct Bounds80	// NOTE: placeholder name (PushBounds)
{
	int x;
	int y;
	int width;
	int height;

	Point center() const;	// NOTE: placeholder name (PushBounds::center)
	Point topLeft() const;	// NOTE: placeholder name (PushBounds::topLeft)
};

struct Room80	// NOTE: placeholder name and layout (E24_0)
{
	Bounds80		bounds;		// +0x00
	int				unknown10;
	vector<int>		junctions;	// +0x14

	bool isDone();				// NOTE: placeholder name (Tunnel_448bc0::isDone)
};
extern vector<Room80> rooms80_d1f31c;	// NOTE: placeholder name

struct Junction80	// NOTE: placeholder name and layout (Elem_9e3be0)
{
	int			unknown00;
	Bounds80	bounds;		// +0x04
	char		pad14[0x58 - 0x14];
	int			size;		// +0x58
	char		pad5c[0x60 - 0x5c];
};
extern vector<Junction80> junctions80_cf13e8;	// NOTE: placeholder name
extern int minSize80_ced228;	// NOTE: placeholder name

struct Location80	// NOTE: placeholder name and layout
{
	int unknown00;
	int type;
};

class HLoc80	// NOTE: placeholder name
{
	int ID;
public:
	Location80 *operator->() const;
};

struct Marker80	// NOTE: placeholder name and layout (OpQ5_T9da9f0)
{
	Point	pos;	// +0x00
	HLoc80	loc;	// +0x08
};

class Grid80	// NOTE: placeholder name
{
public:
	int getWidth();		// NOTE: folded getter
	int getHeight();	// NOTE: folded getter
	int *atPoint(const Point &p);			// NOTE: folded (OpX5_Array2D<int>::atPoint)
	void getRandom_9cf0c0(Point *out);		// NOTE: placeholder name
};
extern Grid80 cells80_cfd44c;			// NOTE: placeholder name
extern Grid80 marks80_cf447c;			// NOTE: placeholder name
extern Grid80 originalTerrain;	// NOTE: placeholder type (0xd378c0)

struct Terrain80	// NOTE: placeholder name
{
	int ID;
};
extern Terrain80 *terrain80_cefb9c;	// NOTE: placeholder name

bool OpX5_containsRecord(vector<int> &v, int value);	// NOTE: placeholder name
int OpU8a_randomRec(vector<int> &v);					// NOTE: placeholder name (0x9d5d00)
void OpT8a_eraseAt(vector<int> &v, unsigned int &i);	// NOTE: placeholder name (0x9ce6d0)
void sweepGetSurroundingCells(const Point &point, vector<Point> &adjacent);
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

class BS	// NOTE: placeholder layout
{
public:
	char				pad000[0x10];
	vector<Marker80 *>	markers;		// +0x10
	char				pad020[0xc38 - 0x20];
	vector<int>			usedJunctions;	// +0xc38
	vector<int>			usedRooms;		// +0xc48

	Point unknown6c2230(int level);	// NOTE: placeholder name
};

Point BS::unknown6c2230(int level)
{
	int amount = (cells80_cfd44c.getWidth() + cells80_cfd44c.getHeight()) / 2 / 4;
	int first = (cells80_cfd44c.getWidth() + cells80_cfd44c.getHeight()) / 2 / 6;
	Pos last(-1);
	bool failed = false;
	vector<int> total2;
	for (int i = 0; i < rooms80_d1f31c.size(); i++)
	{
		if (rooms80_d1f31c[i].isDone() && !OpX5_containsRecord(usedRooms,i))
		{
			total2.push_back(i);
			failed = true;
		}
	}
	if (total2.empty())
	{
		for (int j = 0; j < rooms80_d1f31c.size(); j++)
		{
			for (int k = 0; k < rooms80_d1f31c[j].junctions.size(); k++)
			{
				if (junctions80_cf13e8[rooms80_d1f31c[j].junctions[k]].size > minSize80_ced228 && !OpX5_containsRecord(usedRooms,j))
					total2.push_back(j);
			}
		}
	}
	if (total2.empty())
	{
		for (int m = 0; m < rooms80_d1f31c.size(); m++)
		{
			if (!OpX5_containsRecord(usedRooms,m))
				total2.push_back(m);
		}
	}
	if (!total2.empty())
	{
		vector<int> msgs;
		if (!failed)
		{
			for (unsigned int a = 0; a < total2.size(); a++)
			{
				for (unsigned int b = 0; b < markers.size(); b++)
				{
					if (OpQ1_distanceCeil_40a3f0(rooms80_d1f31c[total2[a]].bounds.center(),markers[b]->pos) <= (markers[b]->loc->type == level ? amount : first))
						goto nextRoom;
				}
				msgs.push_back(total2[a]);
nextRoom:		;
			}
		}
		int tail;
		if (msgs.empty())
			tail = OpU8a_randomRec(total2);
		else
			tail = OpU8a_randomRec(msgs);
		int time = 0;
		for (unsigned int c = 0; c < markers.size(); c++)
		{
			if (OpQ1_distanceCeil_40a3f0(rooms80_d1f31c[tail].bounds.center(),markers[c]->pos) <= (markers[c]->loc->type == level ? amount : first))
				time += 40;
		}
		if (time && rng.chance(time))
			goto junctions;
		last = rooms80_d1f31c[tail].bounds.center();
		usedRooms.push_back(tail);
		*marks80_cf447c.atPoint(rooms80_d1f31c[tail].bounds.topLeft()) = 3;
		return last;
	}
junctions:
	vector<int> mode;
	for (int n = 0; n < junctions80_cf13e8.size(); n++)
	{
		if (junctions80_cf13e8[n].size > minSize80_ced228 && !OpX5_containsRecord(usedJunctions,n) && junctions80_cf13e8[n].bounds.x != -1)
			mode.push_back(n);
	}
	if (mode.empty())
	{
		for (int q = 0; q < junctions80_cf13e8.size(); q++)
		{
			if (!OpX5_containsRecord(usedJunctions,q) && junctions80_cf13e8[q].bounds.x != -1)
				mode.push_back(q);
		}
	}
	if (!mode.empty())
	{
		int id;
		vector<int> adj;
		for (unsigned int a2 = 0; a2 < mode.size(); a2++)
		{
			for (unsigned int b2 = 0; b2 < markers.size(); b2++)
			{
				if (OpQ1_distanceCeil_40a3f0(junctions80_cf13e8[mode[a2]].bounds.center(),markers[b2]->pos) <= (markers[b2]->loc->type == level ? amount : first))
					goto nextJunction;
			}
			adj.push_back(mode[a2]);
			OpT8a_eraseAt(mode,a2);
nextJunction:	;
		}
		if (adj.empty())
			id = OpU8a_randomRec(mode);
		else
			id = OpU8a_randomRec(adj);
		last = junctions80_cf13e8[id].bounds.center();
		usedJunctions.push_back(id);
		*marks80_cf447c.atPoint(junctions80_cf13e8[id].bounds.topLeft()) = 3;
	}
	else
	{
		int tries = 0;
		while (true)
		{
			originalTerrain.getRandom_9cf0c0(&last);
			tries++;
			if (*originalTerrain.atPoint(last) != terrain80_cefb9c->ID)
			{
				vector<Point> around;
				sweepGetSurroundingCells(last,around);
				for (unsigned int s = 0; s < around.size(); s++)
				{
					if (*originalTerrain.atPoint(around[s]) != terrain80_cefb9c->ID)
						goto retry;
				}
				break;
retry:			;
			}
		}
	}
	return last;
}
