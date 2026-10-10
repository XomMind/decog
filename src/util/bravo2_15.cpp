// NOTE: placeholder names and partial layouts; STrapTrigger::unknown665fd0 (0x665fd0): applies a triggered
// trap's effect (blades, splash, explosions, spikes, shock, fire, stasis, alarm, hatch ambush, sucking hatch).
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;
struct T3Entity;struct T3Item;struct T3Prop;struct T3Group;struct T3Effect;struct T3Record;struct T3AI;struct T3Trap;struct T3ItemType;struct T3Lair;struct T3Ambush;
struct T3Point {int x,y;T3Point(const T3Point&);bool eq_409bd0(const T3Point&) const;bool ne_409b90(const T3Point&) const;};
struct T3Pos {int a,b;T3Pos(int);T3Pos(int,int);int randomInRange_40c130();};
struct T3HE {int id;T3HE();bool isValid() const;T3Entity *operator->() const;};
struct T3HI {int id;bool isValid() const;bool isNull() const;T3Item *operator->() const;};
struct T3HP {int id;T3Prop *operator->() const;};
struct T3HG {int id;T3Group *operator->() const;};
struct T3HS {int id;};
struct T3ItemType {char pad[0x70];int slots;};
struct T3Item {T3ItemType *getType();int unknown457af0();bool unknown457e90();int getIntegrity();void unknown458310(int);void remove57dbe0(bool,bool,bool,bool);string unknown571db0(int,int);};
struct T3Trap {char pad[0x18];int state;bool escapeStasis(const T3Point&,T3HE);};
struct T3Prop {T3Trap *getTrap();void unknown65f170();const T3Point &position4184d0();};
struct T3Group {int getType();void unknown6719c0(int,T3HE,T3HE,bool*,vector<T3HE>&,const T3Point&,int);};
struct T3AI {void chase(T3HE,int,int,int,int);void setFollowEntity(T3HE,int);};
struct T3Entity {
 T3HG getGroup();void *unknown45ac40(int);T3HI unknown5e3cb0(int,int,vector<unsigned>&,int,int);bool isPlayer();bool unknown45aaa0(T3HE);bool unknown45aa10();
 void unknown642940(T3HI,bool,int,int,int);int takeDamage(int,int,int,int,int,int,int,bool,T3HE,int,int,int,int,int);int unknown5d2090(int);T3HI unknown5d24e0(int);
 int unknown5cab90();int getFaction();int unknown5cb570(int,int);int unknown5defa0(int,int);void unknown45b210(int);void unknown45b0b0();int unknown5d22a0(int);const T3Point &getPosition();
 bool unknown5cb680(T3HG);int unknown5d15a0(int);T3AI *getAI();int unknown5c7d30();void unknown6395d0(T3Ambush*,int);void unknown5fd900(int,int);int getSize();void unknown637bb0();bool isHostileTo(T3HE);
};
struct T3Cell {T3HE getEntity();T3HI getItem();T3HP getProp();bool unknown45dcf0();void removeProp(int,int);};
struct T3Grid {T3Cell **atPoint(const T3Point&);};extern T3Grid t3_cells_cfd44c;
struct T3Expl {T3Expl(T3HE,int,const T3Point&,T3HE,const T3Pos&,const T3Pos&);char pad[0x40];};
struct T3Factory {T3HS createA(T3Expl*);};extern T3Factory *t3_factory_cefaa8;
struct T3Lair {int group;int evolve;vector<int> a;vector<int> b;vector<string> c;void add(T3HE);};
struct T3World {T3HE getPlayer();bool unknown4633c0(const T3Point&);T3HG unknown463890(int);T3Record *selectRobotOfClass(int,int,int,int);T3HE placeEntity(T3Record*,const T3Point&,int,bool,int,int,bool);
 T3HS addRecord(T3HS);void spawnInfestiationFromTrap(int);vector<T3Lair*> &getLairs();};
