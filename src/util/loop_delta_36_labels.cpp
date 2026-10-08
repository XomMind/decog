#include <string>
#include <vector>
#include <cstddef>
using std::string;using std::vector;
// NOTE: private names for borrowed map/entity/label views and true native local owners.
struct D36Point{int x,y;D36Point()throw();D36Point(int,int)throw();D36Point(const D36Point&)throw();D36Point&operator=(const D36Point&)throw();D36Point&add409a30(const D36Point&)throw();};
struct D36Entity;struct D36Item;struct D36Con;
struct D36HE{int id;D36HE()throw();D36Entity*get9b6570()const throw();bool valid9b7230()const throw();bool operator==(D36HE)const throw();bool operator!=(D36HE)const throw();void reset9b7270()throw();};
struct D36HI{int id;bool valid9b7230()const throw();};
struct D36Entity{const D36Point&pos45a4a0()throw();int size45a360()throw();int relation5c7fc0(D36HE);int effect5d22a0(int);D36HI item5d2380(int);int ai45a2a0()throw();bool named5c7f70();vector<D36Point>*cells45d1a0()throw();};
struct D36Cell{D36HE entity45d250()throw();bool door45dda0()throw();};struct D36Cells{int width,height;D36Cell**data;D36Cells();~D36Cells();D36Cell**at9ceda0(int,int)throw();};extern D36Cells d36_cfd44c;
struct D36Scan{int tick,unknown;D36HE entity;};struct D36Scans{int width,height;D36Scan*data;D36Scans();~D36Scans();D36Scan*at9cdf20(int,int)throw();};
struct D36Companion;struct D36HC{int id;D36Companion*get9b7250()const throw();};struct D36Companion{vector<D36HE>*members416f40()throw();};
struct D36World{char omitted00[0x66c];D36HE playerHandle;char omitted670[0x740-0x670];D36Scans scans;int generation;D36HE player4630f0()throw();bool visible4631f0(D36HE);bool sensor4632e0();D36HC companion463890(int);};extern D36World*d36_cefc4c;
struct D36Con{bool contains417440(const D36Point&)throw();};struct D36Label{int type;D36Con*console;};
struct D36Column{int value,next;};extern D36Column d36_cefd20[],d36_cefd24[];extern bool d36_bcbe54[];extern int d36_cf27f4,d36_cf27f8;
int d36_max9cdb60(int,int)throw();bool d36_range9daf80(int,int,int)throw();bool d36_contains9d31e0(vector<D36HE>&,D36HE)throw();void d36_move810180(vector<D36HE>&,vector<D36HE>&);int d36_text7fea30(D36HE,bool,string&,bool);
struct D36Map{char omitted00[0x6c];D36Point offset;char omitted74[0x1d8-0x74];vector<D36Label*>labels;char omitted1e8[0x208-0x1e8];D36Point last;D36HE anchor;void bounds8051f0(D36Point&,D36Point&)throw();bool visible8052f0(const D36Point&)throw();bool has49b1a0(int,D36HE)throw();bool inBounds417360(int,int)throw();D36Point absolute428650(D36Point)throw();bool add80fa60(bool,const D36Point&,int,int,bool,bool);int label810270(int,D36HE,bool,bool);};
int D36Map::label810270(int mode,D36HE focus,bool suffix,bool skip){
 int s=4+(mode!=0);vector<D36HE>entities;vector<D36Con*>other; int key;int radius;int top;
 if(focus.valid9b7230()){
  entities.push_back(focus);for(unsigned jj=0;jj<labels.size();jj++)if(d36_range9daf80(4,labels[jj]->type,7))other.push_back(labels[jj]->console);
  last=focus.get9b6570()->pos45a4a0();if(focus.get9b6570()->size45a360()>1)anchor=focus;else anchor.reset9b7270();
 }else{
  D36Point tile,unit;bounds8051f0(tile,unit);vector<D36HE>seen;
  for(int x0=tile.x,node=d36_max9cdb60(offset.x,0);x0<=unit.x&&node<d36_cf27f4;x0++,node++)for(int w2=tile.y,matter=d36_max9cdb60(offset.y,0);w2<=unit.y&&matter<d36_cf27f8;w2++,matter++){
   if(d36_cfd44c.at9ceda0(x0,w2)[0]->entity45d250().valid9b7230()&&d36_cfd44c.at9ceda0(x0,w2)[0]->entity45d250()!=d36_cefc4c->playerHandle&&d36_cefc4c->playerHandle.get9b6570()->relation5c7fc0(d36_cfd44c.at9ceda0(x0,w2)[0]->entity45d250())==mode&&d36_cefc4c->visible4631f0(d36_cfd44c.at9ceda0(x0,w2)[0]->entity45d250())&&!d36_contains9d31e0(seen,d36_cfd44c.at9ceda0(x0,w2)[0]->entity45d250())){
    if(skip&&has49b1a0(s,d36_cfd44c.at9ceda0(x0,w2)[0]->entity45d250()))continue;
    seen.push_back(d36_cfd44c.at9ceda0(x0,w2)[0]->entity45d250());
   }
  }
  if(!seen.empty()){entities.push_back(seen.back());seen.pop_back();d36_move810180(seen,entities);}
  bool terrain=d36_cefc4c->sensor4632e0()||d36_max9cdb60(d36_cefc4c->playerHandle.get9b6570()->item5d2380(13).valid9b7230()?4:0,d36_cefc4c->playerHandle.get9b6570()->effect5d22a0(12))>=2;
  if(!terrain){vector<D36HE>*members=d36_cefc4c->companion463890(0).get9b7250()->members416f40();for(unsigned jj=1;jj<members->size();jj++)if(d36_max9cdb60((*members)[jj].get9b6570()->item5d2380(13).valid9b7230()?4:0,(*members)[jj].get9b6570()->effect5d22a0(12))>=2){terrain=true;break;}}
  if(terrain){
   for(int x0=tile.x,node=d36_max9cdb60(offset.x,0);x0<=unit.x&&node<d36_cf27f4;x0++,node++)for(int w2=tile.y,matter=d36_max9cdb60(offset.y,0);w2<=unit.y&&matter<d36_cf27f8;w2++,matter++){
    if(d36_cefc4c->scans.at9cdf20(x0,w2)->tick==d36_cefc4c->generation&&d36_cefc4c->scans.at9cdf20(x0,w2)->entity.get9b6570()&&d36_cefc4c->playerHandle.get9b6570()->relation5c7fc0(d36_cefc4c->scans.at9cdf20(x0,w2)->entity)==mode&&!d36_contains9d31e0(entities,d36_cefc4c->scans.at9cdf20(x0,w2)->entity)&&!d36_contains9d31e0(seen,d36_cefc4c->scans.at9cdf20(x0,w2)->entity)){
     if(skip&&has49b1a0(s,d36_cefc4c->scans.at9cdf20(x0,w2)->entity))continue;
     seen.push_back(d36_cefc4c->scans.at9cdf20(x0,w2)->entity);
    }
   }
   if(!seen.empty()){if(entities.empty()){entities.push_back(seen.back());seen.pop_back();}d36_move810180(seen,entities);}
  }
  if(entities.empty())return 0;
 }
 int score=0;D36HE entity;vector<D36Point>selection;string text;D36Point bestPoint;
 for(unsigned jj=0;jj<entities.size();jj++){
  entity=entities[jj];vector<vector<int> >costs(entity.get9b6570()->cells45d1a0()->size());for(unsigned j=0;j<costs.size();j++)costs[j].assign(6u,0);
  bool selected=focus.valid9b7230()||entity.get9b6570()->ai45a2a0()==0||entity.get9b6570()->named5c7f70();
  radius=(d36_text7fea30(entity,selected,text,true)+5)/2;key=6;vector<D36Point>*cells=entity.get9b6570()->cells45d1a0();
  for(unsigned j=0;j<cells->size();j++)for(unsigned k=0;k<costs[j].size();k++){
   top=0;int turns=0;int rooms=(*cells)[j].x+d36_cefd20[k].value-(d36_bcbe54[k]?radius-1:0),origin=(*cells)[j].y+d36_cefd24[k].value;
   for(;turns<radius;turns++,rooms++){
    if(visible8052f0(D36Point(rooms,origin))){
     if(d36_cfd44c.at9ceda0(rooms,origin)[0]->entity45d250().valid9b7230()&&d36_cfd44c.at9ceda0(rooms,origin)[0]->entity45d250().get9b6570()->relation5c7fc0(d36_cefc4c->player4630f0())!=1&&(d36_cefc4c->visible4631f0(d36_cfd44c.at9ceda0(rooms,origin)[0]->entity45d250())||d36_cefc4c->scans.at9cdf20(rooms,origin)->tick==d36_cefc4c->generation)){
      if(d36_cfd44c.at9ceda0(rooms,origin)[0]->entity45d250()==entity)top+=100;else top+=10;continue;
     }else if(d36_cfd44c.at9ceda0(rooms,origin)[0]->door45dda0()){top+=6;continue;}
    }else if(!inBounds417360(rooms+offset.x,origin+offset.y)){top+=2;continue;}
    D36Point pos(rooms,origin);pos.add409a30(offset);pos=absolute428650(pos);
    for(unsigned node=0;node<other.size();node++)if(other[node]->contains417440(pos)){top++;break;}
   }
   if(top!=0)costs[j][k]=top;else{bestPoint=(*cells)[j];key=k;goto placementDone;}
  }
  if(key==6){top=costs[0][0];bestPoint=(*cells)[0];key=0;for(unsigned j=0;j<cells->size();j++)for(unsigned k=1;k<costs[j].size();k++)if(costs[j][k]<top){top=costs[j][k];bestPoint=(*cells)[j];key=k;}}
  placementDone:
  if(add80fa60(focus.valid9b7230(),bestPoint,s,key,selected,suffix)){other.push_back(labels.back()->console);score++;}
 }
 return score;
}
