// 0x633790 Entity::die (COGMIND.exe Beta 17.1, 0x4281 bytes): semantic reconstruction, not byte-matched.
// Notes, open questions and gdiff numbers: docs/giants/633790.md.
// NOTE: class layouts below are partial; members are listed in offset order with their 32-bit offsets in comments.
// Names are placeholders unless stated otherwise; callees keep their csv names.
#include <string>
#include <vector>
#include "util/rng.h"
using namespace std;

//==================================================================
// Declarations
//==================================================================

struct Point
{
	int x;
	int y;

	Point();
	Point(int v);					// 0x409990, (v,v)
	Point(const Point &p);			// 0x46ca50
	Point &operator=(const Point &p);	// 0x46ca50 (folded with the copy ctor)
	bool operator==(const Point &p) const;	// 0x409b90
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

class Entity;
class Item;
class Group;
class Inventory;
struct Location;

class HEntity
{
	int	ID;
public:
	HEntity();
	bool isNull() const;			// 0x9b65d0
	bool isValid() const;			// 0x9b7230
	void clear();					// NOTE: placeholder name (0x9b7270)
	Entity *operator->() const;		// 0x9b6570
	bool operator==(HEntity other) const;	// 0x9b78e0
	bool operator!=(HEntity other) const;	// 0x9b6510
};

class HProp
{
	int	ID;
public:
	HProp();
};

class HItem
{
	int	ID;
public:
	HItem();
	bool isValid() const;			// 0x9b7230
	Item *operator->() const;		// 0x9b65b0
};

class HGroup
{
	int	ID;
public:
	Group *operator->() const;		// 0x9b7250
};

class HLocation	// NOTE: placeholder name (global handle at 0xd1e888)
{
	int	ID;
public:
	Location *operator->() const;	// 0x9b7910
};

class HRecord	// NOTE: placeholder name (handle returned by GM::createA, 0x7930e0)
{
	int	ID;
};

struct Location	// NOTE: placeholder name
{
	int		unknown00;
	int		type;	// +0x04, NOTE: placeholder name (map type)
};

class Group
{
public:
	int unknown9b4350();				// NOTE: placeholder name (ICF'd trivial getter of +0x08, the group type)
	void unknown6716f0(HEntity e);		// NOTE: placeholder name (removes a member)
};

struct ItemEffect	// NOTE: placeholder name
{
	int		type;
	int		state;

	ItemEffect(int type_, int state_);	// 0x46ca20
};

class Item
{
public:
	int unknown457f90();				// NOTE: placeholder name (data->+0xf0)
	int unknown44aec0();				// NOTE: placeholder name (ICF'd trivial getter of +0x0c)
	string getName(int a, int b);		// NOTE: placeholder name (0x571db0)
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	ItemEffect *getEffect(int type);	// NOTE: placeholder name (0x457b70)
	int getEffectValue(int type);		// NOTE: placeholder name (0x457be0)
	void addEffect(ItemEffect *effect);	// NOTE: placeholder name (0x4585a0)
	void unknown4585c0(int type);		// NOTE: placeholder name (removes an effect)
};

struct EntityEffect;	// NOTE: opaque here (0x45ac40 result)

class EntityAI
{
public:
	int unknown9b4350();				// NOTE: placeholder name (ICF'd trivial getter of +0x08)
	void willDie(bool flag);			// 0x5b5b60
	void unknown5bb750(int a, int cause, bool unseen);	// NOTE: placeholder name
};

struct OpS1c_Data;	// NOTE: opaque here

class OpS1c_RecList	// NOTE: placeholder name
{
public:
	vector<OpS1c_Data *>	records;	// +0x00
	int						turn;		// +0x10

	OpS1c_RecList(vector<OpS1c_Data *> list);	// 0x456280
	~OpS1c_RecList();							// 0x4563c0 (scalar deleting dtor 0x458720)
};

struct DeathSource	// NOTE: placeholder name; type of the 6th argument (only +0x9c is read)
{
	vector<OpS1c_Data *>	unknown9c;	// +0x9c, NOTE: placeholder name
};

struct TurnRecord;	// NOTE: opaque here
bool turnUpdate_51da30(vector<TurnRecord *> *records, int type, HEntity entity, HEntity other, HEntity unused, int unknown1, int unknown2);	// 0x51da30

struct DamageSource	// NOTE: placeholder name; elements of Entity+0xf4 / +0x104
{
	HEntity	source;		// +0x00
	int		amount;		// +0x04, NOTE: placeholder name
};

struct EntityData	// NOTE: placeholder name (robot definition)
{
	int		ID;				// +0x00
	string	name;			// +0x04
	int		aiType;			// +0x24
	int		faction;		// +0x28
	int		classID;		// +0x48, NOTE: placeholder name
	string	altName;		// +0x4c, NOTE: placeholder name
	int		unknown68;		// +0x68
	int		unknown70;		// +0x70
	bool	unknown74;		// +0x74
	int		size;			// +0x98, NOTE: placeholder name (0-4: small/medium/large)
	int		unknownBC;		// +0xbc
	int		unknown110;		// +0x110
	int		unknown120;		// +0x120
	int		unknown158;		// +0x158

	int unknown5c3120();	// NOTE: placeholder name
};

class Entity
{
public:
	HEntity					self;				// +0x04
	EntityData				*data;				// +0x08
	string					label;				// +0x0c, NOTE: placeholder name
	HGroup					group;				// +0x28
	vector<Point>			footprint;			// +0x30
	int						unknown70;			// +0x70
	int						unknown8c;			// +0x8c
	int						unknownC4;			// +0xc4
	Inventory				*inventory;			// +0xec
	vector<DamageSource *>	corruptionSources;	// +0xf4, NOTE: placeholder name
	vector<DamageSource *>	meltdownSources;	// +0x104, NOTE: placeholder name
	HEntity					lastAttacker;		// +0x114, NOTE: placeholder name
	int						unknown120;			// +0x120
	vector<HItem>			items;				// +0x134
	EntityAI				*ai;				// +0x144

	void die(bool unseen, int damageType, HEntity killer, int cause, int critType, DeathSource *source, vector<TurnRecord *> *records, bool quiet);	// 0x633790

