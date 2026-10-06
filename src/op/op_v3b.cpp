// op_v3b: BattleScape (BS) methods in 0x6ef730-0x7469f0 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members, member names and method names are placeholders
//	unless stated otherwise.
#include <string>
#include <vector>
#include "../util/stringutil.h"
using namespace std;
#include "../util/rng.h"
extern RNG rng;	// 0xd30908

//==================================================================
// declarations
//==================================================================

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);	// 0x411f10
	bool operator!=(XColor color);	// 0x411f90
};
extern XColor &COLOR_BLACK;	// 0xcfe674, NOTE: placeholder name

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(int x_, int y_);
	Point(const Point &p);	// 0x46ca50
	explicit Point(int v);	// 0x409990
	int randomInRange_40c130();	// NOTE: placeholder name
	bool opW4_is(int x_, int y_);	// NOTE: placeholder name (0x409cb0)
	Point &operator+=(const Point &p);	// 0x409a30
	Point &operator-=(const Point &p);	// 0x409a70
	Point &operator=(const Point &p);	// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
	void set(int x_, int y_);	// 0x40a010
	bool contains_40c190(int v);	// NOTE: placeholder name
};

struct OpW4_Area	// NOTE: placeholder name
{
	Point min;
	Point max;

	OpW4_Area();	// 0x40b100
	OpW4_Area &operator=(const OpW4_Area &a);	// 0x40b130
	OpW4_Area(const OpW4_Area &a);	// 0x40b130 (folded with operator=)
	void randomPoint_40be30(Point *out);	// NOTE: placeholder name
};

struct Rect	// NOTE: placeholder name
{
	int x1;
	int y1;
	int x2;
	int y2;
};

namespace Protobuf {
// NOTE: the exe's ICF folded this getter with unrelated game getters, so calls carry this name
class PingRequest
{
public:
	virtual int GetCachedSize() const;	// 0x9b4350
};
}

class HEntity;
class Group : public Protobuf::PingRequest	// NOTE: placeholder name
{
public:
	void unknown671940(int a, int b);	// NOTE: placeholder name
	void unknown45e480(int value);	// NOTE: placeholder name (adds to the field at +0x24)
	void unknown45e4c0();	// NOTE: placeholder name
	void unknown45e440(int value);	// NOTE: placeholder name

	vector<HEntity> *getMembers();	// NOTE: placeholder name (0x416f40, folded getter)
	HEntity unknown45e250(int type);	// NOTE: placeholder name

	char pad04[0x2c - 0x04];
	vector<XColor> colors;	// NOTE: placeholder name
};

class Entity;
class HItem
{
public:
	int ID;
	HItem();
	bool isValid() const;
};

class HEntity : public HItem	// NOTE: placeholder layout
{
public:
	HEntity();
	Entity *operator->() const;	// 0x9b6570
	bool operator==(HEntity other) const;	// 0x9b78e0
	bool operator!=(HEntity other) const;	// 0x9b6510
	bool isNull() const;	// 0x9b65d0
};

class HProp;
class HItemB;
class Prop	// NOTE: placeholder name
{
public:
	int unknown45c9b0();	// NOTE: placeholder name
	const string &unknown45c590();	// NOTE: placeholder name (the prop's tag)
	void unknown41a800(int x, int y);	// NOTE: placeholder name
	bool isTrap();
	void unknown45ccd0(bool flag);	// NOTE: placeholder name
	const Point &opW4_getPosition();	// NOTE: placeholder name (0x4184d0, folded getter)
	int opW4_unknown44ab40() throw();	// NOTE: placeholder name (folded getter)
	int opW4_unknown457b10();	// NOTE: placeholder name (folded getter)
	struct OpW4_PropData *opW4_unknown9b8f00();	// NOTE: placeholder name (folded getter)
	bool unknown45c9d0(int a);	// NOTE: placeholder name
	bool unknown65e1d0(HEntity e);	// NOTE: placeholder name
	int opW4_unknown45c630();	// NOTE: placeholder name
	const string *opW4_unknown45c5b0();	// NOTE: placeholder name
	class OpW4_Inventory *opW4_getInventory();	// NOTE: placeholder name (folded getter)
	void unknown45cc50(const Point &p);	// NOTE: placeholder name
	void unknown45ce10(bool a, int b, bool c, HProp d);	// NOTE: placeholder name
	void unknown665b10(int value, int a);	// NOTE: placeholder name
};

