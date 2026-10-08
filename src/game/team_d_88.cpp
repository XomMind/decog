// team_d_88: GM::unserialize (0x78cc50): loads a save file (inverse of team_c_18's GM::serialize).
// NOTE: global names are placeholders unless noted; layouts are partial.
#include <string>
#include <vector>
#include <istream>
#include <stdio.h>
#include "thirdparty/zfstream.h"
using namespace std;

void logInfo(string location, string message);	// 0x405090
void logMessage(string message);	// 0x404cb0
void logNotice(string message);	// NOTE: placeholder signature (single-argument overload)
void logError(string location, string message);
string opr1c_getManualSaveName_432f20(const string &name);	// 0x432f20, NOTE: placeholder name
string opr1c_getSaveName_432af0(int version, bool error);	// 0x432af0, NOTE: placeholder name
void OpQ1_copyPhysFile(string source, string dest);	// NOTE: placeholder name
int opr4a_unknown77e2b0(gzifstream &stream, bool a, bool b);	// NOTE: placeholder name (save header check)
void OpT8a_readInts(istream &stream, vector<int> &v);
template <class T> void readBinary(istream &stream, T *value);
template <class T> void OpQ5_readPointer(istream &stream, T *&p);	// NOTE: placeholder name
template <class T> bool OpQ5_findByName(vector<T*> &v, const string &name, T *&result);	// NOTE: placeholder name; const string& here (the exe instantiation takes string&)
void OpU5s4_recreateCBD_7ad350();

struct OpQ2_Rec55e530 { void load(istream &stream); };	// NOTE: placeholder name (map record)
struct OpY9_Pool4 { void unserialize(istream &stream); };
struct OpY9_Pool5 { void unserialize(istream &stream); };
struct OpY9_Pool6 { void unserialize(istream &stream); };
struct OpY9_Pool7 { void unserialize(istream &stream); };
struct OpY9_Pool8 { void unserialize(istream &stream); };
struct OpY9_Pool9 { void unserialize(istream &stream); };
struct OpY9_Pool10 { void unserialize(istream &stream); };
class PlayerData { public: void read(istream &stream); };
class OpR1h_Stats { public: void load472830(istream &stream); };
class GameData { public: void unserialize(istream &stream); };
struct OpU3_Rec673e70 { void load(istream &stream); };	// NOTE: placeholder name
struct Unknown_45f320_45f560 { void unserialize(istream &stream); };	// NOTE: placeholder name (team_d_04.cpp)
struct OpQ2_Rec69cbb0 { void load(istream &stream); };	// NOTE: placeholder name
struct OpQ2_Rec6be9d0 { void load(istream &stream); };	// NOTE: placeholder name
struct OpQ5_T9df650	// NOTE: placeholder (map type)
{
	void setFlag(bool flag);	// NOTE: placeholder name (folded with a _Vector_const_iterator::_Compat)
};
struct OpQ5_U9d7530	// NOTE: placeholder layout (faction record)
{
	char pad0[0x78];
	int unknown78;
	char pad7c[0x94 - 0x7c];
	int unknown94;
	int unknown98;
	int unknown9c;
	char pada0[0xa4 - 0xa0];
	int unknowna4;
};
class LuigiAi	// NOTE: placeholder layout
{
public:
	char	pad00[0x1c];
	int		unknown1c;

	void cleanup();
	void initialize();
	void unknown777bc0();	// NOTE: placeholder name
};
class OpQ1_Clock { public: void start_416920(); };
class JLog { public: int end(int type); };
class HEntity { int ID; public: HEntity(); };
class OpW9_InterfaceMessage { public: char pad[4]; };
class OpS2_PhraseTextA : public OpW9_InterfaceMessage	// NOTE: placeholder layout (0x20 bytes)
{
public:
	char pad4[0x1c];
	OpS2_PhraseTextA(int id, string *a, string *b, string *c, HEntity e1, HEntity e2);
};
class CInterfaceMsg { public: void add(OpW9_InterfaceMessage *message); };

