// op_t5: assorted functions in 0x702000-0x7ed000
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <stdio.h>
#include "thirdparty/zfstream.h"

using namespace std;

//==================================================================
// data file loaders
//==================================================================

struct MapRecord;
struct OpQ5_T9e1b20;	// NOTE: placeholder name
struct OpQ5_T9e1c60;	// NOTE: placeholder name
struct OpQ5_T9e1da0;	// NOTE: placeholder name
struct OpQ5_T9e1ee0;	// NOTE: placeholder name
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name

void OpQ1_readString(istream &in, string *text);	// NOTE: placeholder name (0x4096f0)
void OpQ1_readStringVector(istream &in, vector<string> *list);	// NOTE: placeholder name (0x4097e0)
void OpQ1_readStringVectorList(istream &in, vector<vector<string> > *lists);	// NOTE: placeholder name (0x4098f0)
void opW5_readIntVector(istream &stream, vector<int> *value);	// NOTE: placeholder name (0x9cf5e0)
template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name

class RNG
{
public:
	int seed(int value);	// 0x4a3dc0
};
extern RNG rng_d20d00;	// NOTE: placeholder name (0xd20d00)

extern vector<MapRecord *> opt5_mapRecords;	// NOTE: placeholder name (0xcf1a04)
extern vector<OpQ5_T9e1c60 *> opt5_d161c4;	// NOTE: placeholder name
extern int opt5_d2ed8c;	// NOTE: placeholder name
extern int opt5_d33ad4;	// NOTE: placeholder name
extern vector<int> opt5_cf686c;	// NOTE: placeholder name
extern vector<vector<string> > opt5_d21b10;	// NOTE: placeholder name
extern vector<string> opt5_cf45a0;	// NOTE: placeholder name
extern vector<string> opt5_cf08b4;	// NOTE: placeholder name
extern vector<OpQ5_T9e1da0 *> opt5_d379ec;	// NOTE: placeholder name
extern vector<OpQ5_T9e1da0 *> opt5_d25860;	// NOTE: placeholder name
extern vector<OpQ5_T9e1ee0 *> opt5_d39458;	// NOTE: placeholder name
extern vector<OpQ5_T9e1ee0 *> opt5_d1d078;	// NOTE: placeholder name

struct OpT5_DataLoader	// NOTE: placeholder name
{
	bool unknown7917a0();	// 0x7917a0
	bool unknown792510();	// 0x792510
	bool unknown792750();	// 0x792750
	bool unknown792890();	// 0x792890
	bool unknown7929d0();	// 0x7929d0
	bool unknown792b10();	// 0x792b10
	bool unknown792c50();	// 0x792c50
};

bool OpT5_DataLoader::unknown792510()
{
	gzifstream stream((string() + "data/messages.bin").c_str(),ios::binary);
	if (!stream.is_open())
		return false;
	rng_d20d00.seed(0x5e);
	string version;
	OpQ1_readString(stream,&version);
	int numMaps;
	int skip;
	readBinary(stream,&numMaps);
	readBinary(stream,&skip);
	OpQ5_readObjects(stream,(vector<OpQ5_T9e1b20*>&)opt5_mapRecords,0);
	OpQ5_readObjects(stream,opt5_d161c4,opt5_mapRecords.size() == numMaps ? 0 : skip / 2);
	readBinary(stream,&opt5_d2ed8c);
	readBinary(stream,&opt5_d33ad4);
	opW5_readIntVector(stream,&opt5_cf686c);
	stream.close();
	return true;
}

bool OpT5_DataLoader::unknown792750()
{
	gzifstream stream((string() + "data/dialogue1.bin").c_str(),ios::binary);
	if (!stream.is_open())
		return false;
	OpQ5_readObjects(stream,opt5_d379ec,0);
	stream.close();
	return true;
}

bool OpT5_DataLoader::unknown792890()
{
	gzifstream stream((string() + "data/dialogue5.bin").c_str(),ios::binary);
	if (!stream.is_open())
		return false;
	OpQ5_readObjects(stream,opt5_d25860,0);
	stream.close();
	return true;
}

bool OpT5_DataLoader::unknown7929d0()
{
	gzifstream stream((string() + "data/dialogue3.bin").c_str(),ios::binary);
	if (!stream.is_open())
		return false;
	OpQ5_readObjects(stream,opt5_d39458,0);
	stream.close();
	return true;
}

bool OpT5_DataLoader::unknown792b10()
{
	gzifstream stream((string() + "data/dialogue6.bin").c_str(),ios::binary);
	if (!stream.is_open())
		return false;
	OpQ5_readObjects(stream,opt5_d1d078,0);
	stream.close();
	return true;
}

bool OpT5_DataLoader::unknown792c50()
{
	gzifstream stream((string() + "data/dialogue4.bin").c_str(),ios::binary);
	if (!stream.is_open())
		return false;
	OpQ1_readStringVectorList(stream,&opt5_d21b10);
	OpQ1_readStringVector(stream,&opt5_cf45a0);
	OpQ1_readStringVector(stream,&opt5_cf08b4);
	stream.close();
	return true;
}

//==================================================================
// save file removal
//==================================================================

