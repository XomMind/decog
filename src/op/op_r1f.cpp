// op_r1f: functions in 0x45f8c0-0x46cbc0 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <iostream>
#include <ctype.h>
#include "../util/rng.h"
#include "../thirdparty/zfstream.h"

using namespace std;

template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name
template <class T> void writeBinary(ostream &stream, T *value);	// NOTE: placeholder name
void OpQ1_writeString(ostream &out, string text);	// 0x409650
void OpQ1_readString(istream &in, string *text);	// 0x4096f0
void OpQ1_writeStringVector(ostream &out, vector<string> *list);	// 0x409770
void OpQ1_readStringVector(istream &in, vector<string> *list);	// 0x4097e0
void OpR1F_write409740(ostream &out, string *text);	// NOTE: placeholder name (0x409740)
void opr2_readText_436960(istream &stream, string *value);	// NOTE: placeholder name (0x436960, forwards to OpQ1_readString)

class OpR1F_Rec45fd10	// NOTE: placeholder name
{
public:
	int value0;
	string text;
	int value20;

	OpR1F_Rec45fd10(istream &stream);
	void write(ostream &stream);
};

OpR1F_Rec45fd10::OpR1F_Rec45fd10(istream &stream)
{
	readBinary(stream,&value0);
	OpQ1_readString(stream,&text);
	readBinary(stream,&value20);
}

void OpR1F_Rec45fd10::write(ostream &stream)
{
	writeBinary(stream,&value0);
	OpQ1_writeString(stream,text);
	writeBinary(stream,&value20);
}

struct Pos
{
	int x;
	int y;

	Pos() throw();	// 0x453b40
	Pos(const Pos &pos) throw();	// 0x46ca50
	Pos(int v) throw();	// 0x409990
	void set(int value);	// NOTE: placeholder name (0x409ff0)
	void read(istream &stream);	// 0x40a330, NOTE: placeholder name
	void write(ostream &stream);	// 0x40a370, NOTE: placeholder name
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();	// 0x40a6e0, NOTE: placeholder
	void read_40a8b0(istream &in);	// NOTE: placeholder name
	void write_40a910(ostream &out);	// NOTE: placeholder name
};

struct OpQ5_U9d0840
{
	int pad;
	void write(ostream &stream);
};

struct OpQ5_U9d25c0
{
	int pad;
	void write(ostream &stream);
};

struct OpQ5_U9d9600
{
	int pad;
	void write(ostream &stream);
};

template <class T> void OpQ5_writeElements(ostream &stream, vector<T> &v);	// NOTE: placeholder name
void OpR1F_read9d07e0(istream &stream, void *value);	// NOTE: placeholder name
void OpR1F_read9d2560(istream &stream, void *value);	// NOTE: placeholder name
void OpR1F_read9da130(istream &stream, void *value);	// NOTE: placeholder name
void OpR1F_write9d2130(ostream &stream, vector<int> *value);	// NOTE: placeholder name (0x9d2130)
void OpR1F_read9cf5e0(istream &stream, vector<int> *value);	// NOTE: placeholder name (0x9cf5e0)

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();	// 0x411d40
	XColor(const XColor &c);
	XColor &operator=(XColor c);
	void read(istream &stream);	// NOTE: placeholder name
	void write(ostream &stream);	// NOTE: placeholder name
};

struct OpR6_KCDA_16_1	// 16-byte element with non-trivial dtor (vector dtor 0x9b8b60, see op_r6_kcda.cpp)
{
	int m0;
	int m4;
	int m8;
	int m12;
	OpR6_KCDA_16_1();
	OpR6_KCDA_16_1(const OpR6_KCDA_16_1 &o);
	OpR6_KCDA_16_1 &operator=(const OpR6_KCDA_16_1 &o);
	~OpR6_KCDA_16_1();
};

class OpR1F_Obj45f8c0	// NOTE: placeholder name
{
public:
	vector<unsigned int> unknown0;
	vector<OpR6_KCDA_16_1> unknown10;
	vector<OpR6_KCDA_16_1> unknown20;
	vector<OpR6_KCDA_16_1> unknown30;
	int unknown40;
	string unknown44;

	~OpR1F_Obj45f8c0();
};

OpR1F_Obj45f8c0::~OpR1F_Obj45f8c0()
{
}

extern int opR1f_bba97c[];	// NOTE: placeholder name

int opR1f_45f9a0(int value)	// NOTE: placeholder name
{
	for (int i = 0; i < 7; i++)
	{
		if (value <= opR1f_bba97c[i])
			return i;
	}

	return 6;
}

extern XColor *opR1f_d2f34c;	// NOTE: placeholder name
extern XColor *opR1f_d23094;	// NOTE: placeholder name
extern XColor *opR1f_cf27e8;	// NOTE: placeholder name
extern XColor *opR1f_cf6b24;	// NOTE: placeholder name
extern XColor *opR1f_d2981c;	// NOTE: placeholder name
extern XColor *opR1f_d25e0c;	// NOTE: placeholder name
extern XColor *opR1f_d20b78;	// NOTE: placeholder name
extern XColor opR1f_d395fc;	// NOTE: placeholder name
extern XColor opR1f_d395ff;	// NOTE: placeholder name
extern XColor opR1f_d39602;	// NOTE: placeholder name
extern XColor opR1f_d39605;	// NOTE: placeholder name
extern XColor opR1f_d39608;	// NOTE: placeholder name
extern XColor opR1f_d3960b;	// NOTE: placeholder name
extern XColor opR1f_d3960e;	// NOTE: placeholder name

void opR1f_45f9e0()	// NOTE: placeholder name
{
	opR1f_d395fc = *opR1f_d2f34c;
	opR1f_d395ff = *opR1f_d23094;
	opR1f_d39602 = *opR1f_cf27e8;
	opR1f_d39605 = *opR1f_cf6b24;
	opR1f_d39608 = *opR1f_d2981c;
	opR1f_d3960b = *opR1f_d25e0c;
	opR1f_d3960e = *opR1f_d20b78;
}

