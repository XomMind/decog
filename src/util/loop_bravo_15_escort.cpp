// NOTE: private partial aliases and real call-site layouts for Forge escort spawning743350.
#include <string>
#include "rng.h"
using std::string;extern RNG rng;
struct LB15Point {int x,y;LB15Point() throw();};struct LB15Entity;struct LB15AI;struct LB15Squad;struct LB15Data {char pad[0x28];int faction;char pad2c[0x70];int size;};
struct LB15Area {int left,top,right,bottom;};
struct LB15H {int id;LB15H() throw();LB15Entity*get9b6570()const throw();bool valid9b7230()const throw();bool different9b6510(LB15H)const throw();};
struct LB15HS {int id;LB15Squad*get9b7250()const throw();};struct LB15HP {int id;LB15HP() throw();};
struct LB15Handles {char layout[16];LB15Handles() throw();~LB15Handles();void push9b80b0(const LB15H&);bool empty9b86e0()const throw();LB15H&front9b7060() throw();unsigned size9b9260()const throw();LB15H&at9b81f0(unsigned) throw();};
struct LB15Squad {LB15Handles*members416f40() throw();};
struct LB15AI {void follow5b2f80(LB15H,bool) throw();void flag418480(bool) throw();void goal459410(const LB15Area&) throw();};
struct LB15Entity {LB15AI*ai45b590() throw();const string&name416f40() throw();int score5d15a0(int) throw();int faction45a2c0() throw();void command639530(int,bool) throw();};
struct LB15Weighted {char layout[36];LB15Weighted() throw();~LB15Weighted();void add9ba310(LB15Data*,int);LB15Data*&pick9ba470();};
struct LB15DataList {LB15Data*&at9b81f0(unsigned) throw();};extern LB15DataList lb15_d25de0;
int lb15_find9d7b80(LB15DataList&,const string&);
extern int lb15_b99950[],lb15_b99968[],lb15_b99980[],lb15_b99998[],lb15_b999b0[],lb15_b999c8[],lb15_b999e0[],lb15_b999f8[],lb15_b99a10[],lb15_b99a28[],lb15_b99a40[];
extern LB15Data *lb15_cefc10;
struct LB15Squads {char layout[16];LB15HS&at9b81f0(unsigned) throw();};
struct LB15Map {char pad0[0x4c];LB15Squads squads;char pad5c[0x934-0x5c];LB15Area goal,goal2;char pad954[0x14];int waves;char pad96c[0x24];LB15Handles arrivals;
 LB15H place6c58c0(LB15Data*,const LB15Point&,int,int,int,int,int) throw();bool dialog6c65a0(LB15H,const string&,bool);void escort743350(bool,bool,bool);
};
bool lb15_location742b60(LB15Point&,int) throw();
struct LB15GameData {int tier46fd60() throw();};extern LB15GameData lb15_d1e860;
struct LB15Flag{void set451400(int) throw();};extern LB15Flag lb15_cf1080;int lb15_sound4541b0(unsigned,int,int) throw();
bool lb15_route5111e0(int,const string&,const string*,const string*,LB15H,LB15HP,const LB15Point*,bool);
struct LB15UI{void update8758d0(bool) throw();};extern LB15UI*lb15_cec058;
struct LB15Log{void end7b4f10() throw();};extern LB15Log*lb15_cec0b4;
#define LB15_ADD(NAME,TABLE) list.add9ba310(lb15_d25de0.at9b81f0(lb15_find9d7b80(lb15_d25de0,NAME)),TABLE[count])
void LB15Map::escort743350(bool special,bool quiet,bool alternate){
 LB15Point pos;
 if(special){
  if(lb15_location742b60(pos,1)){
   LB15H p=place6c58c0(lb15_cefc10,pos,10,0,17,0,0);
   if(p.valid9b7230()){
    arrivals.push9b80b0(p);
    int index=2+lb15_d1e860.tier46fd60()/2;
    LB15Data *count=lb15_d25de0.at9b81f0(lb15_find9d7b80(lb15_d25de0,rng.chance(50)?"Elite_7":"Scrapoid_8"));
    for(int i=0;i<index;i++){
     if(!lb15_location742b60(pos,count->size))continue;
     LB15H item=place6c58c0(count,pos,10,0,3,14,0);
     if(item.valid9b7230()){
      item.get9b6570()->ai45b590()->follow5b2f80(p,false);
      item.get9b6570()->ai45b590()->flag418480(true);
      item.get9b6570()->ai45b590()->goal459410(goal);
     }
    }
    if(!quiet){
     string line="0bP_NET: "+p.get9b6570()->name416f40()+" inbound, all units not involved in other operations escort to target.";
     do{lb15_cf1080.set451400(true);if(false)lb15_sound4541b0(-1,0,0);do{if(lb15_route5111e0(0x324,line,0,0,LB15H(),LB15HP(),0,false))lb15_cec058->update8758d0(true);lb15_cec0b4->end7b4f10();}while(false);lb15_cec0b4->end7b4f10();}while(false);
    }
   }
  }
 }else{
  waves++;
  int count=lb15_d1e860.tier46fd60();
  LB15Weighted list;
  LB15_ADD("Bolteater",lb15_b99950);LB15_ADD("Federalist",lb15_b99968);LB15_ADD("Explorer",lb15_b99980);LB15_ADD("Ranger",lb15_b99998);LB15_ADD("Guru",lb15_b999b0);LB15_ADD("Scrapper_6",lb15_b999c8);LB15_ADD("Elite_7",lb15_b999e0);LB15_ADD("Scrapoid_6",lb15_b999f8);LB15_ADD("Scrapoid_8",lb15_b99a10);LB15_ADD("Scraphulk_6",lb15_b99a28);LB15_ADD("Scraphulk_8",lb15_b99a40);
  for(int n=2;n!=0;n--){
   if(squads.at9b81f0(10).get9b7250()->members416f40()->size9b9260()>=70)return;
   bool active=false;
   LB15Handles point;
   for(int i=4;i!=0;i--){
    LB15Data *item=list.pick9ba470();
    while(active&&item->faction==47)item=list.pick9ba470();
    if(!lb15_location742b60(pos,item->size))continue;
    LB15H u=place6c58c0(item,pos,10,0,3,14,0);
    if(u.valid9b7230()){
     point.push9b80b0(u);
     u.get9b6570()->ai45b590()->goal459410(alternate?goal2:goal);
     if(alternate)u.get9b6570()->command639530(149,true);
     if(item->faction==47)active=true;
    }
   }
   if(!point.empty9b86e0()){
    LB15H b=point.front9b7060();
    int p=b.get9b6570()->score5d15a0(0);
    int value;
    for(int i=1;i<point.size9b9260();i++){
     value=point.at9b81f0(i).get9b6570()->score5d15a0(0);
     if(value>p){b=point.at9b81f0(i);p=value;}
    }
    for(int i=0;i<point.size9b9260();i++)if(point.at9b81f0(i).different9b6510(b))point.at9b81f0(i).get9b6570()->ai45b590()->follow5b2f80(b,false);
    LB15H best;
    switch(waves){
     case 1:
select:
    for(int i=0;i<point.size9b9260();i++){
     if(point.at9b81f0(i).get9b6570()->faction45a2c0()==40||point.at9b81f0(i).get9b6570()->faction45a2c0()==41||point.at9b81f0(i).get9b6570()->faction45a2c0()==42||point.at9b81f0(i).get9b6570()->faction45a2c0()==44||point.at9b81f0(i).get9b6570()->faction45a2c0()==45){best=point.at9b81f0(i);break;}
    }
    break;
    case 2:case 3:case 4:if(n==1)goto select;break;
    }
    if(best.valid9b7230())dialog6c65a0(best,"FRG_UFD_Fight_Talk_Rand",false);
   }
  }
 }
}
