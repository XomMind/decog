// CMap::unknown81a8e0 (0x81a8e0): debug console command parser (COORDS, GOTO, EVOLVE, GIVE, ATTACH, ...),
// passed as a callback by CMap::input (0x827ed0). Matches with try.sh.
// Every name here is file-unique (dc_ / Dc prefix) so callees stay stubs and pair by address.
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class DcEntity;

class DcHEntity	// NOTE: placeholder name (entity handle)
{
public:
	int ID;
	DcHEntity();	// 0x9b6590
	DcEntity *operator->() const;	// HEntity::operator-> (0x9b7210 area; pairs by address)
};

class DcMap	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	DcEntity *getPlayer();	// Map::getPlayer
};
extern DcMap *dc_world;	// NOTE: placeholder name (0xcefc4c)

class DcTextWindow	// NOTE: placeholder name (CType at 0xcec10c)
{
public:
	virtual void v00();
	virtual void v04();
	virtual void v08();
	virtual void v0c();
	virtual void v10();
	virtual void v14();
	virtual void v18();
	virtual void v1c();
	virtual void v20();
	virtual void unknown24();	// NOTE: placeholder name (vtable slot 9)
};
extern DcTextWindow *dc_textWindow;	// NOTE: placeholder name (0xcec10c)

// message log
struct DcPhraseC	// NOTE: placeholder name (interface message phrase, ctor 0x511020)
{
	char pad[0x20];	// NOTE: placeholder layout
	DcPhraseC(string text, string *a, string *b, string *c, DcHEntity d, DcHEntity e);	// 0x511020
};
struct DcLogPhrase	// NOTE: placeholder name (log phrase; its ctor folds into 0x511020)
{
	char pad[0x28];	// NOTE: placeholder layout
	DcLogPhrase(string text, string *a, string *b, string *c, DcHEntity d, DcHEntity e);	// 0x511020
};
class DcMessageLog	// NOTE: placeholder name (object at 0xcf1080)
{
public:
	int push(DcLogPhrase *text);	// 0x5121f0
};
extern DcMessageLog dc_messageLog;	// NOTE: placeholder name (0xcf1080)
class DcMessages	// NOTE: placeholder name (0xcec058)
{
public:
	void bubble(bool flag);	// 0x8758d0
};
extern DcMessages *dc_messages;	// NOTE: placeholder name (0xcec058)
class DcLogMsgs	// NOTE: placeholder name (CLogMsgs at 0xcec0b4)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern DcLogMsgs *dc_logMsgs;	// NOTE: placeholder name (0xcec0b4)
class DcInterfaceMsg	// NOTE: placeholder name (CInterfaceMsg at 0xcec0f4)
{
public:
	void add(DcPhraseC *text);	// 0x7b1880
};
extern DcInterfaceMsg *dc_interfaceMsg;	// NOTE: placeholder name (0xcec0f4)

#define DC_LOG(text) do { if (dc_messageLog.push(new DcLogPhrase(text, 0, 0, 0, DcHEntity(), DcHEntity()))) dc_messages->bubble(true); dc_logMsgs->scrollToEnd(); } while (0)
#define DC_MSG(text) dc_interfaceMsg->add(new DcPhraseC(text, 0, 0, 0, DcHEntity(), DcHEntity()))

// string helpers
string dc_intToString(int value);	// 0x4051f0
int dc_stringToInt(const string &s);	// 0x405610
string dc_toUpper(const string &text);	// 0x4083a0
void dc_r1f_466950(const string &text);	// NOTE: placeholder name (0x466950)
int dc_charToDigit(char c);	// 0x405b40
void dc_eraseLastChar(string &s);	// 0x407840
int dc_findString(string *strings, int count, string text);	// 0x9cda80
int dc_maxInt(int a, int b);	// 0x9cdb60

extern bool dc_showCoords_cefb10;	// NOTE: placeholder name (0xcefb10)

// part 1 declarations (GOTO .. ACCESS_LOCKDOWN)
struct DcP1Node	// NOTE: placeholder layout (map location node)
{
	int unknown00;
	int type;
	int depth;
};
class DcP1HNode	// NOTE: placeholder name (location handle)
{
public:
	int ID;
	DcP1HNode();	// 0x9b6590
	DcP1Node *operator->() const;	// 0x9b7910
	bool isValid() const;	// 0x9b7230
};
struct DcP1MapFlags	// NOTE: placeholder layout (0xba6650, 3 bytes per map type)
{
	bool unknown0;
	bool unknown1;
	bool unknown2;
};
extern DcP1MapFlags dc_mapFlags_ba6650[];	// NOTE: placeholder name
extern string dc_mapNames_cfe140[];	// NOTE: placeholder name (0xcfe140)
extern DcP1HNode dc_currentLocation_d1e884;	// NOTE: placeholder name (0xd1e884)
extern DcP1HNode dc_location_d1e888;	// NOTE: placeholder name (0xd1e888)
void dc_findNode(int type, int depth, DcP1HNode node, DcP1HNode *result);	// 0x470180
void dc_openEvolve(int a, DcP1HNode loc, int b);	// 0x4b5780

// part 2 declarations (GIVE .. ACCESS_LOCKDOWN)
class DcP2Entity;
class DcP2Item;
struct DcP2Point;	// NOTE: placeholder name (position)
class DcP2HEntity	// NOTE: placeholder name (entity handle)
{
public:
	int ID;
	DcP2HEntity();	// 0x9b6590
	DcP2Entity *operator->() const;	// 0x9b6570
};
class DcP2HItem	// NOTE: placeholder name (item handle)
{
public:
	int ID;
	DcP2HItem();	// 0x9b6590
	DcP2Item *operator->() const;	// 0x9b65b0
	bool isValid() const;	// 0x9b7230
};
struct DcP2ItemType	// NOTE: placeholder name / layout (item record)
{
	int ID;	// +0x00
	char pad04[0x24 - 0x04];
	string name;	// +0x24 NOTE: placeholder name
	char pad40[0x48 - 0x40];
	int slot;	// +0x48 NOTE: placeholder name
	int count;	// +0x4c NOTE: placeholder name
	string initials();	// 0x5704b0
};
struct DcP2ItemData	// NOTE: placeholder layout
{
	char pad00[0x64];
	int value64;	// +0x64 NOTE: placeholder name
};
class DcP2Item
{
public:
	int unknown457f90();	// 0x457f90
	DcP2ItemData *getData();	// 0x9b4350 (folded getter)
	void setAmount(int value);	// 0x44fc60 NOTE: placeholder name (folded setter)
	bool unknown415ee0();	// 0x415ee0
	void unknown458390(bool flag);	// 0x458390
	int getType();	// 0x44aec0
};
class DcP2Entity
{
public:
	int unknown5c92e0(int slot);	// 0x5c92e0
	int getSlotTotal();	// 0x45a860
	void unknown5c94e0(int slot, DcP2HEntity owner);	// 0x5c94e0
	int unknown45a810();	// 0x45a810
	const DcP2Point &getPosition();	// 0x45a4a0
};
class DcP2Map
{
public:
	DcP2HEntity getPlayer();	// 0x4630f0
	DcP2HItem unknown6c51d0(DcP2ItemType *type, DcP2HEntity owner, bool a, bool b);	// 0x6c51d0
	DcP2HItem unknown6c5400(DcP2ItemType *type, const DcP2Point &pos);	// 0x6c5400
};
extern DcP2Map *dc2_world;	// 0xcefc4c
extern vector<DcP2ItemType *> dc2_itemTypes;	// 0xd2d1c4
int dc2_findNameNoCase(vector<DcP2ItemType *> &types, const string &name);	// 0x9e2830
bool dc2_equalsNoCase(const string &a, const string &b) throw();	// 0x407960
int dc2_findNoCase(const string &text, const string &term) throw();	// 0x4078c0
class DcP2GM	// NOTE: placeholder name (0xd25628)
{
public:
	void addItemAttachCount(int itemID, int count, bool force);	// 0x778560
};
extern DcP2GM dc2_gm;	// 0xd25628
class DcP2Part;
class DcP2Parts	// NOTE: placeholder name (0xcec088)
{
public:
	DcP2Part *unknown894e70(DcP2HItem item);	// 0x894e70
	void toggle8993e0(DcP2Part *part, bool flag);	// 0x8993e0
};
extern DcP2Parts *dc2_parts;	// 0xcec088
class DcP2GameData	// NOTE: placeholder name (0xd1e860)
{
public:
	int unknown789250(int value);	// 0x789250
};
extern DcP2GameData dc2_gameData;	// 0xd1e860
extern int dc2_difficulty_cf4718;	// NOTE: placeholder name (0xcf4718)
extern float dc2_table_ba65d8[];	// NOTE: placeholder name (0xba65d8)
extern bool dc2_flag_cefacd;	// NOTE: placeholder name (0xcefacd)
class DcP2Inventory	// NOTE: placeholder name (CInventory 0xcec08c)
{
public:
	void reopen(int mode, DcP2HItem item);	// 0x8a2ce0
};
extern DcP2Inventory *dc2_inventory;	// 0xcec08c
class DcP2Overmind	// NOTE: placeholder name (0xcf6428)
{
public:
	int presence;	// +0x00 NOTE: placeholder name
	void unknown68d980(int a, int b, int c);	// 0x68d980
	void unknown68e1a0();	// 0x68e1a0
};
extern DcP2Overmind dc2_overmind;	// 0xcf6428
extern bool dc2_presence_cefad4;	// NOTE: placeholder name (0xcefad4)
extern bool dc2_presencePopup_cefb14;	// NOTE: placeholder name (0xcefb14)

