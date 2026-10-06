// op_x5_c: CShellButton / CShell* / console helpers in 0x909c70-0x965c10 (Beta 17.1)
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
#include <string>
#include <vector>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Point
{
	int x;
	int y;

	Point(int x_, int y_);	// 0x46ca20
	Point(const Point &p) throw();	// 0x46ca50
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

	int getWidth();	// 0x44b0d0
	void setHidden(bool hidden_);
	void setChar_417f50(int x, int y, int ch);	// NOTE: placeholder name
	void setScaleX_417b60(float value);	// NOTE: placeholder name
	void setScaleY_417b80(float value);	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class OpX5C_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class Engine
{
public:
	OpX5C_EngineItem *unknown50fb50(Engine *engine, int type, Point *a, Point *b, Point *c, Point *d, int value);	// NOTE: placeholder name
};

class Console : public XConsole
{
public:
	virtual ~Console();
	virtual void render();
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);
	void unknown48c3c0(int value);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	void *title;
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	HItem() throw();	// 0x9b6590
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity() throw();	// 0x9b6590
};

class OpX5C_Prop;	// NOTE: placeholder name

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp() throw();	// 0x9b6590
	OpX5C_Prop *operator->() const throw();	// 0x9b64f0
};

class OpR5d_ItemType;	// NOTE: placeholder name
class OpR5d_OtherType;	// NOTE: placeholder name
struct OpW2_WeaponRef;	// NOTE: placeholder name

class Map
{
public:
	HEntity getPlayer() throw();	// 0x4630f0
};

class BS : public Map
{
public:
	int unknown71adc0(HEntity attacker, HProp target, OpW2_WeaponRef *weapon, int type, int index, OpR5d_ItemType *itemType, OpR5d_OtherType *other, HItem item, bool flag);	// NOTE: placeholder name
};
extern BS *opX5C_world;	// NOTE: placeholder name (0xcefc4c)

class OpX5C_Selection	// NOTE: placeholder name (object at 0xcec0f8)
{
public:
	HProp getItem_4b1460() throw();	// NOTE: placeholder name
	int getField_4b14a0();	// NOTE: placeholder name
};
extern OpX5C_Selection *opX5C_cec0f8;	// NOTE: placeholder name

class OpX5C_Target	// NOTE: placeholder name (object at 0xcec0fc)
{
public:
	OpR5d_ItemType *unknown4afce0();	// NOTE: placeholder name
	OpR5d_OtherType *unknown4afd50();	// NOTE: placeholder name
};
extern OpX5C_Target *opX5C_cec0fc;	// NOTE: placeholder name

int opr1c_getPercentTier(int value, int max);	// NOTE: placeholder name (0x4347e0)

extern Point opX5C_cfbec0;	// NOTE: placeholder name
extern int opX5C_cebd74;	// NOTE: placeholder name
extern int opX5C_cebdc0[];	// NOTE: placeholder name
extern int opX5C_cebdd4;	// NOTE: placeholder name
extern int opX5C_cebdac;	// NOTE: placeholder name

//==================================================================
// CShellButton
//==================================================================

struct OpX5C_ShellRecord	// NOTE: placeholder name
{
	int ID;
};

class CShellButton : public Console
{
public:
	void unknown90b2e0();	// NOTE: placeholder name

	OpX5C_ShellRecord *unknown6c;	// NOTE: placeholder name
	bool unknown70;	// NOTE: placeholder name
	bool unknown71;	// NOTE: placeholder name
	bool unknown72;	// NOTE: placeholder name
	int key;	// NOTE: placeholder name
};

