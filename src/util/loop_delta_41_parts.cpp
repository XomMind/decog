// NOTE: private borrowed Parts/Part views, placeholder member names. No object allocation/complete-size claims.
#include <string>
#include <vector>
using namespace std;
struct D41Point;struct D41Entity;struct D41Item;
struct D41HE{unsigned id;D41HE();D41Entity*get9b6570()const;};
struct D41HI{unsigned id;D41Item*get9b65b0()const;bool valid9b7230()const;bool operator!=(D41HI)const;};
struct D41Def{char p0[0xec];int mode;};
struct D41Item{bool active457cf0();bool over458180();bool flag458220();int type457880();int sub4578a0();int kind457f90();int guided4580c0();D41Def*def9b4350();void setOver579940(bool);string name571db0(bool,bool);string base457990();};
struct D41Entity{int mode5cad50();int check5dc700(D41HI);int check5dc440(D41HI);void off64e7e0(D41HI);bool on64da50(D41HI);};
struct D41Part{char base[0x6c];D41HI item;bool secondary;void update890710(bool);};
struct D41Inventory{void a8a5740();void b8a57e0();void c8a5860();void d8a5900();void e8a59a0();void f8a5a40();};extern D41Inventory*d41_cec08c;
struct D41Map{D41HE player4630f0();};extern D41Map*d41_cefc4c;
struct D41ItemUI{void update4aee10(D41HI);};extern D41ItemUI*d41_cec11c;
struct D41Hints{bool show793450(int,bool,const string*,bool,bool);};extern D41Hints*d41_cefaa8;
struct D41MapView{bool flag49aa00();void update49af00();};extern D41MapView*d41_cec054;
int d41_find9d4660(vector<D41Part*>&,D41Part*);bool d41_between9daf80(int,int,int);int d41_sound4541b0(unsigned,int,int);void d41_msg7b1750(int,const string*,const string*,const string*,D41HE,D41HE,const D41Point*);
extern int d41_cefb38;extern bool d41_d28e7b;
struct D41Parts{char base[0x74];vector<D41Part*>parts;char gap84[0xc0-0x84];bool flag;int mode;void a896cc0();void b896d80();void c896e20();void d896ee0();void e896fa0();void f897040();void toggle8993e0(D41Part*,bool);};
void D41Parts::toggle8993e0(D41Part*part,bool silent){
 D41HE player=d41_cefc4c->player4630f0();
 if(part->secondary){int i;for(i=d41_find9d4660(parts,part)-1;i>=0;i--){if(!parts[i]->secondary)break;}part=parts[i];}
 if(part->item.get9b65b0()->active457cf0()){
  if(part->item.get9b65b0()->over458180()){
   bool enable=!part->item.get9b65b0()->flag458220();
   if(part->item.get9b65b0()->type457880()==10&&part->item.get9b65b0()->def9b4350()->mode&&d41_cefc4c->player4630f0().get9b6570()->mode5cad50()&&d41_cefb38!=part->item.get9b65b0()->def9b4350()->mode)enable=false;
   if(enable){part->item.get9b65b0()->setOver579940(true);part->update890710(true);if(mode>0){f897040();d41_cec08c->f8a5a40();}d41_cec11c->update4aee10(part->item);if(!silent)d41_sound4541b0(36,0,0);return;}
  }
  int result=player.get9b6570()->check5dc700(part->item);
  switch(result){
  case 0:
   player.get9b6570()->off64e7e0(part->item);part->update890710(true);
   switch(part->item.get9b65b0()->kind457f90()){
   case 6:a896cc0();d41_cec08c->a8a5740();break;
   case 102:b896d80();d41_cec08c->b8a57e0();break;
   case 103:c896e20();d41_cec08c->c8a5860();break;
   case 105:d896ee0();d41_cec08c->d8a5900();break;
   case 90:case 106:e896fa0();d41_cec08c->e8a59a0();break;
   }
   if(mode>0&&(part->item.get9b65b0()->sub4578a0()==1||part->item.get9b65b0()->kind457f90()==38)){f897040();d41_cec08c->f8a5a40();}
   if(!silent)d41_sound4541b0(38,0,0);break;
  case 45:d41_msg7b1750(36,&part->item.get9b65b0()->name571db0(false,false),0,0,player,D41HE(),0);break;
  case 46:d41_msg7b1750(37,&part->item.get9b65b0()->name571db0(false,false),0,0,player,D41HE(),0);break;
  }
 }else{
  int result=player.get9b6570()->check5dc440(part->item);
  switch(result){
  case 0:{
   bool success=player.get9b6570()->on64da50(part->item);part->update890710(true);if(!success&&!silent)d41_sound4541b0(35,0,0);
   switch(part->item.get9b65b0()->def9b4350()->mode){
   case 0:if(part->item.get9b65b0()->sub4578a0()!=2)d41_cefaa8->show793450(part->item.get9b65b0()->sub4578a0()==0?34:part->item.get9b65b0()->sub4578a0()==3?35:36,part->item.get9b65b0()->over458180(),&part->item.get9b65b0()->name571db0(false,false),false,false);break;
   case 1:case 2:d41_cefaa8->show793450(37,true,&part->item.get9b65b0()->name571db0(false,false),false,false);break;
   case 3:d41_cefaa8->show793450(38,true,&part->item.get9b65b0()->name571db0(false,false),false,false);break;
   case 4:d41_cefaa8->show793450(39,true,&part->item.get9b65b0()->name571db0(false,false),false,false);break;
   }
   if(part->item.get9b65b0()->sub4578a0()==1){string name;for(int i=0;i<parts.size();i++)if(parts[i]->item.valid9b7230()&&parts[i]->item.get9b65b0()->active457cf0()&&parts[i]->item.get9b65b0()->sub4578a0()==1&&parts[i]->item.get9b65b0()->type457880()!=part->item.get9b65b0()->type457880()){player.get9b6570()->off64e7e0(parts[i]->item);parts[i]->update890710(true);if(name.empty())name=parts[i]->item.get9b65b0()->name571db0(false,false);}d41_cefaa8->show793450(43,!name.empty(),&name,false,false);if(mode>0){f897040();d41_cec08c->f8a5a40();}}
   else if(part->item.get9b65b0()->type457880()>=26){string name;for(int i=0;i<parts.size();i++)if(parts[i]->item!=part->item&&parts[i]->item.valid9b7230()&&parts[i]->item.get9b65b0()->active457cf0()&&parts[i]->item.get9b65b0()->type457880()>=26){player.get9b6570()->off64e7e0(parts[i]->item);parts[i]->update890710(true);if(name.empty())name=parts[i]->item.get9b65b0()->name571db0(false,false);}d41_cefaa8->show793450(44,!name.empty(),&name,false,false);}
   else if(part->item.get9b65b0()->guided4580c0()||(part->item.get9b65b0()->kind457f90()==119&&part->item.get9b65b0()->type457880()<26)){for(int i=0;i<parts.size();i++)if(parts[i]->item.valid9b7230()&&parts[i]->item.get9b65b0()->sub4578a0()==3&&parts[i]->item!=part->item&&parts[i]->item.get9b65b0()->active457cf0()){player.get9b6570()->off64e7e0(parts[i]->item);parts[i]->update890710(true);}}
   else if(part->item.get9b65b0()->type457880()==24&&d41_d28e7b&&!flag){for(int i=0;i<parts.size();i++)if(parts[i]->item.valid9b7230()&&parts[i]->item.get9b65b0()->active457cf0()&&d41_between9daf80(20,parts[i]->item.get9b65b0()->type457880(),25)&&parts[i]->item.get9b65b0()->type457880()!=24&&parts[i]->item.get9b65b0()->kind457f90()!=207){player.get9b6570()->off64e7e0(parts[i]->item);parts[i]->update890710(true);}}
   if(part->item.get9b65b0()->type457880()>=20){
    if(!part->item.get9b65b0()->guided4580c0())for(int i=0;i<parts.size();i++)if(parts[i]->item.valid9b7230()&&parts[i]->item.get9b65b0()->guided4580c0()&&parts[i]->item.get9b65b0()->active457cf0()){player.get9b6570()->off64e7e0(parts[i]->item);parts[i]->update890710(true);}
    if(!(part->item.get9b65b0()->kind457f90()==119&&part->item.get9b65b0()->type457880()<26))for(int i=0;i<parts.size();i++)if(parts[i]->item.valid9b7230()&&parts[i]->item.get9b65b0()->kind457f90()==119&&parts[i]->item.get9b65b0()->type457880()<26&&parts[i]->item.get9b65b0()->active457cf0()){player.get9b6570()->off64e7e0(parts[i]->item);parts[i]->update890710(true);}
   }
   switch(part->item.get9b65b0()->kind457f90()){
   case 6:a896cc0();d41_cec08c->a8a5740();break;
   case 103:c896e20();d41_cec08c->c8a5860();break;
   case 105:d896ee0();d41_cec08c->d8a5900();break;
   case 102:b896d80();d41_cec08c->b8a57e0();break;
   case 38:if(mode==0)break;
   case 90:case 106:e896fa0();d41_cec08c->e8a59a0();break;
   }break;}
  case 36:d41_msg7b1750(40,&part->item.get9b65b0()->base457990(),0,0,player,D41HE(),0);break;
  case 37:d41_msg7b1750(45,&part->item.get9b65b0()->name571db0(false,false),0,0,player,D41HE(),0);break;
  case 38:d41_msg7b1750(41,&part->item.get9b65b0()->name571db0(false,false),0,0,player,D41HE(),0);break;
  case 39:d41_msg7b1750(42,&part->item.get9b65b0()->name571db0(false,false),0,0,player,D41HE(),0);break;
  case 40:d41_msg7b1750(43,&part->item.get9b65b0()->name571db0(false,false),0,0,player,D41HE(),0);break;
  case 41:d41_msg7b1750(44,&part->item.get9b65b0()->name571db0(false,false),0,0,player,D41HE(),0);break;
  case 35:d41_msg7b1750(39,&part->item.get9b65b0()->name571db0(false,false),0,0,player,D41HE(),0);break;
  case 43:d41_msg7b1750(46,&part->item.get9b65b0()->name571db0(false,false),0,0,player,D41HE(),0);break;
  case 31:d41_msg7b1750(47,&part->item.get9b65b0()->name571db0(false,false),0,0,player,D41HE(),0);break;
  case 32:d41_msg7b1750(48,&part->item.get9b65b0()->name571db0(false,false),0,0,player,D41HE(),0);break;
  case 33:d41_msg7b1750(49,&part->item.get9b65b0()->name571db0(false,false),0,0,player,D41HE(),0);break;
  case 44:d41_msg7b1750(50,&part->item.get9b65b0()->name571db0(false,false),0,0,player,D41HE(),0);break;
  }
 }
 if(d41_cec054->flag49aa00())d41_cec054->update49af00();
}
