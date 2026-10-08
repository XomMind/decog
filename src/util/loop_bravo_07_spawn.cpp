// NOTE: private aliases and placeholder layouts for effect placement at 0x5020a0.
#include "../../src/util/rng.h"
extern RNG rng;
struct LB7Point {
 int x,y; LB7Point() throw(); LB7Point(const LB7Point &) throw();
 LB7Point(const LB7Point &,int,int) throw(); LB7Point(const LB7Point &,const LB7Point &) throw();
 void add_40a2a0(int,int) throw(); void assign_46ca50(const LB7Point &) throw();
 void shift_40a060(const LB7Point &,int,int) throw(); void multiply_40a300(int) throw();
 bool same_409b90(const LB7Point &) const throw(); bool different_409bd0(const LB7Point &) const throw();
};
struct LB7Pos:LB7Point { LB7Pos(int) throw(); LB7Pos(int,int) throw(); };
struct LB7Grid { bool contains_9b43b0(const LB7Point &) const throw(); };
extern LB7Grid lb7_grid_cfd44c;
int lb7_distance_40a3f0(const LB7Point &,const LB7Point &) throw();
void lb7_rotate_501fc0(const LB7Point &,const LB7Point &,float,LB7Point &) throw();
extern const float lb7_low_c36f28,lb7_high_c36ec8;
struct LB7Stepper { void delta_410490(LB7Point &) throw(); };
struct LB7Effects;
struct LB7Effect {
 void init_503b20(LB7Effects *,int,const LB7Point &,const LB7Point &,const LB7Point *,const LB7Point *,void *,int,void *) throw();
};
struct LB7Effects { LB7Effect *create_508610() throw(); };
struct LB7Record { int particle; char pad04[0x20-4]; int position,dx,dy,pattern,a,b; bool attached; };
struct LB7Runner {
 int vptr; LB7Effects *pool; char pad08[0x18-8]; LB7Point offset,point20,point28;
 char pad30[0x38-0x30]; char stepper[0x30]; LB7Point point68,point70; int target;
 bool spawn_5020a0(LB7Record *,LB7Point);
};
bool LB7Runner::spawn_5020a0(LB7Record *data,LB7Point point) {
 switch(data->position) {
 break;
 case 1:
  point.add_40a2a0(data->dx,data->dy);
  if(!lb7_grid_cfd44c.contains_9b43b0(point))return false;
  break;
 case 2:
  {
   LB7Point first;
   for(int i=0;i<25;i++) {
    first.shift_40a060(point,rng.rangeInt(-data->dx,data->dx),rng.rangeInt(-data->dy,data->dy));
    if(lb7_grid_cfd44c.contains_9b43b0(first)) {
     if(data->dx<3 || data->dy<3 || data->dx!=data->dy || lb7_distance_40a3f0(point,first)<=data->dx)break;
    }
   }
   if(!lb7_grid_cfd44c.contains_9b43b0(first))return false;
   point.assign_46ca50(first);
  }
  break;
 }
 switch(data->pattern) {
 case 0:
  pool->create_508610()->init_503b20(pool,data->particle,point,offset,0,0,0,data->attached?target:9,this);
  break;
 case 1:
  if(point.different_409bd0(point20))pool->create_508610()->init_503b20(pool,data->particle,point,offset,&point20,&point28,0,data->attached?target:9,this);
  break;
 case 2:
  if(point.different_409bd0(point68))pool->create_508610()->init_503b20(pool,data->particle,point,offset,&point68,&point70,0,data->attached?target:9,this);
  break;
 case 3:
  {
   LB7Point first(point,data->a,data->b);
   if(lb7_grid_cfd44c.contains_9b43b0(first) && point.different_409bd0(first))pool->create_508610()->init_503b20(pool,data->particle,point,offset,&first,&point70,0,data->attached?target:9,this);
  }
  break;
 case 4:
  if(lb7_grid_cfd44c.contains_9b43b0(point) && lb7_grid_cfd44c.contains_9b43b0(point68)) {
   LB7Pos first(-1);
   for(int i=0;i<25 && (!lb7_grid_cfd44c.contains_9b43b0(first) || point.same_409b90(first));i++) {
    first.shift_40a060(point68,rng.rangeInt(-data->a,data->a),rng.rangeInt(-data->b,data->b));
   }
   if(lb7_grid_cfd44c.contains_9b43b0(first))pool->create_508610()->init_503b20(pool,data->particle,point,offset,&first,&point70,0,data->attached?target:9,this);
  }
  break;
 case 5:
 case 6:
  {
   LB7Point first;
   reinterpret_cast<LB7Stepper *>(stepper)->delta_410490(first);
   if(first.x==0 && first.y==0)break;
   first.multiply_40a300(5);
   LB7Point a(point,first);
   LB7Point i;
   int count=data->pattern==5?data->a:rng.rangeInt(-data->a,data->a);
   if(data->pattern==6)count+=data->b;
   if(count<0)count+=360;
   lb7_rotate_501fc0(point,a,(float)count,i);
   pool->create_508610()->init_503b20(pool,data->particle,point,offset,&i,&offset,0,data->attached?target:9,this);
  }
  break;
 case 7:
  pool->create_508610()->init_503b20(pool,data->particle,point,offset,&(rng.chance(50)?LB7Pos(point.x+(rng.chance(50)?-100:100),point.y):LB7Pos(point.x,point.y+(rng.chance(50)?-100:100))),&offset,0,data->attached?target:9,this);
  break;
 case 8:
  {
   LB7Point first;
   do {
    first.x=point.x+rng.rangeInt(lb7_low_c36f28,lb7_high_c36ec8);
    first.y=point.y+rng.rangeInt(lb7_low_c36f28,lb7_high_c36ec8);
   } while(first.same_409b90(point));
   pool->create_508610()->init_503b20(pool,data->particle,point,offset,&first,&offset,0,data->attached?target:9,this);
  }
  break;
 case 9:
  {
   LB7Pos count(point.x,point.y-100);
   LB7Point a;
   int first=data->a;
   lb7_rotate_501fc0(point,count,(float)first,a);
   pool->create_508610()->init_503b20(pool,data->particle,point,offset,&a,&offset,0,data->attached?target:9,this);
  }
  break;
 case 10:
  {
   int first=data->a<0?rng.rangeInt(0,-data->a):data->a;
   for(int index=first,count=0;count<360;index+=data->b,count+=data->b) {
    if(index>=360)index-=360;
    LB7Pos first(point.x,point.y-100);
    LB7Point a;
    lb7_rotate_501fc0(point,first,(float)index,a);
    pool->create_508610()->init_503b20(pool,data->particle,point,offset,&a,&offset,0,data->attached?target:9,this);
   }
  }
  break;
 }
 return true;
}
