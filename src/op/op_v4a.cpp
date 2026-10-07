// op_v4a: UI consoles 0x889000-0x96a000, Beta 17.1.
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
	void unknown429fe0(XConsole *console, const Pos &pos, const Rect &rect) throw();	// NOTE: placeholder name (nothrow in the exe)
	void clearInterior();
	void deleteSubconsoles();
	void unknown429f10(vector<unsigned int> *colors, bool flag);	// NOTE: placeholder name
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)
	float getScaleX();
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
	bool unknown454d30();	// NOTE: placeholder name
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
	void replaceSpecialChars(int ch);	// NOTE: placeholder name
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
class OpV4a_Shortcut	// NOTE: placeholder name (0xcec128)
{
public:
	int unknownGetter();	// NOTE: placeholder name (folded getter)
};
extern OpV4a_Shortcut *opv4a_cec128;	// NOTE: placeholder name
extern XConsole *opv4a_cec07c;	// NOTE: placeholder name

class CEvasionFull : public Console
{
public:
	CEvasionFull(XConsole *parent, const Rect &rect);	// 0x888c80
};

void opq4a_unknown889950()	// NOTE: placeholder name
{
	if (opv4a_cec128 && opv4a_cec128->unknownGetter() == 4)
		return;
	int w = 0x22;
	int h = 0xc;
	Rect rect(-4,0,w,h);
	new CEvasionFull(opv4a_cec07c,rect);
}

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);
	char pad6c[0x8c - 0x6c];
};

//==================================================================
// CVolleyButtons / CVolley
//==================================================================

extern XColor *opv4a_cf6b24;	// NOTE: placeholder name

class CVolleyButton : public Console
{
public:
	CVolleyButton(XConsole *parent, int x, int range);	// 0x4a2d60
	virtual ~CVolleyButton();

	int range;	// NOTE: placeholder name
};

class CVolleyButtons : public Console
{
public:
	CVolleyButtons(XConsole *parent);	// 0x889a70
	virtual ~CVolleyButtons();

	vector<CVolleyButton*> buttons;	// NOTE: placeholder name
};

CVolleyButtons::CVolleyButtons(XConsole *parent)
	: Console(parent,3,1,3,parent->getHeight() - 1,0,false,-1)
{
	putChar_418110(0,0,'{',*opv4a_cf6b24);
	for (int i = 2; i < getWidth() - 1; i += 2)
		putChar_418110(i,0,'\\',*opv4a_cf6b24);
	putChar_418110(getWidth() - 1,0,'}',*opv4a_cf6b24);
	for (int i = 0, x = 1; i < 1; i++, x += 2)
		buttons.push_back(new CVolleyButton(this,x,i));
}

extern Rect opv4a_d35e08;	// NOTE: placeholder name

class OpV4a_MapView	// NOTE: placeholder name (0xcec054)
{
public:
	bool unknown49aa00();	// NOTE: placeholder name
};
extern OpV4a_MapView *opv4a_mapView;	// NOTE: placeholder name

class CVolley : public Console
{
public:
	CVolley(XConsole *parent);	// 0x889c10
	virtual ~CVolley();
	virtual void update();	// 0x889df0
	virtual void render();	// 0x88a000
	virtual void open();	// 0x889d70
	virtual void close();	// 0x889fc0

	bool unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	bool unknown74;	// NOTE: placeholder name
	vector<unsigned int> unknown78;	// NOTE: placeholder name
	bool unknown88;	// NOTE: placeholder name
	vector<unsigned int> unknown8c;	// NOTE: placeholder name
};

CVolley::CVolley(XConsole *parent)
	: Console(parent,opv4a_d35e08,0,true,3)
	, unknown74	(false)
	, unknown88	(false)
{
	setTitle((ConsoleTitle *)new ConsoleTitle(this,"/ V O L L E Y /",0,4));
	unknown6c = false;
	new CVolleyButtons(this);
}

