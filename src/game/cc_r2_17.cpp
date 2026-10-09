// CEffects / CMission / CMainUiButton / CFovEnemies(Button) header-inline members and a few
//	free helpers laid out at 0x4b3160-0x4b38e6.
// NOTE: class layouts are partial; padding members, member names and method names are placeholders.
#include <typeinfo>
#include "consoles/console.h"

struct Point
{
	int x;
	int y;

	Point(int value);	// 0x409990
};

class Entity;

class HEntity
{
	int ID;
public:
	Entity *operator->() const;	// 0x9b6570
};

class Entity
{
public:
	int getSlotTotal();	// 0x45a860
};

class Map	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	HEntity getPlayer();	// 0x4630f0
};
extern Map *world;	// NOTE: placeholder name (0xcefc4c)

class KeyBindings	// NOTE: placeholder name (global at 0xcefa8c, same object as keyMap)
{
public:
	void unknown4162e0(int command, bool flag);	// NOTE: placeholder name
};
extern KeyBindings *unknown_cefa8c;	// NOTE: placeholder name

extern unsigned int unknown_caed20;	// NOTE: placeholder name (tick counter)
extern int unknown_cefc94;	// NOTE: placeholder name
extern int unknown_cefc90;	// NOTE: placeholder name
extern bool unknown_cefc89;	// NOTE: placeholder name
extern bool unknown_cf4a00;	// NOTE: placeholder name
extern int unknown_cf27f4;	// NOTE: placeholder name
extern int unknown_caf128;	// NOTE: placeholder name
extern Rect unknown_d31690;	// NOTE: placeholder name
extern int unknown_d33be8;	// NOTE: placeholder name
extern int unknown_d33bec;	// NOTE: placeholder name
extern int unknown_cfb798;	// NOTE: placeholder name
extern int unknown_d38470;	// NOTE: placeholder name
extern string unknown_d39618[];	// NOTE: placeholder name
extern XColor *unknown_cf6b24;	// NOTE: placeholder name
extern XColor *unknown_cf169c;	// NOTE: placeholder name

class PanelHeight	// NOTE: placeholder name (global at 0xd223f0)
{
public:
	int unknown4189a0();	// NOTE: placeholder name
};
extern PanelHeight unknown_d223f0;	// NOTE: placeholder name

bool unknown4328a0();	// NOTE: placeholder name
bool vectorContains(vector<int> &values, int value);	// NOTE: placeholder name (0x9d51d0)
void unknown9cdcc0(int *values, int count, int value);	// NOTE: placeholder name

//==================================================================
// CEffects
//==================================================================
struct Container9cec20	// NOTE: placeholder name
{
	~Container9cec20() throw();	// 0x9cec20
	char pad[0x10];
};

class CEffects : public Console
{
public:
	virtual ~CEffects();
	virtual void update();

	bool unknown4b3160();	// NOTE: placeholder name
	bool unknown4b3180();	// NOTE: placeholder name
	bool unknown4b31a0();	// NOTE: placeholder name
	void unknown4b31c0();	// NOTE: placeholder name
	bool unknown4b31e0(int value);	// NOTE: placeholder name
	void unknown4b3210();	// NOTE: placeholder name

	char pad6c[0xc];
	int unknown78;	// NOTE: placeholder name
	vector<unsigned int> unknown7c;	// NOTE: placeholder name
	char pad8c[0x10];
	vector<unsigned int> unknown9c;	// NOTE: placeholder name
	char padac[4];
	int unknownb0;	// NOTE: placeholder name
	char padb4[8];
	vector<unsigned int> unknownbc;	// NOTE: placeholder name
	char padcc[4];
	vector<unsigned int> unknownd0;	// NOTE: placeholder name
	char padd4[4];
	vector<unsigned int> unknowne4;	// NOTE: placeholder name
	char padf4[0xc];
	vector<int> unknown100;	// NOTE: placeholder name
	char pad110[8];
	int unknown118;	// NOTE: placeholder name
	vector<unsigned int> unknown11c;	// NOTE: placeholder name
	vector<unsigned int> unknown12c;	// NOTE: placeholder name
	char pad13c[0x10];
	vector<Console *> unknown14c;	// NOTE: placeholder name
	vector<unsigned int> unknown15c;	// NOTE: placeholder name
	char pad16c[4];
	int unknown170;	// NOTE: placeholder name
	char pad174[0x1c];
	vector<Point> unknown190;	// NOTE: placeholder name
	Container9cec20 unknown1a0;	// NOTE: placeholder name
};

CEffects::~CEffects()
{
}

bool CEffects::unknown4b3160()
{
	return unknownb0 != 0;
}

bool CEffects::unknown4b3180()
{
	return unknown170 != -4;
}

bool CEffects::unknown4b31a0()
{
	return unknown118 != -1;
}

void CEffects::unknown4b31c0()
{
	unknown78--;
}

bool CEffects::unknown4b31e0(int value)
{
	return vectorContains(unknown100,value);
}

void CEffects::unknown4b3210()
{
	unknown14c.clear();
}

//==================================================================
// CMission
//==================================================================
class CMission : public Console
{
public:
	virtual ~CMission();
	virtual bool input(void *event);
	virtual void update();
	virtual void render();

	int unknown417eb0(XConsole *console);	// NOTE: placeholder name
	void unknown417f10(XConsole *console, int layer);	// NOTE: placeholder name
	void unknown4b3280();	// NOTE: placeholder name
	void unknown4b32c0();	// NOTE: placeholder name
	void unknown4b32e0();	// NOTE: placeholder name

