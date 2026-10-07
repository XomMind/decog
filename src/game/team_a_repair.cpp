// team_a_repair: definitions moved out of earlier shared files so that LTCG compiles them late enough in the link
// order to know their callees are nothrow (the exe has no EH frame for them).
// NOTE: class layouts are partial; names are placeholders unless noted.
#include <string>
#include <vector>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor() throw();	// 0x411d40
};

struct OpX5_S14;
template <class T> class OpX5_Array2D	// NOTE: placeholder name (defined and instantiated in op_x5.cpp)
{
public:
	int	width;
	int	height;
	T	*cells;
	OpX5_Array2D();	// 0x9d2670
};

class XConsole;
class FontSet;

class REX	// NOTE: placeholder layout (0xd223f0); see cc_r2_22.cpp
{
public:
	REX();

	char pad0[0x24];
	string title;
	string icon;
	char pad5c[0x6c - 0x5c];
	XConsole *root;
	OpX5_Array2D<OpX5_S14> screen;	// NOTE: an Array2D<XCell>; the exe calls the folded OpX5_Array2D<OpX5_S14> constructor
	string unknown7c;
	XColor unknown98;
	vector<int> unknown9c;
	vector<int> unknownac;
	vector<FontSet*> fontSets;
	char padcc[0xe0 - 0xcc];
	string unknowne0;
	int unknownfc;
	string unknown100;
	char pad11c[0x150 - 0x11c];
	string unknown150;
	string unknown16c;
	char pad188[0x1a0 - 0x188];
};

REX::REX()
{
	root = NULL;
}

// Pos and Rect value constructors: no other file defines them, so every caller linked against a stub and LTCG had to
// assume they may throw (the exe proves them nothrow). Defining them lets LTCG drop the EH frames, as in the exe.
// The exe folds them with Push_409990::operate, Point::Point(int, int) and Push_456940::operate.
struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_);	// 0x46ca20
	Pos(int v);				// 0x409990
};

Pos::Pos(int x_, int y_)
{
	x = x_;
	y = y_;
}

Pos::Pos(int v)
{
	x = v;
	y = v;
}

struct Rect
{
	int x;
	int y;
	int width;
	int height;
	Rect(int x_, int y_, int width_, int height_);	// 0x456940
};

Rect::Rect(int x_, int y_, int width_, int height_)
{
	x = x_;
	y = y_;
	width = width_;
	height = height_;
}
