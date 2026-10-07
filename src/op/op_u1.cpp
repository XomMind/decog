// op_u1: misc functions in 0x409000-0x4c5000
#include "engine/xconsole.h"
#include <map>
#include <iterator>

//==================================================================
// destructors of data records
//==================================================================

class OpU1_Unk416bf0	// NOTE: placeholder name
{
public:
	string name;
	vector<unsigned int> v1;
	char pad[0xc];
	vector<unsigned int> v2;
	vector<unsigned int> v3;
	vector<unsigned int> v4;
	vector<unsigned int> v5;
	vector<unsigned int> v6;
	~OpU1_Unk416bf0();	// 0x416bf0
};

OpU1_Unk416bf0::~OpU1_Unk416bf0()
{
}

class OpU1_Obj9cec20	// NOTE: placeholder name
{
public:
	char pad[0xc];
	~OpU1_Obj9cec20();	// 0x9cec20
};

class OpU1_Obj9b44c0	// NOTE: placeholder name
{
public:
	char pad[0x10];
	~OpU1_Obj9b44c0();	// 0x9b44c0
};

class OpU1_Unk418e60	// NOTE: placeholder name
{
public:
	char pad0[0x24];
	string s24;
	string s40;
	char pad1[0x14];
	OpU1_Obj9cec20 o70;
	string s7c;
	char pad2[4];
	OpU1_Obj9b44c0 o9c;
	vector<unsigned int> vac;
	vector<unsigned int> vbc;
	char pad3[0x14];
	string se0;
	char pad4[4];
	string s100;
	char pad5[0x34];
	string s150;
	string s16c;
	int m188;
	~OpU1_Unk418e60();	// 0x418e60
};

OpU1_Unk418e60::~OpU1_Unk418e60()
{
}

struct OpU1_Glyph	// NOTE: placeholder name
{
	char data[0x10];
};

class OpU1_FontInfo	// NOTE: placeholder name
{
public:
	char pad0[0x10];
	vector<unsigned int> v10;
	map<char,OpU1_Glyph> m20;
	vector<OpU1_Glyph> v30;
	~OpU1_FontInfo();	// 0x425ae0
};

OpU1_FontInfo::~OpU1_FontInfo()
{
}

//==================================================================
// small helpers
//==================================================================

struct OpU1_Point	// NOTE: placeholder name
{
	int x;
	int y;
	void read(istream &stream);	// 0x40a330
	void write(ostream &stream);	// 0x40a370
};

void OpU1_Point::read(istream &stream)
{
	stream.read((char*)&x,4);
	stream.read((char*)&y,4);
}

void OpU1_Point::write(ostream &stream)
{
	stream.write((char*)&x,4);
	stream.write((char*)&y,4);
}

struct OpU1_Rect	// NOTE: placeholder name
{
	int x;
	int y;
	int width;
	int height;
	OpU1_Rect() throw();	// 0x40a6e0
	OpU1_Rect &operator=(const OpU1_Rect &rect);	// 0x40a720
	void set(int x_, int y_, int width_, int height_);	// 0x40a840
	OpU1_Rect *read(istream &stream);	// 0x434340
};

OpU1_Rect *OpU1_Rect::read(istream &stream)
{
	readBinary(stream,&x);
	readBinary(stream,&y);
	readBinary(stream,&width);
	readBinary(stream,&height);
	return this;
}

struct Point	// NOTE: placeholder name
{
	int x;
	int y;
};

class Area	// NOTE: placeholder layout
{
public:
	Point min;
	Point max;
	bool contains_40b750(const Point &p);	// NOTE: placeholder name
};

bool opU1_anyAreaContains(vector<Area> &areas, const Point &p)	// NOTE: placeholder name (0x436d30)
{
	for (unsigned int i = 0; i < areas.size(); i++)
	{
		if (areas[i].contains_40b750(p))
			return true;
	}
	return false;
}

class OpU1_Rex	// NOTE: placeholder name (REX at 0xd223f0)
{
public:
	int getWidth_418980();	// NOTE: placeholder name
	int getHeight_4189a0();	// NOTE: placeholder name
	int getDesktopWidth_9b6bf0();	// NOTE: placeholder name
	int getDesktopHeight_44afb0();	// NOTE: placeholder name
};

