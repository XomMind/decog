// op_x4d: BS (0xcefc4c) methods in 0x6ea660-0x6ff270 matched against COGMIND.exe (Beta 17.1).
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

struct Area;
class HProp;

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(const Point &p);
	T &operator()(int x, int y);
	Area getArea();	// NOTE: placeholder name (0x9b4400)
	void getRect(const Point &p, int radius, Area &out);	// NOTE: placeholder name (0x9b4430)
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
	bool contains(int x, int y);	// NOTE: placeholder name (0x9b45c0)
	int getWidth();					// NOTE: placeholder name (0x9fcd80)
	int getLastY();					// NOTE: placeholder name (0x9b4390)
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
	bool isNull() const;	// NOTE: placeholder name (folded with HProp::isNull 0x9b65d0)
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
	void disableMachine();	// 0x65ed00
	int unknown45c800(int type);			// NOTE: placeholder name
	int unknown45ca00(int type);			// NOTE: placeholder name
	void unknown45ce10(bool a, bool b, bool c, HProp d);	// NOTE: placeholder name
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
	HProp();
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

class OpW2_Machine;

class OpW2_HMachine	// NOTE: placeholder name
{
	int	ID;
public:
	OpW2_HMachine();	// NOTE: folded with 0x9b6590
	bool isValid() const;	// 0x9b7230
	OpW2_Machine *operator->() const;	// 0x9b7910
};

class OpW2_Machine	// NOTE: placeholder name
{
public:
	bool unknown46ecb0();	// NOTE: placeholder name
	int getDepthIndex();	// NOTE: placeholder name

	int		unknown0;
	int		type;	// NOTE: placeholder name
	int		depth;	// NOTE: placeholder name
	vector<OpW2_HMachine>	children;	// 0xc	NOTE: placeholder name
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
	int unknown9b8f00();	// NOTE: placeholder name (folded getter)
	void setFollowEntity(HEntity followEntity, int followParam);	// 0x5b2f80
	void unknown4593d0(vector<Point> &path);	// NOTE: placeholder name
	void unknown451930(int value);	// NOTE: placeholder name
	void unknown459540(const Point &p);	// NOTE: placeholder name
	void unknown4593f0(bool flag);	// NOTE: placeholder name
	void unknown459410(const Area &area);	// NOTE: placeholder name
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
	void unknown45e4a0(int value);	// NOTE: placeholder name
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
	bool unknown637da0(int count, int id, struct OpW2_Attack *attack, Point &p);	// NOTE: placeholder name
	bool unknown5d51a0();				// NOTE: placeholder name
	bool unknown45aaa0(HEntity e);		// NOTE: placeholder name
	int getAiType();					// 0x45a2a0
	bool unknown5cb680(OpW2_HGroup g);	// NOTE: placeholder name
	void name45b070(const string &name);	// NOTE: placeholder name (retail 0x45b070 takes const string&; config row is the char* mangling)
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
	void unknown66a050(int terrainID, int cause, int unknown);	// NOTE: placeholder name
	void unknown66b660();	// NOTE: placeholder name
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
	bool unknown6701c0(int count, int id, struct OpW2_Attack *attack);	// NOTE: placeholder name
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
void logError(string location, string message);	// NOTE: placeholder name (0x404f10)
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
	int unknown789090();	// NOTE: placeholder name
	void setEntryText(const string &key, const string &text);	// NOTE: placeholder name (0x46f700)
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


struct OpX4d_Node	// NOTE: placeholder name
{
	int pad0;
	int pad4;
	int depth;
};
class OpX4d_HNode	// NOTE: placeholder name
{
	int ID;
public:
	OpX4d_HNode();	// NOTE: folded with 0x9b6590
	OpX4d_Node *operator->() const;	// 0x9b7910
};
extern OpX4d_HNode opX4d_node_d1e884;	// NOTE: placeholder name
bool opX4d_findNode_470180(int type, int ID, OpX4d_HNode node, OpX4d_HNode *result);	// NOTE: placeholder name
extern bool opX4d_flag_d1eabc;	// NOTE: placeholder name
extern bool opX4d_flag_d1eabd;	// NOTE: placeholder name
HEntity opX4d_unknown6fcf90(bool flag);	// NOTE: placeholder name (0x6fcf90)
extern OpX4d_HNode opX4d_node;	// NOTE: placeholder name (0xd1e888)
struct OpX4d_Terrain;
extern OpX4d_Terrain *opX4d_terrain_cefb88;	// NOTE: placeholder name
extern bool opX4d_flag_d1eaac;	// NOTE: placeholder name
extern bool opX4d_flag_d1eaad;	// NOTE: placeholder name
extern Cartographer2DMoveCost *opX4d_moveCost_cefc44;	// NOTE: placeholder name
extern XColor *opX4d_colorBlack;	// NOTE: placeholder name (0xcfe674)
void opX4d_unknown6c9c90(const Point &p, OpX4d_Terrain *terrain);	// NOTE: placeholder name (0x6c9c90)
bool opX4d_unknown6fcc60(bool flag);	// NOTE: placeholder name (0x6fcc60)

struct Area	// NOTE: placeholder name
{
	Point min;
	Point max;

