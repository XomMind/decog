// NOTE: private aliases and partial layouts for 0x6716f0 group membership removal.
struct LB3GPoint { int x,y; };
struct LB3GE;
struct LB3GH { int id; LB3GH(); LB3GE *get_9b6570() const throw(); };
struct LB3GE {
 int target_45a760() throw();
 const LB3GPoint &position_45a4a0() throw();
 void *effect_45ac40(int) throw();
 int faction_45a2c0() throw();
};
struct LB3GVec {
 int a,b,c,d;
 unsigned size_9b9260() const throw();
 LB3GH &at_9b81f0(unsigned) throw();
};
struct LB3GMarker { void init_6c20b0(int,const LB3GPoint &,int) throw(); };
struct LB3GMH { int id; LB3GMH(); LB3GMarker *get_9b7cd0() const throw(); };
struct LB3GMarkers {
 void push_9b7cf0(LB3GMH &&) throw();
 const LB3GMH &back_9b6540() const throw();
};
struct LB3GMarkerLists { LB3GMarkers &at_9b8070(unsigned) throw(); };
struct LB3GMap {
 void removeMarker_72e790(int) throw();
 bool trackedA_463510(LB3GH) throw();
 int indexA_463540(LB3GH) throw();
 bool trackedB_4635c0(LB3GH) throw();
 int indexB_4635f0(LB3GH) throw();
 void *group_4638e0(int,int) throw();
 void detach_464800(LB3GH) throw();
 void changed_734560(LB3GH,int,int) throw();
 bool visible_4631c0(const LB3GPoint &) throw();
 LB3GMarkerLists &markers_463ec0() throw();
};
extern LB3GMap *lb3g_map_cefc4c;
int lb3g_index_9d3110(LB3GVec &,LB3GH) throw();
void lb3g_erase_9da940(LB3GVec &,int) throw();
struct LB3GFactory { LB3GMH create_793190() throw(); };
extern LB3GFactory *lb3g_factory_cefaa8;
struct LB3GMission { void changed_987de0() throw(); };
extern LB3GMission *lb3g_mission_cec034;
struct LB3GOvermind { bool remove_683380(LB3GH,int *) throw(); };
extern LB3GOvermind lb3g_overmind_cf6428;
struct LB3GroupRemove {
 int unknown0,group,role;
 LB3GVec members;
 int unknown1c,unknown20,unknown24;
 bool special;
 void remove_6716f0(LB3GH);
};
void LB3GroupRemove::remove_6716f0(LB3GH entity) {
 int index=lb3g_index_9d3110(members,entity);
 if(role==0) lb3g_map_cefc4c->removeMarker_72e790(index);
 else if(lb3g_map_cefc4c->trackedA_463510(entity)) lb3g_map_cefc4c->removeMarker_72e790(lb3g_map_cefc4c->indexA_463540(entity));
 else if(lb3g_map_cefc4c->trackedB_4635c0(entity)) lb3g_map_cefc4c->removeMarker_72e790(lb3g_map_cefc4c->indexB_4635f0(entity));
 if(!lb3g_map_cefc4c->group_4638e0(group,0)) lb3g_map_cefc4c->detach_464800(entity);
 lb3g_erase_9da940(members,index);
 lb3g_map_cefc4c->changed_734560(entity,0,0);
 switch(role) {
 case 3: lb3g_overmind_cf6428.remove_683380(entity,0); break;
 case 0:
  if(!entity.get_9b6570()->target_45a760() && !lb3g_map_cefc4c->visible_4631c0(entity.get_9b6570()->position_45a4a0())) {
   int type=entity.get_9b6570()->effect_45ac40(57) ? 13 : 12;
   LB3GMarkers &markers=lb3g_map_cefc4c->markers_463ec0().at_9b8070(type);
   markers.push_9b7cf0(lb3g_factory_cefaa8->create_793190());
   markers.back_9b6540().get_9b7cd0()->init_6c20b0(type,entity.get_9b6570()->position_45a4a0(),-1);
   lb3g_mission_cec034->changed_987de0();
  }
  break;
 }
 if(entity.get_9b6570()->faction_45a2c0()==20) {
  special=false;
  for(unsigned i=0;i<members.size_9b9260();i++) {
   if(members.at_9b81f0(i).get_9b6570()->faction_45a2c0()==20) { special=true; break; }
  }
 }
}
