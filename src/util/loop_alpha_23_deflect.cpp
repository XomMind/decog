#include <string>
#include <cstdlib>
#include "rng.h"
using std::string;extern RNG rng;
// NOTE: private names and partial layouts; all collection backing stores are actual retail owners.
// Two literal true gates reproduce explicit retail constant conditions at+3cd and+494; no invented code or storage.
struct LA23P{int x,y;LA23P(int,int)throw();LA23P(const LA23P&)throw();bool unequal409bd0(const LA23P&)const throw();LA23P&copy46ca50(const LA23P&)throw();};
struct LA23Area{LA23P min,max;LA23Area()throw();LA23P random40be90()throw();};struct LA23Range{float low,high;LA23Range&set40c490(float,float)throw();bool contains40c730(float)throw();};
struct LA23Entity;struct LA23Item;struct LA23H{int id;LA23H()throw();LA23Entity*get9b6570()const throw();bool valid9b7230()const throw();};struct LA23HI{int id;LA23HI()throw();LA23Item*get9b65b0()const throw();bool null9b65d0()const throw();bool valid9b7230()const throw();};struct LA23HP{int id;LA23HP()throw();struct LA23Prop*get9b64f0()const throw();};
struct LA23Items{int a,b,c,d;LA23Items();~LA23Items();unsigned size9b9260()const throw();LA23HI&at9b81f0(unsigned)throw();bool empty9b86e0()const throw();void push9b80b0(const LA23HI&);};
struct LA23Ps{int a,b,c,d;LA23Ps();~LA23Ps();unsigned size9b9a50()const throw();LA23P&at9e7c10(unsigned)throw();bool empty9b86e0()const throw();void pushPoint(LA23P&&);};
struct LA23Def{char p0[0xec];int property;char pf0[0xa4];struct LA23Fx*fx;};struct LA23Item{bool available457cf0()throw();int special457f90()throw();int capacity457fb0()throw();int effect457be0(int)throw();void*record457b70(int)throw();LA23Def*def9b4350()throw();int state577fb0()throw();int category457880()throw();int type44aec0()throw();bool enabled457d70()throw();int shield577790()throw();string name571db0(bool,bool);int integrity9b6bf0()throw();void integrity450460(int)throw();void remove57dbe0(bool,bool,int,bool);const string&name457860()throw();};
struct LA23Projectile{char p0[0x170];int kind;};
struct LA23Entity{int p0;LA23H self;char p8[0x28];LA23Ps positions;char p40[0xf4];LA23Items items;bool deflect637f00(LA23Projectile*,const LA23P&,const LA23P&,LA23P&);bool shield5ced30()throw();LA23HI item5d2380(int)throw();int movement5cad50()throw();int size5ccab0()throw();bool player5c7600()throw();bool hostile45aa70(LA23H)throw();const LA23P&pos45a4a0()throw();const string&name416f40()throw();};
struct LA23Link{char p0[0x14];int integrity;bool valid65cf80()throw();};struct LA23Prop{LA23Link*link44b020()throw();};
struct LA23Cell{LA23H entity45d250()throw();LA23HP prop45d550()throw();bool has45dd40(int)throw();void remove66c100(bool,int);};struct LA23Grid{LA23Cell**at9ceda0(int,int)throw();LA23Cell**at9ced70(LA23P&)throw();void rect9b4430(const LA23P&,int,LA23Area*)throw();};extern LA23Grid la23_cfd44c;
struct LA23Map{bool line465200(const LA23P&,const LA23P&)throw();bool visible4631c0(const LA23P&)throw();};extern LA23Map*la23_cefc4c;
struct LA23Owned;struct LA23Effects;struct LA23Effect{void init503b20(LA23Effects*,LA23Fx*,const LA23P&,const LA23P&,const LA23P*,const LA23P*,LA23Owned*,int,LA23Effect*)throw();};struct LA23Effects{LA23Effect*alloc508610()throw();};extern LA23Effects*la23_cefc50;extern LA23P la23_d2e20c;
struct LA23UI{void update8758d0(bool);};extern LA23UI*la23_cec058;struct LA23Log{void end7b4f10()throw();};extern LA23Log*la23_cec0b4,*la23_cec0c4;
struct LA23Part{void draw4a8e70(bool);};struct LA23Parts{LA23Part*part894e70(LA23HI);};extern LA23Parts*la23_cec088;
struct LA23Player{void achieve77fbc0(int);bool companion780790()throw();};extern LA23Player la23_cf45d8;struct LA23Stats{bool add4729d0(unsigned,int,string,int);};extern LA23Stats la23_d2c658;
struct LA23Tracker{bool spawn7aa280(int,bool,string);};struct LA23State{char p0[0x30];LA23Tracker*tracker;};extern LA23State*la23_cf4ac8;
extern int la23_bbca60[],la23_cefb38,la23_d28d18;extern unsigned la23_c2ea48;
LA23HI la23_randomItem(LA23Items&);LA23P la23_randomPoint(LA23Ps&);bool la23_between(int,int,int)throw();void la23_maxAssign(int*,int)throw();int la23_distance40a3f0(const LA23P&,const LA23P&)throw();float la23_angle40a680(const LA23P&,const LA23P&)throw();void la23_erase(LA23Ps&,int)throw();void la23_error(string,string);
bool la23_route5111e0(int,const string*,const string*,const string*,LA23H,LA23H,const LA23P*,bool);
#define LA23_MSG_false(ID,TEXT,OTHER,E,POS) do{if(la23_route5111e0(ID,TEXT,OTHER,0,E,LA23H(),POS,false))la23_cec058->update8758d0(true);la23_cec0b4->end7b4f10();}while(false)
#define LA23_MSG_true(ID,TEXT,OTHER,E,POS) do{if(la23_route5111e0(ID,TEXT,OTHER,0,E,LA23H(),POS,true))la23_cec058->update8758d0(false);la23_cec0c4->end7b4f10();}while(false)
#define LA23_MSG(ID,TEXT,OTHER,E,POS,BUFFER) LA23_MSG_##BUFFER(ID,TEXT,OTHER,E,POS)
bool LA23Entity::deflect637f00(LA23Projectile*projectile,const LA23P&from,const LA23P&position,LA23P&destination){
 if(!projectile->kind)return false;
 LA23HI a;int first=0;LA23Items type;LA23Items h;int mode=0;
 for(unsigned n=0;n<items.size9b9260();n++){
  if(items.at9b81f0(n).get9b65b0()->available457cf0()){
   if((items.at9b81f0(n).get9b65b0()->special457f90()==73||(items.at9b81f0(n).get9b65b0()->special457f90()==214&&items.at9b81f0(n).get9b65b0()->capacity457fb0()>0))&&(abs(items.at9b81f0(n).get9b65b0()->effect457be0(111))==4||abs(items.at9b81f0(n).get9b65b0()->effect457be0(111))==projectile->kind)&&(a.null9b65d0()||(items.at9b81f0(n).get9b65b0()->special457f90()==73?items.at9b81f0(n).get9b65b0()->capacity457fb0():la23_bbca60[items.at9b81f0(n).get9b65b0()->capacity457fb0()])>first)){
    if(!items.at9b81f0(n).get9b65b0()->record457b70(113)||(shield5ced30()&&item5d2380(116).null9b65d0())){
     a=items.at9b81f0(n);first=a.get9b65b0()->special457f90()==73?a.get9b65b0()->capacity457fb0():la23_bbca60[items.at9b81f0(n).get9b65b0()->capacity457fb0()];
    }
   }
   if(items.at9b81f0(n).get9b65b0()->def9b4350()->property==4&&items.at9b81f0(n).get9b65b0()->state577fb0()==2&&true)type.push9b80b0(items.at9b81f0(n));
  }
  if(la23_between(26,items.at9b81f0(n).get9b65b0()->category457880(),28)&&items.at9b81f0(n).get9b65b0()->type44aec0()!=4&&items.at9b81f0(n).get9b65b0()->enabled457d70()&&true){if(!h.empty9b86e0()||(movement5cad50()==2&&la23_cefb38==3)||item5d2380(92).valid9b7230())h.push9b80b0(items.at9b81f0(n));}
 }
 if(!type.empty9b86e0()){
  int h=0;for(unsigned i=0;i<type.size9b9260();i++)h+=type.at9b81f0(i).get9b65b0()->shield577790();int p=(int)((double)h/size5ccab0()*50.0);if(p>first){first=p;a=la23_randomItem(type);mode=1;}
 }
 if(!h.empty9b86e0()){
  int p=10;for(int n=h.size9b9260()-1,x=5;n!=0;n--,x/=2){la23_maxAssign(&x,2);p+=x;}
  if(p>first){first=p;a=la23_randomItem(h);mode=2;}
 }
 if(a.valid9b7230()&&rng.chance(first)){
  int id,h,x,n;
  switch(mode){case 0:x=a.get9b65b0()->effect457be0(112);h=a.get9b65b0()->effect457be0(111);break;case 1:x=-90;h=4;break;case 2:x=120;h=4;break;}
  if(x==-1){destination.copy46ca50(from);id=player5c7600()?413:412;n=728;}
  else{
   float first;float count;int a=abs(x);float type=x>0?la23_angle40a680(position,from):la23_angle40a680(from,position);LA23Range f;f.set40c490(type-a/2,type+a/2);count=0;
   if(f.low<0.0)count=-f.low;else if(f.high>360.0)count=360.0-f.high;if(count!=0){f.low+=count;f.high+=count;}
   LA23Area mode;la23_cfd44c.rect9b4430(position,12,&mode);
   if(h<0){
    LA23Ps p;
    for(int x=mode.min.x;x<=mode.max.x;x++)for(int y=mode.min.y;y<=mode.max.y;y++)if((*la23_cfd44c.at9ceda0(x,y))->entity45d250().valid9b7230()&&(*la23_cfd44c.at9ceda0(x,y))->entity45d250().get9b6570()->hostile45aa70(self)&&la23_distance40a3f0(pos45a4a0(),LA23P(x,y))<=12&&la23_cefc4c->line465200(pos45a4a0(),LA23P(x,y)))p.pushPoint(LA23P(x,y));
    if(a<360)for(int i=p.size9b9a50()-1;i>=0;i--){first=la23_angle40a680(position,p.at9e7c10(i))+count;if(first<0.0)first+=360.0;else if(first>360.0)first-=360.0;if(!f.contains40c730(first))la23_erase(p,i);}
    if(!p.empty9b86e0()){destination.copy46ca50(la23_randomPoint(p));id=player5c7600()?411:410;n=727;goto deflected;}
   }
   id=player5c7600()?408:407;n=726;
   for(int i=0;;i++){
    destination.copy46ca50(mode.random40be90());
    if(destination.unequal409bd0(position)){first=la23_angle40a680(position,destination)+count;if(first<0.0)first+=360.0;else if(first>360.0)first-=360.0;if(f.contains40c730(first))break;}
    if(i==1000){la23_error("Entity::deflectProjectile()","failed");return false;}
   }
  }
  deflected:
  if(a.get9b65b0()->record457b70(113))for(unsigned i=0;i<positions.size9b9a50();i++)if((*la23_cfd44c.at9ced70(positions.at9e7c10(i)))->has45dd40(11)&&(*la23_cfd44c.at9ced70(positions.at9e7c10(i)))->prop45d550().get9b64f0()->link44b020()->valid65cf80()){
   (*la23_cfd44c.at9ced70(positions.at9e7c10(i)))->prop45d550().get9b64f0()->link44b020()->integrity-=a.get9b65b0()->effect457be0(113);
   if((*la23_cfd44c.at9ced70(positions.at9e7c10(i)))->prop45d550().get9b64f0()->link44b020()->integrity<1){LA23_MSG(548,0,0,LA23H(),&positions.at9e7c10(i),false);(*la23_cfd44c.at9ced70(positions.at9e7c10(i)))->remove66c100(false,3);}break;
  }
  if(la23_cefc4c->visible4631c0(position)&&a.get9b65b0()->def9b4350()->fx)la23_cefc50->alloc508610()->init503b20(la23_cefc50,a.get9b65b0()->def9b4350()->fx,position,la23_d2e20c,0,0,0,9,0);
  LA23_MSG(id,&a.get9b65b0()->name571db0(false,false),&name416f40(),LA23H(),&position,false);
  if(la23_d28d18>=0){LA23_MSG(n,&a.get9b65b0()->name571db0(false,false),0,LA23H(),&position,true);}
  if(mode==2&&rng.chance(50)){
   if(a.get9b65b0()->integrity9b6bf0()==1){if(player5c7600()){LA23_MSG(409,&a.get9b65b0()->name571db0(false,false),0,self,0,false);}a.get9b65b0()->remove57dbe0(true,true,1,true);}
   else{a.get9b65b0()->integrity450460(a.get9b65b0()->integrity9b6bf0()-1);if(player5c7600()){LA23Part*p=la23_cec088->part894e70(a);if(p)p->draw4a8e70(true);}}
  }
  if(player5c7600()){la23_d2c658.add4729d0(360,1,"",-1);la23_cf45d8.achieve77fbc0(56);if(a.get9b65b0()&&a.get9b65b0()->name457860().find("Companion",0)!=la23_c2ea48&&la23_cf45d8.companion780790())la23_cf4ac8->tracker->spawn7aa280(20,false,"");}
  return true;
 }else{return false;}
}
