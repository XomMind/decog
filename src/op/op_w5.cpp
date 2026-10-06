// op_w5: game UI consoles in 0x490000-0x4a0000 (CGameoverOverlay, ...) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
#include <iosfwd>
#include "../util/rng.h"
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
	Rect getRect();	// NOTE: placeholder name
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void setTitle(class ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void unknown7b0640(int a, XColor color, int b, int c);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	void *title;
};

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)

class OpW5_GameData	// NOTE: placeholder name (object at 0xd1e860)
{
public:
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
};
extern OpW5_GameData opW5_gameData;	// NOTE: placeholder name (0xd1e860)
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
bool opW5_replace(string &text, string from, string to);	// NOTE: placeholder name (0x407e00)
bool opW5_findAnimation(const string &name, int *index);	// NOTE: placeholder name (0x9d45a0)

struct OpW5_Point	// NOTE: placeholder name
{
	int x;
	int y;

	OpW5_Point() throw();	// 0x453b40
	OpW5_Point(int v);	// 0x409990
};

extern int opW5_unknown_cf4b38;	// NOTE: placeholder name
extern XConsole *opW5_cec034;	// NOTE: placeholder name

class OpW5_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void registerConsole(int command, Console *console, int unknown1, int unknown2);	// NOTE: placeholder name (0x416790)
};
extern OpW5_KeyMap *opW5_keyMap;	// NOTE: placeholder name

class OpW5_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	Pos getPos_40a970();	// NOTE: placeholder name
};
extern OpW5_Mouse *opW5_mouse;	// NOTE: placeholder name

class OpW5_Rex	// NOTE: placeholder name (0xd223f0)
{
public:
	XConsole *getConsole_4ab670();	// NOTE: placeholder name (folded getter)
	int getWidth_418980();	// NOTE: placeholder name
	int getHeight_4189a0();	// NOTE: placeholder name
	bool unknown404af0();	// NOTE: placeholder name
	bool unknown4188e0();	// NOTE: placeholder name
};
extern OpW5_Rex opW5_rex;	// NOTE: placeholder name

extern string gameStrings_d26040[];	// NOTE: placeholder name

//==================================================================
// CGameoverEndingText / CGameoverOverlay
//==================================================================

extern string gameStrings_d358e8[];	// NOTE: placeholder name
extern bool opW5_mapLayers_bbcad8[];	// NOTE: placeholder name

// returns the suffix of the gameover animation set for the current ending
string opW5_getEndingType()	// NOTE: placeholder name
{
	if (stringToInt(opW5_gameData.unknown46f6d0("usedCoreResetMatrix_g")))
		return "Reset";
	else if (stringToInt(opW5_gameData.unknown46f6d0("installedRif_g")))
		return "RIF";
	else if (stringToInt(opW5_gameData.unknown46f6d0("zioWasImprinted_g")))
		return "Imp";
	else
		return "Std";
}

class CGameoverEndingText : public Console
{
public:
	CGameoverEndingText(XConsole *parent, int x, int y, const string &text, const string &animation, int layer);

	virtual void update();
};

CGameoverEndingText::CGameoverEndingText(XConsole *parent, int x, int y, const string &text, const string &animation, int layer)
	: Console(parent,Rect(x,y,text.size(),1),2,false,layer)
{
	print(0,0,text);
	animate(animation);
}

void CGameoverEndingText::update()
{
	if (!engine->isRunning())
		getParent()->removeSubconsole(this);
}

class OpW5_Buffer88	// NOTE: placeholder name
{
public:
	OpW5_Buffer88();	// 0x9d2670
	~OpW5_Buffer88();	// 0x9cec20

	int data[3];
};

class CGameoverOverlay : public Console
{
public:
	CGameoverOverlay(Console *parent);
	virtual ~CGameoverOverlay();

	virtual void update();
	virtual void trigger(const string &command, int value);

	void loadAnimations();	// NOTE: placeholder name
	void unknown490590();	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
	unsigned int unknown70;	// NOTE: placeholder name
	unsigned int unknown74;	// NOTE: placeholder name
	unsigned int unknown78;	// NOTE: placeholder name
	unsigned int unknown7c;	// NOTE: placeholder name
	int unknown80;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	OpW5_Buffer88 unknown88;	// NOTE: placeholder name
	OpW5_Point unknown94;	// NOTE: placeholder name
	vector<int> mapAnimations;	// NOTE: placeholder name
	int eraseAnimation;	// NOTE: placeholder name
	int closeAnimation;	// NOTE: placeholder name
	unsigned int unknownb4;	// NOTE: placeholder name
	unsigned int unknownb8;	// NOTE: placeholder name
	OpW5_Point unknownbc;	// NOTE: placeholder name
	vector<Console*> unknownc4;	// NOTE: placeholder name (martyrs)
};

CGameoverOverlay::CGameoverOverlay(Console *parent)
	: Console(parent,parent->getRect(),opW5_unknown_cf4b38 <= 9 ? 4 : 2,false,-1),
	unknown6c(false),
	unknown70(1),
	unknown74(0),
	unknown78(0),
	unknown7c(0),
	unknown80(0),
	unknownb4(tickCount),
	unknownb8(tickCount),
	unknownbc(-1)
{
	loadAnimations();
	if (opW5_unknown_cf4b38 == 4)
		animate("A_CGameover_0b10_Bkg_" + opW5_getEndingType());
}

CGameoverOverlay::~CGameoverOverlay()
{
}

void CGameoverOverlay::trigger(const string &command, int value)
{
	if (command == "create_line" && !unknown6c)
	{
		unknown6c = true;
		animate("A_Gameover_Loss_Line");
	}
}

void CGameoverOverlay::unknown490590()
{
	unknown74 = tickCount;
	unknown80 = 1;
}

void CGameoverOverlay::loadAnimations()
{
	mapAnimations.clear();
	int animation;
	{
		string type = opW5_getEndingType();
		for (int i = 0; i < 21; i++)
		{
			if (opW5_mapLayers_bbcad8[i])
			{
				string name = gameStrings_d358e8[i];
				opW5_replace(name,"?",type);
				opW5_findAnimation(name,&animation);
				mapAnimations.push_back(animation);
			}
			else
				mapAnimations.push_back(0);
		}
		opW5_findAnimation("Gameover_Map_Erase",&eraseAnimation);
		opW5_findAnimation("A_Gameover_Map_Close",&closeAnimation);
	}
}

//==================================================================
// CGameover (destructor only; see the CGameover* code elsewhere)
//==================================================================

class CGameoverAchievements;
class CGameover;

// declared as in op_w9b.cpp (its other methods live at 0x7bxxxx)
class CGameoverMain : public Console
{
public:
	CGameoverMain(CGameover *parent, const Rect &rect);
	// NOTE: inline here only because op_w9b.cpp leaves the destructor undeclared (an
	//	out-of-line definition would clash with its implicit one in the combined link)
	virtual ~CGameoverMain() {}

	virtual void trigger(const string &command, int value);

	int printSection(int y, bool performance);	// NOTE: placeholder name

	Console *unknown6c;	// NOTE: placeholder name (upload console)
	CGameoverAchievements *achievements;	// NOTE: placeholder name
	unsigned int unknown74;	// NOTE: placeholder name
	Console *unknown78;	// NOTE: placeholder name (restart button)
	Console *unknown7c;	// NOTE: placeholder name (quit button)
	unsigned int unknown80;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	Console *unknown88;	// NOTE: placeholder name
};

class CGameover : public Console
{
public:
	CGameover();
	virtual ~CGameover();

	virtual bool input(void *event);
	virtual void update();
	virtual void trigger(const string &command, int value);

	void unknown7bfe60();	// NOTE: placeholder name
	bool getUnknown6c_4ab570();	// NOTE: placeholder name (folded getter)
	string &getScore_490820();	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
	string score;	// NOTE: placeholder name
	CGameoverOverlay *overlay;	// NOTE: placeholder name
	unsigned int unknown90;	// NOTE: placeholder name
	CGameoverMain *stats;	// NOTE: placeholder name
	unsigned int unknown98;	// NOTE: placeholder name
	bool unknown9c;	// NOTE: placeholder name
};
extern Console *opW5_gameover;	// NOTE: placeholder name (0xcec144)

CGameover::~CGameover()
{
	opW5_gameover = NULL;
}

// References the CGameoverMain destructor (0x490030) so LTCG emits it in this TU.
void opW5_useGameoverMain(CGameoverMain *main)	// NOTE: placeholder name
{
	main->CGameoverMain::~CGameoverMain();
}

//==================================================================
// CHelp
//==================================================================

class CHelp : public Console
{
public:
	CHelp(XConsole *parent, const Rect &rect, int topic_);

	virtual bool input(void *event);
	virtual void update();
	virtual void close();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	int topic;	// NOTE: placeholder name
	OpW5_Point unknown70;	// NOTE: placeholder name
};
extern CHelp *opW5_help;	// NOTE: placeholder name (0xcec038)

CHelp::CHelp(XConsole *parent, const Rect &rect, int topic_)
	: Console(parent,rect,0,false,0x19),
	topic(topic_),
	unknown70(-1)
{
	resetBack_418450();
	animate("A_CHelp_Border");
	opW5_help = this;
	opW5_keyMap->registerConsole(0x1d,this,0x182,0);
}

void opW5_showHelp(int topic)	// NOTE: placeholder name
{
	if (topic == 0x192)
		return;

	Pos p = opW5_mouse->getPos_40a970();
	Rect rect(p.x,p.y + 1,0,0);
	if (gameStrings_d26040[topic].size() <= 50)
	{
		rect.width = gameStrings_d26040[topic].size() + 4;
		rect.height = 3;
	}
	else
	{
		rect.width = 54;
		rect.height = opW5_rex.getConsole_4ab670()->countLines_418350(0,0,50,9999,0,gameStrings_d26040[topic]) + 2;
	}
	if (rect.x + rect.width >= opW5_rex.getWidth_418980())
		rect.x = opW5_rex.getWidth_418980() - 1 - rect.width;
	if (rect.y + rect.height >= opW5_rex.getHeight_4189a0())
		rect.y = p.y - rect.height;
	new CHelp(opW5_cec034,rect,topic);
}

//==================================================================
// 0x490ae0: help text color table
//==================================================================

extern XColor *opW5_color_d32df8;	// NOTE: placeholder name
extern XColor *opW5_color_cf766c;	// NOTE: placeholder name
extern XColor *opW5_color_d29d68;	// NOTE: placeholder name
extern XColor *opW5_color_d33d88;	// NOTE: placeholder name
extern XColor *opW5_color_cf39f4;	// NOTE: placeholder name
extern XColor *opW5_color_d2043c;	// NOTE: placeholder name
extern XColor *opW5_color_cf44c4;	// NOTE: placeholder name
extern XColor *opW5_color_cf13fc;	// NOTE: placeholder name
extern XColor *opW5_color_d20438;	// NOTE: placeholder name
extern XColor *opW5_color_cf6ed4;	// NOTE: placeholder name
extern XColor *opW5_color_d22130;	// NOTE: placeholder name
extern XColor *opW5_color_d204ac;	// NOTE: placeholder name
extern XColor *opW5_color_d33884;	// NOTE: placeholder name
extern XColor *opW5_color_cfd4c8;	// NOTE: placeholder name
extern XColor *opW5_color_d33d24;	// NOTE: placeholder name
extern XColor *opW5_color_d2175c;	// NOTE: placeholder name
extern XColor *opW5_color_cf6b24;	// NOTE: placeholder name
extern XColor *opW5_color_d2981c;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c18;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c1b;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c1e;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c21;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c24;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c27;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c2a;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c2d;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c30;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c33;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c36;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c39;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c3c;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c3f;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c42;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c45;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c48;	// NOTE: placeholder name
extern XColor opW5_helpColor_d01c4b;	// NOTE: placeholder name

void opW5_initHelpColors()	// NOTE: placeholder name
{
	opW5_helpColor_d01c18 = *opW5_color_d32df8;
	opW5_helpColor_d01c1b = *opW5_color_cf766c;
	opW5_helpColor_d01c1e = *opW5_color_d29d68;
	opW5_helpColor_d01c21 = *opW5_color_d33d88;
	opW5_helpColor_d01c24 = *opW5_color_cf39f4;
	opW5_helpColor_d01c27 = *opW5_color_d2043c;
	opW5_helpColor_d01c2a = *opW5_color_cf44c4;
	opW5_helpColor_d01c2d = *opW5_color_cf13fc;
	opW5_helpColor_d01c30 = *opW5_color_d20438;
	opW5_helpColor_d01c33 = *opW5_color_cf6ed4;
	opW5_helpColor_d01c36 = *opW5_color_d22130;
	opW5_helpColor_d01c39 = *opW5_color_d204ac;
	opW5_helpColor_d01c3c = *opW5_color_d33884;
	opW5_helpColor_d01c3f = *opW5_color_cfd4c8;
	opW5_helpColor_d01c42 = *opW5_color_d33d24;
	opW5_helpColor_d01c45 = *opW5_color_d2175c;
	opW5_helpColor_d01c48 = *opW5_color_cf6b24;
	opW5_helpColor_d01c4b = *opW5_color_d2981c;
}

//==================================================================
// 0x490cb0: animation lookup for the menu consoles
//==================================================================

extern string gameStrings_d15db0[];	// NOTE: placeholder name
extern int opW5_anim_cef8bc;	// NOTE: placeholder name
extern int opW5_anim_cef818;	// NOTE: placeholder name
extern int opW5_anim_cef8b8;	// NOTE: placeholder name
extern int opW5_anim_cef960;	// NOTE: placeholder name
extern int opW5_anim_cef97c;	// NOTE: placeholder name
extern int opW5_anim_cef820;	// NOTE: placeholder name
extern int opW5_anim_cef94c;	// NOTE: placeholder name
extern int opW5_anim_cef87c;	// NOTE: placeholder name
extern int opW5_anim_cef964;	// NOTE: placeholder name
extern int opW5_anim_cef81c;	// NOTE: placeholder name
extern int opW5_anim_cef95c;	// NOTE: placeholder name
extern int opW5_anim_cef8e0;	// NOTE: placeholder name
extern int opW5_anim_cef92c;	// NOTE: placeholder name
extern int opW5_anim_cef784;	// NOTE: placeholder name
extern int opW5_anim_cef8ac;	// NOTE: placeholder name
extern int opW5_anim_cef958;	// NOTE: placeholder name
extern int opW5_anim_cef780;	// NOTE: placeholder name
extern int opW5_anim_cef968;	// NOTE: placeholder name
extern int opW5_anim_cef888;	// NOTE: placeholder name
extern int opW5_anim_cef984;	// NOTE: placeholder name
extern int opW5_anim_cef900;	// NOTE: placeholder name
extern int opW5_anim_cef954;	// NOTE: placeholder name
extern int opW5_anim_cef88c;	// NOTE: placeholder name
extern int opW5_anim_cef980;	// NOTE: placeholder name
extern int opW5_anim_cef884;	// NOTE: placeholder name
extern int opW5_anim_cef7bc;	// NOTE: placeholder name
extern int opW5_anim_cef8a8;	// NOTE: placeholder name
extern int opW5_anim_cef858;	// NOTE: placeholder name
extern int opW5_anim_cef824;	// NOTE: placeholder name
extern int opW5_anim_cef860;	// NOTE: placeholder name
extern int opW5_anim_cef8b4;	// NOTE: placeholder name
extern int opW5_anim_cef8dc;	// NOTE: placeholder name
extern int opW5_anim_cef790;	// NOTE: placeholder name
extern int opW5_anim_cef9a0;	// NOTE: placeholder name
extern int opW5_anim_cef840;	// NOTE: placeholder name
extern int opW5_anim_cef950;	// NOTE: placeholder name
extern int opW5_anim_cef844;	// NOTE: placeholder name
extern int opW5_anim_cef814;	// NOTE: placeholder name
extern int opW5_anim_cef8c0;	// NOTE: placeholder name
extern int opW5_anim_cef85c;	// NOTE: placeholder name
extern int opW5_anim_cef970;	// NOTE: placeholder name
extern int opW5_anim_cef978;	// NOTE: placeholder name
extern int opW5_anim_cef988;	// NOTE: placeholder name
extern int opW5_anim_cef98c;	// NOTE: placeholder name
extern int opW5_anim_cef990;	// NOTE: placeholder name
extern int opW5_anim_cef994;	// NOTE: placeholder name
extern int opW5_anim_cef848;	// NOTE: placeholder name
extern int opW5_anim_cef84c;	// NOTE: placeholder name
extern int opW5_anim_cef850;	// NOTE: placeholder name
extern int opW5_anim_cef854;	// NOTE: placeholder name
extern int opW5_anim_cef8fc;	// NOTE: placeholder name
extern int opW5_anim_cef7f8;	// NOTE: placeholder name
extern int opW5_anim_cef7fc;	// NOTE: placeholder name
extern int opW5_anim_cef800;	// NOTE: placeholder name
extern int opW5_anim_cef804;	// NOTE: placeholder name
extern int opW5_anim_cef808;	// NOTE: placeholder name
extern int opW5_anim_cef80c;	// NOTE: placeholder name
extern int opW5_anim_cef880;	// NOTE: placeholder name
extern int opW5_anim_cef810;	// NOTE: placeholder name
extern int opW5_anim_cef948;	// NOTE: placeholder name
extern int opW5_anim_cef788;	// NOTE: placeholder name
extern int opW5_anim_cef7e0[];	// NOTE: placeholder name
extern int opW5_anim_cef8e4[];	// NOTE: placeholder name
extern int opW5_anim_cef864[];	// NOTE: placeholder name
extern int opW5_anim_cef998;	// NOTE: placeholder name
extern int opW5_anim_cef7dc;	// NOTE: placeholder name
extern int opW5_anim_cef8b0;	// NOTE: placeholder name
extern int opW5_anim_cef78c;	// NOTE: placeholder name
extern int opW5_anim_cef99c;	// NOTE: placeholder name
extern int opW5_anim_cef7c0[];	// NOTE: placeholder name
extern int opW5_anim_cef930[];	// NOTE: placeholder name
extern int opW5_anim_cef828[];	// NOTE: placeholder name
extern int opW5_anim_cef8c4[];	// NOTE: placeholder name
extern int opW5_anim_cef890;	// NOTE: placeholder name
extern int opW5_anim_cef894;	// NOTE: placeholder name
extern int opW5_anim_cef898;	// NOTE: placeholder name
extern int opW5_anim_cef89c;	// NOTE: placeholder name
extern int opW5_anim_cef8a0;	// NOTE: placeholder name
extern int opW5_anim_cef8a4;	// NOTE: placeholder name
extern int opW5_anim_cef96c;	// NOTE: placeholder name
extern int opW5_anim_cef974;	// NOTE: placeholder name
extern int opW5_anim_cef7d8;	// NOTE: placeholder name
extern int opW5_anim_cef794;	// NOTE: placeholder name
extern int opW5_anim_cef798;	// NOTE: placeholder name
extern int opW5_anim_cef79c;	// NOTE: placeholder name
extern int opW5_anim_cef7a0;	// NOTE: placeholder name
extern int opW5_anim_cef7a4;	// NOTE: placeholder name
extern int opW5_anim_cef7a8;	// NOTE: placeholder name
extern int opW5_anim_cef7ac;	// NOTE: placeholder name
extern int opW5_anim_cef7b0;	// NOTE: placeholder name
extern int opW5_anim_cef7b4;	// NOTE: placeholder name
extern int opW5_anim_cef7b8;	// NOTE: placeholder name
extern int opW5_anim_cef904;	// NOTE: placeholder name
extern int opW5_anim_cef908;	// NOTE: placeholder name
extern int opW5_anim_cef90c;	// NOTE: placeholder name
extern int opW5_anim_cef910;	// NOTE: placeholder name
extern int opW5_anim_cef914;	// NOTE: placeholder name
extern int opW5_anim_cef918;	// NOTE: placeholder name
extern int opW5_anim_cef91c;	// NOTE: placeholder name
extern int opW5_anim_cef920;	// NOTE: placeholder name
extern int opW5_anim_cef924;	// NOTE: placeholder name
extern int opW5_anim_cef928;	// NOTE: placeholder name

