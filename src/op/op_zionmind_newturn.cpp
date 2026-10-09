// op_zionmind_newturn: Zionmind::newTurn (0x6bf880): delivers the pending Zion dispatch at the drone bay (robots,
//	items or a courier with supplies), rerolls/extends the pending dispatch queue, and may send a Zion hero to
//	rescue the player in the caves (COGMIND.exe Beta 17.1).
// NOTE: class layouts are partial; member, method and global names are placeholders unless noted.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
	Point(const Point &p) throw();	// 0x46ca50
};
extern Point znt_effectOrigin_d2e20c;	// NOTE: placeholder name

class Prop;
class Entity;
class Item;

class HProp
{
public:
	int ID;
	HProp();
	Prop *operator->() const;	// NOTE: OpC_Handle::get22c
	bool isValid() const;		// NOTE: folded with HItem::isValid
	void resetField();			// NOTE: placeholder name (0x9b7270)
};

class HEntity
{
public:
	int ID;
	HEntity();
	bool isValid() const;			// NOTE: folded with HItem::isValid
	Entity *operator->() const throw();	// 0x9b6570
};

class HItem
{
public:
	int ID;
	HItem();
	bool isValid() const;
	Item *operator->() const;	// NOTE: OpC_Handle::get224
};

class Prop
{
public:
	int unknown44ab40();			// NOTE: placeholder name (folded getter)
	int unknown457b10();			// NOTE: placeholder name (folded getter)
	const Point &getPosition();		// NOTE: placeholder name (0x4184d0)
	void unknown45ce10(bool a, int b, bool c, HProp d);	// NOTE: placeholder name
};

class EntityAI
{
public:
	void setFollowEntity(HEntity followEntity_, int followParam_);	// 0x5b2f80
};

class Entity
{
public:
	const string &name416f40();					// NOTE: placeholder name (0x416f40)
	vector<Point> *unknown45d1a0();				// NOTE: placeholder name
	bool unknown5c98c0(int a, int b, int c);	// NOTE: placeholder name
	void removeEffectsA(int a);					// NOTE: placeholder name (0x639730)
	EntityAI *getAI();							// 0x45b590
	void unknown6396a0(const string &name, int a);	// NOTE: placeholder name
};

class Item
{
public:
	bool unknown457ff0();			// NOTE: placeholder name
	int unknown457fb0();			// NOTE: placeholder name
	void unknown44fc60(int v);		// NOTE: placeholder name (folded setter)
	bool unknown415ee0();			// NOTE: placeholder name (folded getter)
	void unknown458390(bool flag);	// NOTE: placeholder name
	const Point &unknown575920();	// NOTE: placeholder name (position)
};

class Cell
{
public:
	HProp getProp();
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(Point &p);	// NOTE: folded (OpX5_Array2D<int>::atPoint)
};
extern CellGrid znt_cells_cfd44c;	// NOTE: placeholder name

struct OpQ5_U9d7a40	// NOTE: placeholder layout (item type record)
{
	char		pad000[0x50];
	int			minDepth;	// +0x50, NOTE: placeholder name
	char		pad054[4];
	int			decay;		// +0x58, NOTE: placeholder name
	char		pad05c[4];
	int			weight;		// +0x60, NOTE: placeholder name
	char		pad064[0x210 - 0x64];
	vector<int>	dispatches;	// +0x210, NOTE: placeholder name
};
struct OpQ5_U9d7530;	// NOTE: entity record
template <class T> bool OpQ5_findByName(vector<T*> &v, const string &name, T *&result);
extern vector<OpQ5_U9d7a40 *> znt_itemTypes_d2d1c4;	// NOTE: placeholder name
extern vector<OpQ5_U9d7530 *> znt_entityRecords_d25de0;	// NOTE: placeholder name

// declarations matching team_d_18.cpp / team_b_10.cpp (spawnDispatchGroup / spawnDispatchItems)
struct EntityRecord;
struct DispatchDef;
struct ItemType;
struct TeamB_DispatchInfo;

struct ZNT_Dispatch	// NOTE: placeholder name (OpU4_Spawn)
{
	int		type;
	string	code;
	int		count;
	~ZNT_Dispatch();	// 0x43aeb0 scalar deleting dtor
	ZNT_Dispatch(int type_);	// 0x6bec80
};

template <class T>
class OpR5h_WL	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	void add(T value, int weight);	// 0x9ba310
	T &pick();	// 0x9ba470
	T &pickNot(T value);	// 0x9ba750
	unsigned int size();	// NOTE: placeholder name (0x9b81d0)
};

