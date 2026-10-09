// op_w3: BattleScape (BS) methods in 0x720000-0x730000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members, member names and method names are placeholders
//	unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// NOTE: placeholder name (0xd30908)

//==================================================================
// declarations
//==================================================================

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(int v);	// 0x409990
	Point(int x_, int y_);	// 0x46ca20
	Point(const Point &p) throw();	// 0x46ca50
	Point &operator=(const Point &p);	// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
	void set(int x_, int y_);	// 0x40a010
	int randomInRange_40c130();	// NOTE: placeholder name
	bool opw3_adjacent(const Point &p);	// NOTE: placeholder name (0x409dd0)
};

class Entity;
class HItemP;
class HItem
{
public:
	int ID;
	HItem();
	bool isValid() const throw();
};

class HEntity : public HItem	// NOTE: placeholder layout
{
public:
	HEntity() throw();
	void opw3_reset();	// NOTE: placeholder name (0x9b7270)
	Entity *operator->() const throw();	// 0x9b6570
	bool operator==(HEntity other) const;
	bool operator!=(HEntity other) const;
	bool isNull() const;
};

struct OpW3_EntityRecord	// NOTE: placeholder name
{
	int unknown9b4350() throw();	// NOTE: placeholder name (ICF'd field getter)
	void opw3_setUnknown(int value);	// NOTE: placeholder name (0x452270, ICF'd setter)
	int opw3_unknown581630();	// NOTE: placeholder name
	int opw3_unknown459570(HEntity e);	// NOTE: placeholder name
	void opw3_unknown5b3a30(int range);	// NOTE: placeholder name
	bool opw3_unknown459090();	// NOTE: placeholder name (EntityAI::unknown459090)
	void opw3_unknown4591c0(int value);	// NOTE: placeholder name (EntityAI::unknown4591c0)
	bool opw3_unknown458fb0(HEntity e);	// NOTE: placeholder name (EntityAI::unknown458fb0)
	void opw3_unknown459540(const Point &p);	// NOTE: placeholder name
	void opw3_unknown459470(const struct Area &area);	// NOTE: placeholder name
	void opw3_setMode(int mode);	// NOTE: placeholder name (ICF'd setter)
	void opw3_setFollowEntity(HEntity e, int value);	// NOTE: placeholder name (EntityAI::setFollowEntity)
	bool opw3_unknown581580();	// NOTE: placeholder name
	void opw3_unknown5b5f40();	// NOTE: placeholder name
	struct OpW3_AIPart *opw3_unknown4590f0();	// NOTE: placeholder name (EntityAI::unknown4590f0)
	void opw3_unknown459320();	// NOTE: placeholder name (EntityAI::unknown459320)
	int opw3_getIndex457af0();	// NOTE: placeholder name (ICF'd getter)
};
struct OpW3_AIPart	// NOTE: placeholder name
{
	int opw3_unknown458950(int type);	// NOTE: placeholder name (EntityPart4588f0::unknown458950)
};

struct OpW3_Color	// NOTE: placeholder name (3-byte RGB color)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	OpW3_Color(const OpW3_Color &color) throw();
	OpW3_Color &operator=(OpW3_Color color);	// 0x... XColor::operator=
};

class HGroup;

struct OpW3_EntityData	// NOTE: placeholder name
{
	char pad00[0x48];
	int unknown48;	// NOTE: placeholder name
	char pad4c[0x68 - 0x4c];
	int value;	// NOTE: placeholder name
	char pad6c[0x88 - 0x6c];
	float unknown88;	// NOTE: placeholder name
	char pad8c[0x110 - 0x8c];
	int unknown110;	// NOTE: placeholder name
};

struct OpQ1_Box	// same layout as Area; its 4-int constructor is the configured OpQ1_Box ctor 0x40b1e0
{
	OpQ1_Box(int x1_, int y1_, int x2_, int y2_);	// 0x40b1e0

	int x1;
	int y1;
	int x2;
	int y2;
};

struct Area	// NOTE: placeholder name
{
	void randomPoint_40be30(Point *out);	// NOTE: placeholder name
	Point randomPoint_40be90();	// NOTE: placeholder name

	int x1;
	int y1;
	int x2;
	int y2;

	Area() throw();	// 0x40b100
};
int opw3_distance406480(int x1, int y1, int x2, int y2) throw();	// NOTE: placeholder name

class Entity	// NOTE: placeholder name
{
public:
	const Point &getPosition() throw();	// 0x45a4a0
	int opw3_unknown5c7f40();	// NOTE: placeholder name
	HGroup getGroup();	// 0x45a3f0
	int getAiType();	// 0x45a2a0
	const string &opw3_getName();	// NOTE: placeholder name (0x416f40)
	int unknown45acb0(int value);	// NOTE: placeholder name
	Point unknown5c80f0(const Point &p);	// NOTE: placeholder name
	void *opw3_unknown45ac40(int type);	// NOTE: placeholder name
	int unknown45a540(const Point &p);	// NOTE: placeholder name
	const OpW3_Color &opw3_unknown5c7630();	// NOTE: placeholder name
	bool opw3_unknown5d4490(HEntity e);	// NOTE: placeholder name
	bool opw3_unknown5cb680(HGroup g);	// NOTE: placeholder name
	bool unknown45aaa0(HEntity entity);	// NOTE: placeholder name
	bool isPlayer() throw();	// 0x5c7600
	int opw3_unknown5c7d30();	// NOTE: placeholder name
	int unknown45a340();	// NOTE: placeholder name
	int opw3_unknown5d22a0(int type);	// NOTE: placeholder name
	HItemP opw3_unknown5d2380(int type);	// NOTE: placeholder name
	vector<HItemP> *opw3_getInventoryList();	// NOTE: placeholder name (0x45ab00)
	vector<Point> *opw3_getFootprint();	// NOTE: placeholder name (0x45d1a0)
	int opw3_unknown5e2f00(HEntity e, int value, HItemP item);	// NOTE: placeholder name
	bool opw3_unknown5e2fe0(HEntity e, int value, HItemP item);	// NOTE: placeholder name
	bool opw3_unknown5e30d0(HEntity e, int value, HItemP item);	// NOTE: placeholder name
	bool opw3_unknown5e3310(HEntity e, int a, int b, HItemP item);	// NOTE: placeholder name
	int getFaction() throw();	// 0x45a2c0
	int getTarget() throw();	// 0x45a760
	bool isHostileTo(HEntity entity) throw();	// 0x45aa70
	OpW3_EntityRecord *opw3_getRecord() throw();	// NOTE: placeholder name (0x45b590)
	int getSize();	// 0x45a360
	bool opw3_unknown5d5250() throw();	// NOTE: placeholder name
	Point unknown45a4c0();	// NOTE: placeholder name
	int unknown45a3c0();	// NOTE: placeholder name
	int opw3_unknown5c7e40();	// NOTE: placeholder name
	int opw3_unknown5d2090(int type);	// NOTE: placeholder name
	void unknown639730(bool b);	// NOTE: placeholder name
	bool opw3_unknown5c98c0(int a, int b, int c);	// NOTE: placeholder name
	bool opw3_unknown5d51a0();	// NOTE: placeholder name
	void opw3_unknown64ecf0(class OpW3_AI57f6a0 *ai);	// NOTE: placeholder name
	int unknown45adb0(int value);	// NOTE: placeholder name
	void unknown6395d0(struct OpW3_Talk *talk, int value);	// NOTE: placeholder name
	void opw3_unknown639530(int type, bool flag);	// NOTE: placeholder name (Entity::unknown639530)
	const string &opw3_getNameRef();	// NOTE: placeholder name (ICF'd getter)
	void *opw3_getInventory();	// NOTE: placeholder name (Entity::getInventory, 0x45ad90)
	string &opw3_getName45a280();	// NOTE: placeholder name (Entity::getName)
	int opw3_unknown45afb0();	// NOTE: placeholder name (Entity::unknown45afb0)
	void opw3_setTurn(int turn);	// NOTE: placeholder name (ICF'd setter 0x451620)
	void opw3_unknown5c89d0(vector<Point> &area);	// NOTE: placeholder name
	void opw3_unknown5d2430(int type, vector<HItemP> &items);	// NOTE: placeholder name
	void opw3_unknown5d3830();	// NOTE: placeholder name
	int unknown5cab90();	// NOTE: placeholder name
	int unknown5c7d80(bool *out);	// NOTE: placeholder name
	void opw3_unknown5d3700();	// NOTE: placeholder name
	OpW3_EntityData *opw3_getData() throw();	// NOTE: placeholder name (ICF'd getter 0x9b4350)
};

class HProp;
class Cell	// NOTE: placeholder layout
{
public:
	HEntity getEntity() throw();	// 0x45d250
	HProp getProp();	// 0x45d550
	bool unknown45d270();	// NOTE: placeholder name
	void opw3_unknown670f50(int *range, float factor);	// NOTE: placeholder name
	bool opw3_unknown45e0e0();	// NOTE: placeholder name
	bool isMachinePart();	// 0x45dcd0
	bool isEdge();	// 0x45dc30
	bool isPassableFor(HEntity entity);
	bool opw3_unknown45ddf0();	// NOTE: placeholder name
	bool opw3_unknown45df50(HProp prop);	// NOTE: placeholder name
	bool unknown45dcf0();	// NOTE: placeholder name
	void opw3_removeProp(bool keepTerrain, int cause);	// NOTE: placeholder name (Cell::removeProp, 0x66c100)
	bool unknown66b120();	// NOTE: placeholder name
	void opw3_unknown66b690(int type, int value);	// NOTE: placeholder name
	int getTerrain();	// NOTE: placeholder name (0x9fcd80)
	bool unknown45dc70();	// NOTE: placeholder name
	void opw3_unknown66a050(int terrainID, int cause, int unknown);	// NOTE: placeholder name
	bool unknown45d700();	// NOTE: placeholder name
	bool isDoor();	// 0x45dda0
	bool isShortcut();	// 0x45dc50
	bool unknown45db90();	// NOTE: placeholder name
	bool opw3_unknown4550b0();	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(int x, int y) throw();	// 0x9ceda0
	T &operator()(const Point &p);	// 0x9ced70
	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
	void fill(T value);	// NOTE: placeholder name (0x9d28e0 for bool)
	void opw3_unknown9cedd0(struct OpW3_Region *region);	// NOTE: placeholder name
};

class OpW3_CellArea : public Array2D<Cell *>	// NOTE: placeholder name (same object as cells, 0xcfd44c)
{
public:
	Point opw3_getSize();	// NOTE: placeholder name (0x9b7930)
	Area opw3_unknown9b4400();	// NOTE: placeholder name
	void getRect(const Point &p, int radius, Area &out) throw();	// NOTE: placeholder name (0x9b4430)
	void getBounds(const Point &center, int radius, Point &topLeft, Point &bottomRight);	// NOTE: placeholder name (0x9b7a40)
	void opw3_unknown9d24b0(const Point &p, vector<Point> &out);	// NOTE: placeholder name
};
extern OpW3_CellArea opw3_cells;	// NOTE: placeholder name (0xcfd44c)

template <class T> bool OpW3_addUnique(vector<T> &v, T e);	// NOTE: placeholder name (0x9d30e0)
template <class T> bool OpW3_inVector(vector<T> &v, T e) throw();	// NOTE: placeholder name (0x9d31e0)
template <class T> bool OpW3_erase(vector<T> &v, T e);	// NOTE: placeholder name (0x9d2f00)
template <class T> void OpW3_eraseAt(vector<T> &v, int i);	// NOTE: placeholder name (0x9da940)

struct OpW3_ItemEffect	// NOTE: placeholder name
{
	OpW3_ItemEffect(int type_, int state_) throw();	// 0x46ca20

	int type;	// NOTE: placeholder name
	int state;	// NOTE: placeholder name
};
extern vector<int> opw3_effectTypes;	// NOTE: placeholder name (0xd2f0f8)

class Item	// NOTE: placeholder name
{
public:
	void addEffect(OpW3_ItemEffect *effect);	// 0x4585a0
	void unknown458460();	// NOTE: placeholder name
	void unknown4584f0();	// NOTE: placeholder name
	int unknown4580a0();	// NOTE: placeholder name
	bool opw3_unknown577b80();	// NOTE: placeholder name
	HEntity unknown457b50();	// NOTE: placeholder name (owner)
	bool unknown457cf0();	// NOTE: placeholder name
	int unknown457f90();	// NOTE: placeholder name
	int unknown457fb0();	// NOTE: placeholder name
	int opw3_getType();	// NOTE: placeholder name (ICF'd getter)
	int opw3_unknown457fd0();	// NOTE: placeholder name (Item::unknown457fd0)
	void *getEffect(int type);	// 0x457b70
	const Point &opw3_unknown575920();	// NOTE: placeholder name
	string opw3_unknown571db0(bool a, bool b);	// NOTE: placeholder name
	void opw3_unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	struct OpW3_ItemData *opw3_getData();	// NOTE: placeholder name (ICF'd getter 0x9b4350)
};

struct OpW3_ItemData	// NOTE: placeholder name
{
	char pad000[0x1a8];
	int unknown1a8;	// NOTE: placeholder name
};

class HItemP : public HItem	// NOTE: placeholder name
{
public:
	HItemP();	// 0x9b6590
	bool isNull() const;	// 0x9b65d0
	Item *operator->() const;	// 0x9b65b0
};

extern bool opw3_itemTypeFlags[];	// NOTE: placeholder name (0xba39d8)

class Group	// NOTE: placeholder name
{
public:
	vector<HEntity> *opw3_getMembers();	// NOTE: placeholder name (0x416f40, ICF'd getter)
	int opw3_indexOf(HEntity e);	// NOTE: placeholder name (0x45e1a0)
	int opw3_unknown9b4350();	// NOTE: placeholder name (ICF'd field getter)
	void opw3_unknown6719c0(int a, HEntity e, int b, bool &result, int c, int d, int e2);	// NOTE: placeholder name
};

class HGroup : public HItem	// NOTE: placeholder name
{
public:
	Group *operator->() const;	// 0x9b7250
};

struct PropData	// NOTE: placeholder name
{
	char pad[0x8];
	int unknown8;	// NOTE: placeholder name
	char pad0c[0x28 - 0xc];
	int unknown28;	// NOTE: placeholder name
	char pad2c[0xf8 - 0x2c];
	int unknownf8;	// NOTE: placeholder name
};

class Prop	// NOTE: placeholder name
{
public:
	bool unknown45cc10();	// NOTE: placeholder name
	bool opw3_unknown65e230();	// NOTE: placeholder name
	int opw3_getIndex457af0();	// NOTE: placeholder name (ICF'd getter)
	const Point &opw3_getPosition() throw();	// NOTE: placeholder name (0x4184d0, ICF'd getter)
	PropData *opw3_getData();	// NOTE: placeholder name (0x9b8f00, ICF'd getter)
	PropData *opw3_getData2();	// NOTE: placeholder name (0x45cb30, ICF'd getter)
	int opw3_getUnknown44a630() throw();	// NOTE: placeholder name (ICF'd getter)
	int opw3_getUnknown44ab40();	// NOTE: placeholder name (ICF'd getter)
	OpW3_Color opw3_getColor() throw();
	int opw3_getUnknown457b10();	// NOTE: placeholder name (ICF'd getter)
	bool unknown45cb10();	// NOTE: placeholder name
	void opw3_unknown65f170();	// NOTE: placeholder name
	bool opw3_unknown665be0(bool flag);	// NOTE: placeholder name
	int opw3_unknown45c800(int type);	// NOTE: placeholder name (MapDatabase::unknown45c800)
	struct OpW3_PropObj *opw3_getObj();	// NOTE: placeholder name (ICF'd getter)
	vector<int> *opw3_getList45c7e0();	// NOTE: placeholder name
	int opw3_getUnknownH();	// NOTE: placeholder name (ICF'd getter 0x9b8f00)
	void opw3_unknown45cc50(const Point &p);	// NOTE: placeholder name (Prop::unknown45cc50)
	struct OpW3_HackData *opw3_getHackData();	// NOTE: placeholder name (ICF'd getter)
	bool opw3_unknown45cbd0();	// NOTE: placeholder name (Prop::unknown45cbd0)
	const string &opw3_getName45c590();	// NOTE: placeholder name
	int opw3_getUnknownGetter();	// NOTE: placeholder name (ICF'd getter)
	void opw3_unknown45ce10(bool a, int b, bool c, HProp d);	// NOTE: placeholder name (Prop::unknown45ce10)
	const string &opw3_getName();	// NOTE: placeholder name (0x45c5b0)	// NOTE: placeholder name (0x45c780)
};

class HProp : public HItem	// NOTE: placeholder layout
{
public:
	HProp();
	bool isNull() const;
	Prop *operator->() const throw();	// 0x9b64f0
};

class OpW3_Marker	// NOTE: placeholder name
{
public:
	void init(int type, const Point &p, int value);	// NOTE: placeholder name (0x6c20b0)

	char pad[8];
	Point position;	// NOTE: placeholder name
};

class OpW3_HMarker : public HItem	// NOTE: placeholder name
{
public:
	OpW3_Marker *operator->() const;	// 0x9b7cd0
};

class OpW3_EntityMgr	// NOTE: placeholder name
{
public:
	OpW3_HMarker createMarker();	// NOTE: placeholder name (0x793190)
	void opw3_unknown793450(int a, int b, int c, int d, int e);	// NOTE: placeholder name
	void opw3_unknown793690();	// NOTE: placeholder name
	HProp opw3_unknown793360(int id);	// NOTE: placeholder name
	HEntity opw3_unknown7930e0(class OpW3_Obj515ca0 *obj);	// NOTE: placeholder name
};
extern OpW3_EntityMgr *opw3_entityMgr;	// NOTE: placeholder name (0xcefaa8)

class OpW3_Console	// NOTE: placeholder name
{
public:
	bool isHidden();	// NOTE: placeholder name (0x48e3c0 XConsole::isHidden)
	void opw3_unknown7ba190();	// NOTE: placeholder name
};
extern OpW3_Console *opw3_consoleCC;	// NOTE: placeholder name (0xcec0cc)

struct OpW3_Region	// NOTE: placeholder name
{
	OpW3_Region(HEntity owner);	// NOTE: placeholder name (0x461950)
	void opw3_unknown72b290(int range, int x0, int y0, int x1, int y1);	// NOTE: placeholder name
	bool opw3_unknown461b10(vector<Point> &points);	// NOTE: placeholder name

	Array2D<int> map;	// NOTE: placeholder name
	int id;	// NOTE: placeholder name
	Point center;	// NOTE: placeholder name
	int radius;	// NOTE: placeholder name
};

struct OpW3_Link	// NOTE: placeholder name; element of the list at BS+0x4d0
{
	HEntity owner;	// NOTE: placeholder name
	HEntity target;	// NOTE: placeholder name
};

struct OpW3_Mark7f0	// NOTE: placeholder name; element of the list at BS+0x7f0
{
	OpW3_Mark7f0(const Point &position_, const string &text_, int type_);	// NOTE: placeholder name (0x4614b0)

	Point position;	// NOTE: placeholder name
	string text;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
};

struct OpW3_PropMark	// NOTE: placeholder name
{
	OpW3_PropMark(const Point &position_, int value_, const OpW3_Color &color_);	// 0x461f50

	Point position;	// NOTE: placeholder name
	int value;	// NOTE: placeholder name
	OpW3_Color color;	// NOTE: placeholder name
};

struct OpW3_MapLayer	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	vector<Point> points;	// NOTE: placeholder name
};

class OpW3_Conduit	// NOTE: placeholder name
{
public:
	HProp opw3_getProp();	// NOTE: placeholder name (0x6c12e0)

	bool opw3_unknown6c1320();	// NOTE: placeholder name

	vector<int> indices;	// NOTE: placeholder name
	vector<int> targets;	// NOTE: placeholder name
	vector<int> flags;	// NOTE: placeholder name
	bool active;	// NOTE: placeholder name
};
extern vector<OpW3_Conduit *> opw3_conduits;	// NOTE: placeholder name (0xd39f1c)
void OpW3_traceLine(const Point &from, const Point &to, vector<Point> *out);	// NOTE: placeholder name (0x40ff30)

class OpW3_MapConsole	// NOTE: placeholder name (object at 0xcec054)
{
public:
	OpW3_MapLayer *opw3_getLayer(int index);	// NOTE: placeholder name (0x49ae50)
	void opw3_unknown814540(const Point &p);	// NOTE: placeholder name
	void opw3_unknown80e3a0(bool flag, const Point &p);	// NOTE: placeholder name
	void opw3_unknown49ad30();	// NOTE: placeholder name (MapView::unknown49ad30)
	void opw3_unknown49adf0(HEntity e);	// NOTE: placeholder name (MapView::unknown49adf0)
	void opw3_unknown813050(bool flag, HProp prop, int a, int b, int c);	// NOTE: placeholder name
	OpW3_MapLayer *opw3_unknown49aec0();	// NOTE: placeholder name (MapView::unknown49aec0)
	void opw3_unknown80ed40(bool flag, OpW3_Mark7f0 *mark);	// NOTE: placeholder name
	void opw3_unknown819870(const Point &p, int range);	// NOTE: placeholder name
	void opw3_unknown49adc0(int value);	// NOTE: placeholder name (MapView::unknown49adc0)
};
extern OpW3_MapConsole *opw3_mapConsole;	// NOTE: placeholder name (0xcec054)

class OpW3_Obj_cf45d8	// NOTE: placeholder name
{
public:
	bool opw3_unknown77f260(int value);	// NOTE: placeholder name
	bool opw3_unknown46de40(int value);	// NOTE: placeholder name
	void opw3_unknown77fbc0(int value);	// NOTE: placeholder name
};
extern OpW3_Obj_cf45d8 opw3_obj_cf45d8;	// NOTE: placeholder name (0xcf45d8)
extern bool opw3_flag_d28e84;	// NOTE: placeholder name
extern bool opw3_flag_d28e85;	// NOTE: placeholder name
extern bool opw3_flag_d28e86;	// NOTE: placeholder name

bool traceSubcellLine(const Point &from, const Point &to, vector<Point> &cells, vector<int> &steps, int subcells);	// 0x9d...

