// NOTE: placeholder names and partial layouts; BS 0x6ff590: Garrison setup (checkpoint guard, door squads,
// Garrison Terminal placement, RIF installers, items and cave wall cleanup).
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;
struct BV11Entity;struct BV11AI;struct BV11Prop;struct BV11Terrain {int id;};
struct BV11Point {int x,y;BV11Point();BV11Point(int,int);BV11Point(const BV11Point&,int,int);BV11Point &operator=(const BV11Point&);};
struct BV11Rect {int x,y,w,h;BV11Rect();};
struct BV11HE {int id;BV11HE();bool isValid() const;BV11Entity *operator->() const;};
struct BV11HI {int id;bool isValid() const;};
struct BV11HP {int id;bool isValid() const;BV11Prop *operator->() const;};
struct BV11Trap;
struct BV11Trigger {BV11Trap *trap;int count;BV11Trigger(BV11Trap*,int);};
BV11Trigger::BV11Trigger(BV11Trap *trap_,int count_) {trap=trap_;count=count_;}
struct BV11Tag {int a,b,c;BV11Tag(int,int);};
BV11Tag::BV11Tag(int a_,int b_) {a=a_;b=b_;c=0;}
struct BV11Entity {void unknown45b340(BV11Trigger*);void unknown5fd900(int,int);BV11AI *getAI();};
struct BV11AI {void setFollowEntity(BV11HE,int);};
struct BV11Prop {const string &name45c590();int unknown457b10();};
struct BV11Cell {BV11HP getProp();BV11HI getItem();bool field4550b0();BV11Terrain *terrain();bool unknown66a630();void unknown66a050(int,int,bool);};
struct BV11Grid {BV11Cell **at(int,int);BV11Cell **atPoint(const BV11Point&);int getWidth();int getHeight();};extern BV11Grid bv11_cells_cfd44c;
extern BV11Terrain *TERRAIN_EARTH,*TERRAIN_CAVE_WALL;
struct BV11LocInfo {int depth46ed20();};
struct BV11HLoc {int id;BV11LocInfo *operator->() const;};extern BV11HLoc bv11_location_d1e888;
extern int bv11_chances_b9388c[];extern const int bv11_weights_b94368[];
struct BV11Record;
struct BV11Party {BV11Party(int,BV11HE,int,int,int);char pad[0x38];};
struct BV11Overmind {void unknown6827d0(BV11Party*,void*);};extern BV11Overmind bv11_overmind_cf6428;
struct BV11WL {BV11WL(const int*,int);~BV11WL();int &pick();void remove(int);char pad[0x24];};
extern vector<BV11Trap*> bv11_traps_d2f0f8;
template<class T> bool BV11_findByName(vector<T*>&,const string&,T*&);
bool bv11_anyContainsPoint(vector<vector<BV11Point> >&,const BV11Point&);
BV11Point bv11_popRandomPoint(vector<BV11Point>&);
struct BV11Layer {int getWidth();int getHeight();};
struct BV11Machine {int id;char pad[0x3c-4];vector<BV11Layer*> layers;};extern vector<BV11Machine*> bv11_machines_cf35b0;
bool bv11_findWallStrip(int,int,int,BV11Rect*,BV11Rect*,int*,int,bool,bool);
void bv11_fillRing(BV11Rect*,BV11Rect*,int,BV11Terrain*,int);
extern int bv11_dirTable_b96348[];extern int bv11_dirMap_bb8360[];
struct BV11Placed {void unknown45bbe0(BV11Tag*);};
struct BV11Lists {BV11Lists(int);char pad[0x34];};extern vector<BV11Lists*> bv11_lists_d39f1c;
extern vector<vector<BV11HP> > bv11_entries_d31640;
void sweepGetSurroundingCells(const BV11Point&,vector<BV11Point>&);
struct BS {
 BV11Record *unknown6c5600(int,int,bool,bool);
 BV11HE placeEntity(BV11Record*,const BV11Point&,int,bool,int,int,bool);
 BV11Placed *placeMachine(int,const BV11Point&,int,int,int);
 void garrison_6ff590();
 char pad[0x258];vector<int> installers;char pad268[0x2d0-0x268];vector<BV11HI> items;vector<BV11Point> itemPositions;
};
void BS::garrison_6ff590() {
 BV11Machine *door;
 BV11Trap *room;
 int pick,type,num2;
 BV11Record *rec,*start;
 int m2=bv11_location_d1e888->depth46ed20();
 if(rng.chance(bv11_chances_b9388c[m2])) {
  rec=unknown6c5600(1,0x1c,false,false);
  if(rec) {
   BV11HE g=placeEntity(rec,BV11Point(0x31,0x31),3,false,0x22,0xe,false);
   if(g.isValid())
    bv11_overmind_cf6428.unknown6827d0(new BV11Party(0,g,-1,0,0),0);
  }
 }
 vector<vector<BV11Point> > doors;
 BV11WL tags(bv11_weights_b94368,10);
 BV11Point origin;
 BV11HE robot;
 if(!BV11_findByName(bv11_traps_d2f0f8,"GAR_Checkpoint_Guard",room)) {}
 for(int x=0;x<bv11_cells_cfd44c.getWidth();x++)
  for(int y=0;y<bv11_cells_cfd44c.getHeight();y++) {
   if((*bv11_cells_cfd44c.at(x,y))->getProp().isValid()&&(*bv11_cells_cfd44c.at(x,y))->getProp()->name45c590()=="GAR_Door_Shootable"&&!bv11_anyContainsPoint(doors,BV11Point(x,y))) {
    bool visible=(*bv11_cells_cfd44c.at(x+1,y))->getProp().isValid()&&(*bv11_cells_cfd44c.at(x+1,y))->getProp()->name45c590()=="GAR_Door_Shootable";
    doors.push_back(vector<BV11Point>());
    doors.back().push_back(BV11Point(x,y));
    if(visible)
     for(int x2=x+1;(*bv11_cells_cfd44c.at(x2,y))->getProp().isValid()&&(*bv11_cells_cfd44c.at(x2,y))->getProp()->name45c590()=="GAR_Door_Shootable";x2++)
      doors.back().push_back(BV11Point(x2,y));
    else
     for(int y2=y+1;(*bv11_cells_cfd44c.at(x,y2))->getProp().isValid()&&(*bv11_cells_cfd44c.at(x,y2))->getProp()->name45c590()=="GAR_Door_Shootable";y2++)
      doors.back().push_back(BV11Point(x,y2));
    vector<BV11Point> cols;
    if(visible) {
     if(!(*bv11_cells_cfd44c.atPoint(BV11Point(doors.back().front(),-1,-1)))->field4550b0()&&!(*bv11_cells_cfd44c.atPoint(BV11Point(doors.back().back(),1,-1)))->field4550b0())
      for(unsigned i=0;i<doors.back().size();i++)
       cols.push_back(BV11Point(doors.back()[i],0,-1));
     else
      for(unsigned j=0;j<doors.back().size();j++)
       cols.push_back(BV11Point(doors.back()[j],0,1));
    }
    else {
     if(!(*bv11_cells_cfd44c.atPoint(BV11Point(doors.back().front(),-1,-1)))->field4550b0()&&!(*bv11_cells_cfd44c.atPoint(BV11Point(doors.back().back(),-1,1)))->field4550b0())
      for(unsigned i=0;i<doors.back().size();i++)
       cols.push_back(BV11Point(doors.back()[i],-1,0));
     else
      for(unsigned j=0;j<doors.back().size();j++)
       cols.push_back(BV11Point(doors.back()[j],1,0));
    }
    while(1) {
     type=tags.pick();
     switch(type) {
     case 0:
      goto placed;
     case 1:
      pick=0x10;
      num2=rng.rangeInt(2.0f,3.0f);
      goto spawn;
     case 2:
      pick=0x15;
      num2=rng.rangeInt(1.0f,2.0f);
      goto spawn;
     case 6:
      pick=0x18;
      num2=rng.rangeInt(1.0f,2.0f);
      goto spawn;
     case 7:
      pick=0x17;
      num2=rng.rangeInt(1.0f,2.0f);
      goto spawn;
     case 9:
      pick=0xf;
      num2=rng.rangeInt(2.0f,3.0f);
spawn:
      rec=unknown6c5600(1,pick,false,false);
      if(!rec)
       tags.remove(type);
      else {
       for(int i=0;i<num2&&!cols.empty();i++) {
        origin=bv11_popRandomPoint(cols);
        robot=placeEntity(rec,origin,3,false,1,0xe,false);
        if(robot.isValid())
         robot->unknown45b340(new BV11Trigger(room,1));
       }
       goto placed;
      }
      break;
     case 3:
      rec=unknown6c5600(1,0xd,false,false);
      if(!rec)
       tags.remove(type);
      else {
       while(!cols.empty()) {
        origin=bv11_popRandomPoint(cols);
        robot=placeEntity(rec,origin,3,false,1,0xe,false);
        if(robot.isValid())
         robot->unknown45b340(new BV11Trigger(room,1));
       }
       goto placed;
      }
      break;
     case 4:
      rec=unknown6c5600(1,6,false,false);
      if(!rec)
       tags.remove(type);
      else {
       for(int i=0;!cols.empty();i++) {
        origin=bv11_popRandomPoint(cols);
        robot=placeEntity(rec,origin,3,false,1,0xe,false);
        if(robot.isValid()) {
         if(i==0)
          robot->unknown45b340(new BV11Trigger(room,1));
         else
          robot->unknown5fd900(6,0);
        }
       }
       goto placed;
      }
      break;
     case 5:
      rec=unknown6c5600(1,0x11,false,false);
      start=unknown6c5600(1,0x12,false,false);
      if(!rec&&!start)
       tags.remove(type);
      else {
       vector<BV11Record*> recs;
       if(rec&&start)
        for(int k=0;k<2;k++)
         recs.push_back(rng.chance(50)?rec:start);
       else if(rec)
        recs.assign(2,rec);
       else
        recs.assign(2,start);
       for(unsigned m=0;m<recs.size()&&!cols.empty();m++) {
        origin=bv11_popRandomPoint(cols);
        robot=placeEntity(recs[m],origin,3,false,1,0xe,false);
        if(robot.isValid())
         robot->unknown45b340(new BV11Trigger(room,1));
       }
       goto placed;
      }
      break;
     case 8: {
      rec=unknown6c5600(1,0x16,false,false);
      start=unknown6c5600(1,0x13,false,false);
      if(!rec||!start||cols.size()<2) {
       tags.remove(type);
       break;
      }
      origin=bv11_popRandomPoint(cols);
      robot=placeEntity(rec,origin,3,false,1,0xe,false);
      if(robot.isValid())
       robot->unknown45b340(new BV11Trigger(room,1));
      origin=bv11_popRandomPoint(cols);
      BV11HE f=placeEntity(start,origin,3,false,1,0xe,false);
      if(f.isValid()&&robot.isValid())
       f->getAI()->setFollowEntity(robot,0);
      goto placed;
     }
     }
    }
placed:
    if(!visible)
     y+=doors.back().size();
   }
  }
 if(BV11_findByName(bv11_machines_cf35b0,"Garrison Terminal",door)) {
  int last=door->layers.front()->getWidth();
  int n=door->layers.front()->getHeight();
  BV11Rect min;
  BV11Rect res;
  int facing;
  for(int t=0;t<10;t++) {
   if(bv11_findWallStrip(last,n,4,&min,&res,&facing,0,false,false)) {
    bv11_fillRing(&res,&min,5,TERRAIN_CAVE_WALL,0);
    BV11Placed *m=placeMachine(door->id,BV11Point(res.x,res.y),bv11_dirTable_b96348[bv11_dirMap_bb8360[facing]],1,0);
    bv11_lists_d39f1c.push_back(new BV11Lists(bv11_entries_d31640.size()-1));
    if(m)
     m->unknown45bbe0(new BV11Tag(9,-1));
    break;
   }
  }
 }
 for(int i=0;i<bv11_entries_d31640.size();i++)
  if(!bv11_entries_d31640[i].empty()&&bv11_entries_d31640[i].front()->name45c590()=="GAR_RIF_Installer"&&bv11_entries_d31640[i].front()->unknown457b10()!=1)
   installers.push_back(i);
 for(int x=0;x<bv11_cells_cfd44c.getWidth();x++)
  for(int y=0;y<bv11_cells_cfd44c.getHeight();y++)
   if((*bv11_cells_cfd44c.at(x,y))->getItem().isValid()) {
    items.push_back((*bv11_cells_cfd44c.at(x,y))->getItem());
    itemPositions.push_back(BV11Point(x,y));
   }
 vector<BV11Point> wall;
 for(int x=0;x<bv11_cells_cfd44c.getWidth();x++)
  for(int y=0;y<bv11_cells_cfd44c.getHeight();y++) {
   if((*bv11_cells_cfd44c.at(x,y))->terrain()==TERRAIN_CAVE_WALL) {
    vector<BV11Point> around;
    sweepGetSurroundingCells(BV11Point(x,y),around);
    for(unsigned k=0;k<around.size();k++)
     if(!(*bv11_cells_cfd44c.atPoint(around[k]))->unknown66a630())
      goto next;
    wall.push_back(BV11Point(x,y));
   }
next:;
  }
 for(unsigned w=0;w<wall.size();w++)
  (*bv11_cells_cfd44c.atPoint(wall[w]))->unknown66a050(TERRAIN_EARTH->id,2,false);
}