// part 3 declarations (UNCHAINED/UC, FOLLOW_TARGET)
struct DcP3EntityRecord	// NOTE: placeholder layout (elements of the vector at 0xd25de0)
{
	int unknown00;
	string name;
};
extern vector<DcP3EntityRecord *> dc3_entityRecords;	// NOTE: placeholder name (0xd25de0)
class DcP3Unit	// NOTE: placeholder name (OpS4_Unit at 0xcf6888)
{
public:
	void unknown699720(DcP3EntityRecord *record, int a);	// 0x699720
};
extern DcP3Unit dc3_unit;	// NOTE: placeholder name (0xcf6888)
struct DcP3Range	// NOTE: placeholder name/layout (object at 0xcf68ac)
{
	int first;
	int second;
	void reset();	// 0x45f0a0
};
extern DcP3Range dc3_range_cf68ac;	// NOTE: placeholder name (0xcf68ac)
struct DcP3Brain;
extern DcP3Brain *dc3_brain_cf68b4;	// NOTE: placeholder name (0xcf68b4)
struct DcP3Expiry	// NOTE: placeholder name/layout (object at 0xcf68c0)
{
	int first;
	int second;
	void set(int first_, int second_);	// 0x690d40
};
extern DcP3Expiry dc3_expiry_cf68c0;	// NOTE: placeholder name (0xcf68c0)
extern bool dc3_flag_cefb2a;	// NOTE: placeholder name (0xcefb2a)
extern bool dc3_followTarget_cefb16;	// NOTE: placeholder name (0xcefb16, debugShowPlayerPathHistoryFollowTarget)

// part 4 declarations (I/M/E/C/H, T/TURN, PT/PASS_TURNS, PLACE_ALLY/PA/PAP/PAW/PLACE_ENEMY/PE)
class DcP4Entity	// NOTE: placeholder name
{
public:
	int unknown5ca260();	// 0x5ca260
	void unknown5dea60(int a, bool b);	// 0x5dea60
	int unknown5ca670();	// 0x5ca670
	void unknown45b240(int a);	// 0x45b240
	int unknown5ca400();	// 0x5ca400
	void unknown45b270(int a);	// 0x45b270
	void unknown44e2c0(int a);	// 0x44e2c0
	void unknown4514c0(int a);	// 0x4514c0
};
class DcP4HEntity	// NOTE: placeholder name (entity handle, returned by value)
{
public:
	int ID;
	DcP4HEntity();	// 0x9b6590
	DcP4Entity *operator->() const;	// 0x9b6570
};
class DcP4Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	DcP4HEntity getPlayer();	// 0x4630f0
	void unknown465990(int turns);	// 0x465990
	void unknown4659c0(int turns);	// 0x4659c0
};
extern DcP4Map *dc4_world;	// NOTE: placeholder name (0xcefc4c)
#include "util/rng.h"
extern RNG rng;	// 0xd30908
extern const float dc4_f99_c37024;	// NOTE: placeholder name (0xc37024, 99.0f)
extern const float dc4_f500_c36f20;	// NOTE: placeholder name (0xc36f20, 500.0f)

struct DcP4EntityRecord	// NOTE: placeholder layout (elements of the vector at 0xd25de0)
{
	char pad00[0x24];
	int unknown24;
	int faction;
	string unknown2c;
	char pad48[0x68 - 0x48];
	int minDepth;
};
extern vector<DcP4EntityRecord *> dc4_entityRecords;	// NOTE: placeholder name (0xd25de0)
int dc4_findNameNoCase(vector<DcP4EntityRecord *> &records, const string &name);	// 0x9e2890
int dc4_findStringNoCase(string *strings, unsigned int count, const string &text);	// 0x409180
extern string dc4_factionNames[];	// NOTE: placeholder name (0xd2f798)

class DcP4Location	// NOTE: placeholder name
{
public:
	int getDepth();	// 0x46ed20
};
class DcP4HLocation	// NOTE: placeholder name (location handle)
{
public:
	int ID;
	DcP4Location *operator->() const;	// 0x9b7910
};
extern DcP4HLocation dc4_location_d1e888;	// NOTE: placeholder name (0xd1e888)
extern bool dc4_placeMode_caed26;	// NOTE: placeholder name (0xcaed26)
extern int dc4_placeRelation_caf13c;	// NOTE: placeholder name (0xcaf13c)
extern int dc4_placeRecord_caf138;	// NOTE: placeholder name (0xcaf138)

// part 5 declarations (CONVERT_CELL .. REMOVE_SLOT)
struct DcP5CellRecord	// NOTE: placeholder layout (cell terrain record)
{
	int unknown00;
	string name;	// +0x4
};
extern vector<DcP5CellRecord *> dc5_cellRecords;	// NOTE: placeholder name (0xcfb844)
int dc5_findNameNoCase(vector<DcP5CellRecord *> &records, const string &name);	// NOTE: placeholder name (0x9e2890)
extern bool dc5_convertFlag_caed26;	// NOTE: placeholder name (0xcaed26)
extern int dc5_convertCell_caf138;	// NOTE: placeholder name (0xcaf138)
extern int dc5_faction_caf140;	// NOTE: placeholder name (0xcaf140)
extern string dc5_factionNames[];	// NOTE: placeholder name (0xd31c00, 15 strings)
extern string dc5_slotNames_d38dd0[];	// NOTE: placeholder name (0xd38dd0, 4 strings)
extern string dc5_slotAbbrevs_d30428[];	// NOTE: placeholder name (0xd30428)
int dc5_findStringNoCase(string *strings, int count, const string &text);	// 0x409180

class DcP5Entity	// NOTE: placeholder name
{
public:
	int getSlotTotal();	// 0x45a860
	void addSlot(int type, DcHEntity source);	// NOTE: placeholder name (0x5c94e0)
	void removeSlot(int type);	// NOTE: placeholder name (0x5c9660)
};
class DcP5HEntity	// NOTE: placeholder name (entity handle)
{
public:
	int ID;
	DcP5HEntity();	// 0x9b6590
	DcP5Entity *operator->() const;	// 0x9b6570
};
class DcP5Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	DcP5HEntity getPlayer();	// 0x4630f0
};
extern DcP5Map *dc5_world;	// NOTE: placeholder name (0xcefc4c)

// part 6 declarations (RIF .. XPIETY)
class DcP6PlayerData	// NOTE: placeholder name (object at 0xcf45d8)
{
public:
	void unknown780ac0();	// 0x780ac0
	void installRIF(int ability);	// 0x780f30
};
extern DcP6PlayerData dc6_playerData;	// NOTE: placeholder name (0xcf45d8)
extern string dc6_rifAbilityNames[];	// NOTE: placeholder name (0xd2a2e0)
class DcP6Xom	// NOTE: placeholder name (object at 0xd25450)
{
public:
	bool active;
	char pad01[0xf];	// NOTE: placeholder layout
	int piety;	// +0x10
	int interest;	// +0x14
	void activate();	// 0x69e450
};
extern DcP6Xom dc6_xom;	// NOTE: placeholder name (0xd25450)
extern int dc6_xomPietyMax;	// NOTE: placeholder name (0xd223ec)
class DcP6Obj	// NOTE: placeholder name (object at 0xcec138)
{
public:
	void unknown9666d0();	// 0x9666d0
};
extern DcP6Obj *dc6_obj_cec138;	// NOTE: placeholder name (0xcec138)
void dc6_increase(int *value, int amount, int maximum);	// NOTE: placeholder name (0x9d06d0)
int dc6_clampInt(int low, int value, int high);	// NOTE: placeholder name (0x9cdc80)

