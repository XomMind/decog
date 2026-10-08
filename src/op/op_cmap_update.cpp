// op_cmap_update: CMap::update (0x7ffee0) of COGMIND.exe (Beta 17.1). Names are placeholders unless stated.
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

//==================================================================
// engine-side declarations
//==================================================================

struct CmuPos	// NOTE: placeholder name (Pos, under a file-unique type so its nothrow callees stay file-local stubs)
{
	int x;
	int y;

	CmuPos() throw();	// 0x453b40
	CmuPos(int x_, int y_) throw();	// 0x46ca20
	CmuPos(int v) throw();	// 0x409990
	CmuPos(const CmuPos &a, const CmuPos &b) throw();	// 0x4099f0 NOTE: placeholder (sum of two points)
	CmuPos(const CmuPos &pos) throw();	// 0x46ca50
	CmuPos &operator=(const CmuPos &pos) throw();	// 0x46ca50
	void set(int v) throw();	// 0x409ff0 NOTE: placeholder name (sets both coordinates)
	void set(int x_, int y_) throw();	// 0x40a010 NOTE: placeholder name
	void negate() throw();	// 0x40a2d0 NOTE: placeholder name
	CmuPos &operator*=(int f) throw();	// 0x40a300
	CmuPos &operator+=(const CmuPos &pos) throw();	// 0x409a30
	CmuPos operator-(const CmuPos &pos) const throw();	// 0x409b30
	CmuPos operator+(const CmuPos &pos) const throw();	// 0x409b60
	bool operator==(const CmuPos &pos) const throw();	// 0x409b90
	bool operator!=(const CmuPos &pos) const throw();	// 0x409bd0
};
typedef CmuPos Point;

class CmuStepper	// NOTE: placeholder name (Bresenham2DStepper, file-unique so its nothrow spec stays local)
{
public:
	CmuStepper(int x0, int y0, int x1, int y1) throw();	// 0x410030
	virtual ~CmuStepper() throw();	// 0x4101c0
	void next(Point &p) throw();	// 0x4102a0

	char pad04[0x2c - 0x04];
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	CmuPos mouse;
};

class XConsole
{
public:
	virtual ~XConsole();

	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(XEvent *event);
	virtual void inputMouse(int x, int y);	// NOTE: placeholder name
	virtual void update();
	virtual void render();	// NOTE: placeholder name

	bool isHidden();	// 0x4175f0
	int getWidth();	// 0x44b0d0 (folded getter)
	bool inBounds(const CmuPos &pos);	// 0x4173d0
	void setPos(int x, int y);	// 0x417a90
	void setPos(const CmuPos &pos);	// 0x4289e0
	void setHidden(bool hidden_);	// 0x417ba0
	void removeSubconsole(XConsole *console);	// 0x428b20
	CmuPos absToLocal(CmuPos pos);	// 0x428560

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	virtual ~Console();

	virtual bool input(XEvent *event);
	virtual void update();	// 0x429e30
	virtual void render();	// NOTE: placeholder name

	int unknown60;
	void *engine;
	void *title;
};

class CmuPopup : public Console	// NOTE: placeholder name (timed sub-console)
{
public:
	unsigned int expire;	// NOTE: placeholder name (0x6c)
};

class CmuMouse	// NOTE: placeholder name (object at *0xcefa94)
{
public:
	bool isOutsideMargin(bool flag);	// 0x41a780
	CmuPos topLeft();	// 0x40a970 NOTE: placeholder name
	bool getField41a6e0();	// NOTE: placeholder name
	void setCell(int x, int y);	// 0x4322a0
	void setCursorHidden(bool hidden);	// 0x432170
	int getWidth9fcd80();	// NOTE: placeholder name (folded getter)
	int getHeight9b8f00();	// NOTE: placeholder name (folded getter)
};
extern CmuMouse *cmu_mouse_cefa94;	// NOTE: placeholder name

class CmuRex	// NOTE: placeholder name (object at 0xd223f0)
{
public:
	bool isValid404af0();	// NOTE: placeholder name
	bool unknown4188e0();	// NOTE: placeholder name
	bool unknown418920();	// NOTE: placeholder name
	bool unknown418940();	// NOTE: placeholder name
	bool unknown418960();	// NOTE: placeholder name
	int unknown418980();	// NOTE: placeholder name
	int unknown4189a0();	// NOTE: placeholder name
};
extern CmuRex cmu_rex_d223f0;	// NOTE: placeholder name

//==================================================================
// game-side declarations
//==================================================================

class Entity;
class Item;
class Prop;

class CmuHEntity
{
public:
	int ID;
	CmuHEntity() throw();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	void reset();	// 0x9b7270
	bool operator==(CmuHEntity e) const;	// 0x9b78e0
	bool operator!=(CmuHEntity e) const;	// 0x9b6510
	Entity *operator->() const;	// 0x9b6570
};

class CmuHItem
{
public:
	int ID;
	CmuHItem() throw();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	bool isNull() const;	// 0x9b65d0
	void reset();	// 0x9b7270
	bool operator!=(CmuHItem e) const;	// 0x9b6510
	Item *operator->() const;	// 0x9b65b0
};

class CmuHProp
{
public:
	int ID;
	CmuHProp() throw();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	Prop *operator->() const;	// 0x9b64f0
};

class CmuGroup	// NOTE: placeholder name
{
public:
	vector<CmuHEntity> *getMembers();	// 0x416f40
};

class CmuHGroup	// NOTE: placeholder name
{
public:
	int ID;
	CmuGroup *operator->() const;	// 0x9b7250
};

struct CmuEntityType	// NOTE: placeholder layout
{
	char pad00[0x68];
	int unknown68;	// NOTE: placeholder name
};

class CmuAI	// NOTE: placeholder name (EntityAI)
{
public:
	bool unknown458fb0(CmuHEntity e);	// NOTE: placeholder name
	vector<Point> &unknown4549b0();	// NOTE: placeholder name (folded getter)
};

class Entity	// NOTE: partial
{
public:
	CmuEntityType *getType9b4350();	// NOTE: placeholder name (folded getter)
	CmuPos &getPosition();	// 0x45a4a0
	Point unknown5c80f0(const Point &p);	// NOTE: placeholder name
	bool unknown5d6610();	// NOTE: placeholder name
	int unknown5d66f0();	// NOTE: placeholder name
	int unknown5d6890();	// NOTE: placeholder name
	bool unknown5d69a0();	// NOTE: placeholder name
	CmuHItem unknown5d2380(int slot);	// NOTE: placeholder name
	bool unknown45aaa0(CmuHEntity e);	// NOTE: placeholder name
	bool isPlayer();	// 0x5c7600
	bool unknown5c8710(const Point &p);	// NOTE: placeholder name
	int getSize();	// 0x45a360
	bool unknown5c85a0(const Point &p, bool flag);	// NOTE: placeholder name
	void *getTarget();	// 0x45a760
	int unknown5d1390();	// NOTE: placeholder name
	CmuHItem unknown5d5d40();	// NOTE: placeholder name
	CmuAI *getAI();	// 0x45b590
	CmuPos unknown45a4c0();	// NOTE: placeholder name
	bool unknown5cb680(CmuHGroup group);	// NOTE: placeholder name
	int unknown5d2150(int a, int b);	// NOTE: placeholder name
	int unknown5c7d30();	// NOTE: placeholder name
	int unknown5d15a0(int a);	// NOTE: placeholder name
};

class Item	// NOTE: partial
{
public:
	int unknown4580a0();	// NOTE: placeholder name
	int unknown457f90();	// NOTE: placeholder name
	int unknown457fb0();	// NOTE: placeholder name
	bool unknown457cf0();	// NOTE: placeholder name
	int unknown577a90();	// NOTE: placeholder name
};

class Prop	// NOTE: partial
{
public:
	bool unknown45cbd0();	// NOTE: placeholder name
};

class Cell	// NOTE: partial
{
public:
	CmuHEntity getEntity();	// 0x45d250
	CmuHProp getProp();	// 0x45d550
	CmuHItem getItem();	// 0x45d8f0
	bool isMachinePart();	// 0x45dcd0
	bool isPassableFor(CmuHEntity e);	// 0x66ab30
	void unknown45db10();	// NOTE: placeholder name
	void unknown45db30();	// NOTE: placeholder name
};

