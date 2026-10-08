// NOTE: private aliases and partial layouts for SExplosionExpand update 0x515e40.
struct LB6Point {
 int x,y; void init_453b40() throw(); void init_46ca20(int,int) throw();
};
struct LB6CopyPoint:LB6Point { LB6CopyPoint(const LB6Point &) throw(); };
struct LB6Pos:LB6Point { LB6Pos(int,int) throw(); };
struct LB6IntArray { int &at_9cfe20(int,int) throw(); };
struct LB6Record;
struct LB6Callback {
 int source; LB6Record *record; int owner; LB6IntArray *area;
 // No throw specification: LTCG proves this body safe while retaining new-result temporaries.
 LB6Callback(int s,LB6Record *r,int o,LB6IntArray *a):source(s),record(r),owner(o),area(a) {}
};
struct LB6Particle { char pad[0x40]; int color; };
struct LB6Ints { int a,b,c,d; bool empty_9b86e0() const throw(); unsigned size_9b9260() const throw(); int &at_9b81f0(unsigned) throw(); };
struct LB6Record {
 char pad0[0x2c]; int type; char pad30[0x3c-0x30]; int radius;
 char pad40[0x74-0x40]; bool flag74; char pad75[0x84-0x75];
 LB6Particle *particle; LB6Ints particles; int sound;
 int field9c; char pada0[0x160-0xa0]; int sound160;
};
struct LB6Prop {
 LB6Record *record_9b8f00() const throw(); const LB6Point &position_4184d0() const throw(); void destroy_45ce50(int,bool) throw();
};
struct LB6HP { int id; LB6Prop *get_9b64f0() const throw(); };
struct LB6Props { int a,b,c,d; unsigned size_9b9260() const throw(); LB6HP &at_9b81f0(unsigned) throw(); bool empty_9b86e0() const throw(); LB6HP &front_9b7060() throw(); };
void lb6_erase_9d6440(LB6Props &,int &) throw();
struct LB6Counter { void finish_658a30() throw(); };
struct LB6HC { int id; LB6Counter *get_9b64d0() const throw(); };
struct LB6Blast { char pad[8]; LB6Point point; char pad10[0x20-0x10]; LB6IntArray area; void start_514ee0() throw(); };
struct LB6Entity { const LB6Point &position_45a4a0() const throw(); };
struct LB6HE { int id; LB6HE() throw(); LB6Entity *get_9b6570() const throw(); };
struct LB6Cell { void blast_66eff0(int,LB6Record *,int,const LB6Point &,int,bool) throw(); };
struct LB6Grid { void bounds_9b7a40(const LB6Point &,int,LB6Point &,LB6Point &) throw(); LB6Cell **at_9ceda0(int,int) throw(); };
extern LB6Grid lb6_grid_cfd44c;
struct LB6Map {
 void update_465a10(LB6IntArray &) throw(); void special_748a00(LB6IntArray &,int) throw();
 bool visible_4631c0(const LB6Point &) const throw(); bool visible_463190(int,int) const throw();
 void flag_4654d0(bool) throw(); void refresh_465a70() throw(); LB6HE player_4630f0() const throw();
 void explosion_732e70(int) throw(); void effect_727150(const LB6Point &,int,int,int) throw();
};
extern LB6Map *lb6_map_cefc4c;
struct LB6View { bool active_49ab20() const throw(); };
extern LB6View *lb6_view_cec054;
struct LB6Effect {
 void init_503b20(void *,int,const LB6Point &,const LB6Point &,const LB6Point *,const LB6Point *,void *,int,int) throw();
};
struct LB6Effects { LB6Effect *create_508610() throw(); bool busy_454990() const throw(); };
extern LB6Effects *lb6_effects_cefc50;
struct LB6Global { int a,value; };
struct LB6HG { LB6Global *get_9b7910() const throw(); };
extern LB6HG lb6_global_d1e888;
struct LB6Shake { void shake_4b38f0(int,int) throw(); };
extern LB6Shake lb6_shake_d2f1c8;
extern int lb6_delta_cefa78,lb6_color_d1f32c;
int lb6_sound_4ff170(const LB6Point &,int,int,bool) throw();
void lb6_sound_454160(const LB6Point &,int,int) throw();
int lb6_distance_40a3f0(const LB6Point &,const LB6Point &) throw();
void lb6_clamp_9cdc50(int,int &,int) throw();
struct LB6Expand {
 int vptr,unknown4,state,time,owner,source;
 LB6Record *record; int damage; LB6Point center; LB6Blast *blast; LB6HC counter; LB6Props props;
 bool update_515e40();
};
bool LB6Expand::update_515e40() {
 bool first; LB6Point count,a,base; LB6IntArray *i;
 if(state==0)state=3;
 time+=lb6_delta_cefa78;
 switch(state) {
 case 3:
  blast->start_514ee0();
  if(lb6_view_cec054->active_49ab20())lb6_map_cefc4c->update_465a10(blast->area);
  if(lb6_global_d1e888.get_9b7910()->value==35 && record->flag74)lb6_map_cefc4c->special_748a00(blast->area,0);
  state=4;
 case 4:
  {
   i=&blast->area;
   count.init_453b40();a.init_453b40();
   lb6_grid_cfd44c.bounds_9b7a40(center,record->radius,count,a);
   base.init_46ca20(5,5);
   if(lb6_map_cefc4c->visible_4631c0(blast->point))first=false;
   else {
    if(record->sound && lb6_sound_4ff170(blast->point,record->sound,-1,true))first=false;
    else {
     first=true;
     for(int x=count.x;x<=a.x;x++) {
      for(int y=count.y;y<=a.y;y++) {
       if(i->at_9cfe20(x,y) && lb6_map_cefc4c->visible_463190(x,y)) {first=false;goto found;}
      }
     }
    }
   }
found:
   if(first) {
    lb6_map_cefc4c->flag_4654d0(true);
    for(int x=count.x;x<=a.x;x++) {
     for(int y=count.y;y<=a.y;y++) {
      if(i->at_9cfe20(x,y))(*lb6_grid_cfd44c.at_9ceda0(x,y))->blast_66eff0(source,record,owner,center,i->at_9cfe20(x,y),true);
     }
    }
    lb6_map_cefc4c->flag_4654d0(false);
    lb6_map_cefc4c->refresh_465a70();
    state=6;
   } else {
    for(int x=count.x;x<=a.x;x++) {
     for(int y=count.y;y<=a.y;y++) {
      if(i->at_9cfe20(x,y) && (x!=center.x || y!=center.y))
       lb6_effects_cefc50->create_508610()->init_503b20(lb6_effects_cefc50,reinterpret_cast<int>(record->particle),center,base,&LB6Pos(x,y),&base,new LB6Callback(owner,record,source,i),9,0);
     }
    }
    lb6_effects_cefc50->create_508610()->init_503b20(lb6_effects_cefc50,reinterpret_cast<int>(record->particle),center,base,&center,&base,new LB6Callback(owner,record,source,i),9,0);
    if(!record->particles.empty_9b86e0()) {
     for(unsigned j=0;j<record->particles.size_9b9260();j++)
      lb6_effects_cefc50->create_508610()->init_503b20(lb6_effects_cefc50,record->particles.at_9b81f0(j),center,base,0,0,0,9,0);
    }
    if(record->sound)lb6_sound_4ff170(center,record->sound,-1,false);
    if(record->type!=3 && record->type!=9) {
     int first=lb6_distance_40a3f0(center,lb6_map_cefc4c->player_4630f0().get_9b6570()->position_45a4a0());
     if(first<=20) {
      int count=damage;
      lb6_clamp_9cdc50(30,count,100);
      int a=(20-first)/4*count;
      lb6_shake_d2f1c8.shake_4b38f0(a,record->particle->color);
     }
    }
    state=5;
   }
  }
  for(int i=0;i<props.size_9b9260();i++) {
   if(!props.at_9b81f0(i).get_9b64f0())lb6_erase_9d6440(props,i);
  }
  if(!props.empty_9b86e0()) {
   int count;
   for(int i=0;i<1;i++) {
    if(props.front_9b7060().get_9b64f0()->record_9b8f00()->sound160)lb6_sound_454160(center,props.front_9b7060().get_9b64f0()->record_9b8f00()->sound160,17);
   }
   count=props.front_9b7060().get_9b64f0()->record_9b8f00()->particles.c;
   for(unsigned i=0;i<props.size_9b9260();i++) {
    LB6CopyPoint p(props.at_9b81f0(i).get_9b64f0()->position_4184d0());
    props.at_9b81f0(i).get_9b64f0()->destroy_45ce50(source,first);
    if(first)lb6_map_cefc4c->effect_727150(p,5,5,lb6_color_d1f32c);
    else if(count)lb6_effects_cefc50->create_508610()->init_503b20(lb6_effects_cefc50,count,p,base,0,0,0,9,0);
   }
  }
 case 5:
  if(lb6_effects_cefc50->busy_454990()) {break;} else state=6;
 case 6:
  lb6_map_cefc4c->explosion_732e70(owner);
  if(counter.get_9b64d0())counter.get_9b64d0()->finish_658a30();
  return true;
 }
 return false;
}
