// NOTE: private partial layouts and external call-site aliases for map edge timer placement8146c0.
#include <string>
#include <vector>
using namespace std;
struct LC28Point{int x,y;LC28Point()throw();LC28Point(int)throw();LC28Point&operator=(const LC28Point&)throw();LC28Point&add409a30(const LC28Point&)throw();LC28Point(int,int)throw();LC28Point(const LC28Point&)throw();LC28Point(const LC28Point&,int,int)throw();bool operator==(const LC28Point&)const throw();LC28Point sum409b60(const LC28Point&)throw();};
struct LC28Color{unsigned char r,g,b;LC28Color()throw();LC28Color(int,int,int)throw();LC28Color(const LC28Color&)throw();LC28Color&operator=(LC28Color)throw();bool operator!=(LC28Color)throw();};
struct LC28XCell{int font,glyph,value;LC28Color fore,back;};
struct LC28Buffer{int width,height;LC28XCell*data;LC28Buffer();~LC28Buffer();};
struct LC28Event;
struct LC28XConsole{virtual ~LC28XConsole();virtual void resize(int,int);virtual bool active();virtual void refresh();virtual bool input(LC28Event*);virtual void mouse(int,int);virtual void update();virtual void render();
 LC28XConsole*parent;LC28Buffer buffer;int font,fontType;LC28Point position,absolutePosition;LC28Color foreground,background;int backFlag,alignment;float scaleX,scaleY;vector<LC28XConsole*>children;bool hidden;int layer;bool passThrough,ignoreMouse;
 bool contains(const LC28Point&)throw();void remove(LC28XConsole*);void reset();void fore(LC28Color);void back(LC28Color);void enable(int);void print(int,int,const string&);int width()throw();LC28Point absolute(LC28Point)throw();LC28Point pos417480()throw();bool hidden4175f0()throw();int width44b0d0()throw();int height4174c0()throw();LC28Color back4176b0(int,int)throw();void pos417a90(int,int);void hidden417ba0(bool);bool in4173d0(const LC28Point&)throw();void row(int,int,int,LC28Color);void rect(int,int,int,int,LC28Color);void put(int,int,int,LC28Color,LC28Color,int);};
struct LC28Engine;struct LC28Title;struct LC28Rect;
struct LC28Console:LC28XConsole{virtual ~LC28Console();virtual void resize(int,int);virtual bool input(LC28Event*);virtual void update();virtual void render();virtual void open();virtual void close();virtual int frameKind();virtual void trigger(const string&,int);int state;LC28Engine*engine;LC28Title*title;LC28Console(LC28XConsole*,int,int,int,int,int,bool,int);void frame(LC28Rect*,LC28Color,bool,bool);void baseRender();};
static_assert(sizeof(LC28XCell)==20&&sizeof(LC28XConsole)==0x60&&sizeof(LC28Console)==0x6c,"actual console owners/layout");

