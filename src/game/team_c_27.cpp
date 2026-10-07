// team_c_27: PlayerData::read (0x77c760): reads the player state at 0xcf45d8 back, mirroring PlayerData::serialize (team_c_14)
// NOTE: member names are placeholders (f<offset>); types and globals are private placeholders (c27_ / C27_)

#include <string>
#include <vector>
#include <istream>
using namespace std;

struct Point { int x; int y; };
struct C27_Elem { int a; int b; };	// NOTE: placeholder layout (element type)
struct C27_Slot;	// NOTE: placeholder (element type)
struct C27_Obj1;	// NOTE: placeholder (element type)
struct C27_Obj2;	// NOTE: placeholder (element type)
struct C27_Obj3;	// NOTE: placeholder (element type)
struct C27_Owned { ~C27_Owned(); };	// NOTE: placeholder (deleting dtor folded with Wrapper_77b4a0::release)
struct C27_Owned2 { ~C27_Owned2(); };	// NOTE: placeholder (deleting dtor folded with OpR6_KCD_68_0)
struct C27_Owned3 { ~C27_Owned3(); };	// NOTE: placeholder (deleting dtor folded with Wrapper_70e610::release)

template <class T> void readBinary(istream &stream, T *value);
template <class T> void OpU8_readStructs(istream &stream, vector<T> &v);
template <class T> void OpQ5_readPointer(istream &stream, T *&p);
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);
template <class T> void OpQ5_clearObjects(vector<T*> &v);
void opr2_readText_436960(istream &stream, string *value);	// NOTE: placeholder name (0x436960)
void OpQ1_readString(istream &in, string *text);	// 0x4096f0
void OpQ1_readStringVector(istream &in, vector<string> *list);	// 0x4097e0
void OpT8a_readInts(istream &in, vector<int> &v);
void c27_readInts(istream &in, vector<int> &v);	// NOTE: placeholder name (folded with OpS8d_readFloats)
void OpS8b_Fn9d4ec0(istream &stream, int *values);
void OpS8c_readPoints(istream &stream, vector<Point> &v);
void OpS8c_copyInts(int *src, int *dst, unsigned int count);
bool OpV4c_Fn9d3f40(int *list, unsigned int count);
int c27_countNonZero(vector<int> &v);	// NOTE: placeholder name (folded with OpS8d_countNonNull)

struct OpC_IntBox { int v; void read(istream &stream); };
struct OpU1_Point { int x; int y; void read(istream &stream); };
struct OpR1g_Triple { char pad[0x30]; void read(istream &stream); };	// NOTE: placeholder layout

class C27_Loader	// NOTE: placeholder name (object at 0xcefaa8)
{
public:
	bool getField();	// NOTE: folded with Sweep_470b30::getField
	void resetField();	// NOTE: folded with Sweep_470be0::resetField
	void unknown792750();
	void unknown792890();
};
class C27_KeyMap { public: void setMarked(unsigned int index, bool value); };	// NOTE: placeholder name (0xcefa8c)
struct C27_Root { char pad0[0x79]; bool f79; int f7c; int f80[12]; };	// NOTE: placeholder layout (0xcec034)
struct C27_Rec { char pad0[0x94]; int f94; };	// NOTE: placeholder layout
struct C27_Rec2;

extern C27_Loader *c27_loader;	// NOTE: placeholder name (0xcefaa8)
extern C27_KeyMap *c27_keyMap;	// NOTE: placeholder name (0xcefa8c)
extern C27_Root *c27_root;	// NOTE: placeholder name (0xcec034)
extern C27_Owned *c27_cefb48;	// NOTE: placeholder name
extern vector<int> c27_d379ec;	// NOTE: placeholder name
extern vector<int> c27_d25860;	// NOTE: placeholder name
extern vector<C27_Rec *> c27_d2d1c4;	// NOTE: placeholder name
extern vector<C27_Rec2 *> c27_d25de0;	// NOTE: placeholder name
extern vector<C27_Rec2 *> c27_d35b58;	// NOTE: placeholder name
extern vector<C27_Rec2 *> c27_cf3a20;	// NOTE: placeholder name
extern bool c27_flag_cefacd;	// NOTE: placeholder name

