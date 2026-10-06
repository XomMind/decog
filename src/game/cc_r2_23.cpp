// Manual/options UI consoles laid out at 0x7c54f0-0x7c5b8c (CCommandsAdvanced, CManualButton,
//	CManualPageButton, COptionButton, COptionValue).
// NOTE: class layouts are partial; names are placeholders unless stated otherwise (RTTI class names are real).
#include <string>
using namespace std;

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos);	// 0x46ca50
};

class Console;
class COptionValue;
class COptionButton;

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);	// NOTE: placeholder name
	virtual void update();
	virtual void render();	// NOTE: placeholder name

	bool isHidden();	// NOTE: placeholder name
	int getWidth();
	int getHeight();
	XConsole *getParent();	// NOTE: placeholder name
	void print(int x, int y, const string &text);	// NOTE: placeholder name
	void setChar_417f50(int x, int y, int ch);	// NOTE: placeholder name
	void setCharRow_4297f0(int x, int y, int width, int ch);	// NOTE: placeholder name

	char pad4[0x5c];
};

class EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class Engine
{
public:
	void killGroup(string group);
	EngineItem *unknown50fb50(Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name

	char data[0x58];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	void animate(string name);	// NOTE: placeholder name
	void unknown48c3c0(int value);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	void *title;
};

extern bool consoleInputBlocked;	// NOTE: placeholder name
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern int unknown_cef92c;	// NOTE: placeholder name
extern int unknown_cef784;	// NOTE: placeholder name
extern int unknown_cef8ac;	// NOTE: placeholder name
extern int unknown_cef958;	// NOTE: placeholder name
extern int unknown_cef858;	// NOTE: placeholder name
extern int unknown_cf27f4;	// NOTE: placeholder name
extern int unknown_caf128;	// NOTE: placeholder name
extern int unknown_d323c0;	// NOTE: placeholder name
extern Pos unknown_cfbec0;	// NOTE: placeholder name
extern Pos unknown_d2e20c;	// NOTE: placeholder name

class PanelHeight	// NOTE: placeholder name (global at 0xd223f0)
{
public:
	int unknown4189a0();	// NOTE: placeholder name
};
extern PanelHeight unknown_d223f0;	// NOTE: placeholder name

int unknown437190(int a, int b);	// NOTE: placeholder name

class ManualUI	// NOTE: placeholder name (pointer global at 0xcec03c)
{
public:
	int unknown496710();	// NOTE: placeholder name
	XConsole *unknown496730(COptionValue *console);	// NOTE: placeholder name
	void unknown496770(int value);	// NOTE: placeholder name
	void unknown496810();	// NOTE: placeholder name
	unsigned int unknown45b590();	// NOTE: placeholder name
	void unknown7d14d0(int value);	// NOTE: placeholder name
	void unknown7d2030(COptionButton *button, string text);	// NOTE: placeholder name
};
extern ManualUI *unknown_cec03c;	// NOTE: placeholder name

class ManualPage	// NOTE: placeholder name
{
public:
	void unknown7d1740();	// NOTE: placeholder name
	void unknown7d17d0();	// NOTE: placeholder name
};

//==================================================================
// CCommandsAdvanced
//==================================================================

class CCommandsAdvanced : public Console
{
public:
	virtual void open();

	int mode;	// NOTE: placeholder name
};

void CCommandsAdvanced::open()
{
	int mid = getWidth() / 2;	// NOTE: placeholder name
	int y;	// NOTE: placeholder name
	int x;	// NOTE: placeholder name

	if (mode == 5)
		mid += 5;
	do
	{
		for (x = Pos(mid + 2,0).x; x < Pos(mid + 2,0).x + getWidth() - 1 - (mid + 2); x++)
		{
			engine->unknown50fb50(engine,unknown_cef92c,&Pos(x,Pos(mid + 2,0).y),&unknown_cfbec0,NULL,NULL,9)->unknown50de10();
		}
	} while (0);
	do
	{
		engine->unknown50fb50(engine,unknown_cef784,&Pos(mid,0),&unknown_cfbec0,&Pos(0,0),&unknown_cfbec0,9)->unknown50de10();
	} while (0);
	for (y = 0; y < getWidth(); y++)
	{
		engine->unknown50fb50(engine,unknown_cef8ac,&Pos(y,1),&unknown_d2e20c,&Pos(y,getHeight() - 1),&Pos(unknown_d2e20c),9)->unknown50de10();
	}
	unknown48c3c0(unknown_cef958);
}

//==================================================================
// CManualButton
//==================================================================

class CManualButton : public Console
{
public:
	virtual bool input(void *event);

