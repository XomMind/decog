// NOTE: placeholder branch and partial layouts; Overmind::spawnCargoDispatch (0x68aec0): spawns the chance
// leader convoy with its escorts and loads its chance.
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;
struct BV5Entity;struct BV5AI;struct BV5Item;
struct BV5ItemType {char pad[0x4c];int size;};
struct BV5Point {int x,y;BV5Point(int,int);BV5Point &operator=(const BV5Point&);void shift(int);};
struct BV5HE {int id;BV5HE();bool isValid() const;BV5Entity *operator->() const;};
struct BV5HI {int id;BV5HI();bool isValid() const;BV5Item *operator->() const;};
struct BV5Item {int getNestedField();void remove57dbe0(int,int,bool,bool);void unknown57c110(const string&,int);};
struct BV5Entity {BV5Point &getPosition();BV5AI *getAI();int unknown5c8e20(int);int unknown5ca210();void unknown5cb830(vector<BV5HI>&);int unknown45a810();BV5HI unknown5d2380(int);};
struct BV5AI {void unknown4593b0(const BV5Point&);void setFollowEntity(BV5HE,int);void setField4505b0(int);};
struct BV5Record;
struct BV5World {BV5HE unknown6c5dc0(const string&,const BV5Point&,int,bool,int,int,bool);BV5HE placeEntity(BV5Record*,const BV5Point&,int,bool,int,int,bool);BV5Record *unknown6c5600(int,int,bool,bool);BV5HI unknown6c51d0(BV5ItemType*,BV5HE,bool,bool);void unknown464f60(BV5HI);BV5HE getPlayer();};
extern BV5World *bv5_world_cefc4c;extern BV5Record *bv5_record_cefc08;
struct BV5GameData {const string &getEntryText(const string&);int unknown46f4e0();};extern BV5GameData bv5_gameData_d1e860;
int stringToInt(const string&);
struct BV5LocInfo {int pad0,pad4;int depth;};
struct BV5HLoc {int ID;BV5HLoc();BV5LocInfo *operator->() const;};extern BV5HLoc bv5_location_d1e888;extern int bv5_map_d1e884;
bool bv5_findNode_470180(int,int,int,BV5HLoc*);
bool bv5_between_9daf80(int,int,int);
struct BV5Difficulty {int ringChance,extraChance,pad[8];};extern BV5Difficulty bv5_difficulty_b939c0[];
struct BV5Range {int a,b;int randomInRange_40c130();};extern BV5Range bv5_range_d30348,bv5_range_d21760;
extern vector<BV5ItemType*> bv5_itemTypes_d2d1c4;
template<class T> bool BV5_findByName(vector<T*>&,const string&,T*&);
string BV5_randomString(vector<string>&);
BV5HI BV5_popRandom(vector<BV5HI>&);
struct BV5WLI {BV5ItemType *&pick();};extern BV5WLI bv5_items_d31700;
extern int bv5_difficulty_cf4718;extern int bv5_escorts_ba6608[];
void logWarning(string location,string message);
struct BV5Party {BV5Party(int,BV5HE,int,int,int);char pad[0x38];};
struct BV5PlayerData {bool isSlotEmpty(int);void unknown77fbc0(int);};extern BV5PlayerData bv5_playerData_cf45d8;
struct BV5Overmind {
 void unknown6827d0(BV5Party*,BV5Point*);
 void unknown6901e0(BV5HE,int,int,int,const BV5Point&,int,int);
 int spawnCargoDispatch_68aec0();
 char pad[0xbc];int unknownbc;BV5Point unknownc0;BV5Point unknownc8;int unknownd0;BV5HE unknownd4;vector<BV5HE> unknownd8;char pade8[0xf8-0xe8];BV5Point unknownf8;
};
int BV5Overmind::spawnCargoDispatch_68aec0() {
 int count=0;
 BV5HE leader=bv5_world_cefc4c->unknown6c5dc0("A-27 Freighter",unknownc0,3,false,0x14,0xe,false);
 if(leader.isValid()) {
  count++;
  leader->getAI()->unknown4593b0(unknownc8);
  unknownd4=leader;
  unknownf8=unknownd4->getPosition();
  int level=bv5_gameData_d1e860.unknown46f4e0()+1;
  BV5Point r1(level,level+2);
  if(r1.y>9)
   r1.shift(9-r1.y);
  unknown6901e0(unknownd4,1,bv5_range_d30348.randomInRange_40c130(),bv5_range_d21760.randomInRange_40c130(),r1,1,0x2a);
  bool tag=false;
  BV5HLoc prev;
  BV5HLoc cur;
  if(bv5_findNode_470180(0xb,-1,bv5_map_d1e884,&prev)&&bv5_findNode_470180(0x1c,-1,bv5_map_d1e884,&cur)&&bv5_between_9daf80(cur->depth,bv5_location_d1e888->depth,prev->depth-2)&&!stringToInt(bv5_gameData_d1e860.getEntryText("scrConvoyRingOfPowerDropped_g")))
   tag=true;
  bool chance=bv5_difficulty_b939c0[bv5_gameData_d1e860.unknown46f4e0()].ringChance&&rng.chance(bv5_difficulty_b939c0[bv5_gameData_d1e860.unknown46f4e0()].ringChance);
  if(tag||chance) {
   if(chance&&unknownbc==1)
    tag=false;
   BV5ItemType *kind;
   vector<string> branch;
   if(tag)
    branch.push_back("PL-3XN's Ring of Power");
   else {
    branch.push_back("Active Cooling Armor");
    branch.push_back("Exp. Thermic Cannon");
   }
   const int total2=1;
   vector<BV5ItemType*> slots;
   int value=unknownd4->unknown5c8e20(0);
   int last=unknownd4->unknown5ca210();
   vector<BV5HI> vec2;
   unknownd4->unknown5cb830(vec2);
   for(int i=0;i<total2;i++) {
    if(BV5_findByName(bv5_itemTypes_d2d1c4,BV5_randomString(branch),kind)) {
     slots.push_back(kind);
     value+=kind->size;
     while(value>last) {
      if(vec2.empty())
       goto done;
      BV5HI it=BV5_popRandom(vec2);
      value-=it->getNestedField();
      it->remove57dbe0(0,0,true,true);
     }
    }
   }
   for(int j=0;j<slots.size();j++) {
    BV5HI item=bv5_world_cefc4c->unknown6c51d0(slots[j],unknownd4,false,false);
    if(item.isValid()&&tag) {
     item->unknown57c110("SCR_RingOfPower_Convoy",0);
     bv5_world_cefc4c->unknown464f60(item);
    }
   }
done:;
  }
  if(bv5_difficulty_b939c0[bv5_gameData_d1e860.unknown46f4e0()].extraChance&&rng.chance(bv5_difficulty_b939c0[bv5_gameData_d1e860.unknown46f4e0()].extraChance)) {
   int n=unknownd4->unknown45a810();
   while(n) {
    bv5_world_cefc4c->unknown6c51d0(bv5_items_d31700.pick(),unknownd4,false,false);
    n--;
   }
  }
  BV5HE attempt;
  BV5Record *base=bv5_record_cefc08;
  for(int k=bv5_escorts_ba6608[bv5_difficulty_cf4718];k>0;k--) {
   attempt=bv5_world_cefc4c->placeEntity(base,unknownd4->getPosition(),3,false,0x22,0xe,false);
   if(attempt.isValid()) {
    attempt->getAI()->setFollowEntity(unknownd4,0);
    attempt->getAI()->setField4505b0(4);
    unknownd8.push_back(attempt);
    count++;
   }
   else
    logWarning("Overmind::spawnCargoDispatch()","Carrier spawn failed");
  }
  base=bv5_world_cefc4c->unknown6c5600(1,0x13,false,true);
  if(base) {
   attempt=bv5_world_cefc4c->placeEntity(base,unknownd4->getPosition(),3,false,0x22,0xe,false);
   if(attempt.isValid()) {
    attempt->getAI()->setFollowEntity(unknownd4,0);
    unknownd8.push_back(attempt);
    count++;
   }
  }
  unknown6827d0(new BV5Party(3,leader,-1,0,0),NULL);
  if(bv5_playerData_cf45d8.isSlotEmpty(0x76)&&(bv5_world_cefc4c->getPlayer()->unknown5d2380(0x16).isValid()||bv5_world_cefc4c->getPlayer()->unknown5d2380(0x17).isValid()))
   bv5_playerData_cf45d8.unknown77fbc0(0x76);
 }
 return count;
}
