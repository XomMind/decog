// team_b_20: CPolymind label refresh (0x87afd0) and CMap labels (0x817390, 0x812b60) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
string intToString(int value);
struct TeamB_PossessRecord { char pad[0x1ac]; string name; };	// NOTE: placeholder layout
struct OpW8_Possession { int index; };	// NOTE: placeholder layout
extern OpW8_Possession *opw8_cf4700;	// NOTE: placeholder name
extern int teamb_cf46f4;	// NOTE: placeholder name
extern vector<TeamB_PossessRecord*> teamb_records_d25de0;	// NOTE: placeholder name
class TeamB_Polymind	// NOTE: placeholder name (CPolymind)
{
public:
	char pad[0x78];
	string name78;
	string text94;
	bool refresh87afd0();
};
bool TeamB_Polymind::refresh87afd0()	// 0x87afd0 (local names follow docs/local-name-buckets.txt)
{
	bool changed = false;
	string label = " ";
	label += opw8_cf4700 == NULL ? string("N/A") : teamb_records_d25de0[opw8_cf4700->index]->name;
	label += " ";
	if (label != name78)
	{
		changed = true;
		name78 = label;
	}
	if (intToString(teamb_cf46f4) != text94)
	{
		changed = true;
		text94 = intToString(teamb_cf46f4);
	}
	return changed;
}

bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
struct Point { int x; int y; Point(int x_, int y_); Point(const Point &p); Point operator+(const Point &p) const; };
struct Pos { int x; int y; explicit Pos(int v); Pos(int x_, int y_); };
struct PosB { int x; int y; };	// NOTE: same name as src/game/cc_r2_19.cpp
class XConsole { public: virtual ~XConsole(); void print(int x, int y, const string &text); };
class Console : public XConsole { public: Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer); void unknown48c3c0(int value); void unknown7ad6a0(int index, int unknown1, int unknown2, int a, int b); void resetBack_418450(); char pad[0x6c - 4]; };
class Entity { public: const Point &getPosition(); int getSize(); };
class HEntity { public: int ID; Entity *operator->() const; };
class TeamB_LabelProp { public: int getType_45c570(); };	// NOTE: placeholder name (Prop)
class HProp { public: int ID; HProp(); bool isValid() const; TeamB_LabelProp *operator->() const; };
struct TeamB_PropType { char pad[0x140]; int category; };	// NOTE: placeholder layout
extern vector<TeamB_PropType*> opX4e_propTypes;	// NOTE: placeholder name (0xcf35b0)
unsigned int opX4e_getPropNameUpper_7ffe10(HProp prop, unsigned int type, string &out);	// NOTE: placeholder name
bool isOdd_406340(int value);
extern string teamb_labelSuffix_d385d4;	// NOTE: placeholder name
extern string teamb_labelCategories_d39298[];	// NOTE: placeholder name
extern string teamb_labelTypes_d38838[];	// NOTE: placeholder name
extern const bool teamb_labelCentered_bcbe54[];	// NOTE: placeholder name
struct TeamB_LabelOffset { int x; int y; };
extern TeamB_LabelOffset teamb_labelOffsets_cefd20[];	// NOTE: placeholder name
class BS { public: bool isVisible(const Point &p); };
extern BS *teamb_world;	// NOTE: placeholder name (0xcefc4c)
class XTimerI	// NOTE: same declaration as src/game/cc_r2_19.cpp
{
public:
	XTimerI(int type_, XConsole *console_, bool c_, int d_, const PosB &e_, int f_, int g_, int h_, const PosB &i_);
	int type;
	Console *console;
	char pad8[0x34 - 8];
};
extern XConsole *opx5e_cec054;	// NOTE: placeholder name (0xcec054)
extern bool opx5b_asciiEnabled;	// NOTE: placeholder name (0xd28d15)
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
extern float teamb_hitChanceBonus_b95a3c;	// NOTE: placeholder name
class TeamB_CMapLabels	// NOTE: placeholder name (CMap)
{
public:
	char pad[0x6c];
	Point offset;
	char pad74[0x1d8 - 0x74];
	vector<XTimerI*> labels;
	void showHitBonus817390(HEntity target);
	void addLabel812b60(bool timed, const Point &pos, int timerType, int labelType, HProp prop, unsigned int propType, bool useSuffix);
};
void TeamB_CMapLabels::showHitBonus817390(HEntity target)	// 0x817390
{
	Point pos = target->getPosition() + offset;
	int anim = 0;
	OpU8a_lookup1("A_CMap_Label_Target_Hit_Chance",&anim);
	string text = "[+" + intToString((int)(teamb_hitChanceBonus_b95a3c * 100.0)) + "%]";
	labels.push_back(new XTimerI(0xd,new Console(opx5e_cec054,text.size(),1,pos.x,pos.y,opx5b_asciiEnabled != 0,false,-1),true,teamb_tickCount + 2000,(PosB&)Point(-1,1),target.ID,HProp().ID,HProp().ID,(PosB&)Point(target->getSize() / 2,target->getSize() - 1)));
	labels.back()->console->print(0,0,text);
	labels.back()->console->unknown48c3c0(anim);
}

void TeamB_CMapLabels::addLabel812b60(bool timed, const Point &pos, int timerType, int labelType, HProp prop, unsigned int propType, bool useSuffix)	// 0x812b60
{
	int data = teamb_world->isVisible(pos) ? opX4e_propTypes[prop.isValid() ? prop->getType_45c570() : propType]->category : 15;
	int rank = 0;
	OpU8a_lookup1(teamb_labelTypes_d38838[labelType] + (useSuffix ? teamb_labelSuffix_d385d4 : teamb_labelCategories_d39298[data]),&rank);
	string label;
	int count = opX4e_getPropNameUpper_7ffe10(prop,propType,label) + 5;
	bool flag = false;
	if ((isOdd_406340(count) && teamb_labelCentered_bcbe54[labelType]) || labelType == 2 || labelType == 3)
	{
		label.insert(0," ");
		flag = true;
		count++;
	}
	Pos pt(teamb_labelOffsets_cefd20[labelType].x - (teamb_labelCentered_bcbe54[labelType] ? count / 2 - 1 : 0),teamb_labelOffsets_cefd20[labelType].y);
	labels.push_back(new XTimerI(timerType,new Console(opx5e_cec054,count,1,pos.x + pt.x + offset.x,pos.y + pt.y + offset.y,opx5b_asciiEnabled != 0,false,-1),timed,(timed ? 2000 : 20000) + teamb_tickCount,(PosB&)pt,HProp().ID,prop.ID,HProp().ID,prop.isValid() ? (const PosB&)Pos(-1) : (const PosB&)Point(pos)));
	labels.back()->console->resetBack_418450();
	labels.back()->console->print(teamb_labelCentered_bcbe54[labelType] ? 1 : 4,0,label);
	if (rank == 0)
		return;
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
}
