// op_w7: CShell*/CHack/CRobot/CType/CEvolve*/CWorldMap* consoles and helpers (0x4b0000-0x4d0000), Beta 17.1.
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
	void update();	// NOTE: placeholder name (0x50fff0)
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
int charToDigit_405b40(char c);	// 0x405b40 (team_a_03.cpp; defined, so LTCG proves it nothrow)

class OpW7_Unk4afe50	// NOTE: placeholder name (object at 0xcec0fc)
{
public:
	bool testField();	// NOTE: placeholder name (0x4afe50)
	class HProp getHandle_4aeb30();	// NOTE: placeholder name
};
extern OpW7_Unk4afe50 *opw7_cec0fc;	// NOTE: placeholder name

extern bool opw7_d28c8a;	// NOTE: placeholder name
extern int opw7_d316bc;	// NOTE: placeholder name
extern XColor *opw7_cfe674;	// NOTE: placeholder name
extern int opw7_cebd90;	// NOTE: placeholder name
extern Pos opw7_cfbec0;	// NOTE: placeholder name

//==================================================================
// CShellManual
//==================================================================

class CTextInput;
class CShellManual : public Console
{
public:
	CShellManual(XConsole *parent, int y);

	CTextInput *input;	// NOTE: placeholder name
	vector<int> unknown70;	// NOTE: placeholder name
	string unknown80;	// NOTE: placeholder name
	vector<int> unknown9c;	// NOTE: placeholder name
	int unknownac;	// NOTE: placeholder name
	vector<int> unknownb0;	// NOTE: placeholder name
	int unknownc0;	// NOTE: placeholder name
	int unknownc4;	// NOTE: placeholder name
};

//==================================================================
// CShellText / CShellClipboard / CShell
//==================================================================

class CShellText : public Console
{
public:
	CShellText(XConsole *parent, const string &text, int unknown6c_);

	void addValue(int value);	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
	vector<int> values;	// NOTE: placeholder name
};

CShellText::CShellText(XConsole *parent, const string &text, int unknown6c_)
	: Console(parent,opw7_d316bc - 4,1,2,0,0,false,-1)
	, unknown6c	(unknown6c_)
{
	resetBack_418450();
	print(0,0,text);
	unknown60 = 1;
}

void CShellText::addValue(int value)
{
	values.push_back(value);
}


class CShellClipboard : public Console
{
public:
	CShellClipboard(XConsole *parent);
};

CShellClipboard::CShellClipboard(XConsole *parent)
	: Console(parent,opw7_d316bc,100,0,0,0,true,-1)
{
}

struct OpW7_Point	// NOTE: placeholder name
{
	int x;
	int y;
};

class CShell : public Console
{
public:
	virtual ~CShell();
	void addPointA8(const OpW7_Point &p);	// NOTE: placeholder name
	void addPointB8(const OpW7_Point &p);	// NOTE: placeholder name
	void addPointC8(const OpW7_Point &p);	// NOTE: placeholder name
	void addPointDC(const OpW7_Point &p);	// NOTE: placeholder name

	char pad6c[0x74 - 0x6c];
	vector<int> unknown74;	// NOTE: placeholder name
	char pad84[0x8c - 0x84];
	vector<int> unknown8c;	// NOTE: placeholder name
	char pad9c[0xa8 - 0x9c];
	vector<OpW7_Point> unknowna8;	// NOTE: placeholder name
	vector<OpW7_Point> unknownb8;	// NOTE: placeholder name
	vector<OpW7_Point> unknownc8;	// NOTE: placeholder name
	char padd8[0xdc - 0xd8];
	vector<OpW7_Point> unknowndc;	// NOTE: placeholder name
	char padec[0xf4 - 0xec];
	vector<int> unknownf4;	// NOTE: placeholder name
	vector<int> unknown104;	// NOTE: placeholder name
	vector<int> unknown114;	// NOTE: placeholder name
};
extern CShell *opw7_cec100;	// NOTE: placeholder name

CShell::~CShell()
{
	opw7_cec100 = NULL;
}

void OpW7_addPoint(vector<OpW7_Point> &points, const OpW7_Point &p);	// NOTE: placeholder name (0x9d4a60)

void CShell::addPointA8(const OpW7_Point &p)
{
	OpW7_addPoint(unknowna8,p);
}

void CShell::addPointB8(const OpW7_Point &p)
{
	OpW7_addPoint(unknownb8,p);
}

void CShell::addPointC8(const OpW7_Point &p)
{
	OpW7_addPoint(unknownc8,p);
}

void CShell::addPointDC(const OpW7_Point &p)
{
	OpW7_addPoint(unknowndc,p);
}

//==================================================================
// CShellButton
//==================================================================

class CShellButton : public Console
{
public:
	CShellButton(XConsole *parent, const Rect &rect, string &text, int command_, bool unknown71_, bool unknown72_);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	void unknown4b0a20();	// NOTE: placeholder name

	int command;	// NOTE: placeholder name
	bool active;	// NOTE: placeholder name
	bool unknown71;	// NOTE: placeholder name
	bool unknown72;	// NOTE: placeholder name
	int key;	// NOTE: placeholder name
};

CShellButton::CShellButton(XConsole *parent, const Rect &rect, string &text, int command_, bool unknown71_, bool unknown72_)
	: Console(parent,rect,0,true,-1)
{
	command = command_;
	active = false;
	unknown71 = unknown71_;
	unknown72 = unknown72_;
	key = -1;
	if (opw7_d28c8a)
	{
		string marker(2,'>');
		unsigned int index = text.rfind(marker);
		if (index != string::npos)
			key = charToDigit_405b40((unsigned char)text[index + 2]);
	}
	print(0,0,text);
}

bool CShellButton::mouseEnter()
{
	if (active || opw7_cec0fc->testField())
		return false;
	animate("A_ButtonHover_Begin_SHEL_HOV_OK");
	return true;
}

void CShellButton::mouseLeave()
{
	if (active || opw7_cec0fc->testField())
		return;
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_SHEL_HOV_OK");
}

void CShellButton::unknown4b0a20()
{
	mouseLeave();
	setBackAll_418410(*opw7_cfe674);
	active = true;
	do
	{
		for (int i = Pos(unknown71 != 0,0).x; i < Pos(unknown71 != 0,0).x + getWidth() - (unknown71 != 0) - (unknown72 != 0); i++)
			engine->unknown50fb50(engine,opw7_cebd90,&Pos(i,Pos(unknown71 != 0,0).y),&opw7_cfbec0,NULL,NULL,9)->unknown50de10();
	} while (0);
}

//==================================================================
// CHackTrace / CHack
//==================================================================

string intToString(int value);
int unknown434840(int value, int max);	// NOTE: placeholder name

extern int opw7_cebdd0;	// NOTE: placeholder name
extern int opw7_cebd88;	// NOTE: placeholder name
extern int opw7_cebda4;	// NOTE: placeholder name
extern int opw7_cebd8c;	// NOTE: placeholder name
extern int opw7_cebdbc;	// NOTE: placeholder name
extern int opw7_cebdb0;	// NOTE: placeholder name
extern int opw7_cebd68;	// NOTE: placeholder name
extern int opw7_cebd78[];	// NOTE: placeholder name
extern bool opw7_cefb3e;	// NOTE: placeholder name

struct OpW7_HackState	// NOTE: placeholder name (object at 0xcec024)
{
	int unknown00;	// NOTE: placeholder name
	int unknown04;	// NOTE: placeholder name
	int tracePercent;	// NOTE: placeholder name
};
extern OpW7_HackState *opw7_cec024;	// NOTE: placeholder name

class CHackTrace : public Console
{
public:
	CHackTrace(XConsole *parent, int y);
	void setPercent(int percent_);	// NOTE: placeholder name
	void refresh();	// NOTE: placeholder name

	int percent;	// NOTE: placeholder name
	int progress;	// NOTE: placeholder name
};

CHackTrace::CHackTrace(XConsole *parent, int y)
	: Console(parent,33,1,4,y,0,false,-1)
{
	percent = 0;
	progress = 0;
	do
	{
		engine->unknown50fb50(engine,opw7_cebdd0,&Pos(0,0),&opw7_cfbec0,NULL,NULL,9)->unknown50de10();
	} while (0);
	do
	{
		for (int x = Pos(1,0).x; x < Pos(1,0).x + 26; x++)
			engine->unknown50fb50(engine,opw7_cebd88,&Pos(x,Pos(1,0).y),&opw7_cfbec0,NULL,NULL,9)->unknown50de10();
	} while (0);
	do
	{
		engine->unknown50fb50(engine,opw7_cebda4,&Pos(27,0),&opw7_cfbec0,NULL,NULL,9)->unknown50de10();
	} while (0);
	refresh();
}

void CHackTrace::setPercent(int percent_)
{
	if (percent_ != percent)
	{
		int progress_ = (int)(percent_ / 100.0 * 26.0);
		if (percent_ == 100)
		{
			engine->killGroup("trace_p");
			clear(1,0,26,1);
			do
			{
				for (int x = Pos(1,0).x; x < Pos(1,0).x + 26; x++)
					engine->unknown50fb50(engine,opw7_cebd8c,&Pos(x,Pos(1,0).y),&opw7_cfbec0,NULL,NULL,9)->unknown50de10();
			} while (0);
			unknown48c3c0(opw7_cebdbc);
		}
		else if (progress_ > progress)
		{
			do
			{
				for (int x = Pos(progress + 1,0).x; x < Pos(progress + 1,0).x + progress_ - progress; x++)
					engine->unknown50fb50(engine,opw7_cebdb0,&Pos(x,Pos(progress + 1,0).y),&opw7_cfbec0,NULL,NULL,9)->unknown50de10();
			} while (0);
			unknown48c3c0(opw7_cebd68);
		}
		percent = percent_;
		progress = progress_;
		refresh();
		if (opw7_cefb3e)
			opw7_cec024->tracePercent = percent_;
	}
}

void CHackTrace::refresh()
{
	int x = 29;
	clear(x,0,4,1);
	print(x,0,intToString(percent) + "%");
	do
	{
		for (int i = Pos(x,0).x; i < Pos(x,0).x + 4; i++)
			engine->unknown50fb50(engine,opw7_cebd78[unknown434840(percent,100)],&Pos(i,Pos(x,0).y),&opw7_cfbec0,NULL,NULL,9)->unknown50de10();
	} while (0);
}

class CHack : public Console
{
public:
	virtual ~CHack();
};

CHack::~CHack()
{
}

//==================================================================
// CRobot / CRobotTarget
//==================================================================

bool opW7_findAnimation(const string &name, int *index);	// NOTE: placeholder name (0x9d45a0)
extern string gameStrings_d1f258[];
extern int opw7_cefc54;	// NOTE: placeholder name
extern int opw7_cef9a4;	// NOTE: placeholder name
extern int opw7_cef9a8;	// NOTE: placeholder name
extern int opw7_cef9ac;	// NOTE: placeholder name
extern int opw7_cef9b0;	// NOTE: placeholder name
extern int opw7_cef9b4;	// NOTE: placeholder name
extern int opw7_cef9b8;	// NOTE: placeholder name
extern int opw7_cef9bc;	// NOTE: placeholder name
extern int opw7_cef9c0;	// NOTE: placeholder name
extern int opw7_cef9c4;	// NOTE: placeholder name
extern int opw7_cef9c8;	// NOTE: placeholder name
extern int opw7_cef9cc;	// NOTE: placeholder name
extern int opw7_cef9d0;	// NOTE: placeholder name
extern int opw7_cef9d4;	// NOTE: placeholder name
extern int opw7_cef9d8;	// NOTE: placeholder name

