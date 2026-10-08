// team_b_42: MapView machine-area move confirmation (0x805520) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
string intToString(int value);
string opw8_countString(int count, const string &noun);	// NOTE: placeholder name (0x407a80)
struct Point
{
	int x;
	int y;
	bool equals_409b90(const Point &p) const;	// NOTE: placeholder name
	bool differs_409bd0(const Point &p) const;	// NOTE: placeholder name
	void assign_46ca50(const Point &p);	// NOTE: placeholder name (folded with Point::Point(const Point &))
};
class HProp { public: int ID; HProp(); };
class TeamB_MoveAI { public: bool unknown4590b0(int type); };	// NOTE: placeholder name (EntityAI)
class TeamB_MoveItem { public: bool unknown457db0(); };	// NOTE: placeholder name (Item)
class TeamB_HMoveItem { public: int ID; TeamB_MoveItem *operator->() const; };	// NOTE: placeholder name (HItem)
class TeamB_MoveEntity;
class HEntity { public: int ID; HEntity(); bool isValid() const; bool operator!=(HEntity other) const; TeamB_MoveEntity *operator->() const; };
class TeamB_MoveEntity	// NOTE: placeholder name (Entity)
{
public:
	bool unknown5c83d0(const Point &pos, int range);	// NOTE: placeholder name
	bool unknown5d1280(int a);	// NOTE: placeholder name
	int getTarget_45a760();	// NOTE: placeholder name
	TeamB_MoveAI *getAI_45b590();	// NOTE: placeholder name
	int getFaction();
	string &getName_416f40();	// NOTE: placeholder name
	vector<TeamB_HMoveItem> *getInventoryList();
};
class TeamB_MoveGroup { public: bool unknown45e360(); vector<HEntity> *getMembers_416f40(); };	// NOTE: placeholder name
class TeamB_HMoveGroup { public: int ID; TeamB_MoveGroup *operator->() const; };	// NOTE: placeholder name
struct TeamB_MoveNodeData { char pad[0x25]; bool known; };	// NOTE: placeholder layout
class TeamB_HMoveNode { public: int ID; TeamB_MoveNodeData *operator->() const; };	// NOTE: placeholder name
struct TeamB_MoveExit { Point pos; TeamB_HMoveNode node; };	// NOTE: placeholder layout
class TeamB_MoveWorld	// NOTE: placeholder name (Map)
{
public:
	char pad[0x10];
	vector<TeamB_MoveExit *> exits;
	char pad20[0x66c - 0x20];
	HEntity player;
	bool unknown715a70();	// NOTE: placeholder name
	TeamB_HMoveGroup getGroup_463890(int index);	// NOTE: placeholder name
	HEntity getPlayer();
};
extern TeamB_MoveWorld *teamb_moveWorld_cefc4c;	// NOTE: placeholder name
class TeamB_MoveCell { public: bool isMachinePart(); };	// NOTE: placeholder name (Cell)
class TeamB_MoveGrid { public: TeamB_MoveCell **atPoint(const Point &p); };	// NOTE: placeholder name
extern TeamB_MoveGrid teamb_moveGrid_cfd44c;	// NOTE: placeholder name
struct TeamB_MoveLocation { int pad; int type; };	// NOTE: placeholder layout
class TeamB_HMoveLocation { public: int ID; TeamB_MoveLocation *operator->() const; };	// NOTE: placeholder name
extern TeamB_HMoveLocation teamb_moveLocation_d1e888;	// NOTE: placeholder name
class TeamB_MoveGameData { public: int getDepthChange(TeamB_HMoveNode node, bool update); };	// NOTE: placeholder name (GameData)
extern TeamB_MoveGameData teamb_gameData_d1e860;	// NOTE: placeholder name
class OpS2_PhraseTextA	// NOTE: same declaration as src/op (0x510d20)
{
public:
	OpS2_PhraseTextA(int index, string *a, string *b, string *c, HEntity d, HEntity e);	// 0x510d20
	char pad[0x20];
};
class TeamB_MoveMsg { public: void add(OpS2_PhraseTextA *msg); };	// NOTE: placeholder name (CInterfaceMsg)
extern TeamB_MoveMsg *teamb_moveMsg_cec0f4;	// NOTE: placeholder name
void teamb_msg805_7b1750(int type, const string &a, const string *b, const string *c, HProp e, HProp p, int d);	// NOTE: placeholder name (0x7b1750)
extern int opw8_cf462c;	// NOTE: placeholder name (game mode)
extern bool teamb_confirmCorrupt_d28fa1;	// NOTE: placeholder name
extern bool teamb_confirmSkip_d28fa2;	// NOTE: placeholder name
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
class TeamB_MoveView	// NOTE: placeholder name (MapView)
{
public:
	char pad[0x578];
	Point lastPos;
	unsigned int shownTime;
	unsigned int repeatTime;
	unsigned int corruptTime;
	void unknown49ad30();	// NOTE: placeholder name
	bool confirmMove805520(const Point &pos);
};
bool TeamB_MoveView::confirmMove805520(const Point &pos)	// 0x805520 (local names follow docs/local-name-buckets.txt)
{
	if ((*teamb_moveGrid_cfd44c.atPoint(pos))->isMachinePart() && teamb_moveLocation_d1e888->type != 1)
	{
		int allies = 0;
		HEntity target;
		if (teamb_moveWorld_cefc4c->unknown715a70())
		{
			for (int g = 0; g < 15; g++)
			{
				if (teamb_moveWorld_cefc4c->getGroup_463890(g)->unknown45e360())
				{
					vector<HEntity> &members = *teamb_moveWorld_cefc4c->getGroup_463890(g)->getMembers_416f40();
					for (unsigned int m = 0; m < members.size(); m++)
					{
						if (members[m] != teamb_moveWorld_cefc4c->getPlayer() && !members[m]->unknown5c83d0(pos,7) && !members[m]->unknown5d1280(0) && members[m]->getTarget_45a760() < 6 && !members[m]->getAI_45b590()->unknown4590b0(0x42) && !members[m]->getAI_45b590()->unknown4590b0(0x43) && !members[m]->getAI_45b590()->unknown4590b0(0x44))
						{
							allies++;
							if (opw8_cf462c == 7 && members[m]->getFaction() == 0x49)
								target = members[m];
						}
					}
				}
			}
		}
		if (target.isValid())
		{
			teamb_msg805_7b1750(0x95,target->getName_416f40(),0,0,HProp(),HProp(),0);
			unknown49ad30();
			return true;
		}
		if (teamb_confirmCorrupt_d28fa1)
		{
			int corrupted = 0;
			for (unsigned int e = 0; e < teamb_moveWorld_cefc4c->exits.size(); e++)
			{
				if (teamb_moveWorld_cefc4c->exits[e]->pos.equals_409b90(pos))
				{
					if (!teamb_moveWorld_cefc4c->exits[e]->node->known || teamb_gameData_d1e860.getDepthChange(teamb_moveWorld_cefc4c->exits[e]->node,false) != 0)
					{
						vector<TeamB_HMoveItem> *inv = teamb_moveWorld_cefc4c->player->getInventoryList();
						for (unsigned int k = 0; k < inv->size(); k++)
						{
							if ((*inv)[k]->unknown457db0())
								corrupted++;
						}
					}
					break;
				}
			}
			if (corrupted != 0 && teamb_tickCount >= corruptTime + 5000)
			{
				corruptTime = teamb_tickCount;
				string text = opw8_countString(corrupted,"corrupted part");
				teamb_msg805_7b1750(0x94,text,0,0,HProp(),HProp(),0);
				unknown49ad30();
				return true;
			}
		}
		if (lastPos.differs_409bd0(pos))
		{
show:
			lastPos.assign_46ca50(pos);
			shownTime = teamb_tickCount;
			repeatTime = teamb_tickCount;
			if (allies != 0)
				teamb_msg805_7b1750(0x93,allies > 1 ? intToString(allies) + " allies" : string("1 ally"),0,0,HProp(),HProp(),0);
			else
			{
				if (teamb_confirmSkip_d28fa2)
					return false;
				teamb_moveMsg_cec0f4->add(new OpS2_PhraseTextA(0x92,0,0,0,HEntity(),HEntity()));
			}
			unknown49ad30();
			return true;
		}
		else if (teamb_tickCount < shownTime + (allies != 0 ? 1000 : 500))
			return true;
		else if (teamb_tickCount > repeatTime + 3000)
			goto show;
		repeatTime = teamb_tickCount;
	}
	return false;
}
