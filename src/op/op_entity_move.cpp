// op_entity_move: Entity::move (0x63d8a0), moves an entity to a destination: momentum/facing, terrain
// instability, stats and achievements, displacing robots under large entities, crushing, item effects
// on the new cell, triggers and the trail/ALERT side effects; returns the time cost (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
#include <algorithm>
#include "../../src/util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(int value);	// 0x409990
	Point(int x_, int y_);	// 0x46ca20
	Point(const Point &p) throw();	// 0x46ca50
	Point(const Point &base, const Point &offset);	// NOTE: placeholder (0x4099f0)
	Point &operator=(const Point &p);	// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
	bool contains(int x1, int y1, int x2, int y2);	// NOTE: placeholder name (PushGeometry::contains 0x409d70)
};

struct Area	// NOTE: placeholder name
{
	Area();	// 0x40b100
	Point min;
	Point max;
};

class Entity;
class Item;
class Prop;
class Group;
struct EntityEffect;
struct CellEffect;

class HEntity
{
public:
	int ID;
	HEntity();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	bool operator==(HEntity other) const;	// 0x9b78e0
	bool operator!=(HEntity other) const;	// 0x9b6510
	Entity *operator->() const;	// 0x9b6570
};

class HItem
{
public:
	int ID;
	HItem();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	bool isNull() const;	// 0x9b65d0
	Item *operator->() const;	// 0x9b65b0
};

class HProp
{
public:
	int ID;
	Prop *operator->() const;	// 0x9b64f0
	bool operator<(const HProp &other) const { return ID < other.ID; }
	bool operator==(const HProp &other) const { return ID == other.ID; }
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
	int unknown9b4350();	// NOTE: placeholder name (folded getter)
};

struct OpEM_Marker	// NOTE: placeholder layout (HMarker target)
{
	char pad00[8];
	Point pos;	// 0x08
	void unknown6c20b0(int a, const Point &p, int b);	// NOTE: placeholder name
};

class HMarker
{
public:
	int ID;
	OpEM_Marker *operator->() const;	// 0x9b7cd0
};

struct OpEM_Location	// NOTE: placeholder layout
{
	int unknown0;
	int type;
};

class OpEM_HLocation	// NOTE: placeholder name (0xd1e888)
{
public:
	int ID;
	OpEM_Location *operator->();	// 0x9b7910
};

class Item
{
public:
	int getType();	// 0x44aec0
	int unknown457880();	// NOTE: placeholder name
	bool unknown457cf0();	// NOTE: placeholder name
	int getEffectValue(int type);	// 0x457be0
	int unknown4578c0();	// NOTE: placeholder name
	int unknown4578a0();	// NOTE: placeholder name
	int unknown457f90();	// NOTE: placeholder name
	int unknown457cd0();	// NOTE: placeholder name
	int unknown457ca0();	// NOTE: placeholder name
	int unknown457fb0();	// NOTE: placeholder name
	bool unknown457e30();	// NOTE: placeholder name
	void unknown458360(int amount);	// NOTE: placeholder name
	void unknown4584a0();	// NOTE: placeholder name
	int unknown577790();	// NOTE: placeholder name
	int unknown9b6bf0();	// NOTE: placeholder name (folded getter, amount)
	void unknown450460(int value);	// NOTE: placeholder name (folded setter, amount)
	int unknown45cb30();	// NOTE: placeholder name (folded getter)
	void unknown44fc60(int value);	// NOTE: placeholder name (folded setter)
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
	void remove57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

struct OpEM_PropRecord	// NOTE: placeholder layout
{
	char pad00[8];
	bool unknown8;
};

struct OpEM_PropInfo	// NOTE: placeholder layout
{
	char pad00[0x10];
	bool unknown10;
	bool unknown11;
	char pad12[0x28 - 0x12];
	int unknown28;
	char pad2c[0x74 - 0x2c];
	bool unknown74;
	OpEM_PropRecord *unknown45c1c0(int type);	// NOTE: placeholder name
};

struct OpEM_PropData	// NOTE: placeholder layout
{
	char pad00[0xf8];
	int unknownF8;
};

class Prop
{
public:
	OpEM_PropInfo *unknown45cb30();	// NOTE: placeholder name (folded getter)
	OpEM_PropData *unknown9b8f00();	// NOTE: placeholder name (folded getter)
	int unknown457b10();	// NOTE: placeholder name (folded getter)
	int unknown44ab40();	// NOTE: placeholder name (folded getter)
	int unknown45c800(int type);	// NOTE: placeholder name
	int unknown45c630();	// NOTE: placeholder name
	const string &getName();	// 0x45c5b0
	const Point &unknown4184d0();	// NOTE: placeholder name (folded getter, position)
	void unknown45ce10(bool a, int b, bool c, HEntity e);	// NOTE: placeholder name
};

struct CellTerrainRecord	// NOTE: placeholder layout
{
	int ID;
};

class Cell
{
public:
	bool canCaveIn();	// 0x66af50
	CellTerrainRecord *unknown9fcd80();	// NOTE: placeholder name (folded getter 0x9fcd80)
	void unknown45e110(bool a, bool b, HEntity e);	// NOTE: placeholder name (Effect_45e110::trigger)
	HEntity getEntity();	// 0x45d250
	void clearEntity();	// 0x66baf0
	HItem getItem();	// 0x45d8f0
	HProp getProp();	// 0x45d550
	bool unknown45de40();	// NOTE: placeholder name
	bool unknown45d500();	// NOTE: placeholder name
	bool unknown45d4e0();	// NOTE: placeholder name
	bool unknown45db70();	// NOTE: placeholder name
	int getArmor();	// 0x66ae70
	CellEffect *getEffect(int type);	// 0x45d350
	const string &unknown45d140();	// NOTE: placeholder name
	void unknown66d580(bool flag);	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	T &operator()(int x, int y);	// 0x9ceda0
	bool contains(const Point &p);	// 0x9b43b0
	void getRect(const Point &p, int radius, Area &out);	// 0x9b4430
};
extern Array2D<Cell *> cells;	// 0xcfd44c
extern Array2D<int> originalTerrain;	// 0xd378c0
extern CellTerrainRecord *TERRAIN_CAVE_WALL;	// 0xcefba0
extern CellTerrainRecord *caveinThirdTerrain;	// 0xcefba4

class OpEM_View	// NOTE: placeholder name (Array2D<int> window, 0x2c bytes)
{
public:
	OpEM_View();	// 0x9cfd10
	~OpEM_View();	// 0x9b6bd0
	int left();	// NOTE: placeholder name (folded getter)
	int top();	// NOTE: placeholder name (folded getter)
	int right();	// NOTE: placeholder name
	int bottom();	// NOTE: placeholder name
	int &operator()(int x, int y);	// 0x9cfe20
	Point findOffset(int index);	// NOTE: placeholder name (0x9b6cb0)

