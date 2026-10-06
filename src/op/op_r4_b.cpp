// op_r4_b: functions in 0x7a8000-0x7ee000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <ctype.h>
using namespace std;

template <class T> void readBinary(istream &stream, T *value)	// NOTE: placeholder name
{
	stream.read((char*)value,sizeof(T));
}

template <class T> void writeBinary(ostream &stream, T *value)	// NOTE: placeholder name
{
	stream.write((char*)value,sizeof(T));
}

struct OpQ5_T9e2080;
struct OpQ5_T9e2130;
template <class T> void OpQ5_readPointer(istream &stream, T *&p);	// NOTE: placeholder name
template <class T> void OpQ5_writePointer(ostream &stream, T *&p);	// NOTE: placeholder name

void OpR4b_readVector9cf5e0(istream &stream, vector<int> &v);	// NOTE: placeholder name
void OpR4b_writeVector9d2130(ostream &stream, vector<int> &v);	// NOTE: placeholder name

class HProp
{
	int	ID;
public:
	HProp();
	void unknown9cfa90(ostream &stream);	// NOTE: placeholder name
	void unknown9cfaf0(istream &stream);	// NOTE: placeholder name
};

class OpR4b_Rec7a9f70	// NOTE: placeholder name
{
public:
	int					v0;
	HProp				prop;
	int					v8;
	bool				vc;
	int					v10;
	int					v14;
	int					v18;
	vector<int>			list;
	int					v2c;
	OpQ5_T9e2130		*ptr;

	OpR4b_Rec7a9f70(istream &stream);	// 0x7a9f70
	void write(ostream &stream);		// 0x7aa090
};

OpR4b_Rec7a9f70::OpR4b_Rec7a9f70(istream &stream)
{
	readBinary(stream,&v0);
	prop.unknown9cfaf0(stream);
	readBinary(stream,&v8);
	readBinary(stream,&vc);
	readBinary(stream,&v10);
	readBinary(stream,&v14);
	readBinary(stream,&v18);
	OpR4b_readVector9cf5e0(stream,list);
	readBinary(stream,&v2c);
	OpQ5_readPointer(stream,(OpQ5_T9e2080*&)ptr);
}

void OpR4b_Rec7a9f70::write(ostream &stream)
{
	writeBinary(stream,&v0);
	prop.unknown9cfa90(stream);
	writeBinary(stream,&v8);
	writeBinary(stream,&vc);
	writeBinary(stream,&v10);
	writeBinary(stream,&v14);
	writeBinary(stream,&v18);
	OpR4b_writeVector9d2130(stream,list);
	writeBinary(stream,&v2c);
	OpQ5_writePointer(stream,ptr);
}

//==================================================================
// Console UI (declarations shared with op_y6.cpp)
//==================================================================


//==================================================================
// engine-side declarations
//==================================================================

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
};

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);
	Pos(const Pos &pos) throw();
};

struct OpY6_Pos2	// NOTE: placeholder name
{
	int x;
	int y;
};

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
	Pos getPos();
	void setHidden(bool hidden_);	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);
	bool input429d00(void *event);	// NOTE: placeholder name (XConsole::input body)
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)

	char pad04[0x60 - 0x04];
};

class Engine
{
public:
	bool isRunning();	// NOTE: placeholder name (0x50fff0)
	void killGroup(string group);
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

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);

	string text;
};

class OpY6_Mouse	// NOTE: placeholder name (pointer global at 0xcefa94)
{
public:
	bool isHovered(XConsole *console);	// NOTE: placeholder name (0x41a760)
};
extern OpY6_Mouse *opY6_mouse;	// NOTE: placeholder name

class OpY6_Rex	// NOTE: placeholder name (object at 0xd223f0)
{
public:
	int getHeight_4189a0();	// NOTE: placeholder name
};
extern OpY6_Rex opY6_rex;	// NOTE: placeholder name