void OpW7_loadRobotAnimations()	// NOTE: placeholder name
{
	opW7_findAnimation("A_CRobot_GroupBox_" + gameStrings_d1f258[opw7_cefc54],&opw7_cef9b4);
	opW7_findAnimation("A_CRobot_GroupTitle_" + gameStrings_d1f258[opw7_cefc54],&opw7_cef9d0);
	opW7_findAnimation("A_CRobot_GroupTitle_Invalid",&opw7_cef9d4);
	opW7_findAnimation("A_CRobot_CouplerValue",&opw7_cef9b0);
	opW7_findAnimation("A_CRobotTarget_Delay",&opw7_cef9cc);
	opW7_findAnimation("CRobotTarget_Ascii",&opw7_cef9bc);
	opW7_findAnimation("CRobotTarget_Dark",&opw7_cef9a8);
	opW7_findAnimation("CRobotTarget_Text",&opw7_cef9c4);
	opW7_findAnimation("CRobotTarget_Ascii2",&opw7_cef9c0);
	opW7_findAnimation("CRobotTarget_Dark2",&opw7_cef9ac);
	opW7_findAnimation("CRobotTarget_Text2",&opw7_cef9c8);
	opW7_findAnimation("CRobotTarget_CostOkay",&opw7_cef9a4);
	opW7_findAnimation("CRobotTarget_CostOnce",&opw7_cef9b8);
	opW7_findAnimation("CRobotTarget_CostInvalid",&opw7_cef9d8);
}

class OpW7_GameData	// NOTE: placeholder name (object at 0xd1e860)
{
public:
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
};
extern OpW7_GameData opw7_gameData;	// NOTE: placeholder name
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)

extern int opw7_b97d38[];	// NOTE: placeholder name (per-hack cost table)

class CRobotTarget : public Console
{
public:
	CRobotTarget(XConsole *parent, int y, bool unknown6c_, int unused, int type_, int unknown78_, int unknown74_);
	virtual bool mouseEnter();

	bool unknown6c;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
	int unknown78;	// NOTE: placeholder name
	int invalid;	// NOTE: placeholder name
};

CRobotTarget::CRobotTarget(XConsole *parent, int y, bool unknown6c_, int unused, int type_, int unknown78_, int unknown74_)
	: Console(parent,parent->getWidth() - 6,1,3,y,0,false,-1)
{
	unknown6c = unknown6c_;
	type = type_;
	unknown74 = unknown74_;
	unknown78 = unknown78_;
	invalid = 0;
	if (type != 73)
	{
		bool locked = opw7_b97d38[type] == 0 && !stringToInt(opw7_gameData.unknown46f6d0("installedRif_g"));
		if (locked)
			invalid = 1;
		else if (opw7_b97d38[type] > unknown74)
			invalid = 1;
	}
	animate("A_CRobotTarget_Delay");
}

bool CRobotTarget::mouseEnter()
{
	if (invalid)
		return false;
	animate("A_ButtonHover_Begin_HACK_HOV_OK");
	return true;
}

class HExplosive	// NOTE: placeholder layout (stands in for the handle vectors whose destructor the exe folds as vector<HExplosive>)
{
	int	ID;
};

class CRobot : public Console
{
public:
	virtual ~CRobot();

	char pad6c[0x78 - 0x6c];
	vector<int> unknown78;	// NOTE: placeholder name
	vector<int> unknown88;	// NOTE: placeholder name
	vector<HExplosive> unknown98;	// NOTE: placeholder name
	vector<HExplosive> unknowna8;	// NOTE: placeholder name
};
extern CRobot *opw7_cec108;	// NOTE: placeholder name

CRobot::~CRobot()
{
	opw7_cec108 = NULL;
}

class Entity
{
public:
	void unknown639870();	// NOTE: placeholder name
};

struct OpW7_PropData	// NOTE: placeholder name
{
	char unknown00[0x40];	// NOTE: placeholder name
	vector<int> list;	// NOTE: placeholder name
};

class Prop
{
public:
	void unknown665cb0();	// NOTE: placeholder name
	OpW7_PropData *getData_45cb30();	// NOTE: placeholder name (folded getter)
};

class HItem
{
protected:
	int ID;
public:
	bool isValid() const;	// 0x9b7230
};

class HEntity : public HItem
{
public:
	Entity *operator->() const;	// 0x9b6570
	bool operator==(HEntity other) const;	// 0x9b78e0
	void reset();	// NOTE: placeholder name (0x9b7270)
	struct OpW7_MapNode *node_9b7910() const;	// NOTE: placeholder name (map node handle operator->)
};

class HProp
{
	int ID;
public:
	Prop *operator->() const;	// 0x9b64f0
};

void OpW7_unknown4b1bf0(HEntity entity, HProp prop)	// NOTE: placeholder name
{
	if (entity.operator->())
		entity->unknown639870();
	else if (prop.operator->())
		prop->unknown665cb0();
}

void opW7_unknown4541b0(int a, int b, int c);	// NOTE: placeholder name

void OpW7_unknown4b1c30()	// NOTE: placeholder name
{
	opW7_unknown4541b0(59,0,0);
}

//==================================================================
// CType
//==================================================================

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);

	char pad6c[0x8c - 0x6c];
};

class CTextInput : public Console
{
public:
	CTextInput(XConsole *parent, int x, int y, int width, int font, bool hidden, bool unknown8c_, int unknownAc_, int unknownB4_, int unknownB8_, int unknownBc_, const char *unknownC0_, int unknownDc_);

	string *getText_458ef0();	// NOTE: placeholder name (folded getter)
	int getCursor_45ab90();	// NOTE: placeholder name (folded getter)
	int getMaxLength_45a8d0();	// NOTE: placeholder name (folded getter)
	void setMaxLength_4544c0(int value);	// NOTE: placeholder name (folded setter)
	void setUnknownAa();

	char pad6c[0xe4 - 0x6c];
};

class CCloseButton : public Console
{
public:
	CCloseButton(XConsole *parent, const XColor &color, int command_);

	char pad6c[0x8c - 0x6c];
};

class OpW7_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void registerConsole(int command, Console *console, int unknown1, int unknown2);	// NOTE: placeholder name (0x416790)
	void setTarget_44cea0(Console *target);	// NOTE: placeholder name (folded setter)
	Console *getTarget_44b020();	// NOTE: placeholder name (folded getter)
	void unknown416570();	// NOTE: placeholder name
	void unknown416340(bool value);	// NOTE: placeholder name
};
extern OpW7_KeyMap *opw7_keyMap;	// NOTE: placeholder name

//==================================================================
// CShellManual
//==================================================================

struct OpW7_Record2d1c4	// NOTE: placeholder name
{
	char unknown00[0x24];	// NOTE: placeholder name
	string name;	// NOTE: placeholder name
};
struct OpW7_Entry6	// NOTE: placeholder name
{
	char unknown00[3];	// NOTE: placeholder name
	bool flag;	// NOTE: placeholder name
	char unknown04[2];	// NOTE: placeholder name
};
struct OpW7_Node1e888	// NOTE: placeholder name
{
	int unknown00;	// NOTE: placeholder name
	int unknown04;	// NOTE: placeholder name
};
class OpW7_Handle1e888	// NOTE: placeholder name
{
	int ID;
public:
	OpW7_Node1e888 *operator->() const;	// 0x9b7910
};
extern vector<unsigned int> opw7_d3860c;	// NOTE: placeholder name (sorted manual topics)
extern vector<int> opw7_cfd1cc;	// NOTE: placeholder name
extern vector<OpW7_Record2d1c4*> opw7_d2d1c4;	// NOTE: placeholder name
extern string gameStrings_d2d508[];
extern int opw7_b9b418[];	// NOTE: placeholder name
extern int opw7_b9b5d8[];	// NOTE: placeholder name
extern OpW7_Entry6 opw7_b9b178[];	// NOTE: placeholder name
extern OpW7_Handle1e888 opw7_d1e888;	// NOTE: placeholder name
extern vector<string> opw7_d257c0;	// NOTE: placeholder name
string OpW7_toUpper_4083a0(const string &text);	// NOTE: placeholder name
void OpW7_insertAt_9dbdc0(vector<unsigned int> &v, int index, unsigned int value);	// NOTE: placeholder name
void OpW7_insertAt_9dbdc0(vector<int> &v, int index, int value);	// NOTE: placeholder name
bool OpW7_isAvailable_9004e0(int topic, bool flag);	// NOTE: placeholder name
bool OpW7_contains_9d3fe0(vector<string> *list, string text);	// NOTE: placeholder name
bool OpW7_contains_9db330(vector<int> &values, int value);	// NOTE: placeholder name
void OpW7_unknown900920();	// NOTE: placeholder name
void OpW7_unknown8fec50();	// NOTE: placeholder name
void OpW7_unknown909990();	// NOTE: placeholder name
void OpW7_unknown4b1c30();	// NOTE: placeholder name