extern T3World *t3_world_cefc4c;
struct T3Overmind {void unknown6823f0(int);void unknown68d920(int);void spawnHunterParty(T3HE,const T3Point&,int);void unknown684250(const T3Point&,int);void spawnAntiInfestationCarrier(const T3Point&,const string&);};
extern T3Overmind t3_overmind_cf6428;
struct T3Stats {bool add4729d0(unsigned,int,string,int);};extern T3Stats t3_stats_d2c658;
struct T3Xom {bool enabled;void unknown69e700(int,int,float);void unknown69ea20(bool);};extern T3Xom t3_xom_d25450;
struct T3PlayerData {void unknown77fbc0(int);};extern T3PlayerData t3_playerData_cf45d8;
struct T3LocInfo {int pad0;int type;};
struct T3HLoc {int id;T3LocInfo *operator->() const;};extern T3HLoc t3_location_d1e888;
struct T3Audio {void unknown451400(int);};extern T3Audio t3_audio_cf1080;
struct T3UI {void bubble(int);};extern T3UI *t3_ui_cec058;
struct T3Log {void scrollToEnd();};extern T3Log *t3_log_cec0b4;
struct T3Fx {void init_503b20();};
struct T3ObjB {T3Fx *unknown508610(T3ObjB*,T3Effect*,const T3Point&,void*,int,int,int,int,int);};extern T3ObjB *t3_objB_cefc50;extern int t3_d2e20c;
struct T3RecordT {char pad[0x28];int type;};
struct T3TrapData {int pad0;string name;char pad20[0x8c-0x20];int blast;char pad90[0x140-0x90];int type;};
extern T3TrapData *t3_trapData_cefb7c;
extern int t3_cf462c,t3_cf645c,t3_caf130;
extern vector<int> t3_rifLevels_cf4a04;
extern vector<vector<T3HP> > t3_squad_d20248;
extern vector<T3Point> t3_infest_d20690;
extern vector<T3Ambush*> t3_ambush_d2c408;
extern T3Pos t3_range_d2c43c;
extern vector<int> t3_evoA_d33a90,t3_evoB_d33aa0;extern vector<string> t3_evoC_d33ab0;
bool t3_show5111e0(int,const string*,const string*,const string*,T3HE,T3HE,const T3Point*,bool);
void t3_logPhrase_5141b0(int,const string*,const string*,const string*,T3HE,const T3Point*);
bool t3_lookup2(const string&,T3Effect*&);
string intToString(int);
int opR1d_454260(const T3Point&,int);
void opR1d_4541b0(int,int,int);
void sweepGetSurroundingCells(const T3Point&,vector<T3Point>&);
int t3_distance_40a3f0(const T3Point&,const T3Point&);
bool t3_containsRecord(vector<int>&,int);
int t3_pickIndex_9d4500(vector<int>&);
template<class T> void t3_shuffle(vector<T>&);
template<class T> void t3_moveElement(vector<T>&,unsigned,unsigned);
template<class T> void t3_eraseAt(vector<T>&,int);
template<class T> void t3_removeVectorElement(vector<T>&,int);
template<class T> bool t3_findByName(vector<T*>&,const string&,T*&);
void OpW7_openEvolve(int,int,int);
template <class T>
class OpR5h_WL	// NOTE: partial declaration of the weighted list from src/op/op_r5h_wl.cpp
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	void add(T value, int weight);	// 0x9ba310
	T &pick();	// 0x9ba470
	void remove(T value);
};
class STrapTrigger {
public:
 void unknown665fd0(bool hidden);
 char pad0[0x10];T3TrapData *data;T3Point position;int group;char pad20[4];int value24;int variant;char pad2c[5];bool friendly;bool xom;bool silent;
};
#define T3MSG2(id,a,b,s,o,at) do { if(t3_show5111e0(id,a,b,0,s,o,at,false)) t3_ui_cec058->bubble(1); t3_log_cec0b4->scrollToEnd(); } while(0)
#define T3MSG(id,a,s,o,at) do { if(t3_show5111e0(id,a,0,0,s,o,at,false)) t3_ui_cec058->bubble(1); t3_log_cec0b4->scrollToEnd(); } while(0)
void STrapTrigger::unknown665fd0(bool hidden) {
 T3Effect *fx=0;
 T3HE e=(*t3_cells_cfd44c.atPoint(position))->getEntity();
 if(e.isValid()&&e->getGroup()->getType()==3&&value24==0) {
  t3_overmind_cf6428.unknown6823f0(5);
  t3_stats_d2c658.add4729d0(0x253,1,"",-1);
 }
 switch(data->type) {
 case 0: {
  T3MSG(0x21e,&string("Massive razor-sharp blades shoot up from within the floor."),T3HE(),T3HE(),&position);
  if(!hidden) {
   t3_lookup2("T_Blade_B",fx);
   if(fx)
    t3_objB_cefc50->unknown508610(t3_objB_cefc50,fx,position,&t3_d2e20c,0,0,0,9,0)->init_503b20();
  }
  if(e.isValid()&&!e->unknown45ac40(0x13)) {
   bool first=(*t3_cells_cfd44c.atPoint(position))->getItem().isValid()&&(*t3_cells_cfd44c.atPoint(position))->getItem()->unknown457af0();
   int total=0;
   int steps=rng.rangeInt(1.0f,3.0f);
   vector<unsigned> slots;
   slots.push_back(7);
   slots.push_back(8);
   slots.push_back(9);
   for(int i=0;i<steps;i++) {
    T3HI part=e->unknown5e3cb0(0,-1,slots,1,1);
    if(part.isNull())
     break;
    if(part->getType()->slots<=1)
     continue;
    if(!hidden) {
     T3Effect *sfx;
     t3_lookup2("Part_Sabotaged",sfx);
     if(sfx)
      t3_objB_cefc50->unknown508610(t3_objB_cefc50,sfx,position,&t3_d2e20c,0,0,0,9,0)->init_503b20();
    }
    T3MSG2(e->isPlayer()?0x21f:(e->unknown45aaa0(t3_world_cefc4c->getPlayer())?0x220:0x221),&string("%2 severed."),&part->unknown571db0(0,0),e,T3HE(),&position);
    total++;
    if(part->unknown457e90()||e->unknown45aa10()) {
     T3MSG(0x45,&part->unknown571db0(0,0),e,T3HE(),&position);
     part->remove57dbe0(e->isPlayer(),true,true,true);
    }
    else {
     part->unknown458310(rng.rangeInt((float)(part->getIntegrity()/8),(float)(part->getIntegrity()/4)));
     if(t3_cf462c!=2||e->isPlayer())
      e->unknown642940(part,e->isPlayer(),1,0,2);
    }
   }
   if(first&&total&&t3_xom_d25450.enabled&&e->isPlayer())
    t3_xom_d25450.unknown69e700(0x13,0,0.0f);
  }
  break;
 }
 case 1: {
  T3MSG(0x21e,&string("Arcs of energy rise from the floor."),T3HE(),T3HE(),&position);
  if(!hidden) {
   t3_lookup2("T_Splash_St",fx);
   if(fx)
    t3_objB_cefc50->unknown508610(t3_objB_cefc50,fx,position,&t3_d2e20c,0,0,0,9,0)->init_503b20();
  }
  if(e.isValid()&&!e->unknown45ac40(0x13)) {
   bool first=(*t3_cells_cfd44c.atPoint(position))->getItem().isValid()&&(*t3_cells_cfd44c.atPoint(position))->getItem()->unknown457af0();
   int total=0;
   int steps=rng.rangeInt(2.0f,4.0f);
   vector<unsigned> slots;
   slots.push_back(7);
   slots.push_back(8);
   slots.push_back(9);
   for(int i=0;i<steps;i++) {
    T3HI part=e->unknown5e3cb0(0,-1,slots,1,1);
    if(part.isNull())
     break;
    if(part->getType()->slots<=1)
     continue;
    if(!hidden) {
     T3Effect *sfx;
     t3_lookup2("Part_Sabotaged",sfx);
     if(sfx)
      t3_objB_cefc50->unknown508610(t3_objB_cefc50,sfx,position,&t3_d2e20c,0,0,0,9,0)->init_503b20();
    }
    T3MSG2(e->isPlayer()?0x21f:(e->unknown45aaa0(t3_world_cefc4c->getPlayer())?0x220:0x221),&string("%2 blown off."),&part->unknown571db0(0,0),e,T3HE(),&position);
    total++;
    if(part->unknown457e90()||e->unknown45aa10()) {
     T3MSG(0x45,&part->unknown571db0(0,0),e,T3HE(),&position);
     part->remove57dbe0(e->isPlayer(),true,true,true);
    }
    else {
     part->unknown458310(rng.rangeInt((float)(part->getIntegrity()/5),(float)(part->getIntegrity()/3)));
     if(t3_cf462c!=2||e->isPlayer())
      e->unknown642940(part,e->isPlayer(),1,0,2);
    }
   }
   if(first&&total&&t3_xom_d25450.enabled&&e->isPlayer())
    t3_xom_d25450.unknown69e700(0x13,0,0.0f);
  }
  break;
 }
 case 2:
  T3MSG(0x21e,&string("An explosion rips through the floor."),T3HE(),T3HE(),&position);
  goto explode;
 case 3:
  T3MSG(0x21e,&string("An explosion rips through the floor."),T3HE(),T3HE(),&position);
  goto explode;
 case 4:
  T3MSG(0x21e,&string("A bubble of electromagnetic force engulfs the area."),T3HE(),T3HE(),&position);
  goto explode;
 case 5:
  T3MSG(0x21e,&string("An expanding cloud of shrapnel blasts out in all directions."),T3HE(),T3HE(),&position);
  goto explode;
 case 6:
  T3MSG(0x21e,&string("A wave of accelerated entropy washes over the area."),T3HE(),T3HE(),&position);
 explode:
  if(t3_xom_d25450.enabled&&xom)
   t3_xom_d25450.unknown69e700(0x14,0,0.0f);
  if(data->blast)
   t3_world_cefc4c->addRecord(t3_factory_cefaa8->createA(new T3Expl(friendly?t3_world_cefc4c->getPlayer():T3HE(),data->blast,position,T3HE(),T3Pos(-1),T3Pos(-1))));
  break;
 case 7:
  T3MSG(0x21e,&string("Spikes shoot up from the floor."),T3HE(),T3HE(),&position);
  if(!hidden) {
   t3_lookup2("T_Ascii_Pt",fx);
   if(fx)
    t3_objB_cefc50->unknown508610(t3_objB_cefc50,fx,position,&t3_d2e20c,0,0,0,9,0)->init_503b20();
  }
  if(e.isValid()) {
   t3_trapData_cefb7c=data;
   int base=3;
   T3Pos damage(7,12);
   T3HE old=e;
   for(int i=0;i<base;i++)
    if(e->takeDamage(0xb,0,0,damage.randomInRange_40c130(),6,rng.chance(0x32)?8:0,0,hidden,T3HE(),0,8,0,0,0)>=1)
     break;
  }
  break;
 case 8: {
  bool em=data->name!="Shock Trap";
  T3MSG(0x21e,&string("The floor emits a surge of raw power."),T3HE(),T3HE(),&position);
  if(!hidden) {
   t3_lookup2(em?"T_Asciisplash_EMSt":"T_Asciisplash_St",fx);
   if(fx)
    t3_objB_cefc50->unknown508610(t3_objB_cefc50,fx,position,&t3_d2e20c,0,0,0,9,0)->init_503b20();
  }
  if(e.isValid()) {
   if(rng.chance(e->unknown5d2090(0x29)*10)) {
    if(e->isPlayer())
     T3MSG(0x222,&e->unknown5d24e0(0x29)->unknown571db0(0,0),e,T3HE(),0);
   }
   else {
    bool fresh=!e->unknown5cab90();
    int amount=!e->isPlayer()&&e->getFaction()!=0x49?(em?rng.rangeInt(80.0f,120.0f):rng.rangeInt(50.0f,80.0f)):(em?rng.rangeInt(3.0f,5.0f):rng.rangeInt(1.0f,2.0f));
    amount=e->unknown5cb570(3,1)*amount/100;
    if(amount>0&&e->unknown5defa0(amount,1)&&e->isPlayer()) {
     string text="System corrupted (+"+intToString(amount)+").";
     T3MSG(0x21f,&text,T3HE(),T3HE(),&position);
     t3_xom_d25450.unknown69ea20(fresh);
    }
   }
  }
  break;
 }
 case 9: {
  T3MSG(0x21e,&string("Burning plasma bursts from the floor."),T3HE(),T3HE(),&position);
  if(!hidden) {
   t3_lookup2("T_Fire_Ft_E",fx);
   if(fx)
    t3_objB_cefc50->unknown508610(t3_objB_cefc50,fx,position,&t3_d2e20c,0,0,0,9,0)->init_503b20();
  }
  if(e.isValid()) {
   t3_trapData_cefb7c=data;
   T3Pos base(3,5);
   T3Pos damage(12,14);
   T3HE old=e;
   int count=base.randomInRange_40c130();
   for(int i=0;i<count;i++)
    if(e->takeDamage(0xb,0,0,damage.randomInRange_40c130(),1,0,0x28,hidden,T3HE(),0,8,0,0,0)>=1)
     break;
  }
  vector<T3Point> cells;
  sweepGetSurroundingCells(position,cells);
  vector<T3HE> targets;
  if(e.operator->())
   targets.push_back(e);
  for(unsigned i=0;i<cells.size();i++)
   if((*t3_cells_cfd44c.atPoint(cells[i]))->getEntity().isValid())
    targets.push_back((*t3_cells_cfd44c.atPoint(cells[i]))->getEntity());
  for(unsigned j=0;j<targets.size();j++)
   if(targets[j].operator->()) {
    int heat=rng.rangeInt(200.0f,400.0f);
    int resist=100-targets[j]->unknown5d2090(0x2c);
    targets[j]->unknown45b210(heat*resist/100);
   }
  break;
 }
 case 10:
  T3MSG(0x21e,&string("A powerful wave of heat washes over the area."),T3HE(),T3HE(),&position);
  goto explode;
 case 11:
  if(!silent)
   T3MSG(0x21e,&string("A bubble of rippling energy engulfs the area."),T3HE(),T3HE(),&position);
  if((*t3_cells_cfd44c.atPoint(position))->unknown45dcf0()) {
   (*t3_cells_cfd44c.atPoint(position))->getProp()->getTrap()->state=1;
   if(e.isValid()) {
    e->unknown45b0b0();
    if(!silent)
     (*t3_cells_cfd44c.atPoint(position))->getProp()->getTrap()->escapeStasis(position,e);
   }
  }
  break;
 case 12:
  if(t3_world_cefc4c->unknown4633c0(position)&&(t3_rifLevels_cf4a04[8]||t3_world_cefc4c->getPlayer()->unknown5d22a0(0x14)&&t3_distance_40a3f0(position,t3_world_cefc4c->getPlayer()->getPosition())<=t3_world_cefc4c->getPlayer()->unknown5d22a0(0x14))) {
   if(t3_rifLevels_cf4a04[8])
    T3MSG(0x2a7,0,T3HE(),T3HE(),&position);
   else
    T3MSG(0x225,&t3_world_cefc4c->getPlayer()->unknown5d24e0(0x14)->unknown571db0(0,0),T3HE(),T3HE(),&position);
   t3_playerData_cf45d8.unknown77fbc0(0x71);
  }
  else {
   T3MSG(0x21e,&string("An alarm sounds."),T3HE(),T3HE(),&position);
   if(t3_location_d1e888->type==0xe)
    t3_overmind_cf6428.unknown68d920(2);
   else if(t3_location_d1e888->type!=0xd) {
    bool heard=opR1d_454260(position,0x9d);
    if(heard) {
     string alert=t3_cf645c?"ALERT: Alarm triggered, assault force dispatched.":"ALERT: Alarm triggered, dispatching investigation squad.";
     do {
      t3_audio_cf1080.unknown451400(1);
      if(0)
       opR1d_4541b0(-1,0,0);
      do { if(t3_show5111e0(0x324,&alert,0,0,T3HE(),T3HE(),0,false)) t3_ui_cec058->bubble(1); t3_log_cec0b4->scrollToEnd(); } while(0);
      t3_log_cec0b4->scrollToEnd();
     } while(0);
    }
    if(t3_caf130!=6) {
     if(t3_cf645c)
      t3_overmind_cf6428.spawnHunterParty(T3HE(),position,1);
     else
      t3_overmind_cf6428.unknown684250(position,0);
    }
   }
   if(e.isValid()&&e->unknown5cb680(t3_world_cefc4c->unknown463890(3))) {
    bool first;
    vector<T3HE> allies;
    t3_world_cefc4c->unknown463890(3)->unknown6719c0(0,T3HE(),e,&first,allies,position,0xf);
    if(t3_xom_d25450.enabled&&e->isPlayer())
     for(unsigned i=0;i<allies.size();i++)
      if(allies[i]->getFaction()==0x1c) {
       t3_xom_d25450.unknown69e700(0x2a,e->unknown5d15a0(0)>=100,0.0f);
       break;
      }
   }
  }
  break;
 case 13: {
  opR1d_454260(position,0x9e);
  vector<T3HP> &squad=t3_squad_d20248[group];
  if(squad.empty())
   break;
  t3_shuffle(squad);
  if(squad.front()->position4184d0().eq_409bd0(position))
   for(unsigned i=1;i<squad.size();i++)
    if(squad[i]->position4184d0().ne_409b90(position)) {
     t3_moveElement(squad,i,0);
     break;
    }
  bool removed=false;
  switch(variant) {
  case 0: {
   OpR5h_WL<int> weight;
   weight.add(0xd,0x32);
   weight.add(0x10,0x32);
   weight.add(0x11,0x19);
   weight.add(0x12,0x19);
   vector<int> tags;
   tags.push_back(0x11);
   tags.push_back(0x12);
   int cnt=0;
   vector<T3Record*> found;
   int pick;
   for(int i=0;i<squad.size()&&i<3;i++)
    for(int t=0;t<20;t++) {
     pick=weight.pick();
     found.push_back(t3_world_cefc4c->selectRobotOfClass(1,pick,0,0));
     if(found.back()) {
      if(t3_containsRecord(tags,pick)) {
       cnt++;
       if(cnt==2)
        for(unsigned k=0;k<tags.size();k++)
         weight.remove(tags[k]);
      }
      break;
     }
     else
      found.pop_back();
    }
   for(unsigned i=0;i<found.size();i++)
    if(t3_containsRecord(tags,((T3RecordT*)found[i])->type))
     t3_moveElement(found,i,0);
   vector<T3Point> pt;
   vector<int> costs;
   for(unsigned i=0;i<found.size();i++) {
    pt.push_back(squad[i]->position4184d0());
    costs.push_back(t3_distance_40a3f0(position,pt.back()));
   }
   for(unsigned i=0;i<found.size();i++) {
    int damage;
    if(t3_containsRecord(tags,((T3RecordT*)found[i])->type))
     damage=t3_pickIndex_9d4500(costs);
    else
     damage=0;
    T3Point at(pt[damage]);
    T3HE first=t3_world_cefc4c->placeEntity(found[i],at,3,false,0x22,0xe,false);
    if(first.isValid()) {
     T3MSG(0x21e,&string("[name] emerges from a hatch in the floor."),first,T3HE(),&position);
     if(e.isValid()&&e->isHostileTo(first))
      first->getAI()->chase(e,1,t3_range_d2c43c.randomInRange_40c130(),0,0);
    }
    t3_eraseAt(pt,damage);
    t3_removeVectorElement(costs,damage);
   }
   break;
  }
  case 1: {
   T3HE leader;
   if(t3_distance_40a3f0(t3_world_cefc4c->getPlayer()->getPosition(),position)<=t3_world_cefc4c->getPlayer()->unknown5c7d30())
    leader=t3_world_cefc4c->getPlayer();
   T3Record *rec;
   for(int i=0;i<squad.size()&&i<3;i++) {
    rec=t3_world_cefc4c->selectRobotOfClass(3,0x10,0,1);
    if(rec) {
     T3HE m=t3_world_cefc4c->placeEntity(rec,squad[i]->position4184d0(),9,false,0x22,0xe,false);
     if(m.isValid()) {
      T3MSG(0x226,0,m,T3HE(),&position);
      if(leader.isValid())
       m->getAI()->setFollowEntity(leader,0);
      else
       leader=m;
      if(i==0) {
       T3Ambush *ambush;
       t3_findByName(t3_ambush_d2c408,"T_Ambush_Derelicts",ambush);
       if(ambush)
        m->unknown6395d0(ambush,0);
      }
     }
    }
   }
   if(rec)
    do {t3_logPhrase_5141b0(0x72,0,0,0,T3HE(),&position);} while(0);
   break;
  }
  case 2:
   if((*t3_cells_cfd44c.atPoint(position))->unknown45dcf0()) {
    removed=true;
    do {t3_logPhrase_5141b0(0x73,0,0,0,T3HE(),&position);} while(0);
    (*t3_cells_cfd44c.atPoint(position))->getProp()->unknown65f170();
    OpR5h_WL<int> weight;
    int pick;
    T3Record *found;
    weight.add(0xd,0x32);
    weight.add(0xf,0x19);
    weight.add(0x10,0x32);
    weight.add(0x11,0x19);
    weight.add(0x12,0x19);
    for(unsigned i=1;i<squad.size();i++)
     for(int t=0;t<10;t++) {
      pick=weight.pick();
      found=t3_world_cefc4c->selectRobotOfClass(1,pick,0,0);
      if(found) {
       T3HE m=t3_world_cefc4c->placeEntity(found,squad[i]->position4184d0(),3,false,0x22,0xe,false);
       if(m.isValid()) {
        T3MSG(0x227,0,m,T3HE(),&position);
        m->unknown5fd900(8,0);
       }
       break;
      }
     }
    (*t3_cells_cfd44c.atPoint(position))->getProp()->getTrap()->state=5;
    t3_infest_d20690.push_back(position);
    t3_world_cefc4c->spawnInfestiationFromTrap(t3_infest_d20690.size()-1);
    t3_overmind_cf6428.spawnAntiInfestationCarrier(position,string("ALERT: Infestation has breached Complex 0b10, dispatching Demolisher response squad."));
   }
   break;
  }
  if(t3_xom_d25450.enabled&&(variant==0||variant==2)&&xom)
   t3_xom_d25450.unknown69e700(0x28,t3_world_cefc4c->getPlayer()->unknown5d15a0(0)>=0x50,0.0f);
  for(int i=squad.size()-1;i>=(removed?1:0);i--)
   (*t3_cells_cfd44c.atPoint(squad[i]->position4184d0()))->removeProp(0,3);
  break;
 }
 case 14:
  opR1d_454260(position,0x9f);
  T3MSG(0x21e,&string("A hatch slides open and sucks a vortex of air into the floor."),T3HE(),T3HE(),&position);
  if(e.isValid()&&e->getSize()==1&&!e->unknown45ac40(0x33)) {
   vector<T3Lair*> &lairs=t3_world_cefc4c->getLairs();
   for(unsigned i=0;i<lairs.size();i++)
    if(lairs[i]->group==group) {
     if(e->isPlayer()) {
      if(t3_xom_d25450.enabled&&xom)
       t3_xom_d25450.unknown69e700(0x29,e->unknown5d15a0(0)>=100,0.0f);
      do {t3_logPhrase_5141b0(0x19,0,0,0,T3HE(),0);} while(0);
      t3_evoA_d33a90=lairs[i]->a;
      t3_evoB_d33aa0=lairs[i]->b;
      t3_evoC_d33ab0=lairs[i]->c;
      OpW7_openEvolve(0,lairs[i]->evolve,0);
     }
     else {
      T3MSG(e->unknown45aaa0(t3_world_cefc4c->getPlayer())?0x220:0x221,&string("[name] sucked into the hatch."),e,T3HE(),&position);
      lairs[i]->add(e);
      e->unknown637bb0();
     }
     break;
    }
  }
  break;
 }
}
