// op_w2_m: map object BS (0xcefc4c) helpers in 0x714000-0x71bcc0 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <cmath>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Point
{
	int x;
	int y;

	Point();
	Point(int v);					// 0x409990
	Point(int x_, int y_);
	Point(const Point &p);			// 0x46ca50
	Point &operator=(const Point &p);
	bool operator==(const Point &p) const;	// 0x409b90
	bool operator!=(const Point &p) const;	// 0x409bd0
	void set(int v);						// 0x409ff0
	void set(int x_, int y_);
};

class Bresenham2DStepper
{
protected:
	int	errorX;
	int	errorY;
	int	deltaX2;
	int	deltaY2;
	int	stepX;
	int	stepY;
	int	deltaX;
	int	deltaY;
	int	x;
	int	y;

public:
	Bresenham2DStepper() {};
	Bresenham2DStepper(int x0, int y0, int x1, int y1)
	{
		init(x0,y0,x1,y1);
	};
	virtual ~Bresenham2DStepper() {};

	void init(int x0, int y0, int x1, int y1);	// NOTE: placeholder name
	void init(const Point &from, const Point &to)	// NOTE: placeholder name
	{
		init(from.x,from.y,to.x,to.y);
	};
	void step();	// NOTE: placeholder name
	void next(Point &p)	// NOTE: placeholder name
	{
		step();
		p.set(x,y);
	};
	void getDelta(Point &d)	// NOTE: placeholder name
	{
		d.x = deltaX;
		d.y = deltaY;
	};
};

class Bresenham2DStepperSubcell : public Bresenham2DStepper
{
	int	subcells;

public:
	Bresenham2DStepperSubcell(const Point &fromCell, const Point &fromSubcell, const Point &toCell, const Point &toSubcell, int subcells_);
	virtual ~Bresenham2DStepperSubcell();
	bool next(Point &cell, Point &subcell);	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(const Point &p);
	T &operator()(int x, int y);
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
	bool contains(int x, int y);	// NOTE: placeholder name (0x9b45c0)
	int getWidth();					// NOTE: placeholder name (0x9fcd80)
	int getHeight();				// NOTE: placeholder name (0x9b8f00)
};

struct OpW2_Grid : public Array2D<int>	// NOTE: placeholder name
{
	int	stamp;
};

class Entity;
class Prop;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool isValid() const;
	bool operator==(HEntity other) const;
	Entity *operator->() const;		// 0x9b6570
};

class OpW2_Prop	// NOTE: placeholder name
{
public:
	void unknown45ccf0(bool flag);			// NOTE: placeholder name
	const string &unknown45c590();			// NOTE: placeholder name
	bool unknown65e1d0(HEntity e);			// NOTE: placeholder name
	int unknown45c5f0();					// NOTE: placeholder name
	bool unknown6658d0(int count, int id, struct OpW2_Attack *attack);	// NOTE: placeholder name
	int unknown45c650();					// NOTE: placeholder name
	struct OpW2_PropInfo *unknown9b8f00();	// NOTE: placeholder name (folded getter)
	struct OpW2_PropData *unknown45cb30();	// NOTE: placeholder name (folded getter)
	int unknown45c800(int type);			// NOTE: placeholder name
	int unknown45c870(int type);			// NOTE: placeholder name
	const string &unknown45c5b0();			// NOTE: placeholder name
	void setState(int state);				// NOTE: placeholder name (trivial setter)
	const Point &unknown4184d0();	// NOTE: placeholder name (trivial getter)
	int unknown457b10();	// NOTE: placeholder name (trivial getter)
};

class HProp
{
	int	ID;
public:
	bool operator!=(HProp other) const;
	bool isValid() const;
	bool isNull() const;
	OpW2_Prop *operator->() const;	// 0x9b64f0
};

struct OpW2_PropInfo	// NOTE: placeholder name
{
	char	pad0[0xf8];
	int		unknownf8;	// NOTE: placeholder name
};

struct OpW2_PropEntry	// NOTE: placeholder name
{
	int		type;		// NOTE: placeholder name
	int		value;		// NOTE: placeholder name
};

struct OpW2_PropData	// NOTE: placeholder name
{
	char	pad0[0xc];
	int		unknownc;	// NOTE: placeholder name
	char	pad10[0x18 - 0x10];
	vector<OpW2_PropEntry *>	entries;	// 0x18	NOTE: placeholder name
	char	pad28[0x3c - 0x28];
	int		unknown3c;	// NOTE: placeholder name
};

class OpW2_ItemType	// NOTE: placeholder name
{
public:
	int unknown457490();	// NOTE: placeholder name
	int unknown457550();	// NOTE: placeholder name

	int		id;	// NOTE: placeholder name
};

class OpW2_Other	// NOTE: placeholder name
{
public:
	int unknown459890();	// NOTE: placeholder name

	int		id;	// NOTE: placeholder name
};

struct OpW2_WeaponRef	// NOTE: placeholder name
{
	int		type;	// NOTE: placeholder name
	int		index;	// NOTE: placeholder name
};

class OpW2_Item	// NOTE: placeholder name
{
public:
	OpW2_ItemType *unknown9b4350();	// NOTE: placeholder name (trivial getter)
	int getAmount();			// NOTE: placeholder name (trivial getter)
	void setAmount(int amount);	// NOTE: placeholder name (trivial setter)
	void unknown57a0f0(const Point &p, bool a, bool b);	// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);		// NOTE: placeholder name
	string unknown571db0(bool a, bool b);				// NOTE: placeholder name
	int unknown44aec0();								// NOTE: placeholder name (trivial getter)
	int unknown457ca0();								// NOTE: placeholder name
	int unknown4578c0();								// NOTE: placeholder name
	int unknown4578a0();								// NOTE: placeholder name
	bool unknown457d70();								// NOTE: placeholder name
	void *getEffect(int type);							// 0x457b70
	int unknown457880();								// NOTE: placeholder name
	int unknown457a30();								// NOTE: placeholder name
	const Point &unknown575920();						// NOTE: placeholder name
};

class HItem
{
	int	ID;
public:
	HItem();
	bool isValid() const;
	OpW2_Item *operator->() const;	// 0x9b65b0
};

class OpW2_Machine	// NOTE: placeholder name
{
public:
	bool unknown46ecb0();	// NOTE: placeholder name
	int getDepthIndex();	// NOTE: placeholder name

	int		unknown0;
	int		type;	// NOTE: placeholder name
};

class OpW2_HMachine	// NOTE: placeholder name
{
	int	ID;
public:
	OpW2_Machine *operator->() const;	// 0x9b7910
};

struct XColor	// NOTE: placeholder name
{
	unsigned int rgba;
	XColor(const XColor &c);
	XColor &operator=(XColor c);
};

class OpW2_AI	// NOTE: placeholder name (EntityAI)
{
public:
	bool unknown458f10();	// NOTE: placeholder name
	int unknown458f30();	// NOTE: placeholder name
	int unknown459570(HEntity e);	// NOTE: placeholder name
	int unknown9b4350();	// NOTE: placeholder name (trivial getter)
	void unknown5b4710(HEntity e, int a, int b, int c, int d);	// NOTE: placeholder name
	HEntity getFollowEntity();	// NOTE: placeholder name (0x?)
};

class OpW2_Group	// NOTE: placeholder name
{
public:
	vector<HEntity> *getMembers();	// NOTE: placeholder name (0x416f40)
	int unknown9b4350();			// NOTE: placeholder name (trivial getter)
};

class OpW2_HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	OpW2_Group *operator->() const;	// 0x9b7250
};

struct EntityEffect	// NOTE: placeholder layout
{
	int		unknown0;
	int		duration;	// NOTE: placeholder name
};

struct OpW2_EntityData	// NOTE: placeholder name
{
	char	pad0[0x48];
	int		unknown48;	// NOTE: placeholder name
	char	pad4c[0x68 - 0x4c];
	int		unknown68;	// NOTE: placeholder name
};

class Entity
{
public:
	const Point &getPosition();			// 0x45a4a0
	OpW2_AI *getAI();					// NOTE: placeholder name (0x45b590)
	void *getTarget();					// 0x45a760
	int getFaction();					// 0x45a2c0
	const string &getName();			// 0x45a280
	int unknown5cd0a0();				// NOTE: placeholder name
	int getSize();						// NOTE: placeholder name (0x45a360)
	Point unknown5c80f0(const Point &p);	// NOTE: placeholder name
	bool unknown45a510(const Point &p);	// NOTE: placeholder name
	vector<Point> *getFootprint();		// NOTE: placeholder name (0x45d1a0)
	bool isHostileTo(HEntity e);		// 0x45aa70
	int unknown5ca260();				// NOTE: placeholder name
	int unknown490840();				// NOTE: placeholder name
	vector<HItem> *getInventoryList();	// 0x45ab00
	int getSlotTotal();					// 0x45a860
	int unknown5d15a0(int a);			// NOTE: placeholder name
	int unknown5d1390();				// NOTE: placeholder name
	int unknown5c7f10();				// NOTE: placeholder name
	int unknown5cab90();				// NOTE: placeholder name
	HItem unknown5d3f80(int a, int b);	// NOTE: placeholder name
	void unknown5ddac0(const Point &p, int a);	// NOTE: placeholder name
	int unknown45a320();				// NOTE: placeholder name
	bool unknown637da0(int count, int id, struct OpS3b_Actor *attack, const Point *p);	// NOTE: placeholder name
	bool unknown5d51a0();				// NOTE: placeholder name
	bool unknown45aaa0(HEntity e);		// NOTE: placeholder name
	int getAiType();					// 0x45a2a0
	EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	int unknown5cccc0();				// NOTE: placeholder name
	void unknown63c770(int a);			// NOTE: placeholder name
	void unknown63d700();				// NOTE: placeholder name
	int unknown45a760();				// NOTE: placeholder name (same trivial getter as getTarget)
	OpW2_EntityData *unknown9b4350();	// NOTE: placeholder name (trivial getter)
	OpW2_HGroup getGroup();				// NOTE: placeholder name
};


