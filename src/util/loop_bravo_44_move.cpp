// NOTE: private borrowed AI/Entity/Cell views. Native44 view owns genuine12 grid;
// fallback+28 positively written/read by9cfd90, not frame padding.
#include <string>
#include <vector>
#include "rng.h"
using std::string;using std::vector;extern RNG rng;
struct LB44P{int x,y;LB44P()throw();LB44P(int,int)throw();LB44P(const LB44P&)throw();LB44P&operator=(const LB44P&)throw();LB44P&operator+=(const LB44P&)throw();bool operator==(const LB44P&)const throw();bool operator!=(const LB44P&)const throw();bool different409cf0(int,int)const throw();};
struct LB44Area{LB44P min,max;LB44P center40b620()const throw();};
struct LB44Entity;struct LB44Item;struct LB44Def;struct LB44AI;
struct LB44HE{int id;LB44HE()throw();LB44Entity*get9b6570()const throw();bool valid9b7230()const throw();bool null9b65d0()const throw();bool operator==(LB44HE)const throw();bool operator!=(LB44HE)const throw();};
struct LB44HI{int id;LB44Item*get9b65b0()const throw();bool valid9b7230()const throw();};
struct LB44Def{char omitted0[0x9c];int size;};
struct LB44Array{int width,height;int*cells;LB44Array();~LB44Array();};
struct LB44View{int worldWidth,worldHeight;LB44Array grid;int width,height,x,y,fill,fallback;LB44View();~LB44View();};
struct LB44Modifier{char omitted0[0x18];LB44HE entity;};struct LB44Part{LB44Modifier*mod458950(int)throw();};
struct LB44Entity{char omitted0[8];LB44Def*definition;char omittedc[0x34];int flag40;LB44P&pos45a4a0()throw();string&name416f40()throw();int size45a360()throw();int faction45a2c0()throw();int type45a2a0()throw();int target45a760()throw();bool active45a780()throw();LB44AI*ai45b590()throw();LB44Def*def9b4350()throw();bool hostile45aa70(LB44HE);bool friendly45aaa0(LB44HE);bool player5c7600();bool blocked5d1280(bool);int flag5db260(int);bool wall5c8710(const LB44P&);bool occupied5c85a0(const LB44P&,bool);bool moveOther5c8820(LB44HE);void pos5dccb0(const LB44P&,bool);int mode5d1390();bool candidate5d51a0();void nearby5c8880(vector<LB44HE>*);bool multi5ddf50(const LB44P&,LB44View*,bool*);int move63d8a0(const LB44P&,int,bool);};
struct LB44Item{int special457f90()throw();};
struct LB44Cell{LB44HE entity45d250()throw();LB44HI item45d8f0()throw();bool pass66ab30(LB44HE);void hide45db10()throw();void show45db30()throw();};
struct LB44Grid{LB44Cell**at9ced70(const LB44P&)throw();LB44Cell**at9ceda0(int,int)throw();void bounds9b79c0(const LB44P&,int,int,LB44P*,LB44P*)throw();};extern LB44Grid lb44_cfd44c;
struct LB44State{int unknown0,type;};struct LB44HS{int id;LB44State*get9b7910()const throw();};extern LB44HS lb44_d1e888;
struct LB44Source;
struct LB44World{vector<LB44P*>*points462e10()throw();bool clear716940(const LB44P&,const LB44P&,LB44Entity*,unsigned*);bool allow748a00(LB44View*,LB44Source*);LB44HE player4630f0()throw();bool near4631f0(LB44HE);bool observed714920(const LB44P&,LB44HE);bool visible4631c0(const LB44P&);int turn464270()throw();};extern LB44World*lb44_cefc4c;
struct LB44AI{LB44HE entity;int state,level,unknownc;LB44P goal,unknown18;LB44HE unknown20;vector<LB44P>path;char omitted34[0x1c];LB44HE follow;int unknown54;LB44HE target;char omitted5c[0x58];LB44HE other;bool step581a00(bool);bool find5b8d20();void reset5b7220();bool has459090()throw();LB44Part*part4590f0()throw();bool wait459030()throw();int turn45ad90()throw();LB44HE follow458ed0()throw();void score5b5260(LB44HE,int);int move5b76c0(int*);};
struct LB44Dispatch{void target6906d0(LB44HE);void remove690750(LB44HE);struct LB44Squad*launch687520(LB44HE,const LB44P*,bool);};extern LB44Dispatch lb44_cf6428;
struct LB44Config{bool mode46f4b0(int);};extern LB44Config lb44_d1e860;
struct LB44UI{void bubble8758d0(bool);};extern LB44UI*lb44_cec058;struct LB44Log{void end7b4f10();};extern LB44Log*lb44_cec0b4;struct LB44Notice{void set451400(int);};extern LB44Notice lb44_cf1080;
bool lb44_route5111e0(int,const string*,const string*,const string*,LB44HE,LB44HE,const LB44P*,bool);int lb44_sound4541b0(unsigned,int,int);bool lb44_adjacent4373c0(const LB44P&,const LB44P&)throw();int lb44_distance40a3f0(const LB44P&,const LB44P&)throw();int lb44_direction4374c0(const LB44P&,const LB44P&)throw();void lb44_erase9d5190(vector<LB44P>&,int);extern LB44P lb44_d015d8[];extern vector<LB44Area>lb44_d1ec74;extern bool lb44_d1ebee,lb44_d28fb0,lb44_cefb0a;extern LB44Def*lb44_cefc10;
#define LB44_MSG(ID,TEXT,A,B) do{if(lb44_route5111e0(ID,TEXT,0,0,A,B,0,false))lb44_cec058->bubble8758d0(true);lb44_cec0b4->end7b4f10();}while(false)
typedef char LB44_CheckP[(sizeof(LB44P)==8)?1:-1];
typedef char LB44_CheckView[(sizeof(LB44View)==44)?1:-1];
typedef char LB44_CheckGrid[(sizeof(LB44Array)==12)?1:-1];
typedef char LB44_CheckNativeVector[(sizeof(vector<LB44P>)==16)?1:-1];
// The World+10 pointer elements are borrowed Point-compatible leading views;
// this does not assert that their full original allocation was Point8.
// Source748a00 is borrowed/nullable, raw reads its native string at+8; opaque here.
int LB44AI::move5b76c0(int*out){
 if(goal.x==-1)return 2;
 if(step581a00(false)){LB44_MSG(0x24c,0,entity,LB44HE());return 2;}
 if(entity.get9b6570()->blocked5d1280(false))return 2;
 if(entity.get9b6570()->flag5db260(1))return 2;
 bool active=entity.get9b6570()->size45a360()>1;
 if(path.empty()||path.back()!=goal||!lb44_adjacent4373c0(entity.get9b6570()->pos45a4a0(),path.front())){
  if(!find5b8d20()){
   reset5b7220();
   if(goal.x!=-1&&(*lb44_cfd44c.at9ced70(goal))->entity45d250().valid9b7230()&&(*lb44_cfd44c.at9ced70(goal))->entity45d250().get9b6570()->hostile45aa70(entity)&&(lb44_d1e860.mode46f4b0(1)||lb44_d1e888.get9b7910()->type==23)&&!active){
    lb44_cf6428.target6906d0((*lb44_cfd44c.at9ced70(goal))->entity45d250());
    if(lb44_d1e888.get9b7910()->type!=13){
     bool blocked=true;vector<LB44P*>*points=lb44_cefc4c->points462e10();
     for(unsigned i=0;i<points->size();i++)if(lb44_cefc4c->clear716940(entity.get9b6570()->pos45a4a0(),*(*points)[i],entity.get9b6570(),0)){blocked=false;break;}
     if(blocked){
      switch(lb44_d1e888.get9b7910()->type){
       case 28:if(entity.get9b6570()->type45a2a0()==2&&entity.get9b6570()->faction45a2c0()==21&&!lb44_d1ebee){
        lb44_cf6428.launch687520(LB44HE(),&goal,false);lb44_cf6428.launch687520(LB44HE(),&goal,false);
        do{lb44_cf1080.set451400(1);if(1&&!(lb44_d28fb0&&1&&1))lb44_sound4541b0(295,0,0);LB44_MSG(0x324,&string("ALERT: Weapon containment endangered. Dispatching heavy reinforcements to area."),LB44HE(),LB44HE());lb44_cec0b4->end7b4f10();}while(false);lb44_d1ebee=true;
       }break;
       case 34:if(entity.get9b6570()->pos45a4a0().x>=135&&lb44_cefc4c->clear716940(entity.get9b6570()->pos45a4a0(),LB44P(153,77),entity.get9b6570(),0))blocked=false;break;
      }
     }
     if(blocked)lb44_cf6428.remove690750((*lb44_cfd44c.at9ced70(goal))->entity45d250());
    }
    if(entity.get9b6570()->faction45a2c0()==96&&!lb44_d1ec74.empty()&&rng.chance(10)&&!lb44_cefc4c->clear716940(entity.get9b6570()->pos45a4a0(),lb44_d1ec74[0].center40b620(),entity.get9b6570(),0)&&lb44_cefc4c->allow748a00(0,0))return 0;
   }
   goal.x=-1;return 1;
  }
 }
 if(lb44_adjacent4373c0(entity.get9b6570()->pos45a4a0(),goal)&&(entity.get9b6570()->wall5c8710(goal)||entity.get9b6570()->occupied5c85a0(goal,true))){if(entity.get9b6570()->wall5c8710(goal))reset5b7220();goal.x=-1;return 2;}
 if(state==4){
  LB44HE h;
  if(other.get9b6570()&&other.get9b6570()->target45a760())h=other;
  else if(has459090()&&part4590f0()->mod458950(8)&&part4590f0()->mod458950(7))h=part4590f0()->mod458950(7)->entity;
  if(h.get9b6570()&&entity.get9b6570()->moveOther5c8820(h)){
   bool moved=false;
   for(unsigned i=1;i<path.size();i++)if((*lb44_cfd44c.at9ced70(path[i]))->pass66ab30(LB44HE())&&(*lb44_cfd44c.at9ced70(path[i]))->entity45d250().null9b65d0()){h.get9b6570()->pos5dccb0(path[i],true);moved=true;break;}
   if(!moved)return 2;else{LB44_MSG(0x251,&h.get9b6570()->name416f40(),entity,LB44HE());}
  }
 }
 int steps=1;
 if(entity.get9b6570()->wall5c8710(path.front())||entity.get9b6570()->occupied5c85a0(path.front(),true)){
  bool found=false;bool skip=false;
  if(!active&&entity.get9b6570()->occupied5c85a0(path.front(),false)){
   LB44HE first=(*lb44_cfd44c.at9ced70(path.front()))->entity45d250();
   if(level<6&&first.get9b6570()->ai45b590()&&first.get9b6570()->ai45b590()->level<6)goto skipPath;
   if(entity.get9b6570()->mode5d1390()==4&&!entity.get9b6570()->active45a780()&&((*lb44_cfd44c.at9ced70(path.back()))->entity45d250().null9b65d0()||!(*lb44_cfd44c.at9ced70(path.back()))->entity45d250().get9b6570()->hostile45aa70(entity)))goto skipPath;
   if(level>=6&&entity.get9b6570()->friendly45aaa0(first)&&!first.get9b6570()->player5c7600()&&first.get9b6570()->size45a360()==1&&!(first.get9b6570()->faction45a2c0()==48&&first.get9b6570()->target45a760()==6&&first.get9b6570()->friendly45aaa0(lb44_cefc4c->player4630f0()))&&!(first.get9b6570()->def9b4350()==lb44_cefc10&&(*lb44_cfd44c.at9ced70(first.get9b6570()->pos45a4a0()))->item45d8f0().valid9b7230()&&(*lb44_cfd44c.at9ced70(first.get9b6570()->pos45a4a0()))->item45d8f0().get9b65b0()->special457f90()==209&&first.get9b6570()->friendly45aaa0(lb44_cefc4c->player4630f0()))){
    bool force=false;
    if(first.get9b6570()->ai45b590()->level<6)force=true;
    else if(!first.get9b6570()->ai45b590()->wait459030()&&first.get9b6570()->ai45b590()->turn45ad90()+3<lb44_cefc4c->turn464270()){
     if(first.get9b6570()->ai45b590()->follow458ed0()==entity)force=true;
     else if(rng.chance(target.valid9b7230()?(target==first?80:66):33))return 2;
     else force=true;
    }
    if(force)goto moveEntity;
   }
   if(!lb44_cefc4c->near4631f0(entity)&&!lb44_cefc4c->observed714920(entity.get9b6570()->pos45a4a0(),entity)&&lb44_distance40a3f0(path.front(),lb44_cefc4c->player4630f0().get9b6570()->pos45a4a0())>15||lb44_cefb0a){skip=level>=6;goto skipPath;}
  }
  {
   vector<LB44P>points;LB44P first,maxScore;
   lb44_cfd44c.bounds9b79c0(entity.get9b6570()->pos45a4a0(),2,entity.get9b6570()->definition->size+2,&first,&maxScore);
   for(int x=first.x;x<=maxScore.x;x++)for(int y=first.y;y<=maxScore.y;y++)if((*lb44_cfd44c.at9ceda0(x,y))->entity45d250().valid9b7230()&&(*lb44_cfd44c.at9ceda0(x,y))->entity45d250()!=entity&&(!active||(*lb44_cfd44c.at9ceda0(x,y))->entity45d250().get9b6570()->size45a360()>1)&&goal.different409cf0(x,y)){
    (*lb44_cfd44c.at9ceda0(x,y))->hide45db10();points.push_back(LB44P(x,y));
   }
   found=find5b8d20();for(unsigned i=0;i<points.size();i++)(*lb44_cfd44c.at9ced70(points[i]))->show45db30();
  }
  if(!found){
   if(entity.get9b6570()->candidate5d51a0()){
    vector<LB44HE>nearby;entity.get9b6570()->nearby5c8880(&nearby);
    for(unsigned i=0;i<nearby.size();i++)if(nearby[i].get9b6570()->hostile45aa70(entity))score5b5260(nearby[i],30);
   }
   skip=(level<6&&!active)?0:1;
   if(!find5b8d20()){reset5b7220();goal.x=-1;return 2;}
 skipPath:
  steps++;lb44_erase9d5190(path,0);
  while(!path.empty()){
   if(entity.get9b6570()->wall5c8710(path.front()))path.clear();
   else if(entity.get9b6570()->occupied5c85a0(path.front(),false))lb44_erase9d5190(path,0);
   else break;
  }
  if(path.empty()||(skip&&(lb44_cefc4c->near4631f0(entity)||lb44_cefc4c->visible4631c0(path.front())||lb44_cefc4c->observed714920(entity.get9b6570()->pos45a4a0(),entity)||lb44_distance40a3f0(path.front(),lb44_cefc4c->player4630f0().get9b6570()->pos45a4a0())<=15))){goal.x=-1;return 2;}
  }
 }
 if(entity.get9b6570()->occupied5c85a0(path.front(),true))return 2;
 if(active&&entity.get9b6570()->occupied5c85a0(path.front(),false)){LB44View grid;if(!entity.get9b6570()->multi5ddf50(path.front(),&grid,0))return 2;}
 moveEntity:
 entity.get9b6570()->flag40=0;bool count=step581a00(true);LB44HE old=entity;
 *out=entity.get9b6570()->move63d8a0(path.front(),steps,false);
 if(old.get9b6570()&&old.get9b6570()->pos45a4a0()==path.front()){
  lb44_erase9d5190(path,0);
  if(count&&follow.get9b6570()){
   LB44P from(follow.get9b6570()->pos45a4a0());LB44P dest(entity.get9b6570()->pos45a4a0());int i=lb44_direction4374c0(from,dest);from+=lb44_d015d8[i];
   if((*lb44_cfd44c.at9ced70(from))->entity45d250().null9b65d0()&&(*lb44_cfd44c.at9ced70(from))->pass66ab30(LB44HE())){LB44_MSG(0x24d,&entity.get9b6570()->name416f40(),follow,LB44HE());follow.get9b6570()->pos5dccb0(from,true);}
  }
 }
 return 0;
}
