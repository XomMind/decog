// op_unchained_6927e0: per-turn update of the Unchained / unit-state object at 0xcf6888 (Unknown_45f320_45f560).
// NOTE: all types below are private placeholders (prefix U6) declared for this one function; names are placeholders
// unless stated otherwise.
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

struct U6Point	// NOTE: placeholder layout
{
	int x;
	int y;

	U6Point();	// 0x453b40 (-1,-1)
	U6Point(int v);	// 0x409990
	U6Point(const U6Point &p);	// 0x46ca50
	U6Point &operator=(const U6Point &p);	// NOTE: folded with the copy constructor (0x46ca50)
	U6Point(int x_, int y_);	// 0x46ca20
	void fill(int v);	// 0x409ff0
};

struct U6Area	// NOTE: placeholder layout
{
	U6Point a;
	U6Point b;

	U6Area();	// 0x40b100
	U6Area(const U6Area &other);	// 0x40b130
	bool contains(const U6Point &p);	// 0x40b750
	U6Point randomPoint();	// 0x40be90
};

struct U6Ranges { int v[4]; };	// NOTE: placeholder layout (pair of ranges)

struct U6Timer	// NOTE: placeholder name (OpR3d_Expiry)
{
	int a;
	int b;

	U6Timer();	// 0x45f020
	void randomize(const U6Ranges &ranges);	// 0x45f070
	bool hasExpired();	// 0x690da0
	void set(int a, int b);	// 0x690d40
	void reset();	// 0x45f0a0
};

struct U6Pair	// NOTE: placeholder name
{
	int a;
	int b;

	void fill(int v);	// 0x409ff0
	int randomInRange();	// 0x40c130
};

struct U6Range	// NOTE: placeholder name
{
	int a;
	int b;

	bool contains(int v);	// 0x40c190
};

struct U6Record	// NOTE: placeholder layout (entity record)
{
	int unknown000;
	char pad004[0x9c - 0x4];
	int unknown9c;
	char pad0a0[0x110 - 0xa0];
	int unknown110;
	bool unknown114;
	char pad115[0x118 - 0x115];
	U6Range ranks;
	char pad120[0x13c - 0x120];
	vector<int> unknown13c;
	char pad14c[0x1ac - 0x14c];
	string name;	// 0x1ac
};
extern vector<U6Record *> u6_records_d25de0;	// NOTE: placeholder name

class U6AI	// NOTE: placeholder layout (EntityAI)
{
public:
	U6AI(class U6HEntity e, int type, int b);	// 0x57f6a0

	char pad[0x130];
	void chase(U6HEntity e, int a, int b, int c, int d);	// 0x5b4710
	bool unknown5b66c0(U6Point &out);	// NOTE: placeholder name
	bool findPatrolSpot(U6Point &out);	// 0x5b6850
	void unknown44bef0(int v);	// NOTE: placeholder name (folded setter)
	void unknown44cea0(int v);	// NOTE: placeholder name (folded setter)
	void unknown451930(int v);	// NOTE: placeholder name (folded setter)
	void unknown459410(U6Area &area);	// NOTE: placeholder name
	void setFollowEntity(U6HEntity e, int flag);	// 0x5b2f80
	int getBehavior();	// NOTE: placeholder name (folded getter 0x9b8f00)
	void unknown459470(U6Area &area);	// NOTE: placeholder name
	void getFollowers580a90(vector<U6HEntity> &out, int range);	// NOTE: placeholder name
	bool anySmallGroup();	// NOTE: placeholder name (0x580c80)
	int unknown9b4350();	// NOTE: placeholder name (folded getter)
	bool unknown458fb0(U6HEntity e);	// NOTE: placeholder name
	U6Area &getArea4b5730();	// NOTE: placeholder name
	U6HEntity *pickTarget580ec0();	// NOTE: placeholder name
	bool anyHostileXom();	// NOTE: placeholder name (0x580d00)
	void unknown459540(const U6Point &p);	// NOTE: placeholder name
};

class U6Entity	// NOTE: placeholder layout
{
public:
	bool unknown5c98c0(int a, int b, int c);	// NOTE: placeholder name
	U6Point &getPosition();	// 0x45a4a0
	U6AI *getAI();	// 0x45b590
	void setAI(U6AI *ai);	// 0x64ecf0
	void changePos(const U6Point &p, int a);	// 0x5dccb0
	int unknown5c92e0(int v);	// NOTE: placeholder name
	int unknown639530(int type, int value);	// NOTE: placeholder name
	void loadout63c770(bool flag);	// NOTE: placeholder name
	void unknown63c660();	// NOTE: placeholder name
	bool unknown5d26e0(int v);	// NOTE: placeholder name
	bool unknown5d1280(int v);	// NOTE: placeholder name
	const string &getName();	// NOTE: placeholder name (folded getter 0x416f40)
	void unknown45b2a0();	// NOTE: placeholder name
	void unknown637bb0();	// NOTE: placeholder name
	void setName(const string &name);	// NOTE: placeholder name (0x45b070)
	int getTarget();	// NOTE: placeholder name (0x45a760)
	bool unknown45aaa0(U6HEntity e);	// NOTE: placeholder name
	bool unknown5d5250();	// NOTE: placeholder name
	U6Record *getRecord();	// NOTE: placeholder name (folded getter 0x9b4350)
	class U6HSquad getGroup();	// 0x45a3f0
	int getSize();	// 0x45a360
	class U6HItem unknown5d2380(int slot);	// NOTE: placeholder name
	int unknown5c8db0();	// NOTE: placeholder name
	void die(bool a, int b, U6HEntity c, int d, int e, int f, int g, int h);	// NOTE: placeholder name (0x633790)
	int unknown5d15a0(int v);	// NOTE: placeholder name
	int unknown45a880();	// NOTE: placeholder name
	int unknown5cab90();	// NOTE: placeholder name
};

class U6Squad	// NOTE: placeholder layout
{
public:
	int unknown9b4350();	// NOTE: placeholder name (folded getter)
};

class U6HSquad	// NOTE: placeholder layout
{
public:
	int ID;
	U6Squad *operator->() const;	// 0x9b7250
};

class U6HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	U6HEntity();	// 0x9b6590
	U6Entity *operator->() const;	// 0x9b6570
	bool isValid() const;	// 0x9b7230
	bool operator==(U6HEntity other) const;	// 0x9b78e0
	bool isNull() const;	// 0x9b65d0
	void reset();	// 0x9b7270
};

class U6HProp	// NOTE: placeholder layout
{
public:
	int ID;
	U6HProp();	// 0x9b6590
};

class U6HItem	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
};

struct U6Loc	// NOTE: placeholder layout (location)
{
	int unknown00;
	int type;
	char pad08[0x25 - 0x08];
	bool unknown25;

	string getText();	// 0x46ed40
};

class U6HLoc	// NOTE: placeholder layout
{
public:
	int ID;
	U6Loc *operator->() const;	// 0x9b7910
};
extern U6HLoc u6_location_d1e888;	// NOTE: placeholder name

struct U6Access	// NOTE: placeholder layout (map exit)
{
	char pad00[0x8];
	U6HLoc loc;
	char pad0c;
	bool unknown0d;

	void unknown6c16d0(string text);	// NOTE: placeholder name
};

class U6CMap	// NOTE: placeholder name (0xcec054)
{
public:
	void labelAccess80e3a0(int a, U6Access *access);	// NOTE: placeholder name
	void unknown49adc0(int delay);	// NOTE: placeholder name
};
extern U6CMap *u6_cmap_cec054;	// NOTE: placeholder name

class U6Map	// NOTE: placeholder name (0xcefc4c)
{
public:
	int unknown4642d0();	// NOTE: placeholder name
	U6HEntity getPlayer();	// 0x4630f0
	int getTurn();	// 0x464270
	U6Point &unknown4184d0();	// NOTE: placeholder name (folded getter)
	bool findPlaceableNear(const U6Point &p, U6Point &out, int size);	// 0x71c150
	U6HEntity placeEntity(U6Record *record, const U6Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);	// 0x6c58c0
	U6HItem giveItem(const string &name, U6HEntity e, int a, int b);	// 0x6c52b0
	U6HItem unknown6c51d0(U6Record *record, U6HEntity e, bool a, bool b);	// NOTE: placeholder name
	U6Record *unknown6c5600(int a, int b, int c, int d);	// NOTE: placeholder name
	U6Access *unknown7143e0(int a);	// NOTE: placeholder name
	bool unknown463160(U6Access *access);	// NOTE: placeholder name
	void announceMachine(U6HLoc loc);	// 0x71dd30
	void unknown4647a0(U6Access *access, int a);	// NOTE: placeholder name
	bool unknown4631f0(U6HEntity e);	// NOTE: placeholder name
	void unknown7142a0(vector<U6Point *> &out);	// NOTE: placeholder name
	bool unknown716940(const U6Point &from, const U6Point &to, U6Entity *e, int *length);	// NOTE: placeholder name
	bool isVisible(const U6Point &p);	// 0x4631c0
	bool unknown463160(const U6Point &p);	// NOTE: placeholder name (overload of the access check)
	void unknown6c65a0(U6HEntity e, const string &text, int a);	// NOTE: placeholder name
	bool isReachable(int range, const U6Point &from, const U6Point &to);	// 0x465230
	bool unknown463400(U6HEntity e);	// NOTE: placeholder name
	bool unknown714920(const U6Point &p, U6HEntity e);	// NOTE: placeholder name
	bool unknown716e50(const U6Point &p);	// NOTE: placeholder name
	bool unknown463380(int x, int y);	// NOTE: placeholder name
	vector<vector<U6Point> > *unknown459070();	// NOTE: placeholder name
	bool unknown74d420(const U6Point &p, U6Point &out);	// NOTE: placeholder name
	U6HEntity unknown6c5dc0(const string &name, const U6Point &pos, int a, bool b, int c, int d, bool e);	// NOTE: placeholder name
	vector<U6HEntity> *unknown4644b0();	// NOTE: placeholder name
	bool unknown7168e0(const U6Point &from, const U6Point &to, U6Entity *e, vector<U6Point> &path);	// NOTE: placeholder name
	int unknown715730(int a);	// NOTE: placeholder name
};
extern U6Map *u6_world_cefc4c;	// NOTE: placeholder name

