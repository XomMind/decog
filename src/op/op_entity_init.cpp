// op_entity_init: Entity::init (0x5c4640), stores the entity's own handle, equips its loadout and the
// procedurally generated parts of class 0x31/0x22 robots, then resolves a negative integrity percentage
// (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
#include "../../src/util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

void logError(string location, string message);	// 0x404f10

struct HEntity
{
	int ID;
	HEntity() throw();	// 0x9b6590
};

class Item
{
public:
	int getType();	// 0x44aec0
	int getNestedField();	// 0x457820
	int unknown457880();	// NOTE: placeholder name (Sweep_457880::getNestedField)
	int unknown457920();	// NOTE: placeholder name (Calls_457920::delegate)
	int unknown577790();	// NOTE: placeholder name
	void unknown57a190(HEntity owner, int slot, int a, int b);	// NOTE: placeholder name
};

struct HItem
{
	int ID;
	HItem() throw();
	Item *operator->() const;	// 0x9b65b0
};

struct OpEI_ItemSub	// NOTE: placeholder layout
{
	char pad00[0x2c];
	int kind;	// 0x2c
};

struct OpEI_ItemRecord	// NOTE: placeholder layout (ItemType)
{
	int id;	// 0x00
	char pad04[4];
	string name;	// 0x08
	char pad24[0x40 - 0x24];
	int category;	// 0x40
	int slotType;	// 0x44
	int slot;	// 0x48
	int slotCount;	// 0x4c
	char pad50[0x60 - 0x50];
	int weight;	// 0x60
	char pad64[0xf0 - 0x64];
	int type;	// 0xf0
	int rating;	// 0xf4
	char padf8[0x138 - 0xf8];
	int f138;	// 0x138
	char pad13c[0x14c - 0x13c];
	int f14c;	// 0x14c
	char pad150[0x1a0 - 0x150];
	OpEI_ItemSub *sub;	// 0x1a0
	char pad1a4[0x239 - 0x1a4];
	bool f239;	// 0x239
};

struct OpEI_Loadout	// NOTE: placeholder layout
{
	int itemID;
	int count;
	int weight;
};

struct OpEI_EntityRecord	// NOTE: placeholder layout
{
	char pad00[4];
	string name;	// 0x04
	char pad20[0x28 - 0x20];
	int kind;	// 0x28
	char pad2c[0x160 - 0x2c];
	vector<vector<OpEI_Loadout *> > loadouts;	// 0x160
};

template <class T>
class OpR5h_WL	// NOTE: placeholder name (weighted list)
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	OpR5h_WL(const int *w, int count);	// 0x9ba790
	void reset();	// NOTE: placeholder name (0x9c07a0)
	void add(T value, int weight);	// 0x9ba310
	void remove(T value);	// 0x9bab80
	bool contains(T value);	// 0x9ba080
	T &pick();	// 0x9ba470
	T &pickNoThrow() throw();	// NOTE: placeholder name (pick, 0x9ba470); throw() keeps the temporary list out of the EH states
	unsigned int size();	// NOTE: placeholder name (0x9b81d0)
	bool empty();	// NOTE: placeholder name (0x9b81b0)
};

class OpEI_Factory	// NOTE: placeholder name (0xcefaa8)
{
public:
	HItem createItem(OpEI_ItemRecord *record);	// NOTE: placeholder name (0x7932b0)
};

class OpEI_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	OpEI_ItemRecord *selectRandomItem(int chanceType, int rating, int category);	// 0x6c3bc0
};

class OpEI_PlayerData	// NOTE: placeholder name (PlayerData, 0xcf45d8)
{
public:
	void unknown77ffb0(int itemTypeID, int flag);	// NOTE: placeholder name
};

class Entity	// NOTE: placeholder layout
{
	char pad00[4];
public:
	HEntity self;	// 0x04
	OpEI_EntityRecord *record;	// 0x08
	char pad0c[0x78 - 0x0c];
	int slotCapacity[4];	// 0x78
	int integrity;	// 0x88, NOTE: placeholder name
	char pad8c[0x134 - 0x8c];
	vector<HItem> items;	// 0x134
	char pad144[0x148 - 0x144];

