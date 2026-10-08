// alpha2_15: AI terminal hacking (0x5be7c0): an allied/operator AI hacks the machine it stands at and reports
//	the result (door control, DSF access, botnet links, squad recall, map/trap/access downloads, cave seals).
// NOTE: placeholder names / placeholder layout throughout; private aliases for mapped callees.
#include <string>
#include <vector>
#include "rng.h"
using std::string;
using std::vector;
extern RNG rng;

struct A2HEntity;
struct A2HProp;
struct A2HPoint
{
	int x;
	int y;
	A2HPoint(int v) throw();	// 0x409990
	A2HPoint(int x_, int y_) throw();	// 0x46ca20
	A2HPoint(const A2HPoint &other) throw();	// 0x46ca50
	void subtract_409a30(const A2HPoint &other) throw();
};
struct A2HRect
{
	int x, y, w, h;
	A2HRect() throw();	// 0x40b100
};
struct A2HHE	// HEntity
{
	int id;
	A2HHE() throw();	// 0x9b6590
	A2HEntity *get_9b6570() const throw();
};
struct A2HHP	// HProp
{
	int id;
	A2HHP() throw();	// 0x9b6590
	A2HProp *get_9b64f0() const throw();
	bool isNull_9b65d0() const throw();
	bool valid_9b7230() const throw();
};
struct A2HHI	// HItem
{
	int id;
	bool valid_9b7230() const throw();
};
struct A2HLoc
{
	int pad0;
	int type;	// +0x04
	bool inRange_46ecb0();
};
struct A2HHL
{
	int id;
	A2HLoc *get_9b7910() const throw();
};
struct A2HMarker
{
	char pad0[0x08];
	A2HPoint pos;	// +0x08
	char pad10[0x14 - 0x10];
	int type;	// +0x14
	void place_6c20b0(int a, const A2HPoint &p, int type_);
};
struct A2HHM	// HMarker
{
	int id;
	A2HMarker *get_9b7cd0() const throw();
};
struct A2HZone
{
	A2HPoint pos;	// +0x00
	A2HHL machine;	// +0x08
	char padc;
	bool found;	// +0x0d
	void label_6c16d0(string text);
	bool unknown6c1a10();
};
struct A2HSquad
{
	int type;
	bool unknown45e820();
};
struct A2HHackRec
{
	int id;
};
struct A2HRec
{
	char pad0[0x08];
	bool used;	// +0x08
};
struct A2HBag
{
	int draw_411520();
};
struct A2HTerm;
struct A2HPicker
{
	bool done;
	A2HPicker();	// 0x45b9e0
	int pick_65c1f0(A2HTerm *term, int mode);
};
struct A2HTerm
{
	A2HHP prop;	// +0x00
	char pad04[0x0c - 0x04];
	int active;	// +0x0c
	char pad10[0x14 - 0x10];
	A2HBag *bag;	// +0x14
	vector<A2HHackRec *> hacks;	// +0x18
	int attempts;	// +0x28
	int alert;	// +0x2c
	bool traced;	// +0x30
	int detection;	// +0x34
	char pad38[0x40 - 0x38];
	vector<int> list40;	// +0x40
	char pad50[0x60 - 0x50];
	vector<int> list60;	// +0x60
	char pad70[0x78 - 0x70];
	A2HPicker *picker;	// +0x78
	A2HRec *record_45c1c0(int hackId);
	void getValues_65cdc0(int *chance, int *detect);
};
struct A2HTrap
{
	int pad0;
	int array;	// +0x04
};
struct A2HProp
{
	A2HTerm *terminal_45cb30() throw();
	const string &getName_45c5b0();
	const string &location_45c590();
	int type_44ab40() throw();
	A2HTrap *trap_44b020() throw();
	const A2HPoint &pos_4184d0() throw();
	void unknown45ce10(bool a, int b, bool c, A2HHE e);
	int unknown65f170();
};
struct A2HEntity
{
	const string &getName_416f40() throw();
	int unknown5c7f40();
};
struct A2HCell
{
	A2HHP getProp_45d550();
	A2HHI getItem_45d8f0();
	bool unknown45dbb0();
	bool isEdge_45dc30() throw();
	bool isMachinePart_45dcd0() throw();
	void unknown66a050(int type, int a, int b);
	bool unknown66b360();
	void unknown670690();
	void unknown670b20();
};
struct A2HGrid
{
	int getWidth_9fcd80() throw();
	int getHeight_9b8f00() throw();
	A2HCell **at_9ceda0(int x, int y) throw();
	A2HCell **atPoint_9ced70(A2HPoint &p) throw();
	void getRect_9b4430(A2HPoint &p, int range, A2HRect &rect);
};
struct A2HText
{
	A2HText(A2HHE entity, int id, string text);	// 0x4617e0
	int data[0x24 / 4];
};
struct A2HDefList
{
	int data[4];
};
struct A2HMap
{
	int difficulty_71adc0(A2HHE entity, A2HHP machine, A2HRec *rec, int hackId, int a, int b, int c, A2HHE other, bool d);
	vector<int> &counts_463b30();
	void addText_4651e0(A2HText *text);
	void delayed_6c65a0(A2HHE entity, const string &name, int a);
	A2HZone *zoneOf_462fd0(A2HHP machine);
	void unknown4647a0(const A2HPoint &p, bool flag);
	void announceMachine_71dd30(A2HHL machine);
	bool findDrop_71ec60(A2HPoint &p, vector<A2HPoint> area);
	vector<A2HHP> &list_463c00(int index);
	vector<vector<A2HHP> > &lists_463be0();
	bool isVisible_4631c0(A2HPoint &p);
	void unknown4647d0(const A2HPoint &p);
	vector<A2HZone *> *exits_462e10();
	void unknown464ab0();
	void unknown464ad0();
	A2HZone *getZone_462e30(const A2HPoint &p);
	void unknown734d60(const A2HPoint &p);
	vector<vector<A2HHM> > &markers_463ec0();
	vector<vector<A2HPoint> > &spots_459070();
	void seal_74bb90(A2HHP machine, A2HHP *seal, A2HPoint *pos, bool *busy);
	void timer_6c6b90(A2HPoint &pos, const string &name, int a, int b);
	void unknown9e29b0(void *list, A2HHP prop);
	char pad0[0x720];
	char list720;	// +0x720
};
struct A2HFov
{
	void compute_40ca20(A2HPoint &origin, int range, void *cost, void *flags);
};
struct A2HFx8
{
	void init_503b20();
};
struct A2HFxB
{
	A2HFx8 *create_508610(A2HFxB *self, int sound, const A2HPoint &p, void *a, int b, int c, int d, int e, int f);
};
struct A2HFx
{
	void init_50de10();
};
struct A2HEffects
{
	A2HFx *create_50fb50(A2HEffects *engine, int id, const A2HPoint &pos, const A2HPoint *a, const A2HPoint *b, const A2HPoint *c, int layer);
};
struct A2HConsole
{
	void bubble_8758d0(bool flag);
};
struct A2HLog
{
	void scrollToEnd_7b4f10();
};
struct A2HOvermind
{
	void unknown682420(int a, int b);
	void recall_68cd80(A2HSquad *squad);
};
struct A2HMapView
{
	const A2HPoint &offset_458ef0() throw();
	bool inBounds_4173d0(const A2HPoint &p) throw();
	void label_813050(bool flag, A2HHP prop, int a, int b, int c);
	void labelAccess_80e3a0(bool flag, const A2HPoint &p);
};
struct A2HFactory
{
	A2HHM createC_793190();
};
struct A2HGameData
{
	string generateID_46f890();
	const string &getEntryText_46f6d0(const string &key);
};
struct A2HPlayerData
{
	bool event_77fbc0(int id);
};
struct A2HMission
{
	void unknown987de0();
};
struct A2HHackInfo
{
	bool a;
	bool b;
	bool c;
	char pad[3];
};

