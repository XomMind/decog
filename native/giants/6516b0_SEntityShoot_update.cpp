// 0x6516b0 SEntityShoot::update (COGMIND.exe Beta 17.1, 0x7365 bytes): semantic reconstruction, not byte-matched.
// bool SEntityShoot::update(): runs one step of an entity's attack (all weapons of a volley, one after the other).
// Notes, open questions and gdiff numbers: docs/giants/6516b0.md.
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

	Point();								// 0x453b40 (-1,-1)
	Point(int v);							// 0x409990, (v,v)
	Point(int x_, int y_);					// 0x46ca20
	Point(const Point &p);					// 0x46ca50
	Point(const Point &a, const Point &b);	// 0x4099f0 (sum)
	Point &operator=(const Point &p);		// 0x46ca50 (folded with the copy ctor)
	Point &operator*=(int factor);			// NOTE: placeholder name (0x40a300)
	bool operator==(const Point &p) const;	// 0x409b90
	bool operator!=(const Point &p) const;	// 0x409bd0
};

struct Area	// NOTE: placeholder name
{
	Point min;	// +0x0
	Point max;	// +0x8

	Area();		// 0x40b100
};

struct Range	// NOTE: placeholder name
{
	int min;
	int max;

	int randomInRange_40c130();	// NOTE: placeholder name
};

struct FRange	// NOTE: placeholder name (OpQ1_FRange)
{
	float min;
	float max;

	float clamp_40c760(float value);	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;
public:
	T &operator()(const Point &p);	// 0x9ced70
	T &operator()(int x, int y);	// 0x9ceda0
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
	void getBounds(const Point &p, int radius, Area *out);	// NOTE: placeholder name (0x9b4430)
	void getNeighbors_9ce500(const Point &p, vector<Point> &out);	// NOTE: placeholder name
};

class Entity;
class Item;
class Prop;
class Group;
class Inventory;
class EntityAI;
struct ItemData;
struct EntityData;
struct TurnRecord;

class HEntity
{
	int	ID;
public:
	HEntity();								// 0x9b6590
	bool isNull() const;					// 0x9b65d0
	bool isValid() const;					// 0x9b7230
	void clear();							// NOTE: placeholder name (0x9b7270)
	Entity *operator->() const;				// 0x9b6570
	bool operator==(HEntity other) const;	// 0x9b78e0
	bool operator!=(HEntity other) const;	// 0x9b6510
};

class HItem
{
	int	ID;
public:
	HItem();								// 0x9b6590
	bool isNull() const;					// 0x9b65d0
	bool isValid() const;					// 0x9b7230
	Item *operator->() const;				// 0x9b65b0
	bool operator!=(HItem other) const;		// 0x9b6510
};

class HProp
{
	int	ID;
public:
	HProp();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	Prop *operator->() const;				// 0x9b64f0
};

class HGroup
{
	int	ID;
public:
	Group *operator->() const;				// 0x9b7250
};

class HBattleState	// NOTE: placeholder name (handle of a battle state, SEntityShoot+0x04)
{
	int	ID;
public:
	HBattleState();							// 0x9b6590
};

class HRecord	// NOTE: placeholder name (handle returned by GM::createA, 0x7930e0)
{
	int	ID;
};

class Group
{
public:
	int unknown9b4350();					// NOTE: placeholder name (ICF'd trivial getter of +0x08, the group type)
};

struct ItemEffect	// NOTE: placeholder name
{
	int		type;
	int		state;

	ItemEffect(int type_, int state_);		// 0x46ca20
};

struct ProjectileRecord	// NOTE: placeholder name (OpR2b_Rec501030; ItemData+0x190/+0x198 and the effect "type")
{
	struct Variant	// NOTE: placeholder name (elements of +0xc8)
	{
		int		unknown00;
		int		unknown04;
		int		unknown08;
		struct Sprite	// NOTE: placeholder name
		{
			string	unknown18;	// +0x18
		}		*unknown0c;			// +0x0c
	};

	int				unknown40;		// +0x40
	bool			unknown44;		// +0x44
	vector<Variant>	unknownC8;		// +0xc8

	bool unknown5012a0(const Point &pos);	// NOTE: placeholder name
};

struct ExplosionRecord	// NOTE: placeholder name (ItemData+0x1a0)
{
	int		unknown2c;		// +0x2c (damage type)
	int		unknown30;		// +0x30
};

struct ItemData	// NOTE: placeholder name (the weapon's item type)
{
	int					unknown44;	// +0x44, NOTE: placeholder name (slot/category, 0x14..0x19 weapons)
	int					unknown100;	// +0x100, NOTE: placeholder name (range)
	int					unknown11c;	// +0x11c, NOTE: placeholder name (spread)
	int					unknown128;	// +0x128, NOTE: placeholder name (damage type)
	bool				unknown165;	// +0x165
	int					unknown168;	// +0x168
	int					unknown174;	// +0x174
	ProjectileRecord	*unknown190;	// +0x190
	ProjectileRecord	*unknown198;	// +0x198
	ExplosionRecord		*unknown1a0;	// +0x1a0
};

