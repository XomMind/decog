// BattleScape (BS) methods matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members and names are placeholders.
#include <string>
#include <vector>
using namespace std;
#include "../util/rng.h"
#include "../util/stringutil.h"

void logError(string location, string message);	// NOTE: placeholder name (0x404f10)

extern RNG rng;	// NOTE: placeholder name (0xd30908)

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(int x_, int y_);
	Point(const Point &p);
	Point &operator=(const Point &p);	// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
};

string pointToString(const Point &p);	// NOTE: placeholder name (0x40a4a0)
void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)

class Entity;
class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();
	bool isValid() const;
	Entity *operator->() const;
};

class Item	// NOTE: placeholder layout
{
public:
	const string &getName();	// NOTE: placeholder name (0x457860)
	int unknown4578a0();	// NOTE: placeholder name
	int unknown4578c0();	// NOTE: placeholder name
	void unknown57a190(HEntity entity, int value, bool flag1, bool flag2);	// NOTE: placeholder name
	void unknown57a0f0(const Point &p, bool flag1, bool flag2);	// NOTE: placeholder name
	void unknown57dbe0(bool flag1, bool flag2, bool flag3, bool flag4);	// NOTE: placeholder name
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
	Item *operator->() const;	// 0x9b65b0
};

class Prop;
class HProp	// NOTE: placeholder layout
{
	int ID;
public:
	HProp();
	Prop *operator->() const;	// 0x9b64f0
};

class Cell	// NOTE: placeholder layout
{
public:
	HProp getProp();	// 0x45d550
	HEntity getEntity();	// 0x45d250
	HItem getItem();	// NOTE: placeholder name (0x45d8f0)
	bool unknown45d7b0();	// NOTE: placeholder name
	int getTerrain();	// ICF'd with 0x9fcd80 (returns the first field)
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(const Point &p);	// 0x9ced70
};
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

struct ItemData	// NOTE: placeholder name
{
	char pad[0x3c];
	int type;	// NOTE: placeholder name
	char pad40[0x7c - 0x40];
	int unknown7c;	// NOTE: placeholder name
};

class Inventory	// NOTE: placeholder name
{
public:
	bool hasType(int type);	// NOTE: placeholder name (0x456490)
	ItemData *findType(int type);	// NOTE: placeholder name (0x4564e0)

	vector<Cell *> slots;	// NOTE: placeholder name (elements are slot objects whose first field is the item)
};

class EntityAI	// NOTE: placeholder name
{
public:
	EntityAI(HEntity owner, int mode1, int mode2);	// 0x57f6a0

	char pad[0x130];
};

struct EntityRecord	// NOTE: placeholder name
{
	char pad[0x9c];
	int size;	// NOTE: placeholder name
};

class Entity	// NOTE: placeholder name
{
public:
	Point unknown5c80f0(const Point &p);	// NOTE: placeholder name
	void changePos(const Point &p, bool unknown);	// 0x5dccb0
	int getFaction();	// NOTE: placeholder name (0x45a2c0)
	const string &getName();	// NOTE: placeholder name (0x45a280)
	const string &getDisplayName();	// NOTE: placeholder name (0x45a280)
	const string &getLabel();	// NOTE: placeholder name (0x416f40)
	int unknown45a810();	// NOTE: placeholder name
	int unknown5c92e0(int value);	// NOTE: placeholder name
	bool isHostileTo(HEntity entity);	// NOTE: placeholder name (0x45aa70)
	Inventory *getInventory();	// NOTE: placeholder name (0x45ad90)
	void setAI(EntityAI *ai);	// NOTE: placeholder name (0x418da0)
	void setFlag(int flag);	// NOTE: placeholder name (0x44e360)
};

bool lookupID(const string &name, int &id);	// NOTE: placeholder name (0x9d7980)

class EffectInstance	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class EffectMgr	// NOTE: placeholder name
{
public:
	EffectInstance *create();	// NOTE: placeholder name (0x508610)
};
extern class BS *world;	// NOTE: placeholder name (0xcefc4c)
extern EffectMgr *effectMgr;	// NOTE: placeholder name (0xcefc50)
extern Point effectOrigin;	// NOTE: placeholder name (0xd2e20c)

