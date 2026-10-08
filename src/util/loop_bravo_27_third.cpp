#include <string>
#include "rng.h"
using std::string;extern RNG rng;
// NOTE: private partial layouts and address-named borrowed interfaces.
struct LB27P{int x,y;};struct LB27Entity;struct LB27Item;struct LB27Group;struct LB27AI;
struct LB27H{int id;LB27H()throw();LB27Entity*get9b6570()const throw();bool null9b65d0()const throw();bool ne9b6510(LB27H)const throw();};
struct LB27HI{int id;LB27HI()throw();LB27Item*get9b65b0()const throw();};struct LB27HG{int id;LB27Group*get9b7250()const throw();};
struct LB27Kind{char p[0x68];int size;int value9b4350()throw();void set44cea0(int)throw();};struct LB27Group{int value9b4350()throw();};

struct LB27Entity{LB27HI weapon5d5d40();int size45a360()throw();LB27Kind*kind9b4350()throw();int energy45a8d0()throw();int matter45a920()throw();void spend45b1e0(int)throw();void alert639ec0(LB27H,bool);void destroy63a0d0();LB27HI item5d2380(int);void remove639730(bool);LB27AI*ai45b590()throw();LB27HG group45a3f0()throw();void faction5dc780(LB27HG,bool);void setAI64ecf0(LB27AI*);const string&name416f40()throw();int effect639530(int,int);void level5fd900(int,int);void refresh63c660();LB27P pos45a4c0()throw();};
struct LB27Item{int category457880()throw();int special457f90()throw();string name571db0(bool,bool);int energy5788e0()throw();int matter5789c0()throw();};
struct LB27Cell{LB27H entity45d250()throw();bool cave66af50()throw();};struct LB27Grid{LB27Cell**at9ced70(const LB27P&)throw();};extern LB27Grid lb27_cfd44c;
template<class T>struct LB27Vec{T*first,*last,*end;std::allocator<T>alloc;LB27Vec();~LB27Vec();unsigned size9b9260()const throw();void clear9b4710();};struct LB27Child{LB27P from,to;};struct LB27Record;struct LB27HR{int id;};
// NOTE: undecoded element types preserve native ownership without guessing integer/pointer semantics.
struct LB27AI24Element;struct LB27AI90Element;struct LB27AI120Element;struct LB27Shoot6cElement;
struct LB27AITarget;struct LB27AIOrder;
struct LB27HandleSlot{unsigned key;};
struct LB27Bounds{LB27P min,max;};
struct LB27AI{
 LB27H entity;int type,rating,unknown0c;LB27P point10,point18;LB27HandleSlot handle20;LB27Vec<LB27AI24Element>owner24;
 int unknown34,unknown38,unknown3c;LB27HandleSlot handle40;int unknown44,unknown48,unknown4c;LB27HandleSlot handle50;
 unsigned char flag54,flag55,flag56;LB27HandleSlot handle58;unsigned char flag5c;
 int unknown60,unknown64,unknown68;LB27Vec<LB27P>points6c;unsigned char flag7c;
 LB27Bounds bounds80;LB27Vec<LB27AI90Element>owner90;int unknowna0;LB27Bounds boundsa4;
 LB27HandleSlot handleb4,handleb8;int unknownbc,unknownc0,unknownc4,unknownc8,unknowncc,unknownd0;LB27HandleSlot handled4;int unknownd8;
 LB27Vec<LB27H>remembereddc;int turnec;LB27Vec<LB27AITarget*>targetsf0;
 int unknown100,unknown104,unknown108,unknown10c;unsigned char flag110;LB27AIOrder*order114;
 int unknown118,unknown11c;LB27Vec<LB27AI120Element>owner120;
 LB27AI(LB27H,int,int);~LB27AI();int kind9b4350()throw();void set44cea0(int)throw();
};
struct LB27Map{LB27Vec<LB27H>&list463d80()throw();int chance7163a0(LB27H);bool allowed716250(LB27H,int,string*);int cost7161e0();void spend774390(int,int);void action735720(LB27H,LB27H,bool);void action7358c0(LB27H,LB27H);void remove730f40(LB27H);LB27HG faction463890(int);void add463da0(LB27H);LB27HR add777a20(LB27HR);};extern LB27Map*lb27_cefc4c;
struct LB27Shoot{
 void*retailVtable;LB27HR record04;int unknown08,unknown0c;
 LB27H entity10;int mode14;LB27P point18,point20;LB27H target28;LB27Vec<LB27Child>children2c;
 unsigned char flag3c,flag3d,flag3e;LB27H target40;LB27Vec<LB27HI>items44;
 int unknown54,unknown58,unknown5c,unknown60,unknown64,unknown68;LB27Vec<LB27Shoot6cElement>owner6c;
 ~LB27Shoot();LB27Shoot(LB27H,int,const LB27P&,const LB27P&,int*,LB27Vec<LB27Child>&,bool,LB27HI);};struct LB27Factory{LB27HR create7930e0(LB27Shoot*);bool show793450(int,bool,const string*,bool,bool);};extern LB27Factory*lb27_cefaa8;extern LB27P lb27_d2e20c;