	bool isPlayer();						// 0x5c7600
	bool unknown45aaa0(HEntity e);			// NOTE: placeholder name
	int getFaction();						// 0x45a2c0
	int getAiType();						// 0x45a2a0
	const string &getName();				// 0x45a280
	const string &getLabel();				// NOTE: placeholder name (0x416f40, returns this+0x0c)
	EntityData *unknown9b4350();			// NOTE: placeholder name (ICF'd trivial getter of +0x08)
	int unknown490840();					// NOTE: placeholder name (ICF'd trivial getter of +0x8c)
	bool isHostileTo(HEntity e);			// 0x45aa70
	Inventory *getInventory();				// 0x45ad90
	vector<HItem> *getInventoryList();		// 0x45ab00
	bool unknown631a20(HEntity killer, bool flag);	// NOTE: placeholder name
	EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	int unknown45acb0(int type);			// NOTE: placeholder name
	const Point &getPosition();				// 0x45a4a0
	Point unknown45a4c0();					// NOTE: placeholder name
	int getTarget();						// NOTE: placeholder name (0x45a760, returns +0x70)
	string unknown45a410();					// NOTE: placeholder name
	int unknown5c7fc0(HEntity other);		// NOTE: placeholder name
	bool unknown5d26e0(int type);			// NOTE: placeholder name
	int takeDamage(int a, int b, int c, int d, int e, int f, int g, bool h, HProp i, int j, int k, int l, int m, int n);	// 0x5e5520
	HItem unknown5d2380(int type);			// NOTE: placeholder name
	unsigned int unknown5d2430(int type, vector<HItem> *out);	// NOTE: placeholder name
	bool unknown5c8020();					// NOTE: placeholder name
	bool unknown5cb680(HGroup g);			// NOTE: placeholder name
};

class Cell
{
public:
	void clearEntity();						// NOTE: placeholder name (0x66baf0)
};

class Obj515ca0	// NOTE: placeholder name; 0x40 bytes in the exe, layout not reconstructed
{
public:
	Obj515ca0(HEntity a, int id, const Point &pos, HEntity b, const Point &c, const Point &d);	// 0x515ca0
};

class Map	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	HEntity getPlayer();					// NOTE: placeholder name (0x4630f0)
	HEntity getEntity671();					// NOTE: placeholder name (0x463110)
	int getTurn();							// 0x464270
	bool unknown714a50();					// NOTE: placeholder name
	vector<HEntity> &unknown4640a0();		// NOTE: placeholder name
	void unknown465910(HEntity e);			// NOTE: placeholder name
	bool findPropSpotNear(const Point &p, Point &out, void *propData);	// NOTE: placeholder name (0x71c3c0)
	bool unknown6c6b90(const Point &p, const string &type, int a, int b);	// NOTE: placeholder name
	bool unknown463dc0(HEntity e);			// NOTE: placeholder name
	string unknown463060(const Point &p);	// NOTE: placeholder name
	void unknown730f40(HEntity e);			// NOTE: placeholder name
	void unknown74b060(const Point &p, int type, int percent);	// NOTE: placeholder name
	void opw3_unknown727150(const Point &center, int count, int radius, int value);	// NOTE: placeholder name
	int pickRecordBelow71cbf0(int limit);	// NOTE: placeholder name
	HRecord addRecord(HRecord h);			// NOTE: placeholder name (0x777a20)
	unsigned int unknown4636d0();			// NOTE: placeholder name
	int &unknown463a50(unsigned int i);		// NOTE: placeholder name
	void unknown4653b0();					// NOTE: placeholder name
	void unknown749630();					// NOTE: placeholder name
	void opw3_unknown72f350();				// NOTE: placeholder name
	bool unknown4631f0(HEntity e);			// NOTE: placeholder name
	void opw3_unknown72f670();				// NOTE: placeholder name
	void opw3_unknown72f460();				// NOTE: placeholder name
	void opw3_unknown72f4e0(HEntity e);		// NOTE: placeholder name
	HEntity unknown464140();				// NOTE: placeholder name
	void opw3_unknown72f3f0();				// NOTE: placeholder name
	bool unknown464180();					// NOTE: placeholder name
	bool &unknown464100();					// NOTE: placeholder name
	void opw3_unknown72f570();				// NOTE: placeholder name
	bool unknown715a70();					// NOTE: placeholder name
	void unknown71ba40(HEntity e);			// NOTE: placeholder name
	void unknown464800(HEntity e);			// NOTE: placeholder name
	void opw3_unknown729470(HEntity e, bool ownerOnly);	// NOTE: placeholder name
};

class EffectInstance	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class EffectMgr	// NOTE: placeholder name
{
public:
	EffectInstance *create();				// NOTE: placeholder name (0x508610)
};

class GM	// NOTE: placeholder name (0xcefaa8)
{
public:
	bool showOnce(int id, bool enabled, const string *text, bool repeat, bool flag);	// NOTE: placeholder name (0x793450)
	HRecord createA(Obj515ca0 *record);		// NOTE: placeholder name (0x7930e0)
};

class PlayerData	// NOTE: placeholder name (0xcf45d8)
{
public:
	bool isSlotEmpty(unsigned int index);	// NOTE: placeholder name (0x46de40); true while achievement <index> is not earned
	void unknown77fbc0(int id);				// NOTE: placeholder name; earns achievement <id>
};

struct StatSet	// NOTE: placeholder name (OpR1h_StatSet)
{
	vector<int>	values;	// +0x00, NOTE: placeholder name
};

class OpR1h_Stats	// NOTE: placeholder name (0xd2c658)
{
public:
	StatSet		*current;	// +0x00

	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
	void add472b90(unsigned int id, int value);	// NOTE: placeholder name (0x472b90)
	int unknown472c90(int id);				// NOTE: placeholder name
	int unknown472c70(int id);				// NOTE: placeholder name (0x472c70, current->get472440(id))
};

struct LogMsg	// NOTE: placeholder name
{
	void	*source;	// +0x00
	string	text;		// +0x04
	int		unknown20;	// +0x20
	int		turn;		// +0x24, NOTE: placeholder name
};

class MessageLog	// NOTE: placeholder name (0xcf1080)
{
public:
	vector<LogMsg *> &getMessages();		// NOTE: placeholder name (0x9c0790, ICF'd: returns this)
	void unknown451400(int value);			// NOTE: placeholder name (ICF'd setter of +0x34)
};

class ConsoleA	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);			// NOTE: placeholder name
};

class CLogMsgs
{
public:
	void scrollToEnd();						// 0x7b4f10
};

class CPart
{
public:
	void unknown4a9120();					// NOTE: placeholder name (Calls_4a9120::delegate)
};

class CParts
{
public:
	CPart *unknown894e70(HItem item);		// NOTE: placeholder name
};

class CAllies
{
public:
	bool unknown48f040(HEntity e);			// NOTE: placeholder name
	void unknown7b7980();					// NOTE: placeholder name
};

