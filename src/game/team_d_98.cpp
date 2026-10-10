// team_d_98: entity map label text 0x7fea30 (callers CMap::update and the entity label code in team_b_34.cpp,
// which declares it as teamb_getEntityLabel_7fea30): the upper-cased name, a "(L)" squad-leader tag, an
// optional integrity readout and a "p-" readout in game mode 0xb; prepended or appended depending on longForm.
// NOTE: class layouts are partial; member names are placeholders. The function keeps team_b_34's name so its
// declaration links to this definition.
#include <string>
using namespace std;

string intToString(int value);	// 0x4051f0
string OpR5f_toUpper_4083a0(const string &text);	// NOTE: placeholder name

class Entity;

class HEntity
{
public:
	int ID;
	Entity *operator->() const;
};

struct EntityData98	// NOTE: placeholder name and layout
{
	char	pad00[0x2c];
	string	name;	// +0x2c
};

struct Group98	// NOTE: placeholder name
{
	int getType();	// NOTE: folded getter (+0x08)
};

class HGroup
{
public:
	int ID;
	HGroup();
	Group98 *operator->();	// NOTE: OpC_Handle::get230
};

class Entity
{
public:
	string *getName98();			// NOTE: placeholder name (folded getter, +0x0c)
	EntityData98 *getData98();		// NOTE: placeholder name (folded getter, +0x08)
	int getFaction();
	HGroup getGroup();
	int unknown45a880();			// NOTE: placeholder name
	int getIntegrity98();			// NOTE: placeholder name (folded getter Sweep_490840::getField)
	bool unknown5d7df0();			// NOTE: placeholder name
	int unknown5d7e90();			// NOTE: placeholder name
};

extern string robotClassNames_d2f798[];

class GameData98	// NOTE: placeholder name (GameData at 0xd1e860)
{
public:
	bool unknown789580(HEntity e);	// NOTE: placeholder name
};
extern GameData98 gameData98_d1e860;	// NOTE: placeholder name

struct Squad98	// NOTE: placeholder name and layout
{
	int leader;	// NOTE: placeholder name
};

class Overmind98	// NOTE: placeholder name (Overmind at 0xcf6428)
{
public:
	Squad98 *unknown683310(HEntity e);	// NOTE: placeholder name
};
extern Overmind98 overmind98_cf6428;	// NOTE: placeholder name

class BS
{
public:
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
};
extern BS *world98_cefc4c;	// NOTE: placeholder name

extern bool flag98_d28dfb;	// NOTE: placeholder name
extern int opw8_cf462c;	// NOTE: placeholder name

int teamb_getEntityLabel_7fea30(HEntity e, bool full, string &out, bool longForm)
{
	out = OpR5f_toUpper_4083a0(full ? *e->getName98() : (!e->getData98()->name.empty() ? e->getData98()->name : robotClassNames_d2f798[e->getFaction()]));
	if (e->getGroup()->getType() == 3 && gameData98_d1e860.unknown789580(e))
	{
		Squad98 *squad = overmind98_cf6428.unknown683310(e);
		if (squad && squad->leader)
		{
			if (longForm)
				out += " (L)";
			else
				out.insert(0,"(L) ");
		}
	}
	if (flag98_d28dfb && world98_cefc4c->unknown4631f0(e) && e->unknown45a880() < 100)
	{
		if (longForm)
			out += " (" + intToString(e->getIntegrity98()) + ")";
		else
			out.insert(0,"(" + intToString(e->getIntegrity98()) + ") ");
	}
	if (opw8_cf462c == 0xb)
	{
		if (longForm)
			out += " * p-" + (e->unknown5d7df0() ? intToString(e->unknown5d7e90()) : string("N/A"));
		else
			out.insert(0,"p-" + (e->unknown5d7df0() ? intToString(e->unknown5d7e90()) : string("N/A")) + " * ");
	}
	return out.size();
}