class OpR1F_M9b7420	// NOTE: placeholder name
{
public:
	int pad[4];

	~OpR1F_M9b7420();
};

class OpR1F_M9cec20	// NOTE: placeholder name
{
public:
	int pad[3];

	~OpR1F_M9cec20();
};

class OpR1F_Obj45f940	// NOTE: placeholder name
{
public:
	int unknown0;
	OpR1F_M9cec20 unknown4;
	OpR1F_M9b7420 unknown10;

	~OpR1F_Obj45f940();
};

OpR1F_Obj45f940::~OpR1F_Obj45f940()
{
}

struct OpR1F_RectValue : public Rect	// NOTE: placeholder name
{
	int value10;

	OpR1F_RectValue(istream &stream);
	void write(ostream &stream);
};

OpR1F_RectValue::OpR1F_RectValue(istream &stream)
{
	read_40a8b0(stream);
	readBinary(stream,&value10);
}

void OpR1F_RectValue::write(ostream &stream)
{
	write_40a910(stream);
	writeBinary(stream,&value10);
}

struct OpR1F_PosPair : public Pos	// NOTE: placeholder name
{
	int value8;
	int valueC;

	OpR1F_PosPair(istream &stream);
};

OpR1F_PosPair::OpR1F_PosPair(istream &stream)
{
	read(stream);
	readBinary(stream,&value8);
	readBinary(stream,&valueC);
}

class OpR1F_Lists460090	// NOTE: placeholder name
{
public:
	int value0;
	bool flag4;
	int value8;
	vector<OpQ5_U9d0840> list0C;
	vector<int> list1C;
	vector<OpQ5_U9d25c0> list2C;
	vector<OpQ5_U9d25c0> list3C;

	OpR1F_Lists460090(int value0_, int value8_);
	OpR1F_Lists460090(istream &stream);
	void write(ostream &stream);
};

OpR1F_Lists460090::OpR1F_Lists460090(int value0_, int value8_)
	: value0	(value0_)
	, flag4		(false)
	, value8	(value8_)
{
}

OpR1F_Lists460090::OpR1F_Lists460090(istream &stream)
{
	readBinary(stream,&value0);
	readBinary(stream,&flag4);
	readBinary(stream,&value8);
	OpR1F_read9d07e0(stream,&list0C);
	OpR1F_read9cf5e0(stream,&list1C);
	OpR1F_read9d2560(stream,&list2C);
	OpR1F_read9d2560(stream,&list3C);
}

void OpR1F_Lists460090::write(ostream &stream)
{
	writeBinary(stream,&value0);
	writeBinary(stream,&flag4);
	writeBinary(stream,&value8);
	OpQ5_writeElements(stream,list0C);
	OpR1F_write9d2130(stream,&list1C);
	OpQ5_writeElements(stream,list2C);
	OpQ5_writeElements(stream,list3C);
}

class OpR1F_Lists460320	// NOTE: placeholder name
{
public:
	vector<int> list0;
	vector<int> list10;
	vector<int> list20;
	bool flag30;

	OpR1F_Lists460320();
	OpR1F_Lists460320(int value);
	OpR1F_Lists460320(istream &stream);
	void write(ostream &stream);
};

OpR1F_Lists460320::OpR1F_Lists460320()
	: flag30	(false)
{
}

OpR1F_Lists460320::OpR1F_Lists460320(int value)
	: flag30	(false)
{
	list0.push_back(value);
}

OpR1F_Lists460320::OpR1F_Lists460320(istream &stream)
{
	OpR1F_read9cf5e0(stream,&list0);
	OpR1F_read9cf5e0(stream,&list10);
	OpR1F_read9cf5e0(stream,&list20);
	readBinary(stream,&flag30);
}

void OpR1F_Lists460320::write(ostream &stream)
{
	OpR1F_write9d2130(stream,&list0);
	OpR1F_write9d2130(stream,&list10);
	OpR1F_write9d2130(stream,&list20);
	writeBinary(stream,&flag30);
}

class HProp
{
public:
	int ID;
	HProp();
	void save(ostream &stream);	// NOTE: placeholder name (0x9cfa90)
	void load(istream &stream);	// NOTE: placeholder name (0x9cfaf0)
	void clear();	// NOTE: placeholder name (0x9b7270)
};

class Entity
{
public:
	int unknown5c7c20(int offset, bool flag);	// NOTE: placeholder name
};

class HEntity
{
public:
	int ID;
	HEntity();
	Entity *operator->() const throw();	// 0x9b6570
	void clear();	// NOTE: placeholder name (0x9b7270)
	void save(ostream &stream);	// NOTE: placeholder name (0x9cfa90)
	void load(istream &stream);	// NOTE: placeholder name (0x9cfaf0)
};

struct OpQ5_U9d2620;
template <class T> void OpQ5_deleteBack(vector<T*> &v);	// NOTE: placeholder name
void OpR1F_insert9dbdc0(vector<OpQ5_U9d2620*> *list, int index, OpQ5_U9d2620 *value);	// NOTE: placeholder name
extern vector<OpQ5_U9d2620*> opR1f_d3977c;	// NOTE: placeholder name

void opR1f_460820(OpQ5_U9d2620 *entry)	// NOTE: placeholder name
{
	if (opR1f_d3977c.size() >= 5)
		OpQ5_deleteBack(opR1f_d3977c);

	OpR1F_insert9dbdc0(&opR1f_d3977c,0,entry);
}

class OpR1F_Rec4608b0	// NOTE: placeholder name
{
public:
	int value0;
	HProp prop4;
	vector<int> list8;
	vector<int> list18;
	vector<string> names28;

	OpR1F_Rec4608b0(istream &stream);
	void write(ostream &stream);
};

OpR1F_Rec4608b0::OpR1F_Rec4608b0(istream &stream)
{
	readBinary(stream,&value0);
	prop4.load(stream);
	OpR1F_read9cf5e0(stream,&list8);
	OpR1F_read9cf5e0(stream,&list18);
	OpQ1_readStringVector(stream,&names28);
}

