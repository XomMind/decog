// Lead cluster c045: small Console subclasses (ctors, dtors and helpers) at 0x4959c0-0x497670.
// NOTE: all class and member names are placeholders (named after the vtable / address).
#include <string>
#include <vector>
#include "engine/xcolor.h"
using namespace std;

struct Pos
{
	int x;
	int y;
};

class Engine
{
public:
	void killGroup(string group);
};

class XConsole
{
public:
	virtual ~XConsole();

	bool contains(const Pos &pos);	// NOTE: placeholder name
	int getWidth();
	int getHeight();
	void setFore(XColor color) throw();
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	void setForeAll_4183d0(XColor color);	// NOTE: placeholder name
	void putChar_4180b0(int x, int y, int ch);	// NOTE: placeholder name
	void print(int x, int y, const string &text);	// NOTE: placeholder name
	int printWrapped_418260(int x, int y, int width, int height, const string &text);	// NOTE: placeholder name
	void clear();	// NOTE: placeholder name
	vector<XConsole*> *getSubconsoles();

	char pad4[0x60 - 4];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();

	void animate(string name);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	void *title;
};

class Calls_48c3c0
{
public:
	int delegate(int arg0);
};
#define SET_COLOR(console, value)	(((Calls_48c3c0 *)(console))->delegate(value))

class PushBounds
{
public:
	Pos topLeft();
};
extern PushBounds *unknown_cefa94;	// NOTE: placeholder name

extern int unknown_cef788;	// NOTE: placeholder name
extern int unknown_cef790;	// NOTE: placeholder name
extern int unknown_cef794[];	// NOTE: placeholder name
extern int unknown_cef814;	// NOTE: placeholder name
extern int unknown_cef840;	// NOTE: placeholder name
extern int unknown_cef844;	// NOTE: placeholder name
extern int unknown_cef848[];	// NOTE: placeholder name
extern int unknown_cef8dc;	// NOTE: placeholder name
extern int unknown_cef950;	// NOTE: placeholder name
extern int unknown_cef988[];	// NOTE: placeholder name
extern int unknown_cef9a0;	// NOTE: placeholder name
extern XColor *unknown_cf44c0;	// NOTE: placeholder name
extern XColor *unknown_d2981c;	// NOTE: placeholder name
extern XColor *unknown_d25f60;	// NOTE: placeholder name
extern string unknown_d20a78[];	// NOTE: placeholder name
extern string unknown_d31520[];	// NOTE: placeholder name
extern string unknown_d397b8[];	// NOTE: placeholder name
extern int unknown_cec040;	// NOTE: placeholder name

//==================================================================
// 0x4959c0: sets four colors
//==================================================================

class Unknown_4959c0 : public Console
{
public:
	void setColors();	// 0x4959c0

	char pad6c[0x74 - sizeof(Console)];
	Console *unknown74;	// NOTE: placeholder name
	Console *unknown78;	// NOTE: placeholder name
	Console *unknown7c;	// NOTE: placeholder name
};

void Unknown_4959c0::setColors()
{
	SET_COLOR(this,unknown_cef9a0);
	SET_COLOR(unknown74,unknown_cef840);
	SET_COLOR(unknown78,unknown_cef950);
	SET_COLOR(unknown7c,unknown_cef814);
}

//==================================================================
// vtable 0xc34b30: text label
//==================================================================

class Unknown_c34b30 : public Console
{
public:
	Unknown_c34b30(XConsole *parent, int x, int y, const string &text);	// 0x495a10
};

Unknown_c34b30::Unknown_c34b30(XConsole *parent, int x, int y, const string &text)
	: Console(parent,text.size(),1,x,y,0,false,-1)
{
	print(0,0,text);
}

//==================================================================
// 0x496180: highlight state
//==================================================================

class Unknown_496180 : public Console
{
public:
	void setHighlight();	// 0x496180

	int unknown6c;	// NOTE: placeholder name
	Console *unknown70;	// NOTE: placeholder name
	Console *unknown74;	// NOTE: placeholder name
	Console *unknown78;	// NOTE: placeholder name
	Console *unknown7c;	// NOTE: placeholder name
	char pad80[0x88 - 0x80];
	bool unknown88;	// NOTE: placeholder name
};

void Unknown_496180::setHighlight()
{
	bool flag = (unknown6c == 1 && !unknown88);
	SET_COLOR(this,flag ? unknown_cef790 : unknown_cef9a0);
	SET_COLOR(unknown70,flag ? unknown_cef790 : unknown_cef840);
	SET_COLOR(unknown74,flag ? unknown_cef790 : unknown_cef950);
	if (unknown78)
		SET_COLOR(unknown78,flag ? unknown_cef790 : unknown_cef844);
	SET_COLOR(unknown7c,flag ? unknown_cef790 : unknown_cef814);
}

//==================================================================
// vtable 0xc34b98
//==================================================================

