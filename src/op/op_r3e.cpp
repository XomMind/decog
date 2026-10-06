// op_r3e: functions in 0x6a0000-0x6c2000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(const Point &p);	// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(const Point &p);	// 0x9ced70
};

struct CellEffect;
class HProp;

class Cell
{
public:
	int unknown45d0e0();	// NOTE: placeholder name
	CellEffect *getEffect(int type);	// NOTE: placeholder name (0x45d350)
	HProp getProp();	// NOTE: placeholder name (0x45d550)
};

class Prop
{
public:
	int unknown457b10();	// NOTE: placeholder name (ICF'd trivial getter)
	int unknown9b8f00();	// NOTE: placeholder name (ICF'd trivial getter)
};

class HProp
{
	int ID;
public:
	bool isNull() const;	// 0x9b65d0
	Prop *operator->() const throw();	// 0x9b64f0
};

class Map	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	int getTurn();	// 0x464270
};

class Area	// NOTE: placeholder layout
{
public:
	Point min;
	Point max;
	bool contains_40b750(const Point &p);	// NOTE: placeholder name
};

extern Map *world;	// NOTE: placeholder name (0xcefc4c)
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

template <class T> void OpR3e_eraseAt(vector<T> &v, unsigned int index);	// NOTE: placeholder name (0x9d8f20)

//==================================================================
// timed records
//==================================================================

struct OpR3e_Rec	// NOTE: placeholder name
{
	Point pos;
	int type;
	int turn;

	OpR3e_Rec(const Point &p, int type_, int turn_) throw();	// 0x460010
};

extern vector<OpR3e_Rec *> opr3e_recs;	// NOTE: placeholder name (0xcf0fa8)
extern vector<Area> opr3e_areas;	// NOTE: placeholder name (0xd204cc)
extern int opr3e_lastIndex;	// NOTE: placeholder name (0xce9ff4)

void OpR3e_unknown6c0f10(const Point &p, int type, int duration)	// NOTE: placeholder name
{
	if (!opr3e_areas.empty())
	{
		for (unsigned int i = 0; i < opr3e_areas.size(); i++)
		{
			if (opr3e_areas[i].contains_40b750(p))
				return;
		}
	}
	int turn = world->getTurn() + duration;
	for (unsigned int j = 0; j < opr3e_recs.size(); j++)
	{
		if (opr3e_recs[j]->pos == p)
		{
			if (opr3e_recs[j]->type != type || turn > opr3e_recs[j]->turn)
				opr3e_recs[j]->turn = turn;
			opr3e_recs[j]->type = type;
			return;
		}
	}
	opr3e_recs.push_back((OpR3e_Rec *)(new OpR3e_Rec(p, type, turn)));
}

bool OpR3e_unknown6c1080(const Point &p)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < opr3e_recs.size(); i++)
	{
		if (opr3e_recs[i]->pos == p)
		{
			OpR3e_eraseAt(opr3e_recs, i);
			return true;
		}
	}
	return false;
}

int OpR3e_unknown6c10f0(const Point &p)	// NOTE: placeholder name
{
	opr3e_lastIndex = -1;
	for (unsigned int i = 0; i < opr3e_recs.size(); i++)
	{
		if (opr3e_recs[i]->pos == p)
		{
			if (cells(p)->unknown45d0e0() != opr3e_recs[i]->type || cells(p)->getEffect(6))
				opr3e_lastIndex = world->getTurn() >= opr3e_recs[i]->turn ? i : -1;
			else
				OpR3e_eraseAt(opr3e_recs, i);
			break;
		}
	}
	return opr3e_lastIndex;
}

class OpR3e_PointList	// NOTE: placeholder name
{
public:
	char pad00[0xc];
	vector<Point> points;

	bool unknown6c11f0(const Point &p);	// NOTE: placeholder name
};

extern int opr3e_propType;	// NOTE: placeholder name (0xcefbd4)

bool OpR3e_PointList::unknown6c11f0(const Point &p)
{
	for (unsigned int i = 0; i < points.size(); i++)
	{
		if (points[i] == p)
		{
			return cells(points[i])->getProp().isNull() || cells(points[i])->getProp()->unknown9b8f00() != opr3e_propType;
		}
	}
	return false;
}

class OpR3e_Conduit	// NOTE: placeholder name (OpW3_Conduit)
{
public:
	vector<int> indices;	// NOTE: placeholder name
	vector<int> targets;	// NOTE: placeholder name
	vector<int> flags;	// NOTE: placeholder name
	bool active;	// NOTE: placeholder name

	HProp unknown6c12e0();	// NOTE: placeholder name
	bool unknown6c1320();	// NOTE: placeholder name
};

extern vector<vector<HProp> > opr3e_machines;	// NOTE: placeholder name (0xd31640)

HProp OpR3e_Conduit::unknown6c12e0()
{
	return opr3e_machines[indices.front()][0];
}

bool OpR3e_Conduit::unknown6c1320()
{
	return !opr3e_machines[indices.front()].empty() && opr3e_machines[indices.front()][0]->unknown457b10() == 0;
}

//==================================================================
// location-specific record
//==================================================================

struct OpR3e_LocationInfo	// NOTE: placeholder name
{
	int unknown0;
	int type;
};

struct OpR3e_HLocation	// NOTE: placeholder name
{
	int ID;
	OpR3e_LocationInfo *operator->() const;	// 0x9b7910
};
extern OpR3e_HLocation opr3e_location;	// NOTE: placeholder name (0xd1e888)

struct OpR3e_Marker	// NOTE: placeholder name
{
	Point pos;
	int unknown8;
	bool unknownC;
	bool unknownD;
	bool unknownE;
	int unknown10;
	int unknown14;
	int unknown18;
	int unknown1C;
	vector<unsigned int> list20;
	vector<unsigned int> list30;
	vector<unsigned int> list40;
	vector<unsigned int> list50;

	OpR3e_Marker(const Point &p, int a, bool b, int c, int d);	// 0x6c13a0
};

OpR3e_Marker::OpR3e_Marker(const Point &p, int a, bool b, int c, int d)
	: pos			(p)
	, unknown8		(a)
	, unknownC		(b)
	, unknownD		(false)
	, unknownE		(false)
	, unknown10		(2)
	, unknown14		(c)
	, unknown18		(d)
	, unknown1C		(opr3e_location->type == 0xd)
{
}