class HProp	// NOTE: placeholder layout
{
	int ID;
public:
	HProp();	// 0x9b6590
	Prop *operator->() const throw();	// 0x9b64f0
	bool operator!=(HProp other) const;	// 0x9b6510
	bool isValid() const;	// 0x9b7230
	bool isNull() const;	// 0x9b65d0
};

class Item	// NOTE: placeholder name
{
public:
	int unknown44a7d0();	// NOTE: placeholder name
	int unknown575950();	// NOTE: placeholder name
	bool unknown457cf0();	// NOTE: placeholder name
	int unknown457f90();	// NOTE: placeholder name
	int unknown457fb0();	// NOTE: placeholder name
	int getTypeID();	// NOTE: placeholder name (0x457820)
	struct OpW4_ItemRecord *opW4_unknown9b4350();	// NOTE: placeholder name (folded getter)
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	int unknown457c80();	// NOTE: placeholder name
	int getAmount();	// NOTE: placeholder name (folded getter)
	void setAmount(int amount);	// NOTE: placeholder name (folded setter)
	bool unknown457ad0();	// NOTE: placeholder name
	void setActivateOkayTurn(int turn);	// 0x?
	void unknown579880(int value);	// NOTE: placeholder name
	void unknown458390(bool flag);	// NOTE: placeholder name
	class OpW4_Inventory *opW4_getInventory();	// NOTE: placeholder name (folded getter)
	string unknown571db0(bool a, bool b);	// NOTE: placeholder name
	const Point &unknown575920();	// NOTE: placeholder name
	int unknown457a30();	// NOTE: placeholder name
	bool unknown57ab10(int amount, int a, int b, int c, HEntity e, int d, int f);	// NOTE: placeholder name
	void opW4_unknown450460(int value);	// NOTE: placeholder name (folded setter)
};

class HItemB : public HItem	// NOTE: placeholder name
{
public:
	HItemB();	// 0x9b6590
	Item *operator->() const;	// 0x9b65b0
	bool operator!=(HItemB other) const;	// 0x9b6510
};

class HGroup : public HEntity	// NOTE: placeholder name
{
public:
	HGroup();
	Group *operator->() const;	// 0x9b7250
};

class Entity	// NOTE: placeholder name
{
public:
	const Point &getPosition();	// 0x45a4a0
	int getFaction();	// 0x45a2c0
	HGroup getGroup();	// 0x45a3f0
	int getTarget();	// 0x45a760
	int getAiType();	// 0x45a2a0
	int unknown490840();	// NOTE: placeholder name
	struct EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	HItemB unknown5d2380(int type);	// NOTE: placeholder name
	struct OpW4_EntityRecord *unknown9b4350();	// NOTE: placeholder name (folded getter)
	bool unknown45aaa0(HEntity other);	// NOTE: placeholder name
	vector<HItemB> *getInventoryList();	// NOTE: placeholder name
	int unknown45ad90();	// NOTE: placeholder name
	vector<Point> *opW4_unknown45d1a0();	// NOTE: placeholder name (folded getter)
	void unknown6396f0(const string &key, bool b);	// NOTE: placeholder name
	void unknown45b340(struct EntityData4563c0 *effect);	// NOTE: placeholder name
	void unknown64ecf0(class OpW4_AI57f6a0 *ai);	// NOTE: placeholder name
	class OpW4_Inventory *getInventory();	// 0x45ad90
	bool unknown5c8820(HEntity other);	// NOTE: placeholder name
	void unknown6398e0();	// NOTE: placeholder name
	void unknown639730(bool b);	// NOTE: placeholder name
	void unknown5ded70(int damage);	// NOTE: placeholder name
	bool unknown5d51a0();	// NOTE: placeholder name
	void opW4_unknown44e360(int value);	// NOTE: placeholder name (folded setter)
	HItemB unknown5d1150(HEntity other);	// NOTE: placeholder name
	Point unknown45a4c0();	// NOTE: placeholder name
	bool isPlayer();	// NOTE: placeholder name (0x5c7600)
	bool isHostileTo(HEntity e);	// NOTE: placeholder name (0x45aa70)
	bool unknown45aad0(HEntity other);	// NOTE: placeholder name
	void die(bool a, int cause, HEntity killer, bool b, int c, int d, int e, int f);	// NOTE: placeholder signature
	class OpW4_Unit *unknown45b590();	// NOTE: placeholder name
	class EntityAI *getEntityAI();	// NOTE: placeholder name (0x45b590)
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(int x, int y);	// 0x9d2c30
	T &operator()(const Point &p);
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
	void getRandom_9cf0c0(Point *out);	// NOTE: placeholder name
	OpW4_Area opW4_unknown9b4400();	// NOTE: placeholder name
	void opW4_unknown9d24b0(const Point &p, vector<Point> &out);	// NOTE: placeholder name
	void getAdjacent(const Point &p, vector<Point> &adjacent);	// NOTE: placeholder name (0x9ce500)
	void getBounds(const Point &center, int radius, Point &topLeft, Point &bottomRight);	// NOTE: placeholder name (0x9b7a40)
	void getRect(const Point &p, int radius, struct OpW4_Area &out);	// NOTE: placeholder name (0x9b4430)
	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
};

