// Win32/SDL 1.2 window and clipboard boundaries (COGMIND Beta 17.1).
// NOTE: opX1-prefixed names and the two REX method names are placeholders.
#include <windows.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

//==================================================================
// SDL 1.2.14 Win32 system window information
//==================================================================

// Matches src/game/cc_r1_04.cpp: HWND at +4, HGLRC at +8, total 12 bytes.
struct SDL_version
{
	unsigned char major;
	unsigned char minor;
	unsigned char patch;
};

struct SDL_SysWMinfo
{
	SDL_version version;
	HWND window;
	HGLRC hglrc;
};

#define SDL_VERSION(X) \
{	\
	(X)->major = 1; \
	(X)->minor = 2; \
	(X)->patch = 14; \
}

extern "C" int SDL_GetWMInfo(SDL_SysWMinfo *info);
extern "C" void SDL_SetError(const char *format, ...);

//==================================================================
// REX window position and inclusive rectangle dimensions
//==================================================================

// NOTE: placeholder class, field, and operation names; the existing mapped
// signature is reused verbatim from src/match_push/straight.cpp (0x456940).
class Push_456940
{
public:
	int field0;
	int field4;
	int field8;
	int fieldc;
	Push_456940 & operate(int arg0, int arg1, int arg2, int arg3);
};

// Partial standalone declaration, as in src/game/batch2.cpp. Neither method
// reads REX fields. The query exposes the original hidden rectangle-result
// argument explicitly: ECX is REX, [esp+4] is the 16-byte result, EAX returns
// that same result pointer, and the callee pops four bytes.
class REX
{
public:
	Push_456940 *getWindowRect(Push_456940 *result);	// NOTE: placeholder name (0x423e30)
	void moveWindow(int x, int y);	// NOTE: placeholder name (0x423ec0)
};

Push_456940 *REX::getWindowRect(Push_456940 *result)
{
	SDL_SysWMinfo info;
	SDL_VERSION(&info.version);
	if (SDL_GetWMInfo(&info))
	{
		RECT windowRect;
		GetWindowRect(info.window,&windowRect);
		result->operate(windowRect.left,windowRect.top,
			windowRect.right - windowRect.left + 1,
			windowRect.bottom - windowRect.top + 1);
		return result;
	}
	result->operate(0,0,2,2);
	return result;
}

void REX::moveWindow(int x, int y)
{
	SDL_SysWMinfo info;
	SDL_VERSION(&info.version);
	if (SDL_GetWMInfo(&info))
	{
		RECT windowRect;
		GetWindowRect(info.window,&windowRect);
		MoveWindow(info.window,x,y,
			windowRect.right - windowRect.left + 1,
			windowRect.bottom - windowRect.top + 1,FALSE);
	}
}

//==================================================================
// SDL scrap clipboard helpers (cdecl, not REX/clipboard object methods)
//==================================================================

extern HWND opX1ClipboardWindow;	// NOTE: placeholder name (0xcec450)

// NOTE: placeholder name (0x41aad0), existing external conversion dependency.
// For TEXT and zero length, it scans the source string and returns the output
// byte count including NUL. A NULL destination only measures; a real one
// drops CR bytes and replaces LF with CR. Other formats carry a size prefix.
int opX1CopyClipboardData(unsigned int format, char *destination, const char *source, int length);

// NOTE: placeholder name (0x41aa70).
unsigned int opX1ClipboardFormat(unsigned int format)
{
	char formatName[24];
	switch (format)
	{
	case 0x54455854:
		return CF_TEXT;
	default:
		sprintf(formatName,"%s%08lx","SDL_scrap_0x",format);
		// The executable imports the W API despite the narrow sprintf buffer.
		// Preserve that measured boundary rather than silently changing encoding.
		return RegisterClipboardFormatW((LPCWSTR)formatName);
	}
}

// NOTE: placeholder name (0x41ac30).
int opX1InitializeClipboardWindow()
{
	SDL_SysWMinfo info;
	int result = -1;
	SDL_SetError("SDL is not running on known window manager");
	SDL_VERSION(&info.version);
	if (SDL_GetWMInfo(&info))
	{
		opX1ClipboardWindow = info.window;
		result = 0;
	}
	return result;
}

// NOTE: placeholder name (0x41ac80).
// The caller supplies realloc-compatible storage; length is reset even when
// the format is unavailable. This returns bytes through char **, not a C++
// string or hidden string-result argument (see the caller at 0x41ae40).
void opX1GetClipboardText(unsigned int format, int *length, char **buffer)
{
	*length = 0;
	unsigned int clipboardFormat = opX1ClipboardFormat(format);
	if (IsClipboardFormatAvailable(clipboardFormat) && OpenClipboard(opX1ClipboardWindow))
	{
		HANDLE data = GetClipboardData(clipboardFormat);
		if (data != NULL)
		{
			char *text = (char *)GlobalLock(data);
			*length = opX1CopyClipboardData(format,NULL,text,0);
			*buffer = (char *)realloc(*buffer,*length);
			if (*buffer == NULL)
				*length = 0;
			else
				opX1CopyClipboardData(format,*buffer,text,0);
			GlobalUnlock(data);
		}
		CloseClipboard();
	}
}
