// NOTE: private partial layouts and placeholder call-site names for access825e00.
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;
struct AccessPoint {int x,y;};struct AccessEntity;
struct AccessH {int id;AccessH() throw();AccessEntity*operator->()const throw();};
struct AccessProp {int id;AccessProp() throw();};
struct AccessEntity {const AccessPoint&position() throw();int energy() throw();};
struct AccessZoneInfo {int unk0,kind,depth;char gap[0x25-12];bool branch;};
struct AccessZH {int id;AccessZoneInfo*operator->()const throw();};
struct AccessZone {char pad[8];AccessZH info;char gap[0x1c-12];int status;};
struct AccessWorld {char pad[0x66c];AccessH playerID;AccessZone*zone(const AccessPoint&);AccessH player();bool overrideFlag();vector<AccessZone*>*zones();void refuse(int);void autosave(bool);};
struct AccessData {string&text(const string&);int depth(AccessZH,bool);};
extern AccessWorld*accessWorld;extern AccessData accessData;
extern AccessZH accessCurrent;
extern int accessMode,accessScenario,accessGauntlet;
extern unsigned char accessBlocked[][3];extern string accessZoneNames[];
struct AccessPhraseA {char bytes[0x20];AccessPhraseA(int,string*,string*,string*,AccessH,AccessH);};
struct AccessPhraseB {char bytes[0x28];AccessPhraseB(int,string*,string*,string*,AccessH,AccessH);};
struct AccessInterface {void add(AccessPhraseA*);};extern AccessInterface*accessInterface;
struct AccessMessages {int push(AccessPhraseB*);};extern AccessMessages accessMessages;
struct AccessConsole {void scroll(bool);};extern AccessConsole*accessConsole;
struct AccessLog {void end();};extern AccessLog*accessLog;
struct AccessStats {vector<int>*counts;bool add(unsigned,int,string,int);};extern AccessStats accessStats;
struct AccessPlayer {void event(int);};extern AccessPlayer accessPlayer;
int accessFind(unsigned char*,unsigned);int accessInt(const string&);
void accessWarning(int,const string*,int,int,AccessH,AccessProp,int);
void accessMessage(int,AccessH,const string&,int);
void accessPhrase(int,int,int,int,AccessProp,int);
bool accessCanAutosave();void accessEvolve(int,AccessZH,int);
class DeltaAccess {public:void pulse(unsigned,bool);void label(bool,AccessZone*);void enter();};
#define ACCESS_WARN(ID,STR) accessWarning(ID,STR,0,0,AccessH(),AccessProp(),0)
#define ACCESS_LOG(ID) do{if(accessMessages.push(new AccessPhraseB(ID,0,0,0,AccessH(),AccessH())))accessConsole->scroll(true);accessLog->end();}while(false)
void DeltaAccess::enter(){
 int count;vector<AccessZone*>*a;unsigned i;int type;
 AccessZone*p=accessWorld->zone(accessWorld->playerID->position());
 if(accessBlocked[p->info->kind][accessMode]){
  if(accessMode==0)ACCESS_WARN(220,&accessZoneNames[p->info->kind]);
  else{count=accessFind(accessBlocked[p->info->kind],3);ACCESS_WARN(count==1?222:221,&accessZoneNames[p->info->kind]);}
  return;
 }
 if(p->status==2){accessInterface->add(new AccessPhraseA(195,0,0,0,AccessH(),AccessH()));return;}
 if(p->status==3){ACCESS_WARN(194,&string("Lockdown"));return;}
 if(p->status==4){ACCESS_WARN(194,&string(accessScenario==4?"Abominations":accessGauntlet?"Gauntlet":"Super Gauntlet"));return;}
 if(p->status==1&&(accessInt(accessData.text("installedRif_g"))||accessWorld->overrideFlag())){
  ACCESS_LOG(463);
  if(accessWorld->overrideFlag()){ACCESS_LOG(464);accessMessage(800,AccessH(),string("Remote lockdown override."),0);}
  else accessMessage(800,AccessH(),string("RIF authorized."),0);
  p->status=0;pulse(7,false);label(true,p);return;
 }
 if(p->status==1&&accessWorld->player()->energy()>25&&!rng.chance(30+accessInt(accessData.text("garrisonRelaysDisabled_g"))*10)){
  ACCESS_LOG(463);ACCESS_LOG(464);
  do{accessPhrase(409,0,0,0,AccessProp(),0);}while(false);
  p->status=2;pulse(7,false);label(true,p);p=0;
  a=accessWorld->zones();
  for(i=0;i<a->size();i++){
   if((*a)[i]->status==1){if(p)goto loopDone;else p=(*a)[i];}
  }
  if(p)p->status=0;
loopDone:
  return;
 }
 if(p->info->depth==0){accessWorld->refuse(28);return;}
 if(accessCanAutosave())accessWorld->autosave(true);
 type=accessData.depth(p->info,true);
 if(accessCurrent->kind!=12&&accessCurrent->kind!=13&&accessCurrent->kind!=14){
  if(p->info->branch){accessStats.add(1030,1,string(""),-1);if((*accessStats.counts)[1030]==10)accessPlayer.event(117);}
  else{accessStats.add(1031,1,string(""),-1);if((*accessStats.counts)[1031]==10)accessPlayer.event(310);}
 }
 accessEvolve(type,p->info,0);
}
