// op_w1_searchitem: CSearchItem::CSearchItem (0x4ab780), one row of the search results list
// (COGMIND.exe Beta 17.1). The class mirrors the declaration in op_w1.cpp so both TUs emit the same vtable.
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor() throw();	// 0x411d40
	XColor(const XColor &c) throw();	// 0x411e30
	bool operator!=(XColor other);	// 0x411f90
	XColor operator*(float f);	// 0x412050
};
XColor opr1c_getScoreColor(int value);	// 0x4348a0

struct Point
{
	int x;
	int y;
	Point(const Point &p) throw();	// 0x46ca50
};

struct OpSI_Result : public Point	// NOTE: placeholder name (OpW1_Result)
{
	int distance;
};

class XEvent;

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool isActive();
	virtual void refresh();
	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int modifier);	// NOTE: placeholder name
	virtual void update();
	virtual void render();

	int getWidth();	// 0x44b0d0
	void putChar_418110(int x, int y, int ch, XColor fore);
	void setFore(XColor color);
	void setForeRow(int x, int y, int width, XColor color);
	void print(int x, int y, const string &text);
	void printAligned(int x, int y, int alignment, const string &text);

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);

	int unknown60;
	void *engine;
	void *title;
};

class CSearchItem : public Console
{
public:
	CSearchItem(XConsole *parent, int y, OpSI_Result *result, int mode_, int index);
	virtual bool input(XEvent *event);
	virtual void update();

	int unknown6c;
	Point pos;	// NOTE: placeholder name
	int mode;	// NOTE: placeholder name
};

struct OpSI_Cell	// NOTE: placeholder name (0x34 bytes)
{
	int glyph;
	int pad04;
	XColor color;	// +0x08
	char pad0b[0x10 - 0x0b];
	int type;	// +0x10
	int count;	// +0x14
	int integrity;	// +0x18
	int pad1c;
	int kind;	// +0x20
};

template<class T> class OpX5_Array2D
{
public:
	T *atPoint(Point &p);
};
struct OpX5_S34 { char b[0x34]; };	// NOTE: placeholder name

class OpSI_World	// NOTE: placeholder name (BS at 0xcefc4c)
{
public:
	OpX5_Array2D<OpX5_S34> *unknown463e70();	// NOTE: placeholder name
	bool isVisible(const Point &pos);	// NOTE: placeholder name (0x4631c0)
};
extern OpSI_World *opSI_world;	// NOTE: placeholder name

class OpSI_Record	// NOTE: placeholder name (item record)
{
public:
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
	void describe_5705b0(string &out, XColor &color);	// NOTE: placeholder name
	char pad00[0x44];
	int category;	// +0x44
};
extern vector<OpSI_Record *> opSI_records_d2d1c4;	// NOTE: placeholder name
extern vector<int> opSI_known_cf4830;	// NOTE: placeholder name

extern XColor *opSI_d386c8;	// NOTE: placeholder name
extern XColor *opSI_cfc174;	// NOTE: placeholder name
extern XColor *opSI_d29758;	// NOTE: placeholder name
extern XColor *opSI_d22fcc;	// NOTE: placeholder name
extern XColor *opSI_d204ac;	// NOTE: placeholder name
extern XColor *opSI_d1dae0;	// NOTE: placeholder name
extern XColor *opSI_d2981c;	// NOTE: placeholder name
extern XColor *opSI_d2175c;	// NOTE: placeholder name
extern XColor *opSI_cf44c0;	// NOTE: placeholder name
extern XColor *opSI_cfe674;	// NOTE: placeholder name
extern bool opSI_ascii_d28d30;	// NOTE: placeholder name
extern int opSI_infoMode_d28d68;	// NOTE: placeholder name
extern int opSI_barEnd_bcc2e0;	// NOTE: placeholder name
extern int opSI_barWidth_bcc2e4;	// NOTE: placeholder name
extern const float opSI_dim_bcc2e8;	// NOTE: placeholder name

