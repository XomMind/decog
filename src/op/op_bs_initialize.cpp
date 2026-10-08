// op_bs_initialize: BS::initialize (0x701390), on the map holding the 0b10 backdoor data, picks a room (an
// existing remote room, a dug-out side room, or a prop location), clears it and places CY-PHR with the data
// (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
	Point() throw();	// 0x453b40
	Point &set_46ca50(const Point &p) throw();	// NOTE: placeholder name (folded with the copy ctor)
	void set_40a010(int x_, int y_) throw();	// NOTE: placeholder name
};
struct Pos : Point
{
	explicit Pos(int v) throw();	// 0x409990
};
struct Rect
{
	int x;
	int y;
	int w;
	int h;
	Rect(int x_, int y_, int w_, int h_) throw();	// 0x456940
	Rect &set_40a720(const Rect &r) throw();	// NOTE: placeholder name (folded with the copy ctor)
	int right_40ac20() const;	// NOTE: placeholder name
	int bottom_40ac40() const;	// NOTE: placeholder name
	Point center() const;	// NOTE: placeholder name (0x40ad40)
};

struct OpBI_Terrain { int id; };	// NOTE: placeholder name
extern OpBI_Terrain *TERRAIN_EARTH;
extern OpBI_Terrain *opBI_wall_cefb9c;	// NOTE: placeholder name

class Entity
{
public:
	const Point &getPosition();	// 0x45a4a0
	void unknown637bb0();	// NOTE: placeholder name
};
class HEntity
{
public:
	int ID;
	Entity *operator->() const;	// 0x9b6570
	bool isValid() const;	// 0x9b65e0
	bool isNull() const;	// 0x9b65d0
	bool operator==(HEntity other) const;	// 0x9b6500
};
class Item
{
public:
	void remove57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown57a0f0(const Point &p, int a, int b);	// NOTE: placeholder name
};
class HItem
{
public:
	int ID;
	HItem();	// 0x9b6590
	bool isValid() const;	// 0x9b65e0
	Item *get224() const;	// NOTE: placeholder name
};
struct OpBI_PropRecord { char pad[0x10]; bool unknown10; };	// NOTE: placeholder name
class Prop
{
public:
	OpBI_PropRecord *getRecord_45cb30();	// NOTE: placeholder name (folded getter)
	const Point &getPos_4184d0();	// NOTE: placeholder name (folded getter)
};
class HProp
{
public:
	int ID;
	Prop *get22c() const;	// NOTE: placeholder name (0x9b64f0)
};
class Cell
{
public:
	HEntity getEntity();	// 0x45d250
	HProp getProp();	// 0x45d550
	HItem getItem();	// 0x45d8f0
	bool unknown45dcf0();	// NOTE: placeholder name
	OpBI_Terrain *getTerrain_41a6e0();	// NOTE: placeholder name (folded getter)
	void removeProp(int a, int b);	// 0x66c100
	void unknown66a050(int terrain, int a, int b);	// NOTE: placeholder name
};
class OpBI_Grid	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(Point &p);	// NOTE: placeholder name
	Cell **at(int x, int y);	// NOTE: placeholder name
	int getWidth();	// NOTE: placeholder name
	int getHeight();	// NOTE: placeholder name
	bool contains(const Point &p);	// NOTE: placeholder name
};
extern OpBI_Grid opBI_cells_cfd44c;	// NOTE: placeholder name

struct OpBI_Room	// NOTE: placeholder name (DF::Room, 0x6c bytes)
{
	OpBI_Room();	// 0x4bd0f0
	~OpBI_Room();	// 0x4bd140
	int pad00;
	Rect bounds;	// +0x04
	char pad18[0x28 - 0x14];
	vector<Point> exits;	// +0x28
	char pad38[0x48 - 0x38];
	vector<int> corridors;	// +0x48
	char pad58[0x6c - 0x58];
};
extern vector<OpBI_Room> opBI_rooms_cf13e8;	// NOTE: placeholder name
struct OpBI_Corridor	// NOTE: placeholder name
{
	vector<Point> points;	// +0x00
	vector<int> rooms;	// +0x10
};
extern vector<OpBI_Corridor> opBI_corridors_cf65c4;	// NOTE: placeholder name

class Cartographer2D
{
public:
	bool findPath(const Point &from, const Point &to, class Cartographer2DMoveCost *cost, void *data, vector<Point> &path);
};
extern Cartographer2D opBI_cartographer_cfe568;	// NOTE: placeholder name
extern class Cartographer2DMoveCost *opBI_cost_cefc30;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);	// 0x406c90
	int rangeInt(float a, float b);	// 0x406d70
};
extern RNG rng;

