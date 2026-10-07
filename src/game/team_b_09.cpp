// team_b_09: game-logic helpers (0x500000-0x9affff) matched against COGMIND.exe (Beta 17.1), batch 7.
// NOTE: class layouts are partial; TeamB_* classes and unknownXXXXXX members are placeholder names.
// NOTE: local names follow docs/local-name-buckets.txt (MSVC stack layout depends on them).
#include <string>
using namespace std;

struct Point
{
	int x; int y;
	Point();	// 0x453b40
	Point(int v);	// 0x409990
	Point &operator=(const Point &p);	// 0x46ca50
	Point &operator+=(const Point &p);	// 0x409a30
	Point &operator-=(const Point &p);	// 0x409a70
};
struct Area { Area(); void randomPoint_40be30(Point *out); Point min; Point max; };
class Entity { public: const Point &getPosition(); };
class HEntity { public: int ID; HEntity(); Entity *operator->() const; };
class Cell { public: bool isOpen(); };
struct TeamB_CellGrid { Cell **at(Point &p); void getRandom_9cf0c0(Point *out); };
extern TeamB_CellGrid teamb_cells_cfd44c;
struct EntityRecord;
class BS
{
public:
	HEntity getPlayer();
	bool findPlaceableNear(const Point &p, Point &out, int size);
	HEntity placeEntity(EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
};
extern BS *teamb_world;
bool terrainFlagB_448b80(Point &p);
// NOTE: "-= 4" relies on the implicit Point(int) conversion; the exe re-takes the temporary's address
HEntity teamb_spawnRandom6fd950(EntityRecord *record, int groupIndex, bool nearPlayer)	// NOTE: placeholder name (0x6fd950)
{
	Point point;
	Point dest;
	Area center;
	int idx;
	if (nearPlayer)
	{
		center.max = center.min = teamb_world->getPlayer()->getPosition();
		center.min -= 4;
		center.max += 4;
	}
	for (idx = 0; idx < 30; idx++)
	{
		if (nearPlayer)
			center.randomPoint_40be30(&point);
		else
			teamb_cells_cfd44c.getRandom_9cf0c0(&point);
		if (!(*teamb_cells_cfd44c.at(point))->isOpen())
		{
			idx--;
			continue;
		}
		if ((nearPlayer || !terrainFlagB_448b80(point)) && teamb_world->findPlaceableNear(point,dest,2))
			return teamb_world->placeEntity(record,dest,groupIndex,true,0x22,0xe,false);
	}
	return HEntity();
}

// NOTE: 0x9650c0 is OpT7_Hud::unknown9650c0 in src/op/op_t7_c.cpp.

//==================================================================
// frame colors
//==================================================================

struct XColor { unsigned char r, g, b; XColor(const XColor &c) throw(); };
class Console { public: void setFrameFore(XColor color); };
class CParts : public Console { public: void refreshCycles(); };
extern XColor teamb_frameColor_cf6f2c;	// NOTE: placeholder name
extern Console *opt7_cec078;
extern Console *opt7_cec07c;
extern Console *opt7_cec084;
extern CParts *teamb_parts_cec088;
extern Console *opt7_cec08c;
extern Console *teamb_cec0b0;
extern Console *teamb_cec0c8;
extern Console *teamb_cec0cc;
extern Console *teamb_cec0b8;
extern Console *teamb_cec0c0;
extern Console *teamb_cec0f8;
extern Console *teamb_cec118;
extern Console *teamb_cec11c;
extern Console *teamb_cec120;
void opw8_unknown789ac0()	// NOTE: placeholder name (0x789ac0, name from src/op/op_w8.cpp)
{
	opt7_cec078->setFrameFore(teamb_frameColor_cf6f2c);
	opt7_cec07c->setFrameFore(teamb_frameColor_cf6f2c);
	opt7_cec084->setFrameFore(teamb_frameColor_cf6f2c);
	teamb_parts_cec088->setFrameFore(teamb_frameColor_cf6f2c);
	teamb_parts_cec088->refreshCycles();
	opt7_cec08c->setFrameFore(teamb_frameColor_cf6f2c);
	teamb_cec0b0->setFrameFore(teamb_frameColor_cf6f2c);
	teamb_cec0c8->setFrameFore(teamb_frameColor_cf6f2c);
	teamb_cec0cc->setFrameFore(teamb_frameColor_cf6f2c);
	teamb_cec0b8->setFrameFore(teamb_frameColor_cf6f2c);
	teamb_cec0c0->setFrameFore(teamb_frameColor_cf6f2c);
	teamb_cec0f8->setFrameFore(teamb_frameColor_cf6f2c);
	teamb_cec118->setFrameFore(teamb_frameColor_cf6f2c);
	teamb_cec11c->setFrameFore(teamb_frameColor_cf6f2c);
	teamb_cec120->setFrameFore(teamb_frameColor_cf6f2c);
}
