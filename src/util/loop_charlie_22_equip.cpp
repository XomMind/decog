#include <string>
#include <memory>
using std::string;
// NOTE: private partial retail layouts and actual address-named borrowed interfaces.
struct LC22P{int x,y;LC22P();bool adjacent409dd0(const LC22P&)throw();};struct LC22Entity;struct LC22Item;struct LC22Def;struct LC22Part;struct LC22FxDef;struct LC22Engine;struct LC22Owned;
struct LC22H{int id;LC22H()throw();LC22Entity*get9b6570()const throw();bool valid9b7230()const throw();};
struct LC22HI{int id;LC22HI()throw();LC22Item*get9b65b0()const throw();bool valid9b7230()const throw();bool ne9b6510(LC22HI)const throw();};
template<class T>struct LC22Vec{T*first,*last,*capacity;std::allocator<T>alloc;LC22Vec();~LC22Vec();T&at9b81f0(unsigned)throw();};
struct LC22Def{char p0[0x9c];int size;};struct LC22ItemDef{char p0[0x1ac];unsigned char needsConfirm;};struct LC22AI{void follow5b2f80(LC22H,int);};
struct LC22Entity{int check5db5f0(LC22HI,bool,bool,bool);const LC22P&pos45a4a0()throw();int effect639530(int,int);LC22AI*ai45b590()throw();const string&name416f40()throw();unsigned inventory5cb8b0(LC22Vec<LC22HI>*);int first5cb760();int second5cb7f0();int matter5cb7a0();int energy45a8d0()throw();int matter45a920()throw();int mode45a810()throw();unsigned items5cb830(LC22Vec<LC22HI>*);int activate6421a0(bool);int unequip642940(LC22HI,bool,bool,bool,int);int equip6430b0(LC22HI,bool,int);bool usable5dc680(LC22HI);bool active5cd220(LC22HI);};
struct LC22Item{int has457b70(int);int value457be0(int);string name571db0(bool,bool);void remove57dbe0(bool,bool,int,bool);LC22ItemDef*def9b4350()throw();bool equip57a190(LC22H,int,bool,bool);unsigned char flag415ee0()throw();int index457820()throw();int type44aec0()throw();int subtype4578a0()throw();int limit4578c0()throw();};
struct LC22Map{LC22H player4630f0()throw();bool nearby71c150(const LC22P&,LC22P&,int);LC22H place6c58c0(LC22Def*,const LC22P&,int,bool,int,int,bool);bool visible4631f0(LC22H);void playerActionFinish(int,int);};extern LC22Map*lc22_cefc4c;extern LC22Vec<LC22Def*>lc22_d25de0;
struct LC22Effect{void init503b20(LC22Engine*,LC22FxDef*,const LC22P&,const LC22P&,const LC22P*,const LC22P*,LC22Owned*,int,LC22Effect*);};struct LC22Engine{LC22Effect*acquire508610();};extern LC22Engine*lc22_cefc50;extern LC22P lc22_d2e20c;
struct LC22Parts{char p0[0x160];LC22HI confirmItem;unsigned confirmTick;char p168[0x178-0x168];LC22HI activeItem;unsigned activeTick;void confirm4a9cf0(LC22HI);LC22Part*part894e70(LC22HI);void select4a9c90(LC22Part*);bool swap89c350(LC22HI,int);void enable8993e0(LC22Part*,bool);};extern LC22Parts*lc22_cec088;
struct LC22Dialog{void update8758d0(bool);};extern LC22Dialog*lc22_cec058;struct LC22Log{void end7b4f10();};extern LC22Log*lc22_cec0b4;struct LC22Factory{bool show793450(int,bool,const string*,bool,bool);};extern LC22Factory*lc22_cefaa8;
extern unsigned char lc22_d25450,lc22_d28e5d,lc22_d28d27,lc22_d28fa5;extern unsigned lc22_caed20;extern int lc22_d28e1c,lc22_cf473c,lc22_cefc68,lc22_cefc6c,lc22_cf496c;extern const int lc22_b95fbc,lc22_b95fb0;extern string gameStrings_d293c0[];extern LC22Vec<int>lc22_cf4830;
int lc22_index9d7b80(LC22Vec<LC22Def*>&,const string&);bool lc22_lookup9d7980(const string&,LC22FxDef**);LC22HI lc22_select4fd9e0(LC22HI,LC22Vec<LC22HI>&,bool);bool lc22_remove9d2f00(LC22Vec<LC22HI>&,LC22HI);string intToString(int);void logWarning(string,string);
void lc22_warn7b1750(int,const string*,const string*,const string*,LC22H,LC22H,const LC22P*);bool lc22_route5111e0(int,const string*,const string*,const string*,LC22H,LC22H,const LC22P*,bool);void lc22_phrase5141b0(int,const string*,const string*,const string*,LC22H,const LC22P*);
#define LC22_MSG(ID,TEXT,E) do{if(lc22_route5111e0(ID,TEXT,0,0,E,LC22H(),0,false))lc22_cec058->update8758d0(true);lc22_cec0b4->end7b4f10();}while(false)
struct LC22Inventory{bool equip8a3f20(LC22HI,bool,int,bool);int select8a4ec0(LC22HI,bool);};
bool LC22Inventory::equip8a3f20(LC22HI item,bool active,int slot,bool fast){
 LC22H x2=lc22_cefc4c->player4630f0();int count=x2.get9b6570()->check5db5f0(item,false,false,false);
 if(count==21){lc22_warn7b1750(8,0,0,0,x2,LC22H(),0);return true;}
 if(count==22){lc22_warn7b1750(9,0,0,0,x2,LC22H(),0);return true;}
 if(count==23){lc22_warn7b1750(10,0,0,0,x2,LC22H(),0);return true;}
 if(count==24){lc22_warn7b1750(11,&string(gameStrings_d293c0[lc22_d28e1c]),0,0,x2,LC22H(),0);return true;}
 if(count==25){lc22_warn7b1750(12,0,0,0,x2,LC22H(),0);return true;}
 if(lc22_d25450&&item.get9b65b0()->has457b70(130)){
  LC22Def*def=lc22_d25de0.at9b81f0(lc22_index9d7b80(lc22_d25de0,item.get9b65b0()->value457be0(130)==2?"Greater Item Mimic":"Item Mimic"));LC22P pos;
  if(lc22_cefc4c->nearby71c150(x2.get9b6570()->pos45a4a0(),pos,def->size)&&pos.adjacent409dd0(x2.get9b6570()->pos45a4a0())){
   LC22H spawned=lc22_cefc4c->place6c58c0(def,pos,3,false,34,14,false);
   if(spawned.valid9b7230()){
    spawned.get9b6570()->effect639530(58,1);spawned.get9b6570()->ai45b590()->follow5b2f80(x2,0);
    if(lc22_cefc4c->visible4631f0(spawned)){LC22FxDef*effect;if(lc22_lookup9d7980("Xom_Part_Mimic_Emerge",&effect))lc22_cefc50->acquire508610()->init503b20(lc22_cefc50,effect,spawned.get9b6570()->pos45a4a0(),lc22_d2e20c,0,0,0,9,0);}
    LC22_MSG(236,&item.get9b65b0()->name571db0(false,false),spawned);
    do{lc22_phrase5141b0(180,&item.get9b65b0()->name571db0(false,false),&spawned.get9b6570()->name416f40(),0,spawned,0);}while(false);
    item.get9b65b0()->remove57dbe0(true,false,1,true);return true;
   }
  }
 }
 int current=0;
 if((count==17||count==19)&&!lc22_cf473c){
  LC22Vec<LC22HI>vec;x2.get9b6570()->inventory5cb8b0(&vec);LC22HI score=lc22_select4fd9e0(item,vec,true);
  if(score.valid9b7230()){
   int value=x2.get9b6570()->first5cb760();int x=x2.get9b6570()->second5cb7f0();int col=x2.get9b6570()->matter5cb7a0();
   if(x2.get9b6570()->energy45a8d0()<value+x){lc22_cefc68=value+x;count=1;}
   else if(x2.get9b6570()->matter45a920()<col){lc22_cefc6c=col;count=20;}
   else{
    count=0;
    if((score.get9b65b0()->def9b4350()->needsConfirm||score.get9b65b0()->has457b70(110))&&(score.ne9b6510(lc22_cec088->confirmItem)||lc22_caed20>lc22_cec088->confirmTick+8000)&&!lc22_d28e5d){lc22_cec088->confirm4a9cf0(score);lc22_warn7b1750(17,&score.get9b65b0()->name571db0(false,false),0,0,x2,LC22H(),0);return true;}
    bool changed=false;if(active&&!x2.get9b6570()->mode45a810()){lc22_cf496c++;changed=true;}
    item.get9b65b0()->equip57a190(x2,4,false,false);lc22_cec088->select4a9c90(lc22_cec088->part894e70(score));lc22_cec088->swap89c350(item,32);
    if(changed){lc22_cf496c--;if(score.get9b65b0()){
     LC22Vec<LC22HI>available;x2.get9b6570()->items5cb830(&available);lc22_remove9d2f00(available,score);LC22HI replacement=lc22_select4fd9e0(score,available,true);if(replacement.valid9b7230())score=replacement;select8a4ec0(score,false);
    }}return true;
   }
  }
 }
 switch(count){
 case 0:{
  if(active){LC22_MSG(0,&item.get9b65b0()->name571db0(false,false),x2);x2.get9b6570()->activate6421a0(true);
   if(item.get9b65b0()->flag415ee0()&&lc22_cf4830.at9b81f0(item.get9b65b0()->index457820())&&(item.ne9b6510(lc22_cec088->activeItem)||lc22_caed20>lc22_cec088->activeTick+8000)){x2.get9b6570()->unequip642940(item,true,false,false,0);return true;}
  }
  lc22_warn7b1750(34,&item.get9b65b0()->name571db0(false,false),0,0,x2,LC22H(),0);int amount=x2.get9b6570()->equip6430b0(item,true,slot);
  if(lc22_d28d27&&item.get9b65b0()&&item.get9b65b0()->type44aec0()<=3&&x2.get9b6570()->usable5dc680(item)){
   if(!(lc22_d28fa5&&item.get9b65b0()->subtype4578a0()==1)||(item.get9b65b0()->subtype4578a0()==1&&!x2.get9b6570()->active5cd220(item))){LC22Part*part=lc22_cec088->part894e70(item);if(!part){logWarning("CInventory::attemptEquip()","part not found for auto-activation");return true;}lc22_cec088->enable8993e0(part,false);}
  }
  if(fast)amount=lc22_b95fbc;else if(active)amount=lc22_b95fb0;
  lc22_cefc4c->playerActionFinish(fast?7:active?4:5,amount+current);break;}
 case 15:lc22_warn7b1750(31,0,0,0,x2,LC22H(),0);break;
 case 16:lc22_warn7b1750(231,0,0,0,x2,LC22H(),0);break;
 case 17:lc22_warn7b1750(32,&intToString(item.get9b65b0()->limit4578c0()),0,0,x2,LC22H(),0);break;
 case 18:lc22_warn7b1750(115,0,0,0,x2,LC22H(),0);break;
 case 19:if(active)return false;else lc22_warn7b1750(33,0,0,0,x2,LC22H(),0);break;
 case 1:lc22_warn7b1750(0,&intToString(lc22_cefc68),0,0,x2,LC22H(),0);lc22_cefaa8->show793450(50,true,0,false,false);break;
 case 20:lc22_warn7b1750(1,&intToString(lc22_cefc6c),0,0,x2,LC22H(),0);lc22_cefaa8->show793450(53,true,0,false,false);break;
 }
 return true;
}
