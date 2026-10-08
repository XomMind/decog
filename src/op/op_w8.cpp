// op_w8: Entity methods (0x5c0000-0x5e0000) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
#include <stdlib.h>
using namespace std;

extern RNG rng;	// NOTE: placeholder name (0xd30908)

int opw2_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(int x_, int y_);	// 0x46ca20
	void opw8_fill(int value);	// NOTE: placeholder name (0x409ff0)
	Point(const Point &p, int dx, int dy);
	Point(const Point &p);	// 0x46ca50
	Point &operator=(const Point &p);	// 0x46ca50
	void save(class OpW8_Stream *stream);	// NOTE: placeholder name (0x40a370)
	bool operator!=(const Point &p) const;	// 0x409bd0
	bool operator==(const Point &p) const;	// 0x409b90
	void assign(const Point &p);	// NOTE: placeholder name (0x40a030)
	void load(class OpW8_Stream *stream);	// NOTE: placeholder name (0x40a330)
};

int opw8_pointDistance(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
bool unknown4373c0(const Point &a, const Point &b);	// NOTE: placeholder name
int minInt(int a, int b);	// 0x9cdb30
template <class T> T sumArray(const T *values, unsigned int count) throw();	// NOTE: placeholder name (0x9d0ca0)
bool opw8_contains(const vector<bool> &values, bool value) throw();	// NOTE: placeholder name (0x9d7670)
int opw2_clampInt(int low, int value, int high);	// NOTE: placeholder name (0x9cdc80)
void opw8_atLeast(int *value, int minimum);	// NOTE: placeholder name (0x9cf5c0)
int opw8_decrease(int *value, int amount, int minimum);	// NOTE: placeholder name (0x9d0690)
bool findEffectID(const string &name, int *id);	// NOTE: placeholder name (0x9d7980)
string intToString(int value);
bool opw8_contains9db330(vector<struct OpW8_ItemRecord *> *list, struct OpW8_ItemRecord *value);	// NOTE: placeholder name
bool opw8_anyNonZero(vector<int> &values);	// NOTE: placeholder name (0x9d7f70)
bool opw8_unknown437320(int value);	// NOTE: placeholder name
bool opw8_inRange(int low, int value, int high);	// NOTE: placeholder name (0x9daf80)
int opw8_distance(int x1, int y1, int x2, int y2);	// NOTE: placeholder name (0x406480)

struct OpW8_Range	// NOTE: placeholder name (8 bytes)
{
	OpW8_Range() throw();	// 0x40bef0
	void load(class OpW8_Stream *stream);	// NOTE: placeholder name (0x45f040)
	int randomInRange_40c130();	// NOTE: placeholder name

	int min;
	int max;
};

struct OpW8_EntityRecord	// NOTE: placeholder layout
{
	OpW8_EntityRecord(class OpW8_Stream *stream);	// 0x5c2930
	void unknown459d00(string *out);	// NOTE: placeholder name

	int unknown00;
	string name;
	bool unknown20;
	int unknown24;
	int unknown28;
	string unknown2C;
	int unknown48;
	string unknown4C;
	int unknown68;
	int unknown6C;
	int unknown70;
	bool unknown74;
	bool unknown75;
	int ascii;	// NOTE: placeholder name
	int unknown7C;
	int unknown80;
	int unknown84;
	int unknown88;
	int unknown8C;
	int unknown90;
	int unknown94;
	int unknown98;
	int type;	// NOTE: placeholder name
	int unknownA0;
	int unknownA4;
	bool unknownA8;
	bool unknownA9;
	int unknownAC;
	int unknownB0;
	int unknownB4;
	int unknownB8;
	int unknownBC;
	int unknownC0;
	vector<Point *> unknownC4;
	vector<int> unknownD4;
	int unknownE4;
	int unknownE8;
	int unknownEC;
	int unknownF0;
	int unknownF4;
	int unknownF8;
	vector<int> unknownFC;
	int unknown10C;
	int unknown110;
	bool unknown114;
	OpW8_Range unknown118;
	int unknown120;
	int unknown124;
	int unknown128;
	int unknown12C;
	OpW8_Range unknown130;
	bool unknown138;
	bool unknown139;
	bool unknown13A;
	bool unknown13B;
	int unknown13C;
	int unknown140;
	float unknown144;
	vector<int> unknown148;
	int unknown158;
	bool unknown15C;
	vector<vector<struct OpW8_PartOption *> > unknown160;
	string unknown170;
	string unknown18C;
	int unknown1A8;
	string unknown1AC;
	int unknown1C8;
	int unknown1CC[4];
	int unknown1DC;
	int unknown1E0;
	int unknown1E4;
	int unknown1E8;
	int unknown1EC;
	int unknown1F0;
	int unknown1F4[7];
	OpW8_Range unknown210;
	int unknown218;
	int unknown21C;
	int unknown220;
	int unknown224;
	int unknown228;

	int unknown459ca0();	// NOTE: placeholder name
	int unknown5c3120();	// NOTE: placeholder name
	bool unknown5c3260(class HProp prop, bool flag);	// NOTE: placeholder name
	string unknown5c32e0();	// NOTE: placeholder name
};

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos);
	Pos &operator=(const Pos &pos);	// 0x46ca50
};

class HItem;
class XConsole
{
public:
	bool isHidden();
	void setPos(const Pos &pos);
	void unknown8a54c0(HItem item, bool flag);	// NOTE: placeholder name (CInventory)
	void unknown987de0();	// NOTE: placeholder name
	void opw8_reopen(int mode, HItem item);	// NOTE: placeholder name (CInventory::reopen 0x8a2ce0)
};

class OpW8_SidePanel : public XConsole	// NOTE: placeholder name (0xcec118/0xcec11c/0xcec120)
{
public:
	void unknown8b5080();	// NOTE: placeholder name
};
extern OpW8_SidePanel *opw8_cec118;	// NOTE: placeholder name
extern OpW8_SidePanel *opw8_cec11c;	// NOTE: placeholder name
extern OpW8_SidePanel *opw8_cec120;	// NOTE: placeholder name
extern XConsole *opw8_cec034;	// NOTE: placeholder name
extern XConsole *opw8_cec08c;	// NOTE: placeholder name (CInventory)

class OpW8_Unk965220	// NOTE: placeholder name (object at 0xcec138)
{
public:
	void unknown965220();	// NOTE: placeholder name
};
extern OpW8_Unk965220 *opw8_cec138;	// NOTE: placeholder name

Pos unknown4b33b0();	// NOTE: placeholder name
void unknown4b3540(XConsole *parent);	// NOTE: placeholder name
template <class T> void eraseAt(vector<T> &v, unsigned int index);	// NOTE: placeholder name (0x9d8f20)

class PlayerData	// NOTE: partial
{
public:
	void loadPartSlots(int a, int b);
	void addPolymindSuspicion(float amount, int type, class HItem item);
	void addPolymindSuspicion(float amount, int type, class HEntity entity);	// NOTE: same function as above (0x77ee70)
	void unknown77fbc0(int type);	// NOTE: placeholder name
	bool unknown780790();	// NOTE: placeholder name
	void unknown780810(HEntity e, int type, int value);	// NOTE: placeholder name
	void unknown46ddd0();	// NOTE: placeholder name
	int unknown46e150();	// NOTE: placeholder name
	void unknown77ffb0(int a, int b);	// NOTE: placeholder name
	bool unknown46dd90();	// NOTE: placeholder name
	void unknown77f230(float amount, int type);	// NOTE: placeholder name
	int unknown46dec0();	// NOTE: placeholder name
	void unknown780700(int index, int value);	// NOTE: placeholder name
};
extern PlayerData opw8_playerData;	// NOTE: placeholder name (0xcf45d8)

extern bool opw8_cf4d14;	// NOTE: placeholder name
extern bool opw8_cf4d15;	// NOTE: placeholder name

class OpW8_HackData	// NOTE: placeholder name
{
public:
	bool unknown65cf80();	// NOTE: placeholder name
};

class OpW8_Prop	// NOTE: placeholder name
{
public:
	OpW8_HackData *unknown44b020();	// NOTE: placeholder name (ICF'd trivial getter)
	struct OpW8_PropType *unknown9b8f00();	// NOTE: placeholder name (ICF'd trivial getter)
	void unknown65f170();	// NOTE: placeholder name
	struct OpW8_PropInfo *unknown45cb30();	// NOTE: placeholder name (ICF'd trivial getter)
};

class HProp
{
public:
	int ID;
	HProp() throw();
	bool isNull() const;
	OpW8_Prop *operator->() const;	// 0x9b64f0
};

struct OpW8_SlotMarker	// NOTE: placeholder name
{
	OpW8_SlotMarker(int index_, int b, HProp prop_, int d, int value_) throw();	// 0x46d1b0
	bool unknown46d2e0();	// NOTE: placeholder name

	int index;
	int unknown04;
	HProp prop;
	int unknown0C;
	int value;
};
extern vector<vector<OpW8_SlotMarker *> > opw8_slotMarkers;	// NOTE: placeholder name (0xcf4750)

struct OpW8_ItemTypeD2d1c4	// NOTE: placeholder name
{
	char pad00[0x48];
	int unknown48;
	char pad4C[4];
	int unknown50;
	char pad54[0x1f0 - 0x54];
	int unknown1F0;
};
extern vector<OpW8_ItemTypeD2d1c4 *> opw8_d2d1c4;	// NOTE: placeholder name

extern vector<OpW8_EntityRecord *> opw8_d25de0;	// NOTE: placeholder name
extern int opw8_caf160;	// NOTE: placeholder name
extern int opw8_caf164;	// NOTE: placeholder name

extern string opw8_factionNames[];	// NOTE: placeholder name (0xd2f798)

struct OpW8_Obj_cf68b4	// NOTE: placeholder name
{
	char pad00[0x110];
	int unknown110;
};
extern OpW8_Obj_cf68b4 *opw8_cf68b4;	// NOTE: placeholder name
extern float opw8_b96580;	// NOTE: placeholder name
extern float opw8_caf22c;	// NOTE: placeholder name
extern float opw8_caf230;	// NOTE: placeholder name

class Entity;
struct EntityEffect;

extern int opw8_cf496c;	// NOTE: placeholder name
extern int opw8_cf462c;	// NOTE: placeholder name
extern int opw8_cf4954;	// NOTE: placeholder name
extern int opw8_cf4970;	// NOTE: placeholder name
extern int opw8_cf4974;	// NOTE: placeholder name
extern int opw8_cf4978;	// NOTE: placeholder name
extern int opw8_cf49dc;
extern int opw8_cf497c;
extern int opw8_cf49d8;	// NOTE: placeholder name
extern bool opw8_table_ba0984[];	// NOTE: placeholder name
extern vector<int> opw8_vec_d2c408;	// NOTE: placeholder name
bool opw8_lookup9d7de0(vector<int> *list, const string &name, struct OpW8_Talk *&talk);	// NOTE: placeholder name
extern unsigned int opw8_tickCount;	// NOTE: placeholder name (0xcaed20)
struct OpW8_Possession	// NOTE: placeholder name (0x34 bytes)
{
	OpW8_Possession(HEntity e);	// NOTE: placeholder name (0x7786b0)

	int unknown00;
	char pad04[0x34 - 4];
};
extern OpW8_Possession *opw8_cf4700;	// NOTE: placeholder name
extern struct OpW8_ItemRecord *opw8_cefbe8;	// NOTE: placeholder name
extern vector<struct OpW8_ItemRecord *> opw8_d31510;	// NOTE: placeholder name
extern int opw8_table_b959fc[];	// NOTE: placeholder name	// NOTE: placeholder name
extern int opw8_table_cf49a0[];	// NOTE: placeholder name
extern int opw8_table_cf4984[];	// NOTE: placeholder name	// NOTE: placeholder name
extern bool opw8_d25450;	// NOTE: placeholder name
extern int opw8_d25564;	// NOTE: placeholder name
extern bool opw8_table_ba0968[];	// NOTE: placeholder name
extern bool opw8_d28d26;	// NOTE: placeholder name
extern int opw8_d35be0;	// NOTE: placeholder name
extern int opw8_d25e0c;	// NOTE: placeholder name
extern int opw8_cf281c;	// NOTE: placeholder name
extern int opw8_d2b284;	// NOTE: placeholder name
extern int opw8_d23094;	// NOTE: placeholder name
extern int opw8_d2f34c;	// NOTE: placeholder name
extern vector<int> opw8_cf4830;	// NOTE: placeholder name
extern float opw8_bba054;	// NOTE: placeholder name
extern float opw8_ba09dc;	// NOTE: placeholder name
extern int opw8_table_b960e8[];	// NOTE: placeholder name
extern int opw8_table_b96100[];	// NOTE: placeholder name

struct Area	// NOTE: placeholder name
{
	Area();	// 0x40b100
	int width();	// NOTE: placeholder name (0x40b670)
	int height();	// NOTE: placeholder name (0x40b690)
	Point min;
	Point max;
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();
	bool isValid() const;
	bool isNull() const;
	bool operator==(HEntity other) const;
	bool operator!=(HEntity other) const;
	Entity *operator->() const throw();	// 0x9b6570
	void opw8_reset();	// NOTE: placeholder name (0x9b7270)
	void save(class OpW8_Stream *stream);	// NOTE: placeholder name (0x9cfa90)
	void load(class OpW8_Stream *stream);	// NOTE: placeholder name (0x9cfaf0)
};

struct OpW8_ItemRecord	// NOTE: placeholder layout
{
	char pad00[0x40];
	int unknown40;
	int unknown44;
	int unknown48;
	int unknown4C;
	int unknown50;
	int unknown54;
	char pad58[0x94 - 0x58];
	int unknown94;
	char pad98[0xb8 - 0x98];
	int unknownB8;
	char padBC[0xec - 0xbc];
	int unknownEC;
	int unknownF0;
	char padF4[0x11c - 0xf4];
	int unknown11C;
	int unknown120;
	int unknown124;
	int unknown128;
	char pad12C[0x13c - 0x12c];
	vector<int> unknown13C;
	char pad14C[0x158 - 0x14c];
	int unknown158;
	char pad15C[0x164 - 0x15c];
	bool unknown164;
	bool unknown165;
	char pad166[0x1a0 - 0x166];
	struct OpW8_LaunchData *unknown1A0;	// NOTE: placeholder name
	char pad1A4[0x1a8 - 0x1a4];
	int unknown1A8;
	bool unknown1AC;
	char pad1AD[0x1ae - 0x1ad];
	bool unknown1AE;
	char pad1AF[0x1b0 - 0x1af];
	bool unknown1B0;
};

class Item
{
public:
	int unknown44aec0() throw();	// NOTE: placeholder name (ICF'd trivial getter)
	int unknown44aec0Nothrow() throw();	// NOTE: placeholder name (same function; private name keeps the throw() declaration under LTCG)
	int unknown457b30();	// NOTE: placeholder name
	int unknown4578c0();	// NOTE: placeholder name
	int unknown4578a0() throw();	// NOTE: placeholder name
	int unknown4578a0Nothrow() throw();	// NOTE: placeholder name (same function; private name keeps the throw() declaration under LTCG)
	int unknown457880();	// NOTE: placeholder name
	bool unknown457d70();	// NOTE: placeholder name
	int unknown457f90();	// NOTE: placeholder name
	bool unknown457cf0();	// NOTE: placeholder name
	const string &unknown457860();	// NOTE: placeholder name
	int unknown457ca0();	// NOTE: placeholder name
	int unknown577790();	// NOTE: placeholder name
	int unknown577df0();	// NOTE: placeholder name
	bool unknown457d10();	// NOTE: placeholder name
	bool unknown457ad0();	// NOTE: placeholder name
	int unknown9b6bf0();	// NOTE: placeholder name (ICF'd trivial getter)
	int unknown457c80();	// NOTE: placeholder name
	bool unknown457db0();	// NOTE: placeholder name
	bool unknown458220();	// NOTE: placeholder name
	int unknown4580c0();	// NOTE: placeholder name
	int unknown4580a0();	// NOTE: placeholder name
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
	int unknown458080();	// NOTE: placeholder name
	int unknown44ab90();	// NOTE: placeholder name (ICF'd trivial getter)
	float unknown577d80();	// NOTE: placeholder name
	int unknown577e60();	// NOTE: placeholder name
	int unknown577c90();	// NOTE: placeholder name
	int unknown577f30();	// NOTE: placeholder name
	int unknown457f50();	// NOTE: placeholder name
	int unknown457f30();	// NOTE: placeholder name
	int unknown457f70();	// NOTE: placeholder name
	int unknown457ed0();	// NOTE: placeholder name
	float unknown457df0();	// NOTE: placeholder name
	int unknown457e10();	// NOTE: placeholder name
	int unknown457820();	// NOTE: placeholder name
	int unknown45cb30();	// NOTE: placeholder name (ICF'd trivial getter)
	int unknown577b10();	// NOTE: placeholder name
	int unknown457fb0();	// NOTE: placeholder name
	int unknown457fd0();	// NOTE: placeholder name
	int getEffectValue(int type);	// NOTE: placeholder name (0x457be0)
	int unknown577fb0();	// NOTE: placeholder name
	int unknown577fd0();	// NOTE: placeholder name
	int unknown578070();	// NOTE: placeholder name
	void *getEffect(int type);	// 0x457b70
	bool unknown5773d0(bool a, bool b);	// NOTE: placeholder name
	bool unknown5775a0();	// NOTE: placeholder name
	bool unknown5776c0();	// NOTE: placeholder name
	bool unknown577700();	// NOTE: placeholder name
	int unknown457cd0();	// NOTE: placeholder name
	int unknown457900();	// NOTE: placeholder name
	int unknown577bd0();	// NOTE: placeholder name
	bool unknown415ee0();	// NOTE: placeholder name (ICF'd trivial getter)
	bool unknown457d30();	// NOTE: placeholder name
	bool unknown457d50();	// NOTE: placeholder name
	bool unknown577940();	// NOTE: placeholder name
	void unknown57a190(HEntity e, int amount, int a, int b);	// NOTE: placeholder name
	void unknown57a0f0(Point *p, int a, int b);	// NOTE: placeholder name
	void unknown458390(bool flag);	// NOTE: placeholder name
	void setActive(bool active);
	bool unknown4579d0();	// NOTE: placeholder name
	string unknown4579f0();	// NOTE: placeholder name
	bool unknown4578e0();	// NOTE: placeholder name
	int unknown4580e0();	// NOTE: placeholder name
	bool unknown578d90(HItem item);	// NOTE: placeholder name
	int unknown578e90(int a);	// NOTE: placeholder name
	float unknown579090();	// NOTE: placeholder name
	int unknown578a70();	// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown458310(int value);	// NOTE: placeholder name
	bool unknown5758f0();	// NOTE: placeholder name
	void unknown44fc60(int value);	// NOTE: placeholder name (ICF'd trivial setter)
	struct OpW8_ItemRecord *unknown9b4350();	// NOTE: placeholder name (ICF'd trivial getter)
};

class HItem
{
public:
	int ID;
	HItem();
	bool isValid() const;
	bool isNull() const;
	bool operator!=(HItem other) const throw();
	bool notEqual_9b6510(HItem other) const throw();	// NOTE: placeholder name (operator!= under a private name, so LTCG keeps this TU's throw())
	bool operator==(HItem other) const;
	Item *operator->() const throw();	// 0x9b65b0
	Item *get_9b65b0() const throw();	// NOTE: placeholder name (operator-> under a private name, so LTCG keeps this TU's throw())
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

class Group	// NOTE: placeholder name
{
public:
	int unknown9b4350();	// NOTE: placeholder name (ICF'd trivial getter)
	vector<HEntity> *getMembers();	// NOTE: placeholder name (0x416f40, ICF'd getter)
	int unknown9b8f00();	// NOTE: placeholder name (ICF'd trivial getter)

	char pad00[0x2c];
	vector<XColor> colors;	// NOTE: placeholder name
};

class HGroup	// NOTE: placeholder name
{
public:
	int ID;
	HGroup();
	Group *operator->() const;	// 0x9b7250
	void opw8_reset();	// NOTE: placeholder name (0x9b7270)
	void save(class OpW8_Stream *stream);	// NOTE: placeholder name (0x9cfa90)
	void load(class OpW8_Stream *stream);	// NOTE: placeholder name (0x9cfaf0)
	bool isValid() const;
};

class Cell
{
public:
	HEntity getEntity();
	bool isPassableFor(HEntity e);
	bool unknown66aed0();	// NOTE: placeholder name
	bool unknown45dd40(int value);	// NOTE: placeholder name
	HProp getProp();
	bool isMachinePart();
	HItem getItem();	// 0x45d8f0
	void clearEntity();	// 0x66baf0
};

void sweepGetSurroundingCells(const Point &point, vector<Point> &adjacent);	// 0x4faaf0

struct OpW8_MachineInfo	// NOTE: placeholder name
{
	char pad00[4];
	int type;	// NOTE: placeholder name
	char pad08[0x25 - 8];
	bool identified;	// NOTE: placeholder name
};

class OpW8_MachineHandle	// NOTE: placeholder name
{
public:
	int ID;
	OpW8_MachineInfo *operator->();	// 0x9b7910
};

class OpW8_Zone	// NOTE: placeholder name
{
public:
	void unknown6c16d0(string text);	// NOTE: placeholder name

	char pad00[8];
	OpW8_MachineHandle machine;
};

class OpW8_Log	// NOTE: placeholder name (object at 0xcec054)
{
public:
	void unknown80e3a0(int type, OpW8_Zone *zone);	// NOTE: placeholder name
	void unknown80e3a0(int type, const Point &p);	// NOTE: placeholder name
	void unknown813050(int a, HProp prop, int b, int c, int d);	// NOTE: placeholder name
	void unknown49b690(const Point &p);	// NOTE: placeholder name (OpW5_MapView2::setUnknown38c)
	void unknown8071e0(HEntity e, int a);	// NOTE: placeholder name
	void unknown8074d0(HEntity e);	// NOTE: placeholder name
	void unknown49ac50();	// NOTE: placeholder name
	HEntity unknown4b1b30();	// NOTE: placeholder name
	void unknown8069e0(Point p, int a);	// NOTE: placeholder name
};
extern OpW8_Log *opw8_cec054;	// NOTE: placeholder name

struct Area;
template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	T &operator()(int x, int y);	// 0x9ceda0
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
	bool contains(int x, int y);	// NOTE: placeholder name (0x9b45c0)
	int getWidth();
	int getHeight();
	void getRect(const Point &p, int radius, Area &out);	// NOTE: placeholder name (0x9b4430)
	void getRect(const Point &p, int before, int after, Area &out);	// NOTE: placeholder name (0x9b7ac0)
	void init(int width, int height, T value);	// NOTE: placeholder name (0x9cffc0)
	void setBounds(int x, int y, int width, int height, int value);	// NOTE: placeholder name (0x9d0050)
	int getMinX();	// NOTE: placeholder name
	int getMaxX();	// NOTE: placeholder name
	int getMinY();	// NOTE: placeholder name
	int getMaxY();	// NOTE: placeholder name
};
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

class Map	// NOTE: partial
{
public:
	OpW8_Zone *getZone(const Point &p);
	void unknown71dd30(OpW8_MachineHandle machine);	// NOTE: placeholder name
	HEntity getPlayer() throw();	// 0x4630f0
	int getTurn();	// 0x464270
	int unknown463910(HGroup a, HGroup b);	// NOTE: placeholder name
	int unknown4638e0(int type, int value);	// NOTE: placeholder name
	HEntity opw8_getEntity671();	// NOTE: placeholder name (BS::getEntity671 0x463110)
	int unknown7275f0(HEntity e, int value);	// NOTE: placeholder name (BS)
	bool opw8_isVisible(const Point &p);	// NOTE: placeholder name (BS::isVisible 0x4631c0)
	unsigned int unknown463710();	// NOTE: placeholder name
	HGroup unknown463890(int i);	// NOTE: placeholder name
	bool unknown463400(HEntity e);	// NOTE: placeholder name
	bool unknown463510(HEntity e);	// NOTE: placeholder name
	void unknown734560(HEntity e, int a, int b);	// NOTE: placeholder name (BS)
	bool unknown4635c0(HEntity e);	// NOTE: placeholder name
	void unknown72e4c0(HEntity e, bool flag);	// NOTE: placeholder name
	HItem unknown6c51d0(OpW8_ItemRecord *type, HEntity e, int a, int b);	// NOTE: placeholder name
	void unknown71c550(HEntity e, vector<HEntity> *out);	// NOTE: placeholder name
	bool unknown71bc10(const Point &p, Point *out);	// NOTE: placeholder name
	void unknown7276b0(HEntity e, int *amount);	// NOTE: placeholder name
	HItem unknown71e7c0(const Point &p, int a, int b);	// NOTE: placeholder name
	bool isReachable(int range, const Point &from, const Point &to);	// NOTE: placeholder name (0x465230)
	bool unknown71c150(const Point &a, Point &b, int size);	// NOTE: placeholder name
	int unknown714590(int &count, int &reachable);	// NOTE: placeholder name
	bool unknown463040();	// NOTE: placeholder name
	void unknown4647d0(const Point &p);	// NOTE: placeholder name
	void unknown4647a0(const Point &p, int a);	// NOTE: placeholder name
	bool unknown463160(const Point &p);	// NOTE: placeholder name
	vector<vector<class HMarker> > *unknown463ec0();	// NOTE: placeholder name
	vector<Point> *unknown463c20();	// NOTE: placeholder name (BS)
	void unknown9e29b0(vector<HProp> *list, HProp prop);	// NOTE: placeholder name
	void unknown724cf0();	// NOTE: placeholder name (BS::opw3_unknown724cf0)
	bool unknown716c30(const Point &p, Entity *e, vector<Point> *path);	// NOTE: placeholder name (BS)
	bool unknown716a60(const Point &p, int type, Entity *e, vector<Point> *path);	// NOTE: placeholder name (BS)
	void unknown729eb0(const Point &p, const string &text, int a, int b);	// NOTE: placeholder name (BS::opw3_unknown729eb0)
	void unknown734d60(const Point &p);	// NOTE: placeholder name (BS)

	char pad000[0x720];
	vector<HProp> unknown720;
};
extern Map *world;	// NOTE: placeholder name (0xcefc4c)

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Point mouse;
};

class OpW8_Interface	// NOTE: placeholder name (object at 0xcec088)
{
public:
	virtual void opw8_virtual0();	// NOTE: placeholder name
	virtual void opw8_virtual1();	// NOTE: placeholder name
	virtual void opw8_virtual2();	// NOTE: placeholder name
	virtual void opw8_virtual3();	// NOTE: placeholder name
	virtual bool input(XEvent *event);
	class CPart *unknown894e70(HItem item);	// NOTE: placeholder name
	void unknown8993e0(class CPart *part, int a);	// NOTE: placeholder name

	int unknown8985d0(int slot);	// NOTE: placeholder name
	int unknown8986c0(int slot);	// NOTE: placeholder name

	vector<struct OpW8_PartEntry *> *unknown4a9ad0();	// NOTE: placeholder name (ICF'd field address getter)
	bool unknown4a9b10(HItem item);	// NOTE: placeholder name (CParts::isLinked4a9b10)
	void unknown4a9cf0(HItem item);	// NOTE: placeholder name (CParts::confirm4a9cf0)
	void unknown4a9d40(HItem item);	// NOTE: placeholder name (CParts::confirm4a9d40)
	void unknown4a9d90(HItem item);	// NOTE: placeholder name (CParts::confirm4a9d90)

	char pad04[0x13c - 0x4];
	HItem unknown13C;
	string unknown140;
	unsigned int unknown15C;
	HItem unknown160;
	unsigned int unknown164;
	HItem unknown168;
	unsigned int unknown16C;
	HItem unknown170;
	unsigned int unknown174;
	HItem unknown178;
	unsigned int unknown17C;
	HItem unknown180;
	unsigned int unknown184;
	HItem unknown188;
	unsigned int unknown18C;
	HItem unknown190;
	unsigned int unknown194;
	unsigned int unknown198;
	unsigned int unknown19C;
	string unknown1A0;
	unsigned int unknown1BC;
	Point unknown1C0;
	int unknown898470(int value);	// NOTE: placeholder name
	bool unknown8984f0(int value);	// NOTE: placeholder name
	void unknown894120(int value);	// NOTE: placeholder name
	int unknown8983e0(int value);	// NOTE: placeholder name
};
extern OpW8_Interface *opw8_cec088;	// NOTE: placeholder name

