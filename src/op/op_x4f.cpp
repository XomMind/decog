// op_x4f: functions in 0x806f30-0x80e390 of COGMIND.exe (Beta 17.1). Names are placeholders unless stated.
#include <string>
#include <vector>
#include <cmath>
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
	Pos(int v);	// 0x409990
	void set_409ff0(int v);	// NOTE: placeholder name (sets both coordinates)
	Pos(const Pos &pos) throw();
	void set(int x_, int y_);	// 0x40a010 NOTE: placeholder name
	Pos &operator+=(const Pos &pos);	// 0x409a30
	Pos operator-(const Pos &pos) const;	// 0x409b30
	Pos &operator*=(const Pos &pos);	// 0x409ab0 NOTE: placeholder name
	Pos &operator/=(const Pos &pos);	// 0x409af0 NOTE: placeholder name
	bool operator!=(const Pos &pos) const;	// 0x409bd0
	bool equals_409cb0(int x_, int y_);	// NOTE: placeholder name
	bool differs_409cf0(int x_, int y_);	// NOTE: placeholder name
	Pos &operator=(const Pos &pos);	// 0x46ca50
	Pos operator+(const Pos &pos) const;	// 0x409b60
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
	void set(int x_, int y_, int width_, int height_);	// 0x40a840 NOTE: placeholder name
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
	bool inBounds(int x, int y);	// 0x417360
	int getWidth();
	int getHeight();
	Pos getPos();
	Pos absToLocal(Pos pos);
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
	void unknown429fe0(XConsole *console, const Pos &pos, int value);	// NOTE: placeholder name
	void clearInterior();
	int getSubconsoleIndex(XConsole *console);	// 0x417eb0
	void moveSubconsole(XConsole *console, int index);
	int countLines_418350(int x, int y, int width, int height, int align, const string &text);
	int countLines_418300(int x, int y, int width, int height, const string &text);
	int printWrapped_418260(int x, int y, int width, int height, const string &text);
	string getString(const Pos &p, unsigned int length);

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
	bool inputBase_429d00(void *event);	// NOTE: placeholder name
	Rect getRect();	// NOTE: placeholder name
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void setTitle(class ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void unknown7b0640(int a, XColor color, int b, int c);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	void *title;
};

typedef Pos Point;

//==================================================================
// game-side declarations (partial; placeholder names)
//==================================================================

struct OpX4f_ItemType;

class Item	// NOTE: partial
{
public:
	string unknown571db0(bool a, bool b);	// NOTE: placeholder name
	int unknown44aec0();	// NOTE: placeholder name (ICF'd trivial getter)
	OpX4f_ItemType *unknown9b4350();	// NOTE: placeholder name (ICF'd trivial getter)
	void *getEffect(int type);	// 0x457b70
};

class HItem
{
public:
	int ID;
	bool isValid() const;
	Item *operator->() const;	// 0x9b65b0
};

class Entity	// NOTE: partial
{
public:
	Pos &getPosition();	// NOTE: placeholder name
	bool isPlayer();	// 0x5c7600
	class OpX4f_AI *getAI();	// NOTE: placeholder name (0x45b590)
	HItem unknown5d2380(int type);	// NOTE: placeholder name
	int unknown5c7d30();	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();
	bool isValid() const;	// 0x9b7230
	void reset();	// 0x9b7270
	Entity *operator->() const;	// 0x9b6570
};

class Prop	// NOTE: partial
{
public:
	const string &getName();	// 0x45c5b0
};

class HProp
{
public:
	int ID;
	HProp();
	bool isValid() const;
	Prop *operator->() const;	// 0x9b64f0
};

class Area;
template <class T>
class Array2D	// NOTE: partial
{
public:
	int width;
	int height;
	T *data;

	T &operator()(const Point &p);	// 0x9ced70
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
	void getRect(const Point &p, int radius, Area &out);	// NOTE: placeholder name (0x9b4430)
	T &operator()(int x, int y);	// 0x9ceda0
	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
};

