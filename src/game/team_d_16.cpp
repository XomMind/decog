// team_d_16: Overmind members (system reset, cargo dispatch, anti-infestation carrier, party redirection).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	int distanceTo(const Point &p) const;	// NOTE: placeholder name (PushGeometry::distanceTo)

	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor (0x46ca50)

	Point();	// 0x453b40
	Point(int v);	// 0x409990
	Point(int x_, int y_) throw();	// 0x46ca20
	Point(const Point &p) throw();	// 0x46ca50
	int randomInRange_40c130();
};

struct Area	// NOTE: placeholder layout
{
	Point min;
	Point max;

	Area();	// 0x40b100
};

class EntityAI
{
public:
	void unknown4593b0(const Point &p);	// NOTE: placeholder name
	int unknown9c3a90();	// NOTE: placeholder name (trivial getter)
	bool setPatrolRandom(Point p);
	void setUnknown451400(int value);	// NOTE: placeholder name (0x451400)
	void unknown459410(Area &area);	// NOTE: placeholder name
	int unknown9b4350();	// NOTE: placeholder name (trivial getter)
	void setFollowEntity(class HEntity followEntity_, int followParam_);	// 0x5b2f80
	void unknown4593d0(vector<Point> &path);	// NOTE: placeholder name
	int unknown5b4710(class HEntity e, int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown459540(const Point &p);	// NOTE: placeholder name
	void unknown459560(int value);	// NOTE: placeholder name (0x...)
	void setField4505b0(int value);		// NOTE: placeholder name (Sweep_4505b0::setField)
	void unknown459470(Area &area);		// NOTE: placeholder name
};

class Group	// NOTE: placeholder name
{
public:
	int unknown9b4350();	// NOTE: placeholder name (trivial getter)
	int unknown9c3a90();	// NOTE: placeholder name (trivial getter)
};

class HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	Group *operator->() const;
};

class Entity
{
public:
	Point &getPosition();	// 0x45a4a0
	EntityAI *getAI();		// 0x45b590
	int getAiType();		// 0x45a2a0
	void unknown45b340(Point *p);	// NOTE: placeholder name
	void unknown5fdab0();	// NOTE: placeholder name
	bool isPlayer();		// 0x5c7600
	class HItem26 unknown5d2380(int slot);	// NOTE: placeholder name
	int getFaction();		// 0x45a2c0
	int getSize();			// 0x45a360
	int getTarget();		// 0x45a760
	HGroup getGroup();		// 0x45a3f0
	bool unknown5d4490(class HEntity e);	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool isValid() const;
	bool isNull() const;
	Entity *operator->() const;
};

class Prop
{
public:
	int unknown9b4410();	// NOTE: placeholder name (trivial getter)
};

class HProp
{
	int ID;
public:
	HProp();
	bool isNull() const;
	bool isValid() const;
	Prop *operator->() const;
};

struct ExitInfo	// NOTE: placeholder name
{
	int unknown0;
	int type;	// +4, NOTE: placeholder name
};

class HExitInfo	// NOTE: placeholder name
{
	int ID;
public:
	ExitInfo *operator->() const;	// 0x9b7910
};

struct MapExit	// NOTE: placeholder name
{
	Point	pos;			// NOTE: placeholder name
	HExitInfo info;			// +8, NOTE: placeholder name
	bool	unknown0c;		// NOTE: placeholder name
	char	pad0d[0x14 - 0xd];
	HProp	prop;			// NOTE: placeholder name
};

struct EntityRecord;	// NOTE: placeholder name

class BS
{
public:
	HEntity getPlayer();	// 0x4630f0
	int getTurn();
	EntityRecord *selectRobotOfClass(int a, int b, bool c, bool d);	// NOTE: placeholder name
	void unknown715570(int radius, int *a, int *b);	// NOTE: placeholder name
	int unknown4638e0(int a, int b);	// NOTE: placeholder name
	bool unknown715a70();				// NOTE: placeholder name
	int unknown715730(int a);			// NOTE: placeholder name
	Point *unknown462f60(int index);	// NOTE: placeholder name
	class HItem27 unknown6c51d0(struct ItemType27 *type, HEntity entity, bool a, bool b);	// NOTE: placeholder name
	bool isVisible(MapExit *exit);
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name
	bool unknown7168e0(const Point &from, const Point &to, Entity *entity, vector<Point> *path);	// NOTE: placeholder name
	HEntity placeEntity(EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);

	char pad[0x10];
	vector<MapExit *> exits;	// +0x10, NOTE: placeholder name
};
extern BS *world;
extern EntityRecord *record_cefc08;	// NOTE: placeholder name

class Grid	// NOTE: placeholder name (0xcfd44c)
{
public:
	void getRect(const Point &p, int radius, Area &out);	// NOTE: placeholder name (0x9b4430)
};
extern Grid cells_cfd44c;	// NOTE: placeholder name

class MessageLog	// NOTE: placeholder name (0xcf1080)
{
public:
	void setUnknown(int value);	// NOTE: placeholder name (0x451400)
};
extern MessageLog messageLog_cf1080;	// NOTE: placeholder name

class ConsoleA	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA *consoleA_cec058;	// NOTE: placeholder name
class CLogMsgs
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern CLogMsgs *logMsgs_cec0b4;	// NOTE: placeholder name
extern bool option_d28fb0;	// NOTE: placeholder name

bool logMessage_5111e0(int id, const string &text, int a, int b, HProp c, HProp d, int e, int f);	// NOTE: placeholder name
void playSound_4541b0(int id, int a, int b);	// NOTE: placeholder name
void logWarning(string location, string message);	// NOTE: placeholder name (0x404e50)
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);

#define OPD_LOG(id,text) do { if (logMessage_5111e0(id,text,0,0,HProp(),HProp(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0)	// NOTE: placeholder macro
#define OPD_ALERT(sound,text) do { messageLog_cf1080.setUnknown(1); if ((sound) != -1 && !(option_d28fb0 && (sound) != 0 && (sound) != 1)) playSound_4541b0(sound,0,0); OPD_LOG(0x324,text); logMsgs_cec0b4->scrollToEnd(); } while (0)	// NOTE: placeholder macro (constant sound ids)
#define OPD_ALERT_EXPR(sound,text) do { messageLog_cf1080.setUnknown(1); if ((sound) >= 0 && (!option_d28fb0 || (sound) < 0x127 || (sound) > 0x12a)) playSound_4541b0(sound,0,0); OPD_LOG(0x324,text); logMsgs_cec0b4->scrollToEnd(); } while (0)	// NOTE: placeholder macro (computed sound ids)

class Party	// NOTE: placeholder layout
{
public:
	Party(int type, HEntity leader, int a, int b, int c);

	int		type;		// NOTE: placeholder name
	HEntity	leader;		// NOTE: placeholder name
	int		unknown08;	// NOTE: placeholder name
	char	pad0c[0x38 - 0xc];
};
extern string partyTypeNames_cf14d0[];
extern vector<EntityRecord *> entityRecords_d25de0;	// NOTE: placeholder name
template <class T> bool OpQ5_findByName(vector<T *> &list, const string &name, T *&out);	// NOTE: placeholder name
void OpV4c_Fn9d0690(int *value, int step, int low);	// NOTE: placeholder name
void logEvent_5141b0(int id, int a, int b, int c, HProp e, int d);	// NOTE: placeholder name
Point OpU8a_randomPoint(vector<Point> &v);	// NOTE: placeholder name (0x9d5350)	// NOTE: placeholder name
void logError(string location, string message);	// NOTE: placeholder name

struct DifficultySettings	// NOTE: placeholder name (0x28-byte records at 0xb939b0)
{
	int cargoChance;	// NOTE: placeholder name
	int pad04;
	int cargoCount;		// NOTE: placeholder name
	int pad[7];
};
extern DifficultySettings difficultySettings_b939b0[];	// NOTE: placeholder name

class GameData46f4b0	// NOTE: placeholder name (0xd1e860)
{
public:
	int getDepthIndex();	// NOTE: placeholder name
	const string &getEntryText(const string &key);	// NOTE: placeholder name (0x46f6d0)
	bool isFlagEnabledB();	// NOTE: placeholder name
};
extern GameData46f4b0 gameData_d1e860;	// NOTE: placeholder name

