// op_q4e: CMission / CMainUiButton / CFovEnemies / CEvolve* console members at 0x987000-0x993100 of
//	COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
#include "engine/xcolor.h"
#include <stdlib.h>
#include "util/rng.h"
using namespace std;
extern RNG rng;	// 0xd30908

//==================================================================
// shared declarations (copied from consoles/xconsole.h + console.h, extended for this file)
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos();
	Pos(int x_, int y_);
	Pos(const Pos &pos) throw();
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(const Pos &pos, int width_, int height_);
	Rect(const Rect &rect);
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Pos mouse;
};

struct Glyph	// NOTE: placeholder name
{
	int font;
	int ch;
	int unknown8;
	XColor fg;
	XColor bg;

	Glyph(int font_);
	Glyph &operator=(const Glyph &glyph);
	XColor *getBg();	// NOTE: placeholder name
};

class XBuffer	// NOTE: placeholder name
{
public:
	XBuffer(int width, int height, Glyph fill);
	int getWidth();
	int getHeight();
	Glyph *get(int x, int y);
	void copy(XBuffer *buffer);	// NOTE: placeholder name

	int data[3];
};

class XConsole
{
public:
	XConsole(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~XConsole();

	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(XEvent *event) = 0;
	virtual void inputMouse(int x, int y);	// NOTE: placeholder name
	virtual void update() = 0;
	virtual void render() = 0;	// NOTE: placeholder name

	bool isHidden();	// NOTE: placeholder name
	int getWidth();
	int getHeight();
	Pos getPos();
	void setPos(int x, int y);	// NOTE: placeholder name
	void setHidden(bool hidden_) throw();	// NOTE: placeholder name
	void setFgColor(XColor color);	// NOTE: placeholder name (0x4183d0)
	void setBgColor(XColor color);	// NOTE: placeholder name (0x418410)
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name (0x417f80)
	void putChar(int x, int y, int ch, XColor color);	// NOTE: placeholder name (0x418110)
	void setCharRow(int x, int y, int width, int ch, XColor color);	// NOTE: placeholder name (0x429840)
	void setFore(XColor color);	// NOTE: placeholder name (0x417b00)
	void removeSubconsole(XConsole *console);
	XConsole *getParent();
	bool isVisible();	// NOTE: placeholder name
	int getLayer_44a7d0();	// NOTE: placeholder name
	vector<XConsole*> *getSubconsoles();	// NOTE: placeholder name
	void moveSubconsole(XConsole *console, int layer);	// NOTE: placeholder name (0x417f10)
	void print(int x, int y, const string &text);	// NOTE: placeholder name
	void clear(int x, int y, int width, int height);	// NOTE: placeholder name
	void clearBack();	// NOTE: placeholder name (0x417cf0)
	void updateBase();	// NOTE: placeholder name (0x429e30)
	void renderBase();	// NOTE: placeholder name (0x429ea0)
	bool unknown429d00(XEvent *event);	// NOTE: placeholder name

	XConsole *parent;
	XBuffer buffer;
	int font;
	int fontData;	// NOTE: placeholder name
	Pos pos;
	Pos offset;	// NOTE: placeholder name
	XColor fgColor;
	XColor bgColor;
	int unknown34;
	int unknown38;
	float unknown3c;
	float unknown40;
	vector<XConsole*> subconsoles;
	bool hidden;
	int unknown58;
	bool unknown5c;
	bool unknown5d;
};

class OpQ4e_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class Engine
{
public:
	OpQ4e_EngineItem *unknown50fb50(Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
	bool unknown454d30();	// NOTE: placeholder name
	void unknown50ff30();	// NOTE: placeholder name
	void update();	// NOTE: placeholder name (0x50fff0)
	void render();	// NOTE: placeholder name (0x5100b0)

	XConsole *console;
	int data[20];
};

class ConsoleTitle;

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual ~Console();

	virtual void resize(int width, int height);
	virtual bool input(XEvent *event);
	virtual void update();
	virtual void render();
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	void animate(string name) { animate(name,0x30,0); };	// NOTE: placeholder name
	void animate(string name, int unknown1, int unknown2);	// NOTE: placeholder name
	bool isActive_7ad420();	// NOTE: placeholder name
	int getUnknown60();	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	ConsoleTitle *title;
};

struct OpQ4e_Hostile;	// NOTE: placeholder name

class Entity
{
public:
	int *unknown45a840();	// NOTE: placeholder name
	int unknown448fe0(int slot);	// NOTE: placeholder name
};

class HEntity
{
	int ID;
public:
	Entity *operator->() const;	// 0x9b6570
};

class Map	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	HEntity getPlayer();	// 0x4630f0
	int unknown463e50();	// NOTE: placeholder name
	int unknown4642d0();	// NOTE: placeholder name
	int getTurn();	// 0x464270
	void unknown464710(int value);	// NOTE: placeholder name
	bool unknown71bbd0();	// NOTE: placeholder name
	void unknown726520();	// NOTE: placeholder name
	vector<OpQ4e_Hostile*> *unknown4636b0();	// NOTE: placeholder name
};
extern Map *world;	// NOTE: placeholder name (0xcefc4c)

//==================================================================
// CMission window modes
//==================================================================
class CLogMsgs : public Console
{
public:
	void clearLines();
	void scrollToEnd();
};
extern CLogMsgs *opq4e_cec0c4;	// NOTE: placeholder name

class CAllies : public Console
{
public:
	CAllies(XConsole *parent);
	void unknown7b7980();	// NOTE: placeholder name

	char pad6c[0xb0 - 0x6c];
};
extern CAllies *opq4e_cec0c8;	// NOTE: placeholder name

class CLog : public Console
{
public:
	CLog(XConsole *parent, int mode_);
	bool getUnknown80();	// NOTE: placeholder name

	char pad6c[0x8c - 0x6c];
};

class CMapFine : public XConsole
{
public:
	void unknown876760();	// NOTE: placeholder name
	void clearBubbles(int type);
};
extern CMapFine *opq4e_cec058;	// NOTE: placeholder name

class AudioMixer	// NOTE: placeholder name
{
public:
	void unknown41a210(int index);	// NOTE: placeholder name
};
extern AudioMixer *opq4e_audioMixer;	// NOTE: placeholder name (0xcefa90)

