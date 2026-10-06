// c085: Entity effect / inventory helpers (0x637a50-0x63c660), matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members and names are placeholders unless stated.
#include <string>
#include <vector>
using namespace std;

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

struct EntityEffectDef	// NOTE: placeholder name
{
	int		type;	// NOTE: placeholder name
	string	name;	// NOTE: placeholder name
};

struct EntityEffect	// NOTE: placeholder name
{
	EntityEffectDef	*def;	// NOTE: placeholder name
	int				value;	// NOTE: placeholder name

	EntityEffect(EntityEffectDef *def_, int value_) throw();
};

class Inventory	// NOTE: placeholder name
{
public:
	Inventory() throw();
	~Inventory();
	int pad[5];
	vector<HItem *> *getItems();	// NOTE: placeholder name
	bool unknown4563e0(Item *item);	// NOTE: placeholder name
	void unknown456660(Item *item);	// NOTE: placeholder name
	void unknown456780(Inventory *other, bool b);	// NOTE: placeholder name
	bool unknown456860();	// NOTE: placeholder name
	bool unknown4568c0();	// NOTE: placeholder name
};

struct Unknown_A	// NOTE: placeholder name
{
	char pad0[0x140];
	int unknown140;	// NOTE: placeholder name
};

struct Unknown_B	// NOTE: placeholder name
{
	char pad0[0x7c];
	string unknown7c;	// NOTE: placeholder name
	bool unknown98;	// NOTE: placeholder name
};

struct Unknown_C	// NOTE: placeholder name
{
	int pad0;
	bool unknown4;	// NOTE: placeholder name
	char pad5[7];
	Unknown_B *unknownC;	// NOTE: placeholder name
};

class Item	// NOTE: placeholder layout
{
public:
	char pad0[0x3c];
	int type;	// NOTE: placeholder name
	char pad40[0x62 - 0x40];
	bool unknown62;	// NOTE: placeholder name
	char pad63[0x7c - 0x63];
	int unknown7c;	// NOTE: placeholder name
	char pad80[0xc0 - 0x80];
	vector<Unknown_A *> unknownC0;	// NOTE: placeholder name
};

class BS	// NOTE: placeholder name (the object behind the global at 0xcefc4c)
{
public:
	void addEntity(int entityID, int cellID);	// NOTE: placeholder name
};
extern BS *world;	// NOTE: placeholder name (0xcefc4c)
extern vector<EntityEffectDef *> effectDefs;	// NOTE: placeholder name (0xd2f0f8)
extern vector<int> unknown_d2c408;
extern int unknown_caf168;	// NOTE: placeholder name (0xcaf168)
extern vector<Unknown_B *> unknown_cf3a20;	// NOTE: placeholder name (0xcf3a20)
extern vector<Unknown_C *> unknown_d02cb4;	// NOTE: placeholder name (0xd02cb4)	// NOTE: placeholder name (0xd2c408)

bool unknown9d7de0(vector<int> *v, int key, int *out);	// NOTE: placeholder name

void unknown9de640(vector<HItem *> *v, unsigned int *i);	// NOTE: placeholder name

int unknown639350(Item *item);	// NOTE: placeholder name

struct EffectPair	// NOTE: placeholder name
{
	int a;
	int b;

	EffectPair(int a_, int b_) throw();
};

class Entity
{
public:
	EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	EffectPair *unknown45b010(vector<EffectPair *> *v, int key);	// NOTE: placeholder name
	void unknown45b340(EntityEffect *e);	// NOTE: placeholder name
	void unknown45b4c0(int a, bool b);	// NOTE: placeholder name

	int unknown639530(int type, int value);	// NOTE: placeholder name
	void unknown6395d0(Item *item, bool b);	// NOTE: placeholder name
	bool unknown6396a0(int key, bool b);	// NOTE: placeholder name
	void unknown6396f0(int key, bool b);	// NOTE: placeholder name
	void unknown639470(int type, int value);	// NOTE: placeholder name
	void unknown639730(bool b);	// NOTE: placeholder name
	void unknown639800(Inventory *other);	// NOTE: placeholder name
	void unknown639870();	// NOTE: placeholder name
	void unknown6398e0();	// NOTE: placeholder name
	void unknown639950(vector<EffectPair *> *v, int key, int amount);	// NOTE: placeholder name