struct ItemDef	// NOTE: placeholder name
{
	int ID;	// NOTE: placeholder name
	char pad04[0x44 - 4];
	int rating;	// NOTE: placeholder name
	char pad48[0x50 - 0x48];
	int tier;	// NOTE: placeholder name
	int unknown54;	// NOTE: placeholder name
	char pad58[0x5c - 0x58];
	int rarity;	// NOTE: placeholder name
	char pad60[0x68 - 0x60];
	int maxCount;	// NOTE: placeholder name
	char pad6c[0x94 - 0x6c];
	int prototype;	// NOTE: placeholder name

	bool matchesCategory(int category);	// NOTE: placeholder name (0x4570c0)
};
extern vector<ItemDef *> itemDefs;	// NOTE: placeholder name (0xd2d1c4)
extern ItemDef *itemTypeMatter;	// NOTE: placeholder name (0xcefbe4)
extern const int rarityWeight[];	// NOTE: placeholder name (0xba3acc)

bool unknown5714a0(int value);	// NOTE: placeholder name
bool unknown571520(int value, int other);	// NOTE: placeholder name
template <class T> T randomElement(vector<T> &v);	// NOTE: placeholder name (0x9d5d00)

// weighted list of items
template <class T>
class ItemSet	// NOTE: placeholder name
{
public:
	ItemSet();	// 0x9bab50
	~ItemSet();	// 0x700dd0
	void add(T item, int weight);	// NOTE: placeholder name (0x9ba310)
	bool pick(T &item);	// NOTE: placeholder name (0x9ba6a0)
	T &pickRandom();	// NOTE: placeholder name (0x9ba470)
	void remove(T item);	// NOTE: placeholder name (0x9bab80)
	int size();	// NOTE: placeholder name (0x9b81d0)

	vector<T> items;
	vector<int> weights;
	int totalWeight;
};

struct GameState	// NOTE: placeholder name
{
	int pad;
	int difficulty;	// NOTE: placeholder name
};

class HGameState	// NOTE: placeholder name (global handle at 0xd1e888)
{
	int ID;
public:
	GameState *operator->() const;	// 0x9b7910
};
extern HGameState gameState;	// NOTE: placeholder name (0xd1e888)
extern const float prototypeChance[][2];
extern int factionAttitude[];	// NOTE: placeholder name (0xbba058)	// NOTE: placeholder name (0xb8fe98)

class Group	// NOTE: placeholder name
{
public:
	void addMember(HEntity entity, bool unknown);	// NOTE: placeholder name (0x671280)
};

class HGroup	// NOTE: placeholder name
{
	int ID;
public:
	Group *operator->() const;	// 0x9b7250
};

class EntityMgr	// NOTE: placeholder name
{
public:
	HEntity createEntity(EntityRecord *record);	// NOTE: placeholder name (0x793200)
};
extern EntityMgr *entityMgr;	// NOTE: placeholder name (0xcefaa8)

class Event	// NOTE: placeholder name
{
public:
	Event(int type, void *data);	// 0x45e530

	char pad[0x10];
};

class HEvent	// NOTE: placeholder name
{
	int ID;
public:
	HEvent();
};

class EventQueue	// NOTE: placeholder name
{
public:
	HEvent add(Event *event, int delay);	// NOTE: placeholder name (0x672310)
};
extern EventQueue eventQueue;	// NOTE: placeholder name (0xd225a0)

namespace google { namespace protobuf {
class Arena;
class UnknownFieldSet;
namespace internal {
class InternalMetadataWithArena;
// NOTE: the exe's ICF folded these trivial functions with unrelated game code, so the calls
//	carry the protobuf names
template <typename T, typename Derived> class InternalMetadataWithArenaBase
{
public:
	InternalMetadataWithArenaBase(Arena *arena)	// 0x9f57e0, stores its argument
		: ptr_	(arena)
	{};

	Arena *ptr_;
};
template <typename T> class ExplicitlyConstructed
{
public:
	T *get_mutable() { return reinterpret_cast<T *>(this); };	// 0x9c0790, returns this
};
} } }
namespace Protobuf { class Stats; }