class HItem26	// NOTE: placeholder name
{
	int ID;
public:
	bool isValid() const;
};

struct ItemData27	// NOTE: placeholder name
{
	char pad[0x64];
	int unknown64;	// NOTE: placeholder name
};

class Item27	// NOTE: placeholder name
{
public:
	ItemData27 *getData();			// NOTE: placeholder name (trivial getter)
	void setUnknown(int value);		// NOTE: placeholder name
};

class HItem27	// NOTE: placeholder name
{
	int ID;
public:
	bool isValid() const;
	Item27 *operator->() const;
};

class RNG
{
public:
	bool chance(int percent);
	int rangeInt(float a, float b);
};
extern RNG rng;

class RolledValues	// NOTE: placeholder name (0xcefb48)
{
public:
	bool say(int ID, bool force, string name);
};
extern RolledValues *rolledValues_cefb48;	// NOTE: placeholder name

class Overmind
{
public:
	bool spawnAntiInfestationCarrier(const Point &target, const string &message);
	bool findCargoDispatchTarget(const Point &from, Point *out);
	int spawnCargoDispatch_68aba0();
	bool redirectParty(Party *party, const Point &target, HEntity e);
	int spawnResponseParty(int type, HEntity target, Point *area, Point *outAccess);
	bool findDispatchExit(Point *out, bool allowVisible, int minDistance, bool ignoreProps, const Point &from, Point **access, bool preferProps, bool ignoreUsed);	// NOTE: placeholder name
	void addParty(Party *party, Point *access);	// NOTE: placeholder name
	void unknown681810();	// NOTE: placeholder name
	void unknown681550();	// NOTE: placeholder name
	int unknown68a500(bool anywhere, Point *patrol, bool forced);	// NOTE: placeholder name
	int unknown6892c0(bool anywhere, Point *patrol, bool forced);	// NOTE: placeholder name
	bool unknown68c960(const Point &target);	// NOTE: placeholder name
	void loadZPartList(vector<int> &out, vector<int> &records);	// NOTE: placeholder name (Q-Series surgical utility parts)
	void unknown683e60(const Point &p, vector<vector<HEntity> > &out);	// NOTE: placeholder name
	int spawnInterceptParty(bool programmer, HEntity target, Point *area);	// NOTE: placeholder name (party type 9: Trackers or one Combat Programmer)
	int spawnCouplingParty(const Point &target);	// NOTE: placeholder name (party type 10: Programmer carrying items)
	void loadZWeaponList(vector<int> &out, int level);
	int unknown68bc80(int exitIndex, int type, const Point &target);	// NOTE: placeholder name
	int unknown686c60(const Point &target, int num, int recType, int recClass);	// NOTE: placeholder name
	bool unknown68fc40();	// NOTE: placeholder name
	void unknown6901e0(HEntity leader, int flag, int a, int b, const Point &p, int c, int d);	// NOTE: placeholder name
	int unknown68b9a0(vector<Point> &targets, bool repeat);	// NOTE: placeholder name
	void unknown681b70(HEntity killed, HEntity killer);	// NOTE: placeholder name
	bool unknown683380(HEntity e, int *kind);	// NOTE: placeholder name
	void unknown682420(int type, int amount);	// NOTE: placeholder name

	char pad[0x4c];
	int unknown4c;		// NOTE: placeholder name
	char pad50[0x84 - 0x50];
	int extraTrackers;		// NOTE: placeholder name
	char pad88[0x90 - 0x88];
	struct SurgicalSettings *surgical;	// +0x90, NOTE: placeholder name
	char pad94[0xbc - 0x94];
	int unknownbc;		// NOTE: placeholder name
	Point unknownc0;	// NOTE: placeholder name
	Point unknownc8;	// NOTE: placeholder name
	int unknownd0;		// NOTE: placeholder name
	char padd4[0x118 - 0xd4];
	vector<Point> usedExits;	// +0x118, NOTE: placeholder name
	int failedDispatches;	// NOTE: placeholder name
};

bool Overmind::spawnAntiInfestationCarrier(const Point &target, const string &message)
{
	EntityRecord *level = record_cefc08;
	Point pos;
	Point *index = NULL;
	if (!findDispatchExit(&pos,1,0,1,world->getPlayer()->getPosition(),&index,0,0))
	{
		logWarning("Overmind::spawnAntiInfestationCarrier()","No valid access point for spawning assault party");
		return false;
	}
	HEntity current = world->placeEntity(level,pos,3,false,0x22,0xe,false);
	if (current.isNull())
		return false;
	current->getAI()->setField4505b0(1);
	Area room;
	cells_cfd44c.getRect(target,0xf,room);
	current->getAI()->unknown459470(room);
	if (!message.empty())
		OPD_ALERT(0x129,message);
	addParty(new Party(7,current,-1,0,0),index);
	return true;
}

class Prop17	// NOTE: placeholder name
{
public:
	struct Data	// NOTE: placeholder name
	{
		char pad[0x28];
		int unknown28;			// NOTE: placeholder name
		char pad2c[0x40 - 0x2c];
		vector<int> markers;	// +0x40, NOTE: placeholder name
	};
	Data *unknown45cb30();	// NOTE: placeholder name (trivial getter)
};

class HProp17	// NOTE: placeholder name
{
	int ID;
public:
	Prop17 *operator->() const;
};

class Cell17	// NOTE: placeholder name
{
public:
	HProp17 getProp();	// 0x45d550
	void removeProp(bool keepTerrain, int cause);	// 0x66c100
};

class Grid17	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell17 **atPoint(Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
};
extern Grid17 cells17_cfd44c;	// NOTE: placeholder name

struct MarkerData	// NOTE: placeholder name
{
	char pad[0x140];
	int unknown140;	// NOTE: placeholder name
};

struct MarkerInfo	// NOTE: placeholder name
{
	char pad[0x10];
	int unknown10;	// NOTE: placeholder name
};

class Marker	// NOTE: placeholder name
{
public:
	MarkerData *unknown9c3a90();	// NOTE: placeholder name (trivial getter)
	MarkerInfo *unknown44cea0();	// NOTE: placeholder name (trivial getter)
	Point &getPosition();			// NOTE: placeholder name (0x4184d0)
};

class HMarker17	// NOTE: placeholder name
{
	int ID;
public:
	Marker *operator->() const;
};
extern vector<vector<HMarker17> > markerLists_d20248;	// NOTE: placeholder name

class World17	// NOTE: placeholder name (0xcefc4c)
{
public:
	vector<vector<Point> > *getZones();				// NOTE: placeholder name (trivial getter 0x459070)
	vector<vector<HMarker17> > *getMarkerLists();	// NOTE: placeholder name (0x463be0)
};
extern World17 *world17_cefc4c;	// NOTE: placeholder name

void OpU8a_removeEntity(vector<HMarker17> &v, HProp17 p);	// NOTE: placeholder name

void Overmind::unknown681810()
{
	OPD_ALERT(-1,string("ALERT: Performing unscheduled system reset."));
	vector<vector<Point> > *zones = world17_cefc4c->getZones();
	for (int i = 0; i < 9; i++)
	{
		for (unsigned int j = 0; j < (*zones)[i].size(); j++)
		{
			if (!(*cells17_cfd44c.atPoint((*zones)[i][j]))->getProp()->unknown45cb30()->markers.empty())
			{
				vector<int> *list = &(*cells17_cfd44c.atPoint((*zones)[i][j]))->getProp()->unknown45cb30()->markers;
				for (unsigned int k = 0; k < list->size(); k++)
					OpU8a_removeEntity((*world17_cefc4c->getMarkerLists())[(*list)[k]],(*cells17_cfd44c.atPoint((*zones)[i][j]))->getProp());
				list->clear();
			}
		}
	}
}

