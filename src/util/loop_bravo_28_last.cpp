#include <string>
using std::string;
// NOTE: private partial layouts and borrowed native interfaces.
struct LB28P{int x,y;bool ne409bd0(const LB28P&)throw();LB28P&assign46ca50(const LB28P&)throw();};struct LB28Entity;struct LB28Prop;
struct LB28H{int id;LB28H()throw();LB28Entity*get9b6570()const throw();bool valid9b7230()const throw();bool null9b65d0()const throw();bool eq9b78e0(LB28H)const throw();bool ne9b6510(LB28H)const throw();};
struct LB28HI{int id;bool valid9b7230()const throw();};struct LB28HP{int id;bool valid9b7230()const throw();LB28Prop*get9b64f0()const throw();};
struct LB28Entity{bool blocked5d1280(bool);bool stopped5fdae0();const string&name45a280()throw();const string&baseName416f40()throw();bool emptySlot5cc7c0(int);bool canPossess5d7df0();int possessCost5d7e90();void possess5d7ef0();int moveType5d1390();LB28HI item5d2380(int);int ram5ff700(int,const LB28P&);void wall600970(int,const LB28P&);int value490840()throw();const LB28P&pos45a4a0()throw();int power6008b0();int speed5d15a0(bool);};
struct LB28Material{char p[0x30];int multiplier;};struct LB28Def{char p[0x60];LB28Material*material;char p64[0xb8-0x64];int multiplier;};
struct LB28Prop{bool pass65e1d0(LB28H);LB28Def*def9b8f00()throw();int armor45c630()throw();const string&name45c5b0()throw();};
struct LB28CellDef{char p[0x50];LB28Material*material;};struct LB28Cell{LB28H entity45d250()throw();LB28HP prop45d550()throw();bool solid4550b0()throw();bool machine45dcd0()throw();int armor66ae70()throw();const string&name45d140()throw();LB28CellDef*def9fcd80()throw();};struct LB28Grid{LB28Cell**at9ced70(const LB28P&)throw();};extern LB28Grid lb28_cfd44c;
struct LB28Phrase{const void*definition;string text;LB28Phrase(int,const string*,const string*,const string*,LB28H,LB28H);};struct LB28Interface{void add7b1880(LB28Phrase*);};extern LB28Interface*lb28_cec0f4;
struct LB28Data{string&text46f6d0(const string&);};extern LB28Data lb28_d1e860;int lb28_parse405610(const string&);string lb28_int4051f0(int);
struct LB28Map{void spend774390(int,int);};extern LB28Map*lb28_cefc4c;extern int lb28_cf462c,lb28_cf46f4;struct LB28Location;extern LB28Location*lb28_cf4700;extern unsigned lb28_caed20;
struct LB28Cinematic{void integrate9682e0(LB28H);};extern LB28Cinematic*lb28_cec138;
void lb28_warn7b1750(int,const string*,const string*,const string*,LB28H,LB28H,const LB28P*);void lb28_message49c610(int,LB28H,const string&,const LB28P*);int lb28_sound4541b0(unsigned,int,int);int lb28_max9cdb60(int,int)throw();extern int lb28_b95fd8;extern int lb28_b95fa0[];
struct LB28CMap{char p[0x55c];LB28H target;unsigned start,last;LB28P wallPoint;unsigned wallStart,wallLast;char p578[0x5c4-0x578];LB28H shell;unsigned shellStart;bool last824c40(LB28H,const LB28P&,int,bool);bool confirm805520(const LB28P&);bool first805de0(LB28H,bool);bool second8062d0();void enter825e00();};
bool LB28CMap::last824c40(LB28H entity,const LB28P&point,int direction,bool quiet){
 if(entity.get9b6570()->blocked5d1280(false)){lb28_cec0f4->add7b1880(new LB28Phrase(131,0,0,0,LB28H(),LB28H()));return false;}
 if(entity.get9b6570()->stopped5fdae0()){lb28_cefc4c->spend774390(14,lb28_b95fd8);return true;}
 int type=11;
 if(!quiet){
  if((*lb28_cfd44c.at9ced70(point))->entity45d250().valid9b7230()){
   LB28H current=(*lb28_cfd44c.at9ced70(point))->entity45d250();if(current.eq9b78e0(entity))return false;
   bool alive=current.get9b6570()->name45a280()=="Sigix Exoskeleton"&&lb28_parse405610(lb28_d1e860.text46f6d0("usedCoreResetMatrix_g"));
   if(alive&&!current.get9b6570()->emptySlot5cc7c0(1))alive=false;
   bool ai=false;if(lb28_cf462c==11)alive=false;
   if(alive){
    if(shell.null9b65d0()){lb28_message49c610(800,LB28H(),string("Sigix Exoskeleton opens, ready for integration override sequence."),0);lb28_sound4541b0(153,0,0);shell=current;shellStart=lb28_caed20;}
    else lb28_cec138->integrate9682e0(current);return true;
   }else if(target.null9b65d0()||target.ne9b6510(current)){
reset:target=current;start=lb28_caed20;last=lb28_caed20;
    if(lb28_cf462c==11&&!lb28_cf4700){
     if(!current.get9b6570()->canPossess5d7df0()){lb28_sound4541b0(60,0,0);lb28_warn7b1750(225,&current.get9b6570()->baseName416f40(),0,0,LB28H(),LB28H(),0);}
     else if(lb28_cf46f4<current.get9b6570()->possessCost5d7e90()){lb28_sound4541b0(60,0,0);lb28_warn7b1750(226,&lb28_int4051f0(current.get9b6570()->possessCost5d7e90()),0,0,LB28H(),LB28H(),0);}
     else{lb28_sound4541b0(318,0,0);lb28_warn7b1750(227,&lb28_int4051f0(current.get9b6570()->possessCost5d7e90()),&current.get9b6570()->baseName416f40(),0,LB28H(),LB28H(),0);}
    }else{
     lb28_sound4541b0(60,0,0);int s=entity.get9b6570()->moveType5d1390();
     if(s==0||(s==3&&entity.get9b6570()->item5d2380(118).valid9b7230()))lb28_cec0f4->add7b1880(new LB28Phrase(142,0,0,0,LB28H(),LB28H()));
     else if(s==1)lb28_cec0f4->add7b1880(new LB28Phrase(143,0,0,0,LB28H(),LB28H()));
     else lb28_cec0f4->add7b1880(new LB28Phrase(141,0,0,0,LB28H(),LB28H()));
    }return true;
   }else if(lb28_caed20<start+500)return true;
   else if(lb28_caed20>last+3000)goto reset;
   if(lb28_cf462c==11&&!lb28_cf4700&&current.get9b6570()->canPossess5d7df0()&&lb28_cf46f4>=current.get9b6570()->possessCost5d7e90()){current.get9b6570()->possess5d7ef0();return true;}
   else{
    if(confirm805520(point))return true;if(first805de0(entity,false))return true;if(second8062d0())return true;type=entity.get9b6570()->ram5ff700(direction,point);if(!entity.get9b6570()->value490840())return true;last=lb28_caed20;
    if((*lb28_cfd44c.at9ced70(entity.get9b6570()->pos45a4a0()))->machine45dcd0()){enter825e00();return true;}
   }
  }else if(!(*lb28_cfd44c.at9ced70(point))->solid4550b0()||((*lb28_cfd44c.at9ced70(point))->prop45d550().valid9b7230()&&!(*lb28_cfd44c.at9ced70(point))->prop45d550().get9b64f0()->pass65e1d0(entity))){
   if(wallPoint.x==-1||wallPoint.ne409bd0(point)){
wallReset:wallPoint.assign46ca50(point);wallStart=lb28_caed20;wallLast=lb28_caed20;lb28_sound4541b0(60,0,0);int num=entity.get9b6570()->power6008b0();
    if((*lb28_cfd44c.at9ced70(point))->prop45d550().valid9b7230()&&!(*lb28_cfd44c.at9ced70(point))->prop45d550().get9b64f0()->pass65e1d0(entity)){
     num=num*(*lb28_cfd44c.at9ced70(point))->prop45d550().get9b64f0()->def9b8f00()->multiplier/100*(*lb28_cfd44c.at9ced70(point))->prop45d550().get9b64f0()->def9b8f00()->material->multiplier/100;
     lb28_warn7b1750((*lb28_cfd44c.at9ced70(point))->prop45d550().get9b64f0()->armor45c630()!=-1&&num>=(*lb28_cfd44c.at9ced70(point))->prop45d550().get9b64f0()->armor45c630()?144:145,&(*lb28_cfd44c.at9ced70(point))->prop45d550().get9b64f0()->name45c5b0(),0,0,LB28H(),LB28H(),0);
    }else{
     num=num*(*lb28_cfd44c.at9ced70(point))->def9fcd80()->material->multiplier/100;
     lb28_warn7b1750((*lb28_cfd44c.at9ced70(point))->armor66ae70()!=-1&&num>=(*lb28_cfd44c.at9ced70(point))->armor66ae70()?144:145,&(*lb28_cfd44c.at9ced70(point))->name45d140(),0,0,LB28H(),LB28H(),0);
    }return true;
   }else if(lb28_caed20<wallStart+500)return true;
   else if(lb28_caed20>wallLast+3000)goto wallReset;
   if(first805de0(entity,false))return true;if(second8062d0())return true;entity.get9b6570()->wall600970(direction,point);if(!entity.get9b6570()->value490840())return true;wallLast=lb28_caed20;
  }else return false;
 }
 int value=lb28_b95fa0[type];if(entity.get9b6570())value=lb28_max9cdb60(value,entity.get9b6570()->speed5d15a0(false));lb28_cefc4c->spend774390(type,value);return true;
}