void OpR1F_Rec4608b0::write(ostream &stream)
{
	writeBinary(stream,&value0);
	prop4.save(stream);
	OpR1F_write9d2130(stream,&list8);
	OpR1F_write9d2130(stream,&list18);
	OpQ1_writeStringVector(stream,&names28);
}

class OpR1F_Named460780	// NOTE: placeholder name
{
public:
	string name;
	Pos pos1C;
	Pos pos24;
	Pos pos2C;
	Pos pos34;

	OpR1F_Named460780(string name_, Pos pos1, Pos pos2, const Pos &pos3, const Pos &pos4);
};

OpR1F_Named460780::OpR1F_Named460780(string name_, Pos pos1, Pos pos2, const Pos &pos3, const Pos &pos4)
	: name		(name_)
	, pos1C		(pos1)
	, pos24		(pos2)
	, pos2C		(pos3)
	, pos34		(pos4)
{
}

class OpR1F_PosText460aa0 : public Pos	// NOTE: placeholder name
{
public:
	int value8;
	int valueC;
	string text10;

	OpR1F_PosText460aa0(Pos pos, int value8_, int valueC_, string text);
	OpR1F_PosText460aa0(istream &stream);
	void write(ostream &stream);
};

OpR1F_PosText460aa0::OpR1F_PosText460aa0(Pos pos, int value8_, int valueC_, string text)
	: Pos		(pos)
	, value8	(value8_)
	, valueC	(valueC_)
	, text10	(text)
{
}

OpR1F_PosText460aa0::OpR1F_PosText460aa0(istream &stream)
{
	Pos::read(stream);
	readBinary(stream,&value8);
	readBinary(stream,&valueC);
	opr2_readText_436960(stream,&text10);
}

void OpR1F_PosText460aa0::write(ostream &stream)
{
	Pos::write(stream);
	writeBinary(stream,&value8);
	writeBinary(stream,&valueC);
	OpR1F_write409740(stream,&text10);
}

class OpR1F_PosPair460c20 : public Pos	// NOTE: placeholder name
{
public:
	int value8;
	int valueC;

	void write(ostream &stream);
};

void OpR1F_PosPair460c20::write(ostream &stream)
{
	Pos::write(stream);
	writeBinary(stream,&value8);
	writeBinary(stream,&valueC);
}

class OpR1F_Props460c60	// NOTE: placeholder name
{
public:
	HProp prop0;
	HProp prop4;
	int value8;

	OpR1F_Props460c60(istream &stream);
	void write(ostream &stream);
};

OpR1F_Props460c60::OpR1F_Props460c60(istream &stream)
{
	prop0.load(stream);
	prop4.load(stream);
	readBinary(stream,&value8);
}

void OpR1F_Props460c60::write(ostream &stream)
{
	prop0.save(stream);
	prop4.save(stream);
	writeBinary(stream,&value8);
}

class OpR1F_PropPos460d30	// NOTE: placeholder name
{
public:
	HProp prop0;
	Pos pos4;
	int valueC;

	OpR1F_PropPos460d30(istream &stream);
	void write(ostream &stream);
};

OpR1F_PropPos460d30::OpR1F_PropPos460d30(istream &stream)
{
	prop0.load(stream);
	pos4.read(stream);
	readBinary(stream,&valueC);
}

void OpR1F_PropPos460d30::write(ostream &stream)
{
	prop0.save(stream);
	pos4.write(stream);
	writeBinary(stream,&valueC);
}

extern XColor *opR1f_cfe674;	// NOTE: placeholder name
extern int opR1f_caf164;	// NOTE: placeholder name
extern int opR1f_caf15c;	// NOTE: placeholder name

class OpR1F_Style460e50	// NOTE: placeholder name
{
public:
	int value0;
	int value4;
	XColor color8;
	XColor colorB;
	bool flagE;
	int value10;
	int value14;
	int value18;
	int value1C;
	int value20;
	int value24;
	int value28;
	int value2C;
	bool flag30;

	OpR1F_Style460e50();
	void reset();	// NOTE: placeholder name
	void read(istream &stream);	// NOTE: placeholder name
	void write(ostream &stream);	// NOTE: placeholder name
};

OpR1F_Style460e50::OpR1F_Style460e50()
	: value0	(32)
	, value4	(32)
	, color8	(*opR1f_cfe674)
	, colorB	(*opR1f_cfe674)
	, flagE		(false)
	, value10	(opR1f_caf164)
	, value14	(0)
	, value18	(0)
	, value1C	(0)
	, value20	(0)
	, value24	(opR1f_caf15c)
	, value28	(0)
	, value2C	(0)
	, flag30	(false)
{
}

void OpR1F_Style460e50::reset()
{
	value4 = 32;
	value0 = 32;
	color8 = colorB = *opR1f_cfe674;
	flagE = false;
	value10 = opR1f_caf164;
	value14 = 0;
	value18 = 0;
	value1C = 0;
	value20 = 0;
	value24 = opR1f_caf15c;
	value28 = 0;
	value2C = 0;
	flag30 = false;
}

void OpR1F_Style460e50::read(istream &stream)
{
	readBinary(stream,&value0);
	readBinary(stream,&value4);
	color8.read(stream);
	colorB.read(stream);
	readBinary(stream,&flagE);
	readBinary(stream,&value10);
	readBinary(stream,&value14);
	readBinary(stream,&value18);
	readBinary(stream,&value1C);
	readBinary(stream,&value20);
	readBinary(stream,&value24);
	readBinary(stream,&value28);
	value2C = 0;
	readBinary(stream,&flag30);
}

void OpR1F_Style460e50::write(ostream &stream)
{
	writeBinary(stream,&value0);
	writeBinary(stream,&value4);
	color8.write(stream);
	colorB.write(stream);
	writeBinary(stream,&flagE);
	writeBinary(stream,&value10);
	writeBinary(stream,&value14);
	writeBinary(stream,&value18);
	writeBinary(stream,&value1C);
	writeBinary(stream,&value20);
	writeBinary(stream,&value24);
	writeBinary(stream,&value28);
	writeBinary(stream,&flag30);
}

