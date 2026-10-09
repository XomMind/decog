//==================================================================
// Entity::takeDamage (0x5e5520, 0xbaec bytes), byte-matched as YtEntity::takeDamage.
//==================================================================
// Based on Heni's semantic draft (native/giants/5e5520_Entity_takeDamage.cpp); all types/externs are private (Yt*/yt_*).
// Some local names are odd on purpose: VS2010 /Od orders stack slots by a hash of the name (frame layout).
// Callees carry their exe addresses in comments; members whose meaning is not known are unknown<offset>.
// The critical-hit macros are expanded inline (the frame-layout tools need to see their locals).

#include <string>
#include <vector>

using namespace std;

//==================================================================
// enums (names from the exe's string tables)
//==================================================================

enum damageType	// NOTE: placeholder names, from gameStrings_d29980 (0xd29980)
{
	DAMAGE_KINETIC,
	DAMAGE_THERMAL,
	DAMAGE_EXPLOSIVE,
	DAMAGE_EM,
	DAMAGE_IMPACT,
	DAMAGE_SLASHING,
	DAMAGE_PIERCING,
	DAMAGE_ENTROPIC,
	DAMAGE_PHASIC,
	DAMAGE_SPECIAL,
	DAMAGE_NA,
};

enum criticalType	// NOTE: placeholder names, from yt_gameStrings_d1e058 (0xd1e058)
{
	CRITICAL_NONE,
	CRITICAL_BURN,
	CRITICAL_MELTDOWN,
	CRITICAL_DESTROY,
	CRITICAL_BLAST,
	CRITICAL_CORRUPT,
	CRITICAL_SMASH,
	CRITICAL_SEVER,
	CRITICAL_IMPALE,
	CRITICAL_DETONATE,
	CRITICAL_SUNDER,
	CRITICAL_INTENSIFY,
	CRITICAL_PHASE,
};

//==================================================================
// declarations (only the members this function touches; 32-bit offsets in comments)
//==================================================================

class YtEntity;
class YtItem;
class YtProp;
class YtCell;
class YtEntityAI;
struct YtEntityEffect;
struct YtEffectPair;
struct YtEntityRecord;
struct YtItemRecord;
struct YtExplosionRecord;

struct YtPoint
{
	int x;	// +0x0
	int y;	// +0x4

	YtPoint();					// NOTE: no-op ctor
	YtPoint(int x_, int y_);		// 0x46ca20
	YtPoint(const YtPoint &p);		// 0x46ca50
	int randomInRange_40c130();	// NOTE: placeholder name (0x40c130): rng.rangeInt(x,y), or x when x==y
	YtPoint(int v);				// 0x409990: x = y = v
	YtPoint(const YtPoint &a, const YtPoint &b);	// 0x4099f0: a + b
	YtPoint &operator+=(const YtPoint &p);	// 0x409a30
	bool unknown409cb0(int x_, int y_);	// NOTE: placeholder name (0x409cb0): x == x_ && y == y_
	YtPoint &operator=(const YtPoint &p);	// 0x46ca50 (folded with the copy constructor)
	bool adjacent(const YtPoint &p) const;	// NOTE: placeholder name (PushGeometry::adjacent 0x409dd0)
};

class YtHEntity
{
public:
	int ID;	// +0x0

	YtHEntity();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	bool isNull() const;					// 0x9b65d0
	bool operator==(YtHEntity other) const;	// 0x9b78e0
	bool operator!=(YtHEntity other) const;	// 0x9b6510
	YtEntity *operator->() const;				// 0x9b6570
};

class YtHItem
{
public:
	int ID;	// +0x0

	YtHItem();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	bool isNull() const;					// 0x9b65d0
	bool operator==(YtHItem other) const;		// 0x9b78e0
	bool operator!=(YtHItem other) const;		// 0x9b6510
	YtItem *operator->() const;				// 0x9b65b0
};

class YtHProp
{
public:
	int ID;	// +0x0

	YtHProp();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	bool isNull() const;					// 0x9b65d0
	YtProp *operator->() const;				// 0x9b64f0
};

class YtRNG
{
public:
	bool chance(int percent);			// 0x406c90
	int rangeInt(float a, float b);		// 0x406d70
};

struct YtOpR3_StatType;	// NOTE: placeholder name (elements of yt_opr3_statTypes, 0xd2f0f8)

struct YtEntityEffect	// 8 bytes, allocated with new
{
	YtOpR3_StatType *record;	// +0x0 NOTE: placeholder name
	int value;				// +0x4 NOTE: placeholder name

	YtEntityEffect(YtOpR3_StatType *record_, int value_);	// 0x46ca20 (shared body with YtPoint(int,int))
};

struct YtEntityRecord	// YtEntity+0x8
{
	int pad0[10];
	int unknown28;	// +0x28 entity class (also read by YtEntity::getFaction 0x45a2c0)
	int pad2c[7];
	int unknown48;	// +0x48 NOTE: placeholder name (robot class, index of yt_gameStrings_d2b4f8)
	int pad4c[19];
	int unknown98;	// +0x98 NOTE: placeholder name (size/mass class used by knockback)
	int unknown9C;	// +0x9c NOTE: placeholder name (read by YtEntity::getSize 0x45a360)

	string getName459c30();	// 0x459c30 (OpR1e_Variant::getName459c30)
};

struct YtItemRecord	// YtItem+0x8; the weapon record passed as 'weapon'
{
	int pad0[9];
	string name;	// +0x24
	int pad40;
	int unknown44;	// +0x44 NOTE: placeholder name (item slot/type: 0x17, 0x1a..0x1e are melee weapons)
	int unknown48;	// +0x48 NOTE: placeholder name (0: chain reaction source)
	int pad4c[9];
	int unknown70;	// +0x70 NOTE: placeholder name (0x457e90 tests == 2; Blast/Sunder only remove parts with > 1)
	char pad74;
	bool unknown75;	// +0x75 NOTE: placeholder name (part immune to Destroy/Smash criticals)
	char pad76;
	char pad77;
	int pad78[30];
	int unknownF0;	// +0xf0 NOTE: placeholder name (weapon special type, 0xd6: tears parts off for the companion)
	int padf4[14];
	int unknown12C;	// +0x12c NOTE: placeholder name (negative: melee weapon knocks matter out of the target)
	int pad130[28];
	YtExplosionRecord *unknown1A0;	// +0x1a0 NOTE: placeholder name (explosion of the item)
	int pad1a4;
	int unknown1A8;	// +0x1a8 NOTE: placeholder name (explosive type created when the part is detonated)

	string getPrefixedName(int *length);	// 0x456fd0 (OpR1e_Named::getPrefixedName)
};

struct YtExplosionRecord	// the explosion record passed as 'explosion' (YtItemRecord+0x1a0 points to one)
{
	int ID;					// +0x0 NOTE: placeholder name
	string name;			// +0x4
	YtItemRecord *unknown20;	// +0x20 NOTE: placeholder name (exploding item)
	struct YtPropData *unknown24;	// +0x24 NOTE: placeholder name (exploding machine/prop)
	int pad28;
	int unknown2c;	// +0x2c NOTE: placeholder name
	int unknown30;	// +0x30 NOTE: placeholder name
	int pad34[19];
	bool unknown80;	// +0x80 NOTE: placeholder name
};

class YtItem
{
public:
	int unknown457880();				// NOTE: placeholder name (0x457880): data->unknown44 (slot type)
	int unknown457c80();				// NOTE: placeholder name (0x457c80): data->+0xa8 (max integrity)
	int unknown457f90();				// NOTE: placeholder name (0x457f90): data->+0xf0
	int unknown9b6bf0();				// NOTE: placeholder name (ICF'd trivial getter 0x9b6bf0): this->+0x1c (integrity)
	YtItemRecord *unknown9b4350();		// NOTE: placeholder name (ICF'd trivial getter 0x9b4350): this->data (+0x8)
	string getName(int a, int b);		// NOTE: placeholder name (0x571db0)
	int unknown4578a0();				// NOTE: placeholder name (0x4578a0): data->+0x48
	bool unknown457cf0();				// NOTE: placeholder name (0x457cf0): +0x28 != -1
	int unknown457fb0();				// NOTE: placeholder name (0x457fb0): data->+0xf4 (share of damage absorbed, percent)
	int unknown44aec0();				// NOTE: placeholder name (ICF'd trivial getter 0x44aec0): this->+0xc
	int unknown577790();				// NOTE: placeholder name (0x577790)
	bool unknown57ab10(int amount, int type, int a, int b, YtHEntity attacker, int c, int *out);	// NOTE: placeholder name (0x57ab10): damage the item, true when destroyed
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name (0x57dbe0)
	bool unknown457e90();	// NOTE: placeholder name (0x457e90)
	YtHEntity unknown457b50();	// NOTE: placeholder name (0x457b50): owner (+0x10)
	int unknown577fb0();	// NOTE: placeholder name (0x577fb0): unknown457be0(0x6b)
	void unknown450460(int value);	// NOTE: placeholder name (ICF'd trivial setter 0x450460): this->+0x1c (integrity)
};

class YtProp
{
public:
	class YtTrap *unknown44b020();	// NOTE: placeholder name (0x44b020): trivial getter of +0x4c (ICF)
	bool isPassableFor(YtHEntity entity);	// NOTE: placeholder name (0x65e1d0)
	int unknown45c630();	// NOTE: placeholder name (0x45c630): data->+0x70
	struct YtPropData *getData();	// NOTE: placeholder name (0x9b8f00)
	void unknown45ceb0(YtHEntity attacker, bool flag);	// NOTE: placeholder name (0x45ceb0)
};

class YtCell
{
public:
	bool unknown45dc70();	// NOTE: placeholder name (0x45dc70)
	bool unknown45dd40(int value);	// NOTE: placeholder name (0x45dd40)
	YtHProp getProp();	// 0x45d550
	void removeProp(bool keepTerrain, int cause);	// NOTE: placeholder name (0x66c100)
	bool hasBlockingObject();	// NOTE: placeholder name (0x45d7b0)
	YtHItem getItem();	// NOTE: placeholder name (0x45d8f0)
	YtHEntity getEntity();	// NOTE: placeholder name (0x45d250)
	bool canPlaceEntity(int size);	// 0x66ad20
};

class YtEntity
{
public:
	int pad0;
	YtHEntity self;						// +0x4
	YtEntityRecord *data;					// +0x8
	int padc[9];
	vector<YtPoint> positions;			// +0x30 yt_cells occupied
	int pad40[19];
	int integrity;						// +0x8c core integrity
	int energy;							// +0x90 NOTE: placeholder name
	int pad94;
	int heat;							// +0x98 NOTE: placeholder name
	int pad9c[4];
	bool unknownAC;						// +0xac NOTE: placeholder name (set by a thermal meltdown roll)
	char padad;
	char padae;
	char padaf;
	int padb0[3];
	int unknownBC;						// +0xbc
	bool unknownC0;						// +0xc0 NOTE: placeholder name
	char padc1;
	char padc2;
	char padc3;
	int padc4[12];
	vector<YtEffectPair *> unknownF4;		// +0xf4 (EM damage list)
	vector<YtEffectPair *> unknown104;	// +0x104 (thermal damage list)
	int pad114[3];
	int unknown120;						// +0x120
	int pad124[4];
	vector<YtHItem> items;				// +0x134 attached parts
	YtEntityAI *ai;						// +0x144