	void init(HEntity self_);	// 0x5c4640
	bool unknown45a780();	// NOTE: placeholder name
	int unknown45a7b0();	// NOTE: placeholder name
	int unknown5c92e0(int slot);	// NOTE: placeholder name
	int unknown5ca8d0();	// NOTE: placeholder name
	int unknown5ca960();	// NOTE: placeholder name
	bool unknown5d26e0(int type);	// NOTE: placeholder name
	bool unknown5d6c30(vector<HItem> *out);	// NOTE: placeholder name
	int unknown5d6d80(vector<HItem> *items, HEntity target);	// NOTE: placeholder name
	int unknown5d7320(vector<HItem> *list, bool notify);	// NOTE: placeholder name
	void unknown5de480(OpEI_ItemRecord *record);	// NOTE: placeholder name
	int unknown5de7b0();	// NOTE: placeholder name
	void unknown5deb40(int value);	// NOTE: placeholder name
	void unknown5ded70(int value);	// NOTE: placeholder name
};

void opEI_fillInts(int *list, unsigned int count, int value);	// NOTE: placeholder name (OpX5_fillInts)
bool opEI_isBetween(int low, int value, int high);	// NOTE: placeholder name (0x9daf80)
OpEI_ItemRecord *opEI_randomRec(vector<OpEI_ItemRecord *> &v);	// NOTE: placeholder name (OpU8a_randomRec)
void opEI_eraseAt(vector<OpEI_ItemRecord *> &v, unsigned int &index);	// NOTE: placeholder name (0x9ce6d0)
bool opEI_removeValue(vector<OpEI_ItemRecord *> &v, OpEI_ItemRecord *value);	// NOTE: placeholder name (0x9d51d0)
bool opEI_contains(vector<int> &v, int value);	// NOTE: placeholder name (0x9db330)
void opEI_insertAt(vector<HItem> &v, int index, HItem item);	// NOTE: placeholder name (0x9d8fc0)
void opEI_eraseRange(vector<HItem> &v, int first, int last);	// NOTE: placeholder name (0x9d9530)

extern vector<OpEI_ItemRecord *> opEI_itemRecords;	// NOTE: placeholder name (0xd2d1c4)
extern vector<int> opEI_known_cf4830;	// NOTE: placeholder name (0xcf4830)
extern OpEI_PlayerData opEI_playerData;	// NOTE: placeholder name (0xcf45d8)
extern OpEI_Factory *opEI_factory;	// NOTE: placeholder name (0xcefaa8)
extern OpEI_World *opEI_world;	// NOTE: placeholder name (0xcefc4c)
extern bool opEI_flag_cefacd;	// NOTE: placeholder name (0xcefacd)
extern int opEI_mode_caf130;	// NOTE: placeholder name (0xcaf130)
extern const int opEI_tierWeights_b9386c[];	// NOTE: placeholder name (0xb9386c)

