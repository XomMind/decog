// team_d_86: BS member 0x74b2c0: builds a 20x20 random obstacle pattern (blocks, circles, thick lines),
// cleared where it would overlap prefab or machine cells; returns the new grid's index.
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();								// NOTE: placeholder name (Push_453b40::operate)
	Point(const Point &p) throw();			// 0x46ca50
	Point &operator=(const Point &p);		// NOTE: folded with the copy constructor (0x46ca50)
	bool operator==(const Point &p) const;	// 0x409b90
	Point add(const Point &p) const;		// NOTE: placeholder name (PushCoord::add)
};

struct Pos : public Point
{
	Pos(int x_, int y_);	// 0x46ca20
};

class OpS7_IntGrid2	// NOTE: placeholder layout
{
public:
	OpS7_IntGrid2(int width_, int height_, int fill);	// 0x9ced10
	int *at(int x, int y);			// NOTE: folded (OpX5_Array2D<int>::at)
	int *atPoint(const Point &p);	// NOTE: folded (OpX5_Array2D<int>::atPoint)
	bool contains(const Point &p);	// NOTE: folded (OpR5h_Grid::contains)
	Point getRandom_9cf050();		// NOTE: placeholder name
	char pad[0xc];
};
extern vector<OpS7_IntGrid2 *> grids86_d22744;	// NOTE: placeholder name
extern OpS7_IntGrid2 prefab86_cf11a0;			// NOTE: placeholder name

class Cell
{
public:
	bool isMachinePart();	// NOTE: placeholder name
};

class CellGrid86	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **at(int x, int y);	// NOTE: folded with OpX5_Array2D<int>::at
};
extern CellGrid86 cells86_cfd44c;	// NOTE: placeholder name

template <class T>
class OpR5h_WL	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	void add(T value, int weight);
	T &pick();
};

class RNG
{
public:
	int rangeInt(float lo, float hi);
	bool chance(int percent);
};
extern RNG rng;

bool isEven_406320(int value);
int opw8_distance(int x1, int y1, int x2, int y2);	// NOTE: placeholder name
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);
void OpQ1_lineBresenhamPoints_40ff30(const Point &from, const Point &to, vector<Point> &line);	// NOTE: placeholder name

class BS
{
public:
	int unknown74b2c0(const Point *origin);	// NOTE: placeholder name
};

int BS::unknown74b2c0(const Point *origin)
{
	grids86_d22744.push_back(new OpS7_IntGrid2(0x14,0x14,0));
	OpS7_IntGrid2 *v = grids86_d22744.back();
	OpR5h_WL<int> x;
	x.add(0,0x19);
	x.add(1,0x19);
	x.add(2,0x28);
	int first = rng.rangeInt(4.0f,10.0f);
	for (int i = 0; i < first; i++)
	{
		switch (x.pick())
		{
		case 0:
			{
				int count = rng.rangeInt(3.0f,5.0f);
				bool found = rng.chance(50);
				Pos pt(rng.rangeInt(0.0f,(float)(0x13 - count)),rng.rangeInt(0.0f,(float)(0x13 - count)));
				for (int w = pt.x, y0 = 0; y0 < count; w++, y0++)
				{
					for (int h = pt.y, y = 0; y < count; h++, y++)
					{
						if (!found || y0 == 0 || y0 == count - 1 || y == 0 || y == count - 1)
							*v->at(w,h) = 1;
					}
				}
			}
			break;
		case 1:
			{
				int count;
				do
				{
					count = rng.rangeInt(3.0f,5.0f);
				} while (isEven_406320(count));
				bool found = rng.chance(25);
				Pos x2(rng.rangeInt(0.0f,(float)(0x13 - count)),rng.rangeInt(0.0f,(float)(0x13 - count)));
				Pos pt(x2.x + count / 2,x2.y + count / 2);
				int n = count / 2;
				int f;
				for (int w = x2.x, y0 = 0; y0 < count; w++, y0++)
				{
					for (int h = x2.y, y = 0; y < count; h++, y++)
					{
						f = opw8_distance(pt.x,pt.y,w,h);
						if (f <= n && (!found || f == n))
							*v->at(w,h) = 1;
					}
				}
			}
			break;
		case 2:
			{
				const int n = 5;
				Point x2 = v->getRandom_9cf050();
				Point center;
				do
				{
					center = v->getRandom_9cf050();
				} while (center == x2 || OpQ1_distanceCeil_40a3f0(x2,center) < n);
				Pos pt(0,0);
				switch (rng.rangeInt(0.0f,3.0f))
				{
				case 0:
					pt.y--;
					break;
				case 1:
					pt.x++;
					break;
				case 2:
					pt.y++;
					break;
				case 3:
					pt.x--;
					break;
				}
				vector<Point> vec;
				OpQ1_lineBresenhamPoints_40ff30(x2,center,vec);
				for (unsigned int k = 0; k < vec.size(); k++)
				{
					*v->atPoint(vec[k]) = 1;
					if (v->contains(vec[k].add(pt)))
						*v->atPoint(vec[k].add(pt)) = 1;
				}
			}
			break;
		}
	}
	if (origin)
	{
		for (int w = 0, y0 = origin->x; w < 0x14; w++, y0++)
		{
			for (int ny = 0, h = origin->y; ny < 0x14; ny++, h++)
			{
				if (*prefab86_cf11a0.at(y0,h) != 0 || (*cells86_cfd44c.at(y0,h))->isMachinePart())
					*v->at(w,ny) = 0;
			}
		}
	}
	return grids86_d22744.size() - 1;
}