	bool isPlayer();								// 0x5c7600
	int unknown5c7fc0(YtHEntity other);				// NOTE: placeholder name (0x5c7fc0): relation to 'other' (2 = ally?)
	YtPoint unknown45a4c0();							// NOTE: placeholder name (0x45a4c0)
	const YtPoint &getPosition();						// 0x45a4a0
	YtEntityEffect *unknown45ac40(int type);			// NOTE: placeholder name (0x45ac40)
	int unknown5d22a0(int type);					// NOTE: placeholder name (0x5d22a0)
	YtHItem unknown5d2380(int type);					// NOTE: placeholder name (0x5d2380)
	bool isHostileTo(YtHEntity e);					// 0x45aa70
	bool unknown45aaa0(YtHEntity e);					// NOTE: placeholder name (0x45aaa0): same group as e
	YtHItem unknown5e3fc0();							// NOTE: placeholder name (0x5e3fc0): pick the part hit by impact damage
	YtHItem unknown5e3cb0(bool a, int b, int c, int d, int e);	// NOTE: placeholder name (0x5e3cb0): pick the part hit (null = core)
	bool unknown5e4fd0(YtHItem item, int *amount, int type, int critical, int a7, YtHEntity attacker);	// NOTE: placeholder name (0x5e4fd0): shielding absorbed the hit
	int unknown5d2090(int type);					// NOTE: placeholder name (0x5d2090)
	int unknown5d2150(int type, int base);			// NOTE: placeholder name (0x5d2150)
	int unknown5cad50();							// NOTE: placeholder name (0x5cad50)
	int unknown5ded70(int amount);					// NOTE: placeholder name (0x5ded70)
	void die(bool a, int cause, YtHEntity killer, int source, int critical, int d, int e, int f);	// 0x633790 NOTE: placeholder signature
	int takeDamage(int source, YtItemRecord *weapon, YtExplosionRecord *explosion, int damage, int type, int critical, int a7, bool a8, YtHEntity attacker, int a10, int a11, int a12, int a13, bool a14);	// 0x5e5520
	void unknown5e5340(bool a, bool b, int c, bool d, int effectIndex, const string &text);	// NOTE: placeholder name (0x5e5340)
	void unknown639950(vector<YtEffectPair *> *list, YtHEntity source, int amount);	// NOTE: placeholder name (0x639950)
	void unknown45b340(YtEntityEffect *effect);	// NOTE: placeholder name (0x45b340): effects.push_back
	void unknown5e40f0(int damage, int type, YtHEntity attacker, YtItemRecord *weapon, int a, int b, int c);	// NOTE: placeholder name (0x5e40f0)
	bool unknown5c7f70();	// NOTE: placeholder name (0x5c7f70)
	unsigned int unknown5d2430(int type, vector<YtHItem> *out);	// NOTE: placeholder name (0x5d2430)
	const string &unknown416f40();	// NOTE: placeholder name (ICF'd trivial getter 0x416f40): name (+0xc)
	string unknown45a410();	// NOTE: placeholder name (0x45a410): name used in messages
	unsigned int unknown5cb8b0(vector<YtHItem> *out);	// NOTE: placeholder name (0x5cb8b0)
	void unknown642940(YtHItem item, bool a, int b, int c, int d);	// NOTE: placeholder name (0x642940): detach a part
	int unknown45a990();	// NOTE: placeholder name (0x45a990): heat (+0x98)
	int unknown45a340();	// NOTE: placeholder name (0x45a340): data->unknown98
	int getSize();	// NOTE: placeholder name (0x45a360)
	int unknown5d1390();	// NOTE: placeholder name (0x5d1390)
	int unknown5cb570(int slot, bool flag);	// NOTE: placeholder name (0x5cb570)
	int unknown5defa0(int amount, bool notify);	// NOTE: placeholder name (0x5defa0): corrupt by amount, returns the corruption applied
	void unknown5e5100(YtHEntity attacker, int *outValue, bool silent);	// NOTE: placeholder name (0x5e5100)
	bool unknown5c84f0(const YtPoint &p);	// NOTE: placeholder name (0x5c84f0)
	bool unknown5c85a0(const YtPoint &p, bool large);	// NOTE: placeholder name (0x5c85a0)
	bool unknown5c8710(const YtPoint &p);	// NOTE: placeholder name (0x5c8710)
	void unknown5ddac0(const YtPoint &p, bool flag);	// NOTE: placeholder name (0x5ddac0): move to p
	bool unknown5fdd30();	// NOTE: placeholder name (0x5fdd30): false when the entity did not survive
	class YtHGroup getGroup();	// 0x45a3f0
	class YtInventory *getInventory();				// 0x45ad90
	int getFaction();	// 0x45a2c0
	bool unknown5c8820(YtHEntity other);	// NOTE: placeholder name (0x5c8820)
	YtHItem unknown5d24e0(int type);	// NOTE: placeholder name (0x5d24e0)
};

struct YtArea	// NOTE: placeholder name (cell rectangle)
{
	YtPoint min;	// +0x0
	YtPoint max;	// +0x8

	YtArea();	// 0x40b100: (-1,-1)-(-1,-1)
};

template <class T>
class YtArray2D	// NOTE: placeholder name
{
public:
	T &operator()(const YtPoint &p);	// 0x9ced70
	void getRect(const YtPoint &p, int radius, YtArea &out);	// NOTE: placeholder name (0x9b4430)
};

template <class T>
class YtWeightedList	// NOTE: placeholder name (weighted random pick; OpR5h_WL in src/op), addresses of this instantiation
{
public:
	vector<T> values;	// +0x0
	vector<int> weights;	// +0x10
	int total;	// +0x20

	YtWeightedList();	// 0x9ba440
	~YtWeightedList();	// 0x787710
	void add(T value, int weight);	// 0x9ba0d0
	bool isEmpty();	// 0x9b81b0
	T &pick();	// 0x9ba470
	unsigned int size();	// 0x9b81d0: values.size()
	void reset();	// 0x9c1be0
	vector<T> *getValues();	// NOTE: placeholder name (ICF'd trivial getter): &values
	vector<int> *getWeights();	// NOTE: placeholder name (0x462e10): &weights
	void setWeight(T value, int weight);	// NOTE: placeholder name (0x9ba270 for YtPoint)
};


class YtEntityAI
{
public:
	void unknown5b39b0(YtHEntity e);	// NOTE: placeholder name (0x5b39b0)
	void prioritizeTarget(YtHEntity target);	// 0x5b52f0
};

class YtOpS4_Xom	// NOTE: placeholder name (object at 0xd25450; Xom = sound/music event system)
{
public:
	bool active;	// +0x0 NOTE: placeholder name

	int unknown69e700(int id, int a, float b);	// NOTE: placeholder name (0x69e700): trigger sound/music event id, returns a value used by R7
	bool unknown69e9b0(const YtPoint &p);	// NOTE: placeholder name (0x69e9b0)
	bool unknown69edf0();	// NOTE: placeholder name (0x69edf0)
	void unknown69ee30(int a, int b, int c);	// NOTE: placeholder name (0x69ee30)
};

class YtMap
{
public:
	YtHEntity getPlayer();					// 0x4630f0
	YtHEntity getEntity671();					// NOTE: placeholder name (0x463110): +0x670
	void unknown464750(int amount);	// NOTE: placeholder name (0x464750): +0x664 += amount
	bool opw3_unknown727780(YtHEntity e, int *amount);	// NOTE: placeholder name (0x727780): remote shields (item types 70/71) absorb part of *amount
	class YtHExplosive unknown777a20(class YtHExplosive h);	// NOTE: placeholder name (0x777a20, OpU5_Level::addRecord in the csv)
	YtHItem unknown71e7c0(const YtPoint &p, int amount, bool protomatter);	// NOTE: placeholder name (0x71e7c0): create matter at p
	void unknown464840(YtHItem item);	// NOTE: placeholder name (0x464840)
	bool unknown465200(const YtPoint &a, const YtPoint &b);	// NOTE: placeholder name (0x465200)
	class YtOpW2_Object *unknown717be0();	// NOTE: placeholder name (0x717be0)
	void unknown735720(YtHEntity source, YtHEntity target, bool flag);	// NOTE: placeholder name (0x735720)
	int getTurn();	// 0x464270
	int unknown714b50();	// NOTE: placeholder name (0x714b50)
	void opw3_unknown72f620();	// NOTE: placeholder name (0x72f620)
	void unknown465270(int range, const YtPoint &from, const YtPoint &to, vector<YtPoint> *out);	// NOTE: placeholder name (0x465270): line from -> to
	bool isReachable(int range, const YtPoint &from, const YtPoint &to);	// 0x465230
};

class YtOpR1h_StatSet	// NOTE: placeholder name (YtOpR1h_Stats::current)
{
public:
	vector<int> values;	// +0x0 NOTE: placeholder name
};

class YtOpR1h_Stats	// NOTE: placeholder name (object at 0xd2c658)
{
public:
	YtOpR1h_StatSet *current;	// +0x0

	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
	int unknown472c70(int id);			// NOTE: placeholder name (0x472c70): current->get(id)
};

class YtPlayerData	// NOTE: partial (object at 0xcf45d8)
{
public:
	void unknown77fbc0(int id);			// NOTE: placeholder name (0x77fbc0): looks like "unlock achievement id"
	bool isSlotEmpty(unsigned int id);	// NOTE: placeholder name (0x46de40): achievement id not unlocked yet
	bool hasCompanion();				// NOTE: placeholder name (0x780790)
};

class YtOpU5_MsgConsole	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void unknown8758d0(bool flag);		// NOTE: placeholder name (0x8758d0)
};

class YtCLogMsgs
{
public:
	void scrollToEnd();					// 0x7b4f10
};

class YtOpS3e_TurnQueue	// NOTE: placeholder name (object at 0xd225a0)
{
public:
	void unknown672b80(YtHEntity entity, int delta);	// NOTE: placeholder name (0x672b80): delay the entity's next turn
};

class YtTrap	// YtProp+0x4c (OpR3_PropLink in the csv)
{
public:
	int pad0[5];
	int stasis;	// +0x14 NOTE: placeholder name

	bool unknown65cf80();	// NOTE: placeholder name (0x65cf80)
};

class YtCMap	// NOTE: partial (object at 0xcec054)
{
public:
	void unknown819500(YtHEntity e);	// NOTE: placeholder name (0x819500)
};

struct YtOpR2b_Location	// NOTE: placeholder name
{
	int unknown00;	// +0x0
	int type;		// +0x4 map type
};

class YtOpR2b_HLocation	// NOTE: placeholder name
{
public:
	int ID;	// +0x0

	YtOpR2b_Location *operator->() const;	// 0x9b7910
};

class YtExplosive	// NOTE: placeholder name (0x40-byte object built by 0x515ca0; the exe has vector<YtHExplosive>)
{
public:
	YtExplosive(YtHEntity source, int type, const YtPoint &pos, YtHEntity b, const YtPoint &c, const YtPoint &d);
	int data[16];	// NOTE: placeholder name (0x515ca0)
};

class YtHExplosive	// NOTE: placeholder name
{
public:
	int ID;	// +0x0

	YtHExplosive();	// 0x9b6590
};

class YtOpU5s2_Factory	// NOTE: placeholder name (object at 0xcefaa8)
{
public:
	YtHExplosive createA(YtExplosive *explosive);	// 0x7930e0
};

class YtRolledValues	// NOTE: placeholder name (object at 0xcefb48)
{
public:
	bool say(int ID, bool force, string name);	// 0x49e250
};

class YtCBD	// NOTE: placeholder name (object at 0xcefc14)
{
public:
	bool canUse(YtHEntity e, unsigned int record);	// NOTE: placeholder name (0x7ac0e0)
	void unknown7ac1c0(YtHEntity e, int record, int a, string text);	// NOTE: placeholder name (0x7ac1c0)
};

class YtOpW2_Object	// NOTE: placeholder name
{
public:
	void unknown45b6b0(YtHEntity entity, const YtPoint &p);	// NOTE: placeholder name (0x45b6b0)
};

class YtGroup	// NOTE: partial
{
public:
	int unknown9b4350();	// NOTE: placeholder name (ICF'd trivial getter 0x9b4350): +0x8
};

class YtHGroup
{
public:
	int ID;	// +0x0

	YtGroup *operator->() const;	// 0x9b7250
};

class YtEffect;	// NOTE: placeholder name
class YtEffectPool	// NOTE: placeholder name (object at 0xcefc50)
{
public:
	YtEffect *unknown508610();	// NOTE: placeholder name (0x508610)
};

class YtEffect	// NOTE: placeholder name
{
public:
	void unknown503b20(YtEffectPool *pool, int id, const YtPoint &pos, const YtPoint &offset, int a, int b, int c, int d, int e);	// NOTE: placeholder name (0x503b20)
};

class YtEndTarget1	// NOTE: placeholder name (object at 0xcec138)
{
public:
	void unknown965c10(int a, bool b, bool c);	// NOTE: placeholder name (0x965c10): screen shake/flash effect
};

class YtInventory;
struct YtPropData	// NOTE: placeholder name
{
	int pad0[8];
	string name;	// +0x20
	int pad3c[20];
	int unknown8C;	// +0x8c NOTE: placeholder name
	int pad90[44];
	int unknown140;	// +0x140 NOTE: placeholder name
};

class YtOpU5_SpawnTracker	// NOTE: placeholder name
{
public:
	bool spawn(unsigned int index, bool force, string extra);	// NOTE: placeholder name (0x7aa280)
};

struct YtOpU5_State	// NOTE: placeholder name (object at 0xcf4ac8)
{
	int unknown00;					// +0x0 NOTE: placeholder name
	int pad4;
	int unknown08;					// +0x8 NOTE: placeholder name
	bool unknown0C;					// +0xc NOTE: placeholder name
	char padd;
	char pade;
	char padf;
	int pad10[3];
	vector<int> unknown1C;			// +0x1c NOTE: placeholder name (kills per robot class)
	int unknown2C;					// +0x2c NOTE: placeholder name
	YtOpU5_SpawnTracker *tracker;		// +0x30

	void increase48b8c0(int amount);	// NOTE: placeholder name (0x48b8c0)
};

struct YtOpV2_LogEntry	// NOTE: placeholder name
{
	int unknown00;	// +0x0 NOTE: placeholder name
	string text;	// +0x4
	int unknown20;	// +0x20 NOTE: placeholder name
	int turn;		// +0x24 NOTE: placeholder name
};

class YtOpV2_MessageLog	// NOTE: placeholder name (object at 0xcf1080)
{
public:
	vector<YtOpV2_LogEntry *> *getEntries();	// NOTE: placeholder name (ICF'd trivial getter 0x9c0790): the log entries (+0x0)
};

class YtOpY5_Builder	// NOTE: placeholder name (same object as yt_xom, 0xd25450)
{
public:
	bool placeEntityNear(const struct YtOpY5_Range *range, YtPoint *pos, YtHEntity e, bool a, bool b);	// NOTE: placeholder name (0x6bd410)
	void showShift(const YtPoint &pos, YtHEntity e);	// NOTE: placeholder name (0x6bd6d0)
};


//==================================================================
// globals
//==================================================================

