// op_t6_ui: Console-derived classes in 0x7ed000-0x895000 of COGMIND.exe (Beta 17.1). Names are placeholders unless stated.
#include <string>
#include <vector>
#include <iosfwd>
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
	void setScaleX(float scale);	// NOTE: placeholder name (0x417b60)
	void setScaleY(float scale);	// NOTE: placeholder name (0x417b80)
	int getLayer_44a7d0();	// NOTE: placeholder name
	void setChar_417f50(int x, int y, int ch);	// NOTE: placeholder name
	void putChar_418110(int x, int y, int ch, XColor fore);	// NOTE: placeholder name
	void resetBack_418450() throw();	// NOTE: placeholder name
	void setForeAll_4183d0(XColor color);	// NOTE: placeholder name
	void unknown429fe0(XConsole *console, const Pos &pos, int value);	// NOTE: placeholder name
	void clearInterior();
	int countLines_418350(int x, int y, int width, int height, int align, const string &text);

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
	bool inputBase_429d00(void *event);	// NOTE: placeholder name
	Rect getRect();	// NOTE: placeholder name
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void setTitle(class ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void unknown7b0640(int a, XColor color, int b, int c);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	void *title;
};

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Pos mouse;
};

class BS	// NOTE: partial (see op_w2_m.cpp)
{
public:
	bool unknown71bbd0();	// NOTE: placeholder name
};
extern BS *opT6_world;	// 0xcefc4c NOTE: placeholder name

class OpT6_Parts	// NOTE: placeholder name (CParts, 0xcec088)
{
public:
	virtual void virtual0();	// NOTE: placeholder name
	virtual void virtual1();	// NOTE: placeholder name
	virtual void virtual2();	// NOTE: placeholder name
	virtual void virtual3();	// NOTE: placeholder name
	virtual bool input(XEvent *event);
};
extern OpT6_Parts *opT6_parts;	// 0xcec088 NOTE: placeholder name

//==================================================================
// CPartsCycle / CPartsCycleModal
//==================================================================

class CPartsCycle : public Console
{
public:
	virtual ~CPartsCycle();
	virtual bool input(void *event);

	int unknown6c;	// NOTE: placeholder name
};

bool CPartsCycle::input(void *event)
{
	if (opT6_world->unknown71bbd0())
		return false;
	switch (((XEvent *)event)->type)
	{
	case 0x117:
		switch (unknown6c)
		{
		case 1:
			opT6_parts->input(&XEvent(0x114));
			break;
		case 2:
			opT6_parts->input(&XEvent(0x115));
			break;
		case 3:
			opT6_parts->input(&XEvent(0x116));
			break;
		}
		return true;
	default:
		return false;
	}
}

class CPartsCycleModal : public Console
{
public:
	virtual ~CPartsCycleModal();
	virtual bool input(void *event);

	int unknown6c;	// NOTE: placeholder name
};

bool CPartsCycleModal::input(void *event)
{
	if (opT6_world->unknown71bbd0())
		return false;
	switch (((XEvent *)event)->type)
	{
	case 0x117:
		switch (unknown6c)
		{
			break;
		case 1:
			opT6_parts->input(&XEvent(0x114));
			break;
		case 2:
			opT6_parts->input(&XEvent(0x115));
			break;
		case 3:
			opT6_parts->input(&XEvent(0x116));
			break;
		}
		return true;
	default:
		return false;
	}
}

//==================================================================
// CPart consoles: update
//==================================================================

class CPart : public Console
{
public:
	void blitTo(XConsole *target);	// NOTE: placeholder name (0x4a94d0)
};

class CPartAnimation : public Console
{
public:
	virtual ~CPartAnimation();
	virtual void update();
};

void CPartAnimation::update()
{
	if (isHidden())
		return;
	if (!engine->isRunning())
		getParent()->removeSubconsole(this);
}

class CPartSorted : public Console
{
public:
	virtual ~CPartSorted();
	virtual void update();
};

void CPartSorted::update()
{
	if (isHidden())
		return;
	((CPart *)getParent())->blitTo(this);
	if (!engine->isRunning())
		getParent()->removeSubconsole(this);
}

class HEntity	// NOTE: placeholder layout
{
	int ID;
public:
	bool operator!=(HEntity other) const;
};

class Push_4a9370	// NOTE: placeholder name (see src/match_push)
{
public:
	void operate(int arg0);
};

class OpT6_PartsHandles	// NOTE: placeholder name (CParts, 0xcec088)
{
public:
	char pad0[0x160];
	HEntity unknown160;	// NOTE: placeholder name
	int pad164;
	HEntity unknown168;	// NOTE: placeholder name
	int pad16c;
	HEntity unknown170;	// NOTE: placeholder name
};
extern OpT6_PartsHandles *opT6_partsHandles;	// 0xcec088 NOTE: placeholder name

