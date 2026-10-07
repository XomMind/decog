// team_b_13: game-logic helpers (0x500000-0x9affff) matched against COGMIND.exe (Beta 17.1), batch 11.
// NOTE: class layouts are partial; TeamB_* classes and unknownXXXXXX members are placeholder names.
// NOTE: local names follow docs/local-name-buckets.txt (MSVC stack layout depends on them).
#include <string>
#include <vector>
using namespace std;
struct Point { int x; int y; Point(); Point(const Point &p); void set(const Point &p); };
class Entity
{
public:
	int unknown5c7d30();
	Point unknown45a4c0();
	Point unknown5c80f0(const Point &p);
	const Point &getPosition();
	int unknown5d2150(int type, int b);
};
class HEntity { public: int ID; HEntity(); Entity *operator->() const; };
struct TeamB_SlotRec;
class Map { public: bool isReachable(int range, const Point &from, const Point &to); vector<TeamB_SlotRec*> *unknown463fc0(); };
extern Map *endObjA;
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);
extern string teamb_aiStateNames_d22328[];	// NOTE: placeholder name
struct TeamB_Threat { HEntity entity; };	// NOTE: placeholder layout
struct TeamB_581850
{
	HEntity self;
	int pad4;
	int value8;
	int state;
	char pad10[0x56 - 0x10];
	bool flag56;
	char pad57[0xf0 - 0x57];
	vector<TeamB_Threat*> threats;
	string getStateName581850();
};
string TeamB_581850::getStateName581850()	// 0x581850
{
	int status = state;
	if (flag56)
		status = 2;
	else if (value8 >= 6 && threats.size())
	{
		HEntity victim;
		Point point;
		int limit = self->unknown5c7d30();
		int nearest = limit;
		int dx;
		for (unsigned int i = 0; i < threats.size(); i++)
		{
			victim = threats[i]->entity;
			point.set(victim->unknown5c80f0(self->unknown45a4c0()));
			dx = OpQ1_distanceCeil_40a3f0(self->unknown5c80f0(point),point);
			if (dx <= nearest && endObjA->isReachable(self->unknown5c7d30(),self->getPosition(),point) && dx <= nearest - victim->unknown5d2150(0x1e,0))
			{
				status = 3;
				goto done;
			}
		}
		status = 4;
	}
done:
	return teamb_aiStateNames_d22328[status];
}

//==================================================================
// slot row colours
//==================================================================
struct XColor { unsigned char r, g, b; XColor(const XColor &c) throw(); };
struct Pos { int x; int y; };
class XConsole
{
public:
	virtual ~XConsole();
	XConsole *getParent();
	Pos getPos();
	void setFore_417f80(int x, int y, XColor color);
	void setForeRow(int x, int y, int width, XColor color);
	char pad04[0x6c - 4];
};
struct OpW5_SlotColor { XColor color; int unknown04; };
extern OpW5_SlotColor opW5_slotColors_d0161c[];
extern XColor *teamb_color_cf44c0;	// NOTE: placeholder names for global colour pointers
extern XColor *teamb_color_cfabbc;
extern XColor *teamb_color_cfe674;
extern XColor *teamb_color_d1d46c;
extern XColor *teamb_color_d20438;
struct TeamB_SlotLayout : XConsole { int x6c; int x70; int width74; };	// NOTE: placeholder layout
extern TeamB_SlotLayout *opU5_cec05c;
bool blink_437320(unsigned int period);
struct TeamB_PartName { int length(); };	// NOTE: placeholder name (ICF'd getter 0x44af50)
struct TeamB_PartData { char pad[0x24]; TeamB_PartName name; char pad28[0x44 - 0x28]; int slot; char pad48[0x54 - 0x48]; int value54; char pad58[0x94 - 0x58]; int value94; };
struct TeamB_SlotRec { int type; TeamB_PartData *data; };
struct TeamB_SlotRow : XConsole	// NOTE: placeholder layout
{
	int index;
	int value70;
	bool flag74;
};
void teamb_drawSlotRow876f60(TeamB_SlotRow *row)	// NOTE: placeholder name (0x876f60)
{
	TeamB_SlotRec *rec = (*endObjA->unknown463fc0())[row->index];
	if (row->flag74)
	{
		row->setFore_417f80(opU5_cec05c->x6c,0,row->value70 ? *teamb_color_cf44c0 : (rec->type == 0 ? (blink_437320(500) ? *teamb_color_cfabbc : *teamb_color_cfe674) : opW5_slotColors_d0161c[rec->data->slot].color));
		bool active = rec->type == 1 && (rec->data->value94 != 0 || rec->data->value54 == 0);
		row->setForeRow(opU5_cec05c->x70,0,opU5_cec05c->width74,active ? *teamb_color_d1d46c : *teamb_color_cf44c0);
		if (active)
		{
			row->setForeRow(0,0,opU5_cec05c->x6c - 1,*teamb_color_d20438);
			row->setForeRow(opU5_cec05c->x6c + 2,0,rec->data->name.length(),*teamb_color_d20438);
			row->getParent()->setFore_417f80(3,row->getPos().y,*teamb_color_d1d46c);
		}
	}
}
