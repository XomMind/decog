// team_b_18: CMap drop-on-target (0x8275d0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
string intToString(int value);
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);
struct Point { int x; int y; Point(const Point &p); };
struct TeamB_PathStep { int x; int y; };	// NOTE: private element type so the folded vector members pair by address, not by name
class Item { public: int unknown4580c0(); string unknown571db0(bool a, bool b); };
class HItem { public: int ID; HItem(); Item *operator->() const; };
// NOTE: the exe destroys the item list with the vector destructor at 0x9b7e00 (vector<HExplosive>); same layout as src/op/op_s1d.cpp
class HExplosive { int ID; public: HExplosive(); Item *operator->() const; };
class Entity;
class HEntity { public: int ID; Entity *operator->() const; void clear() throw(); };
class Entity { public: bool unknown5d6c30(vector<HItem> *out); };
class HProp { public: int ID; HProp(); };
class BS { public: int unknown716f20(HEntity e, const Point &p); };
extern BS *teamb_world;
extern HEntity teamb_d1da44;	// NOTE: placeholder name (0xd1da44)
extern bool teamb_d28c8a;	// NOTE: placeholder name (0xd28c8a)
void teamb_message7b1750(int type, const string &a, const string &b, const string &c, HEntity entity, HProp prop, int d);	// NOTE: placeholder name (0x7b1750)
class TeamB_CMap
{
public:
	void warpMouse_806e70(const Point &pos, bool flag);
	bool dropOnTarget8275d0(HEntity target);
	char pad[0x4c8];
	int value4c8;
	char pad4cc[0x50c - 0x4cc];
	vector<TeamB_PathStep> path;
	int value51c;
};
bool TeamB_CMap::dropOnTarget8275d0(HEntity target)	// 0x8275d0
{
	vector<HExplosive> items;
	if (target->unknown5d6c30((vector<HItem>*)&items) && !path.empty())
	{
		if (teamb_d28c8a)
		{
			Point p((const Point &)path.back());
			warpMouse_806e70(p,true);
		}
		path.pop_back();
		if (!path.empty())
			value51c = teamb_world->unknown716f20(target,(const Point &)path.back());
		else
			teamb_d1da44.clear();
		value4c8 = -1;
		teamb_message7b1750(0xae,items.front()->unknown571db0(false,false),intToString(path.size()),intToString(items.front()->unknown4580c0()),target,HProp(),0);
		opR1d_4541b0(0x2d,0,0);
		return true;
	}
	return false;
}
