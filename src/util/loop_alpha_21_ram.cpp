#include <string>
#include "rng.h"
using std::string;extern RNG rng;
// NOTE: private names and layouts represent only retail-accessed fields.
struct LA21P{int x,y;LA21P(const LA21P&)throw();bool unequal409bd0(const LA21P&)const throw();LA21P&subtract409a30(const LA21P&)throw();int random40c130()throw();};
struct LA21Entity;struct LA21AI;struct LA21Effects;struct LA21Weapon;struct LA21Explosion;struct LA21Record;struct LA21Records{int a,b,c,d;};struct LA21Fx;struct LA21Owned;
struct LA21H{int id;LA21H()throw();LA21Entity*get9b6570()const throw();bool null9b65d0()const throw();};struct LA21HP{int id;LA21HP()throw();};struct LA21HI{int id;LA21HI()throw();bool valid9b7230()const throw();};
struct LA21Group{int pad0,pad4,faction;int faction9b4350()throw();};struct LA21HG{int id;LA21Group*get9b7250()const throw();};
struct LA21Ps{int a,b,c,d;LA21Ps();~LA21Ps();LA21P&at9e7c10(unsigned)throw();void push9b32e0(const LA21P&);unsigned size9b9a50()const throw();bool empty9b86e0()const throw();};
struct LA21Def{char pad[0x24];int value;};struct LA21AI{void alert5b39b0(LA21H);};
struct LA21Entity{int pad0;LA21H self;LA21Def*def;char pc[0x1c];LA21HG group;char p2c[4];LA21Ps positions;char p40[0x10];int momentum,direction;char p58[0x34];int integrity;char p90[0x24];int fieldb4;char pb8[0x34];LA21Effects*effects;
 int ram5ff700(int,const LA21P&);int movement5d1390()throw();int size45a360()throw();int level5d14d0(int,bool)throw();int bonus5d2090(int)throw();int value45a340()throw();int value490840()throw();LA21Record*effect45ac40(int)throw();bool player5c7600()throw();void track5db180(LA21H);bool state45a780()throw();int mass5c8cb0()throw();int power5d1d70()throw();bool important5c8020()throw();void alert639ec0(LA21H,bool);void clear63a0d0();bool hostile45aa70(LA21H)throw();int status5cba50()throw();
 int damage5e5520(int,LA21Weapon*,LA21Explosion*,int,int,int,int,bool,LA21H,int,int,int,int,bool);void hit600e30();void die633790(bool,int,LA21H,int,int,LA21Explosion*,LA21Records*,bool);void move5ddac0(const LA21P&,bool);bool allowed5c84f0(const LA21P&)throw();bool blocked5c8710(const LA21P&)throw();bool other5c85a0(const LA21P&,bool)throw();void set45b090(int)throw();void clear45b0b0()throw();void swap5dd8a0(LA21H);LA21AI*ai45b590()throw();LA21HG group45a3f0()throw();const LA21P&pos45a4a0()throw();void drop5e2b00(int,const LA21P&);bool update5fdd30();LA21HI item5d2380(int)throw();};
