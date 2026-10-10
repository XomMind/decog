// team_c_56: Overmind::spawnPatrolParty (0x6896d0): picks a patrol type (weighted by depth, or given), finds a leader
//	record and a spawn location, places the leader and its followers, and registers the party
// NOTE: names are placeholders; Overmind layout is partial
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908
void logError(string location, string message);
int OpT8a_sumVector(vector<int> &v);
void OpV4c_Fn9d0690(int *value, int a, int b);	// NOTE: placeholder name

struct C56_Point { int x; int y; C56_Point(); C56_Point(const C56_Point &o); C56_Point &operator=(const C56_Point &o); };	// NOTE: placeholder (Point)
struct C56_Pos { int x; int y; C56_Pos(int v); };	// NOTE: placeholder (Pos)
struct C56_Range { int lo; int hi; int randomInRange_40c130(); };	// NOTE: placeholder (Point)
struct C56_Rect { C56_Point randomPos_40b080(); };	// NOTE: placeholder (Rect)
C56_Point OpU8a_randomPoint(vector<C56_Point> *points);	// NOTE: placeholder name
bool terrainFlagB_448b80(C56_Point &p);	// NOTE: placeholder name
struct C56_Record { char pad0[0x28]; int f28; char pad2c[0x9c - 0x2c]; int f9c; };	// NOTE: placeholder (entity record)
struct C56_Cell { bool canPlaceEntity(int size); };
struct C56_CellGrid { C56_Cell **atPoint(C56_Point &p); void getRandom_9cf0c0(C56_Point *out); };
struct C56_AI { void unknown5b51b0(int entity); void set_combat_programmer(int value); void setFollowEntity(int entity, int flag); };	// NOTE: placeholder names
struct C56_Entity { C56_AI *unknown45b590(); C56_Point &getPosition(); };
class C56_HEntity { public: int ID; C56_HEntity(); C56_Entity *operator->() const; bool isNull() const; bool isValid() const; };	// NOTE: placeholder (HEntity)
struct C56_Loc { int f0; int f4; int f8; };
class C56_HLoc { public: int ID; C56_HLoc(); C56_Loc *operator->() const; };	// NOTE: placeholder (location handle)
template <class T> class C56_WL { public: vector<T> values; vector<int> weights; int total; C56_WL(); ~C56_WL(); void add(T value, int weight); bool pick(T *out); };	// NOTE: placeholder (OpR5h_WL)
struct C56_World { C56_Record *selectRobotOfClass(int a, int b, int c, int d); int getDisabledGarrisonAccesses(); C56_HEntity placeEntity(C56_Record *record, const C56_Point &position, int groupIndex, bool flag, int aiMode1, int aiMode2, bool forced); bool findRandomPlaceable(const C56_Point &center, int radius, int size, C56_Point &out, bool checkEntrance); };	// NOTE: placeholder (BS)
struct C56_GameData { int getDepthIndex(); bool isFlagEnabledC(); };
class C56_Party { public: C56_Party(int type, C56_HEntity leader, int a, int b, int c); char data[0x38]; };	// NOTE: placeholder (Party)
template <class T> bool OpQ5_findByName(vector<T *> &v, const string &name, T *&result);	// NOTE: placeholder name

extern C56_HLoc c56_d1e888;	// NOTE: placeholder names below
extern vector<C56_HLoc> c56_d1e88c;
extern C56_GameData c56_d1e860;
extern int c56_b92050[][10];
extern C56_Range c56_d1d640[][10];
extern vector<C56_Record *> c56_d25de0;
extern C56_World *c56_cefc4c;
extern bool c56_d1ebfc;
extern C56_CellGrid c56_cfd44c;
extern vector<int> c56_d1eb44;
extern int c56_cf4718;

class Overmind	// NOTE: placeholder layout (partial)
{
public:
	char pad0[0x41];
	bool f41;
	char pad42[0x128 - 0x42];
	int f128;

