#include <vector>
// NOTE: Partial layouts and unknown-prefixed names are placeholders.
struct Point { int x; int y; };
class Entity;
class HEntity
{
	int ID;
public:
	Entity *operator->() const;
};
class Group
{
public:
	int unknown9b4350();
};
class HGroup
{
	int ID;
public:
	Group *operator->() const;
};
class HItem
{
	int ID;
public:
	bool isValid() const;
};
class Entity
{
public:
	char pad00[0xb8];
	bool unknownB8;
	bool isHostileTo(HEntity e);
	HGroup getGroup();
	int getFaction();
	bool unknown5d4230(HEntity e);
	bool unknown5d4100();
	int unknown5d22a0(int type);
	const Point &getPosition();
	HItem unknown5d2380(int type);
};
class Map
{
public:
	HEntity getPlayer();
	bool unknown463660();
};
class BS : public Map
{
public:
	bool unknown4631f0(HEntity e);
	void opw3_unknown72e8e0(bool flag);
};
extern BS *world;
extern std::vector<int> flags_cf4a04;
int OpQ1_distanceCeil_40a3f0(const Point &a,const Point &b);
class EntityAI
{
public:
	HEntity self;
	bool unknown581140();
};

bool EntityAI::unknown581140()
{
	bool active = false;
	if (world->getPlayer()->isHostileTo(self) || self->getGroup()->unknown9b4350() == 4)
	{
		if (flags_cf4a04[8] != 0)
		{
			switch (self->getGroup()->unknown9b4350())
			{
			case 3:
				if (world->getPlayer()->unknown5d4230(self))
				{
					active = true;
					goto awarenessDone;
				}
				break;
			case 4:
				if ((self->getFaction() == 2 || self->getFaction() == 4) && world->getPlayer()->unknown5d4100())
				{
					active = true;
					goto awarenessDone;
				}
			}
		}
		int range = world->getPlayer()->unknown5d22a0(0x14);
		if (range != 0 && range >= OpQ1_distanceCeil_40a3f0(self->getPosition(),world->getPlayer()->getPosition()))
		{
			if (!self->unknownB8 || world->getPlayer()->unknown5d2380(0x15).isValid())
				active = true;
		}
	}
awarenessDone:
	if (active)
	{
		if (world->unknown4631f0(self))
			return true;
		else if (world->unknown463660())
		{
			world->opw3_unknown72e8e0(false);
			return world->unknown4631f0(self);
		}
		else
			return false;
	}
	else
		return false;
}
