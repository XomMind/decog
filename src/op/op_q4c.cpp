// op_q4c: CCodes/CShell/CShellManual/CHack consoles and helpers in 0x8fec50-0x942c00 of COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
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
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();	// 0x40a6e0
	Rect(const Rect &rect);	// 0x40a720
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Pos mouse;
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool isActive();
	virtual void refresh();
	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int modifier);	// NOTE: placeholder name
	virtual void update();
	virtual void render();

	bool isHidden();
	XConsole *getParent();	// 0x9b8f00
	Pos getPos();
	int getWidth();	// 0x44b0d0
	int getHeight();
	void print(int x, int y, const string &text);
	void putChar_4180b0(int x, int y, int ch);	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);
	bool input429d00(XEvent *event);	// NOTE: placeholder name (XConsole::input body)

	char pad04[0x60 - 0x04];
};

class OpQ4c_Engine	// NOTE: placeholder name (Engine)
{
public:
	void killGroup(string group);
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);
	void setTitle(class ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)

	int unknown60;
	OpQ4c_Engine *engine;
	void *title;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);
	char pad6c[0x8c - 0x6c];
};

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);

	string text;
};

class CTextInput : public Console
{
public:
	void setText(const string &text);	// NOTE: placeholder name (0x48d300)
};

class OpQ4c_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	bool hasCommand(int command);	// NOTE: placeholder name (0x416200)
	void registerConsole(int command, Console *console, int unknown1, int unknown2);	// NOTE: placeholder name (0x416790)
	void unknown416640();	// NOTE: placeholder name
};
extern OpQ4c_KeyMap *opq4c_keyMap;	// NOTE: placeholder name

class OpQ4c_World	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	bool unknown71bbd0();	// NOTE: placeholder name
};
extern OpQ4c_World *opq4c_world;	// NOTE: placeholder name

class OpQ4c_Rex	// NOTE: placeholder name (0xd223f0)
{
public:
	int getHeight_4189a0();	// NOTE: placeholder name
};
extern OpQ4c_Rex opq4c_rex;	// NOTE: placeholder name

class OpQ4c_ItemData	// NOTE: placeholder name
{
public:
	char pad00[0x11];
	bool unknown11;	// NOTE: placeholder name
};

class OpQ4c_Prop	// NOTE: placeholder name
{
public:
	OpQ4c_ItemData *getData();	// NOTE: placeholder name (folded getter)
	const string &unknown45c590();	// NOTE: placeholder name
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	OpQ4c_Prop *operator->() const;	// 0x9b64f0
};

class OpQ4c_Selection	// NOTE: placeholder name (object at 0xcec0f8)
{
public:
	HProp getItem_4b1460();	// NOTE: placeholder name
};
extern OpQ4c_Selection *opq4c_cec0f8;	// NOTE: placeholder name

extern bool opq4c_cefa5f;	// NOTE: placeholder name (console input blocked)
extern bool opq4c_cefca9;	// NOTE: placeholder name

//==================================================================
// CShellManual / CShell / CRobot / CType access
//==================================================================

class OpQ4c_ShellManual	// NOTE: placeholder name (CShellManual)
{
public:
	char pad00[0x6c];
	CTextInput *input;
};

class OpQ4c_Shell : public XConsole	// NOTE: placeholder name (CShell at 0xcec100)
{
public:
	OpQ4c_ShellManual *getManual_48f100();	// NOTE: placeholder name
	void unknown4b0df0();	// NOTE: placeholder name
};
extern OpQ4c_Shell *opq4c_cec100;	// NOTE: placeholder name

class OpQ4c_Robot : public XConsole	// NOTE: placeholder name (CRobot at 0xcec108)
{
public:
	OpQ4c_ShellManual *getManual_4b1b70();	// NOTE: placeholder name
};
extern OpQ4c_Robot *opq4c_cec108;	// NOTE: placeholder name

class OpQ4c_Type	// NOTE: placeholder name (CType at 0xcec10c)
{
public:
	char pad00[0x7c];
	CTextInput *input;
};
extern OpQ4c_Type *opq4c_cec10c;	// NOTE: placeholder name

extern int opq4c_cef9dc;	// NOTE: placeholder name
extern vector<string> opq4c_d33d28;	// NOTE: placeholder name
extern int opq4c_cebd60;	// NOTE: placeholder name
extern vector<string> opq4c_d33d48;	// NOTE: placeholder name

