#include <string>
#include <utility>
#include "rng.h"
using std::string;
// Private partial ABI views. Unknown fields/names remain placeholders.
struct LA18Point{int x,y;int random40c130() throw();};struct LA18Entity;struct LA18AI;struct LA18Effect;
struct LA18H{int id;LA18H();LA18Entity*get9b6570()const throw();bool equal9b78e0(LA18H)const throw();};struct LA18HP{int id;LA18HP();};
struct LA18Group{int faction9b4350() throw();};struct LA18HG{int id;LA18Group*get9b7250()const throw();};
struct LA18Def{char pad[0x28];int faction;string name459c30();};struct LA18Weapon{char pad[0xf0];int special;};
struct LA18IntVec{int a,b,c,d;LA18IntVec();~LA18IntVec();unsigned size9b9260()const throw();int&at9b81f0(unsigned) throw();bool empty9b86e0()const throw();void push9b9d30(const int&);void push9b9280(int&&);};
struct LA18Points{int a,b,c,d;LA18Points();~LA18Points();void push9b32e0(const LA18Point&);};
struct LA18AI{void route4593d0(const LA18Points&);};
struct LA18Entity{int unknown;LA18H self;LA18Def*record;char gapc[0x1c];LA18HG group;char gap2c[0x60];int integrity;void subtract5de950(int,bool) throw();bool player5c7600() throw();string name45a410();int relation5c7fc0(LA18H) throw();int target45a760() throw();LA18Effect*effect45ac40(int) throw();void status5fd900(int,int);bool hostile45aa70(LA18H) throw();int percentage45a880() throw();const LA18Point&position45a4a0() throw();LA18AI*ai45b590() throw();void core5e40f0(int,int,LA18H,LA18Weapon*,int,int,bool);};
struct LA18Map{LA18H player4630f0() throw();LA18H companion463110() throw();bool visible4631f0(LA18H) throw();void remove72e4c0(LA18H,bool);int turn464270() throw();};extern LA18Map*la18_cefc4c;
struct LA18UI{void update8758d0(bool);};extern LA18UI*la18_cec058;struct LA18Log{void end7b4f10() throw();};extern LA18Log*la18_cec0c4,*la18_cec0b4;
struct LA18Stats{bool add4729d0(unsigned,int,string,int);int get472c70(unsigned) throw();};extern LA18Stats la18_d2c658;
struct LA18Flash{void damage965250(int);};extern LA18Flash*la18_cec138;
struct LA18Player{bool companion780790() throw();void event77fbc0(int) throw();};extern LA18Player la18_cf45d8;
struct LA18Tracker{bool spawn7aa280(int,bool,string);};struct LA18State{char pad[8];int amount;char gapc[0x24];LA18Tracker*tracker;};extern LA18State*la18_cf4ac8;
struct LA18View{void message816180(int,int,string,int);};extern LA18View*la18_cec054;
extern RNG rng;
extern int la18_d28d18,la18_cf68ec;extern bool la18_cefc5c,la18_d28d38;extern bool la18_b951c0[];extern string la18_d1e058[];extern LA18H la18_cf68b8;extern LA18Point la18_cfc178,la18_cfd1dc,la18_d221b4[];
string la18_int4051f0(int);bool la18_route5111e0(int,const string*,const string*,const string*,LA18H,LA18HP,const LA18Point*,bool);
struct LA18Entry{int type;LA18H entity;bool test45e820() throw();};struct LA18Entries{int a,b,c,d;unsigned size9b9260()const throw();LA18Entry*&at9b81f0(unsigned) throw();};
struct LA18EntryVec{int a,b,c,d;LA18EntryVec();~LA18EntryVec();bool empty9b86e0()const throw();LA18Entry*&at9b81f0(unsigned) throw();void push9b9d30(LA18Entry*const&);};
struct LA18Pair{int value,weight;};extern const LA18Pair la18_ba43fc[];
struct LA18Weighted{LA18IntVec values,weights;int total;LA18Weighted();~LA18Weighted();void init9b9e90(const LA18Pair*,int);int&pick9ba470() throw();LA18IntVec&values453b40() throw();};
struct LA18Overmind{int countParties(int) throw();LA18Entries*entries45ee50() throw();int response686c60(const LA18Point&,int,int,int);};extern LA18Overmind la18_cf6428;
int la18_distance40a3f0(const LA18Point&,const LA18Point&) throw();int la18_minIndex(LA18IntVec&);int la18_find9d4660(LA18IntVec&,int);
#define LA18_LOG(MSG,TEXT,LATE,OWNER) do{if(la18_route5111e0(MSG,TEXT,0,0,self,LA18HP(),0,LATE))la18_cec058->update8758d0(!LATE);OWNER->end7b4f10();}while(false)
void LA18Entity::core5e40f0(int damage,int unused,LA18H attacker,LA18Weapon*weapon,int chance,int critical,bool overflow){
 subtract5de950(damage,false);
 if(la18_d28d18>=0){
  string text="  "+(player5c7600()?string("Core"):name45a410()+" core");
  text+=overflow?" overflow dmg: ":" damaged: ";text+=la18_int4051f0(damage);
  if(critical)text+=" (Crit: "+la18_d1e058[critical]+")";
  LA18_LOG(player5c7600()?710:relation5c7fc0(la18_cefc4c->player4630f0())==2?711:712,&text,true,la18_cec0c4);
  if(la18_cefc5c&&rng.chance(2)){text="  Combat Log: \"Combat Recyclers are real!\"";LA18_LOG(player5c7600()?710:relation5c7fc0(la18_cefc4c->player4630f0())==2?711:712,&text,true,la18_cec0c4);}
 }
 if(player5c7600()){la18_d2c658.add4729d0(370,damage,"",-1);la18_cec138->damage965250(damage);return;}
 if(self.equal9b78e0(la18_cefc4c->companion463110())){la18_d2c658.add4729d0(1102,damage,"",-1);return;}
 if(integrity>0&&!target45a760()&&((chance&&rng.chance(chance/2))||(weapon&&weapon->special==214&&la18_cf45d8.companion780790()&&rng.chance(5+la18_cf4ac8->amount/150)))&&!effect45ac40(22)){
  status5fd900(3,la18_cfc178.random40c130());
  if(attacker.get9b6570()&&attacker.get9b6570()->player5c7600()){
   la18_d2c658.add4729d0(508,1,"",-1);
   if(la18_b951c0[record->faction]&&attacker.get9b6570()->hostile45aa70(self)){la18_d2c658.add4729d0(509,1,"",-1);if(la18_d2c658.get472c70(509)>=10)la18_cf45d8.event77fbc0(153);}
  }
  LA18_LOG(127,0,false,la18_cec0b4);
  string text="  "+name45a410()+" disabled (Disruption)";
  if(la18_d28d18>=0){LA18_LOG(relation5c7fc0(la18_cefc4c->player4630f0())==2?711:712,&text,true,la18_cec0c4);}
  if(la18_d28d38&&la18_cefc4c->visible4631f0(self))la18_cec054->message816180(12,self.id,"Shutdown",5);
  if(!group.get9b7250()->faction9b4350())la18_cefc4c->remove72e4c0(self,true);
  if(weapon&&weapon->special==214&&la18_cf45d8.companion780790())la18_cf4ac8->tracker->spawn7aa280(16,false,record->name459c30());
 }else if(la18_d28d38&&integrity>0&&la18_cefc4c->visible4631f0(self))la18_cec054->message816180(12,self.id,la18_int4051f0(percentage45a880())+"%",0);
 if(self.equal9b78e0(la18_cf68b8)&&la18_cefc4c->turn464270()>=la18_cf68ec&&rng.chance(15)){
  LA18IntVec first;
  if(rng.chance(75)){first.push9b9280(0);first.push9b9280(1);}else{first.push9b9280(1);first.push9b9280(0);}
  for(unsigned i=0;i<first.size9b9260();i++)switch(first.at9b81f0(i)){
   case 0:if(la18_cf6428.countParties(2)){
    LA18Entries*first=la18_cf6428.entries45ee50();LA18EntryVec h;LA18IntVec v2;
    for(unsigned i=0;i<first->size9b9260();i++)if(first->at9b81f0(i)->type==2&&!first->at9b81f0(i)->test45e820()){
     int firstDist=la18_distance40a3f0(la18_cefc4c->player4630f0().get9b6570()->position45a4a0(),first->at9b81f0(i)->entity.get9b6570()->position45a4a0());
     if(firstDist<=25){h.push9b9d30(first->at9b81f0(i));v2.push9b9d30(firstDist);}
    }
    if(!h.empty9b86e0()){
     int i=la18_minIndex(v2);LA18Points first;
     first.push9b32e0(la18_cefc4c->player4630f0().get9b6570()->position45a4a0());first.push9b32e0(h.at9b81f0(i)->entity.get9b6570()->position45a4a0());h.at9b81f0(i)->entity.get9b6570()->ai45b590()->route4593d0(first);do{}while(false);goto responseDone;
    }
   }break;
   case 1:{LA18Weighted first;first.init9b9e90(la18_ba43fc,6);int b2=first.pick9ba470();int x=la18_d221b4[la18_find9d4660(first.values453b40(),b2)].random40c130();int success=la18_cf6428.response686c60(la18_cefc4c->player4630f0().get9b6570()->position45a4a0(),x,b2,122);if(success){do{}while(false);}goto responseDone;}
  }
 responseDone:
  la18_cf68ec=la18_cefc4c->turn464270()+la18_cfd1dc.random40c130();
 }
}
