// team_d_90: gameOver() (0x7c0c40): hides the game interface, picks a font that fits the screen for the
// game-over display, and opens CGameover.
// NOTE: the function name comes from the exe's log strings; global names are placeholders. Matching relies on
// REX's getters in cc_r2_22.cpp and the local RexOffsets90 getters (LTCG proves the calls cannot throw).
#include <vector>
#include <string>
using namespace std;

void logError(string location, string message);
void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)
string unknown7c0ad0(const string &name);	// NOTE: placeholder name (font family of a font name)
bool opr1c_hasPtr_cebd5c();	// NOTE: placeholder name (0x4328a0)

class XConsole
{
public:
	void setHidden(bool hidden);
	bool isVisible();
};

class REX	// NOTE: placeholder layout (0xd223f0)
{
public:
	int unknown418980();	// NOTE: placeholder name
	int unknown4189a0();	// NOTE: placeholder name
	int unknown4189c0();	// NOTE: placeholder name
	int unknown4189e0();	// NOTE: placeholder name
	string unknown418a60();	// NOTE: placeholder name
	void unknown418aa0(vector<string> *names, bool all);	// NOTE: placeholder name
	void unknown418b20(vector<int> *widths, bool all);	// NOTE: placeholder name
	void unknown418ba0(vector<int> *heights, bool all);	// NOTE: placeholder name
	void unknown4262c0(int a, int b, int c, int d, string text);	// NOTE: placeholder name
};
extern REX rex90_d223f0;	// NOTE: placeholder name

struct RexOffsets90	// NOTE: placeholder name (REX's screen offset fields)
{
	char	pad00[0x14];
	int		offsetX;	// +0x14
	int		offsetY;	// +0x18

	int getOffsetX();	// NOTE: local copy of the folded getter 0x44a630 (Submission_Envelope::GetCachedSize)
	int getOffsetY();	// NOTE: local copy of the folded getter 0x418900 (Submission::GetCachedSize)
};

int RexOffsets90::getOffsetX()
{
	return offsetX;
}

int RexOffsets90::getOffsetY()
{
	return offsetY;
}

class Mixer90	// NOTE: placeholder name (Mixer_419bf0)
{
public:
	void haltAll();
};
extern Mixer90 *mixer90_cefa90;	// NOTE: placeholder name

class SoundMgr
{
public:
	void unknown4544e0();	// NOTE: placeholder name
	void unknown5003b0();	// NOTE: placeholder name
};
extern SoundMgr soundMgr90_d2d2a0;	// NOTE: placeholder name

class OpS_Graph
{
public:
	void setMarked(unsigned int index, bool marked);
};
extern OpS_Graph *graph90_cefa8c;	// NOTE: placeholder name

class PlayerData90	// NOTE: placeholder name (0xcf45d8)
{
public:
	bool isFlagActive();	// NOTE: placeholder name
};
extern PlayerData90 playerData90_cf45d8;	// NOTE: placeholder name

class GM90	// NOTE: placeholder name (0xcefaa8)
{
public:
	void unknown792dc0();	// NOTE: placeholder name
};
extern GM90 *gm90_cefaa8;	// NOTE: placeholder name

class CGameover
{
public:
	CGameover();
	char pad[0xa0];
};

extern void *gameover90_cec144;	// NOTE: placeholder name
extern int music90_cf4b38;		// NOTE: placeholder name
extern void *ptr90_cefc90;		// NOTE: placeholder name
extern bool flag90_d28c8a;		// NOTE: placeholder name
extern int mode90_cebd5c;		// NOTE: placeholder name
extern bool flag90_cefacd;		// NOTE: placeholder name
extern XConsole *c90_cec034, *c90_cec0f4, *c90_cec0b0, *c90_cec0d0, *c90_cec0d4, *c90_cec0d8, *c90_cec0dc,
	*c90_cec0e4, *c90_cec0e8, *c90_cec0ec, *c90_cec0c8, *c90_cec0cc, *c90_cec0b8, *c90_cec0c0, *c90_cec054,
	*c90_cec058, *c90_cec074, *c90_cec078, *c90_cec07c, *c90_cec084, *c90_cec088, *c90_cec08c, *c90_cec138;	// NOTE: placeholder names

