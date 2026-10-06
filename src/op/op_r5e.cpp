// op_r5e: CShell/CHack/CRobot/CType consoles and helpers in 0x90c700-0x954180 of COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <istream>
#include <algorithm>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos, int dx, int dy);	// 0x4099c0
	Pos(const Pos &pos) throw();	// 0x46ca50
	Pos &operator=(const Pos &pos);
};

struct Point
{
	int x;
	int y;

	Point &operator=(const Point &p);	// 0x46ca50
	void offset_40a2a0(int dx, int dy);	// NOTE: placeholder name
	int randomInRange_40c130();	// NOTE: placeholder name
	Point(int v);	// 0x409990
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();
	Rect(int x_, int y_, int width_, int height_);
	Rect(const Rect &rect);
};

class ConsoleTitle;

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);
	virtual void update();
	virtual void render();

	bool isHidden();
	Point getPos();
	void setPos(const Point &pos);
	int getWidth();	// 0x44b0d0
	int getHeight();
	void print(int x, int y, const string &text);
	void printAligned(int x, int y, int align, const string &text);
	void setCharRow(int x, int y, int width, int ch);
	string getFirstLine();
	void clear(int x, int y, int width, int height);
	void clearInterior();
	void setFore(XColor color);
	void setBack(XColor color);
	void setHidden(bool hidden_);
	void putChar_4180b0(int x, int y, int ch);	// NOTE: placeholder name
	void putChar_418150(int x, int y, int ch, XColor fore, XColor back, bool flag);	// NOTE: placeholder name
	void setForeAll_4183d0(XColor color);	// NOTE: placeholder name
	void setScaleX_417b60(float value);	// NOTE: placeholder name
	void setScaleY_417b80(float value);	// NOTE: placeholder name
	float getScaleX();
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	void setBack_417fc0(int x, int y, XColor color, int mode);	// NOTE: placeholder name
	void setUnknown_451400(int value);	// NOTE: placeholder name (folded setter)
	void unknown429ea0();	// NOTE: placeholder name
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)
	void removeSubconsole(XConsole *console);
	void deleteSubconsolesExcept(XConsole *a, XConsole *b);
	void unknown429f10(int a, int b);	// NOTE: placeholder name
	Rect getRect();
	void deleteSubconsoles();
	Pos localToAbs(Pos pos);
	XConsole *getParent();	// 0x9b8f00
	bool input429d00(void *event);	// NOTE: placeholder name (XConsole::input body)
	XConsole *getParent4();	// NOTE: placeholder name (folded +4 getter)
	void setPos(int x, int y);
	void setBackAll_418410(XColor color);	// NOTE: placeholder name
	void resetBack_418450() throw();	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class OpW7_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class Engine
{
public:
	void killGroup(string group);
	bool update();	// NOTE: placeholder name (0x50fff0)
	void render();	// NOTE: placeholder name (0x5100b0)
	void stopAll();	// NOTE: placeholder name
	OpW7_EngineItem *unknown50fb50(Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void render();
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);
	void setTitle(ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void unknown48c460(int anim, const Pos &pos);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	void *title;
};

int unknown405b40(unsigned char c) throw();	// NOTE: placeholder name

extern bool opw7_d28c8a;	// NOTE: placeholder name
extern int opw7_d316bc;	// NOTE: placeholder name
extern XColor *opw7_cfe674;	// NOTE: placeholder name
extern int opw7_cebd90;	// NOTE: placeholder name
extern Pos opw7_cfbec0;	// NOTE: placeholder name

// DECL-BEGIN
//==================================================================
// shared declarations (CShell family)
//==================================================================

extern unsigned int opw7_tickCount;	// NOTE: placeholder name (0xcaed20)
extern bool opw7_cefb3e;	// NOTE: placeholder name

struct OpR5e_HackState	// NOTE: placeholder name (object at 0xcec024)
{
	int unknown00;	// NOTE: placeholder name
	int unknown04;	// NOTE: placeholder name
	int tracePercent;	// NOTE: placeholder name
};
extern OpR5e_HackState *opw7_cec024;	// NOTE: placeholder name

struct OpR5e_PropInfo	// NOTE: placeholder name (Prop::unknown45cb30)
{
	char pad00[0x30];
	bool unknown30;	// NOTE: placeholder name
	int unknown34;	// NOTE: placeholder name
};

struct OpR5e_PropData	// NOTE: placeholder name
{
	char pad[0xf8];
	int unknownF8;	// NOTE: placeholder name
};

class Entity;

class HEntity
{
public:
	int ID;
	HEntity() throw();
	Entity *operator->() const throw();	// 0x9b6570
};

class OpR5e_Prop	// NOTE: placeholder name
{
public:
	OpR5e_PropData *unknown9b8f00();	// NOTE: placeholder name (ICF'd getter)
	OpR5e_PropInfo *unknown45cb30();	// NOTE: placeholder name
};

class HProp
{
	int ID;
public:
	HProp() throw();	// 0x9b6590
	OpR5e_Prop *operator->() const;	// 0x9b64f0
};

class CTextInput : public Console
{
public:
	void setUnknownBc(int unknownBc_, const string &unknownC0_);	// NOTE: placeholder name (0x48d330)
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);
	char pad6c[0x8c - 0x6c];
};

