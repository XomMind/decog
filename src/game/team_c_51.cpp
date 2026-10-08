// team_c_51: BS::checkAutosaving (0x71d130): periodic/forced autosave, plus the rotating AUTO_ save copies (keeps the
//	newest N, deleting the oldest) and the map-count sanity flag
// NOTE: member/global names are placeholders; BS layout is partial
#include <string>
#include <vector>
using namespace std;

string intToString(int value);
int stringToInt(const string &s);
string &padLeft_408090(string &text, int width, char fill);	// NOTE: placeholder name
string opR1d_436e70(int unknown1, int unknown2, int unknown3);	// NOTE: placeholder name (date/time string)
void logError(string location, string message);
void OpQ1_copyPhysFile(string source, string dest);	// NOTE: placeholder name
string opr1c_getSaveName_432af0(int version, bool manual);	// NOTE: placeholder name
string opr1c_getManualSaveName_432f20(const string &name);	// 0x432f20, NOTE: placeholder name
template <class T> void OpQ5_eraseStep(vector<T> &v, unsigned int &index);	// NOTE: placeholder name
extern "C" __declspec(dllimport) void SDL_Delay(unsigned int ms);
extern "C" __declspec(dllimport) int remove(const char *path);

struct PhysfsDirectory
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
struct C51_GM { void serialize(bool a, bool b, bool c, bool d, bool e); };	// NOTE: placeholder (GM::serialize 0x78c260)
struct C51_Input { unsigned int getLastInputTime(); };	// NOTE: placeholder name (folded getter 0x48e040)
struct C51_Flags { bool isFlagActive(); bool unknown77e7c0(); };	// NOTE: placeholder (PlayerData at 0xcf45d8)
class C51_Handle { public: int ID; bool operator!=(C51_Handle other) const; };	// NOTE: placeholder (HEntity)
struct C51_MapRec;

extern int c51_cefb1c;	// NOTE: placeholder names below
extern unsigned int c51_cefb20, c51_caed20;
extern C51_GM *c51_cefaa8;
extern C51_Handle c51_d1e888, c51_d1e884;
extern int c51_cf462c, c51_cf4718, c51_cf4624, c51_d28de4, c51_d28de8, c51_caf2ac, c51_cefbb8;
extern bool c51_cefacd, c51_d28de3, c51_cefb18, c51_cf4620;
extern C51_Flags c51_cf45d8;
extern string c51_cf45f8;
extern C51_Input *c51_cefa8c;
extern XResourceMgr *c51_cefa88;
extern string gameString_cfd42c;	// global_strings.cpp
extern vector<C51_MapRec *> c51_d2d1c4;

class BS	// NOTE: placeholder layout (partial)
{
public:
	bool f0;
	unsigned int f4;

	void checkAutosaving(bool force);
};

void BS::checkAutosaving(bool force)
{
	if (c51_cefb1c != 0 && c51_caed20 >= c51_cefb20 + c51_cefb1c)
	{
		c51_cefb20 = c51_caed20;
		SDL_Delay(c51_cefb1c / 2);
		c51_cefaa8->serialize(false,true,false,false,false);
	}
	if (force)
	{
		c51_cefaa8->serialize(false,false,false,false,false);
		return;
	}
	if (!f0)
	{
		if (c51_d1e888 != c51_d1e884 || c51_cf462c == 6)
		{
			f0 = true;
			bool center = !c51_cefacd && !c51_cf45d8.isFlagActive() && c51_cf4718 != 0 && !c51_d28de3;
			if (c51_cefb18)
				center = true;
			bool col = false;
			if (center && c51_cf4624 >= 66)
			{
				if (c51_cf4620 || !c51_cf45d8.unknown77e7c0())
				{
					c51_cf4620 = true;
					c51_cefaa8->serialize(false,true,false,true,false);
					col = true;
				}
			}
			if (col)
				OpQ1_copyPhysFile(opr1c_getManualSaveName_432f20(c51_cf45f8),opr1c_getSaveName_432af0(94,false));
			else
				c51_cefaa8->serialize(false,true,false,false,false);
		}
	}
	if (c51_d28de4 != 0 && f0 && c51_caed20 - f4 > (unsigned int)(c51_d28de4 * 60000))
	{
		if (c51_caed20 - c51_cefa8c->getLastInputTime() >= 3000)
		{
			if (c51_d28de8 != 0)
			{
				vector<PhysfsDirectory *> center;
				c51_cefa88->getFileTree(string() + "user/",&center,"sav");
				for (unsigned int cols = 0; cols < center[0]->files.size(); cols++)
				{
					if (center[0]->files[cols].find("AUTO_",0) == string::npos)
						OpQ5_eraseStep(center[0]->files,cols);
				}
				int adj = -1;
				int behaviour = -1;
				int allies = 1;
				for (unsigned int cols = 0; cols < center[0]->files.size(); cols++)
				{
					unsigned int current = center[0]->files[cols].find("AUTO_",0) + 5;
					if (current == string::npos)
						continue;
					unsigned int distanceSq = center[0]->files[cols].find('-',current);
					if (distanceSq == string::npos)
						continue;
					int desc = stringToInt(string(center[0]->files[cols].begin() + current,center[0]->files[cols].begin() + distanceSq));
					if (adj == -1 || desc < adj)
					{
						adj = desc;
						behaviour = cols;
					}
					if (desc >= allies)
						allies = desc + 1;
				}
				if (c51_d28de8 != 0 && center[0]->files.size() >= (unsigned int)c51_d28de8)
				{
					if (behaviour == -1)
						logError("BS::checkAutosaving()","Unable to locate oldest relevant save");
					else
						remove((gameString_cfd42c + "user/" + center[0]->files[behaviour]).c_str());
				}
				string col = string() + "user/" + "save_v" + intToString(94) + ".sav";
				string clean = gameString_cfd42c + "user/" + "save_v" + intToString(94) + "(" + "AUTO_" + padLeft_408090(intToString(allies),4,'0') + "-" + opR1d_436e70(0,0,0) + ").sav";
				OpQ1_copyPhysFile(col,clean);
			}
			c51_cefaa8->serialize(false,false,false,false,false);
		}
	}
	if (c51_caf2ac != 32 && c51_caed20 >= 450000)
	{
		if (c51_caf2ac - 64 != c51_d2d1c4.size())
			c51_cefbb8 = 1;
		c51_caf2ac = 32;
	}
}
