#include <stdlib.h>
// NOTE: placeholder names for recovered two-coordinate operations.
struct PushGeometry
{
	int x;
	int y;
	bool less(const PushGeometry &p);
	bool greater(const PushGeometry &p);
	bool adjacent(const PushGeometry &p);
	bool contains(int left, int top, int width, int height);
	int distance(int x_, int y_);
	int distanceTo(const PushGeometry &p);
};
bool PushGeometry::less(const PushGeometry &p)
{
	return x < p.x || (x == p.x && y < p.y);
}
bool PushGeometry::greater(const PushGeometry &p)
{
	return x > p.x || (x == p.x && y > p.y);
}
bool PushGeometry::adjacent(const PushGeometry &p)
{
	return abs(p.x - x) <= 1 && abs(p.y - y) <= 1;
}
bool PushGeometry::contains(int left, int top, int width, int height)
{
	return x >= left && x < left + width && y >= top && y < top + height;
}
int PushGeometry::distance(int x_, int y_)
{
	return abs(x_ - x) + abs(y_ - y);
}
int PushGeometry::distanceTo(const PushGeometry &p)
{
	return abs(p.x - x) + abs(p.y - y);
}
struct PushRectangle
{
	int x;
	int y;
	int width;
	int height;
	int area();
};
int PushRectangle::area()
{
	return width < 0 ? 0 : width * height;
}
