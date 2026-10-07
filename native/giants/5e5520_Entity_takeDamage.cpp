//==================================================================
// Entity::takeDamage (0x5e5520, 0xba81 bytes): semantic reconstruction
//==================================================================
// Not byte-matched. Same behaviour as the exe: same callees in the same order (RNG calls included),
// same strings and globals. Notes, open questions and unresolved callees: docs/giants/5e5520.md.
// Callees keep their csv names (or unknown<va> when the exe function is unnamed); members whose
// meaning is not known are unknown<offset>.

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

enum criticalType	// NOTE: placeholder names, from gameStrings_d1e058 (0xd1e058)
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

class Entity;
class Item;
class Prop;
class Cell;
class EntityAI;
struct EntityEffect;
struct EffectPair;
struct EntityRecord;
struct ItemRecord;
struct ExplosionRecord;

struct Point
{
	int x;	// +0x0
	int y;	// +0x4

	Point();					// NOTE: no-op ctor
	Point(int x_, int y_);		// 0x46ca20
	Point(const Point &p);		// 0x46ca50
	int randomInRange_40c130();	// NOTE: placeholder name (0x40c130): rng.rangeInt(x,y), or x when x==y
	Point(int v);				// 0x409990: x = y = v
	Point(const Point &a, const Point &b);	// 0x4099f0: a + b
	Point &operator+=(const Point &p);	// 0x409a30
	bool unknown409cb0(int x_, int y_);	// NOTE: placeholder name (0x409cb0): x == x_ && y == y_
	Point &operator=(const Point &p);	// 0x46ca50 (folded with the copy constructor)
	bool adjacent(const Point &p) const;	// NOTE: placeholder name (PushGeometry::adjacent 0x409dd0)
};

class HEntity
{
public:
	int ID;	// +0x0

	HEntity();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	bool isNull() const;					// 0x9b65d0
	bool operator==(HEntity other) const;	// 0x9b78e0
	bool operator!=(HEntity other) const;	// 0x9b6510
	Entity *operator->() const;				// 0x9b6570
};

class HItem
{
public:
	int ID;	// +0x0

	HItem();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	bool isNull() const;					// 0x9b65d0
	bool operator==(HItem other) const;		// 0x9b78e0
	bool operator!=(HItem other) const;		// 0x9b6510
	Item *operator->() const;				// 0x9b65b0
};

class HProp
{
public:
	int ID;	// +0x0

	HProp();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	bool isNull() const;					// 0x9b65d0
	Prop *operator->() const;				// 0x9b64f0
};

class RNG
{
public:
	bool chance(int percent);			// 0x406c90
	int rangeInt(float a, float b);		// 0x406d70
};

struct OpR3_StatType;	// NOTE: placeholder name (elements of opr3_statTypes, 0xd2f0f8)

struct EntityEffect	// 8 bytes, allocated with new
{
	OpR3_StatType *record;	// +0x0 NOTE: placeholder name
	int value;				// +0x4 NOTE: placeholder name

	EntityEffect(OpR3_StatType *record_, int value_);	// 0x46ca20 (shared body with Point(int,int))
};

struct EntityRecord	// Entity+0x8
{
	int unknown28;	// +0x28 entity class (also read by Entity::getFaction 0x45a2c0)
	int unknown48;	// +0x48 NOTE: placeholder name (robot class, index of gameStrings_d2b4f8)
	int unknown98;	// +0x98 NOTE: placeholder name (size/mass class used by knockback)
	int unknown9C;	// +0x9c NOTE: placeholder name (read by Entity::getSize 0x45a360)

	string getName459c30();	// 0x459c30 (OpR1e_Variant::getName459c30)
};

struct ItemRecord	// Item+0x8; the weapon record passed as 'weapon'
{
	string name;	// +0x24
	int unknown44;	// +0x44 NOTE: placeholder name (item slot/type: 0x17, 0x1a..0x1e are melee weapons)
	int unknown48;	// +0x48 NOTE: placeholder name (0: chain reaction source)
	int unknown70;	// +0x70 NOTE: placeholder name (0x457e90 tests == 2; Blast/Sunder only remove parts with > 1)
	bool unknown75;	// +0x75 NOTE: placeholder name (part immune to Destroy/Smash criticals)
	int unknownF0;	// +0xf0 NOTE: placeholder name (weapon special type, 0xd6: tears parts off for the companion)
	int unknown12C;	// +0x12c NOTE: placeholder name (negative: melee weapon knocks matter out of the target)
	ExplosionRecord *unknown1A0;	// +0x1a0 NOTE: placeholder name (explosion of the item)
	int unknown1A8;	// +0x1a8 NOTE: placeholder name (explosive type created when the part is detonated)

	string getPrefixedName(int *length);	// 0x456fd0 (OpR1e_Named::getPrefixedName)
};

struct ExplosionRecord	// the explosion record passed as 'explosion' (ItemRecord+0x1a0 points to one)
{
	int ID;					// +0x0 NOTE: placeholder name
	string name;			// +0x4
	ItemRecord *unknown20;	// +0x20 NOTE: placeholder name (exploding item)
	struct PropData *unknown24;	// +0x24 NOTE: placeholder name (exploding machine/prop)
	int unknown2c;	// +0x2c NOTE: placeholder name
	int unknown30;	// +0x30 NOTE: placeholder name
	bool unknown80;	// +0x80 NOTE: placeholder name
};

class Item
{
public:
	int unknown457880();				// NOTE: placeholder name (0x457880): data->unknown44 (slot type)
	int unknown457c80();				// NOTE: placeholder name (0x457c80): data->+0xa8 (max integrity)
	int unknown457f90();				// NOTE: placeholder name (0x457f90): data->+0xf0
	int unknown9b6bf0();				// NOTE: placeholder name (ICF'd trivial getter 0x9b6bf0): this->+0x1c (integrity)
	ItemRecord *unknown9b4350();		// NOTE: placeholder name (ICF'd trivial getter 0x9b4350): this->data (+0x8)
	string getName(int a, int b);		// NOTE: placeholder name (0x571db0)
	int unknown4578a0();				// NOTE: placeholder name (0x4578a0): data->+0x48
	bool unknown457cf0();				// NOTE: placeholder name (0x457cf0): +0x28 != -1
	int unknown457fb0();				// NOTE: placeholder name (0x457fb0): data->+0xf4 (share of damage absorbed, percent)
	int unknown44aec0();				// NOTE: placeholder name (ICF'd trivial getter 0x44aec0): this->+0xc
	int unknown577790();				// NOTE: placeholder name (0x577790)
	bool unknown57ab10(int amount, int type, int a, int b, HEntity attacker, int c, int *out);	// NOTE: placeholder name (0x57ab10): damage the item, true when destroyed
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name (0x57dbe0)
	bool unknown457e90();	// NOTE: placeholder name (0x457e90)
	HEntity unknown457b50();	// NOTE: placeholder name (0x457b50): owner (+0x10)
	int unknown577fb0();	// NOTE: placeholder name (0x577fb0): unknown457be0(0x6b)
	void unknown450460(int value);	// NOTE: placeholder name (ICF'd trivial setter 0x450460): this->+0x1c (integrity)
};

class Prop
{
public:
	class Trap *unknown44b020();	// NOTE: placeholder name (0x44b020): trivial getter of +0x4c (ICF)
	bool isPassableFor(HEntity entity);	// NOTE: placeholder name (0x65e1d0)
	int unknown45c630();	// NOTE: placeholder name (0x45c630): data->+0x70
	struct PropData *getData();	// NOTE: placeholder name (0x9b8f00)
	void unknown45ceb0(HEntity attacker, bool flag);	// NOTE: placeholder name (0x45ceb0)
};

class Cell
{
public:
	bool unknown45dc70();	// NOTE: placeholder name (0x45dc70)
	bool unknown45dd40(int value);	// NOTE: placeholder name (0x45dd40)
	HProp getProp();	// 0x45d550
	void removeProp(bool keepTerrain, int cause);	// NOTE: placeholder name (0x66c100)
	bool hasBlockingObject();	// NOTE: placeholder name (0x45d7b0)
	HItem getItem();	// NOTE: placeholder name (0x45d8f0)
	HEntity getEntity();	// NOTE: placeholder name (0x45d250)
	bool canPlaceEntity(int size);	// 0x66ad20
};

class Entity
{
public:
	HEntity self;						// +0x4
	EntityRecord *data;					// +0x8
	vector<Point> positions;			// +0x30 cells occupied
	int integrity;						// +0x8c core integrity
	int energy;							// +0x90 NOTE: placeholder name
	int heat;							// +0x98 NOTE: placeholder name
	bool unknownAC;						// +0xac NOTE: placeholder name (set by a thermal meltdown roll)
	int unknownBC;						// +0xbc
	bool unknownC0;						// +0xc0 NOTE: placeholder name
	vector<EffectPair *> unknownF4;		// +0xf4 (EM damage list)
	vector<EffectPair *> unknown104;	// +0x104 (thermal damage list)
	int unknown120;						// +0x120
	vector<HItem> items;				// +0x134 attached parts
	EntityAI *ai;						// +0x144

	bool isPlayer();								// 0x5c7600
	int unknown5c7fc0(HEntity other);				// NOTE: placeholder name (0x5c7fc0): relation to 'other' (2 = ally?)
	Point unknown45a4c0();							// NOTE: placeholder name (0x45a4c0)
	const Point &getPosition();						// 0x45a4a0
	EntityEffect *unknown45ac40(int type);			// NOTE: placeholder name (0x45ac40)
	int unknown5d22a0(int type);					// NOTE: placeholder name (0x5d22a0)
	HItem unknown5d2380(int type);					// NOTE: placeholder name (0x5d2380)
	bool isHostileTo(HEntity e);					// 0x45aa70
	bool unknown45aaa0(HEntity e);					// NOTE: placeholder name (0x45aaa0): same group as e
	HItem unknown5e3fc0();							// NOTE: placeholder name (0x5e3fc0): pick the part hit by impact damage
	HItem unknown5e3cb0(bool a, int b, int c, int d, int e);	// NOTE: placeholder name (0x5e3cb0): pick the part hit (null = core)
	bool unknown5e4fd0(HItem item, int *amount, int type, int critical, int a7, HEntity attacker);	// NOTE: placeholder name (0x5e4fd0): shielding absorbed the hit
	int unknown5d2090(int type);					// NOTE: placeholder name (0x5d2090)
	int unknown5d2150(int type, int base);			// NOTE: placeholder name (0x5d2150)
	int unknown5cad50();							// NOTE: placeholder name (0x5cad50)
	int unknown5ded70(int amount);					// NOTE: placeholder name (0x5ded70)
	void die(bool a, int cause, HEntity killer, int source, int critical, int d, int e, int f);	// 0x633790 NOTE: placeholder signature
	int takeDamage(int source, ItemRecord *weapon, ExplosionRecord *explosion, int damage, int type, int critical, int a7, bool a8, HEntity attacker, int a10, int a11, int a12, int a13, bool a14);	// 0x5e5520
	void unknown5e5340(bool a, bool b, int c, bool d, int effectIndex, const string &text);	// NOTE: placeholder name (0x5e5340)
	void unknown639950(vector<EffectPair *> *list, HEntity source, int amount);	// NOTE: placeholder name (0x639950)
	void unknown45b340(EntityEffect *effect);	// NOTE: placeholder name (0x45b340): effects.push_back
	void unknown5e40f0(int damage, int type, HEntity attacker, ItemRecord *weapon, int a, int b, int c);	// NOTE: placeholder name (0x5e40f0)
	bool unknown5c7f70();	// NOTE: placeholder name (0x5c7f70)
	unsigned int unknown5d2430(int type, vector<HItem> *out);	// NOTE: placeholder name (0x5d2430)
	const string &unknown416f40();	// NOTE: placeholder name (ICF'd trivial getter 0x416f40): name (+0xc)
	string unknown45a410();	// NOTE: placeholder name (0x45a410): name used in messages
	unsigned int unknown5cb8b0(vector<HItem> *out);	// NOTE: placeholder name (0x5cb8b0)
	void unknown642940(HItem item, bool a, int b, int c, int d);	// NOTE: placeholder name (0x642940): detach a part
	int unknown45a990();	// NOTE: placeholder name (0x45a990): heat (+0x98)
	int unknown45a340();	// NOTE: placeholder name (0x45a340): data->unknown98
	int getSize();	// NOTE: placeholder name (0x45a360)
	int unknown5d1390();	// NOTE: placeholder name (0x5d1390)
	int unknown5cb570(int slot, bool flag);	// NOTE: placeholder name (0x5cb570)
	int unknown5defa0(int amount, bool notify);	// NOTE: placeholder name (0x5defa0): corrupt by amount, returns the corruption applied
	void unknown5e5100(HEntity attacker, int *outValue, bool silent);	// NOTE: placeholder name (0x5e5100)
	bool unknown5c84f0(const Point &p);	// NOTE: placeholder name (0x5c84f0)
	bool unknown5c85a0(const Point &p, bool large);	// NOTE: placeholder name (0x5c85a0)
	bool unknown5c8710(const Point &p);	// NOTE: placeholder name (0x5c8710)
	void unknown5ddac0(const Point &p, bool flag);	// NOTE: placeholder name (0x5ddac0): move to p
	bool unknown5fdd30();	// NOTE: placeholder name (0x5fdd30): false when the entity did not survive
	class HGroup getGroup();	// 0x45a3f0
	class Inventory *getInventory();				// 0x45ad90
	int getFaction();	// 0x45a2c0
	bool unknown5c8820(HEntity other);	// NOTE: placeholder name (0x5c8820)
	HItem unknown5d24e0(int type);	// NOTE: placeholder name (0x5d24e0)
};

