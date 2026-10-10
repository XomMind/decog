// BS::populate6d4c00: map population (machines, rooms, squads, items, bosses, terminals, links).
// Private partial ABI views; names and untouched fields are placeholders.
// NOTE: placeholder names / placeholder layouts throughout.
#include <string>
#include <vector>
#include <math.h>
#include "rng.h"
using std::string; using std::vector;
extern RNG rng;
// vector<int>::size call sites pair with two different exe copies (0x9b9260, 0x9b5100); call them through
// private views so std::vector<int>::size keeps its own pairing.
struct GrSizeA{unsigned size9b9260()const;};struct GrSizeB{unsigned size9b5100()const;};
#define GR_SZ(v) (((const GrSizeA*)&(v))->size9b9260())
#define GR_SZB(v) (((const GrSizeB*)&(v))->size9b5100())

struct GrPoint{int x,y;GrPoint();GrPoint(int);GrPoint(int,int);GrPoint(const GrPoint&)throw();GrPoint&operator=(const GrPoint&);
 int random40c130()throw();bool contains40c190(int);void set40a010(int,int);void set409ff0(int);bool contains409d70(int,int,int,int);};
struct GrPos{int x,y,z,z2;GrPos();GrPoint toPoint40a970();};
struct GrPos8{int x,y;GrPos8();GrPoint toPoint40a970();};
struct GrRect{int x,y,w,h;int area40ad00();GrPoint center40ad40();GrPoint topLeft40a970();void randomPos40b000(GrPoint*);};
struct GrRectB{int x,y,w,h;GrRectB(int,int,int,int);};
struct GrArea{GrPoint p1;GrPoint p2;GrArea();GrArea(const GrRect&);void grow40bc10(int);bool test40b700(int,int);GrPoint center40b620();void randomPoint40be30(GrPoint*);GrPoint randomPoint40be90();};
struct GrRoom{int id;GrRect rect;vector<GrPoint>v14;int f24;vector<GrPoint>v28;vector<int>v38;vector<int>v48;int f58;vector<int>v5c;};
struct GrE24{int x0,x4,x8,xc;int x10;vector<int*>v14;};
struct GrE8{int a,b;};
struct GrE20{vector<GrPoint>pts;char p10[0x10];};
struct GrRoomRec{GrRect r;int score;GrRoomRec(const GrE24&,int);};
struct GrLists{vector<int>list;vector<int>v10;vector<int>v20;char p30[4];GrLists();GrLists(int);};
struct GrCfg{int f0,f4,f8,fc,f10,f14,f18,f1c,f20;};
struct GrLoc{int a;int type;int depth;int getDepthIndex();bool inRange46ecb0();};
struct GrLayer{int width9fcd80();int height9b8f00();};
struct GrPropDef{int id;char p4[0x38];vector<GrLayer*>layers;char p4c[0xa8];int kind4;int kind8;char pfc[4];int f100[3];int f10c[3];int f118;char p11c[0x24];int f140;int f144;GrPoint range148;int f150;};
struct GrEntityDef{char p0[0x24];int f24;int f28;char p2c[0x3c];int f68;char p6c[0x30];int size;};
struct GrItemDef{int id;char p4[0x58];int f5c;char p60[0x1a9];bool f209;};
struct GrPair{int*a;int b;GrPair(int*,int);};
struct GrHE;struct GrProp;struct GrEntity;struct GrItem;struct GrGroup;struct GrTerrain{int id;};
struct GrHE{int id;GrHE();GrEntity*operator->()const;bool isNull()const;bool valid()const;};
struct GrHP{int id;GrHP();GrProp*operator->()const;bool isNull()const;bool valid()const;};
struct GrHI{int id;GrHI();GrItem*operator->()const;bool valid()const;};
struct GrHG{int id;GrHG();GrGroup*operator->()const;};
struct GrHL{int id;GrHL();GrLoc*operator->()const;};
struct GrParty{char d[0x38];GrParty(int,GrHE,int,int,int);};
struct GrMachInfo{char p0[8];int f8;int fc;char p10[0x60];GrHE f70;bool f45c160(int,int);};
struct GrProp{bool f45cb10();void setField448080(int);GrPropDef*getDef9b8f00();int f44ab40();const GrPoint&f4184d0();GrMachInfo*f45cb30();const string&getName45c5b0();int f45c9b0();void f45ccf0(int);};
struct GrAI{void f451400(int);void f459410(const GrArea&);void setTerminal5b3760(const GrPoint&);};
struct GrEntity{const GrPoint&getPosition45a4a0();GrAI*ai45b590();int faction45a2c0();int f45a810();};
struct GrItem{void addEffect4585a0(GrPair*);void f57bff0(int,int);int effectValue457be0(int);void remove57dbe0(int,int,int,int);int f457880();void f450460(int);int f9b6bf0();};
struct GrGroup{vector<GrHE>&members416f40();};
struct GrCell{bool f45d6a0();bool f4550b0();GrHP getProp();GrTerrain*terrain9fcd80();void f66a050(int,int,int);bool canPlace66ad20(int);};
struct GrGrid{GrCell**atPoint(const GrPoint&);GrCell**at(int,int);bool contains9b43b0(const GrPoint&);bool inBounds9b45c0(int,int);void getRect9b4430(const GrPoint&,int,GrArea&);int width9fcd80();int height9b8f00();void random9cf0c0(GrPoint&);};
extern GrGrid gr_grid_cfd44c;
struct GrIntGrid{int*atPoint(const GrPoint&);};extern GrIntGrid gr_cf1964;
template<class T>struct GrArr{char d[0xc];GrArr();~GrArr();T*at(int,int);int width9fcd80();int height9b8f00();};
template<class T>struct GrWL{vector<T>values;vector<int>weights;int total;GrWL();~GrWL();void add(T,int);T&pick();bool pick9ba6a0(T&);int size9b81d0();void reset9c07a0();};
struct GrExit{GrPoint pos;GrHL h8;char pc[8];GrHP h14;GrHP h18;};
struct GrX{char p0[0x24];string name;};
struct GrBS{char p0[8];GrPoint p8;vector<GrExit*>v10;char p20[0x2c];vector<GrHG>v4c;char p5c[0xbc];vector<vector<GrPoint> >v118;char p128[0x44c];vector<GrPoint>v574;vector<GrPoint>v584;vector<GrHE>v594;vector<vector<GrHE> >v5a4;char p5b4[0x52c];int fae0;char pae4[0xf0];vector<GrPoint>vbd4;
 void populate6d4c00(vector<int>&);
 void*placeMachine6c70a0(int,const GrPoint&,int,bool,bool);void f6c98c0(int,vector<int>&);void f6ca2c0(const GrPoint&,int,int);bool placeProp6c67b0(GrPropDef*,const GrPoint&,int,int,int);GrEntityDef*selectRobotOfClass(int,int,bool,bool);
 GrHE placeEntity6c58c0(GrEntityDef*,const GrPoint&,int,bool,int,int,bool);void placeRandomEncounter6f1e90(vector<int>&,vector<GrE8>&,vector<bool>&,vector<int>&);GrHI f6c5400(GrItemDef*,const GrPoint&);
 GrItemDef*selectRandomItem6c3bc0(int,int,int);GrItemDef*selectRandomItemOfRating6c40e0(int,int,int,int,int,int,int);bool f716940(const GrPoint&,const GrPoint&,int,int);
 bool f6ca170(const GrPoint&,int,int,int,vector<GrX*>&,vector<int>&,int);GrHI f6c51d0(GrItemDef*,GrHE,int,int);int*f6c5180();};
