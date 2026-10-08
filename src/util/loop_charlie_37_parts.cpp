// NOTE: parts trigger895020, complete native allocated Console/Part/Cycle/Exoskeleton owners.
#include <string>
#include <vector>
// NOTE: genuine complete console prefix; real external constructors/destructors; native buffer and child-vector ownership.
using namespace std;
struct LC37Point{int x,y;LC37Point(int)throw();LC37Point(int,int)throw();LC37Point(const LC37Point&)throw();};
struct LC37Color{unsigned char r,g,b;LC37Color()throw();LC37Color(int,int,int)throw();LC37Color(const LC37Color&)throw();LC37Color&operator=(LC37Color)throw();};
struct LC37XCell{int font,glyph,value;LC37Color fore,back;};
struct LC37Buffer{int width,height;LC37XCell*data;LC37Buffer();~LC37Buffer();};
struct LC37Event;
struct LC37XConsole{virtual ~LC37XConsole();virtual void resize(int,int);virtual bool active();virtual void refresh();virtual bool input(LC37Event*);virtual void mouse(int,int);virtual void update();virtual void render();
 LC37XConsole*parent;LC37Buffer buffer;int font,fontType;LC37Point position,absolutePosition;LC37Color foreground,background;int backFlag,alignment;float scaleX,scaleY;vector<LC37XConsole*>children;bool hidden;int layer;bool passThrough,ignoreMouse;
 void remove(LC37XConsole*);void reset();void fore(LC37Color);void back(LC37Color);void enable(int);void print(int,int,const string&);int width()throw();int height()throw();LC37Point absolute(LC37Point)throw();void row(int,int,int,LC37Color);void rect(int,int,int,int,LC37Color);void put(int,int,int,LC37Color,LC37Color,int);};
struct LC37Engine;struct LC37Title;struct LC37Rect;
struct LC37Console:LC37XConsole{virtual ~LC37Console();virtual void resize(int,int);virtual bool input(LC37Event*);virtual void update();virtual void render();virtual void open();virtual void close();virtual int frameKind();virtual void trigger(const string&,int);int state;LC37Engine*engine;LC37Title*title;LC37Console(LC37XConsole*,int,int,int,int,int,bool,int);void frame(LC37Rect*,LC37Color,bool,bool);void baseRender();void animate48c3f0(string);};
static_assert(sizeof(LC37XCell)==20&&sizeof(LC37XConsole)==0x60&&sizeof(LC37Console)==0x6c,"actual console owners/layout");



struct LC37Item{int type44aec0()throw();int slots4578c0()throw();string name571db0(bool,bool);};
struct LC37HI{int id;LC37HI()throw();LC37Item*get9b65b0()const throw();bool null9b65d0()const throw();bool equal9b78e0(LC37HI)const throw();};
struct LC37Entity{vector<LC37HI>*inventory45ab00()throw();int slots45a860()throw();int slotCount448fe0(int)throw();};
struct LC37HE{int id;LC37Entity*get9b6570()const throw();};
struct LC37Map{LC37HE player4630f0()throw();};extern LC37Map*lc37_cefc4c;
struct LC37Marker{int kind;LC37Item*firstItem;LC37HI first;LC37Item*secondItem;LC37HI second;bool firstEmpty46d2a0()throw();bool secondEmpty46d2e0()throw();};
extern vector<vector<LC37Marker*> >lc37_cf4750;
extern bool lc37_cefaee,lc37_d28e56,lc37_d28e55,lc37_cf4a00;
extern int lc37_cefc94,lc37_cefc98,lc37_cf4718;
extern string lc37_cfcc78[],lc37_cfabc0[];
extern LC37Color*lc37_cfe674;
bool lc37_has4328a0()throw();bool lc37_contains9daf80(int,int,int)throw();
void lc37_fillInts(int*,unsigned int,int);
void lc37_logError404f10(string,string);
void lc37_logFatal404fd0(string,string);
struct LC37PartBar;struct LC37Confirm;
struct LC37Part:LC37Console{LC37HI item;bool continuation;LC37HI other;bool flagged;int type,key,unknown84;bool unknown88;int unknown8c;LC37XConsole*child90;LC37PartBar*bar94;LC37XConsole*child98;int unknown9c;LC37Confirm*confirm;
 LC37Part(LC37XConsole*,int,LC37HI,bool,LC37HI,int,int);virtual ~LC37Part();void set890710(bool);};
struct LC37Cycle:LC37Console{int type;LC37Cycle(LC37XConsole*,int,int);virtual ~LC37Cycle();};
struct LC37Modal:LC37Console{int type;LC37Modal(LC37XConsole*,int,int,int,int);virtual ~LC37Modal();};
struct LC37Exoskeleton:LC37Console{int cached,threats,components;LC37Exoskeleton(LC37XConsole*);virtual ~LC37Exoskeleton();};
struct LC37Parts:LC37Console{char unknown6c[8];vector<LC37Part*>parts;char unknown84[4];LC37Cycle*cycle1,*cycle2,*cycle3;vector<LC37Modal*>modals;char unknowna4[4];LC37Exoskeleton*exoskeleton;char unknownac[0xcc-0xac];bool modal;
 virtual ~LC37Parts();virtual void trigger(const string&,int);};