struct Area	// NOTE: placeholder name (cell rectangle)
{
	Point min;	// +0x0
	Point max;	// +0x8

	Area();	// 0x40b100: (-1,-1)-(-1,-1)
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	void getRect(const Point &p, int radius, Area &out);	// NOTE: placeholder name (0x9b4430)
};

template <class T>
class WeightedList	// NOTE: placeholder name (weighted random pick; OpR5h_WL in src/op), addresses of this instantiation
{
public:
	vector<T> values;	// +0x0
	vector<int> weights;	// +0x10
	int total;	// +0x20

	WeightedList();	// 0x9ba440
	~WeightedList();	// 0x787710
	void add(T value, int weight);	// 0x9ba0d0
	bool isEmpty();	// 0x9b81b0
	T &pick();	// 0x9ba470
	unsigned int size();	// 0x9b81d0: values.size()
	void reset();	// 0x9c1be0
	vector<T> *getValues();	// NOTE: placeholder name (ICF'd trivial getter): &values
	vector<int> *getWeights();	// NOTE: placeholder name (0x462e10): &weights
	void setWeight(T value, int weight);	// NOTE: placeholder name (0x9ba270 for Point)
};


class EntityAI
{
public:
	void unknown5b39b0(HEntity e);	// NOTE: placeholder name (0x5b39b0)
	void prioritizeTarget(HEntity target);	// 0x5b52f0
};

class OpS4_Xom	// NOTE: placeholder name (object at 0xd25450; Xom = sound/music event system)
{
public:
	bool active;	// +0x0 NOTE: placeholder name

	int unknown69e700(int id, int a, float b);	// NOTE: placeholder name (0x69e700): trigger sound/music event id, returns a value used by R7
	bool unknown69e9b0(const Point &p);	// NOTE: placeholder name (0x69e9b0)
	bool unknown69edf0();	// NOTE: placeholder name (0x69edf0)
	void unknown69ee30(int a, int b, int c);	// NOTE: placeholder name (0x69ee30)
};

class Map
{
public:
	HEntity getPlayer();					// 0x4630f0
	HEntity getEntity671();					// NOTE: placeholder name (0x463110): +0x670
	void unknown464750(int amount);	// NOTE: placeholder name (0x464750): +0x664 += amount
	bool opw3_unknown727780(HEntity e, int *amount);	// NOTE: placeholder name (0x727780): remote shields (item types 70/71) absorb part of *amount
	class HExplosive unknown777a20(class HExplosive h);	// NOTE: placeholder name (0x777a20, OpU5_Level::addRecord in the csv)
	HItem unknown71e7c0(const Point &p, int amount, bool protomatter);	// NOTE: placeholder name (0x71e7c0): create matter at p
	void unknown464840(HItem item);	// NOTE: placeholder name (0x464840)
	bool unknown465200(const Point &a, const Point &b);	// NOTE: placeholder name (0x465200)
	class OpW2_Object *unknown717be0();	// NOTE: placeholder name (0x717be0)
	void unknown735720(HEntity source, HEntity target, bool flag);	// NOTE: placeholder name (0x735720)
	int getTurn();	// 0x464270
	int unknown714b50();	// NOTE: placeholder name (0x714b50)
	void opw3_unknown72f620();	// NOTE: placeholder name (0x72f620)
	void unknown465270(int range, const Point &from, const Point &to, vector<Point> *out);	// NOTE: placeholder name (0x465270): line from -> to
	bool isReachable(int range, const Point &from, const Point &to);	// 0x465230
};

class OpR1h_StatSet	// NOTE: placeholder name (OpR1h_Stats::current)
{
public:
	vector<int> values;	// +0x0 NOTE: placeholder name
};

class OpR1h_Stats	// NOTE: placeholder name (object at 0xd2c658)
{
public:
	OpR1h_StatSet *current;	// +0x0

	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
	int unknown472c70(int id);			// NOTE: placeholder name (0x472c70): current->get(id)
};

class PlayerData	// NOTE: partial (object at 0xcf45d8)
{
public:
	void unknown77fbc0(int id);			// NOTE: placeholder name (0x77fbc0): looks like "unlock achievement id"
	bool isSlotEmpty(unsigned int id);	// NOTE: placeholder name (0x46de40): achievement id not unlocked yet
	bool hasCompanion();				// NOTE: placeholder name (0x780790)
};

class OpU5_MsgConsole	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void unknown8758d0(bool flag);		// NOTE: placeholder name (0x8758d0)
};

class CLogMsgs
{
public:
	void scrollToEnd();					// 0x7b4f10
};

class OpS3e_TurnQueue	// NOTE: placeholder name (object at 0xd225a0)
{
public:
	void unknown672b80(HEntity entity, int delta);	// NOTE: placeholder name (0x672b80): delay the entity's next turn
};

class Trap	// Prop+0x4c (OpR3_PropLink in the csv)
{
public:
	int stasis;	// +0x14 NOTE: placeholder name

	bool unknown65cf80();	// NOTE: placeholder name (0x65cf80)
};

class CMap	// NOTE: partial (object at 0xcec054)
{
public:
	void unknown819500(HEntity e);	// NOTE: placeholder name (0x819500)
};

struct OpR2b_Location	// NOTE: placeholder name
{
	int unknown00;	// +0x0
	int type;		// +0x4 map type
};

class OpR2b_HLocation	// NOTE: placeholder name
{
public:
	int ID;	// +0x0

	OpR2b_Location *operator->() const;	// 0x9b7910
};

class Explosive	// NOTE: placeholder name (0x40-byte object built by 0x515ca0; the exe has vector<HExplosive>)
{
public:
	Explosive(HEntity source, int type, const Point &pos, HEntity b, const Point &c, const Point &d);	// NOTE: placeholder name (0x515ca0)
};

class HExplosive	// NOTE: placeholder name
{
public:
	int ID;	// +0x0

	HExplosive();	// 0x9b6590
};

class OpU5s2_Factory	// NOTE: placeholder name (object at 0xcefaa8)
{
public:
	HExplosive createA(Explosive *explosive);	// 0x7930e0
};

class RolledValues	// NOTE: placeholder name (object at 0xcefb48)
{
public:
	bool say(int ID, bool force, string name);	// 0x49e250
};

class CBD	// NOTE: placeholder name (object at 0xcefc14)
{
public:
	bool canUse(HEntity e, unsigned int record);	// NOTE: placeholder name (0x7ac0e0)
	void unknown7ac1c0(HEntity e, int record, int a, string text);	// NOTE: placeholder name (0x7ac1c0)
};

class OpW2_Object	// NOTE: placeholder name
{
public:
	void unknown45b6b0(HEntity entity, const Point &p);	// NOTE: placeholder name (0x45b6b0)
};

class Group	// NOTE: partial
{
public:
	int unknown9b4350();	// NOTE: placeholder name (ICF'd trivial getter 0x9b4350): +0x8
};

class HGroup
{
public:
	int ID;	// +0x0

	Group *operator->() const;	// 0x9b7250
};

class Effect;	// NOTE: placeholder name
class EffectPool	// NOTE: placeholder name (object at 0xcefc50)
{
public:
	Effect *unknown508610();	// NOTE: placeholder name (0x508610)
};

class Effect	// NOTE: placeholder name
{
public:
	void unknown503b20(EffectPool *pool, int id, const Point &pos, const Point &offset, int a, int b, int c, int d, int e);	// NOTE: placeholder name (0x503b20)
};

class EndTarget1	// NOTE: placeholder name (object at 0xcec138)
{
public:
	void unknown965c10(int a, bool b, bool c);	// NOTE: placeholder name (0x965c10): screen shake/flash effect
};

class Inventory;
struct PropData	// NOTE: placeholder name
{
	string name;	// +0x20
	int unknown8C;	// +0x8c NOTE: placeholder name
	int unknown140;	// +0x140 NOTE: placeholder name
};

class OpU5_SpawnTracker	// NOTE: placeholder name
{
public:
	bool spawn(unsigned int index, bool force, string extra);	// NOTE: placeholder name (0x7aa280)
};

struct OpU5_State	// NOTE: placeholder name (object at 0xcf4ac8)
{
	int unknown00;					// +0x0 NOTE: placeholder name
	int unknown08;					// +0x8 NOTE: placeholder name
	bool unknown0C;					// +0xc NOTE: placeholder name
	vector<int> unknown1C;			// +0x1c NOTE: placeholder name (kills per robot class)
	int unknown2C;					// +0x2c NOTE: placeholder name
	OpU5_SpawnTracker *tracker;		// +0x30

	void increase48b8c0(int amount);	// NOTE: placeholder name (0x48b8c0)
};

struct OpV2_LogEntry	// NOTE: placeholder name
{
	int unknown00;	// +0x0 NOTE: placeholder name
	string text;	// +0x4
	int unknown20;	// +0x20 NOTE: placeholder name
	int turn;		// +0x24 NOTE: placeholder name
};

class OpV2_MessageLog	// NOTE: placeholder name (object at 0xcf1080)
{
public:
	vector<OpV2_LogEntry *> *getEntries();	// NOTE: placeholder name (ICF'd trivial getter 0x9c0790): the log entries (+0x0)
};

class OpY5_Builder	// NOTE: placeholder name (same object as xom, 0xd25450)
{
public:
	bool placeEntityNear(const struct OpY5_Range *range, Point *pos, HEntity e, bool a, bool b);	// NOTE: placeholder name (0x6bd410)
	void showShift(const Point &pos, HEntity e);	// NOTE: placeholder name (0x6bd6d0)
};


//==================================================================
// globals
//==================================================================

