// op_r2: small UI consoles in 0x490000-0x4c0000 (CInfoText, CInfoSpecial, CInfoButton, ...), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool isActive();
	virtual void refresh();
	virtual bool input(void *event);
	virtual void inputAscii(int key, int modifier);	// NOTE: placeholder name
	virtual void update();
	virtual void render();

	void print(int x, int y, const string &text);
	void printAligned(int x, int y, int align, const string &text);
	int getWidth();	// 0x44b0d0
	void resetBack_418450();	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class Engine
{
public:
	void killGroup(string group);
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();
	void animate(string name);

	int unknown60;
	Engine *engine;
	void *title;
};

//==================================================================
// CInfo sub-consoles
//==================================================================

class CInfoText : public Console
{
public:
	CInfoText(XConsole *parent, int x, int y, int align, const string &text, int value_);	// 0x4ae330

	int value;	// NOTE: placeholder name
};

CInfoText::CInfoText(XConsole *parent, int x, int y, int align, const string &text, int value_)
	: Console(parent,text.size(),1,align == 2 ? x - (text.size() - 1) : x,y,0,false,-1)
{
	value = value_;
	printAligned(align == 2 ? getWidth() - 1 : 0,0,align,text);
}

class CInfoSpecial : public Console
{
public:
	CInfoSpecial(XConsole *parent, int x, int y, int type_, int width, const string &text, int value2_);	// 0x4ae430

	int type;	// NOTE: placeholder name
	int value2;	// NOTE: placeholder name
};

CInfoSpecial::CInfoSpecial(XConsole *parent, int x, int y, int type_, int width, const string &text, int value2_)
	: Console(parent,type_ == 0 ? width : text.size(),1,x,y,0,false,-1)
{
	type = type_;
	value2 = value2_;
	resetBack_418450();
	if (type_ != 0)
		print(0,0,text);
}

class CInfoButton : public Console
{
public:
	CInfoButton(XConsole *parent, int x, int y, int value_, const string &text);	// 0x4ae510
	virtual void mouseLeave();	// 0x4ae7a0

	int value;	// NOTE: placeholder name
};

CInfoButton::CInfoButton(XConsole *parent, int x, int y, int value_, const string &text)
	: Console(parent,text.size() + 2,1,x,y,0,false,-1)
{
	value = value_;
	print(0,0,"[" + text + "]");
}

void CInfoButton::mouseLeave()
{
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_SHEL_HOV_OK");
}

class CInfoLine : public Console
{
public:
	virtual void mouseLeave();	// 0x4aeae0
};

void CInfoLine::mouseLeave()
{
	engine->killGroup("fadein");
	animate("A_CInfoLine_Hov_End");
}

class CMainUiButton : public Console
{
public:
	virtual void mouseLeave();	// 0x4aff80
};

void CMainUiButton::mouseLeave()
{
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_INV_HOV_OK");
}

class CRobotTarget : public Console
{
public:
	virtual void mouseLeave();	// 0x4afb70

	char pad6c[0x7c - 0x6c];
	int invalid;	// NOTE: placeholder name
};

void CRobotTarget::mouseLeave()
{
	if (invalid)
		return;
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_HACK_HOV_OK");
}