class Unknown_c34b98 : public Console
{
public:
	Unknown_c34b98(XConsole *parent, int x, int y, int width, int height, int value);	// 0x4962a0
	void setColor();	// 0x4962f0

	int unknown6c;	// NOTE: placeholder name
};

Unknown_c34b98::Unknown_c34b98(XConsole *parent, int x, int y, int width, int height, int value)
	: Console(parent,width,height,x,y,0,false,-1)
{
	unknown6c = value;
}

void Unknown_c34b98::setColor()
{
	SET_COLOR(this,unknown_cef988[unknown6c]);
}

//==================================================================
// vtable 0xc34bcc
//==================================================================

class Unknown_c34bcc : public Console
{
public:
	Unknown_c34bcc(XConsole *parent, int x, int y, int width, int height, int value);	// 0x496320
	void setColor();	// 0x496370

	int unknown6c;	// NOTE: placeholder name
};

Unknown_c34bcc::Unknown_c34bcc(XConsole *parent, int x, int y, int width, int height, int value)
	: Console(parent,width,height,x,y,0,false,-1)
{
	unknown6c = value;
}

void Unknown_c34bcc::setColor()
{
	SET_COLOR(this,unknown_cef848[unknown6c]);
}

//==================================================================
// vtable 0xc34c00
//==================================================================

class Unknown_c34c00 : public Console
{
public:
	Unknown_c34c00(XConsole *parent, int x, int y, int width, int height);	// 0x4963a0
};

Unknown_c34c00::Unknown_c34c00(XConsole *parent, int x, int y, int width, int height)
	: Console(parent,width,height,x,y,4,false,-1)
{
}

//==================================================================
// vtable 0xc34c34
//==================================================================

class Unknown_c34c34 : public Console
{
public:
	Unknown_c34c34(XConsole *parent, int x, int y, int index);	// 0x496400

	int unknown6c;	// NOTE: placeholder name
};

Unknown_c34c34::Unknown_c34c34(XConsole *parent, int x, int y, int index)
	: Console(parent,unknown_d20a78[index].size() + 2,1,x,y,0,false,-1)
{
	unknown6c = index;
	putChar_4180b0(0,0,'[');
	print(1,0,unknown_d20a78[unknown6c]);
	putChar_4180b0(getWidth() - 1,0,']');
	SET_COLOR(this,unknown_cef788);
}

//==================================================================
// vtable 0xc34c68
//==================================================================

class Unknown_c34c68 : public Console
{
public:
	Unknown_c34c68(XConsole *parent, int x, int y, int width, int height, int value);	// 0x496950
	void setColor();	// 0x4969a0

	int unknown6c;	// NOTE: placeholder name
};

Unknown_c34c68::Unknown_c34c68(XConsole *parent, int x, int y, int width, int height, int value)
	: Console(parent,width,height,x,y,0,false,-1)
{
	unknown6c = value;
}

void Unknown_c34c68::setColor()
{
	SET_COLOR(this,unknown_cef794[unknown6c]);
}

//==================================================================
// vtable 0xc34c9c
//==================================================================

class Unknown_c34c9c : public Console
{
public:
	Unknown_c34c9c(XConsole *parent, int x, int y, bool flag);	// 0x4969d0

	bool unknown6c;	// NOTE: placeholder name
};

Unknown_c34c9c::Unknown_c34c9c(XConsole *parent, int x, int y, bool flag)
	: Console(parent,5,1,x,y,0,false,-1)
{
	unknown6c = flag;
	setFore(*unknown_d2981c);
}

//==================================================================
// vtable 0xc34d38: bracketed label
//==================================================================

class Unknown_c34d38 : public Console
{
public:
	Unknown_c34d38(XConsole *parent, int x, int y, int index);	// 0x496c90
	void hoverEnd();	// 0x496e10
	void hoverBegin();	// 0x496e60

	int unknown6c;	// NOTE: placeholder name
	bool unknown70;	// NOTE: placeholder name
};

Unknown_c34d38::Unknown_c34d38(XConsole *parent, int x, int y, int index)
	: Console(parent,unknown_d31520[index].size() + 2,1,x,y,0,false,-1)
{
	unknown6c = index;
	unknown70 = false;
	setFore(*unknown_cf44c0);
	print(0,0,"[");
	print(getWidth() - 1,0,"]");
	setFore(*unknown_d2981c);
	print(1,0,unknown_d31520[unknown6c]);
	setFore_417f80(1,0,*unknown_d25f60);
}

void Unknown_c34d38::hoverEnd()
{
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_MANU_HOV_OK");
}

void Unknown_c34d38::hoverBegin()
{
	setForeAll_4183d0(*unknown_cf44c0);
	unknown70 = true;
}

//==================================================================
// 0x4964e0 / 0x497560: hover animations
//==================================================================

class Unknown_4964e0 : public Console
{
public:
	bool hoverBegin();	// 0x4964e0
};

