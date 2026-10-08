// NOTE: placeholder names and partial layouts; Overmind dispatcher 0x685a10 (Zion/Q-series party).
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;
struct BV4Entity;struct BV4AI;
struct BV4Point {int x,y;BV4Point();BV4Point(int);BV4Point(const BV4Point&) throw();};
struct BV4Area {BV4Point min,max;BV4Area();BV4Area &operator=(const BV4Area&);};
struct BV4HE {int id;BV4HE();bool isNull() const;bool isValid() const;BV4Entity *operator->() const;};
struct BV4ItemType;
struct BV4Entity {int getFaction();void unknown5de480(BV4ItemType*);void unknown5deb40(int);void unknown5ded70(int);BV4Point &getPosition();BV4AI *getAI();bool isPlayer();void unknown5fdab0();};
struct BV4AI {void unknown459470(BV4Area&);void setUnknown451930(int);void setFollowEntity(BV4HE,int);};
struct BV4Record {char pad[0x28];int group;};
struct BV4World {int unknown4638e0(int,int);BV4HE placeEntity(BV4Record*,const BV4Point&,int,bool,int,int,bool);int unknown715730(int);BV4Record *unknown6c5600(int,int,bool,bool);int getTurn();};
extern BV4World *bv4_world_cefc4c;extern BV4Record *bv4_record_cefc08;extern int bv4_turns_b91e18;extern int bv4_radius_b91df8;
struct BV4Grid {void getRect(const BV4Point&,int,BV4Area&);BV4Area getArea();};extern BV4Grid bv4_cells_cfd44c;
struct BV4GameData {const string &getEntryText(const string&);int unknown46f4e0();};extern BV4GameData bv4_gameData_d1e860;
int stringToInt(const string&);
struct BV4LocInfo {int pad0;int type;};
struct BV4HLoc {int ID;BV4LocInfo *operator->() const;bool operator!=(BV4HLoc) const;};extern BV4HLoc bv4_location_d1e888,bv4_loc_d1ebe0,bv4_loc_d1ebd8;
struct BV4Stats {bool add4729d0(unsigned,int,string,int);};extern BV4Stats bv4_stats_d2c658;extern const char bv4_empty_b95727[],bv4_empty_b9572f[];
struct BV4Chances {int a,b,pad[2];};extern BV4Chances bv4_chances_b93f20[];
struct BV4Weights3 {int w[3];};extern BV4Weights3 bv4_weights_b93e88[];
struct BV4WL {BV4WL();~BV4WL();void add(int,int);bool pick(int*);int size() const;char pad[0x24];};
template<class T> void BV4_eraseAt(vector<T>&,int);
void BV4_clampDown_9d0690(int*,int,int);
struct BV4Party {BV4Party(int,BV4HE,int,bool,int);char pad[0x38];};
struct BV4Range {int a,b;int randomInRange_40c130();};extern BV4Range bv4_ranges_d29310[][2];
struct BV4Wt2 {int w[2];};extern BV4Wt2 bv4_weights_b93738[];extern bool bv4_flag_d1eb99;extern int bv4_turns_b91e00;extern int bv4_radius_b91df4;
extern vector<BV4ItemType*> bv4_itemTypes_d2d1c4;
void logError(string location,string message);
struct BV4Overmind {
 bool unknown683500(BV4Point*,bool,int,bool,const BV4Point&,BV4Point**,bool,bool);
 void unknown683e60(const BV4Point&,vector<vector<BV4HE> >&);
 void unknown6827d0(BV4Party*,BV4Point*);
 void loadZWeaponList(vector<int>&,int);
 void spawnSurgicalParty(vector<int>&,vector<int>&);
 int dispatch685a10(BV4HE target,const BV4Point *area);
 char pad[0x4c];int unknown4c;char pad50[0x90-0x50];void *surgical;char pad94[0x128-0x94];int unknown128;
};
int BV4Overmind::dispatch685a10(BV4HE target,const BV4Point *area) {
 if(stringToInt(bv4_gameData_d1e860.getEntryText("comConduitDisabled_g"))||unknown4c||bv4_world_cefc4c->unknown4638e0(0,3)==2)
  return 0;
 bool seen=bv4_location_d1e888->type==0x22;
 vector<vector<BV4HE> > robots;
 if(seen)
  unknown683e60(area?*area:target->getPosition(),robots);
 BV4WL weight;
 for(int i=0;i<2;i++) {
  int w=bv4_weights_b93738[bv4_gameData_d1e860.unknown46f4e0()].w[i];
  if(w&&i==1&&bv4_flag_d1eb99)
   w/=2;
  weight.add(i,w);
 }
 int type;
 do
  weight.pick(&type);
 while(type==1&&(!surgical||seen));
 int n=bv4_ranges_d29310[bv4_gameData_d1e860.unknown46f4e0()][type].randomInRange_40c130()-1;
 BV4Record *kind;
 BV4Record *elem;
 switch(type) {
 case 0: kind=bv4_world_cefc4c->unknown6c5600(1,0x19,false,false); elem=NULL; break;
 case 1: kind=bv4_world_cefc4c->unknown6c5600(1,0x1b,false,false); elem=NULL; break;
 }
 if(!kind)
  return 0;
 if(!elem)
  elem=kind;
 BV4Point offset;
 BV4Point *root=NULL;
 if(!seen&&!unknown683500(&offset,1,0,1,BV4Point(-1),&root,0,0)) {
  unknown128++;
  return 0;
 }
 else
  BV4_clampDown_9d0690(&unknown128,1,0);
 int amount=0;
 vector<BV4HE> elements;
 BV4HE other;
 if(seen) {
  if(!robots[kind->group].empty()) {
   other=robots[kind->group][0];
   BV4_eraseAt(robots[kind->group],0);
   other->unknown5fdab0();
  }
 }
 else
  other=bv4_world_cefc4c->placeEntity(kind,offset,3,false,0x22,0xe,false);
 if(other.isValid()) {
  amount++;
  BV4Point center(area?*area:target->getPosition());
  BV4Area room;
  bv4_cells_cfd44c.getRect(center,bv4_radius_b91df4,room);
  other->getAI()->unknown459470(room);
  other->getAI()->setUnknown451930(0);
  if(other->getFaction()==0x1b)
   elements.push_back(other);
  while(n) {
   BV4HE e;
   if(seen) {
    if(!robots[elem->group].empty()) {
     e=robots[elem->group][0];
     BV4_eraseAt(robots[elem->group],0);
     e->unknown5fdab0();
    }
   }
   else
    e=bv4_world_cefc4c->placeEntity(elem,offset,3,false,0x22,0xe,false);
   if(e.isNull())
    break;
   e->getAI()->setFollowEntity(other,0);
   e->getAI()->setUnknown451930(0);
   if(e->getFaction()==0x1b)
    elements.push_back(e);
   n--;
   amount++;
  }
  unknown6827d0(new BV4Party(5,other,-1,target.isValid()&&target->isPlayer(),bv4_world_cefc4c->getTurn()+bv4_turns_b91e00),root);
 }
 if(!elements.empty()) {
  if(!surgical) {
   logError("Overmind::spawnSurgicalParty()","No analysis on which to base CLASS_QSERIES");
   return amount;
  }
  for(int i=0;i<elements.size();i++) {
   vector<int> weapons;
   loadZWeaponList(weapons,bv4_gameData_d1e860.unknown46f4e0());
   vector<int> parts;
   spawnSurgicalParty(parts,weapons);
   for(int j=0;j<weapons.size();j++)
    elements[i]->unknown5de480(bv4_itemTypes_d2d1c4[weapons[j]]);
   for(int k=0;k<parts.size();k++)
    elements[i]->unknown5de480(bv4_itemTypes_d2d1c4[parts[k]]);
   elements[i]->unknown5deb40(10000);
   elements[i]->unknown5ded70(10000);
  }
 }
 bv4_stats_d2c658.add4729d0(0x231,1,bv4_empty_b95727,-1);
 bv4_stats_d2c658.add4729d0(0x233,1,bv4_empty_b9572f,-1);
 return amount;
}
