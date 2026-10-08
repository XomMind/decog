// team_b_30: CShell hack completion (0x90c700) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
struct Point
{
	int x;
	int y;
	Point(const Point &p);
	void shift_409a30(const Point &offset);	// NOTE: placeholder name
};
class Prop;
class HProp { public: int ID; bool isValid() const; Prop *operator->() const; };
struct TeamB_HackRecord { char pad[0x18]; vector<struct TeamB_HackEntry *> entries; char pad28[0x40 - 0x28]; vector<int> list40; };	// NOTE: placeholder layout
struct TeamB_HackEntry { int value; };	// NOTE: placeholder layout
struct TeamB_HackData { char pad[0xf8]; int index; };	// NOTE: placeholder layout
class Prop { public: TeamB_HackRecord *getRecord_45cb30(); TeamB_HackData *getData(); };	// NOTE: placeholder name
class TeamB_HackCell { public: HProp getProp(); };	// NOTE: placeholder name (Cell)
class TeamB_HackGrid { public: TeamB_HackCell **atPoint(Point &p); };	// NOTE: placeholder name
extern TeamB_HackGrid teamb_hackGrid_cfd44c;	// NOTE: placeholder name
class XConsole { public: virtual ~XConsole(); void removeSubconsole(XConsole *console); void unknown987de0(); };
class TeamB_HackMap	// NOTE: placeholder name (CMap)
{
public:
	void unknown80e3a0(int type, Point &pos);	// NOTE: placeholder name
	void unknown813050(int type, HProp prop, int a, int b, int c);	// NOTE: placeholder name
	Point &getOffset_458ef0();	// NOTE: placeholder name
	bool inBounds(const Point &pos);	// NOTE: placeholder name
};
extern TeamB_HackMap *teamb_hackMap_cec054;	// NOTE: placeholder name
extern XConsole *teamb_hackMission_cec034;	// NOTE: placeholder name
class TeamB_HackWorld	// NOTE: placeholder name (Map)
{
public:
	char pad[0x720];
	int list720;	// NOTE: placeholder layout
	void unknown9e29b0(int *list, HProp prop);	// NOTE: placeholder name
	vector<vector<Point> > *unknown459070();	// NOTE: placeholder name
};
extern TeamB_HackWorld *teamb_hackWorld_cefc4c;	// NOTE: placeholder name
class TeamB_HackEffect { public: void unknown50de10(); };	// NOTE: placeholder name
class TeamB_HackEngine { public: TeamB_HackEffect *unknown50fb50(TeamB_HackEngine *engine, int type, const Point &pos, Point *b, int c, int d, int value); };	// NOTE: placeholder name (OpR2b_Engine)
extern TeamB_HackEngine *teamb_hackEngine_cefc64;	// NOTE: placeholder name
extern Point teamb_point_cfbec0;	// NOTE: placeholder name
class TeamB_HackHelp { public: void showOnce(int id, int a, int b, int c, int d); };	// NOTE: placeholder name
extern TeamB_HackHelp *teamb_hackHelp_cefaa8;	// NOTE: placeholder name
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
bool teamb_containsInt_9db330(vector<int> &list, int value);	// NOTE: placeholder name
bool teamb_containsPtr_9db330(vector<int> &list, TeamB_HackEntry *value);	// NOTE: placeholder name
void teamb_deleteAndStep_9de640(vector<TeamB_HackEntry *> &list, int &index);	// NOTE: placeholder name
class TeamB_ShellHack : public XConsole	// NOTE: placeholder name (CShell)
{
public:
	char pad04[0x70 - 4];
	HProp target;
	char pad74[0xa8 - 0x74];
	vector<Point> pointsA8;
	vector<Point> pointsB8;
	vector<Point> pointsC8;
	bool flagD8;
	vector<Point> pointsDC;
	char padEC[0x104 - 0xec];
	vector<int> list104;
	vector<int> list114;
	void finish90c700();
};
void TeamB_ShellHack::finish90c700()	// 0x90c700
{
	if (!pointsA8.empty())
	{
		for (unsigned int i = 0; i < pointsA8.size(); i++)
			teamb_hackMap_cec054->unknown80e3a0(1,pointsA8[i]);
	}
	if (!pointsB8.empty())
	{
		for (unsigned int j = 0; j < pointsB8.size(); j++)
			teamb_hackMap_cec054->unknown80e3a0(1,pointsB8[j]);
	}
	if (!pointsC8.empty())
	{
		for (unsigned int k = 0; k < pointsC8.size(); k++)
		{
			if ((*teamb_hackGrid_cfd44c.atPoint(pointsC8[k]))->getProp().isValid())
			{
				teamb_hackMap_cec054->unknown813050(1,(*teamb_hackGrid_cfd44c.atPoint(pointsC8[k]))->getProp(),0,0,0);
				teamb_hackWorld_cefc4c->unknown9e29b0(&teamb_hackWorld_cefc4c->list720,(*teamb_hackGrid_cfd44c.atPoint(pointsC8[k]))->getProp());
			}
		}
	}
	if (flagD8)
		teamb_hackMission_cec034->unknown987de0();
	if (!pointsDC.empty())
	{
		int anim = 0;
		OpU8a_lookup1("CMap_Layout_Reveal_Hack",&anim);
		if (anim != 0)
		{
			Point offset(teamb_hackMap_cec054->getOffset_458ef0());
			for (unsigned int m = 0; m < pointsDC.size(); m++)
			{
				pointsDC[m].shift_409a30(offset);
				if (teamb_hackMap_cec054->inBounds(pointsDC[m]))
					teamb_hackEngine_cefc64->unknown50fb50(teamb_hackEngine_cefc64,anim,pointsDC[m],&teamb_point_cfbec0,0,0,9)->unknown50de10();
			}
		}
	}
	if (target.operator->() != NULL)
	{
		if (!list114.empty())
		{
			vector<Point> &list = (*teamb_hackWorld_cefc4c->unknown459070())[target->getData()->index];
			for (unsigned int n = 0; n < list.size(); n++)
			{
				vector<TeamB_HackEntry *> &items = (*teamb_hackGrid_cfd44c.atPoint(list[n]))->getProp()->getRecord_45cb30()->entries;
				for (unsigned int q = 0; q < items.size(); q++)
				{
					if (teamb_containsInt_9db330(list114,items[q]->value))
						teamb_deleteAndStep_9de640(items,(int &)q);
				}
			}
		}
		if (!list104.empty())
		{
			vector<TeamB_HackEntry *> &entries = target->getRecord_45cb30()->entries;
			for (unsigned int r = 0; r < entries.size(); r++)
			{
				if (teamb_containsPtr_9db330(list104,entries[r]))
					teamb_deleteAndStep_9de640(entries,(int &)r);
			}
		}
		if (!target->getRecord_45cb30()->list40.empty())
			teamb_hackHelp_cefaa8->showOnce(0x48,1,0,0,0);
	}
	teamb_hackMission_cec034->removeSubconsole(this);
}
