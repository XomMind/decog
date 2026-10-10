#include <string>
#include <memory>
#include <stddef.h>
#include "../game/luigiai.h"
using std::string;
// NOTE: private partial retail views; owner operations and callee bodies are external.
// Real LuigiMachineHacking constructor comes from the existing reconstructed header;
// no throwing declaration is narrowed for an allocating string/collection operation.
struct D28Prop;struct D28Entity;struct D28Item;struct D28Level;
struct D28HP{int id;D28Prop*get9b64f0()const throw();};
struct D28HE{int id;D28HE()throw();D28Entity*get9b6570()const throw();};
struct D28HI{int id;D28HI()throw();D28Item*get9b65b0()const throw();};
struct D28HL{int id;D28Level*get9b7910()const throw();};
struct D28P{int x,y;D28P(int,int)throw();};
struct D28Rect{int x,y,w,h;D28Rect(int,int,int,int)throw();D28Rect(const D28Rect&)throw();};
struct D28Items{D28HI*begin,*end,*capacity;std::allocator<D28HI>allocator;unsigned size9b9260()const throw();D28HI&at9b81f0(unsigned)throw();void push9b80b0(const D28HI&);};
struct D28Flags{int*begin,*end,*capacity;std::allocator<int>allocator;};struct D28MapRecord{char p[0x148];D28Flags flags;};struct D28MapRecords{D28MapRecord**begin,**end,**capacity;std::allocator<D28MapRecord*>allocator;D28MapRecord*&at9b81f0(unsigned)throw();};
struct D28ItemLists{D28Items*begin,*end,*capacity;std::allocator<D28Items>allocator;D28Items&at9b8070(unsigned)throw();};
// Native empty allocator member at+c; ordinary pointer alignment rounds to16B.
static_assert(sizeof(std::allocator<int>)==1,"native empty allocator");
static_assert(sizeof(D28Items)==16&&offsetof(D28Items,allocator)==12,"actual item owner layout");
static_assert(sizeof(D28Flags)==16&&offsetof(D28Flags,allocator)==12,"actual integer owner layout");
static_assert(sizeof(D28MapRecords)==16&&offsetof(D28MapRecords,allocator)==12,"actual map record owner layout");
static_assert(sizeof(D28ItemLists)==16&&offsetof(D28ItemLists,allocator)==12,"actual nested owner layout");
struct D28Machine{char p[0x10];bool ready,imprinted;char p12[0x28-0x12];int level;void values65cdc0(int*,int*);};
struct D28PropDef{char p[0xf8];int kind;};
struct D28Prop{const string&name45c5b0()throw();D28Machine*state45cb30()throw();D28PropDef*def9b8f00()throw();int flag457b10()throw();int index44ab40()throw();};
struct D28Entity{bool special5cbf30();D28Items*inventory45ab00()throw();};
struct D28Item{bool special5775a0();void move57a520(D28HP,int);string name571db0(bool,bool);};
struct D28Level{int p0,type;char p8[0x25-8];bool known;};
struct D28Console{char pad[0x60];int state;void*engine,*title;D28Console(D28Console*,D28Rect,int,bool,int);bool hidden4175f0()throw();bool active48e740()throw();void close7b60e0();void hide7b1cc0();void hidden417ba0(bool)throw();void copy429fe0(D28Console*,D28P&,const D28Rect*);void update8758d0(bool);void end7b4f10();int layer44a7d0()throw();void clear417bc0();void interior417c70();void animate48c3f0(string);void scale417b60(float)throw();void scale417b80(float)throw();};
struct D28Inventory{void reopen8a2ce0(int,D28HI);};
struct D28Map{D28HE player4630f0()throw();bool check462f00(D28HP);void announce71dd30(D28HL);void playerActionFinish(int,int);};
struct D28Data{bool enabled46f4b0(int);const string&text46f6d0(const string&);};
struct D28Stats{int count472c90(unsigned);};
struct D28Player{void suspect77ee70(float,int,D28HI);};
struct D28Factory{bool show793450(int,bool,const string*,bool,bool);};
struct D28Graph{void push416570();void clear416340(bool);void mark4162e0(unsigned,bool);};
struct D28Hack:D28Console{bool started;char p6d[0x7c-0x6d];int mode;D28HP prop;int value,extra;void*text;int count;D28Console*copy;int unused98,message;void open939b50(D28HP);};
extern D28Console*d28_cec0f4,*d28_cec0b0,*d28_cec058,*d28_cec0b4,*d28_cec034,*d28_cec054;extern D28Inventory*d28_cec08c;
extern D28Map*d28_cefc4c;extern D28HL d28_d1e888;extern D28Data d28_d1e860;extern D28Player d28_cf45d8;extern D28Factory*d28_cefaa8;extern D28Graph*d28_cefa8c;extern D28Stats d28_d2c658;
extern int*d28_cf4700;extern D28MapRecords d28_d25de0;extern D28ItemLists d28_cf3a10;
extern bool d28_cefb3e,d28_d28d15;extern LuigiMachineHacking*d28_cec024;extern int d28_cf27ec,d28_d01a20,d28_cf27f4,d28_cf27f8;extern const float d28_ba8514;
extern string d28_mapNames_cfaca0[];
bool d28_contains9db330(D28Flags&,int);int d28_string405610(const string&);void d28_lookup4af3e0();
bool d28_route5111e0(int,const string*,const string*,const string*,D28HE,D28HE,const D28P*,bool);
// Retail repeated xor/test backedges support the original do/while(false) message macro.
#define D28_MSG(id,text) do{if(d28_route5111e0(id,text,0,0,d28_cefc4c->player4630f0(),D28HE(),0,false))d28_cec058->update8758d0(true);d28_cec0b4->end7b4f10();}while(0)
void D28Hack::open939b50(D28HP p){
 if(!d28_cec0f4->hidden4175f0())d28_cec0f4->hide7b1cc0();
 if(d28_cec0b0->active48e740())d28_cec0b0->close7b60e0();
 if(p.get9b64f0()->state45cb30()->level<0){D28_MSG(p.get9b64f0()->def9b8f00()->kind==5&&d28_cefc4c->check462f00(p)?444:443,&p.get9b64f0()->name45c5b0());return;}
 if(p.get9b64f0()->flag457b10()){D28_MSG(445,&p.get9b64f0()->name45c5b0());return;}
 if(d28_cf4700&&p.get9b64f0()->def9b8f00()->kind==3&&d28_d1e860.enabled46f4b0(1)&&d28_contains9db330(d28_d25de0.at9b81f0(*d28_cf4700)->flags,6)&&d28_cefc4c->player4630f0().get9b6570()->special5cbf30()){
  D28HI first;D28Items*x=d28_cefc4c->player4630f0().get9b6570()->inventory45ab00();
  for(unsigned i=0;i<x->size9b9260();i++)if(x->at9b81f0(i).get9b65b0()->special5775a0()){first=x->at9b81f0(i);break;}
  D28Items*tag=&d28_cf3a10.at9b8070(p.get9b64f0()->index44ab40());
  first.get9b65b0()->move57a520(p,0);tag->push9b80b0(first);d28_cec08c->reopen8a2ce0(0,D28HI());
  D28_MSG(783,&first.get9b65b0()->name571db0(false,false));
  d28_cf45d8.suspect77ee70(d28_ba8514,5,D28HI());d28_cefc4c->playerActionFinish(17,100);return;
 }
 D28_MSG(446,&p.get9b64f0()->name45c5b0());
 if(!d28_d1e888.get9b7910()->known){d28_cefc4c->announce71dd30(d28_d1e888);D28_MSG(447,&d28_mapNames_cfaca0[d28_d1e888.get9b7910()->type]);}
 if(p.get9b64f0()->def9b8f00()->kind==0&&d28_d1e860.enabled46f4b0(1)&&!p.get9b64f0()->state45cb30()->ready&&d28_string405610(d28_d1e860.text46f6d0("zioWasImprinted_g"))&&!d28_string405610(d28_d1e860.text46f6d0("zioAttackedLocals_g")))p.get9b64f0()->state45cb30()->imprinted=true;
 d28_lookup4af3e0();mode=2;prop=p;D28Machine*machine=prop.get9b64f0()->state45cb30();machine->values65cdc0(&value,&extra);
 if(d28_cefb3e){d28_cec024=new LuigiMachineHacking(value,extra);}
 text=0;count=0;unused98=0;message=87;state=1;
 hidden417ba0(false);
 copy=new D28Console(d28_cec0b0,D28Rect(d28_cf27ec,d28_d01a20,d28_cf27f4,d28_cf27f8),d28_d28d15?3:2,false,d28_cec034->layer44a7d0());
 d28_cec054->copy429fe0(copy,D28P(0,0),0);d28_cec054->hidden417ba0(true);d28_cec058->hidden417ba0(true);
 d28_cefa8c->push416570();d28_cefa8c->clear416340(true);d28_cefa8c->mark4162e0(14,true);
 if(d28_cefaa8->show793450(57,true,0,false,false))message=57;
 else if(prop.get9b64f0()->def9b8f00()->kind==0&&d28_cefaa8->show793450(58,d28_d2c658.count472c90(614)>=3,0,false,false))message=58;
 if(started){interior417c70();animate48c3f0(prop.get9b64f0()->state45cb30()->imprinted?"CHack_Content_ZHack":prop.get9b64f0()->def9b8f00()->kind==6?"CHack_Content_Derelict":prop.get9b64f0()->def9b8f00()->kind==7?(d28_d1e888.get9b7910()->type==35?"CHack_Content_AC0":"CHack_Content_Architect"):prop.get9b64f0()->def9b8f00()->kind==8?"CHack_Content_Archives":"CHack_Content");}
 else{clear417bc0();animate48c3f0(prop.get9b64f0()->state45cb30()->imprinted?"CHack_Border_ZHack":prop.get9b64f0()->def9b8f00()->kind==6?"CHack_Border_Derelict":prop.get9b64f0()->def9b8f00()->kind==7?(d28_d1e888.get9b7910()->type==35?"CHack_Border_AC0":"CHack_Border_Architect"):prop.get9b64f0()->def9b8f00()->kind==8?"CHack_Border_Archives":"CHack_Border");started=true;}
 scale417b60(1);scale417b80(1);
}