void CVolley::update()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
		case 0:
			break;
		case 1:
			if (!engine->isRunning())
				unknown60 = 3;
			break;
		case 3:
			if (unknown6c)
				unknown74 = true;
			engine->isRunning();
			if (opv4a_mapView->unknown49aa00())
			{
				if (!opv4a_cec07c->isHidden())
					opv4a_cec07c->setHidden(true);
			}
			else if (opv4a_cec07c->isHidden())
				opv4a_cec07c->setHidden(false);
			break;
		case 4:
			engine->isRunning();
			if (getScaleX() != 0)
			{
				if (tickCount - unknown70 >= 500)
				{
					setScaleX(0);
					setScaleY(0);
				}
				else
				{
					setScaleX((float)(1 - (tickCount - unknown70) / 500.0));
					setScaleY((float)(1 - (tickCount - unknown70) / 500.0));
					break;
				}
			}
			engine->stopAll();
			unknown60 = 0;
			setHidden(true);
			break;
	}
	updateBase429e30();
}

//==================================================================
// CPartsButton / CPartsButtons
//==================================================================

extern int opv4a_d28d68;	// NOTE: placeholder name
extern XColor *opv4a_d25e0c;	// NOTE: placeholder name
extern XColor *opv4a_d20438;	// NOTE: placeholder name
extern char opv4a_b8f73c[];	// NOTE: placeholder name

class CPartsButton : public Console
{
public:
	CPartsButton(XConsole *parent, int x, int type_);	// 0x4a2ef0
	virtual ~CPartsButton();

	void draw();	// NOTE: placeholder name (0x88b680)

	int type;	// NOTE: placeholder name
};

void CPartsButton::draw()
{
	clear();
	putChar_418110(0,0,opv4a_b8f73c[type],(opv4a_d28d68 == 4 && type == 0) || (opv4a_d28d68 == 5 && type == 1) || (opv4a_d28d68 == 6 && type == 2) || (opv4a_d28d68 == 7 && type == 3) ? *opv4a_d20438 : (opv4a_d28d68 == type ? *opv4a_d25e0c : *opv4a_cf6b24));
}

class CPartsButtons : public Console
{
public:
	CPartsButtons(XConsole *parent);	// 0x88b7c0
	virtual ~CPartsButtons();

	void refreshRows();	// NOTE: placeholder name (0x4a2f80)

	vector<CPartsButton*> buttons;	// NOTE: placeholder name
};

CPartsButtons::CPartsButtons(XConsole *parent)
	: Console(parent,9,1,parent->getWidth() - 10,parent->getHeight() - 1,0,false,-1)
{
	putChar_418110(0,0,'{',*opv4a_cf6b24);
	for (int i = 2; i < getWidth() - 1; i += 2)
		putChar_418110(i,0,'\\',*opv4a_cf6b24);
	putChar_418110(getWidth() - 1,0,'}',*opv4a_cf6b24);
	for (int i = 0, x = 1; i < 4; i++, x += 2)
		buttons.push_back(new CPartsButton(this,x,i));
}

//==================================================================
// CPartInfo
//==================================================================

class OpV4a_Item	// NOTE: placeholder name (Item)
{
public:
	void *getEffect(int type);	// 0x457b70
	bool unknown457cf0();	// NOTE: placeholder name
	bool unknown457d30();	// NOTE: placeholder name
	bool unknown457d50();	// NOTE: placeholder name
	bool unknown458220();	// NOTE: placeholder name
	bool unknown415ee0();	// NOTE: placeholder name (ICF'd trivial getter)
	int unknown44ab90();	// NOTE: placeholder name (ICF'd getter at +0x2c)
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
	OpV4a_Item *operator->() const;	// 0x9b65b0
};

class OpV4a_PropData	// NOTE: placeholder name
{
public:
	char pad00[0xf8];
	int unknownF8;	// NOTE: placeholder name
};

class OpV4a_Prop	// NOTE: placeholder name (Prop)
{
public:
	OpV4a_PropData *getData();	// NOTE: placeholder name (folded getter)
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp();
	OpV4a_Prop *operator->() const;	// 0x9b64f0
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();
};

int opw6_getItemState(HItem item);	// NOTE: placeholder name (0x4a2fd0)

extern BS *opv4a_world;	// NOTE: placeholder name (0xcefc4c)
extern int opv4a_bcc2e0;	// NOTE: placeholder name

