// team_d_77: BS member 0x6e2cb0 (map generation step called from BS::initilize): wall alcoves with a
// recycling unit or item caches, embedded robots, the exit area, and an occasional Warlord squad.
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();								// NOTE: placeholder name (Push_453b40::operate)
	Point(const Point &p) throw();			// 0x46ca50
	Point &operator=(const Point &p);		// NOTE: folded with the copy constructor (0x46ca50)
	void set(int x_, int y_);				// NOTE: placeholder name (Push_40a010::operate)
};

struct Pos	// NOTE: layout as in team_a_repair.cpp
{
	int x;
	int y;

	Pos(int x_, int y_);	// 0x46ca20
};

struct Rect77	// NOTE: placeholder name
{
	int x;
	int y;
	int width;
	int height;

	Rect77();							// NOTE: folded with Pos's default constructor
	Point topLeft() const;				// NOTE: placeholder name (PushBounds::topLeft)
};

struct Area77	// NOTE: placeholder name
{
	Point min;
	Point max;

	int width();	// NOTE: placeholder name (0x40b690)
	int height();	// NOTE: placeholder name (0x40b670)
};
extern Area77 area77_d1eaf8;			// NOTE: placeholder name
extern vector<Area77> areas77_d2b274;	// NOTE: placeholder name
extern vector<Area77> areas77_d204cc;	// NOTE: placeholder name

struct Range77	// NOTE: placeholder name (Point::randomInRange_40c130)
{
	int lo;
	int hi;

	int randomInRange_40c130();
};
extern Range77 ranges77_d21948[];	// NOTE: placeholder name

template <class T>
class OpR5h_WL	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	void add(T value, int weight);
	T &pick();
};

struct OpQ5_U9d7710	// NOTE: machine data record (first field: ID)
{
	int ID;
};
template <class T> bool OpQ5_findByName(vector<T*> &v, const string &name, T *&result);	// NOTE: placeholder name; const string& here (the exe instantiation takes string&)
extern vector<OpQ5_U9d7710 *> machines77_cf35b0;	// NOTE: placeholder name
extern int dirMap77_bb8360[];	// NOTE: placeholder name
extern int dirTable77_b96348[];	// NOTE: placeholder name

bool OpD_findWallStrip_6cbb40_77(int length, int depth, int type, Rect77 *strip, Rect77 *room, int *outDir, int minDistance, bool avoidMarkers, bool avoidItems);	// NOTE: placeholder name (0x6cbb40; file-unique name, the configured signature uses Rect37)
void opt4_fillRing6cba00(Rect77 *r, Rect77 *inner, int entrance, int *wall, bool caveWalls);	// NOTE: placeholder name
extern int *TERRAIN_CAVE_WALL;	// NOTE: placeholder (0xcefba0)
struct Unknown77;	// NOTE: placeholder name
extern Unknown77 &ref77_d2c46c;	// NOTE: placeholder name
int OpX5_maxInt(int a, int b);

class RNG
{
public:
	bool chance(int percent);
	int rangeInt(float lo, float hi);
};
extern RNG rng;

struct Location77	// NOTE: placeholder name and layout
{
	int unknown00;
	int type;
};

class HLoc77	// NOTE: placeholder name
{
	int ID;
public:
	Location77 *operator->() const;
};
extern HLoc77 location77_d1e888;	// NOTE: placeholder name

class Entity;

class HEntity
{
public:
	int ID;
	bool isValid() const;
	Entity *operator->() const;
};

class Entity
{
public:
	Point &getPosition();
	void unknown5fd900(int level, int duration);	// NOTE: placeholder name
};

class Item
{
public:
	int unknown_getNestedField();		// NOTE: placeholder name (Sweep_457880::getNestedField)
	int getCharges();					// NOTE: placeholder name (folded getter)
	void setCharges(int value);			// NOTE: placeholder name (folded setter)
	bool unknown457ad0();				// NOTE: placeholder name
	void setActivateOkayTurn(int turn);
};

class HItem
{
public:
	int ID;
	bool isValid() const;
	Item *operator->() const;
};

struct ItemDef;
struct EntityRec77	// NOTE: placeholder name and layout
{
	char	pad00[0x9c];
	int		size;	// +0x9c
};

class Cluster77	// NOTE: placeholder name
{
public:
	int getWidth();		// NOTE: folded getter
	int getHeight();	// NOTE: folded getter
};

struct Exit77	// NOTE: placeholder name and layout (0x60-byte record)
{
	vector<Cluster77 *>	parts;	// +0x00
	char				pad10[0x50 - 0x10];
	Point				pos;	// +0x50
	char				pad58[8];
};
extern vector<Exit77> exits77_cf124c;	// NOTE: placeholder name

class BS	// NOTE: placeholder layout
{
public:
	char	pad000[0x66c];
	HEntity	player;	// +0x66c