class OpQ4e_LogTabs : public Console	// NOTE: placeholder name (object at 0xcec0d0)
{
public:
	void unknown48e860();	// NOTE: placeholder name
};
extern OpQ4e_LogTabs *opq4e_cec0d0;	// NOTE: placeholder name
extern int opq4e_consoleMode;	// NOTE: placeholder name (0xd28d64)
void unknown4541b0(int a, int b, int c);	// NOTE: placeholder name (sound)
void unknown4b3540(XConsole *parent);	// NOTE: placeholder name


//==================================================================
// console classes created by CMission (constructors are defined elsewhere)
//==================================================================
class CScan : public Console
{
public:
	CScan(XConsole *parent);
	char pad6c[0xb8 - 0x6c];
};

class CEvasion : public Console
{
public:
	CEvasion(XConsole *parent);
	char pad6c[0xcc - 0x6c];
};

class CVolley : public Console
{
public:
	CVolley(XConsole *parent);
	char pad6c[0x9c - 0x6c];
};

class CInventory : public Console
{
public:
	CInventory(XConsole *parent);
	void unknown8a53c0();	// NOTE: placeholder name
	char pad6c[0xc8 - 0x6c];
};

class CPartswap : public Console
{
public:
	CPartswap(XConsole *parent);
	char pad6c[0xd0 - 0x6c];
};

class CPartremove : public Console
{
public:
	CPartremove(XConsole *parent);
	char pad6c[0x70 - 0x6c];
};

class CPartmanage : public Console
{
public:
	CPartmanage(XConsole *parent);
	char pad6c[0x74 - 0x6c];
};

class CMapshift : public Console
{
public:
	CMapshift(XConsole *parent);
	char pad6c[0x70 - 0x6c];
};

class CItemTag : public Console
{
public:
	CItemTag(XConsole *parent);
	char pad6c[0x88 - 0x6c];
};

class CSearch : public Console
{
public:
	CSearch(XConsole *parent);
	char pad6c[0x7c - 0x6c];
};

class CSpecialCommands : public Console
{
public:
	CSpecialCommands(XConsole *parent);
	char pad6c[0xb0 - 0x6c];
};

class CHack : public Console
{
public:
	CHack(XConsole *parent);
	char pad6c[0xa0 - 0x6c];
};

class CInfo : public Console
{
public:
	CInfo(XConsole *parent, bool flag, int layer);	// NOTE: placeholder parameter names
	void unknown8b5080();	// NOTE: placeholder name
	char pad6c[0xfc - 0x6c];
};

//==================================================================
// CMission (0xcec034)
//==================================================================
class CMission : public Console
{
public:
	virtual void update();
	virtual void render();

	bool unknown987b10(int mode);	// NOTE: placeholder name
	void unknown987ea0();	// NOTE: placeholder name
	void unknown987fd0();	// NOTE: placeholder name
	void unknown988270();	// NOTE: placeholder name
	void unknown988a30();	// NOTE: placeholder name
	void unknown988ad0(bool flag);	// NOTE: placeholder name
	void unknown988d30();	// NOTE: placeholder name
	void unknown987de0();	// NOTE: placeholder name
	void unknown987e30();	// NOTE: placeholder name
	void muteAudio();
	void unmuteAudio(bool keepSounds);

	char pad6c[0x74 - 0x6c];
	unsigned int unknown74;	// NOTE: placeholder name
	char pad78[0xb0 - 0x78];
	int unknownb0;	// NOTE: placeholder name
	char padb4[0xf8 - 0xb4];
};
extern CMission *opq4e_cec034;	// NOTE: placeholder name

extern bool opq4e_d28e4e;	// NOTE: placeholder name
extern int opq4e_cebd5c;	// NOTE: placeholder name

class CIntel : public Console	// (object at 0xcec0cc)
{
public:
	CIntel(XConsole *parent);
	void unknown7ba190();	// NOTE: placeholder name

	char pad6c[0xfc - 0x6c];
};
extern CIntel *opq4e_cec0cc;	// NOTE: placeholder name

void CMission::unknown987de0()
{
	if (opq4e_d28e4e && opq4e_cebd5c != 2)
		unknown987b10(1);
	else if (opq4e_cec0cc->isHidden())
		opq4e_cec0cc->unknown7ba190();
}

extern CLog *opq4e_cec0b0;	// NOTE: placeholder name
extern CLog *opq4e_cec0b8;	// NOTE: placeholder name
extern CLog *opq4e_cec0c0;	// NOTE: placeholder name

void CMission::unknown987e30()
{
	if (opq4e_cec0b0 != NULL)
	{
		removeSubconsole(opq4e_cec0b0);
		opq4e_cec0b0 = NULL;
	}
	if (opq4e_cec0b8 != NULL)
	{
		removeSubconsole(opq4e_cec0b8);
		opq4e_cec0b8 = NULL;
	}
	if (opq4e_cec0c0 != NULL)
	{
		removeSubconsole(opq4e_cec0c0);
		opq4e_cec0c0 = NULL;
	}
}

//==================================================================
// CMainUiButtonHolder / CFovEnemies
//==================================================================
class CMainUiButton : public Console
{
public:
	CMainUiButton(XConsole *parent, int x, int index_);
	virtual bool input(XEvent *event);

	int index;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	char unknown74[4];	// NOTE: placeholder name
};

class CMainUiButtonHolder : public Console
{
public:
	CMainUiButtonHolder(XConsole *parent, int index, int layer);
	virtual void update();

	void unknown98a3a0();	// NOTE: placeholder name

	CMainUiButton *button;	// NOTE: placeholder name
};

void CMainUiButtonHolder::update()
{
	if (isHidden())
		return;
	unknown98a3a0();
	XConsole::update();
}

class CFovEnemiesButton : public Console
{
public:
	CFovEnemiesButton(XConsole *parent, int x, const string &text);
};

class CFovEnemies : public Console
{
public:
	CFovEnemies(XConsole *parent);
	virtual ~CFovEnemies();	// defined in cc_r2_17
	virtual void update();

	void unknown98ac30();	// NOTE: placeholder name

	int count;	// NOTE: placeholder name
	CFovEnemiesButton *button;	// NOTE: placeholder name
};

void CFovEnemies::update()
{
	if (isHidden())
		return;
	unknown98ac30();
	XConsole::update();
}

//==================================================================
// CEvolve
//==================================================================
class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text, int font, int maxWidth, int layer);
	char pad6c[0x88 - 0x6c];
};

class CEvolveSlot : public Console
{
public:
	CEvolveSlot(XConsole *parent, int x, int y, int slot);
	char pad6c[0x70 - 0x6c];
};