extern GrBS*gr_world_cefc4c;
struct GrOvermind{void addParty(GrParty*,int);int f6892c0(int,int,int);int spawnPatrol6896d0(GrHE,int,int,int,int,int,int,int,int);int f68a500(int,int,int);GrHE f683b60(int,int,int);};extern GrOvermind gr_overmind_cf6428;
struct GrGameData{const string&getEntryText(const string&);int getDepthIndex();bool f46fac0();};extern GrGameData gr_gd_d1e860;
struct GrPlayerData{bool isTypeAllowed46e100(int);};extern GrPlayerData gr_pd_cf45d8;
extern GrHL gr_loc_d1e888;extern bool gr_d1ebfc,gr_d1eb98,gr_cf6a24;extern GrCfg gr_b934e8[],gr_b92dd8[],gr_b92f90[],gr_b92880[];extern int gr_cf4734,gr_cf462c,gr_cf4718,gr_ba65e4[];
struct GrI3{int v[3];};struct GrI9{int v[9];};struct GrI5{int v[5];};struct GrI4{int v[4];};struct GrI15{int v[15];};struct GrF6{float v[6];};struct GrB17{bool v[0x17];};
struct GrRow18{int a,b,c,d,e,f;};
extern GrI3 gr_b9f530[],gr_b9f270[],gr_b9f368[],gr_b91e88[];extern GrI9 gr_b9efc0[],gr_b9ea68[];extern GrB17 gr_b9e6f0[];extern GrRow18 gr_b9f5c0[];extern GrF6 gr_b91278[],gr_b91608[];
extern GrI15 gr_b96d40[];extern GrI5 gr_b96a88[],gr_b96bc0[],gr_b92558[];extern GrI4 gr_b96cf0[];
extern vector<GrPropDef*>gr_cf35b0;extern vector<GrRect>gr_d222f0;extern vector<GrRoom>gr_cf13e8;extern vector<GrE24>gr_d1f31c;extern vector<GrRoomRec*>gr_cf3a00;extern vector<GrLists*>gr_d39f1c;
extern vector<vector<GrHP> >gr_d31640;extern vector<GrE20>gr_cf65c4;extern vector<int>gr_d20248;extern vector<GrEntityDef*>gr_d25de0;extern vector<GrItemDef*>gr_d2d1c4;extern vector<int*>gr_d2f0f8;
extern vector<GrHE>gr_cf6a80;extern vector<vector<string> >gr_cf6a90;struct GrSquad{char p0[4];GrHE h4;};extern vector<GrSquad*>gr_cf6478;
extern int gr_b9ea60,gr_b96348[],gr_bb8360[],gr_b90000[],gr_b90c40[],gr_b90098[],gr_b91258[],gr_ba3aec[],gr_ba3adc[],gr_caf15c,gr_bba390,gr_bba394,gr_ced21c,gr_d1eb68,gr_b92854[];extern bool gr_bb8380[];
extern GrPoint gr_cfd300,gr_d2a688[],gr_d33bd8;struct GrP16{GrPoint r;char p8[8];};extern GrP16 gr_d357a0[];extern GrHE gr_d1ebd8;
extern const float gr_ba65cc[],gr_ba65b4[],gr_c36ecc,gr_c37034,gr_c37038,gr_ba7b4c,gr_b92850,gr_c36ed8,gr_c36edc;extern const double gr_c371d8;
extern GrTerrain*TERRAIN_EARTH,*TERRAIN_CAVE_WALL,*caveinThirdTerrain,*gr_cefb9c;
int gr_stringToInt(const string&);string gr_intToString(int);
bool gr_flagA448b60(const GrPoint&);bool gr_flagB448b80(const GrPoint&);bool gr_flagC448ba0(const GrPoint&);
bool gr_placeWallProp6ca780(vector<vector<int> >&,int,GrRect&,int,int,int&,GrPoint&,int&);bool gr_placeWallProp6ca780(vector<vector<int> >&,int,GrRoomRec&,int,int,int&,GrPoint&,int&);
void gr_insertAt9dbdc0(vector<int>&,unsigned,unsigned);void gr_insertAt9dbdc0(vector<GrRoomRec*>&,unsigned,GrRoomRec*);
bool gr_edgeClear6c9cb0(int,GrPoint&,int,int,GrRect&);bool gr_areaEmpty6ca040(const GrPoint&,int,int,int);bool gr_layout6cadf0(GrWL<int>&,int,GrRect&,int,int,GrArr<int>&,GrArr<GrPoint>&,GrArr<int>&);
void gr_shuffle9d8f80(vector<int>&);void gr_shuffle9d8f80(vector<GrLists*>&);int gr_randomRec9d5d00(vector<int>&);int gr_distance40a3f0(const GrPoint&,const GrPoint&);bool gr_isEven406320(int);
bool gr_findProp9d7710(vector<GrPropDef*>&,const string&,GrPropDef*&);bool gr_findItem9d7a40(vector<GrItemDef*>&,const string&,GrItemDef*&);
int gr_randomIndex9db950(vector<GrRoom>&);int gr_randomIndex9dbbe0(vector<GrRect>&);int gr_randomIndex9db990(vector<GrE24>&);
void gr_translate446dd0(GrPoint&,int,int,int);void gr_fn9d3020(vector<GrPoint>&,GrPoint);void gr_setTerrain6c9c90(const GrPoint&,GrTerrain*);
bool gr_findWallStrip6cbb40(int,int,int,GrPos&,GrPos&,int&,int,bool,int);void gr_fillRing6cba00(GrPos&,GrPos&,int,GrTerrain*,int);void gr_fillRing6cba00(GrPos8&,GrRect&,int,GrTerrain*,int);bool gr_ringFree6cb8c0(GrPos8&,GrRect&);
void gr_surrounding4faaf0(const GrPoint&,vector<GrPoint>&);void gr_shuffle9d7350(vector<GrPoint>&);bool gr_f6d4b80(const GrPoint&);bool gr_f6d4640(const GrPoint&,int,GrArea&);
void gr_fillInts9e2be0(void*,int,int);int gr_indexOfMin9d9270(vector<int>&);bool gr_containsRecord9db330(vector<int>&,int);int gr_minInt9cdb30(int,int);int gr_maxInt9cdb60(int,int);
GrPoint gr_randomPoint9d5350(vector<GrPoint>&);

