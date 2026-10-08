#include <string>
#include <cstdlib>
#include "thirdparty/zfstream.h"
using std::string;
struct D34P{int x,y;D34P()throw();D34P(int,int)throw();D34P(const D34P&)throw();};struct D34Entity;struct D34HE{int id;D34HE()throw();bool valid9b7230()const throw();D34Entity*get9b6570()const throw();};
struct D34Event{int type;D34P mouse;D34Event(int)throw();D34Event(const D34Event&)throw();};
struct D34Engine{bool busy454d30()throw();};
struct D34Con{virtual~D34Con();virtual void resize(int,int);virtual bool active();virtual void refresh();virtual bool input(D34Event*);virtual void mouse(int,int);virtual void update();virtual void render();virtual void open();virtual void close();char omitted[0x60-4];int state;D34Engine*engine;void*title;bool hidden4175f0()throw();bool base429d00(D34Event*);bool contains417440(const D34P&)throw();void hide7b1cc0();void clear8b5080();void clear7d0a80();void clear8a53c0();int field48c360()throw();int field48e040()throw();};
struct D34PhraseDef;struct D34Phrase{const D34PhraseDef*definition;string text;D34Phrase(int,const string*,const string*,const string*,D34HE,D34HE);};
struct D34Interface{bool hidden4175f0()throw();void hide7b1cc0();void add7b1880(D34Phrase*);void refresh48d7c0();};
struct D34View:D34Con{void refresh827950();void redraw49ac70();D34HE anchor4b1b30()throw();void unanchor49ac50();void move8069e0(D34P,bool);bool active49aa00()throw();unsigned last49abb0()throw();bool labels49b490()throw();bool fading49b4d0()throw();void labels8142d0(unsigned,bool);void next49b5b0();bool focus49b570()throw();};
struct D34Entity{D34P position45a4c0()throw();};struct D34Map{bool blocked71bbd0();D34HE player4630f0()throw();};
struct D34GM{void serialize78c260(bool,bool,bool,bool,bool);void end78d4c0();bool ready78b8a0(bool,bool,bool);void resume78c050();bool show793450(int,bool,const string*,bool,bool);};
struct D34Key{int type457dd0()throw();};struct D34Keys{bool flag416200(int)throw();D34Key*current416230()throw();};
struct D34Mouse{unsigned char hidden41a6e0()throw();void hidden432170(bool);D34P position40a970()throw();};
struct D34Window{void toggle41b120();void toggle41b170();void limit41b0b0();};
struct D34Audio{void volume419580(int);void halt419c50();};struct D34Sound{void halt4544e0();void update5003b0();};extern D34Sound d34_d2d2a0;
struct D34Player{bool flag46dd50()throw();};extern D34Player d34_cf45d8;
struct D34Target{void update49b890();};extern D34Target d34_d1d9c0;
struct D34Parts{void mode8968b0(int);};struct D34Log{unsigned char flag48e740()throw();void skip7b60e0();};struct D34Effects{bool active4b3180()throw();};
struct D34Mission:D34Con{unsigned saveTick,loadTick;char omitted74[4];bool cursorMessage;bool input988d80(D34Event*);void toggle988a30();void quit988ad0(bool);void action988d30();void mute987920();void unmute987a00(bool);};
extern D34Map*d34_cefc4c;extern D34GM*d34_cefaa8;extern D34Interface*d34_cec0f4;extern D34Con*d34_cec118,*d34_cec11c,*d34_cec03c,*d34_cec08c,*d34_cec0c8,*d34_cec130,*d34_cec074;extern D34View*d34_cec054;extern D34Keys*d34_cefa8c;extern D34Mouse*d34_cefa94;extern D34Window*d34_cefaa0;extern D34Audio*d34_cefa90;extern D34Parts*d34_cec088;extern D34Log*d34_cec0b0;extern D34Effects*d34_cec138;
extern bool d34_cefa5f,d34_d28de1,d34_cefacd,d34_d28de3,d34_cf4620,d34_d28c8a,d34_d28cb0,d34_d28cbc,d34_d28c8b,d34_d28d16,d34_d28e58,d34_d28e06,d34_d28fac,d34_d28fab;extern int d34_cf4718,d34_cf4614,d34_d28c8c,d34_d28d68,d34_cefc90;extern unsigned d34_caed20;extern const char d34_c145cc[],d34_c145dc[];
int d34_save77e2b0(gzifstream&,bool,bool);string d34_int4051f0(int);void d34_message7b1750(int,const string*,const string*,const string*,D34HE,D34HE,const D34P*);

