//==================================================================
// REX presentation and screen-shake boundary (Beta 17.1)
//==================================================================
// NOTE: all partial class/member names below are placeholders unless stated
// otherwise. Measured REX offsets: presentation suppression flag +0x00,
// root +0x6c, and previous-frame Array2D<XCell> +0x70.
// renderRoot always restores the cursor background, rate-limits, dispatches and
// composites; suppression skips only blitting, not snapshot/cursor/SDL_Flip.
// renderRootOnly instead suppresses that entire shorter presentation path.
// Shake expiry resets and black-fills once; stopped state keeps an unsigned
// 1000ms redraw tail. Tick addition/comparison intentionally preserves wrap behavior.
#include <stddef.h>
#include <string>
#include "engine/xcolor.h"


struct SDL_PixelFormat;
struct SDL_Surface
{
	char padding0[4];
	SDL_PixelFormat *format;	// +0x04
};

extern "C" unsigned int SDL_MapRGB(SDL_PixelFormat *format, unsigned char red, unsigned char green, unsigned char blue);
extern "C" int SDL_FillRect(SDL_Surface *surface, void *rect, unsigned int color);
extern "C" int SDL_Flip(SDL_Surface *surface);
extern "C" unsigned int SDL_GetTicks(void);
extern "C" void SDL_Delay(unsigned int milliseconds);
extern "C" void SDL_WM_SetCaption(const char *title, const char *icon);

std::string intToString(int value);

struct XCell	// NOTE: placeholder name; sizeof 0x14
{
	int font;
	int ch;
	int glyph;
	XColor fore;
	XColor back;

	XCell(int font_, int ch_, XColor fore_, XColor back_);
};

template <class T> class Array2D	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *data;

	void copyFrom(Array2D<T> *other);	// NOTE: placeholder name (0x9cdf50)
	void resize(int width_, int height_, T fill);
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool isActive();
	virtual void refresh();
	virtual bool input(void *event);
	virtual void mouseMoved(int x, int y);
	virtual void update();
	virtual void render();

	class XConsole *parent;
	Array2D<XCell> buffer;

	void blit(SDL_Surface *surface, Array2D<XCell> *previousBuffer);	// 0x42a5b0
	void clear();
};

class XRoot : public XConsole
{
public:
	XRoot(int width, int height, bool flag);
	virtual ~XRoot();	// 0x4184f0
	char pad14[0x84 - 0x14];

	void composite();	// NOTE: placeholder name (0x42ded0)
};

class XMouse	// NOTE: placeholder name (object at 0xcefa94)
{
public:
	void renderCursor();	// NOTE: placeholder name (0x41a940)
	void renderTrail();	// NOTE: placeholder name (0x41aa30)
	void setPosition(int x_, int y_);	// NOTE: placeholder name (0x41a850)
	XMouse();	// 0x431e30
	~XMouse();
	char pad[0x34];
	bool isCursorHidden_41a6e0();	// NOTE: placeholder name (folded getter)
	void setCursorHidden(bool hidden);	// 0x432170, NOTE: placeholder name
	void setCell(int x, int y);	// NOTE: placeholder name
};

class FrameLimiter	// NOTE: placeholder name (object at 0xcefaa0)
{
public:
	void limitFrame();	// NOTE: placeholder name (0x41af30)

	int frameCounter;				// NOTE: placeholder name; +0x00
	int lastFPS;					// NOTE: placeholder name; +0x04
	unsigned int nextSample;		// NOTE: placeholder name; +0x08
	int frameCap;					// NOTE: placeholder name; +0x0c; zero disables limiting
	char padding10[4];				// +0x10 remains unknown
	unsigned int lastFrameTick;	// NOTE: placeholder name; +0x14
	unsigned int minFrameInterval;	// NOTE: placeholder name; +0x18
	bool showFPS;					// NOTE: placeholder name; +0x1c
};

// Sample deadlines use the original unsigned absolute comparison, including
// rollover behavior. Four independent tick reads preserve sample and cap timing.
// The caption prefix is the literal at 0xc18b2c; the named string survives c_str()
// and SDL_WM_SetCaption, while the intToString temporary dies after concatenation.
void FrameLimiter::limitFrame()
{
	frameCounter++;
	if (SDL_GetTicks() >= nextSample)
	{
		lastFPS = frameCounter;
		frameCounter = 0;
		nextSample = SDL_GetTicks() + 1000;
		if (showFPS)
		{
			std::string caption = "FPS: " + intToString(lastFPS);
			SDL_WM_SetCaption(caption.c_str(),NULL);
		}
	}
	if (frameCap)
	{
		unsigned int now = SDL_GetTicks();
		if (now - lastFrameTick < minFrameInterval)
			SDL_Delay(minFrameInterval - (now - lastFrameTick));
		lastFrameTick = SDL_GetTicks();
	}
}