// line trace state (statics in the original)
extern int opw3_traceDX;	// NOTE: placeholder name (0xd3c2d4)
extern int opw3_traceDY;	// NOTE: placeholder name (0xd3c2d0)
extern int opw3_traceAX;	// NOTE: placeholder name (0xd3c2cc)
extern int opw3_traceAY;	// NOTE: placeholder name (0xd3c2c8)
extern int opw3_traceSX;	// NOTE: placeholder name (0xd3c2c4)
extern int opw3_traceSY;	// NOTE: placeholder name (0xd3c2c0)
extern int opw3_traceX;	// NOTE: placeholder name (0xd3c2bc)
extern int opw3_traceY;	// NOTE: placeholder name (0xd3c2b8)
extern float opw3_traceFactor;	// NOTE: placeholder name (0xd3c2b4)
extern int opw3_traceRange;	// NOTE: placeholder name (0xd3c2b0)
extern int opw3_traceDX2;	// NOTE: placeholder name (0xd3c2ac)
extern int opw3_traceDY2;	// NOTE: placeholder name (0xd3c2a8)
extern int opw3_checkDX;	// NOTE: placeholder name (0xd3c304)
extern int opw3_checkDY;	// NOTE: placeholder name (0xd3c300)
extern int opw3_checkAX;	// NOTE: placeholder name (0xd3c2fc)
extern int opw3_checkAY;	// NOTE: placeholder name (0xd3c2f8)
extern int opw3_checkSX;	// NOTE: placeholder name (0xd3c2f4)
extern int opw3_checkSY;	// NOTE: placeholder name (0xd3c2f0)
extern int opw3_checkX;	// NOTE: placeholder name (0xd3c2ec)
extern int opw3_checkY;	// NOTE: placeholder name (0xd3c2e8)
extern float opw3_checkFactor;	// NOTE: placeholder name (0xd3c2e4)
extern int opw3_checkRange;	// NOTE: placeholder name (0xd3c2e0)
extern int opw3_checkDX2;	// NOTE: placeholder name (0xd3c2dc)
extern int opw3_checkDY2;	// NOTE: placeholder name (0xd3c2d8)
extern int opw3_lineDX;	// NOTE: placeholder name (0xd3c32c)
extern int opw3_lineDY;	// NOTE: placeholder name (0xd3c328)
extern int opw3_lineAX;	// NOTE: placeholder name (0xd3c324)
extern int opw3_lineAY;	// NOTE: placeholder name (0xd3c320)
extern int opw3_lineSX;	// NOTE: placeholder name (0xd3c31c)
extern int opw3_lineSY;	// NOTE: placeholder name (0xd3c318)
extern int opw3_lineX;	// NOTE: placeholder name (0xd3c314)
extern int opw3_lineY;	// NOTE: placeholder name (0xd3c310)
extern int opw3_lineDX2;	// NOTE: placeholder name (0xd3c30c)
extern int opw3_lineDY2;	// NOTE: placeholder name (0xd3c308)
extern int opw3_walkDX;	// NOTE: placeholder name (0xd3c2a4)
extern int opw3_walkDY;	// NOTE: placeholder name (0xd3c2a0)
extern int opw3_walkAX;	// NOTE: placeholder name (0xd3c29c)
extern int opw3_walkAY;	// NOTE: placeholder name (0xd3c298)
extern int opw3_walkSX;	// NOTE: placeholder name (0xd3c294)
extern int opw3_walkSY;	// NOTE: placeholder name (0xd3c290)
extern int opw3_walkX;	// NOTE: placeholder name (0xd3c28c)
extern int opw3_walkY;	// NOTE: placeholder name (0xd3c288)
extern int opw3_walkDX2;	// NOTE: placeholder name (0xd3c284)
extern int opw3_walkDY2;	// NOTE: placeholder name (0xd3c280)
extern int opw3_spreadDX;	// NOTE: placeholder name (0xd3c27c)
extern int opw3_spreadDY;	// NOTE: placeholder name (0xd3c278)
extern int opw3_spreadAX;	// NOTE: placeholder name (0xd3c274)
extern int opw3_spreadAY;	// NOTE: placeholder name (0xd3c270)
extern int opw3_spreadSX;	// NOTE: placeholder name (0xd3c26c)
extern int opw3_spreadSY;	// NOTE: placeholder name (0xd3c268)
extern int opw3_spreadX;	// NOTE: placeholder name (0xd3c264)
extern int opw3_spreadY;	// NOTE: placeholder name (0xd3c260)
extern float opw3_spreadFactor;	// NOTE: placeholder name (0xd3c25c)
extern int opw3_spreadRange;	// NOTE: placeholder name (0xd3c258)
extern int opw3_spreadDX2;	// NOTE: placeholder name (0xd3c254)
extern int opw3_spreadDY2;	// NOTE: placeholder name (0xd3c250)

extern bool opw3_flag_cefc9e;	// NOTE: placeholder name
extern bool opw3_flag_cefc9f;	// NOTE: placeholder name
extern Array2D<int> *opw3_grid_cefca0;	// NOTE: placeholder name
extern vector<Point> opw3_points_d2ec1c;	// NOTE: placeholder name
extern vector<int> opw3_times_cfc20c;	// NOTE: placeholder name
extern vector<Point> opw3_points_cf2800;	// NOTE: placeholder name
extern vector<int> opw3_times_d32ecc;	// NOTE: placeholder name
extern int opw3_tickCount;	// NOTE: placeholder name (0xcaed20)
template <class T> bool OpW3_contains(vector<T> &v, T e);	// NOTE: placeholder name (0x9d0ce0 for Point)
bool OpW3_notLastTwo(int i, int size);	// NOTE: placeholder name

template <class T> int OpW3_indexOf(vector<T> &v, T e);	// NOTE: placeholder name (0x9d3110)
template <class T> void OpW3_insertAt(vector<T> &v, int i, T e);	// NOTE: placeholder name (0x9dbdc0)
template <class T> void OpW3_deleteAtIndex(vector<T> &v, int i);	// NOTE: placeholder name (0x9de400)
bool opw3_unknown5111e0(int id, const string &a, const string *b, int c, HProp d, HProp e, const Point *f, int g);	// NOTE: placeholder name
extern string opw3_string_d2a414;	// NOTE: placeholder name (0xd2a414)
extern vector<vector<HProp> > opw3_propLists;	// NOTE: placeholder name (0xd31640)
extern bool opw3_flag_d28f61;	// NOTE: placeholder name

class OpW3_ConsoleA	// NOTE: placeholder name
{
public:
	void opw3_unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpW3_ConsoleA *opw3_consoleA;	// NOTE: placeholder name (0xcec058)

class OpW3_ConsoleB	// NOTE: placeholder name
{
public:
	void opw3_unknown7b4f10();	// NOTE: placeholder name
};
extern OpW3_ConsoleB *opw3_consoleB;	// NOTE: placeholder name (0xcec0b4)
extern int opw3_mode_cf462c;	// NOTE: placeholder name
extern int opw3_flag_cf49fc;	// NOTE: placeholder name
bool opw3_unknown437320(int value);	// NOTE: placeholder name
extern OpW3_Color opw3_colors_d329a4[];	// NOTE: placeholder name

class OpW3_Tracked	// NOTE: placeholder name
{
public:
	OpW3_Color opw3_getColor();	// NOTE: placeholder name (0x72eb70)
	bool opw3_isActive();	// NOTE: placeholder name (0x72ec10)

	int unknown0;	// NOTE: placeholder name
	int level;	// NOTE: placeholder name
	HEntity entity;	// NOTE: placeholder name
	int unknownc;	// NOTE: placeholder name
	OpW3_Color color;	// NOTE: placeholder name
};

struct OpW3_Mark	// NOTE: placeholder name; element of the grid at BS+0x740
{
	int value;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
	HEntity entity;	// NOTE: placeholder name
	int unknownc;	// NOTE: placeholder name
	OpW3_Color color;	// NOTE: placeholder name
};

class OpW3_GameData	// NOTE: placeholder name (object at 0xd1e860)
{
public:
	bool opw3_unknown46fb60();	// NOTE: placeholder name
	bool opw3_unknown46f4b0(int value);	// NOTE: placeholder name
	bool opw3_unknown789580(HProp prop);	// NOTE: placeholder name
	string &opw3_unknown46f6d0(const string &key);	// NOTE: placeholder name
	void opw3_unknown46f700(const string &key, const string &value);	// NOTE: placeholder name
	bool opw3_unknown789620();	// NOTE: placeholder name
};
extern OpW3_GameData opw3_gameData;	// NOTE: placeholder name (0xd1e860)

class OpW3_Obj_cf4ac8	// NOTE: placeholder name
{
public:
	bool opw3_unknown7abf80();	// NOTE: placeholder name
};
extern OpW3_Obj_cf4ac8 *opw3_obj_cf4ac8;	// NOTE: placeholder name (0xcf4ac8)
extern int opw3_flag_d255ac;	// NOTE: placeholder name
extern bool opw3_flag_cf4a00;	// NOTE: placeholder name

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)

struct OpW3_GameState	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
	char pad08[0x25 - 0x8];
	bool unknown25;	// NOTE: placeholder name
};

class OpW3_HGameState : public HItem	// NOTE: placeholder name
{
public:
	OpW3_GameState *operator->() const;	// 0x9b7910
};
extern OpW3_HGameState opw3_gameState;	// NOTE: placeholder name (0xd1e888)

struct OpW3_Machine	// NOTE: placeholder name
{
	char pad00[0x25];
	bool unknown25;	// NOTE: placeholder name
};

class OpW3_HMachine : public HItem	// NOTE: placeholder name
{
public:
	OpW3_Machine *operator->() const;	// 0x9b7910
};

struct MapZone	// NOTE: placeholder
{
	void opw3_unknown6c16d0(string text);	// NOTE: placeholder name

	int pad[2];
	OpW3_HMachine machine;
	bool unknownc;	// NOTE: placeholder name
	bool found;	// NOTE: placeholder name
};
struct OpW3_PossessData	// NOTE: placeholder name
{
	int index;	// NOTE: placeholder name
};
extern OpW3_PossessData *opw3_possessed;	// NOTE: placeholder name (0xcf4700)

struct OpW3_RobotData	// NOTE: placeholder name
{
	char pad000[0x148];
	vector<int> tags;	// NOTE: placeholder name
};
extern vector<OpW3_RobotData *> opw3_robotData;	// NOTE: placeholder name (0xd25de0)
bool opw3_contains9db330(vector<int> *list, int value);	// NOTE: placeholder name

extern int TERRAIN_EARTH;	// NOTE: placeholder (0xcefb80)
extern int opw3_terrain_cefb84;	// NOTE: placeholder name
extern bool opw3_flag_cefb3e;	// NOTE: placeholder name
void opw3_noop4f0a50(Cell *cell, bool flag);	// NOTE: placeholder name (empty function)

struct OpW3_TerrainRecord	// NOTE: placeholder name
{
	int ID;
};
extern OpW3_TerrainRecord *opw3_terrain_cefb9c;	// NOTE: placeholder name
extern OpW3_TerrainRecord *opw3_terrain_cefbac;	// NOTE: placeholder name
extern Array2D<int> originalTerrain;
void opw3_unknown6c1080(const Point &p);	// NOTE: placeholder name
void opw3_unknown5141b0(int id, const string &text, int a, int b, HProp prop, const Point &p);	// NOTE: placeholder name

extern bool opw3_flag_d28d30;	// NOTE: placeholder name
extern const int opw3_table_ba6a28[];	// NOTE: placeholder name
extern const int opw3_table_ba69e0[];	// NOTE: placeholder name
int opw3_pick9d9c10(const int *table, int count);	// NOTE: placeholder name

class OpW3_Obj515ca0	// NOTE: placeholder name
{
public:
	OpW3_Obj515ca0(HEntity a, int id, const Point &pos, HEntity b, const Point &c, const Point &d);	// NOTE: placeholder name (0x515ca0)
	char pad[0x40];
};
struct OpW3_Exit	// NOTE: placeholder name; element of the list at BS+0x10
{
	void opw3_unknown6c16d0(string text);	// NOTE: placeholder name (MapZone method)

	Point pos;	// NOTE: placeholder name
	OpW3_HGameState destination;	// NOTE: placeholder name
	bool used;	// NOTE: placeholder name
	bool known;	// NOTE: placeholder name
	bool seen;	// NOTE: placeholder name
	char pad0f[0x14 - 0xf];
	HEntity unknown14;	// NOTE: placeholder name
	HEntity unknown18;	// NOTE: placeholder name
};

class Cartographer2DMoveCost;
class Cartographer2D
{
public:
	bool findPath(const Point &from, const Point &to, Cartographer2DMoveCost *moveCost, void *data, vector<Point> &path);	// NOTE: placeholder name
};
extern Cartographer2D opw3_cartographer;	// NOTE: placeholder name (0xcfe568)
extern Cartographer2DMoveCost *opw3_moveCost;	// NOTE: placeholder name (0xcefc30)
void opw3_erasePointAt(vector<Point> &v, int index);	// NOTE: placeholder name (0x9d5190)
bool opw3_removePoint(vector<Point> &v, Point p);	// NOTE: placeholder name (0x9d3060)
void opw3_eraseListAt(vector<vector<HItemP> > &v, int index);	// NOTE: placeholder name (0x9de1d0)

class OpW3_Overmind	// NOTE: placeholder name (object at 0xcf6428)
{
public:
	void opw3_spawnPatrolParty(HProp a, int b, int c, int d, int e, int f, int g, int h, int i);	// NOTE: placeholder name (Overmind::spawnPatrolParty)
};
extern OpW3_Overmind opw3_overmind;	// NOTE: placeholder name (0xcf6428)

class OpW3_MessageLog	// NOTE: placeholder name (object at 0xcf1080)
{
public:
	void opw3_unknown451400(int value);	// NOTE: placeholder name
	int opw3_push(class OpW3_Obj510f80 *message);	// NOTE: placeholder name (MessageLog::push)
};
extern OpW3_MessageLog opw3_messageLog;	// NOTE: placeholder name (0xcf1080)
void opw3_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)
extern bool opw3_flag_d28fb0;	// NOTE: placeholder name
extern vector<void *> opw3_list_d2e9a0;	// NOTE: placeholder name
int opw3_unknown500500(void *data, const Point &a, const Point &b);	// NOTE: placeholder name
void opw3_unknown454260(const Point *p, int value);	// NOTE: placeholder name

void opw3_shuffle9d9fc0(vector<HEntity> &v);	// NOTE: placeholder name
int opw3_maxIndex9d4500(vector<int> &v);	// NOTE: placeholder name

string intToString(int value);
void opw3_eraseAt9d7300(vector<Point> &v, unsigned int &i);	// NOTE: placeholder name
void opw3_unknown9de280(vector<string> &out, vector<string> &in);	// NOTE: placeholder name
int opw3_count9de310(vector<string> &list, string s);	// NOTE: placeholder name
void opw3_sort9de3c0(vector<string>::iterator first, vector<string>::iterator last);	// NOTE: placeholder name
extern int opw3_counter_cf4d20;	// NOTE: placeholder name

struct OpW3_HackData	// NOTE: placeholder name
{
	bool opw3_unknown65cf50(int value);	// NOTE: placeholder name
	bool opw3_unknown65cf80();	// NOTE: placeholder name

	char pad00[0x10];
	int type;	// NOTE: placeholder name
};

class OpW3_Obj510d20	// NOTE: placeholder name
{
public:
	OpW3_Obj510d20(int type, int a, int b, int c, HProp d, HProp e);	// NOTE: placeholder name (0x510d20)
	char pad[0x20];
};

class OpW3_ConsoleF4	// NOTE: placeholder name
{
public:
	void opw3_unknown7b1880(OpW3_Obj510d20 *obj);	// NOTE: placeholder name
};
extern OpW3_ConsoleF4 *opw3_consoleF4;	// NOTE: placeholder name (0xcec0f4)
extern int opw3_flag_cf4744;	// NOTE: placeholder name
void opw3_shufflePoints9d7350(vector<Point> &v);	// NOTE: placeholder name
bool opw3_unknown5111e0(int id, const string &a, const string *b, int c, HEntity d, HProp e, const Point *f, int g);	// NOTE: placeholder name (same function, other overload)

extern bool opw3_flags_b95758[];	// NOTE: placeholder name
void opw3_unknown5141b0(int id, const string &text, int a, int b, HProp prop, const Point *p);	// NOTE: placeholder name (same function, other overload)
void opw3_unknown4569a0(int id, HEntity a, HEntity b, HProp c, HProp d, int e, int f, void *inventory, HEntity g, HProp h, HProp i, int j);	// NOTE: placeholder name

struct OpW3_Obj_cf68b4	// NOTE: placeholder name
{
	char pad000[0x110];
	int type;	// NOTE: placeholder name
};
extern OpW3_Obj_cf68b4 *opw3_obj_cf68b4;	// NOTE: placeholder name
extern HEntity opw3_entity_cf68b8;	// NOTE: placeholder name
extern int opw3_count_cf68c8;	// NOTE: placeholder name
extern int opw3_value_cf6a18;	// NOTE: placeholder name
class OpW3_Obj_cf68f0	// NOTE: placeholder name
{
public:
	void opw3_unknown672f20(HEntity e, int a, int b, string text);	// NOTE: placeholder name
};
extern OpW3_Obj_cf68f0 *opw3_obj_cf68f0;	// NOTE: placeholder name (0xcf68f0)
extern string opw3_names_d1d0f8[];	// NOTE: placeholder name
int opw3_find9cda80(string *list, int count, string text);	// NOTE: placeholder name
extern vector<int> opw3_flags_d1e950;	// NOTE: placeholder name
extern vector<string> opw3_names_d1e930;	// NOTE: placeholder name
extern int opw3_flag_d28d2c;	// NOTE: placeholder name
extern int opw3_flag_d28f8c;	// NOTE: placeholder name
extern bool opw3_flag_d28d28;	// NOTE: placeholder name

struct OpW3_PropObj	// NOTE: placeholder name
{
	bool opw3_unknown456540();	// NOTE: placeholder name
};
class OpW3_Obj_d25450	// NOTE: placeholder name
{
public:
	void opw3_unknown69e700(int a, int b, float c);	// NOTE: placeholder name

	bool enabled;	// NOTE: placeholder name
};
extern OpW3_Obj_d25450 opw3_obj_d25450;	// NOTE: placeholder name
extern Area opw3_area_d1eaf8;	// NOTE: placeholder name
// NOTE: the fields of opw3_area_d1eaf8 as separate symbols; the verifier only pairs data by symbol start
extern int opw3_area_d1eafc;	// NOTE: placeholder name (opw3_area_d1eaf8.y1)
extern int opw3_area_d1eb00;	// NOTE: placeholder name (opw3_area_d1eaf8.x2)
extern int opw3_area_d1eb04;	// NOTE: placeholder name (opw3_area_d1eaf8.y2)
extern int opw3_value_cefbd0;	// NOTE: placeholder name
template <class T> bool OpW3_erase(vector<T> &v, T e);
void opw3_eraseExitAt(vector<OpW3_Exit *> &v, unsigned int &i);	// NOTE: placeholder name (0x9da9f0)
extern vector<int> opw3_vec_cf35b0;	// NOTE: placeholder name
bool opw3_lookup9d7710(vector<int> *list, const string &name, int &id);	// NOTE: placeholder name
void opw3_unknown5141b0(int id, const string *text, int a, int b, HProp prop, const Point *p);	// NOTE: placeholder name (same function, other overload)

class OpW3_AI57f6a0	// NOTE: placeholder name
{
public:
	OpW3_AI57f6a0(HEntity e, int a, int b);	// NOTE: placeholder name (0x57f6a0)
	char pad[0x130];
};
extern int opw3_flag_d1eb10;	// NOTE: placeholder name
void opw3_unknown789ac0();	// NOTE: placeholder name
extern vector<int> opw3_vec_d2c408;	// NOTE: placeholder name
bool opw3_lookup9d7de0(vector<int> *list, const string &name, struct OpW3_Talk *&talk);	// NOTE: placeholder name
int opw3_randomIndex9d9b20(vector<HEntity> *v);	// NOTE: placeholder name
extern int opw3_list_cfc1a4[];	// NOTE: placeholder name
int opw3_find9d4660(int *list, int value);	// NOTE: placeholder name
extern vector<Area> opw3_areas_d22fa8;	// NOTE: placeholder name
void opw3_eraseAt9d6440(vector<HEntity> &v, unsigned int &i);	// NOTE: placeholder name
extern int opw3_turn_d1eb28;	// NOTE: placeholder name
extern int opw3_turn_d1eb2c;	// NOTE: placeholder name
extern int opw3_turn_d1eb30;	// NOTE: placeholder name
extern int opw3_turn_d1eb34;	// NOTE: placeholder name
extern int opw3_turn_d1eb3c;	// NOTE: placeholder name
extern int opw3_count_d1eb40;	// NOTE: placeholder name

void opw3_eraseIndex9ce6d0(vector<int> &v, unsigned int &i);	// NOTE: placeholder name

int opw3_pickWeighted9d9270(vector<int> &weights);	// NOTE: placeholder name

extern int opw3_caf164;	// NOTE: placeholder name
extern int opw3_caf15c;	// NOTE: placeholder name

class Map	// NOTE: placeholder name
{
public:
	MapZone *getZone(const Point &p);	// 0x462e30
	int getTurn();	// 0x464270
	void removeEntity(HEntity e);	// NOTE: placeholder name
	void opw3_unknown465950(int a, int b, int c);	// NOTE: placeholder name
	bool isReachable(int range, const Point &from, const Point &to) throw();	// 0x465230
	int unknown4630a0();	// NOTE: placeholder name
	Array2D<bool> *unknown4637f0();	// NOTE: placeholder name
	Array2D<int> *unknown463830();	// NOTE: placeholder name
	void unknown4647a0(const Point &p, bool flag);	// NOTE: placeholder name
	HEntity getPlayer() throw();	// 0x4630f0
	HGroup unknown463890(int i);	// NOTE: placeholder name
	bool unknown465200(const Point &a, const Point &b);	// NOTE: placeholder name
};

struct MapRecord	// element of the grid at BS+0x7c4
{
	void updateItem(Cell *cell);	// 0x6c1a90
	void opw3_unknown6c1cd0(Cell *cell, bool a, bool b);	// NOTE: placeholder name

	char pad00[0x10];
	int unknown10;	// NOTE: placeholder name
	char pad14[0x24 - 0x14];
	int unknown24;	// NOTE: placeholder name
};

