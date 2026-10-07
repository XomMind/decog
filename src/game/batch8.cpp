// Batch 8: EntityAI / Trap / Prop / Item methods matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; all type/member names are placeholders.
#include <string>
#include <vector>
using namespace std;

void logError(string location, string message);	// NOTE: placeholder name (0x404f10)

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;
	Point();	// 0x453b40
	Point &operator=(const Point &p);	// 0x46ca50
	void setOffset(const Point &base, int dx, int dy);	// NOTE: placeholder name (0x40a060)
	int distance(const Point &p) const;	// NOTE: placeholder name (0x409fb0)
};
bool unknown4373c0(const Point &a, const Point &b);	// NOTE: placeholder name
string pointToString(const Point &p);	// NOTE: placeholder name (0x40a4a0)

class Entity;
class Item;
class HEntity	// NOTE: placeholder layout
{
	int ID;
public:
	bool isValid() const;
	bool operator==(HEntity other) const;
	void clear();	// NOTE: placeholder name (0x9b7270)
	Entity *operator->() const;	// 0x9b6570
};

class HItem	// NOTE: placeholder layout
{
	int ID;
public:
	bool isValid() const;
	Item *operator->() const;	// 0x9b65b0
};

class Group	// NOTE: placeholder name
{
public:
	int getFaction();	// NOTE: placeholder name (0x9b4350: [this+8]); the exe prints it as "faction" (Entity::changeFaction diagnostic), BS::initilize's group ctor 0x670ff0 stores the group index in +4 and +8
};

class HGroup	// NOTE: placeholder name
{
	int ID;
public:
	HGroup();
	Group *operator->() const;	// 0x9b7250
};

struct ItemType;
struct ItemTrait	// NOTE: placeholder name
{
	int unknown00;
	int state;	// NOTE: placeholder name
};

class Item
{
public:
	int getCategory();	// NOTE: placeholder name (0x44aec0: [this+0xc]); op_u2.cpp uses the same getter as `getCategory() <= 3`
	void setActive(bool active);
	void setBroken(int turn, bool flag);	// NOTE: placeholder argument names
	void unknown57c160(const Point &p);	// NOTE: placeholder name
	void unknown57a0f0(const Point &p, int a, bool b);	// NOTE: placeholder name
	ItemTrait *unknown457b70(int id);	// NOTE: placeholder name
	void unknown4585c0(int id);	// NOTE: placeholder name
	void unknown458630(ItemTrait *trait);	// NOTE: placeholder name
	void unknown458460();	// NOTE: placeholder name
	int unknown4580c0();	// NOTE: placeholder name

	int pad00;
	int ID;
	ItemType *type;
	int pad0c;
	HEntity carrier;	// NOTE: placeholder name
	char pad14[0x28 - 0x14];
	int activeTurn;	// NOTE: placeholder name
	int activateOkayTurn;	// NOTE: placeholder name
	char pad30[0x40 - 0x30];
	bool unknown40;	// NOTE: placeholder name
	char pad41[3];
	int unknown44;	// NOTE: placeholder name
};

class EntityAI;

struct EntityRecord	// NOTE: placeholder
{
	int unknown00;
	string name;
	char pad[0x28 - 4 - sizeof(string)];
	int index;
};

class Entity
{
public:
	char pad00[8];
	EntityRecord *record;
	HGroup getGroup();	// 0x45a3f0
	const Point &getPosition();	// 0x45a4a0
	const string &getName();	// NOTE: placeholder name (0x45a280)
	int getFaction();	// 0x45a2c0
	int getSize();	// NOTE: placeholder name (0x45a360)
	HItem unknown5d2380(int type);	// NOTE: placeholder name
	int unknown5d1ee0();	// NOTE: placeholder name
	int unknown5c8cb0();	// NOTE: placeholder name
	int unknown5d1390();	// NOTE: placeholder name
	bool isDead();	// NOTE: placeholder name (0x5c7600)
	int unknown5cb220();	// NOTE: placeholder name
	int unknown5cad50();	// NOTE: placeholder name
	bool unknown5c84f0(const Point &p);	// NOTE: placeholder name
	bool unknown5c87f0(const Point &p);	// NOTE: placeholder name
	EntityAI *getAI();	// NOTE: placeholder name (0x45b590)
};

