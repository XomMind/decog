// op_q4f: CEnding console in 0x9aaf70-0x9ae000, Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
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
	Pos(const Pos &pos) throw();	// 0x46ca50
	Pos &operator=(const Pos &pos);
};

struct Point
{
	int x;
	int y;

	Point(int x_, int y_);	// 0x46ca20
	Point(int v);	// 0x409990
	Point &operator=(const Point &p);	// 0x46ca50
	void set(int x_, int y_);	// NOTE: placeholder name (0x40a010)
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(const Rect &rect);	// 0x40a720
};

struct XCell;

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

	bool isHidden();
	void clear();
	void setIgnoreMouse_4184a0(bool value);	// NOTE: placeholder name
	void setForeAll_4183d0(XColor color);	// NOTE: placeholder name
	void resetBack_418450();	// NOTE: placeholder name
	void unknown429f10(int a, int b);	// NOTE: placeholder name
	void unknown429fe0(XConsole *console, const Point &pos, int flag);	// NOTE: placeholder name
	int getWidth();	// 0x44b0d0
	int getHeight();
	void putCell_4181a0(int x, int y, const struct XCell &cell);	// NOTE: placeholder name
	void updateBase429ea0();	// NOTE: placeholder name
	void setHidden(bool hidden_);
	void removeSubconsole(XConsole *console);
	void deleteSubconsoles();
	Pos absToLocal(Pos pos);
	bool inBounds(const Pos &pos);

	char pad04[0x60 - 0x04];
};

class OpQ4f_Engine	// NOTE: placeholder name (Engine)
{
public:
	void render();	// NOTE: placeholder name (0x5100b0)
	void stopAll();	// NOTE: placeholder name (0x50ff30)
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);	// NOTE: placeholder name

	void unknown48c460(int anim, const Pos &pos);	// NOTE: placeholder name
	void unknown48c650();	// NOTE: placeholder name

	int unknown60;
	OpQ4f_Engine *engine;
	void *title;
};

class OpQ4f_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void unknown4162e0(int command, int value);	// NOTE: placeholder name
};
extern OpQ4f_KeyMap *opq4f_keyMap;	// NOTE: placeholder name (0xcefa8c)

class OpQ4f_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	Pos getPos_41a700();	// NOTE: placeholder name
	bool getField_41a6e0();	// NOTE: placeholder name
	void unknown432170(bool value);	// NOTE: placeholder name
};
extern OpQ4f_Mouse *opq4f_mouse;	// NOTE: placeholder name (0xcefa94)

class OpQ4f_Sound	// NOTE: placeholder name (0xcefa90)
{
public:
	void unknown419c50();	// NOTE: placeholder name (Mix_HaltChannel(-1))
};
extern OpQ4f_Sound *opq4f_sound;	// NOTE: placeholder name (0xcefa90)

class OpQ4f_Unk9c05e0	// NOTE: placeholder name (0xcefaa8)
{
public:
	void unknown9c05e0();	// NOTE: placeholder name (empty function)
};
extern OpQ4f_Unk9c05e0 *opq4f_cefaa8;	// NOTE: placeholder name

class CGameoverOverlay : public Console
{
public:
	void unknown490590();	// NOTE: placeholder name
};

class CGameover : public Console
{
public:
	void unknown7bfe60();	// NOTE: placeholder name
	CGameoverOverlay *getOverlay_490840();	// NOTE: placeholder name (folded getter)
};
extern CGameover *opq4f_cec144;	// NOTE: placeholder name (0xcec144)

class OpQ4f_Rex	// NOTE: placeholder name (0xd223f0)
{
public:
	XConsole *getConsole_4ab670();	// NOTE: placeholder name (folded getter)
	int unknown418980();	// NOTE: placeholder name
	int unknown4189a0();	// NOTE: placeholder name
};
extern OpQ4f_Rex opq4f_rex;	// NOTE: placeholder name

