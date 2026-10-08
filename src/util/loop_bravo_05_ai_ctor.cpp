// NOTE: private aliases and placeholder member layouts for EntityAI constructor 0x57f6a0.
struct LB5Point {
 int x,y; LB5Point(); LB5Point(int); LB5Point(const LB5Point &);
 void assign_46ca50(const LB5Point &); void set_40a010(int,int); void set_409ff0(int);
};
struct LB5Pos : LB5Point { LB5Pos(int); LB5Pos(int,int); };
struct LB5Rect { LB5Point min,max; LB5Rect(); };
struct LB5HP { int id; LB5HP(); void reset_9b7270(); };
struct LB5Entity;
struct LB5H { int id; LB5H(); LB5Entity *get_9b6570() const; };
struct LB5Text;
struct LB5Record {
 int unknown0; char name[28]; int unknown20,subtype,type;
 char pad2c[0x48-0x2c]; int model;
 char pad4c[0x7c-0x4c]; int field7c;
 char pad80[0x15c-0x80]; bool special;
};
struct LB5Cached { char pad[0x68]; int value; };
struct LB5Entity {
 int unknown0,unknown4; LB5Record *record;
 bool special_5c7f70(); bool flag_5d1280();
 LB5Cached *cached_9b4350(); const LB5Point &position_45a4a0();
 bool flag_5cabd0(); bool flag_5cac90(); int count_5cad50();
 const LB5Text &name_45a280();
};
struct LB5Vec {
 int proxy,first,last,end; LB5Vec(); ~LB5Vec();
 void push_9b32e0(const LB5Point &); void assign_9b3430(unsigned,const LB5Point &);
 LB5Point &at_9e7c10(unsigned);
};
struct LB5Points { char pad[0x1c]; LB5Points(int,int,LB5H,const LB5Point &); };
struct LB5Map { LB5H player_4630f0(); int point_74b2c0(const LB5Point &); int turn_464270(); };
extern LB5Map *lb5_map_cefc4c;
struct LB5Grid { int width_9fcd80(); int height_9b8f00(); void rect_9b4430(const LB5Point &,int,LB5Rect &); };
extern LB5Grid lb5_grid_cfd44c;
struct LB5GlobalRecord { int unknown0,value; };
struct LB5GlobalHandle { LB5GlobalRecord *get_9b7910(); };
extern LB5GlobalHandle lb5_record_d1e888;
#include "../../src/util/rng.h"
extern RNG rng;
extern const float lb5_low_c36f20,lb5_high_c36f24;
int lb5_clamp_9cdc80(int,int,int);
bool lb5_equal_9ccb50(const LB5Text &,const char *);
extern const char lb5_swarm_be2a28[],lb5_swarm_be2a34[],lb5_freighter_be2a40[],lb5_sauler_be2a50[],lb5_tracker_be2a58[];
extern const int lb5_type_bb9ed0[],lb5_mode_bba058[],lb5_48_bba680[],lb5_4c_bba1e0[],lb5_radius_bba370[];
struct LB5AI {
 LB5H entity; int type,mode,field0c;
 LB5Point point10,point18; LB5HP h20; LB5Vec v24;
 int field34,field38,field3c; LB5HP h40; int field44,field48,field4c; LB5HP h50;
 bool flag54,flag55,flag56; LB5HP h58; bool flag5c;
 int field60,field64,field68; LB5Vec points; bool flag7c;
 LB5Rect area; LB5Vec v90; int fielda0; LB5Rect otherArea;
 LB5HP hb4,hb8; int fieldbc,fieldc0,fieldc4,fieldc8,fieldcc,fieldd0; LB5HP hd4; int fieldd8;
 LB5Vec vdc; int fieldec; LB5Vec vf0;
 int field100,field104,field108,field10c; bool flag110; LB5Points *field114;
 int field118,field11c; LB5Vec v120;
 LB5AI(LB5H,int,int); void finish_5b2d10();
};
LB5AI::LB5AI(LB5H e,int a,int b)
 :entity(e),type(entity.get_9b6570()->special_5c7f70()?3:(a==34?lb5_type_bb9ed0[entity.get_9b6570()->record->type]:a)),
 mode(b==14?lb5_mode_bba058[entity.get_9b6570()->record->type]:b),field0c(0),
 field34(0),field38(0),field3c(0),field44(0),field48(lb5_48_bba680[entity.get_9b6570()->record->type]),field4c(lb5_4c_bba1e0[entity.get_9b6570()->record->type]),
 flag54(false),flag55(false),flag56(false),field64(0),fieldbc(0),fieldc0(2),fieldc4(0),fieldc8(0),fieldcc(0),
 fieldd0(entity.get_9b6570()->cached_9b4350()->value*300+500),fieldd8(entity.get_9b6570()->record->field7c),
 fieldec(0),field100(0),field104(0),field108(0),field10c(0),flag110(false),
 field114(entity.get_9b6570()->special_5c7f70()?new LB5Points(entity.get_9b6570()->flag_5d1280()?0:2,1,lb5_map_cefc4c->player_4630f0(),LB5Pos(-1)):0),field118(0),field11c(0) {
 point10.x=-1;point18.x=-1;h20.reset_9b7270();h58.reset_9b7270();
 flag5c=false;field60=0;field68=0;flag7c=false;
 switch(type) {
 case 1: points.push_9b32e0(entity.get_9b6570()->position_45a4a0());break;
 break;
 case 5: fieldcc=-1;break;
 case 14:
  if(lb5_record_d1e888.get_9b7910()->value==0) {type=0;break;}
  points.assign_9b3430(6,LB5Pos(-1));
  {
   LB5Point p(entity.get_9b6570()->position_45a4a0());
   points.at_9e7c10(1).assign_46ca50(LB5Pos(lb5_clamp_9cdc80(0,p.x-10,lb5_grid_cfd44c.width_9fcd80()-20),lb5_clamp_9cdc80(0,p.y-10,lb5_grid_cfd44c.height_9b8f00()-20)));
   points.at_9e7c10(0).assign_46ca50(lb5_map_cefc4c->point_74b2c0(points.at_9e7c10(1)));
   points.at_9e7c10(4).assign_46ca50(rng.chance(25)?-1:rng.rangeInt(lb5_low_c36f20,lb5_high_c36f24));
   points.at_9e7c10(5).set_409ff0(0);
  }
  break;
 }
 if(entity.get_9b6570()->record->type==28 && entity.get_9b6570()->record->subtype!=2 && entity.get_9b6570()->flag_5cabd0()) {
  if(entity.get_9b6570()->count_5cad50())fieldcc=lb5_map_cefc4c->turn_464270()+1;
  else if(type==1)fieldcc=1;
 }
 if(entity.get_9b6570()->record->model==44 && entity.get_9b6570()->flag_5cac90()) {
  if(entity.get_9b6570()->count_5cad50())fieldcc=lb5_map_cefc4c->turn_464270()+1;
  else fieldcc=1;
 }
 if(entity.get_9b6570()->special_5c7f70()) {
  switch(mode) {
  case 5: mode=1;break;
  case 3:mode=entity.get_9b6570()->record->special ? (lb5_equal_9ccb50(*reinterpret_cast<LB5Text *>(entity.get_9b6570()->record->name),lb5_swarm_be2a28)?9:8):1;break;
  case 7:mode=8;break;
  }
 } else if(mode==3) {
  if(lb5_equal_9ccb50(*reinterpret_cast<LB5Text *>(entity.get_9b6570()->record->name),lb5_swarm_be2a34))mode=9;
  else if(entity.get_9b6570()->record->special)mode=8;
 } else if(mode==1) {
  if(lb5_equal_9ccb50(*reinterpret_cast<LB5Text *>(entity.get_9b6570()->record->name),lb5_freighter_be2a40) || lb5_equal_9ccb50(*reinterpret_cast<LB5Text *>(entity.get_9b6570()->record->name),lb5_sauler_be2a50))mode=2;
 }
 switch(mode) {case 7:field34=1;break;}
 if(lb5_equal_9ccb50(entity.get_9b6570()->name_45a280(),lb5_tracker_be2a58))field34=1;
 if(lb5_radius_bba370[entity.get_9b6570()->record->type]==0) {
  area.min.set_40a010(0,0);area.max.set_40a010(lb5_grid_cfd44c.width_9fcd80()-1,lb5_grid_cfd44c.height_9b8f00()-1);
 } else lb5_grid_cfd44c.rect_9b4430(entity.get_9b6570()->position_45a4a0(),lb5_radius_bba370[entity.get_9b6570()->record->type],area);
 fielda0=0;otherArea.min.x=-1;hb4.reset_9b7270();finish_5b2d10();
}