struct MachineInfo	// NOTE: placeholder name
{
	char pad00[0x28];
	int unknown28;
	char pad2c[0x40 - 0x2c];
	vector<int> zones;	// NOTE: placeholder name
};

struct PropData	// NOTE: placeholder name
{
	int unknown00;
	string name;
	char pad[0xf4 - 4 - sizeof(string)];
	int interactType;
	int machineType;	// NOTE: placeholder name
};

struct XColor	// NOTE: placeholder layout
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	void getHSV(float *h, float *s, float *v);
	void setHSV(float h, float s, float v);
};

class Trap;
class Prop
{
public:
	MachineInfo *getMachine();	// NOTE: placeholder name (0x45cb30: [this+0x44])
	int getState();	// NOTE: placeholder name (0x457b10: [this+0x3c])
	Trap *getTrap();	// NOTE: placeholder name (0x44b020: [this+0x4c]; NULL for non-trap props, see Trap::escapeStasis's "non-Trap prop" diagnostic)
	void disableMachine();
	const Point &getPosition();	// NOTE: placeholder name (0x4184d0)

	bool isPassableFor(HEntity e);	// NOTE: placeholder name (0x65e1d0)
	const string &getName();	// NOTE: placeholder name (0x45c5b0)
	void unknown65f170();	// NOTE: placeholder name
	void unknown45ccf0(bool flag);	// NOTE: placeholder name

	int ID;
	PropData *data;	// NOTE: placeholder name
	Point position;	// NOTE: placeholder name
	char pad10[8];
	XColor color1;	// NOTE: placeholder name
	XColor color2;	// NOTE: placeholder name
	char pad1e[0x34 - 0x1e];
	int machineIndex;	// NOTE: placeholder name
	int pad38;
	int state;	// NOTE: placeholder name
	char pad40;
	bool soundOrigin;	// NOTE: placeholder name
	char pad42[2];
	MachineInfo *machine;	// NOTE: placeholder name
};

class HProp
{
	int ID;
public:
	HProp();
	bool isValid() const;
	bool isNull() const;
	Prop *operator->() const;	// 0x9b64f0
};

class Cell
{
public:
	HProp getProp();	// 0x45d550
	bool unknown66b1c0(int a, bool b);	// NOTE: placeholder name
	bool isOpen();	// NOTE: placeholder name (0x4550b0)
	void unknown66c100(int a, int b);	// NOTE: placeholder name
	void unknown45daf0(bool flag);	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
};
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

class BS	// NOTE: placeholder name (the object behind the global at 0xcefc4c)
{
public:
	bool unknown71bc10(const Point &from, Point *out);	// NOTE: placeholder name
	bool unknown7168e0(const Point &a, const Point &b, Entity *e, vector<Point> *out);	// NOTE: placeholder name
	HEntity getPlayer();	// NOTE: placeholder name (0x4630f0)
	vector<vector<HProp> > &unknown463be0();	// NOTE: placeholder name
	void removeMachine(int machineType, const Point &position);	// 0x71fbd0
	bool isVisible(const Point &p);	// NOTE: placeholder name (0x4631c0)
	int getTurn();	// NOTE: placeholder name (0x464270)
	void unknown464c70(int itemID);	// NOTE: placeholder name
};
extern BS *world;	// NOTE: placeholder name (0xcefc4c)

struct ItemType	// NOTE: placeholder name
{
	int pad;
	int pad4;
	string name;
	char pad24[0x90 - 0x24];
	bool autoActivate;	// NOTE: placeholder name
	char pad91[0xec - 0x91];
	int unknownEC;	// NOTE: placeholder name
	int ID;	// NOTE: placeholder name
};

class ItemMgr	// NOTE: placeholder name
{
public:
	HItem create(ItemType *type);	// NOTE: placeholder name (0x7932b0)
};
extern ItemMgr *itemMgr;	// NOTE: placeholder name (0xcefaa8)
extern vector<ItemType *> itemTypes;	// NOTE: placeholder name (0xd2d1c4)
bool findItemType(vector<ItemType *> &v, const string &name, ItemType **out);	// NOTE: placeholder name (0x9d7a40)

