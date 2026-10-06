// XConsole subconsole helpers, XStartupProgress, and the REX engine object's small members
// (header-inline code laid out by LTCG at 0x417e30-0x418d61).
// NOTE: class layouts are partial; all REX/FontSet member names are placeholders.
#include <string>
#include <vector>
using namespace std;

extern "C" unsigned char SDL_GetAppState(void);

//==================================================================
// minimal stand-ins for engine types (see src/engine/xconsole.h for the fuller reconstruction)
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos(const Pos &pos) throw();	// 0x46ca50
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor() throw();	// 0x411d40
	XColor(const XColor &color) throw();	// 0x411e30
};

struct XCell;

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	int	width;
	int	height;
	T	*data;

	Array2D() throw();	// 0x9d2670
};

struct XEvent;

extern XColor &COLOR_BLACK;	// 0xcfe674, NOTE: placeholder name

template <class T> void deleteVectorElement(vector<T*> &v, int &i);	// 0x9d4f60, NOTE: placeholder name
template <class T> void moveVectorElement(vector<T> *v, int from, int to);	// 0x9e2ce0, NOTE: placeholder name

// XConsole layout (sizeof 0x60): subconsoles at +0x44
class XConsole
{
public:
	XConsole(XConsole *parent_, int width, int height, int x, int y, int font_, bool hidden_, int layer_) throw();	// 0x4282e0
	virtual ~XConsole() throw();	// 0x4284b0

	virtual void resize(int width, int height);
	virtual bool isActive() { return true; };
	virtual void refresh() {};
	virtual bool input(XEvent *event) = 0;
	virtual void mouseMoved(int x, int y) {};
	virtual void update() = 0;
	virtual void render() = 0;

	void setFore(XColor color) throw();	// 0x417b00
	void setBack(XColor color) throw();	// 0x417b30

	void deleteSubconsolesExcept(XConsole *console1, XConsole *console2)
	{
		for (int i = 0; i < subconsoles.size(); i++)
		{
			if (subconsoles[i] != console1 && subconsoles[i] != console2)
				deleteVectorElement(subconsoles,i);
		}
	};
	int getSubconsoleIndex(XConsole *console)
	{
		for (unsigned int i = 0; i < subconsoles.size(); i++)
		{
			if (subconsoles[i] == console)
				return i;
		}
		return -1;
	};
	void moveSubconsole(XConsole *console, int index)
	{
		int oldIndex = getSubconsoleIndex(console);
		moveVectorElement(&subconsoles,oldIndex,index);
	};

	char pad4[0x40];
	vector<XConsole*> subconsoles;
	char pad54[0x60 - 0x54];
};

//==================================================================
// XStartupProgress: progress bar shown while the game starts up (vtable @ 0xc2eed4)
//==================================================================

class XStartupProgress : public XConsole
{
public:
	XStartupProgress(XConsole *parent, int width, int height, int x, int y, XColor color_, Pos range_);

	virtual bool input(XEvent *event);
	virtual void update();
	virtual void render();

	XColor color;
	Pos range;
	float progress;
	vector<string> lines;	// NOTE: placeholder name
};

XStartupProgress::XStartupProgress(XConsole *parent, int width, int height, int x, int y, XColor color_, Pos range_)
	: XConsole(parent,width,height,x,y,0,false,30)
	, color		(color_)
	, range		(range_)
{
	setFore(color);
	setBack(COLOR_BLACK);
	if (range.y == 0 || range.x == range.y)
		progress = 0;
	else
		progress = (100 / (range.y - range.x + 1)) / 100.0;
}

bool XStartupProgress::input(XEvent *event)
{
	return false;
}

//==================================================================
// REX engine object
//==================================================================

struct FontSet	// NOTE: placeholder name
{
	string name;
	char pad1c[0x2c - 0x1c];
	int cellWidth;
	int cellHeight;
	unsigned char type;
};

class REX
{
public:
	REX();

	bool unknown4188e0();	// NOTE: placeholder name
	int unknown418920();	// NOTE: placeholder name
	bool unknown418940();	// NOTE: placeholder name
	bool unknown418960();	// NOTE: placeholder name
	int unknown418980();	// NOTE: placeholder name
	int unknown4189a0();	// NOTE: placeholder name
	int unknown4189c0();	// NOTE: placeholder name
	int unknown4189e0();	// NOTE: placeholder name
	int unknown418a00(int x);	// NOTE: placeholder name
	int unknown418a30(int y);	// NOTE: placeholder name
	string unknown418a60();	// NOTE: placeholder name
	void unknown418aa0(vector<string> *names, bool all);	// NOTE: placeholder name
	void unknown418b20(vector<int> *widths, bool all);	// NOTE: placeholder name
	void unknown418ba0(vector<int> *heights, bool all);	// NOTE: placeholder name
	int unknown418c20();	// NOTE: placeholder name
	int unknown418c50();	// NOTE: placeholder name
	bool unknown418c80();	// NOTE: placeholder name
	void unknown418ca0(int value);	// NOTE: placeholder name
	void unknown418cc0(bool value);	// NOTE: placeholder name
	void setCaption(string title_, string icon_);	// NOTE: placeholder name
	void unknown418d70();	// NOTE: placeholder name