struct LC28Item;struct LC28HI{int id;LC28HI()throw();bool valid9b7230()const throw();LC28Item*get9b65b0()const throw();void clear9b7270()throw();};
struct LC28Def{char p0[0x44];int matter,subtype;char p4c[8];int special;char p58[0xf0-0x58];int category;};
struct LC28Memory{char p0[0x10];int type,amount,rating,threat,state;char p24[0x34-0x24];};
struct LC28Item{int type457820()throw();int subtype4578a0()throw();unsigned char flag415ee0()throw();bool flag457d10()throw();int rating457ca0()throw();int matter457880()throw();LC28Def*def9b4350()throw();int category457f90()throw();int threat457920()throw();const LC28Point&position575920();};
struct LC28Cell{LC28HI item45d8f0()throw();};
template<class T>struct LC28Grid{int width,height;T*data;LC28Grid();~LC28Grid();T*at(int,int)throw();};
struct LC28World{char p0[0x69c];LC28Grid<int>visible;char p6a8[0x7c4-0x6a8];LC28Grid<LC28Memory>memory;bool visible463190(int,int)throw();};extern LC28World*lc28_cefc4c;extern LC28Grid<LC28Cell*>lc28_cfd44c;extern vector<int>lc28_cf4830;extern vector<LC28Def*>lc28_d2d1c4;
struct LC28Location{int inverse46ed20()throw();};struct LC28HC{int id;LC28Location*get9b7910()const throw();};extern LC28HC lc28_d1e888;
extern int lc28_d28df4,lc28_cf462c,lc28_cf27f4,lc28_cf27f8,lc28_d28df0,lc28_caf164;extern unsigned char lc28_d28df8,lc28_d28df9;extern unsigned lc28_caed20;
extern const bool lc28_bcbe54[];struct LC28OffsetColumn{int value,pair;};extern LC28OffsetColumn lc28_cefd20[],lc28_cefd24[];
struct LC28HE{int id;void clear9b7270()throw();};
struct LC28Timer{int type;LC28XConsole*console;char undecoded8[0x28-8];LC28Point anchor;};
int lc28_label7ff100(LC28HI,LC28Memory*,string&,bool);int lc28_max(int,int);
struct LC28View:LC28Console{LC28Point offset;char p74[0x1d8-0x74];vector<LC28Timer*>labels;char p1e8[8];unsigned stamp;int filter;char p1f8[0x208-0x1f8];LC28Point focus;LC28HE entity;char undecoded214[0x36c-0x214];LC28XConsole*panel;
 void limits8051f0(LC28Point&,LC28Point&)throw();bool inside8052f0(const LC28Point&)throw();bool bounds417360(int,int)throw();bool hasItem49b320(LC28HI);bool hasPos49b220(int,const LC28Point&);void add811350(bool,const LC28Point&,int,LC28HI,LC28Memory*);int items8119c0(LC28HI,bool,bool,bool);void edges8146c0();
};
bool lc28_between9daf80(int,int,int)throw();