	Area();	// 0x40b100
	void set(int x1, int y1, int x2, int y2);	// NOTE: placeholder name (0x40b300)
	void randomPoint_40be30(Point *out);	// NOTE: placeholder name
	Point randomPoint_40be90();	// NOTE: placeholder name
};

struct OpQ1_Box : Area	// NOTE: placeholder name (retail 0x40b1e0 is configured as OpQ1_Box(int,int,int,int))
{
	OpQ1_Box(int x1, int y1, int x2, int y2);	// 0x40b1e0
};

struct OpQ5_U9d7530	// NOTE: placeholder name
{
	int pad;
	string name;
};
template <class T> bool OpQ5_findByName(vector<T *> &v, const string &name, T *&result);	// NOTE: placeholder name (0x9d7530 for OpQ5_U9d7530)
extern vector<OpQ5_U9d7530 *> opX4d_entityRecords;	// NOTE: placeholder name (0xd25de0)
struct EntityRecord;
class OpX4d_PlayerData	// NOTE: placeholder name
{
public:
	int unknown46e150();	// NOTE: placeholder name
};
extern OpX4d_PlayerData opX4d_playerData;	// NOTE: placeholder name (0xcf45d8)
class OpX4d_Overmind	// NOTE: placeholder name (Overmind at 0xcf6428)
{
public:
	void spawnPatrolParty(HProp a, int b, int c, int d, Point *e, int f, int g, int h, int i);	// 0x6896d0
};
extern OpX4d_Overmind opX4d_overmind;	// NOTE: placeholder name
struct OpX4d_Entry	// NOTE: placeholder name
{
	int value;
};
extern vector<OpX4d_Entry> opX4d_entries_cf4a24;	// NOTE: placeholder name
extern int opX4d_cf4724;	// NOTE: placeholder name
extern int opX4d_table_b905d8[];	// NOTE: placeholder name
extern vector<OpW2_HMachine> opX4d_nodes_d1e88c;	// NOTE: placeholder name
extern vector<vector<HProp> > opX4d_props_d31640;	// NOTE: placeholder name
extern vector<int> opX4d_ints_d33a90;	// NOTE: placeholder name
extern vector<int> opX4d_ints_d33aa0;	// NOTE: placeholder name
extern vector<string> opX4d_strings_d33ab0;	// NOTE: placeholder name
HEntity opX4d_unknown6fd950(OpQ5_U9d7530 *record, int group, bool flag);	// NOTE: placeholder name (0x6fd950)
void opX4d_unknown5141b0(int id, const string *text, int a, int b, HProp e, int c);	// NOTE: placeholder name (0x5141b0)
struct OpQ5_U9db510	// NOTE: placeholder name
{
	int ID;
	string name;
};
struct OpQ5_U9d7de0	// NOTE: placeholder name
{
	int ID;
	string name;
};
extern vector<OpQ5_U9db510 *> opX4d_records_d2f0f8;	// NOTE: placeholder name
extern vector<OpQ5_U9d7de0 *> opX4d_records_d2c408;	// NOTE: placeholder name
struct OpX4d_Terrain	// NOTE: placeholder name
{
	int ID;
};
extern OpX4d_Terrain *opX4d_terrain_cefb9c;	// NOTE: placeholder name
void opX4d_message(int type, HEntity entity, const string &text, int value);	// NOTE: placeholder name (0x49c610)
Point opX4d_randomPoint(vector<Point> &v);	// NOTE: placeholder name (0x9d5350)
extern vector<HEntity> opX4d_entities_d1ec00;	// NOTE: placeholder name
extern vector<Point> opX4d_points_d1ec10;	// NOTE: placeholder name
bool opR4_isEntrance(const Point &p);	// NOTE: placeholder name (0x448b80)

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
	vector<OpW2_MachineRecord *> *unknown462e10();	// NOTE: placeholder name
	int unknown463910(OpW2_HGroup a, OpW2_HGroup b);
	OpW2_HGroup unknown463890(int index);	// NOTE: placeholder name
	void unknown74d560(int faction, int other, int value, XColor color);	// NOTE: placeholder name
	HEntity unknown4630f0();	// NOTE: placeholder name (Map::getPlayer)
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name	// NOTE: placeholder name (Map::unknown463910)

	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name (0x71c150)
	HEntity placeEntity(EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);	// 0x6c58c0
	bool unknown6c6b90(const Point &p, const string &type, int a, int b);	// NOTE: placeholder name
	void unknown6c65a0(HEntity e, const string &text, int value);
	HItem giveItem(const string &name, HEntity e, int a, int b);	// NOTE: placeholder name (0x6c52b0)
	HEntity unknown6c5dc0(const string &name, const Point &pos, int a, int b, int c, int d, int e);
	void unknown6f1990();
	void unknown6ef730();
	void unknown6f1c70();
	void unknown6ed0b0();
	OpW2_MachineRecord *unknown6f0ca0();
	bool unknown6f0f80(HEntity &zhirov, HEntity &perun, HEntity &svarog);
	void unknown6ff270();
	void unknown6ea660();
	void unknown6fd470();

