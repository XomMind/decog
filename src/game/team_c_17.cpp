// team_c_17: OpT5_DataLoader::unknown7917a0 (0x7917a0): loads data/particles.bin into the game-data globals
// NOTE: global names are placeholders (data_<exe address>); element types carry the names of the folded instances
#include <string>
#include <vector>
#include <istream>
#include "thirdparty/zfstream.h"
using namespace std;

struct OpQ5_T9d5e90;	// NOTE: placeholder (element type)
struct OpQ5_T9d69b0;	// NOTE: placeholder (element type)
struct OpQ5_T9d6fc0;	// NOTE: placeholder (element type)
struct OpQ5_T9d9d30;	// NOTE: placeholder (element type)
struct OpQ5_T9df780;	// NOTE: placeholder (element type)
struct OpQ5_T9df8c0;	// NOTE: placeholder (element type)
struct OpQ5_T9dfaa0;	// NOTE: placeholder (element type)
struct OpQ5_T9dfc30;	// NOTE: placeholder (element type)
struct OpQ5_T9dfdc0;	// NOTE: placeholder (element type)
struct OpQ5_T9dff00;	// NOTE: placeholder (element type)
struct OpQ5_T9e0040;	// NOTE: placeholder (element type)
struct OpQ5_T9e0180;	// NOTE: placeholder (element type)
struct OpQ5_T9e02c0;	// NOTE: placeholder (element type)
struct OpQ5_T9e0400;	// NOTE: placeholder (element type)
struct OpQ5_T9e04f0;	// NOTE: placeholder (element type)
struct OpQ5_T9e0680;	// NOTE: placeholder (element type)
struct OpQ5_T9e07c0;	// NOTE: placeholder (element type)
struct OpQ5_T9e0900;	// NOTE: placeholder (element type)
struct OpQ5_T9e0a40;	// NOTE: placeholder (element type)
struct OpQ5_T9e0b80;	// NOTE: placeholder (element type)
struct OpQ5_T9e0cc0;	// NOTE: placeholder (element type)
struct OpQ5_T9e13a0;	// NOTE: placeholder (element type)
struct OpQ5_T9e1620;	// NOTE: placeholder (element type)
struct OpQ5_T9e1760;	// NOTE: placeholder (element type)
struct OpQ5_T9e18a0;	// NOTE: placeholder (element type)
struct OpQ5_T9e19e0;	// NOTE: placeholder (element type)
struct OpQ5_T9ef000;	// NOTE: placeholder (element type)
struct OpQ5_U9dfa00;	// NOTE: placeholder (element type)
struct OpQ5_U9dfbe0;	// NOTE: placeholder (element type)
struct OpQ5_U9dfd70;	// NOTE: placeholder (element type)
struct OpQ5_U9e0630;	// NOTE: placeholder (element type)
struct OpQ5_U9e0e50;	// NOTE: placeholder (element type)
struct OpQ5_U9e0f90;	// NOTE: placeholder (element type)
struct OpQ5_U9e10d0;	// NOTE: placeholder (element type)
struct OpQ5_U9e1210;	// NOTE: placeholder (element type)
struct OpQ5_U9e1260;	// NOTE: placeholder (element type)
struct OpC_SubRec	// NOTE: placeholder name/layout
{
	char pad0[0x40];
	string name40;
};

struct OpQ5_T9e14e0	// NOTE: placeholder layout (map record)
{
	char pad0[0x24];
	vector<OpC_SubRec *> sub24;
};