	char pad0[8];
	bool unknown08;	// NOTE: placeholder name
	char pad9[0x14 - 9];
	int offsetX;	// NOTE: placeholder name
	int offsetY;	// NOTE: placeholder name
	char pad1c[0x24 - 0x1c];
	string title;	// NOTE: placeholder name
	string icon;	// NOTE: placeholder name
	char pad5c[0x64 - 0x5c];
	int unknown64;	// NOTE: placeholder name
	int unknown68;	// NOTE: placeholder name
	XConsole *root;
	Array2D<XCell> screen;	// NOTE: placeholder name
	string unknown7c;	// NOTE: placeholder name
	XColor unknown98;	// NOTE: placeholder name
	vector<int> unknown9c;	// NOTE: placeholder name
	vector<int> unknownac;	// NOTE: placeholder name
	vector<FontSet*> fontSets;	// NOTE: placeholder name
	char padcc[4];
	FontSet *fontSet;	// NOTE: placeholder name
	char padd4[8];
	int unknowndc;	// NOTE: placeholder name
	string unknowne0;	// NOTE: placeholder name
	int unknownfc;	// NOTE: placeholder name
	string unknown100;	// NOTE: placeholder name
	int unknown11c;	// NOTE: placeholder name
	int unknown120;	// NOTE: placeholder name
	char pad124[0x150 - 0x124];
	string unknown150;	// NOTE: placeholder name
	string unknown16c;	// NOTE: placeholder name
	char pad188[0x1a0 - 0x188];
};

REX::REX()
{
	root = NULL;
}

bool REX::unknown4188e0()
{
	return unknown08;
}

int REX::unknown418920()
{
	return SDL_GetAppState() & 1;
}

bool REX::unknown418940()
{
	return SDL_GetAppState() & 2;
}

bool REX::unknown418960()
{
	return SDL_GetAppState() & 4;
}

int REX::unknown418980()
{
	return unknown64;
}

int REX::unknown4189a0()
{
	return unknown68;
}

int REX::unknown4189c0()
{
	return fontSet->cellWidth;
}

int REX::unknown4189e0()
{
	return fontSet->cellHeight;
}

int REX::unknown418a00(int x)
{
	return (x - offsetX) / fontSet->cellWidth;
}

int REX::unknown418a30(int y)
{
	return (y - offsetY) / fontSet->cellHeight;
}

string REX::unknown418a60()
{
	return fontSet->name;
}

void REX::unknown418aa0(vector<string> *names, bool all)
{
	for (unsigned int i = 0; i < fontSets.size(); i++)
	{
		if (all || fontSets[i]->type != 1)
			names->push_back(fontSets[i]->name);
	}
}

void REX::unknown418b20(vector<int> *widths, bool all)
{
	for (unsigned int i = 0; i < fontSets.size(); i++)
	{
		if (all || fontSets[i]->type != 1)
			widths->push_back(fontSets[i]->cellWidth);
	}
}

void REX::unknown418ba0(vector<int> *heights, bool all)
{
	for (unsigned int i = 0; i < fontSets.size(); i++)
	{
		if (all || fontSets[i]->type != 1)
			heights->push_back(fontSets[i]->cellHeight);
	}
}

int REX::unknown418c20()
{
	return fontSets[unknownfc]->cellHeight;
}

int REX::unknown418c50()
{
	return fontSets[unknown11c]->cellHeight;
}

bool REX::unknown418c80()
{
	return unknown120;
}

void REX::unknown418ca0(int value)
{
	unknowndc = value;
}

void REX::unknown418cc0(bool value)
{
	unknown08 = value;
}

void REX::setCaption(string title_, string icon_)
{
	title = title_;
	icon = icon_;
	unknown418d70();
}

//==================================================================
// XConsole subconsole helpers (declared inline in xconsole.h, never referenced elsewhere)
//==================================================================

void unknownXConsoleUse22(XConsole *c, XConsole *a, XConsole *b, int i)
{
	c->deleteSubconsolesExcept(a,b);
	c->getSubconsoleIndex(a);
	c->moveSubconsole(a,i);
}
