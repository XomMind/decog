// team_d_101: free function 0x51cd40 (caller BS::turnUpdate_51da30): finds where a size x size footprint can
// be placed around a point. Every candidate top-left cell is scored by distance plus penalties for other robots,
// blocking props and impassable terrain; one of the cheapest is chosen at random. If it is still blocked the
// mode at +0xb4 of the first argument decides: fail with a message, crush the robot, or clear props/terrain.
// NOTE: class layouts are partial; all names are placeholders.
// NOTE: the function-scope locals are named for their stack-slot hash order (vec = costs, positions = spots).
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p);			// 0x46ca50
	Point(int x_, int y_);			// 0x46ca20
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor
};

int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
int OpX5_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)
int opw8_distance(int x1, int y1, int x2, int y2);	// NOTE: placeholder name (0x406480)
int OpT8b_Fn9d7290(vector<int> &v);	// NOTE: placeholder name (minimum)
template <class T> void removeVectorElement(vector<T> &v, int index);
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name
template <class T> int OpQ5_randomIndex(vector<T> &v);	// NOTE: placeholder name

class Entity;

class HEntity
{
public:
	int ID;
	HEntity();
	Entity *operator->() const;
	bool isValid() const;	// NOTE: folded with HItem::isValid
	bool operator!=(HEntity e) const;
};

class Prop;

class HProp
{
public:
	int ID;
	HProp();
	Prop *operator->() const;	// NOTE: OpC_Handle::get22c
	bool isValid() const;	// NOTE: folded with HItem::isValid
};

class Entity
{
public:
	int getSize();
	void unknown637bb0();	// NOTE: placeholder name
};

class Prop
{
public:
	bool isPassableFor(HEntity e);
	int getArmor101();	// NOTE: placeholder name (Sweep_45c630::getNestedField)
	void unknown45ce10(bool a, int b, bool c, HProp d);	// NOTE: placeholder name
};

class Cell
{
public:
	HEntity getEntity();
	HProp getProp();
	bool isPassableFor(HEntity e);
	int getArmor();
	void unknown45e110(bool a, bool b, HProp p);	// NOTE: placeholder name (Effect_45e110::trigger)
};

class CellGrid101	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **at(int x, int y);	// NOTE: folded (OpX5_Array2D<int>::at)
	int getWidth();
	int getHeight();
};
extern CellGrid101 cells101_cfd44c;	// NOTE: placeholder name

class ConsoleA101	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA101 *consoleA101_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs101_cec0b4;	// NOTE: placeholder name

bool showMessage101(int id, const void *text, const void *b, int c, HEntity d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)

struct Placement101	// NOTE: placeholder name and layout
{
	char	pad00[0xb4];
	int		mode;	// +0xb4
};

struct Footprint101	// NOTE: placeholder name and layout
{
	char	pad00[0x9c];
	int		size;	// +0x9c
};

bool placeFootprint_51cd40(Placement101 *placement, Footprint101 *footprint, HEntity e, Point &pos)	// NOTE: placeholder name
{
	int width = e.isValid() ? e->getSize() : 1;
	int size = footprint->size;
	vector<Point> positions;
	vector<int> vec;
	for (int x = OpX5_maxInt(pos.x - size,0); x < OpX5_minInt(pos.x + width,cells101_cfd44c.getWidth() - 1); x++)
	{
		for (int y = OpX5_maxInt(pos.y - size,0); y < OpX5_minInt(pos.y + width,cells101_cfd44c.getHeight() - 1); y++)
		{
			positions.push_back(Point(x,y));
			vec.push_back(opw8_distance(pos.x,pos.y,x,y));
			for (int i = x; i < x + size; i++)
			{
				for (int j = y; j < y + size; j++)
				{
					if ((*cells101_cfd44c.at(i,j))->getEntity().isValid() && (*cells101_cfd44c.at(i,j))->getEntity() != e)
						vec.back() += 100000;
					if ((*cells101_cfd44c.at(i,j))->getProp().isValid() && !(*cells101_cfd44c.at(i,j))->getProp()->isPassableFor(HEntity()))
						vec.back() += (*cells101_cfd44c.at(i,j))->getProp()->getArmor101() == -1 ? 10000 : (*cells101_cfd44c.at(i,j))->getProp()->getArmor101() + 100;
					if (!(*cells101_cfd44c.at(i,j))->isPassableFor(HEntity()))
						vec.back() += (*cells101_cfd44c.at(i,j))->getArmor() == -1 ? 10000 : (*cells101_cfd44c.at(i,j))->getArmor() + 100;
				}
			}
		}
	}
	int min = OpT8b_Fn9d7290(vec);
	for (int k = vec.size() - 1; k >= 0; k--)
	{
		if (vec[k] != min)
		{
			removeVectorElement(vec,k);
			OpQ5_eraseAt(positions,k);
		}
	}
	int choice = OpQ5_randomIndex(vec);
	Point p(positions[choice]);
	if (vec[choice] >= 100000 && placement->mode != 3)
	{
		if (e.isValid())
		{
			do
			{
				if (showMessage101(0xbc,0,0,0,e,HProp(),0,0))
					consoleA101_cec058->unknown8758d0(true);
				logMsgs101_cec0b4->scrollToEnd();
			} while (0);
		}
		return false;
	}
	if (vec[choice] >= 100)
	{
		switch (placement->mode)
		{
		case 0:
			if (e.isValid())
			{
				do
				{
					if (showMessage101(0xbc,0,0,0,e,HProp(),0,0))
						consoleA101_cec058->unknown8758d0(true);
					logMsgs101_cec0b4->scrollToEnd();
				} while (0);
			}
			return false;
		case 1:
			if (e.isValid())
			{
				do
				{
					if (showMessage101(0xbd,0,0,0,e,HProp(),0,0))
						consoleA101_cec058->unknown8758d0(true);
					logMsgs101_cec0b4->scrollToEnd();
				} while (0);
				e->unknown637bb0();
			}
			return false;
		case 2:
		case 3:
		{
			bool crush = placement->mode == 3;
			for (int i = p.x; i < p.x + size; i++)
			{
				for (int j = p.y; j < p.y + size; j++)
				{
					if ((*cells101_cfd44c.at(i,j))->getProp().isValid() && !(*cells101_cfd44c.at(i,j))->getProp()->isPassableFor(HEntity()))
						(*cells101_cfd44c.at(i,j))->getProp()->unknown45ce10(false,0,true,HProp());
					if (!(*cells101_cfd44c.at(i,j))->isPassableFor(HEntity()))
						(*cells101_cfd44c.at(i,j))->unknown45e110(false,false,HProp());
					if (crush && (*cells101_cfd44c.at(i,j))->getEntity().isValid())
						(*cells101_cfd44c.at(i,j))->getEntity()->unknown637bb0();
				}
			}
		}
		}
	}
	pos = p;
	return true;
}