void Entity::init(HEntity self_)
{
	self = self_;
	OpEI_Loadout *p;
	int slots[4];
	OpEI_ItemRecord *rec;
	opEI_fillInts(slots,4,0);
	for (unsigned int i = 0; i < record->loadouts.size(); i++)
	{
		OpR5h_WL<OpEI_Loadout *> options;
		for (unsigned int j = 0; j < record->loadouts[i].size(); j++)
			options.add(record->loadouts[i][j],record->loadouts[i][j]->weight);
		p = options.pick();
		rec = opEI_itemRecords[p->itemID];
		for (int k = 0; k < p->count; k++)
		{
			if (opEI_isBetween(0x7e,rec->type,0x93))
				opEI_factory->createItem(rec)->unknown57a190(self,4,0,0);
			else
			{
				if (rec->slot == 5)
				{
					logError("Entity::init()","Item (" + rec->name + ") has no applicable slot");
					continue;
				}
				if (slots[rec->slot] + rec->slotCount > slotCapacity[rec->slot])
				{
					logError("Entity::init()","Entity (" + record->name + ") doesn't have enough free slots to equip " + rec->name);
					continue;
				}
				slots[rec->slot] += rec->slotCount;
				unknown5de480(rec);
				if (opEI_flag_cefacd && record->kind == 0 && opEI_known_cf4830[rec->id] == 0)
					opEI_playerData.unknown77ffb0(rec->id,0);
			}
		}
	}

	switch (record->kind)
	{
	case 0x31:
		{
			if (opEI_mode_caf130 == 6)
				break;
			OpEI_ItemRecord *item;
			vector<OpEI_ItemRecord *> pool;
			for (unsigned int i = 0; i < opEI_itemRecords.size(); i++)
				if (opEI_itemRecords[i]->category == 0x1b)
					pool.push_back(opEI_itemRecords[i]);
			if (rng.chance(75))
			{
				OpR5h_WL<OpEI_ItemRecord *> options;
				for (unsigned int i = 0; i < pool.size(); i++)
					if (pool[i]->slot == 0)
						options.add(pool[i],pool[i]->weight);
				if (options.size())
					unknown5de480(options.pick());
			}
			else
			{
				item = opEI_world->selectRandomItem(2,0x1f,0);
				if (item)
					unknown5de480(item);
			}
			for (int n = rng.chance(60) ? 2 : 1; n > 0; n--)
			{
				if (rng.chance(80))
				{
					OpR5h_WL<OpEI_ItemRecord *> options;
					for (unsigned int i = 0; i < pool.size(); i++)
						if (pool[i]->slotType == 10)
							options.add(pool[i],pool[i]->weight);
					if (options.size())
						unknown5de480(options.pick());
				}
				else
				{
					item = opEI_world->selectRandomItem(2,10,0x12);
					if (item)
						unknown5de480(item);
				}
			}
			if (rng.chance(10))
			{
				OpR5h_WL<OpEI_ItemRecord *> options;
				for (unsigned int i = 0; i < pool.size(); i++)
					if (pool[i]->slotType == 12 || pool[i]->slotType == 13)
						options.add(pool[i],pool[i]->weight);
				if (options.size())
					unknown5de480(options.pick());
			}
			for (int n = rng.chance(5) ? 3 : (rng.chance(15) ? 2 : (rng.chance(30) ? 1 : 0)); n > 0; n--)
			{
				if (rng.chance(50))
				{
					OpR5h_WL<OpEI_ItemRecord *> options;
					for (unsigned int i = 0; i < pool.size(); i++)
						if (pool[i]->slot == 2)
							options.add(pool[i],pool[i]->weight);
					if (options.size())
						unknown5de480(options.pick());
				}
				else
				{
					item = opEI_world->selectRandomItem(2,0x1f,2);
					if (item)
						unknown5de480(item);
				}
			}
			if (rng.chance(15))
			{
				if (rng.chance(75))
				{
					OpR5h_WL<OpEI_ItemRecord *> options;
					for (unsigned int i = 0; i < pool.size(); i++)
						if (pool[i]->slot == 3)
							options.add(pool[i],pool[i]->weight);
					if (options.size())
						unknown5de480(options.pick());
				}
				else
				{
					item = opEI_world->selectRandomItem(2,0x1f,3);
					if (item)
						unknown5de480(item);
				}
			}
		}
		break;
	case 0x22:
		{
			if (record->name == "V2")
				break;
			vector<OpEI_ItemRecord *> list;
			for (unsigned int i = 0; i < opEI_itemRecords.size(); i++)
				if (opEI_itemRecords[i]->f239)
					list.push_back(opEI_itemRecords[i]);
			vector<OpEI_ItemRecord *> chosen;
			for (unsigned int i = 0; i < list.size(); i++)
				if (list[i]->slotType == 12)
					chosen.push_back(list[i]);
			int left = rng.rangeInt(3,4);
			OpEI_ItemRecord *item;
		retry:
			item = opEI_randomRec(chosen);
			while (left != 0 && item->slotCount <= left)
			{
				unknown5de480(item);
				left -= item->slotCount;
			}
			if (left != 0)
			{
				for (unsigned int i = 0; i < chosen.size(); i++)
					if (chosen[i]->slotCount > 1)
						opEI_eraseAt(chosen,i);
				goto retry;
			}

			int selection = OpR5h_WL<int>(opEI_tierWeights_b9386c,8).pickNoThrow();
			vector<int> slot;
			switch (selection)
			{
			case 0:
			case 1:
				{
					int count = selection == 0 ? 3 : 4;
					bool same = rng.chance(33);
					for (int i = 0; i < count; i++)
					{
						if (i > 0 && !same)
							slot.push_back(slot[0]);
						else
							slot.push_back(rng.chance(50) ? 0x14 : 0x16);
					}
				}
				break;
			case 2:
			case 3:
				{
					int count = selection == 2 ? 1 : 2;
					bool same = rng.chance(33);
					for (int i = 0; i < count; i++)
					{
						if (i > 0 && !same)
							slot.push_back(slot[0]);
						else
							slot.push_back(rng.chance(50) ? 0x15 : 0x17);
					}
				}
				break;
			case 4:
				slot.push_back(0x18);
				break;
			case 5:
				slot.assign(2u,rng.chance(50) ? 0x14 : 0x16);
				slot.push_back(0x18);
				break;
			case 6:
			case 7:
				{
					int count = selection == 6 ? 2 : 3;
					bool same = rng.chance(50);
					for (int i = 0; i < count; i++)
					{
						if (i > 0 && !same)
							slot.push_back(slot[0]);
						else
							slot.push_back(rng.rangeInt(26,28));
					}
				}
				break;
			}

			vector<OpEI_ItemRecord *> queue;
			left = unknown5c92e0(3);
			for (unsigned int i = 0; i < slot.size(); i++)
			{
				if (i == 0 || slot[i] != slot[i - 1])
				{
					chosen.clear();
					for (unsigned int j = 0; j < list.size(); j++)
						if (list[j]->slotType == slot[i])
							chosen.push_back(list[j]);
				}
				do
				{
					if (i == 0 || slot[i] != slot[i - 1] || rng.chance(33) || item == NULL)
						item = opEI_randomRec(chosen);
					if (item->slotCount > left)
					{
						opEI_removeValue(chosen,item);
						item = NULL;
					}
				} while (item == NULL);
				unknown5de480(item);
				queue.push_back(item);
				if ((left -= item->slotCount) == 0)
					break;
			}

			left = 3;
			OpR5h_WL<int> choice;
			if (selection <= 5)
			{
				choice.add(10,100);
				choice.add(0x55,100);
				choice.add(0x57,100);
				choice.add(0x58,100);
				choice.add(0x50,100);
				choice.add(0x5e,100);
				for (unsigned int i = 0; i < queue.size(); i++)
				{
					if (queue[i]->f138)
					{
						choice.add(0x5f,100);
						break;
					}
				}
				if (opEI_contains(slot,0x16) || opEI_contains(slot,0x17))
				{
					choice.add(0x69,100);
					for (unsigned int i = 0; i < queue.size(); i++)
					{
						if (queue[i]->f14c)
						{
							choice.add(0x63,100);
							break;
						}
					}
				}
				if (opEI_contains(slot,0x14) || opEI_contains(slot,0x15))
				{
					choice.add(0x67,100);
					if (slot.size() == 1 && slot[0] == 0x15)
						choice.add(0x4e,300);
				}
			}
			if (selection == 4)
				choice.add(0x4f,100);
			if (selection == 4 || selection == 5)
				choice.add(0x5d,100);
			if (selection != 4 && selection != 5)
			{
				choice.add(0x60,100);
				choice.add(0x62,100);
				choice.add(0xa7,selection > 5 ? 200 : 100);
			}
			if (selection > 5)
			{
				choice.add(0x5a,100);
				choice.add(0x5b,100);
				choice.add(0x5c,100);
				choice.add(0x51,100);
				choice.add(0x6c,100);
				choice.add(0x6a,100);
			}
			int id;
			while (left != 0 && !choice.empty())
			{
				id = choice.pick();
				choice.remove(id);
				chosen.clear();
				for (unsigned int i = 0; i < list.size(); i++)
					if (list[i]->type == id)
						chosen.push_back(list[i]);
				item = opEI_randomRec(chosen);
				if (left < item->slotCount)
					continue;
				unknown5de480(item);
				left -= item->slotCount;
			}

			left = 2;
			chosen.clear();
			for (unsigned int i = 0; i < list.size(); i++)
				if (list[i]->slotType == 0x12)
					chosen.push_back(list[i]);
			vector<int> entries;
			while (left != 0)
			{
				item = opEI_randomRec(chosen);
				if (left < item->slotCount)
					continue;
				unknown5de480(item);
				if (item->type != 0)
					entries.push_back(item->type);
				left -= item->slotCount;
			}

			left = rng.rangeInt(2,3);
			choice.reset();
			choice.add(0x54,100);
			choice.add(0x4b,100);
			if (!opEI_contains(entries,0x2f))
				choice.add(0x2f,100);
			if (!opEI_contains(entries,0x30))
			{
				choice.add(0x30,100);
				choice.add(0x37,100);
			}
			if (!opEI_contains(entries,0x31))
				choice.add(0x31,100);
			if (!opEI_contains(entries,0x32))
				choice.add(0x32,100);
			choice.add(0x38,100);
			choice.add(0x43,100);
			choice.add(0x44,100);
			choice.add(0x48,100);
			choice.add(0x29,100);
			while (left != 0 && !choice.empty())
			{
				id = choice.pick();
				choice.remove(id);
				chosen.clear();
				for (unsigned int i = 0; i < list.size(); i++)
					if (list[i]->type == id)
						chosen.push_back(list[i]);
				item = opEI_randomRec(chosen);
				if (left < item->slotCount)
					continue;
				unknown5de480(item);
				left -= item->slotCount;
			}

			if (unknown45a780() && rng.chance(25))
			{
				chosen.clear();
				for (unsigned int i = 0; i < list.size(); i++)
					if (list[i]->type == 0x22)
						chosen.push_back(list[i]);
				item = opEI_randomRec(chosen);
				if (item->rating >= unknown45a7b0() + 4)
					unknown5de480(item);
			}

			left = unknown5c92e0(2);
			choice.reset();
			if (rng.chance(66))
				choice.add(rng.chance(50) ? 1 : 2,100);
			vector<HItem> found;
			if (!choice.contains(2) && rng.chance(50))
			{
				unknown5d6c30(&found);
				int a = unknown5ca960();
				int b = unknown5ca8d0() + unknown5d7320(&found,false);
				int total = unknown5d6d80(&found,HEntity());
				if (a * total / 100 < b * total / 100)
					choice.add(3,100);
			}
			bool changed = false;
			bool ok = false;
			for (unsigned int i = 0; i < queue.size(); i++)
			{
				if (queue[i]->slotType == 0x18)
				{
					switch (queue[i]->sub->kind)
					{
					case 3:
						ok = true;
						break;
					case 2:
						changed = true;
						break;
					}
				}
			}
			bool matter = unknown5d26e0(0x43) || unknown5d26e0(0x44);
			if (ok || matter || opEI_contains(slot,0x14) || opEI_contains(slot,0x15))
			{
				if (rng.chance(33))
				{
					chosen.clear();
					for (unsigned int i = 0; i < list.size(); i++)
						if (list[i]->slot == 0)
							chosen.push_back(list[i]);
					item = opEI_randomRec(chosen);
					unknown5de480(item);
				}
				else if (matter)
					choice.add(8,100);
				else
					choice.add(rng.chance(50) ? 8 : 0x65,100);
			}
			if (changed || opEI_contains(slot,0x16) || opEI_contains(slot,0x17))
			{
				switch (rng.rangeInt(1,3))
				{
				case 1:
					choice.add(9,100);
					break;
				case 2:
					choice.add(100,100);
					break;
				case 3:
					choice.add(0x9c,100);
					break;
				}
			}
			while (!choice.empty())
			{
				id = choice.pick();
				choice.remove(id);
				chosen.clear();
				for (unsigned int i = 0; i < list.size(); i++)
					if (list[i]->type == id)
						chosen.push_back(list[i]);
				item = opEI_randomRec(chosen);
				if (left < item->slotCount)
					continue;
				unknown5de480(item);
				left -= item->slotCount;
			}

			vector<HItem> vec(items);
			items.clear();
			items.push_back(vec[0]);
			for (unsigned int i = 1; i < vec.size(); i++)
			{
				if (vec[i]->getNestedField() >= items.back()->getNestedField())
					items.push_back(vec[i]);
				else
				{
					for (unsigned int j = 0; j < items.size(); j++)
					{
						if (vec[i]->getNestedField() < items[j]->getNestedField())
						{
							opEI_insertAt(items,j,vec[i]);
							break;
						}
					}
				}
			}
			if (selection > 5)
			{
				for (unsigned int i = 0; i < items.size(); i++)
				{
					if (opEI_isBetween(0x1a,items[i]->unknown457880(),0x1c))
					{
						int first = i;
						int count = 1;
						for (unsigned int j = i + 1; j < items.size(); j++)
						{
							if (opEI_isBetween(0x1a,items[i]->unknown457880(),0x1c))
								count++;
							else
								break;
						}
						vector<HItem> current(items.begin() + first,items.begin() + first + count);
						if (!current.empty())
						{
							vector<HItem> sorted;
							sorted.push_back(current.back());
							current.pop_back();
							while (!current.empty())
							{
								if (sorted.back()->unknown457920() > current.back()->unknown457920())
								{
									sorted.push_back(current.back());
									current.pop_back();
								}
								else
								{
									for (unsigned int k = 0; k < sorted.size(); k++)
									{
										if (current.back()->unknown457920() >= sorted[k]->unknown457920())
										{
											opEI_insertAt(sorted,k,current.back());
											current.pop_back();
											break;
										}
									}
								}
							}
							current = sorted;
						}
						opEI_eraseRange(items,first,first + count - 1);
						items.insert(items.begin() + first,current.begin(),current.end());
					}
				}
			}
			unknown5deb40(10000);
			unknown5ded70(10000);
		}
		break;
	case 8:
		unknown5de7b0();
		break;
	}

	if (integrity < 0)
	{
		float sum = 0;
		float percent = (float)-integrity;
		if (items.empty())
			integrity = 100;
		else
		{
			for (unsigned int i = 0; i < items.size(); i++)
				if (items[i]->getType() <= 3)
					sum += items[i]->unknown577790();
			integrity = (int)(-(sum * percent) / (percent - 100.0));
		}
	}
}
