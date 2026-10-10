// NOTE: placeholder names and partial layouts; BS 0x6ead20: Factory (FRG) map setup (item caches, guard
// posts, V-Series, Overlord, hub targets and the access-terminal rings).
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;
struct BV14Entity;struct BV14AI;struct BV14Item;struct BV14Prop;struct BV14Terrain {int id;};
struct BV14Point {int x,y;BV14Point();BV14Point(int,int);BV14Point &operator=(const BV14Point&);BV14Point &operator+=(const BV14Point&);void set_40a060(const BV14Point&,int,int);bool equals_409b90(const BV14Point&);bool test_409cf0(int,int);void offset_40a2a0(int,int);};
struct BV14Area {BV14Point p1,p2;BV14Area();BV14Area(int,int,int,int);void set(int,int,int,int);void set_40b360(const BV14Point&,int,int);BV14Point randomPoint();BV14Point center();bool contains(const BV14Point&);void offsetBy(const BV14Area&);void clip(BV14Point&,BV14Point&);};
struct BV14Rect {int x,y,w,h;BV14Rect(int,int,int,int);};
struct BV14HE {int id;BV14HE();bool isValid() const;BV14Entity *operator->() const;};
struct BV14HI {int id;bool isValid() const;bool isNull() const;BV14Item *operator->() const;};
struct BV14HP {int id;bool isValid() const;BV14Prop *operator->() const;};
struct BV14EntityAI {BV14EntityAI(BV14HE,int,int);char pad[0x130];};
struct BV14Entity {int getFaction();void setAI(BV14EntityAI*);BV14AI *getAI();BV14Point &getPosition();void removeEffectsA(int);};
struct BV14AI {void unknown4593d0(vector<BV14Point>&);void setFollowEntity(BV14HE,int);void unknown459410(BV14Area&);void setField451930(int);void setUnknown451400(int);};
struct BV14Item {const string &name457860();int getNestedField();};
struct BV14PropDef;
struct BV14Prop {BV14PropDef *def();void *unknown45c800(int);void unknown45ce10(int,int,int,BV14HE);};
struct BV14Cell {BV14Terrain *terrain();void unknown66a050(int,int,bool);BV14HI getItem();BV14HE getEntity();BV14HP getProp();bool canPlaceEntity(int);bool field4550b0();};
struct BV14Grid {BV14Cell **at(int,int);BV14Cell **atPoint(const BV14Point&);int getWidth();int getHeight();BV14Area getArea();bool contains(const BV14Point&);};extern BV14Grid bv14_cells_cfd44c;
extern BV14Terrain *TERRAIN_CAVE_WALL,*caveinThirdTerrain;
struct BV14Special {char pad[0x48];int id;char pad4c[4];BV14Point pos;char pad58[8];};extern const vector<BV14Special> bv14_specials_cf124c;extern int bv14_id_d2ed8c;
struct BV14Machine {void unknown458460();vector<BV14HE> &members416f40();};
struct BV14HM {int id;BV14Machine *operator->() const;};
template<class T> void BV14_shuffle(vector<T>&);
template<class T> void BV14_shufflePts(vector<T>&);
template <class T>
class OpR5h_WL	// NOTE: partial declaration of the weighted list from src/op/op_r5h_wl.cpp
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	void add(T value, int weight);	// 0x9ba310
	T &pick();	// 0x9ba470
};
extern vector<int> bv14_recs_d25f50,bv14_groupOf_cefce8,bv14_tiers_d02cd0;
template<class T> int BV14_randomIndex(vector<T>&);
struct BV14ItemType;extern vector<BV14ItemType*> bv14_itemTypes_d2d1c4;
bool bv14_remove_9db000(vector<int>&,int);
template<class T> void BV14_appendVector(vector<T>&,vector<T>&);
extern vector<BV14Area> bv14_boxes_d2b274;
extern BV14PropDef *bv14_propType_cefbd0,*bv14_propType_cefbe0;
int bv14_distance_40a3f0(const BV14Point&,const BV14Point&);
struct BV14Record {char pad[0x9c];int size;};extern vector<BV14Record*> bv14_records_d25de0;
template<class T> bool BV14_findByName(vector<T*>&,const string&,T*&);
BV14Point bv14_randomPoint(vector<BV14Point>&);
struct BV14Overmind {int spawnPatrolParty(BV14HE,bool,BV14Rect*,vector<BV14Point>*,BV14Point*,int,vector<BV14HE>*,int,bool);};extern BV14Overmind bv14_overmind_cf6428;
extern int bv14_difficulty_cf4718;
bool terrainFlagB_448b80(const BV14Point&);
extern BV14HE bv14_hub_cf6454;
struct BV14LocInfo {bool inRange();};
struct BV14HLoc {int id;BV14LocInfo *operator->() const;};
struct BV14Exit {BV14Point pos;BV14HLoc info;};
struct BV14RoomRect {int x,y,w,h;BV14Point center();};
struct BV14Room {int type;BV14RoomRect rect;};extern vector<BV14Room> bv14_rooms_cf13e8;
void logError(string location,string message);
struct BV14View {BV14View();~BV14View();void init(int,int,int);void resizeView(int,int,int,int,bool);void fillGrid(int);int &operator()(const BV14Point&);char pad[0x2c];};
void sweepGetSurroundingCells(const BV14Point&,vector<BV14Point>&);
struct BS {
 BV14HI unknown6c5400(BV14ItemType*,const BV14Point&);
 void unknown7430a0(int,int);
 BV14Record *selectRobotOfClass(int,int,bool,bool);
 BV14HE placeEntity(BV14Record*,const BV14Point&,int,bool,int,int,bool);
 bool unknown6c65a0(BV14HE,const string&,bool);
 void factory_6ead20();
 char pad[0x10];vector<BV14Exit*> exits;char pad20[0x4c-0x20];vector<BV14HM> machines;char pad5c[0x524-0x5c];vector<int> f524;char pad534[0x8cc-0x534];
 BV14Area base;vector<vector<BV14Point> > rings;vector<vector<int> > f8ec;char pad8fc[0x904-0x8fc];vector<BV14Point> f904;char pad914[0x924-0x914];BV14Area a924,a934,a944,a954;char pad964[0x96c-0x964];vector<BV14Area> targets;vector<BV14Area> f97c;
};
void BS::factory_6ead20() {
 a924.set(0xa9,0xae,0xaa,0xb3);
 a934.set(0,0x7d,0x63,0xe0);
 a944.set(0x7f,0x93,0xa6,0xb6);
 a954.set(0,0x7d,0xc7,0xe0);
 machines[10]->unknown458460();
 for(unsigned i=0;i<bv14_specials_cf124c.size();i++)
  if(bv14_specials_cf124c[i].id==bv14_id_d2ed8c) {
   base.set_40b360(bv14_specials_cf124c[i].pos,0x7a,0x7d);
   break;
  }
 for(int x=0x6b;x<0xc0;x++)
  if((*bv14_cells_cfd44c.at(x,0x7c))->terrain()==TERRAIN_CAVE_WALL)
   (*bv14_cells_cfd44c.at(x,0x7c))->unknown66a050(caveinThirdTerrain->id,2,false);
 vector<vector<BV14Area> > parts;
#define G parts.push_back(vector<BV14Area>());
#define B(a,b,door,d) parts.back().push_back(BV14Area(a,b,door,d));
 G B(4,88,7,98) G B(14,55,15,59) B(14,62,15,64) B(16,51,25,52) G B(42,66,43,74) B(51,56,52,64) G B(61,54,62,61) B(65,51,74,52) G B(109,89,114,90) B(105,75,115,76) G B(106,65,115,66) B(105,54,109,55) B(112,54,116,55) G B(110,44,115,45) B(103,32,109,34) G B(60,7,62,9) B(70,7,72,9) B(60,17,62,19) B(70,17,72,19) G B(109,8,112,11)
#undef G
#undef B
 for(unsigned g=0;g<parts.size();g++)
  for(unsigned b=0;b<parts[g].size();b++)
   parts[g][b].offsetBy(base);
 vector<unsigned> edges;
 for(int k=0;k<=7;k++)
  edges.push_back((unsigned int)k);
 BV14_shuffle(edges);
 edges.push_back(8);
 OpR5h_WL<int> ranks[5];
 ranks[1].add(5,0x19);
 ranks[1].add(4,0x32);
 ranks[1].add(3,0x19);
 ranks[2].add(4,0x19);
 ranks[2].add(3,0x32);
 ranks[2].add(2,0x19);
 ranks[3].add(3,0x19);
 ranks[3].add(2,0x32);
 ranks[3].add(1,0x19);
 ranks[4].add(0,0x32);
 ranks[4].add(1,0x19);
 ranks[4].add(2,0x19);
 for(unsigned g2=0;g2<parts.size();g2++) {
  int kind=edges[g2];
  for(unsigned rr=0;rr<bv14_recs_d25f50.size();rr++) {
   if(bv14_groupOf_cefce8[rr]==kind) {
    int count=ranks[bv14_tiers_d02cd0[rr]].pick();
    BV14Point p;
    for(int c=count;c>0;c--) {
     for(int t=0;t<100;t++) {
      p=parts[g2][BV14_randomIndex(parts[g2])].randomPoint();
      if((*bv14_cells_cfd44c.atPoint(p))->getItem().isNull()) {
       unknown6c5400(bv14_itemTypes_d2d1c4[bv14_recs_d25f50[rr]],p);
       break;
      }
     }
    }
   }
  }
 }
 for(int x=base.p1.x;x<=base.p2.x;x++)
  for(int y=base.p1.y;y<=base.p2.y;y++)
   if((*bv14_cells_cfd44c.at(x,y))->getItem().isValid()&&(*bv14_cells_cfd44c.at(x,y))->getItem()->name457860()!="Crosscalibrator")
    bv14_remove_9db000(f524,(*bv14_cells_cfd44c.at(x,y))->getItem()->getNestedField());
 BV14_shuffle(f524);
 int count=(int)(f524.size()*0.75);
 f524.erase(f524.begin()+count,f524.end());
 for(unsigned g3=0;g3<parts.size();g3++)
  BV14_appendVector(bv14_boxes_d2b274,parts[g3]);
 unknown7430a0(2,1);
 BV14Area a(3,5,0x75,0x67);
 a.p1+=base.p1;
 a.p2+=base.p1;
 vector<BV14HE> elements;
 vector<BV14Point> choices;
 for(int x=a.p1.x;x<=a.p2.x;x++)
  for(int y=a.p1.y;y<=a.p2.y;y++) {
   if((*bv14_cells_cfd44c.at(x,y))->getEntity().isValid()&&(*bv14_cells_cfd44c.at(x,y))->getEntity()->getFaction()==0x14) {
    elements.push_back((*bv14_cells_cfd44c.at(x,y))->getEntity());
    choices.push_back(BV14Point(x,y));
   }
   if((*bv14_cells_cfd44c.at(x,y))->getProp().isValid()&&(*bv14_cells_cfd44c.at(x,y))->getProp()->def()==bv14_propType_cefbd0&&(*bv14_cells_cfd44c.at(x,y))->getProp()->unknown45c800(0x93)) {
    if(!choices.empty()&&choices.back().test_409cf0(x,y))
     choices.push_back(BV14Point(x,y));
    (*bv14_cells_cfd44c.at(x,y))->getProp()->unknown45ce10(1,0,1,BV14HE());
   }
  }
 for(unsigned i=0;i<elements.size();i++) {
  if(rng.chance(33))
   continue;
  elements[i]->setAI(new BV14EntityAI(elements[i],2,0xe));
  vector<BV14Point> nearby;
  for(unsigned j=0;j<choices.size();j++)
   if(bv14_distance_40a3f0(elements[i]->getPosition(),choices[j])<=10)
    nearby.push_back(choices[j]);
  elements[i]->getAI()->unknown4593d0(nearby);
 }
 if(rng.chance(25)) {
  vector<BV14Point> posts;
  posts.push_back(BV14Point(0xb,0x54));
  posts.push_back(BV14Point(0x41,0x54));
  posts.push_back(BV14Point(0x41,0x5f));
  posts.push_back(BV14Point(0x55,0x5f));
  posts.push_back(BV14Point(0x55,0x1f));
  posts.push_back(BV14Point(0x42,0x1f));
  posts.push_back(BV14Point(0x42,0xe));
  for(unsigned k=0;k<posts.size();k++)
   posts[k]+=base.p1;
  BV14_shufflePts(posts);
  BV14Record *vs;
  BV14_findByName(bv14_records_d25de0,"V-Series",vs);
  BV14Point at2;
  for(int t=0;t<10;t++) {
   at2=bv14_randomPoint(posts);
   if((*bv14_cells_cfd44c.atPoint(at2))->canPlaceEntity(vs->size)) {
    BV14HE v=placeEntity(vs,at2,3,true,2,0xe,false);
    if(v.isValid()) {
     v->removeEffectsA(0);
     unknown6c65a0(v,"FRG_VSeries_Unstable2",false);
     v->getAI()->unknown4593d0(posts);
     vs=selectRobotOfClass(1,0x14,false,true);
     if(vs) {
      BV14HE o=placeEntity(vs,at2,3,true,2,0xe,false);
      if(o.isValid()) {
       o->getAI()->setFollowEntity(v,0);
       o->getAI()->unknown4593d0(posts);
      }
     }
    }
    break;
   }
  }
 }
 BV14Area root(0x71,0x83,0xa3,0xb5);
 BV14Record *rec=selectRobotOfClass(1,8,false,false);
 if(rec)
  for(int q=0;q<4;q++) {
   bool found=false;
   BV14Point pt;
   for(int t=0;t<100;t++) {
    pt=root.randomPoint();
    if((*bv14_cells_cfd44c.atPoint(pt))->canPlaceEntity(1)) {
     found=true;
     break;
    }
   }
   if(found) {
    BV14HE g=placeEntity(rec,pt,4,true,0x22,0xe,false);
    if(g.isValid())
     g->getAI()->unknown459410(root);
   }
  }
 BV14Rect tag(0,0x7d,0xc8,0x64);
 for(int p=0;p<4;p++)
  bv14_overmind_cf6428.spawnPatrolParty(BV14HE(),true,&tag,0,0,0,0,8,false);
 if(bv14_difficulty_cf4718!=2) {
  BV14_findByName(bv14_records_d25de0,"Overlord",rec);
  if(rec) {
   BV14Point first;
   vector<BV14Point> hits;
   for(int t=0;t<100;t++) {
    first=root.randomPoint();
    if((*bv14_cells_cfd44c.atPoint(first))->canPlaceEntity(1)) {
     hits.push_back(first);
     break;
    }
   }
   BV14Area min(0,0x7d,0x64,0xe0);
   for(int u=0;u<4;u++)
    for(int w=0;w<200;w++) {
     BV14Point rp=min.randomPoint();
     if((*bv14_cells_cfd44c.atPoint(rp))->canPlaceEntity(1)&&!terrainFlagB_448b80(rp)) {
      if(w<100) {
       for(unsigned m=0;m<hits.size();m++)
        if(bv14_distance_40a3f0(rp,hits[m])<15)
         goto nextW;
      }
      hits.push_back(rp);
      break;
     }
nextW:;
    }
   if(!hits.empty()) {
    BV14HE ov=placeEntity(rec,hits.front(),3,true,2,0xe,false);
    BV14_shufflePts(hits);
    ov->getAI()->unknown4593d0(hits);
    ov->getAI()->setField451930(0x32);
    ov->getAI()->setUnknown451400(1);
   }
  }
 }
 vector<BV14HE> &self=machines[3]->members416f40();
 for(unsigned i=0;i<self.size();i++)
  if(self[i]->getFaction()==0x21) {
   bv14_hub_cf6454=self[i];
   break;
  }
 const int bonus=0xf;
 BV14Point door;
 BV14Area room;
 BV14Area total2=bv14_cells_cfd44c.getArea();
 BV14Area center(0x6b,0x7c,0xb7,0xd0);
 int idx;
 for(int pass=0;pass<10;pass++) {
  if(pass==0&&bv14_difficulty_cf4718!=2) {
   for(unsigned s=0;s<exits.size();s++) {
    if(exits[s]->info->inRange()) {
     do
      door.set_40a060(exits[s]->pos,rng.rangeInt(-1.0f,1.0f),rng.rangeInt(-1.0f,1.0f));
     while(door.equals_409b90(exits[s]->pos));
     room.set(door.x-1,door.y-1,door.x+1,door.y+1);
     targets.push_back(room);
    }
   }
   continue;
  }
  {
   for(int tries=0;;tries++) {
    if(tries>2000)
     logError("FRG","excessive target searching");
    do
     idx=BV14_randomIndex(bv14_rooms_cf13e8);
    while(bv14_rooms_cf13e8[idx].rect.x==-1);
    for(int t=0;t<50;t++) {
     door=bv14_rooms_cf13e8[idx].rect.center();
     door.offset_40a2a0(rng.rangeInt(-10.0f,10.0f),rng.rangeInt(-10.0f,10.0f));
     if(bv14_cells_cfd44c.contains(door)&&(*bv14_cells_cfd44c.atPoint(door))->field4550b0()) {
      room.set(door.x-1,door.y-1,door.x+1,door.y+1);
      room.clip(total2.p1,total2.p2);
      if(center.contains(room.center())||base.contains(room.center()))
       goto nextT;
      if(tries<50) {
       for(unsigned m=0;m<targets.size();m++)
        if(bv14_distance_40a3f0(room.center(),targets[m].center())<bonus)
         goto nextT;
      }
      targets.push_back(room);
      goto nextPass;
     }
nextT:;
    }
   }
  }
nextPass:;
 }
 f97c=targets;
 f904.push_back(BV14Point(0x8a,0x8e));
 f904.push_back(BV14Point(0x7c,0x9c));
 f904.push_back(BV14Point(0x98,0x9c));
 f904.push_back(BV14Point(0x8a,0xaa));
 BV14View cols;
 cols.init(bv14_cells_cfd44c.getWidth(),bv14_cells_cfd44c.getHeight(),1);
 cols.resizeView(0x7c,0x8e,0x1d,0x1d,false);
 cols.fillGrid(0);
 BV14Point dest(0x8a,0x9c);
 vector<BV14Point> other(1,dest);
 cols(dest)=1;
 rings.push_back(other);
 vector<BV14Point> adj;
 vector<BV14Point> *prev;
 while(1) {
  other.clear();
  prev=&rings.back();
  for(unsigned i=0;i<prev->size();i++) {
   adj.clear();
   sweepGetSurroundingCells(prev->at(i),adj);
   for(unsigned j=0;j<adj.size();j++)
    if(cols(adj[j])!=1) {
     cols(adj[j])=1;
     if((*bv14_cells_cfd44c.atPoint(adj[j]))->getProp().isValid()&&(*bv14_cells_cfd44c.atPoint(adj[j]))->getProp()->def()==bv14_propType_cefbe0)
      other.push_back(adj[j]);
    }
  }
  if(!other.empty())
   rings.push_back(other);
  else
   break;
 }
 f8ec.assign(rings.size(),vector<int>());
}
