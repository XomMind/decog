// op_w4: BattleScape (BS) methods in 0x730000-0x750000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members, member names and method names are placeholders
//	unless stated otherwise.
#include <string>
#include <vector>
#include "../util/stringutil.h"
using namespace std;
#include "../util/rng.h"

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
	Point &operator=(const Point &p);	// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
	void set(int x_, int y_);	// 0x40a010
	bool contains_40c190(int v);	// NOTE: placeholder name
};

struct OpW4_Area	// NOTE: placeholder name
{
	int x1;
	int y1;
	int x2;
	int y2;

	OpW4_Area();	// 0x40b100
	OpW4_Area &operator=(const OpW4_Area &a);	// 0x40b130
	OpW4_Area(const OpW4_Area &a);	// 0x40b130 (folded with operator=)
	void set(int x1_, int y1_, int x2_, int y2_);	// NOTE: placeholder name (0x40b300)
	OpW4_Area(int x1_, int y1_, int x2_, int y2_);	// NOTE: placeholder name (0x40b1e0)
	bool contains(const Point &p);	// NOTE: placeholder name (0x40b750)
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
class Item;
class HItem
{
public:
	int ID;
	HItem();	// 0x9b6590
	Item *operator->() const;	// 0x9b65b0
	bool operator!=(HItem other) const;	// 0x9b6510
	bool isValid() const;
};
typedef HItem HItemB;	// NOTE: retail has a single HItem handle class

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
	class Inventory *opW4_getInventory();	// NOTE: placeholder name (folded getter)
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
	Prop *get_9b64f0() const throw();	// NOTE: placeholder name (operator-> under a private name, so LTCG keeps this TU's throw())
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
	class Inventory *opW4_getInventory();	// NOTE: placeholder name (folded getter)
	string unknown571db0(bool a, bool b);	// NOTE: placeholder name
	const Point &unknown575920();	// NOTE: placeholder name
	int unknown457a30();	// NOTE: placeholder name
	bool unknown57ab10(int amount, int a, int b, int c, HEntity e, int d, int f);	// NOTE: placeholder name
	void opW4_unknown450460(int value);	// NOTE: placeholder name (folded setter)
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
	class Inventory *getInventory();	// 0x45ad90
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
	bool unknown45db70();	// NOTE: placeholder name
	void unknown45e110(int a, bool b, HProp prop);	// NOTE: placeholder name
	HEntity getEntity();	// 0x45d250
	bool unknown45df50(HProp prop);	// NOTE: placeholder name
	bool unknown45dcf0();	// NOTE: placeholder name; has a trap prop
	HItem getItem();	// 0x45d8f0
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


//==================================================================
// BS
//==================================================================

void BS::unknown732ce0(bool force)
{
	if (!opW4_unknown_d28d48 && !force && !unknownA30.empty())
		return;
	if (!unknown6a8.empty() && player.operator->() != NULL)
		unknown72e8e0(0);
}

void BS::unknown732e70(int id)
{
	for (unsigned int i = 0; i < unknownA50.size(); i++)
	{
		if (unknownA50[i] == id)
		{
			removeVectorElement(unknownA40,i);
			removeVectorElement(unknownA50,i);
			break;
		}
	}
}

void BS::unknown734d60(const Point &p)
{
	if (addUnique(unknown7d0,p))
		opW4_mapView->unknown49ad30();
}

void BS::unknown7355a0()
{
	for (int x = 0; x < unknown7c4.getWidth(); x++)
		for (int y = 0; y < unknown7c4.getHeight(); y++)
			unknown7c4(x,y).unknown4611c0();
}

bool BS::unknown735be0(HEntity entity)
{
	return entity->getFaction() == 4 &&
		(entity->getGroup()->Protobuf::PingRequest::GetCachedSize() == 3 || entity->getGroup()->Protobuf::PingRequest::GetCachedSize() == 4) &&
		entity->getTarget() == 0;
}

bool BS::unknown74d200(int id)
{
	int index = unknown9d4660(&unknownBb4,id);
	if (index == -1)
	{
		unknownBb4.push_back(id);
		int when = unknown320 + 100;
		unknownBc4.push_back(when);
		return true;
	}
	else
		return false;
}

extern int opW4_unknown_cec34c;	// NOTE: placeholder name

bool BS::unknown74d270()
{
	if (unknown3d4 == 0)
		return false;
	int total = cells.getWidth() * cells.getHeight() * opW4_unknown_cec34c / 100;
	return unknown3e8 * 100 / total >= 33;
}

void BS::unknown734560(int a, int b, int faction)
{
	for (unsigned int i = 0; i < groups.size(); i++)
	{
		if (faction == 0 || unknown9db330(faction,groups[i]->Protobuf::PingRequest::GetCachedSize()))
			groups[i]->unknown671940(a,b);
	}
}

extern vector<Point> unknown_d01b28;	// NOTE: placeholder name
extern vector<int> unknown_d02b64;	// NOTE: placeholder name
void unknown9ce6d0(vector<int> &v, unsigned int &i);	// NOTE: placeholder name

void BS::unknown74b1d0()
{
	if (unknown_d01b28.empty())
	{
		unknown668 = 0;
		return;
	}
	int sum = unknown664 + unknown668;
	int turns = sum / 30;
	unknown668 = (unknown664 + unknown668) % 30;
	for (unsigned int i = 0; i < unknown_d01b28.size(); i++)
	{
		if (unknown_d02b64[i] <= turns)
		{
			erasePointAt(unknown_d01b28,i);
			unknown9ce6d0(unknown_d02b64,i);
		}
		else
			unknown_d02b64[i] -= turns;
	}
}

//==================================================================
// other
//==================================================================

class HExplosive	// NOTE: placeholder name
{
	int ID;
};

struct OpW4_Struct7344f0	// NOTE: placeholder name
{
	OpW4_Struct7344f0(HEntity entity_);

	HEntity entity;
	Point pos;
	int turn;
	vector<HExplosive> unknown10;	// NOTE: placeholder name
	vector<HExplosive> unknown20;	// NOTE: placeholder name
	int unknown30;	// NOTE: placeholder name
};

OpW4_Struct7344f0::OpW4_Struct7344f0(HEntity entity_)
	: entity	(entity_),
	pos	(entity->getPosition()),
	turn	(world->getTurn()),
	unknown30	(0)
{
}

struct ItemDef	// NOTE: placeholder name
{
	int ID;	// NOTE: placeholder name
	char pad04[0x44 - 4];
	int rating;	// NOTE: placeholder name
	char pad48[0x238 - 0x48];
	bool unknown238;	// NOTE: placeholder name
};
extern vector<ItemDef *> itemDefs;	// NOTE: placeholder name (0xd2d1c4)


void opW4_unknown746120(ItemSet<int> &set)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < itemDefs.size(); i++)
	{
		if (itemDefs[i]->unknown238 && itemDefs[i]->rating <= 25)
			set.add(i,1);
	}
}

class StatTracker	// NOTE: placeholder name, the object at 0xd2c658
{
public:
	vector<int> *stats;	// NOTE: placeholder name
	void unknown4729d0(int id,int value,string text,int flag);	// NOTE: placeholder name
	void unknown472b90(int id,int value);	// NOTE: placeholder name
};
extern StatTracker statTracker;	// 0xd2c658
extern int opd_gameModeCf462c;	// NOTE: placeholder name (0xcf462c)
int minInt(int a, int b);	// 0x9cdb30