bool Overmind::findCargoDispatchTarget(const Point &from, Point *out)
{
	bool checkProps = unknownbc == 0 || rng.chance(difficultySettings_b939b0[gameData_d1e860.getDepthIndex()].cargoChance);
	if (checkProps)
	{
		int bestIndex = -1;
		int bestDistance;
		for (unsigned int i = 0; i < world->exits.size(); i++)
		{
			if (!world->exits[i]->unknown0c && world->exits[i]->prop.operator->() && world->exits[i]->prop->unknown9b4410() == 0
				&& (bestIndex == -1 || OpQ1_distanceCeil_40a3f0(from,world->exits[i]->pos) > bestDistance))
			{
				bestIndex = i;
				bestDistance = OpQ1_distanceCeil_40a3f0(from,world->exits[i]->pos);
			}
		}
		if (bestIndex != -1)
			*out = world->exits[bestIndex]->pos;
	}
	if (out->x == -1)
	{
		int bestIndex = -1;
		int bestDistance;
		for (unsigned int i = 0; i < world->exits.size(); i++)
		{
			if (!world->exits[i]->unknown0c && world->exits[i]->prop.isNull()
				&& (bestIndex == -1 || OpQ1_distanceCeil_40a3f0(from,world->exits[i]->pos) > bestDistance))
			{
				bestIndex = i;
				bestDistance = OpQ1_distanceCeil_40a3f0(from,world->exits[i]->pos);
			}
		}
		if (bestIndex != -1)
			*out = world->exits[bestIndex]->pos;
	}
	if (out->x == -1)
	{
		logWarning("Overmind::findCargoDispatchTarget()","no valid targets?");
		return false;
	}
	else
		return true;
}

int Overmind::spawnCargoDispatch_68aba0()
{
	Point *loc = NULL;
	if (!findDispatchExit(&unknownc0,1,0x1e,0,Point(-1),&loc,0,0))
	{
		logWarning("Overmind::spawnCargoDispatch()","No valid access point for spawning");
		return 0;
	}
	if (!findCargoDispatchTarget(unknownc0,&unknownc8))
		return 0;
	OPD_ALERT(-1,string("ALERT: Cargo convoy en route, clear transfer corridor."));
	if (rolledValues_cefb48)
		rolledValues_cefb48->say(0x30,false,"");
	int num = 0;
	HEntity entity;
	int value = difficultySettings_b939b0[gameData_d1e860.getDepthIndex()].cargoCount;
	EntityRecord *rec;
	if (value)
	{
		rec = world->selectRobotOfClass(1,0xd,false,false);
		if (rec)
		{
			for (int i = 0; i < value; i++)
			{
				entity = world->placeEntity(rec,unknownc0,3,false,0x19,0xe,false);
				if (entity.isValid())
				{
					entity->getAI()->unknown459540(unknownc8);
					entity->getAI()->unknown459560(0);
					num++;
				}
			}
		}
	}
	unknownbc++;
	unknownd0 = world->getTurn() + rng.rangeInt(18,25);
	return num;
}

bool Overmind::redirectParty(Party *party, const Point &target, HEntity e)
{
	if (party->unknown08 != -2)
	{
		vector<Point> path;
		if (!world->unknown7168e0(party->leader->getPosition(),target,party->leader.operator->(),&path))
			return false;
		switch (party->type)
		{
			case 0:
			{
				vector<Point> points(1,target);
				party->leader->getAI()->unknown4593d0(points);
				break;
			}
			case 1:
			case 2:
			case 3:
			{
				vector<Point> points;
				points.push_back(party->leader->getPosition());
				points.push_back(target);
				party->leader->getAI()->unknown4593d0(points);
				break;
			}
			case 5:
			case 7:
				if (e.isValid())
				{
					party->leader->getAI()->unknown5b4710(e,-1,0,0,0);
					break;
				}
			case 4:
			case 6:
			{
				Area room;
				cells_cfd44c.getRect(target,0xf,room);
				party->leader->getAI()->unknown459470(room);
				break;
			}
			default:
				if (1)
				{
					logError("Overmind::redirectParty()","non-implemented partyType: " + partyTypeNames_cf14d0[party->type]);
					return false;
				}
		}
		return true;
	}
	return false;
}

int Overmind::spawnResponseParty(int type, HEntity target, Point *area, Point *outAccess)
{
	vector<EntityRecord *> pool;
	EntityRecord *rec;
	OpQ5_findByName(entityRecords_d25de0,"Lightning",rec);
	pool.assign(3,rec);
	OpQ5_findByName(entityRecords_d25de0,"I-47 Archangel",rec);
	pool.push_back(rec);
	Point pos;
	Point *loc = NULL;
	if (!findDispatchExit(&pos,1,0,1,world->getPlayer()->getPosition(),&loc,1,0))
	{
		logWarning("Overmind::spawnResponseParty()","No valid access point for spawning");
		failedDispatches++;
		return 0;
	}
	else
		OpV4c_Fn9d0690(&failedDispatches,1,0);
	int count = 0;
	HEntity leader = world->placeEntity(pool.front(),pos,3,false,0x22,0xe,false);
	if (leader.isValid())
	{
		count++;
		if (area)
		{
			Area room;
			cells_cfd44c.getRect(*area,0x14,room);
			leader->getAI()->unknown459470(room);
		}
		else
			leader->getAI()->unknown5b4710(target,-1,0,0,0);
		for (unsigned int i = 1; i < pool.size(); i++)
		{
			HEntity member = world->placeEntity(pool[i],pos,3,false,0x22,0xe,false);
			if (member.isNull())
				break;
			member->getAI()->setFollowEntity(leader,0);
			count++;
		}
		addParty(new Party(type,leader,-1,0,0),loc);
	}
	if (count && outAccess && loc)
		*outAccess = *loc;
	return count;
}

extern int flag_cf4740;	// NOTE: placeholder name

void Overmind::unknown681550()
{
	OPD_ALERT(-1,string("ALERT: Machine network offline."));
	vector<vector<Point> > *zones = world17_cefc4c->getZones();
	for (int i = 0; i < 9; i++)
	{
		for (unsigned int j = 0; j < (*zones)[i].size(); j++)
		{
			if (!flag_cf4740 || i != 5)
				(*cells17_cfd44c.atPoint((*zones)[i][j]))->getProp()->unknown45cb30()->unknown28 = -1;
		}
	}
	for (unsigned int k = 0; k < markerLists_d20248.size(); k++)
	{
		if (!markerLists_d20248[k].empty())
		{
			for (int m = markerLists_d20248[k].size() - 1; m >= 0; m--)
			{
				if (markerLists_d20248[k][m]->unknown9c3a90()->unknown140 == 0xe && markerLists_d20248[k][m]->unknown44cea0()->unknown10 == 3)
					(*cells17_cfd44c.atPoint(markerLists_d20248[k][m]->getPosition()))->removeProp(false,4);
			}
		}
	}
}

class Stats_d2c658	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern Stats_d2c658 stats_d2c658;	// NOTE: placeholder name

class PlayerData81b70	// NOTE: placeholder name (0xcf45d8)
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern PlayerData81b70 playerData_cf45d8;	// NOTE: placeholder name

extern vector<int> rifLevels_cf4a04;		// NOTE: placeholder name
extern float rewards_b91998[];	// NOTE: placeholder name
extern float multiplier_b919a0;	// NOTE: placeholder name
extern float multiplier_b919a8;	// NOTE: placeholder name
extern int difficulty_cf4718;	// NOTE: placeholder name
void OpC_clampMax(int *value, int max);	// NOTE: placeholder name

void Overmind::unknown681b70(HEntity killed, HEntity killer)
{
	int kind = 0xb;
	bool found = unknown683380(killed,&kind);
	if (killer.operator->())
	{
		if (killer->getGroup()->unknown9b4350() <= 2)
		{
			int type = killed->getGroup()->unknown9c3a90();
			if (type == 3 || type == 4)
			{
				if (rifLevels_cf4a04[0xd] && (killer->getAiType() == 1 || killer->getAiType() == 2) && world->getPlayer()->unknown5d4490(killer))
					stats_d2c658.add4729d0(0x23f,1,"",-1);
				else
				{
					bool active = killed->getAI()->unknown9b4350() >= 6;
					unknown682420(!active,0);
					int amount = (int)rewards_b91998[!active];
					if (found)
					{
						int extra = (int)(amount * multiplier_b919a0 - amount);
						unknown682420(2,extra);
						amount += extra;
					}
					int other;
					int total;
					world->unknown715570(0x14,&total,&other);
					if (total || other)
					{
						int percent = (int)(total + other * multiplier_b919a8);
						OpC_clampMax(&percent,100);
						switch (difficulty_cf4718)
						{
							break;
							case 1:
								percent /= 2;
								break;
							case 2:
								percent /= 3;
								break;
						}
						unknown682420(3,amount * percent / 100);
					}
				}
			}
		}
		if (killed.operator->() && killer->getGroup()->unknown9b4350() > 2 && killed->getGroup()->unknown9b4350() <= 2)
			unknown682420(0x22 + (killed->getAI()->unknown9b4350() < 6),0);
		if (kind == 10 && killer->getGroup()->unknown9b4350() <= 1)
			playerData_cf45d8.unknown77fbc0(0x1c);
	}
}

