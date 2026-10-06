// op_r5b: CRpglikeUpgrade*, CPlayer2/CPolymind buttons, CVolley, CParts*, CPart* UI consoles in 0x879500-0x894e20 matched against COGMIND.exe (Beta 17.1).
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

bool CRpglikeUpgradesConfirmButton::input(void *event)
{
	if (isHidden() || opR5b_inputBlocked)
		return false;
	if (input429d00(event))
		return true;
	switch (*(int*)event)
	{
		case 0x196:
			if (confirm)
				opW5_rpglikeUpgrades->unknown87a220();
			else
				opW5_rpglikeUpgrades->unknown87a260(true);
			return true;
		default:
			return false;
	}
}

void CRpglikeUpgradesConfirmButton::render()
{
	if (isHidden())
		return;
	engine->render();
	setForeAll_4183d0(opR5b_anyNonZero(opW5_rpglikeUpgrades->unknowna0) ? *opR5b_color_d2981c : *opR5b_color_cf44c0);
	XConsole::render();
}

void CRpglikeUpgrade::refresh()
{
	setForeRow(0x1b,0,4,*opR5b_color_cfe674);
	bool isMax = opW5_rpglikeUpgrades->unknown87a040(ID,true,true) == -1;
	bool expensive = !isMax && opW5_rpglikeUpgrades->unknown9c < opW5_getUpgradeCost(ID,opW5_rpglikeUpgrades->unknowna0[ID]);
	string str = isMax ? string("MAX") : intToString(opW5_getUpgradeCost(ID,opW5_rpglikeUpgrades->unknowna0[ID]));
	opR5b_padLeft(str,4,' ');
	setFore(isMax ? *opR5b_color_d204ac : (expensive ? *opR5b_color_d29758 : *opR5b_color_d2981c));
	print(0x1b,0,str);
}

extern int opR5b_cf469c;	// NOTE: placeholder name
extern int opR5b_cf0c60;	// NOTE: placeholder name
extern int opR5b_cf0c64;	// NOTE: placeholder name
extern int opR5b_d1e854;	// NOTE: placeholder name
extern int opR5b_d1e858;	// NOTE: placeholder name
bool opR5b_anyPositive(vector<int> &values);	// NOTE: placeholder name (0x9d54c0)
int opR5b_sumRange(vector<int> *values, int first, int count);	// NOTE: placeholder name (0x9d43f0)
extern bool opR5b_cf46a0;	// NOTE: placeholder name

void CRpglikeUpgrades::close()
{
	if (unknown60 == 4)
		return;
	unknown60 = 4;
	unknown429f10(0,0);
	deleteSubconsoles();
	opW5_keyMap->unknown4162e0(0x22,0);
	unknown6c = tickCount;
	animate("A_BlockFadeVis");
	if (!opR5b_cec118->isHidden())
		opR5b_cec118->unknown8b5080();
	if (!opR5b_cec11c->isHidden())
		opR5b_cec11c->unknown8b5080();
	if (!opR5b_cec120->isHidden())
		opR5b_cec120->unknown8b5080();
}

void CRpglikeUpgrades::unknown87a220()
{
	if (!isActive_7ad420())
		return;
	unknownb0 = true;
	close();
}

class Entity	// NOTE: placeholder layout
{
public:
	int getSlotTotal();
	int unknown5d1390();	// NOTE: placeholder name
	int unknown44a7d0();	// NOTE: placeholder name
	int unknown5d15a0(bool notify);	// NOTE: placeholder name
	int unknown5d1d70();	// NOTE: placeholder name
	int unknown45a700();	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
	Entity *operator->() const throw();	// 0x9b6570
};

class Map	// NOTE: placeholder layout (object at 0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
};
extern Map *opR5b_map;	// NOTE: placeholder name (0xcefc4c)

class BS	// NOTE: placeholder layout (object at 0xcefc4c)
{
public:
	bool unknown71bbd0();	// NOTE: placeholder name
	HEntity getEntity671();	// NOTE: placeholder name (0x463110)
};
extern BS *opR5b_world;	// NOTE: placeholder name (0xcefc4c)