class CCloseButton : public Console
{
public:
	CCloseButton(XConsole *parent, const XColor &color, int x);
	char pad6c[0x8c - 0x6c];
};

class CShellManual : public Console
{
public:
	CShellManual(XConsole *parent, int y);

	CTextInput *input;	// NOTE: placeholder name
	char pad70[0xc8 - 0x70];
};

bool opq4c_createCodes8ff5e0();	// NOTE: placeholder name
void opr5e_unknown8ff8a0();	// NOTE: placeholder name (0x8ff8a0)
void opr5e_unknown900920(int flag);	// NOTE: placeholder name
extern string gameString_cf4db4;

class CShellButton : public Console
{
public:
	void unknown4b0a20();	// NOTE: placeholder name
	int command;	// NOTE: placeholder name
};

class CShellText : public Console
{
public:
	CShellText(XConsole *parent, const string &text, int unknown6c_);
	void addValue(int value);	// NOTE: placeholder name
	void unknown90b850(bool flag);	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
	vector<CShellButton*> buttons;	// NOTE: placeholder name
};

class CShell : public Console
{
public:
	virtual ~CShell();
	virtual bool input(void *event);
	virtual void update();
	virtual void open();
	virtual void close();
	void scroll(int amount);	// 0x90d0a0
	bool unknown4b0dd0();	// NOTE: placeholder name
	CShellManual *getManual_48f100();	// NOTE: placeholder name
	void unknown90c700();	// NOTE: placeholder name
	void addNew(const string &text, const string &text2, int type, int a, bool b);	// 0x90d550
	void unknown90eb10(const string &text);	// NOTE: placeholder name
	void unknown90ec30(string text);	// NOTE: placeholder name
	void unknown90ed30(const string &text, int unknown6c, bool flag, bool log);	// NOTE: placeholder name
	void unknown90eec0(vector<int> &chars, int unknown6c, vector<XColor> *fore, vector<XColor> *back);	// NOTE: placeholder name
	void unknown90f990(const string &text);	// NOTE: placeholder name
	void unknown9397c0(int command);	// NOTE: placeholder name
	void unknown939890();	// NOTE: placeholder name

	char pad6c[0x70 - 0x6c];
	HProp prop;	// NOTE: placeholder name
	vector<CShellText*> lines;	// NOTE: placeholder name
	int scrollOffset;	// NOTE: placeholder name
	char pad88[0xa4 - 0x88];
	CShellManual *manual;	// NOTE: placeholder name
};
extern CShell *opw7_cec100;	// NOTE: placeholder name

class OpR5e_Unk8fd5d0 : public Console	// NOTE: placeholder name (object at 0xcec0fc)
{
public:
	void unknown8fd5d0();	// NOTE: placeholder name
};
extern OpR5e_Unk8fd5d0 *opr5e_cec0fc;	// NOTE: placeholder name

class OpR5e_Obj138	// NOTE: placeholder name (object at 0xcec138)
{
public:
	void unknown96ada0(bool flag);	// NOTE: placeholder name
};
extern OpR5e_Obj138 *opr5e_cec138;	// NOTE: placeholder name

class OpR5e_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	bool getField_41a6e0();	// NOTE: placeholder name
	void unknown432170(bool value);	// NOTE: placeholder name
	bool isIn(const Rect &rect);	// NOTE: placeholder name (0x41a730)
	void setPos_41a910(const Pos &pos);	// NOTE: placeholder name
};
extern Console *opq4c_cec104;	// NOTE: placeholder name
extern OpR5e_Mouse *opr5e_mouse;	// NOTE: placeholder name

class OpR5e_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void unknown416640();	// NOTE: placeholder name
	void unknown4162e0(int a, int b);	// NOTE: placeholder name
};
extern OpR5e_KeyMap *opr5e_keyMap;	// NOTE: placeholder name

