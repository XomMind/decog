// team_c_16: OpQ2_Rec69cbb0::load (0x69bff0), reader for OpQ2_Rec69cbb0::save (object at 0xd25450), with build-number gated fields
// NOTE: class/member names are placeholders
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include <istream>
using namespace std;


template <class T> void writeBinary(ostream &stream, T *value);
template <class T> void OpU8_readStructs(istream &stream, vector<T> &v);
template <class T> void OpS8d_readStructs(istream &stream, vector<T> &v);
template <class T> void OpQ5_readVectors(istream &stream, vector< vector<T> > &v);
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);
template <class T> void OpQ5_clearObjects(vector<T*> &v);
void OpT8a_readInts(istream &stream, vector<int> &v);
void OpQ1_readString(istream &in, string *text);
void OpQ1_readStringVector(istream &in, vector<string> *list);
struct OpS8a_P8 { int a; int b; OpS8a_P8(); void read(istream &stream); };
void OpS8a_readP8s(istream &stream, vector<OpS8a_P8> &v);
template <class T> void readBinary(istream &stream, T *value);
template <class T> void OpQ5_writeElements(ostream &stream, vector<T> &v);
template <class T> void OpS8a_writeRawVector(ostream &stream, vector<T> &v);
template <class T> void OpQ5_writeVectors(ostream &stream, vector< vector<T> > &v);
template <class T> void OpQ5_writeObjects(ostream &stream, vector<T*> &v);
template <class T> void OpQ5_writePointer(ostream &stream, T *&p);
void OpQ1_writeString(ostream &out, string text);
void writeStringRef_409740(ostream &out, const string &text);
void OpQ1_writeStringVector(ostream &out, vector<string> *list);

struct OpC_IntBox { int v; void write(ostream &stream); void read(istream &stream); };
struct OpU1_Point { int x; int y; void write(ostream &stream); void read(istream &stream); };
struct OpC_PointPair { OpU1_Point a; OpU1_Point b; void write(ostream &stream); void read(istream &stream); };	// NOTE: placeholder name (write folded with Calls_40b420::delegate)
template <class T> class OpS8a_Array2D { public: int width; int height; T *cells; void writeRaw(ostream &stream); };
struct OpU8_T9da130 { int m0; OpU8_T9da130(); void read(istream &s); };	// as in op_u8.cpp
struct OpQ5_U9d2090 { int pad; };	// NOTE: placeholder layout
struct OpS1e_Range { int min; int max; void read(istream &stream); };
struct OpC_Pair8 { int a; int b; void reset(); };	// NOTE: placeholder name (reset folded with Push_45fac0::operate)
string opr1c_convertBuildno_432720(const string &build);
bool OpT8b_Fn9dae40(const string &a, const string &b);
extern string str_d204b0;	// team_c_02.cpp: build string of the loaded save
extern int int_caf154;	// NOTE: placeholder name

class OpQ2_Rec69cbb0	// NOTE: placeholder layout (object at 0xd25450)
{
public:
	bool f0;
	int f4;
	int f8;
	OpC_IntBox fc;
	int f10;
	int f14;
	OpS1e_Range f18;
	vector<int> f20;
	vector<int> f30;
	vector<int> f40;
	vector<int> f50;
	vector<int> f60;
	int f70;
	int f74;
	int f78;
	int f7c;
	int f80;
	int f84;
	int f88;
	int f8c;
	int f90;
	int f94;
	int f98;
	int f9c;
	int fa0;
	bool fa4;
	OpC_Pair8 fa8;
	int fb0;
	vector<int> fb4;
	int fc4;
	int fc8;
	bool fcc;
	int fd0;
	int fd4;
	int fd8;
	int fdc;
	int fe0;
	int fe4;
	int fe8;
	int fec;
	int ff0;
	int ff4;
	int ff8;
	int ffc;
	int f100;
	int f104;
	int f108;
	int f10c;
	int f110;
	int f114;
	int f118;
	int f11c;
	vector<int> f120;
	vector<int> f130;
	int f140;
	OpC_IntBox f144;
	vector< vector<OpQ5_U9d2090> > f148;
	bool f158;
	bool f159;
	int f15c;
	bool f160;
	bool f161;
	bool f162;
	bool f163;
	int f164;
	int f168;
	OpC_PointPair f16c;
	int f17c;
	bool f180;
	vector<int> f184;
	int f194;
	vector<OpU8_T9da130> f198;
	int f1a8;
	int f1ac;
	int f1b0;
	OpC_IntBox f1b4;
	int f1b8;
	int f1bc;
	bool f1c0;
	bool f1c1;
	bool f1c2;
	int f1c4;
	int f1c8;
	int f1cc;
	bool f1d0;

