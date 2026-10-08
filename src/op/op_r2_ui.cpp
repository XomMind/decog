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

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);	// 0x46ca20
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

class HProp
{
public:
	int ID;
	HProp() throw();	// 0x9b6590
};
extern int opr2_lineFx_cebfac;	// NOTE: placeholder name
extern int opr2_textFx_cebf18;	// NOTE: placeholder name
extern Pos opr2_fxPos_cfbec0;	// NOTE: placeholder name

class CInfoLine : public Console
{
public:
	CInfoLine(XConsole *parent, int y, int item_, bool effects, string left, string right);	// 0x4ae7f0
	virtual void mouseLeave();	// 0x4aeae0

	int item;	// NOTE: placeholder name
	HProp prop;	// NOTE: placeholder name
};

CInfoLine::CInfoLine(XConsole *parent, int y, int item_, bool effects, string left, string right)
	: Console(parent,parent->getWidth() - 2,1,1,y,0,false,-1)
	, item(item_)
{
	if (effects)
	{
		do
		{
			for (int x = Pos(0x17,0).x; x < Pos(0x17,0).x + 0x16; x++)
				engine->unknown50fb50(engine,opr2_lineFx_cebfac,&Pos(x,Pos(0x17,0).y),&opr2_fxPos_cfbec0,0,0,9)->unknown50de10();
		} while (false);
	}
	if (!left.empty())
	{
		printAligned(0x15,0,2,left);
		do
		{
			for (int x = Pos(0x15 - (left.size() - 1),0).x; x < Pos(0x15 - (left.size() - 1),0).x + left.size(); x++)
				engine->unknown50fb50(engine,opr2_textFx_cebf18,&Pos(x,Pos(0x15 - (left.size() - 1),0).y),&opr2_fxPos_cfbec0,0,0,9)->unknown50de10();
		} while (false);
	}
	if (!right.empty())
	{
		print(0x17,0,right);
		do
		{
			for (int x = Pos(0x17,0).x; x < Pos(0x17,0).x + right.size(); x++)
				engine->unknown50fb50(engine,opr2_textFx_cebf18,&Pos(x,Pos(0x17,0).y),&opr2_fxPos_cfbec0,0,0,9)->unknown50de10();
		} while (false);
	}
}

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
