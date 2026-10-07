// team_b_26: CRpglikeFull::update (0x878620) and ::render (0x878d70) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
using namespace std;
string intToString(int value);
string OpY1_intToStringGrouped(int value);	// NOTE: placeholder name (0x405330)
string &padLeft_408090(string &text, int width, char fill);	// NOTE: placeholder name
int tableEntry_434a80(int index, int n);	// NOTE: placeholder name
struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &color);	// 0x411e30
};
struct Point { int x; int y; };
extern Point pt_d1d62c;
extern Point pt_d2e9c0;
class OpR2b_Engine { public: void render(); };
class XConsole
{
public:
	virtual ~XConsole();
	bool isHidden();
	void setFore(XColor color);
	void setForeRow(int x, int y, int width, XColor color);
	void setCharRow(int x, int y, int width, int ch, XColor fore, XColor back);
	void print(int x, int y, const string &text);
	void render_429ea0();	// NOTE: placeholder name
	void setPos(int x, int y);
	void setHidden(bool hidden);
	void setFgColor(XColor color);
	void setBgColor(XColor color);
	void removeSubconsole(XConsole *console);
	int getWidth_44b0d0();	// NOTE: placeholder name
	int getLayer_44a7d0();	// NOTE: placeholder name
	void update_429e30();	// NOTE: placeholder name
};
class TeamB_RpglikeFull : public XConsole	// NOTE: placeholder name (CRpglikeFull)
{
public:
	char pad04[0x64 - 4];
	OpR2b_Engine *engine;
	void render878d70();
};
extern int teamb_level_cf4690;	// NOTE: placeholder name
extern int teamb_xp_cf4698;	// NOTE: placeholder name
extern int teamb_difficulty_cf4718;	// NOTE: placeholder name
extern XColor *teamb_color_d2981c;	// NOTE: placeholder name
extern XColor *teamb_color_cfe674;	// NOTE: placeholder name
extern XColor *teamb_color_d2175c;	// NOTE: placeholder name
extern XColor *teamb_color_cf6b24;	// NOTE: placeholder name
void TeamB_RpglikeFull::render878d70()	// 0x878d70 (local names follow docs/local-name-buckets.txt)
{
	if (isHidden())
		return;
	engine->render();
	setFore(*teamb_color_d2981c);
	string label = intToString(teamb_level_cf4690);
	padLeft_408090(label,2,'0');
	print(pt_d1d62c.x,pt_d1d62c.y,label);
	int next = tableEntry_434a80(teamb_difficulty_cf4718,teamb_level_cf4690 + 1) - tableEntry_434a80(teamb_difficulty_cf4718,teamb_level_cf4690);
	setForeRow(pt_d2e9c0.x,1,0x11,*teamb_color_cfe674);
	string status = teamb_level_cf4690 == 99 ? string("MAX") : OpY1_intToStringGrouped(teamb_xp_cf4698) + " / " + OpY1_intToStringGrouped(next);
	print(pt_d2e9c0.x,pt_d2e9c0.y,status);
	int width = 0x30;
	int total = teamb_xp_cf4698 * width / next;
	if (teamb_level_cf4690 == 99)
		total = width;
	else if (total == 0 && teamb_xp_cf4698 > 0)
		total = 1;
	else if (total == width && teamb_xp_cf4698 < next)
		total = width - 1;
	setCharRow(2,2,width,0xab,*teamb_color_d2175c,*teamb_color_cfe674);
	setCharRow(2,2,total,0xab,*teamb_color_cf6b24,*teamb_color_cfe674);
	render_429ea0();
}