class OpV4a_PartsOwner : public Console	// NOTE: placeholder name
{
public:
	HItem item;
};

class OpV4a_PartsOther : public Console	// NOTE: placeholder name
{
public:
	HItem item;
};

class CPartInfo : public Console
{
public:
	CPartInfo(XConsole *parent, bool flag);	// 0x88b970
	virtual ~CPartInfo();

	void unknown88bab0(bool flag);	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
	string unknown78;	// NOTE: placeholder name
	int unknown94;	// NOTE: placeholder name
};

CPartInfo::CPartInfo(XConsole *parent, bool flag)
	: Console(parent,opv4a_bcc2e0,1,parent->getWidth() - opv4a_bcc2e0,0,0,false,-1)
	, unknown6c	(flag)
	, unknown70	(opv4a_d28d68)
	, unknown74	(-1)
{
	unknown94 = opw6_getItemState(unknown6c ? ((OpV4a_PartsOwner *)parent)->item : ((OpV4a_PartsOther *)parent)->item);
	unknown88bab0(false);
}

//==================================================================
// CPart
//==================================================================

extern unsigned int opv4a_cefc80;	// NOTE: placeholder name
extern unsigned int opv4a_cefc84;	// NOTE: placeholder name

class CPart;

class OpV4a_Parts : public XConsole	// NOTE: placeholder name (CParts at 0xcec088)
{
public:
	void unknown8993e0(CPart *part, int a);	// NOTE: placeholder name
	void unknown4a9c60();	// NOTE: placeholder name
	int unknown898910(CPart *part, HProp item, int value);	// NOTE: placeholder name
	void setTimed4a9c30(HItem item);	// NOTE: placeholder name
};
extern OpV4a_Parts *opv4a_cec088;	// NOTE: placeholder name

class OpV4a_Partswap : public Console	// NOTE: placeholder name (CPartswap at 0xcec090)
{
public:
	void open(CPart *part, int b, HProp item, bool flag);	// NOTE: placeholder name
};
extern OpV4a_Partswap *opv4a_cec090;	// NOTE: placeholder name

class OpV4a_Info : public Console	// NOTE: placeholder name (CInfo at 0xcec11c)
{
public:
	void unknown8b4500(HEntity a, HItem b, HEntity c, Pos *pos, int mode, bool e);	// NOTE: placeholder name
};
extern OpV4a_Info *opv4a_cec11c;	// NOTE: placeholder name

class OpV4a_Map	// NOTE: placeholder name (BS at 0xcefc4c)
{
public:
	int getTurn();	// 0x464270
};

extern XColor *opv4a_cfd448;	// NOTE: placeholder name
extern XColor *opv4a_d2b284;	// NOTE: placeholder name
extern XColor *opv4a_d204ac;	// NOTE: placeholder name
extern XColor *opv4a_d30424;	// NOTE: placeholder name
extern XColor *opv4a_cf27e8;	// NOTE: placeholder name
extern XColor *opv4a_d323c4;	// NOTE: placeholder name
extern XColor *opv4a_d1d46c;	// NOTE: placeholder name
extern XColor *opv4a_d2981c;	// NOTE: placeholder name
extern XColor *opv4a_cf44c0;	// NOTE: placeholder name
extern XColor *opv4a_cfc174;	// NOTE: placeholder name
extern XColor *opv4a_d22fcc;	// NOTE: placeholder name
extern XColor *opv4a_d316f4;	// NOTE: placeholder name
extern bool opv4a_b8f734[];	// NOTE: placeholder name
extern OpV4a_Map *opv4a_map;	// NOTE: placeholder name (0xcefc4c)

class CPart : public Console
{
public:
	virtual ~CPart();
	virtual bool input(void *event);	// 0x890540

	void unknown890710(bool flag);	// NOTE: placeholder name

	HItem item;	// NOTE: placeholder name
	bool unknown70;	// NOTE: placeholder name
	char pad71[0x78 - 0x71];
	bool unknown78;	// NOTE: placeholder name
	char pad79[0x88 - 0x79];
	bool unknown88;	// NOTE: placeholder name
	char pad89[0x94 - 0x89];
	CPartInfo *unknown94;	// NOTE: placeholder name
};

