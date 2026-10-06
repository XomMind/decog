// op_q4a: HUD/scan/evasion/volley consoles (0x87b000-0x890000), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);	// 0x46ca20
	Pos(int v);	// 0x409990
	Pos();	// 0x453b40
	Pos(const Pos &pos);
	Pos(const Pos &pos, int dx, int dy);	// 0x4099c0
	bool operator==(const Pos &pos) const;	// 0x409b90
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();	// 0x40a6e0
	Rect(int x_, int y_, int width_, int height_);	// 0x456940
	Rect(const Rect &rect);
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Pos mouse;
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int modifier);	// NOTE: placeholder name
	virtual void update();
	virtual void render();

	bool isHidden();
	void setHidden(bool hidden);
	int getWidth();
	int getHeight();
	void clear();
	void clearInterior();
	void setScaleX(float value);
	void setFore(XColor color);
	void setBackRow(int x, int y, int width, XColor color);
	void printAligned(int x, int y, int align, const string &text);	// NOTE: placeholder name
	void setScaleY(float value);
	void removeSubconsole(XConsole *console);
	void setBackAll_418410(XColor color);
	Pos getPos();
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)
	void render429ea0();	// NOTE: placeholder name (XConsole::render body)
	void setForeAll_4183d0(XColor color);	// NOTE: placeholder name
	void getRect4286b0(Rect &rect);	// NOTE: placeholder name
	float getScaleX();

	char pad04[0x60 - 0x04];
};

class OpQ4a_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class OpQ4a_Engine	// NOTE: placeholder name (Engine)
{
public:
	OpQ4a_EngineItem *unknown50fb50(OpQ4a_Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
	bool update();	// NOTE: placeholder name (0x50fff0)
	void render();	// NOTE: placeholder name (0x5100b0)
	bool unknown454d30();	// NOTE: placeholder name
	void stopAll();	// NOTE: placeholder name (0x50ff30)
};

class ConsoleTitle;

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);	// NOTE: placeholder name
	void animate(string name);
	void setTitle(class ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)

	int unknown60;
	OpQ4a_Engine *engine;
	ConsoleTitle *title;
};

class OpQ4a_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	bool unknown71bbd0();	// NOTE: placeholder name
};
extern OpQ4a_World *opq4a_world;	// NOTE: placeholder name

class OpQ4a_Rex	// NOTE: placeholder name (REX at 0xd223f0)
{
public:
	int unknown4189a0();	// NOTE: placeholder name
};
extern OpQ4a_Rex opq4a_rex;	// NOTE: placeholder name

//==================================================================
// handles
//==================================================================

class OpQ4a_Entity;

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity() throw();	// 0x9b6590
	OpQ4a_Entity *operator->() const;	// 0x9b6570
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp() throw();	// 0x9b6590
	void reset();	// NOTE: placeholder name (0x9b7270)
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	HItem() throw();	// 0x9b6590
};

//==================================================================
// HUD
//==================================================================

extern OpQ4a_Rex opq4a_rex;
extern int opq4a_d33be4;	// NOTE: placeholder name
extern int opq4a_d33be8;	// NOTE: placeholder name
extern int opq4a_d33bec;	// NOTE: placeholder name
extern Rect opq4a_d38464;	// NOTE: placeholder name
extern XColor opq4a_d29804;	// NOTE: placeholder name
extern int opq4a_d3846c;	// NOTE: placeholder name
extern int opq4a_cf462c;	// NOTE: placeholder name
extern bool opq4a_d28c8a;	// NOTE: placeholder name
extern vector<int> opq4a_cf4a14;	// NOTE: placeholder name
extern string opq4a_hudCommands[];	// NOTE: placeholder name (0xd1d4d8)
extern int opq4a_hudRects[][3];	// NOTE: placeholder name (0xbcc1c0)
extern int opq4a_cebd5c;	// NOTE: placeholder name
extern class OpQ4a_Parts *opq4a_parts;	// NOTE: placeholder name (0xcec088)

class OpQ4a_Parts : public Console	// NOTE: placeholder name (CParts at 0xcec088)
{
};

