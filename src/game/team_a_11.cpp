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
	virtual ~Console();
	void animate(string name);	// 0x48c3f0
	void addEffect_48c460(int type, Point *pos);	// NOTE: placeholder name
	void addEffect_48c4a0(int type, Point *pos, Point *target);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
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
class CTransmission : public Console
{
public:
	char pad68[0x7c - 0x68];
	vector<string> lines;
	virtual ~CTransmission();
};

CTransmission::~CTransmission()
{
	transmission_cec134 = 0;
}
