// team_b_60: BS initialization helper for faction AI and the Exiles dialogue (0x6e9270) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
struct Point { int x; int y; };
class HEntity;
class TeamB_InitAIState { public: TeamB_InitAIState(HEntity entity, int type, int b);	/* NOTE: placeholder name (0x57f6a0) */ char pad[0x130]; };
class TeamB_InitEntity { public: int getFaction(); const Point &getPosition(); void setAI(TeamB_InitAIState *ai); };	// NOTE: placeholder name (Entity)
class HEntity { public: int ID; TeamB_InitEntity *operator->() const; };
struct TeamB_InitRecord { int type; HEntity entity; };	// NOTE: placeholder layout
extern vector<TeamB_InitRecord *> teamb_initRecords_cf6478;	// NOTE: placeholder name
class TeamB_InitGroup { public: vector<HEntity> *getMembers_416f40(); };	// NOTE: placeholder name
class TeamB_HInitGroup { public: int ID; TeamB_InitGroup *operator->() const; };	// NOTE: placeholder name (HGroup)
extern int opw8_cf462c;	// NOTE: placeholder name (game mode)
class TeamB_InitWorld	// NOTE: placeholder name (BS)
{
public:
	char pad[0x4c];
	vector<TeamB_HInitGroup> groups;
	void unknown6c65a0(HEntity e, const string &dialogue, int a);	// NOTE: placeholder name
	void init6e9270();
};
void TeamB_InitWorld::init6e9270()	// 0x6e9270
{
	for (unsigned int i = 0; i < teamb_initRecords_cf6478.size(); i++)
	{
		if (teamb_initRecords_cf6478[i]->type == 1 && teamb_initRecords_cf6478[i]->entity->getFaction() == 0xc)
			teamb_initRecords_cf6478[i]->entity->setAI(new TeamB_InitAIState(teamb_initRecords_cf6478[i]->entity,3,0xe));
	}
	if (opw8_cf462c == 8)
	{
		vector<HEntity> &members = *groups[9]->getMembers_416f40();
		if (members.empty())
			return;
		HEntity e = members[0];
		for (unsigned int j = 1; j < members.size(); j++)
		{
			if (members[j]->getPosition().x < e->getPosition().x)
				e = members[j];
		}
		unknown6c65a0(e,"FL_Dialogue_EXT",0);
	}
}
