#pragma once
// op_v3d: shared declarations for the op_v3d slice (0x78b8a0-0x7d6db0), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos();
	Pos(int x_, int y_);	// 0x46ca20
	Pos(int v);	// 0x409990
	Pos(const Pos &pos) throw();	// 0x46ca50
	Pos &operator=(const Pos &pos);
	Pos operator+(const Pos &pos) const;	// 0x409b60
};

struct Point
{
	int x;
	int y;

	Point &operator=(const Point &p);	// 0x46ca50
	Point(const Point &p);	// 0x46ca50
	Point(int v);	// 0x409990
	Point();
	Point(int x_, int y_);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(unsigned char value);
	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
	bool operator==(XColor color);
	bool operator!=(XColor color);
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();
	Rect(int x_, int y_, int width_, int height_);
	Rect(const Rect &rect);
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(const XEvent &event);	// 0x944370
	XEvent(int type_);	// 0x415c60

	int type;
	Point pos;
};

class ConsoleTitle;

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(XEvent *event);
	virtual void inputMouse(int x, int y);
	virtual void update();
	virtual void render();

	bool isHidden();
	Rect getRect();
	Point getPos();
	void setPos(const Pos &pos);
	int getWidth();	// 0x44b0d0
	int getHeight();
	void print(int x, int y, const string &text);
	void printAligned(int x, int y, int align, const string &text);
	void setCharRow(int x, int y, int width, int ch);
	string getFirstLine();
	void clear(int x, int y, int width, int height);
	void clearInterior();
	void setFore(XColor color);
	void setBack(XColor color);
	void setHidden(bool hidden_);
	void putChar_4180b0(int x, int y, int ch);	// NOTE: placeholder name
	void setPassThrough_418480(bool passThrough_);	// NOTE: placeholder name
	int printWrapped_418260(int x, int y, int width, int height, const string &text);	// NOTE: placeholder name
	void deleteSubconsoles();
	void clear();
	void putChar_418150(int x, int y, int ch, XColor fore, XColor back, bool flag);	// NOTE: placeholder name
	void setForeAll_4183d0(XColor color);	// NOTE: placeholder name
	void setScaleX_417b60(float value);	// NOTE: placeholder name
	void setScaleY_417b80(float value);	// NOTE: placeholder name
	float getScaleX();
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	void setBack_417fc0(int x, int y, XColor color, int mode);	// NOTE: placeholder name
	void setUnknown_451400(int value);	// NOTE: placeholder name (folded setter)
	void unknown429ea0();	// NOTE: placeholder name
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)
	void removeSubconsole(XConsole *console);
	XConsole *getParent4();	// NOTE: placeholder name (folded +4 getter)
	void setPos(int x, int y);
	void setBackAll_418410(XColor color);	// NOTE: placeholder name
	void resetBack_418450() throw();	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class OpQ4d_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class OpQ4d_Engine	// NOTE: placeholder name
{
public:
	OpQ4d_EngineItem *unknown50fb50(OpQ4d_Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
	void killGroup(string group);
	void update();	// NOTE: placeholder name (0x50fff0)
	void render();	// NOTE: placeholder name (0x5100b0)
	void stopAll();	// NOTE: placeholder name
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void render();
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);
	int getState_48c360();	// NOTE: placeholder name (folded getter of unknown60)
	void setFrameFore(XColor color);	// NOTE: placeholder name (0x7b0a20)
	void replaceSpecialChars(int ch);	// NOTE: placeholder name (0x7b0a60)
	void animate(string name, int a, int b);
	void drawFrame(Rect *area, XColor color, bool thin, bool lines);	// NOTE: placeholder name
	void setTitle(ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void unknown48c460(int anim, const Pos &pos);	// NOTE: placeholder name

	int unknown60;
	OpQ4d_Engine *engine;
	void *title;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);

	char pad6c[0x8c - 0x6c];
};

class HItem
{
public:
	int ID;
	HItem();
	bool isValid() const;
};

class Entity
{
public:
	int getAiType();	// NOTE: placeholder name (0x45a2a0)
	int getFaction();	// NOTE: placeholder name (0x45a2c0)
	Pos &getPosition();	// NOTE: placeholder name
	int getSize();	// NOTE: placeholder name
	Point unknown45a4c0();	// NOTE: placeholder name
};

class HEntity : public HItem	// NOTE: placeholder layout
{
public:
	HEntity();
	Entity *operator->() const throw();	// 0x9b6570
};

extern string opr5f_factionNames[];	// NOTE: placeholder name (0xd2f798)

class JLog
{
public:
	int end(int type);	// NOTE: placeholder name
};
extern JLog *jlog;	// NOTE: placeholder name (0xcefa64)

void logMessage(string message);	// NOTE: placeholder name
void logInfo(string message);	// NOTE: placeholder name
void logInfo(string location, string message);	// NOTE: placeholder name
void logFatal(string location, string message);	// NOTE: placeholder name