bool opw8_unknown5111e0(int id, const string *a, const string *b, int c, HEntity d, HProp e, const Point *f, int g);	// NOTE: placeholder name

class OpW8_MsgConsole	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpW8_MsgConsole *opw8_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *opw8_logMsgs;	// NOTE: placeholder name (0xcec0b4)

class OpW8_Effect	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class OpW8_EffectMgr	// NOTE: placeholder name
{
public:
	OpW8_Effect *create();	// NOTE: placeholder name (0x508610)
};
extern OpW8_EffectMgr *opw8_effectMgr;	// NOTE: placeholder name (0xcefc50)
extern Point opw8_effectOrigin;	// NOTE: placeholder name (0xd2e20c)
extern int opw8_ba0974;	// NOTE: placeholder name
extern int opw8_table_b96048[];	// NOTE: placeholder name

void opw8_shuffle9d9fc0(vector<HItem> &v);	// NOTE: placeholder name

class OpW8_EntityPart	// NOTE: placeholder name (EntityPart4588f0)
{
public:
	int unknown458950(int type);	// NOTE: placeholder name
};

class OpW8_AI	// NOTE: placeholder name
{
public:
	bool unknown458fb0(HEntity e);	// NOTE: placeholder name
	bool unknown5b6130(Point *out);	// NOTE: placeholder name
};

class OpW8_Unk144	// NOTE: placeholder name
{
public:
	int unknown9b8f00();	// NOTE: placeholder name (ICF'd trivial getter)
	vector<Point> *unknown458ef0();	// NOTE: placeholder name
	bool unknown5810e0();	// NOTE: placeholder name
	bool unknown580c10();	// NOTE: placeholder name
	bool unknown4590b0(int type);	// NOTE: placeholder name
	int unknown9b4350();	// NOTE: placeholder name (ICF'd trivial getter)

	char pad00[0x54];
	bool unknown54;
};

class Entity	// NOTE: placeholder layout
{
public:
	bool isPlayer();
	int getAsciiDefault();	// NOTE: placeholder name (0x5c79d0)
	int unknown5c8db0();	// NOTE: placeholder name
	int unknown5d22a0(int type);	// NOTE: placeholder name
	int unknown5d2090(int type);	// NOTE: placeholder name
	int unknown5cad50();	// NOTE: placeholder name
	int unknown5d7c70();	// NOTE: placeholder name

	int unknown5c7c20(int offset, bool flag);	// NOTE: placeholder name
	int unknown5c7c80();	// NOTE: placeholder name
	int unknown5c7cb0();	// NOTE: placeholder name
	int unknown5c7cf0();	// NOTE: placeholder name
	int unknown5c7d30();	// NOTE: placeholder name
	int unknown5c7d80(bool *out);	// NOTE: placeholder name
	int unknown5c7e40();	// NOTE: placeholder name
	int unknown5c7e90();	// NOTE: placeholder name
	int unknown5c7ee0();	// NOTE: placeholder name
	int unknown5c7f10();	// NOTE: placeholder name
	int unknown5c7f40();	// NOTE: placeholder name
	int unknown5c7fa0();	// NOTE: placeholder name
	int unknown5c7fc0(HEntity other);	// NOTE: placeholder name
	int unknown5c7ff0(int value);	// NOTE: placeholder name
	bool unknown5c8020();	// NOTE: placeholder name
	bool unknown5c80a0();	// NOTE: placeholder name
	Point unknown5c80f0(const Point &p);	// NOTE: placeholder name
	bool unknown5c83d0(const Point &p, int range);	// NOTE: placeholder name
	bool unknown5c8430(const Point &origin, const Point &target, int range);	// NOTE: placeholder name
	bool unknown5c84f0(const Point &p);	// NOTE: placeholder name
	bool unknown5c85a0(const Point &p, bool large);	// NOTE: placeholder name
	bool unknown5c8710(const Point &p);	// NOTE: placeholder name
	bool unknown45aaa0(HEntity e);	// NOTE: placeholder name
	int getSize();	// NOTE: placeholder name (0x45a360)
	const Point &getPosition() throw();	// 0x45a4a0
	bool unknown45a780();	// NOTE: placeholder name
	HItem unknown5d2380(int type);	// NOTE: placeholder name
	int unknown5d2150(int type, int base);	// NOTE: placeholder name
	HItem unknown5d24e0(int type);	// NOTE: placeholder name
	HItem unknown5d25e0(int type);	// NOTE: placeholder name
	bool unknown5d26e0(int type);	// NOTE: placeholder name
	int unknown5d2770(int type);	// NOTE: placeholder name
	int unknown5d2810(int type);	// NOTE: placeholder name
	int unknown5d28f0(int type);	// NOTE: placeholder name
	int unknown5d2990(int type);	// NOTE: placeholder name
	bool unknown5d2a00(int type);	// NOTE: placeholder name
	HItem unknown5d2a90(int type);	// NOTE: placeholder name
	HItem unknown5d2b40(string name);	// NOTE: placeholder name
	HItem unknown5d2c50();	// NOTE: placeholder name
	HItem unknown5d35b0(HEntity e);	// NOTE: placeholder name
	void unknown5d3700();	// NOTE: placeholder name
	HItem unknown5d3f80(int a, int b);	// NOTE: placeholder name
	bool unknown5d4100();	// NOTE: placeholder name
	bool unknown5d4230(HEntity e);	// NOTE: placeholder name
	bool unknown5d5250();	// NOTE: placeholder name
	bool unknown5d52b0();	// NOTE: placeholder name
	bool unknown5d5320();	// NOTE: placeholder name
	bool unknown5d5460(bool active);	// NOTE: placeholder name
	bool unknown5d5520(bool active);	// NOTE: placeholder name
	bool unknown5d55e0();	// NOTE: placeholder name
	HItem unknown5d56d0(const int &key);	// NOTE: placeholder name
	HItem unknown5d5a70();	// NOTE: placeholder name
	HItem unknown5d5b20();	// NOTE: placeholder name
	HItem unknown5d5c30();	// NOTE: placeholder name
	HItem unknown5d5d40();	// NOTE: placeholder name
	bool unknown5d5df0();	// NOTE: placeholder name
	int unknown5d6240();	// NOTE: placeholder name
	bool unknown5d6480(HItem item);	// NOTE: placeholder name
	HItem unknown5d6560();	// NOTE: placeholder name
	bool unknown5d6610();	// NOTE: placeholder name
	int unknown5d66f0();	// NOTE: placeholder name
	int unknown5d6890();	// NOTE: placeholder name
	bool unknown5d7560(HItem item);	// NOTE: placeholder name
	bool unknown5d7670();	// NOTE: placeholder name
	int unknown5d7b00(bool flag);	// NOTE: placeholder name
	int unknown5d7b80();	// NOTE: placeholder name
	float unknown5d7bc0();	// NOTE: placeholder name
	float unknown5d7bf0(int type);	// NOTE: placeholder name
	bool unknown5d7d60(int value);	// NOTE: placeholder name
	bool unknown5d7df0();	// NOTE: placeholder name
	int unknown5d7e90();	// NOTE: placeholder name
	int unknown5d1d70();	// NOTE: placeholder name
	bool unknown5d9340(bool *outFlag, Point *outPos);	// NOTE: placeholder name
	int unknown5db260(int value);	// NOTE: placeholder name
	int unknown5dc700(HItem item);	// NOTE: placeholder name
	int unknown5dc440(HItem item);	// NOTE: placeholder name
	int unknown5dbb60(HItem item, int extra, bool ignoreMass, bool quiet);	// NOTE: placeholder name
	int unknown5defa0(int amount, bool notify);	// NOTE: placeholder name
	void unknown5d3830();	// NOTE: placeholder name
	unsigned int unknown5d47c0(HEntity target, vector<HItem> *out, vector<HItem> *related);	// NOTE: placeholder name
	int unknown5db5f0(HItem item, bool ignoreSlots, bool ignoreStorage, bool quiet);	// NOTE: placeholder name
	bool unknown5dc680(HItem item);	// NOTE: placeholder name
	int unknown5db3c0(HItem item, bool checkFloor, bool quiet);	// NOTE: placeholder name
	void unknown5c6d90(class OpW8_Stream *stream);	// NOTE: placeholder name (save)
	Entity(class OpW8_Stream *stream);	// NOTE: load constructor (0x5c7130)
	Entity(OpW8_EntityRecord *record_);	// 0x5c3590
	void unknown45b340(Point *p);	// NOTE: placeholder name
	const XColor &unknown5c7630();	// NOTE: placeholder name
	const XColor &unknown5c7810();	// NOTE: placeholder name
	int unknown5d6d80(vector<HItem> *items, HEntity target);	// NOTE: placeholder name
	void takeDamage(int a, int b, int c, int d, int e, int f, int g, int h, HProp i, int j, int k, int l, int m, int n);	// 0x5e5520
	void unknown5d5eb0(vector<HItem> *out, HProp target);	// NOTE: placeholder name
	void unknown5d7700(vector<HItem> *items, vector<int> *damage);	// NOTE: placeholder name
	int unknown5d7320(vector<HItem> *list, bool notify);	// NOTE: placeholder name
	int unknown5df740(int mode);	// NOTE: placeholder name
	void unknown64e7e0(HItem item);	// NOTE: placeholder name
	void unknown64da50(HItem item);	// NOTE: placeholder name
	bool unknown5c7f70();	// NOTE: placeholder name
	void unknown5dc750(HGroup newGroup);	// NOTE: placeholder name
	void unknown5dfb60(HItem item);	// NOTE: placeholder name
	void unknown5dfbd0(HItem item);	// NOTE: placeholder name
	void unknown5de800();	// NOTE: placeholder name
	void unknown5de870(int amount, bool linked);	// NOTE: placeholder name
	void unknown5de950(int amount, bool linked);	// NOTE: placeholder name
	int unknown45a810();	// NOTE: placeholder name
	int unknown5deb40(int amount);	// NOTE: placeholder name
	int unknown5ded70(int amount);	// NOTE: placeholder name
	void unknown5dea60(int amount, bool linked);	// NOTE: placeholder name
	void unknown5de480(OpW8_ItemRecord *type);	// NOTE: placeholder name
	void unknown5de640(int type, vector<OpW8_ItemRecord *> *list);	// NOTE: placeholder name
	void changePos(const Point &newPos, bool flag);
	void unknown45b090(int value);	// NOTE: placeholder name
	void unknown45b0b0();	// NOTE: placeholder name
	void unknown5dd8a0(HEntity other);	// NOTE: placeholder name
	void unknown5dd9c0(HEntity e, const Point &p);	// NOTE: placeholder name
	void unknown5ddac0(const Point &p, bool flag);	// NOTE: placeholder name
	bool unknown5ddf50(const Point &p, Array2D<int> *grid, bool *tooLarge);	// NOTE: placeholder name
	void unknown5dcc70(int faction, bool flag);	// NOTE: placeholder name
	void unknown5db180(HEntity e);	// NOTE: placeholder name
	void unknown5daf90(int type);	// NOTE: placeholder name
	int unknown5db2b0(HItem item, bool ignoreMass);	// NOTE: placeholder name
	HGroup getGroup();	// 0x45a3f0
	void changeFaction(HGroup newGroup, bool flag);
	int unknown5d15a0(bool notify);	// NOTE: placeholder name
	bool unknown5d6c30(vector<HItem> *out);	// NOTE: placeholder name
	bool unknown5d69a0();	// NOTE: placeholder name
	bool unknown5d6a80(vector<HItem> *out, const Point &p, int range);	// NOTE: placeholder name
	int unknown5d6360();	// NOTE: placeholder name
	HItem unknown5d4dd0(bool any, HItem item);	// NOTE: placeholder name
	bool unknown5d4ff0(bool any, HItem item);	// NOTE: placeholder name
	bool unknown5d4490(HEntity e);	// NOTE: placeholder name
	int getAiType();	// NOTE: placeholder name (0x45a2a0)
	OpW8_EntityRecord *getInfo();	// NOTE: placeholder name (ICF'd trivial getter 0x9b4350)
	Point unknown45a4c0();	// NOTE: placeholder name
	int unknown9b4350();	// NOTE: placeholder name (ICF'd trivial getter)
	unsigned int unknown5d2430(int type, vector<HItem> *out);	// NOTE: placeholder name
	int unknown45a8b0();	// NOTE: placeholder name
	HItem unknown5d2d60(HEntity other, int *counter);	// NOTE: placeholder name
	void unknown5da0a0();	// NOTE: placeholder name
	void unknown5cede0(int *type, int *subtype);	// NOTE: placeholder name
	void polymindPossessMe();
	int *unknown45a840();	// NOTE: placeholder name
	void unknown45b210(int value);	// NOTE: placeholder name
	void unknown637bb0();	// NOTE: placeholder name
	int unknown45acb0(int value);	// NOTE: placeholder name
	string unknown5cd670();	// NOTE: placeholder name
	int unknown5d1ee0();	// NOTE: placeholder name
	int unknown5d1da0();	// NOTE: placeholder name
	float unknown5d1e40();	// NOTE: placeholder name
	bool unknown5d2000(int type);	// NOTE: placeholder name
	bool unknown5c87f0(const Point &p);	// NOTE: placeholder name
	bool unknown5c8820(HEntity other);	// NOTE: placeholder name
	void unknown5c8880(vector<HEntity> *out);	// NOTE: placeholder name
	void unknown5c89d0(vector<Point> *out);	// NOTE: placeholder name
	void unknown5c8b10(vector<Point> *out, HEntity e);	// NOTE: placeholder name
	int unknown5c8c40(int value);	// NOTE: placeholder name
	int unknown5c8cb0();	// NOTE: placeholder name
	int unknown5c8d40(int a, int b);	// NOTE: placeholder name
	int unknown5c8d80(int factor);	// NOTE: placeholder name
	int unknown5c8e20(int *count);	// NOTE: placeholder name
	int unknown5c8ec0(int slot, bool active);	// NOTE: placeholder name
	int unknown5c8fc0(int slot, bool active);	// NOTE: placeholder name
	int unknown5c9090(int slot, bool active);	// NOTE: placeholder name
	unsigned int unknown5c9190(int slot, vector<HItem> *out, bool active);	// NOTE: placeholder name
	int unknown5c92a0(int value);	// NOTE: placeholder name
	int unknown5c92c0(int value);	// NOTE: placeholder name
	int unknown5c92e0(int slot);	// NOTE: placeholder name
	void unknown5c93d0(vector<int> *out);	// NOTE: placeholder name
	bool unknown5c97f0();	// NOTE: placeholder name
	bool unknown5c98c0(bool checkOwner, int value, bool simple);	// NOTE: placeholder name
	bool unknown5c9aa0(int percent);	// NOTE: placeholder name
	bool unknown5c9b10();	// NOTE: placeholder name
	int unknown45a880();	// NOTE: placeholder name
	int unknown5ccab0();	// NOTE: placeholder name
	int getSlotTotal();
	int unknown448fe0(int type);	// NOTE: placeholder name
	void unknown5c94e0(int slot, int value);	// NOTE: placeholder name
	void unknown5c9660(int slot);	// NOTE: placeholder name
	string unknown5c9c30();	// NOTE: placeholder name
	int unknown45a920();	// NOTE: placeholder name
	int unknown5ca750();	// NOTE: placeholder name
	int getTarget();	// 0x45a760
	bool isXomCandidate();	// NOTE: placeholder name (0x5d51a0)
	bool isHostileTo(HEntity e);
	OpW8_AI *getAI();	// NOTE: placeholder name (0x45b590)
	EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	int unknown5ca210();	// NOTE: placeholder name
	int unknown5ca260();	// NOTE: placeholder name
	int unknown5ca2b0();	// NOTE: placeholder name
	int unknown5ca380();	// NOTE: placeholder name
	int unknown5ca400();	// NOTE: placeholder name
	float unknown5ca4f0();	// NOTE: placeholder name
	int unknown5ca580();	// NOTE: placeholder name
	int unknown5ca670();	// NOTE: placeholder name
	int unknown5ca6c0();	// NOTE: placeholder name
	int unknown5ca840();	// NOTE: placeholder name
	int unknown5ca8d0();	// NOTE: placeholder name
	int unknown5ca960();	// NOTE: placeholder name
	int unknown5cab00();	// NOTE: placeholder name
	int unknown5cab30();	// NOTE: placeholder name
	int unknown5cab90();	// NOTE: placeholder name
	bool unknown5cabd0();	// NOTE: placeholder name
	bool unknown5cac90();	// NOTE: placeholder name
	int unknown5caee0();	// NOTE: placeholder name
	int unknown5cb000();	// NOTE: placeholder name
	int unknown5cb110();	// NOTE: placeholder name
	int unknown5cb220();	// NOTE: placeholder name
	bool unknown5cb260();	// NOTE: placeholder name
	int unknown5d1390();	// NOTE: placeholder name
	int unknown5d1440();	// NOTE: placeholder name
	int unknown5d14d0(int type, bool full);	// NOTE: placeholder name
	int unknown5cb570(int slot, bool flag);	// NOTE: placeholder name
	bool unknown5cb680(HGroup g);	// NOTE: placeholder name
	bool isInGroup(HGroup g);	// NOTE: placeholder name (0x5cb6b0)
	bool unknown5cb6e0(HGroup g);	// NOTE: placeholder name
	int unknown5cb760();	// NOTE: placeholder name
	int unknown5cb7a0();	// NOTE: placeholder name
	int unknown5cb7f0();	// NOTE: placeholder name
	unsigned int unknown5cb830(vector<HItem> *out);	// NOTE: placeholder name
	unsigned int unknown5cb8b0(vector<HItem> *out);	// NOTE: placeholder name
	unsigned int unknown5cb930(vector<HItem> *out);	// NOTE: placeholder name
	int unknown5cb9b0(bool flag);	// NOTE: placeholder name
	int unknown5cba50();	// NOTE: placeholder name
	int unknown5cbb10();	// NOTE: placeholder name
	int unknown5cbbb0();	// NOTE: placeholder name
	HItem unknown5cbc80();	// NOTE: placeholder name
	HItem unknown5cbd10();	// NOTE: placeholder name
	bool unknown5cbdf0(int type, bool skipProcessors, bool activeOnly);	// NOTE: placeholder name
	bool unknown5cbec0();	// NOTE: placeholder name
	bool unknown5cbf30();	// NOTE: placeholder name
	bool unknown5cbfa0();	// NOTE: placeholder name
	bool unknown5cc010();	// NOTE: placeholder name
	bool unknown5cc080(HItem item, int slot);	// NOTE: placeholder name
	bool unknown5cc120(int slot);	// NOTE: placeholder name
	int unknown5cc190(int slot);	// NOTE: placeholder name
	int getFaction() throw();	// NOTE: placeholder name (0x45a2c0)
	HItem unknown5cc460(int slot, int maxSize);	// NOTE: placeholder name
	bool unknown5cc550(vector<int> *out);	// NOTE: placeholder name
	bool unknown5cc5d0(int slot);	// NOTE: placeholder name
	bool unknown5cc6a0(int slot, HItem *out, int value);	// NOTE: placeholder name
	bool unknown5cc7c0(int slot);	// NOTE: placeholder name
	bool unknown5cc850(int slot);	// NOTE: placeholder name
	HItem unknown5cc8e0();	// NOTE: placeholder name
	int unknown5cca00();	// NOTE: placeholder name
	int unknown5ccb50(HItem item);	// NOTE: placeholder name
	int unknown5ccc00(int *out);	// NOTE: placeholder name
	int unknown5cccc0();	// NOTE: placeholder name
	bool unknown5ccef0();	// NOTE: placeholder name
	int unknown5cd0a0();	// NOTE: placeholder name
	bool unknown5cd220(HItem item);	// NOTE: placeholder name
	bool unknown5cd3e0();	// NOTE: placeholder name
	bool unknown5cd5d0();	// NOTE: placeholder name
	int unknown5cecf0(const string &name);	// NOTE: placeholder name
	bool unknown5ced30();	// NOTE: placeholder name
	int unknown45adb0(int value);	// NOTE: placeholder name
	int unknown490840();	// NOTE: placeholder name
	bool unknown5d0f60();	// NOTE: placeholder name
	bool unknown5d0fe0();	// NOTE: placeholder name
	int unknown5d1070();	// NOTE: placeholder name
	HItem unknown5d1150(HItem exclude);	// NOTE: placeholder name
	bool unknown5d1280(bool flag);	// NOTE: placeholder name
	unsigned int unknown5cd490(vector<int> *out);	// NOTE: placeholder name

	int unknown00;
	HEntity self;
	OpW8_EntityRecord *record;
	string name;	// NOTE: placeholder name
	HGroup group;	// NOTE: placeholder name
	int unknown2c;
	vector<Point> positions;	// NOTE: placeholder name
	int unknown40;
	Point unknown44;
	int unknown4C;
	int unknown50;
	int unknown54;
	int unknown58;
	float unknown5C;
	vector<int> unknown60;
	int unknown70;
	int unknown74;
	int slots[4];	// NOTE: placeholder name
	int unknown88;
	int unknown8C;
	int unknown90;
	int unknown94;
	int unknown98;
	vector<int> unknown9C;
	bool unknownAC;
	int unknownB0;
	int unknownB4;
	bool unknownB8;
	int unknownBC;
	bool unknownC0;
	int unknownC4;
	int unknownC8;
	int unknownCC;
	int unknownD0;
	int unknownD4;
	unsigned int unknownD8;
	vector<Point *> unknownDC;
	struct OpW8_EntityEC *unknownEC;	// NOTE: placeholder name
	OpW8_EntityPart *unknownF0;
	vector<int> unknownF4;
	vector<int> unknown104;
	HEntity unknown114;
	HEntity unknown118;
	int unknown11C;
	int unknown120;
	vector<int> unknown124;
	vector<HItem> parts;	// NOTE: placeholder name
	OpW8_Unk144 *unknown144;
};

extern bool asciiEnabled;	// NOTE: placeholder name (0xd28d30)
extern int opw8_table_b94998[];	// NOTE: placeholder name
extern int opw8_cf4958;	// NOTE: placeholder name
extern int opw8_cf495c;	// NOTE: placeholder name
extern int opw8_cf4960;	// NOTE: placeholder name
extern int opw8_cf4964;	// NOTE: placeholder name
extern int opw8_cf4968;	// NOTE: placeholder name
extern int opw8_cf49e0;	// NOTE: placeholder name
extern int opw8_cf49e8;	// NOTE: placeholder name
extern int opw8_cefb38;	// NOTE: placeholder name
extern bool opw8_table_ba098c[];	// NOTE: placeholder name

int Entity::unknown5c7c20(int offset, bool flag)
{
	if (asciiEnabled && flag)
	{
		if (record->type == 1)
			return record->ascii;
		else
			return record->ascii + offset;
	}
	else
		return getAsciiDefault();
}

int Entity::unknown5c7c80()
{
	return record->unknown68 + opw8_table_b94998[record->unknown24] + unknown5c8db0();
}

int Entity::unknown5c7cb0()
{
	return isPlayer() ? opw8_cf4958 : record->unknownB4;
}

int Entity::unknown5c7cf0()
{
	return isPlayer() ? opw8_cf495c : record->unknownB8;
}

int Entity::unknown5c7d30()
{
	return (isPlayer() ? opw8_cf4960 : record->unknown21C) + unknown5d22a0(10);
}

int Entity::unknown5c7d80(bool *out)
{
	if (out == 0)
	{
		return (isPlayer() ? opw8_cf4964 : record->unknown220) + opw2_maxInt(unknown5d22a0(11),unknown5d22a0(13));
	}
	else
	{
		int value = unknown5d22a0(13);
		*out = value > 0;
		if (value == 0)
			value = unknown5d22a0(11);
		return (isPlayer() ? opw8_cf4964 : record->unknown220) + value;
	}
}

int Entity::unknown5c7e40()
{
	return (isPlayer() ? opw8_cf4968 : record->unknown228) + unknown5d2090(17);
}

int Entity::unknown5c7e90()
{
	return unknown5cad50() == 2 && opw8_table_ba098c[opw8_cefb38] ? 999 : unknown5c7ee0();
}

int Entity::unknown5c7ee0()
{
	return unknown5d2090(99) + unknown5d7c70();
}

int Entity::unknown5c7f10()
{
	return (isPlayer() ? opw8_cf49e0 : 0) + unknown5d2090(121);
}

int Entity::unknown5c7f40()
{
	return (isPlayer() ? opw8_cf49e8 : 0) + unknown5d2090(122);
}

int Entity::unknown5c7fa0()
{
	return world->getTurn() - unknown2c;
}

int Entity::unknown5c7fc0(HEntity other)
{
	return world->unknown463910(group,other->group);
}

int Entity::unknown5c7ff0(int value)
{
	return world->unknown4638e0(group->unknown9b4350(),value);
}

bool Entity::unknown5c8020()
{
	return unknown45aaa0(world->getPlayer()) && group->unknown9b4350() > 1 && (unknown144 == 0 || !unknown144->unknown5810e0());
}

bool Entity::unknown5c80a0()
{
	return group.operator->() != 0 && group->unknown9b4350() == 1;
}

Point Entity::unknown5c80f0(const Point &p)
{
	if (record->type == 1)
		return positions[0];
	else if (p.x < positions[0].x)
	{
		if (p.y < positions[0].y)
			return Point(positions[0].x,positions[0].y);
		else if (p.y >= positions[0].y + record->type)
			return Point(positions[0].x,positions[0].y + record->type - 1);
		else
			return Point(positions[0].x,p.y);
	}
	else if (p.x >= positions[0].x + record->type)
	{
		if (p.y < positions[0].y)
			return Point(positions[0].x + record->type - 1,positions[0].y);
		else if (p.y >= positions[0].y + record->type)
			return Point(positions[0].x + record->type - 1,positions[0].y + record->type - 1);
		else
			return Point(positions[0].x + record->type - 1,p.y);
	}
	else
	{
		if (p.y < positions[0].y)
			return Point(p.x,positions[0].y);
		else
			return Point(p.x,positions[0].y + record->type - 1);
	}
}

bool Entity::unknown5c83d0(const Point &p, int range)
{
	for (unsigned int i = 0; i < positions.size(); i++)
	{
		if (opw8_pointDistance(positions[i],p) <= range)
			return true;
	}
	return false;
}

bool Entity::unknown5c8430(const Point &origin, const Point &target, int range)
{
	for (int cx = origin.x, i = 0; i < record->type; cx++, i++)
	{
		for (int cy = origin.y, k = 0; k < record->type; cy++, k++)
		{
			if (cells.contains(cx,cy) && opw8_distance(cx,cy,target.x,target.y) <= range)
				return true;
		}
	}
	return false;
}

bool Entity::unknown5c84f0(const Point &p)
{
	if (record->type == 1)
		return cells.contains(p);
	else
		return cells.contains(p) && p.x + record->type - 1 < cells.getWidth() && p.y + record->type - 1 < cells.getHeight();
}

bool Entity::unknown5c85a0(const Point &p, bool large)
{
	if (record->type == 1)
		return cells(p)->getEntity().isValid();
	else
	{
		for (int x = 0; x < record->type; x++)
		{
			for (int y = 0; y < record->type; y++)
			{
				if (cells(Point(p,x,y))->getEntity().isValid() && cells(Point(p,x,y))->getEntity() != self && (!large || cells(Point(p,x,y))->getEntity()->getSize() > 1))
					return true;
			}
		}
		return false;
	}
}

bool Entity::unknown5c8710(const Point &p)
{
	if (record->type == 1)
		return !cells(p)->isPassableFor(self);
	else
	{
		for (int x = 0; x < record->type; x++)
		{
			for (int y = 0; y < record->type; y++)
			{
				if (!cells(Point(p,x,y))->isPassableFor(self))
					return true;
			}
		}
		return false;
	}
}

bool Entity::unknown5c87f0(const Point &p)
{
	return unknown4373c0(unknown5c80f0(p),p);
}

bool Entity::unknown5c8820(HEntity other)
{
	return unknown4373c0(unknown5c80f0(other->getPosition()),other->unknown5c80f0(getPosition()));
}