void opW5_initMenuAnimations()	// NOTE: placeholder name
{
	opW5_findAnimation("CCommands_Border",&opW5_anim_cef8bc);
	opW5_findAnimation("A_CCommand_Button_Active",&opW5_anim_cef818);
	opW5_findAnimation("A_CCommand_Button_Inactive",&opW5_anim_cef8b8);
	opW5_findAnimation("A_CCommand_Button_Deactivate",&opW5_anim_cef960);
	opW5_findAnimation("A_CCommand_Button_Activate",&opW5_anim_cef97c);
	opW5_findAnimation("A_BlockAppear_Core",&opW5_anim_cef820);
	opW5_findAnimation("A_BlockAppear_Energy",&opW5_anim_cef94c);
	opW5_findAnimation("A_BlockAppear_Matter",&opW5_anim_cef87c);
	opW5_findAnimation("A_BlockAppear_Text",&opW5_anim_cef964);
	opW5_findAnimation("A_CCommands_Line_Bkg_Core",&opW5_anim_cef81c);
	opW5_findAnimation("A_CCommands_Line_Bkg_Energy",&opW5_anim_cef95c);
	opW5_findAnimation("A_CCommands_Line_Bkg_Matter",&opW5_anim_cef8e0);
	opW5_findAnimation("CCommands_Header",&opW5_anim_cef92c);
	opW5_findAnimation("CCommands_HeaderLine_E",&opW5_anim_cef784);
	opW5_findAnimation("SilentType_GR3_Vert_E",&opW5_anim_cef8ac);
	opW5_findAnimation("A_CCommands_Backslashes",&opW5_anim_cef958);
	opW5_findAnimation("A_CCommands_Key",&opW5_anim_cef780);
	opW5_findAnimation("A_Manual_But_Active",&opW5_anim_cef968);
	opW5_findAnimation("A_Manual_But_Inactive",&opW5_anim_cef888);
	opW5_findAnimation("A_Manual_But_Deactivate",&opW5_anim_cef984);
	opW5_findAnimation("A_Manual_But_Activate",&opW5_anim_cef900);
	opW5_findAnimation("Manual_But_TextNew",&opW5_anim_cef954);
	opW5_findAnimation("Manual_But_TextDeact",&opW5_anim_cef88c);
	opW5_findAnimation("Manual_But_TextActivate",&opW5_anim_cef980);
	opW5_findAnimation("A_Manual_Title",&opW5_anim_cef884);
	opW5_findAnimation("A_Manual_Text_Header",&opW5_anim_cef7bc);
	opW5_findAnimation("A_Manual_Text",&opW5_anim_cef8a8);
	opW5_findAnimation("A_Manual_Page_Button",&opW5_anim_cef858);
	opW5_findAnimation("A_Option_Header",&opW5_anim_cef824);
	opW5_findAnimation("A_Option_Value_Color",&opW5_anim_cef860);
	opW5_findAnimation("A_Option_Value_Grayed",&opW5_anim_cef8b4);
	opW5_findAnimation("A_Option_Desc",&opW5_anim_cef8dc);
	opW5_findAnimation("A_Gamemenu_Inaccessible",&opW5_anim_cef790);
	opW5_findAnimation("A_Gamemenu_Border",&opW5_anim_cef9a0);
	opW5_findAnimation("A_Gamemenu_Key",&opW5_anim_cef840);
	opW5_findAnimation("A_Gamemenu_Name",&opW5_anim_cef950);
	opW5_findAnimation("A_Gamemenu_Info",&opW5_anim_cef844);
	opW5_findAnimation("A_Gamemenu_ButtonName",&opW5_anim_cef814);
	opW5_findAnimation("A_Gamemenu_BtnConfirm",&opW5_anim_cef8c0);
	opW5_findAnimation("A_Gamemenu_Hover_Good",&opW5_anim_cef85c);
	opW5_findAnimation("A_Gamemenu_Hover_Okay",&opW5_anim_cef970);
	opW5_findAnimation("A_Gamemenu_Hover_Bad",&opW5_anim_cef978);
	opW5_findAnimation("A_News_News",&opW5_anim_cef988);
	opW5_findAnimation("A_News_Text_Normal",&opW5_anim_cef98c);
	opW5_findAnimation("A_News_Text_Highlight",&opW5_anim_cef990);
	opW5_findAnimation("A_News_Text_Dark",&opW5_anim_cef994);
	opW5_findAnimation("A_BlockAppear_Text",&opW5_anim_cef848);
	opW5_findAnimation("A_Credits_Contributor",&opW5_anim_cef84c);
	opW5_findAnimation("A_BlockAppear_Type",&opW5_anim_cef850);
	opW5_findAnimation("A_BlockAppear_Dark",&opW5_anim_cef854);
	opW5_findAnimation("A_Credits_Box",&opW5_anim_cef8fc);
	opW5_findAnimation("A_Credits_Art_Program",&opW5_anim_cef7f8);
	opW5_findAnimation("A_Credits_Art_Design",&opW5_anim_cef7fc);
	opW5_findAnimation("A_Credits_Art_Ascii",&opW5_anim_cef800);
	opW5_findAnimation("A_Credits_Art_Sfx",&opW5_anim_cef804);
	opW5_findAnimation("A_Credits_Art_Music",&opW5_anim_cef808);
	opW5_findAnimation("A_Credits_Art_Sprites",&opW5_anim_cef80c);
	opW5_findAnimation("A_Credits_Art_SpriteFgd",&opW5_anim_cef880);
	opW5_findAnimation("A_Credits_Art_Leaderboards",&opW5_anim_cef810);
	opW5_findAnimation("A_Credits_Sound",&opW5_anim_cef948);
	opW5_findAnimation("A_LetterButton_GR",&opW5_anim_cef788);
	opW5_findAnimation("A_LetterButton_GR",&opW5_anim_cef788);
	for (int i = 0; i < 6; i++)
	{
		opW5_findAnimation("A_AchievCategory_Box_" + gameStrings_d15db0[i],&opW5_anim_cef7e0[i]);
		opW5_findAnimation("A_AchievBarEdge_" + gameStrings_d15db0[i],&opW5_anim_cef8e4[i]);
		opW5_findAnimation("A_LetterButton_" + gameStrings_d15db0[i],&opW5_anim_cef864[i]);
	}
	opW5_findAnimation("A_LetterButton_Off",&opW5_anim_cef998);
	opW5_findAnimation("A_AchievementWordFlash",&opW5_anim_cef7dc);
	opW5_findAnimation("A_AchieveState_Initial",&opW5_anim_cef8b0);
	opW5_findAnimation("A_AchieveState_Active",&opW5_anim_cef78c);
	opW5_findAnimation("A_AchieveState_Deactiv",&opW5_anim_cef99c);
	for (int i = 0; i < 6; i++)
	{
		opW5_findAnimation("A_CMap_Achieve_Icon_" + gameStrings_d15db0[i],&opW5_anim_cef7c0[i]);
		opW5_findAnimation("A_BlockAppear_" + gameStrings_d15db0[i],&opW5_anim_cef930[i]);
		opW5_findAnimation("A_AchievementDate_" + gameStrings_d15db0[i],&opW5_anim_cef828[i]);
		opW5_findAnimation("A_AchievementDescLin_" + gameStrings_d15db0[i],&opW5_anim_cef8c4[i]);
	}
	opW5_findAnimation("SilentType_AM3_Vert_E",&opW5_anim_cef890);
	opW5_findAnimation("SilentType_SK3_Vert_E",&opW5_anim_cef894);
	opW5_findAnimation("SilentType_YE3_Vert_E",&opW5_anim_cef898);
	opW5_findAnimation("SilentType_RE3_Vert_E",&opW5_anim_cef89c);
	opW5_findAnimation("SilentType_FU3_Vert_E",&opW5_anim_cef8a0);
	opW5_findAnimation("SilentType_GR3_Vert_E",&opW5_anim_cef8a4);
	opW5_findAnimation("A_BlockAppear_AchieveLocked",&opW5_anim_cef96c);
	opW5_findAnimation("A_AchievDescLineLocked",&opW5_anim_cef974);
	opW5_findAnimation("SilentType_WH2_Vert_E",&opW5_anim_cef7d8);
	opW5_findAnimation("A_BlockAppear_Text",&opW5_anim_cef794);
	opW5_findAnimation("A_Gallery_Item_Highlight",&opW5_anim_cef798);
	opW5_findAnimation("A_Gallery_Item_Thank",&opW5_anim_cef79c);
	opW5_findAnimation("A_Gallery_Item_Own1",&opW5_anim_cef7a0);
	opW5_findAnimation("A_Gallery_Item_Own2",&opW5_anim_cef7a4);
	opW5_findAnimation("A_Gallery_Item_Uncla",&opW5_anim_cef7a8);
	opW5_findAnimation("A_Gallery_Item_Name",&opW5_anim_cef7ac);
	opW5_findAnimation("A_Gallery_Item_Count",&opW5_anim_cef7b0);
	opW5_findAnimation("A_Gallery_Item_Bar",&opW5_anim_cef7b4);
	opW5_findAnimation("A_Gallery_Item_Unkno",&opW5_anim_cef7b8);
	opW5_findAnimation("A_BlockAppear_Text",&opW5_anim_cef904);
	opW5_findAnimation("A_CSupporter_Adv_Even",&opW5_anim_cef908);
	opW5_findAnimation("A_CSupporter_Imp_Even",&opW5_anim_cef90c);
	opW5_findAnimation("A_CSupporter_Pri_Even",&opW5_anim_cef910);
	opW5_findAnimation("A_CSupporter_Adv_Odd",&opW5_anim_cef914);
	opW5_findAnimation("A_CSupporter_Imp_Odd",&opW5_anim_cef918);
	opW5_findAnimation("A_CSupporter_Pri_Odd",&opW5_anim_cef91c);
	opW5_findAnimation("A_CSupporter_Pat_Arc",&opW5_anim_cef920);
	opW5_findAnimation("A_CSupporter_Pat_Sag",&opW5_anim_cef924);
	opW5_findAnimation("A_CSupporter_Pat_Hac",&opW5_anim_cef928);
	opW5_initHelpColors();
}

//==================================================================
// CCommandsButton / CCommandsHud / CCommandsBasic / CCommandsAdvancedPageButton
//==================================================================

extern string gameStrings_d382f0[];	// NOTE: placeholder name
extern string gameStrings_d39d40[];	// NOTE: placeholder name
void unknown9cdcc0(bool *values, unsigned int count, bool value);	// NOTE: placeholder name (fill)

class CCommandsButton : public Console
{
public:
	CCommandsButton(XConsole *parent, int x, int y, int ID_, bool alternate);

	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
	virtual void update();

	int ID;	// NOTE: placeholder name
	int state;	// NOTE: placeholder name
	bool attention[2];	// NOTE: placeholder name
};

CCommandsButton::CCommandsButton(XConsole *parent, int x, int y, int ID_, bool alternate)
	: Console(parent,(alternate ? gameStrings_d39d40[ID_] : gameStrings_d382f0[ID_]).size(),1,x,y,0,false,-1)
{
	ID = ID_;
	state = 0;
	unknown9cdcc0(attention,2,false);
	print(0,0,alternate ? gameStrings_d39d40[ID] : gameStrings_d382f0[ID]);
}

void CCommandsButton::mouseLeave()
{
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_CMOD_HOV_OK");
}

class CCommandsHud : public Console
{
public:
	CCommandsHud(XConsole *parent, int x, int y, int width, const string &text, int color, int color2);
};

CCommandsHud::CCommandsHud(XConsole *parent, int x, int y, int width, const string &text, int color, int color2)
	: Console(parent,width,1,x,y,0,false,-1)
{
	print(0,0,text);
	unknown48c3c0(color);
	if (color2)
		unknown48c3c0(color2);
}

class CCommandsBasic : public Console
{
public:
	virtual void open();	// NOTE: placeholder name
};

void CCommandsBasic::open()
{
	unknown48c3c0(opW5_anim_cef964);
}

class CCommandsAdvancedPageButton : public Console
{
public:
	CCommandsAdvancedPageButton(XConsole *parent, int x, bool next_);

	virtual bool input(void *event);

	void refresh();	// NOTE: placeholder name

	bool next;	// NOTE: placeholder name
	bool enabled;	// NOTE: placeholder name
};

CCommandsAdvancedPageButton::CCommandsAdvancedPageButton(XConsole *parent, int x, bool next_)
	: Console(parent,4,1,x,0,0,false,-1)
{
	next = next_;
	enabled = true;
	print(1,0,next ? ">>" : "<<");
	refresh();
}

//==================================================================
// CCommandsAdvancedPage
//==================================================================

string intToString(int value);
extern XColor *opW5_color_cfe674;	// NOTE: placeholder name

class CCommandsAdvancedPage : public Console
{
public:
	void init();	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
};

void CCommandsAdvancedPage::init()
{
	setBackRow(4,0,10,*opW5_color_d2981c);
	setFore(*opW5_color_cfe674);
	print(5,0,"Page " + intToString(unknown6c) + "/2");
}

//==================================================================
// CManualButton
//==================================================================

int unknown437190(int a, int b);	// NOTE: placeholder name ((b - a) / 2)
extern int opW5_unknown_cf27f4;	// NOTE: placeholder name
extern int opW5_unknown_caf128;	// NOTE: placeholder name

struct OpW5_ManualSection	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	string title;	// NOTE: placeholder name
};
extern vector<OpW5_ManualSection*> opW5_manualSections;	// NOTE: placeholder name (0xcf39dc)

class CManualButton : public Console
{
public:
	CManualButton(XConsole *parent, int y, int mode_);

	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);

	bool unknown7c56b0();	// NOTE: placeholder name
	void unknown7c56e0();	// NOTE: placeholder name
	void draw(int state);	// NOTE: placeholder name

	int mode;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
};

CManualButton::CManualButton(XConsole *parent, int y, int mode_)
	: Console(parent,0x1c,1,unknown437190(0x60,opW5_unknown_cf27f4 * opW5_unknown_caf128) - 1,y,0,false,-1)
{
	mode = mode_;
	string key;
	key += (char)mode;
	print(1,0,key);
	setChar_417f50(3,0,'-');
	string name = opW5_manualSections[mode - 0x61]->title;
	unknown70 = 6;
	if (name.size() > 0x1c - (unknown70 + 1))
		name.erase(name.begin() + 0x1c - (unknown70 + 1),name.end());
	print(unknown70,0,name);
	unknown74 = unknown70 + name.size() - 1;
	unknown7c56e0();
}

bool CManualButton::mouseEnter()
{
	if (unknown7c56b0())
		return false;
	animate("A_ButtonHover_Begin_MANU_HOV_OK");
	return true;
}

void CManualButton::mouseLeave()
{
	if (unknown7c56b0())
		return;
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_MANU_HOV_OK");
}

extern Pos opW5_cfbec0;	// NOTE: placeholder name

void CManualButton::draw(int state)
{
	if (state)
	{
		engine->stopAll();
		clearBack();
	}
	unknown48c3c0(state == 0 ? (unknown7c56b0() ? opW5_anim_cef968 : opW5_anim_cef888) : (state == 1 ? opW5_anim_cef984 : opW5_anim_cef900));
	do
	{
		for (int x = Pos(unknown70,0).x; x < Pos(unknown70,0).x + unknown74 - unknown70 + 1; x++)
			engine->unknown50fb50(engine,state == 0 ? opW5_anim_cef954 : (state == 1 ? opW5_anim_cef88c : opW5_anim_cef980),&Pos(x,Pos(unknown70,0).y),&opW5_cfbec0,NULL,NULL,9)->unknown50de10();
	} while (false);
}

//==================================================================
// CManualText
//==================================================================

void logError(string location, string message);	// NOTE: placeholder name
string opW5_toUpper(const string &text);	// NOTE: placeholder name (0x4083a0)

class CManualText : public Console
{
public:
	CManualText(XConsole *parent, int y, const string &text, bool header_);

	bool header;	// NOTE: placeholder name
};

CManualText::CManualText(XConsole *parent, int y, const string &text, bool header_)
	: Console(parent,0x44,1,unknown437190(0x60,opW5_unknown_cf27f4 * opW5_unknown_caf128) + 0x1c,y,0,false,-1)
{
	header = header_;
	if (header)
	{
		print(1,0,opW5_toUpper(text));
		int x = text.size() + 2;
		if (x >= getWidth())
		{
			logError("CManualText()","Header too long: \"" + text + "\"");
			return;
		}
		putChar_4180b0(x,0,0x91);
		x++;
		setCharRow(x,0,getWidth() - x,'=');
	}
	else
		print(0,0,text);
}

//==================================================================
// CManualPageButton / COptionButton / COptionValue
//==================================================================

class CManualPageButton : public Console
{
public:
	virtual bool mouseEnter();
};

bool CManualPageButton::mouseEnter()
{
	animate("A_ButtonHover_Begin_MANU_HOV_OK");
	return true;
}

extern int opW5_unknown_cefab4;	// NOTE: placeholder name
extern string gameStrings_cfb948[];	// NOTE: placeholder name

class COptionButton : public Console
{
public:
	COptionButton(XConsole *parent, int y, int key_, int option_);

	void draw();	// NOTE: placeholder name

	int key;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
	int option;	// NOTE: placeholder name
};

COptionButton::COptionButton(XConsole *parent, int y, int key_, int option_)
	: Console(parent,0x1c,1,(key_ < 'a' ? 54 : 10) + opW5_unknown_cefab4 * opW5_unknown_caf128 / 2 - 50,y,0,false,-1)
{
	key = key_;
	option = option_;
	string text;
	text += (char)key;
	print(1,0,text);
	setChar_417f50(3,0,'-');
	string name = gameStrings_cfb948[option];
	unknown70 = 6;
	if (name.size() > 0x1c - (unknown70 + 1))
		name.erase(name.begin() + 0x1c - (unknown70 + 1),name.end());
	print(unknown70,0,name);
	unknown74 = unknown70 + name.size() - 1;
	setChar_417f50(unknown70 - 1,0,'[');
	setChar_417f50(unknown74 + 1,0,']');
}

void COptionButton::draw()
{
	unknown48c3c0(opW5_anim_cef888);
	do
	{
		for (int x = Pos(unknown70,0).x; x < Pos(unknown70,0).x + unknown74 - unknown70 + 1; x++)
			engine->unknown50fb50(engine,opW5_anim_cef954,&Pos(x,Pos(unknown70,0).y),&opW5_cfbec0,NULL,NULL,9)->unknown50de10();
	} while (false);
}

class COptionValue : public Console
{
public:
	COptionValue(XConsole *parent, int x, int y, int option_);

	void refresh();	// NOTE: placeholder name

	int option;	// NOTE: placeholder name
};

COptionValue::COptionValue(XConsole *parent, int x, int y, int option_)
	: Console(parent,15,1,x,y,0,false,-1)
{
	option = option_;
}

//==================================================================
// COptionValue::refresh
//==================================================================