bool lc28_odd406340(int)throw();extern LC28Color*lc28_d20cfc;
int lc28_free8145f0(int,int,int,vector<LC28Point>&,bool);void lc28_erase9ce6d0(vector<LC28Timer*>&,unsigned&);
#define VERTICAL(V,X) {if(active!=-1){group[j]->console->pos417a90(X,active);V.push_back(LC28Point(active-1,active+1));}else group[j]->console->hidden417ba0(true);lc28_erase9ce6d0(group,j);}
#define HORIZONTAL(V,Y) {if(active!=-1){group[j]->console->pos417a90(active,Y);V.push_back(LC28Point(active-1,active+count+1));}else group[j]->console->hidden417ba0(true);lc28_erase9ce6d0(group,j);}
void LC28View::edges8146c0(){
 if(labels.empty())return;
 vector<LC28Timer*>group;
 for(unsigned j=0;j<labels.size();j++){
  if((labels[j]->type==8||labels[j]->type==10)&&!labels[j]->console->hidden4175f0()){
   group.push_back(labels[j]);
   for(unsigned n=0;n<labels.size();n++){
    if(labels[n]->type==labels[j]->type-1&&labels[n]->anchor==group.back()->anchor){
     LC28Point value=labels[n]->console->pos417480();
     for(int x=0;x<labels[n]->console->width44b0d0();x++)for(int y=0;y<labels[n]->console->height4174c0();y++){
      if(labels[n]->console->back4176b0(x,y)!=*lc28_d20cfc&&in4173d0(LC28Point(value,x/2,y))){group.back()->console->hidden417ba0(true);group.pop_back();goto scanned;}
     }
     scanned:break;
    }
   }
  }
 }
 if(group.empty())return;
 LC28Point value;vector<LC28Point>base;base.push_back(LC28Point(0));base.push_back(LC28Point(lc28_cf27f4-2));vector<LC28Point>first(base);
 vector<LC28Point>i;i.push_back(LC28Point(0));i.push_back(LC28Point(lc28_cf27f8-2));vector<LC28Point>last(i);
 int active;
 for(unsigned j=0;j<group.size();j++){
  value=group[j]->anchor.sum409b60(offset);
  if(value.x<0){
   if(value.y<0){
    if(value.x<value.y){active=lc28_free8145f0(1,1,lc28_cf27f8-2,i,true);VERTICAL(i,0)}else{
     int idx=group[j]->type==10;int count=group[j]->console->width44b0d0();if(lc28_odd406340(count))count++;count/=2;
     active=lc28_free8145f0(1,count,lc28_cf27f4-2,base,true);HORIZONTAL(base,idx)
    }
   }else if(value.y>=lc28_cf27f8){
    if(-value.x>value.y-lc28_cf27f8){active=lc28_free8145f0(lc28_cf27f8-2,1,1,i,false);VERTICAL(i,0)}else{
     int count=group[j]->console->width44b0d0();if(lc28_odd406340(count))count++;count/=2;
     active=lc28_free8145f0(1,count,lc28_cf27f4-2,first,true);HORIZONTAL(first,lc28_cf27f8-1)
    }
   }
  }else if(value.x>=lc28_cf27f4){
   if(value.y<0){
    if(-(value.x-lc28_cf27f4)<value.y){active=lc28_free8145f0(panel&&!panel->hidden4175f0()?panel->pos417480().y+panel->height4174c0():1,1,lc28_cf27f8-2,last,true);VERTICAL(last,lc28_cf27f4-group[j]->console->width44b0d0()/2)}else{
     int idx=group[j]->type==10;int count=group[j]->console->width44b0d0();if(lc28_odd406340(count))count++;count/=2;
     active=lc28_free8145f0(lc28_cf27f4-2,count,1,base,false);HORIZONTAL(base,idx)
    }
   }else if(value.y>=lc28_cf27f8){
    if(value.x-lc28_cf27f4>value.y-lc28_cf27f8){active=lc28_free8145f0(lc28_cf27f8-2,1,1,last,false);VERTICAL(last,lc28_cf27f4-group[j]->console->width44b0d0()/2)}else{
     int count=group[j]->console->width44b0d0();if(lc28_odd406340(count))count++;count/=2;
     active=lc28_free8145f0(lc28_cf27f4-2,count,1,first,false);HORIZONTAL(first,lc28_cf27f8-1)
    }
   }
  }
 }
 for(unsigned j=0;j<group.size();j++){
  value=group[j]->anchor.sum409b60(offset);
  if(value.x<0||value.x>=lc28_cf27f4){
   bool changed=value.x<0;vector<LC28Point>&vec=changed?i:last;int col=changed?0:lc28_cf27f4-group[j]->console->width44b0d0()/2;
   active=lc28_free8145f0(!changed&&panel&&!panel->hidden4175f0()?lc28_max(value.y,panel->pos417480().y+panel->height4174c0()):value.y,1,lc28_cf27f8-2,vec,true);
   if(active!=-1){group[j]->console->pos417a90(col,active);vec.push_back(LC28Point(active-1,active+1));}else{
    active=lc28_free8145f0(value.y,1,1,vec,false);
    if(active!=-1){group[j]->console->pos417a90(col,active);vec.push_back(LC28Point(active-1,active+1));}else group[j]->console->hidden417ba0(true);
   }
   lc28_erase9ce6d0(group,j);
  }else{
   bool changed=value.y<0;vector<LC28Point>&line=changed?base:first;int count=changed?0:lc28_cf27f8-1;if(changed&&group[j]->type==10)count++;
   int col=group[j]->console->width44b0d0();if(lc28_odd406340(col))col++;col/=2;
   active=lc28_free8145f0(value.x,col,lc28_cf27f4-2,line,true);
   if(active!=-1){group[j]->console->pos417a90(active,count);line.push_back(LC28Point(active-1,active+col));}else{
    active=lc28_free8145f0(value.x,col,1,line,false);
    if(active!=-1){group[j]->console->pos417a90(active,count);line.push_back(LC28Point(active-1,active+col));}else group[j]->console->hidden417ba0(true);
   }
   lc28_erase9ce6d0(group,j);
  }
 }
}
