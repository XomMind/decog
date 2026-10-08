// team_b_40: knowledge-list browser (0x8b2ee0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
struct Pos { int x; int y; };
class XConsole { public: virtual ~XConsole(); bool isHidden(); };
class TeamB_KnowInfo : public XConsole	// NOTE: placeholder name (CInfo)
{
public:
	void unknown8b5080();	// NOTE: placeholder name
	const Pos &getUnknownB4() throw();	// NOTE: placeholder name
	const Pos &getUnknownBC() throw();	// NOTE: placeholder name
	const Pos &getUnknownC4() throw();	// NOTE: placeholder name
	const Pos &getUnknownCC() throw();	// NOTE: placeholder name
};
extern TeamB_KnowInfo *teamb_info_cec118;	// NOTE: placeholder name
extern TeamB_KnowInfo *teamb_info_cec11c;	// NOTE: placeholder name
class TeamB_KnowList : public XConsole	// NOTE: placeholder name (CList)
{
public:
	TeamB_KnowList(XConsole *parent, const Pos &pos, string title, int unknown74_, const vector<string> &options_, int maxVisible, int font, void (*callback_)(int,const string&), void (*callback2_)(int,const string&), int layer, bool unknown9c_, bool unknown9d_, vector<bool> *enabled_, vector<int> *unknownA4_, vector<int> *unknownA8_, bool noClose_);	// NOTE: placeholder name (CList::CList 0x48d9a0)
	char pad04[0xd4 - 4];
};
struct TeamB_KnowItemType { char pad[0x24]; string name; };	// NOTE: placeholder layout
struct TeamB_KnowRobot { char pad[0x1ac]; string name; string getName_4598f0(); };	// NOTE: placeholder layout
extern vector<TeamB_KnowItemType *> teamb_knowItemTypes_d2d1c4;	// NOTE: placeholder name
extern vector<TeamB_KnowRobot *> teamb_knowRobots_d25de0;	// NOTE: placeholder name
extern vector<int> teamb_knownItems_cf4830;	// NOTE: placeholder name
extern vector<int> teamb_knownParts_cf4844;	// NOTE: placeholder name
extern vector<int> teamb_knownRobots_cf4888;	// NOTE: placeholder name
extern vector<int> teamb_knownStudies_cf48cc;	// NOTE: placeholder name
extern vector<int> teamb_knownAnalyses_cf4910;	// NOTE: placeholder name
bool opy7_compareNames8b2b40(string &a, string &b);	// NOTE: placeholder name
void opr5c_spawn8b36d0(int mode, const string &name);	// NOTE: placeholder name
void opr5c_spawn8b36f0(int mode, const string &name);	// NOTE: placeholder name
void teamb_sortNames_9e3160(vector<string>::iterator first, vector<string>::iterator last, bool (*pred)(string &, string &));	// NOTE: placeholder name (std::sort)
void teamb_showKnowledge8b2ee0(int mode)	// 0x8b2ee0
{
	switch (mode)
	{
		case 0:
		{
			if (!teamb_info_cec11c->isHidden())
				teamb_info_cec11c->unknown8b5080();
			vector<string> names;
			for (unsigned int i = 0; i < teamb_knownItems_cf4830.size(); i++)
			{
				if (teamb_knownItems_cf4830[i] != 0)
					names.push_back(teamb_knowItemTypes_d2d1c4[i]->name);
			}
			teamb_sortNames_9e3160(names.begin(),names.end(),opy7_compareNames8b2b40);
			new TeamB_KnowList(teamb_info_cec118,teamb_info_cec118->getUnknownB4(),"\\ D A T A B A S E \\",mode,names,0x1a,0,opr5c_spawn8b36d0,opr5c_spawn8b36f0,0x16,false,true,0,0,0,false);
			break;
		}
		case 1:
		{
			if (!teamb_info_cec11c->isHidden())
				teamb_info_cec11c->unknown8b5080();
			vector<string> names;
			for (unsigned int i = 0; i < teamb_knownParts_cf4844.size(); i++)
			{
				if (teamb_knownParts_cf4844[i] != 0)
					names.push_back(teamb_knowItemTypes_d2d1c4[i]->name);
			}
			teamb_sortNames_9e3160(names.begin(),names.end(),opy7_compareNames8b2b40);
			new TeamB_KnowList(teamb_info_cec118,teamb_info_cec118->getUnknownBC(),"\\ P A R T S \\",mode,names,0x1a,0,opr5c_spawn8b36d0,opr5c_spawn8b36f0,0x16,false,true,0,0,0,false);
			break;
		}
		case 2:
		{
			if (!teamb_info_cec11c->isHidden())
				teamb_info_cec11c->unknown8b5080();
			vector<string> names;
			for (unsigned int i = 0; i < teamb_knownRobots_cf4888.size(); i++)
			{
				if (teamb_knownRobots_cf4888[i] != 0)
					names.push_back(teamb_knowRobots_d25de0[i]->name);
			}
			teamb_sortNames_9e3160(names.begin(),names.end(),opy7_compareNames8b2b40);
			new TeamB_KnowList(teamb_info_cec118,teamb_info_cec118->getUnknownBC(),"\\ R O B O T S \\",mode,names,0x1a,0,opr5c_spawn8b36d0,opr5c_spawn8b36f0,0x16,false,true,0,0,0,false);
			break;
		}
		case 4:
		{
			if (!teamb_info_cec11c->isHidden())
				teamb_info_cec11c->unknown8b5080();
			vector<string> names;
			for (unsigned int i = 0; i < teamb_knownStudies_cf48cc.size(); i++)
			{
				if (teamb_knownStudies_cf48cc[i] != 0)
					names.push_back(teamb_knowItemTypes_d2d1c4[i]->name);
			}
			teamb_sortNames_9e3160(names.begin(),names.end(),opy7_compareNames8b2b40);
			new TeamB_KnowList(teamb_info_cec118,teamb_info_cec118->getUnknownC4(),"\\ S T U D I E S \\",mode,names,0x1a,0,opr5c_spawn8b36d0,opr5c_spawn8b36f0,0x16,false,true,0,0,0,false);
			break;
		}
		case 5:
		{
			if (!teamb_info_cec11c->isHidden())
				teamb_info_cec11c->unknown8b5080();
			vector<string> names;
			for (unsigned int i = 0; i < teamb_knownAnalyses_cf4910.size(); i++)
			{
				if (teamb_knownAnalyses_cf4910[i] != 0)
					names.push_back(teamb_knowRobots_d25de0[i]->getName_4598f0());
			}
			teamb_sortNames_9e3160(names.begin(),names.end(),opy7_compareNames8b2b40);
			new TeamB_KnowList(teamb_info_cec118,teamb_info_cec118->getUnknownCC(),"\\ A N A L Y S E S \\",mode,names,0x1a,0,opr5c_spawn8b36d0,opr5c_spawn8b36f0,0x16,false,true,0,0,0,false);
			break;
		}
	}
}
