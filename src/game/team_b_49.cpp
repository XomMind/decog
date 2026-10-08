// team_b_49: CMap ally path preview (0x819a60) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <vector>
using namespace std;
struct Point { int x; int y; };
void OpQ1_lineBresenhamPoints_40ff30(const Point &from, const Point &to, vector<Point> &line);	// NOTE: placeholder name
class TeamB_PathEntity;
class HEntity { public: int ID; TeamB_PathEntity *operator->() const; };
struct TeamB_AllyOrder { int pad; int id; HEntity target; vector<Point> path; };	// NOTE: placeholder layout
class TeamB_PathAI { public: TeamB_AllyOrder *unknown459050(); };	// NOTE: placeholder name (EntityAI)
class TeamB_PathEntity { public: TeamB_PathAI *getAI_45b590(); const Point &getPosition(); };	// NOTE: placeholder name (Entity)
class TeamB_PathWorld { public: int unknown715800(vector<HEntity> *allies); bool unknown4631f0(HEntity e); };	// NOTE: placeholder name (BS)
extern TeamB_PathWorld *teamb_pathWorld_cefc4c;	// NOTE: placeholder name
class TeamB_CMapAllyPaths	// NOTE: placeholder name (CMap)
{
public:
	char pad[0x27c];
	vector<vector<Point> > paths;
	vector<int> ids;
	void buildAllyPaths819a60();
};
void TeamB_CMapAllyPaths::buildAllyPaths819a60()	// 0x819a60
{
	if (!ids.empty())
		return;
	vector<HEntity> allies;
	if (teamb_pathWorld_cefc4c->unknown715800(&allies) != 0)
	{
		for (unsigned int i = 0; i < allies.size(); i++)
		{
			TeamB_AllyOrder *order = allies[i]->getAI_45b590()->unknown459050();
			ids.push_back(order->id);
			paths.push_back(vector<Point>());
			if (order->path.size() == 1 || (order->target.operator->() != NULL && teamb_pathWorld_cefc4c->unknown4631f0(order->target)))
			{
				OpQ1_lineBresenhamPoints_40ff30(allies[i]->getPosition(),order->path.empty() ? order->target->getPosition() : order->path.back(),paths.back());
			}
			else if (order->path.size() > 1)
				paths.back().assign(order->path.begin(),order->path.end());
			else
				paths.back().push_back(allies[i]->getPosition());
		}
	}
}
