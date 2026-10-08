// NOTE: private borrowed machine-target view and native Console/string owners for trigger.
#include <string>
#include <vector>
// NOTE: actual twelve-slot Console hierarchy; borrowed MachineTarget and definition views.
// Native string/vector fields own storage; unknown byte ranges describe borrowed prefixes only.
using namespace std;
struct LC36Point{int x,y;LC36Point(int)throw();LC36Point(int,int)throw();LC36Point(const LC36Point&)throw();};
struct LC36Color{unsigned char r,g,b;LC36Color()throw();LC36Color(int,int,int)throw();LC36Color(const LC36Color&)throw();LC36Color&operator=(LC36Color)throw();};
struct LC36XCell{int font,glyph,value;LC36Color fore,back;};
struct LC36Buffer{int width,height;LC36XCell*data;LC36Buffer();~LC36Buffer();};
struct LC36Event;
struct LC36XConsole{virtual ~LC36XConsole();virtual void resize(int,int);virtual bool active();virtual void refresh();virtual bool input(LC36Event*);virtual void mouse(int,int);virtual void update();virtual void render();
 LC36XConsole*parent;LC36Buffer buffer;int font,fontType;LC36Point position,absolutePosition;LC36Color foreground,background;int backFlag,alignment;float scaleX,scaleY;vector<LC36XConsole*>children;bool hidden;int layer;bool passThrough,ignoreMouse;
 void remove(LC36XConsole*);void reset();void fore(LC36Color);void back(LC36Color);void enable(int);void print(int,int,const string&);void setCharRow(int,int,int,int);int width()throw();LC36Point absolute(LC36Point)throw();void row(int,int,int,LC36Color);void rect(int,int,int,int,LC36Color);void put(int,int,int,LC36Color,LC36Color,int);};
struct LC36Engine;struct LC36Title;struct LC36Rect;
struct LC36Console:LC36XConsole{virtual ~LC36Console();virtual void resize(int,int);virtual bool input(LC36Event*);virtual void update();virtual void render();virtual void open();virtual void close();virtual int frameKind();virtual void trigger(const string&,int);int state;LC36Engine*engine;LC36Title*title;LC36Console(LC36XConsole*,int,int,int,int,int,bool,int);void frame(LC36Rect*,LC36Color,bool,bool);void baseRender();void animate48c3f0(string);};
static_assert(sizeof(LC36XCell)==20&&sizeof(LC36XConsole)==0x60&&sizeof(LC36Console)==0x6c,"actual console owners/layout");



