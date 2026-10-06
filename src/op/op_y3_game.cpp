// op_y3: assorted game-level free functions in 0x4fd000-0x4fe000 (font/option toggles, location naming).
// NOTE: global and helper names are placeholders unless stated otherwise.
#include <string>
using namespace std;

string intToString(int value);
void logWarning(string location, string message);

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp();
};

struct Pos	// NOTE: placeholder name
{
	int x;
	int y;
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Pos mouse;
};

class REX
{
public:
	bool unknown404af0();	// NOTE: placeholder name
	int unknown4189e0();	// NOTE: placeholder name
	string unknown418a60();	// NOTE: placeholder name
};
extern REX rex;	// 0xd223f0

class BS
{
public:
	int unknown463e50();	// NOTE: placeholder name
};
extern BS *world;	// NOTE: placeholder name (0xcefc4c)

class XConsole
{
public:
	bool isHidden();
};

class OpY3_Console_cec03c : public XConsole	// NOTE: placeholder name
{
public:
	void unknown7d5c70();	// NOTE: placeholder name
};
extern OpY3_Console_cec03c *opY3_console_cec03c;	// NOTE: placeholder name

class OpY3_MapView : public XConsole	// NOTE: placeholder name (0xcec054)
{
public:
	virtual void v00();
	virtual void v04();
	virtual void v08();
	virtual void v0c();
	virtual bool input(XEvent *event);
	void unknown827950();	// NOTE: placeholder name
	void unknown49ac70();	// NOTE: placeholder name
};
extern OpY3_MapView *opY3_mapView;	// NOTE: placeholder name

class OpY3_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	bool getField();	// NOTE: placeholder name (0x41a6e0)
	void unknown432170(bool value);	// NOTE: placeholder name
};
extern OpY3_Mouse *opY3_mouse;	// NOTE: placeholder name

class OpY3_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	bool unknown416200(int key);	// NOTE: placeholder name
};
extern OpY3_KeyMap *opY3_keyMap;	// NOTE: placeholder name

class OpY3_Audio	// NOTE: placeholder name (0xcefaa8)
{
public:
	void unknown78d700(int a, int b);	// NOTE: placeholder name
};
extern OpY3_Audio *opY3_audio;	// NOTE: placeholder name

void opY3_message(int type, const string *text, int b, int c, HEntity d, HProp e, int f);	// NOTE: placeholder name (0x7b1750)

extern string opY3_fontName;	// NOTE: placeholder name (0xd2d490)
extern string opY3_string_d28c6c;	// NOTE: placeholder name
extern string opY3_string_d2a504;	// NOTE: placeholder name
extern bool opY3_tilesEnabled;	// NOTE: placeholder name (0xd28d30)
extern bool opY3_d28c8a;	// NOTE: placeholder name
extern bool opY3_d28e06;	// NOTE: placeholder name
extern bool opY3_d3c220;	// NOTE: placeholder name
extern bool opY3_d28fae;	// NOTE: placeholder name
extern int opY3_cefc8c;	// NOTE: placeholder name

void fontSetChanged(bool ignore)
{
	if (ignore)
		return;

	opY3_fontName = rex.unknown418a60();
	if (opY3_string_d28c6c != opY3_string_d2a504)
		opY3_string_d28c6c = opY3_fontName;

	if (world != NULL && world->unknown463e50() && opY3_console_cec03c->isHidden())
		opY3_message(0xd9,&opY3_fontName,0,0,HEntity(),HProp(),0);

	if (rex.unknown4189e0() <= 10 && opY3_tilesEnabled)
	{
		opY3_tilesEnabled = !opY3_tilesEnabled;
		logWarning("fontSetChanged()","Specified font size ("+intToString(rex.unknown4189e0())+") has no tileset (too small), forcing ASCII mode");
		if (world != NULL && world->unknown463e50() == 1)
		{
			opY3_tilesEnabled = true;
			opY3_audio->unknown78d700(0,0);
			opY3_message(0xda,0,0,0,HEntity(),HProp(),0);
		}
	}

	if (!opY3_console_cec03c->isHidden())
		opY3_console_cec03c->unknown7d5c70();
}

void opY3_unknown4fd460(int button, int state)	// NOTE: placeholder name
{
	if (button == 1 && state == 0)
	{
		if (rex.unknown404af0() && opY3_d28c8a)
		{
			opY3_mouse->unknown432170(!opY3_mouse->getField());
			opY3_d28c8a = !opY3_d28c8a;
			if (opY3_mapView != NULL && opY3_keyMap->unknown416200(8))
			{
				opY3_mapView->unknown827950();
				if (opY3_d28e06)
				{
					opY3_mapView->unknown49ac70();
					opY3_mapView->input(&XEvent(0x2f));
				}
			}
			opY3_d3c220 = true;
		}
	}
	else if (((button == 2 && state != 0) || (button == 1 && state != 0)) && opY3_d3c220)
	{
		opY3_mouse->unknown432170(!opY3_mouse->getField());
		opY3_d28c8a = !opY3_d28c8a;
		opY3_d3c220 = false;
	}

	if (opY3_d28fae)
	{
		if (button == 1 && state == 0)
			opY3_cefc8c = 3;
		else if (button == 2 && state != 0)
		{
			if (opY3_console_cec03c != NULL && !opY3_console_cec03c->isHidden())
				opY3_cefc8c = 2;
			else
				opY3_cefc8c = 1;
		}
	}
}

struct OpY3_LocationInfo	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
	int depth;	// NOTE: placeholder name
};
class OpY3_HLocation	// NOTE: placeholder name
{
public:
	int ID;
	bool isValid() const;
	OpY3_LocationInfo *operator->() const;	// 0x9b7910
};
extern OpY3_HLocation opY3_location;	// NOTE: placeholder name (0xd1e888)
extern void *opY3_cec028;	// NOTE: placeholder name
extern void *opY3_cec02c;	// NOTE: placeholder name
extern void *opY3_cec030;	// NOTE: placeholder name
extern int opY3_specialMode;	// NOTE: placeholder name (0xcf4b38)
extern string opY3_specialModeNames[];	// NOTE: placeholder name (0xcf4168)
extern string opY3_mapTypeNames[];	// NOTE: placeholder name (0xcfaca0)
void opY3_replaceChar(string &text, char from, char to);	// NOTE: placeholder name (0x4081c0)
string opY3_dateString(int a, int b, int c);	// NOTE: placeholder name (0x436e70)

string opY3_getLocationName(bool forFilename)	// NOTE: placeholder name
{
	if (opY3_cec028)
		return "Difficulty selection";
	if (opY3_cec02c)
		return "Title screen";
	if (opY3_cec030)
		return "Intro sequence";
	if (opY3_specialMode != 28)
		return opY3_specialModeNames[opY3_specialMode];
	if (opY3_location.isValid())
	{
		string name = opY3_mapTypeNames[opY3_location->type];
		opY3_replaceChar(name,' ','_');
		return "-"+intToString(opY3_location->depth)+(forFilename ? "_" : "/")+name;
	}
	return string();
}

void opY3_makeFilename(string &filename)	// NOTE: placeholder name
{
	filename = "cogmind_"+opY3_dateString(0,0,0);
	string location = opY3_getLocationName(true);
	if (!location.empty())
		filename += "_"+location;
}