struct LB27Phrase{const void*definition;string text;LB27Phrase(int,const string*,const string*,const string*,LB27H,LB27H);};struct LB27Interface{void add7b1880(LB27Phrase*);};extern LB27Interface*lb27_cec0f4;
struct LB27Dialog{void update8758d0(bool);};extern LB27Dialog*lb27_cec058;struct LB27Log{void end7b4f10();};extern LB27Log*lb27_cec0b4;
struct LB27Stats{bool add4729d0(unsigned,int,string,int);};extern LB27Stats lb27_d2c658;struct LB27Player{void event77fbc0(int);};extern LB27Player lb27_cf45d8;extern unsigned lb27_caed20;extern const char lb27_b96423[],lb27_b96427[];
string lb27_int4051f0(int);int lb27_clamp9cdc80(int,int,int)throw();void lb27_warn7b1750(int,const string*,const string*,const string*,LB27H,LB27H,const LB27P*);bool lb27_route5111e0(int,const string*,const string*,const string*,LB27H,LB27H,const LB27P*,bool);void lb27_phrase5141b0(int,const string*,const string*,const string*,LB27H,const LB27P*);int lb27_sound4541b0(unsigned,int,int);
#define LB27_MSG(ID,TEXT,SECOND) do{if(lb27_route5111e0(ID,TEXT,SECOND,0,entity,pos,0,false))lb27_cec058->update8758d0(true);lb27_cec0b4->end7b4f10();}while(false)
static_assert(sizeof(LB27AI)==0x130,"observed complete AI allocation");
static_assert(sizeof(LB27Shoot)==0x7c,"observed complete Shoot allocation");
static_assert(sizeof(LB27Vec<LB27HI>)==16,"native owner with allocator");
struct LB27CMap{char p[0x50c];LB27Vec<LB27Child>children;char p51c[0x5b8-0x51c];LB27H target;unsigned start,last;char p5c4[0x618-0x5c4];unsigned caveLast,caveStart;void refresh49ad30();bool third8231f0(LB27H,const LB27P&);};
bool LB27CMap::third8231f0(LB27H entity,const LB27P&point){
 LB27HI x=entity.get9b6570()->weapon5d5d40();int amount;
 if(x.get9b65b0()->category457880()==30){
  switch(x.get9b65b0()->special457f90()){
  case 199:{
   string buffer;LB27H pos=(*lb27_cfd44c.at9ced70(point))->entity45d250();
   if(pos.null9b65d0()){buffer="must be a robot";lb27_warn7b1750(72,&buffer,0,0,LB27H(),LB27H(),0);return false;}
   if(lb27_cefc4c->list463d80().size9b9260()==8){lb27_warn7b1750(73,&lb27_int4051f0(8),0,0,LB27H(),LB27H(),0);return false;}
   int num=lb27_clamp9cdc80(0,lb27_cefc4c->chance7163a0(pos),100);
   if(!lb27_cefc4c->allowed716250(pos,num,&buffer)){lb27_warn7b1750(72,&buffer,0,0,LB27H(),LB27H(),0);return false;}
   int value=lb27_cefc4c->cost7161e0();int line=pos.get9b6570()->kind9b4350()->size*pos.get9b6570()->size45a360()*2+10;
   if(entity.get9b6570()->matter45a920()<value){lb27_warn7b1750(1,&lb27_int4051f0(value),0,0,entity,LB27H(),0);return true;}
   if(target.null9b65d0()||target.ne9b6510(pos)){
    lb27_warn7b1750(74,&lb27_int4051f0(num),&lb27_int4051f0(value),&lb27_int4051f0(line),LB27H(),LB27H(),0);
    reset:target=pos;start=lb27_caed20;last=lb27_caed20;refresh49ad30();return true;
   }else if(lb27_caed20<start+500)return true;
   else if(lb27_caed20>last+3000)goto reset;
   last=lb27_caed20;entity.get9b6570()->spend45b1e0(value);lb27_cefc4c->spend774390(17,300);entity.get9b6570()->alert639ec0(pos,false);entity.get9b6570()->destroy63a0d0();lb27_cefc4c->action735720(entity,pos,false);lb27_cefc4c->action7358c0(entity,pos);LB27HI a=entity.get9b6570()->item5d2380(199);
   if(!rng.chance(num)){LB27_MSG(199,&a.get9b65b0()->name571db0(false,false),0);lb27_sound4541b0(226,0,0);}
   else{
    pos.get9b6570()->remove639730(false);lb27_cefc4c->remove730f40(pos);int current=pos.get9b6570()->ai45b590()->kind9b4350();
    if(pos.get9b6570()->group45a3f0().get9b7250()->value9b4350())pos.get9b6570()->faction5dc780(lb27_cefc4c->faction463890(0),false);
    pos.get9b6570()->setAI64ecf0(new LB27AI(pos,3,current>8?current:8));
    LB27_MSG(198,&a.get9b65b0()->name571db0(false,false),&lb27_int4051f0(line));
    do{lb27_phrase5141b0(99,&a.get9b65b0()->name571db0(false,false),&pos.get9b6570()->name416f40(),0,LB27H(),0);}while(false);
    lb27_sound4541b0(224,0,0);pos.get9b6570()->effect639530(57,line+1);pos.get9b6570()->level5fd900(5,0);pos.get9b6570()->refresh63c660();pos.get9b6570()->ai45b590()->set44cea0(8);lb27_cefc4c->add463da0(pos);
    lb27_d2c658.add4729d0(950,1,lb27_b96423,-1);lb27_d2c658.add4729d0(951,lb27_cefc4c->list463d80().size9b9260(),lb27_b96427,-1);lb27_cf45d8.event77fbc0(136);if(lb27_cefc4c->list463d80().size9b9260()>=8)lb27_cf45d8.event77fbc0(300);
   }
   break;
  }}return true;
 }
 if(x.get9b65b0()->energy5788e0()>entity.get9b6570()->energy45a8d0()){lb27_warn7b1750(0,&lb27_int4051f0(x.get9b65b0()->energy5788e0()),0,0,entity,LB27H(),0);lb27_cefaa8->show793450(50,true,0,false,false);return false;}
 if(x.get9b65b0()->matter5789c0()>entity.get9b6570()->matter45a920()){lb27_warn7b1750(1,&lb27_int4051f0(x.get9b65b0()->matter5789c0()),0,0,entity,LB27H(),0);lb27_cefaa8->show793450(53,true,0,false,false);return false;}
 if((*lb27_cfd44c.at9ced70(entity.get9b6570()->pos45a4c0()))->cave66af50()){
  if(lb27_caed20<caveLast+500)return false;
  else if(lb27_caed20>caveStart+10000){caveStart=lb27_caed20;caveLast=lb27_caed20;lb27_sound4541b0(60,0,0);lb27_cec0f4->add7b1880(new LB27Phrase(167,0,0,0,LB27H(),LB27H()));return false;}
 }
 children.clear9b4710();lb27_cefc4c->add777a20(lb27_cefaa8->create7930e0(new LB27Shoot(entity,0,point,lb27_d2e20c,&amount,children,false,LB27HI())));lb27_cefc4c->spend774390(10,amount);return true;
}
