// alpha2_14: Entity special-item pickup (0x5dfd80): data cores, derelict logs, schematic archives, matter caches
//	and protomatter are consumed (with their effects) when an entity steps onto them.
// NOTE: placeholder names / placeholder layout throughout; private aliases for mapped callees.
#include <string>
#include <vector>
#include "rng.h"
using std::string;
using std::vector;
extern RNG rng;

struct A2KEntity;
struct A2KItem;
struct A2KProp;
struct A2KPoint
{
	int x;
	int y;
	A2KPoint() throw();	// 0x453b40
	A2KPoint(int x_, int y_) throw();	// 0x46ca20
	A2KPoint(const A2KPoint &other) throw();	// 0x46ca50
	void set_40a060(const A2KPoint &base, int dx, int dy) throw();
};
struct A2KRange
{
	int low;
	int high;
	A2KRange() throw();	// 0x40bef0
	void set_40a010(int low_, int high_) throw();
	int randomInRange_40c130() throw();
};
struct A2KHE	// HEntity
{
	int id;
	A2KHE() throw();	// 0x9b6590
	A2KEntity *get_9b6570() const throw();
};
struct A2KHI	// HItem
{
	int id;
	A2KHI() throw();	// 0x9b6590
	A2KItem *get_9b65b0() const throw();
	bool valid_9b7230() const throw();
};
struct A2KHP	// HProp
{
	int id;
	A2KProp *get_9b64f0() const throw();
};
struct A2KTrap
{
	bool armedFor_65cf50(int faction);
};
struct A2KPropDef
{
	char pad0[0x3c];
	int expires;	// +0x3c
};
struct A2KProp
{
	A2KPropDef *def_45cb30() throw();
	bool unknown45cc10();
	int unknown65f170();
	A2KTrap *trap_44b020() throw();
};
struct A2KEffectDef;
struct A2KEffect
{
	A2KEffectDef *def;
	int amount;
	A2KEffect(A2KEffectDef *d, int a) : def(d), amount(a) {}
};
struct A2KItem
{
	void *data_44a7d0() throw();
	int charges_45cb30() throw();
	int itemId_457820() throw();
	int kind_457880() throw();
	int getEffectValue_457be0(int effect) throw();
	bool unknown457db0() throw();
	int unknown457f90() throw();
	void addEffect_4585a0(A2KEffect *effect);
	void setIntegrity_450460(int value) throw();
	int integrity_9b6bf0() throw();
	string getName_571db0(bool full, bool label);
	void remove_57dbe0(bool a, bool b, bool c, bool d);
};
struct A2KCell
{
	A2KHI getItem_45d8f0();
	A2KHP getProp_45d550();
	bool unknown45dbb0();
	bool isEdge_45dc30() throw();
	bool isMachinePart_45dcd0() throw();
	bool hasTrap_45dcf0();
	bool unknown66b1c0(int a, int b);
	void unknown670690();
	void unknown670b20();
};
struct A2KGrid
{
	int getWidth_9fcd80() throw();
	int getHeight_9b8f00() throw();
	A2KCell **at_9ceda0(int x, int y) throw();
	A2KCell **atPoint_9ced70(A2KPoint &p) throw();
};
struct A2KIntGrid
{
	int *at_9ceda0(int x, int y) throw();
};
struct A2KZone
{
	char pad0[0x08];
	int machine;	// +0x08
	char padc;
	bool found;	// +0x0d
	void label_6c16d0(string text);
};
struct A2KZones;
struct A2KMap
{
	A2KZone *getZone_462e30(const A2KPoint &p);
	bool isKnown_463130(int x, int y);
	bool unknown463e90(const A2KPoint &p);
	int getTurn_464270() throw();
	void unknown4647d0(const A2KPoint &p);
	int selectRandomItem_6c3bc0(int category, int type, int level);
	A2KHI spawnItem_6c5400(int item, A2KPoint &p);
	void announceMachine_71dd30(int machine);
	bool findDrop_71ec60(A2KPoint &p, vector<A2KPoint> area);
	void reveal_7243c0(int x, int y, bool full);
	void revealTrap_724420(int x, int y);
	void unknown734d60(const A2KPoint &p);
	void unknown9e29b0(void *list, A2KHP prop);
	char pad0[0x720];
	char list720;	// +0x720
};
struct A2KFov
{
	void compute_40ca20(A2KPoint &origin, int range, void *cost, int *flags);
};
struct A2KMessage
{
	A2KMessage(int id, string *a, string *b, string *c, A2KHE entity, A2KHE other);	// 0x510d20
	int data[0x20 / 4];
};
struct A2KInterface
{
	void add_7b1880(A2KMessage *message);
};
struct A2KMapView
{
	void unknown49ad30();
	const A2KPoint &offset_458ef0() throw();
	bool inBounds_4173d0(const A2KPoint &p) throw();
	void label_813050(bool flag, A2KHP prop, int a, int b, int c);
	void labelAccess_80e3a0(bool flag, const A2KPoint &p);
};
struct A2KEffects
{
	A2KEffectDef *create_50fb50(A2KEffects *engine, int id, const A2KPoint &pos, const A2KPoint *a, const A2KPoint *b, const A2KPoint *c, int layer);
};
struct A2KFx
{
	void init_50de10();
};
struct A2KConsole
{
	void bubble_8758d0(bool flag);
};
struct A2KLog
{
	void scrollToEnd_7b4f10();
};
struct A2KStats
{
	bool add_4729d0(unsigned int id, int value, string text, int extra);
};
struct A2KPlayerData
{
	bool event_77fbc0(int id);
	void unknown77ffb0(int item, bool flag);
	bool unknown780380(int item, int type);
	bool unknown780480(int item, int type);
	void unknown780700(int robot, bool flag);
	int addCapped_77eca0(int amount);
};
struct A2KInventoryUI
{
	void reopen_8a2ce0(int mode, A2KHE entity);
};
struct A2KGameData
{
	void setEntryText_46f700(const string &key, const string &value);
};
struct A2KGM
{
	void addItemAttachCount_778560(int item, int count, int extra);
};
struct A2KFactory
{
	void showOnce_793450(int id, int a, int b, int c, int d);
};
struct A2KWorldRecord
{
	int pad0;
	int type;	// +0x04
};
struct A2KWorldHandle
{
	int id;
	A2KWorldRecord *get_9b7910() const throw();
};
struct A2KWeights
{
	int &pick_9ba470();
};
struct A2KRecord
{
	char pad0[0x1bc];
	string name;	// +0x1bc
};
struct A2KLogRecord
{
	char pad0[0xc0];
	vector<A2KRecord *> entries;	// +0xc0
};
struct A2KRobotDef
{
	int id;	// +0x00
	char pad04[0xe8 - 0x04];
	int fabricable;	// +0xe8
	char padec[0x114 - 0xec];
	bool discovered;	// +0x114
	char pad115[0x118 - 0x115];
	int known;	// +0x118
	char pad11c[0x170 - 0x11c];
	string analysis;	// +0x170
	char pad18c[0x1ac - 0x18c];
	string name;	// +0x1ac
};
struct A2KItemDef
{
	char pad0[0x24];
	string name;	// +0x24
	char pad40[0x271 - 0x40];
	bool unique;	// +0x271
};
struct A2KEntityDef
{
	char pad0[0x28];
	int type;	// +0x28
	char pad2c[0xa8 - 0x2c];
	bool collects;	// +0xa8
};

