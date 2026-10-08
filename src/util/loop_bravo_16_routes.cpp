// NOTE: private partial views for map route collection/marking6dd160.
#include "rng.h"
extern RNG rng;
struct LB16Point {int x,y;LB16Point() throw();LB16Point(int,int) throw();LB16Point(const LB16Point&) throw();};
struct LB16Prop;struct LB16PropData;struct LB16Mode {int id,type;bool special46ecb0() throw();};
struct LB16H {int id;LB16H() throw();};struct LB16HP {int id;bool valid9b7230()const throw();LB16Prop*get9b64f0()const throw();};
struct LB16HM {int id;LB16Mode*get9b7910()const throw();};extern LB16HM lb16_d1e888;
struct LB16Prop {LB16PropData*definition9b8f00() throw();const LB16Point&point4184d0() throw();void open45ccf0(bool) throw();bool pass65e1d0(LB16H) throw();};
struct LB16Points {int a,b,c,d;LB16Points() throw();~LB16Points();unsigned size9b9a50()const throw();LB16Point&at(unsigned) throw();bool empty9b86e0()const throw();void clear9b3560() throw();void pop9b33e0() throw();};
struct LB16Ints {int a,b,c,d;unsigned size9b9260()const throw();int&at(unsigned) throw();void push9b9d30(const int&);void push9b9280(int&&);};
struct LB16MapRecord {LB16Point point;LB16HM mode;int padc,pad10;LB16HP h14,h18;};
struct LB16Records {int a,b,c,d;unsigned size9b9260()const throw();LB16MapRecord*&at(unsigned) throw();};
struct LB16Area {int a,b,c,d;LB16Point center40ad40() throw();};struct LB16AreaRecord:LB16Area {int value;};
struct LB16Areas {int a,b,c,d;unsigned size9b9260()const throw();LB16AreaRecord*&at(unsigned) throw();};extern LB16Areas lb16_cf3a00;
struct LB16Groups {int a,b,c,d;unsigned size9b5100()const throw();bool empty9b86e0()const throw();LB16Points&at9b8070(unsigned) throw();};
struct LB16Other {int id;};struct LB16Others {int a,b,c,d;unsigned size9b9260()const throw();LB16Other*&at(unsigned) throw();};
struct LB16Props {int a,b,c,d;LB16HP&front9b7060() throw();};struct LB16PropGroups {LB16Props&at9b8070(unsigned) throw();};extern LB16PropGroups lb16_d20248;
struct LB16Cell {LB16HP prop45d550() throw();bool pass66ac40() throw();void route45e080(int) throw();void total45e0a0(int*) throw();};
struct LB16Grid {LB16Cell**at9ced70(LB16Point&) throw();LB16Cell**at9ceda0(int,int) throw();void random9cf0c0(LB16Point&) throw();void neighbors9ce500(const LB16Point&,LB16Points&);int width9b8f10() throw();int height9b8f00() throw();};extern LB16Grid lb16_cfd44c;
struct LB16Cart {bool path40c9a0(const LB16Point&,const LB16Point&,void*,void*,LB16Points&);};extern LB16Cart lb16_cfe568;extern void*lb16_cefc34;
extern LB16Ints lb16_d1e88c;extern int lb16_b90000[];extern LB16PropData*lb16_cefbd8;
struct LB16RouteColumn {int value,pad4,pad8;};extern LB16RouteColumn lb16_b9fce4[],lb16_b9fce8[];
bool lb16_center9d3020(LB16Points&,LB16Point) throw();int lb16_distance40a3f0(const LB16Point&,const LB16Point&) throw();bool lb16_between9daf80(int,int,int) throw();bool lb16_contains9d0ce0(LB16Points&,LB16Point) throw();void lb16_erase9d5190(LB16Points&,int) throw();
struct LB16Map {char pad0[8];LB16Point origin;LB16Records records;LB16Others others;char pad30[4];int total;char pad38[0xe0];LB16Groups groups;char pad128[0x968];LB16Points points;LB16Ints weights,types;bool add6dd0e0(const LB16Point&,int) throw();int adjacent71c850(const LB16Point&) throw();bool near71c150(const LB16Point&,LB16Point&,bool) throw();void routes6dd160();};extern LB16Map*lb16_cefc4c;
void LB16Map::routes6dd160(){
 int value;bool a,p;int index;
 for(int i=0;i<records.size9b9260();i++){
  value=records.at(i)->h14.valid9b7230()?1:records.at(i)->h18.valid9b7230()?2:records.at(i)->mode.get9b7910()->special46ecb0()?0:(lb16_b90000[records.at(i)->mode.get9b7910()->type]!=1)+3;
  if(records.at(i)->mode.get9b7910()->type==19)continue;
  add6dd0e0(records.at(i)->point,value);
 }
 if(lb16_d1e88c.size9b9260()>1)add6dd0e0(origin,5);
 for(int i=0;i<lb16_cf3a00.size9b9260();i++)if(lb16_center9d3020(points,lb16_cf3a00.at(i)->center40ad40())){weights.push9b9d30(lb16_cf3a00.at(i)->value);types.push9b9280(6);}
 for(int i=0;i<groups.size9b5100();i++)if(!groups.empty9b86e0()&&i!=5){value=i+7;for(int j=0;j<groups.at9b8070(i).size9b9a50();j++)add6dd0e0(groups.at9b8070(i).at(j),value);}
 for(int i=0;i<others.size9b9260();i++)add6dd0e0(lb16_d20248.at9b8070(others.at(i)->id).front9b7060().get9b64f0()->point4184d0(),16);
 switch(lb16_d1e888.get9b7910()->type){
 case 13:for(int i=49;i<=50;i++)for(int j=49;j<=50;j++)add6dd0e0(LB16Point(i,j),19);break;
 case 20:{LB16Point point;for(int i=0;i<15;i++)for(int j=0;j<100;j++){
  lb16_cfd44c.random9cf0c0(point);
  if((*lb16_cfd44c.at9ced70(point))->prop45d550().valid9b7230()&&(*lb16_cfd44c.at9ced70(point))->prop45d550().get9b64f0()->definition9b8f00()==lb16_cefbd8&&adjacent71c850(point)>=2&&lb16_cefc4c->near71c150(point,point,true)&&add6dd0e0(point,(rng.chance(66)?1:0)+19))break;
 }break;}
 case 15:{LB16Point point;for(int i=0;i<30;i++)for(int j=0;j<500;j++){
  lb16_cfd44c.random9cf0c0(point);
  if((*lb16_cfd44c.at9ced70(point))->prop45d550().valid9b7230()&&(*lb16_cfd44c.at9ced70(point))->prop45d550().get9b64f0()->definition9b8f00()==lb16_cefbd8&&add6dd0e0(point,(rng.chance(66)?1:0)+19))break;
 }break;}
 }
 LB16Points item;
 for(int i=0;i<points.size9b9a50();i++)for(int j=i+1;j<points.size9b9a50();j++){
  if(lb16_distance40a3f0(points.at(i),points.at(j))<=(lb16_b9fce4[types.at(i)].value+lb16_b9fce4[types.at(j)].value)/2){
   item.clear9b3560();a=lb16_between9daf80(7,types.at(i),15);p=lb16_between9daf80(7,types.at(j),15);
   if(a)(*lb16_cfd44c.at9ced70(points.at(i)))->prop45d550().get9b64f0()->open45ccf0(true);
   if(p)(*lb16_cfd44c.at9ced70(points.at(j)))->prop45d550().get9b64f0()->open45ccf0(true);
   if(lb16_cfe568.path40c9a0(points.at(i),points.at(j),lb16_cefc34,0,item)&&item.size9b9a50()<=(lb16_b9fce8[types.at(i)].value+lb16_b9fce8[types.at(j)].value)/2){
    if(a){(*lb16_cfd44c.at9ced70(points.at(i)))->prop45d550().get9b64f0()->open45ccf0(false);lb16_erase9d5190(item,0);}
    else if((*lb16_cfd44c.at9ced70(points.at(i)))->prop45d550().valid9b7230()&&!(*lb16_cfd44c.at9ced70(points.at(i)))->prop45d550().get9b64f0()->pass65e1d0(LB16H()))lb16_erase9d5190(item,0);
    if(p){(*lb16_cfd44c.at9ced70(points.at(j)))->prop45d550().get9b64f0()->open45ccf0(false);item.pop9b33e0();}
    else if((*lb16_cfd44c.at9ced70(points.at(j)))->prop45d550().valid9b7230()&&!(*lb16_cfd44c.at9ced70(points.at(j)))->prop45d550().get9b64f0()->pass65e1d0(LB16H()))lb16_erase9d5190(item,0);
    index=(weights.at(i)+weights.at(j))/2;
    for(int k=0;k<item.size9b9a50();k++){
     (*lb16_cfd44c.at9ced70(item.at(k)))->route45e080(index);
     LB16Points point;lb16_cfd44c.neighbors9ce500(item.at(k),point);
     for(int i=0;i<point.size9b9a50();i++)if((*lb16_cfd44c.at9ced70(point.at(i)))->pass66ac40()&&!lb16_contains9d0ce0(item,point.at(i)))(*lb16_cfd44c.at9ced70(point.at(i)))->route45e080(index/2);
    }
   }else{
    if(a)(*lb16_cfd44c.at9ced70(points.at(i)))->prop45d550().get9b64f0()->open45ccf0(false);
    if(p)(*lb16_cfd44c.at9ced70(points.at(j)))->prop45d550().get9b64f0()->open45ccf0(false);
   }
  }
 }
 total=0;
 for(int i=0;i<lb16_cfd44c.width9b8f10();i++)for(int j=0;j<lb16_cfd44c.height9b8f00();j++)(*lb16_cfd44c.at9ceda0(i,j))->total45e0a0(&total);
}
