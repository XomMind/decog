// op_x5_e: effect-object (0xcec138) methods and CMainUiButton::update in 0x965c10-0x998590 of
//	COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../engine/xcolor.h"
using namespace std;

class RNG
{
public:
	int rangeInt(float a, float b) throw();	// 0x406d70
};
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

	Rect(int x_, int y_, int width_, int height_);	// 0x456940
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

struct Point;

class XConsole
{
public:
	XConsole(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~XConsole();

	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(XEvent *event) = 0;
	virtual void inputKey(int key, int mode);	// NOTE: placeholder name
	virtual void update() = 0;
	virtual void render() = 0;	// NOTE: placeholder name

	bool isHidden();	// NOTE: placeholder name
	int getWidth();
	int getHeight();
	Pos getPos();
	void setPos(int x, int y);	// NOTE: placeholder name
	void setHidden(bool hidden_) throw();	// NOTE: placeholder name
	void setFgColor(XColor color) throw();	// NOTE: placeholder name (0x4183d0)
	void setBgColor(XColor color);	// NOTE: placeholder name (0x418410)
	void setFore(int x, int y, XColor color);	// NOTE: placeholder name (0x417f80)
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
	void clear();	// NOTE: placeholder name
	void deleteSubconsoles();	// NOTE: placeholder name
	void printAligned(int x, int y, int align, const string &text);	// NOTE: placeholder name
	void clearBack();	// NOTE: placeholder name (0x417cf0)
	void resetBack_418450() throw();	// NOTE: placeholder name
	void updateBase();	// NOTE: placeholder name (0x429e30)
	void renderBase();	// NOTE: placeholder name (0x429ea0)
	void setBack_417fc0(int x, int y, XColor color, int mode);	// NOTE: placeholder name
	void unknown429fe0(XConsole *console, const Point &pos, int flag);	// NOTE: placeholder name
	void copyColorsTo(XConsole *dest, Point &destPos, Rect *rect);	// NOTE: placeholder name (0x42a3c0)
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
	class OpR5g_Engine *engine;
	ConsoleTitle *title;
};

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(int x_, int y_);	// 0x46ca20
	Point(const Point &p);	// 0x46ca50
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity() throw();
	class Entity *operator->() const throw();	// 0x9b6570
};

class Entity	// NOTE: placeholder layout
{
public:
	void die(bool a, int cause, HEntity killer, bool b, int c, int d, int e, int f);	// NOTE: placeholder signature (0x633790)
	int unknown5c8e20(int *count);	// NOTE: placeholder name
	int unknown5ca210();	// NOTE: placeholder name
	const Point &getPosition();	// NOTE: placeholder name (0x45a4a0)
};

struct OpX5E_Area	// NOTE: placeholder name
{
	Point min;
	Point max;
};

template <class T> class OpX5_Array2D	// NOTE: placeholder name (defined in op_x5.cpp)
{
public:
	T *at(int x, int y);
	void init_9cf690(int width_, int height_, int fill);	// NOTE: placeholder name

	int width;
	int height;
	T *cells;
};

struct XCell;
class Cell;
template <class T> class Array2D
{
public:
	int getWidth();
	int getHeight();
};
extern Array2D<XCell> opx5e_cellsX;	// NOTE: placeholder name (0xcfd44c)
extern Array2D<Cell *> opx5e_cells;	// NOTE: placeholder name (0xcfd44c)

class OpR5g_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
	void unknown738b70();	// NOTE: placeholder name
	void unknown777190(int value);	// NOTE: placeholder name
	bool unknown715920();	// NOTE: placeholder name
	bool unknown71bbd0();	// NOTE: placeholder name
	bool isVisible(int x, int y);	// 0x463190
	OpX5_Array2D<int> *unknown463830();	// NOTE: placeholder name
	OpX5E_Area *unknown464610();	// NOTE: placeholder name
	vector<OpX5E_Area> *unknown4646d0();	// NOTE: placeholder name
};
extern OpR5g_World *opr5g_world;	// NOTE: placeholder name (0xcefc4c)
//==================================================================
// CMainUiButton / CFovEnemiesButton
//==================================================================

