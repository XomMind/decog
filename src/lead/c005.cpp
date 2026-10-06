// Lead cluster c005: Point (also used as an int range) and Area (inclusive rectangle) methods.
// NOTE: all class/member names are placeholders; addresses are suffixed where the name is generic.
#include <string>
#include <vector>
#include <ostream>
using namespace std;

class RNG	// NOTE: placeholder layout
{
public:
	int rangeInt(float a, float b);
	float rangeFloat(float a, float b);
};
extern RNG rng;	// 0xd30908

string intToString(int value);	// NOTE: placeholder name

int maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
int minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)
bool inRange(int lo, int v, int hi);	// NOTE: placeholder name (0x9daf80)
void writeInt(ostream &os, int *v);	// NOTE: placeholder name (0x9d3b60)

struct Point	// NOTE: placeholder layout; also used as an int range (min,max)
{
	int x;
	int y;
	Point();	// 0x453b40
	Point(int x_, int y_);	// 0x46ca20
	void set(int x_, int y_);	// 0x40a010
	Point &operator=(const Point &p);	// 0x46ca50
	void addBoth(int v);	// NOTE: placeholder name (0x40bf50)
	bool isSingle() const;	// NOTE: placeholder name (ICF with vector<int>::empty)

	void serialize_40bf20(ostream &os);	// NOTE: placeholder name
	int randomInRange_40c130();	// NOTE: placeholder name
	bool contains_40c190(int v);	// NOTE: placeholder name
	bool overlaps_40c1c0(const Point &o);	// NOTE: placeholder name
	int clamp_40c270(int v);	// NOTE: placeholder name
	string rangeToString_40c2b0(string sep);	// NOTE: placeholder name
};

struct RectXYWH	// NOTE: placeholder name
{
	int x;
	int y;
	int w;
	int h;
};

struct Rect4	// NOTE: placeholder name
{
	Rect4(int a, int b, int c, int d);	// 0x456940
	int v[4];
};

struct Area	// NOTE: placeholder name
{
	Point min;
	Point max;

	Area(const RectXYWH &r);	// 0x40b290
	void set_40b360(const Point &p, int w, int h);	// NOTE: placeholder name
	Point center_40b620();	// NOTE: placeholder name
	Rect4 toRect_40b6b0();	// NOTE: placeholder name
	bool contains_40b700(int x, int y);	// 0x40b700
	bool contains_40b750(const Point &p);	// NOTE: placeholder name
	bool containsAny_40b780(vector<Point> &v);	// NOTE: placeholder name
	bool contains_40b7e0(const RectXYWH &r);	// NOTE: placeholder name
	bool contains_40b8a0(const Area &a);	// NOTE: placeholder name
	void unionWith_40b940(const Area &a, Area &out);	// NOTE: placeholder name
	int distance_40ba00(const Area &a);	// NOTE: placeholder name
	void getBorder_40bac0(vector<Point> &out);	// NOTE: placeholder name
	void include_40bb90(const Point &p);	// NOTE: placeholder name
	bool fitAround_40bcb0(const Point &p, int m);	// NOTE: placeholder name
	void grow_40bc10(int n);	// NOTE: placeholder name
	void randomPoint_40be30(Point *out);	// NOTE: placeholder name
	Point randomPoint_40be90();	// NOTE: placeholder name
};

struct FloatRange	// NOTE: placeholder name
{
	float lo;
	float hi;
	float random_40c700();	// NOTE: placeholder name
};

bool pointsOverlap_40c420(vector<Point> &v, const Point &r);	// NOTE: placeholder name

Area::Area(const RectXYWH &r)
{
	min.x = r.x;
	min.y = r.y;
	max.x = r.x + r.w - 1;
	max.y = r.y + r.h - 1;
}

void Area::set_40b360(const Point &p, int w, int h)
{
	min = p;
	max.set(min.x + w - 1, min.y + h - 1);
}

Point Area::center_40b620()
{
	return Point(min.x + (max.x - min.x) / 2, min.y + (max.y - min.y) / 2);
}

Rect4 Area::toRect_40b6b0()
{
	return Rect4(min.x, min.y, max.x - min.x + 1, max.y - min.y + 1);
}

bool Area::contains_40b750(const Point &p)
{
	return contains_40b700(p.x, p.y);
}

