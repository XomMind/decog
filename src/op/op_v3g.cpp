// op_v3g: CMap functions in 0x80fa60-0x825e00 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);
	Pos(const Pos &pos) throw();
	Pos &operator=(const Pos &pos);	// 0x46ca50
	Pos operator+(const Pos &pos) const;	// 0x409b60
	bool operator!=(const Pos &pos) const;	// 0x409bd0
	bool operator==(const Pos &pos) const;	// 0x409b90
};

struct Point
{
	int x;
	int y;

	Point(const Point &p);	// 0x46ca50
};

class Entity
{
public:
	int getSize();	// 0x45a360
};

class HEntity
{
public:
	int ID;
	bool operator==(HEntity other) const;	// 0x9b78e0
	Entity *operator->() const;	// 0x9b6570
};

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern int tickCountInt;	// NOTE: placeholder name (0xcaed20)

class XConsole;
class Console;

struct OpW5_MapLabel	// NOTE: placeholder name
{
	void fade();	// NOTE: placeholder name

	int type;	// NOTE: placeholder name
	Console *console;	// NOTE: placeholder name
	bool unknown8;	// NOTE: placeholder name
	unsigned int fadeTime;	// NOTE: placeholder name
	bool fading;	// NOTE: placeholder name
	Pos offset;	// NOTE: placeholder name
	int entity;	// NOTE: placeholder name
	int prop;	// NOTE: placeholder name
	int item;	// NOTE: placeholder name
	Pos pos;	// NOTE: placeholder name
	bool checkVisible;	// NOTE: placeholder name
	bool checkFov;	// NOTE: placeholder name
};

class XTimer	// NOTE: placeholder name
{
public:
	XTimer(int value_);	// NOTE: placeholder name

	int value;	// NOTE: placeholder name
	unsigned int tick;	// NOTE: placeholder name
};

class XTimerB	// NOTE: placeholder name
{
public:
	XTimerB(const Pos &pos_, int a_, int b_);	// NOTE: placeholder name

	Pos pos;
	int a;
	int b;
	unsigned int tick;
};

struct OpQ5_T9d4840;
template <class T> void OpQ5_deleteObjectAndStep(vector<T*> &v, int &index);	// NOTE: placeholder name (0x9d4840)
template <class T> void OpV3g_insertAt(vector<T> &v, int index, T value);	// NOTE: placeholder name (0x9d8fc0)

int OpU8a_indexOfPoint(vector<Point> &v, Point p);	// NOTE: placeholder name (0x9d3110)

//==================================================================
// CMap
//==================================================================

class CMap
{
public:
	void unknown8142d0(unsigned int type, bool fade);	// NOTE: placeholder name
	void removeLabels(int type);	// NOTE: placeholder name (0x49b390)
	void unknown814540(const Pos &pos);	// NOTE: placeholder name
	void unknown819460(HEntity e);	// NOTE: placeholder name
	void unknown819500(HEntity e);	// NOTE: placeholder name
	void unknown8195a0(const Pos &pos, int a, int b);	// NOTE: placeholder name
	void unknown819610(const Point &p, int amount);	// NOTE: placeholder name

	char pad0[0x1d8];
	vector<OpW5_MapLabel*> labels;	// NOTE: placeholder name
	char pad1e8[0x29c - 0x1e8];
	vector<XTimer> timers29c;	// NOTE: placeholder name
	vector<XTimer> timers2ac;	// NOTE: placeholder name
	vector<XTimerB> timers2bc;	// NOTE: placeholder name
	char pad2cc[0x2ec - 0x2cc];
	vector<Point> points2ec;	// NOTE: placeholder name
	vector<int> values2fc;	// NOTE: placeholder name
	vector<int> ticks30c;	// NOTE: placeholder name
};

void OpV3g_moveBySize(vector<HEntity> &from, vector<HEntity> &to)	// NOTE: placeholder name
{
	while (!from.empty())
	{
		if (from.back()->getSize() >= to.back()->getSize())
		{
			to.push_back(from.back());
			from.pop_back();
		}
		else
		{
			for (unsigned int i = 0; i < to.size(); i++)
			{
				if (from.back()->getSize() < to[i]->getSize())
				{
					OpV3g_insertAt(to,i,from.back());
					from.pop_back();
					break;
				}
			}
		}
	}
}

void CMap::unknown8142d0(unsigned int type, bool fade)
{
	vector<unsigned int> types;
	if (type != 0x12)
	{
		types.push_back(type);
		if (types.back() == 7)
			types.push_back(8);
		else if (types.back() == 9)
			types.push_back(0xa);
	}
	else
	{
		for (int i = 4; i <= 7; i++)
			types.push_back((unsigned int)i);
		types.push_back(8);
		types.push_back(9);
		types.push_back(0xa);
		types.push_back(0xb);
		types.push_back(0x10);
		types.push_back(0x11);
	}
	for (unsigned int i = 0; i < types.size(); i++)
	{
		if (fade)
		{
			for (unsigned int j = 0; j < labels.size(); j++)
			{
				if (labels[j]->type == types[i])
					labels[j]->fade();
			}
		}
		else
			removeLabels(types[i]);
	}
}

void CMap::unknown814540(const Pos &pos)
{
	for (unsigned int i = 0; i < labels.size(); i++)
	{
		if ((labels[i]->type == 9 || labels[i]->type == 10) && labels[i]->pos == pos)
			OpQ5_deleteObjectAndStep(labels,(int&)i);
	}
}

void CMap::unknown819460(HEntity e)
{
	for (unsigned int i = 0; i < timers29c.size(); i++)
	{
		if (((HEntity&)timers29c[i]) == e)
		{
			timers29c[i].tick = tickCountInt;
			return;
		}
	}
	timers29c.push_back(XTimer(e.ID));
}

void CMap::unknown819500(HEntity e)
{
	for (unsigned int i = 0; i < timers2ac.size(); i++)
	{
		if (((HEntity&)timers2ac[i]) == e)
		{
			timers2ac[i].tick = tickCountInt;
			return;
		}
	}
	timers2ac.push_back(XTimer(e.ID));
}

void CMap::unknown8195a0(const Pos &pos, int a, int b)
{
	timers2bc.push_back(XTimerB(pos,a,b));
}

void CMap::unknown819610(const Point &p, int amount)
{
	int index = OpU8a_indexOfPoint(points2ec,p);
	if (index != -1)
	{
		values2fc[index] += amount;
		ticks30c[index] = tickCountInt;
	}
	else
	{
		points2ec.push_back(p);
		values2fc.push_back(amount);
		ticks30c.push_back(tickCountInt);
	}
}
