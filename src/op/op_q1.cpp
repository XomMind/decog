// op_q1: matched functions in 0x409000-0x516000 of COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;

bool OpY1_equalsNoCase(const string &a, const string &b);

int OpQ1_findStringNoCase(const string *list, unsigned int count, const string &text)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
	{
		if (OpY1_equalsNoCase(list[i],text))
			return i;
	}
	return -1;
}

void OpQ1_findNextSlash(string &text, unsigned int *pos)	// NOTE: placeholder name
{
	unsigned int index = text.find('/',*pos + 1);
	if (index == string::npos)
		text += "/";
	*pos = index;
}

#include <fstream>
#include <windows.h>
void logError(string location, string message);	// NOTE: placeholder name

void OpQ1_createDirectories(string path)	// NOTE: placeholder name
{
	if (path.empty())
		return;
	if (path[0] == '/' || path[0] == '\\')
		path.erase(path.begin());
	if (path.back() != '/' && path.back() != '\\')
		path += "/";
	for (unsigned int i = 0; i < path.size(); i++)
	{
		if (path[i] == '\\')
			path[i] = '/';
	}
	unsigned int pos = -1;
	OpQ1_findNextSlash(path,&pos);
	int count = 0;
	while (true)
	{
		string sub(path.begin(),path.begin() + pos + 1);
		CreateDirectoryA(sub.c_str(),NULL);
		if (sub.size() == path.size())
			break;
		pos++;
		OpQ1_findNextSlash(path,&pos);
		count++;
		if (count >= 50)
			logError("createDirectory()","failed on path: " + path);
	}
}

struct Point
{
	int x;
	int y;

	Point(int x_, int y_);
	Point(const Point &p) throw();	// 0x46ca50
	Point &operator=(const Point &p);	// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
	void setBoth(int value);	// NOTE: placeholder name (0x409ff0)
};

struct OpQ1_Pt	// NOTE: placeholder name
{
	int x;
	int y;

	void getAdjacent(vector<Point> &out, bool cardinalOnly);	// NOTE: placeholder name
};

void OpQ1_Pt::getAdjacent(vector<Point> &out, bool cardinalOnly)
{
	out.push_back(Point(x - 1,y));
	out.push_back(Point(x,y - 1));
	out.push_back(Point(x + 1,y));
	out.push_back(Point(x,y + 1));
	if (cardinalOnly)
		return;
	out.push_back(Point(x - 1,y - 1));
	out.push_back(Point(x + 1,y - 1));
	out.push_back(Point(x - 1,y + 1));
	out.push_back(Point(x + 1,y + 1));
}

struct PHYSFS_File;
namespace PhysFScpp
{
	class base_fstream
	{
	protected:
		PHYSFS_File * const file;
	public:
		base_fstream(PHYSFS_File *file);
		virtual ~base_fstream();
	};

	class ifstream : public base_fstream, public std::istream
	{
	public:
		ifstream(string const &filename, std::ios_base::openmode mode = std::ios_base::in);
		virtual ~ifstream();
		void close_9c05e0();	// NOTE: placeholder name (empty)
	};
}

void OpQ1_copyPhysFile(string source, string dest)	// NOTE: placeholder name
{
	PhysFScpp::ifstream in(source.c_str(),ios::binary);
	ofstream out(dest.c_str(),ios::binary);
	out << in.rdbuf();
	in.close_9c05e0();
	out.close();
}

string intToString(int value);
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
void opw8_eraseFirstChar(string &s);	// NOTE: placeholder name (0x4077e0)
void opw8_eraseLastChar(string &s);	// NOTE: placeholder name (0x407840)

struct OpQ1_Pt2	// NOTE: placeholder name
{
	int x;
	int y;

	bool fromString(string text);	// NOTE: placeholder name
};

bool OpQ1_Pt2::fromString(string text)
{
	if (text.empty() || text[0] != '(' || text[text.size() - 1] != ')')
		return false;
	opw8_eraseFirstChar(text);
	opw8_eraseLastChar(text);
	unsigned int comma = text.find(',');
	if (comma == string::npos)
		return false;
	x = stringToInt(string(text.begin(),text.begin() + comma));
	y = stringToInt(string(text.begin() + comma + 1,text.end()));
	return true;
}

string OpQ1_pointToString(const OpQ1_Pt2 *p)	// NOTE: placeholder name
{
	return string("(" + intToString(p->x) + "," + intToString(p->y) + ")");
}

struct Pos
{
	int x;
	int y;