class U6Cell	// NOTE: placeholder layout
{
public:
	U6HEntity getEntity();	// 0x45d250
	int getTerrain();	// NOTE: placeholder name (folded getter 0x9fcd80)
	bool unknown66a630();	// NOTE: placeholder name
	void trigger(int a, int b, U6HEntity e);	// NOTE: placeholder name (0x45e110)
	bool canPlaceEntity(int size);	// 0x66ad20
	bool unknown4550b0();	// NOTE: placeholder name (folded getter)
};

class U6Grid	// NOTE: placeholder name (0xcfd44c)
{
public:
	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
	void getRandom_9cf0c0(U6Point &out);	// NOTE: placeholder name
	U6Point getRandom_9cf050();	// NOTE: placeholder name
	U6Cell **atPoint(const U6Point &p);	// 0x9ced70
	U6Cell **at(int x, int y);	// 0x9ceda0
	void getRect(const U6Point &p, int radius, U6Area *out);	// 0x9b4430
	U6Area getArea();	// 0x9b4400
};
extern U6Grid u6_cells_cfd44c;	// NOTE: placeholder name

class U6Carto	// NOTE: placeholder name (0xcfe568, Cartographer2D)
{
public:
	bool findPath(const U6Point &from, const U6Point &to, void *moveCost, void *data, vector<U6Point> &path);	// 0x40c9a0
	void unknown40ca20(const U6Point &start, int range, void *cost, int a);	// NOTE: placeholder name
};
extern U6Carto u6_carto_cfe568;	// NOTE: placeholder name
extern void *u6_moveCost_cefc30;	// NOTE: placeholder name

struct U6Party	// NOTE: placeholder layout
{
	int unknown00;
	U6HEntity leader;
};

class U6Overmind	// NOTE: placeholder name (Overmind at 0xcf6428)
{
public:
	void *spawnPatrolParty(U6HEntity e, int a, int b, int c, int d, int e2, int f, int g, int h);	// 0x6896d0
	vector<U6Party *> &getParties();	// NOTE: placeholder name (folded getter 0x45ee50)
	bool unknown683500(U6Point *out, bool allowVisible, int minDistance, bool ignoreProps, const U6Point &from, U6Point **access, bool preferProps, bool ignoreUsed);	// 0x683500
};
extern U6Overmind u6_overmind_cf6428;	// NOTE: placeholder name

class U6WL	// NOTE: placeholder name (OpR5h_WL<int>)
{
public:
	U6WL();	// 0x9bab50
	~U6WL();	// 0x700dd0
	void reset();	// 0x9c07a0
	void add(int value, int weight);	// 0x9ba310
	bool empty();	// 0x9b81b0
	int &pick();	// 0x9ba470

	char pad[0x24];
};

class U6Xom	// NOTE: placeholder name (0xd25450)
{
public:
	void unknown69e450();	// NOTE: placeholder name
};
extern U6Xom u6_xom_d25450;	// NOTE: placeholder name
extern bool u6_xomEnabled_d25450;	// NOTE: placeholder name (first byte of the Xom object)
extern int u6_xomTurn_d25454;	// NOTE: placeholder name

class U6GameData	// NOTE: placeholder name (0xd1e860)
{
public:
	int unknown46f4e0();	// NOTE: placeholder name
	bool isFlagEnabledA();	// 0x46fb60
};
extern U6GameData u6_gameData_d1e860;	// NOTE: placeholder name

class U6Stats	// NOTE: placeholder name (0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string s, int a);	// 0x4729d0
	int unknown472c70(int id);	// NOTE: placeholder name
	void add472b90(unsigned int id, int value);	// 0x472b90
};
extern U6Stats u6_stats_d2c658;	// NOTE: placeholder name

class U6PlayerData	// NOTE: placeholder name (0xcf45d8)
{
public:
	bool unknown46dd90();	// NOTE: placeholder name
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern U6PlayerData u6_playerData_cf45d8;	// NOTE: placeholder name

class U6Speaker	// NOTE: placeholder name (OpW5_RolledValues)
{
public:
	void say(int a, int b, string s);	// 0x49e250
};
extern U6Speaker *u6_speaker_cefb48;	// NOTE: placeholder name

class U6MessageLog { public: void setUnknown(int value); };	// NOTE: placeholder name (0xcf1080)
extern U6MessageLog u6_messageLog_cf1080;
class U6ConsoleA { public: void unknown8758d0(bool flag); };	// NOTE: placeholder name (0xcec058)
extern U6ConsoleA *u6_consoleA_cec058;
class U6LogMsgs { public: void scrollToEnd(); };	// 0x7b4f10
extern U6LogMsgs *u6_logMsgs_cec0b4;
extern bool u6_option_d28fb0;	// NOTE: placeholder name
bool u6_logMessage_5111e0(int id, const string &text, int a, int b, U6HProp c, U6HProp d, int e, int f);	// NOTE: placeholder name
void u6_playSound_4541b0(int id, int a, int b);	// NOTE: placeholder name
void u6_logPhrase_5141b0(int id, const string *a, const string *b, int c, U6HEntity d, int e);	// NOTE: placeholder name
void logError(string location, string message);

#define U6_LOG(id,text) do { if (u6_logMessage_5111e0(id,text,0,0,U6HProp(),U6HProp(),0,0)) u6_consoleA_cec058->unknown8758d0(true); u6_logMsgs_cec0b4->scrollToEnd(); } while (0)	// NOTE: placeholder macro
#define U6_ALERT(level,sound,text) do { u6_messageLog_cf1080.setUnknown(level); if ((sound) != -1 && !(u6_option_d28fb0 && (sound) != 0 && (sound) != 1)) u6_playSound_4541b0(sound,0,0); U6_LOG(0x324,text); u6_logMsgs_cec0b4->scrollToEnd(); } while (0)	// NOTE: placeholder macro

struct U6MapCol { int value; int rest[12]; };	// NOTE: placeholder name; one int column of the 0x34-byte map type records
extern U6MapCol u6_mapTypes00_ba44f0[];	// NOTE: placeholder name
extern U6MapCol u6_mapTypes04_ba44f4[];	// NOTE: placeholder name
extern U6MapCol u6_mapTypes08_ba44f8[];	// NOTE: placeholder name
extern int u6_ba4ca8[][5];	// NOTE: placeholder name
extern int u6_ba4fc8[];	// NOTE: placeholder name
extern int u6_ba4fa0[];	// NOTE: placeholder name
extern int u6_ba50b8[];	// NOTE: placeholder name
extern int u6_ba4430[][3];	// NOTE: placeholder name
extern int u6_difficulty_cf4718;	// NOTE: placeholder name
extern int u6_caf2a4;	// NOTE: placeholder name
extern int u6_caf2a8;	// NOTE: placeholder name
extern bool u6_cefb2a;	// NOTE: placeholder name
extern U6Ranges u6_d22580;	// NOTE: placeholder name
extern U6Ranges u6_cfe12c;	// NOTE: placeholder name
extern U6Ranges u6_d31b58;	// NOTE: placeholder name
extern U6Ranges u6_cf0fb8[];	// NOTE: placeholder name
extern U6Ranges u6_d223d4;	// NOTE: placeholder name
extern U6Ranges u6_cf7658;	// NOTE: placeholder name
extern U6Ranges u6_cf6ec4;	// NOTE: placeholder name
extern U6Ranges u6_d1ed48;	// NOTE: placeholder name
extern vector<U6Record *> u6_vec_cf7574;	// NOTE: placeholder name
extern vector<U6HEntity> u6_vec_cf6adc;	// NOTE: placeholder name
extern vector<U6HEntity> u6_vec_cf6aec;	// NOTE: placeholder name
extern string u6_d22674;	// NOTE: placeholder name

extern string u6_names_d225b0[];	// NOTE: placeholder name
extern U6Pair u6_range_d01d50;	// NOTE: placeholder name
extern U6Pair u6_range_d32384;	// NOTE: placeholder name
extern U6Ranges u6_cfc194;	// NOTE: placeholder name

class U6RecWL	// NOTE: placeholder name (OpR5h_WL<EntityRecord *> at 0xd2601c)
{
public:
	U6Record *&pick();	// 0x9ba470
};
extern U6RecWL u6_wl_d2601c;	// NOTE: placeholder name
struct U6Prop	// NOTE: placeholder layout (prop record)
{
	int id;
	string name;
};

class U6PropWL	// NOTE: placeholder name (OpR5h_WL<PropRecord *> at 0xd29da4)
{
public:
	U6Prop *&pick();	// 0x9ba470
};
extern U6PropWL u6_wl_d29da4;	// NOTE: placeholder name

struct U6Col5 { int value; int rest[4]; };	// NOTE: placeholder name; one int column of a 0x14-byte table
extern U6Col5 u6_ba4ff0[];	// NOTE: placeholder name
extern U6Col5 u6_ba4ff4[];	// NOTE: placeholder name
extern U6Col5 u6_ba4ff8[];	// NOTE: placeholder name
extern U6Col5 u6_ba4ffc[];	// NOTE: placeholder name
extern int u6_ba5174[];	// NOTE: placeholder name
extern int u6_ba53a4[];	// NOTE: placeholder name
extern int u6_ba5854[];	// NOTE: placeholder name
extern int u6_ba59d4[];	// NOTE: placeholder name
extern int u6_ba59e8[];	// NOTE: placeholder name
extern vector<U6Point> u6_dijkstra_d15e58;	// NOTE: placeholder name
extern vector<int> u6_vec_d20b5c;	// NOTE: placeholder name
extern char u6_cf0c68;	// NOTE: placeholder name
extern U6Point u6_point_d216e8;	// NOTE: placeholder name
extern int u6_d216ec;	// NOTE: placeholder name (second word of u6_point_d216e8)
extern U6Ranges u6_d1deec;	// NOTE: placeholder name
extern vector<string> u6_strs_cf08b4;	// NOTE: placeholder name
extern vector<string> u6_strs_cf45a0;	// NOTE: placeholder name
extern string u6_names_cfaca0[];	// NOTE: placeholder name
extern int u6_cf462c;	// NOTE: placeholder name
extern int u6_cefb6c;	// NOTE: placeholder name
extern vector<int> u6_vec_cf4554;	// NOTE: placeholder name
struct U6Stat	// NOTE: placeholder layout
{
	char pad00[0x8c];
	int unknown8c;

