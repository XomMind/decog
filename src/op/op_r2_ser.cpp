// op_r2: record readers/writers in 0x4fe000-0x514000 (placeholder record names), Beta 17.1.
// NOTE: placeholder names
#include <vector>
#include <string>
#include <istream>
#include <ostream>
using namespace std;

template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name
template <class T> void writeBinary(ostream &stream, T *value);	// NOTE: placeholder name
void OpQ1_writeString(ostream &out, string text);	// 0x409650
void OpQ1_readString(istream &in, string *text);	// 0x4096f0
void opr2_readText_436960(istream &stream, string *value);	// NOTE: placeholder name (0x436960)
void opr2_readIntArray_9d4ec0(istream &stream, int *values);	// NOTE: placeholder name (0x9d4ec0)

template <class T> void OpQ5_readReference(istream &stream, T *&p, vector<T*> &list);	// NOTE: placeholder name
template <class T> void OpQ5_writeObjects(ostream &stream, vector<T*> &v);	// NOTE: placeholder name

struct OpQ5_T9d5880;
struct OpQ5_T9d5970;
struct OpQ5_T9d5da0;
struct OpQ5_T9d5e90;
struct OpQ5_T9d5f80;
struct OpQ5_T9d6070;
void opr2_writeReference_9da000(ostream &stream, OpQ5_T9d5f80 *p);	// NOTE: placeholder name (0x9da000)

extern vector<OpQ5_T9d5880*> opr2_cfd2ec;	// NOTE: placeholder name
extern vector<OpQ5_T9d5970*> opr2_d35870;	// NOTE: placeholder name
extern vector<OpQ5_T9d5da0*> opr2_cfe704;	// NOTE: placeholder name
extern vector<OpQ5_T9d5e90*> opr2_d1e31c;	// NOTE: placeholder name
extern vector<OpQ5_T9d5f80*> opr2_d2b4d8;	// NOTE: placeholder name

struct OpR2_Rec4feee0
{
	int unknown0;
	string unknown4;
	int unknown20;
	int unknown24;
	int unknown28;

	OpR2_Rec4feee0(istream &stream);	// 0x4feee0
};

OpR2_Rec4feee0::OpR2_Rec4feee0(istream &stream)
{
	readBinary(stream,&unknown0);
	opr2_readText_436960(stream,&unknown4);
	readBinary(stream,&unknown20);
	readBinary(stream,&unknown24);
	unknown28 = 0;
}

struct OpR2_Rec500f10
{
	int unknown0;
	int unknown4;
	int unknown8;
	int unknownC;
	int unknown10;
	int unknown14;
	int unknown18;
	int unknown1C;
	int unknown20;
	int unknown24;
	int unknown28;
	int unknown2C;
	int unknown30;
	int unknown34;
	bool unknown38;

	void read(istream &stream);	// 0x500f10
};

void OpR2_Rec500f10::read(istream &stream)
{
	readBinary(stream,&unknown4);
	readBinary(stream,&unknown8);
	readBinary(stream,&unknownC);
	readBinary(stream,&unknown10);
	readBinary(stream,&unknown14);
	readBinary(stream,&unknown18);
	readBinary(stream,&unknown1C);
	readBinary(stream,&unknown20);
	readBinary(stream,&unknown24);
	readBinary(stream,&unknown28);
	readBinary(stream,&unknown2C);
	readBinary(stream,&unknown30);
	readBinary(stream,&unknown34);
	readBinary(stream,&unknown38);
}

struct OpR2_Rec508930
{
	int unknown0;
	int unknown4;
	int unknown8;
	int unknownC;
	int unknown10;
	int unknown14;
	bool unknown18;
	int unknown1C;
	int unknown20;
	int unknown24;
	int unknown28;
	int unknown2C;
	int unknown30;
	int unknown34;
	int unknown38;
	int unknown3C;
	int unknown40;
	bool unknown44;

	void read(istream &stream);	// 0x508930
};

void OpR2_Rec508930::read(istream &stream)
{
	readBinary(stream,&unknown4);
	readBinary(stream,&unknown8);
	readBinary(stream,&unknownC);
	readBinary(stream,&unknown10);
	readBinary(stream,&unknown14);
	readBinary(stream,&unknown18);
	readBinary(stream,&unknown1C);
	readBinary(stream,&unknown20);
	readBinary(stream,&unknown24);
	readBinary(stream,&unknown28);
	readBinary(stream,&unknown2C);
	readBinary(stream,&unknown30);
	readBinary(stream,&unknown34);
	readBinary(stream,&unknown38);
	readBinary(stream,&unknown3C);
	readBinary(stream,&unknown40);
	readBinary(stream,&unknown44);
}

struct OpR2_Rec508a80
{
	int unknown0;
	int unknown4;
	int unknown8;
	OpQ5_T9d5880 *unknownC;
	OpQ5_T9d5970 *unknown10;
	int unknown14;

	void read(istream &stream);	// 0x508a80
};

