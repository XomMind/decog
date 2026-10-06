// op_r5a (UI): CMapFine, CPay2Buy*, CRpglike* consoles in 0x874000-0x879500 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
#include <iosfwd>
#include "../util/rng.h"
using namespace std;

//==================================================================
// engine-side declarations
//==================================================================

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(int r_, int g_, int b_);
	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
	XColor operator*(float f);
	XColor &operator*=(float f);
	bool operator!=(XColor color);
};

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);
	explicit Pos(int v);	// 0x409990
	void set_409ff0(int v);	// NOTE: placeholder name (sets both coordinates)
	Pos(const Pos &pos) throw();
	Pos &operator=(const Pos &pos);	// 0x46ca50
	Pos operator+(const Pos &pos) const;	// 0x409b60
	bool operator!=(const Pos &pos) const;	// 0x409bd0
	bool operator==(const Pos &pos) const;	// 0x409b90
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(int x_, int y_, int width_, int height_) throw();	// 0x456940 (throw() as in op_w9.cpp: it cannot throw)
	Rect(const Rect &rect);
};

class XConsole;

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
	XConsole *getParent();	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);
	void print(int x, int y, const string &text);	// NOTE: placeholder name
	void printAligned(int x, int y, int align, const string &text);	// NOTE: placeholder name
	void setFore(XColor color) throw();
	void clearBack();	// NOTE: placeholder name
	void putChar_4180b0(int x, int y, int ch);	// NOTE: placeholder name
	void setCharRow(int x, int y, int width, int ch);	// NOTE: placeholder name
	void setCharRow(int x, int y, int width, int ch, XColor fore);	// NOTE: placeholder name
	void setCharColumn(int x, int y, int height, int ch, XColor fore);	// NOTE: placeholder name
	void setBackRow(int x, int y, int width, XColor color);
	void setForeRow(int x, int y, int width, XColor color);	// NOTE: placeholder name
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	void setBackAll_418410(XColor color);	// NOTE: placeholder name
	void setPos(int x, int y);	// NOTE: placeholder name
	void setPos(const Pos &pos);
	void setHidden(bool hidden_);	// NOTE: placeholder name
	vector<XConsole*> *getSubconsoles() throw();
	void clear();	// NOTE: placeholder name
	int getLayer_44a7d0();	// NOTE: placeholder name
	void setChar_417f50(int x, int y, int ch);	// NOTE: placeholder name
	void putChar_418110(int x, int y, int ch, XColor fore);	// NOTE: placeholder name
	void resetBack_418450() throw();	// NOTE: placeholder name
	void setForeAll_4183d0(XColor color);	// NOTE: placeholder name
	void unknown429fe0(XConsole *console, const Pos &pos, int value);	// NOTE: placeholder name
	void clearInterior();
	int countLines_418350(int x, int y, int width, int height, int align, const string &text);
	bool input429d00(void *event);	// NOTE: placeholder name (XConsole::input body)
	void unknown429f10(int a, int b);	// NOTE: placeholder name
	void deleteSubconsoles();

	char pad04[0x60 - 0x04];
};

class OpW5_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class Engine
{
public:
	bool isRunning();	// NOTE: placeholder name (0x50fff0)
	void render();	// NOTE: placeholder name (0x5100b0)
	void stopAll();	// NOTE: placeholder name (0x50ff30)
	class OpW5_EngineItem *unknown50fb50(Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
	void killGroup(string group);
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual ~Console();

	virtual bool input(void *event);
	virtual void update();
	virtual void render();	// NOTE: placeholder name
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	void animate(string name);	// NOTE: placeholder name
	bool isActive_7ad420();	// NOTE: placeholder name
	Rect getRect();	// NOTE: placeholder name
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void setTitle(class ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void unknown7b0640(int a, XColor color, int b, int c);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	void *title;
};

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)

class OpW5_GameData	// NOTE: placeholder name (object at 0xd1e860)
{
public:
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
};
extern OpW5_GameData opW5_gameData;	// NOTE: placeholder name (0xd1e860)
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
bool opW5_replace(string &text, string from, string to);	// NOTE: placeholder name (0x407e00)
bool opW5_findAnimation(const string &name, int *index);	// NOTE: placeholder name (0x9d45a0)

struct OpW5_Point	// NOTE: placeholder name
{
	int x;
	int y;

