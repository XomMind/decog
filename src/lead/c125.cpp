// Cluster c125: small UI console methods (0x7d6690-0x7d9fe0 region) and data-output writers.
// NOTE: class layouts are partial; names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <ostream>
#include <algorithm>
using namespace std;

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);
	Pos(const Pos &pos);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
};

class Console;

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);	// NOTE: placeholder name
	virtual void update();
	virtual void render();	// NOTE: placeholder name

	int getWidth() throw();
	int getHeight() throw();
	XConsole *getParent();	// NOTE: placeholder name
	void print(int x, int y, const string &text);	// NOTE: placeholder name
	void printAligned(int x, int y, int align, const string &text);	// NOTE: placeholder name
	void setChar_417f50(int x, int y, int ch);	// NOTE: placeholder name
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	void setBack_417fc0(int x, int y, XColor color, int flag) throw();	// NOTE: placeholder name
	void resetBack_418450() throw();	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);

	char pad4[0x5c];
};

class Engine
{
public:
	void stopAll();	// NOTE: placeholder name
	char data[0x58];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer) throw();
	virtual ~Console();
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	void animate(string name);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	void *title;
};

string intToString(int value);	// NOTE: placeholder name
bool unknown4328a0();	// NOTE: placeholder name

extern bool unknown_d28c8a;	// NOTE: placeholder name
extern XColor *unknown_d2175c;	// NOTE: placeholder name
extern XColor unknown_d29804;	// NOTE: placeholder name

//==================================================================
// UI objects found through the three global pointers 0xcec040, 0xcec044, 0xcec048
//==================================================================

class UiA : public Console	// NOTE: placeholder name (global at 0xcec040)
{
public:
	int unknown7e8c30();	// NOTE: placeholder name
	int unknown7e8c50();	// NOTE: placeholder name
	void unknown7e83f0(int value);	// NOTE: placeholder name
	int unknown497740(XConsole *parent);	// NOTE: placeholder name
};

class UiB : public Console	// NOTE: placeholder name (global at 0xcec044)
{
public:
	int unknown7ebd10();	// NOTE: placeholder name
	int unknown7ebd30();	// NOTE: placeholder name
	void unknown7eafe0(int value, int flag);	// NOTE: placeholder name
};

class UiC : public Console	// NOTE: placeholder name (global at 0xcec048)
{
public:
	int unknown7f1f60();	// NOTE: placeholder name
	int unknown7f1fb0();	// NOTE: placeholder name
	void unknown7f0d10(int value);	// NOTE: placeholder name
};

extern UiA *unknown_cec040;	// NOTE: placeholder name
extern UiB *unknown_cec044;	// NOTE: placeholder name
extern UiC *unknown_cec048;	// NOTE: placeholder name
extern int unknown_bcbe04[];	// NOTE: placeholder name
extern int unknown_bcbe1c[];	// NOTE: placeholder name
extern int unknown_bcabc4[];	// NOTE: placeholder name

//==================================================================
// scroll-type console pieces
//==================================================================

class CScrollPiece : public Console	// NOTE: placeholder name
{
public:
	int unknown7d7750();	// NOTE: placeholder name
	int unknown7d77b0();	// NOTE: placeholder name
	void unknown7d7810(int value);	// NOTE: placeholder name
	void unknown7d7880();	// NOTE: placeholder name
	bool unknown7d79a0(void *event);	// NOTE: placeholder name
	bool unknown7d7ab0();	// NOTE: placeholder name

	bool flag;	// NOTE: placeholder name
};

int CScrollPiece::unknown7d7750()
{
	return unknown_cec040 ? unknown_cec040->unknown7e8c30() : (unknown_cec044 ? unknown_cec044->unknown7ebd10() : unknown_cec048->unknown7f1f60());
}

int CScrollPiece::unknown7d77b0()
{
	return unknown_cec040 ? unknown_cec040->unknown7e8c50() : (unknown_cec044 ? unknown_cec044->unknown7ebd30() : unknown_cec048->unknown7f1fb0());
}

void CScrollPiece::unknown7d7810(int value)
{
	unknown_cec040 ? unknown_cec040->unknown7e83f0(value) : (unknown_cec044 ? unknown_cec044->unknown7eafe0(value,-1) : unknown_cec048->unknown7f0d10(value));
}

void CScrollPiece::unknown7d7880()
{
	if (flag)
	{
		printAligned(getWidth() - 2,0,2,intToString(unknown7d7750()));
	}
	else
	{
		print(1,0,intToString(unknown7d77b0()));
	}
}