void BS::unknown732d50(HEntity entity, int id)
{
	int index = -1;
	for (unsigned int i = 0; i < unknownA50.size(); i++)
	{
		if (unknownA50[i] == id)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
		unknownA40[index].push_back(entity);
	else
	{
		unknownA40.push_back(vector<HEntity>());
		unknownA40.back().push_back(entity);
		unknownA50.push_back(id);
	}
}

void BS::unknown735620()
{
	int count = 0;
	for (int x = 0; x < unknown680.getWidth(); x++)
		for (int y = 0; y < unknown680.getHeight(); y++)
			if (unknown680(x,y))
				count++;
	int pct = count * 100 / unknown68c;
	statTracker.unknown4729d0(0x402,pct,"",-1);
	if (opd_gameModeCf462c == 11)
		statTracker.unknown472b90(0x13,minInt(pct,80) * 1000 / 100);
}

void BS::unknown7358c0(HEntity source, HEntity target)
{
	if (source.operator->() != NULL && source == player && target.operator->() != NULL)
	{
		if (target->getFaction() == 0x2e || target->getFaction() == 0x2f)
			return;
		if (target->unknown45ac40(0x24))
			return;
		if (target->getGroup()->Protobuf::PingRequest::GetCachedSize() == 2 && target->getAiType() == 1)
			return;
		if (target->getFaction() == 0x49)
			return;
		target->getGroup()->unknown45e480(1);
	}
}

bool opW4_unknown742b60(Point &result, int size)	// NOTE: placeholder name
{
	Rect *area = world->unknown464650();
	for (int x = area->x2; x >= area->x1; x--)
		for (int y = area->y1; y <= area->y2; y++)
			if (cells(x,y)->canPlaceEntity(size))
			{
				result.set(x,y);
				return true;
			}
	for (int x = area->x2; x >= area->x1; x--)
		for (int y = area->y1; y <= area->y2; y++)
			if (world->findPlacement(Point(x,y),result,size))
			{
				result.set(x,y);
				return true;
			}
	return false;
}

void BS::unknown74d560(int faction, int other, int value, XColor color)
{
	for (int i = 0; i < 15; i++)
		if (i != faction)
			unknown465950(i,faction,unknown5c(other,i));
	unknown465950(other,faction,value);
	if (color != COLOR_BLACK)
	{
		for (int i = 0; i < 6; i++)
			groups[faction]->colors[i] = color;
	}
	else
		groups[faction]->unknown45e4c0();
}

struct OpW4_GameState	// NOTE: placeholder name
{
	int pad;
	int branch;	// NOTE: placeholder name
	int depth;	// NOTE: placeholder name
};

class OpW4_HGameState	// NOTE: placeholder name
{
	int ID;
public:
	OpW4_GameState *operator->() const;	// 0x9b7910
};
extern OpW4_HGameState opW4_gameState;	// NOTE: placeholder name (0xd1e888)
extern vector<OpW4_MapSpec *> opW4_mapSpecs;	// NOTE: placeholder name (0xcf1af8)

void BS::unknown74bdc0()
{
	if (unknown288.isEmpty())
	{
		int depth = opW4_gameState->depth;
		int branch = opW4_gameState->branch;
		for (unsigned int i = 0; i < opW4_mapSpecs.size(); i++)
		{
			if (opW4_mapSpecs[i]->depths.contains_40c190(depth) && (opW4_mapSpecs[i]->map == 0x26 || opW4_mapSpecs[i]->map == branch))
				unknown288.add(opW4_mapSpecs[i],opW4_mapSpecs[i]->weight);
		}
		unknown288.isEmpty();
	}
}

class OpW4_Unknown_cf45d8	// NOTE: placeholder name
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern OpW4_Unknown_cf45d8 opW4_unknown_cf45d8;	// NOTE: placeholder name

void BS::unknown732ef0()
{
	if (unknown48 != player)
		return;
	if (unknownA60.empty())
		return;
	if (player.operator->() == NULL || player->unknown490840() == 0)
		return;
	int best = 0;
	int total;
	for (unsigned int i = 0; i < unknownA60.size(); i++)
	{
		total = 0;
		for (unsigned int j = 0; j < unknownA60.size(); j++)
			if (j != i && unknownA60[j]->id == unknownA60[i]->id)
				total++;
		if (total > best)
			best = total;
	}
	statTracker.unknown4729d0(0x18d,best,"",-1);
	if ((*statTracker.stats)[0x18d] >= 1)
		opW4_unknown_cf45d8.unknown77fbc0(0x24);
}

bool unknown4569a0(int type, HEntity a, HEntity b, HProp prop, HItemB item, int c, int d, int value, HEntity e, HProp prop2, HItemB item2, int f);	// NOTE: placeholder name

void BS::unknown737100()
{
	for (unsigned int i = 0; i < unknown4f0.size(); i++)
	{
		if (unknown4f0[i].operator->() != NULL)
		{
			HProp prop = unknown4f0[i];
			unknown4569a0(0x52,HEntity(),HEntity(),unknown4f0[i],HItemB(),0,0,unknown4f0[i]->unknown45c9b0(),HEntity(),unknown4f0[i],HItemB(),0);
			if (i < unknown4f0.size() && unknown4f0[i] != prop)
				i--;
		}
	}
}

void BS::unknown737250()
{
	for (unsigned int i = 0; i < unknown500.size(); i++)
	{
		if (unknown500[i].operator->() != NULL)
		{
			HItemB item = unknown500[i];
			unknown500[i]->unknown575950();
			unknown4569a0(0x57,HEntity(),HEntity(),HProp(),unknown500[i],0,0,unknown500[i]->unknown44a7d0(),HEntity(),HProp(),unknown500[i],0);
			if (i < unknown500.size() && unknown500[i] != item)
				i--;
		}
	}
}

bool BS::unknown735240(Point &p, HEntity entity)
{
	if (unknown740(p).entity != entity || unknown740(p).value != unknown74c)
	{
		int radii[2] = {1,5};
		for (int i = 0; i < 2; i++)
		{
			Point topLeft, bottomRight;
			cells.getBounds(p,radii[i],topLeft,bottomRight);
			for (int x = topLeft.x; x <= bottomRight.x; x++)
				for (int y = topLeft.y; y <= bottomRight.y; y++)
					if (unknown740(x,y).entity == entity && unknown740(x,y).value == unknown74c)
					{
						p.set(x,y);
						return true;
					}
		}
		return false;
	}
	else
		return true;
}

class XConsole
{
public:
	bool isHidden();	// NOTE: placeholder name
};
extern XConsole *opW4_console_cec11c;	// NOTE: placeholder name

class CMap	// NOTE: placeholder layout, the object at 0xcec054
{
public:
	void unknown8142d0(unsigned int a, bool b);	// NOTE: placeholder name
	bool unknown8052f0(const Point &p);	// NOTE: placeholder name
	bool unknown49b220(int type, const Point &p);	// NOTE: placeholder name
	void showCommArraySquad(const Point &p);
	void unknown8051f0(Point &topLeft, Point &bottomRight);	// NOTE: placeholder name
	void unknown8195a0(const Point &p, int a, int b);	// NOTE: placeholder name
	void unknown817de0(HEntity entity, const Point &p);	// NOTE: placeholder name
	const Point &unknown458ef0();	// NOTE: placeholder name
};
extern CMap *opW4_cmap;	// NOTE: placeholder name (0xcec054)

int BS::unknown736120(bool flag)
{
	if (!opW4_console_cec11c->isHidden())
		return 0;
	if (flag)
		opW4_cmap->unknown8142d0(0x12,0);
	vector<Point> shown;
	for (unsigned int i = 0; i < unknown884.size(); i++)
	{
		if (opW4_cmap->unknown8052f0(unknown884[i]) && !opW4_cmap->unknown49b220(0x11,unknown884[i]))
		{
			opW4_cmap->showCommArraySquad(unknown884[i]);
			shown.push_back(unknown884[i]);
		}
	}
	return shown.size();
}

void BS::unknown7456a0()
{
	vector<Point> doors;
	for (int x = 0; x < cells.getWidth(); x++)
		for (int y = 0; y < cells.getHeight(); y++)
			if (cells(x,y)->getProp().isValid() && cells(x,y)->getProp()->unknown45c590() == "GAR_Door_Shootable")
				doors.push_back(Point(x,y));
	if (!doors.empty())
		unknown742630(doors,true,false);
}

void BS::unknown7457f0()
{
	if (unknown63c)
		return;
	unknown63c = true;
	vector<Point> doors;
	for (int x = 0x66; x <= 0x68; x++)
		for (int y = 0x4f; y <= 0x51; y++)
			if (cells(x,y)->getProp().isValid() && cells(x,y)->getProp()->unknown45c590() == "COM_Alternative_Access")
				doors.push_back(Point(x,y));
	if (!doors.empty())
		unknown742630(doors,false,true);
}

class EffectInstance	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class EffectMgr	// NOTE: placeholder name
{
public:
	EffectInstance *create();	// NOTE: placeholder name (0x508610)
};
extern EffectMgr *effectMgr;	// NOTE: placeholder name (0xcefc50)
extern Point effectOrigin;	// NOTE: placeholder name (0xd2e20c)
int unknown406480(int x1, int y1, int x2, int y2);	// NOTE: placeholder name (distance)
void unknown454260(const Point *p, int value);	// NOTE: placeholder name

bool BS::unknown747060(const Point &center, int radius, int effect)
{
	OpW4_Area rect;
	cells.getRect(center,radius,rect);
	int total = 0;
	for (int x = rect.x1; x <= rect.x2; x++)
		for (int y = rect.y1; y <= rect.y2; y++)
		{
			if (!cells(x,y)->isOpen() && !cells(x,y)->unknown45db70() && unknown406480(center.x,center.y,x,y) <= radius)
			{
				effectMgr->create()->init(effectMgr,effect,Point(x,y),effectOrigin,0,0,0,9,0);
				cells(x,y)->unknown45e110(0,true,HProp());
				total++;
			}
		}
	if (total)
		unknown454260(&center,0xcd);
	return total;
}

int pointDistance(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
template <class T> int findIndex(vector<T> &v, T e);	// NOTE: placeholder name (0x9d53a0)
extern int opW4_unknown_cefc04;	// NOTE: placeholder name
extern bool opW4_unknown_d25450;	// NOTE: placeholder name
extern int opW4_unknown_d255fc;	// NOTE: placeholder name
extern const int opW4_table_b94908[];	// NOTE: placeholder name

void BS::unknown74b060(const Point &p, int type, int percent)
{
	if (type == 0 || unknown658 != 2)
		return;
	if (!isVisible(p) && pointDistance(p,player->getPosition()) <= opW4_unknown_cefc04 && (!opW4_unknown_d25450 || opW4_unknown_d255fc == 0) && player->unknown5d2380(0x12).isValid())
	{
		int index = findIndex(unknown_d01b28,p);
		if (index == -1)
		{
			unknown_d01b28.push_back(p);
			unknown_d02b64.push_back(0);
			index = unknown_d01b28.size() - 1;
		}
		if (percent == 100)
			unknown_d02b64[index] += opW4_table_b94908[type];
		else
			unknown_d02b64[index] += opW4_table_b94908[type] * percent / 100;
	}
}

struct PropData;	// NOTE: placeholder name
extern PropData *subcavePropData;	// NOTE: placeholder (0xcefbd8)
class OpW4_EntityMgr	// NOTE: placeholder name
{
public:
	HProp unknown793360(PropData *data);	// NOTE: placeholder name
};
extern OpW4_EntityMgr *opW4_entityMgr;	// NOTE: placeholder name (0xcefaa8)
extern Array2D<int> opW4_unknown_cf11a0;	// NOTE: placeholder name

void BS::unknown74ba20(Array2D<int> &mask, const Point &origin)
{
	for (int i = 0, mapX = origin.x; i < 20; i++, mapX++)
		for (int j = 0, mapY = origin.y; j < 20; j++, mapY++)
		{
			if (mask(i,j) != 0 && cells(mapX,mapY)->isOpen() && cells(mapX,mapY)->getProp().isNull() && cells(mapX,mapY)->getEntity().isNull() && opW4_unknown_cf11a0(mapX,mapY) == 0)
			{
				HProp prop = opW4_entityMgr->unknown793360(subcavePropData);
				cells(mapX,mapY)->unknown45df50(prop);
				prop->unknown41a800(mapX,mapY);
			}
		}
}

extern RNG rng;	// NOTE: placeholder name (0xd30908)
template <class T> bool OpW4_inVector(vector<T> &v, T e);	// NOTE: placeholder name (0x9d31e0)
extern vector<HEntity> opW4_unknown_d1d4c4;	// NOTE: placeholder name
extern bool opW4_unknown_cefb5b;	// NOTE: placeholder name

void BS::unknown735720(HEntity source, HEntity target, bool flag)
{
	if (source.operator->() != NULL && source == player && target.operator->() != NULL)
	{
		if (target->getGroup()->Protobuf::PingRequest::GetCachedSize() == 3 && target->getFaction() != 0x5f)
			return;
		if (target->getFaction() == 0x2e || target->getFaction() == 0x2f)
			return;
		if (target->unknown45ac40(0x24))
			return;
		if (target->getGroup()->Protobuf::PingRequest::GetCachedSize() == 2 && target->getAiType() == 1)
			return;
		if (target->getFaction() == 0x49)
			return;
		if (flag)
		{
			if (OpW4_inVector(opW4_unknown_d1d4c4,target))
				return;
			opW4_unknown_d1d4c4.push_back(target);
			if (rng.chance(opW4_unknown_cefb5b ? 66 : 50))
				return;
		}
		target->getGroup()->unknown45e440(1);
	}
}

void sweepGetSurroundingCells(const Point &point, vector<Point> &adjacent);
void opW4_unknown9d7300(vector<Point> &v, unsigned int &i);	// NOTE: placeholder name (removes element i and steps i back)
Point opW4_randomPoint(vector<Point> &v);	// NOTE: placeholder name (0x9d5350)

bool opW4_unknown74d2e0(const Point &p)	// NOTE: placeholder name
{
	if (cells(p)->canPlaceEntity(1) && !cells(p)->unknown45db70())
	{
		vector<Point> adjacent;
		sweepGetSurroundingCells(p,adjacent);
		int total = 0;
		for (unsigned int i = 0; i < adjacent.size() && total < 5; i++)
			if (cells(adjacent[i])->canPlaceEntity(1) && !cells(adjacent[i])->unknown45db70())
				total++;
		return total == 5;
	}
	return false;
}

bool BS::unknown74d420(const Point &p, Point &result)
{
	if (opW4_unknown74d2e0(p))
	{
		result = p;
		return true;
	}
	vector<Point> adjacent;
	sweepGetSurroundingCells(p,adjacent);
	for (unsigned int i = 0; i < adjacent.size(); i++)
		if (!opW4_unknown74d2e0(adjacent[i]))
			opW4_unknown9d7300(adjacent,i);
	if (adjacent.empty())
		return false;
	else
	{
		result = opW4_randomPoint(adjacent);
		return true;
	}
}

namespace Protobuf {
// NOTE: the exe's ICF folded this getter with Prop's data getter, so the call carries this name
class Stats_Hacking
{
public:
	virtual int GetCachedSize() const;	// 0x44b020, returns the field at +0x4c
};
}
struct PropData	// NOTE: placeholder name
{
	char pad[0x18];
	int uses;	// NOTE: placeholder name
	int cooldownTurn;	// NOTE: placeholder name
};
#define PROP_DATA(prop) ((PropData *)((Protobuf::Stats_Hacking *)(prop))->Protobuf::Stats_Hacking::GetCachedSize())

extern vector<Point> infestationLocations;	// NOTE: placeholder name (0xd20690)
bool opW4_unknown5111e0(int id, const string *text, const string *text2, int b, HEntity entity, HEntity other, const Point *at, int flag);	// NOTE: placeholder name
class ConsoleA	// NOTE: placeholder name
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA *consoleA;	// NOTE: placeholder name (0xcec058)
class ConsoleB	// NOTE: placeholder name
{
public:
	void unknown7b4f10();	// NOTE: placeholder name
};
extern ConsoleB *consoleB;	// NOTE: placeholder name (0xcec0b4)

void BS::unknown736e40()
{
	int turn = getTurn();
	for (unsigned int i = 0; i < infestationLocations.size(); i++)
	{
		if (!cells(infestationLocations[i])->unknown45dcf0())
			opW4_unknown9d7300(infestationLocations,i);
		else if (turn >= PROP_DATA(cells(infestationLocations[i])->getProp().operator->())->cooldownTurn)
		{
			spawnInfestiationFromTrap(i);
			if (PROP_DATA(cells(infestationLocations[i])->getProp().operator->())->uses == 0)
			{
				do
				{
					if (opW4_unknown5111e0(0x228,NULL,0,0,HEntity(),HEntity(),&infestationLocations[i],0))
						consoleA->unknown8758d0(true);
					consoleB->unknown7b4f10();
				} while (false);
				cells(infestationLocations[i])->removeProp(false,3);
				opW4_unknown9d7300(infestationLocations,i);
			}
		}
	}
}

int maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
extern int opW4_unknown_cf27f4;	// NOTE: placeholder name
extern int opW4_unknown_cf27f8;	// NOTE: placeholder name

int BS::unknown735c80()
{
	int result = 0;
	HEntity actor;
	Point a, bottomRight;
	opW4_cmap->unknown8051f0(a,bottomRight);
	for (int x = a.x, screenX = maxInt(opW4_cmap->unknown458ef0().x,0); x <= bottomRight.x && screenX < opW4_unknown_cf27f4; x++, screenX++)
		for (int mapY = a.y, cy = maxInt(opW4_cmap->unknown458ef0().y,0); mapY <= bottomRight.y && cy < opW4_unknown_cf27f8; mapY++, cy++)
		{
			if (unknown69c(x,mapY) != 0)
			{
				if (cells(x,mapY)->getEntity().isValid() && unknown735be0(cells(x,mapY)->getEntity()))
					result++;
			}
			else if (unknown740(x,mapY).value == unknown74c && unknown740(x,mapY).entity.operator->() != NULL && unknown735be0(unknown740(x,mapY).entity))
				result++;
		}
	return result;
}

struct OpW4_EntityRecord	// NOTE: placeholder name
{
	char pad00[0x48];
	int unknown48;	// NOTE: placeholder name
	char pad4c[0x68 - 0x4c];
	int unknown68;	// NOTE: placeholder name
};
extern const int opW4_table_b98740[];	// NOTE: placeholder name

HItemB BS::unknown734920(HEntity source, HEntity target)
{
	int base = opW4_table_b98740[source->unknown9b4350()->unknown68];
	if (target->unknown45aaa0(player) && pointDistance(player->getPosition(),target->getPosition()) <= 10 && unknown465200(player->getPosition(),target->getPosition()))
	{
		vector<HItemB> *inventory = player->getInventoryList();
		for (unsigned int i = 0; i < inventory->size(); i++)
		{
			if ((*inventory)[i]->unknown457cf0() && (*inventory)[i]->unknown457f90() == 0x7a && rng.chance(base + (*inventory)[i]->unknown457fb0() * 2))
			{
				statTracker.unknown4729d0(0x37c,1,"",-1);
				return (*inventory)[i];
			}
		}
	}
	return HItemB();
}

template <class T> void OpW4_removeValue(vector<T> &v, T e);	// NOTE: placeholder name (0x9d2f00)
extern int opW4_unknown_caf164;	// NOTE: placeholder name
extern int opW4_unknown_caf15c;	// NOTE: placeholder name

void BS::unknown7353a0(int x, int y)
{
	if (unknown7c4(x,y).unknown10 != opW4_unknown_caf164 && cells(x,y)->getItem().isValid() && cells(x,y)->getItem()->getTypeID() == unknown7c4(x,y).unknown10)
		OpW4_removeValue(unknown730,cells(x,y)->getItem());
	if (unknown7c4(x,y).unknown24 != opW4_unknown_caf15c && cells(x,y)->getProp().isValid() && cells(x,y)->getProp()->isTrap())
	{
		cells(x,y)->getProp()->unknown45ccd0(true);
		OpW4_removeValue(unknown720,cells(x,y)->getProp());
	}
	unknown7c4(x,y).unknown460f00();
	unknown690(x,y) = 0;
}

class OpW4_GameData	// NOTE: placeholder name (object at 0xd1e860)
{
public:
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
	void unknown7892d0(class OpW4_HObj h, const Point &p, const string &text);	// NOTE: placeholder name
	void unknown46f700(const string &key, const string &value);	// NOTE: placeholder name
};
extern OpW4_GameData opW4_gameData;	// NOTE: placeholder name (0xd1e860)
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
struct OpW4_Map_cfd2cc { int dummy; };	// NOTE: placeholder name
extern OpW4_Map_cfd2cc opW4_map_cfd2cc;	// NOTE: placeholder name (0xcfd2cc)
bool opW4_unknown9d7be0(OpW4_Map_cfd2cc &m, const string &key, int &value);	// NOTE: placeholder name
struct OpW4_Val409990	// NOTE: placeholder name
{
	int value;
	int unknown4;	// NOTE: placeholder name
	OpW4_Val409990(int v);	// 0x409990
};
class OpW4_Obj515ca0	// NOTE: placeholder name
{
public:
	OpW4_Obj515ca0(HEntity a, int id, const Point &pos, HEntity b, const OpW4_Val409990 &c, const OpW4_Val409990 &d);	// 0x515ca0
	char pad[0x40];
};
struct OpW4_Obj;
class OpW4_HObj	// NOTE: placeholder name
{
	int ID;
public:
	OpW4_HObj();	// 0x9b6590
	OpW4_Obj *operator->() const;	// 0x9b7910
};
struct OpW4_Obj	// NOTE: placeholder name (looks like a map-graph node)
{
	int pad00;
	int type;	// NOTE: placeholder name
	int ID;	// NOTE: placeholder name
	vector<OpW4_HObj> links;	// NOTE: placeholder name
	int unknown1c;	// NOTE: placeholder name
	char pad20[0x25 - 0x20];
	bool unknown25;	// NOTE: placeholder name
	void unknown46eb70(int a, int b, int c, int d);	// NOTE: placeholder name
};
class OpW4_EntityMgr2	// NOTE: placeholder name (object at 0xcefaa8)
{
public:
	OpW4_HObj unknown793120();	// NOTE: placeholder name
	void unknown793690();	// NOTE: placeholder name
	HEntity unknown7930e0(OpW4_Obj515ca0 *obj);	// NOTE: placeholder name
};
extern OpW4_EntityMgr2 *opW4_entityMgr2;	// NOTE: placeholder name (0xcefaa8)
class OpW4_Audio	// NOTE: placeholder name (object at 0xd25450)
{
public:
	bool enabled;
	void unknown69e700(int id, int a, float b);	// NOTE: placeholder name
};
extern OpW4_Audio opW4_audio;	// NOTE: placeholder name (0xd25450)

void BS::unknown731960()
{
	if (!stringToInt(opW4_gameData.unknown46f6d0("datHostileToDataMiner_g")))
	{
		int id;
		if (opW4_unknown9d7be0(opW4_map_cfd2cc,"DAT_Inhabitant_Hit",id))
		{
			unknown777a20(opW4_entityMgr2->unknown7930e0(new OpW4_Obj515ca0(HEntity(),id,Point(0x13,0xe),HEntity(),OpW4_Val409990(-1),OpW4_Val409990(-1))));
		}
		if (opW4_audio.enabled)
			opW4_audio.unknown69e700(0x61,0,0.0f);
	}
}

void BS::unknown736fe0()
{
	for (unsigned int i = 0; i < groups.size(); i++)
	{
		vector<HEntity> *members = groups[i]->getMembers();
		for (unsigned int j = 0; j < members->size(); j++)
		{
			if ((*members)[j].operator->() != NULL)
				unknown4569a0(0x4d,(*members)[j],HEntity(),HProp(),HItemB(),0,0,(*members)[j]->unknown45ad90(),(*members)[j],HProp(),HItemB(),0);
		}
	}
}

void BS::unknown749890()
{
	do
	{
		if (opW4_unknown5111e0(0x325,&string("[Congratulations! You are victorious! The exit is now open...]"),0,0,HEntity(),HEntity(),NULL,0))
			consoleA->unknown8758d0(true);
		consoleB->unknown7b4f10();
	} while (false);
	Point pos(100,100);
	if (!findPlacement(pos,pos,1))
		return;
	OpW4_HObj h = opW4_entityMgr2->unknown793120();
	h->unknown46eb70(6,0,8,0);
	opW4_gameData.unknown7892d0(h,pos,"N/A");
	h->unknown25 = true;
}

struct OpW4_Coord	// NOTE: placeholder name
{
	int x;
	int y;
	OpW4_Coord &operator=(const OpW4_Coord &c);	// 0x46ca50
};
class OpW4_Unit	// NOTE: placeholder name
{
public:
	void unknown4582d0(int value);	// NOTE: placeholder name
	void unknown459540(const OpW4_Coord &c);	// NOTE: placeholder name
	void unknown459470(OpW4_Area &area);	// NOTE: placeholder name
	void unknown459410(OpW4_Area &area);	// NOTE: placeholder name
	void unknown580a90(vector<HEntity> &members, int value);	// NOTE: placeholder name
	void unknown4593d0(vector<Point> &route);	// NOTE: placeholder name
};
class OpW4_MessageLog	// NOTE: placeholder name (object at 0xcf1080)
{
public:
	void unknown451400(int value);	// NOTE: placeholder name
};
extern OpW4_MessageLog opW4_messageLog;	// NOTE: placeholder name (0xcf1080)
void opW4_unknown4541b0(int a, int b, int c);	// NOTE: placeholder name
OpW4_Coord opW4_unknown9d7d20(vector<Point> &v);	// NOTE: placeholder name

void BS::unknown740fa0()
{
	string text("ANNOUNCEMENT: Warlord pulling back, all units provide covering fire where possible.");
	do
	{
		opW4_messageLog.unknown451400(0);
		if (false)
			opW4_unknown4541b0(-1,0,0);
		do
		{
			if (opW4_unknown5111e0(0x324,&text,0,0,HEntity(),HEntity(),NULL,0))
				consoleA->unknown8758d0(true);
			consoleB->unknown7b4f10();
		} while (false);
		consoleB->unknown7b4f10();
		OpW4_Coord();	// NOTE: unused temporary; reproduces an 8-byte stack slot (probably from a macro)
	} while (false);
	OpW4_Coord exit;
	exit = opW4_unknown9d7d20(unknown8b4);
	HEntity commander = unknown715230(9,0x5b);
	if (commander.isNull())
		commander = unknown715230(5,0x5b);
	if (commander.isValid())
	{
		commander->unknown45b590()->unknown4582d0(0x19);
		commander->unknown45b590()->unknown459540(exit);
	}
	HEntity other = unknown715230(9,0x5a);
	if (other.isNull())
		other = unknown715230(5,0x5a);
	if (other.isValid())
	{
		other->unknown45b590()->unknown4582d0(0x19);
		other->unknown45b590()->unknown459540(exit);
	}
}

extern int TERRAIN_CAVE_WALL;	// NOTE: placeholder (0xcefba0)
extern Point opW4_directions[];	// NOTE: placeholder name (0xd015d8)
void opW4_shuffle(vector<int> &v);	// NOTE: placeholder name (0x9d8f80)
int opW4_minIndex(vector<int> &v);	// NOTE: placeholder name (0x9d9270)

int BS::unknown7359d0(const Point &start)
{
	vector<int> dirList;
	dirList.push_back(0);
	dirList.push_back(2);
	dirList.push_back(4);
	dirList.push_back(6);
	opW4_shuffle(dirList);
	vector<int> dist(dirList.size(),9999);
	for (unsigned int i = 0; i < dirList.size(); i++)
	{
		Point p = start;
		for (int d = 1; d < 20; d++)
		{
			p += opW4_directions[dirList[i]];
			if (!cells.contains(p))
				break;
			else if (cells(p)->getTerrain() == TERRAIN_CAVE_WALL)
			{
				dist[i] = d;
				break;
			}
		}
	}
	int closest = opW4_minIndex(dist);
	if (dist[closest] == 9999)
		return 8;
	else
		return dirList[closest];
}

class EntityAI	// NOTE: placeholder layout
{
public:
	void setFollowEntity(HEntity followEntity_, int followParam_);
	HEntity getFollowEntity();	// 0x458ed0
};
class OpW4_Obj_cf6428	// NOTE: placeholder name
{
public:
	int opW4_spawnPatrolParty(HProp a, bool b, int c, int d, Point *e, int f, int g, int h, int i);	// NOTE: placeholder name (Overmind::spawnPatrolParty)
	struct OpW4_Squad *lastParty();	// NOTE: placeholder name
	int spawnHunterParty(HEntity entity, int a, int b);	// NOTE: placeholder name
};
extern OpW4_Obj_cf6428 opW4_cf6428;	// NOTE: placeholder name (0xcf6428)
Point opW4_randomPoint(vector<Point> &v);	// NOTE: placeholder name (0x9d5350)

bool BS::unknown7380f0(bool flag, int count, HEntity target)
{
	bool result = false;
	while (count != 0)
	{
		if (flag)
		{
			Point pos(-1);
			if (target.isValid())
				pos = target->getPosition();
			else
			{
				vector<Point> candidates;
				unknown714000(candidates);
				if (candidates.empty())
				{
				}
				else
					pos = opW4_randomPoint(candidates);
			}
			if (pos.x != -1)
			{
				const int num = 4;
				HEntity first;
				for (int i = 0; i < num; i++)
				{
					HEntity e = unknown6c5dc0("Revision",pos,8,0,0x22,0xe,0);
					if (e.isValid())
					{
						if (target.isValid() || first.isValid())
							e->getEntityAI()->setFollowEntity(target.isValid() ? target : first,0);
						result = true;
						if (first.isNull())
							first = e;
					}
				}
			}
		}
		else if (opW4_cf6428.spawnHunterParty(HEntity(),0,0))
			result = true;
		count--;
	}
	return result;
}

void getAdjacentCells(const Point &p, vector<Point> &adjacent);	// NOTE: placeholder name (0x4fab80)
extern OpW4_Map_cfd2cc opW4_map_d2c408;	// NOTE: placeholder name (0xd2c408)
bool opW4_unknown9d7de0(OpW4_Map_cfd2cc &m, const string &key, int &value);	// NOTE: placeholder name

void BS::unknown74bb90(HProp prop, HProp &door, Point &pos, bool &flag)
{
	vector<Point> adjacent;
	pos.x = -1;
	flag = false;
	int sealTimer;
	opW4_unknown9d7de0(opW4_map_d2c408,"COM_Cave_Seal_Timer",sealTimer);
	getAdjacentCells(prop->opW4_getPosition(),adjacent);
	for (unsigned int i = 0; i < adjacent.size(); i++)
	{
		if (cells(adjacent[i])->getProp().isValid())
		{
			if (door.isNull() && cells(adjacent[i])->getProp()->opW4_unknown44ab40() != -1 && cells(adjacent[i])->getProp()->opW4_unknown457b10() == 0)
				door = cells(adjacent[i])->getProp();
			else if (cells(adjacent[i])->getProp()->unknown45c9d0(sealTimer))
				flag = true;
		}
		else if (pos.x == -1)
			pos = adjacent[i];
	}
}

struct OpW4_TerrainData	// NOTE: placeholder name
{
	int id;	// NOTE: placeholder name
};
extern OpW4_TerrainData *TERRAIN_EARTH;	// NOTE: placeholder (0xcefb80); declared as int elsewhere
void opW4_unknown9d80a0(vector<Point> &dst, vector<Point> &src);	// NOTE: placeholder name
void opW4_unknown6c0f10(const Point &p, int terrain, int value);	// NOTE: placeholder name
void opW4_unknown454260(const Point &p, int value);	// NOTE: placeholder name

void BS::unknown7471d0(HEntity entity)
{
	vector<Point> border;
	for (unsigned int i = 0; i < entity->opW4_unknown45d1a0()->size(); i++)
	{
		vector<Point> adjacent;
		cells.opW4_unknown9d24b0((*entity->opW4_unknown45d1a0())[i],adjacent);
		opW4_unknown9d80a0(border,adjacent);
	}
	bool dug = false;
	for (unsigned int i = 0; i < border.size(); i++)
	{
		if (cells(border[i])->unknown66a630() && cells(border[i])->getArmor() != -1)
		{
			opW4_cmap->unknown8195a0(border[i],cells(border[i])->opW4_unknown9b8f00(),9);
			OpW4_TerrainData *terrain = cells(border[i])->opW4_getTerrainData();
			cells(border[i])->unknown45e110(0,true,HProp());
			if (terrain != TERRAIN_EARTH)
				opW4_unknown6c0f10(border[i],terrain->id,100);
			dug = true;
		}
	}
	if (dug)
		opW4_unknown454260(entity->getPosition(),0xa9);
}

struct OpW4_Rec10	// NOTE: placeholder name
{
	int pad00;
	int pad04;
	OpW4_HObj unknown8;	// NOTE: placeholder name
	bool unknownC;	// NOTE: placeholder name
	char pad0d[0x1c - 0x0d];
	int unknown1c;	// NOTE: placeholder name
};
extern bool opW4_flag_cf468c;	// NOTE: placeholder name
extern bool opW4_flag_d28fb0;	// NOTE: placeholder name
extern OpW4_HObj opW4_rootNode;	// NOTE: placeholder name (0xd1e888)
void opW4_unknown5141b0(int id, int a, int b, int c, HEntity entity, int d);	// NOTE: placeholder name
bool opW4_findNode(int type, int ID, OpW4_HObj node, OpW4_HObj *result);	// NOTE: placeholder name (0x470180)
template <class T> bool opW4_addUnique(vector<T> &v, T e);	// NOTE: placeholder name (0x9d30e0)

void BS::unknown749630()
{
	opW4_flag_cf468c = true;
	do
	{
		opW4_messageLog.unknown451400(1);
		if (1 && !(opW4_flag_d28fb0 && 0 && 1))
			opW4_unknown4541b0(0x11e,0,0);
		do
		{
			if (opW4_unknown5111e0(0x324,&string("ALERT: Detected disturbance from likely dimensional gate."),0,0,HEntity(),HEntity(),NULL,0))
				consoleA->unknown8758d0(true);
			consoleB->unknown7b4f10();
		} while (false);
		consoleB->unknown7b4f10();
	} while (false);
	do
	{
		opW4_unknown5141b0(0x22e,0,0,0,HEntity(),0);
	} while (false);
	OpW4_HObj node;
	if (opW4_findNode(5,-1,opW4_rootNode,&node))
	{
		OpW4_HObj gate = opW4_entityMgr2->unknown793120();
		gate->unknown46eb70(0x24,1,8,0);
		gate->unknown25 = true;
		gate->unknown1c = node->unknown1c;
		for (unsigned int i = 0; i < unknown10.size(); i++)
		{
			if (unknown10[i]->unknown1c == 0)
			{
				unknown10[i]->unknownC = true;
				unknown10[i]->unknown8 = gate;
				unknown10[i]->unknown8->unknown25 = true;
				opW4_addUnique(opW4_rootNode->links,gate);
			}
		}
	}
}

extern string opW4_string_cf4acc;	// NOTE: placeholder name
void opW4_unknown789ac0();	// NOTE: placeholder name

// NOTE: byte-identical, but tools/lverify.py reports a DIFF: the .bss string at 0xcf4acc is pushed right
// before operator+(const char *, const string &), so it is compared as a C literal and the exe has no file bytes there.
void BS::unknown7329f0()
{
	opW4_gameData.unknown46f700("scrAttackedLocals_g",intToString(getTurn()));
	string msg = "0bP_NET: " + opW4_string_cf4acc + " betrays us! Get the scumbolt!";
	do
	{
		opW4_messageLog.unknown451400(1);
		if (false)
			opW4_unknown4541b0(-1,0,0);
		do
		{
			if (opW4_unknown5111e0(0x324,&msg,0,0,HEntity(),HEntity(),NULL,0))
				consoleA->unknown8758d0(true);
			consoleB->unknown7b4f10();
		} while (false);
		consoleB->unknown7b4f10();
	} while (false);
	do
	{
		opW4_unknown5141b0(0x20f,0,0,0,HEntity(),0);
	} while (false);
	if (opW4_audio.enabled)
		opW4_audio.unknown69e700(0x74,0,0.0f);
	for (int i = 0; i <= 2; i++)
		unknown465950(i,10,0);
	opW4_entityMgr2->unknown793690();
	opW4_unknown789ac0();
	HEntity optimus = groups[10]->unknown45e250(0x4e);
	if (optimus.isValid())
	{
		optimus->unknown6396f0("FRG_Optimus_Greet",true);
		optimus->unknown6396f0("FRG_Optimus_Greet_Done",true);
	}
}

struct OpW4_PropData	// NOTE: placeholder name
{
	char pad00[0x68];
	int unknown68;	// NOTE: placeholder name
	char pad6c[0x8c - 0x6c];
	int unknown8c;	// NOTE: placeholder name
};
extern vector<vector<HProp> > opW4_machines;	// NOTE: placeholder name (0xd31640)
void opW4_unknown9dbce0(vector<Point> &v, Point p);	// NOTE: placeholder name

void BS::unknown736270(const string &type)
{
	for (unsigned int i = 0; i < unknown148.size(); i++)
	{
		if (cells(unknown148[i])->getProp().isValid() && cells(unknown148[i])->getProp()->opW4_unknown9b8f00()->unknown8c != 0)
		{
			vector<HProp> &parts = opW4_machines[cells(unknown148[i])->getProp()->opW4_unknown44ab40()];
			vector<Point> adj;
			vector<Point> candidates;
			for (unsigned int j = 0; j < parts.size(); j++)
			{
				adj.clear();
				getAdjacentCells(parts[j]->opW4_getPosition(),adj);
				for (unsigned int k = 0; k < adj.size(); k++)
				{
					if (cells(adj[k])->isOpen() && cells(adj[k])->getProp().isNull())
						opW4_unknown9dbce0(candidates,adj[k]);
				}
			}
			if (!candidates.empty())
				unknown6c6b90(opW4_randomPoint(candidates),type,0,-1);
		}
		else
			opW4_unknown9d7300(unknown148,i);
	}
}

int BS::unknown735e70(bool flag)
{
	if (!opW4_console_cec11c->isHidden())
		return 0;
	if (flag)
		opW4_cmap->unknown8142d0(0x12,0);
	vector<HEntity> marked;
	HEntity actor;
	Point a, bottomRight;
	opW4_cmap->unknown8051f0(a,bottomRight);
	for (int x = a.x, screenX = maxInt(opW4_cmap->unknown458ef0().x,0); x <= bottomRight.x && screenX < opW4_unknown_cf27f4; x++, screenX++)
		for (int mapY = a.y, cy = maxInt(opW4_cmap->unknown458ef0().y,0); mapY <= bottomRight.y && cy < opW4_unknown_cf27f8; mapY++, cy++)
		{
			if (unknown69c(x,mapY) != 0)
			{
				if (cells(x,mapY)->getEntity().isValid())
				{
					actor = cells(x,mapY)->getEntity();
					goto found;
				}
			}
			else if (unknown740(x,mapY).value == unknown74c && (actor = unknown740(x,mapY).entity).operator->() != NULL)
				goto found;
			continue;
found:
			if (unknown735be0(actor) && !OpW4_inVector(marked,actor) && !opW4_cmap->unknown49b220(0x10,Point(x,mapY)))
			{
				opW4_cmap->unknown817de0(actor,Point(x,mapY));
				marked.push_back(actor);
			}
		}
	return marked.size();
}

extern string opW4_gameStrings_cf3508[];	// NOTE: placeholder name
extern const int opW4_weights_b99ac4[];	// NOTE: placeholder name
extern Point opW4_ranges_d38434[];	// NOTE: placeholder name
struct OpW4_RecordMap { int dummy; };	// NOTE: placeholder name
extern OpW4_RecordMap opW4_robotData;	// NOTE: placeholder name (0xd25de0)
int opW4_unknown9cda80(string *table, int count, string s) throw();	// NOTE: placeholder name
bool opW4_unknown9d7530(OpW4_RecordMap &m, const string &key, EntityRecord *&record);	// NOTE: placeholder name

bool BS::unknown744800(bool flag)
{
	Point unused(-1);
	for (unsigned int i = 0; i < unknown118[5].size(); i++)
	{
		if (cells(unknown118[5][i])->getProp()->opW4_unknown457b10() == 0)
		{
			int index = flag ? opW4_unknown9cda80(opW4_gameStrings_cf3508,6,"Decapitator") : ItemSet<int>(opW4_weights_b99ac4,6).pickRandom();
			EntityRecord *record;
			if (opW4_unknown9d7530(opW4_robotData,opW4_gameStrings_cf3508[index],record))
			{
				Point *spot = opW4_unknown462f60(cells(unknown118[5][i])->getProp());
				if (spot == NULL)
				{
				}
				else
				{
					OpW4_Area area;
					if (flag)
						cells.getRect(player->getPosition(),0xf,area);
					else
						area = unknown954;
					HEntity leader;
					for (int n = opW4_ranges_d38434[index].randomInRange_40c130(); n > 0; n--)
					{
						HEntity e = placeEntity(record,*spot,3,false,0x22,0xe,false);
						if (e.isValid())
						{
							e->unknown45b590()->unknown459470(area);
							if (leader.isValid())
								e->getEntityAI()->setFollowEntity(leader,0);
							else
								leader = e;
						}
					}
					if (leader.isValid())
						return true;
				}
			}
			break;
		}
	}
	return false;
}

struct EntityData4563c0	// NOTE: placeholder layout
{
	int type;	// NOTE: placeholder name
	int state;	// NOTE: placeholder name
	EntityData4563c0(int type_, int state_) throw();	// 0x46ca20
};
extern vector<int> opW4_effectTypes;	// NOTE: placeholder name (0xd2f0f8)

void BS::unknown731680(int count, const Point *pos, bool flag)
{
	HEntity leader;
	OpW4_Area area;
	if (pos == NULL)
	{
		leader = unknown715230(10,0x4e);
		if (leader.isNull())
			return;
	}
	else if (flag)
		cells.getRect(*pos,0xf,area);
	else
		area = cells.opW4_unknown9b4400();
	Point defaultPos(0x26,3);
	ItemSet<string> derelicts;
	derelicts.add("Explorer",10);
	derelicts.add("Ranger",20);
	derelicts.add("Guru",15);
	derelicts.add("Scrapper_3",0x37);
	for (int i = 0; i < count; i++)
	{
		Point p;
		if (findPlacement(pos != NULL ? *pos : defaultPos,p,1))
		{
			HEntity e = unknown6c5dc0(derelicts.pickRandom(),p,0xd,0,0x22,0xe,0);
			if (e.isValid())
			{
				if (leader.isValid())
					e->getEntityAI()->setFollowEntity(leader,0);
				else
				{
					e->unknown45b590()->unknown459410(area);
					if (!flag)
						e->unknown45b340(new EntityData4563c0(opW4_effectTypes[0x8a],1));
				}
			}
		}
	}
}

struct OpW4_Squad	// NOTE: placeholder name
{
	int pad00;
	HEntity leader;	// NOTE: placeholder name
};
void opW4_shufflePoints(vector<Point> &v);	// NOTE: placeholder name (0x9d7350)

void BS::unknown7430a0(int count, bool flag)
{
	vector<Point> route;
	route.push_back(Point(0xb,0x5f));
	route.push_back(Point(0x15,0x3a));
	route.push_back(Point(0x2e,0x3a));
	route.push_back(Point(0x44,0x3a));
	route.push_back(Point(0x6e,0x52));
	route.push_back(Point(0x6e,0x3c));
	route.push_back(Point(0x6e,0x28));
	route.push_back(Point(0x42,0xd));
	for (unsigned int i = 0; i < route.size(); i++)
		route[i] += *(Point *)&unknown8cc;
	for (int i = 0; i < count; i++)
	{
		Point pos(-1);
		if (flag)
			pos = opW4_randomPoint(route);
		if (opW4_cf6428.opW4_spawnPatrolParty(HProp(),flag,0,0,pos.x != -1 ? &pos : NULL,0,0,9,0))
		{
			opW4_shufflePoints(route);
			OpW4_Squad *squad = opW4_cf6428.lastParty();
			vector<HEntity> robots(1,squad->leader);
			squad->leader->unknown45b590()->unknown580a90(robots,0xf);
			for (unsigned int j = 0; j < robots.size(); j++)
				robots[j]->unknown45b590()->unknown4593d0(route);
		}
	}
	if (!flag)
	{
		do
		{
			opW4_unknown5141b0(0x203,0,0,0,HEntity(),0);
		} while (false);
	}
}

bool BS::unknown73cd10()
{
	return opW4_gameState->branch == 4 && opW4_gameState->depth == 3 &&
		!stringToInt(opW4_gameData.unknown46f6d0("resRevisionAttacked_g")) &&
		!stringToInt(opW4_gameData.unknown46f6d0("cetR17Destroyed_g")) &&
		!stringToInt(opW4_gameData.unknown46f6d0("cetGuardsRemaining_g")) &&
		!stringToInt(opW4_gameData.unknown46f6d0("cetManufacturingDisabled_g")) &&
		!stringToInt(opW4_gameData.unknown46f6d0("zioWasImprinted_g"));
}

struct OpW4_ItemRecord	// NOTE: placeholder name
{
	char pad00[0x1a8];
	int unknown1a8;	// NOTE: placeholder name
};
extern vector<HEntity> opW4_entities_d1ec00;	// NOTE: placeholder name
extern vector<Point> opW4_points_d1ec10;	// NOTE: placeholder name
void opW4_unknown9da940(vector<HEntity> &v, int index);	// NOTE: placeholder name

void BS::unknown745e10()
{
	for (unsigned int i = 0; i < opW4_entities_d1ec00.size(); i++)
	{
		if (opW4_entities_d1ec00[i].operator->() == NULL)
		{
			opW4_unknown9da940(opW4_entities_d1ec00,i);
			opW4_unknown9d7300(opW4_points_d1ec10,i);
		}
	}
	if (opW4_entities_d1ec00.size() <= 10)
		return;
	vector<int> order(opW4_entities_d1ec00.size(),0);
	for (unsigned int i = 0; i < opW4_entities_d1ec00.size(); i++)
		order[i] = i;
	opW4_shuffle(order);
	HEntity e;
	for (int i = (int)(order.size() * 0.2); i >= 0; i--)
	{
		e = opW4_entities_d1ec00[order[i]];
		if (e.operator->() != NULL && e->getAiType() != 2)
		{
			if (rng.chance(5))
			{
				HItemB item = e->unknown5d1150(HEntity());
				if (item.isValid())
				{
					int value = item->opW4_unknown9b4350()->unknown1a8;
					item->unknown57dbe0(0,0,1,1);
					unknown777a20(opW4_entityMgr2->unknown7930e0(new OpW4_Obj515ca0(HEntity(),value,e->unknown45a4c0(),HEntity(),OpW4_Val409990(-1),OpW4_Val409990(-1))));
				}
			}
			if (e.operator->() != NULL)
				e->die(!unknown4631f0(e),10,HEntity(),true,0,0,0,0);
		}
	}
}

extern const int opW4_table_b98454[];	// NOTE: placeholder name

HEntity BS::unknown7345f0(HEntity attacker, HEntity target, bool flag)
{
	int bonus = attacker->isPlayer() ? 0 : opW4_table_b98740[attacker->unknown9b4350()->unknown68];
	OpW4_Area area;
	int range = flag ? 0 : 10;
	cells.getRect(target->getPosition(),range,area);
	for (int x = area.x1; x <= area.x2; x++)
		for (int y = area.y1; y <= area.y2; y++)
		{
			if (cells(x,y)->getEntity().isValid() && cells(x,y)->getEntity()->getFaction() == 0x19 && cells(x,y)->getEntity()->getTarget() == 0 &&
				cells(x,y)->getEntity()->isHostileTo(attacker) && cells(x,y)->getEntity()->unknown45aad0(target) &&
				pointDistance(Point(x,y),target->getPosition()) <= range &&
				rng.chance(opW4_table_b98454[cells(x,y)->getEntity()->unknown9b4350()->unknown68] + bonus) &&
				isReachable(range,Point(x,y),target->getPosition()))
			{
				if (cells(x,y)->getEntity()->getGroup()->Protobuf::PingRequest::GetCachedSize() <= 2)
					statTracker.unknown4729d0(0x37c,1,"",-1);
				return cells(x,y)->getEntity();
			}
		}
	return HEntity();
}

extern struct ItemType *opW4_itemType_cefbec;	// NOTE: placeholder name

void BS::unknown74c7d0(HItemB item, bool flag)
{
	int damage = maxInt(1,item->unknown457c80() * rng.rangeInt(5.0f,15.0f) / 100);
	if (flag)
		damage = 99999;
	string desc = item->unknown571db0(false,false);
	Point point = item->unknown575920();
	int itemType = item->unknown457a30();
	if (item->unknown57ab10(damage,7,0,0,HEntity(),1,0))
	{
		HItemB fragment;
		if (rng.chance(10))
			fragment = unknown6c5400(opW4_itemType_cefbec,point);
		if (fragment.isValid())
		{
			fragment->opW4_unknown450460(fragment->unknown457c80() * rng.rangeInt(80.0f,100.0f) / 100);
			do
			{
				if (opW4_unknown5111e0(0x1ac,&desc,&string("a usable Scrap Shield Fragment"),0,HEntity(),HEntity(),&point,0))
					consoleA->unknown8758d0(true);
				consoleB->unknown7b4f10();
			} while (false);
		}
		else
		{
			do
			{
				if (opW4_unknown5111e0(0x1ac,&desc,NULL,0,HEntity(),HEntity(),&point,0))
					consoleA->unknown8758d0(true);
				consoleB->unknown7b4f10();
			} while (false);
		}
		opW4_unknown454260(point,0xa6);
		opW4_cmap->unknown8195a0(point,itemType,7);
	}
	else
	{
		do
		{
			if (opW4_unknown5111e0(0x1ab,&desc,NULL,0,HEntity(),HEntity(),&point,0))
				consoleA->unknown8758d0(true);
			consoleB->unknown7b4f10();
		} while (false);
	}
}

bool BS::unknown73cfb0()
{
	return opW4_gameState->branch == 4 && opW4_gameState->depth == 2 &&
		stringToInt(opW4_gameData.unknown46f6d0("warMaincAttacked_g")) &&
		stringToInt(opW4_gameData.unknown46f6d0("warMetWarlord_g")) &&
		!stringToInt(opW4_gameData.unknown46f6d0("warWarlordDestroyed_g")) &&
		!stringToInt(opW4_gameData.unknown46f6d0("resWarlordAttacked_g")) &&
		!stringToInt(opW4_gameData.unknown46f6d0("scrAttackedLocals_g")) &&
		!stringToInt(opW4_gameData.unknown46f6d0("scrUfdRegistered_g")) &&
		!stringToInt(opW4_gameData.unknown46f6d0("zioWasImprinted_g"));
}

class OpW4_SoundMgr	// NOTE: placeholder name (object at 0xd2d2a0)
{
public:
	void unknown454540();	// NOTE: placeholder name
	void unknown500010();	// NOTE: placeholder name
};
extern OpW4_SoundMgr opW4_soundMgr;	// NOTE: placeholder name (0xd2d2a0)
extern int opW4_gateX_d1ec6c;	// NOTE: placeholder name (a Point; split so the comparator can pair both fields)
extern int opW4_gateY_d1ec70;	// NOTE: placeholder name
extern OpW4_Map_cfd2cc opW4_map_cf35b0;	// NOTE: placeholder name (0xcf35b0)
bool opW4_unknown9d7710(OpW4_Map_cfd2cc &m, const string &key, PropData *&data);	// NOTE: placeholder name

void BS::unknown749240()
{
	opW4_gameData.unknown46f700("ac0RanGateTestB_g","1");
	int value;
	opW4_unknown9d7de0(opW4_map_d2c408,"AC0_Gate_Destruction2",value);
	const int radius = 3;
	for (int x = opW4_gateX_d1ec6c - radius; x <= opW4_gateX_d1ec6c + radius; x++)
		for (int y = opW4_gateY_d1ec70 - radius; y <= opW4_gateY_d1ec70 + radius; y++)
		{
			if (cells(x,y)->getProp().isValid())
				cells(x,y)->getProp()->unknown45ce10(true,0,true,HProp());
			if (((Point *)&opW4_gateX_d1ec6c)->opW4_is(x,y))
			{
				PropData *data;
				if (opW4_unknown9d7710(opW4_map_cf35b0,"AC0_Singularity",data))
				{
					HProp prop = opW4_entityMgr->unknown793360(data);
					cells(x,y)->unknown45df50(prop);
					prop->unknown41a800(x,y);
					opW4_soundMgr.unknown454540();
					opW4_soundMgr.unknown500010();
				}
			}
			else if (unknown6c6b90(Point(x,y),"AC0_Gate_Destruction1",0,-1) && value != 0)
			{
				cells(x,y)->getProp()->unknown665b10(value,0);
				unknown464e60(cells(x,y)->getProp());
			}
		}
}

struct OpW4_Obj462030	// NOTE: placeholder name
{
	int pad00;
	int pad04;
	vector<int> unknown8;	// NOTE: placeholder name
	int unknown18;	// NOTE: placeholder name
	Point unknown1c;	// NOTE: placeholder name
	char pad24[0x2c - 0x24];
	OpW4_Obj462030(int machine, int size, int value) throw();	// NOTE: placeholder name (0x462030)
};
void opW4_unknown4542a0(const Point &p, int a, int b);	// NOTE: placeholder name

void BS::unknown742270(bool flag)
{
	Point loc(0x4c,0x33);
	HProp gate = cells(loc)->getProp();
	if (gate.isNull())
		return;
	else if (gate->opW4_unknown44ab40() == -1)
		return;
	if (flag)
	{
		OpW4_Obj462030 *obj = new OpW4_Obj462030(gate.get_9b64f0()->opW4_unknown44ab40(),opW4_machines[gate.get_9b64f0()->opW4_unknown44ab40()].size(),500);
		obj->unknown8.assign(10u,4);
		obj->unknown18 = 0x84;
		obj->unknown1c.set(0x4a,0x36);
		unknownA80.push_back(obj);
		opW4_unknown4542a0(obj->unknown1c,0x84,0x16);
	}
	else
	{
		int iterations = 2;
		int dir = 4;
		bool seen = false;
		for (int i = 0; i < iterations; i++)
		{
			vector<HProp> &list = opW4_machines[gate->opW4_unknown44ab40()];
			vector<Point> positions;
			for (unsigned int j = 0; j < list.size(); j++)
			{
				positions.push_back(list[j]->opW4_getPosition());
				positions.back() += opW4_directions[dir];
			}
			for (unsigned int j = 0; j < list.size(); j++)
			{
				Point pos = list[j]->opW4_getPosition();
				cells(pos)->unknown45df70();
				if (!seen && list[j]->opW4_unknown9b8f00()->unknown68 != 0 && isVisible(pos))
					seen = true;
			}
			for (unsigned int j = 0; j < list.size(); j++)
			{
				cells(positions[j])->unknown45df50(list[j]);
				list[j]->unknown45cc50(positions[j]);
				if (!seen && list[j]->opW4_unknown9b8f00()->unknown68 != 0 && isVisible(positions[j]))
					seen = true;
			}
		}
		if (seen)
			unknown72e8e0(0);
		opW4_unknown454260(Point(0x4a,0x36),0x85);
	}
}

void BS::unknown74d660(const Point &pos, int count)
{
	OpW4_Area bounds;
	if (pos.x < 0x4b)
		bounds.set(4,3,0x44,0x61);
	else
		bounds.set(0x4b,0x10,0x80,0x53);
	ItemSet<EntityRecord *> classes;
	EntityRecord *robot;
	if (opW4_unknown9d7530(opW4_robotData,"Federalist",robot))
		classes.add(robot,10);
	if (opW4_unknown9d7530(opW4_robotData,"Explorer",robot))
		classes.add(robot,10);
	if (opW4_unknown9d7530(opW4_robotData,"Ranger",robot))
		classes.add(robot,10);
	if (opW4_unknown9d7530(opW4_robotData,"Guru",robot))
		classes.add(robot,10);
	if (opW4_unknown9d7530(opW4_robotData,"Scrapper_3",robot))
		classes.add(robot,0x32);
	if (opW4_unknown9d7530(opW4_robotData,"Elite_4",robot))
		classes.add(robot,10);
	vector<HEntity> placed;
	if (classes.opW4_total())
	{
		HEntity e;
		for (int i = 0; i < count; i++)
		{
			e = placeEntity(classes.pickRandom(),pos,10,false,0x22,0xe,false);
			if (e.isValid())
			{
				e->unknown45b590()->unknown459470(bounds);
				if (!placed.empty())
					e->getEntityAI()->setFollowEntity(placed.back(),0);
				placed.push_back(e);
			}
		}
	}
}

class OpW4_AI57f6a0	// NOTE: placeholder name
{
public:
	OpW4_AI57f6a0(HEntity e, int a, int b);	// NOTE: placeholder name (0x57f6a0)
	char pad[0x130];
};

void BS::unknown742c80()
{
	if (stringToInt(opW4_gameData.unknown46f6d0("frgResearchGuardsCalled_g")))
		return;
	else
		opW4_gameData.unknown46f700("frgResearchGuardsCalled_g","1");
	OpW4_Area room = unknown8cc;
	room.y2 = room.y1 + 0x1d;
	vector<HEntity> *group = groups[3]->getMembers();
	vector<HEntity> sentries;
	for (unsigned int i = 0; i < group->size(); i++)
	{
		if ((*group)[i]->getFaction() == 0x20 && room.contains((*group)[i]->getPosition()))
			sentries.push_back((*group)[i]);
	}
	if (!sentries.empty())
	{
		vector<Point> path;
		path.push_back(Point(0x1b,0xd));
		path.push_back(Point(0x42,0xd));
		path.push_back(Point(0x42,0x1f));
		path.push_back(Point(0x63,0xd));
		for (unsigned int i = 0; i < path.size(); i++)
			path[i] += *(Point *)&unknown8cc;
		for (unsigned int i = 0; i < sentries.size(); i++)
		{
			opW4_shufflePoints(path);
			sentries[i]->unknown64ecf0(new OpW4_AI57f6a0(sentries[i],2,0xe));
			sentries[i]->unknown45b590()->unknown4593d0(path);
			if (i != 0)
				sentries[i]->getEntityAI()->setFollowEntity(sentries[0],0);
		}
	}
}

void logError(string location, string message);	// NOTE: placeholder name
struct OpW4_ItemType	// NOTE: placeholder name
{
	char pad00[0x44];
	int slot;	// NOTE: placeholder name
	char pad48[0xf0 - 0x48];
	int unknownF0;	// NOTE: placeholder name
	char padF4[0x128 - 0xf4];
	int unknown128;	// NOTE: placeholder name
	char pad12c[0x1a0 - 0x12c];
	struct OpW4_ItemSub *unknown1a0;	// NOTE: placeholder name
	char pad1a4[0x238 - 0x1a4];
	bool unknown238;	// NOTE: placeholder name
};
extern vector<OpW4_ItemType *> opW4_itemTypes;	// NOTE: placeholder name (0xd2d1c4)
int opW4_unknown9d74d0(vector<OpW4_ItemType *> &v, const string &name);	// NOTE: placeholder name

void opW4_unknown746190(ItemSet<int> &pool, vector<int> &weapons)	// NOTE: placeholder name
{
	if (pool.isEmpty())
	{
		logError("loadArchitectQseriesWeaponList()","pool empty");
		return;
	}
	int k = 0;
	int small = 0;
	int chance = 0;
	int bayChance = 0;
	ItemSet<int> types;
	types.add(0,0x19);
	types.add(1,0x19);
	types.add(2,0x14);
	types.add(3,0x14);
	types.add(4,10);
	switch (types.pickRandom())
	{
	case 0:
		small = 2;
		chance = 0x19;
		bayChance = 0x19;
		break;
	case 1:
		k = 1;
		small = 1;
		chance = 0xf;
		bayChance = 0xf;
		break;
	case 2:
		k = 1;
		small = 2;
		break;
	case 3:
		k = 2;
		break;
	case 4:
		k = 2;
		small = 1;
		break;
	}
	int n;
	while (k != 0)
	{
		while (true)
		{
			n = pool.pickRandom();
			if (opW4_itemTypes[n]->slot == 0x17 || opW4_itemTypes[n]->slot == 0x15)
			{
				weapons.push_back(n);
				break;
			}
		}
		k--;
	}
	while (small != 0)
	{
		while (true)
		{
			n = pool.pickRandom();
			if (opW4_itemTypes[n]->slot == 0x16 || opW4_itemTypes[n]->slot == 0x14)
			{
				weapons.push_back(n);
				break;
			}
		}
		small--;
	}
	if (chance != 0 && rng.chance(chance))
	{
		while (true)
		{
			n = pool.pickRandom();
			if (opW4_itemTypes[n]->slot == 0x18)
			{
				weapons.push_back(n);
				break;
			}
		}
	}
	if (bayChance != 0 && rng.chance(bayChance))
	{
		int bay = opW4_unknown9d74d0(opW4_itemTypes,"Swarm Drone Bay");
		if (bay != opW4_unknown_caf164)
			weapons.push_back(bay);
	}
}

void opW4_unknown7464b0(ItemSet<int> &pool)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < opW4_itemTypes.size(); i++)
	{
		if (opW4_itemTypes[i]->unknown238 && opW4_itemTypes[i]->unknownF0 != 0xa7)
			pool.add(i,1);
	}
}