struct OpX4f_Region : public Array2D<int>	// NOTE: placeholder name
{
	int value;
	Point center;
	int radius;
};

class World	// NOTE: placeholder name (the object behind the global at 0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
	bool isVisible(const Point &p);	// 0x4631c0
	char pad0[0x66c];
	HEntity unknown66c;	// NOTE: placeholder name
	char pad670[0x69c - 0x670];
	Array2D<int> unknown69c;	// NOTE: placeholder name
	char pad6a8[0x6d8 - 0x6a8];
	vector<OpX4f_Region*> unknown6d8;	// NOTE: placeholder name
	bool unknown7168e0(const Point &from, const Point &to, Entity *e, vector<Point> &path);	// NOTE: placeholder name
};
extern World *opX4f_world;	// NOTE: placeholder name (0xcefc4c)
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name

struct OpX4f_InterfaceMessage	// NOTE: placeholder name (0x20 bytes, ctor 0x510d20)
{
	OpX4f_InterfaceMessage(int type, int a, int b, int c, HEntity d, HProp e);

	char pad00[0x20];
};

class OpX4f_InterfaceMsg	// NOTE: placeholder name (CInterfaceMsg at 0xcec0f4)
{
public:
	void add(OpX4f_InterfaceMessage *message);	// NOTE: placeholder name
};
extern OpX4f_InterfaceMsg *opX4f_interfaceMsg;	// NOTE: placeholder name (0xcec0f4)

class OpX4f_AI	// NOTE: placeholder name (EntityAI)
{
public:
	vector<Point> *unknown458ef0();	// NOTE: placeholder name
	bool unknown581140();	// NOTE: placeholder name
};

class Area	// NOTE: placeholder name (two corner points)
{
public:
	Area();	// 0x40b100
	bool fitAround_40bcb0(const Point &p, int margin);	// NOTE: placeholder name
	bool contains_40b750(const Point &p);	// NOTE: placeholder name

	Point min;
	Point max;
};
void OpX4f_placePoint_9d5460(vector<Point> &list, unsigned int index, Point p);	// NOTE: placeholder name

class Cell	// NOTE: partial
{
public:
	HEntity getEntity();	// 0x45d250
	bool unknown45db70();	// NOTE: placeholder name
	bool isOpen();	// NOTE: placeholder name (0x4550b0)
};

extern Array2D<Cell *> opX4f_cells;	// NOTE: placeholder name (0xcfd44c)

struct OpX4f_Scroll : public Pos	// NOTE: placeholder name (0xd1d9dc)
{
	char pad08;
	bool unknown09;	// NOTE: placeholder name
	bool unknown0a;	// NOTE: placeholder name
	char pad0b;
	unsigned int unknown0c;	// NOTE: placeholder name
};
extern OpX4f_Scroll opX4f_scroll;	// NOTE: placeholder name (0xd1d9dc)

extern Rect opX4f_screenRect;	// NOTE: placeholder name (0xcf27ec)
extern int opX4f_cebd5c;	// NOTE: placeholder name
extern int opX4f_cefab4;	// NOTE: placeholder name
extern int opX4f_cefab8;
extern Pos opX4f_cfbec0;	// NOTE: placeholder name
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)

