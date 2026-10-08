// team_b_50: CMapFine::render (0x876ba0, vtable slot 7) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
using namespace std;
struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &color);	// 0x411e30
};
struct Pos { int x; int y; };
class XConsole
{
public:
	virtual ~XConsole();
	bool isHidden();
	Pos getPos();
	int getWidth_44b0d0();	// NOTE: placeholder name
	void setBgColor(XColor color);
	void setFore(XColor color);
	void printAligned(int x, int y, int align, const string &text);
	void removeSubconsole(XConsole *console);
	void render_429ea0();	// NOTE: placeholder name
};
class TeamB_FineConsole : public XConsole	// NOTE: placeholder name (Console)
{
public:
	TeamB_FineConsole(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);	// NOTE: placeholder name (Console::Console)
	char pad04[0x6c - 4];
};
extern XConsole *opx5e_cec054;	// NOTE: placeholder name (0xcec054)
extern XConsole *teamb_fine_cec058;	// NOTE: placeholder name
extern XConsole *teamb_pay2buy_cec05c;	// NOTE: placeholder name
extern int teamb_cellWidth_caf128;	// NOTE: placeholder name
extern XColor *teamb_color_d2175c;	// NOTE: placeholder name
extern XColor *teamb_color_d25f60;	// NOTE: placeholder name
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
class TeamB_MapFineRender : public XConsole	// NOTE: placeholder name (CMapFine)
{
public:
	char pad04[0xd8 - 4];
	unsigned int textTime;
	TeamB_FineConsole *textConsole;
	string text;
	void render876ba0();
};
void TeamB_MapFineRender::render876ba0()	// 0x876ba0
{
	if (isHidden())
		return;
	if (textTime != 0)
	{
		if (textConsole == NULL)
		{
			textConsole = new TeamB_FineConsole(this,opx5e_cec054->getWidth_44b0d0() * teamb_cellWidth_caf128 - teamb_pay2buy_cec05c->getWidth_44b0d0() - teamb_pay2buy_cec05c->getPos().x,1,teamb_pay2buy_cec05c->getPos().x + teamb_pay2buy_cec05c->getWidth_44b0d0() + 1,teamb_pay2buy_cec05c->getPos().y - teamb_fine_cec058->getPos().y + 1,0,false,-1);
			textConsole->setBgColor(*teamb_color_d2175c);
			textConsole->setFore(*teamb_color_d25f60);
			textConsole->printAligned(textConsole->getWidth_44b0d0() / 2,0,1,text);
		}
		else if (teamb_tickCount > textTime + 10000)
		{
			textTime = 0;
			if (textConsole != NULL)
			{
				removeSubconsole(textConsole);
				textConsole = NULL;
			}
		}
	}
	render_429ea0();
}