struct OpW4_TurnData	// NOTE: placeholder name
{
	char pad00[0x7c];
	int type;	// NOTE: placeholder name
	char pad80[0xa8 - 0x80];
	int unknownA8;	// NOTE: placeholder name
	char padAc[0xb8 - 0xac];
	int unknownB8;	// NOTE: placeholder name
	int unknownBC;	// NOTE: placeholder name
};
struct TurnRecord	// NOTE: placeholder layout
{
	OpW4_TurnData *data;	// NOTE: placeholder name
};
class Inventory	// NOTE: placeholder name
{
public:
	vector<TurnRecord *> *unknown518c00(int type, HEntity e, HEntity a, HEntity b, HEntity c, int d, int f, int g, int h, int i);	// NOTE: placeholder name
	bool hasType(int type);	// NOTE: placeholder name (0x456490)
	vector<TurnRecord *> *unknown51ca20(vector<int> &types, HEntity e, HEntity a, HEntity b, HItemB item, int d, int f, int g, int h, int i);	// NOTE: placeholder name
	vector<TurnRecord *> *unknown51ca20(vector<int> &types, HEntity e, HEntity a, HProp prop, HEntity c, int d, int f, int g, int h, int i);	// NOTE: placeholder name
	vector<TurnRecord *> *unknown51ca20(vector<int> &types, HEntity e, HEntity a, HEntity b, HEntity c, int d, int f, int g, int h, int i);	// NOTE: placeholder name
};
extern XConsole *opW4_console_cec0f8;	// NOTE: placeholder name
template <class T> void opW4_eraseAtIndex(vector<T> *v, unsigned int *i);	// NOTE: placeholder name (0x9de640, steps i back)
void opW4_unknown9e2c40(vector<TurnRecord *> *records);	// NOTE: placeholder name