bool Area::containsAny_40b780(vector<Point> &v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (contains_40b750(v[i]))
			return true;
	}
	return false;
}

bool Area::contains_40b7e0(const RectXYWH &r)
{
	return contains_40b700(r.x, r.y)
		&& contains_40b700(r.x + r.w - 1, r.y)
		&& contains_40b700(r.x, r.y + r.h - 1)
		&& contains_40b700(r.x + r.w - 1, r.y + r.h - 1);
}

bool Area::contains_40b8a0(const Area &a)
{
	return contains_40b700(a.min.x, a.min.y)
		&& contains_40b700(a.max.x, a.min.y)
		&& contains_40b700(a.min.x, a.max.y)
		&& contains_40b700(a.max.x, a.max.y);
}

void Area::unionWith_40b940(const Area &a, Area &out)
{
	out.min.x = (min.x > a.min.x) ? min.x : a.min.x;
	out.max.x = (max.x > a.max.x) ? max.x : a.max.x;
	out.min.y = (min.y > a.min.y) ? min.y : a.min.y;
	out.max.y = (max.y > a.max.y) ? max.y : a.max.y;
}

int Area::distance_40ba00(const Area &a)
{
	int total = 0;
	int d = maxInt(min.x, a.min.x) - minInt(max.x, a.max.x);
	if (d > 0)
		total += d;
	d = maxInt(min.y, a.min.y) - minInt(max.y, a.max.y);
	if (d > 0)
		total += d;
	return total;
}

void Area::getBorder_40bac0(vector<Point> &out)
{
	for (int x = min.x; x <= max.x; x++)
	{
		out.push_back(Point(x, min.y));
		out.push_back(Point(x, max.y));
	}
	for (int y = min.y + 1; y <= max.y - 1; y++)
	{
		out.push_back(Point(min.x, y));
		out.push_back(Point(max.x, y));
	}
}

void Area::include_40bb90(const Point &p)
{
	if (p.x < min.x)
		min.x = p.x;
	else if (p.x > max.x)
		max.x = p.x;
	if (p.y < min.y)
		min.y = p.y;
	else if (p.y > max.y)
		max.y = p.y;
}

void Area::grow_40bc10(int n)
{
	min.addBoth(-n);
	max.addBoth(n);
}

bool Area::fitAround_40bcb0(const Point &p, int m)
{
	bool changed = false;
	if (p.x - m < min.x)
	{
		max.x = max.x - (min.x - (p.x - m));
		min.x = p.x - m;
		changed = true;
	}
	else if (p.x + m > max.x)
	{
		min.x = p.x + m - max.x + min.x;
		max.x = p.x + m;
		changed = true;
	}
	if (p.y - m < min.y)
	{
		max.y = max.y - (min.y - (p.y - m));
		min.y = p.y - m;
		changed = true;
	}
	else if (p.y + m > max.y)
	{
		min.y = p.y + m - max.y + min.y;
		max.y = p.y + m;
		changed = true;
	}
	return changed;
}

void Area::randomPoint_40be30(Point *out)
{
	out->set(rng.rangeInt(min.x, max.x), rng.rangeInt(min.y, max.y));
}

Point Area::randomPoint_40be90()
{
	return Point(rng.rangeInt(min.x, max.x), rng.rangeInt(min.y, max.y));
}

void Point::serialize_40bf20(ostream &os)
{
	writeInt(os, &x);
	writeInt(os, &y);
}

int Point::randomInRange_40c130()
{
	if (isSingle())
		return y;
	return rng.rangeInt(x, y);
}

bool Point::contains_40c190(int v)
{
	return inRange(x, v, y);
}

bool Point::overlaps_40c1c0(const Point &o)
{
	return inRange(x, o.x, y)
		|| inRange(x, o.y, y)
		|| inRange(o.x, x, o.y)
		|| inRange(o.x, y, o.y);
}

int Point::clamp_40c270(int v)
{
	if (v < x)
		return x;
	if (v > y)
		return y;
	return v;
}

string Point::rangeToString_40c2b0(string sep)
{
	if (x == y)
		return intToString(y);
	else
		return intToString(x) + sep + intToString(y);
}

bool pointsOverlap_40c420(vector<Point> &v, const Point &r)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i].overlaps_40c1c0(r))
			return true;
	}
	return false;
}

float FloatRange::random_40c700()
{
	return rng.rangeFloat(lo, hi);
}
