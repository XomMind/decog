// team_d_52: BS member 0x6c5e20 (restore a stored entity and its inventory into the level).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;
};

class Entity;
class Item;
class EntityAI;

class HEntity
{
	int ID;
public:
	Entity *operator->() const;
};

class HItem
{
	int ID;
public:
	Item *operator->() const;
};

class HProp
{
	int ID;
public:
	HProp();
};

class Item
{
public:
	void setHandle(HItem h);			// NOTE: placeholder name (0x4582d0)
	void setOwner(HEntity e);			// NOTE: placeholder name (0x44eb00)
	int turnsLeft();					// NOTE: placeholder name (0x577ad0)
	void setActivateOkayTurn(int turn);
	int getType();
	bool unknown457cf0();				// NOTE: placeholder name
	int unknown457f90();				// NOTE: placeholder name
	bool unknown571d70();				// NOTE: placeholder name
	int unknown457c80();				// NOTE: placeholder name
	void unknown458360(int value);		// NOTE: placeholder name
};

class EntityAI57f6a0	// NOTE: placeholder name (0x130-byte AI object, constructor 0x57f6a0)
{
public:
	EntityAI57f6a0(HEntity e, int a, int b);
	char pad[0x130];
};

class EntityAI52	// NOTE: placeholder name (EntityAI)
{
public:
	void setFollowEntity(HEntity followEntity_, int followParam_);	// 0x5b2f80
};

class Entity
{
public:
	void setHandle(HEntity h);			// NOTE: placeholder name (0x4582d0)
	const string &getName();			// 0x45a280
	vector<HItem> *getInventoryList();
	void unknown5dc750(HProp p);		// NOTE: placeholder name
	void changePos(const Point &p, int a);
	void setField4514c0(int value);		// NOTE: placeholder name
	void unknown5ded70(int value);		// NOTE: placeholder name
	void unknown45b0b0();				// NOTE: placeholder name
	void setAI(EntityAI57f6a0 *ai);		// NOTE: placeholder name (0x64ecf0)
	EntityAI52 *getAI();				// 0x45b590
	struct EntityEffect *unknown45ac40(int type);		// NOTE: placeholder name (effect)
	int getFaction();					// 0x45a2c0
	int getAiType();					// 0x45a2a0
	int unknown5ca260();				// NOTE: placeholder name
	void unknown5de870(int value, int flag);	// NOTE: placeholder name
};

struct EntityRec52;	// NOTE: placeholder name
struct ItemRec52;	// NOTE: placeholder name

struct StoredEntity52	// NOTE: placeholder name and layout
{
	int					unknown00;
	EntityRec52			*entity;	// +0x04
	int					unknown08;	// NOTE: placeholder name
	int					unknown0c;	// NOTE: placeholder name
	int					unknown10;	// NOTE: placeholder name
	vector<ItemRec52 *>	items;		// +0x14
	vector<int>			flags;		// +0x24
};

class EntityPool52	// NOTE: placeholder name (OpS8a_Pool at 0xd21720)
{
public:
	HEntity add(EntityRec52 *rec);
};
extern EntityPool52 entityPool52_d21720;	// NOTE: placeholder name

class ItemPool52	// NOTE: placeholder name (OpS8a_Pool at 0xd2a298)
{
public:
	HItem add(ItemRec52 *rec);
};
extern ItemPool52 itemPool52_d2a298;	// NOTE: placeholder name
extern vector<HItem> entities52_cf4944;	// NOTE: placeholder name

class ItemRef52	// NOTE: placeholder name (4-byte handle holder)
{
public:
	HItem item;
	ItemRef52(HItem h);	// NOTE: exe constructor folded with a protobuf one; defined below so LTCG proves it cannot throw
};

ItemRef52::ItemRef52(HItem h)
{
	item = h;
}

class EntityRef52	// NOTE: placeholder name (4-byte handle holder)
{
public:
	HEntity entity;
	EntityRef52(HEntity h);	// NOTE: see ItemRef52
};

EntityRef52::EntityRef52(HEntity h)
{
	entity = h;
}

