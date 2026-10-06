// op_q1_rect: Rect helpers in 0x40a8b0-0x40af30 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <istream>
#include <ostream>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Pos
{
	int x;
	int y;

	Pos();	// 0x453b40
	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos) throw();	// 0x46ca50
	void set(int x_, int y_);	// NOTE: placeholder name (0x40a010)
};

int minInt(int a, int b);	// 0x9cdb30
int opw2_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	void read_40a8b0(istream &in);	// NOTE: placeholder name
	void write_40a910(ostream &out);	// NOTE: placeholder name
	bool contains(int x_, int y_) const;	// NOTE: placeholder name (0x40a9a0)
	bool containsRect_40aa70(const Rect &other);	// NOTE: placeholder name
	void intersect_40ab30(const Rect &other, Rect &out);	// NOTE: placeholder name
	bool containsPos_40aa00(const Pos &pos);	// NOTE: placeholder name
	int distance_40ae20(const Rect &other);	// NOTE: placeholder name
	int right_40ac20() const;	// NOTE: placeholder name
	int bottom_40ac40() const;	// NOTE: placeholder name
	bool onOutline_40ad80(int x_, int y_);	// NOTE: placeholder name
	void expandToInclude_40af10(const Pos &pos);	// NOTE: placeholder name
	void randomPos_40b000(Pos &out);	// NOTE: placeholder name
	Pos randomPos_40b080();	// NOTE: placeholder name
};

struct OpQ1_Box	// NOTE: placeholder name (two corner positions)
{
	Pos min;
	Pos max;

	OpQ1_Box(const Pos &pos, int width, int height);
	OpQ1_Box(int x1, int y1, int x2, int y2);
	OpQ1_Box(const Pos &center, int radius);
};

void Rect::read_40a8b0(istream &in)
{
	in.read((char *)&x,4);
	in.read((char *)&y,4);
	in.read((char *)&width,4);
	in.read((char *)&height,4);
}

void Rect::write_40a910(ostream &out)
{
	out.write((const char *)&x,4);
	out.write((const char *)&y,4);
	out.write((const char *)&width,4);
	out.write((const char *)&height,4);
}

bool Rect::contains(int x_, int y_) const
{
	return x_ >= x && x_ < x + width && y_ >= y && y_ < y + height;
}

bool Rect::containsPos_40aa00(const Pos &pos)
{
	return pos.x >= x && pos.x < x + width && pos.y >= y && pos.y < y + height;
}

bool Rect::containsRect_40aa70(const Rect &other)
{
	return contains(other.x,other.y)
		&& contains(other.x + other.width - 1,other.y)
		&& contains(other.x,other.y + other.height - 1)
		&& contains(other.x + other.width - 1,other.y + other.height - 1);
}

void Rect::intersect_40ab30(const Rect &other, Rect &out)
{
	out.x = x > other.x ? x : other.x;
	out.width = (right_40ac20() < other.right_40ac20() ? right_40ac20() : other.right_40ac20()) - out.x + 1;
	out.y = y > other.y ? y : other.y;
	out.height = (bottom_40ac40() < other.bottom_40ac40() ? bottom_40ac40() : other.bottom_40ac40()) - out.y + 1;
}

bool Rect::onOutline_40ad80(int x_, int y_)
{
	return (x_ == x - 1 || x_ == x + width) && y_ >= y && y_ < y + height
		|| (y_ == y - 1 || y_ == y + height) && x_ >= x && x_ < x + width;
}

int Rect::distance_40ae20(const Rect &other)
{
	int total = 0;
	int diff;
	diff = opw2_maxInt(x,other.x) - minInt(x + width - 1,other.x + other.width - 1);
	if (diff > 0)
		total += diff;
	diff = opw2_maxInt(y,other.y) - minInt(y + height - 1,other.y + other.height - 1);
	if (diff > 0)
		total += diff;
	return total;
}

void Rect::expandToInclude_40af10(const Pos &pos)
{
	if (pos.x < x)
		x = pos.x;
	else if (pos.x > x + width - 1)
		width = pos.x - x + 1;
	if (pos.y < y)
		y = pos.y;
	else if (pos.y > y + height - y)
		height = pos.y - y + 1;
}

void Rect::randomPos_40b000(Pos &out)
{
	out.set(rng.rangeInt(x,x + width - 1),rng.rangeInt(y,y + height - 1));
}

Pos Rect::randomPos_40b080()
{
	return Pos(rng.rangeInt(x,x + width - 1),rng.rangeInt(y,y + height - 1));
}

OpQ1_Box::OpQ1_Box(const Pos &pos, int width, int height)
	: min	(pos)
{
	max.x = min.x + width - 1;
	max.y = min.y + height - 1;
}

OpQ1_Box::OpQ1_Box(int x1, int y1, int x2, int y2)
{
	min.x = x1;
	min.y = y1;
	max.x = x2;
	max.y = y2;
}

OpQ1_Box::OpQ1_Box(const Pos &center, int radius)
{
	min.set(center.x - radius,center.y - radius);
	max.set(center.x + radius,center.y + radius);
}
