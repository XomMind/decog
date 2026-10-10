// NOTE: placeholder names and partial layouts; BS::placeMachine (0x6c70a0): stamps a machine's ascii image onto
// the map as props, creates its spawner object, fills it with parts/loot, and links exits for access machines.
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;
struct PM6Glyph;struct PM6Placed;struct PM6ItemObj;struct PM6PropObj;struct PM6Loc;struct PM6PropDef;struct PM6Terrain;
struct PM6Point {int x,y;PM6Point(int);PM6Point(int,int);PM6Point(const PM6Point&) throw();PM6Point &operator=(const PM6Point&);PM6Point &operator+=(const PM6Point&);void rotateInto_40a3b0(int);bool ne_409bd0(const PM6Point&) const;};
struct PM6Range {int a,b;int randomInRange_40c130() throw();};
struct PM6HP {int id;PM6HP() throw();bool isNull() const;bool isValid() const;PM6PropObj *operator->() const;};
struct PM6HI {int id;PM6ItemObj *operator->() const;};
struct PM6HL {int id;PM6HL() throw();bool isNull() const;PM6Loc *operator->() const;};
struct PM6HM {int id;};
struct PM6Loc {int pad0;int type;int f8;vector<PM6HL> events;char pad1c[0x2f-0x1c];bool linked;vector<int> pending;void init(int,int,int,int);bool inRange();int getDepthIndex();};
struct PM6Layer {int getWidth();int getHeight();PM6Glyph *at(int,int);};
struct PM6Glyph {int ch();};
struct PM6Image {vector<PM6Layer*> layers;PM6Image(const PM6Image&);~PM6Image();void rotate_437ee0(int);};
struct PM6MachineDef {int pad0;string name;char pad20[0x3c-0x20];PM6Image image;PM6Point anchor;char pad54[0xf8-0x54];int type;char padfc[0x10c-0xfc];int tiers[3];};
extern vector<PM6MachineDef*> pm6_machines_cf35b0;
struct PM6ItemDef {int id;char pad4[0x44-4];int rating;};
struct PM6Blueprint {char pad0[0x2c];int minDepth;char pad30[0x38-0x30];int minTier;bool test_45b910(int);};
extern vector<PM6Blueprint*> pm6_blueprints_d35b58;
struct PM6RecDef {int id;char pad4[0x68-4];int level;char pad6c[0x170-0x6c];string label;char pad18c[0x1ac-0x18c];string group;};
extern vector<PM6RecDef*> pm6_records_d25de0;
struct PM6Spawn {int id;char pad4[0x64-4];int percent;};
struct PM6PropDef {char pad0[0x8c];int linked;};
struct PM6PropObj {void unknown45cc50(const PM6Point&);void unknown65e8a0(PM6Glyph*);void setMachine_44fc60(PM6Placed*);void setIndex_451400(int);PM6PropDef *def();};
struct PM6ItemObj {int integrity();void setIntegrity(int);void unknown57a520(PM6HP,int);void setScaled_579880(int);};
struct PM6Terrain {int id;};
extern PM6Terrain *caveinThirdTerrain;
struct PM6Cell {bool place45df50(PM6HM);PM6HP getProp() throw();bool getField_4550b0();PM6Terrain *terrain();};
struct PM6Grid {PM6Cell **at(int,int);PM6Cell **atPoint(const PM6Point&) throw();};extern PM6Grid pm6_cells_cfd44c;
struct PM6IntGrid {int *at(int,int);};extern PM6IntGrid pm6_grid_cf447c;
struct PM6Factory {PM6HM createE(PM6MachineDef*);PM6HI createD(PM6ItemDef*);PM6HL createB();};extern PM6Factory *pm6_factory_cefaa8;
struct PM6Part {int id;int value;int extra;PM6Part(int,int);};
PM6Part::PM6Part(int id_,int value_) {id=id_;value=value_;extra=0;}
struct PM6Placed {char pad0[0xc];int level;char pad10[8];vector<PM6Part*> parts;char pad28[0x80-0x28];int item80;int item84;int pick88;int pick8c;PM6Placed(PM6HP,int,int,int,bool);void add45bbe0(PM6Part*);};
struct PM6Shot {int x,y;int id;int amount;PM6Shot(PM6Point,int,int);};
PM6Shot::PM6Shot(PM6Point p,int id_,int amount_) {x=p.x;y=p.y;id=id_;amount=amount_;}
struct PM6Marker {int doorX,doorY;PM6HL loc;int kind;int pad10;PM6HP prop;PM6HP other;char pad1c[0x60-0x1c];PM6Marker(const PM6Point&,PM6HL,int,PM6HP,PM6HP);};
PM6Marker::PM6Marker(const PM6Point &door_,PM6HL loc_,int kind_,PM6HP prop_,PM6HP other_) {doorX=door_.x;doorY=door_.y;loc=loc_;kind=kind_;prop=prop_;other=other_;}
struct PM6Location {int id;PM6Loc *operator->() const;};extern PM6HL pm6_location_d1e888;
struct PM6GameData {int getDepthIndex();int unknown789250(int) throw();};extern PM6GameData pm6_gameData_d1e860;
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
	bool pick(T *out);
};
extern OpR5h_WL<PM6Spawn*> pm6_spawns_d2ae08;
extern OpR5h_WL<PM6ItemDef*> pm6_loot_d31700;
extern int pm6_caf130,pm6_cf4744,pm6_caf160,pm6_cf462c,pm6_cf4718,pm6_cf4724,pm6_cf4740;
extern bool pm6_cefafe;
extern int pm6_chances_b9ba40[][38];extern int pm6_tierCaps_b9e0d8[];extern int pm6_limits_b9e0e8[];extern float pm6_scale_ba65d8[];extern int pm6_mode_b905d8[];extern int pm6_kind_b90000[];extern bool pm6_skip_ba6650[][3];
extern vector<vector<PM6HP> > pm6_props_d31640;
extern vector<vector<PM6Point> > pm6_points_d2f32c;
extern vector<int> pm6_ints_d2a2cc;
extern vector<vector<PM6HI> > pm6_items_cf3a10;
extern vector<vector<int> > pm6_pending_d1e8e0;
extern PM6Range pm6_range_d2f130,pm6_range_d389d4,pm6_range_d221a8;
void logError(string location,string message);
bool isOdd_406340(int);
bool pm6_between_9daf80(int,int,int);
void pm6_clamp_9d06d0(int*,int,int);
bool pm6_containsRecord(vector<int>&,int);
int pm6_randomRec(vector<int>&);
int pm6_minInt(int,int);
PM6Point pm6_randomPoint(vector<PM6Point>&);
PM6HL pm6_randomRecord(vector<PM6HL>&);
void getAdjacentCells(const PM6Point&,vector<PM6Point>&);
struct BS {
 PM6Placed *placeMachine(int,const PM6Point&,int,bool,bool);
 PM6ItemDef *selectRandomItemOfRating(int,int,int,int,int,int,int);
 PM6Point unknown6c6d10(vector<PM6Point>&,const PM6Point&);
 char pad0[0x10];vector<PM6Marker*> markers;char pad20[0xb0-0x20];vector<int> unique;OpR5h_WL<int> fills;char pade4[0x118-0xe4];vector<vector<PM6Point> > origins;vector<vector<PM6Point> > origins2;char pad138[0x148-0x138];vector<PM6Point> linked;char pad158[0x1c8-0x158];vector<PM6Shot*> shots;
};
#define PM6ADD(a,b) group->add45bbe0(new PM6Part(a,b))
PM6Placed *BS::placeMachine(int id,const PM6Point &pos,int rotation,bool bare,bool flag) {
 PM6Image base(pm6_machines_cf35b0[id]->image);
 for(int r=0;r<rotation;r++)
  base.rotate_437ee0(1);
 PM6Layer *next=base.layers.front();
 vector<PM6Point> cols;
 for(int x=pos.x,i=0;x<next->getWidth()+pos.x;x++,i++)
  for(int y=pos.y,j=0;y<next->getHeight()+pos.y;y++,j++) {
   if(next->at(i,j)->ch()!=0x20) {
    if((*pm6_cells_cfd44c.at(x,y))->place45df50(pm6_factory_cefaa8->createE(pm6_machines_cf35b0[id]))) {
     (*pm6_cells_cfd44c.at(x,y))->getProp()->unknown45cc50(PM6Point(x,y));
     (*pm6_cells_cfd44c.at(x,y))->getProp()->unknown65e8a0(next->at(i,j));
     cols.push_back(PM6Point(x,y));
    }
    else
     logError("BS::placeMachine()","Machine placement blocked by existing machine/prop, skipping section (crash likely)");
   }
   if(pm6_caf130==7)
    *pm6_grid_cf447c.at(x,y)=5;
  }
 int other=pm6_machines_cf35b0[id]->type;
 PM6Placed *group=0;
 PM6Point begin(-1);
 if(other!=9) {
  int tier;
  for(int k=0;k<3;k++)
   if(pm6_machines_cf35b0[id]->tiers[k]) {
    tier=k+1;
    break;
   }
  begin=pm6_machines_cf35b0[id]->anchor;
  for(int r=0;r<rotation;r++)
   begin.rotateInto_40a3b0(isOdd_406340(r)?pm6_machines_cf35b0[id]->image.layers.front()->getWidth():pm6_machines_cf35b0[id]->image.layers.front()->getHeight());
  begin+=pos;
  group=new PM6Placed((*pm6_cells_cfd44c.atPoint(begin))->getProp(),origins[other].size()+1,tier,tier,flag);
  (*pm6_cells_cfd44c.atPoint(begin))->getProp()->setMachine_44fc60(group);
  origins[other].push_back(begin);
  origins2[other].push_back(begin);
  if(!bare) {
   switch(other) {
   case 0: {
    int kind=pm6_location_d1e888->type;
    int location=pm6_gameData_d1e860.getDepthIndex();
    vector<int> tags;
    int num;
    int roll;
    for(int j=0;j<=0x40;j++) {
     if(pm6_cf4744&&pm6_between_9daf80(0x13,j,0x15))
      continue;
     if(group->parts.size()==0x19)
      break;
     tags.clear();
     roll=pm6_chances_b9ba40[j][kind];
     if(roll<0x4b)
      pm6_clamp_9d06d0(&roll,pm6_tierCaps_b9e0d8[tier],0x4b);
     num=0;
     while(pm6_chances_b9ba40[j][kind]&&rng.chance(roll)) {
      num++;
      switch(j) {
      case 0: {
       vector<int> cands;
       for(int k=0;k<pm6_blueprints_d35b58.size();k++)
        if(location>=pm6_blueprints_d35b58[k]->minDepth&&tier>=pm6_blueprints_d35b58[k]->minTier&&pm6_blueprints_d35b58[k]->test_45b910(kind)&&!pm6_containsRecord(tags,k))
         cands.push_back(k);
       if(cands.empty()) {}
       else {
        int rec=pm6_randomRec(cands);
        PM6ADD(j,rec);
        tags.push_back(rec);
       }
       break;
      }
      case 1: {
       int attempt=0;
       PM6ItemDef *item;
       do {
        attempt++;
        if(attempt==50) {
         item=0;
         break;
        }
        item=selectRandomItemOfRating(pm6_location_d1e888->getDepthIndex()+rng.rangeInt(0.0f,2.0f),0,0,0x1f,0x12,0x2a,0);
        if(!item)
         break;
       } while(item->rating<6||pm6_containsRecord(tags,item->id)||unique[item->id]&&rng.chance(0x4b));
       if(!item) {}
       else {
        PM6ADD(j,item->id);
        tags.push_back(item->id);
       }
       break;
      }
      case 2: {
       int pick=pm6_caf160;
       int tries=0;
       do {
        tries++;
        if(tries==50||!fills.pick(&pick)) {
         pick=pm6_caf160;
         break;
        }
       } while(pm6_containsRecord(tags,pick));
       if(pick==pm6_caf160) {}
       else {
        PM6ADD(j,pick);
        tags.push_back(pick);
       }
       break;
      }
      case 3: {
       vector<int> cands;
       for(int k=0;k<pm6_records_d25de0.size();k++)
        if(!pm6_records_d25de0[k]->label.empty()&&pm6_between_9daf80(location-2,pm6_records_d25de0[k]->level,location+2)&&(k==0||pm6_records_d25de0[k]->group!=pm6_records_d25de0[k-1]->group)&&!pm6_containsRecord(tags,pm6_records_d25de0[k]->id))
         cands.push_back(k);
       if(!cands.empty()) {
        int rec=pm6_randomRec(cands);
        PM6ADD(j,rec);
        tags.push_back(rec);
       }
       break;
      }
      case 4:
       PM6ADD(j,tier+1);
       break;
      case 0x12:
       if(group->parts.empty()||group->parts.back()->id!=0x11)
        PM6ADD(0x11,-1);
       goto common;
      case 0x14:
       if(group->parts.empty()||group->parts.back()->id!=0x13)
        PM6ADD(0x13,-1);
       goto common;
      case 0x15:
       for(unsigned k=0;k<group->parts.size();k++)
        if(group->parts[k]->id==0x13)
         goto common;
       PM6ADD(0x13,-1);
      default:
      common:
       PM6ADD(j,-1);
       if(pm6_between_9daf80(0x1c,j,0x1f))
        PM6ADD(j+7,-1);
      }
      if(num>=pm6_limits_b9e0e8[j])
       break;
     }
    }
    break;
   }
   case 1:
    PM6ADD(0x41,-1);
    PM6ADD(0x42,-1);
    PM6ADD(0x43,-1);
    if(rng.chance(0x4b)) {
     bool first=rng.chance(0x42);
     PM6ItemDef *chosen;
     int temp;
     for(int k=0;k<0x32;k++) {
      if(first) {
       chosen=selectRandomItemOfRating(pm6_location_d1e888->getDepthIndex()+rng.rangeInt(0.0f,3.0f),0,0,0x1f,0x12,0x2a,0);
       if(chosen&&chosen->rating>=6) {
        group->item80=chosen->id;
        group->item84=group->item80;
        break;
       }
      }
      else {
       if(fills.pick(&temp)) {
        group->pick88=temp;
        group->pick8c=temp;
        break;
       }
      }
     }
    }
    break;
   case 2:
    PM6ADD(0x4c,-1);
    PM6ADD(0x4d,-1);
    PM6ADD(0x4e,-1);
    break;
   case 3:
    PM6ADD(0x51,-1);
    PM6ADD(0x52,-1);
    PM6ADD(0x53,-1);
    PM6ADD(0x54,-1);
    PM6ADD(0x55,-1);
    break;
   case 4:
    PM6ADD(0x5e,-1);
    PM6ADD(0x5f,-1);
    PM6ADD(0x60,-1);
    break;
   case 5:
    PM6ADD(0x63,-1);
    PM6ADD(0x64,-1);
    PM6ADD(0x65,-1);
    break;
   }
  }
 }
 pm6_props_d31640.push_back(vector<PM6HP>());
 pm6_points_d2f32c.push_back(vector<PM6Point>());
 pm6_ints_d2a2cc.push_back(0);
 pm6_items_cf3a10.push_back(vector<PM6HI>());
 vector<PM6HP> &elements=pm6_props_d31640.back();
 int tag=pm6_props_d31640.size()-1;
 if(begin.x!=-1) {
  PM6HP p=(*pm6_cells_cfd44c.atPoint(begin))->getProp();
  p->setIndex_451400(tag);
  elements.push_back(p);
 }
 for(unsigned k=0;k<cols.size();k++)
  if(cols[k].ne_409bd0(begin)) {
   elements.push_back((*pm6_cells_cfd44c.atPoint(cols[k]))->getProp());
   elements.back()->setIndex_451400(tag);
  }
 unknown6c6d10(cols,begin);
 PM6Point to=pm6_randomPoint(cols);
 if((*pm6_cells_cfd44c.atPoint(to))->getProp()->def()->linked)
  linked.push_back(to);
 if(other==5) {
  int n=pm6_range_d2f130.randomInRange_40c130();
  if(pm6_cf462c==5)
   n*=0.5f;
  for(int k=0;k<n;k++) {
   PM6Spawn *s=pm6_spawns_d2ae08.pick();
   shots.push_back(new PM6Shot(begin,s->id,pm6_gameData_d1e860.unknown789250((int)(pm6_range_d389d4.randomInRange_40c130()*s->percent/100*pm6_scale_ba65d8[pm6_cf4718]))));
  }
 }
 if(other==3&&rng.chance(0x4b)&&pm6_location_d1e888->type!=0&&pm6_cf462c!=2) {
  vector<PM6HI> &items=pm6_items_cf3a10[tag];
  for(int k=rng.rangeInt(1.0f,3.0f);k>0;k--) {
   int level=pm6_minInt(8,pm6_location_d1e888->getDepthIndex()+group->level/2);
   PM6ItemDef *item=selectRandomItemOfRating(level,0,0,0x1f,0x12,0x2a,0);
   if(item) {
    PM6HI h=pm6_factory_cefaa8->createD(item);
    h->setIntegrity((int)(h->integrity()*rng.rangeFloat(0.25f,0.75f)));
    h->unknown57a520((*pm6_cells_cfd44c.atPoint(begin))->getProp(),0);
    items.push_back(h);
   }
  }
  if(rng.chance(3)) {
   PM6HI h=pm6_factory_cefaa8->createD(pm6_loot_d31700.pick());
   h->setScaled_579880(pm6_range_d221a8.randomInRange_40c130());
   h->unknown57a520((*pm6_cells_cfd44c.atPoint(begin))->getProp(),0);
   items.push_back(h);
  }
 }
 if(other==5&&pm6_location_d1e888->type!=0) {
  PM6Point door(-1);
  vector<PM6Point> adjacent;
  getAdjacentCells(begin,adjacent);
  for(unsigned k=0;k<adjacent.size();k++)
   if((*pm6_cells_cfd44c.atPoint(adjacent[k]))->getProp().isNull()&&pm6_between_9daf80(pos.x,adjacent[k].x,next->getWidth()+pos.x)&&pm6_between_9daf80(pos.y,adjacent[k].y,next->getHeight()+pos.y)) {
    door=adjacent[k];
    break;
   }
  if(!pm6_cefafe) {
   PM6HL entity=pm6_factory_cefaa8->createB();
   entity->init(0xd,pm6_location_d1e888->f8,8,0);
   pm6_location_d1e888->events.push_back(entity);
   bool open;
   switch(pm6_mode_b905d8[pm6_location_d1e888->type]) {
   case 0:
    open=rng.chance(0x19);
    break;
   case 1:
    open=false;
    break;
   case 2:
    open=true;
    break;
   }
   if(pm6_cf4724)
    open=false;
   if(pm6_cf4740)
    open=true;
   vector<int> &orders=pm6_pending_d1e8e0[pm6_gameData_d1e860.getDepthIndex()];
   if(!orders.empty()) {
    entity->pending=orders;
    orders.clear();
   }
   PM6HL first;
   if(open) {
    vector<PM6HL> opts;
    for(unsigned k=0;k<markers.size();k++)
     if(markers[k]->prop.isNull()&&pm6_kind_b90000[markers[k]->loc->type]==1&&!pm6_skip_ba6650[markers[k]->loc->type][pm6_cf4718])
      opts.push_back(markers[k]->loc);
    if(pm6_cf4740)
     first=markers[0]->loc;
    else if(opts.empty())
     first=markers[0]->loc;
    else
     first=pm6_randomRecord(opts);
   }
   else {
    for(unsigned k=0;k<markers.size();k++)
     if(markers[k]->prop.isValid()&&markers[k]->loc->type==pm6_location_d1e888->type&&markers[k]->loc->f8==pm6_location_d1e888->f8) {
      first=markers[k]->loc;
      break;
     }
    if(first.isNull()) {
     first=pm6_factory_cefaa8->createB();
     first->init(pm6_location_d1e888->type,pm6_location_d1e888->f8,8,0);
     first->events=pm6_location_d1e888->events;
     first->linked=true;
    }
   }
   entity->events.push_back(first);
   markers.push_back(new PM6Marker(door,entity,0,(*pm6_cells_cfd44c.atPoint(begin))->getProp(),PM6HP()));
  }
 }
 if(other==0&&pm6_machines_cf35b0[id]->name=="DSF Access"&&pm6_location_d1e888->type!=0) {
  PM6ADD(6,-1);
  PM6Point door(-1);
  vector<PM6Point> adjacent;
  getAdjacentCells(begin,adjacent);
  for(unsigned k=0;k<adjacent.size();k++)
   if((*pm6_cells_cfd44c.atPoint(adjacent[k]))->getField_4550b0()) {
    vector<PM6Point> adj2;
    getAdjacentCells(adjacent[k],adj2);
    for(unsigned l=0;l<adj2.size();l++)
     if((*pm6_cells_cfd44c.atPoint(adj2[l]))->terrain()->id==caveinThirdTerrain->id) {
      door=adjacent[k];
      goto found;
     }
   }
 found:
  if(!pm6_cefafe) {
   PM6HL ev=pm6_factory_cefaa8->createB();
   ev->init(0xe,pm6_location_d1e888->f8,8,0);
   pm6_location_d1e888->events.push_back(ev);
   if(rng.chance(10))
    for(unsigned k=0;k<markers.size();k++)
     if(markers[k]->prop.isValid())
      for(unsigned l=0;l<markers[k]->loc->events.size();l++)
       if(markers[k]->loc->events[l]->inRange()&&markers[k]->loc->events[l]->getDepthIndex()>pm6_location_d1e888->getDepthIndex()) {
        ev->events.push_back(markers[k]->loc);
        goto done;
       }
  done:
   if(ev->events.empty())
    ev->events.push_back(markers[0]->loc);
   markers.push_back(new PM6Marker(door,ev,1,PM6HP(),(*pm6_cells_cfd44c.atPoint(begin))->getProp()));
  }
 }
 return group;
}