class OpX4f_AnimItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class OpX4f_Engine	// NOTE: placeholder name (0xcefc64)
{
public:
	void unknown454d90(int anim);	// NOTE: placeholder name
	OpX4f_AnimItem *unknown50fb50(OpX4f_Engine *engine, int type, const Pos &a, const Pos &b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
};
extern OpX4f_Engine *opX4f_engine;	// NOTE: placeholder name (0xcefc64)

class Particle
{
public:
	Pos *getPos();	// 0x462e10
};
	// NOTE: placeholder name
void OpB_updateFontScale_446320();	// NOTE: placeholder name

class CAllies	// NOTE: partial
{
public:
	void endOrder();
};
extern CAllies *opX4f_allies;	// NOTE: placeholder name (0xcec0c8)

class SoundMgr	// NOTE: partial
{
public:
	void unknown454540();	// NOTE: placeholder name
};
extern SoundMgr opX4f_soundMgr;	// NOTE: placeholder name (0xd2d2a0)

int opX4f_maxInt(int a, int b) throw();	// NOTE: placeholder name (0x9cdb60)
extern bool opX4f_cefacd;	// NOTE: placeholder name
extern bool opX4f_d28c8a;	// NOTE: placeholder name
extern bool opX4f_d28d15;	// NOTE: placeholder name
extern int opX4f_screenWidth;	// NOTE: placeholder name (0xcf27f4)
extern int opX4f_screenHeight;	// NOTE: placeholder name (0xcf27f8)


class OpX4f_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	Pos getPos_40a970();	// NOTE: placeholder name
};
extern OpX4f_Mouse *opX4f_mouse;	// NOTE: placeholder name (0xcefa94)
extern XConsole *opX4f_mapConsole;	// NOTE: placeholder name (0xcec054)
extern vector<int> opX4f_d22590;	// NOTE: placeholder name
int opX4f_clamp(int low, int value, int high);	// NOTE: placeholder name (0x9cdc80)

struct OpX4f_GameStateData	// NOTE: placeholder name
{
	int pad0;
	int unknown4;	// NOTE: placeholder name
};
class OpX4f_HGameState	// NOTE: placeholder name
{
public:
	int ID;
	OpX4f_GameStateData *operator->() const;	// 0x9b7910
};
extern OpX4f_HGameState opX4f_gameState;	// NOTE: placeholder name (0xd1e888)

int OpU8a_indexOfEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d3110)
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0
struct OpQ5_U9da940	// NOTE: placeholder name
{
	int pad;
};

extern int opX4f_tickCountInt;	// NOTE: placeholder name (0xcaed20)

struct OpX4f_Cec084	// NOTE: placeholder name (object at 0xcec084)
{
	char pad00[0x8c];
	vector<int> unknown8c;	// NOTE: placeholder name
};
extern OpX4f_Cec084 *opX4f_cec084;	// NOTE: placeholder name

class OpX4f_Audio	// NOTE: placeholder name (0xcefaa8)
{
public:
	bool showOnce(int id, bool enabled, const string *text, bool repeat, bool flag);	// NOTE: placeholder name (0x793450)
};
extern OpX4f_Audio *opX4f_audio;	// NOTE: placeholder name

struct OpX4f_Path	// NOTE: placeholder name
{
	int pad0;
	vector<Point> points;
};
bool opX4f_findEffectID(const string &name, int *id);	// NOTE: placeholder name (0x9d7980)
int opX4f_maxInt2(int a, int b);	// NOTE: placeholder name (0x9cdb60)

class OpX4f_Effect	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class OpX4f_EffectMgr	// NOTE: placeholder name
{
public:
	OpX4f_Effect *create();	// NOTE: placeholder name (0x508610)
};
extern OpX4f_EffectMgr *opX4f_effectMgr;	// NOTE: placeholder name (0xcefc50)

void opX4f_clearDijkstraResults();	// NOTE: placeholder name
void opX4f_sweepGetSurroundingCells(const Point &point, vector<Point> &adjacent);	// 0x4faaf0
bool opX4f_fn9d3020(vector<Point> &v, Point p);	// NOTE: placeholder name
extern vector<Point> opX4f_dijkstraCells;	// NOTE: placeholder name (0xd15e58)

struct OpX4f_DijkstraCost	// NOTE: placeholder name
{
	int pad0;
	int pad4;
	int pad8;
	int padc;
};
extern OpX4f_DijkstraCost opX4f_dijkstraCost_d2c56c;	// NOTE: placeholder name
extern OpX4f_DijkstraCost opX4f_dijkstraCost_cefd18;	// NOTE: placeholder name

