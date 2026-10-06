// op_v4c: std template instances and small helpers in 0x9c3000-0x9e0000 of COGMIND.exe (Beta 17.1).
// NOTE: placeholder names (OpV4c_...) where the real names are unknown
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../util/rng.h"
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

class Predicate_409b90	// NOTE: placeholder name (see src/match_push)
{
public:
	int field0;
	int field4;
	bool test(const Predicate_409b90 &arg0);
};

class Predicate_409cf0	// NOTE: placeholder name (see src/match_push)
{
public:
	int field0;
	int field4;
	bool test(int arg0, int arg1);
};

struct Point
{
	int x;
	int y;

	Point(int x_, int y_);	// 0x46ca20
	Point(const Point &other);	// 0x46ca50
};

struct OpV4b_Dims
{
	int width;
	int height;
	bool OpV4b_inBounds(int x, int y);	// NOTE: placeholder name
	void OpV4c_getNeighbors(Point *pos, vector<Point> *list);	// NOTE: placeholder name
};

void OpV4b_Dims::OpV4c_getNeighbors(Point *pos, vector<Point> *list)
{
	for (int x = pos->x - 1; x <= pos->x + 1; x++)
	{
		for (int y = pos->y - 1; y <= pos->y + 1; y++)
		{
			if (((Predicate_409cf0*)pos)->test(x,y) && OpV4b_inBounds(x,y))
				list->push_back(Point(x,y));
		}
	}
}

template void std::wstring::_Copy(unsigned int, unsigned int);	// 0x9c7fc0
template bool std::wstring::_Inside(const wchar_t *);	// 0x9c8150

void OpV4c_Fn9d0690(int *value, int step, int low)	// NOTE: placeholder name
{
	int result;
	if (low + step >= *value)
	{
		*value = low;
		result = low;
	}
	else
	{
		*value -= step;
		result = *value;
	}
}

void OpV4c_Fn9d06d0(int *value, int step, int high)	// NOTE: placeholder name
{
	int result;
	if (*value + step >= high)
	{
		*value = high;
		result = high;
	}
	else
	{
		*value += step;
		result = *value;
	}
}

int OpV4c_Fn9d0ca0(int *list, unsigned int count)	// NOTE: placeholder name
{
	int sum = 0;
	for (unsigned int i = 0; i < count; i++)
		sum += list[i];
	return sum;
}

bool OpV4c_Fn9d3f40(int *list, unsigned int count)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
	{
		if (list[i])
			return true;
	}
	return false;
}

void OpV4c_Fn9d3b80(istream &stream, char *list)	// NOTE: placeholder name
{
	unsigned int count;
	stream.read((char*)&count,4);
	for (unsigned int i = 0; i < count; i++)
		stream.read(list + i,1);
}

void OpV4c_Fn9d3de0(ostream &stream, const char *list, unsigned int count)	// NOTE: placeholder name
{
	stream.write((const char*)&count,4);
	for (unsigned int i = 0; i < count; i++)
		stream.write(list + i,1);
}

bool OpV4c_Fn9d0ce0(vector<Point> &list, Point p)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (((Predicate_409b90*)&list[i])->test(*(Predicate_409b90*)&p))
			return true;
	}
	return false;
}

bool OpV4c_Fn9d3020(vector<Point> &list, Point p)	// NOTE: placeholder name
{
	if (!OpV4c_Fn9d0ce0(list,p))
	{
		list.push_back(p);
		return true;
	}
	return false;
}

void OpV4c_Fn9d5460(vector<Point> &list, unsigned int index, Point p)	// NOTE: placeholder name
{
	if (index == list.size())
		list.push_back(p);
	else
		list.insert(list.begin() + index,p);
}

class OpV4c_IntGrid	// NOTE: placeholder name (Array2D<int>, see OpS7_IntGrid2)
{
public:
	int width;
	int height;
	int *cells;

	void OpV4c_fillRect(const Point *a, const Point *b, int value);	// NOTE: placeholder name
};

void OpV4c_IntGrid::OpV4c_fillRect(const Point *a, const Point *b, int value)
{
	int index, len, c, j;
	len = b->y - a->y;
	for (c = a->x; c <= b->x; c++)
	{
		index = c*height + a->y;
		for (j = 0; j <= len; j++, index++)
			cells[index] = value;
	}
}

//==================================================================
// grid view (Array2D<int> with offset and out-of-range fill value)
//==================================================================

template <class T> class OpS8a_Array2D	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *cells;
	OpS8a_Array2D();
	~OpS8a_Array2D();
	void fill(int value);	// NOTE: placeholder name (0x9ec800)
	void resize(int width_, int height_, istream *stream);
	void OpV4c_resize(int width_, int height_);	// NOTE: placeholder name (0x9ec850)
	OpS8a_Array2D<T> &operator=(const OpS8a_Array2D<T> &other);
	T &operator()(int x, int y);	// 0x9ceda0
	void OpS8e_pad(T value, int left, int right, int top, int bottom);	// NOTE: placeholder name (0x9ec470)
};

