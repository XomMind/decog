// NOTE: private placeholder types and offsets for 0x699a00.
#include <string>
struct LB1RHandle;
struct LB1RAI {
 char pad[0x130];
 LB1RAI(LB1RHandle,int,int);
 int type_9b8f00() throw();
 void *relation_459570(LB1RHandle) throw();
 void reset_459360() throw();
 void chase_5b4710(LB1RHandle,int,int,int,int) throw();
 void mode_44bef0(int) throw();
};
struct LB1REntity { LB1RAI *ai_45b590() throw(); void setAI_64ecf0(LB1RAI *) throw(); };
struct LB1RHandle {
 int id;
 LB1REntity *get_9b6570() const throw();
 bool operator==(LB1RHandle) const throw();
};
struct LB1RMap { LB1RHandle player_4630f0() throw(); };
extern LB1RMap *lb1r_map_cefc4c;
extern int lb1r_active_cf68b4;
extern LB1RHandle lb1r_watched_cf68b8;
struct LB1RSay { void say_672f20(LB1RHandle,int,int,std::string) throw(); };
extern LB1RSay *lb1r_say_cf68f0;
struct LB1RData { char pad00[0x110]; int type; };
struct LB1RUnit {
 char pad00[0x2c];
 LB1RData *data;
 LB1RHandle entity;
 void resetAI_699a00(bool);
};
void LB1RUnit::resetAI_699a00(bool flag) {
 if(entity.get_9b6570()->ai_45b590()->type_9b8f00()==23) return;
 bool allowed=true;
 if(data->type==7 && !entity.get_9b6570()->ai_45b590()->relation_459570(lb1r_map_cefc4c->player_4630f0())) allowed=false;
 entity.get_9b6570()->setAI_64ecf0(new LB1RAI(entity,23,14));
 entity.get_9b6570()->ai_45b590()->reset_459360();
 if(allowed) entity.get_9b6570()->ai_45b590()->chase_5b4710(lb1r_map_cefc4c->player_4630f0(),-2,1,0,0);
 switch(data->type) {
 case 0:case 2:case 5:case 8:
  entity.get_9b6570()->ai_45b590()->mode_44bef0(4);
  break;
 }
 if(flag && lb1r_active_cf68b4 && entity.get_9b6570() && lb1r_watched_cf68b8==entity)
  lb1r_say_cf68f0->say_672f20(entity,3,0,std::string(""));
 do {} while(false);
}
