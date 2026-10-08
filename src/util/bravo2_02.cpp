// NOTE: placeholder names and partial layouts; Overmind dispatcher 0x684250 (investigation squad).
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;
struct BV3Entity;struct BV3AI;
struct BV3Point {int x,y;BV3Point();BV3Point(int);};
struct BV3Area {BV3Point min,max;BV3Area();BV3Area &operator=(const BV3Area&);};
struct BV3HE {int id;BV3HE();bool isNull() const;bool isValid() const;BV3Entity *operator->() const;};
struct BV3Entity {BV3Point &getPosition();BV3AI *getAI();bool isPlayer();void unknown5fdab0();};
struct BV3AI {void unknown459470(BV3Area&);void setUnknown451930(int);void setFollowEntity(BV3HE,int);};
struct BV3Record {char pad[0x28];int group;};
struct BV3World {BV3HE getPlayer();int unknown4638e0(int,int);BV3HE placeEntity(BV3Record*,const BV3Point&,int,bool,int,int,bool);int unknown715730(int);BV3Record *unknown6c5600(int,int,bool,bool);int getTurn();};
extern BV3World *bv3_world_cefc4c;extern BV3Record *bv3_record_cefc08;extern int bv3_turns_b91e18;extern int bv3_radius_b91df8;
struct BV3Grid {void getRect(const BV3Point&,int,BV3Area&);BV3Area getArea();};extern BV3Grid bv3_cells_cfd44c;
struct BV3GameData {const string &getEntryText(const string&);int unknown46f4e0();};extern BV3GameData bv3_gameData_d1e860;
int stringToInt(const string&);
struct BV3LocInfo {int pad0;int type;};
struct BV3HLoc {int ID;BV3LocInfo *operator->() const;bool operator!=(BV3HLoc) const;};extern BV3HLoc bv3_location_d1e888,bv3_loc_d1ebe0,bv3_loc_d1ebd8;
struct BV3Stats {bool add4729d0(unsigned,int,string,int);};extern BV3Stats bv3_stats_d2c658;extern const char bv3_empty_b95725[],bv3_empty_b95726[];
struct BV3Chances {int a,b,pad[2];};extern BV3Chances bv3_chances_b93f20[];
struct BV3Weights3 {int w[3];};extern BV3Weights3 bv3_weights_b93e88[];
struct BV3WL {BV3WL();~BV3WL();void add(int,int);bool pick(int*);int size() const;char pad[0x24];};
template<class T> void BV3_eraseAt(vector<T>&,int);
void BV3_clampDown_9d0690(int*,int,int);
struct BV3Party {BV3Party(int,BV3HE,int,int,int);char pad[0x38];};
struct BV3Range {int a,b;int randomInRange_40c130();};extern BV3Range bv3_ranges_cf08f8[][2];extern BV3Range bv3_range_d35bc8;
struct BV3Wt2 {int w[2];};extern BV3Wt2 bv3_weights_b93688[];
struct BV3Link {string unknown65cc80();};
struct BV3Prop {BV3Link *unknown45cb30();};
struct BV3HP {int id;BV3HP();bool isValid() const;BV3Prop *operator->() const;};
struct BV3Cell {BV3HP getProp();};
struct BV3CellGrid {BV3Cell *&at(const BV3Point&);};extern BV3CellGrid bv3_cellgrid_cfd44c;
extern string gameStrings_cf25d8[];
struct BV3Console {bool isHidden();};extern BV3Console *bv3_console_cec0f8;
struct BV3Flags {void setUnknown(int);};extern BV3Flags bv3_flags_cf1080;extern bool bv3_mute_d28fb0;
void bv3_sound_4541b0(int,int,int);
bool bv3_show_5111e0(int,const string&,int,int,BV3HE,BV3HE,int,int);
struct BV3Bubble {void unknown8758d0(bool);};extern BV3Bubble *bv3_bubble_cec058;
struct BV3Log {void scrollToEnd();};extern BV3Log *bv3_log_cec0b4;
struct BV3Shell {void unknown90ec30(string);};extern BV3Shell *bv3_shell_cec100;
#define BV3_LOG(id,text) do { if (bv3_show_5111e0(id,text,0,0,BV3HE(),BV3HE(),0,0)) bv3_bubble_cec058->unknown8758d0(true); bv3_log_cec0b4->scrollToEnd(); } while (0)
#define BV3_ALERT_EXPR(sound,text) do { bv3_flags_cf1080.setUnknown(1); if ((sound) >= 0 && (!bv3_mute_d28fb0 || (sound) < 0x127 || (sound) > 0x12a)) bv3_sound_4541b0(sound,0,0); BV3_LOG(0x324,text); bv3_log_cec0b4->scrollToEnd(); } while (0)
struct BV3Overmind {
 bool unknown683500(BV3Point*,bool,int,bool,const BV3Point&,BV3Point**,bool,bool);
 void unknown683e60(const BV3Point&,vector<vector<BV3HE> >&);
 void unknown6827d0(BV3Party*,BV3Point*);
 int dispatch684250(const BV3Point &target,bool quiet);
 char pad[0x4c];int unknown4c;char pad50[0x128-0x50];int unknown128;
};
int BV3Overmind::dispatch684250(const BV3Point &target,bool quiet) {
 if(stringToInt(bv3_gameData_d1e860.getEntryText("comConduitDisabled_g"))||unknown4c||bv3_world_cefc4c->unknown4638e0(0,3)==2)
  return 0;
 bool location=bv3_location_d1e888->type==0x22;
 vector<vector<BV3HE> > robots;
 if(location)
  unknown683e60(target,robots);
 BV3WL weight;
 for(int i=0;i<2;i++)
  weight.add(i,bv3_weights_b93688[bv3_gameData_d1e860.unknown46f4e0()].w[i]);
 int type;
 weight.pick(&type);
 int n=bv3_ranges_cf08f8[bv3_gameData_d1e860.unknown46f4e0()][type].randomInRange_40c130()-1;
 BV3Record *kind;
 BV3Record *elem;
 switch(type) {
 case 0: kind=bv3_world_cefc4c->unknown6c5600(1,0x10,false,false); elem=NULL; break;
 case 1: kind=bv3_world_cefc4c->unknown6c5600(1,0x18,false,false); elem=NULL; break;
 }
 if(!kind)
  return 0;
 if(!elem)
  elem=kind;
 BV3Point offset;
 BV3Point *root=NULL;
 if(!location&&!unknown683500(&offset,0,0,1,bv3_world_cefc4c->getPlayer()->getPosition(),&root,0,0)) {
  unknown128++;
  return 0;
 }
 else
  BV3_clampDown_9d0690(&unknown128,1,0);
 int amount=0;
 BV3HE active;
 if(location) {
  if(!robots[kind->group].empty()) {
   active=robots[kind->group][0];
   BV3_eraseAt(robots[kind->group],0);
   active->unknown5fdab0();
  }
 }
 else
  active=bv3_world_cefc4c->placeEntity(kind,offset,3,false,0x22,0xe,false);
 if(active.isValid()) {
  amount++;
  BV3Area room;
  bv3_cells_cfd44c.getRect(target,5,room);
  active->getAI()->unknown459470(room);
  while(n) {
   BV3HE e;
   if(location) {
    if(!robots[elem->group].empty()) {
     e=robots[elem->group][0];
     BV3_eraseAt(robots[elem->group],0);
     e->unknown5fdab0();
    }
   }
   else
    e=bv3_world_cefc4c->placeEntity(elem,offset,3,false,0x22,0xe,false);
   if(e.isNull())
    break;
   e->getAI()->setFollowEntity(active,0);
   n--;
   amount++;
  }
  unknown6827d0(new BV3Party(4,active,bv3_world_cefc4c->getTurn()+bv3_range_d35bc8.randomInRange_40c130(),0,0),root);
  if(!quiet&&bv3_cellgrid_cfd44c.at(target)->getProp().isValid()&&bv3_cellgrid_cfd44c.at(target)->getProp()->unknown45cb30()) {
   string text="ALERT: Suspicious activity at "+bv3_cellgrid_cfd44c.at(target)->getProp()->unknown45cb30()->unknown65cc80()+". Dispatching "+gameStrings_cf25d8[4]+" squad.";
   BV3_ALERT_EXPR(bv3_console_cec0f8->isHidden()?0x127:-1,text);
   if(bv3_shell_cec100)
    bv3_shell_cec100->unknown90ec30(text);
  }
 }
 bv3_stats_d2c658.add4729d0(0x231,1,bv3_empty_b95725,-1);
 bv3_stats_d2c658.add4729d0(0x232,1,bv3_empty_b95726,-1);
 return amount;
}