	OpW5_Point() throw();	// 0x453b40
	OpW5_Point(int v);	// 0x409990
};

extern int opW5_unknown_cf4b38;	// NOTE: placeholder name
extern XConsole *opW5_cec034;	// NOTE: placeholder name

class OpW5_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void registerConsole(int command, Console *console, int unknown1, int unknown2);	// NOTE: placeholder name (0x416790)
	void unknown4162e0(int command, int value);	// NOTE: placeholder name
};
extern OpW5_KeyMap *opW5_keyMap;	// NOTE: placeholder name

class OpW5_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	Pos getPos_40a970();	// NOTE: placeholder name
};
extern OpW5_Mouse *opW5_mouse;	// NOTE: placeholder name

class OpW5_Rex	// NOTE: placeholder name (0xd223f0)
{
public:
	XConsole *getConsole_4ab670();	// NOTE: placeholder name (folded getter)
	int getWidth_418980();	// NOTE: placeholder name
	int getHeight_4189a0();	// NOTE: placeholder name
	bool unknown404af0();	// NOTE: placeholder name
	bool unknown4188e0();	// NOTE: placeholder name
};
extern OpW5_Rex opW5_rex;	// NOTE: placeholder name

extern string gameStrings_d26040[];	// NOTE: placeholder name

string intToString(int value);
string &opR5b_padLeft(string &s, int width, char c);	// NOTE: placeholder name (0x408090)
void opR5b_playSound_4541b0(int sound, int a, int b);	// NOTE: placeholder name
bool opR5b_anyNonZero(vector<int> &values);	// NOTE: placeholder name (0x9d7f70)
extern bool opR5b_inputBlocked;	// NOTE: placeholder name (0xcefa5f)
extern XColor *opR5b_color_cfe674;	// NOTE: placeholder name
extern XColor *opR5b_color_cf44c0;	// NOTE: placeholder name
extern XColor *opR5b_color_d204ac;	// NOTE: placeholder name
extern XColor *opR5b_color_d29758;	// NOTE: placeholder name
extern XColor *opR5b_color_d2981c;	// NOTE: placeholder name

class CInfo : public Console
{
public:
	void unknown8b5080();	// NOTE: placeholder name
};
extern CInfo *opR5b_cec118;	// NOTE: placeholder name
extern CInfo *opR5b_cec11c;	// NOTE: placeholder name
extern CInfo *opR5b_cec120;	// NOTE: placeholder name

//==================================================================
// CRpglikeUpgrade*
//==================================================================

int opW5_getUpgradeCost(int id, int offset);	// NOTE: placeholder name
int opW5_getUpgradeAmount(int id, int count);	// NOTE: placeholder name

// NOTE: the verifier pairs a data symbol only at offset 0, so a column of the table at 0xba7930 is reached through a view
struct OpR5b_UpgradeInfoView	// NOTE: placeholder name
{
	int value;
	int pad[3];
};
extern OpR5b_UpgradeInfoView opR5b_upgradeLimit[];	// NOTE: placeholder name (0xba793c)

class CRpglikeUpgradeButton : public Console
{
public:
	CRpglikeUpgradeButton(XConsole *parent, int x, int ID_, bool next_);

	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);

	void refresh();	// NOTE: placeholder name (0x879300)

	int ID;	// NOTE: placeholder name
	bool next;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
};

class CRpglikeUpgradeCurrent : public Console
{
public:
	CRpglikeUpgradeCurrent(XConsole *parent, int x, int ID_);

	void refresh();	// NOTE: placeholder name (0x879390)

	int ID;	// NOTE: placeholder name
};

class CRpglikeUpgrade : public Console
{
public:
	CRpglikeUpgrade(XConsole *parent, int x, int y, int ID_);

	void refresh();	// NOTE: placeholder name (0x879500)

	int ID;	// NOTE: placeholder name
	CRpglikeUpgradeCurrent *current;	// NOTE: placeholder name
	CRpglikeUpgradeButton *previous;	// NOTE: placeholder name
	CRpglikeUpgradeButton *next;	// NOTE: placeholder name
};

class CRpglikeUpgradesConfirmButton : public Console
{
public:
	CRpglikeUpgradesConfirmButton(XConsole *parent, int x, int y, int width, bool confirm_);

	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
	virtual void render();	// NOTE: placeholder name