class Item
{
public:
	int unknown9b6bf0();					// NOTE: placeholder name (ICF'd trivial getter of +0x1c)
	Inventory *unknown44a7d0();				// NOTE: placeholder name (ICF'd trivial getter of +0x58)
	int unknown45cb30();					// NOTE: placeholder name (ICF'd trivial getter of +0x44, use count)
	ItemData *unknown9b4350();				// NOTE: placeholder name (ICF'd trivial getter of +0x08, the data)
	const string &unknown457860();			// NOTE: placeholder name (data->+0x08, the data name)
	int unknown457880();					// NOTE: placeholder name (data->+0x44, slot)
	int unknown4578a0();					// NOTE: placeholder name (data->+0x48)
	int unknown4578c0();					// NOTE: placeholder name (data->+0x4c)
	int unknown457900();					// NOTE: placeholder name (data->+0x50)
	ItemEffect *getEffect(int type);		// NOTE: placeholder name (0x457b70)
	int getEffectValue(int type);			// NOTE: placeholder name (0x457be0)
	bool unknown457cf0();					// NOTE: placeholder name (+0x28 != -1)
	bool unknown457d10();					// NOTE: placeholder name (+0x2c < 0)
	int unknown457f90();					// NOTE: placeholder name (data->+0xf0, special type)
	int unknown457fb0();					// NOTE: placeholder name (data->+0xf4)
	int unknown4580a0();					// NOTE: placeholder name (data->+0x100, range)
	int unknown4580c0();					// NOTE: placeholder name (data->+0x104)
	int unknown458100();					// NOTE: placeholder name (data->+0x14c)
	int unknown458120();					// NOTE: placeholder name (data->+0x118, shots per volley)
	int unknown458160();					// NOTE: placeholder name (data->+0x15c)
	bool unknown458220();					// NOTE: placeholder name (+0x40)
	int unknown458240();					// NOTE: placeholder name (data->+0x160)
	void unknown458310(int amount);			// NOTE: placeholder name
	void unknown458580();					// NOTE: placeholder name (+0x44 += 1)
	void addEffect(ItemEffect *effect);		// NOTE: placeholder name (0x4585a0)
	void unknown4585c0(int type);			// NOTE: placeholder name (removes an effect)
	string getName(int a, int b);			// NOTE: placeholder name (0x571db0)
	int unknown5788e0();					// NOTE: placeholder name (energy cost)
	int unknown5789c0();					// NOTE: placeholder name (matter cost)
	int unknown578b10();					// NOTE: placeholder name
	void unknown578f20(vector<Point> *out, int a);	// NOTE: placeholder name
	int unknown579050();					// NOTE: placeholder name
	float unknown579090();					// NOTE: placeholder name
	void setBroken(int a, bool b);			// 0x5795b0
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class Inventory	// NOTE: placeholder name (OpT2_Inventory; Entity+0xec, Item+0x58)
{
public:
	vector<TurnRecord *> *unknown51ca20(vector<int> &types, HEntity e, HEntity a, HProp b, HItem c, int d, vector<TurnRecord *> *records, int *value, int f, int g);	// NOTE: placeholder name
};

class Prop
{
public:
	void unknown664840(HEntity attacker, int type, vector<TurnRecord *> *records, ItemData *weapon, float multiplier, bool a, int b, void *c);	// NOTE: placeholder name
};

struct EntityData	// NOTE: placeholder name (robot definition)
{
	string getName459c30();					// NOTE: placeholder name (OpR1e_Variant::getName459c30)
};

class EntityAI
{
public:
	bool unknown5814f0(HEntity e);			// NOTE: placeholder name
};

struct ExplosionData;	// NOTE: opaque here

class Entity
{
public:
	EntityData *unknown9b4350();			// NOTE: placeholder name (ICF'd trivial getter of +0x08)
	const string &getLabel();				// NOTE: placeholder name (0x416f40, returns this+0x0c)
	int getFaction();						// 0x45a2c0
	int getSize();							// 0x45a360
	HGroup getGroup();						// 0x45a3f0
	string unknown45a410();					// NOTE: placeholder name
	const Point &getPosition();				// 0x45a4a0
	Point unknown45a4c0();					// NOTE: placeholder name
	int getTarget();						// NOTE: placeholder name (0x45a760, returns +0x70)
	int unknown45a8d0();					// NOTE: placeholder name (+0x90, energy)
	int unknown45a920();					// NOTE: placeholder name (+0x94, matter)
	bool isHostileTo(HEntity e);			// 0x45aa70
	bool unknown45aaa0(HEntity e);			// NOTE: placeholder name
	vector<HItem> *getInventoryList();		// 0x45ab00
	Inventory *getInventory();				// 0x45ad90
	void unknown45b1b0(int amount);			// NOTE: placeholder name (energy -= amount)
	void unknown45b1e0(int amount);			// NOTE: placeholder name (matter -= amount)
	EntityAI *unknown45b590();				// NOTE: placeholder name (ICF'd trivial getter of +0x144, the AI)
	void unknown451600(HEntity e);			// NOTE: placeholder name (ICF'd setter of +0x118)
	int unknown490840();					// NOTE: placeholder name (ICF'd trivial getter of +0x8c)
	bool isPlayer();						// 0x5c7600
	int unknown5c7d30();					// NOTE: placeholder name
	int unknown5c7e90();					// NOTE: placeholder name
	int unknown5c7fc0(HEntity other);		// NOTE: placeholder name
	Point unknown5c80f0(const Point &p);	// NOTE: placeholder name
	bool unknown5c87f0(const Point &p);		// NOTE: placeholder name
	int unknown5c8c40(int type);			// NOTE: placeholder name
	int unknown5cad50();					// NOTE: placeholder name
	int unknown5d2090(int type);			// NOTE: placeholder name
	int unknown5d22a0(int type);			// NOTE: placeholder name
	HItem unknown5d2380(int type);			// NOTE: placeholder name
	bool isXomCandidate();					// 0x5d51a0
	float unknown5d7bc0();					// NOTE: placeholder name
	float unknown5d7bf0(int damageType);	// NOTE: placeholder name
	void unknown5dea60(int amount, int a);	// NOTE: placeholder name
	void unknown5defa0(int amount, bool a);	// NOTE: placeholder name
	void projectileImpact(HEntity attacker, int type, vector<TurnRecord *> *records, ItemData *weapon, float multiplier, Point *origin, bool a, ExplosionData *explosion, int *explosionDamage);	// 0x5f1010
	void unknown601700(HItem item);			// NOTE: placeholder name
	void unknown602170(HItem item, int direction);	// NOTE: placeholder name
	void unknown6028b0(HItem item);			// NOTE: placeholder name
	bool unknown603030(HItem item);			// NOTE: placeholder name
	bool unknown603280(HItem item);			// NOTE: placeholder name
	void die(bool unseen, int damageType, HEntity killer, int cause, int critType, struct DeathSource *source, vector<TurnRecord *> *records, bool quiet);	// 0x633790
	void unknown63c120();					// NOTE: placeholder name
	void unknown64e7e0();					// NOTE: placeholder name (OpS3b_ItemOwner::unknown64e7e0)
};

class Cell
{
public:
	HProp getProp();						// 0x45d550
	HEntity getEntity();					// 0x45d250
	int unknown45a6e0();					// NOTE: placeholder name (ICF'd trivial getter)
	bool canCaveIn();						// 0x66af50
	void unknown66d470(HEntity e, int amount, bool c, bool d);	// NOTE: placeholder name
	void destabilize(int amount, bool player);	// 0x66d4e0
	void unknown66e650(HEntity attacker, int type, vector<TurnRecord *> *records, ItemData *weapon, float multiplier, bool a);	// NOTE: placeholder name
};

class Obj515ca0	// NOTE: placeholder name; 0x40 bytes in the exe, layout not reconstructed
{
public:
	Obj515ca0(HEntity a, ExplosionRecord *id, const Point &pos, HEntity b, const Point &c, const Point &d);	// 0x515ca0
};

struct E8_1	// NOTE: placeholder name (elements of SEntityShoot+0x2c)
{
	int unknown0;
};

class OpR2b_Obj500dd0	// NOTE: placeholder name (projectile; 100 bytes in the exe, layout not reconstructed)
{
public:
	OpR2b_Obj500dd0(ItemData *weapon, HEntity shooter, int type, int range, float multiplier, HItem a, HItem b, int c, HBattleState state, vector<E8_1> *elems, vector<TurnRecord *> *records, int d);	// 0x500dd0
};

class OpR1F_Named460780	// NOTE: placeholder name (shot record; 0x3c bytes in the exe)
{
public:
	OpR1F_Named460780(string name, Point from, Point to, const Point &subcell, const Point &offset);	// 0x460780
};

struct ClusterCell	// NOTE: placeholder name (0x10 bytes, elements of ClusterState::list)
{
	Point	pos;		// +0x00
	int		amount;		// +0x08
	int		time;		// +0x0c

	ClusterCell(Point pos_, int amount_, int time_);	// NOTE: placeholder name (0x4606d0)
};

struct ClusterState	// NOTE: placeholder name (global at 0xd2a864)
{
	HEntity					owner;		// +0x00
	float					heat;		// +0x04, NOTE: placeholder name
	vector<ClusterCell *>	list;		// +0x08
	Point					origin;		// +0x18
	Point					target;		// +0x20

	void unknown460700();				// NOTE: placeholder name (deletes the list entries)
};

class Effect	// NOTE: placeholder name
{
public:
	Point	unknown68;	// +0x68
	Point	unknown70;	// +0x70
};

class EffectInstance	// NOTE: placeholder name
{
public:
	void init(void *owner, ProjectileRecord *type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class EffectMgr	// NOTE: placeholder name
{
public:
	EffectInstance *create();				// NOTE: placeholder name (0x508610)
	vector<Effect *> &unknown4549b0();		// NOTE: placeholder name (returns this+0x24)
};

class Bresenham2DStepperSubcell
{
	int	data[11];	// NOTE: placeholder layout (base class Bresenham2DStepper + subcells)
public:
	Bresenham2DStepperSubcell(const Point &fromCell, const Point &fromSubcell, const Point &toCell, const Point &toSubcell, int subcells_);	// 0x410320
	virtual ~Bresenham2DStepperSubcell();	// 0x410400
	bool next(Point &cell, Point &subcell);	// NOTE: placeholder name (0x410420)
};

class Map	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	HEntity getPlayer();					// NOTE: placeholder name (0x4630f0)
	bool isVisible(const Point &p);			// NOTE: placeholder name (0x4631c0)
	bool unknown4631f0(HEntity e);			// NOTE: placeholder name
	bool unknown463380(int x, int y);		// NOTE: placeholder name
	bool unknown4633c0(const Point &p);		// NOTE: placeholder name
	int unknown463fa0();					// NOTE: placeholder name (+0xa70)
	int getTurn();							// 0x464270
	bool unknown464370();					// NOTE: placeholder name (+0xb06)
	bool unknown464390();					// NOTE: placeholder name (+0xb07)
	void addList9bc(HEntity e);				// NOTE: placeholder name (0x465360)
	void raiseUnknownA70(int value);		// NOTE: placeholder name (0x465490)
	void setFlagA74(bool flag);				// NOTE: placeholder name (0x4654d0)
	void unknown465a70();					// NOTE: placeholder name (+0xc14 += 1)
	bool unknown7170a0(HEntity e, const Point &p, vector<Point> &path, vector<int> &hits, vector<int> &blocks, Point &last, const Point *at, int atMode, bool f1, bool f2);	// NOTE: placeholder name
	bool unknown717e40(const Point &from, const Point &to, int range, Point &cur, Point &last, ItemData *attack, vector<Point> *hits);	// NOTE: placeholder name
	float unknown718430(HEntity e, const Point &p, vector<float> *breakdown, int range);	// NOTE: placeholder name (melee hit chance)
	float unknown719a90(HEntity e, const Point &p, vector<float> *breakdown, bool *sneakAttack);	// NOTE: placeholder name (ranged hit chance)
	void addEntitiesAround(HEntity e, vector<HEntity> *out);	// NOTE: placeholder name (0x71c550)
	void unknown732ce0(bool force);			// NOTE: placeholder name
	void setPausedShootState(HBattleState state);	// NOTE: placeholder signature (0x733070)
	void unknown735720(HEntity source, HEntity target, bool flag);	// NOTE: placeholder name
	void unknown7358c0(HEntity source, HEntity target);	// NOTE: placeholder name
	void thrownItemArrived(HEntity thrower, HItem item, int mode, const Point &position, vector<TurnRecord *> *records);	// 0x7499f0
	void unknown74b060(const Point &p, int type, int percent);	// NOTE: placeholder name
	HRecord addRecord(HRecord h);			// NOTE: placeholder name (0x777a20)
};

class GM	// NOTE: placeholder name (0xcefaa8)
{
public:
	HRecord createA(Obj515ca0 *record);		// NOTE: placeholder name (0x7930e0)
};

class PlayerData	// NOTE: placeholder name (0xcf45d8)
{
public:
	bool isSlotEmpty(unsigned int index);	// NOTE: placeholder name (0x46de40); true while achievement <index> is not earned
	bool unknown77f260(int id);				// NOTE: placeholder name
	void unknown77fbc0(int id);				// NOTE: placeholder name; earns achievement <id>
	bool hasCompanion();					// NOTE: placeholder name (0x780790)
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
	int unknown472c70(int id);				// NOTE: placeholder name (0x472c70, current->get472440(id))
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
	void drawStatus(bool damaged);			// NOTE: placeholder name (0x4a8e70)
	void unknown890710(bool flag);			// NOTE: placeholder name
};

class CParts
{
public:
	CPart *unknown894e70(HItem item);		// NOTE: placeholder name
};

class Audio	// NOTE: placeholder name (0xd25450)
{
public:
	bool	enabled;		// +0x00

