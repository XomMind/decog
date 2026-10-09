#ifndef XCONSOLE_H
#define XCONSOLE_H

//==================================================================
// XConsole: Kyzrati's "X" engine console (REX engine)
//==================================================================
// Reconstructed from Beta 17.1. RTTI: XConsole vtable @ 0xc2ee8c (8 slots),
//	subclasses XRoot @ 0xc2eeb0, XStartupProgress @ 0xc2eed4, and the game's Console.
// Header-inline members were laid out by LTCG in declaration order at 0x416ca0-0x4184a0
//	(XColorFilter, XCell, XConsole); out-of-line code is at 0x427e80-0x42a5b0.
// Unless stated otherwise every name in here is a placeholder: the exe only attests
//	XConsole::removeSubconsole(), XConsole::blit() and REX::consoleAdd/RemoveFromLayer().
//
// XConsole layout (sizeof 0x60):
//	+0x00	vftable
//	+0x04	XConsole *parent
//	+0x08	Array2D<XCell> buffer		(width, height, data; column-major)
//	+0x14	int font					font set index
//	+0x18	int fontType				0 normal, 1 wide (2x1), 2 quad (2x2), 3 oct (4x2)
//	+0x1c	Pos pos						position in parent cells
//	+0x24	Pos absPos					absolute position in root cells
//	+0x2c	XColor fore					default foreground
//	+0x2f	XColor back					default background
//	+0x34	int backFlag				default background blend flag (XCell::setBack)
//	+0x38	int alignment				default print alignment
//	+0x3c	float scaleX
//	+0x40	float scaleY
//	+0x44	vector<XConsole*> subconsoles
//	+0x54	bool hidden
//	+0x58	int layer					-1 for the root
//	+0x5c	bool passThrough			mouse lookups resolve to the parent
//	+0x5d	bool ignoreMouse
//
// vtable:	0 scalar deleting dtor, 1 resize(w,h), 2 bool isActive() {true},
//	3 void refresh() {}, 4 bool input(XEvent*) = 0 (has a body), 5 void mouseMoved(int,int) {},
//	6 void update() = 0 (has a body), 7 void render() = 0 (has a body)

#include <string>
#include <vector>
#include <iostream>
#include "engine/xcolor.h"
using namespace std;

//==================================================================
// declarations owned by other parts of the program
//==================================================================

// geometry (0x46ca20 etc.)
struct Pos
{
	int x;
	int y;

	Pos();						// (-1,-1)
	Pos(int x_, int y_);
	Pos(const Pos &pos) throw();
	Pos &operator=(const Pos &pos);
	Pos &operator+=(const Pos &pos);
	Pos &operator-=(const Pos &pos);
	void set(int x_);			// 0x409ff0, NOTE: placeholder
	void translate(int dx, int dy);	// 0x40a2a0, NOTE: placeholder
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(int x_, int y_, int width_, int height_) throw();	// 0x456940 (defined in team_a_repair.cpp)
};

// 2D array, column-major: data[x * height + y] (template instances at 0x9b4370-0x9d2930)
template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	int	width;
	int	height;
	T	*data;

	Array2D();
	~Array2D();
	int getWidth();
	int getHeight();
	int getMaxX();
	int getMaxY();
	T *get(int x, int y) throw();	// nothrow in the exe; no definition is linked yet
	T *get(const Pos &p) throw();
	void resize(int width_, int height_, T fill);
	void fill(T value);
};

bool isBetween(int min, int value, int max);	// 0x9daf80, NOTE: placeholder name
template <class T> void deleteVectorContents(vector<T*> &v);	// 0x9ce9e0, NOTE: placeholder name
template <class T> void deleteVector(vector<T*> &v);	// 0x9cead0, NOTE: placeholder name
template <class T> void deleteVectorElement(vector<T*> &v, int &i);	// 0x9d4f60, NOTE: placeholder name
template <class T> void moveVectorElement(vector<T> *v, int from, int to);	// 0x9e2ce0, NOTE: placeholder name
template <class T> void readBinary(istream &stream, T *value);	// 0x9d8480, NOTE: placeholder name