int unknown639350(ItemData *item);	// NOTE: placeholder name

struct TurnRecord;	// NOTE: placeholder name
void addMessage(int type, HEntity entity, const string &text, int flag);	// NOTE: placeholder name (0x49c610)

namespace Protobuf {
// NOTE: the exe's ICF folded this getter with Prop's data getter, so the call carries this name
class Stats_Hacking
{
public:
	virtual int GetCachedSize() const;	// 0x44b020, returns the field at +0x4c
};
}
struct PropData	// NOTE: placeholder name
{
	char pad[0x18];
	int uses;	// NOTE: placeholder name
	int cooldownTurn;	// NOTE: placeholder name
};
#define PROP_DATA(prop) ((PropData *)((Protobuf::Stats_Hacking *)(prop))->Protobuf::Stats_Hacking::GetCachedSize())

class Map	// NOTE: placeholder name
{
public:
	int getTurn();	// 0x464270
};

class GameData	// NOTE: placeholder name
{
public:
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
};
extern GameData gameData;	// NOTE: placeholder name (0xd1e860)
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
bool unknown5111e0(int id, const string &text, int a, int b, HEntity entity, HEntity other, const Point *at, int flag);	// NOTE: placeholder name
void unknown454260(const Point *p, int value);	// NOTE: placeholder name

class ConsoleA	// NOTE: placeholder name
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA *consoleA;	// NOTE: placeholder name (0xcec058)
class ConsoleB	// NOTE: placeholder name
{
public:
	void unknown7b4f10();	// NOTE: placeholder name
};
extern ConsoleB *consoleB;	// NOTE: placeholder name (0xcec0b4)
extern vector<Point> infestationLocations;	// NOTE: placeholder name (0xd20690)

class BS : public Map
{
public:
	void spawnInfestiationFromTrap(unsigned int infestationIndex);	// 0x736ad0
	EntityRecord *unknown6c5600(int a, int b, int c, int d);	// NOTE: placeholder name
	HEntity placeEntity(EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);	// 0x6c58c0
	bool findPlacement(const Point &position, Point &result, int size);	// NOTE: placeholder name (0x71c150)
	void unknown465700(HEntity entity, int value);	// NOTE: placeholder name

	ItemDef *selectRandomItem(int chanceType, int rating, int category);	// 0x6c3bc0
	ItemDef *selectRandomItemOfRating(int level, int mode, int chanceType, int rating, int category, int unknown, int attempt);	// 0x6c40e0
	void thrownItemArrived(HEntity thrower, HItem item, int mode, const Point &position, vector<TurnRecord *> *records);	// 0x7499f0
	static bool turnUpdate_51da30(vector<TurnRecord *> *records, int type, HEntity entity, HEntity other, HEntity unused, int unknown1, int unknown2);	// 0x51da30
	static bool turnUpdate_51da30(vector<TurnRecord *> *records, int type, HEntity entity, HEntity other, HItem item, int unknown1, int unknown2);	// 0x51da30
	bool unknown71bc10(const Point &p, Point &result);	// NOTE: placeholder name
	bool unknown71ec60(const Point &p, vector<Point> points);	// NOTE: placeholder name
	void displayHack(HEntity source, const Point &target, bool success);	// 0x734ae0
	void displayFabricatorOverloadZap(const Point &lvl, HEntity entity);	// 0x7273e0

	bool isVisible(const Point &p);	// NOTE: placeholder name (0x4631c0)
	char pad[0x4c];
	vector<HGroup> groups;	// NOTE: placeholder name
	char pad5c[0x68 - 0x5c];
	ItemSet<int> itemSets[2];	// NOTE: placeholder name
	vector<int> itemUses;	// NOTE: placeholder name
	char padc0[0x66c - 0xc0];
	HEntity player;	// NOTE: placeholder name

