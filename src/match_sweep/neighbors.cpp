// Map-neighbor helpers recovered from Beta 17.1 at 0x4faaf0-0x4fad4a.
// NOTE: placeholder names; neighbor ordering and bounds checks are recovered exactly.
#include <vector>
using namespace std;
struct Point
{
	int x;
	int y;
	Point();
	Point(int x_, int y_);
	Point(const Point &point);
	void setOffset(const Point &base, int dx, int dy);
};
class Cell;
template <class T> class Array2D
{
	int width;
	int height;
	T *data;
public:
	bool contains(const Point &point);
	int getWidth();
	int getHeight();
};
extern Array2D<Cell *> cells;
bool sweepContainsPoint(vector<Point> *points, Point point);
void sweepGetSurroundingCells(const Point &point, vector<Point> &adjacent)
{
	Point p;
	int i;
	int j;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (i != 0 || j != 0)
			{
				p.setOffset(point,i,j);
				if (cells.contains(p))
					adjacent.push_back(p);
			}
		}
	}
}
void getAdjacentCells(const Point &point, vector<Point> &adjacent)
{
	if (point.x > 0)
		adjacent.push_back(Point(point.x - 1,point.y));
	if (point.y > 0)
		adjacent.push_back(Point(point.x,point.y - 1));
	if (point.x < cells.getWidth() - 1)
		adjacent.push_back(Point(point.x + 1,point.y));
	if (point.y < cells.getHeight() - 1)
		adjacent.push_back(Point(point.x,point.y + 1));
}
unsigned int sweepGetCommonNeighbors(const Point &first, const Point &second, vector<Point> &adjacent)
{
	vector<Point> a;
	sweepGetSurroundingCells(first,a);
	vector<Point> b;
	sweepGetSurroundingCells(second,b);
	unsigned int j;
	for (j = 0; j < a.size(); j++)
	{
		if (sweepContainsPoint(&b,a[j]))
			adjacent.push_back(a[j]);
	}
	return adjacent.size();
}
