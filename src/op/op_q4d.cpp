// op_q4d: consoles CRobotManual/CRobotTarget/CRobot/CType/... in 0x942c00-0x966070, Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
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
	Point(const Point &p);	// 0x46ca50
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

struct XEvent	// NOTE: placeholder name
{
	XEvent(const XEvent &event);	// 0x944370

	int type;
	Point pos;
};

class ConsoleTitle;

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(XEvent *event);
	virtual void inputMouse(int x, int y);
	virtual void update();
	virtual void render();

	bool isHidden();
	Rect getRect();
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

class OpQ4d_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class OpQ4d_Engine	// NOTE: placeholder name
{
public:
	OpQ4d_EngineItem *unknown50fb50(OpQ4d_Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
	void killGroup(string group);
	void update();	// NOTE: placeholder name (0x50fff0)
	void render();	// NOTE: placeholder name (0x5100b0)
	void stopAll();	// NOTE: placeholder name
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
	OpQ4d_Engine *engine;
	void *title;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);

	char pad6c[0x8c - 0x6c];
};

class HItem
{
public:
	int ID;
	HItem();
	bool isValid() const;
};

class HEntity : public HItem	// NOTE: placeholder layout
{
public:
	HEntity();
};

struct OpQ4d_TurnData	// NOTE: placeholder name
{
	char pad00[0x6c];
	int unknown6c;	// NOTE: placeholder name
};
struct TurnRecord	// NOTE: placeholder layout
{
	OpQ4d_TurnData *data;	// NOTE: placeholder name
};

class OpQ4d_Inventory	// NOTE: placeholder name
{
public:
	vector<TurnRecord *> *unknown518c00(int type, HEntity e, HEntity a, HEntity b, HEntity c, int d, int f, int g, int h, int i);	// NOTE: placeholder name
};

class BS	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	HEntity getPlayer();	// 0x4630f0
	static bool turnUpdate_51da30(vector<struct TurnRecord *> *records, int type, HEntity entity, HEntity other, HEntity unused, int unknown1, int unknown2);	// 0x51da30
};
extern BS *world;	// NOTE: placeholder name (0xcefc4c)

template <class T> void OpQ4d_eraseAtIndex(vector<T> *v, unsigned int *i);	// NOTE: placeholder name (0x9de640, steps i back)
void OpQ4d_unknown9e2c40(vector<TurnRecord *> *records);	// NOTE: placeholder name

//==================================================================
// CRobotTarget
//==================================================================

extern Pos opq4d_cfbec0;	// NOTE: placeholder name
extern int opq4d_ascii_cef9bc[2];	// NOTE: placeholder name (CRobotTarget_Ascii, Ascii2)
extern int opq4d_dark_cef9a8[2];	// NOTE: placeholder name (CRobotTarget_Dark, Dark2)
extern int opq4d_text_cef9c4[2];	// NOTE: placeholder name (CRobotTarget_Text, Text2)
extern int opq4d_costOkay_cef9a4;	// NOTE: placeholder name
extern int opq4d_costOnce_cef9b8;	// NOTE: placeholder name
extern int opq4d_text2_cef9c8;	// NOTE: placeholder name
extern int opq4d_costInvalid_cef9d8;	// NOTE: placeholder name
extern int opq4d_b97d38[];	// NOTE: placeholder name (per-hack cost table)

class CRobotTarget : public Console
{
public:
	virtual bool input(XEvent *event);
	virtual void trigger(const string &command, int value);

	bool unknown6c;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
	int unknown78;	// NOTE: placeholder name
	int invalid;	// NOTE: placeholder name
};


//==================================================================
// CRobotManual
//==================================================================

class CTextInput : public Console
{
public:
	CTextInput(XConsole *parent, int x, int y, int width, int font, bool hidden, bool unknown8c_, int unknownAc_, int unknownB4_, int unknownB8_, int unknownBc_, const char *unknownC0_, int unknownDc_);

	void setText(const string &text);	// NOTE: placeholder name
	string &getText_458ef0();	// NOTE: placeholder name (folded getter, +0x6c)
	int getCursor_45ab90();	// NOTE: placeholder name (folded getter)
	void setMaxLength_4544c0(int value);	// NOTE: placeholder name (folded setter)

	char pad6c[0xe4 - 0x6c];
};

class OpQ4d_XRoot : public XConsole	// NOTE: placeholder name (XRoot)
{
public:
	int getLayer(XConsole *console);	// 0x42dd70
};

