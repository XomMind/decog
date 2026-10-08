// op_v3f shared engine-side declarations (copied from op_w5.cpp; partial layouts, placeholder names)
#ifndef OP_V3F_H
#define OP_V3F_H
#include <string>
#include <vector>
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

	Pos();	// 0x453b40
	Pos(int x_, int y_);
	explicit Pos(int v);	// 0x409990
	void set_409ff0(int v);	// NOTE: placeholder name (sets both coordinates)
	void set(int x_, int y_);	// 0x40a010 NOTE: placeholder name
	Pos operator-(const Pos &pos) const;	// 0x409b30
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
	Pos absToLocal(Pos pos);
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
	~Engine();
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


//==================================================================
// game-side declarations (partial; placeholder names)
//==================================================================

typedef Pos Point;

class Item	// NOTE: partial
{
public:
	int unknown577a90();	// NOTE: placeholder name
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
	Item *operator->() const throw();	// 0x9b65b0
};

class Entity	// NOTE: partial
{
public:
	Pos &getPosition();	// NOTE: placeholder name
	Point unknown5c80f0(const Point &p);	// NOTE: placeholder name
	HItem unknown5d2380(int type);	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	Entity *operator->() const;
};

class World	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	HEntity getPlayer();	// NOTE: placeholder name (0x4630f0)

	char pad0[0x66c];
	HEntity unknown66c;	// NOTE: placeholder name
};
extern World *opV3F_world;	// NOTE: placeholder name (0xcefc4c)

class OpV3F_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	Pos getPos_40a970();	// NOTE: placeholder name
};
extern OpV3F_Mouse *opV3F_mouse;	// NOTE: placeholder name (0xcefa94)

template <class T> class Array2D	// NOTE: partial
{
public:
	int getWidth();
	int getHeight();
};
struct Cell;
struct XCell;
extern Array2D<Cell *> opV3F_cells;	// NOTE: placeholder name (0xcfd44c)

struct OpV3F_Dims	// NOTE: placeholder name (0xcfd44c)
{
	bool inBounds(int x, int y);	// NOTE: placeholder name
};

int minInt(int a, int b) throw();	// 0x9cdb30
int opV3F_maxInt(int a, int b) throw();	// NOTE: placeholder name (0x9cdb60)
extern int opV3F_screenWidth;	// NOTE: placeholder name (0xcf27f4)
extern int opV3F_screenHeight;	// NOTE: placeholder name (0xcf27f8)
extern Pos opV3F_d1d9dc;	// NOTE: placeholder name
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)

struct OpQ5_T9e2c40;
struct OpQ5_T9ef2e0;
struct OpQ5_T9ef340;
struct OpQ5_T9ef3a0;
template <class T> void OpQ5_clearObjects(vector<T*> &v);	// NOTE: placeholder name (0x9e2c40)

struct OpV3f_PathStep	// NOTE: placeholder name and layout (16-byte path element: the exe uses the 16-byte vector instances)
{
	Point pos;
	int unknown8;
	int unknownC;
};

class CMap : public Console	// NOTE: partial layout
{
public:
	void unknown7fe7a0();	// NOTE: placeholder name
	void centerPush_805020(Pos *out);	// NOTE: placeholder name
	bool unknown8050a0();	// NOTE: placeholder name
	bool unknown805100();	// NOTE: placeholder name
	bool unknown805190(Pos *out);	// NOTE: placeholder name
	void unknown8051f0(Pos *min, Pos *max);	// NOTE: placeholder name
	bool unknown8052f0(Pos *pos);	// NOTE: placeholder name
	int unknown805360(HEntity entity, vector<OpV3f_PathStep> *path, Point *target);	// NOTE: placeholder name
	int unknown8054b0(bool flag);	// NOTE: placeholder name

	// BEGIN CMAP FIELDS
	int scrollX;	// NOTE: placeholder name
	int scrollY;	// NOTE: placeholder name
	char pad74[0x124 - 0x74];
	vector<OpQ5_T9e2c40*> unknown124;	// NOTE: placeholder name
	char pad134[0x1A8 - 0x134];
	vector<OpQ5_T9e2c40*> unknown1a8;	// NOTE: placeholder name
	char pad1B8[0x1C8 - 0x1B8];
	vector<OpQ5_T9ef2e0*> unknown1c8;	// NOTE: placeholder name
	vector<OpQ5_T9ef340*> unknown1d8;	// NOTE: placeholder name
	char pad1E8[0x31C - 0x1E8];
	vector<OpQ5_T9e2c40*> unknown31c;	// NOTE: placeholder name
	vector<OpQ5_T9e2c40*> unknown32c;	// NOTE: placeholder name
	char pad33C[0x35C - 0x33C];
	vector<OpQ5_T9e2c40*> unknown35c;	// NOTE: placeholder name
	XConsole* unknown36c;	// NOTE: placeholder name
	XConsole* unknown370;	// NOTE: placeholder name
	int unknown374;	// NOTE: placeholder name
	char pad378[0x37C - 0x378];
	bool unknown37c;	// NOTE: placeholder name
	char pad37D[0x384 - 0x37D];
	int unknown384;	// NOTE: placeholder name
	char pad388[0x460 - 0x388];
	vector<OpQ5_T9ef3a0*> unknown460;	// NOTE: placeholder name
	char pad470[0x4C8 - 0x470];
	Point unknown4c8;	// NOTE: placeholder name
	char pad4D0[0x50C - 0x4D0];
	vector<OpV3f_PathStep> unknown50c;	// NOTE: placeholder name
	char pad51C[0x558 - 0x51C];
	XConsole* unknown558;	// NOTE: placeholder name
	char pad55C[0x798 - 0x55C];
	vector<Console*> unknown798;	// NOTE: placeholder name
	XConsole* unknown7a8;	// NOTE: placeholder name
	char pad7AC[0x7B0 - 0x7AC];
	vector<Console*> unknown7b0;	// NOTE: placeholder name
	// END CMAP FIELDS
};

#endif