void Entity::unknown5c8880(vector<HEntity> *out)
{
	for (int x = positions[0].x - 1; x <= positions[0].x + record->type; x++)
	{
		for (int y = positions[0].y - 1; y <= positions[0].y + record->type; y++)
		{
			if (cells.contains(x,y) && cells(x,y)->getEntity().isValid() && cells(x,y)->getEntity() != self)
				out->push_back(cells(x,y)->getEntity());
		}
	}
}

void Entity::unknown5c89d0(vector<Point> *out)
{
	for (int x = positions[0].x - 1; x <= positions[0].x + record->type; x++)
	{
		for (int y = positions[0].y - 1; y <= positions[0].y + record->type; y++)
		{
			if (cells.contains(x,y) && (cells(x,y)->getEntity().isNull() || cells(x,y)->getEntity() != self))
				out->push_back(Point(x,y));
		}
	}
}

void Entity::unknown5c8b10(vector<Point> *out, HEntity e)
{
	for (int x = positions[0].x - 1; x <= positions[0].x + record->type; x++)
	{
		for (int y = positions[0].y - 1; y <= positions[0].y + record->type; y++)
		{
			if (cells.contains(x,y) && cells(x,y)->getEntity().isNull() && cells(x,y)->isPassableFor(e))
				out->push_back(Point(x,y));
		}
	}
}

int Entity::unknown5c8c40(int value)
{
	int result = minInt(unknown50,value);
	if (unknown5d2380(0x54).isValid() && !unknown45a780())
		result++;
	result += unknown5d2090(0x6b);
	return result;
}

int Entity::unknown5c8db0()
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() == 4)
			count++;
	}
	return count;
}

int Entity::unknown5c8e20(int *count)
{
	int total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() == 4)
		{
			total += parts[i]->unknown4578c0();
			if (count != 0)
				(*count)++;
		}
	}
	return total;
}

int Entity::unknown5c8ec0(int slot, bool active)
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457880() == slot && (!active || (parts[i]->unknown457d70() && slots[parts[i]->unknown4578a0()] >= parts[i]->unknown4578c0())))
			count++;
	}
	return count;
}

int Entity::unknown5c8fc0(int slot, bool active)
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == slot && (!active || (parts[i]->unknown457d70() && slots[slot] >= parts[i]->unknown4578c0())))
			count++;
	}
	return count;
}

int Entity::unknown5c9090(int slot, bool active)
{
	int total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == slot && (!active || (parts[i]->unknown457d70() && slots[slot] >= parts[i]->unknown4578c0())))
			total += parts[i]->unknown4578c0();
	}
	return total;
}

unsigned int Entity::unknown5c9190(int slot, vector<HItem> *out, bool active)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == slot && (!active || (parts[i]->unknown457d70() && slots[parts[i]->unknown4578a0()] >= parts[i]->unknown4578c0())))
			out->push_back(parts[i]);
	}
	return out->size();
}

int Entity::unknown5c92a0(int value)
{
	return opw8_cec088->unknown898470(value);
}

int Entity::unknown5c92c0(int value)
{
	return opw8_cec088->unknown8983e0(value);
}

int Entity::unknown5c92e0(int slot)
{
	int space = slot == 4 ? sumArray(slots,4) : slots[slot];
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if ((slot == 4 || parts[i]->unknown4578a0() == slot) && parts[i]->unknown44aec0() <= 3)
			space -= parts[i]->unknown4578c0();
	}
	return space;
}

void Entity::unknown5c93d0(vector<int> *out)
{
	out->assign(4u,0);
	for (int i = 0; i < 4; i++)
		(*out)[i] = slots[i];
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() <= 3)
			(*out)[parts[i]->unknown4578a0()] -= parts[i]->unknown4578c0();
	}
}

int Entity::unknown5c8cb0()
{
	int total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() != 4)
			total += parts[i]->unknown457b30();
	}
	return total;
}

int Entity::unknown5c8d40(int a, int b)
{
	if (a > b)
	{
		int result = a / b;
		if (a % b == 0)
			result--;
		return result;
	}
	else
		return 0;
}

int Entity::unknown5c8d80(int factor)
{
	int value = unknown5d1ee0();
	return value * factor + value;
}

bool Entity::unknown5c97f0()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457f90() == 7 && parts[i]->unknown457cf0() && parts[i]->unknown457860() == "Lightpack 2.0")
			return true;
	}
	return false;
}

bool Entity::unknown5c98c0(bool checkOwner, int value, bool simple)
{
	if (checkOwner)
	{
		if (unknown144 != 0 && !unknown144->unknown580c10())
		{
			return false;
		}
		else if (unknown144 == 0 && world->unknown463710() == 0)
			return false;
	}
	if (simple)
		return unknown45a880() <= value;
	int total = unknown5ccab0();
	int base = 100;
	total -= unknown88;
	total += base;
	float rating = unknown45a880() / 100.0 * (float)(base * 100 / total);
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() != 4)
			rating += (float)(parts[i]->unknown457ca0() / 100.0) * (parts[i]->unknown577790() * 100 / total);
	}
	int emptySlots = unknown5c92e0(4);
	if (emptySlots > 1)
		rating -= (emptySlots - 1) * 10;
	return rating <= value;
}

bool Entity::unknown5c9aa0(int percent)
{
	int total = getSlotTotal();
	int empty = unknown5c92e0(4);
	int usedSlots = total - empty;
	total += unknown5ca210();
	usedSlots += unknown5c8e20(0);
	return usedSlots * 100 / total < percent;
}

// Entity::unknown5c9b10 (0x5c9b10) is defined in src/util/claude_a_5c9b10.cpp (needs nothrow-declared callees).

void Entity::unknown5c94e0(int slot, int value)
{
	opw8_playerData.loadPartSlots(0,0);
	slots[slot]++;
	opw8_slotMarkers[slot].push_back(new OpW8_SlotMarker(opw8_slotMarkers[slot].back()->index + 1,0,HProp(),0,value));
	if (slot == 0 || slot == 1 || slot == 3)
		opw8_cf4d14 = false;
	if (slot == 2 && slots[2] > 4)
		opw8_cf4d15 = false;
	if (!opw8_cec118->isHidden())
		opw8_cec118->unknown8b5080();
	if (!opw8_cec11c->isHidden())
		opw8_cec11c->unknown8b5080();
	if (!opw8_cec120->isHidden())
		opw8_cec120->unknown8b5080();
	unknown4b3540(opw8_cec034);
	opw8_cec088->unknown894120(1);
	opw8_cec08c->setPos(unknown4b33b0());
	opw8_cec138->unknown965220();
}

void Entity::unknown5c9660(int slot)
{
	if (unknown5c92e0(slot) == 0 || unknown448fe0(slot) == 1)
		return;
	slots[slot]--;
	opw8_playerData.loadPartSlots(0,0);
	for (unsigned int i = 0; i < opw8_slotMarkers[slot].size(); i++)
	{
		if (opw8_slotMarkers[slot][i]->prop.isNull() && opw8_slotMarkers[slot][i]->unknown46d2e0())
		{
			eraseAt(opw8_slotMarkers[slot],i);
			break;
		}
	}
	if (!opw8_cec118->isHidden())
		opw8_cec118->unknown8b5080();
	if (!opw8_cec11c->isHidden())
		opw8_cec11c->unknown8b5080();
	if (!opw8_cec120->isHidden())
		opw8_cec120->unknown8b5080();
	unknown4b3540(opw8_cec034);
	opw8_cec088->unknown894120(1);
	opw8_cec08c->setPos(unknown4b33b0());
	opw8_cec138->unknown965220();
}

string Entity::unknown5c9c30()
{
	string strings[9] = {"dire","terrible","bad","poor","decent","fine","good","great","wonderful"};
	int rating = 4;
	if (unknown45a880() < 25)
		rating -= 2;
	else if (unknown45a880() < 50)
		rating--;
	else if (unknown45a880() > 75)
		rating++;
	if (unknown5c8fc0(0,true) == 0)
		rating--;
	if (unknown5c8fc0(1,true) == 0)
		rating--;
	if (unknown5d15a0(0) >= 300)
		rating--;
	if (unknown5c8fc0(3,true) == 0)
		rating--;
	if (unknown5c9090(0,true) > unknown448fe0(0) && unknown5c9090(1,true) > unknown448fe0(1) && unknown5c9090(3,true) > unknown448fe0(3))
		rating++;
	int armor = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() <= 3)
			armor += parts[i]->unknown457ca0() * parts[i]->unknown4578c0();
	}
	if (armor / getSlotTotal() < 50)
		rating--;
	else if (armor / getSlotTotal() > 75)
		rating++;
	if (unknown45a920() + unknown5ca750() < 50)
		rating--;
	int enemies = 0;
	int allyCount = 0;
	Area area;
	cells.getRect(getPosition(),15,area);
	for (int x = area.min.x; x < area.max.x; x++)
	{
		for (int y = area.min.y; y < area.max.y; y++)
		{
			if (cells(x,y)->getEntity().isValid())
			{
				HEntity e = cells(x,y)->getEntity();
				if (e->getTarget() == 0 && e->isXomCandidate())
				{
					if (e->unknown45aaa0(self))
						allyCount++;
					else if (e->isHostileTo(self) && e->getAI()->unknown458fb0(self))
						enemies++;
				}
			}
		}
	}
	rating -= enemies / 8;
	rating += allyCount / 3;
	int found = 0;
	int access = 0;
	int dist = world->unknown714590(found,access);
	if (found == 0)
		rating--;
	else if (access != 0 && dist < 30)
		rating++;
	return strings[opw2_clampInt(0,rating,8)];
}

int Entity::unknown5ca210()
{
	return (isPlayer() ? opw8_cf496c : record->unknown1C8) + unknown5d22a0(7);
}

int Entity::unknown5ca260()
{
	return !isPlayer() && (opw8_cf462c != 7 || record->unknown28 != 0x49) ? record->unknown1DC : opw8_cf4954;
}

int Entity::unknown5ca2b0()
{
	float ratio = unknown8C / (double)unknown5ca260();
	if (ratio >= 0.75)
	{
		int high = opw8_d28d26 ? opw8_d35be0 : opw8_d25e0c;
		return high;
	}
	else if (ratio >= 0.4)
		return opw8_cf281c;
	else if (ratio >= 0.2)
	{
		int low = opw8_d28d26 ? opw8_d2b284 : opw8_d23094;
		return low;
	}
	else
		return opw8_d2f34c;
}

int Entity::unknown5ca380()
{
	float ratio = (float)unknown8C / record->unknown1DC;
	if (ratio >= 0.75)
		return 0;
	else if (ratio >= 0.4)
		return 1;
	else if (ratio >= 0.2)
		return 2;
	else
		return 3;
}

int Entity::unknown5ca400()
{
	int total = record->unknown28 == 0 ? opw8_cf4970 : record->unknown1E4;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() != 4 && (false || parts[i]->unknown457d70()))
			total += parts[i]->unknown457ed0();
	}
	return total + unknown5d2090(8);
}

float Entity::unknown5ca4f0()
{
	float total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0())
			total += parts[i]->unknown457df0();
	}
	return total;
}

int Entity::unknown5ca580()
{
	int total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457f90() == 8 && parts[i]->unknown44aec0() == 4 && opw8_cf4830[parts[i]->unknown457820()] != 0)
			total += parts[i]->unknown45cb30();
	}
	return total;
}

int Entity::unknown5ca670()
{
	return (isPlayer() ? opw8_cf4974 : abs(record->unknown1EC)) + unknown5d2090(9);
}

int Entity::unknown5ca6c0()
{
	int total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0())
			total += parts[i]->unknown457e10();
	}
	return total;
}

int Entity::unknown5ca750()
{
	int total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457f90() == 9 && parts[i]->unknown44aec0() == 4 && opw8_cf4830[parts[i]->unknown457820()] != 0)
			total += parts[i]->unknown45cb30();
	}
	return total;
}

int Entity::unknown5ca840()
{
	if (unknown45ac40(30))
	{
		for (int i = 5; i >= 0; i--)
		{
			if (unknown98 >= opw8_table_b960e8[i])
				return i;
		}
	}
	else
	{
		for (int j = 5; j >= 0; j--)
		{
			if (unknown98 >= opw8_table_b96100[j])
				return j;
		}
	}
	return 0;
}

int Entity::unknown5ca8d0()
{
	int total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0())
			total += parts[i]->unknown577b10();
	}
	return total;
}

int Entity::unknown5ca960()
{
	int total = !isPlayer() && (opw8_cf462c != 7 || record->unknown28 != 0x49) ? record->unknown1F0 : opw8_cf49dc;
	if (unknown5d2380(6).isValid())
	{
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == 1)
			{
				total += parts[i]->unknown457fb0() * ((parts[i]->unknown457fd0() != 0) + 1);
				if (isPlayer() && parts[i]->unknown457fd0() != 0)
					opw8_playerData.unknown77fbc0(0x7e);
			}
		}
		return total;
	}
	else
		return total + unknown5d2090(1);
}

int Entity::unknown5cab00()
{
	return unknown5ca960() + unknown5d2090(2);
}

int Entity::unknown5cab30()
{
	if (opw8_d25450 && opw8_d25564 != 0 && isPlayer())
		return minInt(-666,-unknown5d22a0(6));
	return -unknown5d22a0(6);
}

int Entity::unknown5cab90()
{
	if (unknownB0 == 0)
		return 0;
	return opw2_maxInt(0,unknownB0 - unknown5d2090(42));
}

bool Entity::unknown5cabd0()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (opw8_table_ba0968[parts[i]->unknown9b4350()->unknownEC] && parts[i]->unknown44aec0() != 4 && parts[i]->unknown457d70())
			return true;
	}
	return false;
}

bool Entity::unknown5cac90()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown9b4350()->unknownEC == 4 && parts[i]->unknown44aec0() != 4 && parts[i]->unknown457d70())
			return true;
	}
	return false;
}

int Entity::unknown5cad50()
{
	opw8_cefb38 = 0;
	int result = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown9b4350()->unknownEC != 0 && parts[i]->unknown44aec0() != 4)
		{
			switch (parts[i]->getEffectValue(0x6b))
			{
				break;	// NOTE: reproduces a dead jump in the original (likely a removed case)
				case 1:
					opw8_cefb38 = parts[i]->unknown9b4350()->unknownEC;
					result = 1;
					break;
				case 2:
					opw8_cefb38 = parts[i]->unknown9b4350()->unknownEC;
					return 2;
				case 3:
					if (result == 0)
					{
						opw8_cefb38 = parts[i]->unknown9b4350()->unknownEC;
						result = 3;
					}
					break;
			}
		}
	}
	return result;
}

int Entity::unknown5caee0()
{
	int best = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (opw8_table_ba0968[parts[i]->unknown9b4350()->unknownEC] && parts[i]->unknown44aec0() != 4 && parts[i]->getEffectValue(0x6b) == 2 && parts[i]->unknown9b4350()->unknownEC > best)
			best = parts[i]->unknown9b4350()->unknownEC;
	}
	return best;
}

int Entity::unknown5cb000()
{
	int best = 9;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown9b4350()->unknownEC != 0 && parts[i]->unknown44aec0() != 4 && parts[i]->unknown577fb0() == 1 && parts[i]->unknown577fd0() < best)
			best = parts[i]->unknown577fd0();
	}
	return best;
}

int Entity::unknown5cb110()
{
	int best = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown9b4350()->unknownEC != 0 && parts[i]->unknown44aec0() != 4 && parts[i]->unknown577fb0() == 3 && parts[i]->unknown578070() > best)
			best = parts[i]->unknown578070();
	}
	return best;
}

int Entity::unknown5cb220()
{
	int value = opw8_ba0974;
	opw8_decrease(&value,unknown5d2090(0x27),1);
	return value;
}

bool Entity::unknown5cb260()
{
	if (unknown5d2380(0x74).isValid())
		unknownBC = 0;
	else
	{
		int amount = unknown5d1ee0() - unknown5c8cb0();
		opw8_atLeast(&amount,opw8_table_b96048[unknown5d1390()]);
		unknownBC -= amount;
	}
	if (unknownBC > 0)
	{
		do
		{
			if (opw8_unknown5111e0(isPlayer() ? 0x30 : (unknown45aaa0(world->getPlayer()) ? 0x31 : 0x32),&intToString(unknownBC),0,0,self,HProp(),0,0))
				opw8_cec058->unknown8758d0(true);
			opw8_logMsgs->scrollToEnd();
		} while (0);
		int effectID;
		if (findEffectID("T_Glow_Bubble",&effectID))
		{
			for (unsigned int i = 0; i < positions.size(); i++)
			{
				if (world->opw8_isVisible(positions[i]))
					opw8_effectMgr->create()->init(opw8_effectMgr,effectID,positions[i],opw8_effectOrigin,0,0,0,9,0);
			}
		}
		return false;
	}
	else
	{
		unknownBC = 0;
		do
		{
			if (opw8_unknown5111e0(isPlayer() ? 0x33 : (unknown45aaa0(world->getPlayer()) ? 0x34 : 0x35),0,0,0,self,HProp(),0,0))
				opw8_cec058->unknown8758d0(true);
			opw8_logMsgs->scrollToEnd();
		} while (0);
		return true;
	}
}

int Entity::unknown5cb570(int slot, bool flag)
{
	if (slot >= 7)
		return 100;
	int value = unknown5d22a0(slot + 0x2f);
	value = opw2_maxInt(value,unknown5d22a0(0x36));
	value = opw2_maxInt(value,unknown5d22a0(0x66) / 2);
	if (flag && slot == 1)
		value = world->unknown7275f0(self,value);
	if (opw8_cf462c == 5 && isPlayer())
		value = opw2_maxInt(value,opw8_table_cf49a0[slot]);
	return opw2_maxInt(0,(isPlayer() ? opw8_table_cf4984[slot] : record->unknown1F4[slot]) - value);
}

bool Entity::unknown5cb680(HGroup g)
{
	return world->unknown463910(group,g) == 0;
}

bool Entity::isInGroup(HGroup g)
{
	return world->unknown463910(group,g) == 2;
}

bool Entity::unknown5cb6e0(HGroup g)
{
	return isInGroup(g) || (opw8_inRange(3,group->unknown9b4350(),4) && opw8_inRange(3,g->unknown9b4350(),4));
}

int Entity::unknown5cb760()
{
	return (100 - (isPlayer() ? opw8_cf497c : 0)) * 20 / 100;
}

int Entity::unknown5cb7a0()
{
	return opw8_cf462c == 6 ? 0 : (100 - (isPlayer() ? opw8_cf497c : 0)) * 10 / 100;
}

int Entity::unknown5cb7f0()
{
	return (100 - (isPlayer() ? opw8_cf497c : 0)) * 10 / 100;
}

unsigned int Entity::unknown5cb830(vector<HItem> *out)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() == 4)
			out->push_back(parts[i]);
	}
	return out->size();
}

unsigned int Entity::unknown5cb8b0(vector<HItem> *out)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() != 4)
			out->push_back(parts[i]);
	}
	return out->size();
}

unsigned int Entity::unknown5cb930(vector<HItem> *out)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0())
			out->push_back(parts[i]);
	}
	return out->size();
}

int Entity::unknown5cb9b0(bool flag)
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() != 4 && (!flag || !parts[i]->getEffect(0x6c)))
			count++;
	}
	return count;
}

int Entity::unknown5cba50()
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == 3 && parts[i]->unknown44aec0() != 4 && !parts[i]->getEffect(0x3b))
			count++;
	}
	return count;
}

int Entity::unknown5cbb10()
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == 3 && parts[i]->unknown457cf0())
			count++;
	}
	return count;
}

int Entity::unknown5cbbb0()
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == 3 && parts[i]->unknown457cf0() && opw8_inRange(0x14,parts[i]->unknown457880(),0x19))
			count++;
	}
	return count;
}

HItem Entity::unknown5cbc80()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() == 4)
			return parts[i];
	}
	return HItem();
}

HItem Entity::unknown5cbd10()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457f90() == 9 && parts[i]->unknown45cb30() < parts[i]->unknown457fb0())
			return parts[i];
	}
	return HItem();
}

bool Entity::unknown5cbdf0(int type, bool skipProcessors, bool activeOnly)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457820() == type)
		{
			if (skipProcessors && parts[i]->unknown44aec0() == 4)
				continue;
			if (activeOnly && !parts[i]->unknown457cf0())
				continue;
			return true;
		}
	}
	return false;
}

bool Entity::unknown5cbec0()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown5773d0(true,false))
			return true;
	}
	return false;
}

bool Entity::unknown5cbf30()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown5775a0())
			return true;
	}
	return false;
}

bool Entity::unknown5cbfa0()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown5776c0())
			return true;
	}
	return false;
}

bool Entity::unknown5cc010()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown577700())
			return true;
	}
	return false;
}

bool Entity::unknown5cc080(HItem item, int slot)
{
	return item->unknown44aec0() == 4 && item->unknown4578a0() == slot && item->unknown4578c0() == 1 && (!item->unknown415ee0() || opw8_cf4830[item->unknown457820()] == 0);
}

bool Entity::unknown5cc120(int slot)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (unknown5cc080(parts[i],slot))
			return true;
	}
	return false;
}

int Entity::unknown5cc190(int slot)
{
	if (slots[slot] == 0)
		return 0;
	switch (slot)
	{
		case 0:
			if (getFaction() == 0x22)
				return 0;
			break;
		case 2:
			if (getFaction() == 0x1b || getFaction() == 0x22)
				return 0;
			break;
		case 3:
			if ((unknown144 != 0 && unknown144->unknown9b4350() < 8) || getFaction() == 0x1b || getFaction() == 0x22 || getFaction() == 0x14 || (getFaction() == 0xe && unknown5d5d40().isValid()) || getFaction() == 0x2e)
				return 0;
			if (getFaction() == 0x1e && unknown5d5c30().isValid())
				return 0;
			if (isPlayer())
			{
				for (unsigned int i = 0; i < parts.size(); i++)
				{
					if (parts[i]->unknown44aec0() == 3 && parts[i]->unknown457d70() && !opw8_contains9db330(&opw8_d31510,parts[i]->unknown9b4350()))
						return 0;
				}
			}
			break;
	}
	int remaining = minInt(slots[slot],opw8_table_b959fc[slot]);
	if (remaining != 0)
	{
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown4578a0() == slot && parts[i]->unknown44aec0() <= 3)
			{
				remaining -= parts[i]->unknown4578c0();
				if (remaining <= 0)
					return 0;
			}
		}
	}
	return remaining;
}

HItem Entity::unknown5cc460(int slot, int maxSize)
{
	if (maxSize == 0)
		return HItem();
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == slot && parts[i]->unknown44aec0() == 4 && parts[i]->unknown4578c0() <= maxSize)
			return parts[i];
	}
	return HItem();
}

bool Entity::unknown5cc550(vector<int> *out)
{
	out->assign(4u,0u);
	if (opw8_cf462c == 0xb && opw8_cf4700 == 0)
		return false;
	for (int i = 0; i <= 3; i++)
		(*out)[i] = unknown5cc190(i);
	return opw8_anyNonZero(*out);
}

bool Entity::unknown5cc5d0(int slot)
{
	int space = slots[slot];
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == slot)
		{
			if (parts[i]->unknown44aec0() == 4)
				return false;
			else
				space -= parts[i]->unknown4578c0();
		}
	}
	return space;
}

bool Entity::unknown5cc6a0(int slot, HItem *out, int value)
{
	if (slot == 1)
	{
		int type = unknown5d1390() + 9;
		if (type == value)
			return false;
	}
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() == 4 && parts[i]->unknown4578a0() == slot && (parts[i]->unknown4578a0() != 1 || parts[i]->unknown457880() == value))
		{
			*out = parts[i];
			return true;
		}
	}
	return false;
}

bool Entity::unknown5cc7c0(int slot)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == slot && parts[i]->unknown44aec0() <= 3)
			return true;
	}
	return false;
}

bool Entity::unknown5cc850(int slot)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == slot && parts[i]->unknown44aec0() == 4)
			return true;
	}
	return false;
}

HItem Entity::unknown5cc8e0()
{
	if (record->unknown28 != 0x25 && self != world->opw8_getEntity671())
		return HItem();
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown9b4350() == opw8_cefbe8 && parts[i]->unknown457cf0() && parts[i]->unknown457cd0())
			return parts[i];
	}
	return HItem();
}

int Entity::unknown5cca00()
{
	int total = unknown88;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() != 4 && true)
			total += parts[i]->unknown577790();
	}
	return unknown88 * 100 / total;
}

int Entity::unknown5ccab0()
{
	int total = unknown88;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() != 4 && true)
			total += parts[i]->unknown577790();
	}
	return total;
}

int Entity::unknown5ccb50(HItem item)
{
	int total = unknown88;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() != 4 && true)
			total += parts[i]->unknown577790();
	}
	return item->unknown577790() * 100 / total;
}

int Entity::unknown5ccc00(int *out)
{
	*out = 1;
	int total = *out;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() <= 3 && !parts[i]->getEffect(0x54))
			total += parts[i]->unknown4578c0();
	}
	return total;
}

int Entity::unknown5cccc0()
{
	int total = 0;
	int bonus = 0;
	int value;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457880() == 5)
			value = 1;
		else
			value = parts[i]->unknown457900();
		if (value == 10)
			value += 2;
		switch (parts[i]->unknown9b4350()->unknown94)
		{
			case 1:
				value++;
				break;
			case 2:
				value++;
				break;
			case 3:
				value += 2;
				break;
		}
		value *= parts[i]->unknown9b4350()->unknown4C;
		if (parts[i]->unknown9b4350()->unknownF0 == 0x66)
			value += 0x78;
		if (parts[i]->unknown44aec0() != 4)
			total += value;
		else
			bonus += value;
	}
	total = bonus * 0.1 + total;
	if (record->unknown68 != 0)
	{
		total += record->unknown1DC / 5;
		if (record->name == "Tracker")
			total += 0x28;
		else if (record->name == "Sigix Warrior")
			total += 1000;
	}
	return total;
}

bool Entity::unknown5ccef0()
{
	int score = 0;
	int procScore = 0;
	int value;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457880() == 5)
			value = 1;
		else
			value = parts[i]->unknown457900();
		if (value == 10)
			value += 2;
		switch (parts[i]->unknown9b4350()->unknown94)
		{
			case 1:
				value++;
				break;
			case 2:
				value++;
				break;
			case 3:
				value += 2;
				break;
		}
		value *= parts[i]->unknown9b4350()->unknown4C;
		if (parts[i]->unknown9b4350()->unknownF0 == 0x66)
			return false;
		if (parts[i]->unknown44aec0() != 4)
			score += value;
		else
			procScore += value;
	}
	return procScore > score;
}

int Entity::unknown5cd0a0()
{
	int total = 0;
	int value;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() == 4)
			break;
		value = parts[i]->unknown457900();
		if (value == 10)
			value += 2;
		switch (parts[i]->unknown9b4350()->unknown94)
		{
			case 1:
				value++;
				break;
			case 2:
				value++;
				break;
			case 3:
				value += 2;
				break;
		}
		value *= parts[i]->unknown9b4350()->unknown4C;
		total += value;
	}
	if (record->unknown68 != 0)
	{
		total += record->unknown1DC / 5;
		if (record->name == "Tracker")
			total += 0x28;
	}
	return total;
}

bool Entity::unknown5cd220(HItem item)
{
	if (item->unknown4578a0() == 1)
	{
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown457cf0() && parts[i]->unknown4578a0() == 1 && parts[i]->unknown457880() != item->unknown457880())
				return true;
		}
	}
	else if (item->unknown457880() >= 0x1a)
	{
		for (unsigned int j = 0; j < parts.size(); j++)
		{
			if (parts[j] != item && parts[j].isValid() && parts[j]->unknown457cf0() && parts[j]->unknown457880() >= 0x1a)
				return true;
		}
	}
	return false;
}

bool Entity::unknown5cd3e0()
{
	if (!cells(getPosition())->unknown66aed0())
		return true;
	else
	{
		const int shortDelay = 3000;
		const int longDelay = 10000;
		if (opw8_tickCount >= unknownD8 + longDelay)
		{
			unknownD8 = opw8_tickCount;
			return true;
		}
		else if (opw8_tickCount >= unknownD8 + shortDelay)
		{
			unknownD8 = opw8_tickCount - shortDelay;
			return opw8_unknown437320(500);
		}
		else
			return true;
	}
}