class OpR1F_PropPos4613c0	// NOTE: placeholder name
{
public:
	HProp prop0;
	int value4;
	Pos pos8;
	int value10;
	int value14;

	OpR1F_PropPos4613c0(istream &stream);
	void write(ostream &stream);
};

OpR1F_PropPos4613c0::OpR1F_PropPos4613c0(istream &stream)
{
	prop0.load(stream);
	readBinary(stream,&value4);
	pos8.read(stream);
	readBinary(stream,&value10);
	readBinary(stream,&value14);
}

void OpR1F_PropPos4613c0::write(ostream &stream)
{
	prop0.save(stream);
	writeBinary(stream,&value4);
	pos8.write(stream);
	writeBinary(stream,&value10);
	writeBinary(stream,&value14);
}

class OpR1F_PosText4614f0 : public Pos	// NOTE: placeholder name
{
public:
	string text8;
	int value24;

	OpR1F_PosText4614f0(istream &stream);
	void write(ostream &stream);
};

OpR1F_PosText4614f0::OpR1F_PosText4614f0(istream &stream)
{
	Pos::read(stream);
	opr2_readText_436960(stream,&text8);
	readBinary(stream,&value24);
}

void OpR1F_PosText4614f0::write(ostream &stream)
{
	Pos::write(stream);
	OpR1F_write409740(stream,&text8);
	writeBinary(stream,&value24);
}

class OpR1F_Vals4615c0	// NOTE: placeholder name
{
public:
	vector<OpQ5_U9d9600> list0;
	int value10;
	int value14;
	int value18;
	int value1C;
	int value20;

	OpR1F_Vals4615c0(istream &stream);
	void write(ostream &stream);
};

OpR1F_Vals4615c0::OpR1F_Vals4615c0(istream &stream)
{
	OpR1F_read9da130(stream,&list0);
	readBinary(stream,&value10);
	readBinary(stream,&value14);
	readBinary(stream,&value18);
	readBinary(stream,&value1C);
	readBinary(stream,&value20);
}

void OpR1F_Vals4615c0::write(ostream &stream)
{
	OpQ5_writeElements(stream,list0);
	writeBinary(stream,&value10);
	writeBinary(stream,&value14);
	writeBinary(stream,&value18);
	writeBinary(stream,&value1C);
	writeBinary(stream,&value20);
}

class OpR1F_List461730	// NOTE: placeholder name
{
public:
	int value0;
	vector<OpQ5_U9d0840> list4;

	OpR1F_List461730(istream &stream);
	void write(ostream &stream);
};

OpR1F_List461730::OpR1F_List461730(istream &stream)
{
	readBinary(stream,&value0);
	OpR1F_read9d07e0(stream,&list4);
}

void OpR1F_List461730::write(ostream &stream)
{
	writeBinary(stream,&value0);
	OpQ5_writeElements(stream,list4);
}

class OpR1F_Text4617e0	// NOTE: placeholder name
{
public:
	int value0;
	int value4;
	string text8;

	OpR1F_Text4617e0(int value0_, int value4_, string text);
};

OpR1F_Text4617e0::OpR1F_Text4617e0(int value0_, int value4_, string text)
	: value0	(value0_)
	, value4	(value4_)
	, text8		(text)
{
}

class OpR1F_PropText461860	// NOTE: placeholder name
{
public:
	HProp prop0;
	int value4;
	string text8;

	OpR1F_PropText461860(istream &stream);
	void write(ostream &stream);
};

OpR1F_PropText461860::OpR1F_PropText461860(istream &stream)
{
	prop0.load(stream);
	readBinary(stream,&value4);
	OpQ1_readString(stream,&text8);
}

void OpR1F_PropText461860::write(ostream &stream)
{
	prop0.save(stream);
	writeBinary(stream,&value4);
	OpQ1_writeString(stream,text8);
}

class OpR1F_Grid9d2670	// NOTE: placeholder name
{
public:
	int data[3];

	OpR1F_Grid9d2670() throw();	// 0x9d2670
	~OpR1F_Grid9d2670();	// 0x9cec20
	void init(int width, int height, int value);	// NOTE: placeholder name (0x9d4090)
	void clear();	// NOTE: placeholder name (0x9d23e0)
	void save(ostream &stream);	// NOTE: placeholder name (0x9d26a0)
	void load(istream &stream);	// NOTE: placeholder name (0x9cee40)
	int &operator()(const Pos &pos);	// 0x9ced70
	int &operator()(int x, int y);	// 0x9ceda0
};

class OpR1F_Size461950	// NOTE: placeholder name
{
public:
	int getWidth();	// NOTE: placeholder name
	int getHeight();	// NOTE: placeholder name
};

extern OpR1F_Size461950 opR1f_cfd44c;	// NOTE: placeholder name

class OpR1F_GridPos461950	// NOTE: placeholder name
{
public:
	OpR1F_Grid9d2670 grid0;
	int valueC;
	Pos pos10;
	int value18;

	OpR1F_GridPos461950(int unused);
	OpR1F_GridPos461950(istream &stream);
	void initialize();	// NOTE: placeholder name
	bool hasValue(vector<Pos> &list);	// NOTE: placeholder name
	void write(ostream &stream);
};

OpR1F_GridPos461950::OpR1F_GridPos461950(int unused)
{
	initialize();
}

OpR1F_GridPos461950::OpR1F_GridPos461950(istream &stream)
{
	grid0.load(stream);
	readBinary(stream,&valueC);
	pos10.read(stream);
	readBinary(stream,&value18);
}

void OpR1F_GridPos461950::write(ostream &stream)
{
	grid0.save(stream);
	writeBinary(stream,&valueC);
	pos10.write(stream);
	writeBinary(stream,&value18);
}

void OpR1F_GridPos461950::initialize()
{
	grid0.init(opR1f_cfd44c.getWidth(),opR1f_cfd44c.getHeight(),0);
	grid0.clear();
	valueC = 1;
	pos10.set(-1);
	value18 = -1;
}

