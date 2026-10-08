// NOTE: placeholder names and partial layouts; machine operation completion 0x65a260 (fabricator output,
// repair station, scrap engine), called from Machine49::unknown65c8a0.
#include <string>
#include <vector>
using namespace std;
struct BV13Entity;struct BV13AI;struct BV13Item;struct BV13Prop;
struct BV13Spot {int x,y;};
struct BV13Point {int x,y;BV13Point();BV13Point(const BV13Point&);BV13Point(const BV13Spot&);BV13Point &operator=(const BV13Point&);};
struct BV13HE {int id;BV13HE();bool isValid() const;bool isNull() const;BV13Entity *operator->() const;};
struct BV13HI {int id;bool isValid() const;BV13Item *operator->() const;BV13Item *get() const;BV13Item *getNT() const throw();};
struct BV13Trap;
struct BV13Trigger {BV13Trap *trap;int count;BV13Trigger(BV13Trap*,int);};
BV13Trigger::BV13Trigger(BV13Trap *trap_,int count_) {trap=trap_;count=count_;}
struct BV13TypeRef {int id;};
struct BV13Item {void unknown57a0f0(const BV13Point&,int,int);void unknown458390(int);void addEffect(BV13Trigger*);void unknown57bff0(int,int);const BV13Point &unknown575920();BV13TypeRef *typeRef();string name571db0(int,int);string unknown457990();int unknown457ca0();bool unknown457d10();bool unknown457db0();int unknown457c80();int getCached();int unknown457c80NT() throw();int getCachedNT() throw();void unknown458340();void unknown5797c0();void unknown458460();void unknown579c80();};
struct BV13Entity {BV13AI *getAI();void unknown45b2a0();const string &name416f40();vector<BV13Point> *unknown45d1a0();};
struct BV13AI {void unknown4593b0(const BV13Point&);void setFollowEntity(BV13HE,int);};
struct BV13Link {char pad[0x80];int f80,f84,f88,f8c;};
struct BV13Prop {const BV13Point &position();int id44ab40();void unknown45ce10(int,int,int,BV13HE);BV13Link *link45cb30();};
struct BV13HP {int id;bool isValid() const;BV13Prop *operator->() const;};
struct BV13Cell {BV13HP getProp();void unknown66b690(int,int);};
struct BV13Grid {BV13Cell **atPoint(const BV13Point&);};extern BV13Grid bv13_cells_cfd44c;
struct BV13ItemType {int id;char pad4[0x24-4];string name;char pad40[0x50-0x40];int rating;char pad54[0x204-0x54];int count;};
struct BV13Record {char pad[0x68];int value;char pad6c[0x9c-0x6c];int size;char pada0[0xe4-0xa0];int count;char pade8[0x1ac-0xe8];string name;};
struct BV13MapView {void removeMarker(const BV13Point&);void unknown49ada0(int);};extern BV13MapView *bv13_mapView_cec054;
struct BV13World {bool unknown71bde0(const BV13Point&,BV13Point&);BV13Record *unknown6c5600(int,int,bool,bool);void unknown7142a0(vector<BV13Spot>&);void unknown714340(vector<BV13Spot>&);BV13HE placeEntity(BV13Record*,const BV13Point&,int,bool,int,int,bool);vector<vector<BV13HP> > &unknown463be0();bool isVisible(const BV13Point&);void opw3_unknown729eb0(const BV13Point&,const string&,int,int);void opw3_unknown72a1e0(const BV13Point&,int);void opw3_unknown726c30(BV13HP,int);bool findPlaceableNear(const BV13Point&,BV13Point&,int);BV13HE getPlayer();bool unknown6c65a0(BV13HE,const string&,bool);};
extern BV13World *bv13_world_cefc4c;
struct BV13Factory {BV13HI createD(BV13ItemType*);};extern BV13Factory *bv13_factory_cefaa8;
bool bv13_show_5111e0(int,const string*,const string*,int,BV13HE,BV13HE,const BV13Point*,bool);
struct BV13Bubble {void unknown8758d0(bool);};extern BV13Bubble *bv13_bubble_cec058;
struct BV13Log {void scrollToEnd();};extern BV13Log *bv13_log_cec0b4;
extern vector<BV13Trap*> bv13_traps_d2f0f8;
struct BV13PlayerData {void unknown77ffb0(int,int);void unknown77fbc0(int);};extern BV13PlayerData bv13_playerData_cf45d8;
struct BV13Stats {vector<int> *values;bool add4729d0(unsigned,int,string,int);};extern BV13Stats bv13_stats_d2c658;
extern const char bv13_empty_b954b9[],bv13_empty_b954ba[],bv13_empty_b954bb[],bv13_empty_b954c5[],bv13_empty_b954c6[],bv13_empty_b954c7[];
template<class T> void BV13_eraseStep(vector<T>&,int&);
BV13Spot &bv13_randomRec(vector<BV13Spot>&);
void bv13_mark_454260(const BV13Point&,int);
string bv13_pointToString(const BV13Point&);
string intToString(int);
bool bv13_contains(vector<BV13HP>&,BV13HP);
void sweepGetSurroundingCells(const BV13Point&,vector<BV13Point>&);
extern vector<string> bv13_names_cf4c38,bv13_names_cf4c88;extern vector<int> bv13_counts_cf4c48,bv13_turns_cf4c58,bv13_f_cf4c68,bv13_f_cf4c78,bv13_v_cf4c98,bv13_v_cf4ca8,bv13_v_cf4cb8,bv13_v_cf4cc8;
struct BV13GameData {int unknown46f530();};extern BV13GameData bv13_gameData_d1e860;
extern int bv13_time_caed20;extern int bv13_none_caf160,bv13_none_caf164;
void bv13_logPhrase_5141b0(int,const string*,const string*,const string*,BV13HE,const BV13Point*);
int bv13_clamp_9cdc80(int,int,int);
extern bool bv13_flag_d28d30;extern int bv13_tableA_ba6a28[],bv13_tableB_ba69e0[];extern int bv13_d1f32c;
int bv13_randomOf(int*,unsigned);
extern int bv13_counter_cf4d58;
struct BV13Effect;bool bv13_lookup2(const string&,BV13Effect*&);
struct BV13Fx {void init_503b20();};
struct BV13ObjB {BV13Fx *unknown508610(BV13ObjB*,BV13Effect*,const BV13Point&,void*,int,int,int,int,int);};extern BV13ObjB *bv13_objB_cefc50;extern int bv13_d2e20c;
#define BV13_LOG(...) do { if (bv13_show_5111e0(__VA_ARGS__)) bv13_bubble_cec058->unknown8758d0(true); bv13_log_cec0b4->scrollToEnd(); } while (0)
struct BV13Operation {
 BV13HP prop;int type;char pad8[4];BV13ItemType *product;BV13Record *robot;bool f14;bool f15;char pad16[2];vector<BV13HI> items;char pad28[0x44-0x28];bool hacked;bool f45;
 bool complete_65a260(bool flag);
};
bool BV13Operation::complete_65a260(bool flag) {
 switch(type) {
 case 0x43: {
  BV13Point pos;
  if(flag) {
   bv13_mapView_cec054->removeMarker(prop->position());
   int built=0;
   if(product) {
    int count=product->count;
    if(!hacked)
     count*=2;
    vector<BV13HI> made;
    for(int i=0;i<count;i++) {
     if(bv13_world_cefc4c->unknown71bde0(prop->position(),pos)) {
      BV13HI it=bv13_factory_cefaa8->createD(product);
      if(it.isValid()) {
       built++;
       it->unknown57a0f0(pos,0,0);
       it->unknown458390(0);
       made.push_back(it);
       BV13_LOG(0x1c1,&product->name,0,0,BV13HE(),BV13HE(),&prop->position(),false);
       if(hacked) {
        it->addEffect(new BV13Trigger(bv13_traps_d2f0f8[0x68],1));
        bv13_playerData_cf45d8.unknown77ffb0(product->id,0);
        bv13_stats_d2c658.add4729d0(0x302,1,bv13_empty_b954b9,-1);
        bv13_stats_d2c658.add4729d0(0x305,product->rating,bv13_empty_b954ba,-1);
        bv13_playerData_cf45d8.unknown77fbc0(0x4c);
        if((*bv13_stats_d2c658.values)[0x302]==10)
         bv13_playerData_cf45d8.unknown77fbc0(0xb8);
       }
       if(f45)
        it->unknown57bff0(0x60,1);
      }
     }
    }
    for(int j=0;j<made.size();j++)
     if(!made[j].get())
      BV13_eraseStep(made,j);
    if(!hacked&&!made.empty()) {
     BV13Record *rec=bv13_world_cefc4c->unknown6c5600(1,4,false,true);
     if(rec) {
      vector<BV13Spot> spots;
      bv13_world_cefc4c->unknown7142a0(spots);
      bv13_world_cefc4c->unknown714340(spots);
      if(!spots.empty()) {
       BV13Point p(bv13_randomRec(spots));
       BV13HE first=bv13_world_cefc4c->placeEntity(rec,p,3,false,0x12,0xe,false);
       if(first.isValid())
        for(unsigned k=0;k<made.size();k++)
         first->getAI()->unknown4593b0(made[k]->unknown575920());
      }
     }
    }
    if(!made.empty()) {
     bv13_mark_454260(prop->position(),0x86);
     vector<vector<BV13HP> > &lists=bv13_world_cefc4c->unknown463be0();
     if(!lists[7].empty()) {
      bv13_playerData_cf45d8.unknown77ffb0(made.back()->typeRef()->id,0);
      string msg="Completed "+made[0]->name571db0(0,0)+" at "+bv13_pointToString(prop->position());
      BV13_LOG(0x1d6,&string("FABRICATOR"),&msg,0,BV13HE(),BV13HE(),0,false);
      if(!bv13_world_cefc4c->isVisible(made.back()->unknown575920())) {
       bv13_world_cefc4c->opw3_unknown729eb0(made.back()->unknown575920(),made.back()->name571db0(0,0),1,1);
       bv13_world_cefc4c->opw3_unknown72a1e0(prop->position(),1);
      }
      bv13_world_cefc4c->opw3_unknown726c30(prop,1);
     }
    }
   }
   else {
    vector<BV13HE> bots;
    bool known=bv13_contains(bv13_world_cefc4c->unknown463be0()[9],prop);
    for(int i=0;i<robot->count;i++) {
     if(bv13_world_cefc4c->findPlaceableNear(prop->position(),pos,robot->size)) {
      BV13HE e;
      if(hacked) {
       BV13HE r=bv13_world_cefc4c->placeEntity(robot,pos,1,false,0x22,0xe,false);
       if(r.isValid()) {
        built++;
        bots.push_back(r);
        r->unknown45b2a0();
        BV13_LOG(0x1c1,&robot->name,0,0,BV13HE(),BV13HE(),&prop->position(),false);
        r->getAI()->setFollowEntity(bv13_world_cefc4c->getPlayer(),0);
        bv13_stats_d2c658.add4729d0(0x2fd,1,bv13_empty_b954bb,-1);
        bv13_stats_d2c658.add4729d0(0x300,robot->value,bv13_empty_b954c5,-1);
        bv13_playerData_cf45d8.unknown77fbc0(0x4b);
        if((*bv13_stats_d2c658.values)[0x2fd]==10)
         bv13_playerData_cf45d8.unknown77fbc0(0xc6);
        if(f45)
         bv13_world_cefc4c->unknown6c65a0(r,"Cypher_Fab_Ent_Explode",false);
       }
      }
      else {
       known=bv13_contains(bv13_world_cefc4c->unknown463be0()[9],prop);
       BV13HE e2=known?bv13_world_cefc4c->placeEntity(robot,pos,2,false,0x22,0xe,false):bv13_world_cefc4c->placeEntity(robot,pos,3,false,0x17,0xe,false);
       if(e2.isValid()) {
        built++;
        bots.push_back(e2);
        BV13_LOG((known?1:0)+0x1c1,&robot->name,0,0,BV13HE(),BV13HE(),&prop->position(),false);
        if(known) {
         e2->getAI()->setFollowEntity(bv13_world_cefc4c->getPlayer(),0);
         if(i==0)
          bv13_world_cefc4c->unknown6c65a0(e2,"Liberate_Dialogue_Hello",false);
         bv13_world_cefc4c->unknown6c65a0(e2,"Liberate_Leave_Check",false);
        }
       }
      }
     }
    }
    if(!bots.empty()) {
     bv13_mark_454260(prop->position(),0x86);
     if(!bv13_world_cefc4c->unknown463be0()[7].empty()) {
      string msg2("Completed ");
      if(known&&!hacked)
       msg2+="liberated ";
      msg2+=bots[0]->name416f40()+" at "+bv13_pointToString(prop->position());
      BV13_LOG(0x1d6,&string("FABRICATOR"),&msg2,0,BV13HE(),BV13HE(),0,false);
      bv13_world_cefc4c->opw3_unknown726c30(prop,1);
     }
    }
   }
   if(built&&hacked) {
    bv13_names_cf4c38.push_back(product?product->name:robot->name);
    bv13_counts_cf4c48.push_back(built);
    bv13_turns_cf4c58.push_back(bv13_gameData_d1e860.unknown46f530());
    bv13_f_cf4c68.push_back(f14?1:0);
    bv13_f_cf4c78.push_back(f15?1:0);
    if(bv13_world_cefc4c->isVisible(prop->position())||!bv13_world_cefc4c->unknown463be0()[7].empty()) {
     bv13_mapView_cec054->unknown49ada0(bv13_time_caed20+2000);
     do {bv13_logPhrase_5141b0(0x23,&(product?product->name:robot->name),&intToString(built),0,BV13HE(),&prop->position());} while(0);
    }
   }
   prop->link45cb30()->f84=bv13_none_caf164;
   prop->link45cb30()->f80=bv13_none_caf164;
   prop->link45cb30()->f8c=bv13_none_caf160;
   prop->link45cb30()->f88=bv13_none_caf160;
  }
  break;
 }
 case 0x4d: {
  BV13Point pos2;
  BV13_LOG(0x1c7,&items.front()->name571db0(0,0),0,0,BV13HE(),BV13HE(),&prop->position(),false);
  if(hacked) {
   bv13_stats_d2c658.add4729d0(0x307,1,bv13_empty_b954c6,-1);
   bv13_playerData_cf45d8.unknown77fbc0(0x4e);
   if((*bv13_stats_d2c658.values)[0x307]==10)
    bv13_playerData_cf45d8.unknown77fbc0(0xb9);
   if(bv13_world_cefc4c->isVisible(prop->position())) {
    bv13_mapView_cec054->unknown49ada0(bv13_time_caed20+2000);
    do {bv13_logPhrase_5141b0(0x25,&items.front()->name571db0(0,0),0,0,BV13HE(),&prop->position());} while(0);
   }
  }
  bv13_mapView_cec054->removeMarker(prop->position());
  if(flag) {
   bv13_names_cf4c88.push_back(items.front()->unknown457990());
   bv13_v_cf4c98.push_back(bv13_clamp_9cdc80(1,items.front()->unknown457ca0(),0x63));
   bv13_v_cf4ca8.push_back(bv13_gameData_d1e860.unknown46f530());
   bv13_v_cf4cb8.push_back(items.front()->unknown457d10()?1:0);
   bv13_v_cf4cc8.push_back(items.front()->unknown457db0()?1:0);
   bv13_stats_d2c658.add4729d0(0x178,items.front().getNT()->unknown457c80NT()-items.front().getNT()->getCachedNT(),bv13_empty_b954c7,-1);
   items.front()->unknown458340();
   items.front()->unknown5797c0();
   items.front()->unknown458460();
   if(f45)
    items.front()->unknown57bff0(0x60,1);
  }
  if(bv13_world_cefc4c->unknown71bde0(prop->position(),pos2)) {
   items.front()->unknown57a0f0(pos2,0,0);
   items.front()->unknown579c80();
   items.clear();
  }
  break;
 }
 case 0x5c:
 case 0x5d: {
  BV13HP it=prop;
  BV13Point branch(it->position());
  bool visible=type==0x5c;
  vector<BV13Point> cols;
  sweepGetSurroundingCells(branch,cols);
  for(unsigned i=0;i<cols.size();i++)
   if((*bv13_cells_cfd44c.atPoint(cols[i]))->getProp().isValid()&&(*bv13_cells_cfd44c.atPoint(cols[i]))->getProp()->id44ab40()==it->id44ab40()) {
    (*bv13_cells_cfd44c.atPoint(cols[i]))->getProp()->unknown45ce10(1,0,1,BV13HE());
    (*bv13_cells_cfd44c.atPoint(cols[i]))->unknown66b690(bv13_randomOf(bv13_flag_d28d30?bv13_tableA_ba6a28:bv13_tableB_ba69e0,0x11),bv13_d1f32c);
   }
  (*bv13_cells_cfd44c.atPoint(branch))->getProp()->unknown45ce10(1,0,1,BV13HE());
  (*bv13_cells_cfd44c.atPoint(branch))->unknown66b690(bv13_randomOf(bv13_flag_d28d30?bv13_tableA_ba6a28:bv13_tableB_ba69e0,0x11),bv13_d1f32c);
  BV13Record *elem=bv13_world_cefc4c->unknown6c5600(3,visible?0x2e:0x2f,false,true);
  int count=visible?5:1;
  vector<BV13HE> hits;
  BV13HE v;
  for(int k=0;k<count;k++) {
   v=bv13_world_cefc4c->placeEntity(elem,branch,1,false,0x22,0xe,false);
   if(v.isNull()) {}
   else {
    v->getAI()->setFollowEntity(bv13_world_cefc4c->getPlayer(),0);
    hits.push_back(v);
   }
  }
  if(!hits.empty()) {
   BV13_LOG(0x2b0,&string(visible?"Scrapoid":"Scraphulk"),0,0,BV13HE(),BV13HE(),&branch,false);
   if(bv13_world_cefc4c->isVisible(branch)) {
    bv13_mapView_cec054->unknown49ada0(bv13_time_caed20+2000);
    do {bv13_logPhrase_5141b0(0x27,&string(visible?"Scrapoid":"Scraphulk"),0,0,BV13HE(),&branch);} while(0);
   }
   bv13_counter_cf4d58++;
   if(bv13_counter_cf4d58==5)
    bv13_playerData_cf45d8.unknown77fbc0(0xcf);
   BV13Effect *fx;
   if(bv13_lookup2("Fedlink_Dispatch",fx))
    for(unsigned a=0;a<hits.size();a++) {
     vector<BV13Point> *cells=hits[a]->unknown45d1a0();
     for(unsigned c=0;c<cells->size();c++)
      bv13_objB_cefc50->unknown508610(bv13_objB_cefc50,fx,(*cells)[c],&bv13_d2e20c,0,0,0,9,0)->init_503b20();
    }
   bv13_mark_454260(branch,0xb8);
  }
  return true;
 }
 }
 return false;
}