static_assert(sizeof(gzifstream)==184,"actual complete gz stream");
static_assert(sizeof(D34Con)==108&&sizeof(D34Phrase)==32&&sizeof(D34Event)==12,"actual ABI");
bool D34Mission::input988d80(D34Event*event){
 if(hidden4175f0()||d34_cefa5f)return false;
 if(base429d00(event))return true;
 switch(event->type){case 6:toggle988a30();return true;}
 if(!d34_cefc4c||d34_cefc4c->blocked71bbd0())return false;
 switch(event->type){
 case 7:if(!d34_d28de1)quit988ad0(true);return true;
 case 8:
  if(d34_cefacd||d34_cf45d8.flag46dd50())d34_cefaa8->serialize78c260(true,true,false,false,false);
  else if(d34_cf4718){
   if(!saveTick||d34_caed20>saveTick+5000){saveTick=d34_caed20;d34_cec0f4->add7b1880(new D34Phrase(211,0,0,0,D34HE(),D34HE()));}
   else{d34_cf4620=false;d34_cefaa8->serialize78c260(false,true,false,true,false);}
  }return true;
 case 9:action988d30();return true;
 case 10:
  if(d34_cefacd||d34_cf45d8.flag46dd50()||d34_cf4718){
   bool flags=!d34_cefacd&&!d34_cf45d8.flag46dd50()&&d34_cf4718&&!d34_d28de3;gzifstream p;
   if(!d34_save77e2b0(p,false,flags)){
    p.close();if(!d34_cec0f4->hidden4175f0())d34_cec0f4->hide7b1cc0();if(!d34_cec118->hidden4175f0())d34_cec118->clear8b5080();if(!d34_cec11c->hidden4175f0())d34_cec11c->clear8b5080();if(flags&&!d34_cec03c->hidden4175f0())d34_cec03c->clear7d0a80();
    if(flags&&(!loadTick||d34_caed20>loadTick+5000)){loadTick=d34_caed20;d34_cec0f4->add7b1880(new D34Phrase(213,0,0,0,D34HE(),D34HE()));}
    else{int count=d34_cf4614;if(d34_cec054&&d34_cefa8c->flag416200(8))d34_cec054->refresh827950();d34_cefaa8->end78d4c0();if(!d34_cefaa8->ready78b8a0(false,false,flags))exit(1);d34_cefaa8->resume78c050();if(flags)d34_cf4614=count+1;}
   }else{d34_cec0f4->add7b1880(new D34Phrase(215,0,0,0,D34HE(),D34HE()));}
  }return true;
 case 11:
  d34_cefa94->hidden432170(!d34_cefa94->hidden41a6e0());d34_d28c8a=!d34_d28c8a;d34_d1d9c0.update49b890();d34_cefaa8->show793450(22,d34_d28c8a,0,false,false);
  if(cursorMessage)cursorMessage=false;else d34_message7b1750(d34_cefa94->hidden41a6e0()?199:200,&string(d34_c145cc),0,0,D34HE(),D34HE(),0);
  if(d34_cec054&&d34_cefa8c->flag416200(8)){d34_cec054->refresh827950();if(d34_d28e06){d34_cec054->redraw49ac70();d34_cec054->input(&D34Event(47));}}return true;
 case 12:d34_cefaa0->toggle41b120();d34_cefaa0->toggle41b170();d34_d28cb0=!d34_d28cb0;return true;
 case 13:d34_cefaa0->limit41b0b0();return true;
 case 14:if(!d34_d28cbc){d34_d28c8b=!d34_d28c8b;if(d34_d28c8b){mute987920();d34_cec0f4->add7b1880(new D34Phrase(209,0,0,0,D34HE(),D34HE()));}else{unmute987a00(false);d34_cec0f4->add7b1880(new D34Phrase(210,0,0,0,D34HE(),D34HE()));}}return true;
 case 15:if(!d34_d28cbc){if(d34_d28c8c!=0){d34_d28c8c--;d34_cefa90->volume419580(d34_d28c8c);d34_d28c8b=false;}d34_message7b1750(208,&d34_int4051f0(d34_d28c8c),0,0,D34HE(),D34HE(),0);}return true;
 case 16:if(!d34_d28cbc){if(d34_d28c8c!=10){d34_d28c8c++;d34_cefa90->volume419580(d34_d28c8c);d34_d28c8b=false;}d34_message7b1750(208,&d34_int4051f0(d34_d28c8c),0,0,D34HE(),D34HE(),0);}return true;
 case 17:d34_d28d16=!d34_d28d16;if(d34_d28e58){int mode=d34_d28d68;d34_cec088->mode8968b0(mode==2?0:2);d34_cec088->mode8968b0(mode);}d34_message7b1750(d34_d28d16?199:200,&string(d34_c145dc),0,0,D34HE(),D34HE(),0);return true;
 case 18:
  if(d34_cec054->anchor4b1b30().valid9b7230()){d34_cec054->unanchor49ac50();d34_cec054->move8069e0(d34_cefc4c->player4630f0().get9b6570()->position45a4c0(),false);return true;}
  if(d34_cec074->engine->busy454d30())break;
  if(!d34_cec118->hidden4175f0())break;if(!d34_cec11c->hidden4175f0())break;
  if(!d34_cec054->hidden4175f0()&&d34_cec054->active49aa00())break;
  if(!d34_cec054->hidden4175f0()&&d34_cec054->last49abb0()+500>d34_caed20)break;
  if(d34_cec0b0->flag48e740())d34_cec0b0->skip7b60e0();
  else if(d34_cec054->labels49b490()){if(d34_cec054->fading49b4d0())d34_cec054->labels8142d0(18,false);else d34_cec054->labels8142d0(18,true);d34_cec054->next49b5b0();}
  else if(!d34_cec054->focus49b570())d34_cec054->next49b5b0();
  else if(d34_cefc90==2)d34_cec08c->clear8a53c0();
  else{if((d34_d28c8a?d34_d28fac:d34_d28fab)&&d34_cefa8c->current416230()&&d34_cefa8c->current416230()->type457dd0()==27)return true;
   else if(d34_cec03c->field48c360()==0){d34_cefa90->halt419c50();d34_d2d2a0.halt4544e0();d34_d2d2a0.update5003b0();d34_cec03c->open();}}
  return true;
 case 19:if(!d34_cec118->hidden4175f0())d34_cec118->clear8b5080();if(!d34_cec11c->hidden4175f0())d34_cec11c->clear8b5080();if(!d34_cec03c->hidden4175f0())d34_cec03c->clear7d0a80();if(!d34_cec054->hidden4175f0()&&d34_cec054->last49abb0()+500>d34_caed20)break;if(!d34_cec138->active4b3180())d34_cec0f4->refresh48d7c0();return true;
 }
 switch(event->type){case 262:if(d34_cec130&&d34_cec130->field48e040()==11&&!d34_cec0c8->hidden4175f0()&&d34_cec0c8->contains417440(d34_cefa94->position40a970())){D34Event newEvent(*event);newEvent.type=216;d34_cec0c8->input(&newEvent);return true;}}
 return false;
}