	bool findDispatchExit(C56_Point *out, int a, int b, int c, const C56_Pos &p, int *d, int e, int f);	// NOTE: placeholder name
	void addParty(C56_Party *party, int a);	// NOTE: placeholder name
	int spawnPatrolParty(C56_HEntity owner, bool flag, C56_Rect *area, vector<C56_Point> *points, C56_Point *pos, int count, vector<C56_HEntity> *out, int type, bool b);
};

int Overmind::spawnPatrolParty(C56_HEntity owner, bool flag, C56_Rect *area, vector<C56_Point> *points, C56_Point *pos, int count, vector<C56_HEntity> *out, int type, bool b)
{
	if (owner.isNull() && !flag && c56_d1e888->f4 == 34)
	{
		logError("Overmind::spawnPatrolParty()","method not supported in COM");
		return 0;
	}
	C56_WL<int> a1;
	for (int cols = 0; cols < 10; cols++)
		a1.add(cols,c56_b92050[c56_d1e860.getDepthIndex()][cols]);
	C56_Record *col = 0;
	C56_Record *adj = 0;
	int allies;
	if (type != 10)
		allies = type;
	else
		a1.pick(&allies);
	if (owner.isNull() && ((allies <= 5 && rng.chance(7)) || (!flag && allies != 9)) && c56_d1e860.getDepthIndex() > 1)
		OpQ5_findByName(c56_d25de0,"C-30 ARC",col);
	if (col == 0)
	{
		switch (allies)
		{
			case 0:
				col = c56_cefc4c->selectRobotOfClass(1,13,0,b);
				break;
			case 1:
				col = c56_cefc4c->selectRobotOfClass(1,14,0,b);
				break;
			case 2:
				col = c56_cefc4c->selectRobotOfClass(1,16,1,b);
				adj = c56_cefc4c->selectRobotOfClass(1,16,0,b);
				break;
			case 3:
				col = c56_cefc4c->selectRobotOfClass(1,17,0,b);
				adj = c56_cefc4c->selectRobotOfClass(1,16,0,b);
				break;
			case 4:
				col = c56_cefc4c->selectRobotOfClass(1,18,0,b);
				adj = c56_cefc4c->selectRobotOfClass(1,16,0,b);
				break;
			case 5:
				col = c56_cefc4c->selectRobotOfClass(1,24,0,b);
				break;
			case 6:
				col = c56_cefc4c->selectRobotOfClass(1,25,0,b);
				break;
			case 7:
				col = c56_cefc4c->selectRobotOfClass(1,24,0,b);
				adj = c56_cefc4c->selectRobotOfClass(1,16,0,b);
				break;
			case 8:
				OpQ5_findByName(c56_d25de0,"Hotshot",col);
				if (c56_d1e888->f4 == 33 && c56_d1e860.isFlagEnabledC())
					count = 3;
				break;
			case 9:
				if (c56_cefc4c->getDisabledGarrisonAccesses())
				{
					switch (rng.rangeInt(1.0f,2.0f))
					{
						case 1:
							OpQ5_findByName(c56_d25de0,"H-88 Terminator",col);
							count = 4;
							break;
						case 2:
							OpQ5_findByName(c56_d25de0,"P-80 Master",col);
							count = 4;
							break;
					}
					if (c56_d1e860.isFlagEnabledC())
						count--;
				}
				else
				{
					switch (rng.rangeInt(1.0f,3.0f))
					{
						case 1:
							OpQ5_findByName(c56_d25de0,"Hotshot",col);
							count = 4;
							break;
						case 2:
							OpQ5_findByName(c56_d25de0,"Decapitator",col);
							count = 4;
							break;
						case 3:
							OpQ5_findByName(c56_d25de0,"Immortal",col);
							count = 3;
							break;
					}
					if (c56_d1e860.isFlagEnabledC())
						count = 2;
				}
				break;
		}
		if (c56_d1ebfc)
		{
			switch (allies)
			{
				case 0:
					if (rng.chance(50))
					{
						col = rng.chance(50) ? c56_cefc4c->selectRobotOfClass(1,14,0,1) : c56_cefc4c->selectRobotOfClass(2,30,0,1);
						if (col->f28 == 30)
							count = 2;
					}
					break;
				case 2:
					if (rng.chance(25))
					{
						col = c56_cefc4c->selectRobotOfClass(1,23,0,0);
						adj = 0;
					}
					break;
				case 5:
					if (rng.chance(33))
					{
						col = c56_cefc4c->selectRobotOfClass(2,31,0,0);
						adj = 0;
					}
					break;
				case 6:
					if (rng.chance(33))
					{
						col = c56_cefc4c->selectRobotOfClass(1,22,0,0);
						adj = 0;
					}
					break;
			}
		}
	}
	if (col == 0)
		return 0;
	int base = 0;
	C56_Point amount;
	int areas = 0;
	bool attempt = false;
	bool arr = false;
	if (owner.isValid())
	{
		amount = owner->getPosition();
		attempt = true;
	}
	else if (pos != 0)
	{
		amount = *pos;
		attempt = true;
	}
	else if (!flag)
	{
		attempt = findDispatchExit(&amount,1,0,1,C56_Pos(-1),&areas,0,0);
		if (!attempt)
			f128++;
		else
			OpV4c_Fn9d0690(&f128,1,0);
	}
	else
	{
		for (int cols = 0; cols < 100; cols++)
		{
			if (area != 0)
				amount = area->randomPos_40b080();
			else if (points != 0)
				amount = OpU8a_randomPoint(points);
			else
				c56_cfd44c.getRandom_9cf0c0(&amount);
			if ((*c56_cfd44c.atPoint(amount))->canPlaceEntity(col->f9c) && !terrainFlagB_448b80(amount))
			{
				attempt = true;
				break;
			}
		}
	}
	if (attempt)
	{
		bool cols = false;
		C56_HEntity behaviour = c56_cefc4c->placeEntity(col,amount,cols ? 2 : 3,flag,arr ? 3 : 34,14,false);
		if (behaviour.isValid())
		{
			base++;
			if (out != 0)
				out->push_back(behaviour);
			if (owner.isValid())
				owner->unknown45b590()->unknown5b51b0(behaviour.ID);
			if (allies == 7)
				behaviour->unknown45b590()->set_combat_programmer(75);
			int current = count != 0 ? count - 1 : (col->f28 == 6 ? 0 : c56_d1d640[c56_d1e860.getDepthIndex()][allies].randomInRange_40c130() - 1);
			C56_HLoc clean;
			if (current > 1 && c56_d1e88c.size() >= 2)
			{
				clean = c56_d1e88c[c56_d1e88c.size() - 2];
				if (clean->f4 == 13 && clean->f8 == c56_d1e888->f8)
					current--;
			}
			if (current > 1 && c56_d1e888->f4 == 33 && OpT8a_sumVector(c56_d1eb44) >= 6)
				current--;
			if (current > 1 && f41)
				current--;
			if (current > 1 && c56_cf4718 == 2)
				current--;
			while (current > 0)
			{
				C56_Point distanceSq(amount);
				if (flag)
					c56_cefc4c->findRandomPlaceable(behaviour->getPosition(),3,(adj != 0 ? adj : col)->f9c,distanceSq,flag);
				C56_HEntity distances = c56_cefc4c->placeEntity(adj != 0 ? adj : col,distanceSq,cols ? 2 : 3,flag,34,14,false);
				if (distances.isNull())
					break;
				distances->unknown45b590()->setFollowEntity(behaviour.ID,0);
				if (out != 0)
					out->push_back(distances);
				if (owner.isValid())
					owner->unknown45b590()->unknown5b51b0(distances.ID);
				base++;
				current--;
			}
			if (!cols)
				addParty(new C56_Party(2,behaviour,-1,0,0),areas);
		}
	}
	return base;
}
