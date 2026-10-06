// op_r5g: effect-object (0xcec138) methods + CMission/CMainUiButton/CEvolve helpers in
//	0x965c10-0x998590 of COGMIND.exe (Beta 17.1).
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
};

class CEffect : public Console
{
public:
	CEffect(XConsole *parent, const Rect &rect, int type_);

	int type;	// NOTE: placeholder name
};

class REX	// NOTE: placeholder layout (0xd223f0)
{
public:
	int unknown418980();	// NOTE: placeholder name
	int unknown4189a0();	// NOTE: placeholder name
};
extern REX opr5g_rex;	// NOTE: placeholder name

extern unsigned int opr5g_tickCount;	// NOTE: placeholder name (0xcaed20)
bool findEffectID(const string &name, int *id);	// NOTE: placeholder name (0x9d7980)
void opr5g_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)
void opr5g_playSound(int sound, int volume, int a, int b);	// NOTE: placeholder name (0x454200)
void opr5g_copyIndices(vector<unsigned int> *source, vector<int> *indices);	// NOTE: placeholder name (0x9e3380)
extern vector<unsigned int> vec_cf7550;	// NOTE: placeholder name (0xcf7550)
class OpR5g_EffectList	// NOTE: placeholder name (0xcefc50)
{
public:
	void stopAll();	// NOTE: placeholder name (0x5086c0)
};
extern OpR5g_EffectList *opr5g_effectList;	// NOTE: placeholder name (0xcefc50)

class OpR5g_Sound	// NOTE: placeholder name (0xcefa90)
{
public:
	void unknown41a210(int index);	// NOTE: placeholder name
};
extern OpR5g_Sound *opr5g_sound;	// NOTE: placeholder name (0xcefa90)

class OpR5g_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
	void unknown738b70();	// NOTE: placeholder name
	void unknown777190(int value);	// NOTE: placeholder name
	bool unknown715920();	// NOTE: placeholder name
	bool unknown71bbd0();	// NOTE: placeholder name
};
extern OpR5g_World *opr5g_world;	// NOTE: placeholder name (0xcefc4c)

int stringToInt(const string &s);	// 0x405610

class OpR5g_GameData	// NOTE: placeholder name (0xd1e860)
{
public:
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
};
extern OpR5g_GameData opr5g_gameData;	// NOTE: placeholder name

class OpR5g_StatTracker	// NOTE: placeholder name (0xd2c658)
{
public:
	void unknown472b90(int id, int value);	// NOTE: placeholder name
};
extern OpR5g_StatTracker opr5g_statTracker;	// NOTE: placeholder name

extern int opr5g_mode;	// NOTE: placeholder name (0xcf4b38)
extern bool gameActive;	// NOTE: placeholder name (0xcefbc6)

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

class CMainUiButton : public Console
{
public:
	virtual void update();

	int index;	// NOTE: placeholder name
	int state;	// NOTE: placeholder name
	bool attention[4];	// NOTE: placeholder name
};

//==================================================================
// CCycleCounter / CUfdArea (0x997000-0x997220)
//==================================================================

extern unsigned int opr5g_bce9a4;	// NOTE: placeholder name
extern unsigned int opr5g_bce9a0;	// NOTE: placeholder name
extern XColor *opr5g_cfe674;	// NOTE: placeholder name

class CCycleCounter : public Console
{
public:
	void refresh();	// NOTE: placeholder name (0x997030)

	int value;	// NOTE: placeholder name
};

class CUfdArea : public Console
{
public:
	CUfdArea(XConsole *parent, int value_, const Pos &size, int layer);	// NOTE: placeholder parameter names
	virtual void update();

	int value;	// NOTE: placeholder name
	unsigned int unknown70;	// NOTE: placeholder name
	unsigned int unknown74;	// NOTE: placeholder name
	bool unknown78;	// NOTE: placeholder name
	int unknown7c;	// NOTE: placeholder name
};
extern vector<vector<int> > opr5g_cf670c;	// NOTE: placeholder name

//==================================================================
// CEvolve (0xcec140)
//==================================================================

struct OpR5g_Node	// NOTE: placeholder name
{
	char pad[8];
	int depth;
};

class OpR5g_HNode	// NOTE: placeholder name
{
	int ID;
public:
	OpR5g_Node *operator->() const;	// 0x9b7910
};
extern OpR5g_HNode opr5g_d1e888;	// NOTE: placeholder name

struct OpR5g_Range	// NOTE: placeholder name (8 bytes)
{
	int randomInRange_40c130() throw();	// NOTE: placeholder name

	int min;
	int max;
};
extern OpR5g_Range opr5g_cfe610[];	// NOTE: placeholder name

class OpR5g_Engine	// NOTE: placeholder name
{
public:
	void unknown50ff30();	// NOTE: placeholder name
	void update();	// NOTE: placeholder name (0x50fff0)
	void killGroup(string group);	// NOTE: placeholder name (0x50fd90)
};