class Audio	// NOTE: placeholder name (0xd25450)
{
public:
	bool	enabled;		// +0x00
	int		unknown14;		// +0x14
	int		unknown78;		// +0x78
	int		unknown7c;		// +0x7c
	int		unknown88;		// +0x88
	int		unknown8c;		// +0x8c

	void unknown69e700(int id, int a, float b);	// NOTE: placeholder name
	bool unknown69e9b0(const Point &p);		// NOTE: placeholder name
};

class Overmind	// NOTE: placeholder name (0xcf6428)
{
public:
	int		unknown00;		// +0x00
	int		unknown44;		// +0x44
	int		unknown90;		// +0x90

	void unknown68fc40();					// NOTE: placeholder name
	void unknown681b70(HEntity e, HEntity killer);	// NOTE: placeholder name
	void unknown68d980(int a, int b, int c);	// NOTE: placeholder name
};

class Tally	// NOTE: placeholder name (0xcf6888)
{
public:
	void unknown6998a0(unsigned int index, int amount, bool set);	// NOTE: placeholder name
	void unknown69a0a0(bool flag);			// NOTE: placeholder name
	void unknown69a5b0(bool flag);			// NOTE: placeholder name
};

class Plan	// NOTE: placeholder name (pointer at 0xcf68f0)
{
public:
	bool unknown672dd0(HEntity e, int type);	// NOTE: placeholder name
	void unknown672f20(HEntity e, int a, int b, string text);	// NOTE: placeholder name
};

class EntityLists	// NOTE: placeholder name (pointer at 0xcefc14)
{
public:
	void unknown7ac1c0(HEntity e, int a, int b, string text);	// NOTE: placeholder name
	bool take48bfd0(HEntity entity);		// NOTE: placeholder name
};

class RolledValues	// NOTE: placeholder name (OpW5_RolledValues, pointer at 0xcefb48)
{
public:
	bool say(int ID, bool force, string name);	// 0x49e250
};

class GameData	// NOTE: placeholder name (0xd1e860)
{
public:
	unsigned int unknown46f530();			// NOTE: placeholder name (size of the +0x2c vector minus one)
	bool unknown46f4b0(int index);			// NOTE: placeholder name
};

class Obj_d2c76c	// NOTE: placeholder name
{
public:
	void unknown483d30(HEntity e, int a);	// NOTE: placeholder name
};

class EntityPool	// NOTE: placeholder name (0xd21720)
{
public:
	void unknown9d0b30(HEntity e, bool flag);	// NOTE: placeholder name (OpS8a_Pool::remove)
};

class Obj45ef50	// NOTE: placeholder name (object behind the pointer at 0xcf68bc)
{
public:
	~Obj45ef50();							// 0x45ef50 (scalar deleting dtor 0x45f860)
};

class Pair45f0a0	// NOTE: placeholder name (two ints at 0xcf68c0)
{
public:
	void unknown45f0a0();					// NOTE: placeholder name (zeroes both)
};

struct Obj_cf4700	// NOTE: placeholder name
{
	int		unknown2c;		// +0x2c
};

bool unknown5111e0(int id, const string *text1, const string *text2, int value, HEntity subject, HEntity object, const Point *pos, int extra);	// NOTE: placeholder name (show message)
void unknown5141b0(int id, const string *a, const string *b, int c, HEntity e, int d);	// NOTE: placeholder name (history/log record)
void opR1d_4541b0(int sound, int a, int b);	// NOTE: placeholder name (play sound)
void unknown7c0c40();						// NOTE: placeholder name
void logError(string location, string message);	// 0x404f10
string intToString(int value);				// 0x4051f0
bool OpU8a_containsEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d31e0)
bool OpU8a_removeEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d2f00)
bool OpU8a_lookup2(const string &name, int *id);	// NOTE: placeholder name (0x9d7980)
bool OpS1c_unknown4569a0(int id, HEntity a, HEntity b, HProp c, HProp d, int e, int f, void *inventory, HEntity g, HProp h, HProp i, int j);	// NOTE: placeholder name (0x4569a0)
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name
bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (low <= value <= high)
int opr1c_getThresholdIndex(int value);		// NOTE: placeholder name (0x433260)

extern RNG					rng;					// 0xd30908
extern Map					*world;					// 0xcefc4c
extern EffectMgr			*effectMgr;				// 0xcefc50
extern Point				effectOrigin;			// 0xd2e20c
extern Array2D<Cell *>		cells;					// 0xcfd44c
extern GM					*gm;					// 0xcefaa8
extern PlayerData			playerData;				// 0xcf45d8
extern OpR1h_Stats			stats;					// 0xd2c658
extern MessageLog			messageLog;				// 0xcf1080
extern ConsoleA				*consoleA;				// 0xcec058
extern CLogMsgs				*logMsgs;				// 0xcec0b4
extern CLogMsgs				*combatLog;				// 0xcec0c4, NOTE: placeholder name
extern CParts				*cparts;				// 0xcec088
extern CAllies				*allies;				// 0xcec0c8
extern Audio				audio;					// 0xd25450
extern Overmind			overmind;				// 0xcf6428
extern Tally				tally;					// 0xcf6888
extern Plan					*plan;					// 0xcf68f0
extern EntityLists			*entityLists;			// 0xcefc14
extern RolledValues			*rolledValues;			// 0xcefb48
extern GameData				gameData;				// 0xd1e860
extern HLocation			location;				// 0xd1e888
extern Obj_d2c76c			obj_d2c76c;				// 0xd2c76c
extern EntityPool			entityPool;				// 0xd21720
extern vector<int>			effectTypes;			// 0xd2f0f8
extern vector<int>			spawnTypes;				// 0xcfd2cc, NOTE: placeholder name
extern vector<HEntity>		unknownCf6adc;
extern vector<string>		uniqueKills;			// 0xcf4bc0, NOTE: placeholder name
extern vector<unsigned int>	uniqueKillLocations;	// 0xcf4bd0, NOTE: placeholder name (gameData.unknown46f530() per unique kill)
extern vector<int>			unknownCf68cc;
extern string				unknownD1f3d4;
extern string				damageTypeNames[];		// 0xd323f8, NOTE: placeholder name
extern string				classNames[];			// 0xd2b4f8, NOTE: placeholder name
extern string				deathQuotes[];			// 0xd30360, NOTE: placeholder name
extern string				deathQuotesAlt[];		// 0xcfb690, NOTE: placeholder name
extern bool					factionTableB951c0[];
extern bool					classTableB95758[];
extern int					tierScores[];			// 0xba5e24, NOTE: placeholder name
extern int					unknownB949c8[];
extern int					unknownB949d8[];
extern float				thresholdMults[];		// 0xb91b8c, NOTE: placeholder name
extern int					gameMode;				// 0xcf462c, NOTE: placeholder name
extern int					unknownCf4b38;
extern bool					unknownCf468c;
extern Obj_cf4700			*unknownCf4700;
extern int					unknownCf4724;
extern int					unknownCf472c;
extern int					unknownCf4730;
extern int					unknownCf4740;
extern int					unknownCf4b5c;			// kill streak
extern int					unknownCf4b60;
extern int					unknownCf4b64;
extern int					unknownCf4b68;			// turn of the last kill
extern int					unknownCf4b6c;
extern int					unknownCf4b88;
extern int					unknownCf4b8c;
extern int					unknownCf4b90;
extern int					unknownCf4b94;
extern int					unknownCf4d64;
extern int					unknownCf4d70;
extern Point				unknownCf4d74;
extern int					unknownCf4d7c;
extern int					unknownCf4d84;
extern void					*unknownCf68b4;
extern HEntity				unknownCf68b8;
extern Obj45ef50			*unknownCf68bc;
extern Pair45f0a0			unknownCf68c0;
extern HEntity				unknownCf6984;
extern HEntity				unknownCf69a8;
extern bool					unknownCf6a24;
extern int					unknownCaf164;
extern HEntity				unknownD1d9f0;
extern bool					unknownD1da48;
extern int					unknownD1ec60;
extern int					unknownD28d18;
extern int					unknownD29730;