	void getPath(HEntity from, const Point &to, vector<Point> &path, vector<int> &a, vector<int> &b,
		Point &end, int flag1, int flag2, int flag3, int flag4);	// NOTE: placeholder name (0x7170a0)
};

void BS::displayFabricatorOverloadZap(const Point &lvl, HEntity entity)
{
	if (lvl == entity->unknown5c80f0(lvl))
	{
		logError("BS::displayFabricatorOverloadZap()","Zapping self?");
		return;
	}
	int effectID;
	lookupID("Overload_Zap",effectID);
	if (effectID != 0)
	{
		vector<Point> path;
		vector<int> dirs;	// NOTE: placeholder name
		vector<int> frames;	// NOTE: placeholder name
		Point end;
		getPath(entity,lvl,path,dirs,frames,end,0,4,1,1);
		for (unsigned int i = 1; i < path.size() - 1; i++)
		{
			if (isVisible(path[i]))
				effectMgr->create()->init(effectMgr,effectID,path[i],effectOrigin,0,0,0,frames[i],0);
		}
	}
}

ItemDef *BS::selectRandomItem(int chanceType, int rating, int category)
{
	if ((chanceType != 1 && rating == 31 && category == 18 && rng.chance(prototypeChance[gameState->difficulty][0])) || rating <= 3)
		return itemTypeMatter;
	bool prototype;
	switch (chanceType)
	{
	case 0:
		prototype = rng.chance(prototypeChance[gameState->difficulty][1]);
		break;
	case 1:
		prototype = true;
		break;
	case 2:
		prototype = false;
		break;
	default:
		if (true)
		{
			logError("BS::selectRandomItem()","unrecognized prototypeChanceType: " + intToString(chanceType));
			prototype = false;
		}
	}
	int itemID;
	if (rating != 31)
	{
		ItemSet<int> &set = prototype ? itemSets[1] : itemSets[0];
		ItemSet<int> picker;
		for (unsigned int i = 0; i < set.items.size(); i++)
		{
			if (itemDefs[set.items[i]]->rating == rating)
				picker.add(set.items[i],set.weights[i]);
		}
		bool valid = picker.pick(itemID);
		if (!valid)
			return 0;
	}
	else if (category != 18)
	{
		ItemSet<int> &set = prototype ? itemSets[1] : itemSets[0];
		ItemSet<int> picker;
		for (unsigned int i = 0; i < set.items.size(); i++)
		{
			if (itemDefs[set.items[i]]->matchesCategory(category))
				picker.add(set.items[i],set.weights[i]);
		}
		bool valid = picker.pick(itemID);
		if (!valid)
			return 0;
	}
	else
	{
		bool valid = prototype ? itemSets[1].pick(itemID) : itemSets[0].pick(itemID);
		if (!valid)
			return 0;
	}
	itemUses[itemID]++;
	if (itemDefs[itemID]->maxCount != 0 && itemUses[itemID] >= itemDefs[itemID]->maxCount)
	{
		prototype ? itemSets[1].remove(itemID) : itemSets[0].remove(itemID);
	}
	return itemDefs[itemID];
}

