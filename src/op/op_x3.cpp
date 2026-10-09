// op_x3: AI/entity helpers in 0x581000-0x69e000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

struct Point
{
	int x;
	int y;

	Point(int v);	// 0x409990
};
void sweepGetSurroundingCells(const Point &point, vector<Point> &adjacent);	// 0x4faaf0
int distanceCeil(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
class Entity;
class HEntity
{
public:
	int ID;
	Entity *operator->() const;	// 0x9b6570
	void reset();	// NOTE: placeholder name (0x9b7270)
	HEntity();
	bool operator==(HEntity other) const;	// 0x9b78e0
	bool isValid() const;	// NOTE: placeholder name
};
class HProp
{
	int ID;
public:
	HProp();
};
class Item;
class HItem
{
	int ID;
public:
	Item *operator->() const;	// 0x9b65b0
	bool isValid() const;
	bool isNull() const;	// NOTE: placeholder name
};
class HItemList : public vector<HItem>	// NOTE: placeholder layout
{
};
class Item
{
public:
	int name4578a0();	// NOTE: placeholder name (0x4578a0)
	int getNestedField2();	// NOTE: placeholder name (0x4578c0)
	int unknown457f90();	// NOTE: placeholder name
	int unknown457880();	// NOTE: placeholder name
	void setField450460(int value);	// NOTE: placeholder name (0x450460, folded setter)
};
class OpX3_Group	// NOTE: placeholder name
{
public:
	int getType();	// NOTE: placeholder name
	vector<HEntity> *getMembers();	// NOTE: placeholder name (0x416f40, folded getter)
};
class HGroup
{
	int ID;
public:
	OpX3_Group *operator->() const;	// 0x9b7250
};

class OpX3_Part	// NOTE: placeholder name
{
public:
	int unknown458950(int type);	// NOTE: placeholder name
};

class OpX3_AI	// NOTE: placeholder name
{
public:
	bool unknown459090();	// NOTE: placeholder name
	OpX3_Part *unknown4590f0();	// NOTE: placeholder name
	void unknown4582d0(int value);	// NOTE: placeholder name
	void unknown5b5220();	// NOTE: placeholder name
	HEntity getFollowEntity();	// 0x458ed0
	void setField34(int value);	// NOTE: placeholder name (0x451400, folded setter)
	void setFollowEntity(HEntity followEntity_, int followParam_);	// 0x5b2f80
	void unknown459540(const Point &p);	// NOTE: placeholder name
};

struct OpX3_EntityData	// NOTE: placeholder name
{
	char pad00[0x80];
	int m80;
};

class Entity
{
public:
	OpX3_AI *getAI();	// 0x45b590
	bool unknown5c8820(HEntity other);	// NOTE: placeholder name
	int unknown45a340();	// NOTE: placeholder name
	bool isHostileTo(HEntity e);
	HGroup getGroup();
	int getFaction();
	const Point &getPosition();	// 0x45a4a0
	bool unknown5d4230(HEntity e);	// NOTE: placeholder name
	bool unknown5d4100();	// NOTE: placeholder name
	int unknown5d22a0(int type);	// NOTE: placeholder name
	HItem unknown5d2380(int type);	// NOTE: placeholder name
	bool unknown5d6c30(vector<HItem> *out);	// NOTE: placeholder name
	int unknown5d7320(vector<HItem> *list, bool notify);	// NOTE: placeholder name
	int unknown5d6d80(vector<HItem> *items, HProp target);	// NOTE: placeholder name
	int unknown5cab00();	// NOTE: placeholder name
	int unknown5ca8d0();	// NOTE: placeholder name
	int unknown5d1da0();	// NOTE: placeholder name
	int unknown5d15a0(bool notify);	// NOTE: placeholder name
	int unknown5d1390();	// NOTE: placeholder name
	int unknown5d2990(int type);	// NOTE: placeholder name
	int *unknown45a840();	// NOTE: placeholder name
	int unknown5c8fc0(int slot, bool active);	// NOTE: placeholder name
	bool unknown45a780();	// NOTE: placeholder name
	int unknown5d28f0(int type);	// NOTE: placeholder name
	unsigned int unknown5cb830(vector<HItem> *out);	// NOTE: placeholder name
	HItemList *getInventoryList();	// 0x45ab00

	int unknown5c7d30();	// NOTE: placeholder name
	int unknown45a810();	// NOTE: placeholder name
	int unknown5d2150(int type, int base);	// NOTE: placeholder name

	char pad00[8];
	OpX3_EntityData *data;	// +0x08
	char pad0c[0x70 - 0xc];
	int m70;
	char pad74[0xb8 - 0x74];
	bool unknownB8;
};
class OpX3_PlayerData	// NOTE: placeholder name (0xcf45d8)
{
public:
	bool unknown77f260(int value);	// NOTE: placeholder name
};
extern OpX3_PlayerData opX3_playerData;	// NOTE: placeholder name (0xcf45d8)
extern const int opX3_ba87b0;	// NOTE: placeholder name (0xba87b0)
int opX3_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
int distanceCeil(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
extern RNG rng;	// NOTE: placeholder name (0xd30908)

class Map
{
public:
	HEntity getPlayer();
	bool isReachable(int range, const Point &from, const Point &to);	// NOTE: placeholder name (0x465230)
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	bool unknown463660();	// NOTE: placeholder name
	void unknown72e8e0(int a);	// NOTE: placeholder name
};
extern Map *world;	// NOTE: placeholder name (0xcefc4c)
extern vector<int> opX3_options;	// NOTE: placeholder name (0xcf4a04)
extern const float opX3_half;	// NOTE: placeholder name (0xba7b48, 0.5f)
bool inRange(int low, int value, int high);	// NOTE: placeholder name (0x9daf80)

class OpX3_Ai	// NOTE: placeholder name
{
public:
	HEntity owner;	// +0x00
	char pad04[0x50 - 4];
	HEntity target;	// +0x50

	bool unknown581a00(bool flag);	// NOTE: placeholder name
	bool unknown581140();	// NOTE: placeholder name
};


bool OpX3_Ai::unknown581a00(bool flag)
{
	if (target.operator->() != NULL && target->getAI()->unknown459090() && target->getAI()->unknown4590f0()->unknown458950(7))
	{
		if (owner->unknown5c8820(target))
		{
			return flag ? owner->unknown45a340() >= 3 : owner->unknown45a340() < 3;
		}
		else
		{
			return false;
		}
	}
	else
	{
		target.reset();
		return false;
	}
}

//--------------------------------------------------------------
class OpX3_AiB	// NOTE: placeholder name
{
public:
	HEntity owner;	// +0x00
	char pad04[0x10 - 4];
	Point m10;
	char pad18[0xcc - 0x18];
	int mcc;
	char padd0[0x11c - 0xd0];
	OpX3_Part *m11c;

	bool unknown5813a0();	// NOTE: placeholder name
};
extern int opX3_cf64b4;	// NOTE: placeholder name (0xcf64b4)
int opX3_unknown6c10f0(const Point &p);	// NOTE: placeholder name (0x6c10f0)


bool OpX3_AiB::unknown5813a0()
{
	if (owner->getFaction() != 2 || opX3_cf64b4 >= 0xf)
	{
		return false;
	}
	if (mcc != -1)
	{
		return true;
	}
	if (m10.x != -1 && opX3_unknown6c10f0(m10) != -1)
	{
		return true;
	}
	if (m11c != NULL && m11c->unknown458950(9))
	{
		return false;
	}
	vector<Point> cells;
	sweepGetSurroundingCells(owner->getPosition(),cells);
	for (unsigned int i = 0; i < cells.size(); i++)
	{
		if (opX3_unknown6c10f0(cells[i]) != -1)
		{
			return true;
		}
	}
	return false;
}

//--------------------------------------------------------------
extern string gameStrings_d2ed90[];	// 0xd2ed90
extern string gameStrings_cf6b28[];	// 0xcf6b28

class EntityAI	// NOTE: placeholder layout
{
public:
	HEntity owner;	// +0x00
	int mode;		// +0x04
	char pad08[0x55 - 8];
	bool m55;
	char pad56[0x58 - 0x56];
	HEntity target;	// +0x58
	char pad5c[0x104 - 0x5c];
	int m104;

	int unknown459280();	// NOTE: placeholder name
	bool unknown458fb0(HEntity e);	// NOTE: placeholder name
	void unknown5b5f40();	// NOTE: placeholder name
	string unknown581670();	// NOTE: placeholder name
};

string EntityAI::unknown581670()
{
	if (unknown459280() != 0xb)
	{
		return gameStrings_d2ed90[unknown459280()];
	}
	if (owner->getFaction() == 4 && mode == 2)
	{
		return "TRANSPORT";
	}
	if (owner->getFaction() == 0x13)
	{
		return "SUPPORT";
	}
	if (owner->getFaction() == 0x1d)
	{
		return "DISPOSE";
	}
	if (target.operator->() != NULL && target->getGroup()->getType() == 4)
	{
		return "ESCORT";
	}
	if (m55 && mode == 0x19)
	{
		return "RETREAT";
	}
	return gameStrings_cf6b28[mode];
}

void EntityAI::unknown5b5f40()
{
	if (owner->data->m80 != 0 && target.operator->() == NULL && owner->m70 == 0)
	{
		HEntity player = world->getPlayer();
		if (!unknown458fb0(player) && !opX3_playerData.unknown77f260(opX3_ba87b0))
		{
			if (player->unknown5d2380(0x1f).isNull() || owner->getGroup()->getType() != 3)
			{
				if (rng.chance(opX3_maxInt(5,owner->data->m80 - player->unknown5d2150(0x1e,0) * 4)))
				{
					int distance = distanceCeil(player->getPosition(),owner->getPosition());
					if (m104 == 0 || distance < m104)
					{
						if (distance <= owner->unknown5c7d30() - player->unknown5d2150(0x1e,0))
						{
							if (world->isReachable(owner->unknown5c7d30(),owner->getPosition(),player->getPosition()))
							{
								m104 = distance;
							}
						}
					}
				}
			}
		}
	}
}

//--------------------------------------------------------------
class OpX3_Plan	// NOTE: placeholder name
{
public:
	HEntity owner;	// +0x00
	int mode;		// +0x04
	int m8;			// +0x08
	int mc;			// +0x0c
	vector<unsigned int> m10;	// +0x10
	bool m20;
	vector<int> m24;	// +0x24
	int m34;
	float m38;
	int m3c;
	int m40;
	vector<int> m44;	// +0x44

	OpX3_Plan(HEntity owner_, int mode_);	// 0x581af0
	void unknown5823b0();	// NOTE: placeholder name (0x5823b0)
	void unknown581b80(int mode_);	// NOTE: placeholder name
	void unknown582400();	// NOTE: placeholder name
	void unknown582560();	// NOTE: placeholder name
};

OpX3_Plan::OpX3_Plan(HEntity owner_, int mode_)
	: owner		(owner_)
{
	unknown581b80(mode_);
}

void OpX3_Plan::unknown582560()
{
	int type;
	m44.assign(0xdbu,0);
	HItemList *inventory = owner->getInventoryList();
	for (unsigned int i = 0; i < inventory->size(); i++)
	{
		type = (*inventory)[i]->unknown457f90();
		if (type != 0)
		{
			if (inRange(0x43,type,0x45))
			{
				for (int j = 0x43; j <= 0x45; j++)
				{
					m44[j]++;
				}
			}
			else if (inRange(0x46,type,0x47))
			{
				for (int k = 0x46; k <= 0x47; k++)
				{
					m44[k]++;
				}
			}
			else
			{
				m44[type]++;
			}
		}
	}
}

void OpX3_Plan::unknown582400()
{
	vector<HItem> w;
	int bonus;
	int done;
	int f;
	int out;
	owner->unknown5d6c30(&w);
	out = owner->unknown5d7320(&w,false);
	bonus = owner->unknown5d6d80(&w,HProp());
	f = owner->unknown5cab00();
	done = owner->unknown5ca8d0() + owner->unknown5d1da0() * 100 / owner->unknown5d15a0(false);
	if (done > f)
	{
		m38 = 3.0f;
	}
	out += owner->unknown5ca8d0() * bonus / 100;
	f = f * bonus / 100;
	if (f < out)
	{
		m38 = 5.0f;
	}
}

void OpX3_Plan::unknown581b80(int mode_)
{
	mode = mode_;
	m8 = 5;
	mc = 0x1f;
	m10.clear();
	m24.clear();
	m34 = 0;
	m38 = 1.0f;
	m44.clear();
	unknown5823b0();
	m3c = owner->unknown5d2990(7);
	m40 = owner->unknown45a840()[3];
	switch (mode)
	{
	case 1:
		unknown582400();
		break;
	case 2:
		unknown582400();
		for (int i = 0; i < 4; i++)
		{
			if (!owner->unknown5c8fc0(i,false))
			{
				m10.push_back((unsigned int)i);
			}
		}
		m20 = owner->unknown45a780();
		unknown582560();
		break;
	case 3:
		unknown582560();
	case 0:
		m34 = owner->unknown5d28f0(1) + owner->unknown5d28f0(2);
		m34 = (int)(m34 * opX3_half);
		m24.assign(4u,0);
		vector<HItem> items;
		owner->unknown5cb830(&items);
		for (unsigned int i = 0; i < items.size(); i++)
		{
			if (items[i]->name4578a0() < 4)
			{
				m24[items[i]->name4578a0()] += items[i]->getNestedField2();
				if (items[i]->unknown457f90() == 1 || items[i]->unknown457f90() == 2)
				{
					m34 = m34 - 1;
				}
			}
		}
		break;
	}
}

//--------------------------------------------------------------
struct OpX3_FollowRec	// NOTE: placeholder name
{
	char pad00[4];
	HEntity entity;	// +0x04
	int m8;
	char padc[0x18 - 0xc];
	int m18;
};

class OpX3_Mgr	// NOTE: placeholder name
{
public:
	void unknown68cd80(OpX3_FollowRec *rec);	// NOTE: placeholder name
};

void OpX3_Mgr::unknown68cd80(OpX3_FollowRec *rec)
{
	if (rec->m8 != -2)
	{
		rec->entity->getAI()->unknown4582d0(0x17);
		rec->entity->getAI()->unknown5b5220();
		vector<HEntity> *members = rec->entity->getGroup()->getMembers();
		for (unsigned int i = 0; i < members->size(); i++)
		{
			if ((*members)[i]->getAI()->getFollowEntity() == rec->entity)
			{
				(*members)[i]->getAI()->unknown4582d0(0x17);
				(*members)[i]->getAI()->unknown5b5220();
			}
		}
		rec->m8 = -2;
		rec->m18 = 0;
		if (rec->entity->getAI()->getFollowEntity().operator->() != NULL && rec->entity->getAI()->getFollowEntity()->getFaction() == 0x1a)
		{
			rec->entity->getAI()->getFollowEntity()->getAI()->setField34(1);
			rec->entity->getAI()->setFollowEntity(HEntity(),0);
		}
	}
}

//--------------------------------------------------------------
template <class T>
class OpX3_WL	// NOTE: placeholder name (weighted list)
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpX3_WL() throw();	// 0x9bab50
	void add(T value, int weight);	// 0x9ba310
	T &pick();	// 0x9ba470
};

struct OpX3_ItemDef;
class OpX3_Record	// NOTE: placeholder name
{
};

struct OpX3_Range	// NOTE: placeholder name
{
	int lo;
	int hi;
	int randomInRange_40c130();	// NOTE: placeholder name
};
extern OpX3_Range opX3_rangeCfd300;	// NOTE: placeholder name (0xcfd300)
extern OpX3_Range opX3_rangeD33bd8;	// NOTE: placeholder name (0xd33bd8)
extern int opX3_gameModeCf462c;	// NOTE: placeholder name (0xcf462c)

class OpX3_Console	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpX3_Console *opX3_console;	// NOTE: placeholder name (0xcec058)
class OpX3_LogMsgs	// NOTE: placeholder name (0xcec0b4)
{
public:
	void scrollToEnd();	// NOTE: placeholder name
};
extern OpX3_LogMsgs *opX3_logMsgs;	// NOTE: placeholder name (0xcec0b4)
bool opX3_logMessage(int id, const string *a, const string *b, int c, HEntity d, HProp e, const Point *f, int g);	// NOTE: placeholder name (0x5111e0)
int opX3_454260(const Point &pos, unsigned int sound);	// NOTE: placeholder name

class OpX3_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	OpX3_Record *unknown6c5600(int a, int b, int c, int d);	// NOTE: placeholder name (0x6c5600)
	HEntity placeEntity(OpX3_Record *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);	// 0x6c58c0
	bool unknown6ca170(const Point &range, int picks, int count, int chanceType, vector<OpX3_ItemDef *> *items, vector<int> *counts, int unknown);	// NOTE: placeholder name
	HItem unknown6c51d0(OpX3_ItemDef *type, HEntity entity, bool a, bool b);	// NOTE: placeholder name
};
extern OpX3_World *opX3_world;	// NOTE: placeholder name (0xcefc4c)

