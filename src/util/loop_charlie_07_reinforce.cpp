// NOTE: private aliases and partial layouts for AI reinforcement helper0x5b3a30.
// Reserved Overmind helper methods are external declarations only.
#include <string>
#include <vector>
#include "rng.h"
extern RNG rng;
struct LC7Entity;struct LC7Item;
struct LC7Point {int x,y;LC7Point(const LC7Point&) throw();void assign_46ca50(const LC7Point&) throw();void set_40a010(int,int) throw();};
struct LC7Pos:LC7Point {LC7Pos(int) throw();LC7Pos(int,int) throw();};
struct LC7Rect {LC7Point min,max;LC7Rect() throw();};
struct LC7H {int id;LC7H() throw();LC7Entity *get_9b6570() const;bool valid_9b7230() const;};
struct LC7HI {int id;LC7HI() throw();bool valid_9b7230() const;LC7Item *get_9b65b0();};
struct LC7HP {int id;LC7HP() throw();};
struct LC7Record {char pad[0x48];int model;};
struct LC7Entity {const LC7Point &position_45a4a0();bool hostile_45aa70(LC7H);LC7HI item_5d2380(int);bool player_5c7600();int level_5d15a0(int);LC7Record *record_9b4350();};
struct LC7Item {std::string name_571db0(int,int);};
struct LC7Cell {LC7H entity_45d250();bool pass_66ab30(LC7H);};
struct LC7Grid {void rect_9b4430(const LC7Point&,int,LC7Rect&);LC7Cell*&at_9ceda0(int,int);LC7Cell*&point_9ced70(LC7Point&);};extern LC7Grid lc7_grid_cfd44c;
struct LC7Map {LC7H player_4630f0();bool visible_4631f0(LC7H);int turn_464270();int time_4642d0();int getDisabledGarrisonAccesses();bool line_716940(const LC7Point&,const LC7Point&,int,int);void notify_728970(LC7H,int);};extern LC7Map *lc7_map_cefc4c;
int lc7_distance_40a3f0(const LC7Point&,const LC7Point&);int lc7_distance_xy_406480(int,int,int,int);int lc7_min_9cdb30(int,int);
LC7H lc7_random_9dafb0(std::vector<LC7H>&);
struct LC7Stats {bool add_4729d0(unsigned,int,std::string,int);};extern LC7Stats lc7_stats_d2c658;extern const char lc7_empty_b93df5[];
struct LC7Console {void scroll_8758d0(bool);};extern LC7Console *lc7_console_cec058;
struct LC7Log {void end_7b4f10();};extern LC7Log *lc7_log_cec0b4;
bool lc7_show0_5111e0(int,int,int,int,LC7H,LC7HP,int,int);
bool lc7_show_5111e0(int,const std::string&,int,int,LC7H,LC7HP,int,int);
struct LC7GlobalRecord {int getDepthIndex();};struct LC7GlobalH {LC7GlobalRecord*get_9b7910();};extern LC7GlobalH lc7_global_d1e888;
struct LC7Response {int unk0,id,deadline;};
struct LC7Overmind {int reinforce_686c60(const LC7Point&,int,int,int);LC7Response*lastParty();void ready_68d920(bool);};extern LC7Overmind lc7_overmind_cf6428;
struct LC7Flags {void set_451400(int);};extern LC7Flags lc7_flags_cf1080;extern bool lc7_mute_d28fb0;
void lc7_sound_4541b0(int,int,int);
struct LC7Player {void event_77fbc0(int);};extern LC7Player lc7_player_cf45d8;
struct LC7AI {LC7H self;char pad[0x3c-4];int cooldown;LC7H*relation_459570(LC7H);bool jammed_581140();void reinforce_5b3a30(int);};
void LC7AI::reinforce_5b3a30(int range) {
 LC7Pos point(-1);
 if(cooldown==-1)point.assign_46ca50(lc7_map_cefc4c->player_4630f0().get_9b6570()->position_45a4a0());
 else if(lc7_distance_40a3f0(self.get_9b6570()->position_45a4a0(),lc7_map_cefc4c->player_4630f0().get_9b6570()->position_45a4a0())<=range)point.assign_46ca50(lc7_map_cefc4c->player_4630f0().get_9b6570()->position_45a4a0());
 else {
  std::vector<LC7H> list;
  LC7Rect area;
  lc7_grid_cfd44c.rect_9b4430(self.get_9b6570()->position_45a4a0(),range,area);
  for(int x=area.min.x;x<=area.max.x;x++)for(int y=area.min.y;y<=area.max.y;y++) {
   if(lc7_grid_cfd44c.at_9ceda0(x,y)->entity_45d250().valid_9b7230() && lc7_grid_cfd44c.at_9ceda0(x,y)->entity_45d250().get_9b6570()->hostile_45aa70(self) && lc7_distance_40a3f0(self.get_9b6570()->position_45a4a0(),LC7Pos(x,y))<=range && !relation_459570(lc7_grid_cfd44c.at_9ceda0(x,y)->entity_45d250()))list.push_back(lc7_grid_cfd44c.at_9ceda0(x,y)->entity_45d250());
  }
  if(!list.empty())point.assign_46ca50(lc7_random_9dafb0(list).get_9b6570()->position_45a4a0());
 }
 if(point.x!=-1) {
  LC7H target=lc7_grid_cfd44c.point_9ced70(point)->entity_45d250();
  LC7HI p=target.get_9b6570()->item_5d2380(32);
  if(jammed_581140()) {
   do {if(lc7_show0_5111e0(566,0,0,0,self,LC7HP(),0,0))lc7_console_cec058->scroll_8758d0(true);lc7_log_cec0b4->end_7b4f10();}while(false);
   lc7_stats_d2c658.add_4729d0(577,1,std::string(lc7_empty_b93df5),-1);
   cooldown=lc7_map_cefc4c->time_4642d0()+lc7_min_9cdb30(50,target.get_9b6570()->level_5d15a0(0)/2);
   return;
  }
  if(p.valid_9b7230()) {
   LC7Rect center;
   int count;
   lc7_grid_cfd44c.rect_9b4430(self.get_9b6570()->position_45a4a0(),range,center);
   LC7Point pick(self.get_9b6570()->position_45a4a0());
   int i=lc7_distance_40a3f0(pick,point);
   for(int x=center.min.x;x<=center.max.x;x++)for(int y=center.min.y;y<=center.max.y;y++) {
    if(lc7_grid_cfd44c.at_9ceda0(x,y)->pass_66ab30(LC7H())) {
     count=lc7_distance_xy_406480(point.x,point.y,x,y);
     if(count>i){i=count;pick.set_40a010(x,y);}
    }
   }
   if(lc7_map_cefc4c->line_716940(lc7_map_cefc4c->player_4630f0().get_9b6570()->position_45a4a0(),pick,0,0))point.assign_46ca50(pick);
   else point.assign_46ca50(self.get_9b6570()->position_45a4a0());
   if(lc7_map_cefc4c->visible_4631f0(target)) {
    do {if(lc7_show_5111e0(target.get_9b6570()->player_5c7600()?434:435,p.get_9b65b0()->name_571db0(0,0),0,0,target,LC7HP(),0,0))lc7_console_cec058->scroll_8758d0(true);lc7_log_cec0b4->end_7b4f10();}while(false);
   }
  }
  bool damage=target.get_9b6570()->level_5d15a0(0)<=80;
  if(rng.chance(15))damage=rng.chance(50)?true:false;
  bool status=self.get_9b6570()->record_9b4350()->model==47;
  if(status?(lc7_map_cefc4c->getDisabledGarrisonAccesses()?lc7_overmind_cf6428.reinforce_686c60(point,!damage?3:rng.rangeInt(4.0f,5.0f),damage?14:23,122):lc7_overmind_cf6428.reinforce_686c60(point,!damage?3:rng.rangeInt(4.0f,5.0f),97,damage?45:46)):lc7_overmind_cf6428.reinforce_686c60(point,!damage?2:rng.rangeInt(2.0f,3.0f)+(rng.chance(lc7_global_d1e888.get_9b7910()->getDepthIndex()*6)?1:0),damage?14:23,122)) {
   do {if(lc7_show0_5111e0(573,0,0,0,self,LC7HP(),0,0))lc7_console_cec058->scroll_8758d0(true);lc7_log_cec0b4->end_7b4f10();}while(false);
   std::string text="ALERT: Suspicious intruders detected, dispatching ";
   bool flag=false;
   if(status&&!lc7_map_cefc4c->getDisabledGarrisonAccesses()) {text+=damage?"Decapitator":"Immortal";if(damage)flag=true;}
   else text+=damage?"Cutter":"Specialist";
   text+=" reinforcements to area.";
   do {
    lc7_flags_cf1080.set_451400(true);
    if(true && !(lc7_mute_d28fb0 && true && true))lc7_sound_4541b0(295,0,0);
    do {if(lc7_show_5111e0(804,text,0,0,LC7H(),LC7HP(),0,0))lc7_console_cec058->scroll_8758d0(true);lc7_log_cec0b4->end_7b4f10();}while(false);
    lc7_log_cec0b4->end_7b4f10();
   }while(false);
   if(target.get_9b6570()->player_5c7600()) {lc7_player_cf45d8.event_77fbc0(72);if(flag)lc7_player_cf45d8.event_77fbc0(73);}
   cooldown=lc7_map_cefc4c->time_4642d0()+lc7_min_9cdb30(120,target.get_9b6570()->level_5d15a0(0));
   LC7Response *r=lc7_overmind_cf6428.lastParty();
   if(r){r->deadline=lc7_map_cefc4c->turn_464270()+150;if(!status)lc7_map_cefc4c->notify_728970(self,r->id);}
   lc7_overmind_cf6428.ready_68d920(true);
  }
 }
}
