// g_633790: Entity::die (0x633790), COGMIND.exe Beta 17.1.
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
#include "../../src/util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Point
{
	int x;
	int y;

	Point(int value);	// 0x409990
	Point(int x_, int y_);	// 0x46ca20
	Point(const Point &p) throw();	// 0x46ca50
	Point &operator=(const Point &p);	// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
};

class Entity;
struct EntityEffect;
class Item;
class Group;
class Inventory;

class HEntity
{
public:
	int ID;
	HEntity();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	bool isNull() const;	// 0x9b65d0
	bool operator==(HEntity other) const;	// 0x9b78e0
	bool operator!=(HEntity other) const;	// 0x9b6510
	Entity *operator->() const;	// 0x9b6570
	void reset();	// 0x9b7270
};

class HItem
{
public:
	int ID;
	HItem();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	Item *operator->() const;	// 0x9b65b0
};

struct ED_ItemEffect	// NOTE: placeholder layout (8 bytes)
{
	int type;
	int value;

	ED_ItemEffect(int type_, int value_);	// 0x46ca20 (folded)
};

// NOTE: defined here without throw() so that LTCG proves it nothrow, as in the exe (keeps the extra slot)
ED_ItemEffect::ED_ItemEffect(int type_, int value_)
	: type(type_),
	value(value_)
{
}

class Item
{
public:
	int getType();	// 0x44aec0
	int unknown457f90();	// NOTE: placeholder name
	ED_ItemEffect *getEffect(int type);	// 0x457b70
	int getEffectValue(int type);	// 0x457be0
	void addEffect(ED_ItemEffect *effect);	// 0x4585a0
	void unknown4585c0(int type);	// NOTE: placeholder name
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
	void remove57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class HGroup
{
public:
	int ID;
	Group *operator->() const;	// 0x9b7250
};

class Group
{
public:
	int ed_getType_9b4350();	// NOTE: placeholder name (folded getter)
	void removeMember(HEntity e);	// 0x6716f0
};

class EntityAI
{
public:
	int ed_getType_9b4350();	// NOTE: placeholder name (folded getter)
	void willDie(bool flag);	// 0x5b5b60
	void ed_unknown5bb750(int a, int type, bool b);	// NOTE: placeholder name
};

struct ED_Record	// NOTE: placeholder layout (entity record)
{
	int unknown00;
	string name;	// 0x04
	int unknown20;
	int unknown24;
	int unknown28;
	int pad2c[(0x48 - 0x2c) / 4];
	int unknown48;
	string unknown4C;	// 0x4c
	int unknown68;
	int unknown6C;
	int unknown70;
	bool unknown74;
	int pad78[(0x98 - 0x78) / 4];
	int unknown98;
	int pad9c[(0xbc - 0x9c) / 4];
	int unknownBC;
	int padC0[(0x110 - 0xc0) / 4];
	int unknown110;
	int pad114[(0x120 - 0x114) / 4];
	int unknown120;
	int pad124[(0x158 - 0x124) / 4];
	int unknown158;

	int unknown5c3120();	// NOTE: placeholder name
};

struct ED_Attacker	// NOTE: placeholder layout
{
	HEntity entity;
	int amount;
};

struct ED_Rec12	// NOTE: placeholder layout
{
	int a;
	int b;
	int c;
};

struct ED_DieInfo	// NOTE: placeholder layout
{
	int pad00[0x9c / 4];
	vector<ED_Rec12> unknown9C;
};

struct ED_TurnList;	// NOTE: placeholder name

class ED_RecList	// NOTE: placeholder name (0x14 bytes)
{
public:
	ED_RecList(vector<ED_Rec12> list);	// 0x456280
	~ED_RecList();	// 0x458720 (scalar deleting dtor)
	int data[5];
};

class Entity	// NOTE: placeholder layout
{
public:
	void die(bool a, int cause, HEntity killer, int type, int crit, ED_DieInfo *info, ED_TurnList *turns, bool quiet);

	bool isPlayer();	// 0x5c7600
	int getFaction();	// 0x45a2c0
	int getTarget();	// 0x45a760
	const Point &getPosition();	// 0x45a4a0
	const string &getName();	// 0x45a280
	string &unknown416f40();	// NOTE: placeholder name (folded getter, name)
	bool isHostileTo(HEntity e);	// 0x45aa70
	bool unknown45aaa0(HEntity e);	// NOTE: placeholder name
	Inventory *getInventory();	// 0x45ad90
	bool ed_drop_631a20(HEntity killer, bool flag);	// NOTE: placeholder name
	EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	int unknown45acb0(int type);	// NOTE: placeholder name
	string unknown45a410();	// NOTE: placeholder name
	int unknown5c7fc0(HEntity other);	// NOTE: placeholder name
	bool unknown5d26e0(int type);	// NOTE: placeholder name
	int unknown490840();	// NOTE: placeholder name
	int takeDamage(int a, int b, int c, int d, int e, int f, int g, int h, HEntity i, int j, int k, int l, int m, int n);	// 0x5e5520
	vector<HItem> *getInventoryList();	// 0x45ab00
	Point unknown45a4c0();	// NOTE: placeholder name
	HItem unknown5d2380(int type);	// NOTE: placeholder name
	void unknown5d2430(int type, vector<HItem> *out);	// NOTE: placeholder name
	bool unknown5c8020();	// NOTE: placeholder name
	int getAiType();	// 0x45a2a0
	ED_Record *getInfo();	// NOTE: placeholder name (folded getter 0x9b4350)
	bool unknown5cb680(HGroup g);	// NOTE: placeholder name