class PlayerData	// NOTE: placeholder layout (object at 0xcf45d8), same layout as team_c_14
{
public:
	string f0;
	int f1c;
	string f20;
	int f3c;
	OpC_IntBox f40;
	int f44;
	bool f48;
	int f4c;
	bool f50;
	int f54;
	int f58;
	vector<int> f5c;
	vector<int> f6c;
	vector<int> f7c;
	int f8c;
	int f90;
	int f94;
	int f98;
	int f9c;
	int fa0;
	vector<int> fa4;
	bool fb4;
	int fb8;
	int fbc;
	int fc0;
	int fc4;
	bool fc8;
	int fcc;
	int fd0;
	int fd4;
	C27_Owned * fd8;
	vector<C27_Elem> fdc;
	vector<int> fec;
	vector<C27_Elem> ffc;
	vector<int> f10c;
	int f11c;
	int f120;
	int f124;
	C27_Owned2 * f128;
	vector<int> f12c;
	char pad13c[0x4];
	int f140;
	int f144[12];
	bool f174;
	bool f175;
	vector< vector<C27_Slot *> > f178;
	vector<C27_Obj1 *> f188;
	vector<int> f198;
	bool f1a8;
	char pad1a9[0x3];
	OpR1g_Triple f1ac;
	int f1dc;
	int f1e0;
	int f1e4;
	int f1e8;
	int f1ec;
	int f1f0;
	vector<int> f1f4;
	vector<int> f204;
	vector<int> f214;
	int f224;
	vector<int> f228;
	vector<int> f238;
	vector<int> f248;
	vector<int> f258;
	int f268;
	vector<int> f26c;
	int f27c;
	vector<int> f280;
	vector<int> f290;
	vector<int> f2a0;
	vector<int> f2b0;
	int f2c0;
	vector<int> f2c4;
	vector<int> f2d4;
	vector<int> f2e4;
	vector<int> f2f4;
	int f304;
	vector<int> f308;
	vector<int> f318;
	vector<int> f328;
	vector<int> f338;
	int f348;
	vector<int> f34c;
	vector<int> f35c;
	vector<C27_Elem> f36c;
	int f37c;
	int f380;
	int f384;
	int f388;
	int f38c;
	int f390;
	int f394;
	int f398;
	int f39c;
	int f3a0;
	int f3a4;
	bool f3a8;
	int f3ac[7];
	int f3c8[7];
	int f3e4[7];
	int f400;
	int f404;
	int f408;
	bool f40c;
	int f410;
	int f414;
	bool f418;
	int f41c;
	int f420;
	int f424;
	bool f428;
	vector<int> f42c;
	vector<int> f43c;
	vector<int> f44c;
	int f45c;
	vector<C27_Elem> f460;
	vector<C27_Elem> f470;
	vector< vector<int> > f480;
	int f490;
	int f494;
	int f498;
	int f49c;
	bool f4a0;
	int f4a4;
	vector<Point> f4a8;
	int f4b8;
	int f4bc;
	vector<int> f4c0;
	vector<C27_Elem> f4d0;
	vector<int> f4e0;
	C27_Owned3 * f4f0;
	string f4f4;
	string f510;
	string f52c;
	int f548;
	vector<int> f54c;
	int f55c;
	int f560;
	string f564;
	bool f580;
	int f584;
	int f588;
	int f58c;
	int f590;
	int f594;
	int f598;
	vector<int> f59c;
	int f5ac;
	int f5b0;
	int f5b4;
	int f5b8;
	int f5bc;
	int f5c0;
	int f5c4;
	int f5c8;
	int f5cc;
	int f5d0;
	int f5d4;
	int f5d8;
	int f5dc;
	int f5e0;
	int f5e4;
	vector<string> f5e8;
	vector<int> f5f8;
	vector<C27_Obj2 *> f608;
	vector<int> f618;
	vector<int> f628;
	vector<int> f638;
	int f648;
	int f64c;
	vector<int> f650;
	vector<string> f660;
	vector<int> f670;
	vector<int> f680;
	vector<int> f690;
	vector<int> f6a0;
	vector<string> f6b0;
	vector<int> f6c0;
	vector<int> f6d0;
	vector<int> f6e0;
	vector<int> f6f0;
	vector<int> f700;
	vector<int> f710;
	int f720;
	int f724;
	vector<C27_Obj3 *> f728;
	int f738;
	bool f73c;
	bool f73d;
	bool f73e;
	bool f73f;
	bool f740;
	int f744;
	int f748;
	int f74c;
	int f750;
	int f754;
	int f758;
	int f75c;
	vector<int> f760;
	vector<C27_Elem> f770;
	int f780;
	int f784;
	int f788;
	int f78c;
	int f790;
	int f794;
	int f798;
	OpU1_Point f79c;
	int f7a4;
	int f7a8;
	int f7ac;
	int f7b0;
	int f7b4;
	int f7b8;

