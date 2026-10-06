// op_x1: player/game-data helpers and generation-checked entity handles.
// NOTE: partial layouts and unknown member names are placeholders.
// Recovered offsets: GameData currentNode +0x28, nodeHistory +0x2c,
//	lastDepth +0x5c, depthCounts +0x23c (0xd1ea9c), support +0x308,
//	support-state fields +0x310/+0x314. The node field called ID at +0x8
//	is used as a depth index: 11 - ID gives the map-depth accessor result.
// Player unlock vector/counter pairs: +0x26c/+0x27c, +0x2b0/+0x2c0,
//	+0x2f4/+0x304, +0x338/+0x348. The first three record ID/map/turn.
// Codegen: percent/cost local names recover the original stack slots;
//	the difficulty multiplier is a memory operand, not a literal 2.0f.
//	The depth-change helper needs a nonthrowing player-rating accessor.
//	Its integrated EH analysis also requires the real entity-handle lookup;
//	stubbing that lookup can make the rating accessor appear to throw.
// Semantics: getDepthChange optionally records the player's rating and
//	commits lastDepth; the weighted-count helpers cap 3 * recent + prior
//	at 15. Descriptive method names remain inferred placeholders.
// Entity handles: low 16 bits select the pool slot; high 16 bits carry its
//	generation. The pool has parallel entity/generation vectors at +0/+0x10.
//	Null, out-of-range, or stale-generation handles resolve to NULL.
// Companion state: PlayerData +0x4f0 points to type +0/item handle +4.
//	hasCompanion clears expired type-0 state but retains other types.
// Exit record: 0x60 bytes; position +0, node +8, active +0xc, revealed +0xd.
//	addExit registers the node/label/link/record, sets STAIRS_SHORTCUT,
//	reveals the cell, and relocates an item occupying the exit.
// Codegen: the const-reference cast materializes the original allocated-
//	pointer temporary; HProp/exit construction must remain nonthrowing.
#include <string>
#include <vector>
using namespace std;

struct OpC_Node;	// NOTE: placeholder name
class OpC_HNode	// NOTE: placeholder name
{
	int ID;
public:
	OpC_Node *operator->() const;
	bool isValid() const;
};
struct OpC_Node	// NOTE: placeholder name
{
	int pad0;
	int type;
	int ID;
	vector<OpC_HNode> links;
	char pad1c[0x25 - 0x1c];
	bool shortcutAppearance;	// NOTE: placeholder name
	bool flag26;
	bool flag27;
	bool isMainBranch();	// NOTE: placeholder name (0x46ecb0, type in [1,6])
};
void OpC_findNodes_470400(OpC_HNode node, vector<OpC_HNode> &matches, vector<OpC_HNode> &visited);	// NOTE: placeholder name
template <class T> bool OpC_inVector(vector<T> &v, T e);	// NOTE: placeholder name

extern vector<int> opX1_options;	// NOTE: placeholder name (0xcf4a04)
extern int opX1_costBonus[];	// NOTE: placeholder name (0xb988f0)
extern int opd_gameModeCf462c;	// NOTE: placeholder name (0xcf462c)
extern const float opX1_difficultyScale;	// NOTE: placeholder name (0xba7808, 2.0f)
extern int opX1_supportValues[];	// NOTE: placeholder name (0xb99b58)
extern int opX1_branchFlags[];	// NOTE: placeholder name (0xb90000)
int minInt(int a, int b);	// 0x9cdb30

class Push_46ed20	// NOTE: placeholder name
{
public:
	char unknown0[0x8];
	int field8;
	int operate();
};
int stringToInt(const string &s);

class Entity;
class Item;
class HEntity
{
	int ID;
public:
	Entity *operator->() const throw();	// 0x9b6570
	bool isNull() const;
	unsigned int getGeneration() const;	// NOTE: placeholder name (0x9e83a0)
	unsigned int getIndex() const;	// NOTE: placeholder name (0x9e83c0)
};

class OpX1_EntityPool	// NOTE: placeholder name
{
public:
	vector<Entity *> entities;
	vector<unsigned int> generations;
	Entity *get(HEntity entity);	// NOTE: placeholder name (0x9d3af0)
};
extern OpX1_EntityPool *opX1_entityPool;	// NOTE: placeholder name (0xd3c228)
OpX1_EntityPool *opX1_getEntityPool();	// NOTE: placeholder name (0x9bfe70)
class HItem
{
	int ID;
public:
	Item *operator->() const;	// 0x9b65b0
	bool isValid() const;
};
class HProp
{
	int ID;
public:
	HProp() throw();
};
class HItemList : public vector<HItem>	// NOTE: placeholder layout
{
};
namespace Protobuf
{
	class Stats_Actions
	{
	public:
		virtual int GetCachedSize() const;
	};
}
class Sweep_457820	// NOTE: placeholder name
{
public:
	int getNestedField();
};
class Item : public Protobuf::Stats_Actions
{
};
class Entity
{
public:
	HItemList *getInventoryList();
	int unknown45a880() throw();	// NOTE: placeholder name
	HItem unknown5d2380(int type);	// NOTE: placeholder name
	bool unknown5d4490(HEntity entity);	// NOTE: placeholder name
};

