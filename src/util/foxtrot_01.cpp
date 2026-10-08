// NOTE: CParts::input (0x89d970) on private borrowed views of CParts/CPart and their callees; placeholder names.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct FxPos{int x,y;FxPos(int,int);bool operator!=(const FxPos&)const;};
struct FxColor{unsigned char r,g,b;FxColor(const FxColor&);};
struct FxRect{int x,y,w,h;bool contains40aa00(const FxPos&);};
struct FxEvent{int command;FxPos pos;};
struct FxDef{char pad0[0xec];int ec;char padf0[0x1ac-0xf0];bool b1ac;};
struct FxItem{int getType44aec0();int nested457820();int type457880();int slot4578a0();int effect457b70(int);bool active457cf0();bool ready457d70();float heat457df0();int upkeep457e10();int kind457f90();int guided4580c0();int turn44ab90();FxDef*def9b4350();string name571db0(bool,bool);};
struct FxHI{int id;FxItem*get9b65b0()const;bool null9b65d0()const;bool valid9b7230()const;bool operator==(FxHI)const;};
struct FxEntity{int mode5cad50();void parts5cb8b0(vector<FxHI>&);void parts5cb930(vector<FxHI>&);int check5dc440(FxHI);vector<FxHI>*inventory45ab00();};
struct FxHE{int id;FxHE();FxEntity*operator->()const;};
struct FxMap{FxHE player4630f0();int turn464270();void raise465490(int);bool busy71bbd0();};extern FxMap*fx_cefc4c;
struct FxXCon{bool hidden4175f0();FxPos getPos417480();FxPos absPos4174a0();FxColor fore417680(int,int);void setPos417a90(int,int);void setChar417f50(int,int,int);void setFore417f80(int,int,FxColor);void setBg418410(FxColor);void remove428b20(FxXCon*);};
struct FxPart:FxXCon{char base[0x6c];FxHI item;bool continuation;FxHI other;bool flagged;int type,key;};
struct FxText:FxXCon{char pad[0x88];FxText(FxXCon*,const FxPos&,const string&,int,int,int);};
struct FxTemp:FxXCon{char pad[0x6c];FxTemp(FxXCon*,const FxPos&,int,int,int,int);void effect48c460(int,const FxPos&);};
struct FxPair{FxHI first,second;bool player46d440();};
struct FxPhrase{char pad[0x20];FxPhrase(int,string*,string*,string*,FxHE,FxHE);};
struct FxMsgs{void add7b1880(FxPhrase*);};extern FxMsgs*fx_cec0f4;
struct FxFlags{bool active46dd50();};extern FxFlags fx_cf45d8;
struct FxTip{bool shown4a2540();};extern FxTip*fx_cec074;
class RNG{public:int rangeInt(float,float);};extern RNG rng;
struct FxParts:FxXCon{char base[0x74];vector<FxPart*>parts;char pad84[0xac-0x84];int selectedKey;FxHI swapA,swapB;char padb8[0xc0-0xb8];bool cycling;char padc1[0xcc-0xc1];bool modal;char padcd[0xd4-0xcd];vector<FxRect>rects;int unknowne4;vector<FxXCon*>labels;char padf8[0x104-0xf8];unsigned moveTime;vector<vector<FxPos> >paths;vector<int>delays;vector<unsigned>times;bool sorted;
 bool input(FxEvent*);bool base429d00(FxEvent*);void timer4a9bf0();bool busy4a9af0();void set4a9cb0(int);void select8968b0(int);int index8a0d10(FxHI);bool swap89c350(FxHI,int);FxPart*find894e70(FxHI);void toggle8993e0(FxPart*,bool);};
