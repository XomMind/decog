// op_bs_derelicts: BS::unknown6fdcb0 (0x6fdcb0), sets up the Warlord derelicts map: scatters loot, places the
// warning derelict, spawns the derelict groups, stamps the derelict prefab, and depending on the derelicts'
// readiness level damages them, adds extra derelicts and walls/triggers (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(int x_, int y_);	// 0x46ca20
	explicit Point(int v);	// 0x409990
	Point(const Point &p);	// 0x46ca50
	Point &operator=(const Point &p);	// 0x46ca50
	int randomInRange_40c130();	// NOTE: placeholder name
};

struct OpBSD_Rect	// NOTE: placeholder name (x, y, width, height)
{
	int x;
	int y;
	int w;
	int h;

	OpBSD_Rect(const Point &p);	// NOTE: placeholder name (0x40a7a0)
};

struct OpBSD_Area	// NOTE: placeholder name
{
	Point min;
	Point max;

	OpBSD_Area(int x1, int y1, int x2, int y2);	// 0x40b1e0
	void set(const OpBSD_Rect &r);	// NOTE: placeholder name (0x40b3a0)
	void set_40b360(const Point &p, int w, int h);	// NOTE: placeholder name
	void randomPoint_40be30(Point *out);	// NOTE: placeholder name
};

class RNG
{
public:
	bool chance(int percent);	// 0x406c90
	int rangeInt(float lo, float hi);	// 0x406d70
};
extern RNG rng;

struct OpQ5_U9db510	// NOTE: placeholder name
{
	int ID;
	string name;
};
struct OpQ5_U9d7de0	// NOTE: placeholder name
{
	int ID;
	string name;
};
template <class T> bool OpQ5_findByName(vector<T *> &list, const string &name, T *&out);	// NOTE: placeholder name
extern vector<OpQ5_U9db510 *> opBSD_effects_d2f0f8;	// NOTE: placeholder name
extern vector<OpQ5_U9d7de0 *> opBSD_talks_d2c408;	// NOTE: placeholder name

struct OpBSD_Effect	// NOTE: placeholder name (8-byte effect record, ctor folded with Point(int,int))
{
	OpQ5_U9db510 *type;
	int value;

	OpBSD_Effect(OpQ5_U9db510 *type_, int value_);	// 0x46ca20
};

// NOTE: defined here (not throw()) so LTCG proves it nothrow, as in the exe (extra slot around new, no EH state)
OpBSD_Effect::OpBSD_Effect(OpQ5_U9db510 *type_, int value_)
{
	type = type_;
	value = value_;
}

class Item
{
public:
	int getIntegrity_9b6bf0();	// NOTE: placeholder name (folded getter)
	void setIntegrity_450460(int value);	// NOTE: placeholder name (folded setter)
};
class HItem
{
public:
	int ID;
	Item *operator->() const;	// 0x9b65b0
};

class HEntity;
class Entity
{
public:
	const Point &getPosition();	// 0x45a4a0
	vector<HItem> *getInventoryList();	// 0x45ab00
	void unknown45b340(OpBSD_Effect *effect);	// NOTE: placeholder name
	void unknown6395d0(OpQ5_U9d7de0 *talk, bool flag);	// NOTE: placeholder name
	void unknown631a20(HEntity e, bool flag);	// NOTE: placeholder name
	void unknown637bb0();	// NOTE: placeholder name
	int unknown5ca260();	// NOTE: placeholder name
	void unknown5dea60(int amount, bool linked);	// NOTE: placeholder name
	void unknown5fd900(int level, int duration);	// NOTE: placeholder name
};
class HEntity
{
public:
	int ID;
	HEntity();	// 0x9b6590
	bool isValid() const;	// 0x9b65e0
	Entity *operator->() const;	// 0x9b6570
};
class HProp
{
public:
	int ID;
	HProp();	// 0x9b6590
};