class CHudRif : public Console
{
public:
	CHudRif(XConsole *parent);	// 0x4a21c0
	virtual bool input(XEvent *event);	// 0x87b270

	int count;	// NOTE: placeholder name
};

bool CHudRif::input(XEvent *event)
{
	if (opq4a_world->unknown71bbd0())
		return false;
	switch (event->type)
	{
	case 0x117:
		opq4a_parts->input(&XEvent(0x120));
		break;
		return true;
	}
	return false;
}

extern XColor *opq4a_d3579c;	// NOTE: placeholder name
extern XColor *opq4a_cf63b0;	// NOTE: placeholder name
extern XColor *opq4a_d204ac;	// NOTE: placeholder name
extern XColor *opq4a_d2981c;	// NOTE: placeholder name
extern XColor *opq4a_cf27e8;	// NOTE: placeholder name
extern XColor *opq4a_d20438;	// NOTE: placeholder name

XColor opq4a_getSpeedLabel(int speed, string &label)	// NOTE: placeholder name (0x87bc20)
{
	if (speed <= 25)
	{
		label = " FASTx3 ";
		return *opq4a_d3579c;
	}
	else if (speed <= 50)
	{
		label = " FASTx2 ";
		return *opq4a_cf63b0;
	}
	else if (speed <= 80)
	{
		label = " FAST ";
		return *opq4a_d2981c;
	}
	else if (speed >= 335)
	{
		label = " SLOWx3 ";
		return *opq4a_d204ac;
	}
	else if (speed >= 235)
	{
		label = " SLOWx2 ";
		return *opq4a_cf27e8;
	}
	else if (speed >= 135)
	{
		label = " SLOW ";
		return *opq4a_d20438;
	}
	else
		return opq4a_d29804;
}

class OpQ4a_Meter	// NOTE: placeholder name (C026_Meter)
{
public:
	float getRatio(bool zeroIfEmpty);	// 0x453b70

	int cur;
	int max;
};

bool opq4a_findAnimation(const string &name, int *index);	// NOTE: placeholder name (0x9d45a0)
string intToString(int value);
extern Pos opq4a_cfbec0;	// NOTE: placeholder name
extern vector<XColor> opq4a_d2b4bc;	// NOTE: placeholder name
extern XColor *opq4a_d204ac;	// NOTE: placeholder name
extern XColor *opq4a_d338bc;	// NOTE: placeholder name
extern XColor *opq4a_d161d4;	// NOTE: placeholder name
extern XColor *opq4a_cfe674;	// NOTE: placeholder name
extern int opq4a_bcc244[][2];	// NOTE: placeholder name
extern int opq4a_bcc248[][2];	// NOTE: placeholder name
class OpQ4a_MapView;

class CHudData : public Console
{
public:
	CHudData(XConsole *parent, const Rect &rect, int type);	// 0x4a2480
	virtual void render();	// 0x882b90
	void drawContent(int value);	// 0x87bd50
	void drawBar(bool animated, string label, OpQ4a_Meter *meter, XColor color);	// NOTE: placeholder name (0x87b300)

	int type;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
};

void CHudData::render()
{
	if (isHidden())
		return;
	if (unknown60 == 3)
		drawContent(0);
	engine->render();
	render429ea0();
}

class CHud : public Console
{
public:
	CHud(XConsole *parent);	// 0x882be0
	virtual ~CHud();	// defined in op_w6
	virtual void open();	// 0x882d20
	virtual void update();	// 0x882da0
	virtual void trigger(const string &command, int value);	// 0x882ec0

	int unknown6c;	// NOTE: placeholder name
	CHudRif *rif;	// NOTE: placeholder name
};

CHud::CHud(XConsole *parent)
	: Console(parent,opq4a_d38464,0,true,3)
	, unknown6c	(0)
	, rif		(NULL)
{
	if (opq4a_rex.unknown4189a0() > opq4a_d33be4 + opq4a_d33bec - 1)
	{
		Console *console = new Console(this,opq4a_d33be8,opq4a_rex.unknown4189a0() - (opq4a_d33be4 + opq4a_d33bec - 1),0,opq4a_d33be4 + opq4a_d33bec,0,false,-1);
		console->setBackAll_418410(opq4a_d29804);
	}
}