ItemDef *BS::selectRandomItemOfRating(int level, int mode, int chanceType, int rating, int category, int unknown, int attempt)
{
	if (level >= 10)
		level = 9;
	int lvl = level;
	if (lvl > attempt)
		lvl -= attempt;
	bool prototype;
	switch (chanceType)
	{
	case 0:
		prototype = rng.chance(prototypeChance[gameState->difficulty][1]);
		break;
	case 1:
		prototype = true;
		break;
	case 2:
		prototype = false;
		break;
	default:
		if (true)
		{
			logError("BS::selectRandomItemOfRating()","unrecognized prototypeChanceType: " + intToString(chanceType));
			prototype = false;
		}
	}
	vector<int> candidates;	// NOTE: holds ItemDef pointers (the exe names its folded vector<int>::push_back)
	ItemSet<ItemDef *> weighted;
	for (unsigned int i = 1; i < itemDefs.size(); i++)
	{
		if (itemDefs[i]->tier == lvl
			&& ((prototype && itemDefs[i]->prototype == 1) || (!prototype && itemDefs[i]->prototype != 1))
			&& (rating == 31 || itemDefs[i]->rating == rating)
			&& (category == 18 || itemDefs[i]->matchesCategory(category))
			&& (itemDefs[i]->maxCount == 0 || itemUses[i] < itemDefs[i]->maxCount)
			&& (unknown == 42 ? unknown5714a0(itemDefs[i]->unknown54) : unknown571520(itemDefs[i]->unknown54,unknown)))
		{
			switch (mode)
			{
			case 1:
				candidates.push_back(reinterpret_cast<int &>(itemDefs[i]));
				break;
			case 0:
				weighted.add(itemDefs[i],rarityWeight[itemDefs[i]->rarity]);
				break;
			case 2:
				weighted.add(itemDefs[i],110 - rarityWeight[itemDefs[i]->rarity]);
				break;
			}
		}
	}
	ItemDef *item;
	if (mode == 1)
	{
		if (candidates.empty())
			return 0;
		item = (ItemDef *)randomElement(candidates);
	}
	else
	{
		if (weighted.size() == 0)
		{
			if (attempt < 2)
				return selectRandomItemOfRating(level,mode,chanceType,rating,category,unknown,attempt + 1);
			else
				return 0;
		}
		item = weighted.pickRandom();
	}
	itemUses[item->ID]++;
	return item;
}

HEntity BS::placeEntity(EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced)
{
	Point placedPos;
	bool canPlace;
	if (forced)
	{
		placedPos = position;
		canPlace = true;
		if (cells(placedPos)->getEntity().isValid())
			logFatal("BS::placeEntity()","found occupant in forced loc " + pointToString(placedPos) + ": " + cells(placedPos)->getEntity()->getLabel());
	}
	else
		canPlace = findPlacement(position,placedPos,record->size);
	if (!canPlace)
		return HEntity();
	HEntity entity = entityMgr->createEntity(record);
	if (groupIndex == 3 && factionAttitude[entity->getFaction()] < 2 && entity->getName() == "A-27 Freighter" && entity->getDisplayName() == "Sauler")
		groupIndex = 4;
	entity->changePos(placedPos,false);
	groups[groupIndex]->addMember(entity,unknown18);
	entity->setAI(new EntityAI(entity,aiMode1,aiMode2));
	eventQueue.add(new Event(1,new google::protobuf::internal::InternalMetadataWithArenaBase<google::protobuf::UnknownFieldSet,google::protobuf::internal::InternalMetadataWithArena>((google::protobuf::Arena *)entity.ID)),0);
	if (entity->getInventory())
	{
		if (entity->getInventory()->hasType(0x39))
		{
			ItemData *part = entity->getInventory()->findType(0x39);
			unknown465700(entity,unknown639350(part));
			vector<Cell *> *items = (vector<Cell *> *)((google::protobuf::internal::ExplicitlyConstructed<Protobuf::Stats> *)entity->getInventory())->get_mutable();
			for (unsigned int i = 0; i < items->size(); i++)
			{
				if (((ItemData *)(*items)[i]->getTerrain())->type == 0x39 && ((ItemData *)(*items)[i]->getTerrain())->unknown7c)
				{
					entity->setFlag(1);
					break;
				}
			}
		}
	}
	return entity;
}

void BS::displayHack(HEntity source, const Point &target, bool success)
{
	Point pos = source->unknown5c80f0(target);
	if (pos == target)
	{
		logError("BS::displayHack()","AI seems to be hacking itself...");
		return;
	}
	string name("Hack_Attack_");
	name += source->isHostileTo(player) ? "Enemy_" : "Ally_";
	name += success ? "Success" : "Fail";
	int effectType;
	lookupID(name,effectType);
	if (effectType != 0)
	{
		vector<Point> path;
		vector<int> dirs;	// NOTE: placeholder name
		vector<int> frames;	// NOTE: placeholder name
		Point end;
		getPath(source,target,path,dirs,frames,end,0,4,1,1);
		for (unsigned int i = 1; i < path.size() - 1; i++)
		{
			if (isVisible(path[i]))
				effectMgr->create()->init(effectMgr,effectType,path[i],effectOrigin,0,0,0,frames[i],0);
		}
	}
}