	unsigned int unknown6c;	// NOTE: placeholder name
	unsigned int unknown70;	// NOTE: placeholder name
};

extern CMission *unknown_cec034;	// NOTE: placeholder name

CMission::~CMission()
{
}

void CMission::unknown4b3280()
{
	for (int command = 4; command <= 8; command++)
		unknown_cefa8c->unknown4162e0(command,false);
}

void CMission::unknown4b32c0()
{
	unknown6c = unknown_caed20;
}

void CMission::unknown4b32e0()
{
	unknown70 = unknown_caed20;
}

//==================================================================
// free helpers
//==================================================================
string unknown4b3330(XConsole *console)
{
	return typeid(*console).name();
}

class EngineB	// NOTE: placeholder name
{
public:
	string unknown50fc60(int value);	// NOTE: placeholder name
};

struct ConsoleB	// NOTE: placeholder name
{
	char pad[0x64];
	EngineB *engine;
};

string unknown4b3370(ConsoleB *console, int value)
{
	EngineB *engine = console->engine;
	return engine->unknown50fc60(value);
}

Pos unknown4b33b0()
{
	if (!unknown4328a0() || (world != NULL && world->getPlayer()->getSlotTotal() <= unknown_cefc94 - (unknown_cf4a00 ? 1 : 0)))
	{
		unknown_cefc90 = 0;
		unknown_cefc89 = false;
		return Pos(unknown_cf27f4 * unknown_caf128,unknown_d223f0.unknown4189a0() - 14);
	}
	else if (unknown_cefc89)
	{
		unknown_cefc90 = 2;
		return Pos(unknown_d31690.x - unknown_d33be8,unknown_d223f0.unknown4189a0() - 14);
	}
	else
	{
		unknown_cefc90 = 1;
		return Pos(unknown_cf27f4 * unknown_caf128,unknown_d223f0.unknown4189a0());
	}
}

int unknown4b34b0()
{
	if (!unknown4328a0() || (world != NULL && world->getPlayer()->getSlotTotal() <= unknown_cefc94 - (unknown_cf4a00 ? 1 : 0)))
		return unknown_d223f0.unknown4189a0() - unknown_d33bec - unknown_cfb798 - unknown_d38470;
	else
		return unknown_d223f0.unknown4189a0() - unknown_cfb798 - unknown_d38470;
}

class PanelC : public Console	// NOTE: placeholder name (constructor 0x893c70)
{
public:
	PanelC(XConsole *parent, const Rect &rect);

	char padPanel[0x1c8 - sizeof(Console)];
};
extern PanelC *unknown_cec088;	// NOTE: placeholder name

void unknown4b3540(XConsole *parent)
{
	int layer = -1;
	if (unknown_cec088 != NULL)
	{
		layer = unknown_cec034->unknown417eb0(unknown_cec088);
		unknown_cec034->removeSubconsole(unknown_cec088);
	}
	Rect rect(unknown_d31690);
	rect.height = unknown4b34b0();
	unknown_cec088 = new PanelC(parent,rect);
	if (layer != -1)
		unknown_cec034->unknown417f10(unknown_cec088,layer);
}

//==================================================================
// CMainUiButton / CFovEnemiesButton / CFovEnemies
//==================================================================
class CMainUiButton : public Console
{
public:
	CMainUiButton(XConsole *parent, int x, int index);
	virtual ~CMainUiButton();
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
	virtual void update();

	int index;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	int unknown74[4];	// NOTE: placeholder name
};

CMainUiButton::CMainUiButton(XConsole *parent, int x, int index_)
	: Console(parent,unknown_d39618[index_].size(),1,x,0,0,false,-1)
{
	index = index_;
	unknown70 = (index_ == 1 ? 2 : 0);
	unknown9cdcc0(unknown74,4,0);
	setFore(*unknown_cf6b24);
	print(0,0,unknown_d39618[index]);
}

class CFovEnemiesButton : public Console
{
public:
	CFovEnemiesButton(XConsole *parent, int x, const string &text);
	virtual ~CFovEnemiesButton();
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
};

CFovEnemiesButton::CFovEnemiesButton(XConsole *parent, int x, const string &text)
	: Console(parent,text.size(),1,x,0,0,false,-1)
{
	setFore(*unknown_cf169c);
	print(0,0,text);
}

bool CFovEnemiesButton::mouseEnter()
{
	animate("A_ButtonHover_Begin_FOV_ENEMIES_HOV_OK");
	return true;
}

void CFovEnemiesButton::mouseLeave()
{
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_FOV_ENEMIES_HOV_OK");
}

class CFovEnemies : public Console
{
public:
	virtual ~CFovEnemies();
	virtual void update();
};
extern CFovEnemies *unknown_cec0f0;	// NOTE: placeholder name

CFovEnemies::~CFovEnemies()
{
	unknown_cec0f0 = NULL;
}

//==================================================================
// pair of cell records
//==================================================================
struct Cell9b3430	// NOTE: placeholder name
{
	void unknown9b3430(int ch, const Point &p);	// NOTE: placeholder name (0x9b3430)
	char pad[0x10];
};

struct Pair4b38a0	// NOTE: placeholder name
{
	void unknown4b38a0();	// NOTE: placeholder name

	int unknown0;	// NOTE: placeholder name
	char pad4[4];
	Cell9b3430 a;	// NOTE: placeholder name
	Cell9b3430 b;	// NOTE: placeholder name
};

void Pair4b38a0::unknown4b38a0()
{
	unknown0 = 0;
	a.unknown9b3430(0x49,Point(-1));
	b.unknown9b3430(0x49,Point(-1));
}