void CHud::open()
{
	unknown60 = 3;
	setHidden(false);
	animate("CHud_Content");
}

void CHud::update()
{
	if (isHidden())
		return;
	engine->update();
	if (opq4a_cf4a14.empty())
	{
		if (rif && rif)
		{
			removeSubconsole(rif);
			rif = NULL;
		}
	}
	else if (rif == NULL && !engine->unknown454d30())
		rif = new CHudRif(this);
	if (rif)
		rif->setHidden(opq4a_d28c8a);
	updateBase429e30();
}

void CHud::trigger(const string &command, int value)
{
	for (int i = 0; i < 11; i++)
	{
		if (command == opq4a_hudCommands[i])
		{
			if (i == 6 && opq4a_cf462c != 4)
				return;
			int x = (i == 8 || i == 9) ? opq4a_d3846c/2 : 0;
			int w = i >= 7 ? opq4a_d3846c/2 : opq4a_d3846c;
			CHudData *data = new CHudData(this,Rect(x,opq4a_hudRects[i][opq4a_cebd5c],w,1),i);
			data->open();
			return;
		}
	}
}

//==================================================================
// CScan
//==================================================================

class OpQ4a_MapView : public XConsole	// NOTE: placeholder name (MapView at 0xcec054)
{
public:
	bool unknown49b0c0(int id);	// NOTE: placeholder name
	void unknown49b5b0();	// NOTE: placeholder name
	void unknown8142d0(int a, int b);	// NOTE: placeholder name
	void unknown813c80(int a);	// NOTE: placeholder name
	void unknown819e00(int a, int b);	// NOTE: placeholder name
	bool unknown805190(Pos *p);	// NOTE: placeholder name
};
extern OpQ4a_MapView *opq4a_mapView;	// NOTE: placeholder name (0xcec054)


void CHudData::drawBar(bool animated, string label, OpQ4a_Meter *meter, XColor color)
{
	if (animated)
	{
		int filled = (int)(meter->getRatio(true)*getWidth());
		int animIndex;
		if (filled != 0)
		{
			if (filled == 1)
			{
				if (opq4a_findAnimation("CHudData_Bar_" + label + "_Fill",&animIndex))
				{
					do
					{
						engine->unknown50fb50(engine,animIndex,&Pos(0,0),&opq4a_cfbec0,NULL,NULL,9)->unknown50de10();
					} while (false);
				}
			}
			else
			{
				if (opq4a_findAnimation("CHudData_Bar_" + label + "_E",&animIndex))
				{
					do
					{
						engine->unknown50fb50(engine,animIndex,&Pos(0,0),&opq4a_cfbec0,&Pos(filled - 1,0),&opq4a_cfbec0,9)->unknown50de10();
					} while (false);
				}
			}
		}
		unknown70 = filled;
	}
	else
	{
		int filled = (int)(meter->getRatio(true)*getWidth());
		setBackRow(0,0,filled,color);
		if (filled < unknown70)
		{
			int animIndexA;
			if (opq4a_findAnimation("CHudData_Bar_" + label + "_Delta-",&animIndexA))
			{
				do
				{
					for (int x = Pos(filled,0).x; x < Pos(filled,0).x + unknown70 - filled; x++)
						engine->unknown50fb50(engine,animIndexA,&Pos(x,Pos(filled,0).y),&opq4a_cfbec0,NULL,NULL,9)->unknown50de10();
				} while (false);
			}
		}
		else if (filled > unknown70)
		{
			int animIndexB;
			if (opq4a_findAnimation("CHudData_Bar_" + label + "_Delta+",&animIndexB))
			{
				do
				{
					for (int x = Pos(unknown70,0).x; x < Pos(unknown70,0).x + filled - unknown70; x++)
						engine->unknown50fb50(engine,animIndexB,&Pos(x,Pos(unknown70,0).y),&opq4a_cfbec0,NULL,NULL,9)->unknown50de10();
				} while (false);
			}
		}
		unknown70 = filled;
		int percent = meter->max == 0 ? 0 : meter->cur*100/meter->max;
		if (percent <= opq4a_bcc244[type][0] && (type != 2 || meter->max != 0))
		{
			bool critical = percent <= 25;
			setFore(*opq4a_cfe674);
			opq4a_d2b4bc[0] = (percent <= opq4a_bcc248[type][0] ? *opq4a_d204ac : *opq4a_d338bc);
			printAligned(getWidth() - 3,0,2,"`b" + intToString(0) + "`" + (critical ? " Alert " : " Warning ") + "`x`");
			setFore(*opq4a_d161d4);
			if (type < 3)
				opq4a_mapView->unknown819e00(type,(critical != 0) + 1);
		}
		else if (type < 3)
			opq4a_mapView->unknown819e00(type,0);
	}
}