	Pos();	// 0x453b40
	Pos(const Pos &pos) throw();	// 0x46ca50
	void setBoth_409ff0(int value);	// NOTE: placeholder name
	void set(int x_, int y_);	// NOTE: placeholder name (0x40a010)
	int randomInRange_40c130();	// NOTE: placeholder name
	bool parseRange_40bf80(const string &text);	// NOTE: placeholder name
};

struct OpQ1_Box	// NOTE: placeholder name (two corner positions)
{
	Pos min;
	Pos max;

	void set(int x1, int y1, int x2, int y2);	// NOTE: placeholder name (0x40b300)
	bool parse_40b480(const string &text);	// NOTE: placeholder name
};

bool OpQ1_Box::parse_40b480(const string &text)
{
	if (text == "-")
		set(-1,-1,-1,-1);
	else
	{
		vector<int> numbers;
		string current;
		for (unsigned int i = 1; i < text.size(); i++)
		{
			if (isdigit(text[i]))
				current += text[i];
			else
			{
				if (current.size())
				{
					int value = stringToInt(current);
					numbers.push_back(value);
				}
				current.clear();
			}
		}
		if (numbers.size() != 4)
			return false;
		set(numbers[0],numbers[1],numbers[2],numbers[3]);
	}
	return true;
}

bool Pos::parseRange_40bf80(const string &text)
{
	unsigned int dash = text.find('-',0);
	if (dash == 0)
	{
		if (text.size() == 1)
			setBoth_409ff0(0);
		else
			setBoth_409ff0(stringToInt(text));
	}
	else if (dash == string::npos)
		setBoth_409ff0(stringToInt(text));
	else
	{
		if (dash == text.size() - 1)
			return false;
		set(stringToInt(string(text.begin(),text.begin() + dash)),stringToInt(string(text.begin() + dash + 1,text.end())));
		if (x > y)
			return false;
	}
	return true;
}

struct OpQ1_FRange	// NOTE: placeholder name
{
	float min;
	float max;

	void set_40c4c0(float value);	// NOTE: placeholder name
	void set_40c4e0(float a, float b);	// NOTE: placeholder name
	bool parse_40c500(const string &text);	// NOTE: placeholder name
	float clamp_40c760(float value);	// NOTE: placeholder name
};

bool OpQ1_FRange::parse_40c500(const string &text)
{
	unsigned int dash = text.find('-',0);
	if (dash == 0)
		set_40c4e0(0,text.size() == 1 ? 0 : -stringToInt(text));
	else if (dash == string::npos)
		set_40c4c0(stringToInt(text));
	else
	{
		if (dash == text.size() - 1)
			return false;
		set_40c4e0(stringToInt(string(text.begin(),text.begin() + dash)),stringToInt(string(text.begin() + dash + 1,text.end())));
		if (min > max)
			return false;
	}
	return true;
}

float OpQ1_FRange::clamp_40c760(float value)
{
	if (value < min)
		return min;
	if (value > max)
		return max;
	return value;
}

extern Pos pos_cf08ec;	// NOTE: placeholder name (0xcf08ec, defined in cc_r2_31)

#include "../util/rng.h"
extern RNG rng;	// 0xd30908

struct OpQ1_IntList	// NOTE: placeholder name
{
	vector<int> values;

	void split_40c840(int total);	// NOTE: placeholder name
};

void OpQ1_IntList::split_40c840(int total)
{
	int roll;
	int c;
	values.clear();
	if (total == 0)
		return;
	c = pos_cf08ec.randomInRange_40c130();
	if (total > 0)
	{
		for (int i = 0; i < c - 1; i++)
		{
			roll = rng.rangeInt(1,total - 1);
			values.push_back(roll);
			total -= roll;
			if (i == c - 2)
				values.push_back(total);
		}
	}
	else
	{
		for (int j = 0; j < c - 1; j++)
		{
			roll = rng.rangeInt(-1,total + 1);
			values.push_back(roll);
			total += roll;
			if (j == c - 2)
				values.push_back(total);
		}
	}
}

class Unknown_40cde0	// NOTE: placeholder name (destructor at 0x40cde0; layout widened here)
{
public:
	int width;
	int height;
	bool flagA;
	bool flagB;
	int limit;
	int unknown10;	// NOTE: placeholder name
	int *gridA;
	int *cornerA;
	int *gridB;
	int *gridC;
	int *cornerB;
	int *cornerC;
	int *gridD;
	int *cornerD;
	int *gridE;

