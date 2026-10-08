#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
// Private partial retail ABI views; unnamed gaps are omitted fields.
struct LC15Color{unsigned char r,g,b;LC15Color(const LC15Color&)throw();};
struct LC15Strings{void*proxy;string*begin,*end,*capacity;LC15Strings();~LC15Strings();bool empty9b86e0()const throw();unsigned size9b0650()const throw();string&at9b06a0(unsigned)throw();void push9b06f0(const string&);};
struct LC15Def{char p0[0x24];int faction,type;char p2c[0x6c];int size;char p9c[0xac];vector<int>abilities;char p158[0x70];int inventory;char p1cc[0x18];int energy,capacity,matter,heat,resistances[7];char p210[0xc];int sight;};
struct LC15Selection{int id;char p4[0x20];int mode;};
struct LC15Rect;
struct LC15Console{virtual~LC15Console();virtual void resize(int,int);char p4[0x68];int width44b0d0()throw();int height4174c0()throw();int count418300(int,int,int,int,const string&);int wrapped418260(int,int,int,int,const string&);void pos417a90(int,int);void fore417b00(LC15Color);void clear417c70();void row429840(int,int,int,int,LC15Color);void print4181d0(int,int,const string&);void frame7b0640(LC15Rect*,LC15Color,bool,bool);};
struct LC15Poly:LC15Console{LC15Console*child;void refresh(bool);};
extern LC15Selection*lc15_cf4700;extern vector<LC15Def*>lc15_d25de0;extern string lc15_d1e34c,lc15_d28ff8,lc15_d21f70[],lc15_d39e90[],lc15_d323f8[];extern int lc15_bba058[];
extern LC15Color*lc15_cfc174,*lc15_d2175c,*lc15_d2981c,*lc15_cf6b24;extern LC15Color lc15_d2ed1c[];
string intToString(int);
void LC15Poly::refresh(bool animate){
 string str2;
 LC15Def*source=lc15_cf4700==0?0:lc15_d25de0[lc15_cf4700->id];
 if(!source)str2+=lc15_d1e34c;
 else if(!source->abilities.empty()){
  unsigned i=0;int num=0;
  for(;i<source->abilities.size();i++)if(!lc15_d21f70[source->abilities[i]].empty()){
   if(num)str2+="\n\n";str2+=lc15_d21f70[source->abilities[i]];num++;
  }
 }
 if(!str2.empty())str2+="\n\n";str2+=lc15_d28ff8;
 if(source){LC15Strings a;
  switch(source->type){
   case 1:a.push9b06f0("Chute Trap");break;
   case 2:a.push9b06f0("Structural Layout");break;
   case 5:a.push9b06f0("Recycling Unit");break;
   case 4:a.push9b06f0("Fabricator");a.push9b06f0("Stockpiles");a.push9b06f0("DSF");break;
   case 8:a.push9b06f0("Repair Station");break;
   case 9:a.push9b06f0("Terminal");break;
   case 20:a.push9b06f0("Scanalyzer");a.push9b06f0("Analyses");break;
   case 12:a.push9b06f0("Route Map");a.push9b06f0("Security");break;
  }
  if(lc15_cf4700->mode==3&&source->faction==1&&lc15_bba058[source->type]>=6&&source->type!=20){a.push9b06f0("Garrison");a.push9b06f0("Emergency Access");}
  if(!a.empty9b86e0()){
   str2+="\n\n";str2+="Potential Host Acquisition Intel\n";
   for(unsigned i=0;i<a.size9b0650();i++)str2+=" - "+a.at9b06a0(i)+"\n";
  }
 }
 int result=child->count418300(2,2,32,50,str2);int line=0;
 if(source){line=9;int i=0,base=0,r2=0;for(;i<7;i++){
  if(source->resistances[i]<100){base++;if(base>1)line++;}
  else if(source->resistances[i]>100){r2++;if(r2>1)line++;}
 }}
 int center=36,count=result+line+4;
 if(width44b0d0()!=center||height4174c0()!=count){resize(center,count);pos417a90(0,-count);}
 clear417c70();fore417b00(*lc15_cfc174);
 int color=wrapped418260(2,2,32,50,str2)+2;
 if(source){
  row429840(2,color,18,129,*lc15_d2175c);fore417b00(*lc15_d2175c);print4181d0(21,color,"Innate Stats");fore417b00(*lc15_d2981c);
  color++;print4181d0(2,color,"       Size Class:");print4181d0(21,color,lc15_d39e90[source->size]);
  color++;print4181d0(2,color,"        Inventory:");print4181d0(21,color,intToString(source->inventory));
  color++;print4181d0(2,color,"      Sight Range:");print4181d0(21,color,intToString(source->sight));
  color++;print4181d0(2,color,"Energy / Capacity:");print4181d0(21,color,"+"+intToString(source->capacity)+" / "+intToString(source->energy));
  color++;print4181d0(2,color,"  Matter Capacity:");print4181d0(21,color,intToString(abs(source->matter)));
  color++;print4181d0(2,color," Heat Dissipation:");print4181d0(21,color,"-"+intToString(source->heat));
  color++;print4181d0(2,color,"      Resistances:");
  int j=0;
  for(int i=0;i<7;i++)if(source->resistances[i]<100){
   if(j>0)color++;fore417b00(lc15_d2ed1c[i]);print4181d0(21,color,lc15_d323f8[i]);fore417b00(*lc15_d2981c);
   print4181d0(21+lc15_d323f8[i].size(),color,"-"+intToString(100-source->resistances[i])+"%");j++;
  }
  if(j==0){fore417b00(*lc15_d2175c);print4181d0(21,color,"None");fore417b00(*lc15_d2981c);}
  color++;print4181d0(2,color,"       Weaknesses:");j=0;
  for(int i=0;i<7;i++)if(source->resistances[i]>100){
   if(j>0)color++;fore417b00(lc15_d2ed1c[i]);print4181d0(21,color,lc15_d323f8[i]);fore417b00(*lc15_d2981c);
   print4181d0(21+lc15_d323f8[i].size(),color,"+"+intToString(source->resistances[i]-100)+"%");j++;
  }
  if(j==0){fore417b00(*lc15_d2175c);print4181d0(21,color,"None");fore417b00(*lc15_d2981c);}
 }
 if(!animate)frame7b0640(0,*lc15_cf6b24,true,false);
}