void OpR2_Rec508a80::read(istream &stream)
{
	readBinary(stream,&unknown0);
	readBinary(stream,&unknown4);
	readBinary(stream,&unknown8);
	OpQ5_readReference(stream,unknownC,opr2_cfd2ec);
	OpQ5_readReference(stream,unknown10,opr2_d35870);
	readBinary(stream,&unknown14);
}

struct OpR2_Rec510ba0
{
	int unknown0;
	string unknown4;
	OpQ5_T9d5da0 *unknown20;
	OpQ5_T9d5da0 *unknown24;

	OpR2_Rec510ba0(istream &stream);	// 0x510ba0
};

OpR2_Rec510ba0::OpR2_Rec510ba0(istream &stream)
{
	readBinary(stream,&unknown0);
	opr2_readText_436960(stream,&unknown4);
	OpQ5_readReference(stream,unknown20,opr2_cfe704);
	OpQ5_readReference(stream,unknown24,opr2_cfe704);
}

struct OpR2_Rec510c50
{
	int unknown0;
	string unknown4;
	int unknown20;
	OpQ5_T9d5e90 *unknown24;
	string unknown28;

	OpR2_Rec510c50(istream &stream);	// 0x510c50
};

OpR2_Rec510c50::OpR2_Rec510c50(istream &stream)
{
	readBinary(stream,&unknown0);
	opr2_readText_436960(stream,&unknown4);
	readBinary(stream,&unknown20);
	OpQ5_readReference(stream,unknown24,opr2_d1e31c);
	OpQ1_readString(stream,&unknown28);
}

struct OpR2_Rec510dc0
{
	int unknown0;
	string unknown4;
	int unknown20;
	int unknown24[1];	// NOTE: placeholder size

	OpR2_Rec510dc0(istream &stream);	// 0x510dc0
};

OpR2_Rec510dc0::OpR2_Rec510dc0(istream &stream)
{
	readBinary(stream,&unknown0);
	opr2_readText_436960(stream,&unknown4);
	readBinary(stream,&unknown20);
	opr2_readIntArray_9d4ec0(stream,unknown24);
}

struct OpR2_Rec510e60
{
	int unknown0;
	string unknown4;
	int unknown20;
	int unknown24;
	string unknown28;
	bool unknown44;
	bool unknown45;
	bool unknown46;
	bool unknown47;
	bool unknown48;

	OpR2_Rec510e60(istream &stream);	// 0x510e60
};

OpR2_Rec510e60::OpR2_Rec510e60(istream &stream)
{
	readBinary(stream,&unknown0);
	opr2_readText_436960(stream,&unknown4);
	readBinary(stream,&unknown20);
	readBinary(stream,&unknown24);
	OpQ1_readString(stream,&unknown28);
	readBinary(stream,&unknown44);
	readBinary(stream,&unknown45);
	readBinary(stream,&unknown46);
	readBinary(stream,&unknown47);
	readBinary(stream,&unknown48);
}

struct OpR2_Rec511130
{
	OpQ5_T9d5f80 *unknown0;
	string unknown4;
	int unknown20;
	int unknown24;

	OpR2_Rec511130(istream &stream);	// 0x511130
	void serialize(ostream &stream);	// 0x5110c0
};

OpR2_Rec511130::OpR2_Rec511130(istream &stream)
{
	OpQ5_readReference(stream,unknown0,opr2_d2b4d8);
	OpQ1_readString(stream,&unknown4);
	readBinary(stream,&unknown20);
	readBinary(stream,&unknown24);
}

void OpR2_Rec511130::serialize(ostream &stream)
{
	opr2_writeReference_9da000(stream,unknown0);
	OpQ1_writeString(stream,unknown4);
	writeBinary(stream,&unknown20);
	writeBinary(stream,&unknown24);
}

struct OpR2_Rec511f40
{
	vector<OpQ5_T9d6070*> unknown0;
	string unknown10;
	int unknown2C;
	bool unknown30;

	void serialize(ostream &stream);	// 0x511f40
};

void OpR2_Rec511f40::serialize(ostream &stream)
{
	OpQ5_writeObjects(stream,unknown0);
	OpQ1_writeString(stream,unknown10);
	writeBinary(stream,&unknown2C);
	writeBinary(stream,&unknown30);
}

struct OpR2_Rec513f70
{
	int unknown0;
	string unknown4;
	int unknown20;
	int unknown24;
	bool unknown28;
	bool unknown29;
	string unknown2C;

	OpR2_Rec513f70(istream &stream);	// 0x513f70
};

OpR2_Rec513f70::OpR2_Rec513f70(istream &stream)
{
	readBinary(stream,&unknown0);
	opr2_readText_436960(stream,&unknown4);
	readBinary(stream,&unknown20);
	readBinary(stream,&unknown24);
	readBinary(stream,&unknown28);
	readBinary(stream,&unknown29);
	OpQ1_readString(stream,&unknown2C);
}

template void readBinary<int>(istream &stream, int *value);
template void readBinary<bool>(istream &stream, bool *value);
template void writeBinary<int>(ostream &stream, int *value);
template void writeBinary<bool>(ostream &stream, bool *value);