struct PhysfsDirectory	// NOTE: placeholder name
{
	string name;
	vector<string> files;
	vector<PhysfsDirectory*> subdirectories;
};

class XResourceMgr
{
public:
	void getFileTree(string dir, vector<PhysfsDirectory*> *directories, string ext);	// NOTE: placeholder name
};
extern XResourceMgr *opt5_resMgr;	// NOTE: placeholder name (0xcefa88)
extern string gameString_cfd42c;	// CUSTOM_FILE_PATH
struct OpQ5_U9d3d90;	// NOTE: placeholder name
template <class T> void OpQ5_eraseStep(vector<T> &v, int &index);	// NOTE: placeholder name

string opr1c_getSaveName_432af0(int version, bool manual);	// NOTE: placeholder name
string opr1c_getChronoSaveName_432d80();	// NOTE: placeholder name

struct OpT5_SaveFiles	// NOTE: placeholder name
{
	void unknown792dc0();	// 0x792dc0
	void unknown792e90(const string &prefix);	// 0x792e90
};

void OpT5_SaveFiles::unknown792dc0()
{
	remove(opr1c_getSaveName_432af0(0x5e,false).c_str());
	remove(opr1c_getChronoSaveName_432d80().c_str());
	unknown792e90("AUTO_");
}

void OpT5_SaveFiles::unknown792e90(const string &prefix)
{
	vector<PhysfsDirectory*> directories;
	opt5_resMgr->getFileTree(string() + "user/",&directories,"sav");
	for (unsigned int i = 0; i < directories[0]->files.size(); i++)
	{
		if (directories[0]->files[i].find(prefix,0) != string::npos)
		{
			remove((gameString_cfd42c + "user/" + directories[0]->files[i]).c_str());
			OpQ5_eraseStep((vector<OpQ5_U9d3d90>&)directories[0]->files,(int&)i);
		}
	}
}

//==================================================================
// startup loading thread
//==================================================================

void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)
extern OpT5_DataLoader *opt5_gm;	// NOTE: placeholder name (0xcefaa8)
extern int opt5_loadThreads;	// NOTE: placeholder name (0xcefca4)
void opt5_decrementLoadThreads();	// NOTE: placeholder name (0x790be0)

int opt5_loadThread(void *data)	// 0x790c00, NOTE: placeholder name
{
	if (!opt5_gm->unknown7917a0())
		logFatal("File error","Critical fail 2");
	if (!opt5_gm->unknown792510())
		logFatal("File error","Critical fail 3");
	opt5_decrementLoadThreads();
	return 0;
}

//==================================================================
// derelict name generation
//==================================================================

char opt5_randomChar(string &text);	// NOTE: placeholder name (0x4085b0)

string opt5_makeDerelictName()	// 0x790cf0, NOTE: placeholder name
{
	string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	string mixed = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string text;
	for (int i = 0; i < 5; i++)
		text += opt5_randomChar(letters);
	text.insert(text.begin() + 2,'-');
	text += "(";
	text += opt5_randomChar(mixed);
	text += ")";
	return "Unpacking derelicts " + text;
}

//==================================================================
// game manager color init
//==================================================================

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
	bool operator==(XColor color);
	bool operator!=(XColor color);
};

void opr1c_initColors_434910();	// NOTE: placeholder name (0x434910)
void opR1d_434ad0();	// NOTE: placeholder name
void opt5_433410();	// NOTE: placeholder name
void opr1c_initColors_433e60();	// NOTE: placeholder name
void opt5_433f60();	// NOTE: placeholder name
extern bool opt5_d28d26;	// NOTE: placeholder name
extern XColor *opt5_d35be0;	// NOTE: placeholder name
extern XColor opt5_cf0ee0[];	// NOTE: placeholder name

struct OpT5_Rec78f210	// NOTE: placeholder name
{
	char pad0[0x7c];
	XColor color7c;
	char pad7f[0x25];
	XColor colora4;
};

extern XColor *opt5_cfe674;	// NOTE: placeholder name
extern XColor opt5_d29804;	// NOTE: placeholder name
extern vector<OpT5_Rec78f210 *> opt5_cf67c0;	// NOTE: placeholder name

struct OpT5_GM	// NOTE: placeholder name
{
	void unknown78fa10();	// 0x78fa10
};

void opt5_replaceColors()	// 0x78f210, NOTE: placeholder name
{
	if (opt5_d29804 != *opt5_cfe674)
	{
		for (unsigned int i = 0; i < opt5_cf67c0.size(); i++)
		{
			if (opt5_cf67c0[i]->color7c == *opt5_cfe674)
				opt5_cf67c0[i]->color7c = opt5_d29804;
			if (opt5_cf67c0[i]->colora4 == *opt5_cfe674)
				opt5_cf67c0[i]->colora4 = opt5_d29804;
		}
	}
}

void OpT5_GM::unknown78fa10()
{
	opr1c_initColors_434910();
	opR1d_434ad0();
	opt5_433410();
	if (opt5_d28d26)
	{
		for (int i = 1; i < 6; i++)
			opt5_cf0ee0[i] = *opt5_d35be0;
	}
	opr1c_initColors_433e60();
	opt5_433f60();
}