class Entity;
class Cell
{
public:
	bool unknown66b3d0(Entity *e);	// NOTE: placeholder name
	bool canCaveIn();				// 0x66af50
	bool hasBlockingObject();		// NOTE: placeholder name (0x45d7b0)
	bool canPlaceEntity(int size);	// 0x66ad20
	bool isPassableFor(HEntity e);	// 0x66ab30
	bool isMachinePart();
	bool isDoor();
	bool unknown45db70();			// NOTE: placeholder name
	bool unknown45d2d0();			// NOTE: placeholder name
	HItem getItem();				// 0x45d8f0
	int getTerrain();				// NOTE: placeholder name (0x9fcd80)
	bool unknown45d480();			// NOTE: placeholder name
	bool unknown45d500();			// NOTE: placeholder name
	bool unknown6701c0(int count, int id, struct OpR3b_Actor *attack);	// NOTE: placeholder name
	HProp getProp();				// 0x45d550
	HEntity getEntity();			// 0x45d250
	bool isOpen();					// NOTE: placeholder name (0x4550b0)
};

struct OpW2_MachineRecord	// NOTE: placeholder name; element of BS+0x10
{
	Point			position;
	OpW2_HMachine	machine;	// 0x08
	bool			unknownc;	// 0x0c
	bool			unknownd;	// 0x0d
	int				unknown10;
	HProp			prop14;		// 0x14
	HProp			prop18;		// 0x18
};

struct OpW2_Mark	// NOTE: placeholder name
{
	int		stamp;
	int		type;		// NOTE: placeholder name
	HEntity	entity;
	int		unknownc;
	XColor	color;
};

class Cartographer2DMoveCost
{
public:
	bool unknown45b5e0(const Point &from, const Point &to, Entity *e, int &cost);	// NOTE: placeholder name
};
class Cartographer2D
{
public:
	bool findPath(const Point &from, const Point &to, Cartographer2DMoveCost *moveCost, void *data, vector<Point> &path);	// NOTE: placeholder name
	bool unknown40c9e0(const Point &from, const vector<Point> &goals, Cartographer2DMoveCost *moveCost, void *data, vector<Point> &path);	// NOTE: placeholder name
};

extern Cartographer2D			opw2_cartographer;	// NOTE: placeholder name (0xcfe568)
extern Cartographer2DMoveCost	*opw2_moveCost;		// NOTE: placeholder name (0xcefc30)
extern Cartographer2DMoveCost	*opw2_moveCost2c;	// NOTE: placeholder name (0xcefc2c)
extern int						TERRAIN_CAVE_WALL;	// NOTE: placeholder (0xcefba0)
extern bool						opw2_d28e46;		// NOTE: placeholder name
string pointToString(const Point &p);	// NOTE: placeholder name (0x40a4a0)
string intToString(int value);
void logWarning(string location, string message);	// NOTE: placeholder name (0x404e50)
void erasePointAt(vector<Point> &v, int index);		// NOTE: placeholder name (0x9d5190)
void opw2_erasePoints(vector<Point> &v, int from, int to);	// NOTE: placeholder name (0x9d53f0)
void opw2_prependPoints(vector<Point> &v, vector<Point> &front);	// NOTE: placeholder name (0x9de0b0)
extern Array2D<Cell *>			cells;			// NOTE: placeholder name (0xcfd44c)
extern int						opw2_machineFlags[];	// NOTE: placeholder name (0xb90000)

bool opw2_between(int lo, int v, int hi);	// NOTE: placeholder name (0x9daf80)
class GameData	// NOTE: placeholder name
{
public:
	bool unknown46f4b0(int a);					// NOTE: placeholder name
	int getDepthIndex();						// NOTE: placeholder name
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
};
extern GameData gameData;			// NOTE: placeholder name (0xd1e860)
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
extern int	opw2_d1dd3c;	// NOTE: placeholder name
extern int	opw2_cf645c;	// NOTE: placeholder name
extern bool	opw2_cf6468;	// NOTE: placeholder name
extern int	opw2_cf6474;	// NOTE: placeholder name

class OpW2_Obj_cf6428	// NOTE: placeholder name
{
public:
	int unknown683310(HEntity e);	// NOTE: placeholder name
};
extern OpW2_Obj_cf6428	opw2_cf6428;	// NOTE: placeholder name
extern int		opw2_cf4718;			// NOTE: placeholder name
extern int		opw2_table_ba65fc[];	// NOTE: placeholder name
extern string	robotClassNames_d2f798[];
void opw2_lowerToMax(int &value, int maxValue);	// NOTE: placeholder name (0x9cf5a0)
void raiseToMin(int &value, int minValue);		// NOTE: placeholder name (0x9cf5c0)

class OpW2_Object	// NOTE: placeholder name
{
public:
	virtual void v00();
	virtual int getType();	// NOTE: placeholder name
};

class OpW2_HObject	// NOTE: placeholder name
{
	int	ID;
public:
	OpW2_Object *operator->() const;	// 0x9b64d0
};

struct OpW2_EntityRecord	// NOTE: placeholder name
{
	int		unknown0;
	HEntity	entity;
};

extern OpW2_HMachine	opw2_gameState;		// NOTE: placeholder name (0xd1e888)
extern float			opw2_table_ba662c[];	// NOTE: placeholder name
extern float			opw2_table_ba6638[];	// NOTE: placeholder name
extern vector<int>		opw2_d1ea9c;	// NOTE: placeholder name
int opw2_maxInt(int a, int b);		// NOTE: placeholder name (0x9cdb60)
int opw2_minInt(int a, int b);		// NOTE: placeholder name (0x9cdb30)
extern vector<Point>	dijkstraCells;		// NOTE: placeholder name (0xd15e58)
extern int				dijkstraRangeEnd;	// NOTE: placeholder name (0xced284)
extern int				dijkstraRangeStart;	// NOTE: placeholder name (0xcef678)
void clearDijkstraResults();				// NOTE: placeholder name
void findFirstDijkstraRange();				// NOTE: placeholder name

class DijkstraCost_d35394	// NOTE: placeholder name
{
public:
	int pad0;
	int pad4;
	int pad8;
	int padc;
};

class DijkstraRunner	// NOTE: placeholder name (global at 0xcfe568)
{
public:
	void run(const Point &start, int range, void *cost, void *data);	// NOTE: placeholder name (0x40ca20)
};

extern DijkstraRunner		dijkstra;			// NOTE: placeholder name (0xcfe568)
extern DijkstraCost_d35394	dijkstraCost_d35394;

class OpW2_Obj_cefc50	// NOTE: placeholder name
{
public:
	bool unknown454990();	// NOTE: placeholder name
};
extern OpW2_Obj_cefc50 *opw2_cefc50;	// NOTE: placeholder name

class OpW2_StatTracker	// NOTE: placeholder name (0xd2c658)
{
public:
	void unknown472b90(int id, int value);	// NOTE: placeholder name
};
extern OpW2_StatTracker opw2_statTracker;	// NOTE: placeholder name

class OpW2_Obj_cf45d8	// NOTE: placeholder name
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern OpW2_Obj_cf45d8 opw2_cf45d8;	// NOTE: placeholder name

void opw2_unknown5141b0(int id, int a, int b, int c, HEntity e, int d);	// NOTE: placeholder name
bool opw2_eraseInt(vector<int> &v, int value);	// NOTE: placeholder name (0x9d2f00)
struct OpW2_Attack	// NOTE: placeholder name
{
	char		pad0[0x13c];
	vector<int>	ids;	// 0x13c	NOTE: placeholder name
};
extern Point			effectOrigin;		// NOTE: placeholder name (0xd2e20c)
extern Array2D<Point>	opw2_d2ea30;	// NOTE: placeholder name (subcell offsets by type)
extern Array2D<bool>	opw2_d201c8[];		// NOTE: placeholder name
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0
bool opw2_inVectorPoint(vector<Point> &v, Point p);	// NOTE: placeholder name (0x9d0ce0)
int opw2_indexOf(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d3110)
class BS;
extern BS *world;	// NOTE: placeholder name (0xcefc4c)
struct OpW2_ItemType;	// NOTE: placeholder name
extern OpW2_ItemType			*itemTypeMatter;		// NOTE: placeholder (0xcefbe4)
extern vector<OpW2_ItemType *>	opw2_itemTypes;			// NOTE: placeholder name (0xd2d1c4)
bool findItemType(vector<OpW2_ItemType *> &v, const string &name, OpW2_ItemType **out);	// NOTE: placeholder name (0x9d7a40)
class OpW2_ItemFactory	// NOTE: placeholder name
{
public:
	HItem create(OpW2_ItemType *type);	// NOTE: placeholder name (0x7932b0)
};
extern OpW2_ItemFactory *opw2_itemFactory;	// NOTE: placeholder name (0xcefaa8)
void sweepGetSurroundingCells(const Point &point, vector<Point> &adjacent);	// 0x4faaf0
bool opw2_removePoint(vector<Point> &v, Point p);	// NOTE: placeholder name (0x9d3060)
void opw2_shufflePoints(vector<Point> &v);		// NOTE: placeholder name (0x9d7350)
void opw2_appendPoints(vector<Point> &dst, vector<Point> &src);	// NOTE: placeholder name (0x9d7f20)
class DijkstraCost_d1dddc	// NOTE: placeholder name
{
public:
	int pad0;
	int pad4;
	int pad8;
	int padc;
};
extern DijkstraCost_d1dddc	dijkstraCost_d1dddc;
int getDijkstraDistance(const Point &p);	// 0x4fb090
void opw2_shuffleItems(vector<HItem> &v);	// NOTE: placeholder name (0x9de100)
bool unknown5111e0(int id, const string &text, int a, int b, HEntity entity, HEntity other, const Point *at, int flag);	// NOTE: placeholder name
class ConsoleA	// NOTE: placeholder name
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA *consoleA;	// NOTE: placeholder name (0xcec058)
class OpW2_ConsoleB	// NOTE: placeholder name
{
public:
	void unknown7b4f10();	// NOTE: placeholder name
};
extern OpW2_ConsoleB *opw2_consoleB;	// NOTE: placeholder name (0xcec0b4)
class OpW2_MapView	// NOTE: placeholder name
{
public:
	void unknown8195a0(const Point &p, int a, int b);	// NOTE: placeholder name
};
extern OpW2_MapView *opw2_mapView;	// NOTE: placeholder name (0xcec054)
class OpW2_Obj_d20b5c	// NOTE: placeholder name
{
public:
	const int &unknown9b6540();	// NOTE: placeholder name
};
extern OpW2_Obj_d20b5c opw2_d20b5c;	// NOTE: placeholder name
void opw2_erasePointStepBack(vector<Point> &v, unsigned int &i);	// NOTE: placeholder name (0x9d7300)
class DijkstraCost_d21b0c	// NOTE: placeholder name
{
public:
	int pad0;
	int pad4;
	int pad8;
	int padc;
};
extern DijkstraCost_d21b0c	dijkstraCost_d21b0c;
void opw2_unknown9d0690(int &value, int amount, int minimum);	// NOTE: placeholder name
bool opw2_inVector(vector<int> &v, int e);	// NOTE: placeholder name (0x9d31e0)