struct Point
{
	int x;
	int y;
	Point(const Point &p);
};
struct Pos;
class Particle
{
public:
	Pos *getPos();	// folded vector-address getter, 0x462e10
};
class Cell
{
public:
	void unknown66a050(int terrainID, int cause, int flag);	// NOTE: placeholder name
	HItem getItem();
};
template <class T> class Array2D	// NOTE: placeholder name
{
	int width;
	int height;
	T *data;
public:
	T &operator()(const Point &p);	// 0x9ced70
};
extern Array2D<Cell *> cells;	// 0xcfd44c
class Push_66b640	// NOTE: placeholder name
{
public:
	char unknown0[4];
	int field4;
	int field8;
	void operate();
};
struct OpX1_ExitRecord	// NOTE: placeholder name
{
	Point position;
	OpC_HNode node;
	bool active;
	bool revealed;
	char paddingE[0x60 - 0xe];
	OpX1_ExitRecord(const Point &p, OpC_HNode node_, bool active_, HProp source, HProp other) throw();	// 0x6c13a0
};
struct OpX1_Terrain;	// NOTE: placeholder name
extern vector<OpX1_Terrain *> opX1_terrainDefinitions;	// NOTE: placeholder name (0xcfb844)
int opX1_findTerrain(vector<OpX1_Terrain *> &list, const string &name);	// NOTE: placeholder name (0x9d7b80)
extern vector<OpC_HNode> opX1_exitNodes;	// NOTE: placeholder name (0xd1ea7c)
extern vector<string> opX1_exitLabels;	// NOTE: placeholder name (0xd1ea8c)
extern OpC_HNode opX1_rootNode;	// NOTE: placeholder name (0xd1e888)
class Map
{
public:
	HEntity getPlayer() throw();
	void unknown4647a0(const Point &p, bool flag);	// NOTE: placeholder name
};
class BS : public Map
{
public:
	int unknown71abf0(bool flag);	// NOTE: placeholder name
	bool unknown71ec60(const Point &p, vector<Point> visited);	// NOTE: placeholder name
};
extern BS *world;	// 0xcefc4c
extern Map *opX1_map;	// NOTE: placeholder name (0xcefc4c)

class GameData	// NOTE: placeholder name
{
public:
	char padding0[0x28];
	OpC_HNode currentNode;
	vector<OpC_HNode> nodeHistory;
	char padding3c[0x5c - 0x3c];
	int lastDepth;	// NOTE: placeholder name
	char padding60[0x23c - 0x60];
	vector<int> depthCounts;	// NOTE: placeholder name
	char padding24c[0x308 - 0x24c];
	int support;
	int unknown30c;
	int unknown310;
	int unknown314;
	int unknown46f4e0();	// NOTE: placeholder name
	int unknown46f530();	// NOTE: placeholder name
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
	void unknown46f700(const string &key, const string &value);	// NOTE: placeholder name
	int unknown789090();	// NOTE: placeholder name
	int getDepthChange(OpC_HNode node, bool update);	// NOTE: placeholder name
	int unknown789250(int value);	// NOTE: placeholder name
	bool unknown7894d0(OpC_HNode node);	// NOTE: placeholder name
	bool unknown789580(HEntity entity);	// NOTE: placeholder name
	bool unknown789620();	// NOTE: placeholder name
	int getWeightedDepthCount();	// NOTE: placeholder name
	int getNextWeightedDepthCount();	// NOTE: placeholder name
	void unknown7897a0(int type);	// NOTE: placeholder name
	void addExit(OpC_HNode node, const Point &p, const string &label);	// NOTE: placeholder name (0x7892d0)
};
extern GameData gameData;	// 0xd1e860

class StatTracker	// NOTE: placeholder name
{
public:
	void unknown4729d0(int id, int value, string text, int flag);	// NOTE: placeholder name
};
extern StatTracker statTracker;	// 0xd2c658

class CInventory
{
public:
	void unknown8a56d0(int id);	// NOTE: placeholder name
	void reopen(int mode, HProp prop);
};
extern CInventory *cinventory;	// 0xcec08c

