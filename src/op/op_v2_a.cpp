// op_v2_a: EntityAI (0x5b0000-0x600000), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// NOTE: placeholder name (0xd30908)

struct Point
{
	int x;
	int y;

	Point();
	Point(int x_, int y_);
	Point(const Point &p);
	Point &operator=(const Point &p);
	bool operator!=(const Point &p) const;
	bool operator==(const Point &p) const;	// 0x409b90
	void setOffset(const Point &base, int dx, int dy);	// NOTE: placeholder name (0x40a060)
};

class Entity;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool isValid() const;
	Entity *operator->() const throw();
};

class Entity
{
public:
	int getSize();	// NOTE: placeholder name (0x45a360)
	const Point &getPosition() throw();	// 0x45a4a0
	Point unknown45a4c0();	// NOTE: placeholder name
	bool isHostileTo(HEntity e);
};

class OpV2_Grid	// NOTE: placeholder name (object at 0xcfd44c)
{
public:
	int width;
	int height;
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
};
extern OpV2_Grid opv2_cells;	// NOTE: placeholder name (0xcfd44c)

Point OpU8a_randomPoint(vector<Point> &v);	// NOTE: placeholder name (0x9d5350)

class EntityAI
{
public:
	HEntity self;						// +0
	int state;							// +4, NOTE: placeholder name
	char pad08[0x10 - 0x08];
	Point unknown10;					// NOTE: placeholder name
	Point unknown18;					// NOTE: placeholder name
	HEntity target;						// +0x20, NOTE: placeholder name

	int unknown5b76c0(int *arg);			// NOTE: placeholder name
	bool unknown5b7400(int *arg);		// NOTE: placeholder name
};

bool EntityAI::unknown5b7400(int *arg)
{
	if (self->getSize() > 1)
	{
		if (unknown10.x == -1)
			unknown10 = unknown18;
		if (unknown10.x != -1 && target.operator->() && target->isHostileTo(self))
		{
			Point origin(unknown10);
			for (int i = 0; i < 4; i++)
			{
				do
				{
					unknown10.setOffset(origin,rng.rangeInt(-2,2),rng.rangeInt(-2,2));
				} while (unknown10 == origin || !opv2_cells.contains(unknown10));
				if (!unknown5b76c0(arg))
					return true;
			}
			Point selfPos(self->getPosition());
			Point goalPos = self->unknown45a4c0();
			Point tPos(target->getPosition());
			vector<Point> candidates;
			if (goalPos.x != tPos.x)
				candidates.push_back(Point(tPos.x < goalPos.x ? selfPos.x - 1 : selfPos.x + 1,selfPos.y));
			if (goalPos.y != tPos.y)
				candidates.push_back(Point(selfPos.x,tPos.y < goalPos.y ? selfPos.y - 1 : selfPos.y + 1));
			if (!candidates.empty())
				unknown10 = OpU8a_randomPoint(candidates);
			if (!unknown5b76c0(arg))
				return true;
			unknown10 = origin;
		}
	}
	return false;
}
