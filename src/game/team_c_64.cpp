// team_c_64: machine terminal list menus (0x8f9ee0): builds the SCHEMATICS/REPAIR/RECYCLE/SCAN/STUDY option lists
//	for a terminal command type and opens them in a CList
// NOTE: names are placeholders; layouts are partial
#include <string>
#include <vector>
using namespace std;

struct Pos { int x; int y; Pos(int x_, int y_) throw(); };
class XConsole { public: virtual ~XConsole(); };
class C64_Entity;
class HEntity { public: int ID; HEntity(); C64_Entity *operator->() const; };	// NOTE: placeholder accessors
struct C64_Def { bool unknown56f7e0(HEntity entity); };	// NOTE: placeholder (item def)
struct C64_Item	// NOTE: placeholder (Item)
{
	bool unknown5773d0(bool a, bool b);
	int unknown577350();
	bool unknown457d10();
	bool unknown457db0();
	bool unknown5775a0();
	bool unknown5776c0();
	bool unknown577640();
	bool unknown577700();
	int getNestedField();
	C64_Def *getDef();
};
class HItem { public: int ID; HItem(); bool isValid() const; C64_Item *operator->() const; };	// NOTE: placeholder accessors
class C64_Entity { public: vector<HItem> *getInventoryList(); };	// NOTE: placeholder
struct C64_Map { HEntity getPlayer(); };	// NOTE: placeholder (Map at 0xcefc4c)
struct C64_Targeter { HEntity operate(); };	// NOTE: placeholder (0xcec0fc)
class C64_List : public XConsole	// NOTE: placeholder (CList)
{
public:
	C64_List(XConsole *parent, const Pos &pos, string title, int mode, const vector<string> &options, int maxVisible, int font, void (*callback)(int,const string&), void (*callback2)(int,const string&), int layer, bool a, bool b, vector<bool> *enabled, vector<int> *colorsA, vector<int> *colorsB, bool noClose);	// 0x48d9a0
	char pad04[0xd4 - 4];
};

string teamb_name8f8820(int a, int b);
string teamb_itemName8f8ab0(HItem item);
string teamb_itemLabel8f8e90(HItem item);
HItem teamb_findInventoryItem8f8d30(const string &name);
HItem OpR5d_findItem8f90d0(const string &name);
HItem OpR5d_findItem8f98c0(const string &name);
HItem OpR5d_findItem8f96a0(const string &name);
string OpR5d_getItemDescription8f9230(HItem item);
string OpR5d_getItemName8f9830(HItem item);
void teamb_select8f9a20(int type, const string &name);	// team_b_15.cpp
void teamb_info8f9c60(int type, const string &name);
bool opr1c_hasPtr_cebd5c();
bool opy7_compareNames8b2b40(string &a, string &b);
void teamb_sortNames_9e3160(vector<string>::iterator first, vector<string>::iterator last, bool (*pred)(string &, string &));	// NOTE: placeholder name (std::sort)
void c64_eraseAt(vector<string> &v, int index);	// NOTE: placeholder name (OpQ5_eraseAt)

extern string gameString_cf7584;	// global_strings.cpp
extern vector<int> c64_cf4844, c64_cf4888, c64_cf4830;	// NOTE: placeholder names below
extern int c64_caf160, c64_caf164;
extern XConsole *c64_cec034;
extern int c64_d31690, c64_d31694;
extern C64_Map *c64_cefc4c;
extern C64_Targeter *c64_cec0fc;

