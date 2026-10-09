#ifndef CONSOLES_CONSOLE_H
#define CONSOLES_CONSOLE_H

#include "xconsole.h"

// Base of every game UI window (the C* classes). Header-inline members were emitted by
// LTCG in declaration order at 0x48c060-0x48c6e0; the out-of-line ones start at 0x7ad420.

class ConsoleTitle;
class Engine;	// UI animation engine owned by each console (Engine::killGroup() @ 0x50fd90)

extern bool consoleInputBlocked;	// NOTE: placeholder name
extern int consoleFrameCount;	// NOTE: placeholder name
extern const XColor consoleDefaultColor;	// NOTE: placeholder name

void logError(string location, string message);	// NOTE: placeholder name

// deletes every element, then clears the vector
template <class T> void deleteElements(vector<T*> &v) throw();	// NOTE: placeholder name
template <class T> void deleteVector(vector<T*> &v)	// NOTE: placeholder name
{
	deleteElements(v);
	v.clear();
}

// key/command bindings (global at 0xcefa8c)
class Console;
class KeyMap	// NOTE: placeholder name
{
public:
	bool hasCommand(int command);	// NOTE: placeholder name
	void registerConsole(int command, Console *console, int unknown1, int unknown2);	// NOTE: placeholder name
};
extern KeyMap *keyMap;	// NOTE: placeholder name

class Engine
{
public:
	Engine(XConsole *console, Pos *origin, Pos *max);
	~Engine();

	void stopAll();	// NOTE: placeholder name
	void update();
	void render();	// NOTE: placeholder name
	void setMax(const Pos &max);	// NOTE: placeholder name
	void killGroup(string group);

	XConsole *console;
	int data[20];	// layout not reconstructed (0x54 bytes)
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer)
		: XConsole(parent, width, height, x, y, font, hidden, layer)
	{
		unknown60 = 0;
		title = NULL;
		engine = new Engine(this, NULL, NULL);
		setFore(consoleDefaultColor);
		setBack(consoleDefaultColor);
	};
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer)
		: XConsole(parent, rect.width, rect.height, rect.x, rect.y, font, hidden, layer)
	{
		unknown60 = 0;
		title = NULL;
		engine = new Engine(this, NULL, NULL);
		setFore(consoleDefaultColor);
		setBack(consoleDefaultColor);
	};
	virtual ~Console()
	{
		engine->stopAll();
		delete engine;		engine = NULL;
	};

	virtual void resize(int width, int height);
	virtual bool input(void *event)
	{
		if (isHidden() || consoleInputBlocked)
			return false;
		if (XConsole::input(event))
			return true;
		return false;
	};
	virtual void update()
	{
		if (isHidden())
			return;
		engine->update();
		XConsole::update();
	};
	virtual void render()
	{
		if (isHidden())
			return;
		engine->render();
		XConsole::render();
	};
	virtual void open() {};	// NOTE: placeholder name
	virtual void close() {};	// NOTE: placeholder name
	virtual int getFrame() { return consoleFrameCount; };	// NOTE: placeholder name
	virtual void trigger(const string &command, int value)
	{
		logError("Console::trigger()","Subclass method not implemented");
	};

	int getUnknown60() { return unknown60; };	// NOTE: placeholder name
	void setTitle(ConsoleTitle *title_);	// NOTE: placeholder name
	void animate(string name) { animate(name,0x30,0); };	// NOTE: placeholder name
	void animate(string name, int unknown1, int unknown2);	// NOTE: placeholder name
	Rect getRect() { return Rect(getPos(),getWidth(),getHeight()); };	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	ConsoleTitle *title;
};

#endif
