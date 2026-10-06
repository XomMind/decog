// op_t3_a: Entity methods matched against COGMIND.exe (Beta 17.1).
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
	int unknown457b30();	// NOTE: placeholder name
	int unknown4578c0();	// NOTE: placeholder name
	int unknown4578a0() throw();	// NOTE: placeholder name
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
	bool operator==(HItem other) const;
	Item *operator->() const throw();	// 0x9b65b0
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
	int unknown5e2b50();	// NOTE: placeholder name
};


void OpT3a_moveElement(vector<HItem> &v, unsigned int from, unsigned int to);	// NOTE: placeholder name (0x9da1f0)
void opw8_shuffle9d9fc0(vector<HItem> &v);	// NOTE: placeholder name (0x9d9fc0)
void opw8_lowerToMax(int &value, int maxValue);	// NOTE: placeholder name (0x9cf5a0)

int Entity::unknown5e2b50()
{
	int result = 0;
	int capacity = unknown5ca210();
	int lo = unknown5c8e20(0);
	if (lo > capacity)
	{
		Point p;
		vector<HItem> items;
		if (unknown5cb830(&items))
		{
			opw8_shuffle9d9fc0(items);
			for (unsigned int i = 0; i < items.size(); i++)
			{
				if (items[i]->unknown4578c0() > 1)
					OpT3a_moveElement(items,i,0);
			}
			for (unsigned int j = 0; j < items.size(); j++)
			{
				if (items[j]->unknown4578c0() > capacity)
					OpT3a_moveElement(items,j,items.size() - 1);
			}
			while (!items.empty() && lo > capacity)
			{
				lo -= items.back()->unknown4578c0();
				result += items.back()->unknown4578c0();
				if (!world->unknown71bc10(positions[0],&p))
				{
					if (isPlayer())
					{
						do
						{
							if (opw8_unknown5111e0(0x11,&items.back()->getName(0,0),0,0,self,HProp(),0,0))
								opw8_cec058->unknown8758d0(true);
							opw8_logMsgs->scrollToEnd();
						} while (false);
					}
					items.back()->unknown57dbe0(1,1,1,1);
				}
				else
					items.back()->unknown57a0f0(&p,1,1);
				items.pop_back();
			}
		}
	}
	opw8_lowerToMax(unknown90,unknown5ca400());
	opw8_lowerToMax(unknown94,unknown5ca670());
	return result;
}