	Unknown_40cde0(int width_, int height_);	// NOTE: placeholder signature (0x40cac0)
	~Unknown_40cde0();
	void resize_40cec0(int width_, int height_);	// NOTE: placeholder name
};

Unknown_40cde0::Unknown_40cde0(int width_, int height_)
{
	width = width_;
	height = height_;
	flagA = false;
	flagB = false;
	limit = 10;
	gridA = new int[width * height + 2];
	cornerA = new int[(width + 1) * (height + 1)];
	gridB = new int[width * height + 2];
	gridC = new int[width * height + 2];
	cornerB = new int[(width + 1) * (height + 1)];
	cornerC = new int[(width + 1) * (height + 1)];
	gridD = new int[width * height + 2];
	cornerD = new int[(width + 1) * (height + 1)];
	gridE = new int[width * height + 2];
	for (unsigned int i = 0; i < width * height + 2; i++)
	{
		gridE[i] = 0;
		gridD[i] = 0;
		gridC[i] = 0;
		gridB[i] = 0;
		gridA[i] = 0;
	}
	for (unsigned int j = 0; j < (width + 1) * (height + 1); j++)
	{
		cornerD[j] = 0;
		cornerC[j] = 0;
		cornerB[j] = 0;
		cornerA[j] = 0;
	}
}

Unknown_40cde0::~Unknown_40cde0()
{
	delete [] gridA;
	delete [] cornerA;
	delete [] gridB;
	delete [] gridC;
	delete [] cornerB;
	delete [] cornerC;
	delete [] gridD;
	delete [] cornerD;
	delete [] gridE;
}

void Unknown_40cde0::resize_40cec0(int width_, int height_)
{
	width = width_;
	height = height_;
	delete [] gridA;
	delete [] cornerA;
	delete [] gridB;
	delete [] gridC;
	delete [] cornerB;
	delete [] cornerC;
	delete [] gridD;
	delete [] cornerD;
	delete [] gridE;
	gridA = new int[width * height + 2];
	cornerA = new int[(width + 1) * (height + 1)];
	gridB = new int[width * height + 2];
	gridC = new int[width * height + 2];
	cornerB = new int[(width + 1) * (height + 1)];
	cornerC = new int[(width + 1) * (height + 1)];
	gridD = new int[width * height + 2];
	cornerD = new int[(width + 1) * (height + 1)];
	gridE = new int[width * height + 2];
	for (unsigned int i = 0; i < width * height + 2; i++)
	{
		gridE[i] = 0;
		gridD[i] = 0;
		gridC[i] = 0;
		gridB[i] = 0;
		gridA[i] = 0;
	}
	for (unsigned int j = 0; j < (width + 1) * (height + 1); j++)
	{
		cornerD[j] = 0;
		cornerC[j] = 0;
		cornerB[j] = 0;
		cornerA[j] = 0;
	}
}

void OpQ1_lineBresenham(int x1, int y1, int x2, int y2, vector<Point> &line)	// NOTE: placeholder name
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int ax = (dx < 0 ? -dx : dx) << 1;
	int ay = (dy < 0 ? -dy : dy) << 1;
	int x;
	int y;
	int sx = dx < 0 ? -1 : dx > 0;
	int sy = dy < 0 ? -1 : dy > 0;
	int d;
	int d2;
	x = x1;
	y = y1;
	if (ax >= ay)
	{
		d = ay - (ax >> 1);
		for (;;)
		{
			line.push_back(Point(x,y));
			if (x == x2)
				return;
			if (d >= 0)
			{
				y += sy;
				d -= ax;
			}
			x += sx;
			d += ay;
		}
	}
	else
	{
		d2 = ax - (ay >> 1);
		for (;;)
		{
			line.push_back(Point(x,y));
			if (y == y2)
				return;
			if (d2 >= 0)
			{
				x += sx;
				d2 -= ay;
			}
			y += sy;
			d2 += ax;
		}
	}
}

void OpQ1_lineBresenhamPoints_40ff30(const Point &from, const Point &to, vector<Point> &line)	// NOTE: placeholder name
{
	OpQ1_lineBresenham(from.x,from.y,to.x,to.y,line);
}

bool OpQ1_nextLineStep_40ff60(const Point &from, const Point &to, Point &next)	// NOTE: placeholder name
{
	if (from == to)
	{
		next.setBoth(-1);
		return false;
	}
	vector<Point> line;
	OpQ1_lineBresenhamPoints_40ff30(from,to,line);
	next = line[1];
	return true;
}