//--------------------------------------------------------------
struct OpX3_ItemDef	// NOTE: placeholder name
{
	char pad00[0x4c];
	int cost;
};
struct OpX3_LocInfo	// NOTE: placeholder name
{
	char pad00[8];
	int depthIndex;
};
class OpX3_HLoc	// NOTE: placeholder name
{
	int ID;
public:
	OpX3_LocInfo *operator->() const;	// 0x9b7910
};
extern OpX3_HLoc opX3_location;	// NOTE: placeholder name (0xd1e888)
struct OpX3_RangePair	// NOTE: placeholder name
{
	OpX3_Range lo;
	OpX3_Range hi;
};
extern OpX3_RangePair opX3_ranges[];	// NOTE: placeholder name (0xd357a8)
extern OpX3_WL<OpX3_ItemDef *> opX3_wlD31700;	// NOTE: placeholder name (0xd31700)
int minInt(int a, int b);	// 0x9cdb30

class OpX3_Spawner	// NOTE: placeholder name
{
public:
	void unknown690470(const Point &pos, const Point &target, bool flag, bool *seen);	// NOTE: placeholder name
	void unknown6901e0(HEntity e, int chanceType, int n, int count, const Point &range, bool flag, int unknown);	// NOTE: placeholder name
};

void OpX3_Spawner::unknown690470(const Point &pos, const Point &target, bool flag, bool *seen)
{
	OpX3_WL<int> wl;
	wl.add(1,0x1e);
	wl.add(2,0x19);
	wl.add(3,0xf);
	wl.add(5,0x19);
	wl.add(4,5);
	OpX3_Record *record = opX3_world->unknown6c5600(1,wl.pick(),0,0);
	if (record != NULL)
	{
		HEntity placed = opX3_world->placeEntity(record,pos,4,false,0x19,0xe,false);
		if (placed.isValid())
		{
			if (!flag)
			{
				do
				{
					if (opX3_logMessage(0x247,NULL,NULL,0,placed,HProp(),NULL,0))
						opX3_console->unknown8758d0(true);
					opX3_logMsgs->scrollToEnd();
				} while (0);
				if (!flag && !*seen && opX3_454260(pos,0x93))
				{
					*seen = true;
				}
			}
			placed->getAI()->unknown459540(target);
			if (placed->getFaction() == 4 && opX3_gameModeCf462c != 2)
			{
				unknown6901e0(placed,0,opX3_rangeCfd300.randomInRange_40c130(),opX3_rangeD33bd8.randomInRange_40c130(),Point(-1),0,0x2a);
			}
		}
	}
}