extern bool opY6_consoleInputBlocked;	// NOTE: placeholder name (0xcefa5f)
void opY6_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)
string opY6_toUpper(const string &text);	// NOTE: placeholder name (0x4083a0)
bool opY6_contains(vector<int> &values, int value);	// NOTE: placeholder name (0x9db330)
int opY6_centerOffset(int inner, int outer);	// NOTE: placeholder name (0x437190)

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern int opW5_anim_cef85c;	// NOTE: placeholder name
extern int opW5_anim_cef970;	// NOTE: placeholder name
extern int opW5_anim_cef978;	// NOTE: placeholder name

extern int opY6_fontCellSize;	// NOTE: placeholder name (0xcaf128)
extern int opY6_unknown_cf27f4;	// NOTE: placeholder name
extern int opY6_anim_cef884;	// NOTE: placeholder name
extern OpY6_Pos2 opY6_advancedPos;	// NOTE: placeholder name (0xd323bc)
extern bool opY6_unknown_d257d4;	// NOTE: placeholder name
extern bool opY6_unknown_d28d6c;	// NOTE: placeholder name
extern vector<int> opY6_unknown_d22590;	// NOTE: placeholder name
extern int opY6_achievementState_d28d84;	// NOTE: placeholder name
extern int opY6_achievementState_d28d88;	// NOTE: placeholder name
extern string opY6_strings_d2e8f8[];	// NOTE: placeholder name
extern string opY6_strings_d15db0[];	// NOTE: placeholder name
extern string opY6_strings_d1e1e0[];	// NOTE: placeholder name
extern string opY6_strings_d1e448[];	// NOTE: placeholder name
extern vector<bool> opY6_achievementCategories;	// NOTE: placeholder name (0xd28d70)

//==================================================================
// CCommands*
//==================================================================

class CCommandsAdvancedPageButton : public Console
{
public:
	virtual bool mouseEnter();

	bool next;	// NOTE: placeholder name
	bool enabled;	// NOTE: placeholder name
};

bool CCommandsAdvancedPageButton::mouseEnter()
{
	if (enabled != 1)
		return false;
	animate("A_ButtonHover_Begin_EVOL_HOV_OK");
	return true;
}

//==================================================================
// CGamemenu*
//==================================================================

extern int opW5_anim_cef85c;	// NOTE: placeholder name
extern int opW5_anim_cef970;	// NOTE: placeholder name
extern int opW5_anim_cef978;	// NOTE: placeholder name

class CGamemenuButton : public Console
{
public:
	virtual bool mouseEnter();

	int key;	// NOTE: placeholder name
	int index;	// NOTE: placeholder name
};

bool CGamemenuButton::mouseEnter()
{
	unknown48c3c0(index == 0 ? opW5_anim_cef85c : (index == 1 ? opW5_anim_cef970 : opW5_anim_cef978));
	return true;
}

class CGamemenuSaveloadButton : public Console
{
public:
	virtual bool mouseEnter();

	int type;	// NOTE: placeholder name
	char pad70[0x88 - 0x70];
	bool hasSave;	// NOTE: placeholder name
};

bool CGamemenuSaveloadButton::mouseEnter()
{
	if (type == 1 && !hasSave)
		return false;
	unknown48c3c0(type == 0 ? opW5_anim_cef85c : opW5_anim_cef970);
	return true;
}

//==================================================================
// CCommands (the Manual window; global pointer at 0xcec03c) and related
//==================================================================

struct OpY6_ManualSection	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	string title;	// NOTE: placeholder name
	vector<string> lines;	// NOTE: placeholder name
	vector<int> headers;	// NOTE: placeholder name
};
extern vector<OpY6_ManualSection*> opY6_manualSections;	// NOTE: placeholder name (0xcf39dc)

class CManualButton : public Console
{
public:
	void unknown7c56e0();	// NOTE: placeholder name
};

class CManualText : public Console
{
public:
	CManualText(XConsole *parent, int y, const string &text, bool header_);

	bool header;	// NOTE: placeholder name
};

class CManualPageButton : public Console
{
public:
	CManualPageButton(XConsole *parent, bool flag_);

	bool flag;	// NOTE: placeholder name
};

class CCommandsButton : public Console
{
public:
	void draw(int mode);	// NOTE: placeholder name
};

