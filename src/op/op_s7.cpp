// op_s7: functions in 0x8b5000-0x9d0000 of COGMIND.exe (Beta 17.1). Names are placeholders unless stated.
#include <string>
#include <vector>
#include <algorithm>
#include <istream>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos) throw();	// 0x46ca50
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();	// 0x40a6e0
	Rect(const Rect &rect);	// 0x40a720
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Pos mouse;
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool isActive();
	virtual void refresh();
	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int modifier);	// NOTE: placeholder name
	virtual void update();
	virtual void render();

	bool isHidden();
	XConsole *getParent();	// 0x9b8f00
	Pos getPos();
	int getWidth();	// 0x44b0d0
	int getHeight();
	void print(int x, int y, const string &text);
	void putChar_4180b0(int x, int y, int ch);	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);
	bool input429d00(XEvent *event);	// NOTE: placeholder name (XConsole::input body)
	void update429e30();	// NOTE: placeholder name (XConsole::update body)
	void clearInterior();
	void deleteSubconsoles();
	void unknown429f10(int a, int b);	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class OpS7_Engine	// NOTE: placeholder name (animation engine, see OpR2b_Engine)
{
public:
	void killGroup(string group);
	bool update();	// 0x50fff0
	void stopAll();	// 0x50ff30
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);
	void setTitle(class ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)

	int unknown60;
	OpS7_Engine *engine;
	void *title;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);
	char pad6c[0x8c - 0x6c];
};

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);

	string text;
};

class CTextInput : public Console
{
public:
	void setText(const string &text);	// NOTE: placeholder name (0x48d300)
};

class MapRecord;

struct OpS7_RobotManual	// NOTE: placeholder name
{
	char pad00[0x6c];
	CTextInput *input;
	char pad70[0x80 - 0x70];
	string text;
	vector<MapRecord*> records;
	int index;
};

class OpS7_Robot : public XConsole	// NOTE: placeholder name (CRobot at 0xcec108)
{
public:
	OpS7_RobotManual *getManual_4b1b70();	// NOTE: placeholder name
};
extern OpS7_Robot *ops7_cec108;	// NOTE: placeholder name
extern int ops7_cebd58;	// NOTE: placeholder name
extern vector<string> ops7_d33d38;	// NOTE: placeholder name

void ops7_scrollRobot8feee0(bool up)	// NOTE: placeholder name
{
	OpS7_RobotManual *manual = ops7_cec108->getManual_4b1b70();
	if (!manual->text.empty() && manual->records.size() > 1)
	{
		if (up)
		{
			manual->index++;
			if (manual->index == manual->records.size())
				manual->index = 0;
		}
		else
		{
			manual->index--;
			if (manual->index < 0)
				manual->index = manual->records.size() - 1;
		}
	}
	else if (up)
	{
		if (ops7_cebd58 > 0)
		{
			ops7_cebd58--;
			manual->input->setText(ops7_d33d38[ops7_cebd58]);
		}
	}
	else if (ops7_cebd58 < ops7_d33d38.size())
	{
		ops7_cebd58++;
		manual->input->setText(ops7_cebd58 >= ops7_d33d38.size() ? string("") : ops7_d33d38[ops7_cebd58]);
	}
}

//==================================================================
// Array2D<int> helpers
//==================================================================

#include "../util/rng.h"
extern RNG rng;	// 0xd30908

struct Point
{
	int x;
	int y;

	Point(int x_, int y_);	// 0x46ca20
	Point(int v);	// 0x409990 (known as Push_409990::operate)
};

class Push_40a010	// NOTE: placeholder name (see src/match_push)
{
public:
	int field0;
	int field4;
	void operate(int arg0, int arg1);
};

class OpS7_IntGrid	// NOTE: placeholder name (Array2D<int>)
{
public:
	int width;
	int height;
	int *cells;

	Point find_9cefa0(int value);	// NOTE: placeholder name
	Point getRandom_9cf050();	// NOTE: placeholder name
	void getRandom_9cf0c0(Push_40a010 *out);	// NOTE: placeholder name
	void getNeighbors_9ce500(const Point &pos, vector<Point> &list);	// NOTE: placeholder name
};

Point OpS7_IntGrid::find_9cefa0(int value)
{
	for (int i = 0; i < width*height; i++)
	{
		if (cells[i] == value)
			return Point(i/height,i%height);
	}
	return Point(-1);
}

Point OpS7_IntGrid::getRandom_9cf050()
{
	return Point(rng.rangeInt(0,width-1),rng.rangeInt(0,height-1));
}

void OpS7_IntGrid::getRandom_9cf0c0(Push_40a010 *out)
{
	out->operate(rng.rangeInt(0,width-1),rng.rangeInt(0,height-1));
}

