// BS::place6cd110: prefab placement (terrain, machines, props, entities, items).
// Private partial ABI views; names and untouched fields are placeholders.
// NOTE: placeholder names / placeholder layouts throughout.
#include <string>
#include <vector>
#include "rng.h"
using std::string; using std::vector;
extern RNG rng;

struct GqPoint{int x,y;GqPoint();GqPoint(int);GqPoint(int,int);GqPoint(const GqPoint&)throw();GqPoint(const GqPoint&,int,int);GqPoint(const GqPoint&,const GqPoint&);GqPoint&operator=(const GqPoint&);
 void set40a010(int,int);void set40a060(const GqPoint&,int,int);int random40c130()throw();bool contains40c190(int);void fromString40a0c0(string);void parseRange40bf80(const string&);GqPoint add409b60(const GqPoint&)const;int dist409fb0(const GqPoint&);};
struct GqRect{int x1,y1,x2,y2;GqRect();GqRect(const GqPoint&,int,int);GqRect(const GqPoint&,const GqPoint&);bool parse40b480(const string&);void offset40bdd0(const GqPoint&);void clamp40bc40(const GqPoint&,const GqPoint&);};
struct GqColor{unsigned char r,g,b,a;GqColor(const GqColor&);bool operator==(GqColor);};
struct GqXCell{GqColor*getBack416f60();int ch9b8f00();};
struct GqLayer{int width9fcd80();int height9b8f00();GqXCell*at9cdf20(int,int);GqXCell*atPoint9d2930(const GqPoint&);};
struct GqPrefab{vector<GqLayer*>layers;char p10[0x3c];int defIndex;GqPoint offset;int rotation;bool flip;};
struct GqObj{bool reset;vector<string>conds;int chance;bool chanceEach;string name;int ch;int type;string spec;vector<int>optTypes;vector<string>optConds;vector<string>optArgs;void fillMask455c10(vector<bool>&);};
struct GqPrefabDef{char p0[0x24];vector<GqObj*>objs;};
struct GqTerrain{int id;};
struct GqItemDef{int id;char p4[0x48];int f4c;char p50[0x14];int f64;char p68[8];int slot;char p74[0x195];bool f209;};
struct GqPropRec{char p0[0x8c];int f8c;};
struct GqPropDef{int id;char p4[0x38];vector<GqLayer*>layers;char p4c[0xa8];int kind;char pf8[0x20];int f118;char p11c[0x24];int f140;int f144;GqPoint range148;int f150;GqItemDef*f154;};
struct GqPartOpt{int item;int count;int weight;};
struct GqEntityDef{char p0[0x9c];int size;char pa0[0xc0];vector<vector<GqPartOpt*> >parts;};
struct GqPair{int*a;int b;GqPair(int*,int);};
struct GqHack{int a,b,c;GqHack(int,int);};
struct GqShot{char d[0x10];GqShot(GqPoint,int,int);};
struct GqParty{char d[0x38];GqParty(int,struct GqHE,int,int,int);};
struct GqProp;struct GqEntity;struct GqItem;struct GqGroup;struct GqLoc{int a;int type;int depth;int f46ed20();};
struct GqHP{int id;GqHP();GqProp*operator->()const;bool isNull()const;bool valid()const;};
struct GqHE{int id;GqHE();GqEntity*operator->()const;bool isNull()const;bool valid()const;};
struct GqHI{int id;GqHI();GqItem*operator->()const;bool isNull()const;};
struct GqHG{int id;GqHG();GqGroup*operator->()const;};
struct GqHL{int id;GqHL();GqLoc*operator->()const;};
struct GqMachineRec{GqHP prop;char p4[8];int fc;bool f45c160(int,int);void f45bbe0(GqHack*);};
struct GqLink{int a;int group;};
struct GqProp{void f45cc50(const GqPoint&);void f665b10(int,int);GqPair*f45c800(int);void f45cee0(GqPair*);void disable65ed00();void f451400(int);void f65e8a0(GqXCell*);
 const string&getTag45c590();GqPropRec*getDef9b8f00();int f44ab40();GqLink*f44b020();void f65f170();};
struct GqCode{void append459d00(string&);};
struct GqAI{void follow5b2f80(GqHE,int);void f459410(const GqRect&);void f459540(const GqPoint&);void setBoth4594f0(const GqRect&);void f4593b0(const GqPoint&);void f451400(int);};
struct GqEntity{GqCode*code9b4350();void f45b070(const string&);GqAI*ai45b590();vector<GqHI>&inventory45ab00();int f5c92e0(int);void f6395d0(int,int);GqPair*f45ac40(int);void f45b340(GqPair*);
 void f5fd900(int,int);int f490840();void f5dea60(int,int);const GqPoint&getPosition45a4a0();int faction45a2c0();GqHG group45a3f0();};
struct GqGroup{int size9b4350();};
struct GqItem{int type44aec0();void remove57dbe0(int,int,int,int);void f57a190();void f450460(int);int f9b6bf0();int f457880();const string&name457860();void addEffect4585a0(GqPair*);int effectValue457be0(int);
 void f44fc60(int);bool f457ff0();int f457fb0();bool f415ee0();void f458390(int);void setBroken5795b0(int,int);int f457f90();GqItemDef*def9b4350();void f57c090(int,int);GqPair*effect457b70(int);};
struct GqCell{int f45d0e0();void setProp45df50(GqHP);GqHP getProp();GqHI getItem();bool f45d6a0();bool f4550b0();bool f45d230();};
struct GqGrid{GqCell**atPoint(const GqPoint&);bool contains9b43b0(const GqPoint&);GqPoint size9b7930();};extern GqGrid gq_grid_cfd44c;
template<class T>struct GqWL{vector<T>values;vector<int>weights;int total;GqWL();~GqWL();void addUnique(T,int);void add(T,int);int size9b81d0();T&pick();bool empty9b81b0();bool pick9ba6a0(T&);};
struct GqBS{char p0[0xc0];GqWL<int>wlc0;char pe4[0x64];vector<GqPoint>v148;char p158[0x70];vector<GqShot*>v1c8;char p1d8[0x1b8];vector<GqHI>v390;vector<int>v3a0;char p3b0[0x1b0];vector<string>v560;char p570[0x14];vector<GqPoint>v584;vector<GqHE>v594;vector<vector<GqHE> >v5a4;
 void place6cd110(GqPrefab&,int,bool,float);
 void f6c38a0(GqRect*,vector<GqPoint>*,float,GqTerrain*);void f6dd0e0(const GqPoint&,int);GqMachineRec*placeMachine6c70a0(int,const GqPoint&,int,bool,bool);void f464e60(GqHP);
 GqPoint f6c6d10(vector<GqPoint>&,const GqPoint&);bool placeProp6c67b0(GqPropDef*,const GqPoint&,int,int,int);GqEntityDef*f6c5600(int,int,bool,bool);GqHE placeEntity6c58c0(GqEntityDef*,const GqPoint&,int,bool,int,int,bool);
 GqHI f6c5400(GqItemDef*,const GqPoint&);GqItemDef*selectRandomItem6c3bc0(int,int,int);GqItemDef*selectRandomItemOfRating6c40e0(int,int,int,int,int,int,int);void f464f60(GqHI);void f465060(GqHI);
 GqHI f6c51d0(GqItemDef*,GqHE,int,int);};
