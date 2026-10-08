// Private ABI views for obliterator aftermath74da60.
#include <string>
#include "rng.h"
using std::string;extern RNG rng;
struct LB19Entity;struct LB19Item;struct LB19Prop;struct LB19AI;
struct LB19Point {int x,y;LB19Point() throw();LB19Point(int,int) throw();int random40c130() throw();};
struct LB19H {int id;LB19H() throw();bool valid9b7230()const throw();LB19Entity*get9b6570()const throw();};
struct LB19HI {int id;LB19HI() throw();bool valid9b7230()const throw();LB19Item*get9b65b0()const throw();};
struct LB19HP {int id;LB19HP() throw();LB19Prop*get9b64f0()const throw();};
struct LB19Points {int a,b,c,d;LB19Points();~LB19Points();unsigned size9b9260()const throw();LB19Point&at9e7c10(unsigned) throw();void clear9b3560() throw();};
struct LB19Items {int a,b,c,d;LB19Items();~LB19Items();unsigned size9b9260()const throw();LB19HI&at9b81f0(unsigned) throw();bool empty9b86e0()const throw();void push9b9d30(const LB19HI&);};
struct LB19Def {char p0[0x70];int size;char p74;bool blocked;};
struct LB19Item {bool damage57ab10(int,int,int,int,LB19H,int,int) throw();int value9b6bf0() throw();void remove57dbe0(bool,bool,int,bool) throw();LB19Def*def9b4350() throw();int type457f90() throw();int state577fb0() throw();bool blocked457e90() throw();void move57a0f0(const LB19Point&,int,bool) throw();string name571db0(bool,bool);};
struct LB19Prop {int value45c630() throw();void damage45ce10(bool,int,bool,LB19H) throw();};
struct LB19AI {void threat5b39b0(LB19H) throw();};
struct LB19Entity {const string&name416f40() throw();unsigned items5cb8b0(LB19Items&) throw();bool player5c7600() throw();bool blocked45aa10() throw();const LB19Point&pos45a4a0() throw();int integrity490840() throw();int status45a9f0() throw();void status4514e0(int) throw();void timer45b360(int) throw();void die633790(bool,int,LB19H,int,int,int,bool,bool);LB19AI*ai45b590() throw();};
struct LB19Cell {LB19HI item45d8f0() throw();bool prop45d500() throw();LB19HP prop45d550() throw();int armor66ae70() throw();void trigger45e110(int,int,LB19H) throw();LB19H entity45d250() throw();};
struct LB19Grid {LB19Cell**at9ced70(LB19Point&) throw();};extern LB19Grid lb19_cfd44c;
struct LB19Map {void response74da60(LB19H,int,int);LB19H find715230(int,int) throw();bool visible4631f0(LB19H) throw();bool empty71bc10(const LB19Point&,LB19Point&) throw();void attack735720(LB19H,LB19H,bool) throw();};extern LB19Map*lb19_cefc4c;
struct LB19Mode {int pad;int type;};struct LB19HM {int id;LB19Mode*get9b7910()const throw();};extern LB19HM lb19_d1e888;
struct LB19Data {const string&get46f6d0(const string&);void set46f700(const string&,const string&);};extern LB19Data lb19_d1e860;
int lb19_int405610(const string&) throw();void lb19_message49c610(int,LB19H,const string&,int);
void lb19_append(LB19Points&,LB19Points&);void lb19_shuffle(LB19Items&);void lb19_erase(LB19Items&,int&) throw();
extern LB19Points lb19_d3976c,lb19_d29d6c,lb19_d2ac84;extern int lb19_cf462c;
bool lb19_route5111e0(int,const string*,const string*,const string*,LB19H,LB19HP,const LB19Point*,bool);
struct LB19UI {void update8758d0(bool) throw();};extern LB19UI*lb19_cec058;struct LB19Log{void end7b4f10() throw();};extern LB19Log*lb19_cec0b4;
#define LB19_ROUTE(ID,TEXT) do{if(lb19_route5111e0(ID,TEXT,0,0,h,LB19HP(),0,false))lb19_cec058->update8758d0(true);lb19_cec0b4->end7b4f10();}while(false)
void LB19Map::response74da60(LB19H attacker,int unused,int unused2){
 if(lb19_d1e888.get9b7910()->type==34&&!lb19_int405610(lb19_d1e860.get46f6d0("comMaincObliteratorComment_g"))){LB19H h=find715230(3,95);if(h.valid9b7230()&&visible4631f0(h)){lb19_d1e860.set46f700("comMaincObliteratorComment_g","1");string line=h.get9b6570()->name416f40()+": \"So the Derelict weapon is whole again...\"";lb19_message49c610(0x322,h,line,0);}}
 LB19Points first;lb19_append(first,lb19_d3976c);lb19_append(first,lb19_d29d6c);lb19_append(first,lb19_d2ac84);
 LB19HI i;
 for(unsigned n=0;n<first.size9b9260();n++)if((*lb19_cfd44c.at9ced70(first.at9e7c10(n)))->item45d8f0().valid9b7230()){
 i=(*lb19_cfd44c.at9ced70(first.at9e7c10(n)))->item45d8f0();i.get9b65b0()->damage57ab10(rng.rangeInt(50.f,100.f),5,false,false,attacker,true,false);
 if(i.get9b65b0()&&i.get9b65b0()->value9b6bf0()<100&&i.get9b65b0()->value9b6bf0()!=-1&&rng.chance(100-i.get9b65b0()->value9b6bf0()))i.get9b65b0()->remove57dbe0(0,true,true,true);
 }
 for(unsigned n=0;n<lb19_d3976c.size9b9260();n++){
 if((*lb19_cfd44c.at9ced70(lb19_d3976c.at9e7c10(n)))->prop45d500()&&(*lb19_cfd44c.at9ced70(lb19_d3976c.at9e7c10(n)))->prop45d550().get9b64f0()->value45c630()!=-1)(*lb19_cfd44c.at9ced70(lb19_d3976c.at9e7c10(n)))->prop45d550().get9b64f0()->damage45ce10(0,4,0,attacker);
 if((*lb19_cfd44c.at9ced70(lb19_d3976c.at9e7c10(n)))->armor66ae70()!=-1)(*lb19_cfd44c.at9ced70(lb19_d3976c.at9e7c10(n)))->trigger45e110(0,0,attacker);
 }
 for(unsigned n=0;n<lb19_d29d6c.size9b9260();n++)if(rng.chance(50)){
 if((*lb19_cfd44c.at9ced70(lb19_d29d6c.at9e7c10(n)))->prop45d500()&&(*lb19_cfd44c.at9ced70(lb19_d29d6c.at9e7c10(n)))->prop45d550().get9b64f0()->value45c630()!=-1)(*lb19_cfd44c.at9ced70(lb19_d29d6c.at9e7c10(n)))->prop45d550().get9b64f0()->damage45ce10(0,4,0,attacker);
 if((*lb19_cfd44c.at9ced70(lb19_d29d6c.at9e7c10(n)))->armor66ae70()!=-1)(*lb19_cfd44c.at9ced70(lb19_d29d6c.at9e7c10(n)))->trigger45e110(0,0,attacker);
 }
 LB19Point chance(2,4);LB19H h;
 for(unsigned n=0;n<first.size9b9260();n++)if((*lb19_cfd44c.at9ced70(first.at9e7c10(n)))->entity45d250().valid9b7230()){
 h=(*lb19_cfd44c.at9ced70(first.at9e7c10(n)))->entity45d250();LB19Point p;LB19Items b;LB19Items a;
 if(h.get9b6570()->items5cb8b0(a))lb19_shuffle(a);
 for(int index=0,count=chance.random40c130();count>0&&index<a.size9b9260();count--,index++)b.push9b9d30(a.at9b81f0(index));
 if(!b.empty9b86e0())for(int index=0;index<b.size9b9260();index++){
 if(b.at9b81f0(index).get9b65b0()->def9b4350()->size>1&&b.at9b81f0(index).get9b65b0()->type457f90()!=7&&!b.at9b81f0(index).get9b65b0()->state577fb0()&&!b.at9b81f0(index).get9b65b0()->def9b4350()->blocked&&(lb19_cf462c!=2||h.get9b6570()->player5c7600())&&!b.at9b81f0(index).get9b65b0()->blocked457e90()&&!h.get9b6570()->blocked45aa10()&&lb19_cefc4c->empty71bc10(h.get9b6570()->pos45a4a0(),p))b.at9b81f0(index).get9b65b0()->move57a0f0(p,true,true);else lb19_erase(b,index);
 }
 if(!b.empty9b86e0()&&visible4631f0(h)){
 string line;
 for(unsigned index=0;index<b.size9b9260();index++)if(b.at9b81f0(index).get9b65b0()){if(!line.empty())line+=", ";line+=b.at9b81f0(index).get9b65b0()->name571db0(0,0);}
 if(!line.empty())LB19_ROUTE(414+(h.get9b6570()->player5c7600()?1:0),&line);
 }
 if(h.get9b6570()->integrity490840()<100&&rng.chance(50)){
 LB19_ROUTE(416+(h.get9b6570()->player5c7600()?1:0),0);
 if(h.get9b6570()->status45a9f0()>-100)h.get9b6570()->status4514e0(-100);
 h.get9b6570()->timer45b360(50);h.get9b6570()->die633790(!visible4631f0(h),5,attacker,9,0,0,false,true);
 }else if(attacker.get9b6570()&&h.get9b6570()->ai45b590()){h.get9b6570()->ai45b590()->threat5b39b0(attacker);attack735720(attacker,h,false);}
 }
 lb19_d3976c.clear9b3560();lb19_d29d6c.clear9b3560();lb19_d2ac84.clear9b3560();
}
