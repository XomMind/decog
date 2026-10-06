// op_x5_cmap: CMap member functions in 0x80f000-0x825e00 (partial CMap layout, placeholder names)
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(const Pos &pos) throw();
};

class XTimer	// NOTE: placeholder name
{
public:
	XTimer(int value_);	// NOTE: placeholder name

	int value;	// NOTE: placeholder name
	unsigned int tick;	// NOTE: placeholder name
};

class XTimerE	// NOTE: placeholder name
{
public:
	XTimerE(int a_, const Pos &pos_);	// NOTE: placeholder name

	int a;
	Pos pos;
	unsigned int tick;
};

class CMap
{
public:
	void unknown8195e0(int value);	// NOTE: placeholder name
	void unknown819840(int a, const Pos &pos);	// NOTE: placeholder name

	char pad0[0x2dc];
	vector<XTimer> timers2dc;	// NOTE: placeholder name
	char pad2ec[0x34c - 0x2ec];
	vector<XTimerE> timers34c;	// NOTE: placeholder name
};

void CMap::unknown8195e0(int value)
{
	timers2dc.push_back(XTimer(value));
}

void CMap::unknown819840(int a, const Pos &pos)
{
	timers34c.push_back(XTimerE(a,pos));
}

struct OpX5_Node	// NOTE: placeholder name
{
	OpX5_Node *getParent();	// 0x9b8f00
	virtual void unknown0();
	virtual void unknown4();
	virtual void unknown8();
	virtual void unknownC();
};

struct OpX5_Child	// NOTE: placeholder name
{
	void *vtable;
	OpX5_Node *parent;
	OpX5_Node *getParent();	// 0x9b8f00
	void unknown88e360();	// NOTE: placeholder name
	void unknown88e390();	// NOTE: placeholder name
};

void OpX5_Child::unknown88e360()
{
	getParent()->getParent()->unknown8();
}

void OpX5_Child::unknown88e390()
{
	getParent()->getParent()->unknownC();
}

struct Point
{
	int x;
	int y;
	Point(int x_, int y_);	// 0x453b70
};

struct OpX5_Size	// NOTE: placeholder name
{
	int width;
	int height;
	Point unknown9b7930();	// NOTE: placeholder name
};

Point OpX5_Size::unknown9b7930()
{
	return Point(width-1,height-1);
}

class OpS7_IntGrid2	// NOTE: placeholder name (Array2D<int>, second view; defined in op_s7.cpp)
{
public:
	int width;
	int height;
	int *cells;

	void fill(int value);	// NOTE: placeholder name (0x9ec800)
	void resize(int width_, int height_);	// NOTE: placeholder name (0x9ec850)
	void init_9cf690(int width_, int height_, int fill_);	// NOTE: placeholder name
};

void OpS7_IntGrid2::init_9cf690(int width_, int height_, int fill_)
{
	resize(width_,height_);
	fill(fill_);
}