	bool confirm;	// NOTE: placeholder name
};

class CCloseButton : public Console
{
public:
	char pad6c[0x8c - 0x6c];
};

class CRpglikeUpgrades : public Console
{
public:
	CRpglikeUpgrades(XConsole *parent);
	virtual ~CRpglikeUpgrades();

	virtual bool input(void *event);
	virtual void inputMouse(int key, int type);	// NOTE: placeholder name
	virtual void render();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name

	void unknown87a220();	// NOTE: placeholder name
	void unknown87a260(bool flag);	// NOTE: placeholder name
	int unknown87a040(int id, bool increase, bool test);	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
	CCloseButton *closeButton;	// NOTE: placeholder name
	vector<CRpglikeUpgrade*> upgrades;	// NOTE: placeholder name
	CRpglikeUpgradesConfirmButton *confirmButton;	// NOTE: placeholder name
	class CText *enterText;	// NOTE: placeholder name
	CRpglikeUpgradesConfirmButton *resetButton;	// NOTE: placeholder name
	class CText *resetText;	// NOTE: placeholder name
	int unknown94;	// NOTE: placeholder name
	int unknown98;	// NOTE: placeholder name
	int unknown9c;	// NOTE: placeholder name
	vector<int> unknowna0;	// NOTE: placeholder name
	bool unknownb0;	// NOTE: placeholder name
};
extern CRpglikeUpgrades *opW5_rpglikeUpgrades;	// NOTE: placeholder name (0xcec064)

extern XColor *opR5a_color_d20438;	// NOTE: placeholder name
extern XColor *opR5a_color_cf13fc;	// NOTE: placeholder name
extern XColor *opR5a_color_d1d46c;	// NOTE: placeholder name
extern XColor *opR5a_color_d25f60;	// NOTE: placeholder name
extern XColor *opR5a_color_d2175c;	// NOTE: placeholder name
extern XColor *opR5a_color_cfabbc;	// NOTE: placeholder name
extern XColor *opR5a_color_cf44c0;
extern XColor *opR5a_color_d2981c;
extern XColor *opR5a_color_d204ac;	// NOTE: placeholder name
extern bool opR5a_cf46a0;	// NOTE: placeholder name

class BS	// NOTE: placeholder layout (object at 0xcefc4c)
{
public:
	bool unknown71bbd0();	// NOTE: placeholder name
};
extern BS *opR5a_world;	// NOTE: placeholder name (0xcefc4c)

class MapView : public Console
{
public:
	void unknown49ad70(unsigned int time);	// NOTE: placeholder name
};
extern MapView *opR5a_mapView;	// NOTE: placeholder name (0xcec054)

//==================================================================
// CPay2BuyButton / CPay2Buy
//==================================================================

class CPay2BuyButton : public Console
{
public:
	virtual bool input(void *event);
};

class CPay2Buy : public Console
{
public:
	virtual void render();	// NOTE: placeholder name
};

extern void *opR5a_cec130;	// NOTE: placeholder name (CList at 0xcec130)
extern int opR5a_d35794;	// NOTE: placeholder name
extern int opR5a_d35798;	// NOTE: placeholder name
extern int opR5a_cf4630;	// NOTE: placeholder name (CogCoins)
string OpY1_intToStringGrouped(int value);	// NOTE: placeholder name (0x405330)
void opR5a_unknown8779a0();	// NOTE: placeholder name

bool CPay2BuyButton::input(void *event)
{
	if (isHidden() || opR5b_inputBlocked)
		return false;
	if (input429d00(event))
		return true;
	if (opR5a_world->unknown71bbd0())
		return false;
	switch (*(int*)event)
	{
		case 5:
			opR5a_mapView->unknown49ad70(tickCount + 500);
		case 0x98:
			if (!opR5a_cec130)
			{
				opR5a_unknown8779a0();
				return true;
			}
			else
				return false;
	}
	return false;
}

void CPay2Buy::render()
{
	if (isHidden())
		return;
	engine->render();
	setFore(*opR5b_color_d2981c);
	setForeRow(opR5a_d35794,1,0xb,*opR5b_color_cfe674);
	print(opR5a_d35794,opR5a_d35798,OpY1_intToStringGrouped(opR5a_cf4630));
	XConsole::render();
}

