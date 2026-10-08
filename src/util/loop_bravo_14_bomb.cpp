// NOTE: private partial aliases and layouts for buried-bomb update 744aa0.
#include <string>
using std::string;
struct LB14Point {int x,y;};struct LB14Entity;struct LB14Item;struct LB14Record;struct LB14Squad;
struct LB14H {int id;LB14H() throw();LB14Entity *get9b6570()const throw();};
struct LB14HI {int id;LB14Item *get9b65b0()const throw();};
struct LB14HS {int id;LB14Squad *get9b7250()const throw();};
struct LB14HP {int id;LB14HP() throw();};
struct LB14Entities {char pad[16];unsigned size9b9260()const throw();LB14H&at9b81f0(unsigned) throw();};
struct LB14Squad {LB14Entities *members416f40() throw();};
struct LB14Entity {const LB14Point&pos45a4a0() throw();bool player5c7600() throw();int faction45a2c0() throw();bool squad5cb680(LB14HS) throw();void dialog6395d0(LB14Record*,bool) throw();};
struct LB14Item {int effect457be0(int) throw();const LB14Point&point575920() throw();void effect57bf30(int,int) throw();int effect57bff0(int,bool) throw();int value457fb0() throw();string name571db0(int,int);void remove57dbe0(int,bool,bool,bool) throw();};
struct LB14Cell {LB14HI item45d8f0() throw();};
struct LB14Cells {LB14Cell**at(const LB14Point&) throw();};extern LB14Cells lb14_cfd44c;
struct LB14Area {int a,b,c,d;bool contains40b750(const LB14Point&) throw();};
struct LB14Areas {char pad[16];unsigned size9b5100()const throw();LB14Area&at9b8070(unsigned) throw();};
struct LB14Squads {char pad[16];LB14HS&at9b81f0(unsigned) throw();};
struct LB14Records {char pad[16];};extern LB14Records lb14_d2c408;
struct LB14Map {char pad0[0x4c];LB14Squads squads;char pad5c[0x96c-0x5c];LB14Areas areas;char pad97c[0x24];bool warned;bool visible4631f0(LB14H) throw();bool exists463400(LB14H) throw();void bomb744aa0(LB14H);};
void lb14_erase(LB14Areas&,int&) throw();bool lb14_find(LB14Records&,const string&,LB14Record*&);
string lb14_int4051f0(int);
bool lb14_route5111e0(int,const string&,const string*,const string*,LB14H,LB14HP,const LB14Point*,bool);
void lb14_sound454260(const LB14Point&,int) throw();void lb14_message49c610(int,LB14H,const string&,int);
bool lb14_phrase5141b0(int,const string*,const string*,const string*,LB14H,int);
struct LB14UI {void update8758d0(bool) throw();};extern LB14UI *lb14_cec058;
struct LB14Log {void end7b4f10() throw();};extern LB14Log *lb14_cec0b4;
struct LB14Player {void achieve77fbc0(int) throw();};extern LB14Player lb14_cf45d8;
extern int lb14_cf4d88;struct LB14Flag{void set451400(int) throw();};extern LB14Flag lb14_cf1080;int lb14_sound4541b0(unsigned,int,int) throw();
#define LB14_ROUTE(ID,TEXT,B,C,H) do{if(lb14_route5111e0(ID,TEXT,B,C,H,LB14HP(),0,false))lb14_cec058->update8758d0(true);lb14_cec0b4->end7b4f10();}while(false)
#define LB14_PHRASE(ID) do{lb14_phrase5141b0(ID,0,0,0,LB14H(),0);}while(false)
void LB14Map::bomb744aa0(LB14H entity){
 LB14HI item=(*lb14_cfd44c.at(entity.get9b6570()->pos45a4a0()))->item45d8f0();
 if(item.get9b65b0()->effect457be0(2)!=item.get9b65b0()->point575920().x || item.get9b65b0()->effect457be0(3)!=item.get9b65b0()->point575920().y){
  item.get9b65b0()->effect57bf30(2,item.get9b65b0()->point575920().x);
  item.get9b65b0()->effect57bf30(3,item.get9b65b0()->point575920().y);
  item.get9b65b0()->effect57bf30(0,1);
  if(entity.get9b6570()->player5c7600())LB14_ROUTE(0xdd,item.get9b65b0()->name571db0(0,0),&lb14_int4051f0(item.get9b65b0()->value457fb0()),0,entity);
  else LB14_ROUTE(0xdf,item.get9b65b0()->name571db0(0,0),0,0,entity);
  lb14_sound454260(entity.get9b6570()->pos45a4a0(),0x11f);
 }else{
  int count=item.get9b65b0()->effect57bff0(0,true);
  if(count<item.get9b65b0()->value457fb0()){
   if(entity.get9b6570()->player5c7600())LB14_ROUTE(0xde,item.get9b65b0()->name571db0(0,0),&lb14_int4051f0(count),&lb14_int4051f0(item.get9b65b0()->value457fb0()),entity);
   else LB14_ROUTE(0xdf,item.get9b65b0()->name571db0(0,0),0,0,entity);
   lb14_sound454260(entity.get9b6570()->pos45a4a0(),0x11f);
  }else{
   if(visible4631f0(entity)){
    string line=item.get9b65b0()->name571db0(0,0)+" buries itself in the floor.";
    lb14_message49c610(0x320,LB14H(),line,0);
   }
   lb14_sound454260(entity.get9b6570()->pos45a4a0(),0x120);
   bool active=false;
   for(int i=0;i<areas.size9b5100();i++){
    if(areas.at9b8070(i).contains40b750(item.get9b65b0()->point575920())){lb14_erase(areas,i);active=true;}
   }
   if(active){
    if(entity.get9b6570()->player5c7600()){LB14_PHRASE(0x20c);lb14_cf4d88++;lb14_cf45d8.achieve77fbc0(0x1a9);}
    string line="0bP_NET: Important update! "+lb14_int4051f0(10-areas.size9b5100())+"/"+lb14_int4051f0(10)+" targets ready for detonation.";
    do{lb14_cf1080.set451400(true);if(false)lb14_sound4541b0(-1,0,0);LB14_ROUTE(0x324,line,0,0,LB14H());lb14_cec0b4->end7b4f10();}while(false);
    LB14_PHRASE(0x20d);
   }else if(entity.get9b6570()->player5c7600()&&!entity.get9b6570()->squad5cb680(squads.at9b81f0(10))&&!warned){
    LB14Entities *point=squads.at9b81f0(10).get9b7250()->members416f40();
    LB14Record *p;
    if(lb14_find(lb14_d2c408,entity.get9b6570()->pos45a4a0().x>=100?"FRG_Bomb_Wrong_Talk_Rgt":"FRG_Bomb_Wrong_Talk_Lft",p)){
     for(int i=0;i<point->size9b9260();i++){
      if(exists463400(point->at9b81f0(i))&&(point->at9b81f0(i).get9b6570()->faction45a2c0()==44||point->at9b81f0(i).get9b6570()->faction45a2c0()==45||point->at9b81f0(i).get9b6570()->faction45a2c0()==42||point->at9b81f0(i).get9b6570()->faction45a2c0()==41||point->at9b81f0(i).get9b6570()->faction45a2c0()==40||point->at9b81f0(i).get9b6570()->faction45a2c0()==39)){
       point->at9b81f0(i).get9b6570()->dialog6395d0(p,false);warned=true;break;
      }
     }
    }
   }
   item.get9b65b0()->remove57dbe0(0,true,true,true);
  }
 }
}