// option values (Config fields at 0xd28c68+)
extern int opW5_cfg_d28c68;	// NOTE: placeholder name
extern int opW5_cfg_d28c8c;	// NOTE: placeholder name
extern int opW5_cfg_d28c94[];	// NOTE: placeholder name
extern int opW5_cfg_d28d0c;	// NOTE: placeholder name
extern int opW5_cfg_d28d10;	// NOTE: placeholder name
extern int opW5_cfg_d28d18;	// NOTE: placeholder name
extern int opW5_cfg_d28d20;	// NOTE: placeholder name
extern int opW5_cfg_d28d2c;	// NOTE: placeholder name
extern int opW5_cfg_d28d34;	// NOTE: placeholder name
extern int opW5_cfg_d28d40;	// NOTE: placeholder name
extern int opW5_cfg_d28d44;	// NOTE: placeholder name
extern int opW5_cfg_d28d48;	// NOTE: placeholder name
extern int opW5_cfg_d28d50;	// NOTE: placeholder name
extern int opW5_cfg_d28d54;	// NOTE: placeholder name
extern int opW5_cfg_d28d58;	// NOTE: placeholder name
extern int opW5_cfg_d28d5c;	// NOTE: placeholder name
extern bool opW5_cfg_d28c8a;	// NOTE: placeholder name
extern bool opW5_cfg_d28c90[];	// NOTE: placeholder name
extern bool opW5_cfg_d28d04;	// NOTE: placeholder name
extern bool opW5_cfg_d28d05;	// NOTE: placeholder name
extern bool opW5_cfg_d28d06;	// NOTE: placeholder name
extern bool opW5_cfg_d28d07;	// NOTE: placeholder name
extern bool opW5_cfg_d28d08;	// NOTE: placeholder name
extern bool opW5_cfg_d28d09;	// NOTE: placeholder name
extern bool opW5_cfg_d28d14;	// NOTE: placeholder name
extern bool opW5_cfg_d28d16;	// NOTE: placeholder name
extern bool opW5_cfg_d28d1c;	// NOTE: placeholder name
extern bool opW5_cfg_d28d1d;	// NOTE: placeholder name
extern bool opW5_cfg_d28d24;	// NOTE: placeholder name
extern bool opW5_cfg_d28d25;	// NOTE: placeholder name
extern bool opW5_cfg_d28d26;	// NOTE: placeholder name
extern bool opW5_cfg_d28d27;	// NOTE: placeholder name
extern bool opW5_cfg_d28d28;	// NOTE: placeholder name
extern bool opW5_cfg_d28d30;	// NOTE: placeholder name
extern bool opW5_cfg_d28d31;	// NOTE: placeholder name
extern bool opW5_cfg_d28d32;	// NOTE: placeholder name
extern bool opW5_cfg_d28d38;	// NOTE: placeholder name
extern bool opW5_cfg_d28d39;	// NOTE: placeholder name
extern bool opW5_cfg_d28d3a;	// NOTE: placeholder name
extern bool opW5_cfg_d28d3b;	// NOTE: placeholder name
extern bool opW5_cfg_d28d3c;	// NOTE: placeholder name
extern bool opW5_cfg_d28d4c;	// NOTE: placeholder name
extern bool opW5_cfg_d28d4d;	// NOTE: placeholder name
extern bool opW5_cfg_d28d60;	// NOTE: placeholder name
extern string opW5_cfg_d28ccc;	// NOTE: placeholder name
extern string opW5_cfg_d28ce8;	// NOTE: placeholder name
extern string gameStrings_cf1148[];
extern string gameStrings_d1d088[];
extern string gameStrings_d25808[];
extern string gameStrings_d25e8c[];
extern string gameStrings_d307d0[];
extern string gameStrings_d39718[];
extern string opW5_string_d2d490;	// NOTE: placeholder name
string opW5_truncate_408490(const string &text, int length);	// NOTE: placeholder name

