// team_c_60: Zion/derelict squad deployment (0x741610): builds the squad composition table, then for the requested mode
//	spawns 1-4 squads at the map's first exit, leader first, with patrol targets for mode 1
// NOTE: names are placeholders; BS layout is partial
#include <vector>
using namespace std;

struct C60_Point { int x; int y; C60_Point(const C60_Point &p); };	// NOTE: placeholder (Point)
struct C60_Box { int a; int b; int c; int d; C60_Box(int x, int y, int w, int h); bool contains_40b750(const C60_Point &p); C60_Point randomPoint_40be90(); };	// NOTE: placeholder (OpQ1_Box)
struct C60_AI { void setFollowEntity(int entity, int flag); void unknown459410(C60_Box &area); void unknown4582d0(int mode); void unknown4593d0(vector<C60_Point> &points); void setField0(int v); };	// NOTE: placeholder names
struct C60_Entity { C60_AI *unknown45b590(); };
class C60_HEntity { public: int ID; C60_HEntity(); C60_Entity *operator->() const; bool isValid() const; void resetField(); };	// NOTE: placeholder (HEntity)
struct C60_Record;
struct C60_CellGrid { int getWidth(); int getHeight(); C60_Point getRandom_9cf050(); };
struct C60_World { bool unknown716940(const C60_Point &from, const C60_Point &to, int a, int b); };
template <class T> class C60_WL { public: vector<T> values; vector<int> weights; int total; C60_WL(vector<int> &w); ~C60_WL(); T &pick(); };	// NOTE: placeholder (OpR5h_WL)
extern C60_CellGrid c60_cfd44c;	// NOTE: placeholder names
extern C60_World *c60_cefc4c;

class BS	// NOTE: placeholder layout (partial)
{
public:
	char pad0[0x10];
	vector<C60_Point *> f10;

	C60_Record *selectRobotOfClass(int a, int b, bool c, bool d);
	C60_HEntity placeEntity(C60_Record *record, const C60_Point &position, int groupIndex, bool flag, int aiMode1, int aiMode2, bool forced);
	void unknown741610(int type);
};

void BS::unknown741610(int type)
{
	vector< vector<int> > adj;
	vector<int> amount;
	adj.push_back(vector<int>());
	adj.back().push_back(16);
	adj.back().push_back(16);
	adj.back().push_back(16);
	adj.back().push_back(16);
	amount.push_back(25);
	adj.push_back(vector<int>());
	adj.back().push_back(16);
	adj.back().push_back(16);
	adj.back().push_back(16);
	adj.back().push_back(19);
	amount.push_back(5);
	adj.push_back(vector<int>());
	adj.back().push_back(23);
	adj.back().push_back(16);
	adj.back().push_back(16);
	adj.back().push_back(16);
	amount.push_back(10);
	adj.push_back(vector<int>());
	adj.back().push_back(16);
	adj.back().push_back(16);
	adj.back().push_back(15);
	adj.back().push_back(15);
	adj.back().push_back(15);
	amount.push_back(10);
	adj.push_back(vector<int>());
	adj.back().push_back(17);
	adj.back().push_back(17);
	adj.back().push_back(18);
	adj.back().push_back(19);
	amount.push_back(5);
	adj.push_back(vector<int>());
	adj.back().push_back(16);
	adj.back().push_back(16);
	adj.back().push_back(17);
	adj.back().push_back(18);
	adj.back().push_back(8);
	amount.push_back(10);
	adj.push_back(vector<int>());
	adj.back().push_back(13);
	adj.back().push_back(13);
	adj.back().push_back(13);
	adj.back().push_back(13);
	adj.back().push_back(13);
	amount.push_back(15);
	adj.push_back(vector<int>());
	adj.back().push_back(24);
	adj.back().push_back(24);
	adj.back().push_back(13);
	adj.back().push_back(13);
	amount.push_back(10);
	adj.push_back(vector<int>());
	adj.back().push_back(25);
	adj.back().push_back(25);
	adj.back().push_back(25);
	amount.push_back(10);
	C60_WL<int> allies(amount);
	int a1 = 0;
	switch (type)
	{
		case 1:
			a1 = 4;
			break;
		case 2:
			a1 = 1;
			break;
		case 3:
			a1 = 3;
			break;
	}
	C60_Point base(*f10.front());
	C60_Box center(19,43,61,86);
	C60_HEntity begin;
	C60_HEntity areas;
	C60_Record *active;
	C60_Box behaviour(0,0,c60_cfd44c.getWidth() - 1,c60_cfd44c.getHeight() - 1);
	for (int col = 0; col < a1; col++)
	{
		int cols = allies.pick();
		areas.resetField();
		for (unsigned int current = 0; current < adj[cols].size(); current++)
		{
			active = selectRobotOfClass(1,adj[cols][current],current == 0,true);
			if (active != 0)
			{
				begin = placeEntity(active,base,3,false,3,14,false);
				if (begin.isValid())
				{
					if (current == 0)
						areas = begin;
					else if (areas.isValid())
						begin->unknown45b590()->setFollowEntity(areas.ID,0);
					begin->unknown45b590()->unknown459410(center);
					if (type == 1 && areas.isValid())
					{
						vector<C60_Point> distanceSq;
						for (int distances = 0; distances < 2; distances++)
						{
							for (int enemies = 0; enemies < 50; enemies++)
							{
								C60_Point facing = c60_cfd44c.getRandom_9cf050();
								if (!center.contains_40b750(facing) && c60_cefc4c->unknown716940(base,facing,0,0))
								{
									distanceSq.push_back(facing);
									break;
								}
							}
						}
						for (int distances = 0; distances < 50; distances++)
						{
							C60_Point enemies = center.randomPoint_40be90();
							if (c60_cefc4c->unknown716940(base,enemies,0,0))
							{
								distanceSq.push_back(enemies);
								break;
							}
						}
						if (!distanceSq.empty())
						{
							begin->unknown45b590()->unknown4582d0(2);
							begin->unknown45b590()->unknown4593d0(distanceSq);
							begin->unknown45b590()->setField0(0);
						}
					}
				}
			}
		}
	}
}