	void unknown69e700(int id, int a, float b);	// NOTE: placeholder name
};

class SpawnTracker	// NOTE: placeholder name (OpU5_SpawnTracker)
{
public:
	bool spawn(unsigned int index, bool force, string extra);	// NOTE: placeholder name (0x7aa280)
};

class Companion	// NOTE: placeholder name (OpS1f_ItemRec, pointer at 0xcf4ac8)
{
public:
	bool			unknown0c;		// +0x0c
	int				unknown14;		// +0x14
	SpawnTracker	*tracker;		// +0x30

	void increase48b8c0(int amount);		// NOTE: placeholder name (0x48b8c0)
};

class ParticleMgr	// NOTE: placeholder name (OpV4a_EffectMgr, pointer at 0xcec138)
{
public:
	void unknown965430(int id);				// NOTE: placeholder name
	void unknown966c10(int id, int value);	// NOTE: placeholder name
};

class SEntityShoot	// NOTE: placeholder layout (vtable at +0x00; BattleState in src/op/op_s1d.cpp)
{
public:
	HBattleState	handle;				// +0x04, NOTE: placeholder name
	int				state;				// +0x08, NOTE: placeholder name (0 new, 1 waiting, 2 firing)
	int				time;				// +0x0c, NOTE: placeholder name
	HEntity			shooter;			// +0x10, NOTE: placeholder name
	int				type;				// +0x14, NOTE: placeholder name (0 ranged, 1 melee)
	Point			target;				// +0x18, NOTE: placeholder name
	Point			targetSubcell;		// +0x20, NOTE: placeholder name
	HEntity			targetEntity;		// +0x28, NOTE: placeholder name
	vector<E8_1>	unknown2c;			// +0x2c
	bool			unknown3c;			// +0x3c
	bool			martialStrike;		// +0x3e, NOTE: placeholder name
	HEntity			unknown40;			// +0x40
	vector<HItem>	weapons;			// +0x44, NOTE: placeholder name
	int				index;				// +0x54, NOTE: placeholder name (next weapon)
	int				pending;			// +0x58, NOTE: placeholder name (projectiles in flight)
	int				unknown5c;			// +0x5c
	int				hits;				// +0x60, NOTE: placeholder name
	int				misses;				// +0x64, NOTE: placeholder name
	int				gunslingCount;		// +0x68, NOTE: placeholder name
	vector<Point>	spreadTargets;		// +0x6c, NOTE: placeholder name

