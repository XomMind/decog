// op_v2_b: EntityAI (0x5b0000-0x600000), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();
	Point(int x_, int y_);
	Point(const Point &p);
	Point &operator=(const Point &p);
	int distance(const Point &p) const;	// NOTE: placeholder name (0x409fb0)
};

struct Area	// NOTE: placeholder name
{
	Area();	// 0x40b100
	bool contains_40b750(const Point &p);	// NOTE: placeholder name
	void randomPoint_40be30(Point *out);	// NOTE: placeholder name
	Point min;
	Point max;
};

class Entity;

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();
	bool isValid() const;
	Entity *operator->() const throw();
};

class Group	// NOTE: placeholder name
{
public:
	int unknown9b4350();	// NOTE: placeholder name (ICF'd trivial getter)
};

class HGroup	// NOTE: placeholder name
{
public:
	int ID;
	Group *operator->() const;	// 0x9b7250
};

struct OpV2_EntityInfo	// NOTE: placeholder name
{
	char pad00[0x158];
	int unknown158;
};

class Entity
{
public:
	int getFaction() throw();	// 0x45a2c0
	HGroup getGroup();	// 0x45a3f0
	OpV2_EntityInfo *unknown9b4350();	// NOTE: placeholder name (ICF'd trivial getter)
	const string &getName();	// 0x45a280
	const Point &getPosition() throw();	// 0x45a4a0
};

class Cell
{
public:
	bool isPassableFor(HEntity e);
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	int getWidth();
	int getHeight();
	void getRect(const Point &p, int radius, Area &out);	// NOTE: placeholder name (0x9b4430)
	void getRandom_9cf0c0(Point *out);	// NOTE: placeholder name
};
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

class Map	// NOTE: partial
{
public:
	HEntity getPlayer() throw();	// 0x4630f0
	bool isVisible4631c0(const Point &p);	// NOTE: placeholder name (0x4631c0, BS::isVisible; not Map::isVisible(int,int) 0x463190)
};
extern Map *world;	// NOTE: placeholder name (0xcefc4c)
extern int opv2_caf164;	// NOTE: placeholder name (0xcaf164)

int minInt(int a, int b);	// 0x9cdb30

class OpV2_Order	// NOTE: placeholder name (0x1c bytes, PropPoints458bd0)
{
public:
	OpV2_Order(int type, HEntity target, const Point &pos);
	int pad[7];
};

class EntityAI
{
public:
	HEntity self;						// +0
	int state;							// +4, NOTE: placeholder name
	char pad08[0x10 - 0x08];
	Point unknown10;					// NOTE: placeholder name

	bool findPathToGoal();				// 0x5b8d20
	bool unknown5b91e0();				// NOTE: placeholder name
	void unknown5b5380(OpV2_Order *order);	// NOTE: placeholder name
	bool unknown5b94c0();				// NOTE: placeholder name
};

bool EntityAI::unknown5b94c0()
{
	if (self->getFaction() == 10 && self->getGroup()->unknown9b4350() == 0 && self->unknown9b4350()->unknown158 != opv2_caf164)
	{
		if (self->getName() == "Decoy Drone")
		{
			Point center(world->getPlayer()->getPosition());
			Area rect;
			int radius;
			for (radius = minInt(minInt(cells.getWidth(),50),cells.getHeight()); radius >= 20; radius -= 10)
			{
				cells.getRect(center,radius,rect);
				for (int j = 0; j < 100; j++)
				{
					cells.getRandom_9cf0c0(&unknown10);
					if (!rect.contains_40b750(unknown10) && cells(unknown10)->isPassableFor(self) && findPathToGoal())
						return true;
				}
			}
			for (int k = 0; k < 500; k++)
			{
				cells.getRandom_9cf0c0(&unknown10);
				if (findPathToGoal())
					return true;
			}
		}
		unknown10 = world->getPlayer()->getPosition();
		unknown5b5380(new OpV2_Order(10,world->getPlayer(),unknown10));
		return true;
	}
	Point selfPos(self->getPosition());
	Area area;
	for (int i = 0; i < 3; i++)
	{
		cells.getRect(selfPos,i * 20 + 20,area);
		for (int j = 0; j < 25; j++)
		{
			area.randomPoint_40be30(&unknown10);
			if (selfPos.distance(unknown10) >= 20 && !world->isVisible4631c0(unknown10) && cells(unknown10)->isPassableFor(self) && findPathToGoal())
				return true;
		}
	}
	return unknown5b91e0();
}