class Action52	// NOTE: placeholder name (0x10-byte turn action, constructor 0x45e530)
{
public:
	Action52(int type, void *data);
	char pad[0x10];
};

class HAction52	// NOTE: placeholder name
{
	int ID;
};

class TurnQueue52	// NOTE: placeholder name (0xd225a0)
{
public:
	HAction52 add(Action52 *action, int delay);	// NOTE: placeholder name
};
extern TurnQueue52 turnQueue52_d225a0;	// NOTE: placeholder name

class Group52	// NOTE: placeholder name
{
public:
	void unknown671280(HEntity e, bool flag);	// NOTE: placeholder name
	vector<HEntity> *getMembers();	// NOTE: placeholder name (folded getter 0x416f40)
};

class HGroup52	// NOTE: placeholder name
{
	int ID;
public:
	Group52 *operator->() const;	// NOTE: placeholder name (0x9b????)
};

class BS
{
public:
	char			pad000[0x4c];
	vector<HGroup52> groups;		// +0x4c
	char			pad05c[0x4e0 - 0x5c];
	vector<HItem>	unknown4e0;		// NOTE: placeholder name
	char			pad4f0[0x66c - 0x4f0];
	HEntity			leader;			// +0x66c

	void unknown464f60(HItem item);			// NOTE: placeholder name
	void unknown465060(HItem item);			// NOTE: placeholder name
	void opw3_unknown726b70(HItem item);	// NOTE: placeholder name
	void addFollower(HEntity e);
	HEntity unknown6c5e20(StoredEntity52 *rec, const Point &pos, int index, bool flag, bool makeAI, bool follow);	// NOTE: placeholder name
};


HEntity BS::unknown6c5e20(StoredEntity52 *rec, const Point &pos, int index, bool flag, bool makeAI, bool follow)
{
	HEntity entity = entityPool52_d21720.add(rec->entity);
	entity->setHandle(entity);
	bool result = entity->getName() == "Cogmind";
	if (result)
		entities52_cf4944.clear();
	vector<HItem> *items = entity->getInventoryList();
	for (unsigned int i = 0; i < rec->items.size(); i++)
	{
		items->push_back(itemPool52_d2a298.add(rec->items[i]));
		items->back()->setHandle(items->back());
		items->back()->setOwner(entity);
		if (items->back()->turnsLeft() > 0)
			items->back()->setActivateOkayTurn(0);
		unknown464f60(items->back());
		unknown465060(items->back());
		if (items->back()->getType() <= 3)
			opw3_unknown726b70(items->back());
		if (result && items->back()->unknown457cf0() && items->back()->unknown457f90() == 0xbd)
			unknown4e0.push_back((*items)[i]);
		if ((*items)[i]->unknown571d70())
			turnQueue52_d225a0.add(new Action52(2,new ItemRef52((*items)[i])),0);
		if (result && rec->flags[i])
			entities52_cf4944.push_back((*items)[i]);
	}
	entity->unknown5dc750(HProp());
	entity->changePos(pos,0);
	groups[index]->unknown671280(entity,flag);
	turnQueue52_d225a0.add(new Action52(1,new EntityRef52(entity)),0);
	entity->setField4514c0(0);
	entity->unknown5ded70(1000000);
	entity->unknown45b0b0();
	if (makeAI)
		entity->setAI(new EntityAI57f6a0(entity,rec->unknown08,rec->unknown0c));
	if (entity->getAI())
	{
		if (follow)
			entity->getAI()->setFollowEntity(leader,rec->unknown10);
		else
		{
			vector<HEntity> *members = groups[index]->getMembers();
			if (members->size() > 1)
				entity->getAI()->setFollowEntity((*members)[members->size() - 2],0);
		}
	}
	if (index == 0 && entity->unknown45ac40(0x39))
		addFollower(entity);
	if (entity->getFaction() == 0x42 && entity->getAiType() == 0)
	{
		entity->unknown5de870(entity->unknown5ca260() * 0x32 / 100,0);
		vector<HItem> *list = entity->getInventoryList();
		for (unsigned int j = 0; j < list->size(); j++)
			(*list)[j]->unknown458360((*list)[j]->unknown457c80() * 0x32 / 100);
	}
	return entity;
}