string &opr5g_padLeft(string &s, int width, char c);	// NOTE: placeholder name (0x408090)
string &opr5g_padRight(string &s, int width, char c);	// NOTE: placeholder name (0x4080d0)
bool opr5g_any(bool *values, unsigned int count);	// NOTE: placeholder name (0x9d5080)
extern bool opr5g_d257d5;	// NOTE: placeholder name
extern bool opr5g_d257d6;	// NOTE: placeholder name
extern bool opr5g_d28d05;	// NOTE: placeholder name
extern bool opr5g_d25718;	// NOTE: placeholder name
extern bool opr5g_d25738;	// NOTE: placeholder name
extern string opr5g_d2571c;	// NOTE: placeholder name
extern XColor *opr5g_cf6b24;	// NOTE: placeholder name
extern XColor *opr5g_cfc174;	// NOTE: placeholder name
extern vector<int> opr5g_d22590;	// NOTE: placeholder name

string intToString(int value);

class OpR5g_Engine	// NOTE: placeholder name
{
public:
	void update();	// NOTE: placeholder name (0x50fff0)
	void killGroup(string group);	// NOTE: placeholder name (0x50fd90)
};

class CMainUiButton : public Console
{
public:
	virtual void update();

	int index;	// NOTE: placeholder name
	int state;	// NOTE: placeholder name
	bool attention[4];	// NOTE: placeholder name
};

void CMainUiButton::update()
{
	switch (index)
	{
	case 0:
		if (opr5g_world != NULL)
		{
			print(0xb,0,opr5g_padLeft(intToString(opr5g_world->getPlayer()->unknown5c8e20(NULL)),2,' '));
			print(0xe,0,opr5g_padRight(intToString(opr5g_world->getPlayer()->unknown5ca210()),2,' '));
		}
		break;
	case 1:
		break;
	case 2:
		switch (state)
		{
		case 0:
			if (!opr5g_d257d5)
				attention[3] = true;
			if (opr5g_d28d05)
			{
				if (!opr5g_d25718)
					attention[0] = true;
				if (!opr5g_d25738 && !opr5g_d2571c.empty())
					attention[1] = true;
			}
			if (opr5g_any(attention,4))
			{
				animate("A_F1_AttentionGlow");
				state = 1;
			}
			else
				state = 2;
			break;
		case 1:
			if (attention[3] && opr5g_d257d5)
				attention[3] = false;
			if (attention[0] && opr5g_d25718)
				attention[0] = false;
			if (attention[1] && opr5g_d25738)
				attention[1] = false;
			if (!opr5g_any(attention,4))
			{
				state = 2;
				engine->killGroup("attnglo");
				setFgColor(*opr5g_cf6b24);
			}
			break;
		}
		break;
	case 4:
		switch (state)
		{
		case 0:
			if (opr5g_d22590[4])
			{
				if (!opr5g_d257d6)
				{
					animate("A_F1_AttentionGlow");
					state = 1;
				}
				else
					state = 2;
			}
			break;
		case 1:
			if (opr5g_d257d6)
			{
				state = 2;
				engine->killGroup("attnglo");
				setFgColor(*opr5g_cf6b24);
			}
			break;
		}
		break;
	case 5:
		if (opr5g_world != NULL)
		{
			setFgColor(opr5g_world->unknown715920() ? *opr5g_cf6b24 : *opr5g_cfc174);
		}
		break;
	}
	engine->update();
}

//==================================================================
// object at 0xcec138 (0x9695b0-0x96bf80)
//==================================================================

class CEffect : public Console
{
public:
	CEffect(XConsole *parent, const Rect &rect, int type_);
	void unknown48c460(int id, const Point &pos);	// NOTE: placeholder name

	int type;	// NOTE: placeholder name
};

class REX	// NOTE: placeholder layout (0xd223f0)
{
public:
	int unknown418980();	// NOTE: placeholder name
	int unknown4189a0();	// NOTE: placeholder name
	XConsole *getConsole_4ab670();	// NOTE: placeholder name (folded getter)
};
extern REX opx5e_rex;	// NOTE: placeholder name

