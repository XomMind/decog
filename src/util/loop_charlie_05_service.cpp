// NOTE: private aliases and partial layouts for EntityAI service action0x5bac50.
#include <string>
struct LC5Item;
struct LC5Entity;
struct LC5H {int id;LC5H();LC5Entity *get_9b6570() const;void reset_9b7270();};
struct LC5HI {int id;LC5HI();LC5Item *get_9b65b0();};
struct LC5HP {int id;LC5HP();};
struct LC5AIState {char p00[0x10];int pointX;char p14[0x56-0x14];bool flag;};
struct LC5Item {
 void activate_4583b0(int);int category_4578c0();std::string name_571db0(int,int);
 int type_457820();void attach_57a190(LC5H,int,int,int);int nameID_9fcd80();
 int max_457c80();int integrity_9b6bf0();void repair_458360(int);
};
struct LC5Entity {
 bool player_5c7600();int capacity_5ca260();int matter_490840();void recharge_5de870(int,int);
 bool near_45aaa0(LC5H);int attached_5cc190(int);LC5HI take_5cc460(int,int);int locate_5dc440(LC5HI);LC5AIState *ai_45b590();
};
struct LC5Map {LC5H player_4630f0();bool visible_4631f0(LC5H);};extern LC5Map *lc5_map_cefc4c;
struct LC5Part {void update_4a9120();void status_4a8e70(int);};
struct LC5Parts {LC5Part *part_894e70(LC5HI);void update_8993e0(LC5Part*,int);void rebuild_896820(LC5HI);};extern LC5Parts *lc5_parts_cec088;
struct LC5Player {void detach_77ffb0(int,int);};extern LC5Player lc5_player_cf45d8;
struct LC5GM {void attach_778560(int,int,int);};extern LC5GM lc5_gm_d25628;
struct LC5Ints {void push_9b9280(int&&);};extern LC5Ints lc5_attached_cf47cc;
struct LC5Stats {bool add_4729d0(unsigned,int,std::string,int);};extern LC5Stats lc5_stats_d2c658;
extern const char lc5_empty_b93f16[];
extern const float lc5_capacity_bba1dc,lc5_integrity_bba054;
int lc5_min_9cdb30(int,int);
struct LC5Console {void scroll_8758d0(bool);};extern LC5Console *lc5_console_cec058;
struct LC5Log {void end_7b4f10();};extern LC5Log *lc5_log_cec0b4;
bool lc5_message_5111e0(int,const std::string&,int,int,LC5H,LC5HP,int,int);
bool lc5_message0_5111e0(int,int,int,int,LC5H,LC5HP,int,int);
struct LC5Hs {};
extern LC5Hs lc5_pending_cf25b8,lc5_others_d37984;
int lc5_find_9d3110(LC5Hs&,LC5H);void lc5_erase_9da940(LC5Hs&,int);
struct LC5AI {
 LC5H self;char p04[0xb4-4];LC5HP target;char pb8[0xcc-0xb8];int counter,budget;
 int find_5ba870(LC5HP,LC5HI*,int*);int service_5bac50();
};
int LC5AI::service_5bac50() {
 LC5HI item;
 int slot=4;
 int action=find_5ba870(target,&item,&slot);
 int cost=100;
 int damage;
 switch(action) {
 break;
 case 1:{
  int amount=lc5_min_9cdb30(budget,(int)(reinterpret_cast<LC5H &>(target).get_9b6570()->capacity_5ca260()*lc5_capacity_bba1dc)-reinterpret_cast<LC5H &>(target).get_9b6570()->matter_490840());
  if(amount>0) {
   reinterpret_cast<LC5H &>(target).get_9b6570()->recharge_5de870(amount,0);
   budget-=amount;
   do {if(lc5_message0_5111e0(615,0,0,0,self,target,0,0))lc5_console_cec058->scroll_8758d0(true);lc5_log_cec0b4->end_7b4f10();}while(false);
   if(budget==0 && lc5_map_cefc4c->visible_4631f0(self) && self.get_9b6570()->near_45aaa0(lc5_map_cefc4c->player_4630f0())) {
    budget=-1;
    do {if(lc5_message0_5111e0(619,0,0,0,self,LC5HP(),0,0))lc5_console_cec058->scroll_8758d0(true);lc5_log_cec0b4->end_7b4f10();}while(false);
   }
  }
  cost*=2;break;
 }
 case 2:{
  item.get_9b65b0()->activate_4583b0(0);
  LC5Part *p=lc5_parts_cec088->part_894e70(item);
  if(p) {lc5_parts_cec088->update_8993e0(p,0);p->update_4a9120();if(item.get_9b65b0()->category_4578c0()>1)lc5_parts_cec088->rebuild_896820(item);}
  do {if(lc5_message_5111e0(618,item.get_9b65b0()->name_571db0(0,0),0,0,self,LC5HP(),0,0))lc5_console_cec058->scroll_8758d0(true);lc5_log_cec0b4->end_7b4f10();}while(false);
  cost*=2;break;
 }
 case 3:{
  LC5HI h=self.get_9b6570()->take_5cc460(slot,reinterpret_cast<LC5H &>(target).get_9b6570()->attached_5cc190(slot));
  if(reinterpret_cast<LC5H &>(target).get_9b6570()->player_5c7600())lc5_player_cf45d8.detach_77ffb0(h.get_9b65b0()->type_457820(),0);
  h.get_9b65b0()->attach_57a190(reinterpret_cast<LC5H &>(target),slot,1,0);
  if(counter!=-1)counter=1;
  if(reinterpret_cast<LC5H &>(target).get_9b6570()->player_5c7600()) {
   lc5_attached_cf47cc.push_9b9280(h.get_9b65b0()->nameID_9fcd80());
   lc5_gm_d25628.attach_778560(h.get_9b65b0()->type_457820(),1,0);
   if(!reinterpret_cast<LC5H &>(target).get_9b6570()->locate_5dc440(h)) {LC5Part *p=lc5_parts_cec088->part_894e70(h);if(p)lc5_parts_cec088->update_8993e0(p,0);}
  }else if(slot==3 && reinterpret_cast<LC5H &>(target).get_9b6570()->ai_45b590()->flag) {
   reinterpret_cast<LC5H &>(target).get_9b6570()->ai_45b590()->flag=false;
   reinterpret_cast<LC5H &>(target).get_9b6570()->ai_45b590()->pointX=-1;
  }
  do {if(lc5_message_5111e0(613,h.get_9b65b0()->name_571db0(0,0),0,0,self,target,0,0))lc5_console_cec058->scroll_8758d0(true);lc5_log_cec0b4->end_7b4f10();}while(false);
  cost*=2;break;
 }
 case 4:{
  damage=lc5_min_9cdb30(budget,(int)(item.get_9b65b0()->max_457c80()*lc5_integrity_bba054)-item.get_9b65b0()->integrity_9b6bf0());
  if(damage>0) {
   int amount=lc5_min_9cdb30(damage,item.get_9b65b0()->max_457c80()-item.get_9b65b0()->integrity_9b6bf0());
   item.get_9b65b0()->repair_458360(amount);budget-=amount;
   if(reinterpret_cast<LC5H &>(target).get_9b6570()->player_5c7600()) {
    LC5Part *p=lc5_parts_cec088->part_894e70(item);if(p)p->status_4a8e70(0);
    lc5_stats_d2c658.add_4729d0(376,amount,std::string(lc5_empty_b93f16),-1);
    do {if(lc5_message_5111e0(616,item.get_9b65b0()->name_571db0(0,0),0,0,self,LC5HP(),0,0))lc5_console_cec058->scroll_8758d0(true);lc5_log_cec0b4->end_7b4f10();}while(false);
   }else {
    do {if(lc5_message_5111e0(617,item.get_9b65b0()->name_571db0(0,0),0,0,self,target,0,0))lc5_console_cec058->scroll_8758d0(true);lc5_log_cec0b4->end_7b4f10();}while(false);
   }
   if(budget==0 && lc5_map_cefc4c->visible_4631f0(self) && self.get_9b6570()->near_45aaa0(lc5_map_cefc4c->player_4630f0())) {
    budget=-1;
    do {if(lc5_message0_5111e0(619,0,0,0,self,LC5HP(),0,0))lc5_console_cec058->scroll_8758d0(true);lc5_log_cec0b4->end_7b4f10();}while(false);
   }
  }
  cost*=2;break;
 }
 }
 if(!find_5ba870(target,0,0)) {
  int i=lc5_find_9d3110(lc5_pending_cf25b8,reinterpret_cast<LC5H &>(target));
  if(i!=-1){lc5_erase_9da940(lc5_pending_cf25b8,i);lc5_erase_9da940(lc5_others_d37984,i);}
  reinterpret_cast<LC5H &>(target).reset_9b7270();
 }
 return cost;
}