bool OpR1F_GridPos461950::hasValue(vector<Pos> &list)
{
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (grid0(list[i]) == valueC)
			return true;
	}

	return false;
}

class OpR1F_ColorProp461b70	// NOTE: placeholder name
{
public:
	int value0;
	int value4;
	HEntity entity8;
	int valueC;
	XColor color10;

	OpR1F_ColorProp461b70();
	int getValue(bool flag);	// NOTE: placeholder name
	void reset();	// NOTE: placeholder name
	void read(istream &stream);	// NOTE: placeholder name
	void write(ostream &stream);	// NOTE: placeholder name
};

OpR1F_ColorProp461b70::OpR1F_ColorProp461b70()
	: value0	(0)
	, value4	(11)
	, valueC	(0)
	, color10	(*opR1f_cfe674)
{
}

extern bool opR1f_asciiEnabled;	// NOTE: placeholder name (0xd28d30)

int OpR1F_ColorProp461b70::getValue(bool flag)
{
	switch (value4)
	{
	case 0:
	zero:
		return (opR1f_asciiEnabled && flag) ? 0x103 : 0x3f;
	case 1:
		return (opR1f_asciiEnabled && flag) ? 0x104 : 0x78;
	case 2:
		return (opR1f_asciiEnabled && flag) ? 0x105 : 0x58;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		if (entity8.operator->())
			return entity8->unknown5c7c20(valueC,flag);
		else
			goto zero;
		break;
	}

	return 0x20;
}

void OpR1F_ColorProp461b70::reset()
{
	value0 = 0;
	value4 = 11;
	entity8.clear();
	valueC = 0;
	color10 = *opR1f_cfe674;
}

void OpR1F_ColorProp461b70::read(istream &stream)
{
	readBinary(stream,&value0);
	readBinary(stream,&value4);
	entity8.load(stream);
	readBinary(stream,&valueC);
	color10.read(stream);
}

void OpR1F_ColorProp461b70::write(ostream &stream)
{
	writeBinary(stream,&value0);
	writeBinary(stream,&value4);
	entity8.save(stream);
	writeBinary(stream,&valueC);
	color10.write(stream);
}

class OpR1F_Rec461e00	// NOTE: placeholder name
{
public:
	HProp prop0;
	Pos pos4;
	int valueC;
	vector<OpQ5_U9d0840> list10;
	vector<int> list20;
	int value30;

	OpR1F_Rec461e00(istream &stream);
	void write(ostream &stream);
};

OpR1F_Rec461e00::OpR1F_Rec461e00(istream &stream)
{
	prop0.load(stream);
	pos4.read(stream);
	readBinary(stream,&valueC);
	OpR1F_read9d07e0(stream,&list10);
	OpR1F_read9cf5e0(stream,&list20);
	value30 = 0;
}

void OpR1F_Rec461e00::write(ostream &stream)
{
	prop0.save(stream);
	pos4.write(stream);
	writeBinary(stream,&valueC);
	OpQ5_writeElements(stream,list10);
	OpR1F_write9d2130(stream,&list20);
}

class OpR1F_PosColor461f50 : public Pos	// NOTE: placeholder name
{
public:
	int value8;
	XColor colorC;

	OpR1F_PosColor461f50(const Pos &pos, int value, const XColor &color);
	OpR1F_PosColor461f50(istream &stream);
	void write(ostream &stream);
};

OpR1F_PosColor461f50::OpR1F_PosColor461f50(const Pos &pos, int value, const XColor &color)
	: Pos		(pos)
	, value8	(value)
	, colorC	(color)
{
}

OpR1F_PosColor461f50::OpR1F_PosColor461f50(istream &stream)
{
	Pos::read(stream);
	readBinary(stream,&value8);
	colorC.read(stream);
}

void OpR1F_PosColor461f50::write(ostream &stream)
{
	Pos::write(stream);
	writeBinary(stream,&value8);
	colorC.write(stream);
}

extern int opR1f_caed20;	// NOTE: placeholder name

class OpR1F_Rec462030	// NOTE: placeholder name
{
public:
	int value0;
	int value4;
	vector<int> list8;
	int value18;
	Pos pos1C;
	int value24;
	int value28;

	OpR1F_Rec462030(int value0_, int value4_, int value24_);
	OpR1F_Rec462030(istream &stream);
	void write(ostream &stream);
};

OpR1F_Rec462030::OpR1F_Rec462030(int value0_, int value4_, int value24_)
	: value0	(value0_)
	, value4	(value4_)
	, value18	(0x142)
	, pos1C		(-1)
	, value24	(value24_)
	, value28	(opR1f_caed20)
{
}

OpR1F_Rec462030::OpR1F_Rec462030(istream &stream)
{
	readBinary(stream,&value0);
	readBinary(stream,&value4);
	OpR1F_read9cf5e0(stream,&list8);
	value18 = 0x142;
	pos1C.set(-1);
	readBinary(stream,&value24);
	value28 = 0;
}

void OpR1F_Rec462030::write(ostream &stream)
{
	writeBinary(stream,&value0);
	writeBinary(stream,&value4);
	OpR1F_write9d2130(stream,&list8);
	writeBinary(stream,&value24);
}

struct EntityData4563c0;

template <class T> bool addUnique(vector<T> &v, T e);	// NOTE: placeholder name (0x9d30e0 for HEntity, 0x9d3020 for Pos)

struct OpR1F_Target45e690	// NOTE: placeholder name
{
	void unknown45e690(int value);	// NOTE: placeholder name
};

struct OpR1F_Handle9b73b0	// NOTE: placeholder name
{
	int ID;
	OpR1F_Handle9b73b0() throw();	// 0x9b6590
	OpR1F_Target45e690 *operator->() const throw();	// 0x9b73b0
};

struct OpR1F_TableRow	// NOTE: placeholder name
{
	int value0;
	int pad[7];
};
extern OpR1F_TableRow opR1f_b99d88[];	// NOTE: placeholder name