	char pad0[4];
	int ID;	// NOTE: placeholder name
	char pad8[0xcc - 8];
	int unknownCC;	// NOTE: placeholder name
	char padD0[0xdc - 0xd0];
	vector<EntityEffect *> effects;	// NOTE: placeholder name
	Inventory *inventory;	// NOTE: placeholder name
};

void Entity::unknown639470(int type, int value)
{
	for (unsigned int i = 0; i < effects.size(); i++)
	{
		if (effects[i]->def->type == type)
		{
			effects[i]->value = value;
			return;
		}
	}
	unknown45b340(new EntityEffect(effectDefs[type], value));
}

int Entity::unknown639530(int type, int value)
{
	EntityEffect *e = unknown45ac40(type);
	if (e)
	{
		e->value += value;
		return e->value;
	}
	else
	{
		effects.push_back(new EntityEffect(effectDefs[type], value));
		return value;
	}
}

void Entity::unknown6395d0(Item *item, bool b)
{
	if (inventory == NULL)
	{
		Inventory *inv = new Inventory();
		inventory = inv;
	}
	else if (!b && inventory->unknown4563e0(item))
	{
		return;
	}
	inventory->unknown456660(item);
	if (item->type == 0x39)
	{
		world->addEntity(ID, unknown639350(item));
		if (item->unknown7c)
			unknownCC = 1;
	}
}

bool Entity::unknown6396a0(int key, bool b)
{
	int v;
	if (unknown9d7de0(&unknown_d2c408, key, &v))
	{
		unknown6395d0((Item *)v, b);
		return true;
	}
	return false;
}

void Entity::unknown6396f0(int key, bool b)
{
	int v;
	if (unknown9d7de0(&unknown_d2c408, key, &v))
		unknown45b4c0(v, b);
}

void Entity::unknown639730(bool b)
{
	if (inventory)
	{
		if (b)
		{
			vector<HItem *> *items = inventory->getItems();
			for (unsigned int i = 0; i < items->size(); i++)
			{
				if (!(*items)[i]->operator->()->unknown62)
					unknown9de640(items, &i);
			}
			if (!items->empty())
				return;
		}
		delete inventory;
		inventory = NULL;
	}
}

void Entity::unknown639800(Inventory *other)
{
	if (inventory)
	{
		inventory->unknown456780(other, true);
		delete other;
	}
	else
		inventory = other;
}

void Entity::unknown639870()
{
	if (inventory)
	{
		if (inventory->unknown456860())
		{
			delete inventory;
			inventory = NULL;
		}
	}
}

void Entity::unknown6398e0()
{
	if (inventory)
	{
		if (inventory->unknown4568c0())
		{
			delete inventory;
			inventory = NULL;
		}
	}
}

void Entity::unknown639950(vector<EffectPair *> *v, int key, int amount)
{
	EffectPair *e = unknown45b010(v, key);
	if (e)
		e->b += amount;
	else
	{
		EffectPair *n = new EffectPair(key, amount);
		e = n;
		v->push_back(e);
	}
}

int unknown639350(Item *item)
{
	int result = 0;
	if (item->unknownC0[0]->unknown140 != unknown_caf168)
	{
		if (!unknown_cf3a20[item->unknownC0[0]->unknown140]->unknown7c.empty())
		{
			result = 1;
		}
		else
		{
			result = 1;
			Unknown_B *b = unknown_cf3a20[item->unknownC0[0]->unknown140];
			if (b->unknown98)
				return result;
			for (unsigned int j = 0; j < unknown_d02cb4.size(); j++)
			{
				if (unknown_d02cb4[j]->unknownC == b)
				{
					if (unknown_d02cb4[j]->unknown4)
						result = 2;
					break;
				}
			}
		}
	}
	return result;
}