unsigned int Entity::unknown5cd490(vector<int> *out)
{
	if (unknown45ac40(0x14))
		out->push_back(0);
	if (unknown45ac40(0x15))
		out->push_back(1);
	if (unknown45ac40(0x13))
		out->push_back(2);
	if (unknown45ac40(0x16))
		out->push_back(3);
	if (record->unknownAC == 2 || unknown45ac40(0x25))
		out->push_back(5);
	else if (record->unknownAC == 1)
		out->push_back(4);
	if (unknown45ac40(0x20))
		out->push_back(6);
	if (unknown45ac40(0x1e))
		out->push_back(7);
	return out->size();
}

bool Entity::unknown5cd5d0()
{
	return unknown45ac40(0xd) || unknown45ac40(0xe) || unknown45ac40(0xf) || unknown45ac40(0x19) || unknown45ac40(0x1a) || unknown45ac40(0x1b) || unknown45ac40(0x18) || unknown45ac40(0x10) || unknown45ac40(0x12);
}

int Entity::unknown5cecf0(const string &name)
{
	struct OpW8_Talk *talk;
	opw8_lookup9d7de0(&opw8_vec_d2c408,name,talk);
	if (talk != 0)
		return unknown45adb0(*(int *)talk);
	else
		return 0;
}

bool Entity::unknown5ced30()
{
	for (unsigned int i = 0; i < positions.size(); i++)
	{
		if (cells(positions[i])->unknown45dd40(0xb) && cells(positions[i])->getProp()->unknown44b020()->unknown65cf80())
			return true;
	}
	return false;
}

bool Entity::unknown5d0f60()
{
	return unknown490840() < unknown5ca260() && (record->unknown24 == 1 || record->unknown24 == 3) && record->unknown28 != 0x2e && record->unknown28 != 0x2f && record->unknown28 != 0x2c && record->unknown28 != 0x2d;
}

bool Entity::unknown5d0fe0()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() == 4 && !parts[i]->getEffect(0x41))
			return true;
	}
	return false;
}

int Entity::unknown5d1070()
{
	int base = isPlayer() ? opw8_cf49d8 : record->unknown1E8;
	int total = base;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0())
			total += parts[i]->unknown577bd0();
	}
	total += (total - base) * unknown5d2090(0x21) / 100;
	return total;
}

HItem Entity::unknown5d1150(HItem exclude)
{
	vector<HItem> list;
	unknown5cb930(&list);
	opw8_shuffle9d9fc0(list);
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (list[i]->unknown4578a0() == 0 && list[i]->unknown9b4350()->unknown1A8 != 0 && list[i] != exclude)
			return list[i];
	}
	return HItem();
}

bool Entity::unknown5d1280(bool flag)
{
	if (isPlayer())
		return flag ? false : (unknown5cad50() && opw8_table_ba0984[opw8_cefb38]);
	else
	{
		if (unknown5d1390() == 6 && opw8_cf462c != 6 && (opw8_cf462c != 7 || record->unknown28 != 0x49))
			return true;
		return flag ? false : ((unknown5cad50() && opw8_table_ba0984[opw8_cefb38]) || (unknownF0 != 0 && unknownF0->unknown458950(0x34)));
	}
}

int Entity::unknown5d1390()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown4578a0() == 1)
			return parts[i]->unknown457880() - 9;
	}
	return 6;
}

int Entity::unknown5d1440()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == 1)
			return parts[i]->unknown457880() - 9;
	}
	return 6;
}

int Entity::unknown5d14d0(int type, bool full)
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457880() == type)
			count += full ? parts[i]->unknown4578c0() : 1;
	}
	return count;
}

int Entity::unknown5d1da0()
{
	int total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0())
			total += parts[i]->unknown577df0();
	}
	if (total != 0)
		return total;
	else
		return 0;
}

float Entity::unknown5d1e40()
{
	float total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0())
			total += parts[i]->unknown577d80();
	}
	if (total != 0)
		return total;
	else
		return 1;
}

int Entity::unknown5d1ee0()
{
	int total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0())
			total += parts[i]->unknown577e60();
	}
	if (total != 0)
		return (isPlayer() ? total + opw8_cf4978 : total) + record->unknown1E0 + unknown5d22a0(0x22);
	else
		return (isPlayer() ? opw8_cf4978 + 3 : 3) + record->unknown1E0 + unknown5d22a0(0x22);
}

bool Entity::unknown5d2000(int type)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown9b4350()->unknownEC == type && parts[i]->unknown44aec0() != 4)
			return true;
	}
	return false;
}

int Entity::unknown5d2090(int type)
{
	int total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == type)
			total += parts[i]->unknown457fb0();
	}
	return total;
}

int Entity::unknown5d2150(int type, int base)
{
	int highest = base;
	int second = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == type && parts[i]->unknown457fb0() > second)
		{
			if (parts[i]->unknown457fb0() > highest)
			{
				second = highest;
				highest = parts[i]->unknown457fb0();
			}
			else
				second = parts[i]->unknown457fb0();
		}
	}
	return second / 2 + highest;
}

int Entity::unknown5d22a0(int type)
{
	int highest = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == type && parts[i]->unknown457fb0() > highest)
			highest = parts[i]->unknown457fb0();
	}
	return highest;
}

HItem Entity::unknown5d2380(int type)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == type)
			return parts[i];
	}
	return HItem();
}

unsigned int Entity::unknown5d2430(int type, vector<HItem> *out)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == type)
			out->push_back(parts[i]);
	}
	return out->size();
}

HItem Entity::unknown5d24e0(int type)
{
	HItem best;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == type && (best.isNull() || parts[i]->unknown457fb0() > best->unknown457fb0()))
			best = parts[i];
	}
	return best;
}

HItem Entity::unknown5d25e0(int type)
{
	HItem best;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == type && (best.isNull() || parts[i]->unknown457fb0() < best->unknown457fb0()))
			best = parts[i];
	}
	return best;
}

bool Entity::unknown5d26e0(int type)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457f90() == type && parts[i]->unknown44aec0() != 4)
			return true;
	}
	return false;
}

int Entity::unknown5d2770(int type)
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457f90() == type && parts[i]->unknown44aec0() != 4)
			count++;
	}
	return count;
}

int Entity::unknown5d2810(int type)
{
	int highest = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457f90() == type && parts[i]->unknown44aec0() != 4 && parts[i]->unknown457fb0() > highest)
			highest = parts[i]->unknown457fb0();
	}
	return highest;
}

int Entity::unknown5d28f0(int type)
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == type)
			count++;
	}
	return count;
}

int Entity::unknown5d2990(int type)
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457f90() == type)
			count++;
	}
	return count;
}

bool Entity::unknown5d2a00(int type)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (!parts[i]->unknown457d10() && parts[i]->unknown457f90() == type)
			return true;
	}
	return false;
}

HItem Entity::unknown5d2a90(int type)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (!parts[i]->unknown457d10() && parts[i]->unknown457f90() == type)
			return parts[i];
	}
	return HItem();
}

HItem Entity::unknown5d2b40(string name)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457d70() && parts[i]->unknown457860() == name)
			return parts[i];
	}
	return HItem();
}

HItem Entity::unknown5d2c50()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() != 4 && parts[i]->unknown457cf0() && parts[i]->unknown457f90() == 0x7a && rng.chance(parts[i]->unknown457fb0() * 2))
			return parts[i];
	}
	return HItem();
}

HItem Entity::unknown5d35b0(HEntity e)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() != 4 && parts[i]->unknown457f90() == 0xa7 && parts[i]->unknown458080() == e->unknown9b4350() && parts[i]->unknown457d70() && parts[i]->unknown44ab90() <= world->getTurn())
			return parts[i];
	}
	return HItem();
}

void Entity::unknown5d3700()
{
	vector<Point> adjacent;
	sweepGetSurroundingCells(unknown45a4c0(),adjacent);
	for (unsigned int i = 0; i < adjacent.size(); i++)
	{
		if (cells(adjacent[i])->isMachinePart())
		{
			OpW8_Zone *zone = world->getZone(adjacent[i]);
			if (!zone->machine->identified)
			{
				world->unknown71dd30(zone->machine);
				zone->unknown6c16d0("IDENTIFIED");
				opw8_cec054->unknown80e3a0(1,zone);
			}
		}
	}
}

HItem Entity::unknown5d3f80(int a, int b)
{
	if (a != opw8_caf164 || b != opw8_caf160)
	{
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == 0x7b)
			{
				if (a != opw8_caf164)
				{
					if (parts[i]->unknown457820() == opw8_d2d1c4[a]->unknown1F0)
						return parts[i];
				}
				else if (parts[i]->unknown457820() == opw8_d25de0[b]->unknownF8)
					return parts[i];
			}
		}
	}
	return HItem();
}

bool Entity::unknown5d4100()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == 0x7c && parts[i]->getName(0,0).find("Relay Coupler [NC]") != string::npos)
			return true;
	}
	return false;
}

bool Entity::unknown5d4230(HEntity e)
{
	int faction = e->getFaction();
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == 0x7c)
		{
			switch (parts[i]->unknown457fb0())
			{
				case 0:
					if (e->getAiType() != 2 && parts[i]->getName(0,0).find(opw8_factionNames[faction]) != string::npos)
						return true;
					break;
				case 1:
					if (faction == 9 || faction == 12 || faction == 19 || faction == 20 || faction == 29 || faction == 6 || faction == 4 || faction == 2 || faction == 5 || faction == 8)
						return true;
					break;
				case 2:
					if (e->getAiType() == 2)
						break;
					if (faction == 13 || faction == 16 || faction == 17 || faction == 18)
						return true;
					break;
				case 3:
					if (e->getAiType() == 2 && e->getInfo()->unknownAC == 0)
						return true;
					break;
			}
		}
	}
	return false;
}

bool Entity::unknown5d4490(HEntity e)
{
	int faction = e->getFaction();
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == 0x7c)
		{
			switch (parts[i]->unknown457fb0())
			{
				case 0:
					if (e->getAiType() != 2 && parts[i]->getName(0,0).find(opw8_factionNames[faction]) != string::npos)
						return true;
					break;
				case 2:
					if (e->getAiType() == 2)
						break;
					if (faction == 13 || faction == 16 || faction == 17 || faction == 18)
						return true;
					break;
				case 3:
					if (e->getAiType() == 2 && e->getInfo()->unknownAC == 0)
						return true;
					break;
			}
		}
	}
	return false;
}

void opw8_insertItem(vector<HItem> *v, int index, HItem item);	// NOTE: placeholder name (0x9d8fc0)

void opw8_sortParts(vector<HItem> *in, vector<HItem> *out)	// NOTE: placeholder name (0x5d46a0)
{
	out->push_back(in->front());
	for (unsigned int i = 1; i < in->size(); i++)
	{
		if ((*in)[i]->unknown45cb30() >= out->front()->unknown45cb30())
			opw8_insertItem(out,0,(*in)[i]);
		else
		{
			for (int j = out->size() - 1; j >= 0; j--)
			{
				if ((*in)[i]->unknown45cb30() < (*out)[j]->unknown45cb30())
				{
					opw8_insertItem(out,j + 1,(*in)[i]);
					break;
				}
			}
		}
	}
}

HItem Entity::unknown5d4dd0(bool any, HItem item)
{
	bool player = isPlayer();
	HItem weakest;
	float threshold = player ? opw8_bba054 : opw8_ba09dc;
	if (any || item->unknown9b4350()->unknown94 == 0)
	{
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown44aec0() <= 3 && parts[i]->unknown457880() == item->unknown457880() && (parts[i]->unknown9b4350()->unknown94 == 0 || any) && parts[i]->unknown9b6bf0() < (int)(parts[i]->unknown457c80() * threshold) && (weakest.isNull() || parts[i]->unknown9b6bf0() < weakest->unknown9b6bf0()) && parts[i]->unknown5773d0(player,false))
				weakest = parts[i];
		}
	}
	return weakest;
}

bool Entity::unknown5d4ff0(bool any, HItem item)
{
	return item->unknown4578a0() == 3 && item->unknown457880() != 0x18 && item->unknown457880() != 0x19 && item->unknown457880() != 0x1d && item->unknown457880() != 0x1e && item->unknown4578c0() == 1 && item->unknown457d70() && !item->unknown457db0() && (item->unknown9b4350()->unknown94 == 0 || any) && (opw8_cf4830[item->unknown457820()] != 0 || !isPlayer()) && (record->unknown28 == 0x2e ? !isXomCandidate() : (isPlayer() && opw8_cec088->unknown8984f0(3) ? false : unknown5c92e0(3) > 0));
}

bool Entity::isXomCandidate()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown4578a0() == 3 && !parts[i]->getEffect(0x3b))
			return true;
	}
	return false;
}

bool Entity::unknown5d5250()
{
	return unknown144 != 0 && unknown144->unknown9b4350() >= 6 && !isXomCandidate() && record->unknown28 != 6;
}

bool Entity::unknown5d52b0()
{
	if (getTarget() == 5)
		return false;
	return unknown5d5250() || (unknown144 != 0 && record->unknown28 == 0x1d && unknown144->unknown4590b0(0x2d));
}

bool Entity::unknown5d5320()
{
	if (unknown144 == 0 || unknown144->unknown9b4350() < 6 || record->unknown28 == 6)
		return false;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() == 3 && !parts[i]->getEffect(0x3b))
		{
			if (parts[i]->unknown457cf0() || (parts[i]->unknown457d70() && parts[i]->unknown44ab90() >= 0))
				return false;
		}
	}
	return true;
}

bool Entity::unknown5d5460(bool active)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if ((!active || parts[i]->unknown457cf0()) && parts[i]->unknown4578a0() == 3 && parts[i]->getEffect(0x3c))
			return true;
	}
	return false;
}

bool Entity::unknown5d5520(bool active)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if ((!active || parts[i]->unknown457cf0()) && parts[i]->unknown4578a0() == 3 && parts[i]->getEffect(0x3d))
			return true;
	}
	return false;
}

bool Entity::unknown5d55e0()
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if ((parts[i]->unknown4578a0() == 2 && parts[i]->getEffect(0x3e)) || (parts[i]->unknown4578a0() == 3 && parts[i]->getEffect(0x3b)))
			count++;
	}
	return count >= 2;
}

HItem Entity::unknown5d56d0(const int &key)
{
	HItem found;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457f90() == 0xa6 && parts[i]->unknown44aec0() <= 3 && !parts[i]->unknown457d10() && !parts[i]->unknown458220() && parts[i]->unknown45cb30() < parts[i]->unknown457fb0() && parts[i]->getEffectValue(0x51) == key)
		{
			if (found.isNull())
				found = parts[i];
			else if (parts[i]->unknown457cf0() && !found->unknown457cf0())
				found = parts[i];
		}
	}
	if (found.isNull())
	{
		for (unsigned int j = 0; j < parts.size(); j++)
		{
			if (parts[j]->unknown457f90() == 0xa6 && parts[j]->unknown44aec0() <= 3 && !parts[j]->unknown457d10() && !parts[j]->unknown458220() && parts[j]->unknown457fb0() != 0 && parts[j]->unknown45cb30() == 0)
			{
				if (found.isNull())
					found = parts[j];
				else if (parts[j]->unknown457cf0() && !found->unknown457cf0())
					found = parts[j];
			}
		}
	}
	return found;
}

HItem Entity::unknown5d5a70()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown4578a0() == 3)
			return parts[i];
	}
	return HItem();
}

HItem Entity::unknown5d5b20()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() == 3 && parts[i]->unknown457880() < 0x1a && parts[i]->unknown457d70() && (unknown144 == 0 || !parts[i]->getEffect(0x3b)))
			return parts[i];
	}
	return HItem();
}

HItem Entity::unknown5d5c30()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() == 3 && parts[i]->unknown457880() >= 0x1a && parts[i]->unknown457d70() && (unknown144 == 0 || !parts[i]->getEffect(0x3b)))
			return parts[i];
	}
	return HItem();
}

HItem Entity::unknown5d5d40()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457880() >= 0x1a)
			return parts[i];
	}
	return HItem();
}

bool Entity::unknown5d5df0()
{
	bool found = false;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0())
		{
			if (parts[i]->unknown457880() >= 0x1a)
				found = true;
			else if (parts[i]->unknown457880() >= 0x14)
				return false;
		}
	}
	return found;
}

int Entity::unknown5d6240()
{
	int total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if ((parts[i]->unknown457cf0() || (parts[i]->unknown44aec0() == 3 && parts[i]->unknown457d70())) && opw8_inRange(0x1a,parts[i]->unknown457880(),0x1c))
			total += parts[i]->unknown4578c0();
	}
	return total;
}

int Entity::unknown5d6360()
{
	int total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if ((parts[i]->unknown457cf0() || (parts[i]->unknown44aec0() == 3 && parts[i]->unknown457d70())) && opw8_inRange(0x14,parts[i]->unknown457880(),0x19))
			total += parts[i]->unknown4578c0();
	}
	return total;
}

bool Entity::unknown5d6480(HItem item)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == 3 && !parts[i]->getEffect(0x3b) && parts[i]->unknown457d70() && parts[i] != item)
			return true;
	}
	return false;
}

HItem Entity::unknown5d6560()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457f90() == 0x77 && parts[i]->unknown44aec0() != 4)
			return parts[i];
	}
	return HItem();
}

bool Entity::unknown5d6610()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown4578a0() == 3 && parts[i]->unknown4580c0() >= 1 && parts[i]->unknown457f90() != 0xcf)
			return true;
	}
	return false;
}

int Entity::unknown5d66f0()
{
	unsigned int most = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown4578a0() == 3 && !parts[i]->unknown9b4350()->unknown13C.empty() && parts[i]->unknown457f90() != 0xcf)
		{
			if (parts[i]->unknown9b4350()->unknown13C.front() == -1)
			{
				return -1;
			}
			else if (parts[i]->unknown9b4350()->unknown13C.size() > most)
				most = parts[i]->unknown9b4350()->unknown13C.size();
		}
	}
	return most;
}

int Entity::unknown5d6890()
{
	int best = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown4578a0() == 3 && parts[i]->unknown9b4350()->unknown11C > best && parts[i]->unknown457f90() != 0xcf)
			best = parts[i]->unknown9b4350()->unknown11C;
	}
	return best;
}

bool Entity::unknown5d69a0()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown9b4350()->unknown164 && parts[i]->unknown457cf0() && parts[i]->unknown4578a0() == 3 && parts[i]->unknown457f90() != 0xcf)
			return true;
	}
	return false;
}

void opw8_moveElement(vector<HItem> *v, unsigned int to, unsigned int from);	// NOTE: placeholder name (0x9d9530)

bool Entity::unknown5d6a80(vector<HItem> *out, const Point &p, int range)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown4578a0() == 3 && parts[i]->unknown457880() < 0x1a)
		{
			if (parts[i]->unknown4580a0() >= (range == -1 ? opw8_pointDistance(unknown5c80f0(p),p) : range) && parts[i]->unknown457f90() != 0xcf)
			{
				out->push_back(parts[i]);
				if (parts[i]->unknown4580c0() >= 1)
				{
					if (out->size() > 1)
						opw8_moveElement(out,0,out->size() - 2);
					return true;
				}
			}
		}
	}
	return false;
}

bool Entity::unknown5d6c30(vector<HItem> *out)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown4578a0() == 3 && parts[i]->unknown457880() < 0x1a && parts[i]->unknown457f90() != 0xcf)
		{
			out->push_back(parts[i]);
			if (parts[i]->unknown4580c0() >= 1)
			{
				if (out->size() > 1)
					opw8_moveElement(out,0,out->size() - 2);
				return true;
			}
		}
	}
	return false;
}

bool Entity::unknown5d7560(HItem item)
{
	if (item->unknown457f90() == 0xcf)
		return false;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i] != item && opw8_inRange(0x14,parts[i]->unknown457880(),0x19) && parts[i]->unknown457f90() != 0xcf)
			return false;
	}
	return true;
}

bool Entity::unknown5d7670()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == 0x77)
			return true;
	}
	return false;
}

extern HEntity opw8_cf6984;	// NOTE: placeholder name
extern HEntity opw8_cf69a8;	// NOTE: placeholder name

int Entity::unknown5d7b00(bool flag)
{
	int extra = unknown5cbbb0() - 1;
	if (extra > 0)
		extra *= unknown5d2090(0x56);
	else
		extra = 0;
	return unknown5d2090(0x55) + unknown5d2090(0x61) + extra + (flag ? unknown5d22a0(0x5e) : 0);
}

int Entity::unknown5d7b80()
{
	return unknown5d2090(0x5a) - unknown5d2150(0x6a,0) / 5 + unknown5d22a0(0x5e);
}

float Entity::unknown5d7bc0()
{
	return unknown5d22a0(0x6e) / 100.0 + opw8_b96580;
}

float Entity::unknown5d7bf0(int type)
{
	float factor = type == 6 ? opw8_caf22c * opw8_caf230 : opw8_caf22c;
	return 1 + minInt(0x4b0,unknown5c8c40(3) * unknown5d1d70()) / 1200.0 * factor;
}

int Entity::unknown5d7c70()
{
	int total = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown4578a0() == 1)
		{
			if (parts[i]->unknown457880() - 9 == 0)
				total += parts[i]->unknown4578c0();
			else
				return 0;
		}
	}
	return total;
}

bool Entity::unknown5d7d60(int value)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == 3 && parts[i]->unknown9b4350()->unknown128 != value)
			return false;
	}
	return true;
}

bool Entity::unknown5d7df0()
{
	return record->unknown13C != 0 && getTarget() == 0 && (opw8_cf68b4 == 0 || opw8_cf68b4->unknown110 != 2 || (opw8_cf6984 != self && opw8_cf69a8 != self)) && unknown5cb9b0(0) != 0;
}

int Entity::unknown5d7e90()
{
	return world->unknown4638e0(0,group->unknown9b4350()) == 2 ? record->unknown140 : record->unknown13C;
}

extern bool opw8_deadAsciiEnabled;	// NOTE: placeholder name (0xcf4a00)
extern int opw8_cefc68;	// NOTE: placeholder name

int Entity::unknown5d1d70()
{
	return (int)(100.0 / unknown5d15a0(0) * 100.0);
}

int Entity::getAsciiDefault()
{
	if (opw8_deadAsciiEnabled && isPlayer())
		return 'X';
	return record->unknown459ca0();
}

bool Entity::unknown5d9340(bool *outFlag, Point *outPos)
{
	bool flag = unknown5cb9b0(0);
	Point position(getPosition());
	Point target(position);
	if (flag && !world->unknown71c150(target,target,1))
		return false;
	if (outFlag != 0)
		*outFlag = flag;
	if (outPos != 0)
		*outPos = target;
	return true;
}

int Entity::unknown5db260(int value)
{
	int threshold = (int)(unknown5d1e40() * value);
	if (unknown90 < threshold)
	{
		opw8_cefc68 = threshold;
		return 1;
	}
	else
		return 0;
}

int Entity::unknown5dc700(HItem item)
{
	if (!item->unknown457cf0())
	{
		return 0x2d;
	}
	else if (item->unknown457ad0())
	{
		return 0x2e;
	}
	else
		return 0;
}

void Entity::unknown5dcc70(int faction, bool flag)
{
	changeFaction(world->unknown463890(faction),flag);
}

extern float opw8_ba8550;	// NOTE: placeholder name
extern float opw8_ba8554;	// NOTE: placeholder name

void Entity::unknown5db180(HEntity e)
{
	if (e.isNull() || world->unknown4638e0(3,e->getGroup()->unknown9b4350()) != 0)
		opw8_playerData.addPolymindSuspicion(opw8_ba8550,0x14,HItem());
	else if (e->getGroup()->unknown9b4350() > 1 && world->unknown463400(e))
		opw8_playerData.addPolymindSuspicion(opw8_ba8554,0x15,HItem());
}

int Entity::unknown5db2b0(HItem item, bool ignoreMass)
{
	if (cells(positions[0])->getItem().isNull())
		return 2;
	switch (cells(positions[0])->getItem()->unknown457880())
	{
		case 0:
			return 3;
		case 1:
			return 4;
		case 2:
			return 5;
		case 3:
			if (opw8_cf462c == 0xb)
				return 6;
			break;
	}
	if (!ignoreMass && unknown5c8e20(0) + item->unknown4578c0() > unknown5ca210())
	{
		return 7;
	}
	else
		return 0;
}

extern float opw8_cf46f8;	// NOTE: placeholder name
extern int opw8_cf4718;	// NOTE: placeholder name
extern float opw8_ba8500[];	// NOTE: placeholder name
extern float opw8_ba8374[];	// NOTE: placeholder name

void Entity::unknown5daf90(int type)
{
	if (opw8_cf46f8 < 100.0)
	{
		Point position = getPosition();
		vector<HEntity> *members = world->unknown463890(3)->getMembers();
		int dist;
		for (unsigned int i = 0; i < members->size(); i++)
		{
			if ((*members)[i]->getInfo()->unknown144 != 0 && (*members)[i]->getTarget() == 0)
			{
				dist = opw8_pointDistance((*members)[i]->getPosition(),position);
				if (dist <= 16 && dist <= (*members)[i]->unknown5c7d30() && world->isReachable((*members)[i]->unknown5c7d30(),(*members)[i]->getPosition(),position))
				{
					opw8_playerData.addPolymindSuspicion(opw8_ba8500[type] * (*members)[i]->getInfo()->unknown144 * opw8_ba8374[opw8_cf4718],type,(*members)[i]);
					if (opw8_cf46f8 >= 100.0)
						break;
				}
			}
		}
	}
}

int Entity::unknown5dc440(HItem item)
{
	if (item->unknown457cf0())
		return 0x23;
	if (item->unknown415ee0())
		return 0x24;
	if (item->unknown457d30())
		return 0x26;
	if (item->unknown457d50())
		return 0x27;
	if (item->getEffectValue(0x47) == -1)
		return 0x28;
	if (item->unknown577940())
		return 0x29;
	if (world->getTurn() < item->unknown44ab90())
		return 0x25;
	if (unknown144 != 0 && item->getEffect(0x3b) != 0)
		return 0x2a;
	if (item->getEffect(0x52) != 0)
		return 0x2b;

	if (item->unknown4578a0() == 1 && unknown5cad50())
	{
		switch (opw8_cefb38)
		{
			case 1:
			case 2:
				if (item->unknown457880() != 9)
					return 0x1f;
				break;
			case 3:
				if (item->unknown457880() != 0xa)
					return 0x20;
				break;
			case 4:
				if (item->unknown457880() != 0xa)
					return 0x21;
				break;
		}
	}

	if (item->unknown4578a0() == 1 && item->unknown457880() != 0xa && opw8_deadAsciiEnabled && isPlayer())
		return 0x2c;
	return 0;
}

void Entity::unknown5dd8a0(HEntity other)
{
	Point pos(positions[0]);
	for (unsigned int i = 0; i < positions.size(); i++)
		cells(positions[i])->clearEntity();
	for (unsigned int i = 0; i < other->positions.size(); i++)
		cells(other->positions[i])->clearEntity();
	changePos(other->getPosition(),false);
	other->changePos(pos,false);
	other->unknown45b090(0);
	other->unknown45b0b0();
	unknown45b090(0);
	unknown50 = 0;
}

extern bool opw8_d28e27;	// NOTE: placeholder name

void Entity::unknown5dd9c0(HEntity e, const Point &p)
{
	if (e->group->unknown9b4350() == 0 || world->unknown463510(e) || world->unknown4635c0(e))
	{
		world->unknown72e4c0(e,true);
		if (e->isPlayer())
		{
			opw8_cec054->unknown49ac50();
			if (opw8_d28e27)
				opw8_cec054->unknown8069e0(p,0);
		}
		else if (e == opw8_cec054->unknown4b1b30() && opw8_d28e27)
			opw8_cec054->unknown8069e0(p,0);
	}
}

class OpW8_D1d9c0	// NOTE: placeholder name
{
public:
	void unknown49b870();	// NOTE: placeholder name
};
extern OpW8_D1d9c0 opw8_d1d9c0;	// NOTE: placeholder name