class CPartConfirming : public Console
{
public:
	virtual ~CPartConfirming();
	virtual void update();

	HEntity unknown6c;	// NOTE: placeholder name
};

void CPartConfirming::update()
{
	if (isHidden())
		return;
	if (!engine->isRunning() || (unknown6c != opT6_partsHandles->unknown160 && unknown6c != opT6_partsHandles->unknown168 && unknown6c != opT6_partsHandles->unknown170))
	{
		((Push_4a9370 *)getParent())->operate((int)this);
		getParent()->removeSubconsole(this);
	}
}

//==================================================================
// CPartWeaponHitChance
//==================================================================

extern int opT6_d20b6c;	// NOTE: placeholder name

class CPartWeaponHitChance : public Console
{
public:
	CPartWeaponHitChance(XConsole *parent);	// 0x88e3c0
	virtual ~CPartWeaponHitChance();

	vector<unsigned int> unknown6c;	// NOTE: placeholder name
};

CPartWeaponHitChance::CPartWeaponHitChance(XConsole *parent)
	: Console(parent,opT6_d20b6c,1,parent->getWidth() - opT6_d20b6c,0,0,false,-1)
{
}

//==================================================================
// CVolley
//==================================================================

class CVolley : public Console
{
public:
	virtual ~CVolley();
	virtual void open();

	bool unknown6c;	// NOTE: placeholder name
};

void CVolley::open()
{
	unknown60 = 1;
	setHidden(false);
	if (unknown6c)
		clearInterior();
	else
	{
		clear();
		animate("CVolley_Border");
		unknown6c = true;
	}
	setScaleX(1.0f);
	setScaleY(1.0f);
}

//==================================================================
// CRpglikeButton
//==================================================================

extern bool opT6_cf46a0;	// NOTE: placeholder name

class CRpglikeButton : public Console
{
public:
	virtual ~CRpglikeButton();
	virtual bool input(void *event);
	virtual void update();

	void draw();	// NOTE: placeholder name (see op_w5.cpp)

	int unknown6c;	// NOTE: placeholder name
};

void CRpglikeButton::update()
{
	if (unknown6c == -1)
	{
		unknown6c = opT6_cf46a0 != 0;
		if (unknown6c == 0)
			animate("A_Rpglike_LevelGlow");
	}
	else if (unknown6c != (opT6_cf46a0 != 0))
	{
		if (!opT6_cf46a0)
			animate("A_Rpglike_LevelGlow");
		else if (opT6_cf46a0)
		{
			engine->killGroup("attnglo");
			draw();
		}
		unknown6c = opT6_cf46a0 != 0;
	}
	engine->isRunning();
}

//==================================================================
// CRpglikeButton::input
//==================================================================

class CRpglike	// NOTE: placeholder name (0xcec060)
{
public:
	void unknown49cd70();	// NOTE: placeholder name
};
extern CRpglike *opT6_rpglike;	// 0xcec060 NOTE: placeholder name

class CRpglikeUpgrades : public Console
{
public:
	CRpglikeUpgrades(XConsole *parent);	// 0x49d460
	virtual ~CRpglikeUpgrades();

	char pad6c[0xb4 - 0x6c];
};
extern CRpglikeUpgrades *opT6_rpglikeUpgrades;	// 0xcec064 NOTE: placeholder name
extern XConsole *opT6_cec034;	// NOTE: placeholder name
extern bool opT6_cefa5f;	// NOTE: placeholder name (console input blocked)

class OpT6_MapView	// NOTE: placeholder name (0xcec054)
{
public:
	void unknown49ad70(unsigned int time);	// NOTE: placeholder name
	bool unknown8080a0();	// NOTE: placeholder name
};
extern OpT6_MapView *opT6_mapView;	// 0xcec054 NOTE: placeholder name

class OpT6_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	bool hasCommand(int command);	// NOTE: placeholder name (0x416200)
};
extern OpT6_KeyMap *opT6_keyMap;	// 0xcefa8c NOTE: placeholder name

bool CRpglikeButton::input(void *event)
{
	if (isHidden() || opT6_cefa5f)
		return false;
	if (inputBase_429d00(event))
		return true;
	if (opT6_world->unknown71bbd0())
		return false;
	switch (((XEvent *)event)->type)
	{
	case 5:
		opT6_mapView->unknown49ad70(tickCount + 500);
		if (!opT6_keyMap->hasCommand(7))
			return false;
	case 0x98:
		if (opT6_rpglikeUpgrades == NULL)
		{
			opT6_rpglike->unknown49cd70();
			opT6_rpglikeUpgrades = new CRpglikeUpgrades(opT6_cec034);
			return true;
		}
		else
			return false;
		break;
	}
	return false;
}