struct LA21Cell{LA21H entity45d250()throw();};struct LA21Grid{LA21Cell**at9ced70(const LA21P&)throw();};extern LA21Grid la21_cfd44c;
struct LA21Map{void attack735720(LA21H,LA21H,bool);void hit7358c0(LA21H,LA21H);bool companion463510(LA21H)throw();bool follower4635c0(LA21H)throw();void move72e4c0(LA21H,bool);LA21HI spawn71e7c0(const LA21P&,int,bool);};extern LA21Map*la21_cefc4c;
struct LA21Ints{int&at9b81f0(unsigned)throw();};struct LA21Stats{LA21Ints*values;bool add4729d0(unsigned,int,string,int);void adjust472b90(unsigned,int);};extern LA21Stats la21_d2c658;
struct LA21Player{void achieve77fbc0(int);int add77eca0(int);};extern LA21Player la21_cf45d8;
struct LA21Effect;struct LA21EffectPool{LA21Effect*alloc508610()throw();};struct LA21Effect{void init503b20(LA21EffectPool*,LA21Fx*,const LA21P&,const LA21P&,const LA21P*,const LA21P*,LA21Owned*,int,LA21Effect*)throw();};extern LA21EffectPool*la21_cefc50;
struct LA21Factory{bool show793450(int,bool,const string*,bool,bool);};extern LA21Factory*la21_cefaa8;
struct LA21UI{void update8758d0(bool);};extern LA21UI*la21_cec058;struct LA21Log{void end7b4f10()throw();};extern LA21Log*la21_cec0b4;
struct LA21View{void move8069e0(LA21P,bool);};extern LA21View*la21_cec054;
extern int la21_cf4700,la21_d25740,la21_cf462c,la21_cf4718,la21_d1f3f0;extern bool la21_d28e27;extern int la21_b96328[],la21_b962e8[],la21_b96308[],la21_ba7ec0[];extern float la21_b949a8[];extern LA21P la21_d015d8[],la21_d2e20c,la21_d2f17c,la21_d28fd0;extern string la21_d1f3d4,la21_d32468;
int la21_min(int,int)throw();int la21_max(int,int)throw();void la21_clamp(int,int&,int)throw();int la21_sound4541b0(unsigned,int,int);bool la21_lookup9d7980(const string&,LA21Fx*&);void la21_erase(LA21Ps&,int)throw();LA21P la21_random(const LA21Ps&);
bool la21_route5111e0(int,const string*,const string*,const string*,LA21H,LA21HP,const LA21P*,bool);
bool la21_effect4569a0(int,LA21H,LA21H,LA21HP,LA21HI,int,const string&,LA21Effects*,LA21H,LA21HP,LA21HI,int);
#define LA21_LOG(ID) do{if(la21_route5111e0(ID,0,0,0,f,LA21HP(),0,false))la21_cec058->update8758d0(true);la21_cec0b4->end7b4f10();}while(false)
int LA21Entity::ram5ff700(int direction_,const LA21P&position){
 LA21H f=(*la21_cfd44c.at9ced70(position))->entity45d250();
 bool i;int n=movement5d1390();int type=11;i=false;int p=0;bool h=false;
 if(n==1){type=12;if(f.get9b6570()->size45a360()<=3&&rng.chance(level5d14d0(n+9,true)*20))i=true;}
 else{if(n==0||n==3)p=la21_min(bonus5d2090(118),35);if(p){type=13;if(f.get9b6570()->value45a340()<=2&&f.get9b6570()->value490840()<=50&&!f.get9b6570()->effect45ac40(23)&&rng.chance(p))h=true;}}
 if(h){LA21_LOG(156);la21_d2c658.add4729d0(485,1,"",-1);}
 else if(type==12){LA21_LOG(i?155:154);la21_d2c658.add4729d0(484,1,"",-1);}
 else{LA21_LOG(153);la21_d2c658.add4729d0(482,1,"",-1);}
 la21_cefc4c->attack735720(self,f,false);la21_cefc4c->hit7358c0(self,f);
 if(player5c7600()){if(la21_cf4700)track5db180(f);la21_d2c658.add4729d0(483,1,"",-1);la21_cefaa8->show793450(65,true,0,false,false);}
 int list=momentum;if(f.get9b6570()->momentum){if(direction_==la21_b96328[f.get9b6570()->direction])list+=f.get9b6570()->momentum;else list-=f.get9b6570()->momentum;}
 la21_clamp(1,list,3);if(item5d2380(84).valid9b7230()&&!state45a780())list++;list+=bonus5d2090(107);momentum=0;
 bool x;int a=rng.rangeInt(0.f,(float)la21_min(100,(int)(((mass5c8cb0()+10)/5+1)*(power5d1d70()/100.0)*list)));
 int other=!p&&type!=12?a/2:0;
 if(player5c7600()){la21_d2c658.add4729d0(433,a,"",-1);la21_d2c658.add4729d0(438,a,"",-1);la21_d2c658.add4729d0(480,other,"",-1);if(f.get9b6570()->important5c8020()){la21_d2c658.adjust472b90(106,(int)(a*la21_b949a8[f.get9b6570()->def->value]));if(la21_d2c658.values->at9b81f0(106)<=-1000)la21_cf45d8.achieve77fbc0(202);}}
 alert639ec0(f,false);clear63a0d0();x=hostile45aa70(f);bool active=player5c7600()&&rng.chance(50)&&la21_d25740<15&&!status5cba50();
 if(h)f.get9b6570()->fieldb4-=20;else f.get9b6570()->fieldb4+=n==1||n==0?-3:3;
 f.get9b6570()->damage5e5520(7,0,0,a,4,0,0,false,self,active?1:0,direction_,0,0,false);LA21H count=self;
 if(other)damage5e5520(7,0,0,la21_max(1,other),4,0,0,false,LA21H(),0,8,0,0,false);
 if(h){la21_sound4541b0(175,0,0);la21_sound4541b0(176,0,0);}else{la21_sound4541b0(173,0,0);la21_sound4541b0(174,0,0);}
 if(!integrity)return type;
 if(player5c7600()&&!h&&type!=12&&!f.get9b6570()&&x)la21_cf45d8.achieve77fbc0(43);
 if(!p&&type!=12&&rng.chance(20)){hit600e30();if(!integrity)return type;}
 if(h&&f.get9b6570()){LA21Fx*part;la21_lookup9d7980("Robot_Crushed",part);la21_cefc50->alloc508610()->init503b20(la21_cefc50,part,position,la21_d2e20c,0,0,0,9,0);f.get9b6570()->die633790(false,4,self,7,0,0,0,false);}
 LA21P label(positions.at9e7c10(0));
 if((*la21_cfd44c.at9ced70(position))->entity45d250().null9b65d0())move5ddac0(position,true);
 else if(f.get9b6570()&&f.get9b6570()->size45a360()==1&&(type==12?i:rng.chance(80))){
  LA21Ps list;list.push9b32e0(LA21P(position).subtract409a30(la21_d015d8[la21_b962e8[direction_]]));list.push9b32e0(LA21P(position).subtract409a30(la21_d015d8[direction_]));list.push9b32e0(LA21P(position).subtract409a30(la21_d015d8[la21_b96308[direction_]]));
  for(int i=list.size9b9a50()-1;i>=0;i--)if(!f.get9b6570()->allowed5c84f0(list.at9e7c10(i))||f.get9b6570()->blocked5c8710(list.at9e7c10(i))||f.get9b6570()->other5c85a0(list.at9e7c10(i),false))la21_erase(list,i);
  if(!list.empty9b86e0()){LA21P p=la21_random(list);f.get9b6570()->move5ddac0(p,true);f.get9b6570()->set45b090(0);f.get9b6570()->clear45b0b0();move5ddac0(position,true);}else swap5dd8a0(f);
 }
 if(f.get9b6570()&&f.get9b6570()->ai45b590())f.get9b6570()->ai45b590()->alert5b39b0(self);
 if(positions.at9e7c10(0).unequal409bd0(label)&&(!group.get9b7250()->faction9b4350()||la21_cefc4c->companion463510(self)||la21_cefc4c->follower4635c0(self))){la21_cefc4c->move72e4c0(self,true);if(player5c7600()&&la21_d28e27)la21_cec054->move8069e0(positions.at9e7c10(0),false);}
 if(f.get9b6570()&&f.get9b6570()->group45a3f0().get9b7250()->faction9b4350()){
  if(la21_cf462c==11&&rng.chance(la21_ba7ec0[la21_cf4718])){int p=la21_cf45d8.add77eca0(la21_d2f17c.random40c130());if(p>0)la21_cefc4c->spawn71e7c0(pos45a4a0(),p,true);}
  else{drop5e2b00(la21_d28fd0.random40c130(),pos45a4a0());la21_cf45d8.achieve77fbc0(15);}
 }
 la21_d1f3d4=la21_d32468;la21_d1f3f0=a;
 if(f.get9b6570()&&f.get9b6570()->effects){
  if(la21_effect4569a0(14,f,LA21H(),LA21HP(),LA21HI(),0,string("ram"),f.get9b6570()->effects,f,LA21HP(),LA21HI(),0)&&(!count.get9b6570()||!f.get9b6570()))return type;
  if(la21_effect4569a0(15,f,LA21H(),LA21HP(),LA21HI(),0,string("ram"),f.get9b6570()->effects,f,LA21HP(),LA21HI(),0)&&(!count.get9b6570()||!f.get9b6570()))return type;
 }
 if(!update5fdd30())return type;if(f.get9b6570())f.get9b6570()->update5fdd30();return type;
}