static_assert(sizeof(LC37Part)==0xa4&&sizeof(LC37Cycle)==0x70&&sizeof(LC37Modal)==0x70&&sizeof(LC37Exoskeleton)==0x78,"real allocated owner extents");
#define MAKEHEADER(type,row) {LC37Console*title=new LC37Console(this,lc37_cfcc78[type].size(),1,2,row,0,false,-1);title->print(0,0,lc37_cfcc78[type]);title->animate48c3f0("A_CParts_Header");if(type!=0){LC37Console*divider=new LC37Console(this,width()-2-(lc37_cfcc78[type].size()+3),1,lc37_cfcc78[type].size()+3,row,0,false,-1);divider->animate48c3f0("A_CParts_Divider_"+lc37_cfabc0[lc37_cf4718]);}switch(type){case 1:cycle1=new LC37Cycle(this,1,row);break;case 2:cycle2=new LC37Cycle(this,2,row);break;case 3:cycle3=new LC37Cycle(this,3,row);break;}fore(*lc37_cfe674);row++;}
void LC37Parts::trigger(const string&command,int value){
 if(command=="show_parts"){
  LC37HE player=lc37_cefc4c->player4630f0();vector<LC37HI>*inventory=player.get9b6570()->inventory45ab00();
  if(!lc37_cf4750.empty()){for(int i=0;i<4;i++){if(lc37_cf4750[i].empty()){if(!lc37_cefaee)lc37_logError404f10("CParts::trigger()","partSlots data empty - FIX!");lc37_cf4750.clear();break;}}}
  modal=false;if(lc37_has4328a0()&&(lc37_d28e56||(lc37_d28e55&&lc37_contains9daf80(lc37_cefc98,player.get9b6570()->slots45a860(),lc37_cefc94))))modal=true;
  if(lc37_cf4750.empty()){
   int counts[4];lc37_fillInts(counts,4,0);
   for(int i=0;i<inventory->size();i++){if((*inventory)[i].get9b65b0()->type44aec0()<=3){counts[(*inventory)[i].get9b65b0()->type44aec0()]+=(*inventory)[i].get9b65b0()->slots4578c0();}}
   int row=1,key=97;
   for(int type=0;type<4;type++){
    if(!modal)MAKEHEADER(type,row)
    for(int i=0;i<inventory->size();i++){if((*inventory)[i].get9b65b0()->type44aec0()==type){for(int j=0;j<(*inventory)[i].get9b65b0()->slots4578c0();j++){parts.push_back(new LC37Part(this,row,(*inventory)[i],j>0,LC37HI(),type,key));parts.back()->set890710(false);key++;row++;}}}
    int total=player.get9b6570()->slotCount448fe0(type);
    for(int i=counts[type];i<total;i++){parts.push_back(new LC37Part(this,row,LC37HI(),false,LC37HI(),type,key));parts.back()->set890710(false);key++;row++;}
   }
  }else{
   int row=1,key=97;
   for(int type=0;type<4;type++){
    if(!modal)MAKEHEADER(type,row)
    for(int i=0;i<lc37_cf4750[type].size();i++){
     if(!lc37_cf4750[type][i]->firstEmpty46d2a0()&&lc37_cf4750[type][i]->first.null9b65d0()){
      for(int j=0;j<inventory->size();j++){if((*inventory)[j].get9b65b0()==lc37_cf4750[type][i]->firstItem){lc37_cf4750[type][i]->first=(*inventory)[j];lc37_cf4750[type][i]->firstItem=0;break;}}
      if(lc37_cf4750[type][i]->first.null9b65d0())lc37_logFatal404fd0("CParts::trigger()","Item not found in inventory after transfer: "+lc37_cf4750[type][i]->firstItem->name571db0(false,false));
     }
     if(!lc37_cf4750[type][i]->secondEmpty46d2e0()&&lc37_cf4750[type][i]->second.null9b65d0()&&lc37_cf4750[type][i]->secondItem){
      for(int j=0;j<inventory->size();j++){if((*inventory)[j].get9b65b0()==lc37_cf4750[type][i]->secondItem){lc37_cf4750[type][i]->second=(*inventory)[j];lc37_cf4750[type][i]->secondItem=0;break;}}
      if(lc37_cf4750[type][i]->second.null9b65d0())lc37_logFatal404fd0("CParts::trigger()","tempSlotCreator Item not found in inventory after transfer: "+lc37_cf4750[type][i]->secondItem->name571db0(false,false));
     }
    }
    for(int i=0;i<lc37_cf4750[type].size();i++){
     if(lc37_cf4750[type][i]->firstEmpty46d2a0()){parts.push_back(new LC37Part(this,row,LC37HI(),false,lc37_cf4750[type][i]->second,type,key));parts.back()->set890710(false);key++;row++;}
     else{LC37HI item=lc37_cf4750[type][i]->first;parts.push_back(new LC37Part(this,row,item,i!=0&&item.equal9b78e0(lc37_cf4750[type][i-1]->first),lc37_cf4750[type][i]->second,type,key));parts.back()->set890710(false);key++;row++;}
    }
   }
  }
  if(modal){int row=1;for(int type=0;type<4;type++){int count=player.get9b6570()->slotCount448fe0(type);if(count!=0){modals.push_back(new LC37Modal(this,type,0,row,count));modals.push_back(new LC37Modal(this,type,width()-1,row,count));row+=modals.back()->height();}}}
  if(!exoskeleton&&lc37_cf4a00)exoskeleton=new LC37Exoskeleton(this);
 }
}
