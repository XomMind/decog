#include <string>
#include "rng.h"
using std::string;extern RNG rng;
struct LA13Point {int x,y;LA13Point(const LA13Point&) throw();bool equal409b90(const LA13Point&)const throw();int distance409fb0(const LA13Point&)const throw();};
struct LA13Entity;struct LA13Prop;struct LA13TrapState;
struct LA13H {int id;LA13H() throw();LA13Entity *get9b6570()const throw();};
struct LA13HP {int id;LA13HP() throw();LA13Prop *get9b64f0()const throw();bool valid9b7230()const throw();bool null9b65d0()const throw();};
struct LA13PropDef {char pad[0x140];int type;};struct LA13TrapState {bool active65cf80() throw();};
struct LA13Prop {bool trap45cb70() throw();LA13TrapState *state44b020() throw();LA13PropDef *def9b8f00() throw();};
struct LA13Entity {bool player5c7600() throw();int faction45a2c0() throw();const LA13Point&pos45a4a0() throw();};
struct LA13Terrain {int id;string name;char pad20[0x38];bool passable;char pad59[0xf];int armor;int destroyed;int debris;char pad74[0x38];int sound;};
struct LA13Cell {LA13Terrain *terrain;char pad4[0x2c];LA13Point point;char pad38[0xc];LA13HP prop;int armor66ae70() throw();bool cave66af50() throw();bool machine45dc70() throw();bool edge45d310() throw();void set66a050(int,int,int) throw();void destabilize66d4e0(int,bool) throw();void react670dc0() throw();bool destroy66dae0(int,int,bool,bool,int,bool,LA13H,int);};
struct LA13StatsVec {int&at9b81f0(unsigned) throw();};struct LA13Stats {LA13StatsVec *values;bool add4729d0(unsigned,int,string,int) throw();};extern LA13Stats la13_d2c658;
struct LA13Player {void achieve77fbc0(int) throw();bool has46de40(int) throw();};extern LA13Player la13_cf45d8;
struct LA13Map {int type464290() throw();const LA13Point&origin464610() throw();void alert72f6b0() throw();void alert72ffe0(int) throw();void patrol7430a0(int,bool) throw();void machine726ff0(const LA13Point&) throw();void lab7480e0(bool) throw();};extern LA13Map *la13_cefc4c;
struct LA13Data {const string&text46f6d0(const string&);void set46f700(const string&,const string&);};extern LA13Data la13_d1e860;
struct LA13Mode {int id,type;};struct LA13Handle {int id;LA13Mode*get9b7910()const throw();};extern LA13Handle la13_d1e888;
struct LA13Area {int a,b,c,d;bool contains40b750(const LA13Point&) throw();};extern LA13Area la13_d1eaf8;
struct LA13Overmind {void hit682110(LA13Terrain*,LA13H) throw();void wake68d480() throw();};extern LA13Overmind la13_cf6428;
struct LA13Flag {void set451400(int) throw();};extern LA13Flag la13_cf1080;
struct LA13Log {void end7b4f10() throw();};extern LA13Log*la13_cec0b4;struct LA13UI{void update8758d0(bool) throw();};extern LA13UI*la13_cec058;
extern LA13Terrain *TERRAIN_EARTH,*TERRAIN_CAVE_WALL,*caveinThirdTerrain,*la13_cefb9c,*la13_cefb88;extern int la13_caf158;extern int la13_d1da0c,la13_d1ebc0,la13_cf68b4;extern LA13H la13_cf68b8;
int la13_toInt405610(const string&) throw();bool la13_between9daf80(int,int,int) throw();int la13_sound4541b0(unsigned,int,int) throw();bool la13_route5111e0(int,const string&,const string*,const string*,LA13H,LA13HP,const LA13Point*,bool);void la13_sound454160(const LA13Point&,int,int) throw();void la13_debris65f3e0(int,const LA13Point&,int,int) throw();void la13_show6c0f10(const LA13Point&,int,int) throw();
bool LA13Cell::destroy66dae0(int damage,int type,bool force,bool noDebris,int cause,bool quiet,LA13H attacker,int unused){
 if((damage>=armor66ae70()&&armor66ae70()!=-1)||force){
  la13_cf6428.hit682110(terrain,attacker);
  if(attacker.get9b6570()&&attacker.get9b6570()->player5c7600()){
   if(terrain==TERRAIN_EARTH||terrain==TERRAIN_CAVE_WALL||terrain==caveinThirdTerrain){
    if(la13_cefc4c->type464290()==la13_d1da0c&&cause!=5)la13_d2c658.add4729d0(0x409,1,"",-1);
    la13_d2c658.add4729d0(0x40a,1,"",-1);
    switch(cause){case 2:la13_d2c658.add4729d0(0x40b,1,"",-1);if(la13_d2c658.values->at9b81f0(0x40b)==10)la13_cf45d8.achieve77fbc0(8);break;
     case 3:case 4:la13_d2c658.add4729d0(0x40c,1,"",-1);break;case 5:la13_d2c658.add4729d0(0x40d,1,"",-1);if(la13_d2c658.values->at9b81f0(0x40d)==200)la13_cf45d8.achieve77fbc0(235);break;}
    if(terrain==caveinThirdTerrain)la13_cf45d8.achieve77fbc0(10);
   }else if(prop.valid9b7230()&&terrain==la13_cefb9c&&cause==5&&la13_cf45d8.has46de40(30)&&prop.get9b64f0()->trap45cb70()&&prop.get9b64f0()->state44b020()->active65cf80()&&prop.get9b64f0()->def9b8f00()->type==11&&attacker.get9b6570()->pos45a4a0().equal409b90(point))la13_cf45d8.achieve77fbc0(30);
   switch(la13_d1e888.get9b7910()->type){case 10:if((terrain==TERRAIN_CAVE_WALL||terrain==caveinThirdTerrain)&&la13_d1eaf8.contains40b750(point)&&!la13_toInt405610(la13_d1e860.text46f6d0("recScraplabLockedDown_g")))la13_cefc4c->alert72f6b0();break;
    case 11:la13_cefc4c->alert72ffe0(0);break;case 23:if(!terrain->passable&&point.x>=75)la13_d1ebc0++;break;}
  }
  switch(la13_d1e888.get9b7910()->type){case 33:
   if(terrain==caveinThirdTerrain&&!la13_toInt405610(la13_d1e860.text46f6d0("frgResearchMorePatrolsCalled_g"))&&(!attacker.get9b6570()||attacker.get9b6570()->faction45a2c0()!=33)){
    LA13Point area(la13_cefc4c->origin464610());
    if((point.x==area.x&&point.y<=area.y+107)||(la13_between9daf80(area.x+1,point.x,area.x+21)&&point.y==area.y+107)||(point.x==area.x+22&&la13_between9daf80(area.y+102,point.y,area.x+107))||(la13_between9daf80(area.x+23,point.x,area.x+71)&&point.y==area.y+102)||(la13_between9daf80(area.x+79,point.x,area.x+121)&&point.y==area.y+102)||(point.x==area.x+121&&point.y<=area.y+102)){
     la13_cefc4c->patrol7430a0(2,false);la13_d1e860.set46f700("frgResearchMorePatrolsCalled_g","1");
     do{la13_cf1080.set451400(true);if(false)la13_sound4541b0(-1,0,0);do{if(la13_route5111e0(0x324,string("ALERT: Research labs perimeter wall breached, dispatching additonal patrols."),0,0,LA13H(),LA13HP(),0,false))la13_cec058->update8758d0(true);la13_cec0b4->end7b4f10();}while(false);la13_cec0b4->end7b4f10();}while(false);
     la13_cf6428.wake68d480();
    }
   }break;
  }
  if(!noDebris&&!quiet&&terrain->sound)la13_sound454160(point,terrain->sound,17);
  if(machine45dc70())la13_cefc4c->machine726ff0(point);
  if(terrain->name=="BARRIER_LAB"&&!la13_toInt405610(la13_d1e860.text46f6d0("labAlerted_g")))la13_cefc4c->lab7480e0(false);
  if(terrain->destroyed!=la13_caf158&&!force)set66a050(terrain->destroyed,0,0);
  else if(edge45d310())set66a050(la13_cefb88->id,5,0);
  else{
   LA13Terrain *terrainOld=terrain;set66a050(la13_cefb88->id,0,0);
   if(!noDebris&&prop.null9b65d0())la13_debris65f3e0(terrainOld->debris,point,damage-terrainOld->armor,type);
   if(cave66af50()&&type==2&&rng.chance(damage/2))destabilize66d4e0(1,false);
   if(la13_cf68b4&&la13_cf68b8.get9b6570()&&point.distance409fb0(la13_cf68b8.get9b6570()->pos45a4a0())<=15)la13_show6c0f10(point,terrainOld->id,100);
  }
  return true;
 }else{
  if(cave66af50()&&type==2&&rng.chance(damage/2))destabilize66d4e0(1,false);
  if(type==3)react670dc0();return false;
 }
}
