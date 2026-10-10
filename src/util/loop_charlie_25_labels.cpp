// NOTE: private partial layouts and external call-site aliases for map item labels8119c0.
#include <string>
#include <vector>
using namespace std;
struct LC25Point{int x,y;LC25Point()throw();LC25Point(int)throw();LC25Point&operator=(const LC25Point&)throw();LC25Point&add409a30(const LC25Point&)throw();LC25Point(int,int)throw();LC25Point(const LC25Point&)throw();};
struct LC25Color{unsigned char r,g,b;LC25Color()throw();LC25Color(int,int,int)throw();LC25Color(const LC25Color&)throw();LC25Color&operator=(LC25Color)throw();};
struct LC25XCell{int font,glyph,value;LC25Color fore,back;};
struct LC25Buffer{int width,height;LC25XCell*data;LC25Buffer();~LC25Buffer();};
struct LC25Event;
struct LC25XConsole{virtual ~LC25XConsole();virtual void resize(int,int);virtual bool active();virtual void refresh();virtual bool input(LC25Event*);virtual void mouse(int,int);virtual void update();virtual void render();
 LC25XConsole*parent;LC25Buffer buffer;int font,fontType;LC25Point position,absolutePosition;LC25Color foreground,background;int backFlag,alignment;float scaleX,scaleY;vector<LC25XConsole*>children;bool hidden;int layer;bool passThrough,ignoreMouse;
 bool contains(const LC25Point&)throw();void remove(LC25XConsole*);void reset();void fore(LC25Color);void back(LC25Color);void enable(int);void print(int,int,const string&);int width()throw();LC25Point absolute(LC25Point)throw();void row(int,int,int,LC25Color);void rect(int,int,int,int,LC25Color);void put(int,int,int,LC25Color,LC25Color,int);};
struct LC25Engine;struct LC25Title;struct LC25Rect;
struct LC25Console:LC25XConsole{virtual ~LC25Console();virtual void resize(int,int);virtual bool input(LC25Event*);virtual void update();virtual void render();virtual void open();virtual void close();virtual int frameKind();virtual void trigger(const string&,int);int state;LC25Engine*engine;LC25Title*title;LC25Console(LC25XConsole*,int,int,int,int,int,bool,int);void frame(LC25Rect*,LC25Color,bool,bool);void baseRender();};
static_assert(sizeof(LC25XCell)==20&&sizeof(LC25XConsole)==0x60&&sizeof(LC25Console)==0x6c,"actual console owners/layout");