bool CPart::input(void *event)
{
	if (opv4a_world->unknown71bbd0())
		return false;
	if (tickCount < opv4a_cefc84)
		return false;
	switch (((XEvent *)event)->type)
	{
	case 0x117:
		if (item.isValid())
		{
			opv4a_cec088->unknown8993e0(this,0);
			opv4a_cec088->unknown4a9c60();
		}
		else
			opv4a_cec090->open(this,0,HProp(),false);
		return true;
	case 0x118:
		if (item.isValid())
			opv4a_cec088->unknown898910(this,HProp(),0);
		return true;
	case 0x119:
		if (item.isValid())
			opv4a_cec11c->unknown8b4500(HEntity(),item,HEntity(),&Pos(-1),0,false);
		else
			opv4a_cec090->open(this,0,HProp(),false);
		return true;
	case 0x11a:
		if (item.isValid() && tickCount >= opv4a_cefc80)
			opv4a_cec088->setTimed4a9c30(item);
		return true;
	case 0x11b:
		opv4a_cec090->open(this,0,HProp(),false);
		return true;
	default:
		return false;
	}
}

void CPart::unknown890710(bool flag)
{
	if (unknown70)
	{
		animate("A_CPart_Multislot");
		setFore_417f80(1,0,*opv4a_cfd448);
		setFore_417f80(0,0,*opv4a_cfd448);
	}
	else if (item.isValid())
	{
		unknown88 = false;
		int expiry = item->unknown44ab90();
		if (item->getEffect(0x52))
		{
			animate("A_CPart_GolemBuilding");
			setFore_417f80(1,0,*opv4a_d2b284);
			setFore_417f80(0,0,*opv4a_cfd448);
		}
		else if (item->unknown457d30() || item->unknown415ee0())
		{
			animate("A_CPart_Broken");
			setFore_417f80(1,0,*opv4a_d204ac);
			setFore_417f80(0,0,*opv4a_d30424);
			unknown78 = false;
		}
		else if (item->unknown457d50())
		{
			animate("A_CPart_Disabled");
			setFore_417f80(1,0,*opv4a_cf27e8);
			setFore_417f80(0,0,*opv4a_d323c4);
			unknown78 = false;
		}
		else if (expiry > opv4a_map->getTurn())
		{
			animate("A_CPart_Disabled");
			setFore_417f80(1,0,*opv4a_cf27e8);
			setFore_417f80(0,0,*opv4a_d323c4);
			unknown88 = true;
			unknown78 = false;
		}
		else if (item->unknown457cf0())
		{
			if (item->unknown458220())
			{
				animate("A_CPart_Overload");
				setFore_417f80(1,0,*opv4a_d20438);
				setFore_417f80(0,0,*opv4a_d1d46c);
			}
			else
			{
				animate("A_CPart_Active");
				setFore_417f80(1,0,*opv4a_d2981c);
				setFore_417f80(0,0,*opv4a_cf44c0);
			}
		}
		else
		{
			animate("A_CPart_Inactive");
			setFore_417f80(1,0,*opv4a_cfc174);
			setFore_417f80(0,0,*opv4a_d22fcc);
			unknown78 = false;
		}
	}
	else
	{
		animate("A_CPart_EmptySlot");
		setFore_417f80(1,0,*opv4a_d22fcc);
		setFore_417f80(0,0,*opv4a_d316f4);
	}
	if (unknown94 && flag && opv4a_b8f734[opv4a_d28d68])
		unknown94->unknown88bab0(false);
}

//==================================================================
// CParts
//==================================================================

class CTactical : public Console
{
public:
	CTactical(XConsole *parent, int type_);	// 0x4a9880
	virtual ~CTactical();

	int type;	// NOTE: placeholder name
};

class CParts : public Console
{
public:
	CParts(XConsole *parent, const Rect &rect);	// 0x893c70
	virtual ~CParts();

