// Prop::damage65f520: prop destruction handler (garrison / hub / special machines).
// Private partial ABI views; names and untouched fields are placeholders.
// NOTE: placeholder names / placeholder layouts throughout.
#include <string>
#include <vector>
#include "rng.h"
using std::string; using std::vector;
extern RNG rng;

struct GolfGPoint{int x,y;GolfGPoint();GolfGPoint(int);GolfGPoint(int,int);GolfGPoint(const GolfGPoint&)throw();GolfGPoint&operator=(const GolfGPoint&);bool eq409b90(const GolfGPoint&);int random40c130();};
struct GolfGRect{int x1,y1,x2,y2;GolfGRect();GolfGRect(int,int,int,int);bool contains40b750(const GolfGPoint&);GolfGPoint center40b620();};
struct GolfGEntity;struct GolfGProp;struct GolfGItem;struct GolfGGroup;struct GolfGLoc{int a;int type;};struct GolfGEffects;struct GolfGXp;struct GolfGItemDef;
struct GolfGHE{int id;GolfGHE();GolfGEntity*get()const;bool valid()const;};
struct GolfGHP{int id;GolfGHP();GolfGProp*operator->()const;bool valid()const;};
struct GolfGHI{int id;GolfGHI();GolfGItem*operator->()const;bool valid()const;};
struct GolfGHG{int id;GolfGHG();GolfGGroup*operator->()const;};
struct GolfGHL{int id;GolfGHL();GolfGLoc*operator->()const;};
struct GolfGHX{int id;GolfGHX();GolfGXp*operator->()const;};
struct GolfGAI{char d[0x130];GolfGAI(GolfGHE,int,int);void f459540(const GolfGPoint&);};
struct GolfGEntity{bool isPlayer();const GolfGPoint&getPosition();void setAI(GolfGAI*);GolfGAI*ai45b590();GolfGHG getGroup45a3f0();};
struct GolfGGroup{vector<GolfGHE>&members416f40();void f45e440(int);int count9b8f00();};
struct GolfGItem{const string&name457860();int f457c50(int);void f458690(GolfGItemDef*,int);void f57c090(GolfGItemDef*,int);int f457c80();int f9b6bf0();void f450460(int);void remove57dbe0(int,int,int,int);void f57a0f0(const GolfGPoint&,int,int);string getName(int,int);void f44fc60(int);};
struct GolfGItemDef{int id;};
struct GolfGSub{char p0[0x18];vector<GolfGHI>items;char p28[0x1c];bool f44;~GolfGSub();};
struct GolfGMachine{char p0[8];int level;char pc[0xc];vector<int*>parts;char p28[0x10];GolfGSub*sub;char p3c[4];vector<int>v40;};
struct GolfGColor{unsigned char r,g,b;void getHSV(float*,float*,float*);void setHSV(float,float,float);};
struct GolfGDef{char p0[4];string tag;string name;char p3c[0x2c];int f68;char p6c[4];int f70;int f74;char p78[4];int f7c;char p80[0xc];int f8c;int f90;GolfGPoint f94;int f9c;char pa0[0x54];int f4;int kind;char pfc[0x24];int f120;string s124;char p140[0x20];int f160;};
struct GolfGProp{GolfGHP self;GolfGDef*record;GolfGPoint position;char p10[8];GolfGColor fore;GolfGColor back;char p1e[0x12];GolfGEffects*effects;int machineID;char p38[4];int state3c;bool flag40;bool flag41;char p42[2];GolfGMachine*machine;
 const string&getTag45c590();const string&getName45c5b0();int f457b10();void disable65ed00();int f45ca00(int);int f44ab40();int f4184d0();
 void remove45ce10(bool,int,bool,GolfGHE);bool f6646f0(GolfGHE,int,int,bool);
 bool damage65f520(int,int,bool,bool,int,GolfGHE,bool,bool,bool);};
struct GolfGRec{GolfGPoint pos;GolfGHL h8;bool bc;~GolfGRec();};
struct GolfGTF{GolfGPoint pos;int def;int amount;};
struct GolfGCell{void cleanup45df70();void f45b090(int);GolfGHP getProp();GolfGHI getItem();void f66a050(int,int,int);};
struct GolfGGrid{GolfGCell**atPoint(const GolfGPoint&);GolfGCell**at(int,int);void rect9b4430(const GolfGPoint&,int,GolfGRect&);};extern GolfGGrid gf_grid_cfd44c;
struct GolfGXomSet{int unused;};
struct GolfGWorld{void mark729bc0(GolfGHP);vector<vector<GolfGPoint> >&f459070();vector<GolfGRec*>&f462e10();bool f726d60();void f72ed70(int);void f714000(vector<GolfGPoint>&);GolfGHG getGroup(int);
 GolfGHE getPlayer();void f464f60(GolfGHI);void f7480e0(int);void f742c80();void f7430a0(int,int);bool isVisible(const GolfGPoint&);GolfGRec*f462f60(GolfGHP);GolfGRec*f462fd0(GolfGHP);void onGarrisonAccessDisabled();
 vector<vector<GolfGHP> >&f463be0();void removeMachine(int,const GolfGPoint&);void f72f2e0();void f72f6b0();void f72ffe0(int);bool f714a50();GolfGHI f71e7c0(const GolfGPoint&,int,int);void f464840(GolfGHI);
 bool f464a20();bool f71bde0(const GolfGPoint&,GolfGPoint&);GolfGHI f6c5400(GolfGItemDef*,const GolfGPoint&);vector<GolfGTF*>&f464940();void f74b060(const GolfGPoint&,int,int);GolfGHX addRecord(GolfGHX);void f727150(const GolfGPoint&,int,int,int);
 void f464ed0(GolfGHP);void addPoint(const GolfGPoint&);};
