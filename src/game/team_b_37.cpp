// team_b_37: CTrailer::play (0x95a720, vtable slot 8) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
using namespace std;
int halfDiff_437190(int a, int b);	// NOTE: placeholder name (team_a_07.cpp)
struct Pos { int x; int y; Pos(int x_, int y_); };
class XConsole
{
public:
	virtual ~XConsole();
	void setHidden(bool hidden);
	int getWidth_44b0d0();	// NOTE: placeholder name
	void print(int x, int y, const string &text);
};
class TeamB_TrailerConsole : public XConsole	// NOTE: placeholder name (Console)
{
public:
	TeamB_TrailerConsole(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);	// NOTE: placeholder name (Console::Console)
	void animate(string name);
	char pad04[0x6c - 4];
};
class TeamB_TrailerText : public TeamB_TrailerConsole	// NOTE: placeholder name (CText)
{
public:
	TeamB_TrailerText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);	// NOTE: placeholder name (CText::CText)
	char pad6c[0x88 - 0x6c];
};
class TeamB_Graph { public: void clearMarked(bool flag); void setMarked(unsigned int index, bool flag); };	// NOTE: placeholder name (OpS_Graph)
extern TeamB_Graph *teamb_graph_cefa8c;	// NOTE: placeholder name
class TeamB_Rex { public: int unknown4189a0(); };	// NOTE: placeholder name (REX)
extern TeamB_Rex teamb_rex_d223f0;	// NOTE: placeholder name
extern int teamb_trailerTypes_bcda58[];	// NOTE: placeholder name
extern string teamb_trailerTexts_d31738[];	// NOTE: placeholder name
class TeamB_Trailer : public XConsole	// NOTE: placeholder name (CTrailer)
{
public:
	char pad04[0x60 - 4];
	int unknown60;	// NOTE: placeholder name
	char pad64[0x6c - 0x64];
	int index;	// NOTE: placeholder name
	void play95a720();
};
void TeamB_Trailer::play95a720()	// 0x95a720 (local names follow docs/local-name-buckets.txt)
{
	unknown60 = 3;
	setHidden(false);
	teamb_graph_cefa8c->clearMarked(true);
	teamb_graph_cefa8c->setMarked(0x1f,true);
	switch (teamb_trailerTypes_bcda58[index])
	{
		case 0:
		{
			int x = halfDiff_437190(teamb_trailerTexts_d31738[index].size(),getWidth_44b0d0());
			int y = teamb_rex_d223f0.unknown4189a0() / 2;
			TeamB_TrailerConsole *c = new TeamB_TrailerText(this,Pos(x,y),teamb_trailerTexts_d31738[index],0,0,-1);
			c->animate("A_CTrailer_Text");
			c = new TeamB_TrailerText(this,Pos(x,y),teamb_trailerTexts_d31738[index],0,0,-1);
			c->animate("A_CTrailer_01");
			break;
		}
		case 1:
		{
			int x = halfDiff_437190(teamb_trailerTexts_d31738[index].size(),getWidth_44b0d0());
			int y = teamb_rex_d223f0.unknown4189a0() / 2;
			TeamB_TrailerConsole *c = new TeamB_TrailerText(this,Pos(x,y),teamb_trailerTexts_d31738[index],0,0,-1);
			c->animate("A_CTrailer_Typetext");
			c = new TeamB_TrailerText(this,Pos(x,y),teamb_trailerTexts_d31738[index] + " ",0,0,-1);
			c->animate("A_CTrailer_Typing");
			break;
		}
		case 2:
		{
			int x = halfDiff_437190(teamb_trailerTexts_d31738[index].size(),getWidth_44b0d0());
			int y = teamb_rex_d223f0.unknown4189a0() / 2;
			TeamB_TrailerConsole *c = new TeamB_TrailerConsole(this,getWidth_44b0d0(),1,0,y + 1,2,false,-1);
			c->animate("A_CTrailer_Line");
			TeamB_TrailerConsole *label = new TeamB_TrailerText(this,Pos(x,y),teamb_trailerTexts_d31738[index],2,0,-1);
			label->animate("A_CTrailer_Gridsage");
			c = new TeamB_TrailerConsole(this,teamb_trailerTexts_d31738[index].size(),2,x,y,2,false,-1);
			c->animate("A_CTrailer_Underline");
			break;
		}
		case 3:
		{
			int x = halfDiff_437190(teamb_trailerTexts_d31738[index].size(),getWidth_44b0d0());
			int y = teamb_rex_d223f0.unknown4189a0() / 2;
			TeamB_TrailerConsole *c = new TeamB_TrailerConsole(this,getWidth_44b0d0(),1,0,y,2,false,-1);
			c->print(x / 2,0,teamb_trailerTexts_d31738[index]);
			c->animate("A_CTrailer_Whiteflash");
			break;
		}
	}
}