void logMessage(string message);	// 0x404cb0

bool opU1_checkFontSetFits(int cols, int rows, int mode, bool *removed)	// NOTE: placeholder name (0x42f530)
{
	if (((OpU1_Rex*)&rex)->getWidth_418980() * cols > ((OpU1_Rex*)&rex)->getDesktopWidth_9b6bf0() || ((OpU1_Rex*)&rex)->getHeight_4189a0() * rows > ((OpU1_Rex*)&rex)->getDesktopHeight_44afb0())
	{
		switch (mode)
		{
			case 0:
				logMessage("   (set removed, resolution exceeds desktop)");
				return false;
			case 1:
				logMessage("   (set resolution exceeds desktop, but including for other potential applications)");
				*removed = true;
		}
	}
	return true;
}

bool opU1_contains9db330(vector<XConsole*> *list, XConsole *value);	// NOTE: placeholder name (0x9db330)

class OpU1_Console : public XConsole	// NOTE: placeholder name
{
public:
	void getPixelRect(OpU1_Rect *rect);	// 0x4286b0
	void unknown429f10(vector<XConsole*> *exclude, bool flag);	// NOTE: placeholder name
	void unknown429fe0(XConsole *console, Pos *pos, OpU1_Rect *source);	// NOTE: placeholder name
};

void OpU1_Console::unknown429f10(vector<XConsole*> *exclude, bool flag)
{
	if (!subconsoles.empty())
	{
		for (unsigned int i = 0; i < subconsoles.size(); i++)
		{
			if (subconsoles[i]->font == font)
			{
				if (exclude == NULL || !opU1_contains9db330(exclude,subconsoles[i]))
					((OpU1_Console*)subconsoles[i])->unknown429f10(exclude,true);
			}
		}
	}
	if (flag)
		unknown429fe0(parent,&pos,NULL);
}

void OpU1_Console::getPixelRect(OpU1_Rect *rect)
{
	rect->set(absPos.x,absPos.y,getWidth() * FONT_TYPE_WIDTH[fontType],getHeight() * FONT_TYPE_HEIGHT[fontType]);
}

struct OpU1_Cell : public XCell	// NOTE: placeholder name
{
	void setFont(int font_);	// 0x4280e0
};

void OpU1_Cell::setFont(int font_)
{
	font = font_;
	glyph = fontCharmaps[font]->at(ch);
}

class OpU1_Unk426b90	// NOTE: placeholder name
{
public:
	char pad0[0x70];
	Array2D<XCell> grid;
	void clearGrid();	// 0x426b90
};

void OpU1_Unk426b90::clearGrid()
{
	grid.fill(XCell(0,0,COLOR_BLACK,COLOR_BLACK));
}

//==================================================================
// string helpers
//==================================================================

bool opU1_splitAfterChar(string &text, char separator, string &rest)	// NOTE: placeholder name (0x4090e0)
{
	if (text.empty())
		return false;

	unsigned int index = text.find(separator,0);
	if (index == string::npos || index == text.size() - 1)
		return false;

	rest.assign((const string::const_iterator &)(text.begin() + index + 1),(const string::const_iterator &)text.end());	// the non-template assign(const_iterator, const_iterator)
	return true;
}

struct PHYSFS_File;
namespace PhysFScpp
{
	class base_fstream
	{
	protected:
		PHYSFS_File * const file;
	public:
		base_fstream(PHYSFS_File *file);
		virtual ~base_fstream();
	};

	class ifstream : public base_fstream, public std::istream
	{
	public:
		ifstream(string const &filename, std::ios_base::openmode mode = std::ios_base::in);
		virtual ~ifstream();
	};
}

void opU1_readAll(PhysFScpp::ifstream *file, string &text)	// NOTE: placeholder name (0x409600)
{
	text.assign(istreambuf_iterator<char>(*file),istreambuf_iterator<char>());
}


bool opU1_extractParens(string &text, string &inside)	// NOTE: placeholder name (0x436d80)
{
	unsigned int start = text.find('(',0);
	unsigned int end = text.find(')',0);
	if (start != string::npos)
	{
		if (end == string::npos)
			return false;

		inside.assign(text.begin() + start + 1,text.begin() + end);
		text.erase(text.begin() + start,text.end());
	}
	return true;
}