extern GolfGWorld*gf_world_cefc4c;
struct GolfGOvermind{int spawnHunterParty(GolfGHE,const GolfGPoint&,int);void f6821f0();void destroyed681eb0(GolfGHP,GolfGHE);};extern GolfGOvermind gf_overmind_cf6428;
struct GolfGGameData{void addToEntry(const string&,int);const string&getEntryText(const string&);void setEntryText(const string&,const string&);void f7897a0(int);int getDepthIndex();};extern GolfGGameData gf_gd_d1e860;
struct GolfGStats{bool add4729d0(int,int,string,int);void add472b90(int,int);int f472c90(int);};extern GolfGStats gf_stats_d2c658;
struct GolfGStat2{void f451400(int);};extern GolfGStat2 gf_stat2_cf1080;
struct GolfGPlayerData{void f77fbc0(int);};extern GolfGPlayerData gf_pd_cf45d8;
struct GolfGXom{bool active;bool f69e9b0(const GolfGPoint&);void f69e700(int,int,float);};extern GolfGXom gf_xom_d25450;
struct GolfGUI{void bubble(bool);};extern GolfGUI*gf_ui_cec058;struct GolfGLog{void scroll();};extern GolfGLog*gf_log_cec0b4;extern GolfGLog*gf_log_cec0c4;
struct GolfGMapView{void f807100(int);void removeMarker(int);};extern GolfGMapView*gf_mv_cec054;
struct GolfGFx{GolfGFx*f508610();void init503b20(GolfGFx*,int*,const GolfGPoint&,int*,int,int,int,int,int);};extern GolfGFx*gf_fx_cefc50;
struct GolfGSoundMgr{void mute(GolfGHP);};extern GolfGSoundMgr gf_snd_d2d2a0;
struct GolfGPool{void remove(GolfGHP,bool);};extern GolfGPool gf_pool_d1e720;
struct GolfGXpE{char d[0x40];GolfGXpE(GolfGHE,int,const GolfGPoint&,GolfGHE,const GolfGPoint&,const GolfGPoint&);};
struct GolfGFactory{GolfGHX createA(GolfGXpE*);};extern GolfGFactory*gf_factory_cefaa8;
struct GolfGXp{void f455950(vector<GolfGHP>&);};
extern int*gf_cefb9c;extern GolfGHL gf_loc_d1e888;extern GolfGDef*gf_def_cefbe0;extern GolfGDef*gf_def_cefbd8;extern vector<GolfGPoint>gf_cefd04;extern vector<vector<GolfGHP> >gf_machines_d31640;
extern int gf_cf4718,gf_cf4d8c,gf_cf462c,gf_d254fc,gf_d1ebb8,gf_d1ebc0,gf_d28d18,gf_d1f32c;extern bool gf_d1eb98,gf_d1eb99,gf_d255b0,gf_d255b1,gf_d255b2,gf_cf6590,gf_mute_d28fb0;
extern vector<int>gf_cf4a14,gf_cf46e4,gf_d1e920;extern int gf_b9b988[];extern vector<GolfGRect>gf_d1ec74;extern int gf_d1ec6c,gf_d1ec70;extern vector<GolfGItemDef*>gf_d2c408,gf_d2d1c4,gf_d2ed7c,gf_d316a0,gf_d32990,gf_d31510;
extern vector<vector<GolfGHI> >gf_cf3a10;extern GolfGPoint gf_cf39f8,gf_cf2734,gf_d2f128;extern vector<vector<GolfGPoint> >gf_d2f32c;extern int gf_d2e20c;extern GolfGRect gf_d1eaf8;
struct GolfGF12{float a,b,c;};extern GolfGF12 gf_b9e680[],gf_b9e65c[];extern const float gf_b9e650;extern const float gf_c36ecc;
extern string gf_d323f8[];extern string gf_d1f3d4;
extern const char gf_empty_b954de[],gf_empty_b954df[],gf_empty_b95501[],gf_empty_b95502[],gf_empty_b95503[],gf_empty_b95516[],gf_empty_b95517[],gf_empty_b95529[],gf_empty_b9552a[];
int golf_stringToInt_g(const string&);string golf_intToString_g(int);
void gf_sound4541b0(int,int,int);void gf_sound454260(const GolfGPoint&,int);void gf_sound454160(const GolfGPoint&,int,int);
bool gf_show5111e0(int,const string*,const string*,const string*,GolfGHE,GolfGHP,const GolfGPoint*,bool);bool gf_log5141b0(int,const string*,const string*,const string*,GolfGHE,const GolfGPoint*);
void gf_msg49c610(int,GolfGHE,const string*,int);void gf_fn510360(const string&);
GolfGPoint gf_randomPoint9d5350(vector<GolfGPoint>&);bool gf_findByName9d7de0(vector<GolfGItemDef*>&,const string&,GolfGItemDef*&);int gf_indexOf9d7b80(vector<GolfGItemDef*>&,const string&);
bool gf_lookup9d7980(const string&,int*&);int gf_indexOf9d74d0(vector<GolfGItemDef*>&,const string&);void gf_eraseAt9d9f80(vector<GolfGRect>&,unsigned);
void gf_erase9d51d0(vector<GolfGRec*>&,GolfGRec*);void gf_removeEntity9d2f00(vector<GolfGHP>&,GolfGHP);bool gf_collect517ae0(int,vector<GolfGPoint>&,int,int,int);
void gf_delStep9de640(vector<GolfGTF*>&,unsigned&);void gf_eraseStep9d6440(vector<GolfGHI>&,unsigned&);int gf_randomIndex9d9b20(vector<GolfGHI>&);void gf_eraseAt9da940(vector<GolfGHI>&,int);
GolfGItemDef*gf_randomRec9d5d00(vector<GolfGItemDef*>&);int gf_maxInt9cdb60(int,int);void gf_f65f3e0(int,const GolfGPoint&,int,int);
void gf_effect4569a0(int,GolfGHE,GolfGHE,GolfGHP,GolfGHE,int,int,GolfGEffects*,GolfGHE,GolfGHP,GolfGHP,int);