extern int opw2_table_b90264[];	// NOTE: placeholder name (0xb90264)
int opw2_distance(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
void opw2_eraseAt(vector<HEntity> *v, int *i);	// NOTE: placeholder name (0x9d6440)
OpW2_MachineRecord *opw2_randomElement(vector<OpW2_MachineRecord *> &v);	// NOTE: placeholder name (0x9d5d00)

class BS
{
public:
	void unknown714000(vector<Point> &out);
	void unknown714090(vector<Point> &out);
	Point unknown714120(int type);
	OpW2_MachineRecord *unknown7141a0();
	int unknown7142a0(vector<OpW2_MachineRecord *> &out);
	int unknown714340(vector<OpW2_MachineRecord *> &out);
	OpW2_MachineRecord *unknown7143e0(unsigned int *distance);
	int unknown714590(int &count, int &reachable);
	string unknown7146d0(int x, int y);
	bool unknown714920(const Point &p, HEntity e);
	void unknown7149a0(HEntity e);
	bool unknown714a50();
	int unknown7151c0();
	HEntity unknown715230(int group, int faction);
	HEntity unknown7152d0(int group, const string &name);
	int unknown715380();
	void unknown715420(int range, int &countA, int &countB);
	void unknown715570(int range, int &countA, int &countB);
	int unknown715730(int lastGroup);
	int unknown715800(vector<HEntity> &out);
	bool unknown715920();
	bool unknown715a70();
	int unknown715b10();
	HEntity unknown715c70();
	bool unknown715d20();
	bool unknown715ed0();
	int unknown4642d0();	// NOTE: placeholder name
	int getTurn();			// 0x464270
	int unknown715fe0(int index, const Point &p, int range, bool first);
	bool unknown716080(HEntity e);
	int unknown7161e0();
	bool unknown716250(HEntity e, int rating, string *reason);
	int unknown7163a0(HEntity e);
	float unknown7163d0(int group, bool flag);
	void unknown7164a0(vector<HEntity> &v);
	bool unknown716580(const Point &from, const Point &to, Entity *e, vector<Point> &path);
	bool unknown716740(Entity *e, vector<Point> &path, Point &next);
	bool unknown7168e0(const Point &from, const Point &to, Entity *e, vector<Point> &path);
	bool unknown716940(const Point &from, const Point &to, Entity *e, unsigned int *length);
	int unknown716a20(const Point &from, const Point &to, Entity *e);
	bool unknown4633c0(const Point &p);	// NOTE: placeholder name (Map::unknown4633c0)
	bool unknown716a60(const Point &from, int index, Entity *e, vector<Point> &path);
	bool unknown716c30(const Point &from, Entity *e, vector<Point> &path);
	bool unknown716e50(const Point &from);
	int unknown716f20(HEntity e, const Point &p);
	int unknown716f60(HEntity e, const Point &p);
	OpW2_Object *unknown717be0();
	bool unknown717c60(int value, int key);
	bool unknown717ce0(HEntity e, int value);
	int unknown717d60();
	int unknown717dd0();
	int unknown71aa80(HProp p, int *countOut);
	int unknown71ab60(int n);
	int unknown71abf0(bool flag);
	int unknown71ac50(HEntity e);
	void unknown71ba40(int value);
	bool unknown71bb50();
	bool unknown71bbb0();	// NOTE: placeholder name (wrapper of unknown71bb50)
	bool unknown71bbd0();
	bool unknown71bc10(const Point &p, Point &out);
	bool unknown717e40(const Point &from, const Point &to, int range, Point &cur, Point &last, OpW2_Attack *attack, vector<Point> *hits);
	void unknown71cc70(HEntity e, Point &out);
	Point unknown71d000(int limit);
	const Point &unknown4184d0();	// NOTE: placeholder name (trivial getter)
	bool isVisible(const Point &p);	// 0x4631c0
	void unknown71de30(int x, int y);
	HItem unknown71e7c0(const Point &p, int amount, bool protomatter);
	void unknown71e080(int x, int y);	// NOTE: placeholder name
	bool unknown71bcc0(const Point &p, Point &out);	// NOTE: placeholder name
	bool unknown71e970(const Point &p, vector<Point> visited, int base);
	bool unknown71ec60(const Point &p, vector<Point> visited);
	bool unknown71ef30(const Point &p, bool flag);
	bool unknown71bde0(const Point &p, Point &out);
	void unknown71f700(const Point &p, int radius);
	static bool unknown71f080(const Point &p, int distance);	// NOTE: placeholder name
	int unknown714b50();
	bool unknown463400(HEntity e);	// NOTE: placeholder name (Map::unknown463400)
	Point unknown71b5b0(HEntity e, const Point *at);
	void removeMachine(int machineType, const Point &position);
	int unknown71adc0(HEntity attacker, HProp target, OpW2_WeaponRef *weapon, int type, int index, OpW2_ItemType *itemType, OpW2_Other *other, HItem item, bool flag);
	int unknown71a940(int *countOut);
	bool unknown7170a0(HEntity e, const Point &p, vector<Point> &path, vector<int> &hits, vector<int> &blocks, Point &last, const Point *at, int atMode, bool f1, bool f2);
	bool unknown7178d0(HEntity e, const Point &from, const Point &fromSub, const Point &to, const Point &toSub, bool useSeen);	// NOTE: placeholder name
	int unknown463910(OpW2_HGroup a, OpW2_HGroup b);
	HEntity unknown4630f0();	// NOTE: placeholder name (Map::getPlayer)
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name	// NOTE: placeholder name (Map::unknown463910)

	char					pad0[0x10];
	vector<OpW2_MachineRecord *>	machines;	// 0x10	NOTE: placeholder name
	char					pad20[0x4c - 0x20];
	vector<OpW2_HGroup>		groups;				// 0x4c
	char					pad5c[0x118 - 0x5c];
	vector<vector<Point> >	goals118;			// 0x118	NOTE: placeholder name
	char					pad128[0x138 - 0x128];
	vector<Point>			removed138;			// 0x138	NOTE: placeholder name
	char					pad148[0x208 - 0x148];
	vector<int>				values208;			// 0x208	NOTE: placeholder name
	int						unknown218;			// 0x218	NOTE: placeholder name
	int						unknown21c;			// 0x21c	NOTE: placeholder name
	char					pad220[0x268 - 0x220];
	vector<vector<HProp> >	props268;			// 0x268	NOTE: placeholder name
	char					pad278[0x324 - 0x278];
	int						unknown324;			// 0x324	NOTE: placeholder name (turn)
	char					pad328[0x594 - 0x328];
	vector<HEntity>			entities594;		// 0x594	NOTE: placeholder name
	vector<vector<HEntity> >	entities5a4;	// 0x5a4	NOTE: placeholder name
	char					pad5b4[0x5ec - 0x5b4];
	vector<int>				unknown5ec;			// 0x5ec	NOTE: placeholder name
	char					pad5fc[0x658 - 0x5fc];
	int						unknown658;			// 0x658	NOTE: placeholder name
	char					pad65c[0x66c - 0x65c];
	HEntity					target;				// 0x66c	NOTE: placeholder name
	char					pad670[0x69c - 0x670];
	Array2D<int>			seen;				// 0x69c	NOTE: placeholder name
	char					pad6a8[0x6e8 - 0x6a8];
	OpW2_Grid				*fov;				// 0x6e8	NOTE: placeholder name
	char					pad6ec[0x6fc - 0x6ec];
	vector<HEntity>			entities6fc;		// 0x6fc	NOTE: placeholder name
	char					pad70c[0x740 - 0x70c];
	Array2D<OpW2_Mark>		marks;				// 0x740	NOTE: placeholder name
	int						markStamp;			// 0x74c	NOTE: placeholder name
	char					pad750[0x830 - 0x750];
	vector<Point>			points830;			// 0x830	NOTE: placeholder name
	vector<Point>			points840;			// 0x840	NOTE: placeholder name
	vector<HEntity>			entities850;		// 0x850	NOTE: placeholder name
	char					pad860[0xa20 - 0x860];
	vector<int>				valuesa20;			// 0xa20	NOTE: placeholder name
	vector<OpW2_HObject>	objectsa30;			// 0xa30	NOTE: placeholder name
	vector<vector<int> >	valuesa40;			// 0xa40	NOTE: placeholder name
	vector<int>				keysa50;			// 0xa50	NOTE: placeholder name
	vector<OpW2_EntityRecord *>	recordsa60;		// 0xa60	NOTE: placeholder name
	unsigned int			unknowna70;			// 0xa70	NOTE: placeholder name
	char					pada74[0xb04 - 0xa74];
	bool					unknownb04;			// 0xb04	NOTE: placeholder name
};

void BS::unknown714000(vector<Point> &out)
{
	for (unsigned int i = 0; i < machines.size(); i++)
	{
		if (!machines[i]->unknownc && machines[i]->machine->unknown46ecb0())
			out.push_back(machines[i]->position);
	}
}

void BS::unknown714090(vector<Point> &out)
{
	for (unsigned int i = 0; i < machines.size(); i++)
	{
		if (!machines[i]->unknownc && opw2_machineFlags[machines[i]->machine->type] == 1)
			out.push_back(machines[i]->position);
	}
}

Point BS::unknown714120(int type)
{
	for (unsigned int i = 0; i < machines.size(); i++)
	{
		if (machines[i]->machine->type == type)
			return machines[i]->position;
	}
	return Point(-1);
}

OpW2_MachineRecord *BS::unknown7141a0()
{
	vector<OpW2_MachineRecord *> candidates;
	for (unsigned int i = 0; i < machines.size(); i++)
	{
		if (opw2_between(15, machines[i]->machine->type, 18))
			candidates.push_back(machines[i]);
	}
	if (candidates.empty())
		return NULL;
	return opw2_randomElement(candidates);
}

int BS::unknown7142a0(vector<OpW2_MachineRecord *> &out)
{
	for (unsigned int i = 0; i < machines.size(); i++)
	{
		if (machines[i]->prop14.operator->() && machines[i]->prop14->unknown457b10() == 0)
			out.push_back(machines[i]);
	}
	return out.size();
}

int BS::unknown714340(vector<OpW2_MachineRecord *> &out)
{
	for (unsigned int i = 0; i < machines.size(); i++)
	{
		if (machines[i]->prop18.operator->() && machines[i]->prop18->unknown457b10() == 0)
			out.push_back(machines[i]);
	}
	return out.size();
}

OpW2_MachineRecord *BS::unknown7143e0(unsigned int *distance)
{
	int best = -1;
	unsigned int bestDistance;
	vector<Point> path;
	for (unsigned int i = 0; i < machines.size(); i++)
	{
		if ((machines[i]->unknownd || (machines[i]->prop14.isNull() && machines[i]->prop18.isNull())) && opw2_cartographer.findPath(target->getPosition(), machines[i]->position, opw2_moveCost, 0, path))
		{
			if (best == -1 || path.size() < bestDistance)
			{
				bestDistance = path.size();
				best = i;
			}
		}
	}
	if (best == -1)
		return NULL;
	else
	{
		if (distance)
			*distance = bestDistance;
		return machines[best];
	}
}

int BS::unknown714590(int &count, int &reachable)
{
	count = 0;
	reachable = 0;
	int best = -1;
	vector<Point> path;
	for (unsigned int i = 0; i < machines.size(); i++)
	{
		if (machines[i]->unknownd)
		{
			count++;
			if (opw2_cartographer.findPath(target->getPosition(), machines[i]->position, opw2_moveCost, 0, path))
			{
				reachable++;
				if (best == -1 || path.size() < best)
					best = path.size();
			}
		}
	}
	return best;
}

string BS::unknown7146d0(int x, int y)
{
	int w = cells.getWidth();
	int h = cells.getHeight();
	if (x < w * 0.33 && y < h * 0.33)
		return "northwestern";
	else if (x < w * 0.33 && y < h * 0.66)
		return "central western";
	else if (x < w * 0.33)
		return "southwestern";
	else if (x < w * 0.66 && y < h * 0.33)
		return "central northern";
	else if (x < w * 0.66 && y < h * 0.66)
		return "central";
	else if (x < w * 0.66)
		return "central southern";
	else if (y < h * 0.33)
		return "northeastern";
	else if (y < h * 0.66)
		return "central eastern";
	else
		return "southeastern";
}

bool BS::unknown714920(const Point &p, HEntity e)
{
	if (marks(p).stamp == markStamp && marks(p).entity == e)
		return marks(p).type != 0;
	return false;
}

void BS::unknown7149a0(HEntity e)
{
	for (unsigned int i = 0; i < entities6fc.size(); i++)
	{
		if (entities6fc[i].operator->())
			e->getAI()->unknown5b4710(entities6fc[i], 1, 0, 0, 0);
		else
			opw2_eraseAt(&entities6fc, (int *)&i);
	}
}

bool BS::unknown714a50()
{
	if (entities6fc.empty())
		return false;
	for (unsigned int i = 0; i < entities6fc.size(); i++)
	{
		if (entities6fc[i].operator->() && entities6fc[i]->getAI()->unknown9b4350() >= 6 && !entities6fc[i]->getAI()->unknown458f10() && !entities6fc[i]->getTarget())
			return true;
	}
	return false;
}

int BS::unknown7151c0()
{
	int total = 0;
	for (unsigned int i = 0; i < entities6fc.size(); i++)
		total += entities6fc[i]->unknown5cd0a0();
	return total;
}

HEntity BS::unknown715230(int group, int faction)
{
	vector<HEntity> *members = groups[group]->getMembers();
	for (unsigned int i = 0; i < members->size(); i++)
	{
		if ((*members)[i]->getFaction() == faction)
			return (*members)[i];
	}
	return HEntity();
}

HEntity BS::unknown7152d0(int group, const string &name)
{
	vector<HEntity> *members = groups[group]->getMembers();
	for (unsigned int i = 0; i < members->size(); i++)
	{
		if ((*members)[i]->getName() == name)
			return (*members)[i];
	}
	return HEntity();
}

int BS::unknown715380()
{
	int total = 0;
	for (unsigned int i = 0; i < groups.size(); i++)
	{
		if (!unknown463910(groups[0], groups[i]))
			total += groups[i]->getMembers()->size();
	}
	return total;
}

void BS::unknown715420(int range, int &countA, int &countB)
{
	countB = 0;
	countA = 0;
	for (int i = 0; i <= 2; i++)
	{
		for (unsigned int j = (i == 0); j < groups[i]->getMembers()->size(); j++)
		{
			if (opw2_distance(unknown4630f0()->getPosition(), (*groups[i]->getMembers())[j]->getPosition()) <= range)
			{
				((*groups[i]->getMembers())[j]->getAI()->unknown9b4350() >= 6 ? countA : countB)++;
			}
		}
	}
}

void BS::unknown715570(int range, int &countA, int &countB)
{
	countB = 0;
	countA = 0;
	for (int i = 0; i <= 2; i++)
	{
		for (unsigned int j = (i == 0); j < groups[i]->getMembers()->size(); j++)
		{
			if (opw2_distance(unknown4630f0()->getPosition(), (*groups[i]->getMembers())[j]->getPosition()) <= range)
			{
				if ((*groups[i]->getMembers())[j]->getAI()->unknown9b4350() >= 6)
					countA += opw2_table_b90264[(*groups[i]->getMembers())[j]->unknown9b4350()->unknown68];
				else
					countB += (*groups[i]->getMembers())[j]->unknown9b4350()->unknown68;
			}
		}
	}
}

int BS::unknown715730(int lastGroup)
{
	int count = -1;
	for (int i = 0; i <= lastGroup; i++)
	{
		vector<HEntity> *members = groups[i]->getMembers();
		for (unsigned int j = 0; j < members->size(); j++)
		{
			if ((*members)[j]->unknown5d51a0() && (*members)[j]->unknown45a760() < 6)
				count++;
		}
	}
	return count;
}

int BS::unknown715800(vector<HEntity> &out)
{
	vector<HEntity> *members0 = groups[0]->getMembers();
	for (unsigned int i = 1; i < members0->size(); i++)
	{
		if (!(*members0)[i]->getTarget())
			out.push_back((*members0)[i]);
	}
	vector<HEntity> *members1 = groups[1]->getMembers();
	for (unsigned int j = 0; j < members1->size(); j++)
	{
		if (!(*members1)[j]->getTarget() && unknown4631f0((*members1)[j]))
			out.push_back((*members1)[j]);
	}
	return out.size();
}

bool BS::unknown715920()
{
	if (groups[0]->getMembers()->size() > 1)
	{
		vector<HEntity> *members0 = groups[0]->getMembers();
		for (unsigned int i = 1; i < members0->size(); i++)
		{
			if (!(*members0)[i]->getTarget())
				return true;
		}
	}
	if (!groups[1]->getMembers()->empty())
	{
		vector<HEntity> *members1 = groups[1]->getMembers();
		for (unsigned int j = 0; j < members1->size(); j++)
		{
			if (!(*members1)[j]->getTarget() && unknown4631f0((*members1)[j]))
				return true;
		}
	}
	return false;
}

bool BS::unknown715a70()
{
	return groups[0]->getMembers()->size() > 1 || !groups[1]->getMembers()->empty() || !groups[2]->getMembers()->empty();
}

int BS::unknown715b10()
{
	int count = 0;
	for (unsigned int i = 0; i < groups.size(); i++)
	{
		vector<HEntity> *members = groups[i]->getMembers();
		for (unsigned int j = 0; j < members->size(); j++)
		{
			if ((*members)[j]->unknown45aaa0(target) && (*members)[j]->getAI() && (*members)[j]->getAI()->getFollowEntity() == target && opw2_distance((*members)[j]->getPosition(), target->getPosition()) <= 15)
				count++;
		}
	}
	return count;
}

HEntity BS::unknown715c70()
{
	vector<HEntity> *members = groups[1]->getMembers();
	for (unsigned int i = 0; i < members->size(); i++)
	{
		if ((*members)[i]->getFaction() == 20 && unknown4631f0((*members)[i]))
			return (*members)[i];
	}
	return HEntity();
}

bool BS::unknown715d20()
{
	bool show = gameData.unknown46f4b0(1) && (unknown218 == 0 || unknown324 % 5 == 0) && stringToInt(gameData.unknown46f6d0("zioWasImprinted_g")) && !stringToInt(gameData.unknown46f6d0("zioAttackedLocals_g")) && unknown4642d0() < opw2_d1dd3c && (opw2_cf645c == 0 || getTurn() - opw2_cf645c < (opw2_cf6468 ? 1 : 50)) && opw2_cf6474 == 0;
	if (show)
	{
		unknown218 = unknown324;
		return true;
	}
	return false;
}

bool BS::unknown715ed0()
{
	bool show = gameData.unknown46f4b0(1) && (unknown21c == 0 || unknown324 % 5 == 0) && stringToInt(gameData.unknown46f6d0("installedRif_g"));
	if (show)
	{
		unknown21c = unknown324;
		return true;
	}
	return false;
}

int BS::unknown715fe0(int index, const Point &p, int range, bool first)
{
	int count = 0;
	for (unsigned int i = 0; i < props268[index].size(); i++)
	{
		if (opw2_distance(props268[index][i]->unknown4184d0(), p) <= range)
		{
			count++;
			if (first)
				return count;
			break;
		}
	}
	return count;
}

bool BS::unknown716080(HEntity e)
{
	if (e->unknown9b4350()->unknown48 == 47)
		return true;
	for (unsigned int i = 0; i < entities594.size(); i++)
	{
		if (entities594[i] == e)
		{
			for (unsigned int j = 0; j < entities5a4[i].size(); j++)
			{
				if (!entities5a4[i][j].operator->() || !opw2_cf6428.unknown683310(entities5a4[i][j]))
					opw2_eraseAt(&entities5a4[i], (int *)&j);
			}
			return entities5a4[i].size() < opw2_table_ba65fc[opw2_cf4718];
		}
	}
	return false;
}

int BS::unknown7161e0()
{
	int value = 50;
	if (!unknown5ec.empty())
	{
		for (int i = unknown5ec.size() - 1; i >= 0; i--)
			value *= 1.5f;
	}
	return value;
}

bool BS::unknown716250(HEntity e, int rating, string *reason)
{
	if (e->getTarget())
	{
		if (reason)
			*reason = "inactive";
		return false;
	}
	if (!e->getAiType())
	{
		if (reason)
			*reason = "special class";
		return false;
	}
	if (e->getFaction() == 10 || e->getFaction() == 11 || e->getFaction() == 6)
	{
		if (reason)
			*reason = robotClassNames_d2f798[e->getFaction()];
		return false;
	}
	if (e->unknown45ac40(57))
	{
		if (reason)
			*reason = "Borg";
		return false;
	}
	if (e->unknown45ac40(123))
	{
		if (reason)
			*reason = "under external control";
		return false;
	}
	if (!rating)
	{
		if (reason)
			*reason = "rating too high";
		return false;
	}
	return true;
}

int BS::unknown7163a0(HEntity e)
{
	return 100 - e->unknown5cccc0() + 40;
}

float BS::unknown7163d0(int group, bool flag)
{
	int count = 0;
	vector<HEntity> *members = groups[group]->getMembers();
	for (unsigned int i = 0; i < members->size(); i++)
	{
		if ((*members)[i]->unknown45ac40(57))
			count++;
	}
	if (count && !flag)
		count--;
	if (count)
	{
		opw2_lowerToMax(count, 10);
		return 100.0 / (60 - count * 3);
	}
	return 0;
}

void BS::unknown7164a0(vector<HEntity> &v)
{
	if (v.empty())
		return;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		EntityEffect *effect = v[i]->unknown45ac40(57);
		if (effect == NULL)
			opw2_eraseAt(&v, (int *)&i);
		else if (effect->duration > 1)
		{
			effect->duration--;
			if (effect->duration == 1)
				v[i]->unknown63c770(0);
		}
		v[i]->unknown63d700();
	}
}