	bool isFlagActive();	// NOTE: placeholder name (folded with Unknown46d8b0::isFlagActive)
	void clearMarkers();	// NOTE: placeholder name (folded with Unknown46d8b0::clearMarkers)
	void unknown778930();	// NOTE: placeholder name (0x778930)
	void read(istream &stream);
};

void PlayerData::read(istream &stream)
{
	f0.clear();
	opr2_readText_436960(stream,&f0);
	readBinary(stream,&f1c);
	f20.clear();
	opr2_readText_436960(stream,&f20);
	readBinary(stream,&f3c);
	f40.read(stream);
	readBinary(stream,&f44);
	readBinary(stream,&f48);
	readBinary(stream,&f4c);
	readBinary(stream,&f50);
	if (c27_loader->getField())
		f50 = true;
	if (isFlagActive())
	{
		c27_loader->resetField();
		c27_keyMap->setMarked(6,true);
	}
	readBinary(stream,&f54);
	if (f54 == 7 && c27_d379ec.empty())
		c27_loader->unknown792750();
	if (false) {}	// NOTE: stands in for something that compiled to nothing (it shifts the /Od register rotation like the original)
	readBinary(stream,&f58);
	f5c.clear();
	c27_readInts(stream,f5c);
	f6c.clear();
	OpT8a_readInts(stream,f6c);
	f7c.clear();
	OpT8a_readInts(stream,f7c);
	readBinary(stream,&f8c);
	readBinary(stream,&f90);
	readBinary(stream,&f94);
	readBinary(stream,&f98);
	readBinary(stream,&f9c);
	readBinary(stream,&fa0);
	fa4.clear();
	OpT8a_readInts(stream,fa4);
	readBinary(stream,&fb4);
	readBinary(stream,&fb8);
	readBinary(stream,&fbc);
	readBinary(stream,&fc0);
	readBinary(stream,&fc4);
	readBinary(stream,&fc8);
	readBinary(stream,&fcc);
	readBinary(stream,&fd0);
	readBinary(stream,&fd4);
	delete fd8;
	OpQ5_readPointer(stream,fd8);
	c27_cefb48 = fd8;
	fdc.clear();
	OpU8_readStructs(stream,fdc);
	fec.clear();
	OpT8a_readInts(stream,fec);
	ffc.clear();
	OpU8_readStructs(stream,ffc);
	f10c.clear();
	OpT8a_readInts(stream,f10c);
	readBinary(stream,&f11c);
	readBinary(stream,&f120);
	readBinary(stream,&f124);
	delete f128;
	OpQ5_readPointer(stream,f128);
	f12c.clear();
	OpT8a_readInts(stream,f12c);
	readBinary(stream,&f140);
	OpS8b_Fn9d4ec0(stream,f144);
	readBinary(stream,&f174);
	if (!c27_root->f79)
	{
		c27_root->f7c = f54;
		OpS8c_copyInts(f144,c27_root->f80,12);
		c27_root->f79 = true;
		unknown778930();
	}
	else
	{
		f54 = c27_root->f7c;
		OpS8c_copyInts(c27_root->f80,f144,12);
		f174 = OpV4c_Fn9d3f40(f144,12);
	}
	readBinary(stream,&f175);
	clearMarkers();
	vector<C27_Slot *> vec;
	for (int i = 0; i < 4; i++)
	{
		f178.push_back(vec);
		OpQ5_readObjects(stream,f178.back(),0);
	}
	OpQ5_clearObjects(f188);
	OpQ5_readObjects(stream,f188,0);
	f198.clear();
	OpT8a_readInts(stream,f198);
	f1a8 = false;
	f1ac.read(stream);
	readBinary(stream,&f1dc);
	readBinary(stream,&f1e0);
	readBinary(stream,&f1e4);
	readBinary(stream,&f1e8);
	readBinary(stream,&f1ec);
	readBinary(stream,&f1f0);
	f1f4.clear();
	OpT8a_readInts(stream,f1f4);
	f204.clear();
	OpT8a_readInts(stream,f204);
	f214.clear();
	OpT8a_readInts(stream,f214);
	readBinary(stream,&f224);
	f228.clear();
	OpT8a_readInts(stream,f228);
	f238.clear();
	OpT8a_readInts(stream,f238);
	f248.clear();
	OpT8a_readInts(stream,f248);
	f258.clear();
	OpT8a_readInts(stream,f258);
	readBinary(stream,&f268);
	if (f258.size() != c27_d2d1c4.size())
	{
		f258.clear();
		f258.assign(c27_d2d1c4.size(),0);
		for (unsigned int i = 0; i < c27_d2d1c4.size(); i++)
			if (c27_d2d1c4[i]->f94 == 0)
				f258[i] = 1;
		f268 = c27_countNonZero(f258);
	}
	f26c.clear();
	OpT8a_readInts(stream,f26c);
	readBinary(stream,&f27c);
	if (f26c.size() != c27_d2d1c4.size())
	{
		f26c.assign(c27_d2d1c4.size(),0);
		f27c = 0;
	}
	f280.clear();
	OpT8a_readInts(stream,f280);
	f290.clear();
	OpT8a_readInts(stream,f290);
	f2a0.clear();
	OpT8a_readInts(stream,f2a0);
	f2b0.clear();
	OpT8a_readInts(stream,f2b0);
	readBinary(stream,&f2c0);
	if (f2b0.size() != c27_d25de0.size())
	{
		f2b0.assign(c27_d25de0.size(),0);
		f2c0 = 0;
	}
	f2c4.clear();
	OpT8a_readInts(stream,f2c4);
	f2d4.clear();
	OpT8a_readInts(stream,f2d4);
	f2e4.clear();
	OpT8a_readInts(stream,f2e4);
	f2f4.clear();
	OpT8a_readInts(stream,f2f4);
	readBinary(stream,&f304);
	if (f2f4.size() != c27_d2d1c4.size())
	{
		f2f4.assign(c27_d2d1c4.size(),0);
		f304 = 0;
	}
	f308.clear();
	OpT8a_readInts(stream,f308);
	f318.clear();
	OpT8a_readInts(stream,f318);
	f328.clear();
	OpT8a_readInts(stream,f328);
	f338.clear();
	OpT8a_readInts(stream,f338);
	if (f338.size() != c27_d25de0.size())
		f338.assign(c27_d25de0.size(),0);
	readBinary(stream,&f348);
	f34c.clear();
	OpT8a_readInts(stream,f34c);
	if (f34c.size() != c27_d35b58.size())
		f34c.assign(c27_d35b58.size(),0);
	f35c.clear();
	OpT8a_readInts(stream,f35c);
	if (f35c.size() != c27_cf3a20.size())
		f35c.assign(c27_cf3a20.size(),0);
	f36c.clear();
	OpU8_readStructs(stream,f36c);
	readBinary(stream,&f37c);
	readBinary(stream,&f380);
	readBinary(stream,&f384);
	readBinary(stream,&f388);
	readBinary(stream,&f38c);
	readBinary(stream,&f390);
	readBinary(stream,&f394);
	readBinary(stream,&f398);
	readBinary(stream,&f39c);
	readBinary(stream,&f3a0);
	readBinary(stream,&f3a4);
	readBinary(stream,&f3a8);
	OpS8b_Fn9d4ec0(stream,f3ac);
	OpS8b_Fn9d4ec0(stream,f3c8);
	OpS8b_Fn9d4ec0(stream,f3e4);
	readBinary(stream,&f400);
	readBinary(stream,&f404);
	readBinary(stream,&f408);
	readBinary(stream,&f40c);
	readBinary(stream,&f410);
	readBinary(stream,&f414);
	readBinary(stream,&f418);
	readBinary(stream,&f41c);
	readBinary(stream,&f420);
	readBinary(stream,&f424);
	readBinary(stream,&f428);
	f42c.clear();
	OpT8a_readInts(stream,f42c);
	f43c.clear();
	OpT8a_readInts(stream,f43c);
	f44c.clear();
	OpT8a_readInts(stream,f44c);
	f45c = 0;
	f460.clear();
	OpU8_readStructs(stream,f460);
	f470.clear();
	OpU8_readStructs(stream,f470);
	f480.clear();
	int n;
	readBinary(stream,&n);
	if (n)
	{
		f480.assign(n,vector<int>());
		for (int j = 0; j < n; j++)
			OpT8a_readInts(stream,f480[j]);
	}
	readBinary(stream,&f490);
	readBinary(stream,&f494);
	readBinary(stream,&f498);
	readBinary(stream,&f49c);
	readBinary(stream,&f4a0);
	readBinary(stream,&f4a4);
	f4a8.clear();
	OpS8c_readPoints(stream,f4a8);
	readBinary(stream,&f4b8);
	readBinary(stream,&f4bc);
	f4c0.clear();
	OpT8a_readInts(stream,f4c0);
	f4d0.clear();
	OpU8_readStructs(stream,f4d0);
	f4e0.clear();
	OpT8a_readInts(stream,f4e0);
	delete f4f0;
	OpQ5_readPointer(stream,f4f0);
	if (f4f0 && c27_d25860.empty())
		c27_loader->unknown792890();
	if (false) {}	// NOTE: see above
	f4f4.clear();
	OpQ1_readString(stream,&f4f4);
	f510.clear();
	OpQ1_readString(stream,&f510);
	f52c.clear();
	OpQ1_readString(stream,&f52c);
	readBinary(stream,&f548);
	f54c.clear();
	OpT8a_readInts(stream,f54c);
	readBinary(stream,&f55c);
	readBinary(stream,&f560);
	f564.clear();
	opr2_readText_436960(stream,&f564);
	readBinary(stream,&f580);
	if (c27_flag_cefacd)
		f580 = true;
	readBinary(stream,&f584);
	readBinary(stream,&f588);
	readBinary(stream,&f58c);
	readBinary(stream,&f590);
	readBinary(stream,&f594);
	readBinary(stream,&f598);
	f59c.clear();
	OpT8a_readInts(stream,f59c);
	readBinary(stream,&f5ac);
	readBinary(stream,&f5b0);
	readBinary(stream,&f5b4);
	readBinary(stream,&f5b8);
	readBinary(stream,&f5bc);
	readBinary(stream,&f5c0);
	readBinary(stream,&f5c4);
	readBinary(stream,&f5c8);
	readBinary(stream,&f5cc);
	readBinary(stream,&f5d0);
	readBinary(stream,&f5d4);
	readBinary(stream,&f5d8);
	readBinary(stream,&f5dc);
	readBinary(stream,&f5e0);
	readBinary(stream,&f5e4);
	f5e8.clear();
	OpQ1_readStringVector(stream,&f5e8);
	f5f8.clear();
	OpT8a_readInts(stream,f5f8);
	OpQ5_clearObjects(f608);
	OpQ5_readObjects(stream,f608,0);
	f618.clear();
	OpT8a_readInts(stream,f618);
	f628.clear();
	OpT8a_readInts(stream,f628);
	f638.clear();
	OpT8a_readInts(stream,f638);
	readBinary(stream,&f648);
	readBinary(stream,&f64c);
	f650.clear();
	OpT8a_readInts(stream,f650);
	f660.clear();
	OpQ1_readStringVector(stream,&f660);
	f670.clear();
	OpT8a_readInts(stream,f670);
	f680.clear();
	OpT8a_readInts(stream,f680);
	f690.clear();
	OpT8a_readInts(stream,f690);
	f6a0.clear();
	OpT8a_readInts(stream,f6a0);
	f6b0.clear();
	OpQ1_readStringVector(stream,&f6b0);
	f6c0.clear();
	OpT8a_readInts(stream,f6c0);
	f6d0.clear();
	OpT8a_readInts(stream,f6d0);
	f6e0.clear();
	OpT8a_readInts(stream,f6e0);
	f6f0.clear();
	OpT8a_readInts(stream,f6f0);
	f700.clear();
	OpT8a_readInts(stream,f700);
	f710.clear();
	OpT8a_readInts(stream,f710);
	readBinary(stream,&f720);
	readBinary(stream,&f724);
	OpQ5_clearObjects(f728);
	OpQ5_readObjects(stream,f728,0);
	readBinary(stream,&f738);
	readBinary(stream,&f73c);
	readBinary(stream,&f73d);
	readBinary(stream,&f73e);
	readBinary(stream,&f73f);
	readBinary(stream,&f740);
	readBinary(stream,&f744);
	readBinary(stream,&f748);
	readBinary(stream,&f74c);
	readBinary(stream,&f750);
	readBinary(stream,&f754);
	readBinary(stream,&f758);
	readBinary(stream,&f75c);
	f760.clear();
	OpT8a_readInts(stream,f760);
	f770.clear();
	OpU8_readStructs(stream,f770);
	readBinary(stream,&f780);
	readBinary(stream,&f784);
	readBinary(stream,&f788);
	readBinary(stream,&f78c);
	readBinary(stream,&f790);
	readBinary(stream,&f794);
	readBinary(stream,&f798);
	f79c.read(stream);
	readBinary(stream,&f7a4);
	readBinary(stream,&f7a8);
	readBinary(stream,&f7ac);
	readBinary(stream,&f7b0);
	readBinary(stream,&f7b4);
	readBinary(stream,&f7b8);
}