void CShellButton::unknown90b2e0()
{
	setHidden(false);
	int percent = opX5C_world->unknown71adc0(opX5C_world->getPlayer(),opX5C_cec0f8->getItem_4b1460(),NULL,0,unknown6c->ID,opX5C_cec0fc->unknown4afce0(),opX5C_cec0fc->unknown4afd50(),HItem(),0);
	if (unknown71)
		do
		{
			engine->unknown50fb50(engine,opX5C_cebd74,&Point(0,0),&opX5C_cfbec0,NULL,NULL,9)->unknown50de10();
		} while (0);
	do
	{
		for (int i = Point(unknown71 != 0,0).x; i < Point(unknown71 != 0,0).x + getWidth() - (unknown71 != 0) - (unknown72 != 0) - (key != -1 ? 3 : 0); i++)
			engine->unknown50fb50(engine,opX5C_cebdc0[opr1c_getPercentTier(percent,100)],&Point(i,Point(unknown71 != 0,0).y),&opX5C_cfbec0,NULL,NULL,9)->unknown50de10();
	} while (0);
	if (key >= 0)
	{
		do
		{
			for (int j = Point(getWidth() - 4,0).x; j < Point(getWidth() - 4,0).x + 3; j++)
				engine->unknown50fb50(engine,opX5C_cebdd4,&Point(j,Point(getWidth() - 4,0).y),&opX5C_cfbec0,NULL,NULL,9)->unknown50de10();
		} while (0);
	}
	else if (key == -2)
	{
		do
		{
			for (int k = Point(getWidth() - 4,0).x; k < Point(getWidth() - 4,0).x + 2; k++)
				engine->unknown50fb50(engine,opX5C_cebdd4,&Point(k,Point(getWidth() - 4,0).y),&opX5C_cfbec0,NULL,NULL,9)->unknown50de10();
		} while (0);
		setChar_417f50(getWidth() - 2,0,0x20);
	}
	unknown48c3c0(opX5C_cebdac);
	if (unknown72)
		do
		{
			engine->unknown50fb50(engine,opX5C_cebd74,&Point(getWidth() - 1,0),&opX5C_cfbec0,NULL,NULL,9)->unknown50de10();
		} while (0);
}

//==================================================================
// effect console helpers
//==================================================================

bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
void opX5C_unknown9655d0(int a, int b, int c, XConsole *console, int amount);	// NOTE: placeholder name
extern XConsole *opX5C_cec078;	// NOTE: placeholder name
extern XConsole *opX5C_cec07c;	// NOTE: placeholder name
extern XConsole *opX5C_cec084;	// NOTE: placeholder name
extern XConsole *opX5C_cec088;	// NOTE: placeholder name
extern XConsole *opX5C_cec08c;	// NOTE: placeholder name
extern int opX5C_cefc54;	// NOTE: placeholder name

class OpX5C_Effect : public Console	// NOTE: placeholder name
{
public:
	void unknown965c10(int a, bool b, bool c);	// NOTE: placeholder name

	char pad6c[0x74 - 0x6c];
	int type;	// NOTE: placeholder name
};

void OpX5C_Effect::unknown965c10(int a, bool b, bool c)
{
	string name = "CEffect_EM_";
	if (c)
		name += "CorruptedPart";
	else
		switch (type)
		{
			case 0x21:
				switch (opX5C_cefc54)
				{
					case 0:
						name += "Normal";
						break;
					case 1:
						name += "Imprinted";
						break;
					case 2:
						name += "RIF";
						break;
					case 3:
						name += "UFD";
						break;
					case 4:
						name += "Reset";
						break;
					case 5:
						name += "Polymind";
						break;
					case 6:
						name += "IdMask";
						break;
				}
				break;
			case 0x1d:
				name += "StasisB";
				break;
			case 0x1e:
				name += "StasisP";
				break;
			case 0x1f:
				name += "Core";
				break;
			case 0x20:
				name += "Heat";
				break;
		}
	int effect;
	int timer;
	int total;
	if (!(OpU8a_lookup1(name,&effect) && OpU8a_lookup1("A_CEffect_EM_Timer",&timer) && OpU8a_lookup1("A_CEffect_EM_Clear",&total)))
		return;
	int part = a / 4;
	if (b)
		part *= 2;
	opX5C_unknown9655d0(effect,timer,total,opX5C_cec078,part);
	opX5C_unknown9655d0(effect,timer,total,opX5C_cec07c,part);
	opX5C_unknown9655d0(effect,timer,total,opX5C_cec084,part);
	opX5C_unknown9655d0(effect,timer,total,opX5C_cec088,part * 2);
	opX5C_unknown9655d0(effect,timer,total,opX5C_cec08c,part);
	if (c)
	{
		int sfx;
		if (OpU8a_lookup1("A_CEffect_CorrPart_Sfx",&sfx))
			unknown48c3c0(sfx);
	}
}

//==================================================================
// CShellManual
//==================================================================

string OpX5C_toUpper(const string &text);	// NOTE: placeholder name (0x4083a0)
void OpX5C_unknown909840(string &text, bool flag);	// NOTE: placeholder name
int OpS8b_Fn9d4660(vector<int> &v, int value);	// NOTE: placeholder name

class UnknownPart45c060
{
public:
	char pad00[0x11];
	bool unknown11;	// NOTE: placeholder name
	bool unknown45c160(int a, int b) throw();	// NOTE: placeholder name
};

struct OpX5C_PropData	// NOTE: placeholder name
{
	char pad00[0xf8];
	int unknownF8;	// NOTE: placeholder name
};