	bool unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	vector<unsigned int> unknown74;	// NOTE: placeholder name
	CPartsButtons *unknown84;	// NOTE: placeholder name
	int unknown88;	// NOTE: placeholder name
	int unknown8c;	// NOTE: placeholder name
	int unknown90;	// NOTE: placeholder name
	vector<unsigned int> unknown94;	// NOTE: placeholder name
	int unknownA4;	// NOTE: placeholder name
	int unknownA8;	// NOTE: placeholder name
	int unknownAc;	// NOTE: placeholder name
	HProp unknownB0;	// NOTE: placeholder name
	HProp unknownB4;	// NOTE: placeholder name
	int unknownB8;	// NOTE: placeholder name
	int unknownBc;	// NOTE: placeholder name
	bool unknownC0;	// NOTE: placeholder name
	int unknownC4;	// NOTE: placeholder name
	int unknownC8;	// NOTE: placeholder name
	bool unknownCc;	// NOTE: placeholder name
	int unknownD0;	// NOTE: placeholder name
	vector<unsigned int> unknownD4;	// NOTE: placeholder name
	int unknownE4;	// NOTE: placeholder name
	vector<unsigned int> unknownE8;	// NOTE: placeholder name
	int unknownF8;	// NOTE: placeholder name
	int unknownFc;	// NOTE: placeholder name
	HProp unknown100;	// NOTE: placeholder name
	int unknown104;	// NOTE: placeholder name
	vector<unsigned int> unknown108;	// NOTE: placeholder name
	vector<unsigned int> unknown118;	// NOTE: placeholder name
	vector<unsigned int> unknown128;	// NOTE: placeholder name
	bool unknown138;	// NOTE: placeholder name
	HProp unknown13c;	// NOTE: placeholder name
	string unknown140;	// NOTE: placeholder name
	int unknown15c;	// NOTE: placeholder name
	HProp unknown160;	// NOTE: placeholder name
	int unknown164;	// NOTE: placeholder name
	HProp unknown168;	// NOTE: placeholder name
	int unknown16c;	// NOTE: placeholder name
	HProp unknown170;	// NOTE: placeholder name
	int unknown174;	// NOTE: placeholder name
	HProp unknown178;	// NOTE: placeholder name
	int unknown17c;	// NOTE: placeholder name
	HProp unknown180;	// NOTE: placeholder name
	int unknown184;	// NOTE: placeholder name
	HProp unknown188;	// NOTE: placeholder name
	int unknown18c;	// NOTE: placeholder name
	HProp unknown190;	// NOTE: placeholder name
	int unknown194;	// NOTE: placeholder name
	int unknown198;	// NOTE: placeholder name
	int unknown19c;	// NOTE: placeholder name
	string unknown1a0;	// NOTE: placeholder name
	int unknown1bc;	// NOTE: placeholder name
	Pos unknown1c0;	// NOTE: placeholder name
};

CParts::CParts(XConsole *parent, const Rect &rect)
	: Console(parent,rect,0,false,3)
	, unknown88	(0)
	, unknown8c	(0)
	, unknown90	(0)
	, unknownA4	(0)
	, unknownA8	(0)
	, unknownAc	(0x20)
	, unknownB8	(0)
	, unknownBc	(0)
	, unknownC0	(false)
	, unknownC4	(-1)
	, unknownC8	(-1)
	, unknownCc	(false)
	, unknownD0	(0)
	, unknownE4	(0)
	, unknownF8	(0)
	, unknownFc	(0)
	, unknown104	(0)
	, unknown138	(false)
	, unknown15c	(0)
	, unknown164	(0)
	, unknown16c	(0)
	, unknown174	(0)
	, unknown17c	(0)
	, unknown184	(0)
	, unknown18c	(0)
	, unknown194	(0)
	, unknown198	(0)
	, unknown19c	(0)
	, unknown1bc	(0)
	, unknown1c0	(-1)
{
	setTitle(new ConsoleTitle(this,"/ P A R T S /",0,4));
	unknown6c = false;
	new CTactical(this,0);
	new CTactical(this,1);
	new CTactical(this,2);
	unknown84 = new CPartsButtons(this);
	unknown84->refreshRows();
}

//==================================================================
// CShellButton
//==================================================================