// message to the main log (0xcec0b4)
#define MESSAGE(id,text1,text2,value,subject,object,pos,extra) \
	do \
	{ \
		if (unknown5111e0(id,text1,text2,value,subject,object,pos,extra)) \
			consoleA->unknown8758d0(true); \
		logMsgs->scrollToEnd(); \
	} while (0)
// message to the combat log (0xcec0c4)
#define COMBAT_MESSAGE(id,text1,text2,value,subject,object,pos,extra) \
	do \
	{ \
		if (unknown5111e0(id,text1,text2,value,subject,object,pos,extra)) \
			consoleA->unknown8758d0(false); \
		combatLog->scrollToEnd(); \
	} while (0)
// announcement: flags the message log, optional sound, message, extra scroll
#define ANNOUNCE(id,text,sound) \
	do \
	{ \
		messageLog.unknown451400(1); \
		if (sound >= 0) \
			opR1d_4541b0(sound,0,0); \
		MESSAGE(id,text,NULL,0,HEntity(),HEntity(),NULL,0); \
		logMsgs->scrollToEnd(); \
	} while (0)
#define HISTORY(id,a,b,c,e,d) \
	do \
	{ \
		unknown5141b0(id,a,b,c,e,d); \
	} while (0)

//==================================================================
// Entity::die
//==================================================================

