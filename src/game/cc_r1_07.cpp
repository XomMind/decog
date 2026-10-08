// XConsole header-inline drawing helpers, XRoot's inline destructor and the engine's screen
//	shake, laid out by LTCG at 0x417f50-0x418683 (Beta 17.1).
// XConsole/XCell/Array2D are reconstructed in engine/xconsole.h, whose header-inline bodies
//	are already emitted by harness/engine_use.cpp: defining the same names here out of line
//	would clash at link time (LNK2005), so the members matched here that duplicate a name
//	from that header carry the exe address instead (setChar -> setChar_417f50, ...).
// print()/printAligned()/mouseEnter() use the names consoles/xconsole.h declares for them.
// `throw()` on a declaration stands in for LTCG's nothrow inference (as in consoles/xconsole.h).
// NOTE: class layouts are partial; names are placeholders unless stated otherwise.
#include <string>
#include <ctype.h>
#include <vector>
#include "engine/xcolor.h"
#include "util/rng.h"
using namespace std;

extern RNG rng;	// NOTE: placeholder name (0xd30908)
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)

struct Pos
{
	int x;
	int y;
};

// 2D array, column-major (template instances at 0x9b4370-0x9d2930)
template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	int	width;
	int	height;
	T	*data;

	~Array2D();
	int getWidth();
	int getHeight();
	T *get(int x, int y);
	bool inBounds(int x, int y);	// NOTE: placeholder name
	void deleteContents_9ce5d0() throw();	// NOTE: placeholder name (deletes every element, then the array)
};

// folded by ICF with other trivial getters (0x9fcd80, 0x9b8f00)
template <class T>
int Array2D<T>::getWidth()
{
	return width;
}

template <class T>
int Array2D<T>::getHeight()
{
	return height;
}

// one character cell of a console buffer
struct XCell	// NOTE: placeholder name
{
	int font;
	int ch;
	int glyph;
	XColor fore;
	XColor back;

	XCell &operator=(const XCell &cell);
	void setChar(int ch_);
	void setChar(int ch_, XColor fore_);
	void set(int ch_, XColor fore_, XColor back_, int flag);
	void setBack(XColor back_, int flag);
};

extern XColor &COLOR_DEFAULT_BACK;	// 0xd20cfc, NOTE: placeholder name

//==================================================================
// XConsole
//==================================================================

class XConsole
{
public:
	virtual ~XConsole();

	virtual void resize(int width, int height);
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event) = 0;
	virtual void inputMouse(int x, int y);	// NOTE: placeholder name
	virtual void update() = 0;
	virtual void render() = 0;	// NOTE: placeholder name

	// header-inline, in declaration order (NOTE: placeholder names)
	void setChar_417f50(int x, int y, int ch);
	void setFore_417f80(int x, int y, XColor color);
	void setBack_417fc0(int x, int y, XColor color, int flag);
	void setString_418010(int x, int y, string text);
	void putChar_4180b0(int x, int y, int ch);
	void putChar_418110(int x, int y, int ch, XColor fore_);
	void putChar_418150(int x, int y, int ch, XColor fore_, XColor back_, int flag);
	void putCell_4181a0(int x, int y, const XCell &cell);
	void print(int x, int y, const string &text);
	void printAligned(int x, int y, int align, const string &text);
	int printWrapped_418260(int x, int y, int width, int height, const string &text);
	int printWrapped_4182b0(int x, int y, int width, int height, int align, const string &text);
	int countLines_418300(int x, int y, int width, int height, const string &text);
	int countLines_418350(int x, int y, int width, int height, int align, const string &text);
	void setCharRow_4183a0(int x, int y, int width);
	void setForeAll_4183d0(XColor color);
	void setBackAll_418410(XColor color);
	void resetBack_418450();
	void setPassThrough_418480(bool passThrough_);
	void setIgnoreMouse_4184a0(bool ignoreMouse_);
	Array2D<XCell> *getBuffer_4184d0();

	// returns the number of lines; wrap breaks at width, countOnly draws nothing
	int print_428fb0(string text, int x, int y, int width, int height, int align, bool wrap, bool countOnly);	// NOTE: placeholder name
	void setCharRow(int x, int y, int width, int ch);
	void setFore(int x, int y, int width, int height, XColor color);
	void setBack(int x, int y, int width, int height, XColor color);

	XConsole *parent;			// +0x04
	Array2D<XCell> buffer;		// +0x08
	int font;					// +0x14
	int fontType;				// +0x18
	Pos pos;					// +0x1c
	Pos absPos;					// +0x24
	XColor fore;				// +0x2c
	XColor back;				// +0x2f
	int backFlag;				// +0x34	default background blend flag
	int alignment;				// +0x38	default print alignment
	float scaleX;				// +0x3c
	float scaleY;				// +0x40
	vector<XConsole*> subconsoles;	// +0x44
	bool hidden;				// +0x54
	int layer;					// +0x58
	bool passThrough;			// +0x5c
	bool ignoreMouse;			// +0x5d
};

