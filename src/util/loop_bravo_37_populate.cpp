// NOTE: private borrowed world/record views and native weighted owners for6dfdb0.
#include <string>
#include <vector>
#include "rng.h"
using std::string;using std::vector;extern RNG rng;
struct LB37P{int x,y;LB37P()throw();LB37P(int,int)throw();LB37P(const LB37P&)throw();int random40c130()throw();};
struct LB37Area{LB37P min,max;LB37Area(int,int,int,int)throw();bool contains40b750(const LB37P&)throw();void random40be30(LB37P*)throw();};
struct LB37Def;struct LB37Terrain;struct LB37AI{void area459410(const LB37Area&)throw();};
struct LB37Entity{void rename45b070(const string&);LB37AI*ai45b590()throw();const LB37P&pos45a4a0()throw();int faction45a2c0()throw();const string&name45a280()throw();void remove637bb0();};
struct LB37HE{int id;bool valid9b7230()const throw();LB37Entity*get9b6570()const throw();};
struct LB37Loc{int unknown0,unknown4,depth;};struct LB37HL{int id;bool equal9b78e0(LB37HL)const throw();LB37Loc*get9b7910()const throw();};extern LB37HL lb37_d1e888,lb37_d1eadc,lb37_d1ebe4;
struct LB37Group{char undecoded0[12];vector<LB37HE>members;vector<LB37HE>*members416f40()throw();};struct LB37HG{int id;LB37Group*get9b7250()const throw();};
struct LB37Cell{unsigned char flag4550b0()throw();};struct LB37Grid{int width,height;LB37Cell**cells;LB37Grid();~LB37Grid();LB37Cell**at9ceda0(int,int)throw();int height9b8f00()throw();};extern LB37Grid lb37_cfd44c;
struct LB37Weights{vector<LB37Def*>values;vector<int>weights;int total;LB37Weights();~LB37Weights();void add9ba310(LB37Def*,int);bool empty9b81b0()const throw();LB37Def*&pick9ba470();};
static_assert(sizeof(LB37Weights)==36&&sizeof(LB37P)==8&&sizeof(LB37Area)==16,"real native owner extents");
extern vector<LB37Def*>lb37_d25de0;extern LB37Terrain*lb37_cefb88;
LB37P lb37_random9d5350(const vector<LB37P>&);void lb37_terrain6c9c90(LB37P&,LB37Terrain*);void lb37_decode510360(string&);bool lb37_lookup9d7530(vector<LB37Def*>&,const string&,LB37Def*&);bool lb37_terrain448b80(const LB37P&);
struct LB37World{char undecoded0[0x4c];vector<LB37HG>groups;LB37HE spawn6c5dc0(const string&,const LB37P&,int,bool,int,int,bool);LB37HE spawn6c58c0(LB37Def*,const LB37P&,int,bool,int,int,bool);bool dialogue6c65a0(LB37HE,const string&,bool);bool near71c150(const LB37P&,LB37P&,int);void populate6dfdb0();};
void LB37World::populate6dfdb0(){
 if(lb37_d1e888.equal9b78e0(lb37_d1eadc)){
  vector<LB37P>first;first.push_back(LB37P(20,35));first.push_back(LB37P(145,160));
  for(int i=0;i<100;i++){
   int base=lb37_random9d5350(first).random40c130();int slots=-1;
   if(rng.chance(50)){for(int j=0;j<65;j++){if((*lb37_cfd44c.at9ceda0(base,j))->flag4550b0()){if(j>25){slots=j-15;goto foundY;}else break;}}}
   else{for(int j=lb37_cfd44c.height9b8f00()-1;j>lb37_cfd44c.height9b8f00()-65;j--){if((*lb37_cfd44c.at9ceda0(base,j))->flag4550b0()){if(j<lb37_cfd44c.height9b8f00()-25){slots=j+15;break;}else break;}}}
foundY:
   if(slots!=-1){LB37P mode(base,slots);lb37_terrain6c9c90(mode,lb37_cefb88);LB37HE a=spawn6c5dc0("Explorer",mode,9,false,0,0,false);if(a.valid9b7230()){string s="^10_QZ-1L1";lb37_decode510360(s);a.get9b6570()->rename45b070(s);s="^10_HFA_Qznln_Htsywtq";lb37_decode510360(s);dialogue6c65a0(a,s,false);}break;}
  }
 }
 if(lb37_d1e888.equal9b78e0(lb37_d1ebe4)){
  LB37Def*first;LB37Weights count;
  if(lb37_d1e888.get9b7910()->depth<5){
   if(lb37_lookup9d7530(lb37_d25de0,"Thug_7",first))count.add9ba310(first,25);
   if(lb37_lookup9d7530(lb37_d25de0,"Thug_5",first))count.add9ba310(first,5);
   if(lb37_lookup9d7530(lb37_d25de0,"Mutant_8",first))count.add9ba310(first,4);
   if(lb37_lookup9d7530(lb37_d25de0,"Mutant_7",first))count.add9ba310(first,9);
   if(lb37_lookup9d7530(lb37_d25de0,"Mutant_6",first))count.add9ba310(first,4);
   if(lb37_lookup9d7530(lb37_d25de0,"Mutant_5",first))count.add9ba310(first,3);
   if(lb37_lookup9d7530(lb37_d25de0,"Savage_7",first))count.add9ba310(first,8);
   if(lb37_lookup9d7530(lb37_d25de0,"Savage_5",first))count.add9ba310(first,2);
   if(lb37_lookup9d7530(lb37_d25de0,"Butcher_7",first))count.add9ba310(first,8);
   if(lb37_lookup9d7530(lb37_d25de0,"Butcher_5",first))count.add9ba310(first,2);
   if(lb37_lookup9d7530(lb37_d25de0,"Wasp_7",first))count.add9ba310(first,8);
   if(lb37_lookup9d7530(lb37_d25de0,"Wasp_5",first))count.add9ba310(first,2);
   if(lb37_lookup9d7530(lb37_d25de0,"Fireman_7",first))count.add9ba310(first,8);
   if(lb37_lookup9d7530(lb37_d25de0,"Fireman_5",first))count.add9ba310(first,2);
   if(lb37_lookup9d7530(lb37_d25de0,"Guerilla_7",first))count.add9ba310(first,4);
   if(lb37_lookup9d7530(lb37_d25de0,"Guerilla_5",first))count.add9ba310(first,1);
   if(lb37_lookup9d7530(lb37_d25de0,"Wizard_7",first))count.add9ba310(first,4);
   if(lb37_lookup9d7530(lb37_d25de0,"Wizard_5",first))count.add9ba310(first,1);
  }else{
   if(lb37_lookup9d7530(lb37_d25de0,"Thug_5",first))count.add9ba310(first,30);
   if(lb37_lookup9d7530(lb37_d25de0,"Mutant_6",first))count.add9ba310(first,10);
   if(lb37_lookup9d7530(lb37_d25de0,"Mutant_5",first))count.add9ba310(first,10);
   if(lb37_lookup9d7530(lb37_d25de0,"Savage_5",first))count.add9ba310(first,10);
   if(lb37_lookup9d7530(lb37_d25de0,"Butcher_5",first))count.add9ba310(first,10);
   if(lb37_lookup9d7530(lb37_d25de0,"Wasp_5",first))count.add9ba310(first,10);
   if(lb37_lookup9d7530(lb37_d25de0,"Fireman_5",first))count.add9ba310(first,10);
   if(lb37_lookup9d7530(lb37_d25de0,"Guerilla_5",first))count.add9ba310(first,5);
   if(lb37_lookup9d7530(lb37_d25de0,"Wizard_5",first))count.add9ba310(first,5);
  }
  if(!count.empty9b81b0()){
   int base=25;LB37Area mode(19,43,61,86),a(18,64,30,86);LB37P mask;
   for(int i=0;i<25;i++){for(int j=50;j>0;j--){
    mode.random40be30(&mask);while(a.contains40b750(mask))mode.random40be30(&mask);
    if(near71c150(mask,mask,1)&&!lb37_terrain448b80(mask)){LB37HE other=spawn6c58c0(count.pick9ba470(),mask,9,true,34,14,false);if(other.valid9b7230())other.get9b6570()->ai45b590()->area459410(mode);break;}
   }}
   vector<LB37HE>*source=groups[9].get9b7250()->members416f40();for(unsigned i=0;i<source->size();i++)if(!mode.contains40b750((*source)[i].get9b6570()->pos45a4a0()))(*source)[i].get9b6570()->remove637bb0();
   vector<LB37HE>*key=groups[3].get9b7250()->members416f40();for(unsigned i=0;i<key->size();i++)if((*key)[i].get9b6570()->faction45a2c0()==10&&(*key)[i].get9b6570()->name45a280()=="N-01 Spotter")(*source)[i].get9b6570()->remove637bb0();
  }
 }
}
