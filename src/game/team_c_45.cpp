// team_c_45: Rogue Engine X startup (0x4225f0, "REX_Init()"): stores the launch settings on the REX object (0xd223f0),
//	starts logging and SDL, loads the window icon, creates the engine singletons and the root console
// NOTE: class/member names are placeholders (f<offset>); singleton classes are declared here by their mapped names
#include <string>
#include <vector>
#include "../engine/xcolor.h"
using namespace std;

void logInfo(string message);
void logMessage(string message);
void logError(string location, string message);
void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)
void installCrashHandler_421920();	// NOTE: placeholder name
void hookSdlWindow_401110();	// NOTE: placeholder name

struct SDL_PixelFormat;
struct SDL_Surface { unsigned int flags; SDL_PixelFormat *format; int w; int h; };
struct SDL_VideoInfo { unsigned int flags; unsigned int video_mem; SDL_PixelFormat *vfmt; int current_w; int current_h; };
extern "C" __declspec(dllimport) int __stdcall ImmDisableIME(unsigned long thread);
extern "C" __declspec(dllimport) int SDL_putenv(const char *variable);
extern "C" __declspec(dllimport) int SDL_Init(unsigned int flags);
extern "C" __declspec(dllimport) char *SDL_GetError();
extern "C" __declspec(dllimport) const SDL_VideoInfo *SDL_GetVideoInfo();
extern "C" __declspec(dllimport) SDL_Surface *IMG_Load(const char *file);
extern "C" __declspec(dllimport) unsigned int SDL_MapRGB(const SDL_PixelFormat *format, unsigned char r, unsigned char g, unsigned char b);
extern "C" __declspec(dllimport) int SDL_SetColorKey(SDL_Surface *surface, unsigned int flag, unsigned int key);
extern "C" __declspec(dllimport) void SDL_WM_SetIcon(SDL_Surface *icon, unsigned char *mask);
extern "C" __declspec(dllimport) int SDL_EnableKeyRepeat(int delay, int interval);
extern "C" __declspec(dllimport) unsigned char *SDL_GetKeyState(int *numkeys);

class XResourceMgr { public: XResourceMgr(int argc, char **argv, string a, string b); int data; };
class Input_416060 { public: Input_416060(); char data[0xa0]; };
class OpR1a_AudioMixer { public: OpR1a_AudioMixer(); char data[0x54]; };
class C45_Mouse { public: C45_Mouse(); char data[0x34]; };	// NOTE: placeholder (0x431e30, object at 0xcefa94)
class OpR1a_SystemClipboard { public: OpR1a_SystemClipboard(); };
class OpQ1_FrameTimer { public: OpQ1_FrameTimer(); char data[0x20]; };
class Timer_4168b0 { public: Timer_4168b0(); char data[0x10]; };
class XRoot { public: XRoot(int width, int height, bool flag); char data[0x84]; };
struct C45_Cell { int font; int ch; int glyph; XColor fore; XColor back; C45_Cell(); C45_Cell(const C45_Cell &o) throw(); };	// NOTE: placeholder (XCell)
struct C45_CellGrid { int w; int h; C45_Cell *cells; void resize(int width, int height, C45_Cell fill); };	// NOTE: placeholder (OpS7_CellGrid)
struct C45_JLog { void end(int level); };

extern bool c45_cefa76;	// NOTE: placeholder names below
extern int c45_ced168;
extern XResourceMgr *c45_cefa88;
extern Input_416060 *c45_cefa8c;
extern OpR1a_AudioMixer *c45_cefa90;
extern unsigned char *c45_cefa84;
extern C45_Mouse *c45_cefa94;
extern OpR1a_SystemClipboard *c45_cefa98;
extern OpQ1_FrameTimer *c45_cefaa0;
extern Timer_4168b0 *c45_cefa9c;
extern XColor *c45_cfe674;
extern C45_JLog *c45_cefa64;

class C45_Rex	// NOTE: placeholder layout (REX)
{
public:
	int f0;
	int f4;
	bool f8;
	int fc;
	int f10;
	int f14;
	int f18;
	int f1c;
	int f20;
	char pad24[0x5c - 0x24];
	int f5c;
	int f60;
	int f64;
	int f68;
	XRoot *f6c;
	C45_CellGrid f70;
	string f7c;
	XColor f98;
	char pad9b[0xcc - 0x9b];
	int fcc;
	int fd0;
	int fd4;
	int fd8;
	int fdc;
	char pade0[0xfc - 0xe0];
	int ffc;
	char pad100[0x11c - 0x100];
	int f11c;
	int f120;
	char pad124[0x139 - 0x124];
	bool f139;
	int f13c;
	int f140;
	int f144;
	int f148;
	int f14c;
	char pad150[0x188 - 0x150];
	int f188;

