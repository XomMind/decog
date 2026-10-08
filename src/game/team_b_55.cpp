// team_b_55: EntityAI patrol spot selection (0x5b6850) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names (local names follow docs/local-name-buckets.txt).
#include <vector>
using namespace std;
struct Point { int x; int y; void assign_46ca50(const Point &p);	/* NOTE: placeholder name (folded with Point::Point(const Point &)) */ };
struct TeamB_PatrolArea { Point min; Point max; };	// NOTE: placeholder name (Area)
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name
template <class T> void OpV4c_shuffle(vector<T> &v);	// NOTE: placeholder name (0x9d7350)
class TeamB_PatrolAIState { public: TeamB_PatrolAIState(class HEntity entity, int type, int b);	/* NOTE: placeholder name (0x57f6a0) */ char pad[0x130]; };
class TeamB_PatrolEntity;
class HEntity { public: int ID; TeamB_PatrolEntity *operator->() const; };
class TeamB_PatrolEntity { public: const Point &getPosition(); void setAI(TeamB_PatrolAIState *ai); };	// NOTE: placeholder name (Entity)
struct TeamB_PatrolTarget { HEntity entity; };	// NOTE: placeholder layout
class TeamB_PatrolWorld { public: vector<vector<Point> > *unknown459070(); };	// NOTE: placeholder name (Map)
extern TeamB_PatrolWorld *teamb_patrolWorld_cefc4c;	// NOTE: placeholder name
class TeamB_PatrolGrid { public: void getRect(const Point &p, int radius, TeamB_PatrolArea &out); };	// NOTE: placeholder name (OpR5h_Grid)
extern TeamB_PatrolGrid teamb_patrolGrid_cfd44c;	// NOTE: placeholder name
class TeamB_PatrolAI	// NOTE: placeholder name (EntityAI)
{
public:
	HEntity entity;
	char pad4[0x80 - 4];
	TeamB_PatrolArea area;
	char pad90[0xf0 - 0x90];
	vector<TeamB_PatrolTarget *> targets;
	bool findPatrolSpot5b6850(Point &out);
};
bool TeamB_PatrolAI::findPatrolSpot5b6850(Point &out)	// 0x5b6850
{
	vector<Point> &kind = (*teamb_patrolWorld_cefc4c->unknown459070())[5];
	if (kind.empty())
	{
fail:
		do {} while (0);
		entity->setAI(new TeamB_PatrolAIState(entity,0x17,4));
		return false;
	}
	else
	{
		int radius = 10;
		int limit = 20;
		vector<Point> items = kind;
		OpV4c_shuffle(items);
		bool flag = false;
		for (unsigned int i = 0; i < items.size(); i++)
		{
			for (unsigned int j = 0; j < targets.size(); j++)
			{
				if (OpQ1_distanceCeil_40a3f0(items[i],targets[j]->entity->getPosition()) <= limit)
					goto next;
			}
			teamb_patrolGrid_cfd44c.getRect(items[i],radius,area);
			out.assign_46ca50(items[i]);
			flag = true;
			break;
	next:
			;
		}
		if (!flag)
			goto fail;
		else
			return true;
	}
}