struct OpR1F_Area40b100	// NOTE: placeholder name
{
	OpR1F_Area40b100() throw();	// 0x40b100
	int pad[4];
};

struct OpR1F_Items9bab50	// NOTE: placeholder name
{
	OpR1F_Items9bab50();	// 0x9bab50
	~OpR1F_Items9bab50();
	int pad[9];
};

struct OpR1F_Block9cfd10	// NOTE: placeholder name
{
	OpR1F_Block9cfd10();	// 0x9cfd10
	int pad[12];
};

class Map
{
public:
	int unknown0[2];
	Pos unknown8;
	vector<int> unknown10;
	vector<int> unknown20;
	int unknown30[2];
	OpR1F_Grid9d2670 unknown38;
	int unknown44;
	HProp unknown48;
	vector<int> unknown4c;
	OpR1F_Grid9d2670 unknown5c;
	OpR1F_Items9bab50 unknown68;
	OpR1F_Items9bab50 unknown8c;
	vector<int> unknownb0;
	OpR1F_Items9bab50 unknownc0;
	vector<int> unknowne4;
	vector<int> unknownf4;
	int unknown104;
	vector<int> unknown108;
	vector<int> unknown118;
	vector<int> unknown128;
	vector<int> unknown138;
	vector<int> unknown148;
	vector<int> unknown158;
	vector<int> unknown168;
	vector<HEntity> unknown178;
	vector<EntityData4563c0 *> unknown188;
	vector<Pos> unknown198;
	vector<EntityData4563c0 *> unknown1a8;
	vector<int> unknown1b8;
	vector<int> unknown1c8;
	int unknown1d8;
	vector<int> unknown1dc;
	vector<int> unknown1ec;
	int unknown1fc[3];
	vector<int> unknown208;
	int unknown218[2];
	vector<int> unknown220;
	int unknown230;
	HProp unknown234;
	int unknown238;
	int unknown23c;
	int unknown240;
	vector<int> unknown244;
	int unknown254;
	vector<int> unknown258;
	vector<int> unknown268;
	vector<int> unknown278;
	OpR1F_Items9bab50 unknown288;
	int unknown2ac;
	vector<int> unknown2b0;
	vector<int> unknown2c0;
	vector<int> unknown2d0;
	vector<int> unknown2e0;
	int unknown2f0;
	vector<int> unknown2f4;
	vector<int> unknown304;
	int unknown314[3];
	int unknown320;
	int unknown324[3];
	vector<int> unknown330;
	vector<int> unknown340;
	vector<int> unknown350;
	vector<int> unknown360;
	vector<int> unknown370;
	vector<int> unknown380;
	vector<int> unknown390;
	vector<int> unknown3a0;
	vector<int> unknown3b0;
	vector<int> unknown3c0;
	int unknown3d0[2];
	vector<int> unknown3d8;
	int unknown3e8[2];
	vector<int> unknown3f0;
	vector<int> unknown400;
	vector<int> unknown410;
	vector<int> unknown420;
	vector<int> unknown430;
	vector<int> unknown440;
	vector<int> unknown450;
	vector<int> unknown460;
	vector<int> unknown470;
	vector<int> unknown480;
	vector<int> unknown490;
	vector<int> unknown4a0;
	vector<int> unknown4b0;
	vector<int> unknown4c0;
	vector<int> unknown4d0;
	vector<int> unknown4e0;
	vector<int> unknown4f0;
	vector<int> unknown500;
	vector<int> unknown510;
	int unknown520;
	vector<int> unknown524;
	int unknown534;
	vector<int> unknown538;
	vector<int> unknown548;
	int unknown558[2];
	vector<int> unknown560;
	int unknown570;
	vector<int> unknown574;
	vector<int> unknown584;
	vector<int> unknown594;
	vector<int> unknown5a4;
	int unknown5b4[2];
	vector<int> unknown5bc;
	vector<int> unknown5cc;
	vector<int> unknown5dc;
	vector<int> unknown5ec;
	HProp unknown5fc;
	HProp unknown600;
	vector<int> unknown604;
	int unknown614;
	HProp unknown618;
	vector<int> unknown61c;
	vector<int> unknown62c;
	int unknown63c[3];
	vector<int> unknown648;
	int unknown658;
	OpR1F_Handle9b73b0 unknown65c;
	int unknown660[3];
	HProp unknown66c;
	HProp unknown670;
	OpR1F_Grid9d2670 unknown674;
	OpR1F_Grid9d2670 unknown680;
	int unknown68c;
	OpR1F_Grid9d2670 unknown690;
	OpR1F_Grid9d2670 unknown69c;
	vector<int> unknown6a8;
	vector<int> unknown6b8;
	vector<int> unknown6c8;
	vector<int> unknown6d8;
	int unknown6e8;
	vector<int> unknown6ec;
	vector<int> unknown6fc;
	int unknown70c;
	vector<int> unknown710;
	vector<int> unknown720;
	vector<int> unknown730;
	OpR1F_Grid9d2670 unknown740;
	int unknown74c[2];
	vector<int> unknown754;
	vector<int> unknown764;
	vector<int> unknown774;
	vector<int> unknown784;
	vector<int> unknown794;
	vector<int> unknown7a4;
	vector<int> unknown7b4;
	OpR1F_Grid9d2670 unknown7c4;
	vector<int> unknown7d0;
	vector<int> unknown7e0;
	vector<int> unknown7f0;
	vector<int> unknown800;
	Pos unknown810;
	int unknown818;
	vector<int> unknown81c;
	int unknown82c;
	vector<int> unknown830;
	vector<int> unknown840;
	vector<int> unknown850;
	int unknown860[3];
	Pos unknown86c;
	vector<int> unknown874;
	vector<int> unknown884;
	vector<int> unknown894;
	int unknown8a4[4];
	vector<int> unknown8b4;
	int unknown8c4[2];
	OpR1F_Area40b100 unknown8cc;
	vector<int> unknown8dc;
	vector<int> unknown8ec;
	int unknown8fc[2];
	vector<int> unknown904;
	vector<int> unknown914;
	OpR1F_Area40b100 unknown924;
	OpR1F_Area40b100 unknown934;
	OpR1F_Area40b100 unknown944;
	OpR1F_Area40b100 unknown954;
	int unknown964[2];
	vector<int> unknown96c;
	vector<int> unknown97c;
	int unknown98c;
	vector<int> unknown990;
	int unknown9a0[7];
	vector<int> unknown9bc;
	int unknown9cc[2];
	vector<int> unknown9d4;
	int unknown9e4;
	HProp unknown9e8;
	int unknown9ec[2];
	vector<int> unknown9f4;
	int unknowna04[7];
	vector<int> unknowna20;
	vector<int> unknowna30;
	vector<int> unknowna40;
	vector<int> unknowna50;
	vector<int> unknowna60;
	int unknowna70[2];
	HProp unknowna78;
	HProp unknowna7c;
	vector<int> unknowna80;
	vector<int> unknowna90;
	vector<int> unknownaa0;
	vector<int> unknownab0;
	vector<int> unknownac0;
	vector<int> unknownad0;
	int unknownae0;
	vector<int> unknownae4;
	vector<int> unknownaf4;
	int unknownb04;
	vector<int> unknownb08;
	int unknownb18[3];
	vector<int> unknownb24;
	int unknownb34[2];
	Pos unknownb3c;
	int unknownb44[2];
	OpR1F_Items9bab50 unknownb4c;
	vector<int> unknownb70;
	int unknownb80;
	vector<int> unknownb84;
	vector<int> unknownb94;
	int unknownba4;
	HProp unknownba8;
	int unknownbac[2];
	vector<int> unknownbb4;
	vector<int> unknownbc4;
	vector<int> unknownbd4;
	int unknownbe4;
	OpR1F_Block9cfd10 unknownbe8;
	vector<int> unknownc18;
	vector<int> unknownc28;
	vector<int> unknownc38;
	vector<int> unknownc48;
	vector<int> unknownc58;