	char					pad0[8];
	Point					point8;				// 0x8	NOTE: placeholder name
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
	vector<HEntity>			entitiesa20;		// 0xa20	NOTE: placeholder name
	vector<OpW2_HObject>	objectsa30;			// 0xa30	NOTE: placeholder name
	vector<vector<int> >	valuesa40;			// 0xa40	NOTE: placeholder name
	vector<int>				keysa50;			// 0xa50	NOTE: placeholder name
	vector<OpW2_EntityRecord *>	recordsa60;		// 0xa60	NOTE: placeholder name
	unsigned int			unknowna70;			// 0xa70	NOTE: placeholder name
	char					pada74[0xb04 - 0xa74];
	bool					unknownb04;			// 0xb04	NOTE: placeholder name
};


void BS::unknown6f1990()
{
	HEntity b;
	HEntity c;
	HEntity second;
	for (unsigned int i = 0; i < groups[2]->getMembers()->size(); i++)
	{
		switch ((*groups[2]->getMembers())[i]->getFaction())
		{
		case 0x56:
			b = (*groups[2]->getMembers())[i];
			break;
		case 0x57:
			c = (*groups[2]->getMembers())[i];
			break;
		case 0x58:
			second = (*groups[2]->getMembers())[i];
			break;
		}
	}
	if (b.isValid())
	{
		unknown6c65a0(b,"COM_Zhirov_Leave_Talk",0);
		unknown6c65a0(b,"COM_Zhirov_Teleport_Out",0);
	}
	if (c.isValid())
		unknown6c65a0(c,"COM_Zhirov_Teleport_Out",0);
	if (second.isValid())
		unknown6c65a0(second,"COM_Zhirov_Teleport_Out",0);
}