bool BS::unknown716580(const Point &from, const Point &to, Entity *e, vector<Point> &path)
{
	static Bresenham2DStepper stepper;
	if (from == to)
		return false;
	stepper.init(from,to);
	path.clear();
	path.push_back(from);
	Point p;
	do
	{
		stepper.next(p);
		path.push_back(p);
		int cost;
		if (!opw2_moveCost2c->unknown45b5e0(path[path.size() - 2], p, e, cost))
			break;
		for (int x = p.x + e->getSize() - 1; x >= p.x; x--)
		{
			for (int y = p.y + e->getSize() - 1; y >= p.y; y--)
			{
				if (cells(x,y)->unknown66b3d0(e) || cells(x,y)->canCaveIn() || cells(x,y)->getTerrain() == TERRAIN_CAVE_WALL)
					return false;
			}
		}
		if (p == to)
			return true;
	} while (true);
	return false;
}

bool BS::unknown716740(Entity *e, vector<Point> &path, Point &next)
{
	int index = -1;
	if (unknown4633c0(path.back()))
		index = path.size() - 1;
	else
	{
		for (unsigned int i = 0; i < path.size(); i++)
		{
			if (!unknown4633c0(path[i]))
			{
				index = i - 1;
				break;
			}
		}
	}
	if (index > 1)
	{
		vector<Point> line;
		if (unknown716580(e->getPosition(), path[index], e, line))
		{
			erasePointAt(line, 0);
			if (index == path.size() - 1)
			{
				path = line;
				next.set(-1);
			}
			else
			{
				next = path[index + 1];
				opw2_erasePoints(path, 0, index);
				opw2_prependPoints(path, line);
			}
			return true;
		}
	}
	return false;
}

