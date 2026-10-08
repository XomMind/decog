// Private partial ABI views for actual prop label placement813050.
#include <string>
#include <vector>
using namespace std;
// Actual 16-byte uint32 type-code collection: external owning vector lifecycle and typed leaf calls.
struct LP25TypeCodes{void*proxy;unsigned*first,*last,*limit;LP25TypeCodes();~LP25TypeCodes();unsigned size9b9260()const throw();unsigned&operator[](unsigned)throw();void push9b9d30(const unsigned&);};
struct LPPoint{int x,y;LPPoint()throw();LPPoint(int)throw();LPPoint(int,int)throw();LPPoint(const LPPoint&)throw();LPPoint&operator=(const LPPoint&)throw();LPPoint&operator+=(const LPPoint&)throw();};
struct LPProp;struct LPEntity;struct LPConsole;struct LPHP{int id;LPHP()throw();bool valid()const throw();LPProp*get()const throw();void reset()throw();};struct LPHE{int id;bool valid()const throw();LPEntity*get()const throw();};
struct LPPropDef{char pad[0x10];int group;};struct LPProp{const LPPoint&position()throw();LPPropDef*definition()throw();};struct LPEntity{int relation(LPHE)throw();};
struct LPCell{LPHP prop()throw();LPHE entity()throw();bool door()throw();};struct LPGrid{LPCell**at(int,int)throw();};extern LPGrid lp_cfd44c;
struct LPMemo{char pad[0x24];unsigned type;int group;};struct LPMemos{LPMemo*at(int,int)throw();};struct LPSeen{int tick;};struct LPSeens{LPSeen*at(int,int)throw();};struct LPIntsGrid{int*at(int,int)throw();};
struct LPWorld{char pad0[0x69c];LPIntsGrid visible;char pad69d[0x740-0x69d];LPSeens seen;char pad744[8];int generation;char pad750[0x7c4-0x750];LPMemos memory;LPHE player()throw();bool known(LPHE)throw();int group(int,int)throw();};extern LPWorld*lp_cefc4c;
struct LPConsole{bool contains(const LPPoint&)throw();};struct LPLabel{int type;LPConsole*console;};
struct LPColumn{int value,next;};extern LPColumn lp_cefd20[],lp_cefd24[];extern bool lp_bcbe54[];extern int lp_cf27f4,lp_cf27f8;extern const unsigned lp_caf15c;
bool lp_filter9daf80(int,int,int)throw();int lp_max9cdb60(int,int)throw();int lp_name7ffe10(LPHP,unsigned,string&);
struct LPMap{char pad[0x6c];LPPoint offset;char pad74[0x1d8-0x74];vector<LPLabel*>labels;char pad1e8[0x208-0x1e8];LPPoint last;LPHP anchor;void bounds8051f0(LPPoint&,LPPoint&)throw();bool visible8052f0(const LPPoint&)throw();bool hasProp49b2a0(int,LPHP)throw();bool hasPos49b220(int,const LPPoint&)throw();bool inBounds417360(int,int)throw();LPPoint absolute428650(LPPoint)throw();void add812b60(bool,const LPPoint&,int,int,LPHP,unsigned,bool);int label813050(bool,LPHP,bool,bool,bool);};
int LPMap::label813050(bool hostile,LPHP prop,bool suffix,bool skip,bool strong){
 int type=hostile?4:5;
 vector<LPHP>a1;LP25TypeCodes record;vector<LPPoint>p;vector<LPConsole*>key;
 LPMemos*w=&lp_cefc4c->memory;
 if(prop.valid()){
  a1.push_back(prop);record.push9b9d30(lp_caf15c);p.push_back(LPPoint(-1));
  for(unsigned i=0;i<labels.size();i++){if(lp_filter9daf80(4,labels[i]->type,7))key.push_back(labels[i]->console);}
  last=prop.get()->position();anchor.reset();
 }else{
  LPIntsGrid*other=&lp_cefc4c->visible;LPPoint first,a;bounds8051f0(first,a);
  for(int x=first.x,n=lp_max9cdb60(offset.x,0);x<=a.x&&n<lp_cf27f4;x++,n++){
   for(int i=first.y,v1=lp_max9cdb60(offset.y,0);i<=a.y&&v1<lp_cf27f8;i++,v1++){
    if(*other->at(x,i)){
     if(lp_cfd44c.at(x,i)[0]->door()&&hostile==!lp_cefc4c->group(lp_cfd44c.at(x,i)[0]->prop().get()->definition()->group,0)){
      if(skip&&hasProp49b2a0(type,lp_cfd44c.at(x,i)[0]->prop()))continue;
      a1.push_back(lp_cfd44c.at(x,i)[0]->prop());record.push9b9d30(lp_caf15c);p.push_back(LPPoint(-1));
     }
    }else if(w->at(x,i)->type!=lp_caf15c&&hostile==!lp_cefc4c->group(w->at(x,i)->group,0)){
     if(skip&&hasPos49b220(type,LPPoint(x,i)))continue;
     a1.push_back(LPHP());record.push9b9d30(w->at(x,i)->type);p.push_back(LPPoint(x,i));
    }
   }
  }
  if(a1.empty())return 0;
 }
 int data=0;string text;
 int width,index,result;
 for(unsigned i=0;i<a1.size();i++){
  vector<int>p2(6u,0);
  width=(lp_name7ffe10(a1[i],record[i],text)+5)/2;index=6;
  for(unsigned i2=0;i2<p2.size();i2++){
   result=0;
   int n=0,x=(a1[i].valid()?a1[i].get()->position().x:p[i].x)+lp_cefd20[i2].value-(lp_bcbe54[i2]?width-1:0);
   int a=(a1[i].valid()?a1[i].get()->position().y:p[i].y)+lp_cefd24[i2].value;
   for(;n<width;n++,x++){
    if(visible8052f0(LPPoint(x,a))){
     if(lp_cfd44c.at(x,a)[0]->entity().valid()&&lp_cfd44c.at(x,a)[0]->entity().get()->relation(lp_cefc4c->player())!=1&&(lp_cefc4c->known(lp_cfd44c.at(x,a)[0]->entity())||lp_cefc4c->seen.at(x,a)->tick==lp_cefc4c->generation)){
      result+=10;continue;
     }else if(lp_cfd44c.at(x,a)[0]->door()){result+=6;continue;}
    }else if(!inBounds417360(x+offset.x,a+offset.y)){result+=2;continue;}
    LPPoint point(x,a);point+=offset;point=absolute428650(point);
    for(unsigned j=0;j<key.size();j++){if(key[j]->contains(point)){result+=strong?20:1;break;}}
   }
   if(result!=0)p2[i2]=result;
   else{index=i2;goto chosen;}
  }
  if(index==6){result=p2[0];index=0;for(unsigned j=1;j<p2.size();j++){if(p2[j]<result){result=p2[j];index=j;}}}
  chosen:
  add812b60(prop.valid(),a1[i].valid()?a1[i].get()->position():p[i],type,index,a1[i],record[i],suffix);
  key.push_back(labels.back()->console);data++;
 }
 return data;
}