class OpX4f_DijkstraRunner	// NOTE: placeholder name (global at 0xcfe568)
{
public:
	void run(const Point &start, int range, void *cost, void *data);	// NOTE: placeholder name (0x40ca20)
	bool unknown40c9e0(const Point &from, const vector<Point> &goals, void *cost, void *data, vector<Point> &path);	// NOTE: placeholder name
};
extern OpX4f_DijkstraRunner opX4f_dijkstra;	// NOTE: placeholder name
extern void *opX4f_moveCost_cefc2c;	// NOTE: placeholder name (0xcefc2c)
int OpU8a_indexOfPoint(vector<Point> &v, Point p);	// NOTE: placeholder name (0x9d53a0)

int OpY1_round(float value);	// NOTE: placeholder name (0x406360)

class RNG
{
public:
	int rangeInt(float a, float b) throw();	// 0x406d70
};
extern RNG rng;	// 0xd30908

class OpX4f_XBuffer	// NOTE: placeholder name (base of the XBuffer* vector elements)
{
};

class OpX4f_XTimerH : public OpX4f_XBuffer	// NOTE: placeholder name (same layout as XTimerH 0x499d30; defined inline here so the callee is known not to throw)
{
public:
	OpX4f_XTimerH(const Pos &pos_, const Pos &pos2_, int a_, bool flag_, int b_)
		: pos(pos_)
		, pos2(pos2_)
	{
		tick = tickCount;
		unknown14 = -1;
		a = a_;
		flag = flag_;
		b = b_;
	};

	Pos pos;
	Pos pos2;
	unsigned int tick;
	int unknown14;
	int a;
	bool flag;
	int b;
};
extern Point opX4f_effectOrigin;	// NOTE: placeholder name (0xd2e20c)

struct OpX4f_Tip	// NOTE: placeholder name (8 bytes, ctor folded with Pos(int,int) 0x46ca20)
{
	Console *console;
	int time;

	OpX4f_Tip(Console *console_, int time_);
};

class OpX4f_XRoot	// NOTE: placeholder name
{
public:
	int getLayer(XConsole *console);	// 0x42dd70
};

class OpX4f_Rex	// NOTE: placeholder name (0xd223f0)
{
public:
	OpX4f_XRoot *getRoot_4ab670();	// NOTE: placeholder name (folded getter)
};
extern OpX4f_Rex opX4f_rex;	// NOTE: placeholder name (0xd223f0)
extern int opX4f_fontCellWidth;	// NOTE: placeholder name (0xcaf128)
extern int opX4f_d28f88;	// NOTE: placeholder name
extern string opX4f_d22cb8[];	// NOTE: placeholder name (0x1c-byte entries)
void OpC_stringFunc_408660(string &text, char c);	// NOTE: placeholder name

class CMap : public Console	// NOTE: partial layout
{
public:
	bool unknown805190(Pos *out);	// NOTE: placeholder name
	bool unknown8052f0(Pos *pos);	// NOTE: placeholder name
	void unknown8069e0(Point p, bool flag);	// NOTE: placeholder name
	bool unknown806f30(bool flag);	// NOTE: placeholder name
	void unknown807100(const Pos &pos);	// NOTE: placeholder name
	void unknown808020(HEntity entity);	// NOTE: placeholder name
	bool unknown805100();	// NOTE: placeholder name
	void warpMouse_806e70(const Pos &pos, bool flag);	// NOTE: placeholder name
	bool unknown8080a0();	// NOTE: placeholder name
	void unknown8079e0(OpX4f_Path *path);	// NOTE: placeholder name
	void unknown8071e0(HEntity entity, bool flag);	// NOTE: placeholder name
	void unknown8074d0(HEntity entity);	// NOTE: placeholder name
	void unknown807b40();	// NOTE: placeholder name
	void unknown80e0e0(HEntity entity);	// NOTE: placeholder name
	void unknown808860(const string &text, int type);	// NOTE: placeholder name
	void unknown808510(const Pos &center, int radius, vector<Point> &points);	// NOTE: placeholder name
	bool unknown8081d0();	// NOTE: placeholder name