extern XMouse *mouse;			// NOTE: placeholder name (0xcefa94)
extern FrameLimiter *frameLimiter;	// NOTE: placeholder name (0xcefaa0)
extern SDL_Surface *screenSurface;	// NOTE: placeholder name (0xcefa80)
extern XColor &COLOR_BLACK;	// 0xcfe674, NOTE: placeholder name

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();	// 0x40a6e0
	Rect &operator=(const Rect &rect);	// 0x40a720
};

class REX
{
public:
	void updateRoot();		// NOTE: placeholder name (0x426be0)
	void renderRoot();		// NOTE: placeholder name (0x426c00)
	void renderRootOnly();	// NOTE: placeholder name (0x426ca0)

	void run();	// NOTE: placeholder name (0x426cf0, "Starting REX loop")
	void toggleMode_4262c0(int x, int y, int width, int height, std::string font);	// NOTE: placeholder name
	XConsole *getRoot_4ab670();	// NOTE: placeholder name (folded getter)
	Rect getWindowRect();	// NOTE: placeholder name
	void moveWindow(int x, int y);	// NOTE: placeholder name
	void unknown423f40(int value, bool flag);	// NOTE: placeholder name
	void unknown424020(const std::string &font, bool flag);	// NOTE: placeholder name

	int presentationSuppressed;	// NOTE: placeholder name; +0x00
	int windowed;	// NOTE: placeholder name; +0x04
	char padding8[0x14 - 0x08];
	int x;	// NOTE: placeholder name; +0x14
	int y;	// NOTE: placeholder name; +0x18
	char padding1c[0x64 - 0x1c];
	int width;	// NOTE: placeholder name; +0x64
	int height;	// NOTE: placeholder name; +0x68
	XRoot *root;				// +0x6c
	Array2D<XCell> previousFrame;	// NOTE: placeholder name; +0x70
	char padding7c[0xcc - 0x7c];
	int fontIndex;	// NOTE: placeholder name; +0xcc
	char paddingd0[0x120 - 0xd0];
	XRoot *savedRoot;	// NOTE: placeholder name; +0x120
	int savedWidth;	// NOTE: placeholder name; +0x124
	int savedHeight;	// NOTE: placeholder name; +0x128
	int savedFont;	// NOTE: placeholder name; +0x12c
	int savedX;	// NOTE: placeholder name; +0x130
	int savedY;	// NOTE: placeholder name; +0x134
	bool savedCursorHidden;	// NOTE: placeholder name; +0x138
	char padding139[0x140 - 0x139];
	void (*activeCallback)(int state, unsigned char gain);	// NOTE: placeholder name; +0x140
	char padding144[0x14c - 0x144];
	bool (*quitCallback)();	// NOTE: placeholder name; +0x14c
};

void REX::updateRoot()
{
	root->update();
}

void REX::renderRoot()
{
	mouse->renderTrail();
	frameLimiter->limitFrame();
	root->render();
	root->composite();
	if (!presentationSuppressed)
		root->blit(screenSurface,&previousFrame);
	previousFrame.copyFrom(&root->buffer);
	mouse->renderCursor();
	SDL_Flip(screenSurface);
}

struct SDL_Event	// NOTE: SDL 1.2 event union (0x14 bytes)
{
	unsigned char type;
	unsigned char gain;		// active.gain
	unsigned char state;	// active.state
	unsigned char pad3;
	unsigned short x;		// motion.x
	unsigned short y;		// motion.y
	int pad8[3];
};
extern "C" int SDL_PollEvent(SDL_Event *event);
extern "C" void exit(int status);
void logMessage(std::string message);	// NOTE: placeholder name (0x404cb0)

struct XTimer	// NOTE: placeholder name (object at 0xcefa9c)
{
	int unknown00;	// NOTE: placeholder name
	unsigned int next;	// NOTE: placeholder name
	unsigned int accumulated;	// NOTE: placeholder name
	unsigned int last;	// NOTE: placeholder name
};
extern XTimer *timer_cefa9c;	// NOTE: placeholder name
extern int frameTime_cefa78;	// NOTE: placeholder name
extern unsigned int tickCount_caed20;	// NOTE: placeholder name

class XInput	// NOTE: placeholder name (object at 0xcefa8c)
{
public:
	void handleEvent_427320(unsigned char type, SDL_Event event);	// NOTE: placeholder name
};
extern XInput *input_cefa8c;	// NOTE: placeholder name

class AudioMixer	// NOTE: placeholder name (0xcefa90)
{
public:
	void clearFinished();	// NOTE: placeholder name (0x4194d0)
};
extern AudioMixer *audioMixer_cefa90;	// NOTE: placeholder name

