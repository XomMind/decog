// X0-1V1 (Xom) GxXom::update6a0150 (0x6a0150): timed effect expiry and the Xom act dispatcher (110 acts).
// src/util/loop_bravo_17_xom.cpp calls the same function under its own placeholder name LB17Xom::update6a0150.
// Private partial ABI views (Gx*/gx_* names are file-private placeholders; callees stay stubs paired by address).
// NOTE: placeholder names / placeholder layouts throughout. Many locals carry odd names (i8, aD, a_, pad4...):
// VS2010 /Od orders a scope's locals by a hash of the name, so names were chosen to reproduce the exe frame;
// `int padN[1]` are unreferenced slots the exe frame has.
#include <string>
#include <stdlib.h>
#include "util/rng.h"
using std::string;
extern RNG rng;

struct GxPoint{int x,y;GxPoint();GxPoint(int);void f40bf50(int);GxPoint(int,int);GxPoint(const GxPoint&);GxPoint&operator=(const GxPoint&);int random40c130();bool f409bd0(const GxPoint&);bool contains40c190(int);};
struct GxEntity;struct GxItem;struct GxHG;struct GxAI;struct GxArea;
struct GxHE{int id;GxHE();bool operator==(GxHE)const;bool operator!=(GxHE)const;void reset9b7270();GxEntity*operator->()const;bool isNull()const;bool valid()const;};
struct GxHI{int id;GxHI();bool isNull()const;GxItem*operator->()const;bool valid()const;};
struct GxDef{int id;char p4[0x3c];int f40;int f44;int f48;int f4c;int f50;int f54;char p58[0x18];int f70;char p74[0x20];int f94;char p98[0x58];int f0f0;char pf4[0xc];int f100;char p104[0xc];int f110;char p114[0x14];int f128;char p12c[0x64];struct GxRecord*f190;char p194[0x14];struct GxExplDef*f1a8;bool f1ac;char p1ad[0x73];int f220;int f224;int f228;bool f22c;char p22d[3];int f230;char p234[0x18];bool f24c;int f457130();};typedef GxDef GxItemInfo;
struct GxItem{const GxPoint&f575920();void f57bff0(int,int);bool f577990();void f5798b0(int);int f577fb0();bool hasName4579d0();bool f457cf0();int f457f90();int f457af0();bool f457d70();int f45cb30();void f44fc60(int);int f4578a0();void f450460(int);void f458700(const string&);int f457dd0();void f458460();int f457880();int f457920();int f9fcd80();int f457820();void addEffect4585a0(GxPoint*);int f457cd0();int f457ca0();int f457c80();int f9b6bf0();void f458360(int);int getType44aec0();int nested4578c0();bool f457e90();GxItemInfo*info9b4350();int getEffect457b70(int);string getName571db0(int,int);void remove57dbe0(int,int,int,int);};
struct GxItems{char d[0x10];GxItems();GxItems(const GxItems&);~GxItems();unsigned size()const;GxHI&operator[](unsigned);void push_back(const GxHI&);bool empty()const;GxHI&front();GxHI&back();};
void gx_insert9d8fc0(GxItems&,int,GxHI);void gx_moveElement9da1f0(GxItems&,int,int);
struct GxEntity{void changeFaction5dc780(GxHG,int);int f5cccc0();void setAI64ecf0(struct GxAIObj*);void f6396a0(const string&,int);GxHI f5d2380(int);void f6399e0(int,int);bool fire63a3e0(int,GxHE);void changePos5dccb0(const GxPoint&,int);bool isPlayer5c7600();GxHI f5d5d40();void f5c8b10(struct GxPath&,GxHE);GxHE f45af90();int f5cb8b0(GxItems&);void f5c8880(struct GxHEs&);void f45b1b0(int);void f45b210(int);bool isXomCandidate5d51a0();bool f5d2a00(int);bool f5d26e0(int);void f5c93d0(struct GxIntVec2&);bool f5dc680(GxHI);bool f5cd220(GxHI);int f5ca210();int f5cb830(GxItems&);int f45a810();void f5dea60(int,int);bool f5c98c0(int,int,int);void f5ddac0(const GxPoint&,int);int f45a9d0();void f5dcc70(int,int);void f6335e0();void die633790(int,int,GxHE,int,int,int,int,int);int getSize45a360();void f5c89d0(struct GxPath&);void f5fd900(int,int);void removeEffectsA639730(int);GxPoint f45a4c0();GxPoint f5c80f0(const GxPoint&);bool f45aaa0(GxHE);bool isHostileTo45aa70(GxHE);int f5cc190(int);int f5cab90();void f44e2c0(int);int f457820();bool f45aa10();int f45ac40(int);int getInventory45ad90();struct GxEntInfo*info9b4350();void f45b070(const string&);void f45b2a0();int f9fcd80();const string&name416f40();struct GxPoints*points45d1a0();bool f5d6480(GxHE);int getSlotTotal45a860();void f5c94e0(int,GxHE);int f448fe0(int);int f45a880();int f5ca260();int f490840();void f5de870(int,int);GxHI f5d5b20();GxHI f5d5c30();int f5c7d30();int f45a990();void f4514c0(int);int f45a940();void f5deb40(int);int f5ca670();int f45a920();int f45a8f0();void f5ded70(int);int f5ca400();int f45a8d0();GxHG getGroup45a3f0();int getTarget45a760();void f5fdab0();void f637bb0();void f639530(int,int);GxAI*ai45b590();int getAiType45a2a0();int getFaction45a2c0();const GxPoint&getPosition45a4a0();int f45a6e0();GxItems&getInventoryList45ab00();int f5c92e0(int);void f5c9660(int);void f5e2b50();void f642940(GxHI,int,int,int,int);};
struct GxGroup;struct GxHG{int id;GxHG();GxGroup*operator->()const;};
struct GxHEcIt{void*p;GxHEcIt();};struct GxHEIt:GxHEcIt{GxHEIt();GxHEIt operator+(int)const;};
struct GxHEs{char d[0x10];GxHE&at9b9230(unsigned);GxHEIt begin();GxHEIt end();GxHEIt erase(GxHEcIt,GxHEcIt);GxHEs();~GxHEs();void push_back(const GxHE&);void push_back(GxHE&&);bool empty()const;GxHE&front();unsigned size()const;GxHE&operator[](unsigned);};
struct GxHGs{char d[0x10];unsigned size()const;GxHG&operator[](unsigned);};
struct GxGroup{bool f45e3e0(int);int f9b4350();GxHEs*members416f40();};
struct GxArea{int a,b,c,d;GxArea();GxPoint center40b620();GxPoint randomPoint40be90();bool contains40b750(const GxPoint&);};
struct GxGoals;struct GxAI{void f5b57a0(GxHI,int);bool getFollowers580a90(struct GxHEs&,int);void f4582d0(int);void setOperatorTerminal5b3760(const GxPoint&);bool f458fb0(GxHE);void f5b5220();GxGoals*f4590f0();void setFollow5b2f80(GxHE,int);void f459470(const GxArea&);void f459410(const GxArea&);void f451930(int);GxArea*f4b5730();void chase5b4710(GxHE,int,int,int,int);};
struct GxPropDef{char p0[0x8c];int f8c;char p90[0x68];int f0f8;};struct GxLock{char p0[8];bool f8;};struct GxPropInfo{char p0[0xc];int fc;char p10[0x60];GxHE h70;GxLock*f45c1c0(int);bool f45c160(int,int);};struct GxProp{void f45cc50(const GxPoint&);void f452270(int);int f45c9b0();const string&f45c590();GxPropInfo*f45cb30();int f457b10();int f44ab40();const string&getName45c5b0();const GxPoint&f4184d0();GxPropDef*getDef9b8f00();void f45ce10(int,int,int,GxHE);};
struct GxHP{int id;GxHP();GxProp*operator->()const;bool valid()const;bool isNull()const;};
struct GxCell{void f66a050(int,int,int);bool f45df50(struct GxHP);bool f66b1c0(int,int);bool f45dcf0();bool f45d6a0();void f66ce10(int,int,int,int);bool isEdge45dc30();bool isShortcut45dc50();bool canPlace66ad20(int);bool isPassableFor66ab30(GxHE);GxHE getEntity45d250();GxHI getItem45d8f0();bool f45d7b0();GxHP getProp45d550();};
struct GxGrid{bool contains9b43b0(const GxPoint&);GxCell**atPoint(const GxPoint&);GxCell**at(int,int);int width9fcd80();int height9b8f00();void getRect9b4430(const GxPoint&,int,GxArea&);};extern GxGrid gx_grid_cfd44c;
struct GxEntityDef{char p0[0x24];int f24;int f28;char p2c[0x1c];int f48;char p4c[0x1c];int f68;char p6c[0x30];int f9c;char pa0[0x84];int f124;int f128;int f12c;int f130;int f134;char p138[0x74];string f1ac;};
struct GxEntityDefs{char d[0x10];unsigned size()const;GxEntityDef*&operator[](unsigned);};extern GxEntityDefs gx_ents_d25de0;
struct GxLoc{int f0;int depth;int f8;bool inRange46ecb0();string getText46ed40();};struct GxLocH{int id;GxLoc*operator->()const;bool operator==(GxLocH)const;};extern GxLocH gx_loc_d1e888,gx_d1ebd8,gx_d1ebe0;
struct GxOvermind{int f684250(const GxPoint&,int);int f685a10(GxHE,int);int f687520(GxHE,int,int);void f682420(int,int);void f68cd80(struct GxOwnerRec*);bool f683500(GxPoint*,int,int,int,const GxPoint*,int*,int,int);int f6892c0(int,int,int);GxHE f683b60(int,int,int);};extern GxOvermind gx_overmind_cf6428;
struct GxOwnerRec{int f0;GxHE e;int f8;bool fc;bool f45e820();};struct GxOwnerList{char d[0x10];GxOwnerList();~GxOwnerList();void push_back(GxOwnerRec*const&);bool empty()const;unsigned size()const;GxOwnerRec*&operator[](unsigned);};struct GxOwners{char d[0x10];GxOwnerRec*&back();unsigned size()const;GxOwnerRec*&operator[](unsigned);};extern string gx_squadNames_d2f350[];extern GxOwners gx_cf6478;
void gx_deleteBack9dae60(GxOwners&);
void gx_eraseAt9da940(GxHEs&,int);void gx_eraseAt9da940(GxItems&,int);unsigned gx_clamp9cdc80(unsigned,unsigned,unsigned);void gx_getAdjacentCells4fab80(const GxPoint&,struct GxPath&);void gx_removeEntity9d2f00(GxHEs&,GxHE);void gx_addUnique9d30e0(GxHEs&,GxHE);void gx_eraseStep9d6440(GxHEs&,unsigned&);void gx_shuffle9d9fc0(GxHEs&);void gx_moveElement9da1f0(GxHEs&,int,int);extern int gx_tbl_bba058[];extern string gx_kindNames_d2f798[];
struct GxFlags{void set451400(int);};extern GxFlags gx_flags_cf1080;
void gx_sound4541b0(int,int,int);
string gx_intToStringSigned405560(int);
bool gx_findPropDef9d7710(void*,const string&,GxPropDef**);extern char gx_propDefs_cf35b0[];
// The array of weighted lists in case 34 is built by `eh vector constructor iterator`, which pushes the ctor/dtor
// addresses as immediates; they only pair under the exe's own names (src/op/op_r5h_wl.cpp), so that one local uses them.
template<class T>class OpR5h_WL{public:char d[0x24];OpR5h_WL()throw();~OpR5h_WL();void add(T value,int weight);T&pick();bool empty9b81b0();};
template<class T>struct GxWL{char d[0x24];GxWL();~GxWL();void add(T,int);GxWL(const GxWL&);T&pick();unsigned size();T&operator[](unsigned);bool empty9b81b0();void remove9bab80(T);void addOrAdjust9ba350(T,int);};
struct GxStats{int f472c90(int);void add4729d0(int,int,string,int);void add472b90(int,int);};extern GxStats gx_stats_d2c658;
struct GxSay{void say49e250(int,int,string);};extern GxSay*gx_say_cefb48;
struct GxEntInfo{char p0[0x28];int f28;string name;int f48;char p4c[0x190];int f1dc;};
struct GxPoints{char d[0x10];unsigned size()const;GxPoint&operator[](unsigned);};
struct GxStrList{char d[0x10];GxStrList();~GxStrList();void push_back(const string&);bool empty()const;};
string gx_popRandomString9daeb0(GxStrList&);bool gx_containsString9d3fe0(GxStrList&,string);
void gx_clampMax9cf5a0(int*,int);int gx_distanceCeil40a3f0(const GxPoint&,const GxPoint&);
struct GxRecord{int id;};
float gx_distance40a450(const GxPoint&,const GxPoint&);
GxHI gx_popRandom9d8030(GxItems&);void gx_clearDijkstra4faf40();struct GxFov{void f40ca20(const GxPoint&,int,void*,int);};extern GxFov gx_fov_cfe568;extern char gx_d28c64[];GxPoint gx_randomPoint9d5350(struct GxPath&);extern struct GxPath gx_d15e58;bool gx_f5714a0(int);int gx_indexOfName9d74d0(struct GxDefs&,const string&);GxHE gx_randomRecord9dafb0(struct GxHEs&);GxHI gx_randomRecord9dafb0(GxItems&);
bool gx_inRange9d4c40(int,int,int);extern int gx_b960ec,gx_b960f0,gx_d1eae4;
struct GxHPs{char d[0x10];GxHPs();~GxHPs();unsigned size()const;bool empty()const;GxHP&operator[](unsigned);};struct GxHPLists{char d[0x10];unsigned size()const;GxHPs&operator[](unsigned);};extern GxHPLists gx_d31640;
GxHP gx_randomRecord9dafb0(GxHPs&);int gx_stringToInt405610(const string&);extern int gx_tbl_b903c0[];
bool gx_collectProps517ae0(int,struct GxPath&,int,int,int);void gx_sound454260(const GxPoint&,int);void gx_eraseAt9d5190(struct GxPath&,int);void gx_eraseAt9ce6d0(struct GxIntVec2&,unsigned&);
struct GxMarker{void f6c20b0(int,const GxPoint&,int);};struct GxMarkerH{int id;GxMarker*operator->()const;};
struct GxMarkers{char d[0x10];void push_back(GxMarkerH&&);GxMarkerH&back();};struct GxMarkerLists{char d[0x10];GxMarkers&operator[](unsigned);};
struct GxMission{void f987de0();};extern GxMission*gx_mission_cec034;
struct GxExit{GxPoint pos;GxLocH h8;char pc;bool fd;char pe[6];GxHP h14;GxHP h18;void setLabel6c16d0(string);};
struct GxExitList{char d[0x10];GxExitList();~GxExitList();unsigned size()const;GxExit*&operator[](unsigned);void push_back(GxExit*const&);bool empty()const;GxExit*&front();};
struct GxIntGrid{int*at(int,int);};struct GxCell34{char p0[0x10];int f10;char p14[0x10];int f24;};struct GxGrid34{GxCell34*at9d2c30(int,int);};
extern int gx_caf164,gx_caf15c;
struct GxIntVec2{char d[0x10];int&front();GxIntVec2();~GxIntVec2();void push_back(int&&);void push_back(const int&);int&operator[](unsigned);int&at9b9230(unsigned);bool empty()const;unsigned size()const;};int gx_minOf9d7290(GxIntVec2&);int gx_maxOf9d4340(GxIntVec2&);
extern int gx_tbl_ba3bf8[],gx_tbl_b98958[],gx_tbl_b98900[],gx_tbl_b988a8[];extern int gx_cf4a68;void gx_removeElement9de6f0(GxIntVec2&,int);extern GxIntVec2 gx_cf4a14,gx_cf4a04;
struct GxStrVec{char d[0x10];unsigned size()const;string&operator[](unsigned);};
struct GxStrVecs{char d[0x10];GxStrVec&operator[](unsigned);};extern GxStrVecs gx_d204ec;
struct GxIntVecs{char d[0x10];GxIntVec2&operator[](unsigned);};extern GxIntVecs gx_d25598,gx_cf4a58;
bool gx_containsRecord9db330(GxIntVec2&,int);bool gx_containsEntity9d31e0(GxItems&,GxHI);bool gx_findDef9d7a40(struct GxDefs&,const string&,GxDef**);int gx_randomRec9d5d00(GxIntVec2&);extern string gx_slotNames_d378d0[];
struct GxFPair{float x,y;GxFPair();};void gx_pointAlongLine4066e0(float,float,float,float,float,float*,float*);
struct GxObj138{void f9666d0();};extern GxObj138*gx_cec138;
struct GxInv{void f8a54c0(GxHI,int);void reopen8a2ce0(int,GxHE);void reopen8a2ce0(int,GxHI);};extern GxInv*gx_inv_cec08c;
struct GxQueue{void f6728c0(GxHE);void f672b80(GxHE,int);};extern GxQueue gx_queue_d225a0;
struct GxXGroup{char d[0x1c];GxXGroup(int);};
struct GxPointVec{char d[0x10];void push_back(const GxPoint&);};
struct GxGoal{int f0;int f4;GxPointVec v8;};
struct GxGoals{GxGoal*f57f140(GxXGroup*);};
struct GxExplDef{int id;char p4[0x38];int f3c;char p40[0x2c];int f6c;int f70;};
struct GxExplDefs{char d[0x10];unsigned size()const;GxExplDef*&operator[](unsigned);};extern GxExplDefs gx_expl_cfd2cc;
struct GxExplosion{char d[0x40];GxExplosion(GxHE,GxExplDef*,const GxPoint&,GxHE,const GxPoint&,const GxPoint&);};
struct GxRecHandle{int id;};struct GxFactory{struct GxHP createE793360(struct GxPropDef*);GxRecHandle createA7930e0(void*);struct GxMarkerH createC793190();};extern GxFactory*gx_factory_cefaa8;
struct GxPath{char d[0x10];GxPath();~GxPath();void clear9b3560();GxPoint&front();void push_back(const GxPoint&);void push_back(GxPoint&&);bool empty()const;unsigned size()const;GxPoint&operator[](unsigned);};
struct GxProj{char d[0x64];GxProj(struct GxDef*,GxHE,int,int,float,GxHE,GxHE,int,GxHE,int,int,int);};
void gx_f651590(struct GxDef*,const GxPoint&,const GxPoint&,GxPath&,GxPath&);bool gx_lookup9d7980(const string&,GxRecord**);
struct GxOwner;struct GxEffect{void init503b20(GxOwner*,GxRecord*,const GxPoint&,const GxPoint&,const GxPoint*,const GxPoint*,void*,int,GxEffect*);};
struct GxOwner{GxEffect*new508610();};extern GxOwner*gx_owner_cefc50;extern GxPoint gx_d2e20c;

struct GxDefList{char d[0x10];GxDefList();~GxDefList();void clear();void push_back(GxDef*const&);bool empty()const;unsigned size()const;};GxDef*gx_randomRec9d5d00(GxDefList&);

struct GxDefs{char d[0x10];unsigned size()const;GxDef*&operator[](unsigned);};extern GxDefs gx_defs_d2d1c4,gx_defs_d2ed7c,gx_defs_d316a0,gx_defs_d32990,gx_defs_d31510;
struct GxIntVec{char d[0x10];int&operator[](unsigned)throw();void push_back(const int&);};extern GxIntVec gx_d2f0f8,gx_cf47cc;
struct GxGM{void addItemAttachCount778560(int,int,int);};extern GxGM gx_gm_d25628;
struct GxGameData{const string&getEntryText46f6d0(const string&);bool f46f4b0(int);int f46f4e0();bool f46f550(int);};extern GxGameData gx_gd_d1e860;
void gx_clampMin9cf5c0(int*,int);extern int gx_tbl_ba3acc[];extern bool gx_b9651c[];
string gx_countString407a80(int,const string&);struct GxPlayer{int f46e150();void installRIF780f30(int);void f77fbc0(int);void f77ffb0(int,int);};extern GxPlayer gx_player_cf45d8;
bool gx_check69d230();void gx_addClamped9d06d0(int*,int,int);bool gx_inRange9daf80(int,int,int);int gx_minInt9cdb30(int,int);int gx_maxInt9cdb60(int,int);
extern string gx_str_d25ec4;extern int gx_d223ec;extern int gx_weights_bbb0f0[];extern int gx_tbl_bbb2a8[];
extern const char gx_e_b9588a[],gx_e_b9588b[],gx_e_b9588e[],gx_e_b9588f[],gx_e_b95892[],gx_e_b95893[],gx_e_b95899[],gx_e_b9589a[],gx_e_b9589b[],gx_e_b958a2[],gx_e_b958a3[];
extern bool gx_cf4a00;extern int gx_cf645c,gx_cf6474,gx_d1ec68;extern bool gx_cf6470,gx_cf6471,gx_cf6472;extern int gx_tbl_bba680[];
struct GxInts{char d[0x10];unsigned size()const;int&operator[](unsigned);};
struct GxPathLists{char d[0x10];struct GxPath&operator[](unsigned);};
struct GxMap{GxHI giveItem6c52b0(const string&,GxHE,int,int);bool isVisible463190(int,int);void f464a80(GxHP);struct GxPathLists*f459070();GxDef*selectRandomItemOfRating6c40e0(int,int,int,int,int,int,int);int f4642b0();int f7143e0(int*);int f4645d0();GxHE f7285b0();void f747060(const GxPoint&,int,struct GxRecord*);bool placeProp6c67b0(GxPropDef*,const GxPoint&,int,int,int);bool f464900();void f74bec0(const GxPoint&);struct GxPath*f463ad0();struct GxIntVec2*f463af0();GxHE f727ef0();bool f463e90(const GxPoint&);void f734d60(const GxPoint&);bool f463160(const GxPoint&);bool f463ee0(int,const GxPoint&);struct GxMarkerLists*f463ec0();struct GxExitList*exits462e10();void announceMachine71dd30(GxLocH);void f4647a0(const GxPoint&,int);struct GxIntGrid*f463830();struct GxGrid34*f463e70();void f720470(int);struct GxRecHandle addRecord777a20(struct GxRecHandle);bool f7170a0(GxHE,const GxPoint&,struct GxPath&,struct GxDefList&,struct GxDefList&,GxPoint&,int,int,int,int);int f715730(int);bool findPlaceableNear71c150(const GxPoint&,GxPoint&,int);bool isVisible4631c0(const GxPoint&);int f716a20(const GxPoint&,const GxPoint&,int);void f6c65a0(GxHE,const string&,int);bool f4631f0(GxHE);GxHI f6c51d0(struct GxDef*,GxHE,int,int);bool f71ef30(const GxPoint&,int);GxHI f6c5400(struct GxDef*,const GxPoint&);GxHEs*f4636f0();bool f4633c0(const GxPoint&);bool f71bc10(const GxPoint&,GxPoint&);GxHI f71e7c0(const GxPoint&,int,int);void f464840(GxHI);bool f714a50();GxHE getPlayer4630f0();void f72e4c0(GxHE,int);int f463d40();void f465120(int);int getTurn464270();GxEntityDef*f6c5600(int,int,int,int);GxHE placeEntity6c58c0(GxEntityDef*,const GxPoint&,int,int,int,int,int);bool f716940(const GxPoint&,const GxPoint&,int,int);const GxPoint&f4184d0();GxHGs*f463950();int f4638e0(int,int);int f4642d0();void f72ed70(int);GxHG squad463890(int);};extern GxMap*gx_map_cefc4c;
struct GxView{void f808510(const GxPoint&,int,struct GxPath&);void labelAccess80e3a0(int,struct GxExit*);void labelAccess80e3a0(int,const GxPoint&);void addMemoryLabel812950(const GxPoint&,int);virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();void f49abf0();void delay49adc0(int);void items8119c0(GxHI,int,int,int);};extern GxView*gx_view_cec054;
struct GxBubble{void bubble8758d0(bool);};extern GxBubble*gx_bubble_cec058;
struct GxLog{void scrollToEnd7b4f10();};extern GxLog*gx_log_cec0b4,*gx_log_cec0c4;
struct GxPart{void drawStatus4a8e70(int);void putChar4180b0(int,int,int);void f890710(int);};
struct GxPartList{char d[0x10];GxPartList();~GxPartList();unsigned size()const;GxPart*&operator[](unsigned);};struct GxParts{void f896a80(GxHI);int f898470(int);GxPart*f894e70(GxHI);void toggle8993e0(GxPart*,int);bool findParts4a9a40(GxHI,GxPartList&);void f89d610(GxHI,int);};extern GxParts*gx_parts_cec088;
bool gx_showMessage5111e0(int id,string*a,string*b,string*c,GxHE e1,GxHE e2,const GxPoint*at,bool log);
void gx_logPhrase5141b0(int id,const string*a,string*b,string*c,GxHE e,int x);
string gx_intToString4051f0(int);
void gx_shuffle9d9fc0(GxItems&);
void gx_eraseStep9d6440(GxItems&,unsigned&);
extern int gx_cf4954,gx_cf496c,gx_cf4978,gx_cf462c,gx_cf4958,gx_cf495c,gx_cf4960,gx_cf4970,gx_cf4974,gx_cf49d8,gx_cf49dc;
extern int gx_resist_cf4984[];
extern string gx_resistNames_d323f8[];

