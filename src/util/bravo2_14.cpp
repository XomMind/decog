// NOTE: placeholder names and partial layouts; BS 0x6e68d0: DSF scenario setup (item caches, sapper squad,
// warlord force, sterilized derelict garrison, wild derelicts, twisting tunnel).
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;
struct BV15Entity;struct BV15AI;struct BV15Item;struct BV15Prop;struct BV15Terrain {int id;};
struct BV15Point {int x,y;BV15Point();BV15Point(int,int);BV15Point(const BV15Point&);BV15Point &operator=(const BV15Point&);};
struct BV15Area {BV15Point p1,p2;BV15Area();BV15Area(const BV15Point&,int,int);BV15Area &operator=(const BV15Area&);};
struct BV15HE {int id;BV15HE();bool isValid() const;BV15Entity *operator->() const;};
struct BV15HI {int id;bool isValid() const;bool isNull() const;BV15Item *operator->() const;};
struct BV15HP {int id;bool isValid() const;BV15Prop *operator->() const;};
struct BV15Trap;
struct BV15Trigger {BV15Trap *trap;int count;BV15Trigger(BV15Trap*,int);};
BV15Trigger::BV15Trigger(BV15Trap *trap_,int count_) {trap=trap_;count=count_;}
struct BV15Exit;
struct BV15Entity {int getTarget();void unknown637bb0();BV15AI *getAI();void unknown45b070(const string&);BV15Point &getPosition();void unknown45b340(BV15Trigger*);int unknown45a810();void unknown631a20(BV15HE,int);};
struct BV15AI {void unknown459540(BV15Exit*);};
struct BV15Item {int getNestedField();void remove57dbe0(int,int,bool,bool);int unknown457c80();void setCached(int);void unknown57a190(BV15HE,int,int,int);};
struct BV15Prop {int id44ab40();void unknown45ce10(int,int,int,BV15HE);int nested45c630();bool isTrap();void unknown45cc50(const BV15Point&);};
struct BV15Cell {BV15HI getItem();BV15HP getProp();bool field4550b0();int terrain45d0e0();bool isPassableFor(BV15HE);void trigger45e110(int,int,BV15HE);bool isMachinePart();bool canPlaceEntity(int);bool place45df50(BV15HP);};
struct BV15Grid {BV15Cell **at(int,int);BV15Cell **atPoint(const BV15Point&);int getWidth();int getHeight();void getRandom_9cf0c0(BV15Point*);};extern BV15Grid bv15_cells_cfd44c;
extern BV15Terrain *TERRAIN_EARTH,*TERRAIN_CAVE_WALL;
struct BV15GameData {int unknown46f4e0();void setEntryText(const string&,const string&);};extern BV15GameData bv15_gameData_d1e860;
extern vector<int> bv15_scenario_d1eb9c;
struct BV15Range {int a,b;int randomInRange_40c130();};extern BV15Range bv15_range_d2ec2c;
BV15Area bv15_popRandomArea(vector<BV15Area>&);
extern vector<vector<int> > bv15_caches_cf6570;extern vector<vector<BV15Point> > bv15_cachePos_cf6580;
struct BV15Machine {vector<BV15HE> &members416f40();};
struct BV15HM {int id;BV15Machine *operator->() const;};
struct BV15ItemType {char pad[0x1a0];struct BV15Blast *blast;};
struct BV15BlastDef {char pad[0x30];int radius;};
struct BV15Record {char pad[0x9c];int size;};
extern vector<BV15ItemType*> bv15_itemTypes_d2d1c4;extern vector<BV15Trap*> bv15_traps_d2f0f8;
template<class T> bool BV15_findByName(vector<T*>&,const string&,T*&);
void bv15_logPhrase_5141b0(int,const string*,const string*,const string*,BV15HE,const BV15Point*);
template <class T>
class OpR5h_WL	// NOTE: partial declaration of the weighted list from src/op/op_r5h_wl.cpp
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	void add(T value, int weight);	// 0x9ba310
	T &pick();	// 0x9ba470
};
int bv15_distance_40a3f0(const BV15Point&,const BV15Point&);
void getAdjacentCells(const BV15Point&,vector<BV15Point>&);
void sweepGetSurroundingCells(const BV15Point&,vector<BV15Point>&);
template<class T> void BV15_shuffle(vector<T>&);
struct BV15Field {int left();int getRight();int top();int getBottom();int &operator()(int,int);};
struct BV15Blast {BV15Blast(BV15BlastDef*,int,const BV15Point&,const BV15Point&,const BV15Point&);~BV15Blast();void unknown514ee0();char pad[0x20];BV15Field field;char pad24[0x50-0x24];};
int bv15_randomRec(vector<int>&);
extern int bv15_tracker_cf6560;extern bool bv15_flag_cf6470;
template<class T> void BV15_eraseStep(vector<T>&,int&);
BV15Point bv15_randomPoint(vector<BV15Point>&);
extern BV15Point bv15_tunnel_d1ebb0;
struct BV15World {bool findPropSpotNear(const BV15Point&,BV15Point&,int);};extern BV15World *bv15_world_cefc4c;
struct BV15MachineDef;extern vector<BV15MachineDef*> bv15_machines_cf35b0;
struct BV15Factory {BV15HP createE(BV15MachineDef*);};extern BV15Factory *bv15_factory_cefaa8;
string intToString(int);
struct BS {
 BV15HE unknown6c5dc0(const string&,const BV15Point&,int,bool,int,int,bool);
 bool unknown6c65a0(BV15HE,const string&,bool);
 BV15HI unknown6c5400(BV15ItemType*,const BV15Point&);
 bool findPlaceableNear(const BV15Point&,BV15Point&,int);
 BV15Record *unknown6c5600(int,int,bool,bool);
 BV15HE placeEntity(BV15Record*,const BV15Point&,int,bool,int,int,bool);
 bool unknown6c6b90(const BV15Point&,const string&,void*,int);
 void unknown6c6700(BV15HP,const string&,int);
 void dsf_6e68d0();
 char pad[8];BV15Point center;vector<BV15Exit*> exits;char pad20[0x4c-0x20];vector<BV15HM> machines;char pad5c[0x66c-0x5c];BV15HE player;
};
#define B(a,b,c,d) spots.push_back(BV15Area(BV15Point(a,b),c,d));
void BS::dsf_6e68d0() {
 switch(bv15_scenario_d1eb9c[bv15_gameData_d1e860.unknown46f4e0()]) {
 case 0:
scenario0: {
  int n=bv15_range_d2ec2c.randomInRange_40c130();
  if(n) {
   vector<BV15Area> spots;
   B(14,8,2,1) B(17,8,3,1) B(21,7,2,2) B(23,7,3,2) B(26,7,2,2) B(29,8,3,1) B(33,8,2,1) B(14,11,2,2) B(17,11,3,2) B(29,11,3,2) B(33,11,2,2) B(21,13,2,3) B(26,13,2,3) B(8,14,1,2) B(11,14,2,2) B(36,14,2,2) B(40,14,1,2) B(8,17,1,3) B(11,17,2,3) B(21,17,2,3) B(26,17,2,3) B(36,17,2,3) B(40,17,1,3) B(7,21,2,2) B(13,21,3,2) B(17,21,3,2) B(29,21,3,2) B(33,21,3,2) B(40,21,2,2) B(7,26,2,2) B(13,26,3,2) B(17,26,3,2) B(29,26,3,2) B(33,26,3,2) B(40,26,2,2) B(8,29,1,3) B(11,29,2,3) B(21,29,2,3) B(26,29,2,3) B(36,29,2,3) B(40,29,1,3) B(8,33,1,2) B(11,33,2,2) B(21,33,2,3) B(26,33,2,3) B(36,33,2,2) B(40,33,1,2) B(14,36,2,2) B(17,36,3,2) B(29,36,3,2) B(33,36,2,2) B(14,40,2,1) B(17,40,3,1) B(21,40,2,2) B(23,40,3,2) B(26,40,2,2) B(29,40,3,1) B(33,40,2,1)
   while(n) {
    BV15Area a;
    do
     a=bv15_popRandomArea(spots);
    while((*bv15_cells_cfd44c.atPoint(a.p1))->getItem().isNull()&&!spots.empty());
    if((*bv15_cells_cfd44c.atPoint(a.p1))->getItem().isNull())
     break;
    bv15_caches_cf6570.push_back(vector<int>());
    bv15_cachePos_cf6580.push_back(vector<BV15Point>());
    for(int x=a.p1.x;x<=a.p2.x;x++)
     for(int y=a.p1.y;y<=a.p2.y;y++)
      if((*bv15_cells_cfd44c.at(x,y))->getItem().isValid()) {
       bv15_caches_cf6570.back().push_back((*bv15_cells_cfd44c.at(x,y))->getItem()->getNestedField());
       bv15_cachePos_cf6580.back().push_back(BV15Point(x,y));
       (*bv15_cells_cfd44c.at(x,y))->getItem()->remove57dbe0(0,0,true,true);
      }
    if(bv15_caches_cf6570.back().empty()) {
     bv15_caches_cf6570.pop_back();
     bv15_cachePos_cf6580.pop_back();
    }
    n--;
   }
  }
  break;
 }
 case 1:
  if(((*bv15_cells_cfd44c.at(10,10))->field4550b0()&&(*bv15_cells_cfd44c.at(38,38))->field4550b0()&&!(*bv15_cells_cfd44c.at(38,10))->field4550b0()&&!(*bv15_cells_cfd44c.at(10,38))->field4550b0())||(!(*bv15_cells_cfd44c.at(10,10))->field4550b0()&&!(*bv15_cells_cfd44c.at(38,38))->field4550b0()&&(*bv15_cells_cfd44c.at(38,10))->field4550b0()&&(*bv15_cells_cfd44c.at(10,38))->field4550b0())) {
   vector<BV15HE> &line=machines[3]->members416f40();
   for(unsigned i=0;i<line.size();i++)
    if(line[i]->getTarget()==2) {
     line[i]->unknown637bb0();
     i--;
    }
   BV15HE first=unknown6c5dc0("Sapper",center,9,true,0x19,0,false);
   if(first.isValid()) {
    first->getAI()->unknown459540(exits.front());
    first->unknown45b070(string("K3-BOM"));
    unknown6c65a0(first,"DSF_Sapper_Talk1",false);
    BV15HE a=unknown6c5dc0("Sapper",first->getPosition(),9,true,0x19,0,false);
    if(a.isValid()) {
     a->getAI()->unknown459540(exits.front());
     a->unknown45b070(string("H8-EMC"));
    }
    BV15ItemType *base;
    if(BV15_findByName(bv15_itemTypes_d2d1c4,"Sapper Charge",base))
     for(int k=rng.rangeInt(3.0f,6.0f);k>0;k--)
      unknown6c5400(base,center);
    do {int unused; bv15_logPhrase_5141b0(0x116,0,0,0,BV15HE(),0);} while(0);
   }
   break;
  }
  else {
   bv15_scenario_d1eb9c[bv15_gameData_d1e860.unknown46f4e0()]=0;
   goto scenario0;
  }
  break;
 case 2: {
  OpR5h_WL<int> ranks;
  ranks.add(0x10,0x50);
  ranks.add(0x11,0xa);
  ranks.add(0x12,0xa);
  BV15Point vec(player->getPosition());
  BV15Point y0;
  BV15Record *mode;
  bool updated=false;
  BV15Trap *it=0;
  BV15_findByName(bv15_traps_d2f0f8,"DSF_Warlord_Ready",it);
  for(int i=0;i<12;i++) {
   if(findPlaceableNear(vec,y0,1)) {
    mode=unknown6c5600(3,ranks.pick(),true,true);
    if(mode) {
     BV15HE w=placeEntity(mode,y0,9,true,0x18,0xe,false);
     if(w.isValid()) {
      if(!updated) {
       unknown6c65a0(w,"DSF_Warlord_Ready",false);
       updated=true;
      }
      if(it)
       w->unknown45b340(new BV15Trigger(it,1));
     }
    }
   }
  }
  vector<BV15HE> &type=machines[3]->members416f40();
  for(unsigned j=0;j<type.size();j++)
   if(type[j]->getTarget()==2&&bv15_distance_40a3f0(type[j]->getPosition(),center)<7) {
    type[j]->unknown637bb0();
    j--;
   }
  break;
 }
 case 3: {
  vector<BV15HE> &rows=machines[3]->members416f40();
  while(rows.size())
   rows.front()->unknown637bb0();
  vector<BV15Point> cols;
  for(int x=0;x<bv15_cells_cfd44c.getWidth();x++)
   for(int y=0;y<bv15_cells_cfd44c.getHeight();y++) {
    if((*bv15_cells_cfd44c.at(x,y))->terrain45d0e0()==TERRAIN_CAVE_WALL->id) {
     if(rng.chance(10)) {
      cols.clear();
      getAdjacentCells(BV15Point(x,y),cols);
      for(unsigned k=0;k<cols.size();k++) {
       if((*bv15_cells_cfd44c.atPoint(cols[k]))->isPassableFor(BV15HE())) {
        (*bv15_cells_cfd44c.at(x,y))->trigger45e110(0,1,BV15HE());
        if(rng.chance(10)) {
         cols.clear();
         sweepGetSurroundingCells(BV15Point(x,y),cols);
         BV15_shuffle(cols);
         for(unsigned m=0;m<cols.size();m++)
          if((*bv15_cells_cfd44c.atPoint(cols[m]))->terrain45d0e0()==TERRAIN_EARTH->id) {
           (*bv15_cells_cfd44c.atPoint(cols[m]))->trigger45e110(0,1,BV15HE());
           break;
          }
        }
        break;
       }
      }
     }
    }
    else if((*bv15_cells_cfd44c.at(x,y))->getProp().isValid()&&(*bv15_cells_cfd44c.at(x,y))->getProp()->id44ab40()!=-1&&rng.chance(15)) {
     cols.clear();
     getAdjacentCells(BV15Point(x,y),cols);
     for(unsigned n=0;n<cols.size();n++)
      if((*bv15_cells_cfd44c.atPoint(cols[n]))->isPassableFor(BV15HE())) {
       (*bv15_cells_cfd44c.at(x,y))->getProp()->unknown45ce10(1,0,1,BV15HE());
       break;
      }
    }
   }
  if(rng.chance(50)) {
   BV15ItemType *sterilizer;
   if(BV15_findByName(bv15_itemTypes_d2d1c4,"Sapper Charge",sterilizer)) {
    for(int b=2;b>0;b--) {
     if(b==1&&rng.chance(50))
      break;
     BV15Point p;
     do
      bv15_cells_cfd44c.getRandom_9cf0c0(&p);
     while((*bv15_cells_cfd44c.atPoint(p))->terrain45d0e0()==TERRAIN_EARTH->id);
     BV15Blast blast((BV15BlastDef*)sterilizer->blast,((BV15BlastDef*)sterilizer->blast)->radius,p,p,p);
     blast.unknown514ee0();
     BV15Field *f=&blast.field;
     for(int x=f->left();x<=f->getRight();x++)
      for(int y=f->top();y<=f->getBottom();y++)
       if((*f)(x,y)!=0) {
        if((*bv15_cells_cfd44c.at(x,y))->getProp().isValid()&&(*f)(x,y)>=(*bv15_cells_cfd44c.at(x,y))->getProp()->nested45c630()&&!(*bv15_cells_cfd44c.at(x,y))->getProp()->isTrap())
         (*bv15_cells_cfd44c.at(x,y))->getProp()->unknown45ce10(1,0,1,BV15HE());
        if((*bv15_cells_cfd44c.at(x,y))->getItem().isValid()) {
         if(rng.chance(50))
          (*bv15_cells_cfd44c.at(x,y))->getItem()->remove57dbe0(0,0,true,true);
         else
          (*bv15_cells_cfd44c.at(x,y))->getItem()->setCached(rng.rangeInt(1.0f,(float)(*bv15_cells_cfd44c.at(x,y))->getItem()->unknown457c80()));
        }
        if(!(*bv15_cells_cfd44c.at(x,y))->isMachinePart())
         (*bv15_cells_cfd44c.at(x,y))->trigger45e110(0,1,BV15HE());
       }
    }
   }
  }
  OpR5h_WL<int> slots;
  slots.add(0x10,0x2d);
  slots.add(0x11,0xa);
  slots.add(0x12,0xa);
  slots.add(0xd,0xa);
  slots.add(0x18,0x14);
  slots.add(0x19,5);
  vector<int> tags;
  tags.push_back(0x10);
  tags.push_back(0x1c);
  tags.push_back(0x40);
  tags.push_back(0x41);
  tags.push_back(0x42);
  tags.push_back(0x43);
  BV15Point pt;
  BV15HE v;
  const int n=0x19;
  const int num=3;
  BV15Record *dest;
  for(int i=0;i<28;i++) {
   dest=unknown6c5600(3,i!=0?slots.pick():bv15_randomRec(tags),false,true);
   if(dest) {
    for(int t=0;t<200;t++) {
     bv15_cells_cfd44c.getRandom_9cf0c0(&pt);
     if((*bv15_cells_cfd44c.atPoint(pt))->canPlaceEntity(dest->size))
      break;
    }
    if((*bv15_cells_cfd44c.atPoint(pt))->canPlaceEntity(dest->size)) {
     v=placeEntity(dest,pt,9,true,0x22,0xe,false);
     if(v.isValid()) {
      if(i<n) {
       int count=v->unknown45a810();
       if(count>0) {
        BV15Point ip;
        for(int u=0;u<100;u++) {
         bv15_cells_cfd44c.getRandom_9cf0c0(&ip);
         if((*bv15_cells_cfd44c.atPoint(ip))->getItem().isValid()) {
          (*bv15_cells_cfd44c.atPoint(ip))->getItem()->unknown57a190(v,4,0,0);
          break;
         }
        }
       }
      }
      else {
       v->unknown631a20(BV15HE(),0);
       v->unknown637bb0();
      }
     }
    }
   }
  }
  OpR5h_WL<int> weight;
  weight.add(0x10,0x2d);
  weight.add(0x11,0xa);
  weight.add(0x12,0xa);
  weight.add(0xd,0xa);
  weight.add(0x18,0x14);
  weight.add(0x19,5);
  vector<int> edges;
  edges.push_back(0x1c);
  edges.push_back(0x1e);
  edges.push_back(0x1f);
  const int h2=0x14;
  const int xx=3;
  for(int i2=0;i2<23;i2++) {
   int type=i2!=0?weight.pick():bv15_randomRec(edges);
   dest=unknown6c5600(type==0x1e||type==0x1f?2:1,type,false,true);
   if(dest) {
    for(int t2=0;t2<200;t2++) {
     bv15_cells_cfd44c.getRandom_9cf0c0(&pt);
     if((*bv15_cells_cfd44c.atPoint(pt))->canPlaceEntity(dest->size)&&bv15_distance_40a3f0(pt,center)>13)
      break;
    }
    if((*bv15_cells_cfd44c.atPoint(pt))->canPlaceEntity(dest->size)) {
     v=placeEntity(dest,pt,3,true,0x22,0xe,false);
     if(i2>=n) {
      v->unknown631a20(BV15HE(),0);
      v->unknown637bb0();
     }
    }
   }
  }
  bv15_tracker_cf6560=-1;
  bv15_flag_cf6470=true;
  if(!unknown6c6b90(BV15Point(0,0),"DSF_W_Active_Sterilize",0,-1)) {}
  do {bv15_logPhrase_5141b0(0x115,0,0,0,BV15HE(),0);} while(0);
  break;
 }
 case 4:
  if(!unknown6c6b90(BV15Point(0,0),"DSF_Wild_Derelicts",0,-1)) {}
  bv15_flag_cf6470=true;
  break;
 case 5: {
  vector<BV15Point> corners;
  corners.push_back(BV15Point(0x10,0x10));
  corners.push_back(BV15Point(0x1f,0x10));
  corners.push_back(BV15Point(0x10,0x1f));
  corners.push_back(BV15Point(0x1f,0x1f));
  for(int i=0;i<corners.size();i++)
   if(!(*bv15_cells_cfd44c.atPoint(corners[i]))->isPassableFor(BV15HE()))
    BV15_eraseStep(corners,i);
  if(corners.empty()) {
   bv15_scenario_d1eb9c[bv15_gameData_d1e860.unknown46f4e0()]=0;
   goto scenario0;
  }
  else {
   BV15Point p(bv15_tunnel_d1ebb0=bv15_randomPoint(corners));
   if(bv15_world_cefc4c->findPropSpotNear(p,p,0)) {
    BV15MachineDef *m;
    if(BV15_findByName(bv15_machines_cf35b0,"Twisting Tunnel",m)&&(*bv15_cells_cfd44c.atPoint(p))->place45df50(bv15_factory_cefaa8->createE(m))) {
     (*bv15_cells_cfd44c.atPoint(p))->getProp()->unknown45cc50(p);
     unknown6c6700((*bv15_cells_cfd44c.atPoint(p))->getProp(),"DSF_Assembled",0);
    }
   }
  }
  break;
 }
 }
 bv15_gameData_d1e860.setEntryText("dsfScenario_g",intToString(bv15_scenario_d1eb9c[bv15_gameData_d1e860.unknown46f4e0()]));
}
