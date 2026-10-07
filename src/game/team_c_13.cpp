// team_c_13: GameData::serialize (0x787770): writes the game-wide state at 0xd1e860 field by field
// NOTE: member names are placeholders (f<offset>); element types carry the names of the folded instances

#include <string>
#include <vector>
#include <map>
#include <ostream>
using namespace std;

struct OpQ5_T9df390;	// NOTE: placeholder (element type)
struct OpQ5_U9d0840;	// NOTE: placeholder (element type)
struct OpQ5_U9d2190;	// NOTE: placeholder (element type)
struct OpQ5_U9d9600;	// NOTE: placeholder (element type)
struct OpQ5_U9dbee0;	// NOTE: placeholder (element type)
struct OpQ5_U9df330;	// NOTE: placeholder (element type)

template <class T> void writeBinary(ostream &stream, T *value);
template <class T> void OpQ5_writeElements(ostream &stream, vector<T> &v);
template <class T> void OpS8a_writeRawVector(ostream &stream, vector<T> &v);
template <class T> void OpQ5_writeVectors(ostream &stream, vector< vector<T> > &v);
template <class T> void OpQ5_writeObjects(ostream &stream, vector<T*> &v);
void OpQ1_writeString(ostream &out, string text);
void OpQ1_writeStringVector(ostream &out, vector<string> *list);

struct OpC_IntBox { int v; void write(ostream &stream); };
struct OpU1_Point { int x; int y; void write(ostream &stream); };
struct OpC_PointPair { OpU1_Point a; OpU1_Point b; void write(ostream &stream); };	// NOTE: placeholder name (write folded with Calls_40b420::delegate)
template <class T> class OpS8a_Array2D { public: int width; int height; T *cells; void writeRaw(ostream &stream); };

class GameData	// NOTE: placeholder layout (object at 0xd1e860)
{
public:
	int f0;
	string f4;
	bool f20;
	OpC_IntBox f24;
	OpC_IntBox f28;
	vector<OpQ5_U9d9600> f2c;
	vector<OpQ5_U9df330> f3c;
	vector<int> f4c;
	int f5c;
	vector<int> f60;
	vector<int> f70;
	vector< vector<OpQ5_U9d2190> > f80;
	vector< vector<OpQ5_U9d2190> > f90;
	vector<string> fa0;
	vector<int> fb0;
	vector<int> fc0;
	vector<string> fd0;
	vector<int> fe0;
	vector<int> ff0;
	map<string,string> names100;
	OpS8a_Array2D<int> grid110;
	vector<OpQ5_T9df390 *> lists11c[15];
	vector<int> f20c;
	vector<OpQ5_U9d9600> f21c;
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
	vector<OpQ5_U9d9600> f3a0;
	vector<OpQ5_U9d0840> f3b0;
	vector<OpQ5_U9d0840> f3c0;
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
	vector<OpQ5_U9dbee0> f414;
	vector<int> f424;
	vector<int> f434;

	void serialize(ostream &stream);
};

