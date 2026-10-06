// Main window subclassing (blocks the Alt-key system menu), matched against COGMIND.exe (Beta 17.1).
// The rest of the 0x401000-0x4014bc cluster is CRT/STL header-inline code (time.inl, math.h float
// overloads, std::bad_alloc, wchar.h wmem*, char_traits<wchar_t>) that has no source of its own:
// see config/mapping.d/cc_r1_04.csv.
#include <windows.h>

using namespace std;

//==================================================================
// SDL 1.2 (SDL_syswm.h, Win32)
//==================================================================

struct SDL_version
{
	unsigned char major;
	unsigned char minor;
	unsigned char patch;
};

#define SDL_MAJOR_VERSION	1
#define SDL_MINOR_VERSION	2
#define SDL_PATCHLEVEL		14

#define SDL_VERSION(X)							\
{												\
	(X)->major = SDL_MAJOR_VERSION;				\
	(X)->minor = SDL_MINOR_VERSION;				\
	(X)->patch = SDL_PATCHLEVEL;				\
}

struct SDL_SysWMinfo
{
	SDL_version version;
	HWND window;		// the Win32 display window
	HGLRC hglrc;		// the OpenGL context, if any
};

extern "C" int SDL_GetWMInfo(SDL_SysWMinfo *info);

//==================================================================
// Window procedure hook
//==================================================================

extern WNDPROC prevWndProc_cefa60;	// NOTE: placeholder name (0xcefa60)

// NOTE: placeholder name
LRESULT CALLBACK gameWndProc_401080(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// ignore Alt/F10 activating the (nonexistent) window menu, which would pause the game
	if (msg == WM_SYSCOMMAND && (wParam & 0xFFF0) == SC_KEYMENU)
		return 0;
	return CallWindowProcW(prevWndProc_cefa60,hwnd,msg,wParam,lParam);
}

// NOTE: placeholder name; installs the hook, or removes it if already installed
void toggleWndProcHook_4010c0(HWND hwnd)
{
	if (prevWndProc_cefa60)
	{
		SetWindowLongW(hwnd,GWL_WNDPROC,(LONG)prevWndProc_cefa60);
		prevWndProc_cefa60 = NULL;
	}
	else
	{
		prevWndProc_cefa60 = (WNDPROC)GetWindowLongW(hwnd,GWL_WNDPROC);
		SetWindowLongW(hwnd,GWL_WNDPROC,(LONG)gameWndProc_401080);
	}
}

// NOTE: placeholder name
void hookSdlWindow_401110()
{
	SDL_SysWMinfo info;
	SDL_VERSION(&info.version);
	if (SDL_GetWMInfo(&info))
		toggleWndProcHook_4010c0(info.window);
}