struct ZNT_Location	// NOTE: placeholder name
{
	int		unknown00;
	int		type;		// +0x04
	char	pad08[0x24 - 8];
	bool	unknown24;	// +0x24
	int operate();		// 0x46ed20
};
class ZNT_HLocation	// NOTE: placeholder name
{
public:
	int ID;
	ZNT_Location *operator->() const;	// NOTE: OpC_Handle::get23c
};
extern ZNT_HLocation znt_location_d1e888;	// NOTE: placeholder name

class OpV1_GameData
{
public:
	int unknown46f4e0();	// NOTE: placeholder name
	const string &getEntryText(const string &key);
};
extern OpV1_GameData znt_gameData_d1e860;	// NOTE: placeholder name

class BS
{
public:
	Point *getBuffer_4184d0();	// NOTE: placeholder name
	int unknown4642d0();	// NOTE: placeholder name
	HEntity getPlayer();	// 0x4630f0
	HProp giveItem(const string &itemName, HEntity entity, bool a, bool b);
	HItem unknown6c51d0(OpQ5_U9d7a40 *type, HEntity entity, bool a, bool b);	// NOTE: placeholder name
	HEntity placeEntity(OpQ5_U9d7530 *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
	void unknown6c65a0(HEntity e, const string &talk, int a);	// NOTE: placeholder name
};
extern BS *znt_world_cefc4c;	// NOTE: placeholder name

class ZNT_Effect	// NOTE: placeholder name (object initialized by 0x503b20)
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name
};
class EndObjB
{
public:
	ZNT_Effect *unknown508610();	// NOTE: placeholder name
};
extern EndObjB *znt_endObj_cefc50;	// NOTE: placeholder name

class ZNT_Stats	// NOTE: placeholder name (0xd2c658)
{
public:
	vector<int> *current;
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern ZNT_Stats znt_stats_d2c658;	// NOTE: placeholder name

class ZNT_PlayerData	// NOTE: placeholder name (0xcf45d8)
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern ZNT_PlayerData znt_playerData_cf45d8;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

extern int znt_dispatchCap_bbb5bc[];		// NOTE: placeholder name (per depth)
extern int znt_heroChance_bbb5e8[];		// NOTE: placeholder name (per depth)
extern int znt_supplyCount_bbba30[];		// NOTE: placeholder name (per dispatch type)
extern bool znt_mapFlags_b90458[];		// NOTE: placeholder name (per map type)
extern int znt_defaultWeight_ba3ad0;		// NOTE: placeholder name
extern int znt_caf160;					// NOTE: placeholder name
extern string gameStrings_d29af8[];
extern string gameStrings_cf09b8[];
extern vector<int> znt_d1e920;			// NOTE: placeholder name

void logError(string location, string message);
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name
bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980)
bool OpX5_containsRecord(vector<int> &v, int value);	// NOTE: placeholder name (0x9db330)
void sweepGetSurroundingCells(const Point &p, vector<Point> &out);	// NOTE: placeholder name
void opS2_logPhrase_5141b0(int id, const string *a, const string *b, int c, HProp d, int e);	// NOTE: placeholder name
void opW5_message(int type, HProp prop, const string &text, int value);	// NOTE: placeholder name

class OpU4_Obj6bed40	// NOTE: placeholder name (same object as Zionmind; method defined in src/op/op_u4.cpp)
{
public:
	void unknown6bed40(OpR5h_WL<int> *a, OpR5h_WL<int> *b);	// NOTE: placeholder name
};

class Zionmind
{
public:
	char			pad00[0x20];
	vector<int>		heroes;			// +0x20
	vector<int>		heroSent;		// +0x30
	int				lastHeroDepth;	// +0x40
	int				unknown44;
	vector<int>		dispatchRecords;	// +0x48
	vector<ZNT_Dispatch *> queue;	// +0x58
	ZNT_Dispatch	*dispatch;		// +0x68
	HProp			bay;			// +0x6c

	void spawnDispatchGroup(const Point &pos, EntityRecord *record, int mode, DispatchDef *def, vector<HEntity> *out);
	void spawnDispatchItems(const Point &pos, ItemType *type, TeamB_DispatchInfo *info, vector<HItem> &items);
	void newTurn();
};

#define ZNT_LOG(id, a) do { opS2_logPhrase_5141b0(id,a,0,0,HProp(),0); } while (0)