void BS::unknown734db0(HEntity target)
{
	if (unknown320 && opW4_console_cec0f8->isHidden() && unknown318 != unknown314)
	{
		for (unsigned int i = 0; i < unknown2f4.size(); i++)
		{
			if (unknown2f4[i].operator->() != NULL)
			{
				if (unknown2f4[i]->getTarget() == 0 && unknown2f4[i]->getInventory() != NULL)
				{
					vector<TurnRecord *> *records = unknown2f4[i]->getInventory()->unknown518c00(0x39,unknown2f4[i],HEntity(),HEntity(),HEntity(),0,0,0,0,0);
					if (records != NULL)
					{
						for (unsigned int j = 0; j < records->size(); j++)
						{
							bool keep = false;
							switch (records->at(j)->data->type)
							{
							case 0:
								if (target.isNull() && unknown463400(unknown2f4[i]))
									keep = true;
								break;
							case 1:
								if (target.isNull() && player->unknown5c8820(unknown2f4[i]))
									keep = true;
								break;
							case 2:
								if (target == unknown2f4[i])
									keep = true;
								break;
							}
							if (!keep)
								opW4_eraseAtIndex(records,&j);
						}
						if (!records->empty() && turnUpdate_51da30(records,0x39,unknown2f4[i],HEntity(),HEntity(),0,0))
						{
							if (unknown2f4[i].isValid())
								unknown2f4[i]->unknown6398e0();
							if (unknown2f4[i].operator->() == NULL || unknown2f4[i]->getInventory() == NULL || (unknown2f4[i]->getInventory() != NULL && !unknown2f4[i]->getInventory()->hasType(0x39)))
							{
								unknown2f4[i]->opW4_unknown44e360(0);
								opW4_unknown9da940(unknown2f4,i);
								removeVectorElement(unknown304,i);
								i--;
							}
							opW4_mapView->unknown49ad30();
						}
						opW4_unknown9e2c40(records);
						delete records;
					}
				}
			}
			else
			{
				opW4_unknown9da940(unknown2f4,i);
				removeVectorElement(unknown304,i);
				i--;
			}
		}
		unknown314 = getTurn();
	}
}

