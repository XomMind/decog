// Private aliases and observed layouts for encounter-grid layout 0x6cadf0.
#include <vector>
#include "rng.h"
extern RNG rng;
struct LB12Point {int x,y;LB12Point(int,int) throw();LB12Point(const LB12Point &) throw();void assign_46ca50(const LB12Point &) throw();void add_40a2a0(int,int) throw();void sum_40a060(const LB12Point &,int,int) throw();};
struct LB12Box {int x,y,width,height;};
struct LB12Vec {int a,b,c,d;LB12Vec();~LB12Vec();void push_9b32e0(const LB12Point &);LB12Point &back_9e8c10() throw();LB12Point &at_9e7c10(unsigned) throw();};
struct LB12IntGrid {void init_9cf690(int,int,int) throw();int *at_9ceda0(int,int) throw();bool contains_9ceef0(int) throw();int count_9cef40(int) throw();int maxX_9b4370() throw();int maxY_9b4390() throw();int width_9fcd80() throw();int height_9b8f00() throw();};
struct LB12PointGrid {void init_9d3470(int,int,LB12Point) throw();LB12Point *at_9d3330(int,int) throw();};
struct LB12Weights {bool pick_9ba6a0(int *) throw();int size_9b81d0() const throw();};
struct LB12Array {int width_9fcd80() throw();int height_9b8f00() throw();};
struct LB12Arrays {int a,b,c,d;LB12Array *&front_9b7060() throw();};
struct LB12Record {char pad[0x3c];LB12Arrays arrays;char pad4c[0x54-0x4c];bool rotate;char pad55[0x118-0x55];int category;};
struct LB12Records {LB12Record *&at_9b81f0(unsigned) throw();};extern LB12Records lb12_records_cf35b0;
extern int lb12_invalid_caf15c,lb12_odds_b9f150[][3],lb12_edgeOdds_b9e6e4[];
bool lb12_any_9d9b60(const std::vector<bool> &);int lb12_random_9db420(std::vector<bool> &);
bool lb12_empty_6c9f10(const LB12Point &,int,int,int) throw();bool lb12_edge_6c9cb0(int,const LB12Point &,int,int,const LB12Box &) throw();
bool lb12_layout_6cadf0(LB12Weights *weights,int category,const LB12Box &box,int padding,int spacing,LB12IntGrid &grid,LB12PointGrid &points,LB12IntGrid &orientations){
 int value;weights->pick_9ba6a0(&value);
 int line=lb12_records_cf35b0.at_9b81f0(value)->arrays.front_9b7060()->width_9fcd80();
 int row=lb12_records_cf35b0.at_9b81f0(value)->arrays.front_9b7060()->height_9b8f00();
 std::vector<bool> index(4,false);
 index[2]=box.width>=line+padding*2 && box.height>=row+padding*2;
 index[0]=index[2] && lb12_records_cf35b0.at_9b81f0(value)->rotate;
 if(lb12_records_cf35b0.at_9b81f0(value)->rotate)index[1]=index[3]=box.width>=row+padding*2 && box.height>=line+padding*2;
 else index[1]=index[3]=false;
 if(!lb12_any_9d9b60(index))return false;
 int p;do{p=lb12_random_9db420(index);}while(!index[p]);
 bool b=p==1 || p==3;
 int base=(box.width-padding*2-(b?row:line))/((b?row:line)+spacing)+1;
 int a=(box.height-padding*2-(b?line:row))/((b?line:row)+spacing)+1;
 LB12Point other(box.x+padding,box.y+padding);
 grid.init_9cf690(base,a,value);points.init_9d3470(base,a,other);orientations.init_9cf690(base,a,p);
 other.add_40a2a0(rng.rangeInt(0,(float)(box.width-padding*2-base*(b?row:line)-(base-1)*spacing)),rng.rangeInt(0,(float)(box.height-padding*2-a*(b?line:row)-(a-1)*spacing)));
 for(int x=0;x<base;++x){for(int y=0;y<a;++y){
  points.at_9d3330(x,y)->sum_40a060(other,x*((b?row:line)+spacing),y*((b?line:row)+spacing));
  if(!lb12_empty_6c9f10(*points.at_9d3330(x,y),b?row:line,b?line:row,spacing))*grid.at_9ceda0(x,y)=lb12_invalid_caf15c;
 }}
 if(!grid.contains_9ceef0(value))return false;
 bool valid=false;
 if(weights->size_9b81d0()>1 && rng.chance(lb12_odds_b9f150[lb12_records_cf35b0.at_9b81f0(value)->category][category])){
  int remaining=rng.rangeInt(0,(float)(grid.count_9cef40(value)/2));
  while(remaining!=0){--remaining;
   int first,count,a,i,index;bool base;
   do{i=rng.rangeInt(0,(float)grid.maxX_9b4370());a=rng.rangeInt(0,(float)grid.maxY_9b4390());}while(*grid.at_9ceda0(i,a)!=value);
   do{weights->pick_9ba6a0(&index);}while(index==value);
   first=lb12_records_cf35b0.at_9b81f0(index)->arrays.front_9b7060()->width_9fcd80();
   count=lb12_records_cf35b0.at_9b81f0(index)->arrays.front_9b7060()->height_9b8f00();
   if(first<=line && count<=row)base=false;
   else if(count<=line && first<=row)base=true;
   else{if(rng.chance(50))++remaining;continue;}
   if(b)base=!base;
   if(base && !lb12_records_cf35b0.at_9b81f0(index)->rotate){if(rng.chance(50))++remaining;continue;}
   *grid.at_9ceda0(i,a)=index;
   *orientations.at_9ceda0(i,a)=base?(rng.chance(50)?1:3):(lb12_records_cf35b0.at_9b81f0(index)->rotate && rng.chance(50)?0:2);
   valid=true;
  }
 }
 if(category==0 && ((base==1 && b)||(a==1 && !b)) && !valid && rng.chance(lb12_edgeOdds_b9e6e4[category])){
  LB12Vec first;
  for(int x=0;x<grid.width_9fcd80();++x){for(int y=0;y<grid.height_9b8f00();++y){
   first.push_9b32e0(*points.at_9d3330(x,y));
   if(!lb12_edge_6c9cb0(p,first.back_9e8c10(),line,row,box) || !lb12_empty_6c9f10(first.back_9e8c10(),b?row:line,b?line:row,spacing))goto done;
  }}
  for(int x=0,j=0;x<grid.width_9fcd80();++x){for(int y=0;y<grid.height_9b8f00();++y,++j)points.at_9d3330(x,y)->assign_46ca50(first.at_9e7c10(j));}
 done:;
 }
 return true;
}