class BS : public Map	// NOTE: placeholder layout
{
public:
	void opw3_unknown7243c0(int x, int y, bool flag);	// NOTE: placeholder name
	void opw3_unknown724420(int x, int y);	// NOTE: placeholder name
	void opw3_unknown724480();	// NOTE: placeholder name
	void opw3_unknown724a10();	// NOTE: placeholder name
	void opw3_unknown724cf0();	// NOTE: placeholder name
	int opw3_unknown726600(const Point &p);	// NOTE: placeholder name
	void opw3_unknown726840(const Area &area, bool reveal);	// NOTE: placeholder name
	bool opw3_unknown726d60();	// NOTE: placeholder name
	void opw3_unknown727150(const Point &center, int count, int radius, int value);	// NOTE: placeholder name
	HEntity opw3_unknown7285b0();	// NOTE: placeholder name
	bool opw3_unknown728b00(Point p, int &count);	// NOTE: placeholder name
	void opw3_unknown7297a0();	// NOTE: placeholder name
	void opw3_unknown747860(bool a, bool b);	// NOTE: placeholder name
	void opw3_unknown72f2e0();	// NOTE: placeholder name
	void opw3_unknown72f350();	// NOTE: placeholder name
	void opw3_unknown72f3f0();	// NOTE: placeholder name
	void opw3_unknown72f460();	// NOTE: placeholder name
	void opw3_unknown72f4e0(HEntity e);	// NOTE: placeholder name
	void opw3_unknown72f570();	// NOTE: placeholder name
	void opw3_unknown72f5b0(HEntity e);	// NOTE: placeholder name
	void opw3_unknown72f620();	// NOTE: placeholder name
	void opw3_unknown72f670();	// NOTE: placeholder name
	void opw3_unknown72ed70(bool alert);	// NOTE: placeholder name
	void opw3_unknown725930(HEntity e, bool reset);	// NOTE: placeholder name
	void opw3_unknown724f00();	// NOTE: placeholder name
	void opw3_unknown72f6b0();	// NOTE: placeholder name
	void opw3_unknown72ffe0(bool quiet);	// NOTE: placeholder name
	HEntity opw3_unknown6c5dc0(const string &name, const Point &p, int a, int b, int c, int d, int e);	// NOTE: placeholder name
	void opw3_unknown6c65a0(HEntity e, const string &text, int value);	// NOTE: placeholder name
	void opw3_unknown9e29b0(vector<HProp> &v, HProp prop);	// NOTE: placeholder name
	HEntity opw3_unknown727ef0();	// NOTE: placeholder name
	bool unknown7168e0(const Point &from, const Point &to, Entity *e, vector<Point> &path);
	HEntity opw3_unknown777a20(HEntity e);	// NOTE: placeholder name
	bool opw3_unknown71c150(const Point &a, const Point &b, int size);	// NOTE: placeholder name
	bool unknown716940(const Point &from, const Point &to, Entity *e, unsigned int *length);
	void unknown734d60(const Point &p);	// NOTE: placeholder name
	void opw3_unknown71dd30(OpW3_HMachine machine);	// NOTE: placeholder name
	void opw3_unknown71dd30(OpW3_HGameState machine);	// NOTE: placeholder name (same function, other overload)
	void opw3_unknown726260(HEntity e);	// NOTE: placeholder name
	void opw3_unknown726320();	// NOTE: placeholder name
	void opw3_unknown726520();	// NOTE: placeholder name
	void opw3_unknown726af0(int value);	// NOTE: placeholder name
	void opw3_unknown726b70(HItemP item);	// NOTE: placeholder name
	void opw3_unknown726bd0(HItemP item);	// NOTE: placeholder name
	bool opw3_unknown726c30(HProp prop, bool refresh);	// NOTE: placeholder name
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	bool isVisible(const Point &p);	// 0x4631c0
	void opw3_unknown726ff0(const Point &p);	// NOTE: placeholder name
	void opw3_unknown7270c0(Point *p);	// NOTE: placeholder name
	bool opw3_unknown7272e0();	// NOTE: placeholder name
	void opw3_unknown727370();	// NOTE: placeholder name
	int opw3_unknown7275f0(HEntity e, int value);	// NOTE: placeholder name
	bool opw3_unknown7276b0(HEntity e, int value);	// NOTE: placeholder name
	bool opw3_unknown727780(HEntity e, int value);	// NOTE: placeholder name
	bool opw3_unknown7278e0(HEntity e, int a, int b);	// NOTE: placeholder name
	int opw3_unknown7279a0(HEntity e);	// NOTE: placeholder name
	int opw3_unknown727ad0(HEntity e);	// NOTE: placeholder name
	int opw3_unknown727c70(HEntity e, int value);	// NOTE: placeholder name
	void opw3_unknown727e30(HItemP item, int a, int b);	// NOTE: placeholder name
	void opw3_unknown727ea0(HItemP item);	// NOTE: placeholder name
	void opw3_unknown728970(HEntity e, HItemP item);	// NOTE: placeholder name
	void opw3_unknown7289f0(HItemP item, int a);	// NOTE: placeholder name
	void opw3_unknown728f30(HItemP item);	// NOTE: placeholder name
	void opw3_unknown728fa0(HItemP item);	// NOTE: placeholder name
	bool opw3_unknown728ff0(HEntity e);	// NOTE: placeholder name
	bool opw3_unknown7290f0(HEntity e);	// NOTE: placeholder name
	void opw3_unknown729160(HEntity e);	// NOTE: placeholder name
	void opw3_unknown729350(Point p);	// NOTE: placeholder name
	void opw3_unknown729470(HEntity e, bool ownerOnly);	// NOTE: placeholder name
	void opw3_unknown729520(const Point &p);	// NOTE: placeholder name
	void opw3_unknown729bc0(HProp prop);	// NOTE: placeholder name
	bool opw3_unknown729d60(HEntity e);	// NOTE: placeholder name
	bool opw3_unknown729de0();	// NOTE: placeholder name
	void opw3_unknown729eb0(const Point &p, const string &text, int type, bool notify);	// NOTE: placeholder name
	bool opw3_unknown72a050(const Point &p);	// NOTE: placeholder name
	void opw3_unknown72a0b0(HEntity e);	// NOTE: placeholder name
	void opw3_unknown72a1e0(const Point &p, bool flag);	// NOTE: placeholder name
	int unknown463e50();	// NOTE: placeholder name
	vector<HProp> &unknown463c00(int index);	// NOTE: placeholder name
	void opw3_unknown721600();	// NOTE: placeholder name
	void opw3_unknown71fef0(HEntity e);	// NOTE: placeholder name
	void opw3_unknown720070(bool reset);	// NOTE: placeholder name
	void opw3_unknown720210(vector<Point> &points);	// NOTE: placeholder name
	void opw3_unknown7202f0(HEntity e);	// NOTE: placeholder name
	void opw3_unknown720470(bool reset);	// NOTE: placeholder name
	void opw3_unknown720610(vector<Point> &points);	// NOTE: placeholder name
	void opw3_unknown7206f0(HEntity e);	// NOTE: placeholder name
	void opw3_unknown720870(bool reset);	// NOTE: placeholder name
	void opw3_unknown720a30(vector<Point> &points);	// NOTE: placeholder name
	void opw3_unknown720b10(HEntity e);	// NOTE: placeholder name
	void opw3_unknown720c90(bool reset);	// NOTE: placeholder name
	void opw3_unknown720e30(vector<Point> &points);	// NOTE: placeholder name
	void opw3_unknown720f00(HEntity e);	// NOTE: placeholder name
	void opw3_unknown721080(bool reset);	// NOTE: placeholder name
	void opw3_unknown721240(vector<Point> &points);	// NOTE: placeholder name
	void opw3_unknown721320(HEntity e);	// NOTE: placeholder name
	void opw3_unknown7214a0(bool reset);	// NOTE: placeholder name
	bool opw3_unknown72a290(int x0, int y0, int x1, int y1);	// NOTE: placeholder name
	void opw3_unknown72adf0(int x0, int y0, int x1, int y1);	// NOTE: placeholder name
	void opw3_unknown72b030(int x, int y, int radius, int mode);	// NOTE: placeholder name
	void opw3_unknown72bad0(int index);	// NOTE: placeholder name
	static void opw3_unknown72bbe0(vector<int> &indices, vector<string> &names);	// NOTE: placeholder name
	static void opw3_unknown72bdc0(OpW3_Conduit *conduit, int index);	// NOTE: placeholder name
	static bool opw3_unknown72c080(vector<OpW3_Conduit *> &list, bool silent, HEntity e);	// NOTE: placeholder name
	void opw3_unknown72c700(int index, bool flag);	// NOTE: placeholder name
	void opw3_unknown72e4c0(HEntity e, bool flag);	// NOTE: placeholder name
	void opw3_unknown72e5e0(HEntity e, int type, bool silent);	// NOTE: placeholder name
	void opw3_unknown72e790(unsigned int index);	// NOTE: placeholder name
	void opw3_unknown72e8e0(bool flag);	// NOTE: placeholder name
	bool opw3_unknown72e990(HEntity e);	// NOTE: placeholder name
	bool opw3_unknown72e9d0(HEntity e);	// NOTE: placeholder name
	void opw3_unknown72ea10();	// NOTE: placeholder name
	void opw3_unknown72ec60();	// NOTE: placeholder name
	bool opw3_unknown72a4d0(int range, int x0, int y0, int x1, int y1);	// NOTE: placeholder name
	bool opw3_unknown72a850(int range, HEntity a, HEntity b);	// NOTE: placeholder name
	bool opw3_unknown72a900(int range, const Point &from, const Point &to);	// NOTE: placeholder name
	void opw3_unknown72a9d0(int range, int x0, int y0, int x1, int y1, vector<Point> &path);	// NOTE: placeholder name
	void opw3_unknown72ad80(int range, int x0, int y0, int x1, int y1, vector<Point> &path, vector<int> &steps);	// NOTE: placeholder name

	char pad0[0x10];
	vector<struct OpW3_Exit *> exits;	// 0x10	NOTE: placeholder name
	char pad20[0x38 - 0x20];
	Array2D<int> grid;	// 0x38	NOTE: placeholder name
	int gridValue;	// 0x44	NOTE: placeholder name
	char pad48[0x4c - 0x48];
	vector<HGroup> groups;	// 0x4c	NOTE: placeholder name
	char pad5c[0x118 - 0x5c];
	vector<vector<Point> > pointLists;	// 0x118	NOTE: placeholder name
	char pad128[0x1b8 - 0x128];
	vector<Point *> points1b8;	// 0x1b8	NOTE: placeholder name
	char pad1c8[0x1d8 - 0x1c8];
	bool flag1d8;	// 0x1d8	NOTE: placeholder name
	char pad1d9[0x200 - 0x1d9];
	int counter200;	// 0x200	NOTE: placeholder name
	char pad204[0x230 - 0x204];
	int counter230;	// 0x230	NOTE: placeholder name
	char pad234[0x320 - 0x234];
	int unknown320;	// 0x320	NOTE: placeholder name
	int unknown324;	// 0x324	NOTE: placeholder name
	char pad328[0x330 - 0x328];
	vector<vector<HItemP> > itemsByType;	// 0x330	NOTE: placeholder name
	vector<HItemP> items340;	// 0x340	NOTE: placeholder name
	vector<int> ints350;	// 0x350	NOTE: placeholder name
	vector<int> ints360;	// 0x360	NOTE: placeholder name
	vector<HItemP> items370;	// 0x370	NOTE: placeholder name
	vector<int> ints380;	// 0x380	NOTE: placeholder name
	vector<HItemP> items390;	// 0x390	NOTE: placeholder name
	vector<int> ints3a0;	// 0x3a0	NOTE: placeholder name
	vector<HItemP> items3b0;	// 0x3b0	NOTE: placeholder name
	vector<HItemP> items3c0;	// 0x3c0	NOTE: placeholder name
	char pad3d0[0x480 - 0x3d0];
	vector<HItemP> items480;	// 0x480	NOTE: placeholder name
	char pad490[0x4d0 - 0x490];
	vector<OpW3_Link *> links;	// 0x4d0	NOTE: placeholder name
	vector<HProp> props4e0;	// 0x4e0	NOTE: placeholder name
	vector<HProp> props4f0;	// 0x4f0	NOTE: placeholder name
	char pad500[0x584 - 0x500];
	vector<Point> points584;	// 0x584	NOTE: placeholder name
	vector<HEntity> entities594;	// 0x594	NOTE: placeholder name
	vector<vector<HItemP> > items5a4;	// 0x5a4	NOTE: placeholder name
	int unknown5b4;	// 0x5b4	NOTE: placeholder name
	char pad5b8[0x5bc - 0x5b8];
	vector<Point> points5bc;	// 0x5bc	NOTE: placeholder name
	vector<int> times5cc;	// 0x5cc	NOTE: placeholder name
	vector<HEntity> entities5dc;	// 0x5dc	NOTE: placeholder name
	char pad5ec[0x5fc - 0x5ec];
	HEntity entity5fc;	// 0x5fc	NOTE: placeholder name
	HEntity entity600;	// 0x600	NOTE: placeholder name
	char pad604[0x644 - 0x604];
	bool pointsCleared;	// 0x644	NOTE: placeholder name
	char pad645[0x66c - 0x645];
	HEntity player;	// 0x66c	NOTE: placeholder name
	char pad670[0x674 - 0x670];
	Array2D<bool> visited674;	// 0x674	NOTE: placeholder name
	Array2D<bool> seen680;	// 0x680	NOTE: placeholder name
	char pad68c[0x690 - 0x68c];
	Array2D<int> grid690;	// 0x690	NOTE: placeholder name
	Array2D<int> grid69c;	// 0x69c	NOTE: placeholder name
	vector<Point> points6a8;	// 0x6a8	NOTE: placeholder name
	vector<HEntity> entities6b8;	// 0x6b8	NOTE: placeholder name
	vector<HEntity> entities6c8;	// 0x6c8	NOTE: placeholder name
	vector<OpW3_Region *> regions;	// 0x6d8	NOTE: placeholder name
	OpW3_Region *region6e8;	// 0x6e8	NOTE: placeholder name
	vector<HEntity> entities6ec;	// 0x6ec	NOTE: placeholder name
	vector<HEntity> entities6fc;	// 0x6fc	NOTE: placeholder name
	bool flag70c;	// 0x70c	NOTE: placeholder name
	char pad70d[0x720 - 0x70d];
	vector<HProp> props720;	// 0x720	NOTE: placeholder name
	char pad730[0x740 - 0x730];
	Array2D<OpW3_Mark> marks740;	// 0x740	NOTE: placeholder name
	int markValue;	// 0x74c	NOTE: placeholder name
	bool flag750;	// 0x750	NOTE: placeholder name
	bool flag751;	// 0x751	NOTE: placeholder name
	bool flag752;	// 0x752	NOTE: placeholder name
	bool flag753;	// 0x753	NOTE: placeholder name
	vector<Point> marked5;	// 0x754	NOTE: placeholder name
	vector<Point> marked8;	// 0x764	NOTE: placeholder name
	vector<Point> marked7;	// 0x774	NOTE: placeholder name
	vector<Point> marked6;	// 0x784	NOTE: placeholder name
	vector<Point> marked9;	// 0x794	NOTE: placeholder name
	vector<Point> marked10;	// 0x7a4	NOTE: placeholder name
	vector<HEntity> entities7b4;	// 0x7b4	NOTE: placeholder name
	Array2D<MapRecord> cells7c4;	// 0x7c4	NOTE: placeholder name
	vector<Point> points7d0;	// 0x7d0	NOTE: placeholder name
	vector<vector<OpW3_HMarker> > markers;	// 0x7e0	NOTE: placeholder name
	vector<OpW3_Mark7f0 *> marks;	// 0x7f0	NOTE: placeholder name
	char pad800[0x860 - 0x800];
	int timer860;	// 0x860	NOTE: placeholder name
	int timer864;	// 0x864	NOTE: placeholder name
	char pad868[0x8dc - 0x868];
	vector<vector<Point> > propPoints;	// 0x8dc	NOTE: placeholder name
	vector<vector<OpW3_PropMark *> > propMarks;	// 0x8ec	NOTE: placeholder name
	int firstPropList;	// 0x8fc	NOTE: placeholder name
	int propValue;	// 0x900	NOTE: placeholder name
	char pad904[0x9a4 - 0x904];
	int counter9a4;	// 0x9a4	NOTE: placeholder name
	int counter9a8;	// 0x9a8	NOTE: placeholder name
	int counter9ac;	// 0x9ac	NOTE: placeholder name
	int counter9b0;	// 0x9b0	NOTE: placeholder name
	int counter9b4;	// 0x9b4	NOTE: placeholder name
	int counter9b8;	// 0x9b8	NOTE: placeholder name
	vector<HEntity> entities9bc;	// 0x9bc	NOTE: placeholder name
	char pad9cc[0x9f0 - 0x9cc];
	int counter9f0;	// 0x9f0	NOTE: placeholder name
	vector<HEntity> entities9f4;	// 0x9f4	NOTE: placeholder name
	int unknownA04;	// 0xa04	NOTE: placeholder name
	int counterA08;	// 0xa08	NOTE: placeholder name
	char padA0c[0xa10 - 0xa0c];
	int counterA10;	// 0xa10	NOTE: placeholder name
};
extern BS *opw3_world;	// NOTE: placeholder name (0xcefc4c)

bool opw3_lookupID(const string &name, int &id);	// NOTE: placeholder name (0x9d7980)
template <class T> void OpW3_deleteAt(vector<T> &v, int i);	// NOTE: placeholder name (0x9de160)
int opw3_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
int opw3_distance(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
int opw3_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)
int opw3_sqr(int a);	// NOTE: placeholder name (0x9ccff0)
template <class T> void OpW3_eraseAtIndex(vector<T> *v, unsigned int *i);	// NOTE: placeholder name (0x9de640, steps i back)
extern const int opw3_table_ba0b70[][5];	// NOTE: placeholder name (0xba0b70)

extern bool opw3_flag_cefb34;	// NOTE: placeholder name (0xcefb34)
extern bool opw3_flag_cefc8a;	// NOTE: placeholder name (0xcefc8a)


class OpW3_Effect	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class OpW3_EffectMgr	// NOTE: placeholder name
{
public:
	OpW3_Effect *create();	// NOTE: placeholder name (0x508610)
};
extern OpW3_EffectMgr *opw3_effectMgr;	// NOTE: placeholder name (0xcefc50)
extern Point opw3_effectOrigin;	// NOTE: placeholder name (0xd2e20c)

extern int opw3_difficulty_cf4718;	// NOTE: placeholder name (0xcf4718)
extern int opw3_table_ba65a8[];	// NOTE: placeholder name (0xba65a8)
extern int opw3_counter_cf6498;	// NOTE: placeholder name (0xcf6498)

class OpW3_Obj_d2c658	// NOTE: placeholder name
{
public:
	void opw3_unknown4729d0(int id, int a, string text, int b);	// NOTE: placeholder name
};
extern OpW3_Obj_d2c658 opw3_obj_d2c658;	// NOTE: placeholder name (0xd2c658)

class OpW3_Obj_cf6888	// NOTE: placeholder name
{
public:
	void opw3_unknown6998a0(int a, int b, int c);	// NOTE: placeholder name
};
extern OpW3_Obj_cf6888 opw3_obj_cf6888;	// NOTE: placeholder name (0xcf6888)

//==================================================================
// BS
//==================================================================

OpW3_PropMark::OpW3_PropMark(const Point &position_, int value_, const OpW3_Color &color_)
	: position	(position_),
	  value		(value_),
	  color		(color_)
{
}

void BS::opw3_unknown726260(HEntity e)
{
	if (!OpW3_addUnique(entities6ec,e))
		return;
	if (e->opw3_getRecord()->unknown9b4350() >= 2 && e->getFaction() != 8 && e->getFaction() != 19 && (!e->opw3_unknown5d5250() || e->getFaction() == 6))
		OpW3_addUnique(entities6fc,e);
}

void BS::opw3_unknown726320()
{
	OpW3_Region *region = regions[0];
	Point topLeft;
	Point maxP;
	Array2D<int> &map = region->map;
	int mark = region->id;
	opw3_cells.getBounds(region->center,region->radius,topLeft,maxP);
	for (int x = topLeft.x; x <= maxP.x; x++)
	{
		for (int y = topLeft.y; y <= maxP.y; y++)
		{
			if (map(x,y) == mark && opw3_cells(x,y)->getEntity().isValid() && opw3_cells(x,y)->getEntity() != player &&
				opw3_cells(x,y)->getEntity()->isHostileTo(player) && opw3_cells(x,y)->getEntity()->getTarget() < 6 &&
				!OpW3_inVector(entities6ec,opw3_cells(x,y)->getEntity()))
				opw3_unknown726260(opw3_cells(x,y)->getEntity());
		}
	}
}

void BS::opw3_unknown726520()
{
	if (entities6ec.empty())
		return;
	for (int i = entities6ec.size() - 1; i >= 0; i--)
	{
		if (!entities6ec[i].operator->() || !unknown4631f0(entities6ec[i]))
		{
			OpW3_erase(entities6fc,entities6ec[i]);
			OpW3_eraseAt(entities6ec,i);
		}
	}
}

void BS::opw3_unknown726af0(int value)
{
	bool result;
	groups[0]->opw3_unknown6719c0(0,player,value,result,0,0,-1);
	groups[2]->opw3_unknown6719c0(0,player,value,result,0,0,-1);
}

void BS::opw3_unknown726b70(HItemP item)
{
	if (!opw3_itemTypeFlags[item->unknown457f90()])
		return;
	itemsByType[item->unknown457f90()].push_back(item);
}

void BS::opw3_unknown726bd0(HItemP item)
{
	if (!opw3_itemTypeFlags[item->unknown457f90()])
		return;
	OpW3_erase(itemsByType[item->unknown457f90()],item);
}

bool BS::opw3_unknown726c30(HProp prop, bool refresh)
{
	for (unsigned int i = 0; i < markers[0].size(); i++)
	{
		if (markers[0][i]->position == prop->opw3_getPosition())
			return false;
	}
	markers[0].push_back(opw3_entityMgr->createMarker());
	markers[0].back()->init(0,prop->opw3_getPosition(),prop->opw3_getData()->unknownf8);
	if (refresh && opw3_consoleCC && opw3_consoleCC->isHidden())
		opw3_consoleCC->opw3_unknown7ba190();
	return true;
}

void BS::opw3_unknown726ff0(const Point &p)
{
	if (!isVisible(p))
		return;
	int effectID;
	opw3_lookupID("C_Phasewall_Destroy_E",effectID);
	if (effectID != 0)
		opw3_effectMgr->create()->init(opw3_effectMgr,effectID,p,opw3_effectOrigin,0,0,0,9,0);
}

void BS::opw3_unknown7270c0(Point *p)
{
	for (unsigned int i = 0; i < points1b8.size(); i++)
	{
		if (*points1b8[i] == *p)
		{
			OpW3_deleteAt(points1b8,i);
			break;
		}
	}
	points1b8.push_back(p);
}

bool BS::opw3_unknown7272e0()
{
	counter200++;
	return counter200 > opw3_table_ba65a8[opw3_difficulty_cf4718] && rng.chance(opw3_maxInt(5,25 - player->opw3_unknown5c7f40() / 2));
}

void BS::opw3_unknown727370()
{
	counter230++;
	opw3_counter_cf6498 += 75;
	opw3_obj_d2c658.opw3_unknown4729d0(0x25c,1,"",-1);
	opw3_obj_cf6888.opw3_unknown6998a0(8,1,0);
}

int BS::opw3_unknown7275f0(HEntity e, int value)
{
	if (opw3_flag_cefb34)
		return value;
	for (unsigned int i = 0; i < itemsByType[55].size(); i++)
		value = itemsByType[55][i]->unknown457b50()->opw3_unknown5e2f00(e,value,itemsByType[55][i]);
	return value;
}

bool BS::opw3_unknown7276b0(HEntity e, int value)
{
	if (opw3_flag_cefb34)
		return false;
	for (unsigned int i = 0; i < itemsByType[56].size(); i++)
	{
		if (itemsByType[56][i]->unknown457b50()->opw3_unknown5e2fe0(e,value,itemsByType[56][i]))
			return true;
	}
	return false;
}

bool BS::opw3_unknown727780(HEntity e, int value)
{
	for (unsigned int i = 0; i < itemsByType[71].size(); i++)
	{
		if (itemsByType[71][i]->unknown457b50()->opw3_unknown5e30d0(e,value,itemsByType[71][i]))
			return true;
	}
	for (unsigned int j = 0; j < itemsByType[70].size(); j++)
	{
		if (itemsByType[70][j]->unknown457b50()->opw3_unknown5e30d0(e,value,itemsByType[70][j]))
			return true;
	}
	return false;
}

bool BS::opw3_unknown7278e0(HEntity e, int a, int b)
{
	for (unsigned int i = 0; i < itemsByType[72].size(); i++)
	{
		if (itemsByType[72][i]->unknown457b50()->opw3_unknown5e3310(e,a,b,itemsByType[72][i]))
			return true;
	}
	return false;
}

int BS::opw3_unknown7279a0(HEntity e)
{
	int total = 0;
	for (unsigned int i = 0; i < itemsByType[89].size(); i++)
	{
		HItemP item = itemsByType[89][i];
		if (item->unknown457b50()->unknown45aaa0(e) && !item->unknown457b50()->getTarget() && item->unknown457cf0() &&
			opw3_distance(item->unknown457b50()->getPosition(),e->getPosition()) <= 10)
			total += item->unknown457fb0();
	}
	return total;
}

int BS::opw3_unknown727ad0(HEntity e)
{
	int total = 0;
	for (unsigned int i = 0; i < itemsByType[83].size(); i++)
	{
		HItemP item = itemsByType[83][i];
		if (item->unknown457b50()->isHostileTo(e) && !item->unknown457b50()->getTarget() && item->unknown457cf0() &&
			opw3_distance(item->unknown457b50()->getPosition(),e->getPosition()) <= item->unknown457b50()->opw3_unknown5c7d30() &&
			unknown465200(item->unknown457b50()->getPosition(),e->getPosition()))
			total -= item->unknown457fb0();
	}
	return total;
}