bool BS::unknown7168e0(const Point &from, const Point &to, Entity *e, vector<Point> &path)
{
	if (unknown716580(from, to, e, path))
		return true;
	else
		return opw2_cartographer.findPath(from, to, opw2_moveCost2c, e, path);
}

bool BS::unknown716940(const Point &from, const Point &to, Entity *e, unsigned int *length)
{
	bool saved = opw2_d28e46;
	opw2_d28e46 = false;
	vector<Point> path;
	bool result = e ? unknown7168e0(from, to, e, path) : opw2_cartographer.findPath(from, to, opw2_moveCost, 0, path);
	if (length)
		*length = path.size();
	opw2_d28e46 = saved;
	return result;
}

int BS::unknown716a20(const Point &from, const Point &to, Entity *e)
{
	unsigned int length;
	if (!unknown716940(from, to, e, &length))
		return 9999;
	return length;
}

bool BS::unknown716a60(const Point &from, int index, Entity *e, vector<Point> &path)
{
	if (goals118[index].empty())
		return false;
	for (unsigned int i = 0; i < goals118[index].size(); i++)
		cells(goals118[index][i])->getProp()->unknown45ccf0(true);
	path.clear();
	bool found = opw2_cartographer.unknown40c9e0(from, vector<Point>(goals118[index]), opw2_moveCost2c, e, path);
	for (unsigned int j = 0; j < goals118[index].size(); j++)
		cells(goals118[index][j])->getProp()->unknown45ccf0(false);
	if (found)
		erasePointAt(path, 0);
	return found;
}

bool BS::unknown716c30(const Point &from, Entity *e, vector<Point> &path)
{
	if (goals118[0].empty())
		return false;
	vector<Point> goals;
	for (unsigned int i = 0; i < goals118[0].size(); i++)
	{
		if (cells(goals118[0][i])->getProp()->unknown45c590() == "DSF Access")
		{
			goals.push_back(goals118[0][i]);
			cells(goals.back())->getProp()->unknown45ccf0(true);
		}
	}
	path.clear();
	bool found = opw2_cartographer.unknown40c9e0(from, vector<Point>(goals), opw2_moveCost2c, e, path);
	for (unsigned int j = 0; j < goals.size(); j++)
		cells(goals[j])->getProp()->unknown45ccf0(false);
	if (found)
		erasePointAt(path, 0);
	return found;
}

bool BS::unknown716e50(const Point &from)
{
	vector<Point> path;
	for (unsigned int i = 0; i < machines.size(); i++)
	{
		if (opw2_cartographer.findPath(from, machines[i]->position, opw2_moveCost, 0, path))
			return true;
	}
	return false;
}

int BS::unknown716f20(HEntity e, const Point &p)
{
	int result = unknown716f60(e, p);
	if (result == 0)
		return 4;
	else
		return result;
}

int BS::unknown716f60(HEntity e, const Point &p)
{
	return e->unknown45a510(p) ? 0 : (seen(p) == 0 ? 4 : (!cells(p)->isOpen() ? 3 : (cells(p)->getEntity().isValid() ? 1 : (cells(p)->getProp().isValid() && !cells(p)->getProp()->unknown65e1d0(HEntity()) ? 2 : 0))));
}

OpW2_Object *BS::unknown717be0()
{
	for (unsigned int i = 0; i < objectsa30.size(); i++)
	{
		if (objectsa30[i]->getType() == 1)
			return objectsa30[i].operator->();
	}
	return NULL;
}

bool BS::unknown717c60(int value, int key)
{
	for (unsigned int i = 0; i < keysa50.size(); i++)
	{
		if (keysa50[i] == key)
			return opw2_inVector(valuesa40[i], value);
	}
	return false;
}

bool BS::unknown717ce0(HEntity e, int value)
{
	for (unsigned int i = 0; i < recordsa60.size(); i++)
	{
		if (recordsa60[i]->entity == e && recordsa60[i]->unknown0 == value)
			return true;
	}
	return false;
}

int BS::unknown717d60()
{
	return (int)(opw2_gameState->type == 36 ? 3.0 : (cells.getWidth() * cells.getHeight() / 1150 + 5) * opw2_table_ba662c[opw2_cf4718]);
}

int BS::unknown717dd0()
{
	return (int)(opw2_gameState->type == 36 ? 10.0 : (cells.getWidth() * cells.getHeight() / 570 + 5) * opw2_table_ba6638[opw2_cf4718]);
}

int BS::unknown71aa80(HProp p, int *countOut)
{
	int count = 0;
	int total = 0;
	for (unsigned int i = 0; i < props268[2].size(); i++)
	{
		if (props268[2][i] != p)
		{
			int value = 6;
			for (int j = count; j > 0; j--)
				value /= 2;
			total += opw2_maxInt(1, value);
			count++;
		}
	}
	if (countOut)
		*countOut = count;
	return total;
}

int BS::unknown71ab60(int n)
{
	int count = 0;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		int value = 6;
		for (int j = count; j > 0; j--)
			value /= 2;
		total += opw2_maxInt(1, value);
		count++;
	}
	return total;
}

int BS::unknown71abf0(bool flag)
{
	int count = props268[10].size();
	if (flag)
		count += opw2_d1ea9c[gameData.getDepthIndex()];
	return count;
}

int BS::unknown71ac50(HEntity e)
{
	if (!e->getAI() || !e->getAI()->unknown458f30())
		return 0;
	else
	{
		int bonus = 0;
		int depth = opw2_gameState->getDepthIndex();
		if (depth >= 3 && (opw2_d1ea9c[depth - 1] != 0 || opw2_d1ea9c[depth - 2] != 0) && e->getGroup()->unknown9b4350() == 3 && e->getAiType() == 1 && e->getAI()->unknown9b4350() >= 6 && !e->unknown45ac40(36) && !e->getTarget())
		{
			bonus += opw2_d1ea9c[depth - 1] * 3;
			bonus += opw2_d1ea9c[depth - 2];
		}
		return opw2_minInt(bonus, 15);
	}
}

void BS::unknown71ba40(int value)
{
	if (opw2_eraseInt(valuesa20, value) && valuesa20.empty())
	{
		do
		{
			opw2_unknown5141b0(536, 0, 0, 0, HEntity(), 0);
		} while (0);
		if (!stringToInt(gameData.unknown46f6d0("comPlayerSurrenderedBefore_g")))
		{
			opw2_statTracker.unknown472b90(85, -999999);
			opw2_cf45d8.unknown77fbc0(427);
		}
	}
}

bool BS::unknown71bb50()
{
	return !objectsa30.empty() || unknowna70 > 0 || opw2_cefc50->unknown454990();
}

bool BS::unknown71bbd0()
{
	return unknown71bbb0() || unknown658 != 1;
}

