// Entity header-inline accessors (0x45a810-0x45ada4) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members and names are placeholders unless stated.
#include <string>
#include <vector>
using namespace std;

extern unsigned int tickCount;	// 0xcaed20

template <class T> T sumArray(const T *values, unsigned int count);	// NOTE: placeholder name (0x9d0ca0)

struct Point
{
	int x;
	int y;
};

class Entity;
class Item;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	Entity *operator->() const;	// 0x9b6570
};

class HItem	// NOTE: placeholder layout
{
	int	ID;
public:
	Item *operator->() const;	// 0x9b65b0
};

class HGroup	// NOTE: placeholder name
{
	int	ID;
};

class HItemList	// NOTE: placeholder name
{
public:
	unsigned int count();	// NOTE: placeholder name (0x9b9260)
	HItem &at(unsigned int i);	// NOTE: placeholder name (0x9b81f0)

	char pad[0x10];
};

class Item
{
public:
	const string &unknown457860();	// NOTE: placeholder name
};

class Inventory;	// NOTE: placeholder name

struct EntityEffectDef	// NOTE: placeholder name
{
	int		type;	// NOTE: placeholder name
	string	name;	// NOTE: placeholder name
};

struct EntityEffect	// NOTE: placeholder name
{
	EntityEffectDef	*def;	// NOTE: placeholder name
	int				value;	// NOTE: placeholder name
};

struct EntityRecord;

class Entity
{
public:
	int unknown45a810();				// NOTE: placeholder name
	int *unknown45a840();				// NOTE: placeholder name
	int getSlotTotal();
	int unknown45a880();				// NOTE: placeholder name
	int unknown45a8b0();				// NOTE: placeholder name
	int unknown45a8d0();				// NOTE: placeholder name
	int unknown45a8f0();				// NOTE: placeholder name
	int unknown45a920();				// NOTE: placeholder name
	int unknown45a940();				// NOTE: placeholder name
	int unknown45a990();				// NOTE: placeholder name
	vector<int> *unknown45a9b0();		// NOTE: placeholder name
	int unknown45a9d0();				// NOTE: placeholder name
	int unknown45a9f0();				// NOTE: placeholder name
	bool unknown45aa10();				// NOTE: placeholder name
	int unknown45aa30();				// NOTE: placeholder name
	int unknown45aa50();				// NOTE: placeholder name
	bool isHostileTo(HEntity entity);	// NOTE: placeholder name
	bool unknown45aaa0(HEntity entity);	// NOTE: placeholder name
	bool unknown45aad0(HEntity entity);	// NOTE: placeholder name
	HItemList *getInventoryList();		// NOTE: placeholder name
	bool unknown45ab20(const string &itemName);	// NOTE: placeholder name
	int unknown45ab90();				// NOTE: placeholder name
	bool unknown45abb0();				// NOTE: placeholder name
	bool unknown45ac00();				// NOTE: placeholder name
	EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	int unknown45acb0(int type);		// NOTE: placeholder name
	bool unknown45ad20(const string &effectName);	// NOTE: placeholder name
	Inventory *getInventory();			// NOTE: placeholder name

	int unknown5ca210();				// NOTE: placeholder name
	int unknown5c8e20(int *count);		// NOTE: placeholder name
	int unknown5ca260();				// NOTE: placeholder name
	int unknown5ca400();				// NOTE: placeholder name
	int unknown5ca670();				// NOTE: placeholder name
	bool unknown5cb680(HGroup g);		// NOTE: placeholder name
	bool isInGroup(HGroup g);			// NOTE: placeholder name (0x5cb6b0)
	bool unknown5cb6e0(HGroup g);		// NOTE: placeholder name