// colour references (dynamic-initialised pointers into the colour table)
extern XColor &COLOR_BLACK;		// 0xcfe674, NOTE: placeholder name
extern XColor &COLOR_WHITE;		// 0xcfabbc, NOTE: placeholder name
extern XColor &COLOR_DEFAULT_BACK;	// 0xd20cfc, NOTE: placeholder name

// per font set: character code -> glyph index
extern vector<vector<int>*> fontCharmaps;	// 0xd20ae8, NOTE: placeholder name

class XConsole;

//==================================================================
// colour filters applied to whole cells (global list at 0xd1d45c)
//==================================================================

enum colorFilterType	// NOTE: placeholder names
{
	COLOR_FILTER_NONE,
	COLOR_FILTER_SCALE,
	COLOR_FILTER_DESATURATE,
	COLOR_FILTER_COLORIZE,
	COLOR_FILTER_SWAP,
	COLOR_FILTER_SHIFT_HUE,
	COLOR_FILTER_CYCLE,
	COLOR_FILTER_INVERT,
};

struct XColorFilter	// NOTE: placeholder name
{
	int type;
	int amount;
	float value;
	XColor color;

	XColorFilter()
		: type		(0)
		, amount	(0)
		, value		(0)
		, color		(COLOR_BLACK)
	{};
	XColorFilter(const XColorFilter &filter)
		: type		(filter.type)
		, amount	(filter.amount)
		, value		(filter.value)
		, color		(filter.color)
	{};
};

extern vector<XColorFilter> colorFilters;	// NOTE: placeholder name

//==================================================================
// one character cell of a console buffer
//==================================================================

struct XCell	// NOTE: placeholder name
{
	int font;
	int ch;
	int glyph;
	XColor fore;
	XColor back;

	XCell();
	XCell(int font_);
	XCell(int font_, int ch_, XColor fore_, XColor back_);

	void set(const XCell &cell)
	{
		font = cell.font;
		ch = cell.ch;
		glyph = cell.glyph;
		fore = cell.fore;
		back = cell.back;
	};
	XCell(const XCell &cell)
		: font	(cell.font)
		, ch	(cell.ch)
		, glyph	(cell.glyph)
		, fore	(cell.fore)
		, back	(cell.back)
	{};
	void read(istream &stream)
	{
		readBinary(stream,&ch);
		fore.read(stream);
		back.read(stream);
	};
	XCell &operator=(const XCell &cell)
	{
		font = cell.font;
		ch = cell.ch;
		glyph = cell.glyph;
		fore = cell.fore;
		back = cell.back;
		return *this;
	};
	bool operator!=(const XCell &cell)
	{
		return ch != cell.ch || glyph != cell.glyph || fore != cell.fore || back != cell.back || font != cell.font;
	};
	XColor *getFore() { return &fore; };
	XColor *getBack() { return &back; };
	void scale(float value)
	{
		fore *= value;
		back *= value;
	};
	void desaturate(float value)
	{
		fore.desaturate(1.0f - value);
		back.desaturate(1.0f - value);
	};
	void colorize(XColor *color)
	{
		if (back == COLOR_BLACK)
			back = *color;
		if (fore != back && fore != COLOR_BLACK)
		{
			fore.r = (unsigned char)(fore.r * 0.7176 + 59.0);
			fore.g = (unsigned char)(fore.g * 0.7176 + 59.0);
			fore.b = (unsigned char)(fore.b * 0.7176 + 59.0);
		}
	};
	void swapColors()
	{
		XColor temp(back);
		back = fore;
		fore = temp;
	};
	void shiftHue(int degrees)
	{
		fore.shiftHue(degrees);
		back.shiftHue(degrees);
	};
	void cycle(int amount)
	{
		fore.cycle(amount);
		back.cycle(amount);
	};
	void invert()
	{
		fore.invert();
		back.invert();
	};
	void applyFilters()
	{
		for (unsigned int i = 0; i < colorFilters.size(); i++)
		{
			switch (colorFilters[i].type)
			{
				case COLOR_FILTER_SCALE:		scale(colorFilters[i].value); break;
				case COLOR_FILTER_DESATURATE:	desaturate(colorFilters[i].value); break;
				case COLOR_FILTER_COLORIZE:		colorize(&colorFilters[i].color); break;
				case COLOR_FILTER_SWAP:			swapColors(); break;
				case COLOR_FILTER_SHIFT_HUE:	shiftHue(colorFilters[i].amount); break;
				case COLOR_FILTER_CYCLE:		cycle(colorFilters[i].amount); break;
				case COLOR_FILTER_INVERT:		invert(); break;
			}
		}
	};

