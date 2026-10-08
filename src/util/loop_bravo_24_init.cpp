#include <string>
#include "rng.h"
using std::string;extern RNG rng;
// NOTE: private partial ABI views, actual owning collections and borrowed metadata pointers.
struct LB24Def;struct LB24Talk;struct LB24Entity;struct LB24AI;struct LB24EffectType;struct CellTerrainRecord;
struct LB24P{int x,y;LB24P();LB24P(int,int)throw();};
struct LB24Rect{LB24P pos;int width,height;LB24Rect();LB24Rect(int,int,int,int)throw();void random40b000(LB24P*)throw();void random40be30(LB24P*)throw();};
struct LB24Area{LB24P min,max;LB24Area(int,int,int,int)throw();void random40be30(LB24P*)throw();};
struct LB24H{int id;LB24H()throw();LB24Entity*get9b6570()const throw();bool valid9b7230()const throw();};
struct LB24Ps{int a,b,c,d;LB24Ps();~LB24Ps();void clear9b3560()throw();unsigned size9b9260()const throw();LB24P&at9e7c10(unsigned)throw();};
template<class T>struct LB24NativeVec{T*begin,*end,*capacity;std::allocator<T>allocator;};
template<class T>struct LB24W{LB24NativeVec<T>values;LB24NativeVec<int>weights;int total;LB24W();~LB24W();void add(T,int);int count9b81d0()const throw();T&pick();void remove(T);};
struct LB24Defs{LB24Def*&at9b81f0(unsigned)throw();LB24Def*&front9b7060()throw();};extern LB24Defs lb24_d25de0;
struct LB24Def{char p[0x140];int index;};
struct LB24Talk{int id;string name;char p20[0xc0-0x20];LB24Defs definitions;};struct LB24Talks{unsigned size9b9260()const throw();LB24Talk*&at9b81f0(unsigned)throw();};extern LB24Talks lb24_d2c408;
struct LB24Info{char p[0x7c];string name;char p98[4];int weight;};struct LB24Infos{LB24Info*&at9b81f0(unsigned)throw();};extern LB24Infos lb24_cf3a20;
struct LB24Ints{int&at9b81f0(unsigned)throw();};extern LB24Ints lb24_cf4934;
struct LB24Types{LB24EffectType*&at9b81f0(unsigned)throw();};extern LB24Types lb24_d2f0f8;
struct LB24EffectPair{LB24EffectType*type;int value;LB24EffectPair(LB24EffectType*,int);};
LB24EffectPair::LB24EffectPair(LB24EffectType*a,int b){type=a;value=b;}
struct LB24AI{char p[0x130];LB24AI(LB24H,int,int);void area459470(const LB24Area&)throw();};
struct LB24Entity{void effect45b340(LB24EffectPair*);void talk6395d0(LB24Talk*,bool);void talk6396a0(const string&,bool);void ai64ecf0(LB24AI*);LB24AI*ai45b590()throw();void name45b070(const string&);void effects639730(bool);};
struct LB24Cell{bool pass66ab30(LB24H)throw();};struct LB24Grid{int height9b8f00()throw();LB24Cell**at9ced70(LB24P&)throw();};extern LB24Grid lb24_cfd44c;
struct LB24Map{void init6e9570();LB24H place6c58c0(LB24Def*,const LB24P&,int,bool,int,int,bool);bool near71c150(const LB24P&,LB24P&,int);LB24H find715230(int,int);void remove465750(LB24H);};extern LB24Map*lb24_cefc4c;
struct LB24Data{const string&get46f6d0(const string&);};extern LB24Data lb24_d1e860;
extern bool lb24_d257ec;extern string lb24_d292f4;extern unsigned lb24_c2ea48;extern CellTerrainRecord*TERRAIN_CAVE_WALL;
bool lb24_find(LB24Defs&,const string&,LB24Def*&);
bool lb24_wall6cbb40(int,int,int,LB24Rect*,LB24Rect*,int*,int,bool,bool);
void lb24_ring6cba00(LB24Rect*,LB24Rect*,int,CellTerrainRecord*,bool);
bool lb24_terrain448b80(const LB24P&)throw();void lb24_adjacent4fab80(const LB24P&,LB24Ps&);int lb24_int405610(const string&);
#define LB24_ADD(NAME,WEIGHT) if(lb24_find(lb24_d25de0,NAME,first))list.add(first,WEIGHT)
void LB24Map::init6e9570(){
 lb24_d257ec=true;LB24Def*current;LB24Def*first;
 if(lb24_find(lb24_d25de0,"Bouncer_7",current)){
  int count=10;LB24Rect b;LB24Rect p;int first;
  for(int i=0;i<10;i++){if(lb24_wall6cbb40(1,1,4,&b,&p,&first,0,false,false)){
   lb24_ring6cba00(&p,&b,0,TERRAIN_CAVE_WALL,false);LB24H pos=place6c58c0(current,LB24P(p.pos.x,p.pos.y),9,true,34,14,false);pos.get9b6570()->effect45b340(new LB24EffectPair(lb24_d2f0f8.at9b81f0(145),1));
  }}
 }
 LB24W<LB24Def*>list;
 LB24_ADD("Thug_7",40);LB24_ADD("Thug_5",10);LB24_ADD("Mutant_8",5);LB24_ADD("Mutant_7",15);LB24_ADD("Mutant_6",5);LB24_ADD("Mutant_5",5);LB24_ADD("Savage_7",8);LB24_ADD("Savage_5",2);LB24_ADD("Butcher_7",8);LB24_ADD("Butcher_5",2);
 if(list.count9b81d0()){
  int p=2;LB24W<LB24Def*>line;
  if(lb24_find(lb24_d25de0,"Surgeon_4",first))line.add(first,50);if(lb24_find(lb24_d25de0,"Surgeon_6",first))line.add(first,50);
  int type=27;int valid=10;LB24Rect f(0,0,53,75);LB24P active;
  LB24W<LB24Talk*>a;LB24Ps value;LB24Talk*index;
  for(unsigned i=0;i<lb24_d2c408.size9b9260();i++)if(lb24_d2c408.at9b81f0(i)->name.find(lb24_d292f4+"WAR",0)!=lb24_c2ea48&&!lb24_cf4934.at9b81f0(lb24_d2c408.at9b81f0(i)->definitions.front9b7060()->index))a.add(lb24_d2c408.at9b81f0(i),lb24_cf3a20.at9b81f0(lb24_d2c408.at9b81f0(i)->definitions.front9b7060()->index)->weight);
  for(int i=0,j=0;i<27;i++,j++){
   index=a.count9b81d0()&&j<10?a.pick():0;if(index)a.remove(index);
   bool seen=index&&!lb24_cf3a20.at9b81f0(index->definitions.front9b7060()->index)->name.empty();
   for(int n=500;n>0;n--){
    f.random40b000(&active);if(near71c150(active,active,1)&&!lb24_terrain448b80(active)){
     if(seen){value.clear9b3560();lb24_adjacent4fab80(active,value);int count=0;for(unsigned i=0;i<value.size9b9260();i++)if(!(*lb24_cfd44c.at9ced70(value.at9e7c10(i)))->pass66ab30(LB24H()))count++;if(count!=1)continue;}
     LB24H f;f=place6c58c0(i<25?list.pick():line.pick(),active,9,true,34,14,false);
     if(index){f.get9b6570()->talk6395d0(index,false);lb24_cf4934.at9b81f0(index->definitions.front9b7060()->index)=1;if(seen){f.get9b6570()->ai64ecf0(new LB24AI(f,1,14));f.get9b6570()->effect45b340(new LB24EffectPair(lb24_d2f0f8.at9b81f0(145),1));}}
     break;
    }
   }
  }
 }
 if(rng.chance(33)){
  LB24Def*data;if(lb24_find(lb24_d25de0,"LV-01A",data)){
   LB24Area p(0,0,45,lb24_cfd44c.height9b8f00()-1);LB24P pos;
   for(int n=500;n>0;n--){p.random40be30(&pos);if(near71c150(pos,pos,1)&&!lb24_terrain448b80(pos)){
    LB24H f=lb24_cefc4c->place6c58c0(data,pos,9,true,34,14,false);f.get9b6570()->ai45b590()->area459470(p);f.get9b6570()->talk6396a0("AUTO_WAR_LV01A",false);f.get9b6570()->talk6396a0("WAR_LV01A_Muttering",false);break;
   }}
  }
 }
 if(rng.chance(15)){if(lb24_find(lb24_d25de0,"Explorer",first)){
  LB24Rect p(0,0,53,75);LB24P pos;
  for(int n=500;n>0;n--){p.random40b000(&pos);if(near71c150(pos,pos,1)&&!lb24_terrain448b80(pos)){
   LB24H f=lb24_cefc4c->place6c58c0(first,pos,9,true,34,14,false);f.get9b6570()->name45b070(string("KTG-V3"));f.get9b6570()->talk6396a0("WAR_Great_Nut_Preacher",false);break;
  }}
 }
 }
 if(lb24_int405610(lb24_d1e860.get46f6d0("installedRif_g"))){LB24H f=find715230(9,91);if(f.valid9b7230()){remove465750(f);f.get9b6570()->effects639730(true);}}
}
