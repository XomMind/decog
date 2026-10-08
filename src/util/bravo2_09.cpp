// NOTE: placeholder names and partial layouts; Zionmind::newTurn (0x6bf880): completes a pending dispatch at
// the Zion bay, rerolls the dispatch spawn list, and spawns the cave rescue hero.
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;
struct BV10Entity;struct BV10AI;struct BV10Item;struct BV10Prop;
struct BV10Point {int x,y;BV10Point(const BV10Point&);};
struct BV10HE {int id;BV10HE();bool isValid() const;BV10Entity *operator->() const;};
struct BV10HI {int id;BV10HI();bool isValid() const;BV10Item *operator->() const;};
struct BV10HP {int id;BV10HP();bool isValid() const;BV10Prop *operator->() const;BV10Prop *get() const;void reset();};
struct BV10Entity {const string &name416f40();vector<BV10Point> *unknown45d1a0();void removeEffectsA(int);BV10AI *getAI();void unknown6396a0(const string&,int);bool unknown5c98c0(int,int,int);};
struct BV10AI {void setFollowEntity(BV10HE,int);};
struct BV10Item {bool unknown457ff0();int unknown457fb0();void setCached44fc60(int);bool getField415ee0();void unknown458390(int);const BV10Point &unknown575920();};
struct BV10Prop {int unknown457b10();int id44ab40();void unknown45ce10(int,int,int,BV10HE);const BV10Point &position4184d0();};
struct BV10Cell {BV10HP getProp();};
struct BV10Grid {BV10Cell **atPoint(const BV10Point&);};extern BV10Grid bv10_cells_cfd44c;
void sweepGetSurroundingCells(const BV10Point&,vector<BV10Point>&);
struct BV10LocInfo {int pad0;int type;char pad8[0x24-8];bool caves;int depth46ed20();};
struct BV10HLoc {int id;BV10LocInfo *operator->() const;};extern BV10HLoc bv10_location_d1e888;
extern int bv10_maxSpawns_bbb5bc[];extern bool bv10_zionFlags_b90458[];extern int bv10_none_caf160;
extern string bv10_typeNames_d29af8[];extern string bv10_dialogNames_cf09b8[];extern int bv10_chances_bbb5e8[];extern int bv10_itemCounts_bbba30[];
extern vector<int> bv10_counters_d1e920;extern const float bv10_c_ba32f4,bv10_c_ba3664;extern int bv10_weight_ba3ad0;
struct BV10ItemType {char pad[0x50];int minDepth;char pad54[4];int category;char pad5c[4];int weight;char pad64[0x210-0x64];vector<int> dispatchTypes;};
extern vector<BV10ItemType*> bv10_itemTypes_d2d1c4;
struct BV10Record;extern vector<BV10Record*> bv10_records_d25de0;
template<class T> bool BV10_findByName(vector<T*>&,const string&,T*&);
bool bv10_containsRecord(vector<int>&,int);
struct BV10Effect;bool bv10_lookup2(const string&,BV10Effect*&);
struct BV10Fx {void init_503b20();};
struct BV10ObjB {BV10Fx *unknown508610(BV10ObjB*,BV10Effect*,const BV10Point&,void*,int,int,int,int,int);};extern BV10ObjB *bv10_objB_cefc50;extern int bv10_d2e20c;
void logError(string location,string message);
void bv10_sound_4541b0(int,int,int);
void bv10_logPhrase_5141b0(int,const string*,const string*,const string*,BV10HE,const BV10Point*);
void bv10_message_49c610(int,BV10HE,const string&,int);
struct BV10Stats {vector<int> *values;bool add4729d0(unsigned,int,string,int);};extern BV10Stats bv10_stats_d2c658;extern const char bv10_empty_b958ab[],bv10_empty_b958b2[];
struct BV10PlayerData {void unknown77fbc0(int);};extern BV10PlayerData bv10_playerData_cf45d8;
struct BV10World {bool unknown6c65a0(BV10HE,const string&,bool);BV10HI giveItem(const string&,BV10HE,int,int);BV10HI unknown6c51d0(BV10ItemType*,BV10HE,bool,bool);int unknown4642d0();BV10HE getPlayer();const BV10Point &position4184d0();BV10HE placeEntity(BV10Record*,const BV10Point&,int,bool,int,int,bool);};
extern BV10World *bv10_world_cefc4c;
struct BV10GameData {const string &getEntryText(const string&);int unknown46f4e0();};extern BV10GameData bv10_gameData_d1e860;
int stringToInt(const string&);
struct BV10WL {BV10WL();~BV10WL();void add(int,int);int &pick();int &pickNot(int);int size() const;char pad[0x24];};
struct BV10Dispatch {int type;string label;};
struct BV10Spawn {int type;BV10Spawn(int);~BV10Spawn();char pad[0x24-4];};
struct BV10Zionmind {
 void spawnDispatchItems(const BV10Point&,BV10ItemType*,BV10Dispatch*,vector<BV10HI>&);
 void spawnDispatchGroup(const BV10Point&,BV10Record*,int,BV10Dispatch*,vector<BV10HE>*);
 void unknown6bed40(BV10WL&,BV10WL&);
 void newTurn();
 char pad[0x20];vector<int> heroes;vector<int> rescued;int lastDepth;char pad44[4];vector<int> dispatchRecords;vector<BV10Spawn*> spawns;BV10Dispatch *current;BV10HP bay;
};
void BV10Zionmind::newTurn() {
 int depth=bv10_location_d1e888->depth46ed20();
 if(bv10_maxSpawns_bbb5bc[depth]&&bv10_zionFlags_b90458[bv10_location_d1e888->type]&&!dispatchRecords.empty()) {
  if(current) {
   if(bay.get()&&!bay->unknown457b10()) {
    BV10Point to(bay->position4184d0());
    vector<BV10Point> cols;
    sweepGetSurroundingCells(to,cols);
    for(unsigned i=0;i<cols.size();i++)
     if((*bv10_cells_cfd44c.atPoint(cols[i]))->getProp().isValid()&&(*bv10_cells_cfd44c.atPoint(cols[i]))->getProp()->id44ab40()==bay->id44ab40())
      (*bv10_cells_cfd44c.atPoint(cols[i]))->getProp()->unknown45ce10(1,0,1,BV10HE());
    (*bv10_cells_cfd44c.atPoint(to))->getProp()->unknown45ce10(1,0,1,BV10HE());
    int flags=current->type;
    vector<BV10HE> enemies;
    vector<BV10HI> vec;
    BV10ItemType *elem;
    BV10Record *r1;
    if(flags<=7) {
     if(dispatchRecords[flags]==bv10_none_caf160) {
      switch(flags) {
      case 2:
       if(!BV10_findByName(bv10_itemTypes_d2d1c4,"Z-Drone Bay",elem)) {
        logError("Zionmind::newTurn()","found no bay for "+bv10_typeNames_d29af8[flags]);
        break;
       }
       spawnDispatchItems(to,elem,current,vec);
       break;
      case 6:
       if(!BV10_findByName(bv10_records_d25de0,depth==10?"Z_Experiment_10":"Z_Experiment_10",r1))
       {
        logError("Zionmind::newTurn()","found no Ent for "+bv10_typeNames_d29af8[flags]);
        break;
       }
       spawnDispatchGroup(to,r1,2,current,&enemies);
       break;
      case 7:
       r1=bv10_records_d25de0[heroes[bv10_location_d1e888->depth46ed20()]];
       spawnDispatchGroup(to,r1,2,current,&enemies);
       lastDepth=bv10_location_d1e888->depth46ed20();
       heroes[bv10_location_d1e888->depth46ed20()]=bv10_none_caf160;
       bv10_sound_4541b0(300,0,0);
       bv10_playerData_cf45d8.unknown77fbc0(0xcd);
       break;
      }
     }
     else {
      r1=bv10_records_d25de0[dispatchRecords[flags]];
      spawnDispatchGroup(to,r1,2,current,&enemies);
     }
     if(!enemies.empty()&&!bv10_dialogNames_cf09b8[flags].empty()&&!current->label.empty())
      bv10_world_cefc4c->unknown6c65a0(enemies.front(),"ZIO_Dispatch_"+bv10_dialogNames_cf09b8[flags],false);
    }
    else {
     if(!BV10_findByName(bv10_records_d25de0,"Z_Courier",r1)) {}
     else {
      spawnDispatchGroup(to,r1,1,current,&enemies);
      if(!enemies.empty()) {
       if(flags==0xc)
        bv10_world_cefc4c->giveItem("Trap Extractor",enemies[0],0,0);
       BV10WL found;
       float color;
       int value;
       for(unsigned i=0;i<bv10_itemTypes_d2d1c4.size();i++) {
        if(bv10_containsRecord(bv10_itemTypes_d2d1c4[i]->dispatchTypes,flags)&&depth>=bv10_itemTypes_d2d1c4[i]->minDepth) {
         color=1.0f;
         switch(bv10_itemTypes_d2d1c4[i]->category) {
         break;
         case 1:
         case 2:
          color-=(bv10_gameData_d1e860.unknown46f4e0()-bv10_itemTypes_d2d1c4[i]->minDepth)*(bv10_itemTypes_d2d1c4[i]->category==1?bv10_c_ba32f4:bv10_c_ba3664);
          if(color<=0.0)
           continue;
          break;
         }
         value=(int)((bv10_itemTypes_d2d1c4[i]->weight?bv10_itemTypes_d2d1c4[i]->weight:bv10_weight_ba3ad0)*color);
         if(value>0)
          found.add(i,value);
        }
       }
       if(!found.size()) {}
       else {
        bool first=false;
        BV10HI h;
        for(int n=bv10_itemCounts_bbba30[flags];n;n--) {
         h=bv10_world_cefc4c->unknown6c51d0(bv10_itemTypes_d2d1c4[found.pick()],enemies[0],false,true);
         if(h.isValid()) {
          if(h->unknown457ff0())
           h->setCached44fc60(h->unknown457fb0());
          if(h->getField415ee0()) {
           if(first)
            h->unknown458390(0);
           else
            first=true;
          }
         }
        }
       }
      }
     }
    }
    if(!enemies.empty()||!vec.empty()) {
     BV10Effect *fx;
     if(bv10_lookup2("Zion_Dispatch",fx)) {
      for(unsigned g=0;g<enemies.size();g++) {
       vector<BV10Point> *area=enemies[g]->unknown45d1a0();
       for(unsigned c=0;c<area->size();c++)
        bv10_objB_cefc50->unknown508610(bv10_objB_cefc50,fx,(*area)[c],&bv10_d2e20c,0,0,0,9,0)->init_503b20();
      }
      for(unsigned k=0;k<vec.size();k++)
       bv10_objB_cefc50->unknown508610(bv10_objB_cefc50,fx,vec[k]->unknown575920(),&bv10_d2e20c,0,0,0,9,0)->init_503b20();
     }
     bv10_sound_4541b0(0xb4,0,0);
     bv10_stats_d2c658.add4729d0(0x381,1,bv10_empty_b958ab,-1);
     bv10_stats_d2c658.add4729d0(0x382+flags,1,bv10_empty_b958b2,-1);
     if((*bv10_stats_d2c658.values)[0x381]==10)
      bv10_playerData_cf45d8.unknown77fbc0(0xcc);
     if(flags<=7) {
      if(flags==7)
       do {bv10_logPhrase_5141b0(0x86,&enemies.front()->name416f40(),0,0,BV10HE(),0);} while(0);
      else
       do {bv10_logPhrase_5141b0(0x85,&bv10_typeNames_d29af8[flags],0,0,BV10HE(),0);} while(0);
     }
     else
      do {bv10_logPhrase_5141b0(0x87,&bv10_typeNames_d29af8[flags],0,0,BV10HE(),0);} while(0);
    }
   }
   delete current;
   current=NULL;
   bay.reset();
  }
  bool failed=false;
  BV10WL prev;
  BV10WL pt;
  unknown6bed40(prev,pt);
  if(bv10_world_cefc4c->unknown4642d0()%300==0) {
   bool hasSeven=false;
   for(unsigned i=0;i<spawns.size();i++)
    if(spawns[i]->type==7) {
     hasSeven=true;
     break;
    }
   for(unsigned j=0;j<spawns.size();j++) {
    if(rng.chance(25)) {
     delete spawns[j];
     spawns[j]=new BV10Spawn(rng.chance(bv10_chances_bbb5e8[depth])?(hasSeven?prev.pickNot(7):prev.pick()):pt.pick());
     if(spawns[j]->type==7)
      hasSeven=true;
     failed=true;
    }
   }
  }
  if(bv10_world_cefc4c->unknown4642d0()%410==0) {
   bool hasSeven2=false;
   for(unsigned i=0;i<spawns.size();i++)
    if(spawns[i]->type==7) {
     hasSeven2=true;
     break;
    }
   for(int n=spawns.size();n<bv10_maxSpawns_bbb5bc[depth];n++) {
    if(rng.chance(33)) {
     spawns.push_back(new BV10Spawn(rng.chance(bv10_chances_bbb5e8[depth])?(hasSeven2?prev.pickNot(7):prev.pick()):pt.pick()));
     if(spawns.back()->type==7)
      hasSeven2=true;
     failed=true;
    }
   }
  }
  if(failed)
   for(int k=1;k<=6;k++)
    bv10_counters_d1e920[k]=0;
 }
 if((bv10_location_d1e888->type==0x10||bv10_location_d1e888->type==0x11)&&heroes[depth]!=bv10_none_caf160&&!stringToInt(bv10_gameData_d1e860.getEntryText("zioAttackedLocals_g"))&&rescued[depth]==0&&bv10_world_cefc4c->getPlayer()->unknown5c98c0(1,0x19,1)) {
  rescued[depth]=1;
  if(rng.chance(bv10_location_d1e888->caves?10:25)) {
   rescued.assign(rescued.size(),1);
   BV10HE hero=bv10_world_cefc4c->placeEntity(bv10_records_d25de0[heroes[depth]],bv10_world_cefc4c->position4184d0(),2,false,0x22,0xe,false);
   if(hero.isValid()) {
    hero->removeEffectsA(0);
    hero->getAI()->setFollowEntity(bv10_world_cefc4c->getPlayer(),2);
    hero->unknown6396a0("ZIO_Cave_Rescue_Hero_1",0);
    bv10_message_49c610(0x320,BV10HE(),string("A strange signal echoes through the caves."),0);
    bv10_sound_4541b0(300,0,0);
    heroes[depth]=bv10_none_caf160;
   }
  }
 }
}
