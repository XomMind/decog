// op_t1: console classes in 0x48e000 (header-inline ctors of small Console subclasses), Beta 17.1.
// NOTE: class layouts are partial; member/method names are placeholders unless stated otherwise.
//	The declarations below are op_w9.cpp's, minus function bodies.
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos();	// 0x453b40
	Pos(int x_, int y_);
	Pos(const Pos &pos) throw();
	Pos(const Pos &pos, int dx, int dy);	// NOTE: placeholder name
	explicit Pos(int value);	// NOTE: placeholder name (0x409990)
	Pos operator+(const Pos &pos) const;	// 0x409b60
	Pos &operator=(const Pos &pos);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
	static XColor addAlpha(XColor a, XColor b, float alpha);	// 0x4137b0
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect() throw();	// NOTE: folded default ctor
	Rect(int x_, int y_, int width_, int height_) throw();	// 0x456940
	Rect(const Rect &rect);
	Rect &operator=(const Rect &rect);	// NOTE: folded with the copy ctor (0x40a720)
	void set(int x_, int y_, int width_, int height_);	// NOTE: placeholder name (0x40a840)
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
	virtual bool isActive();
	virtual void refresh();
	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int modifier);	// NOTE: placeholder name
	virtual void update();
	virtual void render();

	bool isHidden();
	int getWidth();
	int getHeight();
	Pos getPos();
	bool contains(const Pos &p);
	bool inBounds(const Pos &p);
	float getScaleX();
	void setHidden(bool hidden_) throw();
	XConsole *getParent();
	void removeSubconsole(XConsole *console);
	void deleteSubconsoles();
	void setScaleX(float value);	// NOTE: placeholder name (0x417b60)
	void setScaleY(float value);
	void setPos(const Pos &pos);	// NOTE: placeholder name (0x417b80)
	void unknown429f10(int a, int b);	// NOTE: placeholder name
	void unknown429fe0(XConsole *console, const Pos &pos, int value);	// NOTE: placeholder name
	void clear(XConsole *console);
	void setPos(int x, int y);
	void setFore(XColor color);
	void setFore_417f80(int x, int y, XColor color);
	int getChar(int x, int y);
	bool isWide();
	void setCharRow(int x, int y, int length, int ch, XColor color);
	void setCharColumn(int x, int y, int length, int ch, XColor color);
	void setForeFrame(int x, int y, int width, int height, XColor color);
	struct OpW9_Cell *getCell_4176e0(int x, int y, int layer);	// NOTE: placeholder name
	void setChar_417f50(int x, int y, int ch);
	void setBackAll_418410(XColor color);
	void clearBack();
	void putChar_418110(int x, int y, int ch, XColor fore);
	void putChar_4180b0(int x, int y, int ch);	// NOTE: placeholder name
	void clear();
	void clearRow(int x, int y, int length);	// NOTE: placeholder name
	void clearInterior();
	void move(int dx, int dy);
	void print(int x, int y, const string &text);

	char pad04[0x60 - 0x04];
};

class OpW9_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class Engine
{
public:
	OpW9_EngineItem *unknown50fb50(Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
	bool isRunning();	// NOTE: placeholder name (0x50fff0)
	bool unknown454d30();	// NOTE: placeholder name
	void killGroup(string group);
	void stopAll();	// NOTE: placeholder name (0x50ff30)
	void render();	// NOTE: placeholder name (0x5100b0)
};

struct OpW9_Cell	// NOTE: placeholder name
{
	void unknown4280e0();	// NOTE: placeholder name
};

class RNG
{
public:
	int rangeInt(float min, float max);
};
extern RNG rng;

class Console : public XConsole
{
public:
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);

	bool isActive_7ad420();	// NOTE: placeholder name
	void unknown48e8b0();	// NOTE: placeholder name
	void setTitle(class ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void animate(string name);	// NOTE: placeholder name
	void animate(string name, int unknown1, int unknown2);	// NOTE: placeholder name
	void unknown7ad6a0(int index, int unknown1, int unknown2, int a, int b);	// NOTE: placeholder name
	Pos getAnchor(int anchor);	// NOTE: placeholder name
	void drawFrame(Rect *area, XColor color, bool thin, bool lines);	// NOTE: placeholder name
	void setFrameFore(XColor color);	// NOTE: placeholder name
	void replaceSpecialChars(int ch);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	XConsole *title;
};

class Console;
class OpW9_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void registerConsole(int command, Console *console, int unknown1, int unknown2);	// NOTE: placeholder name (0x416790)
	void unknown416640();	// NOTE: placeholder name
	void unknown4162e0(int command, int value);	// NOTE: placeholder name
};
extern OpW9_KeyMap *opW9_keyMap;	// NOTE: placeholder name

class OpW9_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	Pos getPos();	// NOTE: placeholder name (0x41a700)
	void unknown41a8b0();	// NOTE: placeholder name
	bool unknown41a6e0();	// NOTE: placeholder name (folded getter)
};
extern OpW9_Mouse *opW9_mouse;	// NOTE: placeholder name

class OpW9_SidePanel : public XConsole	// NOTE: placeholder name (0xcec11c)
{
public:
	void unknown8b5080();	// NOTE: placeholder name
};
extern OpW9_SidePanel *opW9_cec11c;	// NOTE: placeholder name

struct OpW9_Options	// NOTE: placeholder name (0xcec130)
{
	char pad00[0x9d];
	bool unknown9d;	// NOTE: placeholder name
	char pad9e[0xc8 - 0x9e];
	void (*renderHook)(XConsole *console);	// NOTE: placeholder name

	int getUnknown58();	// NOTE: placeholder name (folded getter 0x44a7d0)
};
extern OpW9_Options *opW9_options;	// NOTE: placeholder name

extern bool opW9_consoleInputBlocked;	// NOTE: placeholder name (0xcefa5f)
extern unsigned int opW9_tickCount;	// NOTE: placeholder name (0xcaed20)
extern void *opW9_help;	// NOTE: placeholder name (0xcec038)
extern const char opW9_listHotkeys[];	// NOTE: placeholder name (0xb965f4)

