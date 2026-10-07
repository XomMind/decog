// team_b_21: "DECIDE" choice callback (0x8f8340) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names; local names follow docs/local-name-buckets.txt.
#include <string>
#include <vector>
using namespace std;
void logError(string location, string message);
string intToString(int value);
class HProp { public: int ID; HProp(); };
class HEntity;
struct OpS1c_Inventory;
class Entity { public: OpS1c_Inventory *getInventory(); };
class HEntity { public: int ID; Entity *operator->() const; };
bool OpS1c_unknown4569a0(int a, int b, int c, int d, int e, int f, int g, OpS1c_Inventory *inv, int h, int i, int j, int k);
bool opU5_logMessage(int id, const string &text, const string *b, int c, HProp d, HProp e, const struct Point *at, int flag);	// NOTE: placeholder name (0x5111e0)
class OpV1_GameData { public: void setEntryText(const string &key, const string &value); };
extern OpV1_GameData teamb_gameData_d1e860;	// NOTE: placeholder name
class TeamB_ListConsole { public: void unknown7b2870(); };
extern TeamB_ListConsole *opr5c_activeList;	// NOTE: placeholder name (0xcec130)
class TeamB_MsgConsole { public: void unknown8758d0(bool flag); };
extern TeamB_MsgConsole *teamb_msgConsole_cec058;	// NOTE: placeholder name
class CLogMsgs { public: void scrollToEnd(); };
extern CLogMsgs *opr5c_logMsgs;	// NOTE: placeholder name (0xcec0b4)
extern vector<string> teamb_decideOptions_d22300;	// NOTE: placeholder name
extern HEntity teamb_decideEntity_d35bb8;	// NOTE: placeholder name
void teamb_decideCallback8f8340(int index, const string &option)	// NOTE: placeholder name (0x8f8340)
{
	int found = -1;
	for (unsigned int i = 0; i < teamb_decideOptions_d22300.size(); i++)
	{
		if (option == teamb_decideOptions_d22300[i])
		{
			found = i;
			break;
		}
	}
	string str = option;
	opr5c_activeList->unknown7b2870();
	if (found == -1)
	{
		logError("playerDecideDone()","No matching decision found for \"" + str + "\"");
		return;
	}
	teamb_gameData_d1e860.setEntryText("decisionIndex_g",intToString(found));
	string message = "[Decision: " + str + "]";
	do
	{
		if (opU5_logMessage(0x322,message,0,0,HProp(),HProp(),0,0))
			teamb_msgConsole_cec058->unknown8758d0(true);
		opr5c_logMsgs->scrollToEnd();
	} while (0);
	OpS1c_unknown4569a0(0x3b,teamb_decideEntity_d35bb8.ID,HProp().ID,HProp().ID,HProp().ID,0,0,teamb_decideEntity_d35bb8->getInventory(),teamb_decideEntity_d35bb8.ID,HProp().ID,HProp().ID,0);
}