extern RNG rng;								// 0xd30908
extern Map *world;							// 0xcefc4c NOTE: placeholder name
extern OpU5_MsgConsole *msgConsole;			// 0xcec058 NOTE: placeholder name
extern CLogMsgs *logMsgs;					// 0xcec0b4 NOTE: placeholder name
extern CLogMsgs *logMsgs2;					// 0xcec0c4 NOTE: placeholder name (second message log)
extern int opr3b_debugLevel;				// 0xd28d18 NOTE: placeholder name (1: also log to logMsgs2)
extern OpR1h_Stats stats;					// 0xd2c658 NOTE: placeholder name
extern PlayerData playerData;				// 0xcf45d8 NOTE: placeholder name
extern int opS2_intCf462c;					// 0xcf462c NOTE: placeholder name
extern Array2D<Cell *> cells;				// 0xcfd44c NOTE: placeholder name
extern OpS4_Xom xom;						// 0xd25450 NOTE: placeholder name
extern string gameStrings_d1e058[];			// 0xd1e058 critical names, indexed by criticalType
extern bool debugGodMode;					// 0xcefb0b NOTE: placeholder name: the player takes no damage
extern bool debugAlwaysHitCore;				// 0xcefb0c NOTE: placeholder name: forces a10 = 1
extern Point impaleTimeLoss;				// 0xd1f384 NOTE: placeholder name: range of the Impale time loss
extern OpS3e_TurnQueue eventQueue;			// 0xd225a0 NOTE: placeholder name
extern vector<OpR3_StatType *> opr3_statTypes;	// 0xd2f0f8 NOTE: placeholder name
extern CMap *mapView;	// 0xcec054 NOTE: placeholder name
extern OpR2b_HLocation opr2b_location;		// 0xd1e888 NOTE: placeholder name
extern int xomExplosionID;					// 0xd254f0 NOTE: placeholder name
extern int xomNoExplosionID;				// 0xcaf154 NOTE: placeholder name
extern bool xomExplosionHitPlayer;			// 0xd254f4 NOTE: placeholder name
extern int unknownCefb38;					// 0xcefb38 NOTE: placeholder name
extern const unsigned char unknownBa0994[];	// 0xba0994 NOTE: placeholder name (indexed by unknownCefb38)
extern const unsigned char unknownB96570[];	// 0xb96570 NOTE: placeholder name (indexed by source: 1 for 7,8,9)
extern OpU5s2_Factory *opU5s2_factory;		// 0xcefaa8 NOTE: placeholder name
extern RolledValues *rolledValues_cefb48;	// 0xcefb48 NOTE: placeholder name
extern CBD *opU5s4_cbd;						// 0xcefc14 NOTE: placeholder name
extern int coreInstakills;					// 0xcf4d28 NOTE: placeholder name (player kills by core instakill, achievement 0x97 at 50)
extern const int unknownB9654c[];			// 0xb9654c NOTE: placeholder name (detonation chance by a12: 0,100,50,30,10)
extern const unsigned char unknownB96560[];	// 0xb96560 NOTE: placeholder name (indexed by source: overflow damage carries over for 7,9,10)
extern const int unknownB96178[];			// 0xb96178 NOTE: placeholder name (meltdown chance by a13: 0,5,25,37,50,80,120)
extern Point impactCorruption;				// 0xd1619c NOTE: placeholder name (corruption range per part lost to impact damage)
extern Point impactCorruptionPlayer;		// 0xd22258 NOTE: placeholder name (same, for the player and class 0x49)
extern const int unknownB96198[];			// 0xb96198 NOTE: placeholder name (meltdown chance bonus by a13)
extern const int unknownB960f0;				// 0xb960f0 NOTE: placeholder name (200: heat for the player's Burn feedback)
extern const int unknownB96108;				// 0xb96108 NOTE: placeholder name (120: same for other robots)
extern const int unknownB962e8[];			// 0xb962e8 NOTE: placeholder name (direction index, one side of a11)
extern const int unknownB96308[];			// 0xb96308 NOTE: placeholder name (direction index, other side of a11)
extern Point unknownD015d8[];				// 0xd015d8 NOTE: placeholder name (direction offsets)
extern bool screenEffects;					// 0xd28d4c NOTE: placeholder name (screen effect option)
extern EndTarget1 *endTarget1;				// 0xcec138
extern EffectPool *effectPool;				// 0xcefc50 NOTE: placeholder name
extern Point effectOffset;					// 0xd2e20c NOTE: placeholder name
extern const int unknownB96114;				// 0xb96114 NOTE: placeholder name (300: heat after an instant meltdown)
extern int unknownCf49f4;					// 0xcf49f4 NOTE: placeholder name
extern OpU5_State *opU5_state;				// 0xcf4ac8 NOTE: placeholder name
extern int opY3_specialMode;				// 0xcf4b38 NOTE: placeholder name (0x1c: ..., then source + 15)
extern string deathCause;					// 0xcf4b3c NOTE: placeholder name
extern PropData *lastAttackingProp;			// 0xcefb7c NOTE: placeholder name
extern int thrownType;						// 0xce9fe0 NOTE: placeholder name (what thrownSource points to)
extern void *thrownSource;					// 0xcefb64 NOTE: placeholder name (PropData, EntityRecord or ItemRecord by thrownType)
extern string gameStrings_d2b4f8[];			// 0xd2b4f8 robot class names
extern int xomExplosionKills;				// 0xd254f8 NOTE: placeholder name
extern const int unknownBbca4c;				// 0xbbca4c NOTE: placeholder name
extern OpV2_MessageLog messageLog;			// 0xcf1080 NOTE: placeholder name
extern vector<ItemRecord *> specialWeapons;	// 0xd1e00c NOTE: placeholder name
extern int specialWeaponKills;				// 0xcf4d60 NOTE: placeholder name (achievement 0xd7 at 20)
extern int class12MeleeKills;				// 0xcf4d90 NOTE: placeholder name (achievement 0x11e at 10)
extern OpY5_Builder builder;				// 0xd25450 NOTE: placeholder name (same object as xom)

bool unknown5111e0(int type, const string *text, const string *text2, int a, HEntity entity, HProp prop, const Point *pos, int flag);	// NOTE: placeholder name (0x5111e0): add a message to the log, true if the console must be refreshed
bool OpT8b_Fn9daf80(int low, int value, int high);	// 0x9daf80: low <= value <= high
int OpX5_maxInt(int a, int b);		// 0x9cdb60
int OpX5_minInt(int a, int b);		// 0x9cdb30
int opR1d_4542a0(const Point &pos, unsigned int sound, unsigned int channel);	// NOTE: placeholder name (0x4542a0): play a sound at pos
void OpV4c_Fn9d0690(int *value, int amount, int minimum);	// 0x9d0690: *value -= amount, not below minimum
void logError(string location, string message);	// NOTE: placeholder name (0x404f10)
void unknown9d9fc0(vector<HItem> &v);	// NOTE: placeholder name (0x9d9fc0, OpV4c_shuffle): shuffle with rng
float OpQ1_distance_40a450(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a450)
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
float unknown4012b0(float value);	// NOTE: placeholder name (0x4012b0): absolute value
bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980): sound ID by name
Point OpU8a_randomPoint(vector<Point> &v);	// NOTE: placeholder name (0x9d5350)
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name (0x9d5190 for Point): erase v[index]
string intToString(int value);	// 0x4051f0
bool OpS1c_unknown4569a0(int id, HEntity a, HEntity b, HProp c, HProp d, int e, int f, Inventory *inventory, HEntity g, HProp h, HProp i, int j);	// NOTE: placeholder name (0x4569a0)
HItem OpX5_randomRecord(vector<HItem> &v);	// 0x9dafb0: random element of v
void unknown9d6440(vector<HItem> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440, OpQ5_eraseStep in the csv): erase v[i], then step i back
bool OpX5_containsRecord(vector<ItemRecord *> &v, ItemRecord *record);	// 0x9db330
void sweepGetSurroundingCells(const Point &point, vector<Point> &adjacent);	// 0x4faaf0
template <class T> void OpV4c_shuffle(vector<T> &v);	// 0x9d7350 for Point: shuffle with rng

// log a message, then keep the message log scrolled to its end
#define LOG_MESSAGE2(type,text,text2,a,entity,prop,pos,flag)	do { if (unknown5111e0(type,text,text2,a,entity,prop,pos,flag)) msgConsole->unknown8758d0(false); logMsgs2->scrollToEnd(); } while (0)
#define LOG_MESSAGE(type,text,text2,a,entity,prop,pos,flag)	do { if (unknown5111e0(type,text,text2,a,entity,prop,pos,flag)) msgConsole->unknown8758d0(true); logMsgs->scrollToEnd(); } while (0)

// critical statistics/achievements when the player scores a critical hit (expanded inline several
// times in the exe), and the usual critical hit message followed by them
#define RECORD_CRITICAL_HIT()	\
	if (attacker.operator->() != NULL && attacker->isPlayer() && !selfIsPlayer)	\
	{	\
		stats.add4729d0(0x196,1,"",-1);	\
		stats.add4729d0(0x196 + critical,1,"",-1);	\
		if (critical == CRITICAL_MELTDOWN && stats.unknown472c70(0x198) >= 10)	\
			playerData.unknown77fbc0(0x96);	\
		if (playerData.isSlotEmpty(0x98))	\
		{	\
			int criticalKinds = 0;	\
			for (int statID = 0x197; statID < 0x1a3; statID++)	\
			{	\
				if (stats.unknown472c70(statID) != 0)	\
					criticalKinds++;	\
			}	\
			if (criticalKinds >= 8)	\
				playerData.unknown77fbc0(0x98);	\
		}	\
	}

#define LOG_CRITICAL_HIT()	\
	{	\
		LOG_MESSAGE(selfIsPlayer ? 0x1b : (unknown5c7fc0(world->getPlayer()) != 2) + 0x1c,&static_cast<const string &>(string(gameStrings_d1e058[critical])),NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);	\
		RECORD_CRITICAL_HIT()	\
	}

//==================================================================
// Entity::takeDamage
//==================================================================

// source:		NOTE: placeholder name; attack source kind (byte table 0xb96570 is 1 for 7,8,9)
// weapon:		record of the weapon/item that caused the damage, or NULL
// explosion:	explosion record that caused the damage, or NULL
// damage:		amount
// type:		damageType
// critical:	criticalType
// attacker:	entity responsible, or a null handle
// returns 0 when no damage was applied; other return values: see docs/giants/5e5520.md
int Entity::takeDamage(int source, ItemRecord *weapon, ExplosionRecord *explosion, int damage, int type, int critical, int a7, bool a8, HEntity attacker, int a10, int a11, int a12, int a13, bool a14)
{
	// locals shared between regions (others are declared where they are used)
	HEntity selfHandle = self;			// [ebp-0xd78]
	bool selfIsPlayer = isPlayer();		// [ebp-0xd71]
	int rawDamage;						// [ebp-0xd7c] damage after the Impale/Intensify criticals
	// declared by region R2 at their point of construction (exe order): int netDamage [ebp-0xd80],
	// HItem hitPart [ebp-0xd84] (part hit, null when the core is hit), int partDamage [ebp-0xd88],
	// int destroyedCount [ebp-0xd6c] (incremented per part destroyed, consumed by the impact case)

	if (selfIsPlayer && debugGodMode)
		return 0;

	if (debugAlwaysHitCore)
		a10 = 1;

	switch (critical)
	{
	case CRITICAL_IMPALE:
		{
			// the target loses time, and so does a melee attacker
			int timeLoss = impaleTimeLoss.randomInRange_40c130();
			eventQueue.unknown672b80(self,timeLoss * 100);
			if (selfIsPlayer)
				world->unknown464750(timeLoss * 100);

			if (attacker.operator->() != NULL && (weapon == NULL || OpT8b_Fn9daf80(0x1a,weapon->unknown44,0x1e)))
			{
				eventQueue.unknown672b80(attacker,timeLoss * 100);
				if (attacker->isPlayer())
					world->unknown464750(timeLoss * 100);
			}
		}
		// fall through: Impale also doubles the damage
	case CRITICAL_INTENSIFY:
		{
			damage *= (critical == CRITICAL_IMPALE) ? 2 : 2;	// NOTE: both multipliers are 2 in the exe

			LOG_CRITICAL_HIT()

			unknown5e5340(a8,selfIsPlayer,4,false,0x1f,string(gameStrings_d1e058[critical]));
		}
		break;
	}

	if (unknown120 != -1 && attacker.operator->() != NULL && attacker->isPlayer())
	{
		unknown120++;
		if (type != DAMAGE_IMPACT || unknown120 > 1)
			unknown120 = -1;
	}

	rawDamage = damage;

	if (ai != NULL && attacker.operator->() != NULL)
		ai->unknown5b39b0(attacker);

	if (!selfIsPlayer && attacker.operator->() != NULL)
	{
		if (type == DAMAGE_THERMAL || type == DAMAGE_EM)
		{
			vector<EffectPair *> *damageList = (type == DAMAGE_THERMAL) ? &unknown104 : &unknownF4;
			unknown639950(damageList,attacker,rawDamage);
		}

		if (data->unknown28 == 0x1b && attacker->isPlayer() && unknown45ac40(0x2e) == NULL)
			unknown45b340(new EntityEffect(opr3_statTypes[0x2e],1));
	}


	if (!a14)
	{
		// count the damage prevented (0x173 for the player, 0x450 for the entity at Map+0x670)
#define RECORD_DAMAGE_PREVENTED()	\
		if (damage < originalDamage)	\
		{	\
			if (isPlayer())	\
			{	\
				stats.add4729d0(0x173,originalDamage - damage,"",-1);	\
				if (stats.current->values[0x173] >= 1500)	\
					playerData.unknown77fbc0(0x8a);	\
			}	\
			else if (self == world->getEntity671())	\
				stats.add4729d0(0x450,originalDamage - damage,"",-1);	\
		}

		int originalDamage = damage;
		int shieldValue;
		if (cells(getPosition())->unknown45dc70())
		{
			damage = (int)(damage * 0.5f);
			mapView->unknown819500(self);
			opR1d_4542a0(self->getPosition(),0xc6,0x15);
			RECORD_DAMAGE_PREVENTED();
			if (damage == 0)
				return 0;
		}
		// shields: absorb a share of the damage, paid with energy
		else if ((shieldValue = unknown5d22a0(0x45)) != 0 && energy >= damage * 75 / 100 * shieldValue)
		{
			OpV4c_Fn9d0690(&energy,damage * 75 / 100 * shieldValue,0);
			damage = (int)(damage * 0.25);
			RECORD_DAMAGE_PREVENTED();
			if (damage == 0)
				return 0;
		}
		else if ((shieldValue = unknown5d22a0(0x44)) != 0 && energy >= damage * 50 / 100 * shieldValue)
		{
			OpV4c_Fn9d0690(&energy,damage * 50 / 100 * shieldValue,0);
			damage = (int)(damage * 0.5);
			RECORD_DAMAGE_PREVENTED();
			if (damage == 0)
				return 0;
		}
		else if ((shieldValue = unknown5d22a0(0x43)) != 0 && energy >= damage * 25 / 100 * shieldValue)
		{
			OpV4c_Fn9d0690(&energy,damage * 25 / 100 * shieldValue,0);
			damage = (int)(damage * 0.75);
			RECORD_DAMAGE_PREVENTED();
			if (damage == 0)
				return 0;
		}
		else if (unknownBC != 0 && unknown5d2380(0x74).isNull())
		{
			damage = (int)(damage * 0.5f);
			mapView->unknown819500(self);
			opR1d_4542a0(self->getPosition(),0xc6,0x15);
			RECORD_DAMAGE_PREVENTED();
			if (damage == 0)
				return 0;
		}
		else
		{
			// a stasis trap under the entity absorbs a quarter of the damage, losing that much stasis
			for (unsigned int posIndex = 0; posIndex < positions.size(); posIndex++)
			{
				if (cells(positions[posIndex])->unknown45dd40(0xb) && cells(positions[posIndex])->getProp()->unknown44b020()->unknown65cf80() && unknown5d2380(0x74).isNull())
				{
					int damageBefore = damage;
					damage = (int)(damage * 0.75f);
					mapView->unknown819500(self);
					opR1d_4542a0(self->getPosition(),0xc6,0x15);
					int absorbed = damageBefore - damage;
					if (absorbed != 0)
					{
						cells(positions[posIndex])->getProp()->unknown44b020()->stasis -= absorbed;
						if (cells(positions[posIndex])->getProp()->unknown44b020()->stasis < 1)
						{
							LOG_MESSAGE(0x224,NULL,NULL,0,HEntity(),HProp(),&positions[posIndex],0);
							cells(positions[posIndex])->removeProp(false,3);
						}
					}
					RECORD_DAMAGE_PREVENTED();
					if (damage == 0)
						return 0;
					goto damageReduced;
				}
			}

			if (world->opw3_unknown727780(self,&damage))
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
					OpV4c_Fn9d0690(&damage,flatReduction,0);
					RECORD_DAMAGE_PREVENTED();
					if (damage == 0)
						return 0;
				}
			}
		}