extern GqBS*gq_world_cefc4c;
struct GqFactory{GqHP createE(GqPropDef*);GqHI createD(GqItemDef*,GqHE,int,int,int);};extern GqFactory*gq_factory_cefaa8;
struct GqOvermind{void f6827d0(GqParty*,int);};extern GqOvermind gq_overmind_cf6428;
struct GqGameData{int f789250(int)throw();int f46f4e0();};extern GqGameData gq_gd_d1e860;
extern GqColor gq_cf127c[];extern GqColor gq_d223c8;extern GqTerrain*gq_cefb88,*gq_cefb9c,*TERRAIN_CAVE_WALL,*gq_cefb84,*caveinThirdTerrain,*gq_cefbb0,*gq_cefba8,*gq_cefbac,*gq_d2c46c;
extern vector<int>gq_cfc1a4,gq_d2a2cc;extern vector<int*>gq_d2f0f8;extern vector<GqRect>gq_d22fa8;extern vector<GqPrefabDef*>gq_d15d9c;extern vector<GqTerrain*>gq_cfb844;extern string gq_cf0c28;extern GqHL gq_loc_d1e888;
extern vector<GqPropDef*>gq_cf35b0;extern vector<GqEntityDef*>gq_d35b58,gq_d25de0;extern vector<GqItemDef*>gq_d2d1c4;extern string gq_cf6730[],gq_d2d508[],gq_d2f798[],gq_d21bb8[],gq_cf3668[];
extern int gq_bb8370[],gq_bb8340[],gq_b96348[];extern vector<vector<GqHP> >gq_d31640;extern vector<vector<GqPoint> >gq_d2f32c;extern vector<vector<GqHI> >gq_cf3a10;
extern GqPoint gq_cf4538,gq_d2ecf8,gq_d21948[];extern int gq_cf462c,gq_cf4718;extern const float gq_ba780c,gq_c36fb8;extern float gq_ba65d8[];extern bool gq_b9651c[];
extern GqWL<GqItemDef*>gq_d2ae08,gq_d31700,gq_cf0c04,gq_cfe5ec;
int gq_stringToInt(const string&);string gq_intToString(int);
int gq_findColor9d4f10(GqColor*,int,GqColor);void gq_setTerrain6c9c90(const GqPoint&,GqTerrain*);void gq_appendIndices9e3380(vector<GqObj*>&,vector<unsigned>&);void gq_decode4351e0(string&);
bool gq_checkConditions6c3240(vector<string>&);void gq_eraseAt9ce6d0(vector<unsigned>&,unsigned&);bool gq_contains9db650(vector<signed char>&,char);void gq_split408700(const string&,char,vector<string>&);
string gq_randomString9d3280(vector<string>&);bool gq_findTerrain9db6a0(vector<GqTerrain*>&,const string&,GqTerrain*&);bool gq_findProp9d7710(vector<GqPropDef*>&,const string&,GqPropDef*&);
bool gq_checkSpawn6c36c0(string&);void gq_ccdf0(string&,GqObj*,unsigned,vector<int*>&,vector<int>&);void gq_ccf60(string&,GqObj*,unsigned,vector<int>&,int);bool gq_paren900870(string&,string&);
int gq_indexOfName4_9d7b80(vector<GqEntityDef*>&,const string&);int gq_f6c4600(string&);int gq_indexOfName9d74d0(vector<GqItemDef*>&,const string&);int gq_f6c4ac0(string&);int gq_findString9cda80(const string*,int,string);
void gq_floodFill6cccb0(GqLayer*,int,int,vector<GqPoint>&);GqPoint gq_randomPoint9d5350(vector<GqPoint>&)throw();bool gq_containsRecord9db330(vector<int>&,int);int gq_indexOf9d4660(vector<int>&,int);
GqPropDef*gq_randomRec9d5d00(vector<GqPropDef*>&);GqItemDef*gq_randomRec9d5d00(vector<GqItemDef*>&);void gq_eraseAt9d5190(vector<GqPoint>&,unsigned);void gq_parseParts5c2530(vector<string>&,vector<vector<GqPartOpt*> >&,string&);
bool gq_findEntity9d7530(vector<GqEntityDef*>&,const string&,GqEntityDef*&);int gq_maxInt9cdb60(int,int);int gq_minInt9cdb30(int,int);bool gq_containsString9d3fe0(vector<string>&,string);void gq_eraseStep9d3d90(vector<string>&,unsigned&);
bool gq_findItem9d7a40(vector<GqItemDef*>&,const string&,GqItemDef*&);void gq_shuffle9db7e0(vector<string>&);void gq_addUnique9db820(vector<string>&,string);void gq_append9db8c0(vector<string>&,vector<string>&);void gq_eraseFirst4077e0(string&);

#define GQ_CELL(p) (*gq_grid_cfd44c.atPoint(p))
#define GQ_ROTATE(pd,p,rot) switch(rot){case 0:p.x-=gq_cf35b0[pd->id]->layers.front()->width9fcd80()-1;p.y-=gq_cf35b0[pd->id]->layers.front()->height9b8f00()-1;break;case 1:p.y-=gq_cf35b0[pd->id]->layers.front()->width9fcd80()-1;break;case 2:break;case 3:p.x-=gq_cf35b0[pd->id]->layers.front()->height9b8f00()-1;break;}