class Cell
{
public:
	bool isPassableFor(HEntity e);	// 0x66ab30
	bool isOpen();	// NOTE: placeholder name (0x4550b0)
	HEntity getEntity();	// 0x45d250
	void unknown45df90(struct CellEffect *effect);	// NOTE: placeholder name
	void unknown45e110(bool a, bool b, HProp prop);	// NOTE: placeholder name
};
class OpBSD_Grid	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **at(int x, int y);	// 0x9ceda0
	Cell **at(Point &p);	// 0x9ced70
	void getRandom_9cf0c0(Point *out);	// NOTE: placeholder name
};
extern OpBSD_Grid opBSD_cells_cfd44c;	// NOTE: placeholder name

class OpBSD_Layer	// NOTE: placeholder name (prefab art layer)
{
public:
	int getWidth();	// NOTE: placeholder name (0x9fcd80, folded getter)
	int getHeight();	// NOTE: placeholder name (0x9b8f00, folded getter)
};
class TeamA22_ArtLayers	// NOTE: placeholder name (prefab art layers)
{
public:
	void rotate_447010(bool rotateGlyphs);	// NOTE: placeholder name
	void flipHorizontal_447840(bool mirrorGlyphs);	// NOTE: placeholder name

	vector<OpBSD_Layer *> layers;
};
struct OpBSD_Prefab	// NOTE: placeholder name (OpB_ImageRecord)
{
	TeamA22_ArtLayers	image;
	string				name;
	string				file;
	int					unknown48;
	int					unknown4c;
	Point				offset;
	int					rotation;	// NOTE: placeholder name
	bool				unknown5c;

	OpBSD_Prefab();	// 0x448c00
	~OpBSD_Prefab();	// 0x4c1430
	void operator=(const OpBSD_Prefab &prefab);	// 0x448de0
};
extern vector<OpBSD_Prefab *> opBSD_prefabs_d161c4;	// NOTE: placeholder name

struct OpBSD_MapRecord	// NOTE: placeholder name
{
	char			pad00[0x20];
	int				unknown20;
	char			pad24[0xb8 - 0x24];
	bool			flippable;	// NOTE: placeholder name
	float			unknownbc;
	bool			unknownc0;
	vector<unsigned int>	prefabs;	// 0xc4, NOTE: placeholder name
};
extern vector<OpBSD_MapRecord *> opBSD_maps_d21afc;	// NOTE: placeholder name
unsigned int opBSD_randomIndex(vector<unsigned int> &v);	// NOTE: placeholder name (OpU8a_randomRec)
extern int opBSD_rotations_bb8370[];	// NOTE: placeholder name

template <class T> class OpR5h_WL	// NOTE: placeholder name (weighted list)
{
public:
	OpR5h_WL() throw();	// 0x9bab50
	OpR5h_WL(const int *w, int count);	// 0x9ba790
	~OpR5h_WL();	// 0x700dd0
	void add(T value, int weight);	// 0x9ba310
	T &pick();	// 0x9ba470

	vector<T> values;
	vector<int> weights;
	int total;
};
extern int opBSD_levelWeights_b93674[];	// NOTE: placeholder name
extern OpR5h_WL<int> opBSD_loot_d31700;	// NOTE: placeholder name

struct OpBSD_Machine	// NOTE: placeholder name
{
	int getDepth();	// NOTE: placeholder name (0x46ed20)
};
class OpBSD_HMachine	// NOTE: placeholder name
{
public:
	int ID;
	OpBSD_Machine *operator->() const;	// 0x9b7910
};
extern OpBSD_HMachine opBSD_node_d1e888;	// NOTE: placeholder name

class OpBSD_GameData	// NOTE: placeholder name (GameData at 0xd1e860)
{
public:
	void setEntryText(const string &key, const string &text);	// 0x46f700
};
extern OpBSD_GameData opBSD_gameData;	// NOTE: placeholder name

extern int opBSD_level_d1eae0;	// NOTE: placeholder name
extern int opBSD_d1eae4;	// NOTE: placeholder name
extern OpBSD_Area opBSD_area_d1eae8;	// NOTE: placeholder name
extern bool opBSD_d1e880;	// NOTE: placeholder name
extern bool opBSD_d257eb;	// NOTE: placeholder name
extern Point opBSD_d22310;	// NOTE: placeholder name
extern Point opBSD_d21e40;	// NOTE: placeholder name

