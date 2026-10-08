#include <string>
#include <memory>
#include "rng.h"
using std::string;extern RNG rng;
// NOTE: private partial retail views; all collection and adopted-child operations are real external helpers.
template<class T>struct D30Vec{T*first,*last,*capacity;std::allocator<T>allocator;bool empty9b86e0()const throw();T&front9b7060()throw();T&at9b81f0(unsigned)throw();};
struct D30Weights{D30Vec<int>values,weights;int total;D30Weights();~D30Weights();void add9ba310(int,int);int&pick9ba470();};
struct D30P{int x,y;D30P(int)throw();D30P(int,int)throw();};struct D30Rect{int x,y,w,h;D30Rect(int,int,int,int)throw();};
struct D30Color{unsigned char r,g,b;D30Color(const D30Color&)throw();};
struct D30EffectDef; // borrowed real definition, consumed by effect initialization
struct D30Console{virtual~D30Console();virtual void resize(int,int);char pad4[0x68];int height4174c0()throw();int width44b0d0()throw();void pos417a90(int,int);void back418410(D30Color);void put4180b0(int,int,int);int char417650(int,int);int wrap418260(int,int,int,int,const string&);void animate48c3f0(string);void effect48c460(D30EffectDef*,const D30P&);};
struct D30Fx:D30Console{int type;D30Fx(D30Console*,const D30Rect&,int);};
struct D30Frame{int width9fcd80()throw();int height9b8f00()throw();};
struct D30Image{D30Vec<D30Frame*>layers;D30Image();~D30Image();bool empty9b81b0()throw();D30Frame*&front9b7060()throw();};
struct D30Art:D30Console{D30Image image;D30P offset;D30Art(D30Console*,D30Image*,int,int,bool,int,int,const D30P&,int,int);~D30Art();void draw48cb90(int);};
struct D30Grid{int width9fcd80()throw();int height9b8f00()throw();int*at9ceda0(int,int)throw();};
struct D30Lore{char p0[0x28];int text;};struct D30Topic{char p0[0xc0];D30Vec<D30Lore*>lore;};
struct D30Line{char p0[0x24];int style;string text;};struct D30Style{char p0[0x20];int kind;};
struct D30Text58{char p0[0x58];string text;};struct D30Text2c{char p0[0x2c];D30Vec<string>lines;};struct D30Text170{char p0[0x170];string text;};
struct D30Source{char p0[8];D30Text58*one;D30Text2c*many;void*p10;D30Text170*description;};
struct D30Item{char p0[0x7c];D30Image art;};
struct D30Rex{int width418980()throw();int height4189a0()throw();};extern D30Rex d30_d223f0;
extern D30Vec<D30Topic*>d30_d2c408;extern D30Vec<D30Line*>d30_d2b4d8;extern D30Vec<D30Style*>d30_d35b48;extern D30Vec<D30Source*>d30_d02cb4;extern D30Vec<D30Grid*>d30_d2f108;extern D30Vec<D30Item*>d30_d2d1c4;
extern int d30_caf150;extern const unsigned d30_c2ea48;extern string d30_d1e704;extern D30Color*d30_cfe674;
template<class T>T*d30_random9d5d00(D30Vec<T*>&);
string d30_random9d3280(D30Vec<string>&);bool d30_clean4351e0(string&);string d30_replace510110(string&,bool*);bool d30_lookup9d45a0(const string&,D30EffectDef**);
static_assert(sizeof(D30Vec<int>)==16,"native allocator-aligned vector");
static_assert(sizeof(D30Weights)==36,"real two-vector weighted table");
static_assert(sizeof(D30Fx)==112,"real CEffect instance");
static_assert(sizeof(D30Art)==132,"real ConsoleArt owner plus Point");
struct D30Time:D30Console{void spawn96bf80();};
void D30Time::spawn96bf80(){
 D30Weights table;table.add9ba310(7,45);table.add9ba310(8,10);table.add9ba310(9,45);
 switch(table.pick9ba470()){
 case 7:{
  string type;
  if(rng.chance(15)){
   int tries=0;
   while(true){
    D30Lore*record=d30_random9d5d00(d30_random9d5d00(d30_d2c408)->lore);
    if(record->text!=d30_caf150&&d30_d35b48.at9b81f0(d30_d2b4d8.at9b81f0(record->text)->style)->kind==1){
     type=d30_d2b4d8.at9b81f0(record->text)->text;
     unsigned end=type.find('"');if(end==d30_c2ea48)goto retry;
     unsigned begin=type.find('"',end+1);if(begin==d30_c2ea48)goto retry;
     if(type.find('[')!=d30_c2ea48)goto retry;
     if(end)type.erase(type.begin(),type.begin()+end);
     if(begin<type.size()-1)type.erase(type.begin()+begin+1,type.end());
     break;
retry:if(++tries>=200)goto ordinary;
    }
   }
  }else{
ordinary:while(true){
    bool changed=false;D30Source*record=d30_random9d5d00(d30_d02cb4);
    if(record->one){type=record->one->text;d30_clean4351e0(type);if(type.find(d30_d1e704)!=d30_c2ea48)changed=true;}
    else if(record->many){type=d30_random9d3280(record->many->lines);d30_clean4351e0(type);type=d30_replace510110(type,&changed);}
    else type=record->description->text;
    if(!changed)break;
   }
  }
  int x=rng.rangeInt(30,300);if(type.size()<x)x=type.size();x+=2;
  D30Fx*record=new D30Fx(this,D30Rect(0,0,x,20),7);
  int count=record->wrap418260(1,0,x-2,20,type);record->resize(x,count);record->wrap418260(1,0,x-2,20,type);
  int n=record->height4174c0();record->pos417a90(rng.rangeInt(-5,(d30_d223f0.width418980()-x)/2),rng.rangeInt(n>1?-1:0,d30_d223f0.height4189a0()-n+(n>2?n-2:0)));record->animate48c3f0("A_CEffect_Time_Lore");
  break;}
 case 8:{
  if(!d30_d2f108.empty9b86e0()){
   D30Grid*base=d30_random9d5d00(d30_d2f108);D30Fx*a=new D30Fx(this,D30Rect(0,0,base->width9fcd80(),base->height9b8f00()),8);
   a->pos417a90(rng.rangeInt(-base->width9fcd80()/2,d30_d223f0.width418980()-base->width9fcd80()/2),rng.rangeInt(-base->height9b8f00()/2,d30_d223f0.height4189a0()-base->height9b8f00()/2));a->back418410(*d30_cfe674);
   for(int x=0;x<base->width9fcd80();x++)for(int y=0;y<base->height9b8f00();y++)a->put4180b0(x,y,*base->at9ceda0(x,y));
   a->animate48c3f0("A_CEffect_Time_Map");D30EffectDef* i;
   if(d30_lookup9d45a0("CEffect_Time_Map_Period",&i))for(int x=0;x<base->width9fcd80();x++)for(int y=0;y<base->height9b8f00();y++)if(a->char417650(x,y)=='.')a->effect48c460(i,D30P(x,y));
  }break;}
 case 9:{
  D30Image*base;
  while(true){D30Item*record=d30_random9d5d00(d30_d2d1c4);if(!record->art.empty9b81b0()){base=&record->art;break;}}
  int col=base->front9b7060()->width9fcd80();int v=base->front9b7060()->height9b8f00();
  D30Fx*n=new D30Fx(this,D30Rect(rng.rangeInt(-10,d30_d223f0.width418980()-col/2),rng.rangeInt(-5,d30_d223f0.height4189a0()-v/2),col,v),9);n->animate48c3f0("A_CEffect_Time_Art_T");
  D30Art*a=new D30Art(n,base,0,0,false,-1,-1,D30P(-1),0,0);a->draw48cb90(-1);a->animate48c3f0("A_CEffect_Time_Art");break;}
 }
}
