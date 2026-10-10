// team_d_108: Group::addMember (0x671280; callers Entity::changeFaction, BS::placeEntity, BS::initilize and
// others): adds a robot to the group, registers derelict-type members with the map and gives
// numbered names ("<name> <depth><letter>") to fresh members of the first two group types; also tracks stats.
// NOTE: class layouts are partial; names other than addMember are placeholders.
#include <string>
#include <vector>
using namespace std;

string intToString(int value);	// 0x4051f0
bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (in range)

class Entity;

class HEntity
{
public:
	int ID;
	Entity *operator->() const;
};

struct EntityData108	// NOTE: placeholder name and layout
{
	int		type;		// +0x00
	char	pad004[0x1ac - 4];
	string	name;		// +0x1ac
};

struct EntityEffect;

class Entity
{
public:
	void unknown5dc750(int groupID);	// NOTE: placeholder name
	int getAiType();
	int getFaction();
	EntityData108 *getData108();	// NOTE: placeholder name (folded getter, +0x08)
	string *getName108();			// NOTE: placeholder name (folded getter, +0x0c)
	EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	void unknown45b070(const string &name);	// NOTE: placeholder name
	int getWidth108();				// NOTE: placeholder name (folded getter Array2D::getWidth)
};

class BS
{
public:
	void opw3_unknown72e5e0(HEntity e, int a, bool flag);	// NOTE: placeholder name
};
extern BS *world108_cefc4c;	// NOTE: placeholder name

class GameData108	// NOTE: placeholder name (GameData at 0xd1e860)
{
public:
	int getDepthIndex();	// NOTE: placeholder name (current depth)
};
extern GameData108 gameData108_d1e860;	// NOTE: placeholder name
extern vector<int> nameCounts108_cf4b24;	// NOTE: placeholder name

class Stats108	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	vector<int>	*current;

	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern Stats108 stats108_d2c658;	// NOTE: placeholder name

class PlayerData108	// NOTE: placeholder name (PlayerData at 0xcf45d8)
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern PlayerData108 playerData108_cf45d8;	// NOTE: placeholder name

class Group	// NOTE: placeholder layout
{
public:
	int				id;			// +0x00
	char			pad04[4];
	int				type;		// +0x08
	vector<HEntity>	members;	// +0x0c
	char			pad1c[0x28 - 0x1c];
	bool			unknown28;	// +0x28

	void addMember(HEntity e, bool flag);
};

void Group::addMember(HEntity e, bool flag)
{
	members.push_back(e);
	e->unknown5dc750(id);
	if (type == 0)
		world108_cefc4c->opw3_unknown72e5e0(e,0,flag);
	if (type <= 1 && e->getAiType() == 1 && !flag && e->getFaction() != 0xa && e->getFaction() != 0xb && *e->getName108() == e->getData108()->name)
	{
		EntityData108 *data = e->getData108();
		string name(data->name.begin() + 5,data->name.end());
		if (e->getFaction() == 0x1b || e->getFaction() == 0x47 || e->getFaction() == 0x48)
			name = data->name;
		name += " " + intToString(gameData108_d1e860.getDepthIndex());
		nameCounts108_cf4b24[data->type]++;
		int count = nameCounts108_cf4b24[data->type];
		if (count <= 0x1a)
			name += (char)(count + 0x60);
		else
			name += "*" + intToString(count);
		if (e->unknown45ac40(0x7b))
			name.insert(0,"Mastered ");
		e->unknown45b070(name);
	}
	if (OpT8b_Fn9daf80(1,type,2) && e->getFaction() != 0)
	{
		stats108_d2c658.add4729d0(0x37d,1,"",e->getWidth108());
		if ((*stats108_d2c658.current)[0x37d] == 0x4b)
			playerData108_cf45d8.unknown77fbc0(0xc8);
	}
	if (e->getFaction() == 0x14)
		unknown28 = true;
}