	Pos unknown6c;	// NOTE: placeholder name
	char pad74[0x7c - 0x74];
	vector<vector<Point> > unknown7c;	// NOTE: placeholder name
	char pad8c[0xd0 - 0x8c];
	bool unknownd0;	// NOTE: placeholder name
	char padd1[3];
	unsigned int unknownd4;	// NOTE: placeholder name
	bool unknownd8;	// NOTE: placeholder name
	char padd9[3];
	unsigned int unknowndc;	// NOTE: placeholder name
	char pade0[0xe4 - 0xe0];
	Pos unknowne4;	// NOTE: placeholder name
	char padec[0x1a8 - 0xec];
	vector<OpX4f_XBuffer*> unknown1a8;	// NOTE: placeholder name
	char pad1b8[0x1c8 - 0x1b8];
	vector<struct OpX4f_Tip*> unknown1c8;	// NOTE: placeholder name
	char pad1d8[0x25c - 0x1d8];
	vector<HEntity> unknown25c;	// NOTE: placeholder name
	vector<int> unknown26c;	// NOTE: placeholder name
	char pad27c[0x3c8 - 0x27c];
	vector<Point> unknown3c8;	// NOTE: placeholder name
	int unknown3d8;	// NOTE: placeholder name
	unsigned int unknown3dc;	// NOTE: placeholder name
	bool unknown3e0;	// NOTE: placeholder name
	char pad3e1[0x3e4 - 0x3e1];
	vector<Area> unknown3e4;	// NOTE: placeholder name
	vector<Point> unknown3f4;	// NOTE: placeholder name
	vector<int> unknown404;	// NOTE: placeholder name
	int unknown414;	// NOTE: placeholder name
	int unknown418;	// NOTE: placeholder name
	unsigned int unknown41c;	// NOTE: placeholder name
	vector<OpX4f_Path*> unknown420;	// NOTE: placeholder name
	vector<int> unknown430;	// NOTE: placeholder name
	vector<int> unknown440;	// NOTE: placeholder name
	unsigned int unknown450;	// NOTE: placeholder name
};

bool CMap::unknown806f30(bool flag)
{
	Pos mousePos;
	bool valid = unknown805190(&mousePos);
	if (valid && unknown8052f0(&opX4f_world->getPlayer()->getPosition()))
	{
		Pos target = opX4f_world->getPlayer()->getPosition() + unknown6c;
		Pos cell = opX4f_mapConsole->absToLocal(opX4f_mouse->getPos_40a970());
		Pos delta = target - cell;
		int halfW = getWidth() / 2;
		int halfH = getHeight() / 2;
		delta.x = opX4f_clamp(-halfW,delta.x,halfW);
		delta.y = opX4f_clamp(-halfH,delta.y,halfH);
		if (delta != opX4f_scroll)
		{
			((Pos&)opX4f_scroll) = delta;
			opX4f_scroll.unknown0c = tickCount;
			opR1d_4541b0(0x38,0,0);
			unknown8069e0(opX4f_world->getPlayer()->getPosition(),false);
			opX4f_scroll.unknown0a = opX4f_scroll.differs_409cf0(0,0);
			if (!flag)
			{
				opX4f_scroll.unknown09 = true;
				opX4f_d22590[6] = 1;
			}
			else
				opX4f_d22590[7] = 1;
			return true;
		}
	}
	return false;
}

void CMap::unknown807100(const Pos &pos)
{
	if (opX4f_gameState->unknown4 == 8 || opX4f_gameState->unknown4 == 0xd)
	{
		for (unsigned int i = 0; i < unknown7c.size(); i++)
		{
			for (unsigned int j = 0; j < unknown7c[i].size(); j++)
			{
				if (unknown7c[i][j] == pos)
				{
					unknown7c[i][j].set_409ff0(-1);
					return;
				}
			}
		}
	}
}

void CMap::unknown808020(HEntity entity)
{
	int index = OpU8a_indexOfEntity(unknown25c,entity);
	if (index != -1)
	{
		OpQ5_eraseAt((vector<OpQ5_U9da940>&)unknown25c,index);
		removeVectorElement(unknown26c,index);
	}
	unknown25c.push_back(entity);
	unknown26c.push_back(opX4f_tickCountInt);
}