	void load(istream &stream);
};

void OpQ2_Rec69cbb0::load(istream &stream)
{
	readBinary(stream,&f0);
	readBinary(stream,&f4);
	readBinary(stream,&f8);
	fc.read(stream);
	readBinary(stream,&f10);
	readBinary(stream,&f14);
	f18.read(stream);
	f20.clear();
	OpT8a_readInts(stream,f20);
	if (OpT8b_Fn9dae40(opr1c_convertBuildno_432720(str_d204b0),opr1c_convertBuildno_432720("260624a")))
	{
		f30.clear();
		OpT8a_readInts(stream,f30);
		f40.clear();
		OpT8a_readInts(stream,f40);
	}
	if (OpT8b_Fn9dae40(opr1c_convertBuildno_432720(str_d204b0),opr1c_convertBuildno_432720("260629a")))
	{
		f50.clear();
		OpT8a_readInts(stream,f50);
		f60.clear();
		OpT8a_readInts(stream,f60);
	}
	readBinary(stream,&f70);
	f74 = 0;
	readBinary(stream,&f78);
	readBinary(stream,&f7c);
	readBinary(stream,&f80);
	readBinary(stream,&f84);
	readBinary(stream,&f88);
	readBinary(stream,&f8c);
	readBinary(stream,&f90);
	f94 = 0;
	f98 = 0;
	readBinary(stream,&f9c);
	fa0 = int_caf154;
	fa4 = false;
	fa8.reset();
	readBinary(stream,&fb0);
	fb4.clear();
	OpT8a_readInts(stream,fb4);
	readBinary(stream,&fc4);
	readBinary(stream,&fc8);
	readBinary(stream,&fcc);
	readBinary(stream,&fd0);
	readBinary(stream,&fd4);
	readBinary(stream,&fd8);
	readBinary(stream,&fdc);
	readBinary(stream,&fe0);
	readBinary(stream,&fe4);
	readBinary(stream,&fe8);
	readBinary(stream,&fec);
	readBinary(stream,&ff0);
	readBinary(stream,&ff4);
	readBinary(stream,&ff8);
	readBinary(stream,&ffc);
	readBinary(stream,&f100);
	readBinary(stream,&f104);
	readBinary(stream,&f108);
	readBinary(stream,&f10c);
	readBinary(stream,&f110);
	readBinary(stream,&f114);
	readBinary(stream,&f118);
	readBinary(stream,&f11c);
	f120.clear();
	OpT8a_readInts(stream,f120);
	f130.clear();
	OpT8a_readInts(stream,f130);
	readBinary(stream,&f140);
	if (OpT8b_Fn9dae40(opr1c_convertBuildno_432720(str_d204b0),opr1c_convertBuildno_432720("260629a")))
	{
		f144.read(stream);
	}
	f148.clear();
	OpQ5_readVectors(stream,f148);
	readBinary(stream,&f158);
	if (OpT8b_Fn9dae40(opr1c_convertBuildno_432720(str_d204b0),opr1c_convertBuildno_432720("260624a")))
		readBinary(stream,&f159);
	else
		f159 = true;
	readBinary(stream,&f15c);
	readBinary(stream,&f160);
	readBinary(stream,&f161);
	readBinary(stream,&f162);
	readBinary(stream,&f163);
	readBinary(stream,&f164);
	readBinary(stream,&f168);
	f16c.read(stream);
	readBinary(stream,&f17c);
	readBinary(stream,&f180);
	f184.clear();
	OpT8a_readInts(stream,f184);
	readBinary(stream,&f194);
	f198.clear();
	OpU8_readStructs(stream,f198);
	readBinary(stream,&f1a8);
	readBinary(stream,&f1ac);
	readBinary(stream,&f1b0);
	f1b4.read(stream);
	readBinary(stream,&f1b8);
	readBinary(stream,&f1bc);
	readBinary(stream,&f1c0);
	readBinary(stream,&f1c1);
	readBinary(stream,&f1c2);
	readBinary(stream,&f1c4);
	readBinary(stream,&f1c8);
	readBinary(stream,&f1cc);
	readBinary(stream,&f1d0);
	// ??? 0ba8 None 0xaa0d0f
}