class ConsoleArt : public Console
{
public:
	ConsoleArt(XConsole *parent, const string &file, int x, int y, bool hidden, int layer, int frame, const Pos &offset_, int width, int height);
	void drawArt(int layer);

	char pad6c[0x84 - 0x6c];
};

class OpQ4f_Unk437190	// NOTE: placeholder name (object at 0xd2f154)
{
public:
	int getField();	// NOTE: placeholder name (folded getter)
};
extern OpQ4f_Unk437190 opq4f_d2f154;	// NOTE: placeholder name

class OpQ4f_PlayerData	// NOTE: placeholder name (object at 0xcf45d8)
{
public:
	bool getField_46dd90();	// NOTE: placeholder name
};
extern OpQ4f_PlayerData opq4f_playerData_cf45d8;	// NOTE: placeholder name

extern XColor *opq4f_cfe674;	// NOTE: placeholder name
extern bool opq4f_flag_cefc5c;	// NOTE: placeholder name
int opq4f_centerOffset_437190(int a, int b);	// NOTE: placeholder name ((b - a) / 2)
void opq4f_unknown4541b0(int a, int b, int c);	// NOTE: placeholder name
extern bool opq4f_flag_cefacd;	// NOTE: placeholder name
extern int opq4f_mode_cf4b38;	// NOTE: placeholder name
extern unsigned int opq4f_tickCount;	// NOTE: placeholder name (0xcaed20)
extern bool opq4f_inputBlocked;	// NOTE: placeholder name (0xcefa5f)
extern unsigned int opq4f_times_bce8d8[];	// NOTE: placeholder name
bool opq4f_findAnimation_9d45a0(const string &name, int &index);	// NOTE: placeholder name
void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)

class OpQ4f_Grid	// NOTE: placeholder name (Array2D<XCell>)
{
public:
	int getWidth();
	int getHeight();
	XCell &at_9cdf20(int x, int y);	// NOTE: placeholder name
};

class AsciiImage
{
public:
	AsciiImage();	// 0x4588d0
	~AsciiImage();

	vector<OpQ4f_Grid*> layers;
};

//==================================================================
// CEnding
//==================================================================

class CEnding : public Console
{
public:
	CEnding();
	virtual ~CEnding();	// defined in op_w7
	virtual bool input(void *event);
	virtual void close();
	void removeConsoles();	// NOTE: placeholder name
	void unknown9aaf70();	// NOTE: placeholder name
	void unknown9aafd0();	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
	int index;	// NOTE: placeholder name
	unsigned int unknown74;	// NOTE: placeholder name
	vector<int> unknown78;	// NOTE: placeholder name
	AsciiImage unknown88;	// NOTE: placeholder name
	vector<Point> unknown98;	// NOTE: placeholder name
	int unknowna8;	// NOTE: placeholder name
	vector<bool> seen;	// NOTE: placeholder name
	vector<int> unknownc0;	// NOTE: placeholder name
	int unknownd0;	// NOTE: placeholder name
	AsciiImage unknownd4;	// NOTE: placeholder name
	int unknowne4;	// NOTE: placeholder name
	bool unknowne8;	// NOTE: placeholder name
	XConsole *unknownec;	// NOTE: placeholder name
	XConsole *unknownf0;	// NOTE: placeholder name
	XConsole *unknownf4;	// NOTE: placeholder name
	XConsole *unknownf8;	// NOTE: placeholder name
	XConsole *unknownfc;	// NOTE: placeholder name
	XConsole *unknown100;	// NOTE: placeholder name
	XConsole *unknown104;	// NOTE: placeholder name
	vector<int> unknown108;	// NOTE: placeholder name
	vector<int> unknown118;	// NOTE: placeholder name
	XConsole *unknown128;	// NOTE: placeholder name
	vector<int> unknown12c;	// NOTE: placeholder name
	vector<int> unknown13c;	// NOTE: placeholder name
	XConsole *unknown14c;	// NOTE: placeholder name
	XConsole *unknown150;	// NOTE: placeholder name
	XConsole *unknown154;	// NOTE: placeholder name
	XConsole *unknown158;	// NOTE: placeholder name
	AsciiImage unknown15c;	// NOTE: placeholder name
	vector<Point> unknown16c;	// NOTE: placeholder name
	XConsole *unknown17c;	// NOTE: placeholder name
	XConsole *unknown180;	// NOTE: placeholder name
	XConsole *unknown184;	// NOTE: placeholder name
	ConsoleArt *unknown188;	// NOTE: placeholder name
	vector<Point> unknown18c;	// NOTE: placeholder name
	int unknown19c;	// NOTE: placeholder name
	int unknown1a0;	// NOTE: placeholder name
	XConsole *unknown1a4;	// NOTE: placeholder name
	XConsole *unknown1a8;	// NOTE: placeholder name
	XConsole *unknown1ac;	// NOTE: placeholder name
	XConsole *unknown1b0;	// NOTE: placeholder name
	vector<int> unknown1b4;	// NOTE: placeholder name
	vector<int> unknown1c4;	// NOTE: placeholder name
	bool unknown1d4;	// NOTE: placeholder name
	XConsole *unknown1d8;	// NOTE: placeholder name
	XConsole *unknown1dc;	// NOTE: placeholder name
	XConsole *unknown1e0;	// NOTE: placeholder name
	vector<int> unknown1e4;	// NOTE: placeholder name
};