void OpS7_IntGrid::getNeighbors_9ce500(const Point &pos, vector<Point> &list)
{
	if (pos.x != 0)
		list.push_back(Point(pos.x-1,pos.y));
	if (pos.y != 0)
		list.push_back(Point(pos.x,pos.y-1));
	if (pos.x < width-1)
		list.push_back(Point(pos.x+1,pos.y));
	if (pos.y < height-1)
		list.push_back(Point(pos.x,pos.y+1));
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
	OpS7_CellGrid(int width_, int height_, XCell fill);	// 0x9cde40
	OpS7_CellGrid &operator=(const OpS7_CellGrid &other);	// 0x9cdf50
	~OpS7_CellGrid();	// 0x9cec20
	XCell *getData();	// NOTE: placeholder name (folded getter)
	int getWidth();	// 0x9fcd80
	XCell *at(int x, int y);	// 0x9cdf20
	void fill(XCell value);	// 0x9cdfd0
	void resize(int width_, int height_);	// 0x9ce020
	void resize(int width_, int height_, XCell value);	// 0x9ce110
	void copyFrom(int destX, int destY, OpS7_CellGrid &src, int srcX, int srcY, int copyWidth, int copyHeight);	// 0x9ce150
	void paste_9ec220(int x, int y, OpS7_CellGrid &src);	// NOTE: placeholder name
	void expand(XCell value, int left, int right, int top, int bottom);	// 0x9ce1e0
	void mirror();	// 0x9cf450
};

XCell *ops7_copy_9ec2b0(XCell *first, XCell *last, XCell *dest);	// NOTE: placeholder name

OpS7_CellGrid::OpS7_CellGrid(const OpS7_CellGrid &other)
{
	width = other.width;
	height = other.height;
	cells = new XCell[other.width*other.height];
	ops7_copy_9ec2b0(const_cast<OpS7_CellGrid&>(other).getData(),const_cast<OpS7_CellGrid&>(other).getData() + width*height,cells);
}

OpS7_CellGrid::OpS7_CellGrid(int width_, int height_, XCell fill_)
{
	width = width_;
	height = height_;
	cells = new XCell[width_*height_];
	fill(fill_);
}

OpS7_CellGrid &OpS7_CellGrid::operator=(const OpS7_CellGrid &other)
{
	if (width != other.width || height != other.height)
		resize(other.width,other.height);
	ops7_copy_9ec2b0(const_cast<OpS7_CellGrid&>(other).getData(),const_cast<OpS7_CellGrid&>(other).getData() + width*height,cells);
	return *this;
}

void OpS7_CellGrid::fill(XCell value)
{
	for (int i = 0; i < width*height; i++)
		cells[i] = value;
}

void OpS7_CellGrid::resize(int width_, int height_)
{
	if (width_ == width && height_ == height)
		return;
	delete [] cells;
	width = width_;
	height = height_;
	cells = new XCell[width*height];
}

void OpS7_CellGrid::resize(int width_, int height_, XCell value)
{
	resize(width_,height_);
	fill(value);
}

void OpS7_CellGrid::copyFrom(int destX, int destY, OpS7_CellGrid &src, int srcX, int srcY, int copyWidth, int copyHeight)
{
	for (int i = 0; i < copyWidth; i++)
	{
		for (int j = 0; j < copyHeight; j++)
			cells[(i+destX)*height + j+destY] = src.cells[(srcX+i)*src.height + (srcY+j)];
	}
}