extern A2HMap *a2h_map_cefc4c;
extern A2HGrid a2h_grid_cfd44c;
extern A2HFov a2h_fov_cfe568;
extern A2HFxB *a2h_fxb_cefc50;
extern A2HEffects *a2h_effects_cefc64;
extern A2HConsole *a2h_console_cec058;
extern A2HLog *a2h_log_cec0b4;
extern A2HMapView *a2h_mapView_cec054;
extern A2HMission *a2h_mission_cec034;
extern A2HFactory *a2h_factory_cefaa8;
extern A2HOvermind a2h_overmind_cf6428;
extern vector<A2HSquad *> a2h_squads_cf6478;
extern vector<vector<A2HHP> > a2h_arrays_d20248;
extern vector<A2HPoint> a2h_visible_d15e58;
extern A2HGameData a2h_gameData_d1e860;
extern A2HHL a2h_world_d1e888;
extern A2HPlayerData a2h_player_cf45d8;
extern A2HDefList a2h_terrain_cfb844;
extern A2HPoint a2h_none_cfbec0;
extern A2HHackInfo a2h_hacks_b9b178[];
extern int a2h_hubBonus_b9b988[];
extern string a2h_hackNames_d2d508[];
extern string a2h_squadNames_d2f350[];
extern string a2h_locations_cfaca0[];
extern string a2h_markerNames_cf3fb0[];
extern char a2h_cost_cfd428[];
extern char a2h_cost_d297a8[];
extern char a2h_cost_d2f504[];
extern char a2h_doorFx_d2e20c[];
extern bool a2h_dsf_cf6458;
extern int a2h_mode_cf4718;
extern int a2h_hackCount_cf4d34;
extern bool a2h_flag_cf4d18;

