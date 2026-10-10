// NOTE: private borrowed BS views; genuine native string/Point owners for73d320.
#include <string>
#include <vector>
#include "rng.h"
using std::string;using std::vector;extern RNG rng;
struct LB41P{int x,y;LB41P(const LB41P&)throw();LB41P&operator=(const LB41P&)throw();};
struct LB41Area{LB41P min,max;LB41Area(const LB41Area&)throw();LB41P random40be90()throw();};
struct LB41AI{void area459470(const LB41Area&)throw();void follow5b2f80(struct LB41HE,int);};
struct LB41Entity{int faction45a2c0()throw();const LB41P&pos45a4a0()throw();LB41AI*ai45b590()throw();};
struct LB41HE{int id;LB41HE()throw();bool valid9b7230()const throw();bool null9b65d0()const throw();LB41Entity*get9b6570()const throw();};
struct LB41Group{vector<LB41HE>*members416f40()throw();};struct LB41HG{int id;LB41Group*get9b7250()const throw();};
struct LB41State{int unknown0,type;};struct LB41HS{int id;LB41State*get9b7910()const throw();};extern LB41HS lb41_d1e888;extern int lb41_d1eb68;
struct LB41Grid{LB41Area area9b4400()throw();};extern LB41Grid lb41_cfd44c;
struct LB41IntWeights{vector<int>values,sum;int total;LB41IntWeights(vector<int>&);~LB41IntWeights();int&pick9ba470()throw();};
struct LB41StringWeights{vector<string>values;vector<int>sum;int total;LB41StringWeights();~LB41StringWeights();void add9b9f50(string,int);string&pick9b9fd0()throw();};
struct LB41Def{char omitted0[0x9c];int size;};extern vector<LB41Def*>lb41_d25de0;bool lb41_find9d7530(vector<LB41Def*>&,const string&,LB41Def*&);
int lb41_min9cdb30(int,int)throw();void lb41_shuffle9d7350(vector<LB41P>&);LB41Area lb41_random9d7d20(vector<LB41Area>&)throw();
struct LB41Squad;struct LB41Dispatch{LB41Squad*spawnHunterParty(LB41HE,const LB41P*,bool);};extern LB41Dispatch lb41_cf6428;
struct LB41World{char omitted0[0x4c];vector<LB41HG>groups;char omitted5c[0x858];vector<LB41Area>areas;int faction;bool reinforce73d320(bool,bool,bool,const LB41P*);LB41HE spawn6c5dc0(const string&,const LB41P&,int,bool,int,int,bool);bool dialogue6c65a0(LB41HE,const string&,bool);bool place71c300(const LB41P&,int,int,LB41P&,bool);};
bool LB41World::reinforce73d320(bool local,bool existing,bool limited,const LB41P*at){
 bool result=false;
 if(local){
  vector<vector<string> >room;vector<int>sum;
  room.push_back(vector<string>());room.back().insert(room.back().end(),6,"Wasp_7");sum.push_back(10);
  room.push_back(vector<string>());room.back().insert(room.back().end(),5,"Thug_7");sum.push_back(10);
  room.push_back(vector<string>());room.back().insert(room.back().end(),1,"Thug_7");sum.push_back(10);room.back().insert(room.back().end(),2,"Savage_7");room.back().insert(room.back().end(),2,"Butcher_7");
  room.push_back(vector<string>());room.back().insert(room.back().end(),5,"Butcher_7");sum.push_back(10);
  room.push_back(vector<string>());room.back().insert(room.back().end(),2,"Guerilla_7");sum.push_back(10);room.back().insert(room.back().end(),2,"Wasp_7");
  room.push_back(vector<string>());room.back().insert(room.back().end(),3,"Wizard_7");sum.push_back(10);
  room.push_back(vector<string>());room.back().insert(room.back().end(),2,"Mutant_8");sum.push_back(10);room.back().insert(room.back().end(),2,"Mutant_7");
  room.push_back(vector<string>());room.back().insert(room.back().end(),2,"Martyr_7");sum.push_back(10);room.back().insert(room.back().end(),1,"Mutant_8");room.back().insert(room.back().end(),2,"Thug_7");
  room.push_back(vector<string>());room.back().insert(room.back().end(),5,"Fireman_7");sum.push_back(10);
  room.push_back(vector<string>());room.back().insert(room.back().end(),2,"Marauder_8");sum.push_back(10);
  LB41IntWeights group(sum);const int total=50;LB41StringWeights list;
  list.add9b9f50("Commander",1);list.add9b9f50("Knight",1);list.add9b9f50("Troll",1);list.add9b9f50("Dragon",1);list.add9b9f50("Hydra",1);
  const int done=10;vector<LB41P>a;
  if(at){int count=1;if(lb41_d1eb68){int n=lb41_min9cdb30(lb41_d1eb68/20+1,(lb41_d1e888.get9b7910()->type==5)+1);count+=n;}a.assign(count,*at);}
  else{
   if(existing){vector<LB41HE>*members=groups[faction].get9b7250()->members416f40();for(unsigned i=0;i<members->size();i++)if((*members)[i].get9b6570()->faction45a2c0()==68){a.push_back((*members)[i].get9b6570()->pos45a4a0());a.back().y++;a.back().x-=3;}}
   else for(unsigned i=0;i<areas.size();i++)a.push_back(areas[i].random40be90());
   if(limited){lb41_shuffle9d7350(a);while(a.size()>2)a.pop_back();}
   if(lb41_d1eb68){int count=lb41_min9cdb30(lb41_d1eb68/20+1,3);for(int i=0;i<count;i++)a.push_back(lb41_random9d7d20(areas).random40be90());}
  }
  LB41Area first=lb41_cfd44c.area9b4400();
  for(unsigned i=0;i<a.size();i++){
   LB41HE entity,h;int k=group.pick9ba470();vector<string>*entities=&room[k];bool changed=false;
   if(rng.chance(done)){entities->push_back("Surgeon_6");changed=true;}
   for(unsigned j=0;j<entities->size();j++){
    if(j==0&&rng.chance(total)){entity=spawn6c5dc0(list.pick9b9fd0(),a[i],faction,existing,34,14,false);if(entity.valid9b7230())entity.get9b6570()->ai45b590()->area459470(first);}
    LB41P pos(a[i]);if(at){LB41Def*def;lb41_find9d7530(lb41_d25de0,(*entities)[j],def);place71c300(pos,4,def->size,pos,false);}
    h=spawn6c5dc0((*entities)[j],pos,faction,existing,34,14,false);
    if(h.valid9b7230()){
     if(h.get9b6570()->faction45a2c0()!=8)h.get9b6570()->ai45b590()->area459470(first);
     if(entity.null9b65d0())entity=h;else h.get9b6570()->ai45b590()->follow5b2f80(entity,0);
     if(rng.chance(25))dialogue6c65a0(h,"RES_Attack_Machines_LF",false);
    }
   }
   if(at&&entity.valid9b7230()&&i==0)dialogue6c65a0(entity,"RES_Straggler_Talk",false);
   if(changed)entities->pop_back();
  }
  result=!a.empty();
 }else if(lb41_cf6428.spawnHunterParty(LB41HE(),0,false))result=true;
 return result;
}