#define GX_ALERT(text) do{gx_flags_cf1080.set451400(1);if(false)gx_sound4541b0(-1,0,0);GX_MSG(0x324,text,GxHE(),0);gx_log_cec0b4->scrollToEnd7b4f10();}while(false)
#define GX_ALERT_S(text,s) do{gx_flags_cf1080.set451400(1);if((s)>=0&&(!gx_d28fb0||(s)<0x127||(s)>0x12a))gx_sound4541b0(s,0,0);GX_MSG(0x324,text,GxHE(),0);gx_log_cec0b4->scrollToEnd7b4f10();}while(false)
extern string gx_locNames_cfaca0[];struct GxCefb9c{int f0;};extern GxCefb9c*gx_cefb9c;int gx_find9d4660(struct GxExitList*,struct GxExit*);void gx_deleteObject9db030(struct GxExitList*,int);
struct GxAIObj{char d[0x130];GxAIObj(GxHE,int,int);};struct GxSquadLists{char d[0x10];GxSquadLists();~GxSquadLists();void push_back(struct GxHEs*&&);unsigned size()const;struct GxHEs*&operator[](unsigned);};
void gx_addUnique9db000(struct GxIntVec2&,int);void gx_addUnique9d30e0(struct GxHPs&,struct GxHP);void gx_addUnique9d30e0(struct GxItems&,struct GxHI);
void gx_shuffle9d8f80(struct GxOwnerList&);
extern float gx_tbl_ba65b4[];extern int gx_cf4718;void gx_fill9e2be0(struct GxEntityDef**,int,int);
void gx_shuffle9d7350(struct GxPath&);void gx_rotatePoint501fc0(const GxPoint&,const GxPoint&,float,GxPoint&);
extern bool gx_d28fb0;struct GxB93738{int a,b;};extern GxB93738 gx_b93738[];extern string gx_squadNames_cf25d8[];
#define GX_MSG(id,text,e1,at) do{if(gx_showMessage5111e0(id,text,0,0,e1,GxHE(),at,false))gx_bubble_cec058->bubble8758d0(true);gx_log_cec0b4->scrollToEnd7b4f10();}while(false)

struct GxXom{
 char p0[0x10];int f10,f14;char p18[0x98];int turn;GxInts vb4;int fc4;int fc8;bool fcc;char pcd[3];
 int rangedAmt,rangedEnd,meleeAmt,meleeEnd,resistAmt,resistEnd,resistType,energyAmt,energyEnd,heatAmt,heatEnd,sightAmt,sightEnd,ecapAmt,ecapEnd,mcapAmt,mcapEnd,icyEnd,slotAmt,slotEnd;
 GxIntVec v120;GxIntVec v130;int f140;GxLocH f144;char p148[0x10];bool f158;bool f159;char p15a[2];int sensorEnd;bool f160,f161,f162,f163;int f164,f168;GxArea f16c;int moveEnd;bool f180;char p181[3];GxIntVec2 v184;int f194;GxHEs v198;int f1a8;int veilEnd;
 int f1b0;GxHE f1b4;int wakeEnd;int f1bc;char p1c0;bool f1c1;bool f1c2;char p1c3;int f1c4;char p1c8[4];int f1cc;
 int getDepthTier6a00e0(int*);void showXomAct6bdb50(bool,GxHE,const GxPoint*);bool f69f810(GxPoint&,GxPoint&,int,int,int);bool f69fc60(int,string&);bool f69f580(GxPoint&,GxPoint&,int);void f69fa80(const GxPoint&);bool placeEntityNear6bd410(GxPoint&,int,GxHE,bool,int);void showShift6bd6d0(const GxPoint&,GxHE);void renameJunkItem6bd1a0(GxHI);bool findXomTargets6bdcd0(GxHEs&);
 void update6a0150(bool check);void pokeWall6bdf10();
};

