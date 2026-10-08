// team_b_44: CMap::createDynamicEntityInfo (0x815800) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
bool isOdd_406340(int value);
void logError(string source, string message);
string intToString(int value);
int stringToInt(const string &text);
int opr1c_getPercentTier(int value, int max);	// NOTE: placeholder name (0x4347e0)
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
	char pad8[0x34 - 8];
};
class HProp { public: int ID; HProp(); };
class TeamB_InfoEntity2 { public: int getField_490840(); const Point &getPosition(); };	// NOTE: placeholder name (Entity)
class HEntity { public: int ID; TeamB_InfoEntity2 *operator->() const; };
class TeamB_InfoCell { public: HEntity getEntity(); };	// NOTE: placeholder name (Cell)
class TeamB_InfoGrid { public: TeamB_InfoCell **atPoint(const Point &p); };	// NOTE: placeholder name
extern TeamB_InfoGrid teamb_infoGrid_cfd44c;	// NOTE: placeholder name
extern string teamb_infoPrefixes_d2f724[];	// NOTE: placeholder name
extern string teamb_infoTiers_d22d28[];	// NOTE: placeholder name
extern string teamb_infoSuffixes_d22d98[];	// NOTE: placeholder name
extern bool teamb_infoNumbers_d28d16;	// NOTE: placeholder name
extern bool teamb_infoHideNumbers_d28e54;	// NOTE: placeholder name
extern const bool teamb_labelCentered_bcbe54[];	// NOTE: placeholder name
struct TeamB_LabelOffset { int x; int y; };
extern TeamB_LabelOffset teamb_labelOffsets_cefd20[];	// NOTE: placeholder name
extern XConsole *opx5e_cec054;	// NOTE: placeholder name (0xcec054)
extern bool opx5b_asciiEnabled;	// NOTE: placeholder name (0xd28d15)
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
class TeamB_CMapDynInfo	// NOTE: placeholder name (CMap)
{
public:
	char pad[0x6c];
	Point offset;
	char pad74[0x1d8 - 0x74];
	vector<XTimerI*> labels;
	void createDynamicEntityInfo815800(const Point &pos, int timerType, int labelType, const string &text, int kind);
};
void TeamB_CMapDynInfo::createDynamicEntityInfo815800(const Point &pos, int timerType, int labelType, const string &text, int kind)	// 0x815800 (local names follow docs/local-name-buckets.txt)
{
	HEntity target = (*teamb_infoGrid_cfd44c.atPoint(pos))->getEntity();
	if (target.operator->() == NULL)
	{
		logError("CMap::createDynamicEntityInfo()","no Ent found at " + OpQ1_pointToString(pos));
		return;
	}
	int rank = 0;
	string label = text;
	switch (timerType)
	{
		case 0xb:
		{
			string value = text;
			value.erase(value.end() - 1);
			int val = opr1c_getPercentTier(stringToInt(value),100);
			OpU8a_lookup1(teamb_infoPrefixes_d2f724[labelType] + teamb_infoTiers_d22d28[val],&rank);
			break;
		}
		case 0xc:
			switch (kind)
			{
				case 0:
				{
					string value = text;
					value.erase(value.end() - 1);
					int level = opr1c_getPercentTier(stringToInt(value),100);
					OpU8a_lookup1(teamb_infoPrefixes_d2f724[labelType] + teamb_infoTiers_d22d28[level],&rank);
					if (teamb_infoNumbers_d28d16 && !teamb_infoHideNumbers_d28e54)
						label = intToString(target->getField_490840());
					break;
				}
				case 1:
					OpU8a_lookup1(teamb_infoPrefixes_d2f724[labelType] + teamb_infoSuffixes_d22d98[0],&rank);
					break;
				case 2:
					OpU8a_lookup1(teamb_infoPrefixes_d2f724[labelType] + teamb_infoSuffixes_d22d98[1],&rank);
					break;
				case 3:
					OpU8a_lookup1(teamb_infoPrefixes_d2f724[labelType] + teamb_infoSuffixes_d22d98[2],&rank);
					break;
				case 4:
					OpU8a_lookup1(teamb_infoPrefixes_d2f724[labelType] + teamb_infoSuffixes_d22d98[3],&rank);
					break;
				case 5:
					OpU8a_lookup1(teamb_infoPrefixes_d2f724[labelType] + teamb_infoSuffixes_d22d98[4],&rank);
					break;
				case 6:
					OpU8a_lookup1(teamb_infoPrefixes_d2f724[labelType] + teamb_infoSuffixes_d22d98[5],&rank);
					break;
			}
			break;
	}
	int count = label.size() + 2;
	bool flag = false;
	if (isOdd_406340(count) && teamb_labelCentered_bcbe54[labelType])
	{
		label.insert(0," ");
		flag = true;
		count++;
	}
	Pos pt(teamb_labelOffsets_cefd20[labelType].x - (teamb_labelCentered_bcbe54[labelType] ? count / 2 - 1 : 0),teamb_labelOffsets_cefd20[labelType].y);
	labels.push_back(new XTimerI(timerType,new Console(opx5e_cec054,count,1,pos.x + pt.x + offset.x,pos.y + pt.y + offset.y,opx5b_asciiEnabled != 0,false,-1),true,teamb_tickCount + 1000,(PosB&)pt,target.ID,HProp().ID,HProp().ID,(const PosB&)pos.sub_409b30(target->getPosition())));
	labels.back()->console->resetBack_418450();
	labels.back()->console->print(1,0,label);
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