struct EntityRecord;
struct ItemDef;
struct ItemType;
void opV3b_unknown6fdab0(struct ItemType *type);	// NOTE: placeholder name
HEntity teamb_spawnRandom6fd950(EntityRecord *record, int groupIndex, bool nearPlayer);	// NOTE: placeholder name
void OpQ5_eraseStep(vector<Point> &v, int &index);	// NOTE: placeholder name (0x9d7300)
Point OpU8a_randomPoint(vector<Point> &v);	// NOTE: placeholder name (0x9d5350)
bool opS2_logPhrase_5141b0(int id, const string *a, const string *b, const string *c, HEntity subject, const Point *at);	// NOTE: placeholder name

class BS	// NOTE: placeholder layout
{
public:
	void unknown6fdcb0();
	ItemDef *selectRandomItemOfRating(int level, int mode, int chanceType, int rating, int category, int unknown, int attempt);	// 0x6c40e0
	EntityRecord *selectRobotOfClass(int a, int b, bool c, bool d);	// NOTE: placeholder name
	HEntity placeEntity(EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);	// 0x6c58c0
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name (0x71c150)
	void unknown6c65a0(HEntity e, const string &text, int value);	// NOTE: placeholder name
	bool unknown6c6b90(const Point &p, const string &type, int a, int b);	// NOTE: placeholder name
	void unknown6cd110(OpBSD_Prefab &prefab, int a, bool b, float c);	// NOTE: placeholder name

	char	pad00[0x66c];
	HEntity	target;	// 0x66c, NOTE: placeholder name
};
extern BS *world;	// NOTE: placeholder name (0xcefc4c)

