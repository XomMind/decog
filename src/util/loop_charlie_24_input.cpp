// NOTE: private partial layouts and external call-site aliases for inventory input8a5c50.
#include <string>
#include <vector>
using namespace std;
struct LC24Point{int x,y;LC24Point(int)throw();LC24Point(int,int)throw();LC24Point(const LC24Point&)throw();};
struct LC24Color{unsigned char r,g,b;LC24Color()throw();LC24Color(int,int,int)throw();LC24Color(const LC24Color&)throw();LC24Color&operator=(LC24Color)throw();};
struct LC24XCell{int font,glyph,value;LC24Color fore,back;};
struct LC24Buffer{int width,height;LC24XCell*data;LC24Buffer();~LC24Buffer();};
struct LC24Event;
struct LC24XConsole{virtual ~LC24XConsole();virtual void resize(int,int);virtual bool active();virtual void refresh();virtual bool input(LC24Event*);virtual void mouse(int,int);virtual void update();virtual void render();
 LC24XConsole*parent;LC24Buffer buffer;int font,fontType;LC24Point position,absolutePosition;LC24Color foreground,background;int backFlag,alignment;float scaleX,scaleY;vector<LC24XConsole*>children;bool hidden;int layer;bool passThrough,ignoreMouse;
 void remove(LC24XConsole*);void reset();void fore(LC24Color);void back(LC24Color);void enable(int);void print(int,int,const string&);int width()throw();LC24Point absolute(LC24Point)throw();void row(int,int,int,LC24Color);void rect(int,int,int,int,LC24Color);void put(int,int,int,LC24Color,LC24Color,int);};
struct LC24Engine;struct LC24Title;struct LC24Rect;
struct LC24Console:LC24XConsole{virtual ~LC24Console();virtual void resize(int,int);virtual bool input(LC24Event*);virtual void update();virtual void render();virtual void open();virtual void close();virtual int frameKind();virtual void trigger(const string&,int);int state;LC24Engine*engine;LC24Title*title;LC24Console(LC24XConsole*,int,int,int,int,int,bool,int);void frame(LC24Rect*,LC24Color,bool,bool);void baseRender();};
static_assert(sizeof(LC24XCell)==20&&sizeof(LC24XConsole)==0x60&&sizeof(LC24Console)==0x6c,"actual console owners/layout");

