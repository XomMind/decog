#include <string>
using std::string;
// NOTE: private partial ABI views; all allocating helpers retain ordinary exception contracts.
struct LB26P{int x,y;LB26P(const LB26P&,const LB26P&)throw();};
struct LB26Entity;struct LB26Item;struct LB26Prop;struct LB26Group;
struct LB26H{int id;LB26H()throw();LB26Entity*get9b6570()const throw();bool valid9b7230()const throw();bool ne9b6510(LB26H)const throw();};
struct LB26HI{int id;LB26HI()throw();LB26Item*get9b65b0()const throw();bool valid9b7230()const throw();bool null9b65d0()const throw();};
struct LB26HP{int id;LB26HP()throw();LB26Prop*get9b64f0()const throw();bool valid9b7230()const throw();};
struct LB26HG{int id;LB26Group*get9b7250()const throw();};struct LB26Group{int value9b4350()const throw();};
struct LB26HIList{LB26HI*begin,*end,*capacity;std::allocator<LB26HI>allocator;LB26HIList();~LB26HIList();bool empty9b86e0()const throw();unsigned size9b9260()const throw();LB26HI&at9b81f0(unsigned)throw();};
struct LB26Ints{int*begin,*end,*capacity;std::allocator<int>allocator;};struct LB26Def{char p[0x148];LB26Ints features;};struct LB26Defs{LB26Def*&at9b81f0(unsigned)throw();};extern LB26Defs lb26_d25de0;
struct LB26AI{void reset459640();unsigned state458f30()throw();};
struct LB26Entity{const LB26P&pos45a4a0()throw();LB26P pos45a4c0()throw();LB26HI effect5d2380(int);bool has5d2a00(int);int max5ca260()throw();int value490840()throw();void heal5de870(int,bool);int slot5cc190(int)throw();LB26HI take5cc460(int,int);LB26AI*ai45b590()throw();LB26HG group45a3f0()throw();int type45a2a0()throw();int size45a360()throw();bool hostile45aa70(LB26H)throw();unsigned items5cb8b0(LB26HIList*);int unequip642940(LB26HI,bool,bool,bool,int);LB26HI weapon5d5d40();};
struct LB26Item{bool equip57a190(LB26H,int,bool,bool);string name571db0(bool,bool);int max457c80()throw();int value9b6bf0()throw();int repair458360(int);int value577790();bool disposable457e90()throw();void remove57dbe0(bool,bool,int,bool);};
struct LB26Prop{bool pass65e1d0(LB26H)throw();};struct LB26Cell{LB26H entity45d250()throw();bool solid4550b0()throw();LB26HP prop45d550()throw();};struct LB26Grid{bool contains9b43b0(const LB26P&)throw();LB26Cell**at9ced70(const LB26P&)throw();};extern LB26Grid lb26_cfd44c;extern LB26P lb26_d015d8[];
struct LB26Map{char p[0x66c];LB26H player;int find4638e0(int,int);void playerActionFinish(int,int);void drop464870(LB26HI);};extern LB26Map*lb26_cefc4c;
struct LB26Location{int definition;};extern LB26Location*lb26_cf4700;
struct LB26Player{void add77ee70(float,int,LB26H);};extern LB26Player lb26_cf45d8;
struct LB26Data{bool option46f4b0(int)throw();};extern LB26Data lb26_d1e860;
struct LB26Dialog{void update8758d0(bool);};extern LB26Dialog*lb26_cec058;struct LB26Log{void end7b4f10();};extern LB26Log*lb26_cec0b4;
struct LB26CMap{bool action824020(LB26H,int);int service806420(LB26H,LB26HI*,int*);bool first805de0(LB26H,bool);bool second8062d0();bool third8231f0(LB26H,const LB26P&);bool last824c40(LB26H,const LB26P&,int,bool);};
bool lb26_has9db330(LB26Ints&,int);int lb26_min9cdb30(int,int);void lb26_erase9d6440(LB26HIList&,int&);LB26HI lb26_random9dafb0(LB26HIList&);
bool lb26_route5111e0(int,const string*,const string*,const string*,LB26H,LB26H,const LB26P*,bool);
extern const float lb26_bba1dc,lb26_bba054,lb26_ba8520,lb26_ba851c,lb26_ba8528,lb26_ba8524;
#define LB26_MSG(ID,NAME,A,B,PT) do{if(lb26_route5111e0(ID,NAME,0,0,A,B,PT,false))lb26_cec058->update8758d0(true);lb26_cec0b4->end7b4f10();}while(false)
bool LB26CMap::action824020(LB26H entity,int dir){
 const LB26P&first=entity.get9b6570()->pos45a4a0();LB26P p(first,lb26_d015d8[dir]);
 if(lb26_cfd44c.contains9b43b0(p)){
  LB26H pos=(*lb26_cfd44c.at9ced70(p))->entity45d250();
  if(lb26_cf4700&&pos.valid9b7230()&&pos.ne9b6510(entity)){
   if(lb26_has9db330(lb26_d25de0.at9b81f0(lb26_cf4700->definition)->features,8)&&lb26_cefc4c->player.get9b6570()->effect5d2380(162).valid9b7230()){
    LB26HI item;int slot;int type=service806420(pos,&item,&slot);int current=0;LB26H count=pos;
    switch(type){int a,n;break;
    case 1:n=(int)(count.get9b6570()->max5ca260()*lb26_bba1dc)-count.get9b6570()->value490840();if(n>0){count.get9b6570()->heal5de870(n,false);LB26_MSG(785,0,entity,count,0);}current=100;break;
    case 3:{LB26HI x=entity.get9b6570()->take5cc460(slot,pos.get9b6570()->slot5cc190(slot));x.get9b65b0()->equip57a190(count,slot,true,false);if(slot==3)count.get9b6570()->ai45b590()->reset459640();LB26_MSG(784,&x.get9b65b0()->name571db0(false,false),entity,count,0);current=100;break;}
    case 4:a=(int)(item.get9b65b0()->max457c80()*lb26_bba054)-item.get9b65b0()->value9b6bf0();if(a>0){int num=lb26_min9cdb30(a,item.get9b65b0()->max457c80()-item.get9b65b0()->value9b6bf0());item.get9b65b0()->repair458360(num);LB26_MSG(786,&item.get9b65b0()->name571db0(false,false),entity,LB26H(),0);}current=100;break;
    }
    if(current){if(!lb26_cefc4c->find4638e0(3,count.get9b6570()->group45a3f0().get9b7250()->value9b4350()))lb26_cf45d8.add77ee70(lb26_ba8520,8,LB26H());else lb26_cf45d8.add77ee70(lb26_ba851c,7,LB26H());lb26_cefc4c->playerActionFinish(17,current);return true;}
   }
   if(lb26_has9db330(lb26_d25de0.at9b81f0(lb26_cf4700->definition)->features,9)&&lb26_cefc4c->player.get9b6570()->has5d2a00(162)&&lb26_cefc4c->player.get9b6570()->effect5d2380(162).null9b65d0()&&pos.get9b6570()->type45a2a0()==1&&pos.get9b6570()->size45a360()==1&&pos.get9b6570()->hostile45aa70(lb26_cefc4c->player)&&!pos.get9b6570()->ai45b590()->state458f30()){
    LB26HIList list;pos.get9b6570()->items5cb8b0(&list);
    if(!list.empty9b86e0()){
     int first=-1;for(unsigned i=0;i<list.size9b9260();i++)if(list.at9b81f0(i).get9b65b0()->value577790()>first)first=list.at9b81f0(i).get9b65b0()->value577790();
     for(int j=0;j<list.size9b9260();j++)if(list.at9b81f0(j).get9b65b0()->value577790()!=first)lb26_erase9d6440(list,j);
     LB26HI item=lb26_random9dafb0(list);LB26_MSG(787,&item.get9b65b0()->name571db0(false,false),lb26_cefc4c->player,pos,0);
     if(item.get9b65b0()->disposable457e90()){LB26_MSG(69,&item.get9b65b0()->name571db0(false,false),lb26_cefc4c->player,LB26H(),&pos.get9b6570()->pos45a4c0());item.get9b65b0()->remove57dbe0(false,true,1,true);}
     else{pos.get9b6570()->unequip642940(item,false,false,false,0);lb26_cefc4c->drop464870(item);}
     if(lb26_d1e860.option46f4b0(1)){if(!lb26_cefc4c->find4638e0(3,pos.get9b6570()->group45a3f0().get9b7250()->value9b4350()))lb26_cf45d8.add77ee70(lb26_ba8528,10,LB26H());else lb26_cf45d8.add77ee70(lb26_ba8524,9,LB26H());}
     lb26_cefc4c->playerActionFinish(17,100);return true;
    }
   }
  }
  if(entity.get9b6570()->weapon5d5d40().valid9b7230()&&((pos.valid9b7230()&&pos.ne9b6510(entity))||!(*lb26_cfd44c.at9ced70(p))->solid4550b0()||((*lb26_cfd44c.at9ced70(p))->prop45d550().valid9b7230()&&!(*lb26_cfd44c.at9ced70(p))->prop45d550().get9b64f0()->pass65e1d0(LB26H())))){
   if(first805de0(entity,false))return true;if(second8062d0())return true;third8231f0(entity,p);return true;
  }else{
   // AGENTS.md register-allocation idiom: this constant branch emits zero code.
   // The equivalent ordinary else scopes retain an eight-instruction register-only DIFF.
   if(false){}if(last824c40(entity,p,dir,false))return true;}
 }
 return false;
}