bool OpT8b_Fn9d4c40(int a, int b, int c);	// NOTE: placeholder name

class OpV4c_View	// NOTE: placeholder name
{
public:
	int field0;
	int field4;
	OpS8a_Array2D<int> grid;
	int width;
	int height;
	int offsetX;
	int offsetY;
	int fillValue;
	int lastValue;

	OpV4c_View(int x_, int y_, int offsetX_, int offsetY_, int width_, int height_, int fillValue_, bool flag);	// 0x9cfc50
	int *get(Point *pos);	// 0x9cfd90
	int *get(int x, int y);	// 0x9cfe20
	const int *getConst(Point *pos);	// 0x9cfeb0
	OpV4c_View &operator=(const OpV4c_View &other);	// 0x9cff40
	void init(int x_, int y_, int fillValue_);	// 0x9cffc0
	void resizeView(int offsetX_, int offsetY_, int width_, int height_, bool flag);	// 0x9d0050
	void pad(int left, int right, int top, int bottom);	// 0x9d00b0
	void OpV4c_Fn9ed5b0();	// NOTE: placeholder name
};

OpV4c_View::OpV4c_View(int x_, int y_, int offsetX_, int offsetY_, int width_, int height_, int fillValue_, bool flag)
	: field0	(x_)
	, field4	(y_)
{
	width = width_;
	height = height_;
	offsetX = offsetX_;
	offsetY = offsetY_;
	fillValue = fillValue_;
	grid.resize(width_,height_,0);
	if (flag)
		OpV4c_Fn9ed5b0();
}

int *OpV4c_View::get(Point *pos)
{
	if (OpT8b_Fn9d4c40(-1,pos->x - offsetX,width) && OpT8b_Fn9d4c40(-1,pos->y - offsetY,height))
	{
		return &grid(pos->x - offsetX,pos->y - offsetY);
	}
	else
	{
		lastValue = fillValue;
		return &lastValue;
	}
}

int *OpV4c_View::get(int x, int y)
{
	if (OpT8b_Fn9d4c40(-1,x - offsetX,width) && OpT8b_Fn9d4c40(-1,y - offsetY,height))
	{
		return &grid(x - offsetX,y - offsetY);
	}
	else
	{
		lastValue = fillValue;
		return &lastValue;
	}
}

const int *OpV4c_View::getConst(Point *pos)
{
	if (OpT8b_Fn9d4c40(-1,pos->x - offsetX,width) && OpT8b_Fn9d4c40(-1,pos->y - offsetY,height))
	{
		return &grid(pos->x - offsetX,pos->y - offsetY);
	}
	else
	{
		return &fillValue;
	}
}

OpV4c_View &OpV4c_View::operator=(const OpV4c_View &other)
{
	field0 = other.field0;
	field4 = other.field4;
	offsetX = other.offsetX;
	offsetY = other.offsetY;
	width = other.width;
	height = other.height;
	fillValue = other.fillValue;
	grid = other.grid;
	return *this;
}

void OpV4c_View::init(int x_, int y_, int fillValue_)
{
	height = 1;
	width = 1;
	offsetY = 0;
	offsetX = 0;
	grid.resize(1,1,0);
	grid.fill(fillValue_);
	field0 = x_;
	field4 = y_;
	fillValue = fillValue_;
}

void OpV4c_View::resizeView(int offsetX_, int offsetY_, int width_, int height_, bool flag)
{
	offsetX = offsetX_;
	offsetY = offsetY_;
	width = width_;
	height = height_;
	grid.OpV4c_resize(width_,height_);
	if (flag)
		OpV4c_Fn9ed5b0();
}

void OpV4c_View::pad(int left, int right, int top, int bottom)
{
	if (left == 0 && right == 0 && top == 0 && bottom == 0)
		return;
	offsetX = offsetX - left;
	offsetY = offsetY - top;
	width = width + left + right;
	height = height + top + bottom;
	grid.OpS8e_pad(fillValue,left,right,top,bottom);
}

//==================================================================
// Array2D<XCell>
//==================================================================

struct XCell	// NOTE: placeholder layout
{
	int font;
	int ch;
	int glyph;
	XColor fore;
	XColor back;

	XCell();
	XCell(const XCell &cell);
	XCell &operator=(const XCell &cell);
};

class OpS7_CellGrid	// NOTE: placeholder name (Array2D<XCell>)
{
public:
	int width;
	int height;
	XCell *cells;

