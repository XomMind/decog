// op_s9_6716f0: remove an entity from a group (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts throughout.
#include <vector>
using namespace std;

struct Point;
class Entity;
struct OpS9_Effect;	// NOTE: placeholder name

class HEntity
{
	int ID;
public:
	Entity *operator->() const;	// 0x9b6570
};

class Entity
{
public:
	int getTarget();	// 0x45a760
	const Point &getPosition();	// 0x45a4a0
	OpS9_Effect *unknown45ac40(int type);	// NOTE: placeholder name
	int getFaction();	// 0x45a2c0
};

struct OpS9_Marker	// NOTE: placeholder name (OpQ3_Marker)
{
	void unknown6c20b0(int layer, const Point &pos, int flag);	// NOTE: placeholder name
};
class OpS9_HMarker	// NOTE: placeholder name
{
	int ID;
public:
	OpS9_Marker *get240() const;	// NOTE: placeholder name (0x6c0240)
};
class OpS9_Factory	// NOTE: placeholder name
{
public:
	OpS9_HMarker createC();	// 0x793190
};
extern OpS9_Factory *opS9_factory;	// NOTE: placeholder name (0xcefaa8)

class OpS9_Map	// NOTE: placeholder name (BS)
{
public:
	void unknown72e790(int index);	// NOTE: placeholder name
	bool unknown463510(HEntity e);	// NOTE: placeholder name
	int unknown463540(HEntity e);	// NOTE: placeholder name
	bool unknown4635c0(HEntity e);	// NOTE: placeholder name
	int unknown4635f0(HEntity e);	// NOTE: placeholder name
	int unknown4638e0(int id, int flag);	// NOTE: placeholder name
	void unknown464800(HEntity e);	// NOTE: placeholder name
	void unknown734560(HEntity e, int a, int b);	// NOTE: placeholder name
	bool isVisible(const Point &p);	// 0x4631c0
	vector<vector<OpS9_HMarker> > &unknown463ec0();	// NOTE: placeholder name
};
extern OpS9_Map *opS9_map;	// NOTE: placeholder name (0xcefc4c)

class OpS9_Overmind	// NOTE: placeholder name (OpR3c_Overmind at 0xcf6428)
{
public:
	bool unknown683380(HEntity e, int *out);	// NOTE: placeholder name
};
extern OpS9_Overmind opS9_overmind;	// NOTE: placeholder name

class OpS9_Mission	// NOTE: placeholder name (CMission)
{
public:
	void unknown987de0();	// NOTE: placeholder name
};
extern OpS9_Mission *opS9_mission;	// NOTE: placeholder name (0xcec034)

struct OpQ5_U9da940;
int OpU8a_indexOfEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d3110)
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name

class OpS9_Group	// NOTE: placeholder name
{
public:
	int pad00;
	int ID;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
	vector<HEntity> members;
	char pad1c[0x28 - 0x1c];
	bool hasFaction20;	// NOTE: placeholder name
	void removeMember(HEntity entity);	// NOTE: placeholder name
};

void OpS9_Group::removeMember(HEntity entity)
{
	int index = OpU8a_indexOfEntity(members,entity);
	if (type == 0)
		opS9_map->unknown72e790(index);
	else if (opS9_map->unknown463510(entity))
		opS9_map->unknown72e790(opS9_map->unknown463540(entity));
	else if (opS9_map->unknown4635c0(entity))
		opS9_map->unknown72e790(opS9_map->unknown4635f0(entity));
	if (opS9_map->unknown4638e0(ID,0) == 0)
		opS9_map->unknown464800(entity);
	OpQ5_eraseAt((vector<OpQ5_U9da940> &)members,index);
	opS9_map->unknown734560(entity,0,0);
	switch (type)
	{
	case 3:
		opS9_overmind.unknown683380(entity,0);
		break;
	case 0:
		if (entity->getTarget() == 0 && !opS9_map->isVisible(entity->getPosition()))
		{
			int layer = (entity->unknown45ac40(0x39) != 0) + 12;
			vector<OpS9_HMarker> &group = opS9_map->unknown463ec0()[layer];
			group.push_back(opS9_factory->createC());
			group.back().get240()->unknown6c20b0(layer,entity->getPosition(),-1);
			opS9_mission->unknown987de0();
		}
		break;
	}
	if (entity->getFaction() == 20)
	{
		hasFaction20 = false;
		for (unsigned int i = 0; i < members.size(); i++)
		{
			if (members[i]->getFaction() == 20)
			{
				hasFaction20 = true;
				break;
			}
		}
	}
}
