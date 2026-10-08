// NOTE: private aliases for 0x581140; partial object layouts.
struct LB3Point { int x,y; };
struct LB3Group { int type_9b4350() const throw(); };
struct LB3HG { int id; LB3HG(); LB3Group *get_9b7250() const throw(); };
struct LB3HI { int id; LB3HI(); bool valid_9b7230() const throw(); };
struct LB3H;
struct LB3Entity {
 char pad00[0xb8]; bool flag;
 bool hostile_45aa70(LB3H) throw();
 LB3HG group_45a3f0() throw();
 int faction_45a2c0() throw();
 bool relation_5d4230(LB3H) throw();
 bool relation_5d4100() throw();
 int effect_5d22a0(int) throw();
 const LB3Point &position_45a4a0() throw();
 LB3HI item_5d2380(int) throw();
};
struct LB3H { int id; LB3H(); LB3Entity *get_9b6570() const throw(); };
struct LB3Map {
 LB3H player_4630f0() throw();
 bool visible_4631f0(LB3H) throw();
 bool dirty_463660() throw();
 void refresh_72e8e0(bool) throw();
};
extern LB3Map *lb3_map_cefc4c;
struct LB3Flags { int &at_9b81f0(unsigned) throw(); };
extern LB3Flags lb3_flags_cf4a04;
int lb3_distance_40a3f0(const LB3Point &,const LB3Point &) throw();
struct LB3Sensor {
 LB3H self;
 bool detect_581140();
};
bool LB3Sensor::detect_581140() {
 bool result=false;
 if(lb3_map_cefc4c->player_4630f0().get_9b6570()->hostile_45aa70(self) || self.get_9b6570()->group_45a3f0().get_9b7250()->type_9b4350()==4) {
  if(lb3_flags_cf4a04.at_9b81f0(8)) {
   switch(self.get_9b6570()->group_45a3f0().get_9b7250()->type_9b4350()) {
   case 3:
    if(lb3_map_cefc4c->player_4630f0().get_9b6570()->relation_5d4230(self)) { result=true; goto evaluation; }
    break;
   case 4:
    if((self.get_9b6570()->faction_45a2c0()==2 || self.get_9b6570()->faction_45a2c0()==4) && lb3_map_cefc4c->player_4630f0().get_9b6570()->relation_5d4100()) { result=true; goto evaluation; }
    break;
   }
  }
  int range=lb3_map_cefc4c->player_4630f0().get_9b6570()->effect_5d22a0(20);
  if(range && range>=lb3_distance_40a3f0(self.get_9b6570()->position_45a4a0(),lb3_map_cefc4c->player_4630f0().get_9b6570()->position_45a4a0())) {
   if(!self.get_9b6570()->flag || lb3_map_cefc4c->player_4630f0().get_9b6570()->item_5d2380(21).valid_9b7230()) result=true;
  }
 }
evaluation:
 if(result) {
  if(lb3_map_cefc4c->visible_4631f0(self)) return true;
  else if(lb3_map_cefc4c->dirty_463660()) {
   lb3_map_cefc4c->refresh_72e8e0(false);
   return lb3_map_cefc4c->visible_4631f0(self);
  } else return false;
 } else return false;
}