extern Point opq4f_point_d31b48;	// NOTE: placeholder name
extern Point opq4f_point_d31b50;	// NOTE: placeholder name
extern Point opq4f_point_d2f118;	// NOTE: placeholder name
extern Point opq4f_point_d2f120;	// NOTE: placeholder name
extern Point opq4f_point_d1da98;	// NOTE: placeholder name
extern Point opq4f_point_d1daa0;	// NOTE: placeholder name
extern Point opq4f_point_d21dc0;	// NOTE: placeholder name
extern Point opq4f_point_d21dc8;	// NOTE: placeholder name
extern Point opq4f_point_d22318;	// NOTE: placeholder name
extern Point opq4f_point_d22320;	// NOTE: placeholder name
extern Point opq4f_point_d20ce8;	// NOTE: placeholder name
extern Point opq4f_point_d0155c;	// NOTE: placeholder name
extern Point opq4f_point_cefd70;	// NOTE: placeholder name
extern CEnding *opq4f_cec148;	// NOTE: placeholder name

CEnding::CEnding()
	: Console(opq4f_rex.getConsole_4ab670(),opq4f_rex.unknown418980() / 2,opq4f_rex.unknown4189a0(),0,0,4,false,-1)
	, unknown6c	(false)
	, index	(0)
	, unknown74	(opq4f_tickCount)
	, unknowna8	(-1)
	, unknowne4	(0)
	, unknowne8	(false)
	, unknownec	(NULL)
	, unknownf0	(NULL)
	, unknownf4	(NULL)
	, unknownf8	(NULL)
	, unknownfc	(NULL)
	, unknown100	(NULL)
	, unknown104	(NULL)
	, unknown128	(NULL)
	, unknown14c	(NULL)
	, unknown150	(NULL)
	, unknown154	(NULL)
	, unknown158	(NULL)
	, unknown17c	(NULL)
	, unknown180	(NULL)
	, unknown184	(NULL)
	, unknown188	(NULL)
	, unknown1a4	(NULL)
	, unknown1a8	(NULL)
	, unknown1ac	(NULL)
	, unknown1b0	(NULL)
	, unknown1d4	(false)
	, unknown1d8	(NULL)
	, unknown1dc	(NULL)
	, unknown1e0	(NULL)
{
	seen.assign(0x35,false);
	opq4f_cec148 = this;
	opq4f_keyMap->unknown4162e0(0x24,1);
	unknown60 = 3;
	resetBack_418450();
	if (!opq4f_mouse->getField_41a6e0())
	{
		opq4f_mouse->unknown432170(true);
		unknown6c = true;
	}
	setIgnoreMouse_4184a0(true);
	opq4f_point_d31b48.x = opq4f_centerOffset_437190(0x50,getWidth());
	opq4f_point_d31b48.y = opq4f_centerOffset_437190(0x3c,getHeight());
	opq4f_point_d31b50.x = opq4f_point_d31b48.x + 0x4f;
	opq4f_point_d31b50.y = opq4f_point_d31b48.y + 0x3b;
	opq4f_point_d2f118 = opq4f_point_d31b48;
	opq4f_point_d2f120.x = opq4f_point_d2f118.x + 0xf;
	opq4f_point_d2f120.y = opq4f_point_d31b48.y + 0x3b;
	opq4f_point_d1da98.x = opq4f_point_d31b50.x - 0xf;
	opq4f_point_d1da98.y = opq4f_point_d31b48.y;
	opq4f_point_d1daa0 = opq4f_point_d31b50;
	opq4f_point_d21dc0.x = opq4f_point_d31b48.x + 0x10;
	opq4f_point_d21dc0.y = opq4f_point_d31b48.y;
	opq4f_point_d21dc8.x = opq4f_point_d1da98.x - 1;
	opq4f_point_d21dc8.y = opq4f_point_d31b48.y + 7;
	opq4f_point_d22318.x = opq4f_point_d31b48.x + 0x10;
	opq4f_point_d22318.y = opq4f_point_d31b48.y + 8;
	opq4f_point_d22320.x = opq4f_point_d22318.x + 0x2f;
	opq4f_point_d22320.y = opq4f_point_d22318.y + 0x33;
	opq4f_point_d20ce8.set(opq4f_centerOffset_437190(0x4c,getWidth()),5);
	opq4f_point_d0155c.set(opq4f_centerOffset_437190(0x50,getWidth()),0);
	opq4f_point_cefd70.set(opq4f_centerOffset_437190(0x1f,getWidth()),7);
}

