// team_c_25: GameMetaData::serialize (0x46adc0): writes user/progress.bin (tagged fields) and the three text buffers
// NOTE: placed in src/util so it links after every other TU (under /LTCG an earlier position changes EH-state inference in op_w6)
// NOTE: member names are placeholders (f<offset>); globals carry the exe address
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
void OpV4c_Fn9d3de0(ostream &stream, const char *text, unsigned int length);
struct OpC_IntBox { int v; void write(ostream &stream); void read(istream &stream); };
struct OpU1_Point { int x; int y; void write(ostream &stream); void read(istream &stream); };
struct OpC_PointPair { OpU1_Point a; OpU1_Point b; void write(ostream &stream); void read(istream &stream); };	// NOTE: placeholder name (folded with Calls_40b420/40b450::delegate)
template <class T> class OpS8a_Array2D { public: int width; int height; T *cells; void write(ostream &stream); void writeRaw(ostream &stream); void read(istream &stream); };
struct TeamB_6722d0 { char pad[0x10]; void serialize(ostream &stream); };	// NOTE: placeholder layout
struct OpR2_Rec511f40 { void serialize(ostream &stream); };	// NOTE: placeholder layout
struct OpS8a_G20; struct OpS8a_G34;
template <class T> class OpS8a_Grid { public: int width; int height; T *cells; void write(ostream &stream); };
struct OpQ5_T9d3e30;
struct OpC_MapRec { char pad0[8]; string name8; };	// NOTE: placeholder name/layout
struct OpC_Named4 { int pad0; string name4; };	// NOTE: placeholder name/layout
struct OpC_Named1ac { char pad0[0x1ac]; string name1ac; };	// NOTE: placeholder name/layout
struct OpC_Owned { int pad0; bool active4; OpC_Named4 *owner8; OpC_Named4 *ownerc; int pad10; OpC_Named1ac *owner14; };	// NOTE: placeholder name/layout
extern vector<OpC_MapRec *> mapRecords_d2d1c4;	// NOTE: placeholder name
extern vector<OpC_Owned *> records_d02cb4;	// NOTE: placeholder name
extern vector<string> buffer_d33d28, buffer_d33d38, buffer_d33d48;	// NOTE: placeholder names
extern bool flag_cefacc, flag_cefacd;	// NOTE: placeholder names
extern const char newline_c18c78[];	// NOTE: placeholder name ("\n" literal pooled in the exe)
extern string gameStrings_cf3b30[];	// global_string_arrays.cpp
extern string gameString_cfd42c;	// global_strings.cpp
extern string gameString_d21928;
extern string gameString_cf33fc;
void logError(string location, string message);
template <class T> void OpQ5_eraseRange(vector<T> &v, int first, int last);
struct OpQ5_U9d3e90;
void resetCount_466840();
void resetCount_466930();
void resetCount_466a00();
#include "thirdparty/zfstream.h"
#include <fstream>
extern int g_bbbe40;	// NOTE: placeholder name
extern int g_bbbe44;	// NOTE: placeholder name
extern int g_bbbe48;	// NOTE: placeholder name
extern int g_bbbe4c;	// NOTE: placeholder name
extern int g_bbbe50;	// NOTE: placeholder name
extern int g_bbbe54;	// NOTE: placeholder name
extern int g_bbbe58;	// NOTE: placeholder name
extern int g_bbbe5c;	// NOTE: placeholder name
extern int g_bbbe60;	// NOTE: placeholder name
extern int g_bbbe64;	// NOTE: placeholder name
extern int g_bbbe68;	// NOTE: placeholder name
extern int g_bbbe6c;	// NOTE: placeholder name
extern int g_bbbe70;	// NOTE: placeholder name
extern int g_bbbe74;	// NOTE: placeholder name
extern int g_bbbe78;	// NOTE: placeholder name
extern int g_bbbe7c;	// NOTE: placeholder name
extern int g_bbbe80;	// NOTE: placeholder name
extern int g_bbbe84;	// NOTE: placeholder name
extern int g_bbbe88;	// NOTE: placeholder name
extern int g_bbbe8c;	// NOTE: placeholder name
extern int g_bbbe90;	// NOTE: placeholder name
extern int g_bbbe94;	// NOTE: placeholder name
extern int g_bbbe98;	// NOTE: placeholder name
extern int g_bbbe9c;	// NOTE: placeholder name
extern int g_bbbea0;	// NOTE: placeholder name
extern int g_bbbea4;	// NOTE: placeholder name
extern int g_bbbea8;	// NOTE: placeholder name
extern int g_bbbeac;	// NOTE: placeholder name
extern int g_bbbeb0;	// NOTE: placeholder name
extern int g_bbbeb4;	// NOTE: placeholder name
extern int g_bbbeb8;	// NOTE: placeholder name
extern int g_bbbebc;	// NOTE: placeholder name
extern int g_bbbec0;	// NOTE: placeholder name
extern int g_bbbec4;	// NOTE: placeholder name
extern int g_bbbec8;	// NOTE: placeholder name
extern int g_bbbecc;	// NOTE: placeholder name
extern int g_bbbed0;	// NOTE: placeholder name
extern int g_bbbed4;	// NOTE: placeholder name
extern int g_bbbed8;	// NOTE: placeholder name
extern int g_bbbedc;	// NOTE: placeholder name
extern int g_bbbee0;	// NOTE: placeholder name