void COptionValue::refresh()
{
	switch (option)
	{
		case 0:
			{
				string text = opW5_truncate_408490(gameStrings_d1d088[opW5_cfg_d28c68],15);
				print(0,0,text);
				unknown48c3c0(opW5_anim_cef860);
			}
			break;
		case 1:
			{
				string name = opW5_string_d2d490;
				int pos = name.find('(');
				if (pos != string::npos && pos > 0)
					name.erase(name.begin() + pos - 1,name.end());
				print(0,0,name);
				unknown48c3c0(opW5_anim_cef860);
			}
			break;
		case 2:
			{
				int mode;
				if (!opW5_rex.unknown404af0())
					mode = 0;
				else if (opW5_rex.unknown4188e0())
					mode = 2;
				else
					mode = 1;
				print(0,0,gameStrings_cf1148[mode]);
				unknown48c3c0(opW5_anim_cef860);
			}
			break;
		case 3:
			print(0,0,opW5_cfg_d28d08 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d08 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 4:
			print(0,0,opW5_cfg_d28d09 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d09 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 5:
			print(0,0,gameStrings_d307d0[opW5_cfg_d28d0c]);
			unknown48c3c0(opW5_anim_cef860);
			break;
		case 6:
			print(0,0,gameStrings_d25808[opW5_cfg_d28d10]);
			unknown48c3c0(opW5_anim_cef860);
			break;
		case 7:
			print(0,0,intToString(opW5_cfg_d28c8c * 10) + "%");
			unknown48c3c0(opW5_anim_cef860);
			break;
		case 8:
		case 9:
		case 10:
		case 11:
			{
				int index = option - 8;
				print(0,0,opW5_cfg_d28c90[index] ? intToString(opW5_cfg_d28c94[index] * 10) + "%" : "0%");
				unknown48c3c0(opW5_cfg_d28c90[index] ? opW5_anim_cef860 : opW5_anim_cef8b4);
			}
			break;
		case 12:
			print(0,0,opW5_cfg_d28d14 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d14 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 13:
			print(0,0,opW5_cfg_d28d16 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d16 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 14:
			print(0,0,gameStrings_d25e8c[opW5_cfg_d28d18]);
			unknown48c3c0(opW5_anim_cef860);
			break;
		case 15:
			print(0,0,opW5_cfg_d28d1c ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d1c ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 16:
			print(0,0,opW5_cfg_d28d1d ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d1d ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 17:
			print(0,0,intToString(opW5_cfg_d28d20));
			unknown48c3c0(opW5_cfg_d28d20 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 18:
			print(0,0,opW5_cfg_d28d24 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d24 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 19:
			print(0,0,opW5_cfg_d28d25 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d25 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 20:
			print(0,0,opW5_cfg_d28c8a ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28c8a ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 21:
			print(0,0,opW5_cfg_d28d26 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d26 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 22:
			print(0,0,opW5_cfg_d28d27 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d27 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 23:
			print(0,0,opW5_cfg_d28d28 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d28 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 24:
			print(0,0,intToString(opW5_cfg_d28d2c));
			unknown48c3c0(opW5_cfg_d28d2c ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 25:
			{
				string text = opW5_truncate_408490(opW5_cfg_d28ccc,15);
				print(0,0,text);
				unknown48c3c0(opW5_anim_cef860);
			}
			break;
		case 26:
			print(0,0,opW5_cfg_d28d04 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d04 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 27:
			{
				string seed = opW5_truncate_408490(opW5_cfg_d28ce8,15);
				print(0,0,seed != "0" ? seed : "Random");
				unknown48c3c0(seed != "0" ? opW5_anim_cef860 : opW5_anim_cef8b4);
			}
			break;
		case 28:
			print(0,0,opW5_cfg_d28d05 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d05 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 29:
			print(0,0,opW5_cfg_d28d06 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d06 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 30:
			print(0,0,opW5_cfg_d28d07 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d07 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 31:
			print(0,0,!opW5_cfg_d28d30 ? "On" : "Off");
			unknown48c3c0(!opW5_cfg_d28d30 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 32:
			print(0,0,opW5_cfg_d28d31 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d31 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 33:
			print(0,0,opW5_cfg_d28d32 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d32 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 34:
			print(0,0,intToString(opW5_cfg_d28d34));
			unknown48c3c0(opW5_cfg_d28d34 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 35:
			print(0,0,opW5_cfg_d28d38 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d38 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 36:
			print(0,0,opW5_cfg_d28d39 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d39 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 37:
			print(0,0,opW5_cfg_d28d3a ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d3a ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 38:
			print(0,0,opW5_cfg_d28d3b ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d3b ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 39:
			print(0,0,opW5_cfg_d28d3c ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d3c ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 40:
			print(0,0,intToString(opW5_cfg_d28d40));
			unknown48c3c0(opW5_cfg_d28d40 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 41:
			print(0,0,"+" + intToString(opW5_cfg_d28d44));
			unknown48c3c0(opW5_cfg_d28d44 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 42:
			print(0,0,gameStrings_d39718[opW5_cfg_d28d48]);
			unknown48c3c0(opW5_anim_cef860);
			break;
		case 43:
			print(0,0,opW5_cfg_d28d4c ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d4c ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 44:
			print(0,0,opW5_cfg_d28d4d ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d4d ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 45:
			print(0,0,intToString(opW5_cfg_d28d50));
			unknown48c3c0(opW5_anim_cef860);
			break;
		case 46:
			print(0,0,opW5_cfg_d28d54 ? intToString(opW5_cfg_d28d54) + "%" : "0%");
			unknown48c3c0(opW5_cfg_d28d54 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 47:
			print(0,0,opW5_cfg_d28d58 ? intToString(opW5_cfg_d28d58) + "%" : "0%");
			unknown48c3c0(opW5_cfg_d28d58 ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 48:
			print(0,0,opW5_cfg_d28d5c ? intToString(opW5_cfg_d28d5c) + "%" : "0%");
			unknown48c3c0(opW5_cfg_d28d5c ? opW5_anim_cef860 : opW5_anim_cef8b4);
			break;
		case 49:
			print(0,0,opW5_cfg_d28d60 ? "On" : "Off");
			unknown48c3c0(opW5_cfg_d28d60 ? opW5_anim_cef860 : opW5_anim_cef8b4);
	}
}

//==================================================================
// CGamemenuButtonText / CGamemenuButton
//==================================================================

class CGamemenuButtonText : public Console
{
public:
	CGamemenuButtonText(XConsole *parent, int x, int y, const string &text);
};

CGamemenuButtonText::CGamemenuButtonText(XConsole *parent, int x, int y, const string &text)
	: Console(parent,text.size(),1,x,y,0,false,-1)
{
	print(0,0,text);
}

extern string gameStrings_d2f2d8[];	// NOTE: placeholder name
extern string gameStrings_cf0ce8[];	// NOTE: placeholder name

class CGamemenuButton : public Console
{
public:
	CGamemenuButton(XConsole *parent, int x, int y, int key_, int index_);

	int key;	// NOTE: placeholder name
	int index;	// NOTE: placeholder name
	CGamemenuButtonText *keyText;	// NOTE: placeholder name
	CGamemenuButtonText *nameText;	// NOTE: placeholder name
	CGamemenuButtonText *infoText;	// NOTE: placeholder name
	int unknown80;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
};

CGamemenuButton::CGamemenuButton(XConsole *parent, int x, int y, int key_, int index_)
	: Console(parent,0x17,5,x,y,0,false,-1)
{
	key = key_;
	index = index_;
	unknown80 = 0;
	unknown84 = 0;
	unknown7b0640(0,*opW5_color_cfe674,1,0);
	string text = "[";
	text += (char)key;
	text += "]";
	keyText = new CGamemenuButtonText(this,unknown437190(text.size(),getWidth()),0,text);
	nameText = new CGamemenuButtonText(this,unknown437190(gameStrings_d2f2d8[index].size(),getWidth()),2,gameStrings_d2f2d8[index]);
	infoText = new CGamemenuButtonText(this,unknown437190(gameStrings_cf0ce8[index].size(),getWidth()),4,gameStrings_cf0ce8[index]);
}

//==================================================================
// CGamemenuSaveloadButton
//==================================================================

class Unknown_c34b30 : public Console	// CGamemenuSaveloadButtonText (src/lead/c045.cpp)
{
public:
	Unknown_c34b30(XConsole *parent, int x, int y, const string &text);	// 0x495a10
};

struct OpW5_SaveInfo	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	int location;	// NOTE: placeholder name
	int depth;	// NOTE: placeholder name
	char padc[0x25 - 0xc];
	bool known;	// NOTE: placeholder name
};
class OpW5_HSaveInfo	// NOTE: placeholder name
{
public:
	int ID;
	OpW5_SaveInfo *operator->() const;	// 0x9b7910
};
extern OpW5_HSaveInfo opW5_saveInfo;	// NOTE: placeholder name (0xcf4618)
extern int opW5_saveTurn;	// NOTE: placeholder name (0xcf461c)
extern string gameStrings_cfaca0[];	// NOTE: placeholder name
extern string gameStrings_d2b480[];	// NOTE: placeholder name
extern string gameStrings_d1daa8[];	// NOTE: placeholder name

class CGamemenuSaveloadButton : public Console
{
public:
	CGamemenuSaveloadButton(XConsole *parent, int y, int type_, bool hasSave_);

	int type;	// NOTE: placeholder name
	Unknown_c34b30 *keyText;	// NOTE: placeholder name
	Unknown_c34b30 *nameText;	// NOTE: placeholder name
	Unknown_c34b30 *saveText;	// NOTE: placeholder name
	Unknown_c34b30 *infoText;	// NOTE: placeholder name
	int unknown80;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	bool hasSave;	// NOTE: placeholder name
};

CGamemenuSaveloadButton::CGamemenuSaveloadButton(XConsole *parent, int y, int type_, bool hasSave_)
	: Console(parent,0x22,type_ - 1 ? 5 : 7,opW5_unknown_cefab4 * opW5_unknown_caf128 - 0x25,y,0,false,-1)
{
	type = type_;
	saveText = NULL;
	unknown80 = 0;
	unknown84 = 0;
	hasSave = hasSave_;
	unknown7b0640(0,*opW5_color_cfe674,1,0);
	string key = "[";
	key += type == 0 ? "Ctrl-F8" : "Ctrl-F9";
	key += "]";
	keyText = new Unknown_c34b30(this,unknown437190(key.size(),getWidth()),0,key);
	nameText = new Unknown_c34b30(this,unknown437190(gameStrings_d2b480[type].size(),getWidth()),2,gameStrings_d2b480[type]);
	string text;
	if (type == 1)
	{
		if (hasSave)
		{
			text = "-" + intToString(opW5_saveInfo->depth) + "/" + (opW5_saveInfo->known ? gameStrings_cfaca0[opW5_saveInfo->location] : "???");
			text += ", turn " + intToString(opW5_saveTurn);
		}
		else
			text = "(none)";
		saveText = new Unknown_c34b30(this,unknown437190(text.size(),getWidth()),4,text);
	}
	infoText = new Unknown_c34b30(this,unknown437190(gameStrings_d1daa8[type].size(),getWidth()),getHeight() - 1,gameStrings_d1daa8[type]);
}

//==================================================================
// CCollectionCounts
//==================================================================

class Unknown_c34c9c : public Console	// CCollectionCountButton (src/lead/c045.cpp)
{
public:
	Unknown_c34c9c(XConsole *parent, int x, int y, bool flag);	// 0x4969d0

	bool unknown6c;	// NOTE: placeholder name
};

bool opW5_unknown4328a0();	// NOTE: placeholder name
extern const int opW5_collectionHeights_bcb2b4[];	// NOTE: placeholder name
extern XColor *opW5_color_cf6b24;	// NOTE: placeholder name

class CCollectionCounts : public Console
{
public:
	CCollectionCounts(XConsole *parent, int x, int y);
};

CCollectionCounts::CCollectionCounts(XConsole *parent, int x, int y)
	: Console(parent,15,opW5_collectionHeights_bcb2b4[opW5_unknown4328a0() != 0],x,y,0,false,0xb)
{
	if (opW5_unknown4328a0())
	{
		new Unknown_c34c9c(this,2,0,true);
		new Unknown_c34c9c(this,8,0,false);
		putChar_418110(getWidth() / 2,0,'|',*opW5_color_cf6b24);
		putChar_418110(0,0,'[',*opW5_color_cf6b24);
		putChar_418110(getWidth() - 1,0,']',*opW5_color_cf6b24);
	}
	else
	{
		new Unknown_c34c9c(this,2,1,true);
		new Unknown_c34c9c(this,8,1,false);
		putChar_418110(getWidth() / 2,1,'|',*opW5_color_cf6b24);
		animate("CCollectionNum_Border");
	}
}

//==================================================================
// CCollectionExport
//==================================================================

class Unknown_c34c68 : public Console	// CGalleryText (src/lead/c045.cpp)
{
public:
	Unknown_c34c68(XConsole *parent, int x, int y, int width, int height, int value);	// 0x496950
	void setColor();	// 0x4969a0

	int unknown6c;	// NOTE: placeholder name
};

class Unknown_c34d38 : public Console	// CCollectionExportButton (src/lead/c045.cpp)
{
public:
	Unknown_c34d38(XConsole *parent, int x, int y, int index);	// 0x496c90

	int unknown6c;	// NOTE: placeholder name
	bool unknown70;	// NOTE: placeholder name
};

extern const int opW5_exportWidths_bcbc1c[];	// NOTE: placeholder name
extern const int opW5_exportHeights_bcbcd4[];	// NOTE: placeholder name
extern XColor opW5_color_cf6f2c;	// NOTE: placeholder name
extern XColor *opW5_color_cf44c0;	// NOTE: placeholder name

class CCollectionExport : public Console
{
public:
	CCollectionExport(XConsole *parent, int x, int y);

	vector<Unknown_c34d38*> buttons;	// NOTE: placeholder name
};

CCollectionExport::CCollectionExport(XConsole *parent, int x, int y)
	: Console(parent,opW5_exportWidths_bcbc1c[opW5_unknown4328a0() != 0],opW5_exportHeights_bcbcd4[opW5_unknown4328a0() != 0],x,y,0,false,0xb)
{
	if (opW5_unknown4328a0())
	{
		XColor fore = opW5_color_cf6f2c * 0.5f;
		setCharRow(0,0,getWidth() - 1,0x81,fore);
		setCharRow(0,getHeight() - 1,getWidth() - 1,0x81,fore);
		setCharColumn(getWidth() - 1,1,getHeight() - 2,0x80,fore);
		putChar_418110(getWidth() - 1,0,0x83,fore);
		putChar_418110(getWidth() - 1,getHeight() - 1,0x8a,fore);
		string text = "Export";
		Unknown_c34c68 *label = new Unknown_c34c68(this,0,2,text.size(),1,0);
		label->print(0,0,text);
		label->setColor();
		buttons.push_back(new Unknown_c34d38(this,2,3,0));
		buttons.push_back(new Unknown_c34d38(this,1,4,1));
		buttons.push_back(new Unknown_c34d38(this,2,5,2));
		putChar_418110(0,3,0x85,fore);
		putChar_418110(0,4,0x85,fore);
		putChar_418110(0,5,0x87,fore);
		putChar_418110(1,3,0x81,fore);
		putChar_418110(1,5,0x81,fore);
	}
	else
	{
		string text = "Export";
		Unknown_c34c68 *label = new Unknown_c34c68(this,2,1,text.size(),1,0);
		label->print(0,0,text);
		label->setColor();
		string dates = "      /      /     ";
		setFore(*opW5_color_cf44c0);
		print(text.size() + 4,1,dates);
		for (int i = 0, x = 9; i < 3; i++, x++)
		{
			buttons.push_back(new Unknown_c34d38(this,x,1,i));
			x += buttons.back()->getWidth();
		}
		animate("CCollectionNum_Border");
	}
}

//==================================================================
// CGallery / CLoreItem
//==================================================================

class CGallery : public Console
{
public:
	int getKey(Console *item);	// NOTE: placeholder name

	char pad6c[0xa4 - 0x6c];
	vector<Console*> items;	// NOTE: placeholder name
};

int CGallery::getKey(Console *item)
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i] == item)
			return i + '1';
	}
	return 0;
}

struct OpW5_LoreSource	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	string name;	// NOTE: placeholder name
	int unknown20;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
};

struct OpW5_LoreDialogue	// NOTE: placeholder name
{
	char pad0[0x24];
	int type;	// NOTE: placeholder name
	int speaker;	// NOTE: placeholder name
};

struct OpW5_LoreRecord	// NOTE: placeholder name
{
	char pad0[0x24];
	int type;	// NOTE: placeholder name
	char pad28[0x1ac - 0x28];
	string name;	// NOTE: placeholder name
};

struct OpW5_LoreEntry	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	bool known;	// NOTE: placeholder name
	OpW5_LoreSource *source;	// NOTE: placeholder name
	OpW5_LoreDialogue *dialogue;	// NOTE: placeholder name
	int number;	// NOTE: placeholder name
	OpW5_LoreRecord *record;	// NOTE: placeholder name
};

extern string gameStrings_d38648[];	// NOTE: placeholder name
extern vector<string> opW5_loreTypes;	// NOTE: placeholder name (0xd1d9b0)
extern vector<string> opW5_speakers;	// NOTE: placeholder name (0xd2283c)

class CLoreItem : public Console
{
public:
	CLoreItem(XConsole *parent, int y, OpW5_LoreEntry *entry_);

	OpW5_LoreEntry *entry;	// NOTE: placeholder name
};

CLoreItem::CLoreItem(XConsole *parent, int y, OpW5_LoreEntry *entry_)
	: Console(parent,0x32,1,2,y,0,false,-1)
{
	entry = entry_;
	string type;
	string name;
	if (!entry->known)
		type = name = "???";
	else
	{
		type = entry->record ? gameStrings_d38648[entry->record->type] : opW5_loreTypes[entry->source ? entry->source->type : entry->dialogue->type];
		name = entry->source ? entry->source->name : (entry->dialogue ? "Dialogue " + intToString(entry->number) + (entry->dialogue->speaker == -1 ? "" : " (" + opW5_speakers[entry->dialogue->speaker] + ")") : entry->record->name);
	}
	printAligned(0xc,0,2,type);
	print(0x10,0,name);
	animate(entry->known ? "A_CLoreItem_Discovered" : "A_CLoreItem_Unknown");
}

//==================================================================
// CLore / CAchievementsCategoryButton
//==================================================================

class CLore : public Console
{
public:
	virtual ~CLore();

	int unknown6c;	// NOTE: placeholder name
	vector<int> unknown70;	// NOTE: placeholder name
};
extern CLore *opW5_lore;	// NOTE: placeholder name (0xcec044)

CLore::~CLore()
{
	opW5_lore = NULL;
}

extern vector<bool> opW5_achievementCategories;	// NOTE: placeholder name (0xd28d70)

class CAchievementsCategoryButton : public Console
{
public:
	virtual void mouseLeave();

	int category;	// NOTE: placeholder name
};

void CAchievementsCategoryButton::mouseLeave()
{
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_Achieve_" + (opW5_achievementCategories[category] ? gameStrings_d15db0[category] : "OFF") + "_HOV_OK");
}

//==================================================================
// CAchievements*
//==================================================================

class CAchievementsCategoryToggleAllButton : public Console
{
public:
	CAchievementsCategoryToggleAllButton(XConsole *parent, int x, int y);

	void unknown7ed4f0(int mode);	// NOTE: placeholder name
};

CAchievementsCategoryToggleAllButton::CAchievementsCategoryToggleAllButton(XConsole *parent, int x, int y)
	: Console(parent,0x19,1,x,y,0,false,-1)
{
	print(0,0,"[1] Toggle All Categories");
	unknown7ed4f0(0);
}

extern string gameStrings_d20af8[];	// NOTE: placeholder name
extern string gameStrings_d304d0[];	// NOTE: placeholder name
extern int opW5_achievementState_d28d84;	// NOTE: placeholder name
extern int opW5_achievementState_d28d88;	// NOTE: placeholder name

class CAchievementsStateButton : public Console
{
public:
	CAchievementsStateButton(XConsole *parent, int x, int y, int state_, bool primary_);

	void unknown7ed5e0(int mode);	// NOTE: placeholder name

	int state;	// NOTE: placeholder name
	bool primary;	// NOTE: placeholder name
};

CAchievementsStateButton::CAchievementsStateButton(XConsole *parent, int x, int y, int state_, bool primary_)
	: Console(parent,0x11,1,x,y,0,false,-1)
{
	state = state_;
	primary = primary_;
	print(2,0,primary ? gameStrings_d20af8[state] : gameStrings_d304d0[state]);
	unknown7ed5e0((primary ? opW5_achievementState_d28d84 : opW5_achievementState_d28d88) == state);
}

class CAchievements : public Console
{
public:
	virtual ~CAchievements();

	void setPrimaryState(int state);	// NOTE: placeholder name
	void setSecondaryState(int state);	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
	vector<Console*> unknown70;	// NOTE: placeholder name
	vector<CAchievementsStateButton*> primaryButtons;	// NOTE: placeholder name
	vector<CAchievementsStateButton*> secondaryButtons;	// NOTE: placeholder name
};
extern CAchievements *opW5_achievements;	// NOTE: placeholder name (0xcec048)

CAchievements::~CAchievements()
{
	opW5_achievements = NULL;
}

void CAchievements::setPrimaryState(int state)
{
	primaryButtons[opW5_achievementState_d28d84]->unknown7ed5e0(2);
	opW5_achievementState_d28d84 = state;
	primaryButtons[state]->unknown7ed5e0(1);
}

void CAchievements::setSecondaryState(int state)
{
	secondaryButtons[opW5_achievementState_d28d88]->unknown7ed5e0(2);
	opW5_achievementState_d28d88 = state;
	secondaryButtons[state]->unknown7ed5e0(1);
}

//==================================================================
// CSupportersText / CSupporterCountButton
//==================================================================

class CSupportersText : public Console
{
public:
	CSupportersText(XConsole *parent, int x, int y, int width, int height, int unknown6c_, int unknown70_);

	int unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
};

CSupportersText::CSupportersText(XConsole *parent, int x, int y, int width, int height, int unknown6c_, int unknown70_)
	: Console(parent,width,height,x,y,0,false,-1)
{
	unknown6c = unknown6c_;
	unknown70 = unknown70_;
}

class CSupporterCountButton : public Console
{
public:
	CSupporterCountButton(XConsole *parent, int x, int y, bool flag);

	bool unknown6c;	// NOTE: placeholder name
};

CSupporterCountButton::CSupporterCountButton(XConsole *parent, int x, int y, bool flag)
	: Console(parent,5,1,x,y,0,false,-1)
{
	unknown6c = flag;
	setFore(*opW5_color_d2981c);
}

class CSupporterCounts : public Console
{
public:
	CSupporterCounts(XConsole *parent, int x, int y);
};

CSupporterCounts::CSupporterCounts(XConsole *parent, int x, int y)
	: Console(parent,15,3,x,y,0,false,10)
{
	new CSupporterCountButton(this,2,1,true);
	new CSupporterCountButton(this,8,1,false);
	putChar_418110(getWidth() / 2,1,'|',*opW5_color_cf6b24);
	animate("CSupporterCounts_Border");
}

class CSupporters : public Console
{
public:
	virtual ~CSupporters();

	int unknown6c;	// NOTE: placeholder name
	vector<Console*> unknown70;	// NOTE: placeholder name
	int unknown80;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	vector<Console*> unknown88;	// NOTE: placeholder name
};
extern CSupporters *opW5_supporters;	// NOTE: placeholder name (0xcec04c)

CSupporters::~CSupporters()
{
	opW5_supporters = NULL;
}

//==================================================================
// CAlert
//==================================================================

extern bool opW5_bigFont;	// NOTE: placeholder name (config.bigFont, 0xd28d15)
extern string gameStrings_d1d408[];	// NOTE: placeholder name
extern XColor *opW5_color_cf13fc;	// NOTE: placeholder name
extern XColor *opW5_color_d22130;	// NOTE: placeholder name
extern XColor *opW5_color_d20438;	// NOTE: placeholder name
extern XColor *opW5_color_d204ac;	// NOTE: placeholder name

class CAlert : public Console
{
public:
	CAlert(XConsole *parent, int alert_, bool warning_);
	virtual ~CAlert();

	int getAlertWidth(int alert_, bool warning_);	// NOTE: placeholder name
	void draw();	// NOTE: placeholder name

	unsigned int endTime;	// NOTE: placeholder name
	int alert;	// NOTE: placeholder name
	bool warning;	// NOTE: placeholder name
};

CAlert::~CAlert()
{
}

CAlert::CAlert(XConsole *parent, int alert_, bool warning_)
	: Console(parent,getAlertWidth(alert_,warning_),3,0,0,opW5_bigFont ? 1 : 2,true,0x14)
{
	endTime = tickCount + 5000;
	alert = alert_;
	warning = warning_;
	draw();
}

int CAlert::getAlertWidth(int alert_, bool warning_)
{
	return (warning_ ? 20 : 18) + gameStrings_d1d408[alert_].size();
}

void CAlert::draw()
{
	if (getWidth() != getAlertWidth(alert,warning))
		resize(getAlertWidth(alert,warning),3);
	unknown7b0640(0,warning ? *opW5_color_cf13fc : *opW5_color_d22130,1,0);
	string text = " >>> " + gameStrings_d1d408[alert] + (warning ? " WARNING <<< " : " ALERT <<< ");
	print(1,1,text);
	setBackRow(1,1,text.size(),warning ? *opW5_color_d20438 : *opW5_color_d204ac);
	setForeRow(1,1,text.size(),*opW5_color_cfe674);
}

//==================================================================
// CMapModeLabel / CAudioLog / CAudioLogs
//==================================================================

class CMapModeLabel : public Console
{
public:
	CMapModeLabel(XConsole *parent, int mode_);
	virtual ~CMapModeLabel();

	void unknown7f48e0();	// NOTE: placeholder name

	int mode;	// NOTE: placeholder name
};

CMapModeLabel::~CMapModeLabel()
{
}

CMapModeLabel::CMapModeLabel(XConsole *parent, int mode_)
	: Console(parent,parent->getWidth() * ((opW5_bigFont != 0) + 1),1,0,0,opW5_bigFont ? 1 : 2,false,0x14)
{
	mode = mode_;
	unknown7f48e0();
}

string &padLeft(string &str, unsigned int width, char c);	// NOTE: placeholder name (0x408090)
extern XColor opW5_audioLogColors_cf1060[];	// NOTE: placeholder name
extern unsigned int opW5_unknown_d28fb8;	// NOTE: placeholder name
extern int opW5_unknown_caf144;	// NOTE: placeholder name

class CAudioLog : public Console
{
public:
	CAudioLog(XConsole *parent, int type_, int unknown70_, int number_, const string &name_);
	virtual ~CAudioLog();

	void draw();	// NOTE: placeholder name

	int type;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	int number;	// NOTE: placeholder name
	string name;	// NOTE: placeholder name
	unsigned int endTime;	// NOTE: placeholder name
};

CAudioLog::~CAudioLog()
{
}

CAudioLog::CAudioLog(XConsole *parent, int type_, int unknown70_, int number_, const string &name_)
	: Console(parent,1,1,0,0,0,false,-1),
	type(type_),
	unknown70(unknown70_),
	number(number_),
	name(name_),
	endTime(type_ >= 6 ? tickCount + opW5_unknown_d28fb8 : 0)
{
	if (type == 5)
		return;
	draw();
}

extern const char opW5_string_c19b50[];	// NOTE: placeholder name (" / "; the verifier only pairs pooled literals passed to string ctors)

void CAudioLog::draw()
{
	setFore(opW5_audioLogColors_cf1060[type]);
	string text = padLeft(intToString(number),4,' ') + opW5_string_c19b50 + name;
	resize(text.size(),1);
	print(0,0,text);
	XColor dim = opW5_audioLogColors_cf1060[type] * 0.5f;
	setFore_417f80(5,0,dim);
}

class CAudioLogs : public Console
{
public:
	CAudioLogs(XConsole *parent);
	virtual ~CAudioLogs();

	void removeLog(CAudioLog *log);	// NOTE: placeholder name
	void refresh(vector<struct OpW5_AudioEntry> &entries);	// NOTE: placeholder name
	void addLog(int ID, int number, const string &name);	// NOTE: placeholder name
	bool unknown7f5040();	// NOTE: placeholder name
	void unknown7f4f50();	// NOTE: placeholder name
	void layout();	// NOTE: placeholder name

	vector<CAudioLog*> logs;	// NOTE: placeholder name
	vector<int> pendingIDs;	// NOTE: placeholder name
	vector<int> pendingCounts;	// NOTE: placeholder name
};

CAudioLogs::CAudioLogs(XConsole *parent)
	: Console(parent,1,1,0,1,0,true,parent->getLayer_44a7d0() + 2)
{
	logs.push_back(new CAudioLog(this,5,opW5_unknown_caf144,0,""));
}

CAudioLogs::~CAudioLogs()
{
}

bool opW5_removeElement(vector<CAudioLog*> &values, CAudioLog *value);	// NOTE: placeholder name (0x9d51d0)

void CAudioLogs::removeLog(CAudioLog *log)
{
	removeSubconsole(log);
	opW5_removeElement(logs,log);
	unknown7f4f50();
	layout();
}

// NOTE: 0x499160; byte-identical, but the verifier cannot pair &opW5_audioLogColors_cf1060[5]
//	(a mid-array address in .bss), so it is not recorded as matched.
void CAudioLogs::layout()
{
	int height = logs.size();
	int width = 0;
	CAudioLog *title = NULL;
	for (unsigned int i = 0; i < logs.size(); i++)
	{
		if (logs[i]->type == 5)
			title = logs[i];
		else if (logs[i]->getWidth() > width)
			width = logs[i]->getWidth();
	}
	width++;
	if (width % opW5_unknown_caf128)
		width += opW5_unknown_caf128 - width % opW5_unknown_caf128;
	if (getWidth() != width || getHeight() != height)
	{
		resize(width,height);
		setPos(getParent()->getWidth() - width / opW5_unknown_caf128,getPos().y);
		setBackAll_418410(*opW5_color_cfe674);
		if (title)
		{
			if (title->getWidth() != width)
				title->resize(width,1);
			title->clear();
			title->setCharRow(1,0,width - 2,0x81,opW5_audioLogColors_cf1060[5]);
		}
	}
	for (unsigned int i = 0; i < logs.size(); i++)
		logs[i]->setPos(0,i);
}

class OpW5_Prop	// NOTE: placeholder name
{
public:
	const string &getName();	// NOTE: placeholder name (0x45c5b0)
	Pos &getPos_4184d0();	// NOTE: placeholder name (folded getter)
};

class OpW5_HProp	// NOTE: placeholder name
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
	OpW5_Prop *operator->() const;	// 0x9b64f0
};

struct OpW5_AudioSource	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	int ID;	// NOTE: placeholder name
	char pad8[0x3c - 8];
	int type;	// NOTE: placeholder name
};

struct OpW5_AudioEntry	// NOTE: placeholder name
{
	OpW5_HProp prop;	// NOTE: placeholder name
	OpW5_AudioSource *source;	// NOTE: placeholder name
	int count;	// NOTE: placeholder name
};

extern bool opW5_unknown_d28fb2;	// NOTE: placeholder name
void opW5_eraseAt(vector<CAudioLog*> &v, unsigned int &i);	// NOTE: placeholder name (0x9ce6d0)
void opW5_insertAt(vector<CAudioLog*> &v, int i, CAudioLog *e);	// NOTE: placeholder name (0x9dbdc0)
void opW5_eraseRange(vector<CAudioLog*> &v, int first, int last);	// NOTE: placeholder name (0x9e25a0)
void opW5_prepend(vector<CAudioLog*> &v, vector<CAudioLog*> &values);	// NOTE: placeholder name (0x9d46b0)

void CAudioLogs::refresh(vector<OpW5_AudioEntry> &entries)
{
	bool changed = false;
	for (unsigned int i = 0; i < logs.size(); i++)
	{
		if (logs[i]->type == 5)
			break;
		for (unsigned int j = 0; j < entries.size(); j++)
		{
			if (logs[i]->unknown70 == entries[j].source->ID)
			{
				if (logs[i]->number != entries[j].count)
				{
					if (entries[j].count < 10)
						break;
					logs[i]->number = entries[j].count;
					logs[i]->draw();
					changed = true;
				}
				goto nextLog;
			}
		}
		removeSubconsole(logs[i]);
		opW5_eraseAt(logs,i);
		changed = true;
nextLog:;
	}

	for (unsigned int i = 0; i < entries.size(); i++)
	{
		if (!opW5_unknown_d28fb2 && entries[i].source->type == 1)
			continue;
		for (unsigned int j = 0; j < logs.size(); j++)
		{
			if (entries[i].source->ID == logs[j]->unknown70)
				goto nextEntry;
		}
		if (entries[i].source->type && entries[i].count >= 10)
		{
			if (!unknown7f5040())
				break;
			opW5_insertAt(logs,0,new CAudioLog(this,entries[i].source->type,entries[i].source->ID,entries[i].count,entries[i].prop->getName()));
			changed = true;
		}
nextEntry:;
	}

	if (!changed)
		return;

	unknown7f4f50();
	if (logs.front()->type != 5)
	{
		vector<CAudioLog*> sorted;
		sorted.push_back(logs[0]);
		for (unsigned int i = 1; i < logs.size(); i++)
		{
			if (logs[i]->type == 5)
				break;
			if (logs[i]->number <= sorted.back()->number)
				sorted.push_back(logs[i]);
			else
			{
				for (unsigned int j = 0; j < sorted.size(); j++)
				{
					if (logs[i]->number > sorted[j]->number)
					{
						opW5_insertAt(sorted,j,logs[i]);
						break;
					}
				}
			}
		}
		opW5_eraseRange(logs,0,sorted.size() - 1);
		opW5_prepend(logs,sorted);
	}
	layout();
}

struct OpW5_AudioLogSource	// NOTE: placeholder name
{
	char pad0[0x3c];
	int type;	// NOTE: placeholder name
	char pad40[0x5c - 0x40];
	int count;	// NOTE: placeholder name
};
extern vector<OpW5_AudioLogSource*> opW5_audioLogSources;	// NOTE: placeholder name (0xcfd2ec)

bool opW5_contains(vector<int> &values, int value);	// NOTE: placeholder name (0x9db330)
int opW5_indexOf(vector<int> &values, int value);	// NOTE: placeholder name (0x9d4660)
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0

void CAudioLogs::addLog(int ID, int number, const string &name)
{
	if (!pendingIDs.empty() && opW5_contains(pendingIDs,ID))
	{
		int index = opW5_indexOf(pendingIDs,ID);
		pendingCounts[index]--;
		if (pendingCounts[index] == 0)
		{
			removeVectorElement(pendingIDs,index);
			removeVectorElement(pendingCounts,index);
		}
		return;
	}
	else if (opW5_audioLogSources[ID]->count)
	{
		pendingIDs.push_back(ID);
		pendingCounts.push_back(opW5_audioLogSources[ID]->count);
	}

	if (!unknown7f5040())
		return;

	CAudioLog *log = new CAudioLog(this,opW5_audioLogSources[ID]->type,ID,number,name);
	if (logs.size() == 1)
		logs.push_back(log);
	else
	{
		for (int i = logs.size() - 1; i >= 0; i--)
		{
			if (logs[i]->type == 5 || log->number <= logs[i]->number)
			{
				opW5_insertAt(logs,i + 1,log);
				break;
			}
		}
	}
	unknown7f4f50();
	layout();
}

//==================================================================
// CMap (vtable 0xc2efe4)
//==================================================================

struct OpW5_VecU	// NOTE: placeholder name (vector<unsigned int> dtor)
{
	~OpW5_VecU();
	char data[0x10];
};
struct OpW5_VecP	// NOTE: placeholder name (vector<Point> dtor)
{
	~OpW5_VecP();
	char data[0x10];
};
struct OpW5_VecH	// NOTE: placeholder name (vector<HExplosive> dtor)
{
	~OpW5_VecH();
	char data[0x10];
};
struct OpW5_M_9b5720	// NOTE: placeholder name
{
	~OpW5_M_9b5720();	// 0x9b5720
	char data[0x10];
};
struct OpW5_M_9b8b60	// NOTE: placeholder name
{
	~OpW5_M_9b8b60();	// 0x9b8b60
	char data[0x10];
};
struct OpW5_M_9b50a0	// NOTE: placeholder name
{
	~OpW5_M_9b50a0();	// 0x9b50a0
	char data[0x10];
};
struct OpW5_M_9b9680	// NOTE: placeholder name
{
	~OpW5_M_9b9680();	// 0x9b9680
	char data[0x10];
};
struct OpW5_M_9b9890	// NOTE: placeholder name
{
	~OpW5_M_9b9890();	// 0x9b9890
	char data[0x10];
};
struct OpW5_M_421750	// NOTE: placeholder name
{
	~OpW5_M_421750();	// 0x421750
	char data[0x20];
};
struct OpW5_M_49b810	// NOTE: placeholder name
{
	~OpW5_M_49b810();	// 0x49b810
	char data[0x58];
};

class OpW5_CMap : public Console	// NOTE: placeholder name (CMap)
{
public:
	virtual ~OpW5_CMap();

	void unknown7fe7a0();	// NOTE: placeholder name

	char pad6c[0x7c - 0x6c];
	OpW5_M_9b5720 unknown7c;	// NOTE: placeholder name
	char pad8c[0x98 - 0x8c];
	OpW5_VecP unknown98;	// NOTE: placeholder name
	OpW5_VecU unknowna8;	// NOTE: placeholder name
	OpW5_VecU unknownb8;	// NOTE: placeholder name
	char padc8[0x100 - 0xc8];
	OpW5_VecP unknown100;	// NOTE: placeholder name
	char pad110[0x124 - 0x110];
	OpW5_VecU unknown124;	// NOTE: placeholder name
	char pad134[0x138 - 0x134];
	OpW5_VecP unknown138;	// NOTE: placeholder name
	char pad148[0x168 - 0x148];
	OpW5_M_9b5720 unknown168;	// NOTE: placeholder name
	OpW5_M_9b8b60 unknown178;	// NOTE: placeholder name
	OpW5_M_9b50a0 unknown188;	// NOTE: placeholder name
	OpW5_VecU unknown198;	// NOTE: placeholder name
	OpW5_VecU unknown1a8;	// NOTE: placeholder name
	char pad1b8[0x1c8 - 0x1b8];
	OpW5_VecU unknown1c8;	// NOTE: placeholder name
	OpW5_VecU unknown1d8;	// NOTE: placeholder name
	char pad1e8[0x218 - 0x1e8];
	OpW5_VecH unknown218;	// NOTE: placeholder name
	char pad228[0x22c - 0x228];
	OpW5_VecH unknown22c;	// NOTE: placeholder name
	OpW5_VecU unknown23c;	// NOTE: placeholder name
	OpW5_VecU unknown24c;	// NOTE: placeholder name
	OpW5_VecH unknown25c;	// NOTE: placeholder name
	OpW5_VecU unknown26c;	// NOTE: placeholder name
	OpW5_M_9b5720 unknown27c;	// NOTE: placeholder name
	OpW5_VecU unknown28c;	// NOTE: placeholder name
	OpW5_VecP unknown29c;	// NOTE: placeholder name
	OpW5_VecP unknown2ac;	// NOTE: placeholder name
	OpW5_M_9b9680 unknown2bc;	// NOTE: placeholder name
	OpW5_M_9b9890 unknown2cc;	// NOTE: placeholder name
	OpW5_VecP unknown2dc;	// NOTE: placeholder name
	OpW5_VecP unknown2ec;	// NOTE: placeholder name
	OpW5_VecU unknown2fc;	// NOTE: placeholder name
	OpW5_VecU unknown30c;	// NOTE: placeholder name
	OpW5_VecU unknown31c;	// NOTE: placeholder name
	OpW5_VecU unknown32c;	// NOTE: placeholder name
	OpW5_M_9b50a0 unknown33c;	// NOTE: placeholder name
	OpW5_M_9b50a0 unknown34c;	// NOTE: placeholder name
	OpW5_VecU unknown35c;	// NOTE: placeholder name
	char pad36c[0x3a8 - 0x36c];
	OpW5_VecP unknown3a8;	// NOTE: placeholder name
	OpW5_VecU unknown3b8;	// NOTE: placeholder name
	OpW5_VecP unknown3c8;	// NOTE: placeholder name
	char pad3d8[0x3e4 - 0x3d8];
	OpW5_M_9b50a0 unknown3e4;	// NOTE: placeholder name
	OpW5_VecP unknown3f4;	// NOTE: placeholder name
	OpW5_VecU unknown404;	// NOTE: placeholder name
	char pad414[0x420 - 0x414];
	OpW5_VecU unknown420;	// NOTE: placeholder name
	OpW5_VecU unknown430;	// NOTE: placeholder name
	OpW5_VecU unknown440;	// NOTE: placeholder name
	char pad450[0x460 - 0x450];
	OpW5_VecU unknown460;	// NOTE: placeholder name
	OpW5_M_421750 unknown470;	// NOTE: placeholder name
	OpW5_VecP unknown490;	// NOTE: placeholder name
	OpW5_VecU unknown4a0;	// NOTE: placeholder name
	char pad4b0[0x4b4 - 0x4b0];
	OpW5_VecU unknown4b4;	// NOTE: placeholder name
	char pad4c4[0x4dc - 0x4c4];
	OpW5_VecP unknown4dc;	// NOTE: placeholder name
	OpW5_VecU unknown4ec;	// NOTE: placeholder name
	OpW5_VecU unknown4fc;	// NOTE: placeholder name
	OpW5_M_9b50a0 unknown50c;	// NOTE: placeholder name
	char pad51c[0x520 - 0x51c];
	OpW5_VecU unknown520;	// NOTE: placeholder name
	OpW5_VecP unknown530;	// NOTE: placeholder name
	char pad540[0x544 - 0x540];
	OpW5_VecP unknown544;	// NOTE: placeholder name
	char pad554[0x600 - 0x554];
	OpW5_VecH unknown600;	// NOTE: placeholder name
	char pad610[0x66c - 0x610];
	OpW5_VecH unknown66c;	// NOTE: placeholder name
	char pad67c[0x688 - 0x67c];
	OpW5_VecH unknown688;	// NOTE: placeholder name
	char pad698[0x69c - 0x698];
	OpW5_VecH unknown69c;	// NOTE: placeholder name
	char pad6ac[0x6b0 - 0x6ac];
	OpW5_M_49b810 unknown6b0;	// NOTE: placeholder name
	OpW5_M_9b5720 unknown708;	// NOTE: placeholder name
	char pad718[0x730 - 0x718];
	OpW5_VecP unknown730;	// NOTE: placeholder name
	OpW5_VecU unknown740;	// NOTE: placeholder name
	char pad750[0x774 - 0x750];
	OpW5_VecP unknown774;	// NOTE: placeholder name
	char pad784[0x798 - 0x784];
	OpW5_VecU unknown798;	// NOTE: placeholder name
	char pad7a8[0x7b0 - 0x7a8];
	OpW5_VecU unknown7b0;	// NOTE: placeholder name
	OpW5_VecP unknown7c0;	// NOTE: placeholder name
	OpW5_VecP unknown7d0;	// NOTE: placeholder name
	OpW5_VecU unknown7e0;	// NOTE: placeholder name
	char pad7f0[0x7fc - 0x7f0];
	OpW5_Buffer88 unknown7fc;	// NOTE: placeholder name
	OpW5_Buffer88 unknown808;	// NOTE: placeholder name
	OpW5_Buffer88 unknown814;	// NOTE: placeholder name
	OpW5_Buffer88 unknown820;	// NOTE: placeholder name
	OpW5_Buffer88 unknown82c;	// NOTE: placeholder name
	char pad838[0x840 - 0x838];
	OpW5_VecU unknown840;	// NOTE: placeholder name
	char pad850[0x854 - 0x850];
	OpW5_VecU unknown854;	// NOTE: placeholder name
	char pad864[0x874 - 0x864];
	OpW5_VecU unknown874;	// NOTE: placeholder name
	char pad884[0x888 - 0x884];
	OpW5_VecU unknown888;	// NOTE: placeholder name
	char pad898[0x89c - 0x898];
	OpW5_VecU unknown89c;	// NOTE: placeholder name
};

OpW5_CMap::~OpW5_CMap()
{
	unknown7fe7a0();
}

//==================================================================
// CMap labels
//==================================================================

class OpW5_Entity	// NOTE: placeholder name
{
public:
	Pos &getPosition();	// 0x45a4a0
	int *unknown45a840();	// NOTE: placeholder name
	int getField9fcd80();	// NOTE: placeholder name (folded getter)
	unsigned int unknown5cb830(vector<class OpW5_HItem2> *out);	// NOTE: placeholder name
	unsigned int unknown5cb8b0(vector<class OpW5_HItem2> *out);	// NOTE: placeholder name
};

class OpW5_Item	// NOTE: placeholder name
{
public:
	int getType_44aec0();	// NOTE: placeholder name (folded getter)
	Pos &unknown575920();	// NOTE: placeholder name
	XColor *getColor577260();	// NOTE: placeholder name
	struct OpW5_ItemData *getData_9b4350();	// NOTE: placeholder name (folded +8 getter)
	int getField4578a0();	// NOTE: placeholder name (folded getter)
	int getField457820();	// NOTE: placeholder name (folded getter)
	int getField9b6bf0();	// NOTE: placeholder name (folded getter)
	string getName_571db0(int a, int b);	// NOTE: placeholder name
};

class OpW5_HEntity	// NOTE: placeholder name (HEntity)
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
	OpW5_Entity *operator->() const;	// 0x9b6570
	bool operator==(OpW5_HEntity other) const;	// NOTE: shared handle compare
	bool isNull() const;	// 0x9b65d0
	void reset();	// 0x9b7270
};

class OpW5_HItem	// NOTE: placeholder name (HItem)
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
	OpW5_Item *operator->() const;	// 0x9b65b0
};

class OpW5_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	OpW5_HEntity getPlayer();	// 0x4630f0
	OpW5_HEntity getEntity671();	// NOTE: placeholder name (0x463110)
	int getTurn();	// 0x464270
	bool unknown4631f0(OpW5_HEntity entity);	// NOTE: placeholder name
	int unknown464290();	// NOTE: placeholder name
	bool unknown735240(const Pos &pos, OpW5_HEntity entity);	// NOTE: placeholder name
};
extern OpW5_World *opW5_world;	// NOTE: placeholder name

struct OpW5_MapLabel;
class OpW5_Map	// NOTE: placeholder name (CMap at 0xcec054)
{
public:
	void removeLabel(OpW5_MapLabel *label);	// NOTE: placeholder name (0x49b070)
	Pos *getOffset();	// NOTE: placeholder name (0x458ef0)
	bool unknown8052f0(const Pos &pos);	// NOTE: placeholder name
};
extern OpW5_Map *opW5_map;	// NOTE: placeholder name

struct OpW5_MapLabel	// NOTE: placeholder name
{
	void update();	// NOTE: placeholder name
	void fade();	// NOTE: placeholder name

	int type;	// NOTE: placeholder name
	Console *console;	// NOTE: placeholder name
	bool unknown8;	// NOTE: placeholder name
	unsigned int fadeTime;	// NOTE: placeholder name
	bool fading;	// NOTE: placeholder name
	Pos offset;	// NOTE: placeholder name
	OpW5_HEntity entity;	// NOTE: placeholder name
	OpW5_HProp prop;	// NOTE: placeholder name
	OpW5_HItem item;	// NOTE: placeholder name
	Pos pos;	// NOTE: placeholder name
	bool checkVisible;	// NOTE: placeholder name
	bool checkFov;	// NOTE: placeholder name
};

void OpW5_MapLabel::update()
{
	if (fadeTime && tickCount >= fadeTime)
		opW5_map->removeLabel(this);
	else if (fadeTime && !fading && fadeTime < tickCount + 200)
		fade();
	else if (entity.isValid())
	{
		if (!entity.operator->() || (checkVisible && !opW5_world->unknown4631f0(entity)))
			opW5_map->removeLabel(this);
		else
		{
			Pos entityPos = entity->getPosition();
			if (checkFov && !opW5_world->unknown735240(entityPos,entity))
			{
				opW5_map->removeLabel(this);
				return;
			}
			Pos p = entityPos + pos + *opW5_map->getOffset() + offset;
			if (console->getPos() != p)
				console->setPos(p);
		}
	}
	else if (prop.isValid())
	{
		if (prop.operator->())
		{
			Pos p = prop->getPos_4184d0() + *opW5_map->getOffset() + offset;
			if (console->getPos() != p)
				console->setPos(p);
		}
		else
			opW5_map->removeLabel(this);
	}
	else if (item.isValid())
	{
		if (item.operator->() && item->getType_44aec0() == 5)
		{
			Pos p = item->unknown575920() + *opW5_map->getOffset() + offset;
			if (console->getPos() != p)
				console->setPos(p);
		}
		else
			opW5_map->removeLabel(this);
	}
	else if (pos.x != -1)
	{
		if (type == 8 || type == 10)
			console->setHidden(opW5_map->unknown8052f0(pos));
		else
		{
			Pos p = pos + *opW5_map->getOffset() + offset;
			if (console->getPos() != p)
				console->setPos(p);
		}
	}
}

void OpW5_MapLabel::fade()
{
	fading = true;
	fadeTime = tickCount + 200;
	console->engine->stopAll();
	console->animate("A_CMap_Label_Fade");
	for (unsigned int i = 0; i < console->getSubconsoles()->size(); i++)
	{
		((Console*)(*console->getSubconsoles())[i])->engine->stopAll();
		((Console*)(*console->getSubconsoles())[i])->animate("A_CMap_Label_Fade");
	}
}

struct OpW5_EntityMark	// NOTE: placeholder name
{
	OpW5_EntityMark(OpW5_HEntity entity_);

	OpW5_HEntity entity;	// NOTE: placeholder name
	Pos pos;	// NOTE: placeholder name
	unsigned int time;	// NOTE: placeholder name
};

OpW5_EntityMark::OpW5_EntityMark(OpW5_HEntity entity_)
	: entity(entity_),
	pos(entity_->getPosition()),
	time(tickCount)
{
}

struct OpW5_PosMark	// NOTE: placeholder name
{
	OpW5_PosMark(const Pos &pos_, int value_, bool flag_);

	Pos pos;	// NOTE: placeholder name
	int value;	// NOTE: placeholder name
	bool flag;	// NOTE: placeholder name
	unsigned int time;	// NOTE: placeholder name
};

OpW5_PosMark::OpW5_PosMark(const Pos &pos_, int value_, bool flag_)
	: pos(pos_),
	value(value_),
	flag(flag_),
	time(tickCount)
{
}

struct OpW5_PosMark2	// NOTE: placeholder name
{
	OpW5_PosMark2(const Pos &pos_, int value_);

	Pos pos;	// NOTE: placeholder name
	int value;	// NOTE: placeholder name
	unsigned int time;	// NOTE: placeholder name
};

OpW5_PosMark2::OpW5_PosMark2(const Pos &pos_, int value_)
	: pos(pos_),
	value(value_),
	time(tickCount)
{
}

//==================================================================
// CMap label queries
//==================================================================

template <class T> void opW5_deleteAt(vector<T*> &v, int &index);	// NOTE: placeholder name (0x9d4840)
template <class T> void opW5_deleteIndex(vector<T*> &v, int index);	// NOTE: placeholder name (0x9d47d0)
bool opW5_between(int lo, int v, int hi);	// NOTE: placeholder name (0x9daf80)

class OpW5_MapView	// NOTE: placeholder name (CMap)
{
public:
	bool unknown49aa20();	// NOTE: placeholder name
	bool unknown49b0c0(int type);	// NOTE: placeholder name
	bool hasActiveLabel(int type);	// NOTE: placeholder name
	bool hasEntityLabel(int type, OpW5_HEntity entity);	// NOTE: placeholder name
	bool hasPosLabel(int type, const Pos &pos);	// NOTE: placeholder name
	bool hasPropLabel(int type, OpW5_HEntity prop);	// NOTE: placeholder name
	bool hasItemLabel(OpW5_HEntity item);	// NOTE: placeholder name
	void removeLabels(int type);	// NOTE: placeholder name
	void removeMarker(const Pos &pos);	// NOTE: placeholder name
	bool hasAnyLabel4to7();	// NOTE: placeholder name
	bool labelsFading();	// NOTE: placeholder name
	void addPosMark(const Pos &pos, int value, bool flag);	// NOTE: placeholder name
	void unknown49b670();	// NOTE: placeholder name
	void unknown49b740();	// NOTE: placeholder name
	void toggle850();	// NOTE: placeholder name
	void toggle870();	// NOTE: placeholder name

	char pad0[0x1d8];
	vector<OpW5_MapLabel*> labels;	// NOTE: placeholder name
	char pad1e8[0x32c - 0x1e8];
	vector<OpW5_PosMark*> posMarks;	// NOTE: placeholder name
	char pad33c[0x4c4 - 0x33c];
	bool unknown4c4;	// NOTE: placeholder name
	char pad4c5[0x5e4 - 0x4c5];
	unsigned int unknown5e4;	// NOTE: placeholder name
	char pad5e8[0x680 - 0x5e8];
	int unknown680;	// NOTE: placeholder name
	char pad684[0x794 - 0x684];
	unsigned int unknown794;	// NOTE: placeholder name
	char pad798[0x850 - 0x798];
	bool unknown850;	// NOTE: placeholder name
	char pad851[0x870 - 0x851];
	bool unknown870;	// NOTE: placeholder name
};

void OpW5_MapView::unknown49b740()
{
	unknown5e4 = tickCount;
}

void OpW5_MapView::toggle850()
{
	unknown850 = !unknown850;
}

void OpW5_MapView::toggle870()
{
	unknown870 = !unknown870;
}

bool OpW5_MapView::unknown49aa20()
{
	return unknown4c4 && unknown680 == 8;
}

bool OpW5_MapView::hasActiveLabel(int type)
{
	for (unsigned int i = 0; i < labels.size(); i++)
	{
		if (labels[i]->type == type && !labels[i]->unknown8)
			return true;
	}
	return false;
}

bool OpW5_MapView::hasEntityLabel(int type, OpW5_HEntity entity)
{
	for (unsigned int i = 0; i < labels.size(); i++)
	{
		if (labels[i]->type == type && labels[i]->entity == entity)
			return true;
	}
	return false;
}

bool OpW5_MapView::hasPosLabel(int type, const Pos &pos)
{
	for (unsigned int i = 0; i < labels.size(); i++)
	{
		if (labels[i]->type == type && labels[i]->pos == pos)
			return true;
	}
	return false;
}

bool OpW5_MapView::hasPropLabel(int type, OpW5_HEntity prop)
{
	for (unsigned int i = 0; i < labels.size(); i++)
	{
		if (labels[i]->type == type && ((OpW5_HEntity&)labels[i]->prop) == prop)
			return true;
	}
	return false;
}

bool OpW5_MapView::hasItemLabel(OpW5_HEntity item)
{
	for (unsigned int i = 0; i < labels.size(); i++)
	{
		if (((OpW5_HEntity&)labels[i]->item) == item)
			return true;
	}
	return false;
}

void OpW5_MapView::removeLabels(int type)
{
	for (int i = 0; i < labels.size(); i++)
	{
		if (labels[i]->type == type)
			opW5_deleteAt(labels,i);
	}
}

void OpW5_MapView::removeMarker(const Pos &pos)
{
	for (int i = 0; i < labels.size(); i++)
	{
		if (labels[i]->type == 15 && labels[i]->pos == pos)
		{
			opW5_deleteIndex(labels,i);
			break;
		}
	}
}

bool OpW5_MapView::hasAnyLabel4to7()
{
	for (int i = 4; i <= 7; i++)
	{
		if (unknown49b0c0(i))
			return true;
	}
	return false;
}

bool OpW5_MapView::labelsFading()
{
	for (unsigned int i = 0; i < labels.size(); i++)
	{
		if (opW5_between(4,labels[i]->type,7) && !labels[i]->fading)
			return false;
	}
	return true;
}

void OpW5_MapView::addPosMark(const Pos &pos, int value, bool flag)
{
	posMarks.push_back(new OpW5_PosMark(pos,value,flag));
}

void OpW5_MapView::unknown49b670()
{
	unknown794 = tickCount;
}

//==================================================================
// more CMap setters
//==================================================================

class OpW5_MapView2	// NOTE: placeholder name (CMap)
{
public:
	void setUnknown38c(const Pos &pos);	// NOTE: placeholder name
	void setPath(const Pos &pos, int value, const vector<OpW5_Point> &path_);	// NOTE: placeholder name

	char pad0[0x38c];
	Pos unknown38c;	// NOTE: placeholder name
	unsigned int unknown394;	// NOTE: placeholder name
	unsigned int unknown398;	// NOTE: placeholder name
	Pos unknown39c;	// NOTE: placeholder name
	int unknown3a4;	// NOTE: placeholder name
	vector<OpW5_Point> path;	// NOTE: placeholder name
	vector<int> pathState;	// NOTE: placeholder name
};

void OpW5_MapView2::setUnknown38c(const Pos &pos)
{
	unknown38c = pos;
	unknown394 = tickCount;
}

void OpW5_MapView2::setPath(const Pos &pos, int value, const vector<OpW5_Point> &path_)
{
	unknown398 = tickCount;
	unknown39c = pos;
	unknown3a4 = value;
	path = path_;
	pathState.assign(path.size(),0);
}

template <class T> bool opW5_contains_9d31e0(vector<T> &v, T value);	// NOTE: placeholder name

class OpW5_Unk49b830	// NOTE: placeholder name
{
public:
	bool addUnique(void *value);	// NOTE: placeholder name

	char pad0[0xc];
	vector<void*> values;	// NOTE: placeholder name
};

bool OpW5_Unk49b830::addUnique(void *value)
{
	if (opW5_contains_9d31e0(values,value))
		return false;
	values.push_back(value);
	return true;
}

//==================================================================
// global at 0xb59588 init
//==================================================================

class OpW5_HPropD	// NOTE: placeholder name (HProp)
{
public:
	OpW5_HPropD() throw();	// 0x9b6590 (HProp::HProp)
	int ID;
};

struct OpW5_VecA	// NOTE: placeholder name
{
	OpW5_VecA() throw();
	~OpW5_VecA();	// vector<HExplosive> dtor
	char data[0x10];
};

struct OpW5_VecB	// NOTE: placeholder name
{
	OpW5_VecB() throw();
	~OpW5_VecB();	// 0x9b50a0
	char data[0x10];
};

struct OpW5_VecC	// NOTE: placeholder name
{
	OpW5_VecC() throw();
	~OpW5_VecC();	// vector<unsigned> dtor
	char data[0x10];
};

struct OpW5_GlobalState	// NOTE: placeholder name
{
	OpW5_GlobalState();
	~OpW5_GlobalState();

	int unknown0;	// NOTE: placeholder name
	int unknown4;	// NOTE: placeholder name
	OpW5_HPropD unknown8;	// NOTE: placeholder name
	OpW5_VecA unknownc;	// NOTE: placeholder name
	OpW5_Point unknown1c;	// NOTE: placeholder name
	char pad24[0x30 - 0x24];
	OpW5_HPropD unknown30;	// NOTE: placeholder name
	char pad34[0x3c - 0x34];
	OpW5_Point unknown3c;	// NOTE: placeholder name
	OpW5_HPropD unknown44;	// NOTE: placeholder name
	char pad48[0x50 - 0x48];
	OpW5_VecB unknown50;	// NOTE: placeholder name
	OpW5_Point unknown60;	// NOTE: placeholder name
	OpW5_Point unknown68;	// NOTE: placeholder name
	OpW5_Point unknown70;	// NOTE: placeholder name
	char pad78[0x7c - 0x78];
	OpW5_HPropD unknown7c;	// NOTE: placeholder name
	char pad80[0x84 - 0x80];
	OpW5_HPropD unknown84;	// NOTE: placeholder name
	char pad88[0xa0 - 0x88];
	OpW5_VecC unknowna0;	// NOTE: placeholder name
};

OpW5_GlobalState::OpW5_GlobalState()
{
}

OpW5_GlobalState::~OpW5_GlobalState()
{
}

//==================================================================
// CToggleSpriteMode
//==================================================================

class CToggleSpriteMode : public Console
{
public:
	CToggleSpriteMode(XConsole *parent);

	virtual void update();
};

CToggleSpriteMode::CToggleSpriteMode(XConsole *parent)
	: Console(parent,parent->getWidth(),parent->getHeight(),0,0,opW5_bigFont ? 3 : 2,false,-1)
{
	parent->unknown429fe0(this,Pos(0,0),0);
	animate("A_CSpriteMode");
}

//==================================================================
// CAchievementPopup
//==================================================================

class AsciiImage;

class CArtAnimated : public Console
{
public:
	CArtAnimated(XConsole *parent, AsciiImage *image, int x, int y, bool flag, int animation, int a, int b, const Pos &pos, int c, int d);
	void unknown4b29b0();	// NOTE: placeholder name

	char pad6c[0x88 - 0x6c];
};

struct OpW5_Achievement	// NOTE: placeholder name
{
	char pad0[0x20];
	string name;	// NOTE: placeholder name
	char pad3c[0x40 - 0x3c];
	int category;	// NOTE: placeholder name
	char pad44[0x6c - 0x44];
	char image[0x10];	// NOTE: placeholder layout (AsciiImage)
};
extern vector<OpW5_Achievement*> opW5_achievementData;	// NOTE: placeholder name (0xcf09a8)
extern unsigned int opW5_achievementPopupTime;	// NOTE: placeholder name (0xd28f68)
bool opW5_isOdd_406320(int value);	// NOTE: placeholder name

class CAchievementPopup : public Console
{
public:
	CAchievementPopup(XConsole *parent, int index_);
	virtual ~CAchievementPopup();

	int getNameWidth(int index);	// NOTE: placeholder name
	int getWidth_49bcb0(int index);	// NOTE: placeholder name
	void draw();	// NOTE: placeholder name

	unsigned int endTime;	// NOTE: placeholder name
	int index;	// NOTE: placeholder name
};

CAchievementPopup::CAchievementPopup(XConsole *parent, int index_)
	: Console(parent,getWidth_49bcb0(index_),5,0,0,0,false,0x14)
{
	endTime = tickCount + opW5_achievementPopupTime;
	index = index_;
	resetBack_418450();
	draw();
	int animation;
	opW5_findAnimation("A_CMap_Achieve_Icon_" + gameStrings_d15db0[opW5_achievementData[index]->category],&animation);
	CArtAnimated *art = new CArtAnimated(this,(AsciiImage*)opW5_achievementData[index]->image,getWidth() - 11,0,false,animation,-1,-1,Pos(-1),0,0);
	art->resetBack_418450();
	art->unknown4b29b0();
}

CAchievementPopup::~CAchievementPopup()
{
}

int CAchievementPopup::getNameWidth(int index)
{
	return opW5_achievementData[index]->name.size() + 13;
}

int CAchievementPopup::getWidth_49bcb0(int index)
{
	int width = getNameWidth(index);
	return opW5_isOdd_406320(width) ? width : width + 1;
}

void CAchievementPopup::draw()
{
	print(opW5_isOdd_406320(getNameWidth(index)) ? 1 : 2,2,opW5_achievementData[index]->name);
	animate("A_CMap_Achieve_Name_" + gameStrings_d15db0[opW5_achievementData[index]->category]);
	animate("A_CMap_Achieve_Sfx");
}

//==================================================================
// CMapFine (vtable 0xc352e8)
//==================================================================

extern bool opW5_unknown_cefa77;	// NOTE: placeholder name
extern int opW5_unknown_cf27ec;	// NOTE: placeholder name
extern int opW5_unknown_cf27f0;	// NOTE: placeholder name
extern int opW5_unknown_d28f78;	// NOTE: placeholder name

template <class T> int opW5_find_9d4660(vector<T> &v, T value);	// NOTE: placeholder name
template <class T> void opW5_deleteIndex_9d48c0(vector<T*> &v, int index);	// NOTE: placeholder name
template <class T> void opW5_deleteIndex_9d4950(vector<T*> &v, int index);	// NOTE: placeholder name
template <class T> void opW5_deleteAll_9d4930(vector<T*> &v);	// NOTE: placeholder name

template <class T> struct OpW5_FineVector : public vector<T>	// NOTE: placeholder name
{
	OpW5_FineVector() throw();	// 0x9b8e80
	~OpW5_FineVector();	// vector<unsigned int> dtor
};

class CMapFine;
extern CMapFine *opW5_mapFine;	// NOTE: placeholder name (0xcec058)

struct OpW5_FineMessage	// NOTE: placeholder name
{
	OpW5_FineMessage(Console *console_, unsigned int time_, int a, int b, bool flag, Console *second_, unsigned int secondTime_);	// 0x49be20
	void remove();	// NOTE: placeholder name
	void update();	// NOTE: placeholder name

	Console *console;	// NOTE: placeholder name
	unsigned int time;	// NOTE: placeholder name
	int unknown8;	// NOTE: placeholder name
	int unknownc;	// NOTE: placeholder name
	bool unknown10;	// NOTE: placeholder name
	Console *second;	// NOTE: placeholder name
	unsigned int secondTime;	// NOTE: placeholder name
};

struct OpW5_FineBubble	// NOTE: placeholder name
{
	~OpW5_FineBubble();
	bool update();	// NOTE: placeholder name

	Console *console;	// NOTE: placeholder name
	unsigned int time;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
};

struct OpW5_FineTimer	// NOTE: placeholder name
{
	OpW5_FineTimer(int a, int b);

	int unknown0;	// NOTE: placeholder name
	int unknown4;	// NOTE: placeholder name
	unsigned int time;	// NOTE: placeholder name
};

class CMapFine : public Console
{
public:
	CMapFine(XConsole *parent);
	virtual ~CMapFine();

	virtual void update();
	virtual void render();	// NOTE: placeholder name

	void unknown874340();	// NOTE: placeholder name
	int getBottom_49c190();	// NOTE: placeholder name
	int getBottom_49c210();	// NOTE: placeholder name
	bool hasBubbles();	// NOTE: placeholder name
	void removeMessage(OpW5_FineMessage *message);	// NOTE: placeholder name
	void removeBubble(OpW5_FineBubble *bubble, int type);	// NOTE: placeholder name
	void clearBubbles(int type);	// NOTE: placeholder name
	void removeTimer(OpW5_FineTimer *timer);	// NOTE: placeholder name
	void setText(const string &text_);	// NOTE: placeholder name

	OpW5_FineVector<OpW5_FineMessage*> messages;	// NOTE: placeholder name
	OpW5_FineVector<OpW5_FineBubble*> bubbles0;	// NOTE: placeholder name
	OpW5_FineBubble *current0;	// NOTE: placeholder name
	OpW5_FineVector<OpW5_FineBubble*> bubbles1;	// NOTE: placeholder name
	OpW5_FineBubble *current1;	// NOTE: placeholder name
	OpW5_FineVector<OpW5_FineBubble*> bubbles2;	// NOTE: placeholder name
	OpW5_FineBubble *current2;	// NOTE: placeholder name
	OpW5_FineVector<OpW5_FineTimer*> timers;	// NOTE: placeholder name
	OpW5_FineVector<int> unknownc8;	// NOTE: placeholder name
	unsigned int textTime;	// NOTE: placeholder name
	Console *textConsole;	// NOTE: placeholder name
	string text;	// NOTE: placeholder name
};

void OpW5_FineMessage::remove()
{
	if (opW5_unknown_cefa77)
		return;
	((XConsole*)opW5_mapFine)->removeSubconsole(console);
	if (second)
		((XConsole*)opW5_mapFine)->removeSubconsole(second);
}

void OpW5_FineMessage::update()
{
	if (second && tickCount >= secondTime)
	{
		((XConsole*)opW5_mapFine)->removeSubconsole(second);
		second = NULL;
	}
	if (time && tickCount >= time)
		opW5_mapFine->removeMessage(this);
}

OpW5_FineBubble::~OpW5_FineBubble()
{
	if (opW5_unknown_cefa77)
		return;
	((XConsole*)opW5_mapFine)->removeSubconsole(console);
}

bool OpW5_FineBubble::update()
{
	if (time && tickCount >= time)
	{
		opW5_mapFine->removeBubble(this,type);
		return true;
	}
	return false;
}

OpW5_FineTimer::OpW5_FineTimer(int a, int b)
{
	unknown0 = a;
	unknown4 = b;
	time = tickCount + 2000;
}

CMapFine::CMapFine(XConsole *parent)
	: Console(parent,1,1,opW5_unknown_cf27ec,opW5_unknown_cf27f0,0,false,-1),
	current0(NULL),
	current1(NULL),
	current2(NULL)
{
	resetBack_418450();
}

CMapFine::~CMapFine()
{
	unknown874340();
}

int CMapFine::getBottom_49c190()
{
	if (current2)
		return current2->console->getPos().y + 1;
	else if (current1 && current1->console->getPos().x > 0)
		return current1->console->getPos().y + 1;
	else
		return 0;
}

int CMapFine::getBottom_49c210()
{
	if (current1)
	{
		if (current1->console->getPos().x > 0)
			return opW5_unknown_d28f78 + 1;
		else
			return current1->console->getPos().y + 1;
	}
	return 0;
}

bool CMapFine::hasBubbles()
{
	return !bubbles0.empty();
}

void CMapFine::removeMessage(OpW5_FineMessage *message)
{
	int index = opW5_find_9d4660(messages,message);
	if (index != -1)
		opW5_deleteIndex_9d48c0(messages,index);
}

void CMapFine::removeBubble(OpW5_FineBubble *bubble, int type)
{
	vector<OpW5_FineBubble*> *bubbleList;
	OpW5_FineBubble **currentBubble;
	switch (type)
	{
		case 0:
			bubbleList = &bubbles0;
			currentBubble = &current0;
			break;
		case 1:
			bubbleList = &bubbles1;
			currentBubble = &current1;
			break;
		case 2:
			bubbleList = &bubbles2;
			currentBubble = &current2;
			break;
	}
	if (*currentBubble == bubble)
	{
		delete *currentBubble;
		*currentBubble = NULL;
	}
	else
	{
		int index = opW5_find_9d4660(*bubbleList,bubble);
		if (index != -1)
			opW5_deleteIndex_9d4950(*bubbleList,index);
	}
}

void CMapFine::clearBubbles(int type)
{
	switch (type)
	{
		case 0:
			opW5_deleteAll_9d4930(bubbles0);
			delete current0;
			current0 = NULL;
			break;
		case 1:
			opW5_deleteAll_9d4930(bubbles1);
			delete current1;
			current1 = NULL;
			break;
		case 2:
			opW5_deleteAll_9d4930(bubbles2);
			delete current2;
			current2 = NULL;
			break;
	}
}

void CMapFine::removeTimer(OpW5_FineTimer *timer)
{
	int index = opW5_find_9d4660(timers,timer);
	if (index != -1)
		opW5_deleteIndex_9d4950(timers,index);
}

void CMapFine::setText(const string &text_)
{
	if (textConsole && textConsole)
	{
		removeSubconsole(textConsole);
		textConsole = NULL;
	}
	text = text_;
	textTime = tickCount;
}

//==================================================================
// CPay2Buy / CRpglike
//==================================================================

extern XConsole *opW5_mapConsole;	// NOTE: placeholder name (CMap at 0xcec054)
extern int opW5_unknown_caf12c;	// NOTE: placeholder name
extern int opW5_unknown_cefabc;	// NOTE: placeholder name
extern string opW5_string_d25df0;	// NOTE: placeholder name
extern string opW5_string_d2f138;	// NOTE: placeholder name
extern XColor *opW5_color_d25e0c;	// NOTE: placeholder name

class CPay2BuyButton : public Console
{
public:
	CPay2BuyButton(XConsole *parent);

	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
};

CPay2BuyButton::CPay2BuyButton(XConsole *parent)
	: Console(parent,opW5_string_d25df0.size(),1,0x1a,1,0,false,-1)
{
	setFore(*opW5_color_cf44c0);
	print(0,0,opW5_string_d25df0);
	setForeRow(1,0,3,*opW5_color_d2981c);
	setForeRow(6,0,1,*opW5_color_d2981c);
}

class CPay2Buy : public Console
{
public:
	CPay2Buy(XConsole *parent);
	virtual ~CPay2Buy();

	virtual void update();
	virtual void render();	// NOTE: placeholder name

	int getX_4a1c20();	// NOTE: placeholder name
	int getY();	// NOTE: placeholder name
	void unknown7b0640(int a, XColor color, int b, int c);	// NOTE: placeholder name
};

int CPay2Buy::getY()
{
	return opW5_mapConsole->getPos().y + opW5_mapConsole->getHeight() * opW5_unknown_caf12c - 3 - opW5_unknown_caf12c;
}

CPay2Buy::CPay2Buy(XConsole *parent)
	: Console(parent,Rect(getX_4a1c20(),getY(),37,3),0,false,3)
{
	new CPay2BuyButton(this);
	setFore(*opW5_color_d2981c);
	print(2,1,"CogCoins");
	setBackRow(0xb,1,3,*opW5_color_d25e0c);
	putChar_418110(0xc,1,'C',*opW5_color_cfe674);
	unknown7b0640(0,*opW5_color_cf6b24,1,0);
}

CPay2Buy::~CPay2Buy()
{
}

void CPay2Buy::update()
{
	if (isHidden())
		return;
	engine->isRunning();
	setPos(getX_4a1c20(),getY());
	XConsole::update();
}

class CRpglikeButton : public Console
{
public:
	CRpglikeButton(XConsole *parent);

	virtual bool input(void *event);
	virtual void update();

	void draw();	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
};

CRpglikeButton::CRpglikeButton(XConsole *parent)
	: Console(parent,opW5_string_d2f138.size(),1,0x23,1,0,false,-1)
{
	unknown6c = -1;
	setFore(*opW5_color_cf44c0);
	print(0,0,opW5_string_d2f138);
	draw();
}

void CRpglikeButton::draw()
{
	setForeRow(1,0,8,*opW5_color_d2981c);
	setForeRow(0xb,0,1,*opW5_color_d2981c);
}

class CRpglike : public Console
{
public:
	int getY();	// NOTE: placeholder name
};

int CRpglike::getY()
{
	return opW5_mapConsole->getPos().y + opW5_mapConsole->getHeight() * opW5_unknown_caf12c - opW5_unknown_caf12c - 4 - opW5_unknown_cefabc * opW5_unknown_caf12c;
}

//==================================================================
// CRpglike
//==================================================================

class CRpglikeFull : public Console	// NOTE: placeholder name (CRpglike, see CRpglike above)
{
public:
	CRpglikeFull(XConsole *parent);
	virtual ~CRpglikeFull();

	virtual void update();
	virtual void render();	// NOTE: placeholder name

	int getX_4a1c20();	// NOTE: placeholder name
	int getY();	// NOTE: placeholder name (0x49cb20)
	void unknown7b0640(int a, XColor color, int b, int c);	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
};

CRpglikeFull::CRpglikeFull(XConsole *parent)
	: Console(parent,Rect(getX_4a1c20(),getY(),52,4),0,false,3),
	unknown6c(0),
	unknown70(0),
	unknown74(0)
{
	new CRpglikeButton(this);
	setFore(*opW5_color_cfe674);
	print(2,1," LEVEL ");
	setBackRow(2,1,7,*opW5_color_d25e0c);
	print(0xd,1," XP ");
	setBackRow(0xd,1,4,*opW5_color_d25e0c);
	unknown7b0640(0,*opW5_color_cf6b24,1,0);
}

CRpglikeFull::~CRpglikeFull()
{
}

extern int opW5_upgrade_cf4954;	// NOTE: placeholder name
extern int opW5_upgrade_cf49dc;	// NOTE: placeholder name
extern int opW5_upgrade_cf49d8;	// NOTE: placeholder name
extern int opW5_upgrade_cf4970;	// NOTE: placeholder name
extern int opW5_upgrade_cf4974;	// NOTE: placeholder name
extern int opW5_upgrade_cf4978;	// NOTE: placeholder name
extern int opW5_upgrade_cf496c;	// NOTE: placeholder name
extern int opW5_upgrade_cf4960;	// NOTE: placeholder name
extern int opW5_upgrade_cf4964;	// NOTE: placeholder name
extern int opW5_upgrade_cf4968;	// NOTE: placeholder name
extern int opW5_upgrade_cf4958;	// NOTE: placeholder name
extern int opW5_upgrade_cf495c;	// NOTE: placeholder name
extern int opW5_upgrade_cf49e0;	// NOTE: placeholder name
extern int opW5_upgrade_cf49e8;	// NOTE: placeholder name
extern int opW5_upgrade_cf49a0;	// NOTE: placeholder name
extern int opW5_upgrade_cf49a4;	// NOTE: placeholder name
extern int opW5_upgrade_cf49a8;	// NOTE: placeholder name
extern int opW5_upgrade_cf49bc;	// NOTE: placeholder name
extern int opW5_upgrade_cf49c0;	// NOTE: placeholder name
extern int opW5_upgrade_cf49c4;	// NOTE: placeholder name

int *opW5_getUpgradeValue(int id)	// NOTE: placeholder name
{
	switch (id)
	{
		case 0:
		case 1:
		case 2:
		case 3:
			return &opW5_world->getPlayer()->unknown45a840()[id];
		case 4:
			return &opW5_upgrade_cf4954;
		case 5:
			return &opW5_upgrade_cf49dc;
		case 6:
			return &opW5_upgrade_cf49d8;
		case 7:
			return &opW5_upgrade_cf4970;
		case 8:
			return &opW5_upgrade_cf4974;
		case 9:
			return &opW5_upgrade_cf4978;
		case 10:
			return &opW5_upgrade_cf496c;
		case 11:
			return &opW5_upgrade_cf4960;
		case 12:
			return &opW5_upgrade_cf4964;
		case 13:
			return &opW5_upgrade_cf4968;
		case 14:
			return &opW5_upgrade_cf4958;
		case 15:
			return &opW5_upgrade_cf495c;
		case 16:
			return &opW5_upgrade_cf49e0;
		case 17:
			return &opW5_upgrade_cf49e8;
		case 18:
			return &opW5_upgrade_cf49a0;
		case 19:
			return &opW5_upgrade_cf49a4;
		case 20:
			return &opW5_upgrade_cf49a8;
		case 21:
			return &opW5_upgrade_cf49bc;
		case 22:
			return &opW5_upgrade_cf49c0;
		case 23:
			return &opW5_upgrade_cf49c4;
		default:
			return &opW5_upgrade_cf4954;
	}
}

struct OpW5_UpgradeInfo	// NOTE: placeholder name
{
	int base;	// NOTE: placeholder name
	int perLevel;	// NOTE: placeholder name
	int step;	// NOTE: placeholder name
	int unknownc;	// NOTE: placeholder name
};
extern OpW5_UpgradeInfo opW5_upgradeInfo[];	// NOTE: placeholder name (0xba7930)
// NOTE: the verifier pairs a data symbol only at offset 0, so the later columns of the table
//	are reached through views that start at that column
struct OpW5_UpgradeInfoView	// NOTE: placeholder name
{
	int value;
	int pad[3];
};
extern OpW5_UpgradeInfoView opW5_upgradePerLevel[];	// NOTE: placeholder name (0xba7934)
extern OpW5_UpgradeInfoView opW5_upgradeStep[];	// NOTE: placeholder name (0xba7938)

class OpW5_Stats_d2c658	// NOTE: placeholder name
{
public:
	int unknown472c70(int index);	// NOTE: placeholder name
};
extern OpW5_Stats_d2c658 opW5_stats_d2c658;	// NOTE: placeholder name

int opW5_getUpgradeCost(int id, int offset)	// NOTE: placeholder name
{
	int level;
	if (!(level = opW5_stats_d2c658.unknown472c70(id + 0x429) + offset))
		return opW5_upgradeInfo[id].base;
	else
		return opW5_upgradeInfo[id].base + opW5_upgradePerLevel[id].value * level;
}

int opW5_getUpgradeAmount(int id, int count)	// NOTE: placeholder name
{
	if (count == 0)
		return *opW5_getUpgradeValue(id);
	int value = *opW5_getUpgradeValue(id);
	while (count != 0)
	{
		value += opW5_upgradeStep[id].value;
		count--;
	}
	return value;
}

class CRpglikeUpgradeButton : public Console
{
public:
	CRpglikeUpgradeButton(XConsole *parent, int x, int ID_, bool next_);

	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);

	void refresh();	// NOTE: placeholder name (0x879300)

	int ID;	// NOTE: placeholder name
	bool next;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
};

CRpglikeUpgradeButton::CRpglikeUpgradeButton(XConsole *parent, int x, int ID_, bool next_)
	: Console(parent,2,1,x,0,0,false,-1)
{
	ID = ID_;
	next = next_;
	print(0,0,next ? ">>" : "<<");
	refresh();
}

class CRpglikeUpgradeCurrent : public Console
{
public:
	CRpglikeUpgradeCurrent(XConsole *parent, int x, int ID_);

	void refresh();	// NOTE: placeholder name (0x879390)

	int ID;	// NOTE: placeholder name
};

CRpglikeUpgradeCurrent::CRpglikeUpgradeCurrent(XConsole *parent, int x, int ID_)
	: Console(parent,7,1,x,0,0,false,-1)
{
	ID = ID_;
	refresh();
}

struct OpW5_MapRecord	// NOTE: placeholder name (MapRecord)
{
	char pad0[0x20];
	string name;	// NOTE: placeholder name
};
extern vector<OpW5_MapRecord*> opW5_mapRecords;	// NOTE: placeholder name (0xd389c4)

class CRpglikeUpgrade : public Console
{
public:
	CRpglikeUpgrade(XConsole *parent, int x, int y, int ID_);

	void refresh();	// NOTE: placeholder name (0x879500)

	int ID;	// NOTE: placeholder name
	CRpglikeUpgradeCurrent *current;	// NOTE: placeholder name
	CRpglikeUpgradeButton *previous;	// NOTE: placeholder name
	CRpglikeUpgradeButton *next;	// NOTE: placeholder name
};

CRpglikeUpgrade::CRpglikeUpgrade(XConsole *parent, int x, int y, int ID_)
	: Console(parent,53,1,x,y,0,false,-1)
{
	ID = ID_;
	putChar_418110(0,0,ID + 'A',*opW5_color_cf44c0);
	putChar_418110(1,0,'/',*opW5_color_cf44c0);
	putChar_418110(2,0,ID + 'a',*opW5_color_cf44c0);
	putChar_418110(4,0,'-',*opW5_color_cf44c0);
	setFore(*opW5_color_d2981c);
	print(6,0,opW5_mapRecords[ID + 0x429]->name);
	refresh();
	current = new CRpglikeUpgradeCurrent(this,0x24,ID);
	previous = new CRpglikeUpgradeButton(this,0x21,ID,false);
	next = new CRpglikeUpgradeButton(this,0x2c,ID,true);
	print(0x30,0,"+" + intToString(opW5_upgradeStep[ID].value));
}

class CRpglikeUpgradesConfirmButton : public Console
{
public:
	CRpglikeUpgradesConfirmButton(XConsole *parent, int x, int y, int width, bool confirm_);

	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
	virtual void render();	// NOTE: placeholder name

	bool confirm;	// NOTE: placeholder name
};

CRpglikeUpgradesConfirmButton::CRpglikeUpgradesConfirmButton(XConsole *parent, int x, int y, int width, bool confirm_)
	: Console(parent,width,1,x,y,0,false,-1)
{
	confirm = confirm_;
}

//==================================================================
// CRpglikeUpgrades
//==================================================================

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);

	string text;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string text, int a, int b);

	char pad6c[0x8c - 0x6c];
};

class CCloseButton : public Console
{
public:
	CCloseButton(XConsole *parent, const XColor &color, int command);

	char pad6c[0x8c - 0x6c];
};


void opW5_playSound_4541b0(int sound, int a, int b);	// NOTE: placeholder name

extern int opW5_unknown_cfd2e4;	// NOTE: placeholder name
extern int opW5_unknown_cfd2e8;	// NOTE: placeholder name
extern int opW5_unknown_d29d98;	// NOTE: placeholder name
extern int opW5_unknown_d29d9c;	// NOTE: placeholder name
extern int opW5_unknown_d37d48;	// NOTE: placeholder name
extern int opW5_unknown_d37d4c;	// NOTE: placeholder name
extern int opW5_unknown_d25800;	// NOTE: placeholder name
extern int opW5_unknown_d25804;	// NOTE: placeholder name
extern int opW5_unknown_cf0c60;	// NOTE: placeholder name
extern int opW5_unknown_caf128;	// NOTE: placeholder name
extern bool opW5_unknown_cf46a0;	// NOTE: placeholder name
extern XColor *opW5_color_cf1f2c;	// NOTE: placeholder name
extern CRpglike *opW5_rpglike;	// NOTE: placeholder name (0xcec060)

class CRpglikeUpgrades : public Console
{
public:
	CRpglikeUpgrades(XConsole *parent);
	virtual ~CRpglikeUpgrades();

	void unknown87a260(int value);	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
	CCloseButton *closeButton;	// NOTE: placeholder name
	vector<int> unknown74;	// NOTE: placeholder name
	CRpglikeUpgradesConfirmButton *confirmButton;	// NOTE: placeholder name
	CText *enterText;	// NOTE: placeholder name
	CRpglikeUpgradesConfirmButton *resetButton;	// NOTE: placeholder name
	CText *resetText;	// NOTE: placeholder name
	int unknown94;	// NOTE: placeholder name
	int unknown98;	// NOTE: placeholder name
	int unknown9c;	// NOTE: placeholder name
	vector<int> unknowna0;	// NOTE: placeholder name
	bool unknownb0;	// NOTE: placeholder name
};
extern CRpglikeUpgrades *opW5_rpglikeUpgrades;	// NOTE: placeholder name (0xcec064)

CRpglikeUpgrades::CRpglikeUpgrades(XConsole *parent)
	: Console(parent,Rect(opW5_unknown_caf128,opW5_rpglike->getY() - 33,58,33),0,false,3),
	unknown94(-1),
	unknown98(-1),
	unknownb0(false)
{
	opW5_rpglikeUpgrades = this;
	opW5_unknown_cf46a0 = true;
	unknown87a260(0);
	string header = " Distribute XP ";
	print(opW5_unknown_cfd2e4,opW5_unknown_cfd2e8,header);
	setBackRow(opW5_unknown_cfd2e4,opW5_unknown_cfd2e8,header.size(),*opW5_color_d25e0c);
	string label = "      Upgrade     ";
	print(opW5_unknown_d29d98,opW5_unknown_d29d9c,label);
	setBackRow(opW5_unknown_d29d98,opW5_unknown_d29d9c,label.size(),*opW5_color_cf6b24);
	label = " Cost ";
	print(opW5_unknown_d37d48,opW5_unknown_d37d4c,label);
	setBackRow(opW5_unknown_d37d48,opW5_unknown_d37d4c,label.size(),*opW5_color_cf6b24);
	label = " Mod ";
	print(opW5_unknown_d25800,opW5_unknown_d25804,label);
	setBackRow(opW5_unknown_d25800,opW5_unknown_d25804,label.size(),*opW5_color_cf6b24);
	enterText = new CText(this,Pos(30,getHeight() - 3),"Enter - [       ]",0,0,-1);
	enterText->setForeAll_4183d0(*opW5_color_cf44c0);
	string confirmText = "Confirm";
	confirmButton = new CRpglikeUpgradesConfirmButton(this,0x27,getHeight() - 3,confirmText.size(),true);
	confirmButton->setFore(*opW5_color_d2981c);
	confirmButton->print(0,0,confirmText);
	resetText = new CText(this,Pos(0x23,2),"1 - [     ]",0,0,-1);
	resetText->setForeAll_4183d0(*opW5_color_cf44c0);
	string resetStr = "Reset";
	resetButton = new CRpglikeUpgradesConfirmButton(this,0x28,2,resetStr.size(),false);
	resetButton->setFore(*opW5_color_d2981c);
	resetButton->print(0,0,resetStr);
	CText *help = new CText(this,Pos(opW5_unknown_cf0c60,getHeight() - 3),"Up/Down/Left/Right",0,0,-1);
	help->setForeAll_4183d0(*opW5_color_cf44c0);
	opW5_playSound_4541b0(0x139,0,0);
	setTitle(new ConsoleTitle(this,"\\ U P G R A D E S \\",0,2));
	animate("CList_Border");
	opW5_keyMap->registerConsole(0x22,this,0x19c,0);
	unknown60 = 1;
	closeButton = new CCloseButton(this,*opW5_color_cf1f2c,0x22);
	closeButton->setHidden(false);
}

//==================================================================
// CRpglikeUpgrades destructor, saved records
//==================================================================

CRpglikeUpgrades::~CRpglikeUpgrades()
{
	opW5_rpglikeUpgrades = NULL;
}

void opW5_readInt(istream &stream, int *value);	// NOTE: placeholder name (0x9d8480)
void opW5_readBool(istream &stream, bool *value);	// NOTE: placeholder name (0x9cf520)
void opW5_readString(istream &stream, string *value);	// NOTE: placeholder name
void opW5_readIntVector(istream &stream, vector<int> *value);	// NOTE: placeholder name (0x9cf5e0)
void opW5_readIntVector2(istream &stream, vector<int> *value);	// NOTE: placeholder name
void opW5_writeInt(ostream &stream, int *value);	// NOTE: placeholder name (0x9d3b60)
void opW5_writeBool(ostream &stream, bool *value);	// NOTE: placeholder name (0x9cf540)
void opW5_writeIntVector(ostream &stream, vector<int> *value);	// NOTE: placeholder name (0x9d2130)

struct OpW5_Range	// NOTE: placeholder name
{
	OpW5_Range() throw();	// 0x40bef0
	void load(istream &stream);	// NOTE: placeholder name (0x45f040)
	int randomInRange();	// NOTE: placeholder name (0x40c130)

	int low;	// NOTE: placeholder name
	int high;	// NOTE: placeholder name
};

struct OpW5_SavedRecord	// NOTE: placeholder name
{
	OpW5_SavedRecord(istream &stream);

	int unknown0;	// NOTE: placeholder name
	string name;	// NOTE: placeholder name
	int unknown20;	// NOTE: placeholder name
	int unknown24;	// NOTE: placeholder name
	OpW5_Range unknown28;	// NOTE: placeholder name
	int unknown30;	// NOTE: placeholder name
	vector<int> unknown34;	// NOTE: placeholder name
};

OpW5_SavedRecord::OpW5_SavedRecord(istream &stream)
{
	opW5_readInt(stream,&unknown0);
	opW5_readString(stream,&name);
	opW5_readInt(stream,&unknown20);
	opW5_readInt(stream,&unknown24);
	unknown28.load(stream);
	opW5_readInt(stream,&unknown30);
	opW5_readIntVector2(stream,&unknown34);
}

struct OpW5_RangeEntry	// NOTE: placeholder name
{
	char pad0[0x20];
	int type;	// NOTE: placeholder name
	int chance;	// NOTE: placeholder name
	OpW5_Range range;	// NOTE: placeholder name
	int cooldown;	// NOTE: placeholder name
	vector<string> lines;	// NOTE: placeholder name
};
extern vector<OpW5_RangeEntry*> opW5_rangeEntries;	// NOTE: placeholder name (0xd379ec)

struct OpW5_RolledValues	// NOTE: placeholder name
{
	OpW5_RolledValues();
	OpW5_RolledValues(istream &stream);
	void save(ostream &stream);	// NOTE: placeholder name
	bool canSay(int ID);	// NOTE: placeholder name
	bool say(int ID, bool force, string name);	// NOTE: placeholder name

	vector<int> unknown0;	// NOTE: placeholder name
	vector<int> values;	// NOTE: placeholder name
	int unknown20;	// NOTE: placeholder name
	int unknown24;	// NOTE: placeholder name
	bool unknown28;	// NOTE: placeholder name
};

OpW5_RolledValues::OpW5_RolledValues()
{
	unknown0.assign(119u,0);
	values.assign(119u,0);
	for (unsigned int i = 0; i < opW5_rangeEntries.size(); i++)
		values[i] = opW5_rangeEntries[i]->range.randomInRange();
	unknown20 = 4;
	unknown24 = 4;
	unknown28 = false;
}

OpW5_RolledValues::OpW5_RolledValues(istream &stream)
{
	opW5_readIntVector(stream,&unknown0);
	opW5_readIntVector(stream,&values);
	opW5_readInt(stream,&unknown20);
	opW5_readInt(stream,&unknown24);
	opW5_readBool(stream,&unknown28);
}

void OpW5_RolledValues::save(ostream &stream)
{
	opW5_writeIntVector(stream,&unknown0);
	opW5_writeIntVector(stream,&values);
	opW5_writeInt(stream,&unknown20);
	opW5_writeInt(stream,&unknown24);
	opW5_writeBool(stream,&unknown28);
}

extern RNG rng;	// 0xd30908

struct OpW5_Location	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
};

class OpW5_Obj_d1e888	// NOTE: placeholder name
{
public:
	OpW5_Location *unknown9b7910();	// NOTE: placeholder name
};
extern OpW5_Obj_d1e888 opW5_obj_d1e888;	// NOTE: placeholder name

bool OpW5_RolledValues::canSay(int ID)
{
	OpW5_RangeEntry *entry = opW5_rangeEntries[ID];
	if ((unknown0[ID] && (!entry->cooldown || opW5_world->getTurn() - unknown0[ID] < entry->cooldown)) ||
		(entry->type != 0x26 && entry->type != opW5_obj_d1e888.unknown9b7910()->type) ||
		opW5_world->getEntity671().isNull() ||
		(values[ID] && opW5_world->getTurn() < values[ID]) ||
		(entry->chance && !rng.chance(entry->chance)) ||
		!opW5_world->unknown4631f0(opW5_world->getEntity671()))
		return false;
	return true;
}

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *opW5_logMsgs;	// NOTE: placeholder name (0xcec0b4)

struct OpW5_MessageType	// NOTE: placeholder name
{
	char pad0[0x24];
	int category;	// NOTE: placeholder name
};
extern vector<OpW5_MessageType*> opW5_messageTypes;	// NOTE: placeholder name (0xd2b4d8)

struct OpW5_MessageCategory	// NOTE: placeholder name
{
	char pad0[0x20];
	int mode;	// NOTE: placeholder name
};
extern vector<OpW5_MessageCategory*> opW5_messageCategories;	// NOTE: placeholder name (0xd35b48)

extern int opW5_unknown_caf150;	// NOTE: placeholder name
extern OpW5_HEntity opW5_messageSpeaker;	// NOTE: placeholder name (0xd388f4)
extern bool opW5_unknown_cefc70;	// NOTE: placeholder name

bool opW5_addMessage_5111e0(int type, const string &text, int a, int b, OpW5_HEntity entity, OpW5_HPropD prop, int c, int d);	// NOTE: placeholder name

class OpW5_MapFine2	// NOTE: placeholder name (CMapFine)
{
public:
	void unknown8758d0(int value);	// NOTE: placeholder name
};
extern OpW5_MapFine2 *opW5_mapFine2;	// NOTE: placeholder name (0xcec058)

void opW5_message(int type, OpW5_HEntity entity, const string &text, int value)	// NOTE: placeholder name
{
	if (type != opW5_unknown_caf150)
	{
		switch (opW5_messageCategories[opW5_messageTypes[type]->category]->mode)
		{
			break;
			case 1:
				opW5_messageSpeaker = entity;
				break;
			case 2:
				opW5_unknown_cefc70 = true;
				break;
		}
		do
		{
			if (opW5_addMessage_5111e0(type,text,0,0,entity,OpW5_HPropD(),value,0))
				opW5_mapFine2->unknown8758d0(1);
			opW5_logMsgs->scrollToEnd();
		}
		while (0);
		opW5_messageSpeaker.reset();
		opW5_unknown_cefc70 = false;
	}
}

string opW5_randomElement_9d3280(vector<string> &values);	// NOTE: placeholder name
void opW5_processText_4351e0(string &text);	// NOTE: placeholder name
extern string opW5_string_d20b7c;	// NOTE: placeholder name
extern string opW5_string_cf0c70;	// NOTE: placeholder name
extern string opW5_string_cf4acc;	// NOTE: placeholder name

bool OpW5_RolledValues::say(int ID, bool force, string name)
{
	if (!force && !canSay(ID))
		return false;

	unknown0[ID] = opW5_world->getTurn();
	string line = opW5_rangeEntries[ID]->lines.size() > 1 ? opW5_randomElement_9d3280(opW5_rangeEntries[ID]->lines) : opW5_rangeEntries[ID]->lines[0];
	opW5_processText_4351e0(line);
	line.insert(0,"[name]: \"");
	if (!name.empty())
		opW5_replace(line,opW5_string_d20b7c,name);
	opW5_replace(line,opW5_string_cf0c70,opW5_string_cf4acc);
	line += "\"";
	opW5_message(0x322,opW5_world->getEntity671(),line,0);
	return true;
}

//==================================================================
// CPlayer2Info / CPlayer2Button / CPlayer2
//==================================================================

// HItem with its default constructor (kept apart from OpW5_HItem, which has none)
class OpW5_HItem2	// NOTE: placeholder name (HItem)
{
public:
	int ID;
	OpW5_HItem2() throw();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	bool isNull() const;	// 0x9b65d0
	OpW5_Item *operator->() const;	// 0x9b65b0
};

struct OpW5_ItemData	// NOTE: placeholder name
{
	char pad0[0x44];
	int slot;	// NOTE: placeholder name
};

// slot table at 0xd01618 is {int ascii; XColor color;}; declared from its colour field here
struct OpW5_SlotColor	// NOTE: placeholder name
{
	XColor color;	// NOTE: placeholder name
	int unknown04;	// NOTE: placeholder name (next entry's ascii)
};
extern OpW5_SlotColor opW5_slotColors_d0161c[];	// NOTE: placeholder name

struct OpW5_SlotAscii	// NOTE: placeholder name
{
	unsigned char ascii;	// NOTE: placeholder name
	char pad01[7];
};
extern OpW5_SlotAscii opW5_slotAscii_d01618[];	// NOTE: placeholder name

template <class T> int opW5_findIndex_9d3110(vector<T> &v, T value);	// NOTE: placeholder name
template <class T> void opW5_eraseAt_9d6440(vector<T> &v, int &index);	// NOTE: placeholder name
template <class T> void opW5_removeAt_9da940(vector<T> &v, int index);	// NOTE: placeholder name
template <class T> void opW5_insertAt_9d8fc0(vector<T> &v, int index, T value);	// NOTE: placeholder name
template <class T> void opW5_append_9d49c0(vector<T> &v, vector<T> &other);	// NOTE: placeholder name
int opW5_max_9cdb60(int a, int b) throw();	// NOTE: placeholder name
extern bool opW5_unknown_cefb17;	// NOTE: placeholder name

extern XColor *opW5_color_d29758;	// NOTE: placeholder name
extern XConsole *opW5_cec068;	// NOTE: placeholder name
extern int opW5_unknown_cefac0;	// NOTE: placeholder name
extern string opW5_string_d35b98;	// NOTE: placeholder name ("[PLAYER2...]" button label)

class CPlayer2Info : public Console
{
public:
	CPlayer2Info(XConsole *parent);
	virtual ~CPlayer2Info();

	virtual void update();

	void refresh(bool animate);	// NOTE: placeholder name (0x49e7e0)
	void drawList(bool parts, int y, vector<OpW5_HItem2> &current, vector<string> &names, int count, int width);	// NOTE: placeholder name

	unsigned int openTime;	// NOTE: placeholder name
	vector<OpW5_HItem2> parts;	// NOTE: placeholder name
	vector<int> partTimes;	// NOTE: placeholder name
	vector<OpW5_HItem2> items;	// NOTE: placeholder name
	vector<int> itemTimes;	// NOTE: placeholder name
};

CPlayer2Info::CPlayer2Info(XConsole *parent)
	: Console(parent,Rect(0,-5,20,5),0,false,-1),
	openTime(tickCount)
{
	refresh(true);
	opW5_playSound_4541b0(0x139,0,0);
	setTitle(new ConsoleTitle(this,"\\ P L A Y E R 2 \\",0,2));
	animate("CList_Border");
	unknown60 = 1;
}

CPlayer2Info::~CPlayer2Info()
{
}

void CPlayer2Info::update()
{
	if (isHidden())
		return;
	if (unknown60 == 1 && !engine->isRunning())
		unknown60 = 3;
	engine->isRunning();
	refresh(unknown60 != 3);
	XConsole::update();
}

// sort a list of items by their sort key (insertion sort into a new list)
#define OPW5_SORT_ITEMS(list) \
	if (!list.empty()) \
	{ \
		vector<OpW5_HItem2> sorted; \
		sorted.push_back(list.back()); \
		list.pop_back(); \
		while (!list.empty()) \
		{ \
			if (sorted.back()->getField457820() < list.back()->getField457820()) \
			{ \
				sorted.push_back(list.back()); \
				list.pop_back(); \
			} \
			else \
			{ \
				for (int k = 0; k < sorted.size(); k++) \
				{ \
					if (list.back()->getField457820() <= sorted[k]->getField457820()) \
					{ \
						opW5_insertAt_9d8fc0(sorted,k,list.back()); \
						list.pop_back(); \
						break; \
					} \
				} \
			} \
		} \
		list = sorted; \
	}

void CPlayer2Info::refresh(bool animate)
{
	vector<OpW5_HItem2> parts;
	OpW5_HEntity player = opW5_world->getEntity671();
	player->unknown5cb8b0(&parts);
	for (int i = parts.size() - 1; i >= 0; i--)
	{
		if (parts[i]->getField4578a0() != 3)
			opW5_removeAt_9da940(parts,i);
	}
	if (parts.empty())
		parts.push_back(OpW5_HItem2());
	else
		OPW5_SORT_ITEMS(parts)

	vector<OpW5_HItem2> invItems;
	player->unknown5cb8b0(&invItems);
	for (int i = invItems.size() - 1; i >= 0; i--)
	{
		if (invItems[i]->getField4578a0() == 3)
			opW5_removeAt_9da940(invItems,i);
	}
	if (!invItems.empty())
		OPW5_SORT_ITEMS(invItems)
	int itemCount = invItems.size();
	if (opW5_unknown_cefb17)
	{
		vector<OpW5_HItem2> extra;
		player->unknown5cb830(&extra);
		if (!extra.empty())
			OPW5_SORT_ITEMS(extra)
		opW5_append_9d49c0(invItems,extra);
	}

	int numLength = 2;
	int maxValue = 0;
	if (parts.front().isValid())
	{
		for (int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->getField9b6bf0() > maxValue)
			{
				maxValue = parts[i]->getField9b6bf0();
				numLength = opW5_max_9cdb60(2,intToString(maxValue).size());
			}
		}
	}
	for (int i = 0; i < invItems.size(); i++)
	{
		if (invItems[i]->getField9b6bf0() > maxValue)
		{
			maxValue = invItems[i]->getField9b6bf0();
			numLength = opW5_max_9cdb60(2,intToString(maxValue).size());
		}
	}

	vector<string> partNameList;
	string itemName;
	for (int i = 0; i < parts.size(); i++)
	{
		if (parts[i].isNull())
			partNameList.push_back(" -- - unarmed");
		else
		{
			string line = padLeft(intToString(parts[i]->getField9b6bf0()),numLength,' ');
			line += " ";
			line += (char)opW5_slotAscii_d01618[parts[i]->getData_9b4350()->slot].ascii;
			line += " ";
			itemName = parts[i]->getName_571db0(0,0);
			if (itemName.find("Corrupted ") != string::npos)
				itemName.erase(0,10);
			line += itemName;
			partNameList.push_back(line);
		}
	}
	vector<string> itemNames;
	for (int i = 0; i < invItems.size(); i++)
	{
		string line = padLeft(intToString(invItems[i]->getField9b6bf0()),numLength,' ');
		line += " ";
		line += (char)opW5_slotAscii_d01618[invItems[i]->getData_9b4350()->slot].ascii;
		line += " ";
		itemName = invItems[i]->getName_571db0(0,0);
		if (itemName.find("Corrupted ") != string::npos)
			itemName.erase(0,10);
		line += itemName;
		itemNames.push_back(line);
	}

	int totalWidth = 20;
	for (int i = 0; i < partNameList.size(); i++)
	{
		if (partNameList[i].size() + 4 > totalWidth)
			totalWidth = partNameList[i].size() + 4;
	}
	for (int i = 0; i < itemNames.size(); i++)
	{
		if (itemNames[i].size() + 4 > totalWidth)
			totalWidth = itemNames[i].size() + 4;
	}
	int h = parts.size() + invItems.size() + 5;
	if (invItems.empty())
		h--;
	if (getWidth() != totalWidth || getHeight() != h)
	{
		resize(totalWidth,h);
		setPos(0,-h);
	}
	clearInterior();
	engine->stopAll();
	drawList(true,2,parts,partNameList,9999,numLength);
	drawList(false,parts.size() + 3,invItems,itemNames,itemCount,numLength);
	if (!animate)
		unknown7b0640(0,*opW5_color_cf6b24,1,0);
}

void CPlayer2Info::drawList(bool parts, int y, vector<OpW5_HItem2> &current, vector<string> &names, int count, int width)
{
	vector<OpW5_HItem2> &shown = parts ? this->parts : items;
	vector<int> &times = parts ? partTimes : itemTimes;

	for (int i = 0; i < shown.size(); i++)
	{
		if (!opW5_contains_9d31e0(current,shown[i]))
		{
			removeVectorElement(times,i);
			opW5_eraseAt_9d6440(shown,i);
		}
	}
	for (int j = 0; j < current.size(); j++)
	{
		if (current[j].isValid() && !opW5_contains_9d31e0(shown,current[j]))
		{
			shown.push_back(current[j]);
			times.push_back((int &)tickCount);
		}
	}
	if (tickCount < openTime + 1000)
		times.assign(shown.size(),0);

	for (int k = 0; k < names.size(); k++, y++)
	{
		int x = 2;
		XColor color = current[k].isValid() && k < count ? *opW5_color_d2981c : *opW5_color_d29758;
		XColor back = *opW5_color_cfe674;
		int pos;
		if (current[k].isValid() && (pos = opW5_findIndex_9d3110(shown,current[k])) != -1 && tickCount - times[pos] < 3000)
		{
			float fade = (3000 - (tickCount - times[pos])) / 3000.0;
			color *= 1 + fade;
			back = *opW5_color_d2175c * fade;
		}
		setFore(color);
		print(x,y,names[k]);
		if (back != *opW5_color_cfe674)
			setBackRow(1,y,getWidth() - 2,back);
		if (current[k].isValid())
		{
			setForeRow(x,y,width,*current[k]->getColor577260());
			x = x + width + 1;
			setFore_417f80(x,y,opW5_slotColors_d0161c[current[k]->getData_9b4350()->slot].color);
		}
	}
}

class CPlayer2Button : public Console
{
public:
	CPlayer2Button(XConsole *parent);

	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
};

CPlayer2Button::CPlayer2Button(XConsole *parent)
	: Console(parent,opW5_string_d35b98.size(),1,parent->getWidth() - 2 - opW5_string_d35b98.size(),1,0,false,-1)
{
	setFore(*opW5_color_cf44c0);
	print(0,0,opW5_string_d35b98);
	setForeRow(1,0,8,*opW5_color_d2981c);
	setForeRow(0xb,0,1,*opW5_color_d2981c);
}

class CPlayer2 : public Console
{
public:
	CPlayer2(XConsole *parent);
	virtual ~CPlayer2();

	virtual void update();

	int getX_4a1c20();	// NOTE: placeholder name
	int getY();	// NOTE: placeholder name
	bool unknown87a990();	// NOTE: placeholder name
	int getRequiredWidth();	// NOTE: placeholder name
	void toggleInfo();	// NOTE: placeholder name
	void refresh();	// NOTE: placeholder name
	void unknown7b0640(int a, XColor color, int b, int c);	// NOTE: placeholder name

	CPlayer2Button *button;	// NOTE: placeholder name
	CPlayer2Info *info;	// NOTE: placeholder name
	string unknown74;	// NOTE: placeholder name
	string unknown90;	// NOTE: placeholder name
};

int CPlayer2::getY()
{
	return opW5_mapConsole->getPos().y + opW5_mapConsole->getHeight() * opW5_unknown_caf12c - opW5_unknown_caf12c - 3 - opW5_unknown_cefac0 * opW5_unknown_caf12c;
}

CPlayer2::CPlayer2(XConsole *parent)
	: Console(parent,Rect(getX_4a1c20(),getY(),22,3),0,false,3),
	info(NULL)
{
	button = new CPlayer2Button(this);
	update();
}

void CPlayer2::update()
{
	if (isHidden())
		return;
	setPos(getX_4a1c20(),getY());
	if (unknown87a990())
	{
		resize(getRequiredWidth(),3);
		refresh();
	}
	XConsole::update();
}

CPlayer2::~CPlayer2()
{
}

int CPlayer2::getRequiredWidth()
{
	return unknown74.size() + unknown90.size() + 22;
}

void CPlayer2::toggleInfo()
{
	if (info)
	{
		opW5_playSound_4541b0(0x28,0,0);
		removeSubconsole(info);
		info = NULL;
	}
	else
		info = new CPlayer2Info(opW5_cec068);
}

void CPlayer2::refresh()
{
	clear();
	int x = 2;
	setFore(*opW5_color_cfe674);
	print(x,1,unknown74);
	setBackRow(x,1,unknown74.size(),*opW5_color_cf6b24);
	setFore(*opW5_color_d2981c);
	x += unknown74.size();
	x += 1;
	print(x,1,unknown90);
	x += unknown90.size();
	x += 2;
	button->setPos(x,1);
	unknown7b0640(0,*opW5_color_cf6b24,1,0);
}

//==================================================================
// small helpers of classes reconstructed elsewhere
//==================================================================

extern int opW5_anim_cef7bc;	// NOTE: placeholder name
extern int opW5_anim_cef8a8;	// NOTE: placeholder name
extern int opW5_anim_cef8fc;	// NOTE: placeholder name
extern int opW5_anims_cef904[];	// NOTE: placeholder name

class OpW5_Console4931e0 : public Console	// NOTE: placeholder name
{
public:
	void refreshColor();	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
};

void OpW5_Console4931e0::refreshColor()
{
	unknown48c3c0(unknown6c ? opW5_anim_cef7bc : opW5_anim_cef8a8);
}

class OpW5_Console4963e0 : public Console	// NOTE: placeholder name
{
public:
	void refreshColor();	// NOTE: placeholder name
	int getMaxHeight();	// NOTE: placeholder name
};

void OpW5_Console4963e0::refreshColor()
{
	unknown48c3c0(opW5_anim_cef8fc);
}

int OpW5_Console4963e0::getMaxHeight()
{
	return opW5_rex.getHeight_4189a0() - 4;
}

class OpW5_Console496880 : public Console	// NOTE: placeholder name
{
public:
	void delay();	// NOTE: placeholder name

	char pad6c[0x144 - 0x6c];
	unsigned int unknown144;	// NOTE: placeholder name
};

void OpW5_Console496880::delay()
{
	unknown144 = tickCount + 500;
}

class OpW5_Unk497700	// NOTE: placeholder name
{
public:
	vector<int> getValues();	// NOTE: placeholder name

	char pad0[0xa4];
	vector<int> values;	// NOTE: placeholder name
};

vector<int> OpW5_Unk497700::getValues()
{
	return values;
}

class OpW5_Unk4984a0	// NOTE: placeholder name
{
public:
	void *getValue(int index);	// NOTE: placeholder name

	char pad0[0x70];
	vector<void*> values;	// NOTE: placeholder name
};

void *OpW5_Unk4984a0::getValue(int index)
{
	return values[index];
}

class OpW5_Console498540 : public Console	// NOTE: placeholder name
{
public:
	void refreshColor();	// NOTE: placeholder name

	int type;	// NOTE: placeholder name
};

void OpW5_Console498540::refreshColor()
{
	unknown48c3c0(opW5_anims_cef904[type]);
}

class OpW5_Unk49b870	// NOTE: placeholder name
{
public:
	void reset();	// NOTE: placeholder name
	void update();	// NOTE: placeholder name

	char pad0[0x1c];
	Pos unknown1c;	// NOTE: placeholder name
	char pad24[2];
	bool unknown26;	// NOTE: placeholder name
};

void OpW5_Unk49b870::reset()
{
	unknown1c.set_409ff0(0);
	unknown26 = false;
}

void OpW5_Unk49b870::update()
{
	if (!unknown26)
		reset();
}

class OpW5_Unk49b8b0	// NOTE: placeholder name
{
public:
	void unknown49b8b0();	// NOTE: placeholder name

	char pad0[0x4c];
	int unknown4c;	// NOTE: placeholder name
};

void OpW5_Unk49b8b0::unknown49b8b0()
{
	unknown4c = opW5_world->unknown464290() + 1;
}

extern int opW5_unknown_cfe5e4;	// NOTE: placeholder name
extern int opW5_unknown_cea000;	// NOTE: placeholder name

void opW5_unknown49bde0(OpW5_HEntity entity)	// NOTE: placeholder name
{
	opW5_unknown_cfe5e4 = entity->getField9fcd80();
	if (opW5_world->unknown4631f0(entity))
		opW5_unknown_cea000 = opW5_unknown_cfe5e4;
}

class OpW5_Unk496810	// NOTE: placeholder name (owner of the text console at +0x13c)
{
public:
	void clearText();	// NOTE: placeholder name

	char pad0[0x13c];
	XConsole *text;	// NOTE: placeholder name
};

void OpW5_Unk496810::clearText()
{
	text->getSubconsoles()->empty() ? text->clear() : (*text->getSubconsoles())[0]->clear();
}

class CDragDrop : public Console
{
public:
	virtual ~CDragDrop();
};

CDragDrop::~CDragDrop()
{
}