void GrBS::populate6d4c00(vector<int>&out){
 int closed;
 int c2;
 c2=gr_loc_d1e888->type;
 int cx;
 cx=gr_loc_d1e888->depth;
 int found2;
 found2=gr_loc_d1e888->getDepthIndex();
 vector<int> enemy;
 int door;
 int dest;
 int cnt;
 int chosen;
 int bestValue;
 int arr;
 GrCfg* areas;
 areas=gr_loc_d1e888->inRange46ecb0()?(gr_d1ebfc?&gr_b934e8[found2]:&gr_b92dd8[found2]):(gr_d1ebfc?&gr_b92f90[c2]:&gr_b92880[c2]);
 vector<vector<int> > closestDist(3);
 int b2;
 int ax;
 ax=areas->f18;
 int bottom;
 int begin;
 begin=areas->f1c;
 int command;
 command=areas->f4;
 int ay;
 ay=areas->f0;
 if(gr_cf4734!=0)begin=0;
 if(gr_cf462c==4){ay+=command;command=0;}
 if(command!=0){
  if(gr_d1eb98)command--;
  if(command!=0){
   for(int n=gr_ba65e4[gr_cf4718];n>0;n--){
    ay++;
    if(--command==0)break;
   }
  }
 }
 GrWL<int> centre;
 for(int i=0;i<3;i++)if(gr_b9f530[found2].v[i]!=0)centre.add(i,gr_b9f530[found2].v[i]);
 int failed;
 GrWL<int> events;
 GrWL<int> ally;
 int avg;
 for(int kind=0;kind<9;kind++){
  int count=gr_loc_d1e888->inRange46ecb0()?gr_b9efc0[found2].v[kind]:gr_b9ea68[c2].v[kind];
  if(kind==5&&gr_cf4718==2&&count>1)count--;
  if(count!=0){
   events.reset9c07a0();
   for(int i=0;i<3;i++)if(gr_b9f270[kind].v[i]!=0)events.add(i,gr_b9f270[kind].v[i]);
   while(count!=0){
    int size;
    events.pick9ba6a0(size);
    ally.reset9c07a0();
    
    if(kind==5&&gr_loc_d1e888->depth>=8)avg=0;
    else centre.pick9ba6a0(avg);
    for(unsigned p=0;p<gr_cf35b0.size();p++)
     if(gr_cf35b0[p]->kind8==kind&&gr_cf35b0[p]->f10c[avg]!=0&&gr_cf35b0[p]->f100[size]!=0)ally.add(p,gr_cf35b0[p]->f100[size]);
    int pick;
    if(!ally.pick9ba6a0(pick))break;
    closestDist[size].push_back(pick);
    count--;
   }
  }
 }
 int owner;
 int out2;
 int nx;
 GrPoint mapID;
 GrArr<int> link;
 int desc;
 GrArr<GrPoint> clean;
 GrArr<int> added;
 int cy;
 int bestPoint;
 GrWL<int> bestDist;
 for(unsigned p=0;p<gr_cf35b0.size();p++)
  if(gr_cf35b0[p]->kind4==2&&gr_cf35b0[p]->f100[1]!=0&&gr_b9e6f0[c2].v[gr_cf35b0[p]->f118])bestDist.add(p,gr_cf35b0[p]->f100[1]);
 vector<int> cur;
 int counter;
 int costSoFar;
 vector<int> cost(gr_d222f0.size(),5);
 int leader;
 leader=gr_b9f5c0[c2].c;
 int commands;
 commands=gr_b9f5c0[c2].d;
 vector<int> child(9u,0);
 int buf;
 buf=0;
 vector<int> allies;
 if(!gr_d222f0.empty()){
  cur.push_back(0);
 int level;
 int hits;
  for(int i=1;i<gr_d222f0.size();i++){
   hits=gr_d222f0[i].area40ad00();
   if(hits<=gr_d222f0[cur.back()].area40ad00())cur.push_back(i);
   else for(unsigned j=0;j<GR_SZ(cur);j++)if(hits>gr_d222f0[cur[j]].area40ad00()){gr_insertAt9dbdc0(cur,j,i);break;}
  }
 int element;
  GrWL<int> dy;
  for(int i=0;i<6;i++)if(gr_b91278[c2].v[i]!=0)dy.add(i,(int)gr_b91278[c2].v[i]);
 int facing;
 int enemies;
  for(unsigned i=0;i<GR_SZ(cur);i++){
   v574.push_back(gr_d222f0[cur[i]].center40ad40());
   GrRect&r=gr_d222f0[cur[i]];
   
   dy.pick9ba6a0(facing);
   cost[cur[i]]=facing;
   
   
   
   switch(facing){
   case 0:element=1;level=element;enemies=rng.chance(33)?2:1;break;
   case 1:element=1;level=element;enemies=0;break;
   case 2:element=1;level=0;enemies=rng.chance(33)?2:1;break;
   case 3:element=1;enemies=0;level=enemies;break;
   case 4:element=0;level=element;enemies=rng.chance(33)?2:1;break;
   case 5:enemies=0;element=enemies;level=element;break;
   }
   if(begin==0)enemies=0;
   else if(begin<enemies)enemies=begin;
   if(facing!=5){
    if(level&&!closestDist[1].empty()&&!gr_flagC448ba0(r.topLeft40a970())){
     int tries=0;
     do{
      tries++;
      int id,rot;
      if(gr_placeWallProp6ca780(closestDist,1,r,commands,leader,id,mapID,rot)){
       placeMachine6c70a0(id,mapID,gr_b96348[rot],0,0);
       child[gr_cf35b0[id]->kind8]++;
       allies.push_back(gr_d31640.size()-1);
       break;
      }
     }while(tries<5);
    }
    while(enemies!=0){
     if(gr_flagA448b60(r.topLeft40a970()))break;
     enemies--;
     int n=0;
     do{
      n++;
 bool res;
 int ratio;
 int player;
      player=gr_cfd300.random40c130();
 int open;
      open=(int)sqrt((float)player);
      if(sqrt((float)player)-open>gr_c371d8)open++;
 int ny;
 int newValue;
      newValue=rng.rangeInt(0,gr_c36ecc);
      
      
      switch(newValue){
      case 0:ny=r.x+commands;ratio=gr_maxInt9cdb60(r.x+commands,r.x+r.w-commands-open);mapID.x=rng.rangeInt(ny,ratio);mapID.y=r.y+r.h-commands-open;break;
      case 1:ny=r.y+commands;ratio=gr_maxInt9cdb60(r.y+commands,r.y+r.h-commands-open);mapID.x=r.x+commands;mapID.y=rng.rangeInt(ny,ratio);break;
      case 2:ny=r.x+commands;ratio=gr_maxInt9cdb60(r.x+commands,r.x+r.w-commands-open);mapID.x=rng.rangeInt(ny,ratio);mapID.y=r.y+commands;break;
      case 3:ny=r.y+commands;ratio=gr_maxInt9cdb60(r.y+commands,r.y+r.h-commands-open);mapID.x=r.x+r.w-commands-open;mapID.y=rng.rangeInt(ny,ratio);break;
      }
      res=(open+commands*2>r.w&&open+commands*2>r.h)||rng.chance(gr_b9ea60);
      if(!res||gr_edgeClear6c9cb0(newValue,mapID,open,open,r)){
       if(!gr_areaEmpty6ca040(mapID,open,open,leader)){
 int updated;
 bool title;
        title=rng.chance(50);
        updated=0;
        if(newValue==0||newValue==2){
         do{
          if(title){for(int xx=mapID.x-1;xx>=ny;xx--)if(gr_areaEmpty6ca040(GrPoint(xx,mapID.y),open,open,leader)){mapID.x=xx;updated=2;break;}}
          else{for(int xx=mapID.x+1;xx<=ratio;xx++)if(gr_areaEmpty6ca040(GrPoint(xx,mapID.y),open,open,leader)){mapID.x=xx;updated=2;break;}}
          updated++;
          title=!title;
         }while(updated<2);
        }else{
         do{
          if(title){for(int yy=mapID.y-1;yy>=ny;yy--)if(gr_areaEmpty6ca040(GrPoint(mapID.x,yy),open,open,leader)){mapID.y=yy;updated=2;break;}}
          else{for(int yy=mapID.y+1;yy<=ratio;yy++)if(gr_areaEmpty6ca040(GrPoint(mapID.x,yy),open,open,leader)){mapID.y=yy;updated=2;break;}}
          updated++;
          title=!title;
         }while(updated<2);
        }
        if(updated!=3)continue;
       }
       f6ca2c0(mapID,player,open);
       buf++;
       begin--;
       break;
      }
     }while(n<5);
    }
    if(element&&bestDist.size9b81d0()!=0&&!gr_flagC448ba0(r.topLeft40a970())){
     int tries=0;
     do{
      tries++;
      if(gr_layout6cadf0(bestDist,1,r,commands,leader,link,clean,added)){
       for(int x=0;x<link.width9fcd80();x++)for(int y=0;y<link.height9b8f00();y++)
        if(*link.at(x,y)!=gr_caf15c){
         placeMachine6c70a0(*link.at(x,y),*clean.at(x,y),gr_b96348[*added.at(x,y)],0,0);
         allies.push_back(gr_d31640.size()-1);
        }
       break;
      }
     }while(tries<10);
    }
    f6c98c0(1,allies);
    if(!allies.empty()){
     if(!gr_d31640[allies.front()][0]->f45cb10())gr_shuffle9d8f80(allies);
     gr_d39f1c.push_back(new GrLists());
     gr_d39f1c.back()->list=allies;
     allies.clear();
    }
   }
  }
 }
 bestDist.reset9c07a0();
 for(unsigned p=0;p<gr_cf35b0.size();p++)
  if(gr_cf35b0[p]->kind4==2&&gr_cf35b0[p]->f100[0]!=0&&gr_b9e6f0[c2].v[gr_cf35b0[p]->f118])bestDist.add(p,gr_cf35b0[p]->f100[0]);
 vector<int> caption;
 vector<int> active(gr_cf13e8.size(),7);
 leader=gr_b9f5c0[c2].a;
 commands=gr_b9f5c0[c2].b;
 if(!gr_cf13e8.empty()){
  for(int i=0;i<gr_cf13e8.size();i++)caption.push_back(i);
  gr_shuffle9d8f80(caption);
 int sy;
  GrWL<int> shooter;
  for(int i=0;i<6;i++)if(gr_b91608[c2].v[i]!=0)shooter.add(i,(int)gr_b91608[c2].v[i]);
 int ranks;
 int point;
 int old;
  for(unsigned i=0;i<GR_SZ(caption);i++){
   GrRect*r=&gr_cf13e8[caption[i]].rect;
   if(r->x==-1)continue;
   
   shooter.pick9ba6a0(point);
   active[caption[i]]=point;
   bool nearest=true;
   
   
   
   switch(point){
   case 0:sy=1;ranks=sy;old=1;break;
   case 1:sy=1;ranks=sy;old=0;break;
   case 2:sy=1;ranks=0;old=1;break;
   case 3:sy=1;old=0;ranks=old;break;
   case 4:sy=0;ranks=sy;old=1;break;
   case 5:old=0;sy=old;ranks=sy;break;
   }
   if(begin==0)old=0;
   if(point!=5){
    if(ranks&&!closestDist[0].empty()&&!gr_flagC448ba0(r->topLeft40a970())){
     int tries=0;
     do{
      tries++;
      int id,rot;
      if(gr_placeWallProp6ca780(closestDist,0,*r,commands,leader,id,mapID,rot)){
       placeMachine6c70a0(id,mapID,gr_b96348[rot],0,0);
       child[gr_cf35b0[id]->kind8]++;
       allies.push_back(gr_d31640.size()-1);
       nearest=false;
       break;
      }
     }while(tries<5);
    }
    while(old!=0){
     if(gr_flagA448b60(r->topLeft40a970()))break;
     old--;
 bool heuristic;
 int entityID;
     entityID=0;
     
     do{
      entityID++;
      int multiplier=gr_cfd300.random40c130();
      int maxScore=(int)sqrt((float)multiplier);
      if(sqrt((float)multiplier)-maxScore>gr_c371d8)maxScore++;
      if(maxScore>r->w||maxScore>r->h)continue;
      int tries=0;
      heuristic=false;
      do{
       mapID.set40a010(rng.rangeInt(r->x,r->x+r->w-maxScore),rng.rangeInt(r->y,r->y+r->h-maxScore));
       if(gr_areaEmpty6ca040(mapID,maxScore,maxScore,leader)){
        GrRectB rect(mapID.x,mapID.y,maxScore,maxScore);
        heuristic=true;
        break;
       }
      }while(++tries<5);
      if(heuristic){
       f6ca2c0(mapID,multiplier,maxScore);
       buf++;
       begin--;
       nearest=false;
       break;
      }
     }while(entityID<5);
    }
    if(sy&&bestDist.size9b81d0()!=0&&!gr_flagC448ba0(r->topLeft40a970())){
     int tries=0;
     do{
      tries++;
      if(gr_layout6cadf0(bestDist,0,*r,commands,leader,link,clean,added)){
       for(int x=0;x<link.width9fcd80();x++)for(int y=0;y<link.height9b8f00();y++)
        if(*link.at(x,y)!=gr_caf15c){
         placeMachine6c70a0(*link.at(x,y),*clean.at(x,y),gr_b96348[*added.at(x,y)],0,0);
         allies.push_back(gr_d31640.size()-1);
        }
       nearest=false;
       break;
      }
     }while(tries<10);
    }
    f6c98c0(0,allies);
    if(!allies.empty()){
     if(!gr_d31640[allies.front()][0]->f45cb10())gr_shuffle9d8f80(allies);
     gr_d39f1c.push_back(new GrLists());
     gr_d39f1c.back()->list=allies;
     allies.clear();
    }
   }
   if(nearest)enemy.push_back(caption[i]);
  }
 }
 for(int i=0;i<9;i++){}
 for(int i=0;i<3;i++)closestDist[i].empty();
 cy=0;
 int distances;
 int distanceSq;
 bool current;
 current=gr_loc_d1e888->inRange46ecb0();
 if(0){}
 for(unsigned e=0;e<v10.size();e++){
  if(command!=0&&v10[e]->h14.isNull()&&v10[e]->h18.isNull()&&gr_b90000[v10[e]->h8->type]==1&&rng.chance(15)&&!gr_flagB448b80(v10[e]->pos)&&(!current||gr_distance40a3f0(p8,v10[e]->pos)>0x18)){
   for(unsigned k=0;k<v584.size();k++)if(gr_distance40a3f0(v584[k],v10[e]->pos)<=0x28)goto nextExit;
   {
   GrEntityDef*ed=selectRobotOfClass(1,0x1a,0,0);
   if(ed==0){}
   else{
    GrHE h=placeEntity6c58c0(ed,v10[e]->pos,3,1,0x22,0xe,0);
    if(h.valid()){
     h->ai45b590()->f451400(1);
     gr_overmind_cf6428.addParty(new GrParty(0,h,-1,0,0),0);
     v584.push_back(h->getPosition45a4a0());
     v594.push_back(h);
     v5a4.push_back(vector<GrHE>());
    }
    cy++;
   }
   command--;
   }
  }
  nextExit:;
 }
 for(unsigned i=0;i<gr_d1f31c.size();i++){
  door=gr_d1f31c[i].x8/2+gr_d1f31c[i].v14.size()*2+gr_d1f31c[i].x10*3;
  if(gr_cf3a00.empty()||door<=gr_cf3a00.back()->score)gr_cf3a00.push_back(new GrRoomRec(gr_d1f31c[i],door));
  for(unsigned j=0;j<gr_cf3a00.size();j++)if(door>gr_cf3a00[j]->score){gr_insertAt9dbdc0(gr_cf3a00,j,new GrRoomRec(gr_d1f31c[i],door));break;}
  if(gr_cf3a00.empty())break;
 }
 dest=ay*50/100;
 owner=gr_b90c40[gr_loc_d1e888->type]!=0?gr_grid_cfd44c.width9fcd80()*gr_grid_cfd44c.height9b8f00()/4000:0;
 bestValue=0;
 int bestIndex;
 bestIndex=0;
 b2=0;
 out2=0;
 leader=0;
 commands=gr_b9f5c0[c2].f;
 bool hp;
 bool health;
 bool attempt;
 bool angle;
 for(unsigned i=0;i<gr_cf3a00.size();i++){
  v574.push_back(gr_cf3a00[i]->r.center40ad40());
  if(closestDist[2].empty()&&command==0&&dest==0&&owner==0)break;
  GrRoomRec*room=gr_cf3a00[i];
  angle=!closestDist[2].empty()&&!gr_flagC448ba0(room->r.topLeft40a970())&&rng.chance(50);
  attempt=command!=0&&!gr_flagB448b80(room->r.topLeft40a970())&&(!current||gr_distance40a3f0(p8,room->r.center40ad40())>0x18);
  if(attempt)for(unsigned k=0;k<v584.size();k++)if(gr_distance40a3f0(v584[k],room->r.center40ad40())<=0x28){attempt=false;break;}
  hp=dest!=0&&!gr_flagB448b80(room->r.topLeft40a970());
  health=owner!=0&&!gr_flagC448ba0(room->r.topLeft40a970());
  if(!angle&&!attempt&&!hp&&!health)continue;
  if(attempt){
   GrEntityDef*ed=selectRobotOfClass(1,0x1a,0,0);
   if(ed==0){}
   else{
    mapID=room->r.center40ad40();
    if(gr_isEven406320(room->r.w)&&rng.chance(50))mapID.x--;
    if(gr_isEven406320(room->r.h)&&rng.chance(50))mapID.y--;
    GrHE h=placeEntity6c58c0(ed,mapID,3,1,0x22,0xe,0);
    if(h.valid()){
     h->ai45b590()->f451400(1);
     gr_overmind_cf6428.addParty(new GrParty(0,h,-1,0,0),0);
     v584.push_back(h->getPosition45a4a0());
     v594.push_back(h);
     v5a4.push_back(vector<GrHE>());
     if(gr_cf462c==0xb)vbd4.push_back(h->getPosition45a4a0());
    }
    bestIndex++;
   }
   command--;
  }else if(angle){
   int tries=0;
   do{
    tries++;
    int id,rot;
    if(gr_placeWallProp6ca780(closestDist,2,*room,commands,leader,id,mapID,rot)){
     placeMachine6c70a0(id,mapID,gr_b96348[rot],0,0);
     gr_d39f1c.push_back(new GrLists(gr_d31640.size()-1));
     bestValue++;
     break;
    }
   }while(tries<5);
  }else if(hp){
   GrEntityDef*ed=selectRobotOfClass(1,0x15,0,0);
   if(ed==0){}
   else{
    mapID=room->r.center40ad40();
    if(gr_isEven406320(room->r.w)&&rng.chance(50))mapID.x--;
    if(gr_isEven406320(room->r.h)&&rng.chance(50))mapID.y--;
    GrHE h=placeEntity6c58c0(ed,mapID,3,1,0x22,0xe,0);
    if(h.valid()){
     gr_overmind_cf6428.addParty(new GrParty(0,h,-1,0,0),0);
     if(gr_cf462c==0xb)vbd4.push_back(h->getPosition45a4a0());
    }
    b2++;
   }
   dest--;
   ay--;
  }else{
   GrPropDef*pd;
   gr_findProp9d7710(gr_cf35b0,"TF Node",pd);
   mapID=room->r.center40ad40();
   if(gr_isEven406320(room->r.w)&&rng.chance(50))mapID.x--;
   if(gr_isEven406320(room->r.h)&&rng.chance(50))mapID.y--;
   placeMachine6c70a0(pd->id,mapID,0,0,0);
   out2++;
   owner--;
  }
 }
 vector<GrE8> bestDistance;
 vector<bool> candidates;
 vector<int> action;
 placeRandomEncounter6f1e90(enemy,bestDistance,candidates,action);
 out=enemy;
 if(c2==0xd||c2==0xb){
  for(unsigned i=0;i<GR_SZ(enemy);i++){
 GrRoom* tags;
   tags=&gr_cf13e8[enemy[i]];
   GrArea changed(tags->rect);
   changed.grow40bc10(1);
   vector<GrPoint> tag;
   for(int x=changed.p1.x;x<=changed.p2.x;x++)for(int y=changed.p1.y;y<=changed.p2.y;y++){
    if((gr_grid_cfd44c.inBounds9b45c0(x-1,y)&&!changed.test40b700(x-1,y)&&(*gr_grid_cfd44c.at(x-1,y))->f4550b0())
     ||(gr_grid_cfd44c.inBounds9b45c0(x,y-1)&&!changed.test40b700(x,y-1)&&(*gr_grid_cfd44c.at(x,y-1))->f4550b0())
     ||(gr_grid_cfd44c.inBounds9b45c0(x+1,y)&&!changed.test40b700(x+1,y)&&(*gr_grid_cfd44c.at(x+1,y))->f4550b0())
     ||(gr_grid_cfd44c.inBounds9b45c0(x,y+1)&&!changed.test40b700(x,y+1)&&(*gr_grid_cfd44c.at(x,y+1))->f4550b0())
     ||(gr_grid_cfd44c.inBounds9b45c0(x-1,y-1)&&!changed.test40b700(x-1,y-1)&&(*gr_grid_cfd44c.at(x-1,y-1))->f4550b0())
     ||(gr_grid_cfd44c.inBounds9b45c0(x+1,y-1)&&!changed.test40b700(x+1,y-1)&&(*gr_grid_cfd44c.at(x+1,y-1))->f4550b0())
     ||(gr_grid_cfd44c.inBounds9b45c0(x-1,y+1)&&!changed.test40b700(x-1,y+1)&&(*gr_grid_cfd44c.at(x-1,y+1))->f4550b0())
     ||(gr_grid_cfd44c.inBounds9b45c0(x+1,y+1)&&!changed.test40b700(x+1,y+1)&&(*gr_grid_cfd44c.at(x+1,y+1))->f4550b0()))continue;
    tag.push_back(GrPoint(x,y));
   }
   for(unsigned k=0;k<tag.size();k++)gr_setTerrain6c9c90(tag[k],TERRAIN_EARTH);
   vector<GrPoint> branch;
   for(unsigned j=0;j<tags->v28.size();j++){
    GrPoint top2(tags->v28[j]);
 int wall;
    wall=1;
    GrPoint text;
    do{
     bool last=wall==tags->v5c[j];
     (*gr_grid_cfd44c.atPoint(top2))->f66a050(last?TERRAIN_CAVE_WALL->id:TERRAIN_EARTH->id,2,0);
     if(!last){
      text=top2;
      gr_translate446dd0(text,tags->v38[j],-1,0);
      gr_fn9d3020(branch,text);
      text=top2;
      gr_translate446dd0(text,tags->v38[j],1,0);
      gr_fn9d3020(branch,text);
     }
     gr_translate446dd0(top2,tags->v38[j],0,1);
     wall++;
    }while(wall<=tags->v5c[j]);
   }
   for(unsigned j=0;j<branch.size();j++){
    GrPoint q(branch[j]);
    if((*gr_grid_cfd44c.at(q.x-1,q.y-1))->terrain9fcd80()==gr_cefb9c||(*gr_grid_cfd44c.at(q.x-1,q.y))->terrain9fcd80()==gr_cefb9c
     ||(*gr_grid_cfd44c.at(q.x-1,q.y+1))->terrain9fcd80()==gr_cefb9c||(*gr_grid_cfd44c.at(q.x,q.y-1))->terrain9fcd80()==gr_cefb9c
     ||(*gr_grid_cfd44c.at(q.x,q.y+1))->terrain9fcd80()==gr_cefb9c||(*gr_grid_cfd44c.at(q.x+1,q.y-1))->terrain9fcd80()==gr_cefb9c
     ||(*gr_grid_cfd44c.at(q.x+1,q.y))->terrain9fcd80()==gr_cefb9c||(*gr_grid_cfd44c.at(q.x+1,q.y+1))->terrain9fcd80()==gr_cefb9c)continue;
    gr_setTerrain6c9c90(q,TERRAIN_EARTH);
   }
  }
 }
 vector<int> a1(15u,0);
 int bx;
 int bits;
 int bestScore;
 GrEntityDef* attempts[3];
 vector<int> adjacent(15u,0);
 vector<int> amount;
 failed=gr_loc_d1e888->type!=0xd&&gr_loc_d1e888->type!=0xb?gr_cf13e8.size():fae0;
 for(int i=0;i<failed;i++)if(!gr_containsRecord9db330(action,i))amount.push_back(i);
 vector<int> cols;
 for(int i=0;i<gr_d222f0.size();i++)cols.push_back(i);
 GrWL<int> behaviour;
 for(int i=0;i<15;i++){
  if(gr_b96d40[c2].v[i]!=0){
   switch(i){
   case 14:if(gr_cf462c==4||gr_cf462c==7)continue;else if(!gr_gd_d1e860.f46fac0())continue;break;
   case 12:if((float)cx>gr_ba65cc[gr_cf4718])continue;break;
   }
   behaviour.add(i,gr_b96d40[c2].v[i]);
  }
 }
 int bonus;
 bonus=gr_b90000[c2]==1?3:9;
 bx=gr_b90000[c2]==2;
 GrPoint adj;
 counter=gr_d2a688[c2].random40c130();
 if(gr_pd_cf45d8.isTypeAllowed46e100(c2))counter=gr_d2a688[c2].y*10;
 cnt=counter;
 if(cnt!=0&&behaviour.size9b81d0()==0)cnt=0;
 arr=0;
 while(cnt!=0){
  cnt--;
 int disabled;
  disabled=behaviour.pick();
  GrWL<GrPropDef*> total2;
  for(unsigned p=0;p<gr_cf35b0.size();p++)
   if(gr_cf35b0[p]->f140==disabled&&gr_cf35b0[p]->f144!=0&&gr_cf35b0[p]->f150==bx&&(gr_cf35b0[p]->range148.y==0||gr_cf35b0[p]->range148.contains40c190(found2)))total2.add(gr_cf35b0[p],gr_cf35b0[p]->f144);
  if(total2.size9b81d0()==0){cnt++;arr++;if(arr>1000)cnt=0;continue;}
 GrPropDef* color;
  color=total2.pick();
  GrWL<int> closest;
  for(int i=0;i<5;i++)if(gr_b96a88[disabled].v[i])closest.add(i,gr_b96a88[disabled].v[i]);
  if(closest.size9b81d0()==0)continue;
  for(int tries=0,before=GR_SZB(gr_d20248);tries<20;tries++){
 int visible;
 int vec;
   vec=closest.pick();
   GrWL<int> value;
   for(int i=0;i<4;i++)if(gr_b96cf0[vec].v[i])value.add(i,gr_b96cf0[vec].v[i]);
   if(value.size9b81d0()==0)continue;
   visible=value.pick();
   switch(visible){
   case 0:{
    int t=0;
    while(t<100&&!amount.empty()){
     t++;
 int edges;
     edges=gr_randomRec9d5d00(amount);
     if(gr_cf13e8[edges].v28.empty()&&gr_cf13e8[edges].v48.empty())continue;
 int e2;
     e2=rng.rangeInt(0,gr_cf13e8[edges].v28.size()+GR_SZ(gr_cf13e8[edges].v48)-1);
     GrPoint direction;
     if(e2<gr_cf13e8[edges].v28.size())direction=gr_cf13e8[edges].v28[e2];
     else{
      e2-=gr_cf13e8[edges].v28.size();
      direction=rng.chance(50)?gr_cf65c4[gr_cf13e8[edges].v48[e2]].pts.front():gr_cf65c4[gr_cf13e8[edges].v48[e2]].pts.back();
     }
     if((current&&gr_distance40a3f0(p8,direction)<=15)||(c2==0x22&&direction.contains409d70(100,60,77,30)))continue;
     vector<GrPoint> hidden;
     gr_surrounding4faaf0(direction,hidden);
     gr_shuffle9d7350(hidden);
     adj.set409ff0(-1);
     for(unsigned k=0;k<hidden.size();k++)if(gr_grid_cfd44c.contains9b43b0(hidden[k])&&(*gr_grid_cfd44c.atPoint(hidden[k]))->f45d6a0()){adj=hidden[k];break;}
     if(adj.x==-1){}
     else{
      if(gr_f6d4b80(adj))continue;
      else if(placeProp6c67b0(color,adj,-1,bonus,-1)){a1[disabled]++;adjacent[disabled]++;break;}
     }
    }
   }break;
   case 1:{
    int t=0;
    while(t<100){
     t++;
     gr_grid_cfd44c.random9cf0c0(adj);
     if(*gr_cf1964.atPoint(adj)==4&&(!current||gr_distance40a3f0(p8,adj)>15)){
      if(gr_f6d4b80(adj))continue;
      GrArea a;
      if(!gr_f6d4640(adj,vec,a))continue;
      for(int k=0,status=0;k<gr_b96bc0[disabled].v[vec];k++){
       for(int j=0;j<20;j++){
        a.randomPoint40be30(&adj);
        if(gr_grid_cfd44c.contains9b43b0(adj)&&(*gr_grid_cfd44c.atPoint(adj))->f45d6a0()){
         if(placeProp6c67b0(color,adj,status!=0?GR_SZB(gr_d20248)-1:-1,bonus,-1)){status++;a1[disabled]++;if(status==1)adjacent[disabled]++;}
         break;
        }
       }
      }
      break;
     }
    }
   }break;
   case 2:case 3:{
    int t=0;
    while(t<100&&((visible==2&&!amount.empty())||(visible==3&&!cols.empty()))){
     t++;
     GrRect&rr=visible==2?gr_cf13e8[gr_randomRec9d5d00(amount)].rect:gr_d222f0[gr_randomRec9d5d00(cols)];
     int border=visible==2?2:5;
     GrArea a;
     a.p1.x=rr.x;
     a.p1.y=rr.y;
     a.p2.x=rr.x+(rr.w-1)-(border-1);
     a.p2.y=rr.y+(rr.h-1)-(border-1);
     if(a.p2.x<=a.p1.x||a.p2.y<=a.p1.y||!(*gr_grid_cfd44c.atPoint(a.p1))->f45d6a0())continue;
     if(gr_f6d4b80(a.center40b620()))continue;
     for(int k=0,status=0;k<gr_b96bc0[disabled].v[vec];k++){
      for(int j=0;j<20;j++){
       a.randomPoint40be30(&adj);
       if((!current||gr_distance40a3f0(p8,adj)>15)&&(*gr_grid_cfd44c.atPoint(adj))->f45d6a0()){
        if(placeProp6c67b0(color,adj,status!=0?GR_SZB(gr_d20248)-1:-1,bonus,-1)){status++;a1[disabled]++;if(status==1)adjacent[disabled]++;}
        break;
       }
      }
     }
     break;
    }
   }break;
   }
   if(before<GR_SZB(gr_d20248))break;
  }
 }
 for(int i=0;i<15;i++)a1[i];
 for(int i=0;i<3;i++){
  int width=i==0?7:i==1?6:4;
  int placed=0;
  if(!closestDist[i].empty()){
   for(unsigned j=0;j<GR_SZ(closestDist[i]);j++){
 int entityCount;
    entityCount=closestDist[i][j];
 int r1;
 int mode;
    mode=gr_cf35b0[entityCount]->layers.front()->width9fcd80();
    r1=gr_cf35b0[entityCount]->layers.front()->height9b8f00();
    GrPos invalid;
    GrPos line;
 int elem;
    
    if(gr_findWallStrip6cbb40(mode,r1,width,invalid,line,elem,0,gr_cf35b0[entityCount]->kind8==5,0)){
     gr_fillRing6cba00(line,invalid,5,TERRAIN_CAVE_WALL,0);
     placeMachine6c70a0(entityCount,GrPoint(line.x,line.y),gr_b96348[gr_bb8360[elem]],0,0);
     gr_d39f1c.push_back(new GrLists(gr_d31640.size()-1));
     placed++;
    }
   }
  }
 }
 if(gr_b90098[c2]!=0){
 GrPropDef* walls;
  walls=0;
 int frontier;
  vector<int> flags;
  flags.push_back(4);flags.push_back(6);flags.push_back(7);
  frontier=0;
  for(int n=gr_b90098[c2];n>0;n--){
   GrPos iter;
   GrPos health2;
 int g2;
   for(unsigned j=0;j<GR_SZ(flags);j++){
    
    if(gr_findWallStrip6cbb40(2,1,flags[j],iter,health2,g2,0,0,1)){
     gr_fillRing6cba00(health2,iter,5,caveinThirdTerrain,1);
     if(walls==0&&!gr_findProp9d7710(gr_cf35b0,"DSF Access",walls))goto dsfDone;
     GrPoint at;
     switch(g2){
     case 0:at.set40a010(health2.x,health2.y);break;
     case 1:at.set40a010(health2.x,health2.y);break;
     case 2:at.set40a010(health2.x+1,health2.y);break;
     case 3:at.set40a010(health2.x,health2.y+1);break;
     }
     placeMachine6c70a0(walls->id,at,0,1,1);
     gr_d39f1c.push_back(new GrLists(gr_d31640.size()-1));
     frontier++;
     break;
    }
   }
  }
  dsfDone:;
 }
 GrWL<int> base;
 for(int i=0;i<3;i++)if(gr_b9f368[c2].v[i])base.add(i,gr_b9f368[c2].v[i]);
 int col;
 col=0;
 for(int n=ax-1;n>=0;n--){
 int y0;
 GrItemDef* x2;
 int sx;
 vector<GrPoint>* parts;
 int ox;
  
  base.pick9ba6a0(ox);
  x2=0;
  if(rng.chance(25))x2=selectRandomItemOfRating6c40e0(found2,0,0,0x1f,0x12,0x2a,0);
  if(x2==0)x2=selectRandomItem6c3bc0(0,0x1f,0x12);
  if(x2==0)continue;
 GrRect* nearestDist;
  nearestDist=0;
  parts=0;
  sx=0;
  
  do{
   if(++sx>20){nearestDist=0;parts=0;break;}
   switch(ox){
   case 0:
    if(gr_cf13e8.empty())break;
    nearestDist=0;parts=0;
    for(int k=0;k<gr_ba3aec[x2->f5c]+1;k++){
     int r=gr_randomIndex9db950(gr_cf13e8);
     if(gr_cf13e8[r].f58*100/gr_ced21c>=gr_ba3adc[x2->f5c]){
      if(gr_cf13e8[r].rect.x==-1){parts=&gr_cf13e8[r].v14;y0=gr_cf13e8[r].f24;}
      else nearestDist=&gr_cf13e8[r].rect;
      break;
     }
    }
    break;
   case 1:
    if(gr_d222f0.empty())break;
    nearestDist=&gr_d222f0[gr_randomIndex9dbbe0(gr_d222f0)];
    break;
   case 2:
    if(gr_d1f31c.empty())break;
    nearestDist=(GrRect*)&gr_d1f31c[gr_randomIndex9db990(gr_d1f31c)];
    break;
   }
  }while((nearestDist&&gr_flagA448b60(nearestDist->topLeft40a970()))||(parts&&gr_bb8380[y0]));
  if(nearestDist!=0||parts!=0){
   GrPoint p;
   for(int k=0;k<20;k++){
    if(nearestDist)nearestDist->randomPos40b000(&p);
    else p=gr_randomPoint9d5350(*parts);
    if(gr_areaEmpty6ca040(p,1,1,1)){
     GrHI h=f6c5400(x2,p);
     if(h.valid()){
      if(h->f457880()==0)h->f450460(gr_d357a0[cx].r.random40c130());
      if(gr_cf4734!=0)h->f450460(gr_maxInt9cdb60(1,rng.rangeInt(gr_c37034,gr_c37038)*h->f9b6bf0()/100));
      col++;
      ax--;
     }
     break;
    }
   }
  }
 }
 int doors;
 doors=0;
 if(ay!=0){
  caption.clear();
  for(int i=0;i<GR_SZ(active);i++){
   if(gr_cf13e8[i].rect.x==-1||gr_flagB448b80(gr_cf13e8[i].rect.topLeft40a970()))continue;
   if(caption.empty()||(gr_b91258[active[i]]<=gr_b91258[active[caption.back()]]&&gr_cf13e8[i].rect.area40ad00()<=gr_cf13e8[caption.back()].rect.area40ad00()))caption.push_back(i);
   else for(unsigned j=0;j<GR_SZ(caption);j++)
    if(gr_b91258[active[i]]>gr_b91258[active[caption[j]]]||(gr_b91258[active[i]]==gr_b91258[active[caption[j]]]&&gr_cf13e8[i].rect.area40ad00()>gr_cf13e8[caption[j]].rect.area40ad00())){gr_insertAt9dbdc0(caption,j,i);break;}
  }
  for(unsigned i=0;i<GR_SZ(caption);i++){
   GrRoom*room=&gr_cf13e8[caption[i]];
   int t=0;
   do{
    t++;
 int prefix;
    prefix=rng.rangeInt(0,gr_c36ecc);
    if(gr_containsRecord9db330(room->v38,prefix))continue;
 GrEntityDef* oy;
    GrPos8 oldValue;
    switch(prefix){
    case 0:oldValue.x=rng.rangeInt(0,room->rect.w-1)+room->rect.x;oldValue.y=room->rect.y-1;break;
    case 1:oldValue.x=room->rect.x+room->rect.w;oldValue.y=rng.rangeInt(0,room->rect.h-1)+room->rect.y;break;
    case 2:oldValue.x=rng.rangeInt(0,room->rect.w-1)+room->rect.x;oldValue.y=room->rect.y+room->rect.h;break;
    case 3:oldValue.x=room->rect.x-1;oldValue.y=rng.rangeInt(0,room->rect.h-1)+room->rect.y;break;
    }
    oy=selectRobotOfClass(1,0x15,0,0);
    if(oy==0)continue;
 int num;
 int min;
    min=oy->size;
    num=min;
    if(gr_ringFree6cb8c0(oldValue,room->rect)){
     gr_fillRing6cba00(oldValue,room->rect,0,TERRAIN_CAVE_WALL,0);
     GrHE h=placeEntity6c58c0(oy,oldValue.toPoint40a970(),3,1,0x22,0xe,0);
     if(h.valid()){
      gr_overmind_cf6428.addParty(new GrParty(0,h,-1,0,0),0);
      if(gr_cf462c==0xb)vbd4.push_back(h->getPosition45a4a0());
     }
     doors++;
     ay--;
     break;
    }
   }while(t<5);
   if(ay==0)break;
  }
 }
 bits=areas->f8;
 chosen=0;
 cur.clear();
 if(bits!=0){
  cur.clear();
  for(int i=0;i<GR_SZ(cost);i++){
   if(gr_d222f0[i].x==-1)continue;
   if(current&&(gr_flagB448b80(GrPoint(gr_d222f0[i].x,gr_d222f0[i].y))||gr_flagB448b80(GrPoint(gr_d222f0[i].x+gr_d222f0[i].w-1,gr_d222f0[i].y))
    ||gr_flagB448b80(GrPoint(gr_d222f0[i].x,gr_d222f0[i].y+gr_d222f0[i].h-1))||gr_flagB448b80(GrPoint(gr_d222f0[i].x+gr_d222f0[i].w-1,gr_d222f0[i].y+gr_d222f0[i].h-1))
    ||gr_flagB448b80(gr_d222f0[i].center40ad40())))continue;
   if(cur.empty()||(gr_b91258[cost[i]]<=gr_b91258[cost[cur.back()]]&&gr_d222f0[i].area40ad00()<=gr_d222f0[cur.back()].area40ad00()))cur.push_back(i);
   else for(unsigned j=0;j<GR_SZ(cur);j++)
    if(gr_b91258[cost[i]]>gr_b91258[cost[cur[j]]]||(gr_b91258[cost[i]]==gr_b91258[cost[cur[j]]]&&gr_d222f0[i].area40ad00()>gr_d222f0[cur[j]].area40ad00())){gr_insertAt9dbdc0(cur,j,i);break;}
  }
  for(unsigned i=0;i<GR_SZ(cur);i++){
   GrRect&r=gr_d222f0[cur[i]];
   int tile=0;
   do{
    tile++;
 int speed;
    speed=rng.rangeInt(0,gr_c36ecc);
    GrPos8 s;
    switch(speed){
    case 0:s.x=rng.rangeInt(0,r.w-2)+r.x;s.y=r.y-2;break;
    case 1:s.x=r.x+r.w;s.y=rng.rangeInt(0,r.h-2)+r.y;break;
    case 2:s.x=rng.rangeInt(0,r.w-2)+r.x;s.y=r.y+r.h;break;
    case 3:s.x=r.x-2;s.y=rng.rangeInt(0,r.h-2)+r.y;break;
    }
 int retval;
 int pt;
 GrEntityDef* prev;
    prev=selectRobotOfClass(1,0x1c,0,0);
    pt=prev->size;
    retval=pt;
    if(gr_ringFree6cb8c0(s,r)){
     gr_fillRing6cba00(s,r,0,TERRAIN_CAVE_WALL,0);
     GrHE h=placeEntity6c58c0(prev,s.toPoint40a970(),3,1,0x22,0xe,0);
     if(h.valid()){
      gr_overmind_cf6428.addParty(new GrParty(0,h,-1,0,0),0);
      if(gr_cf462c==0xb)vbd4.push_back(h->getPosition45a4a0());
     }
     chosen++;
     bits--;
     break;
    }
   }while(tile<30);
   if(bits==0)break;
  }
 }
 bottom=areas->fc;
 bestPoint=0;
 if(bottom!=0)for(int n=bottom;n>0;n--)if(gr_overmind_cf6428.f6892c0(1,0,0)){bestPoint++;bottom--;}
 distances=gr_b91e88[c2].v[0];
 nx=0;
 if(distances!=0)for(int n=distances;n>0;n--)if(gr_overmind_cf6428.f6892c0(1,0,1)){nx++;distances--;}
 int center;
 center=c2==0xd?gr_minInt9cdb30(gr_d1eb68/15,2)+gr_b92854[found2]:areas->f10;
 int behavior;
 behavior=0;
 if(center!=0){
  if(gr_cf462c==9)center=(int)(center*gr_ba7b4c);
  if(gr_d1ebd8.valid()){
   switch(c2){
   case 30:case 31:center++;break;
   case 5:center+=8;break;
   }
  }
  for(int n=center;n>0;n--)
   if(gr_overmind_cf6428.spawnPatrol6896d0(GrHE(),1,0,0,0,0,0,n==1&&c2==0xd&&rng.chance(20)?1:10,0)){behavior++;center--;}
 }
 closed=areas->f14;
 costSoFar=0;
 gr_cf6a80.clear();
 gr_cf6a90.clear();
 if(closed!=0){
  for(int n=closed;n>0;n--){
   if(gr_overmind_cf6428.f68a500(1,0,0)){
    costSoFar++;
    closed--;
    if(gr_cf6a24&&rng.chance(25)){
     gr_cf6a80.push_back(gr_cf6478.back()->h4);
     vector<GrX*> answer;
     vector<int> a2;
     bool ok=f6ca170(GrPoint(-1),gr_minInt9cdb30(gr_cf6a80.back()->f45a810(),gr_cfd300.random40c130()),gr_d33bd8.random40c130(),0,answer,a2,0x2a);
     if(!ok)gr_cf6a80.pop_back();
     else{
      gr_cf6a90.push_back(vector<string>());
      for(unsigned i=0;i<answer.size();i++)gr_cf6a90.back().push_back(gr_intToString(gr_maxInt9cdb60(1,a2[i]))+"x "+answer[i]->name);
     }
    }
   }
  }
 }
 GrWL<int> armor;
 for(int i=0;i<5;i++)armor.add(i,gr_b92558[c2].v[i]);
 bestScore=areas->f20;
 if(!gr_d1ebfc&&(gr_stringToInt(gr_gd_d1e860.getEntryText("extTransferStationDisabled_g"))!=0||gr_stringToInt(gr_gd_d1e860.getEntryText("hubTransferStationDisabled_g"))!=0))bestScore=(int)(bestScore*gr_b92850);
 desc=0;
 if(bestScore!=0){
  for(int n=bestScore;n>0;n--){
   int kind;
   armor.pick9ba6a0(kind);
   if(gr_overmind_cf6428.f683b60(kind,1,0).valid()){desc++;bestScore--;}
  }
 }
 distanceSq=0;
 
 gr_fillInts9e2be0(attempts,3,0);
 for(int i=0,victim=0;i<gr_d25de0.size()&&victim<3;i++)if(gr_d25de0[i]->f28==8&&gr_d25de0[i]->f24==1)attempts[victim++]=gr_d25de0[i];
 for(unsigned i=0;i<v118[2].size();i++){
  if(rng.chance(30)){
   int lvl=(*gr_grid_cfd44c.atPoint(v118[2][i]))->getProp()->f45cb30()->f8;
   if(lvl==0)continue;
   for(int k=lvl;k>=1;k--){
    if(attempts[k-1]!=0&&attempts[k-1]->f68<=gr_gd_d1e860.getDepthIndex()){
     GrPoint it(v118[2][i]);
     GrPoint h2;
 bool ty;
     ty=false;
     GrArea traps;
     gr_grid_cfd44c.getRect9b4430(it,gr_bba390,traps);
     for(int t=0;t<20;t++){
      h2=traps.randomPoint40be90();
      if((*gr_grid_cfd44c.atPoint(h2))->canPlace66ad20(1)){
       (*gr_grid_cfd44c.atPoint(it))->getProp()->f45ccf0(1);
       if(f716940(h2,it,0,0))ty=true;
       (*gr_grid_cfd44c.atPoint(it))->getProp()->f45ccf0(0);
       if(ty)break;
      }
     }
     if(!ty)h2=it;
     GrHE to=placeEntity6c58c0(attempts[k-1],h2,4,1,0x22,0xe,0);
     if(to.isNull()){}
     else{
      distanceSq++;
      GrArea b;
      gr_grid_cfd44c.getRect9b4430(it,gr_bba390,b);
      to->ai45b590()->f459410(b);
     }
     break;
    }
   }
  }
 }
 if(c2!=10&&c2!=0x19&&(float)cx<=gr_ba65b4[gr_cf4718]){
  int opCount=0;
  vector<GrHE> operators;
  GrEntityDef*ops[3];
  gr_fillInts9e2be0(ops,3,0);
  for(int i=0,victim=0;i<gr_d25de0.size()&&victim<3;i++)if(gr_d25de0[i]->f28==9&&gr_d25de0[i]->f24==1)ops[victim++]=gr_d25de0[i];
  for(unsigned i=0;i<v118[0].size();i++){
   if(rng.chance(25)&&(*gr_grid_cfd44c.atPoint(v118[0][i]))->getProp()->getName45c5b0()=="Terminal"&&!(*gr_grid_cfd44c.atPoint(v118[0][i]))->getProp()->f45cb30()->f45c160(5,0)
    &&(*gr_grid_cfd44c.atPoint(v118[0][i]))->getProp()->f45c9b0()==0){
    int lvl=(*gr_grid_cfd44c.atPoint(v118[0][i]))->getProp()->f45cb30()->fc;
    if(lvl==0)continue;
    GrPoint at(v118[0][i]);
    bool far=true;
    for(unsigned j=0;j<operators.size();j++)if(gr_distance40a3f0(at,operators[j]->getPosition45a4a0())<20){far=false;break;}
    if(!far)continue;
    for(int k=lvl;k>=1;k--){
     if(ops[k-1]!=0&&ops[k-1]->f68<=gr_gd_d1e860.getDepthIndex()){
      GrPoint v1;
 bool y2;
      y2=false;
      GrArea energy;
      gr_grid_cfd44c.getRect9b4430(at,gr_bba394,energy);
      for(int t=0;t<20;t++){
       v1=energy.randomPoint40be90();
       if((*gr_grid_cfd44c.atPoint(v1))->canPlace66ad20(1)){
        (*gr_grid_cfd44c.atPoint(at))->getProp()->f45ccf0(1);
        if(f716940(v1,at,0,0))y2=true;
        (*gr_grid_cfd44c.atPoint(at))->getProp()->f45ccf0(0);
        if(y2)break;
       }
      }
      if(!y2)v1=at;
      GrHE u=placeEntity6c58c0(ops[k-1],v1,3,1,0x22,0xe,0);
      if(u.isNull()){}
      else{
       opCount++;
       operators.push_back(u);
       u->ai45b590()->setTerminal5b3760(at);
       (*gr_grid_cfd44c.atPoint(at))->getProp()->f45cb30()->f70=u;
      }
      break;
     }
    }
   }
  }
 }
 if(c2==0x1e||c2==0x1f||c2==0x20||c2==0x21){
  vector<GrHE> carriers;
  vector<GrHE>&m3=v4c[3]->members416f40();
  for(unsigned i=0;i<m3.size();i++)if(m3[i]->faction45a2c0()==0x14)carriers.push_back(m3[i]);
  vector<GrHE>&m4=v4c[4]->members416f40();
  for(unsigned i=0;i<m4.size();i++)if(m4[i]->faction45a2c0()==0x14)carriers.push_back(m4[i]);
  for(unsigned i=0;i<carriers.size();i++){
   GrItemDef*archive;
   if(gr_findItem9d7a40(gr_d2d1c4,"Schematic Archive",archive)){
    for(int n=rng.rangeInt(gr_c36edc,gr_c36ed8);n!=0;n--){
     GrHI h=gr_world_cefc4c->f6c51d0(archive,carriers[i],0,0);
     if(h.valid()){
      if(rng.chance(75)){
       GrItemDef*sch;
       do{
        sch=gr_world_cefc4c->selectRandomItem6c3bc0(1,0x1f,0x12);
        if(sch==0)break;
       }while(!sch->f209);
       if(sch){h->addEffect4585a0(new GrPair(gr_d2f0f8[0x4f],sch->id));h->f57bff0(0x50,1);}
      }else{
       int*robot=gr_world_cefc4c->f6c5180();
       if(robot){h->addEffect4585a0(new GrPair(gr_d2f0f8[0x4f],-*robot));h->f57bff0(0x50,1);}
      }
      if(h->effectValue457be0(0x4f)==0)h->remove57dbe0(0,0,1,1);
     }
    }
   }
  }
 }
 if(gr_b90000[c2]!=1||c2==0x23)gr_d39f1c.clear();
 if(!gr_d39f1c.empty()){
  gr_shuffle9d8f80(gr_d39f1c);
  for(int i=0;i<gr_d39f1c.size();i++){
   for(unsigned j=0;j<GR_SZ(gr_d39f1c[i]->list);j++)
    for(unsigned k=0;k<gr_d31640[gr_d39f1c[i]->list[j]].size();k++)gr_d31640[gr_d39f1c[i]->list[j]][k]->setField448080(i);
 int groupID;
   GrHP group=gr_d31640[gr_d39f1c[i]->list.front()][0];
   groupID=group->getDef9b8f00()->kind8;
   if(groupID>=6)groupID=9;
   vector<int> entity;
   vector<int> best;
   if(groupID!=9){
    for(int j=0;j<gr_d39f1c.size();j++){
     if(j!=i){
      GrHP other=gr_d31640[gr_d39f1c[j]->list.front()][0];
      if(other->getDef9b8f00()->kind8==groupID&&!gr_containsRecord9db330(gr_d39f1c[i]->v10,j)){
       entity.push_back(j);
       best.push_back(gr_distance40a3f0(gr_d31640[group->f44ab40()][0]->f4184d0(),gr_d31640[other->f44ab40()][0]->f4184d0()));
      }
     }
    }
    if(!entity.empty()){
     int m=gr_indexOfMin9d9270(best);
     gr_d39f1c[i]->v10.push_back(entity[m]);
     gr_d39f1c[entity[m]]->v10.push_back(i);
     goto linkDone;
    }
   }
   {
    entity.clear();
    best.clear();
    for(int j=0;j<gr_d39f1c.size();j++){
     if(j!=i){
      GrHP other=gr_d31640[gr_d39f1c[j]->list.front()][0];
      if(!gr_containsRecord9db330(gr_d39f1c[i]->v10,j)){
       entity.push_back(j);
       best.push_back(gr_distance40a3f0(gr_d31640[group->f44ab40()][0]->f4184d0(),gr_d31640[other->f44ab40()][0]->f4184d0()));
      }
     }
    }
    if(!entity.empty()){
     int m=gr_indexOfMin9d9270(best);
     gr_d39f1c[i]->v10.push_back(entity[m]);
     gr_d39f1c[entity[m]]->v10.push_back(i);
    }
   }
   linkDone:;
  }
  for(unsigned i=0;i<gr_d39f1c.size();i++)
   for(unsigned j=0;j<GR_SZ(gr_d39f1c[j]->v10);j++)gr_d39f1c[i]->v20.push_back(rng.chance(50)?1:0);
 }
}
GrRoomRec::GrRoomRec(const GrE24&,int){}
GrLists::GrLists(){}
GrPair::GrPair(int*,int){}