void XConsole::setChar_417f50(int x, int y, int ch)
{
	buffer.get(x,y)->setChar(ch);
}

void XConsole::setFore_417f80(int x, int y, XColor color)
{
	buffer.get(x,y)->fore = color;
}

void XConsole::setBack_417fc0(int x, int y, XColor color, int flag)
{
	buffer.get(x,y)->setBack(color,flag == 12 ? backFlag : flag);
}

void XConsole::setString_418010(int x, int y, string text)
{
	for (unsigned int i = 0; i < text.size(); i++)
		setChar_417f50(x + i,y,text[i]);
}

void XConsole::putChar_4180b0(int x, int y, int ch)
{
	buffer.get(x,y)->set(ch,fore,back,backFlag);
}

void XConsole::putChar_418110(int x, int y, int ch, XColor fore_)
{
	buffer.get(x,y)->setChar(ch,fore_);
}

void XConsole::putChar_418150(int x, int y, int ch, XColor fore_, XColor back_, int flag)
{
	buffer.get(x,y)->set(ch,fore_,back_,flag);
}

void XConsole::putCell_4181a0(int x, int y, const XCell &cell)
{
	*buffer.get(x,y) = cell;
}

int OpR1b_countVisible(string &text, int pos, int end);	// NOTE: placeholder name (0x4092e0)
int OpR1b_advanceVisible(string &text, int pos, int count);	// NOTE: placeholder name
int OpX5_minInt(int a, int b);	// 0x9cdb30
int OpX5_maxInt(int a, int b);	// 0x9cdb60
int stringToInt(const string &str);	// NOTE: placeholder name (0x405610)
extern vector<XColor> cc07_colors_d2b4bc;	// NOTE: placeholder name (` colour codes)

// prints text with `fN` / `bN` / `x colour codes, optionally wrapped at spaces; returns the number of lines
int XConsole::print_428fb0(string text, int x, int y, int width, int height, int align, bool wrap, bool countOnly)
{
	int pos = 0;
	int sx = 0;
	int cy = y;
	XColor old = fore;
	XColor tmp = back;
	int tag = backFlag;
	if (x >= buffer.getWidth() || y >= buffer.getHeight())
		return 0;
	if (height == 0)
		height = buffer.getHeight() - y;
	if (width == 0)
	{
		switch (align)
		{
			case 0: width = buffer.getWidth() - x; break;
			case 2: width = x + 1; break;
			case 1: width = buffer.getWidth(); break;
		}
	}
	int ty = y;
	int ey = buffer.getHeight() - 1;
	if (height > 0)
		ey = OpX5_minInt(ey,y + height - 1);
	int left;
	int u;
	switch (align)
	{
		case 0:
			left = OpX5_maxInt(0,x);
			u = OpX5_minInt(buffer.getWidth() - 1,x + width - 1);
			break;
		case 2:
			left = OpX5_maxInt(0,x - width + 1);
			u = OpX5_minInt(buffer.getWidth() - 1,x);
			break;
		case 1:
			left = OpX5_maxInt(0,x - width / 2);
			u = OpX5_minInt(buffer.getWidth() - 1,x + width / 2);
			break;
	}
	do
	{
		int end = text.find('\n',pos);
		char first = 0;
		int part = -1;
		int range = OpR1b_countVisible(text,pos,end == string::npos ? text.size() : end);
		switch (align)
		{
			case 0: sx = x; break;
			case 2: sx = x - range + 1; break;
			case 1: sx = x - range / 2; break;
		}
		if (cy >= ty && cy <= ey && sx <= u && sx + range - 1 >= left)
		{
			if (wrap && cy < ey)
			{
				if (sx < left)
					part = OpR1b_advanceVisible(text,pos,align == 1 ? range - (left - sx) * 2 : range - (left - sx));
				else if (align == 1)
				{
					if (range / 2 + sx > u + 1)
						part = OpR1b_advanceVisible(text,pos,u + 1 - sx);
				}
				else if (sx + range > u + 1)
					part = OpR1b_advanceVisible(text,pos,u + 1 - sx);
			}
			if (part != -1)
			{
				int orig = part;
				while (!isspace(text[part]) && part > pos)
					part--;
				if (end != string::npos)
					text[end] = '\n';
				if (!isspace(text[part]))
					part = orig;
				end = part;
				first = text[part];
				part = 0;
				range = OpR1b_countVisible(text,pos,end);
				switch (align)
				{
					case 0: sx = x; break;
					case 2: sx = x - range + 1; break;
					case 1: sx = x - range / 2; break;
				}
			}
			if (sx < left)
			{
				pos += left - sx;
				range -= left - sx;
				sx = left;
			}
			if (sx + range > u + 1)
			{
				part = OpR1b_advanceVisible(text,pos,u + 1 - sx);
				part = -1;
			}
			if (cy >= 0 && cy < buffer.getHeight())
			while (pos < text.size() && pos != end)
			{
				if (text[pos] == '`')
				{
					pos++;
					if (text[pos] == 'x')
					{
						fore = old;
						back = tmp;
						backFlag = tag;
						pos++;
					}
					else
					{
						bool isFore = text[pos] == 'f';
						pos++;
						string code;
						while (text[pos] != '`')
						{
							code += text[pos];
							pos++;
						}
						if (isFore)
							fore = cc07_colors_d2b4bc[stringToInt(code)];
						else
						{
							back = cc07_colors_d2b4bc[stringToInt(code)];
							backFlag = 1;
						}
					}
				}
				else if (!countOnly)
				{
					if (buffer.inBounds(sx,cy))
						putChar_4180b0(sx,cy,text[pos]);
					sx++;
				}
				pos++;
			}
		}
		if (end != -1)
		{
			if (part != -1 && !isspace(first))
			{
				text[end] = first;
				pos = end;
			}
			else
				pos = end + 1;
			cy++;
		}
		else
			pos = string::npos;
	} while (pos != string::npos && cy < buffer.getHeight() && (height == 0 || cy < y + height));
	return cy - y + 1;
}