	int data[0xb];
};

struct OpEM_Trail	// NOTE: placeholder name (0xc bytes)
{
	Point pos;
	unsigned int time;

	OpEM_Trail(const Point &p, unsigned int time_);	// 0x45a010
};

// NOTE: defined here without throw() so that LTCG proves it nothrow, as in the exe (keeps the extra slot)
OpEM_Trail::OpEM_Trail(const Point &p, unsigned int time_)
	: pos(p),
	time(time_)
{
}

struct OpEM_Record	// NOTE: placeholder layout (entity record)
{
	char pad00[0x28];
	int unknown28;
	char pad2c[0x8c - 0x2c];
	int unknown8C;
	char pad90[0x9c - 0x90];
	int size;	// 0x9c
	int unknownA0;
};

struct OpEM_PossessionRecord	// NOTE: placeholder layout
{
	char pad00[0x24];
	int unknown24;
	char pad28[0x148 - 0x28];
	vector<int> unknown148;
};

struct OpEM_Possession	// NOTE: placeholder layout
{
	int id;
};

class CPart
{
public:
	void drawStatus(bool flag);	// 0x4a8e70
};

class Entity	// NOTE: placeholder layout
{
public:
	int move(const Point &dest, int steps, bool flag);

	bool isPlayer();	// 0x5c7600
	int getSize();	// 0x45a360
	int getFaction();	// 0x45a2c0
	int getTarget();	// 0x45a760
	const Point &getPosition();	// 0x45a4a0
	const string &getName();	// 0x45a280
	string &unknown416f40();	// NOTE: placeholder name (folded getter, name)
	OpEM_Record *getInfo();	// NOTE: placeholder name (folded getter 0x9b4350)
	HGroup getGroup();	// 0x45a3f0
	bool isHostileTo(HEntity e);	// 0x45aa70
	void changePos(const Point &p, bool flag);	// 0x5dccb0
	void die(bool a, int b, HEntity killer, int c, int d, void *e, void *f, bool g);	// 0x633790
	int unknown5d1390();	// NOTE: placeholder name
	int unknown5d15a0(bool player);	// NOTE: placeholder name
	bool unknown5fdae0();	// NOTE: placeholder name
	float unknown5d1e40();	// NOTE: placeholder name
	void unknown45b1b0(int value);	// NOTE: placeholder name
	int unknown5d1da0();	// NOTE: placeholder name
	void unknown45b210(int value);	// NOTE: placeholder name
	bool unknown5cb680(HGroup g);	// NOTE: placeholder name
	bool unknown5c85a0(const Point &p, bool large);	// NOTE: placeholder name
	bool unknown5ddf50(const Point &p, OpEM_View *view, bool *tooLarge);	// NOTE: placeholder name
	void unknown637bb0();	// NOTE: placeholder name
	void unknown45b090(int value);	// NOTE: placeholder name
	void unknown45b0b0();	// NOTE: placeholder name
	void unknown5dd9c0(HEntity e, const Point &p);	// NOTE: placeholder name
	int unknown5c7fc0(HEntity other);	// NOTE: placeholder name
	int unknown45a340();	// NOTE: placeholder name
	int unknown490840();	// NOTE: placeholder name
	EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	void alertGroup639ec0(HEntity e, bool flag);	// NOTE: placeholder name
	void unknown5dd8a0(HEntity other);	// NOTE: placeholder name
	void unknown5daf90(int type);	// NOTE: placeholder name
	void unknown5dfd80();	// NOTE: placeholder name
	int unknown45a920();	// NOTE: placeholder name
	int unknown5ca670();	// NOTE: placeholder name
	int unknown5ccab0();	// NOTE: placeholder name
	int rollDestroy63c120();	// NOTE: placeholder name
	bool checkFragile603030(HItem item);	// NOTE: placeholder name
	bool unknown603280(HItem item);	// NOTE: placeholder name
	HItem unknown5d2380(int type);	// NOTE: placeholder name
	int unknown5c7d30();	// NOTE: placeholder name
	int unknown5d2150(int type, int base);	// NOTE: placeholder name
	unsigned int unknown5d2430(int type, vector<HItem> *out);	// NOTE: placeholder name
	HItem unknown5cbd10();	// NOTE: placeholder name
	HItem unknown5d25e0(int type);	// NOTE: placeholder name
	void destroyItems_63a0d0();	// NOTE: placeholder name
	bool unknown5fdd30();	// NOTE: placeholder name
	void unknown5c8880(vector<HEntity> *out);	// NOTE: placeholder name
	bool unknown63c340(HEntity other);	// NOTE: placeholder name
	int unknown5ded70(int amount);	// NOTE: placeholder name
	int unknown5deb40(int amount);	// NOTE: placeholder name

