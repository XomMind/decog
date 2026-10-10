// op_overmind_respond: Overmind::unknown684250 (0x684250), dispatches an investigation squad to a target
// ("ALERT: Suspicious activity at ...") and returns the number of robots sent (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
	Point() throw();	// 0x453b40
	int randomInRange_40c130();	// NOTE: placeholder name
};
struct OpOR_Area	// NOTE: placeholder name (Rect-like, ctor 0x40b100)
{
	OpOR_Area();
	int x1;
	int y1;
	int x2;
	int y2;
};

class OpOR_AI	// NOTE: placeholder name (EntityAI)
{
public:
	void setFollowEntity(class HEntity e, int flag);	// NOTE: placeholder name (0x5b2f80)
	void unknown459470(OpOR_Area &area);	// NOTE: placeholder name
};
class Entity
{
public:
	const Point &getPosition();	// 0x45a4a0
	OpOR_AI *getAI_45b590();	// NOTE: placeholder name
	void unknown5fdab0();	// NOTE: placeholder name
};
class HEntity
{
public:
	int ID;
	HEntity();	// 0x9b6590
	Entity *operator->() const;	// 0x9b6570
	bool isValid() const;	// 0x9b65e0
	bool isNull() const;	// 0x9b65d0
};
class HProp { public: int ID; HProp(); };

struct EntityRecord	// NOTE: placeholder layout
{
	char pad00[0x28];
	int index;	// +0x28, NOTE: placeholder name
};

struct OpOR_Record	// NOTE: placeholder name (machine record)
{
	string unknown65cc80();	// NOTE: placeholder name
};
class OpOR_Prop	// NOTE: placeholder name (Prop)
{
public:
	OpOR_Record *getRecord_45cb30();	// NOTE: placeholder name (folded getter)
};
class OpOR_HProp	// NOTE: placeholder name (HProp)
{
public:
	int ID;
	bool isValid() const;	// 0x9b65e0
	OpOR_Prop *get22c() const;	// NOTE: placeholder name (0x9b64f0)
};
class Cell
{
public:
	OpOR_HProp getProp45d550();	// 0x45d550
};
class OpOR_Grid	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(const Point &p);	// NOTE: placeholder name
	void getRect(const Point &p, int radius, OpOR_Area &out);	// NOTE: placeholder name (0x9b4430)
};
extern OpOR_Grid opOR_cells_cfd44c;	// NOTE: placeholder name

class OpOR_World	// NOTE: placeholder name (BS at 0xcefc4c)
{
public:
	int unknown4638e0(int a, int b);	// NOTE: placeholder name
	HEntity getPlayer();	// 0x4630f0
	int getTurn();	// 0x464270
	EntityRecord *selectRobotOfClass(int a, int b, bool c, bool d);	// NOTE: placeholder name
	HEntity placeEntity(EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
};
extern OpOR_World *opOR_world;	// NOTE: placeholder name

struct OpOR_MapNode { int pad00; int type; };	// NOTE: placeholder name
class OpOR_Handle	// NOTE: placeholder name
{
public:
	int ID;
	OpOR_MapNode *get23c();	// NOTE: placeholder name
};
extern OpOR_Handle opOR_current_d1e888;	// NOTE: placeholder name

class OpOR_GameData	// NOTE: placeholder name (GameData at 0xd1e860)
{
public:
	int getDepthIndex();	// NOTE: placeholder name (difficulty)
	const string &getEntryText(const string &key);	// NOTE: placeholder name (0x46f6d0)
};
extern OpOR_GameData opOR_gameData;	// NOTE: placeholder name

template <class T> class OpR5h_WL	// NOTE: placeholder name (weighted list)
{
public:
	OpR5h_WL();
	~OpR5h_WL();
	void add(T value, int weight);
	bool pick(T *out);
	char pad[0x24];
};

class Party	// NOTE: placeholder layout
{
public:
	Party(int type, HEntity leader, int a, int b, int c);
	char pad[0x38];
};

class OpOR_MessageLog	// NOTE: placeholder name (0xcf1080)
{
public:
	void setUnknown(int value);	// NOTE: placeholder name (0x451400)
};
extern OpOR_MessageLog opOR_messageLog_cf1080;	// NOTE: placeholder name
class OpOR_ConsoleA	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpOR_ConsoleA *opOR_consoleA_cec058;	// NOTE: placeholder name
class OpOR_LogMsgs	// NOTE: placeholder name (CLogMsgs at 0xcec0b4)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpOR_LogMsgs *opOR_logMsgs_cec0b4;	// NOTE: placeholder name
class OpOR_Console	// NOTE: placeholder name (XConsole at 0xcec0f8)
{
public:
	bool isHidden();	// 0x4175f0
};
extern OpOR_Console *opOR_cec0f8;	// NOTE: placeholder name
class OpOR_Shell	// NOTE: placeholder name (CShell at 0xcec100)
{
public:
	void unknown90ec30(string text);	// NOTE: placeholder name
};
extern OpOR_Shell *opOR_shell_cec100;	// NOTE: placeholder name
extern bool opOR_option_d28fb0;	// NOTE: placeholder name

class OpOR_Stats	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern OpOR_Stats opOR_stats;	// NOTE: placeholder name

extern int opOR_squadWeights_b93688[][2];	// NOTE: placeholder name
extern Point opOR_squadSizes_cf08f8[][2];	// NOTE: placeholder name
extern Point opOR_patrolDelay_d35bc8;	// NOTE: placeholder name
extern string opOR_partyTypeNames_cf25d8[];	// NOTE: placeholder name
extern const char empty_b95725[];	// NOTE: placeholder name ("")
extern const char empty_b95726[];	// NOTE: placeholder name ("")

int stringToInt(const string &s);	// 0x405610
bool opOR_log_5111e0(int id, const string &text, int a, int b, HProp c, HProp d, int e, int f);	// NOTE: placeholder name
void opOR_playSound_4541b0(int id, int a, int b);	// NOTE: placeholder name
void OpV4c_Fn9d0690(int *value, int step, int low);	// NOTE: placeholder name
void opOR_eraseAt_9da940(vector<HEntity> &v, int index);	// NOTE: placeholder name (OpQ5_eraseAt)

#define OPOR_LOG(id,text) do { if (opOR_log_5111e0(id,text,0,0,HProp(),HProp(),0,0)) opOR_consoleA_cec058->unknown8758d0(true); opOR_logMsgs_cec0b4->scrollToEnd(); } while (0)	// NOTE: placeholder macro
#define OPOR_ALERT_EXPR(sound,text) do { opOR_messageLog_cf1080.setUnknown(1); if ((sound) >= 0 && (!opOR_option_d28fb0 || (sound) < 0x127 || (sound) > 0x12a)) opOR_playSound_4541b0(sound,0,0); OPOR_LOG(0x324,text); opOR_logMsgs_cec0b4->scrollToEnd(); } while (0)	// NOTE: placeholder macro (computed sound ids)

class Overmind	// NOTE: placeholder layout
{
public:
	int unknown684250(const Point &target, bool silent);	// NOTE: placeholder name
	bool findDispatchExit(Point *out, bool allowVisible, int minDistance, bool ignoreProps, const Point &from, Point **access, bool preferProps, bool ignoreUsed);	// NOTE: placeholder name
	void unknown683e60(const Point &p, vector<vector<HEntity> > &out);	// NOTE: placeholder name
	bool addParty(Party *party, Point *access);	// NOTE: placeholder name