void CEnding::unknown9aaf70()
{
	opq4f_cec144->setHidden(false);
	opq4f_keyMap->unknown4162e0(0x24,0);
	opq4f_cec144->unknown7bfe60();
	if (unknown6c)
		opq4f_mouse->unknown432170(false);
	unknown1d4 = true;
}

void CEnding::unknown9aafd0()
{
	opq4f_sound->unknown419c50();
	opq4f_rex.getConsole_4ab670()->removeSubconsole(this);
}

void CEnding::close()
{
	if (opq4f_mode_cf4b38 == 1)
	{
		opq4f_cec144->unknown48c650();
		opq4f_cec144->getOverlay_490840()->clear();
		opq4f_cec144->setHidden(false);
		opq4f_cec144->getOverlay_490840()->unknown490590();
	}
	opq4f_keyMap->unknown4162e0(0x24,0);
	if (opq4f_mode_cf4b38 == 7)
	{
		opq4f_cec144->unknown7bfe60();
		ConsoleArt *title = new ConsoleArt(this,string() + "data/art/" + "ending/warlord_title",opq4f_centerOffset_437190(opq4f_d2f154.getField(),getWidth()),2,false,6,0,Pos(-1),0,0);
		if (unknown188 == NULL)
		{
			unknown188 = new ConsoleArt(this,string() + "data/art/" + "ending/warlord_map",opq4f_point_d20ce8.x,opq4f_point_d20ce8.y,false,6,0,Pos(-1),0,0);
			unknown188->setForeAll_4183d0(*opq4f_cfe674);
			unknown188->resetBack_418450();
		}
		unknown188->drawArt(0);
		unknown188->drawArt(1);
		unknown188->drawArt(2);
		unknown429f10(0,0);
		unknown429fe0(opq4f_cec144->getOverlay_490840(),Point(0,0),0);
	}
	opq4f_cec144->trigger("show_stats_win",0);
	opq4f_sound->unknown419c50();
	if (unknown6c)
		opq4f_mouse->unknown432170(false);
	if (opq4f_flag_cefc5c && opq4f_mode_cf4b38 <= 9 && !opq4f_playerData_cf45d8.getField_46dd90())
		opq4f_unknown4541b0(0x141,0,0);
	opq4f_rex.getConsole_4ab670()->removeSubconsole(this);
}