string intToString(int value);
bool opW9_findAnimation(const string &name, int *index);	// NOTE: placeholder name (0x9d45a0)
extern string opW9_listDifferentNames[];	// NOTE: placeholder name (0xcfac48)
extern string opW9_listOptionNames[];	// NOTE: placeholder name (0xcf35c0)
extern Pos opW9_cfbec0;	// NOTE: placeholder name
extern XColor *opW9_cfc180;	// NOTE: placeholder name
extern XColor *opW9_cfd448;	// NOTE: placeholder name
extern XColor *opW9_d2d29c;	// NOTE: placeholder name
extern XColor *opW9_cf44c0;	// NOTE: placeholder name
extern XColor *opW9_d1d46c;	// NOTE: placeholder name
extern XColor *opW9_d323c4;	// NOTE: placeholder name
extern XColor *opW9_d30424;	// NOTE: placeholder name
extern XColor *opW9_d22fcc;	// NOTE: placeholder name
void opW9_clamp(int low, int &value, int high);	// NOTE: placeholder name (0x9cdc50)
template <class T> void removeVectorElement(vector<T> &v, int index);
template <class T> void OpW9_insertAt(vector<T> &v, int i, T e);	// NOTE: placeholder name (0x9dbdc0)

//==================================================================
// CListOption / CList
//==================================================================

class CListOption : public Console
{
public:
	CListOption(XConsole *parent, int x, int y, int width, const string &text, int font, bool hidden, int unknown6c_, int unknown70_, bool selectable_, int unknown78_, int unknown7c_);

	void draw();	// NOTE: placeholder name
	virtual bool input(XEvent *event);
	virtual void render();

	int unknown6c;
	int unknown70;
	bool selectable;
	int unknown78;
	int unknown7c;
};

class CList : public Console
{
public:
	CList(XConsole *parent, const Pos &pos, string title, int unknown74_, const vector<string> &options_, int maxVisible, int font, void (*callback_)(int,const string&), int unknownC4_, int layer, bool unknown9c_, bool unknown9d_, vector<bool> *enabled_, vector<int> *unknownA4_, vector<int> *unknownA8_, bool noClose_);	// 0x48d9a0

	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int modifier);
	virtual void update();
	virtual void close();

	void cancel();	// NOTE: placeholder name
	void unknown7b2870();	// NOTE: placeholder name
	int getOptionAtMouse();	// NOTE: placeholder name
	void select(int index);	// NOTE: placeholder name
	void highlight(int index);	// NOTE: placeholder name
	void scroll(int amount, int target);	// NOTE: placeholder name
	void updateScroll();	// NOTE: placeholder name

	unsigned int closeTime;	// NOTE: placeholder name
	XConsole *closeButton;
	int unknown74;
	vector<string> options;
	unsigned int maxLength;
	int optionWidth;
	int numVisible;
	int unknown94;
	int unknown98;
	bool unknown9c;
	bool unknown9d;
	bool noClose;
	vector<bool> *enabled;
	vector<int> *unknownA4;
	vector<int> *unknownA8;
	vector<CListOption*> listOptions;
	void (*callback)(int,const string&);
	bool unknownC0;
	void (*highlightCallback)(int,const string&);	// NOTE: placeholder name
	int unknownC8;
	CListOption *moreAbove;	// NOTE: placeholder name
	CListOption *moreBelow;	// NOTE: placeholder name
};














//==================================================================
// CLogMsg / CLogMsgs / CLog
//==================================================================

struct OpW9_LogSource	// NOTE: placeholder name
{
	char pad00[0x24];
	int unknown24;	// NOTE: placeholder name
};

struct LogMsg	// NOTE: placeholder name
{
	OpW9_LogSource *source;	// NOTE: placeholder name
	string text;
	int unknown20;	// NOTE: placeholder name
	int unknown24;	// NOTE: placeholder name
};

struct OpW9_LogStyle	// NOTE: placeholder name
{
	char pad00[0x24];
	int colors[3];	// NOTE: placeholder name
	int unknown30;	// NOTE: placeholder name
	int unknown34;	// NOTE: placeholder name
};
extern vector<OpW9_LogStyle*> opW9_logStyles;	// NOTE: placeholder name (0xd35b48)
extern vector<int> opW9_cfe704;	// NOTE: placeholder name

class CLogMsg : public Console
{
public:
	CLogMsg(XConsole *parent, int y, LogMsg *msg_, int type);	// 0x48e340

	void setText(const string &text);	// NOTE: placeholder name
	void colorize(int index);	// NOTE: placeholder name (0x48e3e0)

	LogMsg *msg;
};

class CLog;

class CLogMsgs : public Console	// NOTE: placeholder name
{
public:
	CLogMsgs(XConsole *parent, int type_);

	virtual bool input(XEvent *event);
	virtual void update();

	vector<LogMsg*> *getMessages();	// 0x48e4e0, NOTE: placeholder name
	vector<CLogMsg*> *getConsoles();	// NOTE: placeholder name (folded getter 0x45a840)
	CLog *getLog();	// NOTE: placeholder name (0x48e510)
	void unknown7b3df0(int value);	// NOTE: placeholder name
	void addLine(int index, int y, bool atFront);	// NOTE: placeholder name
	void scroll(int amount, bool unknown);	// NOTE: placeholder name
	void scrollToEnd();	// NOTE: placeholder name
	void toggleExpanded();	// NOTE: placeholder name
	void clearLines();	// NOTE: placeholder name

	int type;	// NOTE: placeholder name
	bool expanded;	// NOTE: placeholder name
	int index;	// NOTE: placeholder name
	vector<CLogMsg*> consoles;	// NOTE: placeholder name
	bool unknown88;	// NOTE: placeholder name
	int lastIndex;	// NOTE: placeholder name
	vector<Console*> lines;	// NOTE: placeholder name
	int topIndex;	// NOTE: placeholder name
	int offset;	// NOTE: placeholder name
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);

	string title;
	int align;
};

