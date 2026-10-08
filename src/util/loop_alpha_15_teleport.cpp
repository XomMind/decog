#include <string>
#include "rng.h"
using std::string;extern RNG rng;
struct LA15Point{int x,y;LA15Point() throw();LA15Point(int,int) throw();LA15Point(const LA15Point&) throw();bool contains40c190(int) throw();LA15Point&set40a010(int,int) throw();LA15Point&add409a30(const LA15Point&) throw();LA15Point&add40a2a0(int,int) throw();bool different409bd0(const LA15Point&)const throw();};
struct LA15Area{int left,top,right,bottom;LA15Area() throw();void random40be30(LA15Point*) throw();};
struct LA15Entity;struct LA15AI;
struct LA15H{int id;LA15H() throw();LA15Entity*get9b6570()const throw();bool valid9b7230()const throw();};struct LA15HP{int id;LA15HP() throw();};
struct LA15AI{bool seen458f10() throw();void alert459520(const LA15Point&) throw();int mode9b8f00() throw();void target4593b0(const LA15Point&) throw();};
struct LA15Entity{char pad0[4];LA15H self;const LA15Point&pos45a4a0() throw();bool hostile45aa70(LA15H) throw();bool xom5d51a0() throw();LA15AI*ai45b590() throw();void move5ddac0(const LA15Point&,bool) throw();bool teleport63b5a0(int,int);};
struct LA15Cell{bool place66ad20(int) throw();LA15H entity45d250() throw();};struct LA15Grid{void rect9b4430(const LA15Point&,int,LA15Area*) throw();LA15Cell**at9ced70(LA15Point&) throw();LA15Cell**at9ceda0(int,int) throw();};extern LA15Grid la15_cfd44c;
struct LA15Xom{bool enabled;void update69ec90() throw();void event69ecb0(int) throw();};extern LA15Xom la15_d25450;
struct LA15Phrase{char pad[0x28];LA15Phrase(int,const string*,const string*,const string*,LA15H,LA15HP);};struct LA15Log{int push5121f0(LA15Phrase*) throw();};extern LA15Log la15_cf1080;
struct LA15TextLog{void end7b4f10() throw();};extern LA15TextLog*la15_cec0b4;struct LA15UI{void update8758d0(bool) throw();};extern LA15UI*la15_cec058;
struct LA15Map{void update71cf70() throw();void motion734560(LA15H,int,int) throw();LA15H special463110() throw();};extern LA15Map*la15_cefc4c;
struct LA15View{void refresh49ad30() throw();void delay49adc0(int) throw();const LA15Point&offset458ef0() throw();bool bounds4173d0(const LA15Point&) throw();};extern LA15View*la15_cec054;
struct LA15Stats{bool add4729d0(unsigned,int,string,int) throw();};extern LA15Stats la15_d2c658;struct LA15Player{void event77fbc0(int) throw();};extern LA15Player la15_cf45d8;extern int la15_cf4d68,la15_cf4a90,la15_cf4a94;
struct LA15Record;struct LA15Owner;struct LA15Effect{bool init50de10(LA15Owner*,LA15Record*,const LA15Point&,const LA15Point&,const LA15Point*,const LA15Point*,int);};struct LA15Owner{LA15Effect*new50fb50() throw();};extern LA15Owner*la15_cefc64;extern LA15Point la15_cfbec0;
struct LA15Points{int a,b,c,d;LA15Points();~LA15Points();unsigned size9b9a50()const throw();LA15Point&at9e7c10(unsigned) throw();LA15Point&back9e8c10() throw();void push9b32e0(const LA15Point&);};
bool la15_lookup9d45a0(const string&,LA15Record**);void la15_line40ff30(const LA15Point&,const LA15Point&,LA15Points&);bool la15_contains9d0ce0(LA15Points&,LA15Point) throw();
int la15_distance40a3f0(const LA15Point&,const LA15Point&) throw();float la15_angle40a680(const LA15Point&,const LA15Point&) throw();bool la15_arc4065d0(int,int,int) throw();int la15_clamp9d06d0(int*,int,int) throw();int la15_distance406480(int,int,int,int) throw();int la15_sound4541b0(unsigned,int,int) throw();
bool LA15Entity::teleport63b5a0(int minimum,int maximum){
 LA15Point distance(minimum,maximum);LA15Point enemy(pos45a4a0());LA15Area area;la15_cfd44c.rect9b4430(enemy,distance.y,&area);LA15Point x;
 bool first=false;int turn=la15_cf4a90;bool seen=false;
 retry:
  for(int i=0;i<4000;i++){
   area.random40be30(&x);
   if(distance.contains40c190(la15_distance40a3f0(enemy,x))&&(*la15_cfd44c.at9ced70(x))->place66ad20(1)&&la15_arc4065d0(la15_cf4a94,la15_cf4a90,(int)la15_angle40a680(enemy,x))){first=true;break;}
  }
  if(!first){if(turn<360){la15_clamp9d06d0(&turn,45,360);goto retry;}if(seen)return false;else{distance.x=1;seen=true;goto retry;}}
 if(la15_d25450.enabled)la15_d25450.update69ec90();
 do{if(la15_cf1080.push5121f0(new LA15Phrase(0x114,0,0,0,LA15H(),LA15HP())))la15_cec058->update8758d0(true);la15_cec0b4->end7b4f10();}while(false);
 move5ddac0(x,true);if(la15_d25450.enabled)la15_d25450.event69ecb0(59);
 la15_cefc4c->update71cf70();la15_cefc4c->motion734560(self,-2,0);if(la15_cefc4c->special463110().valid9b7230())la15_cefc4c->motion734560(la15_cefc4c->special463110(),-2,0);
 la15_d2c658.add4729d0(0x3fe,1,"",-1);la15_cf45d8.event77fbc0(134);la15_cf4d68++;if(la15_cf4d68==3)la15_cf45d8.event77fbc0(226);
 la15_cec054->refresh49ad30();la15_cec054->delay49adc0(1000);
 LA15Point location(pos45a4a0());int radius=15;LA15Area a2;la15_cfd44c.rect9b4430(location,radius,&a2);
 for(int i=a2.left;i<=a2.right;i++)for(int j=a2.top;j<=a2.bottom;j++){
  if((*la15_cfd44c.at9ceda0(i,j))->entity45d250().valid9b7230()&&(*la15_cfd44c.at9ceda0(i,j))->entity45d250().get9b6570()->hostile45aa70(self)&&(*la15_cfd44c.at9ceda0(i,j))->entity45d250().get9b6570()->xom5d51a0()&&la15_distance406480(location.x,location.y,i,j)<=radius&&(*la15_cfd44c.at9ceda0(i,j))->entity45d250().get9b6570()->ai45b590()->seen458f10()){
   (*la15_cfd44c.at9ceda0(i,j))->entity45d250().get9b6570()->ai45b590()->alert459520(location);
   if((*la15_cfd44c.at9ceda0(i,j))->entity45d250().get9b6570()->ai45b590()->mode9b8f00()==1)(*la15_cfd44c.at9ceda0(i,j))->entity45d250().get9b6570()->ai45b590()->target4593b0(location);
  }
 }
 LA15Record*s=0;la15_lookup9d45a0("Teleport_Nav_Harness",&s);
 if(s){LA15Point p;for(int i=a2.left;i<=a2.right;i++)for(int j=a2.top;j<=a2.bottom;j++){
  if(la15_distance406480(location.x,location.y,i,j)<=radius){p.set40a010(i,j);p.add409a30(la15_cec054->offset458ef0());if(la15_cec054->bounds4173d0(p))la15_cefc64->new50fb50()->init50de10(la15_cefc64,s,p,la15_cfbec0,0,0,9);}
 }}
 LA15Record*link=0;la15_lookup9d45a0("Teleport_Nav_Harn_Point",&link);
 LA15Points other;la15_line40ff30(enemy,x,other);LA15Points vec;
 {unsigned i=0;int count=0;
 for(;i<other.size9b9a50();i++){
  count++;if(count==5||(count>2&&rng.chance(33))){count=0;vec.push9b32e0(other.at9e7c10(i));vec.back9e8c10().add40a2a0(rng.rangeInt(-2,2),rng.rangeInt(-2,2));vec.back9e8c10().add409a30(la15_cec054->offset458ef0());if(la15_cec054->bounds4173d0(vec.back9e8c10()))la15_cefc64->new50fb50()->init50de10(la15_cefc64,link,vec.back9e8c10(),la15_cfbec0,0,0,9);}
 }
 }
 la15_lookup9d45a0("Teleport_Nav_Harn_Path",&link);LA15Points vec2;
 for(unsigned j=1;j<vec.size9b9a50();j++)if(vec.at9e7c10(j-1).different409bd0(vec.at9e7c10(j)))la15_line40ff30(vec.at9e7c10(j-1),vec.at9e7c10(j),vec2);
 for(unsigned j=0;j<vec2.size9b9a50();j++)if(!la15_contains9d0ce0(vec,vec2.at9e7c10(j))&&la15_cec054->bounds4173d0(vec2.at9e7c10(j)))la15_cefc64->new50fb50()->init50de10(la15_cefc64,link,vec2.at9e7c10(j),la15_cfbec0,0,0,9);
 la15_sound4541b0(0x108,0,0);return true;
}
