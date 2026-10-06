// op_x4c: BS::unknown6c6d10 (0x6c6d10), Beta 17.1. NOTE: class/method names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p);	// 0x46ca50
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor (0x46ca50)
	bool operator!=(const Point &p) const;	// 0x409bd0
};

struct RectXYWH	// NOTE: placeholder name
{
	int x;
	int y;
	int w;
	int h;

	RectXYWH(const Point &p);	// NOTE: placeholder name (0x40a7a0)
};

struct Area	// NOTE: placeholder name
{
	Point min;
	Point max;

	Area(const RectXYWH &r);	// 0x40b290
	Point center_40b620();	// NOTE: placeholder name
	void include_40bb90(const Point &p);	// NOTE: placeholder name
};

class Prop
{
public:
	void unknown45cd30(bool v);	// NOTE: placeholder name
};

class HProp
{
public:
	int ID;
	Prop *operator->() const;	// 0x9b64f0
};

class Cell
{
public:
	HProp getProp();	// 0x45d550
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
};
extern Array2D<Cell *> cells;	// 0xcfd44c

bool OpX4c_contains_9d0ce0(vector<Point> &v, Point p);	// NOTE: placeholder name (0x9d0ce0)
Point OpU8a_randomPoint(vector<Point> &v);	// NOTE: placeholder name (0x9d5350)

class BS	// NOTE: placeholder name
{
public:
	Point unknown6c6d10(vector<Point> &points, Point &target);	// NOTE: placeholder name
};

Point BS::unknown6c6d10(vector<Point> &points, Point &target)
{
	if (target.x != -1)
	{
		for (unsigned int i = 0; i < points.size(); i++)
		{
			if (points[i] != target)
				cells(points[i])->getProp()->unknown45cd30(false);
		}
		return target;
	}
	Area area(points[0]);
	for (unsigned int j = 1; j < points.size(); j++)
		area.include_40bb90(points[j]);
	Point center = area.center_40b620();
	if (!OpX4c_contains_9d0ce0(points,center))
	{
		Point w = center;
		Point e = center;
		Point n = center;
		Point s = center;
		center.x = -1;
		while (true)
		{
			if (w.x != -1)
			{
				if (!cells.contains(w))
					w.x = -1;
				else
				{
					if (OpX4c_contains_9d0ce0(points,w))
					{
						center = w;
						break;
					}
					else
						w.x--;
				}
			}
			if (e.x != -1)
			{
				if (!cells.contains(e))
					e.x = -1;
				else
				{
					if (OpX4c_contains_9d0ce0(points,e))
					{
						center = e;
						break;
					}
					else
						e.x++;
				}
			}
			if (n.x != -1)
			{
				if (!cells.contains(n))
					n.x = -1;
				else
				{
					if (OpX4c_contains_9d0ce0(points,n))
					{
						center = n;
						break;
					}
					else
						n.y--;
				}
			}
			if (s.x != -1)
			{
				if (!cells.contains(s))
					s.x = -1;
				else
				{
					if (OpX4c_contains_9d0ce0(points,s))
					{
						center = s;
						break;
					}
					else
						s.y++;
				}
			}
		}
		if (center.x == -1)
			center = OpU8a_randomPoint(points);
	}
	for (unsigned int k = 0; k < points.size(); k++)
	{
		if (points[k] != center)
			cells(points[k])->getProp()->unknown45cd30(false);
	}
	return center;
}