class OpW9_LogFilter : public Console	// NOTE: placeholder name (0x70 bytes)
{
public:
	OpW9_LogFilter(XConsole *parent);	// 0x48e1d0
	void unknown48e250(bool value);	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
};

class CLog : public Console
{
public:
	CLog(XConsole *parent, int mode_);

	virtual bool input(XEvent *event);
	virtual void update();
	virtual void open();
	virtual void close();

	CLogMsgs *getMessages();	// NOTE: placeholder name (0x48e760)
	bool getUnknown80();	// NOTE: placeholder name (0x48e740)
	bool unknown48e7b0();	// NOTE: placeholder name
	void unknown7b5f40(CLogMsg *msg, bool top);	// NOTE: placeholder name
	bool unknown7b60e0();	// NOTE: placeholder name
	void unknown7b62c0();	// NOTE: placeholder name
	void unknown7b6370();	// NOTE: placeholder name

	bool opened;	// NOTE: placeholder name
	unsigned int closeTime;	// NOTE: placeholder name
	Console *unknown74;	// NOTE: placeholder name
	Console *unknown78;	// NOTE: placeholder name
	int mode;	// NOTE: placeholder name
	bool unknown80;	// NOTE: placeholder name
	Console *unknown84;	// NOTE: placeholder name
	int unknown88;	// NOTE: placeholder name
};

class OpW9_Push : public XConsole	// NOTE: placeholder name (0xcec054)
{
public:
	bool operate();	// NOTE: placeholder name (0x49aa00)
	bool unknown49aa60();	// NOTE: placeholder name
	void unknown819a60();	// NOTE: placeholder name
	bool unknown805190(Pos &pos);	// NOTE: placeholder name
	void unknown827950();	// NOTE: placeholder name
	void unknown49ac70();	// NOTE: placeholder name
	Pos &getOffset();	// NOTE: placeholder name (folded getter 0x458ef0)
	void unknown8069e0(Pos pos, int a);	// NOTE: placeholder name
	void unknown8279c0(const Pos &pos);	// NOTE: placeholder name
	void unknown806e70(const Pos &pos, int a);	// NOTE: placeholder name
};
extern OpW9_Push *opW9_cec054;	// NOTE: placeholder name

class OpW9_UIControl : public XConsole	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown49c3d0(int value);	// NOTE: placeholder name
};
extern OpW9_UIControl *opW9_cec058;	// NOTE: placeholder name

class HEntity;
class OpW9_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	int unknown715800(vector<HEntity> &out);	// NOTE: placeholder name
	HEntity getPlayer() throw();	// 0x4630f0
	vector<vector<HEntity> > *unknown463ec0();	// NOTE: placeholder name
	bool unknown463160(const Pos &pos);	// NOTE: placeholder name
	int unknown4642d0();	// NOTE: placeholder name
};
extern OpW9_World *opW9_world;	// NOTE: placeholder name

struct OpW9_GameState	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
};
class OpW9_HGameState	// NOTE: placeholder name
{
public:
	int ID;
	OpW9_GameState *operator->() const;	// 0x9b7910
};
extern OpW9_HGameState opW9_gameState;	// NOTE: placeholder name (0xd1e888)

class OpW9_Audio	// NOTE: placeholder name (0xcefaa8)
{
public:
	void play(int sound, int a, int b, int c, int d);	// NOTE: placeholder name (0x793450)
};
extern OpW9_Audio *opW9_audio;	// NOTE: placeholder name

extern CLog *opW9_log0;	// NOTE: placeholder name (0xcec0b0)
extern CLogMsgs *opW9_logMsgs0;	// NOTE: placeholder name (0xcec0b4)
extern CLog *opW9_log1;	// NOTE: placeholder name (0xcec0b8)
extern CLogMsgs *opW9_logMsgs1;	// NOTE: placeholder name (0xcec0bc)
extern CLog *opW9_log2;	// NOTE: placeholder name (0xcec0c0)
extern CLogMsgs *opW9_logMsgs2;	// NOTE: placeholder name (0xcec0c4)
class OpW9_LogTabs : public Console	// NOTE: placeholder name (0xcec0d0)
{
};
extern OpW9_LogTabs *opW9_cec0d0;	// NOTE: placeholder name
class OpW9_MessageLog : public XConsole	// NOTE: placeholder name (0xcec0f4)
{
public:
	void unknown7b1cc0();	// NOTE: placeholder name
};
extern OpW9_MessageLog *opW9_cec0f4;	// NOTE: placeholder name
class OpW9_Unk98a3a0	// NOTE: placeholder name (0xcec0e0)
{
public:
	void unknown98a3a0();	// NOTE: placeholder name
};
extern OpW9_Unk98a3a0 *opW9_cec0e0;	// NOTE: placeholder name
extern XConsole *opW9_cec118;	// NOTE: placeholder name
extern XConsole *opW9_cec0f8;	// NOTE: placeholder name
extern Rect opW9_rect_cf4154;	// NOTE: placeholder name
extern Rect opW9_rect_d39268;	// NOTE: placeholder name
extern Rect opW9_rects_d316c4[];	// NOTE: placeholder name
extern Rect opW9_rects_d35dc8[];	// NOTE: placeholder name
extern int opW9_cf4564;	// NOTE: placeholder name
extern int opW9_cf4568;	// NOTE: placeholder name
extern int opW9_cf456c;	// NOTE: placeholder name
extern int opW9_cf4570;	// NOTE: placeholder name
extern int opW9_logConsoleRect0Y;	// NOTE: placeholder name (0xd01a18)
extern int opW9_logConsoleRect0Width;	// NOTE: placeholder name (0xd01a1c)
extern int opW9_logConsoleRect0Height;	// NOTE: placeholder name (0xd01a20)
extern int opW9_logConsoleRect2Y;	// NOTE: placeholder name (0xd01a38)
extern Rect opW9_logRects[];	// NOTE: placeholder name (0xd30234)
extern Rect opW9_logConsoleRects[];	// NOTE: placeholder name (0xd01a14)
extern int opW9_logRect0Width;	// NOTE: placeholder name (0xd3023c, opW9_logRect0Width)
extern int opW9_logRect0Height;	// NOTE: placeholder name (0xd30240)
extern int opW9_logRect1Height;	// NOTE: placeholder name (0xd30250)
extern int opW9_logExpandedWidth;	// NOTE: placeholder name (0xd358b8)
extern int opW9_logExpandedHeight;	// NOTE: placeholder name (0xd358bc)
extern int opW9_cebd5c;	// NOTE: placeholder name
extern int opW9_d28d18;	// NOTE: placeholder name
extern int opW9_d28d64;	// NOTE: placeholder name
extern int opW9_cf462c;	// NOTE: placeholder name
extern int opW9_caf12c;	// NOTE: placeholder name
extern bool opW9_ba7694[];	// NOTE: placeholder name
extern vector<int> opW9_d22590;	// NOTE: placeholder name
unsigned int opW9_minUnsigned(unsigned int a, unsigned int b);	// NOTE: placeholder name (0x9e2310)
int minInt(int a, int b);	// 0x9cdb30




