	int getTotal();	// NOTE: placeholder name (0x457160)
};
extern vector<U6Stat *> u6_vec_d2d1c4;	// NOTE: placeholder name

class Entity { public: const string &getName(); };	// 0x45a280 (mapped)
class RNG { public: bool chance(int percent); int rangeInt(float a, float b); };	// RNG
extern RNG rng;	// NOTE: placeholder name (rng)

class U6Plan	// NOTE: placeholder name (Owned_45f890)
{
public:
	bool unknown672f20(U6HEntity e, int type, bool force, string text);	// NOTE: placeholder name
};

void u6_message_49c610(int type, U6HEntity entity, const string &text, int value);	// NOTE: placeholder name (opW5_message)
int u6_sound_454260(const U6Point &pos, unsigned int sound);	// NOTE: placeholder name (opR1d_454260)
void u6_eraseStep_9d6440(vector<U6HEntity> &v, int &index);	// NOTE: placeholder name
void u6_eraseAt_9da940(vector<U6HEntity> &v, int index);	// NOTE: placeholder name
void u6_eraseAt_9d5190(vector<U6Point> &v, int index);	// NOTE: placeholder name
void u6_eraseStep_9e2670(vector<U6Timer> &v, int &index);	// NOTE: placeholder name
void u6_eraseAt_9dae00(vector<U6Timer> &v, int index);	// NOTE: placeholder name
bool u6_findByName_9d7530(vector<U6Record *> &v, const string &name, U6Record *&out);	// NOTE: placeholder name
int u6_minInt(int a, int b);	// 0x9cdb30
void u6_clearDijkstraResults();	// NOTE: placeholder name (clearDijkstraResults)
bool u6_containsPoint_9d0ce0(vector<U6Point> &v, U6Point p);	// NOTE: placeholder name
int u6_indexOfMinInt_9d9270(vector<int> &v);	// NOTE: placeholder name
void u6_insert_9d8fc0(vector<U6HEntity> &v, int index, U6HEntity e);	// NOTE: placeholder name
void u6_insertAt_9dbdc0(vector<int> &v, int index, int value);	// NOTE: placeholder name
int u6_randomIndex_9d9b20(vector<U6Stat *> &v);	// NOTE: placeholder name
bool u6_logEntity_5111e0(int id, const string *text, const string *a, const string *b, U6HEntity e, U6HProp p, const U6Point *pt, bool flag);	// NOTE: placeholder name (same function as u6_logMessage_5111e0)
void u6_sweepGetSurroundingCells(const U6Point &point, vector<U6Point> &adjacent);	// NOTE: placeholder name (sweepGetSurroundingCells)
U6Point u6_randomPoint_9d5350(vector<U6Point> &v);	// NOTE: placeholder name (OpU8a_randomPoint)
extern int TERRAIN_CAVE_WALL;
extern U6Ranges u6_cf1f90;	// NOTE: placeholder name
extern U6Ranges u6_d20444;	// NOTE: placeholder name
extern U6Ranges u6_d396f4;	// NOTE: placeholder name
extern U6Ranges u6_cf34f8;	// NOTE: placeholder name
int u6_distance_406480(int x1, int y1, int x2, int y2);	// NOTE: placeholder name (opw8_distance)
void u6_addUniqueEntity_9d30e0(vector<U6HEntity> &v, U6HEntity e);	// NOTE: placeholder name (OpX5_addUniqueEntityData)
void u6_shuffle_9d9fc0(vector<U6HEntity> &v);	// NOTE: placeholder name (OpV4c_shuffle)
bool u6_containsRecord_9db330(vector<int> &v, int value);	// NOTE: placeholder name (OpX5_containsRecord)
void logFatal(string module, string message);
extern bool u6_caf21c[];	// NOTE: placeholder name
extern U6Ranges u6_d305c8;	// NOTE: placeholder name
extern int u6_caf160;	// NOTE: placeholder name
void u6_shuffle_9d8f80(vector<U6Point *> &v);	// NOTE: placeholder name (OpS8c_shuffle<int>)
U6HEntity u6_restoreEntity_690940(struct U6Stored *stored, const U6Point &pos, int a, int b, int c);	// NOTE: placeholder name (OpD_restoreEntity_690940)
string intToString(int value);
extern U6Ranges u6_d35b38;	// NOTE: placeholder name
int u6_maxInt(int a, int b);	// 0x9cdb60
bool u6_fn9d3f40(int *values, unsigned int count);	// NOTE: placeholder name
bool u6_fn9daf80(int a, int b, int c);	// NOTE: placeholder name
bool u6_fn9db000(vector<int> &v, int value);	// NOTE: placeholder name
int u6_distance_40a3f0(const U6Point &a, const U6Point &b);	// NOTE: placeholder name
U6Record *u6_randomRec_9d5d00(vector<U6Record *> &v);	// NOTE: placeholder name
int u6_randomInt_9d5d00(vector<int> &v);	// NOTE: placeholder name (same function as u6_randomRec_9d5d00)

class Unknown_45f320_45f560	// NOTE: placeholder name (object at 0xcf6888); layout from team_d_04.cpp
{
public:
	void unknown6927e0();	// NOTE: placeholder name
	void unknown6998a0(unsigned int index, int amount, bool set);	// NOTE: placeholder name (OpS4_Tally::unknown6998a0)
	bool unknown6997f0(int type);	// NOTE: placeholder name (OpS4_A::unknown6997f0)
	void unknown699720(U6Record *record, int a);	// NOTE: placeholder name (OpS4_Unit::unknown699720)
	void unknown699960();	// NOTE: placeholder name (OpS4_Unit::unknown699960)
	void resetAI_699a00(bool flag);
	void unknown699e20();	// NOTE: placeholder name (OpS4_Unit::unknown699e20)
	void unknown699f30();	// NOTE: placeholder name (OpU4_Obj699f30::unknown699f30)
	void unknown69a0a0(bool flag);	// NOTE: placeholder name
	void unknown69a5b0(bool flag);	// NOTE: placeholder name
	bool unknown69ac10(const U6Point &loc, U6Point &range, bool flag);	// NOTE: placeholder name
	int unknown69b9b0(vector<string> &texts, vector<int> &used);	// NOTE: placeholder name (OpS4_Unit::unknown69b9b0)	// NOTE: placeholder name (LB1RUnit::resetAI_699a00)

