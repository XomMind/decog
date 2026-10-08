// team_c_63: Entity item activation (0x64da50): first-use hints for the player, marks the item active and runs the
//	player-side activation effects (scan/sensor/squad identifier utilities etc.)
// NOTE: names are placeholders; layouts are partial
#include <string>
#include <vector>
using namespace std;

string intToString(int value);
string opw8_countString(int count, const string &noun);	// NOTE: placeholder name (0x407a80)
void opR1d_4541b0(int a, int b, int c);	// NOTE: placeholder name
bool OpT8b_Fn9daf80(int min, int value, int max);	// NOTE: placeholder name

struct C63_Pos { int x; int y; C63_Pos(int value); bool test(const C63_Pos &p); };	// NOTE: placeholder (Pos)
class C63_HProp { public: int ID; C63_HProp(); };	// NOTE: placeholder (HProp)
struct C63_Def { char pad0[0x1a0]; int f1a0; };	// NOTE: placeholder layout
struct C63_Item	// NOTE: placeholder (Item)
{
	int getNestedField();
	int unknown4580c0();
	int unknown457f90();
	int unknown457fb0();
	float unknown457df0();
	string unknown571db0(bool a, bool b);
	void setActive(bool active);
	C63_Def *getDef();
	void unknown458700(const string &text);
};
class C63_HItem { public: int ID; C63_Item *operator->() const; };	// NOTE: placeholder (HItem)
struct C63_Entity2 { int getFaction(); void *getTarget(); };	// NOTE: placeholder (Entity)
class C63_HEntity { public: int ID; C63_HEntity(); C63_Entity2 *operator->() const; };	// NOTE: placeholder (HEntity)
struct C63_Squad { vector<C63_HEntity> *getMembers(); };	// NOTE: placeholder (folded getter getFore)
class C63_HSquad { public: int ID; C63_HSquad(); C63_Squad *get230() const; };	// NOTE: placeholder
struct C63_Marker { char pad0[8]; C63_Pos f8; void unknown6c20b0(int type, C63_Pos &p, int a); };	// NOTE: placeholder
class C63_HMarker { public: int ID; C63_HMarker(); C63_Marker *operator->() const; };	// NOTE: placeholder
struct C63_Map	// NOTE: placeholder (Map/BS at 0xcefc4c)
{
	int unknown463e50();
	C63_HSquad unknown463890(int type);
	int unknown735c80();
	int unknown735e70(bool a);
	void unknown464e30(C63_HItem item);
	int unknown4644d0();
	void unknown736120(bool a);
	bool unknown464550();
	vector< vector<C63_HMarker> > &unknown463ec0();
	vector<C63_Pos> *unknown464510();
	bool isVisible(C63_Pos &p);
};
struct C63_Hints { bool showOnce(int id, bool enabled, const string *text, bool repeat, bool flag); C63_HMarker createC(); };	// NOTE: placeholder (0xcefaa8)
struct C63_Info { bool isHidden(); void unknown8b4500(C63_HEntity e, C63_HProp a, C63_HProp b, C63_Pos *p, int c, bool d); };	// NOTE: placeholder (CInfo)
struct C63_ItemUI { void unknown4aee10(C63_HItem item); };
struct C63_CMap { void updatePredictedExplosion(); bool unknown808de0(int type); };	// NOTE: placeholder (CMap)
struct C63_PlayerData { void unknown77fbc0(int type); };
struct C63_GameData { bool unknown46f4b0(int a); bool isFlagEnabledB(); };
class C63_Phrase { public: C63_Phrase(int index, string *a, string *b, string *c, C63_HProp d, C63_HProp e); char pad0[0x20]; };	// NOTE: placeholder (OpS2_PhraseTextA)
struct C63_MsgLog { void add(C63_Phrase *phrase); };	// NOTE: placeholder (CInterfaceMsg)
void c63_message7b1750(int type, const string *a, const string *b, int c, C63_HProp d, C63_HProp e, int f);	// NOTE: placeholder name (opW9_unknown7b1750)

extern C63_Hints *c63_cefaa8;	// NOTE: placeholder names below
extern C63_Map *c63_cefc4c;
extern C63_Info *c63_cec118;
extern C63_ItemUI *c63_cec11c;
extern C63_CMap *c63_cec054;
extern C63_PlayerData c63_cf45d8;
extern C63_GameData c63_d1e860;
extern C63_MsgLog *c63_cec0f4;
extern C63_HEntity c63_cf64fc;
extern const char c63_empty_b953cd[];

class C63_Entity	// NOTE: placeholder (Entity)
{
public:
	char pad0[4];
	C63_HEntity f4;

	bool isPlayer();
	bool unknown5e3830();
	bool activateItem_64da50(C63_HItem item);
};