//==================================================================
// CModeReport / CMulticonsoleButton(s)
//==================================================================

class OpW9_Inventory : public Console	// NOTE: placeholder name (CInventory at 0xcec08c)
{
public:
	void unknown4aa7c0();	// NOTE: placeholder name
};
extern OpW9_Inventory *opW9_inventory;	// NOTE: placeholder name

class OpW9_ModeHost : public Console	// NOTE: placeholder name
{
public:
	void unknown4a9bb0();	// NOTE: placeholder name
};

class OpW9_World2	// NOTE: placeholder name (0xcefc4c)
{
public:
	bool unknown71bbd0();	// NOTE: placeholder name
};
extern OpW9_World2 *opW9_world2;	// NOTE: placeholder name

class OpW9_ModeSwitcher	// NOTE: placeholder name (0xcec034)
{
public:
	void unknown987b10(int mode);	// NOTE: placeholder name

	char pad00[0xb0];
	int unknownB0;	// NOTE: placeholder name
};
extern OpW9_ModeSwitcher *opW9_cec034;	// NOTE: placeholder name

extern int opW9_consoleMode;	// NOTE: placeholder name (0xd28d64)
extern XColor *opW9_cf6b24;	// NOTE: placeholder name
extern XColor *opW9_d25e0c;	// NOTE: placeholder name
extern XColor *opW9_d2981c;	// NOTE: placeholder name
extern XColor *opW9_colorBlack;	// NOTE: placeholder name (0xcfe674)
extern vector<XColor> opW9_d2b4bc;	// NOTE: placeholder name
extern const char opW9_modeChars[];	// NOTE: placeholder name (0xb8f714)
extern int opW9_d31680;	// NOTE: placeholder name
extern int opW9_d31684;	// NOTE: placeholder name
extern int opW9_d31688;	// NOTE: placeholder name
extern int opW9_d3168c;	// NOTE: placeholder name

class CModeReport : public Console
{
public:
	CModeReport(XConsole *parent, const Rect &rect, string text);

	virtual void update();

	unsigned int startTime;	// NOTE: placeholder name
};



class CMulticonsoleButton : public Console
{
public:
	CMulticonsoleButton(XConsole *parent, int x, int mode_);	// 0x48e820

	virtual bool isActive();
	virtual bool input(XEvent *event);

	void draw();	// NOTE: placeholder name

	int mode;	// NOTE: placeholder name
};

class CMulticonsoleButtons : public Console
{
public:
	CMulticonsoleButtons(XConsole *parent);

	virtual bool input(XEvent *event);

	void select(int previous);	// NOTE: placeholder name
	void unknown48e860();	// NOTE: placeholder name

	vector<CMulticonsoleButton*> buttons;	// NOTE: placeholder name
	CModeReport *report;	// NOTE: placeholder name
};






class CAllySymbol : public Console
{
public:
	CAllySymbol(XConsole *parent);	// 0x48e8e0
	void unknown48e920(HEntity entity);	// NOTE: placeholder name
	virtual void refresh();
};

//==================================================================
// CAlly / CAllies
//==================================================================

struct OpW9_AIOrder	// NOTE: placeholder name
{
	bool unknown0;	// NOTE: placeholder name
	int unknown4;	// NOTE: placeholder name
	class HEntity *dummy;	// NOTE: placeholder layout
};

class EntityAI	// NOTE: placeholder layout
{
public:
	bool unknown458eb0();	// NOTE: placeholder name
	struct OpW9_AITarget *unknown459050();	// NOTE: placeholder name
	int unknown459280();	// NOTE: placeholder name
	void unknown5b5380(class OpW9_Order *order);	// NOTE: placeholder name
};

class Entity	// NOTE: placeholder layout
{
public:
	Pos &getPosition() throw();	// 0x45a4a0
	const XColor &unknown5c7810();	// NOTE: placeholder name
	const string &getNameAt0c();	// NOTE: placeholder name (folded getter 0x416f40)
	int getAscii(const Pos &p);	// 0x5c7a10
	XColor *unknown5ca2b0();	// NOTE: placeholder name
	EntityAI *getAI();	// NOTE: placeholder name (folded getter 0x45b590)
	int getFaction();
	int getSize();
	Pos unknown45a4c0();	// NOTE: placeholder name
	bool unknown45aaa0(HEntity entity);	// NOTE: placeholder name
	void *getTarget();
	struct OpW9_EntityData *getData();	// NOTE: placeholder name (folded getter 0x9b4350)
};
struct OpW9_EntityData	// NOTE: placeholder name
{
	char pad000[0x158];
	int unknown158;	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();
	void clear() throw();	// 0x9b7270
	bool isValid() const;
	bool isNull() const;
	Entity *operator->() const throw();	// 0x9b6570
	bool operator==(HEntity other) const;	// 0x9b78e0
	bool operator!=(HEntity other) const;
};