void BS::unknown6f1c70()
{
	int count1;
	int cnt;
	unknown715420(20,count1,cnt);
	if (stringToInt(gameData.unknown46f6d0("datDataConduitDownloaded_g")) || count1 >= 3)
	{
		OpQ5_U9d7530 *record;
		if (OpQ5_findByName(opX4d_entityRecords,"Enhanced Programmer",record))
		{
			OpQ1_Box spot(0,50,160,cells.getLastY());
			Point pos;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 100; j++)
				{
					spot.randomPoint_40be30(&pos);
					if (findPlaceableNear(pos,pos,1) && !opR4_isEntrance(pos) && unknown716940(pos,point8,NULL,NULL))
					{
						HEntity placed = placeEntity(reinterpret_cast<EntityRecord *>(record),pos,12,true,0x22,0xe,false);
						break;
					}
				}
			}
		}
	}
}

void BS::unknown6ed0b0()
{
	vector<Point> spots;
	spots.push_back(Point(0x92,0x4c));
	spots.push_back(Point(0x92,0x4e));
	spots.push_back(Point(0x92,0x50));
	spots.push_back(Point(0x93,0x50));
	for (unsigned int i = 0; i < spots.size(); i++)
	{
		if (cells(spots[i])->getEntity().isValid())
			entitiesa20.push_back(cells(spots[i])->getEntity());
		else
		{
			entitiesa20.clear();
			break;
		}
	}
	vector<HEntity> *members = groups[3]->getMembers();
	for (unsigned int j = 0; j < members->size(); j++)
	{
		if ((*members)[j]->getAI()->unknown9b8f00() == 1 && (*members)[j]->getFaction() != 0x5f)
		{
			opX4d_entities_d1ec00.push_back((*members)[j]);
			opX4d_points_d1ec10.push_back((*members)[j]->getPosition());
		}
	}
	unknown6c6b90(Point(0x72,0x49),"COM_Conduit_RIF",0,-1);
	unknown6c6b90(Point(0x72,0x4a),"COM_Conduit_RIF",0,-1);
	unknown6c6b90(Point(0x73,0x4b),"COM_Conduit_RIF",0,-1);
	unknown6c6b90(Point(0x74,0x4b),"COM_Conduit_RIF",0,-1);
}

OpW2_MachineRecord *BS::unknown6f0ca0()
{
	Area area;
	OpQ5_U9db510 *openWall;
	OpQ5_findByName(opX4d_records_d2f0f8,"MIN_Open_Wall_EXI",openWall);
	OpQ5_U9d7de0 *triggerType;
	OpQ5_findByName(opX4d_records_d2c408,"MIN_Wall_Open_Trigger",triggerType);
	for (unsigned int i = 0; i < machines.size(); i++)
	{
		if (machines[i]->machine->type == 8)
		{
			cells.getRect(machines[i]->position,10,area);
			for (int x = area.min.x; x <= area.max.x; x++)
			{
				for (int y = area.min.y; y <= area.max.y; y++)
				{
					if (cells(x,y)->getProp().isValid())
					{
						if (cells(x,y)->getProp()->unknown45c800(openWall->ID))
						{
							cells(x,y)->unknown66a050(opX4d_terrain_cefb9c->ID,2,0);
							cells(x,y)->getProp()->unknown45ce10(true,false,true,HProp());
						}
						else if (cells(x,y)->getProp()->unknown45ca00(triggerType->ID))
							cells(x,y)->getProp()->unknown45ce10(true,false,true,HProp());
					}
				}
			}
			return machines[i];
		}
	}
	return NULL;
}