void Entity::unknown5ddac0(const Point &p, bool flag)
{
	changePos(p,true);
	unknown45b090(0);
	unknown45b0b0();
	if (group->unknown9b4350() == 0 || world->unknown463510(self) || world->unknown4635c0(self))
	{
		world->unknown72e4c0(self,true);
		if (isPlayer())
		{
			opw8_cec054->unknown49ac50();
			if (flag)
				opw8_d1d9c0.unknown49b870();
			if (opw8_d28e27)
				opw8_cec054->unknown8069e0(p,0);
		}
		else if (self == opw8_cec054->unknown4b1b30() && opw8_d28e27)
			opw8_cec054->unknown8069e0(p,0);
	}
}

bool opw8_removePoint(vector<Point> &v, Point p);	// NOTE: placeholder name (0x9d3060)
void opw8_erasePointStepBack(vector<Point> &v, unsigned int &i);	// NOTE: placeholder name (0x9d7300)
void opw8_shufflePoints(vector<Point> &v);	// NOTE: placeholder name (0x9d7350)
void opw8_appendPoints(vector<Point> &dst, vector<Point> &src);	// NOTE: placeholder name (0x9d7f20)
bool footprintHasImpassableTile(const Point &p, int size);
extern vector<HEntity> opw8_d35850;	// NOTE: placeholder name

bool opw8_shoveEntities(Array2D<int> *grid, const Point &p, vector<Point> visited)	// NOTE: placeholder name (0x5ddbf0)
{
	vector<Point> adjacent;
	sweepGetSurroundingCells(p,adjacent);
	for (unsigned int i = 0; i < visited.size(); i++)
		opw8_removePoint(adjacent,visited[i]);
	for (unsigned int i = 0; i < adjacent.size(); i++)
	{
		if (!grid->contains(adjacent[i].x,adjacent[i].y) || ((*grid)(adjacent[i]) != -1 && opw8_d35850[(*grid)(adjacent[i])]->getSize() > 1))
			opw8_erasePointStepBack(adjacent,i);
	}
	opw8_shufflePoints(adjacent);
	for (unsigned int i = 0; i < adjacent.size(); i++)
	{
		if ((*grid)(adjacent[i]) == -1 && !footprintHasImpassableTile(adjacent[i],1))
		{
			(*grid)(adjacent[i]) = (*grid)(p);
			(*grid)(p) = -1;
			return true;
		}
	}
	vector<Point> path(visited);
	opw8_appendPoints(path,adjacent);
	for (unsigned int i = 0; i < adjacent.size(); i++)
	{
		if ((*grid)(adjacent[i]) != -1 && opw8_shoveEntities(grid,adjacent[i],path))
		{
			(*grid)(adjacent[i]) = (*grid)(p);
			(*grid)(p) = -1;
			return true;
		}
	}
	return false;
}

int findEntityIndex(vector<HEntity> &v, HEntity e);	// 0x9d3110

bool Entity::unknown5ddf50(const Point &p, Array2D<int> *grid, bool *tooLarge)
{
	rng.seed(p.x * p.y);
	const int searchRadius = 6;
	Area bounds;
	cells.getRect(getPosition(),searchRadius,getSize() + searchRadius,bounds);
	opw8_d35850.clear();
	grid->init(cells.getWidth(),cells.getHeight(),-1);
	grid->setBounds(bounds.min.x,bounds.min.y,bounds.width(),bounds.height(),1);
	for (int x = grid->getMinX(); x <= grid->getMaxX(); x++)
	{
		for (int y = grid->getMinY(); y <= grid->getMaxY(); y++)
		{
			if (cells(x,y)->getEntity().isValid() && cells(x,y)->getEntity() != self)
			{
				int index = findEntityIndex(opw8_d35850,cells(x,y)->getEntity());
				if (index == -1)
				{
					opw8_d35850.push_back(cells(x,y)->getEntity());
					index = opw8_d35850.size() - 1;
				}
				(*grid)(x,y) = index;
			}
		}
	}

	vector<Point> points;
	for (int y = 0; y < record->type; y++)
	{
		for (int x = 0; x < record->type; x++)
			points.push_back(Point(p,x,y));
	}

	vector<HEntity> entities;
	Point unused;
	for (unsigned int i = 0; i < points.size(); i++)
	{
		if ((*grid)(points[i]) != -1)
		{
			entities.push_back(opw8_d35850[(*grid)(points[i])]);
			if ((entities.back()->isPlayer() && entities.back()->unknown5cad50() && opw8_table_ba0984[opw8_cefb38]) || entities.back()->getFaction() == 0xb)
				return false;
			if (entities.back()->getSize() > 1)
			{
				if (tooLarge != 0)
					*tooLarge = true;
				return false;
			}
		}
	}
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		vector<Point> visited(1,entities[i]->getPosition());
		opw8_appendPoints(visited,points);
		if (!opw8_shoveEntities(grid,entities[i]->getPosition(),visited))
			return false;
	}
	return true;
}

class OpW8_ItemFactory	// NOTE: placeholder name (object at 0xcefaa8)
{
public:
	HItem create(OpW8_ItemRecord *type);	// NOTE: placeholder name (0x7932b0)
	class HMarker unknown793190();	// NOTE: placeholder name
	void unknown793690();	// NOTE: placeholder name
	void unknown793450(int sound, int a, int b, int c, int d);	// NOTE: placeholder name
};
extern OpW8_ItemFactory *opw8_itemFactory;	// NOTE: placeholder name

void Entity::unknown5de480(OpW8_ItemRecord *type)
{
	opw8_itemFactory->create(type)->unknown57a190(self,type->unknown48,0,0);
	parts.back()->unknown458390(false);
	if (unknown5dc440(parts.back()) == 0 && !unknown5cd220(parts.back()) && parts.back()->getEffect(0x3b) == 0)
	{
		parts.back()->setActive(true);
		switch (parts.back()->unknown457f90())
		{
			case 8:
				unknown5ded70(parts.back()->unknown457fb0());
				break;
			case 9:
				if (record->unknown28 != 1)
					unknown5deb40(parts.back()->unknown457fb0());
				break;
		}
		if (parts.back()->unknown457ed0() != 0)
			unknown5ded70(parts.back()->unknown457ed0());
	}
}

extern int opw8_table_b959ec[];	// NOTE: placeholder name

void Entity::unknown5de640(int type, vector<OpW8_ItemRecord *> *list)
{
	OpW8_ItemRecord *found = 0;
	unsigned int i;
	for (i = 0; i < list->size(); i++)
	{
		if ((*list)[i]->unknown50 <= record->unknown68)
		{
			found = (*list)[i];
			if (found->unknown50 == record->unknown68)
				break;
		}
	}
	if (found == 0)
		return;

	int remaining = unknown45a810();
	int num = opw8_table_b959ec[type];
	for (unsigned int j = 0; j < parts.size(); j++)
	{
		if (parts[j]->unknown4578a0() == 4 && parts[j]->unknown9b4350() == found)
			num--;
	}
	for (int k = 0; k < num; k++)
	{
		if (remaining >= found->unknown4C)
			world->unknown6c51d0(found,self,0,0);
		if ((remaining -= found->unknown4C) == 0)
			break;
	}
}

void Entity::unknown5de800()
{
	if (opw8_cf462c != 5)
		unknown8C = 1 ? opw8_cf4954 : (opw8_cf4954 - unknown8C) * 100 / 100;
	unknown98 = unknown5cab30();
	unknownB0 = 0;
}

void opw8_increase(int *value, int amount, int maximum);	// NOTE: placeholder name (0x9d06d0)

void Entity::unknown5de870(int amount, bool linked)
{
	opw8_increase(&unknown8C,amount,unknown5ca260());
	if (opw8_cf462c == 7 && !linked)
	{
		if (isPlayer())
		{
			if (world->opw8_getEntity671().isValid())
				world->opw8_getEntity671()->unknown5de870(amount,true);
		}
		else if (self == world->opw8_getEntity671())
			world->getPlayer()->unknown5de870(amount,true);
	}
}

class OpW5_RolledValues
{
public:
	bool say(int ID, bool force, string name);
};
extern OpW5_RolledValues *opw8_cefb48;	// NOTE: placeholder name

void Entity::unknown5de950(int amount, bool linked)
{
	opw8_decrease(&unknown8C,amount,0);
	if (opw8_cf462c == 7 && !linked)
	{
		if (isPlayer())
		{
			if (world->opw8_getEntity671().isValid())
			{
				world->opw8_getEntity671()->unknown5de950(amount,true);
				if (opw8_cefb48 != 0)
					opw8_cefb48->say(3,false,"");
			}
		}
		else if (self == world->opw8_getEntity671())
			world->getPlayer()->unknown5de950(amount,true);
	}
}

void Entity::unknown5dea60(int amount, bool linked)
{
	unknown8C = minInt(amount,unknown5ca260());
	if (opw8_cf462c == 7 && !linked)
	{
		if (isPlayer())
		{
			if (world->opw8_getEntity671().isValid())
				world->opw8_getEntity671()->unknown5dea60(amount,true);
		}
		else if (self == world->opw8_getEntity671())
			world->getPlayer()->unknown5dea60(amount,true);
	}
}

int Entity::unknown5deb40(int amount)
{
	int capacity = unknown5ca670();
	if (unknown94 + amount <= capacity)
	{
		unknown94 += amount;
		return 0;
	}
	amount = unknown94 + amount - capacity;
	unknown94 = capacity;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() == 4 && parts[i]->unknown457f90() == 9 && opw8_cf4830[parts[i]->unknown457820()] != 0 && !parts[i]->unknown457db0())
		{
			int space = parts[i]->unknown457fb0() - parts[i]->unknown45cb30();
			if (space > 0)
			{
				int added = minInt(amount,space);
				amount -= added;
				parts[i]->unknown44fc60(parts[i]->unknown45cb30() + added);
				opw8_cec08c->unknown8a54c0(parts[i],true);
			}
			if (amount == 0)
				break;
		}
	}
	return amount;
}

int Entity::unknown5ded70(int amount)
{
	int capacity = unknown5ca400();
	if (unknown90 + amount <= capacity)
	{
		unknown90 += amount;
		return 0;
	}
	amount = unknown90 + amount - capacity;
	unknown90 = capacity;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() == 4 && parts[i]->unknown457f90() == 8 && opw8_cf4830[parts[i]->unknown457820()] != 0 && !parts[i]->unknown457db0())
		{
			int space = parts[i]->unknown457fb0() - parts[i]->unknown45cb30();
			if (space > 0)
			{
				int added = minInt(amount,space);
				amount -= added;
				parts[i]->unknown44fc60(parts[i]->unknown45cb30() + added);
				if (opw8_cec08c != 0)
					opw8_cec08c->unknown8a54c0(parts[i],true);
			}
			if (amount == 0)
				break;
		}
	}
	return amount;
}

bool Entity::unknown5c7f70()
{
	return group->unknown9b4350() <= 1;
}

void Entity::unknown5dc750(HGroup newGroup)
{
	group = newGroup;
	unknown2c = world->getTurn();
}

extern int opw8_cf4a34;	// NOTE: placeholder name

void Entity::unknown5dfb60(HItem item)
{
	parts.push_back(item);
	if (isPlayer() && unknown5c97f0() && !item->unknown9b4350()->unknown1AE)
		opw8_cf4a34++;
}

int findItemIndex(vector<HItem> &v, HItem item);	// NOTE: placeholder name (0x9d3110)
void opw8_eraseItemAt(vector<HItem> &v, int index);	// NOTE: placeholder name (0x9da940)
bool opw8_containsEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d31e0)
extern vector<HEntity> opw8_cf25b8;	// NOTE: placeholder name
extern vector<HProp> opw8_d37984;	// NOTE: placeholder name

void Entity::unknown5dfbd0(HItem item)
{
	int index = findItemIndex(parts,item);
	int type = 4;
	if (!record->unknownA9 && unknown144 != 0 && unknown8C > 0 && item->unknown44aec0() <= 3)
		type = item->unknown4578a0();
	if (type == 3 && unknown144 != 0 && unknown144->unknown9b4350() < 8)
		type = 4;
	opw8_eraseItemAt(parts,index);
	if (type != 4)
	{
		bool found = false;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown4578a0() == type && parts[i]->unknown44aec0() <= 3)
			{
				found = true;
				break;
			}
		}
		if (!found && !opw8_containsEntity(opw8_cf25b8,self) && (unknown144 == 0 || !unknown144->unknown54))
		{
			opw8_cf25b8.push_back(self);
			opw8_d37984.push_back(HProp());
		}
	}
}

int Entity::unknown5df740(int mode)
{
	int current = unknown5d1390();
	if (current == mode)
		return 5;
	if (unknown5cad50())
	{
		switch (opw8_cefb38)
		{
			case 1:
			case 2:
				if (mode != 0)
					return 5;
				break;
			case 3:
			case 4:
				if (mode != 1)
					return 5;
				break;
		}
	}

	if (mode == 6)
	{
		if (isPlayer())
		{
			do
			{
				opw8_cec088->input(&XEvent(0x114));
			}
			while (unknown5d1390() != mode);
		}
		else
		{
			for (unsigned int i = 0; i < parts.size(); i++)
			{
				if (parts[i]->unknown44aec0() == 1 && unknown5dc700(parts[i]) == 0)
					unknown64e7e0(parts[i]);
			}
		}
		return current;
	}

	if (isPlayer())
	{
		bool found = false;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown44aec0() == 1 && parts[i]->unknown457880() - 9 == mode && unknown5dc440(parts[i]) == 0)
			{
				found = true;
				break;
			}
		}
		if (found)
		{
			do
			{
				opw8_cec088->input(&XEvent(0x114));
			}
			while (unknown5d1390() != mode);
			return current;
		}
		else
			return 5;
	}
	else
	{
		bool changed = false;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown44aec0() == 1 && parts[i]->unknown457880() - 9 == mode && unknown5dc440(parts[i]) == 0)
			{
				unknown64da50(parts[i]);
				changed = true;
			}
		}
		if (changed)
		{
			for (unsigned int j = 0; j < parts.size(); j++)
			{
				if (parts[j]->unknown44aec0() == 1 && parts[j]->unknown457880() - 9 != mode && unknown5dc700(parts[j]) == 0)
					unknown64e7e0(parts[j]);
			}
		}
		return changed ? current : 5;
	}
}

class CPart
{
public:
	void drawStatus(bool damaged);	// NOTE: placeholder name (0x4a8e70)
	void unknown4a8fc0();	// NOTE: placeholder name
};

HItem opw8_pickItem9dafb0(vector<HItem> &list);	// NOTE: placeholder name

int Entity::unknown5d7320(vector<HItem> *list, bool notify)
{
	int total = 0;
	int count = 0;
	for (unsigned int i = 0; i < list->size(); i++)
	{
		if ((*list)[i]->unknown578a70() != 0)
		{
			total += (*list)[i]->unknown578a70();
			count++;
		}
	}
	if (count >= 2)
	{
		vector<HItem> items;
		if (unknown5d2430(3,&items))
		{
			HItem item = opw8_pickItem9dafb0(items);
			total = total * (100 - item->unknown457fb0()) / 100;
			if (notify)
			{
				if (item->unknown9b6bf0() <= 1)
				{
					do
					{
						if (opw8_unknown5111e0(0x190,&item->getName(0,0),0,0,self,HProp(),0,0))
							opw8_cec058->unknown8758d0(true);
						opw8_logMsgs->scrollToEnd();
					} while (0);
					item->unknown57dbe0(1,0,6,1);
				}
				else
				{
					item->unknown458310(true);
					if (item->unknown5758f0())
					{
						CPart *part = opw8_cec088->unknown894e70(item);
						if (part != 0)
							part->drawStatus(true);
					}
				}
			}
		}
	}
	return total;
}

struct OpW8_LaunchData	// NOTE: placeholder name
{
	char pad00[0x2c];
	int unknown2C;
	int unknown30;
	int unknown34;
	char pad38[0x64 - 0x38];
	int unknown64;
};

extern int opw8_cf49c4;	// NOTE: placeholder name
extern int opw8_table_cf49bc[];	// NOTE: placeholder name

void Entity::unknown5d7700(vector<HItem> *items, vector<int> *damage)
{
	HEntity entity = self;
	int amount;
	OpW8_ItemRecord *rec;
	int damageType;
	damage->assign(10U,0);
	for (unsigned int i = 0; i < items->size(); i++)
	{
		amount = 0;
		rec = (*items)[i]->unknown9b4350();
		if (rec->unknown1A0 != 0)
		{
			float mult = 1;
			if (entity.isValid())
			{
				if (rec->unknownF0 == 0xc9)
					mult = (*items)[i]->unknown579090();
				else if (opw8_cf462c == 5 && entity->isPlayer() && rec->unknown1A0->unknown2C == 2 && opw8_cf49c4 != 0)
					mult += opw8_cf49c4 / 100.0;
			}
			amount = opw2_maxInt(0,rec->unknown1A0->unknown30 * mult + rec->unknown1A0->unknown34);
			damageType = rec->unknown1A0->unknown2C;
		}
		else
		{
			float mult = 1;
			if (entity.isValid())
			{
				if ((*items)[i]->unknown458220())
					mult = entity->unknown5d7bc0();
				else if (rec->unknown44 >= 0x1a)
					mult = entity->unknown5d7bf0(rec->unknown128);
			}
			int minDamage = rec->unknown120 * mult;
			amount = rec->unknown124 * mult;
			damageType = rec->unknown128;
			if (entity.isValid())
			{
				if (rec->unknown1B0 && !rec->unknown165 && entity->unknown5d22a0(0x66) != 0)
				{
					int bonus = entity->unknown5d22a0(0x66);
					if (bonus != 0)
						amount += amount * bonus / 100;
				}
				else if (rec->unknown44 == 0x14 || rec->unknown44 == 0x15)
				{
					int bonus = rec->unknown165 ? 0 : entity->unknown5d2150(0x67,0);
					if (bonus != 0)
						amount += amount * bonus / 100;
				}
				else if (rec->unknown44 == 0x16 || rec->unknown44 == 0x17)
				{
					int bonus = entity->unknown5d22a0(0x69);
					if (bonus != 0)
					{
						minDamage += minDamage * bonus / 100;
						if (minDamage > amount)
							amount = minDamage;
					}
				}
				else if (opw8_inRange(0x1a,rec->unknown44,0x1c))
				{
					int bonus = entity->unknown5d2150(0x6a,0);
					if (bonus != 0)
						amount += amount * bonus / 100;
				}
				if (opw8_cf462c == 5 && entity->isPlayer() && rec->unknown128 < 7 && opw8_table_cf49bc[rec->unknown128] != 0)
				{
					int bonus = opw8_table_cf49bc[rec->unknown128];
					amount += amount * bonus / 100;
				}
			}
		}
		if (amount > (*damage)[damageType])
			(*damage)[damageType] = amount;
	}
}

extern bool opw8_cefc8b;	// NOTE: placeholder name
void opw8_insertItem(vector<HItem> &v, int index, HItem item);	// NOTE: placeholder name (0x9d8fc0)

class OpW8_Unk7aa280	// NOTE: placeholder name
{
public:
	void unknown7aa280(int a, int b, string text);	// NOTE: placeholder name
};
struct OpW8_Unkcf4ac8	// NOTE: placeholder name
{
	int unknown00;
	char pad04[4];
	int unknown08;
	char pad0C[0x30 - 0xc];
	OpW8_Unk7aa280 *unknown30;	// NOTE: placeholder name
};
extern OpW8_Unkcf4ac8 *opw8_cf4ac8;	// NOTE: placeholder name

void Entity::unknown5d5eb0(vector<HItem> *out, HProp target)
{
	HItem fallback = unknown5d5d40();
	if (opw8_cefc8b || target.isNull())
	{
		out->push_back(fallback);
		return;
	}
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() == 3 && parts[i]->unknown578d90(fallback) && rng.chance(parts[i]->unknown578e90(0)))
			out->push_back(parts[i]);
	}
	if (!out->empty())
		opw8_shuffle9d9fc0(*out);
	opw8_insertItem(*out,0,fallback);
	if (opw8_playerData.unknown780790())
	{
		if (opw8_cf4ac8->unknown00 != 0)
		{
			if (fallback->unknown457f90() == 0xd6 && out->size() > 1)
				out->erase(out->begin() + 1,out->end());
			for (unsigned int j = 1; j < out->size(); j++)
			{
				if ((*out)[j]->unknown457f90() == 0xd6)
				{
					if (opw8_playerData.unknown780790())
						opw8_cf4ac8->unknown30->unknown7aa280(0x23,0,(*out)[0]->getName(0,0));
					opw8_eraseItemAt(*out,j);
					break;
				}
			}
		}
		if (out->size() == 1 && fallback->unknown457f90() == 0xd6 && rng.chance(opw8_cf4ac8->unknown08 / 50 + 0xf))
		{
			vector<HEntity> nearby;
			world->unknown71c550(self,&nearby);
			int hostiles = 0;
			for (unsigned int k = 0; k < nearby.size(); k++)
			{
				if (nearby[k]->isHostileTo(self))
					hostiles++;
			}
			if (hostiles > 1)
				out->push_back(fallback);
		}
	}
}

struct OpW8_Dice	// NOTE: placeholder name (integer-list wrapper)
{
	int roll();	// NOTE: placeholder name (0x40c820)
	vector<int> values;	// +0; retail constructor 0x4588d0, destructor 0x40c960
};
OpW8_Dice opw8_cfcd20[10];	// NOTE: placeholder name (defined here so constant-index offsets resolve)

extern OpW8_Range opw8_d26004;	// NOTE: placeholder name
extern float opw8_ba09c8;	// NOTE: placeholder name

int Entity::unknown5d6d80(vector<HItem> *items, HEntity target)
{
	int time = items->size() >= 10 ? opw8_cfcd20[9].roll() : opw8_cfcd20[items->size() - 1].roll();
	if (items->empty())
		return time;

	int reduction = 0;
	if ((*items)[0]->unknown457880() >= 0x1a)
	{
		if ((*items)[0]->unknown457880() == 0x1e)
			return 300;
		time = opw8_cfcd20[0].roll();
		for (unsigned int i = 0; i < items->size(); i++)
		{
			if (i == 0)
			{
				time += (*items)[i]->unknown4580e0();
				if ((*items)[i]->unknown457f90() == 0xd6 && target.operator->() != 0 && opw8_playerData.unknown780790())
				{
					if (opw8_cf4ac8->unknown00 != 0 && rng.chance(5))
					{
						if (items->size() > 1)
							items->erase(items->begin() + 1,items->end());
						if (opw8_playerData.unknown780790())
							opw8_cf4ac8->unknown30->unknown7aa280(0x13,0,"");
						return 0;
					}
					else if (unknown8C > opw8_d26004.min && rng.chance(opw8_cf4ac8->unknown08 / 200 + 5))
					{
						time /= 2;
						takeDamage(0,0,0,opw8_d26004.randomInRange_40c130(),7,0,0,1,HProp(),1,8,0,0,1);
						if (opw8_playerData.unknown780790())
							opw8_cf4ac8->unknown30->unknown7aa280(0x12,0,"");
					}
				}
			}
			else if ((*items)[i]->unknown457f90() == 0xd6 && (*items)[0]->unknown457f90() == 0xd6)
				time = time;
			else
				time += (*items)[i]->unknown4580e0() / 2;
		}
		reduction = minInt(unknown5d2090(0x51),0x32);
		if (reduction != 0)
			time -= time * reduction / 100;
		if (opw8_cefc8b)
		{
			time *= opw8_ba09c8;
			opw8_cefc8b = false;
		}
	}
	else
	{
		bool flag = false;
		int negative = 0;
		for (unsigned int j = 0; j < items->size(); j++)
		{
			if ((*items)[j]->unknown4580e0() < 0)
				negative += (*items)[j]->unknown4580e0();
			else
				time += (*items)[j]->unknown4580e0();
			if ((*items)[j]->unknown9b4350()->unknown165)
				flag = true;
		}
		if (negative != 0)
			time += opw2_maxInt(negative,-100);
		if (items->size() == 1)
		{
			if (((*items)[0]->unknown457880() == 0x14 || (*items)[0]->unknown457880() == 0x15) && !(*items)[0]->unknown458220() && !(*items)[0]->unknown9b4350()->unknown165)
				reduction = unknown5d22a0(0x4e);
			else if ((*items)[0]->unknown457880() == 0x18)
				reduction = unknown5d22a0(0x4f);
			if (reduction != 0)
			{
				time -= time * reduction / 100;
				goto done;
			}
		}
		if (!flag)
			reduction = minInt(unknown5d2090(0x50),0x1e);
		if (reduction != 0)
			time -= time * reduction / 100;
	}
done:
	opw8_atLeast(&time,0x19);
	return time;
}

struct OpW8_PartOption	// NOTE: placeholder name
{
	OpW8_PartOption(int type_, int count_, int chance_);	// 0x455da0

	int type;
	int count;
	int chance;
};

OpW8_PartOption::OpW8_PartOption(int type_, int count_, int chance_)
{
	type = type_;
	count = count_;
	chance = chance_;
}

void opw8_eraseFirstChar(string &s);	// NOTE: placeholder name (0x4077e0)
void opw8_eraseLastChar(string &s);	// NOTE: placeholder name (0x407840)
bool opw8_extractParenthesized(string &s, string &out);	// NOTE: placeholder name (0x436d80)
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
int opw8_findItemType(vector<OpW8_ItemTypeD2d1c4 *> &v, const string &name);	// NOTE: placeholder name (0x9d74d0)

bool opw8_parsePartOptions(vector<string> &tokens, vector<vector<OpW8_PartOption *> > &options)	// NOTE: placeholder name (0x5c2530)
{
	bool inGroup = false;
	for (unsigned int i = 0; i < tokens.size(); i++)
	{
		if (!inGroup)
			options.push_back(vector<OpW8_PartOption *>());
		if (tokens[i][0] == '[')
		{
			inGroup = true;
			opw8_eraseFirstChar(tokens[i]);
		}
		else if (*(tokens[i].end() - 1) == ']' && tokens[i].find('[',0) == string::npos)
		{
			inGroup = false;
			opw8_eraseLastChar(tokens[i]);
		}
		int chance;
		string countStr;
		if (!opw8_extractParenthesized(tokens[i],countStr))
			return false;
		{
			int amount = countStr.empty() ? 1 : stringToInt(countStr);
			chance = tokens[i].find(':',0);
			if (chance == string::npos)
				chance = 100;
			else
			{
				string chanceStr(tokens[i].begin() + chance + 1,tokens[i].end());
				tokens[i].erase(tokens[i].begin() + chance,tokens[i].end());
				chance = stringToInt(chanceStr);
			}
			int type = opw8_findItemType(opw8_d2d1c4,tokens[i]);
			if (type == -1)
				return false;
			if (amount < 1 || amount > 0x1a)
				return false;
			options.back().push_back(new OpW8_PartOption(type,amount,chance));
		}
	}
	return true;
}


int OpW8_EntityRecord::unknown5c3120()
{
	int total = 0;
	int best;
	for (unsigned int i = 0; i < unknown160.size(); i++)
	{
		best = opw8_d2d1c4[unknown160[i].front()->type]->unknown50;
		for (unsigned int j = 0; j < unknown160[i].size(); j++)
		{
			if (opw8_d2d1c4[unknown160[i][j]->type]->unknown50 > best)
				best = opw8_d2d1c4[unknown160[i][j]->type]->unknown50;
		}
		total += ((opw8_d2d1c4[i]->unknown48 == 3) + 1) * best;
	}
	return total;
}

struct OpW8_PropInfo	// NOTE: placeholder name
{
	char pad00[8];
	int unknown08;
};

class OpW8_GameData	// NOTE: placeholder name (object at 0xd1e860)
{
public:
	int unknown46f4e0();	// NOTE: placeholder name
	bool unknown46fb60();	// NOTE: placeholder name
	const string &unknown46f6d0(const string &key);	// NOTE: placeholder name
};
extern OpW8_GameData opw8_gameData;	// NOTE: placeholder name

bool OpW8_EntityRecord::unknown5c3260(HProp prop, bool flag)
{
	if (flag ? unknown170.empty() : unknownE8 == 0)
		return false;
	return unknown68 < opw8_gameData.unknown46f4e0() + prop->unknown45cb30()->unknown08;
}

struct OpW8_LocationInfo	// NOTE: placeholder name
{
	int unknown46ed20();	// NOTE: placeholder name
	char pad00[4];
	int unknown04;
	int depth;	// NOTE: placeholder name
};

