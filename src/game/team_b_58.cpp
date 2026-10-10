// team_b_58: Overmind single-unit dispatch toward a point (0x689100) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names (local names follow docs/local-name-buckets.txt).
#include <vector>
using namespace std;
struct Point { int x; int y; Point(); };
struct Pos { int x; int y; Pos(int v); };
class TeamB_DispatchAI { public: void setPath_4593d0(const vector<Point> &path); };	// NOTE: placeholder name (EntityAI)
class TeamB_DispatchEntity { public: const Point &getPosition(); TeamB_DispatchAI *getAI_45b590(); };	// NOTE: placeholder name (Entity)
class HEntity { public: int ID; bool isValid() const; TeamB_DispatchEntity *operator->() const; };
class TeamB_DispatchWorld	// NOTE: placeholder name (BS)
{
public:
	int selectRobotOfClass(int a, int b, int c, int d);	// NOTE: placeholder name
	HEntity placeEntity(int record, const Point &pos, int a, int b, int c, int d, int e);
	bool unknown7168e0(const Point &from, const Point &to, TeamB_DispatchEntity *entity, vector<Point> *path);	// NOTE: placeholder name
};
extern TeamB_DispatchWorld *teamb_dispatchWorld_cefc4c;	// NOTE: placeholder name
class TeamB_Party { public: TeamB_Party(int a, HEntity leader, int b, int c, int d); char pad[0x38]; };	// NOTE: placeholder name (Party)
class TeamB_PartyList { public: void addParty(TeamB_Party *party, int dir); };	// NOTE: placeholder name
extern TeamB_PartyList teamb_parties_cf6428;	// NOTE: placeholder name
class TeamB_Overmind	// NOTE: placeholder name (Overmind)
{
public:
	bool findDispatchExit(Point &out, int a, int b, int c, const Pos &d, int *dir, int e, int f);	// NOTE: placeholder name
	bool dispatch689100(const Point &dest);
};
bool TeamB_Overmind::dispatch689100(const Point &dest)	// 0x689100
{
	int record = teamb_dispatchWorld_cefc4c->selectRobotOfClass(1,0x15,0,0);
	if (record == 0)
		return false;
	Point pos;
	int dir = 0;
	bool ok = findDispatchExit(pos,1,0,1,Pos(-1),&dir,0,0);
	if (ok)
	{
		HEntity e = teamb_dispatchWorld_cefc4c->placeEntity(record,pos,3,0,0x22,0xe,0);
		if (e.isValid())
		{
			vector<Point> path;
			if (teamb_dispatchWorld_cefc4c->unknown7168e0(e->getPosition(),dest,e.operator->(),&path))
			{
				vector<Point> goal(1,dest);
				e->getAI_45b590()->setPath_4593d0(goal);
			}
			teamb_parties_cf6428.addParty(new TeamB_Party(0,e,-1,0,0),dir);
			return true;
		}
	}
	return false;
}
