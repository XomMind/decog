// NOTE: private borrowed BS/found views; genuine native owners, placeholder names.
#include <string>
#include <vector>
#include <cstdlib>
using std::string;using std::vector;
struct LB39P{int x,y;LB39P()throw();LB39P(int,int)throw();LB39P(const LB39P&)throw();LB39P&operator=(const LB39P&)throw();};
struct LB39Rect{int x,y,w,h;LB39Rect();LB39Rect(const LB39Rect&);bool contains40aa00(const LB39P&)throw();};
struct LB39Room{int type;LB39Rect rect;vector<int>a14;int a24;vector<LB39P>doors;vector<int>dirs,corridors;int level;vector<int>a5c;LB39Room();~LB39Room();LB39Room(const LB39Room&);};
struct LB39Item{bool powered457cf0()throw();int type44aec0()throw();int field457880()throw();void set450460(int)throw();void setup458390(bool)throw();};
struct LB39HI{int id;bool valid9b7230()const throw();LB39Item*get9b65b0()const throw();};
struct LB39Entity{void change5dccb0(const LB39P&,bool);void rename45b070(const string&);void score5dea60(int,bool);int*values45a840()throw();int amount5ca670();void set45b240(int);void budgets5c93d0(vector<int>*);vector<LB39HI>*inventory45ab00()throw();int state5dc440(LB39HI);bool test5cd220(LB39HI);bool activate64da50(LB39HI);};
struct LB39HE{int id;LB39Entity*get9b6570()const throw();};
struct LB39Def{char omitted0[0x1cc];int values[4];int health;};
struct LB39Map{int index;char omitted4[0x48];int cost,depth,kindA,kindB;char omitted5c[4];int weight;char omitted64[0x30];int special;char omitted98[0x1db];bool eligible;};
struct LB39Weight{vector<int>values,weights;int total;void add9ba310(int,int);int&pick9ba470()throw();};
struct LB39HG{int id;};struct LB39RGB{unsigned char r,g,b;LB39RGB();LB39RGB(const LB39RGB&)throw();};
struct LB39Group{LB39HG self;int a4,a8;vector<LB39HE>members;bool a1c;int a20,a24;bool a28;vector<LB39RGB>colors;LB39Group(int);~LB39Group();};
struct LB39Cell{bool can4550b0()throw();};
struct LB39Cells{int width,height;LB39Cell**data;LB39P random9cf050()throw();LB39Cell**point9cf7d0(LB39P&)throw();LB39Cell**at9ceda0(int,int)throw();int width9fcd80()throw();int height9b8f00()throw();};
struct LB39Grid{int width,height;int*data;LB39Grid();LB39Grid(int,int,int);~LB39Grid();void resize9ec850(int,int);int*at9ceda0(int,int)throw();};
struct LB39GM{bool names7913f0(const string&,vector<string>*,vector<string>*);LB39HG group793410(LB39Group*);};
struct LB39World{char omitted0[8];LB39P position;char omitted10[0x3c];vector<LB39HG>groups;LB39Grid relations;char omitted68[0x604];LB39HE player;char omitted670[0x4dc];LB39Weight weights;char omittedb70[0x10];LB39Grid*boundary;vector<LB39P>corners;void setup6ed7d0();LB39HI item6c5400(LB39Map*,const LB39P&);LB39HI add6c51d0(LB39Map*,LB39HE,bool,bool);LB39HE spawn6c58c0(LB39Def*,const LB39P&,int,bool,int,int,bool);int index6ed550(int);};
extern vector<LB39Map*>lb39_d2d1c4;extern vector<LB39Room>lb39_cf13e8;extern vector<LB39Def*>lb39_d25de0;extern LB39Cells lb39_cfd44c;extern LB39Rect lb39_cf4da4;struct LB39Range{int min,max;int range40c130()throw();};extern LB39Range lb39_d2a7d0;extern LB39GM*lb39_cefaa8;extern int lb39_ced228,lb39_cf4954;extern const float lb39_ba7ae4,lb39_ba7ae8;extern const int lb39_b94550[15][15];extern const char lb39_bef520[];
string lb39_extension4328b0();string lb39_int4051f0(int);string lb39_pop9daeb0(vector<string>&);void lb39_shuffle9d5110(vector<LB39Rect>&);LB39P lb39_place6ed660(vector<LB39Rect>&,vector<LB39Rect>&);bool lb39_find9d7530(vector<LB39Def*>&,const string&,LB39Def*&);void lb39_copy9d9460(int*,int*,unsigned);
static_assert(sizeof(LB39Group)==60&&sizeof(LB39Room)==108&&sizeof(LB39Grid)==12&&sizeof(LB39Weight)==36,"actual native owned extents");
void LB39World::setup6ed7d0(){
 int count;
 for(unsigned i=0;i<lb39_d2d1c4.size();i++){
  LB39Map*def=lb39_d2d1c4[i];if(!def->eligible)continue;if(def->kindA==0)continue;
  float odds=1.0f;switch(def->kindB){break;case 1:case 2:odds-=abs(5-def->depth)*lb39_ba7ae4;if(odds<=0.0)continue;break;}
  count=def->weight*odds;if(def->special)count*=lb39_ba7ae8;if(count>0)weights.add9ba310(def->index,count);
 }
 LB39P a;int value=0;LB39Map*index;
 for(int i=0;i<300;i++){
  index=lb39_d2d1c4[weights.pick9ba470()];
  for(int j=0;j<100;j++){
   a=lb39_cfd44c.random9cf050();if((*lb39_cfd44c.point9cf7d0(a))->can4550b0()&&!lb39_cf4da4.contains40aa00(a)){
    LB39HI item=item6c5400(index,a);if(item.valid9b7230()){
     if(item.get9b65b0()->field457880()==0)item.get9b65b0()->set450460(lb39_d2a7d0.range40c130());
     item.get9b65b0()->setup458390(false);value++;break;
    }
   }
  }
 }
 vector<string>s,mode;if(!lb39_cefaa8->names7913f0(string()+"data/misc/battleroyale"+lb39_extension4328b0(),&s,&mode)){}
 if(s.size()<30||mode.size()<30){}
 vector<LB39Rect>action,list;
 for(unsigned i=0;i<lb39_cf13e8.size();i++){if(lb39_cf13e8[i].level>=lb39_ced228)action.push_back(lb39_cf13e8[i].rect);else list.push_back(lb39_cf13e8[i].rect);}
 lb39_shuffle9d5110(action);lb39_shuffle9d5110(list);
 LB39P other;vector<LB39HE>active;active.push_back(player);
 other=lb39_place6ed660(action,list);position=other;player.get9b6570()->change5dccb0(position,true);
 LB39Def*found;lb39_find9d7530(lb39_d25de0,"Player",found);
 for(int i=0;i<29;i++){
  other=lb39_place6ed660(action,list);groups.push_back(lb39_cefaa8->group793410(new LB39Group(i+15)));
  LB39HE e=spawn6c58c0(found,other,i+15,true,34,14,false);
  e.get9b6570()->rename45b070(lb39_pop9daeb0(s)+lb39_pop9daeb0(mode)+lb39_bef520+lb39_int4051f0(i+2));
  active.push_back(e);
 }
 relations.resize9ec850(groups.size(),groups.size());
 for(int i=0,j=0;i<groups.size();i++,j++)for(int k=j;k<groups.size();k++){
  if(i<15&&k<15)*relations.at9ceda0(i,k)=*relations.at9ceda0(k,i)=lb39_b94550[i][k];
  else *relations.at9ceda0(i,k)=*relations.at9ceda0(k,i)=i==k?2:0;
 }
 lb39_cf4954=found->health;player.get9b6570()->score5dea60(lb39_cf4954,false);
 lb39_copy9d9460(found->values,player.get9b6570()->values45a840(),4);
 player.get9b6570()->set45b240(player.get9b6570()->amount5ca670());
 for(unsigned i=0;i<active.size();i++){
  vector<int>budget;active[i].get9b6570()->budgets5c93d0(&budget);
  for(unsigned j=0;j<budget.size();j++){
   while(budget[j]){int group=index6ed550(j);if(0){} /* AGENTS.md register allocator idiom; emits zero code */ {if(lb39_d2d1c4[group]->cost<=budget[j]){add6c51d0(lb39_d2d1c4[group],active[i],true,false);budget[j]-=lb39_d2d1c4[group]->cost;}}}
  }
  vector<LB39HI>*items=active[i].get9b6570()->inventory45ab00();
  for(unsigned j=0;j<items->size();j++)if(!(*items)[j].get9b65b0()->powered457cf0()&&(*items)[j].get9b65b0()->type44aec0()<=3&&!active[i].get9b6570()->state5dc440((*items)[j])&&!active[i].get9b6570()->test5cd220((*items)[j]))active[i].get9b6570()->activate64da50((*items)[j]);
 }
 boundary=new LB39Grid(lb39_cfd44c.width9fcd80(),lb39_cfd44c.height9b8f00(),0);
 for(int x=1,y=1;;x++,y++){if((*lb39_cfd44c.at9ceda0(x,y))->can4550b0()){*boundary->at9ceda0(x,y)=1;corners.push_back(LB39P(x,y));break;}}
 for(int x=1,y=lb39_cfd44c.height9b8f00()-2;;x++,y--){if((*lb39_cfd44c.at9ceda0(x,y))->can4550b0()){*boundary->at9ceda0(x,y)=1;corners.push_back(LB39P(x,y));break;}}
 for(int x=lb39_cfd44c.width9fcd80()-2,y=1;;x--,y++){if((*lb39_cfd44c.at9ceda0(x,y))->can4550b0()){*boundary->at9ceda0(x,y)=1;corners.push_back(LB39P(x,y));break;}}
 for(int x=lb39_cfd44c.width9fcd80()-2,y=lb39_cfd44c.height9b8f00()-2;;x--,y--){if((*lb39_cfd44c.at9ceda0(x,y))->can4550b0()){*boundary->at9ceda0(x,y)=1;corners.push_back(LB39P(x,y));break;}}
}
