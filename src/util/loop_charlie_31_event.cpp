#include <string>
#include <vector>
#include "rng.h"
using namespace std;extern RNG rng;
// NOTE: borrowed native partial views; all local owners are actual native containers/string.
struct LC31Point{int x,y;LC31Point()throw();LC31Point(int,int)throw();LC31Point(const LC31Point&)throw();LC31Point&operator=(const LC31Point&)throw();LC31Point&add409a30(const LC31Point&)throw();int clamp40c270(int)throw();};
struct LC31FRange{float first,last;float clamp40c760(float)throw();};
struct LC31Entity;struct LC31Item;struct LC31Con;
struct LC31HE{int id;LC31HE()throw();bool valid9b7230()const throw();LC31Entity*get9b6570()const throw();bool operator==(LC31HE)const throw();bool operator!=(LC31HE)const throw();};
struct LC31HI{int id;LC31HI()throw();bool valid9b7230()const throw();LC31Item*get9b65b0()const throw();};
struct LC31Item{int accuracy578b10();int kind457880()throw();int recoil458100();int perfect4580c0();};
struct LC31Entity{const LC31Point&pos45a4a0()throw();vector<LC31Point>*cells45d1a0()throw();bool hostile45aa70(LC31HE);LC31Point nearest5c80f0(const LC31Point&);bool weapons5d6a80(vector<LC31HI>*,const LC31Point&,int);bool melee5c87f0(const LC31Point&);LC31HI weapon5d5d40();int effect5d2090(int);int recoil5c7e90();};
struct LC31Cell{LC31HE entity45d250()throw();};struct LC31Cells{int width,height;LC31Cell**data;LC31Cells();~LC31Cells();LC31Cell**at9ceda0(int,int)throw();};extern LC31Cells lc31_cfd44c;
struct LC31Scan{int tick;};struct LC31Scans{int width,height;LC31Scan*data;LC31Scans();~LC31Scans();LC31Scan*at9cdf20(int,int)throw();};
struct LC31World{char p0[0x66c];LC31HE player;char p670[0x740-0x670];LC31Scans scans;int generation;LC31HE player4630f0()throw();bool visible4631f0(LC31HE);bool known463400(LC31HE);float percent718430(LC31HE,const LC31Point&,vector<float>*,int);float alternate719a90(LC31HE,const LC31Point&,vector<float>*,bool*);};extern LC31World*lc31_cefc4c;
struct LC31Con{bool contains417440(const LC31Point&)throw();};struct LC31Label{int type;LC31Con*console;};
struct LC31Column{int value,next;};extern LC31Column lc31_cefd20[],lc31_cefd24[];extern bool lc31_bcbe54[];extern int lc31_cf27f4,lc31_cf27f8,lc31_d28e50;extern bool lc31_cefc5c;extern LC31Point lc31_d2c3f4;extern LC31FRange lc31_d37978,lc31_cf195c;
int lc31_max9cdb60(int,int)throw();bool lc31_contains9d31e0(vector<LC31HE>&,LC31HE)throw();void lc31_move810180(vector<LC31HE>&,vector<LC31HE>&);string intToString(int);float lc31_average9e27b0(vector<float>&);
struct LC31Map{char p0[0x6c];LC31Point offset;char p74[0x1d8-0x74];vector<LC31Label*>labels;void bounds8051f0(LC31Point&,LC31Point&)throw();bool visible8052f0(const LC31Point&)throw();bool inBounds417360(int,int)throw();LC31Point absolute428650(LC31Point)throw();void add815800(const LC31Point&,int,int,const string&,int);int event816180(int,LC31HE,string,int);};
int LC31Map::event816180(int type,LC31HE focus,string input,int kind){
 vector<LC31HE>group;vector<LC31Con*>base;
 if(focus.valid9b7230()){group.push_back(focus);for(unsigned i=0;i<labels.size();i++)if(labels[i]->type==type)base.push_back(labels[i]->console);}
 else{LC31Point branch,direction;bounds8051f0(branch,direction);vector<LC31HE>facing;
  for(int first=branch.x,count=lc31_max9cdb60(offset.x,0);first<=direction.x&&count<lc31_cf27f4;first++,count++)for(int x=branch.y,height=lc31_max9cdb60(offset.y,0);x<=direction.y&&height<lc31_cf27f8;x++,height++){
   if(lc31_cfd44c.at9ceda0(first,x)[0]->entity45d250().valid9b7230()&&lc31_cfd44c.at9ceda0(first,x)[0]->entity45d250()!=lc31_cefc4c->player&&lc31_cefc4c->player.get9b6570()->hostile45aa70(lc31_cfd44c.at9ceda0(first,x)[0]->entity45d250())&&lc31_cefc4c->known463400(lc31_cfd44c.at9ceda0(first,x)[0]->entity45d250())&&!lc31_contains9d31e0(facing,lc31_cfd44c.at9ceda0(first,x)[0]->entity45d250()))facing.push_back(lc31_cfd44c.at9ceda0(first,x)[0]->entity45d250());
  }
  if(!facing.empty()){group.push_back(facing.back());facing.pop_back();lc31_move810180(facing,group);}if(group.empty())return 0;
 }
 int count=0;LC31HE a;vector<LC31Point>other;LC31Point radius;int active,direction,cost;
 for(unsigned i=0;i<group.size();i++){
  a=group[i];vector<vector<int> >facing(a.get9b6570()->cells45d1a0()->size());for(unsigned j=0;j<facing.size();j++)facing[j].assign(2u,0u);string text;
  if(input.empty()){
   LC31Point near=a.get9b6570()->nearest5c80f0(lc31_cefc4c->player4630f0().get9b6570()->pos45a4a0());
   if(lc31_d28e50==0){int overrideValue=-1;text=intToString(overrideValue==-1?lc31_d2c3f4.clamp40c270((int)(lc31_cefc4c->percent718430(lc31_cefc4c->player4630f0(),near,0,0)*100.0)):overrideValue);text+="%";}
   else{vector<LC31HI>group;lc31_cefc4c->player.get9b6570()->weapons5d6a80(&group,near,-1);int idx=1;
    if(group.empty()){LC31HI melee;if(lc31_cefc4c->player.get9b6570()->melee5c87f0(near))melee=lc31_cefc4c->player.get9b6570()->weapon5d5d40();if(melee.valid9b7230()){group.push_back(melee);idx=0;}}
    if(group.empty()){if(lc31_cefc5c&&rng.chance(1)){switch(rng.rangeInt(0.0f,10.0f)){
     case 0:text="botnet good";break;case 1:text="mtf made me do it";break;case 2:text="avg=lol";break;case 3:text="this is what you get when you complain";break;case 4:text="buff sever, they said";break;case 5:text="oh no, where's the base hit%?";break;case 6:text="do you like it?";break;case 7:text="0% dude";break;case 8:text="move yer butt";break;case 9:text="sad";break;case 10:text="combat log was a better idea";break;
    }}else text="OoR";}
    else{float center=idx==0?lc31_cefc4c->alternate719a90(lc31_cefc4c->player,near,0,0):lc31_cefc4c->percent718430(lc31_cefc4c->player,near,0,0);vector<float>vec;
     for(unsigned j=0;j<group.size();j++){LC31HI type=group[j];float active=type.get9b65b0()->accuracy578b10()/100.0;float mode=type.get9b65b0()->kind457880()==24?lc31_cefc4c->player.get9b6570()->effect5d2090(93)/100.0:0.0;float first=0.0f;float a=center+active+mode+first;float index=0.0f;int count=lc31_cefc4c->player.get9b6570()->recoil5c7e90();for(unsigned k=0;k<group.size();k++){if(k!=j){index+=lc31_max9cdb60(0,group[k].get9b65b0()->recoil458100()-count)/100.0;}}a-=index;a=idx?lc31_d37978.clamp40c760(a):lc31_cf195c.clamp40c760(a);if(type.get9b65b0()->perfect4580c0()>=1)a=1.0f;vec.push_back(a);}
     text=intToString((int)((lc31_average9e27b0(vec)+0.001)*100.0));text+="%";
    }
   }
  }else text=input;
  active=(text.size()+5)/2;direction=6;vector<LC31Point>*cells=a.get9b6570()->cells45d1a0();
  for(unsigned j=0;j<cells->size();j++)for(unsigned k=0;k<facing[j].size();k++){
   cost=0;int n=0,x=(*cells)[j].x+lc31_cefd20[k].value-(lc31_bcbe54[k]?active-1:0);int y=(*cells)[j].y+lc31_cefd24[k].value;
   for(;n<active;n++,x++){
    if(visible8052f0(LC31Point(x,y))){if(lc31_cfd44c.at9ceda0(x,y)[0]->entity45d250().valid9b7230()&&(lc31_cefc4c->visible4631f0(lc31_cfd44c.at9ceda0(x,y)[0]->entity45d250())||lc31_cefc4c->scans.at9cdf20(x,y)->tick==lc31_cefc4c->generation)){if(lc31_cfd44c.at9ceda0(x,y)[0]->entity45d250()==a)cost+=100;else cost+=10;continue;}}
    else if(!inBounds417360(x+offset.x,y+offset.y)){cost+=2;continue;}
    LC31Point point(x,y);point.add409a30(offset);point=absolute428650(point);for(unsigned q=0;q<base.size();q++)if(base[q]->contains417440(point)){cost++;break;}
   }
   if(cost!=0)facing[j][k]=cost;else{radius=(*cells)[j];direction=k;goto placed;}
  }
  if(direction==6){cost=facing[0][0];radius=(*cells)[0];direction=0;for(unsigned j=0;j<cells->size();j++)for(unsigned k=1;k<facing[j].size();k++)if(facing[j][k]<cost){cost=facing[j][k];radius=(*cells)[j];direction=k;}}
placed:add815800(radius,type,direction,text,kind);base.push_back(labels.back()->console);count++;
 }
 return count;
}