class MapRecord;
extern vector<MapRecord*> opq4c_d1e920;	// NOTE: placeholder name
extern vector<MapRecord*> opq4c_d1e950;	// NOTE: placeholder name
extern bool opq4c_b9930c[];	// NOTE: placeholder name
extern bool opq4c_b98c50[];	// NOTE: placeholder name
extern vector<string> opq4c_d1e930;	// NOTE: placeholder name
extern vector<string> opq4c_d1e900;	// NOTE: placeholder name
extern string opq4c_d22858[];	// NOTE: placeholder name
extern string opq4c_d32510[];	// NOTE: placeholder name
extern string opq4c_d15e68[];	// NOTE: placeholder name
extern string opq4c_d1ee10[];	// NOTE: placeholder name
extern XConsole *opq4c_cec034;	// NOTE: placeholder name
extern bool opq4c_d28fa9;	// NOTE: placeholder name

//==================================================================
// CShell history
//==================================================================

struct OpQ4c_ShellManual2	// NOTE: placeholder name (CShellManual)
{
	char pad00[0x6c];
	CTextInput *input;
	char pad70[0x80 - 0x70];
	string text;
	vector<MapRecord*> records;
	int index;
	vector<MapRecord*> records2;
	int index2;
};

void opq4c_scrollShell8fec50(bool up)	// NOTE: placeholder name
{
	OpQ4c_ShellManual2 *manual = (OpQ4c_ShellManual2*)opq4c_cec100->getManual_48f100();
	if (!manual->text.empty() && (manual->records.size() > 1 || manual->records2.size() > 1))
	{
		vector<MapRecord*> &list = manual->records2.size() ? manual->records2 : manual->records;
		int &index = manual->records2.size() ? manual->index2 : manual->index;
		if (!up)
		{
			index++;
			if (index == list.size())
				index = 0;
		}
		else
		{
			index--;
			if (index < 0)
				index = list.size() - 1;
		}
	}
	else if (up)
	{
		if (opq4c_cef9dc > 0)
		{
			opq4c_cef9dc--;
			manual->input->setText(opq4c_d33d28[opq4c_cef9dc]);
		}
	}
	else if (opq4c_cef9dc < opq4c_d33d28.size())
	{
		opq4c_cef9dc++;
		manual->input->setText(opq4c_cef9dc >= opq4c_d33d28.size() ? string("") : opq4c_d33d28[opq4c_cef9dc]);
	}
}

void opq4c_scrollType8ff120(bool up)	// NOTE: placeholder name
{
	if (up)
	{
		if (opq4c_cebd60 > 0)
		{
			opq4c_cebd60--;
			opq4c_cec10c->input->setText(opq4c_d33d48[opq4c_cebd60]);
		}
	}
	else if (opq4c_cebd60 < opq4c_d33d48.size())
	{
		opq4c_cebd60++;
		opq4c_cec10c->input->setText(opq4c_cebd60 >= opq4c_d33d48.size() ? string("") : opq4c_d33d48[opq4c_cebd60]);
	}
}

struct OpQ4c_ItemType	// NOTE: placeholder name
{
	char pad00[0x24];
	string name;	// NOTE: placeholder name
};

extern vector<unsigned int> opq4c_d3860c;	// NOTE: placeholder name (sorted manual topics)
extern vector<int> opq4c_cfd1cc;	// NOTE: placeholder name
extern vector<OpQ4c_ItemType*> opq4c_d2d1c4;	// NOTE: placeholder name
extern string opq4c_d2d508[];	// NOTE: placeholder name

void opq4c_stripText909840(string &text, bool flag)	// NOTE: placeholder name
{
	if (flag)
	{
		if (text.find('*') != string::npos)
		{
			text.erase(text.begin() + text.find('*'),text.end());
		}
		else if (text.find('@') != string::npos)
		{
			text.erase(text.begin() + text.find('@'),text.end());
		}
	}
	else if (text.find('(') != string::npos)
	{
		text.erase(text.begin() + text.find('(') + 1,text.end());
	}
}