class CScanButton : public Console
{
public:
	CScanButton(XConsole *parent, int x, int y, int type);	// 0x4a25c0
	virtual bool input(XEvent *event);	// 0x883ee0

	int type;	// NOTE: placeholder name
};

bool CScanButton::input(XEvent *event)
{
	if (opq4a_world->unknown71bbd0())
		return false;
	switch (event->type)
	{
	case 0x127:
		int id = type - 0x88;
		if (opq4a_mapView->unknown49b0c0(id))
		{
			opq4a_mapView->unknown8142d0(id,1);
			if (id == 6)
				opq4a_mapView->unknown49b5b0();
		}
		else
			opq4a_mapView->unknown813c80(type);
		return true;
	}
	return false;
}

class CScanButtons : public Console
{
public:
	CScanButtons(XConsole *parent);	// 0x883f80

	vector<XConsole*> buttons;	// NOTE: placeholder name
};

CScanButtons::CScanButtons(XConsole *parent)
	: Console(parent,parent->getWidth() - 2,parent->getHeight() - 2,1,1,0,true,-1)
{
	buttons.push_back(new CScanButton(this,1,0,0x8c));
	buttons.push_back(new CScanButton(this,1,1,0x8d));
	buttons.push_back(new CScanButton(this,0x10,0,0x8e));
	buttons.push_back(new CScanButton(this,0x10,1,0x8f));
}

extern Rect opq4a_cfb78c;	// NOTE: placeholder name

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);
	char pad6c[0x8c - 0x6c];
};

class OpQ4a_EntityEffect;	// NOTE: placeholder name

class OpQ4a_Entity	// NOTE: placeholder name (Entity)
{
public:
	OpQ4a_EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	int unknown5ca840();	// NOTE: placeholder name
};

class OpQ4a_Cell	// NOTE: placeholder name (Cell)
{
public:
	bool unknown4550b0();	// NOTE: placeholder name (folded getter)
};

class OpQ4a_Cells	// NOTE: placeholder name (0xcfd44c)
{
public:
	OpQ4a_Cell *&operator()(const Pos &p);	// 0x9ced70
};
extern OpQ4a_Cells opq4a_cells;	// NOTE: placeholder name
extern unsigned int opq4a_tickCount;	// NOTE: placeholder name (0xcaed20)
extern bool opq4a_d28d16;	// NOTE: placeholder name (option)

class CScanText;

class CScan : public Console
{
public:
	CScan(XConsole *parent);	// 0x884200
	virtual ~CScan();	// 0x4a2b10
	virtual void update();	// 0x884460
	virtual void open();	// 0x8843e0
	virtual void close();	// 0x884cc0
	bool unknown884d00();	// NOTE: placeholder name
	void unknown887540();	// NOTE: placeholder name
	int unknown884da0(HEntity entity);	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	CScanText *unknown74;	// NOTE: placeholder name
	CScanText *unknown78;	// NOTE: placeholder name
	CScanButtons *buttons;	// NOTE: placeholder name
	Pos unknown80;	// NOTE: placeholder name
	HProp unknown88;	// NOTE: placeholder name
	HProp unknown8c;	// NOTE: placeholder name
	int unknown90;	// NOTE: placeholder name
	int unknown94;	// NOTE: placeholder name
	int unknown98;	// NOTE: placeholder name
	int unknown9c;	// NOTE: placeholder name
	HProp unknownA0;	// NOTE: placeholder name
	int unknownA4;	// NOTE: placeholder name
	Pos unknownA8;	// NOTE: placeholder name
	int unknownB0;	// NOTE: placeholder name
	bool unknownB4;	// NOTE: placeholder name
};

