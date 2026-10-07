// team_c_23: BS::serialize (0x70e640): writes the battle scape (map object at 0xcefc4c) and its per-map globals
// NOTE: member names are placeholders (f<offset>); globals carry the exe address; element types carry the names of the folded instances
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include <istream>
using namespace std;

class Cell;
struct Point { int x; int y; Point(); Point(const Point &p) throw(); Point &operator=(const Point &p); };
template <class T> void writeBinary(ostream &stream, T *value);
template <class T> void readBinary(istream &stream, T *value);
template <class T> void OpQ5_writeElements(ostream &stream, vector<T> &v);
template <class T> void OpS8a_writeRawVector(ostream &stream, vector<T> &v);
template <class T> void OpQ5_writeVectors(ostream &stream, vector< vector<T> > &v);
template <class T> void OpQ5_writeObjects(ostream &stream, vector<T*> &v);
template <class T> void OpQ5_writePointer(ostream &stream, T *&p);
void OpQ1_writeString(ostream &out, string text);
void writeStringRef_409740(ostream &out, const string &text);
void OpQ1_writeStringVector(ostream &out, vector<string> *list);
void OpS8c_writePoints(ostream &stream, vector<Point> &v);
struct OpC_IntBox { int v; void write(ostream &stream); void read(istream &stream); };
struct OpU1_Point { int x; int y; void write(ostream &stream); void read(istream &stream); };
struct OpC_PointPair { OpU1_Point a; OpU1_Point b; void write(ostream &stream); void read(istream &stream); };	// NOTE: placeholder name (folded with Calls_40b420/40b450::delegate)
template <class T> class OpS8a_Array2D { public: int width; int height; T *cells; void write(ostream &stream); void writeRaw(ostream &stream); void read(istream &stream); };
struct TeamB_6722d0 { char pad[0x10]; void serialize(ostream &stream); };	// NOTE: placeholder layout
struct OpR2_Rec511f40 { void serialize(ostream &stream); };	// NOTE: placeholder layout
struct OpS8a_G20; struct OpS8a_G34;
template <class T> class OpS8a_Grid { public: int width; int height; T *cells; void write(ostream &stream); };
struct OpQ5_T9dbe20;
struct OpQ5_T9dbe80;
struct OpQ5_T9dc000;
struct OpQ5_T9dc060;
struct OpQ5_T9dc0c0;
struct OpQ5_T9dc120;
struct OpQ5_T9dc180;
struct OpQ5_T9dc1e0;
struct OpQ5_T9dc240;
struct OpQ5_T9dc2a0;
struct OpQ5_T9dc2e0;
struct OpQ5_T9dc320;
struct OpQ5_T9dc380;
struct OpQ5_T9dc3e0;
struct OpQ5_T9dc440;
struct OpQ5_T9dc4a0;
struct OpQ5_T9dc560;
struct OpQ5_T9dc5c0;
struct OpQ5_T9dea20;
struct OpQ5_U9d0840;
struct OpQ5_U9d2190;
struct OpQ5_U9d9600;
struct OpQ5_U9da850;
struct OpQ5_U9dbee0;
struct OpQ5_U9dbf40;
struct OpQ5_U9dbfa0;
struct OpQ5_U9dc500;
struct OpV4b_Ints3 { vector<int> list0; vector<int> list10; int value20; void OpV4b_write(ostream &stream); };
struct OpQ5_T9e13a0;
struct OpV4b_Objs3 { vector<OpQ5_T9e13a0 *> objects; vector<int> list10; int value20; void OpV4b_write(ostream &stream); };
class JLog { public: int end(int type); };
extern JLog *jlog_cefa64;	// NOTE: placeholder name
void logInfo(string location, string message);
extern int g_cec34c;	// NOTE: placeholder name
extern int g_cefbb4;	// NOTE: placeholder name
extern vector<OpQ5_T9dc180 *> g_cf0fa8;	// NOTE: placeholder name
extern OpR2_Rec511f40 g_cf1080;	// NOTE: placeholder name
extern OpS8a_Array2D<int> g_cf11a0;	// NOTE: placeholder name
extern vector<OpQ5_U9d9600> g_cf25b8;	// NOTE: placeholder name
extern vector<OpQ5_T9dbe80 *> g_cf3a00;	// NOTE: placeholder name
extern vector< vector<OpQ5_U9dbf40> > g_cf3a10;	// NOTE: placeholder name
extern vector< vector<OpQ5_U9dbfa0> > g_cf44b0;	// NOTE: placeholder name
extern vector<int> g_cfc1a4;	// NOTE: placeholder name
extern OpS8a_Array2D<Cell *> g_cfd44c;	// NOTE: placeholder name
extern vector<OpQ5_U9d0840> g_d01b28;	// NOTE: placeholder name
extern vector<int> g_d02b64;	// NOTE: placeholder name
extern vector<OpQ5_U9d0840> g_d1daec;	// NOTE: placeholder name
extern vector< vector<OpQ5_U9dbf40> > g_d20248;	// NOTE: placeholder name
extern vector<OpQ5_U9dbee0> g_d204cc;	// NOTE: placeholder name
extern vector<OpQ5_U9d0840> g_d20690;	// NOTE: placeholder name
extern TeamB_6722d0 g_d225a0;	// NOTE: placeholder name
extern vector<OpQ5_T9dbe20 *> g_d22744;	// NOTE: placeholder name
extern vector<OpQ5_U9dbee0> g_d22fa8;	// NOTE: placeholder name
extern bool g_d28d30;	// NOTE: placeholder name
extern vector<int> g_d2a2cc;	// NOTE: placeholder name
extern vector<int> g_d2a520;	// NOTE: placeholder name
extern vector<OpQ5_U9dbee0> g_d2b274;	// NOTE: placeholder name
extern vector< vector<OpQ5_U9da850> > g_d2f32c;	// NOTE: placeholder name
extern OpR2_Rec511f40 g_d2f75c;	// NOTE: placeholder name
extern vector< vector<OpQ5_U9dbf40> > g_d31640;	// NOTE: placeholder name
extern vector<int> g_d3239c;	// NOTE: placeholder name
extern vector<OpQ5_U9d9600> g_d33d74;	// NOTE: placeholder name
extern vector<OpQ5_U9d0840> g_d35860;	// NOTE: placeholder name
extern vector<OpQ5_U9d9600> g_d37984;	// NOTE: placeholder name
extern vector<OpQ5_T9dc000 *> g_d39f1c;	// NOTE: placeholder name
extern OpS8a_Array2D<int> originalTerrain;
extern int *TERRAIN_CAVE_WALL;
extern int *TERRAIN_EARTH;
extern int *caveinThirdTerrain;
extern int *p_cefb84;	// NOTE: placeholder name
extern int *p_cefb88;	// NOTE: placeholder name
extern int *p_cefb8c;	// NOTE: placeholder name
extern int *p_cefb90;	// NOTE: placeholder name
extern int *p_cefb94;	// NOTE: placeholder name
extern int *p_cefb98;	// NOTE: placeholder name
extern int *p_cefb9c;	// NOTE: placeholder name
extern int *p_cefba8;	// NOTE: placeholder name
extern int *p_cefbac;	// NOTE: placeholder name
extern int *p_cefbb0;	// NOTE: placeholder name