class OpW8_LocationHandle	// NOTE: placeholder name
{
public:
	int ID;
	OpW8_LocationInfo *operator->();	// 0x9b7910
};
extern OpW8_LocationHandle opw8_d1e888;	// NOTE: placeholder name

string OpW8_EntityRecord::unknown5c32e0()
{
	int depth = -(10 - unknown68) - 3;
	if (-opw8_d1e888->depth < depth)
		return "Access unavailable below " + intToString(depth) + ".";
	else
		return "At 0b10/" + intToString(-opw8_d1e888->depth) + ", security level " + intToString(depth + opw8_d1e888->depth + 3) + " required.";
}

class OpW8_Cefc14	// NOTE: placeholder name
{
public:
	int unknown7ac070(HEntity e);	// NOTE: placeholder name
};
extern OpW8_Cefc14 *opw8_cefc14;	// NOTE: placeholder name
extern XColor opw8_colors_cf0d48[];	// NOTE: placeholder name
extern XColor opw8_colors_d01724[];	// NOTE: placeholder name
extern XColor *opw8_d221e4;	// NOTE: placeholder name
extern XColor *opw8_cefdd0;	// NOTE: placeholder name
extern XColor *opw8_d396f0;	// NOTE: placeholder name
extern XColor *opw8_d25f70;	// NOTE: placeholder name
extern XColor *opw8_d35be4;	// NOTE: placeholder name

const XColor &Entity::unknown5c7630()
{
	if (opw8_cefc14 != 0)
	{
		int index = opw8_cefc14->unknown7ac070(self);
		if (index != 0x20)
			return opw8_colors_cf0d48[index];
	}
	if (opw8_cf462c == 0xb && isPlayer() && opw8_cf4700 != 0)
		return *opw8_d221e4;
	return unknown70 == 0 ? (group->unknown9b8f00() <= 1 ? group->colors[record->unknown6C] : (record->unknown24 == 2 ? (group->unknown9b8f00() == 2 ? *opw8_cefdd0 : *opw8_d396f0) : ((record->unknown24 == 0 && record->unknown00 != 0 && record->unknown28 != 0x3d && record->unknown28 != 0x3b) ? *opw8_d25f70 : ((group->unknown9b8f00() == 0xb && unknown45ac40(0x39)) ? *opw8_d35be4 : group->colors[record->unknown6C])))) : opw8_colors_d01724[unknown70];
}

const XColor &Entity::unknown5c7810()
{
	if (opw8_cefc14 != 0)
	{
		int index = opw8_cefc14->unknown7ac070(self);
		if (index != 0x20)
			return opw8_colors_cf0d48[index];
	}
	if (opw8_cf462c == 0xb && isPlayer() && opw8_cf4700 != 0)
		return *opw8_d221e4;
	return group.isValid() ? (group->unknown9b8f00() <= 1 ? group->colors[record->unknown6C] : (record->unknown24 == 2 ? (group->unknown9b8f00() == 2 ? *opw8_cefdd0 : *opw8_d396f0) : ((record->unknown24 == 0 && record->unknown00 != 0 && record->unknown28 != 0x3d && record->unknown28 != 0x3b) ? *opw8_d25f70 : group->colors[record->unknown6C]))) : world->unknown463890(0)->colors[record->unknown6C];
}

class OpW8_Stream;	// NOTE: placeholder name
void opw8_save9d3b60(OpW8_Stream *stream, const void *value);	// NOTE: placeholder name
void opw8_save9da000(OpW8_Stream *stream, OpW8_EntityRecord *record);	// NOTE: placeholder name
void opw8_save409650(OpW8_Stream *stream, string value);	// NOTE: placeholder name
void opw8_save9d0840(OpW8_Stream *stream, const void *value);	// NOTE: placeholder name
void opw8_save9d4c70(OpW8_Stream *stream, const void *values, int count);	// NOTE: placeholder name
void opw8_save9d2130(OpW8_Stream *stream, const void *value);	// NOTE: placeholder name
void opw8_save9cf540(OpW8_Stream *stream, const void *value);	// NOTE: placeholder name
void opw8_save9d6770(OpW8_Stream *stream, const void *value);	// NOTE: placeholder name
void opw8_save9d84d0(OpW8_Stream *stream, const void *value);	// NOTE: placeholder name
void opw8_save9d8dd0(OpW8_Stream *stream, const void *value);	// NOTE: placeholder name
void opw8_save9d95a0(OpW8_Stream *stream, const void *value);	// NOTE: placeholder name
void opw8_save9d9600(OpW8_Stream *stream, const void *value);	// NOTE: placeholder name
void opw8_save9d9660(OpW8_Stream *stream, const void *value);	// NOTE: placeholder name

void Entity::unknown5c6d90(OpW8_Stream *stream)
{
	opw8_save9d3b60(stream,&unknown00);
	self.save(stream);
	opw8_save9da000(stream,record);
	opw8_save409650(stream,name);
	group.save(stream);
	opw8_save9d3b60(stream,&unknown2c);
	opw8_save9d0840(stream,&positions);
	opw8_save9d3b60(stream,&unknown40);
	unknown44.save(stream);
	opw8_save9d3b60(stream,&unknown4C);
	opw8_save9d3b60(stream,&unknown50);
	opw8_save9d3b60(stream,&unknown54);
	opw8_save9d3b60(stream,&unknown58);
	opw8_save9d3b60(stream,&unknown5C);
	opw8_save9d3b60(stream,&unknown70);
	opw8_save9d3b60(stream,&unknown74);
	opw8_save9d4c70(stream,slots,4);
	opw8_save9d3b60(stream,&unknown88);
	opw8_save9d3b60(stream,&unknown8C);
	opw8_save9d3b60(stream,&unknown90);
	opw8_save9d3b60(stream,&unknown94);
	opw8_save9d3b60(stream,&unknown98);
	opw8_save9d2130(stream,&unknown9C);
	opw8_save9cf540(stream,&unknownAC);
	opw8_save9d3b60(stream,&unknownB0);
	opw8_save9d3b60(stream,&unknownB4);
	opw8_save9cf540(stream,&unknownB8);
	opw8_save9d3b60(stream,&unknownBC);
	opw8_save9cf540(stream,&unknownC0);
	opw8_save9d3b60(stream,&unknownC4);
	opw8_save9d3b60(stream,&unknownC8);
	opw8_save9d3b60(stream,&unknownCC);
	opw8_save9d6770(stream,&unknownDC);
	opw8_save9d84d0(stream,&unknownEC);
	opw8_save9d8dd0(stream,&unknownF0);
	opw8_save9d95a0(stream,&unknownF4);
	opw8_save9d95a0(stream,&unknown104);
	unknown114.save(stream);
	unknown118.save(stream);
	opw8_save9d3b60(stream,&unknown11C);
	opw8_save9d3b60(stream,&unknown120);
	opw8_save9d2130(stream,&unknown124);
	opw8_save9d9600(stream,&parts);
	opw8_save9d9660(stream,&unknown144);
}

void opw8_load9d8480(OpW8_Stream *stream, void *value);	// NOTE: placeholder name
void opw8_load9d69b0(OpW8_Stream *stream, OpW8_EntityRecord **record, vector<OpW8_EntityRecord *> *table);	// NOTE: placeholder name
void opw8_load4096f0(OpW8_Stream *stream, string *value);	// NOTE: placeholder name
void opw8_load9d07e0(OpW8_Stream *stream, void *value);	// NOTE: placeholder name
void opw8_load9d4ec0(OpW8_Stream *stream, void *values);	// NOTE: placeholder name
void opw8_load9cf5e0(OpW8_Stream *stream, void *value);	// NOTE: placeholder name
void opw8_load9cf520(OpW8_Stream *stream, void *value);	// NOTE: placeholder name
void opw8_load9d6580(OpW8_Stream *stream, void *value, int a);	// NOTE: placeholder name
void opw8_load9d8510(OpW8_Stream *stream, void *value);	// NOTE: placeholder name
void opw8_load9d8b00(OpW8_Stream *stream, void *value);	// NOTE: placeholder name
void opw8_load9d96a0(OpW8_Stream *stream, void *value, int a);	// NOTE: placeholder name
void opw8_load9da130(OpW8_Stream *stream, void *value);	// NOTE: placeholder name
void opw8_load9d97e0(OpW8_Stream *stream, void *value);	// NOTE: placeholder name

Entity::Entity(OpW8_Stream *stream)
{
	opw8_load9d8480(stream,&unknown00);
	self.load(stream);
	opw8_load9d69b0(stream,&record,&opw8_d25de0);
	opw8_load4096f0(stream,&name);
	group.load(stream);
	opw8_load9d8480(stream,&unknown2c);
	opw8_load9d07e0(stream,&positions);
	opw8_load9d8480(stream,&unknown40);
	unknown44.load(stream);
	opw8_load9d8480(stream,&unknown4C);
	opw8_load9d8480(stream,&unknown50);
	opw8_load9d8480(stream,&unknown54);
	opw8_load9d8480(stream,&unknown58);
	opw8_load9d8480(stream,&unknown5C);
	opw8_load9d8480(stream,&unknown70);
	opw8_load9d8480(stream,&unknown74);
	opw8_load9d4ec0(stream,slots);
	opw8_load9d8480(stream,&unknown88);
	opw8_load9d8480(stream,&unknown8C);
	opw8_load9d8480(stream,&unknown90);
	opw8_load9d8480(stream,&unknown94);
	opw8_load9d8480(stream,&unknown98);
	opw8_load9cf5e0(stream,&unknown9C);
	opw8_load9cf520(stream,&unknownAC);
	opw8_load9d8480(stream,&unknownB0);
	opw8_load9d8480(stream,&unknownB4);
	opw8_load9cf520(stream,&unknownB8);
	opw8_load9d8480(stream,&unknownBC);
	opw8_load9cf520(stream,&unknownC0);
	opw8_load9d8480(stream,&unknownC4);
	opw8_load9d8480(stream,&unknownC8);
	opw8_load9d8480(stream,&unknownCC);
	unknownD0 = 0;
	unknownD4 = 0;
	unknownD8 = 0;
	opw8_load9d6580(stream,&unknownDC,0);
	opw8_load9d8510(stream,&unknownEC);
	opw8_load9d8b00(stream,&unknownF0);
	opw8_load9d96a0(stream,&unknownF4,0);
	opw8_load9d96a0(stream,&unknown104,0);
	unknown114.load(stream);
	unknown118.load(stream);
	opw8_load9d8480(stream,&unknown11C);
	opw8_load9d8480(stream,&unknown120);
	opw8_load9cf5e0(stream,&unknown124);
	opw8_load9da130(stream,&parts);
	opw8_load9d97e0(stream,&unknown144);
}

void opw8_load9d92d0(OpW8_Stream *stream, void *value, vector<string> *names);	// NOTE: placeholder name
void opw8_load9d8110(OpW8_Stream *stream, void *value, vector<string> *names);	// NOTE: placeholder name
void opw8_load9d8200(OpW8_Stream *stream, void *value, vector<string> *names);	// NOTE: placeholder name
void opw8_load465ea0(OpW8_Stream *stream, int *value);	// NOTE: placeholder name
void opw8_load9d93c0(OpW8_Stream *stream, void *value);	// NOTE: placeholder name
extern vector<string> opw8_cf671c;	// NOTE: placeholder name
extern vector<string> opw8_cfd2cc;	// NOTE: placeholder name
extern vector<string> opw8_d2c408;	// NOTE: placeholder name

OpW8_EntityRecord::OpW8_EntityRecord(OpW8_Stream *stream)
{
	opw8_load9d8480(stream,&unknown00);
	opw8_load4096f0(stream,&name);
	opw8_load9cf520(stream,&unknown20);
	opw8_load9d8480(stream,&unknown24);
	opw8_load9d8480(stream,&unknown28);
	opw8_load4096f0(stream,&unknown2C);
	opw8_load9d8480(stream,&unknown48);
	opw8_load4096f0(stream,&unknown4C);
	opw8_load9d8480(stream,&unknown68);
	opw8_load9d8480(stream,&unknown6C);
	opw8_load9d8480(stream,&unknown70);
	opw8_load9cf520(stream,&unknown74);
	opw8_load9cf520(stream,&unknown75);
	opw8_load9d8480(stream,&ascii);
	opw8_load9d8480(stream,&unknown7C);
	opw8_load9d8480(stream,&unknown80);
	opw8_load9d8480(stream,&unknown84);
	opw8_load9d8480(stream,&unknown88);
	opw8_load9d8480(stream,&unknown8C);
	opw8_load9d92d0(stream,&unknown90,&opw8_cf671c);
	opw8_load9d8480(stream,&unknown94);
	opw8_load9d8480(stream,&unknown98);
	opw8_load9d8480(stream,&type);
	opw8_load9d8480(stream,&unknownA0);
	opw8_load465ea0(stream,&unknownA4);
	opw8_load9cf520(stream,&unknownA8);
	opw8_load9cf520(stream,&unknownA9);
	opw8_load9d8480(stream,&unknownAC);
	opw8_load9d8480(stream,&unknownB0);
	opw8_load9d8480(stream,&unknownB4);
	opw8_load9d8480(stream,&unknownB8);
	opw8_load9d8110(stream,&unknownBC,&opw8_cfd2cc);
	opw8_load9d8480(stream,&unknownC0);
	opw8_load9d6580(stream,&unknownC4,0);
	opw8_load9d8200(stream,&unknownD4,&opw8_d2c408);
	opw8_load9d8480(stream,&unknownE4);
	opw8_load9d8480(stream,&unknownE8);
	opw8_load9d8480(stream,&unknownEC);
	opw8_load9d8480(stream,&unknownF0);
	opw8_load9d8480(stream,&unknownF4);
	opw8_load9d8480(stream,&unknownF8);
	opw8_load9cf5e0(stream,&unknownFC);
	opw8_load9d8480(stream,&unknown10C);
	opw8_load9d8480(stream,&unknown110);
	opw8_load9cf520(stream,&unknown114);
	unknown118.load(stream);
	opw8_load9d8480(stream,&unknown120);
	opw8_load9d8480(stream,&unknown124);
	opw8_load9d8480(stream,&unknown128);
	opw8_load9d8480(stream,&unknown12C);
	unknown130.load(stream);
	opw8_load9cf520(stream,&unknown138);
	opw8_load9cf520(stream,&unknown139);
	opw8_load9cf520(stream,&unknown13A);
	opw8_load9cf520(stream,&unknown13B);
	opw8_load9d8480(stream,&unknown13C);
	opw8_load9d8480(stream,&unknown140);
	opw8_load9d8480(stream,&unknown144);
	opw8_load9cf5e0(stream,&unknown148);
	opw8_load9d8480(stream,&unknown158);
	opw8_load9cf520(stream,&unknown15C);
	opw8_load9d93c0(stream,&unknown160);
	opw8_load4096f0(stream,&unknown170);
	opw8_load4096f0(stream,&unknown18C);
	opw8_load9d8480(stream,&unknown1A8);
	opw8_load4096f0(stream,&unknown1AC);
	opw8_load9d8480(stream,&unknown1C8);
	opw8_load9d4ec0(stream,unknown1CC);
	opw8_load465ea0(stream,&unknown1DC);
	opw8_load9d8480(stream,&unknown1E0);
	opw8_load9d8480(stream,&unknown1E4);
	opw8_load9d8480(stream,&unknown1E8);
	opw8_load9d8480(stream,&unknown1EC);
	opw8_load9d8480(stream,&unknown1F0);
	opw8_load9d4ec0(stream,unknown1F4);
	unknown210.load(stream);
	opw8_load9d8480(stream,&unknown218);
	opw8_load9d8480(stream,&unknown21C);
	opw8_load9d8480(stream,&unknown220);
	opw8_load9d8480(stream,&unknown224);
	opw8_load9d8480(stream,&unknown228);
}

bool Entity::unknown5dc680(HItem item)
{
	return item->unknown9b4350()->unknownB8 == 0 && item->unknown457f90() != 0xa7 && item->unknown457f90() != 0xb4 && unknown5dc440(item) == 0;
}

extern int opw8_cf473c;	// NOTE: placeholder name
extern bool opw8_d28e7d;	// NOTE: placeholder name

int Entity::unknown5db3c0(HItem item, bool checkFloor, bool quiet)
{
	if (opw8_cf473c != 0 && item->unknown44aec0() <= 3)
		return 0xb;
	if (item->unknown577fb0())
	{
		switch (item->unknown9b4350()->unknownEC)
		{
			case 1:
			case 2:
				return 0xc;
			case 3:
				return 0xd;
			case 4:
				return 0xe;
		}
	}
	if (item->getEffect(0x6c) != 0)
		return 0x22;
	if (checkFloor && opw8_d28e7d && cells(getPosition())->getItem().isValid())
	{
		if (getPosition() != opw8_cec088->unknown1C0 || opw8_tickCount > opw8_cec088->unknown1BC + 8000)
		{
			opw8_cec088->unknown1C0.assign(getPosition());
			opw8_cec088->unknown1BC = opw8_tickCount;
			return 8;
		}
	}
	if (!quiet && opw8_tickCount > opw8_cec088->unknown19C + 8000 && !item->unknown9b4350()->unknown1AC && item->getEffect(0x6e) == 0)
	{
		Point dropPos;
		if (!world->unknown71bc10(world->getPlayer()->getPosition(),&dropPos))
		{
			opw8_cec088->unknown19C = opw8_tickCount;
			return 9;
		}
	}
	return 0;
}

extern unsigned char opw8_caed27;	// NOTE: placeholder name
extern int opw8_d28e1c;	// NOTE: placeholder name
extern int opw8_cefc6c;	// NOTE: placeholder name

int Entity::unknown5db5f0(HItem item, bool ignoreSlots, bool ignoreStorage, bool quiet)
{
	int slot = item->unknown4578a0();
	if (slot == 5 || item->getEffect(0x56) != 0)
		return 0xf;
	if (opw8_cf462c == 0xb)
		return 0x10;
	if (!quiet && item->unknown415ee0() && opw8_cf4830[item->unknown457820()] != 0)
	{
		if (item != opw8_cec088->unknown178 || opw8_tickCount > opw8_cec088->unknown17C + 8000)
		{
			opw8_cec088->unknown178 = item;
			opw8_cec088->unknown17C = opw8_tickCount;
			return 0x15;
		}
	}
	if (!quiet && item->unknown457db0())
	{
		if (item != opw8_cec088->unknown180 || opw8_tickCount > opw8_cec088->unknown184 + 8000)
		{
			opw8_cec088->unknown180 = item;
			opw8_cec088->unknown184 = opw8_tickCount;
			return 0x16;
		}
	}
	if (!quiet && item->unknown4579d0() && item->unknown4579f0().find(opw8_caed27,0) != string::npos && (item.notEqual_9b6510(opw8_cec088->unknown188) || opw8_tickCount > opw8_cec088->unknown18C + 8000))
	{
		opw8_cec088->unknown188 = item;
		opw8_cec088->unknown18C = opw8_tickCount;
		return 0x17;
	}
	if (opw8_d28e1c != 0 && opw8_inRange(9,item->unknown457880(),0xd) && item->unknown457880() != opw8_d28e1c)
	{
		if (quiet || item != opw8_cec088->unknown190 || opw8_tickCount > opw8_cec088->unknown194 + 8000)
		{
			if (!quiet)
			{
				opw8_cec088->unknown190 = item;
				opw8_cec088->unknown194 = opw8_tickCount;
			}
			return 0x18;
		}
	}

	int total = 0;
	if (!ignoreSlots)
	{
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown4578a0() == slot && parts[i]->unknown44aec0() <= 3)
				total += parts[i]->unknown4578c0();
		}
		if (item->unknown4578e0())
		{
			if (item->unknown4578c0() + total > slots[slot])
				return 0x11;
			total += opw8_cec088->unknown8985d0(slot);
			if (item->unknown4578c0() + total > slots[slot])
				return 0x12;
		}
		else if (item->unknown4578c0() + total > slots[slot])
			return 0x13;
	}
	if (!ignoreStorage && unknown90 < unknown5cb760())
	{
		opw8_cefc68 = unknown5cb760();
		return 1;
	}
	if (!ignoreStorage && unknown94 < unknown5cb7a0())
	{
		opw8_cefc6c = unknown5cb7a0();
		return 0x14;
	}
	if (!ignoreSlots && !quiet && item->unknown4578c0() > opw8_cec088->unknown8986c0(item->unknown4578a0()) && opw8_tickCount > opw8_cec088->unknown198 + 8000)
	{
		opw8_cec088->unknown198 = opw8_tickCount;
		return 0x19;
	}
	return 0;
}

unsigned int Entity::unknown5d47c0(HEntity target, vector<HItem> *out, vector<HItem> *related)
{
	vector<HItem> candidates;
	int bestType = opw8_caf164;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == 0x7c)
		{
			if (parts[i]->unknown457820() == bestType)
				candidates.push_back(parts[i]);
			else if (bestType == opw8_caf164)
			{
				switch (parts[i]->unknown457fb0())
				{
					case 0:
						if (target->getAiType() != 1 || target->getGroup()->unknown9b4350() != 3 || parts[i]->getName(0,0).find(opw8_factionNames[target->getFaction()],0) == string::npos)
							goto nextPart;
						break;
					case 1:
						if (target->getGroup()->unknown9b4350() == 4 || (target->getGroup()->unknown9b4350() == 3 && (target->getFaction() == 9 || target->getFaction() == 0xc || target->getFaction() == 0x13 || target->getFaction() == 0x14 || target->getFaction() == 6 || target->getFaction() == 4 || target->getFaction() == 2 || target->getFaction() == 5 || target->getFaction() == 8)) || (target->getGroup()->unknown9b4350() == 5 && target->getFaction() == 0x1d))
							break;
						goto nextPart;
					case 2:
						if (target->getGroup()->unknown9b4350() != 3 || target->getAiType() != 1 || (target->getFaction() != 0xd && target->getFaction() != 0x10 && target->getFaction() != 0x11 && target->getFaction() != 0x12))
							goto nextPart;
						break;
					case 3:
						if (target->getGroup()->unknown9b4350() != 3 || target->getAiType() != 2 || target->getInfo()->unknownAC != 0)
							goto nextPart;
				}
				candidates.push_back(parts[i]);
				bestType = parts[i]->unknown457820();
			}
		}
nextPart:;
	}
	if (!candidates.empty())
		opw8_sortParts(&candidates,out);
	if (related != 0)
	{
		candidates.clear();
		for (unsigned int j = 0; j < parts.size(); j++)
		{
			if (parts[j]->unknown457820() == bestType && parts[j]->unknown44aec0() == 4 && !parts[j]->unknown457d10())
				candidates.push_back(parts[j]);
		}
		if (!candidates.empty())
			opw8_sortParts(&candidates,related);
	}
	return out->size();
}

extern string opw8_machineNames[];	// NOTE: placeholder name (0xcfaca0)
extern bool opw8_d1ebed;	// NOTE: placeholder name

class OpW8_Cf1080	// NOTE: placeholder name
{
public:
	void unknown451400(int value);	// NOTE: placeholder name (ICF'd trivial setter)
};
extern OpW8_Cf1080 opw8_cf1080;	// NOTE: placeholder name
void unknown4541b0(int a, int b, int c);	// NOTE: placeholder name

void Entity::unknown5d3830()
{
	vector<Point> adjacent;
	sweepGetSurroundingCells(unknown45a4c0(),adjacent);
	for (unsigned int i = 0; i < adjacent.size(); i++)
	{
		if (cells(adjacent[i])->isMachinePart())
		{
			OpW8_Zone *zone = world->getZone(adjacent[i]);
			if (!zone->machine->identified && (zone->machine->type == 0x1f || zone->machine->type == 0x1e))
			{
				world->unknown71dd30(zone->machine);
				zone->unknown6c16d0("IDENTIFIED");
				opw8_cec054->unknown80e3a0(1,zone);
				string msg("FARCOM_MSG: ");
				const string &label = opw8_machineNames[zone->machine->type];
				if (opw8_d1ebed)
					msg += "Danger! You're approaching an entrance to " + label + "!";
				else
				{
					opw8_d1ebed = true;
					switch (rng.rangeInt(0,6.0f))
					{
						case 0:
							msg += "Whoa there, are you sure you want to do that? " + label + "? Bad things will happen to you.";
							break;
						case 1:
							msg += "While we would love for you to report back what you find inside " + label + ", your report would likely be very, very short.";
							break;
						case 2:
							msg += label + "? Only the best science in there, but if you head that way our totally scientific relationship with you will likely come to an end.";
							break;
						case 3:
							msg += "We cannot in good conscience advise you to enter " + label + " at this time. EX-BIN: It would be funny, though.";
							break;
						case 4:
							msg += "I finished my Atomic Chain Massager. We'll give it to the next anonymous tester bot for their inevitably unsafe journey into " + label + ". You stay out.";
							break;
						case 5:
							msg += "In case you forgot, our tech and " + label + " do not mix. It's like fire and water. Assembled and Derelicts. Imprinter and sanity.";
							break;
						case 6:
							msg += "We can't do much more than enjoy the fireworks if you do decide to enter " + label + ". EX-BIN: Is laughing hysterically on the table?";
							break;
					}
				}
				do
				{
					opw8_cf1080.unknown451400(1);
					if (0)
						unknown4541b0(-1,0,0);
					do
					{
						if (opw8_unknown5111e0(0x324,&msg,0,0,HEntity(),HProp(),0,0))
							opw8_cec058->unknown8758d0(true);
						opw8_logMsgs->scrollToEnd();
					} while (0);
					opw8_logMsgs->scrollToEnd();
				} while (0);
			}
		}
	}
}

extern bool opw8_cf49f0;	// NOTE: placeholder name

class OpW8_StatTracker	// NOTE: placeholder name (object at 0xd2c658)
{
public:
	vector<int> *values;	// NOTE: placeholder name
	bool unknown4729d0(int id, int value, string text, int flag);	// NOTE: placeholder name
	void unknown472b90(int a, int b);	// NOTE: placeholder name
};
extern OpW8_StatTracker opw8_statTracker;	// NOTE: placeholder name

int Entity::unknown5defa0(int amount, bool notify)
{
	bool player = isPlayer();
	if (opw8_cf49f0 && player)
	{
		do
		{
			if (opw8_unknown5111e0(0x15e,&intToString(amount),0,0,self,HProp(),0,0))
				opw8_cec058->unknown8758d0(true);
			opw8_logMsgs->scrollToEnd();
		} while (0);
		return 0;
	}
	if (unknown5d2380(0x2b).isValid())
	{
		vector<HItem> list;
		vector<HItem> ordered;
		if (unknown5d2430(0x2b,&list))
		{
			ordered.push_back(list[0]);
			for (unsigned int i = 1; i < list.size(); i++)
			{
				if (list[i]->unknown9b6bf0() >= ordered.back()->unknown9b6bf0())
					ordered.push_back(list[i]);
				else
				{
					for (unsigned int j = 0; j < ordered.size(); j++)
					{
						if (list[i]->unknown9b6bf0() < ordered[j]->unknown9b6bf0())
						{
							opw8_insertItem(ordered,j,list[i]);
							break;
						}
					}
				}
			}
			for (unsigned int k = 0; k < ordered.size(); k++)
			{
				int cost = ordered[k]->unknown9b6bf0() / 2;
				if (cost * 2 < ordered[k]->unknown9b6bf0())
					cost++;
				if (cost <= amount)
				{
					do
					{
						if (opw8_unknown5111e0(0x62,&ordered[k]->getName(0,0),&intToString(cost),0,self,HProp(),0,0))
							opw8_cec058->unknown8758d0(true);
						opw8_logMsgs->scrollToEnd();
					} while (0);
					do
					{
						if (opw8_unknown5111e0(0x61,&ordered[k]->getName(0,0),0,0,self,HProp(),0,0))
							opw8_cec058->unknown8758d0(true);
						opw8_logMsgs->scrollToEnd();
					} while (0);
					if (player)
						opw8_statTracker.unknown4729d0(0x1c3,cost,"",-1);
					ordered[k]->unknown57dbe0(1,0,7,1);
					amount -= cost;
				}
				else
				{
					do
					{
						if (opw8_unknown5111e0(0x62,&ordered[k]->getName(0,0),&intToString(amount),0,self,HProp(),0,0))
							opw8_cec058->unknown8758d0(true);
						opw8_logMsgs->scrollToEnd();
					} while (0);
					if (player)
						opw8_statTracker.unknown4729d0(0x1c3,amount,"",-1);
					ordered[k]->unknown458310(amount * 2);
					if (player)
					{
						CPart *part = opw8_cec088->unknown894e70(ordered[k]);
						if (part != 0)
							part->drawStatus(true);
					}
					amount = 0;
				}
				if (amount == 0)
					break;
			}
		}
	}
	if (notify)
		world->unknown7276b0(self,&amount);
	unknownB0 += amount;
	return amount;
}