CScan::CScan(XConsole *parent)
	: Console(parent,opq4a_cfb78c,0,true,3)
	, unknown74	(NULL)
	, unknown78	(NULL)
	, buttons	(NULL)
	, unknown80	(-1,-1)
	, unknown90	(-1)
	, unknown94	(6)
	, unknownA4	(-1)
	, unknownA8	(-1)
	, unknownB0	(0)
	, unknownB4	(false)
{
	setTitle(new ConsoleTitle(this,"/ S C A N /",0,4));
	unknown6c = false;
	buttons = new CScanButtons(this);
}

void CScan::open()
{
	unknown60 = 1;
	setHidden(false);
	if (unknown6c)
		clearInterior();
	else
	{
		clear();
		animate("CScan_Border");
		unknown6c = true;
	}
	setScaleX(1.0f);
	setScaleY(1.0f);
}

void CScan::close()
{
	unknown60 = 4;
	unknown70 = opq4a_tickCount;
	animate("A_BlockFadeInterior");
}

bool CScan::unknown884d00()
{
	Pos target;
	if (!opq4a_mapView->unknown805190(&target))
		return false;
	return unknownA8 == target && opq4a_tickCount > unknownB0 + 500 && !opq4a_cells(unknownA8)->unknown4550b0();
}

int CScan::unknown884da0(HEntity entity)
{
	if (!opq4a_d28d16 || entity->unknown45ac40(0x1e))
		return 6;
	int result = entity->unknown5ca840();
	if (result == 0)
		result = 6;
	return result;
}

string opq4a_splitLine(string &text, unsigned int maxWidth)	// NOTE: placeholder name (0x884e00)
{
	if (text.size() <= maxWidth)
		return string();
	int pos = text.size();
	do
	{
		pos = text.rfind(' ',pos);
		if (pos == string::npos)
			pos = maxWidth;
	} while (pos > (int)maxWidth);
	string result(text.begin() + pos + 1,text.end());
	text.erase(text.begin() + pos,text.end());
	return result;
}

//==================================================================
// CScan (continued)
//==================================================================

class CScanText : public Console
{
public:
	CScanText(XConsole *parent, int x, int y, int width, string text, HItem item_, HEntity entity_);	// 0x4a27c0

	HItem item;	// NOTE: placeholder name
	HEntity entity;	// NOTE: placeholder name
};

void opq4a_initScanColors();	// NOTE: placeholder name (0x4a2b60)

extern int opq4a_cfb794;	// NOTE: placeholder name (opq4a_cfb78c.width)
extern XColor *opq4a_cf44c0;	// NOTE: placeholder name

void CScan::unknown887540()
{
	if (unknown74)
	{
		removeSubconsole(unknown74);
		unknown74 = NULL;
	}
	if (unknown78)
	{
		removeSubconsole(unknown78);
		unknown78 = NULL;
	}
	clearInterior();
	unknown80.x = -1;
	unknown88.reset();
	unknown8c.reset();
	unknownA0.reset();
	unknown74 = new CScanText(this,2,1,opq4a_cfb794 - 4,"[1 - Hostile]  [3 - Parts]",HItem(),HEntity());
	unknown74->setForeAll_4183d0(*opq4a_cf44c0);
	unknown78 = new CScanText(this,2,2,opq4a_cfb794 - 4,"[2 - Friendly] [4 - Exits]",HItem(),HEntity());
	unknown78->setForeAll_4183d0(*opq4a_cf44c0);
}

//==================================================================
// CEvasion
//==================================================================

class OpQ4a_Keys	// NOTE: placeholder name (0xd338cc)
{
public:
	bool isDown(int key);	// NOTE: placeholder name (0x439510)
};
extern OpQ4a_Keys opq4a_keys;	// NOTE: placeholder name

class OpQ4a_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	bool isIn(const Rect &rect);	// NOTE: placeholder name (0x41a730)
};
extern OpQ4a_Mouse *opq4a_mouse;	// NOTE: placeholder name