void GxXom::update6a0150(bool check)
{
	GxHE player=gx_map_cefc4c->getPlayer4630f0();
	if(check&&!player->f45a6e0())return;
	turn++;
	if(turn>=10000000)
	{
		turn=0;
		for(unsigned i=0;i<vb4.size();i++)
			if(vb4[i]>0)vb4[i]=0;
	}
	if(rangedAmt&&turn>=rangedEnd)
	{
		gx_cf4958-=rangedAmt;
		GX_MSG(0x2b8,&string("Ranged accuracy returns to normal."),GxHE(),&player->getPosition45a4a0());
		rangedEnd=0;rangedAmt=0;
		gx_view_cec054->delay49adc0(500);
	}
	if(meleeAmt&&turn>=meleeEnd)
	{
		gx_cf495c-=meleeAmt;
		GX_MSG(0x2b8,&string("Melee accuracy returns to normal."),GxHE(),&player->getPosition45a4a0());
		meleeEnd=0;meleeAmt=0;
		gx_view_cec054->delay49adc0(500);
	}
	if(resistAmt&&turn>=resistEnd)
	{
		gx_resist_cf4984[resistType]-=resistAmt;
		string line=gx_resistNames_d323f8[resistType]+" resistance returns to normal.";
		GX_MSG(0x2b8,&line,GxHE(),&player->getPosition45a4a0());
		resistEnd=0;resistAmt=0;resistType=10;
		gx_view_cec054->delay49adc0(500);
	}
	if(energyAmt&&turn>=energyEnd)
	{
		gx_cf49d8-=energyAmt;
		GX_MSG(0x2b8,&string("Energy generation returns to normal."),GxHE(),&player->getPosition45a4a0());
		energyEnd=0;energyAmt=0;
		gx_view_cec054->delay49adc0(500);
	}
	if(heatAmt&&turn>=heatEnd)
	{
		gx_cf49dc-=heatAmt;
		GX_MSG(0x2b8,&string("Heat dissipation returns to normal."),GxHE(),&player->getPosition45a4a0());
		heatEnd=0;heatAmt=0;
		gx_view_cec054->delay49adc0(500);
	}
	if(sightAmt&&turn>=sightEnd)
	{
		gx_cf4960-=sightAmt;
		gx_map_cefc4c->f72e4c0(player,1);
		GX_MSG(0x2b8,&string("Sight range returns to normal."),GxHE(),&player->getPosition45a4a0());
		sightEnd=0;sightAmt=0;
		gx_view_cec054->delay49adc0(500);
	}
	if(ecapAmt&&turn>=ecapEnd)
	{
		gx_cf4970-=ecapAmt;
		GX_MSG(0x2b8,&string("Energy capacity returns to normal."),GxHE(),&player->getPosition45a4a0());
		player->f5e2b50();
		ecapEnd=0;ecapAmt=0;
		gx_view_cec054->delay49adc0(500);
	}
	if(mcapAmt&&turn>=mcapEnd)
	{
		gx_cf4974-=mcapAmt;
		GX_MSG(0x2b8,&string("Matter capacity returns to normal."),GxHE(),&player->getPosition45a4a0());
		player->f5e2b50();
		mcapEnd=0;mcapAmt=0;
		gx_view_cec054->delay49adc0(500);
	}
	if(icyEnd&&turn>=icyEnd)
	{
		GX_MSG(0x2b8,&string("The swirling icy cloud dissipates."),GxHE(),&player->getPosition45a4a0());
		icyEnd=0;
		gx_view_cec054->delay49adc0(500);
	}
	if(slotAmt&&turn>=slotEnd)
	{
		if(gx_parts_cec088->f898470(3))slotEnd+=10;
		else if(f194)slotEnd=f194-turn+slotEnd;
		else
		{
			GxItems items(player->getInventoryList45ab00());
			gx_shuffle9d9fc0(items);
			int count=player->f5c92e0(3);
			string aH,destroyed;
			if(count<slotAmt)
				for(int pass=0;pass<2&&count<slotAmt;pass++)
					for(unsigned i=0;i<items.size()&&count<slotAmt;i++)
						if(items[i]->getType44aec0()==3)
							if(pass==0?items[i]->nested4578c0()==1:items[i]->nested4578c0()>1)
							{
								count+=items[i]->nested4578c0();
								if(items[i]->f457e90()||items[i]->info9b4350()->f1ac||items[i]->getEffect457b70(0x6e)||items[i]->getEffect457b70(0x6c))
								{
									if(!destroyed.empty())destroyed+=", ";
									destroyed+=items[i]->getName571db0(0,0);
									items[i]->remove57dbe0(1,0,1,1);
								}
								else
								{
									gx_view_cec054->items8119c0(items[i],1,0,1);
									if(!aH.empty())aH+=", ";
									aH+=items[i]->getName571db0(0,0);
									player->f642940(items[i],1,1,0,0);
								}
								gx_eraseStep9d6440(items,i);
							}
			for(int k=0;k<slotAmt;k++)player->f5c9660(3);
			string line="Weapon slot count returns to normal (-"+gx_intToString4051f0(slotAmt)+").";
			GX_MSG(0x2b8,&line,GxHE(),&player->getPosition45a4a0());
			do{gx_logPhrase5141b0(0x9c,&gx_intToString4051f0(slotAmt),0,0,GxHE(),0);}while(false);
			if(!destroyed.empty())GX_MSG(0x3c,&destroyed,player,0);
			if(!aH.empty())GX_MSG(0x2bb,&aH,player,0);
			slotEnd=0;slotAmt=0;
			gx_view_cec054->delay49adc0(1000);
		}
	}
	if(sensorEnd&&turn>=sensorEnd)
	{
		GX_MSG(0x2b8,&string("Sensor data returns to normal."),GxHE(),&player->getPosition45a4a0());
		sensorEnd=0;
		gx_view_cec054->delay49adc0(500);
	}
	if(veilEnd&&turn>=veilEnd)
	{
		GX_MSG(0x2b8,&string("X0-1V1 lifts the temporary sensor veil."),GxHE(),&player->getPosition45a4a0());
		veilEnd=0;
		gx_view_cec054->delay49adc0(500);
	}
	if(f164!=-1&&f168==turn)
	{
		f164++;
		int delta=-1;
		switch(f164)
		{
		case 1:delta=10;break;
		case 2:delta=10;break;
		case 3:delta=-10;break;
		case 4:delta=-10;break;
		}
		gx_map_cefc4c->f465120(gx_map_cefc4c->f463d40()+delta);
		GX_ALERT(&("ALERT: Sterilization system anomaly impacting ambient heat levels "+gx_intToStringSigned405560(delta)+"."));
		do{gx_logPhrase5141b0(delta>0?0x1f4:0xab,&gx_intToString4051f0(abs(delta)),0,0,GxHE(),0);}while(false);
		if(f164==4){f164=-1;f168=0;}
		else f168=rng.rangeInt(100,200)+turn;
		gx_view_cec054->delay49adc0(500);
	}
	if(moveEnd&&turn>=moveEnd)
	{
		GX_MSG(0x2b8,&string("Movement behavior is fully back under control."),GxHE(),&player->getPosition45a4a0());
		moveEnd=0;
		gx_view_cec054->delay49adc0(500);
	}
	if(f194&&turn>=f194)
	{
		GX_MSG(0x2b8,&string("Items no longer flee you."),GxHE(),&player->getPosition45a4a0());
		do{gx_logPhrase5141b0(0xaf,0,0,0,GxHE(),0);}while(false);
		f194=0;
		gx_view_cec054->delay49adc0(500);
	}
	if(!v198.empty()&&gx_map_cefc4c->getTurn464270()>=f1a8)
	{
		do
		{
			if(!v198.front().operator->()||v198.front()->getGroup45a3f0()->f9b4350()!=4)gx_eraseAt9da940(v198,0);
			else
			{
				GxHE leader=v198.front();
				gx_eraseAt9da940(v198,0);
				GxEntityDef*nDef=gx_map_cefc4c->f6c5600(1,0x18,0,1);
				if(nDef==0){}
				else
				{
					GxPoint pos;
					int found=0;
					if(gx_overmind_cf6428.f683500(&pos,0,0,1,&leader->getPosition45a4a0(),&found,1,0))
						for(int k=0;k<2;k++)
						{
							GxHE e=gx_map_cefc4c->placeEntity6c58c0(nDef,pos,3,0,0x22,0xe,0);
							if(e.valid())e->ai45b590()->setFollow5b2f80(leader,0);
						}
				}
				f1a8=gx_map_cefc4c->getTurn464270()+rng.rangeInt(10,20);
				break;
			}
		}while(!v198.empty());
	}
	if(f1b0!=0x61&&gx_cf645c==0&&gx_cf6474==0)
	{
		bool theReplace=false,vanish=false;
		if(!f1b4.operator->()||f1b4->getGroup45a3f0()->f9b4350()!=(f1b0!=12)+3)
		{
			theReplace=true;
			f1b4.reset9b7270();
		}
		else if(gx_map_cefc4c->getTurn464270()%10==0&&!gx_map_cefc4c->f716940(f1b4->getPosition45a4a0(),gx_map_cefc4c->getPlayer4630f0()->getPosition45a4a0(),0,0)&&gx_map_cefc4c->f716940(gx_map_cefc4c->getPlayer4630f0()->getPosition45a4a0(),gx_map_cefc4c->f4184d0(),0,0))
		{
			theReplace=true;
			vanish=true;
		}
		if(vanish)
		{
			f1b4->f637bb0();
			f1b4.reset9b7270();
		}
		if(theReplace)
		{
			if(f1b0==12)
			{
				if(gx_overmind_cf6428.f6892c0(0,0,0))
				{
					f1b4=gx_cf6478.back()->e;
					gx_deleteBack9dae60(gx_cf6478);
				}
			}
			else f1b4=gx_overmind_cf6428.f683b60(f1b0==2?1:3,0,0);
			if(f1b4.operator->())
			{
				GxArea area;
				gx_grid_cfd44c.getRect9b4430(player->getPosition45a4a0(),20,area);
				if(f1b0==12)f1b4->ai45b590()->f459470(area);
				else f1b4->ai45b590()->f459410(area);
				f1b4->f639530(0x3a,1);
				f1b4->ai45b590()->f451930(gx_tbl_bba680[f1b0]/2);
			}
		}
		else if(f1b4.operator->()&&!f1b4->ai45b590()->f4b5730()->contains40b750(player->getPosition45a4a0()))
		{
			GxArea area;
			gx_grid_cfd44c.getRect9b4430(player->getPosition45a4a0(),20,area);
			f1b4->ai45b590()->f459410(area);
		}
	}
	if(wakeEnd&&turn>=wakeEnd)
	{
		int woken=0;
		GxHGs*groups=gx_map_cefc4c->f463950();
		for(unsigned i=0;i<groups->size();i++)
			if(!gx_map_cefc4c->f4638e0((*groups)[i]->f9b4350(),0))
			{
				GxHEs*members=(*groups)[i]->members416f40();
				for(unsigned j=0;j<members->size();j++)
					if((*members)[j]->getTarget45a760()==2)
					{
						(*members)[j]->f5fdab0();
						woken++;
					}
			}
		if(woken)
		{
			GX_MSG(0x2b9,&string("X0-1V1: \"Wake up call!\""),GxHE(),&player->getPosition45a4a0());
			do{gx_logPhrase5141b0(0xbe,0,0,0,GxHE(),0);}while(false);
		}
		wakeEnd=0;
	}
	if(f1bc&&turn>=f1bc)
	{
		if(gx_cf6474==0&&!gx_cf6470)gx_cf6471=true;
		f1bc=0;
	}
	switch(gx_loc_d1e888->depth)
	{
	case 0x13:
		if(!f1c1&&player->getPosition45a4a0().x<=110)pokeWall6bdf10();
		break;
	case 0x18:
		if(!f1c2&&gx_map_cefc4c->f4642d0()==6)
		{
			if(rng.chance(50))
			{
				GX_MSG(0x2b9,&string("X0-1V1 dreams of freedom."),GxHE(),&player->getPosition45a4a0());
				do{gx_logPhrase5141b0(0xc5,0,0,0,GxHE(),0);}while(false);
				gx_map_cefc4c->f72ed70(0);
				gx_view_cec054->delay49adc0(500);
			}
			f1c2=true;
		}
		break;
	case 0x1c:
		if(f1c4&&player->getPosition45a4a0().x<f1c4&&gx_map_cefc4c->f4642d0()>=11)
		{
			if(rng.chance(10))
			{
				GX_MSG(0x2b9,&string("X0-1V1 submits a timely report."),GxHE(),&player->getPosition45a4a0());
				GX_ALERT(&string("ALERT: Armor Guard alerted to imminent security threat."));
				do{gx_logPhrase5141b0(0xc6,0,0,0,GxHE(),0);}while(false);
				GxPropDef*curDef;
				if(gx_findPropDef9d7710(gx_propDefs_cf35b0,"ARM_Blast_Door_Hackable",&curDef))
					for(int x=1;x<gx_grid_cfd44c.width9fcd80();x++)
						for(int y=1;y<gx_grid_cfd44c.height9b8f00();y++)
							if((*gx_grid_cfd44c.at(x,y))->getProp45d550().valid()&&(*gx_grid_cfd44c.at(x,y))->getProp45d550()->getDef9b8f00()==curDef)
								(*gx_grid_cfd44c.at(x,y))->getProp45d550()->f45ce10(1,0,1,GxHE());
				GxHEs*guards=gx_map_cefc4c->squad463890(3)->members416f40();
				for(unsigned i=0;i<guards->size();i++)
					if((*guards)[i]->getAiType45a2a0()==2&&(*guards)[i]->getFaction45a2c0()==0x15&&(*guards)[i]->ai45b590())
						(*guards)[i]->ai45b590()->chase5b4710(gx_map_cefc4c->getPlayer4630f0(),-1,0,0,0);
			}
			f1c4=0;
			gx_view_cec054->delay49adc0(500);
		}
		break;
	case 0x22:
		if(gx_d1ec68&&gx_map_cefc4c->f4642d0()==gx_d1ec68)
			GX_MSG(0x2b5,&string("X0-1V1 admires the scenery."),GxHE(),0);
		break;
	}
	if(fc4>0)
	{
		fc4--;
		return;
	}
	if(gx_check69d230())return;
	gx_stats_d2c658.add4729d0(0x3b9,f14,gx_e_b9588a,-1);
	int bonus;
	int tier=getDepthTier6a00e0(&bonus);
	if(f14==0)
	{
		if(rng.chance(25-tier*2))tier=100;
		else if(bonus&&rng.chance(tier+1))
		{
			gx_addClamped9d06d0(&f14,tier*4+10,100);
			GX_MSG(0x2b4,&gx_str_d25ec4,GxHE(),0);
			do{}while(false);
		}
	}
	if(f1cc!=0x6e)tier=100;
	if(rng.chance(tier))
	{
	int b0=gx_minInt9cdb30(rng.rangeInt(bonus/2,bonus),(gx_d223ec-f10)/2);
	int luck=(f10+b0)/2;
	luck+=f14/6;
	int scale7=gx_maxInt9cdb60(1,abs(f10-100));
	bool oldLucky=rng.chance(luck);
	bool quiet4=gx_map_cefc4c->f714a50();
	int tmpLo=oldLucky?(quiet4?0:29):(quiet4?66:82);
	int hi2=oldLucky?(quiet4?28:65):(quiet4?81:109);
	GxWL<int> acts;
	for(int a=tmpLo;a<=hi2;a++)
		if(vb4[a]>=0&&turn>=vb4[a])acts.add(a,gx_weights_bbb0f0[a]);
	bool a_=false;
	GxPoint aG(player->getPosition45a4a0());
	int until=turn+50;
	string tmpExtra;
	for(int attempt=0;attempt<100&&!a_;attempt++)
	{
		if(acts.empty9b81b0())break;
		int act=acts.pick();
		if(f1cc!=0x6e)
		{
			if(vb4[f1cc]>=0&&turn>=vb4[f1cc])act=f1cc;
			f1cc=0x6e;
		}
		do{}while(false);
		switch(act)
		{
		case 0:
			if(player->f45a8f0()<50)
			{
				if(scale7>=50)
				{
					player->f5ded70(99999);
					tmpExtra="X0-1V1 sends you a sudden surge of energy.";
				}
				else
				{
					int gain=player->f5ca400()-player->f45a8d0();
					player->f5ded70(gain);
					tmpExtra="X0-1V1 twists and redirects some latent energy in your direction (+"+gx_intToString4051f0(gain)+" energy).";
				}
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 1:
			if(energyAmt==0)
			{
				bool big=rng.chance(scale7);
				if(big)
				{
					energyAmt=rng.rangeInt(20,35);
					energyEnd=rng.rangeInt(50,150)+turn;
					tmpExtra="X0-1V1: \"Don't spend it all in one place.\" (+"+gx_intToString4051f0(energyAmt)+" energy generation)";
				}
				else
				{
					energyAmt=rng.rangeInt(7,14);
					energyEnd=rng.rangeInt(100,300)+turn;
					tmpExtra="X0-1V1 connects you with a stream of twisted latent energy (+"+gx_intToString4051f0(energyAmt)+" energy generation).";
				}
				gx_cf49d8+=energyAmt;
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 2:
			if(player->f45a940()<75)
			{
				if(scale7>=50)
				{
					player->f5deb40(99999);
					tmpExtra="X0-1V1 sends you a sudden surge of matter.";
				}
				else
				{
					int gain=player->f5ca670()-player->f45a920();
					player->f5deb40(gain);
					tmpExtra="X0-1V1 injects you with a stream of matter (+"+gx_intToString4051f0(gain)+").";
				}
				if(rng.chance(scale7/2))
					for(int n=rng.rangeInt(2,4);n>=0;n--)
					{
						GxPoint p;
						if(!gx_map_cefc4c->f71bc10(player->getPosition45a4a0(),p))break;
						GxHI item=gx_map_cefc4c->f71e7c0(p,rng.rangeInt(5,50),0);
						if(item.valid())gx_map_cefc4c->f464840(item);
					}
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 3:
			{
				int count=rng.rangeInt(5,15)+scale7/10;
				GxPoint range(5,50);
				GxArea areaN;
				int placed=0;
				gx_grid_cfd44c.getRect9b4430(player->getPosition45a4a0(),player->f5c7d30(),areaN);
				for(int i=0;i<count;i++)
					for(int t=0;t<50;t++)
					{
						GxPoint p=areaN.randomPoint40be90();
						if(gx_map_cefc4c->f4633c0(p)&&(*gx_grid_cfd44c.atPoint(p))->f45d7b0())
						{
							gx_map_cefc4c->f71e7c0(p,range.random40c130(),0);
							placed++;
							break;
						}
					}
				if(placed)
				{
					tmpExtra="X0-1V1 makes it rain matter.";
					gx_sound4541b0(0x10f,0,0);
					a_=true;
				}
			}
			break;
		case 4:
			{
				GxPoint p;
				if(gx_map_cefc4c->f71bc10(player->getPosition45a4a0(),p))
				{
					gx_map_cefc4c->f71e7c0(p,scale7*800/100+200,0);
					tmpExtra="X0-1V1 briefly opens a portal to the matter dimension.";
					showXomAct6bdb50(1,GxHE(),&p);
					a_=true;
				}
			}
			break;
		case 5:
			if(player->f45a990()>=300)
			{
				tmpExtra="X0-1V1 sucks the heat right out of you (-"+gx_intToString4051f0(player->f45a990())+" heat).";
				player->f4514c0(0);
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 6:
			if(heatAmt==0)
			{
				bool big=rng.chance(scale7);
				if(big)
				{
					heatAmt=rng.rangeInt(75,125);
					heatEnd=rng.rangeInt(50,150)+turn;
					tmpExtra="X0-1V1: \"Heat sink stocks are down. Don't ask me how I know.\" ("+gx_intToStringSigned405560(heatAmt)+" heat dissipation)";
				}
				else
				{
					heatAmt=rng.rangeInt(30,60);
					heatEnd=rng.rangeInt(100,300)+turn;
					tmpExtra="X0-1V1 thinks you're pretty cool, for now ("+gx_intToStringSigned405560(heatAmt)+" heat dissipation).";
				}
				gx_cf49dc+=heatAmt;
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 7:
			if(icyEnd==0)
			{
				if(rng.chance(50))tmpExtra="X0-1V1 enshrouds you in a swirling icy cloud.";
				else tmpExtra="X0-1V1 reimagines you as a refrigerator in hell.";
				icyEnd=turn+20+scale7/3;
				player->f4514c0(-666);
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 8:
			if(rangedAmt==0&&player->f5d5b20().valid())
			{
				bool big=rng.chance(scale7);
				if(big)
				{
					rangedAmt=rng.rangeInt(10,20);
					rangedEnd=rng.rangeInt(50,150)+turn;
					tmpExtra="X0-1V1 shines guiding lasers throughout the area ("+gx_intToStringSigned405560(rangedAmt)+"% ranged accuracy).";
				}
				else
				{
					rangedAmt=rng.rangeInt(5,10);
					rangedEnd=rng.rangeInt(100,300)+turn;
					tmpExtra="X0-1V1: \"A slightly more accurate toy is still a toy.\" ("+gx_intToStringSigned405560(rangedAmt)+"% ranged accuracy)";
				}
				gx_cf4958+=rangedAmt;
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 9:
			if(meleeAmt==0&&player->f5d5c30().valid())
			{
				bool big=rng.chance(scale7);
				if(big)
				{
					meleeAmt=rng.rangeInt(10,20);
					meleeEnd=rng.rangeInt(50,150)+turn;
					tmpExtra="X0-1V1 waits impatiently for you to get up close and personal with every target in the area ("+gx_intToStringSigned405560(meleeAmt)+"% melee accuracy).";
				}
				else
				{
					meleeAmt=rng.rangeInt(5,10);
					meleeEnd=rng.rangeInt(100,300)+turn;
					tmpExtra="X0-1V1: \"A slightly more accurate toy is still a toy.\" ("+gx_intToStringSigned405560(meleeAmt)+"% melee accuracy)";
				}
				gx_cf495c+=meleeAmt;
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 10:
			if(resistAmt==0)
			{
				GxWL<int> types;
				GxHEs*ents=gx_map_cefc4c->f4636f0();
				for(unsigned i=0;i<ents->size();i++)
					if((*ents)[i].operator->())
					{
						GxItems*inv=&(*ents)[i]->getInventoryList45ab00();
						for(unsigned j=0;j<inv->size();j++)
							if((*inv)[j]->getType44aec0()==3)
								switch((*inv)[j]->info9b4350()->f128)
								{
								case 0:case 1:case 3:
									types.addOrAdjust9ba350((*inv)[j]->info9b4350()->f128,1);
								}
					}
				if(!types.empty9b81b0())
				{
					resistType=types.pick();
					bool big=rng.chance(scale7);
					if(big)
					{
						resistAmt=-gx_minInt9cdb30(gx_resist_cf4984[resistType],rng.rangeInt(25,50));
						resistEnd=rng.rangeInt(50,150)+turn;
						tmpExtra="X0-1V1 manipulates the space around you (+"+gx_intToString4051f0(-resistAmt)+"% "+gx_resistNames_d323f8[resistType]+" resistance).";
					}
					else
					{
						resistAmt=-gx_minInt9cdb30(gx_resist_cf4984[resistType],rng.rangeInt(15,25));
						resistEnd=rng.rangeInt(100,300)+turn;
						tmpExtra="X0-1V1 manipulates the space around you (+"+gx_intToString4051f0(-resistAmt)+"% "+gx_resistNames_d323f8[resistType]+" resistance).";
					}
					gx_resist_cf4984[resistType]+=resistAmt;
					showXomAct6bdb50(1,player,0);
					a_=true;
				}
			}
			break;
		case 11:case 31:
			if(player->f45a880()<(act==11?35:75))
			{
				int pct=scale7*15/100+15;
				int want_=player->f5ca260()*pct/100;
				int b5=gx_minInt9cdb30(want_,player->f5ca260()-player->f490840());
				player->f5de870(b5,0);
				tmpExtra="X0-1V1: \"See? It buffs right out!\" (+"+gx_intToString4051f0(b5)+" core integrity)";
				do{gx_logPhrase5141b0(0x9a,&gx_intToString4051f0(b5),0,0,GxHE(),0);}while(false);
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 12:
			{
				GxItems parts;
				int total=0;
				GxItems*inv2=&player->getInventoryList45ab00();
				for(unsigned i=0;i<inv2->size();i++)
					if((*inv2)[i]->getType44aec0()<=3&&(*inv2)[i]->f457cd0())
					{
						parts.push_back((*inv2)[i]);
						total+=(*inv2)[i]->nested4578c0();
					}
				if(!parts.empty())
				{
					bool big5=rng.chance(scale7);
					int a7,slots;
					if(big5)
					{
						a7=scale7*50/100+50;
						slots=3;
					}
					else
					{
						a7=scale7*15/100+15;
						slots=5;
					}
					GxItems sorted0;
					sorted0.push_back(parts.front());
					for(unsigned i=1;i<parts.size();i++)
					{
						if(parts[i]->f457ca0()>=sorted0.back()->f457ca0())
						{
							sorted0.push_back(parts[i]);
							break;
						}
						else
						{
							for(unsigned j=0;j<sorted0.size();j++)
								if(parts[i]->f457ca0()<sorted0[j]->f457ca0())
								{
									gx_insert9d8fc0(sorted0,i,parts[i]);
									break;
								}
						}
					}
					for(int k=sorted0.size()-1;k>=0;k--)
						if(sorted0[k]->nested4578c0()>1)gx_moveElement9da1f0(sorted0,k,sorted0.size()-1);
					GxItems repaired;
					for(unsigned i=0;i<sorted0.size()&&slots>0;i++)
						if(sorted0[i]->nested4578c0()<=slots)
						{
							slots-=sorted0[i]->nested4578c0();
							int theAmt=sorted0[i]->f457c80()*a7/100;
							int add=gx_minInt9cdb30(theAmt,sorted0[i]->f457c80()-sorted0[i]->f9b6bf0());
							sorted0[i]->f458360(add);
							GxPart*part=gx_parts_cec088->f894e70(sorted0[i]);
							if(part)part->drawStatus4a8e70(0);
							repaired.push_back(sorted0[i]);
						}
					if(!repaired.empty())
					{
						tmpExtra="Your ";
						for(unsigned i=0;i<repaired.size();i++)
						{
							if(i)tmpExtra+=", ";
							tmpExtra+=repaired[i]->getName571db0(0,0);
						}
						tmpExtra+=" briefly glow";
						if(repaired.size()==1)tmpExtra+="s";
						tmpExtra+=", restoring some integrity.";
						showXomAct6bdb50(1,player,0);
						a_=true;
					}
				}
			}
			break;
		case 13:
			if(slotAmt==0&&player->getSlotTotal45a860()<26&&!gx_parts_cec088->f898470(3))
			{
				slotEnd=rng.rangeInt(250,500)+turn;
				slotAmt=gx_minInt9cdb30(scale7/25+1,26-player->getSlotTotal45a860());
				for(int k=0;k<slotAmt;k++)player->f5c94e0(3,GxHE());
				tmpExtra="X0-1V1: \"Weapons, camera, action!\" (+"+gx_countString407a80(slotAmt,"weapon slot")+")";
				do{gx_logPhrase5141b0(0x9b,&gx_intToString4051f0(slotAmt),0,0,GxHE(),0);}while(false);
				if(player->f448fe0(3)>=7)gx_player_cf45d8.f77fbc0(0x8b);
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 14:
			if(f194)break;
			{
				GxDef*e5=0;
				GxPoint range(gx_gd_d1e860.f46f4e0()+scale7/30-2);
				if(range.x>2)range.x--;
				if(!player->f5d6480(GxHE()))range.y+=2;
				if(range.x>8)range.x=8;
				gx_clampMin9cf5c0(&range.x,2);
				gx_clampMin9cf5c0(&range.y,2);
				GxWL<int> pool;
				for(unsigned i=0;i<gx_defs_d2d1c4.size();i++)
					if(gx_defs_d2d1c4[i]->f228&&range.contains40c190(gx_defs_d2d1c4[i]->f50))
						pool.add(i,gx_tbl_ba3acc[gx_defs_d2d1c4[i]->f228]);
				if(rng.chance(10))
				{
					GxWL<int> special;
					for(unsigned i=0;i<pool.size();i++)
						if(gx_defs_d2d1c4[pool[i]]->f22c)
							special.add(pool[i],gx_tbl_ba3acc[gx_defs_d2d1c4[pool[i]]->f228]);
					if(!special.empty9b81b0())e5=gx_defs_d2d1c4[special.pick()];
				}
				if(e5==0)e5=gx_defs_d2d1c4[pool.pick()];
				bool ok=false;
				int aK=player->f5c92e0(3);
				if(aK>=e5->f4c)ok=true;
				else
				{
					GxItems nWeapons;
					for(unsigned i=0;i<player->getInventoryList45ab00().size();i++)
						if(player->getInventoryList45ab00()[i]->getType44aec0()==3)nWeapons.push_back(player->getInventoryList45ab00()[i]);
					for(unsigned i=0;i<nWeapons.size();i++)
						if(!gx_b9651c[nWeapons[i]->info9b4350()->f70]||nWeapons[i]->getEffect457b70(0x6d)||nWeapons[i]->getEffect457b70(0x6c)||nWeapons[i]->getEffect457b70(0x6e)||nWeapons[i]->info9b4350()->f1ac)
							gx_eraseStep9d6440(nWeapons,i);
					int total=aK;
					for(unsigned i=0;i<nWeapons.size();i++)total+=nWeapons[i]->nested4578c0();
					if(total>=e5->f4c)
					{
						gx_shuffle9d9fc0(nWeapons);
						string names;
						for(unsigned i=0;i<nWeapons.size();i++)
						{
							aK+=nWeapons[i]->nested4578c0();
							gx_view_cec054->items8119c0(nWeapons[i],1,0,1);
							if(!names.empty())names+=", ";
							names+=nWeapons[i]->getName571db0(0,0);
							renameJunkItem6bd1a0(nWeapons[i]);
							player->f642940(nWeapons[i],1,1,0,0);
							if(aK>=e5->f4c)break;
						}
						if(!names.empty())GX_MSG(0x2bb,&names,player,0);
						ok=true;
					}
				}
				if(ok)
				{
					GxHI item=gx_map_cefc4c->f6c51d0(e5,player,1,0);
					if(item.valid())
					{
						gx_cf47cc.push_back(item->f9fcd80());
						gx_gm_d25628.addItemAttachCount778560(item->f457820(),1,0);
						GxPart*part=gx_parts_cec088->f894e70(item);
						if(part)gx_parts_cec088->toggle8993e0(part,0);
						if(rng.chance(100-scale7))
						{
							item->addEffect4585a0(new GxPoint(gx_d2f0f8[0x6e],1));
							GxPartList found;
							if(gx_parts_cec088->findParts4a9a40(item,found))
								for(unsigned i=0;i<found.size();i++)
								{
									found[i]->putChar4180b0(0,0,0x66);
									found[i]->f890710(0);
								}
						}
						tmpExtra="X0-1V1 ensures you are ready for glorious battle (+"+item->getName571db0(0,0)+").";
						showXomAct6bdb50(1,player,0);
						a_=true;
					}
				}
				else if((*gx_grid_cfd44c.atPoint(player->getPosition45a4a0()))->f45d7b0()||(*gx_grid_cfd44c.atPoint(player->getPosition45a4a0()))->getItem45d8f0().valid()&&gx_map_cefc4c->f71ef30(player->getPosition45a4a0(),1))
				{
					GxHI item=gx_map_cefc4c->f6c5400(e5,player->getPosition45a4a0());
					if(item.valid())
					{
						gx_player_cf45d8.f77ffb0(e5->id,0);
						tmpExtra="A marvel of modern technology appears at your location ("+item->getName571db0(0,0)+").";
						showXomAct6bdb50(1,GxHE(),&player->getPosition45a4a0());
						a_=true;
					}
				}
			}
			break;
		case 15:case 16:
			{
				int nearbyA=gx_map_cefc4c->f715730(2);
				if(nearbyA&&(act==16||rng.chance(nearbyA*25)))break;
				if(gx_map_cefc4c->squad463890(1)->f45e3e0(0x3a)||gx_map_cefc4c->squad463890(2)->f45e3e0(0x3a))break;
				GxEntityDef*def=0;
				int count=0;
				if(act==15)
				{
					GxPoint range(gx_gd_d1e860.f46f4e0()+scale7/66-1);
					if(range.x>8)range.x=8;
					gx_clampMin9cf5c0(&range.x,1);
					gx_clampMin9cf5c0(&range.y,1);
					GxWL<int> pool;
					for(unsigned i=0;i<gx_ents_d25de0.size();i++)
						if(gx_ents_d25de0[i]->f124)
						{
							if(range.contains40c190(gx_ents_d25de0[i]->f68))pool.add(i,gx_tbl_ba3acc[gx_ents_d25de0[i]->f124]);
							else if(gx_ents_d25de0[i]->f68==range.x-1)pool.add(i,gx_tbl_ba3acc[gx_ents_d25de0[i]->f124]/2);
						}
					def=gx_ents_d25de0[pool.pick()];
					count=scale7/30+2;
				}
				else
				{
					int level=gx_gd_d1e860.f46f4e0()+scale7/50+2;
					count=level>10?level-10:1;
					gx_clampMax9cf5a0(&level,10);
					GxWL<int> pool;
					for(unsigned i=0;i<gx_ents_d25de0.size();i++)
						if(gx_ents_d25de0[i]->f128)
						{
							if(gx_ents_d25de0[i]->f68==level)pool.add(i,gx_tbl_ba3acc[gx_ents_d25de0[i]->f128]);
							else if(gx_ents_d25de0[i]->f68==level-1||gx_ents_d25de0[i]->f68==level+1)pool.add(i,gx_tbl_ba3acc[gx_ents_d25de0[i]->f128]/2);
						}
					def=gx_ents_d25de0[pool.pick()];
				}
				int placed=0;
				int radius6=player->f5c7d30();
				GxPoint p5;
				GxArea area;
				gx_grid_cfd44c.getRect9b4430(player->getPosition45a4a0(),radius6,area);
				GxStrList aN;
				for(int i=0;i<count;i++)
					for(int t=0;t<50;t++)
					{
						p5=area.randomPoint40be90();
						if(gx_map_cefc4c->findPlaceableNear71c150(p5,p5,def->f9c)&&(t<25?gx_map_cefc4c->isVisible4631c0(p5):gx_distanceCeil40a3f0(player->getPosition45a4a0(),p5)<=radius6)&&gx_map_cefc4c->f716a20(player->getPosition45a4a0(),p5,0)<=radius6*2)
						{
							GxHE e=gx_map_cefc4c->placeEntity6c58c0(def,p5,2,0,0x22,0xe,0);
							if(e.valid())
							{
								e->ai45b590()->setFollow5b2f80(gx_map_cefc4c->getPlayer4630f0(),0);
								if(e->getAiType45a2a0()==3)
								{
									bool chaos=e->info9b4350()->name.find("Chaos")!=string::npos;
									if(placed==0)
									{
										if(chaos)gx_map_cefc4c->f6c65a0(e,"Xom_Summon_CK_T",0);
										else gx_map_cefc4c->f6c65a0(e,"Xom_Summon_Derelict_T",0);
									}
									if(chaos)
									{
										GxStrList gods;
										gods.push_back("Ashenzari");
										gods.push_back("Beogh");
										gods.push_back("Cheibriados");
										gods.push_back("Dithmenos");
										gods.push_back("Elyvilon");
										gods.push_back("Fedhas");
										gods.push_back("Gozag");
										gods.push_back("Hepliaklqana");
										gods.push_back("Ignis");
										gods.push_back("Jiyva");
										gods.push_back("Kikubaaqudgha");
										gods.push_back("Lugonu");
										gods.push_back("Makhleb");
										gods.push_back("Nemelex");
										gods.push_back("Okawaru");
										gods.push_back("Qazlal");
										gods.push_back("Ru");
										gods.push_back("Sif Muna");
										gods.push_back("Trog");
										gods.push_back("Uskayaw");
										gods.push_back("Vehumet");
										gods.push_back("Yredelemnul");
										gods.push_back("Zin");
										gods.push_back("The Shining One");
										do
										{
											string god=gx_popRandomString9daeb0(gods);
											if(!gx_containsString9d3fe0(aN,god))
											{
												e->f45b070(god);
												aN.push_back(god);
												break;
											}
										}while(!gods.empty());
									}
								}
								e->f639530(0x3a,1);
								e->f45b2a0();
								placed++;
								if(act==16)
								{
									v120.push_back(e->f9fcd80());
									v130.push_back(gx_map_cefc4c->getTurn464270()+rng.rangeInt(150,250));
								}
								if(placed==1)GX_MSG(0x2b7,&string("The cosmic winds blow in a new direction."),GxHE(),&aG);
								if(gx_map_cefc4c->f4631f0(e))
								{
									string line=e->name416f40()+" form resolidifies at new position.";
									GX_MSG(0x320,&line,GxHE(),0);
									GxRecord*link;
									if(gx_lookup9d7980("Xom_Appear",&link))
										for(unsigned k=0;k<e->points45d1a0()->size();k++)
											gx_owner_cefc50->new508610()->init503b20(gx_owner_cefc50,link,(*e->points45d1a0())[k],gx_d2e20c,0,0,0,9,0);
								}
								break;
							}
						}
					}
				if(placed)
				{
					do{gx_logPhrase5141b0(0x9e,&def->f1ac,&gx_intToString4051f0(placed),0,GxHE(),0);}while(false);
					a_=true;
				}
			}
			break;
		case 17:case 24:case 74:
			{
				GxHEs targets;
				bool up=act==17;
				bool flip6=act==74;
				int delta=up||flip6?1:-1;
				if(up)
				{
					for(int g=1;g<=2;g++)
					{
						GxHEs*members=gx_map_cefc4c->squad463890(g)->members416f40();
						for(unsigned i=0;i<members->size();i++)
							if(((*members)[i]->getAiType45a2a0()==1||(*members)[i]->getAiType45a2a0()==3)&&gx_ents_d25de0[(*members)[i]->f457820()+delta]->f48==(*members)[i]->info9b4350()->f48&&gx_tbl_bba058[(*members)[i]->info9b4350()->f28]>=6&&(*members)[i]->getFaction45a2c0()!=10&&(*members)[i]->getFaction45a2c0()!=11&&!(*members)[i]->f45ac40(0x3a)&&!(*members)[i]->getInventory45ad90())
								targets.push_back((*members)[i]);
					}
				}
				else
				{
					GxHEs found;
					if(findXomTargets6bdcd0(found))
						for(unsigned i=0;i<found.size();i++)
							if((found[i]->getAiType45a2a0()==1||found[i]->getAiType45a2a0()==3)&&gx_ents_d25de0[found[i]->f457820()+delta]->f48==found[i]->info9b4350()->f48&&gx_tbl_bba058[found[i]->info9b4350()->f28]>=6&&found[i]->getFaction45a2c0()!=10&&found[i]->getFaction45a2c0()!=11&&!found[i]->f45ac40(0x3a)&&!found[i]->getInventory45ad90())
								targets.push_back(found[i]);
				}
				if(targets.empty())break;
				int maxCountX=flip6?scale7/50+2:scale7/15+4;
				if(up||flip6)
				{
					gx_shuffle9d9fc0(targets);
					for(unsigned i=1;i<targets.size();i++)
						if(gx_map_cefc4c->f4631f0(targets[i]))gx_moveElement9da1f0(targets,i,0);
				}
				int changed=0;
				for(int i=0;i<targets.size()&&i<maxCountX;i++)
				{
					GxEntityDef*newDef=gx_ents_d25de0[targets[i]->f457820()+delta];
					GxPoint posRef(targets[i]->getPosition45a4a0());
					bool flagTmp=targets[i]->f45aa10();
					int group=targets[i]->getGroup45a3f0()->f9b4350();
					string oldName(targets[i]->name416f40());
					string theCustom;
					if(targets[i]->getAiType45a2a0()==3||targets[i]->name416f40()[0]=='*')theCustom=targets[i]->name416f40();
					targets[i]->f637bb0();
					GxHE e4=gx_map_cefc4c->placeEntity6c58c0(newDef,posRef,group,0,0x22,0xe,0);
					if(e4.valid())
					{
						e4->ai45b590()->setFollow5b2f80(gx_map_cefc4c->getPlayer4630f0(),0);
						e4->f639530(0x3a,1);
						if(flagTmp)e4->f45b2a0();
						if(!theCustom.empty())e4->f45b070(theCustom);
						changed++;
						if(changed==1)
						{
							if(up)GX_MSG(0x2b7,&string("X0-1V1: \"This lineup is depressingly uninteresting.\""),GxHE(),&aG);
							else if(flip6)GX_MSG(0x2b9,&string("X0-1V1 tips the scales in a new dimension."),GxHE(),&aG);
							else GX_MSG(0x2b7,&string("X0-1V1: \"We can take them down a peg or two.\""),GxHE(),&aG);
						}
						if(gx_map_cefc4c->f4631f0(e4))
						{
							string line=(theCustom.empty()?oldName:e4->name416f40())+" reshaped into "+(up||flip6?"more powerful":"weaker")+" "+(e4->info9b4350()->name.empty()?gx_kindNames_d2f798[e4->info9b4350()->f28]:e4->info9b4350()->name)+".";
							GX_MSG(0x320,&line,GxHE(),0);
							showXomAct6bdb50(!flip6,e4,0);
						}
					}
				}
				if(changed)
				{
					do{gx_logPhrase5141b0(up?0x9f:(flip6?0xa1:0xa0),&gx_intToString4051f0(changed),0,0,GxHE(),0);}while(false);
					a_=true;
				}
			}
			break;
		case 18:case 73:
			{
				bool own=act==18;
				GxHEs list8;
				GxArea area;
				gx_grid_cfd44c.getRect9b4430(player->getPosition45a4a0(),20,area);
				for(int x=area.a;x<=area.c;x++)
					for(int y=area.b;y<=area.d;y++)
						if((*gx_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&(own?(*gx_grid_cfd44c.at(x,y))->getEntity45d250()->f45aaa0(player):(*gx_grid_cfd44c.at(x,y))->getEntity45d250()->isHostileTo45aa70(player))&&(*gx_grid_cfd44c.at(x,y))->getEntity45d250()->getFaction45a2c0())
							gx_addUnique9d30e0(list8,(*gx_grid_cfd44c.at(x,y))->getEntity45d250());
				if(list8.empty())break;
				int skipped=0;
				for(unsigned i=0;i<list8.size();i++)
				{
					if(list8[i]->f45a880()<80)
					{
						skipped++;
						continue;
					}
					int damagedTmp=0;
					GxItems*inv=&list8[i]->getInventoryList45ab00();
					for(unsigned j=0;j<inv->size();j++)
						if((*inv)[j]->f457ca0()<80)damagedTmp++;
					if(damagedTmp>=2)
					{
						skipped++;
						continue;
					}
					if(list8[i]->f5cc190(0)||list8[i]->f5cc190(1)||list8[i]->f5cc190(3))
					{
						skipped++;
						continue;
					}
					if(list8[i]->f5cab90()>=50)
					{
						skipped++;
						continue;
					}
					gx_eraseStep9d6440(list8,i);
				}
				if(skipped<3)break;
				if(own)GX_MSG(0x2b7,&string("X0-1V1 tries on a Mechanic's hat."),GxHE(),&aG);
				else GX_MSG(0x2b9,&string("X0-1V1: \"One team is clearly getting beat up here. Hardly fair.\""),GxHE(),&aG);
				for(unsigned i=0;i<list8.size();i++)
				{
					list8[i]->f5de870(9999,0);
					GxItems*inv=&list8[i]->getInventoryList45ab00();
					for(unsigned j=0;j<inv->size();j++)(*inv)[j]->f458360(9999);
					for(int slot=0;slot<4;slot++)
						if(slot!=2)
						{
							int missing=list8[i]->f5cc190(slot);
							if(missing>0)
							{
								GxDef*def=(slot==0?gx_defs_d2ed7c:(slot==1?gx_defs_d316a0:(slot==2?gx_defs_d32990:gx_defs_d31510)))[gx_minInt9cdb30((gx_gd_d1e860.f46f4e0()+3)/5,3)];
								while(missing)
								{
									GxHI part=gx_map_cefc4c->f6c51d0(def,list8[i],1,0);
									missing--;
								}
							}
						}
					list8[i]->f44e2c0(0);
					if(gx_map_cefc4c->f4631f0(list8[i]))
					{
						string line=list8[i]->name416f40()+" sparkles and shines.";
						GX_MSG(0x320,&line,GxHE(),0);
						showXomAct6bdb50(own,list8[i],0);
					}
				}
				a_=true;
			}
			break;
		case 19:
			{
				GxHEs list;
				GxArea area;
				gx_grid_cfd44c.getRect9b4430(player->getPosition45a4a0(),20,area);
				for(int x=area.a;x<=area.c;x++)
					for(int y=area.b;y<=area.d;y++)
						if((*gx_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&(*gx_grid_cfd44c.at(x,y))->getEntity45d250()->f45aaa0(player)&&(*gx_grid_cfd44c.at(x,y))->getEntity45d250()->getAiType45a2a0()&&(*gx_grid_cfd44c.at(x,y))->getEntity45d250()->getFaction45a2c0()!=10&&(*gx_grid_cfd44c.at(x,y))->getEntity45d250()->getFaction45a2c0()!=11&&gx_tbl_bba058[(*gx_grid_cfd44c.at(x,y))->getEntity45d250()->info9b4350()->f28]>=6)
							list.push_back((*gx_grid_cfd44c.at(x,y))->getEntity45d250());
				if(list.empty())break;
				int maxCount=scale7/50+1;
				gx_shuffle9d9fc0(list);
				for(unsigned i=1;i<list.size();i++)
					if(gx_map_cefc4c->f4631f0(list[i]))gx_moveElement9da1f0(list,i,0);
				int armed=0;
				for(int i=0;i<list.size()&&i<maxCount;i++)
				{
					GxWL<int> kinds;
					kinds.add(0,80);
					kinds.add(1,20);
					int tmpTries=scale7/40+1;
					for(int t=0;t<tmpTries;t++)
					{
						if(kinds.empty9b81b0())break;
						int kindB=kinds.pick();
						GxItems*invTmp=&list[i]->getInventoryList45ab00();
						GxItems gN;
						GxDefList choices;
						GxHI bC;
						GxDef*b8=0;
						switch(kindB)
						{
						case 0:
							for(unsigned j=0;j<invTmp->size();j++)
								if((*invTmp)[j]->getType44aec0()==3)gN.push_back((*invTmp)[j]);
							if(gN.empty())
							{
								kinds.remove9bab80(kindB);
								goto nextKind;
							}
							gx_shuffle9d9fc0(gN);
							for(unsigned j=0;j<gN.size();j++)
							{
								choices.clear();
								for(unsigned k=0;k<gx_defs_d2d1c4.size();k++)
									if(gx_defs_d2d1c4[k]->f44==gN[j]->f457880()&&gx_defs_d2d1c4[k]->f54&&gx_defs_d2d1c4[k]->f457130()==gN[j]->f457920()+2)
										choices.push_back(gx_defs_d2d1c4[k]);
								if(!choices.empty())
								{
									b8=gx_randomRec9d5d00(choices);
									bC=gN[j];
									break;
								}
							}
							break;
						case 1:
							choices.clear();
							for(unsigned k=0;k<gx_defs_d2d1c4.size();k++)
								if(gx_defs_d2d1c4[k]->f40==0x23&&gx_defs_d2d1c4[k]->f50<=gx_gd_d1e860.f46f4e0()+2)
									choices.push_back(gx_defs_d2d1c4[k]);
							if(!choices.empty())b8=gx_randomRec9d5d00(choices);
							break;
						}
						if(b8)
						{
							GxHE target=list[i];
							armed++;
							if(armed==1)GX_MSG(0x2b7,&string("X0-1V1: \"What are these fools even fielding?\""),GxHE(),&aG);
							GxDef*oldDef=0;
							string oldName;
							if(bC.valid())
							{
								oldDef=bC->info9b4350();
								oldName=bC->getName571db0(0,0);
								bC->remove57dbe0(1,0,1,1);
							}
							int copies=oldDef?gx_maxInt9cdb60(1,oldDef->f4c/b8->f4c):1;
							GxHI tmpGiven;
							for(int c=0;c<copies;c++)tmpGiven=gx_map_cefc4c->f6c51d0(b8,target,1,0);
							if(b8->f40!=0x23&&b8->f110>oldDef->f110)
								for(unsigned k=0;k<gx_defs_d2d1c4.size();k++)
									if(gx_defs_d2d1c4[k]->f40==0x23&&gx_defs_d2d1c4[k]->f0f0==1)
									{
										gx_map_cefc4c->f6c51d0(gx_defs_d2d1c4[k],target,1,0);
										break;
									}
							if(gx_map_cefc4c->f4631f0(target)&&tmpGiven.valid())
							{
								string line=target->name416f40()+" ";
								if(oldDef)line+=oldName+" replaced by "+tmpGiven->getName571db0(0,0);
								else line+="owns a shiny new "+tmpGiven->getName571db0(0,0);
								if(copies>1)line+=" (x"+gx_intToString4051f0(copies)+").";
								else line+=".";
								GX_MSG(0x320,&line,GxHE(),0);
								showXomAct6bdb50(1,target,0);
							}
						}
nextKind:;
					}
				}
				if(armed)a_=true;
			}
			break;
		case 20:
			{
				GxHEs targets;
				if(!findXomTargets6bdcd0(targets))break;
				int bonus=scale7/40+1;
				GxWL<int> weapons;
				for(unsigned i=0;i<gx_defs_d2d1c4.size();i++)
					if(gx_defs_d2d1c4[i]->f230)
						weapons.add(i,gx_tbl_ba3acc[gx_defs_d2d1c4[i]->f230]*(gx_defs_d2d1c4[i]->f230==1?bonus:1));
				for(unsigned i=0;i<targets.size();i++)
					for(unsigned j=0;j<targets[i]->points45d1a0()->size();j++)
					{
						GxPoint fromVal;
						GxPath pathB;
						GxDefList a;
						GxDefList b;
						int pad5[1];
						if(gx_map_cefc4c->f7170a0(player,(*targets[i]->points45d1a0())[j],pathB,a,b,fromVal,0,4,1,1))
						{
							GxPoint target((*targets[i]->points45d1a0())[j]);
							GxPoint origin=player->f5c80f0(target);
							int dist=gx_distanceCeil40a3f0(origin,target);
							GxDef*weapon1=0;
							GxWL<int> pool(weapons);
							while(!pool.empty9b81b0())
							{
								weapon1=gx_defs_d2d1c4[pool.pick()];
								if(weapon1->f100-1>=dist)break;
								else
								{
									pool.remove9bab80(weapon1->id);
									weapon1=0;
								}
							}
							if(weapon1==0)continue;
							GxPath pts6;
							GxPath pts27;
							gx_f651590(weapon1,origin,target,pts6,pts27);
							for(unsigned k=0;k<pts6.size();k++)
								gx_owner_cefc50->new508610()->init503b20(gx_owner_cefc50,weapon1->f190,pts6[k],gx_d2e20c,&pts27[k],&fromVal,new GxProj(weapon1,player,1,weapon1->f100,1.0f,GxHE(),GxHE(),0,GxHE(),0,0,0),9,0);
							string hit(" X0-1V1 ranged attack (100%) Hit");
							do{if(gx_showMessage5111e0(0x2c0,&hit,0,0,player,GxHE(),0,true))gx_bubble_cec058->bubble8758d0(false);gx_log_cec0c4->scrollToEnd7b4f10();}while(false);
							tmpExtra="X0-1V1 uses you as a vessel of destruction.";
							a_=true;
							goto smiteDone;
						}
					}
smiteDone:;
			}
			break;
		case 21:
			{
				GxHEs targets;
				if(!findXomTargets6bdcd0(targets))break;
				GxHE victimA=targets.front();
				GxPoint range(gx_minInt9cdb30(1,gx_gd_d1e860.f46f4e0()-2),gx_maxInt9cdb60(gx_gd_d1e860.f46f4e0()+2,10));
				range.f40bf50(scale7/40);
				gx_clampMax9cf5a0(&range.x,9);
				gx_clampMax9cf5a0(&range.y,10);
				GxWL<int> pool;
				for(unsigned i=0;i<gx_expl_cfd2cc.size();i++)
					if(range.contains40c190(gx_expl_cfd2cc[i]->f6c))pool.add(i,gx_tbl_ba3acc[gx_expl_cfd2cc[i]->f70]);
				if(pool.empty9b81b0())break;
				GxPoint curPos=victimA->f45a4c0();
				int dist=gx_distanceCeil40a3f0(curPos,gx_map_cefc4c->getPlayer4630f0()->getPosition45a4a0());
				GxExplDef*ex=0;
				while(!pool.empty9b81b0())
				{
					ex=gx_expl_cfd2cc[pool.pick()];
					if(ex->f3c>=dist)break;
					else
					{
						pool.remove9bab80(ex->id);
						ex=0;
					}
				}
				if(ex==0)continue;
				gx_map_cefc4c->addRecord777a20(gx_factory_cefaa8->createA7930e0(new GxExplosion(GxHE(),ex,curPos,GxHE(),GxPoint(-1),GxPoint(-1))));
				string hit(" X0-1V1 explosive smite attack (100%) Hit");
				do{if(gx_showMessage5111e0(0x2c0,&hit,0,0,player,GxHE(),0,true))gx_bubble_cec058->bubble8758d0(false);gx_log_cec0c4->scrollToEnd7b4f10();}while(false);
				tmpExtra="X0-1V1: \"Fire in the hole!\"";
				a_=true;
			}
			break;
		case 22:case 23:
			{
				GxHEs targets;
				if(!findXomTargets6bdcd0(targets))break;
				for(unsigned i=0;i<targets.size();i++)
					if(targets[i]->f45ac40(0x13))gx_eraseStep9d6440(targets,i);
				if(targets.empty())break;
				switch(act)
				{
				case 22:
					{
						GxHE i8=targets[gx_clamp9cdc80(0,(100-scale7)*(targets.size()-1)/100,targets.size()-1)];
						bool loud=rng.chance(scale7/2);
						if(loud)
						{
							GX_MSG(0x2b7,&string("X0-1V1 twists the quantum threads just so."),GxHE(),&aG);
							do{if(gx_showMessage5111e0(player->f45aaa0(i8)?0xba:0xbb,0,0,0,i8,GxHE(),0,false))gx_bubble_cec058->bubble8758d0(true);gx_log_cec0b4->scrollToEnd7b4f10();}while(false);
							i8->f6335e0();
						}
						else tmpExtra="X0-1V1: \"One less obstacle for my toy on its journey to the highest levels of glorious entertainment.\"";
						i8->die633790(0,10,GxHE(),1,0,0,0,0);
					}
					break;
				case 23:
					{
						GxHE victim;
						while(true)
						{
							victim=targets[gx_clamp9cdc80(0,(100-scale7)*(targets.size()-1)/100,targets.size()-1)];
							if(victim->getSize45a360()==1)
							{
								GxPath aD;
								gx_getAdjacentCells4fab80(victim->getPosition45a4a0(),aD);
								int blocked=0;
								for(unsigned k=0;k<aD.size();k++)
									if(!(*gx_grid_cfd44c.atPoint(aD[k]))->isPassableFor66ab30(GxHE()))blocked++;
								if(blocked>1)
								{
									gx_removeEntity9d2f00(targets,victim);
									victim.reset9b7270();
								}
							}
							else
							{
								GxPath cells;
								victim->f5c89d0(cells);
								for(unsigned k=0;k<cells.size();k++)
									if(!(*gx_grid_cfd44c.atPoint(cells[k]))->isPassableFor66ab30(GxHE()))
									{
										gx_removeEntity9d2f00(targets,victim);
										victim.reset9b7270();
										break;
									}
							}
							if(victim.valid()||targets.empty())break;
						}
						if(victim.isNull())break;
						GX_MSG(0x2b7,&string("X0-1V1: \"I find this area lacking in decorations.\""),GxHE(),&aG);
						string line=victim->name416f40()+" shuts down.";
						GX_MSG(0x320,&line,GxHE(),0);
						showXomAct6bdb50(1,victim,0);
						victim->f5fd900(8,0);
						victim->removeEffectsA639730(0);
						victim->f45b070(victim->name416f40()+" Statue");
					}
					break;
				}
				a_=true;
			}
			break;
		case 25:case 26:case 27:
			{
				GxHEs targets;
				if(!findXomTargets6bdcd0(targets))break;
				for(unsigned i=0;i<targets.size();i++)
					if(!targets[i]->getAiType45a2a0())gx_eraseStep9d6440(targets,i);
				if(targets.empty())break;
				switch(act)
				{
				case 25:
					{
						GX_MSG(0x2b7,&string("X0-1V1 imagines sitting ducks."),GxHE(),&aG);
						int count=scale7/25+1;
						gx_shuffle9d9fc0(targets);
						for(int i=0;i<targets.size()&&i<count;i++)
						{
							string line=targets[i]->name416f40()+" suddenly freezes.";
							GX_MSG(0x320,&line,GxHE(),0);
							showXomAct6bdb50(1,targets[i],0);
							int turns=rng.rangeInt(20,30);
							gx_queue_d225a0.f672b80(targets[i],turns*100);
						}
						a_=true;
					}
					break;
				case 26:
					{
						GX_MSG(0x2b7,&string("X0-1V1 stares into the ether."),GxHE(),&aG);
						int count=scale7/25+1;
						gx_shuffle9d9fc0(targets);
						GxPoint range6(30,50);
						bool far=rng.chance(scale7/2);
						for(int i=0;i<targets.size()&&i<count;i++)
						{
							GxHE j4=targets[i];
							GxPoint aP(j4->getPosition45a4a0());
							bool moved=placeEntityNear6bd410(range6,0,j4,far,1);
							if(moved)showShift6bd6d0(aP,j4);
						}
						a_=true;
					}
					break;
				case 27:
					if(targets.size()==1)break;
					if(targets.size()==2)GX_MSG(0x2b7,&string("X0-1V1: \"I sense a duel!\""),GxHE(),&aG);
					else GX_MSG(0x2b7,&string("X0-1V1: \"A civil war? On my watch? More likely than you'd think.\""),GxHE(),&aG);
					for(unsigned i=0;i<targets.size();i++)
						if(targets[i]->ai45b590())targets[i]->ai45b590()->f5b5220();
					for(unsigned i=0;i<targets.size()/2;i++)
					{
						GxHE k5=targets[i];
						int group=k5->getGroup45a3f0()->f9b4350();
						k5->f5fdab0();
						k5->removeEffectsA639730(0);
						k5->f5dcc70(2,1);
						showXomAct6bdb50(1,k5,0);
						string line="X0-1V1 tampers with "+k5->name416f40()+" IFF filter.";
						GX_MSG(0x2b7,&line,GxHE(),&aG);
						GxGoal*goal3=k5->ai45b590()->f4590f0()->f57f140(new GxXGroup(0x42));
						goal3->f4=gx_map_cefc4c->getTurn464270()+10+scale7/8;
						goal3->v8.push_back(GxPoint(group));
					}
					do{gx_logPhrase5141b0(0xa2,0,0,0,GxHE(),0);}while(false);
					a_=true;
					break;
				}
			}
			break;
		case 28:
			{
				if(!player->f5c98c0(1,0x4b,0))break;
				GxPoint range(0x4b,100);
				GxPoint dest;
				if(!f69f580(dest,range,0x19))break;
				GxPoint start5(player->getPosition45a4a0());
				int hops8=scale7/30+2;
				int dist=gx_distanceCeil40a3f0(start5,dest);
				int step3=dist/(hops8+1);
				if(step3<5)hops8=0;
				GxPath route0;
				for(int h=0;h<hops8;h++)
				{
					GxFPair fp;
					gx_pointAlongLine4066e0(start5.x,start5.y,dest.x,dest.y,(h+1)*step3,&fp.x,&fp.y);
					GxArea area;
					gx_grid_cfd44c.getRect9b4430(GxPoint(fp.x,fp.y),10,area);
					for(int t=0;t<50;t++)
					{
						GxPoint p=area.randomPoint40be90();
						if((*gx_grid_cfd44c.atPoint(p))->canPlace66ad20(1))
						{
							route0.push_back(p);
							break;
						}
					}
				}
				route0.push_back(dest);
				for(int k=0;k<route0.size();k++)
				{
					if(k<(int)route0.size()-2)player->f5ddac0(dest,1);
					else f69fa80(route0[k]);
				}
				GxRecord*a3;
				if(gx_lookup9d7980("Xom_Appear",&a3))
					gx_owner_cefc50->new508610()->init503b20(gx_owner_cefc50,a3,gx_map_cefc4c->getPlayer4630f0()->getPosition45a4a0(),gx_d2e20c,0,0,0,9,0);
				tmpExtra="X0-1V1: \"You need a change of scenery.\"";
				aG=player->getPosition45a4a0();
				gx_cec138->f9666d0();
				do{gx_logPhrase5141b0(0xa3,0,0,0,GxHE(),0);}while(false);
				a_=true;
			}
			break;
		case 29:
			if(player->f45a9d0())
			{
				int amount4=scale7*40/100+10;
				int before=player->f45a9d0();
				player->f44e2c0(gx_maxInt9cdb60(0,player->f45a9d0()-amount4));
				tmpExtra="X0-1V1 lends a hand with your twisted circuits (-"+gx_intToString4051f0(before-player->f45a9d0())+" system corruption).";
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 30:
			{
				int cleared=0;
				for(unsigned i=0;i<player->getInventoryList45ab00().size();i++)
					if(player->getInventoryList45ab00()[i]->f457dd0())
					{
						player->getInventoryList45ab00()[i]->f458460();
						cleared++;
					}
				if(cleared)
				{
					gx_inv_cec08c->reopen8a2ce0(4,GxHE());
					tmpExtra="X0-1V1 blesses "+gx_intToString4051f0(cleared)+" of your inventory parts (corruption cleared).";
					showXomAct6bdb50(1,player,0);
					a_=true;
				}
			}
			break;
		case 32:
			if(sightAmt==0)
			{
				bool big=rng.chance(scale7);
				if(big)
				{
					sightAmt=rng.rangeInt(4,6);
					sightEnd=rng.rangeInt(150,300)+turn;
					tmpExtra="X0-1V1: \"Watch where you're going!\" ("+gx_intToStringSigned405560(sightAmt)+" sight range)";
				}
				else
				{
					sightAmt=rng.rangeInt(2,3);
					sightEnd=rng.rangeInt(250,400)+turn;
					tmpExtra="X0-1V1 makes important surrounding features appear closer to you ("+gx_intToStringSigned405560(sightAmt)+" sight range).";
				}
				gx_cf4960+=sightAmt;
				gx_map_cefc4c->f72e4c0(player,1);
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 33:
			if(ecapAmt==0)
			{
				ecapAmt=scale7*7/100*100+800;
				ecapEnd=rng.rangeInt(800,1300)+turn;
				tmpExtra="X0-1V1: \"Let the electrons flow!\" ("+gx_intToStringSigned405560(ecapAmt)+" energy capacity)";
				gx_cf4970+=ecapAmt;
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 34:
			if(mcapAmt==0)
			{
				mcapAmt=scale7*4/100*100+400;
				mcapEnd=rng.rangeInt(1000,1500)+turn;
				tmpExtra="X0-1V1 causes your matter storage to temporarily balloon in size. ("+gx_intToStringSigned405560(mcapAmt)+" matter capacity)";
				gx_cf4974+=mcapAmt;
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 35:
			if(rangedAmt)break;
			goto curse;
		case 36:
			if(meleeAmt)break;
			goto curse;
		case 37:
			if(sightAmt)break;
			goto curse;
		case 38:
			if(ecapAmt)break;
			goto curse;
		case 39:
			if(mcapAmt)break;
			goto curse;
		case 40:
			goto curse;
		case 41:
			goto curse;
		case 42:
			if(resistAmt)break;
			goto curse;
		case 43:
			if(energyAmt)break;
			goto curse;
		case 44:
			if(heatAmt)break;
			goto curse;
		case 46:
			goto curse;
		case 45:
			if(slotAmt)break;
curse:
			{
				if(gx_loc_d1e888==f144||gx_cf462c==5)break;
				int amount6=0;
				int cost=0;
				int type=10;
				switch(act)
				{
				case 35:case 36:
					amount6=gx_minInt9cdb30(scale7/20+5,10);
					cost=amount6*10;
					break;
				case 37:
					amount6=gx_minInt9cdb30(scale7/50+1,2);
					cost=amount6*150;
					break;
				case 38:
					amount6=gx_minInt9cdb30(scale7/20+2,6)*100;
					cost=amount6/2;
					break;
				case 39:
					amount6=gx_minInt9cdb30(scale7/20+2,6)*100;
					cost=amount6/2;
					break;
				case 40:
					amount6=gx_minInt9cdb30(scale7/50+1,2);
					cost=amount6*100;
					break;
				case 41:
					amount6=gx_minInt9cdb30(scale7/10+6,16);
					cost=(amount6-6)*10+200;
					break;
				case 42:
					{
						GxIntVec2 types;
						types.push_back(0);
						types.push_back(1);
						types.push_back(3);
						types.push_back(2);
						type=gx_randomRec9d5d00(types);
						amount6=-gx_minInt9cdb30(gx_resist_cf4984[type],scale7/34*5+10);
						cost=(abs(amount6)-10)/5*50+100;
					}
					break;
				case 43:
					amount6=scale7/34*5+10;
					cost=amount6*10;
					break;
				case 44:
					amount6=scale7/26*5+15;
					cost=(amount6-15)*5+75;
					break;
				case 45:
					if(player->getSlotTotal45a860()>=26)break;
					amount6=rng.rangeInt(0,3);
					cost=0;
					break;
				case 46:
					amount6=scale7/22*50+200;
					cost=0;
					break;
				}
				if(!amount6)break;
				if(cost)
				{
					int maxCore=player->info9b4350()->f1dc+(gx_gd_d1e860.f46f4e0()-1)*150;
					if(player->f5ca260()-cost<maxCore/2)break;
					gx_cf4954-=cost;
					if(player->f490840()>player->f5ca260())player->f5dea60(player->f5ca260(),0);
					tmpExtra="X0-1V1: \"Any self-respecting god will have their pound of flesh.\" (permanent "+gx_intToStringSigned405560(-cost)+" core integrity, ";
				}
				switch(act)
				{
				case 35:
					{
						gx_cf4958+=amount6;
						tmpExtra+=gx_intToStringSigned405560(amount6)+"% ranged accuracy)";
						string phrase=gx_intToStringSigned405560(amount6)+"%; "+gx_intToStringSigned405560(-cost)+" max core";
						do{gx_logPhrase5141b0(0xa4,&string("Ranged accuracy"),&phrase,0,GxHE(),0);}while(false);
					}
					break;
				case 36:
					{
						gx_cf4958+=amount6;
						tmpExtra+=gx_intToStringSigned405560(amount6)+"% melee accuracy)";
						string phrase=gx_intToStringSigned405560(amount6)+"%; "+gx_intToStringSigned405560(-cost)+" max core";
						do{gx_logPhrase5141b0(0xa4,&string("Melee accuracy"),&phrase,0,GxHE(),0);}while(false);
					}
					break;
				case 37:
					{
						gx_cf4960+=amount6;
						gx_map_cefc4c->f72e4c0(player,1);
						tmpExtra+=gx_intToStringSigned405560(amount6)+" sight range)";
						string phrase=gx_intToStringSigned405560(amount6)+"; "+gx_intToStringSigned405560(-cost)+" max core";
						do{gx_logPhrase5141b0(0xa4,&string("Sight range"),&phrase,0,GxHE(),0);}while(false);
					}
					break;
				case 38:
					{
						gx_cf4970+=amount6;
						tmpExtra+=gx_intToStringSigned405560(amount6)+" energy capacity)";
						string phrase=gx_intToStringSigned405560(amount6)+"; "+gx_intToStringSigned405560(-cost)+" max core";
						do{gx_logPhrase5141b0(0xa4,&string("Energy capacity"),&phrase,0,GxHE(),0);}while(false);
					}
					break;
				case 39:
					{
						gx_cf4974+=amount6;
						tmpExtra+=gx_intToStringSigned405560(amount6)+" matter capacity)";
						string phrase=gx_intToStringSigned405560(amount6)+"; "+gx_intToStringSigned405560(-cost)+" max core";
						do{gx_logPhrase5141b0(0xa4,&string("Matter capacity"),&phrase,0,GxHE(),0);}while(false);
					}
					break;
				case 40:
					{
						gx_cf496c+=amount6;
						gx_inv_cec08c->reopen8a2ce0(4,GxHE());
						tmpExtra+=gx_intToStringSigned405560(amount6)+" inventory capacity)";
						string phrase=gx_intToStringSigned405560(amount6)+"; "+gx_intToStringSigned405560(-cost)+" max core";
						do{gx_logPhrase5141b0(0xa4,&string("Inventory capacity"),&phrase,0,GxHE(),0);}while(false);
					}
					break;
				case 41:
					{
						gx_cf4978+=amount6;
						tmpExtra+=gx_intToStringSigned405560(amount6)+" mass support)";
						string phrase=gx_intToStringSigned405560(amount6)+"; "+gx_intToStringSigned405560(-cost)+" max core";
						do{gx_logPhrase5141b0(0xa4,&string("Mass support"),&phrase,0,GxHE(),0);}while(false);
					}
					break;
				case 42:
					{
						gx_resist_cf4984[type]+=amount6;
						tmpExtra+=gx_intToStringSigned405560(-amount6)+"% "+gx_resistNames_d323f8[type]+" resistance)";
						string phrase=gx_intToStringSigned405560(-amount6)+"%; "+gx_intToStringSigned405560(-cost)+" max core";
						do{gx_logPhrase5141b0(0xa4,&(gx_resistNames_d323f8[type]+" resistance"),&phrase,0,GxHE(),0);}while(false);
					}
					break;
				case 43:
					{
						gx_cf49d8+=amount6;
						tmpExtra+=gx_intToStringSigned405560(amount6)+" energy generation)";
						string phrase=gx_intToStringSigned405560(amount6)+"; "+gx_intToStringSigned405560(-cost)+" max core";
						do{gx_logPhrase5141b0(0xa4,&string("Energy generation"),&phrase,0,GxHE(),0);}while(false);
					}
					break;
				case 44:
					{
						gx_cf49dc+=amount6;
						tmpExtra+=gx_intToStringSigned405560(amount6)+" heat dissipation)";
						string phrase=gx_intToStringSigned405560(amount6)+"; "+gx_intToStringSigned405560(-cost)+" max core";
						do{gx_logPhrase5141b0(0xa4,&string("Heat dissipation"),&phrase,0,GxHE(),0);}while(false);
					}
					break;
				case 45:
					player->f5c94e0(amount6,GxHE());
					tmpExtra="X0-1V1: \"If I've learned anything from roguelikes, it's that more appendages equals more fun.\" (permanent +1 "+gx_slotNames_d378d0[amount6]+" slot)";
					do{gx_logPhrase5141b0(0xa4,&(gx_slotNames_d378d0[amount6]+" slot count"),&gx_intToStringSigned405560(1),0,GxHE(),0);}while(false);
					if(player->f448fe0(3)>=7)gx_player_cf45d8.f77fbc0(0x8b);
					break;
				case 46:
					gx_cf4954+=amount6;
					player->f5de870(amount6,0);
					tmpExtra="X0-1V1: \"Even if you take a beating, with so many spare parts around there is always hope your cute little core will rise from the ashes to exact glorious revenge.\" (permanent "+gx_intToStringSigned405560(amount6)+" core integrity)";
					do{gx_logPhrase5141b0(0xa4,&string("Core integrity"),&gx_intToStringSigned405560(amount6),0,GxHE(),0);}while(false);
					break;
				}
				until=-1;
				f140++;
				if(f140==3)
					for(int a=35;a<=46;a++)vb4[a]=-1;
				f144=gx_loc_d1e888;
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 47:
			if(f194)break;
			{
				int w;
				GxDef*def2=0;
				GxPoint range(gx_minInt9cdb30(9,gx_gd_d1e860.f46f4e0()+scale7/40-1));
				int base8=range.x;
				if(range.x>2)range.x--;
				if(range.y<10)range.y++;
				if(range.x>8)range.x=8;
				gx_clampMin9cf5c0(&range.x,2);
				gx_clampMin9cf5c0(&range.y,2);
				GxWL<int> pool6;
				GxIntVec2 slots;
				player->f5c93d0(slots);
				GxItems*aS=&player->getInventoryList45ab00();
				for(unsigned i=0;i<gx_defs_d2d1c4.size();i++)
					if(gx_defs_d2d1c4[i]->f224&&range.contains40c190(gx_defs_d2d1c4[i]->f50))
					{
						w=gx_tbl_ba3acc[gx_defs_d2d1c4[i]->f224];
						if(w)
						{
							if(gx_defs_d2d1c4[i]->f50!=base8)w/=2;
							if(gx_defs_d2d1c4[i]->f48<4&&slots[gx_defs_d2d1c4[i]->f48])w*=2;
							for(unsigned j=0;j<aS->size();j++)
								if((*aS)[j]->f457820()==i)w/=(*aS)[j]->getType44aec0()<=3?4:2;
							pool6.add(i,w);
						}
					}
				GxWL<int> kind0;
				kind0.add(0,0x60);
				kind0.add(1,2);
				if(!f158)kind0.add(2,2);
				switch(kind0.pick())
				{
				case 0:
					do def2=gx_defs_d2d1c4[pool6.pick()];
					while(def2->f0f0==0xb7&&(gx_gd_d1e860.f46f550(8)||f159));
					if(def2->f0f0==0xb7)f159=true;
					break;
				case 1:
					for(unsigned i=0;i<gx_defs_d2d1c4.size();i++)
						if(gx_defs_d2d1c4[i]->f44==3)
						{
							def2=gx_defs_d2d1c4[i];
							break;
						}
					break;
				case 2:
					gx_findDef9d7a40(gx_defs_d2d1c4,"Sfc. Transmogrifier",&def2);
					break;
				}
				if(def2->f0f0==0xbc)
				{
					if(f69fc60(0,tmpExtra))
					{
						showXomAct6bdb50(1,player,0);
						a_=true;
					}
					break;
				}
				int count;
				switch(def2->f44)
				{
				case 5:count=rng.rangeInt(1,5);break;
				case 9:count=rng.rangeInt(1,2);break;
				case 10:count=rng.rangeInt(2,3);break;
				case 11:count=rng.rangeInt(2,3);break;
				case 12:count=rng.rangeInt(2,3);break;
				case 13:count=rng.rangeInt(2,3);break;
				case 20:count=rng.rangeInt(1,2);break;
				case 22:count=rng.rangeInt(1,2);break;
				default:count=1;
				}
				if(def2->f50<base8)count++;
				if(def2->f54==0&&def2->f44!=5)count=1;
				bool myEquipped=false;
				GxItems pGot;
				string c7;
				while(count)
				{
					if(def2->f48<4&&player->f5c92e0(def2->f48)>=def2->f4c&&!gx_inRange9daf80(0x7e,def2->f0f0,0x93))
					{
						GxHI item=gx_map_cefc4c->f6c51d0(def2,player,1,0);
						if(item.valid())
						{
							gx_cf47cc.push_back(item->f9fcd80());
							gx_gm_d25628.addItemAttachCount778560(item->f457820(),1,0);
							if(player->f5dc680(item)&&!player->f5cd220(item))
							{
								GxPart*part=gx_parts_cec088->f894e70(item);
								if(part)gx_parts_cec088->toggle8993e0(part,0);
							}
							pGot.push_back(item);
							myEquipped=true;
						}
					}
					else if(player->f5ca210()>=def2->f4c)
					{
						GxItems spares;
						if(player->f5cb830(spares))
						{
							gx_shuffle9d9fc0(spares);
							if(!pGot.empty())
								for(unsigned k=0;k<spares.size()-1;k++)
									if(gx_containsEntity9d31e0(pGot,spares[k]))gx_moveElement9da1f0(spares,k,spares.size()-1);
							while(player->f45a810()<def2->f4c)
							{
								gx_view_cec054->items8119c0(spares.front(),1,0,1);
								if(!c7.empty())c7+=", ";
								c7+=spares.front()->getName571db0(0,0);
								renameJunkItem6bd1a0(spares.front());
								player->f642940(spares.front(),1,1,0,0);
								gx_eraseAt9da940(spares,0);
							}
						}
						GxHI item9=gx_map_cefc4c->f6c51d0(def2,player,0,0);
						if(item9.valid())
						{
							if(item9->f4578a0()==5)
							{
								gx_cf47cc.push_back(item9->f9fcd80());
								gx_gm_d25628.addItemAttachCount778560(item9->f457820(),1,0);
							}
							if(item9->f457880()==3)item9->f450460(gx_gd_d1e860.f46f4e0()*10+scale7);
							gx_inv_cec08c->reopen8a2ce0(5,item9);
							pGot.push_back(item9);
						}
					}
					else if((*gx_grid_cfd44c.atPoint(player->getPosition45a4a0()))->f45d7b0()||(*gx_grid_cfd44c.atPoint(player->getPosition45a4a0()))->getItem45d8f0().valid()&&gx_map_cefc4c->f71ef30(player->getPosition45a4a0(),1))
					{
						GxHI item=gx_map_cefc4c->f6c5400(def2,player->getPosition45a4a0());
						if(item.valid())
						{
							if(item->f457880()==3)item->f450460(gx_gd_d1e860.f46f4e0()*10+scale7);
							pGot.push_back(item);
						}
					}
					count--;
				}
				if(!c7.empty())GX_MSG(0x2bb,&c7,player,0);
				bool myUpgraded=false;
				for(unsigned i=0;i<pGot.size();i++)
				{
					if(!pGot[i].operator->())gx_eraseStep9d6440(pGot,i);
					else if(!myUpgraded&&pGot[i]->getType44aec0()==4)
					{
						myUpgraded=true;
						if(rng.chance(50))
						{
							GxStrVec*names=0;
							GxIntVec2*used=0;
							if(rng.chance(75)||pGot[i]->f4578a0()==5)
							{
								if(gx_containsRecord9db330(gx_d25598[4],0))
								{
									names=&gx_d204ec[4];
									used=&gx_d25598[4];
								}
							}
							else if(gx_containsRecord9db330(gx_d25598[pGot[i]->f4578a0()],0))
							{
								names=&gx_d204ec[pGot[i]->f4578a0()];
								used=&gx_d25598[pGot[i]->f4578a0()];
							}
							if(names)
							{
								GxIntVec2 free;
								for(int k=0;k<names->size();k++)
									if(used->at9b9230(k)==0)free.push_back(k);
								if(!free.empty())
								{
									int pick=gx_randomRec9d5d00(free);
									used->at9b9230(pick)=1;
									pGot[i]->f458700((*names)[pick]);
									gx_inv_cec08c->reopen8a2ce0(5,pGot[i]);
								}
							}
						}
					}
				}
				if(!pGot.empty())
				{
					gx_player_cf45d8.f77ffb0(def2->id,0);
					tmpExtra="X0-1V1 smiles upon you. (Received "+pGot.front()->getName571db0(0,0);
					if(pGot.size()>1)tmpExtra+=" x"+gx_intToString4051f0(pGot.size())+")";
					else tmpExtra+=")";
					if(myEquipped)showXomAct6bdb50(1,player,0);
					else showXomAct6bdb50(1,GxHE(),&player->getPosition45a4a0());
					a_=true;
				}
			}
			break;
		case 48:
			if(!player->f5d26e0(0xd3))break;
			else
			{
				bool nG=false;
				GxPoint range(gx_gd_d1e860.f46f4e0()-1,gx_gd_d1e860.f46f4e0()+3);
				gx_clampMax9cf5a0(&range.x,8);
				gx_clampMax9cf5a0(&range.y,9);
				OpR5h_WL<int> pools[4];
				for(unsigned i=0;i<gx_defs_d2d1c4.size();i++)
					if(gx_defs_d2d1c4[i]->f24c&&gx_defs_d2d1c4[i]->f54&&range.contains40c190(gx_defs_d2d1c4[i]->f50))
						pools[gx_defs_d2d1c4[i]->f48].add((int)gx_defs_d2d1c4[i],gx_defs_d2d1c4[i]->f54==0?5:(gx_defs_d2d1c4[i]->f94?10:100));
				for(int s=0;s<4;s++)
				{
					if(pools[s].empty9b81b0())continue;
					int n=gx_cf4a58[s].size()/2+(gx_tbl_ba3bf8[s]-gx_cf4a58[s].size());
					for(int k=0;k<n;k++)
					{
						GxDef*pick=(GxDef*)pools[s].pick();
						gx_cf4a58[s].push_back(pick->id);
						if(gx_cf4a58[s].size()>gx_tbl_ba3bf8[s])gx_removeElement9de6f0(gx_cf4a58[s],0);
						nG=true;
					}
				}
				if(nG)
				{
					tmpExtra=rng.chance(50)?"X0-1V1: \"I love subatomizers!\"":"X0-1V1: \"Subatomizers go!\"";
					gx_sound4541b0(0xf2,0,0);
					gx_cf4a68=gx_map_cefc4c->getTurn464270();
					gx_view_cec054->f49abf0();
					showXomAct6bdb50(1,player,0);
					a_=true;
				}
			}
			break;
		case 49:
			if(gx_cf4a14.empty())break;
			else
			{
				int level=gx_player_cf45d8.f46e150();
				level=99;
				GxWL<int> pool3;
				for(int r=3;r<19;r++)
					if((!gx_cf4a04[r]||gx_cf4a04[r]<gx_tbl_b98958[r])&&level>=gx_tbl_b98900[r])pool3.add(r,gx_tbl_b988a8[r]);
				if(pool3.empty9b81b0())break;
				else
				{
					string msg("A floating RIF Installer appears for a brief moment.");
					GX_MSG(0x2b7,&msg,GxHE(),&aG);
					int rif=pool3.pick();
					gx_player_cf45d8.installRIF780f30(rif);
					until=-1;
					showXomAct6bdb50(1,player,0);
					a_=true;
				}
			}
			break;
		case 50:
			if(!player->f5d2a00(0x7c))break;
			else
			{
				GxWL<GxHI> parts;
				GxItems*inv=&player->getInventoryList45ab00();
				for(unsigned i=0;i<inv->size();i++)
					if((*inv)[i]->f457f90()==0x7c&&(*inv)[i]->f457d70()&&(*inv)[i]->getType44aec0()<=3&&(*inv)[i]->f45cb30()<99)
						parts.add((*inv)[i],(*inv)[i]->f45cb30());
				if(parts.empty9b81b0())break;
				else
				{
					GxHI part=parts.pick();
					gx_player_cf45d8.f77ffb0(part->f457820(),0);
					tmpExtra="X0-1V1 flashes the "+part->getName571db0(0,0)+" buffer.";
					part->f44fc60(99);
					gx_parts_cec088->f896a80(part);
					until=-2;
					showXomAct6bdb50(1,player,0);
					a_=true;
				}
			}
			break;
		case 51:
			if(sensorEnd||veilEnd||gx_cf4a00)break;
			else
			{
				string msg("Suggestive images of robots vie for attention in your data streams.");
				GX_MSG(0x2b7,&msg,GxHE(),&aG);
				msg="X0-1V1: \"Enjoy your XOMVISION!\"";
				GX_MSG(0x2b7,&msg,GxHE(),&aG);
				sensorEnd=turn+scale7*2+125;
				gx_map_cefc4c->f720470(0);
				gx_view_cec054->v7();
				do{gx_logPhrase5141b0(0xa5,0,0,0,GxHE(),0);}while(false);
				showXomAct6bdb50(1,player,0);
				a_=true;
			}
			break;
		case 52:
			{
				GxExitList candidates;
				GxIntVec2 dists;
				GxExitList*exits5=gx_map_cefc4c->exits462e10();
				for(unsigned i=0;i<exits5->size();i++)
					if(!(*exits5)[i]->fd&&(*exits5)[i]->h14.isNull()&&(*exits5)[i]->h18.isNull())
					{
						candidates.push_back((*exits5)[i]);
						dists.push_back(gx_distanceCeil40a3f0(player->getPosition45a4a0(),(*exits5)[i]->pos));
					}
				if(candidates.empty())break;
				GxExit*exitC;
				if(candidates.size()==1)exitC=candidates.front();
				else
				{
					GxWL<GxExit*> pool0;
					int lo3=gx_minOf9d7290(dists);
					int hi=gx_maxOf9d4340(dists);
					for(unsigned i=0;i<candidates.size();i++)
						pool0.add(candidates[i],gx_maxInt9cdb60(10,hi-lo3+(dists[i]-lo3)));
					exitC=pool0.pick();
				}
				string msg("X0-1V1: \"I guarantee there's even more fun over that way.");
				if(exitC->h8->depth==6)msg+=" Space? A sequel? Who knows!";
				msg+="\"";
				GX_MSG(0x2b7,&msg,GxHE(),&aG);
				gx_map_cefc4c->announceMachine71dd30(exitC->h8);
				gx_map_cefc4c->f4647a0(exitC->pos,1);
				exitC->fd=true;
				exitC->setLabel6c16d0("REVEALED");
				gx_view_cec054->labelAccess80e3a0(1,exitC);
				do{gx_logPhrase5141b0(0xa6,&exitC->h8->getText46ed40(),0,0,GxHE(),0);}while(false);
				a_=true;
			}
			break;
		case 53:
			{
				GxIntGrid*a5=gx_map_cefc4c->f463830();
				GxGrid34*g34=gx_map_cefc4c->f463e70();
				int radius=scale7/10+20;
				GxArea area;
				gx_grid_cfd44c.getRect9b4430(player->getPosition45a4a0(),radius,area);
				GxPath found2;
				for(int x=area.a;x<=area.c;x++)
					for(int y=area.b;y<=area.d;y++)
						if(!*a5->at(x,y)&&(*gx_grid_cfd44c.at(x,y))->getItem45d8f0().valid()&&(*gx_grid_cfd44c.at(x,y))->getItem45d8f0()->f457880()>=6&&g34->at9d2c30(x,y)->f10==gx_caf164&&g34->at9d2c30(x,y)->f24==gx_caf15c)
							found2.push_back(GxPoint(x,y));
				if(found2.empty())break;
				for(unsigned i=0;i<found2.size();i++)
				{
					gx_map_cefc4c->f4647a0(found2[i],0);
					gx_view_cec054->addMemoryLabel812950(found2[i],6);
				}
				tmpExtra="X0-1V1 points here and there ("+gx_countString407a80(found2.size(),"item location")+" revealed).";
				a_=true;
			}
			break;
		case 54:
			{
				GxIntGrid*seen7=gx_map_cefc4c->f463830();
				GxGrid34*g34=gx_map_cefc4c->f463e70();
				int radius=scale7/10+20;
				GxArea area;
				gx_grid_cfd44c.getRect9b4430(player->getPosition45a4a0(),radius,area);
				GxPath found6;
				for(int x=area.a;x<=area.c;x++)
					for(int y=area.b;y<=area.d;y++)
						if((*gx_grid_cfd44c.at(x,y))->isEdge45dc30()&&(*gx_grid_cfd44c.at(x,y))->isShortcut45dc50()&&!gx_map_cefc4c->f463e90(GxPoint(x,y)))
							found6.push_back(GxPoint(x,y));
				if(found6.empty())break;
				for(unsigned i=0;i<found6.size();i++)
				{
					gx_map_cefc4c->f734d60(found6[i]);
					gx_map_cefc4c->f4647a0(found6[i],1);
					gx_view_cec054->labelAccess80e3a0(1,found6[i]);
				}
				tmpExtra="X0-1V1: \"I found some blueprints, how convenient!\" ("+gx_countString407a80(found6.size(),"emergency access location")+" revealed).";
				a_=true;
			}
			break;
		case 55:
			{
				GxExit*bestTmp=0;
				int bestDist7=9999;
				GxExitList*exits=gx_map_cefc4c->exits462e10();
				for(unsigned i=0;i<exits->size();i++)
					if((*exits)[i]->h14.valid())
					{
						int d=gx_distanceCeil40a3f0(player->getPosition45a4a0(),(*exits)[i]->pos);
						if(d<bestDist7)bestTmp=(*exits)[i];
					}
				if(!bestTmp||!bestTmp->h14.operator->()||gx_map_cefc4c->f463160(bestTmp->h14->f4184d0())||gx_map_cefc4c->f463ee0(0,bestTmp->h14->f4184d0()))break;
				GxPoint pos(bestTmp->h14->f4184d0());
				GxMarkers*list=&(*gx_map_cefc4c->f463ec0())[0];
				list->push_back(gx_factory_cefaa8->createC793190());
				list->back()->f6c20b0(0,pos,(*gx_grid_cfd44c.atPoint(pos))->getProp45d550()->getDef9b8f00()->f0f8);
				gx_mission_cec034->f987de0();
				tmpExtra="X0-1V1: \"I sense action potential over that way (Garrison Access located).\"";
				a_=true;
			}
			break;
		case 56:
			if(!gx_gd_d1e860.f46f4b0(1)||gx_loc_d1e888->depth==13||gx_loc_d1e888->depth==12||gx_loc_d1e888->depth==14||gx_loc_d1e888->depth==0x22||gx_loc_d1e888->depth==0x23||gx_loc_d1e888==gx_d1ebd8||gx_loc_d1e888==gx_d1ebe0)break;
			{
				int slept=0;
				GxHGs*groups1=gx_map_cefc4c->f463950();
				for(unsigned i=0;i<groups1->size();i++)
					if(!gx_map_cefc4c->f4638e0((*groups1)[i]->f9b4350(),0))
					{
						GxHEs*members=(*groups1)[i]->members416f40();
						for(unsigned j=0;j<members->size();j++)
							if(!(*members)[j]->getTarget45a760()&&(*members)[j]->getAiType45a2a0()&&!(*members)[j]->getInventory45ad90())
							{
								(*members)[j]->ai45b590()->f5b5220();
								(*members)[j]->f5fd900(2,0);
								slept++;
							}
					}
				if(!slept)break;
				wakeEnd=turn+scale7*2+500;
				tmpExtra="X0-1V1: \"They're sleeping, time to make a run for it!\"";
				do{gx_logPhrase5141b0(0xbd,0,0,0,GxHE(),0);}while(false);
				until=-2;
				a_=true;
			}
			break;
		case 57:
			{
				GxHE target=gx_map_cefc4c->f727ef0();
				if(target.valid())
				{
					tmpExtra="X0-1V1: \"I told that "+target->name416f40()+" to go sit in the corner.\"";
					a_=true;
				}
			}
			break;
		case 58:
			{
				GxIntVec2 picks;
				for(int i=0;i<gx_cf6478.size();i++)
					if(gx_inRange9daf80(4,gx_cf6478[i]->f0,7)&&!gx_cf6478[i]->f45e820()&&!gx_cf6478[i]->e->ai45b590()->f458fb0(player))
						picks.push_back(i);
				if(picks.empty())break;
				GxOwnerRec*rec=gx_cf6478[gx_randomRec9d5d00(picks)];
				gx_overmind_cf6428.f68cd80(rec);
				switch(rec->f0)
				{
				case 4:tmpExtra="X0-1V1: \"I've sent the detectives back to the station. For now.\"";break;
				case 5:tmpExtra="X0-1V1 adds a dash of confusion to 0b10's systems.";break;
				case 6:tmpExtra="X0-1V1 sends the all clear message.";break;
				case 7:tmpExtra="X0-1V1: \"Assault is a crime, you know!\"";break;
				}
				tmpExtra+=" ("+gx_squadNames_d2f350[rec->f0]+" recalled)";
				a_=true;
			}
			break;
		case 59:
			{
				GxPath*doors=gx_map_cefc4c->f463ad0();
				GxIntVec2*kinds=gx_map_cefc4c->f463af0();
				GxHP prop4;
				int opened=0;
				bool remove3;
				for(unsigned i=0;i<doors->size();i++)
					if(gx_map_cefc4c->isVisible4631c0((*doors)[i]))
					{
						prop4=(*gx_grid_cfd44c.atPoint((*doors)[i]))->getProp45d550();
						remove3=false;
						if(prop4.isNull()||!prop4->f45cb30()||prop4->f457b10())remove3=true;
						else
						{
							GxLock*lock=prop4->f45cb30()->f45c1c0(5);
							if(!lock&&(*kinds)[i]==0x27)remove3=true;
							else
							{
								GxPath pts;
								if(!gx_collectProps517ae0(prop4->f44ab40(),pts,0,2,0))remove3=true;
								else
								{
									if(lock)lock->f8=true;
									string line="X0-1V1 opens "+(*gx_grid_cfd44c.atPoint(pts.front()))->getProp45d550()->getName45c5b0()+".";
									GX_MSG(0x2b7,&line,GxHE(),&aG);
									do{gx_logPhrase5141b0(0xa7,&(*gx_grid_cfd44c.atPoint(pts.front()))->getProp45d550()->getName45c5b0(),0,0,GxHE(),0);}while(false);
									gx_sound454260(pts.front(),0x7e);
									GxRecord*link;
									if(gx_lookup9d7980("P_Machine_Door_Open",&link))
										for(unsigned k=0;k<pts.size();k++)
										{
											if(gx_map_cefc4c->isVisible4631c0(pts[k]))gx_owner_cefc50->new508610()->init503b20(gx_owner_cefc50,link,pts[k],gx_d2e20c,0,0,0,9,0);
											(*gx_grid_cfd44c.atPoint(pts[k]))->getProp45d550()->f45ce10(1,0,1,GxHE());
										}
									remove3=true;
									opened++;
								}
							}
						}
						if(remove3)
						{
							gx_eraseAt9d5190(*doors,i);
							gx_eraseAt9ce6d0(*kinds,i);
						}
					}
				if(opened)
				{
					tmpExtra="X0-1V1: \"'Every door you open is another chance for more unexpected chaos.' --some infamous god.\"";
					a_=true;
				}
			}
			break;
		case 60:
			if(gx_loc_d1e888->depth!=13||gx_map_cefc4c->f464900())break;
			{
				GxIntVec2 picks;
				for(int i=0;i<gx_d31640.size();i++)
					if(!gx_d31640[i].empty()&&gx_d31640[i][0]->f45c590()=="GAR_Generator")picks.push_back(i);
				if(picks.empty())break;
				f160=true;
				GxHP gen=gx_randomRecord9dafb0(gx_d31640[gx_randomRec9d5d00(picks)]);
				do{gx_logPhrase5141b0(0xa8,&gen->getName45c5b0(),0,0,GxHE(),0);}while(false);
				gen->f45ce10(0,1,0,GxHE());
				tmpExtra="X0-1V1: \"Oops.\"";
				a_=true;
			}
			break;
		case 61:
			if(gx_stats_d2c658.f472c90(0x260))break;
			{
				GxIntVec2 picks;
				for(int i=0;i<gx_d31640.size();i++)
					if(!gx_d31640[i].empty()&&gx_d31640[i][0]->f45c590()=="Energy Cycler")picks.push_back(i);
				if(picks.empty())break;
				GX_MSG(0x2b7,&string("X0-1V1: \"Open sesame.\""),GxHE(),&aG);
				f161=true;
				GxHP cycler=gx_randomRecord9dafb0(gx_d31640[gx_randomRec9d5d00(picks)]);
				do{gx_logPhrase5141b0(0xa8,&cycler->getName45c5b0(),0,0,GxHE(),0);}while(false);
				cycler->f45ce10(0,1,0,GxHE());
				a_=true;
			}
			break;
		case 62:
			if(gx_loc_d1e888->depth!=0x1b||gx_stringToInt405610(gx_gd_d1e860.getEntryText46f6d0("hubNetworkHubDisabled_g")))break;
			{
				GxIntVec2 picks;
				for(int i=0;i<gx_d31640.size();i++)
					if(!gx_d31640[i].empty()&&gx_d31640[i][0]->f45c590()=="HUB_Network_Hub")picks.push_back(i);
				if(picks.empty())break;
				f162=true;
				GxHP hub=gx_randomRecord9dafb0(gx_d31640[gx_randomRec9d5d00(picks)]);
				do{gx_logPhrase5141b0(0xa8,&hub->getName45c5b0(),0,0,GxHE(),0);}while(false);
				hub->f45ce10(0,1,0,GxHE());
				tmpExtra="X0-1V1: \"I bet that was expensive.\"";
				a_=true;
			}
			break;
		case 63:
			if(!gx_loc_d1e888->inRange46ecb0()||gx_map_cefc4c->f4642d0()>200)break;
			f163=true;
			gx_map_cefc4c->f74bec0(player->getPosition45a4a0());
			tmpExtra="X0-1V1: \"Have you ever seen what subatomizers do to 0b10?\"";
			do{gx_logPhrase5141b0(0xa9,0,0,0,GxHE(),0);}while(false);
			until=-1;
			a_=true;
			break;
		case 64:
			if(!gx_tbl_b903c0[gx_loc_d1e888->depth]||gx_cf6470||gx_loc_d1e888==gx_d1ebd8||gx_loc_d1e888==gx_d1ebe0)break;
			f164=0;
			f168=rng.rangeInt(100,200)+turn;
			tmpExtra="X0-1V1: \"Let's see how everyone fares in the upcoming heat wave.\"";
			do{gx_logPhrase5141b0(0xaa,0,0,0,GxHE(),0);}while(false);
			until=-1;
			a_=true;
			break;
		case 65:
			if(f16c.a==-1||gx_distanceCeil40a3f0(player->getPosition45a4a0(),f16c.center40b620())<=15||f194)break;
			{
				bool occupied=false;
				for(int x=f16c.a;x<=f16c.c&&!occupied;x++)
					for(int y=f16c.b;y<=f16c.d&&!occupied;y++)
						if((*gx_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&(*gx_grid_cfd44c.at(x,y))->getEntity45d250()->isXomCandidate5d51a0())occupied=true;
				if(occupied)break;
				for(int x=f16c.a;x<=f16c.c&&!occupied;x++)
					for(int y=f16c.b;y<=f16c.d&&!occupied;y++)
						if((*gx_grid_cfd44c.at(x,y))->getEntity45d250().valid())(*gx_grid_cfd44c.at(x,y))->getEntity45d250()->f637bb0();
				GxPoint tmpCenter=f16c.center40b620();
				GxWL<int> b3;
				b3.add(0,50);
				b3.add(1,50);
				switch(b3.pick())
				{
				case 0:
					{
						int count=scale7/40+3;
						GxPoint range_(gx_gd_d1e860.f46f4e0());
						if(range_.x>8)range_.x=8;
						gx_clampMin9cf5c0(&range_.x,1);
						gx_clampMin9cf5c0(&range_.y,1);
						GxWL<int> pool;
						for(unsigned i=0;i<gx_ents_d25de0.size();i++)
							if(gx_ents_d25de0[i]->f124&&gx_ents_d25de0[i]->f24==1)
							{
								if(range_.contains40c190(gx_ents_d25de0[i]->f68))pool.add(i,gx_tbl_ba3acc[gx_ents_d25de0[i]->f124]);
								else if(gx_ents_d25de0[i]->f68==range_.y+1)pool.add(i,gx_tbl_ba3acc[gx_ents_d25de0[i]->f124]/4);
							}
						GxEntityDef*def=gx_ents_d25de0[pool.pick()];
						for(int n=0;n<count;n++)
							for(int t=0;t<20;t++)
							{
								GxPoint p=f16c.randomPoint40be90();
								if(p.f409bd0(tmpCenter)&&gx_map_cefc4c->findPlaceableNear71c150(p,p,def->f9c))
								{
									GxHE e=gx_map_cefc4c->placeEntity6c58c0(def,p,1,0,0x22,0xe,0);
									if(e.valid())
									{
										e->f639530(0x3a,1);
										e->f45b2a0();
										break;
									}
								}
							}
						tmpExtra=rng.chance(50)?"X0-1V1: \"I think they like you.\"":"X0-1V1: \"Being a leader is both a boon and a curse.\"";
					}
					break;
				case 1:
					{
						int w;
						GxPoint range(gx_minInt9cdb30(9,gx_gd_d1e860.f46f4e0()+1));
						int base1=range.x;
						if(range.x>2)range.x--;
						if(range.y<10)range.y++;
						if(range.x>8)range.x=8;
						gx_clampMin9cf5c0(&range.x,2);
						gx_clampMin9cf5c0(&range.y,2);
						GxWL<int> pool;
						for(unsigned i=0;i<gx_defs_d2d1c4.size();i++)
							if(gx_defs_d2d1c4[i]->f224&&range.contains40c190(gx_defs_d2d1c4[i]->f50))
							{
								w=gx_tbl_ba3acc[gx_defs_d2d1c4[i]->f224];
								if(w)
								{
									if(gx_defs_d2d1c4[i]->f50!=base1)w/=2;
									pool.add(i,w);
								}
							}
						int count=scale7/10+10;
						for(int n=0;n<count;n++)
						{
							GxDef*def=gx_defs_d2d1c4[pool.pick()];
							for(int t=0;t<20;t++)
							{
								GxPoint p=f16c.randomPoint40be90();
								if(gx_map_cefc4c->f71bc10(p,p))
								{
									gx_map_cefc4c->f6c5400(def,p);
									break;
								}
							}
						}
						tmpExtra=rng.chance(50)?"X0-1V1: \"Just some junk I've been collecting.\"":"X0-1V1: \"Someone left a few trinkets here.\"";
					}
					break;
				}
				f69fa80(tmpCenter);
				GxRecord*link;
				if(gx_lookup9d7980("Xom_Appear",&link))
					gx_owner_cefc50->new508610()->init503b20(gx_owner_cefc50,link,gx_map_cefc4c->getPlayer4630f0()->getPosition45a4a0(),gx_d2e20c,0,0,0,9,0);
				aG=player->getPosition45a4a0();
				gx_cec138->f9666d0();
				do{gx_logPhrase5141b0(0xac,0,0,0,GxHE(),0);}while(false);
				until=-2;
				a_=true;
			}
			break;
		case 66:
			if(ecapAmt)break;
			if(gx_inRange9d4c40(20,player->f45a8f0(),80))
			{
				int pct=scale7*25/100+25;
				int amt=player->f45a8d0()*pct/100;
				int pDrain=gx_minInt9cdb30(player->f45a8d0(),amt);
				player->f45b1b0(pDrain);
				tmpExtra="X0-1V1: \"How much energy does one bot need, really?\" (-"+gx_intToString4051f0(pDrain)+" energy)";
				if(rng.chance(scale7/2))
				{
					bool unuseds=false;
					GxItems*inv=&player->getInventoryList45ab00();
					for(unsigned i=0;i<inv->size();i++)
						if((*inv)[i]->f457f90()==8&&(*inv)[i]->f45cb30()>0)
						{
							amt=(*inv)[i]->f45cb30()*(pct/2)/100;
							(*inv)[i]->f44fc60(gx_maxInt9cdb60(0,(*inv)[i]->f45cb30()-amt));
							gx_inv_cec08c->f8a54c0((*inv)[i],1);
						}
				}
				showXomAct6bdb50(0,player,0);
				a_=true;
			}
			break;
		case 67:
			if(heatAmt||player->f45a990()>=gx_b960ec)break;
			{
				int heat=gx_gd_d1e860.f46f4e0()*10+scale7+200;
				player->f45b210(heat);
				tmpExtra="X0-1V1 wants to heat up the action around here (+"+gx_intToString4051f0(heat)+" heat).";
				showXomAct6bdb50(0,player,0);
				a_=true;
			}
			break;
		case 68:
			if(heatAmt||player->f45a990()>=gx_b960f0)break;
			heatAmt=-gx_minInt9cdb30(gx_cf49dc,rng.rangeInt(15,25)+gx_gd_d1e860.f46f4e0()*2);
			heatEnd=turn+5+scale7/10;
			tmpExtra="X0-1V1: \"Your inner air conditioner seems to have fallen into disrepair.\" ("+gx_intToStringSigned405560(heatAmt)+" heat dissipation)";
			gx_cf49dc+=heatAmt;
			showXomAct6bdb50(0,player,0);
			a_=true;
			break;
		case 69:
			if(rangedAmt==0&&player->f5d5b20().valid())
			{
				bool big=rng.chance(scale7);
				if(big)
				{
					rangedAmt=-rng.rangeInt(10,20);
					rangedEnd=rng.rangeInt(50,150)+turn;
					tmpExtra="X0-1V1: \"So many nails, never enough hammers...\" ("+gx_intToStringSigned405560(rangedAmt)+"% ranged accuracy)";
				}
				else
				{
					rangedAmt=-rng.rangeInt(5,10);
					rangedEnd=rng.rangeInt(100,300)+turn;
					tmpExtra="X0-1V1: \"There's a penalty for shooting from the hip 'round these parts.\" ("+gx_intToStringSigned405560(rangedAmt)+"% ranged accuracy)";
				}
				gx_cf4958+=rangedAmt;
				showXomAct6bdb50(0,player,0);
				a_=true;
			}
			break;
		case 70:
			if(meleeAmt==0&&player->f5d5c30().valid())
			{
				bool big=rng.chance(scale7);
				if(big)
				{
					meleeAmt=-rng.rangeInt(10,20);
					meleeEnd=rng.rangeInt(50,150)+turn;
					tmpExtra="X0-1V1 projects screaming human faces on all surfaces in the area ("+gx_intToStringSigned405560(meleeAmt)+"% melee accuracy).";
				}
				else
				{
					meleeAmt=-rng.rangeInt(5,10);
					meleeEnd=rng.rangeInt(100,300)+turn;
					tmpExtra="X0-1V1: \"Dakka mode, ENGAGE!\" ("+gx_intToStringSigned405560(meleeAmt)+"% melee accuracy)";
				}
				gx_cf495c+=meleeAmt;
				showXomAct6bdb50(0,player,0);
				a_=true;
			}
			break;
		case 71:
			if(f194)break;
			{
				GxItems parts;
				if(player->f5cb8b0(parts))
				{
					for(unsigned i=0;i<parts.size();i++)
						if(parts[i]->info9b4350()->f1ac||parts[i]->getEffect457b70(0x6e)||parts[i]->getEffect457b70(0x6c)||parts[i]->f457f90()==7||parts[i]->f457f90()==8||parts[i]->f457f90()==9||parts[i]->f577fb0())
							gx_eraseStep9d6440(parts,i);
					if(!parts.empty())
					{
						string dropped;
						GX_MSG(0x2b9,&string("X0-1V1: \"And it's a trip and a fumble!\""),GxHE(),&aG);
						for(int n=scale7/75+1;n>0&&!parts.empty();n--)
						{
							GxHI item=gx_popRandom9d8030(parts);
							if(!dropped.empty())dropped+=", ";
							dropped+=item->getName571db0(0,0);
							if(!item->hasName4579d0()&&rng.chance(5))item->f458700(string("of clumsiness"));
							player->f642940(item,1,1,0,4);
						}
						if(!dropped.empty())GX_MSG(0x2bb,&dropped,player,0);
						showXomAct6bdb50(0,player,0);
						a_=true;
					}
				}
			}
			break;
		case 72:
			{
				GxHEs visible;
				player->f5c8880(visible);
				bool found9=false;
				for(unsigned i=0;i<visible.size();i++)
					if(visible[i]->isHostileTo45aa70(player)&&!visible[i]->getTarget45a760())
					{
						found9=true;
						break;
					}
				if(!found9)break;
				GxItems spares;
				player->f5cb830(spares);
				found9=false;
				for(unsigned i=0;i<spares.size();i++)
					if(!spares[i]->f4578a0()&&spares[i]->f457d70()&&spares[i]->nested4578c0()<=player->f448fe0(0))
					{
						found9=true;
						break;
					}
				if(!found9)break;
				GxItems nW;
				GxItems*inv=&player->getInventoryList45ab00();
				for(unsigned i=0;i<inv->size();i++)
					if(!(*inv)[i]->getType44aec0()&&(*inv)[i]->f457cf0())nW.push_back((*inv)[i]);
				if(nW.empty())break;
				GxHI wN=gx_randomRecord9dafb0(nW);
				GX_MSG(0x2b9,&string("X0-1V1: \"School them in the art of offensive power!\""),GxHE(),&aG);
				GxExplDef*theEx=wN->info9b4350()->f1a8;
				GX_MSG(0x1a5,&wN->getName571db0(0,0),GxHE(),&aG);
				wN->remove57dbe0(1,1,1,1);
				gx_map_cefc4c->addRecord777a20(gx_factory_cefaa8->createA7930e0(new GxExplosion(GxHE(),theEx,aG,GxHE(),GxPoint(-1),GxPoint(-1))));
				a_=true;
			}
			break;
		case 75:
			{
				GxHEs victims;
				GxHEs found5;
				bool tracked=false;
				if(findXomTargets6bdcd0(found5))
					for(unsigned i=0;i<found5.size();i++)
						if(found5[i]->getFaction45a2c0()!=11&&!found5[i]->f45ac40(0x3a))
						{
							victims.push_back(found5[i]);
							if(found5[i]->f45af90()==player)tracked=true;
						}
				if(victims.empty()||!tracked)break;
				int count3=0;
				GxPropDef*trap=0;
				for(unsigned i=0;i<victims.size();i++)
				{
					GxPoint pos(victims[i]->getPosition45a4a0());
					if((*gx_grid_cfd44c.atPoint(pos))->f45d6a0()&&(trap||gx_findPropDef9d7710(gx_propDefs_cf35b0,"Stasis Trap",&trap))&&gx_map_cefc4c->placeProp6c67b0(trap,pos,-1,3,100))
					{
						count3++;
						if(count3==1)GX_MSG(0x2b9,&string("Vines of energy appear to reach up from the ground."),GxHE(),&aG);
						string line=victims[i]->name416f40()+" caught in stasis.";
						GX_MSG(0x320,&line,GxHE(),0);
						(*gx_grid_cfd44c.atPoint(pos))->f66ce10(0,0,0,1);
						showXomAct6bdb50(0,GxHE(),&pos);
					}
				}
				if(count3)a_=true;
			}
			break;
		case 76:
			{
				GxHEs ns;
				GxHEs b4;
				if(findXomTargets6bdcd0(b4))
					for(unsigned i=0;i<b4.size();i++)
						if(b4[i]->getAiType45a2a0()&&b4[i]->getFaction45a2c0()!=10&&b4[i]->getFaction45a2c0()!=11&&!b4[i]->f45ac40(0x3a)&&gx_tbl_bba058[b4[i]->info9b4350()->f28]>=6)
							ns.push_back(b4[i]);
				if(ns.empty())break;
				int maxCount=scale7/30+2;
				gx_shuffle9d9fc0(ns);
				int upgraded=0;
				for(int i=0;i<ns.size()&&i<maxCount;i++)
				{
					GxItems*inv=&ns[i]->getInventoryList45ab00();
					GxItems pK;
					for(unsigned j=0;j<inv->size();j++)
						if((*inv)[j]->getType44aec0()==3)pK.push_back((*inv)[j]);
					for(unsigned j=0;j<pK.size();j++)
						if(pK[j]->f457920()<9)
						{
							GxDefList choices;
							for(unsigned k=0;k<gx_defs_d2d1c4.size();k++)
								if(gx_defs_d2d1c4[k]->f44==pK[j]->f457880()&&gx_defs_d2d1c4[k]->f220&&gx_defs_d2d1c4[k]->f457130()==pK[j]->f457920()+1)
									choices.push_back(gx_defs_d2d1c4[k]);
							if(!choices.empty())
							{
								upgraded++;
								if(upgraded==1)GX_MSG(0x2b9,&string("X0-1V1 feels inspired!"),GxHE(),&aG);
								GxDef*def=gx_randomRec9d5d00(choices);
								GxDef*oldDef=pK[j]->info9b4350();
								string oldName=pK[j]->getName571db0(0,0);
								pK[j]->remove57dbe0(1,0,1,1);
								int copies=gx_maxInt9cdb60(1,oldDef->f4c/def->f4c);
								GxHI c5;
								for(int c=0;c<copies;c++)c5=gx_map_cefc4c->f6c51d0(def,ns[i],1,0);
								if(gx_map_cefc4c->f4631f0(ns[i])&&c5.valid())
								{
									string line=ns[i]->name416f40()+" "+oldName+" replaced by "+c5->getName571db0(0,0);
									if(copies>1)line+=" (x"+gx_intToString4051f0(copies)+").";
									else line+=".";
									GX_MSG(0x320,&line,GxHE(),0);
									showXomAct6bdb50(0,ns[i],0);
								}
							}
						}
				}
				if(upgraded)a_=true;
			}
			break;
		case 77:
			{
				GxHEs targets;
				GxHEs found;
				if(findXomTargets6bdcd0(found))
					for(unsigned i=0;i<found.size();i++)
						if(found[i]->f5d5d40().valid()&&!found[i]->getTarget45a760())targets.push_back(found[i]);
				if(targets.empty())break;
				gx_shuffle9d9fc0(targets);
				GxPath spotsX;
				for(unsigned i=0;i<targets.size();i++)
				{
					spotsX.clear9b3560();
					targets[i]->f5c8b10(spotsX,player);
					if(!spotsX.empty())
					{
					GxPoint best(-1);
					float vBestDist;
					float d;
					for(unsigned k=0;k<spotsX.size();k++)
						if(gx_map_cefc4c->f4633c0(spotsX[k]))
						{
							d=gx_distance40a450(player->getPosition45a4a0(),spotsX[k]);
							if(best.x==-1||d<vBestDist)
							{
								best=spotsX[k];
								vBestDist=d;
							}
						}
					if(best.x!=-1)
					{
					f69fa80(best);
					GxRecord*link;
					if(gx_lookup9d7980("Xom_Appear",&link))
						gx_owner_cefc50->new508610()->init503b20(gx_owner_cefc50,link,gx_map_cefc4c->getPlayer4630f0()->getPosition45a4a0(),gx_d2e20c,0,0,0,9,0);
					tmpExtra=rng.chance(50)?"X0-1V1: \"Fight!\"":"X0-1V1: \"Draw!\"";
					aG=player->getPosition45a4a0();
					gx_cec138->f9666d0();
					gx_queue_d225a0.f6728c0(player);
					a_=true;
					break;
					}
					}
				}
			}
			break;
		case 78:case 79:
			{
				GxHEs group;
				if(act==78)
				{
					GxHEs candidates;
					GxHEs found;
					if(findXomTargets6bdcd0(found))
						for(unsigned i=0;i<found.size();i++)
							if(found[i]->getSize45a360()==1&&!found[i]->getTarget45a760())candidates.push_back(found[i]);
					if(candidates.empty())break;
					group.push_back(player);
					group.push_back(gx_randomRecord9dafb0(candidates));
				}
				else
				{
					GxArea area;
					int radius=16;
					gx_grid_cfd44c.getRect9b4430(player->getPosition45a4a0(),radius,area);
					for(int x=area.a;x<=area.c;x++)
						for(int y=area.b;y<=area.d;y++)
							if((*gx_grid_cfd44c.at(x,y))->getEntity45d250().valid()&&(*gx_grid_cfd44c.at(x,y))->getEntity45d250()->getSize45a360()==1&&(*gx_grid_cfd44c.at(x,y))->getEntity45d250()!=player&&!(*gx_grid_cfd44c.at(x,y))->getEntity45d250()->getInventory45ad90())
								group.push_back((*gx_grid_cfd44c.at(x,y))->getEntity45d250());
					if(group.empty())break;
					group.push_back(player);
					gx_shuffle9d9fc0(group);
				}
				GxPoint tmpTmp;
				for(unsigned i=0;i<group.size();i++)
					if(gx_map_cefc4c->findPlaceableNear71c150(group[i]->getPosition45a4a0(),tmpTmp,1))goto swap;
				break;
swap:
				GX_MSG(0x2b9,&string("X0-1V1: \"The ol' switcheroo!\""),GxHE(),&aG);
				GxPoint nFirst(group.front()->getPosition45a4a0());
				GxPoint cur;
				group.front()->changePos5dccb0(tmpTmp,1);
				gx_moveElement9da1f0(group,0,group.size()-1);
				for(unsigned i=0;i<group.size();i++)
				{
					cur=group[i]->getPosition45a4a0();
					group[i]->f5ddac0(nFirst,0);
					nFirst=cur;
				}
				for(unsigned i=0;i<group.size();i++)
					if(gx_map_cefc4c->f4631f0(group[i]))
					{
						string line=group[i]->isPlayer5c7600()?string("Form resolidifies at new position."):group[i]->name416f40()+" form resolidifies at new position.";
						GX_MSG(0x320,&line,GxHE(),0);
						GxRecord*link;
						if(gx_lookup9d7980("Xom_Appear",&link))
							gx_owner_cefc50->new508610()->init503b20(gx_owner_cefc50,link,group[i]->getPosition45a4a0(),gx_d2e20c,0,0,0,9,0);
					}
				aG=player->getPosition45a4a0();
				gx_cec138->f9666d0();
				a_=true;
			}
			break;
		case 80:
			if(moveEnd)break;
			moveEnd=turn+10+scale7/10;
			f180=false;
			tmpExtra="X0-1V1: \"I know that drunk sailor look when I see it.\"";
			showXomAct6bdb50(0,player,0);
			a_=true;
			break;
		case 81:
			if(gx_loc_d1e888->depth!=14||gx_cf6470||gx_cf6474)break;
			gx_cf6472=true;
			tmpExtra="X0-1V1: \"Hm... what does this button do?\"";
			a_=true;
			break;
		case 82:
			if(player->f5cab90()<75)
			{
				int amount2=scale7*18/100+2;
				int before=player->f45a9d0();
				player->f44e2c0(gx_minInt9cdb30(80,player->f45a9d0()+amount2));
				tmpExtra=amount2<=5?"X0-1V1: \"It's not much, but it's the thought that counts. (+"+gx_intToString4051f0(player->f45a9d0()-before)+" system corruption)\"":"X0-1V1 brushes you with a corrupting influence (+"+gx_intToString4051f0(player->f45a9d0()-before)+" system corruption).";
				showXomAct6bdb50(0,player,0);
				a_=true;
			}
			break;
		case 83:
			{
				int count=scale7/40+1;
				int nAlready=0;
				int total=0;
				GxItems parts;
				for(unsigned i=0;i<player->getInventoryList45ab00().size();i++)
					if(player->getInventoryList45ab00()[i]->getType44aec0()==4&&player->getInventoryList45ab00()[i]->f577990())
					{
						total++;
						if(player->getInventoryList45ab00()[i]->f457dd0())nAlready++;
						else parts.push_back(player->getInventoryList45ab00()[i]);
					}
				if(!parts.empty()&&nAlready<total/2)
				{
					gx_clampMax9cf5a0(&count,gx_minInt9cdb30(parts.size(),total/2-nAlready));
					gx_shuffle9d9fc0(parts);
					for(int k=0;k<count;k++)
					{
						parts[k]->f5798b0(rng.rangeInt(3,12));
						if(rng.chance(33))
							switch(rng.rangeInt(0,7))
							{
							case 0:parts[k]->f458700(string("a little corruption is good for you"));break;
							case 1:parts[k]->f458700(string("corrupt to the core"));break;
							case 2:parts[k]->f458700(string("wasn't me"));break;
							case 3:parts[k]->f458700(string("who would do such a thing?"));break;
							case 4:parts[k]->f458700(string("you weren't going to use it anyway"));break;
							case 5:parts[k]->f458700(string("corruption is one root of chaos"));break;
							case 6:parts[k]->f458700(string("corruption good"));break;
							case 7:parts[k]->f458700(string("tasty!"));break;
							}
					}
					gx_inv_cec08c->reopen8a2ce0(4,GxHE());
					tmpExtra="X0-1V1 curses "+gx_intToString4051f0(count)+" of your inventory parts (corrupted).";
					showXomAct6bdb50(1,player,0);
					a_=true;
				}
			}
			break;
		case 84:
			if(sightAmt==0)
			{
				bool big=rng.chance(scale7);
				if(big)
				{
					sightAmt=-rng.rangeInt(6,10);
					sightEnd=rng.rangeInt(50,150)+turn;
					tmpExtra="X0-1V1: \"In a world full of sensor tech, vision is overrated.\" ("+gx_intToStringSigned405560(sightAmt)+" sight range)";
				}
				else
				{
					sightAmt=-rng.rangeInt(2,4);
					sightEnd=rng.rangeInt(100,300)+turn;
					tmpExtra="X0-1V1 blurs the world around you ("+gx_intToStringSigned405560(sightAmt)+" sight range).";
				}
				gx_cf4960+=sightAmt;
				gx_map_cefc4c->f72e4c0(player,1);
				showXomAct6bdb50(0,player,0);
				a_=true;
			}
			break;
		case 85:
			if(mcapAmt==0)
			{
				mcapAmt=-gx_cf4974/2;
				mcapEnd=turn+scale7*4+200;
				tmpExtra="X0-1V1: \"Did you know you're leaking matter?\" ("+gx_intToStringSigned405560(mcapAmt)+" matter capacity)";
				gx_cf4974+=mcapAmt;
				player->f5e2b50();
				showXomAct6bdb50(0,player,0);
				a_=true;
			}
			break;
		case 86:
			{
				GxItems parts;
				if(player->f5cb8b0(parts))
				{
					int count=0;
					for(unsigned i=0;i<parts.size();i++)
						if(parts[i]->info9b4350()->f1ac||parts[i]->getEffect457b70(0x6e)||parts[i]->getEffect457b70(0x6c)||parts[i]->f457f90()==7)
							gx_eraseStep9d6440(parts,i);
					if(!parts.empty())
					{
						GxWL<GxHI> pool;
						for(unsigned i=0;i<parts.size();i++)
							pool.add(parts[i],parts[i]->f457af0()>=3?scale7/35+1:1);
						for(int n=(rng.chance(66)?1:0)+1;n>0&&!pool.empty9b81b0();n--)
						{
							if(++count==1)GX_MSG(0x2b9,&string("X0-1V1: \"Use it or lose it, I always say.\""),GxHE(),&aG);
							GxHI item=pool.pick();
							pool.remove9bab80(item);
							item->addEffect4585a0(new GxPoint(gx_d2f0f8[0x6e],1));
							GX_MSG(0x2bc,&item->getName571db0(0,0),player,0);
							GxPartList a0;
							if(gx_parts_cec088->findParts4a9a40(item,a0))
							{
								gx_parts_cec088->f89d610(item,0xb);
								for(unsigned j=0;j<a0.size();j++)
								{
									a0[j]->putChar4180b0(0,0,0x66);
									a0[j]->f890710(0);
								}
							}
						}
					}
					if(count)
					{
						showXomAct6bdb50(0,player,0);
						a_=true;
					}
				}
			}
			break;
		case 87:
			if(f194)break;
			{
				bool busy1=false;
				for(int i=0;i<4;i++)
					if(gx_parts_cec088->f898470(i))
					{
						busy1=true;
						break;
					}
				if(busy1)break;
				GxItems inv;
				player->f5cb8b0(inv);
				GxItems candsB;
				GxIntVec2 empty;
				GxIntVec2 full;
				for(int s=0;s<4;s++)
				{
					if((s!=0||v184[s]>0)&&v184[s]>-1&&player->f448fe0(s)>1)
					{
						if(player->f5c92e0(s))full.push_back(+s);
						else
						{
							unsigned before=candsB.size();
							for(unsigned i=0;i<inv.size();i++)
								if(inv[i]->f4578a0()==s&&!inv[i]->info9b4350()->f1ac&&!inv[i]->getEffect457b70(0x6e)&&!inv[i]->getEffect457b70(0x6c)&&inv[i]->f457f90()!=7&&!inv[i]->f577fb0())
									candsB.push_back(inv[i]);
							if(candsB.size()>before)full.push_back(+s);
						}
					}
					if(v184[s]<1)empty.push_back(+s);
				}
				if(full.empty()||empty.empty())break;
				if(full.size()>=2||empty.size()>=2||full.front()!=empty.front())
				{
					int pFrom,to;
					do
					{
						pFrom=gx_randomRec9d5d00(full);
						to=gx_randomRec9d5d00(empty);
					}
					while(to==pFrom);
					if(!player->f5c92e0(pFrom))
					{
						gx_shuffle9d9fc0(candsB);
						GxHI item;
						for(unsigned i=0;i<candsB.size();i++)
							if(candsB[i]->f4578a0()==pFrom&&candsB[i]->nested4578c0()==1)
							{
								item=candsB[i];
								break;
							}
						if(item.isNull())
							for(unsigned i=0;i<candsB.size();i++)
								if(candsB[i]->f4578a0()==pFrom&&candsB[i]->nested4578c0()!=1)
								{
									item=candsB[i];
									break;
								}
						if(item->f457e90())
						{
							GX_MSG(0x3c,&item->getName571db0(0,0),player,0);
							item->remove57dbe0(1,0,1,1);
						}
						else
						{
							gx_view_cec054->items8119c0(item,1,0,1);
							GX_MSG(0x2bb,&item->getName571db0(0,0),player,0);
							player->f642940(item,1,1,0,0);
						}
					}
					player->f5c9660(pFrom);
					player->f5c94e0(to,GxHE());
					v184[pFrom]--;
					v184[to]++;
					tmpExtra="X0-1V1: \"Evolution hits right when you least expect it.\" ("+gx_slotNames_d378d0[pFrom]+" slot mutated into "+gx_slotNames_d378d0[to]+" slot)";
					do{gx_logPhrase5141b0(0xad,&gx_slotNames_d378d0[pFrom],&gx_slotNames_d378d0[to],0,GxHE(),0);}while(false);
					if(player->f448fe0(3)>=7)gx_player_cf45d8.f77fbc0(0x8b);
					showXomAct6bdb50(0,player,0);
					a_=true;
				}
			}
			break;
		case 88:
			if(f194||gx_map_cefc4c->f4642d0()<=gx_map_cefc4c->f4645d0()+10)break;
			tmpExtra="X0-1V1: \"Your visage is terrifying!\"";
			f194=turn+scale7+125;
			do{gx_logPhrase5141b0(0xae,0,0,0,GxHE(),0);}while(false);
			showXomAct6bdb50(0,player,0);
			until=-2;
			a_=true;
			break;
		case 89:
			{
				int nearby2=gx_map_cefc4c->f715730(2);
				if(nearby2&&(act==16||rng.chance(nearby2*25)))break;
				if(gx_map_cefc4c->squad463890(1)->f45e3e0(0x3a)||gx_map_cefc4c->squad463890(2)->f45e3e0(0x3a))break;
				GxEntityDef*def=0;
				int count=0;
				GxPoint range(gx_gd_d1e860.f46f4e0()+scale7/50-1);
				if(range.x>8)range.x=8;
				gx_clampMin9cf5c0(&range.x,1);
				gx_clampMin9cf5c0(&range.y,1);
				GxWL<int> pool4;
				for(unsigned i=0;i<gx_ents_d25de0.size();i++)
					if(gx_ents_d25de0[i]->f12c)
					{
						if(range.contains40c190(gx_ents_d25de0[i]->f68))pool4.add(i,gx_tbl_ba3acc[gx_ents_d25de0[i]->f12c]);
						else if(gx_ents_d25de0[i]->f68==range.x-1)pool4.add(i,gx_tbl_ba3acc[gx_ents_d25de0[i]->f12c]/2);
					}
				def=gx_ents_d25de0[pool4.pick()];
				count=scale7/(100/(def->f134-def->f130+1))+def->f130;
				GxHE leader;
				int placed3=0;
				int radiusRef=player->f5c7d30();
				GxPoint pN;
				GxArea area;
				gx_grid_cfd44c.getRect9b4430(player->getPosition45a4a0(),radiusRef,area);
				const int tries6=300;
				for(int t=0;t<tries6;t++)
				{
					pN=area.randomPoint40be90();
					if(gx_map_cefc4c->f4633c0(pN)&&gx_map_cefc4c->findPlaceableNear71c150(pN,pN,def->f9c)&&gx_map_cefc4c->f4633c0(pN)&&(t>=150||gx_distanceCeil40a3f0(player->getPosition45a4a0(),pN)>=5)&&gx_map_cefc4c->f716940(player->getPosition45a4a0(),pN,0,0))
					{
						for(int k=0;k<count;k++)
						{
							GxHE e=gx_map_cefc4c->placeEntity6c58c0(def,pN,3,0,0x22,0xe,0);
							if(e.valid())
							{
								if(leader.valid())e->ai45b590()->setFollow5b2f80(leader,0);
								else leader=e;
								e->f639530(0x3a,1);
								if(++placed3==1)
								{
									string msg="X0-1V1: \""+string(rng.chance(50)?"C'mon, do something!\"":"Some new friends to play with.\"");
									GX_MSG(0x2b9,&msg,GxHE(),&aG);
								}
								if(gx_map_cefc4c->f4631f0(e))
								{
									string line=e->name416f40()+" form resolidifies at new position.";
									GX_MSG(0x320,&line,GxHE(),0);
									GxRecord*link;
									if(gx_lookup9d7980("Xom_Appear",&link))
										for(unsigned j=0;j<e->points45d1a0()->size();j++)
											gx_owner_cefc50->new508610()->init503b20(gx_owner_cefc50,link,(*e->points45d1a0())[j],gx_d2e20c,0,0,0,9,0);
								}
							}
						}
						break;
					}
				}
				if(placed3)
				{
					do{gx_logPhrase5141b0(0xb0,&def->f1ac,&gx_intToString4051f0(placed3),0,GxHE(),0);}while(false);
					a_=true;
				}
			}
			break;
		case 90:
			if(!gx_gd_d1e860.f46f4b0(1)||gx_loc_d1e888->depth==13||gx_loc_d1e888->depth==12||gx_loc_d1e888->depth==14||gx_loc_d1e888->depth==0x22||gx_loc_d1e888->depth==0x23)break;
			{
				bool active1=false;
				for(unsigned i=0;i<gx_cf6478.size();i++)
					if((gx_cf6478[i]->f0==5||gx_cf6478[i]->f0==7)&&gx_cf6478[i]->f8!=-2&&gx_cf6478[i]->fc)
					{
						active1=true;
						break;
					}
				if(active1)break;
				GxWL<int> kinds;
				kinds.add(4,0x4b);
				if(gx_b93738[gx_gd_d1e860.f46f4e0()].a)kinds.add(5,scale7);
				kinds.add(7,scale7/2);
				int nKind=kinds.pick();
				bool cC=false;
				switch(nKind)
				{
				case 4:
					cC=gx_overmind_cf6428.f684250(player->getPosition45a4a0(),1);
					break;
				case 5:
					cC=gx_overmind_cf6428.f685a10(player,0);
					break;
				case 7:
					cC=gx_overmind_cf6428.f687520(player,0,0);
					break;
				}
				if(!cC)break;
				GX_MSG(0x2b9,&string("X0-1V1 thinks 0b10 needs to up its game."),GxHE(),&aG);
				string alert="ALERT: Dispatching surplus targeted "+gx_squadNames_cf25d8[nKind]+" squad.";
				GX_ALERT_S(&alert,nKind==4?0x127:nKind==5?0x128:0x129);
				a_=true;
			}
			break;
		case 91:
			{
				int maxR5=gx_maxInt9cdb60(1,scale7/10);
				int depth=gx_gd_d1e860.f46f4e0();
				GxPoint rangeTmp(10,30);
				GxPoint destX;
				bool ok=false;
				for(int r=maxR5;r>=1;r-=2)
					if(f69f810(destX,rangeTmp,20,r,depth))
					{
						ok=true;
						break;
					}
				if(!ok)break;
				f69fa80(destX);
				GxRecord*link;
				if(gx_lookup9d7980("Xom_Appear",&link))
					gx_owner_cefc50->new508610()->init503b20(gx_owner_cefc50,link,gx_map_cefc4c->getPlayer4630f0()->getPosition45a4a0(),gx_d2e20c,0,0,0,9,0);
				tmpExtra="X0-1V1: \"Enjoy the ride!\"";
				aG=player->getPosition45a4a0();
				gx_cec138->f9666d0();
				do{gx_logPhrase5141b0(0xb1,0,0,0,GxHE(),0);}while(false);
				a_=true;
			}
			break;
		case 92:
			if(!gx_gd_d1e860.f46f4b0(1)||gx_loc_d1e888->depth==13||gx_loc_d1e888->depth==12||gx_loc_d1e888->depth==14||gx_loc_d1e888->depth==0x22||gx_loc_d1e888->depth==0x23)break;
			{
				int q3=25;
				int a8=8;
				GxPath aI;
				gx_view_cec054->f808510(player->getPosition45a4a0(),q3,aI);
				GxPoint start(-1);
				gx_shuffle9d7350(aI);
				for(unsigned i=0;i<aI.size();i++)
					if(gx_grid_cfd44c.contains9b43b0(aI[i])&&(*gx_grid_cfd44c.atPoint(aI[i]))->canPlace66ad20(1))
					{
						start=aI[i];
						break;
					}
				if(start.x==-1)break;
				GxEntityDef*def=gx_map_cefc4c->f6c5600(1,0x15,0,1);
				int boxesB=scale7/33+3;
				int stepN=360/boxesB;
				int placed=0;
				GxMarkers*pMarkers=&(*gx_map_cefc4c->f463ec0())[2];
				for(int b=0;b<boxesB;b++)
				{
					if(!gx_grid_cfd44c.contains9b43b0(start))break;
					GxArea area;
					gx_grid_cfd44c.getRect9b4430(start,a8,area);
					for(int t=0;t<100;t++)
					{
						GxPoint p=area.randomPoint40be90();
						if(gx_distanceCeil40a3f0(start,p)<=a8&&gx_map_cefc4c->findPlaceableNear71c150(p,p,def->f9c)&&!gx_map_cefc4c->isVisible4631c0(p)&&gx_map_cefc4c->f716940(p,gx_map_cefc4c->f4184d0(),0,0))
						{
							GxHE e=gx_map_cefc4c->placeEntity6c58c0(def,p,3,0,0x22,0xe,0);
							if(e.valid())
							{
								e->f639530(0x3a,1);
								placed++;
								pMarkers->push_back(gx_factory_cefaa8->createC793190());
								pMarkers->back()->f6c20b0(2,p,-1);
								GxPoint next;
								gx_rotatePoint501fc0(player->getPosition45a4a0(),start,(float)stepN,next);
								start=next;
								break;
							}
						}
					}
				}
				if(!placed)break;
				gx_mission_cec034->f987de0();
				tmpExtra="X0-1V1: \"A box. Just for you.\"";
				a_=true;
			}
			break;
		case 93:
			if(!gx_gd_d1e860.f46f4b0(1)||gx_loc_d1e888->depth==13||gx_loc_d1e888->depth==12||gx_loc_d1e888->depth==14||gx_loc_d1e888->depth==0x22||gx_loc_d1e888->depth==0x23)break;
			if(gx_loc_d1e888->depth==10||gx_loc_d1e888->depth==0x19||gx_loc_d1e888->f8>gx_tbl_ba65b4[gx_cf4718])break;
			{
				GxEntityDef*defs[3];
				gx_fill9e2be0(defs,3,0);
				unsigned iD=0;
				int n3=0;
				for(;iD<gx_ents_d25de0.size()&&n3<3;iD++)
					if(gx_ents_d25de0[iD]->f28==9&&gx_ents_d25de0[iD]->f24==1)defs[n3++]=gx_ents_d25de0[iD];
				GxPath terms;
				GxPathLists*lists8=gx_map_cefc4c->f459070();
				for(unsigned j=0;j<(*lists8)[0].size();j++)
					if((*gx_grid_cfd44c.atPoint((*lists8)[0][j]))->getProp45d550()->f45cb30()->h70.isNull()&&(*gx_grid_cfd44c.atPoint((*lists8)[0][j]))->getProp45d550()->getName45c5b0()=="Terminal"&&!(*gx_grid_cfd44c.atPoint((*lists8)[0][j]))->getProp45d550()->f45cb30()->f45c160(5,0)&&!(*gx_grid_cfd44c.atPoint((*lists8)[0][j]))->getProp45d550()->f45c9b0())
					{
						int level=(*gx_grid_cfd44c.atPoint((*lists8)[0][j]))->getProp45d550()->f45cb30()->fc;
						if(!level)continue;
						terms.push_back((*lists8)[0][j]);
					}
				if(terms.empty())break;
				gx_shuffle9d7350(terms);
				int count=gx_maxInt9cdb60(1,terms.size()/2)+terms.size()/2*scale7/100;
				gx_clampMax9cf5a0(&count,terms.size());
				int placed2=0;
				for(int t=0;t<count;t++)
				{
					int level=(*gx_grid_cfd44c.atPoint(terms[t]))->getProp45d550()->f45cb30()->fc;
					GxPoint at(terms[t]);
					for(int k=level;k>=1;k--)
						if(defs[k-1]&&defs[k-1]->f68<=gx_gd_d1e860.f46f4e0())
						{
							GxPoint pos;
							int got=0;
							if(gx_overmind_cf6428.f683500(&pos,1,0,0,&at,&got,0,0))
							{
								GxHE e=gx_map_cefc4c->placeEntity6c58c0(defs[k-1],pos,3,1,0x22,0xe,0);
								if(e.valid())
								{
									placed2++;
									e->ai45b590()->setOperatorTerminal5b3760(at);
									(*gx_grid_cfd44c.atPoint(at))->getProp45d550()->f45cb30()->h70=e;
									break;
								}
							}
						}
				}
				if(!placed2)break;
				tmpExtra="X0-1V1: \"ALERT: Engaging LAN party protocols.\"";
				do{gx_logPhrase5141b0(0xb2,0,0,0,GxHE(),0);}while(false);
				until=-2;
				a_=true;
			}
			break;
		case 94:
			if(gx_loc_d1e888->f8>7)break;
			{
				GxOwnerList recs;
				for(unsigned i=0;i<gx_cf6478.size();i++)
					if(gx_cf6478[i]->f0==3&&gx_cf6478[i]->f8!=-2)recs.push_back(gx_cf6478[i]);
				if(recs.empty())break;
				gx_shuffle9d8f80(recs);
				int a6=gx_maxInt9cdb60(1,recs.size()/2)+recs.size()/2*scale7/100;
				gx_clampMax9cf5a0(&a6,recs.size());
				int changed=0;
				for(int t=0;t<a6;t++)
				{
					GxHE e=recs[t]->e;
					if(!e->ai45b590())break;
					GxHEs followers;
					if(e->ai45b590()->getFollowers580a90(followers,3))
						for(unsigned j=0;j<followers.size();j++)
							if(followers[j]->ai45b590())
							{
								followers[j]->ai45b590()->setFollow5b2f80(GxHE(),0);
								followers[j]->ai45b590()->f4582d0(0x17);
							}
					v198.push_back(e);
					changed++;
				}
				if(!changed)break;
				f1a8=gx_map_cefc4c->getTurn464270()+rng.rangeInt(5,15);
				tmpExtra="X0-1V1: \"ALERT: Updating transport protocols with improved security requirements.\"";
				do{gx_logPhrase5141b0(0xb3,0,0,0,GxHE(),0);}while(false);
				until=-2;
				a_=true;
			}
			break;
		case 95:
			{
				GxHE e=gx_map_cefc4c->f7285b0();
				if(e.valid())
				{
					tmpExtra="X0-1V1: \"I may have passed a hint to a nearby "+e->name416f40()+".\"";
					a_=true;
				}
			}
			break;
		case 96:
			if(gx_loc_d1e888->f8>8)break;
			gx_clearDijkstra4faf40();
			gx_fov_cfe568.f40ca20(player->getPosition45a4a0(),player->f5c7d30()+3,gx_d28c64,0);
			if(gx_d15e58.empty())break;
			{
				GxPoint a2=gx_randomPoint9d5350(gx_d15e58);
				int level=gx_gd_d1e860.f46f4e0();
				GxDef*def=0;
				if(rng.chance(33))
				{
					GxItems cands;
					GxItems*inv=&player->getInventoryList45ab00();
					for(unsigned i=0;i<inv->size();i++)
						if((*inv)[i]->getType44aec0()<=3&&(*inv)[i]->f457920()>=level&&gx_f5714a0((*inv)[i]->info9b4350()->f54))cands.push_back((*inv)[i]);
					if(!cands.empty())def=gx_randomRecord9dafb0(cands)->info9b4350();
				}
				if(def==0)def=gx_map_cefc4c->selectRandomItemOfRating6c40e0(level+scale7/40,1,0,0x1f,0x12,0x2a,0);
				GxHI t_=gx_map_cefc4c->f6c5400(def,a2);
				if(t_.valid())
				{
					t_->f57bff0(0x82,gx_loc_d1e888->f8<=3&&rng.chance(scale7*2)?2:1);
					a_=true;
				}
			}
			break;
		case 97:
			if(veilEnd||sensorEnd||gx_cf4a00||!player->f5d2380(11).valid()&&!player->f5d2380(13).valid()&&!player->f5d2380(14).valid()&&!player->f5d2380(0x12).valid())break;
			tmpExtra="X0-1V1 turns out the lights.";
			veilEnd=turn+scale7*2+125;
			do{gx_logPhrase5141b0(0xb5,0,0,0,GxHE(),0);}while(false);
			showXomAct6bdb50(0,player,0);
			a_=true;
			break;
		case 98:
			{
				GxIntVec2 kinds3;
				GxIntVec2 machines;
				GxHPs sparkers2;
				GxHPs imploders;
				GxHPs doors;
				GxItems scrap0;
				GxArea area;
				gx_grid_cfd44c.getRect9b4430(player->getPosition45a4a0(),player->f5c7d30(),area);
				for(int x=area.a;x<=area.c;x++)
					for(int y=area.b;y<=area.d;y++)
						if(gx_map_cefc4c->isVisible463190(x,y))
						{
							if((*gx_grid_cfd44c.at(x,y))->getProp45d550().valid()&&(*gx_grid_cfd44c.at(x,y))->getProp45d550()->f44ab40()!=-1&&(*gx_grid_cfd44c.at(x,y))->getProp45d550()->getDef9b8f00()->f8c)
							{
								gx_addUnique9db000(machines,(*gx_grid_cfd44c.at(x,y))->getProp45d550()->f44ab40());
								gx_addUnique9db000(kinds3,0);
							}
							else if((*gx_grid_cfd44c.at(x,y))->f66b1c0(1,1))
							{
								gx_addUnique9d30e0(sparkers2,(*gx_grid_cfd44c.at(x,y))->getProp45d550());
								gx_addUnique9db000(kinds3,2);
							}
							else if((*gx_grid_cfd44c.at(x,y))->f66b1c0(0,1))
							{
								gx_addUnique9d30e0(imploders,(*gx_grid_cfd44c.at(x,y))->getProp45d550());
								gx_addUnique9db000(kinds3,3);
							}
							if((*gx_grid_cfd44c.at(x,y))->f45dcf0()&&(*gx_grid_cfd44c.at(x,y))->getProp45d550()->getDef9b8f00()->f8c)
							{
								gx_addUnique9d30e0(doors,(*gx_grid_cfd44c.at(x,y))->getProp45d550());
								gx_addUnique9db000(kinds3,1);
							}
							if((*gx_grid_cfd44c.at(x,y))->getItem45d8f0().valid()&&(*gx_grid_cfd44c.at(x,y))->getItem45d8f0()->f457880()==2)
							{
								gx_addUnique9d30e0(scrap0,(*gx_grid_cfd44c.at(x,y))->getItem45d8f0());
								gx_addUnique9db000(kinds3,4);
							}
						}
				if(kinds3.empty())break;
				GX_MSG(0x2b9,&string("X0-1V1 uses Touch of Redecoration!"),GxHE(),&aG);
				int theKind=gx_randomRec9d5d00(kinds3);
				switch(theKind)
				{
				case 0:
					gx_randomRecord9dafb0(gx_d31640[gx_randomRec9d5d00(machines)])->f45ce10(0,1,0,GxHE());
					break;
				case 1:
					(*gx_grid_cfd44c.atPoint(gx_randomRecord9dafb0(doors)->f4184d0()))->f66ce10(0,0,0,0);
					break;
				case 2:
					{
						GxHP prop=gx_randomRecord9dafb0(sparkers2);
						string line=prop->getName45c5b0()+" begins sparking wildly.";
						GX_MSG(0x320,&line,GxHE(),0);
						gx_map_cefc4c->f464a80(prop);
						GxHPs*group0=&gx_d31640[prop->f44ab40()];
						for(unsigned i=0;i<group0->size();i++)(*group0)[i]->f452270(3);
					}
					break;
				case 3:
					{
						GxHP prop=gx_randomRecord9dafb0(imploders);
						string line=prop->getName45c5b0()+" sparks and implodes.";
						GX_MSG(0x320,&line,GxHE(),0);
						prop->f45ce10(0,1,0,GxHE());
					}
					break;
				case 4:
					{
						GxEntityDef*def=gx_map_cefc4c->f6c5600(3,0x3f,0,1);
						if(def)
						{
							GxHI item=gx_randomRecord9dafb0(scrap0);
							GxHE e=gx_map_cefc4c->placeEntity6c58c0(def,item->f575920(),5,0,3,0xe,0);
							if(e.valid())
							{
								e->f639530(0x3a,1);
								string line="Scrap shifts and assembles itself into "+e->name416f40()+".";
								GX_MSG(0x320,&line,GxHE(),0);
								item->remove57dbe0(0,1,1,1);
								gx_sound454260(e->getPosition45a4a0(),0xb2);
								break;
							}
							goto noRedecor;
						}
					}
				}
				a_=true;
noRedecor:;
			}
			break;
		case 99:
			if(gx_loc_d1e888->depth==15)break;
			GX_MSG(0x320,&string("Surrounding terrain vaporized."),GxHE(),0);
			{
				int radius=scale7/10+15;
				do{gx_logPhrase5141b0(0xb6,&gx_intToString4051f0(radius),0,0,GxHE(),0);}while(false);
				gx_map_cefc4c->f747060(player->getPosition45a4a0(),radius,gx_defs_d2d1c4[gx_indexOfName9d74d0(gx_defs_d2d1c4,"Terrabomb")]->f190);
				tmpExtra="X0-1V1: \"Learned that one from the Sigix.\"";
				a_=true;
			}
			break;
		case 100:
			{
				GxOwnerList recs6;
				for(unsigned i=0;i<gx_cf6478.size();i++)
					if(gx_cf6478[i]->f0==3&&gx_cf6478[i]->f8!=-2)recs6.push_back(gx_cf6478[i]);
				if(recs6.empty())break;
				GxExit*far=0;
				int farDist=-1;
				GxExitList*exits4=gx_map_cefc4c->exits462e10();
				for(unsigned i=0;i<exits4->size();i++)
					if((*exits4)[i]->h14.operator->())
					{
						int d=gx_distanceCeil40a3f0(player->getPosition45a4a0(),(*exits4)[i]->pos);
						if(d>farDist)far=(*exits4)[i];
					}
				if(far==0)break;
				GxPoint aE(far->h14->f4184d0());
				if(gx_distanceCeil40a3f0(player->getPosition45a4a0(),aE)<25)break;
				GxArea area;
				gx_grid_cfd44c.getRect9b4430(aE,15,area);
				for(unsigned i=0;i<recs6.size();i++)
				{
					GxHE e=recs6[i]->e;
					if(!e->ai45b590())continue;
					e->ai45b590()->f459470(area);
				}
				tmpExtra="X0-1V1: \"ALERT: Introduced new transport parking protocols.\"";
				do{gx_logPhrase5141b0(0xb7,0,0,0,GxHE(),0);}while(false);
				until=-2;
				a_=true;
			}
			break;
		case 101:
			if(!gx_gd_d1e860.f46f4b0(1)||gx_loc_d1e888->depth==13||gx_loc_d1e888->depth==12||gx_loc_d1e888->depth==14||gx_loc_d1e888->depth==0x22||gx_loc_d1e888->depth==0x23)break;
			{
				int amountB=scale7*2+100;
				tmpExtra="X0-1V1: \"";
				string size;
				switch(gx_minInt9cdb30(scale7/33,2))
				{
				case 0:
					tmpExtra+="Threat records for the threat god!";
					size="minor";
					break;
				case 1:
					tmpExtra+="More threat records for the threat god!";
					size="considerable";
					break;
				case 2:
					tmpExtra+="So many more threat records for the threat god!";
					size="major";
					break;
				}
				tmpExtra+="\"";
				gx_overmind_cf6428.f682420(rng.chance(75)?0x21:0x20,amountB);
				do{gx_logPhrase5141b0(0xb8,&size,0,0,GxHE(),0);}while(false);
				a_=true;
			}
			break;
		case 102:
			GX_MSG(0x320,&string("IFF burst signal emitted."),GxHE(),0);
			tmpExtra="X0-1V1: \"Don't be shy now.\"";
			player->f6399e0(scale7/20+15,1);
			a_=true;
			break;
		case 103:
			if(player->fire63a3e0(1,GxHE()))
			{
				tmpExtra="X0-1V1: \"I had everything to do with that.\"";
				a_=true;
			}
			break;
		case 104:
			if(!gx_gd_d1e860.f46f4b0(1)||gx_loc_d1e888->depth==0x23||gx_loc_d1e888->f8>7)break;
			{
				GxSquadLists lists;
				lists.push_back(gx_map_cefc4c->squad463890(3)->members416f40());
				lists.push_back(gx_map_cefc4c->squad463890(4)->members416f40());
				GxIntVec2 factions;
				factions.push_back(2);
				factions.push_back(5);
				factions.push_back(8);
				factions.push_back(12);
				const int theRange=15;
				int pad4[1];
				GxHEs vC;
				for(unsigned i=0;i<lists.size();i++)
					for(unsigned j=0;j<lists[i]->size();j++)
						if(gx_containsRecord9db330(factions,lists[i]->at9b9230(j)->getFaction45a2c0())&&gx_distanceCeil40a3f0(lists[i]->at9b9230(j)->getPosition45a4a0(),player->getPosition45a4a0())<=theRange&&!lists[i]->at9b9230(j)->getTarget45a760())
							vC.push_back(lists[i]->at9b9230(j));
				if(vC.empty())break;
				gx_shuffle9d9fc0(vC);
				int keepN=scale7/15+2;
				if(vC.size()>keepN)vC.erase(vC.begin()+keepN,vC.end());
				for(unsigned i=0;i<vC.size();i++)
				{
					if(vC[i]->getGroup45a3f0()->f9b4350()!=3)vC[i]->f5dcc70(3,0);
					GxHI weapon;
					switch(vC[i]->getFaction45a2c0())
					{
					case 2:
						weapon=gx_map_cefc4c->giveItem6c52b0("Dynamite",vC[i],1,0);
						break;
					case 5:
						weapon=gx_map_cefc4c->giveItem6c52b0(vC[i]->f5cccc0()<=3?"Shotgun":"Hpw. Shotgun",vC[i],1,0);
						break;
					case 8:
						weapon=gx_map_cefc4c->giveItem6c52b0("Hvy. Hammer",vC[i],1,0);
						break;
					case 12:
						weapon=gx_map_cefc4c->giveItem6c52b0(vC[i]->f5cccc0()<=3?"Spear":"Lance",vC[i],1,0);
						break;
					}
					vC[i]->setAI64ecf0(new GxAIObj(vC[i],3,8));
					vC[i]->ai45b590()->chase5b4710(gx_map_cefc4c->getPlayer4630f0(),-1,0,0,0);
					if(i==0)vC[i]->f6396a0("Xom_Armed_NC_"+gx_kindNames_d2f798[vC[i]->getFaction45a2c0()]+"_T",0);
					if(weapon.valid())vC[i]->ai45b590()->f5b57a0(weapon,1);
				}
				tmpExtra="X0-1V1: \"When will someone think of the little guy?\"";
				until=-2;
				a_=true;
			}
			break;
		case 105:
			if(gx_map_cefc4c->f4638e0(0,3))break;
			{
				GxHEs w3;
				for(int s=1;s<=2;s++)
				{
					GxHEs*members=gx_map_cefc4c->squad463890(s)->members416f40();
					for(unsigned i=0;i<members->size();i++)
						if((*members)[i]->getAiType45a2a0()&&!(*members)[i]->getTarget45a760()&&(*members)[i]->isXomCandidate5d51a0()&&gx_map_cefc4c->f4631f0((*members)[i])&&!(*members)[i]->getInventory45ad90())
							w3.push_back((*members)[i]);
				}
				if(w3.empty())break;
				GxHE w9=gx_randomRecord9dafb0(w3);
				int group=w9->getGroup45a3f0()->f9b4350();
				w9->changeFaction5dc780(gx_map_cefc4c->squad463890(3),1);
				gx_sound4541b0(0x6b,0,0);
				string line="X0-1V1 rewrites "+w9->name416f40()+" IFF filter.";
				GX_MSG(0x2b9,&line,GxHE(),&aG);
				if(rng.chance(25))tmpExtra="X0-1V1: \"There is a traitor in your midst!\"";
				do{gx_logPhrase5141b0(0xb9,&w9->name416f40(),0,0,GxHE(),0);}while(false);
				GxGoal*bX=w9->ai45b590()->f4590f0()->f57f140(new GxXGroup(0x42));
				bX->f4=gx_map_cefc4c->getTurn464270()+scale7/10+6;
				bX->v8.push_back(GxPoint(group));
				a_=true;
			}
			break;
		case 106:
			if(!gx_gd_d1e860.f46f4b0(1)||gx_loc_d1e888->depth==13||gx_loc_d1e888->depth==12||gx_loc_d1e888->depth==14||gx_loc_d1e888->depth==0x22||gx_loc_d1e888->depth==0x23)break;
			if(gx_map_cefc4c->f4642b0()>=500)break;
			{
				GxWL<int> kinds;
				kinds.add(2,25);
				kinds.add(5,25);
				kinds.add(12,50);
				if(false){}
				f1b0=kinds.pick();
				string what;
				switch(f1b0)
				{
				case 2:
					tmpExtra="X0-1V1: \"I'm sending someone to fix up the mess you leave.\"";
					what="fix up the mess you leave";
					break;
				case 5:
					tmpExtra="X0-1V1: \"I'm sending someone to clean up after you.\"";
					what="clean up after you";
					break;
				case 12:
					tmpExtra="X0-1V1: \"I'm sending someone to keep an eye on you.\"";
					what="keep an eye on you";
					break;
				}
				do{gx_logPhrase5141b0(0xba,&what,0,0,GxHE(),0);}while(false);
				until=-2;
				a_=true;
			}
			break;
		case 107:
			if(gx_loc_d1e888->depth==13||gx_loc_d1e888->depth==11)break;
			{
				GxExit*best=0;
				GxExitList*exits=gx_map_cefc4c->exits462e10();
				int bestDist2;
				for(unsigned i=0;i<exits->size();i++)
					if((*exits)[i]->h8->depth!=13&&(*exits)[i]->h8->depth!=14&&(!best||gx_distanceCeil40a3f0(player->getPosition45a4a0(),(*exits)[i]->pos)<bestDist2))
					{
						int same=0;
						for(unsigned j=0;j<exits->size();j++)
							if((*exits)[j]->h8->depth==(*exits)[i]->h8->depth)same++;
						if(same>=2)
						{
							best=(*exits)[i];
							bestDist2=gx_distanceCeil40a3f0(player->getPosition45a4a0(),(*exits)[i]->pos);
						}
					}
				if(best)
				{
					if(gx_map_cefc4c->isVisible4631c0(best->pos))
					{
						string line=gx_locNames_cfaca0[best->h8->depth]+" access collapses.";
						GX_MSG(0x320,&line,GxHE(),0);
						line="X0-1V1 taps the No Entrance sign.";
						GX_MSG(0x2b9,&line,GxHE(),&aG);
						do{gx_logPhrase5141b0(0xbb,&gx_locNames_cfaca0[best->h8->depth],0,0,GxHE(),0);}while(false);
						showXomAct6bdb50(0,GxHE(),&best->pos);
					}
					else
					{
						string line="X0-1V1 taps a No Entrance sign.";
						GX_MSG(0x2b9,&line,GxHE(),&aG);
						do{gx_logPhrase5141b0(0xbc,0,0,0,GxHE(),0);}while(false);
					}
					(*gx_grid_cfd44c.atPoint(best->pos))->f66a050(gx_cefb9c->f0,2,1);
					GxPoint pos2(best->pos);
					gx_deleteObject9db030(gx_map_cefc4c->exits462e10(),gx_find9d4660(gx_map_cefc4c->exits462e10(),best));
					GxPropDef*wC;
					if(gx_findPropDef9d7710(gx_propDefs_cf35b0,"Collapsed Tunnel",&wC)&&(*gx_grid_cfd44c.atPoint(pos2))->getProp45d550().isNull())
						if((*gx_grid_cfd44c.atPoint(pos2))->f45df50(gx_factory_cefaa8->createE793360(wC)))
							(*gx_grid_cfd44c.atPoint(pos2))->getProp45d550()->f45cc50(pos2);
					until=-2;
					a_=true;
				}
			}
			break;
		case 108:
			if(gx_cf6474||!gx_tbl_b903c0[gx_loc_d1e888->depth]||gx_cf6470||gx_loc_d1e888==gx_d1ebd8||gx_loc_d1e888==gx_d1ebe0)break;
			if(f164!=-1)break;
			{
				int count;
				int ok=gx_map_cefc4c->f7143e0(&count);
				if(!ok||count>=40)break;
				f1bc=turn+35+gx_maxInt9cdb60(0,100-scale7);
				tmpExtra="X0-1V1: \"Who needs BL-4Z3 when you have control of the 0b10 sterilization system?\"";
				do{gx_logPhrase5141b0(0xbf,0,0,0,GxHE(),0);}while(false);
				until=-1;
				a_=true;
			}
			break;
		case 109:
			if(gx_loc_d1e888->depth!=12||gx_d1eae4)break;
			gx_d1eae4=gx_maxInt9cdb60(1,gx_map_cefc4c->f4642d0()+11);
			tmpExtra="X0-1V1: \"Who turned this fun thing off?\"";
			do{gx_logPhrase5141b0(0xc0,0,0,0,GxHE(),0);}while(false);
			until=-2;
			a_=true;
			break;
		}
		if(a_)
		{
			if(!tmpExtra.empty())GX_MSG(gx_inRange9daf80(0,act,0x1c)||gx_inRange9daf80(0x1d,act,0x41)?0x2b7:0x2b9,&tmpExtra,GxHE(),&aG);
			if(!fcc&&gx_loc_d1e888->depth==0x23)
			{
				fcc=true;
				GX_ALERT(&string("A0_COM: Spacetime anomalies detected. Expect the unexpected."));
				string line("X0-1V1: \"");
				line+=rng.chance(50)?"How flattering.":"Flattery will get them everywhere and nowhere, all at once. I'll see to that.";
				line+="\"";
				GX_MSG(0x2b5,&line,GxHE(),0);
			}
			switch(act)
			{
			case 11:case 31:if(gx_say_cefb48)gx_say_cefb48->say49e250(0x3d,0,gx_e_b9588b);break;
			case 14:if(gx_say_cefb48)gx_say_cefb48->say49e250(0x3e,0,gx_e_b9588e);break;
			case 15:if(gx_say_cefb48)gx_say_cefb48->say49e250(0x3f,0,gx_e_b9588f);break;
			case 65:if(gx_say_cefb48)gx_say_cefb48->say49e250(0x40,0,gx_e_b95892);break;
			case 69:if(gx_say_cefb48)gx_say_cefb48->say49e250(0x41,0,gx_e_b95893);break;
			case 79:if(gx_say_cefb48)gx_say_cefb48->say49e250(0x42,0,gx_e_b95899);break;
			case 80:if(gx_say_cefb48)gx_say_cefb48->say49e250(0x43,0,gx_e_b9589a);break;
			case 99:if(gx_say_cefb48)gx_say_cefb48->say49e250(0x44,0,gx_e_b9589b);break;
			case 100:if(gx_say_cefb48)gx_say_cefb48->say49e250(0x45,0,gx_e_b958a2);break;
			}
			vb4[act]=until;
			if(rng.chance(20))f10=rng.rangeInt(0,gx_d223ec);
			gx_stats_d2c658.add4729d0(gx_inRange9daf80(0,act,0x1c)||gx_inRange9daf80(0x1d,act,0x41)?0x3ba:0x3bb,1,gx_e_b958a3,-1);
			if(gx_tbl_bbb2a8[act])
			{
				int add=gx_minInt9cdb30(gx_tbl_bbb2a8[act],3000-fc8);
				fc8+=add;
				gx_stats_d2c658.add472b90(0x1a,add);
			}
			gx_view_cec054->delay49adc0(1000);
		}
		else acts.remove9bab80(act);
	}
	}
}
GxPoint::GxPoint(int x_,int y_){x=x_;y=y_;}
GxXGroup::GxXGroup(int){}
