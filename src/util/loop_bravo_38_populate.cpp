// NOTE: private borrowed world/record views and native weighted owners for6e3c30.
#include <string>
#include <vector>
#include "rng.h"
using std::string;using std::vector;extern RNG rng;
struct LB38P{int x,y;LB38P()throw();LB38P(int,int)throw();LB38P(const LB38P&)throw();LB38P&operator=(const LB38P&)throw();int random40c130()throw();};
struct LB38Area{LB38P min,max;LB38Area(int,int,int,int)throw();LB38P random40be90()throw();bool contains40b750(const LB38P&)throw();void random40be30(LB38P*)throw();};
struct LB38Def;struct LB38Terrain;struct LB38AI{void area459410(const LB38Area&)throw();void follow5b2f80(struct LB38HE,int);};
struct LB38Entity{void talk6395d0(struct LB38Talk*,bool);bool talk6396a0(const string&,bool);void rename45b070(const string&);LB38AI*ai45b590()throw();const LB38P&pos45a4a0()throw();int faction45a2c0()throw();const string&name45a280()throw();void remove637bb0();};
struct LB38HE{LB38HE()throw();int id;bool valid9b7230()const throw();LB38Entity*get9b6570()const throw();};
struct LB38Cell{unsigned char flag4550b0()throw();LB38HE entity45d250()throw();bool pass66ab30(LB38HE);};struct LB38Grid{int width,height;LB38Cell**cells;LB38Grid();~LB38Grid();LB38Cell**point9cf7d0(LB38P&)throw();LB38Cell**at9ceda0(int,int)throw();int height9b8f00()throw();};extern LB38Grid lb38_cfd44c;
struct LB38Weights{vector<LB38Def*>values;vector<int>weights;int total;LB38Weights();~LB38Weights();void add9ba310(LB38Def*,int);bool empty9b81b0()const throw();LB38Def*&pick9ba470();unsigned count9b81d0()const throw();};
static_assert(sizeof(LB38Weights)==36&&sizeof(LB38P)==8&&sizeof(LB38Area)==16,"real native owner extents");
extern vector<LB38Def*>lb38_d25de0;extern LB38Terrain*TERRAIN_EARTH;
LB38P lb38_random9d5350(const vector<LB38P>&);void lb38_terrain6c9c90(LB38P&,LB38Terrain*);void lb38_decode510360(string&);bool lb38_lookup9d7530(vector<LB38Def*>&,const string&,LB38Def*&);bool lb38_terrain448b80(const LB38P&);
struct LB38World{LB38World();~LB38World();LB38HE spawn6c5dc0(const string&,const LB38P&,int,bool,int,int,bool);LB38HE spawn6c58c0(LB38Def*,const LB38P&,int,bool,int,int,bool);bool dialogue6c65a0(LB38HE,const string&,bool);bool near71c150(const LB38P&,LB38P&,int);void terrain6c38a0(struct LB38Rect&,int,float,LB38Terrain*);LB38Def*find6c5600(int,int,bool,bool);vector<struct LB38Exit*>*exits462e10()throw();bool path716940(const LB38P&,const LB38P&,LB38Entity*,unsigned*);void populate6e3c30();};

