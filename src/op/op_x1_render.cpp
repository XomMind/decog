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
	char data[0x14];
};

template <class T> class Array2D	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *data;

	void copyFrom(Array2D<T> *other);	// NOTE: placeholder name (0x9cdf50)
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
};

class XRoot : public XConsole
{
public:
	virtual ~XRoot();	// 0x4184f0

	void composite();	// NOTE: placeholder name (0x42ded0)
};

class XMouse	// NOTE: placeholder name (object at 0xcefa94)
{
public:
	void renderCursor();	// NOTE: placeholder name (0x41a940)
	void renderTrail();	// NOTE: placeholder name (0x41aa30)
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

class REX
{
public:
	void updateRoot();		// NOTE: placeholder name (0x426be0)
	void renderRoot();		// NOTE: placeholder name (0x426c00)
	void renderRootOnly();	// NOTE: placeholder name (0x426ca0)

	int presentationSuppressed;	// NOTE: placeholder name; +0x00
	char padding4[0x6c - 0x04];
	XRoot *root;				// +0x6c
	Array2D<XCell> previousFrame;	// NOTE: placeholder name; +0x70
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
