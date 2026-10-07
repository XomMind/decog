// team_a_18: savepng write callback (0x413f20), a 12-byte record copy constructor (0x454300) and a by-value
// result wrapper (0x4326e0), a second copy of the OpR2D_Rec57f0b0 reader (0x4374f0) and the crash-log stack dump (0x421d20).
// NOTE: names and layouts are placeholders.
#include <stdio.h>
#include <vector>
#include <istream>
#include <string>
using namespace std;

struct SDL_RWops
{
	int (*seek)(SDL_RWops *context, int offset, int whence);
	int (*read)(SDL_RWops *context, void *ptr, int size, int maxnum);
	int (*write)(SDL_RWops *context, const void *ptr, int size, int num);
	int (*close)(SDL_RWops *context);
};

extern void *(*png_get_io_ptr_b6159c)(void *png);	// NOTE: placeholder name (libpng import by ordinal, IAT slot 0xb6159c)

void pngWriteData_413f20(void *png, unsigned char *data, unsigned int length)	// NOTE: placeholder name (savepng write callback)
{
	SDL_RWops *dst = (SDL_RWops *)png_get_io_ptr_b6159c(png);
	dst->write(dst,data,1,length);
}

struct Field_454300	// NOTE: placeholder name (4-byte value copied as a unit)
{
	int value;
};

struct Triple_454300	// NOTE: placeholder name (12-byte record; the exe folds several pair/record copy constructors here)
{
	Field_454300 a;
	int b;
	int c;
	Triple_454300(const Triple_454300 &o);
};

Triple_454300::Triple_454300(const Triple_454300 &o)
	: a(o.a), b(o.b), c(o.c)
{
}

struct Bytes4_4326b0	// NOTE: placeholder name (team_a_07.cpp)
{
	char a;
	char b;
	char c;
	char d;
	Bytes4_4326b0();
};

struct Result_4326e0	// NOTE: placeholder name (returned by value; has a destructor)
{
	int value;
	~Result_4326e0();
};

Result_4326e0 makeResult_a43bf0(int a, int b, const Bytes4_4326b0 &flags);	// NOTE: placeholder name

Result_4326e0 makeResult_4326e0(int a, int b)	// NOTE: placeholder name
{
	return makeResult_a43bf0(a,b,Bytes4_4326b0());
}


struct OpQ5_T9cf200;
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name

struct ObjList_4374f0	// NOTE: placeholder name (same shape as OpR2D_Rec57f0b0, a second copy in the exe)
{
	vector<OpQ5_T9cf200 *> objects;
	ObjList_4374f0(istream &stream);
};

ObjList_4374f0::ObjList_4374f0(istream &stream)
{
	OpQ5_readObjects(stream,objects,0);
}


extern FILE *crashLog_cefaa4;	// NOTE: placeholder name (0xcefaa4)
extern int inStackDump_d3bef8;	// NOTE: placeholder name (0xd3bef8)

void dumpStack_421d20(unsigned long faultAddress, unsigned char *stackFrame)	// NOTE: placeholder name
{
	unsigned char *p;
	unsigned int count;
	unsigned int i;
	int failed;
	unsigned long *f;

	if (inStackDump_d3bef8)
	{
		fprintf(crashLog_cefaa4,"\n***\n*** Recursive Stack Dump skipped\n***\n");
		return;
	}
	fprintf(crashLog_cefaa4,"****************************************************\n");
	fprintf(crashLog_cefaa4,"*** CallStack:\n");
	fprintf(crashLog_cefaa4,"****************************************************\n");
	inStackDump_d3bef8 = 1;
	failed = stackFrame != 0;
	if (stackFrame == 0)
	{
		__asm mov stackFrame, ebp
	}
	else
		fprintf(crashLog_cefaa4,"\n  Fault Occured At $ADDRESS:%08LX\n",faultAddress);
	for (i = 0; stackFrame != 0 && i < 100; i++)
	{
		f = (unsigned long *)stackFrame;
		stackFrame = (unsigned char *)f[0];
		p = (unsigned char *)(f + 2);
		fprintf(crashLog_cefaa4,"         with ");
		for (count = 0; p < stackFrame && count < 20; p++, count++)
			fprintf(crashLog_cefaa4,"%02X ",*p);
		fprintf(crashLog_cefaa4,"\n\n");
		if (i == 1 && !failed)
			fprintf(crashLog_cefaa4,"****************************************************\n         Fault Occured Here:\n");
		fprintf(crashLog_cefaa4,"*** %2d called from $ADDRESS:%08X\n",i,f[1]);
		if (f[1] == 0)
			break;
	}
	fprintf(crashLog_cefaa4,"************************************************************\n");
	fprintf(crashLog_cefaa4,"\n\n");
	inStackDump_d3bef8 = 0;
	fflush(crashLog_cefaa4);
}


