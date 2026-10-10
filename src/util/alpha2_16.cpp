// alpha2_16: event trigger evaluation (0x518c00): for each registered trigger of the given event type, walks its
//	condition chain (with jump indices) against the event's actors/prop/item/position and collects the matches.
// NOTE: placeholder names / placeholder layout throughout; private aliases for mapped callees.
#include <string>
#include <vector>
#include "rng.h"
using std::string;
using std::vector;
extern RNG rng;

struct A2QEntity;
struct A2QProp;
struct A2QItem;
struct A2QPoint
{
	int x;
	int y;
	A2QPoint(const A2QPoint &other) throw();	// 0x46ca50
};
struct A2QHE	// HEntity
{
	int id;
	A2QHE() throw();	// 0x9b6590
	A2QEntity *get_9b6570() const throw();
	bool isValid_9b7230() const throw();
};
struct A2QHP	// HProp
{
	int id;
	A2QProp *get_9b64f0() const throw();
	bool isValid_9b7230() const throw();
};
struct A2QHI	// HItem
{
	int id;
	A2QItem *get_9b65b0() const throw();
	bool isValid_9b7230() const throw();
};
struct A2QGroup
{
	vector<A2QHE> &members_416f40() throw();
	int count_44afb0() throw();
	int type_9b4350() throw();
	int id_9b8f00() throw();
};
struct A2QHG	// group handle
{
	int id;
	A2QGroup *get_9b7250() const throw();
};
struct A2QLoc
{
	int pad0;
	int type;	// +0x04
	int depth;	// +0x08
};
struct A2QHL
{
	int id;
	A2QLoc *get_9b7910() const throw();
};
struct A2QAI
{
	A2QHE *getEntity_459570(A2QHE entity);
	int unknown458f30() throw();
	int id_9b8f00() throw();
};
struct A2QEntityDef
{
	char pad0[0x24];
	int x24;	// +0x24
	int x28;	// +0x28
	char pad2c[0x9c - 0x2c];
	int x9c;	// +0x9c
	char pada0[0x1ac - 0xa0];
	string name1ac;	// +0x1ac
};
struct A2QEntity
{
	const string &getName_45a280();
	const string &getName_416f40() throw();
	A2QEntityDef *def_9b4350() throw();
	A2QPoint &getPosition_45a4a0() throw();
	A2QPoint pos_45a4c0();
	int getTarget_45a760() throw();
	A2QHG getGroup_45a3f0();
	vector<A2QHI> *getInventoryList_45ab00() throw();
	A2QAI *ai_45b590() throw();
	void *unknown45ac40(int effect);
	int unknown45acb0(int a);
	int unknown45adb0(int a);
	int unknown45a920() throw();
	int unknown45a940() throw();
	int unknown45a8d0() throw();
	int unknown45a8f0() throw();
	int unknown45a880() throw();
	int getField_490840() throw();
	int unknown5c7fa0();
	int unknown5c8cb0();
	bool unknown5c9b10();
	int unknown5ca260();
	int unknown5ca400();
	int unknown5ca670();
	int unknown5cab90();
	bool unknown5cb680(A2QHG group);
	int unknown5cbb10();
	bool unknown5cbdf0(int a, bool b, bool c);
};
struct A2QInfo
{
	int pad0;
	string name;	// +0x04
};
struct A2QPropDef
{
	char pad0[0x60];
	A2QInfo *info;	// +0x60
};
struct A2QProp
{
	A2QPoint &pos_4184d0() throw();
	const string &location_45c590();
	const string &getName_45c5b0();
	int getNestedField_45c630() throw();
	int unknown45c870(int a);
	int unknown45ca00(int a);
	A2QPropDef *def_9b8f00() throw();
};
struct A2QHE2;
struct A2QItem
{
	int getType_44aec0() throw();
	int getNestedField_457820() throw();
	const string &name_457860();
	const string &name_457970();
	A2QHE unknown457b50();
	int getEffectValue_457be0(int effect) throw();
	int unknown457c50(int effect) throw();
	int unknown457ca0() throw();
	bool unknown457d70() throw();
	A2QPoint &pos_575920();
	int trap_9b6bf0() throw();
};
struct A2QCellDef
{
	char pad0[0x50];
	A2QInfo *info;	// +0x50
};
struct A2QCell
{
	bool getField_4550b0() throw();
	const string &unknown45d100();
	const string &unknown45d120();
	A2QHE getEntity_45d250();
	int getEffectValue_45d3c0(int effect);
	A2QHP getProp_45d550();
	A2QHI getItem_45d8f0();
	bool isPassableFor_66ab30(A2QHE entity);
	int getArmor_66ae70();
	A2QCellDef *def_9fcd80() throw();
};
struct A2QGrid
{
	A2QCell **atPoint_9ced70(A2QPoint &p) throw();
};
struct A2QMap
{
	A2QHE getPlayer_4630f0();
	bool isVisible_4631c0(A2QPoint &p);
	bool unknown4631f0(A2QHE entity);
	bool unknown4633c0(A2QPoint &p);
	bool unknown463400(A2QHE entity);
	int unknown463710();
	A2QHG group_463890(int index);
	void *unknown4638e0(int id, int faction);
	vector<A2QHG> *groups_463950();
	int getTurn_464270() throw();
	int unknown4642d0() throw();
	bool unknown465200(A2QPoint &a, A2QPoint &b);
	bool isReachable_465230(int range, A2QPoint &a, A2QPoint &b);
	int unknown715b10();
};
struct A2QOvermind
{
	int countParties(int a);
};
struct A2QGameData
{
	const string &getEntryText_46f6d0(const string &key);
};
struct A2QCond	// OpV1_Condition
{
	int type;	// +0x00
	string key;	// +0x04
	int op;	// +0x20
	string operand;	// +0x24
	bool compareInt(int value);	// 0x455e00
	bool compareString(const string &value);	// 0x455f40
};
struct A2QDef
{
	char pad0[0x3c];
	int type;	// +0x3c
	vector<A2QCond> conds;	// +0x40
	vector<int> jumps;	// +0x50
};
struct A2QRec
{
	A2QDef *def;	// +0x00
	int x04;	// +0x04
	int x08;	// +0x08
	int x0c;	// +0x0c
	int x10;	// +0x10
	void unknown5189b0(A2QHE entity);
};
struct A2QMatch
{
	A2QMatch(A2QDef *def, A2QHE entity, int a, A2QHE other);	// 0x456940
	int data[4];
};
struct A2QActorFlag
{
	bool b;
	char pad[3];
};