int Overmind::unknown68b9a0(vector<Point> &targets, bool repeat)
{
	if (targets.empty())
		return 0;
	EntityRecord *rec = world->selectRobotOfClass(1,3,false,false);
	if (!rec)
		return 0;
	EntityRecord *current = world->selectRobotOfClass(1,0x10,false,false);
	int total = 0;
	Point pos;
	Point *loc = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (findDispatchExit(&pos,1,0,1,world->getPlayer()->getPosition(),&loc,0,0))
		{
			HEntity leader = world->placeEntity(rec,pos,4,false,0x22,0xe,false);
			Area area;
			cells_cfd44c.getRect(OpU8a_randomPoint(targets),0xc,area);
			leader->getAI()->unknown459410(area);
			if (current)
			{
				HEntity member = world->placeEntity(current,pos,3,false,0x22,0xe,false);
				if (member.isValid())
					member->getAI()->setFollowEntity(leader,0);
			}
		}
	}
	string text = repeat ? "ALERT: Derelict activity in mines confirmed. Dispatching additional escorted excavation squad." : "ALERT: Suspicious cave-in, suspected derelict activity in mines. Dispatching escorted excavation squad.";
	OPD_ALERT(0x127,text);
	do { logEvent_5141b0(0xdb,0,0,0,HProp(),0); } while (0);
	return total;
}

template <class T> class OpR5h_WL	// NOTE: placeholder name (weighted list)
{
public:
	OpR5h_WL();
	OpR5h_WL(const int *w, int count);	// 0x9ba790
	~OpR5h_WL();
	void remove(T value);
	void add(T value, int weight);
	bool pick(T *out);
	T &pick();
	int size();		// NOTE: placeholder name (folded with a deque iterator operator*)
	void reset();	// NOTE: placeholder name (folded with OpX5_Q9c07a0::reset)

	vector<T> values;
	vector<int> weights;
	int totalWeight;	// NOTE: placeholder layout
};

class Cell21	// NOTE: placeholder name
{
public:
	bool canPlaceEntity(int size);	// 0x66ad20
};

class Grid21	// NOTE: placeholder name (0xcfd44c)
{
public:
	void getRandom_9cf0c0(Point *out);	// NOTE: placeholder name
	Cell21 **atPoint(Point &p);			// NOTE: folded with OpX5_Array2D<int>::atPoint
};
extern Grid21 cells21_cfd44c;	// NOTE: placeholder name

struct EntityRecord21	// NOTE: placeholder name
{
	char pad[0x9c];
	int size;	// +0x9c, NOTE: placeholder name
};

struct GameState21	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;	// NOTE: placeholder name
};
class HGameState21	// NOTE: placeholder name
{
	int ID;
public:
	GameState21 *operator->() const;
};
extern HGameState21 gameState_d1e888;	// NOTE: placeholder name

bool terrainFlagB_448b80(Point &p);	// NOTE: placeholder name
extern int spawnWeights_b92500[][2];	// NOTE: placeholder name
extern int gameMode_cf462c;			// NOTE: placeholder name
extern Point range_d32cf4;			// NOTE: placeholder name
extern Point range_cfd300;			// NOTE: placeholder name
extern Point range_d33bd8;			// NOTE: placeholder name
extern Overmind overmind_cf6428;	// NOTE: placeholder name

int Overmind::unknown68a500(bool anywhere, Point *patrol, bool forced)
{
	int kind;
	if (forced)
		kind = 1;
	else
	{
		OpR5h_WL<int> weights;
		for (int i = 0; i < 2; i++)
			weights.add(i,spawnWeights_b92500[gameData_d1e860.getDepthIndex()][i]);
		weights.pick(&kind);
	}
	EntityRecord *current = world->selectRobotOfClass(1,4,false,false);
	if (!current)
		return 0;
	int total = 0;
	Point pos;
	Point *loc = NULL;
	bool success = false;
	if (!anywhere)
		success = findDispatchExit(&pos,0,0,0,Point(-1),&loc,0,0);
	else
	{
		for (int j = 0; j < 100; j++)
		{
			cells21_cfd44c.getRandom_9cf0c0(&pos);
			if ((*cells21_cfd44c.atPoint(pos))->canPlaceEntity(((EntityRecord21 *)current)->size) && !terrainFlagB_448b80(pos))
			{
				success = true;
				break;
			}
		}
	}
	if (success)
	{
		switch (kind)
		{
			case 0:
			case 1:
			{
				HEntity leader = world->placeEntity(current,pos,4,anywhere,0x22,0xe,false);
				if (leader.isValid())
				{
					total++;
					if (patrol)
						leader->getAI()->setPatrolRandom(*patrol);
					if (kind == 1)
					{
						if (gameState_d1e888->unknown4 != 2)
							leader->getAI()->setUnknown451400(1);
						EntityRecord *rec = world->selectRobotOfClass(1,0x10,false,false);
						if (!rec)
						{
						}
						else
						{
							int num2 = range_d32cf4.randomInRange_40c130();
							while (num2)
							{
								HEntity member = world->placeEntity(rec,pos,3,anywhere,0x22,0xe,false);
								if (member.isNull())
									break;
								member->getAI()->setFollowEntity(leader,0);
								total++;
								num2--;
							}
						}
					}
					overmind_cf6428.addParty(new Party(3,leader,-1,0,0),loc);
					if (gameMode_cf462c != 2)
						unknown6901e0(leader,kind == 1,range_cfd300.randomInRange_40c130(),range_d33bd8.randomInRange_40c130(),Point(-1),0,0x2a);
				}
			}
		}
	}
	return total;
}

extern int spawnWeights_b91e30[][2];	// NOTE: placeholder name

int Overmind::unknown6892c0(bool anywhere, Point *patrol, bool forced)
{
	int kind;
	if (forced)
		kind = 1;
	else
	{
		OpR5h_WL<int> weights;
		for (int i = 0; i < 2; i++)
			weights.add(i,spawnWeights_b91e30[gameData_d1e860.getDepthIndex()][i]);
		weights.pick(&kind);
	}
	EntityRecord *source = NULL;
	switch (kind)
	{
		case 0:
			source = world->selectRobotOfClass(1,0xc,false,false);
			break;
		case 1:
			OpQ5_findByName(entityRecords_d25de0,"N-01 Spotter",source);
			break;
	}
	if (!source)
		return 0;
	int total = 0;
	Point pos;
	Point *loc = NULL;
	bool found = false;
	if (!anywhere)
		found = findDispatchExit(&pos,1,0,1,Point(-1),&loc,0,0);
	else
	{
		for (int j = 0; j < 100; j++)
		{
			cells21_cfd44c.getRandom_9cf0c0(&pos);
			if ((*cells21_cfd44c.atPoint(pos))->canPlaceEntity(((EntityRecord21 *)source)->size) && !terrainFlagB_448b80(pos))
			{
				found = true;
				break;
			}
		}
	}
	if (found)
	{
		HEntity leader;
		switch (kind)
		{
			case 0:
				leader = world->placeEntity(source,pos,3,anywhere,0x22,0xe,false);
				if (leader.isValid())
				{
					total++;
					if (patrol)
						leader->getAI()->setPatrolRandom(*patrol);
					overmind_cf6428.addParty(new Party(1,leader,-1,0,0),loc);
				}
				break;
			case 1:
				leader = world->placeEntity(source,pos,3,anywhere,0x22,0xe,false);
				if (leader.isValid())
				{
					total++;
					if (patrol)
						leader->getAI()->setPatrolRandom(*patrol);
					overmind_cf6428.addParty(new Party(1,leader,-1,0,0),loc);
				}
				break;
		}
	}
	return total;
}

class Faction23	// NOTE: placeholder name
{
public:
	vector<HEntity> *getMembers();	// NOTE: placeholder name (trivial getter)
};