class OpQ4a_Partswap : public Console	// NOTE: placeholder name (CPartswap at 0xcec090)
{
public:
	int unknownGetter();	// NOTE: placeholder name (folded getter)
};
extern OpQ4a_Partswap *opq4a_partswap;	// NOTE: placeholder name

class OpQ4a_ItemTag : public Console	// NOTE: placeholder name (CItemTag at 0xcec0a0)
{
public:
	bool unknown4ab690();	// NOTE: placeholder name (folded getter)
};
extern OpQ4a_ItemTag *opq4a_itemTag;	// NOTE: placeholder name

extern class CEvasionFull *opq4a_cec080;	// NOTE: placeholder name
extern int opq4a_cec100;	// NOTE: placeholder name
extern int opq4a_cec108;	// NOTE: placeholder name
extern string opq4a_d2f2bc;	// NOTE: placeholder name
extern string opq4a_cfb7b8[];	// NOTE: placeholder name
void opq4a_unknown889950();	// NOTE: placeholder name
string &opq4a_padLeft(string &str, unsigned int width, char c);	// NOTE: placeholder name (0x408090)

class CEvasion : public Console
{
public:
	CEvasion(XConsole *parent);	// 0x887750
	virtual ~CEvasion();	// 0x4a2c30
	virtual void update();	// 0x887920
	virtual void render();	// 0x887cc0
	virtual void open();	// 0x8878a0
	virtual void close();	// 0x887b30
	void unknown887b70(unsigned int index, string &text, string &colorName);	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	bool unknown74;	// NOTE: placeholder name
	vector<string> unknown78;	// NOTE: placeholder name
	vector<int> unknown88;	// NOTE: placeholder name
	vector<bool> unknown98;	// NOTE: placeholder name
	int unknownAc;	// NOTE: placeholder name
	string unknownB0;	// NOTE: placeholder name
};

extern Rect opq4a_d35e08;	// NOTE: placeholder name

CEvasion::CEvasion(XConsole *parent)
	: Console(parent,opq4a_d35e08,0,true,0xc)
	, unknown74	(false)
	, unknownAc	(0)
{
	setTitle(new ConsoleTitle(this,"/ E V A S I O N /",0,4));
	unknown6c = false;
	opq4a_initScanColors();
}

void CEvasion::open()
{
	unknown60 = 1;
	setHidden(false);
	if (unknown6c)
		clearInterior();
	else
	{
		clear();
		animate("CEvasion_Border");
		unknown6c = true;
	}
	setScaleX(1.0f);
	setScaleY(1.0f);
}

void CEvasion::update()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
		case 0:
			break;
		case 1:
			if (!engine->update())
				unknown60 = 3;
			break;
		case 3:
			if (unknown6c)
				unknown74 = true;
			engine->update();
			if (opq4a_cec080 == 0 && !unknown78.empty() && opq4a_cec100 == 0 && opq4a_cec108 == 0 && opq4a_partswap->unknownGetter() == 0)
			{
				if (opq4a_keys.isDown(0x5c) && !opq4a_itemTag->unknown4ab690())
					opq4a_unknown889950();
				else
				{
					Rect rect;
					getRect4286b0(rect);
					if (opq4a_mouse->isIn(rect))
						opq4a_unknown889950();
				}
			}
			break;
		case 4:
			engine->update();
			if (getScaleX() != 0)
			{
				if (opq4a_tickCount - unknown70 >= 500)
				{
					setScaleX(0);
					setScaleY(0);
				}
				else
				{
					setScaleX((float)(1 - (opq4a_tickCount - unknown70) / 500.0));
					setScaleY((float)(1 - (opq4a_tickCount - unknown70) / 500.0));
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

void CEvasion::close()
{
	unknown60 = 4;
	unknown70 = opq4a_tickCount;
	animate("A_BlockFadeInterior");
}

void CEvasion::unknown887b70(unsigned int index, string &text, string &colorName)
{
	text = intToString(abs(unknown88[index]));
	opq4a_padLeft(text,2,' ');
	text.insert(0,index == 1 || (index == 2 && unknown88[index] < 0) ? " -" : " +");
	text.insert(0,unknown78[index]);
	colorName = unknown98[index] ? opq4a_d2f2bc : opq4a_cfb7b8[index];
}

//==================================================================
// CEvasionFull
//==================================================================

extern CEvasion *opq4a_cec07c;	// NOTE: placeholder name

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);

	string text;
};