int BS::opw3_unknown727c70(HEntity e, int value)
{
	for (unsigned int i = 0; i < itemsByType[190].size(); i++)
	{
		HItemP item = itemsByType[190][i];
		if (item->unknown457b50()->isHostileTo(e) && !item->unknown457b50()->getTarget() && item->unknown457cf0() &&
			opw3_distance(item->unknown457b50()->getPosition(),e->getPosition()) <= item->unknown457fb0() &&
			unknown465200(item->unknown457b50()->getPosition(),e->getPosition()))
		{
			if (e->isPlayer())
				opw3_flag_cefc8a = true;
			return 50;
		}
	}
	if (e->isPlayer())
		opw3_flag_cefc8a = false;
	return value;
}

void BS::opw3_unknown727e30(HItemP item, int a, int b)
{
	if (OpW3_inVector(items340,item))
		{}	// NOTE: empty in this build
	if (opw3_difficulty_cf4718 == 2)
		return;
	items340.push_back(item);
	ints350.push_back(a);
	ints360.push_back(b);
}

void BS::opw3_unknown727ea0(HItemP item)
{
	if (OpW3_inVector(items370,item))
		{}	// NOTE: empty in this build
	items370.push_back(item);
	ints380.push_back(unknown320);
}

void BS::opw3_unknown728970(HEntity e, HItemP item)
{
	for (unsigned int i = 0; i < entities594.size(); i++)
	{
		if (entities594[i] == e)
		{
			items5a4[i].push_back(item);
			break;
		}
	}
}

void BS::opw3_unknown7289f0(HItemP item, int a)
{
	if (OpW3_inVector(items390,item))
		return;
	items390.push_back(item);
	ints3a0.push_back(a);
	item->addEffect(new OpW3_ItemEffect(opw3_effectTypes[0x56],1));
	if (a == 0)
		item->addEffect(new OpW3_ItemEffect(opw3_effectTypes[0x58],1));
	item->unknown458460();
}

void BS::opw3_unknown728f30(HItemP item)
{
	if (item->opw3_unknown577b80() && !OpW3_inVector(items3b0,item) && !OpW3_inVector(items3c0,item))
		items3b0.push_back(item);
}

void BS::opw3_unknown728fa0(HItemP item)
{
	if (OpW3_inVector(items480,item))
		return;
	items480.push_back(item);
	item->unknown4584f0();
}

bool BS::opw3_unknown728ff0(HEntity e)
{
	for (unsigned int i = 0; i < links.size(); i++)
	{
		if (links[i]->target == e)
		{
			int level = opw3_minInt(links[i]->owner->opw3_unknown5d22a0(0x73),3);
			if (level > 0 && e->opw3_unknown5d2380(0x74).isNull() && !rng.chance(opw3_table_ba0b70[level - 1][e->unknown45a340()]))
				return true;
		}
	}
	return false;
}

bool BS::opw3_unknown7290f0(HEntity e)
{
	for (unsigned int i = 0; i < links.size(); i++)
	{
		if (links[i]->target == e)
			return true;
	}
	return false;
}

void BS::opw3_unknown729160(HEntity e)
{
	for (unsigned int i = 0; i < links.size(); i++)
	{
		if (links[i]->owner == e || links[i]->target == e)
		{
			HItemP found;
			vector<HItemP> *inventory = links[i]->owner->opw3_getInventoryList();
			for (unsigned int j = 0; j < inventory->size(); j++)
			{
				if ((*inventory)[j]->unknown457f90() == 0x73 && (*inventory)[j]->unknown457cf0())
				{
					found = (*inventory)[j];
					break;
				}
			}
			if (found.isNull() || opw3_distance(links[i]->owner->getPosition(),e->getPosition()) > found->unknown4580a0() ||
				!unknown465200(links[i]->owner->getPosition(),e->getPosition()))
				OpW3_eraseAtIndex(&links,&i);
		}
	}
}

void BS::opw3_unknown729350(Point p)
{
	for (unsigned int i = 0; i < links.size(); i++)
	{
		if (opw3_distance(p,links[i]->owner->getPosition()) > 16 || opw3_distance(p,links[i]->target->getPosition()) > 16)
			continue;
		if (!unknown465200(links[i]->owner->getPosition(),links[i]->target->getPosition()))
			OpW3_eraseAtIndex(&links,&i);
	}
}

void BS::opw3_unknown729470(HEntity e, bool ownerOnly)
{
	for (unsigned int i = 0; i < links.size(); i++)
	{
		if (links[i]->owner == e || (!ownerOnly && links[i]->target == e))
			OpW3_eraseAtIndex(&links,&i);
	}
}

void BS::opw3_unknown729520(const Point &p)
{
	if (entities594.empty() || opw3_obj_cf45d8.opw3_unknown77f260(100))
		return;
	for (unsigned int i = 0; i < entities594.size(); i++)
	{
		if (entities594[i].operator->() && entities594[i]->getGroup()->opw3_unknown9b4350() == 3)
		{
			if (rng.chance(3) && !entities594[i]->getTarget() && entities594[i]->opw3_getRecord()->opw3_unknown581630() &&
				!entities594[i]->opw3_getRecord()->opw3_unknown459570(opw3_world->getPlayer()) && player->opw3_unknown5d2380(0x1f).isNull())
			{
				int range = entities594[i]->opw3_unknown5d22a0(0xd);
				range -= 2;
				if (opw3_distance(p,entities594[i]->getPosition()) <= range)
				{
					entities594[i]->opw3_getRecord()->opw3_setUnknown(-1);
					entities594[i]->opw3_getRecord()->opw3_unknown5b3a30(range);
				}
			}
		}
		else
			entities594[i].opw3_reset();
	}
}

void BS::opw3_unknown729bc0(HProp prop)
{
	Point pos = prop->opw3_getPosition();
	for (unsigned int i = 0; i < propPoints.size(); i++)
	{
		for (unsigned int j = 0; j < propPoints[i].size(); j++)
		{
			if (propPoints[i][j] == pos)
			{
				propMarks[i].push_back(new OpW3_PropMark(prop->opw3_getPosition(),prop->opw3_getUnknown44a630(),prop->opw3_getColor()));
				if (firstPropList == -1 || (int)i < firstPropList)
					firstPropList = i;
				if (propValue == -1)
					propValue = prop->opw3_getUnknown44ab40();
				return;
			}
		}
	}
}

bool BS::opw3_unknown729d60(HEntity e)
{
	if (e == entity5fc)
	{
		if (entity600 == e)
			return false;
		else
		{
			entity600 = e;
			return true;
		}
	}
	else
	{
		entity5fc = e;
		entity600.opw3_reset();
		return false;
	}
}

bool BS::opw3_unknown729de0()
{
	if (pointsCleared)
		return false;
	for (int i = 0; i < 9; i++)
	{
		if (i != 5)
		{
			for (unsigned int j = 0; j < pointLists[i].size(); j++)
				opw3_cells(pointLists[i][j])->getProp()->opw3_getData2()->unknown28 = -1;
		}
	}
	pointsCleared = true;
	return true;
}

void BS::opw3_unknown729eb0(const Point &p, const string &text, int type, bool notify)
{
	OpW3_Mark7f0 *mark = 0;
	bool found = false;
	for (unsigned int i = 0; i < marks.size(); i++)
	{
		if (marks[i]->position == p)
		{
			marks[i]->text = text;
			marks[i]->type = type;
			mark = marks[i];
			found = true;
			break;
		}
	}
	if (mark == 0)
	{
		marks.push_back(new OpW3_Mark7f0(p,text,type));
		mark = marks.back();
	}
	if (found)
		opw3_mapConsole->opw3_unknown814540(p);
	if (notify)
		opw3_mapConsole->opw3_unknown80ed40(type != 0,mark);
}

bool BS::opw3_unknown72a050(const Point &p)
{
	for (unsigned int i = 0; i < marks.size(); i++)
	{
		if (marks[i]->position == p)
			return true;
	}
	return false;
}

void BS::opw3_unknown72a0b0(HEntity e)
{
	switch (e->getFaction())
	{
		case 0x1a:
			if (!opw3_flag_d28e84)
				return;
			break;
		case 0x1c:
			if (!opw3_flag_d28e85)
				return;
			break;
		case 0x15:
			if (!opw3_flag_d28e86)
				return;
			break;
		default:
			return;
	}
	if (e->getAiType() == 1 && e->isHostileTo(player) && e->opw3_getRecord()->opw3_unknown581580() && !opw3_unknown72a050(e->getPosition()))
		opw3_unknown729eb0(e->getPosition(),e->opw3_getName(),e->getFaction() == 0x1a ? 2 : 1,false);
}

void BS::opw3_unknown72a1e0(const Point &p, bool flag)
{
	for (unsigned int i = 0; i < marks.size(); i++)
	{
		if (marks[i]->position == p)
		{
			if (!flag || marks[i]->type != 0)
			{
				OpW3_deleteAt(marks,i);
				opw3_mapConsole->opw3_unknown814540(p);
			}
			break;
		}
	}
}

bool BS::opw3_unknown72a850(int range, HEntity a, HEntity b)
{
	vector<Point> *cells1 = a->opw3_getFootprint();
	vector<Point> *cells2 = b->opw3_getFootprint();
	for (unsigned int i = 0; i < cells1->size(); i++)
	{
		for (unsigned int j = 0; j < cells2->size(); j++)
		{
			if (isReachable(range,(*cells1)[i],(*cells2)[j]))
				return true;
		}
	}
	return false;
}

bool BS::opw3_unknown72a900(int range, const Point &from, const Point &to)
{
	vector<Point> path;
	opw3_unknown72a9d0(range,from.x,from.y,to.x,to.y,path);
	return opw3_unknown72a4d0(range,from.x,from.y,path[path.size() - 2].x,path[path.size() - 2].y);
}

void BS::opw3_unknown72a9d0(int range, int x0, int y0, int x1, int y1, vector<Point> &path)
{
	opw3_traceDX = x1 - x0;
	opw3_traceDY = y1 - y0;
	opw3_traceAX = (opw3_traceDX < 0 ? -opw3_traceDX : opw3_traceDX) << 1;
	opw3_traceAY = (opw3_traceDY < 0 ? -opw3_traceDY : opw3_traceDY) << 1;
	opw3_traceSX = opw3_traceDX < 0 ? -1 : opw3_traceDX > 0;
	opw3_traceSY = opw3_traceDY < 0 ? -1 : opw3_traceDY > 0;
	opw3_traceX = x0;
	opw3_traceY = y0;
	opw3_traceFactor = opw3_minInt(abs(opw3_traceDX),abs(opw3_traceDY)) == 0 ? 1.01 : (double)opw3_minInt(abs(opw3_traceDX),abs(opw3_traceDY)) / opw3_maxInt(abs(opw3_traceDX),abs(opw3_traceDY)) * 0.41f + 1.01f;
	opw3_traceRange = (int)(range / opw3_traceFactor);
	if (opw3_traceAX >= opw3_traceAY)
	{
		opw3_traceDX2 = opw3_traceAY - (opw3_traceAX >> 1);
		for (;;)
		{
			if (!opw3_cells(opw3_traceX,opw3_traceY)->unknown45d270())
				return;
			path.push_back(Point(opw3_traceX,opw3_traceY));
			opw3_traceRange--;
			opw3_cells(opw3_traceX,opw3_traceY)->opw3_unknown670f50(&opw3_traceRange,opw3_traceFactor);
			if (opw3_traceRange < 0)
				return;
			if (opw3_traceX == x1)
				return;
			if (opw3_traceDX2 >= 0)
			{
				opw3_traceY += opw3_traceSY;
				opw3_traceDX2 -= opw3_traceAX;
			}
			opw3_traceX += opw3_traceSX;
			opw3_traceDX2 += opw3_traceAY;
		}
	}
	else
	{
		opw3_traceDY2 = opw3_traceAX - (opw3_traceAY >> 1);
		for (;;)
		{
			if (!opw3_cells(opw3_traceX,opw3_traceY)->unknown45d270())
				return;
			path.push_back(Point(opw3_traceX,opw3_traceY));
			opw3_traceRange--;
			opw3_cells(opw3_traceX,opw3_traceY)->opw3_unknown670f50(&opw3_traceRange,opw3_traceFactor);
			if (opw3_traceRange < 0)
				return;
			if (opw3_traceY == y1)
				return;
			if (opw3_traceDY2 >= 0)
			{
				opw3_traceX += opw3_traceSX;
				opw3_traceDY2 -= opw3_traceAY;
			}
			opw3_traceY += opw3_traceSY;
			opw3_traceDY2 += opw3_traceAX;
		}
	}
}

void BS::opw3_unknown72ad80(int range, int x0, int y0, int x1, int y1, vector<Point> &path, vector<int> &steps)
{
	opw3_unknown72a9d0(range,x0,y0,x1,y1,path);
	Point end = path.back();
	path.clear();
	traceSubcellLine(Point(x0,y0),end,path,steps,10);
}

bool BS::opw3_unknown72a4d0(int range, int x0, int y0, int x1, int y1)
{
	opw3_checkDX = x1 - x0;
	opw3_checkDY = y1 - y0;
	opw3_checkAX = (opw3_checkDX < 0 ? -opw3_checkDX : opw3_checkDX) << 1;
	opw3_checkAY = (opw3_checkDY < 0 ? -opw3_checkDY : opw3_checkDY) << 1;
	opw3_checkSX = opw3_checkDX < 0 ? -1 : opw3_checkDX > 0;
	opw3_checkSY = opw3_checkDY < 0 ? -1 : opw3_checkDY > 0;
	opw3_checkX = x0;
	opw3_checkY = y0;
	opw3_checkFactor = opw3_minInt(abs(opw3_checkDX),abs(opw3_checkDY)) == 0 ? 1.01 : (double)opw3_minInt(abs(opw3_checkDX),abs(opw3_checkDY)) / opw3_maxInt(abs(opw3_checkDX),abs(opw3_checkDY)) * 0.41f + 1.01f;
	opw3_checkRange = (int)((range + 1) / opw3_checkFactor);
	if (opw3_checkAX >= opw3_checkAY)
	{
		opw3_checkDX2 = opw3_checkAY - (opw3_checkAX >> 1);
		for (;;)
		{
			if (!opw3_cells(opw3_checkX,opw3_checkY)->unknown45d270())
				return false;
			opw3_checkRange--;
			opw3_cells(opw3_checkX,opw3_checkY)->opw3_unknown670f50(&opw3_checkRange,opw3_checkFactor);
			if (opw3_checkRange < 0)
				return false;
			if (opw3_checkX == x1)
				return true;
			if (opw3_checkDX2 >= 0)
			{
				opw3_checkY += opw3_checkSY;
				opw3_checkDX2 -= opw3_checkAX;
			}
			opw3_checkX += opw3_checkSX;
			opw3_checkDX2 += opw3_checkAY;
		}
	}
	else
	{
		opw3_checkDY2 = opw3_checkAX - (opw3_checkAY >> 1);
		for (;;)
		{
			if (!opw3_cells(opw3_checkX,opw3_checkY)->unknown45d270())
				return false;
			opw3_checkRange--;
			opw3_cells(opw3_checkX,opw3_checkY)->opw3_unknown670f50(&opw3_checkRange,opw3_checkFactor);
			if (opw3_checkRange < 0)
				return false;
			if (opw3_checkY == y1)
				return true;
			if (opw3_checkDY2 >= 0)
			{
				opw3_checkX += opw3_checkSX;
				opw3_checkDY2 -= opw3_checkAY;
			}
			opw3_checkY += opw3_checkSY;
			opw3_checkDY2 += opw3_checkAX;
		}
	}
}

bool BS::opw3_unknown72a290(int x0, int y0, int x1, int y1)
{
	opw3_lineDX = x1 - x0;
	opw3_lineDY = y1 - y0;
	opw3_lineAX = (opw3_lineDX < 0 ? -opw3_lineDX : opw3_lineDX) << 1;
	opw3_lineAY = (opw3_lineDY < 0 ? -opw3_lineDY : opw3_lineDY) << 1;
	opw3_lineSX = opw3_lineDX < 0 ? -1 : opw3_lineDX > 0;
	opw3_lineSY = opw3_lineDY < 0 ? -1 : opw3_lineDY > 0;
	opw3_lineX = x0;
	opw3_lineY = y0;
	if (opw3_lineAX >= opw3_lineAY)
	{
		opw3_lineDX2 = opw3_lineAY - (opw3_lineAX >> 1);
		for (;;)
		{
			if (!opw3_cells(opw3_lineX,opw3_lineY)->unknown45d270())
				return false;
			if (opw3_lineX == x1)
				return true;
			if (opw3_lineDX2 >= 0)
			{
				opw3_lineY += opw3_lineSY;
				opw3_lineDX2 -= opw3_lineAX;
			}
			opw3_lineX += opw3_lineSX;
			opw3_lineDX2 += opw3_lineAY;
		}
	}
	else
	{
		opw3_lineDY2 = opw3_lineAX - (opw3_lineAY >> 1);
		for (;;)
		{
			if (!opw3_cells(opw3_lineX,opw3_lineY)->unknown45d270())
				return false;
			if (opw3_lineY == y1)
				return true;
			if (opw3_lineDY2 >= 0)
			{
				opw3_lineX += opw3_lineSX;
				opw3_lineDY2 -= opw3_lineAY;
			}
			opw3_lineY += opw3_lineSY;
			opw3_lineDY2 += opw3_lineAX;
		}
	}
	return true;
}

void BS::opw3_unknown72adf0(int x0, int y0, int x1, int y1)
{
	opw3_walkDX = x1 - x0;
	opw3_walkDY = y1 - y0;
	opw3_walkAX = (opw3_walkDX < 0 ? -opw3_walkDX : opw3_walkDX) << 1;
	opw3_walkAY = (opw3_walkDY < 0 ? -opw3_walkDY : opw3_walkDY) << 1;
	opw3_walkSX = opw3_walkDX < 0 ? -1 : opw3_walkDX > 0;
	opw3_walkSY = opw3_walkDY < 0 ? -1 : opw3_walkDY > 0;
	opw3_walkX = x0;
	opw3_walkY = y0;
	if (opw3_walkAX >= opw3_walkAY)
	{
		opw3_walkDX2 = opw3_walkAY - (opw3_walkAX >> 1);
		for (;;)
		{
			if (!opw3_cells(opw3_walkX,opw3_walkY)->unknown45d270())
				return;
			if (opw3_walkX == x1)
				return;
			if (opw3_walkDX2 >= 0)
			{
				opw3_walkY += opw3_walkSY;
				opw3_walkDX2 -= opw3_walkAX;
			}
			opw3_walkX += opw3_walkSX;
			opw3_walkDX2 += opw3_walkAY;
		}
	}
	else
	{
		opw3_walkDY2 = opw3_walkAX - (opw3_walkAY >> 1);
		for (;;)
		{
			if (!opw3_cells(opw3_walkX,opw3_walkY)->unknown45d270())
				return;
			if (opw3_walkY == y1)
				return;
			if (opw3_walkDY2 >= 0)
			{
				opw3_walkX += opw3_walkSX;
				opw3_walkDY2 -= opw3_walkAY;
			}
			opw3_walkY += opw3_walkSY;
			opw3_walkDY2 += opw3_walkAX;
		}
	}
}

bool OpW3_notLastTwo(int i, int size)	// NOTE: placeholder name
{
	return i != size && i != size - 1;
}

void BS::opw3_unknown72b030(int x, int y, int radius, int mode)
{
	grid(x,y) = unknown4630a0();
	if (radius == 0)
		return;
	int minX = opw3_maxInt(0,x - radius);
	int xMax = opw3_minInt(x + radius + 1,grid.getWidth());
	int yMin = opw3_maxInt(0,y - radius);
	int maxY = opw3_minInt(y + radius + 1,grid.getHeight());
	switch (mode)
	{
		case 0:
		{
			int radiusSq = radius * radius;
			for (int i = minX; i < xMax; i++)
			{
				for (int j = yMin; j < maxY; j++)
				{
					if (opw3_sqr(i - x) + opw3_sqr(j - y) <= radiusSq)
						opw3_unknown72adf0(x,y,i,j);
				}
			}
		}
			break;
		case 1:
		{
			int radiusSq = radius * radius;
			for (int i = minX; i < xMax; i++)
			{
				for (int j = yMin; j < maxY; j++)
				{
					if (opw3_sqr(i - x) + opw3_sqr(j - y) <= radiusSq)
						grid(i,j) = gridValue;
				}
			}
		}
			break;
		case 2:
			for (int i = minX; i < xMax; i++)
			{
				for (int j = yMin; j < maxY; j++)
					grid(i,j) = gridValue;
			}
			break;
	}
}

#define MARK_SPREAD \
	if (opw3_flag_cefc9e && OpW3_notLastTwo(map(opw3_spreadX,opw3_spreadY),id) && !OpW3_contains(opw3_points_d2ec1c,Point(opw3_spreadX,opw3_spreadY)) && (*opw3_grid_cefca0)(opw3_spreadX,opw3_spreadY) == 0) \
	{ \
		opw3_points_d2ec1c.push_back(Point(opw3_spreadX,opw3_spreadY)); \
		opw3_times_cfc20c.push_back(opw3_tickCount); \
	} \
	if (opw3_flag_cefc9f && opw3_cells(opw3_spreadX,opw3_spreadY)->opw3_unknown45e0e0()) \
	{ \
		opw3_points_cf2800.push_back(Point(opw3_spreadX,opw3_spreadY)); \
		opw3_times_d32ecc.push_back(opw3_tickCount); \
	} \
	map(opw3_spreadX,opw3_spreadY) = id;

void OpW3_Region::opw3_unknown72b290(int range, int x0, int y0, int x1, int y1)
{
	opw3_spreadDX = x1 - x0;
	opw3_spreadDY = y1 - y0;
	opw3_spreadAX = (opw3_spreadDX < 0 ? -opw3_spreadDX : opw3_spreadDX) << 1;
	opw3_spreadAY = (opw3_spreadDY < 0 ? -opw3_spreadDY : opw3_spreadDY) << 1;
	opw3_spreadSX = opw3_spreadDX < 0 ? -1 : opw3_spreadDX > 0;
	opw3_spreadSY = opw3_spreadDY < 0 ? -1 : opw3_spreadDY > 0;
	opw3_spreadX = x0;
	opw3_spreadY = y0;
	opw3_spreadFactor = opw3_minInt(abs(opw3_spreadDX),abs(opw3_spreadDY)) == 0 ? 1.01 : (double)opw3_minInt(abs(opw3_spreadDX),abs(opw3_spreadDY)) / opw3_maxInt(abs(opw3_spreadDX),abs(opw3_spreadDY)) * 0.41f + 1.01f;
	opw3_spreadRange = (int)(range / opw3_spreadFactor);
	if (opw3_spreadAX >= opw3_spreadAY)
	{
		opw3_spreadDX2 = opw3_spreadAY - (opw3_spreadAX >> 1);
		for (;;)
		{
			if (!opw3_cells(opw3_spreadX,opw3_spreadY)->unknown45d270())
			{
				MARK_SPREAD
				return;
			}
			MARK_SPREAD
			opw3_spreadRange--;
			opw3_cells(opw3_spreadX,opw3_spreadY)->opw3_unknown670f50(&opw3_spreadRange,opw3_spreadFactor);
			if (opw3_spreadRange < 0)
				return;
			if (opw3_spreadX == x1)
				return;
			if (opw3_spreadDX2 >= 0)
			{
				opw3_spreadY += opw3_spreadSY;
				opw3_spreadDX2 -= opw3_spreadAX;
			}
			opw3_spreadX += opw3_spreadSX;
			opw3_spreadDX2 += opw3_spreadAY;
		}
	}
	else
	{
		opw3_spreadDY2 = opw3_spreadAX - (opw3_spreadAY >> 1);
		for (;;)
		{
			if (!opw3_cells(opw3_spreadX,opw3_spreadY)->unknown45d270())
			{
				MARK_SPREAD
				return;
			}
			MARK_SPREAD
			opw3_spreadRange--;
			opw3_cells(opw3_spreadX,opw3_spreadY)->opw3_unknown670f50(&opw3_spreadRange,opw3_spreadFactor);
			if (opw3_spreadRange < 0)
				return;
			if (opw3_spreadY == y1)
				return;
			if (opw3_spreadDY2 >= 0)
			{
				opw3_spreadX += opw3_spreadSX;
				opw3_spreadDY2 -= opw3_spreadAY;
			}
			opw3_spreadY += opw3_spreadSY;
			opw3_spreadDY2 += opw3_spreadAX;
		}
	}
}
#undef MARK_SPREAD