class Cell	// NOTE: placeholder layout
{
public:
	bool canPlaceEntity(int size);	// NOTE: placeholder name (0x66ad20)
	HProp getProp();	// 0x45d550
	bool isOpen();	// NOTE: placeholder name (0x4550b0)
	bool hasBlockingObject();	// 0x45d7b0
	bool unknown45db70();	// NOTE: placeholder name
	void unknown45e110(int a, bool b, HProp prop);	// NOTE: placeholder name
	HEntity getEntity();	// 0x45d250
	bool unknown45df50(HProp prop);	// NOTE: placeholder name
	bool unknown45dcf0();	// NOTE: placeholder name; has a trap prop
	HItemB getItem();	// 0x45d8f0
	int getTerrain();	// NOTE: placeholder name (0x9fcd80, folded getter)
	struct OpW4_TerrainData *opW4_getTerrainData();	// NOTE: placeholder name (0x9fcd80, folded getter)
	int opW4_unknown9b8f00();	// NOTE: placeholder name (folded getter)
	bool unknown66a630();	// NOTE: placeholder name
	void unknown45df70();	// NOTE: placeholder name
	void unknown670ed0();	// NOTE: placeholder name
	const string *unknown45d140();	// NOTE: placeholder name
	int getArmor();
	void removeProp(bool keepTerrain, int cause);	// NOTE: placeholder name (0x66c100)
};
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

class Map	// NOTE: placeholder name
{
public:
	int getTurn();	// 0x464270
	HEntity getPlayer();	// 0x4630f0
	bool isReachable(int range, const Point &from, const Point &to);	// NOTE: placeholder name (0x465230)
	Rect *unknown464650();	// NOTE: placeholder name
	bool unknown465200(const Point &a, const Point &b);	// NOTE: placeholder name
};
extern class BS *world;	// NOTE: placeholder name (0xcefc4c)

template <class T> void removeVectorElement(vector<T> &v, int index);	// NOTE: placeholder name
template <class T> bool addUnique(vector<T> &v, T e);	// NOTE: placeholder name (0x9d3020 for Point)
void erasePointAt(vector<Point> &v, int index);	// NOTE: placeholder name (0x9d5190)

class MapView	// NOTE: placeholder name
{
public:
	void unknown49ad30();
};
extern MapView *opW4_mapView;	// NOTE: placeholder name (0xcec054)


struct OpW4_Cell7c4	// NOTE: placeholder name
{
	void unknown4611c0();	// NOTE: placeholder name
	void unknown460f00();	// NOTE: placeholder name

	char pad00[0x10];
	int unknown10;	// NOTE: placeholder name
	char pad14[0x24 - 0x14];
	int unknown24;	// NOTE: placeholder name
};

template <class T>
class ItemSet	// NOTE: placeholder name
{
public:
	ItemSet();
	ItemSet(const int *weights, int count);	// NOTE: placeholder name (0x9ba790)
	~ItemSet();	// 0x700dd0
	vector<T> *opW4_getItems();	// NOTE: placeholder name (folded getter)
	T &pickRandom() throw();	// NOTE: placeholder name (0x9ba470)
	void add(T item, int weight);	// NOTE: placeholder name (0x9ba310)
	bool isEmpty();	// NOTE: placeholder name (0x9b81b0)
	int opW4_total();	// NOTE: placeholder name (0x9b81d0, folded getter)