void OpX5_fillChars(char *p, unsigned int count, char value);	// NOTE: placeholder name
extern char keyFlags_cec14c[4];	// NOTE: placeholder name (0xcec14c)
extern int keyCodes_cec458[0x143];	// NOTE: placeholder name (0xcec458)

class Input_416060	// NOTE: placeholder name (keyboard/mouse state, built during REX setup)
{
public:
	vector<unsigned int> unknown0;
	vector<bool> unknown10;
	vector<bool> unknown24;
	bool unknown38;
	vector<unsigned int> unknown3c;
	int unknown4c;
	int unknown50;
	int unknown54;
	bool unknown58;
	int unknown5c;
	int unknown60;
	bool unknown64;
	int unknown68;
	int unknown6c;
	int unknown70;
	int unknown74;
	int unknown78;
	int unknown7c;
	vector<int> unknown80;
	vector<int> unknown90;
	Input_416060();
};

Input_416060::Input_416060()
	: unknown38(false), unknown4c(0), unknown50(0), unknown54(-1), unknown58(false), unknown5c(0), unknown60(0),
	  unknown64(false), unknown68(0), unknown6c(-1), unknown70(-1), unknown74(0), unknown78(0), unknown7c(0)
{
	OpX5_fillChars(keyFlags_cec14c,4,0);
	for (int i = 0; i < 0x143; i++)
		keyCodes_cec458[i] = i;
	unknown80.assign(2u,0);
	unknown90.assign(2u,0);
}


struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &color) throw();	// 0x411e30
};
extern XColor color_d29804;	// NOTE: placeholder name (0xd29804)

struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_);	// 0x46ca20
	Pos(int v);	// 0x409990
};

struct XCell;
template <class T> class Array2D	// NOTE: placeholder name
{
public:
	int getWidth();
	int getHeight();
};

class AsciiImage
{
public:
	vector<Array2D<XCell> *> frames;	// NOTE: placeholder layout
};

int halfDiff_437190(int a, int b);	// NOTE: placeholder name (team_a_07.cpp)

class XConsole
{
public:
	virtual ~XConsole();
	int getHeight();	// 0x4174c0
	int getWidth_44b0d0();	// NOTE: placeholder name
	void setFgColor(XColor color) throw();	// 0x4183d0
	void resetBack_418450() throw();	// NOTE: placeholder name
};

class ConsoleArt : public XConsole
{
public:
	ConsoleArt(XConsole *parent, AsciiImage *art, int x, int y, bool hidden, int layer, int frame, const Pos &offset, int width, int height);	// 0x48c7e0
	char pad[0x84 - 4];
};

class CTitleAnimated : public ConsoleArt
{
public:
	CTitleAnimated(XConsole *parent, AsciiImage *art, int unknown84_, int frame);	// 0x4b28f0

	int unknown84;	// NOTE: placeholder name
};

// CTitleAnimated::CTitleAnimated (0x4b28f0) is defined in cc_r2_21.cpp.

class OpX5C_EngineItem;
struct Point;

class OpR2b_Engine
{
public:
	void stopAll();
	OpX5C_EngineItem *unknown50fb50(OpR2b_Engine *engine, int type, const struct Pos &a, Point *b, int c, int d, int value);	// NOTE: placeholder name
};

struct OpW2_WeaponRef	// NOTE: placeholder layout
{
	char pad[8];
	bool unknown8;
};

class Console_4afab0	// NOTE: placeholder (Console's virtual interface up to trigger)
{
public:
	virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
	virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
	virtual void v20(); virtual void v24(); virtual void v28();
	virtual void trigger(const string &command, int value);
	void clear();	// 0x417bc0 (XConsole::clear)
	char pad04[0x64 - 4];
	OpR2b_Engine *engine;
	void *title;
};