struct OpW9_AITarget	// NOTE: placeholder name
{
	bool unknown0;	// NOTE: placeholder name
	int unknown4;	// NOTE: placeholder name
	HEntity target;	// NOTE: placeholder name
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp();
};

struct OpW9_Pair	// NOTE: placeholder name
{
	OpW9_Pair(int value);	// 0x409990
	int a;
	int b;
};

class Cell
{
public:
	HEntity getEntity();
	bool unknown4550b0();	// NOTE: placeholder name (folded getter)
	bool unknown45db70();	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Pos &p);	// 0x9ced70
};
extern Array2D<Cell *> opW9_cells;	// NOTE: placeholder name (0xcfd44c)

class OpW9_Info : public Console	// NOTE: placeholder name (CInfo at 0xcec11c)
{
public:
	void unknown8b4500(HEntity entity, HProp a, HProp b, const OpW9_Pair &c, int d, int e);	// NOTE: placeholder name
};

class CAlly;
class CAllies : public Console
{
public:
	CAllies(XConsole *parent);

	virtual bool input(XEvent *event);
	virtual void update();
	virtual void open();
	virtual void close();
	virtual void trigger(const string &command, int value);

	void unknown7b7980();	// NOTE: placeholder name
	void beginOrder();	// NOTE: placeholder name (0x7b8200)
	void endOrder();	// NOTE: placeholder name (0x7b8290)
	void unknown7b8500(HEntity entity);	// NOTE: placeholder name
	void scrollTop();	// NOTE: placeholder name
	void scrollBottom();	// NOTE: placeholder name
	void scrollUp();	// NOTE: placeholder name (0x7b78a0)
	void scrollDown();	// NOTE: placeholder name (0x7b78e0)
	void unknown7b8340(const Pos &pos);	// NOTE: placeholder name
	bool unknown48f040(HEntity e);	// NOTE: placeholder name
	HEntity unknown48f120();	// NOTE: placeholder name
	bool unknown48f210();	// NOTE: placeholder name
	void unknown48f310();	// NOTE: placeholder name
	bool getUnknown48f0a0();	// NOTE: placeholder name
	void unknown48f2d0();	// NOTE: placeholder name
	void unknown48f2f0();	// NOTE: placeholder name
	void setUnknownA4(int value);	// NOTE: placeholder name (folded setter)
	vector<HEntity> *getUnknown94();	// NOTE: placeholder name (0x48f0e0)
	bool getUnknown48f0c0();	// NOTE: placeholder name

	bool opened;	// NOTE: placeholder name
	unsigned int closeTime;	// NOTE: placeholder name
	vector<CAlly*> allies;	// NOTE: placeholder name
	int scroll;	// NOTE: placeholder name
	CAlly *upArrow;	// NOTE: placeholder name
	CAlly *downArrow;	// NOTE: placeholder name
	bool unknown90;	// NOTE: placeholder name
	bool unknown91;	// NOTE: placeholder name
	vector<HEntity> unknown94;	// NOTE: placeholder name
	int unknownA4;	// NOTE: placeholder name
	bool unknownA8;	// NOTE: placeholder name
	int unknownAc;	// NOTE: placeholder name
};
extern Rect opW9_alliesRect;	// NOTE: placeholder name (0xd31680)
extern CAllies *opW9_allies;	// NOTE: placeholder name (0xcec0c8)
void opW9_unknown7b8bc0(HEntity entity, bool value);	// NOTE: placeholder name


extern XColor *opW9_d20b70;	// NOTE: placeholder name
extern XColor opW9_d29804;	// NOTE: placeholder name
extern XColor *opW9_d30264;	// NOTE: placeholder name
extern const int opW9_b96600[];	// NOTE: placeholder name
extern float opW9_ba6ae0;	// NOTE: placeholder name
float opW9_pulse(float low, float high, int period, int offset);	// NOTE: placeholder name (0x4371a0)

class CAlly : public Console
{
public:
	CAlly(XConsole *parent, int y, int number_, HEntity entity_, int type_);	// 0x48e980
	void setNumber(int number_);	// NOTE: placeholder name (folded setter 0x4ec710)

	virtual bool isActive();
	virtual void refresh();
	virtual bool input(XEvent *event);
	virtual void update();
	virtual void render();

	void unknown48eab0();	// NOTE: placeholder name
	void unknown48eea0();	// NOTE: placeholder name

	HEntity entity;
	int type;	// NOTE: placeholder name
	int number;	// NOTE: placeholder name
	Console *label;	// NOTE: placeholder name
	int unknown7c;	// NOTE: placeholder name
	HEntity unknown80;	// NOTE: placeholder name
	bool highlighted;	// NOTE: placeholder name
	int status;	// NOTE: placeholder name
};
















int opW9_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
template <class T> bool opW9_contains(vector<T> &v, T value);	// NOTE: placeholder name (0x9db330)


extern int opW9_d1e848;	// NOTE: placeholder name
extern bool opW9_d28e06;	// NOTE: placeholder name



int opW9_unknown7b9750(int order, HEntity target, const Pos &pos);	// NOTE: placeholder name
void opW9_unknown7b9540(int order, vector<HEntity> &targets, const Pos &pos);	// NOTE: placeholder name
template <class T> bool opW9_erase(vector<T> &v, T e);	// NOTE: placeholder name (0x9d2f00)

class OpW9_Message	// NOTE: placeholder name (0x20 bytes, ctor 0x510d20)
{
public:
	OpW9_Message(int type, int a, int b, int c, HProp d, HProp e);
	int pad[8];
};
class OpW9_MessageLog2 : public XConsole	// NOTE: placeholder name (0xcec0f4)
{
public:
	void add(OpW9_Message *message);	// NOTE: placeholder name (0x7b1880)
};