void gameOver()
{
	if (gameover90_cec144)
	{
		logError("gameOver()","Called twice!");
		return;
	}
	if (music90_cf4b38 != 5 && music90_cf4b38 != 0xc && music90_cf4b38 != 9 && music90_cf4b38 != 0xd)
		mixer90_cefa90->haltAll();
	soundMgr90_d2d2a0.unknown4544e0();
	soundMgr90_d2d2a0.unknown5003b0();
	c90_cec034->setHidden(true);
	c90_cec0f4->setHidden(true);
	c90_cec0b0->setHidden(true);
	c90_cec0d0->setHidden(true);
	c90_cec0d4->setHidden(!(ptr90_cefc90 && c90_cec0d0->isVisible()));
	c90_cec0d8->setHidden(!c90_cec0d0->isVisible());
	c90_cec0dc->setHidden(!c90_cec0d0->isVisible());
	c90_cec0e4->setHidden(!(!flag90_d28c8a && c90_cec0d0->isVisible()));
	c90_cec0e8->setHidden(!(c90_cec0d0->isVisible() && mode90_cebd5c == 2));
	c90_cec0ec->setHidden(!(c90_cec0d0->isVisible() && mode90_cebd5c == 2));
	c90_cec0c8->setHidden(true);
	c90_cec0cc->setHidden(true);
	c90_cec0b8->setHidden(true);
	c90_cec0c0->setHidden(true);
	c90_cec054->setHidden(true);
	c90_cec058->setHidden(true);
	c90_cec074->setHidden(true);
	c90_cec078->setHidden(true);
	c90_cec07c->setHidden(true);
	c90_cec084->setHidden(true);
	c90_cec088->setHidden(true);
	c90_cec08c->setHidden(true);
	c90_cec138->setHidden(true);
	graph90_cefa8c->setMarked(4,false);
	graph90_cefa8c->setMarked(5,false);
	graph90_cefa8c->setMarked(7,false);
	if (!flag90_cefacd && !playerData90_cf45d8.isFlagActive())
		gm90_cefaa8->unknown792dc0();
	vector<string> base;
	rex90_d223f0.unknown418aa0(&base,true);
	vector<int> ok;
	rex90_d223f0.unknown418b20(&ok,true);
	vector<int> adj;
	rex90_d223f0.unknown418ba0(&adj,true);
	int x = rex90_d223f0.unknown418980() * rex90_d223f0.unknown4189c0();
	int avg = rex90_d223f0.unknown4189a0() * rex90_d223f0.unknown4189e0();
	int amount = 0x3c;
	int center = avg / amount;
	int ally = -1;
	if (!opr1c_hasPtr_cebd5c())
		rex90_d223f0.unknown4262c0(((RexOffsets90 *)&rex90_d223f0)->getOffsetX(),((RexOffsets90 *)&rex90_d223f0)->getOffsetY(),rex90_d223f0.unknown418980(),rex90_d223f0.unknown4189a0(),rex90_d223f0.unknown418a60());
	else
	{
		for (unsigned int i = 0; i < adj.size(); i++)
		{
			if (adj[i] <= center && (ally == -1 || adj[i] > adj[ally]))
				ally = i;
		}
		if (ally == -1)
			logFatal("gameOver()","no font?");
		if (unknown7c0ad0(rex90_d223f0.unknown418a60()) != unknown7c0ad0(base[ally]))
		{
			string w = unknown7c0ad0(rex90_d223f0.unknown418a60());
			for (unsigned int j = 0; j < adj.size(); j++)
			{
				if (adj[j] == adj[ally] && unknown7c0ad0(base[j]) == w)
				{
					ally = j;
					break;
				}
			}
		}
		int first = x / ok[ally];
		if (first < 0xa0)
			logFatal("gameOver()","w < 160?");
		int h = avg / adj[ally];
		rex90_d223f0.unknown4262c0((x - first * ok[ally]) / 2,(avg - h * adj[ally]) / 2,first,h,base[ally]);
	}
	new CGameover();
}
