// team_b_08: game-logic helpers (0x500000-0x9affff) matched against COGMIND.exe (Beta 17.1), batch 6.
// NOTE: class layouts are partial; TeamB_* classes and unknownXXXXXX members are placeholder names.
#include <string>
#include <vector>
using namespace std;
int stringToInt(const string &text);
int ops7_clamp_9cdc80(int low, int value, int high);
void OpV4c_Fn9d0690(int *value, int amount, int limit);
void OpV4c_Fn9d06d0(int *value, int amount, int limit);
class OpV1_GameData { public: const string &getEntryText(const string &key); };
extern OpV1_GameData teamb_gameData_d1e860;	// NOTE: placeholder name
struct Point;
class EntityAI;
class Entity { public: int unknown5c7f40(); EntityAI *getAI(); const Point &getPosition(); };
class HEntity { public: int ID; HEntity(); Entity *operator->() const; };
class Map { public: HEntity getPlayer(); };
extern Map *endObjA;
extern const int teamb_maxLevel_b9b9f0[];	// NOTE: placeholder name
extern const float teamb_levelScale_b9b9cc[];	// NOTE: placeholder name
extern const int teamb_hubBonus_b9b988[];	// NOTE: placeholder name
struct TeamB_PropInfo { char pad[0xf8]; int type; char padfc[0x108 - 0xfc]; int values[1]; };
class TeamB_PropBody { public: TeamB_PropInfo *getInfo(); };
class TeamB_HProp { public: int ID; TeamB_PropBody *operator->() const; };
struct TeamB_65cdc0
{
	TeamB_HProp prop;
	char pad4[8];
	int index;
	char pad10[0x28 - 0x10];
	int level;
	int bonus;
	bool disabled;
	int fixed;
	void getValues65cdc0(int *value, int *extra);
};
void TeamB_65cdc0::getValues65cdc0(int *value, int *extra)	// 0x65cdc0
{
	*extra = 0;
	if (index != 0)
	{
		if (disabled)
		{
			*value = -1;
			*extra = fixed;
		}
		else
		{
			int type = prop->getInfo()->type;
			*value = prop->getInfo()->values[index];
			*value = (int)((1 + ops7_clamp_9cdc80(0,level,teamb_maxLevel_b9b9f0[type]) * teamb_levelScale_b9b9cc[type]) * *value);
			OpV4c_Fn9d0690(value,endObjA->getPlayer()->unknown5c7f40() + teamb_hubBonus_b9b988[stringToInt(teamb_gameData_d1e860.getEntryText("hubNetworkHubDisabled_g"))],10);
			OpV4c_Fn9d06d0(value,bonus,100);
		}
	}
	else
		*value = 0;
}

//==================================================================
// random area pick (squad)
//==================================================================

struct Point { int x; int y; Point(); Point &operator=(const Point &p); };
struct TeamB_Rect { int x; int y; int width; int height; TeamB_Rect(); };	// NOTE: Rect (ctor 0x40b100) under a unique name
class EntityAI { public: void unknown5b5220(); void setArea459470(TeamB_Rect *area); };
class BS { public: bool unknown7168e0(const Point &from, const Point &to, Entity *e, vector<Point> &path); };
extern BS *teamb_world;
struct TeamB_CellGrid { void getRandom_9cf0c0(Point *out); void getRect(Point &center, int radius, TeamB_Rect &out); };
extern TeamB_CellGrid teamb_cells_cfd44c;
struct TeamB_673780
{
	int pad0;
	HEntity entity;
	int pad8;
	bool flagC;
	int value10;
	int value14;
	void pickArea673780();
};
void TeamB_673780::pickArea673780()	// 0x673780 (local names chosen for the exe stack layout)
{
	entity->getAI()->unknown5b5220();
	Point target;
	int tryCount = 0;
	vector<Point> tmpPath;
	do
	{
		tryCount++;
		if (tryCount == 200)
		{
			target = entity->getPosition();
			break;
		}
		teamb_cells_cfd44c.getRandom_9cf0c0(&target);
		tmpPath.clear();
	} while (!teamb_world->unknown7168e0(entity->getPosition(),target,entity.operator->(),tmpPath));
	TeamB_Rect bounds;
	teamb_cells_cfd44c.getRect(target,5,bounds);
	entity->getAI()->setArea459470(&bounds);
	flagC = false;
	value10 = 0;
	value14 = -1;
}
