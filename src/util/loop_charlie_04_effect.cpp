// NOTE: private placeholder names and partial layouts for the 0x601700 effect dispatcher.
#include <string>
#include <vector>
struct LC4Item;
struct LC4HI { unsigned id; LC4HI(); LC4Item *get_9b65b0(); };
struct LC4HP { int id; LC4HP(); };
struct LC4HE { int id; };
struct LC4Template { char p[0x94]; int type; };
struct LC4Item {
 bool excluded_457ad0(); int category_457880(); int special_577fb0(); int effect_457b70(int);
 LC4Template *template_9b4350();
 std::string name_571db0(int,int);
 void broken_5795b0(int,bool); void destroy_57dbe0(int,int,int,int);
 int integrity_9b6bf0();
 void damage_57ab10(int,int,int,int,LC4HP,int,int);
};
struct LC4Weights {
 std::vector<int> a,b; int total;
 LC4Weights(const int *,int); ~LC4Weights(); int &pick_9ba470();
};
extern const int lc4_weights_b9658c[];
#include "../../src/util/rng.h"
extern RNG rng;
void lc4_sound_4541b0(int,int,int);
int lc4_max_9cdb60(int,int),lc4_min_9cdb30(int,int);
std::string lc4_int_4051f0(int);
struct LC4Stats { bool add_4729d0(unsigned,int,std::string,int); }; extern LC4Stats lc4_stats_d2c658;
extern const char lc4_empty_b94bd7[],lc4_empty_b94bdd[],lc4_empty_b94bde[],lc4_empty_b94bdf[],lc4_empty_b94be7[],lc4_empty_b94bf1[],lc4_empty_b94bf2[],lc4_empty_b94bf3[];
struct LC4Console { void scroll_8758d0(bool); }; extern LC4Console *lc4_console_cec058;
struct LC4Log { void end_7b4f10(); }; extern LC4Log *lc4_log_cec0b4;
bool lc4_show_5111e0(int,const std::string &,const std::string *,int,LC4HE,LC4HP,int,int);
bool lc4_show2_5111e0(int,const std::string &,const std::string &,int,LC4HE,LC4HP,int,int);
bool lc4_show0_5111e0(int,int,int,int,LC4HE,LC4HP,int,int);
void lc4_erase_9da940(std::vector<LC4HI>&,int);
LC4HI lc4_random_9dafb0(std::vector<LC4HI>&);
void lc4_shuffle_9d9fc0(std::vector<LC4HI>&);
struct LC4Xom { bool active; bool item_69eba0(LC4HI); void react_69e700(int,int,float); }; extern LC4Xom lc4_xom_d25450;
struct LC4Entity {
 int unk0; LC4HE self; char p08[0x90-8]; int energy;
 bool player_5c7600(); void drain_45b1b0(int); void heat_45b210(int);
 unsigned inventory_5cb930(std::vector<LC4HI>*); unsigned attached_5cb8b0(std::vector<LC4HI>*);
 void effect_601700(LC4HI);
};
void LC4Entity::effect_601700(LC4HI source) {
 bool flag=player_5c7600();
 if(flag) lc4_sound_4541b0(97,0,0);
 LC4Weights table(lc4_weights_b9658c,4);
 switch(table.pick_9ba470()) {
 case 0: {
  if(energy==0) break;
  int amount=lc4_max_9cdb60(1,rng.rangeInt(25.0f,50.0f)*energy/100);
  drain_45b1b0(amount);
  do { if(lc4_show_5111e0(373,lc4_int_4051f0(amount),0,0,self,LC4HP(),0,0)) lc4_console_cec058->scroll_8758d0(true); lc4_log_cec0b4->end_7b4f10(); } while(false);
  if(flag) { lc4_stats_d2c658.add_4729d0(467,1,std::string(lc4_empty_b94bd7),-1); lc4_stats_d2c658.add_4729d0(468,1,std::string(lc4_empty_b94bdd),-1); }
  break;
 }
 case 1: {
  int amount=rng.rangeInt(100.0f,200.0f);
  heat_45b210(amount);
  do { if(lc4_show_5111e0(374,lc4_int_4051f0(amount),0,0,self,LC4HP(),0,0)) lc4_console_cec058->scroll_8758d0(true); lc4_log_cec0b4->end_7b4f10(); } while(false);
  if(flag) { lc4_stats_d2c658.add_4729d0(467,1,std::string(lc4_empty_b94bde),-1); lc4_stats_d2c658.add_4729d0(469,1,std::string(lc4_empty_b94bdf),-1); }
  break;
 }
 case 2: {
  bool flag2=false;
  std::vector<LC4HI> items;
  if(inventory_5cb930(&items)) {
   for(int i=items.size()-1;i>=0;i--) {
    if(items[i].get_9b65b0()->excluded_457ad0() || items[i].get_9b65b0()->category_457880()>=26 || items[i].get_9b65b0()->special_577fb0() || items[i].get_9b65b0()->effect_457b70(85) || items[i].get_9b65b0()->template_9b4350()->type==2) lc4_erase_9da940(items,i);
   }
   if(!items.empty()) {
    LC4HI item=lc4_random_9dafb0(items);
    do { if(lc4_show_5111e0(318,item.get_9b65b0()->name_571db0(0,0),0,0,self,LC4HP(),0,0)) lc4_console_cec058->scroll_8758d0(true); lc4_log_cec0b4->end_7b4f10(); } while(false);
    item.get_9b65b0()->broken_5795b0(-2,true);
    if(!flag2) {
     do { if(lc4_show0_5111e0(375,0,0,0,self,LC4HP(),0,0)) lc4_console_cec058->scroll_8758d0(true); lc4_log_cec0b4->end_7b4f10(); } while(false);
     flag2=true;
     if(lc4_xom_d25450.active && lc4_xom_d25450.item_69eba0(item)) lc4_xom_d25450.react_69e700(1,0,0.0f);
    }
    if(flag) { lc4_stats_d2c658.add_4729d0(467,1,std::string(lc4_empty_b94be7),-1); lc4_stats_d2c658.add_4729d0(470,1,std::string(lc4_empty_b94bf1),-1); }
   }
  }
  break;
 }
 case 3: {
  do { if(lc4_show_5111e0(376,source.get_9b65b0()->name_571db0(0,0),0,0,self,LC4HP(),0,0)) lc4_console_cec058->scroll_8758d0(true); lc4_log_cec0b4->end_7b4f10(); } while(false);
  source.get_9b65b0()->destroy_57dbe0(flag,1,1,1);
  int count=rng.rangeInt(1.0f,3.0f);
  std::vector<LC4HI> items;
  if(attached_5cb8b0(&items)) {
   lc4_shuffle_9d9fc0(items);
   for(int i=0;i<items.size() && i<count;i++) {
    int integrity=items[i].get_9b65b0()->integrity_9b6bf0();
    if(integrity>1) {
     int amount=lc4_max_9cdb60(1,rng.rangeInt(20.0f,50.0f)*integrity/100);
     do { if(lc4_show2_5111e0(316,items[i].get_9b65b0()->name_571db0(0,0),lc4_int_4051f0(amount),0,self,LC4HP(),0,0)) lc4_console_cec058->scroll_8758d0(true); lc4_log_cec0b4->end_7b4f10(); } while(false);
     items[i].get_9b65b0()->damage_57ab10(lc4_min_9cdb30(items[i].get_9b65b0()->integrity_9b6bf0()-1,amount),1,0,0,LC4HP(),0,0);
     if(flag) { lc4_stats_d2c658.add_4729d0(467,1,std::string(lc4_empty_b94bf2),-1); lc4_stats_d2c658.add_4729d0(471,1,std::string(lc4_empty_b94bf3),-1); }
    }
   }
  }
  break;
 }
 }
}