bool opW4_unknown55ccf0(int x, int y, HEntity e, int value);	// NOTE: placeholder name
bool opW4_unknown55ce00(int x, int y, HEntity e, OpW4_TurnData *data);	// NOTE: placeholder name
void opW4_unknown55d180(OpW4_TurnData *data, vector<Point> &points);	// NOTE: placeholder name
void opW4_unknown55d2b0(OpW4_TurnData *data, HEntity e, vector<TurnRecord *> &records, const Point &p, int index, HEntity other);	// NOTE: placeholder name

void BS::unknown7373c0()
{
	vector<int> types;
	types.push_back(0x4e);
	types.push_back(0x4f);
	types.push_back(0x50);
	types.push_back(0x51);
	for (unsigned int i = 0; i < groups.size(); i++)
	{
		vector<HEntity> *members = groups[i]->getMembers();
		for (unsigned int j = 0; j < members->size(); j++)
		{
			if ((*members)[j].operator->() != NULL && (*members)[j]->getInventory() != NULL)
			{
				vector<TurnRecord *> *records = (*members)[j]->getInventory()->unknown51ca20(types,(*members)[j],HEntity(),HEntity(),HEntity(),0,0,0,0,0);
				if (records != NULL)
				{
					Point origin = (*members)[j]->unknown45a4c0();
					HEntity robot = (*members)[j];
					vector<Point> points;
					for (unsigned int k = 0; k < records->size(); k++)
					{
						TurnRecord *tr = records->at(k);
						int d = tr->data->unknownA8;
						unknown4652f0(origin,d,tr->data->unknownB8);
						points.clear();
						OpW4_Area b;
						int type2 = tr->data->unknownBC;
						cells.getRect(origin,d,b);
						for (int x = b.x1; x <= b.x2; x++)
							for (int y = b.y1; y <= b.y2; y++)
							{
								if (unknown38(x,y) == unknown44 && opW4_unknown55ccf0(x,y,robot,type2) && opW4_unknown55ce00(x,y,robot,tr->data))
									points.push_back(Point(x,y));
							}
						vector<TurnRecord *> tmp;
						tmp.push_back(tr);
						opW4_unknown55d180(tr->data,points);
						for (unsigned int m = 0; m < points.size(); m++)
							opW4_unknown55d2b0(tr->data,robot,tmp,points[m],k,HEntity());
					}
					opW4_unknown9e2c40(records);
					delete records;
				}
			}
		}
	}
}