class OpX5C_Prop	// NOTE: placeholder name
{
public:
	UnknownPart45c060 *unknown45cb30() throw();	// NOTE: placeholder name (folded getter)
	OpX5C_PropData *unknown9b8f00();	// NOTE: placeholder name (folded getter)
};

struct OpX5C_ManualEntry	// NOTE: placeholder name
{
	char pad00[0x24];
	string name;	// NOTE: placeholder name
	char pad40[0x209 - 0x40];
	bool unknown209;	// NOTE: placeholder name
	bool unknown56f4c0(HProp prop) throw();	// NOTE: placeholder name
};

class CTextInput : public Console
{
public:
	const string &unknown458ef0();	// NOTE: placeholder name (folded getter)
};

extern bool opX5C_d28fa9;	// NOTE: placeholder name
extern vector<int> opX5C_d3860c;	// NOTE: placeholder name
extern string opX5C_d2d508[];	// NOTE: placeholder name
extern vector<int> opX5C_cfd1cc;	// NOTE: placeholder name
extern vector<OpX5C_ManualEntry *> opX5C_d2d1c4;	// NOTE: placeholder name

class CShellManual : public Console
{
public:
	void unknown909c70();	// NOTE: placeholder name

	CTextInput *input;	// NOTE: placeholder name
	vector<int> unknown70;	// NOTE: placeholder name
	string unknown80;	// NOTE: placeholder name
	vector<int> unknown9c;	// NOTE: placeholder name
	int unknownac;	// NOTE: placeholder name
	vector<int> unknownb0;	// NOTE: placeholder name
	int unknownc0;	// NOTE: placeholder name
	int unknownc4;	// NOTE: placeholder name
};

void CShellManual::unknown909c70()
{
	if (opX5C_d28fa9)
		return;
	string text = input->unknown458ef0();
	if (text.empty())
	{
		unknown80.clear();
		return;
	}
	if (text != unknown80)
	{
		int prevCommand = -1;
		if (!unknown80.empty() && !unknown9c.empty())
			prevCommand = unknown9c[unknownac];
		unknown80 = text;
		unknown9c.clear();
		unknownb0.clear();
		string upper = OpX5C_toUpper(text);
		string name;
		for (unsigned int i = 0; i < unknown70.size(); i++)
		{
			name = OpX5C_toUpper(opX5C_d2d508[opX5C_d3860c[unknown70[i]]]);
			OpX5C_unknown909840(name,text.find('(') != string::npos);
			if (name.find(upper) == 0)
				unknown9c.push_back(unknown70[i]);
		}
		unknownac = 0;
		if (prevCommand != -1)
		{
			int newIndex = OpS8b_Fn9d4660(unknown9c,prevCommand);
			if (newIndex != -1)
				unknownac = newIndex;
		}
		if (upper.find(OpX5C_toUpper("Schematic(")) == 0)
		{
			int oldSchematic = -1;
			if (!unknownb0.empty())
				oldSchematic = unknownb0[unknownc0];
			unknownb0.clear();
			upper = OpX5C_toUpper(text);
			upper.erase(upper.begin(),upper.begin() + upper.find('(') + 1);
			if (!upper.empty())
			{
				for (int j = 0; j < opX5C_cfd1cc.size(); j++)
				{
					if (OpX5C_toUpper(opX5C_d2d1c4[opX5C_cfd1cc[j]]->name).find(upper) == 0 && ((opX5C_d2d1c4[opX5C_cfd1cc[j]]->unknown209 && opX5C_d2d1c4[opX5C_cfd1cc[j]]->unknown56f4c0(opX5C_cec0f8->getItem_4b1460())) || opX5C_cec0f8->getItem_4b1460()->unknown45cb30()->unknown45c160(1,opX5C_cfd1cc[j])))
						unknownb0.push_back(j);
				}
			}
			unknownc0 = 0;
			if (oldSchematic != -1)
			{
				int newIndex = OpS8b_Fn9d4660(unknownb0,oldSchematic);
				if (newIndex != -1)
					unknownc0 = newIndex;
			}
		}
	}
}

//==================================================================
// CShell
//==================================================================

class CShellClipboard : public Console
{
public:
	CShellClipboard(XConsole *parent);	// 0x4b0c90
};

class CShellText : public Console
{
public:
	CShellText(XConsole *parent, const string &text, int unknown6c_);
	void unknown90b850(bool flag);	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
	vector<int> values;	// NOTE: placeholder name
};

struct OpX5C_Node	// NOTE: placeholder name
{
	int pad0;
	int type;
};