#define GOLF_SOUND(id) if((id)!=-1&&!(gf_mute_d28fb0&&1&&1))gf_sound4541b0(id,0,0)
#define GOLF_SHOW(id,MSG,POS,B) do{if(gf_show5111e0(id,MSG,0,0,GolfGHE(),GolfGHP(),POS,B))gf_ui_cec058->bubble(true);gf_log_cec0b4->scroll();}while(0)
#define GOLF_ALERT(lvl,snd,MSG) do{gf_stat2_cf1080.f451400(lvl);GOLF_SOUND(snd);GOLF_SHOW(0x324,MSG,0,0);gf_log_cec0b4->scroll();}while(0)
#define GOLF_LOG(TEXT,POS) do{gf_log5141b0(0x16,&string(TEXT),0,0,GolfGHE(),POS);}while(0)
#define GOLF_PLAYERPOS (&gf_world_cefc4c->getPlayer().get()->getPosition())
#define GOLF_CELL(p) (*gf_grid_cfd44c.atPoint(p))
#define GOLF_CELLXY(x,y) (*gf_grid_cfd44c.at(x,y))
#define GOLF_REMOVE(c) (c)->getProp()->remove45ce10(true,0,true,GolfGHE())

bool GolfGProp::damage65f520(int damage,int type,bool force,bool quiet,int cause,GolfGHE attacker,bool flag,bool silent,bool chain){
 if((damage>=record->f70&&record->f70!=-1)||force){
  bool dead=state3c==1;
  GOLF_CELL(position)->cleanup45df70();
  int value=0x82;
  if(record==gf_def_cefbe0){
   gf_world_cefc4c->mark729bc0(self);
  }else if(record->f4!=0){
   if(record->f8c)gf_cefd04.push_back(position);
   if(rng.chance(50))GOLF_CELL(position)->f45b090(-9999);
   if(!flag40){
    vector<GolfGHP>&list=gf_machines_d31640[machineID];
    for(unsigned i=0;i<list.size();i++)list[i]->flag40=true;
   }
   if(state3c!=1){
    if(record->kind==5){
     gf_machines_d31640[machineID].front()->state3c=1;
     if(gf_loc_d1e888->type==5&&gf_world_cefc4c->f459070()[5].size()==1){
      vector<GolfGRec*>&recs=gf_world_cefc4c->f462e10();
      for(unsigned j=0;j<recs.size();j++){
       if(recs[j]->h8->type==0x22){
        recs[j]->bc=false;
        GolfGRect area;
        gf_grid_cfd44c.rect9b4430(recs[j]->pos,10,area);
        for(int x=area.x1;x<=area.x2;x++)for(int y=area.y1;y<=area.y2;y++)
         if(GOLF_CELLXY(x,y)->getProp().valid()&&GOLF_CELLXY(x,y)->getProp()->getTag45c590()=="ACC_Door_Shootable_COM")GOLF_REMOVE(GOLF_CELLXY(x,y));
        break;
       }
      }
     }
     if(gf_overmind_cf6428.spawnHunterParty(GolfGHE(),position,1)){
      string msg("ALERT: Garrison Access compromised, dispatching ");
      if(gf_cf4718==0){gf_overmind_cf6428.spawnHunterParty(GolfGHE(),position,1);msg+="multiple assault carriers.";}
      else msg+="assault squad.";
      GOLF_ALERT(1,0x129,&msg);
     }
    }else if(record->tag=="GAR_Generator"){
     bool b=gf_world_cefc4c->f726d60();
     if(gf_loc_d1e888->type==13){
      gf_gd_d1e860.f7897a0(2);
      if(gf_xom_d25450.active&&b){if(gf_d255b0)gf_d255b0=false;else value=0x4a;}
     }
    }else if(gf_loc_d1e888->type==13){
     if(record->tag=="GAR_Relay"){
      gf_gd_d1e860.addToEntry("garrisonRelaysDisabled_g",1);
      gf_stats_d2c658.add4729d0(0x25d,1,string(gf_empty_b954de),-1);
      GOLF_LOG("Garrison Relay",&position);
      gf_gd_d1e860.f7897a0(1);
     }else if(record->tag=="GAR_RIF_Installer"){
      gf_gd_d1e860.f7897a0(0);
      if(attacker.get()&&attacker.get()->isPlayer()){if(++gf_cf4d8c==3)gf_pd_cf45d8.f77fbc0(0xf1);}
      if(gf_xom_d25450.active&&!gf_cf4a14.empty())value=0x49;
     }else if(record->tag=="GAR_Heavy_Assembler"){
      gf_d1eb98=true;
      GOLF_LOG("H-XX Assembler",&position);
      gf_gd_d1e860.f7897a0(2);
     }else if(record->tag=="GAR_QS_Assembler"){
      gf_d1eb99=true;
      GOLF_LOG("QS Assembler",&position);
      gf_gd_d1e860.f7897a0(2);
     }
    }else if(record->tag=="Energy Cycler"){
     gf_stats_d2c658.add4729d0(0x260,1,string(gf_empty_b954df),-1);
     gf_world_cefc4c->f72ed70(1);
     if(attacker.get()&&attacker.get()->isPlayer())gf_pd_cf45d8.f77fbc0(0xf0);
     if(gf_xom_d25450.active&&gf_stats_d2c658.f472c90(0x260)==1){if(gf_d255b1)gf_d255b1=false;else value=0x58;}
    }else if(gf_loc_d1e888->type==0x1b&&record->tag=="HUB_Network_Hub"){
     gf_gd_d1e860.addToEntry("hubNetworkHubDisabled_g",1);
     gf_stats_d2c658.add4729d0(0x25f,1,string(gf_empty_b95501),-1);
     gf_stats_d2c658.add472b90(0x27,-999999);
     GOLF_LOG("Network Hub",GOLF_PLAYERPOS);
     if(golf_stringToInt_g(gf_gd_d1e860.getEntryText("hubNetworkHubDisabled_g"))==1){
      string msg="ALERT: Network intrusion management efficiency reduced by "+golf_intToString_g(gf_b9b988[1])+"%. Dispatching hub defense squads. All non-combat units evacuate.";
      GOLF_ALERT(1,0x129,&msg);
      vector<GolfGPoint> spots;
      gf_world_cefc4c->f714000(spots);
      if(spots.empty()){}
      else{
       vector<GolfGHE>&members=gf_world_cefc4c->getGroup(4)->members416f40();
       for(unsigned i=0;i<members.size();i++){
        members[i].get()->setAI(new GolfGAI(members[i],0x19,0xe));
        members[i].get()->ai45b590()->f459540(gf_randomPoint9d5350(spots));
       }
      }
      gf_cf6590=true;
      if(gf_cf462c==8&&gf_cf46e4[6]==0){
       string secret("^14_MVYIPKKLU UVAPJL: nypkzhnlnhtlz.jvt/jvntpuk/lcluaz /mvyipkklusvyl/S6-jf1ZT80yH8/S6-jf1ZT80yH8.oats.");
       gf_fn510360(secret);
       GOLF_ALERT(3,-1,&secret);
       gf_cf46e4[6]=1;
      }
      if(gf_xom_d25450.active){if(gf_d255b2)gf_d255b2=false;else value=0x51;}
     }else{
      GOLF_ALERT(1,-1,&("ALERT: Network intrusion management efficiency at "+golf_intToString_g(100-gf_b9b988[golf_stringToInt_g(gf_gd_d1e860.getEntryText("hubNetworkHubDisabled_g"))])+"%."));
     }
    }else if(gf_loc_d1e888->type==8&&golf_stringToInt_g(gf_gd_d1e860.getEntryText("exiMaincAttacked_g"))==0&&(GolfGRect(0x2c,0,0x71,0x47).contains40b750(position)||GolfGRect(0x12,0x4a,0x4b,0x63).contains40b750(position))){
     gf_world_cefc4c->getGroup(9)->f45e440(1);
    }else if(gf_loc_d1e888->type==0x15&&record->tag=="DAT_Data_Conduit"){
     gf_gd_d1e860.setEntryText("datDataConduitDisabled_g","1");
     GolfGPoint p(9,0xb);
     if(GOLF_CELL(p)->getProp().valid())GOLF_REMOVE(GOLF_CELL(p));
     GolfGPoint pos(0x14,6);
     if(GOLF_CELL(pos)->getProp().valid())GOLF_REMOVE(GOLF_CELL(pos));
     GolfGPoint pt(0x13,0x17);
     gf_sound454260(pt,0x91);
     GOLF_LOG("Data Conduit",GOLF_PLAYERPOS);
    }else if(gf_loc_d1e888->type==0x14&&(record->tag=="ZIO_Memory_Banks"||record->tag=="ZIO_Imprinter")){
     gf_gd_d1e860.setEntryText("zioImprinterDisabled_g","1");
     if(golf_stringToInt_g(gf_gd_d1e860.getEntryText("zioWasImprinted_g"))==0&&golf_stringToInt_g(gf_gd_d1e860.getEntryText("zioAttackedLocals_g"))==0)gf_world_cefc4c->getGroup(8)->f45e440(1);
    }else if(gf_loc_d1e888->type==0x13&&record->tag=="DEE_Z_Facility"){
     gf_gd_d1e860.setEntryText("deeFacilityDisabled_g","1");
     GOLF_LOG("Z-Facility",GOLF_PLAYERPOS);
    }else if(gf_loc_d1e888->type==0x22&&record->tag=="COM_0b10_Conduit"){
     gf_gd_d1e860.setEntryText("comConduitDisabled_g","1");
     GolfGPoint p(0x73,0x4a);
     GolfGPoint pos=position.y<-position.x+0xbd?GolfGPoint(0x74,0x4c):GolfGPoint(0x71,0x49);
     if(GOLF_CELL(pos)->getProp().valid()&&GOLF_CELL(pos)->getProp()->getTag45c590()=="COM_0b10_Conduit"&&GOLF_CELL(pos)->getProp()->f457b10()==0)GOLF_CELL(pos)->getProp()->disable65ed00();
     GOLF_LOG("0b10 Conduit",GOLF_PLAYERPOS);
    }else if(record->tag=="ZIOWAR_Quarantine_Array"){
     vector<GolfGPoint> arrays;
     if(gf_loc_d1e888->type==0x14){
      arrays.push_back(GolfGPoint(0x70,0x3f));arrays.push_back(GolfGPoint(0x70,0x42));arrays.push_back(GolfGPoint(0x75,0x3f));arrays.push_back(GolfGPoint(0x75,0x42));
     }else{
      arrays.push_back(GolfGPoint(0x5a,0x22));arrays.push_back(GolfGPoint(0x5a,0x25));arrays.push_back(GolfGPoint(0x5f,0x22));arrays.push_back(GolfGPoint(0x5f,0x25));
     }
     for(unsigned i=0;i<arrays.size();i++)if(GOLF_CELL(arrays[i])->getProp().valid())GOLF_REMOVE(GOLF_CELL(arrays[i]));
    }else if(gf_loc_d1e888->type==0x16&&record->tag=="ZHI_Cloak_Generator"){
     GolfGPoint p(0x13,0x11);
     if(GOLF_CELL(p)->getProp().valid()){
      GOLF_REMOVE(GOLF_CELL(p));
      GOLF_LOG("Cloak Generator",GOLF_PLAYERPOS);
     }
    }else if(gf_loc_d1e888->type==0x19&&record->tag=="Cetus Manufacturing Module"){
     GolfGPoint p(0x2d,0x23);
     GolfGPoint pos(0x2d,0x24);
     if(GOLF_CELL(pos)->getProp().valid()){
      gf_msg49c610(0x320,GolfGHE(),&string("Cetus Manufacturing Module sparks and beeps for a brief moment, then falls silent."),0);
      gf_sound454260(p,0x95);
      GOLF_REMOVE(GOLF_CELL(pos));
     }
     gf_gd_d1e860.setEntryText("cetManufacturingDisabled_g","1");
     GOLF_LOG("Cetus Manufacturing Module",GOLF_PLAYERPOS);
     if(gf_xom_d25450.active&&gf_d1e920[0x19]!=0)value=0x65;
    }else if(gf_loc_d1e888->type==0x1d&&record->tag=="LAB_Door_Hackable"&&golf_stringToInt_g(gf_gd_d1e860.getEntryText("labAlerted_g"))==0&&cause!=0){
     gf_world_cefc4c->f7480e0(0);
    }else if(gf_loc_d1e888->type==0x1f&&record->tag=="TES_Terrabomb"){
     GolfGRect area;
     gf_grid_cfd44c.rect9b4430(position,8,area);
     for(int x=area.x1;x<=area.x2;x++)for(int y=area.y1;y<=area.y2;y++){
      if(GOLF_CELLXY(x,y)->getItem().valid()&&GOLF_CELLXY(x,y)->getItem()->name457860()=="Terrabomb Derivative"){
       GolfGHI item=GOLF_CELLXY(x,y)->getItem();
       GolfGItemDef*source,*other;
       if(gf_findByName9d7de0(gf_d2c408,"TES_Terrabomb_Timer",source)&&item->f457c50(source->id)==0){
        gf_findByName9d7de0(gf_d2c408,"TES_Terrabomb_Unstable",other);
        item->f458690(other,0);
        GOLF_ALERT(1,-1,&string("ALERT: Terrabomb reconfiguration apparatus unstable. Structure dematerialization imminent."));
        item->f57c090(source,0);
        gf_world_cefc4c->f464f60(item);
       }
       goto done;
      }
     }
     done:;
    }else if(record->tag=="Cryocooling Duct"){
     gf_overmind_cf6428.f6821f0();
     GOLF_LOG("Cryocooling Duct",GOLF_PLAYERPOS);
    }else if(gf_loc_d1e888->type==0x21&&record->tag=="FRG_ATD_Cell"){
     gf_world_cefc4c->f742c80();
     if(golf_stringToInt_g(gf_gd_d1e860.getEntryText("frgResearchMorePatrolsCalled_g"))==0){
      gf_world_cefc4c->f7430a0(2,0);
      gf_gd_d1e860.setEntryText("frgResearchMorePatrolsCalled_g","1");
      GOLF_ALERT(1,-1,&string("ALERT: Tinkerer labs infiltrated, dispatching additonal patrols."));
     }
    }else if(gf_loc_d1e888->type==0x23&&record->tag=="AC0_Singularity_Gate"){
     gf_gd_d1e860.setEntryText("ac0GateDisabled_g","1");
     const int range=3;
     int index=gf_indexOf9d7b80(gf_d2c408,"AC0_Gate_Destruction1");
     for(int x=gf_d1ec6c-range;x<=gf_d1ec6c+range;x++)for(int y=gf_d1ec70-range;y<=gf_d1ec70+range;y++)
      if(GOLF_CELLXY(x,y)->getProp().valid()&&GOLF_CELLXY(x,y)->getProp()->f45ca00(index))GOLF_REMOVE(GOLF_CELLXY(x,y));
     GOLF_LOG("Singularity Gate",GOLF_PLAYERPOS);
    }else if(gf_loc_d1e888->type==0x23&&record->tag.find("AC0_Subspace_Node",0)!=string::npos){
     gf_gd_d1e860.addToEntry("ac0NodeDisabled_g",1);
     GolfGPoint center(-1);
     for(unsigned i=0;i<gf_d1ec74.size();i++){
      if(gf_d1ec74[i].contains40b750(position)){
       center=gf_d1ec74[i].center40b620();
       for(int x=gf_d1ec74[i].x1;x<=gf_d1ec74[i].x2;x++)for(int y=gf_d1ec74[i].y1;y<=gf_d1ec74[i].y2;y++)
        if(GOLF_CELLXY(x,y)->getProp().valid()&&GOLF_CELLXY(x,y)->getProp()->getTag45c590().find("AC0_Subspace_Node",0)!=string::npos&&GOLF_CELLXY(x,y)->getProp()->f457b10()==0)GOLF_CELLXY(x,y)->getProp()->disable65ed00();
       gf_eraseAt9d9f80(gf_d1ec74,i);
       break;
      }
     }
     if(center.x!=-1)gf_sound454260(center,0x126);
     GOLF_LOG("Subspace Access Node",GOLF_PLAYERPOS);
    }
    if(gf_xom_d25450.active&&record->kind==1&&gf_world_cefc4c->isVisible(position)&&!(attacker.get()&&attacker.get()->isPlayer())&&!gf_machines_d31640[machineID].empty()
     &&gf_machines_d31640[machineID].front()->machine&&gf_machines_d31640[machineID].front()->machine->sub&&gf_machines_d31640[machineID].front()->machine->sub->f44)value=0x16;
    state3c=1;
    vector<GolfGHP>&parts=gf_machines_d31640[machineID];
    for(unsigned i=0;i<parts.size();i++){
     parts[i]->state3c=1;
     gf_mv_cec054->f807100(parts[i]->f4184d0());
     if(parts[i]->machine){
      if(type==3&&rng.chance(25)){
       for(unsigned j=0;j<parts[i]->machine->parts.size();j++){
        if(*parts[i]->machine->parts[j]==5){
         vector<GolfGPoint> doors;
         if(gf_collect517ae0(machineID,doors,0,2,0)){
          string name(GOLF_CELL(doors.front())->getProp()->getName45c5b0());
          do{if(gf_show5111e0(0x1c0,&name,0,0,gf_world_cefc4c->getPlayer(),GolfGHP(),0,0))gf_ui_cec058->bubble(true);gf_log_cec0b4->scroll();}while(0);
          do{gf_log5141b0(0x81,0,0,0,GolfGHE(),&position);}while(0);
          gf_sound454260(doors.front(),0x7e);
          if(attacker.get()&&attacker.get()->isPlayer())gf_pd_cf45d8.f77fbc0(0x1f);
          int*effect;
          if(gf_lookup9d7980("P_Machine_Door_Open",effect)){
           for(unsigned k=0;k<doors.size();k++){
            if(gf_world_cefc4c->isVisible(doors[k]))gf_fx_cefc50->f508610()->init503b20(gf_fx_cefc50,effect,doors[k],&gf_d2e20c,0,0,0,9,0);
            GOLF_REMOVE(GOLF_CELL(doors[k]));
           }
          }
         }
         break;
        }
       }
      }
      if(record->kind==5){
       GolfGRec*rec=gf_world_cefc4c->f462f60(parts[i]);
       if(rec==0){}
       else{
        GOLF_CELL(rec->pos)->f66a050(*gf_cefb9c,2,1);
        delete rec;
        gf_erase9d51d0(gf_world_cefc4c->f462e10(),rec);
        rec=0;
       }
       gf_world_cefc4c->onGarrisonAccessDisabled();
      }else if(record->tag=="DSF Access"){
       GolfGRec*rec=gf_world_cefc4c->f462fd0(parts[i]);
       if(rec){
        GOLF_CELL(rec->pos)->f66a050(*gf_cefb9c,2,1);
        delete rec;
        gf_erase9d51d0(gf_world_cefc4c->f462e10(),rec);
        rec=0;
       }
      }
      for(unsigned j=0;j<parts[i]->machine->v40.size();j++)gf_removeEntity9d2f00(gf_world_cefc4c->f463be0()[parts[i]->machine->v40[j]],parts[i]);
      parts[i]->machine->v40.clear();
      gf_world_cefc4c->removeMachine(record->kind,parts[i]->position);
     }
     if(parts[i]->flag41)gf_snd_d2d2a0.mute(parts[i]);
    }
    if(record->f8c==0){
     if(cause&&!record->s124.empty())do{if(gf_show5111e0(0x1b9,&record->name,&record->s124,0,GolfGHE(),GolfGHP(),&position,0))gf_ui_cec058->bubble(true);gf_log_cec0b4->scroll();}while(0);
     if(record->f4==1||(record->f120!=0&&record->s124=="disabled")){
      float h,s,v;
      for(unsigned i=0;i<parts.size();i++){
       parts[i]->fore.getHSV(&h,&s,&v);
       v=v/(record->f4==1?gf_b9e680[record->kind].a:gf_b9e65c[record->f120].a)*gf_b9e650;
       parts[i]->fore.setHSV(0,0,v);
       parts[i]->back.getHSV(&h,&s,&v);
       v=v/(record->f4==1?gf_b9e680[record->kind].a:gf_b9e65c[record->f120].a)*gf_b9e650;
       parts[i]->back.setHSV(0,0,v);
      }
     }
    }
    if(attacker.get()){
     if(attacker.get()->isPlayer()){
      gf_world_cefc4c->f72f2e0();
      switch(gf_loc_d1e888->type){
      case 10:
       if(gf_d1eaf8.contains40b750(position)&&golf_stringToInt_g(gf_gd_d1e860.getEntryText("recScraplabLockedDown_g"))==0)gf_world_cefc4c->f72f6b0();
       break;
      case 11:
       gf_world_cefc4c->f72ffe0(0);
       break;
      case 20:
       if(record==gf_def_cefbd8)gf_d1ebb8++;
       break;
      case 23:
       if(position.x>=0x4b)gf_d1ebc0++;
       break;
      }
     }
     if(attacker.get()->getGroup45a3f0()->count9b8f00()<=2){
      gf_stats_d2c658.add4729d0(0x25a,1,string(gf_empty_b95502),-1);
      if(gf_xom_d25450.active&&(gf_d254fc!=0||gf_world_cefc4c->f714a50())&&gf_xom_d25450.f69e9b0(attacker.get()->getPosition()))gf_d254fc++;
     }
    }
    if(record->f4!=3)gf_overmind_cf6428.destroyed681eb0(self,attacker);
    if(attacker.get()&&attacker.get()->isPlayer()&&record->f70>=0x28&&(record->name.find("Sealed",0)!=string::npos||record->name.find("Blast",0)!=string::npos))gf_pd_cf45d8.f77fbc0(10);
   }
  }else{
   if(flag41)gf_snd_d2d2a0.mute(self);
   if(attacker.get()&&attacker.get()->isPlayer()){
    switch(gf_loc_d1e888->type){
    case 20:
     if(record==gf_def_cefbd8)gf_d1ebb8++;
     break;
    case 23:
     if(position.x>=0x4b)gf_d1ebc0++;
     break;
    }
   }
  }
  if(type!=2&&record->f94.y!=0){
   int amount=record->f94.random40c130();
   int num=1;
   if(amount>=6){num=rng.rangeInt(1,gf_c36ecc);amount/=num;}
   while(num!=0){
    GolfGHI scrap=gf_world_cefc4c->f71e7c0(position,amount,0);
    if(scrap.valid()){
     gf_world_cefc4c->f464840(scrap);
     if(attacker.get()&&attacker.get()->isPlayer())gf_stats_d2c658.add4729d0(0xd4,amount,string(gf_empty_b95503),-1);
    }
    num--;
   }
  }
  if(record->tag=="TF Node"){
   bool visible=gf_world_cefc4c->f464a20();
   int level=gf_gd_d1e860.getDepthIndex();
   vector<GolfGItemDef*> items;
   if(visible||rng.chance(50))items.push_back(gf_d2d1c4[gf_indexOf9d74d0(gf_d2d1c4,level<=2?"Sensor Array":level<=6?"Imp. Sensor Array":"Adv. Sensor Array")]);
   if(visible||rng.chance(50))items.push_back(gf_d2d1c4[gf_indexOf9d74d0(gf_d2d1c4,level<=2?"Signal Interpreter":level<=6?"Imp. Signal Interpreter":"Adv. Signal Interpreter")]);
   for(unsigned i=0;i<items.size();i++){
    GolfGPoint drop;
    if(gf_world_cefc4c->f71bde0(position,drop)){
     GolfGHI item=gf_world_cefc4c->f6c5400(items[i],drop);
     GOLF_SHOW(0x1d3,&item->getName(0,0),&position,0);
    }
   }
  }
  if((record->kind==5&&gf_machines_d31640[machineID][0]->machine)||record->tag=="GAR_Relay"){
   vector<GolfGTF*>&stored=gf_world_cefc4c->f464940();
   if(record->kind==5)for(unsigned i=0;i<stored.size();i++)if(rng.chance(50))gf_delStep9de640(stored,i);
   for(unsigned i=0;i<stored.size();i++){
    if(stored[i]->pos.eq409b90(position)||(GOLF_CELL(stored[i]->pos)->getProp().valid()&&GOLF_CELL(stored[i]->pos)->getProp()->f44ab40()==machineID)){
     GolfGPoint drop;
     if(gf_world_cefc4c->f71bde0(position,drop)){
      GolfGHI item=gf_world_cefc4c->f6c5400(gf_d2d1c4[stored[i]->def],drop);
      item->f44fc60(stored[i]->amount);
      GOLF_SHOW(0x1d1+(record->kind!=5),&item->getName(0,0),&position,0);
      gf_stats_d2c658.add4729d0(0x371,1,string(gf_empty_b95516),-1);
      gf_stats_d2c658.add4729d0(0x373,1,string(gf_empty_b95517),-1);
     }
     gf_delStep9de640(stored,i);
    }
   }
  }
  if(damage>0&&record->kind==3&&!gf_cf3a10[machineID].empty()){
   vector<GolfGHI>&stored=gf_cf3a10[machineID];
   for(unsigned i=0;i<stored.size();i++){
    if(rng.chance(damage/5)){
     int loss=stored[i]->f457c80()*gf_cf39f8.random40c130()/100;
     if(loss>=stored[i]->f9b6bf0()){
      stored[i]->remove57dbe0(0,0,1,1);
      gf_eraseStep9d6440(stored,i);
     }else stored[i]->f450460(stored[i]->f9b6bf0()-loss);
    }
   }
   if(!gf_cf3a10[machineID].empty()&&rng.chance(50)){
    int index=gf_randomIndex9d9b20(stored);
    GolfGPoint pos;
    if(gf_world_cefc4c->f71bde0(position,pos)){
     GOLF_SHOW(0x1ca,&stored[index]->getName(0,0),&position,0);
     stored[index]->f57a0f0(pos,0,0);
    }
    gf_eraseAt9da940(stored,index);
   }
  }
  if(record->kind==2&&!gf_machines_d31640[machineID].empty()&&gf_machines_d31640[machineID].front()->machine&&gf_cf462c!=2){
   int count=gf_cf2734.random40c130();
   if(count!=0){
    vector<GolfGItemDef*> pool;
    unsigned level=gf_machines_d31640[machineID].front()->machine->level-1;
    if(level<gf_d2ed7c.size()){
     pool.push_back(gf_d2ed7c[level]);pool.push_back(gf_d316a0[level]);pool.push_back(gf_d32990[level]);pool.push_back(gf_d31510[level]);
    }
    if(!pool.empty()){
     for(int i=0;i<count;i++){
      GolfGPoint drop;
      if(gf_world_cefc4c->f71bde0(position,drop)){
       GolfGHI item=gf_world_cefc4c->f6c5400(gf_randomRec9d5d00(pool),drop);
       item->f450460(gf_maxInt9cdb60(1,item->f457c80()*(100-gf_d2f128.random40c130())/100));
       GOLF_SHOW(0x1cc,&item->getName(0,0),&position,0);
      }
     }
    }
   }
   GolfGMachine*m=gf_machines_d31640[machineID].front()->machine;
   if(m->sub&&!m->sub->items.empty()&&rng.chance(15)){
    GolfGPoint drop;
    if(gf_world_cefc4c->f71bde0(position,drop)){
     gf_mv_cec054->removeMarker(gf_machines_d31640[machineID].front()->f4184d0());
     GolfGHI item=m->sub->items.front();
     item->f57a0f0(drop,0,0);
     m->sub->items.clear();
     delete m->sub;
     m->sub=0;
     GOLF_SHOW(0x1cc,&item->getName(0,0),&position,0);
    }
   }
  }
  gf_world_cefc4c->f74b060(position,record->f9c,100);
  if(!quiet){
   gf_f65f3e0(record->f74,position,damage-record->f70,type);
   if(record->f160)gf_sound454160(position,record->f160,0x11);
  }
  if(!silent&&machineID!=-1&&!dead){
   if(record->f8c){
    GOLF_SHOW(0x1b7+(chain!=0),&record->name,&position,0);
    if(gf_d28d18==1){
     string msg=(attacker.valid()?"  ":gf_empty_b95529)+record->name+" explodes";
     do{if(gf_show5111e0(0x2cd,&msg,0,0,GolfGHE(),GolfGHP(),&position,true))gf_ui_cec058->bubble(false);gf_log_cec0c4->scroll();}while(0);
    }
    if(chain)gf_stats_d2c658.add4729d0(0x257,1,string(gf_empty_b9552a),-1);
    GolfGHX blast=gf_factory_cefaa8->createA(new GolfGXpE(attacker,record->f8c,position,GolfGHE(),GolfGPoint(-1),GolfGPoint(-1)));
    vector<GolfGHP>&parts=gf_machines_d31640[machineID];
    gf_removeEntity9d2f00(parts,self);
    blast->f455950(parts);
    gf_world_cefc4c->addRecord(blast);
   }
   if(record->f7c==2&&record->f90){
    if(gf_world_cefc4c->isVisible(position))gf_fx_cefc50->f508610()->init503b20(gf_fx_cefc50,(int*)record->f90,position,&gf_d2e20c,0,0,0,9,0);
    else gf_world_cefc4c->f727150(position,5,5,gf_d1f32c);
   }
  }
  if(value!=0x82)gf_xom_d25450.f69e700(value,0,0);
  gf_d1f3d4=gf_d323f8[type];
  gf_effect4569a0(4,GolfGHE(),GolfGHE(),self,GolfGHE(),0,0,effects,GolfGHE(),self,GolfGHP(),0);
  gf_world_cefc4c->f464ed0(self);
  if(machineID!=-1){
   gf_removeEntity9d2f00(gf_machines_d31640[machineID],self);
   gf_d2f32c[machineID].push_back(position);
  }
  if(record->f68)gf_world_cefc4c->addPoint(position);
  gf_pool_d1e720.remove(self,true);
  return true;
 }else if(f6646f0(attacker,type,cause,flag))return true;
 return false;
}
