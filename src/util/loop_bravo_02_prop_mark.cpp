// NOTE: private partial layouts for 0x729bc0; defined leaf constructor preserves new's result slots.
struct LB2MPoint {
 int x,y;
 LB2MPoint(const LB2MPoint &) throw();
 bool operator==(const LB2MPoint &) const throw();
};
struct LB2MColor {
 unsigned char r,g,b;
 LB2MColor(const LB2MColor &) throw();
};
struct LB2MProp {
 const LB2MPoint &position_4184d0() throw();
 int value_44a630() throw();
 LB2MColor color_45c780() throw();
 int kind_44ab40() throw();
};
struct LB2MHP {
 int id;
 LB2MHP();
 LB2MProp *get_9b64f0() const throw();
};
struct LB2MMark {
 LB2MPoint position;
 int value;
 LB2MColor color;
 LB2MMark(const LB2MPoint &,int,const LB2MColor &);
};
LB2MMark::LB2MMark(const LB2MPoint &p,int v,const LB2MColor &c):position(p),value(v),color(c) {}
struct LB2MPoints {
 int a,b,c,d;
 unsigned size_9b9a50() const throw();
 LB2MPoint &at_9e7c10(unsigned) throw();
};
struct LB2MPointLists {
 int a,b,c,d;
 unsigned size_9e3c60() const throw();
 LB2MPoints &at_9de000(unsigned) throw();
};
struct LB2MMarks { void push_9b8000(LB2MMark *&&) throw(); };
struct LB2MMarkLists {
 int a,b,c,d;
 LB2MMarks &at_9de000(unsigned) throw();
};
struct LB2MMap {
 char pad00[0x8dc];
 LB2MPointLists points;
 LB2MMarkLists marks;
 int firstPropList,propValue;
 void mark_729bc0(LB2MHP);
};
void LB2MMap::mark_729bc0(LB2MHP prop) {
 LB2MPoint pos=prop.get_9b64f0()->position_4184d0();
 for(unsigned i=0;i<points.size_9e3c60();i++) {
  for(unsigned j=0;j<points.at_9de000(i).size_9b9a50();j++) {
   if(points.at_9de000(i).at_9e7c10(j)==pos) {
    marks.at_9de000(i).push_9b8000(new LB2MMark(prop.get_9b64f0()->position_4184d0(),prop.get_9b64f0()->value_44a630(),prop.get_9b64f0()->color_45c780()));
    if(firstPropList==-1 || (int)i<firstPropList) firstPropList=i;
    if(propValue==-1) propValue=prop.get_9b64f0()->kind_44ab40();
    return;
   }
  }
 }
}