template <class T> void readBinary(istream &stream, T *value);
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);
template <class T> void OpQ5_readObjectVectors(istream &stream, vector< vector<T*> > &v);
template <class T> void OpQ5_readObjectsChance(istream &stream, vector<T*> &v);
template <class T> void OpQ5_readReference(istream &stream, T *&p, vector<T*> &list);
template <class T> void OpQ5_readReferences(istream &stream, vector<T*> &v, vector<T*> &list);
template <class T> void OpS8d_readPointers(istream &stream, vector<T*> &v);
void OpQ1_readString(istream &in, string *text);
void OpQ1_readStringVector(istream &in, vector<string> *list);
void OpQ1_readStringVectorList(istream &in, vector< vector<string> > *lists);
void OpT8a_readInts(istream &stream, vector<int> &v);
void OpS8b_Fn9d4ec0(istream &stream, int *values);
void OpV4c_Fn9d3b80(istream &stream, char *text);
void opr4a_unknown777dd0(istream &stream);
int ops7_indexOf_9cf120(const char *text, unsigned int length, char c);
void OpV3d_setLogMsgTimes();
void opt5_replaceColors();

class RNG
{
public:
	int seed(int value);
};
extern RNG rng_d20d00;

struct OpS7_ByteGrid { int width; int height; char *cells; void read_9cec80(istream &stream); };
struct OpS7_IntGrid2 { int width; int height; int *cells; void read_9cee40(istream &stream); };
struct OpV4b_Ints3 { int a; int b; int c; void OpV4b_read(istream &stream); };
struct ObjList_437560 { void read(istream &stream); };	// NOTE: placeholder layout
struct OpC_Reader9d3360 { void read(istream &stream); };	// NOTE: placeholder name (0x9d3360)
struct OpX5_Reader9d3230 { void read(istream &stream, vector<OpQ5_T9d6fc0 *> &list); };	// NOTE: placeholder layout
struct OpX5_Reader9d32e0 { void read(istream &stream, vector<OpQ5_U9e1260 *> &list); };	// NOTE: placeholder layout