// part 7 declarations (BREAK .. BREAK_MAINC)
struct DcP7Point	// NOTE: placeholder layout
{
	int x, y;
};

class DcP7Item	// NOTE: placeholder name
{
public:
	void setBroken(int a, bool b);	// 0x5795b0 NOTE: placeholder signature
	void setActivateOkayTurn(int turn);	// 0x4583b0
};

class DcP7HItem	// NOTE: placeholder name (item handle)
{
public:
	int ID;
	DcP7Item *operator->() const;	// 0x9b65b0
};

struct DcP7Slot	// NOTE: placeholder layout (inventory slot record)
{
	char pad00[0x6c];
	DcP7HItem item;
};

class DcP7Inventory	// NOTE: placeholder name (CInventory at 0xcec08c)
{
public:
	vector<DcP7Slot *> *getSlots();	// NOTE: placeholder name (folded getter 0x4a9ad0)
	void reopen(int mode, DcHEntity item);	// NOTE: placeholder signature (0x8a2ce0)
};
extern DcP7Inventory *dc7_inventory;	// NOTE: placeholder name (0xcec08c)

class DcP7HEntity;

class DcP7Entity	// NOTE: placeholder name
{
public:
	void unknown637bb0();	// NOTE: placeholder name (0x637bb0, destroy)
	void die(bool a, int cause, DcHEntity killer, bool b, int c, int d, int e, int f);	// NOTE: placeholder signature (0x633790)
	void unknown5dea60(int a, int b);	// NOTE: placeholder name (0x5dea60)
	void unknown5fd900(int a, int b);	// NOTE: placeholder name (0x5fd900)
	const DcP7Point &getPosition();	// 0x45a4a0
};

class DcP7HEntity	// NOTE: placeholder name (entity handle)
{
public:
	int ID;
	DcP7HEntity();	// 0x9b6590
	DcP7Entity *operator->() const;	// 0x9b6570
};

class DcP7Group	// NOTE: placeholder name
{
public:
	vector<DcP7HEntity> *getMembers();	// NOTE: placeholder name (folded getter 0x416f40)
};

class DcP7HGroup	// NOTE: placeholder name (group handle)
{
public:
	int ID;
	DcP7HGroup();	// 0x9b6590
	DcP7Group *operator->() const;	// 0x9b7250
};

class DcP7Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	int getTurn();	// 0x464270
	DcP7HGroup getGroup(int i);	// NOTE: placeholder name (0x463890)
	vector<DcP7HGroup> *getGroups();	// NOTE: placeholder name (0x463950)
	bool unknown4631f0(DcP7HEntity e);	// NOTE: placeholder name (0x4631f0, entity visible?)
	DcP7HEntity getPlayer();	// 0x4630f0
};
extern DcP7Map *dc7_world;	// 0xcefc4c

int dc7_distance(const DcP7Point &a, const DcP7Point &b);	// NOTE: placeholder name (0x40a3f0)

// part 8 declarations (NO_AI .. RANDOMIZE_INTEGRITY_MAP_ITEMS)
class DcP8Item	// NOTE: placeholder layout
{
public:
	int unknown457c80();	// NOTE: placeholder name (0x457c80, max integrity?)
	void setIntegrity(int value);	// NOTE: placeholder name (0x450460)
	int getType();	// 0x44aec0
};
class DcP8HItem	// NOTE: placeholder name (item handle)
{
public:
	int ID;
	DcP8HItem();	// 0x9b6590
	DcP8Item *operator->() const;	// 0x9b65b0
	bool isValid() const;	// 0x9b7230
};
class DcP8Entity	// NOTE: placeholder layout
{
public:
	void unknown5cb8b0(vector<DcP8HItem> &items);	// NOTE: placeholder name (0x5cb8b0)
	void unknown5cb830(vector<DcP8HItem> &items);	// NOTE: placeholder name (0x5cb830)
	vector<DcP8HItem> *getInventoryList();	// 0x45ab00
};
class DcP8HEntity	// NOTE: placeholder name (entity handle)
{
public:
	int ID;
	DcP8HEntity();	// 0x9b6590
	DcP8Entity *operator->() const;	// 0x9b6570
};
class DcP8Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	DcP8HEntity getPlayer();	// 0x4630f0
};
extern DcP8Map *dc8_world;	// 0xcefc4c
extern bool dc8_noAI;	// NOTE: placeholder name (0xcefb0e)
class DcP8MapView	// NOTE: placeholder name (0xcec054)
{
public:
	void toggle850();	// NOTE: placeholder name (0x49b760)
};
extern DcP8MapView *dc8_mapView;	// 0xcec054
class DcP8Experience	// NOTE: placeholder name (object at 0xcf45d8)
{
public:
	void gain(int amount, bool raw);	// 0x77e900
};
extern DcP8Experience dc8_experience;	// 0xcf45d8
class DcP8Part
{
public:
	void drawStatus(bool flag);	// 0x4a8e70
};
class DcP8Parts	// NOTE: placeholder name (CParts at 0xcec088)
{
public:
	DcP8Part *unknown894e70(DcP8HItem item);	// NOTE: placeholder name (0x894e70)
};
extern DcP8Parts *dc8_parts;	// 0xcec088
class DcP8Inventory	// NOTE: placeholder name (CInventory at 0xcec08c)
{
public:
	void reopen(int mode, DcP8HItem item);	// 0x8a2ce0
};
extern DcP8Inventory *dc8_inventory;	// 0xcec08c
class DcP8Cell
{
public:
	DcP8HItem getItem();	// 0x45d8f0
};
template <class T> class DcP8Array2D
{
public:
	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
	T &at(int x, int y);	// 0x9ceda0
};
extern DcP8Array2D<DcP8Cell *> dc8_cells;	// 0xcfd44c

// part 9 declarations (DESTROY_PART .. DAMAGE_COGMIND_PART)
struct DcP9Pos	// NOTE: placeholder layout (Pos)
{
	int x;
	int y;
	DcP9Pos();	// 0x453b40
};
class DcP9Item
{
public:
	int getType();	// 0x44aec0
	const string &getName();	// NOTE: placeholder name (0x457860)
	void setField450460(int value);	// NOTE: placeholder name (0x450460, folded setter)
	void remove57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name (0x57dbe0)
};
class DcP9HItem
{
public:
	int ID;
	DcP9HItem();	// 0x9b6590
	DcP9Item *operator->() const;	// 0x9b65b0
};
class DcP9Entity
{
public:
	vector<DcP9HItem> *getInventoryList();	// 0x45ab00
};
class DcP9HEntity
{
public:
	int ID;
	DcP9HEntity();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	DcP9Entity *operator->() const;	// 0x9b6570
};
class DcP9Cell
{
public:
	DcP9HEntity getEntity();	// 0x45d250
};
class DcP9CellGrid	// NOTE: placeholder name (map cells at 0xcfd44c)
{
public:
	DcP9Cell *&atPoint(const DcP9Pos &p);	// 0x9ced70
};
extern DcP9CellGrid dc9_cells;	// NOTE: placeholder name (0xcfd44c)
class DcP9CMap	// NOTE: placeholder name (CMap at 0xcec054)
{
public:
	bool unknown805190(DcP9Pos &pos);	// NOTE: placeholder name (0x805190)
};
extern DcP9CMap *dc9_cmap;	// NOTE: placeholder name (0xcec054)
class DcP9Map	// NOTE: placeholder name (0xcefc4c)
{
public:
	DcP9HEntity getPlayer();	// 0x4630f0
};
extern DcP9Map *dc9_world;	// NOTE: placeholder name (0xcefc4c)
class DcP9Part
{
public:
	void drawStatus(bool damaged);	// NOTE: placeholder name (0x4a8e70)
};
class DcP9Parts	// NOTE: placeholder name (CParts at 0xcec088)
{
public:
	DcP9Part *unknown894e70(DcP9HItem item);	// NOTE: placeholder name (0x894e70)
};
extern DcP9Parts *dc9_parts;	// NOTE: placeholder name (0xcec088)