int CRpglikeUpgrades::unknown87a040(int id, bool increase, bool test)
{
	if (increase)
	{
		switch (opR5b_upgradeLimit[id].value)
		{
			case 0:
				break;
			case -1:
				if (opR5b_map->getPlayer()->getSlotTotal() + opR5b_sumRange(&unknowna0,0,3) == 0x1a)
					return -1;
				break;
			default:
				if (opW5_getUpgradeAmount(id,unknowna0[id]) >= opR5b_upgradeLimit[id].value)
					return -1;
		}
		int cost = opW5_getUpgradeCost(id,unknowna0[id]);
		if (unknown9c < cost)
			return 0;
		if (test)
			return 1;
		else
		{
			unknown9c -= cost;
			unknowna0[id]++;
			return 1;
		}
	}
	else
	{
		if (unknowna0[id] == 0)
			return 0;
		else
		{
			if (test)
				return 1;
			else
			{
				unknowna0[id]--;
				unknown9c += opW5_getUpgradeCost(id,unknowna0[id]);
				return 1;
			}
		}
	}
}

void CRpglikeUpgrades::unknown87a260(bool flag)
{
	if (flag && opR5b_anyPositive(unknowna0))
		opR5b_playSound_4541b0(0x28,0,0);
	unknown9c = opR5b_cf469c;
	unknowna0.assign(0x18u,0);
	for (unsigned int i = 0; i < upgrades.size(); i++)
	{
		if (upgrades[i])
			removeSubconsole(upgrades[i]);
	}
	upgrades.clear();
	for (int i = 0, y = opR5b_cf0c64; i < 0x18; i++, y++)
		upgrades.push_back(new CRpglikeUpgrade(this,opR5b_cf0c60,y,i));
}

bool CRpglikeUpgrades::input(void *event)
{
	if (isHidden() || opR5b_inputBlocked)
		return false;
	if (input429d00(event))
		return true;
	switch (*(int*)event)
	{
		case 0x197:
			unknown87a220();
			return true;
		case 0x198:
			if (unknown94 <= 0)
				unknown94 = upgrades.size() - 1;
			else
				unknown94--;
			return true;
		case 0x199:
			if (unknown94 == upgrades.size() - 1)
				unknown94 = 0;
			else
				unknown94++;
			return true;
		case 0x19a:
			if (unknown94 != -1)
				inputMouse(unknown94 + 0x61,0);
			return true;
		case 0x19b:
			if (unknown94 != -1)
				inputMouse(unknown94 + 0x41,1);
			return true;
		case 0x19c:
			close();
			return true;
		default:
			return false;
	}
}

void CRpglikeUpgrades::inputMouse(int key, int type)
{
	if (!isActive_7ad420())
		return;
	switch (type)
	{
		case 0:
		{
			int x = key - 0x61;
			if (x < 0 || x >= 0x18)
				return;
			int res = unknown87a040(x,true,false);
			if (res == 1)
			{
				opR5b_playSound_4541b0(0x27,0,0);
				upgrades[x]->current->refresh();
				break;
			}
			else
				return;
		}
		case 1:
		{
			int x = key - 0x41;
			if (x < 0 || x >= 0x18)
				return;
			int res = unknown87a040(x,false,false);
			if (res == 1)
			{
				opR5b_playSound_4541b0(0x28,0,0);
				upgrades[x]->current->refresh();
				break;
			}
			else
				return;
		}
		case 2:
			if (key == 0x31)
				unknown87a260(true);
			return;
	}
	for (unsigned int i = 0; i < upgrades.size(); i++)
	{
		upgrades[i]->refresh();
		upgrades[i]->previous->refresh();
		upgrades[i]->next->refresh();
	}
}