extern YtRNG rng;								// 0xd30908
extern YtMap *yt_world;							// 0xcefc4c NOTE: placeholder name
extern YtOpU5_MsgConsole *yt_msgConsole;			// 0xcec058 NOTE: placeholder name
extern YtCLogMsgs *yt_logMsgs;					// 0xcec0b4 NOTE: placeholder name
extern YtCLogMsgs *yt_logMsgs2;					// 0xcec0c4 NOTE: placeholder name (second message log)
extern int yt_opr3b_debugLevel;				// 0xd28d18 NOTE: placeholder name (1: also log to yt_logMsgs2)
extern YtOpR1h_Stats yt_stats;					// 0xd2c658 NOTE: placeholder name
extern YtPlayerData yt_playerData;				// 0xcf45d8 NOTE: placeholder name
extern int yt_opS2_intCf462c;					// 0xcf462c NOTE: placeholder name
extern YtArray2D<YtCell *> yt_cells;				// 0xcfd44c NOTE: placeholder name
extern YtOpS4_Xom yt_xom;						// 0xd25450 NOTE: placeholder name
extern string yt_gameStrings_d1e058[];			// 0xd1e058 critical names, indexed by criticalType
extern bool yt_debugGodMode;					// 0xcefb0b NOTE: placeholder name: the player takes no damage
extern bool yt_debugAlwaysHitCore;				// 0xcefb0c NOTE: placeholder name: forces a10 = 1
extern YtPoint yt_impaleTimeLoss;				// 0xd1f384 NOTE: placeholder name: range of the Impale time loss
extern YtOpS3e_TurnQueue yt_eventQueue;			// 0xd225a0 NOTE: placeholder name
extern vector<YtOpR3_StatType *> yt_opr3_statTypes;	// 0xd2f0f8 NOTE: placeholder name
extern YtCMap *yt_mapView;	// 0xcec054 NOTE: placeholder name
extern YtOpR2b_HLocation yt_opr2b_location;		// 0xd1e888 NOTE: placeholder name
extern int yt_xomExplosionID;					// 0xd254f0 NOTE: placeholder name
extern int yt_xomNoExplosionID;				// 0xcaf154 NOTE: placeholder name
extern bool yt_xomExplosionHitPlayer;			// 0xd254f4 NOTE: placeholder name
extern int yt_unknownCefb38;					// 0xcefb38 NOTE: placeholder name
extern const unsigned char yt_unknownBa0994[];	// 0xba0994 NOTE: placeholder name (indexed by yt_unknownCefb38)
extern const unsigned char yt_unknownB96570[];	// 0xb96570 NOTE: placeholder name (indexed by source: 1 for 7,8,9)
extern YtOpU5s2_Factory *yt_opU5s2_factory;		// 0xcefaa8 NOTE: placeholder name
extern YtRolledValues *yt_rolledValues_cefb48;	// 0xcefb48 NOTE: placeholder name
extern YtCBD *yt_opU5s4_cbd;						// 0xcefc14 NOTE: placeholder name
extern int yt_coreInstakills;					// 0xcf4d28 NOTE: placeholder name (player kills by core instakill, achievement 0x97 at 50)
extern const int yt_unknownB9654c[];			// 0xb9654c NOTE: placeholder name (detonation chance by a12: 0,100,50,30,10)
extern const unsigned char yt_unknownB96560[];	// 0xb96560 NOTE: placeholder name (indexed by source: overflow damage carries over for 7,9,10)
extern const int yt_unknownB96178[];			// 0xb96178 NOTE: placeholder name (meltdown chance by a13: 0,5,25,37,50,80,120)
extern YtPoint yt_impactCorruption;				// 0xd1619c NOTE: placeholder name (corruption range per part lost to impact damage)
extern YtPoint yt_impactCorruptionPlayer;		// 0xd22258 NOTE: placeholder name (same, for the player and class 0x49)
extern const int yt_unknownB96198[];			// 0xb96198 NOTE: placeholder name (meltdown chance bonus by a13)
extern const int yt_unknownB960f0;				// 0xb960f0 NOTE: placeholder name (200: heat for the player's Burn feedback)
extern const int yt_unknownB96108;				// 0xb96108 NOTE: placeholder name (120: same for other robots)
extern const int yt_unknownB962e8[];			// 0xb962e8 NOTE: placeholder name (direction index, one side of a11)
extern const int yt_unknownB96308[];			// 0xb96308 NOTE: placeholder name (direction index, other side of a11)
extern YtPoint yt_unknownD015d8[];				// 0xd015d8 NOTE: placeholder name (direction offsets)
extern bool yt_screenEffects;					// 0xd28d4c NOTE: placeholder name (screen effect option)
extern YtEndTarget1 *yt_endTarget1;				// 0xcec138
extern YtEffectPool *yt_effectPool;				// 0xcefc50 NOTE: placeholder name
extern YtPoint yt_effectOffset;					// 0xd2e20c NOTE: placeholder name
extern const int yt_unknownB96114;				// 0xb96114 NOTE: placeholder name (300: heat after an instant meltdown)
extern int yt_unknownCf49f4;					// 0xcf49f4 NOTE: placeholder name
extern YtOpU5_State *yt_opU5_state;				// 0xcf4ac8 NOTE: placeholder name
extern int yt_opY3_specialMode;				// 0xcf4b38 NOTE: placeholder name (0x1c: ..., then source + 15)
extern string yt_deathCause;					// 0xcf4b3c NOTE: placeholder name
extern YtPropData *yt_lastAttackingProp;			// 0xcefb7c NOTE: placeholder name
extern int yt_thrownType;						// 0xce9fe0 NOTE: placeholder name (what yt_thrownSource points to)
extern void *yt_thrownSource;					// 0xcefb64 NOTE: placeholder name (YtPropData, YtEntityRecord or YtItemRecord by yt_thrownType)
extern string yt_gameStrings_d2b4f8[];			// 0xd2b4f8 robot class names
extern int yt_xomExplosionKills;				// 0xd254f8 NOTE: placeholder name
extern const int yt_unknownBbca4c;				// 0xbbca4c NOTE: placeholder name
extern YtOpV2_MessageLog yt_messageLog;			// 0xcf1080 NOTE: placeholder name
extern vector<YtItemRecord *> yt_specialWeapons;	// 0xd1e00c NOTE: placeholder name
extern int yt_specialWeaponKills;				// 0xcf4d60 NOTE: placeholder name (achievement 0xd7 at 20)
extern int yt_class12MeleeKills;				// 0xcf4d90 NOTE: placeholder name (achievement 0x11e at 10)
extern YtOpY5_Builder yt_builder;				// 0xd25450 NOTE: placeholder name (same object as yt_xom)

bool yt_unknown5111e0(int type, const string *text, const string *text2, int a, YtHEntity entity, YtHProp prop, const YtPoint *pos, int flag);	// NOTE: placeholder name (0x5111e0): add a message to the log, true if the console must be refreshed
bool yt_OpT8b_Fn9daf80(int low, int value, int high);	// 0x9daf80: low <= value <= high
int yt_OpX5_maxInt(int a, int b);		// 0x9cdb60
int yt_OpX5_minInt(int a, int b);		// 0x9cdb30
int yt_opR1d_4542a0(const YtPoint &pos, unsigned int sound, unsigned int channel);	// NOTE: placeholder name (0x4542a0): play a sound at pos
void yt_OpV4c_Fn9d0690(int *value, int amount, int minimum);	// 0x9d0690: *value -= amount, not below minimum
void yt_logError(string location, string message);	// NOTE: placeholder name (0x404f10)
void yt_unknown9d9fc0(vector<YtHItem> &v);	// NOTE: placeholder name (0x9d9fc0, yt_OpV4c_shuffle): shuffle with rng
float yt_OpQ1_distance_40a450(const YtPoint &a, const YtPoint &b);	// NOTE: placeholder name (0x40a450)
int yt_OpQ1_distanceCeil_40a3f0(const YtPoint &a, const YtPoint &b);	// NOTE: placeholder name (0x40a3f0)
float yt_unknown4012b0(float value);	// NOTE: placeholder name (0x4012b0): absolute value
bool yt_OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980): sound ID by name
YtPoint yt_OpU8a_randomPoint(vector<YtPoint> &v);	// NOTE: placeholder name (0x9d5350)
template <class T> void yt_OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name (0x9d5190 for YtPoint): erase v[index]
string yt_intToString(int value);	// 0x4051f0
bool yt_OpS1c_unknown4569a0(int id, YtHEntity a, YtHEntity b, YtHProp c, YtHProp d, int e, int f, YtInventory *inventory, YtHEntity g, YtHProp h, YtHProp i, int j);	// NOTE: placeholder name (0x4569a0)
YtHItem yt_OpX5_randomRecord(vector<YtHItem> &v);	// 0x9dafb0: random element of v
void yt_unknown9d6440(vector<YtHItem> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440, OpQ5_eraseStep in the csv): erase v[i], then step i back
bool yt_OpX5_containsRecord(vector<YtItemRecord *> &v, YtItemRecord *record);	// 0x9db330
void yt_sweepGetSurroundingCells(const YtPoint &point, vector<YtPoint> &adjacent);	// 0x4faaf0
template <class T> void yt_OpV4c_shuffle(vector<T> &v);	// 0x9d7350 for YtPoint: shuffle with rng

// log a message, then keep the message log scrolled to its end
#define LOG_MESSAGE2(type,text,text2,a,entity,prop,pos,flag)	do { if (yt_unknown5111e0(type,text,text2,a,entity,prop,pos,flag)) yt_msgConsole->unknown8758d0(false); yt_logMsgs2->scrollToEnd(); } while (0)
#define LOG_MESSAGE(type,text,text2,a,entity,prop,pos,flag)	do { if (yt_unknown5111e0(type,text,text2,a,entity,prop,pos,flag)) yt_msgConsole->unknown8758d0(true); yt_logMsgs->scrollToEnd(); } while (0)

// critical statistics/achievements when the player scores a critical hit (expanded inline several
// times in the exe), and the usual critical hit message followed by them
#define RECORD_CRITICAL_HIT()	\
	if (attacker.operator->() != NULL && attacker->isPlayer() && !selfIsPlayer)	\
	{	\
		yt_stats.add4729d0(0x196,1,"",-1);	\
		yt_stats.add4729d0(0x196 + critical,1,"",-1);	\
		if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)	\
			yt_playerData.unknown77fbc0(0x96);	\
		if (yt_playerData.isSlotEmpty(0x98))	\
		{	\
			int criticalKinds = 0;	\
			for (int statID = 0x197; statID < 0x1a3; statID++)	\
			{	\
				if (yt_stats.unknown472c70(statID) != 0)	\
					criticalKinds++;	\
			}	\
			if (criticalKinds >= 8)	\
				yt_playerData.unknown77fbc0(0x98);	\
		}	\
	}

#define LOG_CRITICAL_HIT()	\
	{	\
		LOG_MESSAGE(selfIsPlayer ? 0x1b : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x1c,&static_cast<const string &>(string(yt_gameStrings_d1e058[critical])),NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);	\
		RECORD_CRITICAL_HIT()	\
	}

//==================================================================
// YtEntity::takeDamage
extern const float yt_f_b948d4;
extern const float yt_f_b97628;
extern const float yt_f_b96cec;
extern const float yt_f_b96518;
extern const float yt_f_b96514;
extern const float yt_f_b96194;

// helper: lets LTCG prove the 0x46ca20 ctor nothrow (no EH state around new, extra temp slot kept)
YtEntityEffect::YtEntityEffect(YtOpR3_StatType *record_, int value_)
{
	record = record_;
	value = value_;
}


#define RECORD_DAMAGE_PREVENTED()	\
		if (damage < originalDamage)	\
		{	\
			if (isPlayer())	\
			{	\
				yt_stats.add4729d0(0x173,originalDamage - damage,"",-1);	\
				if (yt_stats.current->values[0x173] >= 1500)	\
					yt_playerData.unknown77fbc0(0x8a);	\
			}	\
			else if (self == yt_world->getEntity671())	\
				yt_stats.add4729d0(0x450,originalDamage - damage,"",-1);	\
		}

//==================================================================