void BS::opw3_unknown72e4c0(HEntity e, bool flag)
{
	if (e->getGroup()->opw3_unknown9b4350() == 0)
		opw3_unknown72c700(groups[0]->opw3_indexOf(e),flag);
	else
	{
		int index = OpW3_indexOf(entities6b8,e);
		if (index != -1)
			opw3_unknown72c700(groups[0]->opw3_getMembers()->size() + index,flag);
		else
		{
			index = OpW3_indexOf(entities6c8,e);
			opw3_unknown72c700(groups[0]->opw3_getMembers()->size() + index + entities6b8.size(),flag);
		}
	}
}

void BS::opw3_unknown72e5e0(HEntity e, int type, bool silent)
{
	int index = -1;
	switch (type)
	{
		case 0:
			index = groups[0]->opw3_getMembers()->size() - 1;
			break;
		case 1:
			index = groups[0]->opw3_getMembers()->size() + entities6b8.size() - 1;
			break;
		case 2:
			index = groups[0]->opw3_getMembers()->size() + entities6b8.size() + entities6c8.size() - 1;
			break;
	}
	OpW3_insertAt(regions,index,new OpW3_Region(e));
	if (regions.size() == 1)
		region6e8 = regions[0];
	if (!silent)
		opw3_unknown72c700(index,false);
}

void BS::opw3_unknown72e790(unsigned int index)
{
	if (index >= groups[0]->opw3_getMembers()->size())
	{
		unsigned int i = index - groups[0]->opw3_getMembers()->size();
		if (i < entities6b8.size())
		{
			if (!entities6b8[i]->opw3_getRecord()->opw3_unknown459090())
				{}
			else
				entities6b8[i]->opw3_getRecord()->opw3_unknown4591c0(50);
			OpW3_eraseAt(entities6b8,i);
		}
		else
		{
			i -= entities6b8.size();
			OpW3_eraseAt(entities6c8,i);
		}
	}
	opw3_unknown72bad0(index);
	OpW3_deleteAtIndex(regions,index);
	if (index == 0)
		region6e8 = 0;
}

void BS::opw3_unknown72e8e0(bool flag)
{
	for (unsigned int i = 0; i < regions.size(); i++)
	{
		if (!flag && !points6a8.empty() && !regions[i]->opw3_unknown461b10(points6a8))
			continue;
		opw3_unknown72c700(i,!flag);
	}
	points6a8.clear();
}

bool BS::opw3_unknown72e990(HEntity e)
{
	if (OpW3_addUnique(entities6b8,e))
	{
		opw3_unknown72e5e0(e,1,false);
		return true;
	}
	return false;
}

bool BS::opw3_unknown72e9d0(HEntity e)
{
	if (OpW3_addUnique(entities6c8,e))
	{
		opw3_unknown72e5e0(e,2,false);
		return true;
	}
	return false;
}

void BS::opw3_unknown72ea10()
{
	if (entities6c8.empty())
		return;
	while (!entities6c8.empty())
		opw3_unknown72e790(groups[0]->opw3_getMembers()->size() + entities6b8.size());
	string text("All visual feed links lost");
	do
	{
		if (opw3_unknown5111e0(0x1d6,string(opw3_string_d2a414),&text,0,HProp(),HProp(),0,0))
			opw3_consoleA->opw3_unknown8758d0(true);
		opw3_consoleB->opw3_unknown7b4f10();
	} while (0);
}

OpW3_Color OpW3_Tracked::opw3_getColor()
{
	if (opw3_mode_cf462c == 4 && entity.operator->() && entity->getFaction() == 0x48 && level >= 4 && opw3_unknown437320(250))
		return opw3_colors_d329a4[entity->unknown45acb0(0x28)];
	else
		return color;
}

bool OpW3_Tracked::opw3_isActive()
{
	return entity.operator->() && opw3_world->unknown4631f0(entity);
}

void BS::opw3_unknown72ec60()
{
	if (opw3_flag_cf49fc)
	{
		timer860 = unknown320 + 30 + rng.rangeInt(1,6) + rng.rangeInt(1,6) + rng.rangeInt(1,6);
		timer864 = unknown324 + 15 + rng.rangeInt(1,6) + rng.rangeInt(1,6) + rng.rangeInt(1,6);
	}
	else
	{
		timer864 = 0;
		timer860 = 0;
	}
}

void BS::opw3_unknown72bad0(int index)
{
	Array2D<int> &ids = regions[index]->map;
	int mark = regions[index]->id;
	Point topLeft;
	Point maxP;
	opw3_cells.getBounds(regions[index]->center,regions[index]->radius,topLeft,maxP);
	for (int x = topLeft.x; x <= maxP.x; x++)
	{
		for (int y = topLeft.y; y <= maxP.y; y++)
		{
			if (ids(x,y) == mark)
				grid69c(x,y)--;
		}
	}
}

void BS::opw3_unknown72bbe0(vector<int> &indices, vector<string> &names)
{
	Array2D<bool> *seen = opw3_world->unknown4637f0();
	Array2D<int> *mapped = opw3_world->unknown463830();
	vector<Point> *points = &opw3_mapConsole->opw3_getLayer(1)->points;
	for (unsigned int i = 0; i < indices.size(); i++)
	{
		vector<HProp> &props = opw3_propLists[indices[i]];
		for (unsigned int j = 0; j < props.size(); j++)
		{
			if (j == 0)
			{
				if (props[j]->opw3_getUnknown457b10())
					continue;
				if (!(*seen)(props[j]->opw3_getPosition()) && (props[j]->unknown45cb10() || opw3_flag_d28f61))
					names.push_back(props[j]->opw3_getName());
			}
			if (!props[j]->unknown45cb10())
				points->push_back(props[j]->opw3_getPosition());
			if ((*mapped)(props[j]->opw3_getPosition()) == 0)
				opw3_world->unknown4647a0(props[j]->opw3_getPosition(),true);
		}
	}
}

void BS::opw3_unknown72bdc0(OpW3_Conduit *conduit, int index)
{
	vector<Point> *list = &opw3_mapConsole->opw3_getLayer(0)->points;
	HProp propA = conduit->opw3_getProp();
	HProp propB = opw3_conduits[conduit->targets[index]]->opw3_getProp();
	int clockwise = conduit->flags[index];
	const Point *ptA = &propA->opw3_getPosition();
	const Point *ptB = &propB->opw3_getPosition();
	if (ptA->y == ptB->y)
	{
		for (int x = opw3_minInt(ptA->x,ptB->x); x <= opw3_maxInt(ptA->x,ptB->x); x++)
			list->push_back(Point(x,ptA->y));
	}
	else if (ptA->y == ptB->y)
	{
		for (int y = opw3_minInt(ptA->y,ptB->y); y <= opw3_maxInt(ptA->y,ptB->y); y++)
			list->push_back(Point(ptA->x,y));
	}
	else
	{
		Point corner;
		if ((ptA->x < ptB->x && ptA->y < ptB->y) || (ptA->x > ptB->x && ptA->y > ptB->y))
		{
			if (clockwise)
				corner.set(opw3_maxInt(ptA->x,ptB->x),opw3_minInt(ptA->y,ptB->y));
			else
				corner.set(opw3_minInt(ptA->x,ptB->x),opw3_maxInt(ptA->y,ptB->y));
		}
		else
		{
			if (clockwise)
				corner.set(opw3_minInt(ptA->x,ptB->x),opw3_minInt(ptA->y,ptB->y));
			else
				corner.set(opw3_maxInt(ptA->x,ptB->x),opw3_maxInt(ptA->y,ptB->y));
		}
		OpW3_traceLine(*ptA,corner,list);
		list->pop_back();
		OpW3_traceLine(corner,*ptB,list);
	}
}

void BS::opw3_unknown720210(vector<Point> &points)
{
	if (unknown463e50() && marks740(points[0]).type == 6)
	{
		marks740(points[0]).value = 0;
		if (points.size() > 1)
		{
			for (unsigned int i = 1; i < points.size(); i++)
			{
				if (marks740(points[i]).type == 6)
					marks740(points[i]).value = 0;
			}
		}
	}
}

void BS::opw3_unknown720610(vector<Point> &points)
{
	if (unknown463e50() && marks740(points[0]).type == 7)
	{
		marks740(points[0]).value = 0;
		if (points.size() > 1)
		{
			for (unsigned int i = 1; i < points.size(); i++)
			{
				if (marks740(points[i]).type == 7)
					marks740(points[i]).value = 0;
			}
		}
	}
}

void BS::opw3_unknown720a30(vector<Point> &points)
{
	if (unknown463e50() && marks740(points[0]).type == 8)
	{
		marks740(points[0]).value = 0;
		if (points.size() > 1)
		{
			for (unsigned int i = 1; i < points.size(); i++)
			{
				if (marks740(points[i]).type == 8)
					marks740(points[i]).value = 0;
			}
		}
	}
}

void BS::opw3_unknown720e30(vector<Point> &points)
{
	if (marks740(points[0]).type == 9)
	{
		marks740(points[0]).value = 0;
		if (points.size() > 1)
		{
			for (unsigned int i = 1; i < points.size(); i++)
			{
				if (marks740(points[i]).type == 9)
					marks740(points[i]).value = 0;
			}
		}
	}
}

void BS::opw3_unknown721240(vector<Point> &points)
{
	if (unknown463e50() && marks740(points[0]).type == 10)
	{
		marks740(points[0]).value = 0;
		if (points.size() > 1)
		{
			for (unsigned int i = 1; i < points.size(); i++)
			{
				if (marks740(points[i]).type == 10)
					marks740(points[i]).value = 0;
			}
		}
	}
}

void BS::opw3_unknown7202f0(HEntity e)
{
	vector<Point> *cells = e->opw3_getFootprint();
	for (unsigned int i = 0; i < cells->size(); i++)
	{
		if (grid69c((*cells)[i]) == 0)
		{
			marks740((*cells)[i]).value = markValue;
			marks740((*cells)[i]).type = 6;
			marks740((*cells)[i]).entity = e;
			marks740((*cells)[i]).unknownc = e->unknown45a540((*cells)[i]);
			marks740((*cells)[i]).color = e->opw3_unknown5c7630();
			marked6.push_back((*cells)[i]);
		}
	}
	opw3_unknown72a0b0(e);
}

void BS::opw3_unknown7206f0(HEntity e)
{
	vector<Point> *cells = e->opw3_getFootprint();
	for (unsigned int i = 0; i < cells->size(); i++)
	{
		if (grid69c((*cells)[i]) == 0)
		{
			marks740((*cells)[i]).value = markValue;
			marks740((*cells)[i]).type = 7;
			marks740((*cells)[i]).entity = e;
			marks740((*cells)[i]).unknownc = e->unknown45a540((*cells)[i]);
			marks740((*cells)[i]).color = e->opw3_unknown5c7630();
			marked7.push_back((*cells)[i]);
		}
	}
	opw3_unknown72a0b0(e);
}

void BS::opw3_unknown720b10(HEntity e)
{
	vector<Point> *cells = e->opw3_getFootprint();
	for (unsigned int i = 0; i < cells->size(); i++)
	{
		if (grid69c((*cells)[i]) == 0)
		{
			marks740((*cells)[i]).value = markValue;
			marks740((*cells)[i]).type = 8;
			marks740((*cells)[i]).entity = e;
			marks740((*cells)[i]).unknownc = e->unknown45a540((*cells)[i]);
			marks740((*cells)[i]).color = e->opw3_unknown5c7630();
			marked8.push_back((*cells)[i]);
		}
	}
	opw3_unknown72a0b0(e);
}

void BS::opw3_unknown720f00(HEntity e)
{
	vector<Point> *cells = e->opw3_getFootprint();
	for (unsigned int i = 0; i < cells->size(); i++)
	{
		if (grid69c((*cells)[i]) == 0)
		{
			marks740((*cells)[i]).value = markValue;
			marks740((*cells)[i]).type = 9;
			marks740((*cells)[i]).entity = e;
			marks740((*cells)[i]).unknownc = e->unknown45a540((*cells)[i]);
			marks740((*cells)[i]).color = e->opw3_unknown5c7630();
			marked9.push_back((*cells)[i]);
		}
	}
	opw3_unknown72a0b0(e);
}

void BS::opw3_unknown721320(HEntity e)
{
	vector<Point> *cells = e->opw3_getFootprint();
	for (unsigned int i = 0; i < cells->size(); i++)
	{
		if (grid69c((*cells)[i]) == 0)
		{
			marks740((*cells)[i]).value = markValue;
			marks740((*cells)[i]).type = 10;
			marks740((*cells)[i]).entity = e;
			marks740((*cells)[i]).unknownc = e->unknown45a540((*cells)[i]);
			marks740((*cells)[i]).color = e->opw3_unknown5c7630();
			marked10.push_back((*cells)[i]);
		}
	}
	opw3_unknown72a0b0(e);
}

void BS::opw3_unknown720470(bool reset)
{
	if (opw3_flag_d255ac)
	{
		if (reset)
		{
			for (unsigned int i = 0; i < marked6.size(); i++)
			{
				if (marks740(marked6[i]).type == 6)
					marks740(marked6[i]).value = 0;
			}
		}
		marked6.clear();
		Point pos = player->getPosition();
		for (unsigned int g = 0; g < groups.size(); g++)
		{
			vector<HEntity> *members = groups[g]->opw3_getMembers();
			for (unsigned int j = 0; j < members->size(); j++)
			{
				if (!(*members)[j]->getTarget() && opw3_distance(pos,(*members)[j]->unknown5c80f0(pos)) <= 18)
					opw3_unknown7202f0((*members)[j]);
			}
		}
	}
}

void BS::opw3_unknown720870(bool reset)
{
	if (opw3_obj_cf4ac8 && opw3_obj_cf4ac8->opw3_unknown7abf80())
	{
		if (reset)
		{
			for (unsigned int i = 0; i < marked7.size(); i++)
			{
				if (marks740(marked7[i]).type == 7)
					marks740(marked7[i]).value = 0;
			}
		}
		marked7.clear();
		Point pos = player->getPosition();
		for (unsigned int g = 0; g < groups.size(); g++)
		{
			vector<HEntity> *members = groups[g]->opw3_getMembers();
			for (unsigned int j = 0; j < members->size(); j++)
			{
				if (!(*members)[j]->getTarget() && opw3_distance(pos,(*members)[j]->unknown5c80f0(pos)) <= 12)
					opw3_unknown7206f0((*members)[j]);
			}
		}
	}
}

void BS::opw3_unknown720c90(bool reset)
{
	if (opw3_flag_cf4a00)
	{
		if (reset)
		{
			for (unsigned int i = 0; i < marked8.size(); i++)
			{
				if (marks740(marked8[i]).type == 8)
					marks740(marked8[i]).value = 0;
			}
		}
		marked8.clear();
		Point pos = player->getPosition();
		for (unsigned int g = 0; g < groups.size(); g++)
		{
			vector<HEntity> *members = groups[g]->opw3_getMembers();
			for (unsigned int j = 0; j < members->size(); j++)
			{
				if (!(*members)[j]->getTarget() && opw3_distance(pos,(*members)[j]->unknown5c80f0(pos)) <= 18)
					opw3_unknown720b10((*members)[j]);
			}
		}
	}
}

void BS::opw3_unknown720070(bool reset)
{
	if (opw3_gameData.opw3_unknown46fb60())
	{
		if (reset)
		{
			for (unsigned int i = 0; i < marked5.size(); i++)
			{
				if (marks740(marked5[i]).type == 5)
					marks740(marked5[i]).value = 0;
			}
		}
		marked5.clear();
		Point playerPos = player->getPosition();
		vector<HEntity> *members = groups[3]->opw3_getMembers();
		for (unsigned int j = 0; j < members->size(); j++)
		{
			if (!(*members)[j]->getTarget() && opw3_distance(playerPos,(*members)[j]->unknown5c80f0(playerPos)) <= 18 && !(*members)[j]->opw3_unknown45ac40(0x11))
				opw3_unknown71fef0((*members)[j]);
		}
	}
}

void BS::opw3_unknown721080(bool reset)
{
	if (opw3_gameData.opw3_unknown789580(HProp()))
	{
		if (reset)
		{
			for (unsigned int i = 0; i < marked9.size(); i++)
			{
				if (marks740(marked9[i]).type == 9)
					marks740(marked9[i]).value = 0;
			}
		}
		marked9.clear();
		Point playerPos = player->getPosition();
		vector<HEntity> *members = groups[3]->opw3_getMembers();
		for (unsigned int j = 0; j < members->size(); j++)
		{
			if (!(*members)[j]->getTarget() && opw3_distance(playerPos,(*members)[j]->unknown5c80f0(playerPos)) <= 24 && player->opw3_unknown5d4490((*members)[j]))
				opw3_unknown720f00((*members)[j]);
		}
	}
}

void BS::opw3_unknown7214a0(bool reset)
{
	if (opw3_gameData.opw3_unknown789620())
	{
		if (reset)
		{
			for (unsigned int i = 0; i < marked10.size(); i++)
			{
				if (marks740(marked10[i]).type == 10)
					marks740(marked10[i]).value = 0;
			}
		}
		marked10.clear();
		Point playerPos = player->getPosition();
		for (int k = 3; k <= 4; k++)
		{
			vector<HEntity> *members = groups[k]->opw3_getMembers();
			for (unsigned int j = 0; j < members->size(); j++)
			{
				if (!(*members)[j]->getTarget())
					opw3_unknown721320((*members)[j]);
			}
		}
	}
}

void BS::opw3_unknown7243c0(int x, int y, bool flag)
{
	cells7c4(x,y).opw3_unknown6c1cd0(opw3_cells(x,y),flag,false);
	visited674(x,y) = true;
}

void BS::opw3_unknown724420(int x, int y)
{
	cells7c4(x,y).opw3_unknown6c1cd0(opw3_cells(x,y),false,false);
	visited674(x,y) = true;
}

void BS::opw3_unknown724480()
{
	flag753 = false;
	if (!flag1d8 && (opw3_gameState->type != 34 || !stringToInt(opw3_gameData.opw3_unknown46f6d0("comPlayerSurrendered_g"))))
	{
		flag753 = true;
		return;
	}
	if (opw3_gameState->type == 22 && !stringToInt(opw3_gameData.opw3_unknown46f6d0("zhiCloakGeneratorsDisabled_g")))
	{
		flag753 = true;
		return;
	}

	Point topLeft;
	Point maxP;
	vector<HEntity> *members = groups[0]->opw3_getMembers();
	for (unsigned int i = 0; i < members->size(); i++)
	{
		if (!(*members)[i]->getTarget())
		{
			Point pos = (*members)[i]->unknown45a4c0();
			int range = (*members)[i]->unknown45a3c0();
			int chance = (*members)[i]->opw3_unknown5c7e40();
			if (range)
			{
				if (opw3_obj_cf45d8.opw3_unknown46de40(116) && chance >= 100 && range >= 16 && (*members)[i]->isPlayer())
					opw3_obj_cf45d8.opw3_unknown77fbc0(116);
				int rangeSq = range * range;
				opw3_cells.getBounds(pos,range,topLeft,maxP);
				for (int x = topLeft.x; x <= maxP.x; x++)
				{
					for (int y = topLeft.y; y <= maxP.y; y++)
					{
						if (grid69c(x,y) == 0 && opw3_sqr(x - pos.x) + opw3_sqr(y - pos.y) <= rangeSq && rng.rangeInt(1,10000) <= chance)
						{
							if (visited674(x,y))
							{
								if (cells7c4(x,y).unknown10 == opw3_caf164 && cells7c4(x,y).unknown24 == opw3_caf15c)
									cells7c4(x,y).opw3_unknown6c1cd0(opw3_cells(x,y),true,true);
							}
							else
							{
								cells7c4(x,y).opw3_unknown6c1cd0(opw3_cells(x,y),true,true);
								visited674(x,y) = true;
								if (opw3_cells(x,y)->isMachinePart())
								{
									MapZone *zone = getZone(Point(x,y));
									zone->found = true;
									if (opw3_difficulty_cf4718 == 2 && !zone->machine->unknown25)
										opw3_unknown71dd30(zone->machine);
									zone->opw3_unknown6c16d0("FOUND");
									opw3_mapConsole->opw3_unknown80e3a0(true,Point(x,y));
								}
							}
						}
					}
				}
			}
		}
	}
}

void BS::opw3_unknown724a10()
{
	if (opw3_flag_cf4a00)
	{
		Point topLeft;
		Point maxP;
		Point playerPos = player->unknown45a4c0();
		int range = 18;
		int rangeSq = range * range;
		opw3_cells.getBounds(playerPos,range,topLeft,maxP);
		for (int x = topLeft.x; x <= maxP.x; x++)
		{
			for (int y = topLeft.y; y <= maxP.y; y++)
			{
				if (grid69c(x,y) == 0 && opw3_sqr(x - playerPos.x) + opw3_sqr(y - playerPos.y) <= rangeSq)
				{
					if (visited674(x,y))
						cells7c4(x,y).opw3_unknown6c1cd0(opw3_cells(x,y),false,true);
					else
					{
						cells7c4(x,y).opw3_unknown6c1cd0(opw3_cells(x,y),false,true);
						visited674(x,y) = true;
						if (opw3_cells(x,y)->isMachinePart())
						{
							MapZone *zone = getZone(Point(x,y));
							zone->found = true;
							if (opw3_difficulty_cf4718 == 2 && !zone->machine->unknown25)
								opw3_unknown71dd30(zone->machine);
							zone->opw3_unknown6c16d0("FOUND");
							opw3_mapConsole->opw3_unknown80e3a0(true,Point(x,y));
						}
						else if (opw3_cells(x,y)->isEdge() && !OpW3_contains(points7d0,Point(x,y)))
						{
							unknown734d60(Point(x,y));
							opw3_mapConsole->opw3_unknown80e3a0(true,Point(x,y));
						}
					}
				}
			}
		}
	}
}

void BS::opw3_unknown724cf0()
{
	if (opw3_possessed == NULL || !opw3_contains9db330(&opw3_robotData[opw3_possessed->index]->tags,5))
		return;

	Point topLeft;
	Point maxP;
	Point playerPos = player->unknown45a4c0();
	int range = 16;
	int rangeSq = range * range;
	opw3_cells.getBounds(playerPos,range,topLeft,maxP);
	for (int x = topLeft.x; x <= maxP.x; x++)
	{
		for (int y = topLeft.y; y <= maxP.y; y++)
		{
			if (grid69c(x,y) == 0 && opw3_sqr(x - playerPos.x) + opw3_sqr(y - playerPos.y) <= rangeSq && opw3_cells(x,y)->unknown45d700() && !opw3_cells(x,y)->isDoor())
			{
				if (visited674(x,y))
					cells7c4(x,y).updateItem(opw3_cells(x,y));
				else
				{
					cells7c4(x,y).updateItem(opw3_cells(x,y));
					visited674(x,y) = true;
				}
			}
		}
	}
}