string intToString(int value);	// 0x4051f0
string &padLeft_408090(string &s, unsigned int width, char c);	// NOTE: placeholder name
string &padRight_4080d0(string &s, unsigned int width, char c);	// NOTE: placeholder name
bool opw6_truncate408220(string &text, unsigned int length, int unknown);	// NOTE: placeholder name
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name
int ops7_clamp_9cdc80(int low, int value, int high);	// NOTE: placeholder name

class TeamOct08CharlieString
{
public:
	void assign9af390(const char *s);
};

CSearchItem::CSearchItem(XConsole *parent, int y, OpSI_Result *result, int mode_, int index)
	: Console(parent,parent->getWidth() - 4,1,2,y,0,false,-1)
	, unknown6c(index)
	, pos(*result)
	, mode(mode_)
{
	OpSI_Cell *cell = (OpSI_Cell *)opSI_world->unknown463e70()->atPoint(pos);
	if (mode == 0)
	{
		setFore(opSI_world->isVisible(pos) ? *opSI_d386c8 : (result->distance <= 20 ? *opSI_cfc174 : (result->distance <= 50 ? *opSI_d29758 : *opSI_d22fcc)));
		string distance(result->distance > 999 ? string("***") : intToString(result->distance));
		print(1,0,padLeft_408090(distance,3,' '));
		if (opSI_ascii_d28d30)
		{
			Console *glyph = new Console(this,1,1,7,0,2,false,-1);
			glyph->putChar_418110(0,0,cell->glyph,cell->color);
		}
		else
			putChar_418110(7,0,cell->glyph,cell->color);
	}
	string name = opSI_records_d2d1c4[cell->type]->getName(cell->count,cell->kind);
	opw6_truncate408220(name,getWidth() - ((opSI_ascii_d28d30 != 0) + 9) - opSI_barWidth_bcc2e4 - 3,0);
	padRight_4080d0(name,getWidth() - ((opSI_ascii_d28d30 != 0) + 9) - opSI_barWidth_bcc2e4 - 3,' ');
	if (mode == 0)
		setFore(opSI_known_cf4830[cell->type] && (cell->kind == 2 || cell->kind == 3) ? *opSI_d204ac : (cell->kind == 5 ? *opSI_d1dae0 : *opSI_d2981c));
	else
		setFore(*opSI_d2175c);
	print((opSI_ascii_d28d30 != 0) + 9,0,name);
	if (mode == 0 && opSI_records_d2d1c4[cell->type]->category >= 6)
	{
		if (opSI_infoMode_d28d68 == 3)
		{
			string desc;
			XColor color;
			if (!opSI_known_cf4830[cell->type])
				((TeamOct08CharlieString *)&desc)->assign9af390("???");
			else
				opSI_records_d2d1c4[cell->type]->describe_5705b0(desc,color);
			if (!desc.empty())
			{
				setFore(*opSI_cf44c0);
				printAligned(getWidth() - 1,0,2,desc);
				if (color != *opSI_cfe674)
					setForeRow(getWidth() - 2,0,2,color);
			}
		}
		else
		{
			int percent = ops7_clamp_9cdc80(1,cell->integrity,100);
			if (percent > 0)
			{
				int total = OpX5_maxInt(1,(int)(percent / 100.0 * opSI_barWidth_bcc2e4));
				int offset = 40;
				int start = opSI_barEnd_bcc2e0 - opSI_barWidth_bcc2e4;
				if (opSI_known_cf4830[cell->type])
				{
					for (int x = offset + opSI_barEnd_bcc2e0 - 1 - start; total > 0; x--, total--)
						putChar_418110(x,0,'|',opr1c_getScoreColor(cell->integrity) * opSI_dim_bcc2e8);
				}
				string val(!opSI_known_cf4830[cell->type] ? string(" ???") : (cell->count > 9999 ? string("****") : string(padLeft_408090(intToString(cell->count),4,' '))));
				setFore(opr1c_getScoreColor(cell->integrity) * opSI_dim_bcc2e8);
				print(offset + opSI_barEnd_bcc2e0 - start,0,val);
			}
		}
	}
}