void Zionmind::newTurn()
{
	int depth = znt_location_d1e888->operate();
	if (znt_dispatchCap_bbb5bc[depth] != 0 && znt_mapFlags_b90458[znt_location_d1e888->type] && !dispatchRecords.empty())
	{
		if (dispatch != NULL)
		{
			if (bay.operator->() != NULL && bay->unknown457b10() == 0)
			{
				Point pos(bay->getPosition());
				vector<Point> neighbors;
				sweepGetSurroundingCells(pos,neighbors);
				for (unsigned int i = 0; i < neighbors.size(); i++)
				{
					if ((*znt_cells_cfd44c.atPoint(neighbors[i]))->getProp().isValid() && (*znt_cells_cfd44c.atPoint(neighbors[i]))->getProp()->unknown44ab40() == bay->unknown44ab40())
						(*znt_cells_cfd44c.atPoint(neighbors[i]))->getProp()->unknown45ce10(true,0,true,HProp());
				}
				(*znt_cells_cfd44c.atPoint(pos))->getProp()->unknown45ce10(true,0,true,HProp());
				OpQ5_U9d7530 *entityRec;
				OpQ5_U9d7a40 *bayItem;
				int dispType = dispatch->type;
				vector<HEntity> entities;
				vector<HItem> items;
				if (dispType <= 7)
				{
					if (dispatchRecords[dispType] == znt_caf160)
					{
						switch (dispType)
						{
						case 2:
							if (!OpQ5_findByName(znt_itemTypes_d2d1c4,"Z-Drone Bay",bayItem))
							{
								logError("Zionmind::newTurn()","found no bay for " + gameStrings_d29af8[dispType]);
								break;
							}
							spawnDispatchItems(pos,(ItemType *)bayItem,(TeamB_DispatchInfo *)dispatch,items);
							break;
						case 6:
							if (!OpQ5_findByName(znt_entityRecords_d25de0,depth == 10 ? "Z_Experiment_10" : "Z_Experiment_10",entityRec))
							{
								logError("Zionmind::newTurn()","found no Ent for " + gameStrings_d29af8[dispType]);
								break;
							}
							spawnDispatchGroup(pos,(EntityRecord *)entityRec,2,(DispatchDef *)dispatch,&entities);
							break;
						case 7:
							entityRec = znt_entityRecords_d25de0[heroes[znt_location_d1e888->operate()]];
							spawnDispatchGroup(pos,(EntityRecord *)entityRec,2,(DispatchDef *)dispatch,&entities);
							lastHeroDepth = znt_location_d1e888->operate();
							heroes[znt_location_d1e888->operate()] = znt_caf160;
							opR1d_4541b0(300,0,0);
							znt_playerData_cf45d8.unknown77fbc0(0xcd);
							break;
						}
					}
					else
					{
						entityRec = znt_entityRecords_d25de0[dispatchRecords[dispType]];
						spawnDispatchGroup(pos,(EntityRecord *)entityRec,2,(DispatchDef *)dispatch,&entities);
					}
					if (!entities.empty() && !gameStrings_cf09b8[dispType].empty() && !dispatch->code.empty())
						znt_world_cefc4c->unknown6c65a0(entities.front(),"ZIO_Dispatch_" + gameStrings_cf09b8[dispType],0);
				}
				else
				{
					if (!OpQ5_findByName(znt_entityRecords_d25de0,"Z_Courier",entityRec))
					{
					}
					else
					{
						spawnDispatchGroup(pos,(EntityRecord *)entityRec,1,(DispatchDef *)dispatch,&entities);
						if (!entities.empty())
						{
							if (dispType == 12)
								znt_world_cefc4c->giveItem("Trap Extractor",entities[0],false,false);
							OpR5h_WL<int> wl;
							int odds;
							float mult;
							for (unsigned int i = 0; i < znt_itemTypes_d2d1c4.size(); i++)
							{
								if (OpX5_containsRecord(znt_itemTypes_d2d1c4[i]->dispatches,dispType) && depth >= znt_itemTypes_d2d1c4[i]->minDepth)
								{
									mult = 1.0f;
									switch (znt_itemTypes_d2d1c4[i]->decay)
									{
										break;
									case 1:
									case 2:
										mult -= (znt_gameData_d1e860.unknown46f4e0() - znt_itemTypes_d2d1c4[i]->minDepth) * (znt_itemTypes_d2d1c4[i]->decay == 1 ? 0.35f : 0.15f);
										if (mult <= 0.0)
											continue;
										break;
									}
									odds = (znt_itemTypes_d2d1c4[i]->weight ? znt_itemTypes_d2d1c4[i]->weight : znt_defaultWeight_ba3ad0) * mult;
									if (odds > 0)
										wl.add(i,odds);
								}
							}
							if (wl.size() == 0)
							{
							}
							else
							{
								bool placed = false;
								HItem item;
								for (int count = znt_supplyCount_bbba30[dispType]; count != 0; count--)
								{
									item = znt_world_cefc4c->unknown6c51d0(znt_itemTypes_d2d1c4[wl.pick()],entities[0],false,true);
									if (item.isValid())
									{
										if (item->unknown457ff0())
											item->unknown44fc60(item->unknown457fb0());
										if (item->unknown415ee0())
										{
											if (placed)
												item->unknown458390(false);
											else
												placed = true;
										}
									}
								}
							}
						}
					}
				}
				if (!entities.empty() || !items.empty())
				{
					int effect;
					if (OpU8a_lookup2("Zion_Dispatch",&effect))
					{
						for (unsigned int i = 0; i < entities.size(); i++)
						{
							vector<Point> *points = entities[i]->unknown45d1a0();
							for (unsigned int j = 0; j < points->size(); j++)
								znt_endObj_cefc50->unknown508610()->init(znt_endObj_cefc50,effect,(*points)[j],znt_effectOrigin_d2e20c,0,0,0,9,0);
						}
						for (unsigned int k = 0; k < items.size(); k++)
							znt_endObj_cefc50->unknown508610()->init(znt_endObj_cefc50,effect,items[k]->unknown575920(),znt_effectOrigin_d2e20c,0,0,0,9,0);
					}
					opR1d_4541b0(0xb4,0,0);
					znt_stats_d2c658.add4729d0(0x381,1,"",-1);
					znt_stats_d2c658.add4729d0(dispType + 0x382,1,"",-1);
					if ((*znt_stats_d2c658.current)[0x381] == 10)
						znt_playerData_cf45d8.unknown77fbc0(0xcc);
					if (dispType <= 7)
					{
						if (dispType == 7)
							ZNT_LOG(0x86,&entities.front()->name416f40());
						else
							ZNT_LOG(0x85,&gameStrings_d29af8[dispType]);
					}
					else
						ZNT_LOG(0x87,&gameStrings_d29af8[dispType]);
				}
			}
			delete dispatch;
			dispatch = NULL;
			bay.resetField();
		}
		bool altered = false;
		OpR5h_WL<int> robots;
		OpR5h_WL<int> supplies;
		((OpU4_Obj6bed40 *)this)->unknown6bed40(&robots,&supplies);
		if (znt_world_cefc4c->unknown4642d0() % 300 == 0)
		{
			bool hasHero = false;
			for (unsigned int i = 0; i < queue.size(); i++)
			{
				if (queue[i]->type == 7)
				{
					hasHero = true;
					break;
				}
			}
			for (unsigned int j = 0; j < queue.size(); j++)
			{
				if (rng.chance(25))
				{
					delete queue[j];
					queue[j] = new ZNT_Dispatch(rng.chance(znt_heroChance_bbb5e8[depth]) ? (hasHero ? robots.pickNot(7) : robots.pick()) : supplies.pick());
					if (queue[j]->type == 7)
						hasHero = true;
					altered = true;
				}
			}
		}
		if (znt_world_cefc4c->unknown4642d0() % 410 == 0)
		{
			bool hasHero = false;
			for (unsigned int i = 0; i < queue.size(); i++)
			{
				if (queue[i]->type == 7)
				{
					hasHero = true;
					break;
				}
			}
			for (int j = queue.size(); j < znt_dispatchCap_bbb5bc[depth]; j++)
			{
				if (rng.chance(33))
				{
					queue.push_back(new ZNT_Dispatch(rng.chance(znt_heroChance_bbb5e8[depth]) ? (hasHero ? robots.pickNot(7) : robots.pick()) : supplies.pick()));
					if (queue.back()->type == 7)
						hasHero = true;
					altered = true;
				}
			}
		}
		if (altered)
		{
			for (int i = 1; i <= 6; i++)
				znt_d1e920[i] = 0;
		}
	}
	if ((znt_location_d1e888->type == 0x10 || znt_location_d1e888->type == 0x11) && heroes[depth] != znt_caf160 && !stringToInt(znt_gameData_d1e860.getEntryText("zioAttackedLocals_g")) && heroSent[depth] == 0 && znt_world_cefc4c->getPlayer()->unknown5c98c0(1,0x19,1))
	{
		heroSent[depth] = 1;
		if (rng.chance(znt_location_d1e888->unknown24 ? 10 : 25))
		{
			heroSent.assign(heroSent.size(),1);
			HEntity hero = znt_world_cefc4c->placeEntity(znt_entityRecords_d25de0[heroes[depth]],*znt_world_cefc4c->getBuffer_4184d0(),2,false,0x22,0xe,false);
			if (hero.isValid())
			{
				hero->removeEffectsA(0);
				hero->getAI()->setFollowEntity(znt_world_cefc4c->getPlayer(),2);
				hero->unknown6396a0("ZIO_Cave_Rescue_Hero_1",0);
				opW5_message(0x320,HProp(),string("A strange signal echoes through the caves."),0);
				opR1d_4541b0(300,0,0);
				heroes[depth] = znt_caf160;
			}
		}
	}
}