	bool update();						// 0x6516b0
	Point unknown658a70(const Point &origin, Point target, float spread);	// NOTE: placeholder name (miss deviation)
	bool unknown6591c0(HEntity e);		// NOTE: placeholder name
	bool unknown659220(HEntity e);		// NOTE: placeholder name
};

struct DeathSource;	// NOTE: opaque here

bool unknown5111e0(int id, const string *text1, const string *text2, int value, HEntity subject, HEntity object, const Point *pos, int extra);	// NOTE: placeholder name (show message)
void unknown5141b0(int id, const string *a, const string *b, int c, HEntity e, int d);	// NOTE: placeholder name (history/log record)
void opW5_message(int type, HEntity entity, const string &text, int flag);	// NOTE: placeholder name (0x49c610, adds a log message)
void opW5_unknown49bde0(HEntity e);			// NOTE: placeholder name
void opR1d_4541b0(int sound, int a, int b);	// NOTE: placeholder name (play sound)
void logError(string location, string message);	// 0x404f10
string intToString(int value);				// 0x4051f0
string OpY1_intToStringSigned(int value);	// NOTE: placeholder name (0x405560, with a leading '+')
string OpQ1_pointToString(const Point &p);	// NOTE: placeholder name (0x40a4a0)
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name
int unknown4374c0(const Point &from, const Point &to);	// NOTE: placeholder name (direction from -> to)
bool OpS1c_unknown4569a0(int id, HEntity a, HEntity b, HProp c, HItem item, int d, const string *name, void *e, HEntity f, HProp g, HItem h, int i);	// NOTE: placeholder name (0x4569a0, trigger)
void opR1f_460820(OpR1F_Named460780 *entry);	// NOTE: placeholder name (adds a shot record, keeps 5)
void opr2b_rotatePoint(const Point &origin, const Point &p, float angle, Point &out);	// NOTE: placeholder name (0x501fc0)
void OpS3b_f651590(ItemData *data, Point &from, Point &to, vector<Point> &fromOut, vector<Point> &toOut);	// NOTE: placeholder name
int minInt(int a, int b);					// 0x9cdb30
int maxInt(int a, int b);					// 0x9cdb60
bool containsPoint(vector<Point> &v, Point p);	// NOTE: placeholder name (0x9d0ce0)
bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (low <= value <= high)
unsigned int OpT8b_Fn9d9ab0(vector<float> &weights);	// NOTE: placeholder name (weighted random index)
template <class T> void eraseAt(vector<T> &v, int i);		// NOTE: placeholder name (0x9da940/0x9d5190 family)
template <class T> void eraseStep(vector<T> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440, erases and steps i back)
template <class T> void shuffle(vector<T> &v);				// NOTE: placeholder name (0x9d9fc0/0x9d7350)
template <class T> void removeVectorElement(vector<T> &v, int i);	// 0x9de6f0

extern RNG					rng;					// 0xd30908
extern Map					*world;					// 0xcefc4c
extern EffectMgr			*effectMgr;				// 0xcefc50
extern Point				effectOrigin;			// 0xd2e20c
extern Array2D<Cell *>		cells;					// 0xcfd44c
extern GM					*gm;					// 0xcefaa8
extern PlayerData			playerData;				// 0xcf45d8
extern OpR1h_Stats			stats;					// 0xd2c658
extern ConsoleA				*consoleA;				// 0xcec058
extern CLogMsgs				*logMsgs;				// 0xcec0b4
extern CLogMsgs				*combatLog;				// 0xcec0c4, NOTE: placeholder name
extern CParts				*cparts;				// 0xcec088
extern Audio				audio;					// 0xd25450
extern vector<int>			effectTypes;			// 0xd2f0f8
extern bool					factionTableB951c0[];
extern int					gameMode;				// 0xcf462c, NOTE: placeholder name
extern int					unknownD28d18;			// combat log detail level
extern unsigned int			tickCount;				// NOTE: placeholder name (0xcaed20)
extern int					unknownCefa78;			// NOTE: placeholder name (time per update)
extern Companion			*unknownCf4ac8;
extern ParticleMgr			*unknownCec138;
extern int					unknownCefb68;
extern int					unknownBbca50[];
extern FRange				unknownCf195c;			// ranged hit chance limits
extern FRange				unknownD37978;			// melee hit chance limits
extern EntityData			*unknownCefc0c;
extern int					unknownCf4b98;
extern int					unknownCf4b9c;			// consecutive melee hits
extern int					unknownCf4ba0;			// consecutive melee misses
extern ClusterState			unknownD2a864;
extern Range				unknownD35bd0;
extern bool					unknownCefb25;			// debug flag
extern vector<string>		unknownD2d4c8;			// debug log
extern vector<Point>		unknownD3976c;
extern vector<Point>		unknownD29d6c;
extern vector<Point>		unknownD2ac84;
extern string				breakdownLabels[];		// 0xd37a90, NOTE: placeholder name (0x13 hit chance factors)
extern bool					unknownBa0968[];
extern int					unknownCefb38;

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
#define HISTORY(id,a,b,c,e,d) \
	do \
	{ \
		unknown5141b0(id,a,b,c,e,d); \
	} while (0)
// percentage with rounding away from zero
#define PERCENT_ROUNDED(x) (int)(((x) + ((x) > 0 ? 0.005 : -0.005)) * 100.0)
// gunslinging is always available in this build (the exe tests the constant 100)
#define GUNSLINGING 100	// NOTE: placeholder name
// address of a temporary string that lives until the end of the full expression (the exe passes &temp)
#define TEMP_PTR(s) (&static_cast<const string &>(s))

//==================================================================
// SEntityShoot::update
//==================================================================

bool SEntityShoot::update()
{
	if (shooter.operator->() == NULL || weapons.empty())
		return true;

	if (state == 0)
		state = 2;
	time += unknownCefa78;

	switch (state)
	{
	case 1:
		return false;
	case 2:
	{
		// first weapon at an entity: notify the target and fire the attack triggers
		if (index == 0 && cells(target)->getEntity().isValid())
		{
			HEntity victim = cells(target)->getEntity();
			if (!unknown3c)
			{
				if (!unknown6591c0(victim))
					world->unknown735720(shooter,victim,false);
				if (!unknown659220(victim))
					world->unknown7358c0(shooter,victim);
			}
			OpS1c_unknown4569a0(10,shooter,shooter,HProp(),HItem(),0,0,shooter->getInventory(),shooter,HProp(),HItem(),0);
			if (shooter.operator->() == NULL)
				return true;
			OpS1c_unknown4569a0(9,shooter,victim,HProp(),HItem(),0,0,shooter->getInventory(),victim,HProp(),HItem(),0);
			if (shooter.operator->() == NULL)
				return true;
		}

		bool skipAnimation = false;
		for (;;)
		{
			if (shooter.operator->() == NULL)
				return true;

			// pick the next usable weapon
			while (true)
			{
				if (weapons[index].operator->() != NULL)
					weapons[index]->unknown458580();
				if (weapons[index].operator->() != NULL && weapons[index]->unknown458220())
				{
					if (shooter == world->getPlayer())
					{
						stats.add4729d0(0x1d2,1,string(""),-1);
						if (stats.current->values[0x1d2] == 10)
							playerData.unknown77fbc0(0x2c);
					}
					if (rng.chance(weapons[index]->unknown458160()))
						shooter->unknown601700(weapons[index]);
				}
				if (weapons[index].operator->() != NULL && weapons[index]->getEffect(0x5a) != NULL)
				{
					if (weapons[index]->getEffectValue(0x5b) == 0 || weapons[index]->unknown45cb30() > weapons[index]->getEffectValue(0x5b))
					{
						if (rng.chance(weapons[index]->getEffectValue(0x5a)))
							shooter->unknown6028b0(weapons[index]);
					}
				}
				if (weapons[index].operator->() != NULL)
				{
					if (weapons[index]->getEffect(0x5c) != NULL && (weapons[index]->getEffectValue(0x5d) == 0 || weapons[index]->unknown45cb30() > weapons[index]->getEffectValue(0x5d)))
					{
						float chance = weapons[index]->getEffectValue(0x5c) / 10.0f;
						if (weapons[index]->getEffectValue(0x5d) != 0 && weapons[index]->unknown45cb30() > weapons[index]->getEffectValue(0x5d))
						{
							for (int i = 2; weapons[index]->unknown45cb30() / weapons[index]->getEffectValue(0x5d) >= i; i++)
								chance += chance;
						}
						if (rng.chance(chance))
						{
							if (shooter->isPlayer())
							{
								MESSAGE(0x180,TEMP_PTR(weapons[index]->getName(0,0)),NULL,0,shooter,HEntity(),NULL,0);
								HISTORY(0x33,TEMP_PTR(weapons[index]->getName(0,0)),NULL,0,HEntity(),0);
							}
							weapons[index]->setBroken(-2,true);
						}
					}
					shooter->unknown603030(weapons[index]);
					shooter->unknown603280(weapons[index]);
				}

				if (weapons[index].operator->() == NULL)
				{
					eraseAt(weapons,index);
					if (index == weapons.size())
						return true;
					continue;
				}

				if (world->unknown464370())
					break;

				int energy = weapons[index]->unknown5788e0();
				int matter = weapons[index]->unknown5789c0();
				if (shooter->unknown45a8d0() - energy >= 0 && shooter->unknown45a920() - matter >= 0 && !weapons[index]->unknown457d10())
				{
					shooter->unknown45b1b0(energy);
					shooter->unknown45b1e0(matter);
					break;
				}

				eraseAt(weapons,index);
				if (index == weapons.size())
					return true;
			}

			index++;
			pending = 0;
			bool lastWeapon = index == weapons.size();
			if (!lastWeapon && !skipAnimation)
				world->unknown732ce0(true);
			skipAnimation = false;
			HItem weapon = weapons[index - 1];

			// player statistics, achievements and weapon sounds
			if (shooter == world->getPlayer())
			{
				if (weapon->unknown457880() >= 0x1a)
					stats.add4729d0(0x1a3,1,string(""),-1);
				else
				{
					stats.add4729d0(0x17d,1,string(""),-1);
					switch (weapon->unknown457880())
					{
					case 0x14:
						if (playerData.isSlotEmpty(0xd6) && weapon->unknown4578c0() >= 4 && weapon->getName(0,0).find("Storm") != string::npos)
							playerData.unknown77fbc0(0xd6);
					case 0x16:
						stats.add4729d0(0x17e,1,string(""),-1);
						break;
					case 0x15:
						if (playerData.isSlotEmpty(0xdc) && weapon->getName(0,0).find("Potential Cannon") != string::npos)
							playerData.unknown77fbc0(0xdc);
						if (playerData.isSlotEmpty(0x165) && weapon->getName(0,0).find("L-Cannon") != string::npos)
							playerData.unknown77fbc0(0x165);
					case 0x17:
						stats.add4729d0(0x17f,1,string(""),-1);
						break;
					case 0x18:
						if (playerData.isSlotEmpty(0x154) && weapon->unknown457860() == "Supercharged Sigix Terminator")
							playerData.unknown77fbc0(0x154);
						stats.add4729d0(0x180,1,string(""),-1);
						break;
					case 0x19:
						stats.add4729d0(0x181,1,string(""),-1);
						break;
					}
					if (weapons.size() == 1 && (weapon->unknown457880() == 0x14 || weapon->unknown457880() == 0x15) && world->getPlayer()->unknown5d22a0(0x4e) && !weapons[0]->unknown9b4350()->unknown165)
						stats.add4729d0(0x190,1,string(""),-1);
				}

				int damageType = weapon->unknown9b4350()->unknown1a0 != NULL ? weapon->unknown9b4350()->unknown1a0->unknown2c : (weapon->unknown9b4350()->unknown190 != NULL ? weapon->unknown9b4350()->unknown128 : 10);
				if (damageType != 9)
				{
					if (weapon->unknown457880() >= 0x1a)
						stats.add4729d0(damageType + 0x1a4,1,string(""),-1);
					else
						stats.add4729d0(damageType + 0x182,1,string(""),-1);
				}

				if (weapon->unknown457860().find("Sigix Terminator",0) != string::npos || weapon->unknown457860().find("L-Cannon",0) != string::npos)
				{
					HISTORY(0x34,&weapon->unknown457860(),NULL,0,HEntity(),0);
					if (audio.enabled && weapon->unknown457860().find("L-Cannon",0) != string::npos)
					{
						if (weapon->unknown457860().find("Drained",0) == string::npos)
							audio.unknown69e700(0x45,0,0.0f);
						else
							audio.unknown69e700(0x45,3,100.0f);
					}
				}

				if (weapon->unknown457f90() == 0xd6 && unknownCf4ac8 != NULL)
					unknownCf4ac8->unknown14++;

				if (weapon->unknown458220())
					unknownCec138->unknown965430(weapon->unknown457900());

				if (weapon->unknown9b4350()->unknown44 == 0x15 && weapon->unknown9b4350()->unknown128 == 1 && !weapon->unknown9b4350()->unknown190->unknownC8.empty()
					&& string(weapon->unknown9b4350()->unknown190->unknownC8.front().unknown0c->unknown18.end() - 3,weapon->unknown9b4350()->unknown190->unknownC8.front().unknown0c->unknown18.end()) == "_CH")
					unknownCec138->unknown966c10(weapon->unknown457900(),weapon->unknown9b4350()->unknown190->unknown40);
			}

			// some weapons destabilize the ceiling
			if (OpT8b_Fn9daf80(0x14,weapon->unknown457880(),0x1e))
			{
				if (cells(shooter->unknown45a4c0())->canCaveIn())
					cells(shooter->unknown45a4c0())->destabilize(weapon->unknown457880() - 0x12,shooter->isPlayer());
			}

			// follow-up attacks pick a new hostile target
			if (type == 0 && index > 1 && weapon->unknown457f90() == 0xd6 && weapons[0].operator->() != NULL && weapons[0]->unknown457f90() == 0xd6 && targetEntity.isValid())
			{
				vector<HEntity> candidates;
				world->addEntitiesAround(shooter,&candidates);
				if (!candidates.empty())
				{
					for (unsigned int i = 0; i < candidates.size(); i++)
					{
						if (!candidates[i]->isHostileTo(shooter) || candidates[i] == targetEntity)
							eraseStep(candidates,i);
					}
					shuffle(candidates);
				}
				if (candidates.empty())
					return true;
				target = candidates[0]->unknown5c80f0(shooter->getPosition());
				targetEntity = candidates[0];
			}
			else if (type == 0 && index > 1)
			{
				if (cells(target)->getEntity().isNull() || !shooter->unknown5c87f0(target))
				{
					if (!rng.chance(shooter->unknown5d2090(0x5a) * 2 + 100))
						return true;
					vector<HEntity> candidates;
					world->addEntitiesAround(shooter,&candidates);
					if (!candidates.empty())
					{
						for (unsigned int i = 0; i < candidates.size(); i++)
						{
							if (!candidates[i]->isHostileTo(shooter))
								eraseStep(candidates,i);
						}
						shuffle(candidates);
					}
					if (candidates.empty())
						return true;
					target = candidates[0]->unknown5c80f0(shooter->getPosition());
					targetEntity = candidates[0];
				}
			}

			// gunslinging: a melee volley whose locked target died picks another one in range
			if (type == 1 && index > 1 && unknown40.isValid() && unknown40.operator->() == NULL)
			{
				unknown40.clear();
				if (GUNSLINGING)
				{
					int range = 999999;
					for (unsigned int i = index - 1; i < weapons.size(); i++)
					{
						if (weapons[i].operator->() != NULL && weapons[i]->unknown4580a0() < range)
							range = weapons[i]->unknown4580a0();
					}

					vector<Point> positions;
					vector<float> weights;
					Area area;
					cells.getBounds(shooter->getPosition(),shooter->unknown5c7d30(),&area);
					for (int y = area.min.y; y <= area.max.y; y++)
					{
						for (int x = area.min.x; x <= area.max.x; x++)
						{
							if (world->unknown463380(x,y) && cells(x,y)->getEntity().isValid() && cells(x,y)->getEntity() != shooter && shooter->isHostileTo(cells(x,y)->getEntity()) && cells(x,y)->getEntity()->isXomCandidate() && cells(x,y)->getEntity()->getTarget() == 0)
							{
								if (gameMode == 0xb && shooter->getGroup()->unknown9b4350() == 3 && cells(x,y)->getEntity()->isPlayer() && playerData.unknown77f260(100))
									continue;
								if (OpQ1_distanceCeil_40a3f0(shooter->getPosition(),Point(x,y)) <= range)
								{
									if (shooter->getGroup()->unknown9b4350() == 3 && !cells(x,y)->getEntity()->unknown5d2380(0x1f).isNull())
										continue;
									if (!containsPoint(positions,Point(x,y)))
									{
										positions.push_back(Point(x,y));
										weights.push_back(world->unknown718430(shooter,Point(x,y),NULL,0));
									}
								}
							}
						}
					}

					while (!positions.empty())
					{
						unsigned int pick = OpT8b_Fn9d9ab0(weights);
						if (cells(positions[pick])->getEntity()->getSize() >= 2)
						{
							Point pos = cells(positions[pick])->getEntity()->unknown5c80f0(shooter->getPosition());
							if (world->unknown4633c0(pos))
								positions[pick] = pos;
							else
							{
								eraseAt(positions,pick);
								removeVectorElement(weights,pick);
								continue;
							}
						}

						vector<Point> path;
						vector<int> hitList;
						vector<int> blocks;
						Point last;
						if (!world->unknown7170a0(shooter,positions[pick],path,hitList,blocks,last,NULL,4,true,true))
						{
							eraseAt(positions,pick);
							removeVectorElement(weights,pick);
							continue;
						}
						target = positions[pick];
						targetEntity = cells(positions[pick])->getEntity();
						unknown40 = cells(target)->getEntity();
						shooter->unknown451600(targetEntity);
						if (shooter->isPlayer())
						{
							MESSAGE(0xb1,&cells(target)->getEntity()->getLabel(),NULL,0,shooter,HEntity(),NULL,0);
							string text = " Gunslinging -> " + cells(target)->getEntity()->getLabel();
							if (unknownD28d18 >= 0)
								COMBAT_MESSAGE(0x2e1,&text,NULL,0,shooter,HEntity(),NULL,1);
							stats.add4729d0(0x18e,1,string(""),-1);
							gunslingCount++;
							stats.add4729d0(0x18f,gunslingCount,string(""),-1);
							world->addList9bc(unknown40);
						}
						break;
					}
				}
			}

			// hit chance
			vector<float> breakdown;
			if (index == 1 && shooter == world->getPlayer() && unknownD28d18 == 1)
				breakdown.resize(0x13,0);

			bool sneakAttack = false;
			int maxRange = 0;
			if (shooter->isPlayer() && type == 1)
			{
				for (unsigned int i = 0; i < weapons.size(); i++)
				{
					if (weapons[i].operator->() != NULL && weapons[i]->unknown4580a0() > maxRange)
						maxRange = weapons[i]->unknown4580a0();
				}
			}

			float baseHit = type == 0 ? world->unknown719a90(shooter,target,breakdown.empty() ? NULL : &breakdown,&sneakAttack) : world->unknown718430(shooter,target,breakdown.empty() ? NULL : &breakdown,maxRange);

			if (type == 0)
			{
				if (sneakAttack)
				{
					MESSAGE(shooter->isPlayer() ? 0xa7 : (shooter->unknown45aaa0(world->getPlayer()) ? 0xa8 : 0xa9),&cells(target)->getEntity()->getLabel(),NULL,0,shooter,HEntity(),NULL,0);
					if (shooter->isPlayer() && cells(target)->getEntity()->getTarget() < 6)
					{
						stats.add4729d0(0x1ad,1,string(""),-1);
						if (shooter->isHostileTo(cells(target)->getEntity()) && factionTableB951c0[cells(target)->getEntity()->getFaction()] && cells(target)->getEntity()->getTarget() == 0)
						{
							stats.add4729d0(0x1ae,1,string(""),-1);
							if (stats.current->values[0x1ae] == 0xf)
								playerData.unknown77fbc0(0xaf);
							if (weapon->unknown457f90() == 0xd6 && playerData.hasCompanion())
								unknownCf4ac8->tracker->spawn(0x25,false,cells(target)->getEntity()->unknown9b4350()->getName459c30());
						}
					}
				}

				if (index > 1 && cells(target)->getEntity().isValid())
				{
					bool followUp = weapon->unknown457f90() == 0xd6 && weapons[index - 2].operator->() != NULL && weapons[index - 2]->unknown457f90() == 0xd6;
					MESSAGE(followUp ? 0xad : (shooter->isPlayer() ? 0xaa : (shooter->unknown45aaa0(world->getPlayer()) ? 0xab : 0xac)),TEMP_PTR(weapon->getName(0,0)),&cells(target)->getEntity()->getLabel(),0,shooter,HEntity(),NULL,0);
					if (shooter->isPlayer())
					{
						stats.add4729d0(0x1af,1,string(""),-1);
						if (!followUp && unknownCf4ac8 != NULL && weapon->unknown457f90() == 0xd6 && !unknownCf4ac8->unknown0c)
						{
							unknownCf4ac8->increase48b8c0(unknownBbca50[0]);
							if (weapons[index - 2].operator->() != NULL && playerData.hasCompanion())
								unknownCf4ac8->tracker->spawn(5,false,weapons[index - 2]->getName(0,0));
						}
					}
					if (followUp && playerData.hasCompanion())
						unknownCf4ac8->tracker->spawn(0x11,false,cells(target)->getEntity()->unknown9b4350()->getName459c30());
				}
			}

			if (!breakdown.empty())
			{
				string text("Base Hit%: ");
				for (int i = 0; i < 0x13; i++)
				{
					if (breakdown[i] * 100.0 != 0)
					{
						if (i != 0)
							text += OpY1_intToStringSigned(PERCENT_ROUNDED(breakdown[i]));
						else
							text += intToString(PERCENT_ROUNDED(breakdown[i]));
						text += breakdownLabels[i];
					}
				}
				text += "=";
				if (sneakAttack)
					text += "N/A (" + intToString(PERCENT_ROUNDED(baseHit)) + ")";
				else
					text += intToString(PERCENT_ROUNDED(baseHit));
				COMBAT_MESSAGE(0x2e1,&text,NULL,0,HEntity(),HEntity(),NULL,1);
			}

			// fire every shot of the weapon
			bool animated = false;
			bool countedHit = false;
			int hitCount = 0;
			unknownCefb68 = 0;
			for (int shot = 0; weapon.operator->() != NULL && shot < weapon->unknown458120(); shot++)
			{
				if (shooter.operator->() == NULL)
					return true;

				if (weapon->unknown9b4350()->unknown128 == 0)
					unknown5c++;
				if (unknown5c == 10 && shooter->isPlayer())
					playerData.unknown77fbc0(0x8d);

				vector<TurnRecord *> *records = NULL;
				if (weapon->unknown44a7d0() != NULL)
				{
					vector<int> types;
					types.push_back(0x14);
					types.push_back(0x15);
					types.push_back(0x16);
					types.push_back(0x17);
					types.push_back(0x18);
					types.push_back(0x19);
					if (type != 0)
					{
						types.push_back(0x22);
						types.push_back(0x23);
					}
					records = weapon->unknown44a7d0()->unknown51ca20(types,shooter,HEntity(),HProp(),HItem(),0,records,&weapon->unknown9b4350()->unknown174,0,0);
					if (type != 0)
					{
						types.clear();
						types.push_back(0x20);
						types.push_back(0x21);
						records = weapon->unknown44a7d0()->unknown51ca20(types,shooter,HEntity(),HProp(),HItem(),0,records,&weapon->unknown9b4350()->unknown174,0,0);
					}
				}

				float weaponBonus = weapon->unknown578b10() / 100.0;
				float slotBonus = weapon->unknown457880() == 0x18 ? shooter->unknown5d2090(0x5d) / 100.0 : 0;
				float followUpBonus = type == 0 && index > 1 ? 0.1f : 0;
				float chance = baseHit + weaponBonus + slotBonus + followUpBonus;
				float penalty = 0;
				int limit = shooter->unknown5c7e90();
				int total = 0;
				for (unsigned int i = 0; i < weapons.size(); i++)
				{
					if (weapons[i] != weapon && weapons[i].operator->() != NULL)
					{
						penalty += maxInt(0,weapons[i]->unknown458100() - limit) / 100.0;
						total += minInt(weapons[i]->unknown458100(),limit);
					}
				}
				chance -= penalty;
				chance = type != 0 ? unknownD37978.clamp_40c760(chance) : unknownCf195c.clamp_40c760(chance);
				if (total >= 0x10 && shooter->isPlayer())
					playerData.unknown77fbc0(0x8e);

				bool guaranteed = false;
				bool surprise = false;
				if (world->unknown464390() || weapon->unknown4580c0() >= 1)
				{
					chance = 1;
					guaranteed = true;
				}
				else if (type == 0 && index > 1 && weapon->unknown457f90() == 0xd6 && weapons[0].operator->() != NULL && weapons[0]->unknown457f90() == 0xd6)
				{
					chance = 1;
					guaranteed = true;
					surprise = true;
				}

				if (weapon->getEffectValue(0x3f))
				{
					vector<HItem> *inventory = shooter->getInventoryList();
					for (unsigned int i = 0; i < inventory->size(); i++)
					{
						if ((*inventory)[i]->unknown4578a0() == 0 && (*inventory)[i]->unknown457cf0())
							goto activeFound;
					}
					chance = 0;
				}
activeFound:
				bool hit = rng.rangeFloat(0,1) <= chance;
				if (hit && shooter->unknown9b4350() == unknownCefc0c && rng.chance(50))
					hit = false;
				if (hit)
					hitCount++;

				if (targetEntity.operator->() != NULL && targetEntity->isPlayer())
				{
					stats.add4729d0(0x165,1,string(""),-1);
					if (hit)
					{
						stats.add4729d0(0x169,1,string(""),-1);
						stats.add4729d0(0x16a + (type != 0),1,string(""),-1);
					}
					else
						stats.add4729d0(0x166,1,string(""),-1);
				}

				// combat log line after the last shot
				if (unknownD28d18 >= 0 && shot == weapon->unknown458120() - 1)
				{
					string text(" ");
					if (shooter != world->getPlayer())
					{
						text.append(shooter->unknown45a410());
						text += ": ";
					}
					text += weapon->getName(0,0);
					if (surprise)
						text += " surprise attack";
					else
					{
						if (followUpBonus != 0)
							text += " follow-up";
						if (sneakAttack)
							text += " sneak attack";
						if (martialStrike)
							text += " martial strike";
					}
					text += " (";
					if (unknownD28d18 >= 0 && shooter == world->getPlayer() && !guaranteed && (weaponBonus != 0 || slotBonus != 0 || followUpBonus != 0 || penalty != 0))
					{
						text += intToString((int)(baseHit * 100.0));
						if (weaponBonus != 0)
							text += OpY1_intToStringSigned(PERCENT_ROUNDED(weaponBonus));
						if (slotBonus != 0)
							text += OpY1_intToStringSigned((int)((slotBonus + 0.005) * 100.0));
						if (followUpBonus != 0)
							text += OpY1_intToStringSigned((int)((followUpBonus + 0.005) * 100.0));
						if (penalty != 0)
							text += OpY1_intToStringSigned((int)(-(penalty + 0.005) * 100.0));
						text += "=";
					}
					text += intToString((int)((chance + 0.005) * 100.0));
					text += "%) ";
					bool anyHit;
					if (shot != 0)
					{
						text += intToString(hitCount) + "/" + intToString(weapon->unknown458120()) + " Hit";
						anyHit = hitCount != 0;
					}
					else
					{
						text += hit ? "Hit" : "Miss";
						anyHit = hit;
					}
					if (world->getPlayer().operator->() != NULL)
					{
						opW5_unknown49bde0(shooter);
						if (shooter->isPlayer())
							COMBAT_MESSAGE(anyHit ? 0x2c0 : 0x2c1,&text,NULL,0,shooter,HEntity(),NULL,1);
						else if (shooter->unknown5c7fc0(world->getPlayer()) == 2)
							COMBAT_MESSAGE(anyHit ? 0x2c2 : 0x2c3,&text,NULL,0,shooter,HEntity(),NULL,1);
						else
							COMBAT_MESSAGE(anyHit ? 0x2c4 : 0x2c5,&text,NULL,0,shooter,HEntity(),NULL,1);
					}
				}

				// a ranged miss with no line of fire to animate
				if (!hit && type == 0)
				{
					misses++;
					if (world->isVisible(target))
					{
						world->setFlagA74(true);
						effectMgr->create()->init(effectMgr,weapon->unknown9b4350()->unknown198,target,targetSubcell,NULL,NULL,NULL,9,0);
						world->raiseUnknownA70(200);
						world->setFlagA74(false);
						animated = true;
					}
					else
						skipAnimation = true;
					continue;
				}

				Point origin = shooter->unknown5c80f0(target);
				Point aim;
				if (hit)
				{
					hits++;
					if (!countedHit)
					{
						if (shooter->isPlayer() && cells.contains(target) && cells(target)->getEntity().isValid())
						{
							countedHit = true;
							stats.add4729d0(0x192,1,string(""),-1);
						}
					}
					if (shooter->isPlayer() && cells.contains(target) && cells(target)->getEntity().isValid() && type == 1)
					{
						unknownCf4ba0 = 0;
						unknownCf4b9c++;
						stats.add4729d0(0x18b,unknownCf4b9c,string(""),-1);
						if (stats.current->values[0x18b] == 10)
							playerData.unknown77fbc0(0x23);
					}
					aim = target;
				}
				else
				{
					misses++;
					if (shooter->isPlayer() && cells.contains(target) && cells(target)->getEntity().isValid() && type == 1)
					{
						unknownCf4b9c = 0;
						unknownCf4ba0++;
						stats.add4729d0(0x18c,unknownCf4ba0,string(""),-1);
						if (stats.current->values[0x18c] == 5)
							playerData.unknown77fbc0(0x22);
					}
					aim = unknown658a70(origin,target,0.25f);
				}

				// spread: shots of one volley avoid each other's aim points
				if (weapon->unknown9b4350()->unknown11c != 0 && aim != origin)
				{
					int spread = weapon->unknown9b4350()->unknown11c;
					int attempts = 0;
					do
					{
						int factor;
						switch (OpQ1_distanceCeil_40a3f0(origin,aim))
						{
						case 1: factor = 20; break;
						case 2: factor = 10; break;
						case 3: factor = 7; break;
						default: factor = 5; break;
						}
						Point delta(aim.x - origin.x,aim.y - origin.y);
						delta *= factor;
						Point far(origin,delta);
						int angle = rng.rangeInt(-spread / 2,spread / 2);
						if (angle < 0)
							angle += 360;
						opr2b_rotatePoint(origin,far,(float)angle,aim);
						if (++attempts >= 10)
							break;
					} while (containsPoint(spreadTargets,aim));
					spreadTargets.push_back(aim);
				}

				opR1f_460820(new OpR1F_Named460780(shooter->getLabel(),target,aim,targetSubcell,target == aim ? Point(0) : Point(aim.x - target.x,aim.y - target.y)));

				if (aim == origin)
				{
					logError("SEntityShoot::update()","target matches origin, aborting attack");
					return true;
				}

				// damage multiplier
				float multiplier = 1.0f;
				if (weapon->unknown458220())
					multiplier = shooter->unknown5d7bc0();
				else if (type == 0)
				{
					multiplier = shooter->unknown5d7bf0(weapon->unknown9b4350()->unknown128);
					if (shooter->isPlayer() && shooter->unknown5c8c40(3))
						shooter->unknown63c120();
					if (cells(target)->getEntity().isValid())
					{
						if (cells(target)->getEntity()->unknown45b590() != NULL && cells(target)->getEntity()->unknown45b590()->unknown5814f0(shooter))
							multiplier += 1.0;
						if (shooter->isPlayer() && playerData.isSlotEmpty(0x33) && cells(target)->getEntity()->isHostileTo(shooter) && shooter->unknown5c8c40(3) > 3)
							playerData.unknown77fbc0(0x33);
					}
				}

				// cluster weapons spread heat over the cells around the shooter
				if (weapon->unknown457f90() == 0xc9)
				{
					unknownD2a864.owner = shooter;
					unknownD2a864.heat = weapon->unknown579090();
					unknownD2a864.origin = shooter->getPosition();
					unknownD2a864.target = target;
					int remaining = weapon->unknown579050();
					if (shooter->isPlayer())
					{
						stats.add4729d0(0x20a,remaining,string(""),-1);
						if (stats.unknown472c70(0x20a) > 999)
							playerData.unknown77fbc0(0xd4);
					}
					vector<Point> positions;
					weapon->unknown578f20(&positions,0);
					shuffle(positions);
					for (unsigned int i = 0; i < positions.size() && remaining != 0; i++)
					{
						int capacity = cells(positions[i])->unknown45a6e0();
						int amount;
						if (remaining < capacity)
						{
							amount = remaining;
							remaining = 0;
						}
						else
						{
							remaining -= capacity;
							amount = capacity;
						}
						unknownD2a864.list.push_back(new ClusterCell(positions[i],amount,rng.rangeInt(0,500) + tickCount));
					}
					int heat = (int)(weapon->unknown9b4350()->unknown1a0->unknown30 * unknownD2a864.heat / 34.0 + 1.0);
					shooter->unknown5defa0(heat,false);
					if (shooter->isPlayer())
						stats.add4729d0(0x20b,heat,string(""),-1);
				}
				else if (weapon->unknown457f90() == 0x9e)
				{
					if (weapon->getEffectValue(0x46) == 2 && shot == 0)
					{
						int heat = unknownD35bd0.randomInRange_40c130();
						shooter->unknown5defa0(heat,false);
						if (shooter->isPlayer())
							stats.add4729d0(0x20b,heat,string(""),-1);
					}
				}

				if (!shooter->isPlayer() && weapon->unknown9b4350()->unknown168 != 0)
					world->unknown74b060(origin,weapon->unknown9b4350()->unknown168,100);

				// resolve the shot instantly when nothing of it can be seen, otherwise launch a projectile
				Point last;
				Point stop;
				vector<Point> path;
				bool instant;
				if (world->isVisible(origin))
					instant = false;
				else if (world->unknown717e40(origin,aim,weapon->unknown4580a0(),last,stop,weapon->unknown9b4350(),&path))
					instant = false;
				else if (weapon->unknown9b4350()->unknown190->unknown5012a0(origin))
					instant = false;
				else
					instant = true;

				if (instant)
				{
					if (last.x != -1)
						path.push_back(last);
					for (unsigned int i = 0; i < path.size(); i++)
					{
						last = path[i];
						world->setFlagA74(true);
						if (cells(last)->getEntity().isValid())
						{
							cells(last)->getEntity()->projectileImpact(shooter,type,records,weapon->unknown9b4350(),multiplier,&origin,true,NULL,NULL);
							if (weapon.operator->() != NULL && weapon->unknown9b4350()->unknown1a0 != NULL)
								world->addRecord(gm->createA(new Obj515ca0(shooter,weapon->unknown9b4350()->unknown1a0,last,HEntity(),Point(-1),Point(-1))));
						}
						else if (cells(last)->getProp().isValid())
						{
							cells(last)->getProp()->unknown664840(shooter,type,records,weapon->unknown9b4350(),multiplier,true,0,NULL);
							if (weapon.operator->() != NULL && weapon->unknown9b4350()->unknown1a0 != NULL)
								world->addRecord(gm->createA(new Obj515ca0(shooter,weapon->unknown9b4350()->unknown1a0,last,HEntity(),Point(-1),Point(-1))));
						}
						else
						{
							cells(last)->unknown66e650(shooter,type,records,weapon->unknown9b4350(),multiplier,true);
							if (weapon.operator->() != NULL && weapon->unknown9b4350()->unknown1a0 != NULL)
								world->addRecord(gm->createA(new Obj515ca0(shooter,weapon->unknown9b4350()->unknown1a0,stop,HEntity(),Point(-1),Point(-1))));
						}
						world->setFlagA74(false);
						if (shooter.operator->() == NULL || weapon.operator->() == NULL)
							break;
					}
					if (weapon.operator->() != NULL && weapon->getEffect(0x45) != NULL)
						world->thrownItemArrived(shooter,weapon,weapon->getEffectValue(0x45),last,records);
					delete records;
					skipAnimation = true;
					world->unknown465a70();
					for (unsigned int i = 0; i < unknownD2a864.list.size(); i++)
						cells(unknownD2a864.list[i]->pos)->unknown66d470(shooter,unknownD2a864.list[i]->amount,true,true);
					unknownD2a864.unknown460700();
				}
				else
				{
					vector<Point> origins;
					vector<Point> targets;
					OpS3b_f651590(weapon->unknown9b4350(),origin,aim,origins,targets);
					for (unsigned int i = 0; i < origins.size(); i++)
					{
						OpR2b_Obj500dd0 *projectile = new OpR2b_Obj500dd0(weapon->unknown9b4350(),shooter,type,weapon->unknown4580a0(),multiplier,type == 0 ? weapon : HItem(),weapon->getEffect(0x45) != NULL ? weapon : HItem(),weapon->getEffectValue(0x45),lastWeapon ? HBattleState() : handle,&unknown2c,records,0);
						effectMgr->create()->init(effectMgr,weapon->unknown9b4350()->unknown190,origins[i],effectOrigin,&targets[i],&targetSubcell,projectile,9,0);
						if (!lastWeapon)
							pending++;
						if (weapon->unknown9b4350()->unknown190->unknown44 && i == 0)
							unknownCefb68++;
						if (unknownCefb25)
						{
							Effect *effect = effectMgr->unknown4549b0().back();
							unknownD2d4c8.push_back("target=" + OpQ1_pointToString(effect->unknown68) + " | offset=" + OpQ1_pointToString(effect->unknown70));
						}
					}
				}

				// overheating rings (effect 0x79/0x7a)
				if (weapon.operator->() != NULL && weapon->getEffectValue(0x79))
				{
					unknownD3976c.clear();
					unknownD29d6c.clear();
					unknownD2ac84.clear();
					Point from = shooter->getPosition();
					int maxDistance = weapon->unknown9b4350()->unknown100;
					Point subcell;
					Point previous;
					Point cell;
					Bresenham2DStepperSubcell stepper(from,effectOrigin,aim,targetSubcell,9);
					previous = from;
					stepper.next(cell,subcell);
					while (cell == from)
						stepper.next(cell,subcell);
					while (!stepper.next(cell,subcell))
					{
						if (previous != cell)
						{
							if (!cells.contains(cell))
								break;
							unknownD3976c.push_back(cell);
							if (OpQ1_distanceCeil_40a3f0(from,cell) >= maxDistance)
								break;
							previous = cell;
						}
					}

					vector<Point> neighbors;
					for (unsigned int i = 0; i < unknownD3976c.size(); i++)
					{
						neighbors.clear();
						cells.getNeighbors_9ce500(unknownD3976c[i],neighbors);
						for (unsigned int j = 0; j < neighbors.size(); j++)
						{
							if (neighbors[j] != from && !containsPoint(unknownD3976c,neighbors[j]))
								unknownD29d6c.push_back(neighbors[j]);
						}
					}
					for (unsigned int i = 0; i < unknownD29d6c.size(); i++)
					{
						neighbors.clear();
						cells.getNeighbors_9ce500(unknownD29d6c[i],neighbors);
						for (unsigned int j = 0; j < neighbors.size(); j++)
						{
							if (neighbors[j] != from && !containsPoint(unknownD3976c,neighbors[j]) && !containsPoint(unknownD29d6c,neighbors[j]))
								unknownD2ac84.push_back(neighbors[j]);
						}
					}

					if (weapon->getEffect(0x7a) != NULL)
						weapon->getEffect(0x7a)->state++;
					else
						weapon->addEffect(new ItemEffect(effectTypes[0x7a],1));
					int heat = weapon->getEffect(0x7a)->state;
					if (weapon->getEffectValue(0x79) > 1 && heat > (weapon->getEffectValue(0x79) == 3 ? 20 : 10) && rng.chance(heat > 50 ? 33 : 10))
					{
						weapon->getEffect(0x79)->state--;
						weapon->getEffect(0x7a)->state = 1;
						if (shooter->isPlayer())
						{
							string text = weapon->getName(0,0) + " violently vaporizes one of its rings.";
							opW5_message(0x320,HEntity(),text,0);
							HISTORY(0x110,&weapon->unknown457860(),NULL,0,HEntity(),0);
							cparts->unknown894e70(weapon)->unknown4a9120();
							opR1d_4541b0(0xfd,0,0);
						}
						int rings = weapon->getEffect(0x79)->state;
						int value = rings == 2 ? 5 : 10;
						if (weapon->getEffect(0x5a) != NULL)
							weapon->getEffect(0x5a)->state = value;
						else
							weapon->addEffect(new ItemEffect(effectTypes[0x5a],value));
					}
				}
			}

			// after the volley
			if (weapon.operator->() != NULL && weapon->unknown457f90() == 0xc2)
			{
				int damage = weapon->unknown457fb0();
				damage = rng.rangeInt(damage * 0.5,damage * 1.5);
				if (damage < shooter->unknown490840())
					shooter->unknown5dea60(shooter->unknown490840() - damage,0);
				else
					shooter->die(!world->unknown4631f0(shooter),10,HEntity(),1,0,NULL,NULL,false);
			}

			if (shooter.operator->() != NULL && weapon.operator->() != NULL && weapon->getEffectValue(0x44))
			{
				weapon->getEffect(0x44)->state--;
				if (weapon->getEffectValue(0x44) == 0)
				{
					MESSAGE(0x191,TEMP_PTR(weapon->getName(0,0)),NULL,0,shooter,HEntity(),NULL,0);
					weapon->unknown57dbe0(1,0,0,1);
				}
			}

			if (shooter.operator->() != NULL && weapon.operator->() != NULL && weapon->getEffectValue(0x47))
			{
				weapon->getEffect(0x47)->state--;
				if (weapon->getEffectValue(0x47) == 0)
				{
					weapon->getEffect(0x47)->state = -1;
					shooter->unknown64e7e0();
					if (shooter->isPlayer())
						cparts->unknown894e70(weapon)->unknown890710(true);
				}
			}

			if (shooter.operator->() != NULL && weapon.operator->() != NULL && weapon->getEffectValue(0x76))
			{
				weapon->unknown4585c0(0x77);
				shooter->unknown64e7e0();
				if (shooter->isPlayer())
					cparts->unknown894e70(weapon)->unknown890710(true);
			}

			if (shooter.operator->() != NULL && weapon.operator->() != NULL && weapon->getEffectValue(0x59))
			{
				if (rng.chance(weapon->getEffectValue(0x59)))
				{
					if (shooter->unknown5cad50() != 2 || !unknownBa0968[unknownCefb38])
						shooter->unknown602170(weapon,unknown4374c0(target,shooter->getPosition()));
				}
			}

			if (shooter.operator->() != NULL && weapon.operator->() != NULL && weapon->unknown458240())
			{
				if (weapon->unknown9b6bf0() <= weapon->unknown458240())
				{
					MESSAGE(0x192,TEMP_PTR(weapon->getName(0,0)),NULL,0,shooter,HEntity(),NULL,0);
					weapon->unknown57dbe0(1,0,1,1);
				}
				else
				{
					weapon->unknown458310(weapon->unknown458240());
					CPart *part = cparts->unknown894e70(weapon);
					if (part != NULL)
						part->drawStatus(true);
				}
			}

			if (shooter.operator->() != NULL && weapon.operator->() != NULL)
				OpS1c_unknown4569a0(6,shooter,HEntity(),HProp(),weapon,0,TEMP_PTR(weapon->getName(0,0)),weapon->unknown44a7d0(),HEntity(),HProp(),weapon,0);

			if (shooter.operator->() != NULL && weapon.operator->() != NULL)
				OpS1c_unknown4569a0(7,shooter,HEntity(),HProp(),weapon,0,TEMP_PTR(weapon->getName(0,0)),weapon->unknown44a7d0(),shooter,HProp(),weapon,0);

			if (cells(target)->getEntity().isValid())
			{
				HEntity victim = cells(target)->getEntity();
				if (weapon.operator->() != NULL)
				{
					if (type == 0)
						OpS1c_unknown4569a0(0xb,victim,HEntity(),HProp(),HItem(),0,TEMP_PTR(weapon->getName(0,0)),victim->getInventory(),victim,HProp(),HItem(),0);
					else
						OpS1c_unknown4569a0(0xc,victim,HEntity(),HProp(),HItem(),0,TEMP_PTR(weapon->getName(0,0)),victim->getInventory(),victim,HProp(),HItem(),0);
				}
				if (victim.operator->() != NULL && weapon.operator->() != NULL)
					OpS1c_unknown4569a0(0xd,victim,HEntity(),HProp(),HItem(),0,TEMP_PTR(weapon->getName(0,0)),victim->getInventory(),victim,HProp(),HItem(),0);
			}

			if (lastWeapon)
			{
				if (shooter.operator->() != NULL)
				{
					if (shooter == world->getPlayer())
						unknownCf4b98 = world->getTurn();
					if (type == 1 && targetEntity.operator->() != NULL)
						shooter->unknown451600(targetEntity);
					else
						shooter->unknown451600(HEntity());
				}
				return true;
			}

			// nothing to animate: fire the next weapon right away
			if (skipAnimation && world->unknown463fa0() == 0)
				continue;

			state = 1;
			if (skipAnimation || animated)
				world->setPausedShootState(handle);
			break;
		}
		break;
	}
	default:
		return true;
	}

	return false;
}
