// NOTE: placeholder names and partial layouts; BS 0x6fdcb0: Wastes setup (salvage items, derelict
// encounter prefab, derelict squads and their triggers).
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;
struct BV9Entity;struct BV9AI;struct BV9Item;
struct BV9Point {int x,y;BV9Point();BV9Point(int);BV9Point(int,int);BV9Point(const BV9Point&);};
struct BV9PointA {int x,y;BV9PointA &operator=(const BV9Point&);};
struct BV9Area {int a,b,c,d;BV9Area(const BV9Point&);BV9Area &operator=(const BV9Area&);void set_40b360(const BV9PointA&,int,int);};
struct BV9Box {int a,b,c,d;BV9Box(int,int,int,int);void randomPoint(BV9Point*);};
struct BV9HE {int id;BV9HE();bool isValid() const;BV9Entity *operator->() const;};
struct BV9HI {int id;BV9Item *operator->() const;};
struct BV9Item {int getCached();void setCached(int);};
struct BV9Dialogue;struct BV9Trap;
struct BV9Trigger {BV9Trap *trap;int count;BV9Trigger(BV9Trap*,int);};
BV9Trigger::BV9Trigger(BV9Trap *trap_,int count_) {trap=trap_;count=count_;}
struct BV9Entity {BV9Point &getPosition();vector<BV9HI> *getInventoryList();void unknown6395d0(BV9Dialogue*,int);void unknown45b340(BV9Trigger*);void unknown631a20(BV9HE,int);void unknown637bb0();int unknown5ca260(int);void unknown5dea60(int);void unknown5fd900(int,int);};
struct BV9Cell {bool isPassableFor(BV9HE);bool field4550b0();BV9HE getEntity();void trigger45e110(int,int,BV9HE);void unknown45df90(BV9Trigger*);};
struct BV9Grid {BV9Cell **at(int,int);BV9Cell **atPoint(const BV9Point&);void getRandom_9cf0c0(BV9Point*);};extern BV9Grid bv9_cells_cfd44c;
struct BV9WL {BV9WL();BV9WL(const int*,int);~BV9WL();void add(int,int);int &pick();char pad[0x24];};
extern const int bv9_levelWeights_b93674[];
struct BV9LocInfo {int depth46ed20();};
struct BV9HLoc {int id;BV9LocInfo *operator->() const;};extern BV9HLoc bv9_location_d1e888;
extern int bv9_level_d1eae0,bv9_danger_d1eae4;extern BV9Area bv9_area_d1eae8;
struct BV9Range {int a,b;int randomInRange_40c130();};extern BV9Range bv9_range_d22310,bv9_range_d21e40;
struct BV9ItemType;
struct BV9WLI {BV9ItemType *&pick();};extern BV9WLI bv9_items_d31700;
void opV3b_unknown6fdab0(BV9ItemType*);
extern bool bv9_flag_d1e880,bv9_flag_d257eb;
struct BV9Record;
extern vector<BV9Dialogue*> bv9_dialogues_d2c408;extern vector<BV9Trap*> bv9_traps_d2f0f8;
template<class T> bool BV9_findByName(vector<T*>&,const string&,T*&);
BV9HE bv9_spawnRandom_6fd950(BV9Record*,int,bool);
struct BV9GameData {void setEntryText(const string&,const string&);};extern BV9GameData bv9_gameData_d1e860;
template<class T> void BV9_eraseStep(vector<T>&,int&);
BV9Point bv9_randomPoint(vector<BV9Point>&);
int bv9_randomRec(vector<int>&);
struct BV9Place {BV9PointA pos;int rotation;bool flag;};
struct BV9Prefab {char pad[0x20];int type;char pad24[0xb8-0x24];bool flip;char padb9[3];float chance;bool fill;char padc1[3];vector<int> images;};
extern vector<BV9Prefab*> bv9_prefabs_d21afc;
struct BV9Layer {int getWidth();int getHeight();};
struct BV9Image {vector<BV9Layer*> layers;char pad[0x50-0x10];BV9Image();~BV9Image();BV9Image &operator=(const BV9Image&);void flipHorizontal(int);void rotate(int);};
extern vector<BV9Image*> bv9_images_d161c4;
extern int bv9_turns_bb8370[];
void bv9_logPhrase_5141b0(int,int,int,int,BV9HE,int);
extern const char bv9_empty_b958be[];
struct BV9World {void unknown6c6b90(const BV9Point&,const string&,BV9Dialogue*,int);};extern BV9World *bv9_world_cefc4c;
struct BS {
 BV9ItemType *selectRandomItemOfRating(int,int,int,int,int,int,int);
 BV9Record *unknown6c5600(int,int,bool,bool);
 BV9HE placeEntity(BV9Record*,const BV9Point&,int,bool,int,int,bool);
 bool unknown6c65a0(BV9HE,const string&,bool);
 void unknown6cd110(BV9Image&,int,bool,float);
 bool findPlaceableNear(const BV9Point&,BV9Point&,int);
 void wastes_6fdcb0();
 char pad[0x66c];BV9HE player;
};
void BS::wastes_6fdcb0() {
 BV9WL traps(bv9_levelWeights_b93674,5);
 int chosen=traps.pick();
 bv9_level_d1eae0=chosen;
 int old=bv9_location_d1e888->depth46ed20();
 BV9WL tags;
 BV9Dialogue *title;
 BV9Record *rec;
 if(old<10)
  tags.add(old,10);
 if(old+1<10)
  tags.add(old+1,20);
 if(old+2<10)
  tags.add(old+2,50);
 if(old+3<10)
  tags.add(old+3,20);
 for(int n=bv9_range_d22310.randomInRange_40c130();n>0;n--) {
  BV9ItemType *type=selectRandomItemOfRating(tags.pick(),1,0,0x1f,0x12,0x2a,0);
  if(type)
   opV3b_unknown6fdab0(type);
 }
 if(rng.chance(10))
  for(int m=bv9_range_d21e40.randomInRange_40c130();m>0;m--)
   opV3b_unknown6fdab0(bv9_items_d31700.pick());
 if(bv9_flag_d1e880&&(!bv9_flag_d257eb||chosen<=2&&rng.chance(20))) {
  bv9_flag_d257eb=true;
  rec=unknown6c5600(3,0x10,false,true);
  if(rec) {
   BV9Point p(player->getPosition());
   while((*bv9_cells_cfd44c.at(p.x,p.y+1))->isPassableFor(BV9HE()))
    p.y++;
   BV9HE first=placeEntity(rec,p,9,true,0x22,0xe,false);
   if(first.isValid()) {
    BV9_findByName(bv9_dialogues_d2c408,"WAS_Derelict_Warning",title);
    if(title)
     first->unknown6395d0(title,0);
    BV9Trap *s;
    BV9_findByName(bv9_traps_d2f0f8,"ENC_WAS_DERELICT",s);
    if(s)
     first->unknown45b340(new BV9Trigger(s,1));
   }
  }
 }
 rec=unknown6c5600(1,0x1d,false,true);
 vector<BV9HE> elements;
 for(int i=0;i<6;i++)
  elements.push_back(bv9_spawnRandom_6fd950(rec,5,false));
 bv9_danger_d1eae4=chosen>1?0:15;
 bv9_area_d1eae8=BV9Point(-1);
 bv9_gameData_d1e860.setEntryText("wasUnreadyDerelictsAttacked_g","0");
 if(chosen==0)
  return;
 vector<BV9Point> cols;
 cols.push_back(BV9Point(0x1a,0x18));
 cols.push_back(BV9Point(0x26,0x18));
 cols.push_back(BV9Point(0x32,0x18));
 cols.push_back(BV9Point(0x3e,0x18));
 cols.push_back(BV9Point(0x1a,0x40));
 cols.push_back(BV9Point(0x26,0x40));
 cols.push_back(BV9Point(0x32,0x40));
 cols.push_back(BV9Point(0x3e,0x40));
 for(int j=0;j<cols.size();j++)
  if(!(*bv9_cells_cfd44c.atPoint(cols[j]))->field4550b0())
   BV9_eraseStep(cols,j);
 if(cols.empty())
  return;
 BV9Point hidden=bv9_randomPoint(cols);
 BV9Prefab *elem=bv9_prefabs_d21afc[(chosen>=3)+0x5a];
 BV9Image base;
 base=*bv9_images_d161c4[bv9_randomRec(elem->images)];
 if(elem->flip&&rng.chance(50))
  base.flipHorizontal(1);
 BV9Place mode;
 mode.rotation=2;
 if(hidden.y==0x40) {
  mode.rotation=0;
  for(int r=0;r<bv9_turns_bb8370[mode.rotation];r++)
   base.rotate(1);
 }
 mode.flag=false;
 mode.pos=hidden;
 mode.pos.x+=rng.rangeInt(-2.0f,2.0f);
 if(hidden.y==0x18)
  mode.pos.y-=base.layers.front()->getHeight()+1;
 else
  mode.pos.y+=9;
 unknown6cd110(base,elem->type,elem->fill,elem->chance);
 if(chosen==1)
  bv9_area_d1eae8.set_40b360(mode.pos,base.layers.front()->getWidth(),base.layers.front()->getHeight());
 if(chosen>=3) {
  for(unsigned i=0;i<elements.size();i++) {
   if(elements[i].operator->()) {
    vector<BV9HI> *list=elements[i]->getInventoryList();
    for(unsigned k=0;k<list->size();k++)
     (*list)[k]->setCached((*list)[k]->getCached()*rng.rangeInt(25.0f,90.0f)/100);
    if(rng.chance(75)) {
     elements[i]->unknown631a20(BV9HE(),0);
     elements[i]->unknown637bb0();
    }
    else {
     elements[i]->unknown5dea60(elements[i]->unknown5ca260(0)*rng.rangeInt(40.0f,60.0f)/100);
     elements[i]->unknown5fd900(8,0);
     unknown6c65a0(elements[i],"WAS_Compactor_Restart",false);
    }
   }
  }
  BV9Point where;
  rec=unknown6c5600(3,0x10,true,true);
  if(rec) {
   for(int it=0,count=0;it<50&&count<5;it++) {
    bv9_cells_cfd44c.getRandom_9cf0c0(&where);
    if(findPlaceableNear(where,where,1)) {
     BV9HE d=placeEntity(rec,where,9,true,0,0xe,false);
     if(d.isValid()) {
      d->unknown5dea60(d->unknown5ca260(0)*rng.rangeInt(10.0f,40.0f)/100);
      d->unknown5fd900(8,0);
      vector<BV9HI> *items=d->getInventoryList();
      for(unsigned k=0;k<items->size();k++)
       (*items)[k]->setCached((*items)[k]->getCached()*rng.rangeInt(25.0f,90.0f)/100);
     }
     count++;
    }
   }
  }
  if(chosen==3) {
   BV9WL edges;
   edges.add(0x10,0x2d);
   edges.add(0xd,0x19);
   edges.add(0x11,5);
   edges.add(0x12,5);
   edges.add(8,0xa);
   edges.add(0x16,0xa);
   BV9Trap *score;
   BV9_findByName(bv9_traps_d2f0f8,"ENC_WAS_DERELICTS",score);
   BV9Point line(player->getPosition());
   BV9Box vec(line.x-4,line.y-4,line.x+4,line.y+4);
   bool changed=false;
   for(int t=0;t<20;t++) {
    for(int u=0;u<30;u++) {
     vec.randomPoint(&where);
     if(findPlaceableNear(where,where,1))
      goto placed;
    }
    continue;
placed:
    rec=unknown6c5600(3,edges.pick(),true,true);
    if(rec) {
     BV9HE w=placeEntity(rec,where,9,true,1,0xe,false);
     if(w.isValid()) {
      if(score)
       w->unknown45b340(new BV9Trigger(score,1));
      if(!changed) {
       unknown6c65a0(w,"WAS_Derelicts_Victory",false);
       changed=true;
      }
     }
    }
   }
  }
  else
   do {bv9_logPhrase_5141b0(0x188,0,0,0,BV9HE(),0);} while(0);
  BV9Point q(hidden);
  if(hidden.y==0x18)
   q.y-=1;
  else
   q.y+=8;
  for(int x=q.x,y=q.y;x<q.x+8;x++)
   if((*bv9_cells_cfd44c.at(x,y-1))->field4550b0()&&(*bv9_cells_cfd44c.at(x,y+1))->field4550b0())
    (*bv9_cells_cfd44c.at(x,y))->trigger45e110(0,1,BV9HE());
 }
 else {
  BV9Point o(hidden);
  if(hidden.y==0x18)
   o.y-=2;
  else
   o.y+=9;
  BV9_findByName(bv9_dialogues_d2c408,chosen==1?"WAS_Derelicts_Unready":"WAS_Derelicts_Ready",title);
  if(title) {
   for(int x=o.x,n=0;x<o.x+8;x++) {
    if((*bv9_cells_cfd44c.at(x,o.y))->getEntity().isValid()) {
     if(n==1) {
      (*bv9_cells_cfd44c.at(x,o.y))->getEntity()->unknown6395d0(title,0);
      break;
     }
     else
      n++;
    }
   }
  }
  if(chosen==2) {
   BV9Dialogue *trig2;
   BV9_findByName(bv9_dialogues_d2c408,"WAS_Derelicts_Trigger",trig2);
   if(trig2) {
    BV9Point a(hidden);
    a.x+=4;
    if(hidden.y!=0x18)
     a.y+=7;
    bv9_world_cefc4c->unknown6c6b90(a,bv9_empty_b958be,trig2,-1);
    BV9Point b(hidden);
    if(hidden.y==0x18)
     b.y-=1;
    else
     b.y+=8;
    BV9Trap *wall;
    BV9_findByName(bv9_traps_d2f0f8,"ENC_WAS_DERELICTS_WALL",wall);
    if(wall) {
     for(int x=b.x,y=b.y;x<b.x+8;x++)
      if((*bv9_cells_cfd44c.at(x,y-1))->field4550b0()&&(*bv9_cells_cfd44c.at(x,y+1))->field4550b0())
       (*bv9_cells_cfd44c.at(x,y))->unknown45df90(new BV9Trigger(wall,1));
    }
   }
  }
 }
}