class OpQ4d_Rex	// NOTE: placeholder name (REX at 0xd223f0)
{
public:
	OpQ4d_XRoot *getConsole_4ab670();	// NOTE: placeholder name (folded getter)
};
extern OpQ4d_Rex opq4d_rex;	// NOTE: placeholder name (0xd223f0)

class OpQ4d_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void setTarget_44cea0(Console *target);	// NOTE: placeholder name (folded setter)
	Console *getTarget_44b020();	// NOTE: placeholder name (folded getter)
	void unknown416570();	// NOTE: placeholder name
	void unknown416340(bool value);	// NOTE: placeholder name
};
extern OpQ4d_KeyMap *opq4d_keyMap;	// NOTE: placeholder name

void OpW7_unknown4b1c30();	// NOTE: placeholder name (0x4b1c30)
void ops7_scrollRobot8feee0(bool up);	// NOTE: placeholder name (0x8feee0, defined in src/op/op_s7.cpp)
void OpQ4d_unknown942d40(bool flag);	// NOTE: placeholder name
bool opQ4d_recallHistory();	// NOTE: placeholder name (0x943a90)
extern bool opq4d_d28fa9;	// NOTE: placeholder name
extern XColor *opq4d_d20b70;	// NOTE: placeholder name
extern XColor *opq4d_cfc174;	// NOTE: placeholder name
extern XColor *opq4d_d35bc4;	// NOTE: placeholder name
extern XColor opq4d_d29804;	// NOTE: placeholder name
extern unsigned int opq4d_tickCount;	// NOTE: placeholder name (0xcaed20)
string intToString(int value);	// 0x4051f0
string OpQ4d_toUpper_4083a0(const string &text);	// NOTE: placeholder name
int OpQ4d_indexOf_9d4660(vector<int> &values, int value);	// NOTE: placeholder name

class OpQ4d_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	bool isIn(const Rect &rect);	// NOTE: placeholder name (0x41a730)
	bool isOver(XConsole *console);	// NOTE: placeholder name (0x41a760)
};
extern OpQ4d_Mouse *opq4d_mouse;	// NOTE: placeholder name (0xcefa94)
extern bool opq4d_inputBlocked;	// NOTE: placeholder name (0xcefa5f)

class OpQ4d_Shell : public Console	// NOTE: placeholder name (object at 0xcec104)
{
public:
	vector<XConsole*> *getList_458ef0();	// NOTE: placeholder name (folded getter)
};
extern OpQ4d_Shell *opq4d_cec104;	// NOTE: placeholder name

class CRobotManual : public Console
{
public:
	CRobotManual(XConsole *parent, const Rect &rect, const Rect &rect2);
	virtual bool input(XEvent *event);
	virtual void render();

	void updateMatches_943f70();	// NOTE: placeholder name

	CTextInput *textInput;	// NOTE: placeholder name
	vector<int> unknown70;	// NOTE: placeholder name
	string unknown80;	// NOTE: placeholder name
	vector<int> unknown9c;	// NOTE: placeholder name
	int unknownac;	// NOTE: placeholder name
	Rect unknownb0;	// NOTE: placeholder name
};

class OpQ4d_Robot : public Console	// NOTE: placeholder name (CRobot at 0xcec108)
{
public:
	CRobotManual *getManual_4b1b70();	// NOTE: placeholder name (folded getter, +0xb8)
	vector<CRobotTarget*> *getTargets_4b1b50();	// NOTE: placeholder name (folded getter, +0x88)
	HEntity getEntity_4b1b30();	// NOTE: placeholder name (folded getter, +0x74)
};
extern OpQ4d_Robot *opq4d_cec108;	// NOTE: placeholder name
extern string gameStrings_cfc460[];

bool opQ4d_recallHistory()
{
	CRobotManual *manual = opq4d_cec108->getManual_4b1b70();
	if (!manual->unknown80.empty() && !manual->unknown9c.empty())
	{
		string text = gameStrings_cfc460[manual->unknown9c[manual->unknownac]];
		manual->textInput->setText(text);
		return true;
	}
	return false;
}

