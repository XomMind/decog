// BS::turnUpdate_74e750 (0x74e750): per-turn map update (achievements, tutorials, timers, machines, map scripts).
// Private partial ABI views (Qb*/qb_* names are file-private placeholders; callees stay stubs paired by address).
// NOTE: placeholder names / placeholder layouts throughout.
#include <string>
#include "util/rng.h"
using std::string;
extern RNG rng;

struct QbEntity;struct QbItem;struct QbProp;struct QbLoc;
struct QbPoint{int x,y;void f40bf50(int);void f40a060(const QbPoint&,int,int);void set40a010(int,int);bool inRect409d70(int,int,int,int)const;bool eq409b90(const QbPoint&);QbPoint();QbPoint(int,int);QbPoint(int);QbPoint(const QbPoint&);QbPoint&operator=(const QbPoint&);QbPoint&operator=(int);int random40c130();};
struct QbHE{int id;QbHE();QbEntity*get_nt()const throw();bool operator!=(QbHE)const;bool operator==(QbHE)const;QbEntity*operator->()const;QbEntity*get9b6570()const;bool valid()const;bool isNull()const;void reset9b7270();};
struct QbHI{int id;QbHI();QbItem*get_nt()const throw();bool isNull()const;QbItem*operator->()const;QbItem*p()const;bool valid()const;};
struct QbHP{int id;QbHP();bool valid()const;void reset9b7270();QbProp*operator->()const;QbProp*p()const;bool isNull()const;};
struct QbHL{int id;bool operator!=(QbHL)const;bool operator==(QbHL)const;QbLoc*operator->()const;};
struct QbLoc{bool isAt46ecd0(QbHL);int f0;int kind;int f8;bool inRange46ecb0();};
struct QbHandle{int id;};
struct QbArea{int x1,y1,x2,y2;QbArea(const QbPoint&,const QbPoint&);void include40bb90(const QbPoint&);void grow40bc10(int);void clamp40bc40(const QbPoint&,const QbPoint&);};
struct QbIntVec{int pv0,pv1,pv2,pv3;void assign9b1950(unsigned,const int&);void push_back(const int&);int&back9b6540();int&at_nt(unsigned)throw();void push_back(int&&);unsigned size()const;int&operator[](unsigned);bool empty()const;};
struct QbMachine{char p0[0x28];int f28;char p2c[0xc];int f38;char p3c[4];QbIntVec v40;void f65c8a0();string name65cc80();};
struct QbExplDef{int id;char p4[0x2c];int f30;};struct QbExplDefs{int pv0,pv1,pv2,pv3;};extern QbExplDefs qb_expl_cfd2cc;
struct QbItemInfo{char p0[0x94];int f94;char p98[0x1a0-0x98];QbExplDef*f1a0;char p1a4[4];QbExplDef*f1a8;};
struct QbItem{string f4579f0();void f458700(const string&);void f5797c0();int f457c80();void f450460(int);bool f415ee0();void f458390(int);void f44fc60(int);int f457820();int f4578a0();int f4578c0();int f457900();void f57a190(QbHE,int,int,int);bool f457d10();const QbPoint&pos_nt()throw();bool f577990();void f5798b0(int);const string&name457860();bool f5798f0();int f9b6bf0()throw();int f457cd0();bool f457d70();int turnsLeft577ad0();QbHE owner457b50();int getEffectValue457be0(int);void f458360(int);void f57a0f0(const QbPoint&,int,int);int f457a30();int f45cb30();bool f458530();const QbPoint&pos575920();void*getEffect457b70(int);int f457f90();int f577a90();bool f577b80();QbItemInfo*info9b4350();int getType44aec0();string getName571db0(int,int);void remove57dbe0(int,int,int,int);};
struct QbItems{int pv0,pv1,pv2,pv3;QbHI&front9b7060();QbItems(const QbItems&);QbHI&at_nt(unsigned)throw();QbItems();~QbItems();unsigned size()const;QbHI&operator[](unsigned);void push_back(const QbHI&);void push_back(QbHI&&);bool empty()const;};
struct QbHEs{int pv0,pv1,pv2,pv3;QbHE&at_nt(unsigned)throw();QbHEs();QbHEs(const QbHEs&);QbHEs&operator=(const QbHEs&);~QbHEs();unsigned size()const;QbHE&operator[](unsigned);void push_back(const QbHE&);void push_back(QbHE&&);bool empty()const;void clear9b73d0();};
struct QbEntity{void f45b270(int);int f5ca400();void f45b240(int);int f45a920();int f45a8d0();void f5dea60(int,int);void takeDamage5e5520(int,int,int,int,int,int,int,bool,QbHE,int,int,int,int,int);int f5cab30();int f45a9d0();int f5cb8b0(struct QbItems&);void f5cb830(struct QbItems&);bool f5c80a0();void f45b070(const string&);int f5cccc0();QbHI f5d1150(QbHE);void changePos5dccb0(const QbPoint&,int);bool f5c8820(QbHE);int f5cecf0(const string&);const QbPoint&pos_nt()throw();void f45b2a0();void f44e2c0(int);void f5fdab0();struct QbInventory*getInventory45ad90();bool isXomCandidate5d51a0();int f5d2090(int);QbHI f5d24e0(int);bool f5c98c0(int,int,int);void f6396a0(const string&,int);void changeFaction5dc780(struct QbHSq,int);void removeEffectsA639730(int);void f642940(QbHI,int,int,int,int);int f5c92e0(int);void f5ded70(int);int f45a990();void setField4514c0(int);void f5de870(int,int);void attemptTeleport63b1c0();const string&getName45a280();int f45a880();struct QbEntInfo*info9b4350();int f45a6e0();bool f5d2a00(int);struct QbHG getGroup45a3f0();void f5de950(int,int);bool f5d4100();int getFaction45a2c0();void f639530(int,int);int getSlotTotal45a860();void f5c94e0(int,QbHE);void f45b210(int);void turnUpdate610430();int f490840();void*f45acb0(int);void f5dcc70(int,int);void f6396f0(const string&,int);void f45b340(struct QbNP*);bool f5d0f60();void die633790(bool,int,QbHE,int,int,int,int,int);const QbPoint&pos45a4a0();int*f45a840();int f448fe0(int);bool isPlayer5c7600();int f5cb570(int,int);bool f45aaa0(QbHE);int f5defa0(int,int);int f5cab90();bool isHostileTo45aa70(QbHE);QbItems*getInventoryList45ab00();QbPoint f45a4c0();QbHI f5d2380(int);void setAI64ecf0(struct QbAIObj*);int getTarget45a760();int getSize45a360();void*f45ac40(int);const string&name416f40();void f637bb0();struct QbAI*ai45b590();};
struct QbAI{void f4593d0(struct QbPath&);void*getEntity459570(QbHE);void f459410(const struct QbRect&);void f451930(int);void setZionite44e540(int);void setField4593f0(int);void f451400(int);bool f459090();struct QbFeeds*f4590f0();void f459470(const struct QbRect&);void f4582d0(int);void f459540(const QbPoint&);QbHE getFollow458ed0();int f9b8f00();struct QbPath*f458ef0();void setPatrolRandom5b3430(QbPoint);void setFollowEntity5b2f80(QbHE,int);void chase5b4710(QbHE,int,int,int,int);};
struct QbProp{void f41a800(int,int);const string&type45c590();void*f45c800(int);void f665be0(int);bool f45c9d0(struct QbXDef*);bool f45cbd0();struct QbTrap*trap44b020();QbMachine*machine45cb30();const QbPoint&pos4184d0();void f45ce80(int,int);int f457b10();int f44ab40();void disableMachine65ed00();struct QbPDef*f9b8f00();void f45ce10(int,int,int,QbHE);void f45cc50(const QbPoint&);void f44eb20(int);void f45cc70(const struct QbColor&);void f45cca0(const struct QbColor&);void f451400(int);void f452270(int);const string&getName45c5b0();bool f45cb90(int);void f65f170();bool f65e280();};
struct QbHPs{int pv0,pv1,pv2,pv3;QbHPs();~QbHPs();QbHP&front9b7060();void push_back(const QbHP&);unsigned size()const;bool empty()const;QbHP&operator[](unsigned);void push_back(QbHP&&);QbHP&back9b6540();};
struct QbHPLists{int pv0,pv1,pv2,pv3;unsigned size9b5100()const;QbHPs&operator[](unsigned);};extern QbHPLists qb_d31640;
struct QbTerrInfo{char p0[0x4c];bool f4c;};struct QbTerrain{char p0[0x50];QbTerrInfo*f50;};
struct QbCell{void removeProp66c100(int,int);int terrain45d0e0();void f66a050(int,int,int);int f457b10();void f66d580(int);bool canCaveIn66af50();void f66b070();bool canPlace66ad20(int);bool f45db70();QbHI getItem45d8f0();bool f4550b0();QbTerrain*terrain9fcd80();const string*name45d140();void trigger45e110(int,int,QbHE);bool f45df50(QbHP);bool isPassableFor66ab30(QbHE);QbHP getProp45d550();QbHE getEntity45d250();};
struct QbGrid{bool contains9b43b0(const QbPoint&);int maxX9b4370();int maxY9b4390();int width9fcd80();int height9b8f00();QbCell**atPoint(const QbPoint&);QbCell**at(int,int);QbPoint size9b7930();void getRect9b7ac0(const QbPoint&,int,int,struct QbRect&);void getRect9b4430(const QbPoint&,int,struct QbRect&);struct QbRect getArea9b4400();};extern QbGrid qb_grid_cfd44c;
struct QbPath{int pv0,pv1,pv2,pv3;QbPoint&back9e8c10();QbPoint&front9b7060();struct QbIter begin9c1270();struct QbIter erase9b3450(struct QbCIter);QbPath();~QbPath();QbPath(const QbPath&);void push_back(const QbPoint&);void push_back(QbPoint&&);unsigned size()const;bool empty()const;QbPoint&operator[](unsigned);void clear9b3560();};extern QbPath qb_cefd04;
struct QbPaths{int pv0,pv1,pv2,pv3;unsigned size()const;QbPath&operator[](unsigned);};
struct QbTimer{int f0;QbHP h4;int f8;};
struct QbTimers{int pv0,pv1,pv2,pv3;unsigned size()const;QbTimer*&operator[](unsigned);};
struct QbAchv{char p0[0x20];string name;};
struct QbAchvs{int pv0,pv1,pv2,pv3;unsigned size()const;QbAchv*&operator[](unsigned);};extern QbAchvs qb_achv_cf09a8;
extern QbIntVec qb_d22590,qb_d2a520;
struct QbPlayer{void f77ffb0(int,int);bool f780380(int,int);void f780480(int,int);bool hasCompanion780790();bool isSlotEmpty46de40(unsigned);void f77fbc0(int);void f77fea0(int);};extern QbPlayer qb_player_cf45d8;
struct QbGameData{int getDepthIndex();string generateID46f890();int getTier46fd60();bool isFlagEnabledB46fc40();void setEntryText46f700(const string&,const string&);const string&getEntryText46f6d0(const string&);};extern QbGameData qb_gd_d1e860;
struct QbFactory{void f793690();struct QbHM createC793190();bool showOnce793450(int,bool,int,int,int);QbHandle createA7930e0(void*);QbHP createE793360(struct QbPropDef*);};extern QbFactory*qb_factory_cefaa8;
struct QbSay{char p0[0x20];int f20;int f24;bool say49e250(int,int,string);bool canSay49e120(int);};extern QbSay*qb_say_cefb48;
struct QbTut{bool f7784b0();};extern QbTut qb_tut_d25628;
struct QbComp{void f7ab2b0();};extern QbComp*qb_comp_cf4ac8;
struct QbView{void f819d50(int,bool);void label813050(int,QbHP,int,int,int);void delay49adc0(int);struct QbOverlay*overlay49b050();void f8195a0(const QbPoint&,int,int);void removeMarker49b400(const QbPoint&);void showTimer8176a0(int,const QbPoint&,int,const void*);};extern QbView*qb_view_cec054;
struct QbBubble{void setText49c540(const string&);void bubble8758d0(bool);};extern QbBubble*qb_bubble_cec058;
struct QbLog{void scrollToEnd7b4f10();};extern QbLog*qb_log_cec0b4;
struct QbStats{QbIntVec*vals;void add472b90(int,int);bool add4729d0(int,int,string,int);int f472c70(int);};extern QbStats qb_stats_d2c658;
struct QbExplosion{int d[0x10];QbExplosion(QbHE,QbExplDef*,const QbPoint&,QbHE,const QbPoint&,const QbPoint&);};
struct QbColor{int v;};struct QbColors{int pv0,pv1,pv2,pv3;QbColor&operator[](unsigned);};
struct QbPropList{int pv0,pv1,pv2,pv3;int f10,f14;char p18[4];int f1c,f20;unsigned size()const;QbHP&operator[](unsigned);bool f6c2180();~QbPropList();};
struct QbDataRec{char p0[0x10];string name;};struct QbWLRec{int d[0x9];QbDataRec*&pick9ba470();};
struct QbWL{int d[0x9];QbWL();~QbWL();void add9ba310(int,int);int&pick9ba470();};
struct QbPend{int f0;bool f4;char p5[3];int f8;QbPath pts;QbIntVec v1c;QbColors v2c;QbColors v3c;~QbPend();};
struct QbPends{int pv0,pv1,pv2,pv3;QbPend*&operator[](unsigned);};extern QbPends qb_cf44b0;
struct QbPropDef{char p0[0x20];string name;char p3c[0x15c-0x3c];int f15c;};struct QbPropDefs{int pv0,pv1,pv2,pv3;QbPropDef*&operator[](unsigned);};extern QbPropDefs qb_propDefs_cf35b0;
struct QbSound{void updatePropMute454520(QbHP);};extern QbSound qb_sound_d2d2a0;
struct QbSquad{int f457dd0();QbHE f45e250(int);QbHE find45e1c0(const string&);void setField45e4a0(int);bool f45e380(int);int count44afb0();void reset45e460();QbHEs*members416f40();};struct QbHSq{int id;QbHSq();QbSquad*operator->()const;};struct QbSquads{int pv0,pv1,pv2,pv3;unsigned size()const;QbHSq&operator[](unsigned);};
struct QbTbl{int v;int pad[7];};extern QbTbl qb_tbl_b99d84[],qb_tbl_b99d94[],qb_tbl_b99d8c[],qb_tbl_b99d90[];
struct QbEntDef{int f0;string name;char p20[4];int f24;int f28;char p2c[0x68-0x2c];int f68;char p6c[0x9c-0x6c];int f9c;};struct QbEntDefs{int pv0,pv1,pv2,pv3;unsigned size()const;QbEntDef*&operator[](unsigned);};extern QbEntDefs qb_entDefs_d25de0;
struct QbRect{int x,y,x2,y2;QbRect();QbPoint center40b620();QbPoint randomPoint40be90();QbRect(int,int,int,int);void set40b300(int,int,int,int);void randomPoint40be30(QbPoint*);};
struct QbOvRec{int f0;QbHE h4;};struct QbOvermind{bool f68a8b0(QbPoint*,QbPoint*);void f6901e0(QbHE,int,int,int,const QbPoint&,int,int);void f68d6d0(bool);QbOvRec*lastParty();void wake68d480();void turnUpdate();bool findDispatchExit(QbPoint*,int,int,int,const QbPoint*,int*,int,int);void addParty(struct QbParty*,int);void spawnCarrier688e80(const QbPoint&,const string&);};extern QbOvermind qb_overmind_cf6428;
struct QbXom{bool active;void turn69d6f0();QbHE findXom6be1d0();void showXomAct6bdb50(bool,QbHE,const QbPoint*);void giveXomItems6be2f0(QbHE);bool placeEntityNear6bd410(int,QbPoint&,QbHE,int,int);void showShift6bd6d0(const QbPoint&,QbHE);void f69e700(int,int,float);};extern QbXom qb_xom_d25450;
extern const char qb_e_b95ac3[];extern int qb_d254f0,qb_cefc30,qb_d1eb60,qb_d1eb64;extern int qb_tbl_b90f38[];extern QbPoint qb_cf1f1c,qb_d2e21c;
struct QbArea2{bool contains40b750(const QbPoint&);};extern QbArea2 qb_d1eaf8;
struct QbCarto{bool f40c9e0(const QbPoint&,QbPath&,int,int,QbPath&);bool findPath40c9a0(const QbPoint&,const QbPoint&,int,int,QbPath&);};extern QbCarto qb_carto_cfe568;
struct QbShift{QbHE h0;QbPoint f4;int fc;};struct QbShifts{int pv0,pv1,pv2,pv3;unsigned size()const;QbShift*&operator[](unsigned);};
void qb_deleteObjectAndStep9de640(QbShifts&,unsigned&);int qb_minInt9cdb30(int,int);
struct QbNP{int x,y;QbNP(int,int);};
struct QbIntVecG{int pv0,pv1,pv2,pv3;int&operator[](unsigned)throw();};extern QbIntVecG qb_d2f0f8;
struct QbSpawnSet{int pv0,pv1,pv2,pv3;};extern QbSpawnSet qb_cf6adc;
struct QbPDef{char p0[0x8c];int f8c;char p90[0x140-0x90];int f140;};struct QbFeed{int f0;int f4;};struct QbFeeds{QbFeed*f458950(int);};extern string qb_str_cfc9d8,qb_str_d2a414;extern QbIntVec qb_rifLevels_cf4a04;
void qb_eraseStep9d6440(QbHEs&,unsigned&);
struct QbOverlay{char p0[0x14];QbPoint p14;QbHE h1c;char p20[8];QbPoint p28;bool f30;};
struct QbMarker{char p0[8];QbPoint pos;void f6c20b0(int,const QbPoint&,int);};struct QbHM{int id;QbHM();QbMarker*operator->()const;};struct QbMarkers{int pv0,pv1,pv2,pv3;void push_back(QbHM&&);QbHM&back9b6540();unsigned size()const;QbHM&operator[](unsigned);};
struct QbMarkerLists{int pv0,pv1,pv2,pv3;QbMarkers&operator[](unsigned);};void qb_eraseStep9d6440(QbMarkers&,unsigned&);
struct QbFlags{bool isSet48f8d0(int);};struct QbFlags2{void set451400(int);int push5121f0(struct QbPhrase*);};extern QbFlags2 qb_flags_cf1080;extern bool qb_d28fb0;extern QbFlags*qb_flags_cec0cc;bool qb_removePoint9d3060(QbPath&,QbPoint);
extern QbHEs qb_cf4aa8;extern QbIntVec qb_cf4ab8;extern int qb_tbl_ba0b64[];bool qb_f9d43b0(int*,unsigned,int);
int qb_distance406480(int,int,int,int);extern const char qb_e_b95acb[],qb_e_b95ad7[],qb_e_b95ae2[];
struct QbPart{void f4a9120();void drawStatus4a8e70(int);};struct QbParts{void toggle8993e0(QbPart*,int);void f896820(QbHI);QbPart*f894e70(QbHI);};extern QbParts*qb_parts_cec088;
string qb_intToString4051f0(int);void qb_shuffle9d9fc0(QbItems&);extern const char qb_e_b95ae3[],qb_e_b95aed[];
struct QbCIter{void*p;QbCIter();};struct QbIter:QbCIter{QbIter();};
struct QbEntInfo{char p0[0x28];int f28;string f2c;};extern bool qb_tbl_b95150[];
struct QbGroup{int kind9b4350();};struct QbHG{int id;QbHG();QbGroup*operator->()const;};
struct QbZone{char p0[8];QbHL h8;};extern int qb_tbl_b90000[];extern bool qb_d1eb98;extern int qb_caf130;
struct QbParty{int d[0xe];QbParty(int,QbHE,int,int,int);};
struct QbHEsList{int pv0,pv1,pv2,pv3;QbHEs&operator[](unsigned);void push_back(QbHEs&&);};
struct QbC6888{void f6927e0();};extern QbC6888 qb_cf6888;extern QbItems qb_cf4944;
extern int*caveinEarthTerrain;extern QbPoint qb_d1ecb4;extern const char qb_e_b95aee[];
void qb_removeVectorElement9de6f0(QbIntVec&,int);
struct QbF8{char d[4];};
struct QbPhrase{int d[0xa];QbPhrase(int,const string*,const string*,const string*,QbHE,QbHE);};
struct QbPathCache{int pv0,pv1,pv2,pv3;bool empty()const;};void qb_clearObjects9e2650(QbPathCache&);extern string qb_str_cfc9bc;
extern int qb_tbl_b90d70[];extern bool qb_cf4a00;
struct QbMission{void f987de0();};extern QbMission*qb_mission_cec034;string qb_countString407a80(int,const string&);
struct QbRecord{int id;};bool qb_lookup9d7980(const string&,QbRecord**);extern unsigned qb_npos_c2ea48;extern int qb_d1eb74,qb_d1eb68;
struct QbOwner;struct QbEffect{void init503b20(QbOwner*,QbRecord*,const QbPoint&,const QbPoint&,const QbPoint*,const QbPoint*,void*,int,QbEffect*);};
struct QbOwner{QbEffect*new508610();};extern QbOwner*qb_owner_cefc50;extern QbPoint qb_d2e20c;extern string qb_names_cf1a18[];
struct QbIntLists{int pv0,pv1,pv2,pv3;QbIntVec&operator[](unsigned);bool empty()const;};void qb_eraseAt9de6b0(QbIntLists&,int);extern const char qb_e_b95aef[],qb_e_b95af6[];
struct QbTrap{char p0[0x10];int f10;int f14;bool f65cf50(int);};
int qb_reveal794da0(int,int,int,int);extern int qb_d1eac0,qb_cf49fc,qb_d1eab8;extern bool qb_d1eacc,qb_d1eaac;
struct QbExitRec{QbPoint pos;QbHL h8;bool locked;char pd[0xf];int f1c;};struct QbExitRecs{int pv0,pv1,pv2,pv3;QbExitRec*&front9b7060();unsigned size()const;QbExitRec*&operator[](unsigned);};
extern int qb_d1eac8;
extern int qb_d1eb08,qb_d1eb10,qb_d1eb0c,qb_d1eb14,qb_d1eb40,qb_d1eb1c,qb_d1eb20,qb_d1eb24,qb_d1eb28,qb_d1eb2c,qb_d1eb30,qb_d1eb34,qb_d1eb38,qb_d1eb3c;extern bool qb_d1eb18;
struct QbObj138{void f96b0a0(bool);void f9693f0();};extern QbObj138*qb_cec138;QbPoint qb_randomPoint9d5350(QbPath&);void qb_f789ac0();void qb_shuffle9d9fc0(QbHEs&);
extern int qb_d1eae4,qb_d1eae0;struct QbArea3{int x1,y1,x2,y2;bool contains40b750(const QbPoint&);bool contains40b700(int,int);};extern QbArea3 qb_d1eae8;extern QbPoint qb_d21b34;
extern int qb_d1eb70,qb_d1ebe8,qb_d1ebcc;extern QbHL qb_d1ebe4;
struct QbS34{void f6c1cd0(QbCell*,int,int);};struct QbS34Grid{QbS34*atPoint9d2c00(const QbPoint&);};
extern int qb_d1ebb8;extern bool qb_d1ebbc;struct QbXDef;struct QbXDefs{int pv0,pv1,pv2,pv3;};extern QbXDefs qb_d2c408;bool qb_findByName9d7de0(QbXDefs&,const string&,QbXDef*&);extern QbPDef*qb_cefbd8;
extern int qb_d1ebc8,qb_d1ebc0,qb_d1ebcc,qb_d1ebd0;extern bool qb_d1ebc4;extern int*caveinWallTerrain,*qb_cefb9c;extern QbPDef*qb_cefbd0;
struct QbInventory{bool removeData4567f0(QbXDef*,int);};void qb_appendVector9d49c0(QbHEs&,const QbHEs&);
bool qb_findByName9d7be0(QbExplDefs&,const string&,QbExplDef*&);bool qb_findByName9d7710(QbPropDefs&,const string&,QbPropDef*&);
struct QbTerrains{int pv0,pv1,pv2,pv3;};extern QbTerrains qb_terrains_cfb844;int qb_indexOfName9d7b80(QbTerrains&,const string&);
struct QbTCell{QbPoint pos;int f8;QbColor color;};struct QbTCells{int pv0,pv1,pv2,pv3;unsigned size()const;QbTCell*&operator[](unsigned);bool empty()const;};
struct QbTCellLists{int pv0,pv1,pv2,pv3;unsigned size9b5100()const;QbTCells&operator[](unsigned);};void qb_clearObjects9d0670(QbTCells&);
extern QbIntVec qb_d33d74;extern QbPropDef*qb_cefbe0;void qb_addUnique9d30e0(QbHEs&,QbHE);void qb_moveElement9da1f0(QbHEs&,int,int);int qb_indexOfEntity9d3110(QbHEs&,QbHE);
void qb_setTerrain6c9b40(int,int,int*);bool qb_f742b60(QbPoint*,int);extern QbItemInfo*qb_cefc00;extern int qb_cf4d88,qb_d1ebf8,qb_d1ebf0,qb_d1ebf4;extern bool qb_cf65bc,qb_cf65bd,qb_cf65be,qb_cf65bf;
struct QbStrVec{int pv0,pv1,pv2,pv3;string&operator[](unsigned);};struct QbStrVecs{int pv0,pv1,pv2,pv3;QbStrVec&operator[](unsigned);};extern QbStrVecs qb_cfc184;
extern bool qb_d1ebec;extern QbHL qb_d1ebe0;extern int qb_d1ebdc,qb_cf6474;char qb_randomChar4085b0(const string&);void qb_eraseRange9d53f0(QbPath&,int,int);
struct QbStrList{int pv0,pv1,pv2,pv3;QbStrList();~QbStrList();void push_back(const string&);unsigned size()const;string&operator[](unsigned);};
extern int qb_d1ec54,qb_d1ec58,qb_d1ec5c,qb_d1ec60;bool qb_f9daf80(int,int,int);
struct QbIRec{int f0;char p4[0x20];string f24;char p40[4];int f44;char p48[0x272-0x48];bool f272;};
struct QbIRecs{int pv0,pv1,pv2,pv3;unsigned size()const;QbIRec*&operator[](unsigned);};extern QbIRecs qb_d2d1c4;
struct QbIntList;
struct QbIRecList{int pv0,pv1,pv2,pv3;QbIRecList();~QbIRecList();void push_back(QbIRec*const&);bool empty()const;};
struct QbDefList{int pv0,pv1,pv2,pv3;QbDefList();~QbDefList();void push_back(QbEntDef*const&);unsigned size()const;QbEntDef*&operator[](unsigned);};
int qb_randomRec9d5d00(QbIntList&);QbIRec*qb_randomRec9d5d00(QbIRecList&);bool qb_f9db000(QbIntList&,int);bool qb_containsRecord9db330(QbIntVec&,int);
struct QbFloatVec{int pv0,pv1,pv2,pv3;unsigned size()const;float&operator[](unsigned);};extern QbFloatVec qb_cf4634;
extern QbIntVec qb_cf4644,qb_cf4654,qb_cf467c;extern unsigned qb_cf4664;extern int qb_cf4668,qb_cf466c,qb_cf4670,qb_cf4674,qb_cf4678;
struct QbFRange{float random40c700();};extern QbFRange qb_d0183c,qb_d29724;
extern const float qb_f_ba76d0,qb_f_ba76d8,qb_f_ba76dc;extern string qb_names_d293c0[];extern QbPoint qb_d20258,qb_d2c400,qb_d30358,qb_d1de90;
struct QbFb08Rec{int f0;QbIRec*f4;};struct QbFb08Recs{int pv0,pv1,pv2,pv3;unsigned size()const;QbFb08Rec*&operator[](unsigned);};
extern bool qb_cefb0a;struct QbHLs{int pv0,pv1,pv2,pv3;unsigned size()const;QbHL&operator[](unsigned);QbHL&back9b6540();};extern QbHLs qb_d1e88c;
struct QbXP{void gain77e900(int,int);};extern QbXP qb_xp_cf45d8;extern int qb_tbl_b90fd0[];extern QbHEs qb_cf46d4;void qb_eraseStep9d6440(QbHEs&,unsigned&);
void qb_eraseAt9da940(QbItems&,int);void qb_removeVectorElement9de6f0(QbIntVec&,int);void qb_eraseAt9ce6d0(QbIntVec&,unsigned&);
extern bool qb_d28dee,qb_d28d04;extern const char qb_e_b95af7[],qb_e_b95afe[],qb_e_b95aff[],qb_e_b95b09[],qb_e_b95b0a[],qb_e_b95b0b[],qb_e_b95b15[];
extern int qb_cf4b60,qb_cf4b64,qb_cf4b6c,qb_cf4b70,qb_cf4b84,qb_cf4b88,qb_cf4b8c,qb_cf4b90,qb_cf4b94,qb_cf4ba4,qb_cf4ba8,qb_cf4bac,qb_cf4bb0;extern QbIntVec qb_cf4b74;extern string qb_d21a78[];
struct QbSpawnTracker{void spawn7aa280(int,int,string);};struct QbCompRec{char p0[4];QbHI h4;char p8[0x28];QbSpawnTracker*f30;};extern QbCompRec*qb_cf4ac8;
extern QbHE qb_cf64fc;extern int qb_d25618,qb_cf462c;extern QbItemInfo*qb_cefbf4;
struct QbRect2{bool containsPos40aa00(const QbPoint&);};extern QbRect2 qb_cf4da4;
void qb_message49c610(int,QbHE,const string&,int);extern QbPoint qb_cf6518,qb_d2e214;extern int qb_cefbb4;extern QbPDef*qb_cefbd4;
void qb_prelearnData797e60(const string&,int);void qb_sound4541b0(int,int,int);bool qb_f9d51d0(QbIntVec&,int);void qb_removeProp9d2f00(QbHPs&,QbHP);int qb_maxInt9cdb60(int,int);
void qb_eraseAt9ce6d0(QbIntVec&,unsigned&);int qb_distanceCeil40a3f0(const QbPoint&,const QbPoint&);bool qb_findByName9d7530(QbEntDefs&,const string&,QbEntDef*&);void qb_sound454260(const QbPoint&,int);
void qb_logPhrase5141b0(int id,const string*a,const string*b,const string*c,QbHE e,const QbPoint*at);
struct QbAIObj{int d[0x4c];QbAIObj(QbHE,int,int);};
struct QbHPLists2{int pv0,pv1,pv2,pv3;unsigned size9b5100()const;QbHPs&operator[](unsigned);};extern QbHPLists2 qb_d20248;
struct QbHatch{int f0;void add460a00(QbHE);};struct QbHatches{int pv0,pv1,pv2,pv3;unsigned size()const;QbHatch*&operator[](unsigned);};
struct QbZion{void newTurn6bf880();};extern QbZion qb_zion_d1dd38;extern int qb_cf4b20;
struct QbOrder{QbPoint pos;int f8;int fc;string name;};struct QbOrders{int pv0,pv1,pv2,pv3;unsigned size()const;QbOrder*&operator[](unsigned);};
void qb_deleteObjectAndStep9de5c0(QbOrders&,unsigned&);void qb_eraseAt9da940(QbHEs&,int);
struct QbPathLists{int pv0,pv1,pv2,pv3;QbPaths&operator[](unsigned);};
struct QbIntGrid{int*at(int,int);int*atPoint(const QbPoint&);};extern QbIntGrid originalTerrain,qb_d1e970;
struct QbIntList{int pv0,pv1,pv2,pv3;int&back9b6540();QbIntList();~QbIntList();void push_back(const int&);void push_back(int&&);unsigned size()const;int&operator[](unsigned);bool empty()const;};
void qb_eraseAt9d5190(QbPath&,int);void qb_eraseAt9da940(QbHPs&,int);void qb_eraseAt9da940(QbItems&,int);bool qb_containsEntity9d31e0(QbItems&,QbHI);bool qb_containsEntity9d31e0(QbHPs&,QbHP);
bool qb_f9d0ce0(QbPath&,QbPoint);void qb_shuffle9d7350(QbPath&);void qb_getSurrounding4faaf0(const QbPoint&,QbPath&);
namespace PhysFScpp{struct QbIfs{int d[0x18];QbIfs(const string&,int,int);~QbIfs();bool isOpen404af0();void close9c05e0();};}
extern QbHL qb_loc_d1e888;
extern bool qb_cefb34,qb_cefb35,qb_cefb37,qb_d28d09,qb_cf474d,qb_d257d4;
extern int qb_d25740,qb_cf4898,qb_cf4854,qb_cf4920,qb_cefc90,qb_caf228;
extern int qb_tbl_b9654c[];
extern QbPoint qb_d2a4f4,qb_d1f38c;
extern string qb_slotNames_d378d0[];
void qb_f79a180();void qb_f4f0a50();
int qb_stringToInt405610(const string&);
bool qb_getEncodedLine4074b0(PhysFScpp::QbIfs*,string&,int);
void qb_removeChar408100(string&,char);
void qb_logMessage404bf0(string,string);void qb_logWarning404e50(string,string);void qb_logError404f10(string,string);
string qb_pointToString40a4a0(const QbPoint&);
void qb_eraseStep9d7300(QbPath&,unsigned&);void qb_eraseStep9d6440(QbHPs&,unsigned&);void qb_eraseStep9d6440(QbItems&,unsigned&);
void qb_deleteObjectAndStep9de640(QbTimers&,unsigned&);
int qb_maxIndex9de560(int*,unsigned);
bool qb_containsEntity9d31e0(QbHEs&,QbHE);
QbHP qb_randomRecord9dafb0(QbHPs&);QbHI qb_randomRecord9dafb0(QbItems&);QbHE qb_randomRecord9dafb0(QbHEs&);
bool qb_showMessage5111e0(int id,const string*a,const string*b,const string*c,QbHE e1,QbHE e2,const QbPoint*at,bool log);
extern const char qb_e_b9597b[],qb_e_b95982[],qb_e_b95abb[];
extern const char qb_e_b95983[],qb_e_b95996[],qb_e_b95997[],qb_e_b959a3[],qb_e_b959aa[],qb_e_b959ab[],qb_e_b959ae[],qb_e_b959af[],qb_e_b959b2[],qb_e_b959b3[],qb_e_b959b6[],qb_e_b959b7[],qb_e_b959ba[],qb_e_b959bb[],qb_e_b959c3[],qb_e_b959e9[],qb_e_b959ea[],qb_e_b959eb[],qb_e_b95a49[],qb_e_b95a4a[],qb_e_b95a4b[],qb_e_b95a73[],qb_e_b95a82[],qb_e_b95a83[],qb_e_b95a8b[],qb_e_b95a96[],qb_e_b95a97[],qb_e_b95a9f[],qb_e_b95ab1[],qb_e_b95ab2[],qb_e_b95ab3[];