bool C63_Entity::activateItem_64da50(C63_HItem item)
{
	if (isPlayer())
	{
		if (item->getNestedField() == 13)
			c63_cefaa8->showOnce(33,true,0,0,0);
		if (OpT8b_Fn9daf80(26,item->getNestedField(),30))
			c63_cefaa8->showOnce(40,true,0,0,0);
		if (item->unknown4580c0() >= 1)
			c63_cefaa8->showOnce(41,true,0,0,0);
		if (item->unknown457f90() == 119 && item->getNestedField() < 26)
			c63_cefaa8->showOnce(42,true,0,0,0);
		if (item->unknown457df0() >= 10.0)
			c63_cefaa8->showOnce(51,true,&item->unknown571db0(false,false),0,0);
	}
	item->setActive(true);
	if (isPlayer() && c63_cefc4c->unknown463e50())
	{
		if (!c63_cec118->isHidden())
			c63_cec118->unknown8b4500(f4,C63_HProp(),C63_HProp(),&C63_Pos(-1),0,0);
		c63_cec11c->unknown4aee10(item);
		if (item->getDef()->f1a0 != 0)
			c63_cec054->updatePredictedExplosion();
		switch (item->unknown457f90())
		{
			case 10:
				c63_cf45d8.unknown77fbc0(112);
				return c63_cec054->unknown808de0(1);
			case 11:
				return c63_cec054->unknown808de0(2);
			case 12:
				return c63_cec054->unknown808de0(3);
			case 13:
				return c63_cec054->unknown808de0(4);
			case 14:
				return c63_cec054->unknown808de0(5);
			case 15:
				return c63_cec054->unknown808de0(32);
			case 16:
				return c63_cec054->unknown808de0(6);
			case 17:
				return c63_cec054->unknown808de0(7);
			case 18:
				return c63_cec054->unknown808de0(8);
			case 20:
				return c63_cec054->unknown808de0(9);
			case 22:
			case 23:
				if (c63_d1e860.unknown46f4b0(1))
				{
					int center = 0;
					vector<vector<C63_HEntity> *> v0ec;
					v0ec.push_back(c63_cefc4c->unknown463890(3).get230()->getMembers());
					v0ec.push_back(c63_cefc4c->unknown463890(4).get230()->getMembers());
					for (unsigned int col = 0; col < v0ec.size(); col++)
					{
						for (unsigned int cols = 0; cols < v0ec[col]->size(); cols++)
						{
							if (v0ec[col]->at(cols)->getFaction() == 4 && !v0ec[col]->at(cols)->getTarget())
								center++;
						}
					}
					int adj = 0;
					if (item->unknown457f90() == 22)
						adj = c63_cefc4c->unknown735c80();
					else
						adj = c63_cefc4c->unknown735e70(true);
					if (center != 0)
					{
						c63_message7b1750(103,&opw8_countString(center,"Hauler"),&intToString(adj),0,C63_HProp(),C63_HProp(),0);
						if (c63_cf64fc.operator->() != 0)
							c63_cf45d8.unknown77fbc0(118);
					}
					else
						c63_cec0f4->add(new C63_Phrase(102,0,0,0,C63_HProp(),C63_HProp()));
				}
				return false;
			case 24:
				return c63_cec054->unknown808de0(10);
			case 25:
				return c63_cec054->unknown808de0(11);
			case 26:
				return c63_cec054->unknown808de0(12);
			case 28:
				return c63_cec054->unknown808de0(13);
			case 30:
				opR1d_4541b0(84,0,0);
				return true;
			case 85:
			case 86:
				return c63_cec054->unknown808de0(14);
			case 89:
				return unknown5e3830();
			case 90:
				return c63_cec054->unknown808de0(15);
			case 106:
				return c63_cec054->unknown808de0(16);
			case 93:
				return c63_cec054->unknown808de0(17);
			case 94:
				return c63_cec054->unknown808de0(18);
			case 95:
				return c63_cec054->unknown808de0(19);
			case 96:
				return c63_cec054->unknown808de0(20);
			case 55:
				return c63_cec054->unknown808de0(21);
			case 56:
				return c63_cec054->unknown808de0(22);
			case 70:
				return c63_cec054->unknown808de0(23);
			case 71:
				return c63_cec054->unknown808de0(24);
			case 72:
				return c63_cec054->unknown808de0(25);
			case 152:
				return c63_cec054->unknown808de0(item->unknown457fb0() + 28);
			case 176:
				return c63_cec054->unknown808de0(37);
			case 177:
				return c63_cec054->unknown808de0(38);
			case 186:
				return c63_cec054->unknown808de0(33);
			case 189:
				c63_cefc4c->unknown464e30(item);
				return c63_cec054->unknown808de0(34);
			case 199:
				item->unknown458700(string(c63_empty_b953cd));
				return c63_cec054->unknown808de0(35);
			case 201:
				return c63_cec054->unknown808de0(36);
			case 210:
				if (!c63_d1e860.isFlagEnabledB())
					c63_cec0f4->add(new C63_Phrase(105,0,0,0,C63_HProp(),C63_HProp()));
				else
				{
					int center = c63_cefc4c->unknown4644d0();
					if (center != 0)
					{
						c63_message7b1750(104,&opw8_countString(center,"squad identifier"),0,0,C63_HProp(),C63_HProp(),0);
						c63_cefc4c->unknown736120(true);
						if (c63_cefc4c->unknown464550())
						{
							vector<C63_HMarker> &col = c63_cefc4c->unknown463ec0()[17];
							vector<C63_Pos> *cols = c63_cefc4c->unknown464510();
							for (unsigned int current = 0; current < cols->size(); current++)
							{
								if (!c63_cefc4c->isVisible((*cols)[current]))
								{
									for (unsigned int distanceSq = 0; distanceSq < col.size(); distanceSq++)
									{
										if (col[distanceSq]->f8.test((*cols)[current]))
											goto next;
									}
									col.push_back(c63_cefaa8->createC());
									col.back()->unknown6c20b0(17,(*cols)[current],-1);
								}
							next:;
							}
						}
					}
					else
					{
						string col = "No squad identifiers";
						c63_message7b1750(104,&col,0,0,C63_HProp(),C63_HProp(),0);
					}
				}
				return false;
		}
	}
	return false;
}