extern A2KMap *a2k_map_cefc4c;
extern A2KGrid a2k_grid_cfd44c;
extern A2KIntGrid originalTerrain;
extern int *TERRAIN_EARTH;
extern A2KMapView *a2k_mapView_cec054;
extern A2KInterface *a2k_interface_cec0f4;
extern A2KInventoryUI *a2k_parts_cec08c;
extern A2KEffects *a2k_effects_cefc64;
extern A2KFactory *a2k_factory_cefaa8;
extern A2KConsole *a2k_console_cec058;
extern A2KLog *a2k_log_cec0b4;
extern A2KStats a2k_stats_d2c658;
extern A2KPlayerData a2k_player_cf45d8;
extern A2KGameData a2k_gameData_d1e860;
extern A2KGM a2k_gm_d25628;
extern A2KFov a2k_fov_cfe568;
extern char a2k_cost_cfd428[];
extern vector<A2KPoint> a2k_visible_d15e58;
extern vector<A2KLogRecord *> a2k_logs_d2c408;
extern vector<A2KRobotDef *> a2k_robots_d25de0;
extern vector<A2KItemDef *> a2k_items_d2d1c4;
extern vector<A2KEffectDef *> a2k_effects_d2f0f8;
extern vector<int> a2k_analyzed_cf4910;
extern vector<int> a2k_known_cf4830;
extern A2KWorldHandle a2k_world_d1e888;
extern A2KWeights a2k_weights_d31700;
extern A2KPoint a2k_none_cfbec0;
extern int a2k_mode_cf462c;
extern int a2k_difficulty_cf4718;
extern int a2k_hackBonus_cf49e0;
extern bool a2k_backdoor_cf49e4;
extern int a2k_logCount_cf4d80;
extern const char a2k_empty_b9449f[];
extern const char a2k_empty_b944a7[];
extern const char a2k_empty_b944b3[];

