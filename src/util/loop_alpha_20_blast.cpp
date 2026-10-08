#include <string>
#include "rng.h"
using std::string;extern RNG rng;
// NOTE: private placeholder names and partial layouts, real pointer/handle ownership.
struct LA20P {int x,y;LA20P()throw();LA20P(int)throw();LA20P(const LA20P&)throw();void copy46ca50(const LA20P&)throw();bool equal409b90(const LA20P&)throw();bool unequal409bd0(const LA20P&)const throw();LA20P&sum40a090(const LA20P&,const LA20P&)throw();int random40c130()throw();};
struct LA20Entity;struct LA20Item;struct LA20Prop;struct LA20Explosion;
struct LA20H {int id;LA20H()throw();LA20Entity*get9b6570()const throw();bool valid9b7230()const throw();bool equal9b78e0(LA20H)const throw();};
struct LA20HP {int id;LA20HP()throw();LA20Prop*get9b64f0()const throw();bool valid9b7230()const throw();bool null9b65d0()const throw();};
struct LA20HI {int id;LA20HI()throw();LA20Item*get9b65b0()const throw();bool valid9b7230()const throw();};
struct LA20Items{int a,b,c,d;LA20Items(const LA20Items&);~LA20Items();unsigned size9b9260()const throw();bool empty9b86e0()const throw();LA20HI&at9b81f0(unsigned)throw();LA20HI&front9b7060()throw();};
struct LA20Recs{int a,b,c,d;LA20Recs(const LA20Recs&);~LA20Recs();bool empty9b86e0()const throw();};struct LA20Effects{char data[20];LA20Effects(LA20Recs);~LA20Effects();};
struct LA20Ps{int a,b,c,d;LA20Ps(unsigned,const LA20P&);LA20Ps(const LA20Ps&);~LA20Ps();};
struct LA20Resistance{char pad[0x20];int types[7];};struct LA20Terrain{char pad[0x50];LA20Resistance*resistance;};struct LA20Def{char p[0x20];string name;char p3c[0x16c];LA20Explosion*explosion;};
struct LA20Trap{bool active65cf80()throw();};struct LA20Prop{bool trap45cb70()throw();LA20Trap*state44b020()throw();const string&name45c5b0()throw();LA20Def*def9b8f00()throw();bool passable470b30()throw();void fixed45cd70(LA20H,LA20Explosion*,int,bool);};
struct LA20Item{bool damage57ab10(int,int,int,int,LA20H,int,int);bool explosive577990()throw();void charge5798b0(int)throw();void remove57dbe0(bool,bool,int,bool);void move57a0f0(const LA20P&,int,bool);LA20Def*def9b4350()throw();string name571db0(bool,bool);};
struct LA20Explosion{char p0[0x2c];int type;LA20P damage;char p38[0x14];LA20P push;bool flag54,flag55;char p56[6];int cause;int explode;char p64[4];int value68;char p6c[0x30];LA20Recs effects;};
struct LA20Entity{bool player5c7600()throw();bool hostile45aa70(LA20H)throw();void blast45b2c0(LA20H,LA20Explosion*,const LA20P&,int,bool);};
struct LA20Cell{LA20Terrain*terrain;char p4[8];int unknownc;char p10[0x20];LA20P position;char p38[8];int armor;LA20HP prop;LA20H entity;LA20Items items;bool blocking45d7b0()throw();LA20HI item45d8f0()throw();bool place45d880()throw();void remove66ce10(bool,bool,bool,bool);bool door45dda0()throw();bool destroy66dae0(int,int,bool,bool,int,bool,LA20H,int);void blast66eff0(LA20H,LA20Explosion*,int,const LA20P&,int,bool);};
struct LA20Grid{bool contains9b43b0(const LA20P&)throw();LA20Cell**at9ced70(LA20P&)throw();};extern LA20Grid la20_cfd44c;extern LA20P la20_cfd420,la20_d015d8[];int la20_cost4374c0(const LA20P&,const LA20P&)throw();
struct LA20Mode{int id,type;};struct LA20HM{int id;LA20Mode*get9b7910()const throw();};extern LA20HM la20_d1e888;
struct LA20HE{int id;LA20HE()throw();};struct LA20Expand{char data[64];LA20Expand(LA20H,LA20Explosion*,const LA20P&,LA20HE,const LA20P&,const LA20P&);};
struct LA20Factory{LA20HE create7930e0(LA20Expand*);};extern LA20Factory*la20_cefaa8;
struct LA20Map{void charge464af0(LA20HI,int);void item728f30(LA20HI);bool move71ec60(const LA20P&,LA20Ps);bool same717c60(LA20H,int);void hit732d50(LA20H,int);LA20H player4630f0()throw();LA20HE queue777a20(LA20HE);void value74b060(const LA20P&,int,int);};extern LA20Map*la20_cefc4c;
struct LA20Stats{bool add4729d0(unsigned,int,string,int);int count472c70(unsigned)throw();};extern LA20Stats la20_d2c658;struct LA20Player{void achieve77fbc0(int);};extern LA20Player la20_cf45d8;
struct LA20UI{void update8758d0(bool);};extern LA20UI*la20_cec058;struct LA20Log{void end7b4f10()throw();};extern LA20Log*la20_cec0b4,*la20_cec0c4;
extern int la20_d1f3f0,la20_d28d18,la20_b9654c[];extern LA20Terrain*caveinThirdTerrain;
bool la20_effect4569a0(int,LA20H,LA20H,LA20HP,LA20HI,const LA20P*,int,LA20Effects*,LA20H,LA20HP,LA20HI,const LA20P*);
bool la20_route5111e0(int,const string*,const string*,const string*,LA20H,LA20HP,const LA20P*,bool);
#define LA20_LOG0(ID,TEXT) do{if(la20_route5111e0(ID,TEXT,0,0,LA20H(),LA20HP(),&position,false))la20_cec058->update8758d0(true);la20_cec0b4->end7b4f10();}while(false)
#define LA20_LOG1(ID,TEXT) do{if(la20_route5111e0(ID,TEXT,0,0,LA20H(),LA20HP(),&position,true))la20_cec058->update8758d0(false);la20_cec0c4->end7b4f10();}while(false)
void LA20Cell::blast66eff0(LA20H attacker,LA20Explosion*record,int owner,const LA20P&center,int damage,bool quiet){
 if(record->flag55)unknownc=-1;
 if(!items.empty9b86e0()){
  if(!record->effects.empty9b86e0()){
   LA20Items p(items);for(unsigned i=0;i<p.size9b9260();i++)if(p.at9b81f0(i).get9b65b0()){
    LA20Effects*type=new LA20Effects(record->effects);la20_effect4569a0(28,attacker,LA20H(),LA20HP(),p.at9b81f0(i),0,0,type,LA20H(),LA20HP(),p.at9b81f0(i),0);delete type;
   }
  }
  if(record->type!=9){int value=rng.rangeInt(0.f,(float)(record->type==3?damage/2:damage));if(value>0){LA20Items p(items);for(unsigned i=0;i<p.size9b9260();i++){
   if(p.at9b81f0(i).get9b65b0())p.at9b81f0(i).get9b65b0()->damage57ab10(value,record->type,record->cause,0,attacker,1,0);
   if(record->type==3&&p.at9b81f0(i).get9b65b0()){
    la20_cefc4c->charge464af0(p.at9b81f0(i),value);if(p.at9b81f0(i).get9b65b0()->explosive577990())p.at9b81f0(i).get9b65b0()->charge5798b0(damage/4);
    if(la20_d1e888.get9b7910()->type==15)la20_cefc4c->item728f30(p.at9b81f0(i));
   }
  }}}
  if(record->push.y&&!items.empty9b86e0()){
   int value=record->push.random40c130()+2;if(value>0){
    LA20P p;if(center.unequal409bd0(position))p.copy46ca50(center);else if(la20_cfd420.x!=-1&&la20_cfd420.unequal409bd0(position))p.copy46ca50(la20_cfd420);else goto pushDone;
    int direction=la20_cost4374c0(p,position);LA20P x(position);LA20P y;
    for(int i=value;i>0;i--){y.sum40a090(x,la20_d015d8[direction]);if(!la20_cfd44c.contains9b43b0(y))break;
     if(i==1&&((*la20_cfd44c.at9ced70(y))->blocking45d7b0()||(*la20_cfd44c.at9ced70(y))->item45d8f0().valid9b7230())){x.copy46ca50(y);break;}
     if(!(*la20_cfd44c.at9ced70(y))->place45d880())break;
    }
    if(x.unequal409bd0(position)){
     if((*la20_cfd44c.at9ced70(x))->item45d8f0().valid9b7230()){LA20Ps p(1u,x);if(!la20_cefc4c->move71ec60(x,p))goto pushDone;}
     items.front9b7060().get9b65b0()->move57a0f0(x,0,false);
    }
   }
  }
 }
 pushDone:
 if(entity.valid9b7230()&&!la20_cefc4c->same717c60(entity,owner)){
  la20_cefc4c->hit732d50(entity,owner);
  if(entity.get9b6570()->player5c7600()&&attacker.get9b6570()&&attacker.get9b6570()->hostile45aa70(la20_cefc4c->player4630f0()))la20_d2c658.add4729d0(0x16c,1,"",-1);
  entity.get9b6570()->blast45b2c0(attacker,record,center,damage,quiet);
 }
 if(record->explode&&!items.empty9b86e0()){
  LA20Items p(items);for(unsigned i=0;i<p.size9b9260();i++)if(p.at9b81f0(i).get9b65b0()&&p.at9b81f0(i).get9b65b0()->def9b4350()->explosion&&rng.chance(la20_b9654c[record->explode])){
   LA20Explosion*type=p.at9b81f0(i).get9b65b0()->def9b4350()->explosion;
   do{if(la20_route5111e0(0x1a5,&p.at9b81f0(i).get9b65b0()->name571db0(false,false),0,0,LA20H(),LA20HP(),&position,false))la20_cec058->update8758d0(true);la20_cec0b4->end7b4f10();}while(false);
   if(attacker.get9b6570()&&attacker.get9b6570()->player5c7600()){la20_d2c658.add4729d0(0x209,1,"",-1);if(la20_d2c658.count472c70(0x209)>=15)la20_cf45d8.achieve77fbc0(154);}
   p.at9b81f0(i).get9b65b0()->remove57dbe0(false,false,1,true);
   la20_cefc4c->queue777a20(la20_cefaa8->create7930e0(new LA20Expand(attacker,type,position,LA20HE(),LA20P(-1),LA20P(-1))));
  }
 }
 if(prop.valid9b7230()){
  if(prop.get9b64f0()->trap45cb70()&&!prop.get9b64f0()->state44b020()->active65cf80()&&record->type==3&&rng.chance(20)){
   LA20_LOG0(0x21a,&prop.get9b64f0()->name45c5b0());
   if(la20_d28d18>=0){string text=prop.get9b64f0()->name45c5b0()+" short circuited";LA20_LOG1(0x2cf,&text);}
   remove66ce10(false,false,false,false);
   if(attacker.valid9b7230()&&attacker.equal9b78e0(la20_cefc4c->player4630f0())){la20_d2c658.add4729d0(0x249,1,"",-1);la20_d2c658.add4729d0(0x24a,1,"",-1);}
  }else prop.get9b64f0()->fixed45cd70(attacker,record,damage,quiet);
 }
 if(!record->effects.empty9b86e0()){
  la20_d1f3f0=damage;LA20Effects*type=new LA20Effects(record->effects);
  la20_effect4569a0(29,attacker,LA20H(),LA20HP(),LA20HI(),&position,0,type,LA20H(),LA20HP(),LA20HI(),&position);delete type;
 }
 if(record->type==9)return;
 if(armor!=-9999)armor-=damage;
 LA20Terrain*first=terrain;LA20Def*n=door45dda0()?prop.get9b64f0()->def9b8f00():0;
 if(prop.null9b65d0()||prop.get9b64f0()->passable470b30()||prop.get9b64f0()->trap45cb70()){
  if(destroy66dae0(damage/(terrain==caveinThirdTerrain?2:1)*(record->type>=7?100:terrain->resistance->types[record->type])/100,record->type,false,false,5,position.equal409b90(center),attacker,quiet)&&n&&la20_d28d18==1){string text="  "+n->name+" destroyed";LA20_LOG1(0x2cc,&text);}
 }
 if(record->value68)la20_cefc4c->value74b060(position,record->value68,damage*100/(record->damage.x+record->damage.y));
}