void OpS7_CellGrid::expand(XCell value, int left, int right, int top, int bottom)
{
	if (left == 0 && right == 0 && top == 0 && bottom == 0)
		return;
	int oldWidth = width;
	int oldHeight = height;
	OpS7_CellGrid old(*this);
	resize(width + left + right,height + top + bottom);
	paste_9ec220(left,top,old);
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

void ops7_rotate4_9ec7b0(XCell *a, XCell *b, XCell *c, XCell *d);	// NOTE: placeholder name

void ops7_rotateGrid_9cf450(OpS7_CellGrid *grid)	// NOTE: placeholder name
{
	int size = grid->getWidth();
	for (int i = 0; i < size/2; i++)
	{
		for (int j = 0; j < (size+1)/2; j++)
			ops7_rotate4_9ec7b0(grid->at(i,j),grid->at(j,size-1-i),grid->at(size-1-i,size-1-j),grid->at(size-1-j,i));
	}
}

//==================================================================
// small Array2D / math helpers
//==================================================================

template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name

class OpS7_ByteGrid	// NOTE: placeholder name (Array2D<char>)
{
public:
	int width;
	int height;
	char *cells;

	void read_9cec80(istream &stream);	// NOTE: placeholder name
};

void OpS7_ByteGrid::read_9cec80(istream &stream)
{
	readBinary(stream,&width);
	readBinary(stream,&height);
	cells = new char[width*height];
	for (int i = 0; i < width*height; i++)
		stream.read(cells + i,1);
}

class OpS7_IntGrid2	// NOTE: placeholder name (Array2D<int>, second view)
{
public:
	int width;
	int height;
	int *cells;

	OpS7_IntGrid2(int width_, int height_, int fill);	// 0x9ced10
	OpS7_IntGrid2 &operator=(const OpS7_IntGrid2 &other);	// 0x9cedd0
	int *getData();	// NOTE: placeholder name (folded getter)
	void fill(int value);	// NOTE: placeholder name (0x9ec800)
	void resize(int width_, int height_);	// NOTE: placeholder name (0x9ec850)
	void read_9cee40(istream &stream);	// NOTE: placeholder name
	bool contains_9ceef0(int value);	// NOTE: placeholder name
	int count_9cef40(int value);	// NOTE: placeholder name
	void replace_9cf630(int from, int to);	// NOTE: placeholder name
	void fillRect_9cf6c0(const Point *a, const Point *b, int value);	// NOTE: placeholder name
};

int *ops7_copy_9fd1a0(int *first, int *last, int *dest);	// NOTE: placeholder name

OpS7_IntGrid2::OpS7_IntGrid2(int width_, int height_, int fill_)
{
	width = width_;
	height = height_;
	cells = new int[width_*height_];
	fill(fill_);
}

OpS7_IntGrid2 &OpS7_IntGrid2::operator=(const OpS7_IntGrid2 &other)
{
	if (width != other.width || height != other.height)
		resize(other.width,other.height);
	ops7_copy_9fd1a0(const_cast<OpS7_IntGrid2&>(other).getData(),const_cast<OpS7_IntGrid2&>(other).getData() + width*height,cells);
	return *this;
}

void OpS7_IntGrid2::read_9cee40(istream &stream)
{
	readBinary(stream,&width);
	readBinary(stream,&height);
	cells = new int[width*height];
	for (int i = 0; i < width*height; i++)
		stream.read((char*)(cells + i),4);
}

bool OpS7_IntGrid2::contains_9ceef0(int value)
{
	for (int i = 0; i < width*height; i++)
	{
		if (cells[i] == value)
			return true;
	}
	return false;
}

int OpS7_IntGrid2::count_9cef40(int value)
{
	int count = 0;
	for (int i = 0; i < width*height; i++)
	{
		if (cells[i] == value)
			count++;
	}
	return count;
}

void OpS7_IntGrid2::replace_9cf630(int from, int to)
{
	for (int i = 0; i < width*height; i++)
	{
		if (cells[i] == from)
			cells[i] = to;
	}
}

int ops7_indexOf_9cf120(const char *text, unsigned int length, char c)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < length; i++)
	{
		if (text[i] == c)
			return i;
	}
	return -1;
}

int ops7_indexOf_9cf560(int *values, unsigned int count, int value)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
	{
		if (values[i] == value)
			return i;
	}
	return -1;
}

bool ops7_between_9cdb90(float low, float value, float high)	// NOTE: placeholder name
{
	return low <= value && value <= high;
}

int ops7_clamp_9cdc80(int low, int value, int high)	// NOTE: placeholder name
{
	return value < low ? low : (value > high ? high : value);
}

void OpS7_IntGrid2::fillRect_9cf6c0(const Point *a, const Point *b, int value)
{
	int index, dy, x, j;
	dy = b->y - a->y;
	for (x = a->x; x <= b->x; x++)
	{
		index = x*height + a->y;
		for (j = 0; j <= dy; j++, index++)
			cells[index] = value;
	}
}

//==================================================================
// animation consoles (state at +0x60, engine at +0x64)
//==================================================================

extern unsigned int ops7_tickCount;	// NOTE: placeholder name (0xcaed20)

class OpS7_AnimConsole : public Console	// NOTE: placeholder name
{
public:
	virtual void update();
	void stop_90c690();	// NOTE: placeholder name
};

void OpS7_AnimConsole::update()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
	case 1:
		if (!engine->update())
			unknown60 = 3;
		break;
	case 3:
		engine->update();
		break;
	}
	update429e30();
}

void OpS7_AnimConsole::stop_90c690()
{
	unknown60 = 4;
	clearInterior();
	unknown429f10(0,0);
	engine->stopAll();
	deleteSubconsoles();
	*(unsigned int*)((char*)this + 0x6c) = ops7_tickCount;
	animate("A_BlockFadeVisSilent");
}