void OpX3_Spawner::unknown6901e0(HEntity e, int chanceType, int n, int count, const Point &range, bool flag, int unknown)
{
	int budget;
	vector<OpX3_ItemDef *> key;
	vector<int> t;
	bool ok;
	if (!flag && rng.chance(1))
	{
		for (int i = 0; i < n; i++)
		{
			key.push_back(opX3_wlD31700.pick());
		}
		t.assign(key.size(),1);
		ok = true;
	}
	else
	{
		ok = opX3_world->unknown6ca170(range,minInt(e->unknown45a810(),n),count,chanceType,&key,&t,unknown);
	}
	if (!ok && chanceType == 1)
	{
		ok = opX3_world->unknown6ca170(range,minInt(e->unknown45a810(),n),count,0,&key,&t,unknown);
	}
	budget = e->unknown45a810();
	if (ok)
	{
		for (unsigned int i = 0; i < key.size(); i++)
		{
			for (int j = 0; j < t[i]; j++)
			{
				if (budget >= key[i]->cost)
				{
					HItem item = opX3_world->unknown6c51d0(key[i],e,false,!flag);
					if (item->unknown457880() == 0)
					{
						item->setField450460(opX3_ranges[opX3_location->depthIndex].lo.randomInRange_40c130());
					}
					budget -= key[i]->cost;
				}
			}
		}
	}
}