class SoundMgr	// NOTE: partial
{
public:
	void unknown4544e0();	// NOTE: placeholder name
	void unknown5003b0();	// NOTE: placeholder name
};
extern SoundMgr opx5e_soundMgr;	// NOTE: placeholder name (0xd2d2a0)

class OpX5E_Sound	// NOTE: placeholder name (0xcefa90)
{
public:
	void haltAll();	// NOTE: placeholder name (0x419c50)
};
extern OpX5E_Sound *opx5e_sound;	// NOTE: placeholder name (0xcefa90)

class OpW5_Unk49b870	// NOTE: placeholder name
{
public:
	void reset();	// NOTE: placeholder name
};
extern OpW5_Unk49b870 opx5e_d1d9c0;	// NOTE: placeholder name

class OpR5g_Effect	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class OpR5g_EffectMgr	// NOTE: placeholder name
{
public:
	OpR5g_Effect *create();	// NOTE: placeholder name (0x508610)
};
extern OpR5g_EffectMgr *opr5g_effectMgr;	// NOTE: placeholder name (0xcefc50)

class CMap : public Console	// NOTE: partial layout
{
public:
	void unknown8069e0(Point p, bool flag);	// NOTE: placeholder name
	void unknown8051f0(Pos *min, Pos *max);	// NOTE: placeholder name
	const Point &unknown458ef0();	// NOTE: placeholder name (folded getter)
};
extern CMap *opx5e_cec054;	// NOTE: placeholder name

class CInfo : public Console	// NOTE: partial layout
{
public:
	void unknown8b5080();	// NOTE: placeholder name
};
extern CInfo *opx5e_cec118;	// NOTE: placeholder name
extern CInfo *opx5e_cec11c;	// NOTE: placeholder name
extern CInfo *opx5e_cec120;	// NOTE: placeholder name

extern XConsole *opx5e_cec058;	// NOTE: placeholder name
extern XConsole *opx5e_cec074;	// NOTE: placeholder name
extern XConsole *opx5e_cec078;	// NOTE: placeholder name
extern XConsole *opx5e_cec07c;	// NOTE: placeholder name
extern XConsole *opx5e_cec084;	// NOTE: placeholder name
extern XConsole *opx5e_cec088;	// NOTE: placeholder name
extern XConsole *opx5e_cec08c;	// NOTE: placeholder name
extern XConsole *opx5e_cec0b0;	// NOTE: placeholder name
extern XConsole *opx5e_cec0b8;	// NOTE: placeholder name
extern XConsole *opx5e_cec0c0;	// NOTE: placeholder name
extern XConsole *opx5e_cec0c8;	// NOTE: placeholder name
extern XConsole *opx5e_cec0cc;	// NOTE: placeholder name
extern XConsole *opx5e_cec0d0;	// NOTE: placeholder name
extern XConsole *opx5e_cec0d4;	// NOTE: placeholder name
extern XConsole *opx5e_cec0d8;	// NOTE: placeholder name
extern XConsole *opx5e_cec0dc;	// NOTE: placeholder name
extern XConsole *opx5e_cec0e4;	// NOTE: placeholder name
extern XConsole *opx5e_cec0e8;	// NOTE: placeholder name
extern XConsole *opx5e_cec0ec;	// NOTE: placeholder name
extern XConsole *opx5e_cec0f4;	// NOTE: placeholder name
extern int opx5e_cefc90;	// NOTE: placeholder name
extern bool opx5e_d28c8a;	// NOTE: placeholder name
extern int opx5e_cebd5c;	// NOTE: placeholder name
extern unsigned int opx5e_tickCount;	// NOTE: placeholder name (0xcaed20)
extern int opx5e_screenWidth;	// NOTE: placeholder name (0xcf27f4)
extern int opx5e_screenHeight;	// NOTE: placeholder name (0xcf27f8)
extern XColor *opx5e_d20cfc;	// NOTE: placeholder name

