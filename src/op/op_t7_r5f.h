#pragma once
// op_r5f: consoles CType/CNotification/CParse/CTrailer/CRexpaint/CDifficulty/CTitle/CIntro/CMapAnim/CEffect in 0x954180-0x965c10, Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos();
	Pos(int x_, int y_);	// 0x46ca20
	Pos(int v);	// 0x409990
	Pos(const Pos &pos) throw();	// 0x46ca50
	Pos &operator=(const Pos &pos);
	Pos operator+(const Pos &pos) const;	// 0x409b60
};

struct Point
{
	int x;
	int y;

	Point &operator=(const Point &p);	// 0x46ca50
	Point(const Point &p);	// 0x46ca50
	Point(int v);	// 0x409990
	Point(int x_, int y_);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(unsigned char value);
	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();
	Rect(int x_, int y_, int width_, int height_);
	Rect(const Rect &rect);
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(const XEvent &event);	// 0x944370
	XEvent(int type_);	// 0x415c60

	int type;
	Point pos;
};

class ConsoleTitle;

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(XEvent *event);
	virtual void inputMouse(int x, int y);
	virtual void update();
	virtual void render();

	bool isHidden();
	Rect getRect();
	Point getPos();
	void setPos(const Point &pos);
	int getWidth();	// 0x44b0d0
	int getHeight();
	void print(int x, int y, const string &text);
	void printAligned(int x, int y, int align, const string &text);
	void setCharRow(int x, int y, int width, int ch);
	string getFirstLine();
	void clear(int x, int y, int width, int height);
	void clearInterior();
	void setFore(XColor color);
	void setBack(XColor color);
	void setHidden(bool hidden_);
	void setPassThrough_418480(bool passThrough_);	// NOTE: placeholder name
	int printWrapped_418260(int x, int y, int width, int height, const string &text);	// NOTE: placeholder name
	void deleteSubconsoles();
	void clear();
	void putChar_418150(int x, int y, int ch, XColor fore, XColor back, bool flag);	// NOTE: placeholder name
	void setForeAll_4183d0(XColor color);	// NOTE: placeholder name
	void setScaleX_417b60(float value);	// NOTE: placeholder name
	void setScaleY_417b80(float value);	// NOTE: placeholder name
	float getScaleX();
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	void setBack_417fc0(int x, int y, XColor color, int mode);	// NOTE: placeholder name
	void setUnknown_451400(int value);	// NOTE: placeholder name (folded setter)
	void unknown429ea0();	// NOTE: placeholder name
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)
	void removeSubconsole(XConsole *console);
	XConsole *getParent4();	// NOTE: placeholder name (folded +4 getter)
	void setPos(int x, int y);
	void setBackAll_418410(XColor color);	// NOTE: placeholder name
	void resetBack_418450() throw();	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class OpQ4d_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class OpQ4d_Engine	// NOTE: placeholder name
{
public:
	OpQ4d_EngineItem *unknown50fb50(OpQ4d_Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
	void killGroup(string group);
	void update();	// NOTE: placeholder name (0x50fff0)
	void render();	// NOTE: placeholder name (0x5100b0)
	void stopAll();	// NOTE: placeholder name
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void render();
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);
	int getState_48c360();	// NOTE: placeholder name (folded getter of unknown60)
	void setFrameFore(XColor color);	// NOTE: placeholder name (0x7b0a20)
	void replaceSpecialChars(int ch);	// NOTE: placeholder name (0x7b0a60)
	void animate(string name, int a, int b);
	void drawFrame(Rect *area, XColor color, bool thin, bool lines);	// NOTE: placeholder name
	void setTitle(ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void unknown48c460(int anim, const Pos &pos);	// NOTE: placeholder name

	int unknown60;
	OpQ4d_Engine *engine;
	void *title;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);

	char pad6c[0x8c - 0x6c];
};

class HItem
{
public:
	int ID;
	HItem();
	bool isValid() const;
};