bool a2k_trigger_4569a0(int type, A2KHE a, A2KHE b, A2KHE c, A2KHI d, A2KPoint *pos, const string *name, void *data, A2KHE e, A2KHE f, A2KHI g, A2KPoint *pos2);
bool a2k_show_5111e0(int id, const string &text, string *a, string *b, A2KHE entity, A2KHE other, int c, int d);
bool a2k_show0_5111e0(int id, int text, string *a, string *b, A2KHE entity, A2KHE other, int c, int d);
void a2k_logPhrase_5141b0(int id, string *a, string *b, string *c, A2KHE entity, int d);
void a2k_message_49c610(int id, A2KHE entity, const string &text, int a);
string a2k_intToString_4051f0(int value);
string a2k_expand_510110(const string &text, int a);
void a2k_codex_797e60(string &entry, int a);
void a2k_eraseFirst_4077e0(string &text);
void a2k_eraseLast_407840(string &text);
bool a2k_lookup_9d45a0(const string &name, int *id);
void a2k_clearDijkstra_4faf40();
void a2k_sound_4541b0(int id, int a, int b);
int a2k_randomItem_777cf0();
bool a2k_findByName_9d7a40(vector<A2KItemDef *> &list, const string &name, int &index);
int a2k_indexOfName_9d74d0(vector<A2KItemDef *> &list, const string &name);
void a2k_eraseAt_9ce6d0(vector<int> &list, unsigned int &index);

#define A2K_MSG(ID,TEXT) do{if(a2k_show_5111e0(ID,TEXT,0,0,self,A2KHE(),0,0))a2k_console_cec058->bubble_8758d0(true);a2k_log_cec0b4->scrollToEnd_7b4f10();}while(false)
#define A2K_MSG0(ID) do{if(a2k_show0_5111e0(ID,0,0,0,self,A2KHE(),0,0))a2k_console_cec058->bubble_8758d0(true);a2k_log_cec0b4->scrollToEnd_7b4f10();}while(false)
#define A2K_LOG(ID,TEXT) do{a2k_logPhrase_5141b0(ID,TEXT,0,0,A2KHE(),0);}while(false)

struct A2KEntity
{
	void pickUp();
	bool isPlayer_5c7600() throw();
	void collect_5e2590(A2KHI item, int a, int b);
	void unknown5e2840(A2KHI item);
	void unknown5e29e0(A2KHI item);

	int pad0;
	A2KHE self;	// +0x04
	A2KEntityDef *def;	// +0x08
	char padc[0x30 - 0x0c];
	vector<A2KPoint> cells;	// +0x30
};