	Map();
	void unknown465800(HEntity entity, EntityData4563c0 *data);	// NOTE: placeholder name
	void unknown465840(const Pos &pos, EntityData4563c0 *data);	// NOTE: placeholder name
	void unknown465890(HProp prop);	// NOTE: placeholder name
	void unknown465950(int x, int y, int value);	// NOTE: placeholder name
	void unknown4659c0(int amount);	// NOTE: placeholder name
	int getTurn();	// 0x464270
};

Map::Map()
	: unknown658	(0)
{
}

void Map::unknown465800(HEntity entity, EntityData4563c0 *data)
{
	if (addUnique(unknown178,entity))
		unknown188.push_back(data);
}

void Map::unknown465840(const Pos &pos, EntityData4563c0 *data)
{
	if (addUnique(unknown198,pos))
		unknown1a8.push_back(data);
}

void Map::unknown465890(HProp prop)
{
	unknown234 = prop;
	unknown238 = 2;
	unknown23c = opR1f_b99d88[unknown238].value0;
	unknown240 = 0;
}

void Map::unknown465950(int x, int y, int value)
{
	unknown5c(y,x) = value;
	unknown5c(x,y) = value;
}

void Map::unknown4659c0(int amount)
{
	unknown65c->unknown45e690(getTurn() + amount);
	unknown320 += amount;
}

struct OpR1F_NameRecord	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	char pad8[0x1c];
	string name24;
};

string OpR1F_pickRandom9d3280(vector<string> &values);	// NOTE: placeholder name (0x9d3280)
void OpR1F_copyValues9da8f0(vector<OpR1F_NameRecord *> *records, vector<int> *values);	// NOTE: placeholder name
extern vector<OpR1F_NameRecord *> opR1f_d2d1c4;	// NOTE: placeholder name
extern vector<string> opR1f_d204dc;	// NOTE: placeholder name
extern vector<string> opR1f_d2c444;	// NOTE: placeholder name
extern vector<string> opR1f_d388e0;	// NOTE: placeholder name
extern vector<string> opR1f_d2c42c;	// NOTE: placeholder name

void opR1f_465b10()	// NOTE: placeholder name
{
	vector<int> values;
	OpR1F_copyValues9da8f0(&opR1f_d2d1c4,&values);
	for (unsigned int i = 0; i < opR1f_d2d1c4.size(); i++)
		opR1f_d2d1c4[i]->unknown4 = values[i];
}

string opR1f_465bc0()	// NOTE: placeholder name
{
	string name;
retry:
	name = OpR1F_pickRandom9d3280(opR1f_d2c444) + " " + OpR1F_pickRandom9d3280(opR1f_d204dc);
	for (unsigned int i = 0; i < opR1f_d2d1c4.size(); i++)
	{
		if (opR1f_d2d1c4[i]->name24 == name)
			goto retry;
	}

	return name;
}

string opR1f_465db0()	// NOTE: placeholder name
{
	string name = OpR1F_pickRandom9d3280(opR1f_d388e0);
	name[0] = toupper(name[0]);
	name += OpR1F_pickRandom9d3280(opR1f_d2c42c);
	return name;
}

extern RNG rng_d20d00;	// NOTE: placeholder name (0xd20d00)

void opR1f_465ea0(istream &stream, int *out)	// NOTE: placeholder name
{
	int count;
	int i;
	int value;
	if (!rng_d20d00.chance(2))
		stream.read((char *)out,4);
	else
	{
		stream.read((char *)&count,4);
		*out = 0;
		for (i = 0; i < count; i++)
		{
			stream.read((char *)&value,4);
			*out += value;
		}
	}
}

void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)

extern gzifstream *opR1f_cefc20;	// NOTE: placeholder name
extern gzifstream *opR1f_cefc24;	// NOTE: placeholder name
extern gzifstream *opR1f_cefc28;	// NOTE: placeholder name

