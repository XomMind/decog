// op_cmap_squad: CMap::showCommArraySquad (0x818a00), the map label listing a comm array squad
// (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &c) throw();	// 0x411e30
};

struct Point
{
	int x;
	int y;
	Point(const Point &p) throw();	// 0x46ca50
};
struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_) throw();	// 0x46ca20
};
struct PosB { int x; int y; };	// NOTE: same name as src/game/cc_r2_19.cpp
struct OpCM_Loc	// NOTE: placeholder name
{
	int x;
	int y;
	bool isAt(const Point &p);	// NOTE: placeholder name (0x409b90)
};

class OpCM_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};
class OpCM_Engine	// NOTE: placeholder name (Engine)
{
public:
	OpCM_EngineItem *unknown50fb50(OpCM_Engine *engine, int type, Pos *a, Point *b, Pos *c, Point *d, int value);	// NOTE: placeholder name
};

class XConsole
{
public:
	virtual ~XConsole();
	void print(int x, int y, const string &text);
	void resetBack_418450();	// NOTE: placeholder name
	void setBackRow(int x, int y, int width, XColor color);
	int getLayer_44a7d0();	// NOTE: placeholder name (folded getter)
	char pad04[0x60 - 0x04];
};
class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	void animate(string name);

	int unknown60;
	OpCM_Engine *engine;
	void *title;
};

class OpCM_Timer	// NOTE: placeholder layout
{
public:
	OpCM_Timer(int type_, XConsole *console_, bool c_, int d_, const PosB &e_, int f_, int g_, int h_, const PosB &i_) {}	// NOTE: placeholder name (XTimerI::XTimerI 0x499e00, defined trivially so LTCG proves it nothrow)
	int type;
	Console *console;
	char pad8[0x28 - 8];
	OpCM_Loc loc;	// +0x28
	char pad30[0x34 - 0x30];
};
class HProp { public: int ID; HProp() throw(); };

class OpCM_Map	// NOTE: placeholder name (Map at 0xcefc4c)
{
public:
	vector<Point> &unknown464510();	// NOTE: placeholder name
	vector<int> &unknown464530();	// NOTE: placeholder name
	vector<vector<int> > &unknown4644f0();	// NOTE: placeholder name
};
extern OpCM_Map *opCM_map;	// NOTE: placeholder name

struct OpCM_Record	// NOTE: placeholder name
{
	char pad00[0x2c];
	string name;	// +0x2c
};
extern vector<OpCM_Record *> opCM_records_d25de0;	// NOTE: placeholder name
extern string opCM_squadNames_cf1a18[];	// NOTE: placeholder name
extern XConsole *opx5e_cec054;	// NOTE: placeholder name (0xcec054)
extern bool opx5b_asciiEnabled;	// NOTE: placeholder name (0xd28d15)
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
extern int opCM_labelTime_d28e90;	// NOTE: placeholder name
extern XColor *opCM_back_cfe674;	// NOTE: placeholder name
extern Point opY5_effectOrigin;	// NOTE: placeholder name (0xd2e20c)

void logError(string location, string message);	// 0x404f10
string intToString(int value);	// 0x4051f0
string OpR5f_toUpper_4083a0(const string &s);	// NOTE: placeholder name
int OpU8a_indexOfPoint(vector<Point> &v, Point p);	// NOTE: placeholder name (0x9d53a0)
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0
void opCM_deleteLabel_9d47d0(vector<OpCM_Timer *> &v, int index);	// NOTE: placeholder name

class CMap
{
public:
	void showCommArraySquad(const Point &p);

	char pad00[0x6c];
	Point offset;	// +0x6c
	char pad74[0x1d8 - 0x74];
	vector<OpCM_Timer *> labels;	// +0x1d8
};

void CMap::showCommArraySquad(const Point &p)
{
	int ii = OpU8a_indexOfPoint(opCM_map->unknown464510(),p);
	if (ii == -1)
	{
		logError("CMap::showCommArraySquad()","Invalid loc");
		return;
	}
	for (unsigned int i = 0; i < labels.size(); i++)
	{
		if (labels[i]->type == 0x11 && labels[i]->loc.isAt(p))
		{
			opCM_deleteLabel_9d47d0(labels,i);
			break;
		}
	}
	Pos pt(1,0);
	string buf = " " + OpR5f_toUpper_4083a0(opCM_squadNames_cf1a18[opCM_map->unknown464530()[ii]]) + " SQUAD ";
	Console *label = new Console(opx5e_cec054,buf.size(),1,p.x + pt.x + offset.x,p.y + pt.y + offset.y,opx5b_asciiEnabled != 0,false,-1);
	labels.push_back(new OpCM_Timer(0x11,label,false,teamb_tickCount + opCM_labelTime_d28e90,(PosB&)pt,HProp().ID,HProp().ID,HProp().ID,(const PosB&)p));
	label->resetBack_418450();
	label->print(0,0,buf);
	label->animate("A_CMap_HaulerHeader");
	vector<int> list(opCM_map->unknown4644f0()[ii]);
	vector<string> rows;
	for (unsigned int i = 0; i < list.size(); i++)
	{
		int n = 1;
		for (unsigned int j = i + 1; j < list.size(); j++)
		{
			if (list[j] == list[i])
			{
				n++;
				removeVectorElement(list,j);
				j--;
			}
		}
		rows.push_back(" " + intToString(n) + "x " + opCM_records_d25de0[list[i]]->name);
	}
	int w = 0;
	for (unsigned int i = 0; i < rows.size(); i++)
		w = OpX5_maxInt(w,rows[i].size() + 1);
	int h = rows.size();
	label = new Console(label,w,h,0,1,opx5b_asciiEnabled != 0,false,label->getLayer_44a7d0());
	label->resetBack_418450();
	for (unsigned int i = 0; i < rows.size(); i++)
	{
		label->print(0,i,rows[i]);
		label->setBackRow(0,i,rows[i].size() + 1,*opCM_back_cfe674);
	}
	int total = 0;
	if (rows.size() > 1)
	{
		OpU8a_lookup1("Type_GR3_Vert_E",&total);
		label->engine->unknown50fb50(label->engine,total,&Pos(1,0),&opY5_effectOrigin,&Pos(1,h - 1),&Point(opY5_effectOrigin),9)->unknown50de10();
		OpU8a_lookup1("Type_GR2_Vert_E",&total);
		label->engine->unknown50fb50(label->engine,total,&Pos(2,0),&opY5_effectOrigin,&Pos(2,h - 1),&Point(opY5_effectOrigin),9)->unknown50de10();
		OpU8a_lookup1("Type_WH7_Vert_E",&total);
		for (int x = 4; x < w; x++)
			label->engine->unknown50fb50(label->engine,total,&Pos(x,0),&opY5_effectOrigin,&Pos(x,h - 1),&Point(opY5_effectOrigin),9)->unknown50de10();
	}
	else
		label->animate("A_CMap_HaulerSingle");
}