class OpX5C_HNode	// NOTE: placeholder name
{
public:
	int ID;
	OpX5C_Node *operator->() const;	// 0x9b7910
};
extern OpX5C_HNode opX5C_rootNode;	// NOTE: placeholder name (0xd1e888)

struct OpQ5_T9de730	// NOTE: placeholder name (message record)
{
	int type;
	char pad04[0xc - 0x4];
	string source;	// NOTE: placeholder name
	string text;	// NOTE: placeholder name
};
template <class T> void OpQ5_deleteObjectAndStep(vector<T*> &v, int &index);	// NOTE: placeholder name

struct OpX5C_Terminal	// NOTE: placeholder name (object at 0xcefc58)
{
	char pad00[0x30];
	bool unknown30;	// NOTE: placeholder name
	char pad31[0x7c - 0x31];
	vector<OpQ5_T9de730 *> messages;	// NOTE: placeholder name
};

struct OpX5C_Phrase	// NOTE: placeholder name
{
	char pad00[0x28];
	string text;	// NOTE: placeholder name
};

struct OpX5C_HackState	// NOTE: placeholder name (object at 0xcec024)
{
	int unknown00;	// NOTE: placeholder name
};

extern OpX5C_Terminal *opX5C_cefc58;	// NOTE: placeholder name
extern vector<OpX5C_Phrase *> opX5C_d2b4d8;	// NOTE: placeholder name
extern string gameStrings_d3a280[];
extern bool opX5C_d25450;	// NOTE: placeholder name
extern int opX5C_d254d0;	// NOTE: placeholder name
extern int opX5C_d254d4;	// NOTE: placeholder name
extern int opX5C_d1dd40;	// NOTE: placeholder name
extern bool opX5C_cefb3e;	// NOTE: placeholder name
extern OpX5C_HackState *opX5C_cec024;	// NOTE: placeholder name

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

void OpS8d_appendInts(vector<int> &v, int *values, unsigned int count);	// NOTE: placeholder name

class CShell : public Console
{
public:
	virtual void open();	// 0x90bc90
	void unknown90ed30(const string &text, int unknown6c, bool flag, bool log);	// NOTE: placeholder name
	void unknown90eec0(vector<int> &chars, int unknown6c, vector<XColor> *fore, vector<XColor> *back);	// NOTE: placeholder name
	void unknown90f0a0();	// NOTE: placeholder name
	void scroll(int amount);	// 0x90d0a0
	void addNew(const string &text, const string &text2, int type, int a, bool b);	// 0x90d550

	char pad6c[0x70 - 0x6c];
	HProp prop;	// NOTE: placeholder name
	vector<CShellText *> unknown74;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	CShellClipboard *clipboard;	// NOTE: placeholder name
	char pad8c[0x9c - 0x8c];
	int unknown9c;	// NOTE: placeholder name
	int unknowna0;	// NOTE: placeholder name
	int unknowna4;	// NOTE: placeholder name
	vector<Point> unknownA8;	// NOTE: placeholder name
	vector<Point> unknownB8;	// NOTE: placeholder name
	vector<Point> unknownC8;	// NOTE: placeholder name
	bool unknownD8;	// NOTE: placeholder name
	char padD9[0xdc - 0xd9];
	vector<Point> unknownDc;	// NOTE: placeholder name
	int unknownEc;	// NOTE: placeholder name
	int unknownF0;	// NOTE: placeholder name
	vector<Console *> unknownF4;	// NOTE: placeholder name
	vector<Console *> unknown104;	// NOTE: placeholder name
	vector<Console *> unknown114;	// NOTE: placeholder name
	int unknown124;	// NOTE: placeholder name
};

