#include <string>
using std::string;
// NOTE: private partial views of real Item/definition fields and external helpers.
struct LB22Effect;struct LB22Def{char p[0x1b4];string name;};
struct LB22Defs{LB22Def*&at9b81f0(unsigned)throw();};extern LB22Defs lb22_d2d1c4;
extern int lb22_caf164;extern LB22Def*lb22_cefbec;
string lb22_int4051f0(int);string lb22_count407a80(int,const string&);
struct LB22Item{int a,b;LB22Def*def;char p[0x10];int value;
 int detail5745d0(string&);bool flag457ff0()throw();int kind457f90()throw();int capacity457fb0()throw();int count45cb30()throw();LB22Effect*effect457b70(int)throw();int effectValue457be0(int)throw();int timer458240()throw();int timerValue458260()throw();};
int LB22Item::detail5745d0(string&out){
 string text;
 if(flag457ff0()||kind457f90()==160)text=" ("+lb22_int4051f0(count45cb30())+")";
 else if(kind457f90()==166){
  text=" ("+lb22_int4051f0(count45cb30())+"/"+lb22_int4051f0(capacity457fb0());
  if(count45cb30()){int p=effectValue457be0(81);text+=" "+(p==lb22_caf164?string("ERR"):string(lb22_d2d1c4.at9b81f0(p)->name));}
  text+=")";
 }
 else if(kind457f90()==124)text=" ("+lb22_int4051f0(count45cb30())+")";
 else if(kind457f90()==167)text=" ("+lb22_int4051f0(count45cb30())+"/"+lb22_int4051f0(capacity457fb0())+")";
 else if(kind457f90()==204)text=effect457b70(124)?" (Full)":" (Empty)";
 else if(kind457f90()==205)text=effect457b70(124)?" (Ready)":" (Expended)";
 else if(effectValue457be0(74))text=" ("+lb22_int4051f0(effectValue457be0(73))+")";
 else if(effectValue457be0(75))text=" ("+lb22_int4051f0(effectValue457be0(75))+"%)";
 else if(timer458240())text=" ("+lb22_int4051f0(timerValue458260())+")";
 else if(effect457b70(68))text=" ("+lb22_int4051f0(effectValue457be0(68))+")";
 else if(effect457b70(71))text=" ("+lb22_int4051f0(effectValue457be0(71)==-1?0:effectValue457be0(71))+")";
 else if(effect457b70(118)){
  text=" (";if(effectValue457be0(119)==effectValue457be0(118))text+="Charged";
  else text+=lb22_int4051f0(effectValue457be0(119))+"/"+lb22_int4051f0(effectValue457be0(118));
  text+=")";
 }
 else if(effect457b70(121))text=" ("+lb22_count407a80(effectValue457be0(121),"Ring")+")";
 else if(def==lb22_cefbec)text=" ("+lb22_int4051f0(value)+")";
 if(text.length())out+=text;return text.length();
}
