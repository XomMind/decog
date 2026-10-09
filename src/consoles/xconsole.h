#ifndef CONSOLES_XCONSOLE_H
#define CONSOLES_XCONSOLE_H

// `throw()` on a declaration stands in for LTCG's nothrow inference: the real engine bodies
//	are known not to throw, which removes EH states from the callers in the exe.
//
// Minimal declarations of the X* engine side that the game consoles build on.
// XConsole itself and the geometry/colour types are reconstructed elsewhere; nothing here
// is defined, only declared with the layout the Console classes depend on.

#include <string>
#include <vector>
#include "engine/xcolor.h"
using namespace std;

struct Pos
{
	int x;
	int y;

	Pos();
	Pos(int x_, int y_);
	Pos(const Pos &pos) throw();
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(const Pos &pos, int width_, int height_);
	Rect(const Rect &rect);
};

// one character cell of a buffer
struct Glyph	// NOTE: placeholder name
{
	int font;
	int ch;
	int unknown8;
	XColor fg;
	XColor bg;

	Glyph(int font_);
	Glyph &operator=(const Glyph &glyph);
	XColor *getBg();	// NOTE: placeholder name
};

// the libtcod-like character buffer XConsole draws into
class XBuffer	// NOTE: placeholder name
{
public:
	XBuffer(int width, int height, Glyph fill);
	int getWidth();
	int getHeight();
	Glyph *get(int x, int y);
	void copy(XBuffer *buffer);	// NOTE: placeholder name

	int data[3];
};

// layered REXPaint image
class AsciiImage
{
public:
	AsciiImage();
	~AsciiImage();
	void copy(AsciiImage *image);	// NOTE: placeholder name
	void copyRegion(AsciiImage *image, int font, Pos *offset, int width, int height);	// NOTE: placeholder name
	bool load(const string &file, int font, Pos *offset, int width, int height);

	vector<XBuffer*> layers;
};

class XConsole
{
public:
	XConsole(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~XConsole();

	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event) = 0;
	virtual void inputMouse(int x, int y);	// NOTE: placeholder name
	virtual void update() = 0;
	virtual void render() = 0;	// NOTE: placeholder name

	bool isHidden();	// NOTE: placeholder name
	int getWidth();
	int getHeight();
	Pos getPos();
	Pos getMaxCoord();	// NOTE: placeholder name
	void setPos(Pos pos);	// NOTE: placeholder name
	void setFore(XColor color);	// 0x417b00 (engine/xconsole.h inline)
	void setBack(XColor color);	// 0x417b30 (engine/xconsole.h inline)
	void removeSubconsole(XConsole *console);
	XConsole *getParent() { return parent; };
	XBuffer *getBuffer() { return &buffer; };	// NOTE: placeholder name
	void print(int x, int y, const string &text);	// NOTE: placeholder name
	void printAligned(int x, int y, int align, const string &text);	// NOTE: placeholder name
	bool isTileFont();	// NOTE: placeholder name
	void setHidden(bool hidden_) throw();	// NOTE: placeholder name
	void setForeNothrow_417f80(int x, int y, XColor color) throw();	// NOTE: placeholder alias of setFore_417f80 (0x417f80, cc_r1_07.cpp): a file-unique stub keeps the call nothrow as in the exe
	void resetBack_418450();	// NOTE: placeholder name (cc_r1_07.cpp)
	void setArtFgColor(XColor color) throw();	// NOTE: placeholder name
	void setArtBgColor(XColor color) throw();	// NOTE: placeholder name

	XConsole *parent;
	XBuffer buffer;
	int font;
	int fontData;	// NOTE: placeholder name
	Pos pos;
	Pos offset;	// NOTE: placeholder name
	XColor fgColor;
	XColor bgColor;
	int unknown34;
	int unknown38;
	float unknown3c;
	float unknown40;
	vector<XConsole*> subconsoles;
	bool hidden;
	int unknown58;
	bool unknown5c;
	bool unknown5d;
};

#endif