// part 10 declarations (CRIT_TYPE .. colorFilters options)
struct DcP10ItemData	// NOTE: placeholder layout
{
	char pad000[0x134];
	int critType;	// NOTE: placeholder name (+0x134)
	int critChance;	// NOTE: placeholder name (+0x138)
};
class DcP10Item	// NOTE: placeholder layout
{
public:
	int getNestedField();	// NOTE: placeholder name (0x4578a0)
	DcP10ItemData *getData();	// NOTE: placeholder name (folded getter 0x9b4350)
};
class DcP10HItem	// NOTE: placeholder name (item handle)
{
public:
	int ID;
	DcP10HItem();	// 0x9b6590
	DcP10Item *operator->() const;	// 0x9b65b0
};
struct DcP10Point	// NOTE: placeholder layout
{
	int x;
	int y;
};
class DcP10Entity	// NOTE: placeholder layout
{
public:
	vector<DcP10HItem> *getInventoryList();	// 0x45ab00
	const DcP10Point &getPosition();	// 0x45a4a0
};
class DcP10HEntity	// NOTE: placeholder name (entity handle)
{
public:
	int ID;
	DcP10HEntity();	// 0x9b6590
	DcP10Entity *operator->() const;	// 0x9b6570
};
class DcP10Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	DcP10HEntity getPlayer();	// 0x4630f0
	DcP10HItem spawnMatter(const DcP10Point &pos, int amount, bool flag);	// NOTE: placeholder name (0x71e7c0)
};
extern DcP10Map *dc10_world;	// 0xcefc4c
extern const float dc10_c36ec8;	// NOTE: placeholder name (0xc36ec8)
extern string gameStrings_d1e058[];	// 0xd1e058 (global_string_arrays.cpp, 13 crit type names)
extern string configOptionNames[];	// 0xd35e18 (global_string_arrays.cpp; [77] = 0xd36684, [78] = 0xd366a0)
class DcP10Color	// NOTE: placeholder name (XColor, 4 bytes)
{
public:
	int value;
	DcP10Color(const DcP10Color &other) throw();	// 0x411e30
};
extern DcP10Color *dc10_colorBlack;	// NOTE: placeholder name (0xcfe674)
void dc10_setColor(DcP10Color color);	// NOTE: placeholder name (0x4347a0)
class DcP10Config	// NOTE: placeholder name (object at 0xd28c68)
{
public:
	void parseColorFilters(int which, string text);	// 0x4456b0
};
extern DcP10Config dc10_config;	// 0xd28c68

// part 11 declarations (BASE / B)
#include <istream>
class DcP11Entity;
class DcP11HEntity	// NOTE: placeholder name (entity handle)
{
public:
	int ID;
	DcP11HEntity();	// 0x9b6590
	DcP11Entity *operator->() const;	// 0x9b6570
};
struct DcP11ItemType	// NOTE: placeholder layout
{
	char pad00[0x48];
	int slot;	// NOTE: placeholder name (+0x48)
	int count;	// NOTE: placeholder name (+0x4c)
};
class DcP11Item	// NOTE: placeholder name
{
public:
	int getCategory();	// 0x44aec0
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name (0x57dbe0)
};
class DcP11HItem	// NOTE: placeholder name (item handle)
{
public:
	int ID;
	DcP11HItem();	// 0x9b6590
	DcP11Item *operator->() const;	// 0x9b65b0
};
class DcP11Entity	// NOTE: placeholder name
{
public:
	void unknown5c94e0(int slot, DcHEntity e);	// NOTE: placeholder name (0x5c94e0)
	int unknown5c92e0(int slot);	// NOTE: placeholder name (0x5c92e0)
	int getSlotTotal();	// 0x45a860
	vector<DcP11HItem> *getInventoryList();	// 0x45ab00
	void unknown5ded70(int a);	// NOTE: placeholder name (0x5ded70)
	void unknown5deb40(int a);	// NOTE: placeholder name (0x5deb40)
};
class DcP11Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	DcP11HEntity getPlayer();	// 0x4630f0
	DcP11HItem giveItem(const string &name, DcP11HEntity e, int a, int b);	// NOTE: placeholder name (0x6c52b0)
	DcP11HItem unknown6c51d0(DcP11ItemType *type, DcP11HEntity e, int a, int b);	// NOTE: placeholder name (0x6c51d0)
};
extern DcP11Map *dc11_world;	// NOTE: placeholder name (0xcefc4c)
struct DcP11Part;	// NOTE: placeholder name
class DcP11Parts	// NOTE: placeholder name (CParts at 0xcec088)
{
public:
	DcP11Part *unknown894e70(DcP11HItem item);	// NOTE: placeholder name (0x894e70)
	void toggle8993e0(DcP11Part *part, int a);	// NOTE: placeholder name (0x8993e0)
};
extern DcP11Parts *dc11_parts;	// NOTE: placeholder name (0xcec088)

struct DcP11PhysFile;
class DcP11BaseFstream	// NOTE: placeholder name (PhysFScpp::base_fstream)
{
protected:
	DcP11PhysFile * const file;
public:
	DcP11BaseFstream(DcP11PhysFile *file);
	virtual ~DcP11BaseFstream();
	bool isOpen();	// 0x404af0
};
class DcP11Ifstream : public DcP11BaseFstream, public std::istream	// NOTE: placeholder name (PhysFScpp::ifstream)
{
public:
	DcP11Ifstream(const string &filename, std::ios_base::openmode mode = std::ios_base::in);	// 0x411b40
	virtual ~DcP11Ifstream();	// vbase dtor 0x4095b0
	void close_9c05e0();	// NOTE: placeholder name (0x9c05e0)
};
bool dc11_getEncodedLine(DcP11Ifstream *file, string &line, int key);	// NOTE: placeholder name (0x4074b0)
void dc11_removeChar(string &text, char c);	// NOTE: placeholder name (0x408100)
void dc11_split(const string &text, char separator, vector<string> &out);	// NOTE: placeholder name (0x408700)
extern vector<DcP11ItemType *> dc11_itemTypes;	// NOTE: placeholder name (0xd2d1c4)
bool dc11_findItemType(vector<DcP11ItemType *> &v, const string &name, DcP11ItemType **out);	// NOTE: placeholder name (0x9d7a40)

// part 12 declarations (EXILES_SEEDS .. P2_SLOTS)
#include <fstream>
extern int dc12_exilesSeeds_cefaf8;	// NOTE: placeholder name (0xcefaf8)
class DcP12MapView	// NOTE: placeholder name (object at 0xcec054)
{
public:
	void toggle870();	// NOTE: placeholder name (0x49b790)
};
extern DcP12MapView *dc12_mapView;	// NOTE: placeholder name (0xcec054)
class DcP12Entity
{
public:
	int *unknown45a840();	// NOTE: placeholder name (0x45a840)
};
class DcP12HEntity	// NOTE: placeholder name (entity handle)
{
public:
	int ID;
	DcP12HEntity();	// 0x9b6590
	DcP12Entity *operator->() const;	// 0x9b6570
	bool isValid() const;	// 0x9b7230
};
class DcP12Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	DcP12HEntity getEntity671();	// NOTE: placeholder name (0x463110)
};
extern DcP12Map *dc12_world;	// NOTE: placeholder name (0xcefc4c)
extern string dc12_names_d38dd0[];	// NOTE: placeholder name (0xd38dd0)
extern string dc12_slotNames_d30428[];	// NOTE: placeholder name (0xd30428)
extern int dc12_slotBase_ba7aec[];	// NOTE: placeholder name (0xba7aec)
extern int dc12_slotFactor_ba7afc[];	// NOTE: placeholder name (0xba7afc)
int dc12_findStringNoCase(string *strings, int count, const string &text);	// 0x409180
int dc12_minInt(int a, int b);	// 0x9cdb30
string &dc12_padLeft(string &s, int length, char c);	// NOTE: placeholder name (0x408090)
class DcP12Grid	// NOTE: placeholder layout (Array2D<int>)
{
public:
	int width, height;	// NOTE: placeholder layout (12 bytes)
	int *data;
	DcP12Grid(int width, int height, int fill);	// 0x9ced10
	~DcP12Grid();	// 0x9cec20
	int *at(int x, int y) throw();	// 0x9ceda0
};
class DcP12WL	// NOTE: placeholder name (weighted list)
{
public:
	vector<int> values;
	vector<int> weights;
	int total;
	DcP12WL(vector<int> &w);	// 0x9baaa0
	int &pick() throw();	// 0x9ba470
	vector<int> &getWeights() throw();	// NOTE: placeholder name (0x462e10)
};

