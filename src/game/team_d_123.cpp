// team_d_123: Overmind member 0x68c6d0 (caller BS::turnUpdate_51da30): a protovariant robot goes rogue - an
// alert sound and message, a phrase record, it switches to the hostile faction, a hunting AI gets the whole map
// as its area, and the containment squad's last member is set to hunt.
// NOTE: class layouts are partial; names are placeholders. The sound/message blocks are the game's usual
// do { ... } while (0) message macros.
#include <string>
#include <vector>
using namespace std;

class Entity;

class HProp
{
public:
	int ID;
	HProp();
};

struct Group123	// NOTE: placeholder name
{
	int getType123();	// NOTE: placeholder name (folded getter, +0x08)
};

class HGroup
{
public:
	int ID;
	HGroup();
	Group123 *operator->();	// NOTE: OpC_Handle::get230
};

class HEntity
{
public:
	int ID;
	Entity *operator->() const;
};

struct OpQ1_Box	// NOTE: placeholder name
{
	int a;
	int b;
	int c;
	int d;

	OpQ1_Box(int a_, int b_, int c_, int d_);
};

class AI123	// NOTE: placeholder name
{
public:
	int getMode123();	// NOTE: placeholder name (folded getter Array2D::getHeight)
	void setArea123(const OpQ1_Box &box);	// NOTE: placeholder name (Calls_459470::delegate)
	void setMode123(int mode);	// NOTE: placeholder name (folded setter Sweep_4505b0::setField)
};

class Entity
{
public:
	HGroup getGroup();
	string *getName123();	// NOTE: placeholder name (folded getter XCell::getFore, +0x0c)
	void unknown5fdab0();	// NOTE: placeholder name (Push_5fdab0::operate)
	void changeFaction(HGroup newGroup, bool flag);
	AI123 *getAI123();	// NOTE: placeholder name (folded getter ManualUI::unknown45b590)
};

class CellGrid123	// NOTE: placeholder name (0xcfd44c)
{
public:
	int getWidth();
	int getHeight();
};
extern CellGrid123 cells123_cfd44c;	// NOTE: placeholder name

class BS
{
public:
	HGroup unknown463890(int i);	// NOTE: placeholder name
};
extern BS *world123_cefc4c;	// NOTE: placeholder name

class MessageLog123	// NOTE: placeholder name (0xcf1080)
{
public:
	void unknown451400(int value);	// NOTE: placeholder name
};
extern MessageLog123 messageLog123_cf1080;	// NOTE: placeholder name
extern bool soundOff123_d28fb0;	// NOTE: placeholder name
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name

class ConsoleA123	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA123 *consoleA123_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs123_cec0b4;	// NOTE: placeholder name

bool showMessage123(int id, const string *text, const string *b, int c, HProp d, HProp e, const void *at, int flag);	// NOTE: placeholder name (0x5111e0)
void message123_5141b0(int id, const string *text, int b, int c, HProp e, int d);	// NOTE: placeholder name (0x5141b0)

struct Squad123	// NOTE: placeholder name and layout
{
	int		unknown00;
	HEntity	leader;	// +0x04
};

class Overmind123	// NOTE: placeholder name and layout (Overmind)
{
public:
	char				pad00[0x50];
	vector<Squad123 *>	squads;	// +0x50

	Squad123 *spawnHunterParty(HEntity e, int a, bool b);	// NOTE: placeholder name
	void unknown68c6d0(HEntity e);	// NOTE: placeholder name
};

void Overmind123::unknown68c6d0(HEntity e)
{
	if (e->getGroup()->getType123() == 5)
		return;
	string msg = "ALERT: Protovariant " + *e->getName123() + " out of control, dispatching containment squad.";
	do
	{
		messageLog123_cf1080.unknown451400(1);
		if (1)
		{
			if (!(soundOff123_d28fb0 && 1 && 1))
				opR1d_4541b0(0x129,0,0);
		}
		do
		{
			if (showMessage123(0x324,&msg,0,0,HProp(),HProp(),0,0))
				consoleA123_cec058->unknown8758d0(true);
			logMsgs123_cec0b4->scrollToEnd();
		} while (0);
		logMsgs123_cec0b4->scrollToEnd();
	} while (0);
	do
	{
		message123_5141b0(0x1ef,e->getName123(),0,0,HProp(),0);
	} while (0);
	e->unknown5fdab0();
	e->changeFaction(world123_cefc4c->unknown463890(5),true);
	if (e->getAI123()->getMode123() == 1)
		e->getAI123()->setArea123(OpQ1_Box(0,0,cells123_cfd44c.getWidth() - 1,cells123_cfd44c.getHeight() - 1));
	if (spawnHunterParty(e,0,true) && !squads.empty())
		squads.back()->leader->getAI123()->setMode123(2);
}