extern vector<HEntity> aiEntities;	// NOTE: placeholder name (0xcf25b8)
extern vector<HEntity> aiEntitiesB;	// NOTE: placeholder name (0xd37984)
int findEntityIndex(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d3110)
void eraseEntityAt(vector<HEntity> &v, int index);	// NOTE: placeholder name (0x9da940)
bool isBetween(int low, int value, int high);	// NOTE: placeholder name (0x9daf80)
void erasePointAt(vector<Point> &v, int index);	// NOTE: placeholder name (0x9d5190)
void erasePointAndRewind(vector<Point> &v, unsigned int &index);	// NOTE: placeholder name (0x9d7300)

struct AIOrder	// NOTE: placeholder name
{
	int unknown00;
	int type;
};

class EntityAI
{
public:
	void willDie(bool flag);
	bool findPathToGoal();
	void setFollowEntity(HEntity followEntity_, int followParam_);
	bool unknown458a90();	// NOTE: placeholder name
	HEntity getFollowEntity();	// NOTE: placeholder name (0x458ed0)

	HEntity entity;
	int pad04;
	int state;
	int pad0c;
	Point goal;
	char pad18[0x24 - 0x18];
	vector<Point> route;	// NOTE: placeholder name
	char pad34[0x58 - 0x34];
	HEntity followEntity;	// NOTE: placeholder name
	bool followFlag;	// NOTE: placeholder name
	int followParam;	// NOTE: placeholder name
	int followCounter;	// NOTE: placeholder name
	char pad68[4];
	vector<Point> path;
	char pad7c[0xb4 - 0x7c];
	HEntity target;	// NOTE: placeholder name
	char padb8[0xf0 - 0xb8];
	vector<int> unknownF0;	// NOTE: placeholder name
	char pad100[0x114 - 0x100];
	AIOrder *order;
};

void EntityAI::willDie(bool flag)
{
	if (!entity.operator->())
	{
		bool problem = true;	// NOTE: placeholder name
		logError("EntityAI::willDie()","me already gone, hm");
		return;
	}
	int index = findEntityIndex(aiEntities,entity);
	if (index != -1)
	{
		eraseEntityAt(aiEntities,index);
		eraseEntityAt(aiEntitiesB,index);
	}
	if (unknown458a90() && target.operator->() && target->getAI()->unknownF0.empty())
		target->getAI()->goal = entity->getPosition();
	switch (entity->getFaction())
	{
	case 1:
		if (target.isValid() && target.operator->() && target->getAI())
			target->getAI()->target.clear();
		break;
	case 8:
		if (target.isValid())
		{
			int i = findEntityIndex(aiEntitiesB,entity);
			if (i != -1)
				aiEntitiesB[i].clear();
		}
		break;
	case 9:
		if (!flag && !path.empty() && isBetween(3,entity->getGroup()->getFaction(),4) &&
			cells(path.front())->unknown66b1c0(0,false) &&
			cells(path.front())->getProp()->getMachine()->unknown28 >= 0 &&
			cells(path.front())->getProp()->getState() == 0)
		{
			Point p;
			if (world->unknown71bc10(entity->getPosition(),&p))
			{
				ItemType *type;
				findItemType(itemTypes,"Data Core",&type);
				HItem dc = itemMgr->create(type);
				dc->unknown57c160(path.front());
				dc->unknown57a0f0(p,0,false);
			}
		}
		break;
	}
}

void EntityAI::setFollowEntity(HEntity followEntity_, int followParam_)
{
	if (followEntity_ == entity)
	{
		logError("EntityAI::setFollowEntity()",entity->record->name + " attempting to follow self at " + pointToString(entity->getPosition()) + ", cancelling");
		return;
	}
	if (followEntity_.operator->() && followEntity_->getAI() && followEntity_->getAI()->getFollowEntity() == entity)
	{
		logError("EntityAI::setFollowEntity()",entity->record->name + " at " + pointToString(entity->getPosition()) + " attempting to follow an Ent (" + followEntity_->getName() + ") at " + pointToString(followEntity_->getPosition()) + " already following self, cancelling");
		return;
	}
	followEntity = followEntity_;
	followFlag = false;
	followParam = followParam_;
	followCounter = 0;
}

