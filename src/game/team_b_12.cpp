// team_b_12: game-logic helpers (0x500000-0x9affff) matched against COGMIND.exe (Beta 17.1), batch 10.
// NOTE: class layouts are partial; TeamB_* classes and unknownXXXXXX members are placeholder names.
#include <string>
#include <vector>
using namespace std;

//==================================================================
// SExplosionExpand
//==================================================================

struct Point { int x; int y; Point(const Point &p); Point &operator=(const Point &p); void set(int v); };	// NOTE: placeholder layout
class HProp { public: int ID; HProp(); };
class TeamB_BattleState2	// NOTE: placeholder name for BattleState (ctor 0x453bc0)
{
public:
	TeamB_BattleState2();
	virtual ~TeamB_BattleState2();
	virtual int getType();
	virtual bool update();
	virtual void unknown3() = 0;
	HProp prop4;
	int unknown8;
	int unknownC;
};
struct TeamB_ExplosionRec { int id; string name; char pad20[0x30 - 0x20]; int radius; char pad34[0x78 - 0x34]; int type; };	// NOTE: placeholder layout
struct TeamB_ExplosionArea { TeamB_ExplosionArea(TeamB_ExplosionRec *rec, int radius, const Point &origin, int e, const Point &f); char pad[0x4c]; };	// NOTE: placeholder name (ctor 0x455820)
extern float teamb_explosionScale_d2a868;	// NOTE: placeholder name
extern int teamb_explosionCounter_ce9fe4;	// NOTE: placeholder name
extern Point teamb_lastExplosion_cfd420;	// NOTE: placeholder name
extern bool opw8_d25450;	// NOTE: placeholder name
extern int teamb_sigixExplosion_d254f0;	// NOTE: placeholder name
class SExplosionExpand : public TeamB_BattleState2
{
public:
	SExplosionExpand(int a, TeamB_ExplosionRec *rec, const Point &origin, int d, int e, const Point &f);
	virtual ~SExplosionExpand();
	virtual int getType();
	virtual bool update();
	int id;
	int value14;
	TeamB_ExplosionRec *rec;
	int radius;
	Point origin;
	TeamB_ExplosionArea *area;
	int value2c;
	vector<unsigned int> list30;
};
SExplosionExpand::SExplosionExpand(int a, TeamB_ExplosionRec *rec_, const Point &origin_, int d, int e, const Point &f)
	: value14(a),
	rec(rec_),
	origin(origin_),
	value2c(d)
{
	radius = (int)(rec->type == 0xc9 ? rec->radius * teamb_explosionScale_d2a868 : (double)rec->radius);
	area = new TeamB_ExplosionArea(rec_,radius,origin_,e,f);
	teamb_lastExplosion_cfd420 = f;
	id = teamb_explosionCounter_ce9fe4;
	teamb_explosionCounter_ce9fe4++;
	if (teamb_explosionCounter_ce9fe4 > 1000000)
		teamb_explosionCounter_ce9fe4 = 1;
	if (opw8_d25450 && rec->name.find("Sigix_Terminator",0) != string::npos)
		teamb_sigixExplosion_d254f0 = rec->id;
}

//==================================================================
// AI state reset
//==================================================================

class HEntity { public: int ID; void clear() throw(); };	// NOTE: placeholder layout
struct TeamB_Y8 { int a; int b; };	// NOTE: placeholder element type
struct TeamB_AIState	// NOTE: placeholder name/layout
{
	int value0;
	bool flag4;
	HEntity handle8;
	char padc[0x1c - 0xc];
	Point point1c;
	bool flag24, flag25, flag26;
	int value28;
	int value2c;
	HEntity entity30;
	int value34;
	bool flag38;
	Point pos3c;
	HEntity prop44;
	int turn48;
	int value4c;
	vector<TeamB_Y8> list50;
	Point point60, point68, point70;
	bool flag78;
	int value7c;
	int value80;
	HEntity handle84;
	bool flag88, flag89, flag8a, flag8b, flag8c;
	int value90, value94, value98, value9c;
	vector<int> listA0;
	bool flagB0;
	int valueB4;
	bool flagB8;
	int valueBC;
	int valueC0;
	void reset872c80();
};
void TeamB_AIState::reset872c80()
{
	value0 = 5;
	flag4 = false;
	handle8.clear();
	point1c.set(0);
	flag24 = false;
	flag25 = false;
	flag26 = false;
	value28 = 0;
	value2c = 8;
	entity30.clear();
	value34 = 0;
	flag38 = false;
	pos3c.set(-1);
	prop44.clear();
	turn48 = -9999;
	value4c = -1;
	list50.clear();
	point60.set(-1);
	point68.set(-1);
	point70.set(-1);
	flag78 = false;
	value80 = 0;
	handle84.clear();
	flag88 = false;
	flag89 = false;
	flag8a = false;
	flag8b = false;
	flag8c = false;
	value90 = 0;
	value94 = 0;
	value98 = 0;
	value9c = 0;
	listA0.assign((unsigned int)3,0);
	flagB0 = false;
	valueB4 = 0;
	flagB8 = false;
	valueBC = 0;
	valueC0 = 0;
}
