// Batch 2: REX engine layer/fullscreen helpers, font set, resource manager.
// NOTE: class layouts are partial; padding members and names are placeholders.
#include <string>
#include <vector>
using namespace std;

void logError(string location, string message);	// NOTE: placeholder name
void logNote(string location, string message);	// NOTE: placeholder name (0x404fd0)

// NOTE: minimal stand-ins for the real XConsole/Console (src/consoles/*.h), which lack blit()
class XConsole
{
public:
	virtual ~XConsole();
	void blit(void *surface, int flag);	// 0x42a5b0

	char pad4[0x5c];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();

	char pad60[0xc];
};

class XRootStub : public XConsole	// NOTE: placeholder name
{
public:
	bool addToLayer(XConsole *console, int layer);	// 0x42da30
	bool removeFromLayer(XConsole *console);	// 0x42dcc0
};

extern string (*consoleToString)(XConsole *console);	// NOTE: placeholder name (0xcebc48)
extern void *screenSurface;	// NOTE: placeholder name (0xcefa80)

class REX
{
public:
	void consoleAddToLayer(XConsole *console, int layer);
	void consoleRemoveFromLayer(XConsole *console);
	void toggleFullscreen();
	void setVideoMode();
	void unknown424020(string *mode, bool flag);	// NOTE: placeholder name

	char pad0[4];
	int fullscreen;	// NOTE: placeholder name
	char pad8[0x64];
	XRootStub *root;
	char pad70[0x60];
	const string *videoMode;	// NOTE: placeholder name
	char padd4[0xc];
	string modeA;	// NOTE: placeholder name
	char pade1c[4];
	string modeB;	// NOTE: placeholder name
	char pad11c[4];
	XRootStub *swappedRoot;	// NOTE: placeholder name
};

void REX::consoleAddToLayer(XConsole *console, int layer)
{
	if (root->addToLayer(console,layer))
		return;
	if (swappedRoot && swappedRoot->addToLayer(console,layer))
		return;
	logError("REX::consoleAddToLayer()","XConsole parent not found: " + consoleToString(console));
}

void REX::consoleRemoveFromLayer(XConsole *console)
{
	if (root->removeFromLayer(console))
		return;
	if (swappedRoot && swappedRoot->removeFromLayer(console))
		return;
	logError("REX::consoleRemoveFromLayer()","XConsole not found: " + consoleToString(console));
}

void REX::toggleFullscreen()
{
	if (swappedRoot)
		logNote("REX::toggleFullscreen()","not allowed while root swapped");
	fullscreen = !fullscreen;
	if (fullscreen)
	{
		modeA = *videoMode;
		if (modeB != *videoMode)
		{
			unknown424020(&modeB,false);
			return;
		}
	}
	else
	{
		modeB = *videoMode;
		if (modeA != *videoMode)
		{
			unknown424020(&modeA,false);
			return;
		}
	}
	setVideoMode();
	root->blit(screenSurface,0);
}

class CCommandsAdvancedButton : public Console	// NOTE: placeholder name (vtable 0xc34928)
{
public:
	CCommandsAdvancedButton(XConsole *parent, int unknown1, bool unknown2);	// 0x4928d0

	bool unknown6c;	// NOTE: placeholder name
	bool unknown6d;	// NOTE: placeholder name
};

class CCommandsAdvancedPage : public Console	// vtable 0xc3495c
{
public:
	CCommandsAdvancedPage(XConsole *parent, int x, int y);	// 0x4929b0
	virtual ~CCommandsAdvancedPage();

	void init();	// NOTE: placeholder name (0x492ad0)

	int unknown6c;	// NOTE: placeholder name
	CCommandsAdvancedButton *button1;	// NOTE: placeholder name
	CCommandsAdvancedButton *button2;	// NOTE: placeholder name
};

