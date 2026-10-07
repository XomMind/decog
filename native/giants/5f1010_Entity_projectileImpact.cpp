// Entity::projectileImpact (0x5f1010), semantic reconstruction (not byte-matching) of COGMIND.exe Beta 17.1.
// NOTE: class layouts are partial (only the members this function touches, in offset order, with `// +0xNN`
//	comments); member and method names are placeholders unless they come from the csvs/src.
#include <string>
#include <vector>
using namespace std;

class Entity;
class EntityAI;
class Item;
class Prop;
class Group;
class Cell;
struct EntityData;
struct ItemData;
struct ExplosionData;
struct EntityStatus;
struct Area;
struct EntityEffect;
struct StatSet;
struct TurnRecord;
struct EntityEffectDef;
struct AttackRecord;
struct PropData;
class Dispatch;
struct ItemEffect;
struct Range;
struct MapRecord;
struct EntityTimer;
class MapEvent;
class HMapEvent;
struct PropType;
class PulledObject;
class CPart;
class CParts;
struct EffectData;
class EffectList;
struct SoundSet;
class Object717be0;

//==================================================================
// basic types and handles
//==================================================================

struct Point
{
	int x;
	int y;
	Point();								// 0x453b40 (x = y = -1)
	Point(int v);							// 0x409990 (x = y = v)
	Point(int x_, int y_);					// 0x46ca20
	Point(const Point &p);					// 0x46ca50
	Point(const Point &a, const Point &b);	// 0x4099f0 (sum)
	Point &operator=(const Point &p);		// 0x46ca50 (ICF-folded with the copy ctor)
	Point &operator+=(const Point &p);		// 0x409a30
	bool operator==(const Point &p) const;	// 0x409b90
	bool operator!=(const Point &p) const;	// 0x409bd0
	int randomInRange_40c130();				// NOTE: placeholder name (random value in [x,y])
	bool contains_40c190(int v);	// NOTE: placeholder name
};

class HEntity
{
public:
	int ID;
	HEntity();								// 0x9b6590 (shared by every handle's default ctor)
	Entity *operator->() const;				// 0x9b6570
	bool operator==(HEntity other) const;	// 0x9b78e0
	bool operator!=(HEntity other) const;	// 0x9b6510
	bool isValid() const;					// 0x9b7230 (the exe folds every handle's isValid() into this one)
	bool isNull() const;					// 0x9b65d0
};

class HItem
{
public:
	int ID;
	HItem();								// 0x9b6590
	Item *operator->() const;				// 0x9b65b0
	bool isValid() const;					// 0x9b7230
	bool isNull() const;					// 0x9b65d0
	void clear();							// 0x9b7270
};

class HProp
{
public:
	int ID;
	HProp();								// 0x9b6590
	Prop *operator->() const;				// 0x9b64f0
	bool isValid() const;					// 0x9b7230
	bool isNull() const;					// 0x9b65d0
};

class HGroup
{
public:
	int ID;
	Group *operator->() const;				// 0x9b7250
};

class Group	// NOTE: placeholder layout
{
public:
	int type;								// +0x08, NOTE: placeholder name

	int getType();							// 0x9b4350 (ICF-folded getter, returns +0x8), NOTE: placeholder name
};

template <class T>
class OpR5h_WL	// NOTE: placeholder name (weighted list)
{
public:
	vector<T> values;
	vector<int> weights;
	int total;
	OpR5h_WL();								// 0x9bab50
	~OpR5h_WL();							// (folded with OpR4_TwoVecs::~OpR4_TwoVecs)
	void add(T value, int weight);			// 0x9ba310
	T &pick();								// 0x9ba470
};

//==================================================================
// game objects
//==================================================================

struct EntityData	// NOTE: placeholder name (Entity+0x8)
{
	int ID;									// +0x00, NOTE: placeholder name
	int aiType;								// +0x24, NOTE: placeholder name (Entity::getAiType returns it)
	int faction;							// +0x28, NOTE: placeholder name (Entity::getFaction returns it)
	int unknown48;							// +0x48, NOTE: placeholder name
	SoundSet *sounds;						// +0x90, NOTE: placeholder name
	int unknown98;							// +0x98, NOTE: placeholder name (Entity::unknown45a340 returns it)
	int size;								// +0x9c, NOTE: placeholder name (Entity::getSize returns it)
	int unknownAC;							// +0xac, NOTE: placeholder name

	string getName459c30();					// NOTE: placeholder name
};

struct ItemData	// NOTE: placeholder name (the weapon's item type)
{
	string name;							// +0x24, NOTE: placeholder name
	int kind;								// +0x44, NOTE: placeholder name (Item::getKind 0x457880 returns it)
	int unknown70;							// +0x70, NOTE: placeholder name (index into unknownB9651c)
	int specialType;						// +0xf0, NOTE: placeholder name (special effect: 0x72..0xca)
	int hackMode;							// +0xf4, NOTE: placeholder name
	int unknown118;							// +0x118, NOTE: placeholder name
	Point damage;							// +0x120, NOTE: placeholder name (damage range)
	int damageType;							// +0x128, NOTE: placeholder name
	int heatTransfer;						// +0x12c, NOTE: placeholder name
	int criticalType;						// +0x134, NOTE: placeholder name
	int criticalChance;						// +0x138, NOTE: placeholder name
	int unknown150;							// +0x150, NOTE: placeholder name
	int unknown154;							// +0x154, NOTE: placeholder name
	int unknown158;							// +0x158, NOTE: placeholder name
	int unknown15c;							// +0x15c, NOTE: placeholder name
	bool unknown165;						// +0x165, NOTE: placeholder name
	int unknown16c;							// +0x16c, NOTE: placeholder name
	string unknown174;						// +0x174, NOTE: placeholder name
	int unknown1a0;							// +0x1a0, NOTE: placeholder name
	int unknown1a8;							// +0x1a8, NOTE: placeholder name
	bool unknown1ac;						// +0x1ac, NOTE: placeholder name
	bool unknown1b0;						// +0x1b0, NOTE: placeholder name
	int *unknown278;						// +0x278, NOTE: placeholder name
	int impactSoundMode;					// +0x27c, NOTE: placeholder name
	int impactSound;						// +0x280, NOTE: placeholder name

	int getValue457330(int ID);				// 0x457330, NOTE: placeholder name
};

struct ExplosionData	// NOTE: placeholder name
{
	int damageType;							// +0x2c, NOTE: placeholder name
	int unknown30;							// +0x30, NOTE: placeholder name (knockback impact damage)
	Point hits;								// +0x44, NOTE: placeholder name (range of the number of hits)
	Point knockback;						// +0x4c, NOTE: placeholder name (knockback distance range)
	int heatTransfer;						// +0x58, NOTE: placeholder name
	int unknown5c;							// +0x5c, NOTE: placeholder name
	int unknown60;							// +0x60, NOTE: placeholder name
	int unknown64;							// +0x64, NOTE: placeholder name
	int specialType;						// +0x78, NOTE: placeholder name
	vector<EffectData *> effects;			// +0x9c, NOTE: placeholder name
};

struct EntityStatus	// NOTE: placeholder name (record returned by AsciiImage::unknown57f140)
{
	int expireTurn;							// +0x04, NOTE: placeholder name
	vector<Point> values;					// +0x08, NOTE: placeholder name
	HEntity source;							// +0x18, NOTE: placeholder name

	EntityStatus(int ID_);					// 0x458890
};

class AsciiImage	// NOTE: placeholder name (Entity+0xf0, see src/game/cc_r2_20.cpp)
{
public:
	EntityStatus *unknown458950(int ID);	// NOTE: placeholder name
	EntityStatus *unknown57f140(EntityStatus *status);	// NOTE: placeholder name
};

class EntityAI
{
public:
	void unknown5b39b0(HEntity e);			// NOTE: placeholder name
	bool unknown459090();	// NOTE: placeholder name
	AsciiImage *unknown4590f0();	// NOTE: placeholder name
	int getMode();							// 0x9b4350 (ICF-folded getter, returns +0x8), NOTE: placeholder name
	bool unknown581140();					// NOTE: placeholder name
	bool unknown5b3890(HEntity e, int maxValue);	// NOTE: placeholder name
	void setFollowEntity(HEntity followEntity_, int followParam_);	// 0x5b2f80
	void unknown5b5220();					// NOTE: placeholder name
	int getState();							// 0x9b8f00 (ICF-folded getter, returns +0x4), NOTE: placeholder name
};

class Cell
{
public:
	HProp getProp();						// 0x45d550
	HEntity getEntity();					// 0x45d250
	HItem getItem();						// NOTE: placeholder name (0x45d8f0)
	bool canPlaceEntity(int size);		// NOTE: placeholder name (0x66ad20)
	bool unknown45d480();					// NOTE: placeholder name
	bool unknown45d4e0();					// NOTE: placeholder name
	bool unknown45d500();					// NOTE: placeholder name
	int getArmor();							// 0x66ae70
	void unknown45e110(int a, int b, HEntity e);	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder layout
{
public:
	T &operator()(const Point &p);			// 0x9ced70
	T &operator()(int x, int y);			// 0x9ceda0
	void getBounds(const Point &p, int radius, Area *out);	// NOTE: placeholder name (0x9b4430)
	bool isInBounds(const Point &p);		// NOTE: placeholder name (0x9b43b0)
};

class Prop
{
public:
	const Point &getPosition();	// NOTE: placeholder name (0x4184d0)
	int getState();							// 0x457b10 (ICF-folded getter, returns +0x3c), NOTE: placeholder name
	PropData *getData();					// 0x45cb30 (ICF-folded getter, returns +0x44), NOTE: placeholder name
	PropType *getType();					// 0x9b8f00 (ICF-folded getter, returns +0x4), NOTE: placeholder name
	int unknown45c630();					// NOTE: placeholder name (ICF-folded getter, returns getType()->+0x70)
	void unknown45ce10(bool a, int b, bool c, HEntity d);	// NOTE: placeholder name
	bool isPassableFor(HEntity e);			// NOTE: placeholder name (0x65e1d0)
	void unknown45ceb0(HEntity source, bool flag);	// NOTE: placeholder name
};

class Item
{
public:
	int unknown4578a0();	// NOTE: placeholder name
	ItemData *getData();	// 0x9b4350 (ICF-folded getter, returns +0x8), NOTE: placeholder name
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
	void setBroken(int turn, bool flag);	// NOTE: placeholder argument names
	ItemEffect *getEffect(int type);		// NOTE: placeholder name (0x457b70)
	void setActive(bool active);			// 0x5791a0
	void setActivateOkayTurn(int turn);		// 0x4583b0
	int unknown44aec0();					// NOTE: placeholder name (ICF-folded getter, returns +0xc)
	ItemData *unknown9b4350();				// NOTE: placeholder name (ICF-folded getter, returns +0x8)
	int unknown457820();					// NOTE: placeholder name (ICF-folded getter, returns data->+0x0)
	int unknown4578c0();					// NOTE: placeholder name (ICF-folded getter, returns data->+0x4c)
	int unknown577fb0();					// NOTE: placeholder name (returns getEffectValue(0x6b))
	bool unknown57a190(HEntity entity, int value, bool flag1, bool flag2);	// NOTE: placeholder name
	int unknown457b30();					// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);	// 0x57dbe0
	int getCategory();						// 0x44aec0 (ICF-folded getter, returns +0xc), NOTE: placeholder name
	int getIntegrity();						// 0x9b6bf0 (ICF-folded getter, returns +0x1c), NOTE: placeholder name
	void setIntegrity(int integrity);		// 0x450460 (ICF-folded setter of +0x1c), NOTE: placeholder name
	int unknown457880();					// 0x457880 (ICF-folded getter, returns data->+0x44), NOTE: placeholder name
	int unknown457900();					// 0x457900 (ICF-folded getter, returns data->+0x50), NOTE: placeholder name
	bool unknown457cf0();					// NOTE: placeholder name
	bool unknown457e90();					// NOTE: placeholder name
	int unknown457f90();					// NOTE: placeholder name
	int unknown457fb0();					// NOTE: placeholder name
	void unknown458310(int amount);			// NOTE: placeholder name
	ItemData *getType();					// 0x9b4350 (ICF-folded getter, returns +0x8), NOTE: placeholder name
	bool getUnknown20();					// 0x415ee0 (ICF-folded getter, returns +0x20), NOTE: placeholder name
	int getKind();							// 0x457880 (ICF-folded getter, returns type->+0x44), NOTE: placeholder name
	int unknown577ad0();	// NOTE: placeholder name
	int getEffectValue(int type);			// NOTE: placeholder name (0x457be0)
};

class Entity
{
public:
	HEntity self;							// +0x04
	EntityData *data;						// +0x08
	HGroup group;							// +0x28
	vector<Point> footprint;				// +0x30
	int unknown50;							// +0x50, NOTE: placeholder name
	int target;								// +0x70, NOTE: placeholder name (Entity::getTarget returns it)
	int unknown8c;							// +0x8c, NOTE: placeholder name
	int unknownB4;							// +0xb4, NOTE: placeholder name
	int unknownBC;							// +0xbc, NOTE: placeholder name
	bool unknownC0;							// +0xc0, NOTE: placeholder name
	int unknownC8;							// +0xc8, NOTE: placeholder name
	int unknownD4;							// +0xd4, NOTE: placeholder name
	EffectList *unknownEC;					// +0xec, NOTE: placeholder name
	vector<HItem> items;					// +0x134, NOTE: placeholder name
	EntityAI *ai;							// +0x144

