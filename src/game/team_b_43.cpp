// team_b_43: CMap access label (0x80e3a0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
bool isOdd_406340(int value);
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
string OpR5f_toUpper_4083a0(const string &text);	// NOTE: placeholder name
struct Point
{
	int x;
	int y;
	Point();
	void set(int x_, int y_);
	void assign_46ca50(const Point &p);	// NOTE: placeholder name (folded with Point::Point(const Point &))
};
struct Pos { int x; int y; Pos(int x_, int y_); };
struct PosB { int x; int y; };	// NOTE: same name as src/game/cc_r2_19.cpp
class XConsole { public: virtual ~XConsole(); void print(int x, int y, const string &text); bool inBounds(int x, int y); };
class Console : public XConsole { public: Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer); void unknown48c3c0(int value); void unknown7ad6a0(int index, int unknown1, int unknown2, int a, int b); void resetBack_418450(); char pad[0x6c - 4]; };
class XTimerI	// NOTE: same declaration as src/game/cc_r2_19.cpp
{
public:
	XTimerI(int type_, XConsole *console_, bool c_, int d_, const PosB &e_, int f_, int g_, int h_, const PosB &i_);
	int type;
	Console *console;
	char pad8[0x34 - 8];
};
class HProp { public: int ID; HProp(); };
struct TeamB_AccessNodeData { int pad; int type; char pad8[0x25 - 8]; bool known; };	// NOTE: placeholder layout
class TeamB_HAccessNode { public: int ID; TeamB_AccessNodeData *operator->() const; };	// NOTE: placeholder name
struct TeamB_AccessZone { char pad[8]; TeamB_HAccessNode node; char padc[0x1c - 0xc]; int type; };	// NOTE: placeholder layout
class TeamB_AccessWorld { public: bool unknown462ea0(const Point &pos); TeamB_AccessZone *getZone(const Point &pos); };	// NOTE: placeholder name (Map)
extern TeamB_AccessWorld *teamb_accessWorld_cefc4c;	// NOTE: placeholder name
class TeamB_AccessCell { public: bool isEdge(); bool isShortcut(); };	// NOTE: placeholder name (Cell)
class TeamB_AccessGrid { public: TeamB_AccessCell **atPoint(const Point &p); };	// NOTE: placeholder name
extern TeamB_AccessGrid teamb_accessGrid_cfd44c;	// NOTE: placeholder name
class TeamB_AccessMark { public: void resetField_9b7270(); };	// NOTE: placeholder name
extern int opw8_cf462c;	// NOTE: placeholder name (game mode)
extern int teamb_difficulty_cf4718;	// NOTE: placeholder name (0xcf4718)
extern string gameString_cfe110;	// "Final Abomination's Lair" (src/game/global_strings.cpp)
extern string teamb_locationNames_cfaca0[];	// NOTE: placeholder name
extern const bool teamb_lockedBranch_ba6650[][3];	// NOTE: placeholder name
extern XConsole *opx5e_cec054;	// NOTE: placeholder name (0xcec054)
extern bool opx5b_asciiEnabled;	// NOTE: placeholder name (0xd28d15)
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
class TeamB_CMapAccess : public XConsole	// NOTE: placeholder name (CMap)
{
public:
	char pad04[0x6c - 4];
	Point offset;
	char pad74[0x1d8 - 0x74];
	vector<XTimerI*> labels;
	char pad1e8[0x208 - 0x1e8];
	Point lastAccess;
	TeamB_AccessMark mark;
	bool isBlocked_8052f0(const Point &pos);	// NOTE: placeholder name
	void labelAccess80e3a0(bool timed, const Point &pos);
};
void TeamB_CMapAccess::labelAccess80e3a0(bool timed, const Point &pos)	// 0x80e3a0 (local names follow docs/local-name-buckets.txt)
{
	string label;
	if ((*teamb_accessGrid_cfd44c.atPoint(pos))->isEdge())
		label = (*teamb_accessGrid_cfd44c.atPoint(pos))->isShortcut() ? "HIDDEN DOOR" : "PHASE WALL";
	else if (teamb_accessWorld_cefc4c->unknown462ea0(pos))
	{
		TeamB_AccessZone *zone = teamb_accessWorld_cefc4c->getZone(pos);
		switch (zone->type)
		{
			case 2:
				label = "SEALED ACCESS";
				break;
			case 3:
				label = "RESTRICTED ACCESS";
				break;
			case 4:
				label = "BLOCKED ACCESS";
				break;
			default:
			{
				TeamB_HAccessNode node = zone->node;
				if (opw8_cf462c == 4 && node->type == 0x24)
					label = gameString_cfe110;
				else
				{
					label = node->known ? OpR5f_toUpper_4083a0(teamb_locationNames_cfaca0[node->type]) : string("???");
					if (teamb_lockedBranch_ba6650[node->type][teamb_difficulty_cf4718])
					{
						label.insert(0,"LOCKED BRANCH (");
						label += ")";
					}
				}
				break;
			}
		}
	}
	else
		return;
	lastAccess.assign_46ca50(pos);
	mark.resetField_9b7270();
	Pos pt(pos.x + offset.x - 1,pos.y + offset.y - 1);
	int w = label.size() + 9;
	bool right = !isBlocked_8052f0(pos) || inBounds(w / 2 + pt.x,pt.y);
	bool first = isOdd_406340(label.size());
	Point ox;
	if (right)
		ox.set(-1,-1);
	else
	{
		ox.set(-3 - label.size() / 2,-1);
		pt.x = pos.x + offset.x + ox.x;
		if (first)
			w--;
	}
	int val = 0;
	OpU8a_lookup1(right ? "A_CMap_Label_Access_R" : "A_CMap_Label_Access_L",&val);
	labels.push_back(new XTimerI(7,new Console(opx5e_cec054,w,3,pt.x,pt.y,opx5b_asciiEnabled != 0,false,-1),timed,(timed ? 2000 : 20000) + teamb_tickCount,(PosB&)ox,HProp().ID,HProp().ID,HProp().ID,(const PosB&)pos));
	labels.back()->console->resetBack_418450();
	int x = right ? 8 : (first ? 1 : 2);
	labels.back()->console->print(x,0,label);
	if (val == 0)
		return;
	if (right)
		labels.back()->console->unknown48c3c0(val);
	else
	{
		labels.back()->console->unknown7ad6a0(val,0x31,0,0,0);
		if (!first)
		{
			OpU8a_lookup1("CMap_L_Access_Trans_L",&val);
			labels.back()->console->unknown7ad6a0(val,0x30,0,0,0);
		}
	}
	if (teamb_accessWorld_cefc4c->unknown462ea0(pos))
	{
		int off = 0;
		OpU8a_lookup1("A_CMap_Label_Access_Off",&off);
		labels.push_back(new XTimerI(8,new Console(opx5e_cec054,label.size() + 2,1,0,-1,opx5b_asciiEnabled != 0,false,-1),timed,(timed ? 2000 : 20000) + teamb_tickCount,(const PosB&)Pos(0,0),HProp().ID,HProp().ID,HProp().ID,(const PosB&)pos));
		labels.back()->console->resetBack_418450();
		labels.back()->console->print(1,0,label);
		labels.back()->console->unknown48c3c0(off);
	}
}