extern Pos opq4a_cfd2c4;	// NOTE: placeholder name

class CEvasionFull : public Console
{
public:
	CEvasionFull(XConsole *parent, const Rect &rect);	// 0x888c80
	virtual ~CEvasionFull();	// defined in op_w6
	virtual void update();	// 0x888dd0
	virtual void open();	// 0x888d70
	virtual void close();	// 0x888e70
	virtual void trigger(const string &command, int value);	// 0x888e90
};

CEvasionFull::CEvasionFull(XConsole *parent, const Rect &rect)
	: Console(parent,rect,0,false,0xe)
{
	setTitle(new ConsoleTitle(this,"/ E V A S I O N /",0,4));
	opq4a_cec080 = this;
	open();
}

void CEvasionFull::open()
{
	unknown60 = 3;
	animate("CEvasionFull_Border");
	animate("CEvasionFull_Content");
}

void CEvasionFull::update()
{
	if (isHidden())
		return;
	engine->update();
	if (opq4a_partswap->unknownGetter())
	{
		close();
		return;
	}
	if (!opq4a_keys.isDown(0x5c))
	{
		Rect rect;
		getRect4286b0(rect);
		if (!opq4a_mouse->isIn(rect))
		{
			close();
			return;
		}
	}
	updateBase429e30();
}

void CEvasionFull::close()
{
	opq4a_cec07c->removeSubconsole(this);
}

void CEvasionFull::trigger(const string &command, int value)
{
	if (command == "start")
	{
		CText *label = new CText(this,Pos(2,2),"Theoretical Avoidance Rate 40%",0,0,-1);
		label->animate("A_BlockAppear_GR3");
		Rect rect(2,9,30,1);
		Console *bar = new Console(this,rect,0,false,-1);
		bar->animate("A_CEvasionFull_Bar");
	}
	else if (command == "movement")
	{
		string amount, color;
		opq4a_cec07c->unknown887b70(0,amount,color);
		CText *text = new CText(this,Pos(opq4a_cfd2c4,-amount.size(),0),amount,0,0,-1);
		text->animate("A_BlockAppear_" + color);
	}
	else if (command == "heat")
	{
		string amount, color;
		opq4a_cec07c->unknown887b70(1,amount,color);
		CText *text = new CText(this,Pos(opq4a_cfd2c4,-amount.size(),1),amount,0,0,-1);
		text->animate("A_BlockAppear_" + color);
	}
	else if (command == "speed")
	{
		string amount, color;
		opq4a_cec07c->unknown887b70(2,amount,color);
		CText *text = new CText(this,Pos(opq4a_cfd2c4,-amount.size(),2),amount,0,0,-1);
		text->animate("A_BlockAppear_" + color);
	}
	else if (command == "evasion")
	{
		string amount, color;
		opq4a_cec07c->unknown887b70(3,amount,color);
		CText *text = new CText(this,Pos(opq4a_cfd2c4,-amount.size(),3),amount,0,0,-1);
		text->animate("A_BlockAppear_" + color);
	}
	else if (command == "phasing")
	{
		string amount, color;
		opq4a_cec07c->unknown887b70(4,amount,color);
		CText *text = new CText(this,Pos(opq4a_cfd2c4,-amount.size(),4),amount,0,0,-1);
		text->animate("A_BlockAppear_" + color);
	}
	else if (command == "total")
	{
		string text = " " + intToString(opq4a_cec07c->unknownAc) + "% ";
		CText *label = new CText(this,Pos(opq4a_cfd2c4,-text.size() + 2,6),text,0,0,-1);
		label->animate("A_BkgText_" + opq4a_cec07c->unknownB0);
		text = "Modified Avoidance";
		label = new CText(this,Pos(label->getPos().x - 1 - text.size(),label->getPos().y),text,0,0,-1);
		label->animate("A_BlockAppear_GR3");
	}
}