class HFaction23	// NOTE: placeholder name
{
	int	ID;
public:
	Faction23 *operator->() const;
};

class Map23	// NOTE: placeholder name (world at 0xcefc4c)
{
public:
	HFaction23 unknown463890(int faction);	// NOTE: placeholder name
};
extern Map23 *world23_cefc4c;	// NOTE: placeholder name

struct PropData23	// NOTE: placeholder name
{
	string unknown65cc80();	// NOTE: placeholder name
};

class Prop23	// NOTE: placeholder name
{
public:
	PropData23 *unknown45cb30();	// NOTE: placeholder name (trivial getter)
};

class HProp23	// NOTE: placeholder name
{
	int ID;
public:
	Prop23 *operator->() const;
};

class Cell23	// NOTE: placeholder name
{
public:
	HProp23 getProp();	// 0x45d550
};

class Grid23	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell23 **atPoint(const Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
};
extern Grid23 cells23_cfd44c;	// NOTE: placeholder name

class XConsole23	// NOTE: placeholder name
{
public:
	bool isHidden();
};
extern XConsole23 *console_cec0f8;	// NOTE: placeholder name

int indexOfMinInt(vector<int> &v);	// NOTE: placeholder name (OpS8c_indexOfMinInt)
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name
template <class T> void removeVectorElement(vector<T> &v, int index);

bool Overmind::unknown68c960(const Point &target)
{
	vector<HEntity> candidates;
	vector<int> distances;
	vector<HEntity> *members = world23_cefc4c->unknown463890(3)->getMembers();
	for (unsigned int i = 0; i < members->size(); i++)
	{
		if ((*members)[i]->getAI()->unknown9c3a90() == 1 && (*members)[i]->getTarget() == 0 && (*members)[i]->getSize() == 1)
		{
			candidates.push_back((*members)[i]);
			distances.push_back(OpQ1_distanceCeil_40a3f0((*members)[i]->getPosition(),target));
		}
	}
	bool found = false;
	for (int k = 0; k < 2 && !candidates.empty(); k++)
	{
		int idx = indexOfMinInt(distances);
		candidates[idx]->getAI()->unknown5b4710(world->getPlayer(),-1,0,0,0);
		OpQ5_eraseAt(candidates,idx);
		removeVectorElement(distances,idx);
		found = true;
	}
	unknown682420(0x17,0);
	if (found)
	{
		string text = "ALERT: Suspicious activity at " + (*cells23_cfd44c.atPoint(target))->getProp()->unknown45cb30()->unknown65cc80() + ". Transmitting hostile system tracking data.";
		OPD_ALERT_EXPR(console_cec0f8->isHidden() ? 0x127 : -1,text);
	}
	return found;
}

struct SurgicalSettings	// NOTE: placeholder name
{
	SurgicalSettings();	// NOTE: trivial; defined below so LTCG can prove it cannot throw
	bool operator==(const SurgicalSettings &other) const;
	int		unknown0;
	int		type;		// +4, NOTE: placeholder name
	int		unknown8;
	bool	unknownc;	// NOTE: placeholder name
	bool	unknownd;	// NOTE: placeholder name
	bool	unknowne;	// NOTE: placeholder name
	bool	unknownf;	// NOTE: placeholder name
	bool	unknown10;	// NOTE: placeholder name
	bool	unknown11;	// NOTE: placeholder name
	bool	unknown12;	// NOTE: placeholder name
};

struct PartRecord24	// NOTE: placeholder name
{
	char	pad00[0x44];
	int		unknown44;		// NOTE: placeholder name
	char	pad48[0x128 - 0x48];
	int		unknown128;		// NOTE: placeholder name
	char	pad12c[0x1a0 - 0x12c];
	struct Sub
	{
		char	pad[0x2c];
		int		unknown2c;	// NOTE: placeholder name
	}		*unknown1a0;	// NOTE: placeholder name
};
extern vector<PartRecord24 *> partRecords_d2d1c4;	// NOTE: placeholder name
extern int notFound_caf164;	// NOTE: placeholder name

int OpU8a_indexOfName(vector<PartRecord24 *> &list, const string &name);	// NOTE: placeholder name
void opT3_f6854b0(vector<int> &list, int key);	// NOTE: placeholder name
bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (in range)

void Overmind::loadZPartList(vector<int> &out, vector<int> &records)
{
	if (surgical->unknowne)
		opT3_f6854b0(out,10);
	if (surgical->unknownd)
	{
		int idx = OpU8a_indexOfName(partRecords_d2d1c4,"Swarm Drone Bay");
		if (idx != notFound_caf164)
			out.push_back(idx);
	}
	if (surgical->unknownf && rng.chance(50))
		opT3_f6854b0(out,0x31);
	int kind = 0x30;
	switch (surgical->type)
	{
		case 0:
			kind = 0x2f;
			break;
		case 1:
			kind = 0x30;
			break;
		case 3:
			kind = 0x32;
			break;
	}
	opT3_f6854b0(out,kind);
	if (surgical->unknown10 && rng.chance(50))
		opT3_f6854b0(out,0x62);
	if (surgical->unknownc || surgical->unknown11)
	{
		kind = 0x5d;
		for (unsigned int i = 0; i < records.size(); i++)
		{
			if (partRecords_d2d1c4[records[i]]->unknown44 < 0x18)
			{
				kind = 0x55;
				break;
			}
			else if (OpT8b_Fn9daf80(0x1a,partRecords_d2d1c4[records[i]]->unknown44,0x1c))
			{
				kind = 0x5a;
				break;
			}
		}
		opT3_f6854b0(out,kind);
		if (rng.chance(25))
			opT3_f6854b0(out,kind);
	}
	bool found = false;
	bool visible = false;
	bool changed = false;
	bool updated = false;
	for (unsigned int j = 0; j < records.size(); j++)
	{
		switch (partRecords_d2d1c4[records[j]]->unknown1a0 ? partRecords_d2d1c4[records[j]]->unknown1a0->unknown2c : partRecords_d2d1c4[records[j]]->unknown128)
		{
			case 0:
				visible = true;
				changed = true;
				break;
			case 1:
				found = true;
				break;
			case 2:
				visible = true;
				updated = true;
				break;
			case 3:
				found = true;
				break;
		}
	}
	if (found)
	{
		opT3_f6854b0(out,8);
		if (rng.chance(50))
			opT3_f6854b0(out,0x67);
	}
	if (visible)
	{
		opT3_f6854b0(out,9);
		if (changed && rng.chance(50))
			opT3_f6854b0(out,0x69);
	}
	if (records.size() == 1 && rng.chance(50))
		opT3_f6854b0(out,0x3d);
	if (OpT8b_Fn9daf80(0x1a,partRecords_d2d1c4[records[0]]->unknown44,0x1c))
	{
		if (rng.chance(75))
			opT3_f6854b0(out,0x51);
		if (rng.chance(75))
			opT3_f6854b0(out,0x6c);
	}
	else if (records.size() == 1)
	{
		if (surgical->unknown12 || rng.chance(50))
		{
			if (partRecords_d2d1c4[records[0]]->unknown44 == 0x15)
			{
				opT3_f6854b0(out,0x4e);
				opT3_f6854b0(out,1);
			}
			if (updated)
				opT3_f6854b0(out,0x4f);
		}
	}
	else
	{
		if (surgical->unknown12 || rng.chance(50))
		{
			opT3_f6854b0(out,0x50);
			opT3_f6854b0(out,1);
		}
	}
}

class Cell25	// NOTE: placeholder name
{
public:
	HEntity getEntity();
};

class Grid25	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell25 **at(int x, int y);	// NOTE: folded with OpX5_Array2D<int>::at
	int getHeight();			// NOTE: placeholder name
};
extern Grid25 cells25_cfd44c;	// NOTE: placeholder name

