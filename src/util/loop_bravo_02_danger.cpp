// NOTE: private aliases and partial layouts for 0x726600; leaf declarations isolate nothrow inference.
struct LB2DPoint { int x,y; };
struct LB2DArea { int x1,y1,x2,y2; LB2DArea() throw(); };
struct LB2DH;
struct LB2DRecord { int value_9b4350() throw(); };
struct LB2DData { char pad00[0x68]; int value; };
struct LB2DEntity {
 bool player_5c7600() throw();
 bool hostile_5c7fc0(LB2DH) throw();
 int target_45a760() throw();
 LB2DRecord *record_45b590() throw();
 int faction_45a2c0() throw();
 bool special_5d5250() throw();
 const LB2DPoint &position_45a4a0() throw();
 LB2DData *data_9b4350() throw();
};
struct LB2DH {
 int id;
 LB2DH() throw();
 bool valid_9b7230() const throw();
 LB2DEntity *get_9b6570() const throw();
};
struct LB2DVec { int a,b,c,d; LB2DVec() throw(); ~LB2DVec() throw(); };
struct LB2DCell { LB2DH entity_45d250() throw(); };
struct LB2DGrid {
 LB2DCell *&at_9ceda0(int,int) throw();
 void bounds_9b4430(const LB2DPoint &,int,LB2DArea &) throw();
};
extern LB2DGrid lb2d_grid_cfd44c;
struct LB2DMap {
 LB2DH player_4630f0() throw();
 bool reachable_716e60(int,const LB2DPoint &,const LB2DPoint &) throw();
 int danger_726600(const LB2DPoint &);
};
extern LB2DMap *lb2d_map_cefc4c;
bool lb2d_contains_9d7160(LB2DVec &,LB2DH) throw();
int lb2d_distance_406480(int,int,int,int) throw();
int LB2DMap::danger_726600(const LB2DPoint &p) {
 const int range=16;
 int danger=0;
 LB2DVec done;
 LB2DH entity;
 LB2DArea area;
 lb2d_grid_cfd44c.bounds_9b4430(p,range,area);
 for(int x=area.x1;x<=area.x2;x++) {
  for(int y=area.y1;y<=area.y2;y++) {
   if(lb2d_grid_cfd44c.at_9ceda0(x,y)->entity_45d250().valid_9b7230()) {
    entity=lb2d_grid_cfd44c.at_9ceda0(x,y)->entity_45d250();
    if(!entity.get_9b6570()->player_5c7600() && entity.get_9b6570()->hostile_5c7fc0(lb2d_map_cefc4c->player_4630f0()) && entity.get_9b6570()->target_45a760()<6 && !lb2d_contains_9d7160(done,entity) &&
     lb2d_distance_406480(p.x,p.y,x,y)<=range && entity.get_9b6570()->record_45b590()->value_9b4350()>=2 && entity.get_9b6570()->faction_45a2c0()!=8 && entity.get_9b6570()->faction_45a2c0()!=19 &&
     (!entity.get_9b6570()->special_5d5250() || entity.get_9b6570()->faction_45a2c0()==6) && reachable_716e60(range,entity.get_9b6570()->position_45a4a0(),p))
      danger+=entity.get_9b6570()->data_9b4350()->value;
   }
  }
 }
 return danger;
}