void BS::unknown6fdcb0()	// NOTE: placeholder name
{
	OpR5h_WL<int> lvlWeights(opBSD_levelWeights_b93674,5);
	int readiness = lvlWeights.pick();
	opBSD_level_d1eae0 = readiness;
	int depthIndex = opBSD_node_d1e888->getDepth();
	OpR5h_WL<int> ratings;
	if (depthIndex < 10)
		ratings.add(depthIndex,10);
	if (depthIndex + 1 < 10)
		ratings.add(depthIndex + 1,20);
	if (depthIndex + 2 < 10)
		ratings.add(depthIndex + 2,50);
	if (depthIndex + 3 < 10)
		ratings.add(depthIndex + 3,20);
	for (int n = opBSD_d22310.randomInRange_40c130(); n > 0; n--)
	{
		ItemType *type = (ItemType *)selectRandomItemOfRating(ratings.pick(),1,0,0x1f,0x12,0x2a,0);
		if (type)
			opV3b_unknown6fdab0(type);
	}
	if (rng.chance(10))
	{
		for (int m = opBSD_d21e40.randomInRange_40c130(); m > 0; m--)
			opV3b_unknown6fdab0((ItemType *)opBSD_loot_d31700.pick());
	}
	EntityRecord *entityRecord;
	OpQ5_U9d7de0 *talk;
	if (opBSD_d1e880 && (!opBSD_d257eb || (readiness <= 2 && rng.chance(20))))
	{
		opBSD_d257eb = true;
		entityRecord = selectRobotOfClass(3,0x10,false,true);
		if (entityRecord)
		{
			Point pos = target->getPosition();
			while ((*opBSD_cells_cfd44c.at(pos.x,pos.y + 1))->isPassableFor(HEntity()))
				pos.y++;
			HEntity e = placeEntity(entityRecord,pos,9,true,0x22,0xe,false);
			if (e.isValid())
			{
				OpQ5_findByName(opBSD_talks_d2c408,"WAS_Derelict_Warning",talk);
				if (talk)
					e->unknown6395d0(talk,false);
				OpQ5_U9db510 *effect;
				OpQ5_findByName(opBSD_effects_d2f0f8,"ENC_WAS_DERELICT",effect);
				if (effect)
					e->unknown45b340(new OpBSD_Effect(effect,1));
			}
		}
	}
	entityRecord = selectRobotOfClass(1,0x1d,false,true);
	vector<HEntity> wrecks;
	for (int i = 0; i < 6; i++)
		wrecks.push_back(teamb_spawnRandom6fd950(entityRecord,5,false));
	opBSD_d1eae4 = readiness > 1 ? 0 : 15;
	opBSD_area_d1eae8.set(Point(-1));
	opBSD_gameData.setEntryText("wasUnreadyDerelictsAttacked_g","0");
	if (readiness == 0)
		return;
	vector<Point> spots;
	spots.push_back(Point(0x1a,0x18));
	spots.push_back(Point(0x26,0x18));
	spots.push_back(Point(0x32,0x18));
	spots.push_back(Point(0x3e,0x18));
	spots.push_back(Point(0x1a,0x40));
	spots.push_back(Point(0x26,0x40));
	spots.push_back(Point(0x32,0x40));
	spots.push_back(Point(0x3e,0x40));
	for (int i = 0; i < spots.size(); i++)
	{
		if (!(*opBSD_cells_cfd44c.at(spots[i]))->isOpen())
			OpQ5_eraseStep(spots,i);
	}
	if (spots.empty())
		return;
	Point chosen = OpU8a_randomPoint(spots);
	OpBSD_MapRecord *encounter = opBSD_maps_d21afc[(readiness >= 3) + 0x5a];
	OpBSD_Prefab localPrefab;
	localPrefab = *opBSD_prefabs_d161c4[opBSD_randomIndex(encounter->prefabs)];
	if (encounter->flippable && rng.chance(50))
		localPrefab.image.flipHorizontal_447840(true);
	localPrefab.rotation = 2;
	if (chosen.y == 0x40)
	{
		localPrefab.rotation = 0;
		for (int i = 0; i < opBSD_rotations_bb8370[localPrefab.rotation]; i++)
			localPrefab.image.rotate_447010(true);
	}
	localPrefab.unknown5c = false;
	localPrefab.offset = chosen;
	localPrefab.offset.x += rng.rangeInt(-2.0f,2.0f);
	if (chosen.y == 0x18)
		localPrefab.offset.y -= localPrefab.image.layers.front()->getHeight() + 1;
	else
		localPrefab.offset.y += 9;
	unknown6cd110(localPrefab,encounter->unknown20,encounter->unknownc0,encounter->unknownbc);
	if (readiness == 1)
		opBSD_area_d1eae8.set_40b360(localPrefab.offset,localPrefab.image.layers.front()->getWidth(),localPrefab.image.layers.front()->getHeight());
	if (readiness >= 3)
	{
		for (unsigned int i = 0; i < wrecks.size(); i++)
		{
			if (wrecks[i].operator->())
			{
				vector<HItem> *inv = wrecks[i]->getInventoryList();
				for (unsigned int j = 0; j < inv->size(); j++)
					(*inv)[j]->setIntegrity_450460((*inv)[j]->getIntegrity_9b6bf0() * rng.rangeInt(25.0f,90.0f) / 100);
				if (rng.chance(75))
				{
					wrecks[i]->unknown631a20(HEntity(),false);
					wrecks[i]->unknown637bb0();
				}
				else
				{
					wrecks[i]->unknown5dea60(wrecks[i]->unknown5ca260() * rng.rangeInt(40.0f,60.0f) / 100,false);
					wrecks[i]->unknown5fd900(8,0);
					unknown6c65a0(wrecks[i],"WAS_Compactor_Restart",0);
				}
			}
		}
		Point spot;
		entityRecord = selectRobotOfClass(3,0x10,true,true);
		if (entityRecord)
		{
			for (int attempt = 0, num = 0; attempt < 50 && num < 5; attempt++)
			{
				opBSD_cells_cfd44c.getRandom_9cf0c0(&spot);
				if (findPlaceableNear(spot,spot,1))
				{
					HEntity e = placeEntity(entityRecord,spot,9,true,0,0xe,false);
					if (e.isValid())
					{
						e->unknown5dea60(e->unknown5ca260() * rng.rangeInt(10.0f,40.0f) / 100,false);
						e->unknown5fd900(8,0);
						vector<HItem> *items = e->getInventoryList();
						for (unsigned int j = 0; j < items->size(); j++)
							(*items)[j]->setIntegrity_450460((*items)[j]->getIntegrity_9b6bf0() * rng.rangeInt(25.0f,90.0f) / 100);
					}
					num++;
				}
			}
		}
		if (readiness == 3)
		{
			OpR5h_WL<int> types;
			types.add(0x10,0x2d);
			types.add(0xd,0x19);
			types.add(0x11,5);
			types.add(0x12,5);
			types.add(8,10);
			types.add(0x16,10);
			OpQ5_U9db510 *effectRec;
			OpQ5_findByName(opBSD_effects_d2f0f8,"ENC_WAS_DERELICTS",effectRec);
			Point origin = target->getPosition();
			OpBSD_Area bounds(origin.x - 4,origin.y - 4,origin.x + 4,origin.y + 4);
			bool spoken = false;
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					bounds.randomPoint_40be30(&spot);
					if (findPlaceableNear(spot,spot,1))
						goto placed;
				}
				continue;
placed:
				entityRecord = selectRobotOfClass(3,types.pick(),true,true);
				if (entityRecord)
				{
					HEntity e = placeEntity(entityRecord,spot,9,true,1,0xe,false);
					if (e.isValid())
					{
						if (effectRec)
							e->unknown45b340(new OpBSD_Effect(effectRec,1));
						if (!spoken)
						{
							unknown6c65a0(e,"WAS_Derelicts_Victory",0);
							spoken = true;
						}
					}
				}
			}
		}
		else
			do { opS2_logPhrase_5141b0(0x188,NULL,NULL,NULL,HEntity(),NULL); } while (0);
		Point wallRow = chosen;
		if (chosen.y == 0x18)
			wallRow.y--;
		else
			wallRow.y += 8;
		for (int x = wallRow.x, y = wallRow.y; x < wallRow.x + 8; x++)
		{
			if ((*opBSD_cells_cfd44c.at(x,y - 1))->isOpen() && (*opBSD_cells_cfd44c.at(x,y + 1))->isOpen())
				(*opBSD_cells_cfd44c.at(x,y))->unknown45e110(false,true,HProp());
		}
	}
	else
	{
		Point p = chosen;
		if (chosen.y == 0x18)
			p.y -= 2;
		else
			p.y += 9;
		OpQ5_findByName(opBSD_talks_d2c408,readiness == 1 ? "WAS_Derelicts_Unready" : "WAS_Derelicts_Ready",talk);
		if (talk)
		{
			for (int x = p.x, n = 0; x < p.x + 8; x++)
			{
				if ((*opBSD_cells_cfd44c.at(x,p.y))->getEntity().isValid())
				{
					if (n == 1)
					{
						(*opBSD_cells_cfd44c.at(x,p.y))->getEntity()->unknown6395d0(talk,false);
						break;
					}
					else
						n++;
				}
			}
		}
		if (readiness == 2)
		{
			OpQ5_U9d7de0 *trigger;
			OpQ5_findByName(opBSD_talks_d2c408,"WAS_Derelicts_Trigger",trigger);
			if (trigger)
			{
				Point trigPos = chosen;
				trigPos.x += 4;
				if (chosen.y != 0x18)
					trigPos.y += 7;
				world->unknown6c6b90(trigPos,"",(int)trigger,-1);
				Point wallRow = chosen;
				if (chosen.y == 0x18)
					wallRow.y--;
				else
					wallRow.y += 8;
				OpQ5_U9db510 *wallType;
				OpQ5_findByName(opBSD_effects_d2f0f8,"ENC_WAS_DERELICTS_WALL",wallType);
				if (wallType)
				{
					for (int x = wallRow.x, y = wallRow.y; x < wallRow.x + 8; x++)
					{
						if ((*opBSD_cells_cfd44c.at(x,y - 1))->isOpen() && (*opBSD_cells_cfd44c.at(x,y + 1))->isOpen())
							(*opBSD_cells_cfd44c.at(x,y))->unknown45df90((CellEffect *)new OpBSD_Effect(wallType,1));
					}
				}
			}
		}
	}
}
