// team_c_43: Scorekeeper score history append (0x47f2e0, "Scorekeeper::totalScore()"): appends one summary line for
//	this run to user/scorehistory.txt (writing the header first when the file is new)
// NOTE: helper classes and globals are private placeholders; Scorekeeper layout is partial
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string intToString(int value);
string &padRight_4080d0(string &text, int width, char fill);	// NOTE: placeholder name
string opR1d_436e70(int unknown1, int unknown2, int unknown3);	// NOTE: placeholder name (date/time string)
void logError(string location, string message);
extern string g_cfd42c;	// NOTE: placeholder name (gameString_cfd42c)
extern string gameStrings_cfd308[], gameStrings_cfe140[], gameStrings_d297b0[], gameStrings_d22b68[];	// global_string_arrays.cpp

struct C43_PlayerData { bool getField(); };	// NOTE: placeholder (PlayerData)
struct C43_Meta { int getLoreCollectionPercent(); int getGalleryCollectionPercent(); int percent(); };	// NOTE: placeholder (GameMetaData)
struct C43_Loc { int f0; int f4; int f8; };	// NOTE: placeholder
class C43_HLoc { public: int ID; C43_Loc *operator->() const; };	// NOTE: placeholder
extern C43_PlayerData c43_cf45d8;	// NOTE: placeholder names
extern int c43_cf462c, c43_cf4b38, c43_cf4718, c43_cf471c[];
extern C43_HLoc c43_d1e888;
extern vector<C43_HLoc> c43_d1e88c;
extern C43_Meta c43_d25628;
extern string c43_d1e864;

class Scorekeeper	// NOTE: placeholder layout (partial)
{
public:
	vector<int> *values;
	char pad4[0x3c - 4];
	string f3c;
	char pad58[0x110 - 0x58];
	int f110;
	char pad114[0x158 - 0x114];
	vector<int> f158;

	int delegate(int index);	// NOTE: placeholder name
	void totalScore_47f2e0();
};

void Scorekeeper::totalScore_47f2e0()
{
	if (!c43_cf45d8.getField() && c43_cf462c == 0)
	{
		ofstream center;
		bool adj = false;
		ifstream a((g_cfd42c + "user/" + "scorehistory.txt").c_str());
		if (!a.is_open())
		{
			center.open((g_cfd42c + "user/" + "scorehistory.txt").c_str(),ios::out);
			adj = true;
		}
		else
		{
			a.close();
			center.open((g_cfd42c + "user/" + "scorehistory.txt").c_str(),ios::out | ios::app);
		}
		if (center.is_open())
		{
			if (adj)
			{
				center << "\n";
				center << "Cogmind Score History\n";
				center << "\n";
				center << "                                    Slots------  Carried  Security Level %         Composite %--------\n";
				center << "Version   Date    Score   Location  P  P  U  W   Max Avg  L  1  2  3  4  5   Maps  Lore Gallery Achiev  Mode  Seed\n";
				center << "--------  ------  ------  --------  -- -- -- --  --- ---  -- -- -- -- -- --  ----  ---- ------- ------  ----  ----\n";
			}
			string col;
			col = f3c;
			padRight_4080d0(col,10,32);
			center << col;
			col = opR1d_436e70(1,0,0) + "  ";
			center << col;
			col = intToString(f110);
			padRight_4080d0(col,8,32);
			center << col;
			if (c43_cf4b38 <= 9)
				col = gameStrings_cfd308[c43_cf4b38];
			else
				col = "-" + intToString(c43_d1e888->f8) + "/" + gameStrings_cfe140[c43_d1e888->f4];
			padRight_4080d0(col,10,32);
			center << col;
			for (int cols = 0; cols < 4; cols++)
			{
				col = intToString(f158[cols]);
				padRight_4080d0(col,3,32);
				center << col;
			}
			center << " ";
			col = intToString(delegate(199));
			padRight_4080d0(col,4,32);
			center << col;
			col = intToString(delegate(200));
			padRight_4080d0(col,5,32);
			center << col;
			for (int cols = 525; cols <= 530; cols++)
			{
				col = (*values)[cols] == 100 ? string("**") : ((*values)[cols] == 0 ? string("-") : intToString((*values)[cols]));
				padRight_4080d0(col,3,32);
				center << col;
			}
			center << " ";
			col = intToString(c43_d1e88c.size());
			padRight_4080d0(col,6,32);
			center << col;
			col = intToString(c43_d25628.getLoreCollectionPercent());
			padRight_4080d0(col,5,32);
			center << col;
			col = intToString(c43_d25628.getGalleryCollectionPercent());
			padRight_4080d0(col,8,32);
			center << col;
			col = intToString(c43_d25628.percent());
			padRight_4080d0(col,8,32);
			center << col;
			col = gameStrings_d297b0[c43_cf4718];
			padRight_4080d0(col,6,32);
			center << col;
			col = c43_d1e864;
			center << col;
			for (int cols = 0; cols < 12; cols++)
			{
				if (c43_cf471c[cols] != 0)
					center << " +" << gameStrings_d22b68[cols];
			}
			center << "\n";
			center.close();
		}
		else
			logError("Scorekeeper::totalScore()","Unable to open file to append score summary: " + (g_cfd42c + "user/" + "scorehistory.txt"));
	}
}