A2QMatch::A2QMatch(A2QDef *def, A2QHE entity, int a, A2QHE other)
{
}

extern A2QMap *a2q_map_cefc4c;
extern A2QGrid a2q_grid_cfd44c;
extern A2QOvermind a2q_overmind_cf6428;
extern A2QGameData a2q_gameData_d1e860;
extern A2QHL a2q_world_d1e888;
extern bool a2q_needsEntity_ba60b0[];
extern A2QActorFlag a2q_actor_ba6118[];
extern string a2q_locations_cfe140[];
extern int a2q_mapTypes_b90000[];
extern string a2q_mapNames_d312f0[];
extern string a2q_global_d25664;
extern string a2q_global_d1f3b8;
extern string a2q_global_d1f3d4;
extern int a2q_global_d1f3f0;
extern string a2q_global_d1f3f4;
extern int a2q_global_cf47fc;
extern string a2q_names_cfd458[];
extern string a2q_names_d2f798[];
extern bool a2q_targets_caf1f8[];
extern string a2q_groups_d01860[];
extern string a2q_ais_d31db8[];

int a2q_stringToInt_405610(const string &text);
int a2q_distanceCeil_40a3f0(A2QPoint &a, A2QPoint &b);

#define ACT (a2q_actor_ba6118[type].b ? a : e)
#define CELLPROP(E) (*a2q_grid_cfd44c.atPoint_9ced70(E.get_9b6570()->getPosition_45a4a0()))->getProp_45d550()
#define POS (d ? *d : b.isValid_9b7230() ? b.get_9b64f0()->pos_4184d0() : a.isValid_9b7230() ? a.get_9b6570()->getPosition_45a4a0() : e.isValid_9b7230() ? e.get_9b6570()->getPosition_45a4a0() : c.get_9b65b0()->pos_575920())