class CEvolveConfirmButton : public Console
{
public:
	CEvolveConfirmButton(XConsole *parent, int x, int y, int width);
	virtual bool input(XEvent *event);
};

class CEvolveApply : public Console
{
public:
	CEvolveApply(XConsole *parent, int x, int y, int count_);
	virtual void update();

	int count;	// NOTE: placeholder name
};

class CEvolveMain : public Console
{
public:
	CEvolveMain(XConsole *parent, const Rect &rect, int circuits);	// NOTE: placeholder parameter names
	virtual ~CEvolveMain();	// defined in op_w7
	virtual void update();
	virtual void render();

	void unknown98bda0(int slot, bool increase);	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	int unknown74[4];	// NOTE: placeholder name
	vector<Console*> unknown84;	// NOTE: placeholder name
	CEvolveConfirmButton *unknown94;	// NOTE: placeholder name
	CText *unknown98;	// NOTE: placeholder name
	CText *unknown9c;	// NOTE: placeholder name
	int unknowna0;	// NOTE: placeholder name
	int unknowna4;	// NOTE: placeholder name
};

class CEvolve : public Console
{
public:
	int *unknown4b5730();	// NOTE: placeholder name
	void unknown992dc0();	// NOTE: placeholder name

	char pad6c[0x78 - 0x6c];
	bool unknown78;	// NOTE: placeholder name
	char pad79[0x7c - 0x79];
	CEvolveMain *unknown7c;	// NOTE: placeholder name
	char pad80[0xb0 - 0x80];
	Console *unknownb0;	// NOTE: placeholder name
};
extern CEvolve *opq4e_cec140;	// NOTE: placeholder name
extern string opq4e_d29018[];	// NOTE: placeholder name
string &opq4e_padLeft(string &s, int width, char c);	// NOTE: placeholder name (0x408090)
string intToString(int value);
extern XColor *opq4e_cf6b24;	// NOTE: placeholder name
extern XColor *opq4e_cf13fc;	// NOTE: placeholder name
extern XColor *opq4e_cfe674;	// NOTE: placeholder name
extern XColor *opq4e_d20438;	// NOTE: placeholder name
extern bool opq4e_cefa5f;	// NOTE: placeholder name (console input blocked)

extern XColor *opq4e_d2981c;	// NOTE: placeholder name
extern XColor *opq4e_d29758;	// NOTE: placeholder name

class CEvolveSlotButton : public Console
{
public:
	virtual bool mouseEnter();
	virtual void update();
	virtual bool input(XEvent *event);

	bool unknown98b210();	// NOTE: placeholder name

	int slot;	// NOTE: placeholder name
	bool increase;	// NOTE: placeholder name
};

bool CEvolveSlotButton::unknown98b210()
{
	return increase ? opq4e_cec140->unknown7c->unknown70 : world->getPlayer()->unknown45a840()[slot] + opq4e_cec140->unknown7c->unknown74[slot] > opq4e_cec140->unknown4b5730()[slot];
}

void CEvolveSlotButton::update()
{
	engine->update();
	setFgColor(unknown98b210() ? *opq4e_d2981c : *opq4e_d29758);
}

bool CEvolveSlotButton::mouseEnter()
{
	if (!unknown98b210())
		return false;
	animate("A_ButtonHover_Begin_EVOL_HOV_OK");
	return true;
}

bool CEvolveSlotButton::input(XEvent *event)
{
	switch (event->type)
	{
	case 0x190:
		if (unknown98b210())
			opq4e_cec140->unknown7c->unknown98bda0(slot,increase);
		return true;
	}
	return false;
}

//==================================================================
// CMission::update
//==================================================================
struct OpQ4e_Record	// NOTE: placeholder name
{
	int pad;
};

struct OpQ4e_ConsoleShake	// NOTE: placeholder name (global at 0xd2f1c8)
{
	void update();
};
extern OpQ4e_ConsoleShake opq4e_consoleShake;	// NOTE: placeholder name

class OpQ4e_MapView : public XConsole	// NOTE: placeholder name (object at 0xcec054)
{
};
extern OpQ4e_MapView *opq4e_cec054;	// NOTE: placeholder name

extern int opq4e_cefc8c;	// NOTE: placeholder name (pending audio mute state)
extern bool opq4e_d28cbc;	// NOTE: placeholder name
extern bool opq4e_d28c8b;	// NOTE: placeholder name
extern int opq4e_cefc1c;	// NOTE: placeholder name
extern bool opq4e_cefbc5;	// NOTE: placeholder name
extern vector<int> opq4e_cf686c;	// NOTE: placeholder name
extern vector<OpQ4e_Record*> opq4e_d2c408;	// NOTE: placeholder name
extern vector<OpQ4e_Record*> opq4e_cf35b0;	// NOTE: placeholder name
extern vector<OpQ4e_Record*> opq4e_cfb844;	// NOTE: placeholder name
extern vector<OpQ4e_Record*> opq4e_d2d1c4;	// NOTE: placeholder name
extern vector<OpQ4e_Record*> opq4e_d25de0;	// NOTE: placeholder name
extern vector<OpQ4e_Record*> opq4e_d15d9c;	// NOTE: placeholder name
extern vector<OpQ4e_Record*> opq4e_d21afc;	// NOTE: placeholder name
extern vector<OpQ4e_Record*> opq4e_cf1a04;	// NOTE: placeholder name
extern vector<OpQ4e_Record*> opq4e_d161c4;	// NOTE: placeholder name
extern vector<OpQ4e_Record*> opq4e_cf67c0;	// NOTE: placeholder name
extern vector<OpQ4e_Record*> opq4e_cfe704;	// NOTE: placeholder name

OpQ4e_Record *opq4e_randomElement_9d5d00(vector<OpQ4e_Record*> &v);	// NOTE: placeholder name
void opq4e_addUnique_9db000(vector<OpQ4e_Record*> &v, OpQ4e_Record *record);	// NOTE: placeholder name

