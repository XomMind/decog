#include <string>
using std::string;
struct LA16Point{int x,y;LA16Point();LA16Point(int) throw();LA16Point(int,int) throw();LA16Point(const LA16Point&) throw();void assign46ca50(const LA16Point&) throw();};
struct LA16Area{int left,top,right,bottom;LA16Area() throw();void random40be30(LA16Point*) throw();};
struct LA16Entity;struct LA16Item;struct LA16RecordH{int id;};
struct LA16H{int id;LA16H();LA16Entity*get9b6570()const throw();bool valid9b7230()const throw();bool different9b6510(LA16H)const throw();};
struct LA16HI{int id;LA16HI();LA16Item*get9b65b0()const throw();bool valid9b7230()const throw();bool null9b65d0()const throw();bool different9b6510(LA16HI)const throw();};
struct LA16HP{int id;LA16HP();};
struct LA16ItemDefInfo{char pad[0x2c];int category;};struct LA16ItemDef{char pad[0x1a0];LA16ItemDefInfo *info;};
struct LA16Item{bool ready5790e0() throw();bool active457cf0() throw();bool disabled457d10() throw();bool blocked415ee0() throw();int turn44ab90() throw();int special457f90() throw();int effect457be0(int) throw();string name571db0(bool,bool);int category457880() throw();int kind4578a0() throw();int energy5788e0() throw();int matter5789c0() throw();int range4580a0() throw();LA16ItemDef*def9b4350() throw();void active5791a0(bool) throw();};
struct LA16Items{int a,b,c,d;LA16Items();~LA16Items();unsigned size9b9260()const throw();LA16HI&at9b81f0(unsigned) throw();bool empty9b86e0()const throw();void push9b80b0(const LA16HI&);};
LA16HI la16_random9dafb0(LA16Items&);
struct LA16Entity{char pad0[4];LA16H self;char pad8[0x88];int energy,matter;char pad98[0x9c];LA16Items items;LA16HI item5d2380(int) throw();const LA16Point&position45a4a0() throw();LA16Point position45a4c0() throw();bool disallowed5c7f70() throw();bool friendly45aaa0(LA16H) throw();void refresh45b0b0() throw();bool fire63a3e0(bool,LA16HI);};
struct LA16Weighted{char data[0x24];LA16Weighted();~LA16Weighted();bool contains9ba520(const LA16H*) throw();void add9ba0d0(LA16H,int);int size9b81d0() throw();LA16H&pick9ba470() throw();};
struct LA16Cell{LA16H entity45d250() throw();};struct LA16Grid{LA16Cell**at9ceda0(int,int) throw();void rect9b4430(const LA16Point&,int,LA16Area*) throw();};extern LA16Grid la16_cfd44c;
struct LA16Part{void refresh890710(bool) throw();};struct LA16Parts{LA16Part*find894e70(LA16HI) throw();void activate8993e0(LA16Part*,bool) throw();};extern LA16Parts*la16_cec088;
struct LA16Map{int turn464270() throw();bool visible463380(int,int) throw();bool visible4633c0(const LA16Point&) throw();LA16RecordH add777a20(LA16RecordH);};extern LA16Map*la16_cefc4c;
struct LA16View{void bounds8051f0(LA16Point*,LA16Point*) throw();};extern LA16View*la16_cec054;
int la16_distance40a3f0(const LA16Point&,const LA16Point&) throw();bool la16_between9daf80(int,int,int) throw();bool la16_invalid63a2b0(const LA16Point&,const LA16Point&) throw();
struct LA16Children{int a,b,c,d;LA16Children();~LA16Children();};
struct LA16Shoot{char data[0x7c];LA16Shoot(LA16H,int,const LA16Point&,const LA16Point&,int*,LA16Children&,bool,LA16HI);};struct LA16Factory{LA16RecordH create7930e0(LA16Shoot*);};extern LA16Factory*la16_cefaa8;extern LA16Point la16_d2e20c;
struct LA16UI{void update8758d0(bool) throw();};extern LA16UI*la16_cec058;struct LA16Log{void end7b4f10() throw();};extern LA16Log*la16_cec0b4;
bool la16_route5111e0(int,const string*,const string*,const string*,LA16H,LA16HP,const LA16Point*,bool);
struct LA16Stats{bool add4729d0(unsigned,int,string,int);};extern LA16Stats la16_d2c658;struct LA16Player{void event77fbc0(int) throw();};extern LA16Player la16_cf45d8;extern bool la16_cefaef;extern int la16_cefaf4;
#define LA16_ROUTE(ID,TEXT) do{if(la16_route5111e0(ID,TEXT,0,0,self,LA16HP(),0,false))la16_cec058->update8758d0(true);la16_cec0b4->end7b4f10();}while(false)
bool LA16Entity::fire63a3e0(bool quiet,LA16HI selected){
 if(la16_cefaef&&la16_cefaf4)return false;
 LA16HI x;LA16Items right;
 if(selected.valid9b7230()){if(selected.get9b65b0()->ready5790e0())right.push9b80b0(selected);}
 else for(unsigned i=0;i<items.size9b9260();i++)if(items.at9b81f0(i).get9b65b0()->ready5790e0())right.push9b80b0(items.at9b81f0(i));
 if(right.empty9b86e0())return false;x=la16_random9dafb0(right);
 if(!x.get9b65b0()->active457cf0()){
  if(x.get9b65b0()->disabled457d10()||x.get9b65b0()->blocked415ee0()||x.get9b65b0()->turn44ab90()>la16_cefc4c->turn464270()||(x.get9b65b0()->special457f90()==158&&x.get9b65b0()->effect457be0(71)==-1))return false;
  LA16Part*p=la16_cec088->find894e70(x);la16_cec088->activate8993e0(p,false);
 }
 if(!quiet){LA16_ROUTE(selected.valid9b7230()?0x135:0x167,&x.get9b65b0()->name571db0(false,false));
  if(x.get9b65b0()->category457880()==24){LA16HI item=item5d2380(93);if(item.valid9b7230()){LA16_ROUTE(selected.valid9b7230()?0x136:0x168,&item.get9b65b0()->name571db0(false,false));return false;}}
 }
 if(x.get9b65b0()->energy5788e0()>energy||x.get9b65b0()->matter5789c0()>matter)return false;
 LA16Point destination(-1);LA16Weighted other;LA16Point first,value;la16_cec054->bounds8051f0(&first,&value);
 for(int y=first.y;y<value.y;y++)for(int z=first.x;z<value.x;z++){
  if(la16_cefc4c->visible463380(z,y)&&(*la16_cfd44c.at9ceda0(z,y))->entity45d250().valid9b7230()&&(*la16_cfd44c.at9ceda0(z,y))->entity45d250().different9b6510(self)&&!(*la16_cfd44c.at9ceda0(z,y))->entity45d250().get9b6570()->disallowed5c7f70()&&!other.contains9ba520(&(*la16_cfd44c.at9ceda0(z,y))->entity45d250())&&la16_distance40a3f0(position45a4a0(),LA16Point(z,y))<=x.get9b65b0()->range4580a0())other.add9ba0d0((*la16_cfd44c.at9ceda0(z,y))->entity45d250(),(*la16_cfd44c.at9ceda0(z,y))->entity45d250().get9b6570()->friendly45aaa0(self)?1:10);
 }
 if(other.size9b81d0())destination.assign46ca50(other.pick9ba470().get9b6570()->position45a4c0());
 else{
  LA16Point part(position45a4a0());int v=x.get9b65b0()->range4580a0();LA16Area p;la16_cfd44c.rect9b4430(part,v,&p);int a=0;
  do{p.random40be30(&destination);a++;}while((!la16_cefc4c->visible4633c0(destination)||!la16_between9daf80(1,la16_distance40a3f0(part,destination),v)||la16_invalid63a2b0(part,destination))&&a<100);
  if(a==100)return false;
 }
 LA16Items i;
 for(unsigned j=0;j<items.size9b9260();j++){
  if(items.at9b81f0(j).get9b65b0()->active457cf0()&&items.at9b81f0(j).get9b65b0()->kind4578a0()==3&&items.at9b81f0(j).get9b65b0()->category457880()<26&&items.at9b81f0(j).different9b6510(x)){
   i.push9b80b0(items.at9b81f0(j));items.at9b81f0(j).get9b65b0()->active5791a0(false);LA16Part*p=la16_cec088->find894e70(items.at9b81f0(j));if(p)p->refresh890710(false);
  }
 }
 refresh45b0b0();string name=x.get9b65b0()->name571db0(false,false);
 bool temp=x.get9b65b0()->category457880()==24&&x.get9b65b0()->def9b4350()->info&&x.get9b65b0()->def9b4350()->info->category==2;
 LA16Children base;int amount;
 la16_cefc4c->add777a20(la16_cefaa8->create7930e0(new LA16Shoot(self,1,destination,la16_d2e20c,&amount,base,true,LA16HI())));
 if(!quiet){LA16_ROUTE(selected.valid9b7230()?0x137:0x169,&name);if(selected.null9b65d0()){la16_d2c658.add4729d0(452,1,"",-1);la16_d2c658.add4729d0(461,1,"",-1);if(temp)la16_cf45d8.event77fbc0(24);}}
 for(unsigned j=0;j<i.size9b9260();j++){
  if(i.at9b81f0(j).get9b65b0()&&!i.at9b81f0(j).get9b65b0()->disabled457d10()&&!i.at9b81f0(j).get9b65b0()->blocked415ee0()&&la16_cefc4c->turn464270()>=i.at9b81f0(j).get9b65b0()->turn44ab90()){
   LA16Part*p=la16_cec088->find894e70(i.at9b81f0(j));la16_cec088->activate8993e0(p,false);if(p)p->refresh890710(false);
  }
 }
 return true;
}
