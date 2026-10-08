// team_c_28: BS::BattleScape_70ffd0 (0x70ffd0): constructor that unserializes a saved BattleScape (the twin of team_c_22's destructor
// and the reader for team_c_23's BS::serialize)
// NOTE: member names are placeholders (f<offset>); element types and globals are private placeholders
#include <string>
#include <vector>
#include <istream>
using namespace std;

class Cell;
struct Point { int x; int y; };
struct XColor { unsigned char r, g, b; XColor(const XColor &c); XColor &operator=(XColor c); };
struct OpS8a_P8 { int a; int b; };
struct OpS8d_Pair16 { int a; int b; int c; int d; };
struct OpU8_T9da130 { int v; };	// NOTE: placeholder element types (names of the folded exe instances)
struct OpQ5_U9dd4b0 { int v; };
struct OpQ5_U9da6b0 { int v; };
struct OpQ5_U9d2090 { int v; };
struct OpQ5_U9ddb90;
struct OpQ5_T9dc620; struct OpQ5_T9dc760; struct OpQ5_T9dc950; struct OpQ5_T9dca90; struct OpQ5_T9dcbd0; struct OpQ5_T9dcd10;
struct OpQ5_T9dce50; struct OpQ5_T9dcf90; struct OpQ5_T9dd0d0; struct OpQ5_T9dd210; struct OpQ5_T9dd2c0; struct OpQ5_T9dd370;
struct OpQ5_T9dd550; struct OpQ5_T9dd690; struct OpQ5_T9dd7d0; struct OpQ5_T9dd910; struct OpQ5_T9dda50; struct OpQ5_T9ddc30;
struct OpQ5_T9ddd70; struct OpQ5_T9ee9a0;

template <class T> void readBinary(istream &stream, T *value);
void OpT8a_readInts(istream &in, vector<int> &v);
void OpS8a_readP8s(istream &stream, vector<OpS8a_P8> &v);
void OpS8c_readPoints(istream &stream, vector<Point> &v);
template <class T> void OpU8_readStructs(istream &stream, vector<T> &v);
template <class T> void OpS8d_readStructs(istream &stream, vector<T> &v);
template <class T> void OpQ5_readVectors(istream &stream, vector< vector<T> > &v);
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);
template <class T> void OpQ5_readPointer(istream &stream, T *&p);
template <class T> void OpS8d_readPointers(istream &stream, vector<T*> &v);
template <class T> void OpQ5_readObjectVectors(istream &stream, vector< vector<T*> > &v);
string opr1c_convertBuildno_432720(const string &build);	// 0x432720
extern string str_d204b0;	// team_c_02.cpp: build string of the loaded save
void logInfo(string location, string message);
class JLog { public: int end(int type); };
extern JLog *jlog_cefa64;	// NOTE: placeholder name

struct OpC_IntBox { int v; OpC_IntBox(); void read(istream &stream); };	// NOTE: ctor folded with HProp::HProp
struct C28_Flag { int v; C28_Flag(); void resetField(); };	// NOTE: placeholder (ctor folded with HProp::HProp, resetField with Sweep_9b7270::resetField)
struct OpU1_Point { int x; int y; OpU1_Point(); void read(istream &stream); };	// NOTE: ctor folded with Push_453b40::operate
struct OpC_PointPair { OpU1_Point a; OpU1_Point b; OpC_PointPair(); void read(istream &stream); };	// NOTE: placeholder name (ctor/read folded with Calls_40b100/40b450::delegate)
template <class T> struct C28_Array2D	// NOTE: placeholder (ctor folded with OpX5_Array2D<OpX5_S14>)
{
	int width; int height; T *cells;
	C28_Array2D(); ~C28_Array2D();
	void read(istream &stream);
	void resize(int width, int height, istream *stream);
	void zero();
};
struct C28_G20 { char pad[0x14]; }; struct C28_G34 { char pad[0x34]; };
struct OpV4b_Ints3 { vector<int> list0; vector<int> list10; int value20; OpV4b_Ints3(); void OpV4b_read(istream &stream); };	// NOTE: ctor folded with OpR5h_WL<int>
struct C28_Obj3;
struct OpV4b_Objs3 { vector<C28_Obj3 *> objects; vector<int> list10; int value20; OpV4b_Objs3(); void OpV4b_read(istream &stream); };
struct C28_View { int pad[0xb]; C28_View(); ~C28_View(); void init(int width, int height, int value); };	// NOTE: placeholder (ctor OpT8a_Holder, init OpC_View::init)
struct C28_Obj { char pad0[0x2c]; vector<XColor> colors; void unknown45e4c0(); };	// NOTE: placeholder layout
struct C28_Handle { int id; C28_Obj *get230(); };	// NOTE: placeholder (get230 folded with OpC_Handle::get230)
struct C28_PathMap { void resize_40cec0(int width, int height); void setField(bool value); };	// NOTE: placeholder (0xcfe568)
struct C28_EntityList { void unserialize(istream &stream); };	// NOTE: placeholder (0xd225a0)
struct C28_Log { void unserialize(istream &stream, int size); };	// NOTE: placeholder (MessageLog)
struct C28_RollPool { void initialize(); };	// NOTE: placeholder (PenetrationRollPool)
struct C28_Cells { int getWidth(); int getHeight(); void read(istream &stream); };	// NOTE: placeholder (Array2D<Cell *> at 0xcfd44c)