template <class T> void opW9_eraseAt(vector<T> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440)
string opW9_unknown407a80(int count, const string &text);	// NOTE: placeholder name
void opW9_showWarning(int type, const string &text, int a, int b, HEntity entity, HProp prop, int c);	// NOTE: placeholder name (0x7b1750)


extern CList *opW9_activeList;	// NOTE: placeholder name (0xcec130)
extern string opW9_orderNames[];	// NOTE: placeholder name (0xd2ed90)
extern const bool opW9_orderAllowed[][10];	// NOTE: placeholder name (0xb96630)
extern int opW9_caf128;	// NOTE: placeholder name
extern int opW9_caf164;	// NOTE: placeholder name
extern int opW9_cf27ec;	// NOTE: placeholder name
extern int opW9_cf27f0;	// NOTE: placeholder name
extern int opW9_cf27f4;	// NOTE: placeholder name
extern int opW9_cf27f8;	// NOTE: placeholder name
void opW9_orderListCallback(int id, const string &option);	// NOTE: placeholder name (0x7b9340)


int opW9_findString(string *strings, int count, string text);	// NOTE: placeholder name (0x9cda80)


class OpW9_Order	// NOTE: placeholder name (0x1c bytes, PropPoints458bd0)
{
public:
	OpW9_Order(int type, HEntity target, const Pos &pos);
	int pad[7];
};

class OpW9_Strings	// NOTE: placeholder name (0xd2c658)
{
public:
	void unknown4729d0(int id, int value, string text, int flag);	// NOTE: placeholder name
};
extern OpW9_Strings opW9_d2c658;	// NOTE: placeholder name
void opW9_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)



//==================================================================
// CIntel
//==================================================================

void opW9_fillInt(int *values, unsigned int count, int value);	// NOTE: placeholder name (0x9e2be0)
void opW9_fillBool(bool *values, unsigned int count, bool value);	// NOTE: placeholder name (0x9cdcc0)
extern Rect opW9_intelRect;	// NOTE: placeholder name (0xd1e844)

class CIntelSymbol : public Console
{
public:
	CIntelSymbol(XConsole *parent);	// 0x48f3e0
};

class CIntelLine : public Console
{
public:
	CIntelLine(XConsole *parent, int y, int number_, int category_, int type_);	// 0x48f420

	virtual void refresh();
	virtual bool input(XEvent *event);
	virtual void update();

	void setNumber(int number_);	// NOTE: placeholder name (folded setter)
	void unknown48f7a0();	// NOTE: placeholder name
	void unknown7b9ab0();	// NOTE: placeholder name
	void unknown48f550();	// NOTE: placeholder name

	int category;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
	int number;	// NOTE: placeholder name
	unsigned int count;	// NOTE: placeholder name
	Console *label;	// NOTE: placeholder name
};

class CIntel : public Console
{
public:
	CIntel(XConsole *parent);

	virtual bool input(XEvent *event);
	virtual void update();
	virtual void open();
	virtual void close();
	virtual void trigger(const string &command, int value);

	void unknown7ba190();	// NOTE: placeholder name
	void scrollUp();	// NOTE: placeholder name
	void scrollDown();	// NOTE: placeholder name
	void scrollTop();	// NOTE: placeholder name
	void scrollBottom();	// NOTE: placeholder name
	void beginSelect();	// NOTE: placeholder name
	void endSelect();	// NOTE: placeholder name
	void unknown48f940(int category);	// NOTE: placeholder name
	void unknown48f9e0(int category);	// NOTE: placeholder name
	void unknown48fa80();	// NOTE: placeholder name
	bool getSelecting();	// NOTE: placeholder name (folded getter 0x48f8b0)
	bool unknown48f8d0(int category);	// NOTE: placeholder name

	bool opened;	// NOTE: placeholder name
	unsigned int closeTime;	// NOTE: placeholder name
	vector<CIntelLine*> lines;	// NOTE: placeholder name
	int filters[20];	// NOTE: placeholder name
	int scroll;	// NOTE: placeholder name
	CIntelLine *upArrow;	// NOTE: placeholder name
	CIntelLine *downArrow;	// NOTE: placeholder name
	bool selecting;	// NOTE: placeholder name
	bool unknownE1[20];	// NOTE: placeholder name
	bool unknownF5;	// NOTE: placeholder name
	int unknownF8;	// NOTE: placeholder name
};













extern CIntel *opW9_intel;	// NOTE: placeholder name (0xcec0cc)



extern string opW9_intelNames[];	// NOTE: placeholder name (0xd2eec8)



//==================================================================
// Console (out-of-line members)
//==================================================================






//==================================================================
// CCloseButton / CInterfaceMsg
//==================================================================

class OpW9_KeyMap2	// NOTE: placeholder name (0xcefa8c)
{
public:
	bool hasCommand(int command);	// NOTE: placeholder name (0x416200)
};

class OpW9_ItemTag	// NOTE: placeholder name (CItemTag at 0xcec0a0)
{
public:
	bool isOpen_4ab690();	// NOTE: placeholder name (folded getter)
	void close_8ac1f0();	// NOTE: placeholder name (CItemTag::close)
};
extern OpW9_ItemTag *opW9_itemTag;	// NOTE: placeholder name (0xcec0a0)
extern Console *opW9_cec104;	// NOTE: placeholder name

class CTextButton : public Console
{
public:
	string text;
};

class CCloseButton : public CTextButton
{
public:
	virtual bool input(XEvent *event);

	int command;
};


struct OpW9_MsgStyle	// NOTE: placeholder name
{
	char pad00[0x20];
	int unknown20;	// NOTE: placeholder name
	int unknown24;	// NOTE: placeholder name
};
struct OpW9_MsgSource	// NOTE: placeholder name
{
	char pad00[0x24];
	OpW9_MsgStyle *style;	// NOTE: placeholder name
};
extern OpW9_MsgStyle *opW9_defaultMsgStyle;	// NOTE: placeholder name (0xcefbc8)