struct EntityRecord;
extern vector<EntityRecord *> opBI_entityRecords_d25de0;	// NOTE: placeholder name
struct OpBI_ItemRecord;
extern vector<OpBI_ItemRecord *> opBI_itemRecords_d2d1c4;	// NOTE: placeholder name
class OpBI_Factory	// NOTE: placeholder name (0xcefaa8)
{
public:
	HItem createD(OpBI_ItemRecord *record);	// NOTE: placeholder name (0x7932b0)
};
extern OpBI_Factory *opBI_factory_cefaa8;	// NOTE: placeholder name

class OpBI_Expiry	// NOTE: placeholder name
{
public:
	void reset_45f0a0();	// NOTE: placeholder name
	void unknown45f070(void *value);	// NOTE: placeholder name
};
struct OpBI_Tracked { char pad[0x110]; int index; };	// NOTE: placeholder name
extern OpBI_Tracked *opBI_cf68b4;	// NOTE: placeholder name
extern HEntity opBI_cyphr_cf68b8;	// NOTE: placeholder name
extern vector<int> opBI_cf68dc;	// NOTE: placeholder name
extern OpBI_Expiry opBI_cf68ac;	// NOTE: placeholder name
extern OpBI_Expiry opBI_cf68c0;	// NOTE: placeholder name
extern OpBI_Expiry opBI_cf6a3c;	// NOTE: placeholder name
extern OpBI_Expiry opBI_cf6a44;	// NOTE: placeholder name
extern char opBI_d1deec[];	// NOTE: placeholder name
extern char opBI_d29ad0[];	// NOTE: placeholder name
class OpBI_Unit	// NOTE: placeholder name (OpS4_Unit at 0xcf6888)
{
public:
	void unknown699720(EntityRecord *record, int a);	// NOTE: placeholder name
};
extern OpBI_Unit opBI_unit_cf6888;	// NOTE: placeholder name
extern bool opBI_cf6a24;	// NOTE: placeholder name
extern HEntity opBI_cf6a28;	// NOTE: placeholder name
extern HEntity opBI_current_d1e888;	// NOTE: placeholder name
extern int opBI_reverse_bb8360[];	// NOTE: placeholder name
extern const float opBI_three_c36ecc;	// NOTE: placeholder name (3.0)
extern const float opBI_seven_c36ffc;	// NOTE: placeholder name (7.0)

void logError(string location, string message);	// 0x404f10
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name
int OpX5_minInt(int a, int b);	// NOTE: placeholder name
void opBI_insertAt(vector<int> &v, int index, int value);	// NOTE: placeholder name (OpX5_insertAt)
void OpT8a_eraseAt(vector<int> &v, unsigned int &index);	// NOTE: placeholder name
bool OpX5_containsRecord(vector<int> &v, int value);	// NOTE: placeholder name
int OpS8b_Fn9d4500(vector<int> &v);	// NOTE: placeholder name (index of max)
int OpS8b_Fn9d4660(vector<int> &v, int value);	// NOTE: placeholder name (index of)
bool OpS8b_Fn9d51d0(vector<int> &v, int value);	// NOTE: placeholder name (remove value)
bool OpD_digRoomExit_6cc8a0(int room, int chance, bool flag);	// NOTE: placeholder name
void opBI_appendVector(vector<Point> &to, vector<Point> &from);	// NOTE: placeholder name (OpQ5_appendVector)
void OpS8c_appendUnique(vector<Point> &to, vector<Point> &from);	// NOTE: placeholder name
void OpB_translateRotated(Point &p, int dir, int a, int b);	// NOTE: placeholder name
void opBI_shuffle(vector<HProp> &v);	// NOTE: placeholder name (OpV4c_shuffle)
template <class T> bool OpQ5_findByName(vector<T *> &list, const string &name, T *&out);	// NOTE: placeholder name
int OpU8a_indexOfName(vector<OpBI_ItemRecord *> &list, const string &name);	// NOTE: placeholder name

class BS	// NOTE: placeholder layout
{
public:
	void initialize(vector<int> &rooms);
	bool unknown716940(const Point &from, const Point &to, void *e, int *length);	// NOTE: placeholder name
	void unknown701030(OpBI_Room *room, Point &target, vector<Point> *path);	// NOTE: placeholder name
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name
	HEntity placeEntity(EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);

	char pad000[8];
	Point playerPos;	// +0x08, NOTE: placeholder name
	char pad010[0x118 - 0x10];
	vector<vector<Point> > markers;	// +0x118, NOTE: placeholder name
	char pad128[0xc38 - 0x128];
	vector<int> visited;	// +0xc38, NOTE: placeholder name
};

