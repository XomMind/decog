// team_d_20: restore of a stored entity into the world (0x690940).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

class HEntity;
class HItem;

class EntityAI
{
public:
	int unknown5b4710(HEntity e, int a, int b, int c, int d);	// NOTE: placeholder name
};

class EntityAI57f6a0	// NOTE: placeholder name (0x130-byte AI object, constructor 0x57f6a0)
{
public:
	EntityAI57f6a0(HEntity e, int a, int b);
	char pad[0x130];
};

class Item
{
public:
	void setHandle(HItem h);			// NOTE: placeholder name (0x4582d0)
	void setOwner(HEntity e);			// NOTE: placeholder name
	int turnsLeft();					// NOTE: placeholder name
	void setActivateOkayTurn(int turn);
	int unknown44aec0();				// NOTE: placeholder name (trivial getter)
	bool unknown571d70();				// NOTE: placeholder name
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
	void setHandle(HEntity h);			// NOTE: placeholder name (0x4582d0)
	vector<HItem> *getInventoryList();
	void unknown5dc750(class HProp p);	// NOTE: placeholder name
	void changePos(const Point &p, int a);
	void setField4514c0(int value);		// NOTE: placeholder name
	void unknown5ded70(int value);		// NOTE: placeholder name
	void unknown45b0b0();				// NOTE: placeholder name
	void setAI(EntityAI57f6a0 *ai);		// NOTE: placeholder name (0x64ecf0)
	EntityAI *getAI();					// 0x45b590
};

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	Entity *operator->() const;
};

class HProp
{
	int ID;
public:
	HProp();
};

struct EntityRec;	// NOTE: placeholder name
struct ItemRec;		// NOTE: placeholder name

template <class T, class H> class Pool	// NOTE: placeholder name
{
public:
	H add(T *rec);
};
extern Pool<EntityRec,HEntity>	entityPool_d21720;	// NOTE: placeholder name
extern Pool<ItemRec,HItem>		itemPool_d2a298;	// NOTE: placeholder name

class Faction	// NOTE: placeholder name
{
public:
	void unknown671280(HEntity e, int a);	// NOTE: placeholder name
};

class HFaction	// NOTE: placeholder name
{
	int	ID;
public:
	Faction *operator->() const;
};

class BS
{
public:
	HEntity getPlayer();	// 0x4630f0
	HFaction unknown463890(int faction);	// NOTE: placeholder name
	void unknown464f60(HItem item);		// NOTE: placeholder name
	void unknown465060(HItem item);		// NOTE: placeholder name
	void opw3_unknown726b70(HItem item);	// NOTE: placeholder name
};
extern BS *world;

struct TurnRef	// NOTE: placeholder name (4-byte handle copy)
{
	TurnRef(HItem h);
	TurnRef(HEntity h);
	int ID;
};

class TurnSlot	// NOTE: placeholder name
{
public:
	TurnSlot(int type, TurnRef *ref);	// NOTE: placeholder name (0x45e530)
	char pad[0x10];
};

class HTurnClock	// NOTE: placeholder name
{
	int ID;
};

class TurnQueue	// NOTE: placeholder name (0xd225a0)
{
public:
	HTurnClock add(TurnSlot *slot, int delay);
};
extern TurnQueue turnQueue_d225a0;	// NOTE: placeholder name

struct StoredEntity	// NOTE: placeholder name
{
	EntityRec		*entity;	// NOTE: placeholder name
	vector<ItemRec *> items;	// NOTE: placeholder name
	bool			unknown14;	// NOTE: placeholder name
};

HEntity OpD_restoreEntity_690940(StoredEntity *stored, const Point &pos, int faction, int a, int b)	// NOTE: placeholder name
{
	HEntity entity = entityPool_d21720.add(stored->entity);
	entity->setHandle(entity);
	vector<HItem> *items = entity->getInventoryList();
	for (unsigned int i = 0; i < stored->items.size(); i++)
	{
		items->push_back(itemPool_d2a298.add(stored->items[i]));
		items->back()->setHandle(items->back());
		items->back()->setOwner(entity);
		if (items->back()->turnsLeft() > 0)
			items->back()->setActivateOkayTurn(0);
		world->unknown464f60(items->back());
		world->unknown465060(items->back());
		if (items->back()->unknown44aec0() <= 3)
			world->opw3_unknown726b70(items->back());
		if ((*items)[i]->unknown571d70())
			turnQueue_d225a0.add(new TurnSlot(2,new TurnRef((*items)[i])),0);
	}
	entity->unknown5dc750(HProp());
	entity->changePos(pos,0);
	world->unknown463890(faction)->unknown671280(entity,0);
	turnQueue_d225a0.add(new TurnSlot(1,new TurnRef(entity)),0);
	entity->setField4514c0(0);
	entity->unknown5ded70(1000000);
	entity->unknown45b0b0();
	entity->setAI(new EntityAI57f6a0(entity,a,b));
	entity->getAI()->unknown5b4710(world->getPlayer(),-2,1,0,0);
	stored->unknown14 = false;
	return entity;
}

// Defined here (not just declared) so that LTCG can prove these constructors cannot throw, which
// removes the exception states around the new-expressions but keeps their result temporaries.
// In the exe both fold with InternalMetadataWithArenaBase's constructor (0x9f57e0).
TurnRef::TurnRef(HItem h)
{
	ID = *(int *)&h;
}

TurnRef::TurnRef(HEntity h)
{
	ID = *(int *)&h;
}