extern bool opv4a_cefa5f;	// NOTE: placeholder name (console input blocked)

struct OpV4a_ShellRecord	// NOTE: placeholder name
{
	int ID;
};

class OpV4a_Selection	// NOTE: placeholder name (object at 0xcec0f8)
{
public:
	HProp getItem_4b1460();	// NOTE: placeholder name
};
extern OpV4a_Selection *opv4a_cec0f8;	// NOTE: placeholder name

class OpV4a_Selection2	// NOTE: placeholder name (object at 0xcec0fc)
{
public:
	bool testField_4afe50();	// NOTE: placeholder name
};
extern OpV4a_Selection2 *opv4a_cec0fc;	// NOTE: placeholder name

class OpV4a_Shell : public XConsole	// NOTE: placeholder name (CShell at 0xcec100)
{
public:
	bool unknown91ca50(HProp item, int a, int b, int c, int d, int e, HProp f);	// NOTE: placeholder name
	void unknown9397c0(OpV4a_ShellRecord *record);	// NOTE: placeholder name
};
extern OpV4a_Shell *opv4a_cec100;	// NOTE: placeholder name

class CShellButton : public Console
{
public:
	virtual ~CShellButton();
	virtual bool input(void *event);	// 0x90b200
	void unknown90b2e0();	// NOTE: placeholder name

	OpV4a_ShellRecord *unknown6c;	// NOTE: placeholder name
	bool unknown70;	// NOTE: placeholder name
};

bool CShellButton::input(void *event)
{
	if (isHidden() || opv4a_cefa5f)
		return false;
	if (inputBase_429d00(event))
		return true;
	switch (((XEvent *)event)->type)
	{
	case 0xf6:
		if (!unknown70 && !opv4a_cec0fc->testField_4afe50() && opv4a_cec100->unknown91ca50(opv4a_cec0f8->getItem_4b1460(),0,0,unknown6c->ID,0,0,HProp()))
			opv4a_cec100->unknown9397c0(unknown6c);
		return true;
	default:
		return false;
	}
}

//==================================================================
// CShellText
//==================================================================

class CShellText : public Console
{
public:
	virtual ~CShellText();
	virtual void update();	// 0x90b6f0
	virtual void trigger(const string &command, int value);	// 0x90b760

	void unknown90b850(bool flag);	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
	vector<CShellButton*> buttons;	// NOTE: placeholder name
};

CShellButton *opv4a_randomButton(vector<CShellButton*> &v);	// NOTE: placeholder name (0x9d5d00)

void CShellText::update()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
		case 0:
			break;
		case 1:
			if (!engine->isRunning())
				unknown60 = 3;
			break;
		case 3:
			engine->isRunning();
			break;
	}
	updateBase429e30();
}

void CShellText::unknown90b850(bool flag)
{
	switch (unknown6c)
	{
		case 0:
			animate(flag ? (opv4a_cec0f8->getItem_4b1460()->getData()->unknownF8 == 6 ? "A_CShellText_Command_Der" : "A_CShellText_Command") : "A_CShellText_CommandMulti");
			break;
		case 1:
			animate(flag ? "A_CShellText_Text" : "A_CShellText_TextMulti");
			break;
		case 2:
			animate(flag ? "A_CShellText_Failure" : "A_CShellText_FailureMulti");
			break;
		case 3:
			animate(flag ? "A_CShellText_Notice" : "A_CShellText_NoticeMulti");
			break;
		case 4:
			animate("A_CShellText_Meta");
			break;
		case 5:
			animate(flag ? "A_CShellText_Cypher" : "A_CShellText_CypherMulti");
			break;
		case 6:
			animate(flag ? "A_CShellText_Crash" : "A_CShellText_CrashMulti");
			break;
		case 7:
			animate(flag ? "A_CShellText_Red" : "A_CShellText_RedMulti");
			break;
		case 8:
			animate(flag ? "A_CShellText_Xom" : "A_CShellText_XomMulti");
			break;
	}
}

