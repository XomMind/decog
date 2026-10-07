// team_b_18: CMap item drop-on-target (0x8275d0) and target pick (0x827170) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
string intToString(int value);
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);
struct Point { int x; int y; Point(); Point(const Point &p); bool operator==(const Point &p) const; };
struct TeamB_PathStep { Point pos; Point dir; TeamB_PathStep(const Point &pos_, const Point &dir_); };	// NOTE: private element type so the folded vector members pair by address, not by name
class Item { public: int unknown4580c0(); int unknown4580a0(); string unknown571db0(bool a, bool b); };
class HItem { public: int ID; HItem(); Item *operator->() const; };
// NOTE: the exe destroys the item list with the vector destructor at 0x9b7e00 (vector<HExplosive>); same layout as src/op/op_s1d.cpp
class HExplosive { public: int ID; HExplosive(); Item *operator->() const; };
class Entity;
class HEntity { public: int ID; Entity *operator->() const; void clear() throw(); };
class Entity { public: bool unknown5d6c30(vector<HItem> *out); bool unknown5d6a80(vector<HItem> *out, const Point &p, int range); bool unknown5d6610(); };
class HProp { public: int ID; HProp(); };
class BS { public: int unknown716f20(HEntity e, const Point &p); };
extern BS *teamb_world;
extern HEntity teamb_d1da44;	// NOTE: placeholder name (0xd1da44)
extern bool teamb_d28c8a;	// NOTE: placeholder name (0xd28c8a)
void teamb_message7b1750(int type, const string &a, const string &b, const string &c, HEntity entity, HProp prop, int d);	// NOTE: placeholder name (0x7b1750)
void teamb_message7b1750(int type, int a, int b, int c, HEntity entity, HProp prop, int d);	// NOTE: placeholder name (0x7b1750, no-text overload)
extern const bool teamb_stepBlocked_b96384[];	// NOTE: placeholder name
class TeamB_CMap
{
public:
	void warpMouse_806e70(const Point &pos, bool flag);
	bool dropOnTarget8275d0(HEntity target);
	bool unknown805190(Point *out);
	int unknown805360(HEntity entity, void *path, Point *target);
	bool pickTarget827170(HEntity target);
	char pad[0x4c8];
	Point target4c8;
	Point dir4d0;
	bool flag4d8;
	char pad4d9[0x50c - 0x4d9];
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
		target4c8.x = -1;
		teamb_message7b1750(0xae,items.front()->unknown571db0(false,false),intToString(path.size()),intToString(items.front()->unknown4580c0()),target,HProp(),0);
		opR1d_4541b0(0x2d,0,0);
		return true;
	}
	return false;
}

bool TeamB_CMap::pickTarget827170(HEntity target)	// 0x827170
{
	vector<HExplosive> items;
	if (target->unknown5d6a80((vector<HItem>*)&items,target4c8,-1))
	{
		Point pos;
		if (unknown805190(&pos) && target4c8.x != -1)
		{
			if (flag4d8)
			{
				if (!path.empty() && target4c8 == (const Point &)path.back())
					return true;
				if (path.size() == items.front()->unknown4580c0())
					return true;
				else if (unknown805360(target,0,0) > items.front()->unknown4580a0())
					teamb_message7b1750(0xb1,0,0,0,target,HProp(),0);
				else if (!path.empty() && teamb_stepBlocked_b96384[value51c])
					teamb_message7b1750(0xb2,0,0,0,target,HProp(),0);
				else
				{
					value51c = teamb_world->unknown716f20(target,target4c8);
					path.push_back(TeamB_PathStep(target4c8,dir4d0));
					teamb_d1da44.ID = items.front().ID;
					teamb_message7b1750(0xad,items.front()->unknown571db0(false,false),intToString(path.size()),intToString(items.front()->unknown4580c0()),target,HProp(),0);
					opR1d_4541b0(0x2c,0,0);
				}
			}
			else
				teamb_message7b1750(0xb4,0,0,0,target,HProp(),0);
		}
	}
	else if (target->unknown5d6610())
		teamb_message7b1750(0xb1,0,0,0,target,HProp(),0);
	else
		teamb_message7b1750(0xb5,0,0,0,target,HProp(),0);
	return false;
}
