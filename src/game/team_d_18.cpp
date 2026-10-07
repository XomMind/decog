// team_d_18: Zionmind::spawnDispatchGroup (0x6bf450).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;
};

class HEntity;

class EntityAI
{
public:
	void setFollowEntity(HEntity followEntity_, int followParam_);	// 0x5b2f80
};

class Entity
{
public:
	EntityAI *getAI();						// 0x45b590
	void unknown45b070(const string &name);	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool isNull() const;
	Entity *operator->() const;
};

struct EntityRecord	// NOTE: placeholder name
{
	int		unknown00;
	string	name;		// +4, NOTE: placeholder name
	char	pad20[0x2c - 0x20];
	string	tag;		// +0x2c, NOTE: placeholder name
};

struct DispatchDef	// NOTE: placeholder name
{
	int		type;		// NOTE: placeholder name
	string	label;		// +4, NOTE: placeholder name
	int		count;		// +0x20, NOTE: placeholder name
};

class BS
{
public:
	HEntity getPlayer();	// 0x4630f0
	HEntity placeEntity(EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
};
extern BS *world;

class GameData	// NOTE: placeholder name (0xd1e860)
{
public:
	const string &getEntryText(const string &key);	// NOTE: placeholder name (0x46f6d0)
};
extern GameData gameData_d1e860;	// NOTE: placeholder name
extern string dispatchTypeNames_d29af8[];	// NOTE: placeholder name

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
void logError(string location, string message);	// NOTE: placeholder name

class Zionmind
{
public:
	void spawnDispatchGroup(const Point &pos, EntityRecord *record, int mode, DispatchDef *def, vector<HEntity> *out);
};

void Zionmind::spawnDispatchGroup(const Point &pos, EntityRecord *record, int mode, DispatchDef *def, vector<HEntity> *out)
{
	HEntity entity;
	out->clear();
	if (mode != 2 && stringToInt(gameData_d1e860.getEntryText("usedCoreResetMatrix_g")) && record->tag.find("Z-",0) != string::npos && mode != 0)
		mode = 1;
	for (int i = 0; i < def->count; i++)
	{
		entity = world->placeEntity(record,pos,mode,false,0x22,0xe,false);
		if (entity.isNull())
		{
			logError("Zionmind::spawnDispatchGroup()","Could not place " + record->name + " for " + dispatchTypeNames_d29af8[def->type]);
			break;
		}
		if (i == 0 && !def->label.empty())
			entity->unknown45b070(def->label);
		entity->getAI()->setFollowEntity(world->getPlayer(),1);
		out->push_back(entity);
	}
}