class Entity
{
public:
	int getAiType();	// NOTE: placeholder name (0x45a2a0)
	int getFaction();	// NOTE: placeholder name (0x45a2c0)
	Pos &getPosition();	// NOTE: placeholder name
	int getSize();	// NOTE: placeholder name
};

class HEntity : public HItem	// NOTE: placeholder layout
{
public:
	HEntity();
	Entity *operator->() const throw();	// 0x9b6570
};

extern string opr5f_factionNames[];	// NOTE: placeholder name (0xd2f798)
string OpR5f_toUpper_4083a0(const string &text);	// NOTE: placeholder name

int opr5f_maxInt(int a, int b) throw();	// NOTE: placeholder name (0x9cdb60)
void opr5f_unknown953d90(HEntity entity, vector<int> *hacks);	// NOTE: placeholder name
extern int opr5f_hackCosts[];	// NOTE: placeholder name (0xb97d38)
extern int opr5f_tileWidth;	// NOTE: placeholder name (0xcaf128)
extern int opr5f_tileHeight;	// NOTE: placeholder name (0xcaf12c)
extern int opr5f_cf27ec;	// NOTE: placeholder name
extern int opr5f_cf27f0;	// NOTE: placeholder name
extern int opr5f_cf27f4;	// NOTE: placeholder name
extern int opr5f_cf27f8;	// NOTE: placeholder name

class OpR5f_Map	// NOTE: placeholder name (CMap at 0xcec054)
{
public:
	Pos &unknown458ef0();	// NOTE: placeholder name (folded getter)
};
extern OpR5f_Map *opr5f_cec054;	// NOTE: placeholder name
extern XConsole *opr5f_cec034;	// NOTE: placeholder name

class CRobot : public Console	// 0xcec108
{
public:
	CRobot(XConsole *parent, const Pos &pos, HEntity entity, vector<int> hacks);	// 0x9450f0

	char pad6c[0xc4 - 0x6c];
};


//==================================================================
// shared declarations (op_r5f)
//==================================================================

class OpR5f_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void unknown416640();	// NOTE: placeholder name
	void unknown416340(bool value);	// NOTE: placeholder name
	void unknown416570();	// NOTE: placeholder name
	void unknown4162e0(int command, bool value);	// NOTE: placeholder name
};
extern OpR5f_KeyMap *opr5f_keyMap;	// NOTE: placeholder name

extern bool opr5f_inputBlocked;	// NOTE: placeholder name (0xcefa5f)
void opr5f_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)

class OpR5f_Sound	// NOTE: placeholder name (0xcefa90)
{
public:
	void haltAll();	// NOTE: placeholder name (0x419c50)
};
extern OpR5f_Sound *opr5f_sound;	// NOTE: placeholder name

class OpR5f_Unk9c05e0	// NOTE: placeholder name (0xcefaa8)
{
public:
	void unknown9c05e0();	// NOTE: placeholder name (empty function)
};
extern OpR5f_Unk9c05e0 *opr5f_cefaa8;	// NOTE: placeholder name

class OpR5f_Rex	// NOTE: placeholder name (0xd223f0)
{
public:
	XConsole *getConsole_4ab670();	// NOTE: placeholder name (folded getter)
	int unknown418980();	// NOTE: placeholder name
	int unknown4189a0();	// NOTE: placeholder name
};
extern OpR5f_Rex opr5f_rex;	// NOTE: placeholder name

class OpR5f_Delay	// NOTE: placeholder name (0xcec03c)
{
public:
	void delay();	// NOTE: placeholder name
};
extern OpR5f_Delay *opr5f_cec03c;	// NOTE: placeholder name

class OpR5f_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	void unknown464710(int value);	// NOTE: placeholder name
};
extern OpR5f_World *opr5f_world;	// NOTE: placeholder name

void opr5f_unknown954640(bool flag);	// NOTE: placeholder name

class CTextInput : public Console
{
public:
	string &getText_458ef0();	// NOTE: placeholder name (folded getter, +0x6c)

	char pad6c[0xe4 - 0x6c];
};

//==================================================================
// CType
//==================================================================

class CType : public Console
{
public:
	virtual bool input(XEvent *event);
	virtual void close();

