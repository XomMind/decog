// op_x1_mouse: SDL mouse coordinates and cursor-surface blitting.
// NOTE: XMouse and its member names are placeholders (object at 0xcefa94).
// Measured XMouse offsets: mapped coordinates +0x00/+0x04; SDL mouse x/y
// +0x10/+0x14; cursor-hidden flag +0x18; cursor SDL_Surface* +0x1c;
// background SDL_Surface* +0x20; background SDL_Rect +0x24; redraw tick
// +0x2c; hovered XConsole* +0x30. SDL_Rect follows SDL 1.2 ABI: signed
// 16-bit x/y and unsigned 16-bit w/h. SDL_GetMouseState writes 32-bit ints
// and returns Uint8.
// Position updates call updateHoveredConsole() at 0x4321d0, not REX redraw.
// Hover lookup passes the mapped x/y as an 8-byte Pos by const reference.
// XConsole vtable slots 2/3 are isActive/refresh: leaving refreshes then
// clears the old pointer; entering assigns only after isActive accepts.
// Cursor draw/restore use positive hidden/surface guards; the draw path also
// requires SDL mouse focus and advances its unsigned redraw deadline by 5000ms.
#include <stddef.h>


typedef unsigned char Uint8;
typedef unsigned short Uint16;
typedef unsigned int Uint32;

struct SDL_Rect
{
	short x;
	short y;
	Uint16 w;
	Uint16 h;
};

struct SDL_PixelFormat;
struct SDL_BlitMap;
struct private_hwdata;
struct SDL_Surface
{
	Uint32 flags;
	SDL_PixelFormat *format;
	int w;
	int h;
	Uint16 pitch;
	void *pixels;
	int offset;
	private_hwdata *hwdata;
	SDL_Rect clip_rect;
	Uint32 unused1;
	Uint32 locked;
	SDL_BlitMap *map;
	unsigned int format_version;
	int refcount;
};
struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);
};

struct XConsole
{
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool isActive();
	virtual void refresh();
	virtual bool input(void *event) = 0;
	virtual void mouseMoved(int x, int y);
	virtual void update() = 0;
	virtual void render() = 0;

	XConsole *getConsoleAt(const Pos &position);
};
class XRoot;
class REX
{
public:
	char data0[0x6c];
	XRoot *root;
	int unknown418a00(int x);
	int unknown418a30(int y);
	void unknown426b90();
	XRoot *getRoot() { return root; }
};
extern REX rex; // 0xd223f0
class XRoot : public XConsole
{
public:
	virtual ~XRoot(); // Existing destructor (0x4184f0).
};

class XModal
{
public:
	XConsole *getConsole();
};
extern XModal *modal;

extern "C" Uint8 SDL_GetAppState(void);
extern "C" Uint8 SDL_GetMouseState(int *x, int *y);
extern "C" int SDL_UpperBlit(SDL_Surface *src, SDL_Rect *srcRect, SDL_Surface *dst, SDL_Rect *dstRect);

extern unsigned int tickCount; // NOTE: placeholder name (0xcaed20)
extern SDL_Surface *screenSurface; // NOTE: placeholder name (0xcefa80)

class XMouse // NOTE: placeholder layout (object at 0xcefa94)
{
public:
	int x;
	int y;
	char padding08[0x10 - 0x08];
	int mouseX;
	int mouseY;
	unsigned char cursorHidden;
	char padding19[0x1c - 0x19];
	SDL_Surface *cursorSurface;
	SDL_Surface *backgroundSurface;
	SDL_Rect backgroundRect;
	unsigned int nextRedrawTick;
	XConsole *hoveredConsole;

	void setPosition(int x_, int y_); // NOTE: placeholder name (0x41a850)
	void updatePosition(); // NOTE: placeholder name (0x41a8b0)
	void renderCursor(); // NOTE: placeholder name (0x41a940)
	void saveCursorBackground(); // NOTE: placeholder name (0x41a9e0)
	void renderTrail(); // NOTE: placeholder name (0x41aa30)
	void updateHoveredConsole(); // NOTE: placeholder name (0x4321d0)
};
extern XMouse *mouse; // 0xcefa94

void XMouse::setPosition(int x_, int y_)
{
	mouseX = x_;
	mouseY = y_;
	x = rex.unknown418a00(mouseX);
	y = rex.unknown418a30(mouseY);
	updateHoveredConsole();
}

void XMouse::updatePosition()
{
	SDL_GetMouseState(&mouseX, &mouseY);
	x = rex.unknown418a00(mouseX);
	y = rex.unknown418a30(mouseY);
	updateHoveredConsole();
}

void XMouse::renderCursor()
{
	if (!cursorHidden && cursorSurface)
	{
		if (!(SDL_GetAppState() & 1))
			return;

		saveCursorBackground();
		SDL_Rect destination;
		destination.x = (short)mouseX;
		destination.y = (short)mouseY;
		SDL_UpperBlit(cursorSurface, NULL, screenSurface, &destination);
		if (tickCount >= nextRedrawTick)
		{
			rex.unknown426b90();
			nextRedrawTick = tickCount + 0x1388;
		}
	}
}

void XMouse::saveCursorBackground()
{
	backgroundRect.x = (short)mouseX;
	backgroundRect.y = (short)mouseY;
	SDL_UpperBlit(screenSurface, &backgroundRect, backgroundSurface, NULL);
}

void XMouse::renderTrail()
{
	if (!cursorHidden && cursorSurface)
		SDL_UpperBlit(backgroundSurface, NULL, screenSurface, &backgroundRect);
}

void XMouse::updateHoveredConsole()
{
	XConsole *console = modal->getConsole() ?
		modal->getConsole()->getConsoleAt(Pos(x,y)) :
		rex.getRoot()->getConsoleAt(Pos(x,y));

	if (console != hoveredConsole)
	{
		if (hoveredConsole != NULL)
		{
			hoveredConsole->refresh();
			hoveredConsole = NULL;
		}
		if (console != NULL && console->isActive())
			hoveredConsole = console;
	}
}