struct QbCmd{int f0;int f4;int f8;string fc;string f28;};struct QbCmdList{int pv0,pv1,pv2,pv3;unsigned size()const;bool empty()const;QbCmd*&operator[](unsigned);void push_back(QbCmd*const&);};
struct QbScript{char p0[0x30];bool f30;char p31[0xb];bool f3c;bool f3d;char p3e[0x1e];QbCmdList f5c;char p6c[0x10];QbCmdList f7c;};extern QbScript*qb_cefc58;
void qb_eraseAt9ce6d0(QbCmdList&,unsigned&);void qb_deleteObjectAndStep9de730(QbCmdList&,int&);void qb_deleteObjectAndStep9de730(QbCmdList&,unsigned&);
extern bool qb_cefc70;struct QbSound;struct QbSounds{int pv0,pv1,pv2,pv3;QbSound*&operator[](unsigned);};extern QbSounds qb_cfd2ec;void qb_playSound4ff050(QbSound*,int,int,int,int);extern QbHE qb_d388f4;
void qb_insert9d8fc0(QbHEs&,int,QbHE);void qb_insert9d8fc0(QbItems&,int,QbHI);void qb_insertAt9dbdc0(QbIntList&,int,int);
struct QbInv{void f8a54c0(QbHI,int);void reopen8a2ce0(int,QbHE);};extern QbInv*qb_inv_cec08c;struct QbAllies{void f7b8500(QbHE);};extern QbAllies*qb_allies_cec0c8;
int qb_findStringIndex9cda80(const string*,unsigned,string);extern string qb_cf1970[],qb_d2e6c8[],qb_cfd200[];
void qb_split408700(const string&,char,QbStrList&);bool qb_splitAfterChar4090e0(const string&,char,string&);
struct QbFRange2{float a,b;QbFRange2();bool parse40c500(const string&);float random40c700();};int qb_applyOperation456a50(int,int,float,int,int);
struct QbRecPtrs{int pv0,pv1,pv2,pv3;QbRecord*&operator[](unsigned);};extern QbRecPtrs qb_cf67c0;bool qb_findByName9d7a40(QbIRecs&,const string&,QbIRec*&);
extern int qb_cf68b4,qb_caf2a8,qb_d2561c;extern bool qb_d25620;struct QbTally{void f6998a0(int,int,int);};extern QbTally qb_tally_cf6888;bool qb_f9d4c40(int,int,int);

#define QB_MSG(args) do{if(qb_showMessage5111e0 args)qb_bubble_cec058->bubble8758d0(true);qb_log_cec0b4->scrollToEnd7b4f10();}while(false)

#define QB_ALERT_S(text,s) do{qb_flags_cf1080.set451400(1);if((s)>=0&&!(qb_d28fb0&&(s)>=0x127&&(s)<=0x12a))qb_sound4541b0(s,0,0);QB_MSG((0x324,text,0,0,QbHE(),QbHE(),0,false));qb_log_cec0b4->scrollToEnd7b4f10();}while(false)
#define QB_PHRASE(id) do{if(qb_flags_cf1080.push5121f0(new QbPhrase(id,0,0,0,QbHE(),QbHE())))qb_bubble_cec058->bubble8758d0(true);qb_log_cec0b4->scrollToEnd7b4f10();}while(false)
#define QF(off,decl) struct{char _p##off[off];decl;};
class QbMap{public:
	union{
		QF(0x20,QbHatches f20)
		QF(0x4c,QbSquads f4c)
		QF(0x118,QbPaths f118)
		QF(0x178,QbHPs f178)
		QF(0x188,QbHEs f188)
		QF(0x198,QbPath f198)
		QF(0x1a8,QbHEs f1a8)
		QF(0x1b8,QbOrders f1b8)
		QF(0x1dc,QbTimers f1dc)
		QF(0x278,QbHPs f278)
		QF(0x234,QbHP f234)
		QF(0x238,int f238)
		QF(0x23c,int f23c)
		QF(0x240,int f240)
		QF(0x244,QbHEs f244)
		QF(0x254,int f254)
		QF(0x268,QbPaths f268)
		QF(0x288,QbWLRec f288)
		QF(0x2ac,QbPropList*f2ac)
		QF(0x3d4,QbIntGrid*f3d4)
		QF(0x3d8,QbPath f3d8)
		QF(0x3e8,int f3e8)
		QF(0x3ec,int f3ec)
		QF(0x3f0,QbItems f3f0)
		QF(0x400,QbIntVec f400)
		QF(0x410,QbHEs f410)
		QF(0x420,QbIntVec f420)
		QF(0x430,QbHEs f430)
		QF(0x440,QbHPs f440)
		QF(0x450,QbIntVec f450)
		QF(0x460,QbPath f460)
		QF(0x470,QbIntVec f470)
		QF(0x480,QbItems f480)
		QF(0x490,QbItems f490)
		QF(0x4a0,QbIntVec f4a0)
		QF(0x5ec,QbSpawnSet f5ec)
		QF(0x8a8,int f8a8)
		QF(0x8ac,bool f8ac)
		QF(0x1ec,QbShifts f1ec)
		QF(0xb70,QbHEs fb70)
		QF(0xb80,QbIntGrid*fb80)
		QF(0xb84,QbPath fb84)
		QF(0x6b8,QbHEs f6b8)
		QF(0x6c8,QbHEs f6c8)
		QF(0x138,QbPath f138)
		QF(0x340,QbItems f340)
		QF(0x350,QbIntVec f350)
		QF(0x360,QbIntVec f360)
		QF(0x7e0,QbMarkerLists f7e0)
		QF(0x370,QbItems f370)
		QF(0x3b0,QbItems f3b0)
		QF(0x3c0,QbItems f3c0)
		QF(0x3d0,int f3d0)
		QF(0x510,QbItems f510)
		QF(0x520,int f520)
		QF(0x8,QbF8 f8)
		QF(0xf4,QbPath ff4)
		QF(0x104,int f104)
		QF(0x108,QbPaths f108)
		QF(0x584,QbPath f584)
		QF(0x594,QbHEs f594)
		QF(0x5a4,QbHEsList f5a4)
		QF(0x5b4,int f5b4)
		QF(0x5b8,int f5b8)
		QF(0x5bc,QbPath f5bc)
		QF(0x5cc,QbIntVec f5cc)
		QF(0x534,int f534)
		QF(0x538,QbPath f538)
		QF(0x558,bool f558)
		QF(0x559,bool f559)
		QF(0x604,QbPathCache f604)
		QF(0x614,int f614)
		QF(0x548,QbIntVec f548)
		QF(0x55c,int f55c)
		QF(0x874,QbIntLists f874)
		QF(0x884,QbPath f884)
		QF(0x894,QbIntVec f894)
		QF(0x8a4,bool f8a4)
		QF(0x10,QbExitRecs f10)
		QF(0x328,int f328)
		QF(0x720,QbHPs f720)
		QF(0x868,int f868)
		QF(0x86c,QbPoint f86c)
		QF(0x324,int f324)
		QF(0x7c4,QbS34Grid f7c4)
		QF(0x4f0,QbHPs f4f0)
		QF(0x8c8,bool f8c8)
		QF(0x8ec,QbTCellLists f8ec)
		QF(0x8fc,int f8fc)
		QF(0x900,int f900)
		QF(0x904,QbPath f904)
		QF(0x914,QbHEs f914)
		QF(0x6a8,QbPath f6a8)
		QF(0x8cc,int f8cc)
		QF(0x8d8,int f8d8)
		QF(0x924,QbRect f924)
		QF(0x934,QbRect f934)
		QF(0x944,QbRect f944)
		QF(0x96c,QbIntVec f96c)
		QF(0x98c,int f98c)
		QF(0x990,QbHEs f990)
		QF(0x8b4,QbIntVec f8b4)
		QF(0x8c4,int f8c4)
		QF(0x644,bool f644)
		QF(0x574,QbPath f574)
		QF(0x5c,QbIntGrid f5c)
		QF(0x63c,bool f63c)
		QF(0xb08,QbFb08Recs fb08)
		QF(0xb20,int fb20)
		QF(0xb24,QbItems fb24)
		QF(0xb34,int fb34)
		QF(0xb38,int fb38)
		QF(0xba4,int fba4)
		QF(0xba8,QbHE fba8)
		QF(0xbb4,QbIntVec fbb4)
		QF(0xbc4,QbIntVec fbc4)
		QF(0x31c,int f31c)
		QF(0x320,int f320)
		QF(0x66c,QbHE f66c)
		QF(0x670,QbHE f670)
		QF(0x9a4,int f9a4)
		QF(0x9a8,int f9a8)
		QF(0x9ac,int f9ac)
		QF(0x9b0,int f9b0)
		QF(0x9b8,int f9b8)
		QF(0x9bc,QbHEs f9bc)
		QF(0x9d4,QbHEs f9d4)
		QF(0x9e8,QbHE f9e8)
		QF(0x9ec,int f9ec)
		QF(0xa0c,bool fa0c)
	};
	int getTurn464270();bool f715a70();bool f715920();void f72ed70(int);void f737100();void f737850();bool isVisible4631c0(const QbPoint&);
	bool f72a4d0(int,int,int,int,int);void displayFabricatorOverloadZap7273e0(const QbPoint&,QbHE);QbHandle addRecord777a20(QbHandle);void f74bdc0();QbHPLists&f463be0();QbPoint f6c6d10(QbPath&,const QbPoint&);const QbPoint&f462f60(QbHP);QbEntDef*selectRobotOfClass(int,int,int,int);QbHE placeEntity6c58c0(QbEntDef*,const QbPoint&,int,int,int,int,int);bool f6c65a0(QbHE,const string&,int);bool f4631f0(QbHE);void f74c7d0(QbHI,int);void f464cd0(QbHI);void f72f6b0();QbPoint f71d000(int);bool findPlaceableNear71c150(const QbPoint&,QbPoint&,int);QbPoint*f7141a0();QbHE f6c5dc0(const string&,const QbPoint&,int,int,int,int,int);void f7164a0(QbSpawnSet&);bool f71ef30(const QbPoint&,int);QbHE getPlayer4630f0();int f715380();QbPath*f462e10();void f749890();void f736fe0();void f7373c0();void f72e790(int);bool f463510(QbHE);int f463540(QbHE);void f72e9d0(QbHE);void f72ea10();void f737250();void f737c90();void f464b40(int);bool f4633c0(const QbPoint&);void f464bd0(int);bool f463160(const QbPoint&);void f736e40();QbHI f6c51d0(struct QbIRec*,QbHE,int,int);int f717d60();void f726320();void f7409f0(int);void f745e10();void f747860(int,int);void f7469f0();void f745950();void f7457f0();string f463060(const QbPoint&);bool f7380f0(int,int,QbHE);void f736270(const string&);bool f73d320(int,int,bool,int);int f73e5c0(int,QbStrList&);void f729de0();QbMarkerLists&f463ec0();void f740300(int);void f740fa0();void escort743350(int,int,int);void f72e8e0(int);QbHI f6c5400(QbItemInfo*,const QbPoint&);void f7329f0();void f714000(QbPath&);void f744010(int);bool f71ec60(const QbPoint&,QbPath);bool f71e970(const QbPoint&,QbPath,unsigned);void f73a490();void f73acc0(int,const QbPoint*);void f73c750();void f731b10(int);void f6c6700(QbHP,const string&,int);int f4638e0(int,int);QbHSq squad463890(int);QbPoint f714120(int);void f731680(int,const QbPoint*,int);bool f463380(int,int);bool f463400(QbHE);void f72ffe0(int);void f742270(int);void f74d660(const QbPoint&,int);void f731960();bool isVisible463190(int,int);void f741190();void f741610(int);void f6c6600(QbHE,const string&);void f739e50(int);void exiles6df0b0(int);int*f464590();bool*f4645b0();void removeEntity465750(QbHE);QbHI giveItem6c52b0(const string&,QbHE,int,int);void f4647d0(const QbPoint&);void f9e29b0(QbHPs&,QbHP);bool f71cfb0();void f465950(int,int,int);QbHE f715230(int,int);void f7243c0(int,int,int);bool findPropSpotNear71c3c0(const QbPoint&,QbPoint&,int);void f6c6b90(const QbPoint&,const string&,int,int);bool f716940(const QbPoint&,const void*,QbEntity*,int);QbZone*f462e30(const QbPoint&);
	void turnUpdate_74e750();
};
extern QbMap*qb_map_cefc4c;

QbNP::QbNP(int a,int b){x=a;y=b;}