struct OpW9_InterfaceMessage	// NOTE: placeholder name (0x20 bytes, ctor 0x510d20)
{
	OpW9_InterfaceMessage(int type, int a, int b, int c, HEntity d, HProp e);

	OpW9_MsgSource *source;	// NOTE: placeholder name
	string text;	// NOTE: placeholder name
};

class OpW9_KeyHelper	// NOTE: placeholder name (0xcefa90)
{
public:
	void unknown41a210(int index);	// NOTE: placeholder name
};
extern OpW9_KeyHelper *opW9_keyHelper;	// NOTE: placeholder name

class CInterfaceMsg : public Console
{
public:
	virtual void update();
	virtual void close();

	void add(OpW9_InterfaceMessage *message);	// NOTE: placeholder name
	void hide();	// NOTE: placeholder name

	unsigned int closeTime;	// NOTE: placeholder name
	vector<OpW9_InterfaceMessage*> messages;
	int current;	// NOTE: placeholder name
	bool unknown84;	// NOTE: placeholder name
	unsigned int openTime;	// NOTE: placeholder name
};
extern CInterfaceMsg *opW9_interfaceMsg;	// NOTE: placeholder name (0xcec0f4)

struct OpW9_MapRecord	// NOTE: placeholder name
{
	char pad00[0x20];
	int unknown20;	// NOTE: placeholder name
};
extern vector<OpW9_MapRecord*> opW9_messageTypes;	// NOTE: placeholder name (0xd01c04)

class OpW9_World3	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer() throw();	// 0x4630f0
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	bool isVisible(HProp p);	// NOTE: placeholder name (BS::isVisible)
};






extern XColor *opW9_d25e0c;	// NOTE: placeholder name
extern XColor *opW9_cf6b24;	// NOTE: placeholder name


//==================================================================
// CTextInput / CTemp
//==================================================================

class OpW9_Clipboard	// NOTE: placeholder name (0xcefa98)
{
public:
	bool getText(string &text);	// NOTE: placeholder name (0x41ae40)
};
extern OpW9_Clipboard *opW9_clipboard;	// NOTE: placeholder name
extern bool opW9_ctrlHeld;	// NOTE: placeholder name (0xcec14d)
extern const int opW9_invalidFileChars[];	// NOTE: placeholder name (0xcaecf8)
bool opW9_between(int lo, int v, int hi);	// NOTE: placeholder name (0x9daf80)
bool opW9_inArray(const int *a, unsigned int n, int e);	// NOTE: placeholder name (0x9d43b0)

class CTextInput : public Console
{
public:
	virtual void inputAscii(int key, int type);

	string text;
	int cursor;
	bool unknown8c;	// NOTE: placeholder name
	int maxLength;	// NOTE: placeholder name
	bool numeric;	// NOTE: placeholder name
	bool skipNext;	// NOTE: placeholder name
	vector<int> blockedKeys;	// NOTE: placeholder name
	bool uppercase;	// NOTE: placeholder name
	bool trimLeading;	// NOTE: placeholder name
	bool unknownAa;	// NOTE: placeholder name
	void (*doneCallback)(int cancelled);	// NOTE: placeholder name
	int result;	// NOTE: placeholder name
	void (*historyCallback)(bool down);	// NOTE: placeholder name
	void (*typeCallback)();	// NOTE: placeholder name
	void (*matchCallback)();	// NOTE: placeholder name
	string matchText;	// NOTE: placeholder name
	bool (*specialCallback)(int key);	// NOTE: placeholder name
	void (*keyHook)(int key, int type);	// NOTE: placeholder name
};


class CTemp : public Console
{
public:
	virtual void update();
};


//==================================================================
// Console subclasses (0x48e1d0 ..)
//==================================================================

extern XColor *opT1_cf6b24;	// NOTE: placeholder name
extern struct OpT1_Dim { int width; int unk[3]; } opT1_d3023c[];	// NOTE: placeholder name

class CLogSizeButton : public Console
{
public:
	CLogSizeButton(XConsole *parent);	// 0x48e1d0
	void unknown48e250(bool expanded_);	// NOTE: placeholder name

	bool expanded;	// NOTE: placeholder name
};

CLogSizeButton::CLogSizeButton(XConsole *parent)
	: Console(parent,3,1,0,0,0,false,-1)
{
	unknown48e250(true);
}

void CLogSizeButton::unknown48e250(bool expanded_)
{
	expanded = expanded_;
	setPos(Pos(1,getParent()->getHeight() - 1));
	setFore(*opT1_cf6b24);
	print(0,0,expanded ? "[+]" : "[-]");
	clearBack();
}

CLogMsg::CLogMsg(XConsole *parent, int y, LogMsg *msg_, int type)
	: Console(parent,opT1_d3023c[type].width,1,0,y,0,false,-1)
{
	msg = msg_;
	print(0,0,msg->text);
}

extern OpW9_LogStyle *opT1_defaultLogStyle;	// NOTE: placeholder name (0xcefbcc)
extern vector<LogMsg*> opT1_d2f75c;	// NOTE: placeholder name
extern vector<LogMsg*> opT1_cf1080;	// NOTE: placeholder name
extern int opT1_cebd5c;	// NOTE: placeholder name

void CLogMsg::colorize(int index)
{
	unknown48c3c0(opW9_cfe704[msg->source ? opW9_logStyles[msg->source->unknown24]->colors[index] : opT1_defaultLogStyle->colors[index]]);
}

vector<LogMsg*> *CLogMsgs::getMessages()
{
	vector<LogMsg*> *messages = type == 2 ? &opT1_d2f75c : &opT1_cf1080;
	return messages;
}

