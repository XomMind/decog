#include <string>
#include <vector>
using namespace std;
struct LC16Point{int x,y;LC16Point(int,int)throw();LC16Point(const LC16Point&)throw();void assign46ca50(const LC16Point&)throw();};
struct LC16Handle{int id;LC16Handle()throw();void reset9b7270()throw();};
struct LC16Def;struct LC16Engine;
struct LC16Effect{bool init50de10(LC16Engine*,LC16Def*,const LC16Point&,const LC16Point&,const LC16Point*,const LC16Point*,int);};
struct LC16Engine{LC16Effect*new50fb50();};
struct LC16Console{virtual~LC16Console();char p4[0x60];LC16Engine*engine;char p68[4];LC16Console(LC16Console*,int,int,int,int,int,bool,int);bool inBounds417360(int,int);void reset418450();void print4181d0(int,int,const string&);void animate48c3c0(LC16Def*);int width44b0d0()throw();};
struct LC16Timer{int type;LC16Console*console;char p8[0x2c];LC16Timer(int,LC16Console*,bool,unsigned,const LC16Point&,int,int,int,const LC16Point&);};
struct LC16Timers{LC16Timer**begin,**end,**capacity;allocator<LC16Timer*>alloc;void push9b9280(LC16Timer*&&);LC16Timer*const&back9b6540()const throw();};
struct LC16Record{LC16Point pos;string text;int mode;};
struct LC16Map:LC16Console{LC16Point offset;char p74[0x164];LC16Timers labels;char p1e8[0x20];LC16Point last;LC16Handle mark;bool blocked8052f0(const LC16Point&);void comment(bool,LC16Record*);};
extern LC16Console*lc16_cec054;extern bool lc16_d28d15;extern unsigned lc16_caed20;extern LC16Point lc16_cfbec0;
bool isOdd_406340(int);bool lc16_lookup9d45a0(const string&,LC16Def**);string opW5_truncate_408490(const string&,int);
void LC16Map::comment(bool timed,LC16Record*record){
 string i=record->text;last.assign46ca50(record->pos);mark.reset9b7270();
 LC16Point root(record->pos);LC16Point x(root.x+offset.x,root.y+offset.y);int w=i.size()+3;
 bool left=!blocked8052f0(root)||inBounds417360(x.x+w/2,x.y);
 if(left){i.insert(0,"> ");i+=" ";}else{i.insert(0," ");i+=" <";}
 bool type=false;if(left)x.x++;else{if(isOdd_406340(w)){i.insert(0," ");type=true;w++;}x.x-=w/2;}
 labels.push9b9280(new LC16Timer(9,new LC16Console(lc16_cec054,w,1,x.x,x.y,lc16_d28d15!=0,false,-1),timed,timed?lc16_caed20+2000:0,left?LC16Point(1,0):LC16Point(-i.size()/2,0),LC16Handle().id,LC16Handle().id,LC16Handle().id,record->pos));
 labels.back9b6540()->console->reset418450();labels.back9b6540()->console->print4181d0(0,0,i);
 LC16Def*center=0,*a=0,*b=0;
 if(lc16_lookup9d45a0(record->mode?"CMap_Label_Comment_Auto_Caret":"CMap_Label_Comment_Manual_Caret",&center)&&lc16_lookup9d45a0(record->mode?"CMap_Label_Comment_Auto_Text":"CMap_Label_Comment_Manual_Text",&a)&&lc16_lookup9d45a0("A_CMap_Label_Comment_S",&b)){labels.back9b6540()->console->animate48c3c0(b);if(left){
 do{for(int x=LC16Point(0,0).x;x<LC16Point(0,0).x+1;x++)labels.back9b6540()->console->engine->new50fb50()->init50de10(labels.back9b6540()->console->engine,center,LC16Point(x,LC16Point(0,0).y),lc16_cfbec0,0,0,9);}while(0);
 do{for(int x=LC16Point(1,0).x;x<LC16Point(1,0).x+labels.back9b6540()->console->width44b0d0()-1;x++)labels.back9b6540()->console->engine->new50fb50()->init50de10(labels.back9b6540()->console->engine,a,LC16Point(x,LC16Point(1,0).y),lc16_cfbec0,0,0,9);}while(0);
 }else{
 do{for(int x=LC16Point(labels.back9b6540()->console->width44b0d0()-1,0).x;x<LC16Point(labels.back9b6540()->console->width44b0d0()-1,0).x+1;x++)labels.back9b6540()->console->engine->new50fb50()->init50de10(labels.back9b6540()->console->engine,center,LC16Point(x,LC16Point(labels.back9b6540()->console->width44b0d0()-1,0).y),lc16_cfbec0,0,0,9);}while(0);
 do{for(int x=LC16Point(type?1:0,0).x;x<LC16Point(type?1:0,0).x+labels.back9b6540()->console->width44b0d0()-((type?1:0)+1);x++)labels.back9b6540()->console->engine->new50fb50()->init50de10(labels.back9b6540()->console->engine,a,LC16Point(x,LC16Point(type?1:0,0).y),lc16_cfbec0,0,0,9);}while(0);
 }}
 string temp=i;while(temp[0]==' '||temp[0]=='>')temp.erase(temp.begin());while(temp.back()==' '||temp.back()=='<')temp.pop_back();temp=opW5_truncate_408490(temp,10);
 LC16Def*base=0;lc16_lookup9d45a0(record->mode?"A_CMap_Label_Com_A_Off":"A_CMap_Label_Com_M_Off",&base);
 labels.push9b9280(new LC16Timer(10,new LC16Console(lc16_cec054,temp.size()+2,1,0,-1,lc16_d28d15!=0,false,-1),timed,timed?lc16_caed20+2000:0,LC16Point(0,0),LC16Handle().id,LC16Handle().id,LC16Handle().id,record->pos));
 labels.back9b6540()->console->reset418450();labels.back9b6540()->console->print4181d0(1,0,temp);labels.back9b6540()->console->animate48c3c0(base);
}
