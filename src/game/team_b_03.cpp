// team_b_03: Console-derived UI classes (0x500000-0x9affff) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial class layouts; virtual names follow src/op/op_v3f.h; TeamB_* are placeholder names.
#include <string>
#include <vector>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &color) throw();	// 0x411e30
};

class Engine { public: bool isRunning(); };	// NOTE: placeholder name (0x50fff0)

class XConsole	// NOTE: partial
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);	// NOTE: placeholder name
	virtual void update();
	virtual void render();	// NOTE: placeholder name

	bool isHidden();
	int getWidth();
	int getHeight();
	XConsole *getParent();
	void updateBase429e30();	// NOTE: placeholder name (XConsole::update body)
	void setChar_417f50(int x, int y, int ch);	// NOTE: placeholder name
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	// NOTE: the two members below are 0x417fc0 / 0x418450 (XConsole::setBack_417fc0 / resetBack_418450 in
	// src/game/cc_r1_07.cpp) under nothrow alias names: LTCG would otherwise infer from those bodies that
	// they can throw and add an EH frame to CGalleryInfoButton's constructor, which the exe does not have.
	void setBackNothrow_417fc0(int x, int y, XColor color, int mode) throw();	// NOTE: placeholder name
	void resetBackNothrow_418450() throw();	// NOTE: placeholder name
	void setForeAll_4183d0(XColor color);	// NOTE: placeholder name
	void resetBack_418450() throw();	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class Console : public XConsole	// NOTE: partial
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	int unknown60;
	Engine *engine;
	void *title;
};

extern bool teamb_d28c8a;	// NOTE: placeholder name (0xd28c8a)

//==================================================================
// CEvolveSlotButton
//==================================================================

extern XColor *opU5s4_color_d2981c;	// NOTE: placeholder name
extern XColor *opU5s4_color_d29758;	// NOTE: placeholder name

class CEvolveSlotButton : public Console	// NOTE: partial
{
public:
	bool unknown98b210();	// NOTE: placeholder name
	void update98b1b0();	// vtable slot 6 (update)
};

void CEvolveSlotButton::update98b1b0()	// 0x98b1b0
{
	engine->isRunning();
	setForeAll_4183d0(unknown98b210() ? *opU5s4_color_d2981c : *opU5s4_color_d29758);
}

//==================================================================
// CGalleryInfoButton
//==================================================================

class CGallery { public: int getKey(Console *item); };
extern CGallery *opU5_gallery_cec040;	// NOTE: placeholder name (0xcec040)
extern XColor *opy7_d2175c;	// NOTE: placeholder name
extern XColor teamb_color_d29804;	// NOTE: placeholder name (0xd29804)

class CGalleryInfoButton : public Console	// NOTE: partial
{
public:
	CGalleryInfoButton(XConsole *parent);
	virtual void update();
};

CGalleryInfoButton::CGalleryInfoButton(XConsole *parent)	// 0x7d69b0
	: Console(parent,parent->getWidth() + 2,parent->getHeight(),-1,0,0,false,-1)
{
	resetBackNothrow_418450();
	if (teamb_d28c8a)
		setBackNothrow_417fc0(0,2,teamb_color_d29804,1);
}

void CGalleryInfoButton::update()	// 0x7d6a30
{
	engine->isRunning();
	if (teamb_d28c8a)
	{
		setChar_417f50(0,2,opU5_gallery_cec040->getKey((Console*)getParent()));
		setFore_417f80(0,2,*opy7_d2175c);
	}
}

//==================================================================
// CAchievements
//==================================================================

bool opr1c_hasPtr_cebd5c();	// NOTE: placeholder name (0x4328a0)
extern int opr4c_bcbe24[];	// NOTE: placeholder name

class TeamB_Achievements : public Console	// NOTE: placeholder name for CAchievements (class declared in other files)
{
public:
	void unknown7f1bd0(int count, int start, bool flag);	// NOTE: placeholder name
	void update7eead0();	// CAchievements vtable slot 6 (update)
};

void TeamB_Achievements::update7eead0()	// 0x7eead0
{
	if (isHidden())
		return;
	switch (unknown60)
	{
		break;	// NOTE: needed for the exe's dead jump after the switch dispatch
	case 1:
		unknown7f1bd0(opr4c_bcbe24[opr1c_hasPtr_cebd5c() != 0],0,true);
		unknown60 = 3;
	case 3:
		engine->isRunning();
	}
	updateBase429e30();
}