	void projectileImpact(HEntity attacker, int unknownA2, vector<TurnRecord *> *records, ItemData *weapon, float unknownA5, Point *unknownA6, bool unknownA7, ExplosionData *explosion, int *explosionDamage);	// 0x5f1010
	bool isPlayer();						// 0x5c7600
	const Point &getPosition();				// 0x45a4a0
	const string &getNameAt0c();			// NOTE: placeholder name (0x416f40 returns this+0xc, not Entity::getName)
	int getAiType();						// 0x45a2a0
	int getFaction();						// 0x45a2c0
	int getTarget();						// 0x45a760
	HGroup getGroup();						// 0x45a3f0
	AsciiImage *unknown45ae50();			// NOTE: placeholder name
	bool unknown45aaa0(HEntity entity);		// NOTE: placeholder name
	int takeDamage(int source, ItemData *weapon, ExplosionData *explosion, int damage, int damageType, int critical, int unknown7, bool unknown8, HEntity attacker, int unknown10, int direction, int unknown12, int unknown13, int unknown14);	// 0x5e5520, NOTE: placeholder parameter names
	EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	void unknown45b340(EntityEffect *e);	// NOTE: placeholder name
	int unknown45acb0(int type);		// NOTE: placeholder name
	int unknown5c7f10();	// NOTE: placeholder name
	bool unknown5cb680(HGroup g);		// NOTE: placeholder name
	void unknown5fdab0();					// NOTE: placeholder name (clears +0x70/+0x74)
	void changeFaction(HGroup newGroup, bool flag);	// NOTE: placeholder parameter names
	EntityAI *getAI();	// NOTE: placeholder name (0x45b590)
	bool unknown45ae30();	// NOTE: placeholder name
	void unknown45b210(int value);	// NOTE: placeholder name
	unsigned int unknown5cb930(vector<HItem> *out);	// NOTE: placeholder name
	Point unknown45a4c0();					// NOTE: placeholder name
	bool isHostileTo(HEntity entity);		// NOTE: placeholder name (0x45aa70)
	void unknown5e5340(bool a, bool b, int c, bool d, int effectIndex, const string &text);	// NOTE: placeholder name
	void unknown5fd900(int a, int b);		// NOTE: placeholder name
	void unknown6335e0();					// NOTE: placeholder name (0x6335e0)
	void die(bool a, int cause, HEntity killer, bool b, int c, int d, int e, int f);	// 0x633790
	void unknown639730(bool flag);			// NOTE: placeholder name
	void unknown642940(HItem item, bool a, bool b, bool c, int d);	// NOTE: placeholder name
	int getSize();	// 0x45a360
	int unknown5c7d30();	// NOTE: placeholder name
	void changePos(const Point &p, bool flag);	// NOTE: placeholder parameter names
	void unknown5ddac0(const Point &p, int a);	// NOTE: placeholder name
	void unknown5c93d0(vector<int> *out);	// NOTE: placeholder name
	vector<HItem> *getInventoryList();		// 0x45ab00
	int unknown45a340();					// NOTE: placeholder name
	bool unknown5c8820(HEntity other);		// NOTE: placeholder name
	int unknown5d15a0(bool notify);			// NOTE: placeholder name
	Point unknown5c80f0(const Point &toward);	// NOTE: placeholder name
	void unknown5c89d0(vector<Point> *out);	// NOTE: placeholder name
	const string &getName();				// 0x45a280
	int unknown45a810();					// NOTE: placeholder name
	HItem unknown5e3cb0(bool skipFlag, int bonus, vector<int> *excluded, bool c, bool d);	// NOTE: placeholder name
	void unknown637bb0();					// NOTE: placeholder name
	void removeEffectsA(bool onlyInactive);	// NOTE: placeholder name (0x639730)
	int unknown45a8d0();				// NOTE: placeholder name
	void unknown45b1b0(int value);			// NOTE: placeholder name
	unsigned int unknown5cb8b0(vector<HItem> *out);	// NOTE: placeholder name
	void unknown5fd550(HItem item, int turns);	// NOTE: placeholder name
	int unknown5d22a0(int type);			// NOTE: placeholder name
	int unknown5d2150(int type, int base);	// NOTE: placeholder name
	int unknown5d2090(int type);			// NOTE: placeholder name
	HItem unknown5d2380(int type);			// NOTE: placeholder name
	int unknown5d1390();					// NOTE: placeholder name
	bool unknown5e2e60(int *value, int type);	// NOTE: placeholder name
	bool unknown5c8020();					// NOTE: placeholder name
	bool unknown5c84f0(const Point &p);		// NOTE: placeholder name
	bool unknown5c85a0(const Point &p, bool large);	// NOTE: placeholder name
	bool unknown5c8710(const Point &p);		// NOTE: placeholder name
	bool unknown5fdd30();					// NOTE: placeholder name
};

class Map	// NOTE: placeholder name (the world object at 0xcefc4c)
{
public:
	HEntity getPlayer();					// 0x4630f0
	int getTurn();							// 0x464270
	void unknown735720(HEntity source, HEntity target, bool flag);	// NOTE: placeholder name
	HGroup unknown463890(int i);	// NOTE: placeholder name
	HEntity unknown7345f0(HEntity attacker, HEntity target, bool flag);	// NOTE: placeholder name
	void setEntityA7c(HEntity e);	// NOTE: placeholder name
	void unknown464e10(AttackRecord *record);	// NOTE: placeholder name
	vector<vector<Point> > *getMarkers();	// 0x459070 (ICF-folded getter, returns this+0x118), NOTE: placeholder name
	const Point &unknown462f60(HProp prop);	// NOTE: placeholder name
	bool unknown7168e0(const Point &a, const Point &b, Entity *e, vector<Point> *out);	// NOTE: placeholder name
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	bool isVisible(const Point &p);	// NOTE: placeholder name (0x4631c0)
	HEntity getEntity671();	// NOTE: placeholder name (0x463110)
	void unknown4651b0(HEntity entity);	// NOTE: placeholder name
	bool isVisible_4631c0(const Point &p);	// NOTE: placeholder name (csv: BS::isVisible; Map::isVisible is 0x463190)
	bool isReachable(int range, const Point &from, const Point &to);	// NOTE: placeholder name (0x465230)
	void unknown464a00(EntityTimer *timer);	// NOTE: placeholder name
	HMapEvent addRecord(HMapEvent h);	// NOTE: placeholder name (0x777a20)
	bool findPlacement(const Point &p, Point &out, int size);		// 0x71c150
	void unknown730f40(HEntity e);			// NOTE: placeholder name
	void setFlagA74(bool v);				// NOTE: placeholder name
	void unknown749ee0(HEntity source, PulledObject *object, const Point &to, bool flag);	// NOTE: placeholder name
	void unknown6c65a0(HEntity e, const string &text, int value);	// NOTE: placeholder name
	bool unknown748a00(int a, ItemData *weapon);	// NOTE: placeholder name
	static bool turnUpdate_51da30(vector<TurnRecord *> *records, int type, HEntity entity, HEntity other, HEntity unused, int unknown1, int unknown2);	// 0x51da30
	void unknown74b060(const Point &p, int type, int percent);	// NOTE: placeholder name
	Object717be0 *unknown717be0();			// NOTE: placeholder name
};

class RNG
{
public:
	bool chance(int percent);				// 0x406c90
	int rangeInt(float a, float b);			// 0x406d70
};

class StatTracker	// NOTE: placeholder name
{
public:
	StatSet *current;						// +0x00, NOTE: placeholder name

	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
	void add472b90(unsigned int id, int value);	// NOTE: placeholder name (0x472b90)
};

class PlayerData
{
public:
	void unknown77fbc0(int a);				// NOTE: placeholder name
	bool isSlotEmpty(unsigned int index);	// NOTE: placeholder name
	void unknown77ffb0(int a, int b);		// NOTE: placeholder name
	bool hasCompanion();					// NOTE: placeholder name (0x780790)
};

class Audio	// NOTE: placeholder name (object at 0xd25450)
{
public:
	bool enabled;							// +0x00, NOTE: placeholder name
	int unknown9C;							// +0x9c, NOTE: placeholder name

	void unknown69e700(int id, int a, float b);	// NOTE: placeholder name
	bool placeEntityNear(Range *range, Point *pos, HEntity e, bool a, bool b);	// NOTE: placeholder name (0x6bd410)
	bool unknown69edf0();	// NOTE: placeholder name
	void unknown69ee30(int a, int b, int c);	// NOTE: placeholder name
};

class MsgConsole	// NOTE: placeholder name (object at *0xcec058)
{
public:
	void unknown8758d0(bool flag);			// NOTE: placeholder name
};

class CLogMsgs
{
public:
	void scrollToEnd();						// 0x7b4f10
};

struct Area	// NOTE: placeholder name
{
	Point min;
	Point max;
	Area();									// 0x40b100
	Point randomPoint_40be90();				// NOTE: placeholder name
	void getBorder_40bac0(vector<Point> &out);	// NOTE: placeholder name
	void grow_40bc10(int n);				// NOTE: placeholder name
};

struct EntityEffectDef;

struct EntityEffect	// NOTE: placeholder name
{
	EntityEffectDef	*def;					// NOTE: placeholder name
	int				value;					// NOTE: placeholder name
	EntityEffect(EntityEffectDef *def_, int value_);	// 0x46ca20 (ICF-folded with Point::Point(int,int))
};

class EffectInstance	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class EffectMgr	// NOTE: placeholder name (object at *0xcefc50)
{
public:
	EffectInstance *create();				// NOTE: placeholder name (0x508610)
};

class GameData	// NOTE: placeholder name (object at 0xd1e860)
{
public:
	const string &getEntryText(const string &key);	// NOTE: placeholder name (0x46f6d0)
	void setEntryText(const string &key, const string &text);	// NOTE: placeholder name (0x46f700)
	int unknown46f4e0();					// NOTE: placeholder name
};

class CPart
{
public:
	HItem getItem();						// 0x4aeed0 (ICF-folded getter, returns +0x6c), NOTE: placeholder name
	void setUnknown9c(int value);			// 0x450570 (ICF-folded setter of +0x9c), NOTE: placeholder name
	void unknown890710(int a);				// NOTE: placeholder name
};

class CParts	// NOTE: placeholder name (object at *0xcec088)
{
public:
	vector<CPart *> *getParts();			// 0x4a9ad0 (ICF-folded getter, returns this+0x74), NOTE: placeholder name
	CPart *unknown894e70(HItem item);		// NOTE: placeholder name
};

class SpawnTracker	// NOTE: placeholder name
{
public:
	bool spawn(unsigned int index, bool force, string extra);	// NOTE: placeholder name (0x7aa280)
};

struct SpawnState	// NOTE: placeholder name (object at *0xcf4ac8)
{
	int unknown00;							// +0x00, NOTE: placeholder name
	int unknown2c;							// +0x2c, NOTE: placeholder name
	SpawnTracker *tracker;					// +0x30, NOTE: placeholder name
};

//==================================================================
// globals and free functions
//==================================================================

extern Map			*world;					// NOTE: placeholder name (0xcefc4c)
extern RNG			rng;					// 0xd30908
extern StatTracker	statTracker;			// 0xd2c658
extern PlayerData	playerData;				// NOTE: placeholder name (0xcf45d8)
extern Audio		audio;					// NOTE: placeholder name (0xd25450)
extern MsgConsole	*msgConsole;			// NOTE: placeholder name (0xcec058)
extern CLogMsgs		*logMsgs;				// NOTE: placeholder name (0xcec0b4)
extern HEntity		unknownCf69a8;			// NOTE: placeholder name (0xcf69a8)
extern int			hackWeights[0x49][4];	// NOTE: placeholder name (0xb97e60, [hack][hackMode])
extern int			unknownBa5ea4[0xb];		// NOTE: placeholder name (0xba5ea4)
extern Array2D<Cell *> cells;				// NOTE: placeholder name (0xcfd44c)
extern vector<EntityEffectDef *> effectDefs;	// NOTE: placeholder name (0xd2f0f8)
extern EffectMgr	*effectMgr;				// NOTE: placeholder name (0xcefc50)
extern Point		effectOrigin;			// NOTE: placeholder name (0xd2e20c)
extern GameData		gameData;				// NOTE: placeholder name (0xd1e860)
extern CParts		*parts;					// NOTE: placeholder name (0xcec088)
extern SpawnState	*spawnState;			// NOTE: placeholder name (0xcf4ac8)
extern HEntity		player;					// NOTE: placeholder name (0xcf68b8)

bool showMessage(int type, const string *text1, const string *text2, int value, HEntity subject, HEntity object, const Point *pos, int extra);	// NOTE: placeholder name (0x5111e0)
void unknown5141b0(int type, const string *text1, const string *text2, const string *text3, HEntity e, int c);	// NOTE: placeholder name (history log record)
bool findEffectID(const string &name, int *id);	// NOTE: placeholder name (0x9d7980)

// log a message (the exe shows this do-while(0) shape at every call site)
#define MESSAGE(type,text1,text2,value,subject,object,pos,extra)	\
	do { if (showMessage(type,text1,text2,value,subject,object,pos,extra)) msgConsole->unknown8758d0(true); logMsgs->scrollToEnd(); } while (0)


struct AttackRecord	// NOTE: placeholder name (0xc bytes, queued on Map+0x4d0)
{
	HEntity attacker;						// +0x00, NOTE: placeholder name
	HEntity target;							// +0x04, NOTE: placeholder name
	int unknown8;							// +0x08, NOTE: placeholder name

	AttackRecord(HEntity attacker_, HEntity target_) throw();	// 0x460dd0
};

struct StatSet	// NOTE: placeholder name (StatTracker::current)
{
	vector<int> values;						// +0x00, NOTE: placeholder name
};

class Dispatch	// NOTE: placeholder name (0x48 bytes)
{
public:
	Dispatch(HProp source, int type, int strength, int a, int b, int c, int d, HEntity target, int level, const Point &pos, int e, int f);	// NOTE: placeholder name (0x659800)
};

struct PropData	// NOTE: placeholder name (Prop+0x44)
{
	Dispatch *dispatch;						// +0x38, NOTE: placeholder name