extern int TERRAIN_EARTH;
extern int terrain_cefb84, terrain_cefb88, terrain_cefb8c, terrain_cefb90, terrain_cefb94, terrain_cefb98, terrain_cefb9c;	// NOTE: placeholder names
extern int TERRAIN_CAVE_WALL;
extern int caveinThirdTerrain;
extern int terrain_cefba8, terrain_cefbac, terrain_cefbb0;	// NOTE: placeholder names
extern vector<int> terrainIds_cfb844;	// NOTE: placeholder name
extern C28_Cells cells_cfd44c;	// NOTE: placeholder name
extern C28_Array2D<int> originalTerrain;
extern C28_Array2D<int> grid_cf11a0;	// NOTE: placeholder name
extern C28_PathMap pathMap_cfe568;	// NOTE: placeholder name
extern C28_EntityList entities_d225a0;	// NOTE: placeholder name
extern C28_Log log_cf1080, log_d2f75c;	// NOTE: placeholder names
extern int logSize_d28ea8, logSize_d28eac;	// NOTE: placeholder names
extern C28_RollPool rollPool_d2c41c;	// NOTE: placeholder name
extern bool flag_d28d26, flag_d28d30, flag_cefacf;	// NOTE: placeholder names
extern XColor *color_d35be0;	// NOTE: placeholder name
extern int g_cec34c;	// NOTE: placeholder name
extern int g_cefbb4;	// NOTE: placeholder name
extern vector<OpQ5_T9dce50 *> g_cf0fa8;	// NOTE: placeholder name
extern vector<OpU8_T9da130> g_cf25b8;	// NOTE: placeholder name
extern vector<OpQ5_T9dc760 *> g_cf3a00;	// NOTE: placeholder name
extern vector< vector<OpQ5_U9dd4b0> > g_cf3a10;	// NOTE: placeholder name
extern vector<OpQ5_T9ee9a0 *> g_cf44b0;	// NOTE: placeholder name
extern vector<int> g_cfc1a4;	// NOTE: placeholder name
extern vector<OpS8a_P8> g_d01b28;	// NOTE: placeholder name
extern vector<int> g_d02b64;	// NOTE: placeholder name
extern vector<OpS8a_P8> g_d1daec;	// NOTE: placeholder name
extern vector< vector<OpQ5_U9dd4b0> > g_d20248;	// NOTE: placeholder name
extern vector<OpS8d_Pair16> g_d204cc;	// NOTE: placeholder name
extern vector<OpS8a_P8> g_d20690;	// NOTE: placeholder name
extern vector<OpQ5_T9dc620 *> g_d22744;	// NOTE: placeholder name
extern vector<OpS8d_Pair16> g_d22fa8;	// NOTE: placeholder name
extern vector<int> g_d2a2cc;	// NOTE: placeholder name
extern vector<int> g_d2a520;	// NOTE: placeholder name
extern vector<OpS8d_Pair16> g_d2b274;	// NOTE: placeholder name
extern vector< vector<OpQ5_U9da6b0> > g_d2f32c;	// NOTE: placeholder name
extern vector< vector<OpQ5_U9dd4b0> > g_d31640;	// NOTE: placeholder name
extern vector<int> g_d3239c;	// NOTE: placeholder name
extern vector<OpU8_T9da130> g_d33d74;	// NOTE: placeholder name
extern vector<OpS8a_P8> g_d35860;	// NOTE: placeholder name
extern vector<OpU8_T9da130> g_d37984;	// NOTE: placeholder name
extern vector<OpQ5_T9dc950 *> g_d39f1c;	// NOTE: placeholder name

