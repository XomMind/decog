// team_b_34: CMap::labelEntity (0x80fa60) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
bool isOdd_406340(int value);
void logError(string source, string message);
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
struct Point { int x; int y; Point sub_409b30(const Point &p) const; };	// NOTE: placeholder name (PushCoord::subtract)
string OpQ1_pointToString(const Point &p);
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
	char pad8[0x30 - 8];
	bool unknown30;	// NOTE: placeholder name
	bool remembered31;	// NOTE: placeholder name
	char pad32[0x34 - 0x32];
};
class HProp { public: int ID; HProp(); };
class TeamB_LabelEntity	// NOTE: placeholder name (Entity)
{
public:
	bool unknown5d5250();	// NOTE: placeholder name
	int getTarget_45a760();	// NOTE: placeholder name
	int unknown5ca380();	// NOTE: placeholder name
	int getAiType();
	bool unknown5c7f70();	// NOTE: placeholder name
	int getFaction();
	const Point &getPosition();
};
class HEntity { public: int ID; bool isNull() const; TeamB_LabelEntity *operator->() const; };
class TeamB_EntityCell { public: HEntity getEntity(); };	// NOTE: placeholder name (Cell)
class TeamB_EntityGrid { public: TeamB_EntityCell **atPoint(const Point &p); };	// NOTE: placeholder name
extern TeamB_EntityGrid teamb_entityGrid_cfd44c;	// NOTE: placeholder name
struct TeamB_ScanMemory { char pad[8]; HEntity entity; };	// NOTE: placeholder layout
template <class T> class TeamB_ScanGrid { public: T *atPoint(const Point &p); };	// NOTE: placeholder name
class TeamB_EntityWorld { public: char pad[0x740]; TeamB_ScanGrid<TeamB_ScanMemory> scans; bool unknown4631f0(HEntity e); };	// NOTE: placeholder name (BS)
extern TeamB_EntityWorld *teamb_entityWorld_cefc4c;	// NOTE: placeholder name
int teamb_getEntityLabel_7fea30(HEntity e, bool full, string &out, bool longForm);	// NOTE: placeholder name
extern string teamb_labelTypes_d38838[];	// NOTE: placeholder name
extern string teamb_labelEntityTypes_d38548[];	// NOTE: placeholder name
extern const bool teamb_labelCentered_bcbe54[];	// NOTE: placeholder name
struct TeamB_LabelOffset { int x; int y; };
extern TeamB_LabelOffset teamb_labelOffsets_cefd20[];	// NOTE: placeholder name
extern XConsole *opx5e_cec054;	// NOTE: placeholder name (0xcec054)
extern bool opx5b_asciiEnabled;	// NOTE: placeholder name (0xd28d15)
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
class TeamB_CMapEntityLabels	// NOTE: placeholder name (CMap)
{
public:
	char pad[0x6c];
	Point offset;
	char pad74[0x1d8 - 0x74];
	vector<XTimerI*> labels;
	bool labelEntity80fa60(bool timed, const Point &pos, int timerType, int labelType, bool full, bool scanned);
};
bool TeamB_CMapEntityLabels::labelEntity80fa60(bool timed, const Point &pos, int timerType, int labelType, bool full, bool scanned)	// 0x80fa60 (local names follow docs/local-name-buckets.txt)
{
	HEntity target = (*teamb_entityGrid_cfd44c.atPoint(pos))->getEntity();
	if (target.isNull())
		target = teamb_entityWorld_cefc4c->scans.atPoint(pos)->entity;
	if (target.operator->() == NULL)
	{
		logError("CMap::labelEntity()","no Ent or scan record found at " + OpQ1_pointToString(pos));
		return false;
	}
	bool memory = !teamb_entityWorld_cefc4c->unknown4631f0(target);
	int suffix = scanned ? 5 : (memory ? 6 : ((target->unknown5d5250() || target->getTarget_45a760() == 6) ? 4 : target->unknown5ca380()));
	int rank = 0;
	OpU8a_lookup1(teamb_labelTypes_d38838[labelType] + teamb_labelEntityTypes_d38548[suffix],&rank);
	string label;
	if (target->getAiType() == 0 || target->unknown5c7f70() || target->getFaction() == 0x47 || target->getFaction() == 0x48)
		full = true;
	int count = teamb_getEntityLabel_7fea30(target,full,label,!teamb_labelCentered_bcbe54[labelType]) + 5;
	bool flag = false;
	if ((isOdd_406340(count) && teamb_labelCentered_bcbe54[labelType]) || labelType == 2 || labelType == 3)
	{
		label.insert(0," ");
		flag = true;
		count++;
	}
	Pos pt(teamb_labelOffsets_cefd20[labelType].x - (teamb_labelCentered_bcbe54[labelType] ? count / 2 - 1 : 0),teamb_labelOffsets_cefd20[labelType].y);
	labels.push_back(new XTimerI(timerType,new Console(opx5e_cec054,count,1,pos.x + pt.x + offset.x,pos.y + pt.y + offset.y,opx5b_asciiEnabled != 0,false,-1),timed,(timed ? 2000 : 20000) + teamb_tickCount,(PosB&)pt,target.ID,HProp().ID,HProp().ID,memory ? (const PosB&)Pos(0,0) : (const PosB&)pos.sub_409b30(target->getPosition())));
	labels.back()->remembered31 = memory;
	if (memory)
		labels.back()->unknown30 = false;
	labels.back()->console->resetBack_418450();
	labels.back()->console->print(teamb_labelCentered_bcbe54[labelType] ? 1 : 4,0,label);
	if (rank == 0)
		return true;
	if (teamb_labelCentered_bcbe54[labelType])
	{
		labels.back()->console->unknown7ad6a0(rank,0x31,0,0,0);
		if (flag)
		{
			OpU8a_lookup1("CMap_L_Obj_Trans_L",&rank);
			labels.back()->console->unknown7ad6a0(rank,0x30,0,0,0);
		}
	}
	else
		labels.back()->console->unknown48c3c0(rank);
	return true;
}
