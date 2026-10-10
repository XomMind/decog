// team_d_116: BS member 0x7469f0 (caller BS::turnUpdate_74e750): warps in a depth-scaled squad of "EQ-NNN"
// robots - some near the player, some near an anchor robot, the rest anywhere on the map - each equipped from
// two weighted item pools, announcing visible arrivals with a teleport effect.
// NOTE: class layouts are partial; names other than BS/placeEntity are placeholders. Local names follow the
// stack-slot hash order.
#include <string>
#include <vector>
using namespace std;

string intToString(int value);	// 0x4051f0
string &padLeft_408090(string &text, int width, char fill);	// NOTE: placeholder name
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980)

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);	// 0x46ca20
};

struct Point
{
	int x;
	int y;

	Point();								// 0x453b40
	Point(const Point &p);					// 0x46ca50
	Point &operator=(const Point &p);		// NOTE: folded with the copy constructor
};
extern Point effectOrigin116_d2e20c;	// NOTE: placeholder name

struct Area116	// NOTE: placeholder name
{
	int x1;
	int y1;
	int x2;
	int y2;

	Area116();								// 0x40b100
	Area116(const Pos &a, const Pos &b);	// NOTE: placeholder name (0x40b160)
	Area116(const Area116 &a);				// 0x40b130
	Area116 &operator=(const Area116 &a);	// NOTE: folded with the copy constructor
	Point randomPoint_40be90();				// NOTE: placeholder name
};

template <class T> class ItemSet	// NOTE: placeholder name (as in op_w4.cpp)
{
public:
	ItemSet();
	~ItemSet();	// 0x700dd0

	vector<T> items;
	vector<int> weights;
	int total;
};

void opW4_unknown746120(ItemSet<int> &set);	// NOTE: placeholder name
void opW4_unknown746190(ItemSet<int> &pool, vector<int> &weapons);	// NOTE: placeholder name
void opW4_unknown7464b0(ItemSet<int> &pool);	// NOTE: placeholder name
void opW4_unknown746520(ItemSet<int> &pool, vector<int> &out, vector<int> &weapons);	// NOTE: placeholder name

class Entity;

class HEntity
{
public:
	int ID;
	HEntity();
	Entity *operator->() const;
};

class HProp
{
public:
	int ID;
	HProp();
};

struct ItemRecord116;	// NOTE: placeholder name
extern vector<ItemRecord116 *> itemRecords116_d2d1c4;	// NOTE: placeholder name

class Entity
{
public:
	const Point &getPosition();
	void unknown45b070(const string &name);	// NOTE: placeholder name
	void unknown5de480(ItemRecord116 *record);	// NOTE: placeholder name
	void unknown5deb40(int value);	// NOTE: placeholder name
	void unknown5ded70(int value);	// NOTE: placeholder name
	string *getName116();	// NOTE: placeholder name (folded getter XCell::getFore, +0x0c)
};

void opW5_message(int type, HProp prop, const string &text, int value);	// NOTE: placeholder name

class Cell
{
public:
	bool isPassableFor(HEntity e);
};

class CellGrid116	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(Point &p);			// NOTE: folded (OpX5_Array2D<int>::atPoint)
	Area116 getArea();					// NOTE: placeholder name (0x9b4400)
	void getRect(const Point &center, int radius, Area116 *out);	// NOTE: placeholder name (0x9b4430)
};
extern CellGrid116 cells116_cfd44c;	// NOTE: placeholder name

class TerrainGrid116	// NOTE: placeholder name (originalTerrain at 0xd378c0)
{
public:
	int *atPoint(Point &p);	// NOTE: folded (OpX5_Array2D<int>::atPoint)
};
extern TerrainGrid116 originalTerrain;	// 0xd378c0

struct TerrainType116	// NOTE: placeholder name
{
	int		ID;
};
extern TerrainType116 *TERRAIN_EARTH;	// 0xcefb80
extern TerrainType116 *TERRAIN_CAVE_WALL;	// 0xcefba0

