// alpha2_03: Shoot action constructor (0x64fb40), from codex scratch/loop_bravo_46/ctor.cpp. NOTE: placeholder names.
#include <string>
#include <memory>
#include "rng.h"
using std::string;
extern RNG rng;
// NOTE: private native Shoot124 constructor; borrowed prefixes are partial views.
struct LB46P{int x,y;LB46P();LB46P(const LB46P&) throw();};
struct LB46E;struct LB46I;struct LB46G;struct LB46AI;
struct LB46HE{int id;LB46HE();LB46E*get9b6570()const throw();bool valid9b7230()const throw();void clear9b7270() throw();bool equal9b78e0(LB46HE)const throw();};
struct LB46HI{int id;LB46HI();LB46I*get9b65b0()const throw();bool valid9b7230()const throw();bool equal9b78e0(LB46HI)const throw();};
struct LB46HG{int id;LB46G*get9b7250()const throw();};
template<class T>struct LB46V{T*first,*last,*end;std::allocator<T>allocator;LB46V();LB46V(const LB46V&);~LB46V();unsigned size9b9260()const throw();bool empty9b86e0()const throw();T&at9b81f0(unsigned) throw();void push9b80b0(const T&);void push9b9d30(const T&);void clear();int sum40c820() throw();};
struct LB46Line{LB46P from,to;};
struct LB46EffectDef;struct LB46Modifier{LB46EffectDef*def;int amount;LB46Modifier(LB46EffectDef*d,int a):def(d),amount(a){}};
struct LB46Info{char p[0x2c];int category;};struct LB46IDef{char p0[0x40];int special;char p44[0x15c];LB46Info*info;char p1a4[0x97];bool flag23b;};
struct LB46I{int category457880() throw();LB46Modifier*effect457b70(int) throw();int delay4580e0() throw();void add4585a0(LB46Modifier*);string name571db0(bool,bool);LB46IDef*def9b4350() throw();int value578a70();};
struct LB46G{int kind9b4350() throw();};
struct LB46E{void fill5d5eb0(LB46V<LB46HI>*,LB46HE);int delay5d6d80(LB46V<LB46HI>*,LB46HE);bool fill5d6a80(LB46V<LB46HI>*,const LB46P&,int);int faction45a2c0() throw();int type45a2a0() throw();LB46V<int>*list45afd0() throw();bool player5c7600() throw();LB46HG group45a3f0() throw();string&name45a280() throw();const LB46P&position45a4a0() throw();bool hostile45aa70(LB46HE);int stat5cab90();int cost5d7320(LB46V<LB46HI>*,bool);void add45b210(int) throw();LB46V<int>*values45a9b0() throw();LB46HI item5d2380(int);LB46P point5c80f0(const LB46P&);int range5c7d30();LB46AI*ai45b590() throw();void target45b570(LB46HE) throw();void alert639ec0(LB46HE,bool);void remove63a0d0();void act5db180(LB46HE);int value45a880() throw();string&label416f40() throw();};
struct LB46AI{void alert5b39b0(LB46HE);void flag5b5830(bool);};
struct LB46Part{char p[0x6c];LB46HI item;char p70[0xc];int kind;};struct LB46Parts{LB46V<LB46Part*>*parts4a9ad0() throw();};extern LB46Parts*lb46_cec088;
struct LB46Terrain;struct LB46Cell{LB46HE entity45d250() throw();LB46Terrain*terrain9fcd80() throw();};struct LB46Grid{LB46Cell**at9ced70(const LB46P&) throw();};extern LB46Grid lb46_cfd44c;
struct LB46Player{bool enabled46de40(int);bool event77fbc0(int);void suspicion77ee70(float,int,LB46HE);};extern LB46Player lb46_cf45d8;
struct LB46Target{void init873a50(LB46HE,bool);void pos873ad0(const LB46P&);void update49b8b0();};extern LB46Target lb46_d1d9c0;
struct LB46World{bool check4631f0(LB46HE);void action464120(LB46HE);bool reach465230(int,const LB46P&,const LB46P&);int mode4636d0() throw();bool group71cb10(LB46HE);void action464160();};extern LB46World*lb46_cefc4c;
struct LB46Count{int value46ed20() throw();};struct LB46HC{int id;LB46Count*get9b7910()const throw();};extern LB46HC lb46_d1e888;
extern LB46V<int>lb46_d1dd48,lb46_cfcd20sum;
extern LB46V<LB46EffectDef*>lb46_d2f0f8;extern LB46V<LB46HE>lb46_cf46d4;
bool lb46_contains9db330(const LB46V<int>&,int);void lb46_erase9da940(LB46V<LB46HI>&,int);void lb46_step9d6440(LB46V<LB46HI>&,int&);void lb46_unique9d30e0(LB46V<LB46HE>*,LB46HE);
int lb46_distance40a3f0(const LB46P&,const LB46P&) throw();bool lb46_between9daf80(int,int,int) throw();string lb46_int4051f0(int);void lb46_log404f10(string,string);
struct LB46InfoUI{bool hidden4175f0() throw();void refresh8b5080();};extern LB46InfoUI*lb46_cec118,*lb46_cec11c,*lb46_cec120;
struct LB46UI{void update8758d0(bool);};extern LB46UI*lb46_cec058;struct LB46Log{void end7b4f10();};extern LB46Log*lb46_cec0b4;
struct LB46Stats{bool add4729d0(unsigned,int,string,int);};extern LB46Stats lb46_d2c658;
bool lb46_route5111e0(int,const string*,const string*,const string*,LB46HE,LB46HE,const LB46P*,bool);
struct LB46Mission{bool add7ac1c0(LB46HE,unsigned,bool,string);};extern LB46Mission*lb46_cefc14;
struct LB46EntityPrefix{char p[0x110];int mode;};extern LB46EntityPrefix*lb46_cf68b4;extern LB46HE lb46_cf68b8;
extern bool lb46_cefc8b,lb46_cefb5b,lb46_d1da48,lb46_cefb25;extern int lb46_cf4700,lb46_b96274;extern bool lb46_b951c0[];extern const float lb46_c36ec8,lb46_b96244,lb46_ba8558;extern unsigned lb46_c2ea48;extern LB46Terrain*TERRAIN_EARTH,*TERRAIN_CAVE_WALL,*caveinThirdTerrain;
extern const char lb46_empty_b953ce[],lb46_empty_b953cf[];extern LB46V<string>lb46_d2d4c8;
struct LB46Base{virtual~LB46Base();virtual int kind45b6a0();virtual bool update6516b0();virtual void finish45b6f0();int record,state,time;LB46Base();};
struct LB46Shoot:LB46Base{LB46HE self;int mode;LB46P origin,offset;LB46HE target;LB46V<LB46Line>children;bool quiet,selected,flag;LB46HE tracking;LB46V<LB46HI>items;int fired,active,counter5c,counter60,counter64,counter68;LB46V<LB46P>points;virtual~LB46Shoot();virtual int kind45b6a0();virtual bool update6516b0();virtual void finish45b6f0();void add64faa0(LB46P&);bool excluded6591c0(LB46HE);LB46Shoot(LB46HE,int,const LB46P&,const LB46P&,int*,const LB46V<LB46Line>&,bool,LB46HI);};
static_assert(sizeof(LB46Shoot)==124&&sizeof(LB46Base)==16&&sizeof(LB46Line)==16,"actual owners");
#define TARGET ((*lb46_cfd44c.at9ced70(origin))->entity45d250())
#define ROUTE(ID,TEXT) do{if(lb46_route5111e0(ID,TEXT,0,0,self,LB46HE(),0,false))lb46_cec058->update8758d0(true);lb46_cec0b4->end7b4f10();}while(false)
LB46Shoot::LB46Shoot(LB46HE e,int m,const LB46P&p,const LB46P&o,int*delay,const LB46V<LB46Line>&c,bool q,LB46HI h):LB46Base(),self(e),mode(m),origin(p),offset(o),target(),children(c),quiet(q),selected(h.valid9b7230()),flag(lb46_cefc8b),tracking(),items(),fired(0),active(0),counter5c(0),counter60(0),counter64(0),counter68(0),points(){
 add64faa0(origin);
 switch(mode){
 case 0:self.get9b6570()->fill5d5eb0(&items,TARGET);*delay=self.get9b6570()->delay5d6d80(&items,TARGET);break;
 case 1:
 if(selected){items.push9b80b0(h);*delay=lb46_cfcd20sum.sum40c820()+h.get9b65b0()->delay4580e0();}
 else{self.get9b6570()->fill5d6a80(&items,origin,-1);*delay=self.get9b6570()->delay5d6d80(&items,LB46HE());
 if(self.get9b6570()->faction45a2c0()==24&&self.get9b6570()->type45a2a0()==1&&lb46_contains9db330(*self.get9b6570()->list45afd0(),5)){
 *delay/=2;if(rng.chance(10))for(unsigned i=0;i<items.size9b9260();i++)if(!items.at9b81f0(i).get9b65b0()->effect457b70(92))items.at9b81f0(i).get9b65b0()->add4585a0(new LB46Modifier(lb46_d2f0f8.at9b81f0(92),1000));
 }}
 if(self.get9b6570()->player5c7600()){
 LB46V<LB46HI> w(items);items.clear();LB46V<LB46Part*>*first=lb46_cec088->parts4a9ad0();
 for(unsigned i=0;i<first->size9b9260();i++)if(first->at9b81f0(i)->item.valid9b7230()&&first->at9b81f0(i)->kind==3){for(unsigned j=0;j<w.size9b9260();j++)if(w.at9b81f0(j).equal9b78e0(first->at9b81f0(i)->item)){items.push9b80b0(w.at9b81f0(j));lb46_erase9da940(w,j);break;}}
 if(!w.empty9b86e0())lb46_log404f10("SEntityShoot()",lb46_int4051f0(w.size9b9260())+" weapons left in unordered volley");
 }break;
 }
 if(TARGET.valid9b7230())target=TARGET;
 lb46_cefb5b=quiet;if(self.get9b6570()->player5c7600())lb46_d1da48=quiet;
 if(!quiet&&self.get9b6570()->player5c7600()&&!selected){
 if(TARGET.valid9b7230()){
 lb46_d1d9c0.init873a50(TARGET,excluded6591c0(TARGET));lb46_unique9d30e0(&lb46_cf46d4,TARGET);
 if(TARGET.get9b6570()->group45a3f0().get9b7250()->kind9b4350()==2&&TARGET.get9b6570()->name45a280().find("Zion_Hero_",0)!=lb46_c2ea48&&!excluded6591c0(TARGET)){
 int i=0;int j=lb46_d1e888.get9b7910()->value46ed20();for(;i<3&&j<11;i++,j++)lb46_d1dd48.at9b81f0(j)=1;
 }
 if(lb46_cf45d8.enabled46de40(176)&&lb46_distance40a3f0(self.get9b6570()->position45a4a0(),origin)>20&&lb46_cefc4c->check4631f0(TARGET)&&self.get9b6570()->hostile45aa70(TARGET)&&lb46_b951c0[TARGET.get9b6570()->faction45a2c0()]){
 for(unsigned i=0;i<items.size9b9260();i++)if(!lb46_between9daf80(20,items.at9b81f0(i).get9b65b0()->category457880(),23))goto noAction;
 lb46_cefc4c->action464120(TARGET);
 noAction:;
 }
 if(TARGET.get9b6570()->group45a3f0().get9b7250()->kind9b4350()==4&&!excluded6591c0(TARGET))lb46_cf45d8.event77fbc0(11);
 }else{if(children.empty9b86e0())lb46_d1d9c0.pos873ad0(origin);if((*lb46_cfd44c.at9ced70(origin))->terrain9fcd80()==TERRAIN_EARTH||(*lb46_cfd44c.at9ced70(origin))->terrain9fcd80()==TERRAIN_CAVE_WALL||(*lb46_cfd44c.at9ced70(origin))->terrain9fcd80()==caveinThirdTerrain)lb46_d1d9c0.update49b8b0();}
 }
 if(!quiet&&self.get9b6570()->player5c7600()&&self.get9b6570()->stat5cab90()>=lb46_b96274&&!selected){
 for(int i=0;(unsigned)i<items.size9b9260();i++)if(items.at9b81f0(i).get9b65b0()->category457880()<25&&!items.at9b81f0(i).get9b65b0()->effect457b70(68)&&rng.rangeFloat(0.0f,lb46_c36ec8)<=self.get9b6570()->stat5cab90()/(double)lb46_b96244){
 int message;switch(items.at9b81f0(i).get9b65b0()->category457880()){case 20:case 21:message=363;break;case 22:case 23:message=364;break;case 24:message=365;break;}
 ROUTE(message,&items.at9b81f0(i).get9b65b0()->name571db0(false,false));lb46_d2c658.add4729d0(452,1,lb46_empty_b953ce,-1);lb46_d2c658.add4729d0(465,1,lb46_empty_b953cf,-1);lb46_step9d6440(items,i);
 }
 if(items.empty9b86e0())return;
 }
 int value=self.get9b6570()->cost5d7320(&items,true);int level=*delay/100;
 if(level==0)self.get9b6570()->add45b210(value);
 else{LB46V<int>*v=self.get9b6570()->values45a9b0();value/=level;for(int i=0;i<level;i++){if((unsigned)i<v->size9b9260())v->at9b81f0(i)+=value;else v->push9b9d30(value);}}
 if(lb46_cf45d8.enabled46de40(217))for(unsigned i=0;i<items.size9b9260();i++)if(items.at9b81f0(i).get9b65b0()->def9b4350()->flag23b&&items.at9b81f0(i).get9b65b0()->value578a70()>=350)lb46_cf45d8.event77fbc0(217);
 if(!lb46_cec118->hidden4175f0())lb46_cec118->refresh8b5080();if(!lb46_cec11c->hidden4175f0())lb46_cec11c->refresh8b5080();if(!lb46_cec120->hidden4175f0())lb46_cec120->refresh8b5080();
 if(TARGET.valid9b7230()){
 tracking=TARGET;if(self.get9b6570()->item5d2380(109).valid9b7230()){for(unsigned i=0;i<items.size9b9260();i++)if(items.at9b81f0(i).get9b65b0()->category457880()>25)tracking.clear9b7270();}
 else for(unsigned i=0;i<items.size9b9260();i++)if(items.at9b81f0(i).get9b65b0()->category457880()!=20&&items.at9b81f0(i).get9b65b0()->category457880()!=22)tracking.clear9b7270();
 LB46HE entity=TARGET;
 if(lb46_cefc4c->reach465230(entity.get9b6570()->range5c7d30(),origin,self.get9b6570()->point5c80f0(origin))&&!excluded6591c0(entity)){
 if(entity.get9b6570()->ai45b590())entity.get9b6570()->ai45b590()->alert5b39b0(self);entity.get9b6570()->target45b570(self);
 }}
 if(!excluded6591c0(LB46HE()))self.get9b6570()->alert639ec0(TARGET,mode==0);
 self.get9b6570()->remove63a0d0();if(self.equal9b78e0(lb46_cf68b8)&&lb46_cf68b4->mode==1)self.get9b6570()->ai45b590()->flag5b5830(true);
 if(self.get9b6570()->player5c7600()){
 if(lb46_cf45d8.enabled46de40(159)&&items.size9b9260()>=4){int count=0;for(unsigned i=0;i<items.size9b9260();i++)if(items.at9b81f0(i).get9b65b0()->def9b4350()->special==33)count++;if(count>=4)lb46_cf45d8.event77fbc0(159);}
 if(lb46_cf45d8.enabled46de40(177))for(unsigned i=0;i<items.size9b9260();i++)if(items.at9b81f0(i).get9b65b0()->category457880()==24&&items.at9b81f0(i).get9b65b0()->def9b4350()->info->category!=3){if(!lb46_cefc4c->mode4636d0()&&!lb46_cefc4c->group71cb10(self))lb46_cefc4c->action464160();break;}
 if(!children.empty9b86e0())lb46_cf45d8.event77fbc0(61);
 }
 if(lb46_cf4700){if(self.get9b6570()->player5c7600()){if(!quiet||TARGET.valid9b7230())self.get9b6570()->act5db180(TARGET);}else if(TARGET.valid9b7230()&&TARGET.get9b6570()->player5c7600()&&self.get9b6570()->group45a3f0().get9b7250()->kind9b4350()==3)lb46_cf45d8.suspicion77ee70(lb46_ba8558,22,LB46HE());}
 if(lb46_cefc14){
 if(TARGET.valid9b7230()&&TARGET.get9b6570()->value45a880()<50&&lb46_cefc14->add7ac1c0(self,5,false,TARGET.get9b6570()->label416f40())){}
 else if(!items.empty9b86e0()&&lb46_cefc14)lb46_cefc14->add7ac1c0(self,4,false,items.at9b81f0(0).get9b65b0()->name571db0(false,false));
 }
 if(lb46_cefb25)lb46_d2d4c8.clear();
}
