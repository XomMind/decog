#include <string>
#include "rng.h"
using std::string;extern RNG rng;
struct LA14Point{int x,y;LA14Point(const LA14Point&) throw();};struct LA14Entity;struct LA14Prop;struct LA14Item;struct LA14Group;
struct LA14H{int id;LA14H() throw();LA14Entity*get9b6570()const throw();bool null9b65d0()const throw();bool valid9b7230()const throw();};
struct LA14HP{int id;LA14HP() throw();LA14Prop*get9b64f0()const throw();};
struct LA14HI{int id;LA14Item*get9b65b0()const throw();bool null9b65d0()const throw();bool valid9b7230()const throw();};
struct LA14HG{int id;LA14Group*get9b7250()const throw();};struct LA14Group{int type9b4350() throw();};
struct LA14Item{string name571db0(bool,bool);};
struct LA14Entity{LA14HG group45a3f0() throw();void*effect45ac40(int) throw();LA14HI item5d2380(int) throw();LA14HI effectItem5d24e0(int) throw();int dodge5cab90() throw();int category5d1390() throw();bool special45a780() throw();bool player5c7600() throw();int bonus5d22a0(int) throw();int size45a360() throw();bool at5c84f0(const LA14Point&) throw();bool friendly45aaa0(LA14H) throw();void move5dccb0(const LA14Point&,bool) throw();};
struct LA14TrapState{LA14HP prop;int group;char pad8[8];int faction;bool active65cf80() throw();bool accepts65cf50(int) throw();};
struct LA14PropDef{char pad[0x140];int type;};struct LA14Prop{LA14TrapState*state44b020() throw();LA14PropDef*def9b8f00() throw();bool used45cbd0() throw();};
struct LA14Cell{char pad[0x30];LA14Point point;char pad38[0xc];LA14HP prop;LA14H entity;bool trap45dcf0() throw();LA14H getEntity45d250() throw();void trigger66ce10(bool,bool,bool,bool) throw();bool test66c290();};
struct LA14Grid{LA14Cell**at9ced70(LA14Point&) throw();};extern LA14Grid la14_grid_cfd44c;
struct LA14Mode{int a,type;};struct LA14MH{int id;LA14Mode*get9b7910()const throw();};extern LA14MH la14_d1e888;
struct LA14Data{const string&text46f6d0(const string&);};extern LA14Data la14_d1e860;int la14_int405610(const string&) throw();
struct LA14Player{bool event77f260(int) throw();bool permitted46e100(int) throw();};extern LA14Player la14_cf45d8;extern int la14_cf4700,la14_caf234[];
struct LA14Map{int relation4638e0(int,int) throw();LA14H player4630f0() throw();bool visible463510(LA14H) throw();bool tracked4635c0(LA14H) throw();void entity72e4c0(LA14H,bool) throw();};extern LA14Map*la14_cefc4c;
struct LA14View{void focus8069e0(LA14Point,bool) throw();};extern LA14View*la14_cec054;extern bool la14_d28e27;
struct LA14Movement{bool pass64f0e0(int,int,LA14Entity*) throw();};extern LA14Movement*la14_cefc2c;
struct LA14Points{int a,b,c,d;LA14Points();~LA14Points();unsigned size9b9a50()const throw();LA14Point&at9e7c10(unsigned) throw();};
void la14_surround4faaf0(const LA14Point&,LA14Points&) throw();void la14_shuffle9d7350(LA14Points&) throw();void la14_reorder9d9020(LA14Points&,unsigned,unsigned) throw();
struct LA14Props{int a,b,c,d;unsigned size9b9260()const throw();LA14HP&at9b81f0(unsigned) throw();};struct LA14Groups{LA14Props&at9b8070(unsigned) throw();};extern LA14Groups la14_d20248;
bool la14_route5111e0(int,const string*,const string*,const string*,LA14H,LA14HP,const LA14Point*,bool);struct LA14Log{void end7b4f10() throw();};extern LA14Log*la14_cec0b4;struct LA14UI{void update8758d0(bool) throw();};extern LA14UI*la14_cec058;
bool LA14Cell::test66c290(){
 if(entity.null9b65d0()||!trap45dcf0()||prop.get9b64f0()->state44b020()->active65cf80()||entity.get9b6570()->effect45ac40(34))return false;
 bool first=prop.get9b64f0()->state44b020()->accepts65cf50(entity.get9b6570()->group45a3f0().get9b7250()->type9b4350());
 if(first&&prop.get9b64f0()->state44b020()->faction==3){if((la14_cf4700&&la14_cf45d8.event77f260(100))||entity.get9b6570()->item5d2380(31).valid9b7230())first=false;}
 bool newValue=false;
 if(!first&&rng.chance(entity.get9b6570()->dodge5cab90())&&entity.get9b6570()->item5d2380(166).null9b65d0()){
  first=newValue=true;
  switch(la14_d1e888.get9b7910()->type){case 11:if(!la14_int405610(la14_d1e860.text46f6d0("scrAttackedLocals_g"))&&!la14_int405610(la14_d1e860.text46f6d0("scrCivilWar_g")))first=newValue=false;break;
   case 20:if(!la14_int405610(la14_d1e860.text46f6d0("zioAttackedLocals_g")))first=newValue=false;break;}
 }
 if(first){
  int type=entity.get9b6570()->category5d1390();if(type==0&&prop.get9b64f0()->def9b8f00()->type==14)return false;
  int count=la14_caf234[type];
  if(la14_cefc4c->relation4638e0(prop.get9b64f0()->state44b020()->faction,false)==2)count=100;
  else if(prop.get9b64f0()->def9b8f00()->type==11)count=100-count;
  bool a=entity.get9b6570()->special45a780();if(a)count=100;
  if(entity.get9b6570()->player5c7600()&&la14_cf45d8.permitted46e100(la14_d1e888.get9b7910()->type))count+=20;
  if(rng.chance(count)){
   int amount=0;
   switch(type){case 1:case 3:case 4:case 6:if(!a){int temp=entity.get9b6570()->bonus5d22a0(84);if(temp)amount+=temp;}break;}
   if(entity.get9b6570()->size45a360()==1&&rng.chance(amount)){
    LA14Points list;la14_surround4faaf0(point,list);la14_shuffle9d7350(list);
    for(int ii=list.size9b9a50()-2;ii>=0;ii--)if((*la14_grid_cfd44c.at9ced70(list.at9e7c10(ii)))->trap45dcf0())la14_reorder9d9020(list,ii,list.size9b9a50()-1);
    for(unsigned part=0;part<list.size9b9a50();part++){
     if(entity.get9b6570()->at5c84f0(list.at9e7c10(part))&&(*la14_grid_cfd44c.at9ced70(list.at9e7c10(part)))->getEntity45d250().null9b65d0()&&la14_cefc2c->pass64f0e0(list.at9e7c10(part).x,list.at9e7c10(part).y,entity.get9b6570())){
      do{if(la14_route5111e0(entity.get9b6570()->player5c7600()?0x214:entity.get9b6570()->friendly45aaa0(la14_cefc4c->player4630f0())?0x215:0x216,&entity.get9b6570()->effectItem5d24e0(84).get9b65b0()->name571db0(false,false),0,0,entity,LA14HP(),0,false))la14_cec058->update8758d0(true);la14_cec0b4->end7b4f10();}while(false);
      LA14H owner=entity;entity.get9b6570()->move5dccb0(list.at9e7c10(part),true);
      if(owner.get9b6570()->group45a3f0().get9b7250()->type9b4350()==0||la14_cefc4c->visible463510(owner)||la14_cefc4c->tracked4635c0(owner)){
       la14_cefc4c->entity72e4c0(owner,true);if(owner.get9b6570()->player5c7600()&&la14_d28e27)la14_cec054->focus8069e0(list.at9e7c10(part),false);
      }break;
     }
    }
   }
   bool s=false;
   if(entity.valid9b7230()){
    if(newValue){do{if(la14_route5111e0(entity.get9b6570()->player5c7600()?0x217:entity.get9b6570()->friendly45aaa0(la14_cefc4c->player4630f0())?0x218:0x219,0,0,0,entity,LA14HP(),&point,false))la14_cec058->update8758d0(true);la14_cec0b4->end7b4f10();}while(false);}
    if(entity.get9b6570()->player5c7600()){
     s=true;LA14Props*data=&la14_d20248.at9b8070(prop.get9b64f0()->state44b020()->group);
     for(unsigned r=0;r<data->size9b9260();r++){if(data->at9b81f0(r).get9b64f0()->used45cbd0()){s=false;break;}}
    }
   }
   trigger66ce10(true,0,s,false);return true;
  }
 }
 return false;
}