bool BS::unknown71bc10(const Point &p, Point &out)
{
	if (!cells(p)->hasBlockingObject())
	{
		clearDijkstraResults();
		dijkstra.run(p, 12, &dijkstraCost_d35394, 0);
		if (dijkstraCells.empty())
		{
			return false;
		}
		else
		{
			findFirstDijkstraRange();
			out = dijkstraCells[rng.rangeInt(dijkstraRangeStart, dijkstraRangeEnd)];
			return true;
		}
	}
	else
	{
		out = p;
		return true;
	}
}

bool BS::unknown717e40(const Point &from, const Point &to, int range, Point &cur, Point &last, OpW2_Attack *attack, vector<Point> *hits)
{
	vector<int> penetrate;
	bool ok;
	int index;
	if (attack)
		penetrate = attack->ids;
	Point subcell;
	Bresenham2DStepperSubcell bresenham(from, effectOrigin, to, effectOrigin, 9);
	last = from;
	bresenham.next(cur, subcell);
	while (cur == from)
		bresenham.next(cur, subcell);
	while (!bresenham.next(cur, subcell))
	{
		if (last != cur)
		{
			if (!cells.contains(cur))
			{
				cur.x = -1;
				return false;
			}
			if (seen(cur) != 0)
				return true;
			ok = false;
			if (cells(cur)->unknown45d480() || opw2_distance(from, cur) > range)
			{
				if (cells(cur)->unknown45d500())
					ok = !penetrate.empty() && cells(cur)->getProp()->unknown6658d0(hits->size(), penetrate.front(), attack);
				else
					ok = opw2_distance(from, cur) <= range && !penetrate.empty() && cells(cur)->unknown6701c0(hits->size(), penetrate.front(), (OpR3b_Actor *)attack);
				if (ok)
				{
					if (penetrate.front() != -1)
						removeVectorElement(penetrate, 0);
					hits->push_back(cur);
				}
				else
					return false;
			}
			index = 0;
			if (cells(cur)->getEntity().isValid())
				index = cells(cur)->getEntity()->unknown45a320();
			else if (cells(cur)->getProp().isValid() && cells(cur)->getProp()->unknown45c5f0())
				index = cells(cur)->getProp()->unknown45c5f0();
			last = cur;
		}
		if (index != 0 && opw2_d201c8[index](subcell) && (!hits || !opw2_inVectorPoint(*hits, cur)))
		{
			if (!penetrate.empty())
			{
				if (cells(cur)->getEntity().isValid())
					ok = cells(cur)->getEntity()->unknown637da0(hits->size(), penetrate.front(), (OpS3b_Actor *)attack, &cur);
				else
					ok = cells(cur)->getProp()->unknown6658d0(hits->size(), penetrate.front(), attack);
				if (ok)
				{
					if (penetrate.front() != -1)
						removeVectorElement(penetrate, 0);
					hits->push_back(cur);
				}
				else
					return false;
			}
			else
				return false;
		}
	}
	cur.x = -1;
	return false;
}

void BS::unknown71cc70(HEntity e, Point &out)
{
	if (e->getSize() > 1)
	{
		if (!points840.empty())
		{
			for (unsigned int i = 0; i < entities850.size(); i++)
			{
				if (!entities850[i].operator->())
					opw2_eraseAt(&entities850, (int *)&i);
			}
			int idx = opw2_indexOf(entities850, e);
			if (idx == -1)
			{
				idx = entities850.size();
				entities850.push_back(e);
			}
			int steps = idx * 2 + 6;
			if (points840.size() >= steps)
				out = points840[points840.size() - steps];
			else
				out = points840.front();
		}
	}
	else if (!e->unknown5d51a0() && !points830.empty())
	{
		if (points830.size() >= 4)
			out = points830[points830.size() - 4];
		else
			out = points830.front();
	}
}

Point BS::unknown71d000(int limit)
{
	int count = 0;
	Point pos(-1);
	vector<Point> path;
	if (opw2_cartographer.findPath(world->unknown4184d0(), world->unknown4630f0()->getPosition(), opw2_moveCost, 0, path))
	{
		for (int i = path.size() - 1; i >= 0; i--)
		{
			if (!world->isVisible(path[i]))
			{
				pos = path[i];
				count++;
				if (count > limit)
					break;
			}
		}
	}
	return pos;
}

void BS::unknown71de30(int x, int y)
{
	if (cells(x,y)->getProp().isValid() && cells(x,y)->getProp()->unknown45c650() <= -1)
	{
		switch (cells(x,y)->getProp()->unknown45c650())
		{
			case -21:
			case -20:
				unknown71e080(x,y);
				break;
			case -10:
				if (cells.contains(x - 1,y) && cells(x - 1,y)->isOpen() && !cells(x - 1,y)->unknown45db70() && !cells(x - 1,y)->unknown45d2d0() &&
					cells.contains(x + 1,y) && cells(x + 1,y)->isOpen() && !cells(x + 1,y)->unknown45db70() && !cells(x + 1,y)->unknown45d2d0())
					cells(x,y)->getProp()->setState(124);
				else
					cells(x,y)->getProp()->setState(45);
				break;
		}
	}
}

HItem BS::unknown71e7c0(const Point &p, int amount, bool protomatter)
{
	Point here;
	if (unknown71bcc0(p, here))
	{
		if (cells(here)->getItem().isValid())
		{
			cells(here)->getItem()->setAmount(cells(here)->getItem()->getAmount() + amount);
			return cells(here)->getItem();
		}
		else
		{
			OpW2_ItemType *type = itemTypeMatter;
			if (protomatter)
				findItemType(opw2_itemTypes, "Protomatter", &type);
			HItem item = opw2_itemFactory->create(type);
			item->setAmount(amount);
			item->unknown57a0f0(here, false, false);
			return item;
		}
	}
	else
		return HItem();
}

bool BS::unknown71e970(const Point &p, vector<Point> visited, int base)
{
	if (visited.size() - base >= 30)
		return false;
	vector<Point> list;
	sweepGetSurroundingCells(p, list);
	for (unsigned int i = 0; i < visited.size(); i++)
		opw2_removePoint(list, visited[i]);
	opw2_shufflePoints(list);
	HEntity target = cells(p)->getEntity();
	if (target->getSize() != 1)
		return false;
	for (unsigned int j = 0; j < list.size(); j++)
	{
		if (cells(list[j])->canPlaceEntity(1))
		{
			target->unknown5ddac0(list[j], 0);
			return true;
		}
	}
	vector<Point> path(visited);
	opw2_appendPoints(path, list);
	for (unsigned int k = 0; k < list.size(); k++)
	{
		if (cells(list[k])->getEntity().isValid() && unknown71e970(list[k], path, base))
		{
			target->unknown5ddac0(list[k], 0);
			return true;
		}
	}
	return false;
}

bool BS::unknown71ec60(const Point &p, vector<Point> visited)
{
	if (visited.size() >= 30)
		return false;
	vector<Point> list;
	sweepGetSurroundingCells(p, list);
	for (unsigned int i = 0; i < visited.size(); i++)
		opw2_removePoint(list, visited[i]);
	opw2_shufflePoints(list);
	for (unsigned int j = 0; j < list.size(); j++)
	{
		if (cells(list[j])->hasBlockingObject())
		{
			cells(p)->getItem()->unknown57a0f0(list[j], false, false);
			return true;
		}
	}
	vector<Point> path(visited);
	opw2_appendPoints(path, list);
	for (unsigned int k = 0; k < list.size(); k++)
	{
		if (cells(list[k])->getItem().isValid() && unknown71ec60(list[k], path))
		{
			cells(p)->getItem()->unknown57a0f0(list[k], false, false);
			return true;
		}
	}
	return false;
}

bool BS::unknown71ef30(const Point &p, bool flag)
{
	if (cells(p)->getItem().isValid())
	{
		vector<Point> visited(1, Point(p));
		if (unknown71ec60(Point(p), visited))
			return true;
		else if (flag)
		{
			cells(p)->getItem()->unknown57dbe0(0, 0, 1, 1);
			return true;
		}
		else
			return false;
	}
	return true;
}

bool BS::unknown71bde0(const Point &p, Point &out)
{
	vector<Point> list;
	sweepGetSurroundingCells(p, list);
	opw2_shufflePoints(list);
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (cells(list[i])->hasBlockingObject())
		{
			out = list[i];
			return true;
		}
	}
	for (unsigned int j = 0; j < list.size(); j++)
	{
		if (cells(list[j])->getItem().isValid())
		{
			vector<Point> visited(1, list[j]);
			if (unknown71ec60(list[j], visited))
			{
				out = list[j];
				return true;
			}
		}
	}
	for (unsigned int k = 0; k < list.size(); k++)
	{
		if (cells(list[k])->getItem().isValid())
		{
			vector<Point> visited(1, list[k]);
			cells(list[k])->getItem()->unknown57dbe0(0, 0, 1, 1);
			out = list[k];
			return true;
		}
	}
	for (unsigned int l = 0; l < list.size(); l++)
	{
		if (cells(list[l])->isMachinePart() || cells(list[l])->isDoor())
			return unknown71bde0(list[l], out);
	}
	return false;
}

void BS::unknown71f700(const Point &p, int radius)
{
	HItem machine = cells(p)->getItem();
	if (machine.isValid())
	{
		string rec = machine->unknown571db0(false, false);
		int points = machine->unknown457880();
		int index = machine->unknown457a30();
		unknown71ef30(p, true);
		if (!machine.operator->() && isVisible(p))
		{
			do
			{
				if (unknown5111e0(points != 0 && points != 3 ? 17 : 18, rec, 0, 0, target, HEntity(), 0, 0))
					consoleA->unknown8758d0(true);
				opw2_consoleB->unknown7b4f10();
			} while (0);
			opw2_mapView->unknown8195a0(p, index, 2);
		}
	}
	vector<Point> down;
	clearDijkstraResults();
	dijkstra.run(p, radius * 2 + 2, &dijkstraCost_d1dddc, 0);
	down = dijkstraCells;
	vector<HItem> aux;
	for (unsigned int i = 0; i < down.size(); i++)
	{
		if (cells(down[i])->getItem().isValid())
			aux.push_back(cells(down[i])->getItem());
	}
	opw2_shuffleItems(aux);
	int s2 = 16;
	clearDijkstraResults();
	dijkstra.run(p, 34, &dijkstraCost_d1dddc, 0);
	for (unsigned int j = 0; j < aux.size(); j++)
	{
		if (!aux[j].operator->())
			continue;
		const Point &pos = aux[j]->unknown575920();
		if (!unknown71f080(Point(pos), getDijkstraDistance(pos) + 1))
		{
			if (isVisible(aux[j]->unknown575920()))
			{
				do
				{
					if (unknown5111e0(aux[j]->unknown457880() != 0 && aux[j]->unknown457880() != 3 ? 17 : 18, aux[j]->unknown571db0(false, false), 0, 0, target, HEntity(), 0, 0))
						consoleA->unknown8758d0(true);
					opw2_consoleB->unknown7b4f10();
				} while (0);
				opw2_mapView->unknown8195a0(pos, aux[j]->unknown457a30(), 2);
			}
			aux[j]->unknown57dbe0(0, 0, 1, 1);
		}
	}
}

