// team_b_16: "DECIDE" choice list (0x8f8680) matched against COGMIND.exe (Beta 17.1).
// NOTE: placeholder names; local names follow docs/local-name-buckets.txt.
#include <string>
#include <vector>
using namespace std;
struct Pos { int x; int y; Pos(int x_, int y_); Pos(const Pos &p); Pos &operator+=(const Pos &p); Pos operator+(const Pos &p) const; };
class XConsole { public: virtual ~XConsole(); Pos getPos(); };
class Entity { public: Pos unknown45a4c0(); int getSize(); };
class HEntity { public: int ID; HEntity(); Entity *operator->() const; };
class Map { public: HEntity getPlayer(); };
extern Map *endObjA;
class CMap : public XConsole { public: void unknown8069e0(Pos p, bool flag); const Pos &unknown458ef0(); };
extern CMap *opx5e_cec054;	// NOTE: placeholder name (0xcec054)
extern XConsole *teamb_cec034;	// NOTE: placeholder name (0xcec034)
class CList
{
public:
	CList(XConsole *parent, const Pos &pos, string title, int unknown74_, const vector<string> &options_, int maxVisible, int font, void (*callback_)(int,const string&), int unknownC4_, int layer, bool unknown9c_, bool unknown9d_, vector<bool> *enabled_, vector<int> *unknownA4_, vector<int> *unknownA8_, bool noClose_);	// 0x48d9a0
	char pad[0xd4];
};
void opw1_split(const string &text, char separator, vector<string> &out);	// NOTE: placeholder name (0x408700)
extern int teamb_decideType_d35bb8;	// NOTE: placeholder name
extern vector<string> teamb_decideOptions_d22300;	// NOTE: placeholder name
extern int opr5f_tileWidth;	// NOTE: placeholder name (0xcaf128)
extern int opr5f_tileHeight;	// NOTE: placeholder name (0xcaf12c)
void teamb_decideCallback8f8340(int index, const string &option);	// NOTE: placeholder name
void teamb_openDecide8f8680(int type, const string &options)	// NOTE: placeholder name (0x8f8680)
{
	teamb_decideType_d35bb8 = type;
	teamb_decideOptions_d22300.clear();
	opw1_split(options,'=',teamb_decideOptions_d22300);
	opx5e_cec054->unknown8069e0(endObjA->getPlayer()->unknown45a4c0(),true);
	Pos offset = opx5e_cec054->unknown458ef0() + endObjA->getPlayer()->unknown45a4c0();
	Pos point((offset.x + endObjA->getPlayer()->getSize()) * opr5f_tileWidth,offset.y * opr5f_tileHeight);
	point += opx5e_cec054->getPos();
	new CList(teamb_cec034,point,"\\ D E C I D E \\",10,teamb_decideOptions_d22300,0x1a,0,teamb_decideCallback8f8340,0,0x16,false,true,NULL,NULL,NULL,true);
}