bool Unknown_4964e0::hoverBegin()
{
	animate("A_ButtonHover_Begin_CMOD_HOV_OK");
	return true;
}

class Unknown_497560 : public Console
{
public:
	void hoverEnd();	// 0x497560
};

void Unknown_497560::hoverEnd()
{
	engine->killGroup("fadein");
	animate("A_Gallery_Item_HOV_DONE");
}

//==================================================================
// vtable 0xc34a60: many id lists
//==================================================================

class Unknown_c34a60 : public Console
{
public:
	virtual ~Unknown_c34a60();	// 0x496590
	unsigned int getValue(unsigned int key);	// 0x496730
	void setText(int index);	// 0x496770
	int clearText();	// 0x496810

	char pad6c[0x70 - sizeof(Console)];
	vector<unsigned int> unknown70;	// NOTE: placeholder name
	vector<unsigned int> unknown80;	// NOTE: placeholder name
	vector<unsigned int> unknown90;	// NOTE: placeholder name
	vector<unsigned int> unknownA0;	// NOTE: placeholder name
	char padB0[0xb4 - 0xb0];
	vector<unsigned int> unknownB4;	// NOTE: placeholder name
	char padC4[0xd4 - 0xc4];
	vector<unsigned int> unknownD4;	// NOTE: placeholder name
	char padE4[0xe8 - 0xe4];
	vector<unsigned int> unknownE8;	// NOTE: placeholder name
	char padF8[0x10c - 0xf8];
	vector<unsigned int> unknown10c;	// NOTE: placeholder name
	vector<unsigned int> unknown11c;	// NOTE: placeholder name
	vector<unsigned int> unknown12c;	// NOTE: placeholder name
	XConsole *unknown13c;	// NOTE: placeholder name
	char pad140[0x14c - 0x140];
	vector<unsigned int> unknown14c;	// NOTE: placeholder name
	char pad15c[0x160 - 0x15c];
	vector<unsigned int> unknown160;	// NOTE: placeholder name
	vector<unsigned int> unknown170;	// NOTE: placeholder name
	vector<unsigned int> unknown180;	// NOTE: placeholder name
	char pad190[0x19c - 0x190];
	vector<unsigned int> unknown19c;	// NOTE: placeholder name
	vector<unsigned int> unknown1ac;	// NOTE: placeholder name
	vector<unsigned int> unknown1bc;	// NOTE: placeholder name
};

unsigned int unknown_9d4660(vector<unsigned int> *list, unsigned int key);	// NOTE: placeholder name

Unknown_c34a60::~Unknown_c34a60()
{
}

unsigned int Unknown_c34a60::getValue(unsigned int key)
{
	return unknown11c[unknown_9d4660(&unknown12c,key)];
}

int Unknown_c34a60::clearText()
{
	if (unknown13c->getSubconsoles()->empty())
	{
		unknown13c->clear();
		return 0;
	}
	(*unknown13c->getSubconsoles())[0]->clear();
	return 0;
}

void Unknown_c34a60::setText(int index)
{
	clearText();
	XConsole *console = unknown13c->getSubconsoles()->empty() ? unknown13c : (*unknown13c->getSubconsoles())[0];
	console->printWrapped_418260(0,0,console->getWidth(),console->getHeight(),unknown_d397b8[index]);
	SET_COLOR(console,unknown_cef8dc);
}

//==================================================================
// 0x496560 / vtable 0xc34e08
//==================================================================

class Unknown_496560 : public Console
{
public:
	int unknown_496540();	// NOTE: placeholder name
	int unknown_7c6830();	// NOTE: placeholder name
	int getRange();	// 0x496560
};

int Unknown_496560::getRange()
{
	return unknown_496540() - unknown_7c6830() + 1;
}

struct Unknown_497670Item	// NOTE: placeholder name
{
	char pad[0x78];
	XConsole *unknown78;	// NOTE: placeholder name
};

class Unknown_c34e08 : public Console
{
public:
	virtual ~Unknown_c34e08();	// 0x4975d0
	XConsole *findHovered();	// 0x497670

	char pad6c[0x74 - sizeof(Console)];
	vector<Unknown_497670Item*> unknown74;	// NOTE: placeholder name
	vector<unsigned int> unknown84;	// NOTE: placeholder name
	vector<unsigned int> unknown94;	// NOTE: placeholder name
	vector<Unknown_497670Item*> unknownA4;	// NOTE: placeholder name
};

Unknown_c34e08::~Unknown_c34e08()
{
	unknown_cec040 = 0;
}

XConsole *Unknown_c34e08::findHovered()
{
	for (unsigned int i = 0; i < unknownA4.size(); i++)
	{
		if (unknownA4[i]->unknown78->contains(unknown_cefa94->topLeft()))
			return unknownA4[i]->unknown78;
	}
	return NULL;
}