bool EntityAI::findPathToGoal()
{
	do { } while (0);
	if (!cells.contains(goal))
	{
		logError("EntityAI::findPathToGoal()","goal outside bMap!");
		return false;
	}
	if (entity->getSize() > 1 && !entity->unknown5c84f0(goal))
		return false;
	route.clear();
	vector<Point> openCells;	// NOTE: placeholder name
	vector<Point> propCells;	// NOTE: placeholder name
	if (!unknown4373c0(entity->getPosition(),goal))
	{
		Point p;
		int x;
		for (x = 0; x < entity->getSize(); x++)
		{
			int y;
			for (y = 0; y < entity->getSize(); y++)
			{
				p.setOffset(goal,x,y);
				if (!cells(p)->isOpen())
				{
					cells(p)->unknown45daf0(true);
					openCells.push_back(p);
				}
				if (cells(p)->getProp().isValid() && !cells(p)->getProp()->isPassableFor(entity))
				{
					cells(p)->getProp()->unknown45ccf0(true);
					propCells.push_back(p);
				}
			}
		}
		if (entity->getSize() > 1)
		{
			unsigned int i;
			for (i = 0; i < openCells.size(); i++)
			{
				if (entity->unknown5c87f0(openCells[i]))
				{
					cells(openCells[i])->unknown45daf0(false);
					erasePointAndRewind(openCells,i);
				}
			}
		}
	}
	bool found = world->unknown7168e0(entity->getPosition(),goal,entity.operator->(),&route);
	if (!openCells.empty())
	{
		unsigned int i;
		for (i = 0; i < openCells.size(); i++)
			cells(openCells[i])->unknown45daf0(false);
	}
	if (!propCells.empty())
	{
		unsigned int i;
		for (i = 0; i < propCells.size(); i++)
			cells(propCells[i])->getProp()->unknown45ccf0(false);
	}
	if (found)
	{
		erasePointAt(route,0);
		if (followEntity == world->getPlayer() || (order && order->type == 2))
		{
			if (route.size() > entity->getPosition().distance(goal) * 3 && entity->record->index != 10)
			{
				route.clear();
				found = false;
			}
		}
	}
	return found;
}

class Effect;	// NOTE: placeholder name

class EffectPool	// NOTE: placeholder name
{
public:
	Effect *unknown508610();	// NOTE: placeholder name
};
extern EffectPool *effectPool;	// NOTE: placeholder name (0xcefc50)

class Effect	// NOTE: placeholder name
{
public:
	void unknown503b20(EffectPool *pool, int id, const Point &pos, const Point &offset, int a, int b, int c, int d, int e);	// NOTE: placeholder name
};
extern Point effectOffset;	// NOTE: placeholder name (0xd2e20c)

class UIControl	// NOTE: placeholder name (global at 0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern UIControl *uiControl;	// NOTE: placeholder name (0xcec058)

class LogControl	// NOTE: placeholder name (global at 0xcec0b4)
{
public:
	void unknown7b4f10();	// NOTE: placeholder name
};
extern LogControl *logControl;	// NOTE: placeholder name (0xcec0b4)

bool findEffectID(const string &name, int *id);	// NOTE: placeholder name (0x9d7980)
string intToString(int value);	// NOTE: placeholder name
bool unknown5111e0(int id, const string &text, int a, int b, HEntity e, HProp p, const Point &pos, int c);	// NOTE: placeholder name
bool unknown5111e0(int id, int text, int a, int b, HProp e, HProp p, const Point &pos, int c);	// NOTE: placeholder name (same function, 0x5111e0)
void raiseToMin(int &value, int minValue);	// NOTE: placeholder name (0x9cf5c0)
extern int stasisResistance[];	// NOTE: placeholder name (0xb96048)

class Trap
{
public:
	bool escapeStasis(const Point &pos, HEntity entity);

	char pad00[0x14];
	int stasis;	// NOTE: placeholder name
};

