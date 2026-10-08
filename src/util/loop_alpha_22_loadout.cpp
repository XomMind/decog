#include <string>
#include "rng.h"
using std::string;extern RNG rng;
// NOTE: private names and partial layouts reflect the retail fields accessed here.
// Collections own their backing slots via retail ctor/dtor APIs; element metadata pointers and handles are borrowed.
struct LA22Def{char p0[0x44];int category,slot,size,rating;char p54[0x9c];int special;void*rec4573a0(int)throw();};
struct LA22Defs{int a,b,c,d;LA22Defs();~LA22Defs();unsigned size9b9260()const throw();LA22Def*&at9b81f0(unsigned)throw();void push9b9d30(LA22Def*const&);bool empty9b86e0()const throw();};
struct LA22Groups{int a,b,c,d;LA22Groups();~LA22Groups();LA22Defs&at9b8070(unsigned)throw();void pushCategories(LA22Defs&&);};
struct LA22Ints{int a,b,c,d;LA22Ints();~LA22Ints();int&at9b81f0(unsigned)throw();void push9b9280(int&&);};
struct LA22Weights{LA22Ints a,b;int total;LA22Weights();~LA22Weights();void add9ba310(int,int);int&pick9ba470();void remove9bab80(int);};
struct LA22Entity;struct LA22Item;struct LA22H{int id;LA22H()throw();};struct LA22HP{int id;LA22HP()throw();};struct LA22HI{int id;LA22Item*get9b65b0()const throw();};
struct LA22Items{int a,b,c,d;LA22Items();~LA22Items();unsigned size9b9260()const throw();LA22HI&at9b81f0(unsigned)throw();void push9b80b0(const LA22HI&);};
struct LA22Item{int category4578a0()throw();void*effect457b70(int)throw();void remove57dbe0(bool,bool,int,bool);LA22Def*def9b4350()throw();int type457820()throw();string name571db0(bool,bool);};
struct LA22P{int x,y;};struct LA22AI{void update5b2d10();};
struct LA22Entity{int pad0;LA22H self;char p8[0x12c];LA22Items items;LA22AI*ai;void loadout63c770(bool);int movement5d1440()throw();int status5cba50()throw();bool effect5d26e0(int)throw();void update5fdab0();bool hostile45aa70(LA22H)throw();const LA22P&pos45a4a0()throw();};
struct LA22Map{LA22HI add6c51d0(LA22Def*,LA22H,bool,bool);LA22H player4630f0()throw();};extern LA22Map*la22_cefc4c;
struct LA22Data{int depth46f4e0()throw();};extern LA22Data la22_d1e860;extern LA22Defs la22_d2d1c4;
struct LA22UI{void update8758d0(bool);};extern LA22UI*la22_cec058;struct LA22Log{void end7b4f10()throw();};extern LA22Log*la22_cec0b4;
void la22_erase(LA22Defs&,unsigned&)throw();bool la22_contains(LA22Ints&,int)throw();LA22Def*la22_random(LA22Defs&);LA22Def*la22_pop(LA22Defs&);int la22_min(int,int)throw();int la22_max(int,int)throw();string la22_int(int);int la22_sound454260(const LA22P&,unsigned);
bool la22_route5111e0(int,const string*,const string*,const string*,LA22H,LA22H,const LA22P*,bool);
void LA22Entity::loadout63c770(bool quiet){
 LA22Groups f;
 for(int i=0;i<4;i++){
  f.pushCategories(LA22Defs());
  for(unsigned j=0;j<la22_d2d1c4.size9b9260();j++)if(la22_d2d1c4.at9b81f0(j)->rec4573a0(57)&&la22_d2d1c4.at9b81f0(j)->slot==i)f.at9b8070(i).push9b9d30(la22_d2d1c4.at9b81f0(j));
 }
 LA22Def*h;LA22Defs a;
 for(unsigned i=0;i<f.at9b8070(2).size9b9260();i++)switch(f.at9b8070(2).at9b81f0(i)->special){
 case 1:h=f.at9b8070(2).at9b81f0(i);la22_erase(f.at9b8070(2),i);break;
 case 159:case 181:case 184:case 190:a.push9b9d30(f.at9b8070(2).at9b81f0(i));la22_erase(f.at9b8070(2),i);break;
 case 35:if(movement5d1440()>=3)la22_erase(f.at9b8070(2),i);break;
 }
 LA22Weights first;first.add9ba310(0,25);first.add9ba310(1,50);first.add9ba310(2,20);first.add9ba310(3,5);
 int label=la22_d1e860.depth46f4e0();int temp=la22_max(5,label);
 while(true){
  int p=first.pick9ba470();LA22Ints h;
  switch(p){case 0:h.push9b9280(26);h.push9b9280(27);h.push9b9280(28);break;case 1:h.push9b9280(20);h.push9b9280(22);break;case 2:h.push9b9280(21);h.push9b9280(23);break;case 3:h.push9b9280(24);break;}
  LA22Defs a;
  for(unsigned i=0;i<f.at9b8070(3).size9b9260();i++)if(la22_contains(h,f.at9b8070(3).at9b81f0(i)->category)&&f.at9b8070(3).at9b81f0(i)->rating<=temp)a.push9b9d30(f.at9b8070(3).at9b81f0(i));
  if(a.empty9b86e0()){first.remove9bab80(p);}else{
  bool n=false;
  if(status5cba50()&&rng.chance(p==0?100:p==1?33:p==2?66:90)){
   for(unsigned i=0;i<items.size9b9260();i++)if(items.at9b81f0(i).get9b65b0()->category4578a0()==3&&!items.at9b81f0(i).get9b65b0()->effect457b70(59)){items.at9b81f0(i).get9b65b0()->remove57dbe0(false,true,1,true);i--;}
   n=true;
  }
  LA22Def*group=la22_random(a);int type=1;
  switch(p){case 0:if(group->size==1&&rng.chance(la22_min(85,(label-group->rating)*30)))type=2;break;case 1:if(rng.chance(n?la22_min(90,(label-group->rating+1)*50):la22_min(85,(label-group->rating)*20)))type=2;break;case 2:if(n&&rng.chance((label-group->rating)*2))type=2;break;}
  for(int i=0;i<type;i++)la22_cefc4c->add6c51d0(group,self,true,false);
  ai->update5b2d10();break;}
 }
 int other=rng.chance(15)?2:1;
 for(int i=0;i<other;i++){LA22Def*p=la22_pop(f.at9b8070(2));la22_cefc4c->add6c51d0(p,self,true,false);}
 other=rng.chance(10)?1:0;
 for(int i=0;i<other;i++){LA22Def*p=la22_random(a);la22_cefc4c->add6c51d0(p,self,true,false);}
 if(status5cba50()>=3||effect5d26e0(35)){if(rng.chance(25))la22_cefc4c->add6c51d0(h,self,true,false);if(rng.chance(10))la22_cefc4c->add6c51d0(la22_random(f.at9b8070(0)),self,true,false);}
 LA22Items type;LA22Ints i;
 for(unsigned n=0;n<items.size9b9260();n++){
  if(items.at9b81f0(n).get9b65b0()->def9b4350()->rec4573a0(57)){
   for(unsigned j=0;j<type.size9b9260();j++)if(type.at9b81f0(j).get9b65b0()->type457820()==items.at9b81f0(n).get9b65b0()->type457820()){i.at9b81f0(j)++;goto next;}
   type.push9b80b0(items.at9b81f0(n));i.push9b9280(1);
  }next:;
 }
 string list;
 for(unsigned n=0;n<type.size9b9260();n++){if(n)list+=", ";list+=type.at9b81f0(n).get9b65b0()->name571db0(false,false);if(i.at9b81f0(n)>1)list+=" (x"+la22_int(i.at9b81f0(n))+")";}
 update5fdab0();
 if(!quiet){do{if(la22_route5111e0(hostile45aa70(la22_cefc4c->player4630f0())?201:200,&list,0,0,self,LA22H(),0,false))la22_cec058->update8758d0(true);la22_cec0b4->end7b4f10();}while(false);la22_sound454260(pos45a4a0(),225);}
}
