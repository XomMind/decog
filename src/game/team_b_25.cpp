// team_b_25: CMap look/inspect at cursor (0x820dc0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
using namespace std;
struct Pos { int x; int y; explicit Pos(int v); };	// 0x409990
struct Point { int x; int y; Point(); Point(const Point &p); Point &operator=(const Point &p); };
class Entity { public: const Point &getPosition(); };
class HEntity { public: int ID; HEntity(); Entity *operator->() const; bool isValid() const; bool operator==(HEntity other) const; bool operator!=(HEntity other) const; };
class HItem { public: int ID; HItem(); };
struct TeamB_PropInfo3 { char pad[0xf4]; int interactive; };	// NOTE: placeholder layout
class Prop { public: TeamB_PropInfo3 *getInfo(); int getNested_45c5d0(); };
class HProp { public: int ID; HProp(); Prop *operator->() const; bool isValid() const; };
class Cell { public: HEntity getEntity(); HProp getProp(); HItem getItem(); bool unknown45d700(); bool isOpen(); bool unknown45dbb0(); };
struct TeamB_CellGrid { Cell **at(Point &p); };
extern TeamB_CellGrid teamb_cells_cfd44c;
class BS { public: char pad[0x66c]; HEntity player; HEntity getPlayer(); bool isVisible(const Point &p); };
extern BS *teamb_world;
class XConsole { public: virtual ~XConsole(); bool isHidden(); };
class CInfo : public XConsole { public: void unknown8b5080(); void unknown8b4500(HEntity a, HProp b, HEntity c, Pos *pos, int mode, bool e); };
extern CInfo *teamb_info_cec118;	// NOTE: placeholder name
extern CInfo *opx5e_cec11c;	// NOTE: placeholder name (0xcec11c)
extern CInfo *teamb_info_cec120;	// NOTE: placeholder name
extern XConsole *opr5c_activeList;	// NOTE: placeholder name (0xcec130)
extern bool teamb_d28c8a;	// NOTE: placeholder name
struct OpS2_PhraseTextA { OpS2_PhraseTextA(int index, string *a, string *b, string *c, HEntity d, HEntity e); char pad[0x20]; };
class CInterfaceMsg { public: void add(OpS2_PhraseTextA *message); };
extern CInterfaceMsg *teamb_interfaceMsg_cec0f4;	// NOTE: placeholder name
#define H_E (*(HEntity*)&HProp())
class TeamB_CMapLook	// NOTE: placeholder name (CMap)
{
public:
	bool unknown805190(Point *out);
	bool look820dc0(bool atPlayer, bool force);
};
bool TeamB_CMapLook::look820dc0(bool atPlayer, bool force)	// 0x820dc0
{
	Point pos;
	if (atPlayer || (unknown805190(&pos) && teamb_world->isVisible(pos)))
	{
		if (atPlayer)
			pos = teamb_world->getPlayer()->getPosition();
		if ((*teamb_cells_cfd44c.at(pos))->getEntity().isValid() && (*teamb_cells_cfd44c.at(pos))->getEntity() != teamb_world->player)
		{
			if (!teamb_info_cec118->isHidden())
			{
				if (opr5c_activeList)
					return false;
				teamb_info_cec118->unknown8b5080();
			}
			opx5e_cec11c->unknown8b4500((*teamb_cells_cfd44c.at(pos))->getEntity(),HProp(),H_E,&Pos(-1),0,false);
			return true;
		}
		else if ((*teamb_cells_cfd44c.at(pos))->getProp().isValid() && (*teamb_cells_cfd44c.at(pos))->getProp()->getInfo()->interactive != 0 && ((*teamb_cells_cfd44c.at(pos))->getProp()->getNested_45c5d0() != 0 || (*teamb_cells_cfd44c.at(pos))->getProp()->getInfo()->interactive != 2))
		{
			opx5e_cec11c->unknown8b4500(H_E,HProp(),*(HEntity*)&(*teamb_cells_cfd44c.at(pos))->getProp(),&Pos(-1),0,false);
			return true;
		}
		else if ((*teamb_cells_cfd44c.at(pos))->unknown45d700())
		{
			opx5e_cec11c->unknown8b4500(H_E,*(HProp*)&(*teamb_cells_cfd44c.at(pos))->getItem(),H_E,&Pos(-1),0,false);
			return true;
		}
		else if ((teamb_d28c8a || force) && (!(*teamb_cells_cfd44c.at(pos))->isOpen() || (*teamb_cells_cfd44c.at(pos))->unknown45dbb0()))
		{
			opx5e_cec11c->unknown8b4500(H_E,HProp(),H_E,(Pos*)&pos,0,false);
			return true;
		}
		else if ((*teamb_cells_cfd44c.at(pos))->getEntity() == teamb_world->player && teamb_info_cec118->isHidden())
		{
			if (atPlayer)
			{
				teamb_interfaceMsg_cec0f4->add(new OpS2_PhraseTextA(0xcd,NULL,NULL,NULL,H_E,H_E));
				return false;
			}
			else
			{
				if (!opx5e_cec11c->isHidden())
					opx5e_cec11c->unknown8b5080();
				if (!teamb_info_cec120->isHidden())
					teamb_info_cec120->unknown8b5080();
				teamb_info_cec118->unknown8b4500(teamb_world->player,HProp(),H_E,&Pos(-1),0,false);
				return true;
			}
		}
	}
	return false;
}