// part 13 declarations (P2_INV, FACTION_COLOR)
class DcP13Color	// NOTE: placeholder name (XColor, 4 bytes)
{
public:
	unsigned char b, g, r, a;	// NOTE: placeholder layout
	DcP13Color(const DcP13Color &other) throw();	// 0x411e30
	DcP13Color &operator=(DcP13Color other);	// 0x411f10
	void set(int r, int g, int b);	// 0x4124a0
	string toString() const;	// 0x4121c0
};
class DcP13Faction	// NOTE: placeholder name/layout
{
public:
	char pad00[0x2c];
	vector<DcP13Color> colors;
};
class DcP13HFaction	// NOTE: placeholder name (handle)
{
public:
	int ID;
	DcP13Faction *operator->() const;	// 0x9b7250
};
class DcP13Map
{
public:
	vector<DcP13HFaction> *getFactions();	// 0x463950 NOTE: placeholder name
};
extern DcP13Map *dc13_world;	// 0xcefc4c
extern bool dc13_player2Inventory;	// 0xcefb17 NOTE: placeholder name
extern DcP13Color *dc13_defaultColor;	// 0xd31574 NOTE: placeholder name (pointer)
extern int dc13_faction;	// 0xcaf140 NOTE: placeholder name
extern string dc13_factionNames[];	// 0xd31c00 NOTE: placeholder name
void dc13_split(const string &text, char separator, vector<string> &out);	// 0x408700

