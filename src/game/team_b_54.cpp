// team_b_54: EntityAI target selection (0x580ec0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names (local names follow docs/local-name-buckets.txt).
#include <vector>
using namespace std;
struct Point { int x; int y; };
class TeamB_AiGroup { public: int getType_9b4350(); };	// NOTE: placeholder name
class TeamB_HAiGroup { public: int ID; TeamB_AiGroup *operator->() const; };	// NOTE: placeholder name (HGroup)
class TeamB_AiEntity;
class HEntity { public: int ID; TeamB_AiEntity *operator->() const; };
class TeamB_AiEntity	// NOTE: placeholder name (Entity)
{
public:
	TeamB_HAiGroup getGroup();
	int getFaction();
	const Point &getPosition();
	int unknown5c7d30();	// NOTE: placeholder name
};
struct TeamB_AiTarget { HEntity entity; int pad4; int priority; };	// NOTE: placeholder layout
class TeamB_AiWorld { public: HEntity getPlayer(); bool unknown463400(HEntity e); bool isReachable(int range, const Point &from, const Point &to); };	// NOTE: placeholder name (Map)
extern TeamB_AiWorld *teamb_aiWorld_cefc4c;	// NOTE: placeholder name
extern vector<int> teamb_aiFlags_cf4a04;	// NOTE: placeholder name
class TeamB_EntityAI	// NOTE: placeholder name (EntityAI)
{
public:
	HEntity entity;
	char pad4[0x55 - 4];
	bool checkReach;
	char pad56[0xf0 - 0x56];
	vector<TeamB_AiTarget *> targets;
	bool unknown580ba0(HEntity e);	// NOTE: placeholder name
	TeamB_AiTarget *pickTarget580ec0();
};
TeamB_AiTarget *TeamB_EntityAI::pickTarget580ec0()	// 0x580ec0
{
	bool first = entity->getGroup()->getType_9b4350() <= 1 || unknown580ba0(teamb_aiWorld_cefc4c->getPlayer());
	bool found = first && teamb_aiFlags_cf4a04[0xb] != 0;
	TeamB_AiTarget *best = NULL;
	for (unsigned int i = 0; i < targets.size(); i++)
	{
		if (best == NULL || targets[i]->priority > best->priority)
		{
			if (targets[i]->entity->getFaction() == 0xc)
			{
				if (found && targets[i]->entity->getGroup()->getType_9b4350() == 3)
					continue;
				if (first && !teamb_aiWorld_cefc4c->unknown463400(targets[i]->entity))
					continue;
			}
			if (checkReach && !teamb_aiWorld_cefc4c->isReachable(entity->unknown5c7d30(),entity->getPosition(),targets[i]->entity->getPosition()))
				continue;
			best = targets[i];
		}
	}
	return best;
}