int BS::opw3_unknown726600(const Point &p)
{
	const int range = 16;
	int danger = 0;
	vector<HEntity> done;
	HEntity entity;
	Area area;
	opw3_cells.getRect(p,range,area);
	for (int x = area.x1; x <= area.x2; x++)
	{
		for (int y = area.y1; y <= area.y2; y++)
		{
			if (opw3_cells(x,y)->getEntity().isValid())
			{
				entity = opw3_cells(x,y)->getEntity();
				if (!entity->isPlayer() && entity->isHostileTo(opw3_world->getPlayer()) && entity->getTarget() < 6 && !OpW3_inVector(done,entity) &&
					opw3_distance406480(p.x,p.y,x,y) <= range && entity->opw3_getRecord()->unknown9b4350() >= 2 && entity->getFaction() != 8 && entity->getFaction() != 19 &&
					(!entity->opw3_unknown5d5250() || entity->getFaction() == 6) && isReachable(range,entity->getPosition(),p))
					danger += entity->opw3_getData()->value;
			}
		}
	}
	return danger;
}

void BS::opw3_unknown726840(const Area &area, bool reveal)
{
	if (reveal)
	{
		visited674.fill(true);
		for (int x = area.x1; x <= area.x2; x++)
		{
			for (int y = area.y1; y <= area.y2; y++)
				cells7c4(x,y).opw3_unknown6c1cd0(opw3_cells(x,y),false,false);
		}
		if (opw3_flag_cefb3e)
		{
			for (int x = area.x1; x <= area.x2; x++)
			{
				for (int y = area.y1; y <= area.y2; y++)
					opw3_noop4f0a50(opw3_cells(x,y),true);
			}
		}
	}
	else
	{
		for (int x = area.x1; x <= area.x2; x++)
		{
			for (int y = area.y1; y <= area.y2; y++)
			{
				if (opw3_cells(x,y)->getTerrain() != TERRAIN_EARTH && opw3_cells(x,y)->getTerrain() != opw3_terrain_cefb84 &&
					cells7c4(x,y).unknown10 == opw3_caf164 && cells7c4(x,y).unknown24 == opw3_caf15c)
					opw3_unknown7243c0(x,y,true);
			}
		}
		if (opw3_flag_cefb3e)
		{
			for (int x = area.x1; x <= area.x2; x++)
			{
				for (int y = area.y1; y <= area.y2; y++)
				{
					if (opw3_cells(x,y)->getTerrain() != TERRAIN_EARTH && opw3_cells(x,y)->getTerrain() != opw3_terrain_cefb84)
						opw3_noop4f0a50(opw3_cells(x,y),false);
				}
			}
		}
	}
}

bool BS::opw3_unknown726d60()
{
	if (flag1d8)
		return false;
	flag1d8 = true;
	if (opw3_gameState->type != 34 || !stringToInt(opw3_gameData.opw3_unknown46f6d0("comPlayerSurrendered_g")))
		opw3_obj_d2c658.opw3_unknown4729d0(606,1,"",-1);
	do
	{
		opw3_unknown5141b0(22,string("Phase Generator"),0,0,HProp(),player->getPosition());
	} while (false);
	for (int x = 0; x < opw3_cells.getWidth(); x++)
	{
		for (int y = 0; y < opw3_cells.getHeight(); y++)
		{
			if (opw3_cells(x,y)->unknown45dc70())
			{
				opw3_cells(x,y)->opw3_unknown66a050(opw3_terrain_cefb9c->ID,2,0);
				opw3_unknown726ff0(Point(x,y));
			}
			else if (originalTerrain(x,y) == opw3_terrain_cefbac->ID)
			{
				originalTerrain(x,y) = opw3_terrain_cefb9c->ID;
				opw3_unknown6c1080(Point(x,y));
			}
		}
	}
	return true;
}

void BS::opw3_unknown727150(const Point &center, int count, int radius, int value)
{
	Area area;
	opw3_cells.getRect(center,radius,area);
	Point pos;
	vector<Point> path;
	for (int i = 0; i < count; i++)
	{
		for (int attempt = 0; attempt < 10; attempt++)
		{
			area.randomPoint_40be30(&pos);
			OpW3_traceLine(center,pos,&path);
			for (unsigned int j = 1; j < path.size(); j++)
			{
				if (!opw3_cells(path[j])->isPassableFor(HEntity()))
					goto retry;
			}
			opw3_cells(pos)->opw3_unknown66b690(opw3_pick9d9c10(opw3_flag_d28d30 ? opw3_table_ba6a28 : opw3_table_ba69e0,17),value);
			break;
		retry:
			path.clear();
		}
	}
}

HEntity BS::opw3_unknown7285b0()
{
	HEntity chosen;
	vector<HEntity> candidates;
	vector<int> chances;
	for (unsigned int i = 0; i < entities594.size(); i++)
	{
		if (entities594[i].operator->() && entities594[i]->getFaction() == 26 && entities594[i]->getGroup()->opw3_unknown9b4350() == 3 &&
			entities594[i]->opw3_getRecord() && !entities594[i]->opw3_getRecord()->opw3_unknown458fb0(player) &&
			opw3_distance(player->getPosition(),entities594[i]->getPosition()) >= 20)
		{
			candidates.push_back(entities594[i]);
			chances.push_back(opw3_distance(player->getPosition(),entities594[i]->getPosition()));
		}
	}
	if (!candidates.empty())
	{
		HEntity robot = candidates[opw3_pickWeighted9d9270(chances)];
		Point destination(-1);
		Area area;
		opw3_cells.getRect(player->getPosition(),5,area);
		for (int attempt = 0; attempt < 50; attempt++)
		{
			Point p = area.randomPoint_40be90();
			if (opw3_unknown71c150(p,p,robot->getSize()) && unknown716940(robot->getPosition(),p,robot.operator->(),NULL))
			{
				destination = p;
				break;
			}
		}
		if (destination.x != -1)
		{
			int index = OpW3_indexOf(entities594,robot);
			points584[index] = destination;
			robot->opw3_getRecord()->opw3_unknown459540(destination);
			return robot;
		}
	}
	return HEntity();
}

bool BS::opw3_unknown728b00(Point p, int &count)
{
	if (opw3_cells(p)->getEntity().isNull())
		return false;
	for (unsigned int i = 0; i < items390.size(); i++)
	{
		if (!items390[i].operator->() || items390[i]->opw3_getType() != 5)
		{
			OpW3_eraseAt(items390,i);
			opw3_eraseIndex9ce6d0(ints3a0,i);
		}
		else if (p.opw3_adjacent(items390[i]->opw3_unknown575920()) && opw3_cells(p)->getEntity()->opw3_unknown5cb680(groups[ints3a0[i]]))
		{
			if (!items390[i]->getEffect(0x56))
			{
				OpW3_eraseAt(items390,i);
				opw3_eraseIndex9ce6d0(ints3a0,i);
			}
			else
			{
				if (items390[i]->getEffect(0x58))
					count++;
				Point pos = items390[i]->opw3_unknown575920();
				do
				{
					if (opw3_unknown5111e0(0xcd,items390[i]->opw3_unknown571db0(false,false),NULL,0,HProp(),HProp(),&pos,0))
						opw3_consoleA->opw3_unknown8758d0(true);
					opw3_consoleB->opw3_unknown7b4f10();
				} while (0);
				int value = items390[i]->opw3_getData()->unknown1a8;
				items390[i]->opw3_unknown57dbe0(0,0,1,1);
				if (!value)
				{
					// NOTE: empty branch; reproduces the original's cmp/jne/jmp
				}
				else
					opw3_unknown777a20(opw3_entityMgr->opw3_unknown7930e0(new OpW3_Obj515ca0(HEntity(),value,pos,HEntity(),Point(-1),Point(-1))));
				OpW3_eraseAt(items390,i);
				opw3_eraseIndex9ce6d0(ints3a0,i);
				return true;
			}
		}
	}
	return false;
}

void BS::opw3_unknown7297a0()
{
	vector<Point> points;
	for (unsigned int i = 0; i < exits.size(); i++)
	{
		if (exits[i]->unknown14.isNull() && exits[i]->unknown18.isNull() && !exits[i]->used)
			points.push_back(exits[i]->pos);
	}
	for (unsigned int j = 0; j < points584.size(); j++)
	{
		if (!entities594[j].operator->() || entities594[j]->getGroup()->opw3_unknown9b4350() != 3)
		{
			opw3_erasePointAt(points584,j);
			OpW3_eraseAt(entities594,j);
			opw3_eraseListAt(items5a4,j);
			j--;
		}
	}
	for (unsigned int k = 0; k < points584.size(); k++)
		opw3_removePoint(points,points584[k]);
	vector<Point> path;
	for (unsigned int m = 0; m < points584.size(); m++)
	{
		if (points.empty())
			break;
		if (!opw3_cells(points584[m])->isMachinePart())
		{
			int best = 0;
			int minDist;
			int dist;
			if (points.size() > 1)
			{
				path.clear();
				for (unsigned int n = 0; n < points.size(); n++)
				{
					dist = opw3_cartographer.findPath(points584[m],points[n],opw3_moveCost,NULL,path);
					if (n == 0 || dist < minDist)
					{
						minDist = dist;
						best = n;
					}
				}
			}
			points584[m] = points[best];
			entities594[m]->opw3_getRecord()->opw3_unknown459540(points584[m]);
			opw3_erasePointAt(points,best);
		}
	}
	Point interval(40,100);
	int turn = getTurn();
	points5bc = points;
	for (unsigned int p = 0; p < points5bc.size(); p++)
	{
		turn += interval.randomInRange_40c130();
		times5cc.push_back(turn);
	}
	unknown5b4 = -1;
}

void BS::opw3_unknown72f2e0()
{
	counter9a4++;
	opw3_obj_d2c658.opw3_unknown4729d0(603,counter9a4,"",-1);
	if (counter9a4 >= 10)
		opw3_obj_cf45d8.opw3_unknown77fbc0(7);
}

void BS::opw3_unknown72f350()
{
	counter9a8++;
	opw3_obj_d2c658.opw3_unknown4729d0(352,counter9a8,"",-1);
	if (counter9a8 >= 50)
	{
		if (opw3_gameState->type == 34)
			opw3_unknown747860(true,false);
		if (counter9a8 >= 100)
			opw3_obj_cf45d8.opw3_unknown77fbc0(346);
	}
}

void BS::opw3_unknown72f3f0()
{
	counter9ac++;
	opw3_obj_d2c658.opw3_unknown4729d0(354,counter9ac,"",-1);
	if (counter9ac >= 5)
		opw3_obj_cf45d8.opw3_unknown77fbc0(37);
}

void BS::opw3_unknown72f460()
{
	counter9b0++;
	opw3_obj_d2c658.opw3_unknown4729d0(355,counter9b0,"",-1);
	counter9b4++;
	if (counter9b4 == 2)
		opw3_obj_cf45d8.opw3_unknown77fbc0(52);
}

void BS::opw3_unknown72f4e0(HEntity e)
{
	if (OpW3_inVector(entities9bc,e))
	{
		counter9b8++;
		opw3_obj_d2c658.opw3_unknown4729d0(353,counter9b8,"",-1);
		if (counter9b8 == 2)
			opw3_obj_cf45d8.opw3_unknown77fbc0(143);
	}
}

void BS::opw3_unknown72f570()
{
	counter9f0++;
	if (counter9f0 == 15)
		opw3_obj_cf45d8.opw3_unknown77fbc0(281);
}

void BS::opw3_unknown72f5b0(HEntity e)
{
	if (!opw3_obj_cf45d8.opw3_unknown46de40(194))
		return;
	if (OpW3_addUnique(entities9f4,e) && entities9f4.size() == 6)
		opw3_obj_cf45d8.opw3_unknown77fbc0(194);
}

void BS::opw3_unknown72f620()
{
	if (unknown320 == unknownA04)
	{
		counterA08++;
		if (counterA08 == 3)
			opw3_obj_cf45d8.opw3_unknown77fbc0(195);
	}
}

void BS::opw3_unknown72f670()
{
	counterA10++;
	if (counterA10 == 20)
		opw3_obj_cf45d8.opw3_unknown77fbc0(321);
}

void BS::opw3_unknown72ed70(bool alert)
{
	vector<Point> points;
	for (int x = 0; x < opw3_cells.getWidth(); x++)
	{
		for (int y = 0; y < opw3_cells.getHeight(); y++)
		{
			if (opw3_cells(x,y)->getProp().isValid() && opw3_cells(x,y)->getProp()->opw3_getName45c590().find("_Door_Hackable") != string::npos &&
				opw3_cells(x,y)->getProp()->opw3_getUnknownGetter() == 0)
				points.push_back(Point(x,y));
		}
	}
	if (!points.empty())
	{
		int effect;
		int value;
		opw3_lookupID("P_Machine_Door_Open",effect);
		Point start = player->getPosition();
		Point closest(-1);
		int bestValue = -1;
		for (unsigned int i = 0; i < points.size(); i++)
		{
			opw3_cells(points[i])->getProp()->opw3_unknown45ce10(true,0,true,HProp());
			if (effect && isVisible(points[i]))
				opw3_effectMgr->create()->init(opw3_effectMgr,effect,points[i],opw3_effectOrigin,0,0,0,9,0);
			if (opw3_list_d2e9a0[126] && bestValue < 100)
			{
				value = opw3_unknown500500(opw3_list_d2e9a0[126],points[i],start);
				if (closest.x == -1 || value > bestValue)
				{
					bestValue = value;
					closest = points[i];
				}
			}
		}
		if (closest.x != -1)
			opw3_unknown454260(&closest,126);
	}
	if (!points.empty())
	{
		int count = rng.rangeInt(2,3);
		while (count)
		{
			opw3_overmind.opw3_spawnPatrolParty(HProp(),0,0,0,0,0,0,10,0);
			count--;
		}
		if (alert)
		{
			do
			{
				opw3_messageLog.opw3_unknown451400(1);
				if (1 && !(opw3_flag_d28fb0 && 1 && 1))
					opw3_playSound(295,0,0);
				do
				{
					if (opw3_unknown5111e0(804,string("ALERT: Power surge detected, dispatching additional patrols."),NULL,0,HProp(),HProp(),NULL,0))
						opw3_consoleA->opw3_unknown8758d0(true);
					opw3_consoleB->opw3_unknown7b4f10();
				} while (0);
				opw3_consoleB->opw3_unknown7b4f10();
			} while (0);
			do
			{
				opw3_unknown5141b0(22,string("Energy Cycler"),0,0,HProp(),player->getPosition());
			} while (0);
		}
	}
}

HEntity BS::opw3_unknown727ef0()
{
	HEntity chosen;
	vector<HEntity> candidates;
	for (unsigned int i = 0; i < entities594.size(); i++)
	{
		if (entities594[i].operator->())
		{
			Point pos = entities594[i]->getPosition();
			if (marks740(pos).value == markValue && entities594[i]->getFaction() == 26 && entities594[i]->getGroup()->opw3_unknown9b4350() == 3 &&
				entities594[i]->opw3_getRecord() && !entities594[i]->opw3_getRecord()->opw3_unknown458fb0(player))
				candidates.push_back(entities594[i]);
		}
	}
	opw3_shuffle9d9fc0(candidates);
	for (unsigned int j = 0; j < candidates.size(); j++)
	{
		vector<Point> corners;
		vector<int> distances;
		corners.push_back(Point(0,0));
		corners.push_back(Point(opw3_cells.opw3_getSize().x,0));
		corners.push_back(Point(0,opw3_cells.opw3_getSize().y));
		corners.push_back(Point(opw3_cells.opw3_getSize().x,opw3_cells.opw3_getSize().y));
		for (unsigned int k = 0; k < corners.size(); k++)
			distances.push_back(opw3_distance(player->getPosition(),corners[k]) - opw3_distance(candidates[j]->getPosition(),corners[k]));
		Point target = corners[opw3_maxIndex9d4500(distances)];
		Point dest(-1);
		Area bounds;
		opw3_cells.getRect(target,30,bounds);
		for (int attempt = 0; attempt < 20; attempt++)
		{
			Point p = bounds.randomPoint_40be90();
			if (opw3_cells(p)->isPassableFor(candidates[j]) && unknown716940(candidates[j]->getPosition(),p,candidates[j].operator->(),NULL))
			{
				vector<Point> path;
				if (unknown7168e0(candidates[j]->getPosition(),p,candidates[j].operator->(),path))
				{
					int dist = opw3_distance(candidates[j]->getPosition(),player->getPosition());
					int minDist = opw3_maxInt(1,dist - 5);
					bool ok = true;
					for (unsigned int s = 5; s < path.size(); s += 5)
					{
						if (opw3_distance(path[s],player->getPosition()) < minDist)
						{
							ok = false;
							break;
						}
					}
					if (ok)
						dest = p;
				}
				break;
			}
		}
		if (dest.x != -1)
		{
			int index = OpW3_indexOf(entities594,candidates[j]);
			points584[index] = dest;
			candidates[j]->opw3_getRecord()->opw3_unknown459540(dest);
			return candidates[j];
		}
	}
	return HEntity();
}

bool BS::opw3_unknown72c080(vector<OpW3_Conduit *> &list, bool silent, HEntity e)
{
	bool result = false;
	if (!list.empty())
	{
		Array2D<bool> *seen = opw3_world->unknown4637f0();
		for (unsigned int i = 0; i < list.size(); i++)
		{
			OpW3_Conduit *conduit = list[i];
			vector<string> names;
			opw3_unknown72bbe0(conduit->indices,names);
			if (!silent && conduit->opw3_getProp()->unknown45cb10() && opw3_world->opw3_unknown726c30(conduit->opw3_getProp(),false))
				result = true;
			for (unsigned int j = 0; j < conduit->targets.size(); j++)
			{
				if (opw3_conduits[conduit->targets[j]]->opw3_unknown6c1320())
				{
					opw3_unknown72bbe0(opw3_conduits[conduit->targets[j]]->indices,names);
					if (!silent && opw3_conduits[conduit->targets[j]]->opw3_getProp()->unknown45cb10() && opw3_world->opw3_unknown726c30(opw3_conduits[conduit->targets[j]]->opw3_getProp(),false))
						result = true;
					opw3_unknown72bdc0(conduit,j);
					vector<Point> *points = &opw3_mapConsole->opw3_unknown49aec0()->points;
					for (unsigned int k = 0; k < points->size(); k++)
					{
						if ((*seen)((*points)[k]) && opw3_cells((*points)[k])->unknown66b120())
							opw3_eraseAt9d7300(*points,k);
					}
				}
			}
			if (!silent && !names.empty())
			{
				HItemP item = e->opw3_unknown5d2380(26);
				do
				{
					if (opw3_unknown5111e0(468,item->opw3_unknown571db0(false,false),NULL,0,HProp(),HProp(),NULL,0))
						opw3_consoleA->opw3_unknown8758d0(true);
					opw3_consoleB->opw3_unknown7b4f10();
				} while (0);
				vector<string> lines;
				opw3_unknown9de280(lines,names);
				for (unsigned int m = 0; m < lines.size(); m++)
				{
					lines[m] += " x" + intToString(opw3_count9de310(names,lines[m]));
					lines[m].insert(lines[m].begin(),2,' ');
				}
				opw3_sort9de3c0(lines.begin(),lines.end());
				for (unsigned int n = 0; n < lines.size(); n++)
				{
					do
					{
						if (opw3_unknown5111e0(469,lines[n],NULL,0,HProp(),HProp(),NULL,0))
							opw3_consoleA->opw3_unknown8758d0(true);
						opw3_consoleB->opw3_unknown7b4f10();
					} while (0);
				}
				opw3_counter_cf4d20 += names.size();
				if (opw3_counter_cf4d20 >= 20)
					opw3_obj_cf45d8.opw3_unknown77fbc0(167);
			}
		}
	}
	return result;
}

void BS::opw3_unknown725930(HEntity e, bool reset)
{
	if (reset)
	{
		OpW3_erase(entities6ec,e);
		OpW3_erase(entities6fc,e);
	}
	if (OpW3_addUnique(entities6ec,e))
	{
		opw3_entityMgr->opw3_unknown793450(60,1,0,0,0);
		if (e->getFaction() == 28 && opw3_gameState->type == 13)
			opw3_obj_cf45d8.opw3_unknown77fbc0(29);
		if (e->getFaction() == 33)
			opw3_obj_cf45d8.opw3_unknown77fbc0(408);
		if (e->opw3_getData()->unknown48 != 122 && opw3_flags_b95758[e->opw3_getData()->unknown48] && !e->opw3_unknown45ac40(35) &&
			(e->getFaction() != 61 || e->opw3_getInventoryList()->size() >= 8))
		{
			e->opw3_unknown639530(35,true);
			do
			{
				opw3_unknown5141b0(10,e->opw3_getNameRef(),0,0,HProp(),NULL);
			} while (0);
		}
		else if (e->opw3_getData()->unknown110 != 10 && !e->opw3_unknown45ac40(35))
		{
			e->opw3_unknown639530(35,true);
			do
			{
				opw3_unknown5141b0(10,e->opw3_getNameRef(),0,0,HProp(),NULL);
			} while (0);
		}
		opw3_unknown72a0b0(e);
		if (player->opw3_getInventory())
			opw3_unknown4569a0(76,player,e,HProp(),HProp(),0,0,player->opw3_getInventory(),player,HProp(),HProp(),0);
		if (opw3_obj_cf68b4)
		{
			if (opw3_obj_cf68b4 && e.operator->() && opw3_entity_cf68b8 == e)
				opw3_obj_cf68f0->opw3_unknown672f20(e,0,0,"");
			if (opw3_count_cf68c8 > 1)
			{
				if (opw3_obj_cf68b4 && e.operator->() && opw3_entity_cf68b8 == e)
					opw3_obj_cf68f0->opw3_unknown672f20(e,1,0,"");
				else
				{
					switch (opw3_obj_cf68b4->type)
					{
					case 6:
						if (opw3_value_cf6a18)
						{
							if (opw3_obj_cf68b4 && e.operator->() && opw3_entity_cf68b8 == e)
								opw3_obj_cf68f0->opw3_unknown672f20(e,17,0,"");
							opw3_value_cf6a18 = -opw3_value_cf6a18;
						}
						break;
					}
				}
			}
		}
	}
	if (e->opw3_getRecord()->unknown9b4350() >= 2 && e->getFaction() != 8 && e->getFaction() != 19 && (!e->opw3_unknown5d5250() || e->getFaction() == 6) && OpW3_addUnique(entities6fc,e))
	{
		opw3_unknown726af0(e.ID);
		if (e->opw3_getName45a280().size() == 2 && e->opw3_getName45a280()[0] == 'A' && stringToInt(opw3_gameData.opw3_unknown46f6d0("datDataConduitDownloaded_g")) && unknown463e50())
		{
			string name = "DESTROY_" + e->opw3_getName45a280();
			int index = opw3_find9cda80(opw3_names_d1d0f8,28,name);
			if (index != -1 && opw3_flags_d1e950[index] == 0)
			{
				opw3_flags_d1e950[index] = 1;
				opw3_unknown6c65a0(player,"DAT_" + e->opw3_getName45a280() + "_Hack",0);
				name = "Found relevant data record, DESTROY_" + e->opw3_getName45a280() + ": " + opw3_names_d1e930[index];
				do
				{
					if (opw3_unknown5111e0(801,name,NULL,0,HProp(),HProp(),NULL,0))
						opw3_consoleA->opw3_unknown8758d0(true);
					opw3_consoleB->opw3_unknown7b4f10();
				} while (0);
			}
		}
	}
	if ((opw3_flag_d28d2c != 0 || opw3_flag_d28f8c != 0) && e->opw3_unknown45afb0() + 10 <= getTurn() &&
		(!opw3_flag_d28d28 || (e->opw3_getRecord()->unknown9b4350() >= 2 && (!e->opw3_unknown5d5250() || e->getFaction() == 6))))
		opw3_mapConsole->opw3_unknown49adf0(e);
	e->opw3_setTurn(getTurn());
}

