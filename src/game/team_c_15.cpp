// team_c_15: GameData::unserialize (0x7881a0): reads the game-wide state at 0xd1e860 field by field
// NOTE: member names are placeholders (f<offset>); element types carry the names of the folded instances
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include <istream>
using namespace std;

struct OpQ5_T9df4d0;	// NOTE: placeholder (element type)

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
struct OpQ5_T9df4d0;
struct OpQ5_T9ed8f0;
struct OpU8_T9da130 { int m0; OpU8_T9da130(); void read(istream &s); };	// as in op_u8.cpp
struct OpQ5_U9d2090 { int pad; };	// NOTE: placeholder layout
struct OpS8d_Pair16 { int a, b, c, d; OpS8d_Pair16(); void read(istream &stream); };	// as in op_s8d_a.cpp
struct OpC_E30 { char pad[0x30]; };	// NOTE: placeholder name/layout
void OpC_read9df3f0(istream &stream, vector<OpC_E30> &v);	// NOTE: placeholder name (0x9df3f0)
struct OpS7_IntGrid2 { int width; int height; int *cells; void read_9cee40(istream &stream); };
string opr1c_convertBuildno_432720(const string &build);
extern string str_d204b0;	// team_c_02.cpp: build string of the loaded save

class GameData	// NOTE: placeholder layout (object at 0xd1e860)
{
public:
	int f0;
	string f4;
	bool f20;
	OpC_IntBox f24;
	OpC_IntBox f28;
	vector<OpU8_T9da130> f2c;
	vector<OpC_E30> f3c;
	vector<int> f4c;
	int f5c;
	vector<int> f60;
	vector<int> f70;
	vector< vector<OpQ5_U9d2090> > f80;
	vector< vector<OpQ5_U9d2090> > f90;
	vector<string> fa0;
	vector<int> fb0;
	vector<int> fc0;
	vector<string> fd0;
	vector<int> fe0;
	vector<int> ff0;
	map<string,string> f100;
	OpS7_IntGrid2 f110;
	vector<OpQ5_T9df4d0 *> f11c[15];
	vector<int> f20c;
	vector<OpU8_T9da130> f21c;
	vector<string> f22c;
	vector<int> f23c;
	bool f24c;
	bool f24d;
	int f250;
	int f254;
	int f258;
	bool f25c;
	bool f25d;
	int f260;
	int f264;
	int f268;
	bool f26c;
	int f270;
	int f274;
	int f278;
	OpC_IntBox f27c;
	int f280;
	int f284;
	OpC_PointPair f288;
	OpC_PointPair f298;
	int f2a8;
	int f2ac;
	int f2b0;
	int f2b4;
	bool f2b8;
	int f2bc;
	int f2c0;
	int f2c4;
	int f2c8;
	int f2cc;
	int f2d0;
	int f2d4;
	int f2d8;
	int f2dc;
	int f2e0;
	vector<int> f2e4;
	int f2f4;
	int f2f8;
	int f2fc;
	int f300;
	int f304;
	int f308;
	int f30c;
	int f310;
	int f314;
	vector<string> f318;
	vector<int> f328;
	bool f338;
	bool f339;
	vector<int> f33c;
	int f34c;
	OpU1_Point f350;
	int f358;
	bool f35c;
	int f360;
	bool f364;
	int f368;
	int f36c;
	int f370;
	bool f374;
	OpC_IntBox f378;
	int f37c;
	OpC_IntBox f380;
	OpC_IntBox f384;
	int f388;
	bool f38c;
	bool f38d;
	bool f38e;
	int f390;
	int f394;
	int f398;
	bool f39c;
	vector<OpU8_T9da130> f3a0;
	vector<OpS8a_P8> f3b0;
	vector<OpS8a_P8> f3c0;
	vector<int> f3d0;
	vector<int> f3e0;
	int f3f0;
	int f3f4;
	int f3f8;
	int f3fc;
	int f400;
	int f404;
	int f408;
	OpU1_Point f40c;
	vector<OpS8d_Pair16> f414;
	vector<int> f424;
	vector<int> f434;

	void unserialize(istream &stream);
};

