// team_b_35: CMap scan command handler (0x813c80) matched against COGMIND.exe (Beta 17.1).
// NOTE: borrowed partial layouts; corrected actual label/effect/message contracts.
// Allocated PhraseTextA owns a real native string at +4, total32B.
#include <string>
#include <vector>
using namespace std;
struct TeamB_ScanDef;
bool teamb_lookup9d45a0(const string &name, TeamB_ScanDef **value);	// NOTE: placeholder name (0x9d45a0)
struct Point { int x; int y; Point add_409b60(const Point &p) const; };	// NOTE: placeholder name (PushCoord::add)
struct Pos { int x; int y; Pos(int x_, int y_); };
class HProp { public: int ID; HProp(); };
class HEntity { public: int ID; HEntity(); };
class HItem { public: int ID; HItem(); };
struct OpS2_Phrase;
class OpS2_PhraseTextA	// NOTE: same declaration as src/op (0x510d20)
{
public:
	OpS2_PhraseTextA(int index, string *a, string *b, string *c, HEntity d, HEntity e);	// 0x510d20
	OpS2_Phrase *m0;
	string m4;
};
class TeamB_ScanMsg { public: void add(OpS2_PhraseTextA *msg); };	// NOTE: placeholder name (CInterfaceMsg)
extern TeamB_ScanMsg *teamb_interfaceMsg_cec0f4;	// NOTE: placeholder name
void teamb_msg813_7b1750(int type, const string *a, const string *b, const string *c, HEntity e, HEntity p, const Point *d);	// NOTE: placeholder name (0x7b1750)
struct TeamB_ScanExit { Point pos; char pad8[5]; bool known; };	// NOTE: placeholder layout
class TeamB_ScanWorld { public: char pad[0x10]; vector<TeamB_ScanExit *> exits; bool unknown464310(); bool unknown464330(); };	// NOTE: placeholder name (Map)
extern TeamB_ScanWorld *teamb_scanWorld_cefc4c;	// NOTE: placeholder name
class TeamB_ScanEngine;
class TeamB_ScanEffect { public: bool unknown50de10(TeamB_ScanEngine*,TeamB_ScanDef*,const Pos&,const Point&,const Point*,const Point*,int); };	// NOTE: placeholder name
class TeamB_ScanEngine { public: TeamB_ScanEffect *unknown50fb50(); };	// NOTE: placeholder name (OpR2b_Engine)
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
	int labelEntities_810270(int mode, HEntity entity, bool a, bool b);	// NOTE: placeholder name
	int labelProps_813050(bool hostile, HProp prop, bool a, bool b, bool c);	// NOTE: placeholder name
	int labelItems_8119c0(HItem item, bool recent, bool a, bool b);	// NOTE: placeholder name
	void unknown80e3a0(bool timed, const Point &pos);	// NOTE: placeholder name
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
			int count = labelEntities_810270(type != 0x8c ? 2 : 0,HEntity(),false,false);
			if ((count += labelProps_813050(type == 0x8c,HProp(),false,false,false)) == 0)
				teamb_msg813_7b1750(0x62,&string(type == 0x8c ? "hostiles" : "friendlies"),0,0,HEntity(),HEntity(),0);
			break;
		}
		case 0x8e:
		{
			int total = labelItems_8119c0(HItem(),teamb_tickCount <= partsTime + 5000,false,false);
			if (total == 0)
			{
				teamb_msg813_7b1750(0x62,&string("parts"),0,0,HEntity(),HEntity(),0);
				partsTime = teamb_tickCount;
			}
			break;
		}
		case 0x8f:
		{
			int hits = 0;
			TeamB_ScanDef *value = 0;
			teamb_lookup9d45a0("CMap_Exit_Intersector",&value);
			for (unsigned int i = 0; i < teamb_scanWorld_cefc4c->exits.size(); i++)
			{
				if (teamb_scanWorld_cefc4c->exits[i]->known)
				{
					hits++;
					unknown80e3a0(false,teamb_scanWorld_cefc4c->exits[i]->pos);
					if (isBlocked_8052f0(teamb_scanWorld_cefc4c->exits[i]->pos))
					{
						Point pt = teamb_scanWorld_cefc4c->exits[i]->pos.add_409b60(offset);
						for (int x = pt.x, y = 0; y < teamb_mapHeight_cf27f8; y++)
							teamb_scanEngine_cefc64->unknown50fb50()->unknown50de10(teamb_scanEngine_cefc64,value,Pos(x,y),teamb_point_cfbec0,0,0,9);
						for (int x = 0, y = pt.y; x < teamb_mapWidth_cf27f4; x++)
							teamb_scanEngine_cefc64->unknown50fb50()->unknown50de10(teamb_scanEngine_cefc64,value,Pos(x,y),teamb_point_cfbec0,0,0,9);
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