void BS::opw3_unknown72f6b0()
{
	if (stringToInt(opw3_gameData.opw3_unknown46f6d0("scrAttackedLocals_g")))
		return;
	opw3_gameData.opw3_unknown46f700("scrAttackedLocals_g",intToString(getTurn()));
	do
	{
		opw3_unknown5141b0(241,(const string *)NULL,0,0,HProp(),NULL);
	} while (0);
	if (opw3_obj_d25450.enabled)
		opw3_obj_d25450.opw3_unknown69e700(91,player->opw3_unknown5c98c0(0,66,0) ? 1 : 0,0.0f);
	for (int x = opw3_area_d1eaf8.x1; x <= opw3_area_d1eb00; x++)
	{
		for (int y = opw3_area_d1eafc; y <= opw3_area_d1eb04; y++)
		{
			if (opw3_cells(x,y)->getProp().isValid())
			{
				opw3_cells(x,y)->getProp()->opw3_unknown665be0(true);
				if (!opw3_cells(x,y)->getProp()->opw3_getObj() || !opw3_cells(x,y)->getProp()->opw3_getObj()->opw3_unknown456540())
					OpW3_erase(props4f0,opw3_cells(x,y)->getProp());
				if (!opw3_cells(x,y)->getProp()->opw3_getObj() && opw3_cells(x,y)->getProp()->opw3_getList45c7e0()->empty() &&
					opw3_cells(x,y)->getProp()->opw3_getUnknownH() == opw3_value_cefbd0)
					opw3_cells(x,y)->getProp()->opw3_unknown45ce10(false,0,true,HProp());
			}
			if (opw3_cells(x,y)->getEntity().isValid() && !opw3_cells(x,y)->getEntity()->isPlayer())
			{
				removeEntity(opw3_cells(x,y)->getEntity());
				opw3_cells(x,y)->getEntity()->unknown639730(true);
			}
		}
	}
	for (unsigned int i = 0; i < exits.size(); i++)
	{
		if (exits[i]->destination->type == 11)
		{
			OpW3_Exit *exit = exits[i];
			opw3_cells(exit->pos)->opw3_unknown66a050(opw3_terrain_cefb9c->ID,2,1);
			if (exit->known)
			{
				do
				{
					if (opw3_unknown5111e0(436,string("Scraptown"),NULL,0,HProp(),HProp(),&exit->pos,0))
						opw3_consoleA->opw3_unknown8758d0(true);
					opw3_consoleB->opw3_unknown7b4f10();
				} while (0);
			}
			Point location = exit->pos;
			opw3_eraseExitAt(exits,i);
			int type;
			if (opw3_lookup9d7710(&opw3_vec_cf35b0,"Collapsed Tunnel",type) && opw3_cells(location)->getProp().isNull())
			{
				if (opw3_cells(location)->opw3_unknown45df50(opw3_entityMgr->opw3_unknown793360(type)))
					opw3_cells(location)->getProp()->opw3_unknown45cc50(location);
			}
			HEntity robot = opw3_unknown6c5dc0("Scrapper_3",location,10,0,34,14,0);
			if (robot.isValid())
			{
				robot->opw3_getRecord()->opw3_unknown459470(opw3_area_d1eaf8);
				opw3_unknown6c65a0(robot,"REC_Scraplab_Reinforce",0);
			}
			break;
		}
	}
	for (int t = 0; t <= 2; t++)
		opw3_unknown465950(t,10,0);
	vector<HEntity> *members = groups[10]->opw3_getMembers();
	for (int k = members->size() - 1; k >= 0; k--)
		(*members)[k]->opw3_getRecord()->opw3_unknown459470(opw3_area_d1eaf8);
}

void BS::opw3_unknown72ffe0(bool quiet)
{
	if (stringToInt(opw3_gameData.opw3_unknown46f6d0("scrAttackedLocals_g")) || opw3_flag_d1eb10)
		return;
	opw3_gameData.opw3_unknown46f700("scrAttackedLocals_g",intToString(getTurn()));
	do
	{
		opw3_messageLog.opw3_unknown451400(1);
		if (1 && !(opw3_flag_d28fb0 && 0 && 1))
			opw3_playSound(137,0,0);
		do
		{
			if (opw3_unknown5111e0(804,string("ANNOUNCEMENT: Intruder alert! Defend Scraptown!"),NULL,0,HProp(),HProp(),NULL,0))
				opw3_consoleA->opw3_unknown8758d0(true);
			opw3_consoleB->opw3_unknown7b4f10();
		} while (0);
		opw3_consoleB->opw3_unknown7b4f10();
	} while (0);
	do
	{
		opw3_unknown5141b0(257,(const string *)NULL,0,0,HProp(),NULL);
	} while (0);
	if (opw3_obj_d25450.enabled && !quiet)
		opw3_obj_d25450.opw3_unknown69e700(92,0,0.0f);
	for (int x = 0; x < opw3_cells.getWidth(); x++)
	{
		for (int y = 0; y < opw3_cells.getHeight(); y++)
		{
			if (opw3_cells(x,y)->getProp().isValid() && !opw3_cells(x,y)->getProp()->opw3_unknown45c800(135))
			{
				if (opw3_cells(x,y)->getProp()->opw3_unknown665be0(true))
					OpW3_erase(props4f0,opw3_cells(x,y)->getProp());
				if (!opw3_cells(x,y)->getProp()->opw3_getObj() && opw3_cells(x,y)->getProp()->opw3_getUnknownH() == opw3_value_cefbd0)
					opw3_cells(x,y)->getProp()->opw3_unknown45ce10(false,0,true,HProp());
			}
			if (opw3_cells(x,y)->getEntity().isValid() && !opw3_cells(x,y)->getEntity()->isPlayer() && !opw3_cells(x,y)->getEntity()->unknown45acb0(135))
			{
				removeEntity(opw3_cells(x,y)->getEntity());
				opw3_cells(x,y)->getEntity()->unknown639730(true);
			}
		}
	}
	for (int t = 0; t <= 2; t++)
		opw3_unknown465950(t,10,0);
	opw3_entityMgr->opw3_unknown793690();
	opw3_unknown789ac0();
	vector<HEntity> *members = groups[10]->opw3_getMembers();
	if (!members->empty())
	{
		OpW3_Talk *talk;
		if (opw3_lookup9d7de0(&opw3_vec_d2c408,"SCR_Hostile_Combat_Talk",talk))
		{
			for (int i = 0; i < 5; i++)
			{
				for (int attempt = 0; attempt < 50; attempt++)
				{
					int index = opw3_randomIndex9d9b20(members);
					if (((*members)[index]->getFaction() == 41 || (*members)[index]->getFaction() == 42 || (*members)[index]->getFaction() == 44) &&
						!(*members)[index]->unknown45adb0(*(int *)talk))
					{
						(*members)[index]->unknown6395d0(talk,0);
						break;
					}
				}
			}
		}
	}
	int doorIndex = opw3_find9d4660(opw3_list_cfc1a4,48);
	if (doorIndex != -1)
	{
		Area *area = &opw3_areas_d22fa8[doorIndex];
		for (int x = area->x1; x <= area->x2; x++)
		{
			for (int y = area->y1; y <= area->y2; y++)
			{
				if (opw3_cells(x,y)->getProp().isValid() && opw3_cells(x,y)->getProp()->opw3_getName45c590() == "SCR_Reading_Room_Door")
				{
					opw3_cells(x,y)->getProp()->opw3_unknown45ce10(true,0,true,HProp());
					break;
				}
			}
		}
	}
	Point zoneA(38,3);
	Point zoneB(122,14);
	Area mapBounds = opw3_cells.opw3_unknown9b4400();
	vector<HEntity> robots(*groups[10]->opw3_getMembers());
	for (unsigned int j = 0; j < robots.size(); j++)
	{
		if (!robots[j]->opw3_unknown5d51a0())
		{
			robots[j]->opw3_unknown64ecf0(new OpW3_AI57f6a0(robots[j],25,0));
			robots[j]->opw3_getRecord()->opw3_unknown459540(robots[j]->getPosition().x >= 75 ? zoneB : zoneA);
			opw3_eraseAt9d6440(robots,j);
		}
	}
	HEntity optimus;
	for (unsigned int k = 0; k < robots.size(); k++)
	{
		switch (robots[k]->getFaction())
		{
		case 78:
			optimus = robots[k];
			opw3_unknown6c65a0(optimus,"SCR_Optimus_Hostile",0);
		case 77:
			opw3_eraseAt9d6440(robots,k);
			break;
		}
	}
	OpQ1_Box westPart(38,34,71,63);
	OpQ1_Box eastZone(79,35,116,62);
	for (unsigned int m = 0; m < robots.size(); m++)
	{
		robots[m]->opw3_getRecord()->opw3_unknown459470(reinterpret_cast<const Area &>(robots[m]->getPosition().x < 75 ? westPart : eastZone));
		robots[m]->opw3_getRecord()->opw3_setMode(33);
		if (robots[m]->getPosition().x >= 75)
			robots[m]->opw3_getRecord()->opw3_setFollowEntity(optimus,0);
	}
	opw3_turn_d1eb28 = getTurn() + rng.rangeInt(25,75);
	opw3_turn_d1eb2c = getTurn() + rng.rangeInt(50,100);
	opw3_turn_d1eb30 = getTurn() + rng.rangeInt(90,110);
	opw3_turn_d1eb34 = getTurn() + rng.rangeInt(160,240);
	opw3_turn_d1eb3c = getTurn() + rng.rangeInt(400,700);
	for (int g = 0; g < 2; g++)
	{
		vector<HEntity> *list = groups[g]->opw3_getMembers();
		for (unsigned int n = 0; n < list->size(); n++)
		{
			if ((*list)[n]->opw3_unknown5d51a0())
				opw3_count_d1eb40++;
		}
	}
}

void BS::opw3_unknown724f00()
{
	Point pos;
	Point topLeft;
	Point maxP;
	OpW3_Region *curRegion;
	int tagVal;
	int depth;
	vector<HEntity> *members = groups[0]->opw3_getMembers();
	for (unsigned int i = 0; i < members->size(); i++)
	{
		if (!(*members)[i]->getTarget())
		{
			int percent = 1;
			if (opw3_flag_cf4744 == 0)
				percent += (*members)[i]->opw3_unknown5d2090(25) + (*members)[i]->unknown45acb0(44);
			if (!percent)
				continue;
			curRegion = regions[i];
			Array2D<int> *map = &curRegion->map;
			map->opw3_unknown9cedd0(curRegion);
			tagVal = curRegion->id;
			pos = curRegion->center;
			depth = curRegion->radius;
			if (depth)
			{
				opw3_cells.getBounds(pos,depth,topLeft,maxP);
				for (int x = topLeft.x; x <= maxP.x; x++)
				{
					for (int y = topLeft.y; y <= maxP.y; y++)
					{
						if ((*map)(x,y) == tagVal && opw3_cells(x,y)->opw3_unknown45ddf0() && rng.chance(percent))
						{
							opw3_cells(x,y)->getProp()->opw3_unknown65f170();
							opw3_unknown724420(x,y);
							if (opw3_cells(x,y)->getProp()->opw3_getHackData()->opw3_unknown65cf50(0))
							{
								opw3_consoleF4->opw3_unknown7b1880(new OpW3_Obj510d20(59,0,0,0,HProp(),HProp()));
								opw3_mapConsole->opw3_unknown49ad30();
							}
							opw3_mapConsole->opw3_unknown813050(true,opw3_cells(x,y)->getProp(),0,0,0);
							opw3_unknown9e29b0(props720,opw3_cells(x,y)->getProp());
						}
					}
				}
			}
		}
	}

	if (unknown320 % 2 == 0)
	{
		vector<HEntity> robots(1,player);
		for (unsigned int j = 0; j < groups[1]->opw3_getMembers()->size(); j++)
		{
			if ((*groups[1]->opw3_getMembers())[j]->getFaction() == 48)
				robots.push_back((*groups[1]->opw3_getMembers())[j]);
		}
		for (unsigned int k = 0; k < robots.size(); k++)
		{
			HEntity robot = robots[k];
			vector<Point> footprint(*robot->opw3_getFootprint());
			robot->opw3_unknown5c89d0(footprint);
			vector<Point> traps;
			for (unsigned int m = 0; m < footprint.size(); m++)
			{
				if (opw3_cells(footprint[m])->unknown45dcf0() && !opw3_cells(footprint[m])->getProp()->opw3_getHackData()->opw3_unknown65cf80() &&
					opw3_cells(footprint[m])->getProp()->opw3_unknown45cbd0() && opw3_cells(footprint[m])->getProp()->opw3_getHackData()->opw3_unknown65cf50(robot->getGroup()->opw3_unknown9b4350()))
					traps.push_back(footprint[m]);
			}
			if (!traps.empty())
			{
				opw3_shufflePoints9d7350(traps);
				vector<HItemP> items;
				robot->opw3_unknown5d2430(25,items);
				for (unsigned int n = 0; n < items.size(); n++)
				{
					if (rng.chance(items[n]->opw3_unknown457fd0()))
					{
						do
						{
							if (opw3_unknown5111e0(robot->isPlayer() ? 529 : (robot->unknown45aaa0(opw3_world->getPlayer()) ? 530 : 531),items[n]->opw3_unknown571db0(false,false),
								&opw3_cells(traps.front())->getProp()->opw3_getName(),0,robot,HProp(),&traps.front(),0))
								opw3_consoleA->opw3_unknown8758d0(true);
							opw3_consoleB->opw3_unknown7b4f10();
						} while (0);
						opw3_cells(traps.front())->opw3_removeProp(false,4);
						if (opw3_world->isVisible(traps.front()))
						{
							int effect;
							if (opw3_lookupID("Trap_Scan_Disable",effect))
								opw3_effectMgr->create()->init(opw3_effectMgr,effect,traps.front(),opw3_effectOrigin,0,0,0,9,0);
						}
						opw3_erasePointAt(traps,0);
						if (traps.empty())
							break;
					}
				}
			}
		}
	}
}

class OpW3_Obj510f80	// NOTE: placeholder name
{
public:
	OpW3_Obj510f80(int id, int a, int b, int c, HProp d, HProp e);	// NOTE: placeholder name (0x510f80)
	char pad[0x28];
};
bool opw3_unknown5111e0(int id, const string *a, const string *b, int c, HEntity d, HProp e, const Point *f, int g);	// NOTE: placeholder name (same function, other overload)
class OpW3_Obj_cefb48	// NOTE: placeholder name
{
public:
	void opw3_unknown49e250(int a, int b, string text);	// NOTE: placeholder name
};
extern OpW3_Obj_cefb48 *opw3_obj_cefb48;	// NOTE: placeholder name
extern OpW3_TerrainRecord *caveinEarthTerrain;	// 0xcefb80
extern int opw3_mode_d28d48;	// NOTE: placeholder name
extern bool opw3_flag_cefb0a;	// NOTE: placeholder name
extern bool opw3_flag_d1eacc;	// NOTE: placeholder name
extern bool opw3_flag_d28d09;	// NOTE: placeholder name
extern vector<int> opw3_list_cf4a04;	// NOTE: placeholder name
extern vector<int> opw3_list_d22590;	// NOTE: placeholder name
void opw3_pushUnique9d3020(vector<Point> &v, Point p);	// NOTE: placeholder name
void opw3_append9d7f20(vector<Point> &v, vector<Point> &add);	// NOTE: placeholder name

void BS::opw3_unknown72c700(int index, bool flag)
{
	if (flag)
		opw3_unknown72bad0(index);

	opw3_flag_cefc9e = opw3_mode_d28d48 == 2;
	opw3_grid_cefca0 = &grid69c;
	OpW3_Region *visRegion = regions[index];
	visRegion->id++;
	if (visRegion->id > 100000)
		visRegion->id = 1;

	HEntity entity = index >= groups[0]->opw3_getMembers()->size() ?
		(index - groups[0]->opw3_getMembers()->size() >= entities6b8.size() ? entities6c8[index - groups[0]->opw3_getMembers()->size() - entities6b8.size()] :
		entities6b8[index - groups[0]->opw3_getMembers()->size()]) : (*groups[0]->opw3_getMembers())[index];
	if (entity->getTarget())
		return;

	visRegion->center = entity->unknown45a4c0();
	visRegion->radius = entity->opw3_unknown5c7d30();

	HEntity helper;
	if (opw3_possessed != NULL && opw3_contains9db330(&opw3_robotData[opw3_possessed->index]->tags,11))
		helper = player;
	else
	{
		vector<HEntity> *members = groups[1]->opw3_getMembers();
		for (unsigned int i = 0; i < members->size(); i++)
		{
			if ((*members)[i]->getFaction() == 9 && !(*members)[i]->getTarget() && opw3_distance(visRegion->center,(*members)[i]->unknown45a4c0()) <= 20)
			{
				helper = (*members)[i];
				break;
			}
		}
	}

	bool netAccess = !opw3_conduits.empty() && entity->opw3_unknown5d2380(26).isValid();
	int range2 = entity->opw3_unknown5d22a0(24);
	if (range2)
	{
		if (!flag1d8 && (opw3_gameState->type != 34 || !stringToInt(opw3_gameData.opw3_unknown46f6d0("comPlayerSurrendered_g"))))
			range2 = 0;
		else if (opw3_gameState->type == 22 && !stringToInt(opw3_gameData.opw3_unknown46f6d0("zhiCloakGeneratorsDisabled_g")))
			range2 = 0;
	}
	bool mapAll = index == 0 && opw3_list_cf4a04[14] != 0;
	bool revealEverything = index == 0 && opw3_flag_cf4a00;
	opw3_flag_cefc9f = entity->opw3_unknown5d2380(13).isValid();

	Point topLeft;
	Point maxP;
	Array2D<int> *map = &visRegion->map;
	int scanTag = visRegion->id;
	Point origPos = visRegion->center;
	int scanDepth = visRegion->radius;
	HProp prop;
	(*map)(origPos) = scanTag;
	if (scanDepth)
	{
		bool refresh = false;
		vector<Point> border;
		vector<Point> adj;
		vector<OpW3_Conduit *> linkedConduits;
		opw3_cells.getBounds(origPos,scanDepth,topLeft,maxP);
		for (int x = topLeft.x; x <= maxP.x; x++)
		{
			for (int y = topLeft.y; y <= maxP.y; y++)
				visRegion->opw3_unknown72b290(scanDepth,origPos.x,origPos.y,x,y);
		}

		if (opw3_flag_cefb0a)
			grid69c.fill(1);
		else
		{
			int earth = caveinEarthTerrain->ID;
			for (int x = topLeft.x; x <= maxP.x; x++)
			{
				for (int y = topLeft.y; y <= maxP.y; y++)
				{
					if ((*map)(x,y) == scanTag)
					{
						if (!seen680(x,y) && originalTerrain(x,y) != earth)
							seen680(x,y) = true;
						visited674(x,y) = true;
						grid69c(x,y)++;
						grid690(x,y)++;
						if (opw3_cells(x,y)->isEdge() &&
							((opw3_cells(x,y)->isShortcut() && (range2 || helper.isValid() || mapAll || revealEverything || opw3_cells(x,y)->unknown45db90())) ||
							(opw3_cells(x,y)->unknown45dc70() && (helper.isValid() || mapAll || revealEverything || opw3_cells(x,y)->unknown45db90()))) &&
							!OpW3_contains(points7d0,Point(x,y)) && unknown320)
						{
							unknown734d60(Point(x,y));
							if ((range2 && opw3_cells(x,y)->isShortcut()) || helper.isValid() || mapAll || revealEverything)
							{
								opw3_mapConsole->opw3_unknown80e3a0(true,Point(x,y));
								if (revealEverything)
								{
									do
									{
										if (opw3_messageLog.opw3_push(new OpW3_Obj510f80(opw3_cells(x,y)->unknown45dc70() ? 303 : 302,0,0,0,HProp(),HProp())))
											opw3_consoleA->opw3_unknown8758d0(true);
										opw3_consoleB->opw3_unknown7b4f10();
									} while (0);
								}
								else if (mapAll)
								{
									do
									{
										if (opw3_messageLog.opw3_push(new OpW3_Obj510f80(opw3_cells(x,y)->unknown45dc70() ? 675 : 674,0,0,0,HProp(),HProp())))
											opw3_consoleA->opw3_unknown8758d0(true);
										opw3_consoleB->opw3_unknown7b4f10();
									} while (0);
								}
								else if (helper.isValid())
								{
									if (helper == player)
									{
										do
										{
											if (opw3_unknown5111e0(opw3_cells(x,y)->unknown45dc70() ? 789 : 788,NULL,NULL,0,helper,HProp(),NULL,0))
												opw3_consoleA->opw3_unknown8758d0(true);
											opw3_consoleB->opw3_unknown7b4f10();
										} while (0);
									}
									else
									{
										do
										{
											if (opw3_unknown5111e0(opw3_cells(x,y)->unknown45dc70() ? 473 : 472,NULL,NULL,0,helper,HProp(),NULL,0))
												opw3_consoleA->opw3_unknown8758d0(true);
											opw3_consoleB->opw3_unknown7b4f10();
										} while (0);
									}
								}
							}
						}

						if (opw3_cells(x,y)->getProp().isValid())
						{
							prop = opw3_cells(x,y)->getProp();
							if (helper.isValid() && prop->unknown45cc10() && prop->opw3_getHackData()->type == 3 && opw3_flag_cf4744 == 0 && unknown320)
							{
								prop->opw3_unknown65f170();
								if (helper == player)
								{
									do
									{
										if (opw3_unknown5111e0(790,&prop->opw3_getName(),NULL,0,helper,HProp(),NULL,0))
											opw3_consoleA->opw3_unknown8758d0(true);
										opw3_consoleB->opw3_unknown7b4f10();
									} while (0);
								}
								else
								{
									do
									{
										if (opw3_unknown5111e0(474,&prop->opw3_getName(),NULL,0,helper,HProp(),NULL,0))
											opw3_consoleA->opw3_unknown8758d0(true);
										opw3_consoleB->opw3_unknown7b4f10();
									} while (0);
								}
								if (prop->opw3_getHackData()->opw3_unknown65cf50(0))
								{
									opw3_consoleF4->opw3_unknown7b1880(new OpW3_Obj510d20(59,0,0,0,HProp(),HProp()));
									opw3_mapConsole->opw3_unknown49ad30();
								}
								opw3_mapConsole->opw3_unknown813050(true,prop,0,0,0);
								opw3_unknown9e29b0(props720,prop);
							}
							if (netAccess && prop->opw3_unknown65e230())
							{
								linkedConduits.push_back(opw3_conduits[prop->opw3_getIndex457af0()]);
								linkedConduits.back()->active = true;
								if (!linkedConduits.back()->opw3_unknown6c1320())
									linkedConduits.pop_back();
							}
							if (prop->opw3_getData2() && !prop->opw3_getUnknown457b10())
							{
								if (opw3_unknown726c30(prop,false))
									refresh = true;
							}
						}

						if (range2 && !opw3_cells(x,y)->opw3_unknown4550b0())
						{
							adj.clear();
							opw3_cells.opw3_unknown9d24b0(Point(x,y),adj);
							for (unsigned int i = 0; i < adj.size(); i++)
							{
								if ((*map)(adj[i]) != scanTag)
									opw3_pushUnique9d3020(border,adj[i]);
							}
						}
						cells7c4(x,y).opw3_unknown6c1cd0(opw3_cells(x,y),false,false);
					}
				}
			}

			if (range2 && !border.empty())
			{
				if (range2 > 1)
				{
					vector<Point> next;
					for (int r = 1; r < range2; r++)
					{
						for (unsigned int i = 0; i < border.size(); i++)
						{
							adj.clear();
							opw3_cells.opw3_unknown9d24b0(border[i],adj);
							for (unsigned int j = 0; j < adj.size(); j++)
							{
								if ((*map)(adj[j]) != scanTag && !OpW3_contains(border,adj[j]))
									opw3_pushUnique9d3020(next,adj[j]);
							}
						}
						opw3_append9d7f20(border,next);
					}
				}
				for (unsigned int i = 0; i < border.size(); i++)
				{
					Point &p = border[i];
					if (visited674(p))
					{
						if (cells7c4(p).unknown10 == opw3_caf164 && cells7c4(p).unknown24 == opw3_caf15c)
							cells7c4(p).opw3_unknown6c1cd0(opw3_cells(p),true,true);
					}
					else
					{
						cells7c4(p).opw3_unknown6c1cd0(opw3_cells(p),true,true);
						visited674(p) = true;
						if (opw3_cells(p)->isMachinePart())
						{
							MapZone *zone = getZone(p);
							zone->found = true;
							if (opw3_difficulty_cf4718 == 2 && !zone->machine->unknown25)
								opw3_unknown71dd30(zone->machine);
							zone->opw3_unknown6c16d0("FOUND");
							opw3_mapConsole->opw3_unknown80e3a0(true,p);
						}
					}
				}
			}
		}

		for (unsigned int i = 0; i < exits.size(); i++)
		{
			if (exits[i]->unknown14.isNull() && exits[i]->unknown18.isNull() && visited674(exits[i]->pos) && (unknown463e50() == 1 || unknown463e50() == 2))
			{
				if (!exits[i]->known)
				{
					exits[i]->known = true;
					if (opw3_difficulty_cf4718 == 2 && !exits[i]->destination->unknown25)
						opw3_unknown71dd30(exits[i]->destination);
					exits[i]->opw3_unknown6c16d0("FOUND");
					opw3_entityMgr->opw3_unknown793450(59,1,0,0,0);
					opw3_mapConsole->opw3_unknown80e3a0(true,exits[i]->pos);
					if (opw3_gameState->type == 3 && !exits[i]->destination->unknown25 && opw3_obj_cefb48 != NULL)
						opw3_obj_cefb48->opw3_unknown49e250(54,0,"");
				}
				if (!exits[i]->seen && exits[i]->known && isVisible(exits[i]->pos))
					exits[i]->seen = true;
			}
		}

		if (opw3_flag_d1eacc && opw3_gameState->type == 4)
			entity->opw3_unknown5d3830();
		if (entity->opw3_unknown5d2380(12).isValid() || opw3_flag_cefc9f)
			entity->opw3_unknown5d3700();
		if (opw3_unknown72c080(linkedConduits,false,entity))
			refresh = true;
		if (!linkedConduits.empty())
			opw3_playSound(81,0,0);
		if (refresh && opw3_consoleCC != NULL && opw3_consoleCC->isHidden())
			opw3_consoleCC->opw3_unknown7ba190();
	}

	if (index == 0)
	{
		entities6ec.clear();
		entities6fc.clear();
		for (int x = topLeft.x; x <= maxP.x; x++)
		{
			for (int y = topLeft.y; y <= maxP.y; y++)
			{
				if ((*map)(x,y) == scanTag && opw3_cells(x,y)->getEntity().isValid() && opw3_cells(x,y)->getEntity() != player &&
					opw3_cells(x,y)->getEntity()->isHostileTo(player) && opw3_cells(x,y)->getEntity()->getTarget() < 6 &&
					!OpW3_inVector(entities6ec,opw3_cells(x,y)->getEntity()))
				{
					opw3_cells(x,y)->getEntity()->opw3_getRecord()->opw3_unknown5b5f40();
					opw3_unknown725930(opw3_cells(x,y)->getEntity(),false);
				}
			}
		}
		if (opw3_flag_d28d09 && opw3_list_d22590[61] == 0)
		{
			for (int x = topLeft.x; x <= maxP.x; x++)
			{
				for (int y = topLeft.y; y <= maxP.y; y++)
				{
					if ((*map)(x,y) == scanTag && opw3_cells(x,y)->unknown66b120())
					{
						opw3_entityMgr->opw3_unknown793450(61,1,0,0,0);
						goto done;
					}
				}
			}
		}
done:
		flag70c = false;
	}
	opw3_unknown720070(true);
	opw3_unknown720470(true);
	opw3_unknown720870(true);
	opw3_unknown720c90(true);
	opw3_unknown721080(true);
	opw3_unknown7214a0(true);
}

