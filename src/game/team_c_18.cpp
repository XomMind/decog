// team_c_18: GM::serialize (0x78c260): writes a save file (game state of every subsystem)
// NOTE: global names are placeholders unless noted
#include <string>
#include <vector>
#include <ostream>
#include "thirdparty/zfstream.h"
using namespace std;

extern "C" __declspec(dllimport) int __cdecl SDL_PeepEvents(void *events, int numevents, int action, unsigned int mask);

void logInfo(string location, string message);	// 0x405090
void logMessage(string message);	// 0x404cb0
string opr1c_getFatalSaveName_433100();	// 0x433100, NOTE: placeholder name
string opr1c_getManualSaveName_432f20(const string &name);	// 0x432f20, NOTE: placeholder name
string opr1c_getChronoSaveName_432d80();	// 0x432d80, NOTE: placeholder name
string opr1c_getSaveName_432af0(int version, bool error);	// 0x432af0, NOTE: placeholder name
void OpQ1_copyPhysFile(string source, string dest);	// NOTE: placeholder name
void OpQ1_writeString(ostream &out, string text);	// 0x409650
template <class T> void writeBinary(ostream &stream, T *value);
template <class T> void OpS8a_writeRawVector(ostream &stream, vector<T> &v);
template <class T> void OpQ5_writePointer(ostream &stream, T *&p);
template <class T> bool OpQ5_findByNameC(vector<T*> &v, const string &name, T *&result);	// NOTE: placeholder name (0x9d7530; const-ref twin of OpQ5_findByName)
int opC_readSaveHeader_77e2b0(gzifstream &stream, int a, int b);	// NOTE: placeholder name (0x77e2b0)

struct OpQ2_Stream;
struct OpQ2_Rec55e0c0 { void save(OpQ2_Stream *stream); };
struct OpQ2_Rec6744d0 { void save(OpQ2_Stream *stream); };
struct OpQ2_Rec69cbb0 { void save(OpQ2_Stream *stream); };
struct OpQ2_Rec6beb40 { void save(OpQ2_Stream *stream); };
struct OpC_Rec6919f0 { void save(ostream &stream); };	// NOTE: placeholder name (0x6919f0)
struct OpY9_Pool4 { void serialize(ostream &stream); };
struct OpY9_Pool5 { void serialize(ostream &stream); };
struct OpY9_Pool6 { void serialize(ostream &stream); };
struct OpY9_Pool7 { void serialize(ostream &stream); };
struct OpY9_Pool8 { void serialize(ostream &stream); };
struct OpY9_Pool9 { void serialize(ostream &stream); };
struct OpY9_Pool10 { void serialize(ostream &stream); };
class PlayerData { public: void serialize(ostream &stream); };
class OpR1h_Stats { public: void write472780(ostream &stream); };
class GameData { public: char pad0[0x28]; int unknown28; void serialize(ostream &stream); };
class GameMetaData { public: void serialize(); };
struct OpQ5_T9df610;	// NOTE: placeholder (map type)
class Map { public: int getTurn(); void unknown4646f0(); };
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
class TickStamp_427300 { public: void stamp(); };
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

extern string gameString_d21928;	// "Beta 17.1" (global_strings.cpp)
extern string gameString_cf33fc;	// "260906a" (global_strings.cpp)
extern const int saveVersion_b8f378;	// NOTE: placeholder name
extern string saveName_cf45f8;	// NOTE: placeholder name
extern vector<unsigned int> sessionTimes_cf4cd8;	// NOTE: placeholder name
extern TickStamp_427300 *tickStamp_cefa8c;	// NOTE: placeholder name
extern vector<int> mapIndices_cf4554;	// NOTE: placeholder name
extern vector<OpQ2_Rec55e0c0 *> mapRecords_d2d1c4;	// NOTE: placeholder name
extern OpY9_Pool9 pool9_d33888;	// NOTE: placeholder name
extern OpY9_Pool10 pool10_d2f288;	// NOTE: placeholder name
extern OpY9_Pool4 pool4_d208d4;	// NOTE: placeholder name
extern OpY9_Pool5 pool5_d21720;	// NOTE: placeholder name
extern OpY9_Pool7 pool7_d2a298;	// NOTE: placeholder name
extern OpY9_Pool6 pool6_d1e720;	// NOTE: placeholder name
extern OpY9_Pool8 pool8_cfac14;	// NOTE: placeholder name
extern GameData gameData_d1e860;	// NOTE: placeholder name
extern int savedDepth_cf4618;	// NOTE: placeholder name
extern int savedTurn_cf461c;	// NOTE: placeholder name
extern OpQ5_T9df610 *map_cefc4c;	// NOTE: placeholder name
extern PlayerData playerData_cf45d8;	// NOTE: placeholder name
extern OpR1h_Stats stats_d2c658;	// NOTE: placeholder name
extern OpQ2_Rec6744d0 rec_cf6428;	// NOTE: placeholder name
extern OpC_Rec6919f0 rec_cf6888;	// NOTE: placeholder name
extern OpQ2_Rec69cbb0 rec_d25450;	// NOTE: placeholder name
extern OpQ2_Rec6beb40 rec_d1dd38;	// NOTE: placeholder name
extern int gameMode_cf462c;	// NOTE: placeholder name
extern vector<OpQ5_U9d7530 *> factions_d25de0;	// NOTE: placeholder name
extern int int_caf2b8;	// NOTE: placeholder name
extern GameMetaData metaData_d25628;	// NOTE: placeholder name
extern OpQ1_Clock *clock_cefa9c;	// NOTE: placeholder name
extern CInterfaceMsg *interfaceMsg_cec0f4;	// NOTE: placeholder name
extern JLog *jlog_cefa64;	// NOTE: placeholder name