bool CEnding::input(void *event)
{
	if (isHidden() || opq4f_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (*(int*)event)
	{
		case 0x1a1:
			opq4f_cec144->setHidden(false);
			if (opq4f_mode_cf4b38 == 8 || opq4f_mode_cf4b38 == 9)
				unknown9aaf70();
			else
				close();
			return true;
		case 0x1a2:
			if (opq4f_flag_cefacd)
				unknown74 = opq4f_tickCount - opq4f_times_bce8d8[index];
			return true;
		case 0x1a3:
			if (opq4f_flag_cefacd)
			{
				index = 0;
				unknown74 = opq4f_tickCount - opq4f_times_bce8d8[index];
				removeConsoles();
				deleteSubconsoles();
				opq4f_sound->unknown419c50();
			}
			return true;
		case 0x1a4:
			if (opq4f_flag_cefacd)
			{
				index = 9;
				unknown74 = opq4f_tickCount - opq4f_times_bce8d8[index];
				removeConsoles();
				deleteSubconsoles();
				opq4f_sound->unknown419c50();
				engine->stopAll();
			}
			return true;
		case 0x1a5:
			if (opq4f_flag_cefacd && (index == 4 || index == 5))
			{
				Pos pos = absToLocal(opq4f_mouse->getPos_41a700());
				if (inBounds(pos))
				{
					int anim;
					opq4f_findAnimation_9d45a0("A_CEnding_Surface_Close",anim);
					unknown48c460(anim,pos);
				}
			}
			return true;
		case 0x1a6:
			if (opq4f_flag_cefacd)
			{
				unknown48c650();
				opq4f_cefaa8->unknown9c05e0();
			}
			return true;
		default:
			return false;
	}
}

void OpQ4f_dataIntegrity_9adc80()	// NOTE: placeholder name
{
	logFatal("MAIN.C","DATA INTEGRITY COMPROMISED");
}

//==================================================================
// CEndingFade
//==================================================================

extern Point opq4f_point_d22318;	// NOTE: placeholder name

class CEndingFade : public Console
{
public:
	virtual void render();

	unsigned int startTime;	// NOTE: placeholder name
	unsigned int duration;	// NOTE: placeholder name
	bool shake;	// NOTE: placeholder name
	unsigned int shakeDuration;	// NOTE: placeholder name
	bool planet;	// NOTE: placeholder name
	AsciiImage planetArt;	// NOTE: placeholder name
	AsciiImage scarArt;	// NOTE: placeholder name
};

void CEndingFade::render()
{
	if (isHidden())
		return;
	if (planet)
	{
		OpQ4f_Grid *art = planetArt.layers.front();
		for (int i = 0, px = opq4f_point_d22318.x; i < art->getWidth(); i++, px++)
		{
			for (int y = 0, py = opq4f_point_d22318.y; y < art->getHeight(); y++, py++)
				putCell_4181a0(px,py,art->at_9cdf20(i,y));
		}
		if (opq4f_tickCount >= startTime + 1000)
		{
			OpQ4f_Grid *scar = scarArt.layers.front();
			for (int i = 0, px = opq4f_point_d22318.x + 0x11; i < scar->getWidth(); i++, px++)
			{
				for (int y = 0, py = opq4f_point_d22318.y + 0x15; y < scar->getHeight(); y++, py++)
					putCell_4181a0(px,py,scar->at_9cdf20(i,y));
			}
		}
	}
	engine->render();
	updateBase429ea0();
}