	int getChar() { return ch; };	// folded with Array2D::getHeight (0x9b8f00)
	void setChar(int ch_);
	void setChar(int ch_, XColor fore_);
	void set(int ch_, XColor fore_, XColor back_, int flag);
	void setBack(XColor back_, int flag);
};

//==================================================================
// engine-side singletons XConsole talks to
//==================================================================

class XRoot;

class REX
{
public:
	char data0[0x6c];
	XRoot *root;		// +0x6c
	char data70[0x9c - 0x70];
	struct FontSetInfo	// NOTE: placeholder name (0x40 bytes)
	{
		int type;
		char data[0x3c];
	};
	vector<FontSetInfo> fontSets;	// +0x9c

	XRoot *getRoot() { return root; };
	void consoleAddToLayer(XConsole *console, int layer);
	void consoleRemoveFromLayer(XConsole *console);
};

extern REX rex;	// 0xd223f0

class XMouse	// NOTE: placeholder name (0xcefa94)
{
public:
	void forgetConsole(XConsole *console);	// 0x41a820, NOTE: placeholder name
};
extern XMouse *mouse;	// NOTE: placeholder name

class XModal	// NOTE: placeholder name (0xcefa8c)
{
public:
	XConsole *getConsole();	// 0x4189a0, NOTE: placeholder name
};
extern XModal *modal;	// NOTE: placeholder name

extern bool rexShuttingDown;	// 0xcefa76, NOTE: placeholder name

extern const int FONT_TYPE_WIDTH[];	// 0xb8cf18 {1,2,2,4}, NOTE: placeholder name
extern const int FONT_TYPE_HEIGHT[];	// 0xb8cf28 {1,1,2,2}, NOTE: placeholder name

struct XEvent	// NOTE: placeholder name
{
	int type;
	Pos mouse;	// x == MOUSE_NONE for non-mouse events
};

const int MOUSE_NONE = -10000;	// NOTE: placeholder name

//==================================================================
// XConsole
//==================================================================

class XConsole
{
public:
	XConsole(XConsole *parent_, int width, int height, int x, int y, int font_, bool hidden_, int layer_);
	virtual ~XConsole();

	virtual void resize(int width, int height);
	virtual bool isActive() { return true; };
	virtual void refresh() {};
	virtual bool input(XEvent *event) = 0;
	virtual void mouseMoved(int x, int y) {};
	virtual void update() = 0;
	virtual void render() = 0;

