// op_map_dialog: 0x874d80, pushes a speech dialog onto the map message stack (called by MessageLog::push)
// (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
	Point() throw();	// 0x453b40
	Point(const Point &p) throw();	// 0x46ca50
	Point(const Point &p, int dx, int dy) throw();	// 0x4099c0
	Point &set_46ca50(const Point &p) throw();	// NOTE: placeholder name (folded with the copy ctor)
};
struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_) throw();	// 0x46ca20
	Pos(const Pos &p, int dx, int dy) throw();	// 0x4099c0
};
struct Rect
{
	int x;
	int y;
	int w;
	int h;
	Rect() throw();	// 0x40a6e0
	Rect(const Rect &r) throw();	// 0x40a720
};

class OpMD_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};
class OpMD_Engine	// NOTE: placeholder name (Engine)
{
public:
	OpMD_EngineItem *unknown50fb50(OpMD_Engine *engine, int type, Pos *a, Point *b, Pos *c, Point *d, int value);	// NOTE: placeholder name
};

class XConsole
{
public:
	virtual ~XConsole();
	Pos getPos();	// 0x417480
	int getHeight();	// 0x4174c0
	int getWidth();	// 0x44b0d0
	void setPos(const Pos &pos);	// 0x4289e0
	void printWrapped_4182b0(int x, int y, int width, int height, int align, const string &text);	// NOTE: placeholder name
	char pad04[0x60 - 0x04];
};
class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	void animate(string name);

	int unknown60;
	OpMD_Engine *engine;
	void *title;
};

class Entity
{
public:
	const Point &getPosition();	// 0x45a4a0
	int unknown5c7fc0(class HEntity other);	// NOTE: placeholder name
};
class HEntity
{
public:
	int ID;
	Entity *operator->() const;	// 0x9b6570
	bool isValid() const;	// 0x9b65e0
};

class OpMD_Map	// NOTE: placeholder name (Map at 0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
};
extern OpMD_Map *opMD_map;	// NOTE: placeholder name

class OpMD_CMap : public XConsole	// NOTE: placeholder name (CMap at 0xcec054)
{
public:
	bool unknown8052f0(const Point &p);	// NOTE: placeholder name
	Point *getOffset_458ef0();	// NOTE: placeholder name (folded getter)
};
extern OpMD_CMap *opMD_cmap_cec054;	// NOTE: placeholder name
extern XConsole *opMD_parent_cec058;	// NOTE: placeholder name

struct OpMD_Dialog	// NOTE: placeholder name (0x1c bytes)
{
	OpMD_Dialog(Console *console_, int expire_, HEntity source_, int type_, bool alt_, Console *bar_, int start_);	// 0x49be20
	~OpMD_Dialog();	// NOTE: placeholder name (0x8758a0)
	Console *console;
	int expire;
	int start;
	int type;	// +0x0c
	bool alt;	// +0x10
	Console *bar;	// +0x14
	HEntity source;
};

extern int fontCellWidth;	// 0xcaf128
extern int fontCellScale;	// 0xcaf12c
extern int opMD_bottom_cefac8;	// NOTE: placeholder name
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
extern string opMD_speakerNames_d35be8[];	// NOTE: placeholder name
extern Point opMD_origin_cfbec0;	// NOTE: placeholder name

bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)

class OpMD_Dialogs	// NOTE: placeholder name
{
public:
	void push_874d80(HEntity source, const string &text);	// NOTE: placeholder name

	char pad00[0x6c];
	vector<OpMD_Dialog *> dialogs;	// +0x6c
};

void OpMD_Dialogs::push_874d80(HEntity source, const string &text)
{
	int size = opMD_cmap_cec054->getWidth() * fontCellWidth;
	int n = 2;
	int len = size - fontCellWidth * 2;
	int count = text.size() / len + (text.size() % len != 0);
	for (unsigned int i = 0; i < dialogs.size(); i++)
		dialogs[i]->console->setPos(Pos(dialogs[i]->console->getPos(),0,-count));
	const int num = 10;
	while (dialogs.size() > num)
	{
		delete dialogs.front();
		dialogs.erase(dialogs.begin());
	}
	Rect bottom;
	Point location;
	if (source.operator->())
		location.set_46ca50(source->getPosition());
	if (source.operator->() && opMD_cmap_cec054->unknown8052f0(location))
	{
		bottom.x = (location.x + opMD_cmap_cec054->getOffset_458ef0()->x) * fontCellWidth;
		bottom.y = (location.y + opMD_cmap_cec054->getOffset_458ef0()->y + 1) * fontCellScale;
		bottom.w = fontCellWidth;
		bottom.h = opMD_cmap_cec054->getHeight() * fontCellScale - opMD_bottom_cefac8 - count - bottom.y;
		if (bottom.h <= 0)
			bottom.x = -1;
	}
	else
		bottom.x = -1;
	int counter = source.isValid() ? (source.operator->() ? opMD_map->getPlayer()->unknown5c7fc0(source) : 1) : 3;
	bool chosen = false;
	if (!dialogs.empty() && dialogs.back()->type == counter && !dialogs.back()->alt)
		chosen = true;
	dialogs.push_back(new OpMD_Dialog(new Console(opMD_parent_cec058,size,count,0,opMD_cmap_cec054->getHeight() * fontCellScale - opMD_bottom_cefac8 - count,0,false,-1),teamb_tickCount + 8000,source,counter,chosen,bottom.x != -1 ? new Console(opMD_parent_cec058,bottom,0,false,-1) : NULL,teamb_tickCount + 400));
	dialogs.back()->console->printWrapped_4182b0(size / 2,0,len,count,1,text);
	string last = "A_CMap_MapDialog_" + (counter == 3 ? string("S") : string(opMD_speakerNames_d35be8[counter]));
	string line = "CMap_MapDialog_E_" + (counter == 3 ? string("S") : string(opMD_speakerNames_d35be8[counter]));
	if (chosen)
	{
		last += "_Alt";
		line += "_Alt";
	}
	dialogs.back()->console->animate(last);
	int f;
	OpU8a_lookup1(line,&f);
	OpMD_Engine *id = dialogs.back()->console->engine;
	for (int i = 0; i < count; i++)
	{
		id->unknown50fb50(id,f,&Pos(size / 2,i),&opMD_origin_cfbec0,&Pos(0,i),&opMD_origin_cfbec0,9)->unknown50de10();
		id->unknown50fb50(id,f,&Pos(size / 2 + 1,i),&opMD_origin_cfbec0,&Pos(size,i),&opMD_origin_cfbec0,9)->unknown50de10();
	}
	if (dialogs.back()->bar)
	{
		last = "A_CMap_MapDialog_Bar_" + (counter == 3 ? string("S") : string(opMD_speakerNames_d35be8[counter]));
		if (chosen)
			last += "_Alt";
		dialogs.back()->bar->animate(last);
	}
}