	vector<int>				unknown000;
	vector<int>				unknown010;
	struct U6Owned			*unknown020;
	U6Timer					unknown024;
	U6Record				*unknown02c;
	U6HEntity				unknown030;
	struct U6Stored			*unknown034;
	U6Timer					unknown038;
	int						unknown040;
	vector<int>				unknown044;
	vector<int>				unknown054;
	int						unknown064;
	U6Plan					*unknown068;
	int						unknown06c;
	vector<int>				unknown070;
	U6Timer					unknown080;
	vector<U6HEntity>		unknown088;
	vector<U6Point>			unknown098;
	vector<U6Timer>			unknown0a8;
	vector<U6HEntity>		unknown0b8;
	int						unknown0c8;
	int						unknown0cc;
	unsigned int			unknown0d0;
	U6Timer					unknown0d4;
	vector<U6HEntity>		unknown0dc;
	U6Timer					unknown0ec;
	U6Timer					unknown0f4;
	U6HEntity				unknown0fc;
	string					unknown100;
	int						unknown11c;
	U6HEntity				unknown120;
	vector<int>				unknown124;
	U6Timer					unknown134;
	U6Point					unknown13c;
	U6Point					unknown144;
	int						unknown14c;
	int						unknown150;
	vector<U6HEntity>		unknown154;
	vector<U6Point>			unknown164;
	vector<int>				unknown174;
	int						unknown184;
	U6Point					unknown188;
	int						unknown190;
	bool					unknown194;
	int						unknown198;
	bool					unknown19c;
	U6HLoc					unknown1a0;
	int						unknown1a4;
	int						unknown1a8;
	bool					unknown1ac;
	int						unknown1b0;
	U6Timer					unknown1b4;
	U6Timer					unknown1bc;
	char					pad1c4[0x230 - 0x1c4];
	int						unknown230;
	vector<int>				unknown234;
	vector<int>				unknown244;
	vector<U6HEntity>		unknown254;
	vector<U6HEntity>		unknown264;
	vector<U6HEntity>		unknown274;
};

extern Unknown_45f320_45f560 u6_unk_cf6888;	// NOTE: placeholder name (this object)

struct U6Stored { ~U6Stored(); };	// NOTE: placeholder layout (StoredEntity; scalar deleting destructor 0x45f860)

struct U6Owned	// NOTE: placeholder layout (0x45f830)
{
	vector<int>				unknown00;
	vector<vector<unsigned int> > unknown10;
};

void Unknown_45f320_45f560::unknown6927e0()
{
	if (u6_mapTypes00_ba44f0[u6_location_d1e888->type].value && u6_world_cefc4c->unknown4642d0() && u6_world_cefc4c->unknown4642d0() % u6_mapTypes00_ba44f0[u6_location_d1e888->type].value == 0 && unknown010[0] < u6_mapTypes08_ba44f8[u6_location_d1e888->type].value)
	{
		int count = u6_minInt(u6_mapTypes04_ba44f4[u6_location_d1e888->type].value,u6_mapTypes08_ba44f8[u6_location_d1e888->type].value - unknown010[0]);
		unknown6998a0(0,count,false);
	}
	if (unknown024.a == 0 && unknown02c == NULL && !u6_xomEnabled_d25450 && u6_world_cefc4c->unknown4642d0() % 24 == 0 && u6_fn9d3f40(u6_ba4ca8[u6_location_d1e888->type],5))
	{
		for (int i = 0; i < 16; i++)
		{
			if (unknown000[i] >= u6_ba4430[i][u6_difficulty_cf4718] && i != 3)
			{
				unknown024.randomize(u6_location_d1e888->type == 5 ? u6_d22580 : u6_cfe12c);
				do {} while (0);
				do {} while (0);
				unknown6998a0(i,0,true);
				switch (i)
				{
				case 4:
					unknown6998a0(3,0,true);
					unknown6998a0(9,0,true);
					if (unknown198 == 0)
					{
						unknown198 = -2;
						do {} while (0);
					}
					else if (unknown198 >= 1 && unknown198 < 6)
					{
						unknown198 = -1;
						do {} while (0);
					}
					break;
				case 9:
					unknown6998a0(4,0,true);
				case 11:
					unknown6998a0(6,0,true);
				}
				if (unknown020)
					unknown020->unknown10.back().push_back(i);
				break;
			}
		}
	}
	else if (unknown024.hasExpired())
	{
		if (unknown6997f0(unknown02c ? unknown02c->unknown110 : 10))
		{
			unknown024.set(-1,-1);
			do {} while (0);
		}
		else if (unknown02c && (++unknown040, unknown040 > u6_ba50b8[unknown02c->unknown110]))
		{
			unknown054[unknown02c->unknown110] = 1;
			unknown024.reset();
			unknown02c = NULL;
			unknown038.reset();
			unknown040 = 0;
			do {} while (0);
		}
		else if (!u6_cefb2a && u6_world_cefc4c->getPlayer()->unknown5c98c0(0,0x42,0))
		{
			unknown024.randomize(u6_d31b58);
			do {} while (0);
			if (unknown02c)
				unknown040--;
		}
		else
		{
			if (unknown02c == NULL)
			{
				U6WL list;
				for (int j = 0; j < 10; j++)
				{
					if (unknown044[j] && !unknown054[j] && u6_ba4ca8[u6_location_d1e888->type][u6_ba4fc8[j]] == 3 && u6_ba4fa0[j])
						list.add(j,u6_ba4fa0[j]);
				}
				if (!(u6_caf2a4 == 10 && u6_caf2a8 == 10))
				{
					int forced = u6_caf2a4 != 10 ? u6_caf2a4 : u6_caf2a8;
					list.reset();
					list.add(forced,1);
					u6_caf2a8 = 10;
				}
				if (!list.empty())
				{
					int type = list.pick();
					if (type != 9)
					{
						for (unsigned int k = 0; k < u6_records_d25de0.size(); k++)
						{
							if (u6_records_d25de0[k]->unknown110 == type)
							{
								unknown699720(u6_records_d25de0[k],1);
								break;
							}
						}
					}
					else
					{
						string text("ALERT: Unchained X0-1V1 authori--X0-1V1 DOES NOT COME FOR YOU, YOU ENTERTAIN XOM.");
						U6_ALERT(1,0x12a,text);
						if (u6_gameData_d1e860.isFlagEnabledA() && u6_fn9db000(unknown070,unknown02c->unknown110))
							u6_xomTurn_d25454 = u6_world_cefc4c->getTurn();
						u6_xom_d25450.unknown69e450();
						unknown024.reset();
						goto announced;
					}
				}
				else
				{
					unknown024.set(-1,-1);
					do {} while (0);
				}
			}
			if (unknown02c)
			{
				unknown038.randomize(u6_cf0fb8[unknown02c->unknown110]);
				do {} while (0);
				do {} while (0);
				if (u6_fn9daf80(0xf,u6_location_d1e888->type,0x12))
				{
					string text("PUBLIC SERVICE ANNOUNCEMENT: Unchained detected in the area, stay safe out there!");
					U6_ALERT(1,-1,text);
				}
				else
				{
					string text = "ALERT: Unchained \"" + unknown02c->name + "\" authorized to operate in " + u6_location_d1e888->getText() + ", avoid or assist as necessary.";
					U6_ALERT(1,0x12a,text);
					if (u6_speaker_cefb48)
						u6_speaker_cefb48->say(0x31,0,"");
					if (u6_gameData_d1e860.isFlagEnabledA() && u6_fn9db000(unknown070,unknown02c->unknown110))
						unknown06c = u6_world_cefc4c->getTurn();
				}
announced:
				u6_stats_d2c658.add4729d0(0x239,1,"",-1);
				if (u6_stats_d2c658.unknown472c70(0x239) == 1)
					u6_playerData_cf45d8.unknown77fbc0(0xa5);
				do { u6_logPhrase_5141b0(0x79,&unknown02c->name,0,0,U6HEntity(),0); } while (0);
				unknown024.reset();
			}
		}
	}
	else if (unknown038.hasExpired())
	{
		unknown038.reset();
		if (unknown6997f0(unknown02c->unknown110))
		{
			unknown024.set(-1,-1);
			do {} while (0);
		}
		else
		{
			switch (unknown02c->unknown110)
			{
			}
			U6Point pos;
			U6Point *entry = NULL;
			int range = 0;
			switch (unknown02c->unknown110)
			{
			case 5:
				range = u6_maxInt(u6_cells_cfd44c.getWidth(),u6_cells_cfd44c.getHeight()) / 3;
				break;
			case 8:
				range = u6_maxInt(u6_cells_cfd44c.getWidth(),u6_cells_cfd44c.getHeight()) / 3;
				break;
			}
			if (!u6_overmind_cf6428.unknown683500(&pos,false,range,true,U6Point(-1),&entry,false,false))
			{
				bool found = false;
				for (int n = 0; n < 200; n++)
				{
					u6_cells_cfd44c.getRandom_9cf0c0(pos);
					if (u6_world_cefc4c->findPlaceableNear(pos,pos,1) && u6_distance_40a3f0(pos,u6_world_cefc4c->getPlayer()->getPosition()) >= 40)
					{
						vector<U6Point> path;
						if (u6_carto_cfe568.findPath(pos,u6_world_cefc4c->unknown4184d0(),u6_moveCost_cefc30,0,path))
						{
							found = true;
							break;
						}
					}
				}
				if (!found)
				{
					logError("UC","path fail");
					pos.x = -1;
				}
			}
			if (pos.x != -1)
			{
				unknown030 = u6_world_cefc4c->placeEntity(unknown02c,pos,0xb,false,0x22,0xe,false);
				unknown030->getAI()->chase(u6_world_cefc4c->getPlayer(),-2,1,0,0);
			}
			switch (unknown02c->unknown110)
			{
			case 0:
			{
				unknown030->setAI(new U6AI(unknown030,0x1c,4));
				unknown030->getAI()->chase(u6_world_cefc4c->getPlayer(),-2,1,0,0);
				U6Point spot;
				if (unknown030->getAI()->unknown5b66c0(spot) && u6_overmind_cf6428.unknown683500(&pos,false,0,true,spot,&entry,false,false))
					unknown030->changePos(pos,1);
				unknown080.randomize(u6_d223d4);
				break;
			}
			case 1:
				unknown699960();
				unknown0d4.randomize(u6_cf7658);
				unknown0ec.reset();
				break;
			case 2:
				u6_world_cefc4c->giveItem("CL-0N3 Data Core",unknown030,0,0);
				unknown699960();
				unknown0f4.randomize(u6_cf6ec4);
				break;
			case 3:
				unknown699960();
				unknown134.randomize(u6_d1ed48);
				unknown13c.fill(-1);
				break;
			case 5:
			{
				unknown030->setAI(new U6AI(unknown030,0x1d,4));
				unknown030->getAI()->chase(u6_world_cefc4c->getPlayer(),-2,1,0,0);
				U6Point spot;
				if (unknown030->getAI()->findPatrolSpot(spot) && u6_overmind_cf6428.unknown683500(&pos,false,0,true,spot,&entry,false,false))
					unknown030->changePos(pos,1);
				break;
			}
			case 6:
			{
				U6Record *rec = u6_randomRec_9d5d00(u6_vec_cf7574);
				for (int m = unknown030->unknown5c92e0(3); m > 0; m--)
					u6_world_cefc4c->unknown6c51d0(rec,unknown030,true,false);
				if (!rec->unknown13c.empty())
					unknown030->getAI()->unknown44bef0(0xb);
				break;
			}
			break;
			case 8:
			{
				unknown030->unknown639530(0x39,1);
				u6_vec_cf6adc.push_back(unknown030);
				unknown030->setAI(new U6AI(unknown030,0x1f,4));
				unknown030->getAI()->unknown44cea0(0xc);
				U6Area area;
				do
				{
					area.a = u6_cells_cfd44c.getRandom_9cf050();
				} while (!(*u6_cells_cfd44c.atPoint(area.a))->unknown4550b0());
				u6_cells_cfd44c.getRect(area.a,20,&area);
				unknown030->getAI()->unknown459410(area);
				vector<int> types;
				types.push_back(0x10);
				types.push_back(0x18);
				types.push_back(0x19);
				for (int k = 0; k < 2; k++)
				{
					U6HEntity escort = u6_world_cefc4c->placeEntity(u6_world_cefc4c->unknown6c5600(1,u6_randomInt_9d5d00(types),1,1),unknown030->getPosition(),0xb,false,3,0xe,false);
					if (escort.isValid())
					{
						escort->loadout63c770(true);
						escort->getAI()->setFollowEntity(unknown030,0);
						escort->unknown639530(0x39,1);
						escort->unknown63c660();
						escort->getAI()->unknown44cea0(0xc);
						escort->getAI()->unknown451930(0x32);
						u6_vec_cf6adc.push_back(escort);
						u6_vec_cf6aec.push_back(escort);
					}
				}
				break;
			}
			}
		}
	}
	if (unknown1b0 && unknown1b0 == u6_world_cefc4c->getTurn())
	{
		unknown1b0 = 0;
		if (u6_gameData_d1e860.isFlagEnabledA() && unknown19c)
		{
			string text = "FARCOM_MSG: " + u6_d22674;
			U6_ALERT(1,-1,text);
		}
	}
	if (unknown02c)
	{
		if (unknown06c && u6_gameData_d1e860.isFlagEnabledA())
		{
			if (unknown070.size() == 1)
			{
				switch (u6_world_cefc4c->getTurn() - unknown06c)
				{
				case 10:
					U6_ALERT(1,-1,string("FARCOM_MSG: We kinda like the data you're collecting and don't want to witness your untimely demise, so we kindly advise you to run like hell."));
					break;
				case 40:
flee:
				{
					U6Access *exit = u6_world_cefc4c->unknown7143e0(0);
					if (exit && !u6_world_cefc4c->unknown463160(exit))
					{
						if (unknown070.size() == 1)
							U6_ALERT(1,-1,string("FARCOM_MSG: I've located an exit near your position you could probably use to shake them for a while."));
						else
							U6_ALERT(1,-1,string("FARCOM_MSG: Flee option, unlocked!"));
						exit->loc->unknown25 = true;
						u6_world_cefc4c->announceMachine(exit->loc);
						u6_world_cefc4c->unknown4647a0(exit,1);
						exit->unknown0d = true;
						u6_cmap_cec054->labelAccess80e3a0(1,exit);
						exit->unknown6c16d0("LOCATED");
						do { u6_logPhrase_5141b0(0x131,&exit->loc->getText(),0,0,U6HEntity(),0); } while (0);
					}
					break;
				}
				case 50:
				{
					string text = "FARCOM_MSG: EX-HEX means well, but I for one want to see you stick around and beat the bolts out of " + unknown02c->name + ".";
					U6_ALERT(1,-1,text);
					break;
				}
				case 51:
				{
					string text = "FARCOM_MSG: " + u6_names_d225b0[unknown02c->unknown110];
					U6_ALERT(1,-1,text);
					unknown06c = 0;
					break;
				}
				}
			}
			else
			{
				switch (u6_world_cefc4c->getTurn() - unknown06c)
				{
				case 1:
				{
					string text = "FARCOM_MSG: " + u6_names_d225b0[unknown02c->unknown110];
					U6_ALERT(1,-1,text);
					break;
				}
				case 40:
					unknown06c = 0;
					goto flee;
				}
			}
		}
		switch (unknown02c->unknown110)
		{
		case 0:
			if (unknown030.operator->())
			{
				bool shielded = unknown030->unknown5d26e0(0xab);
				if (!shielded && unknown030->getAI()->getBehavior() != 0x17)
					resetAI_699a00(true);
				if (unknown0c8 == 0 || u6_world_cefc4c->getTurn() >= unknown0c8)
				{
					U6Area area;
					u6_cells_cfd44c.getRect(unknown030->getPosition(),15,&area);
					for (int i = 0; i < unknown0b8.size(); i++)
					{
						if (!unknown0b8[i].operator->())
							u6_eraseStep_9d6440(unknown0b8,i);
						else if (u6_distance_40a3f0(unknown030->getPosition(),unknown0b8[i]->getPosition()) > 20)
							unknown0b8[i]->getAI()->unknown459410(area);
					}
					if (unknown0b8.size() < 5 && shielded)
					{
						U6HEntity drone = u6_world_cefc4c->placeEntity(u6_wl_d2601c.pick(),unknown030->getPosition(),0xb,false,0x22,0xe,false);
						if (drone.isValid())
						{
							unknown0b8.push_back(drone);
							drone->getAI()->unknown459470(area);
							drone->unknown45b2a0();
							if (u6_world_cefc4c->unknown4631f0(unknown030))
							{
								string text = unknown030->getName() + " launches drone.";
								u6_message_49c610(0x320,U6HEntity(),text,0);
								u6_sound_454260(unknown030->getPosition(),0xbf);
							}
							do {} while (0);
						}
					}
					unknown0c8 = u6_world_cefc4c->getTurn() + u6_range_d01d50.randomInRange();
				}
				if (unknown030->getAI()->getBehavior() != 0x17)
				{
					for (int i = 0; i < unknown088.size(); i++)
					{
						if (!unknown088[i].operator->() || unknown088[i]->unknown5d1280(0))
						{
							u6_eraseAt_9da940(unknown088,i);
							u6_eraseAt_9d5190(unknown098,i);
							u6_eraseStep_9e2670(unknown0a8,i);
							do {} while (0);
						}
					}
					if (unknown080.hasExpired())
					{
						if (unknown088.size() >= 8)
						{
							vector<U6HEntity> followers;
							unknown088[0]->getAI()->getFollowers580a90(followers,0xf);
							followers.push_back(unknown088[0]);
							for (unsigned int j = 0; j < followers.size(); j++)
							{
								if (u6_world_cefc4c->unknown4631f0(followers[j]))
								{
									string text = followers[j]->getName() + " disintegrates.";
									u6_message_49c610(0x320,U6HEntity(),text,0);
									u6_sound_454260(followers[j]->getPosition(),0xc0);
								}
								followers[j]->unknown637bb0();
							}
							u6_eraseAt_9da940(unknown088,0);
							u6_eraseAt_9d5190(unknown098,0);
							u6_eraseAt_9dae00(unknown0a8,0);
							do {} while (0);
						}
						if (shielded)
						{
							vector<U6Record *> recs;
							for (int n = u6_range_d32384.randomInRange(); n > 0; n--)
								recs.push_back(u6_wl_d2601c.pick());
							if (rng.chance(20))
							{
								U6Record *stasis;
								if (u6_findByName_9d7530(u6_records_d25de0,"Stasis Drone",stasis))
									recs.push_back(stasis);
							}
							bool placed = false;
							U6Point origin;
							for (int t = 0; t < 50; t++)
							{
								u6_cells_cfd44c.getRandom_9cf0c0(origin);
								if (u6_world_cefc4c->findPlaceableNear(origin,origin,1))
								{
									placed = true;
									break;
								}
							}
							if (placed)
							{
								U6Area area;
								u6_cells_cfd44c.getRect(origin,15,&area);
								U6Point pos;
								vector<U6HEntity> squad;
								for (unsigned int q = 0; q < recs.size(); q++)
								{
									if (u6_world_cefc4c->findPlaceableNear(unknown030->getPosition(),pos,1))
									{
										U6HEntity drone = u6_world_cefc4c->placeEntity(recs[q],pos,0xb,false,0x22,0xe,false);
										if (drone.isValid())
										{
											squad.push_back(drone);
											drone->getAI()->unknown459470(area);
											drone->unknown45b2a0();
											if (q == 0)
											{
												unknown088.push_back(drone);
												unknown098.push_back(origin);
												U6Timer timer;
												timer.randomize(u6_cfc194);
												unknown0a8.push_back(timer);
											}
											else
												drone->getAI()->setFollowEntity(unknown088.back(),0);
										}
									}
								}
								if (!squad.empty())
								{
									if (u6_world_cefc4c->unknown4631f0(unknown030))
									{
										string text = unknown030->getName() + " launches drone squad.";
										u6_message_49c610(0x320,U6HEntity(),text,0);
										u6_sound_454260(unknown030->getPosition(),0xbf);
										if (u6_unk_cf6888.unknown02c && unknown030.operator->() && u6_unk_cf6888.unknown030 == unknown030)
											u6_unk_cf6888.unknown068->unknown672f20(unknown030,6,false,"");
									}
									do {} while (0);
								}
								unknown080.randomize(u6_d223d4);
							}
						}
					}
					for (unsigned int w = 0; w < unknown088.size(); w++)
					{
						if (unknown0a8[w].hasExpired())
						{
							vector<U6HEntity> members;
							unknown088[w]->getAI()->getFollowers580a90(members,0xf);
							members.push_back(unknown088[w]);
							unknown098[w] = u6_world_cefc4c->getPlayer()->getPosition();
							U6Area zone;
							u6_cells_cfd44c.getRect(unknown098[w],15,&zone);
							for (unsigned int z = 0; z < members.size(); z++)
								members[z]->getAI()->unknown459410(zone);
							unknown0a8[w].reset();
							do {} while (0);
						}
					}
				}
			}
			break;
		case 1:
			for (int i = 0; i < unknown0dc.size(); i++)
			{
				if (!unknown0dc[i].operator->())
					u6_eraseStep_9d6440(unknown0dc,i);
			}
			if (unknown030.operator->())
			{
				unknown699e20();
				if (unknown0ec.hasExpired())
				{
					U6Area area;
					u6_cells_cfd44c.getRect(u6_world_cefc4c->getPlayer()->getPosition(),50,&area);
					for (unsigned int j = 0; j < unknown0dc.size(); j++)
						unknown0dc[j]->getAI()->unknown459470(area);
					unknown0ec.randomize(u6_d35b38);
				}
			}
			else if (unknown0d4.a)
			{
				bool found = false;
				for (unsigned int k = 0; k < unknown0dc.size(); k++)
				{
					if (unknown0dc[k]->getAI()->anySmallGroup())
					{
						found = true;
						break;
					}
					vector<U6HEntity> followers;
					unknown0dc[k]->getAI()->getFollowers580a90(followers,0xf);
					for (unsigned int m = 0; m < followers.size(); m++)
					{
						if (followers[m]->getAI()->anySmallGroup())
						{
							found = true;
							break;
						}
					}
				}
				if (found)
				{
					U6Point nearest(-1);
					U6Point from = u6_world_cefc4c->getPlayer()->getPosition();
					vector<U6Point *> doors;
					u6_world_cefc4c->unknown7142a0(doors);
					u6_shuffle_9d8f80(doors);
					int len;
					for (unsigned int e = 0; e < doors.size(); e++)
					{
						if (u6_world_cefc4c->unknown716940(from,*doors[e],0,&len) && len <= 25)
						{
							nearest = *doors[e];
							break;
						}
					}
					U6Point point(-1);
					if (nearest.x == -1)
					{
						U6Area area;
						u6_cells_cfd44c.getRect(from,0x23,&area);
						for (int t = 0; t < 100; t++)
						{
							U6Point p = area.randomPoint();
							if (!u6_world_cefc4c->isVisible(p) && u6_distance_40a3f0(p,from) > 20 && u6_world_cefc4c->findPlaceableNear(p,p,unknown02c->unknown9c) && u6_world_cefc4c->unknown716940(from,p,0,&len) && len <= 40)
							{
								if (!u6_world_cefc4c->unknown463160(p))
								{
									nearest = p;
									break;
								}
								else if (point.x == -1)
									point = p;
							}
						}
					}
					if (nearest.x == -1 && point.x != -1)
						nearest = point;
					if (nearest.x == -1)
					{
						U6Point *access = NULL;
						u6_overmind_cf6428.unknown683500(&nearest,true,0,true,U6Point(-1),&access,false,false);
					}
					if (nearest.x != -1 && u6_world_cefc4c->findPlaceableNear(nearest,nearest,unknown02c->unknown9c))
					{
						if (unknown034 == NULL)
							do {} while (0);
						unknown030 = u6_restoreEntity_690940(unknown034,nearest,0xb,0x22,0xe);
						delete unknown034;
						unknown034 = NULL;
						unknown030->getAI()->chase(u6_world_cefc4c->getPlayer(),-2,1,0,0);
					}
					U6Area area;
					u6_cells_cfd44c.getRect(u6_world_cefc4c->getPlayer()->getPosition(),50,&area);
					for (unsigned int v = 0; v < unknown0dc.size(); v++)
					{
						unknown0dc[v]->getAI()->chase(u6_world_cefc4c->getPlayer(),1,0,0,0);
						unknown0dc[v]->getAI()->unknown459470(area);
					}
					unknown0ec.randomize(u6_d35b38);
				}
			}
			if ((!unknown030.operator->() || unknown030->getAI()->getBehavior() != 0x17) && unknown0d4.hasExpired())
			{
				unknown0d4.randomize(u6_cf7658);
				if (unknown0dc.size() < unknown0d0)
				{
					U6Record *trooper;
					if (u6_findByName_9d7530(u6_records_d25de0,"Stormtrooper",trooper))
					{
						for (int s = 0; s < 2 && unknown0dc.size() < unknown0d0; s++)
						{
							U6Point spot(-1);
							U6Point *access = NULL;
							if (!u6_overmind_cf6428.unknown683500(&spot,true,0,true,U6Point(-1),&access,false,false) && !u6_world_cefc4c->isVisible(u6_world_cefc4c->unknown4184d0()))
								spot = u6_world_cefc4c->unknown4184d0();
							if (spot.x != -1)
							{
								U6HEntity leader;
								for (int u = 0; u < 2; u++)
								{
									U6HEntity soldier = u6_world_cefc4c->placeEntity(trooper,spot,0xb,false,0x22,0xe,false);
									if (soldier.isValid())
									{
										soldier->setName("TK-" + intToString(rng.rangeInt(0,9)) + intToString(rng.rangeInt(0,9)) + intToString(rng.rangeInt(0,9)) + intToString(rng.rangeInt(0,9)));
										soldier->getAI()->unknown459410(u6_cells_cfd44c.getArea());
										soldier->getAI()->unknown451930(rng.rangeInt(0,75));
										if (leader.isValid())
											soldier->getAI()->setFollowEntity(leader,0);
										else
										{
											leader = soldier;
											unknown0dc.push_back(soldier);
											if (unknown0dc.size() == 1 || unknown0dc.size() == unknown0d0 - 4)
												u6_world_cefc4c->unknown6c65a0(soldier,"Stormtrooper_Talk",0);
										}
									}
								}
							}
						}
					}
				}
			}
			break;
		case 2:
			if (unknown030.operator->())
			{
			}
			else if (unknown034)
			{
				if (unknown0fc.isValid())
				{
					if (!unknown0fc.operator->())
						logFatal("CLONE","invalid host: " + (unknown100.empty() ? string("UNKNOWN") : unknown100));
					bool attack = false;
					if (u6_caf21c[unknown0fc->getTarget()])
						attack = true;
					else if (unknown0fc->unknown45aaa0(u6_world_cefc4c->getPlayer()))
					{
						if (rng.chance(3))
							attack = true;
					}
					else if (unknown0fc->getAI()->unknown9b4350() < 6)
					{
						if (rng.chance(0x21) && u6_distance_40a3f0(unknown0fc->getPosition(),u6_world_cefc4c->getPlayer()->getPosition()) <= 12 && u6_world_cefc4c->isReachable(0x22,unknown0fc->getPosition(),u6_world_cefc4c->getPlayer()->getPosition()))
							attack = true;
						else
							unknown699f30();
					}
					else
					{
						if (u6_world_cefc4c->unknown463400(unknown0fc) && rng.chance(8) && unknown0fc->getAI()->unknown458fb0(u6_world_cefc4c->getPlayer()))
							attack = true;
						else
							unknown699f30();
					}
					if (attack)
						unknown69a0a0(false);
					else if (u6_distance_40a3f0(u6_world_cefc4c->getPlayer()->getPosition(),unknown0fc->getPosition()) > 60)
					{
						do {} while (0);
						unknown0fc.reset();
						unknown0f4.set(1,1);
					}
				}
				else if (unknown120.isValid())
				{
					if (!unknown120.operator->())
						logFatal("CLONE","invalid combat form");
					if (!u6_world_cefc4c->unknown4631f0(unknown120) && u6_distance_40a3f0(u6_world_cefc4c->getPlayer()->getPosition(),unknown120->getPosition()) > 60 && !unknown120->unknown5d1280(1))
					{
						do {} while (0);
						unknown0f4.randomize(u6_d305c8);
						unknown120->unknown637bb0();
						unknown120.reset();
						unknown11c = u6_caf160;
					}
					else if (unknown120->unknown5d1280(1) || unknown120->unknown5d5250())
						unknown69a5b0(false);
				}
				else if (unknown0f4.hasExpired() && u6_world_cefc4c->getTurn() % 3 == 0)
				{
					U6Point center = u6_world_cefc4c->getPlayer()->getPosition();
					U6Area area;
					u6_cells_cfd44c.getRect(center,20,&area);
					vector<U6HEntity> selected;
					for (int x = area.a.x; x <= area.b.x; x++)
					{
						for (int y = area.a.y; y <= area.b.y; y++)
						{
							if (u6_distance_406480(center.x,center.y,x,y) <= 20 && (*u6_cells_cfd44c.at(x,y))->getEntity().isValid() && (*u6_cells_cfd44c.at(x,y))->getEntity()->getRecord()->unknown114 && !(*u6_cells_cfd44c.at(x,y))->getEntity()->getTarget() && (*u6_cells_cfd44c.at(x,y))->getEntity()->getGroup()->unknown9b4350() > 1 && (*u6_cells_cfd44c.at(x,y))->getEntity()->getSize() == 1)
								u6_addUniqueEntity_9d30e0(selected,(*u6_cells_cfd44c.at(x,y))->getEntity());
						}
					}
					if (!selected.empty())
					{
						u6_shuffle_9d9fc0(selected);
						int length;
						if (rng.chance(50))
						{
							for (unsigned int c = 0; c < selected.size(); c++)
							{
								if (selected[c]->getAI()->unknown9b4350() < 6 && u6_world_cefc4c->unknown716940(selected[c]->getPosition(),u6_world_cefc4c->getPlayer()->getPosition(),selected[c].operator->(),&length) && length <= 40)
								{
									unknown0fc = selected[c];
									unknown100 = reinterpret_cast<Entity *>(unknown0fc.operator->())->getName();
									do {} while (0);
									break;
								}
							}
						}
						if (unknown0fc.isNull())
						{
							for (unsigned int c = 0; c < selected.size(); c++)
							{
								if (u6_world_cefc4c->unknown716940(selected[c]->getPosition(),u6_world_cefc4c->getPlayer()->getPosition(),selected[c].operator->(),&length) && length <= 40)
								{
									if (rng.chance(0x21) && !u6_world_cefc4c->unknown714920(selected[c]->getPosition(),selected[c]))
									{
										U6Point spot;
										if (u6_world_cefc4c->findPlaceableNear(selected[c]->getPosition(),spot,1))
										{
											unknown0fc = u6_world_cefc4c->placeEntity(selected[c]->getRecord(),spot,selected[c]->getGroup()->unknown9b4350(),false,0x22,0xe,false);
											unknown0fc->getAI()->setFollowEntity(selected[c],0);
											unknown100 = reinterpret_cast<Entity *>(unknown0fc.operator->())->getName();
											do {} while (0);
										}
									}
									if (unknown0fc.isNull())
									{
										unknown0fc = selected[c];
										unknown100 = reinterpret_cast<Entity *>(unknown0fc.operator->())->getName();
										do {} while (0);
									}
									break;
								}
							}
						}
						if (unknown0fc.isValid())
						{
							unknown0fc->unknown45b2a0();
							unknown0fc->unknown639530(0x33,1);
							int rank = u6_gameData_d1e860.unknown46f4e0();
							vector<U6Record *> options;
again:
							for (unsigned int r = 0; r < u6_records_d25de0.size(); r++)
							{
								if (u6_records_d25de0[r]->ranks.contains(rank) && !u6_containsRecord_9db330(unknown124,u6_records_d25de0[r]->unknown000))
									options.push_back(u6_records_d25de0[r]);
							}
							if (options.empty() && !unknown124.empty())
							{
								unknown124.clear();
								goto again;
							}
							unknown11c = u6_randomRec_9d5d00(options)->unknown000;
						}
					}
				}
			}
			break;
		case 3:
			if (unknown030.operator->())
			{
				if (!u6_world_cefc4c->unknown4631f0(unknown030) && u6_distance_40a3f0(u6_world_cefc4c->getPlayer()->getPosition(),unknown030->getPosition()) > 40 && !unknown030->unknown5d1280(0))
				{
					do {} while (0);
					if (unknown030->getAI()->getBehavior() == 0x17)
					{
						unknown030->unknown637bb0();
						unknown030.reset();
						unknown038.set(1,1);
						unknown134.randomize(u6_cf1f90);
					}
					else
					{
						unknown134.randomize(u6_d20444);
						unknown13c.fill(-1);
						unknown699960();
					}
				}
				else
				{
					unknown699e20();
					if (unknown030->getAI()->getBehavior() != 0x17)
					{
						if (!u6_world_cefc4c->unknown716940(unknown030->getPosition(),u6_world_cefc4c->getPlayer()->getPosition(),unknown030.operator->(),0) && !u6_world_cefc4c->unknown716e50(unknown030->getPosition()))
							unknown14c++;
						if (unknown14c >= 6)
						{
							vector<U6Point> adjacent;
							u6_sweepGetSurroundingCells(unknown030->getPosition(),adjacent);
							for (unsigned int a = 0; a < adjacent.size(); a++)
							{
								if ((*u6_cells_cfd44c.atPoint(adjacent[a]))->unknown66a630())
								{
									do {} while (0);
									if (u6_unk_cf6888.unknown02c && unknown030.operator->() && u6_unk_cf6888.unknown030 == unknown030)
										u6_unk_cf6888.unknown068->unknown672f20(unknown030,0xc,false,"");
									unknown134.randomize(u6_d396f4);
									unknown13c.fill(-1);
									unknown699960();
									break;
								}
							}
						}
					}
				}
			}
			else if (unknown034 && unknown134.hasExpired())
			{
				if (unknown13c.x != -1)
					goto trigger;
				else
				{
					if (unknown144.x != -1 && u6_distance_40a3f0(u6_world_cefc4c->getPlayer()->getPosition(),unknown144) < 30)
					{
						do {} while (0);
						unknown134.randomize(u6_d396f4);
					}
					else
					{
					{
						vector<U6Point> nearSpots;
						vector<U6Point> points;
						U6Point origin = u6_world_cefc4c->getPlayer()->getPosition();
						U6Area area;
						u6_cells_cfd44c.getRect(origin,16,&area);
						for (int x = area.a.x; x <= area.b.x; x++)
						{
							for (int y = area.a.y; y <= area.b.y; y++)
							{
								if ((*u6_cells_cfd44c.at(x,y))->getTerrain() == TERRAIN_CAVE_WALL && u6_world_cefc4c->unknown463380(x,y))
								{
									int distance = u6_distance_406480(origin.x,origin.y,x,y);
									if (distance <= 8)
										nearSpots.push_back(U6Point(x,y));
									else if (distance <= 16)
										points.push_back(U6Point(x,y));
								}
							}
						}
						if (!nearSpots.empty())
							unknown13c = u6_randomPoint_9d5350(nearSpots);
						else if (!points.empty())
							unknown13c = u6_randomPoint_9d5350(points);
						else
						{
							do {} while (0);
							unknown134.randomize(u6_d396f4);
						}
					}
					if (unknown13c.x != -1)
					{
						u6_cmap_cec054->unknown49adc0(1000);
						if (u6_world_cefc4c->getPlayer()->unknown5d2380(0x18).isValid())
						{
							u6_message_49c610(0x320,U6HEntity(),string("Structural anomaly detected."),0);
							unknown134.randomize(u6_cf34f8);
						}
						else
						{
trigger:
							(*u6_cells_cfd44c.atPoint(unknown13c))->trigger(0,1,U6HEntity());
						}
					}
					}
				}
			}
			break;
		case 4:
			if (unknown030.operator->())
			{
				unknown699e20();
				if (unknown030->getAI()->getBehavior() != 0x17 && !unknown030->unknown5c8db0() && unknown030->unknown5d5250())
				{
					do {} while (0);
					if (u6_unk_cf6888.unknown02c && unknown030.operator->() && u6_unk_cf6888.unknown030 == unknown030)
						u6_unk_cf6888.unknown068->unknown672f20(unknown030,0xd,false,"");
					unknown030->setAI(new U6AI(unknown030,0x17,4));
					unknown030->getAI()->chase(u6_world_cefc4c->getPlayer(),-2,1,0,0);
				}
			}
			break;
		case 5:
			if (unknown030.operator->() && unknown030->getAI()->getBehavior() != 0x17)
			{
				if (unknown150 == 0)
				{
					U6Area area(unknown030->getAI()->getArea4b5730());
					vector<U6Point> &list = (*u6_world_cefc4c->unknown459070())[5];
					U6Point start(0);
					for (unsigned int i = 0; i < list.size(); i++)
					{
						if (area.contains(list[i]))
						{
							start = list[i];
							break;
						}
					}
					do {} while (0);
					u6_clearDijkstraResults();
					u6_carto_cfe568.unknown40ca20(start,9999,&u6_cf0c68,0);
					if (!u6_dijkstra_d15e58.empty())
					{
						for (int r = 0; r < 5; r++)
						{
							int begin = -1;
							int last = -1;
							for (unsigned int k = 0; k < u6_vec_d20b5c.size(); k++)
							{
								if (begin == -1)
								{
									if (u6_vec_d20b5c[k] == u6_ba5174[r])
										begin = k;
								}
								else if (u6_vec_d20b5c[k] != u6_ba5174[r])
								{
									last = k - 1;
									break;
								}
							}
							if (last == -1)
								last = u6_vec_d20b5c.size() - 1;
							if (begin == -1)
							{
							}
							else
							{
								for (int c = 0; c < u6_ba53a4[r]; c++)
								{
									for (int attempt = 0; attempt < 50; attempt++)
									{
										U6Point p = u6_dijkstra_d15e58[rng.rangeInt(begin,last)];
										if ((*u6_cells_cfd44c.atPoint(p))->canPlaceEntity(1))
										{
											int count = 0;
											bool changed = u6_ba5854[r] < 3;
											U6Area center;
											u6_cells_cfd44c.getRect(p,u6_ba59d4[r],&center);
											U6Point q;
											for (int n = 0; n < u6_ba5854[r]; n++)
											{
												for (int m = 0; m < 15; m++)
												{
													p = center.randomPoint();
													if (u6_world_cefc4c->unknown74d420(p,q) && !u6_containsPoint_9d0ce0(unknown164,q))
													{
														U6Prop *rec = u6_wl_d29da4.pick();
														if (rec->name.find("Stasis",0) != string::npos || rec->name.find("Shield",0) != string::npos)
														{
															if (changed)
																continue;
															changed = true;
														}
														unknown164.push_back(q);
														unknown174.push_back(rec->id);
														count++;
														break;
													}
												}
											}
											do {} while (0);
											break;
										}
									}
								}
							}
						}
					}
					unknown150 = 1;
				}
				for (unsigned int i = 0; i < unknown154.size(); i++)
				{
					if (unknown154[i].operator->() && unknown154[i]->unknown5d1280(0))
					{
						do { if (u6_logEntity_5111e0(0x285,0,0,0,unknown154[i],U6HProp(),0,0)) u6_consoleA_cec058->unknown8758d0(true); u6_logMsgs_cec0b4->scrollToEnd(); } while (0);
						unknown154[i]->die(!u6_world_cefc4c->unknown4631f0(unknown154[i]),0xa,U6HEntity(),1,0,0,0,0);
					}
				}
				for (int s = 0; s < 4 && s < unknown164.size(); s++)
				{
					if (unknown154.size() <= s || !unknown154[s].operator->())
					{
						U6Point spot;
						U6Point *access = NULL;
						if (u6_overmind_cf6428.unknown683500(&spot,false,0,true,unknown164[s],&access,false,false))
						{
							U6HEntity drone = u6_world_cefc4c->unknown6c5dc0("Aperture Drone",spot,0xb,false,0x1e,4,false);
							drone->unknown45b2a0();
							if (unknown154.size() <= s)
								unknown154.push_back(drone);
							else
								unknown154[s] = drone;
						}
					}
				}
				if (u6_unk_cf6888.unknown02c && unknown030.operator->() && u6_unk_cf6888.unknown030 == unknown030)
					u6_unk_cf6888.unknown068->unknown672f20(unknown030,0xf,false,"");
			}
			break;
		case 6:
			if (unknown030.operator->())
			{
				unknown699e20();
				U6HEntity *target = unknown030->getAI()->pickTarget580ec0();
				if (target)
				{
					U6Point dest = (*target)->getPosition();
					U6Point jump(-1);
					bool flag = true;
					if (unknown184 > 0)
					{
						if (unknown184 >= 6 || rng.chance(u6_ba59e8[unknown184]))
							jump = u6_point_d216e8;
						unknown184 = -unknown184;
					}
					if (unknown030->getAI()->getBehavior() != 0x17 && jump.x == -1 && u6_distance_40a3f0(unknown030->getPosition(),dest) >= 30)
					{
						jump.fill(u6_d216ec);
						flag = false;
					}
					if (jump.x != -1)
						unknown69ac10(dest,jump,flag);
				}
			}
			break;
		case 7:
			if (unknown030.operator->())
			{
				if (unknown030->getAI()->anyHostileXom())
				{
					unknown1ac = true;
					unknown19c = false;
					u6_stats_d2c658.add472b90(0x1d,-999999);
					u6_playerData_cf45d8.unknown77fbc0(0x12e);
				}
				if (unknown030->getAI()->getBehavior() != 0x17 && (unknown1ac || unknown6997f0(10)))
					resetAI_699a00(true);
				unknown699e20();
				if (unknown1b4.hasExpired())
				{
					if (rng.chance(25))
					{
						vector<U6HEntity> *all = u6_world_cefc4c->unknown4644b0();
						vector<U6HEntity> hostiles;
						for (unsigned int i = 0; i < all->size(); i++)
						{
							if ((*all)[i].operator->() && (*all)[i]->getGroup()->unknown9b4350() == 3 && !(*all)[i]->getTarget())
								hostiles.push_back((*all)[i]);
						}
						if (!hostiles.empty())
						{
							vector<U6Point> path;
							if (u6_world_cefc4c->unknown7168e0(u6_world_cefc4c->getPlayer()->getPosition(),unknown030->getPosition(),unknown030.operator->(),path) && path.size() > 20)
							{
								U6Point mid = path[path.size() / 2 + rng.rangeInt(-7,7)];
								vector<int> distances;
								for (unsigned int h = 0; h < hostiles.size(); h++)
								{
									path.clear();
									if (u6_world_cefc4c->unknown7168e0(hostiles[h]->getPosition(),mid,hostiles[h].operator->(),path))
										distances.push_back(path.size());
									else
										distances.push_back(9999);
								}
								int best = u6_indexOfMinInt_9d9270(distances);
								if (distances[best] != 9999)
								{
									hostiles[best]->getAI()->unknown459540(mid);
									do {} while (0);
								}
							}
						}
					}
					unknown1b4.randomize(u6_d1deec);
				}
				if (unknown1bc.hasExpired() && u6_world_cefc4c->unknown715730(2) >= 5)
				{
					U6Area area;
					u6_cells_cfd44c.getRect(unknown030->getPosition(),0x23,&area);
					for (int p = 0; p < 2; p++)
					{
						if (u6_overmind_cf6428.spawnPatrolParty(U6HEntity(),0,0,0,0,0,0,0xa,0) && !u6_overmind_cf6428.getParties().empty())
							u6_overmind_cf6428.getParties().back()->leader->getAI()->unknown459470(area);
					}
					do {} while (0);
					unknown1bc.reset();
				}
			}
			break;
		case 8:
			if (unknown030.operator->())
			{
				bool shielded = unknown030->unknown5d26e0(0xc7);
				if (!shielded && unknown030->getAI()->getBehavior() != 0x17)
					resetAI_699a00(true);
				if (!unknown274.empty())
				{
					for (int i = 0; i < unknown264.size(); i++)
					{
						if (!unknown264[i].operator->())
							u6_eraseStep_9d6440(unknown264,i);
					}
					for (int j = 0; j < unknown274.size(); j++)
					{
						if (!unknown274[j].operator->())
							u6_eraseStep_9d6440(unknown274,j);
					}
					while (unknown264.size() < 5 && !unknown274.empty())
					{
						unknown264.push_back(unknown274.front());
						u6_eraseAt_9da940(unknown274,0);
					}
					if (unknown274.size() >= 3)
					{
						vector<U6HEntity> squad;
						vector<int> scores;
						squad.push_back(unknown274.front());
						scores.push_back(squad.back()->unknown5d15a0(0));
						for (int i = 1; i < 3; i++)
						{
							int score = unknown274[i]->unknown5d15a0(0);
							if (score <= scores.back())
							{
								squad.push_back(unknown274[i]);
								scores.push_back(score);
							}
							else
							{
								for (unsigned int j = 0; j < squad.size(); j++)
								{
									if (score > scores[j])
									{
										u6_insert_9d8fc0(squad,j,unknown274[i]);
										u6_insertAt_9dbdc0(scores,j,score);
										break;
									}
								}
							}
						}
						unknown274.erase(unknown274.begin(),unknown274.begin() + 3);
						for (unsigned int k = 0; k < squad.size(); k++)
						{
							squad[k]->getAI()->unknown459470(u6_cells_cfd44c.getArea());
							if (k == 0)
								squad[k]->getAI()->setFollowEntity(U6HEntity(),0);
							else
								squad[k]->getAI()->setFollowEntity(squad[0],0);
						}
					}
				}
			}
			break;
		}
		if (unknown030.operator->() && unknown030->getAI()->getBehavior() != 0x17 && u6_world_cefc4c->unknown4642d0() % 2 == 0)
		{
			if ((u6_ba4ff0[unknown02c->unknown110].value && unknown030->unknown45a880() < u6_ba4ff0[unknown02c->unknown110].value && rng.chance(u6_ba4ff4[unknown02c->unknown110].value)) || (u6_ba4ff8[unknown02c->unknown110].value && unknown030->unknown5cab90() >= u6_ba4ff8[unknown02c->unknown110].value && rng.chance(u6_ba4ffc[unknown02c->unknown110].value)))
				resetAI_699a00(true);
		}
	}
	if (unknown230 && u6_world_cefc4c->getTurn() == abs(unknown230))
	{
		if (unknown230 < 0)
		{
			int index = unknown69b9b0(u6_strs_cf08b4,unknown244);
			U6_ALERT(1,-1,u6_strs_cf08b4[index]);
		}
		else if (rng.chance(50))
		{
			if (u6_containsRecord_9db330(unknown244,0))
			{
				string text;
				switch (rng.rangeInt(0,14))
				{
				case 0:
					text = "ALERT: Hostile activity reported, dispatching reinforcements to area.";
					break;
				case 1:
					text = "ALERT: Suspicious intruders detected, dispatching Cutter reinforcements to area.";
					break;
				case 2:
					text = "ALERT: Suspected Assembled signals approaching local area.";
					break;
				case 3:
					text = "ALERT: Power surge detected, dispatching additional patrols.";
					break;
				case 4:
					text = "ALERT: Infestation has breached Complex 0b10, dispatching Demolisher response squad.";
					break;
				case 5:
					text = "ALERT: Security rotation in progress.";
					break;
				case 6:
					text = "ALERT: Foreign system detected. Charging EMP.";
					break;
				case 7:
					text = "ALERT: Terminal network lockdown.";
					break;
				case 8:
					text = "ALERT: A rogue bot has emerged from the scrapyard. Terminate on contact.";
					break;
				case 9:
					text = "ALERT: Ambient heat levels +10.";
					break;
				case 10:
					text = "ALERT: All non-combat units evacuate.";
					break;
				case 11:
					text = "ALERT: Garrison responsiveness significantly impaired, staging for potential maximum security.";
					break;
				case 12:
					text = "ALERT: Persistent threat exposed, engaging " + u6_names_cfaca0[u6_location_d1e888->type] + " sterilization system.";
					break;
				case 13:
					text = "ALERT: Cargo convoy en route, clear transfer corridor.";
					break;
				case 14:
					text = "ALERT: High security lockdown imminent, T-100.";
					break;
				}
				U6_ALERT(1,-1,text);
				unknown230 = -(u6_world_cefc4c->getTurn() + rng.rangeInt(6,10));
			}
		}
		else if (u6_containsRecord_9db330(unknown234,0))
		{
			int index = unknown69b9b0(u6_strs_cf45a0,unknown234);
			U6_ALERT(1,-1,u6_strs_cf45a0[index]);
		}
	}
	if (rng.chance(10) && !u6_playerData_cf45d8.unknown46dd90() && !u6_cf462c)
	{
		int index;
		do
		{
			index = u6_randomIndex_9d9b20(u6_vec_d2d1c4);
		} while (u6_containsRecord_9db330(u6_vec_cf4554,index));
		if (u6_vec_d2d1c4[index]->unknown8c != u6_vec_d2d1c4[index]->getTotal())
		{
			do {} while (0);
			u6_cefb6c = 1;
		}
	}
}