int opr5g_playSound(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name (0x4541b0)
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980)
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
int OpW7_getFont(int index);	// NOTE: placeholder name

class OpX5E_Obj : public Console	// NOTE: placeholder name (object at 0xcec138)
{
public:
	void unknown9695b0();	// NOTE: placeholder name
	void unknown96ada0(bool flag);	// NOTE: placeholder name
	void unknown96b0a0(bool flag);	// NOTE: placeholder name
	void unknown96bbb0();	// NOTE: placeholder name

	char pad6c[0x144 - 0x6c];
	int unknown144;
	int unknown148;
	vector<CEffect*> unknown14c;
	char pad15c[0x17c - 0x15c];
	bool unknown17c;
	CEffect *unknown180;
	bool unknown184;
	CEffect *unknown188;
	Console *unknown18c;
	vector<Point> unknown190;
	OpX5_Array2D<int> unknown1a0;
	int unknown1ac;
	int unknown1b0;
	int unknown1b4;
};

void OpX5E_Obj::unknown96ada0(bool flag)
{
	unknown17c = flag;
	opx5e_soundMgr.unknown5003b0();
	opx5e_soundMgr.unknown4544e0();
	opx5e_sound->haltAll();
	unknown180 = new CEffect(this,Rect(0,0,opx5e_rex.unknown418980(),opx5e_rex.unknown4189a0()),0x1b);
	opx5e_rex.getConsole_4ab670()->unknown429fe0(unknown180,Point(0,0),0);
	unknown180->animate("A_CEffect_Singularity");
	opx5e_cec0f4->setHidden(true);
	opx5e_cec0b0->setHidden(true);
	opx5e_cec0d0->setHidden(true);
	opx5e_cec0d4->setHidden(!(opx5e_cefc90 && opx5e_cec0d0->isVisible()));
	opx5e_cec0d8->setHidden(!opx5e_cec0d0->isVisible());
	opx5e_cec0dc->setHidden(!opx5e_cec0d0->isVisible());
	opx5e_cec0e4->setHidden(!(!opx5e_d28c8a && opx5e_cec0d0->isVisible()));
	opx5e_cec0e8->setHidden(!(opx5e_cec0d0->isVisible() && opx5e_cebd5c == 2));
	opx5e_cec0ec->setHidden(!(opx5e_cec0d0->isVisible() && opx5e_cebd5c == 2));
	opx5e_cec0c8->setHidden(true);
	opx5e_cec0cc->setHidden(true);
	opx5e_cec0b8->setHidden(true);
	opx5e_cec0c0->setHidden(true);
	opx5e_cec054->setHidden(true);
	opx5e_cec058->setHidden(true);
	opx5e_cec074->setHidden(true);
	opx5e_cec078->setHidden(true);
	opx5e_cec07c->setHidden(true);
	opx5e_cec084->setHidden(true);
	opx5e_cec088->setHidden(true);
	opx5e_cec08c->setHidden(true);
}