template <class T>
class CmuArray2D	// NOTE: placeholder name (Array2D)
{
public:
	T &operator()(const Point &p);	// 0x9ced70 / 0x9d2930 / 0x9d2c00
	bool contains(const Point &p) throw();	// 0x9b43b0
};
extern CmuArray2D<Cell *> cmu_cells_cfd44c;	// NOTE: placeholder name

struct CmuMemCell	// NOTE: placeholder name (0x14 bytes)
{
	int unknown0;	// NOTE: placeholder name
	int unknown4;	// NOTE: placeholder name
	CmuHEntity entity;	// NOTE: placeholder name
	char pad0c[0x14 - 0x0c];
};

struct CmuItemMem	// NOTE: placeholder name (0x34 bytes)
{
	char pad00[0x10];
	int unknown10;	// NOTE: placeholder name
};

struct CmuComment	// NOTE: placeholder name
{
	Point pos;
};

class CmuTrackedNew	// NOTE: placeholder name (allocation view of CmuTracked; ctor 0x7344f0)
{
public:
	CmuTrackedNew(CmuHEntity e);

	char pad00[0x34];
};

// Trivial stand-in for the 0x7344f0 constructor: declared without throw() and defined here so that LTCG
// proves it nothrow (the exe keeps the extra `new` result slot but has no EH state for it).
CmuTrackedNew::CmuTrackedNew(CmuHEntity e)
{
}

class CmuTracked	// NOTE: placeholder name (0x34 bytes)
{
public:

	CmuHEntity entity;	// NOTE: placeholder name
	Point pos;	// NOTE: placeholder name
	int turn;	// NOTE: placeholder name
	vector<Point> path;	// NOTE: placeholder name
	vector<XConsole *> marks;	// NOTE: placeholder name
	unsigned int time;	// NOTE: placeholder name
};

class World	// NOTE: placeholder name (the object behind the global at 0xcefc4c)
{
public:
	void unknown774b70();	// NOTE: placeholder name
	bool unknown71bbd0();	// NOTE: placeholder name
	bool unknown71bbb0();	// NOTE: placeholder name
	int unknown716f20(CmuHEntity e, const Point &p);	// NOTE: placeholder name
	bool unknown7170a0(CmuHEntity e, Point &a, vector<Point> &b, vector<int> &c, vector<int> &d, Point &f, Point *g, int h, bool i, bool j);	// NOTE: placeholder name
	bool unknown4633c0(const Point &p);	// NOTE: placeholder name
	bool unknown463160(const Point &p);	// NOTE: placeholder name
	bool isVisible(const Point &p);	// 0x4631c0
	int unknown4636d0();	// NOTE: placeholder name
	int unknown463710();	// NOTE: placeholder name
	bool unknown716740(Entity *e, vector<Point> &path, Point &next);	// NOTE: placeholder name
	bool unknown7168e0(const CmuPos &from, const Point &to, Entity *e, vector<Point> &path);	// NOTE: placeholder name
	CmuArray2D<CmuItemMem> *unknown463e70();	// NOTE: placeholder name
	void unknown735e70(int a);	// NOTE: placeholder name
	void unknown736120(int a);	// NOTE: placeholder name
	bool unknown4631f0(CmuHEntity e);	// NOTE: placeholder name
	int getTurn();	// 0x464270
	bool unknown463f80();	// NOTE: placeholder name
	int *unknown4640c0();	// NOTE: placeholder name
	int *unknown4640e0();	// NOTE: placeholder name
	bool *unknown464100();	// NOTE: placeholder name
	void unknown4652b0(int a, const Point &b, Point &c, vector<Point> &d, vector<XConsole *> &e);	// NOTE: placeholder name

	char pad0[0x4c];
	vector<CmuHGroup> groups;	// NOTE: placeholder name (0x4c)
	char pad5c[0x658 - 0x5c];
	int unknown658;	// NOTE: placeholder name
	char pad65c[0x66c - 0x65c];
	CmuHEntity player;	// NOTE: placeholder name (0x66c)
	char pad670[0x740 - 0x670];
	CmuArray2D<CmuMemCell> unknown740;	// NOTE: placeholder name
	char pad741[0x74c - 0x741];
	int unknown74c;	// NOTE: placeholder name
	char pad750[0x7c4 - 0x750];
	CmuArray2D<CmuItemMem> unknown7c4;	// NOTE: placeholder name
	char pad7c5[0x7f0 - 0x7c5];
	vector<CmuComment *> comments;	// NOTE: placeholder name (0x7f0)
	vector<CmuTracked *> tracked;	// NOTE: placeholder name (0x800)
	Point trackedPos;	// NOTE: placeholder name (0x810)
	int trackedLevel;	// NOTE: placeholder name (0x818)
	vector<CmuHEntity> unknown81c;	// NOTE: placeholder name
	int unknown82c;	// NOTE: placeholder name
};
extern World *cmu_world_cefc4c;	// NOTE: placeholder name

class CmuEngine	// NOTE: placeholder name (0xcefc64)
{
public:
	bool update50fff0();	// NOTE: placeholder name
};
extern CmuEngine *cmu_engine_cefc64;	// NOTE: placeholder name

class CmuScan : public Console	// NOTE: placeholder name (CScan at *0xcec078)
{
public:
	void load(const CmuPos &pos, bool flag);	// 0x884f60
};
extern CmuScan *cmu_scan_cec078;	// NOTE: placeholder name

extern Console *cmu_cec11c;	// NOTE: placeholder name
extern Console *cmu_cec118;	// NOTE: placeholder name
extern Console *cmu_cec0f8;	// NOTE: placeholder name
extern Console *cmu_cec03c;	// NOTE: placeholder name
extern Console *cmu_cec054;	// NOTE: placeholder name

struct CmuMessage	// NOTE: placeholder name (0x20 bytes, ctor 0x510d20)
{
	CmuMessage(int type, string *a, string *b, string *c, CmuHEntity d, CmuHEntity e);

	char pad00[0x20];
};

class CmuInterfaceMsg	// NOTE: placeholder name (CInterfaceMsg at 0xcec0f4)
{
public:
	void add(CmuMessage *message);	// 0x7b1880
};
extern CmuInterfaceMsg *cmu_msgs_cec0f4;	// NOTE: placeholder name

struct CmuPart	// NOTE: placeholder layout
{
	char pad00[0x6c];
	CmuHItem item;	// NOTE: placeholder name
};

class CmuParts	// NOTE: placeholder name (CParts at 0xcec088)
{
public:
	CmuPart *unknown894ee0();	// NOTE: placeholder name
};
extern CmuParts *cmu_parts_cec088;	// NOTE: placeholder name

class CmuSweep	// NOTE: placeholder name (0xcec0a4)
{
public:
	bool getField4ab570();	// NOTE: placeholder name
};
extern CmuSweep *cmu_cec0a4;	// NOTE: placeholder name

class CmuAllies	// NOTE: placeholder name (CAllies at 0xcec0c8)
{
public:
	CmuHEntity unknown48f120();	// NOTE: placeholder name
	vector<CmuHEntity> *unknown48f0e0();	// NOTE: placeholder name
	int unknown48f100();	// NOTE: placeholder name
};
extern CmuAllies *cmu_allies_cec0c8;	// NOTE: placeholder name

class CmuTimerSrc	// NOTE: placeholder name (0xcefa8c)
{
public:
	unsigned int unknown4272a0(int a);	// NOTE: placeholder name
	unsigned int getField48e040();	// NOTE: placeholder name
};
extern CmuTimerSrc *cmu_cefa8c;	// NOTE: placeholder name

class CmuTheme	// NOTE: placeholder name (0xcefaa8)
{
public:
	bool check4705f0();	// NOTE: placeholder name
	bool apply4705b0();	// NOTE: placeholder name
	bool check470630();	// NOTE: placeholder name
	int getField9fcd80();	// NOTE: placeholder name
	void unknown793690();	// NOTE: placeholder name
};
extern CmuTheme *cmu_theme_cefaa8;	// NOTE: placeholder name

class CmuBubble	// NOTE: placeholder name
{
public:
	void bubble8758d0(bool flag);	// NOTE: placeholder name
};
extern CmuBubble *cmu_cec058;	// NOTE: placeholder name

class CmuLog	// NOTE: placeholder name
{
public:
	void scrollToEnd_7b4f10();	// NOTE: placeholder name
};
extern CmuLog *cmu_cec0b4;	// NOTE: placeholder name

