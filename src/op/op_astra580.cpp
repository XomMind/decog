// op_astra580: EntityAI target-record selection, 0x580ec0.
// NOTE: partial layouts and unknown-prefixed names are placeholders.
// Isolated try.sh MATCH, 531 bytes. Full-link verification is not yet performed.
// Local names changed/found preserve MSVC /Od stack-slot ordering.
#include <vector>
using namespace std;

struct Point { int x; int y; };
class Group
{
public:
	int unknown9b4350(); // NOTE: placeholder name (folded getter)
};
class HGroup
{
	int ID;
public:
	Group *operator->() const;
};
class Entity
{
public:
	HGroup getGroup();
	int getFaction();
	const Point &getPosition();
	int unknown5c7d30(); // NOTE: placeholder name
};
class HEntity
{
	int ID;
public:
	Entity *operator->() const;
};
class Map
{
public:
	HEntity getPlayer();
	bool unknown463400(HEntity e); // NOTE: placeholder name
	bool isReachable(int range, const Point &from, const Point &to);
};
extern Map *world;
extern vector<int> flags_cf4a04; // NOTE: placeholder name (0xcf4a04)

struct OpAstra580_Record // NOTE: placeholder name and layout
{
	HEntity entity; // +0x00
	int unknown4;
	int score; // +0x08
};
class EntityAI
{
public:
	HEntity self; // +0x00
	char pad04[0x55 - 4];
	bool requireReachable; // +0x55
	char pad56[0xf0 - 0x56];
	vector<OpAstra580_Record *> records; // +0xf0

	bool unknown580ba0(HEntity e); // NOTE: placeholder name
	OpAstra580_Record *unknown580ec0(); // NOTE: placeholder name
};

OpAstra580_Record *EntityAI::unknown580ec0()
{
	bool changed = !(self->getGroup()->unknown9b4350() > 1 && !unknown580ba0(world->getPlayer()));
	bool found = changed && flags_cf4a04[11] != 0;
	OpAstra580_Record *best = 0;
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (best == 0 || records[i]->score > best->score)
		{
			if (records[i]->entity->getFaction() == 12)
			{
				if (found && records[i]->entity->getGroup()->unknown9b4350() == 3)
					continue;
				if (changed && !world->unknown463400(records[i]->entity))
					continue;
			}
			if (requireReachable && !world->isReachable(self->unknown5c7d30(),self->getPosition(),records[i]->entity->getPosition()))
				continue;
			best = records[i];
		}
	}
	return best;
}