	int unknown00;
	HEntity self;	// 0x04
	OpEM_Record *record;	// 0x08
	char pad0c[0x28 - 0x0c];
	HGroup group;	// 0x28
	int unknown2C;
	vector<Point> positions;	// 0x30
	char pad40[0x50 - 0x40];
	int unknown50;
	int unknown54;
	int unknown58;
	float unknown5C;
	vector<OpEM_Trail *> trail;	// 0x60
	char pad70[0x7c - 0x70];
	int unknown7C;
	char pad80[0xb0 - 0x80];
	int unknownB0;
	int unknownB4;
	char padB8[0x134 - 0xb8];
	vector<HItem> parts;	// 0x134
};

class Map	// NOTE: partial
{
public:
	bool unknown464350();	// NOTE: placeholder name
	HEntity getPlayer();	// 0x4630f0
	bool unknown463490(HEntity e, const Point &p);	// NOTE: placeholder name
	bool unknown463400(HEntity e);	// NOTE: placeholder name
	void unknown72e4c0(HEntity e, bool flag);	// NOTE: placeholder name
	void unknown74b060(const Point &p, int type, int percent);	// NOTE: placeholder name
	void unknown725930(HEntity e, bool flag);	// NOTE: placeholder name
	void unknown464800(HEntity e);	// NOTE: placeholder name
	void addTrailPoint(const Point &p);	// NOTE: placeholder name (0x71ce30)
	void unknown729520(const Point &p);	// NOTE: placeholder name
	void unknown71f700(const Point &p, int radius);	// NOTE: placeholder name
	void unknown4657c0();	// NOTE: placeholder name
	int unknown4642f0();	// NOTE: placeholder name
	vector<HEntity> *unknown4636b0();	// NOTE: placeholder name
	bool isReachable(int range, const Point &from, const Point &to);	// 0x465230
	void addPropsAround(HEntity e, vector<HProp> *out);	// NOTE: placeholder name (0x71c6d0)
	bool unknown715d20();	// NOTE: placeholder name
	bool unknown715ed0();	// NOTE: placeholder name
	vector<vector<Point> > *unknown459070();	// NOTE: placeholder name (folded getter)
	bool isVisible4631c0(const Point &p);	// 0x4631c0
	bool unknown463160(const Point &p);	// NOTE: placeholder name
	vector<vector<HMarker> > *unknown463ec0();	// NOTE: placeholder name
	void unknown74bb90(HProp prop, HEntity *owner, Point *target, bool *flag);	// NOTE: placeholder name
	void unknown6c6b90(const Point &p, const string &name, int a, int b);	// NOTE: placeholder name
	bool unknown463b50(Point p);	// NOTE: placeholder name
	void unknown463b80(Point p);	// NOTE: placeholder name
	vector<int> *unknown463bc0();	// NOTE: placeholder name
	void unknown4647a0(const Point &p, int a);	// NOTE: placeholder name
	HItem unknown71e7c0(const Point &p, int amount, int a);	// NOTE: placeholder name
	void unknown464840(HItem item);	// NOTE: placeholder name
};
extern Map *world;	// 0xcefc4c

class OpEM_Stats	// NOTE: placeholder name (0xd2c658)
{
public:
	vector<int> *current;
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
	int unknown472c70(int id);	// NOTE: placeholder name
};
extern OpEM_Stats opem_stats;	// NOTE: placeholder name (0xd2c658)

class OpEM_PlayerData	// NOTE: placeholder name (PlayerData, 0xcf45d8)
{
public:
	bool isSlotEmpty(int slot);	// NOTE: placeholder name (0x46de40)
	void unknown77fbc0(int id);	// NOTE: placeholder name
	void addPolymindSuspicion(float amount, int type, HEntity e);	// 0x77ee70
};
extern OpEM_PlayerData opem_playerData;	// NOTE: placeholder name (0xcf45d8)

class OpEM_MapView	// NOTE: placeholder name (object at 0xcec054)
{
public:
	void unknown49b670();	// NOTE: placeholder name
	void unknown49ad30();	// NOTE: placeholder name
	void unknown49adc0(int duration);	// NOTE: placeholder name
	void unknown49afd0(const Point &p, bool flag);	// NOTE: placeholder name
	void unknown49ad70(int time);	// NOTE: placeholder name
	void showInfo81a340(HEntity e);	// NOTE: placeholder name
};
extern OpEM_MapView *opem_cec054;	// NOTE: placeholder name

class OpEM_MsgConsole	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void bubble(bool flag);	// NOTE: placeholder name (0x8758d0)
};
extern OpEM_MsgConsole *opem_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern CLogMsgs *opem_logMsgs;	// NOTE: placeholder name (0xcec0b4)

class OpEM_Interface	// NOTE: placeholder name (object at 0xcec088)
{
public:
	CPart *unknown894e70(HItem item);	// NOTE: placeholder name
};
extern OpEM_Interface *opem_cec088;	// NOTE: placeholder name

class OpEM_Mission	// NOTE: placeholder name (object at 0xcec034)
{
public:
	void unknown987de0();	// NOTE: placeholder name
};
extern OpEM_Mission *opem_cec034;	// NOTE: placeholder name

class OpEM_Effect	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class OpEM_EffectMgr	// NOTE: placeholder name
{
public:
	OpEM_Effect *create();	// NOTE: placeholder name (0x508610)
};
extern OpEM_EffectMgr *opem_effectMgr;	// NOTE: placeholder name (0xcefc50)
extern Point opem_effectOrigin;	// NOTE: placeholder name (0xd2e20c)

class OpEM_GameData	// NOTE: placeholder name (0xd1e860)
{
public:
	bool unknown46f4b0(int a);	// NOTE: placeholder name
	const string &getEntryText(const string &key);	// NOTE: placeholder name (0x46f6d0)
};
extern OpEM_GameData opem_gameData;	// NOTE: placeholder name

class OpEM_Factory	// NOTE: placeholder name (0xcefaa8)
{
public:
	HMarker createC();	// NOTE: placeholder name (0x793190)
};
extern OpEM_Factory *opem_factory;	// NOTE: placeholder name

class OpEM_Tally	// NOTE: placeholder name (0xcf6888)
{
public:
	void unknown6998a0(int a, int b, int c);	// NOTE: placeholder name
};
extern OpEM_Tally opem_tally;	// NOTE: placeholder name

class OpEM_Range	// NOTE: placeholder name (0xd306a4)
{
public:
	int randomInRange_40c130();	// NOTE: placeholder name
};
extern OpEM_Range opem_d306a4;	// NOTE: placeholder name

class OpEM_EntityLists	// NOTE: placeholder name (object behind 0xcefc14)
{
public:
	bool take48bf50(HEntity e);	// NOTE: placeholder name
	bool unknown7ac1c0(HEntity e, int a, int b, string text);	// NOTE: placeholder name
};
extern OpEM_EntityLists *opem_cefc14;	// NOTE: placeholder name

class OpEM_Notice	// NOTE: placeholder name (0xcf1080)
{
public:
	void unknown451400(int value);	// NOTE: placeholder name (folded setter)
};
extern OpEM_Notice opem_cf1080;	// NOTE: placeholder name

struct OpEM_LevelInfo	// NOTE: placeholder layout (0x34 bytes)
{
	int interval;
	int amount;
	int limit;
	char pad0c[0x34 - 0x0c];
};
extern OpEM_LevelInfo opem_levels_ba4500[];	// NOTE: placeholder name

