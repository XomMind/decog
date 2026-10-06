// op_u5_a: level-map mark helpers (BS methods) in 0x71f000-0x720000
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct XColor
{
	unsigned int rgba;
	XColor(const XColor &c);
	XColor &operator=(XColor c);
};

class Entity
{
public:
	vector<Point> *unknown45d1a0();	// NOTE: placeholder name (0x45d1a0, ICF'd getter)
	int unknown45a540(const Point &p);	// NOTE: placeholder name
	const XColor &unknown5c7630();	// NOTE: placeholder name
};

class HEntity
{
public:
	int ID;
	Entity *operator->() const;	// 0x9b6570
};

struct OpR4p_Mark	// NOTE: placeholder name (layout differs in member names from op_r4_p.cpp only)
{
	int stamp;
	int type;
	HEntity entity;
	int owner;	// NOTE: placeholder name
	XColor color;
};

template <class T>
class OpR4p_Grid	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *data;
	T &operator()(const Point &p);	// 0x9d2930
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

class BS
{
public:
	char pad0[0x69c];
	Array2D<int> markFlags;		// +0x69c
	char pad6a8[0x740 - 0x6a8];
	OpR4p_Grid<OpR4p_Mark> marks;	// +0x740
	int markStamp;			// +0x74c
	int pad750;
	vector<Point> markedPoints;	// +0x754
	void opu5_unknown71fef0(HEntity entity);	// NOTE: placeholder name (0x71fef0)
	void opw3_unknown72a0b0(HEntity e);	// NOTE: placeholder name
};

void BS::opu5_unknown71fef0(HEntity entity)
{
	vector<Point> *footprint = entity->unknown45d1a0();
	for (unsigned int i = 0; i < footprint->size(); i++)
	{
		if (markFlags((*footprint)[i]) == 0)
		{
			marks((*footprint)[i]).stamp = markStamp;
			marks((*footprint)[i]).type = 5;
			marks((*footprint)[i]).entity = entity;
			marks((*footprint)[i]).owner = entity->unknown45a540((*footprint)[i]);
			marks((*footprint)[i]).color = entity->unknown5c7630();
			markedPoints.push_back((*footprint)[i]);
		}
	}
	opw3_unknown72a0b0(entity);
}
