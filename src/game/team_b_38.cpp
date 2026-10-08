// team_b_38: CMapFine::update (0x874590, vtable slot 6) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <vector>
using namespace std;
struct Pos { int x; int y; bool notAt_409cf0(int x_, int y_);	/* NOTE: placeholder name (Predicate_409cf0::test) */ };
class XConsole
{
public:
	virtual ~XConsole();
	bool isHidden();
	Pos getPos();
	int getHeight();
	int getWidth_44b0d0();	// NOTE: placeholder name
	void setPos(int x, int y);
	void move(int dx, int dy);
	void removeSubconsole(XConsole *console);
	void update_429e30();	// NOTE: placeholder name
};
struct TeamB_FineMessage { XConsole *console; void update(); };	// NOTE: placeholder name (OpW5_FineMessage)
struct TeamB_FineItem { XConsole *console; void update(); };	// NOTE: placeholder name (OpW5_FineBubble)
struct TeamB_FineTimer { XConsole *console; bool update8767a0(int row); };	// NOTE: placeholder name (OpW5_FineTimer)
class TeamB_FinePopup : public XConsole	// NOTE: placeholder name (CAchievementPopup)
{
public:
	TeamB_FinePopup(XConsole *parent, int id);	// NOTE: placeholder name (CAchievementPopup::CAchievementPopup)
	char pad04[0x6c - 4];
	unsigned int expire;
	char pad70[0x74 - 0x70];
};
class TeamB_FineHelper { public: int cleanup_470b50(); int popFront(); };	// NOTE: placeholder name
extern TeamB_FineHelper *teamb_fineHelper_cefaa8;	// NOTE: placeholder name
class TeamB_FineWorld { public: bool cleanup_71bbb0(); };	// NOTE: placeholder name
extern TeamB_FineWorld *teamb_fineWorld_cefc4c;	// NOTE: placeholder name
extern XConsole *opx5e_cec054;	// NOTE: placeholder name (0xcec054)
extern XConsole *teamb_fine_cec058;	// NOTE: placeholder name
extern XConsole *teamb_fine_cec08c;	// NOTE: placeholder name
extern XConsole *teamb_fine_cec0f8;	// NOTE: placeholder name
extern XConsole *teamb_fine_cec11c;	// NOTE: placeholder name
extern void *teamb_fine_cec140;	// NOTE: placeholder name
extern int teamb_fine_cf4b38;	// NOTE: placeholder name
extern int teamb_fine_caf178;	// NOTE: placeholder name
extern int teamb_fine_d28f68;	// NOTE: placeholder name
extern int teamb_fine_cefc90;	// NOTE: placeholder name
extern int teamb_fine_d28f78;	// NOTE: placeholder name
extern int teamb_fine_d01a24;	// NOTE: placeholder name
extern int teamb_cellWidth_caf128;	// NOTE: placeholder name
extern int teamb_cellHeight_caf12c;	// NOTE: placeholder name
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
int OpX5_minInt(int a, int b);
void OpT8a_eraseAt(vector<int> &v, unsigned int &index);
class TeamB_MapFineUpdate : public XConsole	// NOTE: placeholder name (CMapFine)
{
public:
	char pad[0x6c - 4];
	vector<TeamB_FineMessage *> messages;
	vector<TeamB_FineItem *> bubbles0;
	TeamB_FineItem *current0;
	vector<TeamB_FineItem *> bubbles1;
	TeamB_FineItem *current1;
	vector<TeamB_FineItem *> bubbles2;
	TeamB_FineItem *current2;
	vector<TeamB_FineTimer *> timers;
	vector<XConsole *> popups;
	void update874590();
};
void TeamB_MapFineUpdate::update874590()	// 0x874590 (local names follow docs/local-name-buckets.txt)
{
	if (isHidden())
		return;
	if (!messages.empty())
	{
		for (int i = messages.size() - 1; i >= 0; i--)
			messages[i]->update();
	}
	if (!bubbles0.empty())
	{
		for (int j = bubbles0.size() - 1; j >= 0; j--)
			bubbles0[j]->update();
	}
	if (current0 != NULL)
		current0->update();
	if (!bubbles1.empty())
	{
		for (int k = bubbles1.size() - 1; k >= 0; k--)
			bubbles1[k]->update();
	}
	if (current1 != NULL)
		current1->update();
	if (!bubbles1.empty() && bubbles1.front()->console->getPos().notAt_409cf0(0,1))
	{
		int x = 0, y = 1;
		for (unsigned int m = 0; m < bubbles1.size(); m++, y++)
		{
			if (m == teamb_fine_d28f78 + 1)
			{
				x = teamb_fine_d01a24;
				y = 1;
			}
			bubbles1[m]->console->setPos(x,y);
		}
		if (current1 != NULL)
			current1->console->setPos(x,y);
	}
	if (!bubbles2.empty())
	{
		for (int n = bubbles2.size() - 1; n >= 0; n--)
			bubbles2[n]->update();
	}
	if (current2 != NULL)
		current2->update();
	if (!bubbles2.empty() && bubbles2.front()->console->getPos().y != 1)
	{
		int dy = bubbles2.front()->console->getPos().y - 1;
		for (unsigned int p = 0; p < bubbles2.size(); p++)
			bubbles2[p]->console->move(0,-dy);
		if (current2 != NULL)
			current2->console->move(0,-dy);
	}
	if (!timers.empty())
	{
		for (int idx = timers.size() - 1, row = opx5e_cec054->getHeight() * teamb_cellHeight_caf12c - 1; idx >= 0; idx--, row--)
		{
			if (timers[idx]->update8767a0(row))
				row++;
		}
	}
	if (teamb_fineHelper_cefaa8->cleanup_470b50() != 0 && teamb_fine_cec11c->isHidden() && teamb_fine_cec0f8->isHidden() && !teamb_fineWorld_cefc4c->cleanup_71bbb0() && teamb_fine_cec140 == NULL && teamb_fine_cf4b38 == 0x1c && popups.size() < 5)
	{
		int id = teamb_fineHelper_cefaa8->popFront();
		if (id != teamb_fine_caf178 && teamb_fine_d28f68 > 0)
			popups.push_back(new TeamB_FinePopup(this,id));
	}
	if (!popups.empty())
	{
		for (unsigned int s = 0; s < popups.size(); s++)
		{
			if (teamb_tickCount >= ((TeamB_FinePopup *)popups[s])->expire)
			{
				removeSubconsole(popups[s]);
				OpT8a_eraseAt((vector<int> &)popups,s);
			}
		}
		if (!popups.empty())
		{
			int bottom = messages.empty() ? opx5e_cec054->getHeight() * teamb_cellHeight_caf12c - 1 : messages.front()->console->getPos().y;
			if (teamb_fine_cefc90 == 2)
				bottom = OpX5_minInt(bottom,teamb_fine_cec08c->getPos().y - teamb_fine_cec058->getPos().y - 1);
			bottom--;
			bottom -= popups.back()->getHeight();
			for (int t = popups.size() - 1; t >= 0; bottom -= popups[t]->getHeight() + 1, t--)
				popups[t]->setPos(opx5e_cec054->getWidth_44b0d0() * teamb_cellWidth_caf128 - 1 - popups[t]->getWidth_44b0d0(),bottom);
		}
	}
	update_429e30();
}