	char pad6c[0x74 - 0x6c];
	void (*callback)(const string &text);	// NOTE: placeholder name
	bool unknown78;	// NOTE: placeholder name
	char pad79[0x7c - 0x79];
	CTextInput *textInput;	// NOTE: placeholder name
};
extern CType *opr5f_cec10c;	// NOTE: placeholder name




//==================================================================
// CNotification
//==================================================================

class CNotification : public Console
{
public:
	virtual ~CNotification();
	virtual bool input(XEvent *event);
	virtual void close();
};



//==================================================================
// CParse
//==================================================================

class CParse : public Console
{
public:
	virtual bool input(XEvent *event);

	void unknown95a590();	// NOTE: placeholder name
};



//==================================================================
// CRobot window
//==================================================================


//==================================================================
// CParseLine
//==================================================================

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);

	string text;
};

class CParseLine : public Console
{
public:
	CParseLine(XConsole *parent, int width, int y, const string &left, const string &right);	// 0x9548e0
};


//==================================================================
// CTrailer
//==================================================================

class CTrailer : public Console
{
public:
	CTrailer();	// 0x95a6c0
	virtual ~CTrailer();	// defined in cc_r2_21
	virtual bool input(XEvent *event);

	void stop();	// NOTE: placeholder name (0x95aed0)
	void toggle();	// NOTE: placeholder name (0x95af10)

	int unknown6c;	// NOTE: placeholder name
	bool playing;	// NOTE: placeholder name
};





//==================================================================
// CRexpaint
//==================================================================

class ConsoleArt : public Console
{
public:
	void drawArt(int layer);

	char pad6c[0x84 - 0x6c];
};

class CArtAnimated : public ConsoleArt
{
public:
	CArtAnimated(XConsole *parent, const string &file, int x, int y, bool hidden, int unknown84_, int layer, int frame, const Pos &offset_, int width, int height);
	void unknown4b29b0();	// NOTE: placeholder name (0x4b29b0)

	int unknown84;
};

int opr5f_centerOffset(int inner, int outer) throw();	// NOTE: placeholder name (0x437190)
bool opr5f_findAnimation_9d45a0(const string &name, int *index);	// NOTE: placeholder name
extern OpR5f_KeyMap *opr5f_keyMap;

class CRexpaint : public Console
{
public:
	CRexpaint();	// 0x95b020
	virtual ~CRexpaint();	// defined in cc_r2_21
	virtual void open();	// 0x95b090
	virtual bool input(XEvent *event);
	virtual void trigger(const string &command, int value);

	void stop();	// NOTE: placeholder name (0x95b510)

	CArtAnimated *unknown6c;	// NOTE: placeholder name
	CArtAnimated *unknown70;	// NOTE: placeholder name
	CArtAnimated *unknown74;	// NOTE: placeholder name
};






//==================================================================
// CDifficultyWindow
//==================================================================

class CDifficultyButton : public Console
{
public:
	CDifficultyButton(XConsole *parent, int x, int y, const string &text);	// 0x4b26f0
};

class CText;
class CDifficulty;

extern int opr5f_difficultyHeights[];	// NOTE: placeholder name (0xbcdb6c)
extern int opr5f_difficultyNumbers[];	// NOTE: placeholder name (0xbcdb60)
extern string opr5f_difficultyNames[];	// NOTE: placeholder name (0xd1de98)
extern string opr5f_difficultyShort[];	// NOTE: placeholder name (0xd318c0)
extern string opr5f_difficultyTails[];	// NOTE: placeholder name (0xd20880)
extern string opr5f_confirmText;	// NOTE: placeholder name (0xd384d4)
extern string opr5f_infoText;	// NOTE: placeholder name (0xd39e74)
extern XColor *opr5f_COLOR_BLACK;	// NOTE: placeholder name (0xcfe674)
extern int opr5f_difficulty;	// NOTE: placeholder name (0xd28d0c)
string intToString(int value);	// 0x4051f0