struct LC36Def{int unknown0;string name;};
struct LC36ItemDef{char unknown0[0x24];string name;};
struct LC36EntityDef{char unknown0[0x1ac];string name;};
struct LC36Item{LC36ItemDef*def9b4350()throw();string name571db0(bool,bool);};
struct LC36HI{int id;LC36Item*get9b65b0()const throw();};
struct LC36MachineData{char unknown0[12];LC36ItemDef*item;LC36EntityDef*entity;};
struct LC36PropData{char unknown0[0x38];LC36MachineData*machine;};
struct LC36Prop{LC36PropData*data45cb30()throw();};
struct LC36HP{int id;LC36Prop*get9b64f0()const throw();};
struct LC36Machine{LC36ItemDef*def4afce0();LC36EntityDef*entity4afd50();LC36HP prop4aeb30()throw();LC36HI item4afcc0()throw();};extern LC36Machine*lc36_cec0fc;
struct LC36EffectDef;
struct LC36Effect{bool init50de10(LC36Engine*,LC36EffectDef*,const LC36Point&,const LC36Point&,const LC36Point*,const LC36Point*,int);};
struct LC36Engine{LC36Effect*acquire50fb50();};
extern LC36EffectDef*lc36_cebdb4,*lc36_cebd6c,*lc36_cebda8,*lc36_cebd70,*lc36_cebdb8,*lc36_cebd78[];
extern LC36Point lc36_cfbec0;
extern string lc36_cfd4d0[];
extern vector<LC36Def*>lc36_d35b58;
extern vector<LC36ItemDef*>lc36_d2d1c4;
extern vector<LC36EntityDef*>lc36_d25de0;
struct LC36Record{int unknown0;bool flag;LC36Def*def;char unknownc[8];LC36EntityDef*entity;};extern vector<LC36Record*>lc36_d02cb4;extern bool lc36_d28e75;
struct LC36WeaponRef{int type,value;bool flag;};
string lc36_truncate408490(const string&,int);
string& lc36_padLeft408090(string&,unsigned int,char);
string lc36_intToString4051f0(int);
bool lc36_contains9daf80(int,int,int)throw();
int lc36_tier4347e0(int,int)throw();
struct LC36MachineTarget:LC36Console{bool isTarget;LC36WeaponRef*record;int chance,key,status;string label;virtual ~LC36MachineTarget();virtual void trigger(const string&,int);};
#define FX(record,point) do {engine->acquire50fb50()->init50de10(engine,record,point,lc36_cfbec0,0,0,9);}while(false)
void LC36MachineTarget::trigger(const string&command,int value){
 if(command=="content"){
  string s;s+=(unsigned char)key;
  if(status==0){print(0,0,s);FX(lc36_cebdb4,LC36Point(0,0));print(2,0,"-");FX(lc36_cebd6c,LC36Point(2,0));print(4,0,"[");FX(lc36_cebdb4,LC36Point(4,0));}
  string output=lc36_cfd4d0[record?record->type:111];int sx=output.find('*');
  if(record&&sx!=string::npos){
   output.erase(output.begin()+sx);
   switch(record->type){
   case 0:
    output.insert(output.begin()+sx,lc36_d35b58[record->value]->name.begin(),lc36_d35b58[record->value]->name.end());
    if(lc36_d28e75){for(int i=0;i<lc36_d02cb4.size();i++){if(lc36_d02cb4[i]->def==lc36_d35b58[record->value]){if(!lc36_d02cb4[i]->flag)output.insert(output.begin()+sx-2,'!');break;}}}break;
   case 1:output.insert(output.begin()+sx,lc36_d2d1c4[record->value]->name.begin(),lc36_d2d1c4[record->value]->name.end());break;
   case 2:output.insert(output.begin()+sx,lc36_d25de0[record->value]->name.begin(),lc36_d25de0[record->value]->name.end());break;
   case 3:output.insert(output.begin()+sx,lc36_d25de0[record->value]->name.begin(),lc36_d25de0[record->value]->name.end());
    if(lc36_d28e75){for(int i=0;i<lc36_d02cb4.size();i++){if(lc36_d02cb4[i]->entity==lc36_d25de0[record->value]){if(!lc36_d02cb4[i]->flag)output.insert(output.begin()+sx-2,'!');break;}}}break;
   case 67:switch(status){case 0:{LC36ItemDef*item=lc36_cec0fc->def4afce0();LC36EntityDef*entity=lc36_cec0fc->entity4afd50();string&name=item?item->name:entity->name;output.insert(output.begin()+sx,name.begin(),name.end());break;}
     case 1:output="No Schematic Loaded";break;
     case 2:output="Building "+(lc36_cec0fc->prop4aeb30().get9b64f0()->data45cb30()->machine->item?lc36_cec0fc->prop4aeb30().get9b64f0()->data45cb30()->machine->item->name:lc36_cec0fc->prop4aeb30().get9b64f0()->data45cb30()->machine->entity->name);break;
    }break;
   case 77:switch(status){case 0:{LC36HI item=lc36_cec0fc->item4afcc0();output.insert(output.begin()+sx,item.get9b65b0()->def9b4350()->name.begin(),item.get9b65b0()->def9b4350()->name.end());break;}
     case 1:output="No Component Scanned";break;
     case 2:output="Repairing "+lc36_cec0fc->item4afcc0().get9b65b0()->name571db0(false,false);break;
    }break;
   case 95:switch(status){case 0:{LC36HI entityID=lc36_cec0fc->item4afcc0();string name=entityID.get9b65b0()->name571db0(false,false);output.insert(output.begin()+sx,name.begin(),name.end());break;}
     case 1:output="No Component Inserted";break;
     case 2:output="Scanned "+lc36_cec0fc->item4afcc0().get9b65b0()->name571db0(false,false);break;
    }break;
   }
  }
  int left=-1,r1=-1;
  for(int i=0;i<output.size();i++){if(output[i]=='~'){output.erase(output.begin()+i);if(left==-1)left=i;else{r1=i-1;break;}}}
  label=output;output=lc36_truncate408490(output,34);print(5,0,output);
  for(int i=0;i<output.size();i++){FX(status?lc36_cebda8:lc36_contains9daf80(left,i,r1)?lc36_cebd70:lc36_cebdb8,LC36Point(i+5,0));}
  int x;
  if(status==0){x=output.size()+5;print(x,0,"]");FX(lc36_cebdb4,LC36Point(x,0));}
  if(isTarget){x=output.size()+(status?1:2)+5;setCharRow(x,0,width()-4-x,'-');do{for(int i=LC36Point(x,0).x;i<LC36Point(x,0).x+width()-4-x;i++){engine->acquire50fb50()->init50de10(engine,lc36_cebd6c,LC36Point(i,LC36Point(x,0).y),lc36_cfbec0,0,0,9);}}while(false);}
  int chance=record&&status==0?this->chance:-1;
  string row=chance==-1?string("N/A"):lc36_intToString4051f0(chance)+"%";
  lc36_padLeft408090(row,4,' ');x=width()-4;print(x,0,row);
  do{for(int i=LC36Point(x,0).x;i<LC36Point(x,0).x+row.size();i++){engine->acquire50fb50()->init50de10(engine,chance==-1?lc36_cebd6c:lc36_cebd78[lc36_tier4347e0(chance,100)],LC36Point(i,LC36Point(x,0).y),lc36_cfbec0,0,0,9);}}while(false);
 }
}