bool opq4c_suggest909990(bool flag)	// NOTE: placeholder name
{
	if (!flag)
		return false;
	OpQ4c_ShellManual2 *manual = (OpQ4c_ShellManual2*)opq4c_cec100->getManual_48f100();
	if (!manual->text.empty() && (!manual->records.empty() || !manual->records2.empty()))
	{
		string command = manual->records2.empty() ? string(opq4c_d2d508[opq4c_d3860c[(int)manual->records[manual->index]]]) : "Schematic(" + opq4c_d2d1c4[opq4c_cfd1cc[(int)manual->records2[manual->index2]]]->name + ")";
		opq4c_stripText909840(command,manual->text.find('(') != string::npos);
		manual->input->setText(command);
		return true;
	}
	return false;
}

//==================================================================
// CCodesCode / CCodes
//==================================================================

class CCodesCode : public Console
{
public:
	CCodesCode(XConsole *parent, int y, int key_, int index_);

	bool input8ff4c0(XEvent *event);	// NOTE: placeholder name (CCodesCode vtable slot 4)

	int key;	// NOTE: placeholder name
	int index;	// NOTE: placeholder name
};

CCodesCode::CCodesCode(XConsole *parent, int y, int key_, int index_)
	: Console(parent,0x32,1,2,y,0,false,-1)
{
	key = key_;
	index = index_;
	string keyText;
	keyText.push_back(key - 0x20);
	print(1,0,keyText);
	putChar_4180b0(3,0,0x2d);
	print(5,0,opq4c_cec108 ? opq4c_d1e930[index] : opq4c_d1e900[index]);
	if ((opq4c_cec108 ? opq4c_d22858[index] : opq4c_d32510[index]) != "N/A")
		print(0xd,0,opq4c_cec108 ? opq4c_d22858[index] : opq4c_d32510[index]);
	print(0x1b,0,opq4c_cec108 ? opq4c_d15e68[index] : opq4c_d1ee10[index]);
	animate("A_CCodesCode_Code");
}

class CCodes : public Console
{
public:
	CCodes(XConsole *parent, const Rect &rect);
	virtual void open();
	virtual void close();
	virtual void trigger(const string &command, int value);

	void unknown9000e0();	// NOTE: placeholder name
	void closeCodes900260(bool keep);	// NOTE: placeholder name
	bool input8ffa60(XEvent *event);	// NOTE: placeholder name (CCodes vtable slot 4)
	void inputAscii8ffad0(int key, int modifier);	// NOTE: placeholder name (CCodes vtable slot 5)

	vector<CCodesCode*> codes;	// NOTE: placeholder name
	Console *unknown7c;	// NOTE: placeholder name
};
extern CCodes *opq4c_cec104;	// NOTE: placeholder name

bool opq4c_createCodes8ff5e0()	// NOTE: placeholder name
{
	if (opq4c_d28fa9)
		return false;
	bool shell = opq4c_cec100;
	int num = 0;
	if (shell)
	{
		for (int i = 0; i < opq4c_d1e920.size(); i++)
		{
			if (opq4c_d1e920[i] && !opq4c_b9930c[i] && (i > 12 || opq4c_cec0f8->getItem_4b1460()->getData()->unknown11))
				num++;
		}
	}
	else
	{
		for (int i = 0; i < opq4c_d1e950.size(); i++)
		{
			if (opq4c_d1e950[i] && !opq4c_b98c50[i])
				num++;
		}
	}
	if (num == 0)
		return false;
	Rect rect;
	rect.width = 0x36;
	rect.height = num + 5;
	if (shell)
	{
		rect.x = opq4c_cec100->getPos().x + opq4c_cec100->getWidth();
		rect.y = opq4c_cec100->getPos().y + ((XConsole*)opq4c_cec100->getManual_48f100())->getPos().y - 1;
	}
	else
	{
		Rect robotRect = *(Rect*)((char*)opq4c_cec108->getManual_4b1b70() + 0xb0);
		robotRect.x += opq4c_cec108->getPos().x + ((XConsole*)opq4c_cec108->getManual_4b1b70())->getPos().x;
		robotRect.y += opq4c_cec108->getPos().y + ((XConsole*)opq4c_cec108->getManual_4b1b70())->getPos().y;
		rect.x = robotRect.x;
		rect.y = robotRect.y - rect.height;
	}
	if (rect.y + rect.height >= opq4c_rex.getHeight_4189a0())
		rect.y -= rect.y + rect.height - opq4c_rex.getHeight_4189a0();
	new CCodes(opq4c_cec034,rect);
	return true;
}