class CCommandPage : public XConsole	// NOTE: placeholder name
{
public:
	int getPage() { return page; };	// NOTE: placeholder name

	char pad[0x6c - sizeof(XConsole)];
	int page;
};

class CCommands : public Console
{
public:
	void setAdvancedCommandsPage(int page);

	void unknown7d1050(int mode);	// NOTE: placeholder name
	void unknown7d1130();	// NOTE: placeholder name
	void unknown7d1340();	// NOTE: placeholder name
	void unknown7d14d0(int section);	// NOTE: placeholder name
	void unknown7d1740();	// NOTE: placeholder name
	void unknown7d17d0();	// NOTE: placeholder name
	void unknown7d1840();	// NOTE: placeholder name
	void unknown7d18d0();	// NOTE: placeholder name
	int unknown7c6830();	// NOTE: placeholder name
	int getMaxHeight();	// NOTE: placeholder name (0x4963e0)
	int getRange();	// NOTE: placeholder name (0x496560)

	int ID;	// NOTE: placeholder name
	vector<CCommandsButton*> tabButtons;	// NOTE: placeholder name
	char pad80[0xc4 - 0x80];
	CCommandPage *pageIndicator;	// NOTE: placeholder name
	char padc8[0xd0 - 0xc8];
	CText *title;	// NOTE: placeholder name
	vector<CManualButton*> sectionButtons;	// NOTE: placeholder name
	int page;	// NOTE: placeholder name
	vector<Console*> lines;	// NOTE: placeholder name
	int scroll;	// NOTE: placeholder name
	int unknownfc;	// NOTE: placeholder name
	int prevPage;	// NOTE: placeholder name
	CManualPageButton *nextButton;	// NOTE: placeholder name
	CManualPageButton *prevButton;	// NOTE: placeholder name
};

void CCommands::unknown7d1130()
{
	int row;
	unsigned int i;
	int posY;
	for (i = 0; i < lines.size(); i++)
	{
		if (lines[i])
			removeSubconsole(lines[i]);
	}
	lines.clear();
	row = scroll;
	posY = unknown7c6830();
	for (; row < opY6_manualSections[page]->lines.size() && posY <= getMaxHeight(); row++, posY++)
	{
		if (opY6_manualSections[page]->lines[row].empty())
			lines.push_back(NULL);
		else
			lines.push_back(new CManualText(this,posY,opY6_manualSections[page]->lines[row],opY6_contains(opY6_manualSections[page]->headers,row)));
	}
	opY6_playSound(0x31,0,0);
}

class CAchievementsCategoryButton : public Console
{
public:
	virtual bool mouseEnter();
	virtual bool input(void *event);

	int category;	// NOTE: placeholder name
};

class CAchievements : public Console
{
public:
	virtual ~CAchievements();
};
extern CAchievements *opY6_achievements;	// NOTE: placeholder name (0xcec048)

class CAchievementsStateButton : public Console
{
public:
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);

	int state;	// NOTE: placeholder name
	bool primary;	// NOTE: placeholder name
};

bool CAchievementsStateButton::input(void *event)
{
	switch (*(int*)event)
	{
		case 0x26:
			opY6_achievements->inputMouse(tolower(primary ? opY6_strings_d1e1e0[state][0] : opY6_strings_d1e448[state][0]),0);
			return true;
	}
	return false;
}

bool OpR4b_matchesKey(const string &text, char key)	// NOTE: placeholder name (0x7e88b0)
{
	return (text.size() >= 5 && text[3] == '.' && text[4] == ' ' ? text[5] : text[0]) == key;
}

struct OpR4b_ItemType	// NOTE: placeholder name; element of the vector at 0xd2d1c4
{
	int pad0, pad4;
	string name;
};
extern vector<OpR4b_ItemType *> opR4b_itemTypes;	// NOTE: placeholder name (0xd2d1c4)

bool opR4b_inRange(int low, int value, int high);	// NOTE: placeholder name (0x9daf80)

class CGalleryItem : public Console
{
public:
	CGalleryItem(XConsole *parent, int x, int y, int value, int index);	// 0x7d6db0

