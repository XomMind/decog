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
	void clear();
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
// CPartWeaponHitFactor
//==================================================================

void OpU7_removeChar_408100(string &text, char c);	// NOTE: placeholder name
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
int opr1c_getPercentTier(int value, int max);	// NOTE: placeholder name (0x4347e0)
extern string opu7_hitFactorNames[];	// NOTE: placeholder name (0xd2e7c8)

class CPartWeaponHitFactor : public Console
{
public:
	CPartWeaponHitFactor(XConsole *parent, int x, int width, int type_, string text_);	// 0x88e130
	virtual ~CPartWeaponHitFactor();

	int type;	// NOTE: placeholder name
	string text;	// NOTE: placeholder name
};

CPartWeaponHitFactor::CPartWeaponHitFactor(XConsole *parent, int x, int width, int type_, string text_)
	: Console(parent,width,1,x,0,0,false,-1)
	, type	(type_)
	, text	(text_)
{
	print(0,0,text);
	if (type == 1 && text.find('-') != string::npos)
		animate(opu7_hitFactorNames[1] + "_Neg");
	else if (type == 0)
	{
		string value = text;
		OpU7_removeChar_408100(value,' ');
		OpU7_removeChar_408100(value,'%');
		animate(opu7_hitFactorNames[0] + intToString(opr1c_getPercentTier(stringToInt(value),100)));
	}
	else
		animate(opu7_hitFactorNames[type]);
}

//==================================================================
// CPart (label handling)
//==================================================================

int minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)
extern int opu7_bcc2e0;	// NOTE: placeholder name
extern int opu7_bcc540[];	// NOTE: placeholder name

class HItem
{
public:
	int ID;
};

class CPartLabel : public Console
{
public:
	CPartLabel(XConsole *parent, HItem item_, int x, int type_);	// 0x4a3020
	virtual ~CPartLabel();
	int getType_4a3010();	// NOTE: placeholder name
	void unknown4a6d00();	// NOTE: placeholder name

	int type;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
};

class CPart : public Console
{
public:
	CPartLabel *createLabel(int type);	// NOTE: placeholder name (0x890bb0)
	void moveLabel();	// NOTE: placeholder name (0x890c90)
	void refreshLabel();	// NOTE: placeholder name (0x890cf0)

	HItem item;
	char pad70[0x8c - 0x70];
	int unknown8c;	// NOTE: placeholder name
	CPartLabel *unknown90;	// NOTE: placeholder name
};

CPartLabel *CPart::createLabel(int type)
{
	if (!unknown90)
	{
		unknown90 = new CPartLabel(this,item,minInt(unknown8c + 2,getWidth() - opu7_bcc2e0 - opu7_bcc540[type]),type);
		return unknown90;
	}
	return NULL;
}

void CPart::moveLabel()
{
	if (unknown90)
		unknown90->setPos(minInt(unknown8c + 2,getWidth() - opu7_bcc2e0 - opu7_bcc540[unknown90->type]),0);
}

void CPart::refreshLabel()
{
	if (!unknown90)
		createLabel(0x14);
	if (unknown90->getType_4a3010() == 0x14)
		unknown90->unknown4a6d00();
}

//==================================================================
// CParts
//==================================================================

class OpU7_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void setTarget_44cea0(Console *target);	// NOTE: placeholder name (folded setter)
};
extern OpU7_KeyMap *opu7_keyMap;	// NOTE: placeholder name

class CParts : public Console
{
public:
	virtual ~CParts();	// 0x4a9950
	void open(bool immediate);	// NOTE: placeholder name (0x894120)

	bool unknown6c;	// NOTE: placeholder name
	char pad6d[0xac - 0x6d];
	int unknownAC;	// NOTE: placeholder name
};

void CParts::open(bool immediate)
{
	unknown60 = 1;
	setHidden(false);
	opu7_keyMap->setTarget_44cea0(this);
	unknownAC = 0x20;
	if (unknown6c)
	{
		clearInterior();
		animate("CParts_Content");
	}
	else
	{
		clear();
		if (immediate)
			animate("CParts_Immediate");
		else
			animate("CParts_Border");
		unknown6c = true;
	}
	setScaleX_417b60(1.0f);
	setScaleY_417b80(1.0f);
}
