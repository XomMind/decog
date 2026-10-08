// Private aliases and observed layout for Item target selection 0x57c3f0.
#include <string>
struct LB11Point {int x,y;LB11Point();LB11Point(int,int) throw();LB11Point(const LB11Point &) throw();void assign_46ca50(const LB11Point &) throw();};
struct LB11Pair {int x,y;};
struct LB11Entity;struct LB11Group;
struct LB11Handle {int id;LB11Handle();LB11Entity *get_9b6570() const throw();bool valid_9b7230() const throw();bool different_9b6510(LB11Handle) const throw();bool null_9b65d0() const throw();};
struct LB11OwnH {int id;void *get_9b65b0() const throw();};
struct LB11GH {int id;LB11Group *get_9b7250() const throw();};
struct LB11Group {int kind_9b4350() const throw();};
template<class T> struct LB11Vector {
 int a,b,c,d;LB11Vector();~LB11Vector();bool empty_9b86e0() const throw();unsigned size_9b9a50() const throw();
 int &intAt_9b81f0(unsigned) throw();const int &back_9b6540() const throw();LB11Point &pointAt_9e7c10(unsigned) throw();
 void pushInt_9b9d30(const int &);void pushMove_9b3020(LB11Point &&);void pushPoint_9b32e0(const LB11Point &);
};
typedef LB11Vector<LB11Point> LB11Vec;
typedef LB11Vector<int> LB11Ints;
typedef LB11Vector<LB11Pair> LB11ChildVec;
void lb11_insertPoint_9d5460(LB11Vec &,unsigned,LB11Point);void lb11_insertInt_9dbdc0(LB11Ints &,int,int);
void lb11_erase_9d7300(LB11Vec &,unsigned &);void lb11_append_9d7f20(LB11Vec &,LB11Vec &);
struct LB11Rect {int left,top,right,bottom;LB11Rect();};
struct LB11Cell {LB11Handle entity_45d250() throw();};
struct LB11Grid {void rect_9b4430(const LB11Point &,int,LB11Rect &) throw();LB11Cell *&at_9ceda0(int,int) throw();LB11Cell *&atPoint_9ced70(LB11Point &) throw();};
extern LB11Grid lb11_grid_cfd44c;
struct LB11Entity {
 int resource_45a8d0() throw();int alternate_45a920() throw();bool player_5c7600() throw();const LB11Point &position_45a4a0() throw();
 bool hostile_45aa70(LB11Handle) throw();int target_45a760() throw();LB11GH group_45a3f0() throw();LB11Handle prop_5d2380(int) throw();
 void *effect_45ac40(int) throw();bool exclude_5c87f0(const LB11Point &) throw();bool xom_5d51a0() throw();LB11Point position_5c80f0(const LB11Point &) throw();
};
struct LB11Record {char pad[0x100];int range;char pad104[0x190-0x104];int data;};
struct LB11Obj {char data[0x7c];LB11Obj(LB11Handle,int,const LB11Point &,const LB11Point &,const LB11Handle &,LB11ChildVec &,int,int);};
struct LB11EffectData {char data[0x64];LB11EffectData(LB11Record *,LB11Handle,int,int,float,LB11Handle,LB11Handle,int,LB11Handle,int,int,int);};
struct LB11Factory {LB11Handle create_7930e0(LB11Obj *);};extern LB11Factory *lb11_factory_cefaa8;
struct LB11Map {bool visible_463190(int,int) throw();bool line_7170a0(LB11Handle,const LB11Point &,LB11Vec &,LB11Ints &,LB11Ints &,LB11Point &,int,int,bool,bool);LB11Handle add_777a20(LB11Handle);};extern LB11Map *lb11_map_cefc4c;
struct LB11Player {bool check_77f260(int) throw();void increment_77fbc0(int) throw();};extern LB11Player lb11_player_cf45d8;
struct LB11Stats {bool add_4729d0(unsigned,int,std::string,int);};extern LB11Stats lb11_stats_d2c658;
struct LB11Controller;
struct LB11Effect {void init_503b20(LB11Controller *,int,const LB11Point &,const LB11Point &,const LB11Point *,const LB11Point *,LB11EffectData *,int,bool);};
struct LB11Controller {LB11Effect *get_508610() throw();};extern LB11Controller *lb11_console_cefc50;
extern const LB11Point lb11_zero_d2e20c;
int lb11_distance_40a3f0(const LB11Point &,const LB11Point &) throw();
struct LB11Item {int field0;LB11OwnH owner;int fields8,fieldc;LB11Handle entity;int resource_5788e0() throw();int alternate_5789c0() throw();int range_4580a0() throw();void *effect_457b70(int) throw();bool select_57c3f0(LB11Point &,const LB11Handle &,LB11Record *,bool);};
bool LB11Item::select_57c3f0(LB11Point &out,const LB11Handle &handle,LB11Record *record,bool filter){
 if(resource_5788e0()<=entity.get_9b6570()->resource_45a8d0() || alternate_5789c0()<=entity.get_9b6570()->alternate_45a920()){
 bool valid=entity.get_9b6570()->player_5c7600();LB11Point active(entity.get_9b6570()->position_45a4a0());int index=record?record->range:range_4580a0();unsigned char map=effect_457b70(98)!=0;
 int other;LB11Vec i;LB11Ints first;LB11Rect a;lb11_grid_cfd44c.rect_9b4430(active,index,a);
 for(int y=a.top;y<=a.bottom;++y){for(int x=a.left;x<=a.right;++x){
  if(lb11_grid_cfd44c.at_9ceda0(x,y)->entity_45d250().valid_9b7230() && lb11_grid_cfd44c.at_9ceda0(x,y)->entity_45d250().different_9b6510(entity) && lb11_grid_cfd44c.at_9ceda0(x,y)->entity_45d250().get_9b6570()->hostile_45aa70(entity) && lb11_grid_cfd44c.at_9ceda0(x,y)->entity_45d250().get_9b6570()->target_45a760()<6 &&
   (entity.get_9b6570()->group_45a3f0().get_9b7250()->kind_9b4350()!=3 ||
    (lb11_grid_cfd44c.at_9ceda0(x,y)->entity_45d250().get_9b6570()->prop_5d2380(31).null_9b65d0() &&
     (!lb11_grid_cfd44c.at_9ceda0(x,y)->entity_45d250().get_9b6570()->player_5c7600() || !lb11_player_cf45d8.check_77f260(100)))) &&
   (!map || !lb11_grid_cfd44c.at_9ceda0(x,y)->entity_45d250().get_9b6570()->effect_45ac40(47)) && (!valid || lb11_map_cefc4c->visible_463190(x,y))){
  other=lb11_distance_40a3f0(active,LB11Point(x,y));if(other<=index){
  if(first.empty_9b86e0() || other>=first.back_9b6540()){i.pushMove_9b3020(LB11Point(x,y));first.pushInt_9b9d30(other);}
  else{for(unsigned j=0;j<i.size_9b9a50();++j){if(other<first.intAt_9b81f0(j)){lb11_insertPoint_9d5460(i,j,LB11Point(x,y));lb11_insertInt_9dbdc0(first,j,other);break;}}}
 }}}}
 if(filter){for(unsigned j=0;j<i.size_9b9a50();++j){if(entity.get_9b6570()->exclude_5c87f0(i.pointAt_9e7c10(j)))lb11_erase_9d7300(i,j);}}
 LB11Vec b;for(unsigned j=0;j<i.size_9b9a50();++j){if(lb11_grid_cfd44c.atPoint_9ced70(i.pointAt_9e7c10(j))->entity_45d250().get_9b6570()->xom_5d51a0()){b.pushPoint_9b32e0(i.pointAt_9e7c10(j));lb11_erase_9d7300(i,j);}}
 if(!i.empty_9b86e0())lb11_append_9d7f20(b,i);
 LB11OwnH value=owner;LB11Handle base=entity;
 for(unsigned j=0;j<b.size_9b9a50();++j){LB11Point count;LB11Vec a;LB11Ints first;LB11Ints i;
  if(lb11_map_cefc4c->line_7170a0(entity,b.pointAt_9e7c10(j),a,first,i,count,0,4,true,true)){
   out.assign_46ca50(b.pointAt_9e7c10(j));
   // Retail retains an uninitialized four-byte local before either allocation branch.
   int pending;
   if(!record){LB11ChildVec p;lb11_map_cefc4c->add_777a20(lb11_factory_cefaa8->create_7930e0(new LB11Obj(entity,1,out,lb11_zero_d2e20c,handle,p,0,owner.id)));}
   else{LB11Point p=entity.get_9b6570()->position_5c80f0(out);lb11_console_cefc50->get_508610()->init_503b20(lb11_console_cefc50,record->data,p,lb11_zero_d2e20c,&out,&count,new LB11EffectData(record,entity,1,record->range,1.0f,LB11Handle(),LB11Handle(),0,LB11Handle(),0,0,0),9,false);}
   if(!value.get_9b65b0() || !base.get_9b6570())return true;
   if(valid){lb11_stats_d2c658.add_4729d0(401,1,std::string(""),-1);lb11_player_cf45d8.increment_77fbc0(60);}return false;
  }
 }
 }
 return true;
}