void Overmind::unknown683e60(const Point &p, vector<vector<HEntity> > &out)
{
	out.assign(0x61,vector<HEntity>());
	vector<Point> origin;
	vector<int> steps;
	if (p.y < cells25_cfd44c.getHeight() / 2)
	{
		origin.push_back(Point(0x8f,0x13));
		steps.push_back(-1);
		origin.push_back(Point(0x8f,0x28));
		steps.push_back(1);
		origin.push_back(Point(0x8f,0x6d));
		steps.push_back(-1);
		origin.push_back(Point(0x8f,0x82));
		steps.push_back(1);
	}
	else
	{
		origin.push_back(Point(0x8f,0x6d));
		steps.push_back(-1);
		origin.push_back(Point(0x8f,0x82));
		steps.push_back(1);
		origin.push_back(Point(0x8f,0x13));
		steps.push_back(-1);
		origin.push_back(Point(0x8f,0x28));
		steps.push_back(1);
	}
	int width = 0x13;
	int height = 6;
	for (unsigned int i = 0; i < origin.size(); i++)
	{
		for (int x = origin[i].x, a = 0; a < width; x++, a++)
		{
			for (int y = origin[i].y, x2 = 0; x2 < height; y += steps[i], x2++)
			{
				if ((*cells25_cfd44c.at(x,y))->getEntity().isValid() && (*cells25_cfd44c.at(x,y))->getEntity()->getTarget() == 2)
					out[(*cells25_cfd44c.at(x,y))->getEntity()->getFaction()].push_back((*cells25_cfd44c.at(x,y))->getEntity());
			}
		}
	}
}

class PlayerData26	// NOTE: placeholder name (0xcf45d8)
{
public:
	bool unknown77f260(int id);	// NOTE: placeholder name
};
extern PlayerData26 playerData26_cf45d8;	// NOTE: placeholder name
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
extern Point trackerCounts_d387d8[];	// NOTE: placeholder name

struct TrackerChance	// NOTE: placeholder name (12-byte records at 0xb938c0)
{
	int chance;
	int pad[2];
};
extern TrackerChance trackerChances_b938c0[];	// NOTE: placeholder name

int Overmind::spawnInterceptParty(bool programmer, HEntity target, Point *area)
{
	if (stringToInt(gameData_d1e860.getEntryText("comConduitDisabled_g")) || unknown4c || world->unknown4638e0(0,3) == 2)
		return 0;
	EntityRecord *source;
	OpQ5_findByName(entityRecords_d25de0,programmer ? "Combat Programmer" : "Tracker",source);
	int count = programmer ? 1 : trackerCounts_d387d8[gameData_d1e860.getDepthIndex()].randomInRange_40c130() + extraTrackers;
	if (!programmer && rng.chance(trackerChances_b938c0[gameData_d1e860.getDepthIndex()].chance))
		extraTrackers++;
	if (!source)
		return 0;
	Point pos;
	Point *loc = NULL;
	if (!findDispatchExit(&pos,1,0,1,Point(-1),&loc,0,0))
	{
		failedDispatches++;
		return 0;
	}
	else
		OpV4c_Fn9d0690(&failedDispatches,1,0);
	int total = 0;
	while (count)
	{
		count--;
		HEntity e = world->placeEntity(source,pos,3,false,0x22,0xe,false);
		if (e.isValid())
		{
			total++;
			if (area)
			{
				Area room;
				cells_cfd44c.getRect(*area,0xf,room);
				e->getAI()->unknown459470(room);
			}
			else if (target->isPlayer() && (playerData26_cf45d8.unknown77f260(0x50) || target->unknown5d2380(0x1f).isValid()))
			{
				Area room;
				cells_cfd44c.getRect(target->getPosition(),0xf,room);
				e->getAI()->unknown459470(room);
			}
			else
				e->getAI()->unknown5b4710(target,-1,0,0,0);
			addParty(new Party(9,e,-1,0,0),loc);
		}
	}
	return total;
}

class GameData27	// NOTE: placeholder name (0xd1e860)
{
public:
	int unknown789250(int value);	// NOTE: placeholder name
};
extern GameData27 gameData27_d1e860;	// NOTE: placeholder name
extern Point couplingSizes_cf0c90[];		// NOTE: placeholder name
extern Point range_d2f130;			// NOTE: placeholder name
extern float multiplier_ba780c;		// NOTE: placeholder name
extern float multipliers_ba65d8[];	// NOTE: placeholder name
extern OpR5h_WL<ItemType27 *> itemWeights_d2ae08;	// NOTE: placeholder name

int Overmind::spawnCouplingParty(const Point &target)
{
	if (stringToInt(gameData_d1e860.getEntryText("comConduitDisabled_g")) || unknown4c || world->unknown4638e0(0,3) == 2)
		return 0;
	EntityRecord *current = world->selectRobotOfClass(1,0x19,true,false);
	EntityRecord *closest = NULL;
	if (!closest)
		closest = current;
	int num = couplingSizes_cf0c90[gameData_d1e860.getDepthIndex()].randomInRange_40c130() - 1;
	Point pos;
	Point *loc = NULL;
	if (!findDispatchExit(&pos,1,0,1,Point(-1),&loc,0,0))
		return 0;
	int total = 0;
	HEntity leader = world->placeEntity(current,pos,3,false,0x13,0xe,false);
	if (leader.isValid())
	{
		total++;
		leader->getAI()->unknown4593b0(target);
		int count = range_d2f130.randomInRange_40c130();
		if (gameMode_cf462c == 5)
			count = (int)(count * multiplier_ba780c);
		for (int i = 0; i < count; i++)
		{
			ItemType27 *type = itemWeights_d2ae08.pick();
			HItem27 item = world->unknown6c51d0(type,leader,false,false);
			if (item.isValid())
				item->setUnknown(gameData27_d1e860.unknown789250((int)(item->getData()->unknown64 * multipliers_ba65d8[difficulty_cf4718])));
		}
		while (num)
		{
			HEntity member = world->placeEntity(closest ? closest : current,pos,3,false,0x22,0xe,false);
			if (member.isNull())
				break;
			member->getAI()->setFollowEntity(leader,0);
			num--;
			total++;
		}
		addParty(new Party(10,leader,-1,0,0),loc);
	}
	return total;
}

struct ZWeaponTable	// NOTE: placeholder name (0x14-byte records at 0xb93798)
{
	int tier2;		// NOTE: placeholder name
	int tier3;		// NOTE: placeholder name
	int explosive;	// NOTE: placeholder name
	int pad[2];
};
extern ZWeaponTable zWeaponTable_b93798[];	// NOTE: placeholder name
string intToString(int value);
void OpT3d_unknown684d00(OpR5h_WL<int> *list, int id, Point range, bool flag);	// NOTE: placeholder name

void Overmind::loadZWeaponList(vector<int> &out, int level)
{
	OpR5h_WL<int> table;
	table.add(2,zWeaponTable_b93798[level].tier2);
	table.add(3,zWeaponTable_b93798[level].tier3);
	bool flags = table.pick() == 3;
	int count = 0;
	int record;
	switch (surgical->unknown0)
	{
		case 0:
			record = flags ? 0x17 : 0x16;
			count = flags ? 1 : 2;
			break;
		case 1:
			record = flags ? 0x15 : 0x14;
			count = flags ? 1 : 2;
			break;
		case 2:
			record = 0x18;
			count = 1;
			break;
		case 3:
			record = flags ? 0x15 : 0x14;
			count = flags ? 1 : 2;
			break;
		case 4:
			record = 0x1a;
			count = rng.rangeInt(2,3);
			break;
		case 5:
			record = 0x1b;
			count = rng.rangeInt(2,3);
			break;
		case 6:
			record = 0x1c;
			count = rng.rangeInt(2,3);
			break;
		default:
			if (1)
			{
				logError("Overmind::loadZWeaponList()","unrecognized weakness: " + intToString(surgical->unknown0));
				record = 0x16;
				count = 2;
			}
			break;
	}
	OpR5h_WL<int> options;
	OpT3d_unknown684d00(&options,record,Point(level - 1,level + 1),surgical->unknown0 == 3);
	if (!options.size())
	{
		logError("Overmind::loadZWeaponList()","No applicable weapons found for level " + intToString(level));
		return;
	}
	for (int i = 0; i < count; i++)
		out.push_back(options.pick());
	if (surgical->unknown8 > 0 && record != 0x18 && rng.chance(zWeaponTable_b93798[level].explosive * surgical->unknown8))
	{
		options.reset();
		OpT3d_unknown684d00(&options,0x18,Point(level - 1,level + 1),false);
		if (!options.size())
		{
			logError("Overmind::loadZWeaponList()","No applicable explosive found for level " + intToString(level));
			return;
		}
		out.push_back(options.pick());
	}
}