bool CScrollPiece::unknown7d79a0(void *event)
{
	switch (*(int*)event)
	{
	case 0x26:
		if (unknown_cec040)
		{
			if (flag)
				unknown7d7810(-3);
			else
				unknown7d7810(3);
		}
		else if (unknown_cec044)
		{
			if (flag)
				unknown_cec044->unknown7eafe0(-unknown_bcbe04[unknown4328a0() != 0],-1);
			else
				unknown_cec044->unknown7eafe0(unknown_bcbe04[unknown4328a0() != 0],-1);
		}
		else
		{
			if (flag)
				unknown_cec048->unknown7f0d10(-(unknown_bcbe1c[unknown4328a0() != 0] * 2));
			else
				unknown_cec048->unknown7f0d10(unknown_bcbe1c[unknown4328a0() != 0] * 2);
		}
		return true;
	default:
		return false;
	}
}

bool CScrollPiece::unknown7d7ab0()
{
	if ((flag && !unknown7d7750()) || (!flag && !unknown7d77b0()))
		return false;
	animate(string("A_ButtonHover_Begin_CMOD_HOV_OK"));
	return true;
}

//==================================================================
// misc consoles
//==================================================================

class CScrollPiece2 : public Console	// NOTE: placeholder name
{
public:
	bool unknown7d88d0(void *event);	// NOTE: placeholder name
	bool unknown7d8990();	// NOTE: placeholder name
	void unknown496e60();	// NOTE: placeholder name

	int index;	// NOTE: placeholder name
	bool flag;	// NOTE: placeholder name
};

bool CScrollPiece2::unknown7d88d0(void *event)
{
	switch (*(int*)event)
	{
	case 0x26:
		unknown496e60();
		if (unknown_cec040)
			unknown_cec040->inputMouse(unknown_bcabc4[index],1);
		else if (unknown_cec044)
			unknown_cec044->inputMouse(unknown_bcabc4[index],1);
		else if (unknown_cec048)
			unknown_cec048->inputMouse(unknown_bcabc4[index],1);
		return true;
	default:
		return false;
	}
}

bool CScrollPiece2::unknown7d8990()
{
	if (flag)
		return false;
	animate(string("A_ButtonHover_Begin_MANU_HOV_OK"));
	return true;
}

struct GalleryPieceData	// NOTE: placeholder name
{
	char pad[0x6c];
	int index;	// NOTE: placeholder name
};

class CGalleryPiece : public Console	// NOTE: placeholder name
{
public:
	bool unknown7d6c30();	// NOTE: placeholder name
};

struct GalleryPiece	// NOTE: placeholder name
{
	int unknown0;
};
extern vector<GalleryPiece*> unknown_d25790;	// NOTE: placeholder name

bool CGalleryPiece::unknown7d6c30()
{
	if (unknown_d25790[((GalleryPieceData*)getParent())->index] == NULL)
		return false;
	animate(string("A_Gallery_Item_HOV_OK"));
	return true;
}

// NOTE: 0x7d6a30 (CGalleryInfoButton::update) is defined in src/game/team_b_03.cpp.

class CGalleryFrame : public Console	// NOTE: placeholder name
{
public:
	CGalleryFrame(XConsole *parent);	// NOTE: placeholder name
};

CGalleryFrame::CGalleryFrame(XConsole *parent)
	: Console(parent,parent->getWidth() + 2,parent->getHeight(),-1,0,0,false,-1)
{
	resetBack_418450();
	if (unknown_d28c8a)
		setBack_417fc0(0,2,unknown_d29804,1);
}

//==================================================================
// gallery name comparison
//==================================================================

struct GalleryItem	// NOTE: placeholder name
{
	char pad0[8];
	string name;	// NOTE: placeholder name
	char pad1[0x40 - 8 - sizeof(string)];
	int prefix;		// NOTE: placeholder name
};
extern vector<GalleryItem*> unknown_d2d1c4;	// NOTE: placeholder name

bool unknown7d8bd0(string &a, unsigned int i, string &b, unsigned int j);	// NOTE: placeholder name
bool unknown7d8c30(int a, int b);	// NOTE: placeholder name

bool unknown7d8bd0(string &a, unsigned int i, string &b, unsigned int j)
{
	for (; i < a.size() && j < b.size(); i++, j++)
	{
		if (a[i] != b[j])
			return false;
	}
	return true;
}

