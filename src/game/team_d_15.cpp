// team_d_15: flood-collect of prop positions around a marker group or a centre (0x517ae0).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(int v);					// 0x409990
	Point(int x_, int y_);			// 0x46ca20
	Point(const Point &p) throw();	// 0x46ca50
	Point operator+(const Point &p) const;	// 0x409b60
	Point operator-(const Point &p) const;	// 0x409b30
	void shift(int amount);			// NOTE: placeholder name (0x40bf50)
};

struct Area	// NOTE: placeholder layout
{
	Point min;
	Point max;

	Area();								// 0x40b100
	void set(const Point &a, const Point &b);	// NOTE: placeholder name (0x40b330)
	void set(const Point &p);			// NOTE: placeholder name (0x40b3f0)
	void include_40bb90(const Point &p);	// NOTE: placeholder name
	void clip(const Point &a, const Point &b);	// NOTE: placeholder name (0x40bc40)
};

class Prop
{
public:
	bool unknown45ca70();	// NOTE: placeholder name
	bool unknown45cab0();	// NOTE: placeholder name
};

class HProp
{
	int ID;
public:
	bool isValid() const;
	Prop *operator->() const;
};

class Cell
{
public:
	HProp getProp();	// 0x45d550
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **at(int x, int y);	// NOTE: folded with OpX5_Array2D<int>::at
	Point getSize();			// NOTE: placeholder name (0x9b7930)
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

class Marker	// NOTE: placeholder name
{
public:
	Point &getPosition();	// NOTE: placeholder name (0x4184d0)
};

class HMarker
{
	int ID;
public:
	Marker *operator->() const;
};

extern vector<vector<HMarker> > markerLists_d31640;	// NOTE: placeholder name

bool OpV4c_Fn9d0ce0(vector<Point> &list, Point p);	// NOTE: placeholder name

bool OpD_collectProps_517ae0(int index, vector<Point> *out, bool flag, int radius, Point *center)	// NOTE: placeholder name
{
	Area area;
	unsigned int count;
	if (center)
		area.set(*center - radius,*center + radius);
	else
	{
		vector<HMarker> &list = markerLists_d31640[index];
		Point pos(list.front()->getPosition());
		area.set(pos);
		for (unsigned int i = 1; i < list.size(); i++)
			area.include_40bb90(list[i]->getPosition());
		area.min.shift(-radius);
		area.max.shift(radius);
	}
	area.clip(Point(0),cells_cfd44c.getSize());
	do
	{
		count = out->size();
		for (int x = area.min.x; x <= area.max.x; x++)
		{
			for (int y = area.min.y; y <= area.max.y; y++)
			{
				if ((*cells_cfd44c.at(x,y))->getProp().isValid()
					&& ((*cells_cfd44c.at(x,y))->getProp()->unknown45ca70() || (flag && (*cells_cfd44c.at(x,y))->getProp()->unknown45cab0()))
					&& !OpV4c_Fn9d0ce0(*out,Point(x,y)))
				{
					out->push_back(Point(x,y));
					if (x - radius < area.min.x)
						area.min.x = x - radius;
					if (y - radius < area.min.y)
						area.min.y = y - radius;
					if (x + radius > area.max.x)
						area.max.x = x + radius;
					if (y + radius > area.max.y)
						area.max.y = y + radius;
				}
			}
		}
	}
	while (out->size() != count);
	return !out->empty();
}