bool BS::unknown71f080(const Point &p, int distance)
{
	if (distance > opw2_d20b5c.unknown9b6540())
	{
		if (cells(p)->getItem().isValid())
		{
			if (world->isVisible(p))
			{
				do
				{
					if (unknown5111e0(cells(p)->getItem()->unknown457880() != 0 && cells(p)->getItem()->unknown457880() != 3 ? 17 : 18, cells(p)->getItem()->unknown571db0(false, false), 0, 0, world->unknown4630f0(), HEntity(), 0, 0))
						consoleA->unknown8758d0(true);
					opw2_consoleB->unknown7b4f10();
				} while (0);
				opw2_mapView->unknown8195a0(p, cells(p)->getItem()->unknown457a30(), 2);
			}
			cells(p)->getItem()->unknown57dbe0(0, 0, 1, 1);
		}
		return true;
	}
	vector<Point> adjacent;
	sweepGetSurroundingCells(p, adjacent);
	for (unsigned int i = 0; i < adjacent.size(); i++)
	{
		int d = getDijkstraDistance(adjacent[i]);
		if (d == -1 || d < distance)
			opw2_erasePointStepBack(adjacent, i);
	}
	opw2_shufflePoints(adjacent);
	for (unsigned int j = 0; j < adjacent.size(); j++)
	{
		if (cells(adjacent[j])->hasBlockingObject())
		{
			cells(p)->getItem()->unknown57a0f0(adjacent[j], false, false);
			return true;
		}
	}
	for (unsigned int k = 0; k < adjacent.size(); k++)
	{
		if (cells(adjacent[k])->getItem().isValid())
		{
			int d2 = getDijkstraDistance(adjacent[k]);
			if (d2 != -1 && unknown71f080(adjacent[k], d2 + 1))
			{
				cells(p)->getItem()->unknown57a0f0(adjacent[k], false, false);
				return true;
			}
		}
	}
	if (cells(p)->getItem().isValid())
	{
		if (world->isVisible(p))
		{
			do
			{
				if (unknown5111e0(cells(p)->getItem()->unknown457880() != 0 && cells(p)->getItem()->unknown457880() != 3 ? 17 : 18, cells(p)->getItem()->unknown571db0(false, false), 0, 0, world->unknown4630f0(), HEntity(), 0, 0))
					consoleA->unknown8758d0(true);
				opw2_consoleB->unknown7b4f10();
			} while (0);
			opw2_mapView->unknown8195a0(p, cells(p)->getItem()->unknown457a30(), 2);
		}
		cells(p)->getItem()->unknown57dbe0(0, 0, 1, 1);
	}
	return true;
}

int BS::unknown714b50()
{
	clearDijkstraResults();
	dijkstra.run(target->getPosition(), 50, &dijkstraCost_d21b0c, 0);
	if (dijkstraCells.empty())
		return 0;
	int frame = 0;
	int dy = 0;
	HEntity tmp;
	int height;
	for (unsigned int i = 0; i < dijkstraCells.size(); i++)
	{
		tmp = cells(dijkstraCells[i])->getEntity();
		if (tmp->isHostileTo(target))
		{
			height = tmp->unknown5cd0a0();
			if (tmp->getAI()->unknown458f10())
				height = height * 0.5;
			else
			{
				frame++;
				if (tmp->getAI()->unknown459570(target) && unknown463400(tmp))
					height = height * 1.2;
			}
			height /= 20;
			raiseToMin(height, 1);
			dy += height;
		}
	}
	if (frame == 0)
	{
		dy = 0;
		return 0;
	}
	for (unsigned int j = 0; j < dijkstraCells.size(); j++)
	{
		tmp = cells(dijkstraCells[j])->getEntity();
		if (tmp->unknown45aaa0(target))
		{
			height = tmp->unknown5cd0a0();
			if (tmp->unknown45ac40(58))
				height *= 2;
			height /= 20;
			raiseToMin(height, 1);
			opw2_unknown9d0690(dy, height, 0);
		}
	}
	dy = 2.0 * target->unknown5ca260() / (target->unknown490840() + target->unknown5ca260()) * dy;
	vector<HItem> *turn = target->getInventoryList();
	int points = 0;
	bool cur = false;
	for (unsigned int k = 0; k < turn->size(); k++)
	{
		if ((*turn)[k]->unknown44aec0() <= 3)
			points += (*turn)[k]->unknown457ca0() * (*turn)[k]->unknown4578c0();
		if (!cur && (*turn)[k]->unknown4578a0() == 3 && (*turn)[k]->unknown457d70() && !(*turn)[k]->getEffect(59))
			cur = true;
	}
	if (points / target->getSlotTotal() < 50)
		dy *= 2;
	else if (points / target->getSlotTotal() < 75)
		dy = dy * 1.5;
	if (!cur)
		dy *= 2;
	int robot = target->unknown5d15a0(0);
	if (target->unknown5d1390() == 6)
		dy *= 2;
	else if (robot >= 300)
		dy *= 2;
	else if (robot > 150)
		dy = dy * 1.5;
	else if (robot < 60)
		dy = dy * 0.75;
	else if (robot < 30)
		dy = dy * 0.5;
	int result = 9999999;
	vector<Point> cell;
	for (unsigned int m = 0; m < machines.size(); m++)
	{
		if (machines[m]->unknownd && opw2_cartographer.findPath(target->getPosition(), machines[m]->position, opw2_moveCost, 0, cell) && cell.size() < result)
			result = cell.size();
	}
	if (result != 9999999)
	{
		result = result * robot / 100;
		if (result < 10)
			dy = dy * 0.6;
		else if (result < 20)
			dy = dy * 0.8;
	}
	if (opw2_cf645c || opw2_cf6474)
		dy = dy * 1.2;
	return dy;
}

Point BS::unknown71b5b0(HEntity e, const Point *at)
{
	Point result(-1);
	if (e->getSize() == 1)
	{
		Point p = at ? *at : e->getPosition();
		if ((*fov)(p) == fov->stamp)
			result = p;
	}
	else
	{
		vector<Point> visible;
		if (at)
		{
			for (int y = at->y; y < e->getSize(); y++)
			{
				for (int x = at->x; x < e->getSize(); x++)
				{
					if ((*fov)(x,y) == fov->stamp)
						visible.push_back(Point(x,y));
				}
			}
		}
		else
		{
			vector<Point> *footprint = e->getFootprint();
			for (unsigned int i = 0; i < footprint->size(); i++)
			{
				if ((*fov)((*footprint)[i]) == fov->stamp)
					visible.push_back((*footprint)[i]);
			}
		}
		if (!visible.empty())
		{
			if (visible.size() == 1)
				result = visible.front();
			else
			{
				const Point &helper = target->getPosition();
				int entries;
				int number = 0;
				int dx = opw2_distance(helper, visible[number]);
				for (unsigned int j = 1; j < visible.size(); j++)
				{
					entries = opw2_distance(helper, visible[j]);
					if (entries < dx)
					{
						entries = dx;
						number = j;
					}
				}
				result = visible[number];
				for (unsigned int k = 0; k < visible.size(); k++)
				{
					vector<Point> cell;
					vector<int> range;
					vector<int> outer;
					Point array;
					if (!unknown7170a0(target, visible[k], cell, range, outer, array, 0, 4, true, true))
						opw2_erasePointStepBack(visible, k);
				}
				if (!visible.empty())
				{
					number = 0;
					dx = opw2_distance(helper, visible[number]);
					for (unsigned int m = 1; m < visible.size(); m++)
					{
						entries = opw2_distance(helper, visible[m]);
						if (entries < dx)
						{
							entries = dx;
							number = m;
						}
					}
					result = visible[number];
				}
			}
		}
	}
	return result;
}

void BS::removeMachine(int machineType, const Point &position)
{
	for (unsigned int i = 0; i < goals118[machineType].size(); i++)
	{
		if (goals118[machineType][i] == position)
		{
			erasePointAt(goals118[machineType], i);
			removed138.push_back(position);
			return;
		}
	}
	logWarning("BS::removeMachine()", "Machine type " + intToString(machineType) + " not found at " + pointToString(position));
}

bool BS::unknown7170a0(HEntity e, const Point &p, vector<Point> &path, vector<int> &hits, vector<int> &blocks, Point &last, const Point *at, int atMode, bool f1, bool f2)
{
	int range = at ? atMode : unknown716f60(e, p);
	Point room = at ? *at : e->unknown5c80f0(p);
	const Point &origin = room;
	Point front = effectOrigin;
	if (origin == p)
	{
		path.push_back(origin);
		hits.push_back(0);
		blocks.push_back(0);
		last = effectOrigin;
		return true;
	}
	last.x = last.y = 4;
	if (unknownb04 && !at && range != 4 && !unknown7178d0(e, origin, front, p, last, at != 0))
	{
		int p0 = range == 1 ? cells(p)->getEntity()->unknown45a320() : (range == 2 ? cells(p)->getProp()->unknown45c5f0() : 0);
		Point walker;
		for (int prop = 0; prop < 4; prop++)
		{
			walker.set(opw2_d2ea30(p0,prop).x, opw2_d2ea30(p0,prop).y);
			if (unknown7178d0(e, origin, front, p, walker, at != 0))
			{
				last = walker;
				break;
			}
		}
	}
	Point temp;
	Point helper;
	Bresenham2DStepperSubcell label(origin, front, p, last, 9);
	Point unit;
	bool msg = false;
	if (f1)
	{
		unit = origin;
		path.push_back(origin);
		hits.push_back(0);
		blocks.push_back(0);
		label.next(temp, helper);
		while (temp == origin)
		{
			label.next(temp, helper);
			blocks[blocks.size() - 1]++;
		}
		msg = true;
	}
	else
		unit.set(-1);
	Array2D<int> *steps = 0;
	int pos;
	if (e == target)
	{
		steps = at ? &seen : fov;
		pos = fov->stamp;
	}
	int height;
	int found;
	do
	{
		if (msg)
			msg = false;
		else
			label.next(temp, helper);
		if (unit != temp)
		{
			if (unit.x == -1)
				unit = temp;
			path.push_back(temp);
			hits.push_back(0);
			blocks.push_back(1);
			found = 0;
			if (steps && ((at && seen(temp) == 0) || (!at && (*steps)(temp) != pos)))
			{
				height = 0;
				hits[hits.size() - 1] = 0;
			}
			else if (cells(temp)->unknown45d480())
			{
				height = 0;
				hits[hits.size() - 1] = 3;
			}
			else if (cells(temp)->getEntity().isValid())
			{
				height = cells(temp)->getEntity()->unknown45a320();
				found = 4;
			}
			else if (cells(temp)->getProp().isValid() && cells(temp)->getProp()->unknown45c5f0())
			{
				height = cells(temp)->getProp()->unknown45c5f0();
				found = 2;
			}
		}
		else
			blocks[blocks.size() - 1]++;
		unit = temp;
		if (found != 0 && opw2_d201c8[height](helper))
		{
			hits[hits.size() - 1] = found;
			found = 0;
		}
	} while (temp != p || helper != last);
	for (unsigned int ent = f1 ? 1 : 0; ent < hits.size() - 1; ent++)
	{
		if (hits[ent] != 0)
			return false;
	}
	if (f2)
	{
		hits[hits.size() - 1] = 0;
		return true;
	}
	else
		return hits.back() == 0;
}