void CMission::update()
{
	if (isHidden())
		return;
	opq4e_consoleShake.update();
	engine->update();
	if (opq4e_cefc8c != 0 && !opq4e_d28cbc && !opq4e_d28c8b && world != NULL && world->unknown463e50() && opq4e_cec054 != NULL)
	{
		switch (opq4e_cefc8c)
		{
		case 1:
		case 2:
			opq4e_cec034->unmuteAudio(opq4e_cefc8c == 2);
			opq4e_cefc8c = 0;
			break;
		case 3:
			opq4e_cec034->muteAudio();
			opq4e_cefc8c = 0;
			break;
		}
	}
	if (opq4e_cefc1c != -1 && world != NULL && world->unknown463e50() && world->unknown4642d0() > 50 && world->getTurn() > opq4e_cefc1c)
	{
		opq4e_cefc1c = world->getTurn();
		if (rng.chance(1))
		{
			bool changed = false;
			if (opq4e_cefbc5)
				changed = true;
			else if (opq4e_d2c408.size() != opq4e_cf686c[0])
				changed = true;
			else if (opq4e_cf35b0.size() != opq4e_cf686c[1])
				changed = true;
			else if (opq4e_cfb844.size() != opq4e_cf686c[2])
				changed = true;
			else if (opq4e_d2d1c4.size() != opq4e_cf686c[3])
				changed = true;
			else if (opq4e_d25de0.size() != opq4e_cf686c[4])
				changed = true;
			else if (opq4e_d15d9c.size() != opq4e_cf686c[5])
				changed = true;
			else if (opq4e_d21afc.size() != opq4e_cf686c[6])
				changed = true;
			else if (opq4e_cf1a04.size() != opq4e_cf686c[7])
				changed = true;
			else if (opq4e_d161c4.size() != opq4e_cf686c[8])
				changed = true;
			else if (opq4e_cf67c0.size() != opq4e_cf686c[9])
				changed = true;
			else if (opq4e_cfe704.size() != opq4e_cf686c[10])
				changed = true;
			if (changed)
			{
				vector<OpQ4e_Record*> picked;
				switch (rng.rangeInt(0.0f,10.0f))
				{
				case 0:
				{
					int count = rng.rangeInt(5.0f,10.0f);
					for (; count > 0; count--)
						opq4e_addUnique_9db000(picked,opq4e_randomElement_9d5d00(opq4e_d2c408));
					break;
				}
				case 1:
				{
					int count = rng.rangeInt(5.0f,10.0f);
					for (; count > 0; count--)
						opq4e_addUnique_9db000(picked,opq4e_randomElement_9d5d00(opq4e_cf35b0));
					break;
				}
				case 2:
				{
					int count = rng.rangeInt(5.0f,10.0f);
					for (; count > 0; count--)
						opq4e_addUnique_9db000(picked,opq4e_randomElement_9d5d00(opq4e_cfb844));
					break;
				}
				case 3:
				{
					int count = rng.rangeInt(5.0f,10.0f);
					for (; count > 0; count--)
						opq4e_addUnique_9db000(picked,opq4e_randomElement_9d5d00(opq4e_d2d1c4));
					break;
				}
				case 4:
				{
					int count = rng.rangeInt(5.0f,10.0f);
					for (; count > 0; count--)
						opq4e_addUnique_9db000(picked,opq4e_randomElement_9d5d00(opq4e_d25de0));
					break;
				}
				case 5:
				{
					int count = rng.rangeInt(5.0f,10.0f);
					for (; count > 0; count--)
						opq4e_addUnique_9db000(picked,opq4e_randomElement_9d5d00(opq4e_d15d9c));
					break;
				}
				case 6:
				{
					int count = rng.rangeInt(5.0f,10.0f);
					for (; count > 0; count--)
						opq4e_addUnique_9db000(picked,opq4e_randomElement_9d5d00(opq4e_d21afc));
					break;
				}
				case 7:
				{
					int count = rng.rangeInt(5.0f,10.0f);
					for (; count > 0; count--)
						opq4e_addUnique_9db000(picked,opq4e_randomElement_9d5d00(opq4e_cf1a04));
					break;
				}
				case 8:
				{
					int count = rng.rangeInt(5.0f,10.0f);
					for (; count > 0; count--)
						opq4e_addUnique_9db000(picked,opq4e_randomElement_9d5d00(opq4e_d161c4));
					break;
				}
				case 9:
				{
					int count = rng.rangeInt(10.0f,20.0f);
					for (; count > 0; count--)
						opq4e_addUnique_9db000(picked,opq4e_randomElement_9d5d00(opq4e_cf67c0));
					break;
				}
				case 10:
				{
					int count = rng.rangeInt(10.0f,20.0f);
					for (; count > 0; count--)
						opq4e_addUnique_9db000(picked,opq4e_randomElement_9d5d00(opq4e_cfe704));
					break;
				}
				}
				for (unsigned int i = 0; i < picked.size(); i++)
					delete picked[i];
			}
			opq4e_cefc1c = -1;
		}
	}
	updateBase();
}


bool CMission::unknown987b10(int mode)
{
	opq4e_cec0c4->clearLines();
	switch (opq4e_consoleMode)
	{
	case 0:
		if (!opq4e_cec0c8->isActive_7ad420())
			return false;
		opq4e_cec0c8->setHidden(true);
		break;
	case 1:
		if (!opq4e_cec0cc->isActive_7ad420())
			return false;
		opq4e_cec0cc->setHidden(true);
		break;
	case 2:
		if (!opq4e_cec0b8->isActive_7ad420())
			return false;
		if (opq4e_cebd5c == 2)
			opq4e_cec058->unknown876760();
		opq4e_cec0b8->setHidden(true);
		opq4e_audioMixer->unknown41a210(0xe);
		break;
	case 3:
		if (!opq4e_cec0c0->isActive_7ad420())
			return false;
		if (opq4e_cebd5c == 2)
			opq4e_cec058->clearBubbles(2);
		opq4e_cec0c0->setHidden(true);
		opq4e_audioMixer->unknown41a210(0xe);
		opq4e_cec0c4->scrollToEnd();
		break;
	}
	if (mode != opq4e_consoleMode)
		unknownb0 = opq4e_consoleMode;
	opq4e_consoleMode = mode;
	switch (opq4e_consoleMode)
	{
	case 0:
		if (opq4e_cec0c8->getUnknown60() == 0)
			opq4e_cec0c8->open();
		else
		{
			opq4e_cec0c8->setHidden(false);
			opq4e_cec0c8->unknown7b7980();
			unknown4541b0(0x2e,0,0);
		}
		break;
	case 1:
		if (opq4e_cec0cc->getUnknown60() == 0)
			opq4e_cec0cc->open();
		else
		{
			opq4e_cec0cc->setHidden(false);
			unknown4541b0(0x2e,0,0);
		}
		break;
	case 2:
		if (opq4e_cec0b8->getUnknown60() == 0)
			opq4e_cec0b8->open();
		else
		{
			opq4e_cec0b8->setHidden(false);
			unknown4541b0(0x2e,0,0);
			opq4e_cec0b8->engine->unknown50ff30();
		}
		break;
	case 3:
		if (opq4e_cec0c0->getUnknown60() == 0)
			opq4e_cec0c0->open();
		else
		{
			opq4e_cec0c0->setHidden(false);
			unknown4541b0(0x2e,0,0);
			opq4e_cec0c0->engine->unknown50ff30();
		}
		break;
	}
	opq4e_cec0d0->unknown48e860();
	return true;
}

