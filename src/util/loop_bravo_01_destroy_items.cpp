// NOTE: private placeholder names and partial layouts for 0x63a0d0.
#include <vector>
#include <string>
struct LB1Item;
struct LB1HItem {
 int id;
 bool valid_9b7230() const;
 LB1Item *get_9b65b0();
};
struct LB1HProp { int id; LB1HProp(); };
struct LB1HEntity { int id; };
struct LB1Item {
 std::string name_571db0(int,int);
 void destroy_57dbe0(int,int,int,int);
};
struct LB1Console { void scroll_8758d0(bool); };
struct LB1Log { void end_7b4f10(); };
extern LB1Console *lb1_console_cec058;
extern LB1Log *lb1_log_cec0b4;
bool lb1_show_5111e0(int,const std::string &,int,int,LB1HEntity,LB1HProp,int,int);
void lb1_message_5141b0(int,const std::string &,int,int,LB1HEntity,int);
struct LB1DestroyEntity {
 int unused;
 LB1HEntity self;
 LB1HItem effect_5d2380(int);
 void effects_5d2430(int,std::vector<LB1HItem> &);
 bool player_5c7600();
 void destroyItems_63a0d0();
};
void LB1DestroyEntity::destroyItems_63a0d0() {
 if(effect_5d2380(31).valid_9b7230()) {
  std::vector<LB1HItem> vec;
  effects_5d2430(31,vec);
  for(unsigned i=0;i<vec.size();i++) {
   if(player_5c7600()) {
    do {
     if(lb1_show_5111e0(195,vec[i].get_9b65b0()->name_571db0(0,0),0,0,self,LB1HProp(),0,0)) lb1_console_cec058->scroll_8758d0(true);
     lb1_log_cec0b4->end_7b4f10();
    } while(false);
    do { lb1_message_5141b0(96,vec[i].get_9b65b0()->name_571db0(0,0),0,0,self,0); } while(false);
   }
   vec[i].get_9b65b0()->destroy_57dbe0(1,0,9,1);
  }
 }
}