void XConsole::print(int x, int y, const string &text)
{
	print_428fb0(text,x,y,0,0,alignment,false,false);
}

void XConsole::printAligned(int x, int y, int align, const string &text)
{
	print_428fb0(text,x,y,0,0,align,false,false);
}

int XConsole::printWrapped_418260(int x, int y, int width, int height, const string &text)
{
	return print_428fb0(text,x,y,width,height,alignment,true,false);
}

int XConsole::printWrapped_4182b0(int x, int y, int width, int height, int align, const string &text)
{
	return print_428fb0(text,x,y,width,height,align,true,false);
}

int XConsole::countLines_418300(int x, int y, int width, int height, const string &text)
{
	return print_428fb0(text,x,y,width,height,alignment,true,true);
}

int XConsole::countLines_418350(int x, int y, int width, int height, int align, const string &text)
{
	return print_428fb0(text,x,y,width,height,align,true,true);
}

void XConsole::setCharRow_4183a0(int x, int y, int width)
{
	setCharRow(x,y,width,' ');
}

void XConsole::setForeAll_4183d0(XColor color)
{
	setFore(0,0,buffer.getWidth(),buffer.getHeight(),color);
}

void XConsole::setBackAll_418410(XColor color)
{
	setBack(0,0,buffer.getWidth(),buffer.getHeight(),color);
}

void XConsole::resetBack_418450()
{
	setBackAll_418410(COLOR_DEFAULT_BACK);
}

void XConsole::setPassThrough_418480(bool passThrough_)
{
	passThrough = passThrough_;
}

void XConsole::setIgnoreMouse_4184a0(bool ignoreMouse_)
{
	ignoreMouse = ignoreMouse_;
}

bool XConsole::mouseEnter()
{
	return true;
}

Array2D<XCell> *XConsole::getBuffer_4184d0()
{
	return &buffer;
}

//==================================================================
// XRoot (vtable @ 0xc2eeb0)
//==================================================================

class XRoot : public XConsole
{
public:
	virtual ~XRoot();

	virtual bool input(void *event);
	virtual void update();
	virtual void render();

	Array2D<XCell*> *getLastFrame_418570();	// NOTE: placeholder name

	int frameCount;						// +0x60
	Array2D<XCell*> lastFrame;			// +0x64	NOTE: placeholder name
	vector<vector<XConsole*> > layers;	// +0x70
	bool unknown80;						// +0x80
};

XRoot::~XRoot()
{
	lastFrame.deleteContents_9ce5d0();
}

Array2D<XCell*> *XRoot::getLastFrame_418570()
{
	return &lastFrame;
}

//==================================================================
// screen shake applied when blitting the root (global at 0xd16188, updated at 0x42e550)
//==================================================================

class XScreenShake	// NOTE: placeholder name
{
public:
	XScreenShake();
	void reset();	// NOTE: placeholder name
	void start(int duration);	// NOTE: placeholder name

	unsigned int endTime;	// NOTE: placeholder name
	bool stopped;			// NOTE: placeholder name
	int offsetX;			// NOTE: placeholder name
	int offsetY;			// NOTE: placeholder name
	unsigned int lastTime;	// NOTE: placeholder name
};

XScreenShake::XScreenShake()
{
	reset();
}

void XScreenShake::reset()
{
	endTime = 0;
	stopped = true;
	lastTime = tickCount;
}

void XScreenShake::start(int duration)
{
	endTime = tickCount + duration;
	stopped = false;
	do
	{
		offsetX = rng.rangeInt(-1,1);
		offsetY = rng.rangeInt(-1,1);
	} while (offsetX == 0 && offsetY == 0);
}