class OpW5_Unk49b870	// NOTE: placeholder name
{
public:
	void reset();	// NOTE: placeholder name
};
extern OpW5_Unk49b870 opr5e_d1d9c0;	// NOTE: placeholder name

extern XConsole *opr5e_cec0b0;	// NOTE: placeholder name (CLog)
extern XConsole *opr5e_cec054;	// NOTE: placeholder name (MapView)
extern XConsole *opr5e_cec058;	// NOTE: placeholder name


class OpR5e_LogMsgs	// NOTE: placeholder name (object at 0xcec0b4)
{
public:
	void scrollToEnd();
};
extern OpR5e_LogMsgs *opr5e_logMsgs;	// NOTE: placeholder name (0xcec0b4)

class OpR5e_LogConsole	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void unknown8758d0(int value);	// NOTE: placeholder name
};
extern OpR5e_LogConsole *opr5e_cec058log;	// NOTE: placeholder name

bool opr5e_logMessage(int id, const string &text, const string *b, int c, HProp d, HProp e, int f, int g);	// NOTE: placeholder name (0x5111e0)
extern int opr5e_bcd8f8[];	// NOTE: placeholder name
void opr5e_insertAt_9dbdc0(vector<CShellText*> &v, int index, CShellText *value);	// NOTE: placeholder name
void opr5e_replaceAll_407f00(string &text, string from, string to);	// NOTE: placeholder name
char opr5e_randomChar(const string &chars);	// NOTE: placeholder name (0x4085b0)

class OpR5e_Unk69b8a0	// NOTE: placeholder name (object at 0xcf6888)
{
public:
	int unknown69b8a0(int id);	// NOTE: placeholder name
};
extern OpR5e_Unk69b8a0 opr5e_cf6888;	// NOTE: placeholder name
extern vector<vector<string> > opr5e_d21b10;	// NOTE: placeholder name
extern string opr5e_d226cc;	// NOTE: placeholder name
extern int opr5e_d316bc;	// NOTE: placeholder name

void opr5e_wrapText_408e60(string text, int width, vector<string> *out);	// NOTE: placeholder name

#define OPR5E_LOG(id,text) do { if (opr5e_logMessage(id,text,0,0,HProp(),HProp(),0,0)) opr5e_cec058log->unknown8758d0(true); opr5e_logMsgs->scrollToEnd(); } while (0)	// NOTE: placeholder macro

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);
	char pad6c[0x88 - 0x6c];
};

string intToString(int value);
int opr5e_getPercentTier(int value, int max);	// NOTE: placeholder name (0x4347e0)
extern string opr5e_d1e248[];	// NOTE: placeholder name
extern string opr5e_d01740[];	// NOTE: placeholder name
extern int opr5e_cebd94[];	// NOTE: placeholder name

class CHack : public Console
{
public:
	CHack(XConsole *parent);
	virtual ~CHack();
	virtual bool input(void *event);
	virtual void update();
	virtual void close();
	virtual void trigger(const string &command, int value);
	void unknown93aae0();	// NOTE: placeholder name
	void unknown942780(int x);	// NOTE: placeholder name
	void unknown942a60();	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	CCloseButton *closeButton;	// NOTE: placeholder name
	bool unknown78;	// NOTE: placeholder name
	char pad79[0x7c - 0x79];
	int unknown7c;	// NOTE: placeholder name
	HProp unknown80;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	int unknown88;	// NOTE: placeholder name
	CText *unknown8c;	// NOTE: placeholder name
	int unknown90;	// NOTE: placeholder name
	XConsole *unknown94;	// NOTE: placeholder name
};
extern CHack *opq4e_cec0f8;	// NOTE: placeholder name
extern Rect opr5e_d2a88c;	// NOTE: placeholder name
extern XColor *opr5e_cf1f2c;	// NOTE: placeholder name
extern bool opq4c_cefa5f;	// NOTE: placeholder name (console input blocked)

class OpR5e_Event	// NOTE: placeholder name
{
public:
	int type;
};

// DECL-END

//==================================================================
// CShell
//==================================================================

void CShell::unknown9397c0(int command)
{
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		if (lines[i])
		{
			for (unsigned int j = 0; j < lines[i]->buttons.size(); j++)
			{
				if (lines[i]->buttons[j]->command == command)
					lines[i]->buttons[j]->unknown4b0a20();
			}
		}
	}
}

