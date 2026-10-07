// team_b_27: inventory item label (0x8f8ab0) and MapView entity interaction (0x825a60) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
using namespace std;
string intToString(int value);
class TeamB_NameItem	// NOTE: placeholder name (Item)
{
public:
	int getType();	// 0x44aec0
	int unknown457c80();	// NOTE: placeholder name
	int getValue_9b6bf0() const;	// NOTE: placeholder name
	string getName_571db0(int a, int b);	// NOTE: placeholder name
};
class HItem { public: int ID; TeamB_NameItem *operator->() const; };
string teamb_itemName8f8ab0(HItem item)	// 0x8f8ab0
{
	string name = item->getName_571db0(0,0) + " (" + intToString(item->getValue_9b6bf0()) + "/" + intToString(item->unknown457c80()) + ")";
	if (item->getType() == 4)
		name += " [inv]";
	return name;
}

struct Point { int x; int y; };
class HProp { public: int ID; HProp(); };
struct TeamB_HGroup { int ID; };	// NOTE: placeholder name (HGroup)
struct TeamB_EntityRecord { char pad[0x48]; int type; char pad4c[0xac - 0x4c]; int unknownac; };	// NOTE: placeholder layout
class TeamB_Entity;
class HEntity { public: int ID; TeamB_Entity *operator->() const; };
class TeamB_Entity	// NOTE: placeholder name (Entity)
{
public:
	TeamB_EntityRecord *getRecord_44a7f0();	// NOTE: placeholder name
	int getTarget_45a760();	// NOTE: placeholder name
	bool unknown45aaa0(HEntity e);	// NOTE: placeholder name
	int unknown5c7f10();	// NOTE: placeholder name
	const string *getName_416f40();	// NOTE: placeholder name
	void operate_5fdab0();	// NOTE: placeholder name
	void changeFaction_5dc780(TeamB_HGroup group, bool flag);	// NOTE: placeholder name
};
class TeamB_GridCell { public: HEntity getEntity_45d250(); };	// NOTE: placeholder name (Cell)
class TeamB_CellGrid { public: TeamB_GridCell **atPoint(Point &p); };	// NOTE: placeholder name
extern TeamB_CellGrid teamb_cells_cfd44c;	// NOTE: placeholder name
class TeamB_World825 { public: TeamB_HGroup getGroup_463890(int index); void unknown774390(int a, int b); };	// NOTE: placeholder name
extern TeamB_World825 *teamb_world825_cefc4c;	// NOTE: placeholder name
bool teamb_logMessage_5111e0(int id, const string *text, const string *b, int c, HEntity entity, HProp prop, const Point *at, int flag);	// NOTE: placeholder name
void teamb_logMessage_5141b0(int id, const string *a, int b, int c, HProp e, int d);	// NOTE: placeholder name
class TeamB_MsgConsole825 { public: void unknown8758d0(bool flag); };	// NOTE: placeholder name
extern TeamB_MsgConsole825 *teamb_msgConsole825_cec058;	// NOTE: placeholder name
class TeamB_LogMsgs825 { public: void scrollToEnd(); };	// NOTE: placeholder name (CLogMsgs)
extern TeamB_LogMsgs825 *teamb_logMsgs_cec0b4;	// NOTE: placeholder name
class RNG { public: bool chance(int percent); };
extern RNG rng;
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name
class TeamB_Stats825 { public: bool add4729d0(unsigned int id, int value, string text, int extra) throw(); };	// NOTE: placeholder name
extern TeamB_Stats825 teamb_stats825_d2c658;	// NOTE: placeholder name
class TeamB_PlayerData825 { public: bool unknown77fbc0(int type); };	// NOTE: placeholder name
extern TeamB_PlayerData825 teamb_playerData_cf45d8;	// NOTE: placeholder name
extern const bool teamb_table_b95758[];	// NOTE: placeholder name
class TeamB_MapView825	// NOTE: placeholder name (MapView)
{
public:
	void unknown49aee0();	// NOTE: placeholder name
	void unknown49ad30();	// NOTE: placeholder name
	bool interact825a60(HEntity actor, Point &pos, bool check);
};
#define TEAMB_MSG(id,e) do { if (teamb_logMessage_5111e0(id,0,0,0,e,HProp(),0,0)) teamb_msgConsole825_cec058->unknown8758d0(true); teamb_logMsgs_cec0b4->scrollToEnd(); } while (0)
bool TeamB_MapView825::interact825a60(HEntity actor, Point &pos, bool check)	// 0x825a60 (local names follow docs/local-name-buckets.txt)
{
	HEntity target = (*teamb_cells_cfd44c.atPoint(pos))->getEntity_45d250();
	int type = -1;
	if (target->getRecord_44a7f0()->unknownac != 0)
		type = 0x8a;
	else if (target->getTarget_45a760() == 1)
		type = 0x84;
	else if (target->getTarget_45a760() == 2)
		type = 0x85;
	else if (target->getTarget_45a760() == 5)
		type = 0x86;
	else if (target->getTarget_45a760() == 6)
		type = 0x87;
	else if (target->getTarget_45a760() == 7)
		type = 0x88;
	else if (target->getTarget_45a760() == 8)
		type = 0x89;
	if (type != 0 && check)
		return true;
	bool changed = actor->unknown45aaa0(target);
	if (!changed)
		TEAMB_MSG(0x83,target);
	if (type != -1)
		TEAMB_MSG(type,target);
	else if (changed)
	{
		TEAMB_MSG(0x82,target);
		target->operate_5fdab0();
		unknown49aee0();
	}
	else if (rng.chance(actor->unknown5c7f10() / 2 + 10))
	{
		TEAMB_MSG(0x8b,target);
		if (teamb_table_b95758[target->getRecord_44a7f0()->type])
			do { teamb_logMessage_5141b0(0x15,target->getName_416f40(),0,0,HProp(),0); } while (0);
		target->operate_5fdab0();
		target->changeFaction_5dc780(teamb_world825_cefc4c->getGroup_463890(1),true);
		opR1d_4541b0(0x6b,0,0);
		teamb_stats825_d2c658.add4729d0(0x37a,1,"",-1);
		teamb_playerData_cf45d8.unknown77fbc0(0x63);
		unknown49aee0();
	}
	teamb_world825_cefc4c->unknown774390(0xf,-1);
	unknown49ad30();
	return false;
}