	int unknown00;
	HEntity self;	// 0x04
	ED_Record *record;	// 0x08
	string name;	// 0x0c
	HGroup group;	// 0x28
	int unknown2C;
	vector<Point> positions;	// 0x30
	int pad40[(0x70 - 0x40) / 4];
	int unknown70;
	int pad74[(0x8c - 0x74) / 4];
	int unknown8C;
	int pad90[(0xc4 - 0x90) / 4];
	int unknownC4;
	int padC8[(0xec - 0xc8) / 4];
	Inventory *unknownEC;
	int padF0;
	vector<ED_Attacker *> attackersA;	// 0xf4
	vector<ED_Attacker *> attackersB;	// 0x104
	HEntity unknown114;
	int pad118[(0x120 - 0x118) / 4];
	int unknown120;
	int pad124[(0x134 - 0x124) / 4];
	vector<HItem> parts;	// 0x134
	EntityAI *ai;	// 0x144
};

struct ED_Handle	// NOTE: placeholder name
{
	int ID;
};

class ED_Explosion	// NOTE: placeholder name (0x40 bytes, ctor 0x515ca0)
{
public:
	ED_Explosion(HEntity owner, int type, const Point &pos, HEntity other, const Point &from, const Point &at);	// 0x515ca0
	int data[0x10];
};

class Map	// NOTE: partial
{
public:
	HEntity getPlayer();	// 0x4630f0
	HEntity getEntity671();	// NOTE: placeholder name (0x463110)
	vector<HEntity> *unknown4640a0();	// NOTE: placeholder name
	bool unknown714a50();	// NOTE: placeholder name
	void unknown465910(HEntity e);	// NOTE: placeholder name
	bool findPropSpotNear(const Point &p, Point &out, void *data);	// NOTE: placeholder name (0x71c3c0)
	void unknown6c6b90(const Point &p, const string &name, int a, int b);	// NOTE: placeholder name
	int getTurn();	// 0x464270
	bool unknown463dc0(HEntity e);	// NOTE: placeholder name
	string unknown463060(const Point &p);	// NOTE: placeholder name
	void unknown730f40(HEntity e);	// NOTE: placeholder name
	void unknown74b060(const Point &p, int type, int percent);	// NOTE: placeholder name
	void unknown727150(const Point &p, int radius, int strength, int a);	// NOTE: placeholder name
	int pickRecordBelow71cbf0(int value);	// NOTE: placeholder name
	ED_Handle addRecord(ED_Handle h);	// NOTE: placeholder name (0x777a20)
	int unknown4636d0();	// NOTE: placeholder name
	int *unknown463a50(int id);	// NOTE: placeholder name
	void unknown4653b0();	// NOTE: placeholder name
	void unknown72f350();	// NOTE: placeholder name
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	void unknown72f670();	// NOTE: placeholder name
	void unknown749630();	// NOTE: placeholder name
	void unknown72f460();	// NOTE: placeholder name
	void unknown72f4e0(HEntity e);	// NOTE: placeholder name
	HEntity unknown464140();	// NOTE: placeholder name
	void unknown72f3f0();	// NOTE: placeholder name
	bool unknown464180();	// NOTE: placeholder name
	bool *unknown464100();	// NOTE: placeholder name
	void unknown72f570();	// NOTE: placeholder name
	bool unknown715a70();	// NOTE: placeholder name
	void unknown71ba40(HEntity e);	// NOTE: placeholder name
	void unknown464800(HEntity e);	// NOTE: placeholder name
	void unknown729470(HEntity e, int a);	// NOTE: placeholder name
};
extern Map *world;	// 0xcefc4c

class Cell
{
public:
	void clearEntity();	// 0x66baf0
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
};
extern Array2D<Cell *> cells;	// 0xcfd44c

class ED_Stats	// NOTE: placeholder name (0xd2c658)
{
public:
	vector<int> *current;
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
	void add472b90(unsigned int id, int value);	// NOTE: placeholder name
	int unknown472c70(int id);	// NOTE: placeholder name
	int unknown472c90(int id);	// NOTE: placeholder name
};
extern ED_Stats ed_stats;	// NOTE: placeholder name (0xd2c658)

class ED_PlayerData	// NOTE: placeholder name (PlayerData, 0xcf45d8)
{
public:
	bool isSlotEmpty(int slot);	// NOTE: placeholder name (0x46de40)
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern ED_PlayerData ed_playerData;	// NOTE: placeholder name (0xcf45d8)

class ED_Snapshot	// NOTE: placeholder name (0xd2c76c)
{
public:
	void unknown483d30(HEntity e, int a);	// NOTE: placeholder name
};
extern ED_Snapshot ed_snapshot;

class ED_Xom	// NOTE: placeholder name (0xd25450)
{
public:
	bool enabled;
	void unknown69e700(int id, int flag, float amount);	// NOTE: placeholder name
	bool unknown69e9b0(const Point &p);	// NOTE: placeholder name
};
extern ED_Xom ed_xom;
extern int ed_d25464;	// NOTE: placeholder name

class ED_MsgConsole	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void bubble(bool flag);	// NOTE: placeholder name (0x8758d0)
};
extern ED_MsgConsole *ed_cec058;

class CLogMsgs
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern CLogMsgs *ed_logMsgs;	// NOTE: placeholder name (0xcec0b4)
extern CLogMsgs *ed_logMsgs2;	// NOTE: placeholder name (0xcec0c4)

class ED_Factory	// NOTE: placeholder name (0xcefaa8)
{
public:
	bool showOnce(int id, bool enabled, const string *text, bool repeat, bool flag);	// NOTE: placeholder name (0x793450)
	ED_Handle createA(ED_Explosion *e);	// NOTE: placeholder name (0x7930e0)
};
extern ED_Factory *ed_factory;

class ED_Overmind	// NOTE: placeholder name (0xcf6428)
{
public:
	int value;
	void unknown68fc40();	// NOTE: placeholder name
	void unknown681b70(HEntity a, HEntity b);	// NOTE: placeholder name
	void unknown68d980(int a, int b, int c);	// NOTE: placeholder name
};
extern ED_Overmind ed_overmind;
extern int ed_cf64b8;	// NOTE: placeholder name

class ED_Plan	// NOTE: placeholder name (object behind 0xcf68f0)
{
public:
	void unknown672f20(HEntity e, int a, int b, string text);	// NOTE: placeholder name
	bool unknown672dd0(HEntity e, int a);	// NOTE: placeholder name
};
extern ED_Plan *ed_cf68f0;
extern int ed_cf68b4;	// NOTE: placeholder name
extern HEntity ed_cf68b8;	// NOTE: placeholder name

class ED_EntityLists	// NOTE: placeholder name (object behind 0xcefc14)
{
public:
	bool unknown7ac1c0(HEntity e, int a, int b, string text);	// NOTE: placeholder name
	bool take48bfd0(HEntity e);	// NOTE: placeholder name
};
extern ED_EntityLists *ed_cefc14;

class ED_Speaker	// NOTE: placeholder name (object behind 0xcefb48)
{
public:
	bool say(int ID, bool force, string name);	// 0x49e250
};
extern ED_Speaker *ed_cefb48;

struct ED_LogRecord	// NOTE: placeholder layout
{
	int pad00;
	string text;	// 0x04
	int pad20;
	int turn;	// 0x24
};

class ED_Log	// NOTE: placeholder name (0xcf1080)
{
public:
	vector<ED_LogRecord *> &getRecords();	// NOTE: placeholder name (0x9c0790)
	void unknown451400(int value);	// NOTE: placeholder name (folded setter)
};
extern ED_Log ed_log;

extern int ed_cf462c;	// NOTE: placeholder name
extern int ed_cf4b38;	// NOTE: placeholder name
extern bool ed_d1da48;	// NOTE: placeholder name
extern int ed_d28d18;	// NOTE: placeholder name
extern string ed_d1f3d4;	// NOTE: placeholder name
extern string ed_causeNames_d323f8[];	// NOTE: placeholder name
extern string ed_lines_d30360[];	// NOTE: placeholder name
extern string ed_lines_cfb690[];	// NOTE: placeholder name
extern bool ed_table_b951c0[];	// NOTE: placeholder name
extern const char empty_b95223[];
extern const char empty_b9522b[];
extern const char empty_b9523e[];
extern const char empty_b9523f[];
extern const char empty_b9524e[];
extern const char empty_b9524f[];
extern const char empty_b95257[];
extern const char empty_b9525e[];
extern const char empty_b9525f[];
extern const char empty_b95267[];
extern const char empty_b95272[];
extern const char empty_b95273[];
extern const char empty_b9527b[];
extern const char empty_b9528f[];
extern const char empty_b952a1[];
extern const char empty_b952a2[];
extern const char empty_b952a3[];

class ED_Effect	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class ED_EffectMgr	// NOTE: placeholder name (object behind 0xcefc50)
{
public:
	ED_Effect *create();	// NOTE: placeholder name (0x508610)
};
extern ED_EffectMgr *ed_effectMgr;
extern Point ed_effectOrigin;	// NOTE: placeholder name (0xd2e20c)

class ED_Part	// NOTE: placeholder name
{
public:
	void delegate_4a9120();	// NOTE: placeholder name
};

class ED_Interface	// NOTE: placeholder name (object behind 0xcec088)
{
public:
	ED_Part *unknown894e70(HItem item);	// NOTE: placeholder name
};
extern ED_Interface *ed_cec088;

struct ED_Tag;	// NOTE: placeholder name

class ED_GameData	// NOTE: placeholder name (0xd1e860)
{
public:
	ED_Tag *unknown46f530();	// NOTE: placeholder name
	bool unknown46f4b0(int a);	// NOTE: placeholder name
};
extern ED_GameData ed_gameData;

struct ED_Location	// NOTE: placeholder layout
{
	int unknown0;
	int type;
};

class ED_HLocation	// NOTE: placeholder name (0xd1e888)
{
public:
	int ID;
	ED_Location *operator->();	// 0x9b7910
};
extern ED_HLocation ed_location;

class ED_Tally	// NOTE: placeholder name (0xcf6888)
{
public:
	void unknown6998a0(int a, int b, int c);	// NOTE: placeholder name
	void unknown69a0a0(int a);	// NOTE: placeholder name
	void unknown69a5b0(int a);	// NOTE: placeholder name
};
extern ED_Tally ed_tally;

struct ED_Possession	// NOTE: placeholder layout
{
	int pad00[0x2c / 4];
	int unknown2C;
};
extern ED_Possession *ed_cf4700;

class ED_Wrapper	// NOTE: placeholder name
{
public:
	~ED_Wrapper();	// 0x45f860 (scalar deleting dtor)
};
extern ED_Wrapper *ed_cf68bc;

class ED_Pair	// NOTE: placeholder name (0xcf68c0)
{
public:
	void reset_45f0a0();	// NOTE: placeholder name
};
extern ED_Pair ed_cf68c0;

class CAllies
{
public:
	bool unknown48f040(HEntity e);	// NOTE: placeholder name
	void unknown7b7980();	// NOTE: placeholder name
};
extern CAllies *ed_allies;	// NOTE: placeholder name (0xcec0c8)

class ED_Pool	// NOTE: placeholder name (0xd21720)
{
public:
	void remove(HEntity e, bool flag);	// NOTE: placeholder name (0x9d0b30)
};
extern ED_Pool ed_pool;

extern vector<HEntity> ed_cf6adc;	// NOTE: placeholder name
extern vector<int> ed_cfd2cc;	// NOTE: placeholder name
extern vector<int> ed_d2f0f8;	// NOTE: placeholder name
extern vector<int> ed_cf68cc;	// NOTE: placeholder name
extern vector<string> ed_cf4bc0;	// NOTE: placeholder name
extern vector<ED_Tag *> ed_cf4bd0;	// NOTE: placeholder name
extern string ed_names_d2b4f8[];	// NOTE: placeholder name
extern HEntity ed_d1d9f0;	// NOTE: placeholder name
extern HEntity ed_cf6984;	// NOTE: placeholder name
extern HEntity ed_cf69a8;	// NOTE: placeholder name
extern Point ed_cf4d74;	// NOTE: placeholder name
extern int ed_d29730;	// NOTE: placeholder name
extern int ed_cf4b88;	// NOTE: placeholder name
extern int ed_cf4b8c;	// NOTE: placeholder name
extern int ed_cf4b90;	// NOTE: placeholder name
extern int ed_cf4b94;	// NOTE: placeholder name
extern int ed_d254c8;	// NOTE: placeholder name
extern int ed_d254cc;	// NOTE: placeholder name
extern int ed_d254d8;	// NOTE: placeholder name
extern int ed_d254dc;	// NOTE: placeholder name
extern int ed_table_ba5e24[];	// NOTE: placeholder name
extern bool ed_table_b95758[];	// NOTE: placeholder name
extern int ed_cf4d84;	// NOTE: placeholder name
extern bool ed_cf468c;	// NOTE: placeholder name
extern int ed_cf4b5c;	// NOTE: placeholder name
extern int ed_cf4b60;	// NOTE: placeholder name
extern int ed_cf4b64;	// NOTE: placeholder name
extern int ed_cf4b68;	// NOTE: placeholder name
extern int ed_cf4b6c;	// NOTE: placeholder name
extern int ed_cf4d7c;	// NOTE: placeholder name
extern int ed_cf4724;	// NOTE: placeholder name
extern int ed_cf472c;	// NOTE: placeholder name
extern int ed_cf4730;	// NOTE: placeholder name
extern int ed_cf4740;	// NOTE: placeholder name
extern float ed_factors_b91b8c[];	// NOTE: placeholder name
extern int ed_cf4d70;	// NOTE: placeholder name
extern int ed_cf646c;	// NOTE: placeholder name
extern int ed_table_b949c8[];	// NOTE: placeholder name
extern int ed_table_b949d8[];	// NOTE: placeholder name
extern int ed_caf164;	// NOTE: placeholder name
extern int ed_cf4d64;	// NOTE: placeholder name
extern int ed_d1ec60;	// NOTE: placeholder name
extern bool ed_cf6a24;	// NOTE: placeholder name
extern const float ed_f_ba6830;	// NOTE: placeholder name (0.33)
extern const float ed_f_ba6834;	// NOTE: placeholder name (1.0)
extern const float ed_f_ba6838;	// NOTE: placeholder name (0.33)
extern const float ed_f_ba683c;	// NOTE: placeholder name (0.5)
extern const float ed_f_b91b78;	// NOTE: placeholder name (2.0)
extern const float ed_f_b91b74;	// NOTE: placeholder name (0.75)

void logError(string location, string message);	// 0x404f10
void gameOver();	// 0x7c0c40
bool OpU8a_containsEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d31e0)
bool ed_trigger_4569a0(int id, HEntity a, HEntity b, HEntity c, HEntity d, int e, int f, void *list, HEntity g, HEntity h, HEntity i, int j);	// NOTE: placeholder name (0x4569a0)
bool ed_turnUpdate_51da30(ED_TurnList *turns, int type, HEntity entity, HEntity other, HEntity unused, int a, int b);	// NOTE: placeholder name
bool opS2_showMessage_5111e0(int id, const string *a, const string *b, const string *c, HEntity subject, HEntity object, const Point *at, bool flag);	// NOTE: placeholder name
bool opS2_logPhrase_5141b0(int id, const string *a, const string *b, const string *c, HEntity subject, const Point *at);	// NOTE: placeholder name
int opR1d_4541b0(int sound, int a, int b);	// NOTE: placeholder name
bool ed_removeEntity_9d2f00(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name
string intToString(int value);	// 0x4051f0
bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (findEffectID 0x9d7980)
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name
bool ed_between_9daf80(int lo, int v, int hi);	// NOTE: placeholder name
int opr1c_getThresholdIndex(int value);	// NOTE: placeholder name (0x433260)

#define ED_MSG(ID, A, B, C, S, O, AT, FL, BUB, LOG) do { if (opS2_showMessage_5111e0(ID, A, B, C, S, O, AT, FL)) ed_cec058->bubble(BUB); LOG->scrollToEnd(); } while (false)

void Entity::die(bool a, int cause, HEntity killer, int type, int crit, ED_DieInfo *info, ED_TurnList *turns, bool quiet)
{
	unknown8C = 0;
	if (isPlayer() || (ed_cf462c == 7 && self == world->getEntity671()))
	{
		if (ed_cf4b38 == 0x1c)
			ed_cf4b38 = 0xf;
		ed_playerData.unknown77fbc0(0xf3);
		ed_snapshot.unknown483d30(self, 0);
		if (ed_xom.enabled)
		{
			string msg;
			if (ed_d25464 == 0)
				msg = "X0-1V1: \"" + ed_lines_d30360[rng.rangeInt(0, 6)] + "\"";
			else
				msg = "X0-1V1 " + ed_lines_cfb690[rng.rangeInt(0, 8)];
			ED_MSG(0x2b6, &msg, 0, 0, HEntity(), HEntity(), 0, false, true, ed_logMsgs);
		}
		gameOver();
		return;
	}
	if (!self.operator->())
	{
		bool flag = a;
		logError("Entity::die()", "handle already invalid, hm");
		return;
	}
	if ((ed_playerData.isSlotEmpty(0x7b) || ed_xom.enabled) && killer.operator->() && killer->isPlayer() && killer->unknown45aaa0(self) && ed_d1da48)
	{
		ed_playerData.unknown77fbc0(0x7b);
		if (ed_xom.enabled && world->unknown714a50())
			ed_xom.unknown69e700(0x20, record->unknown120 >= 3, 0);
	}
	if (ai)
		ai->willDie(false);
	if (killer.isNull() && (type == 2 || type == 3))
	{
		vector<ED_Attacker *> &list = type == 2 ? attackersA : attackersB;
		ED_Attacker *best = 0;
		for (unsigned int i = 0; i < list.size(); i++)
		{
			if (best == 0 || list[i]->amount > best->amount)
				best = list[i];
		}
		if (best && best->entity.operator->())
			killer = best->entity;
		if (type == 2 && OpU8a_containsEntity(*world->unknown4640a0(), self))
		{
			ed_stats.add4729d0(0x264, 1, empty_b95223, -1);
			ed_playerData.unknown77fbc0(0x3a);
		}
		if (killer == world->getPlayer())
		{
			switch (type)
			{
			case 2:
				ed_stats.add4729d0(0x1fe, 1, empty_b9522b, -1);
				ed_playerData.unknown77fbc0(0x29);
				if (ed_table_b951c0[record->unknown28] && killer->isHostileTo(self))
				{
					ed_stats.add4729d0(0x1ff, 1, empty_b9523e, -1);
					if ((*ed_stats.current)[0x1ff] == 50)
						ed_playerData.unknown77fbc0(0x94);
				}
				break;
			case 3:
				ed_stats.add4729d0(0x202, 1, empty_b9523f, -1);
				ed_playerData.unknown77fbc0(0x2a);
				if (ed_table_b951c0[record->unknown28] && killer->isHostileTo(self))
				{
					ed_stats.add4729d0(0x203, 1, empty_b9524e, -1);
					if ((*ed_stats.current)[0x203] == 20)
						ed_playerData.unknown77fbc0(0x95);
				}
				break;
			}
		}
	}
	bool byItem = false;
	if (!killer.operator->() && unknown114.isValid() && unknown114.operator->())
	{
		killer = unknown114;
		byItem = true;
	}
	if (getFaction() == 6 && ai && ai->ed_getType_9b4350() == 6)
		ai->ed_unknown5bb750(1, type, a);
	if (getFaction() == 0x1b && isHostileTo(world->getPlayer()) && group->ed_getType_9b4350() != 0xc && ed_cf64b8 != 0)
		ed_overmind.unknown68fc40();
	if (ed_cf462c == 6 && killer.operator->())
		world->unknown465910(killer);
	ed_overmind.unknown681b70(self, killer);
	if (killer.operator->())
	{
		ed_d1f3d4 = ed_causeNames_d323f8[cause];
		ed_trigger_4569a0(0x1e, killer, HEntity(), HEntity(), HEntity(), 0, 0, killer->getInventory(), killer, HEntity(), HEntity(), 0);
		if (killer.operator->())
			ed_trigger_4569a0(0x1f, killer, HEntity(), HEntity(), HEntity(), 0, 0, killer->getInventory(), self, HEntity(), HEntity(), 0);
	}
	int partCount = parts.size();
	bool salvaged = ed_drop_631a20(killer, true);
	if (unknown45ac40(0x7b) && rng.chance(unknown45acb0(0x7b)))
	{
		Point p(getPosition());
		if (world->findPropSpotNear(p, p, 0))
			world->unknown6c6b90(p, "Master_Drone_Spawn", 0, -1);
	}
	if (salvaged && killer == world->getPlayer())
		ed_factory->showOnce(0x42, true, 0, false, false);
	if (unknown70 == 0)
	{
		HEntity selfCopy = self;
		ed_trigger_4569a0(2, self, HEntity(), HEntity(), HEntity(), 0, 0, unknownEC, self, HEntity(), HEntity(), 0);
		if (!selfCopy.operator->())
			return;
		if (turns)
		{
			int result = 0;
			if (type == 7)
			{
				ed_turnUpdate_51da30(turns, 0x20, self, HEntity(), HEntity(), 0, 0);
				if (selfCopy.operator->() && killer.operator->())
					ed_turnUpdate_51da30(turns, 0x21, killer, HEntity(), HEntity(), 0, 0);
				if (result && !selfCopy.operator->())
					return;
			}
			else if (type == 8 || type == 9)
			{
				ed_turnUpdate_51da30(turns, 0x22, self, HEntity(), HEntity(), 0, 0);
				if (selfCopy.operator->() && killer.operator->())
					ed_turnUpdate_51da30(turns, 0x23, killer, HEntity(), HEntity(), 0, 0);
				if (!selfCopy.operator->())
					return;
			}
		}
		else if (type == 10 && info && !info->unknown9C.empty())
		{
			ED_RecList *list = new ED_RecList(info->unknown9C);
			bool success = ed_trigger_4569a0(0x24, killer, self, HEntity(), HEntity(), 0, 0, list, self, HEntity(), HEntity(), 0);
			delete list;
			if (success && !selfCopy.operator->())
				return;
		}
	}
	if (ed_cf68b4 && self.operator->() && ed_cf68b8 == self)
		ed_cf68f0->unknown672f20(self, 4, 0, empty_b9524f);
	if (ed_cefc14 && killer.operator->() && self != killer && ed_cefc14)
		ed_cefc14->unknown7ac1c0(self, 0xc, 0, killer->unknown416f40());
	if (type != 2 && type != 3)
	{
		if (!quiet)
			ED_MSG(unknown45aaa0(world->getPlayer()) ? 0x17 : 0x18, 0, 0, 0, self, HEntity(), 0, false, true, ed_logMsgs);
		switch (record->unknown28)
		{
		case 0xc:
			if (ed_playerData.isSlotEmpty(0x32) && killer.operator->() && killer->isPlayer() && isHostileTo(killer) && !getTarget()
				&& ed_log.getRecords().size() > 2 && ed_log.getRecords()[ed_log.getRecords().size() - 2]->turn == world->getTurn()
				&& ed_log.getRecords()[ed_log.getRecords().size() - 2]->text.find("Sneak attack") != string::npos)
				ed_playerData.unknown77fbc0(0x32);
			break;
		case 0xf:
			if (ed_playerData.isSlotEmpty(0x39) && killer.operator->() && killer->isPlayer() && isHostileTo(killer) && !getTarget() && !byItem)
				ed_playerData.unknown77fbc0(0x39);
			break;
		}
	}
	if (ed_d28d18 >= 0)
	{
		string text = "   " + unknown45a410();
		switch (type)
		{
		case 2:
			text += " system corrupted";
			break;
		case 3:
			text += " melted";
			break;
		default:
			text += " destroyed";
			switch (crit)
			{
				break;
			case 3:
				text += " (Crit: Destroy)";
				break;
			case 6:
				text += " (Crit: Smash)";
				break;
			}
		}
		ED_MSG(isPlayer() ? 0x2c9 : (unknown5c7fc0(world->getPlayer()) == 2 ? 0x2ca : 0x2cb), &text, 0, 0, self, HEntity(), 0, true, false, ed_logMsgs2);
	}
	if (unknown120 == 1 && record->unknown28 == 0x18 && isHostileTo(world->getPlayer()))
		ed_playerData.unknown77fbc0(0x2f);
	if (ed_cefb48 && killer.operator->() && killer == world->getEntity671() && killer->isHostileTo(self) && ed_cefb48)
		ed_cefb48->say(0x25, false, unknown416f40());
	if (killer.operator->() && ed_cf68b4 && killer.operator->() && ed_cf68b8 == killer && ed_cf68f0->unknown672dd0(killer, 2) && killer->isHostileTo(self))
		ed_cf68f0->unknown672f20(killer, 2, 1, self->unknown416f40());
	if (ed_cefc14)
	{
		if (killer.operator->() && self != killer && ed_cefc14)
			ed_cefc14->unknown7ac1c0(killer, 0xd, 0, unknown416f40());
		ed_cefc14->take48bfd0(self);
	}
	if (unknown45ac40(0x39))
	{
		if (group->ed_getType_9b4350() == 0 && world->getPlayer()->unknown5d26e0(0xc7))
		{
			int amount = record->unknown68 * 2;
			if (world->getPlayer()->unknown490840() > amount)
			{
				world->getPlayer()->takeDamage(0, 0, 0, amount, 7, 0, 0, 0, HEntity(), 1, 8, 0, 0, 1);
				ED_MSG(0xca, &intToString(amount), 0, 0, self, HEntity(), 0, false, true, ed_logMsgs);
			}
			else
			{
				HItem part;
				vector<HItem> *inventory = world->getPlayer()->getInventoryList();
				for (unsigned int i = 0; i < inventory->size(); i++)
				{
					if ((*inventory)[i]->unknown457f90() == 0xc7 && (*inventory)[i]->getType() <= 3)
					{
						part = (*inventory)[i];
						break;
					}
				}
				if (part.isValid())
				{
					ED_MSG(0xcb, &part->getName(0, 0), 0, 0, self, HEntity(), 0, false, true, ed_logMsgs);
					part->remove57dbe0(1, 1, 1, 1);
				}
			}
		}
		if (!world->unknown463dc0(self))
			ed_removeEntity_9d2f00(ed_cf6adc, self);
	}
	{
		HEntity selfCopy2 = self;
		ed_trigger_4569a0(3, self, HEntity(), HEntity(), HEntity(), 0, 0, unknownEC, self, HEntity(), HEntity(), 0);
		if (!selfCopy2.operator->())
			return;
	}
	if (record->unknown28 == 0x44)
	{
		string announcement = "ANNOUNCEMENT: Tunneling progress halted along " + world->unknown463060(getPosition()) + " route. " + unknown416f40() + " no longer operational.";
		do
		{
			ed_log.unknown451400(1);
			if (false)
				opR1d_4541b0(-1, 0, 0);
			ED_MSG(0x324, &announcement, 0, 0, HEntity(), HEntity(), 0, false, true, ed_logMsgs);
			ed_logMsgs->scrollToEnd();
		} while (false);
		do { opS2_logPhrase_5141b0(0x1c9, 0, 0, 0, HEntity(), 0); } while (false);
	}
	world->unknown730f40(self);
	for (unsigned int i = 0; i < positions.size(); i++)
	{
		world->unknown74b060(positions[i], 4, 100);
		cells(positions[i])->clearEntity();
	}
	if (a)
	{
		int radius = 0;
		int strength = 0;
		switch (record->unknown98)
		{
		case 0:
		case 1:
			radius = 5;
			strength = 5;
			break;
		case 2:
			radius = 10;
			strength = 6;
			break;
		case 3:
		case 4:
			radius = 15;
			strength = 7;
			break;
		}
		world->unknown727150(unknown45a4c0(), radius, strength, ed_d29730);
	}
	else
	{
		int effectID;
		switch (record->unknown98)
		{
		case 0:
		case 1:
			OpU8a_lookup2(type == 3 ? "Robot_Destroyed_Sml_Meltdown" : "Robot_Destroyed_Sml", &effectID);
			break;
		case 2:
			OpU8a_lookup2(type == 3 ? "Robot_Destroyed_Med_Meltdown" : "Robot_Destroyed_Med", &effectID);
			break;
		case 3:
		case 4:
			OpU8a_lookup2(type == 3 ? "Robot_Destroyed_Lrg_Meltdown" : "Robot_Destroyed_Lrg", &effectID);
			break;
		}
		if (effectID)
			ed_effectMgr->create()->init(ed_effectMgr, effectID, unknown45a4c0(), ed_effectOrigin, 0, 0, 0, 9, 0);
		switch (type)
		{
		case 2:
		{
			int corruptionID;
			OpU8a_lookup2("Robot_Corruption", &corruptionID);
			for (unsigned int i = 0; i < positions.size(); i++)
				ed_effectMgr->create()->init(ed_effectMgr, corruptionID, positions[i], ed_effectOrigin, 0, 0, 0, 9, 0);
			break;
		}
		case 3:
		{
			int meltdownID;
			OpU8a_lookup2("Robot_Meltdown", &meltdownID);
			for (unsigned int i = 0; i < positions.size(); i++)
				ed_effectMgr->create()->init(ed_effectMgr, meltdownID, positions[i], ed_effectOrigin, 0, 0, 0, 9, 0);
			break;
		}
		}
	}
	if (ed_cf462c == 9 && record->unknown24)
		world->addRecord(ed_factory->createA(new ED_Explosion(killer, ed_cfd2cc[world->pickRecordBelow71cbf0(record->unknown68)], unknown45a4c0(), HEntity(), Point(-1), Point(-1))));
	else if (record->unknownBC)
	{
		ED_MSG(unknown45aaa0(world->getPlayer()) ? 0x19 : 0x1a, 0, 0, 0, self, HEntity(), 0, false, true, ed_logMsgs);
		world->addRecord(ed_factory->createA(new ED_Explosion(self, record->unknownBC, unknown45a4c0(), HEntity(), Point(-1), Point(-1))));
	}
	if (killer.operator->() && (killer->isPlayer() || killer == world->getEntity671() || killer->getFaction() == 0x30) && type != 10 && record->unknown24 && killer->unknown5d2380(0x68).isValid())
	{
		vector<HItem> items;
		killer->unknown5d2430(0x68, &items);
		for (unsigned int i = 0; i < items.size(); i++)
		{
			if (!items[i]->getEffect(0x72))
				items[i]->addEffect(new ED_ItemEffect(ed_d2f0f8[0x72], record->unknown48));
			else if (items[i]->getEffectValue(0x72) != record->unknown48)
			{
				items[i]->getEffect(0x72)->value = record->unknown48;
				items[i]->unknown4585c0(0x73);
			}
			else if (!items[i]->getEffect(0x73))
				items[i]->addEffect(new ED_ItemEffect(ed_d2f0f8[0x73], 1));
			else
			{
				items[i]->getEffect(0x73)->value++;
				bool known = items[i]->getEffect(0x74) ? true : false;
				if ((!known || items[i]->getEffectValue(0x74) != record->unknown48) && rng.chance(items[i]->getEffectValue(0x73) * (known ? 1 : 5)))
				{
					if (known)
						items[i]->getEffect(0x74)->value = record->unknown48;
					else
						items[i]->addEffect(new ED_ItemEffect(ed_d2f0f8[0x74], record->unknown48));
					ED_MSG(0xc4, &items[i]->getName(0, 0), &ed_names_d2b4f8[items[i]->getEffectValue(0x74)], 0, killer, HEntity(), 0, false, true, ed_logMsgs);
					if (killer->isPlayer())
					{
						do { opS2_logPhrase_5141b0(0x61, &items[i]->getName(0, 0), &ed_names_d2b4f8[items[i]->getEffectValue(0x74)], 0, killer, 0); } while (false);
						ed_cec088->unknown894e70(items[i])->delegate_4a9120();
						opR1d_4541b0(0x56, 0, 0);
					}
					if (killer == world->getEntity671() && ed_cefb48)
						ed_cefb48->say(0x46, false, ed_names_d2b4f8[items[i]->getEffectValue(0x74)]);
				}
			}
		}
	}
	if (group->ed_getType_9b4350() == 3)
		ed_overmind.unknown68d980(0, 0, 0);
	bool announced = false;
	if (unknown45aaa0(world->getPlayer()))
	{
		if (killer.operator->() && killer == world->getPlayer() && (ed_d1d9f0 == self || (!world->unknown4636d0() && type == 10)))
		{
			ed_cf4b90++;
			ed_cf4b94 = world->getTurn();
			if (!record->unknown24)
			{
				do { opS2_logPhrase_5141b0(0x10, &unknown416f40(), 0, 0, HEntity(), 0); } while (false);
				announced = true;
			}
		}
		else if (OpQ1_distanceCeil_40a3f0(getPosition(), world->getPlayer()->getPosition()) <= 20)
		{
			ed_cf4b88++;
			ed_cf4b8c = world->getTurn();
			if (ed_xom.enabled && group->ed_getType_9b4350() <= 2 && !unknown45ac40(0x3a))
			{
				ed_d254d8 += ed_table_ba5e24[record->unknown120];
				ed_d254dc = world->getTurn();
			}
		}
	}
	if (ed_xom.enabled && isHostileTo(world->getPlayer()) && ed_xom.unknown69e9b0(getPosition()) && !unknown45ac40(0x3a))
	{
		ed_d254c8 += ed_table_ba5e24[record->unknown120];
		ed_d254cc = world->getTurn();
	}
	if (killer.operator->() && unknown70 < 6)
	{
		if (killer == world->getPlayer())
		{
			if (getFaction() != 0)
			{
				if (record->unknown70)
				{
					(*world->unknown463a50(record->unknown00))++;
					if ((!record->unknown74 || *world->unknown463a50(record->unknown00) <= 20) && (record->unknown48 > 0x77 || ed_stats.unknown472c90(record->unknown48 + 0xe5) < 60))
						ed_stats.add4729d0(2, 1, empty_b95257, -1);
				}
				if (record->unknown48 == 0x79)
				{
					ed_stats.add4729d0(0x164, 1, record->name, -1);
					ed_cf4bc0.push_back(record->unknown4C.empty() ? name : record->unknown4C);
					ed_cf4bd0.push_back(ed_gameData.unknown46f530());
					if (!announced)
						do { opS2_logPhrase_5141b0(0x13, &(record->unknown4C.empty() ? name : record->unknown4C), 0, 0, HEntity(), 0); } while (false);
					if (ed_cf4bc0.size() == 15)
						ed_playerData.unknown77fbc0(0x164);
					if (record->unknown28 == 0x5b && ed_location->type == 0x17)
						world->unknown4653b0();
					ed_tally.unknown6998a0(0xc, record->unknown68, 0);
				}
				else if (record->unknown48 != 0x7a)
				{
					ed_stats.add4729d0(0xe4, 1, empty_b9525e, record->unknown28);
					if ((*ed_stats.current)[0xe4] == 30)
						ed_playerData.unknown77fbc0(0x142);
					ed_stats.add4729d0(record->unknown48 + 0xe5, 1, empty_b9525f, -1);
					if ((*ed_stats.current)[0xfe] == 5)
						ed_playerData.unknown77fbc0(0x143);
					if ((*ed_stats.current)[0x100] == 5)
						ed_playerData.unknown77fbc0(0x144);
					if ((*ed_stats.current)[0x104] == 10)
						ed_playerData.unknown77fbc0(0x145);
					if (record->unknown24 == 2)
					{
						ed_cf4d84++;
						if (ed_cf4d84 == 30)
							ed_playerData.unknown77fbc0(0x146);
					}
					if (ed_cf462c == 4 && (*ed_stats.current)[0x15b] >= 50 && !ed_cf468c && rng.chance(0x21) && ed_location->type != 5)
						world->unknown749630();
					if (ed_table_b95758[record->unknown48] && (record->unknown28 != 0x3d || partCount >= 8))
						do { opS2_logPhrase_5141b0(0x11, &unknown416f40(), 0, 0, HEntity(), 0); } while (false);
				}
				world->unknown72f350();
				if (group->ed_getType_9b4350() == 4 || killer->isHostileTo(self))
				{
					if (world->getTurn() > ed_cf4b68 + 20)
						ed_cf4b5c = 1;
					else
						ed_cf4b5c++;
					ed_cf4b68 = world->getTurn();
					ed_stats.add4729d0(0x15e, ed_cf4b5c, empty_b95267, -1);
					if ((!record->unknown74 || *world->unknown463a50(record->unknown00) <= 20) && (record->unknown48 > 0x77 || ed_stats.unknown472c90(record->unknown48 + 0xe5) <= 60))
						ed_stats.add4729d0(3, record->unknown70, empty_b95272, -1);
					switch (record->unknown28)
					{
					case 4:
						ed_stats.add4729d0(0xd6, 1, empty_b95273, -1);
						break;
					case 6:
						if (world->unknown4631f0(self))
							ed_playerData.unknown77fbc0(0x11d);
						break;
					}
					if (ed_location->type == 0x14)
						world->unknown72f670();
					if (ed_table_b951c0[record->unknown28])
					{
						ed_stats.add4729d0(0xdf, 1, empty_b9527b, -1);
						if ((*ed_stats.current)[0xdf] >= 100 && (ed_playerData.isSlotEmpty(0x90) || ed_playerData.isSlotEmpty(0x91) || ed_playerData.isSlotEmpty(0x92) || ed_playerData.isSlotEmpty(0x93)))
						{
							if (int total = (*ed_stats.current)[0x1b2] + (*ed_stats.current)[0x1b3] + (*ed_stats.current)[0x1b4] + (*ed_stats.current)[0x1b5] + (*ed_stats.current)[0x1b6])
							{
								if ((*ed_stats.current)[0x1b2] * 100 / total >= 90)
									ed_playerData.unknown77fbc0(0x90);
								if ((*ed_stats.current)[0x1b3] * 100 / total >= 90)
									ed_playerData.unknown77fbc0(0x91);
								if ((*ed_stats.current)[0x1b4] * 100 / total >= 90)
									ed_playerData.unknown77fbc0(0x92);
								if ((*ed_stats.current)[0x1b5] * 100 / total >= 90)
									ed_playerData.unknown77fbc0(0x93);
							}
						}
						if (ed_between_9daf80(7, type, 10))
						{
							ed_stats.add4729d0(type + 0xd9, 1, empty_b9528f, -1);
							if (type == 7 && (*ed_stats.current)[0xe0] == 200)
								ed_playerData.unknown77fbc0(0x13b);
						}
						ed_cf4b60++;
						ed_cf4b64 += record->unknown5c3120();
						ed_cf4b6c = world->getTurn();
						ed_stats.add4729d0(0x15f, ed_cf4b60, empty_b952a1, -1);
						if ((*ed_stats.current)[0x15f] == 20)
							ed_playerData.unknown77fbc0(0x11b);
						else if ((*ed_stats.current)[0x15f] == 35)
							ed_playerData.unknown77fbc0(0x137);
						if (ed_playerData.isSlotEmpty(0x11c) && ed_location->type == 3)
						{
							if (killer->getPosition() == ed_cf4d74)
							{
								ed_cf4d7c++;
								if (ed_cf4d7c == 30)
									ed_playerData.unknown77fbc0(0x11c);
							}
							else
							{
								ed_cf4d7c = 1;
								ed_cf4d74 = killer->getPosition();
							}
						}
						int threshold = opr1c_getThresholdIndex(ed_overmind.value);
						if (ed_cf4724)
							ed_stats.add472b90(9, (int)(record->unknown70 * ed_f_ba6830));
						if (ed_cf472c)
							ed_stats.add472b90(0xb, (int)(record->unknown70 * ed_f_ba6834));
						if (ed_cf4730)
							ed_stats.add472b90(0xc, (int)(record->unknown70 * ed_f_ba6838));
						if (ed_cf4740)
							ed_stats.add472b90(0x10, (int)(record->unknown70 * ed_f_ba683c));
						if (threshold && ed_factors_b91b8c[threshold] != 0 && ed_gameData.unknown46f4b0(1) && ed_location->type != 0x23 && (record->unknown48 > 0x77 || ed_stats.unknown472c90(record->unknown48 + 0xe5) <= 60))
							ed_stats.add472b90(0x17, (int)(record->unknown70 * ed_factors_b91b8c[threshold]));
						if (ed_location->type == 0x17 && ed_stats.unknown472c70(0x36) && group->ed_getType_9b4350() == 3)
							ed_stats.add472b90(0x37, (int)(record->unknown70 * ed_f_b91b78));
						if (ed_cf4700)
							ed_cf4700->unknown2C++;
						switch (type)
						{
						case 7:
							world->unknown72f460();
							break;
						case 8:
							world->unknown72f4e0(self);
						case 9:
							if (world->unknown464140() == self)
								ed_playerData.unknown77fbc0(0xb0);
							break;
						case 10:
							world->unknown72f3f0();
							if (world->unknown464180())
								ed_playerData.unknown77fbc0(0xb1);
							break;
						}
						*world->unknown464100() = false;
						if (record->unknown28 == 0x15 && cause == 2)
							ed_playerData.unknown77fbc0(0x27);
						if (ed_stats.unknown472c70(0x113) == 5)
							ed_playerData.unknown77fbc0(0x132);
						if (record->unknown28 == 0x3c && ed_location->type == 7)
							world->unknown72f570();
						if (record->unknown28 == 0x25 && ed_location->type == 0xf && ed_cf4d70 != -1)
						{
							if (world->unknown715a70())
								ed_cf4d70 = -1;
							else
								ed_cf4d70++;
						}
						if (group->ed_getType_9b4350() == 3)
							ed_cf646c++;
					}
				}
				else if (unknown5c8020())
				{
					ed_stats.add472b90(0x6a, ed_table_b951c0[record->unknown28] ? ed_table_b949c8[record->unknown24] : ed_table_b949d8[record->unknown24]);
					ed_playerData.unknown77fbc0(0x19);
					if ((*ed_stats.current)[0x6a] <= -1000)
						ed_playerData.unknown77fbc0(0xca);
				}
				if (record->unknown28 == 4)
				{
					ed_playerData.unknown77fbc0(0xd);
					if ((*ed_stats.current)[0xe8] == 20)
						ed_playerData.unknown77fbc0(0xe);
				}
				if (record->unknown110 != 10)
					ed_playerData.unknown77fbc0(0x140);
			}
		}
		else
		{
			if (killer->unknown45aaa0(world->getPlayer()))
			{
				killer->unknownC4++;
				if (killer->getInfo()->unknown158 != ed_caf164 && killer->getName() == "Wardrone")
				{
					ed_cf4d64++;
					if (ed_cf4d64 == 10)
						ed_playerData.unknown77fbc0(0xda);
				}
				if (killer->unknownC4 == 20 && (killer->getAiType() == 1 || killer->getAiType() == 2) && killer->getInfo()->unknown28 != 10 && killer->getInfo()->unknown28 != 11 && killer->getName().find("Enhanced") == string::npos)
					ed_playerData.unknown77fbc0(0x147);
			}
			if (killer->group->ed_getType_9b4350() <= 2)
			{
				ed_stats.add4729d0(0x3b0, 1, empty_b952a2, -1);
				if ((*ed_stats.current)[0x3b0] == 75)
					ed_playerData.unknown77fbc0(0xc9);
				if ((group->ed_getType_9b4350() == 4 || killer->isHostileTo(self)) && ed_table_b951c0[record->unknown28])
				{
					if (killer == world->getEntity671())
						ed_stats.add4729d0(0x453, 1, empty_b952a3, -1);
					if (OpQ1_distanceCeil_40a3f0(killer->getPosition(), world->getPlayer()->getPosition()) <= 20 && (record->unknown48 > 0x77 || ed_stats.unknown472c90(record->unknown48 + 0xe5) <= 60))
						ed_stats.add472b90(0x18, (int)(record->unknown70 * ed_f_b91b74));
					if (group->ed_getType_9b4350() == 3)
						ed_cf646c++;
				}
				if (record->unknown48 == 0x79)
				{
					ed_stats.add4729d0(0x164, 1, record->name, -1);
					ed_cf4bc0.push_back(record->unknown4C.empty() ? name : record->unknown4C);
					ed_cf4bd0.push_back(ed_gameData.unknown46f530());
					do { opS2_logPhrase_5141b0(0x14, &(record->unknown4C.empty() ? name : record->unknown4C), 0, 0, self, 0); } while (false);
					if (ed_cf4bc0.size() == 15)
						ed_playerData.unknown77fbc0(0x164);
					ed_tally.unknown6998a0(0xc, record->unknown68, 0);
				}
				else if (ed_table_b95758[record->unknown48] && (record->unknown28 != 0x3d || partCount >= 8))
					do { opS2_logPhrase_5141b0(0x12, &unknown416f40(), 0, 0, self, 0); } while (false);
			}
		}
	}
	if (record->unknown28 == 0x1b && group->ed_getType_9b4350() == 0xc && ed_location->type == 0x22 && unknown45ac40(0x2e))
		ed_d1ec60++;
	if (record->unknown110 != 10)
	{
		ed_cf68cc[record->unknown110] = 0;
		ed_cf68b4 = 0;
		ed_cf68b8.reset();
		delete ed_cf68bc;
		ed_cf68bc = 0;
		ed_cf68c0.reset_45f0a0();
		if (killer.operator->() && killer->unknown45aaa0(world->getPlayer()))
			ed_stats.add472b90(0x1c, -999999);
		switch (record->unknown110)
		{
		case 7:
			ed_cf6a24 = false;
			break;
		}
	}
	if (ed_cf6984 == self)
		ed_tally.unknown69a0a0(1);
	else if (ed_cf69a8 == self)
		ed_tally.unknown69a5b0(1);
	world->unknown71ba40(self);
	group->removeMember(self);
	if (world->unknown4631f0(self) && world->getPlayer().operator->() && world->getPlayer()->unknown5cb680(group))
		world->unknown464800(self);
	if (ed_allies->unknown48f040(self))
		ed_allies->unknown7b7980();
	world->unknown729470(self, 0);
	ed_pool.remove(self, true);
}