class CEvolveMain : public Console
{
public:
	void unknown98bda0(int slot, bool increase);	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	int unknown74[4];	// NOTE: placeholder name
	vector<Console*> unknown84;	// NOTE: placeholder name
	char pad94[0xa0 - 0x94];
	int unknowna0;	// NOTE: placeholder name
};

class CEvolve : public Console
{
public:
	virtual bool input(XEvent *event);
	virtual void inputKey(int key, int mode);
	virtual void close();

	void unknown992dc0();	// NOTE: placeholder name
	unsigned int unknown98c130();	// NOTE: placeholder name

	char pad6c[0x78 - 0x6c];
	bool unknown78;	// NOTE: placeholder name
	char pad79[0x7c - 0x79];
	CEvolveMain *unknown7c;	// NOTE: placeholder name
	char pad80[0xb0 - 0x80];
	Console *unknownb0;	// NOTE: placeholder name
};
extern CEvolve *opr5g_cec140;	// NOTE: placeholder name
extern vector<XColor> opr5g_d2b4bc;	// NOTE: placeholder name
extern XColor *opr5g_d2981c;	// NOTE: placeholder name
string intToString(int value);
extern string opr5g_d29018[];	// NOTE: placeholder name
extern bool opr5g_inputBlocked;	// NOTE: placeholder name (0xcefa5f)

//==================================================================
// object at 0xcec138 (0x965c10-0x96cc30)
//==================================================================

class OpR5g_Obj : public Console	// NOTE: placeholder name
{
public:
	void unknown966dc0();	// NOTE: placeholder name
	void unknown969300();	// NOTE: placeholder name
	void unknown9693f0();	// NOTE: placeholder name
	void unknown969500();	// NOTE: placeholder name
	void unknown96b930();	// NOTE: placeholder name
	void unknown96b9d0();	// NOTE: placeholder name
	void unknown969970(XConsole *target);	// NOTE: placeholder name

	int pad6c[8];
	int unknown8c;
	int unknown90;
	int unknown94;
	int unknown98;
	int pad9c[0x19];
	vector<class CEffect*> unknown100;
	int unknown110;
	int unknown114;
	int unknown118;
	vector<int> unknown11c;
	vector<XConsole*> unknown12c;
	int pad13c[0x10];
	bool unknown17c;
	XConsole *unknown180;
	bool unknown184;
	XConsole *unknown188;
	XConsole *unknown18c;
};

void OpR5g_Obj::unknown966dc0()
{
	unknown90 = opr5g_tickCount + 3000;
	unknown8c = opr5g_tickCount;
	unknown94 = opr5g_tickCount + 500;
	unknown98 = 0;
	opr5g_playSound(0x90,0,0);
	int effectID;
	findEffectID("Block_Turn_Progress_Conduit",&effectID);
	opr5g_effectMgr->create()->init(opr5g_effectMgr,effectID,Point(0,0),Point(0,0),0,0,0,9,0);
}

void OpR5g_Obj::unknown969300()
{
	opr5g_playSound(0x8d,0,0);
	unknown110 = opr5g_tickCount;
	unknown114 = opr5g_tickCount + 2500;
	int effectID;
	findEffectID("Block_Turn_Progress_FarCom",&effectID);
	opr5g_effectMgr->create()->init(opr5g_effectMgr,effectID,Point(0,0),Point(0,0),0,0,0,9,0);
}

void OpR5g_Obj::unknown9693f0()
{
	opr5g_playSound(0x8e,0x17,0,0);
	unknown118 = 0;
	unknown11c.clear();
	opr5g_copyIndices(&vec_cf7550,&unknown11c);
	int effectID;
	findEffectID("Block_Turn_Progress_CivilWar",&effectID);
	opr5g_effectMgr->create()->init(opr5g_effectMgr,effectID,Point(0,0),Point(0,0),0,0,0,9,0);
	gameActive = true;
}

void OpR5g_Obj::unknown969500()
{
	unknown118 = -1;
	for (unsigned int i = 0; i < unknown12c.size(); i++)
	{
		if (unknown12c[i] != NULL)
			removeSubconsole(unknown12c[i]);
	}
	unknown12c.clear();
	gameActive = false;
	opr5g_sound->unknown41a210(0x17);
	opr5g_effectList->stopAll();
	opr5g_world->unknown738b70();
}

void OpR5g_Obj::unknown96b930()
{
	if (unknown180 != NULL)
	{
		removeSubconsole(unknown180);
		unknown180 = NULL;
	}
	if (unknown17c)
		opr5g_world->unknown777190(5);
	else
	{
		opr5g_mode = 12;
		opr5g_world->getPlayer()->die(false,10,HEntity(),true,0,0,0,0);
	}
}

