// op_r5h_grid: Array2D template helpers in 0x9b4000-0x9b8000, Beta 17.1.
// NOTE: class/method names are placeholders (the exe has one copy per element type; all use width @0, height @4).
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	void set(int x_, int y_);	// NOTE: placeholder name (0x40a010)
};

struct OpR5h_Area	// NOTE: placeholder name (two corner points)
{
	Point topLeft;
	Point bottomRight;

	OpR5h_Area(int x1, int y1, int x2, int y2);	// NOTE: placeholder name (0x40b1e0)
};

int opR5h_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
int opR5h_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)

class OpR5h_Grid	// NOTE: placeholder name (Array2D)
{
public:
	int width;
	int height;

	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
	OpR5h_Area getArea();	// NOTE: placeholder name (0x9b4400)
	void getRect(const Point &p, int radius, OpR5h_Area &out);	// NOTE: placeholder name (0x9b4430)
	void getRectB(const Point &p, int before, int after, OpR5h_Area &out);	// NOTE: placeholder name (0x9b7ac0)
	bool isEdge(const Point &p);	// NOTE: placeholder name (0x9b7960)
	void getBounds(const Point &p, int radius, Point &topLeft, Point &bottomRight);	// NOTE: placeholder name (0x9b7a40)
	void getBoundsB(const Point &p, int radiusX, int radiusY, Point &topLeft, Point &bottomRight);	// NOTE: placeholder name (0x9b79c0)
};

bool OpR5h_Grid::contains(const Point &p)
{
	return p.x >= 0 && p.x < width && p.y >= 0 && p.y < height;
}

OpR5h_Area OpR5h_Grid::getArea()
{
	return OpR5h_Area(0,0,width - 1,height - 1);
}

void OpR5h_Grid::getRect(const Point &p, int radius, OpR5h_Area &out)
{
	out.topLeft.set(opR5h_maxInt(0,p.x - radius),opR5h_maxInt(0,p.y - radius));
	out.bottomRight.set(opR5h_minInt(width - 1,p.x + radius),opR5h_minInt(height - 1,p.y + radius));
}

void OpR5h_Grid::getRectB(const Point &p, int before, int after, OpR5h_Area &out)
{
	out.topLeft.set(opR5h_maxInt(0,p.x - before),opR5h_maxInt(0,p.y - before));
	out.bottomRight.set(opR5h_minInt(width - 1,p.x + after),opR5h_minInt(height - 1,p.y + after));
}

bool OpR5h_Grid::isEdge(const Point &p)
{
	return p.x == 0 || p.y == 0 || p.x == width - 1 || p.y == height - 1;
}

void OpR5h_Grid::getBounds(const Point &p, int radius, Point &topLeft, Point &bottomRight)
{
	topLeft.set(opR5h_maxInt(0,p.x - radius),opR5h_maxInt(0,p.y - radius));
	bottomRight.set(opR5h_minInt(width - 1,p.x + radius),opR5h_minInt(height - 1,p.y + radius));
}

void OpR5h_Grid::getBoundsB(const Point &p, int radiusX, int radiusY, Point &topLeft, Point &bottomRight)
{
	topLeft.set(opR5h_maxInt(0,p.x - radiusX),opR5h_maxInt(0,p.y - radiusY));
	bottomRight.set(opR5h_minInt(width - 1,p.x + radiusX),opR5h_minInt(height - 1,p.y + radiusY));
}

class OpR5h_Bounds	// NOTE: placeholder name
{
public:
	char pad00[0x14];
	int width;
	int height;
	int x;
	int y;

	bool contains(int px, int py);	// NOTE: placeholder name (0x9b6c50)
};

bool OpR5h_Bounds::contains(int px, int py)
{
	return px >= x && px < x + width && py >= y && py < y + height;
}