class CmuPlayerData	// NOTE: placeholder name (PlayerData at 0xcf45d8)
{
public:
	bool unknown77f260(int a);	// NOTE: placeholder name
	bool isFlagActive46dd50();	// NOTE: placeholder name
	void unknown77fbc0(int a);	// NOTE: placeholder name
	bool isSlotEmpty46de40(int a);	// NOTE: placeholder name
};
extern CmuPlayerData cmu_playerData_cf45d8;	// NOTE: placeholder name

class CmuXom	// NOTE: placeholder name (0xd25450)
{
public:
	bool unknown69e680(int a);	// NOTE: placeholder name
	void unknown69e700(int a, int b, float c);	// NOTE: placeholder name

	bool enabled;	// NOTE: placeholder name
};
extern CmuXom cmu_xom_d25450;	// NOTE: placeholder name

class CmuStats	// NOTE: placeholder name (0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int a);	// NOTE: placeholder name
};
extern CmuStats cmu_stats_d2c658;	// NOTE: placeholder name

class CmuAudioLogs	// NOTE: placeholder name (CAudioLogs)
{
public:
	void unknown7f4f50();	// NOTE: placeholder name
};

class CmuPanel	// NOTE: placeholder name
{
public:
	void update7f5170();	// NOTE: placeholder name
};

class CmuTimer	// NOTE: placeholder name
{
public:
	void unknown499dc0();	// NOTE: placeholder name
};

class CmuMapLabel	// NOTE: placeholder name
{
public:
	void update499ec0();	// NOTE: placeholder name
};

struct CmuStep	// NOTE: placeholder name (0x10 bytes)
{
	Point pos;
	char pad08[0x10 - 0x08];
	~CmuStep();
};

struct CmuE14	// NOTE: placeholder name (0x14 bytes)
{
	char pad00[0x10];
	unsigned int time;	// NOTE: placeholder name
};

struct CmuSaveRecord	// NOTE: placeholder layout (0x70 bytes)
{
	string version;
	string unknown1c;	// NOTE: placeholder name
	string unknown38;	// NOTE: placeholder name
	string unknown54;	// NOTE: placeholder name
};
extern string gameStrings_d29dc8[];

extern unsigned int cmu_tick_caed20;	// NOTE: placeholder name
extern bool cmu_d28c8a;	// NOTE: placeholder name
extern int cmu_d28d20;	// NOTE: placeholder name
extern bool cmu_d28d15;	// NOTE: placeholder name
extern bool cmu_d28e3e;	// NOTE: placeholder name
extern int cmu_d28d34;	// NOTE: placeholder name
extern bool cmu_d28d3b;	// NOTE: placeholder name
extern bool cmu_cec14d;	// NOTE: placeholder name
extern bool cmu_cec14c;	// NOTE: placeholder name
extern bool cmu_cec14e;	// NOTE: placeholder name
extern int cmu_caf164;	// NOTE: placeholder name
extern bool cmu_cefa75;	// NOTE: placeholder name
extern bool cmu_d1d9e4;	// NOTE: placeholder name
extern bool cmu_d1d9e5;	// NOTE: placeholder name
extern unsigned int cmu_d28e28;	// NOTE: placeholder name
extern bool cmu_d28d28;	// NOTE: placeholder name
extern unsigned int cmu_d28e20;	// NOTE: placeholder name
extern bool cmu_d28fa8;	// NOTE: placeholder name
extern bool cmu_d28d31;	// NOTE: placeholder name
extern bool cmu_cefacd;	// NOTE: placeholder name
extern bool cmu_d28e26;	// NOTE: placeholder name
extern int cmu_cec108;	// NOTE: placeholder name
extern bool cmu_d28e25;	// NOTE: placeholder name
extern int cmu_caf128;	// NOTE: placeholder name
extern int cmu_caf12c;	// NOTE: placeholder name
extern int cmu_cec144;	// NOTE: placeholder name
extern bool cmu_d28e4c;	// NOTE: placeholder name
extern bool cmu_d28e4b;	// NOTE: placeholder name
extern bool cmu_d28c88;	// NOTE: placeholder name
extern bool cmu_cefbc7;	// NOTE: placeholder name
extern int cmu_cefc54;	// NOTE: placeholder name
extern unsigned int cmu_d1da80;	// NOTE: placeholder name
extern int cmu_cf4cfc;	// NOTE: placeholder name
extern int cmu_cf4cf8;	// NOTE: placeholder name
extern const bool cmu_b96384[];	// NOTE: placeholder name
extern const int cmu_ba3668[];	// NOTE: placeholder name
extern const int cmu_b96600[];	// NOTE: placeholder name
extern CmuPos cmu_directions_d015d8[];	// NOTE: placeholder name
extern const char empty_b96417[];
extern const char empty_b9641a[];

bool opr1c_hasPtr_cebd5c();	// NOTE: placeholder name
void cmu_insert_9d8fc0(vector<CmuHEntity> &v, unsigned int index, CmuHEntity e);	// NOTE: placeholder name
int teamb_getEntityLabel_7fea30(CmuHEntity e, int a, string *out, int b);	// NOTE: placeholder name
void opr2b_rotatePoint(const Point &origin, const Point &p, float angle, Point &out);	// NOTE: placeholder name
bool cmu_addUnique_9d3020(vector<Point> &v, Point p);	// NOTE: placeholder name
bool cmu_contains_9d0ce0(vector<Point> &v, Point p);	// NOTE: placeholder name
void cmu_line_40ff30(const Point &a, const Point &b, vector<Point> &out);	// NOTE: placeholder name
void cmu_cone_6513f0(const Point &a, const Point &b, vector<Point> &out);	// NOTE: placeholder name
int cmu_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name
void cmu_surrounding_4faaf0(const CmuPos &p, vector<Point> &out);	// NOTE: placeholder name
void cmu_eraseAt_9d5190(vector<Point> &v, int index);	// NOTE: placeholder name
int cmu_direction_4374c0(const CmuPos &a, const CmuPos &b);	// NOTE: placeholder name
void cmu_eraseStep_9e2670(vector<Point> &v, int &index);	// NOTE: placeholder name
void cmu_eraseStep_9e26c0(vector<CmuE14> &v, int &index);	// NOTE: placeholder name
void cmu_removeElement_9de6f0(vector<unsigned int> &v, int index);	// NOTE: placeholder name
void cmu_eraseAt_9ce6d0(vector<unsigned int> &v, unsigned int &index);	// NOTE: placeholder name
void cmu_eraseAt_9ce6d0(vector<CmuPopup *> &v, unsigned int &index);	// NOTE: placeholder name
int opW9_unknown7b9750(int order, CmuHEntity target, const CmuPos &pos);	// NOTE: placeholder name
void cmu_clearObjects_9e2710(vector<CmuTracked *> &v);	// NOTE: placeholder name
void cmu_deleteObjectAndStep_9e2730(vector<CmuTracked *> &v, int &index);	// NOTE: placeholder name
bool cmu_containsEntity_9d31e0(vector<CmuHEntity> &v, CmuHEntity e);	// NOTE: placeholder name
int halfDiff_437190(int a, int b);
void opw8_unknown789ac0();
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name
string intToString(int value);
void logError(string location, string message);
bool opS2_showMessage_5111e0(int id, string *a, string *b, string *c, CmuHEntity subject, CmuHEntity object, const CmuPos *at, bool log);

#define CMU_MESSAGE(text) do { if (opS2_showMessage_5111e0(0x325, text, 0, 0, CmuHEntity(), CmuHEntity(), 0, false)) cmu_cec058->bubble8758d0(true); cmu_cec0b4->scrollToEnd_7b4f10(); } while (0)

//==================================================================
// CMap
//==================================================================

class CMap : public Console	// NOTE: partial layout
{
public:
	virtual void update();