bool CMap::unknown8081d0()
{
	unknownd8 = !unknownd8;
	if (unknownd8)
	{
		unknowndc = tickCount;
		opR1d_4541b0(0x40,0,0);
		if (!unknown805100())
			warpMouse_806e70(opX4f_world->getPlayer()->getPosition(),true);
	}
	else
		opR1d_4541b0(0x3f,0,0);
	unknowne4.set_409ff0(-1);
	return unknownd8;
}

bool CMap::unknown8080a0()
{
	unknownd0 = !unknownd0;
	if (unknownd0)
	{
		unknownd4 = tickCount;
		opR1d_4541b0(0x3e,0,0);
		if (opX4f_cec084->unknown8c.empty())
			opX4f_interfaceMsg->add(new OpX4f_InterfaceMessage(0x6a,0,0,0,HEntity(),HProp()));
		opX4f_audio->showOnce(0xf,true,NULL,false,false);
	}
	else
		opR1d_4541b0(0x3f,0,0);
	return unknownd0;
}

void CMap::unknown8079e0(OpX4f_Path *path)
{
	unknown420.push_back(path);
	int interval = 600;
	int duration = 20;
	unknown430.push_back(opX4f_maxInt2(1,(int)(20.0 / (600.0 / (double)path->points.size()))));
	unknown440.push_back(0);
	unknown450 = tickCount - 20;
	opR1d_4541b0(0x133,0,0);
	int delay;
	opX4f_findEffectID("Block_Turn_Progress_SHOW_PATHS",&delay);
	opX4f_effectMgr->create()->init(opX4f_effectMgr,delay,Point(0,0),Point(0,0),0,0,0,9,0);
}

void CMap::unknown8071e0(HEntity entity, bool flag)
{
	vector<Point> adjacent;
	opX4f_clearDijkstraResults();
	if (flag)
	{
		opX4f_dijkstra.run(entity->getPosition(),0x19,&opX4f_dijkstraCost_d2c56c,entity.operator->());
		for (unsigned int i = 0; i < opX4f_dijkstraCells.size(); i++)
		{
			if (opX4f_cells(opX4f_dijkstraCells[i])->unknown45db70())
				unknown3c8.push_back(opX4f_dijkstraCells[i]);
			adjacent.clear();
			opX4f_sweepGetSurroundingCells(opX4f_dijkstraCells[i],adjacent);
			for (unsigned int j = 0; j < adjacent.size(); j++)
			{
				if (opX4f_cells.contains(adjacent[j]) && !opX4f_cells(adjacent[j])->isOpen())
					opX4f_fn9d3020(unknown3c8,adjacent[j]);
			}
		}
	}
	else
	{
		opX4f_dijkstra.run(entity->getPosition(),0x19,&opX4f_dijkstraCost_cefd18,entity.operator->());
		unknown3c8 = opX4f_dijkstraCells;
	}
	int delay = 600;
	int duration = 20;
	unknown3d8 = opX4f_maxInt2(1,(int)(20.0 / (600.0 / (double)unknown3c8.size())));
	unknown3dc = tickCount - 20;
	unknown3e0 = flag;
	opR1d_4541b0(0x131,0,0);
	int effect;
	opX4f_findEffectID("Block_Turn_Progress_MAP_WALLS",&effect);
	opX4f_effectMgr->create()->init(opX4f_effectMgr,effect,Point(0,0),Point(0,0),0,0,0,9,0);
}

