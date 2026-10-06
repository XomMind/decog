// Notification / parse / trailer / rexpaint / difficulty / title consoles (CNotification, CParse,
// CTrailer, CRexpaint, CDifficultyButton, CDifficulty, CTitle, CTitleAnimated) around 0x4b22b0-0x4b2a13.
// NOTE: class layouts are partial; padding members, member names and method names are placeholders.

// engine/xcolor.h with a nothrow copy constructor (LTCG inferred it; removes EH states after base construction)
#define XCOLOR_H
#include <string>
#include <iostream>
#include "util/stringutil.h"

//==================================================================
// XColor
//==================================================================
// 3-byte RGB color (no alpha), reconstructed from 0x411d40-0x413960.
// The blend/compositing set mirrors libtcod's TCODColor and TCOD_bkgnd_flag_t
//	(see XConsole's cell background blending at 0x428120).
// Method names are placeholders unless stated otherwise; XColor::set() is
//	attested by its error strings, but that overload was stripped from the exe.

// NOTE: placeholder names; int helpers live with the math utilities (0x9cdb30-0x9cdc80)
int minInt(int a, int b);
int maxInt(int a, int b);
int clampInt(int min, int value, int max);

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();
	XColor(unsigned char value);
	XColor(int r_, int g_, int b_);
	XColor(float h, float s, float v);
	XColor(const std::string &hex);
	XColor(const XColor &color) throw();

	void read(std::istream &stream);	// NOTE: placeholder name
	void write(std::ostream &stream);	// NOTE: placeholder name

	XColor &operator=(XColor color);
	bool operator==(XColor color);
	bool operator!=(XColor color);
	XColor operator+(XColor color);
	XColor operator*(float value);
	XColor &operator*=(float value);
	bool nonzero();	// NOTE: placeholder name
	std::string toString()	// NOTE: placeholder name
	{
		return std::string() + "(" + intToString(r) + "," + intToString(g) + "," + intToString(b) + ")";
	};

	void set(unsigned char r_, unsigned char g_, unsigned char b_);
	void set(const XColor &color);
	void setHSV(float h, float s, float v);	// NOTE: placeholder name

	// blending (cases of the console background flag)
	void add(XColor color);	// NOTE: placeholder names from here on
	void subtract(XColor color);
	void multiply(XColor color);
	void scale(float value);
	void lerp(XColor color, float coef);
	void addAlpha(XColor color, float alpha);
	void screen(XColor color);
	void colorDodge(XColor color);
	void colorBurn(XColor color);
	void burn(XColor color);
	void overlay(XColor color);

	void grayscale();
	void desaturate(float amount);
	void shiftHue(int degrees);
	void cycle(int amount);
	void invert();
	void getHSV(float *h, float *s, float *v);

	static XColor add(XColor c1, XColor c2);
	static XColor subtract(XColor c1, XColor c2);
	static XColor multiply(XColor c1, XColor c2);
	static XColor scale(XColor c1, float value);
	static XColor lerp(XColor c1, XColor c2, float coef);
	static XColor addAlpha(XColor c1, XColor c2, float alpha);
	static XColor subtractAlpha(XColor c1, XColor c2, float alpha);
	static XColor screen(XColor c1, XColor c2);
	static XColor colorDodge(XColor c1, XColor c2);
	static XColor colorBurn(XColor c1, XColor c2);
	static XColor burn(XColor c1, XColor c2);
	static XColor overlay(XColor c1, XColor c2);
	static XColor shiftHue(XColor c1, int degrees);
	static XColor grayscale(XColor c1);
};



// consoles/xconsole.h with a few extra declarations (Pos(int), Rect(x,y,w,h), printWrapped)
// that the shared header lacks; pre-defining its include guard makes console.h pick this one up.
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
	Pos(int v);	// 0x409990
	Pos(const Pos &pos);
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(int x_, int y_, int width_, int height_);	// 0x456940
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
	void setFgColor(XColor color);	// NOTE: placeholder name
	void setBgColor(XColor color);	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);
	XConsole *getParent() { return parent; };
	XBuffer *getBuffer() { return &buffer; };	// NOTE: placeholder name
	void print(int x, int y, const string &text);	// NOTE: placeholder name
	void printAligned(int x, int y, int align, const string &text);	// NOTE: placeholder name
	int printWrapped_418260(int x, int y, int width, int height, const string &text);	// NOTE: placeholder name
	int printWrapped_4182b0(int x, int y, int width, int height, int align, const string &text);	// NOTE: placeholder name
	void clear() throw();	// NOTE: placeholder name
	bool isTileFont();	// NOTE: placeholder name
	void setHidden(bool hidden_) throw();	// NOTE: placeholder name
	void setFgColor(int x, int y, XColor color) throw();	// NOTE: placeholder name
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


#include "consoles/console.h"
#include "consoles/consoleui.h"