void CMission::unknown987ea0()
{
	opq4e_cec0b0 = new CLog(this,0);
	opq4e_cec0b8 = new CLog(this,1);
	opq4e_cec0c0 = new CLog(this,2);
}

extern XConsole *opq4e_cec078;	// NOTE: placeholder name
extern XConsole *opq4e_cec07c;	// NOTE: placeholder name
extern XConsole *opq4e_cec080;	// NOTE: placeholder name
extern XConsole *opq4e_cec084;	// NOTE: placeholder name
extern XConsole *opq4e_cec088;	// NOTE: placeholder name
extern CInventory *opq4e_cec08c;	// NOTE: placeholder name
extern XConsole *opq4e_cec090;	// NOTE: placeholder name
extern XConsole *opq4e_cec094;	// NOTE: placeholder name
extern XConsole *opq4e_cec098;	// NOTE: placeholder name
extern XConsole *opq4e_cec09c;	// NOTE: placeholder name
extern XConsole *opq4e_cec0a0;	// NOTE: placeholder name
extern XConsole *opq4e_cec0a4;	// NOTE: placeholder name
extern XConsole *opq4e_cec0ac;	// NOTE: placeholder name
extern XConsole *opq4e_cec0f8;	// NOTE: placeholder name
extern CInfo *opq4e_cec118;	// NOTE: placeholder name
extern CInfo *opq4e_cec11c;	// NOTE: placeholder name
extern CInfo *opq4e_cec120;	// NOTE: placeholder name

void CMission::unknown987fd0()
{
	if (opq4e_cec078 != NULL)
	{
		removeSubconsole(opq4e_cec078);
		opq4e_cec078 = NULL;
	}
	if (opq4e_cec07c != NULL)
	{
		removeSubconsole(opq4e_cec07c);
		opq4e_cec07c = NULL;
	}
	if (opq4e_cec080 != NULL && opq4e_cec080 != NULL)
	{
		removeSubconsole(opq4e_cec080);
		opq4e_cec080 = NULL;
	}
	if (opq4e_cec084 != NULL)
	{
		removeSubconsole(opq4e_cec084);
		opq4e_cec084 = NULL;
	}
	if (opq4e_cec088 != NULL)
	{
		removeSubconsole(opq4e_cec088);
		opq4e_cec088 = NULL;
	}
	if (opq4e_cec08c != NULL)
	{
		removeSubconsole(opq4e_cec08c);
		opq4e_cec08c = NULL;
	}
	if (opq4e_cec090 != NULL)
	{
		removeSubconsole(opq4e_cec090);
		opq4e_cec090 = NULL;
	}
	if (opq4e_cec094 != NULL)
	{
		removeSubconsole(opq4e_cec094);
		opq4e_cec094 = NULL;
	}
	if (opq4e_cec098 != NULL)
	{
		removeSubconsole(opq4e_cec098);
		opq4e_cec098 = NULL;
	}
	if (opq4e_cec09c != NULL)
	{
		removeSubconsole(opq4e_cec09c);
		opq4e_cec09c = NULL;
	}
	if (opq4e_cec0a0 != NULL)
	{
		removeSubconsole(opq4e_cec0a0);
		opq4e_cec0a0 = NULL;
	}
	if (opq4e_cec0a4 != NULL)
	{
		removeSubconsole(opq4e_cec0a4);
		opq4e_cec0a4 = NULL;
	}
	if (opq4e_cec0ac != NULL)
	{
		removeSubconsole(opq4e_cec0ac);
		opq4e_cec0ac = NULL;
	}
	if (opq4e_cec0c8 != NULL)
	{
		removeSubconsole(opq4e_cec0c8);
		opq4e_cec0c8 = NULL;
	}
	if (opq4e_cec0cc != NULL)
	{
		removeSubconsole(opq4e_cec0cc);
		opq4e_cec0cc = NULL;
	}
	if (opq4e_cec0f8 != NULL)
	{
		removeSubconsole(opq4e_cec0f8);
		opq4e_cec0f8 = NULL;
	}
	if (opq4e_cec118 != NULL)
	{
		removeSubconsole(opq4e_cec118);
		opq4e_cec118 = NULL;
	}
	if (opq4e_cec11c != NULL)
	{
		removeSubconsole(opq4e_cec11c);
		opq4e_cec11c = NULL;
	}
	if (opq4e_cec120 != NULL)
	{
		removeSubconsole(opq4e_cec120);
		opq4e_cec120 = NULL;
	}
}

extern XConsole *opq4e_cec0d4;	// NOTE: placeholder name
extern XConsole *opq4e_cec0d8;	// NOTE: placeholder name
extern XConsole *opq4e_cec0dc;	// NOTE: placeholder name
extern XConsole *opq4e_cec0e0;	// NOTE: placeholder name
extern XConsole *opq4e_cec0e4;	// NOTE: placeholder name
extern XConsole *opq4e_cec0e8;	// NOTE: placeholder name
extern XConsole *opq4e_cec0ec;	// NOTE: placeholder name
extern XConsole *opq4e_cec0f0;	// NOTE: placeholder name