bool unknown7d8c30(int a, int b)
{
	string &nameA = unknown_d2d1c4[a]->name;
	string &nameB = unknown_d2d1c4[b]->name;

	if (unknown7d8bd0(nameA,unknown_d2d1c4[a]->prefix ? 5 : 0,nameB,unknown_d2d1c4[b]->prefix ? 5 : 0))
		return a < b;
	else
		return lexicographical_compare(nameA.begin() + (unknown_d2d1c4[a]->prefix ? 5 : 0),nameA.end(),nameB.begin() + (unknown_d2d1c4[b]->prefix ? 5 : 0),nameB.end());
}

//==================================================================
// teardown of a manual-style console
//==================================================================

class UiM : public XConsole	// NOTE: placeholder name (global at 0xcec03c)
{
public:
	void unknown4968e0();	// NOTE: placeholder name
};
extern UiM *unknown_cec03c;	// NOTE: placeholder name

class KeyMapX	// NOTE: placeholder name (global at 0xcefa8c)
{
public:
	void unknown416640();	// NOTE: placeholder name
};
extern KeyMapX *unknown_cefa8c;	// NOTE: placeholder name

class CManualX : public Console	// NOTE: placeholder name
{
public:
	void unknown7d9b60();	// NOTE: placeholder name

	char pad6c[0xb4 - 0x6c];
	XConsole *unknownb4;	// NOTE: placeholder name
	XConsole *unknownb8;	// NOTE: placeholder name
	XConsole *unknownbc;	// NOTE: placeholder name
	XConsole *unknownc0;	// NOTE: placeholder name
};

void CManualX::unknown7d9b60()
{
	unknown_cec03c->removeSubconsole(unknownb4);
	unknown_cec03c->removeSubconsole(unknownb8);
	unknown_cec03c->removeSubconsole(unknownbc);
	if (unknownc0)
		unknown_cec03c->removeSubconsole(unknownc0);
	unknown_cec03c->unknown4968e0();
	unknown60 = 0;
	unknown_cefa8c->unknown416640();
	getParent()->removeSubconsole(this);
}

//==================================================================
// data output writers (HTML table / CSV cells)
//==================================================================

string floatToString(float value, int unknown1, int unknown2);	// NOTE: placeholder name (0x405760)

void unknown7d9df0(ostream &out, string &name, float value, int unknown1, int unknown2, string text);	// NOTE: placeholder name
void unknown7d9f10(ostream &out, string &name, string &text);	// NOTE: placeholder name
void unknown7d9f90(ostream &out, string &text, int span);	// NOTE: placeholder name
void unknown7d9fe0(ostream &out, string &text);	// NOTE: placeholder name
void unknown7da020(ostream &out, string &text);	// NOTE: placeholder name
void unknown7da060(ostream &out, int value, string text1, string text2);	// NOTE: placeholder name
void unknown7da120(ostream &out, float value, int unknown1, int unknown2, string text);	// NOTE: placeholder name
void unknown7da210(ostream &out, int value);	// NOTE: placeholder name
void unknown7da260(ostream &out, float value, int unknown1, int unknown2);	// NOTE: placeholder name

void unknown7d9df0(ostream &out, string &name, float value, int unknown1, int unknown2, string text)
{
	if (value == 0)
		return;
	out << name;
	for (int i = name.size(); i <= 15; i++)
		out << " ";
	out << text << floatToString(value,unknown1,unknown2) << "\n";
}

void unknown7d9f10(ostream &out, string &name, string &text)
{
	if (text.empty())
		return;
	out << name;
	for (int i = name.size(); i <= 15; i++)
		out << " ";
	out << text << "\n";
}

void unknown7d9f90(ostream &out, string &text, int span)
{
	out << "  <th class=\"superheader\" colspan=\"" << span << "\">" << text << "</th>\n";
}

void unknown7d9fe0(ostream &out, string &text)
{
	out << "  <th>" << text << "</th>\n";
}

void unknown7da020(ostream &out, string &text)
{
	out << "  <td>" << text << "</td>\n";
}

void unknown7da060(ostream &out, int value, string text1, string text2)
{
	if (value)
		out << "  <td>" << text1 << value << text2 << "</td>\n";
	else
		out << "  <td></td>\n";
}

void unknown7da120(ostream &out, float value, int unknown1, int unknown2, string text)
{
	if (value != 0)
		out << "  <td>" << text << floatToString(value,unknown1,unknown2) << "</td>\n";
	else
		out << "  <td></td>\n";
}

void unknown7da210(ostream &out, int value)
{
	if (value)
		out << "\"" << value << "\",";
	else
		out << "\"\",";
}

void unknown7da260(ostream &out, float value, int unknown1, int unknown2)
{
	if (value != 0)
		out << "\"" << floatToString(value,unknown1,unknown2) << "\",";
	else
		out << "\"\",";
}
