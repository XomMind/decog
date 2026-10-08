// team_b_61: BS player 2 spawn (0x6ee930) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names (local names follow docs/local-name-buckets.txt).
#include <string>
#include <vector>
using namespace std;
struct Point { int x; int y; Point(); };
struct TeamB_P2Record;	// NOTE: placeholder name (robot record)
bool teamb_findByName_9d7530(vector<TeamB_P2Record *> &v, const string &name, TeamB_P2Record *&result);	// NOTE: placeholder name (OpQ5_findByName)
extern vector<TeamB_P2Record *> teamb_p2Records_d25de0;	// NOTE: placeholder name
class TeamB_P2Entity;
class HEntity { public: int ID; TeamB_P2Entity *operator->() const; };
class TeamB_P2AI { public: void setFollowEntity(HEntity e, int a); };	// NOTE: placeholder name (EntityAI)
class TeamB_P2Entity { public: void setName_45b070(const string &name); TeamB_P2AI *getAI_45b590(); };	// NOTE: placeholder name (Entity)
struct TeamB_P2Location { char pad[8]; int type; };	// NOTE: placeholder layout
class TeamB_HP2Location { public: int ID; TeamB_P2Location *operator->() const; };	// NOTE: placeholder name
extern TeamB_HP2Location teamb_p2Location_d1e888;	// NOTE: placeholder name
class TeamB_P2Rolled { public: TeamB_P2Rolled();	/* NOTE: placeholder name (OpW5_RolledValues::OpW5_RolledValues) */ char pad[0x2c]; };
extern TeamB_P2Rolled *teamb_p2Rolled_cf46b0;	// NOTE: placeholder name
extern TeamB_P2Rolled *teamb_p2Rolled_cefb48;	// NOTE: placeholder name
extern int opw8_cf462c;	// NOTE: placeholder name (game mode)
class TeamB_P2World	// NOTE: placeholder name (BS)
{
public:
	char pad[8];
	Point start;
	char pad10[0x66c - 0x10];
	HEntity player;
	HEntity player2;
	void unknown6fd920();	// NOTE: placeholder name
	bool findPlaceableNear(const Point &from, Point &out, bool flag);	// NOTE: placeholder name
	HEntity placeEntity(TeamB_P2Record *record, const Point &pos, int a, int b, int c, int d, int e);
	void spawnPlayer2_6ee930();
};
void TeamB_P2World::spawnPlayer2_6ee930()	// 0x6ee930
{
	unknown6fd920();
	if (opw8_cf462c == 7 && teamb_p2Location_d1e888->type == 0xa)
	{
		TeamB_P2Record *record;
		teamb_findByName_9d7530(teamb_p2Records_d25de0,"Player 2",record);
		Point pt;
		if (record != NULL && findPlaceableNear(start,pt,true))
		{
			player2 = placeEntity(record,pt,2,1,0x22,0xe,0);
			player2->setName_45b070(string("Player 2"));
			player2->getAI_45b590()->setFollowEntity(player,0);
		}
		teamb_p2Rolled_cf46b0 = new TeamB_P2Rolled();
		teamb_p2Rolled_cefb48 = teamb_p2Rolled_cf46b0;
	}
}
