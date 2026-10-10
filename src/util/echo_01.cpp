// NOTE: placeholder names and partial layouts; BS::placeRandomEncounter (0x6f1e90): picks weighted random
// encounters for the current map, places their prefabs into areas/rooms and spawns their contents.
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;
struct E6Hit : vector<int> {};	// NOTE: placeholder (exe: a 16-byte element type distinct from vector<int>)

struct E6View;
struct E6Point
{
	int x, y;
	E6Point();	// 0x453b40
	E6Point(int x_, int y_);	// 0x46ca20
	E6Point(int v);	// 0x409990
	E6Point(const E6Point &p);	// 0x46ca50
	E6Point(const E6Point &p, int dx, int dy);	// 0x4099c0
	E6Point(const E6Point &a, const E6Point &b);	// 0x4099f0
	int randomInRange();	// 0x40c130
	bool isAdjacent(const E6Point &p);	// 0x409e20
	bool eq409bd0(const E6Point &p);	// 0x409bd0
	bool test409cf0(int x_, int y_);	// 0x409cf0
	bool test409cb0(int x_, int y_);	// 0x409cb0
	E6Point &operator=(const E6Point &p);	// 0x46ca50
	void set(int x_, int y_);	// 0x40a010
};
struct E6Rect	// x, y, w, h
{
	int x, y, w, h;
	E6Rect();	// 0x40a6e0
	E6Rect(int x_, int y_, int w_, int h_);	// 0x456940
	E6Rect(const E6Point &p);	// 0x40a7a0
	E6Rect(const E6Point &p, int w_, int h_);	// 0x40a760
	E6Rect(const E6Rect &r);	// 0x40a720
	E6Rect &operator=(const E6Rect &r);	// 0x40a720
	void set(int x_, int y_, int w_, int h_);	// 0x40a840
	int right();	// 0x40ac20
	int bottom();	// 0x40ac40
	E6Point randomPos();	// 0x40b080
	void expandToInclude(const E6Point &p);	// 0x40af10
	void grow(int n);	// 0x40afb0
	bool contains(int x_, int y_);	// 0x40a9a0
	bool touches(const E6Rect &r);	// 0x40aef0
	bool containsPos(const E6Point &p);	// 0x40aa00
	E6Point topLeft();	// 0x40a970
};
struct E6Area	// x1, y1, x2, y2
{
	E6Point p1, p2;
	E6Area();	// 0x40b100
	E6Area(const E6Point &a, const E6Point &b);	// 0x40b160
	E6Area(int x1, int y1, int x2, int y2);	// 0x40b1e0
	E6Area(const E6Rect &r);	// 0x40b290
	void set(const E6Point &a, const E6Point &b);	// 0x40b330
	bool contains(int x, int y);	// 0x40b700
	bool contains(const E6Point &p);	// 0x40b750
	bool contains(const E6Rect &r);	// 0x40b7e0
	bool contains(const E6Area &a);	// 0x40b8a0
	void include(const E6Point &p);	// 0x40bb90
	void grow(int n);	// 0x40bc10
	E6Point randomPoint();	// 0x40be90
	E6Point center();	// 0x40b620
	void set(const E6Point &p, int w, int h);	// 0x40b360
	void randomPoint(E6Point *out);	// 0x40be30
};
struct E6Color
{
	unsigned char r, g, b;
	E6Color(const E6Color &o);	// 0x411e30
	bool operator!=(E6Color o);	// 0x411f90
	bool operator==(E6Color o);	// 0x411f40
};
struct E6XCell
{
	E6Color &getBack();	// 0x416f60
	int getChar();	// 0x9b8f00
};
struct E6Grid	// art layer
{
	int w, h;
	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
	E6XCell *at(int x, int y);	// 0x9cdf20
	E6XCell *atPoint(const E6Point &p);	// 0x9d2930
	bool contains(const E6Point &p);	// 0x9b43b0
	E6Area getArea();	// 0x9b4400
};
struct E6Prefab
{
	vector<E6Grid *> layers;
	string s10;
	string s2c;
	int f48, f4c;
	E6Point origin;
	int rot;
	bool flipped;
	E6Prefab();	// 0x448c00
	~E6Prefab();	// 0x4c1430
	void operator=(const E6Prefab &o);	// 0x448de0
	void rotate(bool glyphs);	// 0x447010
	void flipHorizontal(bool glyphs);	// 0x447840
};
struct E6Prop;
struct E6HProp {int id; bool isNull() const; bool isValid() const; E6Prop *operator->() const;};	// 0x9b65d0, 0x9b7230, 0x9b64f0
struct E6Item
{
	void remove57dbe0(bool a, bool b, bool c, bool d);	// 0x57dbe0
	int nested457880();	// 0x457880
	void set450460(int v);	// 0x450460
	int get9b6bf0();	// 0x9b6bf0
	bool unknown457ad0();	// 0x457ad0
	void setActivateOkayTurn(int t);	// 0x4583b0
	void setScaled579880(int v);	// 0x579880
	void set44fc60(int v);	// 0x44fc60
	void unknown57a0f0(const E6Point &p, int a, int b);	// 0x57a0f0
	void addEffect(struct E6Effect *e);	// 0x4585a0
};
struct E6HItem {int id; bool isValid() const; bool isNull() const; E6Item *operator->() const;};	// 0x9b7230, 0x9b65b0
struct E6Entity;
struct E6HE {int id; E6HE() throw(); bool isValid() const; bool isNull() const; E6Entity *operator->() const;};	// 0x9b65d0	// 0x9b6590, 0x9b7230, 0x9b6570
struct E6AI
{
	void unknown4593b0(const E6Point &p);	// 0x4593b0
	void unknown459470(const E6Area &a);	// 0x459470
	void unknown4594c0(void *room);	// 0x4594c0
	void setFollowEntity(E6HE e, int mode);	// 0x5b2f80
	vector<E6Point> &unknown458ef0();	// 0x458ef0
};
struct E6Entity
{
	E6AI *getAI();	// 0x45b590
	void unknown5fd900(int a, int b);	// 0x5fd900
	void unknown5dea60(int a, int b);	// 0x5dea60
	void unknown5dcc70(int a, int b);	// 0x5dcc70
	int field490840();	// 0x490840
	vector<E6HItem> *getInventoryList();	// 0x45ab00
	const E6Point &getPosition();	// 0x45a4a0
	void unknown6395d0(struct E6Talk *talk, bool b);	// 0x6395d0
};
struct E6Rec2 {char pad0[0x28]; int f28; char pad2c[0x9c - 0x2c]; int size9c;};
struct E6ItemType;
struct E6Marker
{
	E6Point pos;
	char pad[0x58];
	E6Marker(const E6Point &p, E6HItem item, int b, E6HE e1, E6HE e2) throw();	// 0x6c13a0
};
struct E6MachineDef
{
	int id;
	char pad4[0x3c - 4];
	vector<E6Grid *> layers;
	char pad4c[0xf4 - 0x4c];
	int kind;
	int f8;
	char padfc[4];
	int weight100;
	int f104;
	char pad108[0x118 - 0x108];
	int group118;
};
struct E6IntArr
{
	char pad[0xc];
	E6IntArr();	// 0x9d2670
	~E6IntArr();	// 0x9cec20
	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
	int *at(int x, int y);	// 0x9ceda0
};
struct E6PointArr
{
	char pad[0xc];
	E6PointArr();	// 0x9d2670
	~E6PointArr();	// 0x9cec20
	E6Point *at(int x, int y);	// 0x9d3330
};
struct E6Group {char pad[4]; E6HE leader;};
struct E6Overmind
{
	int spawnPatrolParty(E6HE e, int a, int b, void *room, int c, int d, int f, int g, int h);	// 0x6896d0
	E6Group *lastParty();	// 0x45ed10
	void members683410(E6HE leader, vector<E6HE> &out);	// 0x683410
};
extern E6Overmind e6_overmind_cf6428;
struct E6Terrain;
struct E6HE;
struct E6Cell
{
	int terrain();	// 0x45d0e0
	E6HProp getProp();	// 0x45d550
	bool solid66a630();	// 0x66a630
	bool isMachinePart();	// 0x45dcd0
	E6HItem getItem();	// 0x45d8f0
	bool isPassableFor(E6HE e);	// 0x66ab30
	bool unknown45db70();	// 0x45db70
	bool field4550b0();	// 0x4550b0
	E6Terrain *terrainPtr();	// 0x9fcd80
	void unknown66b700(int a, int b);	// 0x66b700
	bool hasBlockingObject();	// 0x45d7b0
	E6HE getEntity();	// 0x45d250
};
struct E6Map
{
	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
	E6Cell **at(int x, int y);	// 0x9ceda0
	E6Cell **atPoint(const E6Point &p);	// 0x9ced70
	bool contains(const E6Point &p);	// 0x9b43b0
	bool inBounds(int x, int y);	// 0x9b45c0
	E6Area getArea();	// 0x9b4400
	void getRandom(E6Point *out);	// 0x9cf0c0
	void getRect(const E6Point &p, int r, E6Area &out);	// 0x9b4430
};
extern E6Map e6_cells_cfd44c;
struct E6IntGrid
{
	int *at(int x, int y);	// 0x9ceda0
	int *atPoint(const E6Point &p);	// 0x9ced70
	void resize(int w, int h, void *src);	// 0x9d4090
	void zero();	// 0x9d23e0
	void fillRect(const E6Point &a, const E6Point &b, int v);	// 0x9cf6c0
};
extern E6IntGrid e6_grid_cf11a0;
extern E6IntGrid e6_grid_cf1964;
extern E6IntGrid e6_grid_cf447c;
struct E6Terrain {int id;};
extern E6Terrain *TERRAIN_EARTH, *TERRAIN_CAVE_WALL, *e6_floor_cefb9c, *e6_door_cefbb0, *e6_terrain_cefba8, *e6_terrain_cefbac, *e6_terrain_cefb84, *e6_terrain_cefb88;
extern vector<E6Terrain *> e6_terrains_cfb844;
extern int e6_d2c46c;
extern E6Point e6_ranges_d21948[];
extern E6Point e6_range_d25dd8;
extern E6Point e6_range_d389bc;
extern bool e6_allowed_b9e6f0[][23];
struct E6Layout {int a, b, c, d, e, f;};
extern E6Layout e6_layout_b9f5c0[];
extern E6Layout e6_layoutC_b9f5c8[];
extern E6Layout e6_layoutD_b9f5cc[];
extern int e6_none_caf15c;
extern int e6_dirTable_b96348[];
extern E6Color *e6_color_d338bc;
extern E6Color e6_colors_cf127c[];
extern const char e6_empty_b958bb[];
class E6WL	// weighted int list (OpR5h_WL<int>)
{
public:
	vector<int> values;
	vector<int> weights;
	int total;
	E6WL();	// 0x9bab50
	E6WL(vector<int> &w);	// 0x9baaa0
	~E6WL();	// 0x700dd0
	void add(int value, int weight);	// 0x9ba310
	int &pick();	// 0x9ba470
	int &pickNT() throw();	// 0x9ba470
	void remove(int value);	// 0x9bab80
	void removeAt(int index);	// 0x9c1d20
	bool pick(int *out);	// 0x9ba6a0
	bool setWeight(int value, int weight);	// 0x9ba9a0
	bool setWeightAt(unsigned int index, int weight);	// 0x9baa30
	int getWeight(int *value);	// 0x9b6f60
	void pickAll(vector<int> &out);	// 0x9b6e70
	int size();	// 0x9b81d0
	bool empty();	// 0x9b81b0
	vector<int> *getValues();	// 0x9c0790
	vector<int> *getWeights();	// 0x462e10
};
struct E6Rec	// encounter record
{
	int id;
	string name;
	int f20;
	int type24;
	char pad28[8];
	int f30;
	char group34;
	char tag35;
	string exclusions;
	int priority;
	int maxSize;
	E6Area bounds;
	int roomMode;
	int listMode;
	int f74;
	int sizeMode;
	int f7c;
	vector<int> depthWeights;
	int f90;
	vector<int> doorWeights;
	int fa4;
	char pada8[4];
	E6Point extraRange;
	int fb4;
	bool canFlip;
	bool b9;
	float fbc;
	bool bc0;
	bool bc1;
	vector<int> prefabs;
	E6WL prefabWeights;
	int minW;
	int minH;
	bool unknown517290();
};
struct E6AreaRec	// 0x6c
{
	char pad0[4];
	E6Rect rect;
	char pad14[0x28 - 0x14];
	vector<E6Point> pts;
	vector<int> rots;
	vector<int> v48;
	char pad58[4];
	vector<int> v5c;
};
struct E6Room	// 0x54
{
	vector<E6Point> points;
	vector<int> v10;
	vector<E6Point> v20;
	vector<int> v30;
	char pad40[4];
	bool b44;
	int cx;
	int cy;
};
struct E6Zone	// 0x60
{
	vector<E6Grid *> layers;
	char pad10[0x50 - 0x10];
	E6Point origin;
	char pad58[8];
};
extern vector<E6Rec *> e6_records_d21afc;
extern vector<int> e6_vec_d1e8d0;
extern vector<E6AreaRec> e6_areas_cf13e8;
extern vector<E6Room> e6_rooms_cf126c;
extern vector<E6Zone> e6_zones_cf124c;
extern vector<E6Prefab *> e6_prefabs_d161c4;
extern int e6_weights_ba656c[][3];
extern int e6_pct_b942d0[];
extern int e6_keep_b942cc;
extern int e6_diff_cf4718;
extern bool e6_noArea_b90158[];
extern int e6_rotCount_bb8370[];
extern int e6_dir_bb8360[];
extern const double e6_mul_c36cc8;
extern bool e6_flag_d1e880, e6_flag_cf474c, e6_flag_d257e9, e6_flag_d257ea;
struct E6Location
{
	char pad0[4];
	int dlev;
	int f8;
	char padc[0x24 - 0xc];
	bool b24;
	char pad25[0x30 - 0x25];
	vector<int> list30;
	int getDepthIndex();	// 0x46ed20
	E6HItem find(int type) throw();	// 0x46ee80
};
struct E6HLocation {int id; E6HLocation(); E6Location *operator->() const throw();};	// 0x9b6590	// 0x9b7910
extern E6HLocation e6_location_d1e888;
int e6_maxInt(int a, int b);	// 0x9cdb60
int e6_minInt(int a, int b);	// 0x9cdb30
bool e6_contains(vector<int> &v, int value);	// 0x9db330
void e6_appendIndices(vector<int> &src, vector<int> &dst);	// 0x9e3380
void e6_shuffle(vector<int> &v);	// 0x9d8f80
bool e6_inRoom(vector<E6Point> &v, E6Point p);	// 0x9d0ce0
E6Point e6_randomPoint(vector<E6Point> &v);	// 0x9d5350
int e6_randomRec(vector<int> &v);	// 0x9d5d00
bool e6_between(int lo, int v, int hi);	// 0x9daf80
int e6_findColor(E6Color *colors, unsigned int n, E6Color c);	// 0x9d4f10
void e6_translate(E6Point *p, int dir, int a, int b);	// 0x446dd0
void e6_setTerrainAt(E6Point &p, E6Terrain *t);	// 0x6c9c90
void e6_setTerrain(int x, int y, E6Terrain *t);	// 0x6c9b40
void sweepGetSurroundingCells(const E6Point &p, vector<E6Point> &out);	// 0x4faaf0
void e6_removeElement(vector<int> &v, int index);	// 0x9de6f0 (removeVectorElement<int>)
int OpT8a_sumVector(vector<int> &v);	// 0x9cdbd0 (defined in src/op/op_t8a.cpp)
int e6_randomIndex(vector<int> &v);	// 0x9d9b20
void e6_logError(string location, string message);	// 0x404f10 (logError)
bool e6_isWall6ddfe0(int x, int y);	// 0x6ddfe0
void e6_ring6de130(const E6Point &p, vector<E6Point> &out);	// 0x6de130
void e6_shufflePoints(vector<E6Point> &v);	// 0x9d7350
int e6_indexOfName(vector<E6Terrain *> &v, const string &name);	// 0x9d7b80
void e6_eraseAt(vector<E6Point> &v, int index);	// 0x9d5190
bool e6_findMachine(vector<E6MachineDef *> &v, const string &name, E6MachineDef *&out);	// 0x9d7710
extern vector<E6MachineDef *> e6_machines_cf35b0;
void e6_removePoint(vector<E6Point> &v, E6Point p);	// 0x9d3060
void getAdjacentCells(const E6Point &p, vector<E6Point> &out);	// 0x4fab80
bool e6_isRingFree(const E6Rect &r, const E6Rect &bounds);	// 0x6cb8c0
void e6_fillRing(const E6Rect &r, const E6Rect &bounds, int a, E6Terrain *t, int b);	// 0x6cba00
bool e6_layout(E6WL &list, int a, E6Rect &bounds, int b, int c, E6IntArr &ids, E6PointArr &spots, E6IntArr &dirs);	// 0x6cadf0
bool e6_removeValue(vector<int> &v, int value);	// 0x9d51d0
extern E6WL e6_wl_d31700;
struct E6EffectType;
struct E6Effect {E6EffectType *type; int value; E6Effect(E6EffectType *t, int v) throw();};	// 0x46ca20
extern vector<E6EffectType *> e6_effects_d2f0f8;
extern vector<E6WL *> e6_logLists_d1e32c;
bool e6_anyNonZero(int *v, unsigned int n);	// 0x9d3f40
extern int e6_logs_b90780[][3];
extern int e6_scrap_b90948[][5];
extern int e6_scrapChance_b90cd8[];
bool e6_flag448b60(const E6Point &p);	// 0x448b60
void e6_deleteBack(vector<E6View *> &v);	// 0x9dbc20
extern int e6_machineType_cefbd8;
struct E6Prop {int type4();};	// 0x9b8f00
bool e6_isAreaEmpty(const E6Point &p, int w, int h, int spacing);	// 0x6c9f10
bool e6_spawn6de200(E6Room *room, int id);	// 0x6de200
struct E6Talk;
bool e6_findTalk(vector<E6Talk *> &v, const string &name, E6Talk *&out);	// 0x9d7de0
extern vector<E6Talk *> e6_talks_d2c408;
bool e6_findNode(int kind, int a, int b, E6HLocation *out);	// 0x470180
extern int e6_d1e884;
extern vector<E6HLocation> e6_locations_d1e88c;
bool e6_findItem(vector<E6ItemType *> &v, const string &name, E6ItemType *&out);	// 0x9d7a40
extern vector<E6ItemType *> e6_itemTypes_d2d1c4;
struct E6Factory {E6HItem createD(E6ItemType *t);};	// 0x7932b0
extern E6Factory *e6_factory_cefaa8;
extern void *e6_cost_cefc30;
void e6_appendPoints(vector<E6Point> &dst, vector<E6Point> &src);	// 0x9d7f20
bool e6_findEntity(vector<E6Rec2 *> &v, const string &name, E6Rec2 *&out);	// 0x9d7530
extern vector<E6Rec2 *> e6_entities_d25de0;
extern vector<struct E6View *> e6_vec_d22744;
int e6_clamp(int lo, int v, int hi);	// 0x9cdc80
struct E6Carto {bool findPath(const E6Point &from, const E6Point &to, void *cost, void *data, vector<E6Point> &path);};	// 0x40c9a0
extern E6Carto e6_carto_cfe568;
extern void *e6_cost_cefc3c;
struct E6World
{
	bool unknown6c6b90(const E6Point &p, const string &s, int a, int b);	// 0x6c6b90
	bool findPlaceableNear(const E6Point &p, E6Point &out, int size);	// 0x71c150
	E6HE placeEntity(E6Rec2 *r, const E6Point &p, int a, bool b, int c, int d, bool e);	// 0x6c58c0
	E6HE unknown71e7c0(const E6Point &p, int a, int b);	// 0x71e7c0
};
extern E6World *e6_bs_cefc4c;