class OpX1_ItemDisplay	// NOTE: placeholder name
{
public:
	void unknown896c20(int id);	// NOTE: placeholder name
	void unknown896ab0(int id);	// NOTE: placeholder name
};
extern OpX1_ItemDisplay *opX1_itemDisplay;	// NOTE: placeholder name (0xcec088)
extern int opX1_gameState;	// NOTE: placeholder name (0xd28d68)

class OpX1_CompanionState	// NOTE: placeholder name
{
public:
	int type;
	HItem item;
	~OpX1_CompanionState();	// 0x48b840
};

class OpX1_PlayerData	// NOTE: placeholder name
{
public:
	char padding0[0x26c];
	vector<int> unlockedA;
	int countA;
	vector<int> IDsA;
	vector<int> mapsA;
	vector<int> turnsA;
	vector<int> unlockedB;
	int countB;
	vector<int> IDsB;
	vector<int> mapsB;
	vector<int> turnsB;
	vector<int> unlockedC;
	int countC;
	vector<int> IDsC;
	vector<int> mapsC;
	vector<int> turnsC;
	vector<int> unlockedD;
	int countD;
	char padding34c[0x4f0 - 0x34c];
	OpX1_CompanionState *companion;

	bool unknown77ffb0(int id, int flag);	// NOTE: placeholder name
	bool unknown780380(int id, int turn);	// NOTE: placeholder name
	bool unknown780480(int id, int turn);	// NOTE: placeholder name
	bool unknown780550(int id, int turn);	// NOTE: placeholder name
	bool unknown780700(int id, bool record);	// NOTE: placeholder name
	bool hasCompanion();	// NOTE: placeholder name (0x780790)
};

bool OpX1_PlayerData::unknown780380(int id, int turn)
{
	if (unlockedA[id])
		return false;
	unlockedA[id] = 1;
	countA++;
	IDsA.push_back(id);
	mapsA.push_back(gameData.unknown46f530());
	turnsA.push_back(turn);
	statTracker.unknown4729d0(0x301,1,"",-1);
	bool result = unknown77ffb0(id,0);
	if (opX1_gameState == 3)
	{
		opX1_itemDisplay->unknown896c20(id);
		cinventory->unknown8a56d0(id);
	}
	return result;
}

bool OpX1_PlayerData::unknown780480(int id, int turn)
{
	if (unlockedB[id])
		return false;
	unlockedB[id] = 1;
	countB++;
	IDsB.push_back(id);
	mapsB.push_back(gameData.unknown46f530());
	turnsB.push_back(turn);
	statTracker.unknown4729d0(0x2fc,1,"",-1);
	return true;
}

bool OpX1_PlayerData::unknown780700(int id, bool record)
{
	if (unlockedD[id])
		return false;
	unlockedD[id] = 1;
	countD++;
	if (record)
		statTracker.unknown4729d0(0x3cf,1,"",-1);
	return true;
}

int GameData::unknown789090()
{
	int count = 1;
	if (nodeHistory.size() >= 2)
	{
		for (int i = nodeHistory.size() - 2; i >= 0; i--)
		{
			if (nodeHistory[i]->ID != currentNode->ID)
				break;
			if (nodeHistory[i]->type == currentNode->type)
				count++;
		}
	}
	return count;
}

int GameData::unknown789250(int value)
{
	int percent = unknown46f4e0() / 2 * 7;
	int cost = value + value * percent / 100;
	if (opX1_options[3])
		cost += opX1_costBonus[opX1_options[3]];
	if (opd_gameModeCf462c == 5)
		cost = (int)(cost * opX1_difficultyScale);
	return cost;
}

bool GameData::unknown7894d0(OpC_HNode node)
{
	vector<OpC_HNode> matches;
	vector<OpC_HNode> visited;
	OpC_findNodes_470400(currentNode,matches,visited);
	return !OpC_inVector(matches,node);
}

void GameData::unknown7897a0(int type)
{
	support += opX1_supportValues[type];
	if (!stringToInt(unknown46f6d0("installedRif_g")) &&
		!stringToInt(unknown46f6d0("zioWasImprinted_g")) &&
		!stringToInt(unknown46f6d0("scrUfdRegistered_g")) &&
		!stringToInt(unknown46f6d0("warAttackedLocals_g")))
	{
		unknown46f700("garCommArraySupport_g","1");
		if (unknown310 == 1 && unknown314 == 0)
			unknown314 = 1;
	}
}