void CShell::unknown939890()
{
	int index;
	if (scrollOffset + lines.size() + 1 < getHeight() - 2)
		index = scrollOffset + lines.size() + 1;
	else
	{
		lines.push_back(NULL);
		lines.push_back(NULL);
		scroll(99999);
		lines.pop_back();
		lines.pop_back();
		index = getHeight() - 2;
	}
	manual = new CShellManual(this,index);
	if (opq4c_createCodes8ff5e0())
		manual->input->setUnknownBc((int)opr5e_unknown8ff8a0,gameString_cf4db4);
}

bool CShell::input(void *event)
{
	if (isHidden() || opq4c_cefa5f)
		return false;
	if (input429d00(event))
		return true;
	switch (((OpR5e_Event*)event)->type)
	{
	case 0xf9:
		if (scrollOffset > 0)
			scroll(-3);
		return true;
	case 0xfa:
		if (lines.size() + scrollOffset >= getHeight() - 2)
			scroll(3);
		return true;
	case 0xfb:
		if (scrollOffset > 0)
			scroll(-(getHeight() - 2));
		return true;
	case 0xfc:
		if (lines.size() + scrollOffset >= getHeight() - 2)
			scroll(getHeight() - 2);
		return true;
	case 0xfd:
		if (scrollOffset > 0)
			scroll(-99999);
		return true;
	case 0xfe:
		if (lines.size() + scrollOffset >= getHeight() - 2)
			scroll(99999);
		return true;
	case 0xf7:
	case 0xff:
		if (unknown60 != 4)
			opq4e_cec0f8->close();
		return true;
	default:
		return false;
	}
}

//==================================================================
// CHack
//==================================================================

CHack::CHack(XConsole *parent)
	: Console(parent,opr5e_d2a88c,0,true,0xf)
	, unknown78	(false)
	, unknown94	(NULL)
{
	setTitle(new ConsoleTitle(this,"/ H A C K I N G /",0,0));
	unknown6c = false;
	closeButton = new CCloseButton(this,*opr5e_cf1f2c,14);
}

void CHack::update()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
		break;	// NOTE: unreachable, but present in the original codegen
	case 1:
		if (!engine->update())
			unknown60 = 3;
		break;
	case 3:
		if (unknown6c)
		{
			if (!unknown78)
				closeButton->setHidden(false);
			unknown78 = true;
		}
		break;
	case 4:
		engine->update();
		if (getScaleX() != 0)
		{
			if (opw7_tickCount - unknown70 >= 500)
			{
				setScaleX_417b60(0);
				setScaleY_417b80(0);
			}
			else
			{
				setScaleX_417b60(1.0 - (double)(opw7_tickCount - unknown70) / 500.0);
				setScaleY_417b80(1.0 - (double)(opw7_tickCount - unknown70) / 500.0);
				break;
			}
		}
		engine->stopAll();
		unknown60 = 0;
		setHidden(true);
		opr5e_keyMap->unknown416640();
		setHidden(true);
		break;
	}
	updateBase429e30();
}

void CHack::close()
{
	if (opw7_cefb3e)
	{
		delete opw7_cec024;
		opw7_cec024 = NULL;
	}
	if (opw7_cec100 && opw7_cec100->unknown4b0dd0())
	{
		unknown93aae0();
		opr5e_cec138->unknown96ada0(true);
		return;
	}
	unknown60 = 4;
	unknown429f10(0,0);
	engine->stopAll();
	deleteSubconsolesExcept((XConsole*)title,closeButton);
	unknown70 = opw7_tickCount;
	animate("A_BlockFadeInterior");
	opr5e_cec0b0->removeSubconsole(unknown94);
	unknown94 = NULL;
	opr5e_cec054->setHidden(false);
	opr5e_cec058->setHidden(false);
	if (unknown80.operator->())
	{
		unknown80->unknown45cb30()->unknown30 = unknown84 == -1;
		unknown80->unknown45cb30()->unknown34 = unknown88;
	}
	if (opr5e_cec0fc)
		opr5e_cec0fc->close();
	if (opw7_cec100)
	{
		if (opw7_cec100->getManual_48f100())
			opr5e_unknown900920(1);
		opw7_cec100->close();
	}
}