void GameData::serialize(ostream &stream)
{
	writeBinary(stream,&f0);
	OpQ1_writeString(stream,f4);
	writeBinary(stream,&f20);
	f24.write(stream);
	f28.write(stream);
	OpQ5_writeElements(stream,f2c);
	OpQ5_writeElements(stream,f3c);
	OpS8a_writeRawVector(stream,f4c);
	writeBinary(stream,&f5c);
	OpS8a_writeRawVector(stream,f60);
	OpS8a_writeRawVector(stream,f70);
	OpQ5_writeVectors(stream,f80);
	OpQ5_writeVectors(stream,f90);
	OpQ1_writeStringVector(stream,&fa0);
	OpS8a_writeRawVector(stream,fb0);
	OpS8a_writeRawVector(stream,fc0);
	OpQ1_writeStringVector(stream,&fd0);
	OpS8a_writeRawVector(stream,fe0);
	OpS8a_writeRawVector(stream,ff0);
	int count = names100.size();
	writeBinary(stream,&count);
	map<string,string>::iterator iter = names100.begin();
	while (iter != names100.end())
	{
		OpQ1_writeString(stream,iter->first);
		OpQ1_writeString(stream,iter->second);
		++iter;
	}
	grid110.writeRaw(stream);
	for (int i = 0; i < 15; i++)
		OpQ5_writeObjects(stream,lists11c[i]);
	OpS8a_writeRawVector(stream,f20c);
	OpQ5_writeElements(stream,f21c);
	OpQ1_writeStringVector(stream,&f22c);
	OpS8a_writeRawVector(stream,f23c);
	writeBinary(stream,&f24c);
	writeBinary(stream,&f24d);
	writeBinary(stream,&f250);
	writeBinary(stream,&f254);
	writeBinary(stream,&f258);
	writeBinary(stream,&f25c);
	writeBinary(stream,&f25d);
	writeBinary(stream,&f260);
	writeBinary(stream,&f264);
	writeBinary(stream,&f268);
	writeBinary(stream,&f26c);
	writeBinary(stream,&f270);
	writeBinary(stream,&f274);
	writeBinary(stream,&f278);
	f27c.write(stream);
	writeBinary(stream,&f280);
	writeBinary(stream,&f284);
	f288.write(stream);
	f298.write(stream);
	writeBinary(stream,&f2a8);
	writeBinary(stream,&f2ac);
	writeBinary(stream,&f2b0);
	writeBinary(stream,&f2b4);
	writeBinary(stream,&f2b8);
	writeBinary(stream,&f2bc);
	writeBinary(stream,&f2c0);
	writeBinary(stream,&f2c4);
	writeBinary(stream,&f2c8);
	writeBinary(stream,&f2cc);
	writeBinary(stream,&f2d0);
	writeBinary(stream,&f2d4);
	writeBinary(stream,&f2d8);
	writeBinary(stream,&f2dc);
	writeBinary(stream,&f2e0);
	OpS8a_writeRawVector(stream,f2e4);
	writeBinary(stream,&f2f4);
	writeBinary(stream,&f2f8);
	writeBinary(stream,&f2fc);
	writeBinary(stream,&f300);
	writeBinary(stream,&f304);
	writeBinary(stream,&f308);
	writeBinary(stream,&f30c);
	writeBinary(stream,&f310);
	writeBinary(stream,&f314);
	OpQ1_writeStringVector(stream,&f318);
	OpS8a_writeRawVector(stream,f328);
	writeBinary(stream,&f338);
	writeBinary(stream,&f339);
	OpS8a_writeRawVector(stream,f33c);
	writeBinary(stream,&f34c);
	f350.write(stream);
	writeBinary(stream,&f358);
	writeBinary(stream,&f35c);
	writeBinary(stream,&f360);
	writeBinary(stream,&f364);
	writeBinary(stream,&f368);
	writeBinary(stream,&f36c);
	writeBinary(stream,&f370);
	writeBinary(stream,&f374);
	f378.write(stream);
	writeBinary(stream,&f37c);
	f380.write(stream);
	f384.write(stream);
	writeBinary(stream,&f388);
	writeBinary(stream,&f38c);
	writeBinary(stream,&f38d);
	writeBinary(stream,&f38e);
	writeBinary(stream,&f390);
	writeBinary(stream,&f394);
	writeBinary(stream,&f398);
	writeBinary(stream,&f39c);
	OpQ5_writeElements(stream,f3a0);
	OpQ5_writeElements(stream,f3b0);
	OpQ5_writeElements(stream,f3c0);
	OpS8a_writeRawVector(stream,f3d0);
	OpS8a_writeRawVector(stream,f3e0);
	writeBinary(stream,&f3f0);
	writeBinary(stream,&f3f4);
	writeBinary(stream,&f3f8);
	writeBinary(stream,&f3fc);
	writeBinary(stream,&f400);
	writeBinary(stream,&f404);
	writeBinary(stream,&f408);
	f40c.write(stream);
	OpQ5_writeElements(stream,f414);
	OpS8a_writeRawVector(stream,f424);
	OpS8a_writeRawVector(stream,f434);
}