void CRpglikeUpgrades::render()
{
	if (isHidden())
		return;
	engine->render();
	setFore(*opR5b_color_d2981c);
	setForeRow(opR5b_d1e854,opR5b_d1e858,0xf,*opR5b_color_cfe674);
	print(opR5b_d1e854,opR5b_d1e858,intToString(unknown9c));
	if (unknown94 != -1 && unknown94 != unknown98)
	{
		if (unknown98 != -1)
		{
			setFore_417f80(1,opR5b_cf0c64 + unknown98,*opR5b_color_cfe674);
			setFore_417f80(0x38,opR5b_cf0c64 + unknown98,*opR5b_color_cfe674);
		}
		putChar_418110(1,opR5b_cf0c64 + unknown94,0x5b,*opR5b_color_d2981c);
		putChar_418110(0x38,opR5b_cf0c64 + unknown94,0x5d,*opR5b_color_d2981c);
		unknown98 = unknown94;
	}
	XConsole::render();
}

//==================================================================
// CPlayer2Button / CPolymindButton / CPlayer2 / CPolymind
//==================================================================

class MapView : public XConsole
{
public:
	void unknown49ad70(int a);	// NOTE: placeholder name
};
extern MapView *opR5b_mapView;	// NOTE: placeholder name (0xcec054)

class CPlayer2 : public Console
{
public:
	void toggleInfo();	// NOTE: placeholder name
	bool unknown87a990();	// NOTE: placeholder name

	char pad6c[0x74 - 0x6c];
	string unknown74;	// NOTE: placeholder name
	string unknown90;	// NOTE: placeholder name
};
extern CPlayer2 *opR5b_cec068;	// NOTE: placeholder name

class CPolymind : public Console
{
public:
	void toggleInfo();	// NOTE: placeholder name
	bool unknown87afd0();	// NOTE: placeholder name

	char pad6c[0x78 - 0x6c];
	string unknown78;	// NOTE: placeholder name
	string unknown94;	// NOTE: placeholder name
};
extern CPolymind *opR5b_cec06c;	// NOTE: placeholder name

class CPlayer2Button : public Console
{
public:
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
};

bool CPlayer2Button::input(void *event)
{
	if (isHidden() || opR5b_inputBlocked)
		return false;
	if (input429d00(event))
		return true;
	if (opR5b_world->unknown71bbd0())
		return false;
	switch (*(int*)event)
	{
		case 5:
			opR5b_mapView->unknown49ad70(tickCount + 500);
		case 0x98:
			opR5b_cec068->toggleInfo();
			return true;
		default:
			return false;
	}
}

class CPolymindButton : public Console
{
public:
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
};

bool CPolymindButton::input(void *event)
{
	if (isHidden() || opR5b_inputBlocked)
		return false;
	if (input429d00(event))
		return true;
	if (opR5b_world->unknown71bbd0())
		return false;
	switch (*(int*)event)
	{
		case 5:
			opR5b_mapView->unknown49ad70(tickCount + 500);
		case 0x98:
			opR5b_cec06c->toggleInfo();
			return true;
		default:
			return false;
	}
}

extern int opR5b_cf46ac;	// NOTE: placeholder name
extern int opR5b_cf46a8;	// NOTE: placeholder name
extern string opR5b_strings_cfc230[];	// NOTE: placeholder name
extern string opR5b_strings_d31348[];	// NOTE: placeholder name
extern string opR5b_strings_d2e148[];	// NOTE: placeholder name
extern bool opR5b_d28d16;	// NOTE: placeholder name

bool CPlayer2::unknown87a990()
{
	bool changed = false;
	string str = " ";
	if (opR5b_cf46ac != 0x14)
		str += opR5b_strings_cfc230[opR5b_cf46ac] + "-";
	str += opR5b_strings_d31348[opR5b_cf46a8];
	str += " ";
	if (str != unknown74)
	{
		changed = true;
		unknown74 = str;
	}
	HEntity player = opR5b_world->getEntity671();
	if (player.isValid())
	{
		int kind = player->unknown5d1390();
		int mode = player->unknown44a7d0();
		str = (((kind == 1 && player->unknown45a700() && (mode == 1 || mode == 7)) ? string(mode == 1 ? "Running" : "Weaving") : opR5b_strings_d2e148[kind]) + " (") + (opR5b_d28d16 ? intToString(player->unknown5d15a0(false)) + ")" : intToString(player->unknown5d1d70()) + "%)");
		if (str != unknown90)
		{
			changed = true;
			unknown90 = str;
		}
	}
	return changed;
}