void CHack::unknown93aae0()
{
	if (opw7_cefb3e)
	{
		delete opw7_cec024;
		opw7_cec024 = NULL;
	}
	unknown60 = 0;
	engine->stopAll();
	opr5e_cec0b0->removeSubconsole(unknown94);
	unknown94 = NULL;
	opr5e_cec054->setHidden(false);
	opr5e_cec058->setHidden(false);
	if (unknown80.operator->())
	{
		unknown80->unknown45cb30()->unknown30 = unknown84 == -1;
		unknown80->unknown45cb30()->unknown34 = unknown88;
	}
	if (opr5e_cec0fc)
		opr5e_cec0fc->unknown8fd5d0();
	if (opw7_cec100)
	{
		if (opw7_cec100->getManual_48f100())
			opr5e_unknown900920(1);
		opw7_cec100->unknown90c700();
	}
	opr5e_keyMap->unknown416640();
	setHidden(true);
}

bool CHack::input(void *event)
{
	if (isHidden() || opq4c_cefa5f)
		return false;
	if (input429d00(event))
		return true;
	switch (((OpR5e_Event*)event)->type)
	{
	case 0xf8:
		opr5e_mouse->unknown432170(!opr5e_mouse->getField_41a6e0());
		opw7_d28c8a = !opw7_d28c8a;
		opr5e_d1d9c0.reset();
		return true;
	case 0xf7:
	case 0xff:
		if (unknown60 != 4 && unknown78)
			close();
		return true;
	default:
		return false;
	}
}

//==================================================================
// CShell lines
//==================================================================

void CShell::unknown90eb10(const string &text)
{
	opr5e_insertAt_9dbdc0(lines,lines.size() - 1,new CShellText(this,text,3));
	lines[lines.size() - 2]->unknown90b850(true);
	if (lines.size() >= getHeight() - 1)
		scrollOffset = lines.size() - (getHeight() - 1);
	scroll(0);
}

void CShell::unknown90ec30(string text)
{
	text.insert(0,1,'[');
	while (text.back() == '.')
		text.pop_back();
	text += "]";
	vector<string> parts;
	opr5e_wrapText_408e60(text,46,&parts);
	for (unsigned int i = 0; i < parts.size(); i++)
		unknown90ed30(parts[i],4,true,false);
}

void CShell::unknown90ed30(const string &text, int unknown6c, bool flag, bool log)
{
	CShellText *line = new CShellText(this,text,unknown6c);
	if (flag && !lines.empty())
		opr5e_insertAt_9dbdc0(lines,lines.size() - 1,line);
	else
	{
		lines.push_back(line);
		if (log)
			OPR5E_LOG(opr5e_bcd8f8[unknown6c],text);
	}
	line->unknown90b850(true);
	if (lines.size() >= getHeight() - 1)
		scrollOffset = lines.size() - (getHeight() - 1);
	scroll(0);
}

void CShell::unknown90eec0(vector<int> &chars, int unknown6c, vector<XColor> *fore, vector<XColor> *back)
{
	string text;
	CShellText *line = new CShellText(this,text,unknown6c);
	lines.push_back(line);
	for (unsigned int i = 0; i < chars.size(); i++)
		line->putChar_4180b0(i,0,chars[i]);
	line->unknown90b850(true);
	if (fore)
	{
		for (unsigned int j = 0; j < chars.size(); j++)
		{
			line->setFore_417f80(j,0,(*fore)[j]);
			line->setBack_417fc0(j,0,(*back)[j],1);
		}
		line->engine->stopAll();
	}
	if (lines.size() >= getHeight() - 1)
		scrollOffset = lines.size() - (getHeight() - 1);
	scroll(0);
}

void CShell::unknown90f990(const string &text)
{
	if (text.empty())
		addNew(string(""),string("*random keyboard noises*"),5,-1,false);
	else
		addNew(string(""),text,5,-1,false);
}

//==================================================================
// CShell helpers
//==================================================================

void opr5e_unknown91c850(int id, int *state, int *mode, const string &text)	// NOTE: placeholder name
{
	if (*mode == 2 && *state != 3)
	{
		int index = opr5e_cf6888.unknown69b8a0(id);
		if (index != -1)
		{
			string line = opr5e_d21b10[id][index];
			opr5e_replaceAll_407f00(line,opr5e_d226cc,text);
			opw7_cec100->unknown90f990(line);
			*mode = 3;
		}
	}
}

int opr5e_unknown91c960(string &out, int offset)	// NOTE: placeholder name
{
	int lineCount = 0;
	string chars("ABCDEFGHIJKLMNOPQRSTUVWXYZ09123456789");
	for (int i = 0; i < opw7_cec100->getHeight() - 3 - offset; i++)
	{
		for (int j = 0; j < opr5e_d316bc - 4; j++)
			out.push_back(opr5e_randomChar(chars));
		out += "\n";
		lineCount++;
	}
	return lineCount;
}