bool a2h_show_5111e0(int id, const string &text, string *a, string *b, A2HHE entity, A2HHE other, int c, int d);
bool a2h_addUnique_9db000(vector<int> &list, int value);
void a2h_addUniqueEntity_9d30e0(vector<A2HHP> &list, A2HHP prop);
int a2h_randomRec_9d5d00(vector<int> &list);
string a2h_countString_407a80(int count, const string &noun);
string a2h_pointToString_40a4a0(const A2HPoint &p);
string a2h_intToString_4051f0(int value);
int a2h_stringToInt_405610(const string &text);
int a2h_maxInt_9cdb60(int a, int b);
void a2h_clamp_9d06d0(int *value, int low, int high);
bool a2h_lookup1_9d45a0(const string &name, int *id);
bool a2h_lookup2_9d7980(const string &name, int *id);
int a2h_indexOfName_9d7b80(A2HDefList &list, const string &name);
void a2h_eraseStep_9d6440(vector<A2HHM> &list, int &index);
void a2h_appendUnique_9d80a0(vector<A2HPoint> &list, vector<A2HPoint> &other);
void a2h_deleteObject_9d8f20(vector<A2HHackRec *> &list, int index);
char a2h_randomChar_4085b0(const string &chars);
void a2h_clearDijkstra_4faf40();
void a2h_sound_454260(const A2HPoint &p, int id);
bool a2h_collectProps_517ae0(int type, vector<A2HPoint> *out, bool a, int b, A2HPoint *c);

A2HPicker::A2HPicker()
{
}

#define A2H_MSG(ID,TEXT,ENTITY) do{if(a2h_show_5111e0(ID,TEXT,0,0,ENTITY,A2HHE(),0,0))a2h_console_cec058->bubble_8758d0(true);a2h_log_cec0b4->scrollToEnd_7b4f10();}while(false)

struct A2HAI
{
	void hack(int mode);

	A2HHE self;	// +0x00
	char pad04[0x6c - 0x04];
	vector<A2HPoint> points;	// +0x6c
};