//==================================================================
// CRpglikeUpgradeButton / CRpglikeUpgradeCurrent
//==================================================================

extern XColor *opR5a_color_cfe674;	// NOTE: placeholder name
extern XColor *opR5a_color_d29758;	// NOTE: placeholder name

bool CRpglikeUpgradeButton::mouseEnter()
{
	if (unknown74 != 1)
		return false;
	animate("A_ButtonHover_Begin_EVOL_HOV_OK");
	return true;
}

bool CRpglikeUpgradeButton::input(void *event)
{
	if (isHidden() || opR5b_inputBlocked)
		return false;
	if (input429d00(event))
		return true;
	switch (*(int*)event)
	{
		case 5:
			opW5_rpglikeUpgrades->inputMouse((next ? 0x61 : 0x41) + ID,!next);
			return true;
	}
	return false;
}

void CRpglikeUpgradeButton::refresh()
{
	unknown74 = opW5_rpglikeUpgrades->unknown87a040(ID,next,true);
	setForeAll_4183d0(unknown74 == 1 ? *opR5a_color_d2981c : (unknown74 == 0 ? *opR5a_color_d29758 : *opR5a_color_d204ac));
}

void CRpglikeUpgradeCurrent::refresh()
{
	if (opW5_rpglikeUpgrades->unknowna0[ID])
	{
		setBackAll_418410(*opR5a_color_d20438);
		setCharRow(1,0,5,'0',*opR5a_color_cf13fc);
	}
	else
	{
		setBackAll_418410(*opR5a_color_d2981c);
		setCharRow(1,0,5,'0',XColor(0,0x9b,0));
	}
	setFore(*opR5a_color_cfe674);
	int amount = opW5_getUpgradeAmount(ID,opW5_rpglikeUpgrades->unknowna0[ID]);
	if (amount)
		printAligned(5,0,2,intToString(amount));
}

//==================================================================
// CMapFine
//==================================================================

class OpR5a_ItemData	// NOTE: placeholder name
{
public:
	char pad00[0x1b0];
};

class OpR5a_Item	// NOTE: placeholder name (Item)
{
public:
	int getField457820();	// NOTE: placeholder name (folded getter)
	int getField4578a0();	// NOTE: placeholder name (folded getter)
	bool unknown457d70();	// NOTE: placeholder name
	bool unknown457db0();	// NOTE: placeholder name
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	OpR5a_Item *operator->() const;	// 0x9b65b0
};

void logError(string location, string message);	// NOTE: placeholder name
extern vector<int> opR5a_cf4830;	// NOTE: placeholder name
extern int opR5a_caf128;	// NOTE: placeholder name

struct OpR5a_FineTimer	// NOTE: placeholder name (OpW5_FineTimer)
{
	OpR5a_FineTimer(int a, int b);	// 0x49c750
};

class CMapFine : public Console
{
public:
	virtual ~CMapFine();

	void addNewInventoryItemIndicator(HItem item);

	char pad6c[0xb8 - 0x6c];
	vector<OpR5a_FineTimer*> timers;	// NOTE: placeholder name
};
extern CMapFine *opR5a_mapFine;	// NOTE: placeholder name (0xcec058)

void CMapFine::addNewInventoryItemIndicator(HItem item)
{
	if (!item.operator->())
	{
		logError("CMapFine::addNewInventoryItemIndicator()","item no longer exists!");
		return;
	}
	string text = " " + item->getName(0,1) + " >> ";
	Console *console = new Console(opR5a_mapFine,text.size(),1,opR5a_mapView->getWidth() * opR5a_caf128 - text.size(),-1,0,false,0x19);
	console->print(0,0,text);
	string animation;
	if (item->getField4578a0() == 5)
		animation = "A_CInvItem_Item_Instant";
	else if (opR5a_cf4830[item->getField457820()] != 0 && !item->unknown457d70())
		animation = "A_CInvItem_Broken_Instant";
	else if (item->unknown457db0())
		animation = "A_CInvItem_Corrupted_Instant";
	else
		animation = "A_CInvItem_Part_Instant";
	console->animate(animation);
	timers.push_back(new OpR5a_FineTimer((int)console,item.ID));
}