template <class T> void opW4_eraseStep(vector<T> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440)

void BS::unknown737850()
{
	vector<int> types;
	types.push_back(0x53);
	types.push_back(0x54);
	types.push_back(0x55);
	types.push_back(0x56);
	for (unsigned int i = 0; i < unknown4f0.size(); i++)
	{
		if (unknown4f0[i].operator->() != NULL)
		{
			if (unknown4f0[i]->opW4_getInventory() == NULL)
			{
				opW4_eraseStep(unknown4f0,i);
				continue;
			}
			{
				vector<TurnRecord *> *records = unknown4f0[i]->opW4_getInventory()->unknown51ca20(types,HEntity(),HEntity(),unknown4f0[i],HEntity(),0,0,0,0,0);
				if (records != NULL)
				{
					Point origin = unknown4f0[i]->opW4_getPosition();
					vector<Point> points;
					for (unsigned int k = 0; k < records->size(); k++)
					{
						TurnRecord *tr = records->at(k);
						int d = tr->data->unknownA8;
						unknown4652f0(origin,d,tr->data->unknownB8);
						points.clear();
						OpW4_Area b;
						cells.getRect(origin,d,b);
						for (int x = b.x1; x <= b.x2; x++)
							for (int y = b.y1; y <= b.y2; y++)
							{
								if (unknown38(x,y) == unknown44 && opW4_unknown55ce00(x,y,HEntity(),tr->data))
									points.push_back(Point(x,y));
							}
						vector<TurnRecord *> tmp;
						tmp.push_back(tr);
						opW4_unknown55d180(tr->data,points);
						for (unsigned int m = 0; m < points.size(); m++)
							opW4_unknown55d2b0(tr->data,HEntity(),tmp,points[m],k,HEntity());
					}
					opW4_unknown9e2c40(records);
					delete records;
				}
			}
		}
	}
}

