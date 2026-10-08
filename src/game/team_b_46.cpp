// team_b_46: CRpglikeFull level-up banner (0x878b90) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
using namespace std;
string intToString(int value);
struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &color);	// 0x411e30
};
class XConsole
{
public:
	virtual ~XConsole();
	int getLayer_44a7d0();	// NOTE: placeholder name
	void printAligned(int x, int y, int align, const string &text);
	void setBackRow(int x, int y, int width, XColor color);
	void setForeRow(int x, int y, int width, XColor color);
};
class TeamB_LevelConsole : public XConsole	// NOTE: placeholder name (Console)
{
public:
	TeamB_LevelConsole(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);	// NOTE: placeholder name (Console::Console)
	void drawFrame_7b0640(int a, XColor color, int b, int c);	// NOTE: placeholder name (Console::drawFrame)
	char pad04[0x6c - 4];
};
extern int teamb_level_cf4690;	// NOTE: placeholder name
extern XColor *teamb_color_cf6b24;	// NOTE: placeholder name
extern XColor *teamb_color_d25e0c;	// NOTE: placeholder name
extern XColor *teamb_color_cfe674;	// NOTE: placeholder name
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
class TeamB_RpglikeLevel : public XConsole	// NOTE: placeholder name (CRpglikeFull)
{
public:
	char pad04[0x6c - 4];
	TeamB_LevelConsole *alert;
	unsigned int alertTime;
	void hideAlert_49cd70();	// NOTE: placeholder name
	void showLevelUp878b90();
};
void TeamB_RpglikeLevel::showLevelUp878b90()	// 0x878b90
{
	hideAlert_49cd70();
	alert = new TeamB_LevelConsole(this,0x34,3,0,-3,0,true,getLayer_44a7d0());
	alert->drawFrame_7b0640(0,*teamb_color_cf6b24,1,0);
	string text = "> > > REACHED LEVEL " + intToString(teamb_level_cf4690) + " < < <";
	alert->printAligned(0x1a,1,1,text);
	alert->setBackRow(2,1,0x30,*teamb_color_d25e0c);
	alert->setForeRow(2,1,0x30,*teamb_color_cfe674);
	alertTime = teamb_tickCount + 5000;
}
