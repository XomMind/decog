// op_r5a: CMap / CMapFine / CPay2Buy / CRpglike helpers (0x828000-0x879500) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
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
	Point(int x_, int y_);	// 0x46ca20
	Point(const Point &p);	// 0x46ca50
	Point &add_409a30(const Point &p);	// NOTE: placeholder name (operator+=)
	Point &set_40a010(int x_, int y_);	// NOTE: placeholder name
};

int minInt(int a, int b);	// 0x9cdb30
int opR5a_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
bool opR5a_contains(vector<int> &values, int value);	// NOTE: placeholder name (0x9db330)
template <class T> void OpQ5_eraseStep(vector<T> &v, unsigned int &index);	// NOTE: placeholder name
void OpQ1_lineBresenhamPoints_40ff30(const Point &from, const Point &to, vector<Point> &line);	// NOTE: placeholder name

class OpR5a_Prop	// NOTE: placeholder name
{
public:
	const Point &getPosition_4184d0();	// NOTE: placeholder name (trivial getter)
};

class HProp
{
	int ID;
public:
	HProp();
	OpR5a_Prop *operator->() const;	// 0x9b64f0
};

class OpR5a_Conduit	// NOTE: placeholder name (OpW3_Conduit)
{
public:
	vector<int> indices;	// NOTE: placeholder name
	vector<int> targets;	// NOTE: placeholder name
	vector<int> flags;	// NOTE: placeholder name
	bool active;	// NOTE: placeholder name
};

extern vector<vector<HProp> > opR5a_machines;	// NOTE: placeholder name (0xd31640)
extern vector<OpR5a_Conduit *> opR5a_conduits;	// NOTE: placeholder name (0xd39f1c)

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

struct Pos;

class XConsole
{
public:
	virtual ~XConsole();
	bool inBounds(const Pos &p);	// retail passes Point objects as the (layout-identical) Pos
};

class OpR5a_MapView : public XConsole	// NOTE: placeholder name (CMap at 0xcec054)
{
public:
	const Point &getOffset_458ef0();	// NOTE: placeholder name (folded getter, +0x6c)
};
extern OpR5a_MapView *opR5a_mapView;	// NOTE: placeholder name (0xcec054)

//==================================================================
// 0x83d9b0-0x83e000
//==================================================================

void opR5a_machinePoints(vector<int> &indices, vector<Point> *out)	// NOTE: placeholder name (0x83dae0)
{
	for (unsigned int i = 0; i < indices.size(); i++)
	{
		for (unsigned int j = 0; j < opR5a_machines[indices[i]].size(); j++)
		{
			Point p = opR5a_machines[indices[i]][j]->getPosition_4184d0();
			p.add_409a30(opR5a_mapView->getOffset_458ef0());
			if (opR5a_mapView->inBounds(reinterpret_cast<const Pos &>(p)))
				out->push_back(p);
		}
	}
}

void opR5a_conduitPath(OpR5a_Conduit &conduit, vector<Point> *out)	// NOTE: placeholder name (0x83dbc0)
{
	HProp first = opR5a_machines[conduit.indices.front()][0];
	vector<HProp> linked;
	for (unsigned int i = 0; i < conduit.targets.size(); i++)
		linked.push_back(opR5a_machines[opR5a_conduits[conduit.targets[i]]->indices.front()][0]);
	if (!linked.empty())
	{
		Point start = first->getPosition_4184d0();
		Point from;
		Point src;
		for (unsigned int k = 0; k < linked.size(); k++)
		{
			const Point &to = linked[k]->getPosition_4184d0();
			if (start.y == to.y)
			{
				for (int x = minInt(start.x,to.x); x <= opR5a_maxInt(start.x,to.x); x++)
					out->push_back(Point(x,start.y));
			}
			else if (start.y == to.y)	// NOTE: same test as above (as in the original)
			{
				for (int y = minInt(start.y,to.y); y <= opR5a_maxInt(start.y,to.y); y++)
					out->push_back(Point(start.x,y));
			}
			else
			{
				Point corner;
				if (start.x < to.x && start.y < to.y || start.x > to.x && start.y > to.y)
				{
					if (rng.chance(50))
						corner.set_40a010(opR5a_maxInt(start.x,to.x),minInt(start.y,to.y));
					else
						corner.set_40a010(minInt(start.x,to.x),opR5a_maxInt(start.y,to.y));
				}
				else
				{
					if (rng.chance(50))
						corner.set_40a010(minInt(start.x,to.x),minInt(start.y,to.y));
					else
						corner.set_40a010(opR5a_maxInt(start.x,to.x),opR5a_maxInt(start.y,to.y));
				}
				OpQ1_lineBresenhamPoints_40ff30(start,corner,*out);
				out->pop_back();
				OpQ1_lineBresenhamPoints_40ff30(corner,to,*out);
			}
		}
		for (unsigned int j = 0; j < out->size(); j++)
		{
			(*out)[j].add_409a30(opR5a_mapView->getOffset_458ef0());
			if (!opR5a_mapView->inBounds(reinterpret_cast<const Pos &>((*out)[j])))
				OpQ5_eraseStep(*out,j);
		}
	}
}

int opR5a_findFree(int start, int end, vector<int> &used, bool forward)	// NOTE: placeholder name (0x868020)
{
	if (forward)
	{
		for (int i = start; i <= end; i++)
		{
			if (!opR5a_contains(used,i))
				return i;
		}
	}
	else
	{
		for (int i = start; i >= end; i--)
		{
			if (!opR5a_contains(used,i))
				return i;
		}
	}
	return -1;
}