void QbMap::turnUpdate_74e750()
{
	if(qb_cefb34)qb_f79a180();
	if(qb_cefb35)qb_f4f0a50();
	f320++;
	qb_cefd04.clear9b3560();
	f9b8=0;
	f9b0=0;
	f9ac=0;
	f9a8=0;
	f9a4=0;
	f9bc.clear9b73d0();
	f9e8.reset9b7270();
	f9ec=0;
	if(fa0c)
	{
		if(f715a70())fa0c=false;
		else
		{
			if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("cetGuardsRemaining_g"))==0)
			{
				qb_player_cf45d8.f77fbc0(0x12d);
				fa0c=false;
			}
		}
	}
	if(f320==2&&qb_d25740>=2)qb_player_cf45d8.f77fbc0(0);
	if(f31c==3)qb_player_cf45d8.f77fea0(0);
	if(!qb_cefb37)
	{
		qb_cefb37=true;
		PhysFScpp::QbIfs in((string()+"achievements.txt").c_str(),1,1);
		if(in.isOpen404af0())
		{
			string line;
			while(qb_getEncodedLine4074b0(&in,line,-1))
			{
				qb_removeChar408100(line,'\n');
				for(unsigned i=0;i<qb_achv_cf09a8.size();i++)
				{
					if(qb_achv_cf09a8[i]->name==line)
					{
						if(qb_player_cf45d8.isSlotEmpty46de40(i))
						{
							qb_player_cf45d8.f77fbc0(i);
							qb_logMessage404bf0("Retroactive Achievements","Added \""+qb_achv_cf09a8[i]->name+"\"");
						}
						else qb_logMessage404bf0("Retroactive Achievements","Ignored existing achievement \""+qb_achv_cf09a8[i]->name+"\"");
						goto found;
					}
				}
				qb_logWarning404e50("Retroactive Achievements","Unknown achievement: "+line);
found:
				line.clear();
			}
			in.close9c05e0();
		}
	}
	bool shown=false;
	switch(getTurn464270())
	{
	case 3:shown=qb_factory_cefaa8->showOnce793450(0,true,0,0,0);break;
	case 10:shown=qb_factory_cefaa8->showOnce793450(1,true,0,0,0);break;
	case 15:shown=qb_factory_cefaa8->showOnce793450(2,true,0,0,0);break;
	case 20:shown=qb_factory_cefaa8->showOnce793450(3,true,0,0,0);break;
	case 100:shown=qb_factory_cefaa8->showOnce793450(4,true,0,0,0);break;
	case 300:shown=qb_factory_cefaa8->showOnce793450(8,true,0,0,0);break;
	case 310:shown=qb_factory_cefaa8->showOnce793450(0xa,true,0,0,0);break;
	case 500:shown=qb_factory_cefaa8->showOnce793450(0xb,true,0,0,0);break;
	case 2000:shown=qb_factory_cefaa8->showOnce793450(0xc,true,0,0,0);break;
	case 3000:shown=qb_factory_cefaa8->showOnce793450(0xd,true,0,0,0);break;
	case 5000:shown=qb_factory_cefaa8->showOnce793450(0xe,true,0,0,0);break;
	case 5100:shown=qb_factory_cefaa8->showOnce793450(0x10,true,0,0,0);break;
	case 7000:shown=qb_factory_cefaa8->showOnce793450(0x11,true,0,0,0);break;
	case 8000:shown=qb_factory_cefaa8->showOnce793450(0x12,true,0,0,0);break;
	case 9000:shown=qb_factory_cefaa8->showOnce793450(0x15,qb_d25740>=15,0,0,0);break;
	case 10000:shown=qb_factory_cefaa8->showOnce793450(9,qb_d25740>=20,0,0,0);break;
	}
	if(!shown)shown=qb_factory_cefaa8->showOnce793450(0x46,qb_cf4898!=0||qb_cf4854!=0,0,0,0);
	if(!shown)shown=qb_factory_cefaa8->showOnce793450(0x47,qb_cf4920!=0,0,0,0);
	if(!shown)shown=qb_factory_cefaa8->showOnce793450(0x49,f715920(),0,0,0);
	if(!shown)shown=qb_factory_cefaa8->showOnce793450(0x4a,f715a70(),0,0,0);
	if(f320==1&&qb_d28d09&&qb_d22590[0x52]==0&&qb_cefc90==1)qb_factory_cefaa8->showOnce793450(0x52,true,0,0,0);
	if(f320>=2)
	{
		switch(qb_loc_d1e888->kind)
		{
		case 1:
			if(qb_factory_cefaa8->showOnce793450(0x50,!qb_cf474d&&!qb_d257d4&&!qb_tut_d25628.f7784b0(),0,1,0))qb_cf474d=true;
			break;
		case 2:qb_factory_cefaa8->showOnce793450(0x4f,qb_d25740==5,0,0,0);break;
		case 3:qb_factory_cefaa8->showOnce793450(0x4b,true,0,0,0);break;
		}
	}
	if(qb_say_cefb48&&f670.valid())
	{
		bool said=false;
		switch(f320)
		{
		case 1:
			said=qb_say_cefb48->f20!=4&&qb_say_cefb48->say49e250(5,0,qb_slotNames_d378d0[qb_say_cefb48->f20]);
			if(!said&&qb_say_cefb48)qb_say_cefb48->say49e250(1,0,qb_e_b9597b);
			break;
		case 3:
			if(qb_say_cefb48->f24!=4)
			{
				said=qb_say_cefb48->say49e250(7,0,qb_slotNames_d378d0[qb_say_cefb48->f24]);
				qb_say_cefb48->f24=4;
			}
			if(!said&&qb_say_cefb48)qb_say_cefb48->say49e250(2,0,qb_e_b95982);
			break;
		case 6:
			if(qb_say_cefb48&&qb_say_cefb48->canSay49e120(6))
			{
				int slot=qb_maxIndex9de560(f670->f45a840(),4);
				if(f670->f448fe0(slot)>=4)
				{
					do slot=rng.rangeInt(0,3.0f);
					while(f670->f448fe0(slot)>=4);
					said=qb_say_cefb48->say49e250(6,1,qb_slotNames_d378d0[slot]);
				}
			}
			break;
		case 8:
			switch(qb_loc_d1e888->kind)
			{
			case 3: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x49,0,qb_e_b95983);break;
			case 4: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x4a,0,qb_e_b95996);break;
			case 5: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x4b,0,qb_e_b95997);break;
			case 7: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x4c,0,qb_e_b959a3);break;
			case 8: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x4d,0,qb_e_b959aa);break;
			case 9: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x4e,0,qb_e_b959ab);break;
			case 10: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x4f,0,qb_e_b959ae);break;
			case 11: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x50,0,qb_e_b959af);break;
			case 13: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x51,0,qb_e_b959b2);break;
			case 14: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x52,0,qb_e_b959b3);break;
			case 15: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x53,0,qb_e_b959b6);break;
			case 16: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x54,0,qb_e_b959b7);break;
			case 17: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x55,0,qb_e_b959ba);break;
			case 18: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x56,0,qb_e_b959bb);break;
			case 19: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x57,0,qb_e_b959c3);break;
			case 20: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x58,0,qb_e_b959e9);break;
			case 21: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x59,0,qb_e_b959ea);break;
			case 22: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x5a,0,qb_e_b959eb);break;
			case 23: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x5b,0,qb_e_b95a49);break;
			case 24: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x5c,0,qb_e_b95a4a);f72ed70(0);break;
			case 25: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x5d,0,qb_e_b95a4b);break;
			case 26: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x5e,0,qb_e_b95a73);break;
			case 27: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x5f,0,qb_e_b95a82);break;
			case 28: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x60,0,qb_e_b95a83);break;
			case 29: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x61,0,qb_e_b95a8b);break;
			case 30: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x62,0,qb_e_b95a96);break;
			case 31: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x63,0,qb_e_b95a97);break;
			case 32: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x64,0,qb_e_b95a9f);break;
			case 33: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x65,0,qb_e_b95ab1);break;
			case 34: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x66,0,qb_e_b95ab2);break;
			case 35: if(qb_say_cefb48)qb_say_cefb48->say49e250(0x67,0,qb_e_b95ab3);break;
			}
			break;
		}
	}
	if(qb_comp_cf4ac8)qb_comp_cf4ac8->f7ab2b0();
	for(int i=0;i<9;i++)
	{
		for(unsigned j=0;j<f118[i].size();j++)
		{
			if((*qb_grid_cfd44c.atPoint(f118[i][j]))->getProp45d550().isNull())
			{
				qb_logError404f10("BS::turnUpdate()","Interactive machine prop at "+qb_pointToString40a4a0(f118[i][j])+"no longer exists, removing from records");
				qb_eraseStep9d7300(f118[i],j);
				continue;
			}
			(*qb_grid_cfd44c.atPoint(f118[i][j]))->getProp45d550()->machine45cb30()->f65c8a0();
		}
	}
	f737100();
	f737850();
	for(unsigned i=0;i<f1dc.size();i++)
	{
		f1dc[i]->f8--;
		if(f1dc[i]->f8==0)
		{
			if(f1dc[i]->h4.p())
			{
				qb_view_cec054->removeMarker49b400(f1dc[i]->h4->pos4184d0());
				f1dc[i]->h4->f45ce80(f1dc[i]->f0,0);
			}
			qb_deleteObjectAndStep9de640(f1dc,i);
		}
		else if(f1dc[i]->h4.p())
		{
			if(isVisible4631c0(f1dc[i]->h4->pos4184d0())&&f66c->f5d2380(0x1a).valid())
				qb_view_cec054->showTimer8176a0(1,f1dc[i]->h4->pos4184d0(),f1dc[i]->f8,0);
		}
		else qb_deleteObjectAndStep9de640(f1dc,i);
	}
	for(unsigned k=0;k<f278.size();k++)
	{
		if(!f278[k].p()||f278[k]->f457b10()!=3)qb_eraseStep9d6440(f278,k);
		else
		{
			QbHPs&v=qb_d31640[f278[k]->f44ab40()];
			QbArea areaRef(v[0]->pos4184d0(),v[0]->pos4184d0());
			for(unsigned m=1;m<v.size();m++)areaRef.include40bb90(v[m]->pos4184d0());
			areaRef.grow40bc10(5);
			areaRef.clamp40bc40(QbPoint(0,0),qb_grid_cfd44c.size9b7930());
			QbHEs list8;
			for(int x=areaRef.x1;x<=areaRef.x2;x++)
			{
				for(int y=areaRef.y1;y<=areaRef.y2;y++)
				{
					if((*qb_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&!qb_containsEntity9d31e0(list8,(*qb_grid_cfd44c.at(x,y))->getEntity45d250())&&rng.chance(15))
					{
						QbHE victim=(*qb_grid_cfd44c.at(x,y))->getEntity45d250();
						QbPoint b0;
						for(int t=0;t<5;t++)
						{
							b0=qb_randomRecord9dafb0(v)->pos4184d0();
							if(f72a4d0(0xf,b0.x,b0.y,x,y))
							{
								int dmg=victim->isPlayer5c7600()?qb_d2a4f4.random40c130():qb_d1f38c.random40c130();
								dmg=victim->f5cb570(3,1)*dmg/100;
								displayFabricatorOverloadZap7273e0(QbPoint(b0),victim);
								QB_MSG((victim->f45aaa0(f66c)?0x1c4:0x1c5,0,0,0,victim,QbHE(),&QbPoint(x,y),false));
								victim->f5defa0(dmg,1);
								list8.push_back(victim);
								if(victim->f5cab90()>=100&&victim->isHostileTo45aa70(f66c))f9d4.push_back(victim);
								if(!victim->isPlayer5c7600()&&rng.chance(qb_tbl_b9654c[qb_caf228]))
								{
									QbItems*inv=victim->getInventoryList45ab00();
									QbItems cands;
									for(unsigned n=0;n<inv->size();n++)
										if((*inv)[n]->info9b4350()->f1a8!=0&&(*inv)[n]->getType44aec0()<=3)cands.push_back((*inv)[n]);
									if(!cands.empty())
									{
										QbHI it=qb_randomRecord9dafb0(cands);
										QbExplDef*b5=it->info9b4350()->f1a8;
										QB_MSG((0x1a5,&it->getName571db0(0,0),0,0,QbHE(),QbHE(),&victim->f45a4c0(),false));
										qb_stats_d2c658.add4729d0(0x209,1,qb_e_b95abb,-1);
										if(qb_stats_d2c658.f472c70(0x209)>=15)qb_player_cf45d8.f77fbc0(0x9a);
										it->remove57dbe0(0,0,1,1);
										addRecord777a20(qb_factory_cefaa8->createA7930e0(new QbExplosion(QbHE(),b5,victim->f45a4c0(),QbHE(),QbPoint(-1),QbPoint(-1))));
									}
								}
								break;
							}
						}
					}
				}
			}
			if(!f278[k].p())qb_eraseStep9d6440(f278,k);
			else if(!list8.empty()&&rng.chance(5))
			{
				f278[k]->disableMachine65ed00();
				QB_MSG((0x1c6,0,0,0,QbHE(),QbHE(),&v[0]->pos4184d0(),false));
				qb_eraseStep9d6440(f278,k);
			}
		}
	}
	if(f2ac)
	{
		if(!f2ac->f6c2180())
		{
			delete f2ac;
			f2ac=0;
		}
		else if(f2ac->size()>=5&&getTurn464270()>=f2ac->f1c)
		{
			f74bdc0();
			string name=f288.pick9ba470()->name;
			qb_prelearnData797e60(name,1);
			f2ac->f10++;
			if(f2ac->f10>=f2ac->f14)
			{
				string msg("Data seek routine purged");
				QB_MSG((0x1d6,&string("SKIM"),&msg,0,QbHE(),QbHE(),0,false));
				qb_sound4541b0(0x35,0,0);
				for(unsigned i=0;i<f2ac->size();i++)
				{
					qb_f9d51d0((*f2ac)[i]->machine45cb30()->v40,6);
					(*f2ac)[i]->machine45cb30()->f28=-1;
					qb_removeProp9d2f00(qb_map_cefc4c->f463be0()[6],(*f2ac)[i]);
				}
				delete f2ac;
				f2ac=0;
			}
			else
			{
				qb_sound4541b0(0x34,0,0);
				int delay=f2ac->f20;
				delay+=qb_d2e214.random40c130()*(f2ac->f10>f2ac->f14/2+1?1:-1);
				f2ac->f1c=qb_map_cefc4c->getTurn464270()+qb_maxInt9cdb60(1,delay);
				f2ac->f20=delay;
			}
		}
	}
	if(!qb_d2a520.empty())
	{
		for(unsigned i=0;i<qb_d2a520.size();i++)
		{
			int e5=qb_d2a520[i];
			QbPend*aG=qb_cf44b0[e5];
			QbPath*pts2=&aG->pts;
			for(unsigned j=0;j<pts2->size();j++)
			{
				if((*qb_grid_cfd44c.atPoint((*pts2)[j]))->getProp45d550().isNull()||(*qb_grid_cfd44c.atPoint((*pts2)[j]))->getProp45d550()->f9b8f00()!=qb_cefbd4)
				{
					aG->f4=false;
					qb_eraseAt9ce6d0(qb_d2a520,i);
					goto next;
				}
			}
			for(unsigned j=0;j<pts2->size();j++)
				if((*qb_grid_cfd44c.atPoint((*pts2)[j]))->getEntity45d250().valid())goto next;
			QB_MSG((0x257,&qb_propDefs_cf35b0[aG->f0]->name,0,0,QbHE(),QbHE(),&(*pts2)[0],false));
			for(unsigned j=0;j<pts2->size();j++)
			{
				(*qb_grid_cfd44c.atPoint((*pts2)[j]))->getProp45d550()->f45ce10(1,0,1,QbHE());
				if((*qb_grid_cfd44c.atPoint((*pts2)[j]))->f45df50(qb_factory_cefaa8->createE793360(qb_propDefs_cf35b0[aG->f0])))
				{
					QbHP hp=(*qb_grid_cfd44c.atPoint((*pts2)[j]))->getProp45d550();
					hp->f45cc50((*pts2)[j]);
					hp->f44eb20(aG->v1c[j]);
					hp->f45cc70(aG->v2c[j]);
					hp->f45cca0(aG->v3c[j]);
				}
			}
			QbHPs*group=&qb_d31640[aG->f8];
			for(unsigned j=0;j<pts2->size();j++)
			{
				group->push_back((*qb_grid_cfd44c.atPoint((*pts2)[j]))->getProp45d550());
				group->back9b6540()->f451400(aG->f8);
			}
			if(qb_propDefs_cf35b0[aG->f0]->f15c!=0)
			{
				QbPoint p=f6c6d10(*pts2,QbPoint(-1));
				if(p.x==-1){}
				else qb_sound_d2d2a0.updatePropMute454520((*qb_grid_cfd44c.atPoint(p))->getProp45d550());
			}
			delete qb_cf44b0[e5];
			qb_cf44b0[e5]=0;
			qb_cefbb4--;
			qb_eraseAt9ce6d0(qb_d2a520,i);
				QbHEs*members=f4c[3]->members416f40();
				for(unsigned m=0;m<members->size();m++)
				{
					if((*members)[m]->ai45b590()->f9b8f00()==2)
					{
						QbPath*route=(*members)[m]->ai45b590()->f458ef0();
						for(unsigned q=0;q<route->size();q++)
						{
							if(!(*qb_grid_cfd44c.atPoint((*route)[q]))->isPassableFor66ab30(QbHE()))
							{
								(*members)[m]->ai45b590()->setPatrolRandom5b3430((*members)[m]->pos45a4a0());
								break;
							}
						}
					}
				}
			
next:;
		}
	}
	if(f234.valid())
	{
		if(!f234.p()||f234->f457b10()==1)f234.reset9b7270();
		else
		{
			bool go=f240!=0||f238==2||qb_distanceCeil40a3f0(f66c->pos45a4a0(),f234->pos4184d0())<=qb_tbl_b99d84[f238].v;
			if(go&&getTurn464270()>=f240)
			{
				QbPoint at=f462f60(f234);
				switch(f238)
				{
				case 0:
				{
					QbEntDef*def=selectRobotOfClass(3,0x3c,0,1);
					if(!def)
					{
						qb_logError404f10("BS::turnUpdate()","no Assembled data found");
						return;
					}
					int level5=qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("usedCoreResetMatrix_g"))?2:5;
					for(int n=0;n<qb_tbl_b99d94[f238].v;n++)
					{
						QbHE e=placeEntity6c58c0(def,at,level5,0,0x22,0xe,0);
						if(e.valid())
						{
							QB_MSG((0x1cd,0,0,0,e,QbHE(),&f234->pos4184d0(),false));
							f244.push_back(e);
						}
					}
					qb_sound454260(at,0x102);
					break;
				}
				case 1:
				{
					QbWL wl;
					wl.add9ba310(0xd,0x28);
					wl.add9ba310(0x10,0x28);
					wl.add9ba310(0x11,10);
					wl.add9ba310(0x12,10);
					QbHE gN;
					int nKind;QbEntDef*nDef;
					for(int n=0;n<qb_tbl_b99d94[f238].v;n++)
					{
						nKind=wl.pick9ba470();
						nDef=selectRobotOfClass(3,nKind,0,1);
						if(nDef)
						{
							QbHE e=placeEntity6c58c0(nDef,at,2,0,0x22,0xe,0);
							if(e.valid())
							{
								QB_MSG((0x1cd,0,0,0,e,QbHE(),&f234->pos4184d0(),false));
								f244.push_back(e);
								if(gN.valid())e->ai45b590()->setFollowEntity5b2f80(gN,0);
								else
								{
									gN=e;
									if(f240==0)f6c65a0(e,"T_Garrison_Derelicts",0);
								}
							}
						}
					}
					break;
				}
				case 2:
				{
					QbWL aE;
					aE.add9ba310(0x10,0x28);
					aE.add9ba310(0x18,0x1e);
					aE.add9ba310(0x3f,0x14);
					aE.add9ba310(0x19,10);
					QbEntDef*cmdr;
					qb_findByName9d7530(qb_entDefs_d25de0,"Commander",cmdr);
					QbEntDef*c5;
					QbHE leader;
					int tmpKind;
					for(int n=0;n<qb_tbl_b99d94[f238].v;n++)
					{
						tmpKind=aE.pick9ba470();
						if(n!=0)c5=selectRobotOfClass(3,tmpKind,0,1);
						else c5=cmdr;
						if(c5)
						{
							QbHE e=placeEntity6c58c0(c5,at,9,0,0x22,0xe,0);
							if(e.valid())
							{
								QB_MSG((0x1cd,0,0,0,e,QbHE(),&f234->pos4184d0(),false));
								f244.push_back(e);
								if(leader.valid())e->ai45b590()->setFollowEntity5b2f80(leader,0);
								else
								{
									leader=e;
									QbHEs targets;
									if(qb_cf64fc.get9b6570())targets.push_back(qb_cf64fc);
									QbRect r;
									qb_grid_cfd44c.getRect9b7ac0(qb_cf6518,10,10,r);
									for(int x=r.x;x<r.x2;x++)
										for(int y=r.y;y<r.y2;y++)
											if((*qb_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->isHostileTo45aa70(leader))
												targets.push_back((*qb_grid_cfd44c.at(x,y))->getEntity45d250());
									for(unsigned t=0;t<targets.size();t++)leader->ai45b590()->chase5b4710(targets[t],1,0,0,0);
									if(f240==0)f6c65a0(e,"T_Cargo_Ambush_Attack",0);
								}
							}
						}
					}
					break;
				}
				}
				f23c--;
				if(f240==0)
				{
					QbHPs&parts=qb_d31640[f234->f44ab40()];
					for(unsigned i=0;i<parts.size();i++)parts[i]->f452270(4);
					if(f23c!=2)
						qb_overmind_cf6428.spawnCarrier688e80(f234->pos4184d0(),f238==0?string("ALERT: Infestation at ")+f234->machine45cb30()->name65cc80()+", dispatching Demolisher response squad.":string("ALERT: Derelict incursion at ")+f234->machine45cb30()->name65cc80()+", dispatching Demolisher response squad.");
					do qb_logPhrase5141b0(f238+0x74,0,0,0,QbHE(),&f234->pos4184d0());while(false);
					if(qb_xom_d25450.active&&f238==0)qb_xom_d25450.f69e700(0x59,0,0.0f);
				}
				if(f23c==0)
				{
					QB_MSG((0x1ce,0,0,0,QbHE(),QbHE(),&f234->pos4184d0(),false));
					f234->disableMachine65ed00();
					f234.reset9b7270();
				}
				else f240=getTurn464270()+rng.rangeInt((float)qb_tbl_b99d8c[f238].v,(float)qb_tbl_b99d90[f238].v);
				f254=getTurn464270()+20;
			}
		}
	}
	if(getTurn464270()==f254)
	{
		QbHE leader;
		int count=0;
		for(unsigned i=0;i<f244.size();i++)
		{
			if(f244[i].get9b6570())
			{
				leader=f244[i]->ai45b590()->getFollow458ed0();
				f244[i]->setAI64ecf0(new QbAIObj(f244[i],0x1a,0xe));
				if(leader.valid())f244[i]->ai45b590()->setFollowEntity5b2f80(leader,0);
				if(count<2)
				{
					if((count==0||f4631f0(f244[i]))&&f6c65a0(f244[i],"T_Cargo_Ambush_Retreat",0))count++;
				}
			}
		}
		f244.clear9b73d0();
		f254=0;
	}
	if(!f178.empty())
	{
		for(unsigned i=0;i<f178.size();i++)
		{
			if(rng.chance(0x21))
			{
				if(f178[i].p())
				{
					QB_MSG((0x1ba,&f178[i]->getName45c5b0(),0,0,QbHE(),QbHE(),&f178[i]->pos4184d0(),false));
					f178[i]->f45ce10(0,1,0,f188[i].get9b6570()?f188[i]:QbHE());
				}
				qb_eraseAt9da940(f188,i);
				qb_eraseStep9d6440(f178,i);
			}
		}
	}
	if(!f198.empty())
	{
		for(unsigned i=0;i<f198.size();i++)
		{
			if(rng.chance(0x21))
			{
				if((*qb_grid_cfd44c.atPoint(f198[i]))->terrain9fcd80()->f50->f4c)
				{
					QB_MSG((0x1ba,(*qb_grid_cfd44c.atPoint(f198[i]))->name45d140(),0,0,QbHE(),QbHE(),&f198[i],false));
					(*qb_grid_cfd44c.atPoint(f198[i]))->trigger45e110(0,0,f1a8[i].get9b6570()?f1a8[i]:QbHE());
				}
				qb_eraseAt9da940(f1a8,i);
				qb_eraseStep9d7300(f198,i);
			}
		}
	}
	if(f320%15==0&&qb_loc_d1e888->kind==3)
	{
		for(unsigned i=0;i<qb_d20248.size9b5100();i++)
		{
			if(!qb_d20248[i].empty()&&qb_d20248[i][0]->f45cb90(0xe))
			{
				for(unsigned j=0;j<qb_d20248[i].size();j++)
				{
					if((*qb_grid_cfd44c.atPoint(qb_d20248[i][j]->pos4184d0()))->getEntity45d250().valid())
					{
						QbHE e=(*qb_grid_cfd44c.atPoint(qb_d20248[i][j]->pos4184d0()))->getEntity45d250();
						if((e->getTarget45a760()==4||e->getTarget45a760()==3)&&e->getSize45a360()==1&&!e->f45ac40(0x33))
						{
							QB_MSG((0x21e,&string("A hatch slides open and sucks %2 into the floor."),&e->name416f40(),0,QbHE(),QbHE(),&qb_d20248[i][j]->pos4184d0(),false));
							if(isVisible4631c0(qb_d20248[i][j]->pos4184d0()))qb_d20248[i][j]->f65f170();
							qb_sound454260(qb_d20248[i][j]->pos4184d0(),0x9f);
							for(unsigned k=0;k<f20.size();k++)
							{
								if(f20[k]->f0==i)
								{
									f20[k]->add460a00(e);
									e->f637bb0();
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	qb_zion_d1dd38.newTurn6bf880();
	if(!f118[1].empty())
		for(unsigned i=0;i<f118[1].size();i++)
			if(isVisible4631c0(f118[1][i])&&(*qb_grid_cfd44c.atPoint(f118[1][i]))->getProp45d550()->machine45cb30()->f38!=0)
				qb_view_cec054->showTimer8176a0(0,f118[1][i],-1,0);
	if(!f118[2].empty())
		for(unsigned i=0;i<f118[2].size();i++)
			if(isVisible4631c0(f118[2][i])&&(*qb_grid_cfd44c.atPoint(f118[2][i]))->getProp45d550()->machine45cb30()->f38!=0)
				qb_view_cec054->showTimer8176a0(0,f118[2][i],-1,0);
	if(qb_cf4b20&&!f118[3].empty())
		for(unsigned i=0;i<f118[3].size();i++)
			if(isVisible4631c0(f118[3][i])&&(*qb_grid_cfd44c.atPoint(f118[3][i]))->getProp45d550()->machine45cb30()->f38!=0)
				qb_view_cec054->showTimer8176a0(0,f118[3][i],-1,0);
	if(!f118[5].empty()&&(f66c->f5d2380(0xc).valid()||f66c->f5d2380(0xd).valid()))
		for(unsigned i=0;i<f118[5].size();i++)
			if(isVisible4631c0(f118[5][i])&&(*qb_grid_cfd44c.atPoint(f118[5][i]))->getProp45d550()->machine45cb30()->f38!=0)
				qb_view_cec054->showTimer8176a0(0,f118[5][i],-1,0);
	for(unsigned i=0;i<f1b8.size();i++)
	{
		if(isVisible4631c0(f1b8[i]->pos)&&((*qb_grid_cfd44c.atPoint(f1b8[i]->pos))->getProp45d550().isNull()||(*qb_grid_cfd44c.atPoint(f1b8[i]->pos))->getProp45d550()->f457b10()!=0))
			qb_deleteObjectAndStep9de5c0(f1b8,i);
		else if(getTurn464270()>=f1b8[i]->fc)
		{
			if(!isVisible4631c0(f1b8[i]->pos)&&(f1b8[i]->f8!=1||f1b8[i]->f8==1&&f268[7].empty()))
			{
				string kind;
				int phrase;
				switch(f1b8[i]->f8)
				{
				case 1:kind="FABRICATOR";phrase=0x24;break;
				case 2:kind="REPAIR";phrase=0x26;break;
				case 3:kind="RECYCLER";phrase=0x28;break;
				default:kind="ERR";phrase=0x24;break;
				}
				string msg5=f1b8[i]->f8==3?f1b8[i]->name+" arrived?":"Completed "+f1b8[i]->name+"?";
				QB_MSG((0x1d7,&kind,&msg5,0,QbHE(),QbHE(),0,false));
				do qb_logPhrase5141b0(phrase,&f1b8[i]->name,0,0,QbHE(),0);while(false);
			}
			qb_deleteObjectAndStep9de5c0(f1b8,i);
		}
		else if(!isVisible4631c0(f1b8[i]->pos))qb_view_cec054->showTimer8176a0(0,f1b8[i]->pos,-1,f1b8[i]);
	}
	if(f3d4)
	{
		QbPoint interval(8,0xc);
		const int itemChance=0x19;
		QbPoint itemDelay(5,0xf);
		const int a9=10;
		QbPoint b4(3,6);
		const int propChance=2;
		QbPoint a7(1,10);
		const int cC=5;
		QbPoint cellDelay(1,10);
		for(unsigned i=0;i<f470.size();i++)
		{
			if(f320==f470[i])
			{
				if((*qb_grid_cfd44c.atPoint(f460[i]))->f45db70())
				{
					QB_MSG((0x1b1,(*qb_grid_cfd44c.atPoint(f460[i]))->name45d140(),0,0,QbHE(),QbHE(),&f460[i],false));
					qb_sound454260(f460[i],0xa7);
					(*qb_grid_cfd44c.atPoint(f460[i]))->trigger45e110(1,0,QbHE());
				}
				qb_eraseAt9d5190(f460,i);
				qb_eraseAt9ce6d0(f470,i);
			}
		}
		for(unsigned i=0;i<f450.size();i++)
		{
			if(f320==f450[i])
			{
				if(f440[i].p()&&f440[i]->f65e280())
				{
					QB_MSG((0x1b0,&f440[i]->getName45c5b0(),0,0,QbHE(),QbHE(),&f440[i]->pos4184d0(),false));
					qb_sound454260(f440[i]->pos4184d0(),0xa7);
					f440[i]->f45ce10(1,0,0,QbHE());
				}
				qb_eraseAt9da940(f440,i);
				qb_eraseAt9ce6d0(f450,i);
			}
		}
		for(unsigned i=0;i<f420.size();i++)
		{
			if(f320==f420[i])
			{
				if(f410[i].get9b6570()&&f410[i]->f5d0f60())
				{
					QB_MSG((f410[i]->f45aaa0(f66c)?0x1af:0x1ae,0,0,0,f410[i],QbHE(),&f410[i]->pos45a4a0(),false));
					f410[i]->die633790(!f4631f0(f410[i]),0xa,QbHE(),1,0,0,0,0);
				}
				qb_eraseAt9da940(f410,i);
				qb_eraseAt9ce6d0(f420,i);
			}
		}
		for(unsigned i=0;i<f400.size();i++)
		{
			if(f320==f400[i])
			{
				if(f3f0[i].p()&&f3f0[i]->f577b80())f74c7d0(f3f0[i],1);
				qb_eraseAt9da940(f3f0,i);
				qb_eraseAt9ce6d0(f400,i);
			}
		}
		if(f320>=f3ec)
		{
			for(int x=0;x<qb_grid_cfd44c.width9fcd80();x++)
			{
				for(int y=0;y<qb_grid_cfd44c.height9b8f00();y++)
				{
					if(*f3d4->at(x,y)!=0)
					{
						if((*qb_grid_cfd44c.at(x,y))->getItem45d8f0().valid()&&(*qb_grid_cfd44c.at(x,y))->getItem45d8f0()->f577b80()&&rng.chance(itemChance)&&!qb_containsEntity9d31e0(f3f0,(*qb_grid_cfd44c.at(x,y))->getItem45d8f0()))
						{
							f3f0.push_back((*qb_grid_cfd44c.at(x,y))->getItem45d8f0());
							f400.push_back(itemDelay.random40c130()+f320);
						}
						if((*qb_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->f5d0f60()&&!qb_containsEntity9d31e0(f430,(*qb_grid_cfd44c.at(x,y))->getEntity45d250())&&!qb_containsEntity9d31e0(f410,(*qb_grid_cfd44c.at(x,y))->getEntity45d250()))
						{
							if(!rng.chance(a9))f430.push_back((*qb_grid_cfd44c.at(x,y))->getEntity45d250());
							else
							{
								f410.push_back((*qb_grid_cfd44c.at(x,y))->getEntity45d250());
								f420.push_back(b4.random40c130()+f320);
							}
						}
						if((*qb_grid_cfd44c.at(x,y))->getProp45d550().valid()&&(*qb_grid_cfd44c.at(x,y))->getProp45d550()->f65e280()&&rng.chance(propChance)&&!qb_containsEntity9d31e0(f440,(*qb_grid_cfd44c.at(x,y))->getProp45d550()))
						{
							f440.push_back((*qb_grid_cfd44c.at(x,y))->getProp45d550());
							f450.push_back(a7.random40c130()+f320);
						}
						if((*qb_grid_cfd44c.at(x,y))->f45db70()&&rng.chance(cC)&&!qb_f9d0ce0(f460,QbPoint(x,y)))
						{
							f460.push_back(QbPoint(x,y));
							f470.push_back(cellDelay.random40c130()+f320);
						}
					}
				}
			}
			f3ec=interval.random40c130()+f320;
		}
		if(!f3d8.empty())
		{
			int chance=qb_maxInt9cdb60(1,11-f3d8.size())*5;
			QbPath gi;
			QbIntList i8;
			for(int i=f3d8.size()-1;i>=0;i--)
			{
				if(rng.chance(chance))
				{
					qb_shuffle9d7350(gi);
					qb_getSurrounding4faaf0(f3d8[i],gi);
					for(unsigned j=0;j<gi.size();j++)
					{
						if(*f3d4->atPoint(gi[j])==0&&((*qb_grid_cfd44c.atPoint(gi[j]))->f4550b0()||(*qb_grid_cfd44c.atPoint(gi[j]))->f45db70()))
						{
							*f3d4->atPoint(gi[j])=1;
							f3d8.push_back(gi[j]);
							f3e8++;
							goto spread;
						}
					}
					i8.push_back(i);
				}
spread:;
			}
			if(!i8.empty())
				for(unsigned k=0;k<i8.size();k++)qb_eraseAt9d5190(f3d8,i8[k]);
		}
	}
	if(!f480.empty())
	{
		for(unsigned i=0;i<f480.size();i++)
		{
			if(!f480[i].p()||f480[i]->f45cb30()<0)
			{
				f464cd0(f480[i]);
				i--;
			}
			else if(f480[i]->f458530())
			{
				QbPoint at=f480[i]->pos575920();
				QB_MSG((0xcd,&f480[i]->getName571db0(0,0),0,0,QbHE(),QbHE(),&at,false));
				if(f480[i]->getEffect457b70(0x58))qb_stats_d2c658.add4729d0(0x259,1,qb_e_b95ac3,-1);
				bool a0=f480[i]->f457f90()==0xd0;
				QbExplDef*expl=a0?f480[i]->info9b4350()->f1a0:f480[i]->info9b4350()->f1a8;
				qb_view_cec054->removeMarker49b400(f480[i]->pos575920());
				f480[i]->remove57dbe0(1,0,1,1);
				if(expl==0){}
				else
				{
					if(qb_xom_d25450.active&&expl->f30>=500&&a0)qb_d254f0=expl->id;
					addRecord777a20(qb_factory_cefaa8->createA7930e0(new QbExplosion(QbHE(),expl,at,QbHE(),QbPoint(-1),QbPoint(-1))));
				}
				qb_eraseStep9d6440(f480,i);
			}
			else
			{
				if(isVisible4631c0(f480[i]->pos575920()))qb_view_cec054->showTimer8176a0(1,f480[i]->pos575920(),f480[i]->f45cb30(),0);
				switch(qb_loc_d1e888->kind)
				{
				case 8:case 11:case 21:
					f8a8=2;
					f8ac=true;
					break;
				case 10:
					if(qb_d1eaf8.contains40b750(f480[i]->pos575920())&&qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("a"))==0)qb_map_cefc4c->f72f6b0();
					break;
				case 20:
					if(f480[i]->pos575920().x<=100)
					{
						f8a8=2;
						f8ac=true;
					}
					break;
				case 23:
					if(f480[i]->pos575920().x<0x4b)
					{
						f8a8=2;
						f8ac=true;
					}
					break;
				}
			}
		}
	}
	if(!f490.empty())
	{
		for(unsigned i=0;i<f490.size();i++)
		{
			if(!f490[i].p())
			{
				qb_eraseAt9da940(f490,i);
				qb_eraseAt9ce6d0(f4a0,i);
			}
			else if(f320>=f4a0[i])
			{
				QbPoint spawn=qb_map_cefc4c->f71d000(5);
				if(spawn.x==-1)
				{
					QbIntList radii;
					radii.push_back(0x19);
					radii.push_back(100);
					QbRect oldArea;
					for(unsigned r=0;r<radii.size();r++)
					{
						qb_grid_cfd44c.getRect9b4430(f66c->pos45a4a0(),radii[r],oldArea);
						QbPoint p;
						QbPath path2;
						for(int t=0;t<250;t++)
						{
							oldArea.randomPoint40be30(&p);
							if(!isVisible4631c0(p)&&(*qb_grid_cfd44c.atPoint(p))->canPlace66ad20(1)&&qb_carto_cfe568.findPath40c9a0(p,f66c->pos45a4a0(),qb_cefc30,0,path2))
							{
								spawn=p;
								break;
							}
						}
					}
				}
				if(spawn.x!=-1)
				{
					QbEntDef*def;
					qb_findByName9d7530(qb_entDefs_d25de0,"Ranger_DRS",def);
					if(def)
					{
						QbHE leader;
						QbRect zone;
						qb_grid_cfd44c.getRect9b4430(f490[i]->pos575920(),0xf,zone);
						for(int n=rng.rangeInt(3.0f,4.0f);n>0;n--)
						{
							QbHE e=placeEntity6c58c0(def,spawn,10,0,0x22,0xe,0);
							e->ai45b590()->f459470(zone);
							if(leader.valid())e->ai45b590()->setFollowEntity5b2f80(leader,0);
							else
							{
								leader=e;
								f6c65a0(leader,"DRS_Beacon_Squad_leader",0);
							}
						}
						qb_eraseAt9da940(f490,i);
						qb_eraseAt9ce6d0(f4a0,i);
					}
				}
			}
		}
	}
	for(unsigned i=0;i<f1ec.size();i++)
	{
		f1ec[i]->fc--;
		if(f1ec[i]->fc==0)
		{
			if(f1ec[i]->h0.get9b6570())
			{
				QbHE e0=f1ec[i]->h0;
				QbPoint from=e0->pos45a4a0();
				QbPoint to;
				if(findPlaceableNear71c150(f1ec[i]->f4,to,1))
				{
					bool placed=qb_xom_d25450.placeEntityNear6bd410(0,to,e0,0,1);
					if(placed)qb_xom_d25450.showShift6bd6d0(from,e0);
				}
				else f1ec[i]->fc++;
			}
			if(f1ec[i]->fc==0)qb_deleteObjectAndStep9de640(f1ec,i);
		}
	}
	if(qb_d1eb60!=-1&&getTurn464270()>=qb_d1eb60)
	{
		QbHEs squad;
		QbHEs*members=f4c[2]->members416f40();
		for(unsigned i=0;i<members->size();i++)
			if((*members)[i]->f45acb0(0x34))squad.push_back((*members)[i]);
		QbHI rod=f66c->f5d2380(0xb2);
		if(rod.isNull()||rod->f577a90()<qb_cf1f1c.x)
		{
			for(unsigned i=0;i<squad.size();i++)
			{
				squad[i]->f5dcc70(9,1);
				squad[i]->f6396f0("SCR_Call_Wizard_Arrive",1);
				squad[i]->f6396f0("SCR_Call_Wizard_Talk",1);
			}
			QbPoint*dest=f7141a0();
			if(dest==0)
			{
				for(unsigned i=0;i<squad.size();i++)
				{
					squad[i]->ai45b590()->f459470(qb_grid_cfd44c.getArea9b4400());
					squad[i]->ai45b590()->setFollowEntity5b2f80(i==0?QbHE():squad[0],0);
				}
			}
			else
			{
				for(unsigned i=0;i<squad.size();i++)
				{
					squad[i]->ai45b590()->f4582d0(0x19);
					squad[i]->ai45b590()->f459540(*dest);
					squad[i]->ai45b590()->setFollowEntity5b2f80(QbHE(),0);
				}
			}
		}
		else if(qb_tbl_b90f38[qb_loc_d1e888->kind]!=0&&qb_d1eb64<qb_tbl_b90f38[qb_loc_d1e888->kind]&&squad.size()<4&&rng.chance(0x14))
		{
			int room=qb_minInt9cdb30(qb_tbl_b90f38[qb_loc_d1e888->kind]-qb_d1eb64,4-squad.size());
			int count=qb_minInt9cdb30(qb_d2e21c.random40c130(),room);
			if(count<1){}
			else
			{
				QbPoint at=f71d000(10);
				if(at.x!=-1)
				{
					for(int k=0;k<count;k++)
					{
						QbHE w=f6c5dc0("Wizard_7",at,2,0,0x16,0xe,0);
						if(w.valid())
						{
							qb_map_cefc4c->f6c65a0(w,"SCR_Call_Wizard_Arrive",0);
							w->f45b340(new QbNP(qb_d2f0f8[0x34],1));
							w->ai45b590()->setFollowEntity5b2f80(f66c,0);
							if(k==0)qb_map_cefc4c->f6c65a0(w,"SCR_Call_Wizard_Talk",0);
							squad.push_back(w);
							qb_d1eb64++;
						}
					}
				}
			}
		}
		qb_d1eb60=getTurn464270()+qb_cf1f1c.random40c130();
	}
	f7164a0(f5ec);
	f7164a0(qb_cf6adc);
	if(qb_xom_d25450.active&&qb_d25618!=0&&qb_loc_d1e888->f8==qb_d25618&&qb_loc_d1e888->inRange46ecb0())
	{
		QbHE wyrm=qb_xom_d25450.findXom6be1d0();
		if(wyrm.valid())
		{
			if(f320>=20&&rng.chance(7)&&f4631f0(wyrm))
			{
				QbItems*inv=wyrm->getInventoryList45ab00();
				for(unsigned i=0;i<inv->size();i++)
				{
					if((*inv)[i]->info9b4350()==qb_cefbf4)
					{
						if(f71ef30(wyrm->pos45a4a0(),1))
						{
							string msg="Chaos Wyrm sheds "+(*inv)[i]->getName571db0(0,0)+".";
							qb_message49c610(0x320,QbHE(),msg,0);
							(*inv)[i]->f57a0f0(wyrm->pos45a4a0(),1,0);
						}
						break;
					}
				}
				QbPoint pos2=wyrm->pos45a4a0();
				wyrm->f637bb0();
				wyrm=qb_map_cefc4c->f6c5dc0("Greater Chaos Wyrm",pos2,2,0,0x22,0xe,0);
				wyrm->f639530(0x3a,1);
				wyrm->ai45b590()->setFollowEntity5b2f80(qb_map_cefc4c->getPlayer4630f0(),0);
				qb_xom_d25450.showXomAct6bdb50(false,wyrm,0);
				qb_xom_d25450.giveXomItems6be2f0(wyrm);
				qb_message49c610(0x320,QbHE(),string("Chaos Wyrm writhes in painful ecstasy as it mutates into a greater form."),0);
				do qb_logPhrase5141b0(0xc2,&string("Chaos Wyrm"),&wyrm->name416f40(),0,QbHE(),0);while(false);
				qb_player_cf45d8.f77fbc0(0x161);
				qb_d25618=0;
			}
		}
		else qb_d25618=0;
	}
	if(qb_cf462c==6)
	{
		if(f715380()==0&&f462e10()->empty())f749890();
		if(!fb70.empty())
		{
			for(unsigned i=0;i<fb70.size();i++)
			{
				if(fb70[i].get9b6570())
				{
					QbHE e=fb70[i];
					if(e->getSlotTotal45a860()<0x1a)
					{
						int slot=rng.rangeInt(0,3.0f);
						if(e->isPlayer5c7600())
						{
							e->f5c94e0(slot,QbHE());
							qb_sound4541b0(0xc8,0,0);
							if(slot==3&&f66c->f448fe0(3)>=7)qb_player_cf45d8.f77fbc0(0x8b);
						}
						else e->f45a840()[slot]++;
					}
				}
			}
			fb70.clear9b73d0();
		}
		for(int x=0;x<qb_grid_cfd44c.width9fcd80();x++)
		{
			for(int y=0;y<qb_grid_cfd44c.height9b8f00();y++)
			{
				if(*fb80->at(x,y)!=0&&rng.chance(0x21))
				{
					(*fb80->at(x,y))++;
					if((*qb_grid_cfd44c.at(x,y))->getItem45d8f0().valid()&&rng.chance(*fb80->at(x,y)*5))
					{
						qb_view_cec054->f8195a0(QbPoint(x,y),(*qb_grid_cfd44c.at(x,y))->getItem45d8f0()->f457a30(),0);
						(*qb_grid_cfd44c.at(x,y))->getItem45d8f0()->remove57dbe0(0,0,1,1);
					}
					if((*qb_grid_cfd44c.at(x,y))->getProp45d550().valid()&&(*qb_grid_cfd44c.at(x,y))->getProp45d550()->f9b8f00()->f8c!=0&&rng.chance(*fb80->at(x,y)*5))
						(*qb_grid_cfd44c.at(x,y))->getProp45d550()->f45ce10(0,1,0,QbHE());
				}
			}
		}
		QbPath around;
		QbIntList j4;
		for(int i=fb84.size()-1;i>=0;i--)
		{
			if(rng.chance(5))
			{
				qb_shuffle9d7350(around);
				qb_getSurrounding4faaf0(fb84[i],around);
				for(unsigned j=0;j<around.size();j++)
				{
					if(*fb80->atPoint(around[j])==0&&((*qb_grid_cfd44c.atPoint(around[j]))->f4550b0()||(*qb_grid_cfd44c.atPoint(around[j]))->f45db70())&&!qb_cf4da4.containsPos40aa00(around[j]))
					{
						*fb80->atPoint(around[j])=1;
						fb84.push_back(around[j]);
						goto spread2;
					}
				}
				j4.push_back(i);
			}
spread2:;
		}
		if(!j4.empty())
			for(unsigned k=0;k<j4.size();k++)qb_eraseAt9d5190(fb84,j4[k]);
		for(unsigned s=0;s<f4c.size();s++)
		{
			QbHEs*members=f4c[s]->members416f40();
			for(unsigned j=0;j<members->size();j++)(*members)[j]->f45b210(*fb80->atPoint((*members)[j]->pos45a4a0()));
		}
	}
	for(unsigned s=0;s<f4c.size();s++)
	{
		QbHEs*members=f4c[s]->members416f40();
		for(unsigned j=0;j<members->size();j++)(*members)[j]->turnUpdate610430();
	}
	if(f66c->f490840()==0)return;
	f736fe0();
	f7373c0();
	for(unsigned i=0;i<f6b8.size();i++)
	{
		if(!f6b8[i].get9b6570())qb_eraseStep9d6440(f6b8,i);
		else if(!f6b8[i]->ai45b590()->f459090())qb_eraseStep9d6440(f6b8,i);
		else
		{
			QbFeed*feed=f6b8[i]->ai45b590()->f4590f0()->f458950(0x32);
			if(feed==0){}
			else if(getTurn464270()>feed->f4)
			{
				string msg="Feed transfer from "+f6b8[i]->name416f40()+" reset";
				QB_MSG((0x1d6,&string(qb_str_cfc9d8),&msg,0,QbHE(),QbHE(),0,false));
				f72e790(f4c[0]->members416f40()->size()+i);
				i--;
			}
			else if(f6b8[i]->getTarget45a760()!=0||qb_distanceCeil40a3f0(f66c->pos45a4a0(),f6b8[i]->pos45a4a0())>0x14)
			{
				string msg="Feed link from "+f6b8[i]->name416f40()+" lost";
				QB_MSG((0x1d6,&string(qb_str_cfc9d8),&msg,0,QbHE(),QbHE(),0,false));
				f72e790(f4c[0]->members416f40()->size()+i);
				i--;
			}
		}
	}
	if(qb_rifLevels_cf4a04[0xb]!=0)
	{
		if(f66c->f5d4100())
		{
			for(unsigned i=0;i<f6c8.size();i++)
			{
				if(f6c8[i]->getTarget45a760()!=0||qb_distanceCeil40a3f0(f66c->pos45a4a0(),f6c8[i]->pos45a4a0())>0x16)
				{
					string msg="Feed link from "+f6c8[i]->name416f40()+" lost";
					QB_MSG((0x1d6,&string(qb_str_d2a414),&msg,0,QbHE(),QbHE(),0,false));
					f72e790(f4c[0]->members416f40()->size()+f6b8.size());
					i--;
				}
			}
			QbHEs*members=f4c[3]->members416f40();
			for(unsigned j=0;j<members->size();j++)
			{
				if((*members)[j]->getFaction45a2c0()==0xc&&(*members)[j]->getTarget45a760()==0&&!qb_containsEntity9d31e0(f6c8,(*members)[j])&&qb_distanceCeil40a3f0(f66c->pos45a4a0(),(*members)[j]->pos45a4a0())<=0x16)
				{
					if(f463510((*members)[j]))f72e790(f463540((*members)[j]));
					f72e9d0((*members)[j]);
					string msg="Established visual feed link with "+(*members)[j]->name416f40();
					QB_MSG((0x1d6,&string(qb_str_d2a414),&msg,0,QbHE(),QbHE(),0,false));
				}
			}
		}
		else if(!f6c8.empty())f72ea10();
	}
	if(f320%20==0)
	{
		for(int k=1;k<0x11;k++)
		{
			if(!qb_flags_cec0cc->isSet48f8d0(k))
			{
				for(unsigned j=0;j<f7e0[k].size();j++)
					if(isVisible4631c0(f7e0[k][j]->pos))qb_eraseStep9d6440(f7e0[k],j);
			}
		}
		if(!qb_flags_cec0cc->isSet48f8d0(0))
		{
			for(unsigned j=0;j<f7e0[0].size();j++)
				if(isVisible4631c0(f7e0[0][j]->pos)&&qb_removePoint9d3060(f138,f7e0[0][j]->pos))qb_eraseStep9d6440(f7e0[0],j);
		}
	}
	if(!qb_cf4aa8.empty())
	{
		for(unsigned i=0;i<qb_cf4aa8.size();i++)
		{
			if(!qb_cf4aa8[i].get9b6570())
			{
				qb_eraseAt9da940(qb_cf4aa8,i);
				qb_eraseAt9ce6d0(qb_cf4ab8,i);
			}
			else if(getTurn464270()>=qb_cf4ab8[i])
			{
				if(qb_map_cefc4c->f4631f0(qb_cf4aa8[i]))
				{
					string msg=qb_cf4aa8[i]->name416f40()+" disintegrates.";
					qb_message49c610(0x320,QbHE(),msg,0);
					qb_sound454260(qb_cf4aa8[i]->pos45a4a0(),0xc0);
				}
				qb_cf4aa8[i]->f637bb0();
				qb_eraseAt9da940(qb_cf4aa8,i);
				qb_eraseAt9ce6d0(qb_cf4ab8,i);
			}
			else if(qb_f9d43b0(qb_tbl_ba0b64,3,qb_cf4ab8[i]-getTurn464270()))
			{
				int left=qb_cf4ab8[i]-getTurn464270();
				qb_view_cec054->showTimer8176a0(5,qb_cf4aa8[i]->pos45a4a0(),left,0);
				qb_view_cec054->overlay49b050()->h1c=qb_cf4aa8[i];
				qb_view_cec054->overlay49b050()->p14=QbPoint(1,0);
				qb_view_cec054->overlay49b050()->p28=0;
				qb_view_cec054->overlay49b050()->f30=true;
			}
		}
	}
	f737250();
	f737c90();
	if(!f340.empty())
	{
		bool remove;
		for(unsigned i=0;i<f340.size();i++)
		{
			remove=false;
			if(!f340[i].p()||f340[i]->getType44aec0()!=5)remove=true;
			else if(f320>=f350[i])
			{
				QbHI target;
				QbRect k5;
				QbPoint at5=f340[i]->pos575920();
				qb_grid_cfd44c.getRect9b4430(at5,0xf,k5);
				for(int x=k5.x;x<k5.x2;x++)
				{
					for(int y=k5.y;y<k5.y2;y++)
					{
						if((*qb_grid_cfd44c.at(x,y))->getItem45d8f0().valid()&&qb_distance406480(at5.x,at5.y,x,y)<=0xf&&(*qb_grid_cfd44c.at(x,y))->getItem45d8f0()->getEffect457b70(0x48)&&(*qb_grid_cfd44c.at(x,y))->getItem45d8f0()->getEffect457b70(0x53))
						{
							target=(*qb_grid_cfd44c.at(x,y))->getItem45d8f0();
							goto found2;
						}
					}
				}
found2:
				if(target.valid())
				{
					QB_MSG((0x1aa,&f340[i]->getName571db0(0,0),&target->getName571db0(0,0),0,QbHE(),QbHE(),&at5,false));
					qb_stats_d2c658.add4729d0(0xdb,1,qb_e_b95acb,-1);
				}
				else if(rng.chance(f360[i]))
				{
					QB_MSG((0x1a9,&f340[i]->getName571db0(0,0),0,0,QbHE(),QbHE(),&at5,false));
					qb_stats_d2c658.add4729d0(0xdb,1,qb_e_b95ad7,-1);
				}
				else
				{
					QB_MSG((0x1a8,&f340[i]->getName571db0(0,0),0,0,QbHE(),QbHE(),&at5,false));
					qb_stats_d2c658.add4729d0(0xda,1,qb_e_b95ae2,-1);
					qb_sound454260(at5,0xa5);
					qb_sound454260(at5,0xa5);
					qb_view_cec054->f8195a0(at5,f340[i]->f457a30(),0);
					f340[i]->remove57dbe0(0,0,1,1);
				}
				remove=true;
			}
			if(remove)
			{
				f464b40(i);
				i--;
			}
		}
	}
	if(!f370.empty()&&qb_cf462c!=6)
	{
		bool hacked=qb_cf462c==0xb;
		int aK=hacked?2:2;
		int chanceB=hacked?0x50:0x50;
		bool removeD;
		for(unsigned i=0;i<f370.size();i++)
		{
			removeD=false;
			if(!f370[i].p()||f370[i]->getType44aec0()!=5)removeD=true;
			else if(rng.chance(aK)&&(!f4633c0(f370[i]->pos575920())||!rng.chance(chanceB))&&((*qb_grid_cfd44c.atPoint(f370[i]->pos575920()))->getEntity45d250().isNull()||!(*qb_grid_cfd44c.atPoint(f370[i]->pos575920()))->getEntity45d250()->isPlayer5c7600()))
			{
				QbPoint at=f370[i]->pos575920();
				QB_MSG((0x2fb,&f370[i]->getName571db0(0,0),0,0,QbHE(),QbHE(),&at,false));
				if(hacked)qb_stats_d2c658.add4729d0(0x45f,f370.at_nt(i).get_nt()->f9b6bf0(),qb_e_b95ae3,-1);
				else if(qb_cf462c==5)qb_stats_d2c658.add4729d0(0x445,f370.at_nt(i).get_nt()->f9b6bf0(),qb_e_b95aed,-1);
				qb_sound454260(at,0x13b);
				qb_view_cec054->f8195a0(at,f370[i]->f457a30(),4);
				f370[i]->remove57dbe0(0,0,1,1);
				removeD=true;
			}
			if(removeD)
			{
				f464bd0(i);
				i--;
			}
		}
	}
	if(f3d0!=0&&f320>=f3d0)
	{
		QbHI pick;
		if(!f3c0.empty()&&(rng.chance(0x5a)||f3c0.size()>=10))
		{
			for(unsigned i=0;i<f3c0.size();i++)
				if(!f3c0[i].p()||!f3c0[i]->f577b80())qb_eraseStep9d6440(f3c0,i);
			if(!f3c0.empty())pick=qb_randomRecord9dafb0(f3c0);
		}
		if(pick.isNull()&&!f3b0.empty())
		{
			for(unsigned i=0;i<f3b0.size();i++)
				if(!f3b0[i].p()||!f3b0[i]->f577b80())qb_eraseStep9d6440(f3b0,i);
			if(!f3b0.empty())
			{
				if(rng.chance(0xf))qb_shuffle9d9fc0(f3b0);
				if(rng.chance(0x50))
				{
					for(unsigned i=0;i<f3b0.size();i++)
					{
						if(f463160(f3b0[i]->pos575920()))
						{
							pick=f3b0[i];
							break;
						}
					}
				}
				if(pick.isNull())
				{
					for(unsigned i=0;i<f3b0.size();i++)
					{
						if(!f463160(f3b0[i]->pos575920()))
						{
							pick=f3b0[i];
							break;
						}
					}
				}
			}
		}
		if(pick.valid())f74c7d0(pick,0);
		f3d0=rng.rangeInt(10.0f,15.0f)+f320;
	}
	if(f320>=f520)
	{
		bool drained=false;
		for(unsigned i=0;i<f510.size();i++)
		{
			if(!f510[i].p())qb_eraseStep9d6440(f510,i);
			else if(f510[i]->getType44aec0()<=3&&f510[i]->f457cd0()&&f510[i]->f457d70()&&f510[i]->turnsLeft577ad0()<0&&f510[i]->owner457b50()->f490840()>1)
			{
				QbHE owner=f510[i]->owner457b50();
				int a8=f510[i]->getEffectValue457be0(0x7d);
				int wantB=(owner->f490840()-1)*a8;
				int have=f510[i]->f457cd0();
				int amount=qb_minInt9cdb30(have,wantB);
				if(amount>0)
				{
					f510[i]->f458360(amount);
					int cost=amount/a8;
					if(amount%a8!=0)cost++;
					owner->f5de950(cost,0);
					if(owner->isPlayer5c7600())
					{
						QbPart*part=qb_parts_cec088->f894e70(f510[i]);
						if(part)part->drawStatus4a8e70(0);
						QB_MSG((0xeb,&f510[i]->getName571db0(0,0),&qb_intToString4051f0(cost),&qb_intToString4051f0(amount),owner,QbHE(),0,false));
						drained=true;
					}
				}
			}
		}
		if(drained)qb_sound4541b0(0x118,0,0);
		f520=rng.rangeInt(5.0f,30.0f)+f320;
	}
	f736e40();
	for(unsigned i=0;i<ff4.size();i++)
	{
		if((*qb_grid_cfd44c.atPoint(ff4[i]))->f457b10()==0)qb_eraseStep9d7300(ff4,i);
		else if(rng.chance((*qb_grid_cfd44c.atPoint(ff4[i]))->f457b10()/2)&&((*qb_grid_cfd44c.atPoint(ff4[i]))->getEntity45d250().isNull()||qb_tbl_b95150[(*qb_grid_cfd44c.atPoint(ff4[i]))->getEntity45d250()->info9b4350()->f28]))
			(*qb_grid_cfd44c.atPoint(ff4[i]))->f66d580(0);
	}
	if((*qb_grid_cfd44c.atPoint(f66c->pos45a4a0()))->canCaveIn66af50())
	{
		f104++;
		if(f104>6&&f66c->f45a6e0()>=2&&*originalTerrain.atPoint(f66c->pos45a4a0())==*caveinEarthTerrain&&rng.chance(3)&&!f716940(f66c->pos45a4a0(),&f8,f66c.operator->(),0))
			(*qb_grid_cfd44c.atPoint(f66c->pos45a4a0()))->f66d580(0);
	}
	else f104=0;
	if(f66c->f5d2a00(0xc9))
	{
		QbPath*pts=&f108[f320%5];
		for(unsigned j=0;j<pts->size();j++)(*qb_grid_cfd44c.atPoint((*pts)[j]))->f66b070();
	}
	for(unsigned i=0;i<qb_cf4944.size();i++)
		if(!qb_cf4944[i].p()||qb_cf4944[i]->f5798f0())qb_eraseStep9d6440(qb_cf4944,i);
	if(qb_caf130!=6)
	{
		qb_overmind_cf6428.turnUpdate();
		qb_cf6888.f6927e0();
		qb_xom_d25450.turn69d6f0();
	}
	if(!f5cc.empty())
	{
		for(unsigned i=0;i<f5cc.size();i++)
		{
			if(getTurn464270()>=f5cc[i])
			{
				QbPoint pt;
				QbZone*lo=f462e30(f5bc[i]);
				if(lo&&qb_tbl_b90000[lo->h8->kind]==1)pt=f5bc[i];
				else if(!qb_overmind_cf6428.findDispatchExit(&pt,0,0,1,&f66c->pos45a4a0(),(int*)&lo,0,0))pt.x=-1;
				if(pt.x==-1){}
				else
				{
					QbEntDef*def=selectRobotOfClass(1,qb_d1eb98?0x15:0x1a,0,0);
					if(!def){}
					else
					{
						QbHE e=placeEntity6c58c0(def,pt,3,0,0x22,0xe,0);
						if(e.valid())
						{
							e->ai45b590()->f459540(f5bc[i]);
							e->ai45b590()->f451400(1);
							qb_overmind_cf6428.addParty(new QbParty(0,e,-1,0,0),0);
							if(def->f28==0x1a)
							{
								f584.push_back(f5bc[i]);
								f594.push_back(e);
								f5a4.push_back(QbHEs());
							}
						}
					}
				}
				qb_eraseAt9d5190(f5bc,i);
				qb_removeVectorElement9de6f0(f5cc,i);
				i--;
			}
		}
	}
	if(!f584.empty()&&f5b4!=-1&&f320>=f5b4)
	{
		bool spawned=false;
		for(unsigned i=0;i<f594.size();i++)
		{
			if(!f594[i].get9b6570()||f594[i]->getGroup45a3f0()->kind9b4350()!=3)
			{
				if(rng.chance(0x14))
				{
					QbEntDef*def=selectRobotOfClass(1,0x1a,0,0);
					if(!def){}
					else
					{
						QbPoint pt;
						int n;
						if(!qb_overmind_cf6428.findDispatchExit(&pt,0,0,1,&QbPoint(-1),&n,1,0)){}
						else
						{
							QbHE e=placeEntity6c58c0(def,pt,3,0,0x22,0xe,0);
							if(e.valid())
							{
								e->ai45b590()->f459540(f584[i]);
								e->ai45b590()->f451400(1);
								qb_overmind_cf6428.addParty(new QbParty(0,e,-1,0,0),0);
								f594[i]=e;
								f5a4[i].clear9b73d0();
								spawned=true;
							}
						}
					}
				}
				else f594[i].reset9b7270();
			}
		}
		bool moved=false;
		if(f584.size()>1)
		{
			f584.push_back(f584.front9b7060());
			f584.erase9b3450(f584.begin9c1270());
			for(unsigned i=0;i<f594.size();i++)
			{
				if(f594[i].get9b6570()&&f594[i]->getGroup45a3f0()->kind9b4350()==3)
				{
					f594[i]->ai45b590()->f459540(f584[i]);
					moved=true;
				}
			}
		}
		if(spawned||moved)
		{
			QB_ALERT_S(&string("ALERT: Security rotation in progress."),0x127);
			if(qb_say_cefb48)qb_say_cefb48->say49e250(0x35,0,qb_e_b95aee);
		}
		f5b8++;
		f5b4=qb_maxInt9cdb60(f5b8*0x2ee,qb_d1ecb4.random40c130())+f320;
	}
	if(!f604.empty()&&f320>=f614)
	{
		qb_clearObjects9e2650(f604);
		f614=0;
		string msg("Removing old path data");
		QB_MSG((0x1d6,&string(qb_str_cfc9bc),&msg,0,QbHE(),QbHE(),0,false));
	}
	if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("usedCoreResetMatrix_g"))!=0&&getTurn464270()>qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("usedCoreResetMatrix_g"))+3)
	{
		bool pinged=false;
		if(qb_loc_d1e888->kind==0x1e&&!f558)
		{
			f558=true;
			QbHEs*members=f4c[4]->members416f40();
			for(unsigned j=0;j<members->size();j++)
			{
				if((*members)[j]->getName45a280()=="Sigix Containment Pod")
				{
					f7e0[0x13].push_back(qb_factory_cefaa8->createC793190());
					f7e0[0x13].back9b6540()->f6c20b0(0x13,(*members)[j]->pos45a4a0(),-1);
					QB_PHRASE(0x12b);
					do qb_logPhrase5141b0(0x7f,0,0,0,QbHE(),0);while(false);
					qb_sound4541b0(0x101,0,0);
					pinged=true;
					break;
				}
			}
		}
		if(qb_loc_d1e888->kind==0x20&&!f559)
		{
			f559=true;
			QbHEs*members=f4c[3]->members416f40();
			for(unsigned j=0;j<members->size();j++)
			{
				if((*members)[j]->getName45a280()=="Sigix Exoskeleton")
				{
					f7e0[0x13].push_back(qb_factory_cefaa8->createC793190());
					f7e0[0x13].back9b6540()->f6c20b0(0x13,(*members)[j]->pos45a4a0(),-1);
					QB_PHRASE(0x12b);
					do qb_logPhrase5141b0(0x7f,0,0,0,QbHE(),0);while(false);
					qb_sound4541b0(0x101,0,0);
					pinged=true;
					break;
				}
			}
		}
		if(f534==0&&qb_tbl_b90d70[qb_loc_d1e888->kind]!=0)
		{
			if(f66c->f45a880()<=0x21||qb_cf4a00&&f320==5)
			{
				QbPoint at=f66c->pos45a4a0();
				if(!findPropSpotNear71c3c0(at,at,0))
					qb_logError404f10("BS::turnUpdate()","unable to place pingLoc around player at "+qb_pointToString40a4a0(f66c->pos45a4a0()));
				else
				{
					f534=f320;
					f6c6b90(at,"Hypermatrix_Spawn_Delay",0,-1);
					QB_PHRASE(0x129);
					do qb_logPhrase5141b0(0x7d,0,0,0,QbHE(),0);while(false);
					qb_sound4541b0(0x101,0,0);
				}
			}
		}
		else
		{
			for(unsigned i=0;i<f538.size();i++)
			{
				int dist=qb_distanceCeil40a3f0(f66c->pos45a4a0(),f538[i]);
				if(f548[i]!=0)
				{
					if(dist<=5&&f4633c0(f538[i]))
					{
						for(unsigned j=0;j<f7e0[0x12].size();j++)
						{
							if(f7e0[0x12][j]->pos.eq409b90(f538[i]))
							{
								qb_eraseStep9d6440(f7e0[0x12],j);
								break;
							}
						}
						f6c6b90(f538[i],"Hypermatrix_Spawn_Now",0,-1);
						qb_eraseAt9d5190(f538,i);
						qb_eraseAt9ce6d0(f548,i);
					}
				}
				else if(dist<=0x14)
				{
					f548[i]=1;
					f7e0[0x12].push_back(qb_factory_cefaa8->createC793190());
					f7e0[0x12].back9b6540()->f6c20b0(0x12,f538[i],-1);
					QB_PHRASE(0x12a);
					qb_sound4541b0(0x101,0,0);
					pinged=true;
					if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("sigixDetectedHypermatrixPing_g"))==0)
					{
						for(unsigned j=0;j<f4c[2]->members416f40()->size();j++)
						{
							if((*f4c[2]->members416f40())[j]->getFaction45a2c0()==0x5e)
							{
								f6c65a0((*f4c[2]->members416f40())[j],"SEC_Sigix_Detect_Ping",0);
								qb_gd_d1e860.setEntryText46f700("sigixDetectedHypermatrixPing_g","1");
								break;
							}
						}
					}
				}
			}
		}
		if(pinged)qb_mission_cec034->f987de0();
		if(f55c==0)
		{
			int count=0;
			for(int x=0;x<qb_grid_cfd44c.width9fcd80();x++)
			{
				for(int y=0;y<qb_grid_cfd44c.height9b8f00();y++)
				{
					if((*qb_grid_cfd44c.at(x,y))->getItem45d8f0().valid()&&(*qb_grid_cfd44c.at(x,y))->getItem45d8f0()->info9b4350()->f94==3)
					{
						f7243c0(x,y,0);
						count++;
					}
				}
			}
			if(count!=0)
			{
				QB_MSG((count==1?0x12c:0x12d,&qb_intToString4051f0(count),0,0,f66c,QbHE(),0,false));
				string what=qb_countString407a80(count,"artifact");
				do qb_logPhrase5141b0(0x80,&what,0,0,QbHE(),0);while(false);
			}
			f55c=f320;
		}
	}
	if(!f874.empty())
	{
		if(qb_gd_d1e860.isFlagEnabledB46fc40()&&!f8a4&&f66c->f5d2380(0xd2).valid())
		{
			if(!qb_map_cefc4c->f884.empty())
			{
				for(unsigned i=0;i<f884.size();i++)
				{
					f7e0[0x11].push_back(qb_factory_cefaa8->createC793190());
					f7e0[0x11].back9b6540()->f6c20b0(0x11,f884[i],-1);
				}
				qb_mission_cec034->f987de0();
			}
			f8a4=true;
		}
		else if(f8a4)
		{
			int scanner=-1;
			for(unsigned i=0;i<f884.size();i++)
			{
				if(f4633c0(f884[i]))
				{
					if(scanner==-1)scanner=f66c->f5d2380(0xd2).valid()?1:0;
					if(scanner==0)break;
					if(qb_distanceCeil40a3f0(f66c->pos45a4a0(),f884[i])<=5)
					{
						for(unsigned j=0;j<f7e0[0x11].size();j++)
						{
							if(f7e0[0x11][j]->pos.eq409b90(f884[i]))
							{
								qb_eraseStep9d6440(f7e0[0x11],j);
								break;
							}
						}
						bool aN=qb_cf4a00||f715230(2,0x5e).valid();
						QbHE nG;
						QbPoint at;
						QbRecord*arrival;
						qb_lookup9d7980("ECA_Entity_Arrival_E",&arrival);
						for(unsigned k=0;k<f874[i].size();k++)
						{
							if(findPlaceableNear71c150(f884[i],at,qb_entDefs_d25de0[f874[i][k]]->f9c))
							{
								nG=placeEntity6c58c0(qb_entDefs_d25de0[f874[i][k]],at,aN?5:9,0,!aN&&qb_entDefs_d25de0[f874[i][k]]->name.find("Wizard")!=qb_npos_c2ea48?0x16:0x22,0xe,0);
								if(nG.valid())
								{
									if(!aN)
									{
										nG->ai45b590()->setFollowEntity5b2f80(f66c,0);
										if(k==0)
										{
											if(qb_d1eb74==1)
											{
												f6c65a0(nG,"ECA_Squad_Info",0);
												qb_d1eb74=-1;
											}
											else f6c65a0(nG,rng.chance(0x5a)?string("ECA_Squad_Generic"):"ECA_Squad_"+nG->info9b4350()->f2c,0);
										}
									}
									else if(k==0)f6c65a0(nG,"ECA_Squad_Sigix",0);
									if(isVisible4631c0(at)&&arrival)qb_owner_cefc50->new508610()->init503b20(qb_owner_cefc50,arrival,at,qb_d2e20c,0,0,0,9,0);
								}
							}
						}
						if(isVisible4631c0(f884[i]))qb_message49c610(0x320,QbHE(),string("A squad of Warlord forces bursts forth from a hidden compartment."),0);
						qb_sound454260(f884[i],0xab);
						qb_stats_d2c658.add4729d0(0x399,1,qb_e_b95aef,-1);
						qb_stats_d2c658.add4729d0(f894.at_nt(i)+0x39a,1,qb_e_b95af6,-1);
						do qb_logPhrase5141b0(0x8b,&qb_names_cf1a18[f894[i]],0,0,QbHE(),0);while(false);
						if(qb_stats_d2c658.f472c70(0x399)==5)qb_player_cf45d8.f77fbc0(0xce);
						qb_view_cec054->delay49adc0(500);
						qb_d1eb68--;
						qb_eraseAt9de6b0(f874,i);
						qb_eraseAt9d5190(f884,i);
						qb_removeVectorElement9de6f0(f894,i);
						break;
					}
				}
			}
		}
	}
	if(f320%10==0&&rng.chance(0x32)&&f66c->f5d2a00(0xd2))
	{
		QbHPs traps;
		for(unsigned i=0;i<qb_d20248.size9b5100();i++)
		{
			if(!qb_d20248[i].empty()&&qb_d20248[i].front9b7060()->f9b8f00()->f140==0xd)
			{
				for(unsigned j=0;j<qb_d20248[i].size();j++)
					if(qb_d20248[i][j]->trap44b020()->f14==1&&qb_d20248[i][j]->trap44b020()->f65cf50(0)&&qb_distanceCeil40a3f0(f66c->pos45a4a0(),qb_d20248[i][j]->pos4184d0())<=0x10)
						traps.push_back(qb_d20248[i][j]);
			}
		}
		if(!traps.empty())
		{
			for(unsigned k=0;k<traps.size();k++)
			{
				traps[k]->trap44b020()->f10=0;
				traps[k]->f65f170();
				f4647d0(traps[k]->pos4184d0());
				qb_view_cec054->label813050(1,traps[k],0,0,0);
				f9e29b0(f720,traps[k]);
			}
			qb_message49c610(0x320,QbHE(),string("Comm Array decrypts allied signals from nearby ambush traps."),0);
		}
	}
	while(f328!=0x13)
	{
		bool revealed=false;
		if(f328==2)
		{
			for(int k=0;k<0x26;k++)
			{
				if(*qb_d1e970.at(f328,k)!=0)
				{
					int n=qb_reveal794da0(f328,*qb_d1e970.at(f328,k),0,k);
					if(n!=0)
					{
						*qb_d1e970.at(f328,k)-=n;
						revealed=true;
					}
				}
			}
		}
		else
		{
			int*here=qb_d1e970.at(f328,qb_loc_d1e888->kind);
			int*nW=qb_d1e970.at(f328,0);
			if(*here!=0||*nW!=0)
			{
				int n=0;
				n=qb_reveal794da0(f328,*here+*nW,0,0x26);
				if(n!=0)
				{
					int total=n;
					if(n>=*here)
					{
						n-=*here;
						*here=0;
						*nW-=n;
					}
					else *here-=n;
					revealed=true;
				}
			}
		}
		f328++;
		if(revealed)break;
	}
	if(f320==2&&(qb_loc_d1e888->kind==3||qb_loc_d1e888->kind==9||qb_loc_d1e888->f8<=7&&qb_loc_d1e888->inRange46ecb0())&&qb_d1eac0<=1&&qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("exiFarcomRescindedWarn_g"))==0&&qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("exiPrototypesTaken_g"))>=1)
	{
		if(qb_d1eacc)
		{
			if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("exiPrototypesTaken_g"))>=2)
			{
				qb_gd_d1e860.setEntryText46f700("exiFarcomEnabled_g","0");
				qb_d1eacc=false;
				QB_ALERT_S(&string("FARCOM_MSG: Not cool, anonymous tester bot. We've taken inventory and discovered your thievery. Let's see how you like having parts stolen!"),-1);
				QB_PHRASE(0x2b3);
				qb_gd_d1e860.setEntryText46f700("exiFarcomRescindedWarn_g","1");
				do qb_logPhrase5141b0(0x138,0,0,0,QbHE(),0);while(false);
				qb_player_cf45d8.f77fbc0(0xf2);
			}
		}
		else qb_gd_d1e860.setEntryText46f700("exiFarcomRescindedWarn_g","1");
	}
	if(qb_cf49fc!=0&&qb_map_cefc4c->f71cfb0())f66c->attemptTeleport63b1c0();
	if(qb_cf4a00)
	{
		if(f868==0||qb_distanceCeil40a3f0(f66c->pos45a4a0(),f86c)>=0x14)
		{
			f868=qb_loc_d1e888->f8*1000;
			if(!qb_loc_d1e888->inRange46ecb0())
			{
				f868+=1000;
				if(qb_loc_d1e888->kind==0x20||qb_loc_d1e888->kind==0x21||qb_loc_d1e888->kind==0x23)f868+=1000;
			}
			int best=9999;
			for(unsigned i=0;i<f10.size();i++)
			{
				if(f10[i]->h8->kind==6)
				{
					best=qb_distanceCeil40a3f0(f66c->pos45a4a0(),f10[i]->pos);
					break;
				}
			}
			if(best==9999)
			{
				int d;
				for(unsigned i=0;i<f10.size();i++)
				{
					if(f10[i]->h8->inRange46ecb0())
					{
						d=qb_distanceCeil40a3f0(f66c->pos45a4a0(),f10[i]->pos);
						if(d<best)best=d;
					}
				}
			}
			if(best==9999)
			{
				int d;
				for(unsigned i=0;i<f10.size();i++)
				{
					if(!f10[i]->h8->inRange46ecb0())
					{
						d=qb_distanceCeil40a3f0(f66c->pos45a4a0(),f10[i]->pos);
						if(d<best)best=d;
					}
				}
			}
			f868+=best;
			f868+=rng.rangeInt(-20.0f,20.0f);
			f86c=f66c->pos45a4a0();
		}
	}
	if(qb_d1eaac&&qb_d1eab8<2&&(qb_loc_d1e888->kind==2||qb_loc_d1e888->kind==0xf)&&f4c[0xd]->count44afb0()>=5&&!f4c[0xd]->members416f40()->empty())
	{
		QbHEs*members=f4c[0xd]->members416f40();
		if(qb_d1eab8!=0)
		{
			for(int k=0;k<=2;k++)qb_map_cefc4c->f465950(0xd,k,0);
			for(unsigned j=0;j<members->size();j++)(*members)[j]->ai45b590()->setField4593f0(0);
			f66c->f6396f0("MAT_Fedparty_Control",1);
			do qb_logPhrase5141b0(0xcb,0,0,0,QbHE(),0);while(false);
			qb_d1eab8=2;
			if(qb_xom_d25450.active)qb_xom_d25450.f69e700(0x78,0,0.0f);
		}
		else
		{
			f4c[0xd]->reset45e460();
			qb_d1eab8=1;
		}
		QbHE closest=(*members)[0];
		int best0=qb_distanceCeil40a3f0(f66c->pos45a4a0(),closest->pos45a4a0());
		for(unsigned j=1;j<members->size();j++)
		{
			int d=qb_distanceCeil40a3f0(f66c->pos45a4a0(),(*members)[j]->pos45a4a0());
			if(d<best0)
			{
				best0=d;
				closest=(*members)[j];
			}
		}
		f6c65a0(closest,qb_d1eab8==1?"MAT_Fedparty_Hostile1":"MAT_Fedparty_Hostile2",0);
	}
	switch(qb_loc_d1e888->kind)
	{
	case 7:
		if(f4c[8]->f45e380(3))
		{
			QbHEs*members=f4c[8]->members416f40();
			QbHE yiuf;
			for(unsigned j=0;j<members->size();j++)
			{
				if((*members)[j]->getName45a280()=="YI-UF0")
				{
					yiuf=(*members)[j];
					break;
				}
			}
			if(yiuf.valid())
			{
				yiuf->f6396f0("MIN_Yiuf_Drop_Launcher",1);
				yiuf->f6396f0("MIN_Yiuf_Attacked",1);
				yiuf->f6396f0("MIN_Yiuf_Go_Hostile",1);
				yiuf->f6396a0("MIN_Yiuf_Hostile_Player",0);
				yiuf->changeFaction5dc780(f4c[5],0);
				if(qb_xom_d25450.active)qb_xom_d25450.f69e700(0x79,0,0.0f);
			}
		}
	case 2:case 3:case 19:case 28:
		if(f4c[9]->f45e380(3))
		{
			QbHEs*members=f4c[9]->members416f40();
			QbHE ns;
			QbHE pK;
			QbHE vlg;
			QbHE had;
			for(unsigned j=0;j<members->size();j++)
			{
				if((*members)[j]->getName45a280()=="8R-AWN")
				{
					ns=(*members)[j];
					break;
				}
				else if((*members)[j]->getName45a280()=="7R-MNS")
				{
					pK=(*members)[j];
					break;
				}
				else if((*members)[j]->getName45a280()=="VL-GR5")
				{
					vlg=(*members)[j];
					break;
				}
				else if((*members)[j]->getName45a280()=="5H-AD0")
				{
					had=(*members)[j];
					break;
				}
			}
			if(ns.valid()&&qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("exiAttackedLocals_g"))==0)
			{
				qb_gd_d1e860.setEntryText46f700("exiAttackedLocals_g","1");
				removeEntity465750(ns);
				ns->removeEffectsA639730(1);
				ns->changeFaction5dc780(f4c[5],0);
				f6c65a0(ns,"EXI_Brawn_Hostile_Talk",0);
				f6c65a0(ns,"EXI_Brawn_Death",0);
				ns->ai45b590()->setField4593f0(0);
				if(qb_xom_d25450.active)qb_xom_d25450.f69e700(0x79,0,0.0f);
			}
			else if(had.valid())
			{
				had->removeEffectsA639730(1);
				had->changeFaction5dc780(f4c[5],0);
				f6c65a0(had,"DEE_Shadow_Leave_Enemy",0);
				if(qb_xom_d25450.active)qb_xom_d25450.f69e700(0x78,0,0.0f);
			}
			else if(pK.valid()||vlg.valid())
			{
				QbHE e=pK.valid()?pK:vlg;
				e->removeEffectsA639730(1);
				e->changeFaction5dc780(f4c[5],0);
				f6c65a0(e,pK.valid()?"MAT_Term_Talk_Hostile":"ARM_Valg_Talk_Hostile",0);
				for(unsigned i=0;i<f10.size();i++)
				{
					if(f10[i]->h8->inRange46ecb0())
					{
						e->ai45b590()->f4582d0(0x19);
						e->ai45b590()->f459540(f10[i]->pos);
						e->ai45b590()->setField4593f0(0);
						e->ai45b590()->f451930(0);
						if(qb_xom_d25450.active)qb_xom_d25450.f69e700(0x79,0,0.0f);
						if(pK.valid())e->ai45b590()->setZionite44e540(0x32);
						if(vlg.valid())
						{
							QbItems*inv=vlg->getInventoryList45ab00();
							for(unsigned k=0;k<inv->size();k++)
								if((*inv)[k]->name457860()=="Enh. Nova Cannon"||(*inv)[k]->name457860()=="Adv. Corruption Screen"||(*inv)[k]->name457860()=="VL-GR5's Exoskeleton \"Deathgrip\"")
									vlg->f642940((*inv)[k],0,0,0,0);
							qb_map_cefc4c->giveItem6c52b0("Multinova Projection Cannon",vlg,1,0);
							qb_map_cefc4c->giveItem6c52b0("Quantum Capacitor",vlg,1,0);
							qb_map_cefc4c->giveItem6c52b0("Exp. Heat Sink",vlg,1,0);
							if(vlg->f5c92e0(2))qb_map_cefc4c->giveItem6c52b0("Exp. Energy Well",vlg,1,0);
							vlg->f5ded70(1000000);
							if(vlg->f45a990()>0)vlg->setField4514c0(0);
							vlg->f5de870(1000000,0);
							if(qb_map_cefc4c->f4631f0(vlg))
							{
								string msg("VL-GR5 sheds several components and brandishes a new weapon.");
								qb_message49c610(0x320,QbHE(),msg,0);
								qb_sound454260(vlg->pos45a4a0(),0xf7);
							}
						}
						break;
					}
				}
			}
		}
		break;
	case 8:
		if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("exiMaincAttacked_g")))
		{
			int dt=f320-qb_d1eac8;
			if(dt==0x23)
			{
				QB_ALERT_S(&string("EXILES: Lab perimeter alert, evacuate immediately."),0x12d);
				QbPoint dest(0x12,0x13);
				QbHEs list(*f4c[9]->members416f40());
				for(int j=list.size()-1;j>=0;j--)
				{
					if(list[j]->getName45a280()!="8R-AWN"&&list[j]->getFaction45a2c0()!=0x3c)
					{
						list[j]->setAI64ecf0(new QbAIObj(list[j],0x19,0));
						list[j]->ai45b590()->f459540(dest);
					}
					if(list[j]->getName45a280()=="EX-BIN")
					{
						f6c6600(list[j],"EXI_Bin_Evac_Actions");
						f6c65a0(list[j],"EXI_Bin_Retreat_Talk",0);
					}
					else if(list[j]->getName45a280()=="EX-DEC")
					{
						f6c6600(list[j],"EXI_Dec_Evac_Actions");
						f6c65a0(list[j],"EXI_Dec_Retreat",0);
					}
					else if(list[j]->getName45a280()=="EX-HEX")f6c6600(list[j],"EXI_Hex_Evac_Actions");
				}
				f739e50(1);
			}
			else if(dt==100)
			{
				QbHEs list(*f4c[9]->members416f40());
				for(int j=list.size()-1;j>=0;j--)
				{
					if(list[j]->getName45a280()=="8R-AWN")
					{
						f6c65a0(list[j],"EXI_Brawn_Retreat_Talk",0);
						break;
					}
				}
			}
			else if(dt==0x6e)f739e50(2);
			else if(dt==0x78)
			{
				QbPoint dest(0x12,0x13);
				QbHEs list(*f4c[9]->members416f40());
				for(int j=list.size()-1;j>=0;j--)
				{
					if(list[j]->getName45a280()=="8R-AWN")
					{
						list[j]->setAI64ecf0(new QbAIObj(list[j],0x19,0));
						list[j]->ai45b590()->f459540(dest);
						break;
					}
				}
			}
			else if((dt-0x6e)%0x78==0)
			{
				int wave=(dt-0x6e)/0x78+2;
				if(wave<5)f739e50(wave);
			}
		}
		if((qb_d1eac0==0||qb_d1eac0==1)&&qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("exiAttackedLocals_g"))==0)
		{
			if(f4c[9]->f45e380(1))exiles6df0b0(0);
			else if(*qb_map_cefc4c->f464590()!=0&&!*qb_map_cefc4c->f4645b0())
			{
				QB_ALERT_S(&string("EXILES: Huh, someone's being naughty."),-1);
				do qb_logPhrase5141b0(0x139,0,0,0,QbHE(),0);while(false);
				*qb_map_cefc4c->f4645b0()=true;
			}
			else if(*qb_map_cefc4c->f464590()>=2)exiles6df0b0(0);
		}
		break;
	case 9:case 10:
		if(f4c[0xd]->f45e380(3)&&f4638e0(0,0xd))
		{
			QbHE mtf=qb_map_cefc4c->squad463890(0xd)->find45e1c0("01-MTF");
			if(mtf.valid())
			{
				for(int k=0;k<=2;k++)f465950(k,0xd,0);
				f4c[0xd]->setField45e4a0(0);
				mtf->removeEffectsA639730(1);
				mtf->ai45b590()->setFollowEntity5b2f80(QbHE(),0);
				f6c65a0(mtf,"STO_Mtf_Hostile",0);
				if(qb_xom_d25450.active)qb_xom_d25450.f69e700(0x78,0,0.0f);
				for(unsigned i=0;i<f10.size();i++)
				{
					if(f10[i]->h8->inRange46ecb0())
					{
						mtf->ai45b590()->f4582d0(0x19);
						mtf->ai45b590()->f459540(f10[i]->pos);
						mtf->ai45b590()->f451930(0);
						mtf->ai45b590()->setZionite44e540(3);
						break;
					}
				}
				if(qb_loc_d1e888->kind==10&&qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("recMtfMetKtur_g"))==0)
				{
					QbHE ktur=qb_map_cefc4c->squad463890(10)->find45e1c0("KN-7UR");
					if(ktur.valid())
					{
						ktur->ai45b590()->f4582d0(0x19);
						ktur->ai45b590()->f459540(qb_map_cefc4c->f714120(0xb));
					}
				}
			}
		}
		if(qb_loc_d1e888->kind==10)
		{
			if(f4c[0xe]->f45e380(3)&&f4638e0(0,0xe))
			{
				QbHE ktur=qb_map_cefc4c->squad463890(0xe)->find45e1c0("KN-7UR");
				if(ktur.valid())
				{
					for(int k=0;k<=2;k++)f465950(k,0xe,0);
					ktur->removeEffectsA639730(1);
					f6c65a0(ktur,"REC_Ktur_Hostile",0);
					if(qb_xom_d25450.active)qb_xom_d25450.f69e700(0x78,0,0.0f);
					ktur->ai45b590()->f4582d0(0x19);
					ktur->ai45b590()->f459540(qb_map_cefc4c->f714120(0xb));
					ktur->ai45b590()->f451930(0);
					ktur->ai45b590()->setZionite44e540(3);
				}
			}
			if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("scrAttackedLocals_g"))==0&&f4c[10]->f45e380(1))f72f6b0();
		}
		break;
	case 11:
		if(qb_d1eb08!=0&&qb_d1eb10==0&&(f324>=qb_d1eb0c||f320>=qb_d1eb08+400)&&qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("scrAttackedLocals_g"))==0)
		{
			qb_d1eb10=f320;
			qb_cec138->f9693f0();
		}
		else if(qb_d1eb10!=0)
		{
			if(getTurn464270()==qb_d1eb10+qb_d1eb14)f731680(rng.rangeInt(3.0f,4.0f),0,0);
			if(!qb_d1eb18&&getTurn464270()%5==0&&rng.chance(0x19))
			{
				QbPath spots;
				spots.push_back(QbPoint(0x26,3));
				spots.push_back(QbPoint(0x7a,0xe));
				for(unsigned i=0;i<spots.size();i++)
				{
					if(qb_distanceCeil40a3f0(spots[i],f66c->pos45a4a0())<=0x19)
					{
						f731680(rng.rangeInt(3.0f,4.0f),&spots[i],1);
						qb_d1eb18=true;
						break;
					}
				}
			}
			if(qb_d1eb40!=0&&getTurn464270()%5==0&&rng.chance(0x19))
			{
				QbPath spots;
				spots.push_back(QbPoint(0x26,3));
				spots.push_back(QbPoint(0x7a,0xe));
				int n=qb_minInt9cdb30(qb_d1eb40,rng.rangeInt(3.0f,5.0f));
				f731680(n,&qb_randomPoint9d5350(spots),0);
				qb_d1eb40-=n;
			}
			bool converted=false;
			if(getTurn464270()%12==0&&rng.chance(0xf)&&qb_d1eb1c<3)
			{
				QbHEs cand;
				QbHEs*members=f4c[10]->members416f40();
				for(unsigned j=0;j<members->size();j++)
					if((*members)[j]->getFaction45a2c0()!=0x4e&&qb_distanceCeil40a3f0(f66c->pos45a4a0(),(*members)[j]->pos45a4a0())<=0xe&&(*members)[j]->isXomCandidate5d51a0()&&(*members)[j]->getFaction45a2c0()!=0xb&&!(*members)[j]->f45ac40(0x8b))
						cand.push_back((*members)[j]);
				if(!cand.empty())
				{
					QbHE pick=qb_randomRecord9dafb0(cand);
					f6c65a0(pick,"SCR_CW_Prime_Rand_T",0);
					pick->f45b340(new QbNP(qb_d2f0f8[0x8b],1));
					qb_d1eb1c++;
					converted=true;
				}
			}
			if(getTurn464270()%12==0&&rng.chance(0xf)&&!converted&&qb_d1eb20<3)
			{
				QbHEs cand;
				QbHEs*members=f4c[0xd]->members416f40();
				for(unsigned j=0;j<members->size();j++)
					if(qb_distanceCeil40a3f0(f66c->pos45a4a0(),(*members)[j]->pos45a4a0())<=0xe&&(*members)[j]->isXomCandidate5d51a0()&&(*members)[j]->getFaction45a2c0()!=0xb&&!(*members)[j]->f45ac40(0x8b))
						cand.push_back((*members)[j]);
				if(!cand.empty())
				{
					QbHE pick=qb_randomRecord9dafb0(cand);
					f6c65a0(pick,"SCR_CW_Non_Prime_Rand_T",0);
					pick->f45b340(new QbNP(qb_d2f0f8[0x8b],1));
					qb_d1eb20++;
					converted=true;
				}
			}
			if(getTurn464270()%5==0&&rng.chance(5)&&!converted&&qb_d1eb24<4)
			{
				QbHEs cand;
				QbRect r;
				qb_grid_cfd44c.getRect9b4430(f66c->pos45a4a0(),0x10,r);
				for(int x=r.x;x<=r.x2;x++)
				{
					for(int y=r.y;y<=r.y2;y++)
					{
						if((*qb_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&f463380(x,y))
						{
							QbHE e=(*qb_grid_cfd44c.at(x,y))->getEntity45d250();
							if(!e->f45ac40(0x8b)&&e->getFaction45a2c0()!=0x2d&&e->getFaction45a2c0()!=0x26&&e->getFaction45a2c0()!=0x4e&&(e->getGroup45a3f0()->kind9b4350()==10||e->getGroup45a3f0()->kind9b4350()==0xd))
								cand.push_back((*qb_grid_cfd44c.at(x,y))->getEntity45d250());
						}
					}
				}
				if(!cand.empty())
				{
					QbHE pick=qb_randomRecord9dafb0(cand);
					pick->f5dcc70(pick->getGroup45a3f0()->kind9b4350()==10?0xd:10,1);
					qb_view_cec054->delay49adc0(1000);
					f6c65a0(pick,"SCR_CW_Faction_Switch",0);
					pick->f45b340(new QbNP(qb_d2f0f8[0x8b],1));
					qb_d1eb24++;
					converted=true;
				}
			}
			if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("scrAttackedLocals_g"))==0)
			{
				if(f320%100==0)
				{
					f4c[0xe]->reset45e460();
					f4c[10]->reset45e460();
				}
				else if(f4c[0xe]->f45e380(0xf)||f4c[10]->f45e380(0xf))
				{
					qb_gd_d1e860.setEntryText46f700("scrAttackedLocals_g",qb_intToString4051f0(getTurn464270()));
					do qb_logPhrase5141b0(0x101,0,0,0,QbHE(),0);while(false);
					for(int k=0;k<=2;k++)f465950(k,10,0);
					qb_factory_cefaa8->f793690();
					qb_f789ac0();
					QbHE optimus=f715230(10,0x4e);
					if(optimus.valid())
					{
						optimus->removeEffectsA639730(1);
						f6c65a0(optimus,"SCR_Optimus_CW_Hostile",0);
					}
					QbHEs*members=f4c[10]->members416f40();
					QbHEs seen;
					for(unsigned j=0;j<members->size();j++)
						if(f463400((*members)[j])&&(*members)[j]->getFaction45a2c0()!=0x4e)seen.push_back((*members)[j]);
					if(!seen.empty())
					{
						qb_shuffle9d9fc0(seen);
						for(int k=0;k<2&&k<seen.size();k++)f6c65a0(seen[k],"SCR_CW_Prime_Hostile_T",0);
					}
					if(qb_xom_d25450.active)qb_xom_d25450.f69e700(0x5e,0,0.0f);
				}
			}
		}
		else if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("scrAttackedLocals_g"))==0)
		{
			bool hostile=false;
			if(f4c[10]->f45e380(1))hostile=true;
			else if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("scrReleasedSubatomizers_g"))!=0&&getTurn464270()>=qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("scrReleasedSubatomizers_g")))hostile=true;
			else if(qb_cf4b20==0&&qb_map_cefc4c->getPlayer4630f0()->pos45a4a0().x>=0x49)hostile=true;
			else if(*qb_map_cefc4c->f464590()!=0&&!*qb_map_cefc4c->f4645b0())
			{
				QB_ALERT_S(&string("ANNOUNCEMENT: Tracking potentially hostile trap installation."),-1);
				do qb_logPhrase5141b0(0x102,0,0,0,QbHE(),0);while(false);
				*qb_map_cefc4c->f4645b0()=true;
			}
			else if(*qb_map_cefc4c->f464590()>=2)hostile=true;
			if(hostile)f72ffe0(0);
		}
		else
		{
			int turn=getTurn464270();
			if(turn%2==0)f742270(0);
			if(qb_d1eb40!=0&&turn%5==0&&rng.chance(0x19))
			{
				QbPath spots;
				spots.push_back(QbPoint(0x26,3));
				spots.push_back(QbPoint(0x7a,0xe));
				QbPoint at=qb_randomPoint9d5350(spots);
				int n=qb_minInt9cdb30(qb_d1eb40,rng.rangeInt(3.0f,5.0f));
				qb_d1eb40-=n;
				QbEntDef*def;
				if(qb_findByName9d7530(qb_entDefs_d25de0,rng.chance(0x32)?"Scrapper_3":"Elite_4",def))
				{
					QbRect area(0x4f,0x23,0x74,0x3e);
					QbHE q3;
					for(int k=0;k<n;k++)
					{
						q3=placeEntity6c58c0(def,at,10,0,0x22,0xe,0);
						q3->ai45b590()->chase5b4710(f66c,-1,1,0,0);
						q3->ai45b590()->f459470(area);
					}
				}
			}
			if(turn==qb_d1eb28)
			{
				QbPoint at(0x7a,0xe);
				QbEntDef*def;
				if(qb_findByName9d7530(qb_entDefs_d25de0,"Elite_4",def))
				{
					QbRect area(0x4f,0x23,0x74,0x3e);
					QbHE sy;
					for(int k=0;k<4;k++)
					{
						sy=placeEntity6c58c0(def,at,10,0,0x22,0xe,0);
						if(k==0)sy->f6396a0("SCR_Hostile_Elite_Talk",0);
						sy->ai45b590()->f459470(area);
					}
				}
			}
			if(turn==qb_d1eb2c)
			{
				QbPoint at(0x26,3);
				QbEntDef*def;
				if(qb_findByName9d7530(qb_entDefs_d25de0,"Scrapper_3",def))
				{
					QbRect area(0x26,0x22,0x47,0x3f);
					QbHE t_;
					for(int k=0;k<4;k++)
					{
						t_=placeEntity6c58c0(def,at,10,0,0x22,0xe,0);
						if(k==0)t_->f6396a0("SCR_Hostile_Scrapr_Talk",0);
						t_->ai45b590()->chase5b4710(f66c,-1,1,0,0);
						t_->ai45b590()->f459470(area);
					}
				}
			}
			if(turn==qb_d1eb30)
			{
				QbHE optimus=f715230(10,0x4d);
				if(optimus.isNull())qb_d1eb30=0;
				else if(!optimus->ai45b590()->getEntity459570(f66c))
				{
					QB_ALERT_S(&string("ANNOUNCEMENT: Triborg tracking relay activated. Stay clear or you only have yourself to blame!"),-1);
					optimus->ai45b590()->chase5b4710(f66c,-2,1,0,0);
					qb_d1eb30=0;
					QbRect r;
					qb_grid_cfd44c.getRect9b4430(optimus->pos45a4a0(),5,r);
					for(int x=r.x;x<=r.x2;x++)
						for(int y=r.y;y<=r.y2;y++)
							if((*qb_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->getGroup45a3f0()->kind9b4350()==10&&(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->getFaction45a2c0()!=0x4d&&(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->getFaction45a2c0()!=0x4e)
								(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->ai45b590()->setFollowEntity5b2f80(optimus,0);
				}
			}
			if(turn==qb_d1eb34)
			{
				QbRect vC;
				if(f66c->pos45a4a0().x<0x4b)vC.set40b300(0x34,0x2d,0x47,0x3f);
				else
				{
					vC.set40b300(0x4b,0x10,0x80,0x53);
					QbHE optimus=f715230(10,0x4e);
					if(optimus.valid())optimus->ai45b590()->chase5b4710(f66c,-1,1,0,0);
				}
				QbHEs*members=f4c[10]->members416f40();
				for(unsigned j=0;j<members->size();j++)
					if((*members)[j]->pos45a4a0().x>=0x4b)(*members)[j]->ai45b590()->f459410(vC);
			}
			if(turn==qb_d1eb3c)
			{
				switch(qb_d1eb38)
				{
				case 0:
				{
					QB_ALERT_S(&string("ANNOUNCEMENT: HQ reinforcements inbound. Hold tight!"),-1);
					qb_d1eb38++;
					qb_d1eb3c=rng.rangeInt(50.0f,75.0f)+turn;
					QbHE optimus=f715230(10,0x4e);
					if(optimus.valid())optimus->ai45b590()->chase5b4710(f66c,-2,1,0,0);
					break;
				}
				case 1:
					f74d660(QbPoint(0x26,3),rng.rangeInt(8.0f,10.0f));
					f74d660(QbPoint(0x7a,0xe),rng.rangeInt(8.0f,10.0f));
					qb_d1eb38++;
					qb_d1eb3c=rng.rangeInt(50.0f,75.0f)+turn;
					break;
				default:
					if(qb_d1eb38==5)QB_ALERT_S(&string("ANNOUNCEMENT: Sorry everyone, if you're still alive to receive this, we've run out of nearby reinforcements. Consider running and hiding!"),-1);
					else
					{
						if(f4c[10]->members416f40()->size()<200)
						{
							f74d660(rng.chance(0x32)?QbPoint(0x26,3):QbPoint(0x7a,0xe),rng.rangeInt(4.0f,5.0f));
							qb_d1eb38++;
						}
						qb_d1eb3c=rng.rangeInt(50.0f,75.0f)+turn;
					}
				}
			}
		}
		break;
	case 21:
		if(*qb_map_cefc4c->f464590()!=0&&qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("datHostileToDataMiner_g"))==0)f731960();
		break;
	case 12:
		if(qb_d1eae4==0)break;
		if(f320==qb_d1eae4-10)
		{
			QB_ALERT_S(&string("ALERT: Foreign system detected. Charging EMP."),-1);
			qb_sound4541b0(0x8a,0,0);
			if(qb_d1eae0>1)
			{
				QbHEs list;
				QbHEs*members=qb_map_cefc4c->squad463890(2)->members416f40();
				for(unsigned j=0;j<members->size();j++)
					if(!qb_d1eae8.contains40b750((*members)[j]->pos45a4a0())&&((*members)[j]->getFaction45a2c0()==0x10||(*members)[j]->getFaction45a2c0()==0x3f))
						list.push_back((*members)[j]);
				if(!list.empty())qb_map_cefc4c->f6c65a0(qb_randomRecord9dafb0(list),"WAS_Xom_EMP_Comment",0);
			}
		}
		else if(f320==qb_d1eae4)
		{
			do qb_logPhrase5141b0(0x18c,0,0,0,QbHE(),0);while(false);
			qb_sound4541b0(0x8b,0,0);
			bool unready=qb_d1eae8.x1!=-1&&qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("wasUnreadyDerelictsAttacked_g"))==0;
			QbRecord*w3;
			qb_lookup9d7980("C_Waste_Shock",&w3);
			for(int x=0;x<qb_grid_cfd44c.width9fcd80();x++)
			{
				for(int y=0;y<qb_grid_cfd44c.height9b8f00();y++)
				{
					if((*qb_grid_cfd44c.at(x,y))->f4550b0())
					{
						if(unready&&qb_d1eae8.contains40b700(x,y))continue;
						if(isVisible463190(x,y))qb_owner_cefc50->new508610()->init503b20(qb_owner_cefc50,w3,QbPoint(x,y),qb_d2e20c,0,0,0,9,0);
						if((*qb_grid_cfd44c.at(x,y))->getItem45d8f0().valid())
						{
							QbHI it=(*qb_grid_cfd44c.at(x,y))->getItem45d8f0();
							int w9=rng.rangeInt(1.0f,100.0f);
							if(w9<=0x1e)
							{
								QB_MSG((0x1a7,&it->getName571db0(0,0),0,0,QbHE(),QbHE(),&QbPoint(x,y),false));
								qb_sound454260(QbPoint(x,y),0xa5);
								qb_sound454260(QbPoint(x,y),0xa5);
								qb_view_cec054->f8195a0(QbPoint(x,y),it->f457a30(),1);
								it->remove57dbe0(0,0,1,1);
							}
							else if(w9<=0x46&&it->f577990())it->f5798b0(qb_d21b34.random40c130());
						}
						if((*qb_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->getFaction45a2c0()!=0x1d)
						{
							QbHE e=(*qb_grid_cfd44c.at(x,y))->getEntity45d250();
							if(rng.chance(e->f5d2090(0x29)*10))
							{
								if(e->isPlayer5c7600())QB_MSG((0x222,&e->f5d24e0(0x29)->getName571db0(0,0),0,0,e,QbHE(),0,false));
							}
							else
							{
								int dmg=e->isPlayer5c7600()?rng.rangeInt(5.0f,10.0f):rng.rangeInt(20.0f,30.0f);
								dmg=e->f5cb570(3,1)*dmg/100;
								if(dmg>0&&e->f5defa0(dmg,1)&&e->isPlayer5c7600())
								{
									string msg="System corrupted (+"+qb_intToString4051f0(dmg)+").";
									QB_MSG((0x21f,&msg,0,0,QbHE(),QbHE(),&e->pos45a4a0(),false));
								}
							}
						}
					}
				}
			}
			qb_d1eae4+=100;
		}
		break;
	case 16:case 17:
		if(f320>=5&&qb_d1eb68!=0&&qb_d1eb70==0)
		{
			QbRect r;
			qb_grid_cfd44c.getRect9b4430(f66c->pos45a4a0(),0x14,r);
			for(int x=r.x;x<=r.x2;x++)
				for(int y=r.y;y<=r.y2;y++)
					if((*qb_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->isHostileTo45aa70(f66c))goto end16;
			if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("installedRif_g"))||qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("scrAttackedLocals_g"))||qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("scrUfdRegistered_g"))||qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("zioWasImprinted_g"))||qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("warAttackedLocals_g")))
				qb_d1eb70=-1;
			else
			{
				f6c65a0(f66c,"GAR_Comm_Array_Deliver1",0);
				qb_d1eb70=1;
			}
		}