extern int mode_caf130;				// NOTE: placeholder name
extern int partyWeights_b94010[];	// NOTE: placeholder name
extern Point range_d30350;			// NOTE: placeholder name
bool logMessageAt_5111e0(int id, const string *text, int a, int b, HEntity c, HProp d, const Point &at, int f);	// NOTE: placeholder name (0x5111e0)

class Stats29	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern Stats29 stats29_d2c658;	// NOTE: placeholder name

int Overmind::unknown68bc80(int exitIndex, int type, const Point &target)
{
	if (mode_caf130 != 7)
		return 0;
	vector<EntityRecord *> current;
	EntityRecord *source = NULL;
	switch (type)
	{
		case 0:
			source = world->selectRobotOfClass(1,0x15,false,false);
			if (!source)
				source = world->selectRobotOfClass(1,0x10,false,false);
			current.push_back(source);
			break;
		case 1:
			if (rng.chance(50))
			{
				source = world->selectRobotOfClass(1,0x15,false,false);
				current.push_back(source);
			}
			if (!source)
			{
				source = world->selectRobotOfClass(1,0x10,false,false);
				current.assign(2,source);
			}
			break;
		case 2:
		{
			OpR5h_WL<int> weights(partyWeights_b94010,8);
			if (!world->unknown715a70())
				weights.remove(7);
			do
			{
				int pick = weights.pick();
				switch (pick)
				{
					case 0:
					case 1:
						source = world->selectRobotOfClass(1,0x15,false,false);
						if (source)
							current.assign((pick != 0) + 1,source);
						break;
					case 2:
					case 3:
						source = world->selectRobotOfClass(1,0x10,false,false);
						if (source)
							current.assign((pick != 2) + 1,source);
						break;
					case 4:
						source = world->selectRobotOfClass(1,0x11,false,false);
						if (source)
							current.push_back(source);
						source = world->selectRobotOfClass(1,0x12,false,false);
						if (source)
							current.push_back(source);
						break;
					case 5:
					case 6:
						source = world->selectRobotOfClass(1,0xd,false,false);
						if (source)
							current.assign((pick != 5) + 2,source);
						break;
					case 7:
						source = world->selectRobotOfClass(1,0x16,false,false);
						if (source)
							current.push_back(source);
						break;
				}
				if (current.empty())
					weights.remove(pick);
			}
			while (current.empty() && weights.size());
			if (!weights.size())
				return 0;
			break;
		}
	}
	if (current.empty())
		return 0;
	Point *node = world->unknown462f60(exitIndex);
	Point pos(*node);
	int count = 0;
	HEntity leader = world->placeEntity(current[0],pos,3,false,0x22,0xe,false);
	if (leader.isValid())
	{
		do { if (logMessageAt_5111e0(0x1cd,0,0,0,leader,HProp(),leader->getPosition(),0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
		count++;
		Area area;
		cells_cfd44c.getRect(target,10,area);
		leader->getAI()->unknown459470(area);
		for (unsigned int i = 1; i < current.size(); i++)
		{
			HEntity member = world->placeEntity(current[i],pos,3,false,0x22,0xe,false);
			if (member.isNull())
				break;
			member->getAI()->setFollowEntity(leader,0);
			do { if (logMessageAt_5111e0(0x1cd,0,0,0,member,HProp(),member->getPosition(),0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
			count++;
		}
		addParty(new Party(8,leader,world->getTurn() + range_d30350.randomInRange_40c130(),0,0),node);
	}
	stats29_d2c658.add4729d0(0x231,1,"",-1);
	stats29_d2c658.add4729d0(0x236,1,"",-1);
	return count;
}

struct EntityRecord30	// NOTE: placeholder name
{
	int		unknown00;		// NOTE: placeholder name
	char	pad04[0x28 - 0x04];
	int		faction;		// +0x28, NOTE: placeholder name
	char	pad2c[0x48 - 0x2c];
	int		unknown48;		// NOTE: placeholder name
};
extern vector<EntityRecord30 *> entityRecords30_d25de0;	// NOTE: placeholder name
extern Point ranges_cf1400[][2];	// NOTE: placeholder name
extern int weights_b93c60[][2];		// NOTE: placeholder name
extern int flag_d1eb68;				// NOTE: placeholder name
extern vector<int> values_d2f0f8;	// NOTE: placeholder name

int Overmind::unknown686c60(const Point &target, int num, int recType, int recClass)
{
	if (stringToInt(gameData_d1e860.getEntryText("comConduitDisabled_g")) || unknown4c || world->unknown4638e0(0,3) == 2)
		return 0;
	bool active = gameState_d1e888->unknown4 == 0x22;
	vector<vector<HEntity> > targets;
	if (active)
		unknown683e60(target,targets);
	OpR5h_WL<int> weight;
	for (int i = 0; i < 2; i++)
		weight.add(i,weights_b93c60[gameData_d1e860.getDepthIndex()][i]);
	int mode;
	weight.pick(&mode);
	int entityCount = num == -1 ? ranges_cf1400[gameData_d1e860.getDepthIndex()][mode].randomInRange_40c130() - 1 : num - 1;
	EntityRecord30 *current;
	EntityRecord30 *element;
	switch (mode)
	{
		case 0:
			current = (EntityRecord30 *)world->selectRobotOfClass(1,0x10,false,false);
			element = NULL;
			break;
		case 1:
			current = (EntityRecord30 *)world->selectRobotOfClass(1,0x18,false,false);
			element = NULL;
			break;
	}
	if (recType != 0x61)
	{
		current = (EntityRecord30 *)world->selectRobotOfClass(1,recType,false,false);
		element = NULL;
	}
	else if (recClass != 0x7a)
	{
		for (unsigned int j = 0; j < entityRecords30_d25de0.size(); j++)
		{
			if (entityRecords30_d25de0[j]->unknown48 == recClass)
			{
				current = entityRecords30_d25de0[j];
				element = NULL;
			}
		}
	}
	if (!current)
		return 0;
	if (!element)
		element = current;
	Point pos;
	Point *loc = NULL;
	if (!active && !findDispatchExit(&pos,1,0,1,world->getPlayer()->getPosition(),&loc,0,0))
	{
		failedDispatches++;
		return 0;
	}
	else
		OpV4c_Fn9d0690(&failedDispatches,1,0);
	vector<HEntity> group;
	HEntity parent;
	if (active)
	{
		if (!targets[current->faction].empty())
		{
			parent = targets[current->faction][0];
			OpQ5_eraseAt(targets[current->faction],0);
			parent->unknown5fdab0();
		}
	}
	else
		parent = world->placeEntity((EntityRecord *)current,pos,3,false,0x22,0xe,false);
	if (parent.isValid())
	{
		group.push_back(parent);
		Area area;
		cells_cfd44c.getRect(target,0xf,area);
		parent->getAI()->unknown459470(area);
		while (entityCount)
		{
			HEntity member;
			if (active)
			{
				if (!targets[element->faction].empty())
				{
					member = targets[element->faction][0];
					OpQ5_eraseAt(targets[element->faction],0);
					member->unknown5fdab0();
				}
			}
			else
				member = world->placeEntity((EntityRecord *)element,pos,3,false,0x22,0xe,false);
			if (member.isNull())
				break;
			member->getAI()->setFollowEntity(parent,0);
			entityCount--;
			group.push_back(member);
		}
		addParty(new Party(6,parent,-1,0,0),loc);
		stats29_d2c658.add4729d0(0x231,1,"",-1);
		stats29_d2c658.add4729d0(0x234,1,"",-1);
		if (recType == 0x17 && flag_d1eb68 && gameData_d1e860.isFlagEnabledB() && rng.chance(25))
		{
			string name;
			if (gameData_d1e860.getDepthIndex() >= 8)
				name = "Infiltrator_8";
			else if (gameData_d1e860.getDepthIndex() == 7)
				name = "Infiltrator_7";
			else
				name = "Infiltrator_6";
			EntityRecord30 *found;
			if (OpQ5_findByName(entityRecords30_d25de0,name,found))
			{
				for (unsigned int k = 0; k < group.size(); k++)
					group[k]->unknown45b340(new Point(values_d2f0f8[0x31],found->unknown00));
			}
		}
	}
	return group.size();
}

class Cartographer2DMoveCost;
class Cartographer2D	// NOTE: placeholder layout
{
public:
	bool findPath(const Point &a, const Point &b, Cartographer2DMoveCost *cost, void *data, vector<Point> &path);
};
extern Cartographer2D pathfinder_cfe568;			// NOTE: placeholder name
extern Cartographer2DMoveCost *moveCost_cefc30;	// NOTE: placeholder name
extern int exitTypeFlags_b90000[];				// NOTE: placeholder name
extern bool flag_cefb0a;						// NOTE: placeholder name
bool OpV4c_Fn9d0ce0(vector<Point> &list, Point p);	// NOTE: placeholder name
void OpT8a_eraseAtMapExit(vector<MapExit *> &v, unsigned int &i);	// NOTE: placeholder name (0x9ce6d0)
template <class T> void OpQ5_moveElement(vector<T> &v, unsigned int from, unsigned int to);	// NOTE: placeholder name
template <class T> void OpS8c_shuffle(vector<T> &v);	// NOTE: placeholder name

bool Overmind::findDispatchExit(Point *out, bool allowVisible, int minDistance, bool ignoreProps, const Point &from, Point **access, bool preferProps, bool ignoreUsed)
{
	vector<MapExit *> candidates;
	bool alive = false;
	for (unsigned int i = 0; i < world->exits.size(); i++)
	{
		if (exitTypeFlags_b90000[world->exits[i]->info->type] == 1 && !world->exits[i]->unknown0c
			&& (ignoreProps || world->exits[i]->prop.isNull())
			&& (world->exits[i]->prop.isNull() || (world->exits[i]->prop.operator->() && world->exits[i]->prop->unknown9b4410() == 0))
			&& (!allowVisible || world->exits[i]->prop.isValid() || (allowVisible && (!world->isVisible(world->exits[i]) || flag_cefb0a)))
			&& (minDistance == 0 || OpQ1_distanceCeil_40a3f0(world->exits[i]->pos,world->getPlayer()->getPosition()) >= minDistance)
			&& (ignoreUsed || !OpV4c_Fn9d0ce0(usedExits,world->exits[i]->pos)))
		{
			candidates.push_back(world->exits[i]);
			if (world->exits[i]->prop.isValid())
				alive = true;
		}
	}
	if (candidates.empty())
	{
		if (allowVisible || minDistance || (!ignoreUsed && !usedExits.empty()))
			return findDispatchExit(out,false,0,ignoreProps,from,access,preferProps,true);
		else
			return false;
	}
	if (ignoreProps && preferProps && alive)
	{
		for (unsigned int j = 0; j < candidates.size(); j++)
		{
			if (candidates[j]->prop.isNull())
				OpT8a_eraseAtMapExit(candidates,j);
		}
	}
	vector<MapExit *> order;
	if (from.x != -1)
	{
		vector<int> distances;
		vector<Point> path;
		for (unsigned int k = 0; k < candidates.size(); k++)
		{
			if (pathfinder_cfe568.findPath(candidates[k]->pos,from,moveCost_cefc30,0,path))
			{
				order.push_back(candidates[k]);
				distances.push_back(path.size() - 1);
			}
			path.clear();
		}
		if (order.empty())
		{
			order = candidates;
			for (unsigned int m = 0; m < order.size(); m++)
				distances.push_back(from.distanceTo(order[m]->pos));
		}
		for (int n = 1; n < order.size(); n++)
		{
			if (distances[n] < distances[n - 1])
			{
				for (int q = 0; q < n; q++)
				{
					if (distances[n] <= distances[q])
					{
						OpQ5_moveElement(order,n,q);
						OpQ5_moveElement(distances,n,q);
					}
				}
			}
		}
	}
	else
	{
		order = candidates;
		OpS8c_shuffle(order);
	}
	for (unsigned int r = 0; r < order.size(); r++)
	{
		if (world->findPlaceableNear(order[r]->pos,*out,1))
		{
			*access = (Point *)order[r];
			return true;
		}
	}
	return false;
}

SurgicalSettings::SurgicalSettings()	// NOTE: folded in the exe with ExplicitlyConstructed<Submission>::get_mutable
{
}
struct ItemData32	// NOTE: placeholder name
{
	char	pad000[0x44];
	int		unknown44;	// NOTE: placeholder name
	char	pad048[0x4c - 0x48];
	int		unknown4c;	// NOTE: placeholder name
	char	pad050[0x124 - 0x50];
	int		unknown124;	// NOTE: placeholder name
	int		unknown128;	// NOTE: placeholder name
	char	pad12c[0x1a0 - 0x12c];
	void	*unknown1a0;	// NOTE: placeholder name
};

class Item32	// NOTE: placeholder name
{
public:
	ItemData32 *getData();	// NOTE: placeholder name (trivial getter)
};

class HItem32	// NOTE: placeholder name
{
	int ID;
public:
	bool isValid() const;
	Item32 *operator->() const;
};

class Entity32	// NOTE: placeholder name (Entity)
{
public:
	int unknown5cb570(int slot, int a);	// NOTE: placeholder name
	void unknown5cb8b0(vector<HItem32> *out);	// NOTE: placeholder name
	vector<HItem32> *getInventoryList();
	int unknown5d15a0(int a);	// NOTE: placeholder name
	HItem32 unknown5d2380(int type);	// NOTE: placeholder name
};

class HEntity32	// NOTE: placeholder name
{
	int ID;
public:
	Entity32 *operator->() const;
};

class World32	// NOTE: placeholder name
{
public:
	HEntity32 getPlayer();	// 0x4630f0
};
extern World32 *world32_cefc4c;	// NOTE: placeholder name

unsigned int randomElement_uints(vector<unsigned int> &v);	// NOTE: placeholder name (folded with OpU8a_randomRec)

bool Overmind::unknown68fc40()
{
	HEntity32 current = world32_cefc4c->getPlayer();
	SurgicalSettings *base = new SurgicalSettings;
	int tags[7];
	for (int i = 0; i < 7; i++)
		tags[i] = current->unknown5cb570(i,1);
	base->unknown0 = 0;
	for (int j = 1; j < 4; j++)
	{
		if (tags[j] > tags[base->unknown0])
			base->unknown0 = j;
	}
	if (tags[base->unknown0] < 100)
		base->unknown0 = rng.rangeInt(4,6);
	else
	{
		vector<unsigned int> ties;
		for (int k = 0; k < 4; k++)
		{
			if (tags[k] == tags[base->unknown0])
				ties.push_back((unsigned int)k);
		}
		base->unknown0 = randomElement_uints(ties);
	}
	base->type = 1;
	base->unknownf = false;
	int amount = 0;
	int bestScore = 0;
	vector<HItem32> parts;
	current->unknown5cb8b0(&parts);
	for (unsigned int m = 0; m < parts.size(); m++)
	{
		ItemData32 *data = parts[m]->getData();
		if ((data->unknown128 == 0 || data->unknown128 == 1) && data->unknown124 > bestScore)
		{
			bestScore = data->unknown124;
			base->type = data->unknown128;
		}
		if (data->unknown44 == 0x12)
			amount += data->unknown4c;
	}
	vector<HItem32> *record = current->getInventoryList();
	for (unsigned int n = 0; n < record->size(); n++)
	{
		if ((*record)[n]->getData()->unknown1a0)
			base->unknownf = true;
	}
	base->unknown8 = world->unknown715730(1);
	int avg = current->unknown5d15a0(0);
	base->unknownc = avg < 100;
	base->unknownd = avg < 0x3c;
	base->unknowne = current->unknown5d2380(0x13).isValid() || current->unknown5d2380(0x1e).isValid();
	base->unknown10 = amount > 1;
	base->unknown11 = current->unknown5d2380(0x52).isValid() || current->unknown5d2380(0x54).isValid() || current->unknown5d2380(0x61).isValid();
	base->unknown12 = current->unknown5d2380(0x4e).isValid() || current->unknown5d2380(0x50).isValid() || current->unknown5d2380(0x51).isValid();
	if (surgical && *base == *surgical)
	{
		delete base;
		return false;
	}
	else
	{
		delete surgical;
		surgical = base;
		return true;
	}
}
