#include <string>
#include <stdio.h>
using std::string;
// NOTE: private partial ABI views; vector fields own native backing storage only.
struct LB23Item;struct LB23Entity;struct LB23AI;struct LB23Items;
struct LB23P{int x,y;int random40c130()throw();int clamp40c270(int)throw();};struct LB23Area{int a,b,c,d;LB23Area()throw();};
struct LB23H{int id;LB23H()throw();LB23Entity*get9b6570()const throw();bool null9b65d0()const throw();bool valid9b7230()const throw();bool equal9b78e0(LB23H)const throw();};
struct LB23HP{int id;LB23HP()throw();};struct LB23HI{int id;LB23HI()throw();LB23Item*get9b65b0()const throw();};
struct LB23Hs{int a,b,c,d;LB23Hs();LB23Hs(const LB23Hs&);~LB23Hs();unsigned size9b9260()const throw();LB23H&at9b81f0(unsigned)throw();void push9b80b0(const LB23H&);const LB23H&back9b6540()const throw();LB23H&front9b7060()throw();bool empty9b86e0()const throw();};
struct LB23Ints{int&at9b81f0(unsigned)throw();};struct LB23Items{unsigned size9b9260()const throw();LB23HI&at9b81f0(unsigned)throw();};
struct LB23Def{int id;char p4[4];string name;char p24[0x44-0x24];int weapon,kind,size;char p50[0x44];int status;char p98[0xd4-0x98];int statd4;char pd8[0xf0-0xd8];int special,specialValue;char pf8[0x1af-0xf8];bool flag;int*stat456da0(int)throw();};
struct LB23Item{int p0;LB23HI self;LB23Def*def;int state;LB23H owner;char p14[0x34-0x14];int installed;
 void remove57dbe0(bool,bool,int,bool);int category4578a0()throw();int rating457920()throw();bool flag457cf0()throw();bool flag458220()throw();void detach579f50(bool,bool);int max457c80()throw();void integrity450460(int)throw();string name571db0(bool,bool);bool flag458180()throw();int kind457f90()throw();int type44aec0()throw();int integrity9b6bf0()throw();void damage458310(int)throw();bool queue571d70()throw();};