void OpX5E_Obj::unknown96bbb0()
{
	unknown148 = opx5e_tickCount + 3000;
	unknown144 = 0;
	if (!opx5e_cec118->isHidden())
		opx5e_cec118->unknown8b5080();
	if (!opx5e_cec11c->isHidden())
		opx5e_cec11c->unknown8b5080();
	if (!opx5e_cec120->isHidden())
		opx5e_cec120->unknown8b5080();
	int effectID;
	OpU8a_lookup2("Block_Turn_Progress_Chrono",&effectID);
	opr5g_effectMgr->create()->init(opr5g_effectMgr,effectID,Point(0,0),Point(0,0),0,0,0,9,0);
	opx5e_soundMgr.unknown5003b0();
	opx5e_soundMgr.unknown4544e0();
	CEffect *anim = new CEffect(this,Rect(0,0,opx5e_rex.unknown418980(),opx5e_rex.unknown4189a0()),10);
	opx5e_rex.getConsole_4ab670()->unknown429fe0(anim,Point(0,0),0);
	anim->animate("A_CEffect_RevertTime");
	opx5e_cec0f4->setHidden(true);
	opx5e_cec0b0->setHidden(true);
	opx5e_cec0d0->setHidden(true);
	opx5e_cec0d4->setHidden(!(opx5e_cefc90 && opx5e_cec0d0->isVisible()));
	opx5e_cec0d8->setHidden(!opx5e_cec0d0->isVisible());
	opx5e_cec0dc->setHidden(!opx5e_cec0d0->isVisible());
	opx5e_cec0e4->setHidden(!(!opx5e_d28c8a && opx5e_cec0d0->isVisible()));
	opx5e_cec0e8->setHidden(!(opx5e_cec0d0->isVisible() && opx5e_cebd5c == 2));
	opx5e_cec0ec->setHidden(!(opx5e_cec0d0->isVisible() && opx5e_cebd5c == 2));
	opx5e_cec0c8->setHidden(true);
	opx5e_cec0cc->setHidden(true);
	opx5e_cec0b8->setHidden(true);
	opx5e_cec0c0->setHidden(true);
	opx5e_cec054->setHidden(true);
	opx5e_cec058->setHidden(true);
	opx5e_cec074->setHidden(true);
	opx5e_cec078->setHidden(true);
	opx5e_cec07c->setHidden(true);
	opx5e_cec084->setHidden(true);
	opx5e_cec088->setHidden(true);
	opx5e_cec08c->setHidden(true);
}

void OpX5E_Obj::unknown96b0a0(bool flag)
{
	unknown184 = flag;
	opx5e_d1d9c0.reset();
	opx5e_cec054->unknown8069e0(opr5g_world->getPlayer()->getPosition(),true);
	opx5e_cec054->render();
	opx5e_soundMgr.unknown5003b0();
	opx5e_soundMgr.unknown4544e0();
	opx5e_sound->haltAll();
	opr5g_playSound(0x79,0,0);
	int effectType;
	OpU8a_lookup2("Block_Turn_Progress_FrgUfdBombs",&effectType);
	opr5g_effectMgr->create()->init(opr5g_effectMgr,effectType,Point(0,0),Point(0,0),0,0,0,9,0);
	unknown1ac = opx5e_tickCount + 250;
	unknown1b0 = 0;
	unknown1b4 = opx5e_tickCount + 4000;
	unknown188 = new CEffect(this,Rect(opx5e_cec054->getPos().x,opx5e_cec054->getPos().y,opx5e_cec054->getWidth(),opx5e_cec054->getHeight()),0x1c);
	opx5e_cec054->unknown429fe0(unknown188,Point(0,0),0);
	unknown18c = new Console(this,Rect(opx5e_cec054->getPos().x,opx5e_cec054->getPos().y,opx5e_cec054->getWidth(),opx5e_cec054->getHeight()),OpW7_getFont(0x1c),false,unknown188->getLayer_44a7d0() + 1);
	opx5e_cec054->unknown429fe0(unknown18c,Point(0,0),0);
	Point screenOffset(opx5e_cec054->unknown458ef0());
	Pos min;
	Pos end;
	opx5e_cec054->unknown8051f0(&min,&end);
	for (int x = min.x, screenX = OpX5_maxInt(screenOffset.x,0); x <= end.x && screenX < opx5e_screenWidth; x++, screenX++)
		for (int y = min.y, cy = OpX5_maxInt(screenOffset.y,0); y <= end.y && cy < opx5e_screenHeight; y++, cy++)
		{
			if (opr5g_world->isVisible(x,y))
				unknown18c->setBack_417fc0(screenX,cy,*opx5e_d20cfc,1);
		}
	unknown1a0.init_9cf690(opx5e_cells.getWidth(),opx5e_cellsX.getHeight(),0);
	vector<OpX5E_Area> *regions = opr5g_world->unknown4646d0();
	for (unsigned int i = 0; i < regions->size(); i++)
	{
		for (int x = (*regions)[i].min.x; x <= (*regions)[i].max.x; x++)
		{
			for (int y = (*regions)[i].min.y; y <= (*regions)[i].max.y; y++)
			{
				unknown190.push_back(Point(x,y));
				*unknown1a0.at(x,y) = 1;
			}
		}
	}
	OpX5E_Area *extent = opr5g_world->unknown464610();
	for (int x = OpX5_maxInt(0,extent->min.x - 1); x < opx5e_cells.getWidth(); x++)
	{
		for (int y = extent->min.y; y <= extent->max.y; y++)
			*unknown1a0.at(x,y) = 1;
	}
	for (int x = 0x6a; x < opx5e_cells.getWidth(); x++)
	{
		for (int y = 0x7d; y < opx5e_cellsX.getHeight(); y++)
			*unknown1a0.at(x,y) = 1;
	}
	opx5e_cec0f4->setHidden(true);
	opx5e_cec0b0->setHidden(true);
	opx5e_cec0d0->setHidden(true);
	opx5e_cec0d4->setHidden(!(opx5e_cefc90 && opx5e_cec0d0->isVisible()));
	opx5e_cec0d8->setHidden(!opx5e_cec0d0->isVisible());
	opx5e_cec0dc->setHidden(!opx5e_cec0d0->isVisible());
	opx5e_cec0e4->setHidden(!(!opx5e_d28c8a && opx5e_cec0d0->isVisible()));
	opx5e_cec0e8->setHidden(!(opx5e_cec0d0->isVisible() && opx5e_cebd5c == 2));
	opx5e_cec0ec->setHidden(!(opx5e_cec0d0->isVisible() && opx5e_cebd5c == 2));
	opx5e_cec0c8->setHidden(true);
	opx5e_cec0cc->setHidden(true);
	opx5e_cec0b8->setHidden(true);
	opx5e_cec0c0->setHidden(true);
	opx5e_cec054->setHidden(true);
	opx5e_cec058->setHidden(true);
	opx5e_cec074->setHidden(true);
	opx5e_cec078->setHidden(true);
	opx5e_cec07c->setHidden(true);
	opx5e_cec084->setHidden(true);
	opx5e_cec088->setHidden(true);
	opx5e_cec08c->setHidden(true);
}