struct BS
{
	char pad0[8];
	E6Point center;
	vector<E6Marker *> markers;
	char pad20[0xac0 - 0x20];
	vector<int> encounterRecords;
	vector<E6Rect> encounterRects;
	char padae0[4];
	vector<int> encounterIds;
	vector<int> encounterTypes;
	char padb04[0xc38 - 0xb04];
	vector<int> c38;
	char padc48[0x10];
	vector<int> c58;
	E6Rec2 *selectRobotOfClass(int a, int b, bool c, bool d);	// 0x6c5600
	E6HE placeEntity(E6Rec2 *r, const E6Point &p, int a, bool b, int c, int d, bool e);	// 0x6c58c0
	void terrain6c38a0(E6Rect *r, E6Room *room, float f, int t);	// 0x6c38a0
	E6ItemType *selectRandomItem(int a, int b, int c);	// 0x6c3bc0
	E6HItem unknown6c5400(E6ItemType *t, const E6Point &p);	// 0x6c5400
	void unknown6dd0e0(const E6Point &p, int a);	// 0x6dd0e0
	void placeMachine(int id, const E6Point &p, int a, int b, int c);	// 0x6c70a0
	E6HE unknown71e7c0(const E6Point &p, int a, int b);	// 0x71e7c0
	void unknown6c65a0(E6HE e, const string &s, bool b);	// 0x6c65a0
	void placeProp(int type, const E6Point &p, int a, int b, int c);	// 0x6c67b0
	void unknown74ba20(E6View *v, const E6Point &p);	// 0x74ba20
	void unknown74b2c0(const E6Point &p);	// 0x74b2c0
	int countPassableAdjacent(const E6Point &p);	// 0x71c850
	void unknown6c6700(E6HProp prop, const string &s, int a);	// 0x6c6700
	bool unknown71bc10(const E6Point &p, E6Point &out);	// 0x71bc10
	void stampPrefab(E6Prefab &child, int a, bool b, float c);	// 0x6cd110
	void addGroup(int type, E6Rect *rect, E6Room *room);	// 0x777aa0
	void placeRandomEncounter(vector<int> &encounters, vector<E6Rect> &placed, vector<bool> &placedFlags, vector<int> &usedEncounters);
};