bool Trap::escapeStasis(const Point &pos, HEntity entity)
{
	HProp prop = cells(pos)->getProp();
	if (prop.isNull())
	{
		logError("Trap::escapeStasis()","Passed a non-Prop pos: " + pointToString(pos));
		return false;
	}
	if (prop->getTrap() == 0)
	{
		logError("Trap::escapeStasis()","Passed a non-Trap prop: " + prop->getName() + " at " + pointToString(pos));
		return true;
	}
	if (world->isVisible(pos))
		prop->unknown65f170();
	if (entity->unknown5d2380(0x74).isValid())
		stasis = 0;
	else
	{
		int strength = entity->unknown5d1ee0() - entity->unknown5c8cb0();
		raiseToMin(strength,stasisResistance[entity->unknown5d1390()]);
		stasis -= strength;
	}
	if (stasis > 0)
	{
		do
		{
			if (unknown5111e0(0x223,intToString(stasis),0,0,entity,HProp(),pos,0))
				uiControl->unknown8758d0(true);
			logControl->unknown7b4f10();
		} while (0);
		if (world->isVisible(pos))
		{
			int glowID;
			findEffectID("T_Glow_Stasis",&glowID);
			if (glowID != 0)
				effectPool->unknown508610()->unknown503b20(effectPool,glowID,pos,effectOffset,0,0,0,9,0);
		}
		return false;
	}
	else
	{
		do
		{
			if (unknown5111e0(0x224,0,0,0,HProp(),HProp(),pos,0))
				uiControl->unknown8758d0(true);
			logControl->unknown7b4f10();
		} while (0);
		cells(pos)->unknown66c100(0,3);
		return true;
	}
}

class SoundMgr	// NOTE: placeholder name
{
public:
	void updatePropMute(HProp prop);	// 0x454520
};
extern SoundMgr soundMgr;	// NOTE: placeholder name (0xd2d2a0)

class PropListener	// NOTE: placeholder name (global at 0xcec054)
{
public:
	void unknown807100(const Point &position);	// NOTE: placeholder name
	void unknown81a090(int itemID);	// NOTE: placeholder name
};
extern PropListener *propListener;	// NOTE: placeholder name (0xcec054)

extern vector<vector<HProp> > machines;	// NOTE: placeholder name (0xd31640)
extern const float machineValueFactor;	// NOTE: placeholder name (0xb9e650)
extern float machineValueScale[][3];	// NOTE: placeholder name (0xb9e680)
bool eraseProp(vector<HProp> &v, HProp prop);	// NOTE: placeholder name (0x9d2f00)

void Prop::disableMachine()
{
	if (state == 1)
	{
		logError("Prop::disableMachine()","Attempting to disable already-disabled " + data->name + " at " + pointToString(position));
		return;
	}
	state = 1;
	vector<HProp> &parts = machines[machineIndex];
	unsigned int i;
	for (i = 0; i < parts.size(); i++)
	{
		parts[i]->state = 1;
		propListener->unknown807100(parts[i]->getPosition());
		if (parts[i]->machine)
		{
			unsigned int j;
			for (j = 0; j < parts[i]->machine->zones.size(); j++)
				eraseProp(world->unknown463be0()[parts[i]->machine->zones[j]],parts[i]);
			parts[i]->machine->zones.clear();
			world->removeMachine(data->machineType,parts[i]->position);
		}
		if (parts[i]->soundOrigin)
			soundMgr.updatePropMute(parts[i]);
	}
	if (data->interactType == 1)
	{
		float h, s, v;
		unsigned int k;
		for (k = 0; k < parts.size(); k++)
		{
			parts[k]->color1.getHSV(&h,&s,&v);
			v = v / machineValueScale[data->machineType][0] * machineValueFactor;
			parts[k]->color1.setHSV(0.0f,0.0f,v);
			parts[k]->color2.getHSV(&h,&s,&v);
			v = v / machineValueScale[data->machineType][0] * machineValueFactor;
			parts[k]->color2.setHSV(0.0f,0.0f,v);
		}
	}
}

class ItemUI	// NOTE: placeholder name (global at 0xcec11c)
{
public:
	void unknown4aee10(int itemID);	// NOTE: placeholder name
};
extern ItemUI *itemUI;	// NOTE: placeholder name (0xcec11c)