//==================================================================
// CVolleyButton / CPartsButton
//==================================================================

class OpT6_Parts2	// NOTE: placeholder name (CParts, 0xcec088)
{
public:
	void unknown8968b0(int value);	// NOTE: placeholder name
};
extern OpT6_Parts2 *opT6_parts2;	// 0xcec088 NOTE: placeholder name

class CVolleyButton : public Console
{
public:
	virtual ~CVolleyButton();
	virtual bool input(void *event);

	void setHighlight(bool highlight);	// NOTE: placeholder name
};

bool CVolleyButton::input(void *event)
{
	if (opT6_world->unknown71bbd0())
		return false;
	switch (((XEvent *)event)->type)
	{
	case 0x34:
	case 0x127:
		setHighlight(opT6_mapView->unknown8080a0());
		return true;
	}
	return false;
}

class CPartsButton : public Console
{
public:
	virtual ~CPartsButton();
	virtual bool input(void *event);

	int unknown6c;	// NOTE: placeholder name
};

bool CPartsButton::input(void *event)
{
	if (opT6_world->unknown71bbd0())
		return false;
	switch (((XEvent *)event)->type)
	{
	case 0x117:
		opT6_parts2->unknown8968b0(unknown6c);
		return true;
	}
	return false;
}

//==================================================================
// CDragDrop
//==================================================================

class OpT6_Mouse	// NOTE: placeholder name (XMouse, 0xcefa94)
{
public:
	int getWidth_9fcd80();	// NOTE: placeholder name (folded getter: first field)
	int getHeight_9b8f00();	// NOTE: placeholder name (folded getter: second field)
};
extern OpT6_Mouse *opT6_mouse;	// 0xcefa94 NOTE: placeholder name
extern unsigned int opT6_d28e64;	// NOTE: placeholder name

class OpT6_Parts3	// NOTE: placeholder name (CParts, 0xcec088)
{
public:
	void unknown4a9c60();	// NOTE: placeholder name (Calls_4a9c60::delegate)
};
extern OpT6_Parts3 *opT6_parts3;	// 0xcec088 NOTE: placeholder name

class OpT6_Inventory	// NOTE: placeholder name (CInventory, 0xcec08c)
{
public:
	void unknown8a53c0();	// NOTE: placeholder name
	void unknown4aa790();	// NOTE: placeholder name (Calls_4aa790::delegate)
};
extern OpT6_Inventory *opT6_inventory;	// 0xcec08c NOTE: placeholder name

class OpT6_Keys	// NOTE: placeholder name (0xcefa8c)
{
public:
	void popFrame();	// 0x416640
	void setField4c_44cea0(OpT6_Parts3 *value);	// NOTE: placeholder name
};
extern OpT6_Keys *opT6_keys;	// 0xcefa8c NOTE: placeholder name

class OpT6_Holder	// NOTE: placeholder name (0xcec0d4)
{
public:
	Console *getConsole_4ab670() throw();	// NOTE: placeholder name
};
extern OpT6_Holder *opT6_holder;	// 0xcec0d4 NOTE: placeholder name
extern int opT6_cec12c;	// NOTE: placeholder name
extern int opT6_cefc90;	// NOTE: placeholder name
extern XColor *opT6_cf6b24;	// NOTE: placeholder name

class OpT6_Mouse2	// NOTE: placeholder name (XMouse, 0xcefa94)
{
public:
	void updatePosition();	// 0x41a8b0
};
extern OpT6_Mouse2 *opT6_mouse2;	// 0xcefa94 NOTE: placeholder name

class CDragDrop : public Console
{
public:
	virtual ~CDragDrop();
	virtual void update();
	virtual void close();

	char pad6c[0x70 - 0x6c];
	bool unknown70;	// NOTE: placeholder name
	unsigned int unknown74;	// NOTE: placeholder name
};

void CDragDrop::update()
{
	engine->isRunning();
	setPos(Pos(opT6_mouse->getWidth_9fcd80() - getWidth() / 2,opT6_mouse->getHeight_9b8f00()));
	if (tickCount > unknown74 + opT6_d28e64)
		close();
}

void CDragDrop::close()
{
	opT6_keys->popFrame();
	opT6_keys->setField4c_44cea0(opT6_parts3);
	if (unknown70)
	{
		opT6_inventory->unknown8a53c0();
		unknown70 = false;
	}
	opT6_cec12c = 0;
	getParent()->removeSubconsole(this);
	opT6_parts3->unknown4a9c60();
	opT6_inventory->unknown4aa790();
	if (opT6_cefc90 == 1)
	{
		opT6_holder->getConsole_4ab670()->engine->killGroup("invglow");
		opT6_holder->getConsole_4ab670()->setForeAll_4183d0(*opT6_cf6b24);
	}
	opT6_mouse2->updatePosition();
}