// source:		NOTE: placeholder name; attack source kind (byte table 0xb96570 is 1 for 7,8,9)
// weapon:		record of the weapon/item that caused the damage, or NULL
// explosion:	explosion record that caused the damage, or NULL
// damage:		amount
// type:		damageType
// critical:	criticalType
// attacker:	entity responsible, or a null handle
// returns 0 when no damage was applied; other return values: see docs/giants/5e5520.md
int YtEntity::takeDamage(int source, YtItemRecord *weapon, YtExplosionRecord *explosion, int damage, int type, int critical, int a7, bool a8, YtHEntity attacker, int a10, int a11, int a12, int a13, bool a14)
{
	// locals shared between regions (others are declared where they are used)
	YtHEntity b0 = self;			// [ebp-0xd78]
	bool b5 = isPlayer();		// [ebp-0xd71]
	int aG;						// [ebp-0xd7c] damage after the Impale/Intensify criticals
	// declared by region R2 at their point of construction (exe order): int netDamage [ebp-0xd80],
	// YtHItem hitPart [ebp-0xd84] (part hit, null when the core is hit), int partDamage [ebp-0xd88],
	// int destroyedCount [ebp-0xd6c] (incremented per part destroyed, consumed by the impact case)

	if (b5 && yt_debugGodMode)
		return 0;

	if (yt_debugAlwaysHitCore)
		a10 = 1;

	switch (critical)
	{
	case CRITICAL_IMPALE:
		{
			// the target loses time, and so does a melee attacker
			int timeLoss = yt_impaleTimeLoss.randomInRange_40c130();
			yt_eventQueue.unknown672b80(self,timeLoss * 100);
			if (b5)
				yt_world->unknown464750(timeLoss * 100);

			if (attacker.operator->() != NULL && (weapon == NULL || yt_OpT8b_Fn9daf80(0x1a,weapon->unknown44,0x1e)))
			{
				yt_eventQueue.unknown672b80(attacker,timeLoss * 100);
				if (attacker->isPlayer())
					yt_world->unknown464750(timeLoss * 100);
			}
		}
		// fall through: Impale also doubles the damage
	case CRITICAL_INTENSIFY:
		{
			damage *= (critical == CRITICAL_IMPALE) ? 2 : 2;	// NOTE: both multipliers are 2 in the exe

			{
				LOG_MESSAGE(b5 ? 0x1b : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x1c,&static_cast<const string &>(string(yt_gameStrings_d1e058[critical])),NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);
					if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
			{
				yt_stats.add4729d0(0x196,1,"",-1);
				yt_stats.add4729d0(0x196 + critical,1,"",-1);
				if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)
					yt_playerData.unknown77fbc0(0x96);
				if (yt_playerData.isSlotEmpty(0x98))
				{
					int criticalKinds = 0;
					for (int statID = 0x197; statID < 0x1a3; statID++)
					{
						if (yt_stats.unknown472c70(statID) != 0)
							criticalKinds++;
					}
					if (criticalKinds >= 8)
						yt_playerData.unknown77fbc0(0x98);
				}
			}
			}

			unknown5e5340(a8,b5,4,false,0x1f,string(yt_gameStrings_d1e058[critical]));
		}
		break;
	}

	if (unknown120 != -1 && attacker.operator->() != NULL && attacker->isPlayer())
	{
		unknown120++;
		if (type != DAMAGE_IMPACT || unknown120 > 1)
			unknown120 = -1;
	}

	aG = damage;

	if (ai != NULL && attacker.operator->() != NULL)
		ai->unknown5b39b0(attacker);

	if (!b5 && attacker.operator->() != NULL)
	{
		if (type == DAMAGE_THERMAL || type == DAMAGE_EM)
		{
			unknown639950(&((type == DAMAGE_THERMAL) ? unknown104 : unknownF4),attacker,aG);
		}

		if (data->unknown28 == 0x1b && attacker->isPlayer() && unknown45ac40(0x2e) == NULL)
			unknown45b340(new YtEntityEffect(yt_opr3_statTypes[0x2e],1));
	}


	if (!a14)
	{
		// count the damage prevented (0x173 for the player, 0x450 for the entity at YtMap+0x670)
		int originalDamage = damage;
		int shieldValue;
		if (yt_cells(getPosition())->unknown45dc70())
		{
			damage = (int)(damage * yt_f_b948d4);
			yt_mapView->unknown819500(self);
			yt_opR1d_4542a0(self->getPosition(),0xc6,0x15);
			RECORD_DAMAGE_PREVENTED();
			if (damage == 0)
				return 0;
		}
		// shields: absorb a share of the damage, paid with energy
		else if ((shieldValue = unknown5d22a0(0x45)) != 0 && energy >= damage * 75 / 100 * shieldValue)
		{
			yt_OpV4c_Fn9d0690(&energy,damage * 75 / 100 * shieldValue,0);
			damage = (int)(damage * 0.25);
			RECORD_DAMAGE_PREVENTED();
			if (damage == 0)
				return 0;
		}
		else if ((shieldValue = unknown5d22a0(0x44)) != 0 && energy >= damage * 50 / 100 * shieldValue)
		{
			yt_OpV4c_Fn9d0690(&energy,damage * 50 / 100 * shieldValue,0);
			damage = (int)(damage * 0.5);
			RECORD_DAMAGE_PREVENTED();
			if (damage == 0)
				return 0;
		}
		else if ((shieldValue = unknown5d22a0(0x43)) != 0 && energy >= damage * 25 / 100 * shieldValue)
		{
			yt_OpV4c_Fn9d0690(&energy,damage * 25 / 100 * shieldValue,0);
			damage = (int)(damage * 0.75);
			RECORD_DAMAGE_PREVENTED();
			if (damage == 0)
				return 0;
		}
		else if (unknownBC != 0 && unknown5d2380(0x74).isNull())
		{
			damage = (int)(damage * yt_f_b97628);
			yt_mapView->unknown819500(self);
			yt_opR1d_4542a0(self->getPosition(),0xc6,0x15);
			RECORD_DAMAGE_PREVENTED();
			if (damage == 0)
				return 0;
		}
		else
		{
			// a stasis trap under the entity absorbs a quarter of the damage, losing that much stasis
			for (unsigned int posIndex = 0; posIndex < positions.size(); posIndex++)
			{
				if (yt_cells(positions[posIndex])->unknown45dd40(0xb) && yt_cells(positions[posIndex])->getProp()->unknown44b020()->unknown65cf80() && unknown5d2380(0x74).isNull())
				{
					int damageBefore = damage;
					damage = (int)(damage * yt_f_b96cec);
					yt_mapView->unknown819500(self);
					yt_opR1d_4542a0(self->getPosition(),0xc6,0x15);
					int absorbed = damageBefore - damage;
					if (absorbed != 0)
					{
						yt_cells(positions[posIndex])->getProp()->unknown44b020()->stasis -= absorbed;
						if (yt_cells(positions[posIndex])->getProp()->unknown44b020()->stasis < 1)
						{
							LOG_MESSAGE(0x224,NULL,NULL,0,YtHEntity(),YtHProp(),&positions[posIndex],0);
							yt_cells(positions[posIndex])->removeProp(false,3);
						}
					}
					RECORD_DAMAGE_PREVENTED();
					if (damage == 0)
						return 0;
					goto damageReduced;
				}
			}

			if (yt_world->opw3_unknown727780(self,&damage))
			{
				RECORD_DAMAGE_PREVENTED();
				if (damage == 0)
					return 0;
			}
			else if (type == DAMAGE_KINETIC || type == DAMAGE_THERMAL)
			{
				int flatReduction = unknown5d22a0(0x42);
				if (flatReduction != 0)
				{
					yt_OpV4c_Fn9d0690(&damage,flatReduction,0);
					RECORD_DAMAGE_PREVENTED();
					if (damage == 0)
						return 0;
				}
			}
		}
damageReduced:
		;
	}

	if (damage == 0)
		return 0;

	if (b5)
		yt_stats.add4729d0(0x171,damage,"",-1);
	else if (self == yt_world->getEntity671())
		yt_stats.add4729d0(0x44d,damage,"",-1);

	// explosions that trigger sound/music events
	if (yt_xom.active && explosion != NULL)
	{
		if (b5)
		{
			if (yt_xomExplosionID != yt_xomNoExplosionID && explosion->ID == yt_xomExplosionID)
				yt_xomExplosionHitPlayer = true;
			else if (explosion->unknown30 >= 500)
			{
				if (explosion->name.find("Dimensional_Slip_Node") != string::npos)
					yt_xom.unknown69e700(0x43,0,0.0f);
				else if (yt_opr2b_location->type == 0x13 && explosion->name.find("Zionite_Power") != string::npos)
					yt_xom.unknown69e700(0x50,0,0.0f);
			}
			else if (explosion->unknown2c == 7 && explosion->name.find("X0") != string::npos)
				yt_xom.unknown69e700(0x44,0,0.0f);
		}

		if (unknown45aaa0(yt_world->getPlayer()))
		{
			switch (yt_opr2b_location->type)
			{
			case 0x1a:
				if (explosion->name.find("ARC_Explode") != string::npos)
					yt_xom.unknown69e700(0x66,0,0.0f);
				break;
			case 0x16:
				if (explosion->name.find("ZHI_Explode") != string::npos)
					yt_xom.unknown69e700(0x68,0,0.0f);
				break;
			}
		}
	}

	int e5 = unknown5d2090(0x4c);	// [ebp-0xd70] NOTE: placeholder name
	if (e5 != 0)
		unknown5ded70(damage * e5 / 100);

	if (a13 != 0 && unknown5d2380(5).isValid())
		a13--;

	int netDamage = damage;
	YtHItem hitPart;
	int partDamage = damage;

	if (a10 == 1)
	{
		if (!a14 && unknown5e4fd0(hitPart,&damage,type,critical,a7,attacker))
			critical = CRITICAL_NONE;
	}
	else
	{
		hitPart = (type == DAMAGE_IMPACT) ? unknown5e3fc0()
			: unknown5e3cb0(source != 10 && attacker.operator->() != NULL && rng.chance(attacker->unknown5d22a0(0x62)),
				(a10 == -1) ? -1
					: ((yt_unknownB96570[source] && attacker.operator->() != NULL && unknown45ac40(0x14) == NULL)
						? yt_OpX5_maxInt(attacker->unknown5d2150(0x60,(type == DAMAGE_PIERCING) ? 8 : 0),attacker->unknown5d22a0(0x61))
						: 0),
				0,0,0);

		if (!a14 && unknown5e4fd0(hitPart,&damage,type,critical,a7,attacker) && critical != CRITICAL_NONE)
		{
			critical = CRITICAL_NONE;
			if (b5)
			{
				yt_stats.add4729d0(0x16e,1,"",-1);
				yt_playerData.unknown77fbc0(0x37);
			}
		}

		if (critical == CRITICAL_DESTROY || critical == CRITICAL_SMASH)
		{
			if (hitPart.isNull() && unknown45ac40(0x15) != NULL)
				goto cancelCritical;

			if (hitPart.isValid()
				&& (self == yt_world->getPlayer() || (data->unknown28 == 0x49 && yt_opS2_intCf462c == 7))
				&& yt_opS2_intCf462c != 6
				&& hitPart->unknown457880() != 0x12
				&& hitPart->unknown9b6bf0() >= hitPart->unknown457c80() * yt_f_b96518)
				goto cancelCritical;

			if (hitPart.isValid() && hitPart->unknown457f90() == 7)
				goto cancelCritical;

			if (hitPart.isValid() && hitPart->unknown9b4350()->unknown75)
				goto cancelCritical;

			if (hitPart.isValid() && hitPart->unknown457880() == 0x12)
				damage = (int)(damage * yt_f_b96514);
			else
			{
				if (!((unknown5cad50() == 2 && yt_unknownBa0994[yt_unknownCefb38])
					|| unknown45ac40(0x14) != NULL
					|| (unknown45ac40(0x15) != NULL && !hitPart.isValid())))
					damage = -1;	// core destroyed outright
				else
					goto cancelCritical;
			}

			{
				LOG_MESSAGE(b5 ? 0x1b : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x1c,&static_cast<const string &>(string(yt_gameStrings_d1e058[critical])),NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);
					if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
			{
				yt_stats.add4729d0(0x196,1,"",-1);
				yt_stats.add4729d0(0x196 + critical,1,"",-1);
				if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)
					yt_playerData.unknown77fbc0(0x96);
				if (yt_playerData.isSlotEmpty(0x98))
				{
					int criticalKinds = 0;
					for (int statID = 0x197; statID < 0x1a3; statID++)
					{
						if (yt_stats.unknown472c70(statID) != 0)
							criticalKinds++;
					}
					if (criticalKinds >= 8)
						yt_playerData.unknown77fbc0(0x98);
				}
			}
			}
			goto criticalChecked;

cancelCritical:
			critical = CRITICAL_NONE;
criticalChecked:
			;
		}
	}

	if (damage >= 200 && attacker.operator->() != NULL && attacker->isPlayer() && !b5 && source != 7
		&& (explosion == NULL || !explosion->unknown80))
		yt_playerData.unknown77fbc0(0xdd);

	int gN = 0;


	if (hitPart.isValid())
	{
		string partName = hitPart->getName(0,0);
		int partSlot = hitPart->unknown457880();
		int overflow = 0;	// damage left over after the part was destroyed

		// some parts detonate when hit (a12 indexes the detonation chance)
		if (a12 != 0 && hitPart->unknown9b4350()->unknown1A8 != 0 && ((data->unknown28 == 0) == false || explosion != NULL)
			&& rng.chance(yt_unknownB9654c[a12]))
		{
			if (hitPart->unknown4578a0() == 0)
			{
				YtHItem detonationBlocker = unknown5d2380(0x3a);
				if (detonationBlocker.isValid())
				{
					if (b5)
						LOG_MESSAGE(0x1a6,&static_cast<const string &>(detonationBlocker->getName(0,0)),&static_cast<const string &>(hitPart->getName(0,0)),0,self,YtHProp(),NULL,0);
					goto damagePart;
				}
				else
				{
				int explosiveType = hitPart->unknown9b4350()->unknown1A8;
				LOG_MESSAGE(0x1a5,&static_cast<const string &>(hitPart->getName(0,0)),NULL,0,YtHEntity(),YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);

				if (attacker.operator->() != NULL && attacker->isPlayer())
				{
					yt_stats.add4729d0(0x209,1,"",-1);
					if (yt_stats.unknown472c70(0x209) >= 15)
						yt_playerData.unknown77fbc0(0x9a);
				}

				if (yt_xom.active && b5 && attacker.operator->() != NULL && attacker->isPlayer())
					yt_xom.unknown69e700(0xc,0,0.0f);

				hitPart->unknown57dbe0(isPlayer(),isPlayer(),1,1);
				yt_world->unknown777a20(yt_opU5s2_factory->createA(new YtExplosive(attacker,explosiveType,unknown45a4c0(),YtHEntity(),YtPoint(-1),YtPoint(-1))));

				if (b0.operator->() == NULL)
					return 2;
				}
			}
		}
		else
		{
damagePart:
			int absorbed = 0;	// damage taken by armor/protection instead of the part
			int selfDamage = 0;	// NOTE: placeholder name; damage turned against the player (part type 0x66)

			if (damage != -1)
			{
				if (b5 && yt_opS2_intCf462c == 5)
				{
					absorbed += (hitPart->unknown457880() != 0x12 ? 80 : 40) * damage / 100;
					damage -= absorbed;
					yt_stats.add4729d0(0x175,absorbed,"",-1);
				}
				else if (yt_opS2_intCf462c == 6)
				{
					absorbed += (hitPart->unknown457880() != 0x12 ? 50 : 25) * damage / 100;
					damage -= absorbed;
					yt_stats.add4729d0(0x175,absorbed,"",-1);
				}
				else
				{
					if (hitPart->unknown457f90() == 0x40 && hitPart->unknown457cf0())
					{
						absorbed += hitPart->unknown457fb0() * damage / 100;
						damage -= absorbed;
						yt_stats.add4729d0(0x175,absorbed,"",-1);
					}

					if (unknown5d2380(0x41).isValid())
					{
						vector<YtHItem> protectors;
						unknown5d2430(0x41,&protectors);
						for (unsigned int protectorIndex = 0; protectorIndex < protectors.size(); protectorIndex++)
						{
							int share = protectors[protectorIndex]->unknown457fb0() * damage / 100;
							absorbed += share;
							damage -= share;
							yt_stats.add4729d0(0x175,share,"",-1);
						}
					}
				}

				if (hitPart->unknown457f90() == 0x66 && b5 && (selfDamage = damage / 3) == 0)
					selfDamage++;
			}

			int partIntegrity = hitPart->unknown9b6bf0();
			if (hitPart->unknown57ab10(damage,type,a7,critical,attacker,1,&overflow))
			{
				// part destroyed
				if (b0.operator->() == NULL)
					return 2;

				if (damage == -1 && attacker.operator->() != NULL && attacker->isPlayer() && !b5)
					yt_stats.add4729d0(0x195,1,"",-1);

				gN++;

				if (attacker.operator->() != NULL && attacker->unknown5c7f70())
					LOG_MESSAGE(0x3e,&partName,NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);

				if (yt_rolledValues_cefb48 != NULL && self == yt_world->getEntity671() && yt_rolledValues_cefb48 != NULL)
					yt_rolledValues_cefb48->say(0x1e,false,partName);

				if (yt_opU5s4_cbd != NULL)
				{
					bool gi = attacker.operator->() != NULL && yt_opU5s4_cbd->canUse(attacker,6);
					bool selfTracked = yt_opU5s4_cbd->canUse(self,7);
					if (gi || selfTracked)
					{
						string lostText = "[" + self->unknown416f40() + " lost " + partName + "]";
						LOG_MESSAGE(0x322,&lostText,NULL,0,YtHEntity(),YtHProp(),NULL,0);
					}
					if (gi)
						yt_opU5s4_cbd->unknown7ac1c0(attacker,6,1,partName);
					if (selfTracked)
						yt_opU5s4_cbd->unknown7ac1c0(self,7,1,partName);
				}

				unknown5e5340(a8,b5,1,true,partSlot,"-" + partName);

				if (damage == -1)
				{
					if (critical == CRITICAL_SMASH)
						overflow = partDamage;
					else if (partDamage > partIntegrity)
						overflow = partDamage - partIntegrity;
				}

				// the rest of the damage carries over to other parts (or the core)
				if (overflow != 0 && partSlot != 0x12 && yt_unknownB96560[source])
				{
					YtWeightedList<YtHItem> overflowCandidates;
				retryOverflow:
					{
						YtHItem aK;
						int overflowRemaining = 0;
						overflowCandidates.reset();
						for (unsigned int itemIndex = 0; itemIndex < items.size(); itemIndex++)
						{
							if (items[itemIndex]->unknown457880() == 0x12 && items[itemIndex]->unknown44aec0() != 4)
								overflowCandidates.add(items[itemIndex],items[itemIndex]->unknown577790());
						}
						aK = overflowCandidates.size() ? overflowCandidates.pick() : ((type == DAMAGE_IMPACT) ? unknown5e3fc0() : unknown5e3cb0(false,0,0,0,0));
						int overflowShielded = 0;

						if (critical == CRITICAL_SMASH && ((!a14 && unknown5e4fd0(aK,&overflowShielded,type,critical,0,attacker))
							|| (aK.isNull() && unknown45ac40(0x15) != NULL)))
							critical = CRITICAL_NONE;
						else
						{
							if (aK.isValid())
							{
								string overflowName = aK->getName(0,0);
								if (aK->unknown57ab10(overflow,type,0,0,attacker,2,&overflowRemaining))
								{
									if (b0.operator->() == NULL)
										return 2;

									if (attacker.operator->() != NULL && attacker->unknown5c7f70())
										LOG_MESSAGE(0x3e,&overflowName,NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);

									gN++;
								}
							}
							else
								unknown5e40f0(overflow,type,attacker,weapon,0,0,1);

							if (attacker.operator->() != NULL && attacker->isPlayer())
							{
								yt_stats.add4729d0(0x1d8,overflow - overflowRemaining,"",-1);
								switch (source)
								{
								case 7:
									yt_stats.add4729d0(0x1db,overflow - overflowRemaining,"",-1);
									break;
								case 9:
									yt_stats.add4729d0(0x1d9,overflow - overflowRemaining,"",-1);
									break;
								case 10:
									yt_stats.add4729d0(0x1da,overflow - overflowRemaining,"",-1);
									break;
								}
							}
						}

						if (overflowRemaining != 0 && overflowCandidates.size() == 0)
						{
							overflow = overflowRemaining;
							goto retryOverflow;
						}
					}
				}
			}
			else if (a13 != 0 && heat >= 250 && ai != NULL && unknown45ac40(0x1e) == NULL && rng.chance(yt_unknownB96178[a13]))
			{
				// the overheated part melts down
				if (attacker.operator->() != NULL && attacker->isPlayer())
				{
					LOG_MESSAGE(0x41,&static_cast<const string &>(hitPart->getName(0,0)),NULL,0,self,YtHProp(),NULL,0);
					yt_stats.add4729d0(0x204,1,"",-1);
				}
				unknown5e5340(a8,b5,2,true,0x1f,"-" + hitPart->getName(0,0));
				hitPart->unknown57dbe0(0,0,1,1);
			}

			if (absorbed != 0)
				unknown5e40f0(absorbed,type,attacker,weapon,a7,0,0);
			if (selfDamage != 0)
				unknown5e40f0(selfDamage,DAMAGE_ENTROPIC,YtHEntity(),weapon,0,0,0);
		}
	}
	else
	{
		// core hit
		if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
			yt_stats.add4729d0(0x193,1,"",-1);

		if (damage == -1)
		{
			if (data->unknown28 == 0x5a)
				yt_logError("Entity::takeDamage()","GM instakilled by " + ((attacker.operator->() != NULL) ? string(attacker->unknown416f40()) : string("UNKNOWN")));

			integrity = 0;
			damage = 0;

			if (attacker.operator->() != NULL && attacker->isPlayer())
			{
				yt_stats.add4729d0(0x194,1,"",-1);
				yt_coreInstakills++;
				if (yt_coreInstakills >= 50)
					yt_playerData.unknown77fbc0(0x97);
			}
		}
		else
			unknown5e40f0(damage,type,attacker,weapon,a7,critical,0);
	}


	switch (critical)
	{
		break;
	case CRITICAL_BLAST:
		if (damage > 0)
		{
			YtHItem blastPart;
			blastPart = unknown5e3fc0();
			int blastAbsorbed = 0;
			if ((!a14 && unknown5e4fd0(blastPart,&blastAbsorbed,type,critical,0,attacker))
				|| (blastPart.isValid() && blastPart->unknown9b4350()->unknown75))
			{
				critical = CRITICAL_NONE;
			}
			else if (blastPart.isValid())
			{
				string blastName = blastPart->getName(0,0);
				int blastSlot = blastPart->unknown457880();
				if (blastPart->unknown57ab10(damage,type,0,0,attacker,1,NULL))
				{
					// the part was destroyed by the hit itself
					if (b0.operator->() == NULL)
						return 2;

					LOG_MESSAGE(b5 ? 0x1b : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x1c,&static_cast<const string &>(string(yt_gameStrings_d1e058[critical])),NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);

					if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
					{
						yt_stats.add4729d0(0x196,1,"",-1);
						yt_stats.add4729d0(0x196 + critical,1,"",-1);

						if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)
							yt_playerData.unknown77fbc0(0x96);

						if (yt_playerData.isSlotEmpty(0x98))
						{
							int criticalKinds = 0;
							for (int statID = 0x197; statID < 0x1a3; statID++)
							{
								if (yt_stats.unknown472c70(statID) != 0)
									criticalKinds++;
							}
							if (criticalKinds >= 8)
								yt_playerData.unknown77fbc0(0x98);
						}
					}

					unknown5e5340(a8,b5,1,true,blastSlot,"-" + blastName);

					if (attacker.operator->() != NULL && attacker->unknown5c7f70())
						LOG_MESSAGE(0x3e,&blastName,NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);

					gN++;
				}
				else if (unknown45ac40(0x13) == NULL && blastPart->unknown9b4350()->unknown70 > 1 && blastPart->unknown457f90() != 7
					&& blastPart->unknown577fb0() == 0 && (yt_opS2_intCf462c != 2 || b5))
				{
					LOG_MESSAGE(b5 ? 0x1e : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x1f,&blastName,NULL,0,self,YtHProp(),NULL,0);

					if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
					{
						yt_stats.add4729d0(0x196,1,"",-1);
						yt_stats.add4729d0(0x196 + critical,1,"",-1);

						if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)
							yt_playerData.unknown77fbc0(0x96);

						if (yt_playerData.isSlotEmpty(0x98))
						{
							int criticalKinds = 0;
							for (int statID = 0x197; statID < 0x1a3; statID++)
							{
								if (yt_stats.unknown472c70(statID) != 0)
									criticalKinds++;
							}
							if (criticalKinds >= 8)
								yt_playerData.unknown77fbc0(0x98);
						}
					}

					if (yt_opr3b_debugLevel == 1)
					{
						string debugText = "  " + (b5 ? "" : unknown45a410() + " ") + blastName + " blasted off";
						LOG_MESSAGE2(b5 ? 0x2c9 : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x2ca,&debugText,NULL,0,self,YtHProp(),NULL,1);
					}

					if (blastPart->unknown457e90() || unknownC0)
					{
						LOG_MESSAGE(0x45,&blastName,NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);
						blastPart->unknown57dbe0(b5,1,1,1);
						unknown5e5340(a8,b5,1,true,blastSlot,"-" + blastName);
					}
					else
					{
						unknown642940(blastPart,b5,1,0,2);
						unknown5e5340(a8,b5,4,true,0x1f,"-" + blastName);
					}

					if (b5 && yt_xom.active)
						yt_xom.unknown69e700(0x10,0,0.0f);
				}
			}
			else if (unknown45ac40(0x15) == NULL)
			{
				// no part to blast off: the core takes the hit
				LOG_MESSAGE(b5 ? 0x1b : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x1c,&static_cast<const string &>(string(yt_gameStrings_d1e058[critical])),NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);

				if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
				{
					yt_stats.add4729d0(0x196,1,"",-1);
					yt_stats.add4729d0(0x196 + critical,1,"",-1);

					if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)
						yt_playerData.unknown77fbc0(0x96);

					if (yt_playerData.isSlotEmpty(0x98))
					{
						int criticalKinds = 0;
						for (int statID = 0x197; statID < 0x1a3; statID++)
						{
							if (yt_stats.unknown472c70(statID) != 0)
								criticalKinds++;
						}
						if (criticalKinds >= 8)
							yt_playerData.unknown77fbc0(0x98);
					}
				}

				unknown5e40f0(damage,type,attacker,weapon,0,0,1);
			}
		}
		break;
	case CRITICAL_SUNDER:
		if (unknown45ac40(0x13) == NULL)
		{
			vector<YtHItem> sundered;
			if (hitPart.isNull())
			{
				// core hit: sunder 1-2 random parts
				vector<YtHItem> sunderCandidates;
				if (unknown5cb8b0(&sunderCandidates) != 0)
				{
					yt_unknown9d9fc0(sunderCandidates);
					unsigned int candidateIndex = 0;
					for (int sunderCount = rng.rangeInt(1.0f,2.0f); sunderCount > 0 && candidateIndex < sunderCandidates.size(); sunderCount--, candidateIndex++)
						sundered.push_back(sunderCandidates[candidateIndex]);
				}
			}
			else if (hitPart.operator->() != NULL && hitPart->unknown457b50() == self && hitPart->unknown44aec0() <= 3)
				sundered.push_back(hitPart);

			if (!sundered.empty())
			{
				bool sunderReported = false;
				for (unsigned int sunderIndex = 0; sunderIndex < sundered.size(); sunderIndex++)
				{
					if (sundered[sunderIndex]->unknown9b4350()->unknown70 > 1 && sundered[sunderIndex]->unknown457f90() != 7
						&& sundered[sunderIndex]->unknown577fb0() == 0 && !sundered[sunderIndex]->unknown9b4350()->unknown75
						&& (yt_opS2_intCf462c != 2 || b5))
					{
						int sunderAbsorbed = 0;
						if (hitPart.isNull() && !a14 && unknown5e4fd0(sundered[sunderIndex],&sunderAbsorbed,type,critical,0,attacker))
						{
							critical = CRITICAL_NONE;
							goto nextSunder;
						}

						if (!sunderReported)
						{
							LOG_MESSAGE(b5 ? 0x1b : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x1c,&static_cast<const string &>(string(yt_gameStrings_d1e058[critical])),NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);

							if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
							{
								yt_stats.add4729d0(0x196,1,"",-1);
								yt_stats.add4729d0(0x196 + critical,1,"",-1);

								if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)
									yt_playerData.unknown77fbc0(0x96);

								if (yt_playerData.isSlotEmpty(0x98))
								{
									int criticalKinds = 0;
									for (int statID = 0x197; statID < 0x1a3; statID++)
									{
										if (yt_stats.unknown472c70(statID) != 0)
											criticalKinds++;
									}
									if (criticalKinds >= 8)
										yt_playerData.unknown77fbc0(0x98);
								}
							}
							sunderReported = true;
						}

						LOG_MESSAGE(b5 ? 0x26 : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x27,&static_cast<const string &>(sundered[sunderIndex]->getName(0,0)),NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);

						if (sundered[sunderIndex]->unknown457e90() || unknownC0)
						{
							LOG_MESSAGE(0x45,&static_cast<const string &>(sundered[sunderIndex]->getName(0,0)),NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);

							if (yt_opr3b_debugLevel == 1)
							{
								string debugText = "  " + (b5 ? "" : unknown45a410() + " ") + sundered[sunderIndex]->getName(0,0) + " disintegrated";
								LOG_MESSAGE2(b5 ? 0x2c9 : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x2ca,&debugText,NULL,0,self,YtHProp(),NULL,1);
							}

							unknown5e5340(a8,b5,1,true,sundered[sunderIndex]->unknown457880(),"-" + sundered[sunderIndex]->getName(0,0));
							sundered[sunderIndex]->unknown57dbe0(b5,1,1,1);
						}
						else
						{
							if (yt_opr3b_debugLevel == 1)
							{
								string debugText = "  " + (b5 ? "" : unknown45a410() + " ") + sundered[sunderIndex]->getName(0,0) + " knocked off";
								LOG_MESSAGE2(b5 ? 0x2c9 : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x2ca,&debugText,NULL,0,self,YtHProp(),NULL,1);
							}

							unknown5e5340(a8,b5,4,true,0x1f,"-" + sundered[sunderIndex]->getName(0,0));
							unknown642940(sundered[sunderIndex],b5,1,0,2);
						}
					}
				nextSunder:;
				}
			}
		}
		break;
	}


	switch (type)
	{
	case DAMAGE_KINETIC:
		{
			// melee weapons with a matter-loss property knock matter out of the target
			int knockedMatter;
			if (source == 9 && weapon != NULL && weapon->unknown12C < -2 && attacker.operator->() != NULL
				&& (knockedMatter = rng.rangeInt(0,(float)-weapon->unknown12C)) != 0)
			{
				YtPoint attackerPos(attacker->getPosition());
				YtPoint centerVal(getPosition());
				float baseDistance = yt_OpQ1_distance_40a450(attackerPos,centerVal);
				YtWeightedList<YtPoint> dropSpots;
				int emptySpots = 0;
				float aH;
				YtArea areaRef;
				yt_cells.getRect(unknown45a4c0(),2,areaRef);
				for (int x = areaRef.min.x; x <= areaRef.max.x; x++)
				{
					for (int y = areaRef.min.y; y <= areaRef.max.y; y++)
					{
						YtPoint spot(x,y);
						if ((yt_cells(spot)->hasBlockingObject() || (yt_cells(spot)->getItem().isValid() && yt_cells(spot)->getItem()->unknown457880() == 0))
							&& (centerVal.unknown409cb0(x,y) || yt_world->unknown465200(centerVal,spot)))
						{
							// prefer spots away from the attacker
							aH = yt_OpQ1_distance_40a450(attacker->getPosition(),spot) - baseDistance;
							float distanceFromCenter = yt_OpQ1_distance_40a450(centerVal,spot);
							int aN = (aH < 0.5) ? 10 : 90;
							if (yt_unknown4012b0(aH) >= 2.0)
								aN /= 2;
							if (yt_cells(spot)->getItem().isNull())
								emptySpots++;
							dropSpots.add(spot,aN);
						}
					}
				}

				if (!dropSpots.isEmpty())
				{
					vector<YtPoint> *spots = dropSpots.getValues();
					if (spots->size() > emptySpots)
					{
						if (emptySpots > 1)
							emptySpots /= 2;
						for (unsigned int spotIndex = 0; spotIndex < spots->size(); spotIndex++)
						{
							if (yt_cells((*spots)[spotIndex])->getItem().isValid() && yt_cells((*spots)[spotIndex])->getItem()->unknown457880() == 0)
								dropSpots.setWeight((*spots)[spotIndex],(*dropSpots.getWeights())[spotIndex] * emptySpots);
						}
					}

					YtPoint j4(dropSpots.pick());
					if (yt_cells(j4)->getItem().isValid() && yt_cells(j4)->getItem()->unknown457880() == 0)
						yt_cells(j4)->getItem()->unknown450460(yt_cells(j4)->getItem()->unknown9b6bf0() + knockedMatter);
					else
					{
						YtHItem matter = yt_world->unknown71e7c0(j4,knockedMatter,false);
						if (matter.isValid())
							yt_world->unknown464840(matter);
					}
				}
			}
		}
		goto knockback;

	case DAMAGE_THERMAL:
		if (a13 != 0)
		{
			int k5 = yt_unknownB96178[a13] * netDamage / aG;
			if (critical == CRITICAL_BURN)
			{
				int nG = k5;
				k5 *= 3;
				string burnText = (const string &)(b5 ? yt_gameStrings_d1e058[critical] + ": +" + yt_intToString(nG) : yt_gameStrings_d1e058[critical]);
				LOG_MESSAGE(b5 ? 0x1b : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x1c,&burnText,NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);
				if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
				{
					yt_stats.add4729d0(0x196,1,"",-1);
					yt_stats.add4729d0(0x196 + critical,1,"",-1);
					if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)
						yt_playerData.unknown77fbc0(0x96);
					if (yt_playerData.isSlotEmpty(0x98))
					{
						int criticalKinds = 0;
						for (int statID = 0x197; statID < 0x1a3; statID++)
						{
							if (yt_stats.unknown472c70(statID) != 0)
								criticalKinds++;
						}
						if (criticalKinds >= 8)
							yt_playerData.unknown77fbc0(0x98);
					}
				}
				if (unknown45a990() >= (b5 ? yt_unknownB960f0 : yt_unknownB96108))
					unknown5e5340(a8,b5,4,false,0x1f,string(yt_gameStrings_d1e058[critical]));
			}

			if (unknown45ac40(0x1e) != NULL)
				k5 = (int)(k5 * yt_f_b96194);
			int lo = 100 - unknown5d2090(0x2c);
			int heatAdded = k5 * lo / 100;
			heat += heatAdded;

			if (attacker.operator->() != NULL)
			{
				if (attacker->isPlayer() && !b5)
					yt_stats.add4729d0(0x205,heatAdded,"",-1);
				else if (b5 && !attacker->isPlayer())
					yt_stats.add4729d0(0x1e8,heatAdded,"",-1);
			}

			// meltdown
			if (integrity > 0 && heat >= 250 && ai != NULL && unknown45ac40(0x1e) == NULL
				&& rng.chance((heat - 250) / 20 + yt_unknownB96198[a13]))
			{
				if (rng.chance(50))
					unknownAC = true;
				else
				{
					unknown5e5100(attacker,&source,false);
					if (yt_opr3b_debugLevel == 1)
					{
						string meltdownText = "  " + (unknown45a410() + " instant meltdown");
						LOG_MESSAGE2((unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x2ca,&meltdownText,NULL,0,self,YtHProp(),NULL,1);
					}
				}
			}
		}
		break;
		break;

	case DAMAGE_EM:
		{
			int emResistance = unknown5d2090(0x29);
			if (emResistance == 0)
				emResistance = 1;
			int corrupted = 0;
			if (b5 || data->unknown28 == 0x49)
			{
				if (rng.chance(aG / emResistance))
					corrupted = unknown5defa0((critical == CRITICAL_CORRUPT) ? yt_OpX5_maxInt(1,rng.rangeInt(1,10) * aG / 100) : 1,true);
			}
			else
				corrupted = unknown5defa0(((critical == CRITICAL_CORRUPT) ? 150 : rng.rangeInt(50,150)) * aG / 100 / emResistance,true);

			if (corrupted != 0 && critical == CRITICAL_CORRUPT)
			{
				if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
				{
					yt_stats.add4729d0(0x196,1,"",-1);
					yt_stats.add4729d0(0x196 + critical,1,"",-1);
					if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)
						yt_playerData.unknown77fbc0(0x96);
					if (yt_playerData.isSlotEmpty(0x98))
					{
						int criticalKinds = 0;
						for (int statID = 0x197; statID < 0x1a3; statID++)
						{
							if (yt_stats.unknown472c70(statID) != 0)
								criticalKinds++;
						}
						if (criticalKinds >= 8)
							yt_playerData.unknown77fbc0(0x98);
					}
				}
				unknown5e5340(a8,b5,4,false,0x1f,string(yt_gameStrings_d1e058[critical]));
			}

			if (b5 && yt_screenEffects)
				yt_endTarget1->unknown965c10(damage,source == 10,false);
		}
		break;

	case DAMAGE_IMPACT:
		// every part destroyed by the impact jars the core: corruption
		while (gN != 0)
		{
			int corruption = (!b5 && data->unknown28 != 0x49) ? yt_impactCorruption.randomInRange_40c130() : yt_impactCorruptionPlayer.randomInRange_40c130();
			corruption = unknown5cb570(3,true) * corruption / 100;
			corruption = unknown5defa0(corruption,false);
			if (corruption != 0)
			{
				if (b5)
					LOG_MESSAGE(0xa4,&static_cast<const string &>(yt_intToString(corruption)),NULL,0,self,YtHProp(),NULL,0);
				else
				{
					LOG_MESSAGE(unknown45aaa0(yt_world->getPlayer()) ? 0xa5 : 0xa6,NULL,NULL,0,self,YtHProp(),NULL,0);
					if (attacker.operator->() != NULL)
						unknown639950(&unknownF4,attacker,corruption);
				}

				if (!a8)
				{
					int soundID;
					yt_OpU8a_lookup2("Part_Destroyed_Corr",&soundID);
					if (soundID != 0)
						yt_effectPool->unknown508610()->unknown503b20(yt_effectPool,soundID,unknown45a4c0(),yt_effectOffset,0,0,0,9,0);
					if (b5 && yt_screenEffects)
						yt_endTarget1->unknown965c10(0x28,false,false);
				}
			}

			if (attacker.operator->() != NULL && attacker->isPlayer())
				yt_stats.add4729d0(0x201,1,"",-1);

			gN--;
		}