	bool inBounds(int x, int y)
	{
		return isBetween(0,x,buffer.getMaxX()) && isBetween(0,y,buffer.getMaxY());
	};
	bool inBounds(const Pos &p)
	{
		return isBetween(0,p.x,buffer.getMaxX()) && isBetween(0,p.y,buffer.getMaxY());
	};
	bool contains(const Pos &p)
	{
		return inBounds(absToLocal(p));
	};
	Pos getPos() { return pos; };
	Pos getAbsPos() { return absPos; };
	int getHeight() { return buffer.getHeight(); };
	Pos getMaxCoord() { return Pos(buffer.getWidth() - 1,buffer.getHeight() - 1); };
	bool isWide() { return fontType == 1; };
	float getScaleX() { return scaleX; };
	bool isUnscaled() { return scaleX == 1 && scaleY == 1; };
	bool hasSubconsoles() { return !subconsoles.empty(); };
	vector<XConsole*> *getSubconsoles() { return &subconsoles; };
	bool isHidden() { return hidden; };
	bool isVisible()
	{
		if (hidden)
			return false;
		if (parent == NULL)
			return true;
		if (!parent->isVisible())
			return false;
		return true;
	};
	int getChar(int x, int y) { return buffer.get(x,y)->ch; };
	XColor getFore(int x, int y) { return buffer.get(x,y)->fore; };
	XColor getBack(int x, int y) { return buffer.get(x,y)->back; };
	XCell *getCell(int x, int y) { return buffer.get(x,y); };
	int getChar(const Pos &p) { return buffer.get(p)->ch; };
	XColor getFore(const Pos &p) { return buffer.get(p)->fore; };
	XColor getBack(const Pos &p) { return buffer.get(p)->back; };
	XCell *getCell(const Pos &p) { return buffer.get(p); };
	string getString(const Pos &p, unsigned int length)
	{
		string text;
		for (int x = p.x; text.size() < length && x < buffer.getWidth(); x++)
			text += (char)buffer.get(x,p.y)->ch;
		return text;
	};
	string getFirstLine()
	{
		string text;
		for (int x = 0; x < buffer.getWidth(); x++)
			text += (char)buffer.get(x,0)->ch;
		return text;
	};
	string getStringVertical(const Pos &p, unsigned int length)
	{
		string text;
		for (int y = p.y; text.size() < length && y < buffer.getHeight(); y++)
			text += (char)buffer.get(p.x,y)->ch;
		return text;
	};
	int getLastCharX(int y)
	{
		for (int x = buffer.getWidth() - 1; x >= 0; x--)
		{
			if (buffer.get(x,y)->getChar() != ' ')
				return x;
		}
		return -1;
	};
	void setPos(int x, int y) { setPos(Pos(x,y)); };
	void move(int dx, int dy) { setPos(Pos(pos.x + dx,pos.y + dy)); };
	void setFore(XColor color) { fore = color; };
	void setBack(XColor color) { back = color; };
	void setScaleX(float scale) { scaleX = scale; };
	void setScaleY(float scale) { scaleY = scale; };
	void setHidden(bool hidden_) { hidden = hidden_; };
	void clear() { buffer.fill(XCell(font)); };
	void clear(int x, int y, int width, int height)
	{
		for (int i = y; i < y + height; i++)
			clearRow(x,i,width);
	};
	void clear(const Rect &rect) { clear(rect.x,rect.y,rect.width,rect.height); };
	void clearInterior() { clear(1,1,buffer.getWidth() - 2,buffer.getHeight() - 2); };
	void clear(XConsole *console) { clear(console->pos.x,console->pos.y,console->buffer.getWidth(),console->buffer.getHeight()); };
	void clearBack()
	{
		for (int x = 0; x < buffer.getWidth(); x++)
		{
			for (int y = 0; y < buffer.getHeight(); y++)
				buffer.get(x,y)->back = COLOR_BLACK;
		}
	};
	void clearChars()
	{
		for (int y = 0; y < buffer.getHeight(); y++)
			setCharRow_4183a0(0,y,buffer.getWidth());
	};
	void setCharRow_4183a0(int x, int y, int width);	// NOTE: placeholder name (0x4183a0 = setCharRow(x,y,width), cc_r1_07.cpp)
	void deleteSubconsolesExcept(XConsole *console)
	{
		for (int i = 0; i < (int)subconsoles.size(); i++)
		{
			if (subconsoles[i] != console)
				deleteVectorElement(subconsoles,i);
		}
	};
	void deleteSubconsolesExcept(XConsole *console1, XConsole *console2)
	{
		for (int i = 0; i < subconsoles.size(); i++)
		{
			if (subconsoles[i] != console1 && subconsoles[i] != console2)
				deleteVectorElement(subconsoles,i);
		}
	};
	int getSubconsoleIndex(XConsole *console)
	{
		for (unsigned int i = 0; i < subconsoles.size(); i++)
		{
			if (subconsoles[i] == console)
				return i;
		}
		return -1;
	};
	void moveSubconsole(XConsole *console, int index)
	{
		int oldIndex = getSubconsoleIndex(console);
		moveVectorElement(&subconsoles,oldIndex,index);
	};
	void setChar(int x, int y, int ch) { buffer.get(x,y)->setChar(ch); };
	void setFore(int x, int y, XColor color) { buffer.get(x,y)->fore = color; };
	void setBack(int x, int y, XColor color, int flag)
	{
		buffer.get(x,y)->setBack(color,flag == 12 ? backFlag : flag);
	};
	void setString(int x, int y, string text)
	{
		for (unsigned int i = 0; i < text.size(); i++)
			setChar(x + i,y,text[i]);
	};
	void putChar(int x, int y, int ch) { buffer.get(x,y)->set(ch,fore,back,backFlag); };
	void putChar(int x, int y, int ch, XColor fore_) { buffer.get(x,y)->setChar(ch,fore_); };
	void putChar(int x, int y, int ch, XColor fore_, XColor back_, int flag) { buffer.get(x,y)->set(ch,fore_,back_,flag); };
	void putCell(int x, int y, const XCell &cell) { *buffer.get(x,y) = cell; };

