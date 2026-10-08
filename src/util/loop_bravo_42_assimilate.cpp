// NOTE: private borrowed EntityAI/Entity views; no custom object allocation.
#include <string>
#include <vector>
#include "rng.h"
using std::string;using std::vector;extern RNG rng;
struct LB42P{int x,y;};struct LB42Range{int min,max;int random40c130()throw();};extern LB42Range lb42_d2191c;
struct LB42Entity;struct LB42Item;struct LB42Prop;struct LB42Group;
struct LB42HE{int id;LB42HE()throw();LB42Entity*get9b6570()const throw();bool null9b65d0()const throw();bool valid9b7230()const throw();bool operator!=(LB42HE)const throw();};
struct LB42HI{int id;LB42HI()throw();LB42Item*get9b65b0()const throw();bool null9b65d0()const throw();bool valid9b7230()const throw();};
struct LB42HP{int id;LB42HP()throw();LB42Prop*get9b64f0()const throw();};struct LB42HG{int id;LB42Group*get9b7250()const throw();};
struct LB42Def{char omitted0[0x68];int kind;char omitted6c[0x40];int flagac,mode;char omittedb4[0x6c];int value;};
struct LB42Effects;struct LB42Effect;struct LB42Entity{char omitted0[0xc];string name;LB42HG group;int faction45a2c0()throw();int type45a2a0()throw();LB42HG group45a3f0()throw();LB42P&pos45a4a0()throw();string&name45a280()throw();string&text416f40()throw();bool friendly45aaa0(LB42HE);LB42Def*def9b4350()throw();bool blocked5d5250();LB42HI tool5d6560();LB42Effect*effect45ac40(int)throw();bool test5d4490(LB42HE);void stun5fd900(int,int);void faction5dc780(LB42HG,bool);LB42Effects*effects45ad90()throw();};
struct LB42Group{int kind9b4350()throw();};struct LB42Machine{char omitted0[0x40];vector<int>flags;};struct LB42Prop{LB42P&pos4184d0()throw();LB42Machine*machine45cb30()throw();};struct LB42Item{string name571db0(bool,bool);};
struct LB42World{vector<vector<LB42HP> >&props463be0()throw();bool reachable465230(int,const LB42P&,const LB42P&);void hack734ae0(LB42HE,const LB42P&,bool);LB42HE player4630f0()throw();LB42HE convert7345f0(LB42HE,LB42HE,bool);LB42HI steal734920(LB42HE,LB42HE);bool near4631f0(LB42HE);LB42HG group463890(int)throw();};extern LB42World*lb42_cefc4c;
int lb42_distance40a3f0(const LB42P&,const LB42P&)throw();bool lb42_remove9d51d0(vector<int>&,int);void lb42_remove9d2f00(vector<LB42HP>&,LB42HP);
struct LB42Target{LB42HE entity;int unknown4,score;};struct LB42AI{LB42HE entity;char omitted4[0xec];vector<LB42Target*>targets;bool can5bd240(LB42HE);int assimilate5bbf70(int,LB42HE);};
struct LB42UI{void bubble8758d0(bool);};struct LB42Log{void end7b4f10();};extern LB42UI*lb42_cec058;extern LB42Log*lb42_cec0b4,*lb42_cec0c4;
bool lb42_route5111e0(int,const string*,const string*,const string*,LB42HE,LB42HE,const LB42P*,bool);bool lb42_phrase5141b0(int,const string*,const string*,const string*,LB42HE,const LB42P*);
struct LB42Stats{bool add4729d0(unsigned,int,string,int);};extern LB42Stats lb42_d2c658;struct LB42Player{bool achieve77fbc0(int);};extern LB42Player lb42_cf45d8;
struct LB42Xom{bool active;int action69e700(int,int,float);};extern LB42Xom lb42_d25450;
extern int lb42_b985e0[][11],lb42_b98480[][11],lb42_bba058[],lb42_d28d18;extern vector<int>lb42_cf4a04;
bool lb42_effect4569a0(int,LB42HE,LB42HE,LB42HP,LB42HI,const LB42P*,const string*,LB42Effects*,LB42HE,LB42HP,LB42HI,const LB42P*);
#define LB42_MSG0(ID,TEXT,A,B,POS) do{if(lb42_route5111e0(ID,TEXT,0,0,A,B,POS,false))lb42_cec058->bubble8758d0(true);lb42_cec0b4->end7b4f10();}while(false)
#define LB42_MSG1(ID,TEXT,A,B,POS) do{if(lb42_route5111e0(ID,TEXT,0,0,A,B,POS,true))lb42_cec058->bubble8758d0(false);lb42_cec0c4->end7b4f10();}while(false)
int LB42AI::assimilate5bbf70(int chance,LB42HE proposed){
 if(entity.get9b6570()->faction45a2c0()==25&&rng.chance(chance)&&!entity.get9b6570()->blocked5d5250()){
  if(entity.get9b6570()->group45a3f0().get9b7250()->kind9b4350()==3&&!lb42_cefc4c->props463be0()[4].empty()){
   vector<LB42HP>*props=&lb42_cefc4c->props463be0()[4];
   for(unsigned i=0;i<props->size();i++)if(lb42_distance40a3f0((*props)[i].get9b64f0()->pos4184d0(),entity.get9b6570()->pos45a4a0())<=10&&lb42_cefc4c->reachable465230(10,entity.get9b6570()->pos45a4a0(),(*props)[i].get9b64f0()->pos4184d0())){
    LB42_MSG0(483,0,entity,LB42HE(),&(*props)[i].get9b64f0()->pos4184d0());
    lb42_cefc4c->hack734ae0(entity,(*props)[i].get9b64f0()->pos4184d0(),true);lb42_remove9d51d0((*props)[i].get9b64f0()->machine45cb30()->flags,4);lb42_remove9d2f00(lb42_cefc4c->props463be0()[4],(*props)[i]);return 1;
   }
  }
  if(entity.get9b6570()->tool5d6560().null9b65d0())return 0;
  LB42HE target=can5bd240(proposed)?proposed:LB42HE();
  if(target.null9b65d0())for(unsigned i=0;i<targets.size();i++)if(targets[i]->entity!=proposed&&can5bd240(targets[i]->entity)){target=targets[i]->entity;break;}
  if(target.valid9b7230()){
   bool changed=false;
   bool convert=((entity.get9b6570()->type45a2a0()==1||entity.get9b6570()->type45a2a0()==2||entity.get9b6570()->name=="ME-RLN"||entity.get9b6570()->name=="AZ-K3N")&&rng.chance(50)&&!target.get9b6570()->effect45ac40(123)&&!entity.get9b6570()->effect45ac40(57));
   if(!rng.chance(convert?lb42_b985e0[target.get9b6570()->def9b4350()->mode][entity.get9b6570()->def9b4350()->kind]:lb42_b98480[target.get9b6570()->def9b4350()->mode][entity.get9b6570()->def9b4350()->kind])){
    LB42_MSG0(entity.get9b6570()->friendly45aaa0(lb42_cefc4c->player4630f0())?479:480,0,entity,target,0);
    if(lb42_d28d18>=0){LB42_MSG1(entity.get9b6570()->friendly45aaa0(lb42_cefc4c->player4630f0())?731:732,0,entity,target,0);}
   }else if(target.get9b6570()->friendly45aaa0(lb42_cefc4c->player4630f0())&&lb42_cf4a04[15]&&(target.get9b6570()->type45a2a0()==1||target.get9b6570()->type45a2a0()==2)&&lb42_cefc4c->player4630f0().get9b6570()->test5d4490(target)){
    LB42_MSG0(680,0,target,LB42HE(),0);if(lb42_d28d18>=0){LB42_MSG1(736,0,target,LB42HE(),0);}lb42_cf45d8.achieve77fbc0(125);
   }else{
    LB42HE other=lb42_cefc4c->convert7345f0(entity,target,false);
    if(other.valid9b7230()){
     LB42_MSG0(other.get9b6570()->friendly45aaa0(lb42_cefc4c->player4630f0())?481:482,0,other,LB42HE(),&target.get9b6570()->pos45a4a0());
     if(lb42_d28d18>=0){LB42_MSG1(other.get9b6570()->friendly45aaa0(lb42_cefc4c->player4630f0())?733:734,0,other,LB42HE(),&target.get9b6570()->pos45a4a0());}
    }else{
     LB42HI item=lb42_cefc4c->steal734920(entity,target);
     if(item.valid9b7230()){
      LB42_MSG0(488,&item.get9b65b0()->name571db0(false,false),target,LB42HE(),0);if(lb42_d28d18>=0){LB42_MSG1(735,&item.get9b65b0()->name571db0(false,false),target,LB42HE(),0);}lb42_cf45d8.achieve77fbc0(125);
     }else if(convert){
      LB42_MSG0(entity.get9b6570()->friendly45aaa0(lb42_cefc4c->player4630f0())?477:478,&string("assimilated"),target,entity,0);
      if(lb42_d28d18>=0){LB42_MSG1(entity.get9b6570()->friendly45aaa0(lb42_cefc4c->player4630f0())?729:730,&string("assimilated"),target,entity,0);}
      if(entity.get9b6570()->friendly45aaa0(lb42_cefc4c->player4630f0())||target.get9b6570()->friendly45aaa0(lb42_cefc4c->player4630f0()))do{lb42_phrase5141b0(entity.get9b6570()->friendly45aaa0(lb42_cefc4c->player4630f0())?130:131,&entity.get9b6570()->text416f40(),&target.get9b6570()->text416f40(),0,target,0);}while(false);
      if(lb42_cefc4c->near4631f0(target)&&target.get9b6570()->friendly45aaa0(lb42_cefc4c->player4630f0())){if(target.get9b6570()->type45a2a0()==0)lb42_cf45d8.achieve77fbc0(124);if(lb42_d25450.active&&target.get9b6570()->def9b4350()->value>=4)lb42_d25450.action69e700(33,0,0.f);}
      int group=entity.get9b6570()->group45a3f0().get9b7250()->kind9b4350();
      if(group==3&&lb42_bba058[target.get9b6570()->faction45a2c0()]<8&&target.get9b6570()->faction45a2c0()!=12&&target.get9b6570()->faction45a2c0()!=19&&target.get9b6570()->name45a280()!="A-27 Freighter")group=4;
      target.get9b6570()->stun5fd900(1,lb42_d2191c.random40c130());target.get9b6570()->faction5dc780(lb42_cefc4c->group463890(group),true);
      lb42_effect4569a0(40,entity,LB42HE(),LB42HP(),LB42HI(),0,0,entity.get9b6570()->effects45ad90(),entity,LB42HP(),LB42HI(),0);changed=true;
     }else{
      lb42_effect4569a0(39,entity,LB42HE(),LB42HP(),LB42HI(),0,0,entity.get9b6570()->effects45ad90(),entity,LB42HP(),LB42HI(),0);
      LB42_MSG0(entity.get9b6570()->friendly45aaa0(lb42_cefc4c->player4630f0())?477:478,&string("rebooting"),target,entity,0);
      if(lb42_d28d18>=0){LB42_MSG1(entity.get9b6570()->friendly45aaa0(lb42_cefc4c->player4630f0())?729:730,&string("rebooting"),target,entity,0);}
      target.get9b6570()->stun5fd900(1,lb42_d2191c.random40c130());changed=true;
     }
    }
   }
   if(changed&&target.get9b6570()->group.get9b7250()->kind9b4350()<=2)lb42_d2c658.add4729d0(891,1,"",-1);
   lb42_cefc4c->hack734ae0(entity,target.get9b6570()->pos45a4a0(),changed);return 1;
  }if(chance==100&&proposed.get9b6570()->def9b4350()->flagac==0)return 2;
 }
 return 0;
}