CLog *CLogMsgs::getLog()
{
	switch (type)
	{
		case 0:
			return opW9_log0;
		case 1:
			return opW9_log1;
		case 2:
			return opW9_log2;
	}
	return NULL;
}

CLogMsgs *CLog::getMessages()
{
	switch (mode)
	{
		case 0:
			return opW9_logMsgs0;
		case 1:
			return opW9_logMsgs1;
		case 2:
			return opW9_logMsgs2;
	}
	return NULL;
}

bool CLog::unknown48e7b0()
{
	return opT1_cebd5c == 2 && getPos().y == 0;
}


CMulticonsoleButton::CMulticonsoleButton(XConsole *parent, int x, int mode_)
	: Console(parent,1,1,x,0,0,false,-1)
	, mode		(mode_)
{
}

void CMulticonsoleButtons::unknown48e860()
{
	for (unsigned int i = 0; i < buttons.size(); i++)
		buttons[i]->draw();
}

CAllySymbol::CAllySymbol(XConsole *parent)
	: Console(parent,1,1,3,0,2,false,-1)
{
}

void CAllySymbol::unknown48e920(HEntity entity)
{
	putChar_418110(0,0,entity->getAscii(entity->getPosition()),entity->unknown5c7810());
}

CAlly::CAlly(XConsole *parent, int y, int number_, HEntity entity_, int type_)
	: Console(parent,opW9_alliesRect.width - 2,1,1,y,0,false,3)
	, entity	(entity_)
	, type		(type_)
	, number	(number_)
	, label		(NULL)
	, highlighted	(false)
	, status	(0)
{
	if (type == 1)
	{
		label = new CAllySymbol(this);
		((CAllySymbol*)label)->unknown48e920(entity);
	}
	unknown48eab0();
}

bool CAllies::unknown48f040(HEntity e)
{
	for (unsigned int i = 0; i < allies.size(); i++)
	{
		if (allies[i]->entity == e)
			return true;
	}
	return false;
}

HEntity CAllies::unknown48f120()
{
	if (!allies.empty() && contains(opW9_mouse->getPos()))
	{
		for (unsigned int i = 0; i < allies.size(); i++)
		{
			if (allies[i]->entity.operator->() && allies[i]->contains(opW9_mouse->getPos()))
				return allies[i]->entity;
		}
	}
	return HEntity();
}

bool CAllies::unknown48f210()
{
	return contains(opW9_mouse->getPos()) && !allies.empty() && allies.front()->entity.isNull() && allies.front()->contains(opW9_mouse->getPos());
}

void CAllies::unknown48f310()
{
	for (unsigned int i = 0; i < allies.size(); i++)
	{
		if (allies[i]->label && allies[i]->entity.operator->())
			((CAllySymbol*)allies[i]->label)->unknown48e920(allies[i]->entity);
	}
}

void CAllies::unknown48f2d0()
{
	unknown94.clear();
}

CIntelSymbol::CIntelSymbol(XConsole *parent)
	: Console(parent,1,1,3,0,2,false,-1)
{
}

extern const char opT1_intelChars[];	// NOTE: placeholder name (0xb9e258)

CIntelLine::CIntelLine(XConsole *parent, int y, int number_, int category_, int type_)
	: Console(parent,opW9_intelRect.width - 2,1,1,y,0,false,3)
	, category	(category_)
	, type		(type_)
	, number	(number_)
	, count		(-1)
	, label		(NULL)
{
	if (type == 1 && opT1_intelChars[category] != ' ')
	{
		label = new CIntelSymbol(this);
		label->putChar_4180b0(0,0,opT1_intelChars[category]);
	}
	unknown48f550();
}

bool opw6_truncate408220(string &text, unsigned int length, int unknown);	// NOTE: placeholder name
extern string opT1_intelNames[];	// NOTE: placeholder name (0xd1db08)

void CIntelLine::unknown48f550()
{
	clearRow(6,0,getWidth() - 6);
	string text = category == 20 ? string("[ALL]") : opT1_intelNames[category];
	if (type == 1)
	{
		text += " (";
		count = (*opW9_world->unknown463ec0())[category].size();
		text += intToString(count);
		text += ")";
		opw6_truncate408220(text,opW9_intelRect.width - 10,0);
	}
	print(6,0,text);
}

extern string opT1_allyAnimNames[];	// NOTE: placeholder name (0xd21b48)

void CAlly::unknown48eab0()
{
	clearRow(8,0,getWidth() - 8);
	string text = entity.isValid() ? entity->getNameAt0c() : string("[ALL]");
	if (type == 1)
	{
		OpW9_AITarget *aiTarget = entity->getAI()->unknown459050();
		unknown7c = aiTarget->unknown4;
		text += " - " + opW9_orderNames[unknown7c];
		if (opW9_b96600[unknown7c] == 2)
		{
			unknown80 = aiTarget->target;
			text += " " + (unknown80.operator->() ? unknown80->getNameAt0c() : string("N/A"));
		}
		else
			unknown80.clear();
	}
	opw6_truncate408220(text,opW9_alliesRect.width - 12,0);
	print(8,0,text);
}

void CAlly::unknown48eea0()
{
	animate(type >= 2 ? string("A_CAlly_Button") : opT1_allyAnimNames[status]);
}

void CIntelLine::unknown48f7a0()
{
	engine->stopAll();
	clearBack();
	unknown7b9ab0();
}

void CIntelLine::refresh()
{
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_ALLY_HOV_OK");
}

void CIntel::unknown48f940(int category)
{
	if (filters[category] == 0)
		return;
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		if (lines[i]->type == 1 && lines[i]->category == category)
		{
			filters[category] = -1;
			return;
		}
	}
	filters[category] = 1;
}

void CIntel::unknown48f9e0(int category)
{
	filters[category] = filters[category] != 1;
	unknownE1[category] = true;
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		if (lines[i]->category == category)
		{
			lines[i]->unknown48f7a0();
			break;
		}
	}
	opW9_intel->endSelect();
}
