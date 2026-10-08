// team_c_50: GameMetaData::unserializeOldMetaBin (0x79ed10): reads the oldest meta format from user/meta.bin (string tags
//	from gameStrings_d389e0); unserialize() falls back to it and then rewrites progress.bin
// NOTE: member names are placeholders (f<offset>); declarations mirror team_c_25 (GameMetaData::serialize)
#include <string>
#include <vector>
#include <istream>
#include <fstream>
#include "../util/rng.h"
using namespace std;
#include "thirdparty/zfstream.h"

extern RNG rng;	// 0xd30908
template <class T> void readBinary(istream &stream, T *value);
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name
template <class T> void OpQ5_deleteObjectAndStep(vector<T*> &v, unsigned int &index);	// NOTE: placeholder name
template <class T> void OpQ5_eraseStep(vector<T> &v, unsigned int &index);	// NOTE: placeholder name
void OpQ1_readString(istream &in, string *text);	// 0x4096f0
void OpQ1_readStringVector(istream &in, vector<string> *list);	// 0x4097e0
void opr2_readText_436960(istream &stream, string *value);	// NOTE: placeholder name (0x436960)
void OpV4c_Fn9d3b80(istream &stream, char *data);	// NOTE: placeholder name
void OpT8a_readInts(istream &in, vector<int> &v);	// NOTE: placeholder name
int OpT8a_sumVector(vector<int> &v);
int OpT8a_findString(vector<string> &list, string s);	// NOTE: placeholder name
int OpT8a_findStringIndex(const string *list, unsigned int count, string s);
string opR1d_436bc0();	// NOTE: placeholder name
string intToString(int value);
void logMessage(string message);
void logWarning(string location, string message);	// NOTE: placeholder name (0x404e50)
void logError(string location, string message);
void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)
void resetCount_466840();
void resetCount_466930();
void resetCount_466a00();
extern "C" __declspec(dllimport) int crypto_sign_keypair(char *pk, char *sk);
extern "C" __declspec(dllimport) int remove(const char *path);

struct OpQ5_T9d3e30 { int id; };	// NOTE: placeholder layout
struct C48_RecFlag { bool test9b81b0() const; };	// NOTE: placeholder (0x9b81b0)
struct OpC_MapRec { char pad0[8]; string name8; char pad24[0x7c - 0x24]; C48_RecFlag f7c; };	// NOTE: placeholder name/layout
struct OpC_Named4 { int pad0; string name4; };	// NOTE: placeholder name/layout
struct OpC_Named1ac { char pad0[0x1ac]; string name1ac; };	// NOTE: placeholder name/layout
struct OpC_Owned { int pad0; bool active4; OpC_Named4 *owner8; OpC_Named4 *ownerc; int pad10; OpC_Named1ac *owner14; };	// NOTE: placeholder name/layout
extern vector<OpC_MapRec *> mapRecords_d2d1c4;	// NOTE: placeholder name
extern vector<OpC_Owned *> records_d02cb4;	// NOTE: placeholder name
extern vector<string> buffer_d33d28, buffer_d33d38, buffer_d33d48;	// NOTE: placeholder names
extern bool flag_cefacc, flag_cefacd;	// NOTE: placeholder names
extern string gameStrings_cf3b30[], gameStrings_d2d508[], gameStrings_d389e0[];	// global_string_arrays.cpp
extern string gameString_cfd42c;	// global_strings.cpp

class XResourceMgr { public: bool fileExists(string path); };	// NOTE: placeholder name (0x415590)
extern XResourceMgr *resourceMgr_cefa88;	// NOTE: placeholder name

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

	void reset();	// 0x467840
	void serialize();
	void unserialize();
	bool unserializeOldMetaBin();
	bool unserializeOld_79c7e0();	// NOTE: placeholder name
};