void OpR5g_Obj::unknown96b9d0()
{
	if (unknown188 != NULL)
	{
		removeSubconsole(unknown188);
		unknown188 = NULL;
	}
	if (unknown18c != NULL)
	{
		removeSubconsole(unknown18c);
		unknown18c = NULL;
	}
	if (unknown184)
	{
		opr5g_mode = 13;
		opr5g_world->getPlayer()->die(false,10,HEntity(),true,0,0,0,0);
	}
	else if (stringToInt(opr5g_gameData.unknown46f6d0("scrAttackedLocals_g")))
	{
		opr5g_mode = 14;
		opr5g_world->getPlayer()->die(false,10,HEntity(),true,0,0,0,0);
	}
	else
	{
		if (!stringToInt(opr5g_gameData.unknown46f6d0("scrOptimusDestroyed_g")))
			opr5g_statTracker.unknown472b90(0x4d,-999999);
		opr5g_world->unknown777190(9);
	}
}

void OpR5g_Obj::unknown969970(XConsole *target)
{
	int index;	// NOTE: unused; reproduces a 4-byte stack slot
	if (target == NULL)
	{
		int w = rng.rangeInt(25,75);
		int h = rng.rangeInt(10,30);
		unknown100.push_back(new CEffect(this,Rect(rng.rangeInt(0,(float)(opr5g_rex.unknown418980() - w)),rng.rangeInt(0,(float)(opr5g_rex.unknown4189a0() - h)),w,h),19));
	}
	else
		unknown100.push_back(new CEffect(this,Rect(target->getPos().x + 1,target->getPos().y + 1,target->getWidth() - 2,target->getHeight() - 2),20));
}

bool CEvolve::input(XEvent *event)
{
	if (isHidden() || opr5g_inputBlocked)
		return false;
	if (unknown429d00(event))
		return true;
	if (unknown78)
		return false;
	switch (event->type)
	{
	case 0x191:
		if (unknown7c != NULL && unknown7c->unknown70 == 0)
			unknown992dc0();
		return true;
	case 0x192:
		if (unknown7c != NULL && !unknown7c->unknown84.empty())
		{
			if (unknown7c->unknowna0 <= 0)
				unknown7c->unknowna0 = unknown7c->unknown84.size() - 1;
			else
				unknown7c->unknowna0--;
		}
		return true;
	case 0x193:
		if (unknown7c != NULL && !unknown7c->unknown84.empty())
		{
			if (unknown7c->unknowna0 == unknown7c->unknown84.size() - 1)
				unknown7c->unknowna0 = 0;
			else
				unknown7c->unknowna0++;
		}
		return true;
	case 0x194:
		if (unknown7c != NULL && !unknown7c->unknown84.empty() && unknown7c->unknowna0 != -1)
			opr5g_cec140->inputKey(opr5g_d29018[unknown7c->unknowna0][2],0);
		return true;
	case 0x195:
		if (unknown7c != NULL && !unknown7c->unknown84.empty() && unknown7c->unknowna0 != -1)
			opr5g_cec140->inputKey(opr5g_d29018[unknown7c->unknowna0][0],1);
		return true;
	}
	return false;
}

void CEvolve::inputKey(int key, int mode)
{
	if (unknown7c == NULL)
		return;
	switch (mode)
	{
	case 0:
		key -= 0x20;
	case 1:
		if (unknown7c != NULL)
		{
			for (int i = 0; i < 4; i++)
			{
				if (opr5g_d29018[i][0] == key)
				{
					unknown7c->unknown98bda0(i,mode == 0);
					return;
				}
			}
		}
		break;
	default:
		return;
	}
}

void CEvolve::close()
{
	unknown60 = 4;
	deleteSubconsoles();
	unknown7c = NULL;
	unknownb0 = NULL;
	engine->unknown50ff30();
	clear();
	opr5g_d2b4bc[0] = *opr5g_d2981c;
	printAligned(getWidth() / 2,getHeight() / 2,1,"`f" + intToString(0) + "`" + "UPDATING SYSTEMS" + "`x`");
}

void CCycleCounter::refresh()
{
	int current = 0x9cd7;
	if (opr5g_tickCount > value)
	{
		int range = 0x2c;
		int elapsed = opr5g_tickCount - value;
		if (elapsed >= opr5g_bce9a4)
			current = 0x9d02;
		else
			current = (int)((float)elapsed / (float)opr5g_bce9a4 * range + current);
	}
	string text = intToString(current);
	text.insert(text.end() - 1,'.');
	print(1,0,text);
}

unsigned int CEvolve::unknown98c130()
{
	if (opr5g_cfe610[opr5g_d1e888->depth].max == 0)
		return 0;
	else
		return opr5g_cfe610[opr5g_d1e888->depth].randomInRange_40c130() + opr5g_tickCount;
}
