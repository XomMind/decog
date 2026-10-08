// team_c_58: Architect map setup (0x6e2110): marks special rooms, crumbles cave walls around tunnels and caves, opens the
//	central cross, wakes the architect squad, places exploration markers and seeds the cave caches
// NOTE: names are placeholders; BS layout is partial
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908
struct C58_Point { int x; int y; C58_Point(); C58_Point(const C58_Point &p, int dx, int dy); C58_Point(int x_, int y_); int distanceTo(const C58_Point &p); };	// NOTE: placeholder (Point/Pos)
struct C58_Rect { int x; int y; int w; int h; C58_Rect(const C58_Point &p, int w_, int h_); void expandToInclude_40af10(const C58_Point &p); int right(); int bottom(); };	// NOTE: placeholder (Rect)
struct C58_Box { int a; int b; int c; int d; C58_Box(const C58_Point &p, int w, int h); C58_Box(int x, int y, int w, int h); void randomPoint_40be30(C58_Point *out); };	// NOTE: placeholder (OpQ1_Box)
struct C58_Area { void set40a060(const C58_Point &p, int w, int h); };	// NOTE: placeholder
struct C58_Room { char pad0[0x48]; int f48; int f4c; C58_Point f50; char pad58[8]; };	// NOTE: placeholder (0x60)
struct C58_Tunnel { vector<C58_Point> pts; char pad10[0x10]; };	// NOTE: placeholder (0x20)
struct C58_Cave { vector<C58_Point> pts; char pad10[0x44 - 0x10]; bool f44; bool f45; char pad46[0x54 - 0x46]; };	// NOTE: placeholder (0x54)
struct CellTerrainRecord;
extern CellTerrainRecord *TERRAIN_CAVE_WALL;
extern CellTerrainRecord *caveinThirdTerrain;
struct C58_Item { bool getField(); void unknown458390(int a); };
class C58_HItem { public: int ID; C58_HItem(); C58_Item *operator->() const; bool isValid() const; bool isNull() const; };	// NOTE: placeholder (HItem/HProp)
struct C58_Cell { CellTerrainRecord *getTerrain(); bool getField(); C58_HItem getProp(); };
struct C58_CellGrid { C58_Cell **atPoint(C58_Point &p); int getMaxX(); int getMaxY(); };
struct C58_AI { void unknown5b4710(int entity, int a, int b, int c, int d); };
struct C58_Entity { int getFaction(); C58_AI *unknown45b590(); };
class C58_HEntity { public: int ID; C58_Entity *operator->() const; };	// NOTE: placeholder (HEntity)
struct C58_Squad { vector<C58_HEntity> *getMembers(); };
class C58_HSquad { public: int ID; C58_Squad *operator->() const; };	// NOTE: placeholder
struct C58_IntGrid { int w; int h; int *cells; int *at(int x, int y); };
struct C58_GameData { void setEntryText(const string &key, const string &value); };
struct C58_Record;
template <class T> bool OpQ5_findByName(vector<T *> &v, const string &name, T *&result);	// NOTE: placeholder name
void sweepGetSurroundingCells(const C58_Point &p, vector<C58_Point> &out);	// NOTE: placeholder name
void teamb_setTerrainAt(C58_Point &p, CellTerrainRecord *terrain);	// NOTE: placeholder name

extern vector<C58_Room> c58_cf124c;	// NOTE: placeholder names below
extern vector<C58_Tunnel> c58_cf125c;
extern vector<C58_Cave> c58_cf126c;
extern int c58_d33ad4, c58_d329a0;
extern C58_Area c58_d1ec6c;
extern vector<C58_Box> c58_d1ec74;
extern C58_CellGrid c58_cfd44c;
extern C58_GameData c58_d1e860;
extern vector<C58_Record *> c58_d2c408;
extern const char c58_empty_b958ba[];

class BS	// NOTE: placeholder layout (partial)
{
public:
	char pad0[0x4c];
	vector<C58_HSquad> f4c;
	C58_IntGrid f5c;
	char pad68[0x66c - 0x68];
	int f66c;

	C58_Record *selectRandomItem(int a, int b, int c);
	C58_HItem unknown6c5400(C58_Record *record, const C58_Point &p);
	void unknown6c6b90(const C58_Point &p, const string &text, C58_Record *record, int a);
	void setupArchitect_6e2110();
};

