#include <string>
#include <memory>
#include <stddef.h>
using std::string;
// NOTE: partial private views of actual native owners; external operations retain retail contracts.
struct D31Entity;struct D31HE{int id;D31Entity*get9b6570()const throw();};
struct D31HI{int id;bool null9b65d0()const throw();};
struct D31Entity{int move5d1390();int subtype44a7d0()throw();int count45a700()throw();bool stasis5ced30();bool held45aff0()throw();bool heavy45a780();D31HI item5d2380(int);int heat45a990()throw();int special5cad50();int stopped45a6e0()throw();int speed5d15a0(bool);int effect5d22a0(int);bool inactive5d26e0(int);int inactiveValue5d2810(int);};
struct D31RGB{unsigned char r,g,b;D31RGB()throw();D31RGB(const D31RGB&)throw();D31RGB&assign411f10(D31RGB)throw();bool equal411f40(D31RGB)throw();};
struct D31Strings{string*first,*last,*capacity;std::allocator<string>allocator;void clear9b0900();void push9b0340(string&&);void push9b06f0(const string&);string&back9b06c0()throw();};
struct D31Ints{int*first,*last,*capacity;std::allocator<int>allocator;void clear9bac80();void push9b9280(int&&);int&back9b6540()throw();int&at9b81f0(unsigned)throw();};
struct D31BitRef{unsigned*word;unsigned bit;operator bool()const throw();D31BitRef&set9b3a70(bool)throw();};
struct D31Bits{unsigned*first,*last,*capacity;std::allocator<unsigned>allocator;unsigned count;void clear9b39e0();void push9b3920(bool);D31BitRef back9b38e0()throw();D31BitRef at9b38a0(unsigned)throw();};
static_assert(sizeof(D31Strings)==16&&sizeof(D31Ints)==16&&sizeof(D31Bits)==20&&sizeof(D31BitRef)==8,"native collections");
static_assert(offsetof(D31Strings,allocator)==12&&offsetof(D31Ints,allocator)==12&&offsetof(D31Bits,allocator)==12,"native allocator tail");
struct D31Engine{void render5100b0();};
struct D31Console{char p[0x60];int state;D31Engine*engine;void*title;bool hidden4175f0()throw();void clear417c70();void fore417b00(D31RGB);void back417b30(D31RGB);void put418110(int,int,int,D31RGB);void print4181d0(int,int,const string&);void base429ea0();};
struct D31Evasion:D31Console{bool active;int age;bool ready;D31Strings names;D31Ints values;D31Bits disabled;int total;string tier;void render887cc0();};
static_assert(sizeof(D31RGB)==3&&sizeof(D31Console)==108&&sizeof(D31Evasion)==204,"retail console/member extents");
struct D31World{D31HE player4630f0()throw();bool field7290f0(D31HE);};extern D31World*d31_cefc4c;
extern D31RGB*d31_d161d4,*d31_d39294,*d31_d204ac,*d31_cf27e8,*d31_d20438,*d31_d2981c,*d31_d35be0,*d31_cfe5a0,*d31_d33ac0;
extern D31RGB d31_d20504[];extern bool d31_d28d26;extern unsigned char d31_ba0984[];extern int d31_cefb38;extern string d31_cf67e0[];
extern const float d31_b96378,d31_b96380;extern const char d31_c016f8[],d31_c016fc[];
int d31_max9cdb60(int,int)throw();int d31_tier4347e0(int,int);string d31_string4051f0(int);
void D31Evasion::render887cc0(){
 if(hidden4175f0())return;
 clear417c70();fore417b00(*d31_d161d4);back417b30(*d31_d39294);engine->render5100b0();
 names.clear9b0900();values.clear9bac80();disabled.clear9b39e0();
 if(ready){
  D31HE player=d31_cefc4c->player4630f0();int mode=player.get9b6570()->move5d1390();
  switch(mode){
   case 1:{int type=player.get9b6570()->subtype44a7d0();
    if(player.get9b6570()->count45a700()&&(type==1||type==7)){
     names.push9b0340(type==1?"Running":"Weaving");
     values.push9b9280(int(-(player.get9b6570()->count45a700()*(type==1?d31_b96378:d31_b96380))*100.0));
     if(player.get9b6570()->stasis5ced30()||player.get9b6570()->held45aff0()){names.back9b06c0()+=" (held in stasis)";disabled.push9b3920(true);}
     else if(d31_cefc4c->field7290f0(player)&&player.get9b6570()->item5d2380(116).null9b65d0()){names.back9b06c0()+=" (held in stasis)";disabled.push9b3920(true);}
     else if(player.get9b6570()->heavy45a780()){names.back9b06c0()+=" (overweight)";disabled.push9b3920(true);}
     else disabled.push9b3920(false);
    }else goto movement;
    break;}
   case 3:case 4:
    names.push9b0340(mode==4?"Flight":"Hover");values.push9b9280(mode==4?10:5);
    if(player.get9b6570()->stasis5ced30()||player.get9b6570()->held45aff0()){names.back9b06c0()+=" (held in stasis)";disabled.push9b3920(true);}
    else if(d31_cefc4c->field7290f0(player)&&player.get9b6570()->item5d2380(116).null9b65d0()){names.back9b06c0()+=" (held in stasis)";disabled.push9b3920(true);}
    else if(player.get9b6570()->heavy45a780()){names.back9b06c0()+=" (overweight)";disabled.push9b3920(true);}
    else disabled.push9b3920(false);
    break;
   default:movement:names.push9b06f0("Movement");values.push9b9280(0);disabled.push9b3920(true);break;
  }
  names.push9b06f0("Heat");values.push9b9280(-d31_max9cdb60(0,player.get9b6570()->heat45a990())*3/100);disabled.push9b3920(values.back9b6540()==0);
  if(player.get9b6570()->special5cad50()&&d31_ba0984[d31_cefb38]){names.push9b06f0(d31_cf67e0[d31_cefb38]);values.push9b9280(-10);}
  else{names.push9b06f0("Speed");values.push9b9280(0);if(!player.get9b6570()->stopped45a6e0()){int speed=player.get9b6570()->speed5d15a0(false);if(speed<=95)values.back9b6540()=(100-speed)/5;}}
  disabled.push9b3920(values.back9b6540()==0);
  names.push9b06f0("Evasion");values.push9b9280(0);disabled.push9b3920(true);
  switch(mode){case 1:case 3:case 4:case 6:{int effect=player.get9b6570()->effect5d22a0(84);
   if(effect){values.back9b6540()=effect;if(player.get9b6570()->heavy45a780())names.back9b06c0()+=" (overweight)";else disabled.back9b38e0().set9b3a70(false);}
   else if(player.get9b6570()->inactive5d26e0(84)){names.back9b06c0()+=" (inactive)";effect=player.get9b6570()->inactiveValue5d2810(84);values.back9b6540()=effect;}
   break;}}
  names.push9b06f0("Phasing");values.push9b9280(d31_max9cdb60(player.get9b6570()->effect5d22a0(82),player.get9b6570()->effect5d22a0(97)));disabled.push9b3920(values.back9b6540()==0);
  if(values.back9b6540()==0&&(player.get9b6570()->inactive5d26e0(82)||player.get9b6570()->inactive5d26e0(97))){names.back9b06c0()+=" (inactive)";values.back9b6540()=d31_max9cdb60(player.get9b6570()->inactiveValue5d2810(82),player.get9b6570()->inactiveValue5d2810(97));}
  total=40;for(int i=0;i<5;i++)if(!disabled.at9b38a0(i))total+=values.at9b81f0(i);
  D31RGB col;switch(d31_tier4347e0(total,100)){case 0:col.assign411f10(*d31_d204ac);tier="RE3";break;case 1:col.assign411f10(*d31_cf27e8);tier="OR3";break;case 2:col.assign411f10(*d31_d20438);tier="YE3";break;case 3:col.assign411f10(*d31_d2981c);tier="GR3";break;}
  if(d31_d28d26){if(col.equal411f40(*d31_d2981c))col.assign411f10(*d31_d35be0);else if(col.equal411f40(*d31_cf27e8))col.assign411f10(*d31_cfe5a0);}
  put418110(1,1,179,col);print4181d0(3,1,d31_string4051f0(total)+"% Avoidance");
  for(int i=0,x=3;i<5;i++){string text=d31_string4051f0(values.at9b81f0(i));if(values.at9b81f0(i)>0)text.insert(0,d31_c016f8);else if(values.at9b81f0(i)==0)text.insert(0,d31_c016fc);fore417b00(disabled.at9b38a0(i)?*d31_d33ac0:d31_d20504[i]);print4181d0(x,2,text);x+=text.size()+1;}
 }
 base429ea0();
}
