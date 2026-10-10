#include <string>
#include <memory>
#include "rng.h"
using std::string;extern RNG rng;
// NOTE: private partial borrowed interfaces; allocated Shoot/Phrase owners have real native fields.
struct D42P{int x,y;D42P();D42P(const D42P&)throw();D42P&operator=(const D42P&)throw();};
struct D42Entity;struct D42Item;struct D42Prop;struct D42Group;struct D42Effects;struct D42EntityEffect;
struct D42HE{int id;D42HE()throw();D42Entity*get9b6570()const throw();bool valid9b7230()const throw();bool ne9b6510(D42HE)const throw();};
struct D42HI{int id;D42HI()throw();D42Item*get9b65b0()const throw();bool valid9b7230()const throw();};
struct D42HP{int id;D42HP()throw();D42Prop*get9b64f0()const throw();bool valid9b7230()const throw();};
struct D42HG{int id;D42Group*get9b7250()const throw();};struct D42HS{int id;D42HS()throw();};
template<class T>struct D42Vec{T*first,*last,*end;std::allocator<T>alloc;D42Vec();D42Vec(const D42Vec&);~D42Vec();D42Vec&operator=(const D42Vec&);unsigned size9b9260()const throw();bool empty9b86e0()const throw();T&front9b7060();T&at9b81f0(unsigned);};
struct D42Range{int low,high;int random40c130();};
struct D42PathStep; // NOTE: borrowed optional path element; only its real Point prefix/16-byte stride are known downstream.
struct D42Line{D42P from,to;};
// NOTE: unknownAc is only a zero-tested 32-bit borrowed word here; its original domain remains undecoded. No pointer interpretation or complete Def-size claim.
struct D42Def{char p[0x48];int category;char p4c[0x1c];int kind;char p6c[0x40];int unknownAc,indexB0;char pb4[0x94];D42Vec<int>flags;};
struct D42Entity{bool same45a510(const D42P&);D42P nearest5c80f0(const D42P&);D42HI melee5d5d40();bool weapons5d6a80(D42Vec<D42HI>*,const D42P&,int);bool friendly45aaa0(D42HE);int hacking5cab90();int target45a760();void target44e2c0(int);D42Def*def9b4350();const D42P&pos45a4a0();D42P point45a4c0();int relation5c7fc0(D42HE);void reset5fdab0();const string&name416f40();void faction5dc780(D42HG,bool);D42EntityEffect*effect45ac40(int);void level5fd900(int,int);D42Effects*effects45ad90();D42HG group45a3f0();int energy45a8d0();int matter45a920();int heat5d7320(D42Vec<D42HI>*,bool);bool hostile45aa70(D42HE);int rating5df740(int);};
struct D42Item{int kind457f90();int category457880();int energy5788e0();int matter5789c0();};struct D42Prop{bool passable65e1d0(D42HE);};struct D42Group{int kind9b4350();};
struct D42Cell{bool blocked45d480();D42HE entity45d250();D42HP prop45d550();bool cave66af50();};struct D42Grid{D42Cell**at9ced70(D42P&);};extern D42Grid d42_cfd44c;
struct D42World{D42HE player4630f0();bool reachable465230(int,const D42P&,const D42P&);void hack734ae0(D42HE,const D42P&,bool);void playerActionFinish(int,int);D42HG group463890(int);D42HE other7345f0(D42HE,D42HE,bool);int member4638e0(int,int);bool free464370();D42HS add777a20(D42HS);};extern D42World*d42_cefc4c;
struct D42Base{virtual ~D42Base();virtual int kind();virtual bool update();virtual void finish();D42HS record;int state,time;D42Base();};
struct D42Shoot: D42Base{D42HE entity;int mode;D42P target,origin;D42HE targetEntity;D42Vec<D42Line>children;bool misfire,autonomous,flag;D42HE targeting;D42Vec<D42HI>items;int fired,active,unknown5c,unknown60,unknown64,unknown68;D42Vec<D42P>points;virtual int kind();virtual bool update();virtual void finish();D42Shoot(D42HE,int,const D42P&,const D42P&,int*,D42Vec<D42Line>&,bool,D42HI);~D42Shoot();};
struct D42PhraseDef;struct D42Phrase{D42PhraseDef*definition;string text;D42Phrase(int,const string*,const string*,const string*,D42HE,D42HE);~D42Phrase();};
struct D42Hints{bool show793450(int,bool,const string*,bool,bool);D42HS create7930e0(D42Shoot*);};extern D42Hints*d42_cefaa8;
struct D42Interface{void add7b1880(D42Phrase*);};extern D42Interface*d42_cec0f4;
struct D42Dialog{void update8758d0(bool);};extern D42Dialog*d42_cec058;struct D42Log{void end7b4f10();};extern D42Log*d42_cec0b4;
struct D42Stats{bool add4729d0(unsigned,int,string,int);};extern D42Stats d42_d2c658;
struct D42Player{bool achieve77fbc0(int);void suspicion77ee70(float,int,D42HE);bool flag46de40(int);};extern D42Player d42_cf45d8;
struct D42GameData{bool flag46f4b0(int);};extern D42GameData d42_d1e860;
struct D42Memory{int type;void init873a50(D42HE,bool);};extern D42Memory d42_d1d9c0;
struct D42Mouse{bool hidden41a6e0();};extern D42Mouse*d42_cefa94;
struct D42Index{int index;};extern D42Index*d42_cf4700;extern D42Vec<D42Def*>d42_d25de0;
extern D42Vec<D42Line>d42_d1da10;extern D42P d42_d1da20,d42_d1da28,d42_d1da30;extern D42Range d42_d2191c;extern D42HE d42_d1da3c;
extern unsigned d42_caed20;extern bool d42_d28e7a;extern unsigned char d42_b95758[];extern int d42_b985e0[][11],d42_b98480[][11];extern const char d42_b9641b[],d42_b9641e[],d42_b9641f[],d42_b96422[];
string d42_int4051f0(int);bool d42_adj4373c0(const D42P&,const D42P&);bool d42_contains9db330(D42Vec<int>&,int);bool d42_range9e28f0(D42Vec<int>&,int,unsigned,unsigned);bool d42_between9daf80(int,int,int);
void d42_message7b1750(int,const string*,const string*,const string*,D42HE,D42HE,const D42P*);bool d42_route5111e0(int,const string*,const string*,const string*,D42HE,D42HE,const D42P*,bool);bool d42_phrase5141b0(int,const string*,const string*,const string*,D42HE,const D42P*);int d42_sound4541b0(unsigned,int,int);
bool d42_effect4569a0(int,D42HE,D42HE,D42HP,D42HI,const D42P*,const string*,D42Effects*,D42HE,D42HP,D42HI,const D42P*);
struct D42Map{char p[0x4c8];D42P target,origin;bool multi;D42Vec<D42P>locations;D42Vec<int>markers;char p4fc[0x10];D42Vec<D42Line>paths;char p51c[0xfc];unsigned caveLast,caveStart,warnLast,warnStart;bool point805190(D42P&);int range805360(D42HE,D42Vec<D42PathStep>*,D42P*);bool third8231f0(D42HE,const D42P&);void refresh827950();void fire821450(D42HE);};
static_assert(sizeof(D42Shoot)==124,"actual native Shoot allocation");static_assert(sizeof(D42Phrase)==32,"actual native Phrase allocation");
#define D42_MSG(ID,TEXT,A,B,POS) do{if(d42_route5111e0(ID,TEXT,0,0,A,B,POS,false))d42_cec058->update8758d0(true);d42_cec0b4->end7b4f10();}while(false)
void D42Map::fire821450(D42HE entity){
 D42P pos;
 if(point805190(pos)&&target.x!=-1){
 if(entity.get9b6570()->same45a510(target)){d42_message7b1750(52,0,0,0,entity,D42HE(),0);return;}
 D42Vec<D42HI>slots;
 if(paths.empty9b86e0())entity.get9b6570()->weapons5d6a80(&slots,target,-1);
 else entity.get9b6570()->weapons5d6a80(&slots,target,range805360(entity,0,0));
 if(slots.empty9b86e0()){
  if(d42_adj4373c0(entity.get9b6570()->nearest5c80f0(target),target)&&entity.get9b6570()->melee5d5d40().valid9b7230()){
   if((*d42_cfd44c.at9ced70(target))->blocked45d480()||(*d42_cfd44c.at9ced70(target))->entity45d250().valid9b7230()||((*d42_cfd44c.at9ced70(target))->prop45d550().valid9b7230()&&!(*d42_cfd44c.at9ced70(target))->prop45d550().get9b64f0()->passable65e1d0(D42HE()))){third8231f0(entity,target);refresh827950();}
   else d42_message7b1750(54,0,0,0,entity,D42HE(),0);
  }else d42_message7b1750(53,0,0,0,entity,D42HE(),0);
  return;
 }
 if(d42_cf4700&&slots.size9b9260()==1&&slots.front9b7060().get9b65b0()->kind457f90()==119){
  D42HE other=(*d42_cfd44c.at9ced70(target))->entity45d250();
  if(other.valid9b7230()){
   if(d42_contains9db330(d42_d25de0.at9b81f0(d42_cf4700->index)->flags,14)&&other.valid9b7230()&&other.get9b6570()->friendly45aaa0(entity)&&other.get9b6570()->hacking5cab90()&&other.get9b6570()->target45a760()==0&&d42_cefc4c->reachable465230(9999,entity.get9b6570()->pos45a4a0(),other.get9b6570()->pos45a4a0())){
    d42_cefc4c->hack734ae0(entity,other.get9b6570()->pos45a4a0(),true);other.get9b6570()->target44e2c0(0);D42_MSG(793,0,entity,other,0);refresh827950();d42_cefc4c->playerActionFinish(17,100);return;
   }
   if(d42_contains9db330(d42_d25de0.at9b81f0(d42_cf4700->index)->flags,15)&&!other.get9b6570()->def9b4350()->unknownAc&&d42_cefc4c->reachable465230(9999,entity.get9b6570()->pos45a4a0(),other.get9b6570()->pos45a4a0())){
    int status=other.get9b6570()->relation5c7fc0(d42_cefc4c->player4630f0());bool allied=status==2;
    if(other.get9b6570()->target45a760()==3||other.get9b6570()->target45a760()==4||(allied&&other.get9b6570()->target45a760()==1)){
     int chance=allied?100:50;
     if(rng.chance(chance)){
      if(allied){D42_MSG(794,0,other,D42HE(),0);other.get9b6570()->reset5fdab0();d42_d1d9c0.init873a50(D42HE(),false);}
      else{D42_MSG(796,0,other,D42HE(),0);if(d42_b95758[other.get9b6570()->def9b4350()->category])do{d42_phrase5141b0(21,&other.get9b6570()->name416f40(),0,0,D42HE(),0);}while(false);other.get9b6570()->reset5fdab0();other.get9b6570()->faction5dc780(d42_cefc4c->group463890(1),true);d42_sound4541b0(107,0,0);d42_d2c658.add4729d0(890,1,d42_b9641b,-1);d42_cf45d8.achieve77fbc0(99);}
      d42_cefc4c->hack734ae0(entity,other.get9b6570()->pos45a4a0(),true);
     }else{D42_MSG(795,0,other,D42HE(),0);d42_cefc4c->hack734ae0(entity,other.get9b6570()->pos45a4a0(),false);}
     refresh827950();d42_cefc4c->playerActionFinish(17,100);return;
    }else if(other.get9b6570()->target45a760()==0&&status==0&&other.get9b6570()->effect45ac40(57)){
     D42HE from=entity,target=other;bool done=false;bool event=rng.chance(33);
     int score2=event?d42_b985e0[target.get9b6570()->def9b4350()->indexB0][from.get9b6570()->def9b4350()->kind]:d42_b98480[target.get9b6570()->def9b4350()->indexB0][from.get9b6570()->def9b4350()->kind];score2=(int)(score2*0.5);
     if(!rng.chance(score2)){D42_MSG(797,0,from,target,0);}
     else{
      D42HE x=d42_cefc4c->other7345f0(from,target,false);
      if(x.valid9b7230()){D42_MSG(798,0,x,D42HE(),&target.get9b6570()->pos45a4a0());}
      else if(event){D42_MSG(799,&string("assimilated"),target,from,0);if(d42_b95758[target.get9b6570()->def9b4350()->category])do{d42_phrase5141b0(141,&target.get9b6570()->name416f40(),0,0,D42HE(),0);}while(false);int group=1;target.get9b6570()->level5fd900(1,d42_d2191c.random40c130());target.get9b6570()->faction5dc780(d42_cefc4c->group463890(group),true);d42_effect4569a0(40,from,D42HE(),D42HP(),D42HI(),0,0,from.get9b6570()->effects45ad90(),from,D42HP(),D42HI(),0);done=true;}
      else{d42_effect4569a0(39,from,D42HE(),D42HP(),D42HI(),0,0,from.get9b6570()->effects45ad90(),from,D42HP(),D42HI(),0);D42_MSG(799,&string("rebooting"),target,from,0);target.get9b6570()->level5fd900(1,d42_d2191c.random40c130());done=true;}
     }
     d42_cefc4c->hack734ae0(from,target.get9b6570()->pos45a4a0(),done);
     if(d42_d1e860.flag46f4b0(1)){if(!d42_cefc4c->member4638e0(3,other.get9b6570()->group45a3f0().get9b7250()->kind9b4350()))d42_cf45d8.suspicion77ee70(-20.0f,14,D42HE());else d42_cf45d8.suspicion77ee70(50.0f,13,D42HE());}
     refresh827950();d42_cefc4c->playerActionFinish(17,200);return;
    }
   }
  }
  d42_cec0f4->add7b1880(new D42Phrase(232,0,0,0,D42HE(),D42HE()));return;
 }
 int cost=0;for(int i=0;i<slots.size9b9260();i++)cost+=slots.at9b81f0(i).get9b65b0()->energy5788e0();
 if(!d42_cefc4c->free464370()&&cost>entity.get9b6570()->energy45a8d0()){d42_message7b1750(0,&d42_int4051f0(cost),0,0,entity,D42HE(),0);d42_cefaa8->show793450(50,true,0,false,false);return;}
 cost=0;for(int i=0;i<slots.size9b9260();i++)cost+=slots.at9b81f0(i).get9b65b0()->matter5789c0();
 if(!d42_cefc4c->free464370()&&cost>entity.get9b6570()->matter45a920()){d42_message7b1750(1,&d42_int4051f0(cost),0,0,entity,D42HE(),0);d42_cf45d8.achieve77fbc0(53);d42_cefaa8->show793450(53,true,0,false,false);return;}
 cost=d42_cefc4c->player4630f0().get9b6570()->heat5d7320(&slots,false);bool hit=false;
 for(int i=0;i<slots.size9b9260();i++)if(d42_between9daf80(20,slots.at9b81f0(i).get9b65b0()->category457880(),30)&&(*d42_cfd44c.at9ced70(entity.get9b6570()->point45a4c0()))->cave66af50())hit=true;
 if(hit){if(d42_caed20<caveLast+500)return;else if(d42_caed20>caveStart+10000){caveStart=d42_caed20;caveLast=d42_caed20;d42_sound4541b0(60,0,0);d42_cec0f4->add7b1880(new D42Phrase(167,0,0,0,D42HE(),D42HE()));return;}}
 if(!multi){
  if(markers.size9b9260()>=2){
   if(d42_range9e28f0(markers,4,0,markers.size9b9260()-2)){
    if(d42_caed20<warnLast+500)return;else if(d42_caed20>warnStart+10000){warnStart=d42_caed20;warnLast=d42_caed20;d42_sound4541b0(60,0,0);d42_cec0f4->add7b1880(new D42Phrase(168,0,0,0,D42HE(),D42HE()));return;}
   }else if(d42_range9e28f0(markers,2,0,markers.size9b9260()-2)||d42_range9e28f0(markers,3,0,markers.size9b9260()-2)){
    if(d42_caed20<warnLast+500)return;else if(d42_caed20>warnStart+10000){warnStart=d42_caed20;warnLast=d42_caed20;d42_sound4541b0(60,0,0);d42_cec0f4->add7b1880(new D42Phrase(170,0,0,0,D42HE(),D42HE()));return;}
   }
  }
 }else if(markers.size9b9260()>=2){
  for(int i=1;i<markers.size9b9260()-1;i++)if(markers.at9b81f0(i)==4&&(*d42_cfd44c.at9ced70(locations.at9b81f0(i)))->entity45d250().valid9b7230()&&(*d42_cfd44c.at9ced70(locations.at9b81f0(i)))->entity45d250().get9b6570()->friendly45aaa0(d42_cefc4c->player4630f0())){
   if(d42_caed20<warnLast+500)return;else if(d42_caed20>warnStart+10000){warnStart=d42_caed20;warnLast=d42_caed20;d42_sound4541b0(60,0,0);d42_cec0f4->add7b1880(new D42Phrase(169,0,0,0,D42HE(),D42HE()));return;}
  }
 }
 d42_d2c658.add4729d0(380,cost,d42_b9641e,-1);
 if(!d42_cefa94->hidden41a6e0()&&(*d42_cfd44c.at9ced70(target))->entity45d250().valid9b7230()&&(*d42_cfd44c.at9ced70(target))->entity45d250().ne9b6510(d42_d1da3c))d42_d1da3c=(*d42_cfd44c.at9ced70(target))->entity45d250();
 d42_cefaa8->show793450(54,!multi,0,false,false);
 if(!paths.empty9b86e0()){d42_d1da10=paths;d42_d1da20=target;d42_d1da28=origin;d42_d1da30=d42_cefc4c->player4630f0().get9b6570()->pos45a4a0();}
 if(d42_cf45d8.flag46de40(59)&&d42_adj4373c0(entity.get9b6570()->pos45a4a0(),target)&&(*d42_cfd44c.at9ced70(target))->entity45d250().valid9b7230()&&(*d42_cfd44c.at9ced70(target))->entity45d250().get9b6570()->hostile45aa70(entity))for(int i=0;i<slots.size9b9260();i++)if(slots.at9b81f0(i).get9b65b0()->category457880()==24){d42_cf45d8.achieve77fbc0(59);break;}
 if(d42_d28e7a&&d42_d1d9c0.type==5)d42_d1d9c0.type=entity.get9b6570()->rating5df740(0);
 int time;d42_cefc4c->add777a20(d42_cefaa8->create7930e0(new D42Shoot(entity,1,target,origin,&time,paths,false,D42HI())));
 d42_d2c658.add4729d0(378,1,d42_b9641f,-1);d42_d2c658.add4729d0(379,slots.size9b9260(),d42_b96422,-1);refresh827950();d42_cefc4c->playerActionFinish(9,time);
}
}
