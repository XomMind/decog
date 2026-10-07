// team_b_04: game-logic helpers (0x500000-0x9affff) matched against COGMIND.exe (Beta 17.1), batch 2.
// NOTE: class layouts are partial; TeamB_* classes and unknownXXXXXX members are placeholder names.
#include <string>
#include <vector>
using namespace std;

class Prop;
class Entity;
class Group { public: int getValue9b4350() const; };	// NOTE: placeholder name (ICF'd getter)
class HGroup { public: int ID; HGroup(); Group *operator->() const; };	// 0x9b7250
class HEntity { public: int ID; HEntity(); Entity *operator->() const; bool operator==(HEntity other) const; };
class HProp { public: int ID; HProp(); Prop *operator->() const; };	// 0x9b64f0
struct Point { int x; int y; void set(int v); Point &operator=(const Point &p); };
class Entity
{
public:
	HGroup getGroup();	// 0x45a3f0
	int unknown5c7ff0(int value);	// NOTE: placeholder name
	const Point &getPosition();	// 0x45a4a0
};
class Map { public: int getTurn(); HEntity getPlayer(); };
extern Map *endObjA;	// 0xcefc4c

//==================================================================
// attack damage scaled by terrain/prop resistances
//==================================================================

struct TeamB_Base { char pad[0x20]; int resists[7]; };	// NOTE: placeholder layout
struct TeamB_Terrain { char pad[0x50]; TeamB_Base *base; };	// NOTE: placeholder layout
struct TeamB_PropData { char pad[0x60]; TeamB_Base *base; };	// NOTE: placeholder layout
struct TeamB_Attack { char pad[0x68]; int damage; int type; };	// NOTE: placeholder layout

class TeamB_Cell	// NOTE: placeholder name (map cell)
{
public:
	TeamB_Terrain *terrain;
	void unknown66dae0(int amount, int type, bool a, int b, int c, int d, HEntity e, int f);	// NOTE: placeholder name
	void applyAttack670150(TeamB_Attack *attack);
};

void TeamB_Cell::applyAttack670150(TeamB_Attack *attack)	// 0x670150
{
	unknown66dae0(attack->damage * (attack->type >= 7 ? 100 : terrain->base->resists[attack->type]) / 100, attack->type, false, 0, 0, 0, HEntity(), 0);
}

class TeamB_Prop	// NOTE: placeholder name (prop)
{
public:
	int ID;
	TeamB_PropData *data;
	bool unknown65f520(int a, int b, int c, int d, int e, HProp f, int g, int h, int i);	// NOTE: placeholder name
	void applyAttack665860(TeamB_Attack *attack);
};

void TeamB_Prop::applyAttack665860(TeamB_Attack *attack)	// 0x665860
{
	unknown65f520(attack->damage * (attack->type >= 7 ? 100 : data->base->resists[attack->type]) / 100, attack->type, 0, 0, 0, HProp(), 0, 0, 0);
}

//==================================================================
// remembered target (entity / position) record
//==================================================================

struct TeamB_TargetMemory	// NOTE: placeholder name/layout
{
	char pad[0x30];
	HEntity entity;
	int groupValue;
	bool flag;
	Point pos;
	HProp prop;
	int turn;
	void init873a50(HEntity e, bool f);
	bool getTarget872e40(HEntity e, Point &out);
};

bool TeamB_TargetMemory::getTarget872e40(HEntity e, Point &out)	// 0x872e40
{
	if (endObjA->getTurn() - turn <= 5)
	{
		if (entity.operator->() && !flag && e->unknown5c7ff0(groupValue) != 2)
		{
			out = entity->getPosition();
			return true;
		}
		else if (pos.x != -1 && prop.operator->())
		{
			out = pos;
			return true;
		}
	}
	return false;
}

void TeamB_TargetMemory::init873a50(HEntity e, bool f)	// 0x873a50
{
	entity = e;
	flag = f;
	if (entity.operator->())
		groupValue = entity->getGroup()->getValue9b4350();
	pos.set(-1);
	turn = endObjA->getTurn();
}

//==================================================================
// misc
//==================================================================

class TeamB_954b10 { public: TeamB_954b10(void *owner, int value); char pad[0x80]; };	// NOTE: placeholder name (ctor 0x954b10)
extern void *teamb_cec034;	// NOTE: placeholder name (0xcec034)
void teamb_create95a640(int value)	// NOTE: placeholder name (0x95a640)
{
	new TeamB_954b10(teamb_cec034,value);
}

class Item { public: int getType() const; HEntity getOwner(); };	// NOTE: placeholder names (0x44aec0, 0x457b50)
class HItem { public: int ID; Item *operator->() const throw(); };	// 0x9b65b0
class TeamB_7abf80	// NOTE: placeholder name (object at 0xcf4ac8)
{
public:
	void *ptr0;
	HItem item;
	char pad8[8];
	int value10;
	bool check7abf80();
};

bool TeamB_7abf80::check7abf80()	// 0x7abf80
{
	return ptr0 && !value10 && item.operator->() && item->getType() == 3 && item->getOwner() == endObjA->getPlayer();
}

class XConsole { public: virtual ~XConsole(); };
class Console : public XConsole { public: void animate(string name); };
extern Console *opx5e_cec078;	// NOTE: placeholder name
extern Console *opx5e_cec07c;	// NOTE: placeholder name
extern Console *opx5e_cec084;	// NOTE: placeholder name
extern Console *opx5e_cec088;	// NOTE: placeholder name
extern Console *opx5e_cec08c;	// NOTE: placeholder name
void teamb_animateHud964cb0(const string &name)	// NOTE: placeholder name (0x964cb0)
{
	opx5e_cec078->animate(name);
	opx5e_cec07c->animate(name);
	opx5e_cec084->animate(name);
	opx5e_cec088->animate(name);
	opx5e_cec08c->animate(name);
}

// NOTE: local names matter here: MSVC's stack layout follows them ("start"/"end" match the exe)
bool teamb_parenthesized900870(const string &text, string &inner)	// NOTE: placeholder name (0x900870)
{
	int start = text.find('(',0);
	if (start == string::npos)
		return false;
	int end = text.rfind(')',string::npos);
	if (end < start || end == string::npos)
		return false;
	inner.assign(text.begin() + start + 1,text.begin() + end);
	return true;
}
