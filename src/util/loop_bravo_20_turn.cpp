#include <string>
#include "rng.h"
using std::string;extern RNG rng;
struct LB20Entity;struct LB20Def;struct LB20Record;struct LB20Fx;
struct LB20P {int x,y;LB20P() throw();LB20P(int) throw();LB20P(int,int) throw();LB20P(const LB20P&) throw();void assign46ca50(const LB20P&) throw();};
struct LB20H {int id;LB20H() throw();bool null9b65d0()const throw();LB20Entity*get9b6570()const throw();};struct LB20HP{int id;LB20HP() throw();};struct LB20HI{int id;};
struct LB20Hs {int a,b,c,d;LB20Hs(const LB20Hs&);~LB20Hs();bool empty9b86e0()const throw();unsigned size9b9260()const throw();LB20H&at9b81f0(unsigned) throw();};
struct LB20Ps {int a,b,c,d;LB20Ps();~LB20Ps();bool empty9b86e0()const throw();unsigned size9b9a50()const throw();LB20P&at9e7c10(unsigned) throw();void clear9b3560() throw();};
struct LB20Ints {int a,b,c,d;LB20Ints();~LB20Ints();int&at9b81f0(unsigned) throw();};
struct LB20Def {char p0[0xf0];int special,other;string name459c30();};
struct LB20Entity {int target45a760() throw();bool player5c7600() throw();int resource45a8d0() throw();bool state45a780() throw();int state5cad50() throw();bool relation5c8820(LB20H) throw();void neighbors5c8b10(LB20Ps&,LB20H) throw();const LB20P&pos45a4a0() throw();void move5ddac0(const LB20P&,bool) throw();int attr5d1390() throw();void adjust45b0d0(int,int,int) throw();void adjust45b1b0(int) throw();LB20Def*def9b4350() throw();const string&name416f40() throw();};
struct LB20EffectType;struct LB20EffectPair {LB20EffectType*type;int value;LB20EffectPair(LB20EffectType*,int);};
LB20EffectPair::LB20EffectPair(LB20EffectType*type_,int value_){type=type_;value=value_;}
struct LB20Item {int pad;LB20HI self;LB20Def*def;int padc;LB20H owner;int turn57cdd0();bool available457cf0() throw();bool select57c3f0(LB20P&,int&,LB20Def*,int) throw();LB20EffectPair*effect457b70(int) throw();void add4585a0(LB20EffectPair*);void remove458630(LB20EffectPair*) throw();string name571db0(bool,bool);void move57a0f0(const LB20P&,int,bool) throw();};
struct LB20Map {LB20Hs*companions4636b0() throw();void refresh726520() throw();bool visible4633c0(const LB20P&) throw();bool line7170a0(LB20H,const LB20P&,LB20Ps&,LB20Ints&,LB20Ints&,LB20P&,const LB20P*,int,bool,bool);int chance463710() throw();bool pull71ef30(const LB20P&,bool) throw();LB20H player4630f0() throw();};extern LB20Map*lb20_cefc4c;
struct LB20Cell {LB20H entity45d250() throw();};struct LB20Grid {LB20Cell**at9ced70(LB20P&) throw();};extern LB20Grid lb20_cfd44c;
void lb20_shuffle(LB20Hs&);float lb20_distance40a450(const LB20P&,const LB20P&) throw();int lb20_distance40a3f0(const LB20P&,const LB20P&) throw();int lb20_cost4374c0(const LB20P&,const LB20P&) throw();
bool lb20_lookup(const string&,LB20Fx*&);struct LB20Defs{int a,b,c,d;};extern LB20Defs lb20_d2d1c4;bool lb20_find(LB20Defs&,const string&,LB20Def*&);struct LB20Types {int a,b,c,d;LB20EffectType*&at9b81f0(unsigned) throw();};extern LB20Types lb20_d2f0f8;
struct LB20Effects;struct LB20Owned;struct LB20Effect {void init503b20(LB20Effects*,LB20Fx*,const LB20P&,const LB20P&,const LB20P*,const LB20P*,LB20Owned*,int,LB20Effect*) throw();};struct LB20Effects{LB20Effect*alloc508610() throw();};extern LB20Effects*lb20_cefc50;extern LB20P lb20_d2e20c;
struct LB20Player {bool companion780790() throw();};extern LB20Player lb20_cf45d8;
struct LB20Tracker {bool spawn7aa280(int,bool,string);};struct LB20State {char pad[0x30];LB20Tracker*tracker;};extern LB20State*lb20_cf4ac8;
struct LB20Queue {void move6728c0(LB20H) throw();};extern LB20Queue lb20_d225a0;
struct LB20View {void delay49adc0(int) throw();int item8119c0(LB20HI,bool,int,int) throw();};extern LB20View*lb20_cec054;
void lb20_message49c610(int,LB20H,const string&,int);bool lb20_route5111e0(int,const string*,const string*,const string*,LB20H,LB20HP,const LB20P*,bool);
struct LB20UI{void update8758d0(bool) throw();};extern LB20UI*lb20_cec058;struct LB20Log{void end7b4f10() throw();};extern LB20Log*lb20_cec0c4;
struct LB20Xom{bool enabled;void event69e700(int,int,float) throw();};extern LB20Xom lb20_d25450;
int LB20Item::turn57cdd0(){
 if(owner.null9b65d0()||owner.get9b6570()->target45a760())return 500;
 switch(def->special){case 214:if(def->other&&owner.get9b6570()->player5c7600()&&rng.chance(5)&&owner.get9b6570()->resource45a8d0()>=25&&!lb20_cefc4c->companions4636b0()->empty9b86e0()&&!owner.get9b6570()->state45a780()&&!owner.get9b6570()->state5cad50()){
 LB20Hs*p=lb20_cefc4c->companions4636b0();
 for(unsigned i=0;i<p->size9b9260();i++)if(p->at9b81f0(i).get9b6570()&&owner.get9b6570()->relation5c8820(p->at9b81f0(i)))goto companionDone;
 lb20_cefc4c->refresh726520();
 if(!p->empty9b86e0()){
 LB20Hs b=*p;lb20_shuffle(b);LB20Ps a;
 for(unsigned i=0;i<b.size9b9260();i++)if(!b.at9b81f0(i).get9b6570()->target45a760()){
 a.clear9b3560();b.at9b81f0(i).get9b6570()->neighbors5c8b10(a,owner);
 if(!a.empty9b86e0()){
 LB20P x(-1);float count;float num;
 for(unsigned index=0;index<a.size9b9a50();index++)if(lb20_cefc4c->visible4633c0(a.at9e7c10(index))){num=lb20_distance40a450(owner.get9b6570()->pos45a4a0(),a.at9e7c10(index));if(x.x==-1||num<count){x.assign46ca50(a.at9e7c10(index));count=num;}}
 if(x.x!=-1){
 LB20P label=owner.get9b6570()->pos45a4a0();LB20Fx*f;lb20_lookup("Companion_Teleport",f);
 if(f){LB20Ps list;LB20Ints first;LB20Ints other;LB20P valid;
 lb20_cefc4c->line7170a0(owner,x,list,first,other,valid,0,4,true,true);
 for(unsigned n=0;n<list.size9b9a50();n++)lb20_cefc50->alloc508610()->init503b20(lb20_cefc50,f,list.at9e7c10(n),lb20_d2e20c,0,0,0,other.at9b81f0(n),0);
 }
 int value=lb20_cost4374c0(label,x);owner.get9b6570()->move5ddac0(x,true);owner.get9b6570()->adjust45b0d0(3,value,owner.get9b6570()->attr5d1390());owner.get9b6570()->adjust45b1b0(25);
 if(lb20_cf45d8.companion780790())lb20_cf4ac8->tracker->spawn7aa280(25,false,b.at9b81f0(i).get9b6570()->def9b4350()->name459c30());
 string line="The surroundings shift and blur.";lb20_message49c610(0x320,LB20H(),line,0);lb20_d225a0.move6728c0(owner);lb20_cec054->delay49adc0(1000);return(int)(rng.rangeFloat(.6f,1.4f)*100.0);
 }
 }
 }
 }
 companionDone:return 100;
 }break;}
 if(!available457cf0())return 100;
 switch(def->special){case 207:{LB20P x(-1);int count;if(select57c3f0(x,count,0,0))return 100;LB20EffectPair*type=effect457b70(97);if(x.x!=-1){if(!type)add4585a0(new LB20EffectPair(lb20_d2f0f8.at9b81f0(97),1));return count;}else{if(type)remove458630(type);return 100;}break;}
 case 214:if(def->other&&rng.chance(lb20_cefc4c->chance463710()*2+2)){
 LB20Def*entity;lb20_find(lb20_d2d1c4,"Quantum Blade",entity);LB20P x(-1);int count;
 if(select57c3f0(x,count,entity,1)){return 100;}else{
 string line=" "+name571db0(0,0)+" ranged attack (100%) Hit";
 do{if(lb20_route5111e0(0x2c0,&line,0,0,owner,LB20HP(),0,true))lb20_cec058->update8758d0(false);lb20_cec0c4->end7b4f10();}while(false);
 if(lb20_cf45d8.companion780790())lb20_cf4ac8->tracker->spawn7aa280(24,false,(*lb20_cfd44c.at9ced70(x))->entity45d250().get9b6570()->def9b4350()->name459c30());
 string label=name571db0(0,0)+" releases a shadow of itself that zips off towards "+(*lb20_cfd44c.at9ced70(x))->entity45d250().get9b6570()->name416f40()+".";lb20_message49c610(0x320,LB20H(),label,0);
 if(lb20_d25450.enabled&&rng.chance(10)&&lb20_cefc4c->pull71ef30(x,true)){
 move57a0f0(x,false,true);lb20_cec054->item8119c0(self,1,0,1);string line="Shadow retroactively draws in "+name571db0(0,0)+".";lb20_message49c610(0x320,LB20H(),line,0);
 if(lb20_cf45d8.companion780790())lb20_cf4ac8->tracker->spawn7aa280(41,false,"");if(lb20_distance40a3f0(lb20_cefc4c->player4630f0().get9b6570()->pos45a4a0(),x)>10)lb20_d25450.event69e700(52,0,0.f);
 }
 lb20_cec054->delay49adc0(1000);return(int)(rng.rangeFloat(.6f,1.4f)*100.0);
 }
 }return 100;
 default:return 100;}
}
