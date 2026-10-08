// team_b_59: Superfortress wake-up alert (0x68d480) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
struct TeamB_FortressPos { int x; int y; TeamB_FortressPos(int x_, int y_) throw();	/* NOTE: placeholder name (Pos::Pos 0x46ca20; private name keeps the throw() declaration under LTCG) */ };
class HProp { public: int ID; HProp(); };
class TeamB_FortressEntity { public: int getTarget_45a760(); int unknown45acb0(int a); void unknown45b340(TeamB_FortressPos *pos); };	// NOTE: placeholder name (Entity)
class TeamB_HFortress { public: int ID; TeamB_FortressEntity *operator->() const; };	// NOTE: placeholder name (HEntity)
class TeamB_FortressGameData { public: void setEntryText(const string &key, const string &text); };	// NOTE: placeholder name (OpV1_GameData)
extern TeamB_FortressGameData teamb_gameData2_d1e860;	// NOTE: placeholder name
class TeamB_FortressWorld { public: int getTurn() throw(); };	// NOTE: placeholder name (Map)
extern TeamB_FortressWorld *teamb_fortressWorld_cefc4c;	// NOTE: placeholder name
extern vector<int> teamb_fortressList_d2f0f8;	// NOTE: placeholder name
class TeamB_FortressFlag { public: void set_451400(int value); };	// NOTE: placeholder name
extern TeamB_FortressFlag teamb_fortressFlag_cf1080;	// NOTE: placeholder name
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name
bool teamb_logMessage7_5111e0(int id, const string *text, const string *b, int c, HProp d, HProp e, const void *at, int flag);	// NOTE: placeholder name
void teamb_logMessage7_5141b0(int id, const string *a, int b, int c, HProp e, int d);	// NOTE: placeholder name
class TeamB_MsgConsole68d { public: void unknown8758d0(bool flag); };	// NOTE: placeholder name
extern TeamB_MsgConsole68d *teamb_msgConsole68d_cec058;	// NOTE: placeholder name
class TeamB_LogMsgs68d { public: void scrollToEnd(); };	// NOTE: placeholder name (CLogMsgs)
extern TeamB_LogMsgs68d *teamb_logMsgs68d_cec0b4;	// NOTE: placeholder name
class TeamB_FortressPlayerData { public: bool unknown77fbc0(int type); };	// NOTE: placeholder name (PlayerData)
extern TeamB_FortressPlayerData teamb_fortressPlayerData_cf45d8;	// NOTE: placeholder name
class TeamB_FortressWatch	// NOTE: placeholder name
{
public:
	char pad[0x2c];
	TeamB_HFortress fortress;
	void wake68d480();
};
void TeamB_FortressWatch::wake68d480()	// 0x68d480
{
	if (fortress.operator->() != NULL && fortress->getTarget_45a760() == 6 && fortress->unknown45acb0(0) == 0)
	{
		teamb_gameData2_d1e860.setEntryText("frgSuperfortressWoke_g","1");
		fortress->unknown45b340(new TeamB_FortressPos(teamb_fortressList_d2f0f8[0],teamb_fortressWorld_cefc4c->getTurn() + 10));
		do
		{
			teamb_fortressFlag_cf1080.set_451400(1);
			if (0)
				opR1d_4541b0(-1,0,0);
			do
			{
				if (teamb_logMessage7_5111e0(0x324,&string("ALERT: Superfortress powering up for active defense."),0,0,HProp(),HProp(),0,0))
					teamb_msgConsole68d_cec058->unknown8758d0(true);
				teamb_logMsgs68d_cec0b4->scrollToEnd();
			} while (0);
			teamb_logMsgs68d_cec0b4->scrollToEnd();
		} while (0);
		do { teamb_logMessage7_5141b0(0x204,0,0,0,HProp(),0); } while (0);
		teamb_fortressPlayerData_cf45d8.unknown77fbc0(0x1a5);
	}
}
