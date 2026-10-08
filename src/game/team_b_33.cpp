// team_b_33: CMap item labels (0x811350, 0x812950) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
bool isOdd_406340(int value);
int opr1c_getScoreTier(int value);
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
struct Point { int x; int y; Point(const Point &p); };
struct Pos { int x; int y; explicit Pos(int v); Pos(int x_, int y_); };
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
class TeamB_LabelItem { public: int getNestedField(); int getMatterType_457880(); int unknown457ca0(); };	// NOTE: placeholder name (Item)
class HItem { public: int ID; HItem(); bool isValid() const; TeamB_LabelItem *operator->() const; };
struct TeamB_LabelItemRecord { char pad[0x10]; int type; char pad14[4]; int rating; };	// NOTE: placeholder layout
struct TeamB_LabelItemType { char pad[0x44]; int matter; char pad48[0x94 - 0x48]; int category; };	// NOTE: placeholder layout
extern vector<TeamB_LabelItemType *> teamb_labelItemTypes_d2d1c4;	// NOTE: placeholder name
template <class T> class TeamB_LabelGrid { public: T *atPoint(const Point &p); };	// NOTE: placeholder name
class TeamB_LabelWorld { public: char pad[0x730]; int list730; char pad734[0x7c4 - 0x734]; TeamB_LabelGrid<TeamB_LabelItemRecord> memory; void unknown9e29b0(int *list, HItem item); bool isVisible(const Point &p); };	// NOTE: placeholder name (BS)
extern TeamB_LabelWorld *teamb_labelWorld_cefc4c;	// NOTE: placeholder name
int teamb_getItemLabel_7ff100(HItem item, TeamB_LabelItemRecord *record, string &out, bool full);	// NOTE: placeholder name
extern string teamb_labelTypes_d38838[];	// NOTE: placeholder name
extern string teamb_tierNames_d221e8[];	// NOTE: placeholder name
extern string teamb_categoryNames_d22138[];	// NOTE: placeholder name
extern string teamb_labelHidden_d1edf4;	// NOTE: placeholder name
extern string teamb_labelTier_d2f484;	// NOTE: placeholder name
extern bool opW5_cfg_d28d3c;	// NOTE: placeholder name
extern bool opw8_d28d26;	// NOTE: placeholder name
extern const bool teamb_labelCentered_bcbe54[];	// NOTE: placeholder name
struct TeamB_LabelOffset { int x; int y; };
extern TeamB_LabelOffset teamb_labelOffsets_cefd20[];	// NOTE: placeholder name
extern XConsole *opx5e_cec054;	// NOTE: placeholder name (0xcec054)
extern bool opx5b_asciiEnabled;	// NOTE: placeholder name (0xd28d15)
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
extern int teamb_noItem_caf164;	// NOTE: placeholder name
class TeamB_CMapItemLabels	// NOTE: placeholder name (CMap)
{
public:
	char pad[0x6c];
	Point offset;
	char pad74[0x1d8 - 0x74];
	vector<XTimerI*> labels;
	void addItemLabel811350(bool timed, const Point &pos, int labelType, HItem item, TeamB_LabelItemRecord *record);
	bool isBlocked_8052f0(const Pos &pos);	// NOTE: placeholder name
	bool addMemoryLabel812950(const Point &pos, int preferred);
};
void TeamB_CMapItemLabels::addItemLabel811350(bool timed, const Point &pos, int labelType, HItem item, TeamB_LabelItemRecord *record)	// 0x811350 (local names follow docs/local-name-buckets.txt)
{
	if (item.isValid())
		teamb_labelWorld_cefc4c->unknown9e29b0(&teamb_labelWorld_cefc4c->list730,item);
	string tag = teamb_labelTypes_d38838[labelType];
	if (opW5_cfg_d28d3c)
	{
		switch (item.isValid() ? item->getMatterType_457880() : teamb_labelItemTypes_d2d1c4[record->type]->matter)
		{
			case 0:
				tag += "Item_Integ_Matter";
				break;
			case 3:
				tag += "Item_Integ_Protomatter";
				if (opw8_d28d26)
					tag += "_CB";
				break;
			default:
				tag += teamb_tierNames_d221e8[opr1c_getScoreTier(item.isValid() ? item->unknown457ca0() : record->rating)];
				break;
		}
		if (!teamb_labelWorld_cefc4c->isVisible(pos))
			tag += teamb_labelHidden_d1edf4;
	}
	else
	{
		int data = teamb_labelWorld_cefc4c->isVisible(pos) ? teamb_labelItemTypes_d2d1c4[item.isValid() ? item->getNestedField() : record->type]->category : 3;
		tag += teamb_categoryNames_d22138[data];
		if (1 && opr1c_getScoreTier(item.isValid() ? item->unknown457ca0() : record->rating) != 3)
			tag += teamb_labelTier_d2f484;
	}
	int rank = 0;
	OpU8a_lookup1(tag,&rank);
	string label;
	int count = teamb_getItemLabel_7ff100(item,record,label,!teamb_labelCentered_bcbe54[labelType]) + 5;
	bool flag = false;
	if ((isOdd_406340(count) && teamb_labelCentered_bcbe54[labelType]) || labelType == 2 || labelType == 3)
	{
		label.insert(0," ");
		flag = true;
		count++;
	}
	Pos pt(teamb_labelOffsets_cefd20[labelType].x - (teamb_labelCentered_bcbe54[labelType] ? count / 2 - 1 : 0),teamb_labelOffsets_cefd20[labelType].y);
	labels.push_back(new XTimerI(6,new Console(opx5e_cec054,count,1,pos.x + pt.x + offset.x,pos.y + pt.y + offset.y,opx5b_asciiEnabled != 0,false,-1),timed,(timed ? 2000 : 20000) + teamb_tickCount,(PosB&)pt,HProp().ID,HProp().ID,item.ID,item.isValid() ? (const PosB&)Pos(-1) : (const PosB&)Point(pos)));
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

bool TeamB_CMapItemLabels::addMemoryLabel812950(const Point &pos, int preferred)	// 0x812950 (local names follow docs/local-name-buckets.txt)
{
	string label;
	if (teamb_labelWorld_cefc4c->memory.atPoint(pos)->type == teamb_noItem_caf164)
		return false;
	int center = (teamb_getItemLabel_7ff100(HItem(),teamb_labelWorld_cefc4c->memory.atPoint(pos),label,true) + 5) / 2;
	int facing = !isBlocked_8052f0(Pos(pos.x + center,pos.y));
	if (facing == preferred)
	{
		if (preferred == 0 && isBlocked_8052f0(Pos(pos.x - center,pos.y)))
			facing = 1;
		else if (preferred == 1 && isBlocked_8052f0(Pos(pos.x + center,pos.y)))
			facing = 0;
		else if (isBlocked_8052f0(Pos(pos.x,pos.y + 1)))
			facing = preferred != 0 ? 5 : 3;
		else
			facing = preferred == 1 ? 4 : 2;
	}
	addItemLabel811350(true,pos,facing,HItem(),teamb_labelWorld_cefc4c->memory.atPoint(pos));
	return true;
}