void BS::unknown737c90()
{
	vector<int> types;
	types.push_back(0x58);
	types.push_back(0x59);
	types.push_back(0x5a);
	types.push_back(0x5b);
	for (unsigned int i = 0; i < unknown500.size(); i++)
	{
		if (unknown500[i].operator->() != NULL)
		{
			if (unknown500[i]->opW4_getInventory() == NULL)
			{
				opW4_eraseStep(unknown500,i);
				continue;
			}
			{
				unknown500[i]->unknown575950();
				vector<TurnRecord *> *records = unknown500[i]->opW4_getInventory()->unknown51ca20(types,HEntity(),HEntity(),HEntity(),unknown500[i],0,0,0,0,0);
				if (records != NULL)
				{
					Point origin = unknown500[i]->unknown575920();
					vector<Point> points;
					for (unsigned int k = 0; k < records->size(); k++)
					{
						TurnRecord *tr = records->at(k);
						int d = tr->data->unknownA8;
						unknown4652f0(origin,d,tr->data->unknownB8);
						points.clear();
						OpW4_Area b;
						cells.getRect(origin,d,b);
						for (int x = b.x1; x <= b.x2; x++)
							for (int y = b.y1; y <= b.y2; y++)
							{
								if (unknown38(x,y) == unknown44 && opW4_unknown55ce00(x,y,HEntity(),tr->data))
									points.push_back(Point(x,y));
							}
						vector<TurnRecord *> tmp;
						tmp.push_back(tr);
						opW4_unknown55d180(tr->data,points);
						for (unsigned int m = 0; m < points.size(); m++)
							opW4_unknown55d2b0(tr->data,HEntity(),tmp,points[m],k,HEntity());
					}
					opW4_unknown9e2c40(records);
					delete records;
				}
			}
		}
	}
}