	bool unknown7c56b0();	// NOTE: placeholder name
	void unknown7c56e0();	// NOTE: placeholder name

	int mode;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
};

bool CManualButton::unknown7c56b0()
{
	return unknown_cec03c->unknown496710() == mode - 0x61;
}

void CManualButton::unknown7c56e0()
{
	int len = unknown74 + 2;	// NOTE: placeholder name

	if (!unknown7c56b0())
	{
		setChar_417f50(unknown70 - 1,0,0x5b);
		setChar_417f50(unknown74 + 1,0,0x5d);
		setCharRow_4297f0(len,0,getWidth() - len,0x20);
	}
	else
	{
		setChar_417f50(unknown70 - 1,0,0x20);
		setChar_417f50(unknown74 + 1,0,0x20);
		setCharRow_4297f0(len,0,getWidth() - len,0x81);
	}
}

bool CManualButton::input(void *event)
{
	if (isHidden() || consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	switch (*(int*)event)
	{
	case 0x14:
		if (!unknown7c56b0())
			unknown_cec03c->unknown7d14d0(mode - 0x61);
		return true;
	}
	return false;
}

//==================================================================
// CManualPageButton
//==================================================================

class CManualPageButton : public Console
{
public:
	CManualPageButton(XConsole *parent, bool flag_);
	virtual bool input(void *event);

	bool flag;	// NOTE: placeholder name
};

CManualPageButton::CManualPageButton(XConsole *parent, bool flag_)
	: Console(parent,3,1,unknown437190(0x60,unknown_cf27f4 * unknown_caf128) + 0x3d,flag_ ? unknown_d223f0.unknown4189a0() - 2 : unknown_d323c0 + 2,0,false,-1)
{
	flag = flag_;
	{
		string text("...");
		print(0,0,text);
	}
	unknown48c3c0(unknown_cef858);
}

bool CManualPageButton::input(void *event)
{
	if (isHidden() || consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	switch (*(int*)event)
	{
	case 0x14:
		if (flag)
			((ManualPage*)getParent())->unknown7d1740();
		else
			((ManualPage*)getParent())->unknown7d17d0();
		return true;
	}
	return false;
}

//==================================================================
// COptionButton
//==================================================================

class COptionButton : public Console
{
public:
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);

	char pad6c[0xc];
	int unknown78;	// NOTE: placeholder name
};

bool COptionButton::input(void *event)
{
	if (tickCount < unknown_cec03c->unknown45b590())
		return false;
	if (isHidden() || consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	switch (*(int*)event)
	{
	case 0x14:
		unknown_cec03c->unknown7d2030(this,string(""));
		return true;
	}
	return false;
}

bool COptionButton::mouseEnter()
{
	unknown_cec03c->unknown496770(unknown78);
	animate(string("A_ButtonHover_Begin_MANU_HOV_OK"));
	return true;
}

void COptionButton::mouseLeave()
{
	unknown_cec03c->unknown496810();
	engine->killGroup(string("fadein"));
	animate(string("A_ButtonHover_End_MANU_HOV_OK"));
}

//==================================================================
// COptionValue
//==================================================================

class COptionValue : public Console
{
public:
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
};

bool COptionValue::input(void *event)
{
	return unknown_cec03c->unknown496730(this)->input(event);
}

bool COptionValue::mouseEnter()
{
	return unknown_cec03c->unknown496730(this)->mouseEnter();
}

void COptionValue::mouseLeave()
{
	unknown_cec03c->unknown496730(this)->mouseLeave();
}
