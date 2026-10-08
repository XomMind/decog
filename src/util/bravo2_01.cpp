// NOTE: placeholder names and partial layouts; Overmind dispatcher 0x687520 (comms dispatch of a hunting party).
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;
struct BV2Entity;struct BV2AI;
struct BV2Point {int x,y;BV2Point();BV2Point(int);};
struct BV2Area {BV2Point min,max;BV2Area();BV2Area &operator=(const BV2Area&);};
struct BV2HE {int id;BV2HE();bool isNull() const;bool isValid() const;BV2Entity *operator->() const;};
struct BV2Entity {BV2Point &getPosition();BV2AI *getAI();bool isPlayer();void unknown5fdab0();};
struct BV2AI {void unknown459470(BV2Area&);void setUnknown451930(int);void setFollowEntity(BV2HE,int);};
struct BV2Record {char pad[0x28];int group;};
struct BV2World {int unknown4638e0(int,int);BV2HE placeEntity(BV2Record*,const BV2Point&,int,bool,int,int,bool);int unknown715730(int);BV2Record *unknown6c5600(int,int,bool,bool);int getTurn();};
extern BV2World *bv2_world_cefc4c;extern BV2Record *bv2_record_cefc08;extern int bv2_turns_b91e18;extern int bv2_radius_b91df8;
struct BV2Grid {void getRect(const BV2Point&,int,BV2Area&);BV2Area getArea();};extern BV2Grid bv2_cells_cfd44c;
struct BV2GameData {const string &getEntryText(const string&);int unknown46f4e0();};extern BV2GameData bv2_gameData_d1e860;
int stringToInt(const string&);
struct BV2LocInfo {int pad0;int type;};
struct BV2HLoc {int ID;BV2LocInfo *operator->() const;bool operator!=(BV2HLoc) const;};extern BV2HLoc bv2_location_d1e888,bv2_loc_d1ebe0,bv2_loc_d1ebd8;
struct BV2Stats {bool add4729d0(unsigned,int,string,int);};extern BV2Stats bv2_stats_d2c658;extern const char bv2_empty_b9573b[],bv2_empty_b9574b[];
struct BV2Chances {int a,b,pad[2];};extern BV2Chances bv2_chances_b93f20[];
struct BV2Weights3 {int w[3];};extern BV2Weights3 bv2_weights_b93e88[];
struct BV2WL {BV2WL();~BV2WL();void add(int,int);bool pick(int*);int size() const;char pad[0x24];};
template<class T> void BV2_eraseAt(vector<T>&,int);
void BV2_clampDown_9d0690(int*,int,int);
struct BV2Party {BV2Party(int,BV2HE,int,bool,int);char pad[0x38];};
struct BV2Overmind {
 bool unknown683500(BV2Point*,bool,int,bool,const BV2Point&,BV2Point**,bool,bool);
 void unknown683e60(const BV2Point&,vector<vector<BV2HE> >&);
 void unknown6827d0(BV2Party*,BV2Point*);
 int dispatch687520(BV2HE target,const BV2Point *area,bool alone);
 char pad[0x4c];int unknown4c;char pad50[0x128-0x50];int unknown128;
};
int BV2Overmind::dispatch687520(BV2HE target,const BV2Point *area,bool alone) {
 if(stringToInt(bv2_gameData_d1e860.getEntryText("comConduitDisabled_g"))||unknown4c||bv2_world_cefc4c->unknown4638e0(0,3)==2)
  return 0;
 bool location=bv2_location_d1e888->type==0x22;
 vector<vector<BV2HE> > robots;
 if(location) {
  unknown683e60(area?*area:target->getPosition(),robots);
 }
 bool valid=true;
 if(bv2_location_d1e888->type==0x21&&stringToInt(bv2_gameData_d1e860.getEntryText("frgUfdAttacked_g")))
  valid=false;
 BV2Record *elem=bv2_record_cefc08;
 BV2Point other;
 BV2Point *best=NULL;
 if(!location&&!unknown683500(&other,1,0,valid,BV2Point(-1),&best,0,0)) {
  unknown128++;
  return 0;
 }
 else
  BV2_clampDown_9d0690(&unknown128,1,0);
 BV2HE first;
 if(location) {
  if(!robots[elem->group].empty()) {
   first=robots[elem->group][0];
   BV2_eraseAt(robots[elem->group],0);
   first->unknown5fdab0();
  }
 }
 else
  first=bv2_world_cefc4c->placeEntity(elem,other,3,false,0x22,0xe,false);
 if(first.isNull())
  return 0;
 BV2Area room;
 if(target.isValid())
  bv2_cells_cfd44c.getRect(target->getPosition(),bv2_radius_b91df8,room);
 else if(area)
  bv2_cells_cfd44c.getRect(*area,0xf,room);
 else
  room=bv2_cells_cfd44c.getArea();
 first->getAI()->unknown459470(room);
 first->getAI()->setUnknown451930(0);
 int count=1;
 int value=bv2_world_cefc4c->unknown715730(1);
 if(value&&!alone) {
  int extra=0;
  if(rng.chance(value*bv2_chances_b93f20[bv2_gameData_d1e860.unknown46f4e0()].a))
   extra++;
  if(extra&&rng.chance(value*bv2_chances_b93f20[bv2_gameData_d1e860.unknown46f4e0()].b))
   extra++;
  if(extra) {
   BV2WL weights;
   for(int i=0;i<3;i++)
    weights.add(i,bv2_weights_b93e88[bv2_gameData_d1e860.unknown46f4e0()].w[i]);
   if(!weights.size()) {}
   else {
    int type;
    BV2Record *rec;
    for(int j=0;j<extra;j++) {
     weights.pick(&type);
     if(value<2&&type<=1)
      type=2;
     switch(type) {
     case 0: rec=bv2_world_cefc4c->unknown6c5600(1,0x16,false,false); break;
     case 1: rec=bv2_world_cefc4c->unknown6c5600(1,0x17,false,false); break;
     case 2: rec=bv2_world_cefc4c->unknown6c5600(1,0x19,false,false); break;
     }
     if(!rec)
      goto done;
     BV2HE e;
     if(location) {
      if(!robots[rec->group].empty()) {
       e=robots[rec->group][0];
       BV2_eraseAt(robots[rec->group],0);
       e->unknown5fdab0();
      }
     }
     else
      e=bv2_world_cefc4c->placeEntity(rec,other,3,false,0x22,0xe,false);
     if(e.isNull())
      break;
     e->getAI()->setFollowEntity(first,0);
     count++;
    }
   }
  }
 }
done:
 unknown6827d0(new BV2Party(7,first,-1,target.isValid()&&target->isPlayer(),bv2_world_cefc4c->getTurn()+bv2_turns_b91e18),best);
 if(bv2_location_d1e888!=bv2_loc_d1ebe0&&bv2_location_d1e888!=bv2_loc_d1ebd8&&!(bv2_location_d1e888->type==0x21&&stringToInt(bv2_gameData_d1e860.getEntryText("frgUfdAttacked_g")))) {
  bv2_stats_d2c658.add4729d0(0x231,1,bv2_empty_b9573b,-1);
  bv2_stats_d2c658.add4729d0(0x235,1,bv2_empty_b9574b,-1);
 }
 return count;
}