class BS	// NOTE: placeholder layout
{
public:
	bool f0;
	char pad4[0x4];
	OpU1_Point f8;
	vector<OpQ5_T9dc060 *> f10;
	vector<OpQ5_T9dc0c0 *> f20;
	bool f30;
	int f34;
	char pad38[0x10];
	OpC_IntBox f48;
	vector<OpQ5_U9d9600> f4c;
	OpS8a_Array2D<int> f5c;
	OpV4b_Ints3 f68;
	OpV4b_Ints3 f8c;
	vector<int> fb0;
	OpV4b_Ints3 fc0;
	vector<int> fe4;
	vector<OpQ5_U9d0840> ff4;
	int f104;
	vector< vector<OpQ5_U9d0840> > f108;
	vector< vector<OpQ5_U9d0840> > f118;
	vector< vector<OpQ5_U9d0840> > f128;
	vector<OpQ5_U9d0840> f138;
	vector<OpQ5_U9d0840> f148;
	vector<OpQ5_U9d0840> f158;
	vector<int> f168;
	vector<OpQ5_U9d9600> f178;
	vector<OpQ5_U9d9600> f188;
	vector<OpQ5_U9d0840> f198;
	vector<OpQ5_U9d9600> f1a8;
	vector<OpQ5_T9dc120 *> f1b8;
	vector<OpQ5_T9dc180 *> f1c8;
	bool f1d8;
	vector<OpQ5_T9dc1e0 *> f1dc;
	vector<OpQ5_T9dc240 *> f1ec;
	int f1fc;
	int f200;
	bool f204;
	vector<int> f208;
	int f218;
	int f21c;
	vector<OpQ5_U9d0840> f220;
	int f230;
	OpC_IntBox f234;
	int f238;
	int f23c;
	int f240;
	vector<OpQ5_U9d9600> f244;
	int f254;
	vector<int> f258;
	vector< vector<OpQ5_U9d9600> > f268;
	vector<OpQ5_U9d9600> f278;
	OpV4b_Objs3 f288;
	OpQ5_T9dc2a0 * f2ac;
	vector<int> f2b0;
	vector<OpQ5_U9d0840> f2c0;
	vector<OpQ5_U9d9600> f2d0;
	vector<OpQ5_U9d0840> f2e0;
	bool f2f0;
	vector<OpQ5_U9d9600> f2f4;
	vector<int> f304;
	int f314;
	int f318;
	int f31c;
	int f320;
	int f324;
	int f328;
	bool f32c;
	bool f32d;
	vector< vector<OpQ5_U9d9600> > f330;
	vector<OpQ5_U9d9600> f340;
	vector<int> f350;
	vector<int> f360;
	vector<OpQ5_U9d9600> f370;
	vector<int> f380;
	vector<OpQ5_U9d9600> f390;
	vector<int> f3a0;
	vector<OpQ5_U9d9600> f3b0;
	vector<OpQ5_U9d9600> f3c0;
	int f3d0;
	OpQ5_T9dc2e0 * f3d4;
	vector<OpQ5_U9d0840> f3d8;
	int f3e8;
	int f3ec;
	vector<OpQ5_U9d9600> f3f0;
	vector<int> f400;
	vector<OpQ5_U9d9600> f410;
	vector<int> f420;
	vector<OpQ5_U9d9600> f430;
	vector<OpQ5_U9d9600> f440;
	vector<int> f450;
	vector<OpQ5_U9d0840> f460;
	vector<int> f470;
	vector<OpQ5_U9d9600> f480;
	vector<OpQ5_U9d9600> f490;
	vector<int> f4a0;
	vector<OpQ5_U9d9600> f4b0;
	vector<OpQ5_U9d9600> f4c0;
	vector<OpQ5_T9dea20 *> f4d0;
	vector<OpQ5_U9d9600> f4e0;
	vector<OpQ5_U9d9600> f4f0;
	vector<OpQ5_U9d9600> f500;
	vector<OpQ5_U9d9600> f510;
	int f520;
	vector<int> f524;
	int f534;
	vector<OpQ5_U9d0840> f538;
	vector<int> f548;
	bool f558;
	bool f559;
	int f55c;
	char pad560[0x10];
	int f570;
	vector<OpQ5_U9d0840> f574;
	vector<OpQ5_U9d0840> f584;
	vector<OpQ5_U9d9600> f594;
	vector< vector<OpQ5_U9dbf40> > f5a4;
	int f5b4;
	int f5b8;
	vector<OpQ5_U9d0840> f5bc;
	vector<int> f5cc;
	vector<OpQ5_U9d9600> f5dc;
	vector<OpQ5_U9d9600> f5ec;
	OpC_IntBox f5fc;
	OpC_IntBox f600;
	vector<OpQ5_T9dc320 *> f604;
	int f614;
	OpC_IntBox f618;
	vector<OpQ5_U9d9600> f61c;
	vector<OpQ5_U9d9600> f62c;
	bool f63c;
	char pad63d[0x7];
	bool f644;
	vector<OpQ5_T9dc380 *> f648;
	int f658;
	OpC_IntBox f65c;
	bool f660;
	int f664;
	int f668;
	OpC_IntBox f66c;
	OpC_IntBox f670;
	OpS8a_Array2D<bool> f674;
	OpS8a_Array2D<bool> f680;
	int f68c;
	OpS8a_Array2D<int> f690;
	OpS8a_Array2D<int> f69c;
	char pad6a8[0x10];
	vector<OpQ5_U9d9600> f6b8;
	vector<OpQ5_U9d9600> f6c8;
	vector<OpQ5_T9dc3e0 *> f6d8;
	char pad6e8[0x4];
	vector<OpQ5_U9d9600> f6ec;
	vector<OpQ5_U9d9600> f6fc;
	bool f70c;
	vector<OpQ5_U9d9600> f710;
	vector<OpQ5_U9d9600> f720;
	vector<OpQ5_U9d9600> f730;
	OpS8a_Grid<OpS8a_G20> f740;
	int f74c;
	bool f750;
	bool f751;
	bool f752;
	bool f753;
	vector<OpQ5_U9d0840> f754;
	vector<OpQ5_U9d0840> f764;
	vector<OpQ5_U9d0840> f774;
	vector<OpQ5_U9d0840> f784;
	vector<OpQ5_U9d0840> f794;
	vector<OpQ5_U9d0840> f7a4;
	vector<OpQ5_U9d9600> f7b4;
	OpS8a_Grid<OpS8a_G34> f7c4;
	vector<OpQ5_U9d0840> f7d0;
	vector< vector<OpQ5_U9d9600> > f7e0;
	vector<OpQ5_T9dc440 *> f7f0;
	vector<OpQ5_T9dc4a0 *> f800;
	OpU1_Point f810;
	int f818;
	vector<OpQ5_U9d9600> f81c;
	int f82c;
	vector<OpQ5_U9d0840> f830;
	vector<OpQ5_U9d0840> f840;
	vector<OpQ5_U9d9600> f850;
	int f860;
	int f864;
	int f868;
	OpU1_Point f86c;
	vector< vector<OpQ5_U9d2190> > f874;
	vector<OpQ5_U9d0840> f884;
	vector<int> f894;
	bool f8a4;
	int f8a8;
	bool f8ac;
	int f8b0;
	vector<OpQ5_U9dbee0> f8b4;
	int f8c4;
	bool f8c8;
	OpC_PointPair f8cc;
	vector< vector<OpQ5_U9da850> > f8dc;
	vector< vector<OpQ5_U9dc500> > f8ec;
	int f8fc;
	int f900;
	vector<OpQ5_U9d0840> f904;
	vector<OpQ5_U9d9600> f914;
	OpC_PointPair f924;
	OpC_PointPair f934;
	OpC_PointPair f944;
	OpC_PointPair f954;
	bool f964;
	int f968;
	vector<OpQ5_U9dbee0> f96c;
	vector<OpQ5_U9dbee0> f97c;
	int f98c;
	vector<OpQ5_U9d9600> f990;
	bool f9a0;
	int f9a4;
	int f9a8;
	int f9ac;
	int f9b0;
	char pad9b4[0x4];
	int f9b8;
	vector<OpQ5_U9d9600> f9bc;
	int f9cc;
	int f9d0;
	vector<OpQ5_U9d9600> f9d4;
	bool f9e4;
	OpC_IntBox f9e8;
	int f9ec;
	int f9f0;
	vector<OpQ5_U9d9600> f9f4;
	int fa04;
	int fa08;
	bool fa0c;
	bool fa0d;
	bool fa0e;
	int fa10;
	bool fa14;
	bool fa15;
	bool fa16;
	int fa18;
	bool fa1c;
	vector<OpQ5_U9d9600> fa20;
	char pada30[0x50];
	vector<OpQ5_T9dc560 *> fa80;
	char pada90[0x74];
	bool fb04;
	vector<OpQ5_T9dc5c0 *> fb08;
	int fb18;
	char padb1c[0x4];
	int fb20;
	vector<OpQ5_U9d9600> fb24;
	int fb34;
	int fb38;
	OpU1_Point fb3c;
	bool fb44;
	int fb48;
	OpV4b_Ints3 fb4c;
	vector<OpQ5_U9d9600> fb70;
	OpQ5_T9dc2e0 * fb80;
	vector<OpQ5_U9d0840> fb84;
	char padb94[0x10];
	int fba4;
	OpC_IntBox fba8;
	int fbac;
	int fbb0;
	vector<int> fbb4;
	vector<int> fbc4;
	vector<Point> fbd4;
	bool fbe4;