extern FxParts*fx_cec088;
extern bool fx_cefa5f,fx_d28e5b,fx_d28e5c,fx_ba0968[];
extern int fx_caf2b4,fx_cefbc0,fx_cefb38;
extern unsigned fx_caed20;
extern vector<int>fx_d15d9c,fx_cf4a14;
extern vector<FxPair*>fx_cf4760;
extern FxColor*fx_d2981c;
extern const float fx_c370e4;
extern const char fx_c01e6c[],fx_c01e68[];
void fx_delete9de640(vector<FxPair*>&,int&);
int fx_indexOf9d3110(vector<FxHI>&,FxHI);
void fx_eraseAt9ce6d0(vector<FxPart*>&,unsigned&);
void fx_append9d0300(vector<FxPart*>&,vector<FxPart*>&);
void fx_remove9de6f0(vector<FxPart*>&,int);
void fx_move9e2ce0(vector<FxPart*>&,unsigned,unsigned);
class CInfoCompare;bool opr5c_compareInfo89d920(CInfoCompare*,CInfoCompare*);
typedef bool(*FxCompare)(FxPart*,FxPart*);
bool fx_lookup9d45a0(const string&,int*);
void fx_eraseStep9d6440(vector<FxHI>&,int&);
void fx_warn7b1750(int,const string*,const string*,const string*,FxHE,FxHE,const FxPos*);
int fx_sound4541b0(int,int,int);
void fx_insert9dbdc0(vector<unsigned>&,int,unsigned);
void fx_moveBlock9e2e40(vector<unsigned>&,int,unsigned,unsigned);
unsigned fx_count9de8f0(vector<int>&);
int fx_find9d4660(vector<int>&,int);
void fx_logError404f10(string,string);
string fx_intToString4051f0(int);
void fx_analysis8b1da0(FxHE,FxHE,int);
bool FxParts::input(FxEvent*event){
 if(hidden4175f0()||fx_cefa5f)return false;
 if(base429d00(event))return true;
 if(fx_cefc4c->busy71bbd0()&&!sorted)return false;
 if(fx_caf2b4!=32&&!fx_cf45d8.active46dd50()&&fx_caed20>=660000){if(fx_caf2b4-64!=fx_d15d9c.size())fx_cefbc0=1;fx_caf2b4=32;}
 switch(event->command){
 case 0x110:{
  for(int i=0;i<labels.size();i++)if(labels[i])remove428b20(labels[i]);
  labels.clear();
  for(int j=0;j<fx_cf4760.size();j++){
   if(!fx_cf4760[j]->player46d440())fx_delete9de640(fx_cf4760,j);
   else{
    FxHI first=fx_cf4760[j]->first.get9b65b0()->getType44aec0()<=3?fx_cf4760[j]->first:fx_cf4760[j]->second;
    FxHI other=fx_cf4760[j]->first.get9b65b0()->getType44aec0()<=3?fx_cf4760[j]->second:fx_cf4760[j]->first;
    FxPart*p=fx_cec088->find894e70(first);
    if(p){
     string text=fx_c01e6c+other.get9b65b0()->name571db0(false,false)+fx_c01e68;
     labels.push_back(new FxText(this,FxPos(-(text.size()-1),p->getPos417480().y),text,0,0,10));
     labels.back()->setBg418410(*fx_d2981c);
    }
   }
  }
  return true;}
 case 0x111:
  if(swapA.get9b65b0()&&swapB.get9b65b0()){
   selectedKey=32;
   int index=index8a0d10(swapA),k;
   vector<FxHI>*items=fx_cefc4c->player4630f0()->inventory45ab00();
   if(index!=-1){
    k=fx_indexOf9d3110(*items,swapB);
    if(k!=-1&&(*items)[k].get9b65b0()->getType44aec0()==4){selectedKey=parts[index]->key;swap89c350((*items)[k],32);goto done111;}
   }else{
    index=index8a0d10(swapB);
    if(index!=-1){
     k=fx_indexOf9d3110(*items,swapA);
     if(k!=-1){selectedKey=parts[index]->key;swap89c350((*items)[k],32);goto done111;}
    }
   }
  }
  fx_cec0f4->add7b1880(new FxPhrase(118,0,0,0,FxHE(),FxHE()));
  done111:
  return true;
 case 0x112:
  timer4a9bf0();
  return true;
 case 0x113:{
  if(busy4a9af0())return true;
  int mode,key;
  vector<FxPart*>result,queue,list,entries;
  for(int type=0;type<4;type++){
   queue.clear();list.clear();entries.clear();
   for(int i=0;i<parts.size();i++)if(parts[i]->type==type)queue.push_back(parts[i]);
   if(type==3&&fx_d28e5b)list=queue;
   else{
    vector<FxPart*>extra;
    for(unsigned i=0;i<queue.size();i++){
     if(queue[i]->item.null9b65d0()){
      if(queue[i]->other.valid9b7230())extra.push_back(queue[i]);else entries.push_back(queue[i]);
      fx_eraseAt9ce6d0(queue,i);
     }
    }
    if(!extra.empty())fx_append9d0300(entries,extra);
    while(!queue.empty()){
     int best=queue[0]->item.get9b65b0()->nested457820();
     int bestIndex=0;
     for(int i=1;i<queue.size();i++){
      if(queue[i]->item.get9b65b0()->nested457820()<best){best=queue[i]->item.get9b65b0()->nested457820();bestIndex=i;}
     }
     FxHI it=queue[bestIndex]->item;
     while(bestIndex<queue.size()&&queue[bestIndex]->item==it){list.push_back(queue[bestIndex]);fx_remove9de6f0(queue,bestIndex);}
    }
    for(int i=0;i<list.size();){
     int start=i;
     int end=i;
     while(end+1<list.size()&&list[end+1]->item.get9b65b0()->nested457820()==list[start]->item.get9b65b0()->nested457820())end++;
     if(start!=end)sort(list.begin()+start,list.begin()+end+1,(FxCompare)opr5c_compareInfo89d920);
     i=end+1;
    }
    if(fx_d28e5c){
     int pos=0;
     for(int i=0;i<list.size();i++){if(list[i]->item.get9b65b0()->def9b4350()->b1ac){fx_move9e2ce0(list,i,pos);pos++;}}
     pos=0;
     for(int i=0;i<list.size();i++){if(list[i]->item.get9b65b0()->effect457b70(108)){fx_move9e2ce0(list,i,pos);pos++;}}
    }
   }
   fx_append9d0300(result,list);
   fx_append9d0300(result,entries);
  }
  key='a';
  for(int i=0;i<result.size();i++){
   if(result[i]!=parts[i]){
    result[i]->key=key;
    result[i]->setChar417f50(1,0,key-32);
    int effect;
    fx_lookup9d45a0("CPart_Sort_Ascii",&effect);
    FxTemp*temp=new FxTemp(result[i],FxPos(1,0),1,1,0,-1);
    temp->setFore417f80(0,0,result[i]->fore417680(1,0));
    temp->effect48c460(effect,FxPos(0,0));
   }
   key++;
  }
  mode=2;
  if(mode==0){
   int row=modal?1:2;
   for(int i=0;i<result.size();i++,row++){
    if(!modal){
     if(i==0&&result[i]->type!=0)row++;
     else if(i!=0&&result[i]->type!=result[i-1]->type)row+=result[i]->type-result[i-1]->type;
    }
    result[i]->setPos417a90(result[i]->getPos417480().x,row);
   }
  }else{
   paths.clear();delays.clear();times.clear();
   bool moved=false;
   int row=modal?1:2;
   for(int i=0;i<result.size();i++,row++){
    if(!modal){
     if(i==0&&result[i]->type!=0)row++;
     else if(i!=0&&result[i]->type!=result[i-1]->type)row+=result[i]->type-result[i-1]->type;
    }
    FxPos current=result[i]->getPos417480();
    FxPos to(current.x,row);
    paths.push_back(vector<FxPos>());
    vector<FxPos>&path=paths.back();
    path.push_back(current);
    delays.push_back(0);
    if(current!=to){
     moved=true;
     int dir=to.y>current.y?1:-1;
     if(mode==1){
      while(path.back()!=to){current.y+=dir;path.push_back(current);}
     }else{
      int steps=4;
      for(int j=0;j<steps;j++){current.x--;path.push_back(current);}
      current.y+=dir;path.push_back(current);
      while(current.y!=to.y){current.y+=dir;path.push_back(current);}
      current.x++;
      while(current.x!=to.x){path.push_back(current);current.x++;}
      path.push_back(to);
     }
    }
   }
   if(moved){
    moveTime=fx_caed20;
    for(int i=0;i<result.size();i++)times.push_back(rng.rangeInt(0,fx_c370e4)+fx_caed20);
    fx_cefc4c->raise465490(1000);
    parts=result;
   }else if(!sorted)fx_cec0f4->add7b1880(new FxPhrase(123,0,0,0,FxHE(),FxHE()));
  }
  sorted=false;
  return true;}
 case 0x114:{
  FxPart*p;
  vector<FxHI>items;
  FxHE player=fx_cefc4c->player4630f0();
  player->parts5cb8b0(items);
  for(int i=0;i<items.size();i++){
   if(items[i].get9b65b0()->slot4578a0()!=1||!items[i].get9b65b0()->ready457d70()||fx_cefc4c->turn464270()<items[i].get9b65b0()->turn44ab90()||items[i].get9b65b0()->effect457b70(82)
    ||(items[i].get9b65b0()->slot4578a0()==1&&fx_cefc4c->player4630f0()->mode5cad50()&&(fx_ba0968[fx_cefb38]&&!fx_ba0968[items[i].get9b65b0()->def9b4350()->ec]||!fx_ba0968[fx_cefb38]&&items[i].get9b65b0()->def9b4350()->ec!=fx_cefb38))
    ||items[i].get9b65b0()->kind457f90()==102)fx_eraseStep9d6440(items,i);
  }
  if(items.empty()){fx_warn7b1750(63,&string("propulsion"),0,0,FxHE(),FxHE(),0);break;}
  int value=31;
  for(int i=0;i<items.size();i++){if(items[i].get9b65b0()->active457cf0()){value=items[i].get9b65b0()->type457880();break;}}
  vector<unsigned>list;
  for(int t=9;t<=13;t++)list.push_back(t);
  list.push_back(31);
  if(value!=31){
   if(value==13)fx_insert9dbdc0(list,0,31);
   else{
    int next=value+1;
    for(int i=0;i<list.size();i++){if(list[i]==next){fx_moveBlock9e2e40(list,0,i,list.size()-1);break;}}
   }
  }
  for(int i=0;i<list.size();i++){
   if(list[i]==31){
    for(int j=0;j<items.size();j++){
     if(items[j].get9b65b0()->active457cf0()){
      p=fx_cec088->find894e70(items[j]);
      if(p){do fx_cec088->toggle8993e0(p,true);while(items[j].get9b65b0()->active457cf0()&&(items[j].get9b65b0()->slot4578a0()!=1||items[j].get9b65b0()->def9b4350()->ec==0)&&items[j].get9b65b0()->kind457f90()!=102);}
     }
    }
    fx_sound4541b0(38,0,0);
    break;
   }
   bool any=false;
   for(int j=0;j<items.size();j++){
    if(items[j].get9b65b0()->type457880()==list[i]&&player->check5dc440(items[j])==0){
     p=fx_cec088->find894e70(items[j]);
     if(p)fx_cec088->toggle8993e0(p,true);
     any=true;
    }
   }
   if(any){fx_sound4541b0(35,0,0);break;}
  }
  return true;}
 case 0x115:{
  FxPart*p;
  vector<FxHI>items;
  FxHE player=fx_cefc4c->player4630f0();
  player->parts5cb930(items);
  for(int i=0;i<items.size();i++){
   if(items[i].get9b65b0()->slot4578a0()!=2||items[i].get9b65b0()->heat457df0()==0&&items[i].get9b65b0()->upkeep457e10()==0)fx_eraseStep9d6440(items,i);
  }
  if(items.empty()){
   bool any=false;
   player->parts5cb8b0(items);
   for(int i=0;i<items.size();i++){
    if(items[i].get9b65b0()->slot4578a0()==2&&items[i].get9b65b0()->heat457df0()!=0&&player->check5dc440(items[i])==0){
     p=fx_cec088->find894e70(items[i]);
     if(p)fx_cec088->toggle8993e0(p,true);
     any=true;
    }
   }
   if(any)fx_sound4541b0(35,0,0);
   else fx_warn7b1750(63,&string("upkeep utilities"),0,0,FxHE(),FxHE(),0);
  }else{
   for(int i=0;i<items.size();i++){
    p=fx_cec088->find894e70(items[i]);
    if(p){do fx_cec088->toggle8993e0(p,true);while(items[i].get9b65b0()->active457cf0());}
   }
   fx_sound4541b0(38,0,0);
  }
  return true;}
 case 0x116:{
  FxPart*p;
  FxHE player=fx_cefc4c->player4630f0();
  vector<FxHI>items;
  player->parts5cb8b0(items);
  for(int i=0;i<items.size();i++){
   if(items[i].get9b65b0()->slot4578a0()!=3||!items[i].get9b65b0()->ready457d70()||fx_cefc4c->turn464270()<items[i].get9b65b0()->turn44ab90()||items[i].get9b65b0()->effect457b70(82)||items[i].get9b65b0()->kind457f90()==207)fx_eraseStep9d6440(items,i);
  }
  if(items.empty()){fx_warn7b1750(63,&string("weapons"),0,0,FxHE(),FxHE(),0);break;}
  vector<vector<FxHI> >pool;
  vector<FxHI>group;
  for(int i=0;i<items.size();i++){
   if(!items[i].get9b65b0()->guided4580c0()&&items[i].get9b65b0()->kind457f90()!=119&&items[i].get9b65b0()->type457880()<26){group.push_back(items[i]);fx_eraseStep9d6440(items,i);}
  }
  if(!group.empty()){pool.push_back(group);group.clear();}
  for(int i=0;i<items.size();i++){
   if(items[i].get9b65b0()->guided4580c0()){group.push_back(items[i]);fx_eraseStep9d6440(items,i);pool.push_back(group);group.clear();}
  }
  for(int i=0;i<items.size();i++){
   if(items[i].get9b65b0()->kind457f90()==119){group.push_back(items[i]);fx_eraseStep9d6440(items,i);pool.push_back(group);group.clear();}
  }
  for(int i=0;i<items.size();i++){
   if(items[i].get9b65b0()->type457880()>=26){group.push_back(items[i]);fx_eraseStep9d6440(items,i);pool.push_back(group);group.clear();}
  }
  if(!items.empty())fx_logError404f10("CParts::input()",fx_intToString4051f0(items.size())+" weapons not considered for cycling; first: "+items.front().get9b65b0()->name571db0(false,false));
  vector<int>data;
  for(int i=0;i<pool.size();i++){
   int active=0;
   for(int j=0;j<pool[i].size();j++)if(pool[i][j].get9b65b0()->active457cf0())active++;
   data.push_back(active==0?0:active==pool[i].size()?2:1);
  }
  cycling=true;
  if(fx_count9de8f0(data)>1){
   for(int i=0;i<pool.size();i++)
    for(int j=0;j<pool[i].size();j++)
     if(pool[i][j].get9b65b0()->active457cf0()){
      p=fx_cec088->find894e70(pool[i][j]);
      if(p){do fx_cec088->toggle8993e0(p,true);while(pool[i][j].get9b65b0()->active457cf0());}
     }
  }else{
   int to=-1;
   int cur=-1;
   int found=fx_find9d4660(data,1);
   if(found==-1)found=fx_find9d4660(data,2);
   if(found!=-1){
    switch(data[found]){
    case 1:to=found;break;
    case 2:cur=found;to=found+1;break;
    }
   }else to=0;
   bool added=false;
   bool changed=false;
   if(cur!=-1){
    for(int j=0;j<pool[cur].size();j++)
     if(pool[cur][j].get9b65b0()->active457cf0()){
      p=fx_cec088->find894e70(pool[cur][j]);
      if(p){do fx_cec088->toggle8993e0(p,true);while(pool[cur][j].get9b65b0()->active457cf0());}
      changed=true;
     }
   }
   if(to>=pool.size()){
    for(int i=0;i<pool.size();i++)
     for(int j=0;j<pool[i].size();j++)
      if(pool[i][j].get9b65b0()->active457cf0()){
       p=fx_cec088->find894e70(pool[i][j]);
       if(p){do fx_cec088->toggle8993e0(p,true);while(pool[i][j].get9b65b0()->active457cf0());}
       changed=true;
      }
   }else{
    for(int j=0;j<pool[to].size();j++)
     if(player->check5dc440(pool[to][j])==0){
      p=fx_cec088->find894e70(pool[to][j]);
      if(p)fx_cec088->toggle8993e0(p,true);
      added=true;
     }
   }
   if(added)fx_sound4541b0(35,0,0);
   if(changed)fx_sound4541b0(38,0,0);
  }
  cycling=false;
  return true;}
 case 0x117:
  for(int i=0;i<rects.size();i++){
   if(rects[i].contains40aa00(event->pos)){
    for(int j=0;j<parts.size();j++){
     if(parts[j]->absPos4174a0().y==rects[i].y){
      if(parts[j]->item.valid9b7230()){
       FxHI item=parts[j]->item;
       for(int k=0;k<fx_cf4760.size();k++){
        if(!fx_cf4760[k]->player46d440())fx_delete9de640(fx_cf4760,k);
        else if(fx_cf4760[k]->first==item||fx_cf4760[k]->second==item){
         FxHI other=fx_cf4760[k]->first==item?fx_cf4760[k]->second:fx_cf4760[k]->first;
         set4a9cb0(parts[j]->key);
         if(swap89c350(other,parts[j]->key)){
          for(int m=0;m<labels.size();m++)if(labels[m])remove428b20(labels[m]);
          labels.clear();
          unknowne4=0;
         }
         break;
        }
       }
      }
      break;
     }
    }
    break;
   }
  }
  return true;
 case 0x11c:case 0x11d:case 0x11e:case 0x11f:
  select8968b0(event->command-0x11c);
  return true;
 case 0x120:
  if(fx_cf4a14.empty())fx_cec0f4->add7b1880(new FxPhrase(82,0,0,0,FxHE(),FxHE()));
  else if(fx_cec074->shown4a2540())fx_analysis8b1da0(fx_cefc4c->player4630f0(),FxHE(),4);
  return true;
 }
 return false;
}
