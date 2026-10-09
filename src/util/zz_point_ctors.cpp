// Constructors of Pos and Point that no file defines (every caller linked against a stub and the strict target check
// rejected the pairing): default (-1,-1), copy, splat, base + offset and sum.
// The exe folds Pos and Point: 0x453b40 (default), 0x46ca50 (copy), 0x409990 (splat), 0x4099c0 (+dx,dy), 0x4099f0 (sum).
struct Pos
{
	int x;
	int y;
	Pos();							// 0x453b40
	Pos(const Pos &pos);			// 0x46ca50
	Pos(const Pos &base, int dx, int dy);	// 0x4099c0
};

struct Point
{
	int x;
	int y;
	Point();						// 0x453b40
	Point(int v);					// 0x409990
	Point(const Point &a, const Point &b);	// 0x4099f0
};

Pos::Pos()
{
	x = -1;
	y = -1;
}

Pos::Pos(const Pos &pos)
{
	x = pos.x;
	y = pos.y;
}

Pos::Pos(const Pos &base, int dx, int dy)
	: x (base.x + dx)
	, y (base.y + dy)
{
}

Point::Point()
{
	x = -1;
	y = -1;
}

Point::Point(int v)
{
	x = v;
	y = v;
}

Point::Point(const Point &a, const Point &b)
	: x (a.x + b.x)
	, y (a.y + b.y)
{
}
