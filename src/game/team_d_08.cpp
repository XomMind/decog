// team_d_08: EntityAI members (0x5b2d10 part scan, 0x5b5380 order handling).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct ItemDataSub	// NOTE: placeholder name
{
	char pad00[0x2c];
	int unknown2c;	// NOTE: placeholder name
	char pad30[0x3c - 0x30];
	int unknown3c;	// NOTE: placeholder name
	int unknown40;	// NOTE: placeholder name
};

struct ItemData	// NOTE: placeholder name
{
	char pad00[8];
	string name;	// +8
	char pad24[0x1a0 - 0x24];
	ItemDataSub *unknown1a0;	// NOTE: placeholder name
};

class Item
{
public:
	int unknown44aec0();		// NOTE: placeholder name (trivial getter)
	ItemData *unknown9b4350();	// NOTE: placeholder name (trivial getter)
	int unknown457f90();		// NOTE: placeholder name
	int unknown4580a0();		// NOTE: placeholder name
};

class HItem
{
	int	ID;
public:
	Item *operator->() const;
};

class Entity
{
public:
	Point &getPosition();	// 0x45a4a0

	char pad[0x134];
	vector<HItem> parts;	// +0x134, NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	bool isValid() const;
	Entity *operator->() const;
	void resetField();	// NOTE: placeholder name (0x9b7270)
};

class HExplosive	// NOTE: placeholder name (as in cc_r2_27.cpp)
{
	int ID;
};

extern vector<HExplosive>	unknown_cf25b8;	// NOTE: placeholder name
extern vector<HExplosive>	unknown_d37984;	// NOTE: placeholder name

int OpU8a_indexOfEntity(vector<HExplosive> &v, HEntity e);	// NOTE: placeholder name (0x9d3110)
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name
void OpQ1_lineBresenhamPoints_40ff30(Point &from, Point &to, vector<Point> *out);	// NOTE: placeholder name

class OpD_AIOrder	// NOTE: placeholder name
{
public:
	~OpD_AIOrder();

	int		unknown0;	// NOTE: placeholder name
	int		type;		// NOTE: placeholder name
	HEntity	entity;		// NOTE: placeholder name
	vector<Point> path;	// NOTE: placeholder name
};

class EntityAI
{
public:
	HEntity self;						// +0
	int state;							// +4, NOTE: placeholder name
	char pad08[0x10 - 0x08];
	int unknown10;						// NOTE: placeholder name
	char pad14[0x24 - 0x14];
	vector<Point> line;					// +0x24, NOTE: placeholder name
	char pad34[0x56 - 0x34];
	bool preserveMemory;
	char pad57[0x58 - 0x57];
	HEntity unknown58;					// NOTE: placeholder name
	char pad5c[0x6c - 0x5c];
	vector<Point> path;					// +0x6c, NOTE: placeholder name
	char pad7c[0xb4 - 0x7c];
	HEntity unknownb4;					// NOTE: placeholder name
	char padb8[0xbc - 0xb8];
	int unknownbc;						// NOTE: placeholder name
	int unknownc0;						// NOTE: placeholder name
	int unknownc4;						// NOTE: placeholder name
	char padc8[0x114 - 0xc8];
	OpD_AIOrder *order;						// +0x114, NOTE: placeholder name

	void setFollowEntity(HEntity followEntity_, int followParam_);	// 0x5b2f80
	void unknown5bb6f0();				// NOTE: placeholder name
	void unknown5b2d10();				// NOTE: placeholder name
	void unknown5b5380(OpD_AIOrder *order_);	// NOTE: placeholder name
};

void EntityAI::unknown5b2d10()
{
	unknownc4 = 0;
	unknownbc = 0;
	for (unsigned int i = 0; i < self->parts.size(); i++)
	{
		if (self->parts[i]->unknown44aec0() <= 3)
		{
			if (self->parts[i]->unknown9b4350()->unknown1a0 != NULL && self->parts[i]->unknown9b4350()->unknown1a0->unknown3c > unknownbc
				&& self->parts[i]->unknown9b4350()->unknown1a0->unknown40 == 0 && self->parts[i]->unknown9b4350()->name != "Containment Facilitator")
			{
				unknownbc = self->parts[i]->unknown9b4350()->unknown1a0->unknown3c;
				unknownc0 = self->parts[i]->unknown9b4350()->unknown1a0->unknown2c;
			}
			if (self->parts[i]->unknown457f90() == 0xcf && self->parts[i]->unknown4580a0() > unknownc4)
				unknownc4 = self->parts[i]->unknown4580a0();
		}
	}
}

void EntityAI::unknown5b5380(OpD_AIOrder *order_)
{
	delete order;
	order = order_;
	if (order->type != 10)
		preserveMemory = false;
	unknown58.resetField();
	path.clear();
	if (unknownb4.isValid())
	{
		int index = OpU8a_indexOfEntity(unknown_cf25b8,unknownb4);
		if (index != -1)
		{
			if (!unknownb4.operator->())
			{
				OpQ5_eraseAt(unknown_cf25b8,index);
				OpQ5_eraseAt(unknown_d37984,index);
			}
			else
				((HEntity &)unknown_d37984[index]).resetField();
		}
		unknownb4.resetField();
	}
	switch (order->type)
	{
		case 0:
			state = 1;
			path.push_back(self->getPosition());
			unknown10 = -1;
			break;
		case 1:
			unknown5bb6f0();
			break;
		case 2:
		case 3:
		case 4:
			setFollowEntity(order->entity,0);
			unknown5bb6f0();
			break;
		case 5:
			line.clear();
			OpQ1_lineBresenhamPoints_40ff30(self->getPosition(),order->path.front(),&line);
			order->path.assign(line.begin() + 1,line.end());
			unknown5bb6f0();
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
		case 9:
			unknown10 = -1;
			unknown5bb6f0();
			break;
		case 10:
			setFollowEntity(order->entity,0);
			unknown5bb6f0();
			break;
	}
}