void BS::initialize(vector<int> &rooms)
{
	if (opBI_cf6a24 && opBI_current_d1e888 == opBI_cf6a28)
	{
		vector<int> list;
		list.push_back(0);
		if (rng.chance(50))
			list.push_back(1);
		else
			opBI_insertAt(list,0,1);
		list.push_back(2);
		Pos first(-1);
		for (unsigned int i = 0; i < list.size(); i++)
		{
			switch (list[i])
			{
				case 0:
				{
					vector<int> candidates(rooms);
					for (unsigned int j = 0; j < candidates.size(); j++)
					{
						if (opBI_rooms_cf13e8[candidates[j]].bounds.w < 5 || opBI_rooms_cf13e8[candidates[j]].bounds.h < 5 || OpQ1_distanceCeil_40a3f0(opBI_rooms_cf13e8[candidates[j]].bounds.center(),playerPos) < 25)
							OpT8a_eraseAt(candidates,j);
					}
					if (!candidates.empty())
					{
						vector<int> scores;
						for (unsigned int k = 0; k < candidates.size(); k++)
						{
							int length;
							if (!OpX5_containsRecord(visited,candidates[k]) && unknown716940(playerPos,opBI_rooms_cf13e8[candidates[k]].bounds.center(),0,&length))
								scores.push_back(length);
							else
								scores.push_back(-1);
						}
						int best = OpS8b_Fn9d4500(scores);
						if (scores[best] == -1)
							break;
						else
						{
							OpBI_Room *room = &opBI_rooms_cf13e8[candidates[best]];
							int exits = room->exits.size() + room->corridors.size();
							if (exits >= 2 || OpD_digRoomExit_6cc8a0(candidates[best],0x32,true))
							{
								OpS8b_Fn9d51d0(rooms,best);
								first.set_46ca50(room->bounds.center());
								for (int x = room->bounds.x; x <= room->bounds.right_40ac20(); x++)
								{
									for (int y = room->bounds.y; y <= room->bounds.bottom_40ac40(); y++)
									{
										if ((*opBI_cells_cfd44c.at(x,y))->getEntity().isValid())
											(*opBI_cells_cfd44c.at(x,y))->getEntity()->unknown637bb0();
										if ((*opBI_cells_cfd44c.at(x,y))->unknown45dcf0())
											(*opBI_cells_cfd44c.at(x,y))->removeProp(1,4);
										if ((*opBI_cells_cfd44c.at(x,y))->getItem().isValid())
											(*opBI_cells_cfd44c.at(x,y))->getItem().get224()->remove57dbe0(0,0,1,1);
									}
								}
								vector<Point> path;
								if (exits > 1)
								{
									vector<Point> doors;
									opBI_appendVector(doors,room->exits);
									if (!room->corridors.empty())
									{
										for (unsigned int d = 0; d < room->corridors.size(); d++)
											doors.push_back(opBI_corridors_cf65c4[room->corridors[d]].points[OpS8b_Fn9d4660(opBI_corridors_cf65c4[room->corridors[d]].rooms,candidates[best])]);
									}
									for (unsigned int a = 0; a < doors.size(); a++)
									{
										for (unsigned int b = a + 1; b < doors.size(); b++)
										{
											vector<Point> segment;
											if (opBI_cartographer_cfe568.findPath(doors[a],doors[b],opBI_cost_cefc30,0,segment))
												OpS8c_appendUnique(path,segment);
										}
									}
								}
								unknown701030(room,first,&path);
								goto placed;
							}
						}
					}
					break;
				}
				case 1:
				{
					int count = OpX5_minInt(opBI_cells_cfd44c.getWidth() / 3,opBI_cells_cfd44c.getHeight() / 3);
					int a = 5;
					int b = 2;
					int c = 7;
					for (int t = 0; t < 300; t++)
					{
						Point p;
						int kind = rng.rangeInt(0.0f,opBI_three_c36ecc);
						switch (kind)
						{
							case 0:
								p.set_40a010(rng.rangeInt(opBI_seven_c36ffc,opBI_cells_cfd44c.getWidth() - 7),opBI_cells_cfd44c.getHeight() - 1);
								break;
							case 1:
								p.set_40a010(0,rng.rangeInt(opBI_seven_c36ffc,opBI_cells_cfd44c.getHeight() - 7));
								break;
							case 2:
								p.set_40a010(rng.rangeInt(opBI_seven_c36ffc,opBI_cells_cfd44c.getWidth() - 7),0);
								break;
							case 3:
								p.set_40a010(opBI_cells_cfd44c.getWidth() - 1,rng.rangeInt(opBI_seven_c36ffc,opBI_cells_cfd44c.getHeight() - 7));
								break;
						}
						int h = 0;
						while ((*opBI_cells_cfd44c.atPoint(p))->getTerrain_41a6e0() == TERRAIN_EARTH)
						{
							h++;
							OpB_translateRotated(p,kind,0,1);
							if (!opBI_cells_cfd44c.contains(p))
								goto next;
						}
						if (h >= 7 && OpQ1_distanceCeil_40a3f0(p,playerPos) >= count)
						{
							for (int k = 0; k < 4; k++)
								OpB_translateRotated(p,opBI_reverse_bb8360[kind],0,1);
							Rect bottom(p.x - 2,p.y - 2,5,5);
							bool changed = true;
							for (int x = bottom.x; x <= bottom.right_40ac20(); x++)
							{
								for (int y = bottom.y; y <= bottom.bottom_40ac40(); y++)
								{
									if ((*opBI_cells_cfd44c.at(x,y))->getTerrain_41a6e0() != TERRAIN_EARTH)
									{
										changed = false;
										break;
									}
								}
							}
							if (changed)
							{
								for (int x = bottom.x; x <= bottom.right_40ac20(); x++)
								{
									for (int y = bottom.y; y <= bottom.bottom_40ac40(); y++)
										(*opBI_cells_cfd44c.at(x,y))->unknown66a050(opBI_wall_cefb9c->id,2,0);
								}
								OpBI_Room room;
								opBI_rooms_cf13e8.push_back(room);
								OpBI_Room *id = &opBI_rooms_cf13e8.back();
								id->bounds.set_40a720(bottom);
								if (OpD_digRoomExit_6cc8a0(opBI_rooms_cf13e8.size() - 1,0x32,false))
								{
									OpD_digRoomExit_6cc8a0(opBI_rooms_cf13e8.size() - 1,0x64,false);
									first.set_46ca50(bottom.center());
									unknown701030(id,first,0);
									goto placed;
								}
								else
								{
									for (int x = bottom.x; x <= bottom.right_40ac20(); x++)
									{
										for (int y = bottom.y; y <= bottom.bottom_40ac40(); y++)
											(*opBI_cells_cfd44c.at(x,y))->unknown66a050(TERRAIN_EARTH->id,2,0);
									}
								}
								opBI_rooms_cf13e8.pop_back();
							}
						}
next:
						;
					}
					break;
				}
				case 2:
				{
					vector<HProp> props;
					for (unsigned int k = 0; k < markers[0].size(); k++)
					{
						if (!(*opBI_cells_cfd44c.atPoint(markers[0][k]))->getProp().get22c()->getRecord_45cb30()->unknown10)
							props.push_back((*opBI_cells_cfd44c.atPoint(markers[0][k]))->getProp());
					}
					opBI_shuffle(props);
					int count = OpX5_minInt(opBI_cells_cfd44c.getWidth() / 3,opBI_cells_cfd44c.getHeight() / 3);
					for (int pass = 0; pass < 2; pass++)
					{
						for (unsigned int k = 0; k < props.size(); k++)
						{
							if ((pass != 0 || OpQ1_distanceCeil_40a3f0(props[k].get22c()->getPos_4184d0(),playerPos) >= count) && findPlaceableNear(props[k].get22c()->getPos_4184d0(),first,1))
								goto placed;
						}
					}
					break;
				}
			}
		}
placed:
		if (first.x == -1)
			logError("BS::initialize()","UC room fail");
		else if (true)
		{
			if (opBI_cf68b4)
			{
				opBI_cf68dc[opBI_cf68b4->index] = 1;
				opBI_cf68ac.reset_45f0a0();
				opBI_cf68b4 = 0;
				opBI_cf68c0.reset_45f0a0();
			}
			EntityRecord *record;
			if (OpQ5_findByName(opBI_entityRecords_d25de0,"CY-PHR",record))
			{
				opBI_cyphr_cf68b8 = placeEntity(record,first,0xb,true,1,0xe,true);
				if (opBI_cyphr_cf68b8.isNull())
					logError("BS","CY fail");
				else
				{
					opBI_unit_cf6888.unknown699720(record,0);
					opBI_cf6a3c.unknown45f070(opBI_d1deec);
					opBI_cf6a44.unknown45f070(opBI_d29ad0);
					HItem data = opBI_factory_cefaa8->createD(opBI_itemRecords_d2d1c4[OpU8a_indexOfName(opBI_itemRecords_d2d1c4,"0b10 Backdoor Data")]);
					data.get224()->unknown57a0f0(opBI_cyphr_cf68b8->getPosition(),0,0);
				}
			}
		}
	}
}