extern OpEM_HLocation opem_location;	// NOTE: placeholder name (0xd1e888)
extern OpEM_Possession *opem_cf4700;	// NOTE: placeholder name
extern vector<OpEM_PossessionRecord *> opem_d25de0;	// NOTE: placeholder name
extern vector<HEntity> opem_d35850;	// NOTE: placeholder name
extern vector<vector<HProp> > opem_d31640;	// NOTE: placeholder name
extern vector<int> opem_cf6898;	// NOTE: placeholder name
extern int opem_b95fd8;	// NOTE: placeholder name (100)
extern int opem_d28d40;	// NOTE: placeholder name
extern int opem_d255e4;	// NOTE: placeholder name
extern int opem_cf47fc;	// NOTE: placeholder name
extern unsigned int opem_tick;	// NOTE: placeholder name (0xcaed20)
extern int opem_table_b96080[];	// NOTE: placeholder name
extern int opem_table_b96064[];	// NOTE: placeholder name
extern bool opem_table_b91198[];	// NOTE: placeholder name
extern bool opem_table_b95150[];	// NOTE: placeholder name
extern Point opem_dirOffsets[];	// NOTE: placeholder name (0xd015d8)
extern Point opem_cfcc6c;	// NOTE: placeholder name
extern Point opem_d3578c;	// NOTE: placeholder name
extern bool opem_cefc5d;	// NOTE: placeholder name
extern bool opem_cefc9c;	// NOTE: placeholder name
extern const char empty_b952f6[];
extern const char empty_b952f7[];
extern const char empty_b95302[];
extern const char empty_b95303[];
extern const char empty_b9530e[];
extern const char empty_b9530f[];
extern const char empty_b9531d[];
extern const char empty_b9531e[];
extern const char empty_b9531f[];
extern const char empty_b95326[];
extern const char empty_b95327[];

void logError(string location, string message);	// 0x404f10
string intToString(int value);	// 0x4051f0
int stringToInt(const string &text);	// 0x405610
int pointsFn_4374c0(const Point &a, const Point &b);	// NOTE: placeholder name (direction)
int opr1c_getCircularDistance(int a, int b);	// NOTE: placeholder name (0x433e20)
void OpV4c_Fn9d06d0(int *value, int step, int high);	// NOTE: placeholder name
void OpV4c_Fn9d0690(int *value, int step, int low);	// NOTE: placeholder name
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name
int OpX5_minInt(int a, int b);	// 0x9cdb30
int OpX5_maxInt(int a, int b);	// 0x9cdb60
void OpR3e_unknown6c0f10(const Point &p, int type, int duration);	// NOTE: placeholder name
int OpU8a_indexOfEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d3110)
bool OpU8a_lookup2(const string &name, int *id);	// NOTE: placeholder name (findEffectID 0x9d7980)
bool OpV4c_Fn9d0ce0(vector<Point> &list, Point p);	// NOTE: placeholder name
void opem_deleteAt_9d8f20(vector<OpEM_Trail *> &v, int index);	// NOTE: placeholder name (template deleteObject)
void opem_eraseStep_9d6440(vector<HEntity> &v, unsigned int &index);	// NOTE: placeholder name
void OpT8a_eraseAt(vector<int> &v, unsigned int &index);	// NOTE: placeholder name (0x9ce6d0)
bool OpD_collectProps_517ae0(int a, vector<Point> *out, bool b, int c, Point *d);	// NOTE: placeholder name
bool OpX5_containsRecord(vector<int> &list, int value);	// NOTE: placeholder name (0x9db330)
void opem_shuffle_9d9fc0(vector<HEntity> &v);	// NOTE: placeholder name
bool opS2_showMessage_5111e0(int id, const string *a, const string *b, const string *c, HEntity subject, HEntity object, const Point *at, bool flag);	// NOTE: placeholder name
bool opS2_logPhrase_5141b0(int id, const string *a, const string *b, const string *c, HEntity subject, const Point *at);	// NOTE: placeholder name
void opW5_message(int id, HEntity entity, const string &text, int extra);	// NOTE: placeholder name
int opR1d_454260(const Point &pos, int sound);	// NOTE: placeholder name
int opR1d_4541b0(int sound, int a, int b);	// NOTE: placeholder name

#define OPEM_MSG(ID, A, B, C, S, O) do { if (opS2_showMessage_5111e0(ID, A, B, C, S, O, 0, false)) opem_cec058->bubble(true); opem_logMsgs->scrollToEnd(); } while (false)