class Console : public XConsole
{
public:
	Console(XConsole *parent, int x, int y, int width, int height, int font, bool hidden, int layer);
	char pad[0x6c - 4];
};
class TeamB_Stats { public: int unknown472c70(int id); };	// NOTE: placeholder name
extern TeamB_Stats teamb_stats2_d2c658;	// NOTE: placeholder name
class TeamB_MapFlags { public: bool unknown463280(); bool unknown463260(); };	// NOTE: placeholder name (Map)
extern TeamB_MapFlags *teamb_map_cefc4c;	// NOTE: placeholder name
class TeamB_Polymind49c2d0 { public: int getHeight_49c2d0(); };	// NOTE: placeholder name
extern TeamB_Polymind49c2d0 *teamb_cec058;	// NOTE: placeholder name
extern int teamb_cefabc;	// NOTE: placeholder name
extern void *teamb_upgrades_cec064;	// NOTE: placeholder name
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
extern bool teamb_d25450;	// NOTE: placeholder name
extern int teamb_d255fc;	// NOTE: placeholder name
extern XColor *teamb_color_d204ac;	// NOTE: placeholder name
int OpX5_maxInt(int a, int b);
bool OpX5_inRangeIncl(int min, int value, int max);
class TeamB_RpglikeFull2 : public Console	// NOTE: placeholder name (CRpglikeFull)
{
public:
	int getX_4a1c20();	// NOTE: placeholder name
	int getY_49cb20();	// NOTE: placeholder name
	void hideAlert_49cd70();	// NOTE: placeholder name
	void update878620();
	Console *alert6c;
	unsigned int time70;
	Console *sensor74;
};
void TeamB_RpglikeFull2::update878620()	// 0x878620 (local names follow docs/local-name-buckets.txt)
{
	if (isHidden())
		return;
	int shift = OpX5_maxInt(0,teamb_cec058->getHeight_49c2d0() - teamb_cefabc);
	if (teamb_upgrades_cec064 != NULL)
		shift = 0;
	setPos(getX_4a1c20(),getY_49cb20() - shift);
	if (alert6c != NULL)
	{
		if (teamb_tickCount >= time70)
			hideAlert_49cd70();
		else
		{
			bool visible = true;
			int time = teamb_tickCount - (time70 - 5000);
			if (OpX5_inRangeIncl(500,time,1000) || OpX5_inRangeIncl(1500,time,2000))
				visible = false;
			alert6c->setHidden(!visible);
		}
	}
	bool flag = teamb_stats2_d2c658.unknown472c70(0x435);
	if (flag && teamb_d25450 && teamb_d255fc != 0)
	{
		if (sensor74 == NULL)
		{
			string text = " SENSOR DATA BLINDED ";
			sensor74 = new Console(this,text.size(),1,getWidth_44b0d0() + 1,2,0,false,getLayer_44a7d0());
			sensor74->print(0,0,text);
			sensor74->setBgColor(*teamb_color_d204ac);
			sensor74->setFgColor(*teamb_color_cfe674);
		}
	}
	else if (flag && teamb_map_cefc4c->unknown463280())
	{
		if (sensor74 == NULL)
		{
			string text = " SENSOR DATA SCRAMBLED ";
			sensor74 = new Console(this,text.size(),1,getWidth_44b0d0() + 1,2,0,false,getLayer_44a7d0());
			sensor74->print(0,0,text);
			sensor74->setBgColor(*teamb_color_d204ac);
			sensor74->setFgColor(*teamb_color_cfe674);
		}
	}
	else if (flag && teamb_map_cefc4c->unknown463260())
	{
		if (sensor74 == NULL)
		{
			string text = " SENSOR DATA JAMMED ";
			sensor74 = new Console(this,text.size(),1,getWidth_44b0d0() + 1,2,0,false,getLayer_44a7d0());
			sensor74->print(0,0,text);
			sensor74->setBgColor(*teamb_color_d204ac);
			sensor74->setFgColor(*teamb_color_cfe674);
		}
	}
	else if (sensor74 != NULL && sensor74 != NULL)
	{
		removeSubconsole(sensor74);
		sensor74 = NULL;
	}
	update_429e30();
}