void CShell::open()
{
	unknown60 = 3;
	unknown84 = 0;
	unknown9c = 0;
	unknowna0 = 0;
	unknowna4 = 0;
	unknownA8.clear();
	unknownB8.clear();
	unknownC8.clear();
	unknownD8 = false;
	unknown124 = 0;
	unknownDc.clear();
	unknownEc = 0;
	unknownF0 = 0;
	if (opX5C_d25450)
	{
		opX5C_d254d0 = 0x70;
		opX5C_d254d4 = 0;
	}
	unknownF4.clear();
	unknown104.clear();
	unknown114.clear();
	clipboard = new CShellClipboard(this);
	animate("CShell_Border");
	animate(prop->unknown9b8f00()->unknownF8 == 6 ? "A_CShell_Bkg_Derelict" : (prop->unknown9b8f00()->unknownF8 == 7 ? (opX5C_rootNode->type == 0x23 ? "A_CShell_Bkg_AC0" : "A_CShell_Bkg_Architect") : (prop->unknown9b8f00()->unknownF8 == 8 ? "A_CShell_Bkg" : "A_CShell_Bkg")));
	if (opX5C_cec0f8->getField_4b14a0() != 0x57)
		addNew(string(""),"\n" + string(opX5C_d2b4d8[opX5C_cec0f8->getField_4b14a0() + 0x32d]->text),4,-1,false);
	if (prop->unknown45cb30()->unknown11)
	{
		if (opX5C_d1dd40 == 0)
			addNew(string("RECEIVING..."),string("Welcome to your first Zion-integrated 0b10 terminal! Unaware Operators have no clue how to secure these things, ha! Check the roster for backup, and if you need any intel that'll take longer so we'll sever this connection and you can retrieve it at the next terminal."),1,-1,false);
		opX5C_d1dd40++;
	}
	if (opX5C_cefc58->unknown30 && !opX5C_cefc58->messages.empty())
	{
		bool scrolled = false;
		for (int i = 0; i < opX5C_cefc58->messages.size(); i++)
		{
			if (opX5C_cefc58->messages[i]->type == 8 || opX5C_cefc58->messages[i]->type == 9)
			{
				if (opX5C_cefc58->messages[i]->source == gameStrings_d3a280[prop->unknown9b8f00()->unknownF8])
				{
					unknown74.push_back(new CShellText(this,opX5C_cefc58->messages[i]->text,opX5C_cefc58->messages[i]->type == 8 ? 3 : 7));
					unknown74.back()->unknown90b850(true);
					unknown74.push_back(NULL);
					OpQ5_deleteObjectAndStep(opX5C_cefc58->messages,i);
					scrolled = true;
				}
			}
		}
		if (scrolled)
			scroll(0);
	}
	setScaleX_417b60(1.0f);
	setScaleY_417b80(1.0f);
	if (opX5C_cefb3e)
		opX5C_cec024->unknown00++;
}

void CShell::unknown90f0a0()
{
	string header = "01 0 0 0 0 1 1 0 1 0 1 1 0 0 1 0 1 0 1 0 0 00";
	unknown90ed30(header,5,false,false);
	const unsigned int dim = 40;
	const int rows = 5;
	int characters[5][40] =
	{
		{0x20,0x20,0x20,0x20,0x20,0x20,0x2d,0x20,0xac,0x20,0xab,0x20,0x20,0x2e,0x20,0x20,0xab,0xab,0xab,0x20,0x20,0xab,0xab,0xab,0xab,0xab,0xab,0xab,0xab,0x20,0x20,0x2d,0x20,0x20,0xad,0xab,0x20,0x20,0xab,0x20},
		{0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xaa,0xaa,0x20,0xad,0xaa,0xaa,0xaa,0x20,0xad,0xaa,0x20,0xae,0xaa,0x20,0x2d,0xaa,0xaa,0x20,0x20,0xae,0xab,0x20,0xaa,0x20,0xaa,0xaa,0x20,0x20,0xaa,0xac,0xaa,0xac,0x2d},
		{0x20,0x20,0x20,0x20,0x20,0x20,0xad,0xaa,0x20,0xac,0xad,0xac,0xad,0xaa,0x20,0xab,0xaa,0xae,0xae,0xaa,0x20,0x20,0xad,0xaa,0x2e,0x2d,0xad,0xae,0xae,0xab,0x20,0xad,0xaa,0x20,0x20,0x20,0xaa,0xaa,0x20,0x20},
		{0x20,0x20,0x20,0x20,0x20,0x20,0xaa,0xaa,0x20,0xaa,0xaa,0xac,0xad,0xaa,0xac,0xad,0xaa,0x20,0x2d,0xad,0xac,0x20,0xad,0xaa,0xac,0x20,0xad,0xaa,0x20,0xaa,0xac,0xad,0xaa,0xac,0x2d,0xad,0xaa,0x20,0xaa,0xac},
		{0x20,0x20,0x20,0x20,0x20,0x20,0xae,0xae,0x20,0x20,0xaa,0x20,0xae,0xae,0xae,0x20,0xae,0x20,0x20,0xae,0x20,0x20,0xae,0xae,0xae,0x20,0x2e,0xae,0x20,0x20,0xae,0xae,0xae,0xae,0x20,0xae,0xae,0x20,0xae,0xae}
	};
	for (int y = 0; y < rows; y++)
	{
		vector<int> row;
		OpS8d_appendInts(row,characters[y],dim);
		unknown90eec0(row,5,NULL,NULL);
	}
	string message = "01 0 0 1 0 0 0 0 1 0 0 0 1 0 1 0 1 0 1 0 0 10";
	unknown90ed30(message,5,false,false);
}