	void unknown6c38a0(Rect77 *rect, const vector<Point> *points, float threshold, Unknown77 &value);	// NOTE: placeholder name
	void placeMachine(int id, const Pos &pos, int dir, int a, int b);	// NOTE: placeholder signature
	ItemDef *selectRandomItem(int chanceType, int rating, int category);
	HItem unknown6c5400(ItemDef *def, const Pos &pos);					// NOTE: placeholder name
	EntityRec77 *selectRobotOfClass(int a, int id, bool b, bool c);			// NOTE: placeholder name
	HEntity placeEntity(EntityRec77 *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
	bool unknown6dd0e0(const Point &p, int type);						// NOTE: placeholder name
	bool findPlaceableNear(const Point &p, Point &out, int size);		// NOTE: placeholder name
	void unknown6c65a0(HEntity e, const string &text, int value);
	void unknown6e2cb0();	// NOTE: placeholder name
};

void BS::unknown6e2cb0()
{
	Rect77 bottom;
	Rect77 open;
	int id;
	for (int i = 0; i < 8; i++)
	{
		if (OpD_findWallStrip_6cbb40_77(3,2,4,&bottom,&open,&id,0,false,false))
		{
			opt4_fillRing6cba00(&open,&bottom,0,TERRAIN_CAVE_WALL,false);
			unknown6c38a0(&open,0,1.0f,ref77_d2c46c);
			if (rng.chance(50))
			{
				OpQ5_U9d7710 *data;
				OpQ5_findByName(machines77_cf35b0,"Recycling vH.06a",data);
				placeMachine(data->ID,Pos(open.x,open.y),dirTable77_b96348[dirMap77_bb8360[id]],0,0);
			}
			else
			{
				ItemDef *def = selectRandomItem(0,0x1f,0x12);
				if (def)
				{
					for (int x = open.x; x < open.x + open.width; x++)
					{
						for (int y = open.y; y < open.y + open.height; y++)
						{
							if (rng.chance(80))
							{
								HItem item = unknown6c5400(def,Pos(x,y));
								if (item.isValid())
								{
									if (!item->unknown_getNestedField())
										item->setCharges(ranges77_d21948[location77_d1e888->type].randomInRange_40c130());
									else
										item->setCharges(OpX5_maxInt(1,rng.rangeInt(20.0f,60.0f) * item->getCharges() / 100));
									if (!item->unknown457ad0() && rng.chance(10))
										item->setActivateOkayTurn(-2);
								}
							}
						}
					}
				}
			}
		}
	}
	for (int count = rng.rangeInt(3.0f,4.0f); count > 0; count--)
	{
		if (OpD_findWallStrip_6cbb40_77(1,1,4,&bottom,&open,&id,0,false,false))
		{
			opt4_fillRing6cba00(&open,&bottom,0,TERRAIN_CAVE_WALL,false);
			unknown6c38a0(&open,0,1.0f,ref77_d2c46c);
			EntityRec77 *rec = selectRobotOfClass(1,0x15,false,true);
			if (!rec)
			{
			}
			else
			{
				open.width = open.height = rec->size;
				HEntity e = placeEntity(rec,open.topLeft(),3,true,0x22,0xe,false);
				e->unknown5fd900(2,0);
				unknown6dd0e0(e->getPosition(),0x13);
			}
		}
	}
	exits77_cf124c.size();
	area77_d1eaf8.min = exits77_cf124c[0].pos;
	area77_d1eaf8.max.set(exits77_cf124c[0].parts.front()->getWidth() + area77_d1eaf8.min.x,exits77_cf124c[0].parts.front()->getHeight() + area77_d1eaf8.min.y);
	if (area77_d1eaf8.width() < area77_d1eaf8.height())
		area77_d1eaf8.max.y -= 5;
	else
		area77_d1eaf8.min.x += 4;
	areas77_d2b274.push_back(area77_d1eaf8);
	areas77_d204cc.push_back(area77_d1eaf8);
	if (rng.chance(3))
	{
		HEntity x;	// NOTE: unused (the exe's frame has an unreferenced slot here)
		OpR5h_WL<int> base;
		base.add(0x10,0x32);
		base.add(0xd,0x1e);
		base.add(0x11,5);
		base.add(0x12,5);
		base.add(8,5);
		base.add(0x16,5);
		Point dest(player->getPosition());
		Point temp;
		bool ok = false;
		EntityRec77 *other;
		for (int k = 0; k < 15; k++)
		{
			if (findPlaceableNear(dest,temp,1))
			{
				other = selectRobotOfClass(3,base.pick(),true,true);
				if (other)
				{
					HEntity e2 = placeEntity(other,temp,9,true,0x18,0xe,false);
					if (e2.isValid() && !ok)
					{
						unknown6c65a0(e2,"REC_Warlord_Ready",0);
						ok = true;
					}
				}
			}
		}
	}
}