bool BS::unknown6f0f80(HEntity &zhirov, HEntity &perun, HEntity &svarog)
{
	zhirov = unknown6c5dc0("Zhirov",target->getPosition(),2,1,0x22,0xe,0);
	if (zhirov.isNull())
		return false;
	giveItem("Deep Network Scanner",zhirov,0,0);
	giveItem("Quantum Router",zhirov,0,0);
	giveItem("Transdimensional Reconstructor",zhirov,0,0);
	giveItem("Zhirov Special",zhirov,0,0);
	if (stringToInt(gameData.unknown46f6d0("zhiPerunDead_g")) == 0)
		perun = unknown6c5dc0("Perun",zhirov->getPosition(),2,1,0x22,0xe,0);
	if (stringToInt(gameData.unknown46f6d0("zhiSvarogDead_g")) == 0)
		svarog = unknown6c5dc0("Svarog",zhirov->getPosition(),2,1,0x22,0xe,0);
	zhirov->getAI()->setFollowEntity(target,2);
	if (perun.isValid())
		perun->getAI()->setFollowEntity(target,2);
	if (svarog.isValid())
		svarog->getAI()->setFollowEntity(target,2);
	return true;
}

void BS::unknown6ff270()
{
	bool spoken = false;
	int count = 0;
	int group;
	for (unsigned int i = 0; i < opX4d_ints_d33a90.size(); i++)
	{
		group = opX4d_ints_d33aa0[i];
		HEntity e = opX4d_unknown6fd950(opX4d_entityRecords[opX4d_ints_d33a90[i]],group,!target->unknown5cb680(groups[group]));
		if (e.isValid())
		{
			e->name45b070(opX4d_strings_d33ab0[i]);
			if (e->unknown45aaa0(target))
			{
				count++;
				e->getAI()->setFollowEntity(unknown4630f0(),0);
				if (!spoken && e->getAiType() == 3 && (e->getFaction() == 0x10 || e->getFaction() == 0x11 || e->getFaction() == 0x18 || e->getFaction() == 0x19))
				{
					unknown6c65a0(e,"WAS_Derelict_Victim",0);
					spoken = true;
				}
			}
		}
	}
	if (count)
	{
		string text = intToString(count);
		if (count == 1)
			text += " ally";
		else
			text += " allies";
		do { opX4d_unknown5141b0(0x189,&text,0,0,HProp(),0); } while (0);
	}
	opX4d_ints_d33a90.clear();
	opX4d_ints_d33aa0.clear();
	opX4d_strings_d33ab0.clear();
}

void BS::unknown6ea660()
{
	if (rng.chance(15))
	{
		HEntity valguris = world->unknown6c5dc0("VL-GR5",point8,9,1,0x1b,0xe,0);
		if (valguris.isNull())
			return;
		vector<Point> path;
		Point tile;
		OpQ1_Box area(0,0,cells.getWidth() / 3,cells.getHeight() - 1);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; i < 100; j++)
			{
				tile = area.randomPoint_40be90();
				if (cells(tile)->isPassableFor(HEntity()) && unknown716940(point8,tile,NULL,NULL))
				{
					path.push_back(tile);
					break;
				}
			}
		}
		area.set(cells.getWidth() / 3,0,cells.getWidth() / 3 * 2,cells.getHeight() - 1);
		for (int k = 0; k < 2; k++)
		{
			for (int m = 0; k < 100; m++)
			{
				tile = area.randomPoint_40be90();
				if (cells(tile)->isPassableFor(HEntity()) && unknown716940(point8,tile,NULL,NULL))
				{
					path.push_back(tile);
					break;
				}
			}
		}
		valguris->getAI()->unknown4593d0(path);
		valguris->getAI()->unknown451930(0);
		unknown6c65a0(valguris,"ARM_Valguris_Greet",0);
		unknown6c65a0(valguris,"ARM_Valg_Kills",0);
		unknown6c65a0(target,"ARM_Valg_Cogmind_Kills",0);
		unknown6c65a0(valguris,"ARM_Valg_Check_Kills",0);
		unknown6c65a0(valguris,"ARM_Valg_Check_Immobile",0);
		unknown6c65a0(valguris,"ARM_Valg_Check_Disarmed",0);
		unknown6c65a0(valguris,"ARM_Valg_Death",0);
	}
}