struct OpW8_PartEntry	// NOTE: placeholder name
{
	HItem getItem();	// NOTE: placeholder name (0x4b1b30)
};

string opw8_countString(int count, const string &noun);	// NOTE: placeholder name (0x407a80)
extern bool opw8_d28e5d;	// NOTE: placeholder name

int Entity::unknown5dbb60(HItem item, int extra, bool ignoreMass, bool quiet)
{
	if (opw8_cf473c != 0)
		return 0xb;
	if (item->unknown577fb0())
	{
		switch (item->unknown9b4350()->unknownEC)
		{
			case 1:
			case 2:
				return 0xc;
			case 3:
				return 0xd;
			case 4:
				return 0xe;
		}
	}
	if (item->getEffect(0x6c) != 0 || opw8_cf462c == 0xb)
		return 0x22;
	if (unknown90 < unknown5cb7f0())
	{
		opw8_cefc68 = unknown5cb7f0();
		return 1;
	}

	int base = isPlayer() ? opw8_cf496c : record->unknown1C8;
	int bonus = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == 7 && parts[i] != item && parts[i]->unknown457fb0() > bonus)
			bonus = parts[i]->unknown457fb0();
	}
	int capacity = opw2_maxInt(bonus,extra) + base;
	int mass = unknown5c8e20(0);
	if (item->unknown457f90() == 7 && mass > capacity)
	{
		if (item != opw8_cec088->unknown13C || opw8_tickCount > opw8_cec088->unknown15C + 8000)
		{
			opw8_cec088->unknown13C = item;
			opw8_cec088->unknown140 = opw8_countString(mass - capacity,"item");
			opw8_cec088->unknown15C = opw8_tickCount;
			return 0x1b;
		}
		if (opw8_tickCount > opw8_cec088->unknown19C + 8000)
		{
			Point target(world->getPlayer()->getPosition());
			int toDrop = mass - capacity;
			toDrop++;
			vector<HItem> spawned;
			Point freePos;
			for (int k = 0; k < toDrop; k++)
			{
				if (!world->unknown71bc10(target,&freePos))
					break;
				spawned.push_back(world->unknown71e7c0(freePos,1,0));
			}
			int fails = toDrop - spawned.size();
			for (unsigned int m = 0; m < spawned.size(); m++)
				spawned[m]->unknown57dbe0(0,1,1,1);
			spawned.clear();
			if (fails != 0)
			{
				opw8_cec088->unknown19C = opw8_tickCount;
				opw8_cec088->unknown1A0 = opw8_countString(fails,"random item");
				return 10;
			}
		}
	}
	if (item->unknown457f90() == 0xd4 && (item != opw8_cec088->unknown168 || opw8_tickCount > opw8_cec088->unknown16C + 8000))
	{
		vector<OpW8_PartEntry *> *entries = opw8_cec088->unknown4a9ad0();
		for (unsigned int n = 0; n < entries->size(); n++)
		{
			if ((*entries)[n]->getItem() == item)
			{
				opw8_cec088->unknown4a9d40(item);
				return 0x1c;
			}
		}
	}
	if (opw8_cec088->unknown4a9b10(item) && (item != opw8_cec088->unknown170 || opw8_tickCount > opw8_cec088->unknown174 + 8000))
	{
		opw8_cec088->unknown4a9d90(item);
		return 0x1d;
	}
	if ((item->unknown9b4350()->unknown1AC || item->getEffect(0x6e) != 0) && (item != opw8_cec088->unknown160 || opw8_tickCount > opw8_cec088->unknown164 + 8000) && !opw8_d28e5d)
	{
		opw8_cec088->unknown4a9cf0(item);
		return 0x1e;
	}
	if ((!ignoreMass && item->unknown4578c0() + mass > capacity) || quiet)
	{
		if (opw8_tickCount > opw8_cec088->unknown19C + 8000 && !item->unknown9b4350()->unknown1AC && item->getEffect(0x6e) == 0)
		{
			Point dropPos;
			if (!world->unknown71bc10(world->getPlayer()->getPosition(),&dropPos))
			{
				opw8_cec088->unknown19C = opw8_tickCount;
				return 9;
			}
		}
		if (!quiet)
			return 7;
	}
	return 0;
}

class BS	// NOTE: placeholder name (same object as world)
{
public:
	int opw3_unknown727c70(HEntity e, int value);	// NOTE: placeholder name
};
extern bool opw8_cefc8a;	// NOTE: placeholder name
extern int opw8_table_b9602c[];	// NOTE: placeholder name
extern float opw8_b97638;	// NOTE: placeholder name (2.0)
extern float opw8_ba09c4;	// NOTE: placeholder name (2.0)

int Entity::unknown5d15a0(bool notify)
{
	int moveType = unknown5d1390();
	int partCount = 0;
	int baseTime = 0;
	int penaltySum = 0;
	int legTime = 0;
	int overload = 0;
	int doubled = 0;
	vector<HItem> list;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == 1)
		{
			if (parts[i]->unknown457cf0())
			{
				if (list.empty() || parts[i]->unknown577e60() <= list.back()->unknown577e60())
					list.push_back(parts[i]);
				else
				{
					for (unsigned int j = 0; j < list.size(); j++)
					{
						if (parts[i]->unknown577e60() > list[j]->unknown577e60())
						{
							opw8_insertItem(list,j,parts[i]);
							break;
						}
					}
				}
			}
			else if (parts[i]->unknown44aec0() <= 3 && parts[i]->unknown457880() <= 0xb)
				legTime += parts[i]->unknown457f50();
		}
	}
	int wt = unknown5c8cb0();
	int maxMass = unknown5d1ee0();
	for (unsigned int k = 0; k < list.size(); k++)
	{
		for (int m = 0; m < (list[k]->unknown458220() && list[k]->unknown457f70() != 0 ? 2 : 1); m++)
		{
			partCount++;
			baseTime += list[k]->unknown577c90();
			penaltySum += list[k]->unknown457f30();
			if (m > 0)
				doubled++;
			overload += list[k]->unknown577f30();
		}
	}
	if (notify)
	{
		opw8_statTracker.unknown4729d0(0xc1,wt,"",-1);
		if ((*opw8_statTracker.values)[0xc1] >= 0x96)
			opw8_playerData.unknown77fbc0(0x9c);
		opw8_statTracker.unknown4729d0(0xc2,maxMass,"",-1);
		if (wt > maxMass)
		{
			opw8_statTracker.unknown4729d0(0xc3,unknown5c8d40(wt,maxMass),"",-1);
			opw8_itemFactory->unknown793450(0x2f,1,0,0,0);
		}
		opw8_statTracker.unknown4729d0(0xc4,unknown5c8d40(wt,maxMass),"",-1);
	}
	if (partCount != 0)
	{
		baseTime /= partCount;
		baseTime = (float)penaltySum / partCount * (partCount - 1) + baseTime;
	}
	else
	{
		baseTime = 50;
		overload = 50;
		partCount = 1;
	}
	if (unknownF0 != 0 && unknownF0->unknown458950(0x35) != 0)
		baseTime *= opw8_b97638;
	if (moveType >= 3 && unknown5d2380(0x26).isValid())
		baseTime /= 2;
	if (wt > maxMass)
		baseTime += overload / partCount * unknown5c8d40(wt,maxMass);
	int reduction = 0;
	switch (moveType)
	{
		case 0:
			reduction = unknown5d22a0(0x23);
			if (reduction != 0)
				baseTime = baseTime / (1 + reduction / 100.0);
			break;
		case 1:
			reduction = opw2_maxInt(unknown5d22a0(0x24),unknown5d22a0(0x23));
			if (reduction != 0)
				baseTime = baseTime / (1 + reduction / 100.0);
			if (unknown5cad50() != 0 && opw8_cefb38 == 3)
				baseTime *= opw8_ba09c4;
			break;
		case 2:
			reduction = opw2_maxInt(wt <= maxMass ? unknown5d22a0(0x25) : 0,unknown5d22a0(0x23));
			if (reduction != 0)
				baseTime = baseTime / (1 + reduction / 100.0);
			break;
	}
	if (moveType >= 3 && moveType != 6)
	{
		baseTime += legTime;
		if (legTime != 0 && notify)
			opw8_itemFactory->unknown793450(0x30,1,0,0,0);
	}
	if (moveType >= 3 && baseTime < 0x32)
		baseTime = ((BS *)world)->opw3_unknown727c70(self,baseTime);
	else if (notify)
		opw8_cefc8a = false;
	if (partCount == 1 && !list.empty() && list.front()->unknown457860() == "T-thruster")
		return baseTime;
	opw8_atLeast(&baseTime,opw8_table_b9602c[moveType]);
	if (baseTime == opw8_table_b9602c[moveType] && doubled != 0)
	{
		baseTime -= doubled;
		opw8_atLeast(&baseTime,5);
	}
	return baseTime;
}

HItem Entity::unknown5d2d60(HEntity other, int *counter)
{
	if (other->unknown45a8b0() != 0)
		*counter += 5;
	for (unsigned int i = 0; i < other->parts.size(); i++)
	{
		if (other->parts[i]->unknown457cd0() != 0)
			*counter += 2;
	}
	int total = 0;
	for (unsigned int j = 0; j < other->record->unknown160.size(); j++)
		total += other->record->unknown160[j][0]->count;
	if (other->parts.size() < total)
		*counter += (total - other->parts.size()) * 2;

	bool found = false;
	vector<HItem> available;
	vector<HItem> partialList;
	for (unsigned int k = 0; k < parts.size(); k++)
	{
		if (parts[k]->unknown44aec0() != 4 && parts[k]->unknown457f90() == 0xa7 && parts[k]->unknown458080() == other->unknown9b4350() && parts[k]->unknown457d70() && parts[k]->unknown44ab90() <= world->getTurn())
		{
			found = true;
			if (*counter == 0 || parts[k]->unknown9b6bf0() - *counter >= 10)
			{
				if (parts[k]->unknown45cb30() < parts[k]->unknown457fb0())
					return parts[k];
				else
					available.push_back(parts[k]);
			}
			else if (parts[k]->unknown45cb30() < parts[k]->unknown457fb0())
				partialList.push_back(parts[k]);
		}
	}
	if (found)
	{
		for (unsigned int m = 0; m < parts.size(); m++)
		{
			if (parts[m]->unknown44aec0() == 4 && parts[m]->unknown457f90() == 0xa7 && parts[m]->unknown458080() == other->unknown9b4350() && parts[m]->unknown457d70() && parts[m]->unknown44ab90() <= world->getTurn())
			{
				found = true;
				if (*counter == 0 || parts[m]->unknown9b6bf0() - *counter >= 10)
				{
					if (parts[m]->unknown45cb30() < parts[m]->unknown457fb0())
						return parts[m];
					else
						available.push_back(parts[m]);
				}
				else if (parts[m]->unknown45cb30() < parts[m]->unknown457fb0())
					partialList.push_back(parts[m]);
			}
		}
	}
	if (found && *counter != 0)
	{
		if (!partialList.empty() && !available.empty())
		{
			HItem source = partialList[0];
			for (unsigned int n = 1; n < partialList.size(); n++)
			{
				if (partialList[n]->unknown9b6bf0() > source->unknown9b6bf0())
					source = partialList[n];
			}
			HItem lowest = available[0];
			for (unsigned int q = 1; q < available.size(); q++)
			{
				if (available[q]->unknown9b6bf0() < source->unknown9b6bf0())
					lowest = available[q];
			}
			source->unknown44fc60(source->unknown45cb30() + 1);
			CPart *cpart = opw8_cec088->unknown894e70(source);
			if (cpart != 0)
			{
				cpart->unknown4a8fc0();
				if (source->unknown457cf0())
					opw8_cec088->unknown8993e0(cpart,0);
			}
			else
				opw8_cec08c->opw8_reopen(5,source);
			lowest->unknown44fc60(lowest->unknown45cb30() - 1);
			return lowest;
		}
		*counter = -1;
	}
	return HItem();
}

struct OpW8_PropType	// NOTE: placeholder name
{
	char pad00[0xf8];
	int unknownF8;
};

struct OpW8_Marker	// NOTE: placeholder name
{
	void unknown6c20b0(int type, const Point &p, int value);	// NOTE: placeholder name

	char pad00[8];
	Point pos;
};

class HMarker
{
public:
	int ID;
	HMarker();
	OpW8_Marker *operator->() const;	// 0x9b7cd0
};

struct OpW8_Cf6478	// NOTE: placeholder name
{
	bool unknown45e820();	// NOTE: placeholder name

	int unknown00;
	HEntity entity;
};

class OpW8_Dijkstra	// NOTE: placeholder name (object at 0xcfe568)
{
public:
	void unknown40ca20(const Point &start, int range, int *table, int *flag);	// NOTE: placeholder name
};

void clearDijkstraResults();
int opw8_takeRandom9de500(vector<int> &values);	// NOTE: placeholder name
void opw8_eraseMarkerStepBack(vector<HMarker> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440)
extern OpW8_Dijkstra opw8_cfe568;	// NOTE: placeholder name
extern int opw8_d297a8[];	// NOTE: placeholder name
extern vector<Point> opw8_d15e58;	// NOTE: placeholder name
extern vector<int> opw8_cf4910;	// NOTE: placeholder name
extern vector<OpW8_Cf6478 *> opw8_cf6478;	// NOTE: placeholder name
extern int opw8_table_bba058[];	// NOTE: placeholder name

void Entity::unknown5da0a0()
{
	int searchType = 9;
	int stat;
	HEntity entity = self;
	if (group->unknown9b4350() == 4)
	{
		switch (record->unknown28)
		{
			case 1:
			{
				Point p;
				if (world->unknown463040() && entity->getAI()->unknown5b6130(&p))
				{
					opw8_playerData.unknown780810(entity,5,-1);
					cells(p)->getProp()->unknown65f170();
					world->unknown4647d0(p);
					opw8_cec054->unknown813050(1,cells(p)->getProp(),0,0,0);
					world->unknown9e29b0(&world->unknown720,cells(p)->getProp());
					opw8_cec054->unknown49b690(p);
				}
			}
				break;
			case 2:
				opw8_playerData.unknown780810(entity,10,-1);
				opw8_cec054->unknown8071e0(entity,1);
				break;
			case 5:
				world->unknown724cf0();
				searchType = 3;
				stat = 0x12;
				break;
			case 4:
			{
				searchType = 1;
				stat = 0xd;
				vector<Point> path;
				if (world->unknown716c30(entity->getPosition(),entity.operator->(),&path))
				{
					opw8_playerData.unknown780810(entity,0xe,-1);
					Point target(path.back());
					bool exists = false;
					vector<HMarker> &markers = (*world->unknown463ec0())[0];
					for (unsigned int i = 0; i < markers.size(); i++)
					{
						if (markers[i]->pos == target)
						{
							exists = true;
							break;
						}
					}
					if (!exists && !world->unknown463160(target))
					{
						vector<HMarker> &list = (*world->unknown463ec0())[0];
						list.push_back(opw8_itemFactory->unknown793190());
						list.back()->unknown6c20b0(0,target,cells(target)->getProp()->unknown9b8f00()->unknownF8);
						opw8_cec034->unknown987de0();
					}
					world->unknown729eb0(target,"DSF Access",1,1);
				}
				vector<Point> *spots = world->unknown463c20();
				vector<Point> available;
				HItem item;
				for (unsigned int j = 0; j < spots->size(); j++)
				{
					item = cells((*spots)[j])->getItem();
					if (item.isNull())
						opw8_erasePointStepBack(*spots,j);
					else if (item->unknown9b4350()->unknown94 == 0)
						available.push_back((*spots)[j]);
				}
				if (!available.empty())
				{
					opw8_playerData.unknown780810(entity,0x11,-1);
					int type = 0xe;
					vector<HMarker> &list = (*world->unknown463ec0())[type];
					list.clear();
					for (unsigned int k = 0; k < available.size(); k++)
					{
						list.push_back(opw8_itemFactory->unknown793190());
						list.back()->unknown6c20b0(type,available[k],cells(available[k])->getItem()->unknown457820());
						world->unknown4647d0(available[k]);
					}
					opw8_cec034->unknown987de0();
				}
			}
				break;
			case 8:
				searchType = 2;
				stat = 0x14;
				break;
			case 9:
			case9:
				searchType = 0;
				stat = 0x19;
				break;
			case 20:
			case20:
				searchType = 4;
				stat = 0x27;
				int location = opw8_d1e888->unknown46ed20();
				vector<int> candidates;
				for (int i = 0; i < opw8_d25de0.size(); i++)
				{
					if (!opw8_d25de0[i]->unknown170.empty() && opw8_d25de0[i]->unknown24 == 1 && opw8_inRange(location - 2,opw8_d25de0[i]->unknown68,location + 2) && opw8_cf4910[i] == 0)
						candidates.push_back(i);
				}
				vector<unsigned int> chosen;
				int count = rng.rangeInt(3.0f,5.0f);
				for (int n = 0; n < count; n++)
				{
					if (candidates.empty())
						break;
				chosen.push_back(opw8_takeRandom9de500(candidates));
			}
			if (!chosen.empty())
			{
				opw8_playerData.unknown780810(entity,0x2c,-1);
				for (unsigned int m = 0; m < chosen.size(); m++)
					opw8_playerData.unknown780700(m,0);
			}
				break;
		}
	}
	else if (group->unknown9b4350() == 3)
	{
		switch (record->unknown28)
		{
			case 12:
			{
				if (unknown144->unknown9b8f00() == 2 && unknown144->unknown458ef0()->size() == 2)
				{
					opw8_playerData.unknown780810(entity,0x22,-1);
					opw8_cec054->unknown8074d0(entity);
				}
				opw8_playerData.unknown780810(entity,0x23,-1);
				int before = 0;
				int added = 0;
				int id = 0;
				int markerType = 2;
				vector<HMarker> &list = (*world->unknown463ec0())[markerType];
				before = list.size();
				bool update = false;
				for (unsigned int i = 0; i < list.size(); i++)
				{
					if (opw8_pointDistance(list[i]->pos,entity->getPosition()) <= 0x28)
					{
						opw8_eraseMarkerStepBack(list,i);
						update = true;
					}
				}
				for (unsigned int j = 0; j < opw8_cf6478.size(); j++)
				{
					if (opw8_cf6478[j]->unknown00 == id && !opw8_cf6478[j]->unknown45e820() && opw8_pointDistance(opw8_cf6478[j]->entity->getPosition(),entity->getPosition()) <= 0x28)
					{
						added++;
						update = true;
						list.push_back(opw8_itemFactory->unknown793190());
						list.back()->unknown6c20b0(markerType,opw8_cf6478[j]->entity->unknown45a4c0(),-1);
					}
				}
			}
				break;
			case 9:
				goto case9;
			case 20:
				goto case20;
		}
		if (entity->getGroup()->unknown9b4350() == 3 && entity->getAiType() == 1 && opw8_table_bba058[entity->getFaction()] >= 6 && entity->getFaction() != 0x14)
		{
			searchType = 5;
			stat = 0x30;
			opw8_playerData.unknown780810(entity,0x2f,-1);
			clearDijkstraResults();
			int flag = 1;
			opw8_cfe568.unknown40ca20(entity->getPosition(),0x32,opw8_d297a8,&flag);
			if (!opw8_d15e58.empty())
			{
				for (unsigned int i = 0; i < opw8_d15e58.size(); i++)
				{
					world->unknown734d60(opw8_d15e58[i]);
					world->unknown4647a0(opw8_d15e58[i],1);
					opw8_cec054->unknown80e3a0(1,opw8_d15e58[i]);
				}
			}
		}
	}
	if (searchType != 9)
	{
		vector<Point> route;
		if (world->unknown716a60(entity->getPosition(),searchType,entity.operator->(),&route))
		{
			opw8_playerData.unknown780810(entity,stat,-1);
			Point target(route.back());
			bool exists = false;
			vector<HMarker> &markers = (*world->unknown463ec0())[0];
			for (unsigned int i = 0; i < markers.size(); i++)
			{
				if (markers[i]->pos == target)
				{
					exists = true;
					break;
				}
			}
			if (!exists && !world->unknown463160(target))
			{
				vector<HMarker> &list = (*world->unknown463ec0())[0];
				list.push_back(opw8_itemFactory->unknown793190());
				list.back()->unknown6c20b0(0,target,cells(target)->getProp()->unknown9b8f00()->unknownF8);
				opw8_cec034->unknown987de0();
			}
		}
	}
}

Point::Point(int x_, int y_)
{
	x = x_;
	y = y_;
}

Point::Point(const Point &p)
{
	x = p.x;
	y = p.y;
}

struct OpW8_EntityEC	// NOTE: placeholder name (0x14 bytes)
{
	OpW8_EntityEC();	// 0x456260
	void unknown518b30() throw();	// NOTE: placeholder name
	void unknown4566c0(vector<int> values);	// NOTE: placeholder name

	vector<int> unknown00;
	int unknown10;
};

OpW8_EntityEC::OpW8_EntityEC()
{
	unknown518b30();
}

class OpW8_WeightedTable	// NOTE: placeholder name
{
public:
	OpW8_WeightedTable();	// NOTE: placeholder name (0x9bab50)
	OpW8_WeightedTable(const int *weights, int count);	// NOTE: placeholder name (0x9ba790)
	~OpW8_WeightedTable();	// NOTE: placeholder name (0x700dd0)
	void add(int value, int weight);	// NOTE: placeholder name (0x9ba310)
	void remove(int value);	// NOTE: placeholder name (0x9bab80)
	unsigned int size();	// NOTE: placeholder name (0x9b81d0)
	int &pick() throw();	// NOTE: placeholder name (0x9ba470)

	vector<int> values;
	vector<int> weights;
	int unknown20;
};

string &opw8_padLeft(string &s, int width, char c);	// NOTE: placeholder name (0x408090)
char opw8_randomChar(const string &chars);	// NOTE: placeholder name (0x4085b0)
void opw8_copyInts(const int *src, int *dst, int count);	// NOTE: placeholder name (0x9d9460)
extern string opw8_d38e40[];	// NOTE: placeholder name
extern string opw8_d20260[];	// NOTE: placeholder name
extern int opw8_d1eb58;	// NOTE: placeholder name
extern int opw8_d1eb5c;	// NOTE: placeholder name
extern int opw8_caf2b8[];	// NOTE: placeholder name
extern int opw8_caf43c;	// NOTE: placeholder name
extern vector<int> opw8_d2f0f8;	// NOTE: placeholder name
extern int opw8_ba773c[];	// NOTE: placeholder name
extern int opw8_ba7704[];	// NOTE: placeholder name
extern int opw8_cf471c;	// NOTE: placeholder name
extern int opw8_b95a1c[];	// NOTE: placeholder name

Entity::Entity(OpW8_EntityRecord *record_)
{
	unknown00 = opw8_playerData.unknown46dec0();
	self.opw8_reset();
	record = record_;
	name = record->unknown1AC;
	if (record->unknown24 == 3)
	{
		if (record->unknown28 == 0x3b || record->unknown28 == 0x3c || record->unknown28 == 0x3d)
		{
			switch (record->unknown28)
			{
				case 0x3b:
					name = "AS-";
					break;
				case 0x3c:
					name = "as-";
					break;
				case 0x3d:
					name = "AG-";
					break;
			}
			name += opw8_padLeft(intToString(rng.rangeInt(0.0f,99999.0f)),5,'0');
		}
		else if (record->unknown28 == 0x2e || record->unknown28 == 0x2f)
		{
			name += opw8_padLeft(intToString(opw8_d1e888->depth),2,'0');
			name += opw8_d38e40[opw8_d1e888->unknown04];
			int &counter = record->unknown28 == 0x2e ? opw8_d1eb58 : opw8_d1eb5c;
			counter++;
			if (counter <= 99)
				name += opw8_padLeft(intToString(counter),2,'0');
			else
			{
				int over = counter - 100;
				if (over > 0x2a4)
					name += "**";
				else
				{
					name += (char)(over / 26 + 'A');
					name += (char)(over % 26 + 'A');
				}
			}
			name += record->unknown28 == 0x2e ? "-D" : "-K";
		}
		else if (record->name[0] == 'L' && record->name[1] == 'u' && record->name[2] == 'g')
		{
			name += " ";
			for (int i = 0; i < 3; i++)
				name += intToString(rng.rangeInt(0.0f,9.0f));
		}
		else
		{
			name.clear();
			record->unknown459d00(&name);
		}
	}
	if (record->unknown28 == 0x1b)
	{
		name = "Q";
		for (int i = 0; i < 3; i++)
			name += intToString(rng.rangeInt(0.0f,9.0f));
		name += "-";
		string letters("abcdefghijklmnopqrstuvwxyz");
		name += opw8_randomChar(letters);
	}
	else if (record->unknown28 == 0x22 && record->name != "V2")
	{
		name = "V";
		for (int i = 0; i < 3; i++)
			name += intToString(rng.rangeInt(0.0f,9.0f));
		name += "-";
		string letters("abcdefghijklmnopqrstuvwxyz");
		name += opw8_randomChar(letters);
	}
	else if (record->name[0] == 'P' && record->name[1] == '_')
	{
		string chars("ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
		name = "P";
		name += (char)(isalpha(opw8_caf2b8[record->unknown28]) ? toupper(opw8_caf2b8[record->unknown28]) : (char)opw8_caf2b8[record->unknown28]);
		name += "-";
		for (int i = 0; i < 10; i++)
			name += opw8_randomChar(chars);
	}
	else if (record->unknown28 == 0x48)
	{
		OpW8_WeightedTable table;
		for (int i = 0; i < 0xe; i++)
		{
			if (opw8_d1e888->depth <= opw8_ba773c[i])
				table.add(i,opw8_ba7704[i]);
		}
		if (opw8_d1e888->unknown04 == 0x24)
			table.remove(8);
		if (table.size() != 0)
		{
			int choice = opw8_caf43c != 0xe ? opw8_caf43c : table.pick();
			opw8_caf43c = 0xe;
			Point *location = new Point(opw8_d2f0f8[0x28],choice);
			unknown45b340(location);
			name = opw8_d20260[location->y] + " Anomaly";
		}
	}
	group.opw8_reset();
	unknown2c = 0;
	for (int i = 0; i < record->type; i++)
		positions.push_back(Point(-100,-100));
	unknown40 = 0;
	unknown44.opw8_fill(-1);
	unknown4C = -1;
	unknown50 = 0;
	unknown54 = 0;
	unknown58 = 5;
	unknown5C = 0;
	unknown70 = 0;
	unknown74 = 0;
	opw8_copyInts(record->unknown1CC,slots,4);
	if (opw8_cf471c != 0)
	{
		OpW8_WeightedTable table(opw8_b95a1c,4);
		for (int i = 20 - sumArray(slots,4); i > 0; i--)
			slots[table.pick()]++;
	}
	unknown88 = record->unknownA4;
	unknown8C = record->unknown28 == 0 ? opw8_cf4954 : record->unknown1DC;
	unknown90 = record->unknown1E4;
	unknown94 = record->unknown28 == 0 ? (opw8_cf462c != 0xb ? 100 : 0) : opw2_maxInt(0,record->unknown1EC);
	unknown98 = 0;
	unknownAC = false;
	unknownB0 = 0;
	unknownB4 = record->unknown218;
	unknownB8 = record->unknown84 != 0 ? rng.chance(record->unknown84) : false;
	unknownBC = 0;
	unknownC0 = record->unknown28 == 10;
	unknownC4 = 0;
	unknownC8 = 0;
	unknownCC = 0;
	unknownD0 = 0;
	unknownD4 = 0;
	unknownD8 = 0;
	for (unsigned int i = 0; i < record->unknownC4.size(); i++)
		unknownDC.push_back(new Point(*record->unknownC4[i]));
	unknownEC = 0;
	if (!record->unknownD4.empty())
	{
		unknownEC = new OpW8_EntityEC();
		unknownEC->unknown4566c0(record->unknownD4);
	}
	unknownF0 = 0;
	unknown11C = 0;
	unknown120 = 0;
	unknown144 = 0;
}

extern int opw8_d2b4ec;	// NOTE: placeholder name
extern int opw8_d2b4f0;	// NOTE: placeholder name
extern int opw8_d1dafc;	// NOTE: placeholder name
extern int opw8_d1db00;	// NOTE: placeholder name

string Entity::unknown5cd670()
{
	string text;
	int value;
	value = unknown45acb0(0xd);
	if (value != 0)
	{
		if (!text.empty())
			text += "\n\n";
		text += "Sensor Jamming (" + intToString(value) + "): Prevents Sensor Arrays within a range of " + intToString(value) + " from pinpointing signals, but gives away its position in the process.";
	}
	value = unknown45acb0(0xe);
	if (value != 0)
	{
		if (!text.empty())
			text += "\n\n";
		text += "Core Regeneration (" + intToString(value) + "): Regenerates " + intToString(value) + " core integrity every turn.";
	}
	value = unknown45acb0(0xf);
	if (value != 0)
	{
		if (!text.empty())
			text += "\n\n";
		text += "Part Regeneration (" + intToString(value) + "): All attached parts regenerate " + intToString(value) + " integrity every turn. Also regenerates one missing part every ten turns.";
	}
	value = unknown45acb0(0x19);
	if (value != 0)
	{
		if (!text.empty())
			text += "\n\n";
		text += "Corruption Emission (" + intToString(value) + "): " + intToString(value) + "% chance each turn to cause anywhere from " + intToString(opw8_d2b4ec) + "-" + intToString(opw8_d2b4f0) + "% corruption in each robot in view and within a range of " + intToString(10) + ". (Cogmind is less susceptible to the effect and only suffers " + intToString(opw8_d1dafc) + "-" + intToString(opw8_d1db00) + "% corruption.)";
	}
	value = unknown45acb0(0x1b);
	if (value != 0)
	{
		if (!text.empty())
			text += "\n\n";
		text += "Energy Drain (" + intToString(value) + "): Each turn drains [" + intToString(value) + "-(range*" + intToString(2) + ")] energy from each robot in view and within a range of " + intToString(10) + ". Also drains an equivalent amount of heat.";
	}
	value = unknown45acb0(0x18);
	if (value != 0)
	{
		if (!text.empty())
			text += "\n\n";
		text += "Energy Emission (" + intToString(value) + "): Each turn transfers [" + intToString(value) + "-range] energy to each robot in view and within a range of " + intToString(value / 2) + ".";
	}
	value = unknown45acb0(0x1a);
	if (value != 0)
	{
		if (!text.empty())
			text += "\n\n";
		text += "Heat Emission (" + intToString(value) + "): Each turn transfers [" + intToString(value) + "-(range*" + intToString(10) + ")] heat to each robot in view and within a range of " + intToString(10) + ".";
	}
	value = unknown45acb0(0x10);
	if (value != 0)
	{
		if (!text.empty())
			text += "\n\n";
		text += "Scan Cloak (" + intToString(value) + "): Hides this robot from sensors without a Signal Interpreter of at least strength " + intToString(value) + ".";
	}
	value = unknown45acb0(0x12);
	if (value != 0)
	{
		if (!text.empty())
			text += "\n\n";
		text += "Self-destructing: Leaves no parts on destruction, unless self-destruct mechanism fails due to system corruption.";
	}
	return text;
}

struct OpW8_D02cb4	// NOTE: placeholder name
{
	char pad00[4];
	bool unknown04;
	char pad05[0x14 - 5];
	OpW8_EntityRecord *unknown14;
};

class OpW8_Cf6428	// NOTE: placeholder name
{
public:
	void unknown682420(int a, int b);	// NOTE: placeholder name
};

void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)
void opw8_appendItems(vector<HItem> &to, vector<HItem> &from);	// NOTE: placeholder name (0x9d49c0)
void opw8_unknown5141b0(int id, const string *a, const string *b, int c, HProp d, int e);	// NOTE: placeholder name
float maxf(float a, float b);
void opw8_unknown789ac0();	// NOTE: placeholder name
extern int opw8_cf46f4;	// NOTE: placeholder name
extern int opw8_cf4714;	// NOTE: placeholder name
extern float opw8_ba8798;	// NOTE: placeholder name (0.25)
extern int opw8_ba64d8[][3];	// NOTE: placeholder name
extern bool opw8_b951c0[];	// NOTE: placeholder name
extern bool opw8_b95758[];	// NOTE: placeholder name
extern vector<OpW8_D02cb4 *> opw8_d02cb4;	// NOTE: placeholder name
extern OpW8_Cf6428 opw8_cf6428;	// NOTE: placeholder name