//==================================================================
// CHack
//==================================================================

void CHack::unknown942780(int x)
{
	if (unknown8c)
		removeSubconsole(unknown8c);
	int tier = opr5e_getPercentTier(unknown84,100);
	unknown8c = new CText(this,Pos(x,unknown7c),opr5e_d1e248[tier] + " (" + intToString(unknown84) + "%)",0,0,-1);
	unknown8c->unknown48c3c0(opr5e_cebd94[tier]);
}

void CHack::unknown942a60()
{
	if (!unknown90)
		unknown7c += 2;
	CText *text = new CText(this,Pos(2,unknown7c)," " + opr5e_d01740[unknown80->unknown9b8f00()->unknownF8] + " CRASHED ",0,0,-1);
	text->animate("A_CHack_Locked");
}

//==================================================================
// CRobot
//==================================================================

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Pos pos;
};

class OpR5e_Message	// NOTE: placeholder name (ctor 0x510d20)
{
public:
	OpR5e_Message(int type, int a, int b, int c, HProp d, HProp e);
	char pad[0x20];
};

class OpR5e_MessageLog : public Console	// NOTE: placeholder name (object at 0xcec0f4)
{
public:
	void add(OpR5e_Message *message);	// NOTE: placeholder name
};
extern OpR5e_MessageLog *opr5e_cec0f4;	// NOTE: placeholder name

class OpR5e_AudioMixer	// NOTE: placeholder name (object at 0xcefa90)
{
public:
	void unknown41a210(int index);	// NOTE: placeholder name
};
extern OpR5e_AudioMixer *opr5e_audioMixer;	// NOTE: placeholder name

class OpR5e_Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	void unknown464710(int value);	// NOTE: placeholder name
	HEntity getPlayer();	// 0x4630f0
};
extern OpR5e_Map *opr5e_world;	// NOTE: placeholder name

class Item
{
public:
	int unknown457fb0();	// NOTE: placeholder name
	int unknown45cb30();	// NOTE: placeholder name (ICF'd getter)
	void unknown44fc60(int value);	// NOTE: placeholder name (ICF'd setter)
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown57a190(HEntity entity, int a, int b, int c);	// NOTE: placeholder name
	void setActive(bool active);
	int unknown9fcd80();	// NOTE: placeholder name (ICF'd getter)
	int getNestedField();	// 0x457820
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
	const string &unknown457860();	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	Item *operator->() const;	// 0x9b65b0
};

class OpR5e_PlayerData	// NOTE: placeholder name (object at 0xcf45d8)
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern OpR5e_PlayerData opr5e_cf45d8;	// NOTE: placeholder name

class OpR5e_Parts	// NOTE: placeholder name (CParts object at 0xcec088)
{
public:
	void unknown896a80(HItem item);	// NOTE: placeholder name
};
extern OpR5e_Parts *opr5e_cec088;	// NOTE: placeholder name

class GM
{
public:
	void addItemAttachCount(int itemID, int count, bool force);	// NOTE: placeholder parameter names
};
extern GM opr5e_gm;	// NOTE: placeholder name (0xd25628)

extern int opr5e_b97d38[];	// NOTE: placeholder name (per-hack cost table)
extern vector<int> opr5e_cf47cc;	// NOTE: placeholder name

class CRobotTarget : public Console
{
public:
	virtual bool input(void *event);

	bool unknown6c;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
	int unknown78;	// NOTE: placeholder name
	int invalid;	// NOTE: placeholder name
};

class CRobotManual : public Console
{
public:
	CRobotManual(XConsole *parent, const Rect &rect, const Rect &rect2);

	CTextInput *textInput;	// NOTE: placeholder name
	char pad70[0xc0 - 0x70];
};

void opr5e_unknown942d40(bool flag);	// NOTE: placeholder name
void opr5e_unknown4541b0(int a, int b, int c);	// NOTE: placeholder name (sound)

class CRobot : public Console
{
public:
	virtual bool input(void *event);
	virtual void inputMouse(int a, int b);
	virtual void close();
	void unknown9471d0(HEntity entity, int type, string text);	// NOTE: placeholder name
	void unknown946990();	// NOTE: placeholder name
	void unknown953c70();	// NOTE: placeholder name
	void unknown946da0(int type);	// NOTE: placeholder name