void Entity::die(bool unseen, int damageType, HEntity killer, int cause, int critType, DeathSource *source, vector<TurnRecord *> *records, bool quiet)
{
	unknown8c = 0;

	// the player (or the entity standing in for it in game mode 7)
	if (isPlayer() || (gameMode == 7 && self == world->getEntity671()))
	{
		if (unknownCf4b38 == 0x1c)
			unknownCf4b38 = 0xf;
		playerData.unknown77fbc0(0xf3);
		obj_d2c76c.unknown483d30(self,0);
		if (audio.enabled)
		{
			string text;
			if (audio.unknown14 == 0)
				text = "X0-1V1: \"" + deathQuotes[rng.rangeInt(0,6)] + "\"";
			else
				text = "X0-1V1 " + deathQuotesAlt[rng.rangeInt(0,8)];
			MESSAGE(0x2b6,&text,NULL,0,HEntity(),HEntity(),NULL,0);
		}
		unknown7c0c40();
		return;
	}

	if (self.operator->() == NULL)
	{
		logError("Entity::die()","handle already invalid, hm");
		return;
	}

	if ((playerData.isSlotEmpty(0x7b) || audio.enabled) && killer.operator->() != NULL && killer->isPlayer() && killer->unknown45aaa0(self) && unknownD1da48)
	{
		playerData.unknown77fbc0(0x7b);
		if (audio.enabled && world->unknown714a50())
			audio.unknown69e700(0x20,data->unknown120 >= 3,0.0f);
	}

	if (ai != NULL)
		ai->willDie(false);

	// corruption/meltdown without a killer: credit the largest contributor
	if (killer.isNull() && (cause == 2 || cause == 3))
	{
		vector<DamageSource *> &sources = (cause == 2) ? corruptionSources : meltdownSources;
		DamageSource *best = NULL;
		for (unsigned int i = 0; i < sources.size(); i++)
		{
			if (best == NULL || sources[i]->amount > best->amount)
				best = sources[i];
		}
		if (best != NULL && best->source.operator->() != NULL)
			killer = best->source;

		if (cause == 2 && OpU8a_containsEntity(world->unknown4640a0(),self))
		{
			stats.add4729d0(0x264,1,string(""),-1);
			playerData.unknown77fbc0(0x3a);
		}

		if (killer == world->getPlayer())
		{
			switch (cause)
			{
				case 2:
					stats.add4729d0(0x1fe,1,string(""),-1);
					playerData.unknown77fbc0(0x29);
					if (factionTableB951c0[data->faction] && killer->isHostileTo(self))
					{
						stats.add4729d0(0x1ff,1,string(""),-1);
						if (stats.current->values[0x1ff] == 50)
							playerData.unknown77fbc0(0x94);
					}
					break;
				case 3:
					stats.add4729d0(0x202,1,string(""),-1);
					playerData.unknown77fbc0(0x2a);
					if (factionTableB951c0[data->faction] && killer->isHostileTo(self))
					{
						stats.add4729d0(0x203,1,string(""),-1);
						if (stats.current->values[0x203] == 20)
							playerData.unknown77fbc0(0x95);
					}
					break;
			}
		}
	}

	bool killerFromLastAttacker = false;
	if (killer.operator->() == NULL && lastAttacker.isValid() && lastAttacker.operator->() != NULL)
	{
		killer = lastAttacker;
		killerFromLastAttacker = true;
	}

	if (getFaction() == 6 && ai != NULL && ai->unknown9b4350() == 6)
		ai->unknown5bb750(1,cause,unseen);

	if (getFaction() == 0x1b && isHostileTo(world->getPlayer()) && group->unknown9b4350() != 0xc && overmind.unknown90 != 0)
		overmind.unknown68fc40();

	if (gameMode == 6 && killer.operator->() != NULL)
		world->unknown465910(killer);

	overmind.unknown681b70(self,killer);

	if (killer.operator->() != NULL)
	{
		unknownD1f3d4 = damageTypeNames[damageType];
		OpS1c_unknown4569a0(0x1e,killer,HEntity(),HProp(),HProp(),0,0,killer->getInventory(),killer,HProp(),HProp(),0);
		if (killer.operator->() != NULL)
			OpS1c_unknown4569a0(0x1f,killer,HEntity(),HProp(),HProp(),0,0,killer->getInventory(),self,HProp(),HProp(),0);
	}

	int partCount = items.size();
	bool unknownFlag = unknown631a20(killer,true);	// NOTE: placeholder name

	if (unknown45ac40(0x7b) != NULL && rng.chance(unknown45acb0(0x7b)))
	{
		Point spot = getPosition();
		if (world->findPropSpotNear(spot,spot,NULL))
			world->unknown6c6b90(spot,"Master_Drone_Spawn",0,-1);
	}

	if (unknownFlag && killer == world->getPlayer())
		gm->showOnce(0x42,true,NULL,false,false);

	if (unknown70 == 0)
	{
		HEntity check = self;
		OpS1c_unknown4569a0(2,self,HEntity(),HProp(),HProp(),0,0,inventory,self,HProp(),HProp(),0);
		if (check.operator->() == NULL)
			return;

		if (records != NULL)
		{
			bool removed = false;	// NOTE: never set in the exe
			if (cause == 7)
			{
				turnUpdate_51da30(records,0x20,self,HEntity(),HEntity(),0,0);
				if (check.operator->() != NULL && killer.operator->() != NULL)
					turnUpdate_51da30(records,0x21,killer,HEntity(),HEntity(),0,0);
				if (removed && check.operator->() == NULL)
					return;
			}
			else if (cause == 8 || cause == 9)
			{
				turnUpdate_51da30(records,0x22,self,HEntity(),HEntity(),0,0);
				if (check.operator->() != NULL && killer.operator->() != NULL)
					turnUpdate_51da30(records,0x23,killer,HEntity(),HEntity(),0,0);
				if (check.operator->() == NULL)
					return;
			}
		}
		else if (cause == 10 && source != NULL && !source->unknown9c.empty())
		{
			OpS1c_RecList *list = new OpS1c_RecList(source->unknown9c);
			bool handled = OpS1c_unknown4569a0(0x24,killer,self,HProp(),HProp(),0,0,list,self,HProp(),HProp(),0);
			delete list;
			if (handled && check.operator->() == NULL)
				return;
		}
	}

	if (unknownCf68b4 != NULL && self.operator->() != NULL && unknownCf68b8 == self)
		plan->unknown672f20(self,4,0,string(""));

	if (entityLists != NULL && killer.operator->() != NULL && self != killer && entityLists != NULL)
		entityLists->unknown7ac1c0(self,0xc,0,killer->getLabel());

	if (cause != 2 && cause != 3)
	{
		if (!quiet)
			MESSAGE(unknown45aaa0(world->getPlayer()) ? 0x17 : 0x18,NULL,NULL,0,self,HEntity(),NULL,0);

		switch (data->faction)
		{
			case 0xc:
				if (playerData.isSlotEmpty(0x32) && killer.operator->() != NULL && killer->isPlayer() && isHostileTo(killer) && getTarget() == 0
					&& messageLog.getMessages().size() > 2
					&& messageLog.getMessages()[messageLog.getMessages().size() - 2]->turn == world->getTurn()
					&& messageLog.getMessages()[messageLog.getMessages().size() - 2]->text.find("Sneak attack",0) != string::npos)
					playerData.unknown77fbc0(0x32);
				break;
			case 0xf:
				if (playerData.isSlotEmpty(0x39) && killer.operator->() != NULL && killer->isPlayer() && isHostileTo(killer) && getTarget() == 0 && !killerFromLastAttacker)
					playerData.unknown77fbc0(0x39);
				break;
		}
	}

	// combat log line
	if (unknownD28d18 >= 0)
	{
		string text = "   " + unknown45a410();
		switch (cause)
		{
			case 2:
				text += " system corrupted";
				break;
			case 3:
				text += " melted";
				break;
			default:
				text += " destroyed";
				switch (critType)
				{
					case 3:
						text += " (Crit: Destroy)";
						break;
					case 6:
						text += " (Crit: Smash)";
						break;
				}
				break;
		}
		COMBAT_MESSAGE(isPlayer() ? 0x2c9 : 0x2ca + (unknown5c7fc0(world->getPlayer()) != 2),&text,NULL,0,self,HEntity(),NULL,1);
	}

	if (unknown120 == 1 && data->faction == 0x18 && isHostileTo(world->getPlayer()))
		playerData.unknown77fbc0(0x2f);

	if (rolledValues != NULL && killer.operator->() != NULL && killer == world->getEntity671() && killer->isHostileTo(self) && rolledValues != NULL)
		rolledValues->say(0x25,false,getLabel());

	if (killer.operator->() != NULL && unknownCf68b4 != NULL && killer.operator->() != NULL && unknownCf68b8 == killer && plan->unknown672dd0(killer,2) && killer->isHostileTo(self))
		plan->unknown672f20(killer,2,1,self->getLabel());

	if (entityLists != NULL)
	{
		if (killer.operator->() != NULL && self != killer && entityLists != NULL)
			entityLists->unknown7ac1c0(killer,0xd,0,getLabel());
		entityLists->take48bfd0(self);
	}

	if (unknown45ac40(0x39) != NULL)
	{
		if (group->unknown9b4350() == 0 && world->getPlayer()->unknown5d26e0(0xc7))
		{
			int damage = data->unknown68 * 2;
			if (world->getPlayer()->unknown490840() > damage)
			{
				world->getPlayer()->takeDamage(0,0,0,damage,7,0,0,0,HProp(),1,8,0,0,1);
				do
				{
					bool shown;	// the text is a temporary in the exe: destroyed before the result is tested
					{
						string damageText = intToString(damage);
						shown = unknown5111e0(0xca,&damageText,NULL,0,self,HEntity(),NULL,0);
					}
					if (shown)
						consoleA->unknown8758d0(true);
					logMsgs->scrollToEnd();
				} while (0);
			}
			else
			{
				HItem found;
				vector<HItem> *list = world->getPlayer()->getInventoryList();
				for (unsigned int i = 0; i < list->size(); i++)
				{
					if ((*list)[i]->unknown457f90() == 0xc7 && (*list)[i]->unknown44aec0() < 4)
					{
						found = (*list)[i];
						break;
					}
				}
				if (found.isValid())
				{
					do
					{
						bool shown;
						{
							string itemName = found->getName(0,0);
							shown = unknown5111e0(0xcb,&itemName,NULL,0,self,HEntity(),NULL,0);
						}
						if (shown)
							consoleA->unknown8758d0(true);
						logMsgs->scrollToEnd();
					} while (0);
					found->unknown57dbe0(1,1,1,1);
				}
			}
		}
		if (!world->unknown463dc0(self))
			OpU8a_removeEntity(unknownCf6adc,self);
	}

	HEntity check = self;
	OpS1c_unknown4569a0(3,self,HEntity(),HProp(),HProp(),0,0,inventory,self,HProp(),HProp(),0);
	if (check.operator->() == NULL)
		return;

	if (data->faction == 0x44)
	{
		string text = "ANNOUNCEMENT: Tunneling progress halted along " + world->unknown463060(getPosition()) + " route. " + getLabel() + " no longer operational.";
		ANNOUNCE(0x324,&text,-1);
		HISTORY(0x1c9,NULL,NULL,0,HEntity(),0);
	}

	world->unknown730f40(self);
	for (unsigned int i = 0; i < footprint.size(); i++)
	{
		world->unknown74b060(footprint[i],4,100);
		cells(footprint[i])->clearEntity();
	}

	// destruction effects
	if (unseen)
	{
		int count = 0;
		int radius = 0;
		switch (data->size)
		{
			case 0:
			case 1:
				count = 5;
				radius = 5;
				break;
			case 2:
				count = 10;
				radius = 6;
				break;
			case 3:
			case 4:
				count = 15;
				radius = 7;
				break;
		}
		world->opw3_unknown727150(unknown45a4c0(),count,radius,unknownD29730);
	}
	else
	{
		int effectID;	// NOTE: uninitialised in the exe when size > 4
		switch (data->size)
		{
			case 0:
			case 1:
				OpU8a_lookup2(cause == 3 ? "Robot_Destroyed_Sml_Meltdown" : "Robot_Destroyed_Sml",&effectID);
				break;
			case 2:
				OpU8a_lookup2(cause == 3 ? "Robot_Destroyed_Med_Meltdown" : "Robot_Destroyed_Med",&effectID);
				break;
			case 3:
			case 4:
				OpU8a_lookup2(cause == 3 ? "Robot_Destroyed_Lrg_Meltdown" : "Robot_Destroyed_Lrg",&effectID);
				break;
		}
		if (effectID != 0)
			effectMgr->create()->init(effectMgr,effectID,unknown45a4c0(),effectOrigin,NULL,NULL,NULL,9,0);

		switch (cause)
		{
			case 2:
			{
				int corruptionID;
				OpU8a_lookup2("Robot_Corruption",&corruptionID);
				for (unsigned int i = 0; i < footprint.size(); i++)
					effectMgr->create()->init(effectMgr,corruptionID,footprint[i],effectOrigin,NULL,NULL,NULL,9,0);
				break;
			}
			case 3:
			{
				int meltdownID;
				OpU8a_lookup2("Robot_Meltdown",&meltdownID);
				for (unsigned int i = 0; i < footprint.size(); i++)
					effectMgr->create()->init(effectMgr,meltdownID,footprint[i],effectOrigin,NULL,NULL,NULL,9,0);
				break;
			}
		}
	}

	// spawn on death
	if (gameMode == 9 && data->aiType != 0)
		world->addRecord(gm->createA(new Obj515ca0(killer,spawnTypes[world->pickRecordBelow71cbf0(data->unknown68)],unknown45a4c0(),HEntity(),Point(-1),Point(-1))));
	else if (data->unknownBC != 0)
	{
		MESSAGE(unknown45aaa0(world->getPlayer()) ? 0x19 : 0x1a,NULL,NULL,0,self,HEntity(),NULL,0);
		world->addRecord(gm->createA(new Obj515ca0(self,data->unknownBC,unknown45a4c0(),HEntity(),Point(-1),Point(-1))));
	}

	// parts of the killer that learn from kills of a robot class (effects 0x72-0x74)
	if (killer.operator->() != NULL && (killer->isPlayer() || killer == world->getEntity671() || killer->getFaction() == 0x30)
		&& cause != 10 && data->aiType != 0 && killer->unknown5d2380(0x68).isValid())
	{
		vector<HItem> list;
		killer->unknown5d2430(0x68,&list);
		for (unsigned int i = 0; i < list.size(); i++)
		{
			if (list[i]->getEffect(0x72) == NULL)
				list[i]->addEffect(new ItemEffect(effectTypes[0x72],data->classID));
			else if (list[i]->getEffectValue(0x72) != data->classID)
			{
				list[i]->getEffect(0x72)->state = data->classID;
				list[i]->unknown4585c0(0x73);
			}
			else if (list[i]->getEffect(0x73) == NULL)
				list[i]->addEffect(new ItemEffect(effectTypes[0x73],1));
			else
			{
				list[i]->getEffect(0x73)->state++;
				bool learned = list[i]->getEffect(0x74) != NULL;
				if ((!learned || list[i]->getEffectValue(0x74) != data->classID) && rng.chance(list[i]->getEffectValue(0x73) * (learned ? 1 : 5)))
				{
					if (learned)
						list[i]->getEffect(0x74)->state = data->classID;
					else
						list[i]->addEffect(new ItemEffect(effectTypes[0x74],data->classID));
					do
					{
						bool shown;
						{
							string itemName = list[i]->getName(0,0);
							shown = unknown5111e0(0xc4,&itemName,&classNames[list[i]->getEffectValue(0x74)],0,killer,HEntity(),NULL,0);
						}
						if (shown)
							consoleA->unknown8758d0(true);
						logMsgs->scrollToEnd();
					} while (0);
					if (killer->isPlayer())
					{
						do
						{
							string itemName = list[i]->getName(0,0);
							unknown5141b0(0x61,&itemName,&classNames[list[i]->getEffectValue(0x74)],0,killer,0);
						} while (0);
						cparts->unknown894e70(list[i])->unknown4a9120();
						opR1d_4541b0(0x56,0,0);
					}
					if (killer == world->getEntity671() && rolledValues != NULL)
						rolledValues->say(0x46,false,classNames[list[i]->getEffectValue(0x74)]);
				}
			}
		}
	}

	if (group->unknown9b4350() == 3)
		overmind.unknown68d980(0,0,0);

	// allies of the player
	bool reported = false;
	if (unknown45aaa0(world->getPlayer()))
	{
		if (killer.operator->() != NULL && killer == world->getPlayer() && (unknownD1d9f0 == self || (world->unknown4636d0() == 0 && cause == 10)))
		{
			unknownCf4b90++;
			unknownCf4b94 = world->getTurn();
			if (data->aiType == 0)
			{
				HISTORY(0x10,&getLabel(),NULL,0,HEntity(),0);
				reported = true;
			}
		}
		else if (OpQ1_distanceCeil_40a3f0(getPosition(),world->getPlayer()->getPosition()) <= 20)
		{
			unknownCf4b88++;
			unknownCf4b8c = world->getTurn();
			if (audio.enabled && group->unknown9b4350() <= 2 && unknown45ac40(0x3a) == NULL)
			{
				audio.unknown88 += tierScores[data->unknown120];
				audio.unknown8c = world->getTurn();
			}
		}
	}

	if (audio.enabled && isHostileTo(world->getPlayer()) && audio.unknown69e9b0(getPosition()) && unknown45ac40(0x3a) == NULL)
	{
		audio.unknown78 += tierScores[data->unknown120];
		audio.unknown7c = world->getTurn();
	}

	// kill statistics and achievements
	if (killer.operator->() != NULL && unknown70 < 6)
	{
		if (killer == world->getPlayer())
		{
			if (getFaction() != 0)
			{
				if (data->unknown70 != 0)
				{
					world->unknown463a50(data->ID)++;
					if ((!data->unknown74 || world->unknown463a50(data->ID) <= 20) && (data->classID > 0x77 || stats.unknown472c90(data->classID + 0xe5) < 60))
						stats.add4729d0(2,1,string(""),-1);
				}

				if (data->classID == 0x79)
				{
					stats.add4729d0(0x164,1,data->name,-1);
					uniqueKills.push_back(data->altName.empty() ? label : data->altName);
					uniqueKillLocations.push_back(gameData.unknown46f530());
					if (!reported)
						HISTORY(0x13,data->altName.empty() ? &label : &data->altName,NULL,0,HEntity(),0);
					if (uniqueKills.size() == 15)
						playerData.unknown77fbc0(0x164);
					if (data->faction == 0x5b && location->type == 0x17)
						world->unknown4653b0();
					tally.unknown6998a0(0xc,data->unknown68,false);
				}
				else if (data->classID != 0x7a)
				{
					stats.add4729d0(0xe4,1,string(""),data->faction);
					if (stats.current->values[0xe4] == 30)
						playerData.unknown77fbc0(0x142);
					stats.add4729d0(data->classID + 0xe5,1,string(""),-1);
					if (stats.current->values[0xfe] == 5)
						playerData.unknown77fbc0(0x143);
					if (stats.current->values[0x100] == 5)
						playerData.unknown77fbc0(0x144);
					if (stats.current->values[0x104] == 10)
						playerData.unknown77fbc0(0x145);
					if (data->aiType == 2 && ++unknownCf4d84 == 30)
						playerData.unknown77fbc0(0x146);
					if (gameMode == 4 && stats.current->values[0x15b] >= 50 && !unknownCf468c && rng.chance(33) && location->type != 5)
						world->unknown749630();
					if (classTableB95758[data->classID] && (data->faction != 0x3d || partCount >= 8))
						HISTORY(0x11,&getLabel(),NULL,0,HEntity(),0);
				}

				world->opw3_unknown72f350();

				if (group->unknown9b4350() == 4 || killer->isHostileTo(self))
				{
					if (world->getTurn() > unknownCf4b68 + 20)
						unknownCf4b5c = 1;
					else
						unknownCf4b5c++;
					unknownCf4b68 = world->getTurn();
					stats.add4729d0(0x15e,unknownCf4b5c,string(""),-1);

					if ((!data->unknown74 || world->unknown463a50(data->ID) <= 20) && (data->classID > 0x77 || stats.unknown472c90(data->classID + 0xe5) <= 60))
						stats.add4729d0(3,data->unknown70,string(""),-1);

					switch (data->faction)
					{
						case 4:
							stats.add4729d0(0xd6,1,string(""),-1);
							break;
						case 6:
							if (world->unknown4631f0(self))
								playerData.unknown77fbc0(0x11d);
							break;
					}

					if (location->type == 0x14)
						world->opw3_unknown72f670();

					if (factionTableB951c0[data->faction])
					{
						stats.add4729d0(0xdf,1,string(""),-1);
						if (stats.current->values[0xdf] >= 100 && (playerData.isSlotEmpty(0x90) || playerData.isSlotEmpty(0x91) || playerData.isSlotEmpty(0x92) || playerData.isSlotEmpty(0x93)))
						{
							int total = stats.current->values[0x1b2] + stats.current->values[0x1b3] + stats.current->values[0x1b4] + stats.current->values[0x1b5] + stats.current->values[0x1b6];
							if (total != 0)
							{
								if (stats.current->values[0x1b2] * 100 / total >= 90)
									playerData.unknown77fbc0(0x90);
								if (stats.current->values[0x1b3] * 100 / total >= 90)
									playerData.unknown77fbc0(0x91);
								if (stats.current->values[0x1b4] * 100 / total >= 90)
									playerData.unknown77fbc0(0x92);
								if (stats.current->values[0x1b5] * 100 / total >= 90)
									playerData.unknown77fbc0(0x93);
							}
						}

						if (OpT8b_Fn9daf80(7,cause,10))
						{
							stats.add4729d0(cause + 0xd9,1,string(""),-1);
							if (cause == 7 && stats.current->values[0xe0] == 200)
								playerData.unknown77fbc0(0x13b);
						}

						unknownCf4b60++;
						unknownCf4b64 += data->unknown5c3120();
						unknownCf4b6c = world->getTurn();
						stats.add4729d0(0x15f,unknownCf4b60,string(""),-1);
						if (stats.current->values[0x15f] == 20)
							playerData.unknown77fbc0(0x11b);
						else if (stats.current->values[0x15f] == 35)
							playerData.unknown77fbc0(0x137);

						if (playerData.isSlotEmpty(0x11c) && location->type == 3)
						{
							if (killer->getPosition() == unknownCf4d74)
							{
								if (++unknownCf4d7c == 30)
									playerData.unknown77fbc0(0x11c);
							}
							else
							{
								unknownCf4d7c = 1;
								unknownCf4d74 = killer->getPosition();
							}
						}

						int threshold = opr1c_getThresholdIndex(overmind.unknown00);
						if (unknownCf4724 != 0)
							stats.add472b90(9,(int)(data->unknown70 * 0.33f));
						if (unknownCf472c != 0)
							stats.add472b90(0xb,(int)(data->unknown70 * 1.0f));
						if (unknownCf4730 != 0)
							stats.add472b90(0xc,(int)(data->unknown70 * 0.33f));
						if (unknownCf4740 != 0)
							stats.add472b90(0x10,(int)(data->unknown70 * 0.5f));
						if (threshold != 0 && thresholdMults[threshold] != 0.0f && gameData.unknown46f4b0(1) && location->type != 0x23
							&& (data->classID > 0x77 || stats.unknown472c90(data->classID + 0xe5) <= 60))
							stats.add472b90(0x17,(int)(data->unknown70 * thresholdMults[threshold]));
						if (location->type == 0x17 && stats.unknown472c70(0x36) != 0 && group->unknown9b4350() == 3)
							stats.add472b90(0x37,(int)(data->unknown70 * 2.0f));

						if (unknownCf4700 != NULL)
							unknownCf4700->unknown2c++;

						switch (cause)
						{
							case 7:
								world->opw3_unknown72f460();
								break;
							case 8:
								world->opw3_unknown72f4e0(self);
								// fall through
							case 9:
								if (world->unknown464140() == self)
									playerData.unknown77fbc0(0xb0);
								break;
							case 10:
								world->opw3_unknown72f3f0();
								if (world->unknown464180())
									playerData.unknown77fbc0(0xb1);
								break;
						}
						world->unknown464100() = false;

						if (data->faction == 0x15 && damageType == 2)
							playerData.unknown77fbc0(0x27);
						if (stats.unknown472c70(0x113) == 5)
							playerData.unknown77fbc0(0x132);
						if (data->faction == 0x3c && location->type == 7)
							world->opw3_unknown72f570();
						if (data->faction == 0x25 && location->type == 0xf && unknownCf4d70 != -1)
						{
							if (world->unknown715a70())
								unknownCf4d70 = -1;
							else
								unknownCf4d70++;
						}
						if (group->unknown9b4350() == 3)
							overmind.unknown44++;
					}
				}
				else if (unknown5c8020())
				{
					stats.add472b90(0x6a,factionTableB951c0[data->faction] ? unknownB949c8[data->aiType] : unknownB949d8[data->aiType]);
					playerData.unknown77fbc0(0x19);
					if (stats.current->values[0x6a] <= -1000)
						playerData.unknown77fbc0(0xca);
				}

				if (data->faction == 4)
				{
					playerData.unknown77fbc0(0xd);
					if (stats.current->values[0xe8] == 20)
						playerData.unknown77fbc0(0xe);
				}
				if (data->unknown110 != 10)
					playerData.unknown77fbc0(0x140);
			}
		}
		else
		{
			// killed by an ally of the player
			if (killer->unknown45aaa0(world->getPlayer()))
			{
				killer->unknownC4++;
				if (killer->unknown9b4350()->unknown158 != unknownCaf164 && killer->getName() == "Wardrone" && ++unknownCf4d64 == 10)
					playerData.unknown77fbc0(0xda);
				if (killer->unknownC4 == 20 && (killer->getAiType() == 1 || killer->getAiType() == 2)
					&& killer->unknown9b4350()->faction != 10 && killer->unknown9b4350()->faction != 0xb
					&& killer->getName().find("Enhanced",0) == string::npos)
					playerData.unknown77fbc0(0x147);
			}

			if (killer->group->unknown9b4350() <= 2)
			{
				stats.add4729d0(0x3b0,1,string(""),-1);
				if (stats.current->values[0x3b0] == 75)
					playerData.unknown77fbc0(0xc9);

				if ((group->unknown9b4350() == 4 || killer->isHostileTo(self)) && factionTableB951c0[data->faction])
				{
					if (killer == world->getEntity671())
						stats.add4729d0(0x453,1,string(""),-1);
					if (OpQ1_distanceCeil_40a3f0(killer->getPosition(),world->getPlayer()->getPosition()) <= 20
						&& (data->classID > 0x77 || stats.unknown472c90(data->classID + 0xe5) <= 60))
						stats.add472b90(0x18,(int)(data->unknown70 * 0.75f));
					if (group->unknown9b4350() == 3)
						overmind.unknown44++;
				}

				if (data->classID == 0x79)
				{
					stats.add4729d0(0x164,1,data->name,-1);
					uniqueKills.push_back(data->altName.empty() ? label : data->altName);
					uniqueKillLocations.push_back(gameData.unknown46f530());
					HISTORY(0x14,data->altName.empty() ? &label : &data->altName,NULL,0,self,0);
					if (uniqueKills.size() == 15)
						playerData.unknown77fbc0(0x164);
					tally.unknown6998a0(0xc,data->unknown68,false);
				}
				else if (classTableB95758[data->classID] && (data->faction != 0x3d || partCount >= 8))
					HISTORY(0x12,&getLabel(),NULL,0,self,0);
			}
		}
	}

	if (data->faction == 0x1b && group->unknown9b4350() == 0xc && location->type == 0x22 && unknown45ac40(0x2e) != NULL)
		unknownD1ec60++;

	if (data->unknown110 != 10)
	{
		unknownCf68cc[data->unknown110] = 0;
		unknownCf68b4 = NULL;
		unknownCf68b8.clear();
		delete unknownCf68bc;	unknownCf68bc = NULL;
		unknownCf68c0.unknown45f0a0();
		if (killer.operator->() != NULL && killer->unknown45aaa0(world->getPlayer()))
			stats.add472b90(0x1c,-999999);
		switch (data->unknown110)
		{
			case 7:
				unknownCf6a24 = false;
				break;
		}
	}

	if (unknownCf6984 == self)
		tally.unknown69a0a0(true);
	else if (unknownCf69a8 == self)
		tally.unknown69a5b0(true);

	// remove from the world
	world->unknown71ba40(self);
	group->unknown6716f0(self);
	if (world->unknown4631f0(self) && world->getPlayer().operator->() != NULL && world->getPlayer()->unknown5cb680(group))
		world->unknown464800(self);
	if (allies->unknown48f040(self))
		allies->unknown7b7980();
	world->opw3_unknown729470(self,false);
	entityPool.unknown9d0b30(self,true);
}