	vector<T> items;	// NOTE: placeholder layout
	vector<int> weights;	// NOTE: placeholder name
	int total;	// NOTE: placeholder name
};

struct OpW4_MapSpec	// NOTE: placeholder name
{
	Point depths;	// NOTE: placeholder name
	int map;	// NOTE: placeholder name
	int weight;	// NOTE: placeholder name
};

struct OpW4_A60Elem	// NOTE: placeholder name
{
	int id;	// NOTE: placeholder name
};

struct OpW4_Owner	// NOTE: placeholder name
{
	int value;	// NOTE: placeholder name
	int unknown4;	// NOTE: placeholder name
	HEntity entity;	// NOTE: placeholder name
};

extern int opW4_unknown_d28d48;	// NOTE: placeholder name

class BS : public Map
{
public:
	void unknown72e8e0(int value);	// NOTE: placeholder name
	void unknown732ce0(bool force);	// NOTE: placeholder name
	void unknown732e70(int id);	// NOTE: placeholder name
	void unknown734560(int a, int b, int faction);	// NOTE: placeholder name
	void unknown734d60(const Point &p);	// NOTE: placeholder name
	void unknown7355a0();	// NOTE: placeholder name
	bool unknown735be0(HEntity entity);	// NOTE: placeholder name
	bool unknown74d200(int id);	// NOTE: placeholder name
	bool unknown74d270();	// NOTE: placeholder name
	void unknown74b1d0();	// NOTE: placeholder name
	void unknown732d50(HEntity entity, int id);	// NOTE: placeholder name
	void unknown735620();	// NOTE: placeholder name
	void unknown7358c0(HEntity source, HEntity target);	// NOTE: placeholder name
	bool findPlacement(const Point &position, Point &result, int size);	// NOTE: placeholder name (0x71c150)
	void unknown465950(int faction, int other, int value);	// NOTE: placeholder name
	void unknown74d560(int faction, int other, int value, XColor color);	// NOTE: placeholder name
	void unknown74bdc0();	// NOTE: placeholder name
	bool unknown71bc10(const Point &p, Point &out);	// NOTE: placeholder name
	void unknown732ef0();	// NOTE: placeholder name
	void unknown737100();	// NOTE: placeholder name
	void unknown737250();	// NOTE: placeholder name
	bool unknown735240(Point &p, HEntity entity);	// NOTE: placeholder name
	int unknown736120(bool flag);	// NOTE: placeholder name
	void unknown742630(vector<Point> &points, bool a, bool b);	// NOTE: placeholder name
	void unknown7456a0();	// NOTE: placeholder name
	void unknown7457f0();	// NOTE: placeholder name
	bool unknown747060(const Point &center, int radius, int effect);	// NOTE: placeholder name
	bool isVisible(const Point &p);	// 0x4631c0
	void unknown74b060(const Point &p, int type, int percent);	// NOTE: placeholder name
	void unknown74ba20(Array2D<int> &mask, const Point &origin);	// NOTE: placeholder name
	void unknown735720(HEntity source, HEntity target, bool flag);	// NOTE: placeholder name
	bool unknown74d420(const Point &p, Point &result);	// NOTE: placeholder name
	void unknown736e40();	// NOTE: placeholder name
	void spawnInfestiationFromTrap(unsigned int infestationIndex);	// 0x736ad0
	int unknown735c80();	// NOTE: placeholder name
	HItemB unknown734920(HEntity source, HEntity target);	// NOTE: placeholder name
	void unknown7353a0(int x, int y);	// NOTE: placeholder name
	void unknown731960();	// NOTE: placeholder name
	void unknown736fe0();	// NOTE: placeholder name
	void unknown740fa0();	// NOTE: placeholder name
	int unknown7359d0(const Point &start);	// NOTE: placeholder name
	bool unknown7380f0(bool flag, int count, HEntity target);	// NOTE: placeholder name
	void unknown74bb90(HProp prop, HProp &door, Point &pos, bool &flag);	// NOTE: placeholder name
	void unknown7471d0(HEntity entity);	// NOTE: placeholder name
	void unknown749630();	// NOTE: placeholder name
	void unknown7329f0();	// NOTE: placeholder name
	void unknown736270(const string &type);	// NOTE: placeholder name
	void unknown749240();	// NOTE: placeholder name
	void unknown742270(bool flag);	// NOTE: placeholder name
	void unknown74d660(const Point &pos, int count);	// NOTE: placeholder name
	void unknown742c80();	// NOTE: placeholder name
	void unknown734db0(HEntity target);	// NOTE: placeholder name
	void unknown7373c0();	// NOTE: placeholder name
	void unknown737850();	// NOTE: placeholder name
	void unknown737c90();	// NOTE: placeholder name
	void unknown741190();	// NOTE: placeholder name
	void unknown745950();	// NOTE: placeholder name
	void unknown747400(HEntity e, HItemB item, bool flag, bool verbose);	// NOTE: placeholder name
	void unknown73c750();	// NOTE: placeholder name
	Array2D<int> *unknown4638c0();	// NOTE: placeholder name
	void unknown6c65a0(HEntity e, const string &text, int value);	// NOTE: placeholder name
	void unknown747860(int a, bool b);	// NOTE: placeholder name
	void unknown741610(bool flag);	// NOTE: placeholder name
	void removeEntity(HEntity e);	// 0x465750
	void unknown4652f0(Point p, int range, int value);	// NOTE: placeholder name
	bool unknown463400(HEntity e);	// NOTE: placeholder name
	static bool turnUpdate_51da30(vector<struct TurnRecord *> *records, int type, HEntity entity, HEntity other, HEntity unused, int unknown1, int unknown2);	// 0x51da30
	void unknown464e60(HProp prop);	// NOTE: placeholder name
	int unknown735e70(bool flag);	// NOTE: placeholder name
	bool unknown744800(bool flag);	// NOTE: placeholder name
	void unknown731680(int count, const Point *pos, bool flag);	// NOTE: placeholder name
	void unknown7430a0(int count, bool flag);	// NOTE: placeholder name
	bool unknown73cd10();	// NOTE: placeholder name
	bool unknown73cfb0();	// NOTE: placeholder name
	void unknown745e10();	// NOTE: placeholder name
	HEntity unknown7345f0(HEntity attacker, HEntity target, bool flag);	// NOTE: placeholder name
	void unknown74c7d0(HItemB item, bool flag);	// NOTE: placeholder name
	HItemB unknown6c5400(struct ItemType *type, const Point &p);	// NOTE: placeholder name
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	Point *opW4_unknown462f60(HProp prop);	// NOTE: placeholder name (Map::unknown462f60)
	HEntity placeEntity(struct EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
	bool unknown6c6b90(const Point &p, const string &type, int a, int b);	// NOTE: placeholder name
	void unknown714000(vector<Point> &out);
	HEntity unknown6c5dc0(const string &name, const Point &pos, int a, int b, int c, int d, int e);	// NOTE: placeholder name
	HEntity unknown715230(int group, int faction);
	void unknown749890();	// NOTE: placeholder name
	HEntity unknown777a20(HEntity entity);	// NOTE: placeholder name

	char pad00[0x10];
	vector<struct OpW4_Rec10 *> unknown10;	// NOTE: placeholder name
	char pad20[0x38 - 0x20];
	Array2D<int> unknown38;	// NOTE: placeholder name
	int unknown44;	// NOTE: placeholder name
	HEntity unknown48;	// NOTE: placeholder name
	vector<HGroup> groups;	// NOTE: placeholder name
	Array2D<int> unknown5c;	// NOTE: placeholder name
	char pad68[0x118 - 0x68];
	vector<vector<Point> > unknown118;	// NOTE: placeholder name
	char pad128[0x148 - 0x128];
	vector<Point> unknown148;	// NOTE: placeholder name
	char pad158[0x288 - 0x158];
	ItemSet<OpW4_MapSpec *> unknown288;	// NOTE: placeholder name
	char pad2ac[0x2f4 - 0x2ac];
	vector<HEntity> unknown2f4;	// NOTE: placeholder name
	vector<int> unknown304;	// NOTE: placeholder name
	int unknown314;	// NOTE: placeholder name
	int unknown318;	// NOTE: placeholder name
	char pad31c[0x320 - 0x31c];
	int unknown320;	// NOTE: placeholder name
	char pad324[0x3d4 - 0x324];
	int unknown3d4;	// NOTE: placeholder name
	char pad3d8[0x3e8 - 0x3d8];
	int unknown3e8;	// NOTE: placeholder name
	char pad3ec[0x4f0 - 0x3ec];
	vector<HProp> unknown4f0;	// NOTE: placeholder name
	vector<HItemB> unknown500;	// NOTE: placeholder name
	char pad510[0x63c - 0x510];
	bool unknown63c;	// NOTE: placeholder name
	char pad63d[0x658 - 0x63d];
	int unknown658;	// NOTE: placeholder name
	char pad65c[0x664 - 0x65c];
	int unknown664;	// NOTE: placeholder name
	int unknown668;	// NOTE: placeholder name
	HEntity player;	// NOTE: placeholder name
	char pad670[0x680 - 0x670];
	Array2D<bool> unknown680;	// NOTE: placeholder name
	int unknown68c;	// NOTE: placeholder name
	Array2D<int> unknown690;	// NOTE: placeholder name
	Array2D<int> unknown69c;	// NOTE: placeholder name
	vector<int> unknown6a8;	// NOTE: placeholder name
	char pad6b8[0x720 - 0x6b8];
	vector<HProp> unknown720;	// NOTE: placeholder name
	vector<HItemB> unknown730;	// NOTE: placeholder name
	Array2D<OpW4_Owner> unknown740;	// NOTE: placeholder name
	int unknown74c;	// NOTE: placeholder name
	char pad750[0x7c4 - 0x750];
	Array2D<OpW4_Cell7c4> unknown7c4;	// NOTE: placeholder name
	vector<Point> unknown7d0;	// NOTE: placeholder name
	char pad7e0[0x884 - 0x7e0];
	vector<Point> unknown884;	// NOTE: placeholder name
	char pad894[0x8b4 - 0x894];
	vector<Point> unknown8b4;	// NOTE: placeholder name
	char pad8c4[0x8cc - 0x8c4];
	OpW4_Area unknown8cc;	// NOTE: placeholder name (area whose top-left is used as the map offset)
	char pad8dc[0x954 - 0x8dc];
	OpW4_Area unknown954;	// NOTE: placeholder name
	char pad964[0xa1c - 0x964];
	bool unknownA1c;	// NOTE: placeholder name
	char padA1d[0xa30 - 0xa1d];
	vector<int> unknownA30;	// NOTE: placeholder name
	vector<vector<HEntity> > unknownA40;	// NOTE: placeholder name
	vector<int> unknownA50;	// NOTE: placeholder name
	vector<OpW4_A60Elem *> unknownA60;	// NOTE: placeholder name
	char padA70[0xa80 - 0xa70];
	vector<struct OpW4_Obj462030 *> unknownA80;	// NOTE: placeholder name
	char padA90[0xbb4 - 0xa90];
	vector<int> unknownBb4;	// NOTE: placeholder name
	vector<int> unknownBc4;	// NOTE: placeholder name
};

bool unknown9db330(int faction, int groupFaction);	// NOTE: placeholder name
int unknown9d4660(vector<int> *v, int id);	// NOTE: placeholder name


struct EntityRecord;
bool opV3b_unknown448b80(Point *p);	// NOTE: placeholder name


bool opV3b_unknown448b60(Point *p);	// NOTE: placeholder name
extern Point opV3b_d3978c;	// NOTE: placeholder name
int opV3b_maxInt(int a, int b);	// 0x9cdb60

void opV3b_unknown6fdab0(struct ItemType *type)	// NOTE: placeholder name
{
	Point spot, target;
	for (int i = 0; i < 30; i++)
	{
		cells.getRandom_9cf0c0(&spot);
		if (!cells(spot)->hasBlockingObject())
		{
			i--;
			continue;
		}
		if (!opV3b_unknown448b60(&spot) && world->unknown71bc10(spot,target))
		{
			HItemB item = world->unknown6c5400(type,target);
			if (rng.chance(0x42))
				item->setAmount(opV3b_maxInt(1,rng.rangeInt(5.0f,20.0f) * item->getAmount() / 100));
			else
				item->setAmount(opV3b_maxInt(1,rng.rangeInt(50.0f,75.0f) * item->getAmount() / 100));
			if (!item->unknown457ad0() && rng.chance(0x32))
				item->setActivateOkayTurn(-2);
			else if (item->unknown457f90() == 0x7b)
				item->unknown579880(opV3b_d3978c.randomInRange_40c130());
			item->unknown458390(false);
			return;
		}
	}
}