struct A2QTracker
{
	vector<A2QMatch *> *evaluate(int type, A2QHE e, A2QHE a, A2QHP b, A2QHI c, A2QPoint *d, vector<A2QMatch *> *f, int g, vector<A2QRec *> *h, vector<int> *results);

	vector<A2QRec *> recs;	// +0x00
	int lastTurn;	// +0x10
};

vector<A2QMatch *> *A2QTracker::evaluate(int type, A2QHE e, A2QHE a, A2QHP b, A2QHI c, A2QPoint *d, vector<A2QMatch *> *f, int g, vector<A2QRec *> *h, vector<int> *results)
{
	if (a2q_needsEntity_ba60b0[type] && !e.get_9b6570())
		return f;
	for (int r = 0; r < recs.size(); r++)
	{
		if (recs[r]->def->type == type)
		{
		bool failed = false;
		if (!recs[r]->def->conds.empty())
		{
			vector<A2QCond> &conds = recs[r]->def->conds;
			for (int i = 0; i < conds.size(); i++)
			{
				switch (conds[i].type)
				{
					case 0:
						if (conds[i].compareInt(rng.rangeInt(1,100))) goto pass;
						break;
					case 1:
						if (conds[i].compareString(a2q_gameData_d1e860.getEntryText_46f6d0(conds[i].key))) goto pass;
						break;
					case 2:
						if (conds[i].compareInt(a2q_map_cefc4c->getTurn_464270())) goto pass;
						break;
					case 3:
						if (conds[i].compareInt(a2q_map_cefc4c->unknown4642d0())) goto pass;
						break;
					case 4:
						if (conds[i].compareString(a2q_locations_cfe140[a2q_world_d1e888.get_9b7910()->type])) goto pass;
						break;
					case 5:
						if (conds[i].compareString(a2q_mapNames_d312f0[a2q_mapTypes_b90000[a2q_world_d1e888.get_9b7910()->type]])) goto pass;
						break;
					case 6:
						if (conds[i].compareInt(a2q_world_d1e888.get_9b7910()->depth)) goto pass;
						break;
					case 7:
					{
						bool flag = false;
						if (ACT.isValid_9b7230())
							flag = a2q_stringToInt_405610(conds[i].key) <= 1 ? a2q_map_cefc4c->unknown463400(ACT) && (a2q_stringToInt_405610(conds[i].key) == 0 || ACT.get_9b6570()->ai_45b590()->getEntity_459570(a2q_map_cefc4c->getPlayer_4630f0())) : a2q_map_cefc4c->unknown4631f0(ACT);
						else if (b.isValid_9b7230())
							flag = a2q_stringToInt_405610(conds[i].key) <= 1 ? a2q_map_cefc4c->unknown4633c0(b.get_9b64f0()->pos_4184d0()) : a2q_map_cefc4c->isVisible_4631c0(b.get_9b64f0()->pos_4184d0());
						else if (c.isValid_9b7230())
							flag = a2q_stringToInt_405610(conds[i].key) <= 1 ? a2q_map_cefc4c->unknown4633c0(c.get_9b65b0()->pos_575920()) : a2q_map_cefc4c->isVisible_4631c0(c.get_9b65b0()->pos_575920());
						else if (d)
							flag = a2q_stringToInt_405610(conds[i].key) <= 1 ? a2q_map_cefc4c->unknown4633c0(*d) : a2q_map_cefc4c->isVisible_4631c0(*d);
						if (conds[i].compareInt(flag != 0)) goto pass;
						break;
					}
					case 8:
					{
						bool found = false;
						int data = a2q_stringToInt_405610(conds[i].key);
						int group = data / 50000;
						int range = data % 50000 / 1000;
						int event = data % 1000;
						A2QPoint v(ACT.isValid_9b7230() ? ACT.get_9b6570()->getPosition_45a4a0() : b.isValid_9b7230() ? b.get_9b64f0()->pos_4184d0() : c.isValid_9b7230() ? c.get_9b65b0()->pos_575920() : *d);
						vector<A2QHE> &members = a2q_map_cefc4c->group_463890(group).get_9b7250()->members_416f40();
						for (int j = 0; j < members.size(); j++)
						{
							if (members[j].get_9b6570()->unknown45ac40(event) && a2q_distanceCeil_40a3f0(v,members[j].get_9b6570()->getPosition_45a4a0()) <= range && a2q_map_cefc4c->isReachable_465230(range,v,members[j].get_9b6570()->getPosition_45a4a0()))
							{
								found = true;
								break;
							}
						}
						if (conds[i].compareInt(found != 0)) goto pass;
						break;
					}
					case 9:
						if (conds[i].compareInt(a2q_overmind_cf6428.countParties(a2q_stringToInt_405610(conds[i].key)))) goto pass;
						break;
					case 10:
						if (conds[i].compareInt(a2q_map_cefc4c->unknown715b10())) goto pass;
						break;
					case 11:
						if (conds[i].compareInt(a2q_map_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5cbdf0(a2q_stringToInt_405610(conds[i].key),false,false) != 0)) goto pass;
						break;
					case 12:
						if (conds[i].compareInt(a2q_map_cefc4c->getPlayer_4630f0().get_9b6570()->unknown5cbdf0(a2q_stringToInt_405610(conds[i].key),true,true) != 0)) goto pass;
						break;
					case 13:
						if (conds[i].compareInt(a2q_map_cefc4c->group_463890(a2q_stringToInt_405610(conds[i].key)).get_9b7250()->count_44afb0())) goto pass;
						break;
					case 14:
						if (conds[i].compareInt(a2q_map_cefc4c->unknown463710())) goto pass;
						break;
					case 15:
						if (conds[i].compareInt((a2q_global_d25664 == conds[i].key) != 0)) goto pass;
						break;
					case 16:
						if (conds[i].compareInt(recs[r]->x0c)) goto pass;
						break;
					case 17:
						if (conds[i].compareInt(a2q_map_cefc4c->getTurn_464270() - recs[r]->x04)) goto pass;
						break;
					case 18:
						if (conds[i].compareInt(a2q_global_cf47fc - recs[r]->x08)) goto pass;
						break;
					case 19:
						if (conds[i].compareInt(a2q_map_cefc4c->getTurn_464270() - lastTurn)) goto pass;
						break;
					case 20:
						if (conds[i].compareInt(a2q_map_cefc4c->getTurn_464270() - recs[r]->x10)) goto pass;
						break;
					case 21:
						if (conds[i].compareString(a2q_global_d1f3b8)) goto pass;
						break;
					case 22:
						if (conds[i].compareString(a2q_global_d1f3d4)) goto pass;
						break;
					case 23:
						if (conds[i].compareInt(a2q_global_d1f3f0)) goto pass;
						break;
					case 24:
						if (conds[i].compareString(a2q_global_d1f3f4)) goto pass;
						break;
					case 25:
						if (conds[i].compareString(ACT.get_9b6570()->getName_45a280())) goto pass;
						break;
					case 26:
						if (conds[i].compareString(ACT.get_9b6570()->def_9b4350()->name1ac)) goto pass;
						break;
					case 27:
						if (conds[i].compareString(ACT.get_9b6570()->getName_416f40())) goto pass;
						break;
					case 28:
						if (conds[i].compareString(a2q_names_cfd458[ACT.get_9b6570()->def_9b4350()->x24])) goto pass;
						break;
					case 29:
						if (conds[i].compareString(a2q_names_d2f798[ACT.get_9b6570()->def_9b4350()->x28])) goto pass;
						break;
					case 30:
						if (conds[i].compareInt(ACT.get_9b6570()->def_9b4350()->x9c)) goto pass;
						break;
					case 31:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown5c8cb0())) goto pass;
						break;
					case 32:
						if (conds[i].compareInt(ACT.get_9b6570()->getTarget_45a760() == 0)) goto pass;
						break;
					case 33:
						if (conds[i].compareInt(a2q_targets_caf1f8[ACT.get_9b6570()->getTarget_45a760()])) goto pass;
						break;
					case 34:
						if (conds[i].compareString(a2q_groups_d01860[ACT.get_9b6570()->getGroup_45a3f0().get_9b7250()->type_9b4350()])) goto pass;
						break;
					case 35:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown5c7fa0())) goto pass;
						break;
					case 36:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown5cb680(a2q_map_cefc4c->group_463890(a2q_stringToInt_405610(conds[i].key))))) goto pass;
						break;
					case 37:
					{
						A2QAI *ai = ACT.get_9b6570()->ai_45b590();
						if (ai && conds[i].compareInt(ai->unknown458f30())) goto pass;
						break;
					}
					case 38:
					{
						A2QAI *ai = ACT.get_9b6570()->ai_45b590();
						if (ai && conds[i].compareString(a2q_ais_d31db8[ai->id_9b8f00()])) goto pass;
						break;
					}
					case 39:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown5c9b10())) goto pass;
						break;
					case 40:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown5cbb10())) goto pass;
						break;
					case 41:
					case 42:
					{
						vector<A2QHI> &list = *ACT.get_9b6570()->getInventoryList_45ab00();
						for (int j = 0; j < list.size(); j++)
						{
							if (list[j].get_9b65b0()->getType_44aec0() <= 3 && list[j].get_9b65b0()->unknown457d70() && conds[i].compareString(list[j].get_9b65b0()->name_457970())) goto pass;
						}
						break;
					}
					case 43:
					{
						vector<A2QHI> &list = *ACT.get_9b6570()->getInventoryList_45ab00();
						for (int j = 0; j < list.size(); j++)
						{
							if (conds[i].compareString(list[j].get_9b65b0()->name_457970())) goto pass;
						}
						break;
					}
					case 44:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown45a920())) goto pass;
						break;
					case 45:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown5ca670())) goto pass;
						break;
					case 46:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown45a940())) goto pass;
						break;
					case 47:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown45a8d0())) goto pass;
						break;
					case 48:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown5ca400())) goto pass;
						break;
					case 49:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown45a8f0())) goto pass;
						break;
					case 50:
						if (conds[i].compareInt(ACT.get_9b6570()->getField_490840())) goto pass;
						break;
					case 51:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown5ca260())) goto pass;
						break;
					case 52:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown45a880())) goto pass;
						break;
					case 53:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown5ca260() - ACT.get_9b6570()->getField_490840())) goto pass;
						break;
					case 54:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown5cab90())) goto pass;
						break;
					case 55:
					{
						vector<A2QHI> &list = *ACT.get_9b6570()->getInventoryList_45ab00();
						int val = a2q_stringToInt_405610(conds[i].key);
						for (int j = 0; j < list.size(); j++)
						{
							if (list[j].get_9b65b0()->getType_44aec0() <= 3 && list[j].get_9b65b0()->getNestedField_457820() == val && conds[i].compareInt(list[j].get_9b65b0()->unknown457ca0())) goto pass;
						}
						break;
					}
					case 56:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown45acb0(a2q_stringToInt_405610(conds[i].key)))) goto pass;
						break;
					case 57:
						if (conds[i].compareInt(ACT.get_9b6570()->unknown45adb0(a2q_stringToInt_405610(conds[i].key)))) goto pass;
						break;
					case 58:
					{
						vector<A2QHE> &list = a2q_map_cefc4c->group_463890(a2q_stringToInt_405610(conds[i].key)).get_9b7250()->members_416f40();
						int best = 9999;
						int dist;
						for (int j = 0; j < list.size(); j++)
						{
							if (!list[j].get_9b6570()->getTarget_45a760())
							{
								dist = a2q_distanceCeil_40a3f0(ACT.get_9b6570()->pos_45a4c0(),list[j].get_9b6570()->pos_45a4c0());
								if (dist < best)
									best = dist;
							}
						}
						if (conds[i].compareInt(best)) goto pass;
						break;
					}
					case 59:
					{
						int mode = a2q_stringToInt_405610(conds[i].key);
						if (mode == 0 || mode == 1 && a2q_map_cefc4c->isVisible_4631c0(ACT.get_9b6570()->getPosition_45a4a0()) || mode == 2 && !a2q_map_cefc4c->isVisible_4631c0(ACT.get_9b6570()->getPosition_45a4a0()))
						{
							if (conds[i].compareInt(a2q_distanceCeil_40a3f0(ACT.get_9b6570()->getPosition_45a4a0(),a2q_map_cefc4c->getPlayer_4630f0().get_9b6570()->pos_45a4c0()))) goto pass;
						}
						break;
					}
					case 60:
						if (b.isValid_9b7230())
						{
							if (conds[i].compareString(b.get_9b64f0()->location_45c590())) goto pass;
							else break;
						}
						else if (CELLPROP(e).isValid_9b7230())
						{
							if (conds[i].compareString(CELLPROP(e).get_9b64f0()->location_45c590())) goto pass;
						}
						break;
					case 61:
						if (b.isValid_9b7230())
						{
							if (conds[i].compareString(b.get_9b64f0()->getName_45c5b0())) goto pass;
							else break;
						}
						else if (CELLPROP(e).isValid_9b7230())
						{
							if (conds[i].compareString(CELLPROP(e).get_9b64f0()->getName_45c5b0())) goto pass;
						}
						break;
					case 62:
						if (b.isValid_9b7230())
						{
							if (conds[i].compareInt(b.get_9b64f0()->getNestedField_45c630())) goto pass;
							else break;
						}
						else if (CELLPROP(e).isValid_9b7230())
						{
							if (conds[i].compareInt(CELLPROP(e).get_9b64f0()->getNestedField_45c630())) goto pass;
						}
						break;
					case 63:
						if (b.isValid_9b7230())
						{
							if (conds[i].compareString(b.get_9b64f0()->def_9b8f00()->info->name)) goto pass;
							else break;
						}
						else if (CELLPROP(e).isValid_9b7230())
						{
							if (conds[i].compareString(CELLPROP(e).get_9b64f0()->def_9b8f00()->info->name)) goto pass;
						}
						break;
					case 64:
						if (b.isValid_9b7230())
						{
							if (conds[i].compareInt(b.get_9b64f0()->unknown45c870(a2q_stringToInt_405610(conds[i].key)))) goto pass;
							else break;
						}
						else if (CELLPROP(e).isValid_9b7230())
						{
							if (conds[i].compareInt(CELLPROP(e).get_9b64f0()->unknown45c870(a2q_stringToInt_405610(conds[i].key)))) goto pass;
						}
						break;
					case 65:
						if (b.isValid_9b7230())
						{
							if (conds[i].compareInt(b.get_9b64f0()->unknown45ca00(a2q_stringToInt_405610(conds[i].key)))) goto pass;
							else break;
						}
						else if (CELLPROP(e).isValid_9b7230())
						{
							if (conds[i].compareInt(CELLPROP(e).get_9b64f0()->unknown45ca00(a2q_stringToInt_405610(conds[i].key)))) goto pass;
						}
						break;
					case 66:
					{
						A2QHP prop = b.isValid_9b7230() ? b : CELLPROP(e);
						if (prop.isValid_9b7230())
						{
							vector<A2QHE> &list = a2q_map_cefc4c->group_463890(a2q_stringToInt_405610(conds[i].key)).get_9b7250()->members_416f40();
							int best = 9999;
							int dist;
							for (int j = 0; j < list.size(); j++)
							{
								if (!list[j].get_9b6570()->getTarget_45a760())
								{
									dist = a2q_distanceCeil_40a3f0(prop.get_9b64f0()->pos_4184d0(),list[j].get_9b6570()->pos_45a4c0());
									if (dist < best)
										best = dist;
								}
							}
							if (conds[i].compareInt(best)) goto pass;
						}
						break;
					}
					case 67:
					{
						A2QHP prop = b.isValid_9b7230() ? b : CELLPROP(e);
						if (prop.isValid_9b7230())
						{
							vector<A2QHE> &list = a2q_map_cefc4c->group_463890(a2q_stringToInt_405610(conds[i].key)).get_9b7250()->members_416f40();
							for (int j = 0; j < list.size(); j++)
							{
								if (!list[j].get_9b6570()->getTarget_45a760() && conds[i].compareInt(a2q_distanceCeil_40a3f0(prop.get_9b64f0()->pos_4184d0(),list[j].get_9b6570()->pos_45a4c0())) && a2q_map_cefc4c->unknown465200(prop.get_9b64f0()->pos_4184d0(),list[j].get_9b6570()->pos_45a4c0())) goto pass;
							}
						}
						break;
					}
					case 68:
					{
						A2QHP prop = b.isValid_9b7230() ? b : CELLPROP(e);
						if (prop.isValid_9b7230())
						{
							vector<A2QHG> &groups = *a2q_map_cefc4c->groups_463950();
							int faction = a2q_map_cefc4c->group_463890(3).get_9b7250()->id_9b8f00();
							for (int j = 0; j < groups.size(); j++)
							{
								if (!a2q_map_cefc4c->unknown4638e0(groups[j].get_9b7250()->id_9b8f00(),faction))
								{
									vector<A2QHE> &list = groups[j].get_9b7250()->members_416f40();
									for (int k = 0; k < list.size(); k++)
									{
										if (!list[k].get_9b6570()->getTarget_45a760() && conds[i].compareInt(a2q_distanceCeil_40a3f0(prop.get_9b64f0()->pos_4184d0(),list[k].get_9b6570()->pos_45a4c0())) && (a2q_stringToInt_405610(conds[i].key) == 0 || a2q_stringToInt_405610(conds[i].key) && a2q_map_cefc4c->unknown465200(prop.get_9b64f0()->pos_4184d0(),list[k].get_9b6570()->pos_45a4c0()))) goto pass;
									}
								}
							}
						}
						break;
					}
					case 69:
					{
						A2QHP prop = b.isValid_9b7230() ? b : CELLPROP(e);
						if (prop.isValid_9b7230() && (a2q_stringToInt_405610(conds[i].key) == 0 || a2q_stringToInt_405610(conds[i].key) && a2q_map_cefc4c->isVisible_4631c0(prop.get_9b64f0()->pos_4184d0())) && conds[i].compareInt(a2q_distanceCeil_40a3f0(prop.get_9b64f0()->pos_4184d0(),a2q_map_cefc4c->getPlayer_4630f0().get_9b6570()->pos_45a4c0()))) goto pass;
						break;
					}
					case 70:
						if (c.isValid_9b7230())
						{
							if (conds[i].compareString(c.get_9b65b0()->name_457860())) goto pass;
							break;
						}
						else
							goto inventory;
					case 71:
						if (c.isValid_9b7230())
						{
							if (conds[i].compareString(c.get_9b65b0()->name_457970())) goto pass;
							break;
						}
						else
							goto inventory;
					case 72:
						if (c.isValid_9b7230())
						{
							if (conds[i].compareInt(c.get_9b65b0()->trap_9b6bf0())) goto pass;
							break;
						}
						else
							goto inventory;
					case 73:
						if (c.isValid_9b7230())
						{
							if (conds[i].compareInt(c.get_9b65b0()->getEffectValue_457be0(a2q_stringToInt_405610(conds[i].key)))) goto pass;
							break;
						}
						else
							goto inventory;
					case 74:
						if (c.isValid_9b7230())
						{
							if (conds[i].compareInt(c.get_9b65b0()->unknown457c50(a2q_stringToInt_405610(conds[i].key)))) goto pass;
							break;
						}
					inventory:
					{
						vector<A2QHI> &list = *e.get_9b6570()->getInventoryList_45ab00();
						for (int j = 0; j < list.size(); j++)
						{
							if (list[j].get_9b65b0()->getType_44aec0() <= 3)
							{
								switch (conds[i].type)
								{
									case 0x47:
										if (conds[i].compareString(list[j].get_9b65b0()->name_457970())) goto pass;
										break;
									case 0x48:
										if (conds[i].compareInt(list[j].get_9b65b0()->trap_9b6bf0())) goto pass;
										break;
									case 0x49:
										if (conds[i].compareInt(list[j].get_9b65b0()->getEffectValue_457be0(a2q_stringToInt_405610(conds[i].key)))) goto pass;
										break;
									case 0x4a:
										if (conds[i].compareInt(list[j].get_9b65b0()->unknown457c50(a2q_stringToInt_405610(conds[i].key)))) goto pass;
										break;
								}
							}
						}
						break;
					}
					case 75:
						if (c.isValid_9b7230() && c.get_9b65b0()->unknown457b50().isValid_9b7230() && conds[i].compareString(c.get_9b65b0()->unknown457b50().get_9b6570()->getName_45a280())) goto pass;
						else break;
					case 76:
						if (c.isValid_9b7230() && (a2q_stringToInt_405610(conds[i].key) == 0 || a2q_stringToInt_405610(conds[i].key) && a2q_map_cefc4c->isVisible_4631c0(c.get_9b65b0()->pos_575920())) && conds[i].compareInt(a2q_distanceCeil_40a3f0(c.get_9b65b0()->pos_575920(),a2q_map_cefc4c->getPlayer_4630f0().get_9b6570()->pos_45a4c0()))) goto pass;
						break;
					case 77:
						if (conds[i].compareString((*a2q_grid_cfd44c.atPoint_9ced70(POS))->unknown45d100())) goto pass;
						else break;
					case 78:
						if (conds[i].compareString((*a2q_grid_cfd44c.atPoint_9ced70(POS))->unknown45d120())) goto pass;
						else break;
					case 79:
						if (conds[i].compareInt((*a2q_grid_cfd44c.atPoint_9ced70(POS))->getArmor_66ae70())) goto pass;
						else break;
					case 80:
						if (conds[i].compareString((*a2q_grid_cfd44c.atPoint_9ced70(POS))->def_9fcd80()->info->name)) goto pass;
						else break;
					case 81:
						if (conds[i].compareInt((*a2q_grid_cfd44c.atPoint_9ced70(POS))->getItem_45d8f0().isValid_9b7230() != 0)) goto pass;
						else break;
					case 82:
						if (conds[i].compareInt((*a2q_grid_cfd44c.atPoint_9ced70(POS))->getField_4550b0() != 0)) goto pass;
						else break;
					case 83:
						if (conds[i].compareInt((*a2q_grid_cfd44c.atPoint_9ced70(POS))->isPassableFor_66ab30(A2QHE()) != 0)) goto pass;
						else break;
					case 84:
						if (conds[i].compareInt((*a2q_grid_cfd44c.atPoint_9ced70(POS))->getEntity_45d250().isValid_9b7230() != 0)) goto pass;
						else break;
					case 85:
						if (conds[i].compareInt((*a2q_grid_cfd44c.atPoint_9ced70(POS))->getEffectValue_45d3c0(a2q_stringToInt_405610(conds[i].key)))) goto pass;
						break;
				}
				if (recs[r]->def->jumps[i] != i + 1)
					continue;
				else
				{
					failed = true;
					break;
				}
			pass:
				i = recs[r]->def->jumps[i] - 1;
			}
		}
		if (results)
			results->push_back(failed != 0);
		if (!failed || results)
		{
			if (f == 0)
				f = new vector<A2QMatch *>();
			f->push_back(new A2QMatch(recs[r]->def,e,g,A2QHE()));
			if (h)
				h->push_back(recs[r]);
			else
				recs[r]->unknown5189b0(a2q_actor_ba6118[type].b ? a : e);
		}
		}
	}
	return f;
}