	void initJLog(int a, int b, int c, int d);
	void loadFonts(int type, void *list);
	void setVideoMode();
	void init_4225f0(int argc, char **argv, int width, int height, int x, int y, string title, int fontType, void *fontList, bool noLog, bool useIcon, XColor *iconKey, int f4_, bool f8_, void (*layout)(int *, int *, int *, int *), string resA, string resB, int fd8_, XColor color);
};

void C45_Rex::init_4225f0(int argc, char **argv, int width, int height, int x, int y, string title, int fontType, void *fontList, bool noLog, bool useIcon, XColor *iconKey, int f4_, bool f8_, void (*layout)(int *, int *, int *, int *), string resA, string resB, int fd8_, XColor color)
{
	f0 = 0;
	f4 = f4_;
	f8 = f8_;
	fc = 960;
	f10 = 720;
	f14 = 0;
	f18 = 0;
	f1c = 0;
	f20 = 0;
	f64 = width;
	f68 = height;
	f5c = x;
	f60 = y;
	f7c = title;
	f98 = color;
	fcc = -1;
	fd0 = 0;
	fd8 = fd8_;
	fdc = 0;
	ffc = -1;
	f11c = -1;
	f120 = 0;
	f139 = false;
	f13c = 0;
	f140 = 0;
	f144 = 0;
	f148 = 0;
	f14c = 0;
	c45_cefa76 = false;
	f188 = 0;
	c45_ced168 = 0;
	installCrashHandler_421920();
	if (!noLog)
		initJLog(0,0,0,0);
	logInfo("Initializing Rogue Engine X");
	ImmDisableIME(-1);
	SDL_putenv("SDL_VIDEO_CENTERED=center");
	logMessage("Starting SDL");
	if (SDL_Init(0x21) < 0)
		logFatal("REX_Init()","SDL_Init() failed: " + string(SDL_GetError()));
	hookSdlWindow_401110();
	const SDL_VideoInfo *v0a0 = SDL_GetVideoInfo();
	f1c = v0a0->current_w;
	f20 = v0a0->current_h;
	if (layout != 0)
	{
		int col = 0;
		int adj = 0;
		int behaviour = 0;
		int allies = 0;
		layout(&col,&adj,&behaviour,&allies);
		f64 = col;
		f68 = adj;
		f5c = behaviour;
		f60 = allies;
	}
	logMessage("Importing icon");
	if (useIcon)
	{
		SDL_Surface *v0b4 = IMG_Load("rex/icon.png");
		if (v0b4 == 0)
			logError("REX_Init()","Application icon \"" + string("rex/icon.png") + "\" not found, this program may not be installed correctly!");
		else
		{
			if (v0b4->w != 32 || v0b4->h != 32)
				logFatal("REX_Init()","Application icon " + string("rex/icon.png") + " must be 32x32");
			if (*iconKey != *c45_cfe674)
				SDL_SetColorKey(v0b4,0x1000,SDL_MapRGB(v0b4->format,iconKey->r,iconKey->g,iconKey->b));
			SDL_WM_SetIcon(v0b4,0);
		}
	}
	logMessage("Confirmed resource initialization");
	if (c45_cefa88 == 0)
		c45_cefa88 = new XResourceMgr(argc,argv,resA,resB);
	loadFonts(fontType,fontList);
	setVideoMode();
	SDL_EnableKeyRepeat(500,30);
	c45_cefa8c = new Input_416060;
	logMessage("Initializing audio");
	c45_cefa90 = new OpR1a_AudioMixer;
	c45_cefa84 = SDL_GetKeyState(0);
	c45_cefa94 = new C45_Mouse;
	c45_cefa98 = new OpR1a_SystemClipboard;
	c45_cefaa0 = new OpQ1_FrameTimer;
	c45_cefa9c = new Timer_4168b0;
	logMessage("Creating console");
	f6c = new XRoot(f64,f68,false);
	f70.resize(f64,f68,C45_Cell());
	c45_cefa64->end(2);
}