	unsigned int unknown6c;	// NOTE: placeholder name
	char pad70[0x74 - 0x70];
	HEntity entity;	// NOTE: placeholder name
	char pad78[0x88 - 0x78];
	vector<CRobotTarget*> targets;	// NOTE: placeholder name
	vector<HItem> unknown98;	// NOTE: placeholder name
	vector<HItem> unknowna8;	// NOTE: placeholder name
	CRobotManual *manual;	// NOTE: placeholder name
	unsigned int unknownbc;	// NOTE: placeholder name
	unsigned int unknownc0;	// NOTE: placeholder name
};

void CRobot::close()
{
	opr5e_audioMixer->unknown41a210(13);
	if (manual)
		opr5e_unknown942d40(true);
	if (unknown60 == 4)
		return;
	unknown60 = 4;
	unknown429f10(0,0);
	deleteSubconsoles();
	opr5e_keyMap->unknown4162e0(14,0);
	unknown6c = opw7_tickCount;
	animate("A_BlockFadeVis");
	opr5e_world->unknown464710(2);
}

void CRobot::unknown946990()
{
	opr5e_audioMixer->unknown41a210(13);
	if (manual)
		opr5e_unknown942d40(true);
	unknown60 = 0;
	opr5e_keyMap->unknown416640();
	getParent()->removeSubconsole(this);
	opr5e_world->unknown464710(2);
}

bool CRobot::input(void *event)
{
	if (isHidden() || opq4c_cefa5f)
		return false;
	if (input429d00(event))
		return true;
	switch (((OpR5e_Event*)event)->type)
	{
	case 5:
		if (manual)
		{
			if (opq4c_cec104 && opr5e_mouse->isIn(opq4c_cec104->getRect()))
				return true;
			opr5e_unknown942d40(true);
			unknownbc = opw7_tickCount + 200;
		}
		return true;
	case 0xff:
		if (!manual && unknown60 != 4)
		{
			if (opw7_tickCount > unknownc0 + 3000)
			{
				unknownc0 = opw7_tickCount;
				opr5e_cec0f4->add(new OpR5e_Message(0xc1,0,0,0,HProp(),HProp()));
			}
			else if (opw7_tickCount < unknownc0 + 1000)
				return true;
			else
				unknown946990();
		}
		return true;
	default:
		return false;
	}
}

void CRobot::inputMouse(int a, int b)
{
	if (opw7_tickCount < unknownbc)
		return;
	switch (b)
	{
	case 1:
		a += 0x20;
		for (unsigned int i = 0; i < targets.size(); i++)
		{
			if (targets[i]->unknown78 == a && targets[i]->invalid == 0)
			{
				opr5e_mouse->setPos_41a910(Pos(targets[i]->localToAbs(Pos(0,0)),7,0));
				targets[i]->input(&XEvent(0xf7));
				break;
			}
		}
		break;
	case 0:
		for (unsigned int i = 0; i < targets.size(); i++)
		{
			if (targets[i]->unknown78 == a)
			{
				if (targets[i]->invalid == 0)
					unknown9471d0(entity,targets[i]->type,"");
				break;
			}
		}
		break;
	}
}

void CRobot::unknown953c70()
{
	Rect rect2;
	Rect rect;
	rect2.width = 39;
	rect2.height = 4;
	rect2.x = getWidth();
	rect2.y = getHeight() - rect2.height;
	rect.width = rect2.width - 4;
	rect.height = 1;
	rect.x = rect2.x + 2;
	rect.y = rect2.y + 2;
	opr5e_unknown4541b0(39,0,0);
	manual = new CRobotManual(this,rect,rect2);
	if (opq4c_createCodes8ff5e0())
		manual->textInput->setUnknownBc((int)opr5e_unknown8ff8a0,gameString_cf4db4);
}

