// team_d_32: BS member 0x701030 (fill an area's empty cells with a prop and orient the props beside a point).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(int x_, int y_);
	Point(const Point &p) throw();	// 0x46ca50
};

class Prop
{
public:
	void unknown41a800(int x, int y);	// NOTE: placeholder name (sets the position)
	void unknown44eb20(int value);		// NOTE: placeholder name (setter)
};

class HProp
{
	int ID;
public:
	bool isValid() const;
	bool isNull() const;
	Prop *operator->() const;
};

class Cell
{
public:
	HProp getProp();
	void setProp(HProp prop);	// NOTE: placeholder name (0x45df50)
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(const Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
	Cell **at(int x, int y);		// NOTE: folded with OpX5_Array2D<int>::at
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

struct Rect32	// NOTE: placeholder name
{
	int x;
	int y;
	int width;
	int height;

	int right();	// NOTE: placeholder name (0x40ac20)
	int bottom();	// NOTE: placeholder name (0x40ac40)
};

struct Area32	// NOTE: placeholder name
{
	int		unknown00;
	Rect32	rect;
};

struct PropType32;	// NOTE: placeholder name

class Factory32	// NOTE: placeholder name (OpU5s2_Factory at 0xcefaa8)
{
public:
	HProp createE(PropType32 *type);	// NOTE: placeholder name
};
extern Factory32 *factory_cefaa8;	// NOTE: placeholder name
extern PropType32 *propType_cefbdc;	// NOTE: placeholder name

bool OpV4c_Fn9d0ce0(vector<Point> &list, Point p);	// NOTE: placeholder name (contains)
void getAdjacentCells(const Point &p, vector<Point> &adjacent);	// NOTE: placeholder name (0x4fab80)
int pointsFn_4374c0(const Point &a, const Point &b);	// NOTE: placeholder name (direction)
template <class T> void OpV4c_shuffle(vector<T> &v);	// NOTE: placeholder name

class BS
{
public:
	void unknown701030(Area32 *area, const Point &center, vector<Point> *exclude);	// NOTE: placeholder name
};

void BS::unknown701030(Area32 *area, const Point &center, vector<Point> *exclude)
{
	for (int x = area->rect.x; x <= area->rect.right(); x++)
	{
		for (int y = area->rect.y; y <= area->rect.bottom(); y++)
		{
			if ((*cells_cfd44c.at(x,y))->getProp().isNull() && (!exclude || !OpV4c_Fn9d0ce0(*exclude,Point(x,y))))
			{
				HProp prop = factory_cefaa8->createE(propType_cefbdc);
				(*cells_cfd44c.at(x,y))->setProp(prop);
				prop->unknown41a800(x,y);
			}
		}
	}
	if ((*cells_cfd44c.atPoint(center))->getProp().isValid())
		(*cells_cfd44c.atPoint(center))->getProp()->unknown44eb20(0x8b);
	vector<Point> adjacent;
	getAdjacentCells(center,adjacent);
	OpV4c_shuffle(adjacent);
	for (int i = 0; i < adjacent.size() && i < 2; i++)
	{
		if ((*cells_cfd44c.atPoint(adjacent[i]))->getProp().isValid())
		{
			switch (pointsFn_4374c0(center,adjacent[i]))
			{
			case 4:
				(*cells_cfd44c.atPoint(adjacent[i]))->getProp()->unknown44eb20(0xab);
				break;
			case 6:
				(*cells_cfd44c.atPoint(adjacent[i]))->getProp()->unknown44eb20(0xac);
				break;
			case 0:
				(*cells_cfd44c.atPoint(adjacent[i]))->getProp()->unknown44eb20(0xae);
				break;
			case 2:
				(*cells_cfd44c.atPoint(adjacent[i]))->getProp()->unknown44eb20(0xad);
				break;
			}
		}
	}
}