bool opX4d_unknown6fcc60(bool flag)
{
	if (!opX4d_flag_d1eaac || (opX4d_flag_d1eaad && !flag) || (!opX4d_flag_d1eaad && flag))
		return false;
	if (opX4d_node->depth == 10)
	{
		Point target2 = world->unknown714120(15);
		if (target2.x != -1)
		{
			vector<Point> path;
			if (!opw2_cartographer.findPath(world->unknown4184d0(),target2,opX4d_moveCost_cefc44,NULL,path))
			{
			}
			else
			{
				for (unsigned int i = 0; i < path.size(); i++)
				{
					if (!cells(path[i])->isPassableFor(HEntity()))
						opX4d_unknown6c9c90(path[i],opX4d_terrain_cefb88);
				}
			}
			world->unknown74d560(13,2,2,*opX4d_colorBlack);
			world->unknown463890(13)->unknown45e4a0(1);
			HEntity leader;
			OpQ5_U9d7530 *fedRecord;
			if (OpQ5_findByName(opX4d_entityRecords,"Federalist",fedRecord))
			{
				for (int n = rng.rangeInt(5.0f,6.0f); n > 0; n--)
				{
					HEntity e = world->placeEntity(reinterpret_cast<EntityRecord *>(fedRecord),world->unknown4184d0(),13,true,0x19,0xe,false);
					e->getAI()->unknown459540(target2);
					e->getAI()->unknown4593f0(true);
					if (leader.isNull())
						leader = e;
					else
						e->getAI()->setFollowEntity(leader,0);
				}
				world->unknown6c65a0(world->unknown4630f0(),"MAT_Fedparty_Control",0);
				return true;
			}
		}
	}
	return false;
}

HEntity opX4d_unknown6fcf90(bool flag)
{
	if (!opX4d_flag_d1eabc || (opX4d_flag_d1eabd && !flag) || (!opX4d_flag_d1eabd && flag))
		return HEntity();
	OpX4d_HNode node;
	if (opX4d_findNode_470180(8,-1,opX4d_node_d1e884,&node))
	{
		if (node->depth == opX4d_node->depth)
		{
			OpW2_MachineRecord *exitMin = NULL;
			OpW2_MachineRecord *b = NULL;
			unsigned int dist1;
			unsigned int n2;
			vector<Point> path;
			vector<OpW2_MachineRecord *> *list = world->unknown462e10();
			for (unsigned int m2 = 0; m2 < list->size(); m2++)
			{
				switch ((*list)[m2]->machine->type)
				{
				case 2:
					path.clear();
					if (opw2_cartographer.findPath(world->unknown4184d0(),(*list)[m2]->position,opw2_moveCost,NULL,path))
					{
						if (exitMin == NULL || path.size() > dist1)
						{
							exitMin = (*list)[m2];
							dist1 = path.size();
						}
					}
					break;
				case 7:
					path.clear();
					if (opw2_cartographer.findPath(world->unknown4184d0(),(*list)[m2]->position,opw2_moveCost,NULL,path))
					{
						if (b == NULL || path.size() < n2)
						{
							b = (*list)[m2];
							n2 = path.size();
						}
					}
					break;
				}
			}
			if (exitMin == NULL || b == NULL)
			{
				logError("checkMaterialsBrawnSpawn()","not enough suitable exits");
				return HEntity();
			}
			HEntity b2 = world->unknown6c5dc0("8R-AWN",exitMin->position,9,1,0x19,0xe,0);
			if (b2.isNull())
			{
			}
			else
			{
				gameData.setEntryText("matSpawnedBrawn_g","1");
				b2->getAI()->unknown459540(b->position);
				world->unknown6c65a0(b2,"EXI_Brawn_Dialogue_MAT",0);
				world->unknown6c65a0(b2,"EXI_Brawn_Score_MAT",0);
				world->unknown6c65a0(b2,"EXI_Brawn_Death",0);
			}
			return b2;
		}
	}
	return HEntity();
}

