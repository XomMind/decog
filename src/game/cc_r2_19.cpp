// Small header-inline constructors and console helpers laid out by LTCG at 0x499a50-0x499eba.
// NOTE: class layouts are partial; all class/member names except CScrapEngineContent (RTTI) are placeholders.
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;

	Pos(const Pos &pos);	// 0x46ca50
};

struct PosB	// NOTE: placeholder name (same address as Pos::Pos(const Pos&): ICF)
{
	int x;
	int y;

	PosB &operator=(const PosB &pos);	// 0x46ca50
};

struct Handle4	// NOTE: placeholder name
{
	int ID;
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor &operator=(const XColor &color);	// 0x411e30
};

class XConsole
{
public:
	virtual ~XConsole();
	int getLayer_44a7d0();	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);

	char pad4[0x54];
	int layer;
	char pad5c[4];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();

	char pad60[0xc];
};

class CScrapEngineContent : public Console
{
public:
	CScrapEngineContent(XConsole *parent);
	virtual ~CScrapEngineContent();

	bool flag6c;	// NOTE: placeholder name
	unsigned int tick70;	// NOTE: placeholder name
};

class PanelChild	// NOTE: placeholder name
{
public:
	void unknown499af0();	// NOTE: placeholder name

	char pad0[0x6c];
	bool flag6c;	// NOTE: placeholder name
	unsigned int tick70;	// NOTE: placeholder name
};

class XBuffer	// NOTE: placeholder name
{
public:
	XBuffer(bool flag) throw();	// 0x499b50

	bool flag;	// NOTE: placeholder name
	vector<int> values;	// NOTE: placeholder name
	unsigned int tick;	// NOTE: placeholder name
};

struct MapRecord	// NOTE: placeholder name
{
	int ID;
};

class MapView	// NOTE: placeholder name
{
public:
	void unknown49af80(int id);	// NOTE: placeholder name
};

class Item;

class XTimer	// NOTE: placeholder name
{
public:
	XTimer(int value_);	// NOTE: placeholder name
	void unknown499d90();	// NOTE: placeholder name
	bool unknown499dc0();	// NOTE: placeholder name

	XConsole *console;	// NOTE: placeholder name
	unsigned int tick;	// NOTE: placeholder name
};

class XTimerB	// NOTE: placeholder name
{
public:
	XTimerB(const Pos &pos_, int a_, int b_);	// NOTE: placeholder name

	Pos pos;
	int a;
	int b;
	unsigned int tick;
};

class XTimerC	// NOTE: placeholder name
{
public:
	XTimerC(const Pos &pos_);	// NOTE: placeholder name

	Pos pos;
	unsigned int tick;
};

class XTimerD	// NOTE: placeholder name
{
public:
	XTimerD(const Pos &pos_, bool flag_);	// NOTE: placeholder name

	Pos pos;
	bool flag;
	unsigned int tick;
};

class XTimerE	// NOTE: placeholder name
{
public:
	XTimerE(int a_, const Pos &pos_);	// NOTE: placeholder name

	int a;
	Pos pos;
	unsigned int tick;
};

class XTimerF	// NOTE: placeholder name
{
public:
	XTimerF(const Handle4 &a_, const PosB &pos_, const XColor &color_, int b_);	// NOTE: placeholder name

	Handle4 a;
	PosB pos;
	XColor color;
	int b;
};

class XBufferB	// NOTE: placeholder name
{
public:
	XBufferB(const Pos &pos_, bool flag_) throw();	// 0x499cf0

	Pos pos;
	unsigned int tick;
	bool flag;
};

class XTimerH	// NOTE: placeholder name
{
public:
	XTimerH(const Pos &pos_, const Pos &pos2_, int a_, bool flag_, int b_);	// NOTE: placeholder name

	Pos pos;
	Pos pos2;
	unsigned int tick;
	int unknown14;
	int a;
	bool flag;
	int b;
};

class XTimerI	// NOTE: placeholder name
{
public:
	XTimerI(int type_, XConsole *console_, bool c_, int d_, const PosB &e_, int f_, int g_, int h_, const PosB &i_);	// NOTE: placeholder name
	void unknown499e90();	// NOTE: placeholder name

	int type;
	XConsole *console;
	bool c;
	int d;
	bool e;
	PosB pos14;
	int f;
	int g;
	int h;
	PosB pos28;
	bool table;
	bool flag31;
};

extern unsigned int tickCount;			// 0xcaed20
extern int unknown_d28e94;				// NOTE: placeholder name
extern bool unknown_cefa77;				// NOTE: placeholder name
extern bool unknown_bcac4c[];			// NOTE: placeholder name
extern XConsole *mainConsole;			// NOTE: placeholder name (0xcec054)
extern MapView *mapView;				// NOTE: placeholder name (0xcec054)

int XConsole::getLayer_44a7d0()
{
	return layer;
}

CScrapEngineContent::CScrapEngineContent(XConsole *parent)
	: Console(parent,1,1,0,1,0,true,parent->getLayer_44a7d0() + 2)
{
	flag6c = true;
	tick70 = 0;
}

CScrapEngineContent::~CScrapEngineContent()
{
}

void PanelChild::unknown499af0()
{
	if (unknown_d28e94 == 0)
		return;
	tick70 = tickCount + unknown_d28e94;
	flag6c = true;
}

XBuffer::XBuffer(bool flag_) throw()
	: flag(flag_)
	, values()
{
	tick = tickCount;
}

XTimer::XTimer(int value_)
{
	console = (XConsole *)value_;
	tick = tickCount;
}

XTimerB::XTimerB(const Pos &pos_, int a_, int b_)
	: pos(pos_)
{
	a = a_;
	b = b_;
	tick = tickCount;
}

XTimerC::XTimerC(const Pos &pos_)
	: pos(pos_)
{
	tick = tickCount;
}

XTimerD::XTimerD(const Pos &pos_, bool flag_)
	: pos(pos_)
{
	flag = flag_;
	tick = tickCount;
}

XTimerE::XTimerE(int a_, const Pos &pos_)
	: a(a_)
	, pos(pos_)
{
	tick = tickCount;
}

XTimerF::XTimerF(const Handle4 &a_, const PosB &pos_, const XColor &color_, int b_)
{
	a = a_;
	pos = pos_;
	color = color_;
	b = b_;
}

XBufferB::XBufferB(const Pos &pos_, bool flag_) throw()
	: pos(pos_)
{
	tick = tickCount;
	flag = flag_;
}

XTimerH::XTimerH(const Pos &pos_, const Pos &pos2_, int a_, bool flag_, int b_)
	: pos(pos_)
	, pos2(pos2_)
{
	tick = tickCount;
	unknown14 = -1;
	a = a_;
	flag = flag_;
	b = b_;
}

void XTimer::unknown499d90()
{
	if (unknown_cefa77)
		return;
	mainConsole->removeSubconsole(console);
}

bool XTimer::unknown499dc0()
{
	if (tick && tickCount >= tick)
	{
		mapView->unknown49af80((int)this);
		return true;
	}
	return false;
}

XTimerI::XTimerI(int type_, XConsole *console_, bool c_, int d_, const PosB &e_, int f_, int g_, int h_, const PosB &i_)
{
	type = type_;
	console = console_;
	c = c_;
	d = d_;
	e = false;
	pos14 = e_;
	f = f_;
	g = g_;
	h = h_;
	pos28 = i_;
	table = unknown_bcac4c[type_];
	flag31 = false;
	bool unused = true;
}

void XTimerI::unknown499e90()
{
	if (unknown_cefa77)
		return;
	mainConsole->removeSubconsole(console);
}