void CMission::unknown988270()
{
	opq4e_cec078 = new CScan(this);
	opq4e_cec07c = new CEvasion(this);
	opq4e_cec080 = NULL;
	opq4e_cec084 = new CVolley(this);
	unknown4b3540(this);
	opq4e_cec08c = new CInventory(this);
	opq4e_cec090 = new CPartswap(this);
	opq4e_cec094 = new CPartremove(this);
	opq4e_cec098 = new CPartmanage(this);
	opq4e_cec09c = new CMapshift(this);
	opq4e_cec0a0 = new CItemTag(this);
	opq4e_cec0a4 = new CSearch(this);
	opq4e_cec0ac = new CSpecialCommands(this);
	opq4e_cec0c8 = new CAllies(this);
	opq4e_cec0cc = new CIntel(this);
	opq4e_cec0f8 = new CHack(this);
	opq4e_cec118 = new CInfo(this,true,15);
	opq4e_cec11c = new CInfo(this,false,15);
	opq4e_cec120 = new CInfo(this,false,20);
	moveSubconsole(opq4e_cec0d0,getSubconsoles()->size() - 1);
	moveSubconsole(opq4e_cec0d4,getSubconsoles()->size() - 1);
	moveSubconsole(opq4e_cec0d8,getSubconsoles()->size() - 1);
	moveSubconsole(opq4e_cec0dc,getSubconsoles()->size() - 1);
	if (opq4e_cec0e0 != NULL)
		moveSubconsole(opq4e_cec0e0,getSubconsoles()->size() - 1);
	moveSubconsole(opq4e_cec0e4,getSubconsoles()->size() - 1);
	moveSubconsole(opq4e_cec0e8,getSubconsoles()->size() - 1);
	moveSubconsole(opq4e_cec0ec,getSubconsoles()->size() - 1);
	moveSubconsole(opq4e_cec0f0,getSubconsoles()->size() - 1);
}

//==================================================================
// CMission game-over / restart helpers
//==================================================================
class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp() throw();
};

class OpQ4e_Message	// NOTE: placeholder name (ctor 0x510d20)
{
public:
	OpQ4e_Message(int type, int a, int b, int c, HProp d, HProp e);
	char pad[0x20];
};

class OpQ4e_MessageLog : public Console	// NOTE: placeholder name (object at 0xcec0f4)
{
public:
	void hide();	// NOTE: placeholder name
	void add(OpQ4e_Message *message);	// NOTE: placeholder name
};
extern OpQ4e_MessageLog *opq4e_cec0f4;	// NOTE: placeholder name

class OpQ4e_Commands : public Console	// NOTE: placeholder name (object at 0xcec03c)
{
public:
	void unknown7d0a80();	// NOTE: placeholder name
};
extern OpQ4e_Commands *opq4e_cec03c;	// NOTE: placeholder name

class OpQ4e_Quit46dd50	// NOTE: placeholder name (object at 0xcf45d8)
{
public:
	bool unknown46dd50();	// NOTE: placeholder name
};
extern OpQ4e_Quit46dd50 opq4e_cf45d8;	// NOTE: placeholder name

class OpQ4e_GM	// NOTE: placeholder name (object at 0xcefaa8)
{
public:
	void serialize(bool a, bool b, bool c, bool d, bool e);	// NOTE: placeholder name (0x78c260)
	void unknown792dc0();	// NOTE: placeholder name
	void endGame();
	bool readyGame(bool a, bool b, bool c);	// NOTE: placeholder name
	void unknown78c050();	// NOTE: placeholder name
};
extern OpQ4e_GM *opq4e_gm;	// NOTE: placeholder name

struct OpQ4e_Node	// NOTE: placeholder name
{
	char pad[8];
	int depth;
};

class OpQ4e_HNode	// NOTE: placeholder name
{
	int ID;
public:
	OpQ4e_Node *operator->() const;	// 0x9b7910
};
extern OpQ4e_HNode opq4e_d1e888;	// NOTE: placeholder name

extern bool opq4e_cefacd;	// NOTE: placeholder name
extern int opq4e_d25740;	// NOTE: placeholder name
extern int opq4e_d25744;	// NOTE: placeholder name
extern int opq4e_d25748;	// NOTE: placeholder name
extern int opq4e_cf4718;	// NOTE: placeholder name
extern bool opq4e_cefaee;	// NOTE: placeholder name
extern int opq4e_cefaf8;	// NOTE: placeholder name
extern bool opq4e_cefafd;	// NOTE: placeholder name
extern bool opq4e_cefaff;	// NOTE: placeholder name
extern int opq4e_cec144;	// NOTE: placeholder name
extern int opq4e_cf4b38;	// NOTE: placeholder name
extern unsigned int opq4e_tickCount;	// NOTE: placeholder name (0xcaed20)

void CMission::unknown988a30()
{
	opq4e_gm->unknown792dc0();
	world->unknown464710(5);
	if (opq4e_d1e888->depth > 9 && !opq4e_cefacd && !opq4e_cf45d8.unknown46dd50())
	{
		opq4e_d25740--;
		switch (opq4e_cf4718)
		{
		case 1:
			opq4e_d25744--;
			break;
		case 2:
			opq4e_d25748--;
			break;
		}
	}
	exit(0);
}

void CMission::unknown988ad0(bool flag)
{
	if (!opq4e_cec0f4->isHidden())
		opq4e_cec0f4->hide();
	if (!opq4e_cec118->isHidden())
		opq4e_cec118->unknown8b5080();
	if (!opq4e_cec11c->isHidden())
		opq4e_cec11c->unknown8b5080();
	if (!opq4e_cec120->isHidden())
		opq4e_cec120->unknown8b5080();
	if (!opq4e_cec03c->isHidden())
		opq4e_cec03c->unknown7d0a80();
	if (!opq4e_cefaee && opq4e_cefaf8 == 0 && !opq4e_cefafd && !opq4e_cefaff && opq4e_cec144 == 0 && world != NULL && world->getPlayer().operator->() && opq4e_cf4b38 == 0x1c)
	{
		if (flag && !opq4e_cefacd && !opq4e_cf45d8.unknown46dd50() && (unknown74 == 0 || opq4e_tickCount > unknown74 + 5000))
		{
			unknown74 = opq4e_tickCount;
			opq4e_cec0f4->add(new OpQ4e_Message(0xd8,0,0,0,HProp(),HProp()));
		}
		else
		{
			opq4e_cf4b38 = 10;
			world->unknown464710(5);
		}
	}
	else
	{
		opq4e_gm->endGame();
		if (!opq4e_gm->readyGame(true,false,false))
			exit(1);
		opq4e_gm->unknown78c050();
	}
}

void CMission::unknown988d30()
{
	if (!opq4e_cefacd && !opq4e_cf45d8.unknown46dd50())
		opq4e_gm->serialize(true,true,false,false,false);
	exit(0);
}

class OpQ4e_Rex	// NOTE: placeholder name (object at 0xd223f0)
{
public:
	int getHeight_4189a0();	// NOTE: placeholder name
	int getWidth_418980();	// NOTE: placeholder name
	XConsole *getConsole_4ab670();	// NOTE: placeholder name
};
extern OpQ4e_Rex opq4e_rex;	// NOTE: placeholder name
extern bool opq4e_d28d15;	// NOTE: placeholder name
extern int opq4e_cefab0;	// NOTE: placeholder name
extern int opq4e_cefaac;	// NOTE: placeholder name
extern int opq4e_cf27f0;	// NOTE: placeholder name

