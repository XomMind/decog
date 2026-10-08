// team_b_45: CAnalysis::CAnalysis (0x8b1330) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
void logError(string source, string message);
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name
bool opr5c_unknown8b12f0();	// NOTE: placeholder name
struct XColor { unsigned char r; unsigned char g; unsigned char b; };
struct Point { int x; int y; Point(const Point &p); };
struct Pos { int x; int y; Pos(int x_, int y_); };
struct Rect { int x; int y; int width; int height; Rect(const Rect &r); };
class TeamB_AnalysisEffect { public: void unknown50de10(); };	// NOTE: placeholder name
class TeamB_AnalysisEngine { public: TeamB_AnalysisEffect *unknown50fb50(TeamB_AnalysisEngine *engine, int type, const Pos &pos, Point *b, const void *c, const void *d, int value); };	// NOTE: placeholder name (OpR2b_Engine)
class XConsole
{
public:
	virtual ~XConsole();
	int getHeight();
	int getWidth_44b0d0();	// NOTE: placeholder name
	void setHidden(bool hidden);
	void print(int x, int y, const string &text);
	string getString(const Pos &pos, unsigned int length);
	char pad04[0x64 - 4];
	TeamB_AnalysisEngine *engine;
	char pad68[0x6c - 0x68];
};
class ConsoleTitle : public XConsole { public: ConsoleTitle(XConsole *parent, string text, int a, int b); char pad6c[0x8c - 0x6c]; };
class Console : public XConsole
{
public:
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual ~Console();
	void setTitle(ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void animate(string name);
};
class CCloseButton : public XConsole { public: CCloseButton(XConsole *parent, const XColor &color, int a); char pad6c[0x8c - 0x6c]; };
class OpS_Graph { public: void pushFrame(int a, int b, int c, bool d); void setUpdate_416770(bool (*callback)());	/* NOTE: placeholder name */ };
extern OpS_Graph *teamb_graph_cefa8c;	// NOTE: placeholder name
extern XColor *teamb_color_cf1f2c;	// NOTE: placeholder name
extern Point teamb_point_cfbec0;	// NOTE: placeholder name
extern Point teamb_point_d2e20c;	// NOTE: placeholder name
class CAnalysis;
extern CAnalysis *opw6_cec128;	// NOTE: placeholder name
class CAnalysis : public Console
{
public:
	CAnalysis(XConsole *parent, const Rect &rect, int type, const vector<string> &lines);
	virtual ~CAnalysis();	// 0x4acb90
	int type;
	CCloseButton *closeButton;
};
CAnalysis::CAnalysis(XConsole *parent, const Rect &rect, int type, const vector<string> &lines)	// 0x8b1330 (local names follow docs/local-name-buckets.txt)
	: Console(parent,rect,0,false,0x1a)
{
	this->type = type;
	opw6_cec128 = this;
	if (this->type == 4)
		setTitle(new ConsoleTitle(this,"/ R I F /",0,4));
	else
	{
		string title(this->type == 0 ? "\\ A N A L Y S I S \\" : (this->type == 1 ? "\\ T R A I T S \\" : (this->type == 3 ? "\\ R E S I S T A N C E S \\" : "\\ I N F O \\")));
		setTitle(new ConsoleTitle(this,title,0,2));
	}
	animate("CParse_Border");
	int y = 2;
	for (unsigned int i = 0; i < lines.size(); i++, y++)
		print(2,y,lines[i]);
	if (this->type == 4)
	{
		int sx, color, bottom, pick, last, flags, begin;
		animate("A_BlockAppear_GR3_Rif");
		opR1d_4541b0(0x31,0,0);
		sx = 2;
		bottom = getHeight() - 3;
		OpU8a_lookup1("CHudRif_Help",&color);
		do { for (int x = Pos(sx,bottom).x; x < Pos(sx,bottom).x + getWidth_44b0d0() - 4; x++) engine->unknown50fb50(engine,color,Pos(x,Pos(sx,bottom).y),&teamb_point_cfbec0,0,0,9)->unknown50de10(); } while (0);
		OpU8a_lookup1("CHudRif_Ability",&pick);
		OpU8a_lookup1("CHudRif_Level",&flags);
		for (int row = 2; row < bottom; row++)
		{
			string line = getString(Pos(sx,row),0x1e);
			last = line.find(':',0);
			if (last != string::npos)
			{
				if (line[last - 1] == ')')
				{
					begin = line.rfind('(',last);
					do { for (int x = Pos(sx + begin + 1,row).x; x < Pos(sx + begin + 1,row).x + last - 2 - begin; x++) engine->unknown50fb50(engine,flags,Pos(x,Pos(sx + begin + 1,row).y),&teamb_point_cfbec0,0,0,9)->unknown50de10(); } while (0);
					last = begin - 1;
				}
				do { for (int x = Pos(sx,row).x; x < Pos(sx,row).x + last; x++) engine->unknown50fb50(engine,pick,Pos(x,Pos(sx,row).y),&teamb_point_cfbec0,0,0,9)->unknown50de10(); } while (0);
			}
		}
	}
	else
	{
		if (lines.size() <= 1)
			logError("CAnalysis()","too little content, will crash");
		int vert;
		OpU8a_lookup1("Type_GR3_Vert_E",&vert);
		for (int x = 2; x <= getWidth_44b0d0() - 4; x++)
			engine->unknown50fb50(engine,vert,Pos(x,2),&teamb_point_d2e20c,&Pos(x,lines.size() + 1),&Point(teamb_point_d2e20c),9)->unknown50de10();
	}
	teamb_graph_cefa8c->pushFrame(0xd,(int)this,0xf5,false);
	if (this->type == 4)
		teamb_graph_cefa8c->setUpdate_416770(opr5c_unknown8b12f0);
	closeButton = new CCloseButton(this,*teamb_color_cf1f2c,0xd);
	closeButton->setHidden(false);
}