CCommandsAdvancedPage::CCommandsAdvancedPage(XConsole *parent, int x, int y)
	: Console(parent,0x12,1,x,y,0,false,-1)
{
	unknown6c = 1;
	init();
	button1 = new CCommandsAdvancedButton(this,0,false);
	button2 = new CCommandsAdvancedButton(this,0xe,true);
}

extern "C" const char *PHYSFS_getLastError(void);

struct SDL_RWops;
struct SDL_Surface;
struct Mix_Chunk;
struct PHYSFS_File;
extern "C" PHYSFS_File *PHYSFS_openRead(const char *filename);
extern "C" SDL_Surface *IMG_Load_RW(SDL_RWops *src, int freesrc);
extern "C" Mix_Chunk *Mix_LoadWAV_RW(SDL_RWops *src, int freesrc);
extern "C" const char *SDL_GetError(void);
SDL_RWops *PHYSFSRWOPS_makeRWops(PHYSFS_File *file);	// 0x4038a0

class PhysfsWrapper	// NOTE: placeholder name
{
public:
	bool addToSearchPath(string path, bool append);	// 0x404230
	bool addArchive(string path, bool append);	// NOTE: placeholder name (0x4042c0)
	string getBaseDir();	// NOTE: placeholder name (0x4041a0)
};

class XResourceMgr
{
public:
	bool addSearchPath(string path, bool append);
	bool addResourcePath(string path, bool append);

	SDL_RWops *getRWopsFromFile(const string &path);
	SDL_Surface *getSurfaceFromFile(const string &path);	// 0x4159a0
	Mix_Chunk *getSoundFromFile(const string &path);	// NOTE: placeholder name (0x415b00)

	PhysfsWrapper *physfs;	// NOTE: placeholder name
};

bool XResourceMgr::addSearchPath(string path, bool append)
{
	if (!physfs->addToSearchPath(path,append))
	{
		logNote("XResourceMgr::addSearchPath()","PHYSFS_addToSearchPath() failed to add search path \"" + path + "\", " + string(PHYSFS_getLastError()));
		return false;
	}
	else
		return true;
}

bool XResourceMgr::addResourcePath(string path, bool append)
{
	if (!physfs->addArchive(path,append))
	{
		logNote("XResourceMgr::addResourcePath()","PHYSFS_addToSearchPath() failed to add resource search path (archive) \"" + path + physfs->getBaseDir() + "\", " + string(PHYSFS_getLastError()));
		return false;
	}
	else
		return true;
}

SDL_RWops *XResourceMgr::getRWopsFromFile(const string &path)
{
	PHYSFS_File *const file = PHYSFS_openRead(path.c_str());
	if (file == NULL)
		logNote("XResourceMgr::getRWopsFromFile()","PHYSFS_openRead() failed to open resource file \"" + path + "\", " + string(PHYSFS_getLastError()));
	SDL_RWops *result = PHYSFSRWOPS_makeRWops(file);
	if (result == NULL)
		logNote("XResourceMgr::getRWopsFromFile()","PHYSFSRWOPS_makeRWops() failed to create RWops struct \"" + path + "\"");
	return result;
}

SDL_Surface *XResourceMgr::getSurfaceFromFile(const string &path)
{
	SDL_Surface *surface = IMG_Load_RW(getRWopsFromFile(path),1);
	if (surface == NULL)
		logNote("XResourceMgr::getSurfaceFromFile()","Failed to load texture \"" + path + "\", IMG_Load_RW: " + string(SDL_GetError()));
	return surface;
}

Mix_Chunk *XResourceMgr::getSoundFromFile(const string &path)
{
	Mix_Chunk *chunk = Mix_LoadWAV_RW(getRWopsFromFile(path),1);
	if (chunk == NULL)
		logNote("XResourceMgr::getSurfaceFromFile()","Failed to load sound \"" + path + "\", Mix_LoadWAV_RW: " + string(SDL_GetError()));
	return chunk;
}