class EffectObj116	// NOTE: placeholder name (object initialized by 0x503b20)
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name
};

class EndObjB
{
public:
	EffectObj116 *unknown508610();	// NOTE: placeholder name
};
extern EndObjB *endObj116_cefc50;	// NOTE: placeholder name

class RNG
{
public:
	int rangeInt(float lo, float hi);
};
extern RNG rng;
extern const float maxNear116_c36ed4;	// NOTE: placeholder name (4.0)

extern int depth116_d1ec5c;		// NOTE: placeholder name
extern int counter116_d1ec64;	// NOTE: placeholder name

struct EntityRecord116;	// NOTE: placeholder name

class BS	// NOTE: placeholder layout
{
public:
	char	pad000[0x66c];
	HEntity	player;		// +0x66c

	EntityRecord116 *selectRobotOfClass(int a, int b, bool c, bool d);	// NOTE: placeholder name
	HEntity unknown715230(int a, int b);	// NOTE: placeholder name
	HEntity placeEntity(EntityRecord116 *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	void unknown7469f0();	// NOTE: placeholder name
};

void BS::unknown7469f0()
{
	int level = depth116_d1ec5c - 4;
	int step = level * 2 + 0x12;
	ItemSet<int> vec2;
	opW4_unknown746120(vec2);
	ItemSet<int> arr;
	opW4_unknown7464b0(arr);
	EntityRecord116 *elem = selectRobotOfClass(2,0x1b,false,false);
	HEntity other;
	Point destination;
	HEntity base = unknown715230(3,0x5f);
	int v = OpX5_maxInt(0,3 - level);
	int counter = level == 0 ? 4 : rng.rangeInt(1.0f,maxNear116_c36ed4);
	Area116 center(Pos(0x69,0x40),Pos(0x7d,0x54));
	for (int i = 0; i < step; i++)
	{
		Area116 area;
		if (i < v)
			cells116_cfd44c.getRect(player->getPosition(),0xf,&area);
		else if (i < v + counter && base.operator->())
			cells116_cfd44c.getRect(base->getPosition(),0xf,&area);
		else
		{
			area = cells116_cfd44c.getArea();
			area.x1 = 0x10;
		}
		destination.x = -1;
		for (int t = 0; t < 200; t++)
		{
			Point p = area.randomPoint_40be90();
			if ((*cells116_cfd44c.atPoint(p))->isPassableFor(HEntity()) && *originalTerrain.atPoint(p) != TERRAIN_EARTH->ID && *originalTerrain.atPoint(p) != TERRAIN_CAVE_WALL->ID)
			{
				destination = p;
				break;
			}
		}
		if (destination.x != -1)
		{
			other = placeEntity(elem,destination,0xc,false,0x22,0xe,false);
			counter116_d1ec64++;
			other->unknown45b070("EQ-" + padLeft_408090(intToString(counter116_d1ec64),3,'0'));
			vector<int> weapons;
			opW4_unknown746190(vec2,weapons);
			vector<int> parts;
			opW4_unknown746520(arr,parts,weapons);
			for (unsigned int a = 0; a < weapons.size(); a++)
				other->unknown5de480(itemRecords116_d2d1c4[weapons[a]]);
			for (unsigned int b = 0; b < parts.size(); b++)
				other->unknown5de480(itemRecords116_d2d1c4[parts[b]]);
			other->unknown5deb40(10000);
			other->unknown5ded70(10000);
			if (unknown4631f0(other))
			{
				string msg = *other->getName116() + " warps into view.";
				opW5_message(0x320,HProp(),msg,0);
				int ret;
				if (OpU8a_lookup2("Teleport_hTR",&ret))
					endObj116_cefc50->unknown508610()->init(endObj116_cefc50,ret,other->getPosition(),effectOrigin116_d2e20c,0,0,0,9,0);
			}
		}
	}
}
