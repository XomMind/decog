// NOTE: private aliases and partial layouts for 0x5111e0 message routing.
struct LB3MsgText;
struct LB3MsgPoint { int x,y; };
struct LB3MsgEntity { int id; LB3MsgEntity(); bool operator!=(LB3MsgEntity) const; };
struct LB3MsgProp { int id; LB3MsgProp(); };
struct LB3MsgMap {
 LB3MsgEntity player_4630f0();
 bool visibleEntity_4631f0(LB3MsgEntity);
 bool visiblePoint_4631c0(const LB3MsgPoint &);
};
extern LB3MsgMap *lb3msg_map_cefc4c;
struct LB3MsgData { char pad00[0x20]; int visibility; char pad24[0x47-0x24]; bool announce; };
struct LB3MsgTypes { LB3MsgData *&at_9b81f0(unsigned); };
extern LB3MsgTypes lb3msg_types_d2b4d8;
extern int lb3msg_count_d28d18,lb3msg_current_cfe5e4,lb3msg_none_cea000,lb3msg_stamp_cefb78;
struct LB3Msg {
 LB3Msg(int,LB3MsgText *,LB3MsgText *,int,LB3MsgEntity,LB3MsgProp);
 char bytes[0x28];
};
struct LB3MsgLog { int push_5121f0(LB3Msg *); };
extern LB3MsgLog lb3msg_buffer_d2f75c,lb3msg_log_cf1080;
bool lb3msg_route_5111e0(int type,LB3MsgText *a,LB3MsgText *b,int c,LB3MsgEntity entity,LB3MsgProp prop,const LB3MsgPoint *point,bool buffered) {
 switch(lb3msg_types_d2b4d8.at_9b81f0(type)->visibility) {
 break;
 case 1:
  if(entity!=lb3msg_map_cefc4c->player_4630f0()) { return false; } else break;
 case 2:
  if(!lb3msg_map_cefc4c->visibleEntity_4631f0(entity)) { return false; } else break;
 case 3:
  if(!lb3msg_map_cefc4c->visiblePoint_4631c0(*point)) return false;
 }
 if(buffered) {
  if(lb3msg_count_d28d18>=0 && lb3msg_types_d2b4d8.at_9b81f0(type)->announce && lb3msg_current_cfe5e4 && lb3msg_current_cfe5e4!=lb3msg_none_cea000) {
   lb3msg_current_cfe5e4=lb3msg_stamp_cefb78;
   lb3msg_buffer_d2f75c.push_5121f0(new LB3Msg(738,0,0,0,LB3MsgEntity(),LB3MsgProp()));
  }
  lb3msg_buffer_d2f75c.push_5121f0(new LB3Msg(type,a,b,c,entity,prop));
 } else {
  lb3msg_log_cf1080.push_5121f0(new LB3Msg(type,a,b,c,entity,prop));
 }
 return true;
}