	void setCharRow(int x, int y, int width) { setCharRow(x,y,width,' '); };
	void setForeAll(XColor color) { setFore(0,0,buffer.getWidth(),buffer.getHeight(),color); };
	void setBackAll(XColor color) { setBack(0,0,buffer.getWidth(),buffer.getHeight(),color); };
	void resetBack() { setBackAll(COLOR_DEFAULT_BACK); };
	void setPassThrough(bool passThrough_) { passThrough = passThrough_; };
	void setIgnoreMouse(bool ignoreMouse_) { ignoreMouse = ignoreMouse_; };

	int getWidth() { return buffer.getWidth(); };	// emitted elsewhere (0x44b0d0)

	void setCharRow(int x, int y, int width, int ch);
	void setCharRow(int x, int y, int width, int ch, XColor fore_);
	void setCharRow(int x, int y, int width, int ch, XColor fore_, XColor back_);
	void setCharColumn(int x, int y, int height, int ch);
	void setCharColumn(int x, int y, int height, int ch, XColor fore_);
	void setChars(int x, int y, int width, int height, int ch);
	void setForeRow(int x, int y, int width, XColor color);
	void setForeColumn(int x, int y, int height, XColor color);
	void setFore(int x, int y, int width, int height, XColor color);
	void setForeFrame(int x, int y, int width, int height, XColor color);
	void setBackRow(int x, int y, int width, XColor color);
	void setBack(int x, int y, int width, int height, XColor color);
	void clearRow(int x, int y, int width);

	XConsole *getParent() { return parent; };
	void setPos(const Pos &p);
	Pos absToLocal(Pos p);
	Pos localToAbs(Pos p);
	Rect getRect();
	bool getVisibleArea(int *x, int *y, int *offsetX, int *offsetY);
	XConsole *getConsoleAt(const Pos &p);
	void removeSubconsole(XConsole *console);
	void deleteSubconsoles();
	int countVisible();	// 0x42d3b0

	XConsole *parent;
	Array2D<XCell> buffer;
	int font;
	int fontType;
	Pos pos;
	Pos absPos;
	XColor fore;
	XColor back;
	int backFlag;
	int alignment;
	float scaleX;
	float scaleY;
	vector<XConsole*> subconsoles;
	bool hidden;
	int layer;
	bool passThrough;
	bool ignoreMouse;
};

#endif // XCONSOLE_H
