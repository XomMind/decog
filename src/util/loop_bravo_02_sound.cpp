// NOTE: private placeholders for 0x500500, a positional sound attenuation helper.
struct LB2SPoint { int x,y; bool equal_409b90(const LB2SPoint &) const throw(); };
struct LB2SPath {
 int a,b,c,d;
 LB2SPath() throw(); ~LB2SPath() throw();
 unsigned size_9b9a50() const throw();
 LB2SPoint &at_9e7c10(unsigned) throw();
};
struct LB2SArea { int x1,y1,x2,y2; };
struct LB2SCell { int attenuation_45d430() throw(); };
struct LB2SGrid {
 void bounds_9b4430(const LB2SPoint &,int,LB2SArea &) throw();
 LB2SCell *&at_9ced70(const LB2SPoint &) throw();
};
extern LB2SGrid lb2s_grid_cfd44c;
extern LB2SArea lb2s_bounds_d35b84;
struct LB2SCost;
extern LB2SCost *lb2s_cost_cefc48;
struct LB2SCarto { bool path_40c9a0(const LB2SPoint &,const LB2SPoint &,LB2SCost *,void *,LB2SPath &); };
extern LB2SCarto lb2s_carto_cfe568;
void lb2s_erase_9d5190(LB2SPath &,int);
int lb2s_distance_40a3f0(const LB2SPoint &,const LB2SPoint &) throw();
class C026_Range { public: int percentInverse(int); };
class OpY2_CurveRange { public: int curveA(int); int curveB(int); int curveC(int); };
struct LB2SSound {
 char pad00[0x6c];
 int nearRange,farRange;
 int shape;
 int curve_453fe0(int) throw();
 int curve_454020(int) throw();
 int curve_454080(int) throw();
 int curve_4540f0(int) throw();
};
int lb2s_attenuation_500500(LB2SSound *sound,const LB2SPoint &from,const LB2SPoint &to) {
 if(to.equal_409b90(from)) return 100;
 LB2SPath path;
 if(lb2s_distance_40a3f0(from,to)>=sound->farRange) return 0;
 lb2s_grid_cfd44c.bounds_9b4430(from,sound->farRange,lb2s_bounds_d35b84);
 if(lb2s_carto_cfe568.path_40c9a0(from,to,lb2s_cost_cefc48,0,path)) {
  lb2s_erase_9d5190(path,0);
  if(path.size_9b9a50()<sound->farRange) {
   float factor=1.0f;
   for(unsigned i=0;i<path.size_9b9a50();i++) {
    factor=(100-lb2s_grid_cfd44c.at_9ced70(path.at_9e7c10(i))->attenuation_45d430())*factor/100.0;
    if(factor<=0.0) return 0;
   }
   int (LB2SSound::*result)(int)=0;
   switch(sound->shape) {
   case 0: result=reinterpret_cast<int(LB2SSound::*)(int)>(&C026_Range::percentInverse); break;
   case 1: result=reinterpret_cast<int(LB2SSound::*)(int)>(&OpY2_CurveRange::curveA); break;
   case 2: result=reinterpret_cast<int(LB2SSound::*)(int)>(&OpY2_CurveRange::curveB); break;
   case 3: result=reinterpret_cast<int(LB2SSound::*)(int)>(&OpY2_CurveRange::curveC); break;
   }
   return (int)((path.size_9b9a50()<=sound->nearRange ? 100 : (sound->*result)(path.size_9b9a50()))*factor);
  }
 }
 return 0;
}