	int unknown6c;	// NOTE: placeholder name
	int pos;	// NOTE: placeholder name
	char pad74[0x7c - 0x74];
};

bool opr1c_hasPtr_cebd5c();	// NOTE: placeholder name (0x4328a0)
extern int opR4b_rowSpacing_bcbdf4[2];	// NOTE: placeholder name
void opR4b_insertAt(vector<CGalleryItem*> &v, int index, CGalleryItem *value);	// NOTE: placeholder name (0x9dbdc0)

class CGallery : public Console
{
public:
	bool unknown7e8920(char key);	// NOTE: placeholder name
	void unknown7e8a50(int rows, int index, Pos *pos, bool add);	// NOTE: placeholder name
	void unknown7e83f0(int amount);	// NOTE: placeholder name

	char pad6c[0x74 - 0x6c];
	vector<int> list;	// NOTE: placeholder name
	char pad84[0xa4 - 0x84];
	vector<CGalleryItem*> items;	// NOTE: placeholder name
};

class CLore : public Console
{
public:
	virtual ~CLore();

	void unknown7eafe0(int value, int flag);	// NOTE: placeholder name
	void unknown7e91e0();	// NOTE: placeholder name
	void unknown7ebd60(int key);	// NOTE: placeholder name
	virtual bool input(void *event);	// 0x7e92a0
};

bool CGallery::unknown7e8920(char key)
{
	int index = -1;
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (OpR4b_matchesKey(opR4b_itemTypes[list[i]]->name,key))
		{
			index = i;
			break;
		}
	}
	if (index == -1)
		return false;
	if (!opR4b_inRange(items.front()->pos,index,items.back()->pos))
	{
		if (index < items.back()->pos)
			unknown7e83f0((items.front()->pos - index) / -3 - 1);
		else
			unknown7e83f0((index - items.back()->pos) / 3 + 1);
	}
	return true;
}

void CGallery::unknown7e8a50(int rows, int index, Pos *pos, bool add)
{
	int n = 0;
	for (int row = 0, y = pos->y; row < rows; row++, y += 0xd + opR4b_rowSpacing_bcbdf4[opr1c_hasPtr_cebd5c() ? 1 : 0])
	{
		for (int c = 0, x = pos->x; c < 3; c++, x += 0x32, index++, n++)
		{
			if (index >= list.size())
				return;
			if (add)
				opR4b_insertAt(items,n,new CGalleryItem(this,x,y,list[index],index));
			else
				items.push_back(new CGalleryItem(this,x,y,list[index],index));
		}
	}
}

extern CLore *opR4b_lore;	// NOTE: placeholder name (0xcec044)
extern XConsole *opR4b_commands;	// NOTE: placeholder name (0xcec03c)
extern int opR4b_detailsHeight_bcbdfc[2];	// NOTE: placeholder name

bool CLore::input(void *event)
{
	if (isHidden() || opY6_consoleInputBlocked)
		return false;
	if (input429d00(event))
		return true;
	switch (*(int*)event)
	{
		case 0x27:
			unknown7eafe0(1,-1);
			return true;
		case 0x28:
			unknown7eafe0(-1,-1);
			return true;
		case 0x29:
			unknown7eafe0(10,*(int*)event);
			return true;
		case 0x2a:
			unknown7eafe0(-10,*(int*)event);
			return true;
		case 0x2b:
			unknown7eafe0(-10000,*(int*)event);
			return true;
		case 0x2c:
			unknown7eafe0(10000,*(int*)event);
			return true;
		case 0x2d:
			unknown7e91e0();
			return true;
	}
	return false;
}

class CLoreDetails : public Console
{
public:
	CLoreDetails();	// 0x7e8c90
	virtual bool input(void *event);
};

CLoreDetails::CLoreDetails()
	: Console(opR4b_commands,0x62,opR4b_detailsHeight_bcbdfc[opr1c_hasPtr_cebd5c() ? 1 : 0],opR4b_lore->getPos().x + 0x36,opR4b_lore->getPos().y,0,false,10)
{
	animate("CLoreDetails_Border");
	unknown60 = 3;
}