void BS::unknown6fd470()
{
	opX4d_unknown6fcc60(false);
	opX4d_unknown6fcf90(false);
	if (opX4d_node->depth == 8 && rng.chance(5))
	{
		vector<Point> candidates;
		for (unsigned int i = 0; i < machines.size(); i++)
		{
			if (opw2_distance(target->getPosition(),machines[i]->position) >= 20)
				candidates.push_back(machines[i]->position);
		}
		Point pos = candidates.empty() ? Point(opw2_randomElement(machines)->position) : opX4d_randomPoint(candidates);
		HEntity e = world->unknown6c5dc0("7R-MNS",pos,9,1,3,0xe,0);
		if (e.isNull())
		{
		}
		else
		{
			e->getAI()->unknown459410(cells.getArea());
			e->getAI()->unknown451930(0x23);
			unknown6c65a0(e,"MAT_Terminus_Greet",0);
			unknown6c65a0(e,"MAT_Term_Kills",0);
			unknown6c65a0(e,"MAT_Term_New_Map",0);
			unknown6c65a0(e,"MAT_Term_Talk_Wep_Slots",0);
			unknown6c65a0(e,"MAT_Term_Check_Immobile",0);
			unknown6c65a0(e,"MAT_Term_Check_Disarmed",0);
			unknown6c65a0(e,"MAT_Term_Death",0);
			opX4d_message(0x320,HEntity(),string("Distant sounds of combat echo through the corridors."),0);
			gameData.setEntryText("matSpawnedTerminus_g","1");
		}
	}
}

void BS::unknown6ef730()
{
	int count = gameData.unknown789090() - 1;
	if (count != 0)
	{
		for (int i = 0; i < count; i++)
			opX4d_overmind.spawnPatrolParty(HProp(),1,0,0,0,rng.rangeInt(2.0f,3.0f),0,6,1);
	}
	if (opX4d_cf4724 != 0 && !opX4d_entries_cf4a24.empty() && opX4d_entries_cf4a24.back().value == opw2_gameState->depth)
	{
		for (unsigned int j = 0; j < opX4d_props_d31640.size(); j++)
		{
			if (!opX4d_props_d31640[j].empty() && opX4d_props_d31640[j].front()->unknown45c590() == "GAR_RIF_Installer" && opX4d_props_d31640[j].front()->unknown457b10() != 1)
				opX4d_props_d31640[j].front()->disableMachine();
		}
	}
	if (opX4d_table_b905d8[opX4d_nodes_d1e88c[opX4d_nodes_d1e88c.size() - 2]->type] != 0 || machines[0]->machine->depth != opw2_gameState->depth || opX4d_cf4724 != 0)
		return;
	if ((opX4d_entries_cf4a24.size() >= 1 && opX4d_entries_cf4a24.back().value == opw2_gameState->depth) || (opX4d_playerData.unknown46e150() >= 3 && rng.chance(50)) || (count != 0 && stringToInt(gameData.unknown46f6d0("installedRif_g")) == 0 && rng.chance(50)))
	{
		OpW2_HMachine chosen;
		vector<OpW2_HMachine> list = opX4d_nodes_d1e88c[opX4d_nodes_d1e88c.size() - 2]->children;
		for (unsigned int i = 0; i < list.size(); i++)
		{
			if (list[i]->unknown46ecb0())
			{
				chosen = list[i];
				break;
			}
		}
		if (chosen.isValid())
		{
			opw2_gameState->children.clear();
			opw2_gameState->children.push_back(chosen);
			for (unsigned int j = 0; j < machines.size(); j++)
			{
				machines[j]->machine = chosen;
				if (chosen->unknown46ecb0())
					cells(machines[j]->position)->unknown66b660();
			}
		}
	}
}