extern int opW4_unknown_d1ebe8;	// NOTE: placeholder name

void BS::unknown741190()
{
	opW4_gameData.unknown46f700("proDefenseMaincAttacked_g","1");
	do
	{
		opW4_messageLog.unknown451400(1);
		if (false)
			opW4_unknown4541b0(-1,0,0);
		do
		{
			if (opW4_unknown5111e0(0x324,&string("PUBLIC SERVICE ANNOUNCEMENT: 0b10 forces en route to main doors. Battle stations!"),0,0,HEntity(),HEntity(),NULL,0))
				consoleA->unknown8758d0(true);
			consoleB->unknown7b4f10();
		} while (false);
		consoleB->unknown7b4f10();
	} while (false);
	opW4_unknown_d1ebe8 = unknown320;
	statTracker.unknown472b90(0x38,-999999);
	do
	{
		opW4_unknown5141b0(0x15c,0,0,0,HEntity(),0);
	} while (false);
	OpW4_Area region(0x21,0x42,0x3a,0x4e);
	vector<HEntity> members(*groups[stringToInt(opW4_gameData.unknown46f6d0("proDefenseAttackedLocals_g")) ? 5 : 9]->getMembers());
	for (int i = members.size() - 1; i >= 0; i--)
	{
		removeEntity(members[i]);
		members[i]->unknown639730(true);
		if (members[i]->getFaction() == 0x1c || members[i]->getEntityAI()->getFollowEntity() == player || members[i]->unknown9b4350()->unknown48 == 0x6e || members[i]->getFaction() == 0x35)
			continue;
		members[i]->unknown45b590()->unknown459410(region);
		if (members[i]->getFaction() == 8)
			members[i]->unknown45b590()->unknown4582d0(0xb);
	}
	cells(0x3e,0x49)->unknown670ed0();
	cells(0x3e,0x4a)->unknown670ed0();
	cells(0x3e,0x4b)->unknown670ed0();
	cells(0x3e,0x4c)->unknown670ed0();
	cells(0x3e,0x4d)->unknown670ed0();
	unknown741610(true);
}

void BS::unknown745950()
{
	opW4_gameData.unknown46f700("comPlayerSurrendered_g","0");
	do
	{
		opW4_messageLog.unknown451400(1);
		if (1 && !(opW4_flag_d28fb0 && 1 && 1))
			opW4_unknown4541b0(0x127,0,0);
		do
		{
			if (opW4_unknown5111e0(0x324,&string("ALERT: LRC-V3 betrayed 0b10. Threat protocols amended."),0,0,HEntity(),HEntity(),NULL,0))
				consoleA->unknown8758d0(true);
			consoleB->unknown7b4f10();
		} while (false);
		consoleB->unknown7b4f10();
	} while (false);
	do
	{
		opW4_unknown5141b0(0x21c,0,0,0,HEntity(),0);
	} while (false);
	if (opW4_audio.enabled)
		opW4_audio.unknown69e700(0x77,0,0.0f);
	Array2D<int> *relations = unknown4638c0();
	for (int i = 0; i <= 2; i++)
	{
		(*relations)(3,i) = 0;
		(*relations)(i,3) = 0;
	}
	HEntity mainc = unknown715230(3,0x5f);
	if (mainc.isValid())
	{
		mainc->unknown6396f0("COM_Mainc_Ally_T3",true);
		mainc->unknown6396f0("COM_Mainc_Death_C",true);
		mainc->unknown6396f0("COM_Mainc_Qseries_Talk",true);
		mainc->unknown6396f0("COM_Mainc_Lagging_Talk",true);
		mainc->unknown6396f0("COM_Mainc_Win",true);
		mainc->unknown6396f0("COM_Mainc_Win_Done",true);
		unknown6c65a0(mainc,"COM_Mainc_Death_B",0);
		unknown6c65a0(mainc,"COM_Mainc_Betray_Talk",0);
		mainc->getEntityAI()->setFollowEntity(player,0);
	}
	unknown747860(0,true);
}

struct OpW4_ItemSub	// NOTE: placeholder name
{
	char pad00[0x2c];
	int unknown2c;	// NOTE: placeholder name
};
int opW4_unknown9de500(vector<int> &v);	// NOTE: placeholder name
template <class T> T randomElement(vector<T> &v);	// NOTE: placeholder name (0x9d5d00)

void opW4_unknown746520(ItemSet<int> &pool, vector<int> &out, vector<int> &weapons)	// NOTE: placeholder name
{
	vector<int> slots;
	slots.push_back(10);
	if (rng.chance(50))
		slots.push_back(rng.chance(50) ? 0x31 : 0x48);
	switch (rng.rangeInt(0.0f,2.0f))
	{
	case 0:
		slots.push_back(0x2f);
		break;
	case 1:
		slots.push_back(0x30);
		break;
	case 2:
		slots.push_back(0x32);
		break;
	}
	if (rng.chance(0x21))
		slots.push_back(0x62);
	for (unsigned int i = 0; i < weapons.size(); i++)
	{
		if (opW4_itemTypes[weapons[i]]->slot == 0x18)
		{
			if (rng.chance(0x21))
				slots.push_back(0x5d);
			break;
		}
	}
	slots.push_back(0x55);
	bool a = false;
	bool b = false;
	bool c = false;
	bool w = false;
	for (unsigned int i = 0; i < weapons.size(); i++)
	{
		switch (opW4_itemTypes[weapons[i]]->unknown1a0 ? opW4_itemTypes[weapons[i]]->unknown1a0->unknown2c : opW4_itemTypes[weapons[i]]->unknown128)
		{
		case 0:
			b = true;
			c = true;
			break;
		case 1:
			a = true;
			break;
		case 2:
			b = true;
			w = true;
			break;
		case 3:
			a = true;
			break;
		}
	}
	if (a)
	{
		slots.push_back(1);
		slots.push_back(8);
		if (rng.chance(50))
			slots.push_back(0x67);
	}
	if (b)
	{
		slots.push_back(9);
		if (c && rng.chance(50))
			slots.push_back(0x69);
	}
	if (rng.chance(0x21))
		slots.push_back(0x3d);
	if (rng.chance(50))
		slots.push_back(0x50);
	slots.push_back(1);
	for (int n = rng.rangeInt(4.0f,6.0f); n > 0; n--)
	{
		if (slots.empty())
			break;
		int id = opW4_unknown9de500(slots);
		vector<int> *p = pool.opW4_getItems();
		vector<int> m;
		for (unsigned int j = 0; j < p->size(); j++)
		{
			if (opW4_itemTypes[(*p)[j]]->unknownF0 == id)
				m.push_back((*p)[j]);
		}
		out.push_back(randomElement(m));
	}
}

void opW4_unknown6c1080(const Point &p);	// NOTE: placeholder name

void BS::unknown747400(HEntity e, HItemB item, bool flag, bool verbose)
{
	vector<Point> border;
	for (unsigned int i = 0; i < e->opW4_unknown45d1a0()->size(); i++)
	{
		vector<Point> adj;
		if (flag)
			cells.opW4_unknown9d24b0((*e->opW4_unknown45d1a0())[i],adj);
		else
			cells.getAdjacent((*e->opW4_unknown45d1a0())[i],adj);
		opW4_unknown9d80a0(border,adj);
	}
	for (unsigned int i = 0; i < border.size(); i++)
	{
		if (verbose && cells(border[i])->getProp().isValid() && !cells(border[i])->getProp()->unknown65e1d0(HEntity()) && cells(border[i])->getProp()->opW4_unknown45c630() != -1)
		{
			do
			{
				if (opW4_unknown5111e0(0x297,cells(border[i])->getProp()->opW4_unknown45c5b0(),NULL,0,e,HEntity(),NULL,0))
					consoleA->unknown8758d0(true);
				consoleB->unknown7b4f10();
			} while (false);
			cells(border[i])->getProp()->unknown45ce10(false,0,false,HProp());
		}
		if ((!cells(border[i])->isOpen() || cells(border[i])->unknown45db70()) && cells(border[i])->getArmor() != -1)
		{
			if (item.isValid())
				e->unknown5ded70(rng.rangeInt(item->unknown457fb0() * 0.5,item->unknown457fb0() * 1.5));
			if (verbose)
			{
				do
				{
					if (opW4_unknown5111e0(0x297,cells(border[i])->unknown45d140(),NULL,0,e,HEntity(),NULL,0))
						consoleA->unknown8758d0(true);
					consoleB->unknown7b4f10();
				} while (false);
			}
			cells(border[i])->unknown45e110(0,true,HProp());
			if (verbose)
				opW4_unknown6c1080(border[i]);
		}
	}
}

extern int opW4_unknown_d1ebcc;	// NOTE: placeholder name

void BS::unknown73c750()
{
	if (stringToInt(opW4_gameData.unknown46f6d0("warCounterattacked_g")) || !stringToInt(opW4_gameData.unknown46f6d0("warMaincAttacked_g")) || unknown320 < opW4_unknown_d1ebcc + 200)
		return;
	opW4_gameData.unknown46f700("warCounterattacked_g","1");
	do
	{
		opW4_messageLog.unknown451400(1);
		if (false)
			opW4_unknown4541b0(-1,0,0);
		do
		{
			if (opW4_unknown5111e0(0x324,&string("ANNOUNCEMENT: Designated combat units report to gate area for counterattack."),0,0,HEntity(),HEntity(),NULL,0))
				consoleA->unknown8758d0(true);
			consoleB->unknown7b4f10();
		} while (false);
		consoleB->unknown7b4f10();
	} while (false);
	do
	{
		opW4_unknown5141b0(0x1bb,0,0,0,HEntity(),0);
	} while (false);
	OpW4_Area gate(0x5c,0xc,0x70,0x39);
	int count = 0;
	vector<HEntity> *members = groups[9]->getMembers();
	for (unsigned int i = 0; i < members->size(); i++)
	{
		if ((*members)[i]->unknown5d51a0())
			count++;
	}
	count /= 2;
	for (unsigned int i = 0; i < members->size() && count != 0; i++)
	{
		if ((*members)[i]->unknown5d51a0() && ((*members)[i]->getFaction() == 0x10 || (*members)[i]->getFaction() == 0x11 || (*members)[i]->getFaction() == 0x12 || (*members)[i]->getFaction() == 0x3f))
		{
			(*members)[i]->unknown45b590()->unknown459470(gate);
			count--;
		}
	}
	if (!gate.contains(player->getPosition()) && !stringToInt(opW4_gameData.unknown46f6d0("warAttackedLocals_g")))
	{
		unknown6c65a0(player,"WAR_Escape_Warning",0);
		unknownA1c = true;
	}
}