	OpS7_CellGrid(const OpS7_CellGrid &other);	// 0x9cdd40
	~OpS7_CellGrid();	// 0x9cec20
	void resize(int width_, int height_);	// 0x9ce020
	void OpS8e_blit(int x, int y, OpS7_CellGrid *src);	// NOTE: placeholder name (0x9ec220)
	void OpV4c_expand(XCell value, int left, int right, int top, int bottom);
};

void OpS7_CellGrid::OpV4c_expand(XCell value, int left, int right, int top, int bottom)
{
	if (left == 0 && right == 0 && top == 0 && bottom == 0)
		return;
	int oldWidth = width;
	int oldHeight = height;
	OpS7_CellGrid grid(*this);
	resize(width + left + right,height + top + bottom);
	OpS8e_blit(left,top,&grid);
	if (left)
	{
		for (int i = 0; i < width - oldWidth - right; i++)
		{
			for (int j = 0; j < height; j++)
				cells[i*height + j] = value;
		}
	}
	if (right)
	{
		for (int i = left + oldWidth; i < width; i++)
		{
			for (int j = 0; j < height; j++)
				cells[i*height + j] = value;
		}
	}
	if (top)
	{
		for (int i = left; i < oldWidth + left; i++)
		{
			for (int j = 0; j < height - oldHeight - bottom; j++)
				cells[i*height + j] = value;
		}
	}
	if (bottom)
	{
		for (int i = left; i < oldWidth + left; i++)
		{
			for (int j = top + oldHeight; j < height; j++)
				cells[i*height + j] = value;
		}
	}
}

//==================================================================
// vector helpers
//==================================================================

class MapRecord;

extern RNG rng;	// 0xd30908

extern int (*OpV4c_shuffleFn)(int);	// NOTE: placeholder name (0xcaecd8)

template <class T> void OpV4c_shuffle(vector<T> &v)	// NOTE: placeholder name
{
	random_shuffle(v.begin(),v.end(),OpV4c_shuffleFn);
}

struct OpV4c_T9d9fc0;	// NOTE: placeholder name

template void OpV4c_shuffle<Point>(vector<Point> &v);	// 0x9d7350
template void OpV4c_shuffle<OpV4c_T9d9fc0 *>(vector<OpV4c_T9d9fc0 *> &v);	// 0x9d9fc0
template void OpV4c_shuffle<bool>(vector<bool> &v);	// 0x9db910

bool OpV4c_Fn9d7670(const vector<bool> &v, bool value)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == value)
			return true;
	}
	return false;
}

void OpV4c_Fn9da310(vector<MapRecord *> &records, MapRecord *record, vector<int> &indices)	// NOTE: placeholder name
{
	for (int i = 0; i < records.size(); i++)
	{
		if (records[i] == record)
			indices.push_back(i);
	}
}

template <class T> void OpS8c_shuffle(vector<T> &v);	// NOTE: placeholder name

void OpV4c_Fn9da8f0(vector<MapRecord *> &records, vector<int> &indices)	// NOTE: placeholder name
{
	for (int i = 0; i < records.size(); i++)
		indices.push_back(i);
	OpS8c_shuffle(indices);
}

struct OpV4c_Handle	// NOTE: placeholder name
{
	MapRecord *record;
	OpV4c_Handle();
};

struct OpV4c_Elem9e3c60	// NOTE: placeholder name
{
	int a, b, c, d;
	OpV4c_Elem9e3c60(const OpV4c_Elem9e3c60 &e);	// 0x40b130
};

struct OpV4c_Elem9e3be0	// NOTE: placeholder name
{
	char pad[0x14];
	OpV4c_Elem9e3be0(const OpV4c_Elem9e3be0 &e);	// 0x9e7420
	~OpV4c_Elem9e3be0();
};

template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name

string OpV4c_popRandomString(vector<string> &v)	// NOTE: placeholder name
{
	int index = rng.rangeInt(0,v.size() - 1);
	string s = v[index];
	OpQ5_eraseAt(v,index);
	return s;
}

OpV4c_Handle OpV4c_randomHandle(vector<OpV4c_Handle> &v)	// NOTE: placeholder name
{
	return v[rng.rangeInt(0,v.size() - 1)];
}

bool OpV4c_Fn9db330(vector<MapRecord *> &v, MapRecord *record)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == record)
			return true;
	}
	return false;
}

OpV4c_Elem9e3be0 OpV4c_randomElem(vector<OpV4c_Elem9e3be0> &v)	// NOTE: placeholder name
{
	return v[rng.rangeInt(0,v.size() - 1)];
}

OpV4c_Elem9e3c60 OpV4c_popRandomElem(vector<OpV4c_Elem9e3c60> &v)	// NOTE: placeholder name
{
	int index = rng.rangeInt(0,v.size() - 1);
	OpV4c_Elem9e3c60 elem = v[index];
	OpQ5_eraseAt(v,index);
	return elem;
}