void CMap::unknown8074d0(HEntity entity)
{
	vector<Point> *nodes = entity->getAI()->unknown458ef0();
	vector<Point> dx;
	opX4f_world->unknown7168e0((*nodes)[0],(*nodes)[1],entity.operator->(),dx);
	vector<Area> mapArea;
	vector<Point> ind;
	const int pointsList = 12;
	int val = 10;
	ind.push_back((*nodes)[0]);
	Area cells;
	opX4f_cells.getRect(ind.back(),pointsList,cells);
	mapArea.push_back(cells);
	unsigned int t = 0;
	while (t + val < dx.size())
	{
		t += val;
		ind.push_back(dx[t]);
		opX4f_cells.getRect(ind.back(),pointsList,cells);
		mapArea.push_back(cells);
	}
	if (t < dx.size() - 1)
	{
		ind.push_back((*nodes)[1]);
		opX4f_cells.getRect(ind.back(),pointsList,cells);
		mapArea.push_back(cells);
	}
	int buf = 0;
	dx.clear();
	if (opX4f_dijkstra.unknown40c9e0(entity->getPosition(),ind,opX4f_moveCost_cefc2c,entity.operator->(),dx))
		buf = OpU8a_indexOfPoint(ind,dx.back());
	unknown3e4.push_back(mapArea[buf]);
	unknown404.push_back(0);
	unknown414 = 1;
	unknown3f4.push_back(ind[buf]);
	for (int back2 = buf - 1, back = buf + 1; back2 >= 0 || back < mapArea.size(); back2--, back++, unknown414++)
	{
		if (back2 >= 0)
		{
			unknown3e4.push_back(mapArea[back2]);
			unknown404.push_back(unknown414);
			unknown3f4.push_back(ind[back2]);
		}
		if (back < mapArea.size())
		{
			unknown3e4.push_back(mapArea[back]);
			unknown404.push_back(unknown414);
			unknown3f4.push_back(ind[back]);
		}
	}
	int areas2 = 1600;
	int ret = 100;
	unknown418 = opX4f_maxInt2(1,(int)(100.0 / (1600.0 / (double)unknown414)));
	unknown41c = tickCount - 100;
	unknown414 = 0;
	opR1d_4541b0(0x132,0,0);
	int q;
	opX4f_findEffectID("Block_Turn_Progress_MAP_ROUTE",&q);
	opX4f_effectMgr->create()->init(opX4f_effectMgr,q,Point(0,0),Point(0,0),0,0,0,9,0);
}

void CMap::unknown807b40()
{
	int mid = 0;
	OpU8a_lookup1("CMap_LINK_FOV_Old",&mid);
	int size = 0;
	OpU8a_lookup1("CMap_LINK_FOV_New",&size);
	Array2D<int> *c = &opX4f_world->unknown69c;
	OpX4f_Region *arr = opX4f_world->unknown6d8.back();
	Array2D<int> *fxID = arr;
	int low = arr->value;
	Area anim2;
	opX4f_cells.getRect(arr->center,arr->radius,anim2);
	for (int spacing2 = anim2.min.x, result = anim2.min.x + unknown6c.x; spacing2 < anim2.max.x; spacing2++, result++)
	{
		for (int cx = anim2.min.y, py = anim2.min.y + unknown6c.y; cx < anim2.max.y; cx++, py++)
		{
			if ((*fxID)(spacing2,cx) == low && inBounds(result,py))
				opX4f_engine->unknown50fb50(opX4f_engine,(*c)(spacing2,cx) == 1 ? size : mid,Point(result,py),opX4f_cfbec0,NULL,NULL,9)->unknown50de10();
		}
	}
	opR1d_4541b0(0x134,0,0);
	int routePath;
	opX4f_findEffectID("Block_Turn_Progress_LINK_FOV",&routePath);
	opX4f_effectMgr->create()->init(opX4f_effectMgr,routePath,Point(0,0),Point(0,0),0,0,0,9,0);
}

