// NOTE: private borrowed BS views and genuine allocated EntityAI/native owners for6e0eb0.
#include <string>
#include <vector>
#include "rng.h"
using std::string;using std::vector;extern RNG rng;
struct LB40P{int x,y;LB40P()throw();LB40P(int)throw();LB40P(int,int)throw();LB40P(const LB40P&)throw();LB40P&operator=(const LB40P&)throw();void set40a010(int,int)throw();};
struct LB40Rect{int x,y,w,h;LB40Rect(int,int,int,int)throw();LB40Rect(const LB40Rect&)throw();LB40P center40ad40()throw();int right40ac20()throw();int bottom40ac40()throw();bool contains40aa00(const LB40P&)throw();void random40b000(LB40P*)throw();};
struct LB40Area{LB40P min,max;LB40Area(const LB40Rect&)throw();};
struct LB40Def;struct LB40Talk;struct LB40Terrain;struct LB40AI;
struct LB40Entity{const LB40P&pos45a4a0()throw();void rename45b070(const string&);void talk6395d0(LB40Talk*,bool);bool talk6396a0(const string&,bool);void set64ecf0(LB40AI*);LB40AI*ai45b590()throw();};
struct LB40HE{int id;LB40HE()throw();LB40Entity*get9b6570()const throw();bool null9b65d0()const throw();};
struct LB40Item{void remove57dbe0(bool,bool,int,bool);};struct LB40HI{int id;bool valid9b7230()const throw();LB40Item*get9b65b0()const throw();};
struct LB40Prop{void position45cc50(const LB40P&)throw();struct LB40PropDef*type9b8f00()throw();void remove45ce10(bool,int,bool,LB40HE);};struct LB40HP{int id;LB40HP()throw();bool null9b65d0()const throw();bool valid9b7230()const throw();LB40Prop*get9b64f0()const throw();};
struct LB40Cell{LB40HE entity45d250()throw();LB40HP prop45d550()throw();LB40HI item45d8f0()throw();bool pass66ab30(LB40HE);void set45df50(LB40HP)throw();};struct LB40Grid{int width,height;LB40Cell**data;LB40Cell**point9cf7d0(LB40P&)throw();LB40Cell**at9ceda0(int,int)throw();};extern LB40Grid lb40_cfd44c;
struct LB40MoveCost;struct LB40Cartographer{bool find40c9a0(const LB40P&,const LB40P&,LB40MoveCost*,void*,vector<LB40P>&);};extern LB40Cartographer lb40_cfe568;extern LB40MoveCost*lb40_cefc30;
struct LB40Factory{LB40HP prop793360(struct LB40PropDef*);};extern LB40Factory*lb40_cefaa8;extern struct LB40PropDef*lb40_cefbd8;
void lb40_surround4faaf0(const LB40P&,vector<LB40P>&);void lb40_adjacent4fab80(const LB40P&,vector<LB40P>&);int lb40_max9cdb60(int,int);bool lb40_terrain448b80(const LB40P&);
struct LB40Weights{vector<LB40Def*>values;vector<int>weights;int total;LB40Weights();~LB40Weights();void add9ba310(LB40Def*,int);unsigned count9b81d0()const throw();LB40Def*&pick9ba470()throw();};
struct LB40TalkWeights{vector<LB40Talk*>values;vector<int>weights;int total;LB40TalkWeights();~LB40TalkWeights();void add9ba310(LB40Talk*,int);unsigned count9b81d0()const throw();LB40Talk*&pick9ba470()throw();void remove9bab80(LB40Talk*);};
struct LB40Def{char omitted0[0x140];int index;};struct LB40Talk{LB40Talk();~LB40Talk();int unknown0;string name;char omitted20[0xa0];vector<LB40Def*>defs;};struct LB40EventDef{LB40EventDef();~LB40EventDef();char omitted0[0x7c];string name;int unknown98,weight;};
extern vector<LB40Def*>lb40_d25de0;extern vector<LB40Talk*>lb40_d2c408;extern vector<int>lb40_cf4934;extern vector<LB40EventDef*>lb40_cf3a20;extern const string lb40_d292f4;extern LB40Terrain*lb40_d2c46c;
bool lb40_find9d7530(vector<LB40Def*>&,const string&,LB40Def*&);
struct LB40Tracked{int id;LB40Tracked();};struct LB40Order;struct LB40Pending;struct LB40Target{LB40HE entity;int unknown4,score;};
struct LB40AI{LB40HE entity;int type,mode,unknownC;LB40P goal,point18;LB40Tracked h20;vector<LB40P>route;int unknown34,unknown38,unknown3c;LB40Tracked h40;int unknown44,unknown48,unknown4c;LB40Tracked h50;bool flag54,flag55,flag56;LB40HE follow;bool flag5c;int param,counter,unknown68;vector<LB40P>path;bool flag7c;LB40Area area;vector<LB40P>points90;int unknowna0;LB40Area other;LB40HE target;LB40Tracked hb8;int unknownbc,unknownc0,unknownc4,unknownc8,unknowncc,unknownd0;LB40Tracked hd4;int unknownd8;vector<LB40HE>remembered;int rememberedTurn;vector<LB40Target*>targets;int unknown100,unknown104,targetCounter,unknown10c;bool flag110;LB40Order*order;void*owned118;LB40Pending*owned11c;vector<struct LB40OwnedRecord*>owned120;LB40AI(LB40HE,int,int);~LB40AI();void area459470(const LB40Area&)throw();};
struct LB40World{char omitted0[8];LB40P position;char omitted10[0x65c];LB40HE player;void populate6e0eb0(vector<LB40P>&,vector<LB40Rect>&,vector<bool>&);void terrain6c38a0(LB40Rect&,int,float,LB40Terrain*);bool near71c150(const LB40P&,LB40P&,int);LB40HE spawn6c58c0(LB40Def*,const LB40P&,int,bool,int,int,bool);LB40HE spawn6c5dc0(const string&,const LB40P&,int,bool,int,int,bool);bool dialogue6c65a0(LB40HE,const string&,bool);};extern LB40World*lb40_cefc4c;
extern vector<int>lb40_d1ea7c;extern int lb40_d1e888;extern vector<string>lb40_d1ea8c;bool lb40_contains9d31e0(vector<int>&,int);int lb40_index9d3110(vector<int>&,int);
static_assert(sizeof(LB40AI)==304&&sizeof(LB40Weights)==36&&sizeof(LB40Rect)==16,"genuine native owners and scalar fields");
void LB40World::populate6e0eb0(vector<LB40P>&points,vector<LB40Rect>&rects,vector<bool>&enabled){
 vector<vector<LB40P> >routes;
 for(unsigned i=0;i<rects.size();i++){
  routes.push_back(vector<LB40P>());if(!enabled[i]){routes.back().push_back(LB40P(-1));continue;}
  LB40P pos(-1);
  if((*lb40_cfd44c.point9cf7d0(rects[i].center40ad40()))->pass66ab30(LB40HE()))pos=rects[i].center40ad40();
  else{for(int x=rects[i].x;x<=rects[i].right40ac20();x++)for(int y=rects[i].y;y<=rects[i].bottom40ac40();y++)if((*lb40_cfd44c.at9ceda0(x,y))->pass66ab30(LB40HE())){pos.set40a010(x,y);goto found;}}
 found:if(pos.x==-1)routes.back().push_back(LB40P(-1));else if(!lb40_cfe568.find40c9a0(pos,position,lb40_cefc30,0,routes.back()))routes.back().push_back(LB40P(-1));
 }
 LB40HP prop;
 for(unsigned i=0;i<points.size();i++){
  if((*lb40_cfd44c.point9cf7d0(points[i]))->prop45d550().null9b65d0()&&(*lb40_cfd44c.point9cf7d0(points[i]))->entity45d250().null9b65d0()){
   for(unsigned j=0;j<rects.size();j++)if(!enabled[j]&&rects[j].contains40aa00(points[i]))goto skipProp;
   prop=lb40_cefaa8->prop793360(lb40_cefbd8);(*lb40_cfd44c.point9cf7d0(points[i]))->set45df50(prop);prop.get9b64f0()->position45cc50(points[i]);
   if((*lb40_cfd44c.point9cf7d0(points[i]))->item45d8f0().valid9b7230())(*lb40_cfd44c.point9cf7d0(points[i]))->item45d8f0().get9b65b0()->remove57dbe0(false,false,1,true);
  }skipProp:;
 }
 vector<LB40P>nearby;
 for(unsigned i=0;i<routes.size();i++)if(routes[i].front().x!=-1)for(int j=0;static_cast<unsigned>(j)<routes[i].size()&&j<lb40_max9cdb60(rects[i].w,rects[i].h)*1.5;j++){
  nearby.clear();lb40_surround4faaf0(routes[i][j],nearby);for(unsigned k=0;k<nearby.size();k++)if((*lb40_cfd44c.point9cf7d0(nearby[k]))->prop45d550().valid9b7230()&&(*lb40_cfd44c.point9cf7d0(nearby[k]))->prop45d550().get9b64f0()->type9b8f00()==lb40_cefbd8)(*lb40_cfd44c.point9cf7d0(nearby[k]))->prop45d550().get9b64f0()->remove45ce10(true,0,true,LB40HE());
 }
 for(unsigned i=0;i<rects.size();i++)terrain6c38a0(rects[i],0,1.0f,lb40_d2c46c);
 LB40Rect area(30,0,75,130);LB40Def*found;LB40Weights weights;
 if(lb40_find9d7530(lb40_d25de0,"Zionite",found))weights.add9ba310(found,94);
 if(lb40_find9d7530(lb40_d25de0,"Tinkerer",found))weights.add9ba310(found,1);
 if(lb40_find9d7530(lb40_d25de0,"Surgeon_4",found))weights.add9ba310(found,1);
 if(lb40_find9d7530(lb40_d25de0,"Thug_5",found))weights.add9ba310(found,1);
 if(lb40_find9d7530(lb40_d25de0,"Savage_5",found))weights.add9ba310(found,1);
 if(lb40_find9d7530(lb40_d25de0,"Butcher_5",found))weights.add9ba310(found,1);
 if(lb40_find9d7530(lb40_d25de0,"Mutant_5",found))weights.add9ba310(found,1);
 if(weights.count9b81d0()){
  int count=25,weight=15;LB40P group;LB40TalkWeights allies;vector<LB40P>first;LB40Talk*room;
  for(unsigned i=0;i<lb40_d2c408.size();i++)if(lb40_d2c408[i]->name.find(lb40_d292f4+"ZIO")!=string::npos&&!lb40_cf4934[lb40_d2c408[i]->defs.front()->index])allies.add9ba310(lb40_d2c408[i],lb40_cf3a20[lb40_d2c408[i]->defs.front()->index]->weight);
  for(int i=0,num=0;i<25;i++,num++){
   room=allies.count9b81d0()&&num<15?allies.pick9ba470():0;if(room)allies.remove9bab80(room);bool restricted=room&&!lb40_cf3a20[room->defs.front()->index]->name.empty();
   for(int j=500;j>0;j--){area.random40b000(&group);if(near71c150(group,group,1)){
    first.clear();lb40_adjacent4fab80(group,first);int walls=0;for(unsigned k=0;k<first.size();k++)if(!(*lb40_cfd44c.point9cf7d0(first[k]))->pass66ab30(LB40HE()))walls++;
    if((restricted&&walls!=1)||walls==4)continue;
    LB40HE e;e=spawn6c58c0(weights.pick9ba470(),group,8,true,34,14,false);
    if(room){e.get9b6570()->talk6395d0(room,false);lb40_cf4934[room->defs.front()->index]=1;if(restricted)e.get9b6570()->set64ecf0(new LB40AI(e,1,14));}break;
   }}
  }
 }
 if(rng.chance(10)){if(lb40_find9d7530(lb40_d25de0,"Explorer",found)){LB40P pos;for(int j=500;j>0;j--){area.random40b000(&pos);if(near71c150(pos,pos,1)&&!lb40_terrain448b80(pos)){LB40HE e=lb40_cefc4c->spawn6c58c0(found,pos,8,true,34,14,false);e.get9b6570()->talk6396a0("AUTO_ZIO_UFD_EXPLORER",false);break;}}}}
 if(!lb40_d1ea7c.empty()&&lb40_contains9d31e0(lb40_d1ea7c,lb40_d1e888)){
  int state=lb40_index9d3110(lb40_d1ea7c,lb40_d1e888);LB40HE e=spawn6c5dc0("Zionite",player.get9b6570()->pos45a4a0(),8,true,34,14,false);
  e.get9b6570()->rename45b070(lb40_d1ea8c[state]);dialogue6c65a0(e,"ZIO_Shortcut_Arrive",false);e.get9b6570()->ai45b590()->area459470(area);
 }
}