knockback:
		// knockback (kinetic and impact)
		if (integrity > 0 && attacker.operator->() != NULL && data->unknown9C == 1 && a11 != 8 && unknown5d1390() != 0
			&& (unknown5cad50() != 2 || yt_unknownCefb38 != 3))
		{
			int knockbackChance;
			if (type == DAMAGE_IMPACT)
				knockbackChance = aG + (data->unknown98 - attacker->unknown45a340()) * 10;
			else
			{
				knockbackChance = aG - (data->unknown98 - 2) * 10;
				if (attacker.operator->() != NULL)
					knockbackChance += (10 - yt_OpQ1_distanceCeil_40a3f0(attacker->getPosition(),getPosition())) * 5;
				if (source != 9)
					knockbackChance = 0;
			}

			if (rng.chance(knockbackChance))
			{
				YtPoint knockbackPos(positions[0],yt_unknownD015d8[a11]);
				if (unknown5c84f0(knockbackPos))
				{
					YtHEntity knockedHandle = self;
					YtHEntity victim;
					int collisionDamage = 0;
					if (unknown5c85a0(knockbackPos,false))
					{
						// another robot is in the way: it may be pushed aside
						victim = yt_cells(knockbackPos)->getEntity();
						if (victim->getSize() == 1 && victim->unknown5d1390() != 0
							&& rng.chance(knockbackChance + (victim->unknown45a340() - data->unknown98) * 10))
						{
							vector<YtPoint> pushSpots;
							pushSpots.push_back(YtPoint(knockbackPos) += yt_unknownD015d8[yt_unknownB962e8[a11]]);
							pushSpots.push_back(YtPoint(knockbackPos) += yt_unknownD015d8[a11]);
							pushSpots.push_back(YtPoint(knockbackPos) += yt_unknownD015d8[yt_unknownB96308[a11]]);
							for (int pushIndex = pushSpots.size() - 1; pushIndex >= 0; pushIndex--)
							{
								if (!victim->unknown5c84f0(pushSpots[pushIndex]) || victim->unknown5c8710(pushSpots[pushIndex]) || victim->unknown5c85a0(pushSpots[pushIndex],false))
									yt_OpQ5_eraseAt(pushSpots,pushIndex);
							}
							if (!pushSpots.empty())
							{
								victim->unknown5ddac0(yt_OpU8a_randomPoint(pushSpots),false);
								if (attacker->isPlayer())
								{
									yt_stats.add4729d0(0x1dc,1,"",-1);
									yt_stats.add4729d0(0x1df,1,"",-1);
								}
								victim->unknown5fdd30();
							}

							collisionDamage = aG;
							if (victim.operator->() != NULL && victim->unknown45a340() > 1)
								collisionDamage /= victim->unknown45a340();
						}
					}

					if (knockedHandle.operator->() == NULL)
					{
						yt_logError("Entity::takeDamage()","Handle already invalid! quitting early during knockback");
						return 2;
					}

					if (!unknown5c85a0(knockbackPos,false))
					{
						if (!unknown5c8710(knockbackPos))
						{
							if (attacker->isPlayer())
							{
								yt_stats.add4729d0(0x1dc,1,"",-1);
								yt_stats.add4729d0(0x1dd + (type != DAMAGE_IMPACT),1,"",-1);
							}
							LOG_MESSAGE(b5 ? 0xa2 : 0xa3,NULL,NULL,0,self,YtHProp(),NULL,0);
							unknown5ddac0(knockbackPos,false);
							YtOpW2_Object *tracker = yt_world->unknown717be0();
							if (tracker != NULL)
								tracker->unknown45b6b0(self,getPosition());
							if (!unknown5fdd30())
								return 2;
						}
						else if (yt_cells(knockbackPos)->getProp().isValid() && !yt_cells(knockbackPos)->getProp()->isPassableFor(self)
							&& yt_cells(knockbackPos)->getProp()->unknown45c630() != -1 && yt_cells(knockbackPos)->getProp()->unknown45c630() <= aG)
						{
							// knocked through a door/weak prop
							bool propFlag = false;
							bool hostileToAttacker = false;
							if (attacker->isPlayer())
							{
								yt_stats.add4729d0(0x1dc,1,"",-1);
								yt_stats.add4729d0(0x1dd + (type != DAMAGE_IMPACT),1,"",-1);
								propFlag = (bool)yt_cells(knockbackPos)->getProp()->getData()->unknown8C;
								hostileToAttacker = isHostileTo(attacker);
							}
							LOG_MESSAGE(b5 ? 0xa2 : 0xa3,NULL,NULL,0,self,YtHProp(),NULL,0);
							yt_cells(knockbackPos)->getProp()->unknown45ceb0(attacker,a8);
							if (propFlag && type == DAMAGE_IMPACT && source == 7 && hostileToAttacker)
								yt_playerData.unknown77fbc0(0x31);
							if (knockedHandle.operator->() == NULL)
								return 2;
							unknown5ddac0(knockbackPos,false);
							YtOpW2_Object *nW = yt_world->unknown717be0();
							if (nW != NULL)
								nW->unknown45b6b0(self,getPosition());
							if (!unknown5fdd30())
								return 2;
						}
					}

					if (collisionDamage != 0 && victim.operator->() != NULL)
					{
						if (attacker->isPlayer() && weapon != NULL && weapon->unknown44 == 0x17 && type == DAMAGE_KINETIC)
							yt_playerData.unknown77fbc0(0x30);
						victim->takeDamage((source != 8) + 8,weapon,explosion,collisionDamage,DAMAGE_IMPACT,CRITICAL_NONE,0,a8,attacker,0,8,0,0,false);
						if (attacker->isPlayer() && unknown45aaa0(yt_world->getPlayer()) && victim.operator->() != NULL && victim->getGroup()->unknown9b4350() > 2)
							yt_world->unknown735720(attacker,victim,false);
					}
				}
			}
		}
		break;
	}


	if (b0.operator->() == NULL)
	{
		bool quitEarly = true;	// NOTE: placeholder (stored, never read)
		yt_logError("Entity::takeDamage()","Handle already invalid! quitting early");
		return 2;
	}

	if (integrity > 0)
	{
		switch (critical)
		{
			break;
		case CRITICAL_MELTDOWN:
			if (b5 || (data->unknown28 == 0x49 && yt_opS2_intCf462c == 7))
			{
				// no instant meltdown: heat surge instead
				int heatSurge = netDamage * 10;
				string a1 = yt_gameStrings_d1e058[critical] + ": +" + yt_intToString(heatSurge);
				LOG_MESSAGE(b5 ? 0x1b : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x1c,&a1,NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);
				int ns = 100 - unknown5d2090(0x2c);
				int heatAdded = heatSurge * ns / 100;
				heat += heatAdded;
				if (!attacker->isPlayer())
				{
					if (yt_xom.active && heatAdded >= 300 && heat >= 500 && yt_unknownCf49f4 == 0
						&& unknown5d2380(2).isNull() && unknown5d2380(4).isNull() && unknown5d2380(5).isNull() && unknown5d2380(0x88).isNull())
						yt_xom.unknown69e700(4,0,0.0f);
					yt_stats.add4729d0(0x1e8,heatAdded,"",-1);
				}
				if (yt_opr3b_debugLevel == 1)
				{
					a1 = "  " + (b5 ? string("Suffered critical hit: ") : unknown45a410() + " critical hit: ") + yt_gameStrings_d1e058[critical];
					if (b5)
						a1 += " (+" + yt_intToString(heatAdded) + ")";
					LOG_MESSAGE2(b5 ? 0x2c6 : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x2c7,&a1,NULL,0,self,YtHProp(),NULL,1);
				}
			}
			else if (unknown45ac40(0x1e) == NULL)
			{
				LOG_MESSAGE(b5 ? 0x1b : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x1c,&static_cast<const string &>(string(yt_gameStrings_d1e058[critical])),NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);
				if (heat < yt_unknownB96114)
					heat = yt_unknownB96114;
				unknown5e5100(attacker,&source,true);
				if (attacker.operator->() != NULL && attacker->isPlayer())
					yt_stats.add4729d0(0x194,1,"",-1);
				if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
				{
					yt_stats.add4729d0(0x196,1,"",-1);
					yt_stats.add4729d0(0x196 + critical,1,"",-1);
					if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)
						yt_playerData.unknown77fbc0(0x96);
					if (yt_playerData.isSlotEmpty(0x98))
					{
						int criticalKinds = 0;
						for (int statID = 0x197; statID < 0x1a3; statID++)
						{
							if (yt_stats.unknown472c70(statID) != 0)
								criticalKinds++;
						}
						if (criticalKinds >= 8)
							yt_playerData.unknown77fbc0(0x98);
					}
				}
			}
			break;

		case CRITICAL_SEVER:
			if (unknown45ac40(0x13) == NULL)
			{
				YtWeightedList<YtHItem> severable;
				if (hitPart.isNull())
				{
					for (unsigned int partIndex = 0; partIndex < items.size(); partIndex++)
					{
						if (items[partIndex]->unknown44aec0() != 4 && items[partIndex]->unknown9b4350()->unknown70 > 1
							&& items[partIndex]->unknown457f90() != 7 && items[partIndex]->unknown577fb0() == 0
							&& !items[partIndex]->unknown9b4350()->unknown75 && (yt_opS2_intCf462c != 2 || b5))
							severable.add(items[partIndex],items[partIndex]->unknown577790());
					}
				}
				else if (hitPart.operator->() != NULL && hitPart->unknown9b4350()->unknown70 > 1 && hitPart->unknown457f90() != 7
					&& hitPart->unknown577fb0() == 0 && (yt_opS2_intCf462c != 2 || b5))
					severable.add(hitPart,1);

				if (!severable.isEmpty())
				{
					YtHItem pK = severable.pick();
					int ignoredAmount = 0;
					if (!a14 && unknown5e4fd0(pK,&ignoredAmount,type,critical,0,attacker))
						critical = CRITICAL_NONE;
					else
					{
						string pd = pK->getName(0,0);
						int severedSlot = pK->unknown457880();
						LOG_MESSAGE(b5 ? 0x42 : (unknown45aaa0(yt_world->getPlayer()) ? 0x43 : 0x44),&static_cast<const string &>(pK->getName(0,0)),NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);
						if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
						{
							yt_stats.add4729d0(0x196,1,"",-1);
							yt_stats.add4729d0(0x196 + critical,1,"",-1);
							if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)
								yt_playerData.unknown77fbc0(0x96);
							if (yt_playerData.isSlotEmpty(0x98))
							{
								int criticalKinds = 0;
								for (int statID = 0x197; statID < 0x1a3; statID++)
								{
									if (yt_stats.unknown472c70(statID) != 0)
										criticalKinds++;
								}
								if (criticalKinds >= 8)
									yt_playerData.unknown77fbc0(0x98);
							}
						}

						if (pK->unknown457e90() || unknownC0)
						{
							LOG_MESSAGE(0x45,&pd,NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);
							if (yt_opr3b_debugLevel == 1)
							{
								string severText = "  " + (b5 ? string("") : unknown45a410() + " ") + pd + " disintegrated";
								LOG_MESSAGE2(b5 ? 0x2c9 : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x2ca,&severText,NULL,0,self,YtHProp(),NULL,1);
							}
							pK->unknown57dbe0(b5,1,1,1);
							unknown5e5340(a8,b5,1,true,severedSlot,"-" + pd);
						}
						else
						{
							int severedIntegrity = pK->unknown9b6bf0();
							if (severedIntegrity > 1 && hitPart.isNull())
							{
								int integrityLoss = yt_OpX5_maxInt(1,rng.rangeInt(5,25) * severedIntegrity / 100);
								pK->unknown57ab10(yt_OpX5_minInt(pK->unknown9b6bf0() - 1,integrityLoss),DAMAGE_SLASHING,0,0,YtHEntity(),1,NULL);
							}
							if (yt_opr3b_debugLevel == 1)
							{
								string severText = "  " + (b5 ? string("") : unknown45a410() + " ") + pd + " severed";
								LOG_MESSAGE2(b5 ? 0x2c9 : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x2ca,&severText,NULL,0,self,YtHProp(),NULL,1);
							}
							unknown642940(pK,b5,1,0,2);
							unknown5e5340(a8,b5,4,true,0x1f,"-" + pd);
							if (attacker.operator->() != NULL
								&& yt_OpS1c_unknown4569a0(0x25,attacker,YtHEntity(),YtHProp(),YtHProp(),0,0,attacker->getInventory(),attacker,YtHProp(),YtHProp(),0)
								&& b0.operator->() == NULL)
								return 2;
						}
					}
				}
			}
			break;


		case CRITICAL_PHASE:
			{
				int phaseAmount = 0;
				if (hitPart.isValid())
				{
					if (!a14 && unknown5e4fd0(YtHItem(),&phaseAmount,type,critical,0,attacker))
						critical = CRITICAL_NONE;
					else
					{
						LOG_MESSAGE(b5 ? 0x21 : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x22,&static_cast<const string &>(string("core")),NULL,0,self,YtHProp(),NULL,0);

						if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
						{
							yt_stats.add4729d0(0x196,1,"",-1);
							yt_stats.add4729d0(0x196 + critical,1,"",-1);

							if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)
								yt_playerData.unknown77fbc0(0x96);

							if (yt_playerData.isSlotEmpty(0x98))
							{
								int criticalKinds = 0;
								for (int statID = 0x197; statID < 0x1a3; statID++)
								{
									if (yt_stats.unknown472c70(statID) != 0)
										criticalKinds++;
								}
								if (criticalKinds >= 8)
									yt_playerData.unknown77fbc0(0x98);
							}
						}

						unknown5e5340(a8,b5,4,false,0x1f,string(yt_gameStrings_d1e058[critical]));
						unknown5e40f0(partDamage,type,attacker,weapon,0,0,0);
					}
				}
				else
				{
					YtHItem phasePart = unknown5e3cb0(false,-1,0,0,0);
					if (phasePart.isValid())
					{
						if ((!a14 && unknown5e4fd0(phasePart,&phaseAmount,type,critical,0,attacker)) || phasePart->unknown9b4350()->unknown75)
							critical = CRITICAL_NONE;
						else
						{
							string q3 = phasePart->getName(0,0);
							int phasePartSlot = phasePart->unknown457880();

							LOG_MESSAGE(b5 ? 0x21 : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x22,&q3,NULL,0,self,YtHProp(),NULL,0);

							if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
							{
								yt_stats.add4729d0(0x196,1,"",-1);
								yt_stats.add4729d0(0x196 + critical,1,"",-1);

								if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)
									yt_playerData.unknown77fbc0(0x96);

								if (yt_playerData.isSlotEmpty(0x98))
								{
									int criticalKinds = 0;
									for (int statID = 0x197; statID < 0x1a3; statID++)
									{
										if (yt_stats.unknown472c70(statID) != 0)
											criticalKinds++;
									}
									if (criticalKinds >= 8)
										yt_playerData.unknown77fbc0(0x98);
								}
							}

							if (phasePart->unknown57ab10(partDamage,type,0,0,attacker,1,NULL))
							{
								// the part was destroyed
								if (b0.operator->() == NULL)
									return 2;

								unknown5e5340(a8,b5,1,true,phasePartSlot,"-" + q3);

								if (attacker.operator->() != NULL && attacker->unknown5c7f70())
									LOG_MESSAGE(0x3e,&q3,NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);
							}
							else
								unknown5e5340(a8,b5,4,false,0x1f,string(yt_gameStrings_d1e058[critical]));
						}
					}
				}
			}
			break;

		case CRITICAL_DETONATE:
			{
				vector<YtHItem> detonateParts;
				if (unknown5cb8b0(&detonateParts))
				{
					for (unsigned int detonateIndex = 0; detonateIndex < detonateParts.size(); detonateIndex++)
					{
						if (detonateParts[detonateIndex]->unknown4578a0() != 0 || detonateParts[detonateIndex]->unknown9b4350()->unknown75)
							yt_unknown9d6440(detonateParts,detonateIndex);
					}
				}

				if (!detonateParts.empty())
				{
					YtHItem detonatedPart = yt_OpX5_randomRecord(detonateParts);
					YtHItem sy = unknown5d2380(0x3a);
					if (sy.isValid())
					{
						if (b5)
							LOG_MESSAGE(0x25,&static_cast<const string &>(sy->getName(0,0)),&static_cast<const string &>(detonatedPart->getName(0,0)),0,self,YtHProp(),NULL,0);
					}
					else
					{
						int explosiveType = detonatedPart->unknown9b4350()->unknown1A8;

						LOG_MESSAGE(0x24,&static_cast<const string &>(detonatedPart->getName(0,0)),NULL,0,YtHEntity(),YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);

						if (attacker.operator->() != NULL && attacker->isPlayer())
							yt_stats.add4729d0(0x195,1,"",-1);

						if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
						{
							yt_stats.add4729d0(0x196,1,"",-1);
							yt_stats.add4729d0(0x196 + critical,1,"",-1);

							if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)
								yt_playerData.unknown77fbc0(0x96);

							if (yt_playerData.isSlotEmpty(0x98))
							{
								int criticalKinds = 0;
								for (int statID = 0x197; statID < 0x1a3; statID++)
								{
									if (yt_stats.unknown472c70(statID) != 0)
										criticalKinds++;
								}
								if (criticalKinds >= 8)
									yt_playerData.unknown77fbc0(0x98);
							}
						}

						// NOTE: the exe tests the debug level twice here
						if (yt_opr3b_debugLevel == 1)
						{
							if (yt_opr3b_debugLevel == 1)
							{
								string debugText = "  " + (b5 ? string("") : unknown45a410() + " ") + detonatedPart->getName(0,0) + " detonated";
								LOG_MESSAGE2(b5 ? 0x2c9 : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x2ca,&debugText,NULL,0,self,YtHProp(),NULL,1);
							}
						}

						detonatedPart->unknown57dbe0(isPlayer(),isPlayer(),1,1);
						yt_world->unknown777a20(yt_opU5s2_factory->createA(new YtExplosive(attacker,explosiveType,unknown45a4c0(),YtHEntity(),YtPoint(-1),YtPoint(-1))));
					}
				}
			}
			break;
		}
	}

	// weapon 0xd6 tears a part off for the player's companion (the part goes to the spawn tracker)
	if (weapon != NULL && weapon->unknownF0 == 0xd6 && hitPart.operator->() != NULL && hitPart->unknown44aec0() <= 3
		&& hitPart->unknown9b4350()->unknown70 > 1 && hitPart->unknown457f90() != 7 && hitPart->unknown577fb0() == 0
		&& !hitPart->unknown9b4350()->unknown75 && (yt_opS2_intCf462c != 2 || b5) && yt_playerData.hasCompanion()
		&& rng.chance(yt_opU5_state->unknown08 / 250 + 3))
	{
		string tornName = hitPart->getName(0,0);
		int t_ = hitPart->unknown457880();
		LOG_MESSAGE(b5 ? 0x42 : (unknown45aaa0(yt_world->getPlayer()) ? 0x43 : 0x44),&tornName,NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);
		if (attacker.operator->() != NULL && attacker->isPlayer() && !b5)
		{
			yt_stats.add4729d0(0x196,1,"",-1);
			yt_stats.add4729d0(0x196 + critical,1,"",-1);
			if (critical == CRITICAL_MELTDOWN && yt_stats.unknown472c70(0x198) >= 10)
				yt_playerData.unknown77fbc0(0x96);
			if (yt_playerData.isSlotEmpty(0x98))
			{
				int criticalKinds = 0;
				for (int statID = 0x197; statID < 0x1a3; statID++)
				{
					if (yt_stats.unknown472c70(statID) != 0)
						criticalKinds++;
				}
				if (criticalKinds >= 8)
					yt_playerData.unknown77fbc0(0x98);
			}
		}

		if (hitPart->unknown457e90() || unknownC0)
		{
			LOG_MESSAGE(0x45,&static_cast<const string &>(hitPart->getName(0,0)),NULL,0,self,YtHProp(),&static_cast<const YtPoint &>(unknown45a4c0()),0);
			if (yt_opr3b_debugLevel == 1)
			{
				string tornText = "  " + (b5 ? string("") : unknown45a410() + " ") + tornName + " disintegrated";
				LOG_MESSAGE2(b5 ? 0x2c9 : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x2ca,&tornText,NULL,0,self,YtHProp(),NULL,1);
			}
			hitPart->unknown57dbe0(b5,1,1,1);
			unknown5e5340(a8,b5,1,true,t_,"-" + tornName);
		}
		else
		{
			if (yt_opr3b_debugLevel == 1)
			{
				string tornText = "  " + (b5 ? string("") : unknown45a410() + " ") + tornName + " severed";
				LOG_MESSAGE2(b5 ? 0x2c9 : (unknown5c7fc0(yt_world->getPlayer()) != 2) + 0x2ca,&tornText,NULL,0,self,YtHProp(),NULL,1);
			}
			unknown642940(hitPart,b5,1,0,2);
			unknown5e5340(a8,b5,4,true,0x1f,"-" + tornName);
			if (attacker.operator->() != NULL
				&& yt_OpS1c_unknown4569a0(0x25,attacker,YtHEntity(),YtHProp(),YtHProp(),0,0,attacker->getInventory(),attacker,YtHProp(),YtHProp(),0)
				&& b0.operator->() == NULL)
				return 2;
		}

		if (yt_playerData.hasCompanion())
			yt_opU5_state->tracker->spawn(0xf,false,tornName);
	}

	if (b0.operator->() == NULL)
		return 2;

	if (integrity <= 0)
	{
		// destroyed: record the cause of the player's death
		if (b5 && yt_opY3_specialMode == 0x1c)
		{
			if (yt_xom.active)
			{
				int xomEvent = 6;
				switch (source)
				{
				case 3:
					xomEvent = yt_xom.unknown69e700(0x7a,0,0.0f);
					break;
				case 4:
					xomEvent = yt_xom.unknown69e700(0x7d,0,0.0f);
					break;
				case 10:
					if (explosion != NULL && explosion->unknown24 != NULL && explosion->unknown24->unknown140 != 0x10)
						xomEvent = yt_xom.unknown69e700(0x7e,0,0.0f);
					break;
				case 11:
					xomEvent = yt_xom.unknown69e700(0x7e,0,0.0f);
					break;
				}

				if (attacker.operator->() != NULL)
				{
					if (attacker->isPlayer())
						xomEvent = yt_xom.unknown69e700(0x7c,0,0.0f);
					else if (attacker->getFaction() == 0x1d)
						xomEvent = yt_xom.unknown69e700(0x7f,0,0.0f);
				}

				if (xomEvent == 6 && yt_world->unknown714b50() >= 30)
					yt_xom.unknown69e700(0x81,0,0.0f);

				if (yt_xom.unknown69edf0())
				{
					yt_xom.unknown69ee30(1,0,1);
					return 1;
				}
			}

			yt_opY3_specialMode = source + 0xf;
			if (yt_opY3_specialMode >= 0x16)
			{
				if (explosion != NULL && explosion->unknown24 != NULL && explosion->unknown24->unknown140 != 0x10)
					yt_deathCause = "Destroyed by " + explosion->unknown24->name;
				else if (source == 11 && yt_lastAttackingProp != NULL)
					yt_deathCause = "Destroyed by " + yt_lastAttackingProp->name;
				else if (source == 12)
				{
					switch (yt_thrownType)
					{
						break;
					case 0:
						yt_deathCause = "Destroyed by thrown " + static_cast<YtPropData *>(yt_thrownSource)->name;
						break;
					case 1:
						yt_deathCause = "Destroyed by thrown " + static_cast<YtPropData *>(yt_thrownSource)->name;
						break;
					case 2:
						if (yt_thrownSource == NULL)
							yt_deathCause = "Destroyed when thrown into another robot";
						else
							yt_deathCause = "Destroyed by thrown " + yt_gameStrings_d2b4f8[static_cast<YtEntityRecord *>(yt_thrownSource)->unknown48];
						break;
					case 3:
						yt_deathCause = "Destroyed by thrown " + static_cast<YtItemRecord *>(yt_thrownSource)->name;
						break;
					}
				}
				else if (attacker.operator->() == NULL)
				{
					if (weapon != NULL)
						yt_deathCause = "Destroyed by " + weapon->getPrefixedName(NULL);
					else if (explosion != NULL)
					{
						if (explosion->unknown24 != NULL)
							yt_deathCause = "Destroyed by exploding " + explosion->unknown24->name;
						else if (explosion->unknown20 != NULL)
						{
							yt_deathCause = "Destroyed by " + explosion->unknown20->getPrefixedName(NULL);
							if (explosion->unknown20->unknown48 == 0)
								yt_deathCause += " chain reaction";
						}
					}
				}
				else
				{
					yt_deathCause = attacker->isPlayer() ? string("Destroyed self") : "Destroyed by " + attacker->unknown416f40();
					if (weapon != NULL)
						yt_deathCause += " with " + weapon->getPrefixedName(NULL);
					else if (explosion != NULL)
					{
						if (explosion->unknown20 != NULL)
						{
							yt_deathCause += " with " + explosion->unknown20->getPrefixedName(NULL);
							if (explosion->unknown20->unknown48 == 0)
								yt_deathCause += " chain reaction";
						}
						else if (explosion->unknown24 != NULL)
							yt_deathCause += " via exploding " + explosion->unknown24->name;
					}
				}
			}
		}

		if (yt_xom.active && !b5 && explosion != NULL && explosion->unknown24 != NULL && yt_world->getPlayer()->unknown45aaa0(self)
			&& yt_xom.unknown69e9b0(getPosition()) && unknown45ac40(0x3a) == NULL
			&& (attacker.operator->() == NULL || !attacker->isPlayer()))
			yt_xomExplosionKills++;

		// kills of hostile robots with weapon 0xd6, per robot class
		YtEntityRecord *trackedRecord = NULL;
		if (weapon != NULL && weapon->unknownF0 == 0xd6 && yt_opU5_state != NULL && yt_world->getPlayer()->isHostileTo(self))
		{
			trackedRecord = data;
			yt_opU5_state->unknown1C[trackedRecord->unknown48]++;
		}

		bool vC = yt_world->getPlayer()->isHostileTo(self);
		bool class12 = data->unknown28 == 0x12;	// NOTE: placeholder name
		die(a8,type,attacker,source,critical,0,0,0);

		if (trackedRecord != NULL && yt_opU5_state != NULL)
		{
			if (yt_opU5_state->unknown2C == 0x7a && yt_opU5_state->unknown1C[trackedRecord->unknown48] >= 10 && trackedRecord->unknown48 < 0x79 && rng.chance(2))
			{
				yt_opU5_state->unknown2C = trackedRecord->unknown48;
				if (yt_playerData.hasCompanion())
					yt_opU5_state->tracker->spawn(0x15,false,trackedRecord->getName459c30());
			}
			else if (yt_opU5_state->unknown00 != 0)
			{
				if (yt_playerData.hasCompanion())
					yt_opU5_state->tracker->spawn(0x20,false,trackedRecord->getName459c30());
			}
			else if (!yt_opU5_state->unknown0C)
			{
				yt_opU5_state->increase48b8c0(yt_unknownBbca4c);
				if (yt_playerData.hasCompanion())
					yt_opU5_state->tracker->spawn(4,false,trackedRecord->getName459c30());
			}
		}

		if (yt_playerData.isSlotEmpty(0xdb) && a10 == 1 && yt_messageLog.getEntries()->size() >= 2
			&& (*yt_messageLog.getEntries())[yt_messageLog.getEntries()->size() - 2]->turn == yt_world->getTurn()
			&& ((*yt_messageLog.getEntries())[yt_messageLog.getEntries()->size() - 2]->text.find("core destabilizing") != string::npos
				|| (*yt_messageLog.getEntries())[yt_messageLog.getEntries()->size() - 2]->text.find("core entropy") != string::npos))
			yt_playerData.unknown77fbc0(0xdb);

		if (yt_playerData.isSlotEmpty(0xc3) && explosion != NULL && explosion->unknown20 != NULL && explosion->unknown20->unknown48 == 0)
			yt_world->opw3_unknown72f620();

		if (attacker.operator->() != NULL && attacker->isPlayer())
		{
			if (((yt_playerData.isSlotEmpty(0xd7) && weapon != NULL && yt_OpX5_containsRecord(yt_specialWeapons,weapon))
				|| (explosion != NULL && (yt_specialWeapons[0]->unknown1A0 == explosion || yt_specialWeapons[1]->unknown1A0 == explosion)))
				&& ++yt_specialWeaponKills == 20)
				yt_playerData.unknown77fbc0(0xd7);

			if (yt_playerData.isSlotEmpty(0x11e) && weapon != NULL && class12 && vC && yt_OpT8b_Fn9daf80(0x1a,weapon->unknown44,0x1c)
				&& ++yt_class12MeleeKills == 10)
				yt_playerData.unknown77fbc0(0x11e);
		}
		return 2;
	}
	else
	{
	// survived: a phase shifter (0x4a) may shift the robot out of the attacker's line of fire
	if (damage > 0 && attacker.operator->() != NULL && attacker->isHostileTo(self) && unknown5d2380(0x4a).isValid() && !unknown5c8820(attacker))
	{
		YtHItem shifter = unknown5d24e0(0x4a);
		if (rng.chance(shifter->unknown457fb0()))
		{
			vector<YtPoint> line;
			yt_world->unknown465270(99,getPosition(),attacker->getPosition(),&line);
			if (yt_cells(line.back())->getEntity().isValid() && yt_cells(line.back())->getEntity() == attacker)
			{
				YtPoint shiftOrigin(-1);
				for (int lineIndex = line.size() - 1; lineIndex >= 0; lineIndex--)
				{
					if (yt_cells(line[lineIndex])->getEntity().isNull() || yt_cells(line[lineIndex])->getEntity() != attacker)
					{
						shiftOrigin = line[lineIndex];
						break;
					}
				}

				if (shiftOrigin.x != -1)
				{
					YtPoint shiftTarget(-1);
					if (yt_cells(shiftOrigin)->canPlaceEntity(getSize()))
						shiftTarget = shiftOrigin;
					else
					{
						vector<YtPoint> around;
						yt_sweepGetSurroundingCells(shiftOrigin,around);
						yt_OpV4c_shuffle(around);
						for (unsigned int aroundIndex = 0; aroundIndex < around.size(); aroundIndex++)
						{
							if (around[aroundIndex].adjacent(shiftOrigin) && yt_cells(around[aroundIndex])->canPlaceEntity(getSize())
								&& yt_world->isReachable(0x1e,getPosition(),around[aroundIndex]))
								shiftTarget = around[aroundIndex];
						}
					}

					if (shiftTarget.x != -1)
					{
						YtHEntity w3 = self;
						YtPoint shiftedFrom(w3->getPosition());
						bool placed = yt_builder.placeEntityNear(NULL,&shiftTarget,w3,false,false);
						if (placed)
						{
							yt_builder.showShift(shiftedFrom,w3);
							if (ai != NULL)
								ai->prioritizeTarget(attacker);
						}
						return 1;
					}
				}
			}
		}
	}
	return 0;
	}
}
