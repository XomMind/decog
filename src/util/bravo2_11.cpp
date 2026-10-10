// NOTE: placeholder names and partial layouts; BS::postprocessGarrison (0x6e4dc0): applies the garrison
// type events (convoy, warlord, assembled collapse, derelict garrison, sapper phase).
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;
struct BV12Entity;struct BV12Prop;struct BV12Item;struct BV12Terrain {int id;};
struct BV12Point {int x,y;BV12Point();BV12Point(int,int);BV12Point &operator=(const BV12Point&);};
struct BV12Rect4 {int a,b,c,d;BV12Rect4();};
struct BV12XYWH {int x,y,w,h;};
struct BV12Area {int x1,y1,x2,y2;BV12Area();BV12Area(const BV12XYWH&);BV12Rect4 toRect();};
struct BV12HE {int id;BV12HE();bool isValid() const;BV12Entity *operator->() const;};
struct BV12HI {int id;bool isValid() const;BV12Item *operator->() const;};
struct BV12HP {int id;bool isValid() const;BV12Prop *operator->() const;};
struct BV12Dialogue;
struct BV12Entity {void unknown637bb0();int getAiType();int unknown5cecf0(const string&);void unknown6396f0(const string&,int);void unknown5fd900(int,int);void unknown5dcc70(int,int);};
struct BV12Link;
struct BV12Def {char pad[0x140];int type;};
struct BV12Prop {const string &name45c590();const BV12Point &position();bool unknown45c9d0(BV12Dialogue*);void unknown45ce10(int,int,int,BV12HE);int id44ab40();BV12Link *link45cb30();BV12Def *def();};
struct BV12Item {void remove57dbe0(int,int,bool,bool);int getCached();void setCached(int);};
struct BV12Cell {BV12HP getProp();BV12HE getEntity();BV12HI getItem();int unknown45d0e0();bool isPassableFor(BV12HE);void trigger45e110(int,int,BV12HE);bool isEdge();void unknown66a050(int,int,bool);bool field4550b0();void removeProp(int,int);};
struct BV12Grid {BV12Cell **at(int,int);BV12Cell **atPoint(const BV12Point&);int getWidth();int getHeight();void getRect(const BV12Point&,int,BV12Area&);BV12Area getArea();BV12Point getRandom_9cf050();};extern BV12Grid bv12_cells_cfd44c;
extern BV12Terrain *TERRAIN_EARTH,*TERRAIN_CAVE_WALL,*bv12_terrain_cefb9c;extern int bv12_d2c46c;
struct BV12LocInfo {bool inRange46ecb0();};
struct BV12HLoc {int id;BV12LocInfo *operator->() const;};extern vector<BV12HLoc> bv12_locations_d1e88c;
struct BV12GameData {int getDepthIndex();};extern BV12GameData bv12_gameData_d1e860;
extern vector<int> bv12_garrisonTypes_d1eb88;
struct BV12World {void unknown6c6b90(const BV12Point&,const string&,BV12Dialogue*,int);bool findPlaceableNear(const BV12Point&,BV12Point&,int);};extern BV12World *bv12_world_cefc4c;
struct BV12Raid {void spawnWarlordRaid_68e1f0(int);};extern BV12Raid bv12_overmind_cf6428;
struct BV12Machine {vector<BV12HE> &members416f40();};
struct BV12HM {int id;BV12Machine *operator->() const;};
extern vector<BV12Dialogue*> bv12_dialogues_d2c408;
template<class T> bool BV12_findByName(vector<T*>&,const string&,T*&);
extern vector<vector<BV12HP> > bv12_entries_d31640,bv12_props_d20248;
void getAdjacentCells(const BV12Point&,vector<BV12Point>&);
void sweepGetSurroundingCells(const BV12Point&,vector<BV12Point>&);
template<class T> void BV12_shuffle(vector<T>&);
int bv12_maxInt(int,int);
void logError(string location,string message);
struct BV12ItemRef {int id;int pad4;int weight;};
struct BV12Record {char pad[0x9c];int size;char pada0[0x160-0xa0];vector<vector<BV12ItemRef*> > items;};
struct BV12ItemType {char pad[0x70];int category;};extern vector<BV12ItemType*> bv12_itemTypes_d2d1c4;extern bool bv12_allowed_b9651c[];
int bv12_randomRec(vector<int>&);
struct BV12WL {BV12WL();~BV12WL();void add(int,int);int &pick();bool empty() const;char pad[0x24];};
extern int bv12_counter_cf65b4,bv12_value_cf65b8;
void bv12_logPhrase_5141b0(int,const string*,const string*,const string*,BV12HE,const BV12Point*);
struct BV12MoveCost;extern BV12MoveCost *bv12_costs_cefc30;
struct BV12Cartographer {bool findPath(const BV12Point&,const BV12Point&,BV12MoveCost*,void*,vector<BV12Point>&);};extern BV12Cartographer bv12_cartographer_cfe568;
struct BS {
 void unknown6c38a0(const BV12Rect4&,int,float,int);
 BV12Record *selectRobotOfClass(int,int,bool,bool);
 bool findPlaceableNear(const BV12Point&,BV12Point&,int);
 BV12HE placeEntity(BV12Record*,const BV12Point&,int,bool,int,int,bool);
 bool unknown6c65a0(BV12HE,const string&,bool);
 bool unknown71bc10(const BV12Point&,BV12Point&);
 BV12HI unknown6c5400(BV12ItemType*,const BV12Point&);
 int countPassableAdjacent(const BV12Point&);
 void unknown6c6770(BV12HP,BV12Dialogue*,int);
 void postprocessGarrison();
 char pad[0x4c];vector<BV12HM> machines;char pad5c[0xac0-0x5c];vector<int> zoneTypes;vector<BV12XYWH> zones;
};
void BS::postprocessGarrison() {
 if(!bv12_locations_d1e88c[bv12_locations_d1e88c.size()-2]->inRange46ecb0())
  return;
 switch(bv12_garrisonTypes_d1eb88[bv12_gameData_d1e860.getDepthIndex()]) {
 break;
 case 1:
  bv12_world_cefc4c->unknown6c6b90(BV12Point(0,0),"GAR_Cargo_Convoy_Timer",0,-1);
  break;
 case 2:
  if(rng.chance(50))
   bv12_world_cefc4c->unknown6c6b90(BV12Point(0,0),"GAR_Warlord_Attack",0,-1);
  else
   bv12_overmind_cf6428.spawnWarlordRaid_68e1f0(1);
  break;
 case 3:
  bv12_world_cefc4c->unknown6c6b90(BV12Point(0,0),"GAR_Assembled_Collapse",0,-1);
  break;
 case 4: {
  vector<BV12HE> &line=machines[3]->members416f40();
  while(line.size())
   line.front()->unknown637bb0();
  BV12Dialogue *text;
  if(BV12_findByName(bv12_dialogues_d2c408,"GAR_Checkpoint_Scan",text)) {
   for(unsigned i=0;i<bv12_entries_d31640.size();i++) {
    if(!bv12_entries_d31640[i].empty()&&bv12_entries_d31640[i].front()->name45c590()=="GAR_Door_Shootable") {
     BV12Area area;
     bv12_cells_cfd44c.getRect(bv12_entries_d31640[i].front()->position(),3,area);
     for(int x=area.x1;x<=area.x2;x++)
      for(int y=area.y1;y<=area.y2;y++)
       if((*bv12_cells_cfd44c.at(x,y))->getProp().isValid()&&(*bv12_cells_cfd44c.at(x,y))->getProp()->unknown45c9d0(text)) {
        (*bv12_cells_cfd44c.at(x,y))->getProp()->unknown45ce10(1,0,1,BV12HE());
        goto nextDoor;
       }
    }
nextDoor:;
   }
  }
  vector<BV12Point> cols;
  for(int x=0;x<bv12_cells_cfd44c.getWidth();x++)
   for(int y=0;y<bv12_cells_cfd44c.getHeight();y++) {
    if((*bv12_cells_cfd44c.at(x,y))->unknown45d0e0()==TERRAIN_CAVE_WALL->id) {
     if(rng.chance(10)) {
      cols.clear();
      getAdjacentCells(BV12Point(x,y),cols);
      for(unsigned k=0;k<cols.size();k++) {
       if((*bv12_cells_cfd44c.atPoint(cols[k]))->isPassableFor(BV12HE())) {
        (*bv12_cells_cfd44c.at(x,y))->trigger45e110(0,1,BV12HE());
        if(rng.chance(10)) {
         cols.clear();
         sweepGetSurroundingCells(BV12Point(x,y),cols);
         BV12_shuffle(cols);
         for(unsigned m=0;m<cols.size();m++)
          if((*bv12_cells_cfd44c.atPoint(cols[m]))->unknown45d0e0()==TERRAIN_EARTH->id) {
           (*bv12_cells_cfd44c.atPoint(cols[m]))->trigger45e110(0,1,BV12HE());
           break;
          }
        }
        break;
       }
      }
     }
    }
    else if((*bv12_cells_cfd44c.at(x,y))->isEdge()) {
     if(rng.chance(50))
      (*bv12_cells_cfd44c.at(x,y))->unknown66a050(bv12_terrain_cefb9c->id,2,false);
    }
    else if((*bv12_cells_cfd44c.at(x,y))->field4550b0()) {
     if((*bv12_cells_cfd44c.at(x,y))->getProp().isValid()) {
      if((*bv12_cells_cfd44c.at(x,y))->getProp()->id44ab40()!=-1&&(rng.chance(15)||(*bv12_cells_cfd44c.at(x,y))->getProp()->name45c590()=="GAR_Door_Shootable")&&(*bv12_cells_cfd44c.at(x,y))->getProp()->name45c590()!="GAR_Relay"&&(*bv12_cells_cfd44c.at(x,y))->getProp()->name45c590()!="GAR_Generator"&&(*bv12_cells_cfd44c.at(x,y))->getProp()->name45c590()!="GAR_RIF_Installer"&&(*bv12_cells_cfd44c.at(x,y))->getProp()->name45c590()!="GAR_Heavy_Assembler"&&(*bv12_cells_cfd44c.at(x,y))->getProp()->name45c590()!="GAR_QS_Assembler"&&!(*bv12_cells_cfd44c.at(x,y))->getProp()->link45cb30()) {
       cols.clear();
       getAdjacentCells(BV12Point(x,y),cols);
       for(unsigned n=0;n<cols.size();n++)
        if((*bv12_cells_cfd44c.atPoint(cols[n]))->isPassableFor(BV12HE())) {
         (*bv12_cells_cfd44c.at(x,y))->getProp()->unknown45ce10(1,0,1,BV12HE());
         break;
        }
      }
     }
     else if((*bv12_cells_cfd44c.at(x,y))->getItem().isValid()&&rng.chance(20)) {
      if(rng.chance(50))
       (*bv12_cells_cfd44c.at(x,y))->getItem()->remove57dbe0(0,0,true,true);
      else
       (*bv12_cells_cfd44c.at(x,y))->getItem()->setCached(bv12_maxInt(1,(*bv12_cells_cfd44c.at(x,y))->getItem()->getCached()*rng.rangeInt(40.0f,80.0f)/100));
     }
    }
   }
  for(unsigned j=0;j<bv12_props_d20248.size();j++) {
   if(bv12_props_d20248[j].empty()||bv12_props_d20248[j].front()->def()->type!=0xb)
    continue;
   for(int k=bv12_props_d20248[j].size()-1;k>=0;k--)
    (*bv12_cells_cfd44c.atPoint(bv12_props_d20248[j][k]->position()))->removeProp(0,4);
  }
  unknown6c38a0(bv12_cells_cfd44c.getArea().toRect(),0,0.1f,bv12_d2c46c);
  const int x2=10;
  BV12Record *r1=selectRobotOfClass(3,0x3c,false,true);
  if(!r1) {
   logError("BS::postprocessGarrison()","no Assembled data found");
   break;
  }
  BV12Point to;
  for(int a=0;a<x2;a++)
   for(int b=0;b<200;b++) {
    to=bv12_cells_cfd44c.getRandom_9cf050();
    if(findPlaceableNear(to,to,r1->size)) {
     BV12HE e=placeEntity(r1,to,5,true,0x22,0xe,false);
     if(e.isValid())
      e->unknown5fd900(8,0);
     break;
    }
   }
  const int y0=6;
  vector<int> tags;
  tags.push_back(0x10);
  tags.push_back(0xd);
  tags.push_back(0x15);
  tags.push_back(0x18);
  for(int a2=0;a2<10;a2++)
   for(int b2=0;b2<200;b2++) {
    to=bv12_cells_cfd44c.getRandom_9cf050();
    if(findPlaceableNear(to,to,1)) {
     r1=selectRobotOfClass(1,bv12_randomRec(tags),false,true);
     if(r1) {
      BV12HE e2=placeEntity(r1,to,3,true,0x22,0xe,false);
      if(e2.isValid()) {
       if(rng.chance(50))
        e2->unknown5fd900(8,0);
       else {
        e2->unknown5fd900(4,9999999);
        e2->unknown5dcc70(4,0);
       }
      }
      break;
     }
    }
   }
  const int y2=40;
  BV12WL value;
  for(unsigned i=0;i<tags.size();i++) {
   r1=selectRobotOfClass(1,tags[i],false,true);
   if(r1)
    for(unsigned j=0;j<r1->items.size();j++)
     for(unsigned k=0;k<r1->items[j].size();k++)
      if(bv12_allowed_b9651c[bv12_itemTypes_d2d1c4[r1->items[j][k]->id]->category])
       value.add(r1->items[j][k]->id,r1->items[j][k]->weight);
  }
  if(value.empty()) {}
  else
   for(int a3=0;a3<y2;a3++)
    for(int b3=0;b3<200;b3++) {
     to=bv12_cells_cfd44c.getRandom_9cf050();
     if(unknown71bc10(to,to)) {
      BV12HI item=unknown6c5400(bv12_itemTypes_d2d1c4[value.pick()],to);
      if(rng.chance(50))
       item->setCached(bv12_maxInt(1,item->getCached()*rng.rangeInt(40.0f,80.0f)/100));
      break;
     }
    }
  for(unsigned m=0;m<zoneTypes.size();m++) {
   if(zoneTypes[m]==0x72) {
    BV12Area room(zones[m]);
    for(int x=room.x1;x<=room.x2;x++)
     for(int y=room.y1;y<=room.y2;y++)
      if((*bv12_cells_cfd44c.at(x,y))->getEntity().isValid()&&(*bv12_cells_cfd44c.at(x,y))->getEntity()->getAiType()==3&&(*bv12_cells_cfd44c.at(x,y))->getEntity()->unknown5cecf0("GAR_Derelict_Freed")) {
       (*bv12_cells_cfd44c.at(x,y))->getEntity()->unknown6396f0("GAR_Derelict_Freed",1);
       unknown6c65a0((*bv12_cells_cfd44c.at(x,y))->getEntity(),"GAR_Derelict_Freed_Ass",false);
       goto nextZone;
      }
   }
nextZone:;
  }
  if(bv12_counter_cf65b4==0)
   bv12_value_cf65b8=rng.rangeInt(10.0f,50.0f);
  do {bv12_logPhrase_5141b0(0x19d,0,0,0,BV12HE(),0);} while(0);
  break;
 }
 case 5: {
  BV12Dialogue *gen;
  if(BV12_findByName(bv12_dialogues_d2c408,"GAR_Sapper_Phase_Gen",gen)) {
   for(unsigned i=0;i<bv12_entries_d31640.size();i++) {
    if(!bv12_entries_d31640[i].empty()&&bv12_entries_d31640[i].front()->name45c590()=="GAR_Generator") {
     BV12Point from;
     for(unsigned j=0;j<bv12_entries_d31640[i].size();j++)
      if(countPassableAdjacent(bv12_entries_d31640[i][j]->position())) {
       unknown6c6770(bv12_entries_d31640[i][j],gen,0);
       from=bv12_entries_d31640[i][j]->position();
       break;
      }
     BV12Point to;
     if(bv12_world_cefc4c->findPlaceableNear(from,to,1)) {
      BV12Point center(bv12_cells_cfd44c.getWidth()/2,bv12_cells_cfd44c.getHeight()/2);
      vector<BV12Point> path;
      if(bv12_cartographer_cfe568.findPath(to,center,bv12_costs_cefc30,0,path))
       for(unsigned k=0;k<path.size();k++)
        if((*bv12_cells_cfd44c.atPoint(path[k]))->isEdge())
         (*bv12_cells_cfd44c.atPoint(path[k]))->unknown66a050(bv12_terrain_cefb9c->id,2,false);
     }
     break;
    }
   }
  }
  break;
 }
 }
 bv12_garrisonTypes_d1eb88[bv12_gameData_d1e860.getDepthIndex()]=0;
}