void CMap::unknown808510(const Pos &center, int radius, vector<Point> &points)
{
	if (radius == 0)
		return;
	Point end(center.x - radius,center.y - radius);
	Point ind(center.x + radius,center.y + radius);
	float route = (ind.x - end.x) / 2.0;
	float mapPath = (ind.y - end.y) / 2.0;
	float nodeIndex = (end.x + ind.x) / 2.0;
	float pt = (end.y + ind.y) / 2.0;
	for (int high = end.x; high <= ind.x; high++)
	{
		opX4f_fn9d3020(points,Point(high,(int)(route == 0 ? pt : OpY1_round(sqrt(route * route * mapPath * mapPath - mapPath * mapPath * (high - nodeIndex) * (high - nodeIndex)) / route + pt))));
		opX4f_fn9d3020(points,Point(high,(int)(route == 0 ? pt : OpY1_round(-sqrt(route * route * mapPath * mapPath - mapPath * mapPath * (high - nodeIndex) * (high - nodeIndex)) / route + pt))));
	}
	for (int startIndex = end.y; startIndex <= ind.y; startIndex++)
	{
		opX4f_fn9d3020(points,Point((int)(mapPath == 0 ? nodeIndex : OpY1_round(sqrt(mapPath * mapPath * route * route - route * route * (startIndex - pt) * (startIndex - pt)) / mapPath + nodeIndex)),startIndex));
		opX4f_fn9d3020(points,Point((int)(mapPath == 0 ? nodeIndex : OpY1_round(-sqrt(mapPath * mapPath * route * route - route * route * (startIndex - pt) * (startIndex - pt)) / mapPath + nodeIndex)),startIndex));
	}
}

void CMap::unknown808860(const string &text, int type)
{
	if (!opX4f_d28f88)
		return;
	int anim2 = opX4f_mapConsole->getWidth() * opX4f_fontCellWidth - 6;
	int before = unknown1c8.empty() ? 1 : unknown1c8.back()->console->getPos().y + 2;
	int idx = countLines_418300(1,before,anim2,5,text);
	vector<string> area;
	if (idx == 1)
		area.push_back(text);
	else
	{
		Console *areaList = new Console(this,anim2,5,0,0,0,true,-1);
		int low = areaList->printWrapped_418260(0,0,areaList->getWidth(),areaList->getHeight(),text);
		for (int cell = 0; cell < low; cell++)
		{
			string kind = areaList->getString(Pos(0,cell),areaList->getWidth());
			OpC_stringFunc_408660(kind,' ');
			area.push_back(kind);
		}
		removeSubconsole(areaList);
	}
	int fxID = opX4f_rex.getRoot_4ab670()->getLayer(this) + 3;
	for (int pts = 0; pts < area.size(); pts++)
	{
		area[pts].insert(area[pts].begin(),2,' ');
		area[pts].append("  ");
		if (pts >= 1)
		{
			area[pts].insert(area[pts].begin(),2,' ');
			if (area[pts].size() < area[pts - 1].size())
				area[pts].insert(area[pts].end(),area[pts - 1].size() - area[pts].size(),' ');
		}
		unknown1c8.push_back(new OpX4f_Tip(new Console(opX4f_mapConsole,area[pts].size(),1,1,before,0,false,fxID),tickCount + opX4f_d28f88));
		unknown1c8.back()->console->print(0,0,area[pts]);
		unknown1c8.back()->console->animate("A_CLogMsg_Map_Alert_" + opX4f_d22cb8[type]);
		unknown1c8.back()->console->animate("A_CLogMsg_Map_Al_Fa_" + opX4f_d22cb8[type]);
		before++;
	}
}

void CMap::unknown80e0e0(HEntity entity)
{
	int effect;
	opX4f_findEffectID("Spotter_Scan",&effect);
	opX4f_effectMgr->create()->init(opX4f_effectMgr,effect,entity->getPosition(),opX4f_effectOrigin,0,0,0,9,0);
	Point pos = entity->getPosition();
	int scanRange = entity->unknown5c7d30();
	unknown1a8.push_back(new OpX4f_XTimerH(pos,unknown6c,rng.rangeInt(0.0,120.0),true,scanRange));
	unknown1a8.push_back(new OpX4f_XTimerH(pos,unknown6c,rng.rangeInt(60.0,210.0),false,scanRange));
	unknown1a8.push_back(new OpX4f_XTimerH(pos,unknown6c,rng.rangeInt(150.0,300.0),true,scanRange));
	unknown1a8.push_back(new OpX4f_XTimerH(pos,unknown6c,rng.rangeInt(240.0,360.0),false,scanRange));
}
