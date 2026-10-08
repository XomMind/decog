// team_b_32: CMap::showHaulerContent timer label (0x8176a0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
string intToString(int value);
bool isOdd_406340(int value);
bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (in range)
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
struct Point { int x; int y; };
struct Pos { int x; int y; Pos(int x_, int y_); };
struct PosB { int x; int y; };	// NOTE: same name as src/game/cc_r2_19.cpp
class XConsole { public: virtual ~XConsole(); void print(int x, int y, const string &text); };
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
struct TeamB_TimerSub { char pad[8]; int value; char padc[0x34 - 0xc]; vector<int> list34; };	// NOTE: placeholder layout
struct TeamB_TimerRecord { char pad[0x38]; TeamB_TimerSub *sub; };	// NOTE: placeholder layout
struct TeamB_TimerData { char pad[0xf8]; int type; };	// NOTE: placeholder layout
class TeamB_TimerProp { public: TeamB_TimerData *getData(); TeamB_TimerRecord *getRecord_45cb30(); };	// NOTE: placeholder name
class TeamB_HTimerProp { public: int ID; TeamB_TimerProp *operator->() const; };	// NOTE: placeholder name (HProp)
class TeamB_TimerCell { public: TeamB_HTimerProp getProp(); };	// NOTE: placeholder name (Cell)
class TeamB_TimerGrid { public: TeamB_TimerCell **atPoint(const Point &p); };	// NOTE: placeholder name
extern TeamB_TimerGrid teamb_timerGrid_cfd44c;	// NOTE: placeholder name
class TeamB_TimerEntity { public: const Point &getPosition(); };	// NOTE: placeholder name
class TeamB_HTimerEntity { public: int ID; TeamB_TimerEntity *operator->() const; };	// NOTE: placeholder name
class TeamB_TimerWorld { public: char pad[0x66c]; TeamB_HTimerEntity player; int getTurn(); };	// NOTE: placeholder name (Map)
extern TeamB_TimerWorld *teamb_timerWorld_cefc4c;	// NOTE: placeholder name
struct TeamB_TimerSource { char pad[0xc]; int turn; };	// NOTE: placeholder layout
extern XConsole *opx5e_cec054;	// NOTE: placeholder name (0xcec054)
extern bool opx5b_asciiEnabled;	// NOTE: placeholder name (0xd28d15)
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
class TeamB_CMapTimer	// NOTE: placeholder name (CMap)
{
public:
	char pad[0x6c];
	Point offset;
	char pad74[0x1d8 - 0x74];
	vector<XTimerI*> labels;
	void removeMarker(const Point &pos);	// NOTE: placeholder name
	void showTimer8176a0(int type, const Point &pos, int turns, TeamB_TimerSource *source);
};
void TeamB_CMapTimer::showTimer8176a0(int type, const Point &pos, int turns, TeamB_TimerSource *source)	// 0x8176a0 (local names follow docs/local-name-buckets.txt)
{
	removeMarker(pos);
	int time;
	if (type >= 1)
		time = turns;
	else if (source != NULL)
		time = source->turn - teamb_timerWorld_cefc4c->getTurn();
	else
	{
		switch ((*teamb_timerGrid_cfd44c.atPoint(pos))->getProp()->getData()->type)
		{
			case 1:
			case 2:
			case 3:
				time = (*teamb_timerGrid_cfd44c.atPoint(pos))->getProp()->getRecord_45cb30()->sub->value;
				break;
			case 5:
				time = !(*teamb_timerGrid_cfd44c.atPoint(pos))->getProp()->getRecord_45cb30()->sub->list34.empty() ? (*teamb_timerGrid_cfd44c.atPoint(pos))->getProp()->getRecord_45cb30()->sub->list34.front() : (*teamb_timerGrid_cfd44c.atPoint(pos))->getProp()->getRecord_45cb30()->sub->value;
				break;
		}
	}
	string line = intToString(time);
	if (type == 5)
		line.insert(0,"T-");
	int w = line.size() + 2;
	int center = w / 2 + (w % 2 != 0);
	int px = teamb_timerWorld_cefc4c->player->getPosition().x;
	bool hidden = !(pos.y == teamb_timerWorld_cefc4c->player->getPosition().y && OpT8b_Fn9daf80(pos.x + 1,teamb_timerWorld_cefc4c->player->getPosition().x,pos.x + center));
	bool added = false;
	if (!hidden && isOdd_406340(w))
	{
		line.insert(0," ");
		added = true;
		w++;
	}
	string tag = "A_CMap_Timer_";
	if (type >= 1)
	{
		switch (type)
		{
			case 1:
				tag += "Explosion";
				break;
			case 2:
				tag += "Explosion";
				break;
			case 3:
				tag += "Hack";
				break;
			case 4:
				tag += "Dismantle";
				break;
			case 5:
				tag += "DeckDrone";
				break;
		}
	}
	else if (source == NULL && (*teamb_timerGrid_cfd44c.atPoint(pos))->getProp()->getData()->type == 5)
	{
		if (!(*teamb_timerGrid_cfd44c.atPoint(pos))->getProp()->getRecord_45cb30()->sub->list34.empty())
			tag += "Transmit";
		else
			tag += "Redeploy";
	}
	else if (time <= 50)
		tag += "50";
	else if (time <= 100)
		tag += "100";
	else if (time <= 150)
		tag += "150";
	else
		tag += "151";
	int num;
	OpU8a_lookup1(tag,&num);
	Pos x2(hidden ? 1 : -(w / 2 + (w % 2 != 0)),0);
	labels.push_back(new XTimerI(0xf,new Console(opx5e_cec054,w,1,pos.x + x2.x + offset.x,pos.y + x2.y + offset.y,opx5b_asciiEnabled != 0,false,-1),true,teamb_tickCount + 1000,(PosB&)x2,HProp().ID,HProp().ID,HProp().ID,(const PosB&)pos));
	labels.back()->console->resetBack_418450();
	labels.back()->console->print(1,0,line);
	if (num == 0)
		return;
	labels.back()->console->unknown48c3c0(num);
	if (added)
	{
		OpU8a_lookup1("CMap_L_Obj_Trans_L",&num);
		labels.back()->console->unknown7ad6a0(num,0x30,0,0,0);
	}
}