struct LC24Rect{int x,y,w,h;LC24Rect(int,int,int,int)throw();};
struct LC24Item;struct LC24Entity;
struct LC24HI{int id;LC24HI()throw();LC24Item*get9b65b0()const throw();bool valid9b7230()const throw();};
struct LC24H{int id;LC24H()throw();LC24Entity*get9b6570()const throw();};
struct LC24Item{int type44aec0()throw();int index457820()throw();int rank457840()throw();int has457b70(int);};
struct LC24Entity{vector<LC24HI>*items45ab00()throw();};
struct LC24Map{LC24H player4630f0()throw();bool blocked71bbd0();};extern LC24Map*lc24_cefc4c;
struct LC24Row:LC24Console{LC24HI item;};
struct LC24Button:LC24Console{unsigned tick;unsigned char reversed;};
struct LC24Buttons:LC24Console{vector<LC24Button*>buttons;};
struct LC24ModeReport:LC24Console{unsigned tick;~LC24ModeReport();LC24ModeReport(LC24XConsole*,const LC24Rect&,string);};
struct LC24Info:LC24Console{bool hidden4175f0()throw();LC24HI selected4aebc0()throw();void show8b4500(LC24H,LC24HI,LC24H,const LC24Point*,int,bool);};extern LC24Info*lc24_cec11c;
struct LC24Parts{bool swap89c350(LC24HI,int);};extern LC24Parts*lc24_cec088;
extern bool lc24_cefa5f;extern int lc24_cefc90;extern unsigned lc24_caed20;extern vector<int>lc24_cf4830;
int lc24_sound4541b0(unsigned,int,int);void lc24_sort8a2a40(vector<LC24HI>&);
void lc24_erase9da940(vector<LC24HI>&,int);void lc24_step9d6440(vector<LC24HI>&,int&);void lc24_insert9d8fc0(vector<LC24HI>&,unsigned,LC24HI);void lc24_append9d49c0(vector<LC24HI>&,vector<LC24HI>&);void lc24_prepend9e2fc0(vector<LC24HI>&,vector<LC24HI>&);
struct LC24Event{int type;};
struct LC24Inventory:LC24Console{bool mode;unsigned tick;vector<LC24Row*>records;int a,b;LC24Row*r0,*r1;LC24HI selected;LC24Buttons*buttons;LC24ModeReport*report;
 bool hidden4175f0()throw();bool base429d00(LC24Event*);int height4174c0()throw();void reset8a53c0();void prev8a29b0();void next8a2930();void reopen8a2ce0(int,LC24HI);void clear4aa7c0();bool equip8a3f20(LC24HI,bool,int,bool);int select8a4ec0(LC24HI,bool);bool input8a5c50(LC24Event*);
};
#define ORDER(V,CMP,ICMP,F,N) {vector<LC24HI>V;V.push_back(i.back());i.pop_back();while(!i.empty()){if(V.back().get9b65b0()->F() CMP i.back().get9b65b0()->F()){V.push_back(i.back());i.pop_back();}else{for(unsigned N=0;N<V.size();N++){if(i.back().get9b65b0()->F() ICMP V[N].get9b65b0()->F()){lc24_insert9d8fc0(V,N,i.back());i.pop_back();break;}}}}i=V;}
bool LC24Inventory::input8a5c50(LC24Event*event){
 if(hidden4175f0()||lc24_cefa5f)return false;
 if(base429d00(event))return true;
 if(lc24_cefc4c->blocked71bbd0())return false;
 switch(event->type){
 case 0x121:reset8a53c0();return true;
 case 0x122:if(lc24_cefc90==1)reset8a53c0();else prev8a29b0();return true;
 case 0x123:if(lc24_cefc90==1)reset8a53c0();else next8a2930();return true;
 case 0x124:if(lc24_cefc90==1)reset8a53c0();else reopen8a2ce0(2,LC24HI());return true;
 case 0x125:if(lc24_cefc90==1)reset8a53c0();else reopen8a2ce0(3,LC24HI());return true;
 case 0x126:{
  if(!lc24_cec11c->hidden4175f0()&&lc24_cec11c->selected4aebc0().valid9b7230())return true;
  if(lc24_cefc90==1){reset8a53c0();return true;}
  vector<LC24HI>temp;vector<LC24HI>*base=lc24_cefc4c->player4630f0().get9b6570()->items45ab00();vector<LC24HI>i(*base);vector<LC24HI>p;
  base->clear();
  for(int current=i.size()-1;current>=0;current--){if(i[current].get9b65b0()->type44aec0()!=4){base->push_back(i[current]);lc24_erase9da940(i,current);}}
  bool count=false;unsigned char group=false;LC24Button*x=buttons->buttons.front();
  if(lc24_caed20<x->tick+1000)group=!x->reversed;
  x->tick=lc24_caed20;x->reversed=group;
  if(!group){clear4aa7c0();report=new LC24ModeReport(this,LC24Rect(14,height4174c0()-1,13,1)," TYPE SORTED ");
   if(!i.empty())ORDER(group,<,<=,index457820,j)
   lc24_sort8a2a40(i);p=i;count=true;
  }else{clear4aa7c0();report=new LC24ModeReport(this,LC24Rect(14,height4174c0()-1,21,1)," REVERSE-TYPE SORTED ");
   if(!i.empty())ORDER(group,>,>=,index457820,j)
   lc24_sort8a2a40(i);p=i;count=false;
  }
  if(count){i.clear();for(int j=0;static_cast<unsigned>(j)<p.size();j++){if(p[j].get9b65b0()->has457b70(86)){i.push_back(p[j]);lc24_step9d6440(p,j);}}
   if(!i.empty()){if(!i.empty())ORDER(group,<,<=,index457820,j)lc24_append9d49c0(p,i);}
  }else{i.clear();for(int j=0;static_cast<unsigned>(j)<p.size();j++){if(p[j].get9b65b0()->has457b70(86)){i.push_back(p[j]);lc24_step9d6440(p,j);}}
   if(!i.empty()){if(!i.empty())ORDER(group,>,>=,index457820,j)lc24_prepend9e2fc0(p,i);}
  }
  if(count){i.clear();for(int j=0;static_cast<unsigned>(j)<p.size();j++){if(lc24_cf4830[p[j].get9b65b0()->index457820()]==0){i.push_back(p[j]);lc24_step9d6440(p,j);}}
   if(!i.empty()){if(!i.empty())ORDER(group,<,<=,rank457840,j)lc24_append9d49c0(p,i);}
  }else{i.clear();for(int j=0;static_cast<unsigned>(j)<p.size();j++){if(lc24_cf4830[p[j].get9b65b0()->index457820()]==0){i.push_back(p[j]);lc24_step9d6440(p,j);}}
   if(!i.empty()){if(!i.empty())ORDER(group,>,>=,rank457840,j)lc24_prepend9e2fc0(p,i);}
  }
  lc24_append9d49c0(*base,p);lc24_sound4541b0(41,0,0);reopen8a2ce0(0,LC24HI());return true;
 }
case 0x12c: case 0x12d: case 0x12e: case 0x12f: case 0x130: case 0x131: case 0x132: case 0x133: case 0x134: case 0x135:if(records.size()>=static_cast<unsigned>(event->type-0x12b)){lc24_cec11c->show8b4500(LC24H(),records[event->type-0x12c]->item,LC24H(),&LC24Point(-1),0,false);}return true;
case 0x136: case 0x137: case 0x138: case 0x139: case 0x13a: case 0x13b: case 0x13c: case 0x13d: case 0x13e: case 0x13f:if(records.size()>=static_cast<unsigned>(event->type-0x135)){equip8a3f20(records[event->type-0x136]->item,false,32,false);}return true;
case 0x140: case 0x141: case 0x142: case 0x143: case 0x144: case 0x145: case 0x146: case 0x147: case 0x148: case 0x149:if(records.size()>=static_cast<unsigned>(event->type-0x13f)){select8a4ec0(records[event->type-0x140]->item,true);}return true;
case 0x14a: case 0x14b: case 0x14c: case 0x14d: case 0x14e: case 0x14f: case 0x150: case 0x151: case 0x152: case 0x153:if(records.size()>=static_cast<unsigned>(event->type-0x149)){lc24_cec088->swap89c350(records[event->type-0x14a]->item,32);}return true;
 }return false;
}