int centerOffset(int inner, int outer) throw();	// NOTE: placeholder name (0x437190)
int unknown405b40(unsigned char c);	// NOTE: placeholder name
extern int unknown_bcdb6c[];	// NOTE: placeholder name
extern string unknown_d03260[];	// NOTE: placeholder name
extern int unknown_d31658;	// NOTE: placeholder name
extern int unknown_d3165c;	// NOTE: placeholder name

//==================================================================
// CNotification
//==================================================================

class CNotification : public Console
{
public:
	CNotification(XConsole *parent, int x, int y, const string &text, int width);	// 0x4b22b0
	virtual ~CNotification();	// 0x4b2550

	CCloseButton *closeButton;	// NOTE: placeholder name
};
extern CNotification *unknown_cec110;	// NOTE: placeholder name

CNotification::CNotification(XConsole *parent, int x, int y, const string &text, int width)
	: Console(parent,Rect(x,y,width,1),0,false,10)
{
	unknown_cec110 = this;

	setTitle(new ConsoleTitle(this,"\\ N O T I F I C A T I O N \\",0,2));

	Console *first = new Console(this,50,10,0,0,0,false,-1);
	int lines = first->printWrapped_418260(0,0,50,10,text);
	removeSubconsole(first);
	resize(width,lines + 4);
	animate("A_4_Border");

	Console *second = new Console(this,50,lines,unknown_d31658,unknown_d3165c,0,false,-1);
	second->printWrapped_4182b0(0,0,50,lines,0,text);
	second->animate("A_BlockAppear_Text");

	keyMap->registerConsole(0xf,this,0x101,0);
	closeButton = new CCloseButton(this,*listCloseColor,0xf);
	closeButton->setHidden(false);
};

CNotification::~CNotification()
{
	unknown_cec110 = NULL;
};

//==================================================================
// CParse
//==================================================================

class CParse : public Console
{
public:
	virtual ~CParse();	// 0x4b25b0

	char pad6c[0x70 - sizeof(Console)];
	vector<int> unknown70;	// NOTE: placeholder name
};
extern CParse *unknown_cec114;	// NOTE: placeholder name

CParse::~CParse()
{
	unknown_cec114 = NULL;
};

//==================================================================
// CTrailer / CRexpaint
//==================================================================

class CTrailer : public Console
{
public:
	virtual ~CTrailer();	// 0x4b2650
};

CTrailer::~CTrailer()
{
};

class CRexpaint : public Console
{
public:
	virtual ~CRexpaint();	// 0x4b26a0
};

CRexpaint::~CRexpaint()
{
};

//==================================================================
// CDifficultyButton
//==================================================================

class CDifficultyButton : public Console
{
public:
	CDifficultyButton(XConsole *parent, int x, int y, const string &text);	// 0x4b26f0
};

CDifficultyButton::CDifficultyButton(XConsole *parent, int x, int y, const string &text)
	: Console(parent,text.size(),1,x,y,0,false,-1)
{
	if (getWidth() == 1)
	{
		int index = unknown405b40(text[0]);
		resize(0x6a,unknown_bcdb6c[index] - 4);
		printWrapped_418260(0,0,getWidth(),getHeight(),unknown_d03260[index]);
	}
	else
		print(0,0,text);
};

//==================================================================
// CDifficulty
//==================================================================

struct DifficultyOption	// NOTE: placeholder name
{
	char pad[0x78];
	XConsole *unknown78;	// NOTE: placeholder name

	bool unknown4b27f0();	// NOTE: placeholder name
};

bool DifficultyOption::unknown4b27f0()
{
	return unknown78;
};

class CDifficulty : public Console
{
public:
	virtual ~CDifficulty();	// 0x4b2810

	vector<int> unknown6c;	// NOTE: placeholder name
};

CDifficulty::~CDifficulty()
{
};

//==================================================================
// CTitle / CTitleAnimated
//==================================================================

class CTitle : public Console
{
public:
	virtual ~CTitle();	// 0x4b28a0
	virtual void trigger(const string &command, int value);

	XConsole *ascii;	// NOTE: placeholder name
	bool finished;	// NOTE: placeholder name
};

CTitle::~CTitle()
{
};

class CTitleAnimated : public ConsoleArt
{
public:
	CTitleAnimated(XConsole *parent, AsciiImage *art, int unknown84_, int frame);	// 0x4b28f0
	void unknown4b29b0();	// NOTE: placeholder name

	int unknown84;	// NOTE: placeholder name
};

CTitleAnimated::CTitleAnimated(XConsole *parent, AsciiImage *art, int unknown84_, int frame)
	: ConsoleArt(parent,art,centerOffset(art->layers.front()->getWidth(),parent->getWidth()),centerOffset(art->layers.front()->getHeight(),parent->getHeight()),false,-1,frame,Pos(-1),0,0)
{
	unknown84 = unknown84_;
	setArtFgColor(consoleDefaultColor);
	clear();
};

void CTitleAnimated::unknown4b29b0()
{
	drawArt(unknown84);
};