int BS::unknown71a940(int *countOut)
{
	vector<HEntity> *members = groups[1]->getMembers();
	int count = 0;
	int total = 0;
	for (unsigned int i = 0; i < members->size(); i++)
	{
		if ((*members)[i]->getFaction() == 9 && !(*members)[i]->getTarget() && opw2_distance(target->getPosition(), (*members)[i]->getPosition()) <= 20)
		{
			int chance = 10;
			for (int j = count; j > 0; j--)
				chance /= 2;
			total += opw2_maxInt(1, chance);
			count++;
		}
	}
	if (countOut)
		*countOut = count;
	return total;
}

void BS::unknown71e080(int x, int y)
{
	const string &test = cells(x,y)->getProp()->unknown45c5b0();
	bool success = cells(x,y)->getProp()->unknown45c650() == -21;
	int id = 0;
	if (y - 1 >= 0 && cells(x,y - 1)->getProp().isValid() && cells(x,y - 1)->getProp()->unknown45c5b0() == test)
		id++;
	if (y + 1 < cells.getHeight() && cells(x,y + 1)->getProp().isValid() && cells(x,y + 1)->getProp()->unknown45c5b0() == test)
		id += 20;
	if (x - 1 >= 0 && cells(x - 1,y)->getProp().isValid() && cells(x - 1,y)->getProp()->unknown45c5b0() == test)
		id += 300;
	if (x + 1 < cells.getWidth() && cells(x + 1,y)->getProp().isValid() && cells(x + 1,y)->getProp()->unknown45c5b0() == test)
		id += 4000;
	if (id == 0)
	{
		if (y - 1 >= 0 && !cells(x,y - 1)->isPassableFor(HEntity()))
			id++;
		if (y + 1 < cells.getHeight() && !cells(x,y + 1)->isPassableFor(HEntity()))
			id += 20;
		if (x - 1 >= 0 && !cells(x - 1,y)->isPassableFor(HEntity()))
			id += 300;
		if (x + 1 < cells.getWidth() && !cells(x + 1,y)->isPassableFor(HEntity()))
			id += 4000;
	}
	switch (id)
	{
		case 1:
		case 20:
		case 21:
			cells(x,y)->getProp()->setState(128);
			break;
		case 300:
		case 4000:
		case 4300:
			cells(x,y)->getProp()->setState(129);
			break;
		case 4020:
			cells(x,y)->getProp()->setState(136);
			break;
		case 320:
			cells(x,y)->getProp()->setState(137);
			break;
		case 4001:
			cells(x,y)->getProp()->setState(135);
			break;
		case 301:
			cells(x,y)->getProp()->setState(138);
			break;
		case 4301:
			cells(x,y)->getProp()->setState(132);
			break;
		case 4320:
			cells(x,y)->getProp()->setState(134);
			break;
		case 321:
			cells(x,y)->getProp()->setState(131);
			break;
		case 4021:
			cells(x,y)->getProp()->setState(133);
			break;
		case 4321:
			cells(x,y)->getProp()->setState(130);
			break;
		case 0:
			cells(x,y)->getProp()->setState(139);
			break;
	}
}

struct OpW2_Rec	// NOTE: placeholder name
{
	char	pad0[0x2c];
	int		unknown2c;	// NOTE: placeholder name
	int		unknown30;	// NOTE: placeholder name
};

class OpW2_D2d1c4	// NOTE: placeholder name
{
public:
	int unknown457620();	// NOTE: placeholder name
};

class OpW2_D25de0	// NOTE: placeholder name
{
public:
	int unknown4598b0();	// NOTE: placeholder name
	int unknown4598d0();	// NOTE: placeholder name
};

class OpW2_Options	// NOTE: placeholder name
{
public:
	int getDepthIndex();						// NOTE: placeholder name
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
};

struct OpW2_Six	// NOTE: placeholder name
{
	bool	c[6];
};

extern int					opw2_caf160;	// NOTE: placeholder name
extern int					opw2_caf164;	// NOTE: placeholder name
extern int					opw2_cf4740;	// NOTE: placeholder name
extern int					opw2_cf4718;	// NOTE: placeholder name
extern OpW2_Options			opw2_d1e860;	// NOTE: placeholder name
extern vector<OpW2_Rec *>	opw2_d35b58;	// NOTE: placeholder name
extern vector<OpW2_D2d1c4 *>	opw2_d2d1c4;	// NOTE: placeholder name
extern vector<OpW2_D25de0 *>	opw2_d25de0;	// NOTE: placeholder name
extern int					opw2_b9ade4[];	// NOTE: placeholder name
extern int					opw2_b9adf8[];	// NOTE: placeholder name
extern int					opw2_b9afb8[];	// NOTE: placeholder name
extern OpW2_Six				opw2_b9b17b[];	// NOTE: placeholder name
extern const float			opw2_b99d44;	// NOTE: placeholder name
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
int opw2_clampInt(int low, int value, int high);	// NOTE: placeholder name (0x9cdc80)

// NOTE: its two sparse switches lay out as dword1, bytes1, dword2, bytes2 (lverify handles this).
int BS::unknown71adc0(HEntity attacker, HProp target, OpW2_WeaponRef *weapon, int type, int index, OpW2_ItemType *itemType, OpW2_Other *other, HItem item, bool flag)
{
	if (target->unknown9b8f00()->unknownf8 >= 6)
		return 100;
	switch (weapon ? weapon->type : type)
	{
		case 0x42:
			if (!flag)
				break;
		case 0x43:
			if (attacker->unknown5d3f80(itemType ? itemType->id : opw2_caf164, other ? other->id : opw2_caf160).isValid())
				return 100;
			break;
		case 0x63:
			if (opw2_cf4740 != 0 || stringToInt(opw2_d1e860.unknown46f6d0("installedRif_g")))
				return 100;
			break;
		case 0x64:
		case 0x65:
			if (stringToInt(opw2_d1e860.unknown46f6d0("installedRif_g")))
				return 100;
			break;
	}
	OpW2_PropData *choices = target->unknown45cb30();
	unsigned int m2;
	int roll = weapon ? (weapon->type == 0 ? opw2_b9ade4[opw2_d35b58[weapon->index]->unknown30] : opw2_b9adf8[weapon->type]) : (type == 0 ? opw2_b9ade4[opw2_d35b58[index]->unknown30] : opw2_b9adf8[type]);
	if (roll == -1)
	{
		switch (weapon ? weapon->type : type)
		{
			case 1:
				roll = opw2_d2d1c4[weapon ? weapon->index : index]->unknown457620();
				break;
			case 2:
				roll = opw2_d25de0[weapon ? weapon->index : index]->unknown4598b0();
				break;
			case 3:
				roll = opw2_d25de0[weapon ? weapon->index : index]->unknown4598d0();
				break;
			case 5:
				for (m2 = 0; m2 < choices->entries.size(); m2++)
				{
					if (choices->entries[m2]->type == 5)
					{
						roll = opw2_b9ade4[choices->entries[m2]->value];
						goto found;
					}
				}
				roll = -999;
			found:
				break;
			case 0x43:
				roll = itemType ? itemType->unknown457490() : other->unknown459890();
				break;
			case 0x4d:
				roll = item->unknown9b4350()->unknown457490();
				break;
			case 0x5f:
				roll = item->unknown9b4350()->unknown457550();
				break;
		}
	}
	if (choices->unknownc != 0)
		roll /= pow(2.0f, choices->unknownc - 1);
	OpW2_Rec *inner = (weapon ? weapon->type : type) == 0 ? opw2_d35b58[weapon ? weapon->index : index] : 0;
	if (inner)
	{
		if (opw2_d1e860.getDepthIndex() < inner->unknown2c)
			roll -= (inner->unknown2c - opw2_d1e860.getDepthIndex()) * 15;
		else
			roll += (opw2_d1e860.getDepthIndex() - inner->unknown2c) * 10;
	}
	if (!weapon && !opw2_b9b17b[type].c[0])
		roll -= (type ? 15 : 5) * choices->unknownc;
	if (opw2_b9afb8[weapon ? weapon->type : type] != 0)
		roll -= values208[weapon ? weapon->type : type] * opw2_b9afb8[weapon ? weapon->type : type];
	if (target->unknown9b8f00()->unknownf8 == 0 && choices->unknown3c > 0)
	{
		if (roll <= 0)
			roll = 0;
		else
			roll = roll * opw2_b99d44;
	}
	if (target->unknown45c800(9))
		roll += target->unknown45c870(9);
	roll += unknown71a940(0);
	roll += unknown71aa80(target, 0);
	roll += attacker->unknown5c7f10();
	roll -= attacker->unknown5cab90() / 3;
	if (opw2_cf4718 == 2 && weapon && weapon->type == 0)
		roll = 100;
	return opw2_clampInt(0, roll, 100);
}