extern gzifstream *opt5_stream;	// NOTE: placeholder name (0xcefc18)
extern OpS7_ByteGrid grids_d201c8[7];	// NOTE: placeholder name
extern const char chars_caf450[];	// NOTE: placeholder name
extern bool flag_cefbc5;	// NOTE: placeholder name
extern int data_caf2ac;	// NOTE: placeholder name
extern int data_caf2b0;	// NOTE: placeholder name
extern int data_caf2b4;	// NOTE: placeholder name
extern int data_ce9ff8;	// NOTE: placeholder name
extern int data_cebc4c;	// NOTE: placeholder name
extern char data_cebc58[];	// NOTE: placeholder name
extern char data_cebcd8[];	// NOTE: placeholder name
extern char data_cebdd8[];	// NOTE: placeholder name
extern char data_cebe58[];	// NOTE: placeholder name
extern int data_cec150[];	// NOTE: placeholder name
extern char data_cec350[];	// NOTE: placeholder name
extern char data_cec3d0[];	// NOTE: placeholder name
extern int data_cec964;	// NOTE: placeholder name
extern char data_cec968[];	// NOTE: placeholder name
extern char data_cec9e8[];	// NOTE: placeholder name
extern char data_ced0e8[];	// NOTE: placeholder name
extern char data_cef680[];	// NOTE: placeholder name
extern char data_cef700[];	// NOTE: placeholder name
extern char data_cef9e0[];	// NOTE: placeholder name
extern OpQ5_T9d5e90 * data_cefbc8;	// NOTE: placeholder name
extern OpQ5_T9e0400 * data_cefbcc;	// NOTE: placeholder name
extern OpQ5_T9d9d30 * data_cefbd0;	// NOTE: placeholder name
extern OpQ5_T9d9d30 * data_cefbd4;	// NOTE: placeholder name
extern OpQ5_T9d9d30 * data_cefbd8;	// NOTE: placeholder name
extern OpQ5_T9d9d30 * data_cefbdc;	// NOTE: placeholder name
extern OpQ5_T9d9d30 * data_cefbe0;	// NOTE: placeholder name
extern OpQ5_T9d6fc0 * data_cefbe4;	// NOTE: placeholder name
extern OpQ5_T9d6fc0 * data_cefbe8;	// NOTE: placeholder name
extern OpQ5_T9d6fc0 * data_cefbec;	// NOTE: placeholder name
extern OpQ5_T9d6fc0 * data_cefbf0;	// NOTE: placeholder name
extern OpQ5_T9d6fc0 * data_cefbf4;	// NOTE: placeholder name
extern OpQ5_T9d6fc0 * data_cefbf8;	// NOTE: placeholder name
extern OpQ5_T9d6fc0 * data_cefbfc;	// NOTE: placeholder name
extern OpQ5_T9d6fc0 * data_cefc00;	// NOTE: placeholder name
extern int data_cefc04;	// NOTE: placeholder name
extern OpQ5_T9d69b0 * data_cefc08;	// NOTE: placeholder name
extern OpQ5_T9d69b0 * data_cefc0c;	// NOTE: placeholder name
extern OpQ5_T9d69b0 * data_cefc10;	// NOTE: placeholder name
extern int data_cefcac;	// NOTE: placeholder name
extern vector<int> data_cefce8;	// NOTE: placeholder name
extern vector<OpQ5_T9e0a40 *> data_cf08c4;	// NOTE: placeholder name
extern vector<int> data_cf08d4;	// NOTE: placeholder name
extern vector<OpQ5_T9df8c0 *> data_cf09a8;	// NOTE: placeholder name
extern OpX5_Reader9d3230 data_cf0c04;	// NOTE: placeholder name
extern vector<OpQ5_T9e13a0 *> data_cf1af8;	// NOTE: placeholder name
extern OpX5_Reader9d32e0 data_cf2974;	// NOTE: placeholder name
extern vector<OpQ5_U9e0e50 *> data_cf35b0;	// NOTE: placeholder name
extern vector<OpQ5_T9e0b80 *> data_cf3a20;	// NOTE: placeholder name
extern vector< vector<OpQ5_U9dfa00 *> > data_cf4544;	// NOTE: placeholder name
extern vector<int> data_cf4554;	// NOTE: placeholder name
extern vector<OpQ5_T9e0900 *> data_cf671c;	// NOTE: placeholder name
extern vector<OpQ5_T9dfdc0 *> data_cf67c0;	// NOTE: placeholder name
extern vector<OpQ5_T9e1760 *> data_cf7560;	// NOTE: placeholder name
extern vector<OpQ5_U9e1210 *> data_cf7574;	// NOTE: placeholder name
extern vector<OpQ5_U9e0f90 *> data_cfb844;	// NOTE: placeholder name
extern vector< vector<string> > data_cfc184;	// NOTE: placeholder name
extern vector<string> data_cfcc5c;	// NOTE: placeholder name
extern vector<OpQ5_T9e0680 *> data_cfd2cc;	// NOTE: placeholder name
extern vector<OpQ5_T9dfc30 *> data_cfd2ec;	// NOTE: placeholder name
extern OpX5_Reader9d3230 data_cfe5ec;	// NOTE: placeholder name
extern vector<OpQ5_T9dff00 *> data_cfe704;	// NOTE: placeholder name
extern vector<OpQ5_T9e0180 *> data_d01c04;	// NOTE: placeholder name
extern OpX5_Reader9d32e0 data_d02b74;	// NOTE: placeholder name
extern vector<OpQ5_T9e19e0 *> data_d02cb4;	// NOTE: placeholder name
extern vector<int> data_d02cd0;	// NOTE: placeholder name
extern vector<OpQ5_T9e14e0 *> data_d15d9c;	// NOTE: placeholder name
extern vector<int> data_d161b4;	// NOTE: placeholder name
extern vector<string> data_d1d61c;	// NOTE: placeholder name
extern vector<string> data_d1d9b0;	// NOTE: placeholder name
extern ObjList_437560 data_d1da88;	// NOTE: placeholder name
extern vector<OpQ5_U9e1210 *> data_d1e00c;	// NOTE: placeholder name
extern vector<OpQ5_T9e0040 *> data_d1e31c;	// NOTE: placeholder name
extern vector<OpQ5_T9ef000 *> data_d1e32c;	// NOTE: placeholder name
extern vector<string> data_d204dc;	// NOTE: placeholder name
extern vector< vector<string> > data_d204ec;	// NOTE: placeholder name
extern vector<OpQ5_T9e1620 *> data_d21afc;	// NOTE: placeholder name
extern OpS7_ByteGrid data_d21b28;	// NOTE: placeholder name
extern vector<OpQ5_T9e07c0 *> data_d223b4;	// NOTE: placeholder name
extern vector<string> data_d2283c;	// NOTE: placeholder name
extern vector<OpQ5_U9e1260 *> data_d25de0;	// NOTE: placeholder name
extern vector<int> data_d25f50;	// NOTE: placeholder name
extern OpX5_Reader9d32e0 data_d2601c;	// NOTE: placeholder name
extern vector<string> data_d29808;	// NOTE: placeholder name
extern OpX5_Reader9d3230 data_d29d44;	// NOTE: placeholder name
extern vector<string> data_d29d7c;	// NOTE: placeholder name
extern OpX5_Reader9d32e0 data_d29da4;	// NOTE: placeholder name
extern OpX5_Reader9d3230 data_d2ae08;	// NOTE: placeholder name
extern vector<OpQ5_T9e04f0 *> data_d2b4d8;	// NOTE: placeholder name
extern vector<OpQ5_U9dfbe0 *> data_d2c34c;	// NOTE: placeholder name
extern vector<OpQ5_T9e0cc0 *> data_d2c408;	// NOTE: placeholder name
extern vector<string> data_d2c42c;	// NOTE: placeholder name
extern vector<string> data_d2c444;	// NOTE: placeholder name
extern vector<OpQ5_U9e10d0 *> data_d2d1c4;	// NOTE: placeholder name
extern vector<OpQ5_U9dfd70 *> data_d2e9a0;	// NOTE: placeholder name
extern ObjList_437560 data_d2e9b0;	// NOTE: placeholder name
extern OpC_Reader9d3360 data_d2ea30;	// NOTE: placeholder name
extern vector<OpQ5_U9e1210 *> data_d2ed7c;	// NOTE: placeholder name
extern vector<OpQ5_T9e07c0 *> data_d2f0f8;	// NOTE: placeholder name
extern vector<int> data_d2f4f4;	// NOTE: placeholder name
extern vector<string> data_d30540;	// NOTE: placeholder name
extern vector<OpQ5_U9e1210 *> data_d31510;	// NOTE: placeholder name
extern vector<OpQ5_U9e1210 *> data_d316a0;	// NOTE: placeholder name
extern OpX5_Reader9d3230 data_d31700;	// NOTE: placeholder name
extern vector<string> data_d323ac;	// NOTE: placeholder name
extern vector<OpQ5_U9e1210 *> data_d32990;	// NOTE: placeholder name
extern int data_d329a0;	// NOTE: placeholder name
extern vector<OpQ5_U9e0630 *> data_d32ce0;	// NOTE: placeholder name
extern vector<OpQ5_T9dfaa0 *> data_d35870;	// NOTE: placeholder name
extern OpV4b_Ints3 data_d358c0;	// NOTE: placeholder name
extern vector<OpQ5_T9e02c0 *> data_d35b48;	// NOTE: placeholder name
extern vector<OpQ5_T9e18a0 *> data_d35b58;	// NOTE: placeholder name
extern vector<string> data_d37a40;	// NOTE: placeholder name
extern vector<string> data_d388e0;	// NOTE: placeholder name
extern vector<OpQ5_T9df780 *> data_d389c4;	// NOTE: placeholder name
extern OpS7_IntGrid2 data_d396dc;	// NOTE: placeholder name