void BS::thrownItemArrived(HEntity thrower, HItem item, int mode, const Point &position, vector<TurnRecord *> *records)
{
	if (item.operator->() == NULL)
	{
		logError("BS::thrownItemArrived()","no item found to arrive at " + pointToString(position));
		return;
	}
	HEntity occupant = cells(position)->getEntity();
	if (records)
	{
		if (occupant.isValid())
			turnUpdate_51da30(records,0x14,occupant,HEntity(),HEntity(),0,0);
		if (thrower.isValid())
		{
			bool statue = (item->getName() == "Warlord Statue");
			turnUpdate_51da30(records,0x19,thrower,HEntity(),item,0,0);
			if (item.operator->() == NULL)
			{
				if (statue && isVisible(position))
					addMessage(0x320,HEntity(),string("Warlord Statue falls to pieces."),0);
				return;
			}
		}
	}
	switch (mode)
	{
	case 1:
		item->unknown57dbe0(true,false,true,true);
		break;
	case 2:
	case 3:
		if (occupant.isValid() && occupant->unknown45a810() >= item->unknown4578c0())
		{
			if (mode == 2 && item->unknown4578a0() < 5 && occupant->unknown5c92e0(item->unknown4578a0()) >= item->unknown4578c0())
				item->unknown57a190(occupant,item->unknown4578a0(),true,false);
			else
				item->unknown57a190(occupant,4,true,false);
			break;
		}
	case 4:
		{
			Point landing;
			if (!world->unknown71bc10(position,landing))
				item->unknown57dbe0(true,false,true,true);
			else
				item->unknown57a0f0(landing,true,true);
		}
		break;
	case 5:
		{
			Point p(position);
			if (cells(p)->getItem().isValid())
			{
				vector<Point> list(1,p);
				if (world->unknown71ec60(p,list))
				{
					item->unknown57a0f0(p,true,true);
					return;
				}
			}
			if (!cells(position)->unknown45d7b0() || world->unknown71bc10(position,p))
				item->unknown57a0f0(p,true,true);
			else
				item->unknown57dbe0(true,false,true,true);
		}
		break;
	}
}

void BS::spawnInfestiationFromTrap(unsigned int infestationIndex)
{
	if (infestationIndex >= infestationLocations.size())
	{
		logError("BS::spawnInfestiationFromTrap()","invalid infestationIndex: " + intToString(infestationIndex));
		return;
	}
	EntityRecord *record = unknown6c5600(3,0x3c,0,1);
	if (record == NULL)
	{
		logError("BS::spawnInfestiationFromTrap()","no Assembled data found");
		return;
	}
	int team = stringToInt(gameData.unknown46f6d0("usedCoreResetMatrix_g")) ? 2 : 5;
	for (int i = 0; i < 3; i++)
	{
		HEntity entity = placeEntity(record,infestationLocations[infestationIndex],team,false,0x22,0xe,false);
		if (entity.isValid())
		{
			do
			{
				if (unknown5111e0(0x21e,string("[name] emerges from a hatch in the floor."),0,0,entity,HEntity(),&infestationLocations[infestationIndex],0))
					consoleA->unknown8758d0(true);
				consoleB->unknown7b4f10();
			} while (false);
		}
	}
	unknown454260(&infestationLocations[infestationIndex],0x102);
	PROP_DATA(cells(infestationLocations[infestationIndex])->getProp().operator->())->uses--;
	PROP_DATA(cells(infestationLocations[infestationIndex])->getProp().operator->())->cooldownTurn = getTurn() + 10;
}