void CShellText::trigger(const string &command, int value)
{
	if (command == "button")
	{
		vector<CShellButton*> hidden;
		for (unsigned int i = 0; i < buttons.size(); i++)
		{
			if (buttons[i]->isHidden())
				hidden.push_back(buttons[i]);
		}
		if (!hidden.empty())
			opv4a_randomButton(hidden)->unknown90b2e0();
	}
}

//==================================================================
// CShell
//==================================================================

extern "C" unsigned int __cdecl SDL_GetTicks(void);

class OpV4a_ScreenShake	// NOTE: placeholder name (0xd16188)
{
public:
	void start(int duration);	// NOTE: placeholder name
};
extern OpV4a_ScreenShake opv4a_screenShake;	// NOTE: placeholder name

class OpV4a_Selection3	// NOTE: placeholder name (object at 0xcec0f8)
{
public:
	virtual void virtual0();	// NOTE: placeholder name
	virtual void virtual1();	// NOTE: placeholder name
	virtual void virtual2();	// NOTE: placeholder name
	virtual void virtual3();	// NOTE: placeholder name
	virtual void virtual4();	// NOTE: placeholder name
	virtual void virtual5();	// NOTE: placeholder name
	virtual void virtual6();	// NOTE: placeholder name
	virtual void virtual7();	// NOTE: placeholder name
	virtual void virtual8();	// NOTE: placeholder name
	virtual void unknown();	// NOTE: placeholder name (vtable slot 9)
};
extern OpV4a_Selection3 *opv4a_cec0f8_virtual;	// NOTE: placeholder name

struct OpV4a_Alert	// NOTE: placeholder name
{
	char pad00[0x28];
	int unknown28;	// NOTE: placeholder name
};
extern vector<OpV4a_Alert*> opv4a_d35870;	// NOTE: placeholder name

class OpV4a_Audio	// NOTE: placeholder name (0xcefa90)
{
public:
	void unknown41a210(int index);	// NOTE: placeholder name
};
extern OpV4a_Audio *opv4a_audio;	// NOTE: placeholder name
extern bool opv4a_d28cbc;	// NOTE: placeholder name

extern int opv4a_d316b4;	// NOTE: placeholder name
extern int opv4a_d316b8;	// NOTE: placeholder name
extern int opv4a_d316bc;	// NOTE: placeholder name
extern int opv4a_d316c0;	// NOTE: placeholder name
extern XConsole *opv4a_cec0fc_console;	// NOTE: placeholder name (0xcec0fc)

class CShell : public Console
{
public:
	CShell(XConsole *parent, HProp prop_);	// 0x90bac0
	virtual ~CShell();
	virtual void open();	// 0x90bc90
	virtual void close();	// 0x90c690
	virtual void update();	// 0x90c3a0
	void unknown90c700();	// NOTE: placeholder name

	unsigned int unknown6c;	// NOTE: placeholder name
	HProp prop;	// NOTE: placeholder name
	vector<CShellText*> unknown74;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	char pad88[0x8c - 0x88];
	vector<CShellText*> unknown8c;	// NOTE: placeholder name
	unsigned int unknown9c;	// NOTE: placeholder name
	char pada0[0xa8 - 0xa0];
	vector<unsigned int> unknownA8;	// NOTE: placeholder name
	vector<unsigned int> unknownB8;	// NOTE: placeholder name
	vector<unsigned int> unknownC8;	// NOTE: placeholder name
	char padD8[0xdc - 0xd8];
	vector<unsigned int> unknownDc;	// NOTE: placeholder name
	char padEc[0xf4 - 0xec];
	vector<unsigned int> unknownF4;	// NOTE: placeholder name
	vector<unsigned int> unknown104;	// NOTE: placeholder name
	vector<unsigned int> unknown114;	// NOTE: placeholder name
	int unknown124;	// NOTE: placeholder name
};

CShell::CShell(XConsole *parent, HProp prop_)
	: Console(parent,Rect(opv4a_d316b4,opv4a_cec0fc_console->getHeight() + opv4a_d316b8,opv4a_d316bc,opv4a_d316c0 - opv4a_cec0fc_console->getHeight()),0,false,0xf)
	, prop	(prop_)
{
	setTitle(new ConsoleTitle(this,"/ R E S U L T S /",0,0));
	opv4a_cec100 = (OpV4a_Shell *)this;
	open();
}