CCodes::CCodes(XConsole *parent, const Rect &rect)
	: Console(parent,rect,0,false,0x1e)
{
	unknown7c = NULL;
	setTitle(new ConsoleTitle(this,"/ C O D E S /",0,0));
	opq4c_cec104 = this;
	open();
}

void CCodes::open()
{
	unknown60 = 3;
	animate("CCodes_Border");
	animate("CCodes_Content");
}

void CCodes::close()
{
	unknown60 = 4;
	closeCodes900260(true);
	getParent()->removeSubconsole(this);
}

bool CCodes::input8ffa60(XEvent *event)
{
	if (isHidden() || opq4c_cefa5f)
		return false;
	if (input429d00(event))
		return true;
	switch (event->type)
	{
		case 0x103:
			opq4c_cefca9 = true;
			closeCodes900260(false);
			return true;
	}
	return false;
}

void CCodes::inputAscii8ffad0(int key, int modifier)
{
	if (opq4c_world->unknown71bbd0())
		return;
	switch (modifier)
	{
		case 0:
		case 1:
		{
			if (modifier == 1)
				key += 0x20;
			for (unsigned int i = 0; i < codes.size(); i++)
			{
				if (codes[i]->key == key)
				{
					codes[i]->input(&XEvent(0x102));
					return;
				}
			}
		}
	}
}

void CCodes::closeCodes900260(bool keep)
{
	if (opq4c_keyMap->hasCommand(0x10))
	{
		opq4c_keyMap->unknown416640();
		if (!keep)
		{
			for (unsigned int i = 0; i < codes.size(); i++)
			{
				codes[i]->engine->killGroup("focus");
				codes[i]->animate("A_CCodesCode_Ascii_Off");
			}
			if (unknown7c)
			{
				removeSubconsole(unknown7c);
				unknown7c = NULL;
			}
		}
	}
}

bool CCodesCode::input8ff4c0(XEvent *event)
{
	if (isHidden() || opq4c_cefa5f)
		return false;
	if (input429d00(event))
		return true;
	switch (event->type)
	{
		case 0x102:
			opq4c_cec104->closeCodes900260(false);
		case 5:
			if (opq4c_cec108)
			{
				opq4c_cec108->getManual_4b1b70()->input->setText(opq4c_d1e930[index]);
				opq4c_cec108->getManual_4b1b70()->input->inputAscii(0xd,5);
			}
			else
			{
				opq4c_cec100->getManual_48f100()->input->setText(opq4c_d1e900[index]);
				opq4c_cec100->getManual_48f100()->input->inputAscii(0xd,5);
			}
			return true;
	}
	return false;
}

void CCodes::trigger(const string &command, int value)
{
	if (command == "headers")
	{
		CText *text = new CText(this,Pos(7,2)," CODE ",0,0,-1);
		text->animate("A_CCodes_Header");
		text = new CText(this,Pos(0xf,2),"  NAME/SRC  ",0,0,-1);
		text->animate("A_CCodes_Header");
		text = new CText(this,Pos(0x1d,2),"        TARGET        ",0,0,-1);
		text->animate("A_CCodes_Header");
	}
	else if (command == "codes")
	{
		int code = 'a';
		int row = 3;
		if (opq4c_cec100)
		{
			for (int i = 0; i < opq4c_d1e920.size(); i++)
			{
				if (opq4c_d1e920[i] && !opq4c_b9930c[i] && (i > 12 || opq4c_cec0f8->getItem_4b1460()->getData()->unknown11))
				{
					codes.push_back(new CCodesCode(this,row,code,i));
					row++;
					code++;
				}
			}
		}
		else
		{
			for (int i = 0; i < opq4c_d1e950.size(); i++)
			{
				if (opq4c_d1e950[i] && !opq4c_b98c50[i])
				{
					codes.push_back(new CCodesCode(this,row,code,i));
					row++;
					code++;
				}
			}
		}
	}
}

void CCodes::unknown9000e0()
{
	opq4c_keyMap->registerConsole(0x10,this,-1,0);
	for (unsigned int i = 0; i < codes.size(); i++)
		codes[i]->animate("A_CCodesCode_Ascii_On");
	unknown7c = new CText(this,Pos(7,getHeight() - 2),"Press Esc to instead type a code manually",0,0,-1);
	unknown7c->animate("A_CCodes_Notice");
}