void A2HAI::hack(int mode)
{
	A2HTerm *record = (*a2h_grid_cfd44c.atPoint_9ced70(points[0]))->getProp_45d550().get_9b64f0()->terminal_45cb30();
	A2HHP target = record->prop;
	if (record->picker == 0)
		record->picker = new A2HPicker();
	A2HPicker *base = record->picker;
	int idx = base->pick_65c1f0(record,mode);
	if (idx == 0x70)
	{
		base->done = true;
		points.clear();
		string message;
		switch (mode)
		{
			case 0:
				message = self.get_9b6570()->getName_416f40() + " unable to find more targets on " + target.get_9b64f0()->getName_45c5b0() + ".";
				break;
			case 1:
				message = self.get_9b6570()->getName_416f40() + " doesn't find the " + target.get_9b64f0()->getName_45c5b0() + " useful.";
				break;
		}
		A2H_MSG(0x286,message,self);
		return;
	}
	A2HRec *current = record->record_45c1c0(idx);
	int depth = a2h_map_cefc4c->difficulty_71adc0(self,target,current,idx,-1,0,0,A2HHE(),true);
	depth += 20;
	int pick = record->bag->draw_411520();
	if (depth <= 0 && pick <= depth)
		pick = depth + 1;
	string text = self.get_9b6570()->getName_416f40() + " attempts to hack " + target.get_9b64f0()->getName_45c5b0() + "...";
	A2H_MSG(0x286,text,self);
	bool ok = false;
	if (pick <= depth)
	{
		a2h_map_cefc4c->counts_463b30()[idx]++;
		a2h_addUnique_9db000(record->list60,idx);
		ok = true;
		if (mode == 0)
		{
			text = ">>" + a2h_hackNames_d2d508[idx];
			A2H_MSG(0x202,text,self);
		}
		else
		{
			text = self.get_9b6570()->getName_416f40() + ": \"I tried " + a2h_hackNames_d2d508[idx] + " on " + (*a2h_grid_cfd44c.atPoint_9ced70(points[0]))->getProp_45d550().get_9b64f0()->location_45c590() + ".\"";
			a2h_map_cefc4c->addText_4651e0(new A2HText(self,0x202,text));
			a2h_map_cefc4c->delayed_6c65a0(self,"Ai_Delayed_Dialogue",0);
		}
		vector<A2HPoint> targets;
		vector<A2HPoint> door;
		vector<A2HPoint> props;
		vector<A2HPoint> visible;
		bool changed = false;
		switch (idx)
		{
			case 5:
			{
				vector<A2HPoint> list;
				if (a2h_collectProps_517ae0(target.get_9b64f0()->type_44ab40(),&list,false,2,0))
				{
					string name = (*a2h_grid_cfd44c.atPoint_9ced70(list.front()))->getProp_45d550().get_9b64f0()->getName_45c5b0();
					text = name + " opened.";
					a2h_sound_454260(list.front(),0x7e);
					int label;
					if (a2h_lookup2_9d7980("P_Machine_Door_Open",&label))
					{
						for (int i = 0; i < list.size(); i++)
						{
							if (a2h_map_cefc4c->isVisible_4631c0(list[i]))
								a2h_fxb_cefc50->create_508610(a2h_fxb_cefc50,label,list[i],a2h_doorFx_d2e20c,0,0,0,9,0)->init_503b20();
							(*a2h_grid_cfd44c.atPoint_9ced70(list[i]))->getProp_45d550().get_9b64f0()->unknown45ce10(true,0,true,A2HHE());
						}
					}
				}
				break;
			}
			case 6:
				if (!a2h_dsf_cf6458)
					text = "All DSF locations in lockdown mode.";
				else
				{
					A2HZone *location = a2h_map_cefc4c->zoneOf_462fd0(target);
					A2HPoint loc(location->pos);
					int type = a2h_indexOfName_9d7b80(a2h_terrain_cfb844,"STAIRS_DSF_OPEN");
					(*a2h_grid_cfd44c.atPoint_9ced70(loc))->unknown66a050(type,2,1);
					a2h_map_cefc4c->announceMachine_71dd30(location->machine);
					a2h_map_cefc4c->unknown4647a0(loc,true);
					location->found = true;
					if ((*a2h_grid_cfd44c.atPoint_9ced70(loc))->getItem_45d8f0().valid_9b7230())
					{
						vector<A2HPoint> areas(1,loc);
						a2h_map_cefc4c->findDrop_71ec60(loc,areas);
					}
					targets.push_back(loc);
					text = "DSF access unlocked.";
					location->label_6c16d0("UNLOCKED");
					a2h_sound_454260(loc,0x82);
				}
				break;
			case 56:
			case 57:
			{
				int idx2 = idx - 0x37;
				record->list40.push_back(idx2);
				a2h_addUniqueEntity_9d30e0(a2h_map_cefc4c->list_463c00(idx2),target);
				text.clear();
				switch (idx)
				{
					case 0x38:
						text += "System interface override in place.";
						break;
					case 0x39:
						text += "Terminal linked with " + a2h_countString_407a80(a2h_map_cefc4c->lists_463be0()[2].size() - 1,"system") + ".\nAwaiting botnet instructions.";
						break;
				}
				break;
			}
			case 18:
				a2h_overmind_cf6428.unknown682420(0x27,0);
				text = "Purged threat record, alert level lowered.";
				ok = false;
				break;
			case 35:
			case 36:
			case 37:
			case 38:
			{
				int type = idx - 0x1f;
				vector<int> orders;
				for (int i = 0; i < a2h_squads_cf6478.size(); i++)
				{
					if (a2h_squads_cf6478[i]->type == type && !a2h_squads_cf6478[i]->unknown45e820())
						orders.push_back(i);
				}
				text = "Establishing remote squad link...";
				if (orders.empty())
					text += "\nNo tasked " + a2h_squadNames_d2f350[type] + " squads found.";
				else if (a2h_world_d1e888.get_9b7910()->type == 0x22)
					text += "\nUnable to override squad orders.";
				else
				{
					string table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ09123456789";
					string prefix;
					for (int i = 0; i < 10; i++)
						prefix += a2h_randomChar_4085b0(table);
					text += "\nRecalled " + a2h_squadNames_d2f350[type] + " squad " + prefix + ".";
					a2h_overmind_cf6428.recall_68cd80(a2h_squads_cf6478[a2h_randomRec_9d5d00(orders)]);
					ok = false;
				}
				break;
			}
			case 42:
			{
				A2HPoint origin(target.get_9b64f0()->pos_4184d0());
				a2h_clearDijkstra_4faf40();
				A2HRect range;
				a2h_grid_cfd44c.getRect_9b4430(origin,15,range);
				a2h_fov_cfe568.compute_40ca20(origin,99999,a2h_cost_d2f504,&range);
				visible = a2h_visible_d15e58;
				for (int i = 0; i < visible.size(); i++)
				{
					a2h_map_cefc4c->unknown4647a0(visible[i],true);
					if ((*a2h_grid_cfd44c.atPoint_9ced70(visible[i]))->isMachinePart_45dcd0())
					{
						A2HZone *zone = a2h_map_cefc4c->getZone_462e30(visible[i]);
						if (a2h_mode_cf4718 == 2)
							a2h_map_cefc4c->announceMachine_71dd30(zone->machine);
						zone->found = true;
						zone->label_6c16d0("FOUND");
						targets.push_back(visible[i]);
					}
				}
				text = "Retrieving Zone " + a2h_gameData_d1e860.generateID_46f890() + " layout...";
				text += "\nDownloaded map data.";
				break;
			}
			case 19:
			{
				A2HPoint origin(target.get_9b64f0()->pos_4184d0());
				a2h_clearDijkstra_4faf40();
				int flags = 1;
				a2h_fov_cfe568.compute_40ca20(origin,24,a2h_cost_cfd428,&flags);
				vector<A2HPoint> &vis = a2h_visible_d15e58;
				if (vis.empty())
					text = "No traps found in local area.";
				else
				{
					vector<int> arrays;
					for (int i = 0; i < vis.size(); i++)
						a2h_addUnique_9db000(arrays,(*a2h_grid_cfd44c.atPoint_9ced70(vis[i]))->getProp_45d550().get_9b64f0()->trap_44b020()->array);
					vis.clear();
					for (int i = 0; i < arrays.size(); i++)
					{
						for (int j = 0; j < a2h_arrays_d20248[arrays[i]].size(); j++)
							vis.push_back(a2h_arrays_d20248[arrays[i]][j].get_9b64f0()->pos_4184d0());
					}
					if (idx == 0x13)
					{
						text = "Found " + a2h_countString_407a80(vis.size(),"trap") + " in " + a2h_countString_407a80(arrays.size(),"array") + ":";
						for (int i = 0; i < arrays.size(); i++)
						{
							text += "\n  " + a2h_intToString_4051f0(a2h_arrays_d20248[arrays[i]].size()) + "x " + a2h_arrays_d20248[arrays[i]].front().get_9b64f0()->getName_45c5b0();
							for (int j = 0; j < a2h_arrays_d20248[arrays[i]].size(); j++)
							{
								a2h_arrays_d20248[arrays[i]][j].get_9b64f0()->unknown65f170();
								a2h_map_cefc4c->unknown4647d0(a2h_arrays_d20248[arrays[i]][j].get_9b64f0()->pos_4184d0());
							}
						}
						a2h_appendUnique_9d80a0(props,vis);
						for (int i = 0; i < vis.size(); i++)
							a2h_map_cefc4c->unknown9e29b0(&a2h_map_cefc4c->list720,(*a2h_grid_cfd44c.atPoint_9ced70(vis[i]))->getProp_45d550());
						text += "\nMap updated.";
					}
				}
				break;
			}
			case 7:
			{
				int count = 0;
				vector<A2HZone *> &vec = *a2h_map_cefc4c->exits_462e10();
				int dest;
				for (int i = 0; i < vec.size(); i++)
				{
					if (vec[i]->machine.get_9b7910()->inRange_46ecb0())
					{
						dest = vec[i]->machine.get_9b7910()->type;
						count++;
					}
				}
				if (count == 0)
				{
					text = "No level access points found.";
					a2h_map_cefc4c->unknown464ab0();
				}
				else
				{
					text = "Found " + a2h_countString_407a80(count,"level access point") + " to " + a2h_locations_cfaca0[dest] + ":";
					for (int i = 0; i < vec.size(); i++)
					{
						if (vec[i]->machine.get_9b7910()->inRange_46ecb0())
						{
							text += "\n  " + a2h_pointToString_40a4a0(vec[i]->pos);
							a2h_map_cefc4c->announceMachine_71dd30(vec[i]->machine);
							a2h_map_cefc4c->unknown4647a0(vec[i]->pos,true);
							vec[i]->found = true;
							targets.push_back(vec[i]->pos);
						}
					}
					text += "\nMap updated.";
				}
				break;
			}
			case 8:
			{
				int count = 0;
				vector<A2HZone *> &vec = *a2h_map_cefc4c->exits_462e10();
				for (int i = 0; i < vec.size(); i++)
				{
					if (vec[i]->unknown6c1a10())
						count++;
				}
				if (count == 0)
				{
					text = "No branch access points found.";
					a2h_map_cefc4c->unknown464ad0();
				}
				else
				{
					text = "Found " + a2h_countString_407a80(count,"branch access point") + ":";
					for (int i = 0; i < vec.size(); i++)
					{
						if (vec[i]->unknown6c1a10())
						{
							text += "\n  " + a2h_pointToString_40a4a0(vec[i]->pos) + " " + a2h_locations_cfaca0[vec[i]->machine.get_9b7910()->type];
							a2h_map_cefc4c->announceMachine_71dd30(vec[i]->machine);
							a2h_map_cefc4c->unknown4647a0(vec[i]->pos,true);
							vec[i]->found = true;
							targets.push_back(vec[i]->pos);
						}
					}
					text += "\nMap updated.";
				}
				break;
			}
			case 9:
			{
				bool flag = a2h_world_d1e888.get_9b7910()->type == 0xd;
				vector<A2HPoint> doors;
				if (flag)
				{
					for (int x = 0; x < a2h_grid_cfd44c.getWidth_9fcd80(); x++)
					{
						for (int y = 0; y < a2h_grid_cfd44c.getHeight_9b8f00(); y++)
						{
							if ((*a2h_grid_cfd44c.at_9ceda0(x,y))->isEdge_45dc30())
								doors.push_back(A2HPoint(x,y));
						}
					}
				}
				else
				{
					A2HPoint origin(target.get_9b64f0()->pos_4184d0());
					a2h_clearDijkstra_4faf40();
					int flags = 1;
					a2h_fov_cfe568.compute_40ca20(origin,24,a2h_cost_d297a8,&flags);
					doors = a2h_visible_d15e58;
				}
				if (doors.empty())
					text = flag ? "No phase walls or emergency access doors found in local area." : "No emergency access doors found in local area.";
				else
				{
					text = flag ? "Found " + a2h_countString_407a80(doors.size(),"emergency access point") + "." : "Found " + a2h_countString_407a80(doors.size(),"emergency access door") + ":";
					for (int i = 0; i < doors.size(); i++)
					{
						if (!flag)
							text += "\n  " + a2h_pointToString_40a4a0(doors[i]);
						a2h_map_cefc4c->unknown734d60(doors[i]);
						bool opened = false;
						if ((*a2h_grid_cfd44c.atPoint_9ced70(doors[i]))->unknown45dbb0())
						{
							(*a2h_grid_cfd44c.atPoint_9ced70(doors[i]))->unknown670690();
							opened = true;
						}
						a2h_map_cefc4c->unknown4647a0(doors[i],true);
						if (opened)
							(*a2h_grid_cfd44c.atPoint_9ced70(doors[i]))->unknown670b20();
					}
					door = doors;
					text += "\nMap updated.";
				}
				break;
			}
			case 11:
			case 16:
			{
				int type = idx - 0xb;
				vector<A2HHM> &list = a2h_map_cefc4c->markers_463ec0()[0];
				for (int i = 0; i < list.size(); i++)
				{
					if (list[i].get_9b7cd0()->type == type)
					{
						if ((*a2h_grid_cfd44c.atPoint_9ced70(list[i].get_9b7cd0()->pos))->unknown66b360())
							continue;
						a2h_eraseStep_9d6440(list,i);
					}
				}
				vector<A2HPoint> &positions = a2h_map_cefc4c->spots_459070()[type];
				int added = 0;
				for (int i = 0; i < positions.size(); i++)
				{
					if ((*a2h_grid_cfd44c.atPoint_9ced70(positions[i]))->unknown66b360())
						continue;
					added++;
					list.push_back(a2h_factory_cefaa8->createC_793190());
					list.back().get_9b7cd0()->place_6c20b0(0,positions[i],type);
				}
				if (added)
				{
					text = "Found " + a2h_countString_407a80(added,a2h_markerNames_cf3fb0[type]) + ".";
					text += "\nDownloaded coordinate data.";
					changed = true;
				}
				else
					text = "No " + a2h_markerNames_cf3fb0[type] + (a2h_markerNames_cf3fb0[type][a2h_markerNames_cf3fb0[type].size() - 1] == 's' ? "es" : "s") + " found.";
				break;
			}
			case 49:
			{
				A2HHP door;
				A2HPoint location(-1);
				bool done = false;
				a2h_map_cefc4c->seal_74bb90(target,&door,&location,&done);
				text = "Accessing seal controls...";
				if (done)
					text += "\nError: Seal state transition in progress.";
				else if (door.isNull_9b65d0() || location.x == -1)
					text += "\nError: Unable to establish connection.";
				else
				{
					text += "\nDisengaging subsurface cave network seal C" + a2h_intToString_4051f0(rng.rangeInt(100.0f,999.0f)) + ".";
					text += "\nWarning: Hostile activity detected below.";
					a2h_map_cefc4c->timer_6c6b90(location,"COM_Cave_Seal_Timer",0,-1);
				}
				break;
			}
		}
		if (!text.empty())
		{
			if (mode == 0)
				A2H_MSG(0x203,text,A2HHE());
			else
			{
				a2h_map_cefc4c->addText_4651e0(new A2HText(self,0x203,text));
				a2h_map_cefc4c->delayed_6c65a0(self,"Ai_Delayed_Dialogue",0);
			}
		}
		if (!targets.empty())
		{
			for (int i = 0; i < targets.size(); i++)
				a2h_mapView_cec054->labelAccess_80e3a0(true,targets[i]);
		}
		if (!door.empty())
		{
			for (int i = 0; i < door.size(); i++)
				a2h_mapView_cec054->labelAccess_80e3a0(true,door[i]);
		}
		if (!props.empty())
		{
			for (int i = 0; i < props.size(); i++)
			{
				if ((*a2h_grid_cfd44c.atPoint_9ced70(props[i]))->getProp_45d550().valid_9b7230())
				{
					a2h_mapView_cec054->label_813050(true,(*a2h_grid_cfd44c.atPoint_9ced70(props[i]))->getProp_45d550(),0,0,0);
					a2h_map_cefc4c->unknown9e29b0(&a2h_map_cefc4c->list720,(*a2h_grid_cfd44c.atPoint_9ced70(props[i]))->getProp_45d550());
				}
			}
		}
		if (changed)
			a2h_mission_cec034->unknown987de0();
		if (!visible.empty())
		{
			int key = 0;
			a2h_lookup1_9d45a0("CMap_Layout_Reveal_Hack",&key);
			if (key)
			{
				A2HPoint offset(a2h_mapView_cec054->offset_458ef0());
				for (int i = 0; i < visible.size(); i++)
				{
					visible[i].subtract_409a30(offset);
					if (a2h_mapView_cec054->inBounds_4173d0(visible[i]))
						a2h_effects_cefc64->create_50fb50(a2h_effects_cefc64,key,visible[i],&a2h_none_cfbec0,0,0,9)->init_50de10();
				}
			}
		}
		if (mode == 0)
		{
			a2h_hackCount_cf4d34++;
			if (a2h_hackCount_cf4d34 == 10)
				a2h_player_cf45d8.event_77fbc0(0xb7);
		}
		a2h_flag_cf4d18 = false;
	}
	if (ok && current)
	{
		if (a2h_hacks_b9b178[idx].c)
		{
			vector<A2HPoint> &list = a2h_map_cefc4c->spots_459070()[0];
			for (int i = 0; i < list.size(); i++)
			{
				for (int j = 0; j < record->hacks.size(); j++)
				{
					if (idx == record->hacks[j]->id)
					{
						a2h_deleteObject_9d8f20(record->hacks,j);
						break;
					}
				}
			}
		}
		else if (a2h_hacks_b9b178[idx].b)
		{
			for (int j = 0; j < record->hacks.size(); j++)
			{
				if (idx == record->hacks[j]->id)
				{
					a2h_deleteObject_9d8f20(record->hacks,j);
					break;
				}
			}
		}
		else if (a2h_hacks_b9b178[idx].a)
			current->used = true;
	}
	if (record->attempts == 0)
		record->attempts = 1;
	if (record->active == 0)
		return;
	int limit;
	int amount;
	record->getValues_65cdc0(&limit,&amount);
	if (limit != -1)
	{
		if (pick > depth)
		{
			int penalty = a2h_maxInt_9cdb60(0,pick - depth - (self.get_9b6570()->unknown5c7f40() + a2h_hubBonus_b9b988[a2h_stringToInt_405610(a2h_gameData_d1e860.getEntryText_46f6d0("hubNetworkHubDisabled_g"))])) / 2;
			a2h_clamp_9d06d0(&limit,penalty,100);
			record->alert += penalty;
		}
		if (!rng.chance(limit))
			return;
		limit = -1;
		if (pick <= depth)
			amount = 0;
		else
			amount = pick - depth;
	}
	else
	{
		if (pick <= depth)
			amount += a2h_maxInt_9cdb60(15,50 - (self.get_9b6570()->unknown5c7f40() + a2h_hubBonus_b9b988[a2h_stringToInt_405610(a2h_gameData_d1e860.getEntryText_46f6d0("hubNetworkHubDisabled_g"))]));
		else
			amount += a2h_maxInt_9cdb60(25,50 - (self.get_9b6570()->unknown5c7f40() + a2h_hubBonus_b9b988[a2h_stringToInt_405610(a2h_gameData_d1e860.getEntryText_46f6d0("hubNetworkHubDisabled_g"))]) + (pick - depth) / 3);
		if (amount > 90)
			amount = 90;
	}
	record->traced = limit == -1;
	record->detection = amount;
	if (amount > 15)
	{
		if (mode == 0)
		{
			text = self.get_9b6570()->getName_416f40() + " reports that hacking " + target.get_9b64f0()->getName_45c5b0() + " no longer safe.";
			A2H_MSG(0x286,text,self);
		}
		else
		{
			text = self.get_9b6570()->getName_416f40() + " reports that hacking " + (*a2h_grid_cfd44c.atPoint_9ced70(points[0]))->getProp_45d550().get_9b64f0()->location_45c590() + " no longer safe.";
			a2h_map_cefc4c->addText_4651e0(new A2HText(self,0x203,text));
			a2h_map_cefc4c->delayed_6c65a0(self,"Ai_Delayed_Dialogue",0);
		}
	}
}
