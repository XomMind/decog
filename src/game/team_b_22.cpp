// team_b_22: CMapFine reset/clear (0x873fd0, 0x874340) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; TeamB_MapFine stands for CMapFine (object at 0xcec058).
#include <vector>
using namespace std;
template <class T> void OpQ5_clearObjects(vector<T*> &v);
struct OpQ5_T9ef560;
struct OpQ5_T9edaa0;
class TeamB_FineBubble { public: ~TeamB_FineBubble(); };	// NOTE: placeholder name (OpW5_FineBubble, ??_G 0x49c5e0)
class XConsole { public: virtual ~XConsole(); void removeSubconsole(XConsole *console); };
class CLogMsgs { public: void clearLines(); void scrollToEnd(); };
extern CLogMsgs *teamb_logMsgs_cec0c4;	// NOTE: placeholder name
class CPay2Buy : public XConsole { public: CPay2Buy(XConsole *parent); char pad[0x78 - 4]; };
class CRpglikeFull : public XConsole { public: CRpglikeFull(XConsole *parent); char pad[0x78 - 4]; };
class CPlayer2 : public XConsole { public: CPlayer2(XConsole *parent); void toggleInfo(); char pad[0xac - 4]; };
class CPolymind : public XConsole { public: CPolymind(XConsole *parent); void toggleInfo(); char pad[0xb0 - 4]; };
class HEntity { public: int ID; HEntity(); bool isValid() const; };
class BS { public: HEntity getEntity671(); };
extern BS *teamb_world;	// NOTE: placeholder name (0xcefc4c)
extern XConsole *teamb_cec034;	// NOTE: placeholder name (0xcec034)
extern XConsole *teamb_pay2buy_cec05c;	// NOTE: placeholder name
extern XConsole *teamb_rpglike_cec060;	// NOTE: placeholder name
extern XConsole *teamb_cec064;	// NOTE: placeholder name
extern XConsole *teamb_player2_cec068;	// NOTE: placeholder name
extern XConsole *teamb_polymind_cec06c;	// NOTE: placeholder name
extern int opw8_cf462c;	// NOTE: placeholder name (game mode)
extern bool teamb_cefc71;	// NOTE: placeholder name
extern bool teamb_cefc72;	// NOTE: placeholder name
class TeamB_MapFine : public XConsole	// NOTE: placeholder name (CMapFine, object at 0xcec058)
{
public:
	char pad[0x6c - 4];
	vector<OpQ5_T9ef560*> messages;
	vector<OpQ5_T9edaa0*> bubbles0;
	TeamB_FineBubble *current0;
	vector<OpQ5_T9edaa0*> bubbles1;
	TeamB_FineBubble *current1;
	vector<OpQ5_T9edaa0*> bubbles2;
	TeamB_FineBubble *current2;
	vector<OpQ5_T9edaa0*> timers;
	vector<XConsole*> unknownc8;
	unsigned int textTime;
	XConsole *textConsole;
	void reset873fd0();
	void clear874340();
};
void TeamB_MapFine::reset873fd0()	// 0x873fd0
{
	OpQ5_clearObjects(messages);
	OpQ5_clearObjects(bubbles0);
	delete current0;
	current0 = NULL;
	OpQ5_clearObjects(bubbles1);
	delete current1;
	current1 = NULL;
	OpQ5_clearObjects(bubbles2);
	delete current2;
	current2 = NULL;
	OpQ5_clearObjects(timers);
	unknownc8.clear();
	textTime = 0;
	textConsole = NULL;
	teamb_pay2buy_cec05c = NULL;
	teamb_rpglike_cec060 = NULL;
	teamb_cec064 = NULL;
	teamb_player2_cec068 = NULL;
	teamb_polymind_cec06c = NULL;
	switch (opw8_cf462c)
	{
	case 2:
		teamb_pay2buy_cec05c = new CPay2Buy(teamb_cec034);
		break;
	case 5:
		teamb_rpglike_cec060 = new CRpglikeFull(teamb_cec034);
		break;
	case 7:
		if (teamb_world->getEntity671().isValid())
		{
			teamb_player2_cec068 = new CPlayer2(teamb_cec034);
			if (teamb_cefc71)
				((CPlayer2*)teamb_player2_cec068)->toggleInfo();
		}
		break;
	case 11:
		teamb_polymind_cec06c = new CPolymind(teamb_cec034);
		if (teamb_cefc72)
			((CPolymind*)teamb_polymind_cec06c)->toggleInfo();
		break;
	}
}

void TeamB_MapFine::clear874340()	// 0x874340
{
	OpQ5_clearObjects(messages);
	OpQ5_clearObjects(bubbles0);
	delete current0;
	current0 = NULL;
	OpQ5_clearObjects(bubbles1);
	delete current1;
	current1 = NULL;
	OpQ5_clearObjects(bubbles2);
	delete current2;
	current2 = NULL;
	teamb_logMsgs_cec0c4->clearLines();
	teamb_logMsgs_cec0c4->scrollToEnd();
	OpQ5_clearObjects(timers);
	for (unsigned int i = 0; i < unknownc8.size(); i++)
	{
		if (unknownc8[i])
			removeSubconsole(unknownc8[i]);
	}
	unknownc8.clear();
	if (textConsole)
	{
		removeSubconsole(textConsole);
		textConsole = NULL;
	}
	if (teamb_pay2buy_cec05c)
	{
		teamb_cec034->removeSubconsole(teamb_pay2buy_cec05c);
		teamb_pay2buy_cec05c = NULL;
	}
	if (teamb_rpglike_cec060)
	{
		teamb_cec034->removeSubconsole(teamb_rpglike_cec060);
		teamb_rpglike_cec060 = NULL;
	}
	if (teamb_player2_cec068)
	{
		teamb_cec034->removeSubconsole(teamb_player2_cec068);
		teamb_player2_cec068 = NULL;
	}
	if (teamb_polymind_cec06c)
	{
		teamb_cec034->removeSubconsole(teamb_polymind_cec06c);
		teamb_polymind_cec06c = NULL;
	}
}