extern string saveName88_cf45f8;	// NOTE: placeholder name
extern vector<int> mapIndices88_cf4554;	// NOTE: placeholder name
extern vector<OpQ2_Rec55e530 *> mapRecords88_d2d1c4;	// NOTE: placeholder name
extern vector<string> missing88_cf25c8;	// NOTE: placeholder name
extern OpY9_Pool9 pool988_d33888;	// NOTE: placeholder name
extern OpY9_Pool10 pool1088_d2f288;	// NOTE: placeholder name
extern OpY9_Pool4 pool488_d208d4;	// NOTE: placeholder name
extern OpY9_Pool5 pool588_d21720;	// NOTE: placeholder name
extern OpY9_Pool7 pool788_d2a298;	// NOTE: placeholder name
extern OpY9_Pool6 pool688_d1e720;	// NOTE: placeholder name
extern OpY9_Pool8 pool888_cfac14;	// NOTE: placeholder name
extern PlayerData playerData88_cf45d8;	// NOTE: placeholder name
extern OpR1h_Stats stats88_d2c658;	// NOTE: placeholder name
extern GameData gameData88_d1e860;	// NOTE: placeholder name
extern OpU3_Rec673e70 rec88_cf6428;	// NOTE: placeholder name
extern Unknown_45f320_45f560 rec88_cf6888;	// NOTE: placeholder name
extern OpQ2_Rec69cbb0 rec88_d25450;	// NOTE: placeholder name
extern OpQ2_Rec6be9d0 rec88_d1dd38;	// NOTE: placeholder name
extern OpQ5_T9df650 *map88_cefc4c;	// NOTE: placeholder name
extern bool flag88_cefb3e;	// NOTE: placeholder name
extern bool flag88_cefb36;	// NOTE: placeholder name
extern LuigiAi luigi88_cebffc;	// NOTE: placeholder name
extern int gameMode88_cf462c;	// NOTE: placeholder name
extern vector<OpQ5_U9d7530 *> factions88_d25de0;	// NOTE: placeholder name
extern int int88_caf2b8;	// NOTE: placeholder name
extern OpQ1_Clock *clock88_cefa9c;	// NOTE: placeholder name
extern CInterfaceMsg *interfaceMsg88_cec0f4;	// NOTE: placeholder name
extern JLog *jlog88_cefa64;	// NOTE: placeholder name

class GM	// NOTE: partial
{
public:
	bool unserialize(bool a, bool manual);	// NOTE: placeholder parameter names
};

bool GM::unserialize(bool a, bool manual)
{
	logInfo("GM::unserialize()","Loading saved game");
	gzifstream file;
	if (opr4a_unknown77e2b0(file,a,manual))
	{
		logError("GM::unserialize()","Load failed: No matching file found, or saved data is from incompatible version");
		jlog88_cefa64->end(2);
		file.close();
		return false;
	}
	mapIndices88_cf4554.clear();
	OpT8a_readInts(file,mapIndices88_cf4554);
	for (unsigned int i = 0; i < mapIndices88_cf4554.size(); i++)
		mapRecords88_d2d1c4[mapIndices88_cf4554[i]]->load(file);
	missing88_cf25c8.clear();
	logMessage("MapLinks");
	pool988_d33888.unserialize(file);
	logMessage("IntelData");
	pool1088_d2f288.unserialize(file);
	logMessage("Events");
	pool488_d208d4.unserialize(file);
	logMessage("Entities");
	pool588_d21720.unserialize(file);
	logMessage("Items");
	pool788_d2a298.unserialize(file);
	logMessage("Props");
	pool688_d1e720.unserialize(file);
	logMessage("Factions");
	pool888_cfac14.unserialize(file);
	if (!missing88_cf25c8.empty())
	{
		for (unsigned int j = 0; j < missing88_cf25c8.size(); j++)
			logNotice("Data missing for object \"" + missing88_cf25c8[j] + "\"");
		logError("GM::unserialize()","Load failed: Data missing");
		jlog88_cefa64->end(2);
		file.close();
		rename(opr1c_getSaveName_432af0(0x5e,false).c_str(),opr1c_getSaveName_432af0(0x5e,true).c_str());
		return false;
	}
	playerData88_cf45d8.read(file);
	stats88_d2c658.load472830(file);
	gameData88_d1e860.unserialize(file);
	rec88_cf6428.load(file);
	rec88_cf6888.unserialize(file);
	rec88_d25450.load(file);
	rec88_d1dd38.load(file);
	OpQ5_readPointer(file,map88_cefc4c);
	if (flag88_cefb3e)
	{
		if (luigi88_cebffc.unknown1c)
			luigi88_cebffc.cleanup();
		luigi88_cebffc.initialize();
		luigi88_cebffc.unknown777bc0();
		map88_cefc4c->setFlag(true);
	}
	if (flag88_cefb36)
		OpU5s4_recreateCBD_7ad350();
	if (gameMode88_cf462c == 11)
	{
		OpQ5_U9d7530 *cogmind;
		OpQ5_findByName(factions88_d25de0,"Cogmind",cogmind);
		readBinary(file,&cogmind->unknown9c);
		readBinary(file,&cogmind->unknown98);
		readBinary(file,&cogmind->unknown94);
		readBinary(file,&cogmind->unknowna4);
		readBinary(file,&cogmind->unknown78);
		readBinary(file,&int88_caf2b8);
	}
	file.close();
	clock88_cefa9c->start_416920();
	interfaceMsg88_cec0f4->add(new OpS2_PhraseTextA(0xd6,0,0,0,HEntity(),HEntity()));
	if (manual)
	{
		gzifstream test;
		bool state = !opr4a_unknown77e2b0(test,false,true);
		test.close();
		if (state)
		{
			logMessage("Copying to regular save file");
			OpQ1_copyPhysFile(opr1c_getManualSaveName_432f20(saveName88_cf45f8),opr1c_getSaveName_432af0(0x5e,false));
		}
	}
	jlog88_cefa64->end(2);
	return true;
}