struct LB38Rect{int x,y,w,h;LB38Rect(int,int,int,int)throw();};
struct LB38Def{char omitted0[0x140];int index;};
struct LB38EventDef{char omitted0[0x7c];string name;int unknown98;int weight;LB38EventDef();~LB38EventDef();};
struct LB38Talk{LB38Talk();~LB38Talk();int unknown0;string name;char omitted20[0xa0];vector<LB38Def*>defs;};
struct LB38TalkWeights{vector<LB38Talk*>values;vector<int>weights;int total;LB38TalkWeights();~LB38TalkWeights();void add9ba310(LB38Talk*,int);bool empty9b81b0()const throw();LB38Talk*&pick9ba470();void remove9bab80(LB38Talk*);};
struct LB38Exit{LB38P pos;};extern LB38World*lb38_cefc4c;extern vector<LB38Talk*>lb38_d2c408;extern vector<int>lb38_cf4934;extern vector<LB38EventDef*>lb38_cf3a20;extern const string lb38_d292f4;extern vector<int>lb38_cfc1a4;extern const float lb38_c36f64;extern LB38Terrain*lb38_d2c46c;
bool lb38_contains9d3fe0(vector<string>&,string);bool lb38_contains9db330(vector<int>&,int);
void LB38World::populate6e3c30(){
 LB38Area mode(2,2,71,97),a(84,13,126,84);vector<LB38P>vec;
 vec.push_back(LB38P(132,71));
 vec.push_back(LB38P(133,71));
 vec.push_back(LB38P(134,71));
 vec.push_back(LB38P(134,72));
 vec.push_back(LB38P(133,73));
 vec.push_back(LB38P(134,73));
 vec.push_back(LB38P(134,74));
 vec.push_back(LB38P(131,75));
 vec.push_back(LB38P(132,75));
 vec.push_back(LB38P(133,75));
 vec.push_back(LB38P(134,75));
 for(unsigned i=0;i<vec.size();i++)lb38_terrain6c9c90(vec[i],TERRAIN_EARTH);
 terrain6c38a0(LB38Rect(73,51,4,23),0,1.0f,lb38_d2c46c);
 LB38Def*found;LB38Weights index;
 if(lb38_lookup9d7530(lb38_d25de0,"Federalist",found))index.add9ba310(found,10);
 if(lb38_lookup9d7530(lb38_d25de0,"Explorer",found))index.add9ba310(found,10);
 if(lb38_lookup9d7530(lb38_d25de0,"Ranger",found))index.add9ba310(found,10);
 if(lb38_lookup9d7530(lb38_d25de0,"Guru",found))index.add9ba310(found,5);
 if(lb38_lookup9d7530(lb38_d25de0,"Scientist",found))index.add9ba310(found,5);
 if(lb38_lookup9d7530(lb38_d25de0,"Scrapper_3",found))index.add9ba310(found,45);
 if(lb38_lookup9d7530(lb38_d25de0,"Elite_4",found))index.add9ba310(found,5);
 if(lb38_lookup9d7530(lb38_d25de0,"Zionite",found))index.add9ba310(found,3);
 if(lb38_lookup9d7530(lb38_d25de0,"Tinkerer",found))index.add9ba310(found,2);
 if(lb38_lookup9d7530(lb38_d25de0,"Thug_5",found))index.add9ba310(found,2);
 if(lb38_lookup9d7530(lb38_d25de0,"Savage_5",found))index.add9ba310(found,1);
 if(lb38_lookup9d7530(lb38_d25de0,"Butcher_5",found))index.add9ba310(found,1);
 if(lb38_lookup9d7530(lb38_d25de0,"Mutant_5",found))index.add9ba310(found,1);
 vector<string>s;
 s.push_back("Zionite");
 s.push_back("Tinkerer");
 s.push_back("Thug_5");
 s.push_back("Savage_5");
 s.push_back("Butcher_5");
 s.push_back("Mutant_5");
 if(index.count9b81d0()){
  int idx2=25,y=10;float base=lb38_c36f64;int line=0;LB38P key;LB38TalkWeights count;vector<LB38P>first;
  for(unsigned i=0;i<lb38_d2c408.size();i++)if(lb38_d2c408[i]->name.find(lb38_d292f4+"SCR")!=string::npos&&!lb38_cf4934[lb38_d2c408[i]->defs.front()->index])count.add9ba310(lb38_d2c408[i],lb38_cf3a20[lb38_d2c408[i]->defs.front()->index]->weight);
  for(int i=0;i<25;i++){
   LB38Area&selected=(i<base*25.0)?a:mode;
   for(int j=500;j>0;j--){selected.random40be30(&key);if(near71c150(key,key,1)&&!lb38_terrain448b80(key)){
    LB38HE e;e=spawn6c58c0(index.pick9ba470(),key,10,true,34,14,false);
    if(line<10&&!count.empty9b81b0()&&!lb38_contains9d3fe0(s,e.get9b6570()->name45a280())){
     LB38Talk*t=count.pick9ba470();e.get9b6570()->talk6395d0(t,false);lb38_cf4934[t->defs.front()->index]=1;line++;count.remove9bab80(t);
    }break;
   }}
  }
 }
 LB38Def*key=find6c5600(3,38,false,true);
 if(!key)goto afterGroups;{int state=3;LB38P range(2,3);
  for(int i=0;i<3;i++){LB38HE leader;for(int j=range.random40c130();j>0;j--){
   if(leader.valid9b7230()){LB38HE e=lb38_cefc4c->spawn6c58c0(key,leader.get9b6570()->pos45a4a0(),10,true,34,14,false);if(e.valid9b7230())e.get9b6570()->ai45b590()->follow5b2f80(leader,0);}
   else{vector<LB38Exit*>*exits=lb38_cefc4c->exits462e10();LB38P pos;for(int k=0;k<100;k++){
    pos=(i?mode.random40be90():a.random40be90());
    if((*lb38_cfd44c.point9cf7d0(pos))->pass66ab30(LB38HE())){for(unsigned l=0;l<exits->size();l++){if(path716940(pos,(*exits)[l]->pos,0,0)){leader=lb38_cefc4c->spawn6c58c0(key,pos,10,true,34,14,false);goto placed;}}}
   }placed:;
   }
  }}
 }
afterGroups:
 if(rng.chance(50)){if(lb38_lookup9d7530(lb38_d25de0,"Explorer",found)){LB38P pos;for(int j=500;j>0;j--){mode.random40be30(&pos);if(near71c150(pos,pos,1)&&!lb38_terrain448b80(pos)){LB38HE e=lb38_cefc4c->spawn6c58c0(found,pos,10,true,34,14,false);e.get9b6570()->rename45b070(string("KTG-V3"));e.get9b6570()->talk6396a0("SCR_Great_Nut_Preacher",false);break;}}}}
 if(lb38_contains9db330(lb38_cfc1a4,50)){(*lb38_cfd44c.at9ceda0(39,96))->entity45d250().get9b6570()->remove637bb0();(*lb38_cfd44c.at9ceda0(41,96))->entity45d250().get9b6570()->remove637bb0();}
}