struct LB23AI{void area459470(const LB23Area&)throw();void follow5b2f80(LB23H,int);};struct LB23Entity{bool player5c7600()throw();int integrity490840()throw();void mode5dcc70(int,bool);LB23AI*ai45b590()throw();int rating5d15a0(int)throw();LB23Items*items45ab00()throw();bool flag5d4100()throw();};
struct LB23Map{int turn464270()throw();LB23H player4630f0()throw();LB23H companion463110()throw();int companion463e50()throw();bool flag714a50();LB23Hs*followers463d80()throw();void removeFollower463dc0(LB23H);LB23HI give6c52b0(const string&,LB23H,bool,bool);LB23HI create6c51d0(LB23Def*,LB23H,bool,bool);void update72ea10();void remove464fd0(LB23HI);void remove4650c0(LB23HI);};extern LB23Map*lb23_cefc4c;
struct LB23Stats{bool add4729d0(unsigned,int,string,int);};extern LB23Stats lb23_d2c658;
struct LB23Rule{void update682420(int,int);};extern LB23Rule lb23_cf6428;
struct LB23Rec{int rating46ed20()throw();};struct LB23HR{int id;LB23Rec*get9b7910()const throw();};extern LB23HR lb23_d1e888;
struct LB23Player{bool companion780790()throw();};extern LB23Player lb23_cf45d8;
struct LB23Tracker{bool spawn7aa280(unsigned,bool,string);};struct LB23State{char p[0x30];LB23Tracker*tracker;};extern LB23State*lb23_cf4ac8;
struct LB23View{void select44e360(LB23HP)throw();};extern LB23View*lb23_cec054;
struct LB23Part{void draw4a8e70(bool);};struct LB23Parts{void removed8979b0(LB23HI,bool,int);LB23Part*find894e70(LB23HI);void use8993e0(LB23Part*,bool);};extern LB23Parts*lb23_cec088;
struct LB23Inventory{void reopen8a2ce0(int,LB23HI);};extern LB23Inventory*lb23_cec08c;
struct LB23UI{void update8758d0(bool);};struct LB23Log{void end7b4f10()throw();};extern LB23UI*lb23_cec058;extern LB23Log*lb23_cec0b4;
struct LB23Xom{bool enabled;int event69e700(int,int,float);};extern LB23Xom lb23_d25450;
struct LB23Queue{void remove672980(LB23HI);};extern LB23Queue lb23_d225a0;
struct LB23Pool{void remove9d05e0(LB23HI,bool);};extern LB23Pool lb23_d2a298;
struct LB23Grid{LB23Area area9b4400()throw();};extern LB23Grid lb23_cfd44c;
extern LB23Ints lb23_cf4b74,lb23_cf4a04;extern LB23Items lb23_d33d74;extern LB23P lb23_cefcfc,lb23_cf3a30[];
extern int lb23_cf4b70,lb23_cf4b84,lb23_d254c0,lb23_d254c4,lb23_ba3df8[][4],lb23_ba3ff8[];extern bool lb23_cefc5f,lb23_ba40f8[];extern unsigned lb23_c2ea48;
string lb23_chrono432d80();string lb23_int4051f0(int);int lb23_max(int,int)throw();void lb23_erase9d2f00(LB23Items&,LB23HI);
bool lb23_route5111e0(int,const string*,const string*,const string*,LB23H,LB23H,const LB23P*,bool);
#define LB23_MSG(ID,E) do{if(lb23_route5111e0(ID,0,0,0,E,LB23H(),0,false))lb23_cec058->update8758d0(true);lb23_cec0b4->end7b4f10();}while(false)
#define LB23_NAME(ID,H) do{if(lb23_route5111e0(ID,&H.get9b65b0()->name571db0(false,false),0,0,LB23H(),LB23H(),0,false))lb23_cec058->update8758d0(true);lb23_cec0b4->end7b4f10();}while(false)
void LB23Item::remove57dbe0(bool refresh,bool destroyed,int mode,bool scrap){
 if(installed==-1&&(owner.null9b65d0()||!owner.get9b6570()->player5c7600()||state!=4)){lb23_d2c658.add4729d0(157,1,"",-1);lb23_d2c658.add4729d0(def->flag?162:category4578a0()+158,1,"",-1);}
 if(destroyed&&owner.valid9b7230()){
  if(owner.get9b6570()->player5c7600()){
   lb23_d2c658.add4729d0(144,1,"",-1);lb23_d2c658.add4729d0(def->kind+145,1,"",-1);lb23_cf4b70++;lb23_cf4b74.at9b81f0(def->kind)++;lb23_cf4b84=lb23_cefc4c->turn464270();lb23_d2c658.add4729d0(149,lb23_cf4b70,"",-1);
   if(lb23_d25450.enabled)lb23_d254c0+=lb23_max(0,rating457920()+4-lb23_d1e888.get9b7910()->rating46ed20());lb23_cf6428.update682420(36,0);
  }else if(owner.equal9b78e0(lb23_cefc4c->companion463110())){lb23_d2c658.add4729d0(1100,1,"",-1);lb23_cf6428.update682420(36,0);}
 }
 switch(def->special){case 183:if(owner.equal9b78e0(lb23_cefc4c->player4630f0())&&state<=3){lb23_cec054->select44e360(LB23HP());remove(lb23_chrono432d80().c_str());LB23_MSG(279,lb23_cefc4c->player4630f0());}break;
 case 214:if(!lb23_cefc5f&&lb23_cefc4c->companion463e50()&&lb23_cf45d8.companion780790())lb23_cf4ac8->tracker->spawn7aa280((def->specialValue!=0)+13,false,"");break;}
 LB23H f=owner;int p=state;bool seen=flag457cf0();bool id=flag458220();
 if(lb23_d25450.enabled&&def->special==7)lb23_d254c4=-1;detach579f50(false,false);
 if(refresh&&f.equal9b78e0(lb23_cefc4c->player4630f0())){
  if(p==4){if(lb23_cec08c)lb23_cec08c->reopen8a2ce0(4,LB23HI());}else lb23_cec088->removed8979b0(self,false,mode);
  if(lb23_d25450.enabled&&lb23_d254c4>0){if(lb23_d254c4>=10&&lb23_cefc4c->flag714a50())lb23_d25450.event69e700(14,false,0.f);lb23_d254c4=0;}
 }
 lb23_erase9d2f00(lb23_d33d74,self);
 if(def->special==199&&f.valid9b7230()&&f.get9b6570()->player5c7600()){
  LB23Hs list(*lb23_cefc4c->followers463d80());LB23Hs seen;
  for(unsigned i=0;i<list.size9b9260();i++)if(list.at9b81f0(i).get9b6570()->integrity490840()>0){lb23_cefc4c->removeFollower463dc0(list.at9b81f0(i));list.at9b81f0(i).get9b6570()->mode5dcc70(2,true);seen.push9b80b0(list.at9b81f0(i));seen.back9b6540().get9b6570()->ai45b590()->area459470(lb23_cfd44c.area9b4400());}
  if(!seen.empty9b86e0()){
   int value;LB23H label=seen.front9b7060();int p=label.get9b6570()->rating5d15a0(0);
   for(unsigned i=1;i<seen.size9b9260();i++){value=seen.at9b81f0(i).get9b6570()->rating5d15a0(0);if(value>p){label=seen.at9b81f0(i);p=value;}}
   for(unsigned i=0;i<seen.size9b9260();i++)if(seen.at9b81f0(i).equal9b78e0(label))seen.at9b81f0(i).get9b6570()->ai45b590()->follow5b2f80(LB23H(),0);else seen.at9b81f0(i).get9b6570()->ai45b590()->follow5b2f80(label,0);
  }
 }
 if(def->special==211&&def->name=="Arm. Scrap Engine"&&destroyed&&f.valid9b7230()&&f.get9b6570()->player5c7600()){
  LB23HI pos=lb23_cefc4c->give6c52b0("Scrap Engine",f,true,false);pos.get9b65b0()->integrity450460(pos.get9b65b0()->max457c80()*40/100);LB23Part*area=lb23_cec088->find894e70(pos);if(area)area->draw4a8e70(true);LB23_NAME(285,pos);
 }
 if(def->status==2&&f.valid9b7230()&&f.get9b6570()->player5c7600()){
  if(def->size>1&&destroyed){
   LB23Def*n=def;int u=def->kind;int best=n->size;n->size--;float a=(float)n->size/best;
   for(int i=0;i<32;i++)if(lb23_ba3df8[i][u]&&lb23_ba40f8[i])switch(lb23_ba3ff8[i]){
    case 0:{int*num=n->stat456da0(i);*num=(int)(*num*a);*num=lb23_cf3a30[i].clamp40c270(*num);break;}
    case 1:{float*num=(float*)n->stat456da0(i);*num*=a;*num=(int)(*num/0.5)*0.5;*num=(float)lb23_cf3a30[i].clamp40c270((int)*num);break;}
   }
   if(u==1){if(n->weapon!=12&&n->weapon!=13)n->statd4=(int)(n->statd4*a);if(n->weapon==9)n->specialValue=n->size*5;}
   LB23HI value=lb23_cefc4c->create6c51d0(n,f,true,false);value.get9b65b0()->integrity450460((int)(value.get9b65b0()->max457c80()*a));LB23Part*current=lb23_cec088->find894e70(value);
   if(current){current->draw4a8e70(true);while(flag457cf0())lb23_cec088->use8993e0(current,false);if(seen)lb23_cec088->use8993e0(current,false);if(id&&flag458180())lb23_cec088->use8993e0(current,false);}
   LB23_NAME(285,value);
  }else if(scrap){
   LB23Items*items=f.get9b6570()->items45ab00();for(unsigned i=0;i<items->size9b9260();i++)if(items->at9b81f0(i).get9b65b0()->type44aec0()<=3&&items->at9b81f0(i).get9b65b0()->kind457f90()==211){
    LB23HI first=items->at9b81f0(i);int count=lb23_cefcfc.random40c130();
    if(count>=first.get9b65b0()->integrity9b6bf0()){LB23_NAME(287,first);first.get9b65b0()->remove57dbe0(true,true,1,true);}
    else{do{if(lb23_route5111e0(286,&first.get9b65b0()->name571db0(false,false),&lb23_int4051f0(count),0,LB23H(),LB23H(),0,false))lb23_cec058->update8758d0(true);lb23_cec0b4->end7b4f10();}while(false);first.get9b65b0()->damage458310(count);LB23Part*area=lb23_cec088->find894e70(first);if(area)area->draw4a8e70(true);}
    break;
   }
  }
 }
 if(f.equal9b78e0(lb23_cefc4c->player4630f0())&&lb23_cf4a04.at9b81f0(11)&&def->special==124&&def->name.find("Relay Coupler [NC]",0)!=lb23_c2ea48&&!f.get9b6570()->flag5d4100())lb23_cefc4c->update72ea10();
 lb23_cefc4c->remove464fd0(self);lb23_cefc4c->remove4650c0(self);if(queue571d70())lb23_d225a0.remove672980(self);lb23_d2a298.remove9d05e0(self,true);
}