class CMachineTarget : public Console_4afab0
{
public:
	void unknown4afab0(int state_);	// NOTE: placeholder name (sets state)

	bool unknown6c;	// NOTE: placeholder name
	OpW2_WeaponRef *record;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
	int key;	// NOTE: placeholder name
	int state;	// NOTE: placeholder name
};

void CMachineTarget::unknown4afab0(int state_)
{
	if (state != state_)
	{
		state = state_;
		clear();
		engine->stopAll();
		trigger(string("content"),0);
		if (state == 2)
			record->unknown8 = true;
	}
}

struct Point;
extern Point opX5D_cfbec0;	// NOTE: placeholder name

class OpX5C_EngineItem	// NOTE: placeholder name (declared earlier)
{
public:
	void unknown50de10();	// NOTE: placeholder name
};


extern int anim_cebf68;	// NOTE: placeholder name (CInfoButton_Bracket)
extern int anim_cebf08;	// NOTE: placeholder name (CInfoButton_Text)
extern int anim_cebf4c;	// NOTE: placeholder name (CInfoButton_Key)

#define INFOBUTTON_ANIM(type, pos) do { engine->unknown50fb50(engine,type,pos,&opX5D_cfbec0,0,0,9)->unknown50de10(); } while (0)

class InfoButton_4ae610	// NOTE: placeholder name (a CInfo button console)
{
public:
	int getWidth_44b0d0();	// NOTE: placeholder name
	void animateFrame();	// NOTE: placeholder name

	char pad0[0x64];
	OpR2b_Engine *engine;
};

void InfoButton_4ae610::animateFrame()
{
	INFOBUTTON_ANIM(anim_cebf68,Pos(0,0));
	INFOBUTTON_ANIM(anim_cebf4c,Pos(1,0));
	do
	{
		for (int x = Pos(2,0).x; x < Pos(2,0).x + getWidth_44b0d0() - 3; x++)
			engine->unknown50fb50(engine,anim_cebf08,Pos(x,Pos(2,0).y),&opX5D_cfbec0,0,0,9)->unknown50de10();
	} while (0);
	INFOBUTTON_ANIM(anim_cebf68,Pos(getWidth_44b0d0() - 1,0));
}


extern string gameStrings_d35ce8[];
extern int uploadResult_d2cce8;	// NOTE: placeholder name (0xd2cce8)
extern bool opY2_networkAvailable;	// NOTE: placeholder name (0xcefb3f)
extern vector<int> networkThreadTypes;	// NOTE: placeholder name (0xd16178)
extern bool uploadSucceeded_cefb58;	// NOTE: placeholder name (0xcefb58)
bool containsValue_ints(vector<int> &v, int value);	// NOTE: placeholder name (0x9d55a0 area, folded with OpX5_containsRecord)

class OpR2b_Engine_48fd20	// NOTE: placeholder (OpR2b_Engine; separate name to keep this file's Engine declaration simple)
{
public:
	void render();
};

class Console_48fd20	// NOTE: placeholder (Console's virtual interface up to render)
{
public:
	virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
	virtual void v10(); virtual void v14(); virtual void v18();
	virtual void render();
	void clearChars();	// 0x417d80
	int getWidth_44b0d0();	// NOTE: placeholder name
	void printAligned(int x, int y, int align, const string &text);	// 0x418220
	char pad04[0x64 - 4];
	OpR2b_Engine_48fd20 *engine;
};

class CGameoverUpload : public Console_48fd20
{
public:
	virtual void render();
};

void CGameoverUpload::render()
{
	clearChars();
	string text;
	if (uploadResult_d2cce8)
		text = gameStrings_d35ce8[uploadResult_d2cce8];
	else if (!opY2_networkAvailable)
		text = "(no network connection for upload)";
	else if (containsValue_ints(networkThreadTypes,3))
		text = "(uploading score...)";
	else if (!uploadSucceeded_cefb58)
		text = "(score upload failed)";
	else
		text = "Uploaded-> gridsagegames.com/cogmind/scores/";
	printAligned(getWidth_44b0d0() / 2,0,1,text);
	engine->render();
}