	void centerPush_805020(CmuPos &out);	// NOTE: placeholder name
	void unknown8069e0(Point p, bool flag) throw();	// NOTE: placeholder name
	bool unknown806d00(vector<Point> &points, bool flag);	// NOTE: placeholder name
	bool unknown805190(CmuPos &out);	// NOTE: placeholder name
	void edges8146c0();	// NOTE: placeholder name
	void unknown8142d0(unsigned int a, bool b);	// NOTE: placeholder name
	void event816180(int type, CmuHEntity e, string text, int value);	// NOTE: placeholder name
	void unknown807eb0(bool flag);	// NOTE: placeholder name
	void updatePredictedExplosion();	// 0x808320
	void labelAccess80e3a0(bool flag, const CmuPos &pos);	// NOTE: placeholder name
	void label810270(int a, CmuHEntity e, int b, int c);	// NOTE: placeholder name
	void label813050(int a, CmuHProp p, int b, int c, int d);	// NOTE: placeholder name
	void items8119c0(CmuHItem item, bool a, int b, int c);	// NOTE: placeholder name
	bool unknown8052f0(const CmuPos &pos);	// NOTE: placeholder name
	void labelEntity80fa60(int a, const CmuPos &pos, int b, int c, int d, int e);	// NOTE: placeholder name
	void addMemoryLabel812950(const CmuPos &pos, int a);	// NOTE: placeholder name
	void comment80ed40(int a, CmuComment *comment);	// NOTE: placeholder name
	bool unknown8050a0();	// NOTE: placeholder name
	bool hasActiveLabel(int type);	// 0x49b120
	void unknown806f30(int a);	// NOTE: placeholder name
	void unknown49ad30();	// NOTE: placeholder name
	bool unknown49ab60();	// NOTE: placeholder name
	bool operate49aa00();	// NOTE: placeholder name
	bool test49aa60();	// NOTE: placeholder name
	void unknown808510(Point &p, int range, vector<Point> &out);	// NOTE: placeholder name

	CmuPos scroll;	// 0x6c
	char pad74[0xec - 0x74];
	bool unknownec;	// NOTE: placeholder name
	char paded[0x100 - 0xed];
	vector<Point> unknown100;	// NOTE: placeholder name
	CmuPos unknown110;	// NOTE: placeholder name
	CmuHItem unknown118;	// NOTE: placeholder name
	CmuPos unknown11c;	// NOTE: placeholder name
	char pad124[0x1c4 - 0x124];
	unsigned int unknown1c4;	// NOTE: placeholder name
	vector<CmuTimer *> unknown1c8;	// NOTE: placeholder name
	vector<CmuMapLabel *> unknown1d8;	// NOTE: placeholder name
	CmuPos unknown1e8;	// NOTE: placeholder name
	unsigned int unknown1f0;	// NOTE: placeholder name
	char pad1f4[0x200 - 0x1f4];
	CmuPos unknown200;	// NOTE: placeholder name
	CmuPos unknown208;	// NOTE: placeholder name
	CmuHEntity unknown210;	// NOTE: placeholder name
	char pad214[0x29c - 0x214];
	vector<Point> unknown29c;	// NOTE: placeholder name
	vector<Point> unknown2ac;	// NOTE: placeholder name
	vector<CmuE14> unknown2bc;	// NOTE: placeholder name
	char pad2cc[0x2dc - 0x2cc];
	vector<Point> unknown2dc;	// NOTE: placeholder name
	vector<Point> unknown2ec;	// NOTE: placeholder name
	vector<unsigned int> unknown2fc;	// NOTE: placeholder name
	vector<unsigned int> unknown30c;	// NOTE: placeholder name
	char pad31c[0x36c - 0x31c];
	CmuAudioLogs *audioLogs;	// NOTE: placeholder name
	CmuPanel *panel;	// NOTE: placeholder name
	char pad374[0x384 - 0x374];
	int unknown384;	// NOTE: placeholder name
	unsigned int unknown388;	// NOTE: placeholder name
	char pad38c[0x4c4 - 0x38c];
	bool unknown4c4;	// NOTE: placeholder name
	Point unknown4c8;	// NOTE: placeholder name
	Point unknown4d0;	// NOTE: placeholder name
	bool unknown4d8;	// NOTE: placeholder name
	vector<Point> unknown4dc;	// NOTE: placeholder name
	vector<int> unknown4ec;	// NOTE: placeholder name
	vector<int> unknown4fc;	// NOTE: placeholder name
	vector<CmuStep> unknown50c;	// NOTE: placeholder name
	int unknown51c;	// NOTE: placeholder name
	vector<unsigned int> unknown520;	// NOTE: placeholder name
	vector<Point> unknown530;	// NOTE: placeholder name
	bool unknown540;	// NOTE: placeholder name
	vector<Point> unknown544;	// NOTE: placeholder name
	int unknown554;	// NOTE: placeholder name
	char pad558[0x66c - 0x558];
	vector<CmuHEntity> unknown66c;	// NOTE: placeholder name
	int unknown67c;	// NOTE: placeholder name
	int unknown680;	// NOTE: placeholder name
	int unknown684;	// NOTE: placeholder name
	char pad688[0x6fc - 0x688];
	Point unknown6fc;	// NOTE: placeholder name
	CmuHEntity unknown704;	// NOTE: placeholder name
	vector<vector<Point> > unknown708;	// NOTE: placeholder name
	CmuPos unknown718;	// NOTE: placeholder name
	CmuPos unknown720;	// NOTE: placeholder name
	CmuPos unknown728;	// NOTE: placeholder name
	vector<Point> unknown730;	// NOTE: placeholder name
	vector<unsigned int> unknown740;	// NOTE: placeholder name
	unsigned int unknown750;	// NOTE: placeholder name
	int unknown754;	// NOTE: placeholder name
	CmuPos unknown758;	// NOTE: placeholder name
	int unknown760;	// NOTE: placeholder name
	unsigned int unknown764;	// NOTE: placeholder name
	unsigned int unknown768;	// NOTE: placeholder name
	bool unknown76c;	// NOTE: placeholder name
	int unknown770;	// NOTE: placeholder name
	vector<Point> unknown774;	// NOTE: placeholder name
	Point unknown784;	// NOTE: placeholder name
	Point unknown78c;	// NOTE: placeholder name
	unsigned int unknown794;	// NOTE: placeholder name
	vector<CmuPopup *> unknown798;	// NOTE: placeholder name
	int unknown7a8;	// NOTE: placeholder name
	int unknown7ac;	// NOTE: placeholder name
	vector<CmuPopup *> unknown7b0;	// NOTE: placeholder name
	vector<Point> unknown7c0;	// NOTE: placeholder name
	vector<Point> unknown7d0;	// NOTE: placeholder name
	vector<unsigned int> unknown7e0;	// NOTE: placeholder name
};