class InventoryPart	// NOTE: placeholder name
{
public:
	void unknown890710(int a);	// NOTE: placeholder name
};

class CInventory
{
public:
	void reopen(int mode, int itemID);	// NOTE: placeholder argument names
};
extern CInventory *inventory;	// NOTE: placeholder name (0xcec08c)

class InventoryMgr	// NOTE: placeholder name (global at 0xcec088)
{
public:
	void unknown896a80(int itemID);	// NOTE: placeholder name
	InventoryPart *unknown894e70(int itemID);	// NOTE: placeholder name
};
extern InventoryMgr *inventoryMgr;	// NOTE: placeholder name (0xcec088)

extern bool propulsionExitFlag[];	// NOTE: placeholder name (0xba0968)
extern int propulsionExitCount[];	// NOTE: placeholder name (0xba0970)
extern int lastItemID;	// NOTE: placeholder name (0xd1d9c8)

void Item::setActive(bool active)
{
	if (!active && activeTurn == -1)
		return;
	if (active)
	{
		activeTurn = world->getTurn();
		switch (type->ID)
		{
		case 0xa8:
		case 0xa9:
		case 0xaa:
		case 0xab:
		case 0xac:
		case 0xad:
			if (unknown44 > 0)
			{
				activeTurn = activeTurn - unknown44;
				unknown44 = 0;
			}
			break;
		}
	}
	else if (unknown40 && type->unknownEC)
	{
		unknown40 = false;
		ItemTrait *trait = unknown457b70(0x6b);
		int state = trait ? trait->state : 0;
		switch (state)
		{
		case 0:
			logError("Item::setActive()","encountered overload propulsionMode without trait");
			break;
		case 1:
			if (unknown44 == 1)
			{
				unknown458630(trait);
				unknown44 = 0;
				activeTurn = -1;
			}
			else
				trait->state = 3;
			break;
		case 2:
			if (unknown44 != 0)
				logError("Item::setActive()",type->name + " already has a count value before even starting to exit");
			trait->state = 3;
			if (propulsionExitFlag[type->unknownEC])
				unknown44 = (carrier.isValid() ? carrier->unknown5cb220() : propulsionExitCount[type->unknownEC]) + 1;
			else
				unknown44 = propulsionExitCount[type->unknownEC] + 1;
			break;
		case 3:
			logError("Item::setActive()","unexpected propulsionModeStateType: " + intToString(state));
			break;
		}
		itemUI->unknown4aee10(ID);
	}
	else
	{
		switch (type->ID)
		{
		case 0xa8:
		case 0xa9:
		case 0xaa:
		case 0xab:
		case 0xac:
		case 0xad:
			unknown44 = world->getTurn() - activeTurn;
			break;
		case 0xcf:
			unknown4585c0(0x61);
			break;
		}
		activeTurn = -1;
		unknown40 = false;
		if (carrier.isValid() && carrier->isDead())
		{
			if (unknown4580c0())
				propListener->unknown81a090(ID);
			lastItemID = ID;
		}
	}
}

void Item::setBroken(int turn, bool flag)
{
	if (type->autoActivate)
	{
		logError("Item::setBroken()","cannot break an auto-activate item");
		return;
	}
	if (unknown40 && carrier.isValid() && carrier->unknown5cad50())
	{
		logError("Item::setBroken()","cannot break an overloaded part currently in special mode");
		return;
	}
	if (turn == -1 && activateOkayTurn == -2)
		return;
	setActive(false);
	activateOkayTurn = turn;
	unknown458460();
	if (flag && carrier.isValid() && carrier->isDead())
	{
		if (turn == -2)
		{
			if (getCategory() == 4)
				inventory->reopen(5,ID);
			else
				inventoryMgr->unknown896a80(ID);
		}
		else
		{
			InventoryPart *part = inventoryMgr->unknown894e70(ID);
			if (part)
				part->unknown890710(0);
		}
	}
	if (unknown457b70(0x56))
	{
		unknown4585c0(0x56);
		world->unknown464c70(ID);
	}
}