class BS	// NOTE: placeholder layout (same object as team_c_22 / team_c_23)
{
public:
	bool f0;
	int f4;
	OpU1_Point f8;
	vector<OpQ5_T9dca90 *> f10;
	vector<OpQ5_T9dcbd0 *> f20;
	bool f30;
	int f34;
	C28_Array2D<int> f38;
	int f44;
	OpC_IntBox f48;
	vector<C28_Handle> f4c;
	C28_Array2D<int> f5c;
	OpV4b_Ints3 f68;
	OpV4b_Ints3 f8c;
	vector<int> fb0;
	OpV4b_Ints3 fc0;
	vector<int> fe4;
	vector<OpS8a_P8> ff4;
	int f104;
	vector< vector<OpS8a_P8> > f108;
	vector< vector<OpS8a_P8> > f118;
	vector< vector<OpS8a_P8> > f128;
	vector<OpS8a_P8> f138;
	vector<OpS8a_P8> f148;
	vector<OpS8a_P8> f158;
	vector<int> f168;
	vector<OpU8_T9da130> f178;
	vector<OpU8_T9da130> f188;
	vector<OpS8a_P8> f198;
	vector<OpU8_T9da130> f1a8;
	vector<OpQ5_T9dcd10 *> f1b8;
	vector<OpQ5_T9dce50 *> f1c8;
	bool f1d8;
	vector<OpQ5_T9dcf90 *> f1dc;
	vector<OpQ5_T9dd0d0 *> f1ec;
	int f1fc;
	int f200;
	bool f204;
	vector<int> f208;
	int f218;
	int f21c;
	vector<OpS8a_P8> f220;
	int f230;
	OpC_IntBox f234;
	int f238;
	int f23c;
	int f240;
	vector<OpU8_T9da130> f244;
	int f254;
	vector<int> f258;
	vector< vector<OpU8_T9da130> > f268;
	vector<OpU8_T9da130> f278;
	OpV4b_Objs3 f288;
	OpQ5_T9dd210 * f2ac;
	vector<int> f2b0;
	vector<OpS8a_P8> f2c0;
	vector<OpU8_T9da130> f2d0;
	vector<OpS8a_P8> f2e0;
	bool f2f0;
	vector<OpU8_T9da130> f2f4;
	vector<int> f304;
	int f314;
	int f318;
	int f31c;
	int f320;
	int f324;
	int f328;
	bool f32c;
	bool f32d;
	vector< vector<OpU8_T9da130> > f330;
	vector<OpU8_T9da130> f340;
	vector<int> f350;
	vector<int> f360;
	vector<OpU8_T9da130> f370;
	vector<int> f380;
	vector<OpU8_T9da130> f390;
	vector<int> f3a0;
	vector<OpU8_T9da130> f3b0;
	vector<OpU8_T9da130> f3c0;
	int f3d0;
	OpQ5_T9dd2c0 * f3d4;
	vector<OpS8a_P8> f3d8;
	int f3e8;
	int f3ec;
	vector<OpU8_T9da130> f3f0;
	vector<int> f400;
	vector<OpU8_T9da130> f410;
	vector<int> f420;
	vector<OpU8_T9da130> f430;
	vector<OpU8_T9da130> f440;
	vector<int> f450;
	vector<OpS8a_P8> f460;
	vector<int> f470;
	vector<OpU8_T9da130> f480;
	vector<OpU8_T9da130> f490;
	vector<int> f4a0;
	vector<OpU8_T9da130> f4b0;
	vector<OpU8_T9da130> f4c0;
	vector<OpQ5_T9dd370 *> f4d0;
	vector<OpU8_T9da130> f4e0;
	vector<OpU8_T9da130> f4f0;
	vector<OpU8_T9da130> f500;
	vector<OpU8_T9da130> f510;
	int f520;
	vector<int> f524;
	int f534;
	vector<OpS8a_P8> f538;
	vector<int> f548;
	bool f558;
	bool f559;
	int f55c;
	vector<int> f560;
	int f570;
	vector<OpS8a_P8> f574;
	vector<OpS8a_P8> f584;
	vector<OpU8_T9da130> f594;
	vector< vector<OpQ5_U9dd4b0> > f5a4;
	int f5b4;
	int f5b8;
	vector<OpS8a_P8> f5bc;
	vector<int> f5cc;
	vector<OpU8_T9da130> f5dc;
	vector<OpU8_T9da130> f5ec;
	OpC_IntBox f5fc;
	OpC_IntBox f600;
	vector<OpQ5_T9dd550 *> f604;
	int f614;
	OpC_IntBox f618;
	vector<OpU8_T9da130> f61c;
	vector<OpU8_T9da130> f62c;
	bool f63c;
	int f640;
	bool f644;
	vector<OpQ5_T9dd690 *> f648;
	int f658;
	OpC_IntBox f65c;
	bool f660;
	int f664;
	int f668;
	OpC_IntBox f66c;
	OpC_IntBox f670;
	C28_Array2D<bool> f674;
	C28_Array2D<bool> f680;
	int f68c;
	C28_Array2D<int> f690;
	C28_Array2D<int> f69c;
	vector<int> f6a8;
	vector<OpU8_T9da130> f6b8;
	vector<OpU8_T9da130> f6c8;
	vector<OpQ5_T9dd7d0 *> f6d8;
	OpQ5_T9dd7d0 * f6e8;
	vector<OpU8_T9da130> f6ec;
	vector<OpU8_T9da130> f6fc;
	bool f70c;
	vector<OpU8_T9da130> f710;
	vector<OpU8_T9da130> f720;
	vector<OpU8_T9da130> f730;
	C28_Array2D<C28_G20> f740;
	int f74c;
	bool f750;
	bool f751;
	bool f752;
	bool f753;
	vector<OpS8a_P8> f754;
	vector<OpS8a_P8> f764;
	vector<OpS8a_P8> f774;
	vector<OpS8a_P8> f784;
	vector<OpS8a_P8> f794;
	vector<OpS8a_P8> f7a4;
	vector<OpU8_T9da130> f7b4;
	C28_Array2D<C28_G34> f7c4;
	vector<OpS8a_P8> f7d0;
	vector< vector<OpU8_T9da130> > f7e0;
	vector<OpQ5_T9dd910 *> f7f0;
	vector<OpQ5_T9dda50 *> f800;
	OpU1_Point f810;
	int f818;
	vector<OpU8_T9da130> f81c;
	int f82c;
	vector<OpS8a_P8> f830;
	vector<OpS8a_P8> f840;
	vector<OpU8_T9da130> f850;
	int f860;
	int f864;
	int f868;
	OpU1_Point f86c;
	vector< vector<OpQ5_U9d2090> > f874;
	vector<OpS8a_P8> f884;
	vector<int> f894;
	bool f8a4;
	int f8a8;
	bool f8ac;
	int f8b0;
	vector<OpS8d_Pair16> f8b4;
	int f8c4;
	bool f8c8;
	OpC_PointPair f8cc;
	vector< vector<OpQ5_U9da6b0> > f8dc;
	vector< vector<OpQ5_U9ddb90 *> > f8ec;
	int f8fc;
	int f900;
	vector<OpS8a_P8> f904;
	vector<OpU8_T9da130> f914;
	OpC_PointPair f924;
	OpC_PointPair f934;
	OpC_PointPair f944;
	OpC_PointPair f954;
	bool f964;
	int f968;
	vector<OpS8d_Pair16> f96c;
	vector<OpS8d_Pair16> f97c;
	int f98c;
	vector<OpU8_T9da130> f990;
	bool f9a0;
	int f9a4;
	int f9a8;
	int f9ac;
	int f9b0;
	char pad9b4[0x4];
	int f9b8;
	vector<OpU8_T9da130> f9bc;
	int f9cc;
	int f9d0;
	vector<OpU8_T9da130> f9d4;
	bool f9e4;
	OpC_IntBox f9e8;
	int f9ec;
	int f9f0;
	vector<OpU8_T9da130> f9f4;
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
	vector<OpU8_T9da130> fa20;
	vector<int> fa30;
	vector<int> fa40;
	vector<int> fa50;
	vector<int> fa60;
	int fa70;
	bool fa74;
	C28_Flag fa78;
	C28_Flag fa7c;
	vector<OpQ5_T9ddc30 *> fa80;
	vector<int> fa90;
	vector<int> faa0;
	vector<int> fab0;
	vector<int> fac0;
	vector<int> fad0;
	char padae0[0x4];
	vector<int> fae4;
	vector<int> faf4;
	bool fb04;
	bool fb05;
	bool fb06;
	bool fb07;
	vector<OpQ5_T9ddd70 *> fb08;
	int fb18;
	int fb1c;
	int fb20;
	vector<OpU8_T9da130> fb24;
	int fb34;
	int fb38;
	OpU1_Point fb3c;
	bool fb44;
	int fb48;
	OpV4b_Ints3 fb4c;
	vector<OpU8_T9da130> fb70;
	OpQ5_T9dd2c0 * fb80;
	vector<OpS8a_P8> fb84;
	vector<int> fb94;
	int fba4;
	OpC_IntBox fba8;
	int fbac;
	int fbb0;
	vector<int> fbb4;
	vector<int> fbc4;
	vector<Point> fbd4;
	bool fbe4;
	C28_View fbe8;
	int fc14;
	vector<int> fc18;
	vector<int> fc28;
	vector<int> fc38;
	vector<int> fc48;
	vector<int> fc58;