void GameData::unserialize(istream &stream)
{
	readBinary(stream,&f0);
	f4.clear();
	OpQ1_readString(stream,&f4);
	readBinary(stream,&f20);
	f24.read(stream);
	f28.read(stream);
	f2c.clear();
	OpU8_readStructs(stream,f2c);
	f3c.clear();
	OpC_read9df3f0(stream,f3c);
	f4c.clear();
	OpT8a_readInts(stream,f4c);
	readBinary(stream,&f5c);
	f60.clear();
	OpT8a_readInts(stream,f60);
	f70.clear();
	OpT8a_readInts(stream,f70);
	f80.clear();
	OpQ5_readVectors(stream,f80);
	f90.clear();
	OpQ5_readVectors(stream,f90);
	fa0.clear();
	OpQ1_readStringVector(stream,&fa0);
	fb0.clear();
	OpT8a_readInts(stream,fb0);
	fc0.clear();
	OpT8a_readInts(stream,fc0);
	fd0.clear();
	OpQ1_readStringVector(stream,&fd0);
	fe0.clear();
	OpT8a_readInts(stream,fe0);
	ff0.clear();
	OpT8a_readInts(stream,ff0);
	f100.clear();
	int count;
	readBinary(stream,&count);
	for (int i = 0; i < count; i++)
	{
		string key;
		string value;
		OpQ1_readString(stream,&key);
		OpQ1_readString(stream,&value);
		f100.insert(map<string,string>::value_type(key,value));
	}
	f110.read_9cee40(stream);
	for (int j = 0; j < 15; j++)
	{
		OpQ5_clearObjects((vector<OpQ5_T9ed8f0 *> &)f11c[j]);
		OpQ5_readObjects(stream,f11c[j],0);
	}
	f20c.clear();
	OpT8a_readInts(stream,f20c);
	f21c.clear();
	OpU8_readStructs(stream,f21c);
	f22c.clear();
	OpQ1_readStringVector(stream,&f22c);
	f23c.clear();
	OpT8a_readInts(stream,f23c);
	readBinary(stream,&f24c);
	readBinary(stream,&f24d);
	readBinary(stream,&f250);
	readBinary(stream,&f254);
	readBinary(stream,&f258);
	readBinary(stream,&f25c);
	readBinary(stream,&f25d);
	readBinary(stream,&f260);
	readBinary(stream,&f264);
	readBinary(stream,&f268);
	readBinary(stream,&f26c);
	readBinary(stream,&f270);
	readBinary(stream,&f274);
	readBinary(stream,&f278);
	f27c.read(stream);
	readBinary(stream,&f280);
	readBinary(stream,&f284);
	f288.read(stream);
	f298.read(stream);
	readBinary(stream,&f2a8);
	readBinary(stream,&f2ac);
	readBinary(stream,&f2b0);
	readBinary(stream,&f2b4);
	readBinary(stream,&f2b8);
	readBinary(stream,&f2bc);
	readBinary(stream,&f2c0);
	readBinary(stream,&f2c4);
	readBinary(stream,&f2c8);
	readBinary(stream,&f2cc);
	readBinary(stream,&f2d0);
	readBinary(stream,&f2d4);
	readBinary(stream,&f2d8);
	readBinary(stream,&f2dc);
	readBinary(stream,&f2e0);
	f2e4.clear();
	OpT8a_readInts(stream,f2e4);
	readBinary(stream,&f2f4);
	readBinary(stream,&f2f8);
	readBinary(stream,&f2fc);
	readBinary(stream,&f300);
	readBinary(stream,&f304);
	readBinary(stream,&f308);
	readBinary(stream,&f30c);
	readBinary(stream,&f310);
	readBinary(stream,&f314);
	f318.clear();
	OpQ1_readStringVector(stream,&f318);
	f328.clear();
	OpT8a_readInts(stream,f328);
	readBinary(stream,&f338);
	readBinary(stream,&f339);
	f33c.clear();
	OpT8a_readInts(stream,f33c);
	readBinary(stream,&f34c);
	f350.read(stream);
	readBinary(stream,&f358);
	readBinary(stream,&f35c);
	readBinary(stream,&f360);
	readBinary(stream,&f364);
	readBinary(stream,&f368);
	readBinary(stream,&f36c);
	readBinary(stream,&f370);
	readBinary(stream,&f374);
	f378.read(stream);
	readBinary(stream,&f37c);
	f380.read(stream);
	f384.read(stream);
	readBinary(stream,&f388);
	readBinary(stream,&f38c);
	readBinary(stream,&f38d);
	readBinary(stream,&f38e);
	readBinary(stream,&f390);
	readBinary(stream,&f394);
	readBinary(stream,&f398);
	readBinary(stream,&f39c);
	f3a0.clear();
	OpU8_readStructs(stream,f3a0);
	f3b0.clear();
	OpS8a_readP8s(stream,f3b0);
	f3c0.clear();
	OpS8a_readP8s(stream,f3c0);
	f3d0.clear();
	OpT8a_readInts(stream,f3d0);
	f3e0.clear();
	OpT8a_readInts(stream,f3e0);
	readBinary(stream,&f3f0);
	readBinary(stream,&f3f4);
	readBinary(stream,&f3f8);
	readBinary(stream,&f3fc);
	readBinary(stream,&f400);
	readBinary(stream,&f404);
	if (opr1c_convertBuildno_432720(str_d204b0) >= opr1c_convertBuildno_432720("260819a"))
		readBinary(stream,&f408);
	else
		f408 = 0;
	f40c.read(stream);
	f414.clear();
	OpS8d_readStructs(stream,f414);
	f424.clear();
	OpT8a_readInts(stream,f424);
	f434.clear();
	OpT8a_readInts(stream,f434);
	// ??? 0ede None 0xaa0d0f
}