CShellManual::CShellManual(XConsole *parent, int y)
	: Console(parent,46,1,2,y,0,false,-1)
{
	unknownc4 = 0;
	if (opw7_d3860c.empty())
	{
		opw7_d3860c.push_back(0);
		for (int i = 1; i < 112; i++)
		{
			if (!lexicographical_compare(gameStrings_d2d508[i].begin(),gameStrings_d2d508[i].end(),gameStrings_d2d508[opw7_d3860c.back()].begin(),gameStrings_d2d508[opw7_d3860c.back()].end()))
				opw7_d3860c.push_back(i);
			else
			{
				for (unsigned int j = 0; j < opw7_d3860c.size(); j++)
				{
					if (lexicographical_compare(gameStrings_d2d508[i].begin(),gameStrings_d2d508[i].end(),gameStrings_d2d508[opw7_d3860c[j]].begin(),gameStrings_d2d508[opw7_d3860c[j]].end()))
					{
						OpW7_insertAt_9dbdc0(opw7_d3860c,j,i);
						break;
					}
				}
			}
		}
	}
	if (opw7_cfd1cc.empty())
	{
		vector<string> names;
		for (unsigned int i = 0; i < opw7_d2d1c4.size(); i++)
			names.push_back(OpW7_toUpper_4083a0(opw7_d2d1c4[i]->name));
		opw7_cfd1cc.push_back(0);
		for (int i = 1; i < opw7_d2d1c4.size(); i++)
		{
			if (!lexicographical_compare(((const string &)names[i]).begin(),((const string &)names[i]).end(),((const string &)names[opw7_cfd1cc.back()]).begin(),((const string &)names[opw7_cfd1cc.back()]).end()))
				opw7_cfd1cc.push_back(i);
			else
			{
				for (unsigned int j = 0; j < opw7_cfd1cc.size(); j++)
				{
					if (lexicographical_compare(((const string &)names[i]).begin(),((const string &)names[i]).end(),((const string &)names[opw7_cfd1cc[j]]).begin(),((const string &)names[opw7_cfd1cc[j]]).end()))
					{
						OpW7_insertAt_9dbdc0(opw7_cfd1cc,j,i);
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < 112; i++)
	{
		int topic = opw7_d3860c[i];
		if ((opw7_b9b418[topic] == 38 || opw7_b9b418[topic] == opw7_d1e888->unknown04) && OpW7_isAvailable_9004e0(topic,false))
		{
			if (!opw7_b9b178[topic].flag || OpW7_contains_9d3fe0(&opw7_d257c0,gameStrings_d2d508[topic]))
			{
				if (opw7_b9b5d8[topic] != 25 && OpW7_contains_9db330(opw7_cec0fc->getHandle_4aeb30()->getData_45cb30()->list,opw7_b9b5d8[topic]))
					continue;
				unknown70.push_back(i);
			}
		}
	}
	input = new CTextInput(this,0,0,44,0,false,false,(int)OpW7_unknown900920,(int)OpW7_unknown8fec50,(int)OpW7_unknown4b1c30,0,NULL,(int)OpW7_unknown909990);
	input->setMaxLength_4544c0(44);
	input->setUnknownAa();
	opw7_keyMap->unknown416570();
	opw7_keyMap->unknown416340(true);
	opw7_keyMap->setTarget_44cea0(input);
}

int maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
void opr5f_unknown954640(bool flag);	// NOTE: placeholder name (defined in op_r5f.cpp)

extern XColor *opw7_cf1f2c;	// NOTE: placeholder name
extern XColor *opw7_d20b70;	// NOTE: placeholder name
extern XColor opw7_d29804;	// NOTE: placeholder name
extern unsigned int opw7_tickCount;	// NOTE: placeholder name (0xcaed20)

class CType : public Console
{
public:
	CType(XConsole *parent, const Rect &rect, bool unknown, const string &title_, int titleAlign, int unknown74_, bool unknown2, int layer, bool noClose);
	virtual ~CType();
	virtual void render();

	CCloseButton *closeButton;	// NOTE: placeholder name
	int scroll;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
	bool unknown78;	// NOTE: placeholder name
	CTextInput *input;	// NOTE: placeholder name
};
extern CType *opw7_cec10c;	// NOTE: placeholder name

CType::CType(XConsole *parent, const Rect &rect, bool unknown, const string &title_, int titleAlign, int unknown74_, bool unknown2, int layer, bool noClose)
	: Console(parent,rect,0,false,layer == -1 ? 10 : layer)
{
	scroll = 0;
	unknown74 = unknown74_;
	unknown78 = false;
	opw7_cec10c = this;
	setTitle(new ConsoleTitle(this,title_,0,titleAlign));
	animate("CType_Border");
	input = new CTextInput(this,4,getHeight() - 2,rect.width - 6,0,false,unknown,(int)opr5f_unknown954640,0,(int)OpW7_unknown4b1c30,0,NULL,0);
	input->setMaxLength_4544c0(rect.width - 6);
	opw7_keyMap->registerConsole(15,this,unknown2 ? -1 : 257,0);
	opw7_keyMap->setTarget_44cea0(input);
	if (!noClose)
	{
		closeButton = new CCloseButton(this,*opw7_cf1f2c,15);
		closeButton->setHidden(false);
	}
}

CType::~CType()
{
	opw7_cec10c = NULL;
}

void CType::render()
{
	clearInterior();
	engine->render();
	setFore(*opw7_d20b70);
	setBack(opw7_d29804);
	setUnknown_451400(1);
	int y = getHeight() - 2;
	print(2,y,string(2,'>'));
	int width = getWidth() - 6;
	string text;
	if (!input->getText_458ef0()->empty())
	{
		string *full = input->getText_458ef0();
		if (input->getCursor_45ab90() < scroll)
			scroll = input->getCursor_45ab90();
		else if (input->getCursor_45ab90() >= scroll + width || (full->size() >= width && scroll > input->getCursor_45ab90() - width))
			scroll = maxInt(0,input->getCursor_45ab90() - width);
		text.assign((const string::const_iterator &)(full->begin() + scroll),full->size() <= scroll + width ? (const string::const_iterator &)full->end() : (const string::const_iterator &)(full->begin() + scroll + width));	// non-template assign
	}
	else
		scroll = 0;
	if (!text.empty())
		print(4,y,text);
	if (opw7_keyMap->getTarget_44b020() == input && input->getText_458ef0()->size() < input->getMaxLength_45a8d0() && opw7_tickCount / 500 % 2)
		putChar_418150(input->getCursor_45ab90() + 4 - scroll,y,0xaa,*opw7_d20b70,*opw7_cfe674,true);
	unknown429ea0();
}

//==================================================================
// CIntro / CMapAnim
//==================================================================

class CIntro : public Console
{
public:
	virtual ~CIntro();

	char pad6c[0x70 - 0x6c];
	vector<int> unknown70;	// NOTE: placeholder name
	vector<int> unknown80;	// NOTE: placeholder name
};

CIntro::~CIntro()
{
}

class CMapAnim : public Console
{
public:
	virtual ~CMapAnim();
};

CMapAnim::~CMapAnim()
{
}

extern int opw7_bcdfd8[];	// NOTE: placeholder name (font table)
extern bool opw7_bigFont;	// NOTE: placeholder name (config.bigFont, 0xd28d15)

int OpW7_getFont(int index)	// NOTE: placeholder name
{
	switch (opw7_bcdfd8[index])
	{
		case 7: return (opw7_bigFont != 0);
		case 8: return (opw7_bigFont != 0) + 2;
		case 9: return (opw7_bigFont != 0) + 4;
	}
	return opw7_bcdfd8[index];
}

//==================================================================
// CEffect / CEffects
//==================================================================

class RNG
{
public:
	bool chance(int percent);
	int rangeInt(float a, float b);
};
extern RNG rng;

class CEffect : public Console
{
public:
	CEffect(XConsole *parent, const Rect &rect, int type_);

	int type;	// NOTE: placeholder name
};

CEffect::CEffect(XConsole *parent, const Rect &rect, int type_)
	: Console(parent,rect,OpW7_getFont(type_),false,20)
{
	type = type_;
	unknown60 = 3;
	resetBack_418450();
	switch (type)
	{
		case 0: animate("A_CEffect_Damaged"); break;
		case 1: animate("A_CEffect_Corruption"); break;
		case 2: animate("A_CEffect_Overload"); break;
		case 3: break;
		case 4: break;
		case 5: animate("A_CEffect_Charging"); break;
		case 6: animate(rng.chance(25) ? "A_CEffect_Conduit2" : "A_CEffect_Conduit"); break;
		case 19: animate("A_CEffect_FCom_Borders"); break;
		case 20: animate("A_CEffect_FCom_Text"); break;
	}
}

struct OpW7_Container9d2670	// NOTE: placeholder name
{
	OpW7_Container9d2670() throw();	// 0x9d2670
	char pad[0xc];
};

class CEffects : public Console
{
public:
	CEffects(XConsole *parent);
	virtual ~CEffects();
	virtual void update();

	int unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
	int unknown78;	// NOTE: placeholder name
	vector<int> unknown7c;	// NOTE: placeholder name
	int unknown8c;	// NOTE: placeholder name
	int unknown90;	// NOTE: placeholder name
	char pad94[0x9c - 0x94];
	vector<int> unknown9c;	// NOTE: placeholder name
	char padac[0xb0 - 0xac];
	int unknownb0;	// NOTE: placeholder name
	char padb4[0xbc - 0xb4];
	vector<int> unknownbc;	// NOTE: placeholder name
	int unknowncc;	// NOTE: placeholder name
	vector<int> unknownd0;	// NOTE: placeholder name
	int unknowne0;	// NOTE: placeholder name
	vector<int> unknowne4;	// NOTE: placeholder name
	int unknownf4;	// NOTE: placeholder name
	int unknownf8;	// NOTE: placeholder name
	int unknownfc;	// NOTE: placeholder name
	vector<int> unknown100;	// NOTE: placeholder name
	int unknown110;	// NOTE: placeholder name
	int unknown114;	// NOTE: placeholder name
	int unknown118;	// NOTE: placeholder name
	vector<int> unknown11c;	// NOTE: placeholder name
	vector<int> unknown12c;	// NOTE: placeholder name
	int unknown13c;	// NOTE: placeholder name
	int unknown140;	// NOTE: placeholder name
	int unknown144;	// NOTE: placeholder name
	int unknown148;	// NOTE: placeholder name
	vector<Console*> unknown14c;	// NOTE: placeholder name
	vector<int> unknown15c;	// NOTE: placeholder name
	int unknown16c;	// NOTE: placeholder name
	int unknown170;	// NOTE: placeholder name
	int unknown174;	// NOTE: placeholder name
	int unknown178;	// NOTE: placeholder name
	bool unknown17c;	// NOTE: placeholder name
	int unknown180;	// NOTE: placeholder name
	bool unknown184;	// NOTE: placeholder name
	int unknown188;	// NOTE: placeholder name
	int unknown18c;	// NOTE: placeholder name
	vector<OpW7_Point> unknown190;	// NOTE: placeholder name
	OpW7_Container9d2670 unknown1a0;	// NOTE: placeholder name
	int unknown1ac;	// NOTE: placeholder name
	int unknown1b0;	// NOTE: placeholder name
	int unknown1b4;	// NOTE: placeholder name
};

CEffects::CEffects(XConsole *parent)
	: Console(parent,1,1,0,0,0,false,-1)
	, unknown6c	(0)
	, unknown70	(0)
	, unknown74	(33)
	, unknown78	(0)
	, unknown8c	(0)
	, unknown90	(0)
	, unknownb0	(0)
	, unknowncc	(0)
	, unknowne0	(0)
	, unknownf4	(0)
	, unknownf8	(-3)
	, unknownfc	(0)
	, unknown110	(0)
	, unknown114	(0)
	, unknown118	(-1)
	, unknown13c	(0)
	, unknown140	(0)
	, unknown144	(0)
	, unknown148	(0)
	, unknown16c	(0)
	, unknown170	(-4)
	, unknown178	(0)
	, unknown17c	(false)
	, unknown180	(0)
	, unknown184	(false)
	, unknown188	(0)
	, unknown18c	(0)
	, unknown1ac	(0)
	, unknown1b0	(0)
	, unknown1b4	(0)
{
	resetBack_418450();
	unknown60 = 3;
}

//==================================================================
// console shake effect
//==================================================================

struct Area	// NOTE: placeholder name
{
	Area(int x1_, int y1_, int x2_, int y2_);	// NOTE: placeholder name (0x40b1e0)
	void randomPoint_40be30(Point *out);	// NOTE: placeholder name
	bool contains_40b750(const Point &p);	// NOTE: placeholder name

	int x1;
	int y1;
	int x2;
	int y2;
};

class RNG;
extern bool opw7_d28d4d;	// NOTE: placeholder name (screen shake option)
extern bool opw7_b8f988[];	// NOTE: placeholder name
extern XConsole *opw7_cec028[];	// NOTE: placeholder name (main UI consoles)
extern unsigned int opw7_d16198;	// NOTE: placeholder name

template <class T> void removeVectorElement(vector<T> &v, int index);
void unknown9ce6d0(vector<int> &v, unsigned int &i);	// NOTE: placeholder name

struct OpW7_ConsoleShake	// NOTE: placeholder name
{
	void shake(int duration, int delay);	// NOTE: placeholder name
	void update();

	unsigned int endTime;	// NOTE: placeholder name
	unsigned int nextTime;	// NOTE: placeholder name
	vector<Point> offsetPos;	// NOTE: placeholder name
	vector<Point> basePos;	// NOTE: placeholder name
	vector<int> delayedDurations;	// NOTE: placeholder name
	vector<int> delayedTimes;	// NOTE: placeholder name
};

void OpW7_ConsoleShake::shake(int duration, int delay)
{
	if (!opw7_d28d4d)
		return;
	if (delay)
	{
		delayedDurations.push_back(duration);
		delayedTimes.push_back(opw7_tickCount + delay);
	}
	else if (endTime)
		endTime += duration;
	else
	{
		endTime = opw7_tickCount + duration;
		nextTime = opw7_tickCount + 50;
		for (int i = 0; i < 73; i++)
		{
			if (opw7_b8f988[i] && opw7_cec028[i])
			{
				offsetPos[i] = basePos[i] = opw7_cec028[i]->getPos();
				offsetPos[i].offset_40a2a0(rng.rangeInt(-1.0f,1.0f),rng.rangeInt(-1.0f,1.0f));
				opw7_cec028[i]->setPos(offsetPos[i]);
			}
		}
	}
}

void OpW7_ConsoleShake::update()
{
	if (!delayedDurations.empty())
	{
		for (unsigned int i = 0; i < delayedTimes.size(); i++)
		{
			if (opw7_tickCount >= delayedTimes[i])
			{
				shake(delayedDurations[i],0);
				removeVectorElement(delayedDurations,i);
				unknown9ce6d0(delayedTimes,i);
			}
		}
	}
	if (endTime)
	{
		for (int i = 0; i < 73; i++)
		{
			if (opw7_b8f988[i] && opw7_cec028[i])
			{
				opw7_cec028[i]->setPos(basePos[i]);
				if (opw7_tickCount >= endTime)
					endTime = 0;
				else if (opw7_tickCount >= nextTime)
				{
					Area a(basePos[i].x - 1,basePos[i].y - 1,basePos[i].x + 1,basePos[i].y + 1);
					Area b(offsetPos[i].x - 1,offsetPos[i].y - 1,offsetPos[i].x + 1,offsetPos[i].y + 1);
					do
						a.randomPoint_40be30(&offsetPos[i]);
					while (!b.contains_40b750(offsetPos[i]));
					opw7_cec028[i]->setPos(offsetPos[i]);
				}
			}
		}
		if (endTime == 0)
			opw7_d16198 = opw7_tickCount;
		else if (opw7_tickCount >= nextTime)
			nextTime += 50;
	}
}

//==================================================================
// CEvolveSequencing
//==================================================================

class Particle;
extern Point opw7_cefd58;	// NOTE: placeholder name (evolve row delay range)

class CEvolveRow : public Console	// NOTE: placeholder name
{
};

class CEvolveSequencing : public Console
{
public:
	CEvolveSequencing(XConsole *parent, const Rect &rect);
	virtual void update();
	virtual void trigger(const string &command, Particle *value);
	unsigned int getNextTime();	// NOTE: placeholder name

	vector<Console*> rows;	// NOTE: placeholder name
	vector<unsigned int> rowTimes;	// NOTE: placeholder name
	unsigned int nextTime;	// NOTE: placeholder name
};

unsigned int CEvolveSequencing::getNextTime()
{
	return opw7_cefd58.randomInRange_40c130() + opw7_tickCount;
}

CEvolveSequencing::CEvolveSequencing(XConsole *parent, const Rect &rect)
	: Console(parent,rect,2,false,10)
{
	animate("A_CEvolveSequencing");
	rows.assign(getHeight(),(Console*)NULL);
	rowTimes.resize(getHeight(),0);
	for (unsigned int i = 0; i < rowTimes.size(); i++)
		rowTimes[i] = getNextTime();
	nextTime = opw7_tickCount + opw7_cefd58.x;
}

extern Point opw7_d31bf4;	// NOTE: placeholder name (evolve row width range)

void CEvolveSequencing::update()
{
	if (isHidden())
		return;
	engine->update();
	for (unsigned int i = 0; i < rowTimes.size(); i++)
	{
		if (opw7_tickCount >= rowTimes[i])
		{
			rowTimes[i] = getNextTime();
			if (rows[i] == NULL)
			{
				int length = opw7_d31bf4.randomInRange_40c130();
				rows[i] = new Console(this,length,1,rng.rangeInt(0,getWidth() - length),i,2,false,-1);
				rows[i]->animate("A_CEvolveSequencing_Fd");
				string line = getFirstLine();
				rows[i]->print(0,0,line);
				int anim;
				if (opW7_findAnimation("CEvolveSequencing_HL",&anim))
				{
					do
					{
						for (int x = Pos(0,i).x; x < Pos(0,i).x + getWidth(); x++)
							engine->unknown50fb50(engine,anim,&Pos(x,Pos(0,i).y),&opw7_cfbec0,NULL,NULL,9)->unknown50de10();
					} while (0);
				}
				if (opW7_findAnimation("CEvolveSequencing_Timer",&anim))
					unknown48c460(anim,Pos(0,i));
			}
		}
	}
	if (nextTime && opw7_tickCount >= nextTime)
	{
		Console *header = new Console(this,25,1,0,-2,2,false,-1);
		header->printAligned(header->getWidth() - 1,0,2,"SEQUENCING");
		header->animate("A_CEvolveSequencing_Hdr");
		header->resetBack_418450();
		header = new Console(this,25,1,0,-1,2,false,-1);
		header->animate("A_CEvolveSequencing_Div");
		header->resetBack_418450();
		nextTime = 0;
	}
	updateBase429e30();
}

//==================================================================
// CEvolveQuantumshifting / CEvolveAnalyzing
//==================================================================

class CEvolveQuantumshifting : public Console
{
public:
	CEvolveQuantumshifting(XConsole *parent, const Rect &rect);
	virtual void trigger(const string &command, Particle *value);
};

CEvolveQuantumshifting::CEvolveQuantumshifting(XConsole *parent, const Rect &rect)
	: Console(parent,rect,2,false,10)
{
	animate("A_CEvolveQuantum");
}

void CEvolveQuantumshifting::trigger(const string &command, Particle *value)
{
	if (command == "header")
	{
		Console *header = new Console(this,25,1,0,-2,2,false,-1);
		header->printAligned(header->getWidth() - 1,0,2,"QUANTUMSHIFTING");
		header->animate("A_CEvolveSequencing_Hdr");
		header->resetBack_418450();
		header = new Console(this,25,1,0,-1,2,false,-1);
		header->animate("A_CEvolveSequencing_Div");
		header->resetBack_418450();
	}
}

class CEvolveAnalyzing : public Console
{
public:
	CEvolveAnalyzing(XConsole *parent, const Rect &rect);
	virtual void trigger(const string &command, Particle *value);
};

CEvolveAnalyzing::CEvolveAnalyzing(XConsole *parent, const Rect &rect)
	: Console(parent,rect,2,false,10)
{
	animate("A_CEvolveAnalyze");
}

void CEvolveAnalyzing::trigger(const string &command, Particle *value)
{
	if (command == "header")
	{
		Console *header = new Console(this,25,1,0,-2,2,false,-1);
		header->printAligned(header->getWidth() - 1,0,2,"ANALYZING");
		header->animate("A_CEvolveSequencing_Hdr");
		header->resetBack_418450();
		header = new Console(this,25,1,0,-1,2,false,-1);
		header->animate("A_CEvolveSequencing_Div");
		header->resetBack_418450();
	}
}

//==================================================================
// CEvolveAnomaly
//==================================================================

extern Point opw7_d3863c;	// NOTE: placeholder name (anomaly width range)

struct OpW7_Rect	// NOTE: placeholder name
{
	int x;
	int y;
	int width;
	int height;

	OpW7_Rect(int x_, int y_, int width_, int height_);	// 0x456940
};

class CEvolveAnomaly : public Console
{
public:
	CEvolveAnomaly(XConsole *parent, bool sound_);
	virtual void update();
	virtual void trigger(const string &command, Particle *value);
	void drawBox_7b0640(OpW7_Rect *rect, XColor color, int a, int b);	// NOTE: placeholder name

	bool sound;	// NOTE: placeholder name
	Console *alien;	// NOTE: placeholder name
	bool finished;	// NOTE: placeholder name
};

CEvolveAnomaly::CEvolveAnomaly(XConsole *parent, bool sound_)
	: Console(parent,1,1,0,0,2,false,-1)
{
	sound = sound_;
	finished = false;
	int width = opw7_d3863c.randomInRange_40c130();
	resize(width + 20,3);
	setPos(rng.rangeInt(0,getParent4()->getWidth() * 0.75),rng.rangeInt(0,getParent4()->getHeight() - 1));
	alien = new Console(this,width,1,1,1,4,false,-1);
	alien->animate("A_CEvolveAnomaly_Alien");
	alien->resetBack_418450();
	animate("A_CEvolveAnomaly_Timer");
	resetBack_418450();
}

void CEvolveAnomaly::update()
{
	if (isHidden())
		return;
	engine->update();
	if (finished)
		getParent4()->removeSubconsole(this);
	else
		updateBase429e30();
}

void CEvolveAnomaly::trigger(const string &command, Particle *value)
{
	if (command == "detected")
	{
		if (sound)
			opW7_unknown4541b0(111,0,0);
		int start = alien->getPos().x + alien->getWidth() + 1;
		string str = " ANOMALY DETECTED ";
		print(start,1,str);
		int anim;
		if (opW7_findAnimation("CEvolveAnomaly_Detect",&anim))
		{
			do
			{
				for (unsigned int i = Pos(start,1).x; i < Pos(start,1).x + str.size(); i++)
					engine->unknown50fb50(engine,anim,&Pos(i,Pos(start,1).y),&opw7_cfbec0,NULL,NULL,9)->unknown50de10();
			} while (0);
		}
		OpW7_Rect frame(0,0,alien->getWidth() + 2,3);
		drawBox_7b0640(&frame,*opw7_cfe674,1,0);
		if (opW7_findAnimation("CEvolveAnomaly_Box_E1",&anim))
		{
			Pos pos(frame.x + frame.width - 1,0);
			do
			{
				engine->unknown50fb50(engine,anim,&pos,&opw7_cfbec0,NULL,NULL,9)->unknown50de10();
			} while (0);
			pos.y++;
			do
			{
				engine->unknown50fb50(engine,anim,&pos,&opw7_cfbec0,NULL,NULL,9)->unknown50de10();
			} while (0);
			pos.y++;
			do
			{
				engine->unknown50fb50(engine,anim,&pos,&opw7_cfbec0,NULL,NULL,9)->unknown50de10();
			} while (0);
		}
	}
	else if (command == "erase")
	{
		resetBack_418450();
		alien->animate("A_CEvolveAnomaly_Erase");
	}
	else if (command == "finished")
		finished = true;
}

//==================================================================
// CEvolveSlot* / CEvolveConfirmButton / CEvolveApply
//==================================================================

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);

	char pad6c[0x88 - 0x6c];
};

extern string gameStrings_d29018[];
extern string gameStrings_d378d0[];

class CEvolveSlotCount : public Console
{
public:
	CEvolveSlotCount(XConsole *parent, int x, int y, int slot_);

	int slot;	// NOTE: placeholder name
};

CEvolveSlotCount::CEvolveSlotCount(XConsole *parent, int x, int y, int slot_)
	: Console(parent,4,1,x,y,0,false,-1)
{
	slot = slot_;
}

class CEvolveSlotButton : public Console
{
public:
	CEvolveSlotButton(XConsole *parent, int x, int y, int slot_, bool increase_);

	int slot;	// NOTE: placeholder name
	bool increase;	// NOTE: placeholder name
};

CEvolveSlotButton::CEvolveSlotButton(XConsole *parent, int x, int y, int slot_, bool increase_)
	: Console(parent,4,1,x,y,0,false,-1)
{
	slot = slot_;
	increase = increase_;
	setCharRow(1,0,2,increase ? 62 : 60);
}

class CEvolveSlot : public Console
{
public:
	CEvolveSlot(XConsole *parent, int x, int y, int slot_);

	int slot;	// NOTE: placeholder name
};

CEvolveSlot::CEvolveSlot(XConsole *parent, int x, int y, int slot_)
	: Console(parent,29,1,x,y,0,false,-1)
{
	slot = slot_;
	Console *text = new CText(this,Pos(0,0),gameStrings_d29018[slot],0,0,-1);
	text->animate("A_CEvolveSlot_Keys");
	text = new CText(this,Pos(6,0),gameStrings_d378d0[slot],0,0,-1);
	text->animate("A_CEvolveSlot_Slot");
	new CEvolveSlotButton(this,17,0,slot,false);
	new CEvolveSlotCount(this,21,0,slot);
	new CEvolveSlotButton(this,25,0,slot,true);
}

class CEvolveConfirmButton : public Console
{
public:
	CEvolveConfirmButton(XConsole *parent, int x, int y, int width);
};

CEvolveConfirmButton::CEvolveConfirmButton(XConsole *parent, int x, int y, int width)
	: Console(parent,width,1,x,y,0,true,-1)
{
}

class CEvolveApply : public Console
{
public:
	CEvolveApply(XConsole *parent, int x, int y, int count_);

	int count;	// NOTE: placeholder name
};

CEvolveApply::CEvolveApply(XConsole *parent, int x, int y, int count_)
	: Console(parent,9,1,x,y,0,false,-1)
{
	count = count_;
	print(1,0,"APPLY " + intToString(count));
	animate("A_CEvolveApply_New");
}

class CEvolveMain : public Console
{
public:
	virtual ~CEvolveMain();

	char pad6c[0x84 - 0x6c];
	vector<int> unknown84;	// NOTE: placeholder name
};

CEvolveMain::~CEvolveMain()
{
}

class CEvolve : public Console
{
public:
	CEvolve(XConsole *parent, int unknown, bool flag);
	virtual ~CEvolve();

	char pad6c[0xd0 - 0x6c];
};
extern CEvolve *opw7_cec140;	// NOTE: placeholder name

void OpW7_openEvolve(XConsole *parent, int unknown, bool flag)	// NOTE: placeholder name
{
	new CEvolve(parent,unknown,flag);
}

class CWorldMapInfo : public Console
{
public:
	virtual ~CWorldMapInfo();
	void clearInfo(HEntity entity_);	// NOTE: placeholder name
	void setInfo(HEntity node);

	char pad6c[0x70 - 0x6c];
	HEntity entity;	// NOTE: placeholder name
	vector<Console*> lines;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	int unknown88;	// NOTE: placeholder name
};

CWorldMapInfo::~CWorldMapInfo()
{
}

void CWorldMapInfo::clearInfo(HEntity entity_)
{
	if (entity.isValid() && entity == entity_)
	{
		entity.reset();
		for (unsigned int i = 0; i < lines.size(); i++)
			removeSubconsole(lines[i]);
		lines.clear();
	}
}

struct OpW7_MapNode	// NOTE: placeholder name (world map node)
{
	int unknown00;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
	int depth;	// NOTE: placeholder name
	char unknown0C[0x25 - 0x0c];	// NOTE: placeholder name
	bool unknown25;	// NOTE: placeholder name
	bool unknown26;	// NOTE: placeholder name
	bool unknown27;	// NOTE: placeholder name
};
extern HEntity opw7_d1e884;	// NOTE: placeholder name (world map root node)
extern string gameStrings_cfaca0[];
extern string gameStrings_d38e40[];
extern string gameStrings_cfe140[];
void OpW7_findNodes_470240(HEntity node, int ID, vector<HEntity> &matches, vector<HEntity> &visited);	// NOTE: placeholder name
void OpW7_findNodes_46ff70(int type, int ID, HEntity node, vector<HEntity> &matches, vector<HEntity> &visited);	// NOTE: placeholder name
template <class T> void OpW7_eraseAt_9d6440(vector<T> &v, unsigned int &i);	// NOTE: placeholder name
void logError(string location, string message);	// NOTE: placeholder name

void CWorldMapInfo::setInfo(HEntity node)
{
	if (node == entity)
		return;
	clearInfo(entity);
	entity = node;
	string text = !entity.node_9b7910()->unknown27 || entity.node_9b7910()->unknown25 ? gameStrings_cfaca0[entity.node_9b7910()->type] : "Unknown";
	lines.push_back(new CText(this,Pos(1,1),text,2,0,-1));
	lines.back()->animate("A_CWorldMapInfo_Map");
	text = "-" + intToString(entity.node_9b7910()->depth);
	lines.push_back(new CText(this,Pos(unknown84,3),text,2,0,-1));
	lines.back()->animate("A_CWorldMapInfo_Info");
	vector<HEntity> unvisited;
	vector<HEntity> visited;
	OpW7_findNodes_470240(opw7_d1e884,entity.node_9b7910()->depth,unvisited,visited);
	if (!unvisited.empty())
	{
		vector<HEntity> found;
		vector<HEntity> seen;
		OpW7_findNodes_46ff70(3,entity.node_9b7910()->depth,opw7_d1e884,found,seen);
		if (!found.empty())
		{
			bool known = false;
			for (unsigned int i = 0; i < found.size(); i++)
			{
				if (found[i].node_9b7910()->unknown27)
				{
					known = true;
					break;
				}
			}
			if (known)
			{
				for (unsigned int j = 0; j < unvisited.size(); j++)
				{
					if (unvisited[j].node_9b7910()->type == 3)
						OpW7_eraseAt_9d6440(unvisited,j);
				}
			}
		}
	}
	if (unvisited.empty())
	{
		lines.push_back(new CText(this,Pos(unknown88,4),"?",2,0,-1));
		lines.back()->animate("A_CWorldMapInfo_Info");
	}
	else
	{
		int y = 4;
		for (int i = 0, x = unknown88; i < unvisited.size(); i++)
		{
			lines.push_back(new CText(this,Pos(x,y),gameStrings_d38e40[unvisited[i].node_9b7910()->type],2,0,-1));
			lines.back()->animate("CWorld_Block_" + gameStrings_cfe140[unvisited[i].node_9b7910()->type] + "_Mid");
			if (i == 8)
			{
				logError("CWorldMapInfo::setInfo()","More unvisited maps (" + intToString(unvisited.size()) + ") than can be displayed (8)");
				break;
			}
			if (i == 3)
				y -= 2;
			else if (i >= 4)
				x -= 2;
			else
				x += 2;
		}
	}
}

class CWorldMapPiece : public Console
{
public:
	CWorldMapPiece(XConsole *parent, int width, int height, int x, int y, int type_);
	virtual ~CWorldMapPiece();

	int type;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
};

CWorldMapPiece::CWorldMapPiece(XConsole *parent, int width, int height, int x, int y, int type_)
	: Console(parent,width,height,x,y,2,false,-1)
{
	type = type_;
	unknown70 = 0;
	resetBack_418450();
}

CWorldMapPiece::~CWorldMapPiece()
{
}

class Unknown_9b8010	// NOTE: placeholder name (destructor at 0x9b8010)
{
	int pad[16];
public:
	Unknown_9b8010();
	~Unknown_9b8010();
};

class CWorldMap : public Console
{
public:
	virtual ~CWorldMap();

	char pad6c[0x70 - 0x6c];
	vector<HExplosive> unknown70;	// NOTE: placeholder name
	vector<int> unknown80;	// NOTE: placeholder name
	char pad90[0x98 - 0x90];
	vector<int> unknown98;	// NOTE: placeholder name
	char pada8[0xac - 0xa8];
	Unknown_9b8010 unknownac;	// NOTE: placeholder name
};
extern CWorldMap *opw7_cec070;	// NOTE: placeholder name

CWorldMap::~CWorldMap()
{
	opw7_cec070 = NULL;
}

CEvolve::~CEvolve()
{
	opw7_cec140 = NULL;
}

//==================================================================
// CSurrenderPriority / CCycleCounter
//==================================================================

class ConsoleArt : public Console
{
public:
	ConsoleArt(XConsole *parent, const string &file, int x, int y, bool hidden, int layer, int frame, const Pos &offset_, int width, int height);

	char pad6c[0x84 - 0x6c];
};

string &padLeft(string &str, unsigned int width, char c);	// NOTE: placeholder name (0x408090)
extern int opw7_bce0e8[];	// NOTE: placeholder name (map type art rows)
extern string gameStrings_d2e238[];
extern Point opw7_d25898[];	// NOTE: placeholder name (priority ranges)
extern Point opw7_d1d634;	// NOTE: placeholder name

class CSurrenderPriority : public Console
{
public:
	CSurrenderPriority(XConsole *parent, int type_, const Pos &pos, int layer);
	virtual void update();
	void refresh();	// NOTE: placeholder name

	int type;	// NOTE: placeholder name
	unsigned int lastTime;	// NOTE: placeholder name
	int priority;	// NOTE: placeholder name
	Console *counter;	// NOTE: placeholder name
	Console *art;	// NOTE: placeholder name
	Console *name;	// NOTE: placeholder name
};

void CSurrenderPriority::refresh()
{
	counter->setFore(*opw7_d20b70);
	string text = intToString(priority);
	counter->print(0,0,padLeft(text,4,'0'));
}

CSurrenderPriority::CSurrenderPriority(XConsole *parent, int type_, const Pos &pos, int layer)
	: Console(parent,80,1,pos.x,pos.y,4,false,layer)
{
	type = type_;
	lastTime = opw7_tickCount;
	priority = 0;
	counter = new Console(this,4,1,0,0,4,false,-1);
	refresh();
	art = new ConsoleArt(this,string() + "data/art/" + "ending/mainc_maptypes",5,0,false,-1,0,Pos(0,opw7_bce0e8[type]),11,1);
	art->setForeAll_4183d0(*opw7_cfe674);
	art->resetBack_418450();
	art->animate("A_Surrender_Map_Name");
	name = new Console(this,60,1,17,0,4,false,-1);
	name->print(0,0,gameStrings_d2e238[type]);
	name->animate("A_BlockAppear_WH7");
}

void CSurrenderPriority::update()
{
	if (isHidden())
		return;
	engine->update();
	bool changed = false;
	while (lastTime + 250 < opw7_tickCount)
	{
		if (priority < opw7_d25898[type].x)
			priority += opw7_d1d634.randomInRange_40c130() * ((opw7_d25898[type].x - priority) / 500 + 1);
		else
			priority = opw7_d25898[type].randomInRange_40c130();
		lastTime += 250;
		changed = true;
	}
	if (changed)
		refresh();
	updateBase429e30();
}

extern XColor *opw7_d338bc;	// NOTE: placeholder name

class CCycleCounter : public Console
{
public:
	CCycleCounter(XConsole *parent, const Pos &pos, int value_, int layer);
	virtual void update();
	void refresh();	// NOTE: placeholder name (0x997030)

	int value;	// NOTE: placeholder name
};

CCycleCounter::CCycleCounter(XConsole *parent, const Pos &pos, int value_, int layer)
	: Console(parent,8,1,pos.x,pos.y,4,false,layer)
{
	value = value_;
	setBackAll_418410(*opw7_d338bc);
	setFore(*opw7_cfe674);
	refresh();
}

void CCycleCounter::update()
{
	if (isHidden())
		return;
	engine->update();
	refresh();
	updateBase429e30();
}

//==================================================================
// colour table setup
//==================================================================

extern XColor opw7_d2a584;	// NOTE: placeholder name
extern XColor opw7_d2a587;	// NOTE: placeholder name
extern XColor opw7_d2a58a;	// NOTE: placeholder name
extern XColor opw7_d2a58d;	// NOTE: placeholder name
extern XColor opw7_d2a590;	// NOTE: placeholder name
extern XColor opw7_d2a593;	// NOTE: placeholder name
extern XColor opw7_d2a596;	// NOTE: placeholder name
extern XColor opw7_d2a599;	// NOTE: placeholder name
extern XColor opw7_d2a59c;	// NOTE: placeholder name
extern XColor opw7_d2a59f;	// NOTE: placeholder name
extern XColor opw7_d2a5a2;	// NOTE: placeholder name
extern XColor *opw7_d2f170;	// NOTE: placeholder name
extern XColor *opw7_d338c8;	// NOTE: placeholder name
extern XColor *opw7_d1e1d8;	// NOTE: placeholder name
extern XColor *opw7_cf13fc;	// NOTE: placeholder name
extern XColor *opw7_cf6b24;	// NOTE: placeholder name

void OpW7_initColors()	// NOTE: placeholder name
{
	opw7_d2a584 = *opw7_d2f170;
	opw7_d2a587 = *opw7_d338c8;
	opw7_d2a58a = *opw7_d1e1d8;
	opw7_d2a58d = *opw7_d338c8;
	opw7_d2a590 = *opw7_d1e1d8;
	opw7_d2a593 = *opw7_cf13fc;
	opw7_d2a596 = *opw7_d1e1d8;
	opw7_d2a599 = *opw7_cf6b24;
	opw7_d2a59c = *opw7_cf6b24;
	opw7_d2a59f = *opw7_d1e1d8;
	opw7_d2a5a2 = *opw7_d1e1d8;
}

extern XColor opw7_d21e5c;	// NOTE: placeholder name
extern XColor opw7_d21e5f;	// NOTE: placeholder name
extern XColor opw7_d21e62;	// NOTE: placeholder name
extern XColor opw7_d21e65;	// NOTE: placeholder name
extern XColor opw7_d21e68;	// NOTE: placeholder name
extern XColor opw7_d21e6b;	// NOTE: placeholder name
extern XColor opw7_d21e6e;	// NOTE: placeholder name
extern XColor opw7_d21e71;	// NOTE: placeholder name
extern XColor opw7_d21e74;	// NOTE: placeholder name
extern XColor opw7_d21e77;	// NOTE: placeholder name
extern XColor opw7_d21e7a;	// NOTE: placeholder name
extern XColor opw7_d21e7d;	// NOTE: placeholder name
extern XColor opw7_d21e80;	// NOTE: placeholder name
extern XColor opw7_d21e83;	// NOTE: placeholder name
extern XColor opw7_d21e86;	// NOTE: placeholder name
extern XColor opw7_d21e89;	// NOTE: placeholder name
extern XColor opw7_d21e8c;	// NOTE: placeholder name
extern XColor opw7_d2c37c;	// NOTE: placeholder name
extern XColor opw7_d2c37f;	// NOTE: placeholder name
extern XColor opw7_d2c382;	// NOTE: placeholder name
extern XColor opw7_d2c385;	// NOTE: placeholder name
extern XColor opw7_d2c388;	// NOTE: placeholder name
extern XColor opw7_d2c38b;	// NOTE: placeholder name
extern XColor opw7_d2c38e;	// NOTE: placeholder name
extern XColor opw7_d2c391;	// NOTE: placeholder name
extern XColor opw7_d2c394;	// NOTE: placeholder name
extern XColor opw7_d2c397;	// NOTE: placeholder name
extern XColor opw7_d2c39a;	// NOTE: placeholder name
extern XColor opw7_d2c39d;	// NOTE: placeholder name
extern XColor opw7_d2c3a0;	// NOTE: placeholder name
extern XColor opw7_d2c3a3;	// NOTE: placeholder name
extern XColor opw7_d2c3a6;	// NOTE: placeholder name
extern XColor opw7_d2c3a9;	// NOTE: placeholder name
extern XColor opw7_d2c3ac;	// NOTE: placeholder name
extern XColor *opw7_cefdcc;	// NOTE: placeholder name
extern XColor *opw7_cf13fc;	// NOTE: placeholder name
extern XColor *opw7_cf6b24;	// NOTE: placeholder name
extern XColor *opw7_cf766c;	// NOTE: placeholder name
extern XColor *opw7_cfc174;	// NOTE: placeholder name
extern XColor *opw7_d0249c;	// NOTE: placeholder name
extern XColor *opw7_d20618;	// NOTE: placeholder name
extern XColor *opw7_d20b70;	// NOTE: placeholder name
extern XColor *opw7_d21b44;	// NOTE: placeholder name
extern XColor *opw7_d22130;	// NOTE: placeholder name
extern XColor *opw7_d227ac;	// NOTE: placeholder name
extern XColor *opw7_d22fcc;	// NOTE: placeholder name
extern XColor *opw7_d25f60;	// NOTE: placeholder name
extern XColor *opw7_d28fcc;	// NOTE: placeholder name
extern XColor *opw7_d2f170;	// NOTE: placeholder name
extern XColor *opw7_d316f4;	// NOTE: placeholder name
extern XColor *opw7_d32efc;	// NOTE: placeholder name
extern XColor *opw7_d338bc;	// NOTE: placeholder name
extern XColor *opw7_d338c8;	// NOTE: placeholder name
extern XColor *opw7_d35064;	// NOTE: placeholder name
extern XColor *opw7_d35bbc;	// NOTE: placeholder name
extern XColor *opw7_d38644;	// NOTE: placeholder name
extern XColor *opw7_d386c8;	// NOTE: placeholder name
extern vector<vector<Pos> > opw7_cf4d94;	// NOTE: placeholder name
extern vector<vector<int> > opw7_cf670c;	// NOTE: placeholder name
extern vector<vector<int> > opw7_d21f5c;	// NOTE: placeholder name

void OpW7_initTables()	// NOTE: placeholder name
{
	if (!opw7_cf4d94.empty())
		return;
	OpW7_initColors();
	opw7_d21e5c = *opw7_d20b70;
	opw7_d21e5f = *opw7_d21b44;
	opw7_d21e62 = *opw7_d20618;
	opw7_d21e65 = *opw7_d35bbc;
	opw7_d21e68 = *opw7_d38644;
	opw7_d21e6b = *opw7_d386c8;
	opw7_d21e6e = *opw7_d25f60;
	opw7_d21e71 = *opw7_d20618;
	opw7_d21e74 = *opw7_d35064;
	opw7_d21e77 = *opw7_d25f60;
	opw7_d21e7a = *opw7_d38644;
	opw7_d21e7d = *opw7_d0249c;
	opw7_d21e80 = *opw7_d338bc;
	opw7_d21e83 = *opw7_d25f60;
	opw7_d21e86 = *opw7_d338bc;
	opw7_d21e89 = *opw7_d22fcc;
	opw7_d21e8c = *opw7_d28fcc;
	opw7_d2c37c = *opw7_cfc174;
	opw7_d2c37f = *opw7_d338c8;
	opw7_d2c382 = *opw7_d35064;
	opw7_d2c385 = *opw7_d22130;
	opw7_d2c388 = *opw7_d32efc;
	opw7_d2c38b = *opw7_d2f170;
	opw7_d2c38e = *opw7_cf6b24;
	opw7_d2c391 = *opw7_d35064;
	opw7_d2c394 = *opw7_cefdcc;
	opw7_d2c397 = *opw7_cf6b24;
	opw7_d2c39a = *opw7_d32efc;
	opw7_d2c39d = *opw7_cf766c;
	opw7_d2c3a0 = *opw7_cf13fc;
	opw7_d2c3a3 = *opw7_cf6b24;
	opw7_d2c3a6 = *opw7_cf13fc;
	opw7_d2c3a9 = *opw7_d316f4;
	opw7_d2c3ac = *opw7_d227ac;
	opw7_cf4d94.assign(17,vector<Pos>());
	opw7_cf4d94[0].push_back(Pos(13,0));
	opw7_cf4d94[1].push_back(Pos(13,2));
	opw7_cf4d94[2].push_back(Pos(16,3));
	opw7_cf4d94[3].push_back(Pos(13,6));
	opw7_cf4d94[4].push_back(Pos(16,7));
	opw7_cf4d94[5].push_back(Pos(13,10));
	opw7_cf4d94[6].push_back(Pos(17,11));
	opw7_cf4d94[7].push_back(Pos(9,14));
	opw7_cf4d94[7].push_back(Pos(13,14));
	opw7_cf4d94[8].push_back(Pos(7,17));
	opw7_cf4d94[9].push_back(Pos(23,17));
	opw7_cf4d94[10].push_back(Pos(22,19));
	opw7_cf4d94[11].push_back(Pos(7,23));
	opw7_cf4d94[11].push_back(Pos(10,22));
	opw7_cf4d94[11].push_back(Pos(13,23));
	opw7_cf4d94[11].push_back(Pos(16,23));
	opw7_cf4d94[11].push_back(Pos(21,23));
	opw7_cf4d94[11].push_back(Pos(23,23));
	opw7_cf4d94[12].push_back(Pos(7,26));
	opw7_cf4d94[13].push_back(Pos(7,28));
	opw7_cf4d94[14].push_back(Pos(9,30));
	opw7_cf4d94[15].push_back(Pos(19,26));
	opw7_cf4d94[16].push_back(Pos(15,36));
	opw7_cf670c.assign(17,vector<int>());
	opw7_d21f5c.assign(17,vector<int>());
	opw7_cf670c[0].push_back(0);
	opw7_d21f5c[0].push_back(0);
	opw7_cf670c[0].push_back(1);
	opw7_d21f5c[0].push_back(60);
	opw7_cf670c[0].push_back(2);
	opw7_d21f5c[0].push_back(80);
	opw7_cf670c[1].push_back(0);
	opw7_d21f5c[1].push_back(0);
	opw7_cf670c[1].push_back(1);
	opw7_d21f5c[1].push_back(30);
	opw7_cf670c[1].push_back(2);
	opw7_d21f5c[1].push_back(50);
	opw7_cf670c[2].push_back(0);
	opw7_d21f5c[2].push_back(0);
	opw7_cf670c[2].push_back(1);
	opw7_d21f5c[2].push_back(20);
	opw7_cf670c[2].push_back(2);
	opw7_d21f5c[2].push_back(50);
	opw7_cf670c[3].push_back(0);
	opw7_d21f5c[3].push_back(0);
	opw7_cf670c[3].push_back(1);
	opw7_d21f5c[3].push_back(50);
	opw7_cf670c[3].push_back(2);
	opw7_d21f5c[3].push_back(70);
	opw7_cf670c[3].push_back(1);
	opw7_d21f5c[3].push_back(80);
	opw7_cf670c[3].push_back(2);
	opw7_d21f5c[3].push_back(90);
	opw7_cf670c[4].push_back(0);
	opw7_d21f5c[4].push_back(0);
	opw7_cf670c[4].push_back(1);
	opw7_d21f5c[4].push_back(40);
	opw7_cf670c[4].push_back(2);
	opw7_d21f5c[4].push_back(60);
	opw7_cf670c[5].push_back(0);
	opw7_d21f5c[5].push_back(0);
	opw7_cf670c[5].push_back(1);
	opw7_d21f5c[5].push_back(40);
	opw7_cf670c[5].push_back(2);
	opw7_d21f5c[5].push_back(60);
	opw7_cf670c[6].push_back(0);
	opw7_d21f5c[6].push_back(0);
	opw7_cf670c[6].push_back(1);
	opw7_d21f5c[6].push_back(10);
	opw7_cf670c[6].push_back(2);
	opw7_d21f5c[6].push_back(40);
	opw7_cf670c[7].push_back(0);
	opw7_d21f5c[7].push_back(0);
	opw7_cf670c[7].push_back(1);
	opw7_d21f5c[7].push_back(10);
	opw7_cf670c[7].push_back(2);
	opw7_d21f5c[7].push_back(30);
	opw7_cf670c[8].push_back(2);
	opw7_d21f5c[8].push_back(0);
	opw7_cf670c[9].push_back(5);
	opw7_d21f5c[9].push_back(0);
	opw7_cf670c[9].push_back(6);
	opw7_d21f5c[9].push_back(60);
	opw7_cf670c[10].push_back(5);
	opw7_d21f5c[10].push_back(0);
	opw7_cf670c[10].push_back(6);
	opw7_d21f5c[10].push_back(40);
	opw7_cf670c[11].push_back(2);
	opw7_d21f5c[11].push_back(0);
	opw7_cf670c[11].push_back(3);
	opw7_d21f5c[11].push_back(30);
	opw7_cf670c[11].push_back(2);
	opw7_d21f5c[11].push_back(50);
	opw7_cf670c[11].push_back(4);
	opw7_d21f5c[11].push_back(60);
	opw7_cf670c[12].push_back(4);
	opw7_d21f5c[12].push_back(0);
	opw7_cf670c[13].push_back(7);
	opw7_d21f5c[13].push_back(0);
	opw7_cf670c[13].push_back(8);
	opw7_d21f5c[13].push_back(10);
	opw7_cf670c[13].push_back(4);
	opw7_d21f5c[13].push_back(50);
	opw7_cf670c[14].push_back(4);
	opw7_d21f5c[14].push_back(0);
	opw7_cf670c[15].push_back(9);
	opw7_d21f5c[15].push_back(0);
	opw7_cf670c[16].push_back(10);
	opw7_d21f5c[16].push_back(0);
}

//==================================================================
// CTorShieldValue / CTorRepairValue
//==================================================================

extern unsigned int opw7_bce878[];	// NOTE: placeholder name (shield delays)
extern unsigned int opw7_bce880[];	// NOTE: placeholder name (shield durations)
extern unsigned int opw7_bce8b4[];	// NOTE: placeholder name (repair delays)
extern unsigned int opw7_bce8c0[];	// NOTE: placeholder name (repair durations)
extern int opw7_bce8cc[];	// NOTE: placeholder name (repair totals)
extern string gameStrings_d37a50[];
extern string gameStrings_d2e9c8[];
extern XColor *opw7_d2043c;	// NOTE: placeholder name
extern XColor *opw7_d2981c;	// NOTE: placeholder name
extern XColor *opw7_d2175c;	// NOTE: placeholder name
int OpW7_remap(int value, int inMin, int inMax, int outMin, int outMax);	// NOTE: placeholder name (0x4063b0)

class CTorShieldValue : public Console
{
public:
	CTorShieldValue(XConsole *parent, const Pos &pos, int type_, int layer);
	virtual void render();

	int type;	// NOTE: placeholder name
	unsigned int startTime;	// NOTE: placeholder name
};

CTorShieldValue::CTorShieldValue(XConsole *parent, const Pos &pos, int type_, int layer)
	: Console(parent,4,1,pos.x,pos.y,4,false,layer)
{
	type = type_;
	startTime = opw7_tickCount;
}

void CTorShieldValue::render()
{
	unsigned int elapsed = opw7_tickCount - startTime;
	if (elapsed >= opw7_bce878[type])
	{
		print(0,0,gameStrings_d37a50[type]);
		setFore_417f80(0,0,*opw7_cfe674);
		setBack_417fc0(0,0,*opw7_d2043c,1);
		setFore(*opw7_cf6b24);
		setBack(opw7_d29804);
		unsigned int delta = elapsed - opw7_bce878[type];
		unsigned int percent = delta >= opw7_bce880[type] ? 100 : delta * 100 / opw7_bce880[type];
		print(1,0,intToString(percent));
	}
}

class CTorRepairValue : public Console
{
public:
	CTorRepairValue(XConsole *parent, const Pos &pos, int type_, int layer);
	virtual void render();

	int type;	// NOTE: placeholder name
	unsigned int startTime;	// NOTE: placeholder name
};

CTorRepairValue::CTorRepairValue(XConsole *parent, const Pos &pos, int type_, int layer)
	: Console(parent,gameStrings_d2e9c8[type_].size() + 5,1,pos.x,pos.y,4,false,layer)
{
	type = type_;
	startTime = opw7_tickCount;
	print(0,0,gameStrings_d2e9c8[type]);
	animate("A_TorUI_Msg");
}

void CTorRepairValue::render()
{
	setBack(opw7_d29804);
	unsigned int elapsed = opw7_tickCount - startTime;
	if (elapsed >= opw7_bce8b4[type])
	{
		setFore(*opw7_d2981c);
		unsigned int delta = elapsed - opw7_bce8b4[type];
		unsigned int percent = delta >= opw7_bce8c0[type] ? 100 : delta * 100 / opw7_bce8c0[type];
		int amount = OpW7_remap(percent,0,100,opw7_bce8cc[type],100);
		print(getWidth() - 4,0,intToString(amount) + "%");
	}
	else
	{
		setFore(*opw7_d2175c);
		print(getWidth() - 4,0,intToString(opw7_bce8cc[type]) + "%");
	}
}

//==================================================================
// CEnding
//==================================================================

class AsciiImage
{
public:
	AsciiImage();
	~AsciiImage();
	bool load(const string &file, int font, Pos *offset, int width, int height);

	vector<void*> layers;
};

class CEnding : public Console
{
public:
	virtual ~CEnding();
	void markSeen();	// NOTE: placeholder name
	void removeConsoles();	// NOTE: placeholder name

	char pad6c[0x70 - 0x6c];
	int index;	// NOTE: placeholder name
	char pad74[0x78 - 0x74];
	vector<int> unknown78;	// NOTE: placeholder name
	AsciiImage unknown88;	// NOTE: placeholder name
	vector<OpW7_Point> unknown98;	// NOTE: placeholder name
	char pada8[0xac - 0xa8];
	vector<bool> seen;	// NOTE: placeholder name
	vector<int> unknownc0;	// NOTE: placeholder name
	char padd0[0xd4 - 0xd0];
	AsciiImage unknownd4;	// NOTE: placeholder name
	char pade4[0xec - 0xe4];
	XConsole *unknownec[7];	// NOTE: placeholder name
	vector<int> unknown108;	// NOTE: placeholder name (subconsoles)
	vector<int> unknown118;	// NOTE: placeholder name (subconsoles)
	XConsole *unknown128;	// NOTE: placeholder name
	vector<int> unknown12c;	// NOTE: placeholder name (subconsoles)
	vector<int> unknown13c;	// NOTE: placeholder name (subconsoles)
	XConsole *unknown14c;	// NOTE: placeholder name
	XConsole *unknown150;	// NOTE: placeholder name (child of the main console)
	XConsole *unknown154;	// NOTE: placeholder name (child of the main console)
	XConsole *unknown158;	// NOTE: placeholder name
	AsciiImage unknown15c;	// NOTE: placeholder name
	vector<OpW7_Point> unknown16c;	// NOTE: placeholder name
	XConsole *unknown17c[4];	// NOTE: placeholder name
	vector<OpW7_Point> unknown18c;	// NOTE: placeholder name
	char pad19c[0x1a4 - 0x19c];
	XConsole *unknown1a4[4];	// NOTE: placeholder name
	vector<int> unknown1b4;	// NOTE: placeholder name (subconsoles)
	vector<int> unknown1c4;	// NOTE: placeholder name (subconsoles)
	char pad1d4[0x1d8 - 0x1d4];
	XConsole *unknown1d8[3];	// NOTE: placeholder name
	vector<int> unknown1e4;	// NOTE: placeholder name (subconsoles)
};
extern CEnding *opw7_cec148;	// NOTE: placeholder name

CEnding::~CEnding()
{
	opw7_cec148 = NULL;
}

void CEnding::markSeen()
{
	seen[index] = true;
}


class OpW7_Rex	// NOTE: placeholder name (0xd223f0)
{
public:
	XConsole *getConsole_4ab670();	// NOTE: placeholder name (folded getter)
};
extern OpW7_Rex opw7_rex;	// NOTE: placeholder name

void CEnding::removeConsoles()
{
	if (unknownec[0] != NULL)
	{
		removeSubconsole(unknownec[0]);
		unknownec[0] = NULL;
	}
	if (unknownec[1] != NULL)
	{
		removeSubconsole(unknownec[1]);
		unknownec[1] = NULL;
	}
	if (unknownec[2] != NULL)
	{
		removeSubconsole(unknownec[2]);
		unknownec[2] = NULL;
	}
	if (unknownec[3] != NULL)
	{
		removeSubconsole(unknownec[3]);
		unknownec[3] = NULL;
	}
	if (unknownec[4] != NULL)
	{
		removeSubconsole(unknownec[4]);
		unknownec[4] = NULL;
	}
	if (unknownec[5] != NULL)
	{
		removeSubconsole(unknownec[5]);
		unknownec[5] = NULL;
	}
	if (unknownec[6] != NULL)
	{
		removeSubconsole(unknownec[6]);
		unknownec[6] = NULL;
	}
	for (unsigned int i = 0; i < unknown108.size(); i++)
	{
		if (unknown108[i] != 0)
			removeSubconsole((XConsole*)unknown108[i]);
	}
	unknown108.clear();
	for (unsigned int i = 0; i < unknown118.size(); i++)
	{
		if (unknown118[i] != 0)
			removeSubconsole((XConsole*)unknown118[i]);
	}
	unknown118.clear();
	if (unknown128 != NULL)
	{
		removeSubconsole(unknown128);
		unknown128 = NULL;
	}
	for (unsigned int i = 0; i < unknown12c.size(); i++)
	{
		if (unknown12c[i] != 0)
			removeSubconsole((XConsole*)unknown12c[i]);
	}
	unknown12c.clear();
	for (unsigned int i = 0; i < unknown13c.size(); i++)
	{
		if (unknown13c[i] != 0)
			removeSubconsole((XConsole*)unknown13c[i]);
	}
	unknown13c.clear();
	if (unknown14c != NULL)
	{
		removeSubconsole(unknown14c);
		unknown14c = NULL;
	}
	if (unknown150 != NULL)
	{
		opw7_rex.getConsole_4ab670()->removeSubconsole(unknown150);
		unknown150 = NULL;
	}
	if (unknown154 != NULL)
	{
		opw7_rex.getConsole_4ab670()->removeSubconsole(unknown154);
		unknown154 = NULL;
	}
	if (unknown158 != NULL)
	{
		removeSubconsole(unknown158);
		unknown158 = NULL;
	}
	if (unknown17c[0] != NULL)
	{
		removeSubconsole(unknown17c[0]);
		unknown17c[0] = NULL;
	}
	if (unknown17c[1] != NULL)
	{
		removeSubconsole(unknown17c[1]);
		unknown17c[1] = NULL;
	}
	if (unknown17c[2] != NULL)
	{
		removeSubconsole(unknown17c[2]);
		unknown17c[2] = NULL;
	}
	if (unknown17c[3] != NULL)
	{
		removeSubconsole(unknown17c[3]);
		unknown17c[3] = NULL;
	}
	if (unknown1a4[0] != NULL)
	{
		removeSubconsole(unknown1a4[0]);
		unknown1a4[0] = NULL;
	}
	if (unknown1a4[1] != NULL)
	{
		removeSubconsole(unknown1a4[1]);
		unknown1a4[1] = NULL;
	}
	if (unknown1a4[2] != NULL)
	{
		removeSubconsole(unknown1a4[2]);
		unknown1a4[2] = NULL;
	}
	if (unknown1a4[3] != NULL)
	{
		removeSubconsole(unknown1a4[3]);
		unknown1a4[3] = NULL;
	}
	for (unsigned int i = 0; i < unknown1b4.size(); i++)
	{
		if (unknown1b4[i] != 0)
			removeSubconsole((XConsole*)unknown1b4[i]);
	}
	unknown1b4.clear();
	for (unsigned int i = 0; i < unknown1c4.size(); i++)
	{
		if (unknown1c4[i] != 0)
			removeSubconsole((XConsole*)unknown1c4[i]);
	}
	unknown1c4.clear();
	if (unknown1d8[0] != NULL)
	{
		removeSubconsole(unknown1d8[0]);
		unknown1d8[0] = NULL;
	}
	if (unknown1d8[1] != NULL)
	{
		removeSubconsole(unknown1d8[1]);
		unknown1d8[1] = NULL;
	}
	if (unknown1d8[2] != NULL)
	{
		removeSubconsole(unknown1d8[2]);
		unknown1d8[2] = NULL;
	}
	for (unsigned int i = 0; i < unknown1e4.size(); i++)
	{
		if (unknown1e4[i] != 0)
			removeSubconsole((XConsole*)unknown1e4[i]);
	}
	unknown1e4.clear();
}

//==================================================================
// CEndingFade
//==================================================================

class XScreenShake	// NOTE: placeholder name
{
public:
	void start(int duration);	// NOTE: placeholder name
};
extern XScreenShake opw7_screenShake;	// NOTE: placeholder name (0xd16188)

class CEndingFade : public Console
{
public:
	CEndingFade(XConsole *parent, unsigned int duration_, bool shake_, bool planet, int layer);
	virtual void update();

	unsigned int startTime;	// NOTE: placeholder name
	unsigned int duration;	// NOTE: placeholder name
	bool shake;	// NOTE: placeholder name
	unsigned int shakeDuration;	// NOTE: placeholder name
	bool planet;	// NOTE: placeholder name
	AsciiImage planetArt;	// NOTE: placeholder name
	AsciiImage scarArt;	// NOTE: placeholder name
};

CEndingFade::CEndingFade(XConsole *parent, unsigned int duration_, bool shake_, bool planet_, int layer)
	: Console(parent,opw7_cec148->getWidth(),opw7_cec148->getHeight(),0,0,4,false,layer)
	, duration	(duration_)
	, shake	(shake_)
	, shakeDuration	(0)
	, planet	(planet_)
{
	setScaleX_417b60(1.0f);
	setScaleY_417b80(1.0f);
	unknown60 = 4;
	startTime = opw7_tickCount;
	if (planet)
	{
		planetArt.load(string() + "data/art/" + "ending/planet0",4,(Pos*)&Point(-1),0,0);
		scarArt.load(string() + "data/art/" + "ending/planet0_scar",4,(Pos*)&Point(-1),0,0);
	}
}

void CEndingFade::update()
{
	if (shake && (shakeDuration == 0 || opw7_tickCount - startTime < shakeDuration))
		opw7_screenShake.start(20);
	switch (unknown60)
	{
		case 4:
			engine->update();
			if (getScaleX() != 0)
			{
				if (opw7_tickCount - startTime >= duration)
				{
					setScaleX_417b60(0);
					setScaleY_417b80(0);
				}
				else
				{
					setScaleX_417b60(1.0 - (double)(opw7_tickCount - startTime) / duration);
					setScaleY_417b80(1.0 - (double)(opw7_tickCount - startTime) / duration);
					break;
				}
			}
			engine->stopAll();
			unknown60 = 0;
			setHidden(true);
			break;
	}
}


//==================================================================
// crash report upload
//==================================================================

void logMessage(string location, string message);	// NOTE: placeholder name
void logError(string location, string message);	// NOTE: placeholder name

class OpB_Unk_4b98a0	// NOTE: placeholder name
{
public:
	string unknown4455b0();	// NOTE: placeholder name
};
extern OpB_Unk_4b98a0 opw7_d28c68;	// NOTE: placeholder name

typedef struct _TCPsocket *TCPsocket;
struct IPaddress
{
	unsigned int host;
	unsigned short port;
};
extern "C" __declspec(dllimport) int SDLNet_ResolveHost(IPaddress *address, const char *host, unsigned short port);
extern "C" __declspec(dllimport) TCPsocket SDLNet_TCP_Open(IPaddress *ip);
extern "C" __declspec(dllimport) void SDLNet_TCP_Close(TCPsocket sock);
extern "C" __declspec(dllimport) int SDLNet_TCP_Recv(TCPsocket sock, void *data, int maxlen);
extern "C" __declspec(dllimport) char *SDL_GetError();

class Http
{
public:
	Http(const string &host, const string &path, int port);	// 0x4499c0
	~Http();	// 0x9f51f0
	bool upload(const string &name, const string &content);
	void sendString(TCPsocket socket, const string &text);	// NOTE: placeholder name (0x449850)

	string host;	// NOTE: placeholder name
	string path;	// NOTE: placeholder name
	int port;	// NOTE: placeholder name
};

class JLog
{
public:
	int end(int type);
};
extern JLog *jlog;	// NOTE: placeholder name (0xcefa64)

void logInfo(string location, string message);
void logMessage(string message);
extern string opw7_d21928;	// NOTE: placeholder name (version string)
string OpW7_toString_9d5500(unsigned int value);	// NOTE: placeholder name
void OpW7_replace_4081c0(string &text, char from, char to);	// NOTE: placeholder name

bool Http::upload(const string &name, const string &content)
{
	logInfo("Http::upload()","Uploading data");
	TCPsocket socket = NULL;
	string header = "POST " + path + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "User-Agent: Cogmind - " + opw7_d21928 + "\r\n" + "Content-Type: application/x-www-form-urlencoded\r\n";
	logMessage("Resolving address...");
	IPaddress ip;
	if (SDLNet_ResolveHost(&ip,host.c_str(),port) == 0)
	{
		logMessage("Connecting...");
		socket = SDLNet_TCP_Open(&ip);
		if (!socket)
		{
			logError("Http::upload()","Unable to connect.");
			return false;
		}
		logMessage("Sending content...");
		string request = "filename=" + name + "&content=" + content;
		sendString(socket,header);
		sendString(socket,"Content-length: ");
		sendString(socket,OpW7_toString_9d5500(request.size()));
		sendString(socket,"\r\n\r\n");
		sendString(socket,request.c_str());
		logMessage("Waiting for ACK...");
		char buffer[5000];
		int received = SDLNet_TCP_Recv(socket,buffer,5000);
		buffer[received] = 0;
		string response = buffer;
		OpW7_replace_4081c0(response,'\n',' ');
		logMessage("Got " + intToString(received) + " bytes: " + response);
		if (received < 10)
		{
			logError("Http::upload()","Too few bytes received");
			return false;
		}
		else if (memcmp(buffer,"HTTP/1.",7) != 0)
		{
			logError("Http::upload()","Wrong HTTP version");
			return false;
		}
		else if (memcmp(buffer + 8," 2",2) != 0)
		{
			logError("Http::upload()","POST failed");
			return false;
		}
		else
			logMessage("POST succeeded");
		logMessage("Closing socket...");
		SDLNet_TCP_Close(socket);
		socket = NULL;
	}
	else
	{
		logError("Http::upload()","Unable to resolve address:" + host + ":" + intToString(port));
		logError("Http::upload()","SDL_net error:" + string(SDL_GetError()));
		return false;
	}
	if (socket)
		SDLNet_TCP_Close(socket);
	jlog->end(2);
	return true;
}

class Network
{
public:
	static void threadQuitting(int threadType);
};

extern string gameString_cf33fc;

int OpW7_uploadCrashLog(void *data)	// NOTE: placeholder name
{
	logMessage("reportError()","Uploading " + string("crash.log") + "...");
	string fileName = opw7_d28c68.unknown4455b0() + "-crash_";
	fileName += "nonsteam_";
	fileName += gameString_cf33fc + ".txt";
	string path = ((string*)data)->find("wizard mode") != string::npos ? "/cogmind/temp/errors-wizard/upload.php" : "/cogmind/temp/errors-beta171/upload.php";
	Http client("www.gridsagegames.com",path,80);
	client.upload(fileName,*(string*)data);
	remove("crash.log");
	delete data;
	Network::threadQuitting(1);
	return 0;
}

struct PHYSFS_File;
namespace PhysFScpp
{
	class base_fstream
	{
	protected:
		PHYSFS_File * const file;
	public:
		base_fstream(PHYSFS_File *file);
		virtual ~base_fstream();
		bool isOpen_404af0();	// NOTE: placeholder name
	};

	class ifstream : public base_fstream, public std::istream
	{
	public:
		ifstream(string const &filename, std::ios_base::openmode mode = std::ios_base::in);
		virtual ~ifstream();
		void close_9c05e0();	// NOTE: placeholder name (empty)
	};
}

class XResourceMgr
{
public:
	bool fileExists(string path);	// NOTE: placeholder name
};
extern XResourceMgr *opw7_resMgr;	// NOTE: placeholder name (0xcefa88)
extern bool opw7_d28d06;	// NOTE: placeholder name

struct SDL_Thread;
SDL_Thread *OpC_createThread_449730(int threadType, bool force, int (*fn)(void *), void *data);	// NOTE: placeholder name
void OpW7_readStream_409600(PhysFScpp::ifstream &in, string *out);	// NOTE: placeholder name

void OpW7_checkPreviousLog()	// NOTE: placeholder name
{
	if (opw7_resMgr->fileExists("crash.log") && opw7_d28d06)
	{
		PhysFScpp::ifstream file("crash.log",std::ios_base::binary);
		if (!file.isOpen_404af0())
		{
			logError("checkPreviousLog()","Unable to open crash log: " + string("crash.log"));
		}
		else
		{
			string *data = new string;
			OpW7_readStream_409600(file,data);
			if (!OpC_createThread_449730(1,true,OpW7_uploadCrashLog,data))
				delete data;
			data = NULL;
			file.close_9c05e0();
		}
	}
}

extern string gameString_d2f184;	// "Anonymous"
extern int opw7_d25660;	// NOTE: placeholder name

class OpW7_Player	// NOTE: placeholder name
{
public:
	string getName();	// NOTE: placeholder name

	char pad00[0x64];
	string name;	// NOTE: placeholder name
};

string OpW7_Player::getName()
{
	return name == gameString_d2f184 ? name + intToString(opw7_d25660) : name;
}

//==================================================================
// references that make LTCG emit implicit members
//==================================================================

void OpW7_useImplicit(CShellManual *a)	// NOTE: placeholder name
{
	a->CShellManual::~CShellManual();
	((OpW7_ConsoleShake*)a)->OpW7_ConsoleShake::~OpW7_ConsoleShake();
	((CShellText*)a)->CShellText::~CShellText();
	((CEvolveSequencing*)a)->CEvolveSequencing::~CEvolveSequencing();
	((CEndingFade*)a)->CEndingFade::~CEndingFade();
}

//==================================================================
// text parsing helpers
//==================================================================

void OpW7_trim_408ad0(string &text);	// NOTE: placeholder name
void OpW7_replaceChar_4081c0(string &text, char from, char to);	// NOTE: placeholder name
void OpC_removeChar_408100(string &text, char c);	// NOTE: placeholder name
void OpC_replaceAll_407f00(string &text, string from, string to);	// NOTE: placeholder name
void OpW7_split_408860(const string &text, char separator, char quote, vector<string> &out, bool flag);	// NOTE: placeholder name
float stringToFloat_405ab0(const string &text);	// NOTE: placeholder name

void OpW7_parseLine(string &text, vector<string> &out)	// NOTE: placeholder name
{
	if (text.empty())
		return;
	OpW7_trim_408ad0(text);
	OpW7_replaceChar_4081c0(text,'\t',' ');
	OpC_removeChar_408100(text,'\n');
	OpC_replaceAll_407f00(text,"\\n","\n");
	if (text.find_first_of(' ') == string::npos)
		return;
	OpW7_split_408860(text,' ','"',out,true);
}

int OpW7_parseInt(const string &text)	// NOTE: placeholder name
{
	return text == "-" ? 0 : stringToInt(text);
}

int OpW7_parseFloatInt(const string &text)	// NOTE: placeholder name
{
	return (int)(text == "-" ? 0.0f : stringToFloat_405ab0(text));
}
