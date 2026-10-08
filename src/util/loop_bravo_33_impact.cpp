#include <string>
#include "rng.h"
using std::string;
extern RNG rng;
// NOTE: borrowed partial impact/definition/entity views; native local strings own all text buffers.
struct LB33P{int x,y;int random40c130()throw();};
struct LB33Entity;struct LB33H{int id;LB33H()throw();bool null9b65d0()const throw();LB33Entity*get9b6570()const throw();bool equal9b78e0(LB33H)const throw();};
struct LB33EntityDef;struct LB33Weapon;struct LB33Explosion;struct LB33Records;
struct LB33Entity{bool player5c7600()throw();const string&text416f40()throw();const string&name45a280()throw();LB33EntityDef*def9b4350()throw();bool resist5e2e60(int*,int);int damage5e5520(int,LB33Weapon*,LB33Explosion*,int,int,int,int,bool,LB33H,int,int,int,int,bool);void die633790(bool,int,LB33H,int,int,LB33Explosion*,LB33Records*,bool);};
struct LB33Terrain{char undecoded[0x20];string name;};struct LB33Machine{char undecoded[0x20];string name;char omitted3c[0x15c-0x3c];int flag;};struct LB33ItemDef{string name55eb20(int,int);};
struct LB33Impact{int kind;LB33Terrain*terrain;LB33Machine*machine;LB33H entity;LB33ItemDef*item;char omitted14[0xa];unsigned char pulled;};
struct LB33Cell{LB33H entity45d250()throw();};template<class T>struct LB33Grid{int width,height;T*data;LB33Grid();~LB33Grid();T*at9ced70(LB33P&)throw();};extern LB33Grid<LB33Cell*>lb33_cfd44c;
struct LB33World{bool visible4631f0(LB33H);void impact749ee0(LB33H,LB33Impact*,LB33P&,bool);};extern LB33World*lb33_cefc4c;
struct LB33UI{void bubble8758d0(bool);void end7b4f10();};extern LB33UI*lb33_cec058,*lb33_cec0b4;
struct LB33Say{bool say672f20(LB33H,int,bool,string);};extern LB33Say*lb33_cf68f0;
extern int lb33_ce9fe0,lb33_cf68b4;extern void*lb33_cefb64;extern LB33H lb33_cf68b8;extern LB33P lb33_d2a7c8,lb33_d2ed3c,lb33_cf2000,lb33_cf11cc,lb33_d38424;
bool lb33_msg5111e0(int,const string*,const string*,const string*,LB33H,LB33H,const LB33P*,bool);
#define LB33_MSG(text) do{if(lb33_msg5111e0(800,&text,0,0,LB33H(),LB33H(),0,false))lb33_cec058->bubble8758d0(true);lb33_cec0b4->end7b4f10();}while(false)
void LB33World::impact749ee0(LB33H attacker,LB33Impact*impact,LB33P&pos,bool visible){
 LB33H target=lb33_cfd44c.at9ced70(pos)[0]->entity45d250();if(target.null9b65d0())return;lb33_ce9fe0=impact->kind;
 switch(impact->kind){
 case 0:{
  if(lb33_cefc4c->visible4631f0(target)){string text;if(target.get9b6570()->player5c7600())text="Smashed by "+impact->terrain->name+".";else text=impact->terrain->name+" smashes into "+target.get9b6570()->text416f40()+".";LB33_MSG(text);}
  lb33_cefb64=impact->terrain;
terrainDamage:
  int damage=lb33_d2a7c8.random40c130();if(target.get9b6570()->resist5e2e60(&damage,4))target.get9b6570()->damage5e5520(12,0,0,damage,4,0,0,visible,attacker,0,8,0,0,false);break;
 }
 case 1:{
  if(lb33_cefc4c->visible4631f0(target)){string text;if(target.get9b6570()->player5c7600())text="Smashed by "+impact->machine->name+".";else text=impact->machine->name+" smashes into "+target.get9b6570()->text416f40()+".";LB33_MSG(text);}
  lb33_cefb64=impact->machine;if(!impact->machine->flag)goto terrainDamage;
  int damage=lb33_d2ed3c.random40c130();if(target.get9b6570()->resist5e2e60(&damage,0))target.get9b6570()->damage5e5520(12,0,0,damage,0,0,0,visible,attacker,0,8,0,0,false);
  if(target.get9b6570()){damage=lb33_cf2000.random40c130();if(target.get9b6570()->resist5e2e60(&damage,3))target.get9b6570()->damage5e5520(12,0,0,damage,3,0,0,visible,attacker,0,8,0,0,false);}break;
 }
 case 2:{
  if(!impact->entity.get9b6570())return;
  if(lb33_cefc4c->visible4631f0(target)){string text;
   if(impact->pulled){if(target.get9b6570()->player5c7600())text="Pulled "+impact->entity.get9b6570()->text416f40()+" to self.";else if(impact->entity.get9b6570()->player5c7600()){if(lb33_cf68b4&&attacker.get9b6570()&&lb33_cf68b8.equal9b78e0(attacker))lb33_cf68f0->say672f20(attacker,9,false,"");text="Pulled to "+target.get9b6570()->text416f40()+".";}else text=impact->entity.get9b6570()->text416f40()+" pulled to "+target.get9b6570()->text416f40()+".";}
   else{if(target.get9b6570()->player5c7600())text="Smashed by "+impact->entity.get9b6570()->text416f40()+".";else if(impact->entity.get9b6570()->player5c7600())text="Smashed into "+target.get9b6570()->text416f40()+".";else text=impact->entity.get9b6570()->text416f40()+" smashes into "+target.get9b6570()->text416f40()+".";}
   LB33_MSG(text);if(impact->pulled)break;
  }
  lb33_cefb64=impact->entity.get9b6570()->def9b4350();bool player=impact->entity.get9b6570()->player5c7600();int damage=lb33_cf11cc.random40c130();if(target.get9b6570()->resist5e2e60(&damage,4))target.get9b6570()->damage5e5520(12,0,0,damage,4,0,0,visible,attacker,0,8,0,0,false);
  if(impact->entity.get9b6570()){if(attacker.equal9b78e0(lb33_cf68b8)&&impact->entity.get9b6570()->name45a280()=="Stormtrooper"&&rng.chance(50))impact->entity.get9b6570()->die633790(visible,4,attacker,12,0,0,0,false);else{if(player)lb33_cefb64=0;int half=damage/2;if(impact->entity.get9b6570()->resist5e2e60(&half,4))impact->entity.get9b6570()->damage5e5520(12,0,0,half,4,0,0,visible,attacker,0,8,0,0,false);}}break;
 }
 case 3:{
  if(lb33_cefc4c->visible4631f0(target)){string text;if(target.get9b6570()->player5c7600())text="Smashed by "+impact->item->name55eb20(0,0)+".";else text=impact->item->name55eb20(0,0)+" smashes into "+target.get9b6570()->text416f40()+".";LB33_MSG(text);}
  lb33_cefb64=impact->item;int damage=lb33_d38424.random40c130();if(target.get9b6570()->resist5e2e60(&damage,0))target.get9b6570()->damage5e5520(12,0,0,damage,0,0,0,visible,attacker,0,8,0,0,false);break;
 }
 }
}
