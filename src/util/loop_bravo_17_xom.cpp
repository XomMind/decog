// NOTE: private aliases and partial call-site layouts for Xom turn update69d6f0.
#include <string>
#include "rng.h"
using std::string;extern RNG rng;
struct LB17Point{int x,y;LB17Point() throw();LB17Point(int) throw();void assign46ca50(const LB17Point&) throw();};
struct LB17Area{int left,top,right,bottom;LB17Area() throw();void random40be30(LB17Point*) throw();};
struct LB17Entity;struct LB17Item;struct LB17Squad;
struct LB17H{int id;LB17H() throw();LB17Entity*get9b6570()const throw();bool null9b65d0()const throw();};
struct LB17HP{int id;LB17HP() throw();};
struct LB17HI{int id;LB17Item*get9b65b0()const throw();bool valid9b7230()const throw();bool null9b65d0()const throw();};
struct LB17HS{int id;LB17Squad*get9b7250()const throw();};
struct LB17Entities{unsigned size9b9260()const throw();LB17H&at9b81f0(unsigned) throw();};
struct LB17Points{unsigned size9b9a50()const throw();LB17Point&at(unsigned) throw();};
struct LB17Squad{LB17Entities*members416f40() throw();};
struct LB17Entity{const LB17Point&pos45a4a0() throw();LB17HI item5d2380(int) throw();int score5d15a0(int) throw();const string&name416f40() throw();int id9b8f10() throw();LB17Points*points45d1a0() throw();void vanish637bb0() throw();};
struct LB17Item{string name571db0(int,int);const LB17Point&point575920() throw();int kind44aec0() throw();int value457fb0() throw();void remove57dbe0(int,bool,bool,bool) throw();};
struct LB17Cell{LB17H entity45d250() throw();bool clear45d7b0() throw();};struct LB17Grid{LB17Cell**at9ced70(LB17Point&) throw();void rect9b4430(const LB17Point&,int,LB17Area*) throw();};extern LB17Grid lb17_cfd44c;
struct LB17Map{int turn464270() throw();LB17H player4630f0() throw();bool visible4633c0(const LB17Point&) throw();bool visible4631f0(LB17H) throw();LB17HI placeItem(const string&,const LB17Point&);bool quiet714a50() throw();int score7151c0() throw();LB17HS squad463890(int) throw();};extern LB17Map*lb17_cefc4c;
struct LB17Timer{int a,b;bool expired690da0() throw();void set690d40(int,int) throw();};
struct LB17Ints{int a,b,c,d;unsigned size9b9260()const throw();int&at9b81f0(unsigned) throw();};
struct LB17Xom{bool enabled;char pad1[3];int messageTurn,spawnTurn;LB17HI tracker;int pad10,boredom;LB17Timer boredomTimer;char pad20[0x50];int counter70,pad74,counter78,time7c,pad80,pad84,counter88,time8c,pad90,pad94,score98,pad9c,pending;bool pendingFlag;char pada5[0x120-0xa5];LB17Ints ids,turns;bool eligible69e530() throw();void event69e700(int,int,float) throw();void update6a0150(bool) throw();void turn69d6f0();};
struct LB17Record{int id;};bool lb17_lookup9d7980(const string&,LB17Record**);
struct LB17View{void delay49adc0(int) throw();};extern LB17View*lb17_cec054;
struct LB17Game{bool flag46fb60() throw();};extern LB17Game lb17_d1e860;
struct LB17Flag{void set451400(int) throw();};extern LB17Flag lb17_cf1080;
struct LB17UI{void update8758d0(bool) throw();};extern LB17UI*lb17_cec058;struct LB17Log{void end7b4f10() throw();};extern LB17Log*lb17_cec0b4;
extern string lb17_d226ac;
int lb17_sound4541b0(unsigned,int,int) throw();bool lb17_route5111e0(int,const string&,const string*,const string*,LB17H,LB17HP,const LB17Point*,bool);
void lb17_message49c610(int,LB17H,const string&,int);void lb17_play55ca10(int,const LB17Point&,int) throw();
struct LB17Player{bool companion780790() throw();};extern LB17Player lb17_cf45d8;struct LB17Companion{int pad;LB17HI item;};extern LB17Companion*lb17_cf4ac8;
bool lb17_check69d230() throw();void lb17_clamp9d0690(int*,int,int) throw();extern int lb17_caf154;
void lb17_remove9de6f0(LB17Ints&,int) throw();void lb17_erase9ce6d0(LB17Ints&,unsigned&) throw();
struct LB17Owner;struct LB17Effect{void init503b20(LB17Owner*,LB17Record*,const LB17Point&,const LB17Point&,const LB17Point*,const LB17Point*,void*,int,LB17Effect*);};struct LB17Owner{LB17Effect*new508610() throw();};extern LB17Owner*lb17_cefc50;extern LB17Point lb17_d2e20c;
#define LB17_ROUTE(ID,TEXT) do{if(lb17_route5111e0(ID,TEXT,0,0,LB17H(),LB17HP(),0,false))lb17_cec058->update8758d0(true);lb17_cec0b4->end7b4f10();}while(false)
void LB17Xom::turn69d6f0(){
 if(!enabled)return;
 if(messageTurn&&lb17_d1e860.flag46fb60())switch(lb17_cefc4c->turn464270()-messageTurn){case 1:{string line="FARCOM_MSG: "+lb17_d226ac;do{lb17_cf1080.set451400(true);if(false)lb17_sound4541b0(-1,0,0);LB17_ROUTE(0x324,line);lb17_cec0b4->end7b4f10();}while(false);messageTurn=0;}break;}
 if(spawnTurn){
  if(lb17_cefc4c->turn464270()>=spawnTurn){
   if(!eligible69e530())spawnTurn=0;
   else{
    LB17Area p;lb17_cfd44c.rect9b4430(lb17_cefc4c->player4630f0().get9b6570()->pos45a4a0(),15,&p);LB17Point b(-1),a;
    for(int i=0;i<300;i++){p.random40be30(&a);if(lb17_cefc4c->visible4633c0(a)&&(*lb17_cfd44c.at9ced70(a))->entity45d250().null9b65d0()&&(*lb17_cfd44c.at9ced70(a))->clear45d7b0()){b.assign46ca50(a);break;}}
    if(b.x==-1)spawnTurn+=rng.rangeInt(4,8);
    else{
     LB17HI item=lb17_cefc4c->placeItem("X0-1V1's Piety Tracker",b);
     if(item.valid9b7230()){
      string line=item.get9b65b0()->name571db0(0,0)+" suddenly appears amidst shimmering waves of color.";lb17_message49c610(0x320,LB17H(),line,0);LB17Record *link;
      if(lb17_lookup9d7980("Xom_Piety_Tracker",&link))lb17_play55ca10(link->id,item.get9b65b0()->point575920(),0);
      lb17_cec054->delay49adc0(1000);
     }
     if(tracker.get9b65b0()&&tracker.get9b65b0()->kind44aec0()<=5)tracker.get9b65b0()->remove57dbe0(1,false,true,true);
     tracker=item;
    }
   }
  }
 }else if(lb17_cefc4c->turn464270()%47==0&&eligible69e530())spawnTurn=lb17_cefc4c->turn464270()+rng.rangeInt(5,25);
 if(boredomTimer.expired690da0()){
  int count=boredom;
  if(rng.chance(50)||lb17_cefc4c->player4630f0().get9b6570()->item5d2380(218).null9b65d0()||(lb17_cf45d8.companion780790()&&lb17_cf4ac8->item.get9b65b0()->value457fb0()))lb17_clamp9d0690(&boredom,1,lb17_check69d230()?5:0);
  if(boredom!=count)switch(boredom){case 3:LB17_ROUTE(0x2b4,string("is getting bored..."));lb17_cec054->delay49adc0(1000);break;case 0:LB17_ROUTE(0x2b4,string("is bored!"));lb17_cec054->delay49adc0(1000);break;}
  boredomTimer.set690d40(40,20);
 }
 bool seen=lb17_cefc4c->quiet714a50();
 if(counter70>0){if(counter70>20&&seen){event69e700(9,0,0.f);counter70=0;}if(lb17_cefc4c->turn464270()%2==0)counter70--;}
 if(counter78>0){if(counter78>50){event69e700(23,0,0.f);time7c=0;counter78=0;}if(lb17_cefc4c->turn464270()>time7c+20){time7c=0;counter78=0;}}
 if(counter88>0){if(counter88>40){event69e700(35,0,0.f);time8c=0;counter88=0;}if(lb17_cefc4c->turn464270()>time8c+20){time8c=0;counter88=0;}}
 if(score98){int count=lb17_cefc4c->score7151c0();if(count>score98)event69e700(64,lb17_cefc4c->player4630f0().get9b6570()->score5d15a0(0)>=80,0.f);score98=0;}
 if(pending!=lb17_caf154){event69e700(66,pendingFlag?1:0,0.f);pending=lb17_caf154;pendingFlag=false;}
 update6a0150(true);
 for(unsigned i=0;i<turns.size9b9260();i++)if(lb17_cefc4c->turn464270()>=turns.at9b81f0(i)){
  LB17Entities *point=lb17_cefc4c->squad463890(2).get9b7250()->members416f40();
  for(unsigned j=0;j<point->size9b9260();j++)if(point->at9b81f0(j).get9b6570()->id9b8f10()==ids.at9b81f0(i)&&lb17_cefc4c->visible4631f0(point->at9b81f0(j))){
   string line=point->at9b81f0(j).get9b6570()->name416f40()+" form shifts, blurs, and dematerializes.";LB17_ROUTE(0x320,line);LB17Record *link;
   if(lb17_lookup9d7980("Xom_Disappear",&link))for(unsigned k=0;k<point->at9b81f0(j).get9b6570()->points45d1a0()->size9b9a50();k++)lb17_cefc50->new508610()->init503b20(lb17_cefc50,link,point->at9b81f0(j).get9b6570()->points45d1a0()->at(k),lb17_d2e20c,0,0,0,9,0);
   point->at9b81f0(j).get9b6570()->vanish637bb0();
  }
  lb17_remove9de6f0(ids,i);lb17_erase9ce6d0(turns,i);
 }
}