struct OpT5_DataLoader	// NOTE: placeholder name
{
	void cleanup();
	void processSoundGroups();
	void processSounds();
	void unknown78f9f0();
	void unknown78fa10();
	bool unknown7917a0();
};

bool OpT5_DataLoader::unknown7917a0()
{
	opt5_stream = new gzifstream((string() + "data/particles.bin").c_str(),ios::binary);
	if (!opt5_stream->is_open())
	{
		delete opt5_stream;
		opt5_stream = NULL;
		return false;
	}
	rng_d20d00.seed(0x5e);
	string version;
	OpQ1_readString(*opt5_stream,&version);
	OpQ5_readObjects(*opt5_stream,data_d389c4,0);
	OpQ5_readObjects(*opt5_stream,data_cf09a8,0);
	OpQ5_readObjectVectors(*opt5_stream,data_cf4544);
	OpT8a_readInts(*opt5_stream,data_cf08d4);
	OpS8b_Fn9d4ec0(*opt5_stream,data_cec150);
	OpV4c_Fn9d3b80(*opt5_stream,data_cef680);
	OpV4c_Fn9d3b80(*opt5_stream,data_cef9e0);
	OpV4c_Fn9d3b80(*opt5_stream,data_ced0e8);
	OpV4c_Fn9d3b80(*opt5_stream,data_cebe58);
	OpV4c_Fn9d3b80(*opt5_stream,data_cec968);
	OpV4c_Fn9d3b80(*opt5_stream,data_cebdd8);
	OpV4c_Fn9d3b80(*opt5_stream,data_cec3d0);
	OpV4c_Fn9d3b80(*opt5_stream,data_cec350);
	OpV4c_Fn9d3b80(*opt5_stream,data_cebc58);
	OpV4c_Fn9d3b80(*opt5_stream,data_cec9e8);
	OpV4c_Fn9d3b80(*opt5_stream,data_cef700);
	OpV4c_Fn9d3b80(*opt5_stream,data_cebcd8);
	data_d21b28.read_9cec80(*opt5_stream);
	data_d396dc.read_9cee40(*opt5_stream);
	OpQ5_readObjects(*opt5_stream,data_d35870,0);
	OpQ5_readReferences(*opt5_stream,data_d2c34c,(vector<OpQ5_U9dfbe0 *> &)data_d35870);
	processSoundGroups();
	OpQ5_readObjects(*opt5_stream,data_cfd2ec,0);
	OpQ5_readReferences(*opt5_stream,data_d2e9a0,(vector<OpQ5_U9dfd70 *> &)data_cfd2ec);
	processSounds();
	OpQ5_readObjects(*opt5_stream,data_cf67c0,0);
	OpQ1_readStringVector(*opt5_stream,&data_d29808);
	OpT8a_readInts(*opt5_stream,data_d161b4);
	opt5_replaceColors();
	OpQ5_readObjects(*opt5_stream,data_cfe704,0);
	OpQ1_readStringVector(*opt5_stream,&data_cfcc5c);
	OpQ1_readStringVector(*opt5_stream,&data_d323ac);
	OpT8a_readInts(*opt5_stream,data_d2f4f4);
	OpV3d_setLogMsgTimes();
	OpQ5_readObjects(*opt5_stream,data_d1e31c,0);
	OpQ5_readReference(*opt5_stream,data_cefbc8,(vector<OpQ5_T9d5e90 *> &)data_d1e31c);
	OpQ5_readObjects(*opt5_stream,data_d01c04,0);
	OpQ5_readObjects(*opt5_stream,data_d35b48,0);
	OpQ5_readReference(*opt5_stream,data_cefbcc,(vector<OpQ5_T9e0400 *> &)data_d35b48);
	OpQ5_readObjects(*opt5_stream,data_d2b4d8,0);
	OpQ5_readReferences(*opt5_stream,data_d32ce0,(vector<OpQ5_U9e0630 *> &)data_d35b48);
	OpQ5_readObjects(*opt5_stream,data_cfd2cc,0);
	OpQ5_readObjects(*opt5_stream,data_d2f0f8,0);
	OpQ5_readObjects(*opt5_stream,data_cf671c,0);
	OpQ5_readObjects(*opt5_stream,data_d223b4,0);
	OpQ5_readObjects(*opt5_stream,data_cf08c4,0);
	OpQ5_readObjects(*opt5_stream,data_cf3a20,0);
	OpQ5_readObjects(*opt5_stream,data_d2c408,0);
	OpS8d_readPointers(*opt5_stream,data_d1e32c);
	data_d358c0.OpV4b_read(*opt5_stream);
	OpQ5_readObjectsChance(*opt5_stream,data_cf35b0);
	OpQ5_readReference(*opt5_stream,data_cefbd0,(vector<OpQ5_T9d9d30 *> &)data_cf35b0);
	OpQ5_readReference(*opt5_stream,data_cefbd4,(vector<OpQ5_T9d9d30 *> &)data_cf35b0);
	OpQ5_readReference(*opt5_stream,data_cefbd8,(vector<OpQ5_T9d9d30 *> &)data_cf35b0);
	OpQ5_readReference(*opt5_stream,data_cefbdc,(vector<OpQ5_T9d9d30 *> &)data_cf35b0);
	OpQ5_readReference(*opt5_stream,data_cefbe0,(vector<OpQ5_T9d9d30 *> &)data_cf35b0);
	OpQ5_readObjectsChance(*opt5_stream,data_cfb844);
	cleanup();
	OpQ5_readObjectsChance(*opt5_stream,data_d2d1c4);
	OpQ5_readReference(*opt5_stream,data_cefbe4,(vector<OpQ5_T9d6fc0 *> &)data_d2d1c4);
	OpQ5_readReference(*opt5_stream,data_cefbe8,(vector<OpQ5_T9d6fc0 *> &)data_d2d1c4);
	OpQ5_readReference(*opt5_stream,data_cefbec,(vector<OpQ5_T9d6fc0 *> &)data_d2d1c4);
	OpQ5_readReference(*opt5_stream,data_cefbf0,(vector<OpQ5_T9d6fc0 *> &)data_d2d1c4);
	OpQ5_readReference(*opt5_stream,data_cefbf4,(vector<OpQ5_T9d6fc0 *> &)data_d2d1c4);
	OpQ5_readReference(*opt5_stream,data_cefbf8,(vector<OpQ5_T9d6fc0 *> &)data_d2d1c4);
	OpQ5_readReference(*opt5_stream,data_cefbfc,(vector<OpQ5_T9d6fc0 *> &)data_d2d1c4);
	OpQ5_readReference(*opt5_stream,data_cefc00,(vector<OpQ5_T9d6fc0 *> &)data_d2d1c4);
	readBinary(*opt5_stream,&data_cefc04);
	data_d2e9b0.read(*opt5_stream);
	data_d1da88.read(*opt5_stream);
	OpQ5_readReferences(*opt5_stream,data_d2ed7c,(vector<OpQ5_U9e1210 *> &)data_d2d1c4);
	OpQ5_readReferences(*opt5_stream,data_d316a0,(vector<OpQ5_U9e1210 *> &)data_d2d1c4);
	OpQ5_readReferences(*opt5_stream,data_d32990,(vector<OpQ5_U9e1210 *> &)data_d2d1c4);
	OpQ5_readReferences(*opt5_stream,data_d31510,(vector<OpQ5_U9e1210 *> &)data_d2d1c4);
	data_d2ae08.read(*opt5_stream,(vector<OpQ5_T9d6fc0 *> &)data_d2d1c4);
	data_d31700.read(*opt5_stream,(vector<OpQ5_T9d6fc0 *> &)data_d2d1c4);
	data_cf0c04.read(*opt5_stream,(vector<OpQ5_T9d6fc0 *> &)data_d2d1c4);
	data_cfe5ec.read(*opt5_stream,(vector<OpQ5_T9d6fc0 *> &)data_d2d1c4);
	data_d29d44.read(*opt5_stream,(vector<OpQ5_T9d6fc0 *> &)data_d2d1c4);
	OpQ5_readReferences(*opt5_stream,data_d1e00c,(vector<OpQ5_U9e1210 *> &)data_d2d1c4);
	OpT8a_readInts(*opt5_stream,data_cf4554);
	OpT8a_readInts(*opt5_stream,data_d25f50);
	OpT8a_readInts(*opt5_stream,data_cefce8);
	OpT8a_readInts(*opt5_stream,data_d02cd0);
	OpQ5_readReferences(*opt5_stream,data_cf7574,(vector<OpQ5_U9e1210 *> &)data_d2d1c4);
	OpQ1_readStringVector(*opt5_stream,&data_d2c444);
	OpQ1_readStringVector(*opt5_stream,&data_d204dc);
	OpQ1_readStringVector(*opt5_stream,&data_d37a40);
	OpQ1_readStringVectorList(*opt5_stream,&data_d204ec);
	unknown78f9f0();
	OpQ5_readObjectsChance(*opt5_stream,data_d25de0);
	readBinary(*opt5_stream,&data_cec964);
	OpQ5_readReference(*opt5_stream,data_cefc08,(vector<OpQ5_T9d69b0 *> &)data_d25de0);
	OpQ5_readReference(*opt5_stream,data_cefc0c,(vector<OpQ5_T9d69b0 *> &)data_d25de0);
	OpQ5_readReference(*opt5_stream,data_cefc10,(vector<OpQ5_T9d69b0 *> &)data_d25de0);
	readBinary(*opt5_stream,&data_cebc4c);
	data_d02b74.read(*opt5_stream,data_d25de0);
	data_d2601c.read(*opt5_stream,data_d25de0);
	data_cf2974.read(*opt5_stream,data_d25de0);
	data_d29da4.read(*opt5_stream,data_d25de0);
	readBinary(*opt5_stream,&data_ce9ff8);
	OpQ1_readStringVector(*opt5_stream,&data_d30540);
	OpQ1_readStringVector(*opt5_stream,&data_d1d61c);
	OpQ1_readStringVector(*opt5_stream,&data_d29d7c);
	readBinary(*opt5_stream,&data_caf2ac);
	readBinary(*opt5_stream,&data_caf2b0);
	readBinary(*opt5_stream,&data_caf2b4);
	unknown78fa10();
	for (int i = 0; i < 7; i++)
		grids_d201c8[i].read_9cec80(*opt5_stream);
	data_d2ea30.read(*opt5_stream);
	OpQ5_readObjects(*opt5_stream,data_cf1af8,0);
	OpQ5_readObjects(*opt5_stream,data_d15d9c,0);
	for (unsigned int j = 0; j < data_d15d9c.size(); j++)
	{
		for (unsigned int k = 0; k < data_d15d9c[j]->sub24.size(); k++)
		{
			if (data_d15d9c[j]->sub24[k]->name40.size() >= 4 && ops7_indexOf_9cf120(chars_caf450,12,data_d15d9c[j]->sub24[k]->name40[0]) == -1)
				flag_cefbc5 = true;
		}
	}
	readBinary(*opt5_stream,&data_cefcac);
	readBinary(*opt5_stream,&data_d329a0);
	OpQ5_readObjects(*opt5_stream,data_d21afc,0);
	OpQ5_readObjects(*opt5_stream,data_cf7560,0);
	OpQ1_readStringVector(*opt5_stream,&data_d388e0);
	OpQ1_readStringVector(*opt5_stream,&data_d2c42c);
	OpQ1_readStringVectorList(*opt5_stream,&data_cfc184);
	OpQ5_readObjects(*opt5_stream,data_d35b58,0);
	OpQ1_readStringVector(*opt5_stream,&data_d1d9b0);
	OpQ1_readStringVector(*opt5_stream,&data_d2283c);
	OpQ5_readObjects(*opt5_stream,data_d02cb4,0);
	opr4a_unknown777dd0(*opt5_stream);
	opt5_stream->close();
	delete opt5_stream;
	opt5_stream = NULL;
	return true;
}