extern const int opw3_table_b9b978[];	// NOTE: placeholder name
extern OpW3_Color *opw3_color_d29784;	// NOTE: placeholder name
extern OpW3_Color *opw3_color_d1db04;	// NOTE: placeholder name
extern OpW3_Color *opw3_color_d37980;	// NOTE: placeholder name
extern OpW3_Color *opw3_color_d2171c;	// NOTE: placeholder name
extern bool opw3_flags_b950e0[];	// NOTE: placeholder name
extern bool opw3_flags_caf1e0[];	// NOTE: placeholder name
extern vector<Point> opw3_points_d35860;	// NOTE: placeholder name
extern vector<Point> opw3_points_d1daec;	// NOTE: placeholder name
extern int opw3_value_d28f94;	// NOTE: placeholder name
extern int opw3_value_d28f90;	// NOTE: placeholder name
extern int opw3_value_d255fc;	// NOTE: placeholder name (field of opw3_obj_d25450)
void opw3_addPoints9d4a60(vector<Point> &v, const vector<Point> &add);	// NOTE: placeholder name
void opw3_copy9d49c0(vector<HEntity> &v, const vector<HEntity> &src);	// NOTE: placeholder name
int opw3_randomIndex9d9230(vector<Point> &v);	// NOTE: placeholder name
void opw3_merge9d80a0(vector<Point> &dst, vector<Point> &src);	// NOTE: placeholder name
bool opw3_isBetween9daf80(int low, int value, int high);	// NOTE: placeholder name

void BS::opw3_unknown721600()
{
	Point myPoss = player->unknown45a4c0();
	flag750 = false;
	flag751 = false;
	if (unknown320 % 2 == 0)
		flag752 = false;
	markValue++;
	if (markValue > 100000)
		markValue = 1;

	if (opw3_gameState->type == 22 && !stringToInt(opw3_gameData.opw3_unknown46f6d0("zhiCloakGeneratorsDisabled_g")))
	{
		opw3_unknown720470(false);
		opw3_unknown720870(false);
		return;
	}

	vector<Point> marked;
	vector<HProp> &sensorPropsAll = unknown463c00(0);
	for (unsigned int i = 0; i < sensorPropsAll.size(); i++)
	{
		Point topLeft;
		Point maxP;
		opw3_cells.getBounds(sensorPropsAll[i]->opw3_getPosition(),opw3_table_b9b978[sensorPropsAll[i]->opw3_getData2()->unknown8],topLeft,maxP);
		for (int x = topLeft.x; x <= maxP.x; x++)
		{
			for (int y = topLeft.y; y <= maxP.y; y++)
			{
				if (grid69c(x,y) == 0 && opw3_cells(x,y)->getEntity().isValid())
					marked.push_back(Point(x,y));
			}
		}
	}
	if (!unknown463c00(5).empty())
	{
		vector<vector<HEntity> *> lists;
		lists.push_back(groups[3]->opw3_getMembers());
		lists.push_back(groups[4]->opw3_getMembers());
		for (unsigned int i = 0; i < lists.size(); i++)
		{
			for (unsigned int j = 0; j < lists[i]->size(); j++)
			{
				if (lists[i]->at(j)->getFaction() == 9 && !lists[i]->at(j)->getTarget())
					opw3_pushUnique9d3020(marked,lists[i]->at(j)->getPosition());
			}
		}
	}
	if (!unknown463c00(11).empty() || (opw3_gameData.opw3_unknown46f4b0(1) && (player->opw3_unknown5d2380(22).isValid() || player->opw3_unknown5d2380(23).isValid())))
	{
		vector<vector<HEntity> *> lists;
		lists.push_back(groups[3]->opw3_getMembers());
		lists.push_back(groups[4]->opw3_getMembers());
		for (unsigned int i = 0; i < lists.size(); i++)
		{
			for (unsigned int j = 0; j < lists[i]->size(); j++)
			{
				if (lists[i]->at(j)->getFaction() == 4 && !lists[i]->at(j)->getTarget())
					opw3_pushUnique9d3020(marked,lists[i]->at(j)->getPosition());
			}
		}
	}
	if (!unknown463c00(12).empty())
	{
		vector<HEntity> *team = groups[4]->opw3_getMembers();
		for (unsigned int i = 0; i < team->size(); i++)
		{
			if ((*team)[i]->getFaction() == 8 && !(*team)[i]->getTarget())
				opw3_pushUnique9d3020(marked,(*team)[i]->getPosition());
		}
	}
	if (!unknown463c00(15).empty())
	{
		vector<HEntity> *team = groups[4]->opw3_getMembers();
		for (unsigned int i = 0; i < team->size(); i++)
		{
			if ((*team)[i]->getFaction() == 5 && !(*team)[i]->getTarget())
				opw3_pushUnique9d3020(marked,(*team)[i]->getPosition());
		}
	}
	if (!unknown463c00(17).empty())
	{
		vector<HEntity> *team = groups[4]->opw3_getMembers();
		for (unsigned int i = 0; i < team->size(); i++)
		{
			if ((*team)[i]->getFaction() == 20 && !(*team)[i]->getTarget())
				opw3_pushUnique9d3020(marked,(*team)[i]->getPosition());
		}
	}
	if (!unknown463c00(24).empty())
	{
		vector<HEntity> *team = groups[3]->opw3_getMembers();
		for (unsigned int i = 0; i < team->size(); i++)
		{
			if ((*team)[i]->getFaction() == 12 && !(*team)[i]->getTarget())
				opw3_pushUnique9d3020(marked,(*team)[i]->getPosition());
		}
	}

	for (unsigned int i = 0; i < entities7b4.size(); i++)
	{
		if (entities7b4[i].operator->() == NULL)
			opw3_eraseAt9d6440(entities7b4,i);
		else if (opw3_distance(myPoss,entities7b4[i]->getPosition()) <= 20)
		{
			if (!entities7b4[i]->opw3_getRecord()->opw3_unknown459090() || !entities7b4[i]->opw3_getRecord()->opw3_unknown4590f0()->opw3_unknown458950(36) ||
				entities7b4[i]->getGroup()->opw3_unknown9b4350() != 3 || entities7b4[i]->getTarget())
				opw3_eraseAt9d6440(entities7b4,i);
			else
			{
				Point center = entities7b4[i]->getPosition();
				marked.push_back(center);
				int range = entities7b4[i]->unknown5c7d80(NULL);
				if (range)
				{
					int rangeSq = range * range;
					Point topLeft;
					Point maxP;
					opw3_cells.getBounds(center,range,topLeft,maxP);
					for (int x = topLeft.x; x <= maxP.x; x++)
					{
						for (int y = topLeft.y; y <= maxP.y; y++)
						{
							if (grid69c(x,y) == 0 && opw3_cells(x,y)->getEntity().isValid() && rangeSq >= opw3_sqr(x - center.x) + opw3_sqr(y - center.y))
								opw3_pushUnique9d3020(marked,Point(x,y));
						}
					}
				}
			}
		}
	}

	int range = player->opw3_unknown5d22a0(28);
	if (range)
	{
		Point pos = player->getPosition();
		for (unsigned int g = 0; g < groups.size(); g++)
		{
			if (player->opw3_unknown5cb680(groups[g]))
			{
				vector<HEntity> *team = groups[g]->opw3_getMembers();
				for (unsigned int j = 0; j < team->size(); j++)
				{
					if ((*team)[j]->opw3_getRecord()->opw3_unknown458fb0(player) && opw3_distance(pos,(*team)[j]->getPosition()) <= range)
						opw3_addPoints9d4a60(marked,*(*team)[j]->opw3_getFootprint());
				}
			}
		}
	}

	vector<Point> scoutPos;
	vector<HEntity> allies;
	vector<HEntity> *team = groups[3]->opw3_getMembers();
	int range2 = 0;
	for (unsigned int i = 0; i < team->size(); i++)
	{
		if ((*team)[i]->opw3_unknown5d2380(13).isValid() && !(*team)[i]->getTarget())
		{
			if (range2 == 0)
				range2 = (*team)[i]->opw3_unknown5d22a0(13);
			if (opw3_distance(player->getPosition(),(*team)[i]->getPosition()) <= range2)
			{
				scoutPos.push_back((*team)[i]->getPosition());
				allies.push_back((*team)[i]);
			}
		}
	}
	if (!entities5dc.empty())
	{
		for (unsigned int i = 0; i < entities5dc.size(); i++)
		{
			if (entities5dc[i].operator->() == NULL || entities5dc[i]->getGroup()->opw3_unknown9b4350() != 3 || entities5dc[i]->getTarget() ||
				opw3_distance(player->getPosition(),entities5dc[i]->getPosition()) > range2 + opw3_value_d28f94)
				opw3_eraseAt9d6440(entities5dc,i);
		}
	}
	if (!allies.empty())
	{
		for (unsigned int i = 0; i < allies.size(); i++)
		{
			if (!OpW3_inVector(entities5dc,allies[i]))
			{
				entities5dc.push_back(allies[i]);
				opw3_mapConsole->opw3_unknown819870(allies[i]->getPosition(),range2);
				if (opw3_value_d28f90)
					opw3_mapConsole->opw3_unknown49adc0(opw3_value_d28f90);
				if (opw3_flag_d28e84 && allies[i]->opw3_getRecord()->opw3_unknown581580() && !opw3_unknown72a050(allies[i]->getPosition()))
					opw3_unknown729eb0(allies[i]->getPosition(),allies[i]->opw3_getName(),2,false);
				opw3_entityMgr->opw3_unknown793450(64,1,0,0,0);
			}
		}
	}

	vector<HEntity> bots;
	opw3_copy9d49c0(bots,*groups[0]->opw3_getMembers());
	if (opw3_obj_d25450.enabled && opw3_value_d255fc)
		goto done;
	{
		for (unsigned int i = 0; i < bots.size(); i++)
		{
			if (!bots[i]->getTarget())
			{
				bool fromOwner;
				int range = bots[i]->unknown5c7d80(&fromOwner);
				if (range)
				{
					bool own = i == 0;
					Point centers = bots[i]->unknown45a4c0();
					int rangeSq = range * range;
					Point topLeft;
					Point maxP;
					opw3_cells.getBounds(centers,range,topLeft,maxP);
					if (!flag1d8 && !fromOwner && (opw3_gameState->type != 34 || !stringToInt(opw3_gameData.opw3_unknown46f6d0("comPlayerSurrendered_g"))))
					{
						if (own)
						{
							for (int x = topLeft.x; x <= maxP.x; x++)
							{
								for (int y = topLeft.y; y <= maxP.y; y++)
								{
									if (grid69c(x,y) == 0 && opw3_cells(x,y)->getEntity().isValid() && rangeSq >= opw3_sqr(x - centers.x) + opw3_sqr(y - centers.y))
									{
										flag751 = true;
										goto done;
									}
								}
							}
						}
					}
					else
					{
						vector<Point> spotss;
						int tier = opw3_maxInt(bots[i]->opw3_unknown5d2380(13).isValid() ? 4 : 0,bots[i]->opw3_unknown5d22a0(12));
						vector<HEntity> visibleTo;
						vector<vector<HEntity> *> groupsListVec;
						groupsListVec.push_back(static_cast<vector<HEntity> *&&>(team));
						groupsListVec.push_back(opw3_world->unknown463890(11)->opw3_getMembers());
						if (!fromOwner)
						{
							for (unsigned int g = 0; g < groupsListVec.size(); g++)
							{
								for (unsigned int j = 0; j < groupsListVec[g]->size(); j++)
								{
									if (groupsListVec[g]->at(j)->getFaction() == 12 && !groupsListVec[g]->at(j)->getTarget() &&
										groupsListVec[g]->at(j)->unknown45acb0(13) * groupsListVec[g]->at(j)->unknown45acb0(13) >= opw3_sqr(groupsListVec[g]->at(j)->getPosition().x - centers.x) + opw3_sqr(groupsListVec[g]->at(j)->getPosition().y - centers.y))
										visibleTo.push_back(groupsListVec[g]->at(j));
								}
							}
						}
						bool hasTargets = !visibleTo.empty();
						if (own)
						{
							flag750 = hasTargets;
							if (opw3_obj_cf45d8.opw3_unknown46de40(115) && tier >= 2 && range >= 15)
								opw3_obj_cf45d8.opw3_unknown77fbc0(115);
						}
						for (int x = topLeft.x; x <= maxP.x; x++)
						{
							for (int y = topLeft.y; y <= maxP.y; y++)
							{
								if (grid69c(x,y) == 0 && opw3_cells(x,y)->getEntity().isValid() && rangeSq >= opw3_sqr(x - centers.x) + opw3_sqr(y - centers.y) &&
									opw3_cells(x,y)->getEntity()->unknown45acb0(16) <= tier && (tier >= 4 || opw3_flags_caf1e0[opw3_cells(x,y)->getEntity()->getTarget()]) &&
									(!hasTargets || OpW3_inVector(visibleTo,opw3_cells(x,y)->getEntity())) && !OpW3_contains(marked,Point(x,y)))
								{
									if (!fromOwner && range2 && opw3_cells(x,y)->getEntity()->getGroup()->opw3_unknown9b4350() == 3)
									{
										for (unsigned int k = 0; k < scoutPos.size(); k++)
										{
											if (opw3_distance(Point(x,y),scoutPos[k]) <= range2)
												goto skip;
										}
									}
									spotss.push_back(Point(x,y));
								}
skip:;
							}
						}
						if (!spotss.empty())
						{
							if (own)
							{
								int jamming = player->unknown5cab90();
								if (jamming && tier <= 1)
								{
									int count = jamming / 10 + 1;
									vector<Point> fakes;
									for (int n = 0; n < count; n++)
									{
										if (!spotss.empty() && rng.chance(33))
											opw3_erasePointAt(spotss,opw3_randomIndex9d9230(spotss));
										else
										{
											int tries = 0;
											Point p;
											do
											{
												p.set(rng.rangeInt(topLeft.x,maxP.x),rng.rangeInt(topLeft.y,maxP.y));
												if (grid69c(p) == 0 && rangeSq >= opw3_sqr(p.x - centers.x) + opw3_sqr(p.y - centers.y) && (!visited674(p) || opw3_cells(p)->opw3_unknown4550b0()))
												{
													fakes.push_back(p);
													break;
												}
											} while (++tries < 10);
										}
									}
									if (!fakes.empty())
										opw3_append9d7f20(spotss,fakes);
								}
							}
							for (unsigned int k = 0; k < spotss.size(); k++)
							{
								marks740(spotss[k]).value = markValue;
								HEntity e = opw3_cells(spotss[k])->getEntity();
								if (e.isValid())
								{
									switch (tier)
									{
									case 0:
										marks740(spotss[k]).type = 0;
										marks740(spotss[k]).color = *opw3_color_d29784;
										break;
									case 1:
										marks740(spotss[k]).type = e->unknown45a340() >= 3 ? 2 : 1;
										marks740(spotss[k]).color = *opw3_color_d1db04;
										break;
									case 2:
										marks740(spotss[k]).type = 3;
										marks740(spotss[k]).color = opw3_flags_b950e0[e->getFaction()] ? *opw3_color_d37980 : *opw3_color_d2171c;
										break;
									case 3:
									case 4:
										marks740(spotss[k]).type = 4;
										marks740(spotss[k]).color = e->opw3_unknown5c7630();
										break;
									}
									marks740(spotss[k]).entity = e;
									marks740(spotss[k]).unknownc = e->unknown45a540(spotss[k]);
									if (tier >= 2)
										opw3_unknown72a0b0(e);
									if (fromOwner && e->getGroup()->opw3_unknown9b4350() == 3 && e->opw3_getData()->unknown88 > 0.0 && !e->opw3_getRecord()->opw3_getIndex457af0() &&
										!e->opw3_getRecord()->opw3_unknown458fb0(player))
										e->opw3_getRecord()->opw3_unknown459320();
								}
								else if (tier == 0)
								{
									marks740(spotss[k]).type = 0;
									marks740(spotss[k]).color = *opw3_color_d29784;
								}
								else
								{
									marks740(spotss[k]).type = rng.chance(80) ? 1 : 2;
									marks740(spotss[k]).color = *opw3_color_d1db04;
								}
							}
						}
					}
				}
			}
		}
	}
done:
	opw3_merge9d80a0(marked,scoutPos);
	for (unsigned int i = 0; i < marked.size(); i++)
	{
		HEntity e = opw3_cells(marked[i])->getEntity();
		marks740(marked[i]).value = markValue;
		marks740(marked[i]).type = 4;
		marks740(marked[i]).entity = e;
		marks740(marked[i]).unknownc = e->unknown45a540(marked[i]);
		marks740(marked[i]).color = e->opw3_unknown5c7630();
	}
	opw3_unknown720070(false);
	opw3_unknown720470(false);
	opw3_unknown720870(false);
	opw3_unknown720c90(false);
	opw3_unknown721080(false);
	opw3_unknown7214a0(false);

	if (unknown320 % 2 == 0)
	{
		opw3_points_d35860.clear();
		opw3_points_d1daec.clear();
		int range = player->opw3_unknown5d22a0(14);
		if (range && (!opw3_obj_d25450.enabled || opw3_value_d255fc == 0))
		{
			for (int g = 1; g < groups.size(); g++)
			{
				vector<Point> *list = opw3_isBetween9daf80(3,g,4) ? &opw3_points_d35860 : &opw3_points_d1daec;
				switch (opw3_gameState->type)
				{
				case 21:
				case 22:
					list = &opw3_points_d1daec;
					break;
				case 34:
					if (g <= 1 && stringToInt(opw3_gameData.opw3_unknown46f6d0("comPlayerSurrendered_g")))
						list = &opw3_points_d35860;
					break;
				}
				vector<HEntity> *gm = groups[g]->opw3_getMembers();
				for (unsigned int j = 0; j < gm->size(); j++)
				{
					if (!unknown4631f0((*gm)[j]) && !(*gm)[j]->getTarget() && opw3_distance(myPoss,(*gm)[j]->unknown45a4c0()) <= range)
						list->push_back((*gm)[j]->unknown45a4c0());
				}
			}
			if ((!opw3_points_d35860.empty() || !opw3_points_d1daec.empty()) && !flag1d8 &&
				(opw3_gameState->type != 34 || !stringToInt(opw3_gameData.opw3_unknown46f6d0("comPlayerSurrendered_g"))))
			{
				flag752 = true;
				opw3_points_d35860.clear();
				opw3_points_d1daec.clear();
			}
		}
	}
}