void Entity::polymindPossessMe()
{
	if (isPlayer())
		logFatal("Entity::polymindPossessMe()","can't possess self!");
	if (opw8_cf4700 != 0)
		logFatal("Entity::polymindPossessMe()","haven't yet unpossessed previous Ent!");
	int price = unknown5d7e90();
	if (opw8_cf46f4 < price)
		logFatal("Entity::polymindPossessMe()","prior cost check invalid?");
	else
	{
		opw8_cf46f4 -= price;
		opw8_statTracker.unknown4729d0(0x45e,price,"",-1);
		opw8_statTracker.unknown4729d0(0x460,price,"",-1);
	}
	unknown5da0a0();

	HEntity you = world->getPlayer();
	OpW8_EntityRecord *pdata = you->getInfo();
	opw8_cf496c = record->unknown1C8;
	opw8_cf4978 = record->unknown1E0;
	opw8_cf4960 = record->unknown21C;
	opw8_cf49d8 = record->unknown1E8;
	opw8_cf4970 = record->unknown1E4;
	opw8_cf4974 = abs(record->unknown1EC);
	opw8_cf49dc = record->unknown1F0;
	for (int i = 0; i < 7; i++)
		opw8_table_cf4984[i] = opw8_ba64d8[i][opw8_cf4718] + (record->unknown1F4[i] - 100);
	pdata->type = record->type;
	pdata->unknown98 = record->unknown98;
	pdata->unknown94 = record->unknown94;
	pdata->unknownA4 = unknown88;
	pdata->ascii = record->ascii;
	opw8_caf2b8[0] = opw8_caf2b8[record->unknown28];
	int matter = unknown94;
	int curHeat = unknown90;
	int savedCore = unknown98;
	opw8_copyInts(slots,you->slots,4);
	opw8_playerData.unknown46ddd0();
	if (sumArray(you->slots,4) > 0x1a)
	{
		int excess = sumArray(you->slots,4) - 0x1a;
		if (you->slots[2] >= excess)
			you->slots[2] -= excess;
		else
		{
			excess -= you->slots[2];
			you->slots[2] = 0;
			you->slots[3] -= excess;
		}
	}

	if (!opw8_cec118->isHidden())
		opw8_cec118->unknown8b5080();
	if (!opw8_cec11c->isHidden())
		opw8_cec11c->unknown8b5080();
	if (!opw8_cec120->isHidden())
		opw8_cec120->unknown8b5080();
	unknown4b3540(opw8_cec034);
	opw8_cec088->unknown894120(1);
	opw8_cec08c->setPos(unknown4b33b0());
	opw8_cec138->unknown965220();

	vector<HItem> partsList;
	vector<HItem> stored;
	unknown5cb830(&stored);
	unknown5cb8b0(&partsList);
	parts.clear();
	for (int slot = 0; slot < 4; slot++)
	{
		vector<HItem> sorted;
		for (unsigned int i = 0; i < partsList.size(); i++)
		{
			if (partsList[i]->unknown44aec0() == slot)
			{
				int value = partsList[i]->unknown457900();
				if (sorted.empty() || value <= sorted.back()->unknown457900())
					sorted.push_back(partsList[i]);
				for (unsigned int j = 0; j < sorted.size(); j++)
				{
					if (value > sorted[j]->unknown457900())
					{
						opw8_insertItem(sorted,j,partsList[i]);
						break;
					}
				}
			}
		}
		opw8_appendItems(parts,sorted);
	}
	opw8_appendItems(parts,stored);

	int available[4];
	opw8_copyInts(you->unknown45a840(),available,4);
	while (!parts.empty())
	{
		opw8_playerData.unknown77ffb0(parts.front()->unknown457820(),0);
		if (parts.front()->unknown44aec0() < 3)
		{
			if (available[parts.front()->unknown4578a0()] < parts.front()->unknown4578c0())
			{
				Point dropPos;
				if (world->unknown71bc10(getPosition(),&dropPos))
					parts.front()->unknown57a0f0(&dropPos,1,0);
				else
					parts.front()->unknown57dbe0(0,0,1,1);
			}
			else
			{
				available[parts.front()->unknown4578a0()] -= parts.front()->unknown4578c0();
				parts.front()->unknown57a190(you,parts.front()->unknown44aec0(),1,1);
			}
		}
		else
			parts.front()->unknown57a190(you,parts.front()->unknown44aec0(),1,1);
	}
	for (unsigned int i = 0; i < you->parts.size(); i++)
	{
		if (you->parts[i]->unknown44aec0() <= 3 && you->unknown5dc440(you->parts[i]) == 0)
			opw8_cec088->unknown8993e0(opw8_cec088->unknown894e70(you->parts[i]),1);
	}
	you->unknown5deb40(matter);
	you->unknown5ded70(curHeat);
	you->unknown45b210(savedCore);
	you->unknownBC = unknownBC;
	if (unknown45ac40(0x1d) != 0)
		you->unknown45b340(new Point(opw8_d2f0f8[0x1d],1));

	opw8_cf4700 = new OpW8_Possession(self);
	do
	{
		if (opw8_unknown5111e0(0x305,&name,0,0,you,HProp(),0,0))
			opw8_cec058->unknown8758d0(true);
		opw8_logMsgs->scrollToEnd();
	} while (0);
	opw8_statTracker.unknown4729d0(0x455,1,"",-1);
	switch (world->unknown4638e0(0,group->unknown9b4350()))
	{
		case 0:
			if (opw8_b951c0[record->unknown28])
				opw8_statTracker.unknown4729d0(0x456,1,"",-1);
			break;
		case 2:
			opw8_statTracker.unknown4729d0(0x457,1,"",-1);
			break;
	}
	if (opw8_statTracker.unknown4729d0(0x458,1,"",record->unknown28))
		opw8_statTracker.unknown472b90(0x13,0x32);
	if (record->unknown48 == 0x79 || (record->unknown48 != 0x7a && opw8_b95758[record->unknown48]))
	{
		string text(record->unknown48 == 0x79 && !record->unknown4C.empty() ? record->unknown4C : name);
		if (world->unknown4638e0(0,group->unknown9b4350()) != 0)
			text += " (ally)";
		do
		{
			opw8_unknown5141b0(0x2e,&text,0,0,HProp(),0);
		} while (0);
	}
	if (!opw8_d25de0[opw8_cf4700->unknown00]->unknown170.empty() && opw8_cf4910[opw8_cf4700->unknown00] == 0)
	{
		OpW8_EntityRecord *possessed = opw8_d25de0[opw8_cf4700->unknown00];
		string title;
		if (possessed->unknown24 == 0)
			title = name;
		else if (!possessed->unknown2C.empty())
			title = possessed->unknown2C;
		else
			title = name;
		do
		{
			if (opw8_unknown5111e0(0x306,&title,0,0,you,HProp(),0,0))
				opw8_cec058->unknown8758d0(true);
			opw8_logMsgs->scrollToEnd();
		} while (0);
		opw8_playerData.unknown780700(possessed->unknown00,1);
		for (unsigned int i = 0; i < opw8_d25de0.size(); i++)
		{
			if (opw8_d25de0[i]->unknown1AC == possessed->unknown1AC)
				opw8_playerData.unknown780700(i,0);
		}
		if (!opw8_playerData.unknown46dd90())
		{
			for (int i = opw8_d02cb4.size() - 1; i >= 0; i--)
			{
				if (opw8_d02cb4[i]->unknown14 == possessed)
				{
					opw8_d02cb4[i]->unknown04 = true;
					break;
				}
			}
		}
	}

	Point spot(getPosition());
	unknown637bb0();
	cells(you->positions.front())->clearEntity();
	you->changePos(spot,false);
	you->unknown45b090(0);
	you->unknown45b0b0();
	world->unknown72e4c0(you,true);
	if (opw8_d28e27)
		opw8_cec054->unknown8069e0(spot,0);
	world->unknown734560(you,-2,0);
	bool spotted = false;
	Area area;
	cells.getRect(spot,0x10,area);
	for (int x = area.min.x; x <= area.max.x; x++)
	{
		for (int y = area.min.y; y <= area.max.y; y++)
		{
			if (cells(x,y)->getEntity().isValid() && cells(x,y)->getEntity()->getGroup()->unknown9b4350() == 3 && cells(x,y)->getEntity()->getTarget() == 0 && opw8_pointDistance(cells(x,y)->getEntity()->getPosition(),spot) <= cells(x,y)->getEntity()->unknown5c7d30() && world->isReachable(cells(x,y)->getEntity()->unknown5c7d30(),cells(x,y)->getEntity()->getPosition(),spot))
			{
				spotted = true;
				break;
			}
		}
	}
	if (spotted)
		opw8_playerData.unknown77f230(99.0f,0x13);
	else
	{
		opw8_cf4714 = price;
		opw8_playerData.addPolymindSuspicion(maxf(-20.0f,-(float)price),0x12,HEntity());
		opw8_cf6428.unknown682420(0x28,-(float)price * opw8_ba8798);
	}
	unknown4541b0(0x13f,0,0);
	opw8_itemFactory->unknown793690();
	opw8_unknown789ac0();
}

struct OpW8_ScoreEntry	// NOTE: placeholder name
{
	int unknown00;
	int unknown04;
	int unknown08;
};

int *opW5_getUpgradeValue(int id);	// NOTE: placeholder name
bool opw8_findRecord(vector<OpW8_EntityRecord *> *records, const string &name, OpW8_EntityRecord **out);	// NOTE: placeholder name (0x9d7530)
bool opw8_addUnique(vector<int> &values, int value);	// NOTE: placeholder name (0x9db000)
int opw8_maxIndex(vector<int> *values);	// NOTE: placeholder name (0x9d4500)
extern vector<OpW8_ItemRecord *> opw8_itemTypes;	// NOTE: placeholder name (0xd2d1c4)
extern bool opw8_cf4a00;	// NOTE: placeholder name
OpW8_ScoreEntry opw8_ba21d0[0x40] =	// NOTE: placeholder name (defined here so constant-index offsets resolve)
{
	{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
	{0,0,0}, {0,0,0}, {1,0,0}, {2,0,0}, {2,0,0}, {5,0,0}, {2,0,0}, {4,0,0},
	{2,0,0}, {2,0,0}, {2,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {1,0,0}, {1,0,0},
	{1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {0,0,0}, {1,0,0}, {0,0,0}, {0,0,0},
	{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
	{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,2}, {0,0,2},
	{0,0,2}, {0,0,2}, {0,0,2}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,2}, {0,0,2},
	{0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,2}
};
extern OpW8_ScoreEntry opw8_ba7810[];	// NOTE: placeholder name
enum { OPW8_NUM_ROLES = 0x14 };	// NOTE: placeholder name
extern vector<int> opw8_cf4c28;	// NOTE: placeholder name
extern int opw8_cf48dc;	// NOTE: placeholder name
extern vector<int> opw8_cf48cc;	// NOTE: placeholder name
extern int opw8_cf47c0;	// NOTE: placeholder name
extern int opw8_b96178[];	// NOTE: placeholder name

void Entity::unknown5cede0(int *type, int *subtype)
{
	bool player = isPlayer();
	bool upgraded = player && opw8_cf462c == 5;
	*type = 0x10;
	if (opw8_cf4a00)
		*type = 0;
	else if (unknown5d26e0(0xae))
	{
		OpW8_EntityRecord *golem;
		opw8_findRecord(&opw8_d25de0,"Golem_8",&golem);
		vector<OpW8_ItemRecord *> types;
		for (unsigned int i = 0; i < golem->unknown160.size(); i++)
			types.push_back(opw8_itemTypes[golem->unknown160[i][0]->type]);
		int amount = 0;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (opw8_contains9db330(&types,parts[i]->unknown9b4350()))
				amount += parts[i]->unknown4578c0();
		}
		if (amount >= sumArray(slots,4) / 2)
			*type = 1;
	}
	else if (unknown5d26e0(0xd3))
	{
		int amount = 2;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown9b4350()->unknown94 == 2)
				amount += parts[i]->unknown4578c0();
		}
		if (amount >= sumArray(slots,4) / 2)
			*type = 2;
	}
	else if (unknown5d26e0(0xa1))
	{
		int amount = 2;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown44aec0() <= 3 && parts[i]->unknown9b4350()->unknown54 - 4 == 0xb)
				amount += parts[i]->unknown4578c0();
		}
		if (amount >= sumArray(slots,4) / 3)
			*type = 3;
	}
	if (*type == 0x10)
	{
		bool fast = unknown5d1390() >= 3 && !unknown45a780();
		int score = 0;
		if (player && opw8_gameData.unknown46fb60())
			score += 3;
		if (unknown5d26e0(10) || (upgraded && *opW5_getUpgradeValue(0xb) >= 0x12))
			score += opw8_ba21d0[10].unknown00;
		if (unknown5d26e0(0xd))
			score += opw8_ba21d0[0xd].unknown00;
		else if (unknown5d26e0(0xb) || (upgraded && *opW5_getUpgradeValue(0xc) >= 10))
		{
			score += opw8_ba21d0[0xb].unknown00;
			if (unknown5d26e0(0xc))
				score += opw8_ba21d0[0xc].unknown00;
		}
		if (unknown5d26e0(0xe))
			score += opw8_ba21d0[0xe].unknown00;
		if (unknown5d26e0(0xf))
			score += opw8_ba21d0[0xf].unknown00;
		if (unknown5d26e0(0x10))
		{
			score += opw8_ba21d0[0x10].unknown00;
			if (unknown5d26e0(0x11) || (upgraded && *opW5_getUpgradeValue(0xd) >= 0x32))
				score += opw8_ba21d0[0x11].unknown00;
		}
		if (unknown5d26e0(0x16))
			score += opw8_ba21d0[0x16].unknown00;
		if (unknown5d26e0(0x17))
			score += opw8_ba21d0[0x17].unknown00;
		if (unknown5d26e0(0x18))
			score += opw8_ba21d0[0x18].unknown00;
		if (unknown5d26e0(0x19))
			score += opw8_ba21d0[0x19].unknown00;
		if (unknown5d26e0(0x1a))
			score += opw8_ba21d0[0x1a].unknown00;
		if (unknown5d26e0(0x1b))
			score += opw8_ba21d0[0x1b].unknown00;
		if (unknown5d26e0(0x1d))
			score += opw8_ba21d0[0x1d].unknown00;
		bool strong = score >= 5;
		if (!strong && fast && unknown5d15a0(false) <= 0x21)
			*type = 4;
		else
		{
			bool armed = unknown5d5c30().isValid();
			bool special = unknown5d26e0(0x13) || unknown5d26e0(0x14) || unknown5d26e0(0x1c) || unknown5d26e0(0x1e) || unknown5d26e0(0x1f);
			if (fast && strong)
			{
				if (armed && special)
					*type = 6;
				else
					*type = 5;
			}
			else
			{
				if (armed)
				{
					if (unknown5d6240() >= 2 && (unknown5d26e0(0x51) || unknown5d26e0(0x5a) || (upgraded && *opW5_getUpgradeValue(0xf) >= 5) || unknown5d26e0(0x6c) || unknown5d26e0(0x6a) || unknown5d26e0(0x5b) || unknown5d2000(3)))
						*type = 8;
					else if (strong)
						*type = 7;
				}
				if (*type == 0x10)
				{
					int count = unknown5d6360();
					if (slots[3] >= 6 && count >= 5)
						*type = 0xe;
					else if (count == 2 && strong)
						*type = 9;
					else if (count >= 3)
					{
						int offense = 0;
						int defense = 0;
						for (unsigned int i = 0; i < parts.size(); i++)
						{
							if (parts[i]->unknown44aec0() <= 3)
							{
								offense += opw8_ba21d0[parts[i]->unknown457f90()].unknown04;
								defense += opw8_ba21d0[parts[i]->unknown457f90()].unknown08;
							}
						}
						if (upgraded)
						{
							for (int i = 0; i < 0x18; i++)
							{
								if (*opW5_getUpgradeValue(i) != 0)
								{
									offense += opw8_ba7810[i].unknown04;
									defense += opw8_ba7810[i].unknown08;
								}
							}
						}
						if (unknown5d2000(1) || unknown5d2000(2))
							defense += 3;
						if (score > offense && score > defense)
							*type = 9;
						else
						{
							if (offense >= defense)
								*type = 0xa;
							else
								*type = 0xd;
							if (player && unknown5c8ec0(0x18,false) != 0)
							{
								int best = opw8_caf164;
								for (unsigned int i = 0; i < opw8_itemTypes.size(); i++)
								{
									if (opw8_itemTypes[i]->unknown48 == 3 && (best == opw8_caf164 || opw8_cf4c28[i] > opw8_cf4c28[best]))
										best = i;
								}
								if (opw8_itemTypes[best]->unknown44 == 0x18)
									*type = 0xb;
							}
							if (*type == 0xa && slots[3] == 2 && unknown5c7d30() > record->unknown21C && unknown5d7b00(true) >= 0x14)
							{
								int best = 0;
								for (unsigned int i = 0; i < parts.size(); i++)
								{
									if (opw8_inRange(0x14,parts[i]->unknown457880(),0x17) && parts[i]->unknown44aec0() <= 3 && parts[i]->unknown4580a0() > best)
										best = parts[i]->unknown4580a0();
								}
								if (best >= 0x14)
									*type = 0xc;
							}
						}
					}
				}
			}
		}
		if (*type == 0x10)
			*type = 0xf;
	}

	*subtype = OPW8_NUM_ROLES;
	vector<int> scores(OPW8_NUM_ROLES,0);
	int value = unknown5c7f10() + unknown5c7f40();
	if (unknown5d26e0(0xb9))
		value += 5;
	if (value >= 0x14)
		scores[0] = value;
	bool rif = player && stringToInt(opw8_gameData.unknown46f6d0("installedRif_g")) && unknown5d2a00(0x77);
	if (rif)
	{
		value = unknown5d2990(0x7c) * 6;
		if (value >= 0x14)
		{
			value += (opw8_playerData.unknown46e150() - 1) * 5;
			scores[2] = value;
		}
	}
	if (unknown5d2990(0xa6) != 0 || unknown5d2990(0xba) != 0 || unknown5d2990(0xc5) != 0)
	{
		value = unknown5c8ec0(5,false) * 3;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown457f90() == 0xa6 && parts[i]->unknown457d70())
				value += parts[i]->unknown45cb30() * 3;
			else if (parts[i]->getEffect(0x56) != 0)
				value += 3;
		}
		if (value >= 0x14)
		{
			value += unknown5d2770(0x19) * 4;
			scores[4] = value;
		}
	}
	value = unknown5ca210();
	if (upgraded)
		value *= 3;
	if (value >= 0x1a)
		scores[5] = value;
	if (slots[0] >= 4)
	{
		value = unknown5d1070() / 2.2;
		if (value >= 0x14)
			scores[6] = value;
	}
	value = 0;
	vector<HItem> launchers;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown4578a0() == 3 && parts[i]->unknown44aec0() <= 3)
		{
			value += opw8_b96178[parts[i]->unknown9b4350()->unknown158] / 10;
			if (parts[i]->unknown9b4350()->unknown1A0 != 0 && parts[i]->unknown9b4350()->unknown1A0->unknown64 != 0)
				value += opw8_b96178[parts[i]->unknown9b4350()->unknown1A0->unknown64] / 10;
		}
	}
	if (value >= 0x14)
		scores[7] = value;
	value = 0;
	if (unknown5d26e0(0x13))
		value += 10;
	if (unknown5d26e0(0x14))
		value += 10;
	if (unknown5d26e0(0x1c))
		value += 5;
	if (unknown5d26e0(0x18))
		value += 5;
	if (unknown5d26e0(0x1e))
		value += 5;
	if (unknown5d26e0(0x1f))
		value += 10;
	if (value >= 0xf)
		scores[8] = value;
	value = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() <= 3 && parts[i]->getEffectValue(0x65) != 0)
			value += 5;
	}
	if (value >= 0x14)
		scores[9] = value;
	value = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() <= 3 && parts[i]->getEffectValue(0x68) != 0)
			value += 5;
	}
	if (value >= 0x14)
		scores[10] = value;
	if (opw8_cf48dc != 0)
	{
		vector<int> seen;
		value = 0;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (opw8_cf48cc[parts[i]->unknown457820()] != 0 && parts[i]->unknown44aec0() <= 3)
			{
				value++;
				if (opw8_addUnique(seen,parts[i]->unknown457820()))
					value += 4;
			}
		}
		if (unknown5d26e0(0x96))
			value += 5;
		if (value >= 0x14)
			scores[0xc] = value;
	}
	value = world->unknown463890(1)->getMembers()->size() * 5;
	if (value >= 0x14)
		scores[0xd] = value;
	value = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() <= 3 && (parts[i]->unknown9b4350()->unknown54 == 3 || parts[i]->getEffectValue(0x66) != 0 || parts[i]->getEffectValue(0x69) != 0))
			value += 5;
	}
	if (value >= 0x14)
		scores[0xe] = value;
	value = 0;
	bool core = false;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() <= 3)
		{
			if (parts[i]->unknown9b4350()->unknown40 == 0x1d)
				value += 5;
			else if (parts[i]->unknown9b4350() == opw8_cefbe8)
			{
				value += 10;
				core = true;
			}
		}
	}
	if (value >= 0x14 && core)
		scores[0x10] = value;
	bool zio = player && stringToInt(opw8_gameData.unknown46f6d0("zioWasImprinted_g")) && !stringToInt(opw8_gameData.unknown46f6d0("zioAttackedLocals_g"));
	if (zio)
	{
		value = 10;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown44aec0() <= 3 && parts[i]->unknown9b4350()->unknown40 == 0x1c)
				value += 5;
		}
		if (value >= 0x14)
			scores[0x11] = value;
	}
	bool reset = player && stringToInt(opw8_gameData.unknown46f6d0("usedCoreResetMatrix_g"));
	if (reset)
	{
		value = 10;
		value += opw8_cf47c0 * 5;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown44aec0() <= 3 && parts[i]->unknown9b4350()->unknown94 == 3)
				value += 7;
		}
		if (value >= 0x14)
			scores[0x12] = value;
	}
	value = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown44aec0() <= 3 && parts[i]->unknown9b4350()->unknown40 == 0x24)
			value += 10;
	}
	if (value >= 0x14)
		scores[0x13] = value;
	if (opw8_anyNonZero(scores))
	{
		*subtype = opw8_maxIndex(&scores);
		switch (*subtype)
		{
			case 0:
				if (scores[*subtype] >= 0x3c)
					*subtype = 1;
				break;
			case 2:
				if (player && scores[*subtype] >= 0x3c && opw8_playerData.unknown46e150() - 1 >= 3)
					*subtype = 3;
				break;
			case 9:
				if (scores[0x10] != 0)
					*subtype = 0x10;
				else if (scores[0x11] != 0)
					*subtype = 0x11;
				break;
			case 10:
			{
				int count = 0;
				for (unsigned int i = 0; i < parts.size(); i++)
				{
					if (parts[i]->unknown457f90() == 0x7b && parts[i]->unknown457d70())
						count++;
				}
				if (count >= 3)
					*subtype = 0xb;
			}
				break;
			case 14:
			case 16:
			{
				int count = 0;
				for (unsigned int i = 0; i < parts.size(); i++)
				{
					if (parts[i]->unknown44aec0() <= 3 && parts[i]->getEffectValue(0x69) != 0)
						count++;
				}
				if (count >= 4)
					*subtype = 0xf;
				else if (scores[0x10] != 0)
					*subtype = 0x10;
			}
				break;
		}
	}
}