class OpR5f_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	bool getField_41a6e0();	// NOTE: placeholder name
};
extern OpR5f_Mouse *opr5f_mouse;	// NOTE: placeholder name

class CDifficultyWindow : public Console
{
public:
	CDifficultyWindow(int type_, int y);	// 0x95b630
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(XEvent *event);

	bool hasConfirm();	// NOTE: placeholder name (0x4b27f0, folded getter)
	void undoConfirm();	// NOTE: placeholder name (0x95bec0)

	int type;	// NOTE: placeholder name
	CDifficultyButton *description;	// NOTE: placeholder name
	CDifficultyButton *tail;	// NOTE: placeholder name
	CDifficultyButton *confirm;	// NOTE: placeholder name
};

class OpR5f_Difficulty : public Console	// NOTE: placeholder name (CDifficulty at 0xcec028)
{
public:
	virtual void close();
	vector<CDifficultyWindow*> *getWindows();	// NOTE: placeholder name (0x458ef0, folded getter)
};
extern OpR5f_Difficulty *opr5f_cec028;	// NOTE: placeholder name






//==================================================================
// CDifficulty
//==================================================================

class GM	// NOTE: placeholder layout (object at 0xcefaa8)
{
public:
	bool readyGame(bool a, bool b, bool c);	// 0x78b8a0
};
extern GM *opr5f_gm;	// NOTE: placeholder name

class OpR5f_Clock	// NOTE: placeholder name (0xcefa9c)
{
public:
	void start_416920();	// NOTE: placeholder name
};
extern OpR5f_Clock *opr5f_clock;	// NOTE: placeholder name

class AsciiImage
{
public:
	AsciiImage();
	~AsciiImage();
	bool load(const string &file, int font, Pos *offset, int width, int height);

	char pad00[0x10];
};

class CTitleAnimated : public ConsoleArt
{
public:
	CTitleAnimated(XConsole *parent, AsciiImage *art, int unknown84_, int frame);	// 0x4b28f0
	void unknown4b29b0();	// NOTE: placeholder name

	int unknown84;	// NOTE: placeholder name
};

class OpR5f_Mouse2	// NOTE: placeholder name (0xcefa94)
{
public:
	bool getField_41a6e0();	// NOTE: placeholder name
	void setCursorHidden(bool hidden);	// 0x432170, NOTE: placeholder name
};
extern OpR5f_Mouse2 *opr5f_mouse2;	// NOTE: placeholder name

class OpR5f_GM2	// NOTE: placeholder name (0xcefaa8)
{
public:
	void unknown78c050();	// NOTE: placeholder name
};
extern OpR5f_GM2 *opr5f_gm2;	// NOTE: placeholder name
extern Console *opr5f_cec030;	// NOTE: placeholder name

class CTitle : public Console
{
public:
	CTitle();	// 0x95c5d0
	virtual ~CTitle();	// 0x4b28a0
	virtual bool input(XEvent *event);
	virtual void update();
	virtual void close();
	virtual void trigger(const string &command, int value);	// 0x95ccc0

	void show(bool flag);	// NOTE: placeholder name (0x95c640)

	Console *ascii;	// NOTE: placeholder name
	bool finished;	// NOTE: placeholder name
	bool cursorHidden;	// NOTE: placeholder name
};
extern CTitle *opr5f_cec02c;	// NOTE: placeholder name
extern bool opr5f_cefacd;	// NOTE: placeholder name
extern bool opr5f_cefb2d;	// NOTE: placeholder name

string opr1c_getSaveName_432af0(int version, bool error);	// 0x432af0, NOTE: placeholder name

class CDifficulty : public Console
{
public:
	CDifficulty();	// 0x95bf40
	virtual ~CDifficulty();	// defined in cc_r2_21
	virtual bool input(XEvent *event);
	virtual void update();
	virtual void open();
	virtual void close();

	vector<CDifficultyWindow*> windows;	// NOTE: placeholder name
};






//==================================================================
// CTitle
//==================================================================

bool opr5f_findAnimation_9d45a0(const string &name, int *index);	// NOTE: placeholder name (0x9d45a0)



