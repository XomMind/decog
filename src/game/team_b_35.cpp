// team_b_35: CMap scan command handler (0x813c80) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
struct Point { int x; int y; Point add_409b60(const Point &p) const; };	// NOTE: placeholder name (PushCoord::add)
struct Pos { int x; int y; Pos(int x_, int y_); };
class HProp { public: int ID; HProp(); };
class HEntity { public: int ID; HEntity(); };
class OpS2_PhraseTextA	// NOTE: same declaration as src/op (0x510d20)
{
public:
	OpS2_PhraseTextA(int index, string *a, string *b, string *c, HEntity d, HEntity e);	// 0x510d20
	char pad[0x20];
};
class TeamB_ScanMsg { public: void add(OpS2_PhraseTextA *msg); };	// NOTE: placeholder name (CInterfaceMsg)
extern TeamB_ScanMsg *teamb_interfaceMsg_cec0f4;	// NOTE: placeholder name
void teamb_msg813_7b1750(int type, const string &a, const string *b, const string *c, HProp e, HProp p, int d);	// NOTE: placeholder name (0x7b1750)
struct TeamB_ScanExit { Point pos; char pad8[5]; bool known; };	// NOTE: placeholder layout
class TeamB_ScanWorld { public: char pad[0x10]; vector<TeamB_ScanExit *> exits; bool unknown464310(); bool unknown464330(); };	// NOTE: placeholder name (Map)
extern TeamB_ScanWorld *teamb_scanWorld_cefc4c;	// NOTE: placeholder name
class TeamB_ScanEffect { public: void unknown50de10(); };	// NOTE: placeholder name
class TeamB_ScanEngine { public: TeamB_ScanEffect *unknown50fb50(TeamB_ScanEngine *engine, int type, const Pos &pos, Point *b, int c, int d, int value); };	// NOTE: placeholder name (OpR2b_Engine)
extern TeamB_ScanEngine *teamb_scanEngine_cefc64;	// NOTE: placeholder name
extern Point teamb_point_cfbec0;	// NOTE: placeholder name
extern int teamb_mapHeight_cf27f8;	// NOTE: placeholder name
extern int teamb_mapWidth_cf27f4;	// NOTE: placeholder name
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
class TeamB_CMapScan	// NOTE: placeholder name (CMap)
{
public:
	char pad[0x6c];
	Point offset;
	char pad74[0x1f0 - 0x74];
	unsigned int partsTime;
	char pad1f4[4];
	unsigned int scanTime;
	int unknown1fc;
	void unknown8142d0(unsigned int type, bool flag);	// NOTE: placeholder name
	int labelEntities_810270(int mode, HProp prop, int a, int b);	// NOTE: placeholder name
	int labelProps_813050(bool hostile, HProp prop, int a, int b, int c);	// NOTE: placeholder name
	int labelItems_8119c0(HProp prop, bool recent, int a, int b);	// NOTE: placeholder name
	void unknown80e3a0(int type, Point &pos);	// NOTE: placeholder name
	bool isBlocked_8052f0(const Point &pos);	// NOTE: placeholder name
	void scan813c80(int type);
};
void TeamB_CMapScan::scan813c80(int type)	// 0x813c80 (local names follow docs/local-name-buckets.txt)
{
	unknown1fc = -1;
	unknown8142d0(0x12,false);
	scanTime = teamb_tickCount;
	switch (type)
	{
		case 0x8c:
		case 0x8d:
		{
			int count = labelEntities_810270(type != 0x8c ? 2 : 0,HProp(),0,0);
			if ((count += labelProps_813050(type == 0x8c,HProp(),0,0,0)) == 0)
				teamb_msg813_7b1750(0x62,string(type == 0x8c ? "hostiles" : "friendlies"),0,0,HProp(),HProp(),0);
			break;
		}
		case 0x8e:
		{
			int total = labelItems_8119c0(HProp(),teamb_tickCount <= partsTime + 5000,0,0);
			if (total == 0)
			{
				teamb_msg813_7b1750(0x62,string("parts"),0,0,HProp(),HProp(),0);
				partsTime = teamb_tickCount;
			}
			break;
		}
		case 0x8f:
		{
			int hits = 0;
			int value = 0;
			OpU8a_lookup1("CMap_Exit_Intersector",&value);
			for (unsigned int i = 0; i < teamb_scanWorld_cefc4c->exits.size(); i++)
			{
				if (teamb_scanWorld_cefc4c->exits[i]->known)
				{
					hits++;
					unknown80e3a0(0,teamb_scanWorld_cefc4c->exits[i]->pos);
					if (isBlocked_8052f0(teamb_scanWorld_cefc4c->exits[i]->pos))
					{
						Point pt = teamb_scanWorld_cefc4c->exits[i]->pos.add_409b60(offset);
						for (int x = pt.x, y = 0; y < teamb_mapHeight_cf27f8; y++)
							teamb_scanEngine_cefc64->unknown50fb50(teamb_scanEngine_cefc64,value,Pos(x,y),&teamb_point_cfbec0,0,0,9)->unknown50de10();
						for (int x = 0, y = pt.y; x < teamb_mapWidth_cf27f4; x++)
							teamb_scanEngine_cefc64->unknown50fb50(teamb_scanEngine_cefc64,value,Pos(x,y),&teamb_point_cfbec0,0,0,9)->unknown50de10();
					}
				}
			}
			if (hits == 0)
				teamb_interfaceMsg_cec0f4->add(new OpS2_PhraseTextA(0x63,0,0,0,HEntity(),HEntity()));
			else if (teamb_scanWorld_cefc4c->unknown464310())
				teamb_interfaceMsg_cec0f4->add(new OpS2_PhraseTextA(0x64,0,0,0,HEntity(),HEntity()));
			else if (teamb_scanWorld_cefc4c->unknown464330())
				teamb_interfaceMsg_cec0f4->add(new OpS2_PhraseTextA(0x65,0,0,0,HEntity(),HEntity()));
			break;
		}
	}
}