void CMission::render()
{
	if (isHidden())
		return;
	if (opq4e_d28d15)
	{
		if (opq4e_cefab0 % 2)
			opq4e_rex.getConsole_4ab670()->clear(0,opq4e_rex.getHeight_4189a0() - 1,opq4e_cefaac * 2,1);
		if (opq4e_cefaac % 2)
			opq4e_rex.getConsole_4ab670()->clear(opq4e_cefaac * 2 - 2,opq4e_cf27f0,2,opq4e_cefab0);
	}
	renderBase();
}

//==================================================================
// CEvolve
//==================================================================
class CEvolveSlotCount : public Console
{
public:
	virtual void update();

	int slot;	// NOTE: placeholder name
};

void CEvolveSlotCount::update()
{
	int max = opq4e_cec140->unknown4b5730()[slot];
	int total = world->getPlayer()->unknown448fe0(slot) + opq4e_cec140->unknown7c->unknown74[slot];
	string text = intToString(total);
	opq4e_padLeft(text,2,'0');
	putChar(1,0,text[0],text[0] == '0' ? (total == max ? *opq4e_cf6b24 : *opq4e_cf13fc) : *opq4e_cfe674);
	putChar(2,0,text[1],*opq4e_cfe674);
	setBgColor(total == max ? *opq4e_d2981c : *opq4e_d20438);
}

bool CEvolveConfirmButton::input(XEvent *event)
{
	if (isHidden() || opq4e_cefa5f)
		return false;
	if (unknown429d00(event))
		return true;
	switch (event->type)
	{
	case 0x190:
		opq4e_cec140->unknown992dc0();
		return true;
	}
	return false;
}

void CEvolve::unknown992dc0()
{
	if (!unknown78)
		unknown78 = true;
}

void CEvolveApply::update()
{
	bool hadCount;
	engine->update();
	if (((CEvolveMain *)getParent())->unknown70 != count)
	{
		hadCount = count;
		count = ((CEvolveMain *)getParent())->unknown70;
		string text = intToString(count);
		if (count <= 9)
			text += " ";
		print(7,0,text);
		if (!hadCount || count == 0)
			animate(count != 0 ? "A_CEvolveApply_Again" : "A_CEvolveApply_None");
	}
}

void CEvolveMain::unknown98bda0(int slot, bool increase)
{
	if (increase)
	{
		if (unknown70 != 0)
		{
			unknown70--;
			unknown74[slot]++;
			string name = "A_CEvolve_Circuits_Out_";
			name += opq4e_d29018[slot][0];
			opq4e_cec140->unknownb0->animate(name);
			unknown4541b0(0x27,0,0);
		}
	}
	else
	{
		if (world->getPlayer()->unknown45a840()[slot] + unknown74[slot] > opq4e_cec140->unknown4b5730()[slot])
		{
			unknown70++;
			unknown74[slot]--;
			string name = "A_CEvolve_Circuits_In_";
			name += opq4e_d29018[slot][0];
			opq4e_cec140->unknownb0->animate(name);
			unknown4541b0(0x28,0,0);
		}
	}
}

void CEvolveMain::render()
{
	if (isHidden())
		return;
	engine->render();
	if (!unknown84.empty() && unknowna0 != -1 && unknowna0 != unknowna4)
	{
		if (unknowna4 != -1)
		{
			setFore_417f80(1,unknown84[unknowna4]->getPos().y,*opq4e_cfe674);
			setFore_417f80(getWidth() - 2,unknown84[unknowna4]->getPos().y,*opq4e_cfe674);
		}
		putChar(1,unknown84[unknowna0]->getPos().y,0x5b,*opq4e_d2981c);
		putChar(getWidth() - 2,unknown84[unknowna0]->getPos().y,0x5d,*opq4e_d2981c);
		unknowna4 = unknowna0;
	}
	renderBase();
}

//==================================================================
// CMainUiButton / CMainUiButtonHolder / CFovEnemies
//==================================================================
extern string opq4e_d39618[];	// NOTE: placeholder name
extern XColor *opq4e_cf6b24;	// NOTE: placeholder name
extern XColor *opq4e_d358e4;	// NOTE: placeholder name
extern int opq4e_d31680;	// NOTE: placeholder name
extern int opq4e_d31684;	// NOTE: placeholder name
extern int opq4e_d31688;	// NOTE: placeholder name
extern int opq4e_d3168c;	// NOTE: placeholder name
extern int opq4e_d31690;	// NOTE: placeholder name
extern int opq4e_d01a14;	// NOTE: placeholder name
extern int opq4e_d01a18;	// NOTE: placeholder name
extern int opq4e_d01a20;	// NOTE: placeholder name
extern int opq4e_cf4568;	// NOTE: placeholder name
extern int opq4e_cf4570;	// NOTE: placeholder name
extern int opq4e_cefc90;	// NOTE: placeholder name
int OpY1_countDigits(unsigned int value);	// NOTE: placeholder name (0x406850)

CMainUiButtonHolder::CMainUiButtonHolder(XConsole *parent, int index, int layer)
	: Console(parent,opq4e_d39618[index].size() + 2,1,0,0,0,false,layer)
{
	putChar(0,0,0x3c,*opq4e_cf6b24);
	putChar(getWidth() - 1,0,0x3e,*opq4e_cf6b24);
	button = new CMainUiButton(this,1,index);
	unknown98a3a0();
}

void CMainUiButtonHolder::unknown98a3a0()
{
	int x;
	int y;
	switch (button->index)
	{
	case 0:
		y = opq4e_rex.getHeight_4189a0() - 1;
		x = opq4e_d31690 + 1;
		break;
	case 1:
		y = opq4e_rex.getHeight_4189a0() - 1;
		if (opq4e_cefc90 == 0)
		{
			x = opq4e_rex.getWidth_418980() - 1 - (opq4e_d39618[2].size() + 2);
			x -= opq4e_d39618[1].size() + 3;
		}
		else
			x = opq4e_cec0d4->getPos().x + opq4e_cec0d4->getWidth() + 1;
		break;
	case 2:
		y = opq4e_rex.getHeight_4189a0() - 1;
		if (opq4e_cefc90 == 0)
			x = opq4e_rex.getWidth_418980() - 1 - (opq4e_d39618[2].size() + 2);
		else
			x = opq4e_cec0d8->getPos().x + opq4e_cec0d8->getWidth() + 1;
		break;
	case 3:
		y = opq4e_cec0b0->getUnknown80() ? opq4e_cf4568 + opq4e_cf4570 - 1 : opq4e_d01a18 + opq4e_d01a20 - 1;
		x = opq4e_d01a14 + 1;
		break;
	case 4:
		x = opq4e_d31680 + 1;
		y = opq4e_d3168c + opq4e_d31684 - 1;
		break;
	case 5:
		x = opq4e_d31680 + opq4e_d31688 - 0x1b;
		y = opq4e_d3168c + opq4e_d31684 - 1;
		break;
	case 6:
		x = opq4e_d31680 + opq4e_d31688 - 0x10;
		y = opq4e_d3168c + opq4e_d31684 - 1;
		break;
	}
	setPos(x,y);
}