void CShell::close()
{
	unknown60 = 4;
	clearInterior();
	unknown429f10(0,0);
	engine->stopAll();
	deleteSubconsoles();
	unknown6c = tickCount;
	animate("A_BlockFadeVisSilent");
}

void CShell::update()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
		case 0:
			break;
		case 1:
			break;
		case 3:
			engine->isRunning();
			if (unknown124)
			{
				if (tickCount >= unknown124 + 2000)
				{
					opv4a_cec0f8_virtual->unknown();
					return;
				}
				else
					opv4a_screenShake.start(0x14);
			}
			if (!unknown8c.empty() && SDL_GetTicks() >= unknown9c + 60)
			{
				unknown8c.front()->unknown90b850(false);
				unknown8c.erase(unknown8c.begin());
				unknown9c = SDL_GetTicks();
			}
			if (unknown8c.empty() && opv4a_d35870[0xe]->unknown28 > 0)
			{
				for (int i = unknown84; i < unknown74.size() && i <= unknown84 + getHeight() - 3; i++)
				{
					if (unknown74[i])
					{
						if (unknown74[i]->engine->unknown454d30())
							goto done;
					}
				}
				if (!opv4a_d28cbc)
				{
					opv4a_audio->unknown41a210(0xe);
					opv4a_d35870[0xe]->unknown28 = 0;
				}
			}
done:
			break;
		case 4:
			engine->isRunning();
			if (getScaleX() != 0)
			{
				if (tickCount - unknown6c >= 500)
				{
					setScaleX(0);
					setScaleY(0);
				}
				else
				{
					setScaleX((float)(1 - (tickCount - unknown6c) / 500.0));
					setScaleY((float)(1 - (tickCount - unknown6c) / 500.0));
					break;
				}
			}
			engine->stopAll();
			unknown60 = 0;
			setHidden(true);
			unknown90c700();
			return;
	}
	updateBase429e30();
}

//==================================================================
// effects
//==================================================================

class CEffect : public Console
{
public:
	CEffect(XConsole *parent, const Rect &rect, int type_);	// 0x4b2b90
	virtual ~CEffect();

	int type;	// NOTE: placeholder name
};

struct OpV4a_EffectRec	// NOTE: placeholder name
{
	char pad00[0xf0];
	vector<Pos> unknownF0;	// NOTE: placeholder name
};

class OpV4a_Rex	// NOTE: placeholder name (0xd223f0)
{
public:
	int unknown418980();	// NOTE: placeholder name
	int unknown4189a0();	// NOTE: placeholder name
	XConsole *unknown4ab670();	// NOTE: placeholder name (folded getter at +0x6c)
};
extern OpV4a_Rex opv4a_rex;	// NOTE: placeholder name

class OpV4a_EffectMgr	// NOTE: placeholder name
{
public:
	void unknown966c10(int a, int amount);	// NOTE: placeholder name
};

bool opv4a_lookup1(const string &name, OpV4a_EffectRec **rec);	// NOTE: placeholder name (0x9d7980)
extern XConsole *opv4a_cec074;	// NOTE: placeholder name
extern XConsole *opv4a_cec138;	// NOTE: placeholder name

void OpV4a_EffectMgr::unknown966c10(int a, int amount)
{
	OpV4a_EffectRec *data;
	if (!opv4a_lookup1("A_CEffect_Charging",&data))
		return;
	data->unknownF0.front().y = amount;
	CEffect *effect = new CEffect(opv4a_cec138,Rect(opv4a_cec074->getPos().x,opv4a_cec074->getPos().y,opv4a_cec074->getWidth(),opv4a_rex.unknown4189a0()),5);
	opv4a_rex.unknown4ab670()->unknown429fe0(effect,Pos(0,0),Rect(opv4a_rex.unknown418980() - opv4a_cec074->getWidth(),0,opv4a_cec074->getWidth(),opv4a_rex.unknown4189a0()));
	effect->unknown48c3c0((int)data);
	effect->replaceSpecialChars(0x23);
}