class GameMetaData	// NOTE: placeholder layout
{
public:
	string f0;
	string f1c;
	int f38;
	string f3c;
	char f58[0x20];
	char f78[0x40];
	string fb8;
	string fd4;
	char padf0[0x4];
	string ff4;
	bool f110;
	int f114;
	int f118;
	int f11c;
	int f120;
	int f124;
	vector<int> f128;
	string f138;
	int f154;
	vector<string> f158;
	vector<int> f168;
	vector<string> f178;
	vector<OpQ5_T9d3e30 *> f188;
	vector<string> f198;
	int f1a8;
	bool f1ac;
	bool f1ad;
	bool f1ae;
	bool f1af;
	bool f1b0;
	int f1b4;
	int f1b8;
	bool f1bc;
	bool f1bd;
	bool f1be;
	bool f1bf;
	bool f1c0;
	bool f1c1;
	bool f1c2;
	bool f1c3;
	bool f1c4;

	void serialize();
};

void GameMetaData::serialize()
{
	gzofstream stream((gameString_cfd42c + "user/" + "progress.bin").c_str(),ios::binary | ios::trunc);
	if (!stream.is_open())
		logError("GameMetaData::serialize()","Unable to open/create " + (gameString_cfd42c + "user/" + "progress.bin"));
	else
	{
		f0 = gameString_d21928;
		OpQ1_writeString(stream,gameStrings_cf3b30[0]);
		writeBinary(stream,&g_bbbe40);
		writeStringRef_409740(stream,f0);
		f1c = gameString_cf33fc;
		OpQ1_writeString(stream,gameStrings_cf3b30[1]);
		writeBinary(stream,&g_bbbe44);
		writeStringRef_409740(stream,f1c);
		OpQ1_writeString(stream,gameStrings_cf3b30[2]);
		writeBinary(stream,&g_bbbe48);
		writeBinary(stream,&f38);
		OpQ1_writeString(stream,gameStrings_cf3b30[3]);
		writeBinary(stream,&g_bbbe4c);
		writeStringRef_409740(stream,f3c);
		OpQ1_writeString(stream,gameStrings_cf3b30[4]);
		writeBinary(stream,&g_bbbe50);
		OpV4c_Fn9d3de0(stream,f58,32);
		OpQ1_writeString(stream,gameStrings_cf3b30[5]);
		writeBinary(stream,&g_bbbe54);
		OpV4c_Fn9d3de0(stream,f78,64);
		OpQ1_writeString(stream,gameStrings_cf3b30[6]);
		writeBinary(stream,&g_bbbe58);
		writeStringRef_409740(stream,fb8);
		OpQ1_writeString(stream,gameStrings_cf3b30[7]);
		writeBinary(stream,&g_bbbe5c);
		writeStringRef_409740(stream,fd4);
		OpQ1_writeString(stream,gameStrings_cf3b30[8]);
		writeBinary(stream,&g_bbbe60);
		writeStringRef_409740(stream,ff4);
		OpQ1_writeString(stream,gameStrings_cf3b30[9]);
		writeBinary(stream,&g_bbbe64);
		writeBinary(stream,&f110);
		OpQ1_writeString(stream,gameStrings_cf3b30[10]);
		writeBinary(stream,&g_bbbe68);
		writeBinary(stream,&f114);
		OpQ1_writeString(stream,gameStrings_cf3b30[11]);
		writeBinary(stream,&g_bbbe6c);
		writeBinary(stream,&f118);
		OpQ1_writeString(stream,gameStrings_cf3b30[12]);
		writeBinary(stream,&g_bbbe70);
		writeBinary(stream,&f11c);
		OpQ1_writeString(stream,gameStrings_cf3b30[13]);
		writeBinary(stream,&g_bbbe74);
		writeBinary(stream,&f120);
		OpQ1_writeString(stream,gameStrings_cf3b30[14]);
		writeBinary(stream,&g_bbbe78);
		writeBinary(stream,&f124);
		OpQ1_writeString(stream,gameStrings_cf3b30[15]);
		writeBinary(stream,&g_bbbe7c);
		OpS8a_writeRawVector(stream,f128);
		OpQ1_writeString(stream,gameStrings_cf3b30[16]);
		writeBinary(stream,&g_bbbe80);
		writeStringRef_409740(stream,f138);
		OpQ1_writeString(stream,gameStrings_cf3b30[17]);
		writeBinary(stream,&g_bbbe84);
		writeBinary(stream,&f154);
		OpQ1_writeString(stream,gameStrings_cf3b30[18]);
		writeBinary(stream,&g_bbbe88);
		OpQ1_writeStringVector(stream,&f158);
		OpQ1_writeString(stream,gameStrings_cf3b30[19]);
		writeBinary(stream,&g_bbbe8c);
		int numMaps = mapRecords_d2d1c4.size();
		writeBinary(stream,&numMaps);
		for (int i = 0; i < numMaps; i++)
		{
			OpQ1_writeString(stream,mapRecords_d2d1c4[i]->name8);
			writeBinary(stream,&f168[i]);
		}
		OpQ1_writeString(stream,gameStrings_cf3b30[20]);
		writeBinary(stream,&g_bbbe90);
		f178.clear();
		for (unsigned int j = 0; j < records_d02cb4.size(); j++)
		{
			if (records_d02cb4[j]->active4)
				f178.push_back(records_d02cb4[j]->owner8 ? records_d02cb4[j]->owner8->name4 : (records_d02cb4[j]->ownerc ? records_d02cb4[j]->ownerc->name4 : records_d02cb4[j]->owner14->name1ac));
		}
		OpQ1_writeStringVector(stream,&f178);
		OpQ1_writeString(stream,gameStrings_cf3b30[21]);
		writeBinary(stream,&g_bbbe94);
		OpQ5_writeObjects(stream,f188);
		OpQ1_writeString(stream,gameStrings_cf3b30[22]);
		writeBinary(stream,&g_bbbe98);
		OpQ1_writeStringVector(stream,&f198);
		OpQ1_writeString(stream,gameStrings_cf3b30[23]);
		writeBinary(stream,&g_bbbe9c);
		writeBinary(stream,&f1a8);
		OpQ1_writeString(stream,gameStrings_cf3b30[24]);
		writeBinary(stream,&g_bbbea0);
		writeBinary(stream,&f1ac);
		OpQ1_writeString(stream,gameStrings_cf3b30[25]);
		writeBinary(stream,&g_bbbea4);
		writeBinary(stream,&f1ad);
		OpQ1_writeString(stream,gameStrings_cf3b30[26]);
		writeBinary(stream,&g_bbbea8);
		writeBinary(stream,&f1ae);
		OpQ1_writeString(stream,gameStrings_cf3b30[27]);
		writeBinary(stream,&g_bbbeac);
		writeBinary(stream,&f1af);
		OpQ1_writeString(stream,gameStrings_cf3b30[28]);
		writeBinary(stream,&g_bbbeb0);
		writeBinary(stream,&f1b0);
		OpQ1_writeString(stream,gameStrings_cf3b30[29]);
		writeBinary(stream,&g_bbbeb4);
		writeBinary(stream,&f1b4);
		OpQ1_writeString(stream,gameStrings_cf3b30[30]);
		writeBinary(stream,&g_bbbeb8);
		writeBinary(stream,&f1b8);
		OpQ1_writeString(stream,gameStrings_cf3b30[31]);
		writeBinary(stream,&g_bbbebc);
		writeBinary(stream,&f1bc);
		OpQ1_writeString(stream,gameStrings_cf3b30[32]);
		writeBinary(stream,&g_bbbec0);
		writeBinary(stream,&f1bd);
		OpQ1_writeString(stream,gameStrings_cf3b30[33]);
		writeBinary(stream,&g_bbbec4);
		writeBinary(stream,&f1be);
		OpQ1_writeString(stream,gameStrings_cf3b30[34]);
		writeBinary(stream,&g_bbbec8);
		writeBinary(stream,&f1bf);
		OpQ1_writeString(stream,gameStrings_cf3b30[35]);
		writeBinary(stream,&g_bbbecc);
		writeBinary(stream,&f1c0);
		OpQ1_writeString(stream,gameStrings_cf3b30[36]);
		writeBinary(stream,&g_bbbed0);
		writeBinary(stream,&f1c1);
		OpQ1_writeString(stream,gameStrings_cf3b30[37]);
		writeBinary(stream,&g_bbbed4);
		writeBinary(stream,&f1c2);
		OpQ1_writeString(stream,gameStrings_cf3b30[38]);
		writeBinary(stream,&g_bbbed8);
		writeBinary(stream,&f1c3);
		OpQ1_writeString(stream,gameStrings_cf3b30[39]);
		writeBinary(stream,&g_bbbedc);
		writeBinary(stream,&f1c4);
		OpQ1_writeString(stream,gameStrings_cf3b30[40]);
		writeBinary(stream,&g_bbbee0);
		stream.close();
	}
	ofstream out((gameString_cfd42c + "user/" + "buffer.txt").c_str(),ios::out,0x40);
	if (!out.is_open())
		logError("GameMetaData::serialize()","Unable to open/create " + (gameString_cfd42c + "user/" + "buffer.txt"));
	else
	{
		if (buffer_d33d28.size() > 200)
		{
			OpQ5_eraseRange((vector<OpQ5_U9d3e90> &)buffer_d33d28,0,buffer_d33d28.size() - 200);
			resetCount_466840();
		}
		for (unsigned int k = 0; k < buffer_d33d28.size(); k++)
			out << buffer_d33d28[k] << newline_c18c78;
		out.close();
	}
	out.open((gameString_cfd42c + "user/" + "buffer_robot.txt").c_str(),ios::out,0x40);
	if (!out.is_open())
		logError("GameMetaData::serialize()","Unable to open/create " + (gameString_cfd42c + "user/" + "buffer_robot.txt"));
	else
	{
		if (buffer_d33d38.size() > 200)
		{
			OpQ5_eraseRange((vector<OpQ5_U9d3e90> &)buffer_d33d38,0,buffer_d33d38.size() - 200);
			resetCount_466930();
		}
		for (unsigned int k = 0; k < buffer_d33d38.size(); k++)
			out << buffer_d33d38[k] << newline_c18c78;
		out.close();
	}
	if (flag_cefacd || flag_cefacc)
	{
		out.open((gameString_cfd42c + "user/" + "buffer_debug.txt").c_str(),ios::out,0x40);
		if (!out.is_open())
			logError("GameMetaData::serialize()","Unable to open/create " + (gameString_cfd42c + "user/" + "buffer_debug.txt"));
		else
		{
			if (buffer_d33d48.size() > 200)
			{
				OpQ5_eraseRange((vector<OpQ5_U9d3e90> &)buffer_d33d48,0,buffer_d33d48.size() - 200);
				resetCount_466a00();
			}
			for (unsigned int k = 0; k < buffer_d33d48.size(); k++)
				out << buffer_d33d48[k] << newline_c18c78;
			out.close();
		}
	}
}