void BS::placeRandomEncounter(vector<int> &encounters, vector<E6Rect> &placed, vector<bool> &placedFlags, vector<int> &usedEncounters)
{
	int ay = e6_location_d1e888->dlev;
	int ratio = e6_location_d1e888->f8;
	int num = e6_location_d1e888->getDepthIndex();
	for (int i = 0; i < 0x12e; i++)
		if (e6_records_d21afc[i]->f30 >= 0)
			e6_vec_d1e8d0[i] = 0;
	if (encounters.empty())
		return;
	vector<E6Hit> hits;
	for (unsigned int i = 0; i < e6_records_d21afc.size(); i++)
	{
		E6Hit list;
		if (e6_records_d21afc[i]->depthWeights[ay] != 0)
			e6_appendIndices(e6_records_d21afc[i]->prefabs,list);
		hits.push_back(list);
	}
	if (e6_location_d1e888->dlev == 15)
	{
		e6_grid_cf11a0.resize(e6_cells_cfd44c.getWidth(),e6_cells_cfd44c.getHeight(),0);
		e6_grid_cf11a0.zero();
		for (unsigned int i = 0; i < e6_zones_cf124c.size(); i++)
		{
			E6Area r;
			r.p1 = e6_zones_cf124c[i].origin;
			r.p2.set(r.p1.x + e6_zones_cf124c[i].layers.front()->getWidth(),r.p1.y + e6_zones_cf124c[i].layers.front()->getHeight());
			for (int x = r.p1.x; x < r.p2.x; x++)
				for (int y = r.p1.y; y < r.p2.y; y++)
					*e6_grid_cf11a0.at(x,y) = 1;
		}
	}
	else
	{
		e6_grid_cf11a0.resize(1,1,0);
		e6_grid_cf11a0.zero();
	}
	int last;
	vector<int> flags;
	vector<E6Point> line;
	vector<int> edges;
	E6ItemType *closest;
	unsigned int iter = encounters.size() * e6_pct_b942d0[ay] / 100;
	int amount = 0;
	E6WL score;
	E6ItemType *found;
	for (int i = 0; i < 0x12e; i++)
	{
		if (e6_records_d21afc[i]->unknown517290())
		{
			score.add(i,e6_maxInt(0,e6_records_d21afc[i]->depthWeights[ay] + e6_weights_ba656c[e6_records_d21afc[i]->type24][e6_diff_cf4718]));
			if (e6_records_d21afc[i]->priority > amount)
				amount = e6_records_d21afc[i]->priority;
		}
	}
	if (score.size() == 0)
		return;
	if (ay == 7 && e6_location_d1e888->find(8).isValid())
		score.remove(0);
	if (e6_flag_d1e880 && !e6_flag_cf474c)
	{
		if (!e6_flag_d257e9)
		{
			if (ay == 7)
				score.setWeight(0x22,10000);
			if (ay == 0x10)
				score.setWeight(0xb4,10000);
		}
		if (!e6_flag_d257ea && ay == 0x10)
			score.setWeight(0xb5,10000);
	}
	vector<int> old;
	vector<int> oldValue;
	if (amount != 0)
	{
		vector<int> *values = score.getValues();
		vector<int> *weights = score.getWeights();
		for (unsigned int i = 0; i < values->size(); i++)
		{
			if (e6_records_d21afc[(*values)[i]]->priority == 0)
			{
				old.push_back((*values)[i]);
				oldValue.push_back((*weights)[i]);
				score.setWeightAt(i,1);
			}
		}
	}
	vector<int> *heuristic = score.getValues();
	vector<int> *row = score.getWeights();
	for (unsigned int i = 0; i < row->size(); i++)
	{
		if ((*row)[i] == e6_keep_b942cc)
		{
			encounterIds.push_back((*heuristic)[i]);
			encounterTypes.push_back(e6_records_d21afc[(*heuristic)[i]]->f30);
		}
	}
	E6AreaRec *element = 0;
	E6Room *room = 0;
	E6Prefab child;
	bool hidden = false;
	e6_shuffle(encounters);
	while (iter != 0 && !encounters.empty())
	{
		if (score.size() == 0)
			break;
		int attempts = 0;
		while (1)
		{
			if (score.size() == 0)
				break;
			int idx = score.pick();
			bool t2;
			E6Rec *dest = e6_records_d21afc[idx];
			int option = -1;
			E6Point px;
			int best = -1;
			int bits;
			bool valid = false;
			vector<int> visited;
			if (room != 0)
			{
				E6WL e5;
				int e22 = 0;
				int e31;
				for (unsigned int i = 0; i < encounters.size(); i++)
					e22 = e6_maxInt(e22,e6_rooms_cf126c[encounters[i]].points.size());
				for (unsigned int i = 0; i < encounters.size(); i++)
				{
					e31 = 100;
					e31 += e6_rooms_cf126c[encounters[i]].points.size() / 2;
					switch (dest->sizeMode)
					{
					break;
					case 1:
						e31 -= e6_rooms_cf126c[encounters[i]].points.size() / 2;
						break;
					case 2:
						e31 += e22 - e6_rooms_cf126c[encounters[i]].points.size();
						break;
					case 3:
						e31 += e6_rooms_cf126c[encounters[i]].points.size();
						break;
					}
					for (unsigned int j = 0; j < visited.size(); j++)
						if (e6_contains(e6_rooms_cf126c[encounters[i]].v30,visited[j]))
							e31 = (int)(e31 * e6_mul_c36cc8);
					if (e31 <= 0)
						e31 = 1;
					e5.add(encounters[i],e31);
				}
				encounters.clear();
				while (e5.size() != 0)
				{
					encounters.push_back(e5.pick());
					e5.remove(encounters.back());
				}
			}
			for (unsigned int ei = 0; ei < encounters.size(); ei++)
			{
nextEncounter:
				element = e6_noArea_b90158[ay] ? 0 : &e6_areas_cf13e8[encounters[ei]];
				room = e6_noArea_b90158[ay] ? &e6_rooms_cf126c[encounters[ei]] : 0;
				if (element != 0)
				{
					switch (dest->listMode)
					{
					break;
					case 1:
						if (!e6_contains(c38,encounters[ei]))
							continue;
						break;
					case 2:
						if (e6_contains(c38,encounters[ei]))
							continue;
						break;
					}
				}
				else
				{
					switch (dest->roomMode)
					{
					break;
					case 1:
						if (!room->b44)
							continue;
						break;
					case 2:
						if (room->b44)
							continue;
						break;
					}
					switch (dest->listMode)
					{
					break;
					case 1:
						if (!e6_contains(c58,encounters[ei]))
							continue;
						break;
					case 2:
						if (e6_contains(c58,encounters[ei]))
							continue;
						break;
					}
					if (e6_diff_cf4718 == 2 && (dest->type24 == 2 || dest->type24 == 3) && e6_inRoom(room->points,center))
						continue;
				}
				if (ay != 0xd && ay != 0xb ? dest->maxSize != -1 && (element ? element->pts.size() : room->v10.size()) > dest->maxSize : element->pts.size() != dest->f90)
					continue;
				if (dest->bounds.p1.x != -1 && !dest->bounds.contains(element ? element->rect.topLeft() : room->points.front()))
					continue;
				if (!dest->prefabs.empty())
				{
					if (hits[idx].empty())
						continue;
					if (room == 0)
					{
						if (dest->b9 && !element->v48.empty())
							continue;
						if ((dest->minW <= element->rect.w && dest->minH <= element->rect.h) || (dest->minH <= element->rect.w && dest->minW <= element->rect.h))
						{
							vector<int> rots(element->rots);
							e6_shuffle(rots);
							for (unsigned int r = 0; r < rots.size(); r++)
							{
								vector<int> sel;
								if (dest->prefabWeights.empty())
								{
									sel = hits[idx];
									e6_shuffle(sel);
								}
								else if (hits.size() == dest->prefabWeights.size())
									dest->prefabWeights.pickAll(sel);
								else
								{
									E6WL byWeight;
									for (unsigned int k = 0; k < hits[idx].size(); k++)
										byWeight.add(hits[idx][k],dest->prefabWeights.getWeight(&hits[idx][k]));
									while (!byWeight.empty())
									{
										sel.push_back(byWeight.pick());
										byWeight.remove(sel.back());
									}
								}
								for (unsigned int s = 0; s < sel.size(); s++)
								{
									bool e10 = false;
									E6Prefab *e29 = e6_prefabs_d161c4[dest->prefabs[sel[s]]];
									last = sel[s];
									int e46, e53;
									E6Grid *g26 = e29->layers.front();

									switch (rots[r])
									{
									case 0:
									case 2:
										e10 = g26->getWidth() <= element->rect.w && g26->getHeight() <= element->rect.h;
										e53 = g26->getWidth();
										e46 = g26->getHeight();
										break;
									case 1:
									case 3:
										e10 = g26->getWidth() <= element->rect.h && g26->getHeight() <= element->rect.w;
										e53 = g26->getHeight();
										e46 = g26->getWidth();
										break;
									}
									if (e10)
									{
										int e19;
										option = s;
										bits = rots[r];
										child = *e29;
										hidden = false;
										if (dest->canFlip && rng.chance(50))
										{
											child.flipHorizontal(true);
											t2 = true;
										}
										else
											t2 = false;
										if (bits != 2)
										{
											for (e19 = 0; e19 < e6_rotCount_bb8370[bits]; e19++)
												child.rotate(true);
											hidden = true;
										}
										E6Area g22;
										if (!dest->b9)
										{
											px.set(rng.rangeInt(element->rect.x,element->rect.x + (element->rect.w - e53)),rng.rangeInt(element->rect.y,element->rect.y + (element->rect.h - e46)));
											g22.set(px,E6Point(px,e53 - 1,e46 - 1));
										}
										else
										{
										if (ay == 0xd || ay == 0xb)
										{
											int g31;
											E6Grid *g45 = child.layers[1];
											int g49;
											int g51;
											vector<E6Point> h49;
											switch (bits)
											{
											case 2:
												px.y = element->rect.h - e46 + element->rect.y;
												g49 = g45->getHeight() - 1;
												goto vertical;
											case 0:
												px.y = element->rect.y;
												g49 = 0;
vertical:
												g31 = element->rect.x;
												g51 = element->rect.w - e53 + element->rect.x;
												for (px.x = g31; px.x <= g51; px.x++)
												{
													for (unsigned int k = 0; k < element->pts.size(); k++)
													{
														E6Point q(element->pts[k].x - px.x,g49);
														if (!g45->contains(q) || g45->atPoint(q)->getBack() != *e6_color_d338bc)
															goto nextX;
													}
													h49.push_back(px);
nextX:;
												}
												break;
											case 1:
												px.x = element->rect.w - e53 + element->rect.x;
												g49 = g45->getWidth() - 1;
												goto horizontal;
											case 3:
												px.x = element->rect.x;
												g49 = 0;
horizontal:
												g31 = element->rect.y;
												g51 = element->rect.h - e46 + element->rect.y;
												for (px.y = g31; px.y <= g51; px.y++)
												{
													for (unsigned int k = 0; k < element->pts.size(); k++)
													{
														E6Point q(g49,element->pts[k].y - px.y);
														if (!g45->contains(q) || g45->atPoint(q)->getBack() != *e6_color_d338bc)
															goto nextY;
													}
													h49.push_back(px);
nextY:;
												}
												break;
											}
											if (h49.empty())
											{
												option = -1;
												if (++ei == encounters.size())
													goto encountersDone;
												goto nextEncounter;
											}
											else
											{
												px = e6_randomPoint(h49);
												g22.set(px,E6Point(px,e53 - 1,e46 - 1));
											}
										}
										else
										{
											E6Point g0(element->pts.front());
											int h59;
											int k24;
											int *k27;
											int k30;
											int k5;
											switch (bits)
											{
											case 2:
												px.y = element->rect.h - e46 + element->rect.y;
												goto alongX;
											case 0:
												px.y = element->rect.y;
alongX:
												h59 = g0.x;
												k27 = &px.x;
												k24 = element->rect.x;
												k30 = element->rect.w - e53 + element->rect.x;
												k5 = e53;
												break;
											case 1:
												px.x = element->rect.w - e53 + element->rect.x;
												goto alongY;
											case 3:
												px.x = element->rect.x;
alongY:
												h59 = g0.y;
												k27 = &px.y;
												k24 = element->rect.y;
												k30 = element->rect.h - e46 + element->rect.y;
												k5 = e46;
												break;
											}
											vector<int> g14;
											for (int c = k24; c <= k30; c++)
												if (e6_between(c,h59,c + k5))
													g14.push_back(c);
											if (g14.empty())
											{
												option = -1;
												if (++ei == encounters.size())
													goto encountersDone;
												goto nextEncounter;
											}
											else
												*k27 = e6_randomRec(g14);
											g22.set(px,E6Point(px,e53 - 1,e46 - 1));
											if (!t2)
											{
												int k50;
												switch (rots[r])
												{
												case 2:
													k50 = g0.x - g22.p1.x;
													break;
												case 0:
													k50 = g22.p2.x - g0.x;
													break;
												case 1:
													k50 = g22.p2.y - g0.y;
													break;
												case 3:
													k50 = g0.y - g22.p1.y;
													break;
												}
												E6Grid *g25 = e29->layers[0];
												E6Grid *g42 = e29->layers[2];
												E6Grid *k51 = e29->layers[3];
												if (!(k50 >= 0 && k50 < g25->getWidth() && e6_findColor(e6_colors_cf127c,9,g25->at(k50,g25->getHeight() - 1)->getBack()) == 5 && g42->at(k50,g42->getHeight() - 1)->getChar() == ' ' && k51->at(k50,k51->getHeight() - 1)->getChar() == ' '))
												{
													vector<int> k54;
													E6Point k57;
													switch (rots[r])
													{
													case 2:
														k57.x = g22.p1.x;
														k57.y = g22.p2.y + 2;
														break;
													case 0:
														k57.x = g22.p2.x;
														k57.y = g22.p1.y - 2;
														break;
													case 1:
														k57.x = g22.p2.x + 2;
														k57.y = g22.p2.y;
														break;
													case 3:
														k57.x = g22.p1.x - 2;
														k57.y = g22.p1.y;
														break;
													}
													for (int c = 0; c < g25->getWidth(); c++)
													{
														if (e6_findColor(e6_colors_cf127c,9,g25->at(c,g25->getHeight() - 1)->getBack()) == 5 && (*e6_cells_cfd44c.atPoint(k57))->terrain() == e6_floor_cefb9c->id && (*e6_cells_cfd44c.atPoint(k57))->getProp().isNull() && *e6_grid_cf1964.atPoint(k57) != 7 && g42->at(c,g42->getHeight() - 1)->getChar() == ' ' && k51->at(c,k51->getHeight() - 1)->getChar() == ' ')
															k54.push_back(c);
														e6_translate(&k57,e6_dir_bb8360[rots[r]],1,0);
													}
													if (k54.empty())
													{
														option = -1;
														if (++ei == encounters.size())
															goto encountersDone;
														goto nextEncounter;
													}
													else
													{
														int d = e6_randomRec(k54);
														E6Point moved(g0);
														e6_translate(&moved,e6_dir_bb8360[rots[r]],d - k50,0);
														e6_setTerrainAt(g0,TERRAIN_CAVE_WALL);
														e6_setTerrainAt(moved,e6_door_cefbb0);
														element->pts.front() = moved;
													}
												}
											}
											else
											{
												int m14;
												switch (rots[r])
												{
												case 2:
													m14 = g22.p2.x - g0.x;
													break;
												case 0:
													m14 = g0.x - g22.p1.x;
													break;
												case 1:
													m14 = g0.y - g22.p1.y;
													break;
												case 3:
													m14 = g22.p2.y - g0.y;
													break;
												}
												E6Grid *m27 = e29->layers[0];
												E6Grid *m31 = e29->layers[2];
												E6Grid *m34 = e29->layers[3];
												if (!(m14 >= 0 && m14 < m27->getWidth() && e6_findColor(e6_colors_cf127c,9,m27->at(m14,m27->getHeight() - 1)->getBack()) == 5 && m31->at(m14,m31->getHeight() - 1)->getChar() == ' ' && m34->at(m14,m34->getHeight() - 1)->getChar() == ' '))
												{
													vector<int> m38;
													E6Point m51;
													switch (rots[r])
													{
													case 2:
														m51.x = g22.p2.x;
														m51.y = g22.p2.y + 2;
														break;
													case 0:
														m51.x = g22.p1.x;
														m51.y = g22.p1.y - 2;
														break;
													case 1:
														m51.x = g22.p2.x + 2;
														m51.y = g22.p1.y;
														break;
													case 3:
														m51.x = g22.p1.x - 2;
														m51.y = g22.p2.y;
														break;
													}
													for (int c = 0; c < m27->getWidth(); c++)
													{
														if (e6_findColor(e6_colors_cf127c,9,m27->at(c,m27->getHeight() - 1)->getBack()) == 5 && (*e6_cells_cfd44c.atPoint(m51))->terrain() == e6_floor_cefb9c->id && (*e6_cells_cfd44c.atPoint(m51))->getProp().isNull() && *e6_grid_cf1964.atPoint(m51) != 7 && m31->at(c,m31->getHeight() - 1)->getChar() == ' ' && m34->at(c,m34->getHeight() - 1)->getChar() == ' ')
															m38.push_back(c);
														e6_translate(&m51,e6_dir_bb8360[rots[r]],-1,0);
													}
													if (m38.empty())
													{
														option = -1;
														if (++ei == encounters.size())
															goto encountersDone;
														goto nextEncounter;
													}
													else
													{
														int q12 = e6_randomRec(m38);
														E6Point g44(g0);
														e6_translate(&g44,e6_dir_bb8360[rots[r]],m14 - q12,0);
														e6_setTerrainAt(g0,TERRAIN_CAVE_WALL);
														e6_setTerrainAt(g44,e6_door_cefbb0);
														element->pts.front() = g44;
													}
												}
											}
										}
										E6Area e4(element->rect);
										if (ay == 0xd || ay == 0xb)
										{
											e4.grow(1);
											for (int x = e4.p1.x; x <= e4.p2.x; x++)
												for (int y = e4.p1.y; y <= e4.p2.y; y++)
													if (!g22.contains(x,y))
														e6_setTerrain(x,y,TERRAIN_EARTH);
											for (unsigned int k = 0; k < element->pts.size(); k++)
												e6_setTerrainAt(element->pts[k],e6_floor_cefb9c);
										}
										else
										{
											e4.grow(1);
											for (int x = e4.p1.x; x <= e4.p2.x; x++)
												for (int y = e4.p1.y; y <= e4.p2.y; y++)
													if ((*e6_cells_cfd44c.at(x,y))->terrain() == TERRAIN_CAVE_WALL->id || ((*e6_cells_cfd44c.at(x,y))->terrain() == e6_floor_cefb9c->id && !g22.contains(x,y)))
														e6_setTerrain(x,y,TERRAIN_EARTH);
										}
										int e41 = TERRAIN_EARTH->id;
										int e58 = TERRAIN_CAVE_WALL->id;
										vector<E6Point> e7;
										for (int x = e4.p1.x; x <= e4.p2.x; x++)
										{
											for (int y = e4.p1.y; y <= e4.p2.y; y++)
											{
												if ((*e6_cells_cfd44c.at(x,y))->terrain() == e41)
												{
													if (x - 1 >= 0)
													{
														if (!(*e6_cells_cfd44c.at(x - 1,y))->solid66a630())
															goto expose;
														if (y - 1 >= 0 && !(*e6_cells_cfd44c.at(x - 1,y - 1))->solid66a630())
															goto expose;
														if (y + 1 < e6_cells_cfd44c.getHeight() && !(*e6_cells_cfd44c.at(x - 1,y + 1))->solid66a630())
															goto expose;
													}
													if (x + 1 < e6_cells_cfd44c.getWidth())
													{
														if (!(*e6_cells_cfd44c.at(x + 1,y))->solid66a630())
															goto expose;
														if (y - 1 >= 0 && !(*e6_cells_cfd44c.at(x + 1,y - 1))->solid66a630())
															goto expose;
														if (y + 1 < e6_cells_cfd44c.getHeight() && !(*e6_cells_cfd44c.at(x + 1,y + 1))->solid66a630())
															goto expose;
													}
													if (y - 1 >= 0 && !(*e6_cells_cfd44c.at(x,y - 1))->solid66a630())
														goto expose;
													if (y + 1 < e6_cells_cfd44c.getHeight() && !(*e6_cells_cfd44c.at(x,y + 1))->solid66a630())
														goto expose;
													continue;
expose:
													e7.push_back(E6Point(x,y));
												}
											}
										}
										for (unsigned int k = 0; k < e7.size(); k++)
											e6_setTerrainAt(e7[k],TERRAIN_CAVE_WALL);
										}
										break;
									}
								}
								if (option != -1)
									break;
							}
							if (option == -1)
								continue;
						}
						else
							continue;
					}
					else
					{
						int pick;
						if (dest->f74 < 0)
						{
							if (room->cx == -1)
							{
								E6Area g57(room->points.front(),room->points.front());
								for (unsigned int k = 1; k < room->points.size(); k++)
									g57.include(room->points[k]);
								vector<int> q3((unsigned int)(g57.p2.x - g57.p1.x + 1),0u);
								vector<int> q42((unsigned int)(g57.p2.y - g57.p1.y + 1),0u);
								for (unsigned int k = 0; k < room->points.size(); k++)
								{
									q3[room->points[k].x - g57.p1.x]++;
									q42[room->points[k].y - g57.p1.y]++;
								}
								int q48 = OpT8a_sumVector(q3) / 2;
								int h16 = OpT8a_sumVector(q42) / 2;
								for (unsigned int k = 0; k < q3.size(); k++)
								{
									q48 -= q3[k];
									if (q48 <= 0)
									{
										room->cx = g57.p1.x + k;
										break;
									}
								}
								for (unsigned int k = 0; k < q42.size(); k++)
								{
									h16 -= q42[k];
									if (h16 <= 0)
									{
										room->cy = g57.p1.y + k;
										break;
									}
								}
							}
							int h11 = room->b44 ? 0 : 5;
							E6Area h23(room->cx - h11,room->cy - h11,room->cx + h11,room->cy + h11);
							if (!e6_cells_cfd44c.getArea().contains(h23))
								continue;
							E6Rect h30;
							for (int t = 0; t < 4; t++)
							{
								pick = dest->prefabWeights.empty() ? e6_randomIndex(dest->prefabs) : dest->prefabWeights.pick();
								E6Prefab *g2 = e6_prefabs_d161c4[dest->prefabs[pick]];
								bits = rng.rangeInt(0,3);
								switch (bits)
								{
								case 0:
								case 2:
									h30.w = g2->layers.front()->getWidth();
									h30.h = g2->layers.front()->getHeight();
									break;
								case 1:
								case 3:
									h30.h = g2->layers.front()->getWidth();
									h30.w = g2->layers.front()->getHeight();
									break;
								}
								E6Point g48 = h23.randomPoint();
								px.x = h30.x = g48.x - h30.w / 2;
								px.y = h30.y = g48.y - h30.h / 2;
								if (!e6_cells_cfd44c.inBounds(px.x - 1,px.y - 1) || !e6_cells_cfd44c.inBounds(px.x + h30.w,px.y + h30.h))
									pick = -1;
								else
								{
									for (int x = h30.x; x < h30.x + h30.w; x++)
									{
										for (int y = h30.y; y < h30.y + h30.h; y++)
										{
											if (((*e6_cells_cfd44c.at(x,y))->terrain() == TERRAIN_EARTH->id || (*e6_cells_cfd44c.at(x,y))->terrain() == TERRAIN_CAVE_WALL->id || ((*e6_cells_cfd44c.at(x,y))->terrain() == e6_floor_cefb9c->id && (*e6_grid_cf1964.at(x,y) == 9 || e6_inRoom(room->points,E6Point(x,y))))) && !(*e6_cells_cfd44c.at(x,y))->isMachinePart() && center.test409cf0(x,y))
												continue;
											else
											{
												pick = -1;
												goto roomChecked;
											}
										}
									}
									for (unsigned int k = 0; k < placed.size(); k++)
									{
										if (h30.touches(placed[k]))
										{
											pick = -1;
											break;
										}
									}
								}
roomChecked:
								if (pick == -1)
									continue;
								option = pick;
								child = *e6_prefabs_d161c4[dest->prefabs[option]];
								if (dest->canFlip && rng.chance(50))
								{
									child.flipHorizontal(true);
									t2 = true;
								}
								else
									t2 = false;
								break;
							}
						}
						else
						{
							int h28;
							int k4;
							int qq42;
							vector<E6Point> k10(2);
							int q55;
							vector<int> q15(2);
							E6Point q0;
							E6Rect q49;
							E6Rect h22;
							E6Rect m0;
							E6Rect h2;
							for (int t = 0; t < 8; t++)
							{
								pick = dest->prefabWeights.empty() ? e6_randomIndex(dest->prefabs) : dest->prefabWeights.pick();
								E6Prefab *k49 = e6_prefabs_d161c4[dest->prefabs[pick]];
								bits = rng.rangeInt(0,3);
								switch (bits)
								{
								case 0:
								case 2:
									h28 = qq42 = k49->layers.front()->getWidth();
									k4 = q55 = k49->layers.front()->getHeight();
									break;
								case 1:
								case 3:
									h28 = q55 = k49->layers.front()->getWidth();
									k4 = qq42 = k49->layers.front()->getHeight();
									break;
								}
								for (int k = 0; k < 100; k++)
								{
									k10.assign(2,e6_randomPoint(*(vector<E6Point> *)room));
									e6_translate(&k10[1],bits,h28,0);
									if (e6_inRoom(room->points,k10[1]))
										break;
									else
										k10[0].x = -1;
								}
								if (k10[0].x == -1)
									continue;
								q15.assign(2u,0u);
								for (int e = 0; e < 2; e++)
								{
									q0 = k10[e];
									while (1)
									{
										e6_translate(&q0,bits,0,-1);
										if (!e6_cells_cfd44c.contains(q0))
										{
											pick = -1;
											break;
										}
										else if ((*e6_cells_cfd44c.atPoint(q0))->terrain() == e6_floor_cefb9c->id)
										{
											if (e6_inRoom(room->points,q0))
												q15[e]++;
											else
											{
												pick = -1;
												break;
											}
										}
										else
											break;
									}
									if (pick == -1)
										break;
								}
								if (pick == -1)
									continue;
								if (q15[0] > dest->f74 || q15[1] > dest->f74)
								{
									if (abs(q15[0] - q15[1]) > dest->f74)
										continue;
									else
									{
										int m = e6_minInt(q15[0],q15[1]);
										for (int e = 0; e < 2; e++)
										{
											e6_translate(&k10[e],bits,0,-m);
											if ((*e6_cells_cfd44c.atPoint(k10[e]))->terrain() == e6_floor_cefb9c->id && e6_inRoom(room->points,k10[e]))
												q15[e] -= m;
											else
											{
												pick = -1;
												break;
											}
										}
										if (pick == -1)
											continue;
									}
								}
								int g50 = e6_maxInt(q15[0],q15[1]);
								switch (bits)
								{
								case 2:
									q49.set(k10[1].x,k10[1].y - g50,h28,g50);
									h22.set(q49.x,q49.y - (k4 - g50),h28,k4 - g50);
									px.set(h22.x,h22.y);
									break;
								case 0:
									q49.set(k10[0].x,k10[0].y,h28,g50);
									h22.set(q49.x,q49.y + g50,h28,k4 - g50);
									px.set(q49.x,q49.y);
									break;
								case 1:
									q49.set(k10[0].x - g50,k10[0].y,g50,h28);
									h22.set(q49.x - (k4 - g50),q49.y,k4 - g50,h28);
									px.set(h22.x,h22.y);
									break;
								case 3:
									q49.set(k10[1].x,k10[1].y,g50,h28);
									h22.set(q49.x + g50,q49.y,k4 - g50,h28);
									px.set(q49.x,q49.y);
									break;
								}
								for (int x = h22.x; x < h22.x + h22.w; x++)
								{
									for (int y = h22.y; y < h22.y + h22.h; y++)
									{
										if (!e6_cells_cfd44c.inBounds(x,y) || ((*e6_cells_cfd44c.at(x,y))->terrain() != TERRAIN_EARTH->id && (*e6_cells_cfd44c.at(x,y))->terrain() != TERRAIN_CAVE_WALL->id))
										{
											pick = -1;
											goto bodyChecked;
										}
									}
								}
								for (int x = q49.x; x < q49.x + q49.w; x++)
								{
									for (int y = q49.y; y < q49.y + q49.h; y++)
									{
										if ((*e6_cells_cfd44c.at(x,y))->isMachinePart() || center.test409cb0(x,y))
										{
											pick = -1;
											goto bodyChecked;
										}
									}
								}
bodyChecked:
								if (pick == -1)
									continue;
								m0 = h22;
								m0.grow(1);
								switch (bits)
								{
								case 2:
									m0.h--;
									break;
								case 0:
									m0.y++;
									m0.h--;
									break;
								case 1:
									m0.w--;
									break;
								case 3:
									m0.x++;
									m0.w--;
									break;
								}
								if (!e6_cells_cfd44c.getArea().contains(m0))
									pick = -1;
								else
								{
									for (int x = m0.x; x < m0.x + m0.w; x++)
									{
										for (int y = m0.y; y < m0.y + m0.h; y++)
										{
											if (!h22.contains(x,y) && (*e6_cells_cfd44c.at(x,y))->terrain() != TERRAIN_CAVE_WALL->id && (*e6_cells_cfd44c.at(x,y))->terrain() != TERRAIN_EARTH->id)
											{
												pick = -1;
												goto outerChecked;
											}
										}
									}
								}
outerChecked:
								if (pick == -1)
									continue;
								for (int x = q49.x; x < q49.x + q49.w; x++)
									for (int y = q49.y; y < q49.y + q49.h; y++)
										e6_setTerrain(x,y,e6_floor_cefb9c);
								option = pick;
								child = *e6_prefabs_d161c4[dest->prefabs[option]];
								if (dest->canFlip && rng.chance(50))
								{
									child.flipHorizontal(true);
									t2 = true;
								}
								else
									t2 = false;
								break;
							}
						}
						if (option == -1)
							continue;
					}
				}
				best = ei;
				break;
			}
encountersDone:
			if (best == -1)
				score.remove(idx);
			else
			{
				if (!dest->prefabs.empty())
				{
					if (option == -1)
					{
						e6_logError("BS::placeRandomEncounter()","Encounter requiring prefab had none selected (" + dest->name + "), quitting");
						return;
					}
					child.rot = bits;
					child.flipped = t2;
					child.origin = px;
					if (bits != 2 && !hidden)
						for (int k = 0; k < e6_rotCount_bb8370[bits]; k++)
							child.rotate(true);
					if (room != 0)
					{
						E6Grid *qq46 = child.layers[0];
						E6Rect u10(px,qq46->getWidth(),qq46->getHeight());
						placed.push_back(u10);
						placedFlags.push_back(dest->f74 >= 0);
						vector<E6Point> u20;
						for (int uu23 = 0, h8 = px.x; uu23 < qq46->getWidth(); uu23++, h8++)
						{
							for (int uu27 = 0, k36 = px.y; uu27 < qq46->getHeight(); uu27++, k36++)
							{
								if ((uu23 == 0 || uu27 == 0 || uu23 == qq46->getWidth() - 1 || uu27 == qq46->getHeight() - 1) && qq46->at(uu23,uu27)->getBack() == e6_colors_cf127c[5])
								{
									u20.clear();
									sweepGetSurroundingCells(E6Point(px,uu23,uu27),u20);
									for (unsigned int k = 0; k < u20.size(); k++)
										if ((*e6_cells_cfd44c.atPoint(u20[k]))->terrain() == TERRAIN_EARTH->id && !u10.containsPos(u20[k]))
											e6_setTerrainAt(u20[k],TERRAIN_CAVE_WALL);
								}
							}
						}
						if (dest->f7c != 0 && e6_location_d1e888->dlev == 15 && (dest->f7c == 2 || dest->f7c == 3))
						{
							E6Area fa(u10);
							for (int x = fa.p1.x; x < fa.p2.x; x++)
								for (int y = fa.p1.y; y < fa.p2.y; y++)
									*e6_grid_cf11a0.at(x,y) = 1;
						}
					}
					stampPrefab(child,dest->f20,dest->bc0,dest->fbc);
					if (room != 0 && dest->f74 == -2)
					{
						E6Point start(child.origin,child.layers.front()->getArea().center());
						vector<E6Point> path;
						if (!e6_carto_cfe568.findPath(start,center,e6_cost_cefc3c,0,path))
							;
						else
						{
							for (unsigned int k = 0; k < path.size(); k++)
								if (!(*e6_cells_cfd44c.atPoint(path[k]))->isPassableFor(E6HE()))
									e6_setTerrainAt(path[k],e6_floor_cefb9c);
						}
					}
					if (ay == 0xd || ay == 0xb)
					{
						E6WL doorTypes(dest->doorWeights);
						int doorType = doorTypes.pick();
						for (unsigned int k = 0; k < element->pts.size(); k++)
						{
							E6Point dp(element->pts[k]);
							e6_translate(&dp,element->rots[k],0,element->v5c[k] - 1);
							switch (doorType)
							{
							case 0:
								e6_setTerrainAt(dp,e6_floor_cefb9c);
								break;
							case 1:
								e6_setTerrainAt(dp,e6_terrain_cefba8);
								break;
							case 2:
								e6_setTerrainAt(dp,e6_terrain_cefbac);
								break;
							}
							if (doorType == 0)
							{
								e6_translate(&dp,element->rots[k],0,1);
								if ((*e6_cells_cfd44c.atPoint(dp))->getItem().isValid())
									(*e6_cells_cfd44c.atPoint(dp))->getItem()->remove57dbe0(false,false,true,true);
							}
							if (dest->fa4 != 0 && (*e6_cells_cfd44c.atPoint(element->pts[k]))->getProp().isNull())
								e6_bs_cefc4c->unknown6c6b90(element->pts[k],e6_empty_b958bb,dest->fa4,-1);
						}
					}
					vector<E6Point> extraDoors;
					if (dest->extraRange.y != 0)
					{
						unsigned int uu52;
						E6Point uu56(-1);
						for (uu52 = 0; uu52 < element->rots.size(); uu52++)
						{
							if (element->rots[uu52] == bits)
							{
								uu56 = element->pts[uu52];
								break;
							}
						}
						if (uu56.x == -1)
							goto extraDone;
						*e6_grid_cf447c.atPoint(uu56) = 5;
						vector<int> m15;
						m15.push_back(-1);
						m15.push_back(1);
						e6_shuffle(m15);
						int g7 = dest->extraRange.randomInRange();
						for (unsigned int k = 0; k < m15.size() && g7 != 0; k++)
						{
							E6Point p(uu56);
							while (g7 != 0)
							{
								e6_translate(&p,bits,m15[k],0);
								if (!e6_cells_cfd44c.contains(p))
									break;
								E6Point vv12(p);
								e6_translate(&vv12,e6_dir_bb8360[bits],0,-1);
								E6Point vv16(p);
								e6_translate(&vv16,e6_dir_bb8360[bits],0,1);
								if ((*e6_cells_cfd44c.atPoint(vv12))->terrain() == e6_floor_cefb9c->id && (*e6_cells_cfd44c.atPoint(vv16))->terrain() == e6_floor_cefb9c->id)
								{
									e6_setTerrainAt(p,e6_door_cefbb0);
									extraDoors.push_back(p);
									*e6_grid_cf447c.atPoint(p) = 5;
									g7--;
								}
								else
									break;
							}
						}
					}
extraDone:
					if (dest->fb4 != 0 && rng.chance(dest->fb4))
					{
						for (unsigned int k = 0; k < extraDoors.size(); k++)
							e6_setTerrainAt(extraDoors[k],e6_floor_cefb9c);
						for (unsigned int k = 0; k < element->pts.size(); k++)
							e6_setTerrainAt(element->pts[k],e6_floor_cefb9c);
					}
					valid = true;
				}
				switch (idx)
				{
				case 0:
				case 3:
				{
					E6Point spot(-1);
					if (element != 0)
					{
						if (element->pts.empty())
							break;
						if (!(*e6_cells_cfd44c.atPoint(element->pts.front()))->unknown45db70())
							continue;
						if (!element->v48.empty())
							break;
						spot = element->pts.front();
						e6_setTerrainAt(spot,e6_floor_cefb9c);
						for (int x = element->rect.x; x <= element->rect.right(); x++)
							for (int y = element->rect.y; y <= element->rect.bottom(); y++)
								e6_setTerrain(x,y,e6_terrain_cefb84);
						for (int x = element->rect.x - 1, top = element->rect.y - 1, bottom = element->rect.bottom() + 1; x <= element->rect.right() + 1; x++)
						{
							if (e6_isWall6ddfe0(x,top))
								e6_setTerrain(x,top,TERRAIN_EARTH);
							if (e6_isWall6ddfe0(x,bottom))
								e6_setTerrain(x,bottom,TERRAIN_EARTH);
						}
						for (int e18 = element->rect.x - 1, e21 = element->rect.right() + 1, e25 = element->rect.y; e25 <= element->rect.bottom(); e25++)
						{
							if (e6_isWall6ddfe0(e18,e25))
								e6_setTerrain(e18,e25,TERRAIN_EARTH);
							if (e6_isWall6ddfe0(e21,e25))
								e6_setTerrain(e21,e25,TERRAIN_EARTH);
						}
						if (idx == 3)
						{
							vector<E6Point> e0;
							switch (element->rots.front())
							{
							case 0:
								for (int x = element->rect.x; x <= element->rect.right(); x++)
									e0.push_back(E6Point(x,element->rect.bottom()));
								break;
							case 2:
								for (int x = element->rect.x; x <= element->rect.right(); x++)
									e0.push_back(E6Point(x,element->rect.y));
								break;
							case 3:
								for (int y = element->rect.y; y <= element->rect.bottom(); y++)
									e0.push_back(E6Point(element->rect.right(),y));
								break;
							case 1:
								for (int y = element->rect.y; y <= element->rect.bottom(); y++)
									e0.push_back(E6Point(element->rect.x,y));
								break;
							}
							e6_shufflePoints(e0);
							markers.push_back(new E6Marker(e0[0],e6_location_d1e888->find(0xf),1,E6HE(),E6HE()));
							int g16 = e6_indexOfName(e6_terrains_cfb844,"STAIRS_MAT");
							e6_setTerrainAt(e0[0],e6_terrains_cfb844[g16]);
							e6_bs_cefc4c->unknown6c6b90(e0[0],"MAT_Subdweller_Attack",0,-1);
							E6Point e28(e0[0]);
							e6_eraseAt(e0,0);
							if (!e0.empty())
							{
								E6Point e20(-1);
								for (unsigned int k = 0; k < e0.size(); k++)
								{
									if (!e0[k].isAdjacent(e28))
									{
										e20 = e0[k];
										break;
									}
								}
								if (e20.x == -1)
									e20 = e0[0];
								E6MachineDef *g23;
								e6_findMachine(e6_machines_cf35b0,"D.C.S.S. Altar Unit",g23);
								if (g23 != 0)
								{
									e6_setTerrainAt(e20,e6_floor_cefb9c);
									placeMachine(g23->id,e20,0,0,0);
									e6_removePoint(e0,e20);
								}
								for (unsigned int k = 0; k < e0.size(); k++)
									e6_setTerrainAt(e0[k],TERRAIN_EARTH);
							}
						}
					}
					else
					{
						if (room->v20.empty())
							break;
						spot = room->v20.front();
						e6_setTerrainAt(spot,e6_terrain_cefb88);
						for (unsigned int k = 0; k < room->points.size(); k++)
							if (room->points[k].eq409bd0(spot))
								e6_setTerrainAt(room->points[k],e6_terrain_cefb84);
						vector<E6Point> ring;
						for (unsigned int k = 0; k < room->points.size(); k++)
							e6_ring6de130(room->points[k],ring);
						for (unsigned int k = 0; k < ring.size(); k++)
							e6_setTerrainAt(ring[k],TERRAIN_EARTH);
					}
					if (spot.x != -1)
					{
						E6Rec2 *er = selectRobotOfClass(1,3,false,false);
						if (er != 0)
						{
							E6HE e = placeEntity(er,spot,4,true,0x22,0xe,false);
							e->getAI()->unknown4593b0(E6Point(-1));
							e->getAI()->unknown4593b0(spot);
							e->getAI()->unknown4593b0(E6Point(-1));
						}
					}
					valid = true;
					break;
				}
				case 1:
				case 2:
				case 0x2e:
				{
					if (element != 0)
						terrain6c38a0(&element->rect,0,1,e6_d2c46c);
					else
						terrain6c38a0(0,room,0.5f,e6_d2c46c);
					if (idx != 1)
					{
						int vv2 = idx == 2 ? rng.rangeInt(3,6) : e6_maxInt(element->rect.w,element->rect.h);
						int vv42 = 0;
						while (vv2 != 0)
						{
							E6ItemType *it = selectRandomItem(0,0x1f,0x12);
							if (it != 0)
							{
								E6Point p = element ? element->rect.randomPos() : e6_randomPoint(room->points);
								E6HItem item = unknown6c5400(it,p);
								if (item.isValid())
								{
									if (item->nested457880() == 0)
										item->set450460(e6_ranges_d21948[ay].randomInRange());
									else
										item->set450460(e6_maxInt(1,rng.rangeInt(20,60) * item->get9b6bf0() / 100));
									if (idx == 0x2e)
									{
										if (!item->unknown457ad0() && rng.chance(10))
											item->setActivateOkayTurn(-2);
										if (vv42 < 2)
											unknown6dd0e0(p,0x12);
									}
								}
							}
							vv2--;
							vv42++;
						}
						if (idx == 2)
						{
							vv2 = rng.chance(30) ? rng.rangeInt(1,3) : 0;
							if (vv2 != 0)
							{
								vector<int> ranks;
								ranks.push_back(1);
								ranks.push_back(2);
								ranks.push_back(3);
								ranks.push_back(4);
								ranks.push_back(5);
								while (vv2 != 0)
								{
									E6Rec2 *er = selectRobotOfClass(1,e6_randomRec(ranks),false,false);
									if (er != 0)
									{
										E6Point p = element ? element->rect.randomPos() : e6_randomPoint(room->points);
										E6HE e = placeEntity(er,p,4,true,0x22,0xe,false);
										if (e.isValid())
										{
											e->unknown5fd900(8,0);
											e->unknown5dea60(e6_maxInt(1,rng.rangeInt(10,30) * e->field490840() / 100),0);
											vector<E6HItem> *inv = e->getInventoryList();
											for (unsigned int j = 0; j < inv->size(); j++)
												(*inv)[j]->set450460(e6_maxInt(1,rng.rangeInt(20,60) * (*inv)[j]->get9b6bf0() / 100));
										}
									}
									vv2--;
								}
							}
						}
						else
						{
							vv2 = rng.chance(30) ? rng.rangeInt(12,24) : 0;
							if (vv2 != 0)
							{
								vector<int> e27;
								e27.push_back(1);
								e27.push_back(2);
								e27.push_back(3);
								e27.push_back(4);
								e27.push_back(5);
								vector<int> g24;
								g24.push_back(0xd);
								g24.push_back(0x10);
								g24.push_back(0x10);
								g24.push_back(0x10);
								g24.push_back(0x11);
								g24.push_back(0x12);
								g24.push_back(0x13);
								g24.push_back(0x13);
								g24.push_back(0x15);
								g24.push_back(0x15);
								g24.push_back(0x16);
								g24.push_back(0x18);
								g24.push_back(0x19);
								while (vv2 != 0)
								{
									bool e30 = rng.chance(66);
									E6Rec2 *g38 = selectRobotOfClass(1,e6_randomRec(e30 ? g24 : e27),false,true);
									if (g38 != 0)
									{
										E6Point p;
										if (e6_bs_cefc4c->findPlaceableNear(element->rect.randomPos(),p,g38->size9c))
										{
											vector<E6Point> adj;
											getAdjacentCells(p,adj);
											for (unsigned int j = 0; j < adj.size(); j++)
											{
												if ((*e6_cells_cfd44c.atPoint(adj[j]))->unknown45db70())
												{
													p = element->rect.randomPos();
													break;
												}
											}
											E6HE e = placeEntity(g38,p,e30 ? 3 : 4,true,0x22,0xe,false);
											if (e.isValid())
											{
												int roll = rng.rangeInt(1,100);
												if (roll <= 50 && g38->f28 != 0x19)
												{
													e->unknown5fd900(4,9999999);
													if (e30)
														e->unknown5dcc70(4,0);
												}
												else if (e30 && roll <= 70)
													e->unknown5fd900(2,0);
												else
													e->unknown5fd900(8,0);
												e->unknown5dea60(e6_maxInt(1,rng.rangeInt(25,100) * e->field490840() / 100),0);
												vector<E6HItem> *inv = e->getInventoryList();
												for (unsigned int j = 0; j < inv->size(); j++)
													(*inv)[j]->set450460(e6_maxInt(1,rng.rangeInt(25,100) * (*inv)[j]->get9b6bf0() / 100));
											}
										}
									}
									vv2--;
								}
							}
						}
					}
					if (ay == 10 && idx != 0x2e)
					{
						for (int m = rng.rangeInt(1,2); m > 0; m--)
						{
							for (int t = 0; t < 5; t++)
							{
								int dir = rng.rangeInt(0,3);
								if (e6_contains(element->rots,dir))
									continue;
								E6Rect r;
								switch (dir)
								{
								case 0:
									r.x = rng.rangeInt(0,element->rect.w - 1) + element->rect.x;
									r.y = element->rect.y - 1;
									break;
								case 1:
									r.x = element->rect.x + element->rect.w;
									r.y = rng.rangeInt(0,element->rect.h - 1) + element->rect.y;
									break;
								case 2:
									r.x = rng.rangeInt(0,element->rect.w - 1) + element->rect.x;
									r.y = element->rect.y + element->rect.h;
									break;
								case 3:
									r.x = element->rect.x - 1;
									r.y = rng.rangeInt(0,element->rect.h - 1) + element->rect.y;
									break;
								}
								E6Rec2 *er = selectRobotOfClass(1,5,false,false);
								if (er == 0)
									goto nextTry;
								r.w = r.h = er->size9c;
								if (e6_isRingFree(r,element->rect))
								{
									e6_fillRing(r,element->rect,0,TERRAIN_CAVE_WALL,0);
									E6HE e = placeEntity(er,r.topLeft(),4,true,0x22,0xe,false);
									e->unknown5fd900(6,0);
									if (m > 1)
										unknown6dd0e0(e->getPosition(),0x13);
									break;
								}
nextTry:;
							}
						}
					}
					valid = true;
					break;
				}
				case 0x2f:
				{
					terrain6c38a0(&element->rect,0,1,e6_d2c46c);
					for (int n = e6_range_d25dd8.randomInRange(), k = 0; n > 0; n--, k++)
					{
						int type = e6_wl_d31700.pick();
						E6Point p = element->rect.randomPos();
						E6HItem item = unknown6c5400((E6ItemType *)type,p);
						if (item.isValid())
						{
							item->setScaled579880(e6_range_d389bc.randomInRange());
							if (k < 2)
								unknown6dd0e0(p,0x12);
						}
					}
					valid = true;
					break;
				}
				case 7:
				case 0xe:
				{
					E6WL qq6;
					for (unsigned int i = 0; i < e6_machines_cf35b0.size(); i++)
						if (e6_machines_cf35b0[i]->kind == 2 && e6_machines_cf35b0[i]->weight100 != 0 && e6_allowed_b9e6f0[ay][e6_machines_cf35b0[i]->group118])
							qq6.add(i,e6_machines_cf35b0[i]->weight100);
					if (qq6.size() == 0)
						break;
					E6Rect ww3(room->points.front());
					for (unsigned int k = 1; k < room->points.size(); k++)
						ww3.expandToInclude(room->points[k]);
					int qq26 = e6_layout_b9f5c0[ay].a;
					int m21 = e6_layout_b9f5c0[ay].b;
					E6IntArr qq22;
					E6PointArr vv46;
					E6IntArr k48;
					int h50 = 0;
					do
					{
						h50++;
						if (e6_layout(qq6,0,ww3,m21,qq26,qq22,vv46,k48))
						{
							for (int x = 0; x < qq22.getWidth(); x++)
								for (int y = 0; y < qq22.getHeight(); y++)
									if (*qq22.at(x,y) != e6_none_caf15c)
										placeMachine(*qq22.at(x,y),*vv46.at(x,y),e6_dirTable_b96348[*k48.at(x,y)],0,0);
							break;
						}
					} while (h50 < 10);
					if (rng.chance(10))
					{
						E6Rect r(0,0,1,1);
						h50 = 0;
						do
						{
							int e37 = rng.rangeInt(0,3);
							switch (e37)
							{
							case 0:
								r.x = rng.rangeInt(0,ww3.w - 1) + ww3.x;
								r.y = ww3.y - 1;
								break;
							case 1:
								r.x = ww3.x + ww3.w;
								r.y = rng.rangeInt(0,ww3.h - 1) + ww3.y;
								break;
							case 2:
								r.x = rng.rangeInt(0,ww3.w - 1) + ww3.x;
								r.y = ww3.y + ww3.h;
								break;
							case 3:
								r.x = ww3.x - 1;
								r.y = rng.rangeInt(0,ww3.h - 1) + ww3.y;
								break;
							}
							int e47 = e6_none_caf15c;
							for (unsigned int i = 0; i < e6_machines_cf35b0.size(); i++)
							{
								if (e6_machines_cf35b0[i]->f8 == 0 && e6_machines_cf35b0[i]->layers.front()->getWidth() == 1 && e6_machines_cf35b0[i]->layers.front()->getHeight() == 1)
								{
									e47 = i;
									break;
								}
							}
							if (e47 == e6_none_caf15c)
								continue;
							if (e6_isRingFree(r,ww3))
							{
								e6_fillRing(r,ww3,0,TERRAIN_CAVE_WALL,0);
								placeMachine(e47,r.topLeft(),0,0,0);
								break;
							}
						} while (h50 < 10);
					}
					if (idx == 7)
					{
						E6Rec2 *er = selectRobotOfClass(1,1,false,false);
						if (er != 0)
							for (int i = 0; i < 2; i++)
							{
								E6Point p = e6_randomPoint(room->points);
								E6HE e = placeEntity(er,p,4,true,0x22,0xe,false);
							}
					}
					else
					{
						if (e6_overmind_cf6428.spawnPatrolParty(E6HE(),1,0,room,0,0,0,10,0))
						{
							E6Group *g = e6_overmind_cf6428.lastParty();
							g->leader->getAI()->unknown459470(ww3);
						}
					}
					valid = true;
					break;
				}
				case 8:
				{
					E6WL e35;
					for (unsigned int i = 0; i < e6_machines_cf35b0.size(); i++)
						if (e6_machines_cf35b0[i]->kind == 2 && e6_machines_cf35b0[i]->f104 != 0 && e6_allowed_b9e6f0[ay][e6_machines_cf35b0[i]->group118])
							e35.add(i,e6_machines_cf35b0[i]->f104);
					if (e35.size() == 0)
						break;
					int ww43;
					e35.pick(&ww43);
					int m25 = e6_machines_cf35b0[ww43]->layers.front()->getWidth();
					int u17 = e6_machines_cf35b0[ww43]->layers.front()->getHeight();
					int h41 = e6_layoutC_b9f5c8[ay].a;
					int g5 = e6_layoutD_b9f5cc[ay].a;
					E6Point h20;
					vector<int> e33;
					e33.push_back(0);
					e33.push_back(1);
					e33.push_back(2);
					e33.push_back(3);
					e6_shuffle(e33);
					E6Area e50;
					int h1 = 0;
					bool g13;
					do
					{
						h20 = e6_randomPoint(room->points);
						int dir = 4;
						for (unsigned int d = 0; d < e33.size(); d++)
						{
							g13 = e33[d] == 1 || e33[d] == 3;
							e50.set(h20,g13 ? u17 : m25,g13 ? m25 : u17);
							for (int x = e50.p1.x - g5; x <= e50.p2.x + g5; x++)
								for (int y = e50.p1.y - g5; y <= e50.p2.y + g5; y++)
									if (!e6_cells_cfd44c.inBounds(x,y) || !(*e6_cells_cfd44c.at(x,y))->field4550b0())
										goto nextDir;
							if (!e6_isAreaEmpty(h20,g13 ? u17 : m25,g13 ? m25 : u17,h41))
								goto nextDir;
							dir = e33[d];
							break;
nextDir:
							continue;
						}
						if (dir != 4)
						{
							placeMachine(ww43,h20,e6_dirTable_b96348[dir],0,0);
							valid = true;
							break;
						}
					} while (++h1 < 100);
					break;
				}
				case 9:
				{
					E6Rec2 *er = selectRobotOfClass(1,3,false,false);
					if (er != 0)
					{
						for (int i = 0; i < 2; i++)
						{
							E6Point p = e6_randomPoint(room->points);
							E6HE e = placeEntity(er,p,4,true,0x22,0xe,false);
						}
						valid = true;
					}
					break;
				}
				case 0xa:
				case 0xb:
					if (e6_spawn6de200(room,dest->id))
						valid = true;
					break;
				case 0xc:
				{
					if (e6_spawn6de200(room,dest->id))
						valid = true;
					if (e6_overmind_cf6428.spawnPatrolParty(E6HE(),1,0,room,0,3,0,10,0))
					{
						E6Group *z18 = e6_overmind_cf6428.lastParty();
						E6Area m49;
						e6_cells_cfd44c.getRect(z18->leader->getPosition(),5,m49);
						z18->leader->getAI()->unknown459470(m49);
						E6Talk *ww47;
						e6_findTalk(e6_talks_d2c408,"MIN_Lonewolf_Counter",ww47);
						vector<E6HE> m43;
						e6_overmind_cf6428.members683410(z18->leader,m43);
						for (unsigned int i = 0; i < m43.size(); i++)
							m43[i]->unknown6395d0(ww47,false);
						e6_findTalk(e6_talks_d2c408,"MIN_Lonewolf_Intruder",ww47);
						z18->leader->unknown6395d0(ww47,false);
					}
					break;
				}
				case 0xd:
					if (e6_spawn6de200(room,dest->id))
						valid = true;
					break;
				case 0xf:
					if (e6_overmind_cf6428.spawnPatrolParty(E6HE(),1,0,room,0,0,0,10,0))
						valid = true;
					break;
				case 0x10:
				case 0x11:
				case 0x16:
				case 0x17:
				case 0x18:
				case 0x19:
				case 0x1a:
				case 0x1b:
				case 0x1c:
				case 0x1d:
				case 0x1e:
					if (e6_spawn6de200(room,dest->id))
						valid = true;
					break;
				case 0x22:
				{
					E6HLocation node;
					if (e6_location_d1e888->f8 != 9 || !e6_findNode(0x14,7,e6_d1e884,&node) || e6_locations_d1e88c[e6_locations_d1e88c.size() - 2]->dlev == 8)
					{
						E6ItemType *scrap;
						if (e6_findItem(e6_itemTypes_d2d1c4,"Scrap",scrap))
						{
							E6HItem item = e6_factory_cefaa8->createD(scrap);
							item->set44fc60(rng.rangeInt(0,1000000000));
							item->unknown57a0f0(e6_randomPoint(room->points),0,0);
							valid = true;
						}
						valid = true;
					}
					else if (e6_spawn6de200(room,dest->id))
						valid = true;
					break;
				}
				case 0x7b:
				{
					vector<E6Point> m59;
					m59.push_back(center);
					for (unsigned int i = 0; i < markers.size(); i++)
						m59.push_back(markers[i]->pos);
					vector<E6Point> z26;
					vector<E6Point> u33;
					for (unsigned int i = 0; i < m59.size(); i++)
						for (unsigned int j = i + 1; j < m59.size(); j++)
							if (e6_carto_cfe568.findPath(m59[i],m59[j],e6_cost_cefc30,0,u33))
								e6_appendPoints(z26,u33);
					E6ItemType *m57;
					e6_findItem(e6_itemTypes_d2d1c4,"Scrap",m57);
					for (unsigned int i = 0; i < room->points.size(); i++)
					{
						if (rng.chance(90))
							e6_setTerrainAt(room->points[i],TERRAIN_EARTH);
						else if (rng.chance(7) && m57 != 0)
						{
							E6HItem item = e6_factory_cefaa8->createD(m57);
							item->set44fc60(rng.rangeInt(0,1000000000));
							item->unknown57a0f0(room->points[i],0,0);
						}
					}
					bool u3 = rng.chance(40) ? true : false;
					for (unsigned int i = 0; i < z26.size(); i++)
					{
						if ((*e6_cells_cfd44c.atPoint(z26[i]))->terrainPtr() == TERRAIN_EARTH)
						{
							e6_setTerrainAt(z26[i],e6_floor_cefb9c);
							(*e6_cells_cfd44c.atPoint(z26[i]))->unknown66b700(rng.rangeInt(66,100) * 17 / 100,e6_d2c46c);
							if (rng.chance(5))
								unknown71e7c0(z26[i],rng.rangeInt(3,18),0);
							if (u3 && rng.chance(1))
							{
								vector<E6Point> around;
								sweepGetSurroundingCells(z26[i],around);
								e6_shufflePoints(around);
								for (unsigned int j = 0; j < around.size(); j++)
								{
									if ((*e6_cells_cfd44c.atPoint(around[j]))->terrainPtr() == TERRAIN_EARTH)
									{
										e6_bs_cefc4c->unknown6c6b90(around[j],"SUB_Collapsed_Ambush",0,-1);
										u3 = false;
										break;
									}
								}
							}
						}
					}
					valid = true;
					break;
				}
				case 0x7c:
				{
					E6Point p = e6_randomPoint(room->points);
					e6_bs_cefc4c->unknown6c6b90(p,"SUB_Collapse",0,-1);
					if (rng.chance(10))
					{
						E6Rec2 *et;
						e6_findEntity(e6_entities_d25de0,rng.chance(50) ? "Y-45 Defender" : "Subdweller",et);
						if (et != 0)
							E6HE e = placeEntity(et,p,et->f28 == 0x25 ? 6 : 3,true,1,0xe,false);
					}
					valid = true;
					break;
				}
				case 0x7d:
				{
					E6Rec2 *et;
					if (e6_findEntity(e6_entities_d25de0,"Artisan",et))
					{
						E6Point z37 = e6_randomPoint(room->points);
						E6HE z43 = e6_bs_cefc4c->placeEntity(et,z37,7,true,0x22,0xe,false);
						if (z43.isValid() && rng.chance(25))
						{
							flags.push_back(idx);
							line.push_back(z43->getAI()->unknown458ef0()[1]);
							edges.push_back(e6_vec_d22744.size() - 1);
						}
						valid = true;
					}
					break;
				}
				case 0x7e:
				{
					E6Rec2 *et;
					if (e6_findEntity(e6_entities_d25de0,"Cobbler",et))
					{
						E6Point p = e6_randomPoint(room->points);
						E6HE e = e6_bs_cefc4c->placeEntity(et,p,7,true,0x22,0xe,false);
						if (e.isValid())
						{
							if (rng.chance(5))
							{
								e->unknown5fd900(6,0);
								unknown6c65a0(e,"SUB_Cobbler_Restart",false);
							}
							E6Area z6;
							e6_cells_cfd44c.getRect(e->getPosition(),0x14,z6);
							E6Point m5;
							for (int i = 0; i < 20; i++)
							{
								for (int j = 0; j < 50; j++)
								{
									z6.randomPoint(&m5);
									if ((*e6_cells_cfd44c.atPoint(m5))->hasBlockingObject())
									{
										e6_bs_cefc4c->unknown71e7c0(m5,rng.rangeInt(5,15),0);
										break;
									}
								}
							}
							valid = true;
						}
					}
					break;
				}
				case 0x8f:
					if (e6_spawn6de200(room,dest->id))
						valid = true;
					break;
				case 0x7f:
				case 0x80:
				{
					flags.push_back(idx);
					E6Point p = e6_randomPoint(room->points);
					E6Point view(e6_clamp(0,p.x - 10,e6_cells_cfd44c.getWidth() - 20),e6_clamp(0,p.y - 10,e6_cells_cfd44c.getHeight() - 20));
					line.push_back(view);
					edges.push_back(-1);
					valid = true;
					break;
				}
				case 0x81:
				case 0x82:
				{
					E6Rec2 *et;
					e6_findEntity(e6_entities_d25de0,"Subdweller",et);
					if (et != 0)
					{
						E6HE e = placeEntity(et,e6_randomPoint(room->points),idx == 0x82 ? 5 : 6,true,0x22,0xe,false);
						if (e.isValid())
						{
							valid = true;
							if (idx == 0x82)
								e->getAI()->unknown459470(e6_cells_cfd44c.getArea());
							else
							{
								e->getAI()->unknown4594c0(room);
								for (int n = 1; n > 0; n--)
								{
									E6HE f = placeEntity(et,e->getPosition(),6,true,0x22,0xe,false);
									if (f.isValid())
										f->getAI()->setFollowEntity(e,0);
								}
							}
						}
					}
					break;
				}
				case 0x84:
				{
					E6WL traps;
					E6MachineDef *md;
					if (e6_findMachine(e6_machines_cf35b0,"Piercing Trap",md))
						traps.add((int)md,0x46);
					if (e6_findMachine(e6_machines_cf35b0,"Shrapnel Trap",md))
						traps.add((int)md,0x1e);
					if (traps.size() != 0)
					{
						E6Point p;
						for (int n = rng.rangeInt(10,15); n > 0; n--)
						{
							for (int t = 0; t < 10; t++)
							{
								p = e6_randomPoint(room->points);
								if ((*e6_cells_cfd44c.atPoint(p))->getProp().isNull())
								{
									placeProp(traps.pick(),p,-1,6,-1);
									break;
								}
							}
						}
						valid = true;
					}
					break;
				}
				case 0x90:
				{
					int q19 = room->points.size() / 10 + 1;
					E6Point u7;
					vector<E6Point> z7;
					int m7;
					do
					{
						for (int t = 0; t < 25; t++)
						{
							for (int u = 0; u < 10; u++)
							{
								u7 = e6_randomPoint(room->points);
								if ((*e6_cells_cfd44c.atPoint(u7))->field4550b0() && (*e6_cells_cfd44c.atPoint(u7))->getProp().isNull() && (*e6_cells_cfd44c.atPoint(u7))->getEntity().isNull() && (*e6_cells_cfd44c.atPoint(u7))->getItem().isNull() && !(*e6_cells_cfd44c.atPoint(u7))->isMachinePart())
									break;
								u7.x = -1;
							}
							if (u7.x != -1)
							{
								z7.clear();
								getAdjacentCells(u7,z7);
								m7 = 0;
								for (unsigned int k = 0; k < z7.size(); k++)
									if ((*e6_cells_cfd44c.atPoint(z7[k]))->isPassableFor(E6HE()))
										m7++;
								if (m7 >= 3)
								{
									e6_setTerrainAt(u7,TERRAIN_EARTH);
									break;
								}
							}
						}
					} while (--q19);
					valid = true;
					break;
				}
				case 0x9a:
				case 0x9b:
					if (e6_overmind_cf6428.spawnPatrolParty(E6HE(),1,0,room,0,0,0,10,0))
					{
						valid = true;
						if (idx == 0x9b)
						{
							e6_overmind_cf6428.lastParty()->leader->getAI()->unknown4594c0(room);
							unknown6dd0e0(e6_randomPoint(room->points),0x12);
							unknown6dd0e0(e6_randomPoint(room->points),0x12);
							unknown6dd0e0(e6_randomPoint(room->points),0x11);
						}
					}
					break;
				case 0xa2:
					if (e6_spawn6de200(room,dest->id))
						valid = true;
					break;
				case 0x93:
				case 0x94:
				{
					E6WL ranks;
					if (idx == 0x94)
					{
						ranks.add(1,100);
						ranks.add(5,50);
					}
					ranks.add(0x35,0x19);
					E6Rec2 *er = selectRobotOfClass(3,ranks.pick(),false,false);
					if (er != 0)
					{
						for (int n = rng.rangeInt(1,3); n > 0; n--)
						{
							E6Point p = e6_randomPoint(room->points);
							E6HE e = placeEntity(er,p,7,true,0x22,0xe,false);
							if (e.isValid())
							{
								vector<E6HItem> *inv = e->getInventoryList();
								for (unsigned int j = 0; j < inv->size(); j++)
									(*inv)[j]->set450460(e6_maxInt(1,rng.rangeInt(10,50) * (*inv)[j]->get9b6bf0() / 100));
								if (idx == 0x94)
									e->getAI()->unknown4594c0(room);
							}
						}
						unknown6dd0e0(e6_randomPoint(room->points),0x12);
						if (idx == 0x94)
						{
							unknown6dd0e0(e6_randomPoint(room->points),0x12);
							unknown6dd0e0(e6_randomPoint(room->points),0x11);
						}
						valid = true;
					}
					break;
				}
				case 0x99:
				{
					E6Rec2 *er = selectRobotOfClass(1,7,false,true);
					if (er != 0)
					{
						E6WL traps;
						E6MachineDef *md;
						if (e6_findMachine(e6_machines_cf35b0,"Dirty Bomb Trap",md))
							traps.add((int)md,10);
						if (e6_findMachine(e6_machines_cf35b0,"Fire Trap",md))
							traps.add((int)md,10);
						if (traps.size() != 0)
						{
							E6Point p = e6_randomPoint(room->points);
							E6HE e = placeEntity(er,p,4,true,0x22,0xe,false);
							if (e.isValid())
							{
								e->getAI()->unknown4594c0(room);
								for (int n = rng.rangeInt(8,12); n > 0; n--)
								{
									for (int t = 0; t < 10; t++)
									{
										p = e6_randomPoint(room->points);
										if ((*e6_cells_cfd44c.atPoint(p))->getProp().isNull())
										{
											placeProp(traps.pick(),p,-1,9,-1);
											break;
										}
									}
								}
								if (rng.chance(50))
								{
									E6Rec2 *escort = selectRobotOfClass(1,0x10,false,true);
									if (escort != 0)
									{
										for (int n = rng.rangeInt(1,2); n > 0; n--)
										{
											E6HE f = placeEntity(escort,e->getPosition(),3,true,0x22,0xe,false);
											if (f.isValid())
												f->getAI()->setFollowEntity(e,0);
										}
									}
								}
								unknown6dd0e0(e6_randomPoint(room->points),0x12);
								unknown6dd0e0(e6_randomPoint(room->points),0x11);
								unknown6dd0e0(e6_randomPoint(room->points),0x11);
							}
							valid = true;
						}
					}
					break;
				}
				case 0xb4:
				case 0xb5:
				case 0xb7:
				{
					int ra11 = dest->f20 == 0xb4 ? 0x14 : (dest->f20 == 0xb5 ? 0x15 : 0x17);
					E6HLocation ra15;
					if (!e6_findNode(ra11,ra11 == 0x14 ? -1 : e6_location_d1e888->f8,e6_d1e884,&ra15))
						;
					else if (ra15->f8 <= e6_location_d1e888->f8 && e6_location_d1e888->b24 && e6_spawn6de200(room,dest->id))
						valid = true;
					if (!valid)
					{
						E6ItemType *scrap;
						if (e6_findItem(e6_itemTypes_d2d1c4,"Scrap",scrap))
						{
							E6HItem item = e6_factory_cefaa8->createD(scrap);
							item->set44fc60(rng.rangeInt(0,1000000000));
							item->unknown57a0f0(e6_randomPoint(room->points),0,0);
							valid = true;
						}
					}
					break;
				}
				case 0xb9:
				{
					E6Rec2 *et;
					if (e6_findEntity(e6_entities_d25de0,"N-01 Spotter",et))
					{
						for (int i = 0; i < 2; i++)
						{
							E6Point p = e6_randomPoint(room->points);
							E6HE e = placeEntity(et,p,3,true,0x22,0xe,false);
						}
						valid = true;
					}
					break;
				}
				case 0xba:
					if (e6_spawn6de200(room,dest->id))
						valid = true;
					break;
				case 0x128:
				case 0x129:
				case 0x12a:
				{
					E6Rec2 *et;
					e6_findEntity(e6_entities_d25de0,idx == 0x12a ? "Enhanced Hunter" : "Enhanced Grunt",et);
					if (et != 0)
					{
						E6HE e = placeEntity(et,e6_randomPoint(room->points),0xc,true,0x22,0xe,false);
						if (e.isValid())
						{
							valid = true;
							if (idx == 0x129)
								e->getAI()->unknown4594c0(room);
							for (int n = idx == 0x12a ? 1 : 2; n > 0; n--)
							{
								E6HE f = placeEntity(et,e->getPosition(),0xc,true,0x22,0xe,false);
								if (f.isValid())
									f->getAI()->setFollowEntity(e,0);
							}
						}
					}
					break;
				}
				default:
					dest->prefabs.empty();
					break;
				}
				if (false) {}
				if (valid)
				{
					iter--;
					e6_vec_d1e8d0[idx]++;
					if (dest->f30 < 0)
						e6_removeValue(e6_location_d1e888->list30,dest->f20);
					if (!dest->unknown517290())
						score.remove(idx);
					if (amount != 0 && --amount == 0)
						for (unsigned int i = 0; i < old.size(); i++)
							score.setWeight(old[i],oldValue[i]);
					if (dest->group34 != '-')
					{
						char group = dest->group34;
						for (unsigned int i = 0; i < score.values.size(); i++)
						{
							if (e6_records_d21afc[score.values[i]]->group34 == group && e6_records_d21afc[score.values[i]] != dest)
							{
								score.removeAt(i);
								i--;
								break;
							}
						}
					}
					if (!dest->exclusions.empty())
					{
						string &tags = dest->exclusions;
						for (unsigned int i = 0; i < score.values.size(); i++)
						{
							if (e6_records_d21afc[score.values[i]]->tag35 != '-' && tags.find(e6_records_d21afc[score.values[i]]->tag35,0) != string::npos)
							{
								score.removeAt(i);
								i--;
								break;
							}
						}
					}
					if (dest->bc1)
						e6_removeValue(hits[idx],last);
					if (element != 0)
						e6_grid_cf447c.fillRect(element->rect.topLeft(),E6Point(element->rect.right(),element->rect.bottom()),5);
					else
						for (unsigned int i = 0; i < room->points.size(); i++)
							*e6_grid_cf447c.atPoint(room->points[i]) = 5;
					if (room != 0)
						visited.push_back(encounters[best]);
					usedEncounters.push_back(encounters[best]);
					e6_removeElement(encounters,best);
					encounterRecords.push_back(idx);
					encounterRects.push_back(room ? E6Rect(-1,-1,-1,-1) : E6Rect(element->rect));
					if (dest->f7c != 0 && room != 0 && e6_location_d1e888->dlev == 15 && (dest->f7c == 1 || dest->f7c == 3))
						for (unsigned int i = 0; i < room->points.size(); i++)
							*e6_grid_cf11a0.atPoint(room->points[i]) = 1;
					break;
				}
			}
			if (++attempts == 20)
			{
				int ri = e6_randomIndex(encounters);
				if (e6_noArea_b90158[ay])
					addGroup(0x12e,0,&e6_rooms_cf126c[encounters[ri]]);
				else
					addGroup(0x12e,&e6_areas_cf13e8[encounters[ri]].rect,0);
				e6_removeElement(encounters,ri);
				break;
			}
		}
	}
	if (e6_location_d1e888->dlev == 15)
	{
		vector<E6Point> hubs;
		hubs.push_back(center);
		for (unsigned int i = 0; i < markers.size(); i++)
			hubs.push_back(markers[i]->pos);
		for (unsigned int i = 0; i < hubs.size() - 1; i++)
		{
			for (unsigned int j = i + 1; j < hubs.size(); j++)
			{
				vector<E6Point> path;
				if (e6_carto_cfe568.findPath(hubs[i],hubs[j],e6_cost_cefc30,0,path))
					for (unsigned int k = 0; k < path.size(); k++)
						*e6_grid_cf11a0.atPoint(path[k]) = 1;
			}
		}
		for (unsigned int i = 0; i < flags.size(); i++)
		{
			switch (flags[i])
			{
			case 0x7d:
				unknown74ba20(e6_vec_d22744[edges[i]],line[i]);
				break;
			case 0x7f:
			case 0x80:
			{
				int ra19 = flags[i];
				E6Point q28(line[i]);
				unknown74b2c0(q28);
				unknown74ba20(e6_vec_d22744.back(),q28);
				e6_deleteBack(e6_vec_d22744);
				E6Area ww11;
				e6_cells_cfd44c.getRect(E6Point(q28,10),10,ww11);
				E6Point uu38;
				int uu34 = 2;
				for (int t = 0; t < (ra19 == 0x7f ? 2 : 1); t++)
				{
					for (int u = 0; u <= 1000; u++)
					{
						ww11.randomPoint(&uu38);
						if ((*e6_cells_cfd44c.atPoint(uu38))->getProp().isValid() && (*e6_cells_cfd44c.atPoint(uu38))->getProp()->type4() == e6_machineType_cefbd8 && countPassableAdjacent(uu38) >= uu34)
						{
							if (ra19 == 0x7f)
								unknown6c6700((*e6_cells_cfd44c.atPoint(uu38))->getProp(),"SUB_TMachinery_Part_See",0);
							else
							{
								unknown6c6700((*e6_cells_cfd44c.atPoint(uu38))->getProp(),"SUB_TMachinery_Subs_See",0);
								unknown6c6700((*e6_cells_cfd44c.atPoint(uu38))->getProp(),"SUB_TMachinery_Subs_Dst",0);
							}
							unknown6dd0e0(uu38,flags[i] == 0x80 ? 0x14 : 0x13);
							break;
						}
					}
				}
				break;
			}
			}
		}
	}
	if (e6_anyNonZero(e6_logs_b90780[ay],3) && e6_findItem(e6_itemTypes_d2d1c4,"Derelict Log",found))
	{
		E6WL q35;
		for (int k = 0; k < 3; k++)
			if (e6_logs_b90780[ay][k] != 0)
				q35.add(k + 1,e6_logs_b90780[ay][k]);
		int ww15 = q35.pick();
		if (ww15 != 0)
		{
			if (!e6_logLists_d1e32c[ratio])
				;
			else
			{
				while (ww15 != 0)
				{
					E6Point spot;
					E6Point drop;
					for (int t = 0; t < 30; t++)
					{
						e6_cells_cfd44c.getRandom(&spot);
						if (!(*e6_cells_cfd44c.atPoint(spot))->hasBlockingObject())
						{
							t--;
							continue;
						}
						if (!e6_flag448b60(spot) && unknown71bc10(spot,drop))
						{
							E6HItem log = e6_factory_cefaa8->createD(found);
							log->addEffect(new E6Effect(e6_effects_d2f0f8[0x4e],e6_logLists_d1e32c[ratio]->pickNT()));
							log->unknown57a0f0(drop,0,0);
							break;
						}
					}
					ww15--;
				}
			}
		}
	}
	if (e6_anyNonZero(e6_scrap_b90948[ay],5) && e6_findItem(e6_itemTypes_d2d1c4,"Scrap",closest))
	{
		E6WL q53;
		for (int k = 0; k < 5; k++)
			if (e6_scrap_b90948[ay][k] != 0)
				q53.add(k + 1,e6_scrap_b90948[ay][k]);
		int ww19 = q53.pick();
		while (ww19 != 0)
		{
			E6Point spot;
			E6Point drop;
			for (int t = 0; t < 30; t++)
			{
				e6_cells_cfd44c.getRandom(&spot);
				if (!(*e6_cells_cfd44c.atPoint(spot))->hasBlockingObject())
				{
					t--;
					continue;
				}
				if (!e6_flag448b60(spot) && unknown71bc10(spot,drop))
				{
					E6HItem scrap = e6_factory_cefaa8->createD(closest);
					scrap->set44fc60(rng.rangeInt(0,1000000000));
					scrap->unknown57a0f0(drop,0,0);
					if (ww19 == 1 && e6_scrapChance_b90cd8[ay] != 0 && rng.chance(e6_scrapChance_b90cd8[ay]))
						scrap->addEffect(new E6Effect(e6_effects_d2f0f8[0x67],1));
					break;
				}
			}
			ww19--;
		}
	}
}