void CRobot::unknown946da0(int type)
{
	if (opr5e_b97d38[type] > 0)
	{
		int cost = opr5e_b97d38[type];
		for (int i = unknown98.size() - 1; i >= 0; i--)
		{
			if (unknown98[i]->unknown457fb0() == 3)
				opr5e_cf45d8.unknown77fbc0(0x69);
			if (cost >= unknown98[i]->unknown45cb30())
			{
				cost -= unknown98[i]->unknown45cb30();
				unknown98[i]->unknown57dbe0(1,0,9,1);
			}
			else
			{
				unknown98[i]->unknown44fc60(unknown98[i]->unknown45cb30() - cost);
				opr5e_cec088->unknown896a80(unknown98[i]);
				cost = 0;
			}
			if (cost == 0)
				break;
		}
		if (cost)
		{
			for (int j = unknowna8.size() - 1; j >= 0; j--)
			{
				OPR5E_LOG(0x2a4,unknowna8[j]->getName(0,0));
				if (cost >= unknowna8[j]->unknown45cb30())
				{
					cost -= unknowna8[j]->unknown45cb30();
					unknowna8[j]->unknown57dbe0(1,0,9,1);
				}
				else
				{
					unknowna8[j]->unknown44fc60(unknowna8[j]->unknown45cb30() - cost);
					unknowna8[j]->unknown57a190(opr5e_world->getPlayer(),2,1,0);
					unknowna8[j]->setActive(true);
					opr5e_cf47cc.push_back(unknowna8[j]->unknown9fcd80());
					opr5e_gm.addItemAttachCount(unknowna8[j]->getNestedField(),1,0);
					opr5e_cec088->unknown896a80(unknowna8[j]);
					cost = 0;
				}
				if (cost == 0)
					break;
			}
		}
	}
}

//==================================================================
// CRobot hack list
//==================================================================

class HGroup	// NOTE: placeholder name
{
public:
	int ID;
	class Group *operator->() const;	// 0x9b7250
};

class Group	// NOTE: placeholder name
{
public:
	int unknown9b4350();	// NOTE: placeholder name (ICF'd getter)
};

struct OpR5e_EntityData	// NOTE: placeholder name
{
	char padAc[0xac];
	int unknownAc;	// NOTE: placeholder name
};

struct OpR5e_EntityEffect	// NOTE: placeholder name
{
	char pad[4];
};

class Entity
{
public:
	HGroup getGroup();
	int getAiType();	// 0x45a2a0
	int getFaction();	// 0x45a2c0
	OpR5e_EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	unsigned int unknown5cb930(vector<HItem> *out);	// NOTE: placeholder name
	OpR5e_EntityData *unknown9b4350();	// NOTE: placeholder name (ICF'd getter)
};

extern int opr5e_b97ae8[];	// NOTE: placeholder name
extern int opr5e_b97c10[];	// NOTE: placeholder name
extern int opr5e_bba058[];	// NOTE: placeholder name

void opr5f_unknown953d90(HEntity entity, vector<unsigned int> *hacks)	// NOTE: placeholder name
{
	hacks->push_back(0);
	int groupType = entity->getGroup()->unknown9b4350();
	bool flag = false;
	switch (entity->getAiType())
	{
	case 1:
		flag = entity->unknown9b4350()->unknownAc == 0;
		if (!flag && groupType == 3 && entity->getFaction() == 0x19)
		{
			vector<HItem> items;
			opr5e_world->getPlayer()->unknown5cb930(&items);
			for (unsigned int i = 0; i < items.size(); i++)
			{
				if (items[i]->unknown457860() == "Relay Coupler [Programmer]")
				{
					flag = true;
					break;
				}
			}
		}
		break;
	case 2:
		if (groupType == 3 && !entity->unknown45ac40(0x25))
		{
			vector<HItem> items;
			opr5e_world->getPlayer()->unknown5cb930(&items);
			for (unsigned int i = 0; i < items.size(); i++)
			{
				if (items[i]->unknown457860() == "Relay Coupler [Proto]")
				{
					flag = true;
					break;
				}
			}
		}
		break;
	}
	if (flag)
	{
		for (int i = 1; i < 0x48; i++)
		{
			if (entity->getFaction() == 0x1d)
			{
				if (groupType != 5)
					continue;
			}
			else
			{
				switch (opr5e_b97ae8[i])
				{
				case 0:
					if (groupType != 3)
						continue;
					break;
				case 1:
					if (groupType != 4)
						continue;
					break;
				case 2:
					if (groupType != 3 && groupType != 4)
						continue;
					break;
				case 3:
					continue;
				}
			}
			if (opr5e_b97c10[i] == 100)
			{
				if (groupType == 4 && (i == 0x43 || i == 0x45))
					hacks->push_back(i);
				else if (groupType == 3 && (i == 0x44 || i == 0x46))
					hacks->push_back(i);
			}
			else if (opr5e_b97c10[i] == 0x61
				|| opr5e_b97c10[i] == entity->getFaction()
				|| (opr5e_b97c10[i] == 0x62 && groupType == 4 && opr5e_bba058[entity->getFaction()] < 6)
				|| (opr5e_b97c10[i] == 0x63 && groupType == 3 && opr5e_bba058[entity->getFaction()] >= 6 && entity->getFaction() != 0x14 && entity->getFaction() != 6))
				hacks->push_back(i);
		}
	}
}