void GqBS::place6cd110(GqPrefab&prefab,int id,bool flag,float chance){
 int cnt;
 GqLayer*cols;
 GqObj*current;
 int value;
 bool attempt;
 GqPrefabDef*prefix;
 string bottom;
 string log;
 GqObj*entity;
 if(id!=0x12f){
  vector<GqPoint> hits;
  GqLayer*col=prefab.layers.front();
  GqPoint p;
  GqTerrain*wall=flag?gq_cefb88:gq_cefb9c;
  int found;
  for(int x=0;x<col->width9fcd80();x++)for(int y=0;y<col->height9b8f00();y++){
   found=gq_findColor9d4f10(gq_cf127c,9,*col->at9cdf20(x,y)->getBack416f60());
   p.set40a010(prefab.offset.x+x,prefab.offset.y+y);
   switch(found){
   case 0:case 3:if(GQ_CELL(p)->f45d0e0()!=TERRAIN_CAVE_WALL->id)gq_setTerrain6c9c90(p,TERRAIN_CAVE_WALL);break;
   case 1:if(GQ_CELL(p)->f45d0e0()!=gq_cefb84->id)gq_setTerrain6c9c90(p,gq_cefb84);break;
   case 2:if(GQ_CELL(p)->f45d0e0()!=caveinThirdTerrain->id)gq_setTerrain6c9c90(p,caveinThirdTerrain);break;
   case 4:case 5:if(GQ_CELL(p)->f45d0e0()!=wall->id)gq_setTerrain6c9c90(p,wall);if(chance!=0)hits.push_back(p);break;
   case 6:if(GQ_CELL(p)->f45d0e0()!=gq_cefbb0->id)gq_setTerrain6c9c90(p,gq_cefbb0);break;
   case 7:if(GQ_CELL(p)->f45d0e0()!=gq_cefba8->id)gq_setTerrain6c9c90(p,gq_cefba8);break;
   case 8:if(GQ_CELL(p)->f45d0e0()!=gq_cefbac->id)gq_setTerrain6c9c90(p,gq_cefbac);break;
   }
  }
  if(!hits.empty())f6c38a0(0,&hits,chance,gq_d2c46c);
  gq_cfc1a4.push_back(id);
  gq_d22fa8.push_back(GqRect(prefab.offset,col->width9fcd80(),col->height9b8f00()));
 }
 prefix=gq_d15d9c[prefab.defIndex];
 vector<GqObj*>&element=gq_d15d9c[prefab.defIndex]->objs;
 vector<unsigned> orders;
 gq_appendIndices9e3380(element,orders);
 attempt=false;
 for(unsigned i=0;i<orders.size();i++){
  entity=element[orders[i]];
  if(entity->reset)attempt=false;
  if(!entity->conds.empty()&&entity->conds[0][0]!='`'){
   for(unsigned j=0;j<entity->conds.size();j++)gq_decode4351e0(entity->conds[j]);
   if(!gq_checkConditions6c3240(entity->conds)){attempt=true;gq_eraseAt9ce6d0(orders,i);continue;}
  }
  if(attempt){gq_eraseAt9ce6d0(orders,i);continue;}
  if(entity->chance!=0&&!entity->chanceEach&&!rng.chance(entity->chance)){gq_eraseAt9ce6d0(orders,i);continue;}
 }
 vector<signed char> line;
 signed char mode;
 while(1){
  mode='-';
  for(unsigned i=0;i<orders.size();i++){
   string&name=element[orders[i]]->name;
   if(name[0]!='-'&&!gq_contains9db650(line,name[0])){mode=name[0];break;}
  }
  if(mode=='-')break;
  GqWL<int> wl;
  for(unsigned i=0;i<orders.size();i++){
   string&name=element[orders[i]]->name;
   if(name[0]==mode){
    unsigned pos=name.find('_',0);
    if(pos==string::npos)wl.addUnique(gq_stringToInt(string(name.begin()+1,name.end())),100);
    else wl.addUnique(gq_stringToInt(string(name.begin()+1,name.begin()+pos)),gq_stringToInt(string(name.begin()+pos+1,name.end())));
   }
  }
  if(wl.size9b81d0()<=1){string s;s+=mode;}
  else{
   int chosen=wl.pick();
   for(unsigned i=0;i<orders.size();i++){
    string&name=element[orders[i]]->name;
    if(name[0]==mode){
     unsigned pos=name.find('_',0);
     if(chosen!=(pos==string::npos?gq_stringToInt(string(name.begin()+1,name.end())):gq_stringToInt(string(name.begin()+1,name.begin()+pos))))gq_eraseAt9ce6d0(orders,i);
    }
   }
  }
  line.push_back(mode);
 }
 GqLayer*row=prefab.layers[1];
 GqPoint p2;
 for(int x=0;x<row->width9fcd80();x++)for(int y=0;y<row->height9b8f00();y++)
  if(*row->at9cdf20(x,y)->getBack416f60()==gq_d223c8){
   p2.set40a010(prefab.offset.x+x,prefab.offset.y+y);
   f6dd0e0(p2,row->at9cdf20(x,y)->ch9b8f00()-0x1f);
  }
 if(orders.empty())return;
 vector<string> hidden;
 string text;
 vector<GqPoint> tail;
 vector<string> tags;
 vector<int> edges;
 vector<int> output;
 vector<GqHP> other;
 string title;
 GqPoint vec(prefab.offset);
 GqLayer*leaf;
 int kk;
 GqPoint root;
 cols=prefab.layers[3];
 leaf=prefab.layers[2];
 for(int x=0;x<cols->width9fcd80();x++)for(int y=0;y<cols->height9b8f00();y++){
  if(cols->at9cdf20(x,y)->ch9b8f00()!=0x20){
   kk=cols->at9cdf20(x,y)->ch9b8f00();
   value=-1;
   for(unsigned i=0;i<orders.size();i++)if(element[orders[i]]->ch==kk){value=orders[i];break;}
   if(value==-1)continue;
   current=element[value];
   if(!current->chanceEach||rng.chance(current->chance)){
    switch(current->type){
    case 0:{
     GqTerrain*t=0;
     gq_decode4351e0(current->spec);
     if(current->spec[0]=='&')t=gq_cfb844[gq_stringToInt(string(current->spec.begin()+1,current->spec.end()))];
     else{
      hidden.clear();
      gq_split408700(current->spec,'|',hidden);
      text=gq_randomString9d3280(hidden);
      if(!gq_findTerrain9db6a0(gq_cfb844,text,t))goto end0;
     }
     gq_setTerrain6c9c90(GqPoint(vec,x,y),t);
     end0:;
    }break;
    case 1:{
     vector<int> hits;
     vector<int*> total2;
     vector<int> score;
     gq_decode4351e0(current->spec);
     title=current->spec;
     if(title==gq_cf0c28)title+=gq_intToString(gq_loc_d1e888->depth);
     GqPropDef*res;
     if(title[0]=='&')res=gq_cf35b0[gq_stringToInt(string(title.begin()+1,title.end()))];
     else if(!gq_findProp9d7710(gq_cf35b0,title,res))continue;
     vector<bool> ranks;
     current->fillMask455c10(ranks);
     if(res->kind==0){
      GqPoint first(-1);
      for(unsigned i=0;i<current->optTypes.size();i++){
       if(!ranks[i]||!gq_checkSpawn6c36c0(current->optConds[i]))continue;
       string&arg=current->optArgs[i];
       gq_decode4351e0(arg);
       switch(current->optTypes[i]){
       case 0:first.fromString40a0c0(arg);break;
       case 6:gq_ccdf0(log,current,i,total2,score);break;
       case 5:gq_ccf60(log,current,i,hits,1);break;
       }
      }
      GqPoint dy(vec,x,y);
      GqPoint ny;
      bool found=false;
      if(first.x==-1){ny=dy;found=true;}
      else for(int k=0;k<20;k++){
       ny.set40a060(dy,rng.rangeInt(-first.x,first.x),rng.rangeInt(-first.y,first.y));
       if(gq_grid_cfd44c.contains9b43b0(ny)&&GQ_CELL(ny)->getProp().isNull()){found=true;break;}
      }
      if(!found){}
      else if(GQ_CELL(ny)->getProp().valid()){}
      else{
      GqHP prop=gq_factory_cefaa8->createE(res);
      GQ_CELL(ny)->setProp45df50(prop);
      prop->f45cc50(ny);
      if(!hits.empty()){
       for(unsigned i=0;i<hits.size();i++)prop->f665b10(hits[i],1);
       f464e60(prop);
      }
      for(unsigned i=0;i<total2.size();i++){
       if(prop->f45c800(*total2[i]))prop->f45c800(*total2[i])->b+=score[i];
       else prop->f45cee0(new GqPair(total2[i],score[i]));
      }
      }
     }else if(res->kind==1){
      int kind=2;
      bool changed=false,open=false,disabled=false;
      tags.clear();
      for(unsigned i=0;i<current->optTypes.size();i++){
       if(!ranks[i]||!gq_checkSpawn6c36c0(current->optConds[i]))continue;
       string&arg=current->optArgs[i];
       gq_decode4351e0(arg);
       switch(current->optTypes[i]){
       case 6:gq_ccdf0(log,current,i,total2,score);break;
       case 5:gq_ccf60(log,current,i,hits,1);break;
       case 7:kind=gq_stringToInt(arg);break;
       case 8:
        hidden.clear();
        gq_split408700(arg,'|',hidden);
        for(unsigned j=0;j<hidden.size();j++){
         if(hidden[j]=="CUSTOM")changed=true;
         else if(hidden[j]=="LIMITED")open=true;
         else if(hidden[j]=="DISABLED")disabled=true;
        }
        break;
       case 9:tags.push_back(arg);break;
       }
      }
      for(int k=0;k<gq_bb8370[prefab.rotation];k++)kind=gq_bb8340[kind];
      root=GqPoint(vec,x,y);
      GQ_ROTATE(res,root,kind)
      GqMachineRec*command=placeMachine6c70a0(res->id,root,gq_b96348[kind],changed,open);
      for(unsigned i=0;i<tags.size();i++){
       string&h=tags[i];
       int type=0x70;
       int index=-1;
       if(h.find("Query(",0)!=string::npos){
        if(gq_paren900870(h,title)){type=0;index=gq_indexOfName4_9d7b80(gq_d35b58,title);}
       }else if(h.find("Schematic(",0)!=string::npos){
        if(gq_paren900870(h,title)){
         type=1;
         index=gq_f6c4600(title);
         if(index==-1)index=gq_indexOfName9d74d0(gq_d2d1c4,title);
         if(index==-1){
          type=2;
          index=gq_f6c4ac0(title);
          if(index==-1)index=gq_indexOfName4_9d7b80(gq_d25de0,title);
         }
        }
       }else if(h.find("Analysis(",0)!=string::npos){
        if(gq_paren900870(h,title)){type=3;index=gq_indexOfName4_9d7b80(gq_d25de0,title);}
       }else if(h.find("Prototypes",0)!=string::npos&&h.find("Inventory(",0)==string::npos){
        type=4;
        index=command->fc+1;
       }else if(h.find("Open",0)!=string::npos){
        unsigned pos=h.find('^',0);
        if(pos!=string::npos){
         type=5;
         index=gq_findString9cda80(gq_cf6730,5,string(h.begin()+pos+1,h.end()));
         edges.push_back(GQ_CELL(GqPoint(vec,x,y))->getProp()->f44ab40());
        }
       }else{
        type=gq_findString9cda80(gq_d2d508,0x70,h);
       }
       if(command->f45c160(type,index)&&type!=4){}
       else command->f45bbe0(new GqHack(type,index));
      }
      if(!hits.empty()){
       for(unsigned i=0;i<hits.size();i++)command->prop->f665b10(hits[i],1);
       f464e60(command->prop);
      }
      for(unsigned i=0;i<total2.size();i++){
       if(command->prop->f45c800(*total2[i]))command->prop->f45c800(*total2[i])->b+=score[i];
       else command->prop->f45cee0(new GqPair(total2[i],score[i]));
      }
      if(disabled)command->prop->disable65ed00();
     }else if(res->kind==2&&res->f118!=0){
      int kind=2;
      bool open=false;
      for(unsigned i=0;i<current->optTypes.size();i++){
       if(!ranks[i]||!gq_checkSpawn6c36c0(current->optConds[i]))continue;
       string&arg=current->optArgs[i];
       gq_decode4351e0(arg);
       switch(current->optTypes[i]){
       case 7:kind=gq_stringToInt(arg);break;
       case 8:if(arg=="DISABLED")open=true;break;
       }
      }
      for(int k=0;k<gq_bb8370[prefab.rotation];k++)kind=gq_bb8340[kind];
      root=GqPoint(vec,x,y);
      GQ_ROTATE(res,root,kind)
      unsigned last=gq_d31640.size();
      placeMachine6c70a0(res->id,root,gq_b96348[kind],0,0);
      if(gq_d31640.size()!=last&&open)gq_d31640.back()[0]->disable65ed00();
     }else{
      bool disabled=false;
      for(unsigned i=0;i<current->optTypes.size();i++){
       if(!ranks[i]||!gq_checkSpawn6c36c0(current->optConds[i]))continue;
       string&arg=current->optArgs[i];
       gq_decode4351e0(arg);
       switch(current->optTypes[i]){
       case 6:gq_ccdf0(log,current,i,total2,score);break;
       case 5:gq_ccf60(log,current,i,hits,1);break;
       case 8:
        hidden.clear();
        gq_split408700(arg,'|',hidden);
        for(unsigned j=0;j<hidden.size();j++)if(hidden[j]=="DISABLED")disabled=true;
        break;
       case 9:tags.push_back(arg);break;
       }
      }
      tail.clear();
      gq_floodFill6cccb0(leaf,x,y,tail);
      GqHP prop;
      gq_d31640.push_back(vector<GqHP>());
      gq_d2f32c.push_back(vector<GqPoint>());
      gq_d2a2cc.push_back(0);
      gq_cf3a10.push_back(vector<GqHI>());
      vector<GqHP>&machine=gq_d31640.back();
      int machineIndex=gq_d31640.size()-1;
      for(unsigned i=0;i<tail.size();i++){
       GqPoint pos=vec.add409b60(tail[i]);
       prop=gq_factory_cefaa8->createE(res);
       GQ_CELL(pos)->setProp45df50(prop);
       prop->f45cc50(pos);
       prop->f65e8a0(leaf->atPoint9d2930(tail[i]));
       machine.push_back(GQ_CELL(pos)->getProp());
       machine.back()->f451400(machineIndex);
       tail[i]=pos;
       if(i==0){
        if(!hits.empty()){
         for(unsigned j=0;j<hits.size();j++)prop->f665b10(hits[j],1);
         f464e60(prop);
        }
        for(unsigned j=0;j<total2.size();j++){
         if(prop->f45c800(*total2[j]))prop->f45c800(*total2[j])->b+=score[j];
         else prop->f45cee0(new GqPair(total2[j],score[j]));
        }
       }
      }
      if(disabled)prop->disable65ed00();
      f6c6d10(tail,GqPoint(-1));
      if(prop->getTag45c590()=="GAR_Relay"){
       int count=gq_cf4538.random40c130();
       if(gq_cf462c==5)count=(int)(count*gq_ba780c);
       for(int k=0;k<count;k++){
        GqItemDef*relay=gq_d2ae08.pick();
        v1c8.push_back(new GqShot(gq_randomPoint9d5350(tail),relay->id,gq_gd_d1e860.f789250((int)(gq_d2ecf8.random40c130()*relay->f64/100*gq_ba65d8[gq_cf4718]))));
       }
      }
      GqPoint spot=gq_randomPoint9d5350(tail);
      if(GQ_CELL(spot)->getProp()->getDef9b8f00()->f8c!=0)v148.push_back(spot);
     }
    }break;
    case 2:{
     GqPropDef*res=0;
     int level=3;
     int newValue=0;
     int maxScore=0;
     bool updated=false;
     GqPoint ratio(-1);
     vector<bool> ranks;
     current->fillMask455c10(ranks);
     for(unsigned i=0;i<current->optTypes.size();i++){
      if(!ranks[i]||!gq_checkSpawn6c36c0(current->optConds[i]))continue;
      string&arg=current->optArgs[i];
      gq_decode4351e0(arg);
      switch(current->optTypes[i]){
      case 0:ratio.fromString40a0c0(arg);break;
      case 1:level=gq_stringToInt(arg);break;
      case 2:newValue=gq_stringToInt(arg);
      case 10:maxScore=gq_stringToInt(arg);break;
      case 11:updated=gq_stringToInt(arg);break;
      }
     }
     if(maxScore!=0&&gq_containsRecord9db330(output,maxScore))res=(GqPropDef*)other[gq_indexOf9d4660(output,maxScore)]->getDef9b8f00();
     else{
      gq_decode4351e0(current->spec);
      if(current->spec[0]=='&')res=gq_cf35b0[gq_stringToInt(string(current->spec.begin()+1,current->spec.end()))];
      else{
       hidden.clear();
       gq_split408700(current->spec,'|',hidden);
       text=gq_randomString9d3280(hidden);
       if(text=="TRAP"){
        vector<GqPropDef*> traps;
        for(unsigned i=0;i<gq_cf35b0.size();i++)if(gq_cf35b0[i]->f140!=0&&gq_cf35b0[i]->f150==newValue)traps.push_back(gq_cf35b0[i]);
        if(traps.empty())goto end2;
        res=gq_randomRec9d5d00(traps);
       }else if(!gq_findProp9d7710(gq_cf35b0,text,res))goto end2;
      }
     }
     if(res!=0){
     GqPoint p(vec,x,y);
     GqPoint point;
     bool found=false;
     if(ratio.x==-1){point=p;found=true;}
     else for(int k=0;k<20;k++){
      point.set40a060(p,rng.rangeInt(-ratio.x,ratio.x),rng.rangeInt(-ratio.y,ratio.y));
      if(gq_grid_cfd44c.contains9b43b0(point)&&GQ_CELL(point)->f45d6a0()){found=true;break;}
     }
     if(!found)goto end2;
     if(GQ_CELL(point)->getProp().valid())goto end2;
     {
     int linked=-1;
     if(maxScore!=0&&gq_containsRecord9db330(output,maxScore))linked=other[gq_indexOf9d4660(output,maxScore)]->f44b020()->group;
     if(placeProp6c67b0(res,point,linked,level,-1)){
      output.push_back(maxScore);
      other.push_back(GQ_CELL(point)->getProp());
      if(updated)GQ_CELL(point)->getProp()->f65f170();
     }
     }
     }
     end2:;
    }break;
    case 5:{
     GqPoint first(1,100);
     GqPoint adj(-1);
     for(unsigned i=0;i<current->optTypes.size();i++){
      if(!gq_checkSpawn6c36c0(current->optConds[i]))continue;
      string&arg=current->optArgs[i];
      gq_decode4351e0(arg);
      switch(current->optTypes[i]){
      case 0:adj.fromString40a0c0(arg);break;
      case 12:first.parseRange40bf80(arg);break;
      }
     }
     {
     GqPoint p(vec,x,y);
     GqPoint ny;
     bool found=false;
     if(adj.x==-1){ny=p;found=true;}
     else for(int k=0;k<20;k++){
      ny.set40a060(p,rng.rangeInt(-adj.x,adj.x),rng.rangeInt(-adj.y,adj.y));
      if(gq_grid_cfd44c.contains9b43b0(ny)&&GQ_CELL(ny)->f4550b0()&&GQ_CELL(ny)->getProp().isNull()&&GQ_CELL(ny)->getItem().isNull()&&!GQ_CELL(ny)->f45d230()){found=true;break;}
     }
     if(found&&!GQ_CELL(ny)->f45d230()){
      vector<GqPoint> one(1,ny);
      f6c38a0(0,&one,first.random40c130()/100.0,gq_d2c46c);
     }
     }
    }break;
    }
   }
  }
 }
 vector<GqPoint> room;
 GqHE parent;
 vector<string> events;
 vector<string> closed;
 for(unsigned i=0;i<orders.size();i++){
  current=element[orders[i]];
  kk=current->ch;
  room.clear();
  for(int x=0;x<cols->width9fcd80();x++)for(int y=0;y<cols->height9b8f00();y++)
   if(cols->at9cdf20(x,y)->ch9b8f00()==kk)room.push_back(GqPoint(x,y));
  for(unsigned j=0;j<room.size();j++){
   if(current->chanceEach&&!rng.chance(current->chance))continue;
   switch(current->type){
   case 3:{
    GqPoint direction(-1);
    bool valid=false;
    string key;
    int energy=1;
    bool r1=false;
    bool old=false;
    int len=-1;
    GqEntityDef*defender;
    int speed=3;
    int factor=0x22;
    GqPoint child(-1);
    GqRect neighbor;neighbor.x1=-1;
    GqPoint closest(-1);
    int counter=0xe;
    GqRect areas;areas.x1=-1;
    bool dirty=false;
    bool player=false;
    int groupID=0xb;
    GqPoint steps(-1);
    GqPoint slots(-1);
    vector<vector<GqPartOpt*> > option;
    vector<vector<GqPartOpt*> > allies;
    vector<int> bonus;
    vector<int*> entities;
    vector<int> command;
    bool changed=false;
    vector<GqPoint> positions;
    GqHE shooter;
    vector<bool> flags;
    current->fillMask455c10(flags);
    for(unsigned i=0;i<current->optTypes.size();i++){
     if(!flags[i]||!gq_checkSpawn6c36c0(current->optConds[i]))continue;
     string&arg=current->optArgs[i];
     gq_decode4351e0(arg);
     switch(current->optTypes[i]){
     case 0:direction.fromString40a0c0(arg);break;
     case 4:valid=true;break;
     case 30:key=arg;break;
     case 2:energy=gq_stringToInt(arg);break;
     case 14:r1=gq_stringToInt(arg);break;
     case 15:old=gq_stringToInt(arg);break;
     case 16:
      if(arg=="BROKEN")len=0;
      else if(arg=="UNPOWERED")len=1;
      else if(arg=="DORMANT")len=2;
      else if(arg=="REWIRABLE")len=3;
      else len=gq_stringToInt(arg);
      break;
     case 1:speed=gq_stringToInt(arg);break;
     case 20:factor=gq_stringToInt(arg);break;
     case 25:child.fromString40a0c0(arg);break;
     case 26:
      if(!neighbor.parse40b480(arg)&&1)goto end3;
      neighbor.offset40bdd0(vec);
      neighbor.clamp40bc40(GqPoint(0,0),gq_grid_cfd44c.size9b7930());
      break;
     case 31:closest.fromString40a0c0(arg);break;
     case 21:counter=gq_stringToInt(arg);break;
     case 27:
      if(!areas.parse40b480(arg)&&1)goto end3;
      areas.offset40bdd0(vec);
      areas.clamp40bc40(GqPoint(0,0),gq_grid_cfd44c.size9b7930());
      break;
     case 28:dirty=true;break;
     case 22:if(j==0)player=true;break;
     case 23:if(j==0){player=true;groupID=gq_stringToInt(arg);}break;
     case 3:steps.parseRange40bf80(arg);break;
     case 18:slots.parseRange40bf80(arg);break;
     case 17:case 19:{
      hidden.clear();
      gq_split408700(arg,'|',hidden);
      string s;
      vector<vector<GqPartOpt*> >&list=current->optTypes[i]==17?allies:option;
      gq_parseParts5c2530(hidden,list,s);
     }break;
     case 6:if(0){}gq_ccdf0(log,current,i,entities,command);break;
     case 5:gq_ccf60(log,current,i,bonus,0);break;
     case 29:changed=true;break;
     }
    }
    gq_decode4351e0(current->spec);
    if(current->spec[0]=='&')defender=gq_d25de0[gq_stringToInt(string(current->spec.begin()+1,current->spec.end()))];
    else{
     hidden.clear();
     gq_split408700(current->spec,'|',hidden);
     text=gq_randomString9d3280(hidden);
     int cls=gq_findString9cda80(gq_d2f798,0x61,text);
     if(cls!=-1){
      defender=f6c5600(energy,cls,r1,old);
      if(defender==0)goto end3;
     }else if(!gq_findEntity9d7530(gq_d25de0,text,defender))goto end3;
    }
    positions.push_back(room[j]);
    gq_eraseAt9d5190(room,j);
    j--;
    if(!valid){
     int added;
     do{
      added=0;
      for(unsigned a=j+1;a<room.size();a++)for(unsigned b=0;b<positions.size();b++)
       if(room[a].dist409fb0(positions[b])==1){positions.push_back(room[a]);gq_eraseAt9d5190(room,a);a--;added++;break;}
     }while(added!=0);
    }
    for(unsigned k=0;k<positions.size();k++){
     if(defender->size>1){
      if(prefab.rotation!=2){
       switch(prefab.rotation){
       case 1:positions[k].y--;break;
       case 3:positions[k].x--;break;
       case 0:positions[k].x--;positions[k].y--;break;
       }
      }
      if(prefab.flip){
       switch(prefab.rotation){
       case 0:positions[k].x+=defender->size-1;break;
       case 1:positions[k].y+=defender->size-1;break;
       case 3:positions[k].y-=defender->size-1;break;
       case 2:positions[k].x-=defender->size-1;break;
       }
      }
     }
     GqPoint pt(vec,positions[k]);
     GqPoint u;
     bool ok=false;
     if(direction.x==-1){u=pt;ok=true;}
     else for(int m=0;m<20;m++){
      u.set40a060(pt,rng.rangeInt(-direction.x,direction.x),rng.rangeInt(-direction.y,direction.y));
      if(gq_grid_cfd44c.contains9b43b0(u)){ok=true;break;}
     }
     if(ok)shooter=placeEntity6c58c0(defender,u,speed,true,factor,counter,false);
     if(shooter.isNull()){}
     else{
     if(!key.empty()){
      if(key=="DER"){
       string s;
       shooter->code9b4350()->append459d00(s);
       shooter->f45b070(s);
      }else shooter->f45b070(key);
     }
     if(player){
      parent=shooter;
      if(groupID!=0xb)gq_overmind_cf6428.f6827d0(new GqParty(groupID,parent,-1,0,0),0);
      player=false;
     }else if(parent.valid())shooter->ai45b590()->follow5b2f80(parent,0);
     for(unsigned a=0;a<option.size();a++){
      GqWL<GqPartOpt*> wl;
      for(unsigned b=0;b<option[a].size();b++)wl.add(option[a][b],option[a][b]->weight);
      GqPartOpt*opt=wl.pick();
      for(int c=0;c<opt->count;c++)gq_factory_cefaa8->createD(gq_d2d1c4[opt->item],shooter,4,0,0)->f57a190();
     }
     if(!allies.empty()){
      vector<GqHI>&inv=shooter->inventory45ab00();
      for(unsigned a=0;a<inv.size();a++)if(inv[a]->type44aec0()<=3){inv[a]->remove57dbe0(0,0,1,1);a--;}
      for(unsigned a=0;a<allies.size();a++){
       GqWL<GqPartOpt*> wl;
       for(unsigned b=0;b<allies[a].size();b++)wl.add(allies[a][b],allies[a][b]->weight);
       GqPartOpt*opt=wl.pick();
       for(int c=0;c<opt->count;c++)if(shooter->f5c92e0(4)>=gq_d2d1c4[opt->item]->f4c)gq_world_cefc4c->f6c51d0(gq_d2d1c4[opt->item],shooter,1,0);
      }
     }
     for(unsigned a=0;a<bonus.size();a++)shooter->f6395d0(bonus[a],1);
     for(unsigned a=0;a<entities.size();a++){
      if(shooter->f45ac40(*entities[a]))shooter->f45ac40(*entities[a])->b+=command[a];
      else shooter->f45b340(new GqPair(entities[a],command[a]));
     }
     switch(len){
     case -1:break;
     case 0:shooter->f5fd900(8,0);break;
     case 1:shooter->f5fd900(6,0);break;
     case 2:shooter->f5fd900(2,0);break;
     case 3:shooter->f5fd900(4,9999999);break;
     default:shooter->f5fd900(4,len);break;
     }
     if(steps.y!=-1)shooter->f5dea60(gq_maxInt9cdb60(1,steps.random40c130()*shooter->f490840()/100),0);
     if(slots.y!=-1){
      vector<GqHI>&inv=shooter->inventory45ab00();
      for(unsigned a=0;a<inv.size();a++)inv[a]->f450460(gq_maxInt9cdb60(1,slots.random40c130()*inv[a]->f9b6bf0()/100));
     }
     if(factor==3){
      if(child.x!=-1){
       GqRect r(GqPoint(shooter->getPosition45a4a0(),-child.x,-child.y),GqPoint(shooter->getPosition45a4a0(),child.x,child.y));
       r.clamp40bc40(GqPoint(0,0),gq_grid_cfd44c.size9b7930());
       shooter->ai45b590()->f459410(r);
      }else if(neighbor.x1!=-1)shooter->ai45b590()->f459410(neighbor);
     }else if(factor==0x19){
      if(closest.x==-1){}
      else shooter->ai45b590()->f459540(closest);
     }
     if(areas.x1!=-1)shooter->ai45b590()->setBoth4594f0(areas);
     if(dirty){
      shooter->ai45b590()->f4593b0(GqPoint(-1));
      shooter->ai45b590()->f4593b0(shooter->getPosition45a4a0());
      shooter->ai45b590()->f4593b0(GqPoint(-1));
     }
     if(!changed&&shooter->faction45a2c0()==0x1a&&shooter->group45a3f0()->size9b4350()==3){
      shooter->ai45b590()->f451400(1);
      v584.push_back(shooter->getPosition45a4a0());
      v594.push_back(shooter);
      v5a4.push_back(vector<GqHE>());
     }
     }
    }
    end3:;
   }break;
   case 4:{
    GqItemDef*ex=0;
    GqPoint begin(-1);
    GqPoint branch(1);
    bool removed=false;
    int num2=0;
    bool sy=false;
    bool open=false;
    bool closest=false;
    int cx=-1;
    GqPoint cost(-1);
    bool clean=false;
    bool door=false;
    int groupID=2;
    bool seen=false;
    GqPoint dest(0);
    vector<int> command;
    vector<int*> queue;
    vector<int> frontier;
    bool failed=false;
    vector<string> record;
    vector<GqPoint> positions;
    GqHI robot;
    int elem;
    vector<bool> flags;
    current->fillMask455c10(flags);
    for(unsigned i=0;i<current->optTypes.size();i++){
     if(!flags[i]||!gq_checkSpawn6c36c0(current->optConds[i]))continue;
     string&arg=current->optArgs[i];
     gq_decode4351e0(arg);
     switch(current->optTypes[i]){
     case 0:begin.fromString40a0c0(arg);break;
     case 36:branch.parseRange40bf80(arg);break;
     case 4:removed=true;break;
     case 33:num2=gq_stringToInt(arg);break;
     case 37:sy=true;break;
     case 34:open=true;break;
     case 35:closest=true;break;
     case 32:
      if(arg[0]=='+'){
       string s(arg);
       gq_eraseFirst4077e0(s);
       cx=gq_minInt9cdb30(gq_loc_d1e888->f46ed20()+gq_stringToInt(s),10);
      }else cx=gq_stringToInt(arg);
      break;
     case 3:cost.parseRange40bf80(arg);break;
     case 38:clean=true;break;
     case 39:door=true;break;
     case 2:groupID=gq_stringToInt(arg);break;
     case 40:dest.parseRange40bf80(arg);break;
     case 6:gq_ccdf0(log,current,i,queue,frontier);break;
     case 5:gq_ccf60(log,current,i,command,2);break;
     case 41:gq_split408700(arg,'|',record);break;
     }
    }
    gq_decode4351e0(current->spec);
    hidden.clear();
    gq_split408700(current->spec,'|',hidden);
    if(!v560.empty()){
     for(unsigned a=0;a<hidden.size();a++)if(gq_containsString9d3fe0(v560,hidden[a]))gq_eraseStep9d3d90(hidden,a);
     if(hidden.empty())goto end4;
    }
    if(!closed.empty()){
     for(unsigned a=0;a<hidden.size();a++)if(gq_containsString9d3fe0(closed,hidden[a]))gq_eraseStep9d3d90(hidden,a);
     if(hidden.empty())goto end4;
    }
    text=gq_randomString9d3280(hidden);
    elem=text=="ITEM"?0x1f:gq_findString9cda80(gq_cf3668,0x1f,text);
    if(text[0]=='&')ex=gq_d2d1c4[gq_stringToInt(string(text.begin()+1,text.end()))];
    else if(elem==2)gq_findItem9d7a40(gq_d2d1c4,"Scrap",ex);
    else if(text=="TRAP"){
     int depth=gq_gd_d1e860.f46f4e0();
     GqWL<GqItemDef*> wl;
     for(unsigned a=0;a<gq_cf35b0.size();a++)
      if(gq_cf35b0[a]->f140!=0x10&&gq_cf35b0[a]->f144!=0&&gq_cf35b0[a]->f154!=0&&(groupID==2||gq_cf35b0[a]->f150==groupID)&&(gq_cf35b0[a]->range148.y==0||gq_cf35b0[a]->range148.contains40c190(depth)))
       wl.add(gq_cf35b0[a]->f154,gq_cf35b0[a]->f144);
     ex=wl.pick();
    }
    else if(text=="RELAY_COUPLER")ex=gq_d2ae08.pick();
    else if(text=="AUTHCHIP")ex=gq_d31700.pick();
    else if(text=="AUTHCHIP_ROBOT")ex=gq_cf0c04.pick();
    else if(text=="AUTHCHIP_PART")ex=gq_cfe5ec.pick();
    else if(text.find("SCHEMATIC_ARCHIVE",0)!=string::npos){
     gq_findItem9d7a40(gq_d2d1c4,"Schematic Archive",ex);
     if(text=="SCHEMATIC_ARCHIVE_ITEM")failed=true;
    }
    else if(text.find("RANDOM_ITEM(",0)!=string::npos){
     int index=gq_f6c4600(text);
     if(index==-1)goto end4;
     ex=gq_d2d1c4[index];
    }
    else if(text.find("Part(",0)!=string::npos){
     GqWL<int> w;
     string desc(text.begin()+5,text.end()-1);
     GqEntityDef*x2;
     gq_findEntity9d7530(gq_d25de0,desc,x2);
     if(x2!=0){
      for(unsigned a=0;a<x2->parts.size();a++)for(unsigned b=0;b<x2->parts[a].size();b++)
       if(gq_b9651c[gq_d2d1c4[x2->parts[a][b]->item]->slot])w.add(x2->parts[a][b]->item,x2->parts[a][b]->weight);
      if(!w.empty9b81b0())ex=gq_d2d1c4[w.pick()];
     }
     if(ex==0)goto end4;
    }
    else if(elem==-1&&gq_findString9cda80(gq_d21bb8,0x12,text)!=-1){
     ex=cx==-1?selectRandomItem6c3bc0(num2,0x1f,gq_findString9cda80(gq_d21bb8,0x12,text)):selectRandomItemOfRating6c40e0(cx,0,num2,0x1f,gq_findString9cda80(gq_d21bb8,0x12,text),0x2a,0);
     if(ex==0&&num2==1)ex=cx==-1?selectRandomItem6c3bc0(0,0x1f,gq_findString9cda80(gq_d21bb8,0x12,text)):selectRandomItemOfRating6c40e0(cx,0,0,0x1f,gq_findString9cda80(gq_d21bb8,0x12,text),0x2a,0);
     if(ex==0)goto end4;
    }
    else if(elem==-1&&!gq_findItem9d7a40(gq_d2d1c4,text,ex))goto end4;
    else if(elem!=-1){
     ex=cx==-1?selectRandomItem6c3bc0(num2,elem,0x12):selectRandomItemOfRating6c40e0(cx,0,num2,elem,0x12,0x2a,0);
     if(ex==0&&num2==1)ex=cx==-1?selectRandomItem6c3bc0(0,elem,0x12):selectRandomItemOfRating6c40e0(cx,0,0,elem,0x12,0x2a,0);
     if(ex==0)goto end4;
    }
    positions.push_back(room[j]);
    gq_eraseAt9d5190(room,j);
    j--;
    if(!removed){
     int added;
     do{
      added=0;
      for(unsigned a=j+1;a<room.size();a++)for(unsigned b=0;b<positions.size();b++)
       if(room[a].dist409fb0(positions[b])==1){positions.push_back(room[a]);gq_eraseAt9d5190(room,a);a--;added++;break;}
     }while(added!=0);
    }
    for(unsigned k=0;k<positions.size();k++){
     GqPoint pt(vec,positions[k]);
     GqPoint u;
     bool ok=false;
     if(begin.x==-1){u=pt;ok=true;}
     else for(int m=0;m<20;m++){
      u.set40a060(pt,rng.rangeInt(-begin.x,begin.x),rng.rangeInt(-begin.y,begin.y));
      if(gq_grid_cfd44c.contains9b43b0(u)){ok=true;break;}
     }
     if(ok)robot=f6c5400(ex,u);
     if(robot.isNull()){}
     else{
     switch(robot->f457880()){
     case 0:robot->f450460(branch.y==1?gq_d21948[gq_loc_d1e888->type].random40c130():branch.random40c130());break;
     case 1:
      if(robot->name457860()=="Schematic Archive"){
       if(!record.empty()){
        gq_shuffle9db7e0(record);
        for(unsigned a=0;a<record.size();a++){
         int index=gq_f6c4600(record[a]);
         if(index==-1)index=gq_indexOfName9d74d0(gq_d2d1c4,record[a]);
         if(index!=-1)robot->addEffect4585a0(new GqPair(gq_d2f0f8[0x4f],index));
         else{
          index=gq_indexOfName4_9d7b80(gq_d25de0,record[a]);
          if(index!=-1)robot->addEffect4585a0(new GqPair(gq_d2f0f8[0x4f],-index));
         }
         if(index!=-1)break;
        }
       }else if(failed){
        GqItemDef*sch;
        do{
         sch=cx==-1?selectRandomItem6c3bc0(num2,0x1f,0x12):selectRandomItemOfRating6c40e0(cx,0,num2,0x1f,0x12,0x2a,0);
         if(sch==0)break;
        }while(!sch->f209);
        if(sch)robot->addEffect4585a0(new GqPair(gq_d2f0f8[0x4f],sch->id));
       }else{
        int rid;
        if(wlc0.pick9ba6a0(rid))robot->addEffect4585a0(new GqPair(gq_d2f0f8[0x4f],-rid));
       }
       if(robot->effectValue457be0(0x4f)==0){robot->remove57dbe0(0,0,1,1);goto end4;}
      }
      break;
     case 2:robot->f44fc60(rng.rangeInt(0,gq_c36fb8));break;
     }
     if(sy&&robot->f457ff0())robot->f44fc60(robot->f457fb0());
     if(open&&robot->f415ee0())robot->f458390(0);
     if(closest)robot->setBroken5795b0(-2,0);
     if(cost.y!=-1)robot->f450460(gq_maxInt9cdb60(1,cost.random40c130()*robot->f9b6bf0()/100));
     if(robot->f457f90()==0x7c){
      if(dest.x>1000){GqPoint r(dest.x-1000,dest.y-1000);robot->f44fc60(r.random40c130());}
      else if(dest.y==0)robot->f44fc60(gq_gd_d1e860.f789250((int)(robot->def9b4350()->f64*gq_ba65d8[gq_cf4718])));
      else robot->f44fc60(gq_gd_d1e860.f789250((int)(robot->def9b4350()->f64*dest.random40c130()/100*gq_ba65d8[gq_cf4718])));
     }
     if(clean)gq_addUnique9db820(events,text);
     if(door)gq_addUnique9db820(closed,text);
     if(!command.empty()){
      for(unsigned a=0;a<command.size();a++)robot->f57c090(command[a],1);
      f464f60(robot);
     }
     f465060(robot);
     for(unsigned a=0;a<queue.size();a++){
      if(robot->effect457b70(*queue[a]))robot->effect457b70(*queue[a])->b+=frontier[a];
      else robot->addEffect4585a0(new GqPair(queue[a],frontier[a]));
      if(*queue[a]==0x56){v390.push_back(robot);v3a0.push_back(0);}
     }
     }
    }
    end4:;
   }break;
   }
  }
 }
 if(!events.empty())gq_append9db8c0(v560,events);
}
GqPair::GqPair(int*,int){}
GqHack::GqHack(int,int){}
GqShot::GqShot(GqPoint,int,int){}
