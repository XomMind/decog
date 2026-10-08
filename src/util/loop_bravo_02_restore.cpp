// NOTE: private placeholder names and partial layouts for 0x69a9d0.
#include <string>
struct LB2H;
struct LB2Point {
 int x,y;
 LB2Point &operator=(const LB2Point &) throw();
};
struct LB2Stored { ~LB2Stored(); };
struct LB2AI { void chase_5b4710(LB2H,int,int,int,int) throw(); };
struct LB2Entity {
 LB2AI *ai_45b590() throw();
 const std::string &name_416f40() throw();
};
struct LB2H {
 int id;
 LB2H();
 LB2Entity *get_9b6570() const throw();
 bool operator==(LB2H) const throw();
};
struct LB2HP { int id; LB2HP(); };
struct LB2Map {
 LB2H player_4630f0() throw();
 bool visible_4631f0(LB2H) throw();
};
extern LB2Map *lb2_map_cefc4c;
extern int lb2_active_cf68b4;
extern LB2H lb2_watch_cf68b8;
struct LB2Say { void say_672f20(LB2H,int,int,std::string) throw(); };
extern LB2Say *lb2_say_cf68f0;
LB2H lb2_restore_690940(LB2Stored *,const LB2Point &,int,int,int);
void lb2_sound_454260(const LB2Point &,int) throw();
void lb2_message_49c610(int,LB2HP,const std::string &,int);
void lb2_log_5141b0(int,const std::string &,int,int,LB2HP,int);
struct LB2Unit {
 char pad00[0x30];
 LB2H entity;
 LB2Stored *stored;
 char pad38[0x13c-0x38];
 LB2Point position,last;
 int state;
 void restore_69a9d0();
};
void LB2Unit::restore_69a9d0() {
 if(stored==0) { do {} while(false); }
 entity=lb2_restore_690940(stored,position,11,34,14);
 delete stored;
 stored=0;
 entity.get_9b6570()->ai_45b590()->chase_5b4710(lb2_map_cefc4c->player_4630f0(),-2,1,0,0);
 lb2_sound_454260(position,171);
 if(lb2_map_cefc4c->visible_4631f0(entity)) {
  std::string message=entity.get_9b6570()->name_416f40()+" bursts from the wall.";
  lb2_message_49c610(800,LB2HP(),message,0);
  do { lb2_log_5141b0(147,entity.get_9b6570()->name_416f40(),0,0,LB2HP(),0); } while(false);
  if(lb2_active_cf68b4 && entity.get_9b6570() && lb2_watch_cf68b8==entity)
   lb2_say_cf68f0->say_672f20(entity,11,0,std::string(""));
 }
 last=position;
 position.x=-1;
 state=0;
}
