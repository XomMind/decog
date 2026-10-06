// op_u5: assorted functions in 0x700000-0x7ea000
#include "../pathing/gamedecl.h"

class OpU5_Unk71c850	// NOTE: placeholder name
{
public:
	int countPassableAdjacent(const Point &p);	// NOTE: placeholder name (0x71c850)
};

int OpU5_Unk71c850::countPassableAdjacent(const Point &p)
{
	vector<Point> adjacent;
	getAdjacentCells(p,adjacent);
	int total = 0;
	for (unsigned int i = 0; i < adjacent.size(); i++)
	{
		if (cells(adjacent[i])->isPassableFor(HEntity()))
			total++;
	}
	return total;
}

// NOTE: placeholder layouts of classes only used through casts
class Predicate_409b90
{
public:
	int field0;
	int field4;
	bool test(const Predicate_409b90 & arg0);
};

class PushGeometry
{
public:
	int x;
	int y;
	bool adjacent(const PushGeometry &p);
};

void erasePointAt(vector<Point> &v, int index);		// NOTE: placeholder name (0x9d5190)
void opw2_erasePoints(vector<Point> &v, int from, int to);	// NOTE: placeholder name (0x9d53f0)

class OpU5_Unk71ce30	// NOTE: placeholder name
{
public:
	char pad0[0x830];
	vector<Point> trailA;	// +0x830
	vector<Point> trailB;	// +0x840
	void addTrailPoint(const Point &p);	// NOTE: placeholder name (0x71ce30)
};

void OpU5_Unk71ce30::addTrailPoint(const Point &p)
{
	for (int i = 0; i < 2; i++)
	{
		vector<Point> &trail = (i == 0 ? trailA : trailB);
		int limit = (i == 0 ? 10 : 12);
		if (!trail.empty())
		{
			for (int j = (int)trail.size() - 1; j >= 0; j--)
			{
				if (((Predicate_409b90 &)trail[j]).test((Predicate_409b90 &)p) || (((PushGeometry &)trail[j]).adjacent((PushGeometry &)p) && j != (int)trail.size() - 1))
				{
					opw2_erasePoints(trail,j,(int)trail.size() - 1);
					goto next;;
				}
			}
		}
		trail.push_back(p);
		if (trail.size() > (unsigned int)limit)
			erasePointAt(trail,0);
		next:;
	}
}