// Static CMap member in the original; named fc_typed81a8e0 to share the symbol india_01.cpp (CMap::input) pushes.
void fc_typed81a8e0(const string &text)	// NOTE: placeholder name
{
	string command = text;
	dc_textWindow->unknown24();
	if (!command.empty())
	{
		dc_r1f_466950(command);
		string name;
		string param;
		size_t pos = command.find('=');
		if (pos == string::npos)
			pos = command.find(' ');
		if (pos == string::npos)
			name = command;
		else
		{
			name.assign(command.begin(), command.begin() + pos);
			param.assign(command.begin() + pos + 1, command.end());
		}
		name = dc_toUpper(name);
		if (name == "COORDS")
			dc_showCoords_cefb10 = !dc_showCoords_cefb10;
		else if (name == "GOTO" || name == "GO" || name == "EVOLVE" || name == "EVO")
		{
			int depth = -1;
			if (param.size() > 3 && isdigit(param[param.size() - 1]))
			{
				depth = dc_charToDigit(param[param.size() - 1]);
				if (depth == 0)
					depth = 10;
				dc_eraseLastChar(param);
			}
			param = dc_toUpper(param);
			int type = dc_findString(dc_mapNames_cfe140, 0x26, param);
			if (type != -1 && !dc_mapFlags_ba6650[type].unknown0)
			{
				DcP1HNode node;
				dc_findNode(type, depth, dc_currentLocation_d1e884, &node);
				if (node.isValid())
				{
					DC_LOG("Loading " + dc_mapNames_cfe140[node->type] + " at depth " + dc_intToString(node->depth));
					int delta = dc_location_d1e888->depth - node->depth;
					if (name[0] == 'E')
					{
						if (dc_location_d1e888->type == 1)
							delta--;
						dc_openEvolve(dc_maxInt(delta, 0), node, 1);
					}
					else
						dc_openEvolve(0, node, 0);
				}
			}
		}
		else if (name == "GIVE" || name == "G" || name == "ATTACH" || name == "A" || name == "GAL")
		{
			int id = dc2_findNameNoCase(dc2_itemTypes, param);
			if (id == -1)
			{
				for (unsigned i = 0; i < dc2_itemTypes.size(); i++)
				{
					if (dc2_equalsNoCase(dc2_itemTypes[i]->initials(), param))
					{
						id = i;
						break;
					}
				}
			}
			if (id == -1)
			{
				for (unsigned j = 0; j < dc2_itemTypes.size(); j++)
				{
					if (dc2_findNoCase(dc2_itemTypes[j]->name, param) != -1)
					{
						id = j;
						break;
					}
				}
			}
			if (id != -1)
			{
				if (name == "GAL")
					dc2_gm.addItemAttachCount(dc2_itemTypes[id]->ID, 1, true);
				else
				{
					DcP2ItemType *type = dc2_itemTypes[id];
					DcP2HItem item;
					if (name[0] == 'A')
					{
						if (dc2_world->getPlayer()->unknown5c92e0(type->slot) < type->count)
						{
							if (dc2_world->getPlayer()->getSlotTotal() + (type->count - dc2_world->getPlayer()->unknown5c92e0(type->slot)) <= 26)
							{
								for (int k = type->count - dc2_world->getPlayer()->unknown5c92e0(type->slot); k > 0; k--)
									dc2_world->getPlayer()->unknown5c94e0(type->slot, DcP2HEntity());
							}
							else
								goto equip;
						}
						item = dc2_world->unknown6c51d0(type, dc2_world->getPlayer(), true, false);
						if (item.isValid())
						{
							DcP2Part *part = dc2_parts->unknown894e70(item);
							if (part)
								dc2_parts->toggle8993e0(part, false);
							goto equipped;
						}
					}
				equip:
					if (dc2_world->getPlayer()->unknown45a810() >= type->count)
						item = dc2_world->unknown6c51d0(type, dc2_world->getPlayer(), false, true);
					else
						item = dc2_world->unknown6c5400(type, dc2_world->getPlayer()->getPosition());
				equipped:
					if (item.isValid())
					{
						if (item->unknown457f90() == 0x7c)
							item->setAmount(dc2_gameData.unknown789250((int)(item->getData()->value64 * dc2_table_ba65d8[dc2_difficulty_cf4718])));
						if (item->unknown415ee0() && !dc2_flag_cefacd)
						{
							item->unknown458390(false);
							if (item->getType() == 4)
								dc2_inventory->reopen(5, item);
						}
					}
				}
			}
		}
		else if (name == "PRESENCE")
		{
			if (param.empty())
				dc2_presence_cefad4 = !dc2_presence_cefad4;
			else
				dc2_overmind.presence = dc_stringToInt(param);
		}
		else if (name == "PRESENCE_POPUP")
		{
			dc2_presencePopup_cefb14 = !dc2_presencePopup_cefb14;
			DC_MSG("debugShowPresencePopup=" + dc_intToString(dc2_presencePopup_cefb14 != 0));
		}
		else if (name == "HIGH_SECURITY" || name == "HS")
			dc2_overmind.unknown68d980(1, 0, 0);
		else if (name == "ACCESS_LOCKDOWN" || name == "AL")
			dc2_overmind.unknown68e1a0();
		else if (name == "UNCHAINED" || name == "UC")
		{
			if (!param.empty())
			{
				param = dc_toUpper(param);
				DcP3EntityRecord *record = 0;
				for (unsigned int i = 1; i < dc3_entityRecords.size(); i++)
				{
					if (dc3_entityRecords[i]->name == param || (param.size() == 2 && dc3_entityRecords[i]->name[0] == param[0] && dc3_entityRecords[i]->name[1] == param[1]))
					{
						record = dc3_entityRecords[i];
						break;
					}
				}
				if (record == 0)
				{
					if (param == "X0")
						DC_MSG("X0-1V1 incompatible with this command");
					else
						DC_MSG("UC not found (" + param + ")");
				}
				else if (dc3_brain_cf68b4 != 0)
					DC_MSG("UC already active");
				else
				{
					dc3_unit.unknown699720(record, 1);
					dc3_range_cf68ac.reset();
					dc3_expiry_cf68c0.set(1, 1);
					dc3_flag_cefb2a = true;
					DC_MSG("preparing to dispatch " + record->name);
				}
			}
			else
				DC_MSG("must specify UC using name or first two letters");
		}
		else if (name == "FOLLOW_TARGET")
		{
			dc3_followTarget_cefb16 = !dc3_followTarget_cefb16;
			DC_MSG("debugShowPlayerPathHistoryFollowTarget=" + dc_intToString(dc3_followTarget_cefb16 != 0));
		}
		else if (name == "I")
		{
			if (param.empty())
				dc4_world->getPlayer()->unknown5dea60(dc4_world->getPlayer()->unknown5ca260(), false);
			else if (param == "RAND")
				dc4_world->getPlayer()->unknown5dea60(rng.rangeInt(0, dc4_world->getPlayer()->unknown5ca260()), false);
			else
				dc4_world->getPlayer()->unknown5dea60(dc_stringToInt(param), false);
		}
		else if (name == "M")
		{
			if (param.empty())
				dc4_world->getPlayer()->unknown45b240(dc4_world->getPlayer()->unknown5ca670());
			else if (param == "RAND")
				dc4_world->getPlayer()->unknown45b240(rng.rangeInt(0, dc4_world->getPlayer()->unknown5ca670()));
			else
				dc4_world->getPlayer()->unknown45b240(dc_stringToInt(param));
		}
		else if (name == "E")
		{
			if (param.empty())
				dc4_world->getPlayer()->unknown45b270(dc4_world->getPlayer()->unknown5ca400());
			else if (param == "RAND")
				dc4_world->getPlayer()->unknown45b270(rng.rangeInt(0, dc4_world->getPlayer()->unknown5ca400()));
			else
				dc4_world->getPlayer()->unknown45b270(dc_stringToInt(param));
		}
		else if (name == "C")
		{
			if (param.empty())
				dc4_world->getPlayer()->unknown44e2c0(99);
			else if (param == "RAND")
				dc4_world->getPlayer()->unknown44e2c0(rng.rangeInt(0, dc4_f99_c37024));
			else
				dc4_world->getPlayer()->unknown44e2c0(dc_stringToInt(param));
		}
		else if (name == "H")
		{
			if (param.empty())
				dc4_world->getPlayer()->unknown4514c0(500);
			else if (param == "RAND")
				dc4_world->getPlayer()->unknown4514c0(rng.rangeInt(0, dc4_f500_c36f20));
			else
				dc4_world->getPlayer()->unknown4514c0(dc_stringToInt(param));
		}
		else if (name == "T" || name == "TURN")
		{
			if (!param.empty())
				dc4_world->unknown465990(dc_stringToInt(param));
		}
		else if (name == "PT" || name == "PASS_TURNS")
		{
			if (!param.empty())
				dc4_world->unknown4659c0(dc_stringToInt(param));
		}
		else if (name == "PLACE_ALLY" || name == "PA" || name == "PAP" || name == "PAW" || name == "PLACE_ENEMY" || name == "PE")
		{
			dc4_placeMode_caed26 = true;
			if (name == "PLACE_ALLY" || name == "PA")
				dc4_placeRelation_caf13c = 1;
			else if (name == "PAP")
				dc4_placeRelation_caf13c = 2;
			else if (name == "PAW")
				dc4_placeRelation_caf13c = 9;
			else
				dc4_placeRelation_caf13c = 3;
			dc4_placeRecord_caf138 = dc4_findNameNoCase(dc4_entityRecords, param);
			if (dc4_placeRecord_caf138 == -1)
			{
				int faction = dc4_findStringNoCase(dc4_factionNames, 0x61, param);
				if (faction != -1)
				{
					for (int i = dc4_entityRecords.size() - 1; i >= 0; i--)
					{
						if (dc4_entityRecords[i]->faction == faction && dc4_entityRecords[i]->unknown24 == 1 && dc4_entityRecords[i]->minDepth <= dc4_location_d1e888->getDepth() && dc4_entityRecords[i]->unknown2c.empty())
						{
							dc4_placeRecord_caf138 = i;
							break;
						}
					}
				}
			}
		}
		else if (name == "CONVERT_CELL" || name == "CC")
		{
			dc5_convertFlag_caed26 = false;
			dc5_convertCell_caf138 = dc5_findNameNoCase(dc5_cellRecords, param);
			if (dc5_convertCell_caf138 == -1)
				DC_MSG("unknown cellID");
			else
				DC_MSG("cellID=" + dc5_cellRecords[dc5_convertCell_caf138]->name);
		}
		else if (name == "FACTION" || (name == "F" && !param.empty()))
		{
			param = dc_toUpper(param);
			int faction = dc_findString(dc5_factionNames, 0xf, param);
			if (faction == -1)
				DC_MSG("unknown faction ID");
			else
			{
				dc5_faction_caf140 = faction;
				DC_MSG("assign faction set to " + dc5_factionNames[dc5_faction_caf140]);
			}
		}
		else if (name == "ADD_SLOT" || name == "AS")
		{
			int num = 1;
			if (isdigit(param[param.size() - 1]))
			{
				num = dc_charToDigit(param[param.size() - 1]);
				dc_eraseLastChar(param);
			}
			int type = dc5_findStringNoCase(dc5_slotNames_d38dd0, 4, param);
			if (type == -1)
				type = dc5_findStringNoCase(dc5_slotAbbrevs_d30428, 4, param);
			if (type != -1)
			{
				for (int i = 0; i < num && dc5_world->getPlayer()->getSlotTotal() < 26; i++)
					dc5_world->getPlayer()->addSlot(type, DcHEntity());
			}
		}
		else if (name == "REMOVE_SLOT" || name == "RS")
		{
			int num = 1;
			if (isdigit(param[param.size() - 1]))
			{
				num = dc_charToDigit(param[param.size() - 1]);
				dc_eraseLastChar(param);
			}
			int type = dc5_findStringNoCase(dc5_slotNames_d38dd0, 4, param);
			if (type == -1)
				type = dc5_findStringNoCase(dc5_slotAbbrevs_d30428, 4, param);
			if (type != -1)
			{
				for (int i = 0; i < num; i++)
					dc5_world->getPlayer()->removeSlot(type);
			}
		}
		else if (name == "RIF")
		{
			dc6_playerData.unknown780ac0();
			if (!param.empty())
			{
				param = dc_toUpper(param);
				for (int i = 0; i < 0x13; i++)
				{
					if (param == dc_toUpper(dc6_rifAbilityNames[i]))
					{
						dc6_playerData.installRIF(i);
						break;
					}
				}
			}
		}
		else if (name == "XOM")
		{
			if (!dc6_xom.active)
			{
				dc6_xom.activate();
				DC_MSG("activated Xom");
			}
			dc6_obj_cec138->unknown9666d0();
		}
		else if (name == "XINT")
		{
			if (dc6_xom.active && !param.empty())
			{
				dc6_increase(&dc6_xom.interest, dc_stringToInt(param), 100);
				DC_MSG("Xom interest + " + param + "=" + dc_intToString(dc6_xom.interest));
			}
		}
		else if (name == "XPIETY")
		{
			if (dc6_xom.active && !param.empty())
			{
				dc6_xom.piety = dc6_clampInt(0, dc_stringToInt(param), dc6_xomPietyMax);
				DC_MSG("Xom piety: " + dc_intToString(dc6_xom.piety));
			}
		}
		else if (name == "BREAK")
		{
			if (!dc7_inventory->getSlots()->empty())
				(*dc7_inventory->getSlots())[0]->item->setBroken(-2, 1);
		}
		else if (name == "DISABLE")
		{
			if (!dc7_inventory->getSlots()->empty())
			{
				(*dc7_inventory->getSlots())[0]->item->setActivateOkayTurn(dc7_world->getTurn() + 20);
				dc7_inventory->reopen(0, DcHEntity());
			}
		}
		else if (name == "DESTROY_MAINC" || name == "DM")
		{
			vector<DcP7HEntity> *members = dc7_world->getGroup(3)->getMembers();
			while (!members->empty())
				members->front()->unknown637bb0();
		}
		else if (name == "DESTROY_MAINC_UNSEEN" || name == "DMU")
		{
			vector<DcP7HEntity> members = *dc7_world->getGroup(3)->getMembers();
			for (unsigned int i = 0; i < members.size(); i++)
			{
				if (!dc7_world->unknown4631f0(members[i]))
					members[i]->unknown637bb0();
			}
		}
		else if (name == "DESTROY_UNSEEN" || name == "DU")
		{
			for (unsigned int g = 0; g < dc7_world->getGroups()->size(); g++)
			{
				vector<DcP7HEntity> members = *dc7_world->getGroup(g)->getMembers();
				for (unsigned int i = 0; i < members.size(); i++)
				{
					if (!dc7_world->unknown4631f0(members[i]))
						members[i]->unknown637bb0();
				}
			}
		}
		else if (name == "DESTROY_UNSEEN_FAR" || name == "DUF")
		{
			int range = param.empty() ? 10 : dc_stringToInt(param);
			for (unsigned int g = 0; g < dc7_world->getGroups()->size(); g++)
			{
				vector<DcP7HEntity> members = *dc7_world->getGroup(g)->getMembers();
				for (unsigned int i = 0; i < members.size(); i++)
				{
					if (dc7_distance(members[i]->getPosition(), dc7_world->getPlayer()->getPosition()) > range)
						members[i]->unknown637bb0();
				}
			}
		}
		else if (name == "KILL_MAINC" || name == "KM")
		{
			vector<DcP7HEntity> *members = dc7_world->getGroup(3)->getMembers();
			while (!members->empty())
				members->front()->die(1, 10, DcHEntity(), 1, 0, 0, 0, 0);
		}
		else if (name == "KILL_UNSEEN" || name == "KU")
		{
			for (unsigned int g = 0; g < dc7_world->getGroups()->size(); g++)
			{
				vector<DcP7HEntity> members = *dc7_world->getGroup(g)->getMembers();
				for (unsigned int i = 0; i < members.size(); i++)
				{
					if (!dc7_world->unknown4631f0(members[i]))
						members[i]->die(1, 10, DcHEntity(), 1, 0, 0, 0, 0);
				}
			}
		}
		else if (name == "MAIM_MAINC")
		{
			vector<DcP7HEntity> *members = dc7_world->getGroup(3)->getMembers();
			for (unsigned int i = 0; i < members->size(); i++)
				(*members)[i]->unknown5dea60(1, 0);
		}
		else if (name == "BREAK_MAINC")
		{
			vector<DcP7HEntity> *members = dc7_world->getGroup(3)->getMembers();
			for (unsigned int i = 0; i < members->size(); i++)
				(*members)[i]->unknown5fd900(8, 0);
		}
		else if (name == "NO_AI" || name == "AI")
		{
			dc8_noAI = !dc8_noAI;
			DC_MSG("no_ai=" + dc_intToString(dc8_noAI != 0));
		}
		else if (name == "SHOW_ENERGY")
			dc8_mapView->toggle850();
		else if (name == "XP")
		{
			if (!param.empty())
				dc8_experience.gain(dc_stringToInt(param), true);
		}
		else if (name == "RANDOMIZE_INTEGRITY" || name == "RANDOMIZE_INTEGRITY_ALL" || name == "RANDOMIZE_INTEGRITY_INVENTORY" || name == "RI" || name == "RIA" || name == "RII")
		{
			vector<DcP8HItem> items;
			if (name == "RANDOMIZE_INTEGRITY" || name == "RI")
				dc8_world->getPlayer()->unknown5cb8b0(items);
			else if (name == "RANDOMIZE_INTEGRITY_INVENTORY" || name == "RII")
				dc8_world->getPlayer()->unknown5cb830(items);
			else
				items = *dc8_world->getPlayer()->getInventoryList();
			int minPct = 0;
			int maxPercent = 100;
			if (!param.empty())
			{
				minPct = dc_stringToInt(param);
				if (minPct < 0)
				{
					maxPercent = -minPct;
					minPct = 0;
				}
			}
			for (unsigned int i = 0; i < items.size(); i++)
			{
				items[i]->setIntegrity(rng.rangeInt(minPct ? items[i]->unknown457c80() * minPct / 100 : 1, items[i]->unknown457c80() * maxPercent / 100));
				if (items[i]->getType() <= 3)
					dc8_parts->unknown894e70(items[i])->drawStatus(true);
			}
			if (name == "RANDOMIZE_INTEGRITY_ALL" || name == "RIA" || name == "RANDOMIZE_INTEGRITY_INVENTORY" || name == "RII")
				dc8_inventory->reopen(0, DcP8HItem());
		}
		else if (name == "RANDOMIZE_INTEGRITY_MAP_ITEMS" || name == "RIMI")
		{
			for (int x = 0; x < dc8_cells.getWidth(); x++)
			{
				for (int y = 0; y < dc8_cells.getHeight(); y++)
				{
					if (dc8_cells.at(x, y)->getItem().isValid())
						dc8_cells.at(x, y)->getItem()->setIntegrity(rng.rangeInt(1, dc8_cells.at(x, y)->getItem()->unknown457c80()));
				}
			}
		}
		else if (name == "DESTROY_PART" || name == "DP")
		{
			if (!param.empty())
			{
				param = dc_toUpper(param);
				DcP9Pos cursor;
				if (dc9_cmap->unknown805190(cursor) && dc9_cells.atPoint(cursor)->getEntity().isValid())
				{
					vector<DcP9HItem> *items = dc9_cells.atPoint(cursor)->getEntity()->getInventoryList();
					for (unsigned int i = 0; i < items->size(); i++)
					{
						if (dc_toUpper((*items)[i]->getName()) == param)
						{
							(*items)[i]->remove57dbe0(1, 0, 1, 1);
							break;
						}
					}
				}
			}
		}
		else if (name == "DISARM")
		{
			DcP9Pos cursor;
			if (dc9_cmap->unknown805190(cursor) && dc9_cells.atPoint(cursor)->getEntity().isValid())
			{
				int partCount = 0;
				vector<DcP9HItem> *items = dc9_cells.atPoint(cursor)->getEntity()->getInventoryList();
				for (unsigned int i = 0; i < items->size(); i++)
				{
					if ((*items)[i]->getType() == 3)
					{
						(*items)[i]->remove57dbe0(1, 0, 1, 1);
						partCount++;
					}
				}
				DC_MSG("weapons destroyed: " + dc_intToString(partCount));
			}
			else
				DC_MSG("no actor found");
		}
		else if (name == "DESTROY_COGMIND_PART" || name == "CDP")
		{
			if (!param.empty())
			{
				param = dc_toUpper(param);
				vector<DcP9HItem> *items = dc9_world->getPlayer()->getInventoryList();
				for (unsigned int i = 0; i < items->size(); i++)
				{
					if (dc_toUpper((*items)[i]->getName()) == param)
					{
						(*items)[i]->remove57dbe0(1, 0, 1, 1);
						break;
					}
				}
			}
		}
		else if (name == "DAMAGE_COGMIND_PART" || name == "CDMGP")
		{
			if (!param.empty())
			{
				param = dc_toUpper(param);
				vector<DcP9HItem> *items = dc9_world->getPlayer()->getInventoryList();
				for (unsigned int i = 0; i < items->size(); i++)
				{
					if (dc_toUpper((*items)[i]->getName()) == param)
					{
						(*items)[i]->setField450460(1);
						if ((*items)[i]->getType() <= 3)
							dc9_parts->unknown894e70((*items)[i])->drawStatus(true);
						break;
					}
				}
			}
		}
		else if (name == "CRIT_TYPE" || name == "CT")
		{
			if (!param.empty())
			{
				param = dc_toUpper(param);
				int type = 0;
				for (int i = 0; i < 13; i++)
				{
					if (param == dc_toUpper(gameStrings_d1e058[i]))
					{
						type = i;
						break;
					}
				}
				if (type != 0)
				{
					vector<DcP10HItem> *items = dc10_world->getPlayer()->getInventoryList();
					for (unsigned int j = 0; j < items->size(); j++)
					{
						if ((*items)[j]->getNestedField() == 3)
						{
							(*items)[j]->getData()->critChance = 100;
							(*items)[j]->getData()->critType = type;
							break;
						}
					}
				}
			}
		}
		else if (name == "PROTOMATTER")
		{
			dc10_world->spawnMatter(dc10_world->getPlayer()->getPosition(), param.empty() ? rng.rangeInt(1, dc10_c36ec8) : dc_stringToInt(param), true);
		}
		else if (name == dc_toUpper(configOptionNames[77]) || name == dc_toUpper(configOptionNames[78]))
		{
			bool first = name == dc_toUpper(configOptionNames[77]);
			if (!first)
				dc10_setColor(*dc10_colorBlack);
			dc10_config.parseColorFilters(first ? 77 : 78, dc_toUpper(param));
		}
		else if (name == "BASE" || name == "B")
		{
			DcP11HItem item;
			DcP11Part *part;
			if (param.empty())
			{
				dc11_world->getPlayer()->unknown5c94e0(0, DcHEntity());
				item = dc11_world->giveItem("Quantum Reactor", dc11_world->getPlayer(), 1, 0);
				part = dc11_parts->unknown894e70(item);
				if (part)
					dc11_parts->toggle8993e0(part, 0);
				dc11_world->getPlayer()->unknown5c94e0(1, DcHEntity());
				dc11_world->getPlayer()->unknown5c94e0(1, DcHEntity());
				item = dc11_world->giveItem("Biometal Leg", dc11_world->getPlayer(), 1, 0);
				part = dc11_parts->unknown894e70(item);
				if (part)
					dc11_parts->toggle8993e0(part, 0);
				item = dc11_world->giveItem("Biometal Leg", dc11_world->getPlayer(), 1, 0);
				part = dc11_parts->unknown894e70(item);
				if (part)
					dc11_parts->toggle8993e0(part, 0);
				dc11_world->getPlayer()->unknown5c94e0(2, DcHEntity());
				dc11_world->getPlayer()->unknown5c94e0(2, DcHEntity());
				dc11_world->getPlayer()->unknown5c94e0(2, DcHEntity());
				item = dc11_world->giveItem("Exp. Cooling System", dc11_world->getPlayer(), 1, 0);
				part = dc11_parts->unknown894e70(item);
				if (part)
					dc11_parts->toggle8993e0(part, 0);
				item = dc11_world->giveItem("Exp. Energy Well", dc11_world->getPlayer(), 1, 0);
				part = dc11_parts->unknown894e70(item);
				if (part)
					dc11_parts->toggle8993e0(part, 0);
				item = dc11_world->giveItem("Exp. Matter Compressor", dc11_world->getPlayer(), 1, 0);
				part = dc11_parts->unknown894e70(item);
				if (part)
					dc11_parts->toggle8993e0(part, 0);
				dc11_world->getPlayer()->unknown5ded70(10000);
				dc11_world->getPlayer()->unknown5deb40(10000);
			}
			else
			{
				int lineNumber = dc_stringToInt(param);
				string loadout;
				DcP11Ifstream stream((string() + "builds.txt").c_str());
				if (stream.isOpen())
				{
					int n = 0;
					string line;
					while (dc11_getEncodedLine(&stream, line, -1))
					{
						dc11_removeChar(line, '\n');
						if (++n == lineNumber)
						{
							loadout = line;
							break;
						}
					}
					stream.close_9c05e0();
					if (loadout.empty())
						DC_MSG("line " + dc_intToString(lineNumber) + " not found, or is empty");
					else
					{
						DcP11HEntity player = dc11_world->getPlayer();
						vector<DcP11HItem> *inventory = player->getInventoryList();
						for (unsigned int i = 0; i < inventory->size(); i++)
						{
							if ((*inventory)[i]->getCategory() <= 3)
							{
								(*inventory)[i]->unknown57dbe0(1, 0, 1, 1);
								i--;
							}
						}
						int ok = 0;
						int fails = 0;
						vector<string> partNames;
						dc11_split(loadout, '|', partNames);
						for (unsigned int j = 0; j < partNames.size(); j++)
						{
							DcP11ItemType *type;
							if (!dc11_findItemType(dc11_itemTypes, partNames[j], &type))
								fails++;
							else
							{
								while (player->unknown5c92e0(type->slot) < type->count && player->getSlotTotal() < 26)
									player->unknown5c94e0(type->slot, DcHEntity());
								if (player->unknown5c92e0(type->slot) < type->count)
									fails++;
								else
								{
									item = dc11_world->unknown6c51d0(type, player, 1, 0);
									part = dc11_parts->unknown894e70(item);
									if (part)
										dc11_parts->toggle8993e0(part, 0);
									ok++;
								}
							}
						}
						player->unknown5ded70(10000);
						player->unknown5deb40(10000);
						DC_MSG("added part count: " + dc_intToString(ok) + "; failed part count: " + dc_intToString(fails));
					}
				}
			}
		}
		else if (name == "EXILES_SEEDS")
			dc12_exilesSeeds_cefaf8 = param.empty() ? 50 : dc_stringToInt(param);
		else if (name == "P2B")
			dc12_mapView->toggle870();
		else if ((name == "P2_ADD_SLOT" || name == "P2_AS") && dc12_world->getEntity671().isValid())
		{
			int num = 1;
			if (isdigit(param[param.size() - 1]))
			{
				num = dc_charToDigit(param[param.size() - 1]);
				dc_eraseLastChar(param);
			}
			int type = dc12_findStringNoCase(dc12_names_d38dd0, 4, param);
			if (type == -1)
				type = dc12_findStringNoCase(dc12_slotNames_d30428, 4, param);
			if (type != -1)
			{
				for (int i = 0; i < num; i++)
					dc12_world->getEntity671()->unknown45a840()[type]++;
			}
		}
		else if (name == "P2_SLOTS")
		{
			const int numRuns = 50;
			ofstream out("player2_slot_distribution.txt");
			for (int run = 0; run < numRuns; run++)
			{
				DcP12Grid slotCounts(10, 4, 0);
				*slotCounts.at(0, 0) = 1;
				*slotCounts.at(0, 1) = 2;
				*slotCounts.at(0, 2) = 2;
				*slotCounts.at(0, 3) = 2;
				DcP12Grid weights(10, 4, 0);
				*weights.at(0, 0) = 0;
				*weights.at(0, 1) = 0;
				*weights.at(0, 2) = 0;
				*weights.at(0, 3) = 0;
				for (int x = 1; x <= 9; x++)
				{
					for (int y = 0; y < 4; y++)
						*slotCounts.at(x, y) = *slotCounts.at(x - 1, y);
					for (int k = 2; k > 0; k--)
					{
						int sum = 0;
						vector<int> slotWeights((unsigned)4, 0);
						for (int j = 0; j < 4; j++)
						{
							slotWeights[j] = dc12_slotBase_ba7aec[j];
							if (j != 2)
							{
								int d = (*slotCounts.at(x, j) - *slotCounts.at(0, j)) * -dc12_slotFactor_ba7afc[j];
								d = dc12_minInt(d, slotWeights[j]);
								slotWeights[j] -= d;
								sum += d;
							}
						}
						slotWeights[2] += sum;
						if (*slotCounts.at(x, 0) >= *slotCounts.at(x, 1) - 1)
							slotWeights[0] = 1;
						for (int j = 0; j < 4; j++)
						{
							if (slotWeights[j] <= 0)
								slotWeights[j] = 1;
						}
						DcP12WL wts(slotWeights);
						(*slotCounts.at(x, wts.pick()))++;
						if (k == 2)
						{
							for (int j = 0; j < 4; j++)
								*weights.at(x, j) = wts.getWeights()[j];
						}
					}
				}
				out << "   10  9  8  7  6  5  4  3  2  1\n";
				for (int j = 0; j < 4; j++)
				{
					out << dc12_slotNames_d30428[j];
					for (int x = 0; x < 10; x++)
						out << dc12_padLeft(dc_intToString(*slotCounts.at(x, j)), 3, ' ');
					out << "\n";
				}
				for (int j = 0; j < 4; j++)
				{
					out << dc12_slotNames_d30428[j][0] << "%";
					for (int x = 0; x < 10; x++)
						out << dc12_padLeft(dc_intToString(*weights.at(x, j)), 3, ' ');
					out << "\n";
				}
				out << "\n";
			}
			out.close();
		}
		else if (name == "P2_INV")
		{
			dc13_player2Inventory = !dc13_player2Inventory;
			DC_MSG("debugPlayer2Inventory=" + dc_intToString(dc13_player2Inventory != 0));
		}
		else if (name == "FACTION_COLOR" || name == "FCOL")
		{
			DcP13Color fcolor = *dc13_defaultColor;
			if (!param.empty())
			{
				vector<string> parts;
				dc13_split(param, ',', parts);
				if (parts.size() == 3)
					fcolor.set(dc_stringToInt(parts[0]), dc_stringToInt(parts[1]), dc_stringToInt(parts[2]));
			}
			vector<DcP13HFaction> *factions = dc13_world->getFactions();
			for (int i = 0; i < 6; i++)
				(*factions)[dc13_faction]->colors[i] = fcolor;
			DC_MSG("faction " + dc13_factionNames[dc13_faction] + " color set to " + fcolor.toString());
		}
	}
}