	char pad00[0x4c];
	int unknown4c;	// NOTE: placeholder name
	char pad50[0x128 - 0x50];
	int failedDispatches;	// +0x128, NOTE: placeholder name
};

int Overmind::unknown684250(const Point &target, bool silent)
{
	if (stringToInt(opOR_gameData.getEntryText("comConduitDisabled_g")) || unknown4c || opOR_world->unknown4638e0(0,3) == 2)
		return 0;
	bool changed = opOR_current_d1e888.get23c()->type == 0x22;
	vector<vector<HEntity> > vec2;
	if (changed)
		unknown683e60(target,vec2);
	OpR5h_WL<int> tags;
	for (int i = 0; i < 2; i++)
		tags.add(i,opOR_squadWeights_b93688[opOR_gameData.getDepthIndex()][i]);
	int tag;
	tags.pick(&tag);
	int value = opOR_squadSizes_cf08f8[opOR_gameData.getDepthIndex()][tag].randomInRange_40c130() - 1;
	EntityRecord *first;
	EntityRecord *element;
	switch (tag)
	{
		case 0:
			first = opOR_world->selectRobotOfClass(1,0x10,false,false);
			element = NULL;
			break;
		case 1:
			first = opOR_world->selectRobotOfClass(1,0x18,false,false);
			element = NULL;
			break;
	}
	if (!first)
		return 0;
	if (!element)
		element = first;
	Point cx;
	Point *to = NULL;
	if (!changed && !findDispatchExit(&cx,false,0,true,opOR_world->getPlayer()->getPosition(),&to,false,false))
	{
		failedDispatches++;
		return 0;
	}
	else
		OpV4c_Fn9d0690(&failedDispatches,1,0);
	int entityCount = 0;
	HEntity r1;
	if (changed)
	{
		if (!vec2[first->index].empty())
		{
			r1 = vec2[first->index][0];
			opOR_eraseAt_9da940(vec2[first->index],0);
			r1->unknown5fdab0();
		}
	}
	else
		r1 = opOR_world->placeEntity(first,cx,3,false,0x22,0xe,false);
	if (r1.isValid())
	{
		entityCount++;
		OpOR_Area area;
		opOR_cells_cfd44c.getRect(target,5,area);
		r1->getAI_45b590()->unknown459470(area);
		while (value)
		{
			HEntity follower;
			if (changed)
			{
				if (!vec2[element->index].empty())
				{
					follower = vec2[element->index][0];
					opOR_eraseAt_9da940(vec2[element->index],0);
					follower->unknown5fdab0();
				}
			}
			else
				follower = opOR_world->placeEntity(element,cx,3,false,0x22,0xe,false);
			if (follower.isNull())
				break;
			follower->getAI_45b590()->setFollowEntity(r1,0);
			value--;
			entityCount++;
		}
		addParty(new Party(4,r1,opOR_world->getTurn() + opOR_patrolDelay_d35bc8.randomInRange_40c130(),0,0),to);
		if (!silent && (*opOR_cells_cfd44c.atPoint(target))->getProp45d550().isValid() && (*opOR_cells_cfd44c.atPoint(target))->getProp45d550().get22c()->getRecord_45cb30())
		{
			string text = "ALERT: Suspicious activity at " + (*opOR_cells_cfd44c.atPoint(target))->getProp45d550().get22c()->getRecord_45cb30()->unknown65cc80() + ". Dispatching " + opOR_partyTypeNames_cf25d8[4] + " squad.";
			OPOR_ALERT_EXPR(opOR_cec0f8->isHidden() ? 0x127 : -1,text);
			if (opOR_shell_cec100)
				opOR_shell_cec100->unknown90ec30(text);
		}
	}
	opOR_stats.add4729d0(0x231,1,empty_b95725,-1);
	opOR_stats.add4729d0(0x232,1,empty_b95726,-1);
	return entityCount;
}