bool GameMetaData::unserializeOldMetaBin()
{
	gzifstream center((gameString_cfd42c + "user/" + "meta.bin").c_str(),ios::binary);
	if (!center.is_open())
	{
		logMessage("(" + (gameString_cfd42c + "user/" + "meta.bin") + " not found)");
		return false;
	}
	else
	{
		string col;
		while (true)
		{
			col.clear();
			OpQ1_readString(center,&col);
			int cols = OpT8a_findStringIndex(gameStrings_d389e0,36,col);
			switch (cols)
			{
				case 0:
				{
					f0.clear();
					opr2_readText_436960(center,&f0);
					logMessage(gameStrings_d389e0[cols] + ": " + f0);
					break;
				}
				case 1:
				{
					f1c.clear();
					opr2_readText_436960(center,&f1c);
					logMessage(gameStrings_d389e0[cols] + ": " + f1c);
					break;
				}
				case 2:
				{
					readBinary(center,&f38);
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(f38));
					break;
				}
				case 3:
				{
					opr2_readText_436960(center,&f3c);
					break;
				}
				case 4:
				{
					OpV4c_Fn9d3b80(center,f58);
					break;
				}
				case 5:
				{
					OpV4c_Fn9d3b80(center,f78);
					break;
				}
				case 6:
				{
					OpQ1_readString(center,&fb8);
					logMessage(gameStrings_d389e0[cols] + ": " + fb8);
					break;
				}
				case 7:
				{
					OpQ1_readString(center,&fd4);
					logMessage(gameStrings_d389e0[cols] + ": " + fd4);
					break;
				}
				case 8:
				{
					opr2_readText_436960(center,&ff4);
					logMessage(gameStrings_d389e0[cols] + ": " + "latest_news");
					break;
				}
				case 9:
				{
					readBinary(center,&f110);
					logMessage(gameStrings_d389e0[cols] + ": " + (f110 ? "1" : "0"));
					break;
				}
				case 10:
				{
					readBinary(center,&f114);
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(f114));
					break;
				}
				case 11:
				{
					readBinary(center,&f118);
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(f118));
					break;
				}
				case 12:
				{
					readBinary(center,&f11c);
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(f11c));
					break;
				}
				case 13:
				{
					readBinary(center,&f120);
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(f120));
					break;
				}
				case 14:
				{
					readBinary(center,&f124);
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(f124));
					break;
				}
				case 15:
				{
					f128.clear();
					OpT8a_readInts(center,f128);
					while (f128.size() < 10)
						f128.push_back(0);
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(OpT8a_sumVector(f128)));
					break;
				}
				case 16:
				{
					OpQ1_readString(center,&f138);
					logMessage(gameStrings_d389e0[cols] + ": " + f138);
					break;
				}
				case 17:
				{
					readBinary(center,&f154);
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(f154));
					break;
				}
				case 18:
				{
					int current;
					readBinary(center,&current);
					string distanceSq;
					int adj;
					for (int distances = 0; distances < current; distances++)
					{
						distanceSq.clear();
						OpQ1_readString(center,&distanceSq);
						readBinary(center,&adj);
						if (adj == 0)
							continue;
						if (distances < mapRecords_d2d1c4.size() && mapRecords_d2d1c4[distances]->name8 == distanceSq)
						{
							if (!mapRecords_d2d1c4[distances]->f7c.test9b81b0())
								f168[distances] = adj;
						}
						else
						{
							for (unsigned int enemies = 0; enemies < mapRecords_d2d1c4.size(); enemies++)
							{
								if (mapRecords_d2d1c4[enemies]->name8 == distanceSq)
								{
									if (!mapRecords_d2d1c4[enemies]->f7c.test9b81b0())
										f168[enemies] = adj;
									break;
								}
							}
						}
					}
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(current));
					break;
				}
				case 19:
				{
					OpQ1_readStringVector(center,&f178);
					int current;
					for (unsigned int distanceSq = 0; distanceSq < records_d02cb4.size(); distanceSq++)
					{
						current = OpT8a_findString(f178,records_d02cb4[distanceSq]->owner8 ? records_d02cb4[distanceSq]->owner8->name4 : (records_d02cb4[distanceSq]->ownerc ? records_d02cb4[distanceSq]->ownerc->name4 : records_d02cb4[distanceSq]->owner14->name1ac));
						if (current != -1)
							records_d02cb4[distanceSq]->active4 = true;
					}
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(f178.size()));
					break;
				}
				case 20:
				{
					OpQ5_readObjects(center,f188,0);
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(f188.size()));
					break;
				}
				case 21:
				{
					OpQ1_readStringVector(center,&f198);
					for (unsigned int current = 0; current < f198.size(); current++)
					{
						if (OpT8a_findStringIndex(gameStrings_d2d508,112,f198[current]) == -1)
							OpQ5_eraseStep(f198,current);
					}
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(f198.size()));
					break;
				}
				case 22:
				{
					readBinary(center,&f1a8);
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(f1a8));
					break;
				}
				case 23:
				{
					readBinary(center,&f1ac);
					logMessage(gameStrings_d389e0[cols] + ": " + (f1ac ? "1" : "0"));
					break;
				}
				case 24:
				{
					readBinary(center,&f1ad);
					logMessage(gameStrings_d389e0[cols] + ": " + (f1ad ? "1" : "0"));
					break;
				}
				case 25:
				{
					readBinary(center,&f1af);
					logMessage(gameStrings_d389e0[cols] + ": " + (f1af ? "1" : "0"));
					break;
				}
				case 26:
				{
					readBinary(center,&f1b0);
					logMessage(gameStrings_d389e0[cols] + ": " + (f1b0 ? "1" : "0"));
					break;
				}
				case 27:
				{
					readBinary(center,&f1b4);
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(f1b4));
					break;
				}
				case 28:
				{
					readBinary(center,&f1b8);
					logMessage(gameStrings_d389e0[cols] + ": " + intToString(f1b8));
					break;
				}
				case 29:
				{
					readBinary(center,&f1bd);
					logMessage(gameStrings_d389e0[cols] + ": " + (f1bd ? "1" : "0"));
					break;
				}
				case 30:
				{
					readBinary(center,&f1c0);
					logMessage(gameStrings_d389e0[cols] + ": " + (f1c0 ? "1" : "0"));
					break;
				}
				case 31:
				{
					readBinary(center,&f1c1);
					logMessage(gameStrings_d389e0[cols] + ": " + (f1c1 ? "1" : "0"));
					break;
				}
				case 32:
				{
					readBinary(center,&f1c2);
					logMessage(gameStrings_d389e0[cols] + ": " + (f1c2 ? "1" : "0"));
					break;
				}
				case 33:
				{
					readBinary(center,&f1c3);
					logMessage(gameStrings_d389e0[cols] + ": " + (f1c3 ? "1" : "0"));
					break;
				}
				case 34:
				{
					readBinary(center,&f1c4);
					logMessage(gameStrings_d389e0[cols] + ": " + (f1c4 ? "1" : "0"));
					break;
				}
				case 35:
					logMessage(gameStrings_d389e0[cols] + ": " + "end");
					goto done;
				default:
					logFatal("GameMetaData::unserializeOldMetaBin()","Unrecognized type: " + col);
			}
		}
done:
		center.close();
	}
	return true;
}