CRobotManual::CRobotManual(XConsole *parent, const Rect &rect, const Rect &rect2)
	: Console(parent,rect,0,false,-1)
	, unknownb0	(rect2)
{
	int type;
	vector<CRobotTarget*> *list = opq4d_cec108->getTargets_4b1b50();
	for (unsigned int i = 0; i < list->size(); i++)
	{
		if ((*list)[i]->invalid == 0 && (*list)[i]->type != 0x49)
			unknown70.push_back((*list)[i]->type);
	}
	type = 4;
	string name = type == 4 ? "/ S H E L L /" : "\\ S H E L L \\";
	unknownb0.x = -2;
	unknownb0.y = -2;
	Console *border = new Console(this,unknownb0.width,unknownb0.height,unknownb0.x,unknownb0.y,0,false,opq4d_rex.getConsole_4ab670()->getLayer(this) - 1);
	border->setTitle(new ConsoleTitle(border,name,0,type));
	border->animate("CType_Border");
	textInput = new CTextInput(this,0,0,getWidth(),0,false,false,(int)OpQ4d_unknown942d40,(int)ops7_scrollRobot8feee0,(int)OpW7_unknown4b1c30,0,NULL,(int)opQ4d_recallHistory);
	textInput->setMaxLength_4544c0(getWidth() - 2);
	opq4d_keyMap->unknown416570();
	opq4d_keyMap->unknown416340(true);
	opq4d_keyMap->setTarget_44cea0(textInput);
}

XEvent::XEvent(const XEvent &event)
	: type	(event.type)
	, pos	(event.pos)
{
}