void A2KEntity::pickUp()
{
	for (unsigned int i = 0; i < cells.size(); i++)
	{
		A2KPoint p(cells[i]);
		A2KHI item = a2k_grid_cfd44c.atPoint_9ced70(p)[0]->getItem_45d8f0();
		if (item.valid_9b7230())
		{
		if (isPlayer_5c7600())
		{
			switch (item.get_9b65b0()->kind_457880())
			{
				case 1:
				case 2:
				{
					A2KHE current = self;
					if (a2k_trigger_4569a0(8,self,A2KHE(),A2KHE(),item,0,&item.get_9b65b0()->getName_571db0(false,false),item.get_9b65b0()->data_44a7d0(),self,A2KHE(),item,0))
					{
						if (!item.get_9b65b0() || item.get_9b65b0()->getEffectValue_457be0(129) || !current.get_9b6570())
						{
							if (item.get_9b65b0())
								item.get_9b65b0()->remove_57dbe0(false,true,true,true);
							return;
						}
					}
				}
			}
		}
		switch (item.get_9b65b0()->kind_457880())
		{
			case 0:
				if (def->collects)
					collect_5e2590(item,0,0);
				break;
			case 1:
				if (isPlayer_5c7600())
				{
					if (item.get_9b65b0()->getName_571db0(false,false) == "Data Core")
					{
						int expires = item.get_9b65b0()->charges_45cb30();
						if (a2k_map_cefc4c->getTurn_464270() > expires)
							A2K_MSG0(6);
						else
						{
							A2K_MSG0(4);
							a2k_stats_d2c658.add_4729d0(756,1,a2k_empty_b9449f,-1);
							A2KPoint target(item.get_9b65b0()->getEffectValue_457be0(76),item.get_9b65b0()->getEffectValue_457be0(77));
							if (a2k_grid_cfd44c.atPoint_9ced70(target)[0]->unknown66b1c0(0,0))
								a2k_grid_cfd44c.atPoint_9ced70(target)[0]->getProp_45d550().get_9b64f0()->def_45cb30()->expires = expires;
							a2k_clearDijkstra_4faf40();
							int found = 1;
							a2k_fov_cfe568.compute_40ca20(p,24,a2k_cost_cfd428,&found);
							vector<A2KPoint> *vec = &a2k_visible_d15e58;
							int changed = 0;
							for (unsigned int v = 0; v < vec->size(); v++)
							{
								if (a2k_grid_cfd44c.atPoint_9ced70((*vec)[v])[0]->getProp_45d550().get_9b64f0()->unknown45cc10())
								{
									changed++;
									a2k_grid_cfd44c.atPoint_9ced70((*vec)[v])[0]->getProp_45d550().get_9b64f0()->unknown65f170();
									a2k_map_cefc4c->unknown4647d0((*vec)[v]);
									if (a2k_grid_cfd44c.atPoint_9ced70((*vec)[v])[0]->getProp_45d550().get_9b64f0()->trap_44b020()->armedFor_65cf50(0))
									{
										a2k_interface_cec0f4->add_7b1880(new A2KMessage(59,0,0,0,A2KHE(),A2KHE()));
										a2k_mapView_cec054->unknown49ad30();
									}
									a2k_mapView_cec054->label_813050(true,a2k_grid_cfd44c.atPoint_9ced70((*vec)[v])[0]->getProp_45d550(),0,0,0);
									a2k_map_cefc4c->unknown9e29b0(&a2k_map_cefc4c->list720,a2k_grid_cfd44c.atPoint_9ced70((*vec)[v])[0]->getProp_45d550());
								}
							}
							if (changed)
								A2K_MSG(5,a2k_intToString_4051f0(changed));
							a2k_factory_cefaa8->showOnce_793450(69,1,0,0,0);
						}
					}
					else if (item.get_9b65b0()->getName_571db0(false,false) == "Derelict Log")
					{
						A2K_MSG0(7);
						a2k_stats_d2c658.add_4729d0(976,1,a2k_empty_b944a7,-1);
						vector<A2KRecord *> *entries = &a2k_logs_d2c408[item.get_9b65b0()->getEffectValue_457be0(78)]->entries;
						for (unsigned int e = 0; e < entries->size(); e++)
						{
							string entry = (*entries)[e]->name;
							a2k_eraseFirst_4077e0(entry);
							a2k_eraseLast_407840(entry);
							a2k_codex_797e60(entry,0);
						}
					}
					else if (item.get_9b65b0()->getName_571db0(false,false) == "Schematic Archive")
					{
						int schematic = item.get_9b65b0()->getEffectValue_457be0(79);
						if (schematic < 0)
						{
							schematic = -schematic;
							a2k_player_cf45d8.unknown780480(schematic,7);
							A2K_MSG(8,a2k_robots_d25de0[schematic]->name);
						}
						else
						{
							if (a2k_player_cf45d8.unknown780380(schematic,7))
								a2k_parts_cec08c->reopen_8a2ce0(4,A2KHE());
							A2K_MSG(8,a2k_items_d2d1c4[schematic]->name);
						}
						if (item.get_9b65b0()->getEffectValue_457be0(80))
						{
							a2k_logCount_cf4d80++;
							if (a2k_logCount_cf4d80 == 20)
								a2k_player_cf45d8.event_77fbc0(305);
						}
					}
					else if (item.get_9b65b0()->getName_571db0(false,false) == "Imprinter Data Core")
					{
						string text("Acquired data core, extracted access codes <mhack=DEEP_ACCESS_1>, <mhack=DEEP_ACCESS_2>, <mhack=DEEP_ACCESS_3>, <mhack=DEEP_ACCESS_4>.");
						for (int k = 0; k < 4; k++)
							text = a2k_expand_510110(text,0);
						A2K_MSG(9,text);
						A2K_LOG(375,0);
					}
					else if (item.get_9b65b0()->getName_571db0(false,false) == "0b10 Backdoor Data")
					{
						a2k_hackBonus_cf49e0 += 10;
						a2k_backdoor_cf49e4 = true;
						string text("Acquired data core, extracted CY-PHR backdoor node locations to facilitate hacking 0b10 systems (permanent +10%).");
						A2K_MSG(9,text);
						A2K_LOG(151,0);
					}
					else if (item.get_9b65b0()->getName_571db0(false,false) == "CL-0N3 Data Core")
					{
						int count = 0;
						int updated = 0;
						for (unsigned int r = 0; r < a2k_robots_d25de0.size(); r++)
						{
							if (a2k_robots_d25de0[r]->discovered || a2k_robots_d25de0[r]->known)
							{
								if (a2k_robots_d25de0[r]->fabricable && a2k_player_cf45d8.unknown780480(a2k_robots_d25de0[r]->id,7))
									count++;
								if (!a2k_robots_d25de0[r]->analysis.empty() && !a2k_analyzed_cf4910[r])
								{
									a2k_player_cf45d8.unknown780700(r,true);
									updated++;
								}
							}
						}
						string text = "Acquired data core, extracted " + a2k_intToString_4051f0(count) + " schematics, " + a2k_intToString_4051f0(updated) + " analyses.";
						A2K_MSG(9,text);
						A2K_LOG(146,0);
					}
					else if (item.get_9b65b0()->getName_571db0(false,false) == "A7 Data Core")
					{
						a2k_gameData_d1e860.setEntryText_46f700("extAcquiredA7DataCore_g","1");
						string text("Acquired data core, extracted ID and sensor data for unrecognized location.");
						A2K_MSG(9,text);
						A2K_LOG(418,0);
					}
					else if (item.get_9b65b0()->getName_571db0(false,false) == "A2 Data Core")
					{
						a2k_gameData_d1e860.setEntryText_46f700("ac0AcquiredA2DataCore_g","1");
						string text("Acquired data core, extracted Singularity Gate Test 138-C access codes.");
						A2K_MSG(9,text);
						A2K_LOG(551,0);
					}
					else if (item.get_9b65b0()->getName_571db0(false,false) == "Architect Data Core")
					{
						a2k_gameData_d1e860.setEntryText_46f700("ac0AcquiredArchitectDataCore_g","1");
						string text("Acquired data core, extracted unknown sensor trigger ID.");
						A2K_MSG(9,text);
						A2K_LOG(553,0);
					}
					else if (item.get_9b65b0()->getName_571db0(false,false) == "MAIN.C Data Core")
					{
						for (unsigned int k = 0; k < a2k_items_d2d1c4.size(); k++)
						{
							if (!a2k_items_d2d1c4[k]->unique)
								a2k_player_cf45d8.unknown77ffb0(k,false);
						}
						int tile = 0;
						a2k_lookup_9d45a0("CMap_Layout_Reveal_MC_DataCore",&tile);
						A2KPoint offset(a2k_mapView_cec054->offset_458ef0());
						A2KPoint p2;
						for (int x = 15; x < a2k_grid_cfd44c.getWidth_9fcd80(); x++)
						{
							for (int y = 0; y < a2k_grid_cfd44c.getHeight_9b8f00(); y++)
							{
								if (*originalTerrain.at_9ceda0(x,y) != *TERRAIN_EARTH)
								{
									if (a2k_grid_cfd44c.at_9ceda0(x,y)[0]->hasTrap_45dcf0())
									{
										a2k_grid_cfd44c.at_9ceda0(x,y)[0]->getProp_45d550().get_9b64f0()->unknown65f170();
										a2k_map_cefc4c->revealTrap_724420(x,y);
									}
									else if (a2k_grid_cfd44c.at_9ceda0(x,y)[0]->isEdge_45dc30() && !a2k_map_cefc4c->unknown463e90(A2KPoint(x,y)))
									{
										a2k_map_cefc4c->unknown734d60(A2KPoint(x,y));
										bool open = false;
										if (a2k_grid_cfd44c.at_9ceda0(x,y)[0]->unknown45dbb0())
										{
											a2k_grid_cfd44c.at_9ceda0(x,y)[0]->unknown670690();
											open = true;
										}
										a2k_map_cefc4c->reveal_7243c0(x,y,true);
										if (open)
											a2k_grid_cfd44c.at_9ceda0(x,y)[0]->unknown670b20();
									}
									else if (!a2k_map_cefc4c->isKnown_463130(x,y))
									{
										if (a2k_grid_cfd44c.at_9ceda0(x,y)[0]->getItem_45d8f0().valid_9b7230())
											a2k_map_cefc4c->reveal_7243c0(x,y,false);
										else
											a2k_map_cefc4c->reveal_7243c0(x,y,true);
									}
									if (a2k_grid_cfd44c.at_9ceda0(x,y)[0]->isMachinePart_45dcd0())
									{
										A2KZone *zone = a2k_map_cefc4c->getZone_462e30(A2KPoint(x,y));
										if (a2k_difficulty_cf4718 == 2)
											a2k_map_cefc4c->announceMachine_71dd30(zone->machine);
										zone->found = true;
										zone->label_6c16d0("FOUND");
										a2k_mapView_cec054->labelAccess_80e3a0(true,A2KPoint(x,y));
									}
									p2.set_40a060(offset,x,y);
									if (a2k_mapView_cec054->inBounds_4173d0(p2))
										((A2KFx *)a2k_effects_cefc64->create_50fb50(a2k_effects_cefc64,tile,p2,&a2k_none_cfbec0,0,0,9))->init_50de10();
								}
							}
						}
						a2k_parts_cec08c->reopen_8a2ce0(4,A2KHE());
						string text("Acquired data core, extracted map data and part IDs.");
						A2K_MSG(9,text);
						A2K_LOG(546,0);
					}
					a2k_gm_d25628.addItemAttachCount_778560(item.get_9b65b0()->itemId_457820(),1,0);
					item.get_9b65b0()->remove_57dbe0(false,true,true,true);
				}
				break;
			case 2:
				if (isPlayer_5c7600() || def->type == 73)
				{
					A2K_MSG0(isPlayer_5c7600() ? 10 : 12);
					if (isPlayer_5c7600())
						a2k_stats_d2c658.add_4729d0(1032,1,a2k_empty_b944b3,-1);
					int base = item.get_9b65b0()->charges_45cb30();
					int x2 = item.get_9b65b0()->itemId_457820();
					int value = item.get_9b65b0()->getEffectValue_457be0(103);
					item.get_9b65b0()->remove_57dbe0(false,true,true,true);
					rng.seed(base);
					vector<int> candidates;
					if (value)
					{
						A2KRange count;
						if (value == 1)
							count.set_40a010(2,4);
						else
							count.set_40a010(6,8);
						for (int level = 0; level < 4; level++)
						{
							for (int n = count.randomInRange_40c130(); n > 0; n--)
							{
								int id = a2k_map_cefc4c->selectRandomItem_6c3bc0(n == 1 && rng.chance(25) ? 0 : 2,31,level);
								if (id == 0)
									break;
								else
									candidates.push_back(id);
							}
						}
					}
					else if (a2k_world_d1e888.get_9b7910()->type == 15)
					{
						for (int n = rng.rangeInt(1,2); n > 0; n--)
							candidates.push_back(a2k_randomItem_777cf0());
					}
					else
					{
						for (int n = rng.rangeInt(1,4); n > 0; n--)
						{
							int id = a2k_map_cefc4c->selectRandomItem_6c3bc0(2,31,18);
							if (id == 0)
								break;
							else
								candidates.push_back(id);
						}
						if (rng.chance(1))
							candidates.push_back(a2k_weights_d31700.pick_9ba470());
					}
					int a1;
					a2k_findByName_9d7a40(a2k_items_d2d1c4,"Matter",a1);
					candidates.push_back(a1);
					A2KHI record;
					vector<A2KHI> hits;
					A2KRange temp;
					A2KRange amount;
					if (value)
					{
						temp.set_40a010(80,100);
						amount.set_40a010(100,200);
					}
					else
					{
						temp.set_40a010(50,90);
						amount.set_40a010(30,70);
					}
					for (unsigned int k = 0; k < candidates.size(); k++)
					{
						vector<A2KPoint> area(1,p);
						if (a2k_grid_cfd44c.atPoint_9ced70(p)[0]->getItem_45d8f0().valid_9b7230() && !a2k_map_cefc4c->findDrop_71ec60(p,area))
							a2k_eraseAt_9ce6d0(candidates,k);
						else
						{
							record = a2k_map_cefc4c->spawnItem_6c5400(candidates[k],p);
							if (record.valid_9b7230())
							{
								if (record.get_9b65b0()->kind_457880() == 0)
									record.get_9b65b0()->setIntegrity_450460(amount.randomInRange_40c130());
								else
								{
									record.get_9b65b0()->addEffect_4585a0(new A2KEffect(a2k_effects_d2f0f8[102],1));
									record.get_9b65b0()->setIntegrity_450460(record.get_9b65b0()->integrity_9b6bf0() * temp.randomInRange_40c130() / 100);
								}
								hits.push_back(record);
							}
						}
					}
					if (!hits.empty())
					{
						a2k_sound_4541b0(178,0,0);
						for (unsigned int k = 0; k < hits.size(); k++)
							A2K_MSG(isPlayer_5c7600() ? 11 : 13,hits[k].get_9b65b0()->getName_571db0(false,false));
					}
					if (value && isPlayer_5c7600())
					{
						if (value == 1)
							a2k_message_49c610(800,A2KHE(),string("A note is attached: \"With love, from the DCF.\""),0);
						A2K_LOG(266,&a2k_intToString_4051f0(hits.size()));
					}
					a2k_gm_d25628.addItemAttachCount_778560(x2,1,0);
				}
				break;
			case 3:
				if (isPlayer_5c7600() && a2k_mode_cf462c == 11)
				{
					int amount = item.get_9b65b0()->integrity_9b6bf0();
					int num = a2k_player_cf45d8.addCapped_77eca0(amount);
					if (amount != num)
					{
						A2K_MSG(772,a2k_intToString_4051f0(amount - num));
						if (isPlayer_5c7600())
							a2k_gm_d25628.addItemAttachCount_778560(a2k_indexOfName_9d74d0(a2k_items_d2d1c4,"Protomatter"),amount - num,0);
					}
					if (num > 0)
						item.get_9b65b0()->setIntegrity_450460(num);
					else
						item.get_9b65b0()->remove_57dbe0(false,true,true,true);
				}
				break;
			case 15:
				if (isPlayer_5c7600() && a2k_known_cf4830[item.get_9b65b0()->itemId_457820()] && !item.get_9b65b0()->unknown457db0())
				{
					switch (item.get_9b65b0()->unknown457f90())
					{
						case 8:
							unknown5e29e0(item);
							break;
						case 9:
							unknown5e2840(item);
							break;
					}
				}
				break;
		}
		}
	}
}