	int unknown00;					// NOTE: placeholder name
	HEntity self;					// NOTE: placeholder name
	EntityRecord *record;
	string name;					// NOTE: placeholder name
	HGroup group;					// NOTE: placeholder name
	char pad2c[4];
	vector<Point> footprint;		// NOTE: placeholder name
	char pad40[0x78 - 0x40];
	int slots[4];					// NOTE: placeholder name
	int unknown88;					// NOTE: placeholder name
	int unknown8c;					// NOTE: placeholder name
	int unknown90;					// NOTE: placeholder name
	int unknown94;					// NOTE: placeholder name
	int unknown98;					// NOTE: placeholder name
	vector<int> unknown9c;			// NOTE: placeholder name
	char padAC[4];
	int unknownB0;					// NOTE: placeholder name
	int unknownB4;					// NOTE: placeholder name
	char padB8[8];
	bool unknownC0;					// NOTE: placeholder name
	int unknownC4;					// NOTE: placeholder name
	int unknownC8;					// NOTE: placeholder name
	char padCC[4];
	unsigned int unknownD0;			// NOTE: placeholder name (tickCount)
	unsigned int unknownD4;			// NOTE: placeholder name (tickCount)
	char padD8[4];
	vector<EntityEffect *> effects;	// NOTE: placeholder name
	Inventory *inventory;			// NOTE: placeholder name
	char padF0[0x134 - 0xf0];
	HItemList items;				// NOTE: placeholder name
};

int Entity::unknown45a810()
{
	return unknown5ca210() - unknown5c8e20(NULL);
}

int *Entity::unknown45a840()
{
	return slots;
}

int Entity::getSlotTotal()
{
	return sumArray(slots,4);
}

int Entity::unknown45a880()
{
	return unknown8c * 100 / unknown5ca260();
}

int Entity::unknown45a8b0()
{
	return unknown5ca260() - unknown8c;
}

int Entity::unknown45a8d0()
{
	return unknown90;
}

int Entity::unknown45a8f0()
{
	return unknown45a8d0() * 100 / unknown5ca400();
}

int Entity::unknown45a920()
{
	return unknown94;
}

int Entity::unknown45a940()
{
	int max = unknown5ca670();
	return max == 0 ? 0 : unknown45a920() * 100 / unknown5ca670();
}

int Entity::unknown45a990()
{
	return unknown98;
}

vector<int> *Entity::unknown45a9b0()
{
	return &unknown9c;
}

int Entity::unknown45a9d0()
{
	return unknownB0;
}

int Entity::unknown45a9f0()
{
	return unknownB4;
}

bool Entity::unknown45aa10()
{
	return unknownC0;
}

int Entity::unknown45aa30()
{
	return unknownC4;
}

int Entity::unknown45aa50()
{
	return unknownC8;
}

bool Entity::isHostileTo(HEntity entity)
{
	return unknown5cb680(entity->group);
}

bool Entity::unknown45aaa0(HEntity entity)
{
	return isInGroup(entity->group);
}

bool Entity::unknown45aad0(HEntity entity)
{
	return unknown5cb6e0(entity->group);
}

HItemList *Entity::getInventoryList()
{
	return &items;
}

bool Entity::unknown45ab20(const string &itemName)
{
	for (unsigned int i = 0; i < items.count(); i++)
	{
		if (items.at(i)->unknown457860() == itemName)
			return true;
	}
	return false;
}

int Entity::unknown45ab90()
{
	return unknown88;
}

bool Entity::unknown45abb0()
{
	return unknownD0 && tickCount <= unknownD0 + 2000;
}

bool Entity::unknown45ac00()
{
	return unknownD4 && tickCount <= unknownD4 + 100;
}

EntityEffect *Entity::unknown45ac40(int type)
{
	for (unsigned int i = 0; i < effects.size(); i++)
	{
		if (effects[i]->def->type == type)
			return effects[i];
	}
	return NULL;
}

int Entity::unknown45acb0(int type)
{
	for (unsigned int i = 0; i < effects.size(); i++)
	{
		if (effects[i]->def->type == type)
			return effects[i]->value;
	}
	return 0;
}

bool Entity::unknown45ad20(const string &effectName)
{
	for (unsigned int i = 0; i < effects.size(); i++)
	{
		if (effects[i]->def->name == effectName)
			return true;
	}
	return false;
}

Inventory *Entity::getInventory()
{
	return inventory;
}
