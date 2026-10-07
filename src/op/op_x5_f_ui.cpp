// op_x5_f_ui: CWorldMapInfo ctor, CUfdArea ctor and neighbouring console members of COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
#include "../engine/xcolor.h"
using namespace std;

//==================================================================
// engine-side declarations (copied from op_q4b.cpp, extended)
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos();	// 0x453b40
	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos) throw();	// 0x46ca50
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(const Rect &rect);	// 0x40a720
};

struct XEvent;	// NOTE: placeholder name

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event);
	virtual void inputKey(int key, int mode);	// NOTE: placeholder name
	virtual void update();
	virtual void render();	// NOTE: placeholder name

	int getWidth();	// 0x44b0d0
	void setHidden(bool hidden) throw();	// NOTE: placeholder name
	void setForeAllNothrow_4183d0(XColor color) throw();	// NOTE: 0x4183d0 (setFgColor) under a nothrow alias name, see resetBackNothrow_418450
	void resetBackNothrow_418450() throw();	// NOTE: 0x418450 under a nothrow alias name (LTCG must see it as nothrow: the exe ctor has no EH frame)

	char pad04[0x60 - 0x04];
};

class ConsoleTitle;

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);	// NOTE: placeholder name

	void setTitle(ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void animate(string name);	// NOTE: placeholder name

	int unknown60;	// NOTE: placeholder name
	class OpX5F_Engine *engine;	// NOTE: placeholder name
	ConsoleTitle *title;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);	// 0x48c710

	char pad6c[0x8c - 0x6c];
};

class CCloseButton : public Console
{
public:
	CCloseButton(XConsole *parent, const XColor &color, int unknown);	// 0x48d4a0 (NOTE: placeholder parameter names)

	char pad6c[0x8c - 0x6c];
};

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);

	char pad6c[0x88 - 0x6c];
};

class HEntity
{
public:
	HEntity();
	int ID;
};

class RNG
{
public:
	int rangeIntNothrow_406d70(float a, float b) throw();	// NOTE: 0x406d70 (RNG::rangeInt) under a nothrow alias name, see resetBackNothrow_418450
};
extern RNG rng;	// 0xd30908

extern unsigned int opx5f_tickCount;	// NOTE: placeholder name (0xcaed20)

//==================================================================
// CUfdArea
//==================================================================

extern unsigned int opx5f_bce9a0;	// NOTE: placeholder name
extern XColor *opx5f_cfe674;	// NOTE: placeholder name
extern vector<vector<int> > opx5f_cf670c;	// NOTE: placeholder name

class CUfdArea : public Console
{
public:
	CUfdArea(XConsole *parent, int value_, const Pos &size, int layer);	// NOTE: placeholder parameter names
	virtual void update();

	int value;	// NOTE: placeholder name
	unsigned int unknown70;	// NOTE: placeholder name
	unsigned int unknown74;	// NOTE: placeholder name
	bool unknown78;	// NOTE: placeholder name
	int unknown7c;	// NOTE: placeholder name
};

CUfdArea::CUfdArea(XConsole *parent, int value_, const Pos &size, int layer)
	: Console(parent,0x19,2,size.x,size.y,4,true,layer)
{
	value = value_;
	unknown78 = false;
	setForeAllNothrow_4183d0(*opx5f_cfe674);
	resetBackNothrow_418450();
	unknown70 = opx5f_tickCount + opx5f_bce9a0;
	unknown74 = rng.rangeIntNothrow_406d70(0,(float)opx5f_bce9a0) + opx5f_tickCount;
	unknown7c = opx5f_cf670c[value].front();
}

//==================================================================
// CWorldMapInfo
//==================================================================

extern XColor *opx5f_cf1f2c;	// NOTE: placeholder name

class CWorldMapInfo : public Console
{
public:
	CWorldMapInfo(XConsole *parent, int x, int y);	// NOTE: placeholder parameter names
	virtual ~CWorldMapInfo();	// defined in op_w7

	CCloseButton *closeButton;	// NOTE: placeholder name
	HEntity entity;	// NOTE: placeholder name
	vector<Console*> lines;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	int unknown88;	// NOTE: placeholder name
};

CWorldMapInfo::CWorldMapInfo(XConsole *parent, int x, int y)
	: Console(parent,0x15,6,x,y,2,false,-1)
{
	string name = "/ AREA /";
	setTitle(new ConsoleTitle(this,name,2,4));
	animate("CWorldMapInfo_Border");
	unknown60 = 3;
	closeButton = new CCloseButton(this,*opx5f_cf1f2c,0x1e);
	closeButton->setHidden(false);
	CText *label = new CText(this,Pos(1,3),"DEPTH:",2,0,-1);
	unknown84 = label->getWidth() + 2;
	label->animate("A_CWorldMapInfo_Label");
	label = new CText(this,Pos(1,4),"UNVISITED:",2,0,-1);
	unknown88 = label->getWidth() + 2;
	label->animate("A_CWorldMapInfo_Label");
}