struct LC25Item;struct LC25HI{int id;LC25HI()throw();bool valid9b7230()const throw();LC25Item*get9b65b0()const throw();void clear9b7270()throw();};
struct LC25Def{char p0[0x44];int matter,subtype;char p4c[8];int special;char p58[0xf0-0x58];int category;};
struct LC25Memory{char p0[0x10];int type,amount,rating,threat,state;char p24[0x34-0x24];};
struct LC25Item{int type457820()throw();int subtype4578a0()throw();unsigned char flag415ee0()throw();bool flag457d10()throw();int rating457ca0()throw();int matter457880()throw();LC25Def*def9b4350()throw();int category457f90()throw();int threat457920()throw();const LC25Point&position575920();};
struct LC25Cell{LC25HI item45d8f0()throw();};
template<class T>struct LC25Grid{int width,height;T*data;LC25Grid();~LC25Grid();T*at(int,int)throw();};
struct LC25World{char p0[0x69c];LC25Grid<int>visible;char p6a8[0x7c4-0x6a8];LC25Grid<LC25Memory>memory;bool visible463190(int,int)throw();};extern LC25World*lc25_cefc4c;extern LC25Grid<LC25Cell*>lc25_cfd44c;extern vector<int>lc25_cf4830;extern vector<LC25Def*>lc25_d2d1c4;
struct LC25Location{int getDepthIndex()throw();};struct LC25HC{int id;LC25Location*get9b7910()const throw();};extern LC25HC lc25_d1e888;
extern int lc25_d28df4,lc25_cf462c,lc25_cf27f4,lc25_cf27f8,lc25_d28df0,lc25_caf164;extern unsigned char lc25_d28df8,lc25_d28df9;extern unsigned lc25_caed20;
extern const bool lc25_bcbe54[];struct LC25OffsetColumn{int value,pair;};extern LC25OffsetColumn lc25_cefd20[],lc25_cefd24[];
struct LC25HE{int id;void clear9b7270()throw();};
struct LC25Timer{int type;LC25XConsole*console;};
int lc25_label7ff100(LC25HI,LC25Memory*,string&,bool);int lc25_max(int,int);
struct LC25View:LC25Console{LC25Point offset;char p74[0x1d8-0x74];vector<LC25Timer*>labels;char p1e8[8];unsigned stamp;int filter;char p1f8[0x208-0x1f8];LC25Point focus;LC25HE entity;
 void limits8051f0(LC25Point&,LC25Point&)throw();bool inside8052f0(const LC25Point&)throw();bool bounds417360(int,int)throw();bool hasItem49b320(LC25HI);bool hasPos49b220(int,const LC25Point&);void add811350(bool,const LC25Point&,int,LC25HI,LC25Memory*);int items8119c0(LC25HI,bool,bool,bool);
};
bool lc25_between9daf80(int,int,int)throw();
int LC25View::items8119c0(LC25HI item,bool full,bool unique,bool costly){
 vector<LC25HI>self;vector<LC25Memory*>group;vector<LC25Point>base;vector<LC25XConsole*>x2;
 LC25Grid<LC25Memory>*point=&lc25_cefc4c->memory;
 if(item.valid9b7230()){
  self.push_back(item);group.push_back(0);base.push_back(LC25Point(-1));
  for(unsigned j=0;j<labels.size();j++)if(lc25_between9daf80(4,labels[j]->type,7))x2.push_back(labels[j]->console);
  focus= item.get9b65b0()->position575920();entity.clear9b7270();
 }else{
  LC25Memory*idx2;LC25HI record;int mode=lc25_d28df4?lc25_d1e888.get9b7910()->getDepthIndex()-lc25_d28df4:0;bool hidden=lc25_cf462c==4;LC25Grid<int>*temp=&lc25_cefc4c->visible;LC25Point first,last;limits8051f0(first,last);
  for(int col=first.x,sx=lc25_max(offset.x,0);col<=last.x&&sx<lc25_cf27f4;col++,sx++){
   for(int p=first.y,idx=lc25_max(offset.y,0);p<=last.y&&idx<lc25_cf27f8;p++,idx++){
    if(*temp->at(col,p)){
     if(lc25_cfd44c.at(col,p)[0]->item45d8f0().valid9b7230()){
      record=lc25_cfd44c.at(col,p)[0]->item45d8f0();
      switch(filter){break;case 1:if(record.get9b65b0()->subtype4578a0()!=0)continue;break;case 2:if(record.get9b65b0()->subtype4578a0()!=1)continue;break;case 3:if(record.get9b65b0()->subtype4578a0()!=2)continue;break;case 4:if(record.get9b65b0()->subtype4578a0()!=3)continue;break;case 5:if(record.get9b65b0()->subtype4578a0()!=5)continue;break;}
      if(full||((!lc25_cf4830[record.get9b65b0()->type457820()]||((!lc25_d28df8||!record.get9b65b0()->flag415ee0())&&(!lc25_d28df9||!record.get9b65b0()->flag457d10())))&&(!lc25_d28df0||record.get9b65b0()->rating457ca0()>=lc25_d28df0)&&(!mode||record.get9b65b0()->matter457880()<6||!record.get9b65b0()->def9b4350()->special||record.get9b65b0()->category457f90()==124||record.get9b65b0()->category457f90()==123||record.get9b65b0()->threat457920()>=mode)&&(!hidden||record.get9b65b0()->matter457880()!=0))){
       if(unique&&hasItem49b320(record))continue;
       self.push_back(record);group.push_back(0);base.push_back(LC25Point(-1));
      }
     }
    }else if(point->at(col,p)->type!=lc25_caf164){
     idx2=point->at(col,p);
     switch(filter){break;case 1:if(lc25_d2d1c4[idx2->type]->subtype!=0)continue;break;case 2:if(lc25_d2d1c4[idx2->type]->subtype!=1)continue;break;case 3:if(lc25_d2d1c4[idx2->type]->subtype!=2)continue;break;case 4:if(lc25_d2d1c4[idx2->type]->subtype!=3)continue;break;case 5:if(lc25_d2d1c4[idx2->type]->subtype!=5)continue;break;}
     if(full||((!lc25_cf4830[idx2->type]||((!lc25_d28df8||idx2->state!=2)&&(!lc25_d28df9||idx2->state!=3)))&&(!lc25_d28df0||idx2->rating>=lc25_d28df0)&&(!mode||lc25_d2d1c4[idx2->type]->matter<6||!lc25_d2d1c4[idx2->type]->special||lc25_d2d1c4[idx2->type]->category==124||lc25_d2d1c4[idx2->type]->category==123||idx2->threat>=mode)&&(!hidden||lc25_d2d1c4[idx2->type]->matter!=0))){
      if(unique&&hasPos49b220(6,LC25Point(col,p)))continue;
      self.push_back(LC25HI());group.push_back(idx2);base.push_back(LC25Point(col,p));
     }
    }
   }
  }
  if(self.empty())return 0;stamp=lc25_caed20;
 }
 int n=0;string text;int i,a,active;
 for(unsigned j=0;j<self.size();j++){
  vector<int>scores(6u,0);i=(lc25_label7ff100(self[j],group[j],text,true)+5)/2;a=6;
  for(unsigned k=0;k<scores.size();k++){
   active=0;int mode=0;
   int sx=(self[j].valid9b7230()?self[j].get9b65b0()->position575920().x:base[j].x)+lc25_cefd20[k].value-(lc25_bcbe54[k]?i-1:0);
   int sy=(self[j].valid9b7230()?self[j].get9b65b0()->position575920().y:base[j].y)+lc25_cefd24[k].value;
   for(;mode<i;mode++,sx++){
    if(inside8052f0(LC25Point(sx,sy))){
     if(lc25_cfd44c.at(sx,sy)[0]->item45d8f0().valid9b7230()&&(lc25_cefc4c->visible463190(sx,sy)||point->at(sx,sy)->type!=lc25_caf164)){active+=10;continue;}
    }else if(!bounds417360(sx+offset.x,sy+offset.y)){active+=2;continue;}
    LC25Point pos(sx,sy);pos.add409a30(offset);pos=absolute(pos);
    for(unsigned q=0;q<x2.size();q++)if(x2[q]->contains(pos)){active+=costly?20:1;break;}
   }
   if(active)scores[k]=active;else{a=k;goto selected;}
  }
  if(a==6){active=scores[0];a=0;for(unsigned k=1;k<scores.size();k++)if(scores[k]<active){active=scores[k];a=k;}}
selected:
  add811350(item.valid9b7230(),self[j].valid9b7230()?self[j].get9b65b0()->position575920():base[j],a,self[j],group[j]);x2.push_back(labels.back()->console);n++;
 }
 return n;
}