bool CRobotManual::input(XEvent *event)
{
	if (isHidden() || opq4d_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (event->type)
	{
		case 0xff:
		{
			if (opq4d_cec104 && opq4d_mouse->isIn(opq4d_cec104->getRect()))
			{
				vector<XConsole*> *list = opq4d_cec104->getList_458ef0();
				for (unsigned int i = 0; i < list->size(); i++)
				{
					if (opq4d_mouse->isOver((*list)[i]))
					{
						XEvent e = *event;
						e.type = 5;
						(*list)[i]->input(&e);
						break;
					}
				}
				return true;
			}
			OpQ4d_unknown942d40(true);
			return true;
		}
	}
	return false;
}

void CRobotManual::updateMatches_943f70()
{
	if (opq4d_d28fa9)
		return;
	string current = textInput->getText_458ef0();
	if (current.empty())
	{
		unknown80.clear();
		return;
	}
	if (current != unknown80)
	{
		int selected = 0x49;
		if (!unknown80.empty() && !unknown9c.empty())
			selected = unknown9c[unknownac];
		unknown80 = current;
		unknown9c.clear();
		string upper = OpQ4d_toUpper_4083a0(current);
		string name;
		for (unsigned int i = 0; i < unknown70.size(); i++)
		{
			name = OpQ4d_toUpper_4083a0(gameStrings_cfc460[unknown70[i]]);
			if (name.find(upper,0) == 0)
				unknown9c.push_back(unknown70[i]);
		}
		unknownac = 0;
		if (selected != 0x49)
		{
			int index = OpQ4d_indexOf_9d4660(unknown9c,selected);
			if (index != -1)
				unknownac = index;
		}
	}
}

void CRobotManual::render()
{
	if (isHidden())
		return;
	XColor color = *opq4d_d20b70;
	XColor ghost = *opq4d_cfc174;
	XColor number = *opq4d_d35bc4;
	resetBack_418450();
	setFore(color);
	setBack(opq4d_d29804);
	setUnknown_451400(1);
	print(0,0,string(2,'>'));
	print(2,0,textInput->getText_458ef0());
	if (!opq4d_d28fa9)
	{
		updateMatches_943f70();
		if (!unknown80.empty() && !unknown9c.empty())
		{
			string rest = gameStrings_cfc460[unknown9c[unknownac]];
			rest.erase(rest.begin(),rest.begin() + textInput->getText_458ef0().size());
			if (!rest.empty())
			{
				setFore(ghost);
				print(textInput->getCursor_45ab90() + 2,0,rest);
				if (unknown9c.size() > 1)
				{
					string info = " " + intToString(unknownac + 1) + "/" + intToString(unknown9c.size());
					setFore(number);
					print(textInput->getCursor_45ab90() + rest.size() + 2,0,info);
				}
			}
		}
	}
	if (opq4d_keyMap->getTarget_44b020() == textInput && (opq4d_tickCount / 500) % 2)
	{
		if (textInput->getCursor_45ab90() + 2 < getWidth())
			putChar_418150(textInput->getCursor_45ab90() + 2,0,0xaa,color,opq4d_d29804,true);
	}
	unknown429ea0();
}

void opW5_showHelp(int topic);	// NOTE: placeholder name (0x490970)

bool CRobotTarget::input(XEvent *event)
{
	if (isHidden() || opq4d_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (event->type)
	{
		case 0xf6:
		{
			if (!invalid)
				opq4d_cec108->inputMouse(unknown78,0);
			return true;
		}
		case 0xf7:
		{
			if (!invalid)
				opW5_showHelp(type + 0x147);
			return true;
		}
	}
	return false;
}

void CRobotTarget::trigger(const string &command, int value)
{
	if (command == "content")
	{
		string key;
		key += (char)unknown78;
		int x;
		if (!invalid)
		{
			print(0,0,key);
			do
			{
				engine->unknown50fb50(engine,opq4d_ascii_cef9bc[invalid],&Pos(0,0),&opq4d_cfbec0,NULL,NULL,9)->unknown50de10();
			} while (0);
			print(2,0,"-");
			do
			{
				engine->unknown50fb50(engine,opq4d_dark_cef9a8[invalid],&Pos(2,0),&opq4d_cfbec0,NULL,NULL,9)->unknown50de10();
			} while (0);
			print(4,0,"[");
			do
			{
				engine->unknown50fb50(engine,opq4d_ascii_cef9bc[invalid],&Pos(4,0),&opq4d_cfbec0,NULL,NULL,9)->unknown50de10();
			} while (0);
		}
		string name = type == 73 ? "Manual" : gameStrings_cfc460[type];
		print(5,0,name);
		for (unsigned int i = 0; i < name.size(); i++)
		{
			do
			{
				engine->unknown50fb50(engine,opq4d_text_cef9c4[invalid],&Pos(i + 5,0),&opq4d_cfbec0,NULL,NULL,9)->unknown50de10();
			} while (0);
		}
		if (!invalid)
		{
			x = name.size() + 5;
			print(x,0,"]");
			do
			{
				engine->unknown50fb50(engine,opq4d_ascii_cef9bc[invalid],&Pos(x,0),&opq4d_cfbec0,NULL,NULL,9)->unknown50de10();
			} while (0);
		}
		if (unknown6c)
		{
			x = name.size() + (invalid ? 1 : 2) + 5;
			setCharRow(x,0,getWidth() - 3 - x,'-');
			do
			{
				for (int j = Pos(x,0).x; j < Pos(x,0).x + getWidth() - 3 - x; j++)
					engine->unknown50fb50(engine,opq4d_dark_cef9a8[invalid],&Pos(j,Pos(x,0).y),&opq4d_cfbec0,NULL,NULL,9)->unknown50de10();
			} while (0);
		}
		if (type != 73 && opq4d_b97d38[type] > 0)
		{
			string cost = intToString(opq4d_b97d38[type]);
			int cx = getWidth() - 2;
			print(cx,0,cost);
			do
			{
				for (unsigned int k = Pos(cx,0).x; k < Pos(cx,0).x + cost.size(); k++)
					engine->unknown50fb50(engine,invalid == 1 ? opq4d_text2_cef9c8 : (unknown74 < opq4d_b97d38[type] ? opq4d_costInvalid_cef9d8 : (unknown74 < opq4d_b97d38[type] * 2 ? opq4d_costOnce_cef9b8 : opq4d_costOkay_cef9a4)),&Pos(k,Pos(cx,0).y),&opq4d_cfbec0,NULL,NULL,9)->unknown50de10();
			} while (0);
		}
	}
}

bool OpQ4d_unknown942c00(int type, OpQ4d_Inventory *inventory, int id)	// NOTE: placeholder name
{
	if (inventory)
	{
		vector<TurnRecord *> *records = inventory->unknown518c00(type,world->getPlayer(),opq4d_cec108->getEntity_4b1b30(),HEntity(),HEntity(),0,0,0,0,0);
		if (records)
		{
			for (unsigned int i = 0; i < records->size(); i++)
			{
				if (records->at(i)->data->unknown6c != id)
					OpQ4d_eraseAtIndex(records,&i);
			}
			bool result = BS::turnUpdate_51da30(records,type,opq4d_cec108->getEntity_4b1b30(),HEntity(),HEntity(),0,0);
			OpQ4d_unknown9e2c40(records);
			delete records;
			return result;
		}
	}
	return false;
}

void OpQ4d_useImplicit(CRobotManual *a)	// NOTE: placeholder name
{
	a->CRobotManual::~CRobotManual();
}