bool OpX1_PlayerData::unknown780550(int id, int turn)
{
	if (unlockedC[id])
		return false;
	unlockedC[id] = 1;
	countC++;
	IDsC.push_back(id);
	mapsC.push_back(gameData.unknown46f530());
	turnsC.push_back(turn);
	statTracker.unknown4729d0(0x306,1,"",-1);
	bool result = unknown77ffb0(id,0);
	if (opX1_gameState == 3)
	{
		opX1_itemDisplay->unknown896c20(id);
		cinventory->unknown8a56d0(id);
	}
	opX1_itemDisplay->unknown896ab0(id);
	HItemList *inventory = opX1_map->getPlayer()->getInventoryList();
	for (unsigned int i = 0; i < inventory->size(); i++)
	{
		if (reinterpret_cast<Sweep_457820 *>((*inventory)[i].operator->())->getNestedField() == id &&
			(*inventory)[i]->Protobuf::Stats_Actions::GetCachedSize() == 4)
		{
			cinventory->reopen(4,HProp());
			break;
		}
	}
	return result;
}

int GameData::getDepthChange(OpC_HNode node, bool update)
{
	int change = 0;
	if (node->isMainBranch() && currentNode->type != 12 &&
		(currentNode->type != 13 || lastDepth != node->ID))
	{
		if (update)
			statTracker.unknown4729d0(0x179,opX1_map->getPlayer()->unknown45a880(),"",-1);
		if (lastDepth != node->ID)
		{
			change = lastDepth - node->ID;
			if (update)
				lastDepth = node->ID;
		}
	}
	return change;
}

bool GameData::unknown789580(HEntity entity)
{
	return opX1_options[10] && opX1_branchFlags[currentNode->type] == 1 &&
		currentNode->type != 35 && (entity.isNull() || opX1_map->getPlayer()->unknown5d4490(entity));
}

bool GameData::unknown789620()
{
	return opX1_branchFlags[currentNode->type] == 1 && currentNode->type != 35 &&
		opX1_map->getPlayer()->unknown5d2380(15).isValid();
}

int GameData::getWeightedDepthCount()
{
	int count = 0;
	int depth = reinterpret_cast<Push_46ed20 *>(currentNode.operator->())->operate();
	if (depth >= 3)
	{
		count += depthCounts[depth - 1] * 3;
		count += depthCounts[depth - 2];
	}
	return minInt(count,15);
}

int GameData::getNextWeightedDepthCount()
{
	int count = 0;
	int depth = reinterpret_cast<Push_46ed20 *>(currentNode.operator->())->operate() + 1;
	if (depth >= 3)
	{
		count += world->unknown71abf0(true) * 3;
		count += depthCounts[depth - 2];
	}
	return minInt(count,15);
}

unsigned int HEntity::getGeneration() const
{
	return ((unsigned int)ID >> 16) & 0xffff;
}

unsigned int HEntity::getIndex() const
{
	return ID & 0xffff;
}

OpX1_EntityPool *opX1_getEntityPool()
{
	return opX1_entityPool;
}

Entity *OpX1_EntityPool::get(HEntity entity)
{
	if (entity.isNull())
		return NULL;
	unsigned int index = entity.getIndex();
	if (index >= entities.size() || generations[index] != entity.getGeneration())
		return NULL;
	return entities[index];
}

Entity *HEntity::operator->() const throw()
{
	return opX1_getEntityPool()->get(*this);
}

bool OpX1_PlayerData::hasCompanion()
{
	if (companion)
	{
		if (companion->item.operator->())
		{
			return true;
		}
		else
		{
			if (companion->type == 0)
			{
				delete companion;		companion = NULL;
			}
		}
	}
	return false;
}

void GameData::addExit(OpC_HNode node, const Point &p, const string &label)
{
	opX1_exitNodes.push_back(node);
	opX1_exitLabels.push_back(label);
	opX1_rootNode->links.push_back(node);
	Point *position = reinterpret_cast<Point *>(static_cast<OpX1_ExitRecord *const &>(new OpX1_ExitRecord(p,node,true,HProp(),HProp())));
	vector<Point *> *exits = reinterpret_cast<vector<Point *> *>(reinterpret_cast<Particle *>(world)->getPos());
	exits->push_back(position);
	int terrainID = opX1_findTerrain(opX1_terrainDefinitions,"STAIRS_SHORTCUT");
	cells(*position)->unknown66a050(terrainID,2,0);
	if (!node->isMainBranch() && node->shortcutAppearance)
		reinterpret_cast<Push_66b640 *>(cells(*position))->operate();
	opX1_map->unknown4647a0(*position,true);
	reinterpret_cast<OpX1_ExitRecord *>(position)->revealed = true;
	if (cells(*position)->getItem().isValid())
	{
		vector<Point> visited(1,*position);
		world->unknown71ec60(*position,visited);
	}
}