	void serialize(ostream &stream);
};

void BS::serialize(ostream &stream)
{
	logInfo("BS::BattleScape()","Serializing BattleScape");
	writeBinary(stream,TERRAIN_EARTH);
	writeBinary(stream,p_cefb84);
	writeBinary(stream,p_cefb88);
	writeBinary(stream,p_cefb8c);
	writeBinary(stream,p_cefb90);
	writeBinary(stream,p_cefb94);
	writeBinary(stream,p_cefb98);
	writeBinary(stream,p_cefb9c);
	writeBinary(stream,TERRAIN_CAVE_WALL);
	writeBinary(stream,caveinThirdTerrain);
	writeBinary(stream,p_cefba8);
	writeBinary(stream,p_cefbac);
	writeBinary(stream,p_cefbb0);
	g_cfd44c.write(stream);
	originalTerrain.writeRaw(stream);
	writeBinary(stream,&g_cec34c);
	g_cf11a0.writeRaw(stream);
	OpQ5_writeObjects(stream,g_d22744);
	OpQ5_writeObjects(stream,g_cf3a00);
	OpS8a_writeRawVector(stream,g_cfc1a4);
	OpQ5_writeElements(stream,g_d22fa8);
	OpQ5_writeObjects(stream,g_cf0fa8);
	OpQ5_writeElements(stream,g_d204cc);
	OpQ5_writeElements(stream,g_d33d74);
	OpQ5_writeElements(stream,g_d2b274);
	OpQ5_writeElements(stream,g_cf25b8);
	OpQ5_writeElements(stream,g_d37984);
	OpQ5_writeVectors(stream,g_d31640);
	OpQ5_writeVectors(stream,g_d2f32c);
	OpS8a_writeRawVector(stream,g_d2a2cc);
	OpQ5_writeVectors(stream,g_cf44b0);
	writeBinary(stream,&g_cefbb4);
	OpS8a_writeRawVector(stream,g_d2a520);
	OpQ5_writeObjects(stream,g_d39f1c);
	OpQ5_writeVectors(stream,g_cf3a10);
	OpQ5_writeVectors(stream,g_d20248);
	OpS8a_writeRawVector(stream,g_d3239c);
	OpQ5_writeElements(stream,g_d20690);
	OpQ5_writeElements(stream,g_d35860);
	OpQ5_writeElements(stream,g_d1daec);
	OpQ5_writeElements(stream,g_d01b28);
	OpS8a_writeRawVector(stream,g_d02b64);
	g_d225a0.serialize(stream);
	g_cf1080.serialize(stream);
	g_d2f75c.serialize(stream);
	writeBinary(stream,&f0);
	f8.write(stream);
	OpQ5_writeObjects(stream,f10);
	OpQ5_writeObjects(stream,f20);
	writeBinary(stream,&f30);
	writeBinary(stream,&f34);
	f48.write(stream);
	OpQ5_writeElements(stream,f4c);
	f5c.writeRaw(stream);
	f68.OpV4b_write(stream);
	f8c.OpV4b_write(stream);
	OpS8a_writeRawVector(stream,fb0);
	fc0.OpV4b_write(stream);
	OpS8a_writeRawVector(stream,fe4);
	OpQ5_writeElements(stream,ff4);
	writeBinary(stream,&f104);
	for (int i = 0; i < 5; i++)
		OpQ5_writeElements(stream,f108[i]);
	for (int i = 0; i < 9; i++)
		OpQ5_writeElements(stream,f118[i]);
	for (int i = 0; i < 9; i++)
		OpQ5_writeElements(stream,f128[i]);
	OpQ5_writeElements(stream,f138);
	OpQ5_writeElements(stream,f148);
	OpQ5_writeElements(stream,f158);
	OpS8a_writeRawVector(stream,f168);
	OpQ5_writeElements(stream,f178);
	OpQ5_writeElements(stream,f188);
	OpQ5_writeElements(stream,f198);
	OpQ5_writeElements(stream,f1a8);
	OpQ5_writeObjects(stream,f1b8);
	OpQ5_writeObjects(stream,f1c8);
	writeBinary(stream,&f1d8);
	OpQ5_writeObjects(stream,f1dc);
	OpQ5_writeObjects(stream,f1ec);
	writeBinary(stream,&f1fc);
	writeBinary(stream,&f200);
	writeBinary(stream,&f204);
	OpS8a_writeRawVector(stream,f208);
	writeBinary(stream,&f218);
	writeBinary(stream,&f21c);
	OpQ5_writeElements(stream,f220);
	writeBinary(stream,&f230);
	f234.write(stream);
	writeBinary(stream,&f238);
	writeBinary(stream,&f23c);
	writeBinary(stream,&f240);
	OpQ5_writeElements(stream,f244);
	writeBinary(stream,&f254);
	OpS8a_writeRawVector(stream,f258);
	for (int i = 0; i < 25; i++)
		OpQ5_writeElements(stream,f268[i]);
	OpQ5_writeElements(stream,f278);
	f288.OpV4b_write(stream);
	OpQ5_writePointer(stream,f2ac);
	OpS8a_writeRawVector(stream,f2b0);
	OpQ5_writeElements(stream,f2c0);
	OpQ5_writeElements(stream,f2d0);
	OpQ5_writeElements(stream,f2e0);
	OpQ5_writeElements(stream,f2f4);
	OpS8a_writeRawVector(stream,f304);
	writeBinary(stream,&f2f0);
	writeBinary(stream,&f314);
	writeBinary(stream,&f318);
	writeBinary(stream,&f31c);
	writeBinary(stream,&f320);
	writeBinary(stream,&f324);
	writeBinary(stream,&f328);
	writeBinary(stream,&f32c);
	writeBinary(stream,&f32d);
	for (int i = 0; i < 219; i++)
		OpQ5_writeElements(stream,f330[i]);
	OpQ5_writeElements(stream,f340);
	OpS8a_writeRawVector(stream,f350);
	OpS8a_writeRawVector(stream,f360);
	OpQ5_writeElements(stream,f370);
	OpS8a_writeRawVector(stream,f380);
	OpQ5_writeElements(stream,f390);
	OpS8a_writeRawVector(stream,f3a0);
	OpQ5_writeElements(stream,f3b0);
	OpQ5_writeElements(stream,f3c0);
	writeBinary(stream,&f3d0);
	OpQ5_writePointer(stream,f3d4);
	OpQ5_writeElements(stream,f3d8);
	writeBinary(stream,&f3e8);
	writeBinary(stream,&f3ec);
	OpQ5_writeElements(stream,f3f0);
	OpS8a_writeRawVector(stream,f400);
	OpQ5_writeElements(stream,f410);
	OpS8a_writeRawVector(stream,f420);
	OpQ5_writeElements(stream,f430);
	OpQ5_writeElements(stream,f440);
	OpS8a_writeRawVector(stream,f450);
	OpQ5_writeElements(stream,f460);
	OpS8a_writeRawVector(stream,f470);
	OpQ5_writeElements(stream,f480);
	OpQ5_writeElements(stream,f490);
	OpS8a_writeRawVector(stream,f4a0);
	OpQ5_writeElements(stream,f4b0);
	OpQ5_writeElements(stream,f4c0);
	OpQ5_writeObjects(stream,f4d0);
	OpQ5_writeElements(stream,f4e0);
	OpQ5_writeElements(stream,f4f0);
	OpQ5_writeElements(stream,f500);
	OpQ5_writeElements(stream,f510);
	writeBinary(stream,&f520);
	OpS8a_writeRawVector(stream,f524);
	writeBinary(stream,&f534);
	OpQ5_writeElements(stream,f538);
	OpS8a_writeRawVector(stream,f548);
	writeBinary(stream,&f558);
	writeBinary(stream,&f559);
	writeBinary(stream,&f55c);
	writeBinary(stream,&f570);
	OpQ5_writeElements(stream,f574);
	OpQ5_writeElements(stream,f584);
	OpQ5_writeElements(stream,f594);
	OpQ5_writeVectors(stream,f5a4);
	writeBinary(stream,&f5b4);
	writeBinary(stream,&f5b8);
	OpQ5_writeElements(stream,f5bc);
	OpS8a_writeRawVector(stream,f5cc);
	OpQ5_writeElements(stream,f5dc);
	OpQ5_writeElements(stream,f5ec);
	f5fc.write(stream);
	f600.write(stream);
	OpQ5_writeObjects(stream,f604);
	writeBinary(stream,&f614);
	f618.write(stream);
	OpQ5_writeElements(stream,f61c);
	OpQ5_writeElements(stream,f62c);
	writeBinary(stream,&f63c);
	writeBinary(stream,&f644);
	OpQ5_writeObjects(stream,f648);
	writeBinary(stream,&f658);
	f65c.write(stream);
	writeBinary(stream,&f660);
	writeBinary(stream,&f664);
	writeBinary(stream,&f668);
	f66c.write(stream);
	f670.write(stream);
	f674.writeRaw(stream);
	f680.writeRaw(stream);
	writeBinary(stream,&f68c);
	f690.writeRaw(stream);
	f69c.writeRaw(stream);
	OpQ5_writeElements(stream,f6b8);
	OpQ5_writeElements(stream,f6c8);
	OpQ5_writeObjects(stream,f6d8);
	OpQ5_writeElements(stream,f6ec);
	OpQ5_writeElements(stream,f6fc);
	writeBinary(stream,&f70c);
	OpQ5_writeElements(stream,f710);
	OpQ5_writeElements(stream,f720);
	OpQ5_writeElements(stream,f730);
	f740.write(stream);
	writeBinary(stream,&f74c);
	writeBinary(stream,&f750);
	writeBinary(stream,&f751);
	writeBinary(stream,&f752);
	writeBinary(stream,&f753);
	OpQ5_writeElements(stream,f754);
	OpQ5_writeElements(stream,f774);
	OpQ5_writeElements(stream,f784);
	OpQ5_writeElements(stream,f764);
	OpQ5_writeElements(stream,f794);
	OpQ5_writeElements(stream,f7a4);
	OpQ5_writeElements(stream,f7b4);
	f7c4.write(stream);
	writeBinary(stream,&g_d28d30);
	OpQ5_writeElements(stream,f7d0);
	for (int i = 0; i < 20; i++)
		OpQ5_writeElements(stream,f7e0[i]);
	OpQ5_writeObjects(stream,f7f0);
	OpQ5_writeObjects(stream,f800);
	f810.write(stream);
	writeBinary(stream,&f818);
	OpQ5_writeElements(stream,f81c);
	writeBinary(stream,&f82c);
	OpQ5_writeElements(stream,f830);
	OpQ5_writeElements(stream,f840);
	OpQ5_writeElements(stream,f850);
	writeBinary(stream,&f860);
	writeBinary(stream,&f864);
	writeBinary(stream,&f868);
	f86c.write(stream);
	OpQ5_writeVectors(stream,f874);
	OpQ5_writeElements(stream,f884);
	OpS8a_writeRawVector(stream,f894);
	writeBinary(stream,&f8a4);
	writeBinary(stream,&f8a8);
	writeBinary(stream,&f8ac);
	writeBinary(stream,&f8b0);
	OpQ5_writeElements(stream,f8b4);
	writeBinary(stream,&f8c4);
	writeBinary(stream,&f8c8);
	f8cc.write(stream);
	OpQ5_writeVectors(stream,f8dc);
	OpQ5_writeVectors(stream,f8ec);
	writeBinary(stream,&f8fc);
	writeBinary(stream,&f900);
	OpQ5_writeElements(stream,f904);
	OpQ5_writeElements(stream,f914);
	f924.write(stream);
	f934.write(stream);
	f944.write(stream);
	f954.write(stream);
	writeBinary(stream,&f964);
	writeBinary(stream,&f968);
	OpQ5_writeElements(stream,f96c);
	OpQ5_writeElements(stream,f97c);
	writeBinary(stream,&f98c);
	OpQ5_writeElements(stream,f990);
	writeBinary(stream,&f9a0);
	writeBinary(stream,&f9a4);
	writeBinary(stream,&f9a8);
	writeBinary(stream,&f9ac);
	writeBinary(stream,&f9b0);
	writeBinary(stream,&f9b8);
	OpQ5_writeElements(stream,f9bc);
	writeBinary(stream,&f9cc);
	writeBinary(stream,&f9d0);
	OpQ5_writeElements(stream,f9d4);
	writeBinary(stream,&f9e4);
	f9e8.write(stream);
	writeBinary(stream,&f9ec);
	writeBinary(stream,&f9f0);
	OpQ5_writeElements(stream,f9f4);
	writeBinary(stream,&fa04);
	writeBinary(stream,&fa08);
	writeBinary(stream,&fa0c);
	writeBinary(stream,&fa0d);
	writeBinary(stream,&fa0e);
	writeBinary(stream,&fa10);
	writeBinary(stream,&fa14);
	writeBinary(stream,&fa15);
	writeBinary(stream,&fa16);
	writeBinary(stream,&fa18);
	writeBinary(stream,&fa1c);
	OpQ5_writeElements(stream,fa20);
	OpQ5_writeObjects(stream,fa80);
	writeBinary(stream,&fb04);
	OpQ5_writeObjects(stream,fb08);
	writeBinary(stream,&fb18);
	writeBinary(stream,&fb20);
	OpQ5_writeElements(stream,fb24);
	writeBinary(stream,&fb34);
	writeBinary(stream,&fb38);
	fb3c.write(stream);
	writeBinary(stream,&fb44);
	writeBinary(stream,&fb48);
	fb4c.OpV4b_write(stream);
	OpQ5_writeElements(stream,fb70);
	OpQ5_writePointer(stream,fb80);
	OpQ5_writeElements(stream,fb84);
	writeBinary(stream,&fba4);
	fba8.write(stream);
	writeBinary(stream,&fbac);
	writeBinary(stream,&fbb0);
	OpS8a_writeRawVector(stream,fbb4);
	OpS8a_writeRawVector(stream,fbc4);
	OpS8c_writePoints(stream,fbd4);
	writeBinary(stream,&fbe4);
	jlog_cefa64->end(2);
}
