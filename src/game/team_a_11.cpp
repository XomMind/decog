// team_a_11: key binding record, Console effect helpers, CGamoverButton::mouseLeave, CTransmission dtor.
// NOTE: class layouts are partial; names are placeholders unless they come from RTTI. External callees are declared
// throw() where LTCG proves them nothrow in the real link (no EH frame in the exe).
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int	x;
	int	y;
};

class Cell;
template <class T> class Array2D
{
public:
	int getWidth() throw();
};

namespace Protobuf
{
class Stats_Resources
{
public:
	virtual int GetCachedSize() const throw();
};
}

class Sweep_415f00 { public: unsigned char getField() throw(); };
class Sweep_415f20 { public: unsigned char getField() throw(); };
class Sweep_45e3c0 { public: unsigned char getField() throw(); };

class XCommand
{
public:
	string &getName() throw();
};

struct KeyBinding_4395b0	// NOTE: placeholder name
{
	int key;
	int unknown4;
	string name;
	unsigned char unknown24;
	unsigned char unknown25;
	unsigned char unknown26;
	int unknown28;
	KeyBinding_4395b0(int key_, XCommand *command);
};

KeyBinding_4395b0::KeyBinding_4395b0(int key_, XCommand *command)
	: key(key_),
	  unknown4(((Array2D<Cell *> *)command)->getWidth()),
	  name(command->getName()),
	  unknown24(((Sweep_415f00 *)command)->getField()),
	  unknown25(((Sweep_45e3c0 *)command)->getField()),
	  unknown26(((Sweep_415f20 *)command)->getField()),
	  unknown28(((Protobuf::Stats_Resources *)command)->Protobuf::Stats_Resources::GetCachedSize())
{
}

class XConsole
{
public:
	virtual ~XConsole();
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
	void killGroup(string group);	// 0x50fd90
};

extern Point opX5D_cfbec0;	// NOTE: placeholder name

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);	// 0x48c060
	virtual ~Console();
	void setHidden(bool hidden_);
	void animate(string name);	// 0x48c3f0
	void addEffect_48c460(int type, Point *pos);	// NOTE: placeholder name
	void addEffect_48c4a0(int type, Point *pos, Point *target);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	int unknown68;	// NOTE: placeholder name
};

void Console::addEffect_48c460(int type, Point *pos)
{
	engine->unknown50fb50(engine,type,pos,&opX5D_cfbec0,0,0,9)->unknown50de10();
}

void Console::addEffect_48c4a0(int type, Point *pos, Point *target)
{
	engine->unknown50fb50(engine,type,pos,&opX5D_cfbec0,target,&opX5D_cfbec0,9)->unknown50de10();
}

class CGamoverButton : public Console
{
public:
	virtual void mouseLeave();
};

void CGamoverButton::mouseLeave()
{
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_EVOL_HOV_OK");
}

extern void *transmission_cec134;	// NOTE: placeholder name (0xcec134)

struct Pos
{
	int x;
	int y;
};
struct XColor;
struct HEntity { int ID; };
struct SoundData;

class ConsoleTitle	// 0x48c710
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);
	char pad[0x8c];
};

class CCloseButton : public Console
{
public:
	CCloseButton(XConsole *parent, const XColor &color, int x);
	char pad6c[0x8c - 0x6c];
};

class TeamA11_MapView	// NOTE: placeholder name (CMap at 0xcec054)
{
public:
	bool isActive_49aa00();	// NOTE: placeholder name
	void unknown827950();	// NOTE: placeholder name
};
extern TeamA11_MapView *teamA11_mapView_cec054;	// NOTE: placeholder name

class OpS_Graph
{
public:
	void pushFrame(int index, int value, int other, bool flag);
};
extern OpS_Graph *teamA11_graph_cefa8c;	// NOTE: placeholder name

struct TeamA11_TransmissionData	// NOTE: placeholder name (element of the table at 0xcf3a20)
{
	char pad00[0x58];
	SoundData *sound;	// NOTE: placeholder name
};
extern vector<TeamA11_TransmissionData*> teamA11_transmissions_cf3a20;	// NOTE: placeholder name
extern XColor *teamA11_color_cf1f2c;	// NOTE: placeholder name
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name
int opY3_playSound(SoundData *sound, int channel, int fade, int loopsB, int loops);	// NOTE: placeholder name (0x4ff050)

class CTransmission : public Console
{
public:
	CTransmission(XConsole *parent, const Pos &pos, HEntity entity_, int id_, int type_, const vector<string> &pages_);	// 0x4af020
	virtual ~CTransmission();
	void setTitle(ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void unknown8f3e50();	// NOTE: placeholder name

	char pad6c[0x70 - 0x6c];
	CCloseButton *closeButton;	// NOTE: placeholder name
	int id;	// NOTE: placeholder name
	int unknown78;	// NOTE: placeholder name
	vector<string> lines;
	HEntity entity;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
	Console *text;	// NOTE: placeholder name
	int channel;	// NOTE: placeholder name
};

CTransmission::CTransmission(XConsole *parent, const Pos &pos, HEntity entity_, int id_, int type_, const vector<string> &pages_)
	: Console(parent,50,10,pos.x,pos.y,0,false,10)
	, id(id_)
	, unknown78(0)
	, lines(pages_)
	, entity(entity_)
	, type(type_)
{
	transmission_cec134 = this;
	if (type == 0 || type == 2)
		setTitle(new ConsoleTitle(this,"\\ T R A N S M I S S I O N \\",0,2));
	else
		setTitle(new ConsoleTitle(this,"/ T R A N S M I S S I O N /",0,4));
	animate("CTransmission_Border");
	if (teamA11_mapView_cec054->isActive_49aa00())
		teamA11_mapView_cec054->unknown827950();
	teamA11_graph_cefa8c->pushFrame(0x11,(int)this,0x105,false);
	unknown60 = 1;
	text = new Console(this,48,8,1,1,0,false,-1);
	unknown8f3e50();
	channel = opR1d_4541b0(0x6e,500,-1);
	if (teamA11_transmissions_cf3a20[id]->sound != NULL)
		opY3_playSound(teamA11_transmissions_cf3a20[id]->sound,-1,0,0,0);
	closeButton = new CCloseButton(this,*teamA11_color_cf1f2c,0x11);
	closeButton->setHidden(false);
}

CTransmission::~CTransmission()
{
	transmission_cec134 = 0;
}