class GM	// NOTE: partial
{
public:
	unsigned int getSessionTimeTotal();
	void reset_470bb0();	// NOTE: placeholder name (folded with OpC_Struct470570::reset_470bb0)
	void serialize(bool quiet, bool showMessage, bool chrono, bool manual, bool fatal);
};

void GM::serialize(bool quiet, bool showMessage, bool chrono, bool manual, bool fatal)
{
	logInfo("GM::serialize()","Saving game");
	string fileName = fatal ? opr1c_getFatalSaveName_433100() : (manual ? opr1c_getManualSaveName_432f20(saveName_cf45f8) : (chrono ? opr1c_getChronoSaveName_432d80() : opr1c_getSaveName_432af0(0x5e,false)));
	gzofstream file(fileName.c_str(),ios::binary | ios::trunc);
	OpQ1_writeString(file,gameString_d21928);
	OpQ1_writeString(file,gameString_cf33fc);
	writeBinary(file,&saveVersion_b8f378);
	if (quiet || sessionTimes_cf4cd8.empty())
		sessionTimes_cf4cd8.push_back(getSessionTimeTotal());
	else
		sessionTimes_cf4cd8.back() += getSessionTimeTotal();
	reset_470bb0();
	tickStamp_cefa8c->stamp();
	OpS8a_writeRawVector(file,mapIndices_cf4554);
	for (unsigned int i = 0; i < mapIndices_cf4554.size(); i++)
		mapRecords_d2d1c4[mapIndices_cf4554[i]]->save((OpQ2_Stream *)&file);
	logMessage("MapLinks");
	pool9_d33888.serialize(file);
	logMessage("IntelData");
	pool10_d2f288.serialize(file);
	logMessage("Events");
	pool4_d208d4.serialize(file);
	logMessage("Entities");
	pool5_d21720.serialize(file);
	logMessage("Items");
	pool7_d2a298.serialize(file);
	logMessage("Props");
	pool6_d1e720.serialize(file);
	logMessage("Factions");
	pool8_cfac14.serialize(file);
	if (manual)
	{
		savedDepth_cf4618 = gameData_d1e860.unknown28;
		savedTurn_cf461c = ((Map *)map_cefc4c)->getTurn();
	}
	playerData_cf45d8.serialize(file);
	stats_d2c658.write472780(file);
	gameData_d1e860.serialize(file);
	rec_cf6428.save((OpQ2_Stream *)&file);
	rec_cf6888.save(file);
	rec_d25450.save((OpQ2_Stream *)&file);
	rec_d1dd38.save((OpQ2_Stream *)&file);
	OpQ5_writePointer(file,map_cefc4c);
	((Map *)map_cefc4c)->unknown4646f0();
	if (gameMode_cf462c == 11)
	{
		OpQ5_U9d7530 *cogmind;
		OpQ5_findByNameC(factions_d25de0,"Cogmind",cogmind);
		writeBinary(file,&cogmind->unknown9c);
		writeBinary(file,&cogmind->unknown98);
		writeBinary(file,&cogmind->unknown94);
		writeBinary(file,&cogmind->unknowna4);
		writeBinary(file,&cogmind->unknown78);
		writeBinary(file,&int_caf2b8);
	}
	file.close();
	logMessage("Saving game meta data");
	metaData_d25628.serialize();
	if (manual)
	{
		gzifstream test;
		bool exists = !opC_readSaveHeader_77e2b0(test,0,0);
		test.close();
		if (!exists)
		{
			logMessage("Copying to regular save file, since one doesn't yet exist");
			OpQ1_copyPhysFile(fileName,opr1c_getSaveName_432af0(0x5e,false));
		}
	}
	clock_cefa9c->start_416920();
	if (!quiet)
	{
		SDL_PeepEvents(0,9999,2,0x20);
		SDL_PeepEvents(0,9999,2,0x40);
	}
	if (showMessage)
		interfaceMsg_cec0f4->add(new OpS2_PhraseTextA(0xd4,0,0,0,HEntity(),HEntity()));
	jlog_cefa64->end(2);
}