damageReduced:
		;
#undef RECORD_DAMAGE_PREVENTED
	}

	if (damage == 0)
		return 0;

	if (selfIsPlayer)
		stats.add4729d0(0x171,damage,"",-1);
	else if (self == world->getEntity671())
		stats.add4729d0(0x44d,damage,"",-1);

	// explosions that trigger sound/music events
	if (xom.active && explosion != NULL)
	{
		if (selfIsPlayer)
		{
			if (xomExplosionID != xomNoExplosionID && explosion->ID == xomExplosionID)
				xomExplosionHitPlayer = true;
			else if (explosion->unknown30 >= 500)
			{
				if (explosion->name.find("Dimensional_Slip_Node") != string::npos)
					xom.unknown69e700(0x43,0,0.0f);
				else if (opr2b_location->type == 0x13 && explosion->name.find("Zionite_Power") != string::npos)
					xom.unknown69e700(0x50,0,0.0f);
			}
			else if (explosion->unknown2c == 7 && explosion->name.find("X0") != string::npos)
				xom.unknown69e700(0x44,0,0.0f);
		}

		if (unknown45aaa0(world->getPlayer()))
		{
			switch (opr2b_location->type)
			{
			case 0x1a:
				if (explosion->name.find("ARC_Explode") != string::npos)
					xom.unknown69e700(0x66,0,0.0f);
				break;
			case 0x16:
				if (explosion->name.find("ZHI_Explode") != string::npos)
					xom.unknown69e700(0x68,0,0.0f);
				break;
			}
		}
	}

	int damageToEnergy = unknown5d2090(0x4c);	// [ebp-0xd70] NOTE: placeholder name
	if (damageToEnergy != 0)
		unknown5ded70(damage * damageToEnergy / 100);

	if (a13 != 0 && unknown5d2380(5).isValid())
		a13--;

	int netDamage = damage;
	HItem hitPart;
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
					: ((unknownB96570[source] && attacker.operator->() != NULL && unknown45ac40(0x14) == NULL)
						? OpX5_maxInt(attacker->unknown5d2150(0x60,(type == DAMAGE_PIERCING) ? 8 : 0),attacker->unknown5d22a0(0x61))
						: 0),
				0,0,0);

		if (!a14 && unknown5e4fd0(hitPart,&damage,type,critical,a7,attacker) && critical != CRITICAL_NONE)
		{
			critical = CRITICAL_NONE;
			if (selfIsPlayer)
			{
				stats.add4729d0(0x16e,1,"",-1);
				playerData.unknown77fbc0(0x37);
			}
		}

		if (critical == CRITICAL_DESTROY || critical == CRITICAL_SMASH)
		{
			if (hitPart.isNull() && unknown45ac40(0x15) != NULL)
				goto cancelCritical;

			if (hitPart.isValid()
				&& (self == world->getPlayer() || (data->unknown28 == 0x49 && opS2_intCf462c == 7))
				&& opS2_intCf462c != 6
				&& hitPart->unknown457880() != 0x12
				&& hitPart->unknown9b6bf0() >= hitPart->unknown457c80() * 0.33f)
				goto cancelCritical;

			if (hitPart.isValid() && hitPart->unknown457f90() == 7)
				goto cancelCritical;

			if (hitPart.isValid() && hitPart->unknown9b4350()->unknown75)
				goto cancelCritical;

			if (hitPart.isValid() && hitPart->unknown457880() == 0x12)
				damage = (int)(damage * 1.2f);
			else
			{
				if ((unknown5cad50() == 2 && unknownBa0994[unknownCefb38])
					|| unknown45ac40(0x14) != NULL
					|| (unknown45ac40(0x15) != NULL && !hitPart.isValid()))
					goto cancelCritical;
				damage = -1;	// core destroyed outright
			}

			LOG_CRITICAL_HIT()
			goto criticalChecked;

cancelCritical:
			critical = CRITICAL_NONE;
criticalChecked:
			;
		}
	}

	if (damage >= 200 && attacker.operator->() != NULL && attacker->isPlayer() && !selfIsPlayer && source != 7
		&& (explosion == NULL || !explosion->unknown80))
		playerData.unknown77fbc0(0xdd);

	int destroyedCount = 0;


	if (hitPart.isValid())
	{
		string partName = hitPart->getName(0,0);
		int partSlot = hitPart->unknown457880();
		int overflow = 0;	// damage left over after the part was destroyed

		// some parts detonate when hit (a12 indexes the detonation chance)
		if (a12 != 0 && hitPart->unknown9b4350()->unknown1A8 != 0 && (data->unknown28 != 0 || explosion != NULL)
			&& rng.chance(unknownB9654c[a12]))
		{
			if (hitPart->unknown4578a0() == 0)
			{
				HItem detonationBlocker = unknown5d2380(0x3a);
				if (detonationBlocker.isValid())
				{
					if (selfIsPlayer)
						LOG_MESSAGE(0x1a6,&static_cast<const string &>(detonationBlocker->getName(0,0)),&static_cast<const string &>(hitPart->getName(0,0)),0,self,HProp(),NULL,0);
					goto damagePart;
				}

				int explosiveType = hitPart->unknown9b4350()->unknown1A8;
				LOG_MESSAGE(0x1a5,&static_cast<const string &>(hitPart->getName(0,0)),NULL,0,HEntity(),HProp(),&static_cast<const Point &>(unknown45a4c0()),0);

				if (attacker.operator->() != NULL && attacker->isPlayer())
				{
					stats.add4729d0(0x209,1,"",-1);
					if (stats.unknown472c70(0x209) >= 15)
						playerData.unknown77fbc0(0x9a);
				}

				if (xom.active && selfIsPlayer && attacker.operator->() != NULL && attacker->isPlayer())
					xom.unknown69e700(0xc,0,0.0f);

				hitPart->unknown57dbe0(isPlayer(),isPlayer(),1,1);
				world->unknown777a20(opU5s2_factory->createA(new Explosive(attacker,explosiveType,unknown45a4c0(),HEntity(),Point(-1),Point(-1))));

				if (selfHandle.operator->() == NULL)
					return 2;
			}
		}
		else
		{
damagePart:
			int absorbed = 0;	// damage taken by armor/protection instead of the part
			int selfDamage = 0;	// NOTE: placeholder name; damage turned against the player (part type 0x66)

			if (damage != -1)
			{
				if (selfIsPlayer && opS2_intCf462c == 5)
				{
					absorbed += (hitPart->unknown457880() != 0x12 ? 80 : 40) * damage / 100;
					damage -= absorbed;
					stats.add4729d0(0x175,absorbed,"",-1);
				}
				else if (opS2_intCf462c == 6)
				{
					absorbed += (hitPart->unknown457880() != 0x12 ? 50 : 25) * damage / 100;
					damage -= absorbed;
					stats.add4729d0(0x175,absorbed,"",-1);
				}
				else
				{
					if (hitPart->unknown457f90() == 0x40 && hitPart->unknown457cf0())
					{
						absorbed += hitPart->unknown457fb0() * damage / 100;
						damage -= absorbed;
						stats.add4729d0(0x175,absorbed,"",-1);
					}

					if (unknown5d2380(0x41).isValid())
					{
						vector<HItem> protectors;
						unknown5d2430(0x41,&protectors);
						for (unsigned int protectorIndex = 0; protectorIndex < protectors.size(); protectorIndex++)
						{
							int share = protectors[protectorIndex]->unknown457fb0() * damage / 100;
							absorbed += share;
							damage -= share;
							stats.add4729d0(0x175,share,"",-1);
						}
					}
				}

				if (hitPart->unknown457f90() == 0x66 && selfIsPlayer && (selfDamage = damage / 3) == 0)
					selfDamage++;
			}

			int partIntegrity = hitPart->unknown9b6bf0();
			if (hitPart->unknown57ab10(damage,type,a7,critical,attacker,1,&overflow))
			{
				// part destroyed
				if (selfHandle.operator->() == NULL)
					return 2;

				if (damage == -1 && attacker.operator->() != NULL && attacker->isPlayer() && !selfIsPlayer)
					stats.add4729d0(0x195,1,"",-1);

				destroyedCount++;

				if (attacker.operator->() != NULL && attacker->unknown5c7f70())
					LOG_MESSAGE(0x3e,&partName,NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);

				if (rolledValues_cefb48 != NULL && self == world->getEntity671() && rolledValues_cefb48 != NULL)
					rolledValues_cefb48->say(0x1e,false,partName);

				if (opU5s4_cbd != NULL)
				{
					bool attackerTracked = attacker.operator->() != NULL && opU5s4_cbd->canUse(attacker,6);
					bool selfTracked = opU5s4_cbd->canUse(self,7);
					if (attackerTracked || selfTracked)
					{
						string lostText = "[" + self->unknown416f40() + " lost " + partName + "]";
						LOG_MESSAGE(0x322,&lostText,NULL,0,HEntity(),HProp(),NULL,0);
					}
					if (attackerTracked)
						opU5s4_cbd->unknown7ac1c0(attacker,6,1,partName);
					if (selfTracked)
						opU5s4_cbd->unknown7ac1c0(self,7,1,partName);
				}

				unknown5e5340(a8,selfIsPlayer,1,true,partSlot,"-" + partName);

				if (damage == -1)
				{
					if (critical == CRITICAL_SMASH)
						overflow = partDamage;
					else if (partDamage > partIntegrity)
						overflow = partDamage - partIntegrity;
				}

				// the rest of the damage carries over to other parts (or the core)
				if (overflow != 0 && partSlot != 0x12 && unknownB96560[source])
				{
					WeightedList<HItem> overflowCandidates;
					for (;;)
					{
						HItem overflowPart;
						int overflowRemaining = 0;
						overflowCandidates.reset();
						for (unsigned int itemIndex = 0; itemIndex < items.size(); itemIndex++)
						{
							if (items[itemIndex]->unknown457880() == 0x12 && items[itemIndex]->unknown44aec0() != 4)
								overflowCandidates.add(items[itemIndex],items[itemIndex]->unknown577790());
						}
						overflowPart = overflowCandidates.size() ? overflowCandidates.pick() : ((type == DAMAGE_IMPACT) ? unknown5e3fc0() : unknown5e3cb0(false,0,0,0,0));
						int overflowShielded = 0;

						if (critical == CRITICAL_SMASH && ((!a14 && unknown5e4fd0(overflowPart,&overflowShielded,type,critical,0,attacker))
							|| (overflowPart.isNull() && unknown45ac40(0x15) != NULL)))
							critical = CRITICAL_NONE;
						else
						{
							if (overflowPart.isValid())
							{
								string overflowName = overflowPart->getName(0,0);
								if (overflowPart->unknown57ab10(overflow,type,0,0,attacker,2,&overflowRemaining))
								{
									if (selfHandle.operator->() == NULL)
										return 2;

									if (attacker.operator->() != NULL && attacker->unknown5c7f70())
										LOG_MESSAGE(0x3e,&overflowName,NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);

									destroyedCount++;
								}
							}
							else
								unknown5e40f0(overflow,type,attacker,weapon,0,0,1);

							if (attacker.operator->() != NULL && attacker->isPlayer())
							{
								stats.add4729d0(0x1d8,overflow - overflowRemaining,"",-1);
								switch (source)
								{
								case 7:
									stats.add4729d0(0x1db,overflow - overflowRemaining,"",-1);
									break;
								case 9:
									stats.add4729d0(0x1d9,overflow - overflowRemaining,"",-1);
									break;
								case 10:
									stats.add4729d0(0x1da,overflow - overflowRemaining,"",-1);
									break;
								}
							}
						}

						if (overflowRemaining == 0 || overflowCandidates.size() != 0)
							break;
						overflow = overflowRemaining;
					}
				}
			}
			else if (a13 != 0 && heat >= 250 && ai != NULL && unknown45ac40(0x1e) == NULL && rng.chance(unknownB96178[a13]))
			{
				// the overheated part melts down
				if (attacker.operator->() != NULL && attacker->isPlayer())
				{
					LOG_MESSAGE(0x41,&static_cast<const string &>(hitPart->getName(0,0)),NULL,0,self,HProp(),NULL,0);
					stats.add4729d0(0x204,1,"",-1);
				}
				unknown5e5340(a8,selfIsPlayer,2,true,0x1f,"-" + hitPart->getName(0,0));
				hitPart->unknown57dbe0(0,0,1,1);
			}

			if (absorbed != 0)
				unknown5e40f0(absorbed,type,attacker,weapon,a7,0,0);
			if (selfDamage != 0)
				unknown5e40f0(selfDamage,DAMAGE_ENTROPIC,HEntity(),weapon,0,0,0);
		}
	}
	else
	{
		// core hit
		if (attacker.operator->() != NULL && attacker->isPlayer() && !selfIsPlayer)
			stats.add4729d0(0x193,1,"",-1);

		if (damage == -1)
		{
			if (data->unknown28 == 0x5a)
				logError("Entity::takeDamage()","GM instakilled by " + ((attacker.operator->() != NULL) ? string(attacker->unknown416f40()) : string("UNKNOWN")));

			integrity = 0;
			damage = 0;

			if (attacker.operator->() != NULL && attacker->isPlayer())
			{
				stats.add4729d0(0x194,1,"",-1);
				coreInstakills++;
				if (coreInstakills >= 50)
					playerData.unknown77fbc0(0x97);
			}
		}
		else
			unknown5e40f0(damage,type,attacker,weapon,a7,critical,0);
	}


	switch (critical)
	{
	case CRITICAL_BLAST:
		if (damage > 0)
		{
			HItem blastPart;
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
					if (selfHandle.operator->() == NULL)
						return 2;

					LOG_MESSAGE(selfIsPlayer ? 0x1b : (unknown5c7fc0(world->getPlayer()) != 2) + 0x1c,&static_cast<const string &>(string(gameStrings_d1e058[critical])),NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);

					if (attacker.operator->() != NULL && attacker->isPlayer() && !selfIsPlayer)
					{
						stats.add4729d0(0x196,1,"",-1);
						stats.add4729d0(0x196 + critical,1,"",-1);

						if (critical == CRITICAL_MELTDOWN && stats.unknown472c70(0x198) >= 10)
							playerData.unknown77fbc0(0x96);

						if (playerData.isSlotEmpty(0x98))
						{
							int criticalKinds = 0;
							for (int statID = 0x197; statID < 0x1a3; statID++)
							{
								if (stats.unknown472c70(statID) != 0)
									criticalKinds++;
							}
							if (criticalKinds >= 8)
								playerData.unknown77fbc0(0x98);
						}
					}

					unknown5e5340(a8,selfIsPlayer,1,true,blastSlot,"-" + blastName);

					if (attacker.operator->() != NULL && attacker->unknown5c7f70())
						LOG_MESSAGE(0x3e,&blastName,NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);

					destroyedCount++;
				}
				else if (unknown45ac40(0x13) == NULL && blastPart->unknown9b4350()->unknown70 > 1 && blastPart->unknown457f90() != 7
					&& blastPart->unknown577fb0() == 0 && (opS2_intCf462c != 2 || selfIsPlayer))
				{
					LOG_MESSAGE(selfIsPlayer ? 0x1e : (unknown5c7fc0(world->getPlayer()) != 2) + 0x1f,&blastName,NULL,0,self,HProp(),NULL,0);

					if (attacker.operator->() != NULL && attacker->isPlayer() && !selfIsPlayer)
					{
						stats.add4729d0(0x196,1,"",-1);
						stats.add4729d0(0x196 + critical,1,"",-1);

						if (critical == CRITICAL_MELTDOWN && stats.unknown472c70(0x198) >= 10)
							playerData.unknown77fbc0(0x96);

						if (playerData.isSlotEmpty(0x98))
						{
							int criticalKinds = 0;
							for (int statID = 0x197; statID < 0x1a3; statID++)
							{
								if (stats.unknown472c70(statID) != 0)
									criticalKinds++;
							}
							if (criticalKinds >= 8)
								playerData.unknown77fbc0(0x98);
						}
					}

					if (opr3b_debugLevel == 1)
					{
						string debugText = "  " + (selfIsPlayer ? "" : unknown45a410() + " ") + blastName + " blasted off";
						LOG_MESSAGE2(selfIsPlayer ? 0x2c9 : (unknown5c7fc0(world->getPlayer()) != 2) + 0x2ca,&debugText,NULL,0,self,HProp(),NULL,1);
					}

					if (blastPart->unknown457e90() || unknownC0)
					{
						LOG_MESSAGE(0x45,&blastName,NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);
						blastPart->unknown57dbe0(selfIsPlayer,1,1,1);
						unknown5e5340(a8,selfIsPlayer,1,true,blastSlot,"-" + blastName);
					}
					else
					{
						unknown642940(blastPart,selfIsPlayer,1,0,2);
						unknown5e5340(a8,selfIsPlayer,4,true,0x1f,"-" + blastName);
					}

					if (selfIsPlayer && xom.active)
						xom.unknown69e700(0x10,0,0.0f);
				}
			}
			else if (unknown45ac40(0x15) == NULL)
			{
				// no part to blast off: the core takes the hit
				LOG_MESSAGE(selfIsPlayer ? 0x1b : (unknown5c7fc0(world->getPlayer()) != 2) + 0x1c,&static_cast<const string &>(string(gameStrings_d1e058[critical])),NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);

				if (attacker.operator->() != NULL && attacker->isPlayer() && !selfIsPlayer)
				{
					stats.add4729d0(0x196,1,"",-1);
					stats.add4729d0(0x196 + critical,1,"",-1);

					if (critical == CRITICAL_MELTDOWN && stats.unknown472c70(0x198) >= 10)
						playerData.unknown77fbc0(0x96);

					if (playerData.isSlotEmpty(0x98))
					{
						int criticalKinds = 0;
						for (int statID = 0x197; statID < 0x1a3; statID++)
						{
							if (stats.unknown472c70(statID) != 0)
								criticalKinds++;
						}
						if (criticalKinds >= 8)
							playerData.unknown77fbc0(0x98);
					}
				}

				unknown5e40f0(damage,type,attacker,weapon,0,0,1);
			}
		}
		break;
	case CRITICAL_SUNDER:
		if (unknown45ac40(0x13) == NULL)
		{
			vector<HItem> sundered;
			if (hitPart.isNull())
			{
				// core hit: sunder 1-2 random parts
				vector<HItem> sunderCandidates;
				if (unknown5cb8b0(&sunderCandidates) != 0)
				{
					unknown9d9fc0(sunderCandidates);
					unsigned int candidateIndex = 0;
					for (int sunderCount = rng.rangeInt(1.0f,2.0f); sunderCount > 0 && candidateIndex < sunderCandidates.size(); sunderCount--, candidateIndex++)
						sundered.push_back(sunderCandidates[candidateIndex]);
				}
			}
			else if (hitPart.operator->() != NULL && hitPart->unknown457b50() == self && hitPart->unknown44aec0() < 4)
				sundered.push_back(hitPart);

			if (!sundered.empty())
			{
				bool sunderReported = false;
				for (unsigned int sunderIndex = 0; sunderIndex < sundered.size(); sunderIndex++)
				{
					if (sundered[sunderIndex]->unknown9b4350()->unknown70 > 1 && sundered[sunderIndex]->unknown457f90() != 7
						&& sundered[sunderIndex]->unknown577fb0() == 0 && !sundered[sunderIndex]->unknown9b4350()->unknown75
						&& (opS2_intCf462c != 2 || selfIsPlayer))
					{
						int sunderAbsorbed = 0;
						if (hitPart.isNull() && !a14 && unknown5e4fd0(sundered[sunderIndex],&sunderAbsorbed,type,critical,0,attacker))
						{
							critical = CRITICAL_NONE;
							continue;
						}

						if (!sunderReported)
						{
							LOG_MESSAGE(selfIsPlayer ? 0x1b : (unknown5c7fc0(world->getPlayer()) != 2) + 0x1c,&static_cast<const string &>(string(gameStrings_d1e058[critical])),NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);

							if (attacker.operator->() != NULL && attacker->isPlayer() && !selfIsPlayer)
							{
								stats.add4729d0(0x196,1,"",-1);
								stats.add4729d0(0x196 + critical,1,"",-1);

								if (critical == CRITICAL_MELTDOWN && stats.unknown472c70(0x198) >= 10)
									playerData.unknown77fbc0(0x96);

								if (playerData.isSlotEmpty(0x98))
								{
									int criticalKinds = 0;
									for (int statID = 0x197; statID < 0x1a3; statID++)
									{
										if (stats.unknown472c70(statID) != 0)
											criticalKinds++;
									}
									if (criticalKinds >= 8)
										playerData.unknown77fbc0(0x98);
								}
							}
							sunderReported = true;
						}

						LOG_MESSAGE(selfIsPlayer ? 0x26 : (unknown5c7fc0(world->getPlayer()) != 2) + 0x27,&static_cast<const string &>(sundered[sunderIndex]->getName(0,0)),NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);

						if (sundered[sunderIndex]->unknown457e90() || unknownC0)
						{
							LOG_MESSAGE(0x45,&static_cast<const string &>(sundered[sunderIndex]->getName(0,0)),NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);

							if (opr3b_debugLevel == 1)
							{
								string debugText = "  " + (selfIsPlayer ? "" : unknown45a410() + " ") + sundered[sunderIndex]->getName(0,0) + " disintegrated";
								LOG_MESSAGE2(selfIsPlayer ? 0x2c9 : (unknown5c7fc0(world->getPlayer()) != 2) + 0x2ca,&debugText,NULL,0,self,HProp(),NULL,1);
							}

							unknown5e5340(a8,selfIsPlayer,1,true,sundered[sunderIndex]->unknown457880(),"-" + sundered[sunderIndex]->getName(0,0));
							sundered[sunderIndex]->unknown57dbe0(selfIsPlayer,1,1,1);
						}
						else
						{
							if (opr3b_debugLevel == 1)
							{
								string debugText = "  " + (selfIsPlayer ? "" : unknown45a410() + " ") + sundered[sunderIndex]->getName(0,0) + " knocked off";
								LOG_MESSAGE2(selfIsPlayer ? 0x2c9 : (unknown5c7fc0(world->getPlayer()) != 2) + 0x2ca,&debugText,NULL,0,self,HProp(),NULL,1);
							}

							unknown5e5340(a8,selfIsPlayer,4,true,0x1f,"-" + sundered[sunderIndex]->getName(0,0));
							unknown642940(sundered[sunderIndex],selfIsPlayer,1,0,2);
						}
					}
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
				Point attackerPos(attacker->getPosition());
				Point center(getPosition());
				float baseDistance = OpQ1_distance_40a450(attackerPos,center);
				WeightedList<Point> dropSpots;
				int emptySpots = 0;
				Area area;
				cells.getRect(unknown45a4c0(),2,area);
				for (int x = area.min.x; x <= area.max.x; x++)
				{
					for (int y = area.min.y; y <= area.max.y; y++)
					{
						Point spot(x,y);
						if ((cells(spot)->hasBlockingObject() || (cells(spot)->getItem().isValid() && cells(spot)->getItem()->unknown457880() == 0))
							&& (center.unknown409cb0(x,y) || world->unknown465200(center,spot)))
						{
							// prefer spots away from the attacker
							float distanceGain = OpQ1_distance_40a450(attacker->getPosition(),spot) - baseDistance;
							float distanceFromCenter = OpQ1_distance_40a450(center,spot);
							int weight = (distanceGain < 0.5) ? 10 : 90;
							if (unknown4012b0(distanceGain) >= 2.0)
								weight /= 2;
							if (cells(spot)->getItem().isNull())
								emptySpots++;
							dropSpots.add(spot,weight);
						}
					}
				}

				if (!dropSpots.isEmpty())
				{
					vector<Point> *spots = dropSpots.getValues();
					if (emptySpots < spots->size())
					{
						if (emptySpots > 1)
							emptySpots /= 2;
						for (unsigned int spotIndex = 0; spotIndex < spots->size(); spotIndex++)
						{
							if (cells((*spots)[spotIndex])->getItem().isValid() && cells((*spots)[spotIndex])->getItem()->unknown457880() == 0)
								dropSpots.setWeight((*spots)[spotIndex],(*dropSpots.getWeights())[spotIndex] * emptySpots);
						}
					}

					Point dropSpot(dropSpots.pick());
					if (cells(dropSpot)->getItem().isValid() && cells(dropSpot)->getItem()->unknown457880() == 0)
						cells(dropSpot)->getItem()->unknown450460(cells(dropSpot)->getItem()->unknown9b6bf0() + knockedMatter);
					else
					{
						HItem matter = world->unknown71e7c0(dropSpot,knockedMatter,false);
						if (matter.isValid())
							world->unknown464840(matter);
					}
				}
			}
		}
		goto knockback;

	case DAMAGE_THERMAL:
		if (a13 != 0)
		{
			int heatGain = unknownB96178[a13] * netDamage / rawDamage;
			if (critical == CRITICAL_BURN)
			{
				int burnHeat = heatGain;
				heatGain *= 3;
				string burnText = selfIsPlayer ? gameStrings_d1e058[critical] + ": +" + intToString(burnHeat) : gameStrings_d1e058[critical];
				LOG_MESSAGE(selfIsPlayer ? 0x1b : (unknown5c7fc0(world->getPlayer()) != 2) + 0x1c,&burnText,NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);
				RECORD_CRITICAL_HIT()
				if (unknown45a990() >= (selfIsPlayer ? unknownB960f0 : unknownB96108))
					unknown5e5340(a8,selfIsPlayer,4,false,0x1f,string(gameStrings_d1e058[critical]));
			}

			if (unknown45ac40(0x1e) != NULL)
				heatGain = (int)(heatGain * 0.25f);
			int heatResistance = 100 - unknown5d2090(0x2c);
			int heatAdded = heatGain * heatResistance / 100;
			heat += heatAdded;

			if (attacker.operator->() != NULL)
			{
				if (attacker->isPlayer() && !selfIsPlayer)
					stats.add4729d0(0x205,heatAdded,"",-1);
				else if (selfIsPlayer && !attacker->isPlayer())
					stats.add4729d0(0x1e8,heatAdded,"",-1);
			}

			// meltdown
			if (integrity > 0 && heat >= 250 && ai != NULL && unknown45ac40(0x1e) == NULL
				&& rng.chance((heat - 250) / 20 + unknownB96198[a13]))
			{
				if (rng.chance(50))
					unknownAC = true;
				else
				{
					unknown5e5100(attacker,&source,false);
					if (opr3b_debugLevel == 1)
					{
						string meltdownText = "  " + (unknown45a410() + " instant meltdown");
						LOG_MESSAGE2((unknown5c7fc0(world->getPlayer()) != 2) + 0x2ca,&meltdownText,NULL,0,self,HProp(),NULL,1);
					}
				}
			}
		}
		break;

	case DAMAGE_EM:
		{
			int emResistance = unknown5d2090(0x29);
			if (emResistance == 0)
				emResistance = 1;
			int corrupted = 0;
			if (selfIsPlayer || data->unknown28 == 0x49)
			{
				if (rng.chance(rawDamage / emResistance))
					corrupted = unknown5defa0((critical == CRITICAL_CORRUPT) ? OpX5_maxInt(1,rng.rangeInt(1,10) * rawDamage / 100) : 1,true);
			}
			else
				corrupted = unknown5defa0(((critical == CRITICAL_CORRUPT) ? 150 : rng.rangeInt(50,150)) * rawDamage / 100 / emResistance,true);

			if (corrupted != 0 && critical == CRITICAL_CORRUPT)
			{
				RECORD_CRITICAL_HIT()
				unknown5e5340(a8,selfIsPlayer,4,false,0x1f,string(gameStrings_d1e058[critical]));
			}

			if (selfIsPlayer && screenEffects)
				endTarget1->unknown965c10(damage,source == 10,false);
		}
		break;

	case DAMAGE_IMPACT:
		// every part destroyed by the impact jars the core: corruption
		while (destroyedCount != 0)
		{
			int corruption = (!selfIsPlayer && data->unknown28 != 0x49) ? impactCorruption.randomInRange_40c130() : impactCorruptionPlayer.randomInRange_40c130();
			corruption = unknown5cb570(3,true) * corruption / 100;
			corruption = unknown5defa0(corruption,false);
			if (corruption != 0)
			{
				if (selfIsPlayer)
					LOG_MESSAGE(0xa4,&static_cast<const string &>(intToString(corruption)),NULL,0,self,HProp(),NULL,0);
				else
				{
					LOG_MESSAGE(unknown45aaa0(world->getPlayer()) ? 0xa5 : 0xa6,NULL,NULL,0,self,HProp(),NULL,0);
					if (attacker.operator->() != NULL)
						unknown639950(&unknownF4,attacker,corruption);
				}

				if (!a8)
				{
					int soundID;
					OpU8a_lookup2(string("Part_Destroyed_Corr"),&soundID);
					if (soundID != 0)
						effectPool->unknown508610()->unknown503b20(effectPool,soundID,unknown45a4c0(),effectOffset,0,0,0,9,0);
					if (selfIsPlayer && screenEffects)
						endTarget1->unknown965c10(0x28,false,false);
				}
			}

			if (attacker.operator->() != NULL && attacker->isPlayer())
				stats.add4729d0(0x201,1,"",-1);

			destroyedCount--;
		}

knockback:
		// knockback (kinetic and impact)
		if (integrity > 0 && attacker.operator->() != NULL && data->unknown9C == 1 && a11 != 8 && unknown5d1390() != 0
			&& (unknown5cad50() != 2 || unknownCefb38 != 3))
		{
			int knockbackChance;
			if (type == DAMAGE_IMPACT)
				knockbackChance = rawDamage + (data->unknown98 - attacker->unknown45a340()) * 10;
			else
			{
				knockbackChance = rawDamage - (data->unknown98 - 2) * 10;
				if (attacker.operator->() != NULL)
					knockbackChance += (10 - OpQ1_distanceCeil_40a3f0(attacker->getPosition(),getPosition())) * 5;
				if (source != 9)
					knockbackChance = 0;
			}

			if (rng.chance(knockbackChance))
			{
				Point knockbackPos(positions[0],unknownD015d8[a11]);
				if (unknown5c84f0(knockbackPos))
				{
					HEntity knockedHandle = self;
					HEntity victim;
					int collisionDamage = 0;
					if (unknown5c85a0(knockbackPos,false))
					{
						// another robot is in the way: it may be pushed aside
						victim = cells(knockbackPos)->getEntity();
						if (victim->getSize() == 1 && victim->unknown5d1390() != 0
							&& rng.chance(knockbackChance + (victim->unknown45a340() - data->unknown98) * 10))
						{
							vector<Point> pushSpots;
							pushSpots.push_back(Point(knockbackPos) += unknownD015d8[unknownB962e8[a11]]);
							pushSpots.push_back(Point(knockbackPos) += unknownD015d8[a11]);
							pushSpots.push_back(Point(knockbackPos) += unknownD015d8[unknownB96308[a11]]);
							for (int pushIndex = pushSpots.size() - 1; pushIndex >= 0; pushIndex--)
							{
								if (!victim->unknown5c84f0(pushSpots[pushIndex]) || victim->unknown5c8710(pushSpots[pushIndex]) || victim->unknown5c85a0(pushSpots[pushIndex],false))
									OpQ5_eraseAt(pushSpots,pushIndex);
							}
							if (!pushSpots.empty())
							{
								victim->unknown5ddac0(OpU8a_randomPoint(pushSpots),false);
								if (attacker->isPlayer())
								{
									stats.add4729d0(0x1dc,1,"",-1);
									stats.add4729d0(0x1df,1,"",-1);
								}
								victim->unknown5fdd30();
							}

							collisionDamage = rawDamage;
							if (victim.operator->() != NULL && victim->unknown45a340() > 1)
								collisionDamage /= victim->unknown45a340();
						}
					}

					if (knockedHandle.operator->() == NULL)
					{
						logError("Entity::takeDamage()","Handle already invalid! quitting early during knockback");
						return 2;
					}

					if (!unknown5c85a0(knockbackPos,false))
					{
						if (!unknown5c8710(knockbackPos))
						{
							if (attacker->isPlayer())
							{
								stats.add4729d0(0x1dc,1,"",-1);
								stats.add4729d0(0x1dd + (type != DAMAGE_IMPACT),1,"",-1);
							}
							LOG_MESSAGE(selfIsPlayer ? 0xa2 : 0xa3,NULL,NULL,0,self,HProp(),NULL,0);
							unknown5ddac0(knockbackPos,false);
							OpW2_Object *tracker = world->unknown717be0();
							if (tracker != NULL)
								tracker->unknown45b6b0(self,getPosition());
							if (!unknown5fdd30())
								return 2;
						}
						else if (cells(knockbackPos)->getProp().isValid() && !cells(knockbackPos)->getProp()->isPassableFor(self)
							&& cells(knockbackPos)->getProp()->unknown45c630() != -1 && cells(knockbackPos)->getProp()->unknown45c630() <= rawDamage)
						{
							// knocked through a door/weak prop
							bool propFlag = false;
							bool hostileToAttacker = false;
							if (attacker->isPlayer())
							{
								stats.add4729d0(0x1dc,1,"",-1);
								stats.add4729d0(0x1dd + (type != DAMAGE_IMPACT),1,"",-1);
								propFlag = cells(knockbackPos)->getProp()->getData()->unknown8C != 0;
								hostileToAttacker = isHostileTo(attacker);
							}
							LOG_MESSAGE(selfIsPlayer ? 0xa2 : 0xa3,NULL,NULL,0,self,HProp(),NULL,0);
							cells(knockbackPos)->getProp()->unknown45ceb0(attacker,a8);
							if (propFlag && type == DAMAGE_IMPACT && source == 7 && hostileToAttacker)
								playerData.unknown77fbc0(0x31);
							if (knockedHandle.operator->() == NULL)
								return 2;
							unknown5ddac0(knockbackPos,false);
							OpW2_Object *tracker = world->unknown717be0();
							if (tracker != NULL)
								tracker->unknown45b6b0(self,getPosition());
							if (!unknown5fdd30())
								return 2;
						}
					}

					if (collisionDamage != 0 && victim.operator->() != NULL)
					{
						if (attacker->isPlayer() && weapon != NULL && weapon->unknown44 == 0x17 && type == DAMAGE_KINETIC)
							playerData.unknown77fbc0(0x30);
						victim->takeDamage((source != 8) + 8,weapon,explosion,collisionDamage,DAMAGE_IMPACT,CRITICAL_NONE,0,a8,attacker,0,8,0,0,false);
						if (attacker->isPlayer() && unknown45aaa0(world->getPlayer()) && victim.operator->() != NULL && victim->getGroup()->unknown9b4350() > 2)
							world->unknown735720(attacker,victim,false);
					}
				}
			}
		}
		break;
	}


	if (selfHandle.operator->() == NULL)
	{
		logError("Entity::takeDamage()","Handle already invalid! quitting early");
		return 2;
	}

	if (integrity > 0)
	{
		switch (critical)
		{
		case CRITICAL_MELTDOWN:
			if (selfIsPlayer || (data->unknown28 == 0x49 && opS2_intCf462c == 7))
			{
				// no instant meltdown: heat surge instead
				int heatSurge = netDamage * 10;
				string meltdownText = gameStrings_d1e058[critical] + ": +" + intToString(heatSurge);
				LOG_MESSAGE(selfIsPlayer ? 0x1b : (unknown5c7fc0(world->getPlayer()) != 2) + 0x1c,&meltdownText,NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);
				int heatFactor = 100 - unknown5d2090(0x2c);
				int heatAdded = heatSurge * heatFactor / 100;
				heat += heatAdded;
				if (!attacker->isPlayer())
				{
					if (xom.active && heatAdded >= 300 && heat >= 500 && unknownCf49f4 == 0
						&& unknown5d2380(2).isNull() && unknown5d2380(4).isNull() && unknown5d2380(5).isNull() && unknown5d2380(0x88).isNull())
						xom.unknown69e700(4,0,0.0f);
					stats.add4729d0(0x1e8,heatAdded,"",-1);
				}
				if (opr3b_debugLevel == 1)
				{
					meltdownText = "  " + (selfIsPlayer ? string("Suffered critical hit: ") : unknown45a410() + " critical hit: ") + gameStrings_d1e058[critical];
					if (selfIsPlayer)
						meltdownText += " (+" + intToString(heatAdded) + ")";
					LOG_MESSAGE2(selfIsPlayer ? 0x2c6 : (unknown5c7fc0(world->getPlayer()) != 2) + 0x2c7,&meltdownText,NULL,0,self,HProp(),NULL,1);
				}
			}
			else if (unknown45ac40(0x1e) == NULL)
			{
				LOG_MESSAGE(selfIsPlayer ? 0x1b : (unknown5c7fc0(world->getPlayer()) != 2) + 0x1c,&static_cast<const string &>(string(gameStrings_d1e058[critical])),NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);
				if (heat < unknownB96114)
					heat = unknownB96114;
				unknown5e5100(attacker,&source,true);
				if (attacker.operator->() != NULL && attacker->isPlayer())
					stats.add4729d0(0x194,1,"",-1);
				if (attacker.operator->() != NULL && attacker->isPlayer() && !selfIsPlayer)
				{
					stats.add4729d0(0x196,1,"",-1);
					stats.add4729d0(0x196 + critical,1,"",-1);
					if (critical == CRITICAL_MELTDOWN && stats.unknown472c70(0x198) >= 10)
						playerData.unknown77fbc0(0x96);
					if (playerData.isSlotEmpty(0x98))
					{
						int criticalKinds = 0;
						for (int statID = 0x197; statID < 0x1a3; statID++)
						{
							if (stats.unknown472c70(statID) != 0)
								criticalKinds++;
						}
						if (criticalKinds >= 8)
							playerData.unknown77fbc0(0x98);
					}
				}
			}
			break;

		case CRITICAL_SEVER:
			if (unknown45ac40(0x13) == NULL)
			{
				WeightedList<HItem> severable;
				if (hitPart.isNull())
				{
					for (unsigned int partIndex = 0; partIndex < items.size(); partIndex++)
					{
						if (items[partIndex]->unknown44aec0() != 4 && items[partIndex]->unknown9b4350()->unknown70 > 1
							&& items[partIndex]->unknown457f90() != 7 && items[partIndex]->unknown577fb0() == 0
							&& !items[partIndex]->unknown9b4350()->unknown75 && (opS2_intCf462c != 2 || selfIsPlayer))
							severable.add(items[partIndex],items[partIndex]->unknown577790());
					}
				}
				else if (hitPart.operator->() != NULL && hitPart->unknown9b4350()->unknown70 > 1 && hitPart->unknown457f90() != 7
					&& hitPart->unknown577fb0() == 0 && (opS2_intCf462c != 2 || selfIsPlayer))
					severable.add(hitPart,1);

				if (!severable.isEmpty())
				{
					HItem severed = severable.pick();
					int ignoredAmount = 0;
					if (!a14 && unknown5e4fd0(severed,&ignoredAmount,type,critical,0,attacker))
						critical = CRITICAL_NONE;
					else
					{
						string severedName = severed->getName(0,0);
						int severedSlot = severed->unknown457880();
						LOG_MESSAGE(selfIsPlayer ? 0x42 : (unknown45aaa0(world->getPlayer()) ? 0x43 : 0x44),&static_cast<const string &>(severed->getName(0,0)),NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);
						if (attacker.operator->() != NULL && attacker->isPlayer() && !selfIsPlayer)
						{
							stats.add4729d0(0x196,1,"",-1);
							stats.add4729d0(0x196 + critical,1,"",-1);
							if (critical == CRITICAL_MELTDOWN && stats.unknown472c70(0x198) >= 10)
								playerData.unknown77fbc0(0x96);
							if (playerData.isSlotEmpty(0x98))
							{
								int criticalKinds = 0;
								for (int statID = 0x197; statID < 0x1a3; statID++)
								{
									if (stats.unknown472c70(statID) != 0)
										criticalKinds++;
								}
								if (criticalKinds >= 8)
									playerData.unknown77fbc0(0x98);
							}
						}

						if (severed->unknown457e90() || unknownC0)
						{
							LOG_MESSAGE(0x45,&severedName,NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);
							if (opr3b_debugLevel == 1)
							{
								string severText = "  " + (selfIsPlayer ? string("") : unknown45a410() + " ") + severedName + " disintegrated";
								LOG_MESSAGE2(selfIsPlayer ? 0x2c9 : (unknown5c7fc0(world->getPlayer()) != 2) + 0x2ca,&severText,NULL,0,self,HProp(),NULL,1);
							}
							severed->unknown57dbe0(selfIsPlayer,1,1,1);
							unknown5e5340(a8,selfIsPlayer,1,true,severedSlot,"-" + severedName);
						}
						else
						{
							int severedIntegrity = severed->unknown9b6bf0();
							if (severedIntegrity > 1 && hitPart.isNull())
							{
								int integrityLoss = OpX5_maxInt(1,rng.rangeInt(5,25) * severedIntegrity / 100);
								severed->unknown57ab10(OpX5_minInt(severed->unknown9b6bf0() - 1,integrityLoss),DAMAGE_SLASHING,0,0,HEntity(),1,NULL);
							}
							if (opr3b_debugLevel == 1)
							{
								string severText = "  " + (selfIsPlayer ? string("") : unknown45a410() + " ") + severedName + " severed";
								LOG_MESSAGE2(selfIsPlayer ? 0x2c9 : (unknown5c7fc0(world->getPlayer()) != 2) + 0x2ca,&severText,NULL,0,self,HProp(),NULL,1);
							}
							unknown642940(severed,selfIsPlayer,1,0,2);
							unknown5e5340(a8,selfIsPlayer,4,true,0x1f,"-" + severedName);
							if (attacker.operator->() != NULL
								&& OpS1c_unknown4569a0(0x25,attacker,HEntity(),HProp(),HProp(),0,0,attacker->getInventory(),attacker,HProp(),HProp(),0)
								&& selfHandle.operator->() == NULL)
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
					if (!a14 && unknown5e4fd0(HItem(),&phaseAmount,type,critical,0,attacker))
						critical = CRITICAL_NONE;
					else
					{
						LOG_MESSAGE(selfIsPlayer ? 0x21 : (unknown5c7fc0(world->getPlayer()) != 2) + 0x22,&static_cast<const string &>(string("core")),NULL,0,self,HProp(),NULL,0);

						if (attacker.operator->() != NULL && attacker->isPlayer() && !selfIsPlayer)
						{
							stats.add4729d0(0x196,1,"",-1);
							stats.add4729d0(0x196 + critical,1,"",-1);

							if (critical == CRITICAL_MELTDOWN && stats.unknown472c70(0x198) >= 10)
								playerData.unknown77fbc0(0x96);

							if (playerData.isSlotEmpty(0x98))
							{
								int criticalKinds = 0;
								for (int statID = 0x197; statID < 0x1a3; statID++)
								{
									if (stats.unknown472c70(statID) != 0)
										criticalKinds++;
								}
								if (criticalKinds >= 8)
									playerData.unknown77fbc0(0x98);
							}
						}

						unknown5e5340(a8,selfIsPlayer,4,false,0x1f,string(gameStrings_d1e058[critical]));
						unknown5e40f0(partDamage,type,attacker,weapon,0,0,0);
					}
				}
				else
				{
					HItem phasePart = unknown5e3cb0(false,-1,0,0,0);
					if (phasePart.isValid())
					{
						if ((!a14 && unknown5e4fd0(phasePart,&phaseAmount,type,critical,0,attacker)) || phasePart->unknown9b4350()->unknown75)
							critical = CRITICAL_NONE;
						else
						{
							string phasePartName = phasePart->getName(0,0);
							int phasePartSlot = phasePart->unknown457880();

							LOG_MESSAGE(selfIsPlayer ? 0x21 : (unknown5c7fc0(world->getPlayer()) != 2) + 0x22,&phasePartName,NULL,0,self,HProp(),NULL,0);

							if (attacker.operator->() != NULL && attacker->isPlayer() && !selfIsPlayer)
							{
								stats.add4729d0(0x196,1,"",-1);
								stats.add4729d0(0x196 + critical,1,"",-1);

								if (critical == CRITICAL_MELTDOWN && stats.unknown472c70(0x198) >= 10)
									playerData.unknown77fbc0(0x96);

								if (playerData.isSlotEmpty(0x98))
								{
									int criticalKinds = 0;
									for (int statID = 0x197; statID < 0x1a3; statID++)
									{
										if (stats.unknown472c70(statID) != 0)
											criticalKinds++;
									}
									if (criticalKinds >= 8)
										playerData.unknown77fbc0(0x98);
								}
							}

							if (phasePart->unknown57ab10(partDamage,type,0,0,attacker,1,NULL))
							{
								// the part was destroyed
								if (selfHandle.operator->() == NULL)
									return 2;

								unknown5e5340(a8,selfIsPlayer,1,true,phasePartSlot,"-" + phasePartName);

								if (attacker.operator->() != NULL && attacker->unknown5c7f70())
									LOG_MESSAGE(0x3e,&phasePartName,NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);
							}
							else
								unknown5e5340(a8,selfIsPlayer,4,false,0x1f,string(gameStrings_d1e058[critical]));
						}
					}
				}
			}
			break;

		case CRITICAL_DETONATE:
			{
				vector<HItem> detonateParts;
				if (unknown5cb8b0(&detonateParts))
				{
					for (unsigned int detonateIndex = 0; detonateIndex < detonateParts.size(); detonateIndex++)
					{
						if (detonateParts[detonateIndex]->unknown4578a0() != 0 || detonateParts[detonateIndex]->unknown9b4350()->unknown75)
							unknown9d6440(detonateParts,detonateIndex);
					}
				}

				if (!detonateParts.empty())
				{
					HItem detonatedPart = OpX5_randomRecord(detonateParts);
					HItem detonateBlocker = unknown5d2380(0x3a);
					if (detonateBlocker.isValid())
					{
						if (selfIsPlayer)
							LOG_MESSAGE(0x25,&static_cast<const string &>(detonateBlocker->getName(0,0)),&static_cast<const string &>(detonatedPart->getName(0,0)),0,self,HProp(),NULL,0);
					}
					else
					{
						int explosiveType = detonatedPart->unknown9b4350()->unknown1A8;

						LOG_MESSAGE(0x24,&static_cast<const string &>(detonatedPart->getName(0,0)),NULL,0,HEntity(),HProp(),&static_cast<const Point &>(unknown45a4c0()),0);

						if (attacker.operator->() != NULL && attacker->isPlayer())
							stats.add4729d0(0x195,1,"",-1);

						if (attacker.operator->() != NULL && attacker->isPlayer() && !selfIsPlayer)
						{
							stats.add4729d0(0x196,1,"",-1);
							stats.add4729d0(0x196 + critical,1,"",-1);

							if (critical == CRITICAL_MELTDOWN && stats.unknown472c70(0x198) >= 10)
								playerData.unknown77fbc0(0x96);

							if (playerData.isSlotEmpty(0x98))
							{
								int criticalKinds = 0;
								for (int statID = 0x197; statID < 0x1a3; statID++)
								{
									if (stats.unknown472c70(statID) != 0)
										criticalKinds++;
								}
								if (criticalKinds >= 8)
									playerData.unknown77fbc0(0x98);
							}
						}

						// NOTE: the exe tests the debug level twice here
						if (opr3b_debugLevel == 1)
						{
							if (opr3b_debugLevel == 1)
							{
								string debugText = "  " + (selfIsPlayer ? string("") : unknown45a410() + " ") + detonatedPart->getName(0,0) + " detonated";
								LOG_MESSAGE2(selfIsPlayer ? 0x2c9 : (unknown5c7fc0(world->getPlayer()) != 2) + 0x2ca,&debugText,NULL,0,self,HProp(),NULL,1);
							}
						}

						detonatedPart->unknown57dbe0(isPlayer(),isPlayer(),1,1);
						world->unknown777a20(opU5s2_factory->createA(new Explosive(attacker,explosiveType,unknown45a4c0(),HEntity(),Point(-1),Point(-1))));
					}
				}
			}
			break;
		}
	}

	// weapon 0xd6 tears a part off for the player's companion (the part goes to the spawn tracker)
	if (weapon != NULL && weapon->unknownF0 == 0xd6 && hitPart.operator->() != NULL && hitPart->unknown44aec0() < 4
		&& hitPart->unknown9b4350()->unknown70 > 1 && hitPart->unknown457f90() != 7 && hitPart->unknown577fb0() == 0
		&& !hitPart->unknown9b4350()->unknown75 && (opS2_intCf462c != 2 || selfIsPlayer) && playerData.hasCompanion()
		&& rng.chance(opU5_state->unknown08 / 250 + 3))
	{
		string tornName = hitPart->getName(0,0);
		int tornSlot = hitPart->unknown457880();
		LOG_MESSAGE(selfIsPlayer ? 0x42 : (unknown45aaa0(world->getPlayer()) ? 0x43 : 0x44),&tornName,NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);
		RECORD_CRITICAL_HIT()

		if (hitPart->unknown457e90() || unknownC0)
		{
			LOG_MESSAGE(0x45,&static_cast<const string &>(hitPart->getName(0,0)),NULL,0,self,HProp(),&static_cast<const Point &>(unknown45a4c0()),0);
			if (opr3b_debugLevel == 1)
			{
				string tornText = "  " + (selfIsPlayer ? string("") : unknown45a410() + " ") + tornName + " disintegrated";
				LOG_MESSAGE2(selfIsPlayer ? 0x2c9 : (unknown5c7fc0(world->getPlayer()) != 2) + 0x2ca,&tornText,NULL,0,self,HProp(),NULL,1);
			}
			hitPart->unknown57dbe0(selfIsPlayer,1,1,1);
			unknown5e5340(a8,selfIsPlayer,1,true,tornSlot,"-" + tornName);
		}
		else
		{
			if (opr3b_debugLevel == 1)
			{
				string tornText = "  " + (selfIsPlayer ? string("") : unknown45a410() + " ") + tornName + " severed";
				LOG_MESSAGE2(selfIsPlayer ? 0x2c9 : (unknown5c7fc0(world->getPlayer()) != 2) + 0x2ca,&tornText,NULL,0,self,HProp(),NULL,1);
			}
			unknown642940(hitPart,selfIsPlayer,1,0,2);
			unknown5e5340(a8,selfIsPlayer,4,true,0x1f,"-" + tornName);
			if (attacker.operator->() != NULL
				&& OpS1c_unknown4569a0(0x25,attacker,HEntity(),HProp(),HProp(),0,0,attacker->getInventory(),attacker,HProp(),HProp(),0)
				&& selfHandle.operator->() == NULL)
				return 2;
		}

		if (playerData.hasCompanion())
			opU5_state->tracker->spawn(0xf,false,tornName);
	}

	if (selfHandle.operator->() == NULL)
		return 2;

	if (integrity <= 0)
	{
		// destroyed: record the cause of the player's death
		if (selfIsPlayer && opY3_specialMode == 0x1c)
		{
			if (xom.active)
			{
				int xomEvent = 6;
				switch (source)
				{
				case 3:
					xomEvent = xom.unknown69e700(0x7a,0,0.0f);
					break;
				case 4:
					xomEvent = xom.unknown69e700(0x7d,0,0.0f);
					break;
				case 10:
					if (explosion != NULL && explosion->unknown24 != NULL && explosion->unknown24->unknown140 != 0x10)
						xomEvent = xom.unknown69e700(0x7e,0,0.0f);
					break;
				case 11:
					xomEvent = xom.unknown69e700(0x7e,0,0.0f);
					break;
				}

				if (attacker.operator->() != NULL)
				{
					if (attacker->isPlayer())
						xomEvent = xom.unknown69e700(0x7c,0,0.0f);
					else if (attacker->getFaction() == 0x1d)
						xomEvent = xom.unknown69e700(0x7f,0,0.0f);
				}

				if (xomEvent == 6 && world->unknown714b50() >= 30)
					xom.unknown69e700(0x81,0,0.0f);

				if (xom.unknown69edf0())
				{
					xom.unknown69ee30(1,0,1);
					return 1;
				}
			}

			opY3_specialMode = source + 0xf;
			if (opY3_specialMode >= 0x16)
			{
				if (explosion != NULL && explosion->unknown24 != NULL && explosion->unknown24->unknown140 != 0x10)
					deathCause = "Destroyed by " + explosion->unknown24->name;
				else if (source == 11 && lastAttackingProp != NULL)
					deathCause = "Destroyed by " + lastAttackingProp->name;
				else if (source == 12)
				{
					switch (thrownType)
					{
					case 0:
						deathCause = "Destroyed by thrown " + static_cast<PropData *>(thrownSource)->name;
						break;
					case 1:
						deathCause = "Destroyed by thrown " + static_cast<PropData *>(thrownSource)->name;
						break;
					case 2:
						if (thrownSource == NULL)
							deathCause = "Destroyed when thrown into another robot";
						else
							deathCause = "Destroyed by thrown " + gameStrings_d2b4f8[static_cast<EntityRecord *>(thrownSource)->unknown48];
						break;
					case 3:
						deathCause = "Destroyed by thrown " + static_cast<ItemRecord *>(thrownSource)->name;
						break;
					}
				}
				else if (attacker.operator->() == NULL)
				{
					if (weapon != NULL)
						deathCause = "Destroyed by " + weapon->getPrefixedName(NULL);
					else if (explosion != NULL)
					{
						if (explosion->unknown24 != NULL)
							deathCause = "Destroyed by exploding " + explosion->unknown24->name;
						else if (explosion->unknown20 != NULL)
						{
							deathCause = "Destroyed by " + explosion->unknown20->getPrefixedName(NULL);
							if (explosion->unknown20->unknown48 == 0)
								deathCause += " chain reaction";
						}
					}
				}
				else
				{
					deathCause = attacker->isPlayer() ? string("Destroyed self") : "Destroyed by " + attacker->unknown416f40();
					if (weapon != NULL)
						deathCause += " with " + weapon->getPrefixedName(NULL);
					else if (explosion != NULL)
					{
						if (explosion->unknown20 != NULL)
						{
							deathCause += " with " + explosion->unknown20->getPrefixedName(NULL);
							if (explosion->unknown20->unknown48 == 0)
								deathCause += " chain reaction";
						}
						else if (explosion->unknown24 != NULL)
							deathCause += " via exploding " + explosion->unknown24->name;
					}
				}
			}
		}

		if (xom.active && !selfIsPlayer && explosion != NULL && explosion->unknown24 != NULL && world->getPlayer()->unknown45aaa0(self)
			&& xom.unknown69e9b0(getPosition()) && unknown45ac40(0x3a) == NULL
			&& (attacker.operator->() == NULL || !attacker->isPlayer()))
			xomExplosionKills++;

		// kills of hostile robots with weapon 0xd6, per robot class
		EntityRecord *trackedRecord = NULL;
		if (weapon != NULL && weapon->unknownF0 == 0xd6 && opU5_state != NULL && world->getPlayer()->isHostileTo(self))
		{
			trackedRecord = data;
			opU5_state->unknown1C[trackedRecord->unknown48]++;
		}

		bool hostileToPlayer = world->getPlayer()->isHostileTo(self);
		bool class12 = data->unknown28 == 0x12;	// NOTE: placeholder name
		die(a8,type,attacker,source,critical,0,0,0);

		if (trackedRecord != NULL && opU5_state != NULL)
		{
			if (opU5_state->unknown2C == 0x7a && opU5_state->unknown1C[trackedRecord->unknown48] >= 10 && trackedRecord->unknown48 < 0x79 && rng.chance(2))
			{
				opU5_state->unknown2C = trackedRecord->unknown48;
				if (playerData.hasCompanion())
					opU5_state->tracker->spawn(0x15,false,trackedRecord->getName459c30());
			}
			else if (opU5_state->unknown00 != 0)
			{
				if (playerData.hasCompanion())
					opU5_state->tracker->spawn(0x20,false,trackedRecord->getName459c30());
			}
			else if (!opU5_state->unknown0C)
			{
				opU5_state->increase48b8c0(unknownBbca4c);
				if (playerData.hasCompanion())
					opU5_state->tracker->spawn(4,false,trackedRecord->getName459c30());
			}
		}

		if (playerData.isSlotEmpty(0xdb) && a10 == 1 && messageLog.getEntries()->size() >= 2
			&& (*messageLog.getEntries())[messageLog.getEntries()->size() - 2]->turn == world->getTurn()
			&& ((*messageLog.getEntries())[messageLog.getEntries()->size() - 2]->text.find("core destabilizing") != string::npos
				|| (*messageLog.getEntries())[messageLog.getEntries()->size() - 2]->text.find("core entropy") != string::npos))
			playerData.unknown77fbc0(0xdb);

		if (playerData.isSlotEmpty(0xc3) && explosion != NULL && explosion->unknown20 != NULL && explosion->unknown20->unknown48 == 0)
			world->opw3_unknown72f620();

		if (attacker.operator->() != NULL && attacker->isPlayer())
		{
			if (((playerData.isSlotEmpty(0xd7) && weapon != NULL && OpX5_containsRecord(specialWeapons,weapon))
				|| (explosion != NULL && (specialWeapons[0]->unknown1A0 == explosion || specialWeapons[1]->unknown1A0 == explosion)))
				&& ++specialWeaponKills == 20)
				playerData.unknown77fbc0(0xd7);

			if (playerData.isSlotEmpty(0x11e) && weapon != NULL && class12 && hostileToPlayer && OpT8b_Fn9daf80(0x1a,weapon->unknown44,0x1c)
				&& ++class12MeleeKills == 10)
				playerData.unknown77fbc0(0x11e);
		}
		return 2;
	}

	// survived: a phase shifter (0x4a) may shift the robot out of the attacker's line of fire
	if (damage > 0 && attacker.operator->() != NULL && attacker->isHostileTo(self) && unknown5d2380(0x4a).isValid() && !unknown5c8820(attacker))
	{
		HItem shifter = unknown5d24e0(0x4a);
		if (rng.chance(shifter->unknown457fb0()))
		{
			vector<Point> line;
			world->unknown465270(99,getPosition(),attacker->getPosition(),&line);
			if (cells(line.back())->getEntity().isValid() && cells(line.back())->getEntity() == attacker)
			{
				Point shiftOrigin(-1);
				for (int lineIndex = line.size() - 1; lineIndex >= 0; lineIndex--)
				{
					if (cells(line[lineIndex])->getEntity().isNull() || cells(line[lineIndex])->getEntity() != attacker)
					{
						shiftOrigin = line[lineIndex];
						break;
					}
				}

				if (shiftOrigin.x != -1)
				{
					Point shiftTarget(-1);
					if (cells(shiftOrigin)->canPlaceEntity(getSize()))
						shiftTarget = shiftOrigin;
					else
					{
						vector<Point> around;
						sweepGetSurroundingCells(shiftOrigin,around);
						OpV4c_shuffle(around);
						for (unsigned int aroundIndex = 0; aroundIndex < around.size(); aroundIndex++)
						{
							if (around[aroundIndex].adjacent(shiftOrigin) && cells(around[aroundIndex])->canPlaceEntity(getSize())
								&& world->isReachable(0x1e,getPosition(),around[aroundIndex]))
								shiftTarget = around[aroundIndex];
						}
					}

					if (shiftTarget.x != -1)
					{
						HEntity shifted = self;
						Point shiftedFrom(shifted->getPosition());
						bool placed = builder.placeEntityNear(NULL,&shiftTarget,shifted,false,false);
						if (placed)
						{
							builder.showShift(shiftedFrom,shifted);
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