void opR5d_unknown8f9ee0(int type)
{
	vector<string> names;
	switch (type)
	{
		case 66:
		{
			for (unsigned int cols = 0; cols < c64_cf4844.size(); cols++)
			{
				if (c64_cf4844[cols] != 0)
					names.push_back(teamb_name8f8820(cols,c64_caf160));
			}
			teamb_sortNames_9e3160(names.begin(),names.end(),opy7_compareNames8b2b40);
			int center = names.size();
			for (unsigned int cols = 0; cols < c64_cf4888.size(); cols++)
			{
				if (c64_cf4888[cols] != 0)
					names.push_back(teamb_name8f8820(c64_caf164,cols));
			}
			teamb_sortNames_9e3160(names.begin() + center,names.end(),opy7_compareNames8b2b40);
			vector<int> *col = new vector<int>(names.size(),0);
			for (unsigned int cols = 0; cols < names.size(); cols++)
			{
				if (names[cols].rfind(gameString_cf7584,string::npos) != string::npos)
					col->at(cols) = 2;
			}
			new C64_List(c64_cec034,Pos(c64_d31690,opr1c_hasPtr_cebd5c() ? 5 : c64_d31694),"\\ S C H E M A T I C S \\",3,names,26,0,teamb_select8f9a20,teamb_info8f9c60,22,false,true,0,col,0,false);
			break;
		}
		case 76:
		{
			vector<HItem> *center = c64_cefc4c->getPlayer()->getInventoryList();
			for (unsigned int cols = 0; cols < center->size(); cols++)
			{
				if ((*center)[cols]->unknown5773d0(true,false))
					names.push_back(teamb_itemName8f8ab0((*center)[cols]));
			}
			teamb_sortNames_9e3160(names.begin(),names.end(),opy7_compareNames8b2b40);
			vector<int> *col = new vector<int>(names.size(),-1);
			for (unsigned int cols = 0; cols < names.size(); cols++)
			{
				HItem v0f0 = teamb_findInventoryItem8f8d30(names[cols]);
				if (v0f0.isValid())
				{
					col->at(cols) = v0f0->unknown577350();
					if (v0f0->unknown457d10())
						col->at(cols) = 3;
					else if (v0f0->unknown457db0())
						col->at(cols) = 4;
				}
			}
			new C64_List(c64_cec034,Pos(c64_d31690,opr1c_hasPtr_cebd5c() ? 5 : c64_d31694),"\\ R E P A I R \\",6,names,26,0,teamb_select8f9a20,teamb_info8f9c60,22,false,true,0,0,col,false);
			break;
		}
		case 81:
		{
			vector<HItem> *center = c64_cefc4c->getPlayer()->getInventoryList();
			for (unsigned int cols = 0; cols < center->size(); cols++)
			{
				if ((*center)[cols]->unknown5775a0())
					names.push_back(teamb_itemLabel8f8e90((*center)[cols]));
			}
			teamb_sortNames_9e3160(names.begin(),names.end(),opy7_compareNames8b2b40);
			vector<int> *col = new vector<int>(names.size(),-1);
			for (unsigned int cols = 0; cols < names.size(); cols++)
			{
				HItem v104 = OpR5d_findItem8f90d0(names[cols]);
				if (v104.isValid())
				{
					col->at(cols) = v104->unknown577350();
					if (v104->unknown457d10())
						col->at(cols) = 3;
					else if (v104->unknown457db0())
						col->at(cols) = 4;
				}
			}
			new C64_List(c64_cec034,Pos(c64_d31690,opr1c_hasPtr_cebd5c() ? 5 : c64_d31694),"\\ R E C Y C L E \\",7,names,26,0,teamb_select8f9a20,teamb_info8f9c60,22,false,true,0,0,col,false);
			break;
		}
		case 94:
		{
			int center = 0;
			vector<HItem> *adj = c64_cefc4c->getPlayer()->getInventoryList();
			for (unsigned int current = 0; current < adj->size(); current++)
			{
				if ((*adj)[current]->unknown5776c0())
				{
					names.push_back(OpR5d_getItemDescription8f9230((*adj)[current]));
					for (unsigned int distanceSq = 0; distanceSq < names.size() - 1; distanceSq++)
					{
						if (names[distanceSq] == names.back())
						{
							c64_eraseAt(names,!(*adj)[current]->unknown577640() ? names.size() - 1 : distanceSq);
							break;
						}
					}
				}
			}
			teamb_sortNames_9e3160(names.begin(),names.end(),opy7_compareNames8b2b40);
			vector<int> *col = new vector<int>(names.size(),0);
			vector<int> *cols = new vector<int>(names.size(),-1);
			for (unsigned int current = 0; current < names.size(); current++)
			{
				HItem v124 = OpR5d_findItem8f96a0(names[current]);
				if (v124.isValid())
				{
					if (!v124->unknown577640() && c64_cf4830[v124->getNestedField()] != 0)
						col->at(current) = 1;
					else
					{
						cols->at(current) = v124->unknown577350();
						if (v124->unknown457d10())
							cols->at(current) = 3;
						else if (v124->unknown457db0())
							cols->at(current) = 4;
					}
				}
			}
			new C64_List(c64_cec034,Pos(c64_d31690,opr1c_hasPtr_cebd5c() ? 5 : c64_d31694),"\\ S C A N \\",8,names,26,0,teamb_select8f9a20,teamb_info8f9c60,22,false,true,0,col,cols,false);
			break;
		}
		case 96:
		{
			vector<HItem> *center = c64_cefc4c->getPlayer()->getInventoryList();
			for (unsigned int current = 0; current < center->size(); current++)
			{
				if ((*center)[current]->unknown577700())
				{
					names.push_back(OpR5d_getItemName8f9830((*center)[current]));
					for (unsigned int distanceSq = 0; distanceSq < names.size() - 1; distanceSq++)
					{
						if (names[distanceSq] == names.back())
						{
							names.pop_back();
							break;
						}
					}
				}
			}
			teamb_sortNames_9e3160(names.begin(),names.end(),opy7_compareNames8b2b40);
			vector<int> *col = new vector<int>(names.size(),0);
			vector<int> *cols = new vector<int>(names.size(),-1);
			for (unsigned int current = 0; current < names.size(); current++)
			{
				HItem v140 = OpR5d_findItem8f98c0(names[current]);
				if (v140.isValid())
				{
					if (!v140->getDef()->unknown56f7e0(c64_cec0fc->operate()) && c64_cf4830[v140->getNestedField()] != 0)
						col->at(current) = 1;
					else
					{
						cols->at(current) = v140->unknown577350();
						if (v140->unknown457d10())
							cols->at(current) = 3;
						else if (v140->unknown457db0())
							cols->at(current) = 4;
					}
				}
			}
			new C64_List(c64_cec034,Pos(c64_d31690,opr1c_hasPtr_cebd5c() ? 5 : c64_d31694),"\\ S T U D Y \\",9,names,26,0,teamb_select8f9a20,teamb_info8f9c60,22,false,true,0,col,cols,false);
			break;
		}
	}
}