	void unknown7355a0();
	BS(istream &stream);
};

BS::BS(istream &stream)
{
	logInfo("BS::BattleScape()","Unserializing saved BattleScape");
	int terrain;
	readBinary(stream,&terrain);
	TERRAIN_EARTH = terrainIds_cfb844[terrain];
	readBinary(stream,&terrain);
	terrain_cefb84 = terrainIds_cfb844[terrain];
	readBinary(stream,&terrain);
	terrain_cefb88 = terrainIds_cfb844[terrain];
	readBinary(stream,&terrain);
	terrain_cefb8c = terrainIds_cfb844[terrain];
	readBinary(stream,&terrain);
	terrain_cefb90 = terrainIds_cfb844[terrain];
	readBinary(stream,&terrain);
	terrain_cefb94 = terrainIds_cfb844[terrain];
	readBinary(stream,&terrain);
	terrain_cefb98 = terrainIds_cfb844[terrain];
	readBinary(stream,&terrain);
	terrain_cefb9c = terrainIds_cfb844[terrain];
	readBinary(stream,&terrain);
	TERRAIN_CAVE_WALL = terrainIds_cfb844[terrain];
	readBinary(stream,&terrain);
	caveinThirdTerrain = terrainIds_cfb844[terrain];
	readBinary(stream,&terrain);
	terrain_cefba8 = terrainIds_cfb844[terrain];
	readBinary(stream,&terrain);
	terrain_cefbac = terrainIds_cfb844[terrain];
	readBinary(stream,&terrain);
	terrain_cefbb0 = terrainIds_cfb844[terrain];
	cells_cfd44c.read(stream);
	originalTerrain.read(stream);
	readBinary(stream,&g_cec34c);
	grid_cf11a0.read(stream);
	OpQ5_readObjects(stream,g_d22744,0);
	OpQ5_readObjects(stream,g_cf3a00,0);
	OpT8a_readInts(stream,g_cfc1a4);
	OpS8d_readStructs(stream,g_d22fa8);
	OpQ5_readObjects(stream,g_cf0fa8,0);
	OpS8d_readStructs(stream,g_d204cc);
	OpU8_readStructs(stream,g_d33d74);
	OpS8d_readStructs(stream,g_d2b274);
	OpU8_readStructs(stream,g_cf25b8);
	OpU8_readStructs(stream,g_d37984);
	OpQ5_readVectors(stream,g_d31640);
	OpQ5_readVectors(stream,g_d2f32c);
	OpT8a_readInts(stream,g_d2a2cc);
	OpS8d_readPointers(stream,g_cf44b0);
	readBinary(stream,&g_cefbb4);
	OpT8a_readInts(stream,g_d2a520);
	OpQ5_readObjects(stream,g_d39f1c,0);
	OpQ5_readVectors(stream,g_cf3a10);
	OpQ5_readVectors(stream,g_d20248);
	OpT8a_readInts(stream,g_d3239c);
	OpS8a_readP8s(stream,g_d20690);
	OpS8a_readP8s(stream,g_d35860);
	OpS8a_readP8s(stream,g_d1daec);
	OpS8a_readP8s(stream,g_d01b28);
	OpT8a_readInts(stream,g_d02b64);
	pathMap_cfe568.resize_40cec0(cells_cfd44c.getWidth(),cells_cfd44c.getHeight());
	pathMap_cfe568.setField(true);
	entities_d225a0.unserialize(stream);
	log_cf1080.unserialize(stream,logSize_d28ea8);
	log_d2f75c.unserialize(stream,logSize_d28eac);
	rollPool_d2c41c.initialize();
	readBinary(stream,&f0);
	f4 = 0;
	f8.read(stream);
	OpQ5_readObjects(stream,f10,0);
	OpQ5_readObjects(stream,f20,0);
	readBinary(stream,&f30);
	readBinary(stream,&f34);
	f38.resize(cells_cfd44c.getWidth(),cells_cfd44c.getHeight(),0);
	f38.zero();
	f44 = 0;
	f48.read(stream);
	OpU8_readStructs(stream,f4c);
	if (flag_d28d26)
	{
		for (int i = 1; i < 6; i++)
			f4c[4].get230()->colors[i] = *color_d35be0;
	}
	else
		f4c[4].get230()->unknown45e4c0();
	f5c.read(stream);
	f68.OpV4b_read(stream);
	f8c.OpV4b_read(stream);
	OpT8a_readInts(stream,fb0);
	fc0.OpV4b_read(stream);
	OpT8a_readInts(stream,fe4);
	OpS8a_readP8s(stream,ff4);
	readBinary(stream,&f104);
	f108.assign(5,vector<OpS8a_P8>());
	for (int i = 0; i < 5; i++)
		OpS8a_readP8s(stream,f108[i]);
	f118.assign(9,vector<OpS8a_P8>());
	for (int i = 0; i < 9; i++)
		OpS8a_readP8s(stream,f118[i]);
	f128.assign(9,vector<OpS8a_P8>());
	for (int i = 0; i < 9; i++)
		OpS8a_readP8s(stream,f128[i]);
	OpS8a_readP8s(stream,f138);
	OpS8a_readP8s(stream,f148);
	OpS8a_readP8s(stream,f158);
	OpT8a_readInts(stream,f168);
	OpU8_readStructs(stream,f178);
	OpU8_readStructs(stream,f188);
	OpS8a_readP8s(stream,f198);
	OpU8_readStructs(stream,f1a8);
	OpQ5_readObjects(stream,f1b8,0);
	OpQ5_readObjects(stream,f1c8,0);
	readBinary(stream,&f1d8);
	OpQ5_readObjects(stream,f1dc,0);
	OpQ5_readObjects(stream,f1ec,0);
	readBinary(stream,&f1fc);
	readBinary(stream,&f200);
	readBinary(stream,&f204);
	OpT8a_readInts(stream,f208);
	readBinary(stream,&f218);
	readBinary(stream,&f21c);
	OpS8a_readP8s(stream,f220);
	readBinary(stream,&f230);
	f234.read(stream);
	readBinary(stream,&f238);
	readBinary(stream,&f23c);
	readBinary(stream,&f240);
	OpU8_readStructs(stream,f244);
	readBinary(stream,&f254);
	OpT8a_readInts(stream,f258);
	f268.assign(25,vector<OpU8_T9da130>());
	for (int i = 0; i < 25; i++)
		OpU8_readStructs(stream,f268[i]);
	OpU8_readStructs(stream,f278);
	f288.OpV4b_read(stream);
	OpQ5_readPointer(stream,f2ac);
	OpT8a_readInts(stream,f2b0);
	OpS8a_readP8s(stream,f2c0);
	OpU8_readStructs(stream,f2d0);
	OpS8a_readP8s(stream,f2e0);
	OpU8_readStructs(stream,f2f4);
	OpT8a_readInts(stream,f304);
	readBinary(stream,&f2f0);
	readBinary(stream,&f314);
	readBinary(stream,&f318);
	readBinary(stream,&f31c);
	readBinary(stream,&f320);
	readBinary(stream,&f324);
	readBinary(stream,&f328);
	readBinary(stream,&f32c);
	readBinary(stream,&f32d);
	f330.assign(219,vector<OpU8_T9da130>());
	for (int i = 0; i < 219; i++)
		OpU8_readStructs(stream,f330[i]);
	OpU8_readStructs(stream,f340);
	OpT8a_readInts(stream,f350);
	OpT8a_readInts(stream,f360);
	OpU8_readStructs(stream,f370);
	OpT8a_readInts(stream,f380);
	OpU8_readStructs(stream,f390);
	OpT8a_readInts(stream,f3a0);
	OpU8_readStructs(stream,f3b0);
	OpU8_readStructs(stream,f3c0);
	readBinary(stream,&f3d0);
	OpQ5_readPointer(stream,f3d4);
	OpS8a_readP8s(stream,f3d8);
	readBinary(stream,&f3e8);
	readBinary(stream,&f3ec);
	OpU8_readStructs(stream,f3f0);
	OpT8a_readInts(stream,f400);
	OpU8_readStructs(stream,f410);
	OpT8a_readInts(stream,f420);
	OpU8_readStructs(stream,f430);
	OpU8_readStructs(stream,f440);
	OpT8a_readInts(stream,f450);
	OpS8a_readP8s(stream,f460);
	OpT8a_readInts(stream,f470);
	OpU8_readStructs(stream,f480);
	OpU8_readStructs(stream,f490);
	OpT8a_readInts(stream,f4a0);
	OpU8_readStructs(stream,f4b0);
	OpU8_readStructs(stream,f4c0);
	OpQ5_readObjects(stream,f4d0,0);
	OpU8_readStructs(stream,f4e0);
	OpU8_readStructs(stream,f4f0);
	OpU8_readStructs(stream,f500);
	OpU8_readStructs(stream,f510);
	readBinary(stream,&f520);
	OpT8a_readInts(stream,f524);
	readBinary(stream,&f534);
	OpS8a_readP8s(stream,f538);
	OpT8a_readInts(stream,f548);
	readBinary(stream,&f558);
	readBinary(stream,&f559);
	readBinary(stream,&f55c);
	readBinary(stream,&f570);
	OpS8a_readP8s(stream,f574);
	OpS8a_readP8s(stream,f584);
	OpU8_readStructs(stream,f594);
	OpQ5_readVectors(stream,f5a4);
	readBinary(stream,&f5b4);
	readBinary(stream,&f5b8);
	OpS8a_readP8s(stream,f5bc);
	OpT8a_readInts(stream,f5cc);
	OpU8_readStructs(stream,f5dc);
	OpU8_readStructs(stream,f5ec);
	f5fc.read(stream);
	f600.read(stream);
	OpQ5_readObjects(stream,f604,0);
	readBinary(stream,&f614);
	f618.read(stream);
	OpU8_readStructs(stream,f61c);
	OpU8_readStructs(stream,f62c);
	readBinary(stream,&f63c);
	f640 = 0;
	readBinary(stream,&f644);
	OpQ5_readObjects(stream,f648,0);
	readBinary(stream,&f658);
	f65c.read(stream);
	readBinary(stream,&f660);
	readBinary(stream,&f664);
	readBinary(stream,&f668);
	f66c.read(stream);
	f670.read(stream);
	f674.read(stream);
	f680.read(stream);
	readBinary(stream,&f68c);
	f690.read(stream);
	f69c.read(stream);
	OpU8_readStructs(stream,f6b8);
	OpU8_readStructs(stream,f6c8);
	OpQ5_readObjects(stream,f6d8,0);
	f6e8 = f6d8.empty() ? 0 : f6d8[0];
	OpU8_readStructs(stream,f6ec);
	OpU8_readStructs(stream,f6fc);
	readBinary(stream,&f70c);
	OpU8_readStructs(stream,f710);
	OpU8_readStructs(stream,f720);
	OpU8_readStructs(stream,f730);
	f740.read(stream);
	readBinary(stream,&f74c);
	readBinary(stream,&f750);
	readBinary(stream,&f751);
	readBinary(stream,&f752);
	readBinary(stream,&f753);
	OpS8a_readP8s(stream,f754);
	OpS8a_readP8s(stream,f774);
	OpS8a_readP8s(stream,f784);
	OpS8a_readP8s(stream,f764);
	OpS8a_readP8s(stream,f794);
	OpS8a_readP8s(stream,f7a4);
	OpU8_readStructs(stream,f7b4);
	f7c4.read(stream);
	bool flag;
	readBinary(stream,&flag);
	if (flag != flag_d28d30)
		unknown7355a0();
	OpS8a_readP8s(stream,f7d0);
	f7e0.assign(20,vector<OpU8_T9da130>());
	for (int i = 0; i < 20; i++)
		OpU8_readStructs(stream,f7e0[i]);
	OpQ5_readObjects(stream,f7f0,0);
	OpQ5_readObjects(stream,f800,0);
	f810.read(stream);
	readBinary(stream,&f818);
	OpU8_readStructs(stream,f81c);
	readBinary(stream,&f82c);
	OpS8a_readP8s(stream,f830);
	OpS8a_readP8s(stream,f840);
	OpU8_readStructs(stream,f850);
	readBinary(stream,&f860);
	readBinary(stream,&f864);
	readBinary(stream,&f868);
	f86c.read(stream);
	OpQ5_readVectors(stream,f874);
	OpS8a_readP8s(stream,f884);
	OpT8a_readInts(stream,f894);
	readBinary(stream,&f8a4);
	readBinary(stream,&f8a8);
	readBinary(stream,&f8ac);
	if (opr1c_convertBuildno_432720(str_d204b0) >= opr1c_convertBuildno_432720("260819a"))
		readBinary(stream,&f8b0);
	else
		f8b0 = 0;
	OpS8d_readStructs(stream,f8b4);
	readBinary(stream,&f8c4);
	readBinary(stream,&f8c8);
	f8cc.read(stream);
	OpQ5_readVectors(stream,f8dc);
	OpQ5_readObjectVectors(stream,f8ec);
	readBinary(stream,&f8fc);
	readBinary(stream,&f900);
	OpS8a_readP8s(stream,f904);
	OpU8_readStructs(stream,f914);
	f924.read(stream);
	f934.read(stream);
	f944.read(stream);
	f954.read(stream);
	readBinary(stream,&f964);
	readBinary(stream,&f968);
	OpS8d_readStructs(stream,f96c);
	OpS8d_readStructs(stream,f97c);
	readBinary(stream,&f98c);
	OpU8_readStructs(stream,f990);
	readBinary(stream,&f9a0);
	readBinary(stream,&f9a4);
	readBinary(stream,&f9a8);
	readBinary(stream,&f9ac);
	readBinary(stream,&f9b0);
	readBinary(stream,&f9b8);
	OpU8_readStructs(stream,f9bc);
	readBinary(stream,&f9cc);
	readBinary(stream,&f9d0);
	OpU8_readStructs(stream,f9d4);
	readBinary(stream,&f9e4);
	f9e8.read(stream);
	readBinary(stream,&f9ec);
	readBinary(stream,&f9f0);
	OpU8_readStructs(stream,f9f4);
	readBinary(stream,&fa04);
	readBinary(stream,&fa08);
	readBinary(stream,&fa0c);
	readBinary(stream,&fa0d);
	readBinary(stream,&fa0e);
	readBinary(stream,&fa10);
	readBinary(stream,&fa14);
	readBinary(stream,&fa15);
	readBinary(stream,&fa16);
	readBinary(stream,&fa18);
	readBinary(stream,&fa1c);
	OpU8_readStructs(stream,fa20);
	fa70 = 0;
	fa74 = false;
	fa78.resetField();
	fa7c.resetField();
	OpQ5_readObjects(stream,fa80,0);
	readBinary(stream,&fb04);
	fbe8.init(cells_cfd44c.getWidth(),cells_cfd44c.getHeight(),0);
	fb05 = flag_cefacf, fb06 = flag_cefacf, fb07 = flag_cefacf;	// NOTE: one statement (three separate ones rotate the /Od registers differently)
	OpQ5_readObjects(stream,fb08,0);
	readBinary(stream,&fb18);
	fb1c = 0;
	readBinary(stream,&fb20);
	OpU8_readStructs(stream,fb24);
	readBinary(stream,&fb34);
	readBinary(stream,&fb38);
	fb3c.read(stream);
	readBinary(stream,&fb44);
	readBinary(stream,&fb48);
	fb4c.OpV4b_read(stream);
	OpU8_readStructs(stream,fb70);
	OpQ5_readPointer(stream,fb80);
	OpS8a_readP8s(stream,fb84);
	fc14 = 0;
	readBinary(stream,&fba4);
	fba8.read(stream);
	readBinary(stream,&fbac);
	readBinary(stream,&fbb0);
	OpT8a_readInts(stream,fbb4);
	OpT8a_readInts(stream,fbc4);
	OpS8c_readPoints(stream,fbd4);
	readBinary(stream,&fbe4);
	jlog_cefa64->end(2);
}