// 0x7ffee0
void CMap::update()
{
	if (isHidden())
		return;

	cmu_world_cefc4c->unknown774b70();
	cmu_engine_cefc64->update50fff0();
	CmuHEntity player = cmu_world_cefc4c->player;
	if (player.operator->() == 0)
		return;

	if (!cmu_d28c8a && cmu_d28d20 != 0 && cmu_rex_d223f0.isValid404af0() && !cmu_rex_d223f0.unknown4188e0() && !cmu_world_cefc4c->unknown71bbd0() && !isHidden() && cmu_mouse_cefa94->isOutsideMargin(true) && cmu_rex_d223f0.unknown418920() && cmu_rex_d223f0.unknown418940() && cmu_rex_d223f0.unknown418960())
	{
		int max = 50;
		unsigned int delay = cmu_d28d20;
		if (unknown750 == 0)
			unknown750 = cmu_tick_caed20 + 50;
		else
		{
			CmuPos center;
			centerPush_805020(center);
			CmuPos local = absToLocal(cmu_mouse_cefa94->topLeft());
			CmuPos point(local.x - scroll.x,local.y - scroll.y);
			CmuStepper line(center.x,center.y,point.x,point.y);
			CmuPos cur;
			while (cur != point)
				line.next(cur);
			while (unknown750 + delay <= cmu_tick_caed20)
			{
				Point prev(cur);
				line.next(cur);
				center += cur - prev;
				if (!cmu_cells_cfd44c.contains(center))
				{
					unknown750 = cmu_tick_caed20;
					break;
				}
				unknown8069e0(center,true);
				unknown750 += delay;
			}
		}
	}
	else
		unknown750 = 0;

	if (!unknown66c.empty())
	{
		if ((cmu_d28d15 || opr1c_hasPtr_cebd5c()) && cmu_d28e3e)
		{
			vector<CmuHEntity> list2;
			for (unsigned int i = 0; i < unknown66c.size(); i++)
			{
				if (unknown66c[i].operator->() != 0)
				{
					if (list2.empty() || unknown66c[i]->getType9b4350()->unknown68 <= list2.back()->getType9b4350()->unknown68)
						list2.push_back(unknown66c[i]);
					else
					{
						for (unsigned int j = 0; j < list2.size(); j++)
						{
							if (unknown66c[i]->getType9b4350()->unknown68 > list2[j]->getType9b4350()->unknown68)
							{
								cmu_insert_9d8fc0(list2,j,unknown66c[i]);
								break;
							}
						}
					}
				}
			}
			vector<Point> points;
			for (unsigned int k = 0; k < list2.size(); k++)
				points.push_back(list2[k]->getPosition());
			unknown806d00(points,true);
		}
		unknown66c.clear();
	}

	CmuPos mouse;
	bool onMap = unknown805190(mouse);
	if (!unknown1c8.empty())
	{
		for (int i = unknown1c8.size() - 1; i >= 0; i--)
			unknown1c8[i]->unknown499dc0();
	}
	if (!unknown1d8.empty())
	{
		for (int i = unknown1d8.size() - 1; i >= 0; i--)
			unknown1d8[i]->update499ec0();
	}
	edges8146c0();

	if (unknown1c4 != 0 && cmu_d28d34 != 0 && cmu_tick_caed20 >= unknown1c4)
	{
		unknown1c4 = 0;
		if (unknown680 == 8 && unknown684 == 1 && cmu_cec11c->isHidden())
		{
			unknown8142d0(0x12,false);
			event816180(0xb,CmuHEntity(),empty_b96417,7);
		}
	}

	if (unknown4c4 && onMap)
	{
		Point target = mouse;
		if (target != unknown4c8 || unknown540)
		{
			unknown540 = false;
			Point origin = player->unknown5c80f0(target);
			unknown807eb0(false);
			unknown4c8 = target;
			if (player->unknown5d6610())
			{
				unknown4d8 = cmu_world_cefc4c->unknown7170a0(player,unknown4c8,unknown4dc,unknown4ec,unknown4fc,unknown4d0,unknown50c.empty() ? &origin : &unknown50c.back().pos,cmu_world_cefc4c->unknown716f20(player,unknown4c8),unknown50c.empty(),true);
				if (!unknown50c.empty() && cmu_b96384[cmu_world_cefc4c->unknown716f20(player,unknown50c.back().pos)])
					unknown4d8 = false;
			}
			else
			{
				unknown50c.clear();
				unknown4d8 = cmu_world_cefc4c->unknown7170a0(player,unknown4c8,unknown4dc,unknown4ec,unknown4fc,unknown4d0,0,4,true,true);
				if (!unknown4d8)
				{
					int n = player->unknown5d66f0();
					if (n != 0)
					{
						bool blocked = false;
						for (unsigned int i = 0; i < unknown4dc.size() - 1; i++)
						{
							if (unknown4ec[i] != 0)
							{
								if (n == 0)
									blocked = true;
								else
								{
									reinterpret_cast<vector<int> &>(unknown520).push_back(reinterpret_cast<const int &>(i));	// NOTE: exe calls the folded vector<int> push_back (0x9b9d30); vector<unsigned> is pinned to 0x9b80b0
									if (n != -1)
										n--;
								}
							}
						}
						if (n != 0 && unknown4ec.back() != 0)
							unknown520.push_back(unknown4ec.size() - 1);
						if (!blocked)
							unknown4d8 = true;
					}
				}
				if (unknown4d8)
				{
					int spread = player->unknown5d6890();
					if (spread != 0)
					{
						vector<Point> edges;
						int multiplier;
						switch (cmu_distanceCeil_40a3f0(origin,unknown4c8))
						{
						case 1:
							multiplier = 20;
							break;
						case 2:
							multiplier = 10;
							break;
						case 3:
							multiplier = 7;
							break;
						default:
							multiplier = 5;
						}
						CmuPos vec(unknown4c8.x - origin.x,unknown4c8.y - origin.y);
						vec *= multiplier;
						CmuPos end(origin,vec);
						CmuPos point;
						for (float angle = (float)(-spread / 2); angle <= spread / 2; angle += 0.1)
						{
							int degrees = (int)angle;
							if (degrees < 0)
								degrees += 360;
							opr2b_rotatePoint(origin,end,(float)degrees,point);
							cmu_addUnique_9d3020(edges,point);
						}
						vector<Point> line;
						for (unsigned int i = 0; i < edges.size(); i++)
						{
							line.clear();
							cmu_line_40ff30(origin,edges[i],line);
							for (unsigned int j = 0; j < line.size(); j++)
							{
								if (cmu_cells_cfd44c.contains(line[j]) && cmu_world_cefc4c->unknown4633c0(line[j]))
								{
									if (!cmu_contains_9d0ce0(unknown4dc,line[j]))
										cmu_addUnique_9d3020(unknown530,line[j]);
								}
								else
									break;
							}
						}
					}
					if (player->unknown5d69a0())
					{
						vector<Point> area;
						cmu_cone_6513f0(origin,unknown4c8,area);
						for (unsigned int i = 0; i < unknown4dc.size(); i++)
						{
							for (unsigned int j = 0; j < area.size(); j++)
							{
								Point p = unknown4dc[i] + area[j];
								if (cmu_cells_cfd44c.contains(p) && cmu_world_cefc4c->unknown4633c0(p) && !cmu_contains_9d0ce0(unknown4dc,p))
									cmu_addUnique_9d3020(unknown530,p);
							}
						}
					}
				}
			}
			updatePredictedExplosion();
		}
	}

	if (cmu_scan_cec078 != 0 && !cmu_scan_cec078->isHidden() && onMap && cmu_cec118->isHidden() && cmu_cec11c->isHidden() && cmu_cec0f8->isHidden() && cmu_cec03c->isHidden())
		cmu_scan_cec078->load(mouse,false);

	if (mouse != unknown208)
	{
		if (onMap && cmu_cells_cfd44c(mouse)->getEntity().isValid() && cmu_cells_cfd44c(mouse)->getEntity() == unknown210)
			unknown208 = unknown200 = mouse;
		else
		{
			unknown208.x = -1;
			unknown210.reset();
		}
	}

	if (cmu_cec11c->isHidden() && cmu_cec118->isHidden() && cmu_cec0f8->isHidden() && !cmu_world_cefc4c->unknown71bbb0() && !unknownec && ((cmu_d28d3b && !cmu_d28c8a && unknown680 != 8) || (cmu_d28c8a && unknown680 == 8 && !unknown4c4) || (cmu_cec14d && cmu_cec14c)))
	{
		if (!onMap || (unknown200.x != -1 && mouse != unknown200))
		{
			if (onMap)
				unknown8142d0(0x12,false);
			unknown200.x = -1;
		}
		else
		{
			if (mouse != unknown208 && unknown1d8.empty())
			{
				if (cmu_world_cefc4c->unknown463160(mouse))
				{
					if (cmu_cells_cfd44c(mouse)->isMachinePart())
					{
						labelAccess80e3a0(true,mouse);
						unknown200 = mouse;
					}
					if (cmu_world_cefc4c->isVisible(mouse))
					{
						if (cmu_cells_cfd44c(mouse)->getEntity().isValid() && !cmu_cells_cfd44c(mouse)->getEntity()->isPlayer())
						{
							label810270(0,cmu_cells_cfd44c(mouse)->getEntity(),0,0);
							unknown200 = mouse;
						}
						if (cmu_cells_cfd44c(mouse)->getProp().isValid() && cmu_cells_cfd44c(mouse)->getProp()->unknown45cbd0())
						{
							label813050(1,cmu_cells_cfd44c(mouse)->getProp(),0,0,1);
							unknown200 = mouse;
						}
						if (cmu_cells_cfd44c(mouse)->getItem().isValid())
						{
							items8119c0(cmu_cells_cfd44c(mouse)->getItem(),0,0,1);
							unknown200 = mouse;
						}
					}
					else
					{
						int labelType = 6;
						if (cmu_world_cefc4c->unknown740(mouse).unknown4 >= 4 && cmu_world_cefc4c->unknown740(mouse).unknown0 == cmu_world_cefc4c->unknown74c && cmu_world_cefc4c->unknown740(mouse).entity.operator->() != 0)
						{
							CmuHEntity target = cmu_world_cefc4c->unknown740(mouse).entity;
							string name;
							int w = (teamb_getEntityLabel_7fea30(target,1,&name,1) + 5) / 2;
							labelType = !unknown8052f0(CmuPos(mouse.x + w,mouse.y));
							labelEntity80fa60(1,mouse,4,labelType,1,0);
							unknown200 = unknown208 = mouse;
							unknown210 = target;
						}
						if (cmu_world_cefc4c->unknown7c4(mouse).unknown10 != cmu_caf164)
						{
							addMemoryLabel812950(mouse,labelType);
							unknown200 = unknown208 = mouse;
							unknown210.reset();
						}
					}
				}
				else
				{
					if (cmu_world_cefc4c->unknown740(mouse).unknown4 >= 4 && cmu_world_cefc4c->unknown740(mouse).unknown0 == cmu_world_cefc4c->unknown74c && cmu_world_cefc4c->unknown740(mouse).entity.operator->() != 0)
					{
						CmuHEntity target = cmu_world_cefc4c->unknown740(mouse).entity;
						string name;
						int w = (teamb_getEntityLabel_7fea30(target,1,&name,1) + 5) / 2;
						labelEntity80fa60(1,mouse,4,!unknown8052f0(CmuPos(mouse.x + w,mouse.y)),1,0);
						unknown200 = unknown208 = mouse;
						unknown210 = target;
					}
				}
			}
			if (unknown200.x == -1 && !cmu_world_cefc4c->comments.empty() && (unknown680 != 8 || unknown684 != 3))
			{
				for (unsigned int i = 0; i < cmu_world_cefc4c->comments.size(); i++)
				{
					if (cmu_world_cefc4c->comments[i]->pos == mouse)
					{
						comment80ed40(1,cmu_world_cefc4c->comments[i]);
						unknown200 = unknown208 = mouse;
						unknown210.reset();
						break;
					}
				}
			}
		}
	}
	else if (unknown200.x != -1)
	{
		unknown200.x = -1;
		unknown8142d0(0x12,false);
	}

	if ((unknown1e8.x == -1 || unknown1e8 != scroll) && !unknown8050a0())
	{
		unknown1e8 = scroll;
		if (hasActiveLabel(4))
		{
			label810270(0,CmuHEntity(),0,1);
			label813050(1,CmuHProp(),0,1,0);
		}
		else if (hasActiveLabel(5))
		{
			label810270(2,CmuHEntity(),0,1);
			label813050(0,CmuHProp(),0,1,0);
		}
		else if (hasActiveLabel(6))
			items8119c0(CmuHItem(),cmu_tick_caed20 <= unknown1f0 + 5000,1,0);
		else if (hasActiveLabel(0x10))
			cmu_world_cefc4c->unknown735e70(0);
		else if (hasActiveLabel(0x11))
			cmu_world_cefc4c->unknown736120(0);
	}

	if (!cmu_cefa75)
		cmu_d1d9e4 = false;
	else if (cmu_cefa8c->unknown4272a0(1) >= cmu_d28e28 && !cmu_d28c8a && !cmu_d1d9e5 && cmu_d1d9e4)
		unknown806f30(0);

	if (unknown760 != 8 && cmu_world_cefc4c->unknown658 == 1 && cmu_tick_caed20 >= unknown764)
	{
		if (cmu_world_cefc4c->unknown4636d0() && !cmu_d28d28)
		{
			cmu_msgs_cec0f4->add(new CmuMessage(0x3a,0,0,0,CmuHEntity(),CmuHEntity()));
			unknown49ad30();
		}
		if (cmu_world_cefc4c->unknown463710() && cmu_d28d28)
		{
			cmu_msgs_cec0f4->add(new CmuMessage(0x3b,0,0,0,CmuHEntity(),CmuHEntity()));
			unknown49ad30();
		}
		else if (player->unknown5d2380(0xc1).isValid() || player->unknown5d2380(0xd8).isValid())
		{
			cmu_msgs_cec0f4->add(new CmuMessage(0x3c,0,0,0,CmuHEntity(),CmuHEntity()));
			unknown49ad30();
		}
		else
		{
			unknown76c = true;
			input(&XEvent(unknown760 + 100));
			unknown770++;
			unknown764 = cmu_tick_caed20 + cmu_d28e20;
			unknown768 = cmu_tick_caed20;
		}
	}
	else if (!unknown774.empty() && cmu_world_cefc4c->unknown658 == 1 && cmu_tick_caed20 >= unknown764)
	{
		if (cmu_world_cefc4c->unknown4636d0() && !cmu_d28d28)
		{
			cmu_msgs_cec0f4->add(new CmuMessage(0x3a,0,0,0,CmuHEntity(),CmuHEntity()));
			unknown49ad30();
		}
		else if (cmu_world_cefc4c->unknown463710() && cmu_d28d28)
		{
			cmu_msgs_cec0f4->add(new CmuMessage(0x3b,0,0,0,CmuHEntity(),CmuHEntity()));
			unknown49ad30();
		}
		else if (player->unknown5d2380(0xc1).isValid() || player->unknown5d2380(0xd8).isValid())
		{
			cmu_msgs_cec0f4->add(new CmuMessage(0x3c,0,0,0,CmuHEntity(),CmuHEntity()));
			unknown49ad30();
		}
		else
		{
			if (player->getPosition() == unknown784 && !cmu_world_cefc4c->unknown716740(player.operator->(),unknown774,unknown784))
				unknown784 = unknown774.front();
			int dir;
			for (dir = 0; dir < 8; dir++)
			{
				if (CmuPos(player->getPosition(),cmu_directions_d015d8[dir]) == unknown774.front())
				{
					if (!cmu_d28fa8 && cmu_cells_cfd44c(unknown774.front())->getEntity().isValid() && !player->unknown45aaa0(cmu_cells_cfd44c(unknown774.front())->getEntity()) && !cmu_playerData_cf45d8.unknown77f260(100))
					{
						unsigned int max = unknown774.size();
						vector<Point> path;
						vector<Point> cells;
						vector<Point> adjacent;
						cmu_surrounding_4faaf0(player->getPosition(),adjacent);
						for (unsigned int i = 0; i < adjacent.size(); i++)
						{
							if (cmu_cells_cfd44c(adjacent[i])->getEntity().isValid() && !player->unknown45aaa0(cmu_cells_cfd44c(adjacent[i])->getEntity()) && !cmu_playerData_cf45d8.unknown77f260(100))
							{
								cells.push_back(adjacent[i]);
								cmu_cells_cfd44c(adjacent[i])->unknown45db10();
							}
						}
						if (cmu_world_cefc4c->unknown7168e0(player->getPosition(),unknown774.back(),player.operator->(),path))
						{
							cmu_eraseAt_9d5190(path,0);
							if (path.size() < max + 2)
							{
								unknown774 = path;
								if (unknown774.size() > 1)
									unknown784 = unknown774[1];
							}
						}
						for (unsigned int k = 0; k < cells.size(); k++)
							cmu_cells_cfd44c(cells[k])->unknown45db30();
						for (int d = 0; d < 8; d++)
						{
							if (CmuPos(player->getPosition(),cmu_directions_d015d8[d]) == unknown774.front())
							{
								dir = d;
								break;
							}
						}
					}
					cmu_eraseAt_9d5190(unknown774,0);
					unknown76c = true;
					input(&XEvent(dir + 100));
					unknown770++;
					goto moved_;
				}
			}
			unknown49ad30();
moved_:
			unknown764 = cmu_tick_caed20 + cmu_d28e20;
			unknown768 = cmu_tick_caed20;
		}
	}

	CmuPart *part = cmu_parts_cec088->unknown894ee0();
	if (part != 0 && part->item.isValid() && !cmu_cec0a4->getField4ab570() && (part->item->unknown4580a0() != 0 || cmu_ba3668[part->item->unknown457f90()] != 0))
	{
		if (unknown118 != part->item || unknown110 != player->getPosition() || unknown11c != scroll)
		{
			unknown100.clear();
			unknown110 = player->getPosition();
			unknown11c = scroll;
			Point origin = unknown110 + scroll;
			int range = part->item->unknown4580a0();
			if (range == 0)
				range = cmu_ba3668[part->item->unknown457f90()] == -1 ? part->item->unknown457fb0() : cmu_ba3668[part->item->unknown457f90()];
			if (range <= 100)
				unknown808510(origin,range,unknown100);
		}
	}
	else
	{
		unknown100.clear();
		unknown110.set(-1);
		unknown118.reset();
		unknown11c.set(-1);
	}

	if (cmu_cec0a4->getField4ab570() && (!onMap || cmu_d28c8a))
	{
		CmuPos center;
		centerPush_805020(center);
		if ((*cmu_world_cefc4c->unknown463e70())(center).unknown10 != cmu_caf164 && center != player->getPosition())
		{
			if (unknown544.empty() || unknown544.front() != player->getPosition() || unknown544.back() != center)
				cmu_world_cefc4c->unknown7168e0(player->getPosition(),center,player.operator->(),unknown544);
		}
		else
			unknown544.clear();
	}
	else if (cmu_mouse_cefa94->getField41a6e0() && cmu_d28c8a && cmu_cec14e && cmu_cec14d)
	{
		if (unknown78c.x != -1 && unknown78c != player->getPosition())
		{
			if (unknown544.empty() || unknown544.front() != player->getPosition() || unknown544.back() != unknown78c)
				cmu_world_cefc4c->unknown7168e0(player->getPosition(),unknown78c,player.operator->(),unknown544);
		}
		else if (onMap && operate49aa00() && cmu_cells_cfd44c(mouse)->isPassableFor(player))
		{
			if (unknown544.empty() || unknown544.front() != player->getPosition() || unknown544.back() != mouse)
				cmu_world_cefc4c->unknown7168e0(player->getPosition(),mouse,player.operator->(),unknown544);
		}
		else
			unknown544.clear();
	}
	else if (onMap && !operate49aa00() && !cmu_mouse_cefa94->getField41a6e0() && player->getPosition() != mouse && cmu_world_cefc4c->unknown658 == 1 && unknown774.empty())
	{
		if ((cmu_world_cefc4c->unknown4636d0() && !cmu_d28d28) || (cmu_world_cefc4c->unknown463710() && cmu_d28d28) || player->unknown5d2380(0xc1).isValid() || player->unknown5d2380(0xd8).isValid())
		{
			unknown544.clear();
			int dir = cmu_direction_4374c0(player->getPosition(),mouse);
			Point pos(player->getPosition(),cmu_directions_d015d8[dir]);
			if (!player->unknown5c8710(pos))
			{
				unknown544.push_back(pos);
				if (player->getSize() == 1 && player->unknown5c85a0(pos,false) && !cmu_cells_cfd44c(pos)->getEntity()->getTarget() && !player->unknown45aaa0(cmu_cells_cfd44c(pos)->getEntity()) && player->unknown5d1390() != 4 && player->unknown5d5d40().isNull() && !cmu_playerData_cf45d8.unknown77f260(100))
					unknown554 = 2;
				else
					unknown554 = 1;
			}
		}
		else if ((cmu_d28d31 || (cmu_cec14e && cmu_cec14d)) && cmu_cells_cfd44c(mouse)->isPassableFor(player))
		{
			unknown554 = 0;
			if ((cmu_cefacd || cmu_playerData_cf45d8.isFlagActive46dd50()) && cmu_cells_cfd44c(mouse)->getEntity().isValid() && cmu_cells_cfd44c(mouse)->getEntity()->getAI())
				unknown544 = cmu_cells_cfd44c(mouse)->getEntity()->getAI()->unknown4549b0();
			else if (unknown544.empty() || unknown544.front() != player->getPosition() || unknown544.back() != mouse)
				cmu_world_cefc4c->unknown7168e0(player->getPosition(),mouse,player.operator->(),unknown544);
		}
		else
			unknown544.clear();
	}
	else
		unknown544.clear();

	if (test49aa60())
	{
		CmuHEntity target = cmu_allies_cec0c8->unknown48f120();
		if ((onMap && mouse != unknown6fc) || target != unknown704)
		{
			if (target.isValid())
			{
				unknown6fc = target->getPosition();
				unknown704 = target;
			}
			else
				unknown6fc = mouse;
			if (unknown6fc.x != -1)
			{
				unknown708.clear();
				vector<CmuHEntity> *members = cmu_allies_cec0c8->unknown48f0e0();
				int order = cmu_allies_cec0c8->unknown48f100();
				if (cmu_b96600[order] != 2 || cmu_world_cefc4c->isVisible(unknown6fc))
				{
					if (!opW9_unknown7b9750(order,members->size() == 1 ? members->front() : CmuHEntity(),unknown6fc))
					{
						for (unsigned int i = 0; i < members->size(); i++)
						{
							unknown708.push_back(vector<Point>());
							cmu_line_40ff30((*members)[i]->unknown45a4c0(),unknown6fc,unknown708.back());
						}
					}
				}
			}
		}
	}
	else
	{
		unknown6fc.x = -1;
		unknown704.reset();
	}

	for (int i = 0; i < unknown29c.size(); i++)
	{
		if (cmu_tick_caed20 > unknown29c[i].y + 200)
			cmu_eraseStep_9e2670(unknown29c,i);
	}
	for (int i = 0; i < unknown2ac.size(); i++)
	{
		if (cmu_tick_caed20 > unknown2ac[i].y + 200)
			cmu_eraseStep_9e2670(unknown2ac,i);
	}
	for (int i = 0; i < unknown2bc.size(); i++)
	{
		if (cmu_tick_caed20 > unknown2bc[i].time + 200)
			cmu_eraseStep_9e26c0(unknown2bc,i);
	}
	for (int i = 0; i < unknown2dc.size(); i++)
	{
		if (cmu_tick_caed20 > unknown2dc[i].y + 300)
			cmu_eraseStep_9e2670(unknown2dc,i);
	}
	for (unsigned int i = 0; i < unknown2ec.size(); i++)
	{
		if (cmu_tick_caed20 > unknown30c[i] + 200)
		{
			cmu_eraseAt_9d5190(unknown2ec,i);
			cmu_removeElement_9de6f0(unknown2fc,i);
			cmu_eraseAt_9ce6d0(unknown30c,i);
		}
	}

	if (!unknown730.empty())
	{
		while (!unknown730.empty() && cmu_tick_caed20 >= unknown740.front())
		{
			unknown8069e0(unknown730.front(),true);
			cmu_eraseAt_9d5190(unknown730,0);
			cmu_removeElement_9de6f0(unknown740,0);
		}
	}
	else if (!cmu_d28e26)
	{
		if (cmu_cec14c)
		{
			if (!cmu_d28c8a && cmu_cec108 == 0 && cmu_cec0f8->isHidden())
			{
				CmuPos mouse = cmu_mouse_cefa94->topLeft();
				if (unknown718.x == -1)
				{
					unknown718 = mouse;
					unknown720 = mouse;
					unknown728.set(0);
				}
				else
				{
					CmuPos delta = mouse - unknown718;
					if (cmu_d28e25)
						delta.negate();
					unknown728 += delta;
					CmuPos steps(0);
					if (abs(unknown728.x) >= cmu_caf128)
					{
						steps.x = abs(unknown728.x) / cmu_caf128;
						if (unknown728.x < 0)
							steps.x *= -1;
						unknown728.x -= steps.x * cmu_caf128;
					}
					if (abs(unknown728.y) >= cmu_caf12c)
					{
						steps.y = abs(unknown728.y) / cmu_caf12c;
						if (unknown728.y < 0)
							steps.y *= -1;
						unknown728.y -= steps.y * cmu_caf12c;
					}
					if (steps.x != 0 || steps.y != 0)
					{
						CmuPos center;
						centerPush_805020(center);
						CmuPos dest(center,steps);
						if (cmu_cells_cfd44c.contains(dest))
						{
							unknown8069e0(dest,true);
							cmu_mouse_cefa94->setCell(unknown718.x,unknown718.y);
							cmu_mouse_cefa94->setCursorHidden(true);
						}
					}
				}
			}
		}
		else
		{
			unknown718.x = -1;
			if (!cmu_d28c8a && cmu_cec144 == 0)
			{
				bool hide = (cmu_d28e4c && cmu_world_cefc4c->unknown71bbd0() && !unknown49ab60() && cmu_tick_caed20 > unknown794 + cmu_d28e20) || (!cmu_d28e4b && cmu_world_cefc4c->unknown463f80() && cmu_world_cefc4c->unknown71bbd0() && !unknown49ab60() && cmu_tick_caed20 > unknown794 + cmu_d28e20);
				if (cmu_mouse_cefa94->getField41a6e0() != hide)
				{
					if (hide && cmu_d28c88)
						unknown758.set(cmu_mouse_cefa94->getWidth9fcd80(),cmu_mouse_cefa94->getHeight9b8f00());
					cmu_mouse_cefa94->setCursorHidden(hide);
					if (!hide && cmu_d28c88)
					{
						cmu_mouse_cefa94->setCell(unknown758.x,unknown758.y);
						unknown758.set(cmu_rex_d223f0.unknown418980() / 2,cmu_rex_d223f0.unknown4189a0() / 2);
					}
				}
			}
		}
	}

	CmuHItem item = cmu_world_cefc4c->player->unknown5d2380(0x1c);
	if (item.isNull() || !item->unknown457cf0() || item->unknown577a90() < 1)
	{
		cmu_clearObjects_9e2710(cmu_world_cefc4c->tracked);
		cmu_world_cefc4c->unknown81c.clear();
		cmu_world_cefc4c->unknown82c = 0;
	}
	else
	{
		vector<CmuTracked *> &objects = cmu_world_cefc4c->tracked;
		bool flag;
		CmuTracked *object;
		Point origin = cmu_world_cefc4c->player->getPosition();
		int level = cmu_world_cefc4c->player->unknown5d2150(0x1e,0);
		if (origin != cmu_world_cefc4c->trackedPos || level != cmu_world_cefc4c->trackedLevel)
			cmu_clearObjects_9e2710(cmu_world_cefc4c->tracked);
		cmu_world_cefc4c->trackedPos = origin;
		cmu_world_cefc4c->trackedLevel = level;
		cmu_world_cefc4c->unknown81c.clear();
		cmu_world_cefc4c->unknown82c = cmu_world_cefc4c->getTurn();
		vector<CmuHEntity> targets;
		for (unsigned int g = 0; g < cmu_world_cefc4c->groups.size(); g++)
		{
			if (cmu_world_cefc4c->player->unknown5cb680(cmu_world_cefc4c->groups[g]))
			{
				vector<CmuHEntity> *members = cmu_world_cefc4c->groups[g]->getMembers();
				for (unsigned int m = 0; m < members->size(); m++)
				{
					if (cmu_world_cefc4c->unknown4631f0((*members)[m]) && !(*members)[m]->getTarget())
					{
						if (!(*members)[m]->getAI()->unknown458fb0(cmu_world_cefc4c->player))
							targets.push_back((*members)[m]);
						cmu_world_cefc4c->unknown81c.push_back((*members)[m]);
					}
				}
			}
		}
		for (int i = 0; i < objects.size(); i++)
		{
			if (!cmu_containsEntity_9d31e0(targets,objects[i]->entity))
				cmu_deleteObjectAndStep_9e2730(objects,i);
		}
		for (unsigned int i = 0; i < targets.size(); i++)
		{
			object = 0;
			for (unsigned int j = 0; j < objects.size(); j++)
			{
				if (objects[j]->entity == targets[i])
				{
					object = objects[j];
					break;
				}
			}
			flag = false;
			if (object == 0)
			{
				object = (CmuTracked *)new CmuTrackedNew(targets[i]);
				objects.push_back(object);
				flag = true;
			}
			else if (object->turn != cmu_world_cefc4c->getTurn() || object->pos != targets[i]->getPosition())
			{
				object->turn = cmu_world_cefc4c->getTurn();
				object->pos = targets[i]->getPosition();
				object->path.clear();
				object->marks.clear();
				flag = true;
			}
			if (flag)
			{
				cmu_world_cefc4c->unknown4652b0(object->entity->unknown5c7d30() - level,object->entity->unknown5c80f0(origin),origin,object->path,object->marks);
				object->time = cmu_tick_caed20;
			}
		}
	}

	if (cmu_tick_caed20 >= unknown388)
	{
		unknown388 += 3000;
		unknown384 = 0;
		int num = 0;
		bool enabled = cmu_xom_d25450.enabled && !cmu_xom_d25450.unknown69e680(0x26) && cmu_world_cefc4c->player->unknown5d15a0(0) <= 120;
		int base = enabled ? cmu_world_cefc4c->player->unknown5d15a0(0) : 0;
		for (unsigned int g = 0; g < cmu_world_cefc4c->groups.size(); g++)
		{
			if (cmu_world_cefc4c->player->unknown5cb680(cmu_world_cefc4c->groups[g]))
			{
				vector<CmuHEntity> *members = cmu_world_cefc4c->groups[g]->getMembers();
				for (unsigned int m = 0; m < members->size(); m++)
				{
					if ((*members)[m]->getAI()->unknown458fb0(cmu_world_cefc4c->player))
					{
						unknown384++;
						if (enabled && (*members)[m]->unknown5d15a0(0) < base)
							num++;
					}
				}
			}
		}
		cmu_stats_d2c658.add4729d0(0x244,unknown384,empty_b9641a,-1);
		if (unknown384 >= 20)
			cmu_playerData_cf45d8.unknown77fbc0(0x45);
		if (cmu_playerData_cf45d8.isSlotEmpty46de40(0x44))
		{
			if (unknown384 >= 10)
				*cmu_world_cefc4c->unknown464100() = true;
			else if (unknown384 == 0 && *cmu_world_cefc4c->unknown464100())
				cmu_playerData_cf45d8.unknown77fbc0(0x44);
		}
		if (unknown384 == 0)
		{
			*cmu_world_cefc4c->unknown4640c0() = 0;
			*cmu_world_cefc4c->unknown4640e0() = 0;
		}
		if (enabled && num >= 10)
			cmu_xom_d25450.unknown69e700(0x26,0,0.0f);
	}

	if (!unknown798.empty())
	{
		for (unsigned int i = 0; i < unknown798.size(); i++)
		{
			if (cmu_tick_caed20 >= unknown798[i]->expire)
			{
				removeSubconsole(unknown798[i]);
				cmu_eraseAt_9ce6d0(unknown798,i);
			}
		}
		bool visible = cmu_tick_caed20 % 1666 <= 1000;
		for (unsigned int i = 0; i < unknown798.size(); i++)
			unknown798[i]->setHidden(!visible);
		if (visible)
		{
			for (unsigned int i = 0, y = 2; i < unknown798.size(); i++, y += 4)
				unknown798[i]->setPos(halfDiff_437190(unknown798[i]->getWidth() / (cmu_d28d15 ? 2 : 1),getWidth()),y);
		}
	}

	bool enabled = cmu_world_cefc4c->player->unknown5d2380(0x1e).isValid();
	if ((enabled && !cmu_cefbc7) || (!enabled && cmu_cefbc7) || (cmu_cefc54 == 6 && cmu_world_cefc4c->player->unknown5d2380(0x1f).isNull()))
	{
		cmu_theme_cefaa8->unknown793690();
		opw8_unknown789ac0();
	}
	if (cmu_tick_caed20 >= cmu_d1da80 && cmu_tick_caed20 - cmu_cefa8c->getField48e040() < 10000)
	{
		cmu_cf4cfc++;
		if (cmu_d28d15)
			cmu_cf4cf8++;
		cmu_d1da80 = cmu_tick_caed20 + 2000;
	}

	if (cmu_theme_cefaa8->check4705f0())
		CMU_MESSAGE(&string("A new version of Cogmind is available, see F1 News page."));
	if (cmu_theme_cefaa8->apply4705b0())
	{
		string version = intToString(cmu_theme_cefaa8->getField9fcd80());
		int index = -1;
		for (int i = 0; i < 11; i++)
		{
			if (version == ((CmuSaveRecord *)gameStrings_d29dc8)[i].version)
			{
				index = i;
				break;
			}
		}
		if (index == -1)
			logError("CMap::update()","unable to find oldSaveVersionString among records " + version);
		else
		{
			string text;
			text = "Found incompatible save file from an earlier version of Cogmind (" + ((CmuSaveRecord *)gameStrings_d29dc8)[index].unknown38 + " - " + ((CmuSaveRecord *)gameStrings_d29dc8)[index].unknown1c + "). Use that version to finish the run, or ignore this message to continue a new one.";
			CMU_MESSAGE(&text);
		}
	}
	if (cmu_theme_cefaa8->check470630())
	{
		CMU_MESSAGE(&string("Reminder: Score uploading is currently disabled in the options menu."));
		opR1d_4541b0(0x63,0,0);
	}

	if (audioLogs != 0)
		audioLogs->unknown7f4f50();
	if (panel != 0)
		panel->update7f5170();

	if (!unknown7b0.empty())
	{
		for (unsigned int i = 0; i < unknown7b0.size(); i++)
		{
			if (cmu_tick_caed20 >= unknown7e0[i])
			{
				if (unknown7b0[i] != 0)
				{
					removeSubconsole(unknown7b0[i]);
					unknown7b0[i] = 0;
				}
				cmu_eraseAt_9d5190(unknown7c0,i);
				cmu_eraseAt_9d5190(unknown7d0,i);
				cmu_removeElement_9de6f0(unknown7e0,i);
				cmu_eraseAt_9ce6d0(unknown7b0,i);
			}
			else
			{
				CmuPos pos = unknown7c0[i] + unknown7d0[i] + scroll;
				unknown7b0[i]->setPos(pos);
				unknown7b0[i]->setHidden(!cmu_cec054->inBounds(pos));
			}
		}
	}

	Console::update();
}