void opR1f_465f30()	// NOTE: placeholder name
{
	opR1f_cefc20 = new gzifstream((string() + "data/item.bin").c_str(),ios::binary);
	if (!opR1f_cefc20->is_open())
		logFatal("init","Unable to open object data");

	opR1f_cefc24 = new gzifstream((string() + "data/entity.bin").c_str(),ios::binary);
	if (!opR1f_cefc24->is_open())
		logFatal("init","Unable to open object data");

	opR1f_cefc28 = new gzifstream((string() + "data/maps.bin").c_str(),ios::binary);
	if (!opR1f_cefc28->is_open())
		logFatal("init","Unable to open object data");
}

template <class T> void OpR1F_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name (0x9cfab0 instance)

extern string gameString_cf4db4;	// 0xcf4db4
extern vector<string> opR1f_d33d28;	// NOTE: placeholder name
extern vector<string> opR1f_d33d38;	// NOTE: placeholder name
extern vector<string> opR1f_d33d48;	// NOTE: placeholder name
extern int opR1f_cef9dc;	// NOTE: placeholder name
extern int opR1f_cebd58;	// NOTE: placeholder name
extern int opR1f_cebd60;	// NOTE: placeholder name

void opR1f_466730(const string &text)	// NOTE: placeholder name
{
	if (text.find(gameString_cf4db4,0) != string::npos)
		return;

	{
		if (opR1f_d33d28.empty() || text != opR1f_d33d28.back())
			opR1f_d33d28.push_back(text);

		for (int i = 0; i < (int)opR1f_d33d28.size() - 2; i++)
		{
			if (opR1f_d33d28[i] == text)
			{
				OpR1F_eraseAt(opR1f_d33d28,i);
				break;
			}
		}

		opR1f_cef9dc = opR1f_d33d28.size();
	}
}

void opR1f_466800()	// NOTE: placeholder name
{
	if (opR1f_d33d28.empty())
		return;

	opR1f_d33d28.pop_back();
	opR1f_cef9dc = opR1f_d33d28.size();
}

void opR1f_466860(const string &text)	// NOTE: placeholder name
{
	if (text.find(gameString_cf4db4,0) != string::npos)
		return;

	{
		if (opR1f_d33d38.empty() || text != opR1f_d33d38.back())
			opR1f_d33d38.push_back(text);

		for (int i = 0; i < (int)opR1f_d33d38.size() - 2; i++)
		{
			if (opR1f_d33d38[i] == text)
			{
				OpR1F_eraseAt(opR1f_d33d38,i);
				break;
			}
		}

		opR1f_cebd58 = opR1f_d33d38.size();
	}
}

void opR1f_466950(const string &text)	// NOTE: placeholder name
{
	if (opR1f_d33d48.empty() || text != opR1f_d33d48.back())
		opR1f_d33d48.push_back(text);

	for (int i = 0; i < (int)opR1f_d33d48.size() - 2; i++)
	{
		if (opR1f_d33d48[i] == text)
		{
			OpR1F_eraseAt(opR1f_d33d48,i);
			break;
		}
	}

	opR1f_cebd60 = opR1f_d33d48.size();
}

void logMessage(string location, string message);	// NOTE: placeholder name (0x404c70)

struct OpR1F_Achievement	// NOTE: placeholder name
{
	int unknown0;
	string name;
	int unknown20;
	int unknown24;
	int unknown28;
	int unknown2C;
};
extern vector<OpR1F_Achievement *> opR1f_cf09a8;	// NOTE: placeholder name

class OpR1F_PlayerAchievement	// NOTE: placeholder name
{
public:
	int ID;
	string name;
	int unknown20;
	int unknown24;
	int unknown28;
	int unknown2C;

	OpR1F_PlayerAchievement(istream &stream);
	void write(ostream &stream);
};

OpR1F_PlayerAchievement::OpR1F_PlayerAchievement(istream &stream)
{
	OpQ1_readString(stream,&name);
	readBinary(stream,&unknown20);
	readBinary(stream,&unknown24);
	readBinary(stream,&unknown28);
	readBinary(stream,&unknown2C);
	for (unsigned int i = 0; i < opR1f_cf09a8.size(); i++)
	{
		if (opR1f_cf09a8[i]->name == name)
		{
			ID = i;
			return;
		}
	}

	logMessage("PlayerAchievement(&f)","No achievement with tag \"" + name + "\", presumed removed from game");
	ID = -1;
}

void OpR1F_PlayerAchievement::write(ostream &stream)
{
	OpQ1_writeString(stream,name);
	writeBinary(stream,&unknown20);
	writeBinary(stream,&unknown24);
	writeBinary(stream,&unknown28);
	writeBinary(stream,&unknown2C);
}

string intToString(int value);
string &opR1f_padLeft(string &s, int width, char c);	// NOTE: placeholder name (0x408090)

class OpR1F_Number4675b0	// NOTE: placeholder name
{
public:
	char pad[0x24];
	int value24;

	string getPadded();	// NOTE: placeholder name
};

string OpR1F_Number4675b0::getPadded()
{
	string text = intToString(value24);
	opR1f_padLeft(text,6,'0');
	return text;
}

struct OpQ5_T9ed630;
template <class T> void OpQ5_deleteObjects(vector<T*> &v);	// NOTE: placeholder name

class OpR1F_GameMeta	// NOTE: placeholder name (GameMetaData?)
{
public:
	string unknown0;
	string unknown1C;
	int unknown38;
	string unknown3C;
	char pad58[0xb8 - 0x3c - 0x1c];
	string unknownB8;
	string unknownD4;
	int unknownF0;
	string unknownF4;
	char pad110[0x128 - 0xf4 - 0x1c];
	vector<int> unknown128;
	string unknown138;
	char pad154[0x158 - 0x138 - 0x1c];
	vector<string> unknown158;
	vector<int> unknown168;
	vector<string> unknown178;
	vector<OpQ5_T9ed630 *> unknown188;
	vector<string> unknown198;

	OpR1F_GameMeta();
	~OpR1F_GameMeta();
};

OpR1F_GameMeta::OpR1F_GameMeta()
{
}

OpR1F_GameMeta::~OpR1F_GameMeta()
{
	OpQ5_deleteObjects(unknown188);
}