int Entity::move(const Point &dest, int steps, bool flag)
{
	bool player = isPlayer();
	int step = pointsFn_4374c0(positions[0], dest);
	int facing = opr1c_getCircularDistance(unknown54, step);
	switch (facing)
	{
	case 0:
		OpV4c_Fn9d06d0(&unknown50, 1, 3);
		break;
	case 1:
		OpV4c_Fn9d0690(&unknown50, 1, 1);
		break;
	default:
		unknown50 = 1;
	}
	unknown54 = step;
	unknown58 = unknown5d1390();
	if (unknown58 == 1)
	{
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown457880() == 10 && parts[i]->unknown457cf0() && parts[i]->getEffectValue(0x7f))
			{
				unknown58 = 7;
				break;
			}
		}
	}
	int duration = unknown5d15a0(player);
	int cost = duration * steps;
	if (!flag)
	{
		if (unknown5fdae0())
			return opem_b95fd8;
		if (!world->unknown464350())
		{
			unknown45b1b0((int)(unknown5d1e40() * steps));
			unknown45b210(unknown5d1da0() * steps);
		}
	}
	if (cells(dest)->canCaveIn())
	{
		if (unknown5C < 2.0 && (originalTerrain(dest) == TERRAIN_CAVE_WALL->ID || originalTerrain(dest) == caveinThirdTerrain->ID))
			unknown5C += 0.4;
		else
			unknown5C += 1.0;
	}
	else
		unknown5C = 0;
	if (opem_d28d40 && !player)
	{
		for (unsigned int i = 0; i < positions.size(); i++)
		{
			for (unsigned int j = 0; j < trail.size(); j++)
			{
				if (positions[i] == trail[j]->pos)
				{
					trail[j]->time = opem_tick;
					goto nextPos;
				}
			}
			trail.push_back(new OpEM_Trail(positions[i], opem_tick));
nextPos:;
		}
	}
	int status = 0;
	if (self != world->getPlayer() && world->getPlayer()->unknown5cb680(group))
	{
		if (world->unknown463490(self, dest))
		{
			if (!world->unknown463400(self))
				status = 1;
		}
		else if (world->unknown463400(self) && !world->unknown463490(self, dest))
			status = -1;
	}
	if (player && !flag)
	{
		opem_stats.add4729d0(0x3f6, duration, empty_b952f6, -1);
		opem_stats.add4729d0(0x3f8, duration, empty_b952f7, -1);
		for (int k = 0; k < steps; k++)
			opem_stats.add4729d0(0x3f7, duration, empty_b95302, -1);
		opem_cec054->unknown49b670();
		if (opem_playerData.isSlotEmpty(0x77) || opem_playerData.isSlotEmpty(0xac) || opem_playerData.isSlotEmpty(0xad))
		{
			if (duration <= 25)
				opem_playerData.unknown77fbc0(0x77);
			if (duration <= 10)
				opem_playerData.unknown77fbc0(0xac);
			if (duration <= 5)
				opem_playerData.unknown77fbc0(0xad);
		}
		if (opem_table_b96080[unknown58] == 1)
		{
			if (duration < 100)
				opem_playerData.unknown77fbc0(0xea);
			if (opem_playerData.isSlotEmpty(0xee) && unknown7C >= 8)
			{
				int total = 0;
				for (unsigned int i = 0; i < parts.size(); i++)
				{
					if (parts[i]->unknown457880() == 10 && parts[i]->unknown457cf0())
						total += parts[i]->unknown4578c0();
				}
				if (total >= 8)
					opem_playerData.unknown77fbc0(0xee);
			}
		}
		if (duration <= 50 && opem_table_b96080[unknown58] == 6 && opem_playerData.isSlotEmpty(0x79))
		{
			for (unsigned int i = 0; i < parts.size(); i++)
			{
				if (parts[i]->unknown457880() == 9 && !parts[i]->unknown457cf0() && parts[i]->getType() == 1)
				{
					opem_playerData.unknown77fbc0(0x79);
					break;
				}
			}
		}
	}
	if (record->unknownA0)
	{
		for (int x = dest.x; x < dest.x + record->size; x++)
		{
			for (int y = dest.y; y < dest.y + record->size; y++)
			{
				if (cells(x,y)->unknown9fcd80() == TERRAIN_CAVE_WALL)
				{
					CellTerrainRecord *terrain = cells(x,y)->unknown9fcd80();
					cells(x,y)->unknown45e110(false, false, self);
					OpR3e_unknown6c0f10(Point(x,y), terrain->ID, 100);
				}
			}
		}
	}
	if (getSize() > 1 && unknown5c85a0(dest, false))
	{
		OpEM_View view;
		if (!unknown5ddf50(dest, &view, NULL))
		{
			logError("Entity::move()", "findAlternativePosArrangement() mismatch");
			return opem_b95fd8;
		}
		else
		{
			vector<HEntity> elements;
			vector<int> list;
			int slot;
			for (int x = view.left(); x <= view.right(); x++)
			{
				for (int y = view.top(); y <= view.bottom(); y++)
				{
					if (cells(x,y)->getEntity().isValid())
					{
						if (cells(x,y)->getEntity() == self)
							cells(x,y)->clearEntity();
						else
						{
							slot = OpU8a_indexOfEntity(opem_d35850, cells(x,y)->getEntity());
							if (slot == -1)
							{
								logError("Entity::move()", "posMap entityIndex not found! destroying " + cells(x,y)->getEntity()->getName());
								cells(x,y)->getEntity()->unknown637bb0();
							}
							else if (slot != view(x,y))
							{
								elements.push_back(cells(x,y)->getEntity());
								list.push_back(slot);
								cells(x,y)->clearEntity();
							}
						}
					}
				}
			}
			Point offset;
			for (unsigned int i = 0; i < elements.size(); i++)
			{
				offset = view.findOffset(list[i]);
				if (offset.x == -1)
				{
					logError("Entity::move()", "new loc for adjustment not found, destroying " + elements[i]->getName());
					elements[i]->unknown637bb0();
				}
				else
				{
					Point oldPos = elements[i]->getPosition();
					elements[i]->changePos(offset, false);
					elements[i]->unknown45b090(0);
					elements[i]->unknown45b0b0();
					unknown5dd9c0(elements[i], offset);
					if (oldPos.contains(dest.x, dest.y, dest.x + record->size, dest.y + record->size)
						&& elements[i]->unknown5c7fc0(self) != 2
						&& !elements[i]->isPlayer()
						&& elements[i]->unknown45a340() <= 2
						&& elements[i]->unknown490840() <= 50
						&& !elements[i]->unknown45ac40(0x17)
						&& rng.chance(20))
					{
						OPEM_MSG(isHostileTo(world->getPlayer()) ? 0x9e : 0x9d, 0, 0, 0, elements[i], self);
						alertGroup639ec0(elements[i], false);
						elements[i]->unknownB4 -= 20;
						opR1d_454260(elements[i]->getPosition(), 0xaf);
						opR1d_454260(elements[i]->getPosition(), 0xb0);
						int effectID;
						OpU8a_lookup2("Robot_Crushed", &effectID);
						opem_effectMgr->create()->init(opem_effectMgr, effectID, elements[i]->getPosition(), opem_effectOrigin, 0, 0, 0, 9, 0);
						elements[i]->die(false, 4, self, 7, 0, 0, 0, false);
					}
				}
			}
			changePos(dest, false);
		}
	}
	else if (cells(dest)->getEntity().isValid() && cells(dest)->getEntity() != self)
	{
		HEntity other = cells(dest)->getEntity();
		unknown5dd8a0(other);
		if (other->group->unknown9b4350() == 0)
			world->unknown72e4c0(other, true);
	}
	else
		changePos(dest, true);
	if (!player)
	{
		for (unsigned int i = 0; i < positions.size(); i++)
			world->unknown74b060(positions[i], opem_table_b96064[opem_table_b96080[unknown58]], 100);
	}
	if (status)
	{
		if (status == 1)
			world->unknown725930(self, true);
		else
			world->unknown464800(self);
	}
	for (unsigned int i = 0; i < trail.size(); i++)
	{
		if (OpV4c_Fn9d0ce0(positions, trail[i]->pos))
		{
			opem_deleteAt_9d8f20(trail, i);
			i--;
		}
	}
	if (player && !flag)
	{
		world->addTrailPoint(getPosition());
		world->unknown729520(getPosition());
		if (opem_cf4700)
		{
			if (opem_gameData.unknown46f4b0(1))
			{
				if (opem_d25de0[opem_cf4700->id]->unknown24 == 3)
					opem_playerData.addPolymindSuspicion(0.15f, 0x11, HEntity());
				else
					opem_playerData.addPolymindSuspicion(0.4f, 0x10, HEntity());
			}
			unknown5daf90(0x18);
		}
	}
	if (unknown58 == 2 && cells(dest)->getItem().isValid() && cells(dest)->getItem()->unknown457880() == 0)
	{
		HItem best;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == 0xd5 && parts[i]->unknown457cd0()
				&& (best.isNull() || parts[i]->unknown457ca0() < best->unknown457ca0()))
				best = parts[i];
		}
		if (best.isValid())
		{
			HItem item = cells(dest)->getItem();
			int matter = item->unknown9b6bf0();
			if (unknown45a920() < unknown5ca670())
				matter /= 2;
			int count = OpX5_minInt(matter / best->unknown457fb0(), best->unknown457cd0());
			best->unknown458360(count);
			if (player)
			{
				CPart *part = opem_cec088->unknown894e70(best);
				part->drawStatus(false);
				OPEM_MSG(0x185, &best->getName(0,0), &intToString(count), 0, self, HEntity());
			}
			int total = best->unknown457fb0() * count;
			if (total >= item->unknown9b6bf0())
				item->remove57dbe0(0, 1, 1, 1);
			else
				item->unknown450460(item->unknown9b6bf0() - total);
		}
	}
	unknown5dfd80();
	if (player && opem_d255e4)
		world->unknown71f700(getPosition(), 3);
	if (player)
	{
		opem_stats.add4729d0(0x3ef, steps, empty_b95303, -1);
		if (opem_stats.unknown472c70(0x3ef) % 8 == 0)
		{
			int total = unknown5ccab0();
			int sum = 0;
			for (unsigned int i = 0; i < parts.size(); i++)
			{
				if (parts[i]->getType() != 4)
				{
					total += parts[i]->unknown577790();
					if (parts[i]->unknown4578a0() == 1 && !parts[i]->unknown457cf0())
						sum += parts[i]->unknown577790();
				}
			}
			opem_stats.add4729d0(0xbf, total ? sum * 100 / total : 0, empty_b9530e, -1);
		}
		if (!flag)
		{
			if (steps > 1)
				opem_stats.add4729d0(0x3fb, steps - 1, empty_b9530f, -1);
			int mode = unknown5d1390();
			if (mode == 6)
				opem_stats.add4729d0(0x3f0, steps, empty_b9531d, -1);
			else
				opem_stats.add4729d0(mode + 0x3f1, steps, empty_b9531e, -1);
			if (opem_playerData.isSlotEmpty(3) && (*opem_stats.current)[0x3f1] && (*opem_stats.current)[0x3f3] && (*opem_stats.current)[0x3f2] && (*opem_stats.current)[0x3f4] && (*opem_stats.current)[0x3f5])
				opem_playerData.unknown77fbc0(3);
			if (steps >= 4)
				opem_playerData.unknown77fbc0(0x78);
		}
		world->unknown4657c0();
		opem_cf47fc++;
		if (opem_levels_ba4500[opem_location->type].interval && world->unknown4642f0() && world->unknown4642f0() % opem_levels_ba4500[opem_location->type].interval == 0
			&& opem_cf6898[1] < opem_levels_ba4500[opem_location->type].limit)
		{
			int amount = OpX5_minInt(opem_levels_ba4500[opem_location->type].amount, opem_levels_ba4500[opem_location->type].limit - opem_cf6898[1]);
			opem_tally.unknown6998a0(1, amount, 0);
		}
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->getType() <= 3)
				parts[i]->unknown4584a0();
		}
	}
	unknown5dd9c0(self, dest);
	if (!flag)
	{
		int destroyed = rollDestroy63c120();
		if (destroyed && isPlayer())
		{
			opem_stats.add4729d0(0x3f9, 1, empty_b9531f, -1);
			if (destroyed >= 4)
				opem_playerData.unknown77fbc0(0xab);
		}
	}
	if (getFaction() == 0 || getFaction() == 0x30)
	{
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown457cf0() && parts[i]->unknown4578a0() == 1 && (checkFragile603030(parts[i]) || unknown603280(parts[i])))
			{
				if (isPlayer())
				{
					opem_cec054->unknown49ad30();
					opem_cec054->unknown49adc0(1000);
				}
				break;
			}
		}
	}
	if (unknown5d2380(0x1f).isValid())
	{
		int delay = 0;
		if (player)
		{
			vector<HEntity> *list = world->unknown4636b0();
			for (unsigned int i = 0; i < list->size(); i++)
			{
				if ((*list)[i].operator->() == NULL)
					opem_eraseStep_9d6440(*list, i);
				else if ((*list)[i]->getInfo()->unknown8C > delay
					&& (*list)[i]->getGroup()->unknown9b4350() == 3
					&& OpQ1_distanceCeil_40a3f0(getPosition(), (*list)[i]->getPosition()) <= (*list)[i]->unknown5c7d30() - unknown5d2150(0x1e, 0))
					delay = (*list)[i]->getInfo()->unknown8C;
			}
		}
		else
		{
			Area area;
			cells.getRect(getPosition(), 12, area);
			for (int x = area.min.x; x <= area.max.x; x++)
			{
				for (int y = area.min.y; y <= area.max.y; y++)
				{
					if (cells(x,y)->getEntity().isValid()
						&& cells(x,y)->getEntity()->getGroup()->unknown9b4350() == 3
						&& !cells(x,y)->getEntity()->getTarget()
						&& cells(x,y)->getEntity()->getInfo()->unknown8C > delay
						&& OpQ1_distanceCeil_40a3f0(getPosition(), Point(x,y)) <= cells(x,y)->getEntity()->unknown5c7d30() - unknown5d2150(0x1e, 0)
						&& world->isReachable(cells(x,y)->getEntity()->unknown5c7d30(), Point(x,y), getPosition()))
						delay = cells(x,y)->getEntity()->getInfo()->unknown8C;
				}
			}
		}
		delay += opem_d306a4.randomInRange_40c130();
		delay -= OpX5_maxInt(0, OpX5_minInt(unknownB0 / 10, 3));
		vector<HItem> items;
		unknown5d2430(0x1f, &items);
		for (unsigned int i = 0; i < items.size(); i++)
		{
			if (items[i]->unknown45cb30() > delay)
				items[i]->unknown44fc60(items[i]->unknown45cb30() - delay);
			else
			{
				if (player)
				{
					OPEM_MSG(0xc3, &items[i]->getName(0,0), 0, 0, self, HEntity());
					do { opS2_logPhrase_5141b0(0x60, &items[i]->getName(0,0), 0, 0, self, 0); } while (false);
					opem_cec054->unknown49adc0(2000);
				}
				items[i]->remove57dbe0(1, 0, 9, 1);
			}
		}
	}
	if (player && opem_table_b91198[opem_location->type]
		&& stringToInt(opem_gameData.getEntryText("datMetDataMiner_g"))
		&& !stringToInt(opem_gameData.getEntryText("datHostileToDataMiner_g"))
		&& !stringToInt(opem_gameData.getEntryText("enemiesWithArchitect_g")))
	{
		vector<HProp> props;
		world->addPropsAround(self, &props);
		if (!props.empty())
		{
			sort(props.begin(), props.end());
			props.erase(unique(props.begin(), props.end()), props.end());
			for (unsigned int i = 0; i < props.size(); i++)
			{
				if (props[i].operator->() && props[i]->unknown45cb30() && !props[i]->unknown9b8f00()->unknownF8
					&& !props[i]->unknown457b10() && !props[i]->unknown45cb30()->unknown74)
				{
					props[i]->unknown45cb30()->unknown74 = true;
					OpEM_PropRecord *rec = props[i]->unknown45cb30()->unknown45c1c0(5);
					if (rec && !rec->unknown8)
					{
						int chance = 50;
						if (props[i]->unknown45c800(0x8c))
							chance = 100;
						else if (props[i]->unknown45c800(0x8d))
							chance = 0;
						if (rng.chance(chance))
						{
							vector<Point> points;
							if (OpD_collectProps_517ae0(props[i]->unknown44ab40(), &points, false, 2, 0))
							{
								rec->unknown8 = true;
								string msg = props[i]->getName() + " flashes as you approach.";
								opW5_message(0x320, HEntity(), msg, 0);
								opR1d_454260(points.front(), 0x7e);
								int effect;
								if (OpU8a_lookup2("P_Machine_Door_Open", &effect))
								{
									for (unsigned int j = 0; j < points.size(); j++)
									{
										if (world->isVisible4631c0(points[j]))
											opem_effectMgr->create()->init(opem_effectMgr, effect, points[j], opem_effectOrigin, 0, 0, 0, 9, 0);
										cells(points[j])->getProp()->unknown45ce10(true, 0, true, HEntity());
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (player)
	{
		if (world->unknown715d20())
		{
			vector<Point> &spots = (*world->unknown459070())[0];
			for (unsigned int i = 0; i < spots.size(); i++)
			{
				if (!cells(spots[i])->getProp()->unknown45cb30()->unknown11
					&& !cells(spots[i])->getProp()->unknown45cb30()->unknown10
					&& cells(spots[i])->getProp()->unknown45cb30()->unknown28 >= 0
					&& OpQ1_distanceCeil_40a3f0(getPosition(), spots[i]) <= 10)
				{
					cells(spots[i])->getProp()->unknown45cb30()->unknown11 = true;
					OPEM_MSG(0x2af, 0, 0, 0, self, HEntity());
					if (!world->unknown463160(spots[i]) && !world->isVisible4631c0(spots[i]))
					{
						vector<HMarker> &markers = (*world->unknown463ec0())[0];
						for (unsigned int j = 0; j < markers.size(); j++)
						{
							if (markers[j]->pos == spots[i])
								goto marked;
						}
						markers.push_back(opem_factory->createC());
						markers.back()->unknown6c20b0(0, spots[i], 0);
						opem_cec034->unknown987de0();
					}
marked:
					opem_cec054->unknown49afd0(spots[i], true);
					opR1d_4541b0(0x12b, 0, 0);
					opem_cec054->unknown49ad70(opem_tick + 500);
					if (opem_location->type == 0x22 && cells(spots[i])->getProp()->unknown45cb30()->unknown45c1c0(0x31))
					{
						HEntity owner;
						Point target(-1);
						bool done = false;
						world->unknown74bb90(cells(spots[i])->getProp(), &owner, &target, &done);
						if (owner.isValid() && !done && target.x != -1)
							world->unknown6c6b90(target, "COM_Cave_Seal_Timer", 0, -1);
					}
				}
			}
		}
		if (world->unknown715ed0())
		{
			vector<Point> &spots = (*world->unknown459070())[5];
			for (unsigned int i = 0; i < spots.size(); i++)
			{
				if (!world->unknown463b50(spots[i]) && OpQ1_distanceCeil_40a3f0(getPosition(), spots[i]) <= 15)
				{
					world->unknown463b80(spots[i]);
					OPEM_MSG(0x29f, 0, 0, 0, self, HEntity());
					if (!world->unknown463160(spots[i]) && !world->isVisible4631c0(spots[i]))
					{
						vector<HMarker> &markers = (*world->unknown463ec0())[0];
						for (unsigned int j = 0; j < markers.size(); j++)
						{
							if (markers[j]->pos == spots[i])
								goto marked2;
						}
						markers.push_back(opem_factory->createC());
						markers.back()->unknown6c20b0(0, spots[i], 5);
						opem_cec034->unknown987de0();
					}
marked2:
					opem_cec054->unknown49afd0(spots[i], false);
					opR1d_4541b0(0x12b, 0, 0);
					opem_cec054->unknown49ad70(opem_tick + 500);
				}
			}
			if (opem_location->type == 0xd)
			{
				vector<int> *list = world->unknown463bc0();
				for (unsigned int i = 0; i < list->size(); i++)
				{
					for (unsigned int j = 0; j < opem_d31640[(*list)[i]].size(); j++)
					{
						if (OpQ1_distanceCeil_40a3f0(getPosition(), opem_d31640[(*list)[i]][j]->unknown4184d0()) <= 15)
						{
							if (!opem_d31640[(*list)[i]][j]->unknown457b10())
							{
								OPEM_MSG(0x2a0, 0, 0, 0, self, HEntity());
								Point center = opem_d31640[(*list)[i]][j]->unknown4184d0();
								for (unsigned int k = 0; k < opem_d31640[(*list)[i]].size(); k++)
								{
									Point p = opem_d31640[(*list)[i]][k]->unknown4184d0();
									world->unknown4647a0(p, 1);
								}
								opem_cec054->unknown49afd0(center, false);
								opR1d_4541b0(0x12b, 0, 0);
								opem_cec054->unknown49ad70(opem_tick + 500);
							}
							OpT8a_eraseAt(*list, i);
							break;
						}
					}
				}
			}
		}
	}
	if (player && opem_cf4700)
	{
		if (OpX5_containsRecord(opem_d25de0[opem_cf4700->id]->unknown148, 0) && cells(getPosition())->unknown45de40())
		{
			HItem item = unknown5cbd10();
			if (item.isValid())
				item->unknown44fc60(OpX5_minInt(item->unknown45cb30() + rng.rangeInt(1, 5.0f), item->unknown457fb0()));
			OPEM_MSG(0x309, 0, 0, 0, self, HEntity());
			if (opem_gameData.unknown46f4b0(1))
				opem_playerData.addPolymindSuspicion(-3.0f, 0, HEntity());
		}
		else if (OpX5_containsRecord(opem_d25de0[opem_cf4700->id]->unknown148, 2))
		{
			if (cells(getPosition())->unknown45de40())
			{
				HItem dropped = world->unknown71e7c0(getPosition(), rng.rangeInt(1, 5.0f), 0);
				if (dropped.isValid())
					world->unknown464840(dropped);
				OPEM_MSG(0x30b, &string("debris"), 0, 0, self, HEntity());
			}
			else if (cells(getPosition())->getItem().isValid() && cells(getPosition())->getItem()->unknown457e30())
			{
				HItem found = cells(getPosition())->getItem();
				OPEM_MSG(0x30b, &found->getName(0,0), 0, 0, self, HEntity());
				int amount = rng.rangeInt(5.0f, found->unknown9b6bf0() / 2 + 1);
				found->remove57dbe0(0, 0, 1, 1);
				HItem dropped = world->unknown71e7c0(getPosition(), amount, 0);
				if (dropped.isValid())
					world->unknown464840(dropped);
			}
		}
	}
	if (player)
	{
		HItem shovel = unknown5d25e0(0xd7);
		if (shovel.isValid() && unknown50 >= shovel->unknown457fb0())
		{
			Point target(positions[0], opem_dirOffsets[unknown54]);
			if (cells.contains(target))
			{
				int effect = 0;
				bool dug = false;
				if (cells(target)->unknown45d500() && cells(target)->getProp()->unknown45c630() != -1 && !cells(target)->getProp()->unknown45c800(8))
				{
					OPEM_MSG(0x298, &shovel->getName(0,0), &cells(target)->getProp()->getName(), 0, self, HEntity());
					cells(target)->getProp()->unknown45ce10(false, 0, false, self);
					if (OpU8a_lookup2("Laser_Shovel_Auto", &effect))
						opem_effectMgr->create()->init(opem_effectMgr, effect, target, opem_effectOrigin, 0, 0, 0, 9, 0);
					dug = true;
				}
				if (cells(target)->unknown45d4e0() && !cells(target)->unknown45db70() && cells(target)->getArmor() != -1 && !cells(target)->getEffect(8))
				{
					OPEM_MSG(0x298, &shovel->getName(0,0), &cells(target)->unknown45d140(), 0, self, HEntity());
					cells(target)->unknown45e110(false, false, self);
					opem_stats.add4729d0(0x409, 1, empty_b95326, -1);
					int effect2 = 0;
					if (!effect2 && OpU8a_lookup2("Laser_Shovel_Auto", &effect2))
						opem_effectMgr->create()->init(opem_effectMgr, effect2, target, opem_effectOrigin, 0, 0, 0, 9, 0);
					dug = true;
				}
				if (dug)
				{
					alertGroup639ec0(HEntity(), false);
					destroyItems_63a0d0();
				}
			}
		}
	}
	if (!unknown5fdd30())
		return cost;
	HEntity entity = self;
	vector<HEntity> targets;
	unknown5c8880(&targets);
	opem_shuffle_9d9fc0(targets);
	for (unsigned int i = 0; i < targets.size(); i++)
	{
		if (targets[i]->unknown63c340(self))
		{
			if (entity.operator->() == NULL)
				return cost;
			break;
		}
	}
	if (unknown5C >= 2.0 && opem_table_b95150[record->unknown28])
	{
		if (isPlayer())
		{
			opem_stats.add4729d0(0x3fc, 1, empty_b95327, -1);
			if (opem_stats.unknown472c70(0x3fc) == 30)
				opem_playerData.unknown77fbc0(0xe6);
		}
		if (rng.chance(unknown5C < 8.0 ? 3 : (unknown5C < 16.0 ? 5 : 10)))
			cells(dest)->unknown66d580(false);
	}
	if (opem_cefc14 && (positions[0] == opem_cfcc6c || positions[0] == opem_d3578c) && opem_cefc14->take48bf50(self))
	{
		unknown5ded70(10000);
		unknown5deb40(10000);
		opem_cec054->showInfo81a340(self);
		opR1d_4541b0(0x8a, 0, 0);
		if (opem_cefc14)
			opem_cefc14->unknown7ac1c0(self, 0, 0, unknown416f40());
		opem_cec054->unknown49adc0(2000);
	}
	if (player && opem_cefc5d && !opem_cefc9c && unknown5C >= 10.0)
	{
		do
		{
			opem_cf1080.unknown451400(1);
			if (-1 != -1)
				opR1d_4541b0(-1, 0, 0);
			OPEM_MSG(0x324, &string("ALERT: LUIGI IS DIGGING AGAIN."), 0, 0, HEntity(), HEntity());
			opem_logMsgs->scrollToEnd();
		} while (false);
		opem_cefc9c = true;
	}
	return cost;
}