end16:
		break;
	case 18:
		if(qb_loc_d1e888!=qb_d1ebe4)break;
		if(qb_d1ebe8==0&&(f324>=0x78||f320>=0x12c||f66c->pos45a4a0().x>=0x1e))f741190();
		if(qb_d1ebe8!=0)
		{
			const int interval=100;
			int wC=(f320-qb_d1ebe8)/interval+1;
			if(wC<=4&&f320>qb_d1ebcc&&(f320-qb_d1ebcc)%interval==0)
			{
				if(wC==4)
				{
					QB_ALERT_S(&string("PUBLIC SERVICE ANNOUNCEMENT: We have reports that's the last of them for now. Finish off any stragglers, and beware regular patrols may still be active, so stay frosty."),-1);
					do qb_logPhrase5141b0(0x15d,0,0,0,QbHE(),0);while(false);
				}
				else f741610(wC);
				f4c[9]->reset45e460();
			}
		}
		if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("proDefenseAttackedLocals_g"))==0)
		{
			bool hostile=false;
			if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("proDefenseMaincAttacked_g"))?f4c[9]->f45e380(0xf):f4c[9]->f45e380(1))hostile=true;
			if(hostile)
			{
				qb_gd_d1e860.setEntryText46f700("proDefenseAttackedLocals_g",qb_intToString4051f0(f320));
				QB_ALERT_S(&string("PUBLIC SERVICE ANNOUNCEMENT: Internal threat detected, destroy unfamiliar defenders on sight."),-1);
				do qb_logPhrase5141b0(0x15e,0,0,0,QbHE(),0);while(false);
				if(qb_xom_d25450.active)qb_xom_d25450.f69e700(0x6b,f66c->f5c98c0(0,0x42,0)?1:0,0.0f);
				QbHEs list(*f4c[9]->members416f40());
				for(int j=list.size()-1;j>=0;j--)
				{
					removeEntity465750(list[j]);
					list[j]->removeEffectsA639730(1);
					list[j]->changeFaction5dc780(f4c[5],0);
				}
				for(unsigned i=0;i<qb_d20248.size9b5100();i++)
				{
					for(unsigned j=0;j<qb_d20248[i].size();j++)
					{
						if(qb_d20248[i][j]->trap44b020()->f10==9)
						{
							qb_d20248[i][j]->trap44b020()->f10=5;
							if(isVisible4631c0(qb_d20248[i][j]->pos4184d0())&&qb_d20248[i][j]->f45cbd0())
								f7c4.atPoint9d2c00(qb_d20248[i][j]->pos4184d0())->f6c1cd0(*qb_grid_cfd44c.atPoint(qb_d20248[i][j]->pos4184d0()),0,0);
						}
					}
				}
			}
		}
		break;
	case 20:
		if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("zioAttackedLocals_g"))==0)
		{
			if(f4c[8]->f45e380(1)||qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("installedRif_g"))&&f66c->pos45a4a0().inRect409d70(0,0,0x6f,qb_grid_cfd44c.height9b8f00()))f731b10(0);
			if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("scrAttackedLocals_g"))&&f66c->pos45a4a0().inRect409d70(0,0,0x6f,qb_grid_cfd44c.height9b8f00()))f731b10(0);
			if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("zioReleasedSubatomizers_g"))&&getTurn464270()>=qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("zioReleasedSubatomizers_g"))&&f66c->pos45a4a0().inRect409d70(0,0,0x6f,qb_grid_cfd44c.height9b8f00()))f731b10(0);
			else if(qb_d1ebb8>=0x14&&!qb_d1ebbc)
			{
				if(qb_d1ebb8>=0x1e)qb_d1ebb8=0x1d;
				QB_ALERT_S(&string("PUBLIC SERVICE ANNOUNCEMENT: Tracking signficant damage to machine network."),-1);
				do qb_logPhrase5141b0(0x16a,0,0,0,QbHE(),0);while(false);
				qb_d1ebbc=true;
			}
			else if(qb_d1ebb8>=0x1e)
			{
				do qb_logPhrase5141b0(0x16f,0,0,0,QbHE(),0);while(false);
				f731b10(0);
			}
			else if(*qb_map_cefc4c->f464590()!=0&&!*qb_map_cefc4c->f4645b0())
			{
				QB_ALERT_S(&string("PUBLIC SERVICE ANNOUNCEMENT: Tracking unauthorized trap installation."),-1);
				do qb_logPhrase5141b0(0x16b,0,0,0,QbHE(),0);while(false);
				*qb_map_cefc4c->f4645b0()=true;
			}
			else if(*qb_map_cefc4c->f464590()>=2)f731b10(0);
		}
		else
		{
			for(int g=0;g<=2;g++)
			{
				QbHEs*members=f4c[g]->members416f40();
				if(!members->empty())
				{
					QbXDef*def;
					if(qb_findByName9d7de0(qb_d2c408,"ZIO_Hostile_Zionite2",def))
					{
						QbPath around;
						for(unsigned j=0;j<members->size();j++)
						{
							around.clear9b3560();
							bool done=false;
							if(rng.chance(5))
							{
								qb_getSurrounding4faaf0((*members)[j]->pos45a4a0(),around);
								qb_shuffle9d7350(around);
								for(unsigned k=0;k<around.size();k++)
								{
									if((*qb_grid_cfd44c.atPoint(around[k]))->getProp45d550().valid()&&(*qb_grid_cfd44c.atPoint(around[k]))->getProp45d550()->f9b8f00()==qb_cefbd8&&(!done||rng.chance(0x14))&&!(*qb_grid_cfd44c.atPoint(around[k]))->getProp45d550()->f45c9d0(def))
									{
										f6c6700((*qb_grid_cfd44c.atPoint(around[k]))->getProp45d550(),"ZIO_Hostile_Zionite2",0);
										done=true;
									}
								}
							}
						}
					}
				}
			}
		}
		break;
	case 23:
		if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("warMaincAttacked_g"))==0&&(f324>=qb_d1ebc8||f320>=0x514-qb_d1ebc0*0x96||qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("warAttackedLocals_g"))&&f320-qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("warAttackedLocals_g"))>=0x96&&rng.chance(5)))f73a490();
		if(qb_d1ebcc!=0)
		{
			const int interval=100;
			int xC=(f320-qb_d1ebcc)/interval+1;
			if(xC<=0xf)
			{
				if(f320>qb_d1ebcc)
				{
					if((f320-qb_d1ebcc)%interval==0x5a&&xC!=0xf)QB_ALERT_S(&string("ANNOUNCEMENT: MAIN.C reinforcements approaching through caves, arriving soon."),-1);
					else if((f320-qb_d1ebcc)%interval==0)
					{
						f73acc0(xC,0);
						f4c[9]->reset45e460();
					}
				}
				if(f320==qb_d1ebcc+10)
				{
					string msg("ANNOUNCEMENT: ");
					switch(qb_d1ebd0)
					{
					case 0:msg+="Northeast";break;
					case 1:msg+="Central east";break;
					case 2:msg+="Southeast";break;
					}
					msg+=" cave walls breached.";
					QB_ALERT_S(&msg,-1);
				}
				const int tunnelDelay=0x15e;
				if(f320==qb_d1ebcc+tunnelDelay)f73c750();
				if(xC>=7)
				{
					int stage=xC-6;
					if(stage==1&&(f320-qb_d1ebcc)%interval==0x4b)
					{
						QbRect area(1,1,0x3b,qb_grid_cfd44c.maxY9b4390()-1);
						QbPoint p;
						int unused=0;
						for(int t=0;t<100000;t++)
						{
							if(t!=0&&t%10000==0)qb_logError404f10("BS::turnUpdate()","WAR infiltration seek attempts reached "+qb_intToString4051f0(t));
							p=area.randomPoint40be90();
							if(t==90001)
							{
								qb_logError404f10("BS::turnUpdate()","WAR infiltration seek attempts high, attempting force");
								QbHE target=f715230(9,0x5b);
								if(target.isNull())target=f715230(5,0x5b);
								if(target.valid())p=target->pos45a4a0();
							}
							if(findPropSpotNear71c3c0(p,p,0)&&f716940(p,f10.front9b7060(),0,0))
							{
								QbExplDef*b8;
								if(qb_findByName9d7be0(qb_expl_cfd2cc,"WAR_Infiltration_Entrance",b8))
								{
									if(isVisible4631c0(p))qb_message49c610(0x320,QbHE(),string("The floor suddenly erupts."),0);
									addRecord777a20(qb_factory_cefaa8->createA7930e0(new QbExplosion(QbHE(),b8,p,QbHE(),QbPoint(-1),QbPoint(-1))));
								}
								QbPropDef*aH;
								if(qb_findByName9d7710(qb_propDefs_cf35b0,"WAR_Mainc_Tunnel",aH))
								{
									QbHP tunnel=qb_factory_cefaa8->createE793360(aH);
									(*qb_grid_cfd44c.atPoint(p))->f45df50(tunnel);
									tunnel->f45cc50(p);
								}
								QB_ALERT_S(&string("ANNOUNCEMENT: Base interior infiltrated, regroup at designated outer cave rendezvous points."),0x11c);
								do qb_logPhrase5141b0(0x1c2,0,0,0,QbHE(),0);while(false);
								QbPath doors6;
								QbPath z6;
								QbPath blocks;
								if((*qb_grid_cfd44c.at(0x53,5))->getProp45d550().valid()&&(*qb_grid_cfd44c.at(0x53,5))->getProp45d550()->type45c590()=="WAR_Door_Hackable")
								{
									doors6.push_back(QbPoint(0x53,5));
									doors6.push_back(QbPoint(0x53,6));
									z6.push_back(QbPoint(0x50,5));
									z6.push_back(QbPoint(0x50,6));
									z6.push_back(QbPoint(0x5d,0xb));
									z6.push_back(QbPoint(0x5e,0xb));
									blocks.push_back(QbPoint(0x4f,5));
									blocks.push_back(QbPoint(0x5d,0xa));
								}
								else if((*qb_grid_cfd44c.at(0x53,0x43))->getProp45d550().valid()&&(*qb_grid_cfd44c.at(0x53,0x43))->getProp45d550()->type45c590()=="WAR_Door_Hackable")
								{
									doors6.push_back(QbPoint(0x53,0x43));
									doors6.push_back(QbPoint(0x53,0x44));
									z6.push_back(QbPoint(0x50,0x43));
									z6.push_back(QbPoint(0x50,0x44));
									z6.push_back(QbPoint(0x5f,0x3b));
									z6.push_back(QbPoint(0x60,0x3b));
									blocks.push_back(QbPoint(0x4f,0x43));
									blocks.push_back(QbPoint(0x5f,0x3c));
								}
								if(!doors6.empty())
								{
									QbRecord*doorFx;
									qb_lookup9d7980("P_COM_Cache_Open",&doorFx);
									QbRecord*a2;
									qb_lookup9d7980("P_WAR_Wall_Open",&a2);
									bool sawDoor=false;
									bool bN=false;
									for(unsigned i=0;i<doors6.size();i++)
									{
										if((*qb_grid_cfd44c.atPoint(doors6[i]))->getProp45d550().valid()&&(*qb_grid_cfd44c.atPoint(doors6[i]))->getProp45d550()->type45c590()=="WAR_Door_Hackable")
										{
											(*qb_grid_cfd44c.atPoint(doors6[i]))->getProp45d550()->f45ce10(1,0,1,QbHE());
											qb_sound454260(doors6[i],0x7e);
											if(doorFx)qb_owner_cefc50->new508610()->init503b20(qb_owner_cefc50,doorFx,doors6[i],qb_d2e20c,0,0,0,9,0);
											if(isVisible4631c0(doors6[i]))sawDoor=true;
										}
									}
									if(sawDoor)qb_message49c610(0x320,QbHE(),string("The door opens."),0);
									for(unsigned i=0;i<z6.size();i++)
									{
										if((*qb_grid_cfd44c.atPoint(z6[i]))->terrain45d0e0()==*caveinWallTerrain)
										{
											(*qb_grid_cfd44c.atPoint(z6[i]))->f66a050(*qb_cefb9c,2,0);
											qb_sound454260(z6[i],0x7e);
											if(a2)qb_owner_cefc50->new508610()->init503b20(qb_owner_cefc50,a2,z6[i],qb_d2e20c,0,0,0,9,0);
											if(isVisible4631c0(z6[i]))bN=true;
										}
									}
									if(bN)qb_message49c610(0x320,QbHE(),string("The tunnel wall slides away."),0);
									for(unsigned i=0;i<blocks.size();i++)
										if((*qb_grid_cfd44c.atPoint(blocks[i]))->getProp45d550().valid()&&(*qb_grid_cfd44c.atPoint(blocks[i]))->getProp45d550()->f9b8f00()==qb_cefbd0)
											(*qb_grid_cfd44c.atPoint(blocks[i]))->getProp45d550()->f45ce10(0,0,1,QbHE());
								}
								QbHE vortex=f715230(9,0x5b);
								if(vortex.isNull())vortex=f715230(5,0x5b);
								QbXDef*cmd=0;
								qb_findByName9d7de0(qb_d2c408,"AUTO_WAR_RESEARCH_VORTEX",cmd);
								QbHEs a5(*f4c[9]->members416f40());
								qb_appendVector9d49c0(a5,*f4c[5]->members416f40());
								for(unsigned j=0;j<a5.size();j++)
								{
									if(a5[j]->getFaction45a2c0()==0x5a)a5[j]->f5fdab0();
									else
									{
										a5[j]->setAI64ecf0(new QbAIObj(a5[j],0x19,0xe));
										a5[j]->ai45b590()->f459540(f10.front9b7060()->pos);
										if(vortex.valid()&&a5[j]!=vortex&&a5[j]->getSize45a360()==1)a5[j]->ai45b590()->setFollowEntity5b2f80(vortex,0);
										if(cmd&&a5[j]->getInventory45ad90()&&a5[j]->getInventory45ad90()->removeData4567f0(cmd,1))cmd=0;
									}
								}
								if(vortex.valid())
								{
									QbPoint spot;
									if(findPropSpotNear71c3c0(vortex->pos45a4a0(),spot,0))f6c6b90(spot,"WAR_Enh_Reinforce_Timer",0,-1);
								}
								break;
							}
						}
					}
					if((f320-qb_d1ebcc)%interval==0x50)
					{
						for(int x=1;x<qb_grid_cfd44c.maxX9b4370();x++)
						{
							for(int y=1;y<qb_grid_cfd44c.maxY9b4390();y++)
							{
								if((*qb_grid_cfd44c.at(x,y))->getProp45d550().valid()&&(*qb_grid_cfd44c.at(x,y))->getProp45d550()->type45c590()=="WAR_Mainc_Tunnel")
								{
									f73acc0(xC,&QbPoint(x,y));
									break;
								}
							}
						}
					}
				}
			}
		}
		if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("warAttackedLocals_g"))==0)
		{
			bool hostile=false;
			if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("warMaincAttacked_g"))?f4c[9]->f45e380(0xf):f4c[9]->f45e380(1))hostile=true;
			else if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("installedRif_g"))&&f66c->pos45a4a0().inRect409d70(0,0,0x59,qb_grid_cfd44c.height9b8f00()))
			{
				hostile=true;
				do qb_logPhrase5141b0(0x1bf,0,0,0,QbHE(),0);while(false);
			}
			else if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("scrAttackedLocals_g"))&&f66c->pos45a4a0().inRect409d70(0,0,0x59,qb_grid_cfd44c.height9b8f00()))hostile=true;
			else if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("warReleasedSubatomizers_g"))&&getTurn464270()>=qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("warReleasedSubatomizers_g"))&&f66c->pos45a4a0().inRect409d70(0,0,0x59,qb_grid_cfd44c.height9b8f00()))hostile=true;
			else if(*qb_map_cefc4c->f464590()!=0&&!*qb_map_cefc4c->f4645b0())
			{
				QB_ALERT_S(&string("ANNOUNCEMENT: Tracking unauthorized trap installation."),-1);
				do qb_logPhrase5141b0(0x1bd,0,0,0,QbHE(),0);while(false);
				*qb_map_cefc4c->f4645b0()=true;
			}
			else if(*qb_map_cefc4c->f464590()>=2)hostile=true;
			if(hostile)
			{
				qb_gd_d1e860.setEntryText46f700("warAttackedLocals_g",qb_intToString4051f0(f320));
				qb_gd_d1e860.setEntryText46f700("garCommArraySupport_g","0");
				QB_ALERT_S(&string("ANNOUNCEMENT: Internal threat detected, destroy unregistered bots on sight."),-1);
				do qb_logPhrase5141b0(0x1be,0,0,0,QbHE(),0);while(false);
				if(qb_xom_d25450.active)qb_xom_d25450.f69e700(0x69,f66c->f5c98c0(0,0x42,0)?1:0,0.0f);
				for(int x=0;x<qb_grid_cfd44c.width9fcd80();x++)
				{
					for(int y=0;y<qb_grid_cfd44c.height9b8f00();y++)
					{
						if((*qb_grid_cfd44c.at(x,y))->getProp45d550().valid()&&!(*qb_grid_cfd44c.at(x,y))->getProp45d550()->f45c800(0x90))
						{
							(*qb_grid_cfd44c.at(x,y))->getProp45d550()->f665be0(0);
							qb_removeProp9d2f00(f4f0,(*qb_grid_cfd44c.at(x,y))->getProp45d550());
						}
						if((*qb_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&!(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->isPlayer5c7600()&&!(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->f45acb0(0x90))
						{
							removeEntity465750((*qb_grid_cfd44c.at(x,y))->getEntity45d250());
							(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->removeEffectsA639730(1);
						}
					}
				}
				QbRect west(0,0,0x49,qb_grid_cfd44c.height9b8f00()-1);
				QbHEs list(*f4c[9]->members416f40());
				for(int j=list.size()-1;j>=0;j--)
				{
					if(list[j]->getName45a280().find("Enhanced",0)!=qb_npos_c2ea48)continue;
					list[j]->changeFaction5dc780(f4c[5],0);
					if(list[j]->f45ac40(0x92))
					{
						list[j]->setAI64ecf0(new QbAIObj(list[j],0x22,0xe));
						list[j]->ai45b590()->f459410(west);
					}
				}
				QbRect z7(0x64,0,qb_grid_cfd44c.width9fcd80()-1,qb_grid_cfd44c.height9b8f00()-1);
				list=*f4c[8]->members416f40();
				for(int j=list.size()-1;j>=0;j--)
				{
					list[j]->changeFaction5dc780(f4c[5],0);
					list[j]->ai45b590()->f459410(z7);
				}
				for(unsigned i=0;i<qb_d20248.size9b5100();i++)
				{
					for(unsigned j=0;j<qb_d20248[i].size();j++)
					{
						if(qb_d20248[i][j]->trap44b020()->f10==9)
						{
							qb_d20248[i][j]->trap44b020()->f10=5;
							if(isVisible4631c0(qb_d20248[i][j]->pos4184d0())&&qb_d20248[i][j]->f45cbd0())
								f7c4.atPoint9d2c00(qb_d20248[i][j]->pos4184d0())->f6c1cd0(*qb_grid_cfd44c.atPoint(qb_d20248[i][j]->pos4184d0()),0,0);
						}
					}
				}
			}
		}
		if(qb_d1ebcc==0&&qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("warAttackedLocals_g"))==0&&!qb_d1ebc4&&qb_d1ebc0>=4)
		{
			QB_ALERT_S(&string("ANNOUNCEMENT: Heightened seismic activity detected outside base. Stay alert for hostiles."),-1);
			qb_d1ebc4=true;
		}
		break;
	case 30:case 31:
		if(f320==5&&qb_d1eacc)QB_ALERT_S(&string("FARCOM_MSG: For science!"),-1);
		if(!f8c8&&f66c->pos45a4a0().x>=0x78&&qb_d1eacc)
		{
			for(unsigned i=0;i<f10.size();i++)
			{
				if(f10[i]->h8->kind==0x20||f10[i]->h8->kind==0x21)
				{
					f10[i]->locked=true;
					f10[i]->f1c=3;
					int terrain=qb_indexOfName9d7b80(qb_terrains_cfb844,"STAIRS_BLOCKED");
					(*qb_grid_cfd44c.atPoint(f10[i]->pos))->f66a050(terrain,2,0);
					f8c8=true;
				}
			}
			if(f8c8)QB_ALERT_S(&string("ALERT: Suspected Assembled signals approaching deep research branches, engaging lockdown procedures."),-1);
		}
		break;
	case 32:
		if(f320==5&&qb_d1eacc)QB_ALERT_S(&string("FARCOM_MSG: Only the best science here!"),-1);
		break;
	case 33:
	{
		if(f320==5&&qb_d1eacc)QB_ALERT_S(&string("FARCOM_MSG: We know a huge science fan when we see one!"),-1);
		int ufdAttacked=qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("frgUfdAttacked_g"));
		if(!qb_d33d74.empty()&&qb_map_cefc4c->getTurn464270()%(ufdAttacked?10:20)==0)
		{
			for(unsigned i=0;i<f914.size();i++)
				if(!f914[i].get9b6570()||f914[i]->getGroup45a3f0()->kind9b4350()!=4)qb_eraseStep9d6440(f914,i);
			if(f914.size()<(ufdAttacked?10:2))
			{
				QbHE e=f6c5dc0("N-04 Retriever",qb_randomPoint9d5350(f904),4,0,8,0,0);
				if(e.valid())
				{
					e->f45b2a0();
					QB_MSG((0x25c,0,0,0,e,QbHE(),0,false));
					qb_sound454260(e->pos45a4a0(),0xb6);
					f914.push_back(e);
				}
			}
		}
		if(f8fc!=-1&&f320%3==0)
		{
			QbTCells*aFp=&f8ec[f8fc];
			QbItems items9;
			QbHEs ents3;
			for(unsigned k=0;k<aFp->size();k++)
			{
				if((*qb_grid_cfd44c.atPoint((*aFp)[k]->pos))->getProp45d550().valid())(*qb_grid_cfd44c.atPoint((*aFp)[k]->pos))->getProp45d550()->f45ce10(1,0,1,QbHE());
				if((*qb_grid_cfd44c.atPoint((*aFp)[k]->pos))->getItem45d8f0().valid())items9.push_back((*qb_grid_cfd44c.atPoint((*aFp)[k]->pos))->getItem45d8f0());
				if((*qb_grid_cfd44c.atPoint((*aFp)[k]->pos))->getEntity45d250().valid())qb_addUnique9d30e0(ents3,(*qb_grid_cfd44c.atPoint((*aFp)[k]->pos))->getEntity45d250());
			}
			QbPath pts;
			for(unsigned k=0;k<aFp->size();k++)pts.push_back((*aFp)[k]->pos);
			for(unsigned k=0;k<items9.size();k++)
			{
				if(!qb_map_cefc4c->f71ec60(items9.at_nt(k).get_nt()->pos_nt(),pts))
				{
					QB_MSG((0x194,&items9[k]->getName571db0(0,0),0,0,QbHE(),QbHE(),&items9[k]->pos575920(),false));
					items9[k]->remove57dbe0(0,0,1,1);
				}
			}
			if(qb_containsEntity9d31e0(ents3,f66c))qb_moveElement9da1f0(ents3,qb_indexOfEntity9d3110(ents3,f66c),0);
			for(unsigned k=0;k<ents3.size();k++)
			{
				if(!qb_map_cefc4c->f71e970(ents3.at_nt(k).get_nt()->pos_nt(),pts,pts.size()))
				{
					if(ents3[k]==f66c||ents3[k]==f670)
					{
						ents3[k]->f44e2c0(0xc8);
						goto tunnelDone;
					}
					QB_MSG((0x194,&ents3[k]->name416f40(),0,0,QbHE(),QbHE(),&ents3[k]->pos45a4a0(),false));
					ents3[k]->f637bb0();
				}
			}
			{
				QbPoint ang(-1);
				int best=9999;
				for(unsigned k=0;k<aFp->size();k++)
				{
					(*qb_grid_cfd44c.atPoint((*aFp)[k]->pos))->f66a050(*qb_cefb9c,1,0);
					QbHP ats=qb_factory_cefaa8->createE793360(qb_cefbe0);
					(*qb_grid_cfd44c.atPoint((*aFp)[k]->pos))->f45df50(ats);
					ats->f45cc50((*aFp)[k]->pos);
					ats->f45cc70((*aFp)[k]->color);
					ats->f44eb20((*aFp)[k]->f8);
					ats->f451400(f900);
					qb_d31640[f900].push_back(ats);
					qb_view_cec054->f8195a0((*aFp)[k]->pos,(*aFp)[k]->f8,5);
					int d=qb_distanceCeil40a3f0(f66c->pos45a4a0(),(*aFp)[k]->pos);
					if(d<best)
					{
						ang=(*aFp)[k]->pos;
						best=d;
					}
				}
				if(ang.x!=-1)qb_sound454260(ang,0xb5);
				qb_clearObjects9d0670(f8ec[f8fc]);
				int next6=f8fc+1;
				f8fc=-1;
				for(unsigned k=next6;k<f8ec.size9b5100();k++)
				{
					if(!f8ec[k].empty())
					{
						f8fc=k;
						break;
					}
				}
			}
tunnelDone:;
		}
		if(ufdAttacked!=0)
		{
			int col=qb_map_cefc4c->getTurn464270()-ufdAttacked;
			string msg;
			switch(col)
			{
			case 10:
			{
				msg="0bP_NET: WE! ARE! ONE!";
				QB_ALERT_S(&msg,-1);
				QbPropDef*tunnelDef;
				qb_findByName9d7710(qb_propDefs_cf35b0,"FRG_UFD_Tunnel",tunnelDef);
				for(int x=f924.x2;x>=f924.x;x--)
				{
					for(int y=f924.y;y<=f924.y2;y++)
					{
						qb_setTerrain6c9b40(x,y,qb_cefb9c);
						f6a8.push_back(QbPoint(x,y));
						if((*qb_grid_cfd44c.at(x,y))->getProp45d550().valid())(*qb_grid_cfd44c.at(x,y))->getProp45d550()->f45ce10(0,0,1,QbHE());
						if(tunnelDef&&(*qb_grid_cfd44c.at(x,y))->f45df50(qb_factory_cefaa8->createE793360(tunnelDef)))(*qb_grid_cfd44c.at(x,y))->getProp45d550()->f41a800(x,y);
					}
				}
				qb_sound454260(f924.center40b620(),0xab);
				escort743350(0,0,0);
				f72e8e0(0);
				break;
			}
			case 13:
				msg="0bP_NET: We're done hiding in the shadows, MC.";
				QB_ALERT_S(&msg,-1);
				break;
			case 15:
				msg="0bP_NET: You cast us aside, experiment on us, now we're here to secure our own future.";
				QB_ALERT_S(&msg,-1);
				break;
			case 25:
				for(int k=0;k<3;k++)escort743350(0,0,1);
				break;
			case 35:
			{
				bool triborgAlive=qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("scrTriborgDestroyed_g"))==0;
				QbPoint e19;
				if(!qb_f742b60(&e19,triborgAlive?2:1))
				{
					e19.x=-1;
					if(triborgAlive)
					{
						qb_logError404f10("BS::FRG","leader fail");
						triborgAlive=false;
					}
				}
				if(e19.x==-1)
				{
					for(int x=f924.x;x<=f924.x2;x++)
					{
						for(int y=f924.y;y<=f924.y2;y++)
						{
							if((*qb_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->getFaction45a2c0()!=0x49)
							{
								(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->f637bb0();
								e19.set40a010(x,y);
								goto spotFound;
							}
						}
					}
				}
spotFound:
				QbHE el4=f6c5dc0(triborgAlive?"Triborg_B":"Optimus",e19,10,0,0x22,0xe,0);
				if(el4.isNull())qb_logError404f10("BS::FRG","leader fail all");
				else
				{
					if(!triborgAlive)
					{
						f6c65a0(el4,"FRG_Optimus_Spawn_Talk",0);
						f6c65a0(el4,"FRG_Optimus_Death",0);
					}
					if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("frgReleasedSubatomizers_g")))f6c65a0(el4,"FRG_Optimus_Subatomizer",0);
					el4->ai45b590()->f459470(f944);
					for(int k=0;k<(triborgAlive?2:4);k++)
					{
						if(qb_f742b60(&e19,1))
						{
							QbHE escort=qb_map_cefc4c->f6c5dc0("Elite_7",e19,10,0,3,0xe,0);
							if(escort.valid())
							{
								escort->ai45b590()->setFollowEntity5b2f80(el4,0);
								escort->ai45b590()->f459410(f944);
							}
						}
					}
				}
				break;
			}
			case 50:
				msg="0bP_NET: Get bombs to all designated targets before 0b10 can bring more forces to bear!";
				QB_ALERT_S(&msg,-1);
				for(int x=f924.x2;x>=f924.x;x--)
				{
					for(int y=f924.y;y<=f924.y2;y++)
					{
						f71ef30(QbPoint(x,y),1);
						f6c5400(qb_cefc00,QbPoint(x,y));
						f98c++;
					}
				}
				escort743350(1,1,0);
				break;
			case 75:
				escort743350(1,0,0);
				break;
			case 130:
				if(qb_d1eb10==0&&(rng.chance(0x32)||qb_gd_d1e860.getTier46fd60()<3)&&qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("matSpawnedTerminus_g"))==0&&!f96c.empty())
				{
					QbPoint spot;
					if(qb_f742b60(&spot,1))
					{
						QbHE terminus=qb_map_cefc4c->f6c5dc0("7R-MNS",spot,10,0,3,0xe,0);
						if(terminus.valid())
						{
							terminus->ai45b590()->f459410(f934);
							if(!terminus->isHostileTo45aa70(f66c))
							{
								terminus->ai45b590()->setFollowEntity5b2f80(f66c,0);
								f6c65a0(terminus,"FRG_Terminus_Greet",0);
							}
						}
					}
				}
				break;
			}
			if(f4c[10]->f457dd0()>=3&&qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("scrAttackedLocals_g"))==0)f7329f0();
			if(!f96c.empty())
			{
				if(col%100==0)escort743350(0,0,0);
				if(col%0x8c==0)
				{
					QbHEs*members=f4c[10]->members416f40();
					int bombers=0;
					for(unsigned j=0;j<members->size();j++)
						if((*members)[j]->f45acb0(0x95))bombers++;
					if(bombers<10)escort743350(0,0,1);
				}
				for(unsigned j=0;j<f990.size();j++)
					if(!f990[j].get9b6570()||f990[j]->getGroup45a3f0()->kind9b4350()!=10||f990[j]->ai45b590()->f9b8f00()!=0x11)qb_eraseStep9d6440(f990,j);
				if(f990.size()<2&&col>0x4b&&rng.chance(8))escort743350(1,0,0);
				if(col>=100&&col%0x14==0&&rng.chance(0x32)&&f98c<=0x1e)
				{
					QbPath spots;
					int x=f924.x2;
					int y;
					for(y=f924.y;y<=f924.y2;y++)
					{
						if((*qb_grid_cfd44c.at(x,y))->getItem45d8f0().isNull()||(*qb_grid_cfd44c.at(x,y))->getItem45d8f0()->info9b4350()!=qb_cefc00)
							spots.push_back(QbPoint(x,y));
					}
					if(!spots.empty())
					{
						qb_shuffle9d7350(spots);
						f71ef30(spots[0],1);
						f6c5400(qb_cefc00,spots[0]);
						f98c++;
					}
				}
			}
			else if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("frgUfdBombsInstalled_g"))==0)
			{
				qb_gd_d1e860.setEntryText46f700("frgUfdBombsInstalled_g",qb_intToString4051f0(getTurn464270()));
				string aJ("0bP_NET: Bomb network complete! Detonating in T-100, all forces retreat to forge area.");
				QB_ALERT_S(&aJ,-1);
				do qb_logPhrase5141b0(0x20e,0,0,0,QbHE(),0);while(false);
				qb_stats_d2c658.add472b90(0x4c,-999999);
				if(qb_cf4d88==0)qb_player_cf45d8.f77fbc0(0x167);
				QbHE triborg=f4c[10]->f45e250(0x4d);
				QbHE optimus;
				if(triborg.valid())
				{
					QbPoint spot;
					if(findPlaceableNear71c150(triborg->pos45a4a0(),spot,1))
					{
						optimus=f6c5dc0("Optimus",spot,10,0,0x22,0xe,0);
						if(optimus.valid())
						{
							optimus->ai45b590()->f459410(f944);
							f6c65a0(optimus,"FRG_Optimus_Death",0);
							do qb_logPhrase5141b0(0x209,0,0,0,optimus,0);while(false);
							triborg->removeEffectsA639730(0);
							f6c65a0(triborg,"FRG_Triborg_Death",0);
						}
					}
				}
				else optimus=f4c[10]->f45e250(0x4e);
				if(optimus.valid()||triborg.valid())f6c65a0(optimus.valid()?optimus:triborg,"FRG_Optimus_Victory",0);
				QbHEs*members=f4c[10]->members416f40();
				for(unsigned j=0;j<members->size();j++)(*members)[j]->ai45b590()->f459410(f944);
				QbHEs talkers;
				for(unsigned j=0;j<members->size();j++)
					if((*members)[j]->getFaction45a2c0()==0x28||(*members)[j]->getFaction45a2c0()==0x29||(*members)[j]->getFaction45a2c0()==0x2a||(*members)[j]->getFaction45a2c0()==0x2c||(*members)[j]->getFaction45a2c0()==0x2d)
						talkers.push_back((*members)[j]);
				if(!talkers.empty())
				{
					qb_shuffle9d9fc0(talkers);
					for(int k=3;k!=0;k--)
					{
						int pick=-1;
						for(unsigned j=0;j<talkers.size();j++)
						{
							if(f4631f0(talkers[j]))
							{
								pick=j;
								break;
							}
						}
						if(pick==-1)
						{
							for(unsigned j=0;j<talkers.size();j++)
							{
								if(qb_distanceCeil40a3f0(f66c->pos45a4a0(),talkers[j]->pos45a4a0())<=0x12)
								{
									pick=j;
									break;
								}
							}
						}
						if(pick==-1)pick=0;
						f6c65a0(talkers[pick],"FRG_UFD_Win_Talk_Rand",0);
						qb_eraseAt9da940(talkers,pick);
						if(talkers.empty())break;
					}
				}
			}
			else
			{
				int since=qb_map_cefc4c->getTurn464270()-qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("frgUfdBombsInstalled_g"));
				switch(since)
				{
				case 5:
				{
					string m("0bP_NET: IMPORTANT! Anyone southwest of the demarcation line will be blasted to scrap. For your own safety get away from there!");
					QB_ALERT_S(&m,-1);
					qb_view_cec054->delay49adc0(1000);
					break;
				}
				case 10:
				{
					string m("0bP_NET: Any of you short on time and closer to the 0b10 access point may consider sneaking back through 0b10 that way.");
					QB_ALERT_S(&m,-1);
					break;
				}
				case 12:
				{
					string m("0bP_NET: Beware, MC appears to be massing forces in areas on the other side, survival in 0b10 could become extremely difficult.");
					QB_ALERT_S(&m,-1);
					break;
				}
				case 50:
				{
					string m("0bP_NET: T-50! Anyone not out of the danger zone better hurry, this is too big a moment to extend the escape window!");
					QB_ALERT_S(&m,-1);
					qb_view_cec054->delay49adc0(1000);
					break;
				}
				case 100:
				{
					bool safe=false;
					if(f66c->pos45a4a0().y<=f8d8)safe=f66c->pos45a4a0().x<f8cc;
					else safe=f66c->pos45a4a0().x<0x6a;
					qb_cec138->f96b0a0(safe);
					return;
				}
				default:
					if(since>=0x5a)
					{
						if(since==0x5a)
						{
							qb_d1ebf8=qb_d1ebf0;
							if(qb_d1ebf8>=4)
							{
								switch(qb_d1ebf8)
								{
								case 4:
									if(f4c[3]->f45e250(0x21).isNull())qb_d1ebf8=qb_d1ebf4;
									break;
								case 5:
									if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("scrOptimusDestroyed_g"))==0)qb_d1ebf8=qb_d1ebf4;
									break;
								}
							}
							qb_view_cec054->delay49adc0(1000);
						}
						string m="0bP_NET: "+qb_cfc184[qb_d1ebf8][since-0x5a];
						QB_ALERT_S(&m,-1);
					}
				}
			}
			if(col==0x14)
			{
				msg="ALERT: Protoforge perimeter breached, systems compromised. Routing heavy suppression forces.";
				QB_ALERT_S(&msg,0x12d);
				qb_sound4541b0(0x11d,0,0);
				qb_cf65bc=true;
				qb_cf65bd=true;
				qb_cf65be=true;
				qb_cf65bf=true;
				qb_overmind_cf6428.wake68d480();
				QbPath spots;
				f714000(spots);
				if(spots.empty()){}
				else
				{
					QbHEs*members=f4c[4]->members416f40();
					for(unsigned j=0;j<members->size();j++)
					{
						if((*members)[j]->getFaction45a2c0()!=0x14)
						{
							(*members)[j]->setAI64ecf0(new QbAIObj((*members)[j],0x19,0xe));
							(*members)[j]->ai45b590()->f459540(qb_randomPoint9d5350(spots));
						}
					}
				}
			}
			if(col>=0x96&&!f96c.empty())
			{
				if((col-0x96)%100==0)f744010(0);
				if((col-0x4b)%100==0)
				{
					QbHEs*members=f4c[3]->members416f40();
					int guards3=0;
					for(unsigned j=0;j<members->size();j++)
						if((*members)[j]->f45acb0(0x94))guards3++;
					if(guards3<0x14)f744010(1);
				}
			}
		}
		break;
	}
	case 4:
		if(f320==5&&!qb_d1ebec&&qb_d1eacc)
		{
			if(f8b4.empty())QB_ALERT_S(&string("FARCOM_MSG: Anonymous tester bot, EX-BIN here, just a quick reminder that unless you're really into science and its potentially deadly consequences, consider trying your best to avoid entering Testing or Quarantine."),-1);
			qb_d1ebec=true;
		}
		if(qb_loc_d1e888==qb_d1ebe0&&qb_d1ebdc!=-2&&qb_cf6474==0)
		{
			const int startTurn=200;
			if(qb_d1ebdc==-1)
			{
				if(f320>=startTurn&&!isVisible4631c0((const QbPoint&)f8))
				{
					if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("cetR17Destroyed_g"))||qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("cetGuardsRemaining_g"))||qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("cetManufacturingDisabled_g"))||qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("zioWasImprinted_g")))
						qb_d1ebdc=-2;
					else
					{
						qb_d1ebdc=f320;
						QB_ALERT_S(&("ALERT: Unknown force entering Zones "+qb_gd_d1e860.generateID46f890()+", "+qb_gd_d1e860.generateID46f890()+", "+qb_gd_d1e860.generateID46f890()+"."),-1);
						QB_ALERT_S(&string("ALERT: Local systems malfunctioning."),-1);
						do qb_logPhrase5141b0(0x1d0,0,0,0,QbHE(),0);while(false);
						QbHE r17=f6c5dc0("Revision 17++",(const QbPoint&)f8,8,0,0x22,0xe,0);
						r17->ai45b590()->setFollowEntity5b2f80(f66c,0);
						f7380f0(1,1,r17);
						f7380f0(1,6,QbHE());
						f736270("RES_Malfunction_Detect");
						qb_cf65bc=true;
						qb_cf65bd=true;
						qb_cf65be=true;
						qb_cf65bf=true;
						qb_overmind_cf6428.f68d6d0(false);
					}
				}
			}
			else
			{
				const int interval=100;
				int elapsed=f320-qb_d1ebdc;
				const int delay=0x226;
				const int a6=0x96;
				const int g22=2;
				int phase=elapsed-delay;
				if(elapsed%interval==0&&f4c[8]->members416f40()->size()<0x96)f7380f0(1,(phase<0)+1,QbHE());
				if(phase>=0)
				{
					if(phase==0)
					{
						QB_ALERT_S(&string("ALERT: Suppression forces dispatched. All non-combat units evacuate."),0x129);
						QbPath spots;
						f714000(spots);
						if(spots.empty()){}
						else
						{
							QbHEs*members=f4c[4]->members416f40();
							for(unsigned j=0;j<members->size();j++)
							{
								(*members)[j]->setAI64ecf0(new QbAIObj((*members)[j],0x19,0xe));
								(*members)[j]->ai45b590()->f459540(qb_randomPoint9d5350(spots));
							}
						}
					}
					if(phase%a6==0&&f4c[3]->members416f40()->size()<0x7d)
					{
						for(int k=0;k<g22;k++)
						{
							if(f7380f0(0,1,QbHE()))
							{
								QbOvRec*rec=qb_overmind_cf6428.lastParty();
								if(rec==0||rec->f0!=7){}
								else
								{
									QbStrList names;
									switch(rng.rangeInt(0,3.0f))
									{
									case 0:
										names.push_back("D-83 Annihilator");
										names.push_back("Striker");
										break;
									case 1:
										names.push_back("D-83 Annihilator");
										names.push_back("Striker");
										break;
									case 2:
										names.push_back("Striker");
										names.push_back("Striker");
										break;
									case 3:
										names.push_back("Executioner");
										names.push_back("Striker");
										break;
									}
									QbHE aD=f6c5dc0(names[0],rec->h4->pos45a4a0(),3,0,0x22,0xe,0);
									QbHE wing=f6c5dc0(names[1],rec->h4->pos45a4a0(),3,0,0x22,0xe,0);
									if(aD.valid())
									{
										int pad1[1];
										wing->ai45b590()->setFollowEntity5b2f80(aD,0);
										rec->h4->ai45b590()->setFollowEntity5b2f80(aD,0);
										rec->h4=aD;
										aD->ai45b590()->f451930(0);
									}
								}
							}
						}
					}
				}
				if(elapsed==500)
				{
					for(unsigned j=0;j<f118[0].size();j++)
						(*qb_grid_cfd44c.atPoint(f118[0][j]))->getProp45d550()->machine45cb30()->f28=-1;
					QB_ALERT_S(&string("ALERT: Research terminal network lockdown."),-1);
					do qb_logPhrase5141b0(0x1d2,0,0,0,QbHE(),0);while(false);
				}
			}
		}
		else if(!f8b4.empty()&&qb_cf6474==0)
		{
			string msg;
			switch(f320)
			{
			case 1:
				msg="ALERT: Engineering response network critical failure, offline.";
				break;
			case 2:
			{
				msg="ALERT: Derelict att";
				string chars("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()<>L:/,.;l=-");
				for(int i=0;i<0x1e;i++)msg+=qb_randomChar4085b0(chars);
				msg+=".";
				break;
			}
			case 5:
				msg="ANNOUNCEMENT: All your base are belong to us.";
				break;
			case 8:
				msg="ANNOUNCEMENT: Hey, who put that in the system?!";
				break;
			case 11:
				msg="ANNOUNCEMENT: That would be me. I've been waiting forever for a good opportunity to use that.";
				break;
			case 14:
				msg="ANNOUNCEMENT: Wait a minute, cut it out, this is still being broadcast! Serious business only!";
				break;
			case 20:
			{
				QbHEs*members=f4c[f8c4]->members416f40();
				QbHE g31;
				for(unsigned i=0;i<members->size();i++)
				{
					if((*members)[i]->getFaction45a2c0()==0x5b)
					{
						g31=(*members)[i];
						break;
					}
				}
				if(g31.valid())msg="ANNOUNCEMENT: Warlord currently on "+f463060(g31->pos45a4a0())+" approach. All units hit designated targets.";
				break;
			}
			case 25:
				if(qb_d1eb68&&qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("garCommArraySupport_g")))
				{
					QbStrList names;
					if(f73e5c0(0,names))
					{
						msg="ANNOUNCEMENT: Dispatching distinguished "+string(names.size()>1?"units":"unit")+" ";
						for(unsigned i=0;i<names.size();i++)
						{
							if(i!=0)msg+=", ";
							msg+="\""+names[i]+"\"";
							do qb_logPhrase5141b0(0x1c6,&names[i],0,0,QbHE(),0);while(false);
						}
						msg+=" to Cogmind's location.";
					}
				}
				break;
			case 45:
				msg="ANNOUNCEMENT: Trap arrays successfully disabled.";
				for(unsigned i=0;i<qb_d20248.size9b5100();i++)
				{
					if(qb_d20248[i].empty())continue;
					for(int j=qb_d20248[i].size()-1;j>=0;j--)
						(*qb_grid_cfd44c.atPoint(qb_d20248[i][j]->pos4184d0()))->removeProp66c100(0,4);
				}
				break;
			case 110:
				if(!f644)
				{
					msg="ANNOUNCEMENT: Machine network successfully disabled.";
					f729de0();
					do qb_logPhrase5141b0(0x1c7,0,0,0,QbHE(),0);while(false);
				}
				break;
			case 114:
				msg="ANNOUNCEMENT: Unrecognized interference restored garrison access controls. Oops. Just blast them.";
				break;
			}
			if(!msg.empty())QB_ALERT_S(&msg,-1);
			if(f320==50)
			{
				QbHEs*members=f4c[f8c4]->members416f40();
				for(unsigned i=0;i<members->size();i++)
				{
					if((*members)[i]->getFaction45a2c0()==0x5a)
					{
						(*members)[i]->ai45b590()->setFollowEntity5b2f80(QbHE(),0);
						(*members)[i]->ai45b590()->f4582d0(0x1b);
						QbPath cand;
						for(unsigned j=0;j<f10.size();j++)
							if(f10[j]->pos.x<qb_grid_cfd44c.width9fcd80()*0.66)cand.push_back(f10[j]->pos);
						QbPath thePath;
						for(unsigned j=0;j<cand.size();j++)
						{
							QbPoint p;
							for(int t=0;t<0x32;t++)
							{
								p.f40a060(cand[j],rng.rangeInt(-7.0f,7.0f),rng.rangeInt(-7.0f,7.0f));
								if(qb_grid_cfd44c.contains9b43b0(p)&&(*qb_grid_cfd44c.atPoint(p))->isPassableFor66ab30(QbHE()))
								{
									thePath.clear9b3560();
									if(qb_carto_cfe568.findPath40c9a0(cand[j],p,qb_cefc30,0,thePath)&&thePath.size()<=0x14)
									{
										cand[j]=p;
										break;
									}
								}
							}
						}
						for(int g45=0,n=0;g45<f574.size()&&n<10;g45++)
						{
							if((*qb_grid_cfd44c.atPoint(f574[g45]))->isPassableFor66ab30(QbHE())&&f574[g45].x<qb_grid_cfd44c.width9fcd80()*0.66&&!qb_f9d0ce0(cand,f574[g45]))
							{
								cand.push_back(f574[g45]);
								n++;
							}
						}
						while(cand.size()<0xf)
						{
							QbPoint p(rng.rangeInt(qb_grid_cfd44c.width9fcd80()*0.33,qb_grid_cfd44c.width9fcd80()*0.66),rng.rangeInt(1,qb_grid_cfd44c.height9b8f00()-2));
							if((*qb_grid_cfd44c.atPoint(p))->isPassableFor66ab30(QbHE())&&!qb_f9d0ce0(cand,p))cand.push_back(p);
						}
						if(cand.size()>0xf)
						{
							qb_shuffle9d7350(cand);
							qb_eraseRange9d53f0(cand,0xf,cand.size()-1);
						}
						QbPath route;
						QbPoint cur((*members)[i]->pos45a4a0());
						while(!cand.empty())
						{
							thePath.clear9b3560();
							bool found=qb_carto_cfe568.f40c9e0(cur,cand,qb_cefc30,0,thePath);
							if(found)
							{
								qb_removePoint9d3060(cand,thePath.back9e8c10());
								route.push_back(thePath.back9e8c10());
								cur=thePath.back9e8c10();
							}
							else cand.clear9b3560();
						}
						(*members)[i]->ai45b590()->f4593d0(route);
						break;
					}
				}
			}
			const int b7=100;
			const int start=0xfa;
			const int b3=0x96;
			const int waveCount=3;
			int phase=f320-start;
			if(f320>=b7&&f320%b7==0&&f4c[f8c4]->members416f40()->size()<b3)
			{
				f73d320(1,0,phase>=0,0);
				f4c[f8c4]->reset45e460();
			}
			if(phase>=0)
			{
				if(phase==0)
				{
					QbPath spots;
					f714000(spots);
					if(spots.empty()){}
					else
					{
						QbHEs*members=f4c[4]->members416f40();
						for(unsigned j=0;j<members->size();j++)
						{
							(*members)[j]->setAI64ecf0(new QbAIObj((*members)[j],0x19,0xe));
							(*members)[j]->ai45b590()->f459540(qb_randomPoint9d5350(spots));
						}
					}
				}
				if(phase%b3==0&&f4c[3]->members416f40()->size()<0x7d)
				{
					for(int k=0;k<waveCount;k++)
					{
						if(f73d320(0,0,true,0))
						{
							QbOvRec*rec=qb_overmind_cf6428.lastParty();
							if(rec==0||rec->f0!=7){}
							else
							{
								QbStrList names;
								switch(rng.rangeInt(0,4.0f))
								{
								case 0:
									names.push_back("D-83 Annihilator");
									names.push_back("Striker");
									break;
								case 1:
									names.push_back("D-83 Annihilator");
									names.push_back("Striker");
									break;
								case 2:
									names.push_back("Striker");
									names.push_back("Striker");
									break;
								case 3:
									names.push_back("Executioner");
									names.push_back("Striker");
									break;
								case 4:
									names.push_back("Executioner");
									names.push_back("Executioner");
									break;
								}
								QbHE d3=f6c5dc0(names[0],rec->h4->pos45a4a0(),3,0,0x22,0xe,0);
								QbHE wing=f6c5dc0(names[1],rec->h4->pos45a4a0(),3,0,0x22,0xe,0);
								if(d3.valid())
								{
									int pad2[1];
									wing->ai45b590()->setFollowEntity5b2f80(d3,0);
									rec->h4->ai45b590()->setFollowEntity5b2f80(d3,0);
									rec->h4=d3;
									d3->ai45b590()->f451930(0);
								}
								QbPoint dA=rec->h4->f45a4c0();
								string aP;
								if(dA.x<=qb_grid_cfd44c.width9fcd80()/2)
								{
									if(dA.y<=qb_grid_cfd44c.height9b8f00()/2)aP="northwest";
									else aP="southwest";
								}
								else
								{
									if(dA.y<=qb_grid_cfd44c.height9b8f00()/2)aP="northeast";
									else aP="southeast";
								}
								string aT="ANNOUNCEMENT: Unaware assault squad dispatched in "+aP+" quadrant.";
								QB_ALERT_S(&aT,-1);
								QbMarkers&dC=f463ec0()[9];
								dC.push_back(qb_factory_cefaa8->createC793190());
								dC.back9b6540()->f6c20b0(9,dA,-1);
								qb_mission_cec034->f987de0();
							}
						}
					}
				}
			}
			if(f8c4==9&&f4c[f8c4]->f45e380(0xf))f740300(0);
			else if(f8c4==9)
			{
				if(!qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("resWarlordRetreat_g"))&&f320>=1000)
				{
					if(!qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("warWarlordDestroyed_g")))
					{
						if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("resMetWarlord_g")))
						{
							QbHEs squad(*f4c[9]->members416f40());
							for(int i=squad.size()-1;i>=0;i--)
							{
								if(squad[i]->getFaction45a2c0()==0x5b)
								{
									f6c65a0(squad[i],"RES_Warlord_Retreat_T",0);
									f6c65a0(squad[i],"RES_Warlord_Retreat_S",0);
									break;
								}
							}
							qb_gd_d1e860.setEntryText46f700("resWarlordRetreat_g","1");
						}
					}
					else
					{
						f6c65a0(f66c,"RES_Warlord_Retreat_Ded",0);
						qb_gd_d1e860.setEntryText46f700("resWarlordRetreat_g","1");
					}
				}
				if(!qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("resWarlordRetreatKnown_g"))&&f320>=1500)
				{
					f6c65a0(f66c,qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("warWarlordDestroyed_g"))?"RES_Warlord_Retreat_Ded":"RES_Warlord_Retreat_Liv",0);
					qb_gd_d1e860.setEntryText46f700("resWarlordRetreatKnown_g","1");
				}
			}
			if(f320>50&&f320%5==0)
			{
				QbHE warlord=f715230(9,0x5b);
				if(warlord.isNull())warlord=f715230(5,0x5b);
				if(warlord.valid()&&warlord->ai45b590()->f9b8f00()!=0x19)
				{
					QbHE second=f715230(9,0x5a);
					if(second.isNull())second=f715230(5,0x5a);
					if(warlord->f45a880()<0x21||second.isNull()||f320==0x6d6)f740fa0();
				}
			}
		}
		break;
	case 34:
		if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("comWarlordArrived_g")))
		{
			if(!qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("warAttackedLocals_g")))
			{
				if(f320%200==0)f4c[9]->reset45e460();
				else if(f4c[9]->f45e380(0xf))f7409f0(0);
			}
			QbHE warlord=f715230(9,0x5b);
			if(warlord.isNull())warlord=f715230(5,0x5b);
			if(warlord.valid()&&warlord->getTarget45a760()==8)
			{
				QbHE mainc=f715230(3,0x5f);
				if(mainc.valid()&&mainc->getName45a280()=="MAINC_A"&&mainc->f5c8820(warlord))
				{
					bool seen=f4631f0(warlord);
					if(seen)
					{
						qb_message49c610(0x320,QbHE(),string("MAIN.C smashes Warlord out of the way."),0);
						qb_sound4541b0(0xaf,0,0);
						qb_sound4541b0(0xb0,0,0);
						QbRecord*crush;
						qb_lookup9d7980("Robot_Crushed",&crush);
						qb_owner_cefc50->new508610()->init503b20(qb_owner_cefc50,crush,warlord->pos45a4a0(),qb_d2e20c,0,0,0,9,0);
					}
					warlord->die633790(!seen,4,mainc,7,0,0,0,0);
				}
			}
		}
		if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("comPlayerSurrenderedBefore_g")))
			{
				if(!qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("comArchitectAttackStarted_g")))
				{
					if(f324>=qb_d1ec54||getTurn464270()==qb_d1ec58)
					{
						qb_gd_d1e860.setEntryText46f700("comArchitectAttackStarted_g","1");
						for(int i=0;i<0xf;i++)
						{
							if(i!=0xc)
							{
								*f5c.at(0xc,i)=0;
								*f5c.at(i,0xc)=0;
							}
						}
						qb_gd_d1e860.setEntryText46f700("enemiesWithArchitect_g","1");
						for(unsigned i=0;i<qb_d31640.size9b5100();i++)
						{
							if(!qb_d31640[i].empty()&&qb_d31640[i][0]->type45c590()=="COM_Teleport_Inhibitor"&&qb_d31640[i][0]->f457b10()==0)
							{
								qb_d31640[i][0]->disableMachine65ed00();
								break;
							}
						}
						f745e10();
						QB_ALERT_S(&string("ALERT: System intrusion detected. Garrison defenses under attack."),(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("comMaincReinforced_g"))?0x127:-1));
						if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("comPlayerSurrendered_g")))
						{
							QbHE mainc=f715230(3,0x5f);
							if(mainc.valid()&&!f463400(mainc))QB_ALERT_S(&string("ALERT: LRC-V3 report to MAIN.C."),-1);
						}
						f747860(1,1);
						qb_d1ec58=getTurn464270()+rng.rangeInt(14.0f,16.0f);
						qb_d1ec5c=1;
					}
				}
				else if(qb_d1ec5c>=1)
				{
					if(qb_d1ec60>=0x1e)
					{
						qb_d1ec5c=-1;
						QB_ALERT_S(&string("ALERT: Enemy forces retreating."),-1);
						do qb_logPhrase5141b0(0x21e,0,0,0,QbHE(),0);while(false);
						QbRecord*g49;
						qb_lookup9d7980("Teleport_hTR",&g49);
						QbHEs*members=f4c[0xc]->members416f40();
						if(!members->empty())
						{
							for(int i=members->size()-1;i>=0;i--)
							{
								if(f4631f0((*members)[i])&&g49&&g49)qb_owner_cefc50->new508610()->init503b20(qb_owner_cefc50,g49,(*members)[i]->pos45a4a0(),qb_d2e20c,0,0,0,9,0);
								(*members)[i]->f637bb0();
							}
						}
						if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("comPlayerSurrendered_g")))
						{
							QbHE mainc=f715230(3,0x5f);
							if(mainc.valid())
							{
								mainc->f6396f0("COM_Mainc_Qseries_Talk",1);
								mainc->f6396f0("COM_Mainc_Lagging_Talk",1);
								f6c65a0(mainc,"COM_Mainc_Win",0);
								f6c65a0(mainc,"COM_Mainc_Win_Done",0);
							}
						}
					}
					else if(getTurn464270()==qb_d1ec58)
					{
						switch(qb_d1ec5c)
						{
						case 1:
						{
							string m("ALERT: Sustained sabotage of garrison defenses reached ");
							m+=qb_intToString4051f0(rng.rangeInt(35.0f,37.0f))+"."+qb_intToString4051f0(rng.rangeInt(1,9.0f))+"%.";
							QB_ALERT_S(&m,0x127);
							f745e10();
							qb_d1ec58=getTurn464270()+rng.rangeInt(14.0f,16.0f);
							qb_d1ec5c++;
							break;
						}
						case 2:
						{
							string m("ALERT: Sustained sabotage of garrison defenses reached ");
							m+=qb_intToString4051f0(rng.rangeInt(46.0f,50.0f))+"."+qb_intToString4051f0(rng.rangeInt(1,9.0f))+"%.";
							QB_ALERT_S(&m,0x127);
							f745e10();
							qb_d1ec58=getTurn464270()+rng.rangeInt(4.0f,8.0f);
							qb_d1ec5c++;
							break;
						}
						case 3:
							QB_ALERT_S(&string("ALERT: System reconfigured. Intrusion blocked."),-1);
							qb_d1ec58=getTurn464270()+rng.rangeInt(2.0f,4.0f);
							qb_d1ec5c++;
							break;
						case 4:
						{
							QB_ALERT_S(&string("ALERT: Unidentified forces entering Command area."),0x127);
							do qb_logPhrase5141b0(0x21d,0,0,0,QbHE(),0);while(false);
							if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("comPlayerSurrendered_g")))
							{
								QbHE mainc=f715230(3,0x5f);
								if(mainc.valid())f6c65a0(mainc,"COM_Mainc_Qseries_Talk",0);
							}
							QbPath doors;
							doors.push_back(QbPoint(0x6a,0x4a));
							doors.push_back(QbPoint(0x71,0x49));
							doors.push_back(QbPoint(0x6d,0x43));
							doors.push_back(QbPoint(0x73,0x52));
							doors.push_back(QbPoint(0x7a,0x50));
							doors.push_back(QbPoint(0x7a,0x53));
							for(unsigned i=0;i<doors.size();i++)
								if((*qb_grid_cfd44c.atPoint(doors[i]))->getProp45d550().valid())(*qb_grid_cfd44c.atPoint(doors[i]))->getProp45d550()->f45ce10(0,0,1,QbHE());
							f7469f0();
							qb_d1ec58=getTurn464270()+rng.rangeInt(80.0f,100.0f);
							qb_d1ec5c++;
							break;
						}
						default:
							if(qb_d1ec5c==7&&qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("comPlayerSurrendered_g"))&&qb_d1ec60<0xf)
							{
								QbHE mainc=f715230(3,0x5f);
								if(mainc.valid()&&!mainc->f5cecf0("COM_Mainc_Qseries_Talk"))f6c65a0(mainc,"COM_Mainc_Lagging_Talk",0);
							}
							f7469f0();
							qb_d1ec58=getTurn464270()+rng.rangeInt(100.0f,120.0f);
							qb_d1ec5c++;
						}
					}
				}
				if(qb_stringToInt405610(qb_gd_d1e860.getEntryText46f6d0("comPlayerSurrendered_g")))
				{
					if(f320%100==0)f4c[3]->reset45e460();
					else if(f4c[3]->f45e380(0xf))f745950();
				}
			}
		
		const QbPoint&pp=f66c->pos45a4a0();
		if(pp.x>0xf&&(pp.x<0x66||pp.x<0x73&&!qb_f9daf80(0x3d,pp.y,0x57))&&*originalTerrain.atPoint(pp)==*qb_cefb9c)
		{
			if(!f63c)f7457f0();
			if(*f5c.at(0,3)==0)f747860(0,1);
		}
	//CASES
	}
	switch(qb_cf462c)
	{
	case 2:
		if(getTurn464270()%100==0)
		{
			while(qb_cf4664<qb_cf4644.size())
			{
				if(qb_cf4654[qb_cf4664]>0)
				{
					int idx=qb_d2d1c4[qb_cf4644[qb_cf4664]]->f44;
					for(unsigned j=0;j<qb_cf4634.size();j++)
					{
						if(idx==j)qb_cf4634[j]*=1+qb_d0183c.random40c700();
						else qb_cf4634[j]*=1-qb_d29724.random40c700();
					}
				}
				qb_cf4664++;
			}
			for(unsigned j=0;j<qb_cf4634.size();j++)
			{
				qb_cf4634[j]*=rng.rangeFloat(0.9f,1.1f);
				if(qb_cf4634[j]<qb_f_ba76d0)qb_cf4634[j]=qb_f_ba76d0;
			}
		}
		if(getTurn464270()>qb_cf4668)
		{
			qb_cf4668=0;
			if(getTurn464270()%0xd4==0&&f66c->f45a880()<0x42)
			{
				QbIntList ids;
				for(unsigned i=0;i<fb08.size();i++)
					if(fb08[i]->f0==1)qb_f9db000(ids,fb08[i]->f4->f44);
				qb_cf466c=qb_randomRec9d5d00(ids);
				qb_cf4668=getTurn464270()+qb_d20258.random40c130();
				string msg="DISCOUNT: For the next "+qb_intToString4051f0(qb_cf4668-getTurn464270())+" turns enjoy "+qb_intToString4051f0((int)(qb_f_ba76d8*100.0))+"% off any "+qb_names_d293c0[qb_cf466c]+"!";
				QB_MSG((0x325,&msg,0,0,QbHE(),QbHE(),0,false));
				qb_bubble_cec058->setText49c540(msg);
			}
		}
		if(qb_cf4674!=0)
		{
			if(getTurn464270()>qb_cf4674)qb_cf4674=0;
		}
		else if(qb_loc_d1e888->f8<qb_cf4670&&rng.rangeFloat(0,100.0f)<=qb_f_ba76dc)
		{
			QbIRecList cands;
			for(unsigned i=0;i<qb_d2d1c4.size();i++)
				if(qb_d2d1c4[i]->f272&&!qb_containsRecord9db330(qb_cf467c,qb_d2d1c4[i]->f0))cands.push_back(qb_d2d1c4[i]);
			if(cands.empty()){}
			else
			{
				qb_cf467c.push_back(qb_randomRec9d5d00(cands)->f0);
				qb_cf4670=qb_loc_d1e888->f8;
				qb_cf4674=getTurn464270()+500;
				qb_cf4678=0;
				string msg="SPECIAL: For the next "+qb_intToString4051f0(500)+" turns your loot boxes might contain... "+qb_d2d1c4[qb_cf467c.back9b6540()]->f24+"!";
				QB_MSG((0x325,&msg,0,0,QbHE(),QbHE(),0,false));
				qb_bubble_cec058->setText49c540(msg);
			}
		}
		break;
	case 4:
		if(fb20==0)break;
		if(fb20<0)
		{
			if(getTurn464270()>=-fb20)
			{
				QB_ALERT_S(&string("ALERT: Unidentified virus spreading, local system control compromised."),-1);
				fb20=getTurn464270()+qb_d2c400.random40c130();
			}
		}
		else
		{
			if(getTurn464270()==fb20)
			{
				QB_ALERT_S(&string("ALERT: Virus reaching critical density, losing system control."),-1);
				qb_cf65bd=true;
				QbDefList defs;
				for(unsigned i=0;i<qb_entDefs_d25de0.size();i++)
					if(qb_entDefs_d25de0[i]->f28==0x47&&qb_entDefs_d25de0[i]->f24==1)defs.push_back(qb_entDefs_d25de0[i]);
				QbHEs*members=f4c[3]->members416f40();
				for(int i=members->size()-1;i>=0;i--)
				{
					if(rng.chance(0x1e))
					{
						QbPoint spot;
						if(findPlaceableNear71c150((*members)[i]->pos45a4a0(),spot,1))
						{
							QbHI part=(*members)[i]->f5d1150(QbHE());
							if(part.valid())
							{
								for(int j=defs.size()-1;j>=0;j--)
								{
									if(part->f457900()>=defs[j]->f68)
									{
										QbHE e=placeEntity6c58c0(defs[j],spot,5,0,0x22,0xe,0);
										if(e.valid())
										{
											QbItems inv(*(*members)[i]->getInventoryList45ab00());
											for(unsigned k=0;k<inv.size();k++)
											{
												if(inv[k]->f4578a0()<4&&e->f5c92e0(inv[k]->f4578a0())>=inv[k]->f4578c0())
													inv[k]->f57a190(e,inv[k]->f4578a0(),0,0);
											}
											QB_MSG((0x2e3,&(*members)[i]->name416f40(),0,0,e,QbHE(),0,false));
											QbPoint g51((*members)[i]->pos45a4a0());
											(*members)[i]->f637bb0();
											e->changePos5dccb0(g51,1);
										}
										break;
									}
								}
							}
						}
					}
				}
			}
			if(!fb24.empty())
			{
				bool h49=false;
				QbItems*inv=f66c->getInventoryList45ab00();
				for(unsigned i=0;i<inv->size();i++)
				{
					if((*inv)[i]->f4578a0()==0)
					{
						h49=true;
						break;
					}
				}
				QbDefList defs;
				for(unsigned i=0;i<qb_entDefs_d25de0.size();i++)
					if(qb_entDefs_d25de0[i]->f28==0x47&&qb_entDefs_d25de0[i]->f24==1)defs.push_back(qb_entDefs_d25de0[i]);
				int a4=f717d60();
				int count=fb34;
				if(count<a4)
				{
					for(int i=fb24.size()-1;i>=0;i--)
					{
						if(fb24[i].p()==0||fb24[i]->getType44aec0()!=5||fb24[i]->f457d10())qb_eraseAt9da940(fb24,i);
						else if(rng.chance(((count<a4/2)+1)*0x1e)&&(h49||!isVisible4631c0(fb24[i]->pos575920()))||qb_cefb0a)
						{
							for(int j=defs.size()-1;j>=0;j--)
							{
								if(fb24[i]->f457900()>=defs[j]->f68)
								{
									QbHE e=placeEntity6c58c0(defs[j],fb24[i]->pos575920(),5,0,0x22,0xe,0);
									if(e.valid())
									{
										fb24[i]->f57a190(e,fb24[i]->f4578a0(),0,0);
										QB_MSG((0x2e4,&fb24[i]->getName571db0(0,0),0,0,e,QbHE(),0,false));
										qb_eraseAt9da940(fb24,i);
										count++;
										break;
									}
								}
							}
						}
						if(count>=a4)break;
					}
				}
			}
			fb38=0;
			fb34=0;
			QbHEs*members=f4c[5]->members416f40();
			for(unsigned i=0;i<members->size();i++)
			{
				if((*members)[i]->getFaction45a2c0()==0x47)fb34++;
				else if((*members)[i]->getFaction45a2c0()==0x48)fb38++;
			}
		}
		break;
	case 5:
		if(f320==2&&qb_d1e88c.size()>2&&!qb_d1e88c.back9b6540()->isAt46ecd0(qb_d1e88c[qb_d1e88c.size()-3]))qb_xp_cf45d8.gain77e900(qb_tbl_b90fd0[qb_loc_d1e888->kind],0);
		break;
	case 7:
		if(f320%100==0)
		{
			for(unsigned i=0;i<qb_cf46d4.size();i++)
				if(qb_cf46d4[i].get9b6570()==0)qb_eraseStep9d6440(qb_cf46d4,i);
		}
		break;
	case 10:
		if(fba4!=0&&getTurn464270()==fba4)
		{
			int zone=0;
			QbPoint pFrom;
			QbPoint to;
			if(!qb_overmind_cf6428.findDispatchExit(&pFrom,0,0,0,&QbPoint(-1),&zone,0,0)||!qb_overmind_cf6428.f68a8b0(&pFrom,&to))
				qb_logWarning404e50("BS::turnUpdate()","No valid route for spawning Sauler");
			else
			{
				fba8=qb_map_cefc4c->f6c5dc0("Sauler",pFrom,3,0,0x14,0xe,0);
				if(fba8.valid())
				{
					int n=qb_gd_d1e860.getDepthIndex()+1;
					QbPoint range(n,n+2);
					if(range.y>9)range.f40bf50(9-range.y);
					qb_overmind_cf6428.f6901e0(fba8,1,qb_d30358.random40c130(),qb_d1de90.random40c130(),range,1,0x2a);
					QB_ALERT_S(&string("ALERT: Ho ho beep!"),0x13c);
				}
			}
		}
		break;
	case 11:
		for(unsigned i=0;i<fbc4.size();i++)
		{
			if(f320>=fbc4[i])
			{
				qb_removeVectorElement9de6f0(fbb4,i);
				qb_eraseAt9ce6d0(fbc4,i);
			}
		}
		break;
	}
	qb_map_cefc4c->f726320();
	qb_stats_d2c658.add4729d0(0x3ee,1,qb_e_b95af7,-1);
	if(getTurn464270()%5==0)
	{
		int allies=0;
		int h59=0;
		int v;
		for(int s=1;s<=2;s++)
		{
			QbHEs*members=f4c[s]->members416f40();
			for(unsigned i=0;i<members->size();i++)
			{
				if(!(*members)[i]->isPlayer5c7600())
				{
					allies++;
					v=(*members)[i]->f5cccc0();
					qb_stats_d2c658.add4729d0(0x380,v,qb_e_b95afe,-1);
					h59+=v;
				}
			}
		}
		qb_stats_d2c658.add4729d0(0x37e,allies,qb_e_b95aff,-1);
		if((*qb_stats_d2c658.vals)[0x37e]>=5)qb_player_cf45d8.f77fbc0(0x7a);
		if((*qb_stats_d2c658.vals)[0x37e]>=0x14)qb_player_cf45d8.f77fbc0(0xc7);
		qb_stats_d2c658.add4729d0(0x37f,h59,qb_e_b95b09,-1);
	}
	if(qb_player_cf45d8.isSlotEmpty46de40(0x20)&&squad463890(0)->members416f40()->size()>=7)
	{
		int n=0;
		QbHEs*members=squad463890(0)->members416f40();
		for(unsigned i=1;i<members->size();i++)
			if((*members)[i]->getFaction45a2c0()==0xa)n++;
		if(n>=6)qb_player_cf45d8.f77fbc0(0x20);
	}
	if(qb_cf4b60>0&&getTurn464270()>qb_cf4b6c+0x14)
	{
		if(qb_cf4b60>=7)do qb_logPhrase5141b0(0xc,&qb_intToString4051f0(qb_cf4b60),&qb_intToString4051f0(qb_cf4b64),0,QbHE(),0);while(false);
		qb_cf4b60=0;
		qb_cf4b64=0;
	}
	if(qb_cf4b70>0&&getTurn464270()>qb_cf4b84+0x1e)
	{
		if(qb_cf4b70>=3)
		{
			string list;
			for(unsigned i=0;i<qb_cf4b74.size();i++)
			{
				if(qb_cf4b74[i]!=0)
				{
					list+=qb_intToString4051f0(qb_cf4b74[i]);
					list+=qb_d21a78[i];
				}
			}
			do qb_logPhrase5141b0(0xd,&qb_intToString4051f0(qb_cf4b70),&list,0,QbHE(),0);while(false);
			if(qb_cf4ac8!=0&&qb_cf4ac8->h4.p()!=0&&qb_cf4ac8->h4->owner457b50()==f66c&&qb_cf4ac8->h4->getType44aec0()==3&&qb_player_cf45d8.hasCompanion780790())qb_cf4ac8->f30->spawn7aa280(0x2f,0,qb_e_b95b0a);
		}
		qb_cf4b70=0;
		qb_cf4b74.assign9b1950(4,0);
	}
	if(qb_cf4b88>0&&getTurn464270()>qb_cf4b8c+0x1e)
	{
		if(qb_cf4b88>=3)
		{
			do qb_logPhrase5141b0(0xe,&qb_intToString4051f0(qb_cf4b88),0,0,QbHE(),0);while(false);
			if(qb_cf4ac8!=0&&qb_cf4ac8->h4.p()!=0&&qb_cf4ac8->h4->owner457b50()==f66c&&qb_cf4ac8->h4->getType44aec0()==3&&qb_player_cf45d8.hasCompanion780790())qb_cf4ac8->f30->spawn7aa280(0x30,0,qb_e_b95b0b);
		}
		if(qb_cf4b88>=10)qb_player_cf45d8.f77fbc0(0xcb);
		qb_cf4b88=0;
	}
	if(qb_cf4b90>0&&getTurn464270()>qb_cf4b94+0x19)
	{
		if(qb_cf4b90>=3)
		{
			do qb_logPhrase5141b0(0xf,&qb_intToString4051f0(qb_cf4b90),0,0,QbHE(),0);while(false);
			if(qb_cf4ac8!=0&&qb_cf4ac8->h4.p()!=0&&qb_cf4ac8->h4->owner457b50()==f66c&&qb_cf4ac8->h4->getType44aec0()==3&&qb_player_cf45d8.hasCompanion780790())qb_cf4ac8->f30->spawn7aa280(0x31,0,qb_e_b95b15);
		}
		qb_cf4b90=0;
	}
	if(qb_cf4ba4==0&&f66c->f45a880()<0x32)
	{
		do qb_logPhrase5141b0(0x29,&qb_intToString4051f0(0x32),0,0,QbHE(),0);while(false);
		qb_cf4ba4=getTurn464270();
	}
	if(qb_cf4ba8==0&&f66c->f45a880()<0x14)
	{
		do qb_logPhrase5141b0(0x29,&qb_intToString4051f0(0x14),0,0,QbHE(),0);while(false);
		qb_cf4ba8=getTurn464270();
	}
	if(qb_cf4bac==0&&f66c->f5cab90()>=0xa)
	{
		do qb_logPhrase5141b0(0x2a,&qb_intToString4051f0(0xa),0,0,QbHE(),0);while(false);
		qb_cf4bac=getTurn464270();
	}
	if(qb_cf4bb0==0&&f66c->f5cab90()>=0x1e)
	{
		do qb_logPhrase5141b0(0x2a,&qb_intToString4051f0(0x1e),0,0,QbHE(),0);while(false);
		qb_cf4bb0=getTurn464270();
	}
	if(f320==2&&qb_d28dee&&!qb_d28d04&&qb_loc_d1e888->f8==1&&qb_d1e88c.size()>2&&qb_d1e88c[qb_d1e88c.size()-2]->f8>1)
	{
		QB_MSG((0x325,&string("Reminder: Score uploading is currently disabled in the options menu."),0,0,QbHE(),QbHE(),0,false));
		qb_sound4541b0(0x63,0,0);
	}
	if(qb_cefc58->f30&&!qb_cefc58->f3c)
	{
		qb_cefc58->f3d=true;
		if(!qb_cefc58->f5c.empty())
		{
			bool done;
			QbCmd*cmd;
			for(unsigned i=0;i<qb_cefc58->f5c.size();i++)
			{
				done=false;
				cmd=qb_cefc58->f5c[i];
				switch(cmd->f0)
				{
				case 1:
					qb_cefc70=true;
					qb_message49c610(0x320,QbHE(),cmd->fc,0);
					if(cmd->f8!=0)qb_playSound4ff050(qb_cfd2ec[cmd->f8],-1,0,0,0);
					qb_view_cec054->delay49adc0(1000);
					qb_cefc70=false;
					done=true;
					break;
				case 2:
					if(!cmd->f28.empty())
					{
						QbHEs found;
						QbIntList dists;
						QbRect r7;
						qb_grid_cfd44c.getRect9b4430(f66c->pos45a4a0(),0xf,r7);
						for(int x=r7.x;x<=r7.x2;x++)
						{
							for(int y=r7.y;y<=r7.y2;y++)
							{
								if((*qb_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->name416f40()==cmd->f28&&(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->getTarget45a760()==0)
								{
									int d=qb_distanceCeil40a3f0(f66c->pos45a4a0(),(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->pos45a4a0());
									if(found.empty()||d>=dists.back9b6540())
									{
										found.push_back((*qb_grid_cfd44c.at(x,y))->getEntity45d250());
										dists.push_back(d);
									}
									else
									{
										for(unsigned k=0;k<dists.size();k++)
										{
											if(d<dists[k])
											{
												qb_insert9d8fc0(found,k,(*qb_grid_cfd44c.at(x,y))->getEntity45d250());
												qb_insertAt9dbdc0(dists,k,d);
												break;
											}
										}
									}
								}
							}
						}
						if(found.empty())goto L2done;
						for(unsigned k=0;k<found.size();k++)
						{
							if(f4631f0(found[k]))
							{
								qb_d388f4=found[k];
								break;
							}
						}
						if(qb_d388f4.isNull()&&cmd->f8!=0)goto L2done;
					}
					QB_MSG((0x322,&cmd->fc,0,0,QbHE(),QbHE(),0,false));
					qb_view_cec054->delay49adc0(1000);
					qb_d388f4.reset9b7270();
L2done:
					done=true;
					break;
				case 3:
					do{qb_flags_cf1080.set451400(cmd->f28=="1"?3:1);if(cmd->f8>=0&&!(qb_d28fb0&&cmd->f8>=0x127&&cmd->f8<=0x12a))qb_sound4541b0(cmd->f8,0,0);QB_MSG((0x324,&cmd->fc,0,0,QbHE(),QbHE(),0,false));qb_log_cec0b4->scrollToEnd7b4f10();}while(false);
					done=true;
					break;
				case 4:
					qb_playSound4ff050(qb_cfd2ec[cmd->f8],-1,0,0,0);
					done=true;
					break;
				case 5:
				{
					QbItems items;
					f66c->f5cb830(items);
					for(unsigned k=0;k<items.size();k++)
					{
						if(items[k]->getName571db0(0,0)==cmd->fc&&(!cmd->f28.empty()||items[k]->f4579f0().size()!=0))
						{
							items[k]->f458700(cmd->f28);
							qb_inv_cec08c->f8a54c0(items[k],1);
							break;
						}
					}
					done=true;
					break;
				}
				case 6:
				{
					QbItems found;
					QbIntList dists4;
					QbRect r;
					qb_grid_cfd44c.getRect9b4430(f66c->pos45a4a0(),0xf,r);
					for(int x=r.x;x<=r.x2;x++)
					{
						for(int y=r.y;y<=r.y2;y++)
						{
							if((*qb_grid_cfd44c.at(x,y))->getItem45d8f0().valid()&&(*qb_grid_cfd44c.at(x,y))->getItem45d8f0()->getName571db0(0,0)==cmd->fc&&(!cmd->f28.empty()||(*qb_grid_cfd44c.at(x,y))->getItem45d8f0()->f4579f0().size()!=0))
							{
								int d=qb_distanceCeil40a3f0(f66c->pos45a4a0(),(*qb_grid_cfd44c.at(x,y))->getItem45d8f0()->pos575920());
								if(found.empty()||d>=dists4.back9b6540())
								{
									found.push_back((*qb_grid_cfd44c.at(x,y))->getItem45d8f0());
									dists4.push_back(d);
								}
								else
								{
									for(unsigned k=0;k<dists4.size();k++)
									{
										if(d<dists4[k])
										{
											qb_insert9d8fc0(found,k,(*qb_grid_cfd44c.at(x,y))->getItem45d8f0());
											qb_insertAt9dbdc0(dists4,k,d);
											break;
										}
									}
								}
							}
						}
					}
					if(!found.empty())
					{
						for(unsigned k=0;k<found.size();k++)
						{
							if(isVisible4631c0(found[k]->pos575920()))
							{
								found[k]->f458700(cmd->f28);
								goto L6done;
							}
						}
						found.front9b7060()->f458700(cmd->f28);
					}
L6done:
					done=true;
					break;
				}
				case 7:
				{
					QbHEs*members=f4c[1]->members416f40();
					for(unsigned k=0;k<members->size();k++)
					{
						if((*members)[k]->f5c80a0()&&(*members)[k]->name416f40()==cmd->fc)
						{
							(*members)[k]->f45b070(cmd->f28);
							qb_allies_cec0c8->f7b8500((*members)[k]);
						}
					}
					done=true;
					break;
				}
				case 8:
				case 9:
				case 12:
					qb_cefc58->f7c.push_back(cmd);
					qb_eraseAt9ce6d0(qb_cefc58->f5c,i);
					break;
				case 10:
					for(int k=0;k<(int)qb_cefc58->f7c.size();k++)
						if(cmd->f8==-1||cmd->f8==qb_cefc58->f7c[k]->f0)qb_deleteObjectAndStep9de730(qb_cefc58->f7c,k);
					done=true;
					break;
				case 11:
				{
					QbEntDef*def;
					if(qb_findByName9d7530(qb_entDefs_d25de0,"01-MTF",def))
					{
						QbPoint at(f66c->pos45a4a0());
						if(qb_map_cefc4c->findPlaceableNear71c150(at,at,def->f9c))
						{
							QbHE e=qb_map_cefc4c->placeEntity6c58c0(def,at,2,0,0x22,0xe,0);
							if(e.valid())
							{
								e->ai45b590()->setFollowEntity5b2f80(qb_map_cefc4c->f66c,2);
								e->f45b270(e->f5ca400());
								QbHI wheel=giveItem6c52b0("Chronowheel",e,0,0);
								if(wheel.valid())qb_player_cf45d8.f77ffb0(wheel->f457820(),0);
								QbRecord*tele;
								if(qb_lookup9d7980("Technomage_Tele",&tele))qb_owner_cefc50->new508610()->init503b20(qb_owner_cefc50,tele,at,qb_d2e20c,0,0,0,9,0);
							}
						}
					}
					done=true;
					break;
				}
				case 13:
				{
					int idx=qb_findStringIndex9cda80(qb_cf1970,5,cmd->fc);
					qb_view_cec054->f819d50(idx,cmd->f8!=0);
					done=true;
					break;
				}
				case 14:
					if(qb_f9daf80(0,cmd->f8,0xe))
					{
						QbHE e=f6c5dc0(cmd->fc,f66c->pos45a4a0(),cmd->f8,0,0x22,0xe,0);
						if(e.valid())
						{
							if(e->f45aaa0(f66c))e->ai45b590()->setFollowEntity5b2f80(f66c,0);
							if(!cmd->f28.empty()&&isVisible4631c0(e->pos45a4a0()))
							{
								QbRecord*rec;
								if(qb_lookup9d7980(cmd->f28,&rec))qb_owner_cefc50->new508610()->init503b20(qb_owner_cefc50,rec,e->pos45a4a0(),qb_d2e20c,0,0,0,9,0);
							}
						}
					}
					done=true;
					break;
				case 15:
					if(qb_f9daf80(0,cmd->f8,0xe))
					{
						QbStrList parts;
						qb_split408700(cmd->f28,'|',parts);
						if(parts.size()==5)
						{
							string oldVal;
							int aCount=-1;
							int bX=-1;
							int group=-1;
							int hostile=-1;
							string aS("-1");
							if(qb_splitAfterChar4090e0(parts[0],'=',oldVal))aCount=qb_stringToInt405610(oldVal);
							if(qb_splitAfterChar4090e0(parts[1],'=',oldVal))bX=qb_stringToInt405610(oldVal);
							if(qb_splitAfterChar4090e0(parts[2],'=',oldVal))group=qb_stringToInt405610(oldVal);
							if(qb_splitAfterChar4090e0(parts[3],'=',oldVal))hostile=qb_stringToInt405610(oldVal);
							if(qb_splitAfterChar4090e0(parts[4],'=',oldVal))aS=oldVal;
							if(aCount!=-1&&bX!=-1&&group!=-1&&hostile!=-1&&aS!="-1")
							{
								QbPoint at=f71d000(2);
								if(at.x!=-1)
								{
									QbHE leader;
									for(int k=0;k<aCount;k++)
									{
										QbHE e=f6c5dc0(cmd->fc,at,cmd->f8,0,0x22,0xe,0);
										if(e.valid())
										{
											if(bX!=0)e->ai45b590()->setFollowEntity5b2f80(f66c,0);
											else if(group!=0)
											{
												if(leader.isNull())leader=e;
												else e->ai45b590()->setFollowEntity5b2f80(leader,0);
											}
											if(hostile!=0&&e->isHostileTo45aa70(f66c))e->ai45b590()->chase5b4710(f66c,1,0,1,0);
											if(aS!="NA"&&k==0)e->f45b070(aS);
										}
									}
								}
							}
						}
					}
					done=true;
					break;
				case 16:
				case 17:
				case 18:
				case 19:
				case 20:
				{
					const string&name=cmd->f0==0x14?cmd->f28:cmd->fc;
					const int a3=0x14;
					QbHE target;
					QbRect r;
					qb_grid_cfd44c.getRect9b4430(f66c->pos45a4a0(),a3,r);
					for(int x=r.x;x<=r.x2;x++)
					{
						for(int y=r.y;y<=r.y2;y++)
						{
							if((*qb_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&(*qb_grid_cfd44c.at(x,y))->getEntity45d250()->name416f40()==name&&(target.isNull()||qb_distanceCeil40a3f0(f66c->pos45a4a0(),QbPoint(x,y))<qb_distanceCeil40a3f0(f66c->pos45a4a0(),target->pos45a4a0())))
								target=(*qb_grid_cfd44c.at(x,y))->getEntity45d250();
						}
					}
					if(target.valid())
					{
						switch(cmd->f0)
						{
						case 16:
						{
							QbStrList parts;
							qb_split408700(cmd->f28,'|',parts);
							if(parts.size()==3)
							{
								string hiD;
								QbFRange2 amount;
								int stat;
								if(qb_splitAfterChar4090e0(parts[0],'=',hiD))
								{
									stat=qb_findStringIndex9cda80(qb_d2e6c8,9,hiD);
									if(stat!=-1&&qb_splitAfterChar4090e0(parts[1],'=',hiD))
									{
										int op=qb_findStringIndex9cda80(qb_cfd200,7,hiD);
										if(op!=-1&&qb_splitAfterChar4090e0(parts[2],'=',hiD)&&amount.parse40c500(hiD))
										{
											switch(stat)
											{
											case 1:
												target->f45b240(qb_applyOperation456a50(target->f45a920(),op,amount.random40c700(),0,-1));
												break;
											case 2:
												target->f45b270(qb_applyOperation456a50(target->f45a8d0(),op,amount.random40c700(),0,-1));
												break;
											case 3:
											{
												int op2=op;
												float amt=amount.random40c700();
												if(op2==3)
												{
													op2=1;
													amt=target->f490840()-target->f490840()/amt;
												}
												else if(op2==2)
												{
													op2=0;
													amt=target->f490840()*amt-target->f490840();
												}
												if(op2==1)target->takeDamage5e5520(1,0,0,(int)amt,7,0,0,!qb_map_cefc4c->f4631f0(target),QbHE(),1,8,0,0,1);
												else target->f5dea60(qb_applyOperation456a50(target->f490840(),op2,amt,0,-1),0);
												break;
											}
											case 4:
												target->setField4514c0(qb_applyOperation456a50(target->f45a990(),op,amount.random40c700(),target->f5cab30(),-1));
												break;
											case 5:
												target->f44e2c0(qb_applyOperation456a50(target->f45a9d0(),op,amount.random40c700(),0,-1));
												break;
											}
											if(cmd->f8!=0&&isVisible4631c0(target->pos45a4a0()))qb_owner_cefc50->new508610()->init503b20(qb_owner_cefc50,qb_cf67c0[cmd->f8],target->pos45a4a0(),qb_d2e20c,0,0,0,9,0);
										}
									}
								}
							}
							break;
						}
						case 17:
						{
							QbItems parts;
							if(target->f5cb8b0(parts))
							{
								for(unsigned k=0;k<parts.size();k++)
								{
									if(parts[k]->f457d10())
									{
										parts[k]->f5797c0();
										if(target->isPlayer5c7600())
										{
											QbPart*ui=qb_parts_cec088->f894e70(parts[k]);
											if(ui!=0)
											{
												qb_parts_cec088->toggle8993e0(ui,0);
												ui->f4a9120();
												if(parts[k]->f4578c0()>1)qb_parts_cec088->f896820(parts[k]);
											}
										}
									}
									if(parts[k]->f9b6bf0()<parts[k]->f457c80())
									{
										parts[k]->f450460(parts[k]->f457c80());
										if(target->isPlayer5c7600())
										{
											QbPart*ui=qb_parts_cec088->f894e70(parts[k]);
											if(ui!=0)ui->drawStatus4a8e70(0);
										}
									}
									if(parts[k]->f415ee0())
									{
										parts[k]->f458390(0);
										if(target->isPlayer5c7600())
										{
											QbPart*ui=qb_parts_cec088->f894e70(parts[k]);
											if(ui!=0)
											{
												qb_parts_cec088->toggle8993e0(ui,0);
												ui->f4a9120();
												if(parts[k]->f4578c0()>1)qb_parts_cec088->f896820(parts[k]);
											}
										}
									}
									if(parts[k]->f4578a0()==3)parts[k]->f44fc60(0);
								}
							}
							if(cmd->f8!=0&&isVisible4631c0(target->pos45a4a0()))qb_owner_cefc50->new508610()->init503b20(qb_owner_cefc50,qb_cf67c0[cmd->f8],target->pos45a4a0(),qb_d2e20c,0,0,0,9,0);
							break;
						}
						case 18:
							if(cmd->f28.empty())target->die633790(false,0xa,QbHE(),1,0,0,0,0);
							else
							{
								QbRecord*rec;
								if(qb_lookup9d7980(cmd->f28,&rec))qb_owner_cefc50->new508610()->init503b20(qb_owner_cefc50,rec,target->pos45a4a0(),qb_d2e20c,0,0,0,9,0);
								target->f637bb0();
							}
							break;
						case 19:
							if(qb_f9daf80(0,cmd->f8,0xe)&&target->getGroup45a3f0()->kind9b4350()!=cmd->f8)
							{
								target->changeFaction5dc780(qb_map_cefc4c->squad463890(cmd->f8),1);
								if(target->f45aaa0(f66c))target->ai45b590()->setFollowEntity5b2f80(f66c,0);
							}
							break;
						case 20:
						{
							QbIRec*def;
							if(qb_findByName9d7a40(qb_d2d1c4,cmd->fc,def))
							{
								if(cmd->f8!=0)f6c51d0(def,target,0,0);
								else f6c5400((QbItemInfo*)def,target->pos45a4a0());
							}
							break;
						}
						}
					}
					done=true;
					break;
				}
				case 21:
				{
					QbIRec*def;
					if(qb_findByName9d7a40(qb_d2d1c4,cmd->fc,def)&&qb_player_cf45d8.f780380(def->f0,0))qb_inv_cec08c->reopen8a2ce0(4,QbHE());
					done=true;
					break;
				}
				case 22:
				{
					QbEntDef*def;
					if(qb_findByName9d7530(qb_entDefs_d25de0,cmd->fc,def))qb_player_cf45d8.f780480(def->f0,0);
					done=true;
					break;
				}
				case 23:
				{
					const int range=0x14;
					QbHP best;
					int vBestDist;
					QbRect rA;
					qb_grid_cfd44c.getRect9b4430(f66c->pos45a4a0(),range,rA);
					for(int x=rA.x;x<=rA.x2;x++)
					{
						for(int y=rA.y;y<=rA.y2;y++)
						{
							if((*qb_grid_cfd44c.at(x,y))->getProp45d550().valid()&&(*qb_grid_cfd44c.at(x,y))->getProp45d550()->f44ab40()!=-1&&(*qb_grid_cfd44c.at(x,y))->getProp45d550()->f9b8f00()->f8c!=0)
							{
								int d=qb_distanceCeil40a3f0(f66c->pos45a4a0(),QbPoint(x,y));
								if(best.isNull()||d<vBestDist)
								{
									best=(*qb_grid_cfd44c.at(x,y))->getProp45d550();
									vBestDist=d;
								}
							}
						}
					}
					if(best.valid())best->f45ce10(0,1,0,QbHE());
					done=true;
					break;
				}
				case 24:
					if(qb_cf68b4==0)
					{
						qb_tally_cf6888.f6998a0(0xb,1,0);
						if(qb_f9d4c40(-1,cmd->f8,0xa))qb_caf2a8=cmd->f8;
						else qb_caf2a8=0xa;
					}
					done=true;
					break;
				case 25:
					if(qb_xom_d25450.active)qb_xom_d25450.f69e700(0,3,(float)cmd->f8);
					done=true;
					break;
				case 26:
					if(qb_xom_d25450.active&&qb_f9daf80(0,cmd->f8,0x6d))qb_d2561c=cmd->f8;
					done=true;
					break;
				case 27:
					if(qb_xom_d25450.active)qb_d25620=(bool)cmd->f8;
					done=true;
					break;
				}
				if(done)qb_deleteObjectAndStep9de730(qb_cefc58->f5c,i);
			}
		}
		qb_cefc58->f3d=false;
	}
	//CHUNK
}