void OpX5E_Obj::unknown9695b0()
{
	opr5g_playSound(0x107,0,0);
	opx5e_d1d9c0.reset();
	opx5e_cec054->unknown8069e0(opr5g_world->getPlayer()->getPosition(),true);
	opx5e_cec054->render();
	unknown14c.push_back(new CEffect(this,Rect(opx5e_cec054->getPos().x,opx5e_cec054->getPos().y,opx5e_cec054->getWidth(),opx5e_cec054->getHeight()),0x17));
	opx5e_cec054->unknown429fe0(unknown14c.back(),Point(0,0),0);
	opx5e_cec054->copyColorsTo(unknown14c.back(),Point(0,0),NULL);
	int teleportEffect;
	OpU8a_lookup1("CEffect_Teleportitis",&teleportEffect);
	if (teleportEffect)
	{
		CEffect *effect = unknown14c.back();
		OpX5_Array2D<int> *terrain = opr5g_world->unknown463830();
		Pos min;
		Pos end;
		opx5e_cec054->unknown8051f0(&min,&end);
		for (int x = min.x, screenX = OpX5_maxInt(opx5e_cec054->unknown458ef0().x,0); x <= end.x && screenX < opx5e_screenWidth; x++, screenX++)
		{
			for (int y = min.y, cy = OpX5_maxInt(opx5e_cec054->unknown458ef0().y,0); y <= end.y && cy < opx5e_screenHeight; y++, cy++)
			{
				if (*terrain->at(x,y) != 0)
					effect->unknown48c460(teleportEffect,Point(screenX,cy));
			}
		}
	}
	int effectID;
	OpU8a_lookup2("Block_Turn_Progress_Teleportitis",&effectID);
	opr5g_effectMgr->create()->init(opr5g_effectMgr,effectID,Point(0,0),Point(0,0),0,0,0,9,0);
}