	string unknown65cc80();					// NOTE: placeholder name
};

struct AlarmResponse	// NOTE: placeholder name (0xb93fc0, [alert level])
{
	int unknown0;							// +0x00, NOTE: placeholder name
	int unknown4;							// +0x04, NOTE: placeholder name
	int range;								// +0x08, NOTE: placeholder name
	int chance;								// +0x0c, NOTE: placeholder name
	int strength;							// +0x10, NOTE: placeholder name
	int unknown14;							// +0x14, NOTE: placeholder name
};

struct GameState	// NOTE: placeholder name
{
	int unknown4;							// +0x04, NOTE: placeholder name
};

class HGameState	// NOTE: placeholder name
{
public:
	int ID;
	GameState *operator->() const;			// 0x9b7910
};


class Overmind	// NOTE: placeholder name (object at 0xcf6428)
{
public:
	bool unknown68fc40();					// NOTE: placeholder name
};

class MessageLog	// NOTE: placeholder name (object at 0xcf1080)
{
public:
	void setUnknown34(int value);			// 0x451400 (ICF-folded setter, writes +0x34), NOTE: placeholder name
};

class MapView	// NOTE: placeholder name (object at *0xcec054)
{
public:
	void unknown49aee0();					// NOTE: placeholder name
	void unknown8197f0(const Point &pos, bool flag);	// NOTE: placeholder name
};

class RolledValues	// NOTE: placeholder name (object at *0xcefb48)
{
public:
	bool say(int ID, bool force, string name);	// 0x49e250
};

extern bool			unknownB95758[];		// NOTE: placeholder name (0xb95758, indexed by EntityData::unknown48)
extern AlarmResponse alarmResponses[];		// NOTE: placeholder name (0xb93fc0)
extern HGameState	gameState;				// NOTE: placeholder name (0xd1e888)
extern Overmind		overmind;				// NOTE: placeholder name (0xcf6428)
extern MessageLog	messageLog;				// NOTE: placeholder name (0xcf1080)
extern MapView		*mapView;				// NOTE: placeholder name (0xcec054)
extern RolledValues	*rolledValues;			// NOTE: placeholder name (0xcefb48)
extern int			difficulty;				// NOTE: placeholder name (0xcf4718)
extern bool			unknownCf65bf;			// NOTE: placeholder name (0xcf65bf)
extern bool			unknownD28fb0;			// NOTE: placeholder name (0xd28fb0)

int opR1d_454260(const Point &pos, unsigned int sound);	// NOTE: placeholder name
void playSound_4541b0(int sound, int a, int b);	// NOTE: placeholder name
void playSoundAt_4542a0(const Point &pos, int sound, int a);	// NOTE: placeholder name
int pointDistance(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
extern Point		unknownD22268;			// NOTE: placeholder name (0xd22268)
string intToString(int value);	// 0x4051f0
extern Point		unknownD305d8;			// NOTE: placeholder name (0xd305d8, reboot duration range)
extern bool			unknownB9651c[];		// NOTE: placeholder name (0xb9651c, indexed by ItemData+0x70)

string opw8_countString(int count, const string &noun);	// NOTE: placeholder name (0x407a80)
int unknown40a3f0(const Point &a, const Point &b);		// NOTE: placeholder name (distance, rounded up)
void opR1d_4541b0(int sound, int a, int b);	// NOTE: placeholder name (plays a sound)
void unknown9d6440(vector<HItem> &v, int &i);	// NOTE: placeholder name (erases v[i] and steps i back)
void unknown9d9fc0(vector<HItem> &v);		// NOTE: placeholder name (shuffle)

struct Range	// NOTE: placeholder name (a min/max pair)
{
	int min;	// +0x00
	int max;	// +0x04

	Range();	// 0x40bef0
	void set(int min_, int max_);	// 0x40a010
	bool contains_40c190(int v);	// NOTE: placeholder name
};



struct MapRecord	// NOTE: placeholder name (element of mapRecords)
{
	int unknown28;	// +0x28, NOTE: placeholder name
	int unknown4c;	// +0x4c, NOTE: placeholder name
};

extern vector<MapRecord *>	mapRecords;		// NOTE: placeholder name (0xcfd2cc)



class HMapEvent	// NOTE: placeholder name
{
public:
	int ID;
	HMapEvent();	// 0x9b6590
};

class MapEvent	// NOTE: placeholder name (0x40 bytes)
{
public:
	MapEvent(HEntity source, MapRecord *record, const Point &pos, HEntity other, const Point &a, const Point &b);	// NOTE: placeholder name (0x515ca0)
};

class ObjectFactory	// NOTE: placeholder name (object at 0xcefaa8)
{
public:
	HMapEvent createA(MapEvent *event);	// 0x7930e0
};

extern ObjectFactory *objectFactory;	// NOTE: placeholder name (0xcefaa8)

struct EntityTimer	// NOTE: placeholder name (0x10 bytes, queued on Map+0x1ec)
{
	HEntity entity;	// +0x00
	Point position;	// +0x04
	int turns;	// +0x0c

	EntityTimer(HEntity entity_, const Point &position_, int turns_);	// 0x460d00
};



extern int			gameModeCf462c;			// NOTE: placeholder name (0xcf462c)

// instances of one shuffle template (0x9d9fc0 for 4-byte handles, 0x9d8f80 for int)
void shuffle_9d9fc0(vector<HEntity> &v);	// NOTE: placeholder name
void shuffle_9d9fc0(vector<HItem> &v);	// NOTE: placeholder name
void shuffle_9d8f80(vector<int> &v);	// NOTE: placeholder name
void moveElement_9da1f0(vector<HEntity> &v, int from, int to);	// NOTE: placeholder name
bool anyPositive_9d54c0(vector<int> &values);	// NOTE: placeholder name

// history log record (the exe shows this do-while(0) shape at every call site)
#define HISTORY(type,text1,text2,text3,subject,extra)	do { unknown5141b0(type,text1,text2,text3,subject,extra); } while (0)
struct PropType	// NOTE: placeholder name (Prop+0x4)
{
	int unknown8C;							// +0x8c, NOTE: placeholder name
};

class PulledObject	// NOTE: placeholder name (0x20 bytes, an object moved by a tractor beam)
{
public:
	bool unknown1E;							// +0x1e, NOTE: placeholder name

	PulledObject(int type, const Point &pos);	// NOTE: placeholder name (0x500740)
};

class EffectParams	// NOTE: placeholder name (0x64 bytes, OpR2b_Obj500dd0 in src/op/op_r2_b.cpp)
{
public:
	EffectParams(void *info, HEntity source, int a, int range, float b, HEntity c, HEntity d, int e, HEntity f, void *g, int h, PulledObject *object);	// 0x500dd0
};

class UnknownD225a0	// NOTE: placeholder name (object at 0xd225a0)
{
public:
	void unknown6728c0(HEntity e);			// NOTE: placeholder name
};

class UnknownCf68f0	// NOTE: placeholder name (object at *0xcf68f0)
{
public:
	void unknown672f20(HEntity e, int a, int b, string text);	// NOTE: placeholder name
};

extern UnknownD225a0	unknownD225a0;		// NOTE: placeholder name (0xd225a0)
extern UnknownCf68f0	*unknownCf68f0;		// NOTE: placeholder name (0xcf68f0)
extern int			unknownCf68b4;			// NOTE: placeholder name (0xcf68b4)
extern int			unknownCf6954;			// NOTE: placeholder name (0xcf6954, turn of the last player tractor pull)

bool traceSubcellLine(const Point &from, const Point &to, vector<Point> &cells, vector<int> &steps, int subcells);
void shuffle_9d7350(vector<Point> &v);	// NOTE: placeholder name
bool inVector_9d0ce0(vector<Point> &v, Point p);	// NOTE: placeholder name
void appendRange_9d9890(vector<Point> &from, vector<Point> &to, int first, int last);	// NOTE: placeholder name (appends from[first..last])
void fillIndices_9d98e0(vector<Point> &v, vector<int> &indices);	// NOTE: placeholder name (indices 0..v.size()-1)







extern int			gameMode;				// NOTE: placeholder name (0xcf462c)
extern int			unknownCf4730;			// NOTE: placeholder name (0xcf4730)

void logError(string location, string message);	// NOTE: placeholder name
int maxInt(int a, int b);	// 0x9cdb60
HItem unknown9dafb0(vector<HItem> &v);	// NOTE: placeholder name (random element of v)
class ConsoleShake	// NOTE: placeholder name (object at 0xd2f1c8)
{
public:
	void shake(int duration, int delay);	// NOTE: placeholder name
};







extern ConsoleShake	consoleShake;			// NOTE: placeholder name (0xd2f1c8)

void addMessage(int type, HEntity entity, const string &text, int flag);	// NOTE: placeholder name (0x49c610)
void eraseAt(vector<HItem> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440)
HItem randomItem(vector<HItem> &v);	// NOTE: placeholder name (0x9dafb0)

class EffectList	// NOTE: placeholder name (0x14 bytes; OpS1c_RecList in src/op/op_s1c.cpp, also Entity+0xec)
{
public:
	EffectList(vector<EffectData *> list);	// NOTE: placeholder name (0x456280)
	~EffectList();							// 0x4563c0
};

struct SoundSet	// NOTE: placeholder name (EntityData+0x90)
{
	vector<vector<int> > unknown50;			// +0x50, NOTE: placeholder name
};

class Object717be0	// NOTE: placeholder name (returned by Map::unknown717be0)
{
public:
	void unknown45b6b0(HEntity e, const Point &p);	// NOTE: placeholder name
};

extern string		lastDamageTypeName;		// NOTE: placeholder name (0xd1f3d4)
extern int			lastDamage;				// NOTE: placeholder name (0xd1f3f0)
extern string		damageTypeNames[];		// NOTE: placeholder name (0xd323f8)
extern bool			unknownD28f98;			// NOTE: placeholder name (0xd28f98)
extern int			unknownCaed20;			// NOTE: placeholder name (0xcaed20)
extern vector<int>	unknownCf4910;			// NOTE: placeholder name (0xcf4910, indexed by EntityData::ID)
extern int			unknownCf49bc[7];		// NOTE: placeholder name (0xcf49bc, player damage bonus per damage type)
extern float		unknownB949a8[];		// NOTE: placeholder name (0xb949a8, indexed by EntityData::aiType)
extern float		unknownB949b8[];		// NOTE: placeholder name (0xb949b8, indexed by EntityData::aiType)
extern Point		unknownCfd420;			// NOTE: placeholder name (0xcfd420)
extern Point		directionOffsets[];		// NOTE: placeholder name (0xd015d8)
extern int			unknownB962e8[];		// NOTE: placeholder name (0xb962e8, direction turned one way)
extern int			unknownB96308[];		// NOTE: placeholder name (0xb96308, direction turned the other way)

bool unknown4569a0(int id, HEntity a, HEntity b, HProp c, HItem item, int d, const string *name, EffectList *list, HEntity f, HProp g, HItem h, int i);	// NOTE: placeholder name (0x4569a0)
void addCapped_9d06d0(int *value, int delta, int limit);	// NOTE: placeholder name
bool inRange_9daf80(int min, int value, int max);	// NOTE: placeholder name
int minInt(int a, int b);	// 0x9cdb30
int unknown4374c0(const Point &from, const Point &to);	// NOTE: placeholder name (direction from -> to)
int opR1d_454160(const Point &pos, int sound, int volume);	// NOTE: placeholder name (plays a sound at a position)
void logWarning(string location, string message);	// 0x404e50
void lineBresenhamPoints_40ff30(const Point &from, const Point &to, vector<Point> *out);	// NOTE: placeholder name
void eraseAt_9d5190(vector<Point> &v, int index);	// NOTE: placeholder name
Point randomPoint_9d5350(vector<Point> &v);	// NOTE: placeholder name

//==================================================================
// Entity::projectileImpact
//==================================================================

void Entity::projectileImpact(HEntity attacker, int unknownA2, vector<TurnRecord *> *records, ItemData *weapon, float unknownA5, Point *unknownA6, bool unknownA7, ExplosionData *explosion, int *explosionDamage)
{
	bool isPlayerSelf = isPlayer();
	if (ai != NULL && attacker.operator->() != NULL && (weapon == NULL || weapon->specialType != 0x77))
	{
		ai->unknown5b39b0(attacker);
		world->unknown735720(attacker,self,true);
	}

	if (weapon != NULL)
	{
		switch (weapon->specialType)
		{
		case 0x72:
			if (unknown45ac40(0x32) == NULL)
				unknown45b340(new EntityEffect(effectDefs[0x32],1));
			MESSAGE(isPlayerSelf ? 0x39 : 0x3a,NULL,NULL,0,self,HEntity(),NULL,0);
			if (attacker.operator->() != NULL && attacker->isPlayer())
				unknown5141b0(0x68,&getNameAt0c(),NULL,0,HEntity(),0);
			opR1d_454260(getPosition(),0x117);
			break;
		case 0x77:
			if (attacker.operator->() != NULL && attacker->isPlayer())
			{
				bool resolved = false;
				if (data->unknownAC == 0)
				{
					bool allied = unknown45aaa0(world->getPlayer());
					if (target == 3 || target == 4 || (allied && target == 1))
					{
						resolved = true;
						int chance = allied ? 100 : attacker->unknown5c7f10() / 2 + 50;
						if (rng.chance(chance))
						{
							if (allied)
							{
								MESSAGE(0x82,NULL,NULL,0,self,HEntity(),NULL,0);
								unknown5fdab0();
							}
							else
							{
								MESSAGE(0x8b,NULL,NULL,0,self,HEntity(),NULL,0);
								if (unknownB95758[data->unknown48])
									unknown5141b0(0x15,&getNameAt0c(),NULL,0,HEntity(),0);
								unknown5fdab0();
								changeFaction(world->unknown463890(1),true);
								playSound_4541b0(0x6b,0,0);
								statTracker.add4729d0(0x37a,1,string(""),-1);
								playerData.unknown77fbc0(0x63);
							}
							if (unknownA2 == 0)
								mapView->unknown49aee0();
							return;
						}
						MESSAGE(0x83,NULL,NULL,0,self,HEntity(),NULL,0);
					}
				}
				if (!resolved)
				{
					int chance = weapon->hackMode;
					if (ai != NULL && ai->getMode() < 2)
						chance += 20;
					if (rng.chance(chance))
					{
						if (data->unknownAC == 2 || self == unknownCf69a8)
							MESSAGE(0x1f1,NULL,NULL,0,self,HEntity(),NULL,0);
						else
						{
							HEntity hacked = world->unknown7345f0(attacker,self,weapon->kind == 0x1d);
							if (hacked.isValid())
							{
								MESSAGE(0x1e2,NULL,NULL,0,hacked,HEntity(),&getPosition(),0);
								playSound_4541b0(0x69,0,0);
							}
							else
								world->setEntityA7c(self);
						}
					}
					else
					{
						MESSAGE(0x1f0,&weapon->name,NULL,0,self,HEntity(),NULL,0);
						playSound_4541b0(0x66,0,0);
					}
				}
			}
			break;
		case 0x78:	// hacking
			if (attacker.operator->() != NULL)
			{
				switch (weapon->hackMode)
				{
				case 0:
					if (attacker->isPlayer())
						MESSAGE(0x1fa,NULL,NULL,0,self,HEntity(),NULL,0);
					else
						MESSAGE(0x1fb,NULL,NULL,0,self,HEntity(),&attacker->getPosition(),0);
					break;
				case 2:
					if (attacker->isPlayer())
						MESSAGE(0x1ff,NULL,NULL,0,self,HEntity(),NULL,0);
					else
						MESSAGE(0x200,NULL,NULL,0,self,attacker,NULL,0);
					break;
				case 3:
					if ((data->aiType == 0 && data->faction != 0) || !rng.chance(weapon->getValue457330(0x7e)))
						goto hackDone;
					goto hackStart;
				}

				if (data->unknownAC == 2 || getTarget() != 0 || self == unknownCf69a8)
				{
					if (attacker->isPlayer() && weapon->hackMode != 1)
						MESSAGE(0x1f1,NULL,NULL,0,self,HEntity(),NULL,0);
				}
				else if (getAiType() == 1 && getGroup()->getType() == 3 && (getFaction() == 6 || getFaction() == 0xd || getFaction() == 0xe || getFaction() == 0x10 || getFaction() == 0x11 || getFaction() == 0x12 || getFaction() == 0x15 || getFaction() == 0x16 || getFaction() == 0x17 || getFaction() == 0x18 || getFaction() == 0x1a || getFaction() == 0x1c))
				{
				hackStart:
					OpR5h_WL<int> hacks;
					if (weapon->hackMode != 3)
					{
						for (int i = 0; i < 0x49; i++)
							hacks.add(i,hackWeights[i][weapon->hackMode]);
					}
					if (weapon->hackMode == 2 || weapon->hackMode == 3)
					{
						for (int i = 0; i < 0xb; i++)
							hacks.add(i,unknownBa5ea4[i]);
					}
				pickHack:
					int hack = hacks.pick();
					while (hack == 0x3e && !attacker->isPlayer())
						hack = hacks.pick();

					HEntity target = self;
					EntityStatus *status = NULL;
					switch (hack)
					{
					case 0x3a:
						if (target->getAI()->unknown459090() && target->getAI()->unknown4590f0()->unknown458950(0x3a) != NULL)
						{
							MESSAGE(0x1fc,&string("Found active disruption routine."),NULL,0,target,HEntity(),NULL,0);
							goto hackDone;
						}
						target->getAI()->unknown4590f0()->unknown57f140(new EntityStatus(0x3a));
						MESSAGE(0x1fc,&string("Initiated network disruption routine."),NULL,0,target,HEntity(),NULL,0);
						world->unknown4651b0(target);
						break;
					case 0x3b:
						{
							HItem powerSource;
							vector<HItem> items;
							target->unknown5cb930(&items);
							for (unsigned int i = 0; i < items.size(); i++)
							{
								if (items[i]->unknown4578a0() == 0)
								{
									powerSource = items[i];
									goto tweakPower;
								}
							}
							if (weapon->hackMode != 1)
								MESSAGE(0x1fd,&string("Unable to locate active power source."),NULL,0,target,HEntity(),NULL,0);
							goto hackDone;

						tweakPower:
							MESSAGE(0x1fc,&string("Tweaking power source heat flow."),NULL,0,self,HEntity(),NULL,0);
							if (rng.chance(50))
							{
								MESSAGE(0x1f6,&string("[name] %2 breaks down."),&powerSource->getName(0,0),0,target,HEntity(),NULL,0);
								powerSource->setBroken(-2,false);
							}
							target->unknown45b210(250);
						}
						break;
					case 0x3c:
						if (target->unknown45ae30() && target->unknown45ae50()->unknown458950(0x3c) != NULL)
						{
							if (weapon->hackMode != 1)
								MESSAGE(0x1fd,&string("Found active overload routine."),NULL,0,target,HEntity(),NULL,0);
							goto hackDone;
						}
						{
							HItem powerSource;
							vector<HItem> items;
							target->unknown5cb930(&items);
							for (unsigned int i = 0; i < items.size(); i++)
							{
								if (items[i]->unknown4578a0() == 0 && items[i]->getData()->unknown1a8 != 0)
								{
									powerSource = items[i];
									goto overloadPower;
								}
							}
							if (weapon->hackMode != 1)
								MESSAGE(0x1fd,&string("Unable to locate active power source."),NULL,0,target,HEntity(),NULL,0);
							goto hackDone;

						overloadPower:
							int turns = unknownD22268.randomInRange_40c130();
							status = target->unknown45ae50()->unknown57f140(new EntityStatus(0x3c));
							status->expireTurn = world->getTurn() + turns;
							status->source = attacker;
							string text = "Initiated overload sequence, T-" + intToString(turns) + " to critical power.";
							MESSAGE(0x1fc,&text,NULL,0,target,HEntity(),NULL,0);
						}
						break;
					case 0x3d:
						if (target->unknown45ae30() && target->unknown45ae50()->unknown458950(0x3d) != NULL)
						{
							if (weapon->hackMode != 1)
								MESSAGE(0x1fd,&string("Found active resonance routine."),NULL,0,target,HEntity(),NULL,0);
							goto hackDone;
						}
						{
							HItem powerSource;
							vector<HItem> items;
							target->unknown5cb930(&items);
							for (unsigned int i = 0; i < items.size(); i++)
							{
								if (items[i]->unknown4578a0() == 0 && items[i]->getData()->unknown1a8 != 0)
								{
									powerSource = items[i];
									goto amplifyPower;
								}
							}
							if (weapon->hackMode != 1)
								MESSAGE(0x1fd,&string("Unable to locate active power source."),NULL,0,target,HEntity(),NULL,0);
							goto hackDone;

						amplifyPower:
							status = target->unknown45ae50()->unknown57f140(new EntityStatus(0x3d));
							status->source = attacker;
							string text = "Amplifying resonance, compromised power stability.";
							MESSAGE(0x1fc,&text,NULL,0,target,HEntity(),NULL,0);
						}
						break;
					case 0x3e:
						MESSAGE(0x1fc,&string("Installed hostile record filter."),NULL,0,target,HEntity(),NULL,0);
						if (target->getAI()->unknown5b3890(world->getPlayer(),0))
							MESSAGE(0x1fc,&string("Deleted hostile record."),NULL,0,target,HEntity(),NULL,0);
						status = target->getAI()->unknown4590f0()->unknown57f140(new EntityStatus(0x3e));
						status->expireTurn = world->getTurn() + 10;
						break;
					case 0x3f:
						{
							vector<HItem> weapons;
							target->unknown5cb930(&weapons);
							for (int i = 0; i < weapons.size(); i++)
							{
								if (weapons[i]->unknown4578a0() != 3)
									unknown9d6440(weapons,i);
							}
							if (weapons.empty())
							{
								if (weapon->hackMode != 1)
									MESSAGE(0x1fd,&string("Unable to locate active weapons."),NULL,0,target,HEntity(),NULL,0);
								goto hackDone;
							}
							string text = "Deactivating " + opw8_countString(weapons.size(),"weapon system") + ".";
							MESSAGE(0x1fc,&text,NULL,0,target,HEntity(),NULL,0);
							for (int i = 0; i < weapons.size(); i++)
							{
								weapons[i]->setActive(false);
								weapons[i]->setActivateOkayTurn(world->getTurn() + 20);
							}
						}
						break;
					case 0x40:
						{
							int duration = unknownD305d8.randomInRange_40c130();
							string text = "Initiating full reboot, ETC: " + intToString(duration) + ".";
							MESSAGE(0x1fc,&text,NULL,0,target,HEntity(),NULL,0);
							if (world->getPlayer()->isHostileTo(target))
								playerData.unknown77fbc0(0x6a);
							opR1d_4541b0(0x6a,0,0);
							target->unknown5fd900(1,duration);
						}
						break;
					case 0x41:
						MESSAGE(0x1fc,&string("Shutting down primary systems."),NULL,0,target,HEntity(),NULL,0);
						target->getAI()->unknown5b5220();
						target->unknown5fd900(2,0);
						opR1d_454260(target->getPosition(),0x136);
						break;
					case 0x44:
						if (unknown40a3f0(target->unknown45a4c0(),world->getPlayer()->getPosition()) > 5)
						{
							string text = "System outside max range to establish control (" + intToString(5) + ").";
							MESSAGE(0x1fd,&text,NULL,0,target,HEntity(),NULL,0);
							goto hackDone;
						}
					case 0x42:
					case 0x46:
						{
							int oldFaction = target->getGroup()->getType();
							target->unknown5fdab0();
							target->unknown639730(false);
							target->changeFaction(world->unknown463890(attacker->isPlayer() ? 1 + (hack == 0x42) : (attacker->unknown45aaa0(world->getPlayer()) ? 2 : attacker->getGroup()->getType())),true);
							if (world->unknown4631f0(target))
								opR1d_4541b0(0x6b,0,0);

							switch (hack)
							{
							case 0x42:
								MESSAGE(0x1fc,&string("Rewriting IFF filter."),NULL,0,target,HEntity(),NULL,0);
								status = target->getAI()->unknown4590f0()->unknown57f140(new EntityStatus(0x42));
								status->expireTurn = world->getTurn() + 10;
								status->values.push_back(Point(oldFaction));
								break;
							case 0x44:
								MESSAGE(0x1fc,&string("Hijacking control node."),NULL,0,target,HEntity(),NULL,0);
								status = target->getAI()->unknown4590f0()->unknown57f140(new EntityStatus(0x44));
								status->values.push_back(Point(oldFaction));
								target->getAI()->setFollowEntity(world->getPlayer(),0);
								break;
							case 0x46:
								{
									MESSAGE(0x1fc,&string("Rerouting network defenses."),NULL,0,target,HEntity(),NULL,0);
									MESSAGE(0x1fc,&string("Erasing system data."),NULL,0,target,HEntity(),NULL,0);
									string text = "Installing primary routines, ETC: " + intToString(6) + ".";
									MESSAGE(0x1fc,&text,NULL,0,target,HEntity(),NULL,0);
									target->unknown5fd900(1,6);
								}
								break;
							}
						}
						break;
					case 0:
						if (unknown45ac40(0x13) != NULL || data->faction == 0)
						{
							if (weapon->hackMode != 3)
								MESSAGE(0x1fd,&string("System resists sunder attempts."),NULL,0,target,HEntity(),NULL,0);
							goto hackDone;
						}
						MESSAGE((isPlayerSelf || unknown45aaa0(world->getPlayer())) ? 0xba : 0xbb,NULL,NULL,0,target,HEntity(),NULL,0);
						if (attacker.operator->() != NULL && attacker->isPlayer())
							statTracker.add4729d0(0x208,items.size(),string(""),-1);
						unknown6335e0();
						die(unknownA7,10,attacker,true,0,0,0,0);
						return;
					case 1:
						if (unknown45ac40(0x13) != NULL)
						{
							if (weapon->hackMode != 3)
								MESSAGE(0x1fd,&string("System resists disarm attempts."),NULL,0,target,HEntity(),NULL,0);
							goto hackDone;
						}
						{
							vector<HItem> weapons;
							if (!unknownC0)
							{
								target->unknown5cb930(&weapons);
								for (int i = 0; i < weapons.size(); i++)
								{
									if (weapons[i]->unknown4578a0() != 3 || !unknownB9651c[weapons[i]->getData()->unknown70] || weapons[i]->getEffect(0x6d) != NULL)
										unknown9d6440(weapons,i);
								}
							}
							if (weapons.empty())
							{
								if (weapon->hackMode != 3)
									MESSAGE(0x1fd,&string("Unable to locate transposition target."),NULL,0,target,HEntity(),NULL,0);
								goto hackDone;
							}
							unknown9d9fc0(weapons);
							string name = weapons.front()->getName(0,0);
							if (world->unknown4631f0(self))
							{
								string text = isPlayerSelf ? name + " transposed to ground." : getNameAt0c() + " " + name + " transposed to ground.";
								MESSAGE(0x320,&text,NULL,0,HEntity(),HEntity(),NULL,0);
								unknown5e5340(false,isPlayerSelf,4,true,0x1f,"-" + name);
							}
							unknown642940(weapons.front(),isPlayerSelf,true,false,2);
						}
						break;
					case 2:
					case 3:
						{
							// concussive blast: centred on the target (2) or on the hacker (3)
							HEntity blastSource = hack == 3 ? attacker : target;
							Point blastPos(blastSource->getPosition());
							HEntity blastOther = hack == 3 ? target : attacker;
							int turn = gameData.unknown46f4e0();
							MapRecord *record = NULL;
							for (int i = 0; i < mapRecords.size(); i++)
							{
								if (mapRecords[i]->unknown4c != 0 && (record == NULL || mapRecords[i]->unknown28 <= turn))
									record = mapRecords[i];
							}
							if (record == NULL)
								goto hackDone;

							if (world->unknown4631f0(blastSource))
							{
								string text = blastSource->isPlayer() ? string("A concussive blast radiates outward.") : "A concussive blast radiates from " + blastSource->getNameAt0c() + ".";
								MESSAGE(0x320,&text,NULL,0,HEntity(),HEntity(),NULL,0);
							}
							world->addRecord(objectFactory->createA(new MapEvent(blastOther,record,blastPos,HEntity(),Point(-1),Point(-1))));
						}
						break;
					case 4:
					case 5:
					case 6:
						if (getSize() > 1)
						{
							if (weapon->hackMode != 3)
								MESSAGE(0x1fd,&string("System size prevents spacial translocation."),NULL,0,target,HEntity(),NULL,0);
							goto hackDone;
						}
						{
							bool isHack5 = hack == 5;	// NOTE: placeholder name (never read)
							Range range;
							switch (hack)
							{
							case 4:
								range.set(5,10);
								break;
							case 5:
								range.set(50,75);
								break;
							case 6:
								range.set(75,100);
								break;
							}

							HEntity hacked = target;
							if (hack == 6)
								world->unknown464a00(new EntityTimer(hacked,hacked->getPosition(),rng.rangeInt(12.0f,30.0f)));

							Point oldPos(hacked->getPosition());
							bool moved = audio.placeEntityNear(&range,NULL,hacked,hack == 5,true);
							if (moved)
							{
								if (world->isVisible_4631c0(oldPos))
								{
									string text = hacked->isPlayer() ? string("Form shifts and blurs.") : hacked->getNameAt0c() + " form shifts and blurs.";
									MESSAGE(weapon->hackMode == 3 ? 0x320 : 0x1fc,&text,NULL,0,world->getPlayer(),HEntity(),NULL,0);
									int effectID;
									if (findEffectID("Xom_Disappear",&effectID))
										effectMgr->create()->init(effectMgr,effectID,oldPos,effectOrigin,NULL,NULL,NULL,9,0);
								}
								if (world->unknown4631f0(hacked))
								{
									string text = hacked->isPlayer() ? string("Form resolidifies at new position.") : hacked->getNameAt0c() + " form resolidifies at new position.";
									MESSAGE(0x320,&text,NULL,0,HEntity(),HEntity(),NULL,0);
									int effectID;
									if (findEffectID("Xom_Appear",&effectID))
										effectMgr->create()->init(effectMgr,effectID,hacked->getPosition(),effectOrigin,NULL,NULL,NULL,9,0);
								}
							}
						}
						break;
					case 7:
					case 8:
						if (attacker.operator->() == NULL)
							goto hackDone;
						if (attacker->getSize() > 1 && weapon->hackMode != 3)
						{
							MESSAGE(0x1fd,&string("System size prevents spacial translocation."),NULL,0,target,HEntity(),NULL,0);
							goto hackDone;
						}
						{
							// pull the hacker to a random spot 10-20 cells away (8: one the target can't reach)
							Point oldPos(attacker->getPosition());
							Point distRange(10,20);	// min/max distance
							bool unreachable = hack == 8;
							Point dest;
							Area area;
							cells.getBounds(oldPos,distRange.y,&area);
							for (int tries = 300; tries > 0; tries--)
							{
								dest = area.randomPoint_40be90();
								if (cells(dest)->canPlaceEntity(1) && distRange.contains_40c190(pointDistance(oldPos,Point(dest))) && (!unreachable || !world->isReachable(16,target->getPosition(),dest)))
									goto translocate;
							}
							if (weapon->hackMode != 3)
								MESSAGE(0x1fd,&string("System translocation search failed."),NULL,0,target,HEntity(),NULL,0);
							goto hackDone;

						translocate:
							HEntity hacked = attacker;
							oldPos = hacked->getPosition();
							bool moved = audio.placeEntityNear(NULL,&dest,hacked,false,true);
							if (moved)
							{
								if (world->isVisible_4631c0(oldPos))
								{
									string text = hacked->isPlayer() ? string("Form shifts and blurs.") : hacked->getNameAt0c() + " form shifts and blurs.";
									MESSAGE(weapon->hackMode == 3 ? 0x320 : 0x1fc,&text,NULL,0,world->getPlayer(),HEntity(),NULL,0);
									int effectID;
									if (findEffectID("Xom_Disappear",&effectID))
										effectMgr->create()->init(effectMgr,effectID,oldPos,effectOrigin,NULL,NULL,NULL,9,0);
								}
								if (world->unknown4631f0(hacked))
								{
									string text = hacked->isPlayer() ? string("Form resolidifies at new position.") : hacked->getNameAt0c() + " form resolidifies at new position.";
									MESSAGE(0x320,&text,NULL,0,HEntity(),HEntity(),NULL,0);
									int effectID;
									if (findEffectID("Xom_Appear",&effectID))
										effectMgr->create()->init(effectMgr,effectID,hacked->getPosition(),effectOrigin,NULL,NULL,NULL,9,0);
								}
							}
						}
						break;
					case 9:
						if (target->getSize() > 1 && weapon->hackMode != 3)
						{
							MESSAGE(0x1fd,&string("System size prevents spacial transposition."),NULL,0,target,HEntity(),NULL,0);
							goto hackDone;
						}
						{
							vector<HEntity> entities;
							Area area;
							int range = attacker->unknown5c7d30();
							cells.getBounds(target->getPosition(),range,&area);
							for (int x = area.min.x; x <= area.max.x; x++)
							{
								for (int y = area.min.y; y <= area.max.y; y++)
								{
									if (cells(x,y)->getEntity().isValid() && cells(x,y)->getEntity()->getSize() == 1 && cells(x,y)->getEntity() != attacker && world->isReachable(range,attacker->getPosition(),Point(x,y)))
										entities.push_back(cells(x,y)->getEntity());
								}
							}
							shuffle_9d9fc0(entities);
							entities.push_back(attacker);

							Point dest;
							for (unsigned int i = 0; i < entities.size(); i++)
							{
								if (world->findPlacement(entities[i]->getPosition(),dest,1))
									goto transpose;
							}
							if (weapon->hackMode != 3)
								MESSAGE(0x1fd,&string("Transposition failed."),NULL,0,target,HEntity(),NULL,0);
							goto hackDone;

						transpose:
							// the first entity takes the free spot, every other one moves into the previous one's position
							Point oldPos(entities.front()->getPosition());
							Point pos;
							entities.front()->changePos(dest,true);
							moveElement_9da1f0(entities,0,entities.size() - 1);
							for (unsigned int i = 0; i < entities.size(); i++)
							{
								pos = entities[i]->getPosition();
								entities[i]->unknown5ddac0(oldPos,0);
								oldPos = pos;
							}
							for (unsigned int i = 0; i < entities.size(); i++)
							{
								if (world->unknown4631f0(entities[i]))
								{
									string text(entities[i]->isPlayer() ? string("Form resolidifies at new position.") : entities[i]->getNameAt0c() + " form resolidifies at new position.");
									MESSAGE(0x320,&text,NULL,0,HEntity(),HEntity(),NULL,0);
									int effectID;
									if (findEffectID(string("Xom_Appear"),&effectID))
										effectMgr->create()->init(effectMgr,effectID,entities[i]->getPosition(),effectOrigin,NULL,NULL,NULL,9,0);
								}
							}
						}
						break;
					case 10:
						{
							vector<int> slots;
							attacker->unknown5c93d0(&slots);
							if (!anyPositive_9d54c0(slots) || unknown45ac40(0x13) != NULL || unknownC0 || gameModeCf462c == 2)
								goto pickHack;

							vector<int> slotOrder;
							for (int i = 0; i < 4; i++)
								slotOrder.push_back((int)i);
							shuffle_9d8f80(slotOrder);

							vector<HItem> candidates;
							for (unsigned int i = 0; i < slotOrder.size(); i++)
							{
								if (slots[slotOrder[i]] != 0)
								{
									vector<HItem> *inventory = target->getInventoryList();
									for (unsigned int j = 0; j < inventory->size(); j++)
									{
										if ((*inventory)[j]->unknown4578a0() == slotOrder[i] && (*inventory)[j]->unknown44aec0() <= 3 && (*inventory)[j]->unknown4578c0() == 1 && unknownB9651c[(*inventory)[j]->unknown9b4350()->unknown70]
											&& (*inventory)[j]->getEffect(0x6d) == NULL && (*inventory)[j]->getEffect(0x6c) == NULL && (*inventory)[j]->unknown577fb0() == 0)
											candidates.push_back((*inventory)[j]);
									}
									if (!candidates.empty())
										break;
								}
							}
							if (candidates.empty())
								goto pickHack;

							shuffle_9d9fc0(candidates);
							for (unsigned int i = 0; i < candidates.size(); i++)
							{
								if (attacker->isPlayer())
									playerData.unknown77ffb0(candidates[i]->unknown457820(),0);
								if (candidates[i]->unknown57a190(attacker,candidates[i]->unknown4578a0(),true,false))
								{
									if (world->unknown4631f0(attacker))
									{
										string text = candidates[i]->getName(0,0) + " transposed from " + target->getNameAt0c();
										text += attacker->isPlayer() ? string(".") : " to " + attacker->getNameAt0c() + ".";
										MESSAGE(0x320,&text,NULL,0,HEntity(),HEntity(),NULL,0);
										int effectID;
										if (findEffectID(string("Xom_Appear"),&effectID))
											effectMgr->create()->init(effectMgr,effectID,attacker->getPosition(),effectOrigin,NULL,NULL,NULL,9,0);
									}
									break;
								}
							}
						}
						break;
					}

					if (audio.enabled && attacker->isPlayer())
					{
						switch (weapon->hackMode)
						{
						case 0:
							audio.unknown69e700(0x31,0,0.0f);
							break;
						case 2:
						case 3:
							audio.unknown69e700(0x32,0,0.0f);
							break;
						}
					}
				}
				else if (attacker->isPlayer() && weapon->hackMode != 1)
					MESSAGE(0x1fe,NULL,NULL,0,self,HEntity(),NULL,0);
			}
		hackDone:
			break;
		case 0x7d:
			if (unknown45ac40(0x16) != NULL)
				MESSAGE(unknown45aaa0(world->getPlayer()) ? 0x1e9 : 0x1ea,NULL,NULL,0,self,HEntity(),NULL,0);
			else if (getTarget() >= 6 || unknown45ac40(0x39) != NULL || !rng.chance(weapon->hackMode))
				MESSAGE(unknown45aaa0(world->getPlayer()) ? 0x1ec : 0x1eb,NULL,NULL,0,self,HEntity(),NULL,0);
			else if (attacker.operator->() != NULL)
			{
				int faction = attacker->getGroup()->getType() <= 2 ? 1 : attacker->getGroup()->getType();
				if (group->getType() != faction)
				{
					MESSAGE(unknown45aaa0(world->getPlayer()) ? 0x1ee : 0x1ed,NULL,NULL,0,self,HEntity(),NULL,0);
					if (attacker->isPlayer())
						HISTORY(0x64,&getNameAt0c(),&weapon->unknown174,NULL,HEntity(),0);
					else
						HISTORY(0x65,&attacker->getNameAt0c(),&getNameAt0c(),&weapon->unknown174,HEntity(),0);
					unknown639730(false);
					world->unknown730f40(self);
					changeFaction(world->unknown463890(faction),true);
					unknown5fdab0();
					if (world->unknown4631f0(self))
						opR1d_4541b0(0x6b,0,0);
					if (attacker->isPlayer())
						statTracker.add4729d0(0x3b5,1,string(""),-1);
				}
				else
					MESSAGE(unknown45aaa0(world->getPlayer()) ? 0x1ec : 0x1eb,NULL,NULL,0,self,HEntity(),NULL,0);
			}
			return;
		case 0x73:
			unknown50 = 0;
			if (attacker.operator->() != NULL)
			{
				world->unknown464e10(new AttackRecord(attacker,self));
				MESSAGE(isPlayerSelf ? 0x29 : (unknown45aaa0(world->getPlayer()) ? 0x2a : 0x2b),&weapon->name,NULL,0,self,HEntity(),NULL,0);
				if (isPlayerSelf && attacker.operator->() != NULL && attacker->getGroup()->getType() == 3 && attacker->getFaction() == 0x14 && overmind.unknown68fc40())
				{
					MESSAGE(0x2c,&weapon->name,NULL,0,attacker,HEntity(),NULL,0);
					bool alerted = false;
					if (gameState->unknown4 == 0x20 && stringToInt(gameData.getEntryText(string("secScannedCogmind_g"))) == 0)
					{
						gameData.setEntryText(string("secScannedCogmind_g"),string("1"));
						gameData.setEntryText(string("resScannedCogmind_g"),string("1"));
						do
						{
							messageLog.setUnknown34(1);
							if (0)
								playSound_4541b0(-1,0,0);
							MESSAGE(0x324,&string("ALERT: Modified LRC-V3 signature confirmed."),NULL,0,HEntity(),HEntity(),NULL,0);
							logMsgs->scrollToEnd();
						} while (0);
						statTracker.add472b90(0x46,-999999);
						playerData.unknown77fbc0(0x19b);
						alerted = true;
						if (audio.enabled)
							audio.unknown69e700(0x56,0,0.0f);
					}
					else if (stringToInt(gameData.getEntryText(string("resScannedCogmind_g"))) == 0)
					{
						gameData.setEntryText(string("resScannedCogmind_g"),string("1"));
						do
						{
							messageLog.setUnknown34(1);
							if (0)
								playSound_4541b0(-1,0,0);
							MESSAGE(0x324,&string("ALERT: Encountered unknown unique technology, formulating response."),NULL,0,HEntity(),HEntity(),NULL,0);
							logMsgs->scrollToEnd();
						} while (0);
						statTracker.add472b90(0x46,-999999);
						alerted = true;
						if (audio.enabled)
							audio.unknown69e700(0x55,0,0.0f);
					}
					if (alerted)
						unknown5141b0(0x7a,NULL,NULL,0,HEntity(),0);
				}
			}
			return;
		case 0x75:
			unknown50 = 0;
			unknownBC = 200;
			MESSAGE(isPlayerSelf ? 0x2d : (unknown45aaa0(world->getPlayer()) ? 0x2e : 0x2f),&weapon->name,NULL,0,self,HEntity(),NULL,0);
			playSoundAt_4542a0(getPosition(),0xc6,0x15);
			break;
		case 0xca:
		{
			// tractor beam: small, weak robots implode; otherwise pull the target (or, failing that, nearby objects) toward the attacker
			HEntity selfHandle = self;
			if (unknown45a340() < 3 && unknown8c <= 50 && data->faction != 0 && rng.chance(20))
			{
				if (world->unknown4631f0(self))
				{
					string text = getNameAt0c() + " slowly implodes.";
					MESSAGE(0x320,&text,NULL,0,HEntity(),HEntity(),NULL,0);
				}
				unknownB4 -= 20;
				die(unknownA7,10,attacker,true,0,0,0,true);
				return;
			}

			if (unknown45a340() < 4 && getSize() == 1 && attacker.operator->() != NULL && !unknown5c8820(attacker))
			{
				int chance = 15;
				if (attacker == player)
				{
					if (player->getAI()->getState() == 0x17)
						chance = 0;
					else
					{
						int moveCost = unknown5d15a0(false);
						int playerMoveCost = player->unknown5d15a0(false);
						if (moveCost < playerMoveCost)
							chance = (int)(chance * ((float)playerMoveCost / moveCost));
					}
				}
				if (chance != 0 && rng.chance(chance))
				{
					Point origin(getPosition());
					Point dest = attacker->unknown5c80f0(origin);
					vector<Point> line;
					vector<int> steps;
					traceSubcellLine(origin,dest,line,steps,9);
					for (int i = 1; i < (int)line.size() - 1; i++)
					{
						if (cells(line[i])->unknown45d480() || cells(line[i])->getEntity().isValid())
							goto pullSurroundings;
					}
					if (true)	// NOTE: the exe tests a constant here
					{
						PulledObject *object = new PulledObject(2,origin);
						object->unknown1E = true;
						if (unknownA7)
						{
							world->setFlagA74(true);
							world->unknown749ee0(attacker,object,dest,true);
							delete object;
							world->setFlagA74(false);
						}
						else
						{
							int effectID;
							if (findEffectID("Forcegen_Object_" + intToString(2),&effectID))
							{
								EffectParams *params = new EffectParams(NULL,attacker,0,9999,0.0f,HEntity(),HEntity(),0,HEntity(),NULL,0,object);
								effectMgr->create()->init(effectMgr,effectID,origin,effectOrigin,&dest,&effectOrigin,params,9,0);
							}
						}
						unknownD225a0.unknown6728c0(attacker);
						if (attacker == player)
							unknownCf6954 = world->getTurn();
						return;
					}
				}
			}

		pullSurroundings:
			Point center = unknown45a4c0();
			Area area;
			cells.getBounds(center,1,&area);
			vector<Point> border;
			vector<Point> targets;
			vector<int> types;
			vector<Point> occupied;
			bool activeFootprint = false;
			if (attacker == player && attacker.operator->() != NULL)
			{
				vector<Point> footprint;
				attacker->unknown5c89d0(&footprint);
				for (unsigned int i = 0; i < footprint.size(); i++)
				{
					if (cells(footprint[i])->getProp().isValid() && cells(footprint[i])->getProp()->getType()->unknown8C != 0)
					{
						activeFootprint = true;
						break;
					}
				}
			}

			// search outward ring by ring for up to 10 pullable objects
			for (int ring = 0; ring < 15 && targets.size() < 10; ring++)
			{
				border.clear();
				area.getBorder_40bac0(border);
				shuffle_9d7350(border);
				for (unsigned int i = 0; i < border.size(); i++)
				{
					if (!cells.isInBounds(border[i]) || pointDistance(center,border[i]) > 15)
						continue;

					int type = -1;
					if (cells(border[i])->unknown45d4e0() && cells(border[i])->getArmor() != -1)
						type = 0;
					else if (cells(border[i])->getProp().isValid() && cells(border[i])->unknown45d500() && cells(border[i])->getProp()->unknown45c630() != -1 && (!activeFootprint || cells(border[i])->getProp()->getType()->unknown8C == 0))
						type = 1;
					else if (cells(border[i])->getEntity().isValid() && cells(border[i])->getEntity()->getSize() == 1 && cells(border[i])->getEntity() != attacker)
						type = 2;
					else if (cells(border[i])->getItem().isValid() && (cells(border[i])->getItem()->unknown457b30() != 0 || cells(border[i])->getItem()->unknown4578a0() == 1))
						type = 3;

					if (type != -1)
					{
						vector<Point> line;
						vector<int> steps;
						traceSubcellLine(border[i],getPosition(),line,steps,9);
						for (int j = 1; j < (int)line.size() - 1; j++)
						{
							if (cells(line[j])->unknown45d480() || (cells(line[j])->getEntity().isValid() && cells(line[j])->getEntity() != self) || (type == 2 && inVector_9d0ce0(occupied,line[j])))
								goto nextBorderCell;
						}
						targets.push_back(border[i]);
						types.push_back(type);
						appendRange_9d9890(line,occupied,1,line.size() - 2);
					nextBorderCell:
						;
					}
				}
				area.grow_40bc10(1);
			}

			if (targets.empty())
			{
				if (attacker.operator->() != NULL)
					MESSAGE(0xe5,NULL,NULL,0,attacker,HEntity(),NULL,0);
			}
			else
			{
				vector<int> order;
				fillIndices_9d98e0(targets,order);
				shuffle_9d8f80(order);
				vector<Point> pullTo;
				for (unsigned int i = 0; i < targets.size(); i++)
					pullTo.push_back(unknown5c80f0(targets[i]));
				int maxPulled = attacker == player ? 5 : 3;
				int effectIDs[4];
				for (int i = 0; i < 4; i++)
					findEffectID("Forcegen_Object_" + intToString(i),&effectIDs[i]);

				int pulled = 0;
				for (unsigned int i = 0; i < order.size() && pulled < maxPulled; i++)
				{
					int type = types[order[i]];
					Point from(targets[order[i]]);
					Point to(pullTo[order[i]]);
					switch (type)
					{
					case 0:
						if (!cells(from)->unknown45d4e0())
							continue;
						break;
					case 1:
						if (cells(from)->getProp().isNull() || !cells(from)->unknown45d500())
							continue;
						break;
					case 2:
						if (cells(from)->getEntity().isNull() || cells(from)->getEntity()->getSize() != 1 || cells(from)->getEntity() == attacker)
							continue;
						break;
					case 3:
						if (cells(from)->getItem().isNull())
							continue;
						break;
					}

					pulled++;
					PulledObject *object = new PulledObject(type,from);
					if (type == 0)
						cells(from)->unknown45e110(0,0,attacker);
					else if (type == 1)
						cells(from)->getProp()->unknown45ce10(false,0,false,attacker);
					else if (type == 3)
						cells(from)->getItem()->unknown57dbe0(0,0,1,1);
					if (isPlayerSelf && unknownCf68b4 != 0 && attacker.operator->() != NULL && player == attacker)
						unknownCf68f0->unknown672f20(attacker,8,0,string(""));
					if (unknownA7)
					{
						world->setFlagA74(true);
						world->unknown749ee0(attacker,object,to,true);
						delete object;
						world->setFlagA74(false);
					}
					else
					{
						EffectParams *params = new EffectParams(NULL,attacker,0,9999,0.0f,HEntity(),HEntity(),0,HEntity(),NULL,0,object);
						effectMgr->create()->init(effectMgr,effectIDs[type],from,effectOrigin,&to,&effectOrigin,params,9,0);
					}
				}
			}
			if (selfHandle.operator->() == NULL)
				return;
		}
		break;
		}
	}
	else
	{
		switch (explosion->specialType)
		{
		case 0x75:
			unknown50 = 0;
			unknownBC = 200;
			// NOTE: the exe passes &weapon->name here although weapon is NULL on this path (copied from case 0x75 above)
			MESSAGE(isPlayerSelf ? 0x2d : (unknown45aaa0(world->getPlayer()) ? 0x2e : 0x2f),&weapon->name,NULL,0,self,HEntity(),NULL,0);
			playSoundAt_4542a0(getPosition(),0xc6,0x15);
			break;
		}
	}
	// sabotage: damage the target's parts with a part of the attacker's own inventory
	if (weapon != NULL && weapon->getValue457330(0x3f) != 0)
	{
		if (attacker.operator->() != NULL && unknown45ac40(0x13) == NULL)
		{
			HItem sabotageItem;
			vector<HItem> *inventory = attacker->getInventoryList();
			for (unsigned int i = 0; i < inventory->size(); i++)
			{
				if ((*inventory)[i]->getData() == weapon && (*inventory)[i]->unknown457cf0())
				{
					sabotageItem = (*inventory)[i];
					break;
				}
			}
			if (sabotageItem.operator->() != NULL)
			{
				HItem sacrificed;
				if (attacker->isPlayer())
				{
					vector<CPart *> *partList = parts->getParts();
					for (unsigned int i = 0; i < partList->size(); i++)
					{
						if ((*partList)[i]->getItem().isValid() && (*partList)[i]->getItem()->unknown457cf0() && (*partList)[i]->getItem()->unknown4578a0() == 0)
						{
							sacrificed = (*partList)[i]->getItem();
							break;
						}
					}
				}
				else
				{
					for (unsigned int i = 0; i < inventory->size(); i++)
					{
						if ((*inventory)[i]->unknown4578a0() == 0 && (*inventory)[i]->unknown457cf0())
						{
							sacrificed = (*inventory)[i];
							break;
						}
					}
				}
				if (sacrificed.operator->() != NULL)
				{
					if (attacker->isPlayer())
						MESSAGE(0x46,&sacrificed->getName(0,0),NULL,0,attacker,HEntity(),NULL,0);
					sacrificed->unknown57dbe0(1,1,1,1);

					int count = rng.rangeInt(2.0f,4.0f);
					vector<int> excluded;
					excluded.push_back(7);
					for (int i = 0; i < count; i++)
					{
						HItem part = unknown5e3cb0(false,-1,&excluded,true,true);
						if (part.isNull())
							break;
						if (part->getData()->unknown70 <= 1)
							continue;

						if (!unknownA7)
						{
							int effectID;
							findEffectID("Part_Sabotaged",&effectID);
							if (effectID != 0)
								effectMgr->create()->init(effectMgr,effectID,unknown45a4c0(),effectOrigin,NULL,NULL,NULL,9,0);
						}
						MESSAGE(isPlayerSelf ? 0x47 : unknown45aaa0(world->getPlayer()) ? 0x48 : 0x49,&part->getName(0,0),NULL,0,self,HEntity(),&unknown45a4c0(),0);
						if (isPlayerSelf)
							statTracker.add4729d0(0x206,1,string(""),-1);
						if (part->unknown457e90() || unknownC0)
						{
							MESSAGE(0x45,&part->getName(0,0),NULL,0,self,HEntity(),&unknown45a4c0(),0);
							part->unknown57dbe0(isPlayerSelf,1,1,1);
						}
						else
						{
							part->unknown458310(rng.rangeInt(part->getIntegrity() / 6,part->getIntegrity() / 2));
							if (gameMode != 2 || isPlayerSelf)
								unknown642940(part,isPlayerSelf,1,0,2);
						}
					}
					attacker->takeDamage(7,weapon,NULL,sabotageItem->getData()->damage.randomInRange_40c130(),sabotageItem->getData()->damageType,0,0,unknownA7,HEntity(),1,8,0,0,0);
				}
			}
		}
		return;
	}

	// domination
	if (weapon != NULL && weapon->getValue457330(0x7b) != 0)
	{
		if (attacker.operator->() != NULL)
		{
			int playerGroup = 1;
			if (group->getType() != playerGroup)
			{
				MESSAGE(0x1ef,&weapon->name,NULL,0,attacker,self,NULL,0);
				do
				{
					unknown5141b0(0x67,&attacker->getNameAt0c(),&getNameAt0c(),0,self,0);
				} while (0);
				unknown45b340(new EntityEffect(effectDefs[0x7b],weapon->getValue457330(0x7b)));
				removeEffectsA(false);
				world->unknown730f40(self);
				changeFaction(world->unknown463890(playerGroup),true);
				unknown5fdab0();
				world->unknown6c65a0(self,"Master_Drone_Early_Exit",0);
				attacker->unknown637bb0();
			}
			else
				logError("Entity::projectileImpact()","dominating ally?");
		}
		return;
	}

	// theft
	if (weapon != NULL && weapon->getValue457330(0x40) != 0 && unknown45ac40(0x13) == NULL && attacker.operator->() != NULL
		&& rng.chance(weapon->getValue457330(0x40) + (attacker->getFaction() == 0x3a ? 30 : 0)) && !items.empty())
	{
		HItem stolen;
		if (attacker->getName() == "Thief_7")
		{
			vector<HItem> candidates;
			for (unsigned int i = 0; i < items.size(); i++)
			{
				if (items[i]->getData()->unknown70 != 0 && items[i]->unknown457880() != 1 && items[i]->getEffect(0x6c) == NULL)
					candidates.push_back(items[i]);
			}
			if (!candidates.empty())
			{
				vector<HItem> preferred;
				for (unsigned int i = 0; i < items.size(); i++)
				{
					if (items[i]->getEffect(0x63) != NULL)
						preferred.push_back(items[i]);
				}
				if (!preferred.empty())
					stolen = unknown9dafb0(preferred);
				else if (rng.chance(15))
					stolen = unknown9dafb0(candidates);
				else
				{
					stolen = candidates[0];
					for (unsigned int i = 1; i < candidates.size(); i++)
					{
						if (candidates[i]->unknown457900() > stolen->unknown457900())
							stolen = candidates[i];
					}
				}
			}
		}
		else
		{
			vector<int> excluded;
			excluded.push_back(7);
			stolen = unknown5e3cb0(true,-1,&excluded,true,true);
			if (stolen.isValid() && (stolen->getData()->unknown70 <= 1 || stolen->getEffect(0x6c) != NULL))
				stolen.clear();
		}

		if (stolen.isValid())
		{
			bool isCategory4 = stolen->getCategory() == 4;
			if (isCategory4)
				MESSAGE(isPlayerSelf ? 0x4d : unknown45aaa0(world->getPlayer()) ? 0x4e : 0x4f,&stolen->getName(0,0),NULL,0,self,HEntity(),&unknown45a4c0(),0);
			else
				MESSAGE(isPlayerSelf ? 0x4a : unknown45aaa0(world->getPlayer()) ? 0x4b : 0x4c,&stolen->getName(0,0),NULL,0,self,HEntity(),&unknown45a4c0(),0);
			if (isPlayerSelf)
				statTracker.add4729d0(0x207,1,string(""),-1);

			if (!isCategory4 && (stolen->getData()->unknown1ac || stolen->getEffect(0x6e) != NULL || stolen->unknown457e90() || unknownC0))
				stolen->unknown57dbe0(1,1,1,1);
			else
			{
				stolen->setIntegrity(maxInt(1,stolen->getIntegrity() * 90 / 100));
				if (gameMode != 2 || isPlayerSelf)
				{
					if (attacker.operator->() != NULL && attacker->unknown45a810() >= stolen->unknown4578c0()
						&& (!isPlayerSelf || unknownCf4730 == 0 || (stolen->unknown457fb0() != 7 && stolen->unknown457fb0() != 0x8f))
						&& (gameMode != 9 || stolen->unknown4578a0() != 3 || stolen->getData()->unknown1a0 == 0))
					{
						if (isPlayerSelf && parts->unknown894e70(stolen) != NULL)
							parts->unknown894e70(stolen)->setUnknown9c(2);
						stolen->unknown57a190(attacker,4,isPlayerSelf || attacker->isPlayer(),0);
						if (isPlayerSelf && attacker.operator->() != NULL && attacker->getName() == "Thief_7")
						{
							do
							{
								unknown5141b0(0x135,&stolen->getName(0,0),NULL,0,HEntity(),0);
							} while (0);
						}
						if (isPlayerSelf && stolen->unknown457f90() == 0xd6 && playerData.hasCompanion())
							spawnState->tracker->spawn(0x26,false,string(""));
					}
					else
						unknown642940(stolen,isPlayerSelf || attacker->isPlayer(),1,0,2);
				}
				if (!unknownA7)
				{
					int effectID;
					findEffectID("Part_Sabotaged",&effectID);
					if (effectID != 0)
						effectMgr->create()->init(effectMgr,effectID,unknown45a4c0(),effectOrigin,NULL,NULL,NULL,9,0);
				}
			}
			return;
		}
	}
	if (weapon != NULL && weapon->getValue457330(0x42) != 0)
	{
		opR1d_454260(getPosition(),0xa1);
		int distance = pointDistance(getPosition(),world->getPlayer()->getPosition());
		if (distance <= 10)
			consoleShake.shake((11 - distance)*50,0);

		if (!items.empty())
		{
			int count = rng.rangeInt(2.0f,3.0f);
			int destroyed = 0;
			int dropped = 0;
			for (int i = 0; i < count; i++)
			{
				HItem item = unknown5e3cb0(false,-1,NULL,true,true);
				if (item.isNull())
					break;
				if (item->getType()->unknown70 > 1)
				{
					MESSAGE(isPlayerSelf ? 0xb2 : (unknown45aaa0(world->getPlayer()) ? 0xb3 : 0xb4),&item->getName(0,0),NULL,0,self,HEntity(),&unknown45a4c0(),0);
					if (i == 0)
					{
						item->unknown57dbe0(isPlayerSelf,1,1,1);
						destroyed++;
					}
					else if (item->unknown457e90() || unknownC0)
					{
						MESSAGE(0x45,&item->getName(0,0),NULL,0,self,HEntity(),&unknown45a4c0(),0);
						item->unknown57dbe0(isPlayerSelf,1,1,1);
						destroyed++;
					}
					else
					{
						item->setIntegrity(maxInt(1,item->getIntegrity()/2));
						if (gameMode != 2 || isPlayerSelf)
						{
							unknown642940(item,isPlayerSelf || attacker->isPlayer(),1,0,2);
							dropped++;
						}
					}
				}
			}

			if (destroyed != 0 || dropped != 0)
			{
				if (isPlayerSelf)
				{
					string text = opw8_countString(destroyed,"part") + " destroyed";
					if (dropped != 0)
						text += ", " + intToString(dropped) + " dropped";
					do { unknown5141b0(0x18b,&text,NULL,0,HEntity(),0); } while (0);
				}
				if (!unknownA7)
				{
					int effectID;
					findEffectID("Part_Sabotaged",&effectID);
					if (effectID != 0)
						effectMgr->create()->init(effectMgr,effectID,unknown45a4c0(),effectOrigin,NULL,NULL,NULL,9,0);
				}
			}
		}
	}

	if (weapon != NULL && weapon->getValue457330(0x43) != 0)
	{
		if (isPlayerSelf && audio.enabled && audio.unknown69edf0())
		{
			audio.unknown69ee30(0,0,1);
			return;
		}
		die(unknownA7,0xa,attacker,true,0,0,0,0);
		return;
	}

	if (weapon != NULL)
	{
		bool kill = false;
		switch (weapon->specialType)
		{
		case 0xc3:
			if (unknown45ac40(0x13) != NULL)
				break;
			if (rng.chance(weapon->hackMode))
				kill = true;
			else if (audio.enabled && data->faction == 0x21 && ++audio.unknown9C == 4)
				audio.unknown69e700(0x41,0,0.0f);
			break;
		case 0xd6:
			if (unknown45ac40(0x13) != NULL)
				break;
			if (playerData.hasCompanion() && spawnState->unknown00 != 0 && rng.chance(3) && attacker.operator->() != NULL && attacker->unknown45a8d0() >= 200)
				kill = true;
			break;
		}

		if (kill)
		{
			if (weapon->specialType == 0xd6)
			{
				attacker->unknown45b1b0(200);
				if (playerData.hasCompanion())
					spawnState->tracker->spawn(0x17,false,data->getName459c30());
			}
			MESSAGE(isPlayerSelf || unknown45aaa0(world->getPlayer()) ? 0xba : 0xbb,NULL,NULL,0,self,HEntity(),&unknown45a4c0(),0);
			if (attacker.operator->() != NULL && attacker->isPlayer())
				statTracker.add4729d0(0x208,items.size(),string(""),-1);
			unknown6335e0();
			bool wasHostile = attacker->isHostileTo(self);
			bool wasFaction21 = data->faction == 0x21;
			die(unknownA7,0xa,attacker,true,0,0,0,0);
			if (weapon->specialType == 0xc3 && attacker.operator->() != NULL && attacker->isPlayer())
			{
				if (wasHostile)
					playerData.unknown77fbc0(0xde);
				if (wasFaction21)
					playerData.unknown77fbc0(0xdf);
			}
			return;
		}
	}

	if (weapon != NULL && weapon->specialType == 0xd6 && spawnState != NULL && spawnState->unknown2c == data->unknown48 && world->getPlayer()->isHostileTo(self) && rng.chance(10))
	{
		if (playerData.hasCompanion())
			spawnState->tracker->spawn(0x16,false,data->getName459c30());
		string text = getNameAt0c() + " is pierced by a surge of energy.";
		addMessage(0x320,HEntity(),text,0);
		die(unknownA7,0xa,attacker,true,0,0,0,0);
		return;
	}

	if (weapon != NULL && weapon->specialType == 0xc4 && unknown45ac40(0x16) == NULL)
	{
		vector<HItem> candidates;
		unknown5cb8b0(&candidates);
		for (unsigned int i = 0; i < candidates.size(); i++)
		{
			if ((candidates[i]->getKind() != 0xc && candidates[i]->getKind() != 0xd) || candidates[i]->unknown577ad0() > 0 || candidates[i]->getUnknown20())
				eraseAt(candidates,i);
		}

		if (!candidates.empty())
		{
			HItem part = randomItem(candidates);
			unknown5fd550(part,rng.rangeInt(10.0f,(float)weapon->hackMode));
			MESSAGE(isPlayerSelf ? 0x18c : (isHostileTo(world->getPlayer()) ? 0x18e : 0x18d),&part->getName(0,0),NULL,0,self,HEntity(),NULL,0);
			if (isPlayerSelf)
			{
				CPart *cpart = parts->unknown894e70(part);
				if (cpart != NULL)
					cpart->unknown890710(0);
			}
		}
	}

	if (data->faction == 0x60 && weapon != NULL && weapon->name.find("L-Cannon") != string::npos && world->unknown748a00(0,weapon))
		return;
	int damageType = weapon != NULL ? weapon->damageType : explosion->damageType;
	switch (damageType)
	{
	case 10:
		return;
	}

	// roll the damage
	bool damageBonusApplied = false;
	int damage;
	if (damageType == 9)
		damage = 0;
	else if (weapon != NULL)
	{
		Point range(weapon->damage);
		if (attacker.operator->() != NULL)
		{
			if (weapon->unknown1b0 && !weapon->unknown165 && attacker->unknown5d22a0(0x66) != 0)
			{
				int bonus = attacker->unknown5d22a0(0x66);
				range.x = range.x * bonus / 100 + range.x;
				range.y = range.y * bonus / 100 + range.y;
				damageBonusApplied = true;
			}
			else if (unknownA2 == 0)
			{
				range.y = attacker->unknown5d2150(0x6a,0) * range.y / 100 + range.y;
				addCapped_9d06d0(&range.x,attacker->unknown5d2090(0x5a) / 2,range.y);
			}
			else if (weapon->kind == 0x16 || weapon->kind == 0x17)
			{
				range.x = attacker->unknown5d22a0(0x69) * range.x / 100 + range.x;
				if (range.x > range.y)
					range.y = range.x;
			}
		}
		damage = (int)(range.randomInRange_40c130() * unknownA5);
	}
	else
		damage = *explosionDamage;
	lastDamageTypeName = damageTypeNames[damageType];
	lastDamage = damage;

	if (records != NULL)
	{
		HEntity selfHandle = self;
		if (Map::turnUpdate_51da30(records,0x14,self,HEntity(),HEntity(),0,0) && selfHandle.operator->() == NULL)
			return;
		if (attacker.operator->() != NULL && Map::turnUpdate_51da30(records,0x15,attacker,HEntity(),HEntity(),0,0) && selfHandle.operator->() == NULL)
			return;
		if (Map::turnUpdate_51da30(records,0x18,self,HEntity(),HEntity(),0,0) && selfHandle.operator->() == NULL)
			return;
	}
	else if (explosion != NULL && !explosion->effects.empty())
	{
		HEntity selfHandle = self;
		EffectList *effects = new EffectList(explosion->effects);
		bool triggered = unknown4569a0(0x1a,attacker,self,HProp(),HItem(),0,NULL,effects,self,HProp(),HItem(),0);
		delete effects;
		if (triggered && selfHandle.operator->() == NULL)
			return;
	}

	if (unknownEC != NULL)
	{
		HEntity selfHandle = self;
		if (unknown4569a0(0xe,self,HEntity(),HProp(),HItem(),0,unknownA2 == 0 ? &weapon->name : &weapon->unknown174,unknownEC,self,HProp(),HItem(),0) && selfHandle.operator->() == NULL)
			return;
		if (unknownA2 == 0)
		{
			if (unknown4569a0(0xf,self,HEntity(),HProp(),HItem(),0,&weapon->name,unknownEC,self,HProp(),HItem(),0) && selfHandle.operator->() == NULL)
				return;
		}
		if (unknownA2 != 0)
		{
			if (unknown4569a0(0x10,self,HEntity(),HProp(),HItem(),0,&weapon->unknown174,unknownEC,self,HProp(),HItem(),0) && selfHandle.operator->() == NULL)
				return;
		}
	}

	if (damageType == 9)
		return;

	if (unknownD28f98)
		unknownD4 = unknownCaed20;

	// damage modifiers
	if (weapon != NULL && attacker == world->getPlayer())
	{
		if (unknownCf4910[data->ID] != 0)
			damage = damage * 110 / 100;
		if (ai != NULL && ai->unknown459090() && ai->unknown4590f0()->unknown458950(0x38) != NULL)
			damage = (int)(damage * 1.25f);
	}
	if (attacker.operator->() != NULL && weapon != NULL && (weapon->kind == 0x14 || weapon->kind == 0x15) && !weapon->unknown165 && !damageBonusApplied)
		damage = attacker->unknown5d2150(0x67,0) * damage / 100 + damage;
	if (attacker.operator->() != NULL && weapon != NULL && (attacker->isPlayer() || attacker == world->getEntity671()))
	{
		if ((inRange_9daf80(0x14,weapon->kind,0x17) || inRange_9daf80(0x1a,weapon->kind,0x1c)) && !weapon->unknown165 && data->aiType != 0)
		{
			int bonus = 0;
			for (unsigned int i = 0; i < attacker->items.size(); i++)
			{
				if (attacker->items[i]->unknown457cf0() && attacker->items[i]->unknown457f90() == 0x68 && attacker->items[i]->unknown457fb0() > bonus && attacker->items[i]->getEffect(0x74) != NULL && attacker->items[i]->getEffectValue(0x74) == data->unknown48)
					bonus = attacker->items[i]->unknown457fb0();
			}
			if (bonus != 0)
				damage = damage * bonus / 100 + damage;
		}
	}
	if (damageType < 7 && unknownCf49bc[damageType] != 0 && attacker.operator->() != NULL && attacker->isPlayer())
		damage = damage * unknownCf49bc[damageType] / 100 + damage;
	if (!unknown5e2e60(&damage,damageType))
		return;

	if (weapon != NULL && weapon->unknown16c != 0 && !isPlayerSelf)
		world->unknown74b060(footprint[0],weapon->unknown16c,100);

	// heat transfer
	int heat = weapon != NULL ? weapon->heatTransfer : explosion->heatTransfer;
	if (attacker.operator->() != NULL && weapon != NULL && weapon->unknown118 == 1)
	{
		if (weapon->kind == 0x14 || weapon->kind == 0x16)
			heat = attacker->unknown5d2090(0x70) + heat + attacker->unknown5d2090(0x71);
		else if (weapon->kind == 0x15 || weapon->kind == 0x17)
			heat = attacker->unknown5d2090(0x71) + heat;
	}
	if (heat > 0 && !isPlayerSelf && attacker.operator->() != NULL && attacker->isPlayer() && unknown5c8020())
	{
		statTracker.add472b90(0x6a,(int)(heat * unknownB949b8[data->aiType]));
		if (statTracker.current->values[0x6a] < -999)
			playerData.unknown77fbc0(0xca);
	}
	unknownB4 += heat;

	// critical hits
	int hits = weapon != NULL ? 1 : explosion->hits.randomInRange_40c130();
	int critical = 0;
	if (weapon != NULL && weapon->criticalChance != 0 && unknown45ac40(0x14) == NULL)
	{
		critical = rng.chance(weapon->criticalChance + (attacker.operator->() != NULL && weapon->criticalType != 2 ? attacker->unknown5d2150(0x5f,0) : 0)) ? weapon->criticalType : 0;
		if (critical != 0)
		{
			if (isPlayerSelf)
				statTracker.add4729d0(0x16d,1,string(""),-1);
			if (unknown5d2380(0x4b).isValid())
			{
				critical = 0;
				if (isPlayerSelf)
					statTracker.add4729d0(0x16e,1,string(""),-1);
			}
			else if (critical == 12 && unknown45ac40(0x15) != NULL)
				critical = 0;
		}
	}

	// statistics
	if (attacker.operator->() != NULL)
	{
		if (attacker->isPlayer())
		{
			if (isPlayerSelf)
			{
				statTracker.add4729d0(0x1e0,damage,string(""),-1);
				statTracker.add4729d0(0x1e1,1,string(""),-1);
			}
			else
			{
				statTracker.add4729d0(0x1b1,damage,string(""),-1);
				if (weapon == NULL || weapon->kind != 0x19)
					statTracker.add4729d0(explosion != NULL ? 0x1b4 : (unknownA2 == 0 ? 0x1b5 : (weapon->kind == 0x14 || weapon->kind == 0x16 ? 0x1b2 : 0x1b3)),damage,string(""),-1);
				statTracker.add4729d0(0x1b7 + damageType,damage,string(""),-1);
				if (unknown5c8020())
				{
					statTracker.add472b90(0x6a,(int)(damage * unknownB949a8[data->aiType]));
					if (statTracker.current->values[0x6a] < -999)
						playerData.unknown77fbc0(0xca);
				}
			}
		}
		else
		{
			if (attacker->unknown45aaa0(world->getPlayer()))
				attacker->unknownC8 += damage;
			if (attacker->group->getType() <= 2)
			{
				statTracker.add4729d0(0x3af,damage,string(""),-1);
				if (attacker == world->getEntity671())
					statTracker.add4729d0(0x451,damage,string(""),-1);
			}
		}
	}

	// apply the damage, split over the number of hits
	damage /= hits;
	do
	{
		switch (takeDamage(unknownA2 == 0 ? 7 : (weapon != NULL ? (weapon->kind == 0x14 || weapon->kind == 0x16 ? 8 : 9) : 10),weapon,explosion,damage,damageType,critical,
			weapon != NULL ? weapon->unknown150 : explosion->unknown5c,unknownA7,attacker,0,unknown4374c0(*unknownA6,footprint[0]),
			weapon != NULL ? weapon->unknown154 : (explosion != NULL && isPlayerSelf ? explosion->unknown60 : 0),
			hits == 1 ? (weapon != NULL ? minInt(attacker.operator->() != NULL && attacker->unknown45ac40(0x1f) != NULL && rng.chance(50) ? 0 : weapon->unknown158 + (weapon->unknown158 != 0 && weapon->unknown15c != 0 && unknownA5 > 1.0 ? 1 : 0),6) : explosion->unknown64) : 0,
			0))
		{
		case 0:
			if (weapon != NULL)
			{
				int sound1 = 0;
				int sound2 = 0;
				switch (weapon->impactSoundMode)
				{
				case 1:
					sound1 = weapon->impactSound;
					break;
				case 2:
					sound1 = data->sounds->unknown50[2][*weapon->unknown278];
					sound2 = data->sounds->unknown50[3][*weapon->unknown278];
					break;
				}
				if (sound1 != 0)
					opR1d_454160(unknown45a4c0(),sound1,0x12);
				if (sound2 != 0)
					opR1d_454160(unknown45a4c0(),sound2,0x12);
			}
			break;
		case 1:
			return;
		case 2:
			return;
		}
	} while (--hits);

	// knockback
	if (explosion != NULL && explosion->knockback.y != 0 && data->size == 1 && attacker.operator->() != NULL && unknown5d1390() != 0)
	{
		int distance = explosion->knockback.randomInRange_40c130() + (2 - data->size);
		if (distance > 0)
		{
			Point origin;
			if (*unknownA6 != footprint[0])
				origin = *unknownA6;
			else if (unknownCfd420.x != -1 && unknownCfd420 != footprint[0])
				origin = unknownCfd420;
			else if (footprint[0] == attacker->getPosition())
			{
				logWarning("Entity::projectileImpact()","force origin is shooter");
				goto knockbackDone;
			}
			else
			{
				vector<Point> line;
				lineBresenhamPoints_40ff30(footprint[0],attacker->getPosition(),&line);
				origin = line[1];
			}

			int direction = unknown4374c0(origin,footprint[0]);
			int displaceChance = 50;
			for (int i = distance; i > 0; i--)
			{
				Point next(footprint[0],directionOffsets[direction]);
				if (unknown5c84f0(next))
				{
					HEntity selfHandle = self;
					HEntity blocker;
					int collisionDamage = 0;
					int impactDamage = explosion->unknown30;
					if (unknown5c85a0(next,false))
					{
						blocker = cells(next)->getEntity();
						if (blocker->getSize() == 1 && blocker->unknown5d1390() != 0 && rng.chance((blocker->unknown45a340() - data->unknown98) * 10 + displaceChance))
						{
							vector<Point> candidates;
							candidates.push_back(Point(next) += directionOffsets[unknownB962e8[direction]]);
							candidates.push_back(Point(next) += directionOffsets[direction]);
							candidates.push_back(Point(next) += directionOffsets[unknownB96308[direction]]);
							for (int j = candidates.size() - 1; j >= 0; j--)
							{
								if (!blocker->unknown5c84f0(candidates[j]) || blocker->unknown5c8710(candidates[j]) || blocker->unknown5c85a0(candidates[j],false))
									eraseAt_9d5190(candidates,j);
							}
							if (!candidates.empty())
							{
								unknown5ddac0(randomPoint_9d5350(candidates),0);
								blocker->unknown5fdd30();
							}
							collisionDamage = impactDamage;
							if (blocker.operator->() != NULL && blocker->unknown45a340() > 1)
								collisionDamage /= blocker->unknown45a340();
						}
					}
					if (!unknown5c85a0(next,false))
					{
						if (!unknown5c8710(next))
						{
							MESSAGE(isPlayerSelf ? 0xa2 : 0xa3,NULL,NULL,0,self,HEntity(),NULL,0);
							unknown5ddac0(next,0);
							Object717be0 *object = world->unknown717be0();
							if (object != NULL)
								object->unknown45b6b0(self,getPosition());
							if (!unknown5fdd30())
								return;
						}
						else if (cells(next)->getProp().isValid() && !cells(next)->getProp()->isPassableFor(self) && cells(next)->getProp()->unknown45c630() != -1 && cells(next)->getProp()->unknown45c630() <= impactDamage)
						{
							cells(next)->getProp()->unknown45ceb0(attacker,unknownA7);
							if (selfHandle.operator->() == NULL)
								return;
							unknown5ddac0(next,0);
							Object717be0 *object = world->unknown717be0();
							if (object != NULL)
								object->unknown45b6b0(self,getPosition());
							if (!unknown5fdd30())
								return;
						}
					}
					if (collisionDamage != 0 && blocker.operator->() != NULL)
						blocker->takeDamage(10,weapon,explosion,collisionDamage,4,0,0,unknownA7,attacker,0,8,0,0,0);
					if (selfHandle.operator->() == NULL)
						return;
				}
			}
		}
	}
knockbackDone:
	// a hostile attack on a garrisoned group may activate the nearest garrison
	if ((group->getType() == 3 || group->getType() == 4) && attacker.operator->() != NULL && attacker->unknown5cb680(world->unknown463890(3)) && getTarget() == 0 && (!ai->unknown459090() || ai->unknown4590f0()->unknown458950(1) == NULL))
	{
		bool highAlert = ai->getMode() >= 6;
		int level = highAlert ? 2 : 1;
		if (rng.chance(alarmResponses[level].chance) && !unknownCf65bf)
		{
			HProp best;
			unsigned int bestLength;
			vector<vector<Point> > *markers = world->getMarkers();
			for (unsigned int i = 0; i < (*markers)[5].size(); i++)
			{
				if (pointDistance(getPosition(),(*markers)[5][i]) > alarmResponses[level].range || cells((*markers)[5][i])->getProp()->getState() != 0 || cells((*markers)[5][i])->getProp()->getData()->dispatch != NULL)
					continue;

				vector<Point> path;
				if (world->unknown7168e0(getPosition(),world->unknown462f60(cells((*markers)[5][i])->getProp()),self.operator->(),&path) && path.size() - 1 <= (unsigned int)alarmResponses[level].range && (best.isNull() || path.size() - 1 < bestLength))
				{
					bestLength = path.size();
					best = cells((*markers)[5][i])->getProp();
				}
			}

			if (best.isValid())
			{
				bool announce = ai->unknown581140();
				bool silent = announce & !unknown45acb0(0x20);
				if (!silent)
				{
					if (announce && unknown45acb0(0x20))
						MESSAGE(0x241,NULL,NULL,0,self,HEntity(),NULL,0);
					else
						MESSAGE(highAlert ? 0x242 : 0x23f,NULL,NULL,0,self,HEntity(),NULL,0);
					do
					{
						messageLog.setUnknown34(1);
						if (1 && !(unknownD28fb0 && 1 && 1))
							playSound_4541b0(0x127,0,0);
						MESSAGE(0x324,&("ALERT: Activating " + best->getData()->unknown65cc80() + "."),NULL,0,HEntity(),HEntity(),NULL,0);
						logMsgs->scrollToEnd();
					} while (0);
					unknown5141b0(0x6a,NULL,NULL,0,HEntity(),0);
					best->getData()->dispatch = new Dispatch(best,0x70,alarmResponses[level].strength,0,0,0,0,HEntity(),level,getPosition(),1,0);
					if (difficulty != 0 && world->unknown4631f0(self) && !world->isVisible(best->getPosition()))
						mapView->unknown8197f0(best->getPosition(),true);
					if (attacker->isPlayer() && playerData.isSlotEmpty(0x41) && world->unknown4631f0(self))
						playerData.unknown77fbc0(0x41);
				}
				else
				{
					statTracker.add4729d0(0x241,1,string(""),-1);
					MESSAGE(highAlert ? 0x243 : 0x240,NULL,NULL,0,self,HEntity(),NULL,0);
					if (statTracker.current->values[0x241] == 10)
						playerData.unknown77fbc0(0x72);
				}
			}
		}
	}

	if (rolledValues != NULL && attacker.operator->() != NULL && attacker == world->getEntity671() && isPlayerSelf)
	{
		int sayID = 0x77;
		if (explosion == NULL)
			sayID = 0x3a;
		else if (explosion->damageType != 3)
			sayID = 0x3b;
		if (sayID != 0x77 && rolledValues != NULL)
			rolledValues->say(sayID,false,string(""));
	}
}