void BS::setupArchitect_6e2110()
{
	for (unsigned int col = 0; col < c58_cf124c.size(); col++)
	{
		if (c58_cf124c[col].f48 == c58_d33ad4)
			c58_d1ec6c.set40a060(c58_cf124c[col].f50,8,8);
		else if (c58_cf124c[col].f4c == c58_d329a0)
			c58_d1ec74.push_back(C58_Box(C58_Point(c58_cf124c[col].f50,3,3),4,4));
	}
	vector<C58_Point> adj;
	for (unsigned int col = 0; col < c58_cf125c.size(); col++)
	{
		for (unsigned int cols = 0; cols < c58_cf125c[col].pts.size(); cols++)
		{
			adj.clear();
			sweepGetSurroundingCells(c58_cf125c[col].pts[cols],adj);
			for (unsigned int current = 0; current < adj.size(); current++)
			{
				if ((*c58_cfd44c.atPoint(adj[current]))->getTerrain() == TERRAIN_CAVE_WALL && rng.chance(50))
					teamb_setTerrainAt(adj[current],caveinThirdTerrain);
			}
		}
	}
	for (unsigned int col = 0; col < c58_cf126c.size(); col++)
	{
		if (c58_cf126c[col].f44)
		{
			for (unsigned int cols = 0; cols < c58_cf126c[col].pts.size(); cols++)
			{
				adj.clear();
				sweepGetSurroundingCells(c58_cf126c[col].pts[cols],adj);
				for (unsigned int current = 0; current < adj.size(); current++)
				{
					if ((*c58_cfd44c.atPoint(adj[current]))->getTerrain() == TERRAIN_CAVE_WALL && rng.chance(50))
						teamb_setTerrainAt(adj[current],caveinThirdTerrain);
				}
			}
		}
	}
	for (int col = 0; col < 15; col++)
	{
		if (col != 12)
		{
			*f5c.at(12,col) = 0;
			*f5c.at(col,12) = 0;
		}
	}
	c58_d1e860.setEntryText("enemiesWithArchitect_g","1");
	vector<C58_HEntity> *a1 = f4c[12]->getMembers();
	for (unsigned int col = 0; col < a1->size(); col++)
	{
		if ((*a1)[col]->getFaction() == 96)
		{
			(*a1)[col]->unknown45b590()->unknown5b4710(f66c,-2,1,0,0);
			break;
		}
	}
	const int allies = 100;
	C58_Box attempt(0,50,c58_cfd44c.getMaxX(),c58_cfd44c.getMaxY());
	const int begin = 8;
	vector<C58_Point> center;
	C58_Point behaviour;
	C58_Record *branch;
	OpQ5_findByName(c58_d2c408,"AC0_Exploration_Marker",branch);
	for (int col = 0; col < allies; col++)
	{
		for (int cols = 0; cols < allies * 2; cols++)
		{
			attempt.randomPoint_40be30(&behaviour);
			if ((*c58_cfd44c.atPoint(behaviour))->getField() && (*c58_cfd44c.atPoint(behaviour))->getProp().isNull())
			{
				bool current = cols >= allies;
				if (!current)
				{
					current = true;
					for (unsigned int distanceSq = 0; distanceSq < center.size(); distanceSq++)
					{
						if (behaviour.distanceTo(center[distanceSq]) <= begin)
						{
							current = false;
							break;
						}
					}
				}
				if (current)
				{
					unknown6c6b90(behaviour,c58_empty_b958ba,branch,-1);
					center.push_back(behaviour);
					break;
				}
			}
		}
	}
	for (unsigned int col = 0; col < c58_cf126c.size(); col++)
	{
		if (c58_cf126c[col].f44 && !c58_cf126c[col].f45)
		{
			C58_Rect cols(c58_cf126c[col].pts[0],1,1);
			int clean;
			for (unsigned int current = 0; current < c58_cf126c[col].pts.size(); current++)
				cols.expandToInclude_40af10(c58_cf126c[col].pts[current]);
			for (int current = cols.x + 1; current <= cols.right() - 2; current += 3)
			{
				for (int distanceSq = cols.y + 1; distanceSq <= cols.bottom() - 2; distanceSq += 3)
				{
					C58_Record *distances = selectRandomItem(1,31,18);
					for (int enemies = current, count = 0; count < 2; enemies++, count++)
					{
						for (int facing = distanceSq, desc = 0; desc < 2; facing++, desc++)
						{
							C58_HItem first = unknown6c5400(distances,C58_Point(enemies,facing));
							if (first.isValid() && first->getField())
								first->unknown458390(0);
						}
					}
				}
			}
		}
	}
}