void REX::run()
{
	logMessage("Starting REX loop");
	while (true)
	{
		unsigned int now = SDL_GetTicks();
		if (now - timer_cefa9c->last > 140)
			timer_cefa9c->accumulated += 140;
		else
			timer_cefa9c->accumulated += now - timer_cefa9c->last;
		while (timer_cefa9c->accumulated >= timer_cefa9c->next)
		{
			frameTime_cefa78 = 14;
			tickCount_caed20 = timer_cefa9c->next;
			updateRoot();
			timer_cefa9c->next += 14;
		}
		timer_cefa9c->last = SDL_GetTicks();
		renderRoot();
		audioMixer_cefa90->clearFinished();
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case 4:
					mouse->setPosition(event.x,event.y);
					break;
				case 2:
				case 3:
				case 5:
				case 6:
					input_cefa8c->handleEvent_427320(event.type,event);
					break;
				case 1:
					if (activeCallback != NULL)
					{
						int state = 2;
						if (event.state == 1)
							state = 0;
						else if (event.state == 2)
							state = 1;
						activeCallback(state,event.gain);
					}
					break;
				case 12:
					if (quitCallback != NULL && quitCallback())
						break;
					exit(0);
			}
		}
	}
	exit(0);
}

void REX::renderRootOnly()
{
	if (!presentationSuppressed)
	{
		root->blit(screenSurface,&previousFrame);
		previousFrame.copyFrom(&root->buffer);
		SDL_Flip(screenSurface);
	}
}

class XScreenShake	// NOTE: placeholder name
{
public:
	void reset();	// 0x4185e0; defined in src/game/cc_r1_07.cpp
	bool boundary(bool *output);	// NOTE: placeholder name (0x42e550)

	unsigned int endTime;	// NOTE: placeholder name; +0x00
	bool stopped;			// NOTE: placeholder name; +0x04
	char padding5[0x08 - 0x05];
	int offsetX;			// NOTE: placeholder name; +0x08
	int offsetY;			// NOTE: placeholder name; +0x0c
	unsigned int lastTime;	// NOTE: placeholder name; +0x10
};

extern unsigned int tickCount;		// NOTE: placeholder name (0xcaed20)

bool XScreenShake::boundary(bool *output)
{
	*output = tickCount < endTime;
	bool result;
	result = (!*output && (*output || stopped)) ? 0 : 1;
	if (!*output && !stopped)
	{
		reset();
		SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,0,0,0));
	}
	else
	{
		if (tickCount < lastTime + 1000)
			result = true;
	}
	return result;
}

extern REX rex;	// NOTE: placeholder name (0xd223f0)
extern bool deletingRoot_cefa76;	// NOTE: placeholder name
int OpY1_round(float value);	// NOTE: placeholder name (0x406360)

// swaps between the normal root console and a temporary one of another size and font
void REX::toggleMode_4262c0(int x_, int y_, int width_, int height_, std::string font)
{
	root->clear();
	root->blit(screenSurface,NULL);
	if (savedRoot != NULL)
	{
		XConsole *current = rex.getRoot_4ab670();
		deletingRoot_cefa76 = true;
		delete current;
		deletingRoot_cefa76 = false;
		current = NULL;
		mouse->renderTrail();
		delete mouse;
		mouse = new XMouse();
		root = savedRoot;
		savedRoot = NULL;
		x = savedX;
		y = savedY;
		width = savedWidth;
		height = savedHeight;
		Rect rect;
		if (windowed == 0)
			rect = getWindowRect();
		unknown423f40(savedFont,true);
		if (windowed == 0)
		{
			Rect area = getWindowRect();
			rect.x -= (area.width - rect.width) / 2;
			rect.y -= (area.height - rect.height) / 2;
			moveWindow(rect.x,rect.y);
		}
		previousFrame.resize(width,height,XCell(0,0,COLOR_BLACK,COLOR_BLACK));
		mouse->setCursorHidden(savedCursorHidden);
		mouse->setCell(width / 2,height / 2);
	}
	else
	{
		savedRoot = (XRoot *)rex.getRoot_4ab670();
		savedX = x;
		savedY = y;
		savedWidth = width;
		savedHeight = height;
		savedFont = fontIndex;
		savedCursorHidden = mouse->isCursorHidden_41a6e0();
		mouse->renderTrail();
		delete mouse;
		mouse = new XMouse();
		x = x_;
		y = y_;
		width = width_;
		height = height_;
		XRoot *console = new XRoot(width,height,true);
		root = console;
		Rect rect;
		if (windowed == 0)
			rect = getWindowRect();
		unknown424020(font,true);
		if (windowed == 0)
		{
			Rect area = getWindowRect();
			rect.x -= OpY1_round((area.width - rect.width) / 2.0);
			rect.y -= OpY1_round((area.height - rect.height) / 2.0);
			moveWindow(rect.x,rect.y);
		}
		previousFrame.resize(width,height,XCell(0,0,COLOR_BLACK,COLOR_BLACK));
		mouse->setCursorHidden(savedCursorHidden);
		mouse->setCell(width / 2,height / 2);
	}
}