bool CMainUiButton::input(XEvent *event)
{
	if (world->unknown71bbd0())
		return false;
	switch (event->type)
	{
	case 0x117:
		if (index == 0)
			opq4e_cec08c->unknown8a53c0();
		return true;
	case 0x127:
		switch (index)
		{
		case 1:
			opq4e_cec034->input(&XEvent(0x97));
			break;
		case 2:
			opq4e_cec034->input(&XEvent(0x12));
			break;
		}
		clearBack();
		return true;
	case 0xd8:
		switch (index)
		{
		case 4:
			opq4e_cec054->input(&XEvent(0x31));
			break;
		case 5:
			opq4e_cec0d0->input(&XEvent(0xd0));
			break;
		case 6:
			opq4e_cec0d0->input(&XEvent(0xd1));
			break;
		}
		return true;
	}
	return false;
}

CFovEnemies::CFovEnemies(XConsole *parent)
	: Console(parent,1,1,0,opq4e_d01a18 + opq4e_d01a20 - 1,0,true,opq4e_cec0b0->getLayer_44a7d0() + 1)
{
	count = -1;
	button = NULL;
	unknown98ac30();
}

void CFovEnemies::unknown98ac30()
{
	if (world == NULL)
		return;
	world->unknown726520();
	int hostiles = world->unknown4636b0()->size();
	setHidden(!(hostiles != 0 && opq4e_cec088->isVisible() && !opq4e_cec0b0->getUnknown80()));
	if (isHidden())
		return;
	if (hostiles != count)
	{
		if (button != NULL && OpY1_countDigits(hostiles) == OpY1_countDigits(count) && hostiles != 1 && count != 1)
			button->print(1,0,intToString(hostiles));
		else
		{
			if (button != NULL && button != NULL)
			{
				removeSubconsole(button);
				button = NULL;
			}
			string text = " " + intToString(hostiles) + (hostiles > 1 ? " HOSTILES " : " HOSTILE ");
			resize(text.size() + 2,1);
			putChar(0,0,0x3c,*opq4e_d358e4);
			putChar(getWidth() - 1,0,0x3e,*opq4e_d358e4);
			button = new CFovEnemiesButton(this,1,text);
		}
		count = hostiles;
	}
	setPos(opq4e_cec0b0->getPos().x + opq4e_cec0b0->getWidth() - 1 - getWidth(),getPos().y);
}

extern XColor *opq4e_cf44c0;	// NOTE: placeholder name
extern Pos opq4e_cfbec0;	// NOTE: placeholder name
bool opq4e_findAnimation_9d45a0(const string &name, int *index);	// NOTE: placeholder name
int opq4e_center_437190(int length, int width);	// NOTE: placeholder name
void opq4e_fill_9e2be0(int *values, int count, int value);	// NOTE: placeholder name

void CEvolveMain::update()
{
	if (isHidden())
		return;
	engine->update();
	if (unknown84.empty() && !engine->unknown454d30())
	{
		unknown9c = new CText(this,Pos(21,11),"Parameters",0,0,-1);
		unknown9c->animate("A_CEvolveMain_Param");
		unknown98 = new CText(this,Pos(14,11),"Enter - [       ]",0,0,-1);
		unknown98->setFgColor(*opq4e_cf44c0);
		unknown98->setHidden(true);
		string text = "Confirm";
		unknown94 = new CEvolveConfirmButton(this,23,11,text.size());
		unknown94->setFore(*opq4e_d2981c);
		unknown94->print(0,0,text);
		for (int i = 0, y = 6; i < 4; i++, y++)
			unknown84.push_back(new CEvolveSlot(this,3,y,i));
	}
	if (unknown9c != NULL || unknown94 != NULL)
	{
		if (unknown70 != 0 && unknown94 != NULL)
		{
			unknown94->setHidden(true);
			unknown98->setHidden(true);
			unknown9c->setHidden(false);
		}
		else if (unknown70 == 0 && unknown9c != NULL)
		{
			unknown94->setHidden(false);
			unknown98->setHidden(false);
			unknown9c->setHidden(true);
		}
	}
	updateBase();
}

CEvolveMain::CEvolveMain(XConsole *parent, const Rect &rect, int circuits)
	: Console(parent,rect,0,false,10)
	, unknown6c	(circuits)
	, unknown70	(circuits)
{
	unknown94 = NULL;
	unknown98 = NULL;
	unknown9c = NULL;
	unknowna0 = -1;
	unknowna4 = -1;
	opq4e_fill_9e2be0(unknown74,4,0);
	animate("CEvolveMain_Border");
	string title = "=  EVOLUTION PARAMETERS  =";
	CText *ctext = new CText(this,Pos(opq4e_center_437190(title.size(),getWidth()),2),title,0,0,-1);
	ctext->animate("A_Credits_Contributor");
	new CEvolveApply(this,12,4,unknown70);
	putChar(21,4,0xaa,*opq4e_cfe674);
	setCharRow(22,4,3,0x81,*opq4e_cfe674);
	putChar(25,4,0x86,*opq4e_cfe674);
	putChar(26,4,0x89,*opq4e_cfe674);
	putChar(25,5,0x80,*opq4e_cfe674);
	putChar(26,5,0x80,*opq4e_cfe674);
	int anim;
	if (!opq4e_findAnimation_9d45a0("CEvolveMain_Trace_E",&anim)) {}	// NOTE: empty if reproduces the exe's stored-but-unused test
	do
	{
		engine->unknown50fb50(engine,anim,&Pos(21,4),&opq4e_cfbec0,&Pos(26,4),&opq4e_cfbec0,9)->unknown50de10();
	} while (0);
}
