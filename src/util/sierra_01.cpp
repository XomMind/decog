// EntityAI::takeTurn (0x5826b0): per-turn AI driver (pre-switch upkeep + the 32-mode f4 switch).
// Private partial ABI views (Si*/si_* names are file-private placeholders; callees stay stubs paired by address).
// NOTE: placeholder names / placeholder layouts throughout. Many locals carry odd names: VS2010 /Od orders a scope's
// locals by a hash of the name, so names were chosen to reproduce the exe frame. Some decls are hoisted/uninitialized
// for the same reason. Inline empty ctors (SiRec118, SiShot46) let LTCG prove the `new` nothrow (no EH state).
// Source of truth for edits: scratch/sierra/s1x.cpp (macro-expanded); notes: scratch/sierra/NOTES.md.
#include <string>
#include "util/rng.h"
using namespace std;
extern RNG rng;
struct SiVRecs;struct SiVZ;struct SiVHE5;struct SiZone;struct SiVShot;struct SiVAr;struct SiExpl;struct SiHMk;struct SiVVP;struct SiVMk;struct SiVVMk;struct SiV7;struct SiVHI5;struct SiVArea;struct SiV6e;struct SiTerr{int f0;};struct SiVPl;struct SiVHIg;struct SiVIg;struct SiVI5;struct SiVI2;struct SiPropDef;struct SiInv;struct SiVHE3;struct SiPropInfo;struct SiObj500;struct SiSecDef;struct SiP;struct SiHE;struct SiHI;struct SiHP;struct SiHG;struct SiAI;struct SiEntity;struct SiItem;struct SiProp;
struct SiP{int x,y;SiP()throw();SiP(const SiP&,int,int);SiP(int)throw();SiP(const SiP&)throw();SiP(int,int);SiP&operator=(const SiP&);bool eq409cb0(int,int);void set409ff0(int);void set40a010(int,int);bool ne409cf0(int,int);SiP add409b60(const SiP&);int distanceTo409fb0(const SiP&);bool adjacent409dd0(const SiP&);bool eq409b90(const SiP&);void op40a030(const SiP&);SiP sub409b30(const SiP&);void op409a30(const SiP&);bool ne409bd0(const SiP&);};
struct SiCIt{void*p;SiCIt();};struct SiIt:SiCIt{SiIt();SiIt operator+(int)const;};
struct SiVPf{void*a,*b,*c,*d;SiIt begin9c1270();SiIt end9e9b30();SiIt erase9b34c0(SiCIt,SiCIt);SiIt erase9b3450(SiCIt);void pop_back9b33e0();SiP&back9e8c10();unsigned size9b9a50()const;void push_back9b32e0(const SiP&);bool empty9b86e0()const;SiP&front9b7060();SiP&operator[](unsigned)throw();void clear9b3560();void assign9b3430(unsigned,const SiP&);};
struct SiQ2:SiP{SiQ2();using SiP::operator=;};
struct SiArea{int x1,y1,x2,y2;SiArea();SiArea(int,int,int,int);SiArea&operator=(const SiArea&);SiP randomPoint40be90();void u40b300(int,int,int,int);bool contains40b750(const SiP&);bool containsAny40b780(SiVPl&);bool u40b700(int,int);void randomPoint40be30(SiP*);};
struct SiThrowDef{bool u5012a0(const SiP&);};struct SiVSec{void*a,*b,*c,*d;};
struct SiQ:SiP{SiQ();void operator=(const SiP&);};
struct SiVHE2;struct SiVPl{void*a,*b,*c,*d;SiVPl(unsigned,const SiP&);SiP&front9b7060();bool empty9b86e0()const;void push_back9b3020(SiP&&);void push_back9b32e0(const SiP&);SiVPl();~SiVPl();unsigned size9b9a50()const;SiP&operator[](unsigned);};
struct SiVX{void*a,*b,*c,*d;SiVX();~SiVX();unsigned size9b9260()const;int&operator[](unsigned);};struct SiVE8{void*a,*b,*c,*d;SiVE8();~SiVE8();};struct SiVPP{void*a,*b,*c,*d;SiVPP(const SiVPP&);~SiVPP();unsigned size9b9260()const;SiP*&operator[](unsigned);};
struct SiVI2{void*a,*b,*c,*d;void push_back9b9280(const int&);SiVI2();~SiVI2();unsigned size9b9260()const;int&operator[](unsigned);};
struct SiPlan{int pad[0x16];SiPlan(SiHE,int);~SiPlan();void u581b80(int);int score581e70(SiHI,int);};
struct SiVI5{void*a,*b,*c,*d;unsigned size9b9260()const;SiVI5(unsigned,const int&);~SiVI5();int&operator[](unsigned);};
struct SiWL{char pad[0x24];SiWL();~SiWL();void add9ba310(SiPropDef*,int);int u9b81d0();SiPropDef*&pick9ba470();};
struct SiVPD{unsigned size9b9260()const;SiPropDef*&operator[](unsigned);};
struct SiP;struct SiVP{void*a,*b,*c,*d;SiP&back9e8c10();bool empty9b86e0()const;unsigned size9b9a50()const;SiP&operator[](unsigned);};struct SiTgt;struct SiEntity;struct SiItem;struct SiProp;struct SiGroup;struct SiDef;struct SiAI;
struct SiHE{int id;SiHE()throw();void reset9b7270();bool operator==(SiHE);SiEntity*operator->()const throw();bool isValid()const;bool isNull9b65d0()const;bool operator!=(SiHE)const;bool operator==(SiHE)const;};
struct SiTgt{SiHE e;int f4;int f8;};
struct SiHA{int id;SiHA();};
struct SiSecDef;struct SiRect{char pad[0x10];SiRect(SiSecDef*,SiHE,int,SiHE){}};
struct SiVHE3{void*a,*b,*c,*d;SiVHE3(){}~SiVHE3();void push_back9b9280(SiRect*const&);};
struct SiHI{int id;SiHI()throw();void reset9b7270();SiItem*operator->()const throw();bool operator==(SiHI)const;bool isValid()const throw();bool isNull9b65d0()const throw();};
struct SiObj45b9e0;struct SiVI40{void*a,*b,*c,*d;bool empty9b86e0()const;unsigned size9b9260()const;int&operator[](unsigned);void clear9bac80();};struct SiPropInfo{char pad[0x11];bool b11;char pad12[0x16];int f28;char pad2c[0x14];SiVI40 v40;char pad50[0x28];SiObj45b9e0*f78;string u65cc80();};
struct SiObj45b9e0{char b;SiObj45b9e0(){}int u65c1f0(SiPropInfo*,int);};
struct SiPropDef{char pad0[0x40];int f40;char pad44[4];int f48;char pad4c[0x14];int f60;};
struct SiPropDef2{char pad[0xf4];int ff4;char padf8[0x28];int f120;char pad124[0x30];int f154;};struct SiHackRec{int f0;int f4;char pad8[8];int f10;bool u65cf50(int);};
struct SiProp{void u665b10(int,int);bool isPassableFor65e1d0(SiHE);void u45cc50(const SiP&);void u65e2d0();void u45ce10(int,int,int,SiHE);int u44ab40();const SiP&u4184d0();SiPropDef2*pdef9b8f00();SiHackRec*u44b020();bool u45cbd0();void u65f170();SiPropInfo*u45cb30();int u457b10();const string&tag45c590();int height9b8f00();const string&getName45c5b0();};
struct SiHP{int id;SiHP();SiProp*operator->()const;bool isValid()const;bool isNull9b65d0()const;};
struct SiHG{int id;SiHG();SiGroup*operator->()const;};
struct SiGroup{void u671f80(SiHE,SiHE);int type9b4350();int height9b8f00();SiVHE2*members416f40();};
struct SiDef{string getName459c30();char pad0[4];string name;char pad20[4];int f24;int f28;char pad2c[0x1c];int f48;char pad4c[0x3c];float f88;char pad8c[0x10];int f9c;char pada0[0x80];int f120;char pad124[0x34];int f158;bool b15c;};
struct SiSpawnDef{int f0;string name;char pad20[4];int f24;int f28;char pad2c[0x70];int f9c;};
struct SiInv{bool hasType456490(int);};
struct SiItemDef{char pad0[0xec];int fec;char padf0[0x38];int f128;char pad12c[0x74];int f1a0;int f1a4;int f1a8;bool b1ac;char pad1ad[0xc7];bool b274;SiSpawnDef*u56f3c0();};
struct SiItem{bool u457e30();int u457920();int u457820()throw();int u577790();bool u457e90();int u457ca0();void u57a520(SiHP,int);int u457fb0();SiP&u575920();void u579c80();SiHE u457b50();int u4580a0();bool u578b80(SiHP);bool u578c50(const SiP&);bool u578d00(SiHE);int u457cd0();void u458360(int);bool u457e70();void u458310(int);int u457880();int u577e60();int u457940();int getType44aec0();int u4578c0();int u457b30();void u57a0f0(const SiP&,int,int);void setBroken5795b0(int,int);bool u458180();void setOverload579940(bool);int u5788e0();int u5789c0();const string&name457860();bool u457d70();int u4578a0();void u57a190(SiHE,int,int,int);void u57a0c0();int getEffect457b70(int);string getName571db0(int,int);int u457f90();int u45cb30()throw();bool u457cf0();void u44fc60(int);int u9b6bf0();int u457c80();void u450460(int);void remove57dbe0(int,int,int,int);bool u458220();SiItemDef*def9b4350();void setActive5791a0(bool);};
struct SiVHE2{bool empty9b86e0()const;unsigned size9b9260()const;SiHE&operator[](unsigned);};
struct SiVHE{unsigned size9b9260()const;SiHE&at9b9230(unsigned);};
struct SiVHI{unsigned size9b9260()const;SiHI&operator[](unsigned);};
struct SiVVHE{void*a,*b,*c,*d;SiVVHE();~SiVVHE();unsigned size9b9260()const;SiVHE*&operator[](unsigned);};
struct SiVInt{void*a,*b,*c,*d;bool empty9b86e0()const;void clear9b73d0();unsigned size9b9260()const;SiHE&operator[](unsigned);};
struct SiVHEp{void*a,*b,*c,*d;bool empty9b86e0()const;unsigned size9b9260()const;SiTgt*&operator[](unsigned);};
struct SiVHEl{void*a,*b,*c,*d;void clear9b73d0();SiVHEl&operator=(const SiVHE2&);bool empty9b86e0()const;SiVHEl();~SiVHEl();void push_back9b7cf0(const SiHE&);unsigned size9b9260()const;SiHE&operator[](unsigned);};
struct SiVHIl{void*a,*b,*c,*d;SiHI&front9b7060();void push_back9b7cf0(const SiHI&);bool empty9b86e0()const;SiVHIl();~SiVHIl();unsigned size9b9260()const;SiHI&operator[](unsigned);};
struct SiVHIm{void*a,*b,*c,*d;SiHI&back9b6540();unsigned size9b9260()const;SiHI&operator[](unsigned)throw();};
struct SiVI{void*a,*b,*c,*d;int&operator[](unsigned);};
struct SiRec{int type;int f4;SiVPf v8;SiHE f18;};
struct SiParts{SiRec*u458950(int);void u458a10(int);};
struct SiEntity{char pad0[8];SiDef*def;char padc[0x1c];SiHG g28;int f2c;SiVP v30;int f40;char pad44[0x2c];int f70;int f74;char pad78[0x20];int f98;char pad9c[0x34];int fd0;char padd4[0x18];SiInv*fec;char padf0[0x44];SiVHIm v134;SiAI*ai;
 int u5c8db0();int u5cb830(SiVHIl&);int u490840();int u5ca260();void u5dea60(int,int);SiAI*ai45b590();bool u5d5520(int);bool u45a510(const SiP&);void changePos5dccb0(const SiP&,bool);SiHI u5cbd10();int u5c7fa0();void u5fda70(int);int u5ca210();bool u5d5460(int);SiHI u5d24e0(int);bool u5d4ff0(bool,SiHI);SiHI u5d4dd0(bool,SiHI);int u45a940();int u5ca670();bool u5c84f0(const SiP&);bool u5c8710(const SiP&);bool u5cac90();bool u5cabd0();SiHI u5d5c30();int getSize45a360();SiVPl*u45d1a0();bool u5c87f0(const SiP&);bool u5c7f70();void u64e7e0(SiHI);SiHI u5d5d40();int u5cb570(int,bool);int u5cccc0();int u5d15a0(int);int u45a880();int u45acb0(int);void u5fdab0();void u44e2c0(int);SiHI u5cc8e0();SiHI u5d2d60(SiHE,int*);bool u5cb680(SiHG);bool u5c83d0(const SiP&,int);bool u5c8430(const SiP&,const SiP&,int);int u5d2090(int);bool u5cc5d0(int);bool u5cc7c0(int);bool u5cc6a0(int,SiHI&,int);void u5cb8b0(SiVHIl&);void u5cb8b0(SiVHI5&);bool isInGroup5cb6b0(SiHG);void u5de7b0();void u5df740(int);int u45a7e0();int u45a810();bool u5d1280(int);void u5c93d0(SiVI2&);int u5c8d80(int);int u5d1390();int u5c8cb0();bool u5cc850(int);SiHI u5d5b20();int u45ac40(int);void u5d6c30(SiVHIl&);void removeEffectsA639730(int);void die633790(bool,int,SiHE,int,int,int,int,int);bool u45aaa0(SiHE);void u5d6a80(SiVHIl&,const SiP&,int);int u45a8d0();void u5ded70(int);int u45a920();void u5deb40(int);bool u5d0fe0();bool u5c8820(SiHE);void u642940(SiHI,int,int,int,int);bool isXomCandidate5d51a0();void u5de480(SiPropDef*);int u5d22a0(int);void u45b2a0();
 bool u5d5250();bool isHostileTo45aa70(SiHE);
 SiP&getPosition45a4a0();void clr45b0b0();int u5c7d30();SiP u5c80f0(const SiP&);SiP u45a4c0();int getTarget45a760();int u5d2150(int,int);SiHI u5d2380(int);
 SiHG getGroup45a3f0();bool isPlayer5c7600();int getFaction45a2c0();SiDef*def9b4350();SiHI u5d35b0(SiHE);string&getName45a280();int u5c8e20(int);int u5c8fc0(int,int);void u5cb830(SiVHI5&);int u5cba50();void u5c8880(SiVHE5&);SiHI u5d2a90(int);void setAI64ecf0(SiAI*);void u639530(int,int);void u63c660();void u45b070(const string&);bool u5d2a00(int);bool u5d55e0();SiHI u5cbc80();
 int u45a9d0();int getAiType45a2a0();SiVHI*getInventoryList45ab00();int u5cad50();int u5cb220();int u5c7fc0(SiHE);bool u5d26e0(int);void u637bb0();
 bool u45ae30();SiParts*u45ae50();void u45af20(int);string&name416f40();void u5fd900(int,int);void changeFaction5dc780(SiHG,bool);};
struct SiMap{int u4642d0();SiHE getPlayer4630f0();void u463970(SiHE,SiVVHE&);bool u72a850(int,SiHE,SiHE);bool u4631f0(SiHE);int getTurn464270()throw();void u72e4c0(SiHE,bool);bool u4658e0();void u464840(SiHE);bool u463040();SiVRecs*u45c7e0();void u71cc70(SiHE,const SiP&);bool u463160(const SiP&);bool u463380(int,int);void u72ffe0(int);bool u7168e0(const SiP&,const SiP&,SiEntity*,SiVPl&);bool isVisible463190(int,int);bool isKnown463130(int,int);bool u729d60(SiHE);bool u4633c0(const SiP&);SiVHE2*u4643b0();SiVHE2*u4643d0();void u464d80(SiHE);void u464de0(SiHE);void displayHack734ae0(SiHE,const SiP&,int);int u463540(SiHE);void u72e790(int);bool u463400(SiHE);bool u71bc10(const SiP&,SiP&);bool u74d420(const SiP&,SiP&);bool u716080(SiHE);bool u465200(const SiP&,const SiP&);bool u7170a0(SiHE,const SiP&,SiVPl&,SiVX&,SiVX&,SiP&,int,int,int,int);SiHA addRecord777a20(SiHA);SiVPP*u462e10();SiV6e*u462e10b();bool u716940(const SiP&,const SiP&,SiEntity*,unsigned*);void u747860(int,int);bool isReachable465230(int,const SiP&,const SiP&);bool u7178d0(SiHE,const SiP&,int*,const SiP&,int*,int);void u6c65a0(SiHE,const string&,int);bool u717e40(const SiP&,const SiP&,int,SiP&,SiP&,int,int);void setFlagA74_4654d0(bool);void thrownItemArrived7499f0(SiHE,SiHI,int,const SiP&,SiVHE3*);bool isVisible4631c0(const SiP&);void*u464410(const SiP&);SiHE getEntity463110();void u6c6b90(const SiP&,const string&,int,int);SiVZ*u462e10z();SiVHI5*getItems4655e0();SiVPf*getItemPositions465600();bool u462ea0(const SiP&);SiZone*getZone462e30(const SiP&);bool u464450();bool placeProp6c67b0(int,const SiP&,int,int,int);SiVShot*u464940();SiVAr*u4646b0();SiArea*u464650();bool u716940i(const SiP&,const SiP&,SiEntity*,int*);void u71ef30(const SiP&,int);void bomb744aa0(SiHE);string u463060(const SiP&);int u74b2c0(const SiP&);void u464870(SiHI);SiVPf*u464630();SiVVP&u463be0();SiVVMk&u463ec0();bool u71ec60(const SiP&,SiV7);bool u716a60(const SiP&,int,SiEntity*,SiVP*);SiHE u71e7c0(const SiP&,int,int);bool findPlaceableNear71c150(const SiP&,SiP&,int);SiHE placeEntity6c58c0(SiSpawnDef*,const SiP&,int,int,int,int,int);
 void u464d50(SiHE);void u464db0(SiHE);SiHG u463890(int);};
extern SiMap*si_cefc4c;
struct SiCell{bool fitsProp45d570(int);bool u45d6a0();const string&u45d140();void u45df50(SiHP);SiTerr*terr9fcd80();bool u45d310();bool u45de40();bool u45d230();bool u45dd40(int);int u9fcd80();bool isDoor45dda0();bool u45d330();void u66a050(int,int,int);int u45d180();bool u45dcf0();bool u66b250();bool u4550b0();bool u45db70();bool u45dc70();bool canCaveIn66af50();void*getEffect45d350(int);bool u66b1c0(int,int);void u80e0e0_(SiHE);bool isMachinePart45dcd0();bool u66b3d0(SiEntity*);bool isPassableFor66ab30(SiHE);void u66b700(int,int);SiHI getItem45d8f0();SiHE getEntity45d250();SiHP getProp45d550();};struct SiGrid{SiP getRandom9cf050();SiArea getArea9b4400();void getRandom9cf0c0(SiP&);void getBoundsB9b79c0(const SiP&,int,int,SiP&,SiP&);int width9fcd80();int height9b8f00();bool isEdge9b7960(const SiP&);bool contains9b43b0(const SiP&);void getBounds9b7a40(const SiP&,int,SiP&,SiP&);void getRect9b4430(const SiP&,int,SiArea&);SiCell**atPoint9ced70(const SiP&);SiCell**at9ceda0(int,int);};extern SiGrid si_cfd44c;
struct SiRange{int randomInRange40c130();};extern SiRange si_d38830;
struct SiPlayerData{bool hasCompanion780790();bool u77f260(int);void u77fbc0(int);};extern SiPlayerData si_cf45d8;
struct SiXom{bool on;void giveXomItems6be2f0(SiHE);void u69e700(int,int,float);};extern SiXom si_d25450;
struct SiUI{void bubble8758d0(bool);};extern SiUI*si_cec058;struct SiLog{void end7b4f10();};extern SiLog*si_cec0b4;
struct SiAlly{int f0;int f4;int f8;SiVPf v0c;void checkCapable57f1b0(SiHE);};
bool si_contains9d31e0(SiVInt&,SiHE);
struct SiSquad{int f0;SiHE f4;};
struct SiOvermind{bool findDispatchExit(SiP&,int,int,int,const SiP&,int&,int,int);bool findCargoDispatchTarget68a8b0(const SiP&,SiP&);SiSquad*u683310(SiHE);void u68cd80(SiSquad*);void wake68d480();int u684250(const SiP&,int);void u68d6d0(bool);void u682420(int,int);void u68d920(int);void u6823f0(int);void u682220(const SiP&);int u686c60(const SiP&,int,int,int);SiSquad*lastParty();};extern SiOvermind si_cf6428;
struct SiGameData{void setEntryText46f700(const string&,const string&);int getDepthIndex();bool u46f4b0(int);const string&getEntryText46f6d0(const string&);};extern SiGameData si_d1e860;extern int si_b92f64[];
struct SiState{int f0;int type;int f8;int getDepthIndex();};struct SiHS{int id;SiState*operator->()const;};extern SiHS si_d1e888;
struct SiB6{bool b0;char pad[5];};extern SiB6 si_b90184[];
struct SiVIs{int&operator[](unsigned);};struct SiStats{SiVIs*v;bool add4729d0(unsigned,int,string,int);};extern SiStats si_d2c658;extern const char si_empty_b91d71[];
struct SiNotice{void u451400(int);};extern SiNotice si_cf1080;extern bool si_d28fb0;int si_sound4541b0(unsigned,int,int);
bool si_msg5111e0(int,const string*,const string*,const string*,SiHE,SiHE,const SiP*,bool);
void si_454260(const SiP&,int);
int si_dist40a3f0(const SiP&,const SiP&);
string si_intToString(int);
extern bool si_cefb0e;extern int si_caf164;extern float si_cf6434;extern float si_ba65f0[];extern int si_cf4718;extern bool si_ba0968[];extern int si_d29730;extern int si_bba364;extern int si_bba368;extern int si_bba36c;int si_distance406480(int,int,int,int);extern bool si_caf204[];extern SiRange si_d2c43c;extern SiDef*si_cefc08;int si_maxInt9cdb60(int,int);extern string si_cfc9d8;extern SiItemDef*si_cefbec;extern const char si_empty_b91d8b[];extern const char si_empty_b91d9e[];extern const char si_empty_b91d9f[];extern const char si_empty_b91dc2[];int si_minInt9cdb30(int,int);
struct SiRec118{int f0;int f4;SiHE e8;SiHI hc;SiP p10;SiRec118(int,int,SiHE,SiHE,const SiP&){}};extern const char si_empty_b91d8a[];
struct SiPropPoints{char pad[0x1c];SiPropPoints(int,SiHE,const SiP&);};struct SiCPart{void u4a8fc0();void drawStatus4a8e70(int);};struct SiParts2{SiCPart*u894e70(SiHI);void toggle8993e0(SiCPart*,int);};extern SiParts2*si_cec088;struct SiInvUI{void reopen8a2ce0(int,SiHI);};extern SiInvUI*si_cec08c;extern int si_bb9ec4[];bool si_fn4569a0(int,SiHE,SiHE,SiHE,SiHE,int,int,SiInv*,SiHE,SiHE,SiHE,int);extern bool si_caf210[];extern const char si_empty_b91d7f[];extern const char si_empty_b91d89[];extern int si_cf655c;struct SiVSD{unsigned size9b9260()const;SiSpawnDef*&operator[](unsigned);};extern SiVSD si_d25de0;
void si_deleteObject9d8f20(SiVHEp&,int);void si_fn9d0690(int*,int,int);extern const char si_empty_b91d7e[];extern int si_b95fbc;extern int si_b95fb8;extern const char si_empty_b91d73[];
int si_fn9d4340(SiVI5&);int si_fn9db9d0(SiVI5&,int);int si_fn9d4500(SiVI5&);unsigned si_fn9d8ed0(SiVI5&);void si_eraseStep9d6440(SiVHIl&,unsigned&);void si_eraseAt9da940(SiVHIg&,int);void si_removeVectorElement9de6f0(SiVIg&,int);extern int si_cf462c;extern int si_b95fc0;extern int si_b95fb4;extern int si_ba7ac8[];extern const char si_empty_b91d72[];extern string si_d37cc0[];
struct SiSay{void say49e250(int,int,string);bool canSay49e120(int);};extern SiSay*si_cefb48;struct SiVHIg{void push_back9b80b0(const SiHI&);bool empty9b86e0()const;unsigned size9b9260()const;};extern SiVHIg si_cf46b4;struct SiVIg{void push_back9b9280(const int&);int&operator[](unsigned);};extern SiVIg si_cf46c4;
bool si_anyNonZero9d7f70(SiVI2&);int si_randomIndex9d9b20(SiVI2&);extern SiHE si_cf68b8;struct SiCf68b4{char pad[0x110];int f110;};extern SiCf68b4*si_cf68b4;struct SiUnit{bool u69ba80(SiHE);void resetAI699a00(int);bool u6997f0(int);void u699960();};extern SiUnit si_cf6888;
struct SiWLD{SiSpawnDef*&pick9ba470();};extern SiWLD si_cf2974;struct SiOwned{void u672f20(SiHE,int,int,string);};extern SiOwned*si_cf68f0;extern bool si_cf6a1c;extern int si_cf6a18;extern SiP si_cf6a10;extern int si_bba1d8;extern SiP si_d1ec6c;
struct SiShoot{char pad[0x7c];SiShoot(SiHE,int,const SiP&,SiP&,int&,SiVE8&,int,SiHE);};struct SiFactory{SiHA createA7930e0(SiShoot*);SiHI createD7932b0(int);SiHP createE793360(int);SiHA createA7930e0(SiExpl*);SiHMk createC793190();};extern SiFactory*si_cefaa8;
void si_shuffle9d7350(SiVPl&);void si_shuffle9d9fc0(SiVHIl&);extern int si_bba140;extern int si_cefbd8;extern SiVPD si_d2d1c4;extern int si_caed20;extern int si_d2e20c;
struct SiMapView{void u8196c0(SiHE);void u49ac90(const SiP&,int,int);void u49ada0(int);void showHitBonus817390(SiHE);void u80e0e0(SiHE);};extern SiMapView*si_cec054;
struct SiEffect{void init503b20();};struct SiObj500{char pad[0x64];SiObj500(int,SiHE,int,int,float,SiHE,SiHI,int,SiHE,int,SiVHE3*,int);};
struct SiEndObj{SiEffect*u508610(SiEndObj*,void*,const SiP&,int*,const SiP*,int*,SiObj500*,int,int);};extern SiEndObj*si_cefc50;
int si_stringToInt405610(const string&);void si_message49c610(int,SiHE,const string*,int);bool si_lookupT9d7980(const string&,SiThrowDef*&);extern SiVSec si_d2c408;bool si_findByName9d7de0(SiVSec&,const string&,SiSecDef*&);
void si_sweep4faaf0(const SiP&,SiVPl&);void si_lookup9d7980(const string&,SiPropDef*&);extern int si_d2c46c;
#define SI_MSGX(ID,T1,T2,T3,A,B) do{if(si_msg5111e0(ID,T1,T2,T3,A,B,0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false)
#define SI_MSG(ID,TEXT,A,B) SI_MSGX(ID,TEXT,0,0,A,B)
#define SI_ALERTX(S,T) do{si_cf1080.u451400(1);if((S)!=-1&&!(si_d28fb0&&1&&1))si_sound4541b0(S,0,0);SI_MSG(0x324,&string(T),SiHE(),SiHE());si_cec0b4->end7b4f10();}while(false)
#define SI_ALERT() SI_ALERTX(0x127,"ALERT: Hostile activity reported, dispatching reinforcements to area.")
#define SI_ENDT(X) do{ent->f40++;ent->clr45b0b0();return X;}while(false)
#define SI_END SI_ENDT(rng.rangeInt(-10.0f,10.0f)+100)
#define SI_TRYMOVE do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false)
#define SI_MOVEEND do{SI_TRYMOVE;SI_END;}while(false)
#define SI_PATROLMOVE do{if(!ally114&&rng.chance(f48))SI_END;SI_MOVEEND;}while(false)
bool si_findByName9d7530(SiVSD&,const string&,SiSpawnDef*&);
SiP si_randomPoint9d5350(SiVPl&);
extern int si_cf6954;extern const char si_empty_b91dc3[];
void si_eraseAt9da940(SiVHIl&,int);
extern int si_b949e8[];bool si_contains9d31e0(SiVHEl&,SiHE);SiHE si_randomRecord9dafb0(SiVHEl&);bool si_fn9daf80(int,int,int);bool si_fn9d0ce0(SiVPl&,SiP);
int si_dir4374c0(const SiP&,const SiP&);extern SiP si_d015d8[];
struct SiTracker{void spawn7aa280(int,int,string);};struct SiCf4ac8{int f0;SiHI h4;char pad8[0x28];SiTracker*p30;};extern SiCf4ac8*si_cf4ac8;
extern int si_cf6a0c;
struct SiVTg{void*a,*b,*c,*d;SiVTg();~SiVTg();void push_back9b9d30(SiTgt*const&);bool empty9b86e0()const;SiTgt*&operator[](unsigned);};void si_shuffle9d8f80(SiVTg&);
struct SiCart{void u40ca20(const SiP&,int,void*,int);bool u40ca50(const SiP&,int,void*,SiEntity*,SiVP&,int*);bool findPath40c9a0(const SiP&,const SiP&,void*,void*,SiVPl&);};extern SiCart si_cfe568;extern void*si_cefc30;
struct SiVHEg{void*a,*b,*c,*d;void push_back9b80b0(const SiHE&);SiHE&operator[](unsigned);};extern SiVHEg si_cf25b8;extern SiVHEg si_d37984;int si_indexOfEntity9d3110(SiVHEg&,SiHE);void si_eraseAt9da940(SiVHEg&,int);void si_eraseAt9da940(SiVHEl&,int);bool si_contains9d31e0(SiVHEg&,SiHE);void si_insert9d8fc0(SiVHEl&,int,SiHE);void si_appendVector9d49c0(SiVHEl&,SiVHE2&);extern int si_cf4b98;
bool si_adjacent4373c0(const SiP&,const SiP&);
void si_eraseAt9d5190(SiVPf&,int);extern SiTerr*si_cefb88;extern int si_d1eb10;
extern int si_b95fac;
void si_logError404f10(string,string);extern void*si_cefc2c;extern int si_d395ac;
extern bool si_ba0984[];extern int si_cefb38;extern SiTerr*caveinWallTerrain;int si_randomRec9d5d00(SiVI2&);
struct SiView{char pad[0x2c];SiView();~SiView();void init9cffc0(int,int,int);void resizeView9d0050(int,int,int,int,bool);int left9b6bf0();int right9b6c10();int top44afb0();int bottom9b6c30();int&operator()(int,int);};
void si_moveElement9d9020(SiVPf&,int,int);
struct SiRecX{int f0;void add460a00(SiHE);};struct SiVRecs{unsigned size9b9260()const;SiRecX*&operator[](unsigned);};
extern SiRange si_d2c3b0;
struct SiX5:SiP{int f8;};struct SiVX5{bool empty9b86e0()const;unsigned size9b9260()const;SiX5*&operator[](unsigned);};extern SiVX5 si_cf0fa8;
struct SiY5{char pad[0x58];bool b58;};struct SiVY5{SiY5*&operator[](unsigned);};extern SiVY5 si_cfb844;extern int si_ce9ff4;extern int si_cefbb4;
struct SiVU{void*a,*b,*c,*d;SiVU();~SiVU();void push_back9b9d30(const unsigned&);bool empty9b86e0()const;};int si_randomRec9d5d00(SiVU&);SiX5*si_randomRec9d5d00(SiVX5&);int si_fn6c10f0(const SiP&);
struct SiPL{int f0;bool b4;char pad5[7];SiVPf vc;bool u6c11f0(const SiP&);};struct SiVPL{unsigned size9b9260()const;SiPL*&operator[](unsigned);};extern SiVPL si_cf44b0;
extern SiTerr*si_cefb9c;extern SiTerr*caveinEarthTerrain;extern SiTerr*si_cefbb0;extern bool si_d1eaac;extern SiRange si_d22260;void si_fn6c0f10(const SiP&,int,int);void si_adj4fab80(const SiP&,SiVPl&);
struct SiE6:SiP{SiHS h8;};struct SiV6e{unsigned size9b9260()const;SiE6*&operator[](unsigned);};
struct SiExpl{char pad[0x40];SiExpl(SiHE,int,const SiP&,SiHE,const SiP&,const SiP&);};
struct SiMarker{char pad[8];SiP p8;void u6c20b0(int,const SiP&,int);};struct SiHMk{int id;SiMarker*operator->()const;};
struct SiVMk{unsigned size9b9260()const;SiHMk&operator[](unsigned);void push_back9b7cf0(const SiHMk&);SiHMk&back9b6540();};
struct SiVVMk{SiVMk&operator[](unsigned);};struct SiVHP2{unsigned size9b9260()const;SiHP&operator[](unsigned);bool empty9b86e0()const;};struct SiVVP{SiVHP2&operator[](unsigned);};
struct SiV7{void*a,*b,*c,*d;SiV7(unsigned,const SiP&);SiV7(const SiV7&);~SiV7();};
struct SiVHI5{void*a,*b,*c,*d;SiVHI5();SiVHI5(const SiVHI5&);~SiVHI5();unsigned size9b9260()const;SiHI&operator[](unsigned);void push_back9b80b0(const SiHI&);bool empty9b86e0()const;};struct SiVVHI5{SiVHI5&operator[](unsigned);};extern SiVVHI5 si_cf3a10;
struct SiVArea{void*a,*b,*c,*d;SiVArea();~SiVArea();void push_back9b4610(const SiArea&);};extern SiVArea si_d2b274;void si_appendVector9d9140(SiVArea&,SiVArea&);bool si_anyAreaContains436d30(SiVArea&,const SiP&);
struct SiCMis{void u987de0();};extern SiCMis*si_cec034;bool si_containsRecord9db330(SiVI40&,int);extern bool si_cefb0d;extern SiVHIl si_d33d74;bool si_containsEntity9d31e0(SiVHIl&,SiHI);void si_removeEntity9d2f00(SiVHIl&,SiHI);SiHI si_randomRecord9dafb0(SiVHI5&);
int si_fn4373f0(const SiP&,SiVPf&);bool si_fn9d0ce0(SiVPf&,SiP);SiP si_randomPoint9d5350(SiVPf&);void si_fn454260(const SiP&,int);extern int si_cefbe0;SiHI si_randomRecord9dafb0(SiVHIl&);
void si_eraseStep9d6440(SiVHI5&,unsigned&);extern int si_cf4b98;
extern int si_d28e40;extern int si_cf4d30;extern int si_d254e0;extern int si_bba394;extern SiVPf si_d15e58;extern char si_d1e85c;void si_clearDijkstra4faf40();string si_toUpper4083a0(const string&);string si_countString407a80(int,const string&);bool si_fn9d51d0(SiVI40&,int);void si_removeEntity9d2f00(SiVHP2&,SiHP);
struct SiVGrid{SiGrid*&operator[](unsigned);};extern SiVGrid si_d22744;
int si_minInt9cdb30(int,int);
void si_logPhrase5141b0(int,int,int,int,SiHE,int);struct SiShake{void shake4b38f0(int,int);};extern SiShake si_d2f1c8;
struct SiVAr{bool empty9b86e0()const;unsigned size9b5100()const;SiArea&operator[](unsigned);};
struct SiVIn{void*a,*b,*c,*d;SiVIn();~SiVIn();void push_back9b9d30(const int&);void push_back9b9280(int&&);int&operator[](unsigned);int&back9b6540();unsigned size9b9260()const;};
void si_insertAt9dbdc0(SiVIn&,int,int);void si_fn9d9190(SiVIn&,int,int);struct SiCfg{char pad[0x4c];int f4c;};extern SiCfg*si_cefc00;
void si_eraseStep9d7300(SiVPf&,unsigned&);bool si_fn9d0ce0(SiVPl&,SiP);
struct SiShotB{};struct SiShot46:SiShotB{char pad[0x10];SiShot46(SiP,int,int)throw(){}};struct SiVShot{void push_back9b9280(SiShot46*&&);};
struct SiLoc{bool inRange46ecb0();};struct SiHLoc{int id;SiLoc*operator->()const;};struct SiZone:SiP{SiHLoc h8;bool bc;char padd[7];SiHP h14;};struct SiVZ{unsigned size9b9260()const;SiZone*&operator[](unsigned);};struct SiVHE5{void*a,*b,*c,*d;SiVHE5();~SiVHE5();bool empty9b86e0()const;unsigned size9b9260()const;SiHE&operator[](unsigned);};
struct SiS28{int f0;char pad[0x24];};extern SiS28 si_b939b4[];extern int si_cf6514;extern SiP si_cf6518;extern SiHP si_cf6510;extern SiHE si_cf64fc;extern SiVInt si_cf6500;
struct SiVNm1;extern SiVNm1 si_cf35b0;bool si_findByName9d7710(SiVNm1&,const string&,int&);bool si_findByName9d7de0(SiVSec&,const string&,int&);
void si_eraseAt9da940(SiVHIl&,int);void si_shuffle9d8f80(SiVPP&);
struct SiExpiry{void u45f0a0();void u45f070(const string&);void set690d40(int,int);};extern SiExpiry si_cf68c0,si_cf695c,si_cf6974,si_cf697c,si_cf69bc,si_cf68ac;extern string si_cf1f80,si_cf1f90,si_cfc1b4,si_cf1fa0,si_cf1fc0;
extern bool si_cf6a4c;extern int si_bba058[];struct SiVSq{void*a,*b,*c,*d;SiVSq();~SiVSq();void push_back9b9d30(SiSpawnDef*const&);SiSpawnDef*&operator[](unsigned);unsigned size9b9260()const;};struct SiWLSD{SiSpawnDef*&pick9ba470();};extern SiWLSD si_d2601c;
bool si_findByName9d7a40(SiVPD&,const string&,int&);
extern SiRange si_d2c650;extern SiWLSD si_d29da4;extern SiVPf si_cf69ec;struct SiVSDo{void push_back9b9d30(const int&);int&operator[](unsigned);};extern SiVSDo si_cf69fc;
struct SiVEnt{int a;};extern SiVEnt si_cf69dc;int si_indexOfEntity9d3110(SiVEnt&,SiHE);void si_eraseAt9da940(SiVEnt&,int);void si_removeVectorElement9de6f0(SiVSDo&,int);extern int si_cf69d8;
void si_shuffle9d9fc0(SiVHE5&);bool si_fn9daf80(int,int,int);struct SiTQ{void u672b80(SiHE,int);};extern SiTQ si_d225a0;extern SiVHEg si_cf6adc,si_cf6afc;
struct SiTMem{bool getTarget872e40(SiHE,SiP&);};extern SiTMem si_d1d9c0;
SiHI si_findUpgrade4fe3f0(SiHI,const SiVHI5&,SiHE)throw();void si_removeEntity9d2f00(SiVHI5&,SiHI);extern const char si_empty_b91de7[];
extern int si_b95fb0;
bool si_containsEntity9d31e0(SiVHIg&,SiHI);extern const char si_empty_b91df3[];
//DECL_END
void si_todo(int);
class SiAI{public:SiHE ent;int f4,f8,fc;SiP goal;SiP f18;SiHE f20;SiVP path24;int f34;int f38;int f3c;SiHE f40;int f44;int f48;int f4c;char pad50[5];bool b55;bool b56;char pad57[1];SiHE f58;char pad5c[4];int f60;char pad64[4];int f68;SiVPf v6c;bool b7c;char pad7d[3];SiArea a80;SiVPl v90;int fa0;SiArea fa4;SiHE fb4;SiHE fb8;int fbc;int fc0;int fc4;char padc8[4];int fcc;char padd0[4];SiHI fd4;char padd8[4];
 SiVInt vdc;int fec;SiVHEp vf0;char pad100[4];int f104;int f108;int f10c;bool b110;SiAlly*ally114;SiRec118*p118;SiParts*p11c;char pad120[0x10];SiAI(SiHE,int,int);
 int takeTurn();void u5b93a0();int get8_9b4350();void u44cea0(int);void u459410(const SiArea&);bool findPatrolSpot5b6850(SiP&);bool u5b66c0(SiP&);void addEarlyExiter5bd450(const SiP&);int getF4_9b8f00();void u451930(int);bool getFollowers580a90(SiVHE5&,int);void u4582d0(int);void u459540(const SiP&);void u459470(const SiArea&);void u459520(const SiP&);SiVPf*u458ef0();int u5bac50();SiP u5ba650(int,int);void u5b7340(const SiP&);int u5b6a60(const SiP&,const SiP&);int u5b6d40(const SiP&,const SiP&);void u459150(SiRec*);bool u5b6130(const SiP&);void setPatrolRandom5b3430(SiP);void u5b91e0();SiP*goalp462e10();bool findPathToGoal5b8d20();void hack5be7c0(int);int u5ba870(SiHE,int,int);int service5bac50();int mode9b4350();int assimilate5bbf70(int,SiHE);bool u5815e0();bool u5b9cb0(int);bool u5bd350(SiHE);SiParts*u4590f0();void setField451440(SiHE);void u459230();bool isSpotterOfThree57ef20();void u5b4530();void u5bb750(int,int,int);bool u5b9860();void u5b5380(SiPropPoints*);int move5b76c0(int*);bool u5b7400(int*);void comment5bd7d0();void u5bd680();void u5b2d10();void u5b5830(bool);void u5b57a0(SiHI,int);void reinforce5b3a30(int);int chase5b4710(SiHE,int,int,int,int);SiTgt*u580ec0();void u5b51b0(SiHE);SiTgt*getEntity459570(SiHE);bool u5813a0();void setFollowEntity5b2f80(SiHE,int);void u5b94c0();void u5b64d0();bool u459090();bool u458a90();void u4591c0(int);bool u5b4690(SiHE);void u4593b0(const SiP&);bool u581140();void u5ba3e0();};

int SiAI::takeTurn(){
 if(si_cefc4c->u4642d0()==1){
  int dist=si_dist40a3f0(ent->getPosition45a4a0(),si_cefc4c->getPlayer4630f0()->getPosition45a4a0());
  if(dist>30){int t=dist/5*100;t+=rng.rangeInt(10.0f,90.0f);return t;}
 }
 if(si_cefb0e)do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
 fc=0;b110=false;
 if(ent->f70==2){
  bool found=!vdc.empty9b86e0()||!vf0.empty9b86e0();
  if(!found&&rng.chance(5)){
   SiHE e7;SiQ p;int rC=ent->u5c7d30();int bC=rC;int d;
   SiVVHE groups1;si_cefc4c->u463970(ent,groups1);
   for(unsigned i=0;i<groups1.size9b9260();i++)for(unsigned j=0;j<groups1[i]->size9b9260();j++){
    e7=groups1[i]->at9b9230(j);
    if(!e7->getTarget45a760()){
     p=e7->u5c80f0(ent->u45a4c0());
     d=si_dist40a3f0(ent->u5c80f0(p),p);
     if(d<=bC&&si_cefc4c->u72a850(ent->u5c7d30(),ent,e7)&&d<=bC-e7->u5d2150(30,0)&&(e7->u5d2380(31).isNull9b65d0()||ent->getGroup45a3f0()->type9b4350()!=3)&&(!e7->isPlayer5c7600()||ent->getGroup45a3f0()->type9b4350()!=3||!si_cf45d8.u77f260(100))){found=true;goto done;}
    }
   }
  }
 done:
  if(found){
   ent->f70=0;
   do{if(si_msg5111e0(((0x81)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
   if(si_d25450.on&&ent->def9b4350()->f120>=4&&si_cefc4c->u4631f0(ent))si_d25450.u69e700(0x25,0,0.0f);
  }else{fc=1;do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}
 }
 if(ent->f70==5)do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
 if(ent->f70!=0&&ent->f70<6&&si_cefc4c->getTurn464270()>=ent->f74){
  ent->f70=0;
  if(ent->getGroup45a3f0()->type9b4350()==0)si_cefc4c->u72e4c0(ent,true);
  do{if(si_msg5111e0(((0x80)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
 }

 if(ent->getFaction45a2c0()==10&&ent->getGroup45a3f0()->type9b4350()==0&&ent->def9b4350()->f158!=si_caf164){
  SiHI it=si_cefc4c->getPlayer4630f0()->u5d35b0(ent);
  if(it.isValid()){
   if(ent->f70==7){ent->f70=0;do{if(si_msg5111e0(((0x7d)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);si_cefc4c->u72e4c0(ent,true);}
  }else if(ent->f70==0){ent->f70=7;do{if(si_msg5111e0(((0x7e)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);si_cefc4c->u72e4c0(ent,true);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}
  if(ent->getName45a280()=="Thief Drone"||ent->getName45a280()=="Minesniffer Drone"){
   if(!b56&&ent->u5c8e20(0)){if(f8>=2)f8=1;u5b94c0();}
  }else if(ent->getName45a280()=="Decoy Drone"){
   if(si_cefc4c->getTurn464270()-ent->f2c>20){u5b64d0();return 100;}
  }
 }
 if(ent->u45a9d0()&&ent->getAiType45a2a0())si_cefc4c->u464d50(ent);
 if(u459090()&&ent->getAiType45a2a0()==1)si_cefc4c->u464db0(ent);
 if(ally114)ally114->checkCapable57f1b0(ent);
 if(ent->f70!=0||f4==0){vdc.clear9b73d0();f104=0;do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}
 if(f38==-1){si_cf6434+=ent->def9b4350()->f88*si_ba65f0[si_cf4718];f38=1;}
 if(fcc>1){
  if(ent->def->f28==0x1c&&ent->def->f24!=2&&(si_cefc4c->getTurn464270()>=fcc||vf0.empty9b86e0())){
   SiVHI*inv=ent->getInventoryList45ab00();
   for(unsigned i=0;i<inv->size9b9260();i++)if((*inv)[i]->u458220()&&si_ba0968[(*inv)[i]->def9b4350()->fec])(*inv)[i]->setActive5791a0(false);
   fcc=1;
  }
  if(ent->def->f48==0x2c&&(si_cefc4c->getTurn464270()>=fcc||vf0.empty9b86e0())){
   SiVHI*inv=ent->getInventoryList45ab00();
   for(unsigned i=0;i<inv->size9b9260();i++)if((*inv)[i]->u458220()&&(*inv)[i]->def9b4350()->fec==4)(*inv)[i]->setActive5791a0(false);
   fcc=1;
  }
 }
 if(ent->getFaction45a2c0()==0x4d&&vf0.empty9b86e0()&&ent->u5cad50()==2){
  SiVHI*inv=ent->getInventoryList45ab00();
  for(unsigned i=0;i<inv->size9b9260();i++)if((*inv)[i]->u458220()&&si_ba0968[(*inv)[i]->def9b4350()->fec])(*inv)[i]->setActive5791a0(false);
  do{ent->f40++;ent->clr45b0b0();return (ent->u5cb220()*100);}while(false);
 }
 if(u458a90()&&(!fb4.operator->()||fb4->u5c7fc0(ent)!=2)||f8==9&&ent->getGroup45a3f0()->type9b4350()&&(!fb4.operator->()||fb4->u5c7fc0(ent)!=2||!fb4->u5d26e0(0xa7))){
  do{if(si_msg5111e0(((0x260)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
  (*si_cfd44c.atPoint9ced70(ent->getPosition45a4a0()))->u66b700(rng.rangeInt(1.0f,18.0f)-1,si_d29730);
  ent->u637bb0();
  return 100;
 }
 if(ent->u45ae30()&&ent->u45ae50()->u458950(0x34)&&si_cefc4c->getTurn464270()>ent->u45ae50()->u458950(0x34)->f4)ent->u45af20(0x34);
 if(p11c){
  if(p11c->u458950(0x3e)&&si_cefc4c->getTurn464270()>p11c->u458950(0x3e)->f4)u4591c0(0x3e);
  if(p11c&&p11c->u458950(0x42)&&si_cefc4c->getTurn464270()>p11c->u458950(0x42)->f4){
   SiRec*rec=p11c->u458950(0x42);
   if(ent->getGroup45a3f0()->type9b4350()==rec->v8[0].x)u4591c0(rec->type);
   else{
    int t_=si_d38830.randomInRange40c130();
    string msg="Network quickbooting "+ent->name416f40()+", ETC: "+si_intToString(t_)+".";
    do{if(si_msg5111e0(((0x1f7)),((&msg)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    ent->u5fd900(1,t_);
    ent->changeFaction5dc780(si_cefc4c->u463890(rec->v8[0].x),true);
    return 100;
   }
  }
  if(p11c&&(p11c->u458950(0x43)||p11c->u458950(0x44))&&si_dist40a3f0(ent->u45a4c0(),si_cefc4c->getPlayer4630f0()->getPosition45a4a0())>5){
   SiRec*rec=p11c->u458950(0x43);if(!rec)rec=p11c->u458950(0x44);
   if(ent->getGroup45a3f0()->type9b4350()==rec->v8[0].x)u4591c0(rec->type);
   else{
    string msg=ent->name416f40()+" outside max range, lost control.";
    do{if(si_msg5111e0(((0x1f7)),((&msg)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    int gN=rec->v8[0].x;
    ent->changeFaction5dc780(si_cefc4c->u463890(gN),true);
    return 100;
   }
  }
 }

 if(b56&&f8>=6&&!ent->u5d5250()){b56=false;goal.x=-1;}
 if(f104){
  if(vf0.empty9b86e0()&&ent->isHostileTo45aa70(si_cefc4c->getPlayer4630f0())&&!ent->u5d5250()&&!si_contains9d31e0(vdc,si_cefc4c->getPlayer4630f0())
   &&(si_dist40a3f0(ent->u5c80f0(si_cefc4c->getPlayer4630f0()->getPosition45a4a0()),si_cefc4c->getPlayer4630f0()->getPosition45a4a0())>ent->u5c7d30()
    ||!si_cefc4c->u72a850(ent->u5c7d30(),ent,si_cefc4c->getPlayer4630f0())
    ||si_dist40a3f0(ent->u5c80f0(si_cefc4c->getPlayer4630f0()->getPosition45a4a0()),si_cefc4c->getPlayer4630f0()->getPosition45a4a0())>ent->u5c7d30()-si_cefc4c->getPlayer4630f0()->u5d2150(30,0))
   &&!u5b4690(si_cefc4c->getPlayer4630f0())){
   goal=si_cefc4c->getPlayer4630f0()->getPosition45a4a0();
   if(f4==1)u4593b0(si_cefc4c->getPlayer4630f0()->getPosition45a4a0());
   si_cf6428.u6823f0(0x1b);
   if(!u581140()){
    SiVHE2*mem=ent->getGroup45a3f0()->members416f40();
    for(unsigned i=0;i<mem->size9b9260();i++){
     if((*mem)[i]->ai->vf0.empty9b86e0()&&!(*mem)[i]->ai->f58.operator->()&&(*mem)[i]->ai->f8>=6&&si_dist40a3f0(ent->getPosition45a4a0(),(*mem)[i]->getPosition45a4a0())<=f4c&&!(*mem)[i]->u5d5250()){
      (*mem)[i]->ai->goal=goal;
      if((*mem)[i]->ai->f4==1)(*mem)[i]->ai->u4593b0(goal);
     }
    }
   }
  }
  f104=0;
 }
 if(f10c<0&&!u581140())u5ba3e0();
 if(f8==7){
  if(vf0.empty9b86e0()&&ent->g28->type9b4350()!=4)ent->changeFaction5dc780(si_cefc4c->u463890(4),false);
  else if(!vf0.empty9b86e0()&&ent->g28->type9b4350()!=3)ent->changeFaction5dc780(si_cefc4c->u463890(3),false);
 }
 switch(ent->getFaction45a2c0()){
 case 2:
  if(!vdc.empty9b86e0()){
   for(unsigned i=0;i<vdc.size9b9260();i++){
    if(vdc[i].operator->()&&vdc[i]->getGroup45a3f0()->height9b8f00()<=2){
     if(u5813a0()&&rng.chance(si_b92f64[si_d1e860.getDepthIndex()])&&si_d1e888->type!=10){
      if(u581140())do{if(si_msg5111e0(((0x236)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      else si_cf6428.u682220(ent->getPosition45a4a0());
     }
     break;
    }
   }
  }
  break;
 case 38:
  if(vf0.empty9b86e0()&&rng.chance(50)&&ent->u5c8db0()){
   SiVHIl items;
   ent->u5cb830(items);
   for(unsigned i=0;i<items.size9b9260();i++){
    if(ent->u490840()<ent->u5ca260())ent->u5dea60(ent->u5ca260(),0);
    else{
     for(unsigned j=0;j<ent->v134.size9b9260();j++){
      if(ent->v134[j]->u9b6bf0()<ent->v134[j]->u457c80()){ent->v134[j]->u450460(ent->v134[j]->u457c80());goto L21ac;}
     }
     si_cefc4c->u71e7c0(ent->getPosition45a4a0(),rng.rangeInt(5.0f,20.0f),0);
    }
   L21ac:
    items[i]->remove57dbe0(0,0,true,true);
   }
   do{if(si_msg5111e0(((0x27f)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
  }
  break;
 case 26:
  if(f34&&!vdc.empty9b86e0()&&ent->g28->type9b4350()==3&&si_b90184[si_d1e888->type].b0){
   if(u581140()){
    do{if(si_msg5111e0(((0x236)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    si_d2c658.add4729d0(0x241,1,si_empty_b91d71,-1);
   }else if(ent->def9b4350()->f48==0x2f?si_cf6428.u686c60(ent->getPosition45a4a0(),3,0x17,0x7a):si_cf6428.u686c60(ent->getPosition45a4a0(),-1,0x61,0x7a)){
    si_cf6428.lastParty()->f4->ai45b590()->setFollowEntity5b2f80(ent,0);
    do{if(si_msg5111e0(((0x23d)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    do{si_cf1080.u451400(1);if(((0x127))!=-1&&!(si_d28fb0&&1&&1))si_sound4541b0((0x127),0,0);do{if(si_msg5111e0(((0x324)),((&string(("ALERT: Hostile activity reported, dispatching reinforcements to area.")))),(0),(0),((SiHE())),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);si_cec0b4->end7b4f10();}while(false);
    f34=0;
   }
  }
  break;
 case 27:
  if(vf0.empty9b86e0()&&f58.isNull9b65d0()&&ent->isHostileTo45aa70(si_cefc4c->getPlayer4630f0())){
   int r=ent->u5d22a0(0xe);
   if(r&&si_dist40a3f0(ent->getPosition45a4a0(),si_cefc4c->getPlayer4630f0()->getPosition45a4a0())<=r&&!si_cf45d8.u77f260(100)&&si_cefc4c->getPlayer4630f0()->u5d2380(0x1f).isNull9b65d0()){
    chase5b4710(si_cefc4c->getPlayer4630f0(),-1,0,0,0);
    do{if(si_msg5111e0(((0x235)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    si_cf45d8.u77fbc0(0x19a);
    si_sound4541b0(0x100,0,0);
   }
  }
 case 34:
  if(!vf0.empty9b86e0()&&rng.chance(ent->getFaction45a2c0()==27?3:6)){
   SiVHIm*inv=&ent->v134;
   for(unsigned i=0;i<inv->size9b9260();i++){
    if((*inv)[i]->u457f90()==0xa7){
     if((*inv)[i]->u45cb30()&&(*inv)[i]->u457cf0()){
      SiTgt*t=u580ec0();
      if(t){
       SiSpawnDef*d=(*inv)[i]->def9b4350()->u56f3c0();
       SiHE e;SiQ p;
       for(int n=(*inv)[i]->u45cb30();n>=1;n--){
        if(si_cefc4c->findPlaceableNear71c150(ent->getPosition45a4a0(),p,d->f9c))
         e=si_cefc4c->placeEntity6c58c0(d,p,ent->g28->type9b4350()==1?2:ent->g28->type9b4350(),0,0x22,0xe,0);
        if(e.isNull9b65d0())break;
        e->u45b2a0();
        e->ai45b590()->fb4=ent;
        u5b51b0(e);
        if(t->f4<0){SiTgt*x=e->ai45b590()->getEntity459570(t->e);if(x)x->f4=t->f4;}
        e->ai45b590()->setFollowEntity5b2f80(ent,0);
        do{if(si_msg5111e0(((0x25e)),((0)),(0),(0),((ent)),((e)),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
        (*inv)[i]->u44fc60((*inv)[i]->u45cb30()-1);
        si_454260(ent->getPosition45a4a0(),0xbd);
       }
      }
     }
     break;
    }
   }
  }
  break;
 case 29:
  for(unsigned i=0;i<ent->v30.size9b9a50();i++){
   if((*si_cfd44c.atPoint9ced70(ent->v30[i]))->getItem45d8f0().isValid()){
    do{if(si_msg5111e0(((0xb5)),((&(*si_cfd44c.atPoint9ced70(ent->v30[i]))->getItem45d8f0()->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    (*si_cfd44c.atPoint9ced70(ent->v30[i]))->u66b700(rng.rangeInt(1.0f,18.0f)-1,si_d2c46c);
    (*si_cfd44c.atPoint9ced70(ent->v30[i]))->getItem45d8f0()->remove57dbe0(0,0,true,true);
   }
  }
  break;
 case 49:{
  int mode=0;
  if(!vf0.empty9b86e0()&&!ent->isXomCandidate5d51a0())mode=1;
  else if(vf0.empty9b86e0()&&rng.chance(1))mode=2;
  if(mode){
   SiVPl cells;
   si_sweep4faaf0(ent->getPosition45a4a0(),cells);
   for(unsigned i=0;i<cells.size9b9a50();i++){
    if((*si_cfd44c.atPoint9ced70(cells[i]))->getProp45d550().isValid()&&(*si_cfd44c.atPoint9ced70(cells[i]))->getProp45d550()->height9b8f00()==si_cefbd8){
     switch(mode){
     case 1:{
      SiWL wl;
      for(unsigned j=0;j<si_d2d1c4.size9b9260();j++)if(si_d2d1c4[j]->f48==3&&si_d2d1c4[j]->f40==0x1b)wl.add9ba310(si_d2d1c4[j],si_d2d1c4[j]->f60);
      if(wl.u9b81d0()){
       ent->u5de480(wl.pick9ba470());
       do{if(si_msg5111e0((0x27b),(&ent->v134.back9b6540()->getName571db0(0,0)),(&(*si_cfd44c.atPoint9ced70(cells[i]))->getProp45d550()->getName45c5b0()),(0),(ent),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
       si_454260(ent->getPosition45a4a0(),0xb1);
       si_cec054->u49ada0(si_caed20+2000);
       if(b56){b56=false;goal.x=-1;}
      }
     }
      break;
     case 2:{
      bool vC=rng.chance(25);
      string verb;
      if(vC){
       switch(rng.rangeInt(0.0f,5.0f)){
       case 0:verb="rummages through the";break;
       case 1:verb="shifts around the";break;
       case 2:verb="sifts through the";break;
       case 3:verb="searches inside the";break;
       case 4:verb="scatters some of the";break;
       case 5:verb="uncovers a bit of";break;
       }
      }else{
       switch(rng.rangeInt(0.0f,4.0f)){
       case 0:verb="toys with the";break;
       case 1:verb="plays with the";break;
       case 2:verb="fiddles with the";break;
       case 3:verb="pokes at the";break;
       case 4:verb="examines a few pieces of the";break;
       }
      }
      do{if(si_msg5111e0((0x27c),(&verb),(&(*si_cfd44c.atPoint9ced70(cells[i]))->getProp45d550()->getName45c5b0()),(0),(ent),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      si_454260(ent->getPosition45a4a0(),vC?0xb2:0xb1);
      if(vC){
       SiPropDef*pd;
       si_lookup9d7980("P_Machinery_Spill",pd);
       if(pd){
        for(unsigned j=0;j<cells.size9b9a50();j++){
         if(si_cefc4c->isVisible4631c0(cells[j])&&rng.chance(50)&&(*si_cfd44c.atPoint9ced70(cells[j]))->isPassableFor66ab30(SiHE()))
          si_cefc50->u508610(si_cefc50,pd,cells[j],&si_d2e20c,0,0,0,9,0)->init503b20();
        }
       }
      }
     }
      break;
     }
     break;
    }
   }
  }
 }
  break;
 case 58:
  if(ent->u5d0fe0()){
   if(!ally114&&!si_cefc4c->u4631f0(ent)){ent->u637bb0();return 100;}
   if(f8>=2)f8=ally114==0;
   if(ally114&&ent->u5c8820(si_cefc4c->getPlayer4630f0())){
    SiVHIl items;ent->u5cb830(items);
    for(unsigned i=0;i<items.size9b9260();i++)if(!items[i]->getEffect457b70(0x41))ent->u642940(items[i],0,0,0,0);
    f8=si_bba140;
   }
  }
  break;
 case 94:
  if(si_cefc4c->getTurn464270()%5==0&&!si_stringToInt405610(si_d1e860.getEntryText46f6d0("sigixAcquiredShearcannon_g"))){
   SiArea r;
   si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),12,r);
   for(int x=r.x1;x<=r.x2;x++)for(int y=r.y1;y<=r.y2;y++){
    if((*si_cfd44c.at9ceda0(x,y))->getItem45d8f0().isValid()&&(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->name457860()=="Sigix Shearcannon"&&(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u457d70()
     &&(ent->getPosition45a4a0().eq409cb0(x,y)||si_cefc4c->isReachable465230(9999,SiP(x,y),ent->getPosition45a4a0())&&si_cefc4c->u7178d0(SiHE(),SiP(x,y),&si_d2e20c,ent->getPosition45a4a0(),&si_d2e20c,0))){
     SiP p(x,y);
     SiHI it=(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0();
     if(si_cefc4c->isVisible4631c0(p)){
      string msg=it->getName571db0(0,0)+" flies over to "+ent->name416f40()+".";
      si_message49c610(0x320,SiHE(),&msg,0);
     }
     si_cefc4c->u6c65a0(ent,"SEC_Sigix_Shearcannon",0);
     if(p.eq409b90(ent->getPosition45a4a0()))it->u57a190(ent,it->u4578a0(),1,0);
     else{
      it->u57a0c0();
      SiP dst(ent->getPosition45a4a0());
      SiThrowDef*b5;
      if(si_lookupT9d7980("Thrown_Item",b5)){
       SiVHE3*path=0;
       SiSecDef*sd;
       if(si_findByName9d7de0(si_d2c408,"SEC_Sigix_SC_Comment",sd)){
        path=new SiVHE3;
        path->push_back9b9280(new SiRect(sd,ent,0,ent));
       }
       SiQ aJ,b;
       bool e5;
       if(si_cefc4c->isVisible4631c0(p))e5=false;
       else if(si_cefc4c->u717e40(p,dst,9999,aJ,b,0,0))e5=false;
       else if(b5->u5012a0(p))e5=false;
       else e5=true;
       if(e5){
        si_cefc4c->setFlagA74_4654d0(true);
        si_cefc4c->thrownItemArrived7499f0(SiHE(),it,2,dst,path);
        delete path;
        si_cefc4c->setFlagA74_4654d0(false);
       }else{
        si_cefc50->u508610(si_cefc50,b5,p,&si_d2e20c,&dst,&si_d2e20c,new SiObj500(0,SiHE(),0,9999,0.0f,SiHE(),it,2,SiHE(),0,path,0),9,0)->init503b20();
       }
      }
     }
     return 100;
     goto L3f14;
    }
   }
  L3f14:;
  }
  break;
 case 95:
  if(ent->getPosition45a4a0().ne409cf0(0x72,0x49)&&rng.chance(5)&&!si_stringToInt405610(si_d1e860.getEntryText46f6d0("comMaincReinforced_g"))&&!si_cefc4c->u716940(ent->getPosition45a4a0(),SiP(0x72,0x49),ent.operator->(),0))
   si_cefc4c->u747860(0,1);
  if(si_stringToInt405610(si_d1e860.getEntryText46f6d0("comHackedMainc_g"))&&rng.chance(66)){do{if(si_msg5111e0(((0x299)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);return 100;}
  break;
 case 79:case 80:case 81:case 82:case 83:case 85:case 96:
  if(si_d1e888->type==0x23&&si_cefc4c->getPlayer4630f0()->isHostileTo45aa70(ent)){
   bool b=ent->getFaction45a2c0()==0x60;
   if(b&&rng.chance(50))f8=f8==si_bba1d8?12:si_bba1d8;
   SiVHE2*mem=si_cefc4c->u463890(1)->members416f40();
   for(unsigned i=0;i<mem->size9b9260();i++){
    if(((*mem)[i]->getName45a280().find("Enhanced")!=string::npos||b&&(*mem)[i]->getName45a280().size()==2&&(*mem)[i]->getName45a280()[0]=='A')&&si_cefc4c->isReachable465230(ent->u5c7d30(),ent->getPosition45a4a0(),(*mem)[i]->getPosition45a4a0())){
     if(si_cefc4c->u4631f0(ent))do{if(si_msg5111e0(((0x320)),((&string("[name] flashes a signal at {name}."))),(0),(0),((ent)),(((*mem)[i])),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     if(si_cefc4c->u4631f0((*mem)[i]))do{if(si_msg5111e0(((0x320)),((&string("[name] self-destructs."))),(0),(0),(((*mem)[i])),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     if(b&&(*mem)[i]->getName45a280().find("Enhanced")==string::npos)(*mem)[i]->removeEffectsA639730(0);
     (*mem)[i]->die633790(!si_cefc4c->u4631f0((*mem)[i]),10,SiHE(),1,0,0,0,0);
     i--;
    }
   }
   if(si_stringToInt405610(si_d1e860.getEntryText46f6d0("ac0RanGateTestB_g"))&&!si_stringToInt405610(si_d1e860.getEntryText46f6d0("ac0GateDisabled_g"))&&rng.chance(50)&&!ent->u45aaa0(si_cefc4c->getPlayer4630f0())){
    SiArea i8;
    si_cfd44c.getRect9b4430(si_d1ec6c,10,i8);
    SiVPl pts;
    for(int x=i8.x1;x<=i8.x2;x++)for(int y=i8.y1;y<=i8.y2;y++)
     if((*si_cfd44c.at9ceda0(x,y))->getProp45d550().isValid()&&(*si_cfd44c.at9ceda0(x,y))->getProp45d550()->tag45c590()=="AC0_Singularity_Gate")pts.push_back9b3020(SiP(x,y));
    si_shuffle9d7350(pts);
    for(unsigned k=0;k<pts.size9b9a50();k++){
     if(si_cefc4c->u465200(ent->getPosition45a4a0(),pts[k])){
      if(!si_stringToInt405610(si_d1e860.getEntryText46f6d0("ac0ArchitectShotAtGate_g"))&&si_cefc4c->u4631f0(ent)){
       si_message49c610(0x322,ent,&string("[name]: \"Are you insane?!\""),0);
       si_d1e860.setEntryText46f700("ac0ArchitectShotAtGate_g","1");
      }
      SiQ q;SiVPl b7;SiVX v2;SiVX a5;
      bool fail=!si_cefc4c->u7170a0(ent,pts[k],b7,v2,a5,q,0,4,1,1);
      if(!fail){
       int j4=1;
       SiVHIl items9;
       ent->u5d6a80(items9,pts[k],-1);
       if(items9.empty9b86e0())continue;
       int total=0;
       for(unsigned m=0;m<items9.size9b9260();m++)total+=items9[m]->u5788e0();
       if(total>ent->u45a8d0())ent->u5ded70(ent->u45a8d0());
       total=0;
       for(unsigned m=0;m<items9.size9b9260();m++)total+=items9[m]->u5789c0();
       if(total>ent->u45a920())ent->u5deb40(total);
       ent->f40++;ent->clr45b0b0();
       int aG;
       SiVE8 v;
       si_cefc4c->addRecord777a20(si_cefaa8->createA7930e0(new SiShoot(ent,j4,pts[k],q,aG,v,0,SiHE())));
       return aG;
      }
     }
    }
   }
   if(b&&si_dist40a3f0(*(*si_cefc4c->u462e10())[0],si_cefc4c->getPlayer4630f0()->getPosition45a4a0())<=15&&!si_cefc4c->u4631f0(ent)){
    do{si_cf1080.u451400(1);if(((-1))!=-1&&!(si_d28fb0&&1&&1))si_sound4541b0((-1),0,0);do{if(si_msg5111e0(((0x324)),((&string(("A0_RES: I have more important things to do than play hide-and-seek. Deal with this piece of junk if it returns.")))),(0),(0),((SiHE())),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);si_cec0b4->end7b4f10();}while(false);
    ent->u637bb0();
    return 100;
   }
  }
  break;
 }

 for(unsigned i=0;i<ent->v134.size9b9260();i++)u5b57a0(ent->v134[i],0);
 switch(ent->getFaction45a2c0()){
 case 14:
  for(unsigned i=0;i<ent->v134.size9b9260();i++){
   if(ent->v134[i]->u4578a0()==1&&ent->v134[i]->u458180())ent->v134[i]->setOverload579940(!vf0.empty9b86e0()&&ent->v134[i]->u9b6bf0()>=5);
  }
  break;
 case 26:
  if((f3c==-1||si_cefc4c->u4642d0()>=f3c)&&ent->getGroup45a3f0()->type9b4350()==3){
   if(si_cf45d8.u77f260(100)||si_cefc4c->getPlayer4630f0()->u5d2380(0x1f).isValid())goto L531d;
   else{
    int n=ent->u5d22a0(0xd);
    if(n-=2){
     if((f3c==-1||rng.chance(2))&&!getEntity459570(si_cefc4c->getPlayer4630f0())&&si_cefc4c->u716080(ent))reinforce5b3a30(n);
    }
   }
  }
  L531d:
  if(!vf0.empty9b86e0())si_cf6428.u68d920(0);
  break;
 case 66:
  if(ent->u45ac40(0x3a)&&(ent->getName45a280()[0]=='C'||ent->getName45a280()[0]=='G')){
   if(ent->getName45a280()[0]=='C'){
    SiVHIl items;ent->u5d6c30(items);
    if(!items.empty9b86e0()){
     si_shuffle9d9fc0(items);
     for(unsigned i=1;i<items.size9b9260();i++)items[i]->setActive5791a0(false);
    }
   }else if(ent->u5d5250())si_d25450.giveXomItems6be2f0(ent);
  }
  break;
 case 69:
  if(ent==si_cf68b8){
   switch(si_cf68b4->f110){
   case 1:
    u5b5830(1);
    if(ent->u5d2380(8).isNull9b65d0()){
     if(ent->u5d5b20().isValid())ent->u5d5b20()->setBroken5795b0(-2,0);
     si_cf6888.resetAI699a00(1);
     do{ent->f40++;ent->clr45b0b0();return (0x21);}while(false);
    }
    break;
   case 5:
    if(f4==0x1d&&!vdc.empty9b86e0()&&(fa0==0||si_cefc4c->getTurn464270()>=fa0+5)&&ent->u5d2380(0xac).isValid()){
     SiQ p;
     if(si_cefc4c->u74d420(ent->getPosition45a4a0(),p)){
      fa0=si_cefc4c->getTurn464270();
      SiSpawnDef*d=si_cf2974.pick9ba470();
      SiHE e=si_cefc4c->placeEntity6c58c0(d,p,ent->getGroup45a3f0()->type9b4350(),0,0x22,0xe,0);
      if(e.isValid()){
       if(si_cf68b4&&ent.operator->()&&si_cf68b8==ent)si_cf68f0->u672f20(ent,0xe,0,e->name416f40());
       do{if(si_msg5111e0(((ent->isHostileTo45aa70(si_cefc4c->getPlayer4630f0())?0x28e:0x28d)),((&ent->name416f40())),(0),(0),((e)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
       si_454260(e->getPosition45a4a0(),0xc2);
      }
     }
    }
    break;
   case 6:
    if(si_cf6a1c){
     if(si_cefc4c->u4631f0(ent)||!vdc.empty9b86e0()||si_cefc4c->getTurn464270()>=abs(si_cf6a18)+50)si_cf6a1c=false;
     if(si_cf6a1c){
      SiTgt*t=u580ec0();
      if(t&&si_dist40a3f0(t->e->getPosition45a4a0(),si_cf6a10)>5)si_cf6a1c=false;
     }
    }
    if(si_cf6a1c)do{ent->f40++;ent->clr45b0b0();return (0x21);}while(false);
    break;
   }
  }
  break;
 case 71:
  if(rng.chance(15)&&!ent->u5d1280(0))u5bd680();
  break;
 case 73:
  if(si_cefc4c->getTurn464270()%10==0)u5b2d10();
  if(si_cf462c==7||si_cf462c==6&&rng.chance(10)){
   SiHI newBest;
   int bestScore=0;
   bool flag=false;
   SiPlan dA(ent,0);
   int n9;
   for(unsigned i=0;i<ent->v134.size9b9260();i++){
    if(ent->v134[i]->getType44aec0()==4){
     n9=dA.score581e70(ent->v134[i],0);
     if(n9>bestScore){newBest=ent->v134[i];bestScore=n9;}
    }
   }
   if(newBest.isNull9b65d0()){
    for(unsigned i=0;i<ent->v134.size9b9260();i++){
     if(!ent->v134[i]->u457d70()||ent->v134[i]->getEffect457b70(0x56)||si_cf462c==7&&!ent->v134[i]->def9b4350()->b274){newBest=ent->v134[i];flag=true;break;}
    }
   }
   if(newBest.isValid()){
    do{if(si_msg5111e0(((0x301)),((&newBest->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    if(flag&&si_cefb48)si_cefb48->say49e250(0x38,0,newBest->getName571db0(0,0));
    SiQ dst;
    if(si_cefc4c->u71bc10(ent->getPosition45a4a0(),dst)){
     newBest->u57a0f0(dst,1,0);
     si_cf46b4.push_back9b80b0(newBest);
     si_cf46c4.push_back9b9280(si_cefc4c->getTurn464270()+20);
    }else newBest->remove57dbe0(0,0,true,true);
    do{ent->f40++;ent->clr45b0b0();return (si_b95fc0);}while(false);
   }
  }
  if(si_cf462c==7||si_cf462c==6&&rng.chance(50)){
   SiVI2 slots;
   ent->u5c93d0(slots);
   if(si_anyNonZero9d7f70(slots)){
    SiVHI*inv=ent->getInventoryList45ab00();
    SiHI best0;
    int bestScore=0;
    int cap=ent->u5c8d80(si_ba7ac8[ent->u5d1390()]);
    cap-=ent->u5c8cb0();
    SiPlan aK(ent,1);
    int sc;
    for(unsigned s=0;s<slots.size9b9260();s++){
     if(slots[s]){
      for(unsigned i=0;i<inv->size9b9260();i++){
       if((*inv)[i]->getType44aec0()==4&&(*inv)[i]->u4578a0()==s&&(*inv)[i]->u4578c0()<=slots[s]&&(*inv)[i]->u457b30()<=cap){
        sc=aK.score581e70((*inv)[i],0);
        if(sc>bestScore){best0=(*inv)[i];bestScore=sc;}
       }
      }
     }
    }
    if(best0.isValid()){
     best0->u57a190(ent,best0->u4578a0(),0,0);
     if(si_cf462c==7)si_d2c658.add4729d0(0x44b,1,si_empty_b91d72,-1);
     do{if(si_msg5111e0(((0x302)),((&best0->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     u5b57a0(best0,0);
     do{ent->f40++;ent->clr45b0b0();return (si_b95fb4);}while(false);
    }else if(si_cefb48&&si_cefb48->canSay49e120(8)){
     int k;
     do k=si_randomIndex9d9b20(slots);while(!slots[k]);
     if(!ent->u5cc850(k))si_cefb48->say49e250(8,1,si_d37cc0[k]);
    }
   }
  }
  if((si_cf462c==7||si_cf462c==6&&rng.chance(15))&&!ent->u5d1280(0)){
   SiVHIl curItems;
   ent->u5cb8b0(curItems);
   SiVI5 a(5,0);
   SiVI5 b(5,0);
   for(unsigned i=0;i<curItems.size9b9260();i++){
    if(curItems[i]->u4578a0()==1){
     int t=curItems[i]->u457880()-9;
     a[t]+=curItems[i]->u4578c0();
     b[t]+=curItems[i]->u577e60();
    }
   }
   if(si_fn9db9d0(a,si_fn9d4340(a))==1)ent->u5df740(si_fn9d4500(a));
   else ent->u5df740(si_fn9d4500(b));
   if(si_fn9d8ed0(a)>1){
    int slot=ent->u5d1390()+9;
    for(unsigned i=0;i<ent->v134.size9b9260();i++){
     if(ent->v134[i]->u457880()==slot&&ent->v134[i]->getType44aec0()==4&&ent->v134[i]->u4578c0()==1){
      for(unsigned j=0;j<curItems.size9b9260();j++){
       if(curItems[j]->u4578a0()==1&&curItems[j]->u457880()!=slot){
        curItems[j]->u57a190(ent,4,0,1);
        do{if(si_msg5111e0(((0x303)),((&ent->v134[i]->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
        ent->v134[i]->u57a190(ent,ent->v134[i]->u4578a0(),0,0);
        u5b57a0(ent->v134[i],0);
        if(si_cf462c==7)si_d2c658.add4729d0(0x44b,1,si_empty_b91d73,-1);
        do{ent->f40++;ent->clr45b0b0();return (si_b95fbc);}while(false);
       }
      }
     }
    }
   }
   if(ent->u45a7e0()>si_ba7ac8[ent->u5d1390()]){
    for(unsigned i=0;i<curItems.size9b9260();i++)if(!curItems[i]->u457b30())si_eraseStep9d6440(curItems,i);
    SiHI pick;
    for(unsigned i=0;i<curItems.size9b9260();i++)
     if(curItems[i]->u4578a0()==2&&curItems[i]->u457880()!=0x12&&curItems[i]->u457f90()!=7&&(pick.isNull9b65d0()||curItems[i]->u457940()>pick->u457940()))pick=curItems[i];
    if(pick.isNull9b65d0()){
     for(unsigned i=0;i<curItems.size9b9260();i++)
      if(curItems[i]->u457f90()!=7&&(pick.isNull9b65d0()||curItems[i]->u457940()>pick->u457940()))pick=curItems[i];
     if(pick.isNull9b65d0()){
      int cnt=0;
      for(unsigned i=0;i<curItems.size9b9260();i++)
       if(curItems[i]->u4578a0()==0&&(pick.isNull9b65d0()||curItems[i]->u457940()>pick->u457940())){pick=curItems[i];cnt++;}
      if(cnt==1)pick.reset9b7270();
      if(pick.isNull9b65d0()){
       cnt=0;
       for(unsigned i=0;i<curItems.size9b9260();i++)
        if(curItems[i]->u4578a0()==3&&(pick.isNull9b65d0()||curItems[i]->u457940()<pick->u457940())){pick=curItems[i];cnt++;}
       if(cnt==1)pick.reset9b7270();
       if(pick.isNull9b65d0()){
        for(unsigned i=0;i<curItems.size9b9260();i++)
         if(pick.isNull9b65d0()||curItems[i]->u457940()>pick->u457940())pick=curItems[i];
       }
      }
     }
    }
    if(pick.isValid()){
     if(ent->u45a810()>=pick->u4578c0()){
      do{if(si_msg5111e0(((0x2ff)),((&pick->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      pick->u57a190(ent,4,0,1);
      do{ent->f40++;ent->clr45b0b0();return (si_b95fb8);}while(false);
     }else{
      SiQ dst;
      if(si_cefc4c->u71bc10(ent->getPosition45a4a0(),dst)){
       do{if(si_msg5111e0(((0x301)),((&pick->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
       pick->u57a0f0(dst,1,0);
       do{ent->f40++;ent->clr45b0b0();return (si_b95fc0);}while(false);
      }
     }
    }
   }
  }
  if(si_cf462c==7){
   if(!si_cf46b4.empty9b86e0()){
    int turn=si_cefc4c->getTurn464270();
    for(int i=si_cf46b4.size9b9260()-1;i>=0;i--){
     if(turn>=si_cf46c4[i]){si_eraseAt9da940(si_cf46b4,i);si_removeVectorElement9de6f0(si_cf46c4,i);}
    }
   }
   if(f58.operator->()&&f58->isPlayer5c7600()&&rng.chance(10)){
    SiHI it;
    if(f58->u5cc5d0(0)&&ent->u5cc7c0(0)&&ent->u5cc6a0(0,it,0x1f)){}
    else if(f58->u5cc5d0(1)&&ent->u5cc7c0(1)&&ent->u5cc6a0(1,it,f58->u5d1390()+9)){}
    else if(f58->u5cc5d0(3)&&ent->u5cc7c0(3))ent->u5cc6a0(3,it,0x1f);if(0){}
    if(it.isValid()){
     SiQ dst;
     if(si_cefc4c->u71bc10(ent->getPosition45a4a0(),dst)){
      do{if(si_msg5111e0(((0x301)),((&it->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      it->u57a0f0(dst,1,0);
      si_cf46b4.push_back9b80b0(it);
      si_cf46c4.push_back9b9280(si_cefc4c->getTurn464270()+20);
      if(si_cefb48)si_cefb48->say49e250(0x39,0,it->getName571db0(0,0));
      do{ent->f40++;ent->clr45b0b0();return (si_b95fc0);}while(false);
     }
    }
   }
   if(vf0.size9b9260()>=4){
    SiHI x;
    for(unsigned i=0;i<ent->v134.size9b9260();i++){
     if(ent->v134[i]->u457880()==0x18&&ent->v134[i]->getType44aec0()==4&&ent->v134[i]->u4578c0()==1){
      bool has=false;
      for(unsigned j=0;j<ent->v134.size9b9260();j++)
       if(ent->v134[j]->u457880()==0x18&&ent->v134[j]->getType44aec0()==3){has=true;break;}
      if(!has){
       int near=1;
       for(unsigned a=0;a<vf0.size9b9260();a++){
        for(unsigned b=1;b<vf0.size9b9260();b++){
         if(si_dist40a3f0(vf0[a]->e->getPosition45a4a0(),vf0[b]->e->getPosition45a4a0())<=3){near++;break;}
        }
        if(near>=4)break;
       }
       if(near>=4){
        for(unsigned k=0;k<ent->v134.size9b9260();k++){
         if(ent->v134[k]->getType44aec0()==3&&ent->v134[k]->u4578c0()==1){
          SiHI p1=ent->v134[i];
          SiHI p2=ent->v134[k];
          p2->u57a190(ent,4,0,1);
          do{if(si_msg5111e0(((0x303)),((&p1->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
          p1->u57a190(ent,p1->u4578a0(),0,0);
          u5b57a0(p1,0);
          if(si_cefb48)si_cefb48->say49e250(0x19,0,p1->getName571db0(0,0));
          if(si_cf462c==7)si_d2c658.add4729d0(0x44b,1,si_empty_b91d7e,-1);
          do{ent->f40++;ent->clr45b0b0();return (si_b95fbc);}while(false);
          break;
         }
        }
       }
      }
      break;
     }
    }
   }
  }
  if(si_cefb48)comment5bd7d0();
  break;
 }

 if(ent->getPosition45a4a0().eq409b90(goal)){
  if(b56){
   if(si_cefc4c->isVisible4631c0(goal)&&!si_cefc4c->getPlayer4630f0()->u45aaa0(ent))u5b94c0();
   else{
    do{}while(false);
    b56=false;goal.x=-1;
    if(ent->getName45a280()=="Decoy Drone"){u5b64d0();return 100;}
   }
  }else goal.x=-1;
 }
 if(!vf0.empty9b86e0()){
  for(int i=vf0.size9b9260()-1;i>=0;i--){
   if(ent->u45aaa0(vf0[i]->e)||!si_caf210[vf0[i]->e->getTarget45a760()]&&!vf0[i]->e->u45ac40(0x1c)){
    if(vf0[i]->e->isPlayer5c7600())f108=0;
    si_deleteObject9d8f20(vf0,i);
    continue;
   }
   if(vf0[i]->f4>0){
    vf0[i]->f4--;
    if(ent->u45a9d0()>=10)si_fn9d0690(&vf0[i]->f4,ent->u45a9d0()/10,0);
    si_fn9d0690(&vf0[i]->f4,vf0[i]->e->u5d2090(0x13),0);
   }
   if(vf0[i]->f4==0){
    if(f8>=6&&vf0[i]->e==si_cefc4c->getPlayer4630f0()){
     if(ent->getGroup45a3f0()->type9b4350()==3){
      if(vf0[i]->e->u5d2380(0x13).isNull9b65d0())si_cf6428.u682420(0x1c,0);
      else if(vf0[i]->e->isPlayer5c7600())si_d2c658.add4729d0(0x246,1,si_empty_b91d7f,-1);
     }
     if(si_cefc4c->getTurn464270()>=si_cf655c){si_d2c658.add4729d0(0x245,1,si_empty_b91d89,-1);si_cf655c=si_cefc4c->getTurn464270()+15;}
    }
    if(vf0.size9b9260()==1&&ent->getFaction45a2c0()==0x18&&ent->getAiType45a2a0()==1&&fb4.isNull9b65d0()&&f58.isNull9b65d0()&&ent->g28->type9b4350()==3){
     SiSpawnDef*d=0;
     for(unsigned k=0;k<si_d25de0.size9b9260();k++)if(si_d25de0[k]->f28==10&&si_d25de0[k]->f24==1){d=si_d25de0[k];break;}
     if(!d){}
     else{
      fb4=si_cefc4c->placeEntity6c58c0(d,ent->getPosition45a4a0(),3,0,0x22,0xe,0);
      if(fb4.isValid()){
       fb4->ai45b590()->fb4=ent;
       fb4->ai45b590()->goal=vf0[i]->e->getPosition45a4a0();
       do{if(si_msg5111e0(((0x25e)),((0)),(0),(0),((ent)),((fb4)),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
       si_454260(ent->getPosition45a4a0(),0xbd);
      }
     }
    }
    if(vf0[i]->e->isPlayer5c7600())f108=0;
    si_deleteObject9d8f20(vf0,i);
   }else{
    if(vf0[i]->f8>0){
     si_fn9d0690(&vf0[i]->f8,2,0);
     if(!vf0[i]->e->isXomCandidate5d51a0())si_fn9d0690(&vf0[i]->f8,10,0);
    }else if(fbc>1&&vf0[i]->f8<0&&si_cefc4c->getTurn464270()%8==0)vf0[i]->f8=0;
   }
  }
 }

 if(!vdc.empty9b86e0()&&ent->fec&&ent->fec->hasType456490(0x11)){
  SiHE self=ent;
  if(si_fn4569a0(0x11,ent,SiHE(),SiHE(),SiHE(),0,0,ent->fec,ent,SiHE(),SiHE(),0)&&!self.operator->())return 100;
 }
 if(f58.operator->()&&f58->isPlayer5c7600()&&ent->u45aaa0(f58)){
  SiP p(-1);
  if((*si_cfd44c.atPoint9ced70(f58->getPosition45a4a0()))->isMachinePart45dcd0())p=f58->getPosition45a4a0();
  else{
   SiVPl cells;
   si_sweep4faaf0(f58->getPosition45a4a0(),cells);
   for(unsigned i=0;i<cells.size9b9a50();i++)if((*si_cfd44c.atPoint9ced70(cells[i]))->isMachinePart45dcd0()){p=cells[i];break;}
  }
  if(p.x!=-1&&!ent->u5c83d0(p,7)){
   f68=0;
   if(goal.x!=-1&&ent->u5c8430(goal,p,7)&&!(*si_cfd44c.atPoint9ced70(goal))->u66b3d0(ent.operator->()))do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   goal=p;
   do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
  }
 }
 if(f60&&f58.operator->()){
  if(ent->isHostileTo45aa70(f58))f60=0;
  else if(si_dist40a3f0(ent->getPosition45a4a0(),f58->getPosition45a4a0())>si_bb9ec4[f60]||f58->isPlayer5c7600()&&!si_cefc4c->u463400(ent)){
   f68=0;
   if(goal.x!=-1&&abs(goal.x-f58->getPosition45a4a0().x)<3&&abs(goal.y-f58->getPosition45a4a0().y)<3&&(!f58->isPlayer5c7600()||!(*si_cfd44c.atPoint9ced70(goal))->u66b3d0(ent.operator->())))do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   if(u5b9860()){do{}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
  }
 }

 if(ally114){
  switch(ally114->f4){
  case 10:
   if(ent->u5c8820(si_cefc4c->getPlayer4630f0())){
    int idx=0;
    SiHI h=si_cefc4c->getPlayer4630f0()->u5d2d60(ent,&idx);
    if(idx==-1){
     do{if(si_msg5111e0(((0x282)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     u5b5380(new SiPropPoints(2,si_cefc4c->getPlayer4630f0(),SiP(-1)));
     do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
    }
    if(h.isValid()){
     if(ent->getName45a280()=="Thief Drone"||ent->getName45a280()=="Minesniffer Drone"){
      SiVHIl items;
      if(ent->u5cb830(items)){
       int budget=si_cefc4c->getPlayer4630f0()->u45a810();
       for(unsigned i=0;i<items.size9b9260();i++){
        do{if(si_msg5111e0(((0x284)),((&items[i]->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
        if(budget>=items[i]->u4578c0()){
         items[i]->u57a190(si_cefc4c->getPlayer4630f0(),4,1,0);
         budget-=items[i]->u4578c0();
        }else{
         SiQ dst;
         if(si_cefc4c->u71bc10(si_cefc4c->getPlayer4630f0()->getPosition45a4a0(),dst))items[i]->u57a0f0(dst,0,0);
        }
       }
      }
     }
     if(idx)h->u458310(idx);
     string s=idx?"repair cost: "+si_intToString(idx):string("no repairs");
     do{if(si_msg5111e0((0x281),(&h->getName571db0(0,0)),(&s),(0),(ent),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     h->u44fc60(h->u45cb30()+1);
     SiCPart*cp=si_cec088->u894e70(h);
     if(cp){
      cp->u4a8fc0();
      if(idx)cp->drawStatus4a8e70(1);
      if(h->u457cf0())si_cec088->toggle8993e0(cp,0);
     }else si_cec08c->reopen8a2ce0(5,h);
     si_454260(si_cefc4c->getPlayer4630f0()->getPosition45a4a0(),0xbe);
     si_d2c658.add4729d0(0x3d2,1,si_empty_b91d8a,-1);
     if(ent->def9b4350()->b15c){
      for(int g=3;g<15;g++){
       if(ent->u5cb680(si_cefc4c->u463890(g))){
        SiVHE2*mem=si_cefc4c->u463890(g)->members416f40();
        for(unsigned k=0;k<mem->size9b9260();k++)
         if((*mem)[k]->ai45b590()->getEntity459570(ent))(*mem)[k]->ai45b590()->chase5b4710(si_cefc4c->getPlayer4630f0(),1,0,0,0);
       }
      }
     }
     ent->u637bb0();
     return 100;
    }
   }
   if(goal.ne409bd0(si_cefc4c->getPlayer4630f0()->getPosition45a4a0()))goal=si_cefc4c->getPlayer4630f0()->getPosition45a4a0();
   do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
  }
 }

 if(p118&&p118->f0==1){
  bool done=false;
  if(si_cefc4c->getTurn464270()>p118->f4||(*si_cfd44c.atPoint9ced70(p118->p10))->getItem45d8f0().isNull9b65d0()||(*si_cfd44c.atPoint9ced70(p118->p10))->getItem45d8f0()->def9b4350()!=si_cefbec)done=true;
  else{
   SiHI mine=ent->u5cc8e0();
   if(mine.isValid()){
    if(ent->getPosition45a4a0().eq409b90(p118->p10)){
     done=true;
     SiHE self=ent;
     SiHI k5=(*si_cfd44c.atPoint9ced70(p118->p10))->getItem45d8f0();
     int n=si_minInt9cdb30(k5->u9b6bf0(),mine->u457cd0());
     mine->u458360(n);
     si_454260(self->getPosition45a4a0(),0xbc);
     do{if(si_msg5111e0((ent->isHostileTo45aa70(si_cefc4c->getPlayer4630f0())?0x188:0x187),(&k5->getName571db0(0,0)),(&mine->getName571db0(0,0)),(&si_intToString(n)),(self),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     k5->remove57dbe0(0,0,true,true);
     do{ent->f40++;ent->clr45b0b0();return (100);}while(false);
    }else{
     goal=p118->p10;
     do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
    }
   }else done=true;
  }
  if(done){delete p118;p118=0;}
 }
 if(isSpotterOfThree57ef20()&&!vf0.empty9b86e0()&&(f10c==0||f10c>0&&si_cefc4c->getTurn464270()>f10c+50)){
  bool seen=false;
  bool player=false;
  if(!vdc.empty9b86e0())seen=true;
  else for(unsigned i=0;i<vf0.size9b9260();i++){
   if(vf0[i]->e->isXomCandidate5d51a0()&&si_cefc4c->isReachable465230(ent->u5c7d30(),ent->getPosition45a4a0(),vf0[i]->e->getPosition45a4a0())){
    seen=true;
    if(vf0[i]->e->isPlayer5c7600()){player=true;break;}
   }
  }
  if(seen){
   do{if(si_msg5111e0(((0x23c)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
   if(player)si_cf45d8.u77fbc0(0x4a);
   if(si_cefc4c->u4631f0(ent))si_cec054->u80e0e0(ent);
   if(u581140()){
    f10c=-1;
    si_d2c658.add4729d0(0x241,1,si_empty_b91d8b,-1);
    do{if(si_msg5111e0(((0x23b)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    if((*si_d2c658.v)[0x241]==10)si_cf45d8.u77fbc0(0x72);
    b56=true;goal.x=-1;
   }else f10c=-2;
   do{ent->f40++;ent->clr45b0b0();return (200);}while(false);
  }
 }
 if(!b56&&f8){
  if(!vdc.empty9b86e0()){
   switch(f8){
   case 1:
    b56=true;
    switch(ent->getFaction45a2c0()){
    case 5:
     if(goal.x!=-1&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0().isValid()&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0()->u457e70()){
      for(unsigned i=0;i<vdc.size9b9260();i++)if(vdc[i]->isPlayer5c7600()){
       si_d2c658.add4729d0(0xd7,1,si_empty_b91d9e,-1);
       if((*si_d2c658.v)[0xd7]==5)si_cf45d8.u77fbc0(0xc);
       break;
      }
     }
     break;
    case 4:
     if(f34&&ent->g28->type9b4350()==4&&si_d1e860.getDepthIndex()>=4){
      SiHI c5=ent->u5d2380(0x16);
      SiHI b=si_cefc4c->getPlayer4630f0()->u5d2380(0x16);
      if(b.isNull9b65d0())b=si_cefc4c->getPlayer4630f0()->u5d2380(0x17);
      bool handled;
      if(u581140()){
       if(c5.isNull9b65d0()){do{if(si_msg5111e0(((0x236)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);handled=true;}
       else if(c5.isValid()&&b.isNull9b65d0()){do{if(si_msg5111e0(((0x237)),((&c5->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);handled=false;}
       else if(c5.isValid()&&b.isValid()){
        si_d2c658.add4729d0(0x241,1,si_empty_b91d9f,-1);
        do{if(si_msg5111e0(((0x238)),((&c5->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
        if((*si_d2c658.v)[0x241]==10)si_cf45d8.u77fbc0(0x72);
        handled=true;
       }
      }else handled=false;
      if(!handled&&si_cf6428.u686c60(ent->getPosition45a4a0(),-1,0x61,0x7a)){
       si_d2c658.add4729d0(0x23c,1,si_empty_b91dc2,-1);
       do{if(si_msg5111e0(((0x23d)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
       do{si_cf1080.u451400(1);if(((0x127))!=-1&&!(si_d28fb0&&1&&1))si_sound4541b0((0x127),0,0);do{if(si_msg5111e0(((0x324)),((&string(("ALERT: Hostile activity reported, dispatching reinforcements to area.")))),(0),(0),((SiHE())),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);si_cec0b4->end7b4f10();}while(false);
       f34=0;
       f40=si_cf6428.lastParty()->f4;
      }
     }
     break;
    }
    goal.x=-1;
    do{}while(false);
    break;
   case 5:
    if(!v6c.empty9b86e0()&&(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->u66b1c0(0,0)&&(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->getProp45d550()->u45cb30()->f28>=0&&!(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->getProp45d550()->u457b10())break;
   case 2:case 3:
    if(f58.operator->())goto La8df;
    {
     SiVHE2*mem=ent->g28->members416f40();
     for(unsigned i=0;i<mem->size9b9260();i++){
      if(si_dist40a3f0(ent->getPosition45a4a0(),(*mem)[i]->getPosition45a4a0())<=8&&(!(*mem)[i]->ai||(*mem)[i]->ai->f8>=6)){goto La8df;break;}
     }
     b56=true;goal.x=-1;
     do{}while(false);
    }
   La8df:
    break;
    break;
   case 6:
    u5b4530();
    u5bb750(0,0,0);
    return 100;
   }
   u5b4530();
  }
  if(ent->getFaction45a2c0()==0x19){
   if(rng.chance(33)){
    SiVHE2*list=si_cefc4c->u4643b0();
    if(!list->empty9b86e0()){
     for(unsigned i=0;i<list->size9b9260();i++){
      if(!(*list)[i].operator->()||!(*list)[i]->u45a9d0())si_cefc4c->u464d80((*list)[i]);
      else if((*list)[i]->u45aaa0(ent)&&(*list)[i]!=ent&&!(*list)[i]->getTarget45a760()&&si_dist40a3f0(ent->getPosition45a4a0(),(*list)[i]->getPosition45a4a0())<=15&&si_cefc4c->isReachable465230(15,ent->getPosition45a4a0(),(*list)[i]->getPosition45a4a0())){
       si_cefc4c->displayHack734ae0(ent,(*list)[i]->getPosition45a4a0(),1);
       (*list)[i]->u44e2c0(0);
       do{if(si_msg5111e0(((ent->isHostileTo45aa70(si_cefc4c->getPlayer4630f0())?0x1e5:0x1e4)),((0)),(0),(0),(((*list)[i])),((ent)),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
       si_cefc4c->u464d80((*list)[i]);
       do{ent->f40++;ent->clr45b0b0();return (150);}while(false);
      }
     }
    }
   }
   if(rng.chance(50)){
    SiVHE2*list=si_cefc4c->u4643d0();
    if(!list->empty9b86e0()){
     for(unsigned i=0;i<list->size9b9260();i++){
      if(!(*list)[i].operator->()||!(*list)[i]->ai45b590()->u459090())si_cefc4c->u464de0((*list)[i]);
      else if((*list)[i]->u45aaa0(ent)&&(*list)[i]!=ent&&!(*list)[i]->getTarget45a760()&&si_dist40a3f0(ent->getPosition45a4a0(),(*list)[i]->getPosition45a4a0())<=15&&si_cefc4c->isReachable465230(15,ent->getPosition45a4a0(),(*list)[i]->getPosition45a4a0())){
       si_cefc4c->displayHack734ae0(ent,(*list)[i]->getPosition45a4a0(),1);
       do{if(si_msg5111e0(((ent->isHostileTo45aa70(si_cefc4c->getPlayer4630f0())?0x1e7:0x1e6)),((0)),(0),(0),(((*list)[i])),((ent)),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
       if((*list)[i]->ai45b590()->u459090()){
        SiParts*parts=(*list)[i]->ai45b590()->u4590f0();
        if(parts->u458950(7))parts->u458950(7)->f18->ai45b590()->setField451440(SiHE());
        if(parts->u458950(0x32)){
         string s="Feed link from "+(*list)[i]->name416f40()+" lost";
         do{if(si_msg5111e0((0x1d6),(&string(si_cfc9d8)),(&s),(0),(SiHE()),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
         si_cefc4c->u72e790(si_cefc4c->u463540((*list)[i]));
        }
        (*list)[i]->ai45b590()->u459230();
        si_cefc4c->u464de0((*list)[i]);
       }
       do{ent->f40++;ent->clr45b0b0();return (150);}while(false);
      }
     }
    }
   }
  }
  if(f8!=1&&!b56&&u5815e0()&&(f8!=2||ent->getFaction45a2c0()!=8)){
   SiHE eB;SiQ p;int g0=ent->u5c7d30();int c7=g0;int d;
   if(f8!=7){
    SiVVHE groups;si_cefc4c->u463970(ent,groups);
    for(unsigned i=0;i<groups.size9b9260();i++)for(unsigned j=0;j<groups[i]->size9b9260();j++){
     eB=groups[i]->at9b9230(j);
     if(si_caf204[eB->getTarget45a760()]||eB->u45ac40(0x1c)){
      p=eB->u5c80f0(ent->u45a4c0());
      d=si_dist40a3f0(ent->u5c80f0(p),p);
      if(d<=c7&&si_cefc4c->u72a850(ent->u5c7d30(),ent,eB)&&d<=c7-eB->u5d2150(30,0)){
       bool fail=!u5b9cb0(chase5b4710(eB,1,si_d2c43c.randomInRange40c130(),1,0));
       if(ent->def9b4350()==si_cefc08&&rng.chance(66)&&d>=4&&eB->u5d15a0(0)>=100)continue;
       SiHE self=ent;
       if(si_fn4569a0(0x4c,ent,eB,SiHE(),SiHE(),0,0,ent->fec,ent,SiHE(),SiHE(),0)&&!self.operator->())return 100;
       if(f8==6&&!fail){u5bb750(0,0,0);return 100;}
      }
     }
    }
   }
   if(vf0.empty9b86e0()||f8<6)goto L10d17;
   else{
    if(ent->u45ac40(0x31)){
     SiArea r;
     si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),10,r);
     SiVHEl ents;
     for(int x=r.x1;x<=r.x2;x++)for(int y=r.y1;y<=r.y2;y++)
      if((*si_cfd44c.at9ceda0(x,y))->getEntity45d250().isValid()&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->u45ac40(0x31))ents.push_back9b7cf0((*si_cfd44c.at9ceda0(x,y))->getEntity45d250());
     bool a2=false;
     for(unsigned i=0;i<ents.size9b9260();i++){
      string a0=ents[i]->name416f40();
      SiP pos=ents[i]->getPosition45a4a0();
      int hp=ents[i]->u45a880();
      int nG=ents[i]->u45acb0(0x31);
      ents[i]->u637bb0();
      SiHE n=si_cefc4c->placeEntity6c58c0(si_d25de0[nG],pos,9,0,0x22,0xe,0);
      if(n.isValid()){
       if(si_dist40a3f0(pos,si_cefc4c->getPlayer4630f0()->getPosition45a4a0())<=20)n->ai45b590()->setFollowEntity5b2f80(si_cefc4c->getPlayer4630f0(),0);
       if(hp<100)n->u5dea60(si_maxInt9cdb60(1,n->u490840()*hp/100),0);
       if(si_cefc4c->u4631f0(n)){
        string msg=a0+" reveals itself to be an Infiltrator.";
        si_message49c610(0x320,SiHE(),&msg,0);
        if(!a2){si_cefc4c->u6c65a0(n,"ECA_Infiltrator_Talk",0);a2=true;}
       }
      }
     }
     return 100;
    }
    if(ent->getFaction45a2c0()==0x19){
     for(unsigned i=0;i<vf0.size9b9260();i++){
      if(u5bd350(vf0[i]->e)){
       SiHE t=vf0[i]->e;
       si_cefc4c->displayHack734ae0(ent,t->getPosition45a4a0(),1);
       do{if(si_msg5111e0(((ent->isHostileTo45aa70(si_cefc4c->getPlayer4630f0())?0x8d:0x8c)),((0)),(0),(0),((t)),((ent)),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
       t->u5fdab0();
       t->changeFaction5dc780(ent->getGroup45a3f0(),true);
       t->ai45b590()->setFollowEntity5b2f80(ent,0);
       if(si_cefc4c->u4631f0(t))si_sound4541b0(0x6b,0,0);
       do{ent->f40++;ent->clr45b0b0();return (150);}while(false);
      }
     }
    }
    if(fbc>1){
     SiQ lo;SiQ hiD;SiQ2 pos;
     for(unsigned i=0;i<vf0.size9b9260();i++){
      pos=vf0[i]->e->getPosition45a4a0();
      si_cfd44c.getBounds9b7a40(pos,fbc,lo,hiD);
      for(int x=lo.x;x<=hiD.x;x++)for(int y=lo.y;y<=hiD.y;y++){
       if((*si_cfd44c.at9ceda0(x,y))->getEntity45d250().isValid()&&pos.ne409cf0(x,y)&&((*si_cfd44c.at9ceda0(x,y))->getEntity45d250()!=ent||ent->getFaction45a2c0()==0xe&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->getFaction45a2c0()==0xe)&&!(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->getTarget45a760()){
        int d=si_distance406480(pos.x,pos.y,x,y);
        if(d<=fbc){
         switch((*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->u5c7fc0(ent)){
         case 0:
          vf0[i]->f8+=si_maxInt9cdb60(1,fbc-d)*si_bba364;
          break;
         case 1:
         Lc031:
          vf0[i]->f8-=si_maxInt9cdb60(1,fbc-d)*si_bba368;
          break;
         case 2:
          if(!(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->isXomCandidate5d51a0())goto Lc031;
          if((*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->u5cb570(fc0,1)<=0x4b)break;
          if(ent->getFaction45a2c0()==0xe&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->getFaction45a2c0()==0xe){vf0[i]->f8=-1;goto Lc1f2;}
          vf0[i]->f8-=si_maxInt9cdb60(1,fbc-d)*si_bba36c;
          break;
         }
        }
       }
      }
     Lc1f2:;
     }
    }
    if(ent->def->b15c&&ent->def->name=="Master Drone"){
     for(unsigned i=0;i<vf0.size9b9260();i++){
      if(vf0[i]->e->getTarget45a760()||!vf0[i]->e->isXomCandidate5d51a0()||vf0[i]->e->def->f24!=1||vf0[i]->e->u45ac40(0x39))vf0[i]->f8=-1;
      else vf0[i]->f8=si_maxInt9cdb60(0,vf0[i]->e->u5cccc0()-si_dist40a3f0(ent->getPosition45a4a0(),vf0[i]->e->getPosition45a4a0()));
     }
    }
    SiTgt*tg=u580ec0();
   Lc3f7:
    if(!tg)goto L10d17;
    if(p118&&p118->f0==0){
     bool b1=false;
     if(!p118->e8.operator->()||si_cefc4c->getTurn464270()>p118->f4){
      b1=true;
      if(ent->getFaction45a2c0()==0x25&&rng.chance(40)&&si_d1e888->type==0xf&&!ent->u45aaa0(si_cefc4c->getPlayer4630f0())){
       bool b2=false;
       for(unsigned i=0;i<vf0.size9b9260();i++){
        if(vf0[i]->e->isPlayer5c7600()?si_cefc4c->isVisible4631c0(ent->getPosition45a4a0()):si_cefc4c->isReachable465230(50,vf0[i]->e->getPosition45a4a0(),ent->getPosition45a4a0())){b2=true;break;}
       }
       if(!b2){
        if(rng.chance(50)){
         if(!si_cefc4c->u4631f0(ent)){ent->u637bb0();return 100;}
        }else{
         SiSpawnDef*sd;
         if(si_findByName9d7530(si_d25de0,"Subdweller",sd)){
          SiQ q;
          if(si_cefc4c->findPlaceableNear71c150(ent->getPosition45a4a0(),q,sd->f9c)){
           SiHE n=si_cefc4c->placeEntity6c58c0(sd,q,ent->getGroup45a3f0()->type9b4350(),0,0x22,0xe,0);
           if(n.isValid()){
            n->ai45b590()->setFollowEntity5b2f80(ent,0);
            if(si_cefc4c->u4631f0(n)){string m=n->name416f40()+" emerges from concealment.";si_message49c610(0x320,SiHE(),&m,0);}
            si_454260(n->getPosition45a4a0(),0xab);
           }
          }
         }
        }
       }
      }
     }else{
      if(p118->p10.x==-1||(p118->e8->isPlayer5c7600()?si_cefc4c->u4633c0(p118->p10):si_cefc4c->isReachable465230(50,p118->e8->getPosition45a4a0(),p118->p10))){
       SiVPl pts;
       SiArea r;
       si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),5,r);
       for(int x=r.x1;x<=r.x2;x++)for(int y=r.y1;y<=r.y2;y++){
        if(p118->e8->isPlayer5c7600()?!si_cefc4c->u4633c0(SiP(x,y)):!si_cefc4c->isReachable465230(50,p118->e8->getPosition45a4a0(),SiP(x,y)))pts.push_back9b3020(SiP(x,y));
       }
       if(pts.empty9b86e0())b1=true;
       else p118->p10=si_randomPoint9d5350(pts);
      }
      if(!b1){
       if(ent->getPosition45a4a0().eq409b90(p118->p10))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
       else{goal=p118->p10;do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
      }
     }
     if(b1){delete p118;p118=0;}
    }
    if(fbc&&tg->f8<0){
     SiVHIl items;
     ent->u5d6c30(items);
     if(items.size9b9260()>1){
      bool any=false;
      for(unsigned i=0;i<items.size9b9260();i++){
       if(items[i]->def9b4350()->f1a0)ent->u64e7e0(items[i]);
       else any=true;
      }
      if(any)goto Ld09d;
     }
     if(ent->u5d5d40().isValid()){
      for(unsigned i=0;i<items.size9b9260();i++)if(items[i]->def9b4350()->f1a0)ent->u64e7e0(items[i]);
     }else{
      if(rng.chance(70)){
       for(int k=0;k<3;k++){
        SiP q(ent->getPosition45a4a0(),rng.rangeInt(-1.0f,1.0f),rng.rangeInt(-1.0f,1.0f));
        if(si_cfd44c.contains9b43b0(q)&&(*si_cfd44c.atPoint9ced70(q))->isPassableFor66ab30(ent)&&(*si_cfd44c.atPoint9ced70(q))->getEntity45d250().isNull9b65d0()){goal=q;do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
       }
      }
      do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
     }
    Ld09d:;
    }
    if(tg->f8<0&&ent->def->b15c&&ent->def->name=="Master Drone"){u5b94c0();do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
    eB=tg->e;
    p=eB->u5c80f0(ent->u45a4c0());
    if(f8!=6){
     SiQ q;
     SiVPl path8;
     SiVX nW;
     SiVX c9;
     bool fail=!si_cefc4c->u7170a0(ent,p,path8,nW,c9,q,0,4,1,1);
     if(fail&&f8!=12){
      bool ok=true;
      int ns=0;
      for(unsigned i=0;i<nW.size9b9260()-1;i++){
       if(nW[i]){
        if(nW[i]!=3||!(*si_cfd44c.atPoint9ced70(path8[i]))->getEffect45d350(4)){
         if(f8==11&&nW[i]==3&&++ns<=1)continue;
         ok=false;break;
        }
       }
      }
      if(!ok)goto L1053a;
     }
     if(ent->f98>=250&&!ent->u45ac40(0x1e)){
      ent->fd0=si_caed20;
      if(f8<=9){do{if(si_msg5111e0(((0x90)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}
     }
     int mode=1;
     if(ent==si_cf68b8&&si_cf68b4->f110==1)u5b5830(ent->u5c87f0(p)&&(si_cf6954==si_cefc4c->getTurn464270()||rng.chance(75)));
     else if(ent->getFaction45a2c0()==0x42&&ent->u45ac40(0x3a)&&ent->getName45a280()[0]=='G')si_d25450.giveXomItems6be2f0(ent);
     {
     SiVHIl pK;
     ent->u5d6a80(pK,p,-1);
     bool flag=false;
     if(assimilate5bbf70(0x19,eB)==1)do{ent->f40++;ent->clr45b0b0();return (150);}while(false);
     if(pK.empty9b86e0()){
      if(ent->u5d5d40().isValid()){
       mode=0;
       pK.push_back9b7cf0(ent->u5d5d40());
       if(!ent->u5c87f0(p))goto L1053a;
      }else if(fc4){
       if(fc4<si_dist40a3f0(ent->getPosition45a4a0(),p))goto L1053a;
       else{flag=true;goto Lee0a;}
      }else{
       ent->u5d6c30(pK);
       if(pK.empty9b86e0()){
        switch(assimilate5bbf70(0x64,eB)){
        break;
        case 1:do{ent->f40++;ent->clr45b0b0();return (150);}while(false);break;
        case 2:goto L1053a;
        }
        if(f4==0x20)goto L133be;
        b56=true;goal.x=-1;
        goto L110d4;
       }else goto L1053a;
      }
     }
     int bN;
    Ldae1:
     bN=0;
     for(unsigned i=0;i<pK.size9b9260();i++)bN+=pK[i]->u5788e0();
     if(bN>ent->u45a8d0()){
      if(pK.size9b9260()>1&&rng.chance(50)){
       int best=0;
       int bestv=pK[0]->u5788e0();
       for(unsigned i=1;i<pK.size9b9260();i++){
        int v=pK[i]->u5788e0();
        if(v>bestv){bestv=v;best=i;}
       }
       si_eraseAt9da940(pK,best);
       bN=0;
       goto Ldae1;
      }
      do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
     }
     bN=0;
     for(unsigned i=0;i<pK.size9b9260();i++)bN+=pK[i]->u5789c0();
     if(bN>ent->u45a920()){
      ent->u5deb40(si_maxInt9cdb60(1,bN/3));
      if(ent->getFaction45a2c0()==0x1e){
       for(unsigned i=0;i<pK.size9b9260();i++){
        if(pK[i]->u5789c0()){pK[i]->remove57dbe0(0,0,true,true);si_eraseStep9d6440(pK,i);}
       }
       do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
      }
     }
     if(bN>ent->u45a920())do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
     if(fail&&f8==12){
      int cnt=0;
      for(unsigned i=0;i<nW.size9b9260()-1&&cnt<=3;i++){
       switch(nW[i]){
       break;
       break;
       case 2:
        for(unsigned j=0;j<pK.size9b9260();j++)if(pK[j]->u578b80((*si_cfd44c.atPoint9ced70(path8[i]))->getProp45d550()))goto Le172;
        goto L1053a;
       Le172:
        cnt++;
        break;
       case 3:
        for(unsigned j=0;j<pK.size9b9260();j++)if(pK[j]->u578c50(path8[i]))goto Le236;
        goto L1053a;
       Le236:
        cnt++;
        break;
       case 4:
        for(unsigned j=0;j<pK.size9b9260();j++)if(!(*si_cfd44c.atPoint9ced70(path8[i]))->getEntity45d250()->u45aaa0(ent)&&pK[j]->u578d00((*si_cfd44c.atPoint9ced70(path8[i]))->getEntity45d250()))goto Le365;
        goto L1053a;
       Le365:
        cnt++;
        break;
       }
      }
      if(cnt>3)goto L1053a;
     }
     if(ent->u5c7f70()){
      si_cefc4c->u463890(0)->u671f80(ent,tg->e);
      si_cefc4c->u463890(1)->u671f80(ent,tg->e);
     }
     if(ent->g28->type9b4350()<=2)si_d2c658.add4729d0(0x3ae,1,si_empty_b91dc3,-1);
     if(f34&&f8==7&&f44<si_cefc4c->getTurn464270()&&ent->getGroup45a3f0()->type9b4350()==3&&si_cf6428.u686c60(ent->getPosition45a4a0(),-1,0x61,0x7a)){
      do{if(si_msg5111e0(((u581140()?0x23e:0x23d)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      do{si_cf1080.u451400(1);if(((0x127))!=-1&&!(si_d28fb0&&1&&1))si_sound4541b0((0x127),0,0);do{if(si_msg5111e0(((0x324)),((&string(("ALERT: Hostile activity reported, dispatching reinforcements to area.")))),(0),(0),((SiHE())),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);si_cec0b4->end7b4f10();}while(false);
      si_cf6428.wake68d480();
      f34=0;
      SiHE h;
      SiArea r;
      si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),10,r);
      for(int x=r.x1;x<=r.x2;x++)for(int y=r.y1;y<=r.y2;y++){
       if((*si_cfd44c.at9ceda0(x,y))->getEntity45d250().isValid()){
        h=(*si_cfd44c.at9ceda0(x,y))->getEntity45d250();
        if(h->ai45b590()&&h->ai45b590()->mode9b4350()==7&&h->ai45b590()->f34&&(h->getGroup45a3f0()->type9b4350()==3||h->getGroup45a3f0()->type9b4350()==4))h->ai45b590()->f44=si_cefc4c->getTurn464270()+50;
       }
      }
     }
     if(mode==1&&ent->u45a9d0()&&ent->isHostileTo45aa70(si_cefc4c->getPlayer4630f0())&&rng.chance(ent->u45a9d0()/5)&&si_b949e8[ent->getAiType45a2a0()]){
      int range=0;
      for(unsigned i=0;i<pK.size9b9260();i++)if(pK[i]->u4580a0()>range)range=pK[i]->u4580a0();
      if(range>ent->u5c7d30())range=ent->u5c7d30();
      SiP c(ent->getPosition45a4a0());
      SiArea q3;
      si_cfd44c.getRect9b4430(c,range,q3);
      bool c6=rng.chance(50);
      bool found=false;
      if(c6){
       SiVHEl list;
       for(int y=q3.y1;y<q3.y2;y++)for(int x=q3.x1;x<q3.x2;x++){
        if((*si_cfd44c.at9ceda0(x,y))->getEntity45d250().isValid()&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()!=ent&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()!=eB&&!si_contains9d31e0(list,(*si_cfd44c.at9ceda0(x,y))->getEntity45d250())&&si_dist40a3f0(c,SiP(x,y))<=range&&si_cefc4c->isReachable465230(range,c,SiP(x,y)))
         list.push_back9b7cf0((*si_cfd44c.at9ceda0(x,y))->getEntity45d250());
       }
       if(!list.empty9b86e0()){static_cast<SiP&>(p)=si_randomRecord9dafb0(list)->u45a4c0();found=true;}
       else c6=false;
      }
      if(!c6){
       SiQ q;
       int tries=0;
       do{
        q3.randomPoint40be30(&q);
        tries++;
       }while((!si_fn9daf80(1,si_dist40a3f0(c,q),range)||si_fn9d0ce0(*ent->u45d1a0(),q))&&tries<100);
       if(tries<100){p=q;found=true;}
      }
      if(found){
       do{if(si_msg5111e0(((c6?0x22f:0x230)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
       goto L1039b;
      }
     }
    Lee0a:
     if(!(*si_cfd44c.atPoint9ced70(ent->getPosition45a4a0()))->u45dc70()){
      if(si_dist40a3f0(ent->getPosition45a4a0(),tg->e->getPosition45a4a0())>4&&rng.chance(10)&&!b55&&!ent->u5c7f70()
       ||(*si_cfd44c.atPoint9ced70(ent->u45a4c0()))->canCaveIn66af50()&&rng.chance(66)&&!ent->u5c8820(tg->e)
       ||ent->getFaction45a2c0()==0x5e&&si_dist40a3f0(ent->getPosition45a4a0(),tg->e->getPosition45a4a0())>3&&rng.chance(75)&&pK.front9b7060()->name457860()=="Sigix Shearcannon"){
       goal=tg->e->getPosition45a4a0();
       do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);
      }
      if(ent->getSize45a360()==1&&(si_d1e888->f8<=6||ent->u45aaa0(si_cefc4c->getPlayer4630f0()))&&rng.chance(25)&&!si_cfd44c.isEdge9b7960(ent->getPosition45a4a0())){
       SiP me(ent->getPosition45a4a0());
       SiQ2 dX;
       SiVPl a;
       SiVPl b;
       if(!(*si_cfd44c.at9ceda0(me.x-1,me.y))->u4550b0()&&!(*si_cfd44c.at9ceda0(me.x+1,me.y))->u4550b0()){
        int dir=si_dir4374c0(me,tg->e->getPosition45a4a0());
        if(dir!=6&&dir!=2){
         dX=me.add409b60(si_d015d8[dir]);
         int w3=dX.y>=me.y?1:-1;
         int s2=dX.y<me.y?1:-1;
         for(int x=me.x-1;x<=me.x+1;x++){
          if((*si_cfd44c.at9ceda0(x,me.y+w3))->isPassableFor66ab30(ent)&&(*si_cfd44c.at9ceda0(x,me.y+w3))->getEntity45d250().isNull9b65d0())b.push_back9b3020(SiP(x,me.y+w3));
          if((*si_cfd44c.at9ceda0(x,me.y+s2))->getEntity45d250().isValid()&&(*si_cfd44c.at9ceda0(x,me.y+s2))->getEntity45d250()->u45aaa0(ent)&&(*si_cfd44c.at9ceda0(x,me.y+s2))->getEntity45d250()->isXomCandidate5d51a0()&&(*si_cfd44c.at9ceda0(x,me.y+s2))->getEntity45d250()->getSize45a360()==1)a.push_back9b3020(SiP(x,me.y+s2));
         }
        }
       }else if(!(*si_cfd44c.at9ceda0(me.x,me.y-1))->u4550b0()&&!(*si_cfd44c.at9ceda0(me.x,me.y+1))->u4550b0()){
        int dir=si_dir4374c0(me,tg->e->getPosition45a4a0());
        if(dir!=0&&dir!=4){
         dX=me.add409b60(si_d015d8[dir]);
         int w9=dX.x>=me.x?1:-1;
         int s2=dX.x<me.x?1:-1;
         for(int y=me.y-1;y<=me.y+1;y++){
          if((*si_cfd44c.at9ceda0(me.x+w9,y))->isPassableFor66ab30(ent)&&(*si_cfd44c.at9ceda0(me.x+w9,y))->getEntity45d250().isNull9b65d0())b.push_back9b3020(SiP(me.x+w9,y));
          if((*si_cfd44c.at9ceda0(me.x+s2,y))->getEntity45d250().isValid()&&(*si_cfd44c.at9ceda0(me.x+s2,y))->getEntity45d250()->u45aaa0(ent)&&(*si_cfd44c.at9ceda0(me.x+s2,y))->getEntity45d250()->isXomCandidate5d51a0()&&(*si_cfd44c.at9ceda0(me.x+s2,y))->getEntity45d250()->getSize45a360()==1)a.push_back9b3020(SiP(me.x+s2,y));
         }
        }
       }
       if(!a.empty9b86e0()&&!b.empty9b86e0()){goal=si_randomPoint9d5350(b);do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);}
      }
      if(mode==1&&rng.chance(33)&&ent->getSize45a360()==1&&!(*si_cfd44c.atPoint9ced70(ent->getPosition45a4a0()))->u45db70()){
       for(int dx=-1;dx<=1;dx++)for(int dy=-1;dy<=1;dy++){
        SiP n(ent->getPosition45a4a0(),dx,dy);
        if(si_cfd44c.contains9b43b0(n)&&(*si_cfd44c.atPoint9ced70(n))->getEntity45d250().isValid()&&(*si_cfd44c.atPoint9ced70(n))->getEntity45d250()->isHostileTo45aa70(ent)&&(*si_cfd44c.atPoint9ced70(n))->getEntity45d250()->u5d5d40().isValid()){
         SiP me(ent->getPosition45a4a0());
         int dir=si_dir4374c0(tg->e->getPosition45a4a0(),me);
         goal=me.add409b60(si_d015d8[dir]);
         if(si_cfd44c.contains9b43b0(goal)){
          if((*si_cfd44c.atPoint9ced70(goal))->canCaveIn66af50())goto Lfcaa;
          if(tg->e->isPlayer5c7600()&&si_cf4ac8&&si_cf4ac8->h4.operator->()&&si_cf4ac8->h4->u457b50()==si_cefc4c->getPlayer4630f0()&&si_cf4ac8->h4->getType44aec0()==3&&si_cf45d8.hasCompanion780790())
           si_cf4ac8->p30->spawn7aa280(0x24,0,ent->def9b4350()->getName459c30());
          do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);
         }else{goal.x=-1;goto Lfcaa;}
        }
       }
      }
     }
    Lfcaa:
     if(flag)do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
     if(fcc==1&&rng.chance((10-si_dist40a3f0(ent->getPosition45a4a0(),tg->e->getPosition45a4a0()))*2+20)&&!ent->u5cad50()){
      if((ent->def->f48==0x2c?!ent->u5cac90():!ent->u5cabd0())||ent->u45ac40(0x39)&&ent->u5d5c30().isValid())fcc=0;
      else{
       SiVHI*inv=ent->getInventoryList45ab00();
       for(unsigned i=0;i<inv->size9b9260();i++)if((*inv)[i]->u457cf0()&&(*inv)[i]->def9b4350()->fec)(*inv)[i]->setOverload579940(true);
       fcc=si_cefc4c->getTurn464270()+rng.rangeInt(18.0f,32.0f);
      }
     }
     if(ent->getFaction45a2c0()==0x4d&&ent->u5cabd0()&&!ent->u5cad50()){
      SiVHI*inv=ent->getInventoryList45ab00();
      for(unsigned i=0;i<inv->size9b9260();i++)if((*inv)[i]->u457cf0()&&si_ba0968[(*inv)[i]->def9b4350()->fec])(*inv)[i]->setOverload579940(true);
      do{ent->f40++;ent->clr45b0b0();return (ent->u5cb220()*100);}while(false);
     }
     if(ent->getFaction45a2c0()==0x25&&!p118&&si_dist40a3f0(ent->getPosition45a4a0(),p)>=8&&rng.chance(10)&&!ent->u45aaa0(si_cefc4c->getPlayer4630f0()))p118=new SiRec118(0,si_cefc4c->getTurn464270()+8,eB,SiHE(),SiP(-1));
     if(ent->getFaction45a2c0()==0x5e&&si_cefc4c->u729d60(eB)){
      do{if(si_msg5111e0(((0x28a)),((&eB->name416f40())),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      if(si_cefc4c->u4633c0(eB->getPosition45a4a0()))si_cec054->showHitBonus817390(eB);
     }
     if(ent==si_cf68b8&&si_cf68b4->f110==6)si_cf6a0c=abs(si_cf6a0c)+1;
     tg->f8+=4;
    L1039b:
     ent->f40++;ent->clr45b0b0();
     b110=true;
     SiVE8 v;
     int out;
     si_cefc4c->addRecord777a20(si_cefaa8->createA7930e0(new SiShoot(ent,mode,p,q,out,v,0,SiHE())));
     return out;
     }
    }
   L1053a:
    if(f8!=6){
     SiVTg list;
     for(unsigned i=0;i<vf0.size9b9260();i++){
      if(vf0[i]->e->u5c8820(ent)&&(ent->getFaction45a2c0()!=0x3a||vf0[i]->e->getFaction45a2c0()==10))list.push_back9b9d30(vf0[i]);
     }
     if(!list.empty9b86e0()){si_shuffle9d8f80(list);tg=list[0];goto Lc3f7;}
    }
    if(ent->getFaction45a2c0()==0x4d&&ent->u5cad50()){
     SiVHI*inv=ent->getInventoryList45ab00();
     for(unsigned i=0;i<inv->size9b9260();i++)if((*inv)[i]->u458220()&&si_ba0968[(*inv)[i]->def9b4350()->fec])(*inv)[i]->setActive5791a0(false);
     do{ent->f40++;ent->clr45b0b0();return (ent->u5cb220()*100);}while(false);
    }
    if(goal.x==-1||abs(goal.x-p.x)>ent->getSize45a360()+2||abs(goal.y-p.y)>ent->getSize45a360()+2){
     goal=f18=p;
     f20=(*si_cfd44c.atPoint9ced70(p))->getEntity45d250();
    }
    if(ent->getSize45a360()>1&&ent->u5c84f0(goal)&&ent->u5c8710(goal)){
     for(int k=1;k<ent->getSize45a360();k++){
      SiVPl cands;
      SiArea r;
      si_cfd44c.getRect9b4430(goal,k,r);
      for(int x=r.x1;x<=r.x2;x++)for(int y=r.y1;y<=r.y2;y++){
       if(abs(goal.x-x)==k&&abs(goal.y-y)==k&&ent->u5c84f0(SiP(x,y))&&!ent->u5c8710(SiP(x,y)))cands.push_back9b3020(SiP(x,y));
      }
      if(!cands.empty9b86e0()){goal=si_randomPoint9d5350(cands);goto L10b20;}
     }
     goal.x=-1;
    }
   L10b20:
    if(f60&&f58.operator->()&&goal.x!=-1){
     SiVPl path;
     if(!si_cfe568.findPath40c9a0(ent->getPosition45a4a0(),goal,si_cefc30,0,path)||si_dist40a3f0(f58->getPosition45a4a0(),path.front9b7060())>si_bb9ec4[f60]||f60==2&&f58->isPlayer5c7600()&&!si_cefc4c->u4633c0(path.front9b7060())){
      tg->f8=0;
      goto L10d17;
     }
    }
    do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   }
  }
 L10d17:
  ;
 }
 if(f8==9&&vf0.empty9b86e0()&&ent->getGroup45a3f0()->type9b4350()&&fb4.operator->()&&fb4->u5d26e0(0xa7)){f4=9;f8=0;f58.reset9b7270();}
 if(p118&&p118->f0==4){
  bool done=false;
  if(!p118->hc.operator->())done=true;
  else{
   SiHI it=p118->hc;
   if(ent->getPosition45a4a0().adjacent409dd0(it->u575920())){
    if(si_cefc4c->u4631f0(ent)&&it->u457b50().isValid()){
     string s="[name] snatches the "+it->name457860()+".";
     si_message49c610(0x322,ent,&s,0);
     s="[name]: \"I am GR-1FF!\"";
     si_message49c610(0x322,ent,&s,0);
    }
    it->u57a190(ent,3,1,0);
    it->u579c80();
    done=true;
   }else{goal=it->u575920();do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
  }
  if(done){delete p118;p118=0;}
 }
 L110d4:
 vdc.clear9b73d0();
 if(b56){
  if(goal.x==-1)u5b94c0();
  do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
 }
 if(ally114){
  switch(ally114->f4){
  case 4:
   if(ent->getFaction45a2c0()==8&&si_cefc4c->getTurn464270()>=fec+12){
    if(fb4.isValid()&&(!fb4.operator->()||fb4->getGroup45a3f0()->type9b4350()&&fb4->getGroup45a3f0()->type9b4350()!=1)){
     int idx=si_indexOfEntity9d3110(si_cf25b8,fb4);
     if(idx!=-1){si_eraseAt9da940(si_cf25b8,idx);si_eraseAt9da940(si_d37984,idx);}
     fb4.reset9b7270();
    }
    if(fb4.isNull9b65d0()&&rng.chance(25)){
     SiVHEl cands;
     cands.push_back9b7cf0(si_cefc4c->getPlayer4630f0());
     if(f58.operator->()&&f58!=si_cefc4c->getPlayer4630f0())si_insert9d8fc0(cands,0,f58);
     for(unsigned i=0;i<cands.size9b9260();i++){
      if(u5ba870(cands[i],0,0)){
       int k=si_indexOfEntity9d3110(si_cf25b8,cands[i]);
       if(k==-1||si_d37984[k].isNull9b65d0()){fb4=cands[i];break;}
      }
     }
     if(fb4.isNull9b65d0()){
      cands.clear9b73d0();
      int best=15;
      cands=*si_cefc4c->u463890(0)->members416f40();
      si_eraseAt9da940(cands,0);
      si_appendVector9d49c0(cands,*si_cefc4c->u463890(1)->members416f40());
      for(unsigned i=0;i<cands.size9b9260();i++){
       if(ent!=cands[i]&&u5ba870(cands[i],0,0)&&(!si_contains9d31e0(si_cf25b8,cands[i])||si_d37984[si_indexOfEntity9d3110(si_cf25b8,cands[i])].isNull9b65d0())&&si_dist40a3f0(ent->getPosition45a4a0(),cands[i]->getPosition45a4a0())<=best){
        best=si_dist40a3f0(ent->getPosition45a4a0(),cands[i]->getPosition45a4a0());
        fb4=cands[i];
       }
      }
     }
     if(fb4.isValid()){
      int idx=si_indexOfEntity9d3110(si_cf25b8,fb4);
      if(idx==-1){si_cf25b8.push_back9b80b0(fb4);si_d37984.push_back9b80b0(ent);}
      else si_d37984[idx]=ent;
     }
    }
    if(fb4.isValid()){
     if(si_cefc4c->getTurn464270()>=(fb4->ai?fb4->ai->fec:si_cf4b98)+12){
      if(ent->u5c8820(fb4)){int r=service5bac50();do{ent->f40++;ent->clr45b0b0();return (r);}while(false);}
      else if(goal.ne409bd0(fb4->getPosition45a4a0()))goal=fb4->getPosition45a4a0();
      do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
     }
    }
   }
   break;
  }
 }else{
  switch(f4){
  case 0xb:{
   bool x=u459090()&&p11c->u458950(0x16);
   if(fb4.isValid()&&(!fb4.operator->()||x||!fb4->u45aaa0(ent))){
    int idx=si_indexOfEntity9d3110(si_cf25b8,fb4);
    if(idx!=-1){si_eraseAt9da940(si_cf25b8,idx);si_eraseAt9da940(si_d37984,idx);}
    fb4.reset9b7270();
   }
   if(fb4.isNull9b65d0()&&!x&&si_cefc4c->getTurn464270()>=fec+12&&rng.chance(25)){
    SiVHEl candsB;
    int range_=ent->getGroup45a3f0()->type9b4350()==4?40:25;
    if(ent->u45aaa0(si_cefc4c->getPlayer4630f0())&&si_dist40a3f0(ent->getPosition45a4a0(),si_cefc4c->getPlayer4630f0()->getPosition45a4a0())<=range_)candsB.push_back9b7cf0(si_cefc4c->getPlayer4630f0());
    if(f58.operator->()&&ent->u45aaa0(f58)&&f58!=si_cefc4c->getPlayer4630f0()&&si_dist40a3f0(ent->getPosition45a4a0(),f58->getPosition45a4a0())<=range_)si_insert9d8fc0(candsB,0,f58);
    for(unsigned i=0;i<candsB.size9b9260();i++){
     if(u5ba870(candsB[i],0,0)){
      int k=si_indexOfEntity9d3110(si_cf25b8,candsB[i]);
      if(k==-1||si_d37984[k].isNull9b65d0()){fb4=candsB[i];break;}
     }
    }
    if(fb4.isNull9b65d0()){
     int best;
     SiArea r;
     si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),range_,r);
     for(int x=r.x1;x<=r.x2;x++)for(int y=r.y1;y<=r.y2;y++){
      if((*si_cfd44c.at9ceda0(x,y))->getEntity45d250().isValid()&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()!=ent&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->u45aaa0(ent)
       &&(fb4.isNull9b65d0()||si_dist40a3f0(ent->getPosition45a4a0(),SiP(x,y))<=best)&&u5ba870((*si_cfd44c.at9ceda0(x,y))->getEntity45d250(),0,0)
       &&(!si_contains9d31e0(si_cf25b8,(*si_cfd44c.at9ceda0(x,y))->getEntity45d250())||si_d37984[si_indexOfEntity9d3110(si_cf25b8,(*si_cfd44c.at9ceda0(x,y))->getEntity45d250())].isNull9b65d0())){
       best=si_dist40a3f0(ent->getPosition45a4a0(),SiP(x,y));
       fb4=(*si_cfd44c.at9ceda0(x,y))->getEntity45d250();
      }
     }
    }
    if(fb4.isValid()){
     goal=fb4->getPosition45a4a0();
     if(findPathToGoal5b8d20()&&path24.size9b9a50()<=range_*1.5){
      int idx=si_indexOfEntity9d3110(si_cf25b8,fb4);
      if(idx==-1){si_cf25b8.push_back9b80b0(fb4);si_d37984.push_back9b80b0(ent);}
      else si_d37984[idx]=ent;
     }else fb4.reset9b7270();
    }
   }
  }
   break;
  case 0x16:
   if(f58.operator->()&&si_dist40a3f0(ent->getPosition45a4a0(),f58->getPosition45a4a0())<=20){
    if(v6c.empty9b86e0()||!(*si_cfd44c.atPoint9ced70(v6c[0]))->u66b250()){
     v6c.clear9b3560();
     if(si_cefc4c->getTurn464270()%8){
      SiQ lo,his;
      si_cfd44c.getBounds9b7a40(ent->getPosition45a4a0(),ent->u5c7d30(),lo,his);
      for(int x=lo.x;x<=his.x;x++)for(int y=lo.y;y<=his.y;y++){
       if((*si_cfd44c.at9ceda0(x,y))->u66b250()&&si_cefc4c->isKnown463130(x,y)&&si_dist40a3f0(SiP(x,y),f58->getPosition45a4a0())<=20){
        SiPropInfo*pi=(*si_cfd44c.at9ceda0(x,y))->getProp45d550()->u45cb30();
        if(!pi->f78)pi->f78=new SiObj45b9e0;
        if(pi->f78->u65c1f0(pi,1)==0x70)continue;
        v6c.assign9b3430(1,SiP(x,y));
        goto L124ce;
       }
      }
     }
    }
   L124ce:
    if(!v6c.empty9b86e0()){
     if(si_adjacent4373c0(ent->getPosition45a4a0(),v6c[0])){hack5be7c0(1);do{ent->f40++;ent->clr45b0b0();return (100);}while(false);}
     if(goal.ne409bd0(v6c[0]))goal=v6c[0];
     do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
    }
   }
   break;
  }
 }
 if(!vf0.empty9b86e0()&&f8>=6&&u5815e0()){
  SiTgt*t=u580ec0();
  if(t){goal=t->e->u45a4c0();do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
 }
 if(p118){
  bool done=false;
  if(p118->f4!=-1&&si_cefc4c->getTurn464270()>p118->f4)done=true;
  else switch(p118->f0){
  case 2:{
   SiHI it=ent->u5d24e0(0xa1);
   if(it.isNull9b65d0())done=true;
   else{
    bool b=it->u457fb0();
    if(p118->p10.x==-1||(*si_cfd44c.atPoint9ced70(p118->p10))->getItem45d8f0().isNull9b65d0()||!ent->u5d4ff0(b,(*si_cfd44c.atPoint9ced70(p118->p10))->getItem45d8f0())||ent->u5d4dd0(b,(*si_cfd44c.atPoint9ced70(p118->p10))->getItem45d8f0()).isNull9b65d0()){
     p118->p10.set409ff0(-1);
     int best=9999;
     SiArea wC;
     si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),5,wC);
     int gA;for(int x=wC.x1;x<=wC.x2;x++)for(int y=wC.y1;y<=wC.y2;y++){
      if((*si_cfd44c.at9ceda0(x,y))->getItem45d8f0().isValid()&&(ent->u5d4ff0(b,(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0())||ent->u5d4dd0(b,(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()).isValid())&&!ent->u5c8710(SiP(x,y))){
       gA=si_dist40a3f0(ent->getPosition45a4a0(),SiP(x,y));
       if(p118->p10.x==-1||gA<best){p118->p10.set40a010(x,y);best=gA;}
      }
     }
     if(p118->p10.x==-1)done=true;
    }
    if(!done){
     if(ent->getPosition45a4a0().eq409b90(p118->p10)){
      if(rng.chance(50)){delete p118;p118=0;}
      do{ent->f40++;ent->clr45b0b0();return (100);}while(false);
     }else{goal=p118->p10;do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
    }
   }
  }
   break;
  case 3:
   if(ent->u45a940()==100)done=true;
   else{
    if(p118->p10.x==-1||(*si_cfd44c.atPoint9ced70(p118->p10))->getItem45d8f0().isNull9b65d0()||!(*si_cfd44c.atPoint9ced70(p118->p10))->getItem45d8f0()->u457880()==false){
     p118->p10.set409ff0(-1);
     SiP a7(ent->getPosition45a4a0());
     int best=0;
     SiArea r;
     si_cfd44c.getRect9b4430(a7,5,r);
     for(int x=r.x1;x<=r.x2;x++)for(int y=r.y1;y<=r.y2;y++){
      if((*si_cfd44c.at9ceda0(x,y))->getItem45d8f0().isValid()&&!(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u457880()&&(*si_cfd44c.at9ceda0(x,y))->isPassableFor66ab30(SiHE())&&si_cefc4c->u465200(a7,SiP(x,y))&&(!best||(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u9b6bf0()>best)){
       best=(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u9b6bf0();
       p118->p10.set40a010(x,y);
      }
     }
     if(p118->p10.x==-1)done=true;
    }
    if(!done){
     if(ent->getPosition45a4a0().eq409b90(p118->p10)){
      delete p118;p118=0;
      SiHI it=(*si_cfd44c.atPoint9ced70(ent->getPosition45a4a0()))->getItem45d8f0();
      if(it.isValid()){
       int n=si_minInt9cdb30(it->u9b6bf0(),ent->u5ca670());
       ent->u5deb40(n);
       if(n>=it->u9b6bf0())it->remove57dbe0(0,1,true,true);
       else it->u450460(it->u9b6bf0()-n);
       do{if(si_msg5111e0(((0x27d)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
       do{ent->f40++;ent->clr45b0b0();return (100);}while(false);
      }
     }else{goal=p118->p10;do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
    }
   }
   break;
  }
  if(done){delete p118;p118=0;}
 }
 L133be:
 if(ally114){
  switch(ally114->f4){
  break;
  break;
  case 2:
   if(!f58.operator->())setFollowEntity5b2f80(si_cefc4c->getPlayer4630f0(),0);
   switch(ent->def->f28){
   case 7:
    if(f58->isPlayer5c7600()&&si_cefc4c->u463400(ent)){
    L134cb:
     if(!v6c.empty9b86e0()){
      if(!si_cefc4c->u4633c0(v6c[0])||!(*si_cfd44c.atPoint9ced70(v6c[0]))->u45dcf0())v6c.clear9b3560();
      else if(v6c[0].distanceTo409fb0(ent->getPosition45a4a0())<=1&&(*si_cfd44c.atPoint9ced70(v6c[0]))->getProp45d550()->u44b020()->u65cf50(0)){
       (*si_cfd44c.atPoint9ced70(v6c[0]))->getProp45d550()->u44b020()->f10=0;
       do{if(si_msg5111e0(((0x261)),((&(*si_cfd44c.atPoint9ced70(v6c[0]))->getProp45d550()->getName45c5b0())),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
       do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
      }else if(v6c[0].eq409b90(ent->getPosition45a4a0()))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
      else{goal=v6c[0];do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
     }
     SiQ lo9,hi;
     si_cfd44c.getBounds9b7a40(si_cefc4c->getPlayer4630f0()->getPosition45a4a0(),si_cefc4c->getPlayer4630f0()->u5c7d30(),lo9,hi);
     SiP a3(-1,-1);
     int a9=100000;
     SiP d4(-1,-1);
     int d2=100000;
     const SiP&xC=ent->getPosition45a4a0();
     int jA;for(int x=lo9.x;x<=hi.x;x++)for(int y=lo9.y;y<=hi.y;y++){
      if((*si_cfd44c.at9ceda0(x,y))->u45dcf0()&&(*si_cfd44c.at9ceda0(x,y))->getProp45d550()->pdef9b8f00()->f154&&(*si_cfd44c.at9ceda0(x,y))->getProp45d550()->u44b020()->u65cf50(0)){
       jA=si_dist40a3f0(xC,SiP(x,y));
       if((*si_cfd44c.at9ceda0(x,y))->getProp45d550()->u45cbd0()){
        if(jA<=a9){a9=jA;a3.set40a010(x,y);}
       }else if(jA<=d2){
        SiVPl tmp;
        if(si_cefc4c->isKnown463130(x,y)&&si_cefc4c->u7168e0(ent->getPosition45a4a0(),SiP(x,y),ent.operator->(),tmp)){d2=jA;d4.set40a010(x,y);}
       }
      }
     }
     if(a3.x!=-1){v6c.push_back9b32e0(a3);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}
     else if(d4.x!=-1){v6c.push_back9b32e0(d4);(*si_cfd44c.atPoint9ced70(v6c[0]))->getProp45d550()->u65f170();do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}
    }
    break;
   case 0x3a:
    if(f58->isPlayer5c7600()&&ent->u5d0fe0()){
     if(goal.ne409bd0(f58->getPosition45a4a0()))goal=f58->getPosition45a4a0();
     do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
    }
    break;
   case 10:
    if(ent->def->name=="Hacking Drone"){
     if(v6c.empty9b86e0()||!(*si_cfd44c.atPoint9ced70(v6c[0]))->u66b250()){
      v6c.clear9b3560();
      if(si_cefc4c->getTurn464270()%2){
       SiQ lo,z6;
       si_cfd44c.getBounds9b7a40(ent->getPosition45a4a0(),ent->u5c7d30(),lo,z6);
       for(int x=lo.x;x<=z6.x;x++)for(int y=lo.y;y<=z6.y;y++){
        if(si_cefc4c->isVisible463190(x,y)&&(*si_cfd44c.at9ceda0(x,y))->u66b250()){v6c.assign9b3430(1,SiP(x,y));goto L13ff3;}
       }
      }
     }
    L13ff3:
     if(!v6c.empty9b86e0()){
      if(si_adjacent4373c0(ent->getPosition45a4a0(),v6c[0])){hack5be7c0(0);do{ent->f40++;ent->clr45b0b0();return (100);}while(false);}
      if(goal.ne409bd0(v6c[0]))goal=v6c[0];
      do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
     }
    }else if(ent->def->name=="Minesniffer Drone")goto L134cb;
    break;
   }
   break;
  case 3:case 4:
   if(!f58.operator->())u5b5380(new SiPropPoints(2,si_cefc4c->getPlayer4630f0(),SiP(-1)));
   break;
  case 5:
   if(!ally114->v0c.empty9b86e0()&&ally114->v0c.front9b7060().eq409b90(ent->getPosition45a4a0()))si_eraseAt9d5190(ally114->v0c,0);
   if(ally114->v0c.empty9b86e0())u5b5380(new SiPropPoints(0,SiHE(),ent->getPosition45a4a0()));
   else if(ent->u5d5460(0)){
    SiP n(ally114->v0c.front9b7060());
    if(!si_adjacent4373c0(ent->getPosition45a4a0(),n)){goal=n;do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
    if((*si_cfd44c.atPoint9ced70(n))->u4550b0()){
     if(!(*si_cfd44c.atPoint9ced70(n))->isPassableFor66ab30(ent))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
     else{goal=n;do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
    }
    if(!(*si_cfd44c.atPoint9ced70(n))->u45d330())u5b5380(new SiPropPoints(0,SiHE(),ent->getPosition45a4a0()));
    else{
     (*si_cfd44c.atPoint9ced70(n))->u66a050(si_cefb88->f0,8,0);
     if(rng.chance(50))(*si_cfd44c.atPoint9ced70(n))->u66b700(0,(*si_cfd44c.atPoint9ced70(n))->u45d180());
     if(ally114->v0c.size9b9a50()>1)si_eraseAt9d5190(ally114->v0c,0);
     do{if(si_msg5111e0(((0x258)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     if(si_d1e888->type==0xb&&!si_d1eb10)si_cefc4c->u72ffe0(0);
     do{ent->f40++;ent->clr45b0b0();return (400);}while(false);
    }
   }
   do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
   break;
  case 6:{
   SiVHIl items;
   ent->u5cb830(items);
   for(unsigned i=0;i<items.size9b9260();i++)ent->u642940(items[i],0,0,0,0);
   u5b5380(new SiPropPoints(2,SiHE(),SiP(-1)));
   si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),3,a80);
   do{ent->f40++;ent->clr45b0b0();return (si_b95fc0);}while(false);
  }
   break;
  case 7:{
   int room=ent->u5ca210()-ent->u5c8e20(0);
   int bd;
   if(room>0){
    SiHI bD=(*si_cfd44c.atPoint9ced70(ent->getPosition45a4a0()))->getItem45d8f0();
    if(bD.isValid()&&bD->u457880()>=4&&bD->u4578c0()<=room){
     do{if(si_msg5111e0(((0x280)),((&bD->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     bD->u57a190(ent,4,0,0);
     do{ent->f40++;ent->clr45b0b0();return (si_b95fac);}while(false);
    }
    if(goal.x!=-1&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0().isValid()&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0()->u457880()>=4&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0()->u4578c0()<=room)do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
    else goal.x=-1;
    SiHI best;
    SiQ tmpLo,hi;
    SiP c(si_cefc4c->getPlayer4630f0()->getPosition45a4a0());
    si_cfd44c.getBounds9b7a40(c,si_cefc4c->getPlayer4630f0()->u5c7d30(),tmpLo,hi);
    for(int x=tmpLo.x;x<=hi.x;x++)for(int y=tmpLo.y;y<=hi.y;y++){
     if(si_cefc4c->u463380(x,y)&&(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0().isValid()&&(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u457880()>=4&&(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u4578c0()<=room&&(best.isNull9b65d0()||si_dist40a3f0(c,SiP(x,y))<bd)){
      best=(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0();
      bd=si_dist40a3f0(c,SiP(x,y));
     }
    }
    if(best.isValid()){goal=best->u575920();do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
   }
   u5b5380(new SiPropPoints(2,si_cefc4c->getPlayer4630f0(),SiP(-1)));
   do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
  }
   break;
  case 8:{
   int a4=ent->u5ca210()-ent->u5c8e20(0);
   if(a4<=0){u5b5380(new SiPropPoints(2,si_cefc4c->getPlayer4630f0(),SiP(-1)));do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}
   SiHI c4=(*si_cfd44c.atPoint9ced70(ent->getPosition45a4a0()))->getItem45d8f0();
   if(c4.isValid()&&c4->u457880()>=4&&c4->u4578c0()<=a4){
    do{if(si_msg5111e0(((0x280)),((&c4->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    c4->u57a190(ent,4,0,0);
    do{ent->f40++;ent->clr45b0b0();return (si_b95fac);}while(false);
   }
   if(goal.x!=-1&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0().isValid()&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0()->u457880()>=4&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0()->u4578c0()<=a4)do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   SiHI best;
   int z7;
   SiQ lo3,hi;
   si_cfd44c.getBounds9b7a40(ent->getPosition45a4a0(),10,lo3,hi);
   for(int x=lo3.x;x<=hi.x;x++)for(int y=lo3.y;y<=hi.y;y++){
    if((*si_cfd44c.at9ceda0(x,y))->getItem45d8f0().isValid()&&(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u457880()>=4&&(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u4578c0()<=a4&&(best.isNull9b65d0()||si_dist40a3f0(ent->getPosition45a4a0(),SiP(x,y))<z7)){
     best=(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0();
     z7=si_dist40a3f0(ent->getPosition45a4a0(),SiP(x,y));
    }
   }
   if(best.isValid()){goal=best->u575920();do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
  }
   break;
  case 9:
   if(ent->getGroup45a3f0()->type9b4350()){
    si_logError404f10("EntityAI::takeTurn()::ORDER_EXPLORE","non-FACTION_COGMIND AIs cannot be set to EXPLORE!");
    do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
   }
   if(goal.x==-1||si_cefc4c->u463160(goal)){
    SiP c(goal.x!=-1?goal:ent->getPosition45a4a0());
    if(si_cfe568.u40ca50(c,999999999,si_cefc2c,ent.operator->(),path24,&si_d395ac))goal=path24.back9e8c10();
    else{u5b5380(new SiPropPoints(2,si_cefc4c->getPlayer4630f0(),SiP(-1)));do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}
   }
   do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   break;
  }
 }
 if(f58.operator->()){
  if(f4==1&&f58->ai&&f58->ai->f4==1&&(f58->getPosition45a4a0().eq409b90(f58->ai->v6c.front9b7060())||f58->ai->goal.eq409b90(f58->ai->v6c.front9b7060()))
   ||f4==0xb&&(fb4.isValid()||u459090()&&p11c->u458950(0x16))
   ||f4==0x20&&si_dist40a3f0(ent->getPosition45a4a0(),f58->getPosition45a4a0())<=20
   ||f4==0xf&&f58->isPlayer5c7600()&&(si_cefc4c->getTurn464270()/10%2==0||rng.chance(20))){}
  else{
  L15e5c:
   SiP fp=f58->u45a4c0();
   if(f58->isPlayer5c7600())si_cefc4c->u71cc70(ent,fp);
   else if(ent->getSize45a360()>1&&f58->getSize45a360()>1&&f58->ai45b590()->goalp462e10()->x!=-1&&si_dist40a3f0(f58->getPosition45a4a0(),*f58->ai45b590()->goalp462e10())>=ent->getSize45a360()+7){
    goal=*f58->ai45b590()->goalp462e10();
    do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   }
   if(f68>0&&goal.x==-1&&si_dist40a3f0(ent->getPosition45a4a0(),fp)<=ent->getSize45a360()+5){
    f68--;
    do{}while(false);
    do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
   }
   f68=0;
   if(goal.x!=-1&&abs(goal.x-fp.x)<ent->getSize45a360()+3&&abs(goal.y-fp.y)<ent->getSize45a360()+3&&(f58!=si_cefc4c->getPlayer4630f0()||!(*si_cfd44c.atPoint9ced70(goal))->u66b3d0(ent.operator->())))do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   if(u5b9860()){do{}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
   goal.x=-1;
   do{}while(false);
   do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
  }
 }
 switch(f4){
 case 1:
  if(v6c.size9b9a50()>1&&ent->getSize45a360()>1&&si_cefc4c->getTurn464270()%20==0)v6c.erase9b34c0(v6c.begin9c1270()+1,v6c.end9e9b30());
  if(ally114&&ally114->f4==0&&ent->getSize45a360()>1&&si_dist40a3f0(ent->getPosition45a4a0(),si_cefc4c->getPlayer4630f0()->getPosition45a4a0())<=4){
   SiP a8(ent->getPosition45a4a0());
   int aFp=ent->getSize45a360();
   int two=2;
   SiArea r;
   si_cfd44c.getRect9b4430(si_cefc4c->getPlayer4630f0()->getPosition45a4a0(),2,r);
   if(r.containsAny40b780(*ent->u45d1a0())&&a8.x>1&&a8.y>1&&a8.x+aFp<si_cfd44c.width9fcd80()-1&&a8.y+aFp<si_cfd44c.height9b8f00()){
    SiView view;
    view.init9cffc0(si_cfd44c.width9fcd80(),si_cfd44c.height9b8f00(),-9999);
    view.resizeView9d0050(a8.x-1,a8.y-1,aFp+2,aFp+2,false);
    for(int x=view.left9b6bf0();x<=view.right9b6c10();x++)for(int y=view.top44afb0();y<=view.bottom9b6c30();y++){
     if(!(*si_cfd44c.at9ceda0(x,y))->isPassableFor66ab30(ent)||(*si_cfd44c.at9ceda0(x,y))->getEntity45d250().isValid()&&((*si_cfd44c.at9ceda0(x,y))->getEntity45d250()!=ent&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->getSize45a360()>1||(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->isPlayer5c7600()&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->u5cad50()&&si_ba0984[si_cefb38]||(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->getFaction45a2c0()==0xb))view(x,y)=-9999;
     else if(r.u40b700(x,y))view(x,y)=-2;
     else if((*si_cfd44c.at9ceda0(x,y))->terr9fcd80()==caveinWallTerrain)view(x,y)=0;
     else if((*si_cfd44c.at9ceda0(x,y))->isDoor45dda0())view(x,y)=-4;
     else view(x,y)=2;
    }
    int total=0;
    for(int x=a8.x;x<a8.x+aFp;x++)for(int y=a8.y;y<a8.y+aFp;y++)total+=view(x,y);
    SiQ2 pD;
    SiVI5 at5(8,0);
    for(int d=0;d<8;d++){
     pD=a8.add409b60(si_d015d8[d]);
     for(int x=pD.x;x<pD.x+aFp;x++)for(int y=pD.y;y<pD.y+aFp;y++)at5[d]+=view(x,y);
    }
    int best=si_fn9d4340(at5);
    if(best>total){
     SiVI2 idx;
     for(unsigned i=0;i<at5.size9b9260();i++)if(at5[i]==best)idx.push_back9b9280(i);
     v6c.back9e8c10()=a8.add409b60(si_d015d8[si_randomRec9d5d00(idx)]);
    }
   }
  }
  if(goal.ne409bd0(v6c.back9e8c10()))goal=v6c.back9e8c10();
  if(ent->getPosition45a4a0().ne409bd0(goal))do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
  else if(v6c.size9b9a50()>1)v6c.pop_back9b33e0();
  do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
  break;
 case 2:
  if(v6c.empty9b86e0())setPatrolRandom5b3430(ent->getPosition45a4a0());
  if(ent->getPosition45a4a0().eq409b90(v6c.front9b7060())){
   si_moveElement9d9020(v6c,0,v6c.size9b9a50()-1);
   goal=v6c.front9b7060();
   do{}while(false);
  }else if(goal.x==-1){goal=v6c.front9b7060();do{}while(false);}
  do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
  break;
 case 3:
  if(goal.x==-1||ent->getPosition45a4a0().eq409b90(goal))u5b91e0();
  if(!v90.empty9b86e0()&&si_fn9d0ce0(v90,ent->getPosition45a4a0())||v90.empty9b86e0()&&a80.contains40b750(ent->getPosition45a4a0()))do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
  else do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
  break;
 case 4:{
  bool b3=ent->getAiType45a2a0()==3;
  SiVPl cells7;
  si_sweep4faaf0(ent->getPosition45a4a0(),cells7);
  if(!b3&&u459090()){
   if(p11c->u458950(7)){
    SiRec*r7=p11c->u458950(7);
    SiRec*ats=p11c->u458950(8);
    if(!r7->f18.operator->()){u459150(r7);if(ats)u459150(ats);}
    else if(si_cefc4c->getTurn464270()>r7->f4&&!ats){
     if(ent->u5c8820(r7->f18))do{if(si_msg5111e0(((0x250)),((&r7->f18->name416f40())),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     r7->f18->ai45b590()->setField451440(SiHE());
     u459150(r7);
    }else if(!ent->u5c8820(r7->f18)){
     if(goal.ne409bd0(r7->f18->getPosition45a4a0()))goal=r7->f18->getPosition45a4a0();
     do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
    }else if(ats){
     if((*si_cfd44c.atPoint9ced70(r7->f18->getPosition45a4a0()))->u45dd40(0xe)){
      do{if(si_msg5111e0(((0x252)),((&r7->f18->name416f40())),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      if(si_cefc4c->isVisible4631c0(r7->f18->getPosition45a4a0()))(*si_cfd44c.atPoint9ced70(r7->f18->getPosition45a4a0()))->getProp45d550()->u65f170();
      if(si_d25450.on&&r7->f18->ai45b590()->f8>=6&&si_cefc4c->u4631f0(ent))si_d25450.u69e700(0x1d,0,0.0f);
      int id=(*si_cfd44c.atPoint9ced70(r7->f18->getPosition45a4a0()))->getProp45d550()->u44b020()->f4;
      SiVRecs*recs=si_cefc4c->u45c7e0();
      for(unsigned i=0;i<recs->size9b9260();i++){
       if((*recs)[i]->f0==id){(*recs)[i]->add460a00(r7->f18);break;}
      }
      r7->f18->u637bb0();
      u459150(r7);
      u459150(ats);
      goto L183c5;
     }
     if((goal.x==-1||!(*si_cfd44c.atPoint9ced70(goal))->u45dd40(0xe))&&!u5b6130(goal)){
      u459150(r7);
      u459150(ats);
      goto L183c5;
     }
     do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
    }else{
     if(r7->v8.empty9b86e0()||r7->v8.front9b7060().ne409bd0(r7->f18->getPosition45a4a0())){
      r7->v8.assign9b3430(1,r7->f18->getPosition45a4a0());
      do{if(si_msg5111e0(((0x24f)),((&r7->f18->name416f40())),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      si_454260(ent->getPosition45a4a0(),0xa4);
      if(si_cefc4c->u4631f0(ent)){
       SiPropDef*pd;
       si_lookup9d7980("Worker_Latch",pd);
       if(pd){
        si_cefc50->u508610(si_cefc50,pd,ent->getPosition45a4a0(),&si_d2e20c,0,0,0,9,0)->init503b20();
        SiVPl*occ=r7->f18->u45d1a0();
        for(unsigned i=0;i<occ->size9b9a50();i++){
         if(si_cefc4c->isVisible4631c0((*occ)[i]))si_cefc50->u508610(si_cefc50,pd,(*occ)[i],&si_d2e20c,0,0,0,9,0)->init503b20();
        }
       }
      }
     }
     return 100;
    }
   }else if(p11c->u458950(6)){
    SiRec*r6=p11c->u458950(6);
    while(!r6->v8.empty9b86e0()&&(*si_cfd44c.atPoint9ced70(r6->v8.front9b7060()))->getProp45d550().isNull9b65d0()){
     if(r6->v8.size9b9a50()==1)goal=r6->v8.front9b7060();
     si_eraseAt9d5190(r6->v8,0);
    }
    if(!r6->v8.empty9b86e0()){
     if(si_adjacent4373c0(ent->getPosition45a4a0(),r6->v8.front9b7060())){
      SiP hub4(r6->v8.front9b7060());
      do{if(si_msg5111e0(((0x24b)),((&(*si_cfd44c.atPoint9ced70(hub4))->getProp45d550()->getName45c5b0())),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      si_454260(ent->getPosition45a4a0(),0x135);
      SiHE self=ent;
      bool isHub=(*si_cfd44c.atPoint9ced70(hub4))->getProp45d550()->tag45c590()=="HUB_Network_Hub";
      (*si_cfd44c.atPoint9ced70(hub4))->getProp45d550()->u45ce10(1,1,0,SiHE());
      si_cefc4c->u71e7c0(hub4,si_d2c3b0.randomInRange40c130(),0);
      if(!self.operator->()||isHub)return 100;
      else{si_eraseAt9d5190(r6->v8,0);do{ent->f40++;ent->clr45b0b0();return (300);}while(false);}
     }
     if(goal.ne409bd0(r6->v8.front9b7060())){
      goal=r6->v8.front9b7060();
      bool ok=true;
      if(!findPathToGoal5b8d20()){
       ok=false;
       for(unsigned i=1;i<r6->v8.size9b9a50();i++){
        goal=r6->v8[i];
        if(findPathToGoal5b8d20()){si_moveElement9d9020(r6->v8,i,0);ok=true;break;}
       }
      }
      if(ok)do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
      else{u459150(r6);goto L183c5;}
     }else do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
    }
   }
  }
 L183c5:
  if(!b3){
   if(!si_cefc4c->u463040())goto L18c79;
   if(fb4.isValid()&&(!fb4.operator->()||!fb4->getTarget45a760()))fb4.reset9b7270();
   if(fb4.isNull9b65d0()&&(rng.chance(20)||ent->u5c7fa0()<=2)){
    SiArea r;
    si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),6,r);
    for(int x=r.x1;x<=r.x2;x++)for(int y=r.y1;y<=r.y2;y++){
     if((*si_cfd44c.at9ceda0(x,y))->getEntity45d250().isValid()&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()!=ent&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->getTarget45a760()&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->getSize45a360()==1&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->ai45b590()&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->ai45b590()->fb4.isNull9b65d0()){
      fb4=(*si_cfd44c.at9ceda0(x,y))->getEntity45d250();
      (*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->ai45b590()->fb4=ent;
      goto L18715;
     }
    }
   }
  L18715:
   if(fb4.isValid()){
    bool adjTmp=ent->u5c8820(fb4);
    if(adjTmp&&(*si_cfd44c.atPoint9ced70(fb4->getPosition45a4a0()))->u45dd40(0xe)){
     do{if(si_msg5111e0(((0x252)),((&fb4->name416f40())),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     if(si_cefc4c->isVisible4631c0(fb4->getPosition45a4a0()))(*si_cfd44c.atPoint9ced70(fb4->getPosition45a4a0()))->getProp45d550()->u65f170();
     fb4->u637bb0();
     fb4.reset9b7270();
    }else{
     fb4->u5fda70(1);
     if(!adjTmp){
      if(goal.ne409bd0(fb4->getPosition45a4a0()))goal=fb4->getPosition45a4a0();
      fb8.reset9b7270();
      do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);
     }else{
      if((goal.x==-1||!(*si_cfd44c.atPoint9ced70(goal))->u45dd40(0xe))&&!u5b6130(goal))goto L18c79;
      if(fb8!=fb4){
       fb8=fb4;
       do{if(si_msg5111e0(((0x24f)),((&fb4->name416f40())),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
       si_454260(ent->getPosition45a4a0(),0xa4);
       if(si_cefc4c->u4631f0(ent)){
        SiPropDef*pd;
        si_lookup9d7980("Worker_Latch",pd);
        if(pd){
         si_cefc50->u508610(si_cefc50,pd,ent->getPosition45a4a0(),&si_d2e20c,0,0,0,9,0)->init503b20();
         SiVPl*occ=fb8->u45d1a0();
         for(unsigned i=0;i<occ->size9b9a50();i++){
          if(si_cefc4c->isVisible4631c0((*occ)[i]))si_cefc50->u508610(si_cefc50,pd,(*occ)[i],&si_d2e20c,0,0,0,9,0)->init503b20();
         }
        }
       }
      }
      do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);
     }
    }
   }
  }
 L18c79:
  for(unsigned i=0;i<cells7.size9b9a50();i++){
   if((*si_cfd44c.atPoint9ced70(cells7[i]))->u45de40()){
    if(b3){
     SiHE h=si_cefc4c->u71e7c0(cells7[i],rng.rangeInt(1.0f,5.0f),0);
     if(h.isValid())si_cefc4c->u464840(h);
     do{if(si_msg5111e0(((0x24a)),((&string("debris"))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     do{ent->f40++;ent->clr45b0b0();return (1500);}while(false);
    }else{
     SiHI w=ent->u5cbd10();
     if(w.isValid())w->u44fc60(si_minInt9cdb30(w->u45cb30()+rng.rangeInt(1.0f,5.0f),w->u457fb0()));
     do{if(si_msg5111e0(((0x249)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     do{ent->f40++;ent->clr45b0b0();return (300);}while(false);
    }
   }
  }
  if(b3){
   for(unsigned i=0;i<cells7.size9b9a50();i++){
    if((*si_cfd44c.atPoint9ced70(cells7[i]))->getItem45d8f0().isValid()&&(*si_cfd44c.atPoint9ced70(cells7[i]))->getItem45d8f0()->u457e30()){
     SiHI it=(*si_cfd44c.atPoint9ced70(cells7[i]))->getItem45d8f0();
     do{if(si_msg5111e0(((0x24a)),((&it->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     int n=rng.rangeInt(5.0f,it->u9b6bf0()/2+1);
     it->remove57dbe0(0,0,true,true);
     SiHE h5=si_cefc4c->u71e7c0(cells7[i],n,0);
     if(h5.isValid())si_cefc4c->u464840(h5);
     do{ent->f40++;ent->clr45b0b0();return (600);}while(false);
    }
   }
  }
  if(!b3&&rng.chance(20)){
   SiP target(-1);
   for(unsigned i=0;i<cells7.size9b9a50();i++){
    if((*si_cfd44c.atPoint9ced70(cells7[i]))->getProp45d550().isValid()&&(*si_cfd44c.atPoint9ced70(cells7[i]))->getProp45d550()->pdef9b8f00()->ff4&&!(*si_cfd44c.atPoint9ced70(cells7[i]))->getProp45d550()->u457b10()){target=cells7[i];break;}
   }
   if(target.x!=-1){do{if(si_msg5111e0(((0x24e)),((&(*si_cfd44c.atPoint9ced70(target))->getProp45d550()->getName45c5b0())),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);do{ent->f40++;ent->clr45b0b0();return (300);}while(false);}
  }
  if(goal.x!=-1&&((*si_cfd44c.atPoint9ced70(goal))->u45d230()||b3&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0().isValid()&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0()->u457e30())&&(*si_cfd44c.atPoint9ced70(goal))->isPassableFor66ab30(ent))do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
  SiQ a1,hi2;
  si_cfd44c.getBoundsB9b79c0(ent->getPosition45a4a0(),4,ent->def->f9c+4,a1,hi2);
  SiP best(-1,-1);
  int aH=100000;
  SiP&aN=ent->getPosition45a4a0();
  int d8;for(int x=a1.x;x<=hi2.x;x++)for(int y=a1.y;y<=hi2.y;y++){
   if(((*si_cfd44c.at9ceda0(x,y))->u45d230()||b3&&(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0().isValid()&&(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u457e30())&&(*si_cfd44c.at9ceda0(x,y))->isPassableFor66ab30(SiHE())){
    d8=si_dist40a3f0(aN,SiP(x,y));
    if(d8<=aH){aH=d8;best.set40a010(x,y);}
   }
  }
  if(best.x!=-1){goal=best;do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
  if(goal.x==-1||aN.eq409b90(goal))u5b91e0();
  do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
 }
  break;
 case 5:
  if(si_cf0fa8.empty9b86e0()&&!si_cefbb4||si_cefc4c->u4658e0()||!ent->u5d5520(0)||p11c&&p11c->u458950(9)){
  L19c0d:
   if(goal.x==-1||ent->getPosition45a4a0().eq409b90(goal))u5b91e0();
   do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
  }
  if(!si_cf0fa8.empty9b86e0()){
   if(si_fn6c10f0(ent->getPosition45a4a0())!=-1){
    SiP me(ent->getPosition45a4a0());
    if(!si_cfb844[si_cf0fa8[si_ce9ff4]->f8]->b58){
     SiVPl cells0;
     si_sweep4faaf0(me,cells0);
     SiVU a;
     SiVU b;
     for(unsigned i=0;i<cells0.size9b9a50();i++){
      if((*si_cfd44c.atPoint9ced70(cells0[i]))->isPassableFor66ab30(SiHE())&&(*si_cfd44c.atPoint9ced70(cells0[i]))->getEntity45d250().isNull9b65d0()){
       if((*si_cfd44c.atPoint9ced70(cells0[i]))->terr9fcd80()==si_cefb88)b.push_back9b9d30(i);
       else a.push_back9b9d30(i);
      }
     }
     if(a.empty9b86e0()&&b.empty9b86e0())do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
     me=cells0[a.empty9b86e0()?si_randomRec9d5d00(b):si_randomRec9d5d00(a)];
    }
    return u5b6a60(ent->getPosition45a4a0(),me);
   }
   SiQ lo,e19;
   si_cfd44c.getBoundsB9b79c0(ent->getPosition45a4a0(),1,ent->def->f9c,lo,e19);
   for(int x=lo.x;x<=e19.x;x++)for(int y=lo.y;y<=e19.y;y++){
    if(!ent->u45a510(SiP(x,y))&&si_fn6c10f0(SiP(x,y))!=-1&&!(*si_cfd44c.at9ceda0(x,y))->u45d310()){
     if((*si_cfd44c.at9ceda0(x,y))->getEntity45d250().isValid()&&!si_cfb844[si_cf0fa8[si_ce9ff4]->f8]->b58){
      if((*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->getGroup45a3f0()->type9b4350()==4&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->getSize45a360()==1){
       SiQ q;
       if(si_cefc4c->findPlaceableNear71c150(ent->getPosition45a4a0(),q,1)){(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->changePos5dccb0(q,true);goto L5a;}
      }
      do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
     }
    L5a:
     return u5b6a60(SiP(x,y),ent->getPosition45a4a0());
    }
   }
   if(goal.x==-1||si_fn6c10f0(goal)==-1){
    SiP t(-1);
    int tries=0;
    do{
     if(si_cf0fa8.empty9b86e0())break;
     if(tries==10)goto L1a6e1;
     if(fa4.x1!=-1){
      SiVPl inA;
      for(unsigned i=0;i<si_cf0fa8.size9b9260();i++)if(fa4.contains40b750(*si_cf0fa8[i]))inA.push_back9b32e0(*si_cf0fa8[i]);
      if(inA.empty9b86e0())goto L1a6e1;
      else t=si_randomPoint9d5350(inA);
     }else t=*si_randomRec9d5d00(si_cf0fa8);
     tries++;
    }while((si_dist40a3f0(ent->getPosition45a4a0(),t)>25||si_fn6c10f0(t)==-1)&&!si_cf0fa8.empty9b86e0());
    goal=t;
   }
   do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
  }
 L1a6e1:
  if(!si_cefbb4)goto L19c0d;
  else{
   if(fcc>=0&&(!si_cf44b0[fcc]||si_cf44b0[fcc]->b4))fcc=-1;
   if(fcc==-1){
    for(unsigned i=0;i<si_cf44b0.size9b9260();i++){
     if(si_cf44b0[i]&&!si_cf44b0[i]->b4&&si_dist40a3f0(ent->getPosition45a4a0(),si_cf44b0[i]->vc[0])<=20&&si_dist40a3f0(si_cefc4c->getPlayer4630f0()->getPosition45a4a0(),si_cf44b0[i]->vc[0])<=15){fcc=i;break;}
    }
   }
   if(fcc==-1)goto L19c0d;
   else{
    SiPL*pl=si_cf44b0[fcc];
    if(pl->u6c11f0(ent->getPosition45a4a0())){
     SiP me(ent->getPosition45a4a0());
     SiVPl g31;
     si_sweep4faaf0(me,g31);
     SiVU a;
     for(unsigned i=0;i<g31.size9b9a50();i++){
      if((*si_cfd44c.atPoint9ced70(g31[i]))->isPassableFor66ab30(SiHE())&&(*si_cfd44c.atPoint9ced70(g31[i]))->getEntity45d250().isNull9b65d0())a.push_back9b9d30(i);
     }
     if(a.empty9b86e0())do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
     me=g31[si_randomRec9d5d00(a)];
     return u5b6d40(ent->getPosition45a4a0(),me);
    }
    SiQ lo8,g22;
    si_cfd44c.getBoundsB9b79c0(ent->getPosition45a4a0(),1,ent->def->f9c,lo8,g22);
    for(int x=lo8.x;x<=g22.x;x++)for(int y=lo8.y;y<=g22.y;y++){
     if(!ent->u45a510(SiP(x,y))&&pl->u6c11f0(SiP(x,y))){
      if((*si_cfd44c.at9ceda0(x,y))->getEntity45d250().isValid()){
       if((*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->getGroup45a3f0()->type9b4350()==4&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->getSize45a360()==1){
        SiQ q;
        if(si_cefc4c->findPlaceableNear71c150(ent->getPosition45a4a0(),q,1)){(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->changePos5dccb0(q,true);goto L5b;}
       }
       {
        if((*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->getGroup45a3f0()->type9b4350()<=1&&rng.chance(si_b92f64[si_d1e860.getDepthIndex()]/2)){
         if(u581140())do{if(si_msg5111e0(((0x236)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
         else si_cf6428.u682220(ent->getPosition45a4a0());
        }
        do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
       }
      }
     L5b:
      return u5b6d40(SiP(x,y),ent->getPosition45a4a0());
     }
    }
    if(goal.x==-1||!pl->u6c11f0(goal)){
     SiVPf*v=&pl->vc;
     for(unsigned i=0;i<v->size9b9a50();i++)if(pl->u6c11f0((*v)[i])){goal=(*v)[i];break;}
    }
    do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   }
  }
  break;
 case 6:
  if(ent->u5d5460(0)){
   if(p11c&&p11c->u458950(0xb)){
    SiRec*r=p11c->u458950(0xb);
    if(si_cefc4c->getTurn464270()>r->f4){
     for(unsigned i=2;i<r->v8.size9b9a50();i++){
      SiP pt(r->v8[i]);
      si_fn6c0f10(pt,si_cefb9c->f0,0);
      SiVPl g45;
      si_sweep4faaf0(pt,g45);
      for(unsigned j=0;j<g45.size9b9a50();j++){
       if((*si_cfd44c.atPoint9ced70(g45[j]))->terr9fcd80()==caveinEarthTerrain)si_fn6c0f10(g45[j],caveinWallTerrain->f0,0);
      }
     }
     p11c->u458a10(0xb);
    }else{
     SiVPl aAdj;
     si_adj4fab80(ent->getPosition45a4a0(),aAdj);
     for(unsigned i=0;i<aAdj.size9b9a50();i++){
      if((*si_cfd44c.atPoint9ced70(aAdj[i]))->getEntity45d250().isValid()&&(*si_cfd44c.atPoint9ced70(aAdj[i]))->getEntity45d250()->getGroup45a3f0()->type9b4350()==1)do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
     }
     if(r->v8[1].x==0&&rng.chance(15)){
      r->v8[0]=si_d015d8[rng.rangeInt(0.0f,3.0f)*2];
      r->v8[1].set40a010(si_d22260.randomInRange40c130(),0);
     }
     SiP n=ent->getPosition45a4a0().add409b60(r->v8[0]);
     if(!si_cfd44c.contains9b43b0(n)||si_cfd44c.isEdge9b7960(n)){
      r->v8[0]=si_d015d8[rng.rangeInt(0.0f,3.0f)*2];
      r->v8[1].set40a010(si_d22260.randomInRange40c130(),0);
      if(si_cfd44c.isEdge9b7960(ent->getPosition45a4a0())){
       if(ent->getPosition45a4a0().x==0)r->v8[0]=si_d015d8[2];
       else if(ent->getPosition45a4a0().y==0)r->v8[0]=si_d015d8[4];
       else if(ent->getPosition45a4a0().x==si_cfd44c.width9fcd80()-1)r->v8[0]=si_d015d8[6];
       else r->v8[0]=si_d015d8[0];
      }
      do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
     }
     if((*si_cfd44c.atPoint9ced70(n))->getEntity45d250().isValid()){
      if(r->v8[1].y>=3){
       r->v8[0]=si_d015d8[rng.rangeInt(0.0f,3.0f)*2];
       r->v8[1].set40a010(si_d22260.randomInRange40c130(),0);
      }else r->v8[1].y++;
      do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
     }
     if((*si_cfd44c.atPoint9ced70(n))->u45d330()){
      if(r->v8[1].x!=0)r->v8[1].x--;
      r->v8.push_back9b32e0(n);
      (*si_cfd44c.atPoint9ced70(n))->u66a050(si_cefb88->f0,2,0);
      if(rng.chance(50))(*si_cfd44c.atPoint9ced70(n))->u66b700(0,(*si_cfd44c.atPoint9ced70(n))->u45d180());
      do{if(si_msg5111e0(((0x258)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      do{ent->f40++;ent->clr45b0b0();return (200);}while(false);
     }else if((*si_cfd44c.atPoint9ced70(n))->isPassableFor66ab30(ent)){
      if(r->v8[1].x!=0)r->v8[1].x--;
      goal=n;
      do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
     }else{
      r->v8[0]=si_d015d8[rng.rangeInt(0.0f,3.0f)*2];
      r->v8[1].set40a010(si_d22260.randomInRange40c130(),0);
      do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
     }
    }
   }
   if(!v6c.empty9b86e0()){
    if(v6c.size9b9a50()==3){
     if(si_cefc4c->isVisible4631c0(ent->getPosition45a4a0())||ent->getPosition45a4a0().distanceTo409fb0(si_cefc4c->getPlayer4630f0()->getPosition45a4a0())<=10)v6c.pop_back9b33e0();
     else do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
    }
    if(v6c.front9b7060().x==-1){
     if(ent->getPosition45a4a0().ne409bd0(v6c[1]))si_eraseAt9d5190(v6c,0);
    }else if(ent->getPosition45a4a0().eq409b90(v6c[0])){
     si_fn6c0f10(v6c[0],si_cefbb0->f0,0);
     v6c.clear9b3560();
     SiP g49(ent->getPosition45a4a0());
     SiVPl theAdj;
     si_adj4fab80(g49,theAdj);
     int g51=0;
     int idx;
     for(unsigned i=0;i<theAdj.size9b9a50();i++){
      if(!(*si_cfd44c.atPoint9ced70(theAdj[i]))->u4550b0()){g51++;idx=i;}
     }
     if(g51==1){
      SiVPl line;
      g49.op409a30(g49.sub409b30(theAdj[idx]));
      line.push_back9b32e0(g49);
      SiP oldD=ent->getPosition45a4a0().sub409b30(theAdj[idx]);
      g49.op409a30(oldD);
      while(si_cfd44c.contains9b43b0(g49)&&(*si_cfd44c.atPoint9ced70(g49))->u4550b0()){line.push_back9b32e0(g49);g49.op409a30(oldD);}
      if(line.size9b9a50()<=3){
       for(unsigned i=0;i<line.size9b9a50();i++)si_fn6c0f10(line[i],si_cefbb0->f0,0);
      }
     }
    }
   }
   SiQ vLo,hi;
   si_cfd44c.getBoundsB9b79c0(ent->getPosition45a4a0(),1,ent->def->f9c,vLo,hi);
   for(int x=vLo.x;x<=hi.x;x++)for(int y=vLo.y;y<=hi.y;y++){
    if(!ent->u45a510(SiP(x,y))&&(*si_cfd44c.at9ceda0(x,y))->u45d310()){
     (*si_cfd44c.at9ceda0(x,y))->u66a050(si_cefb88->f0,5,0);
     u5b7340(SiP(x,y));
     if(rng.chance(50))(*si_cfd44c.at9ceda0(x,y))->u66b700(0,(*si_cfd44c.at9ceda0(x,y))->u45d180());
     do{if(si_msg5111e0(((0x258)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     int ret=400;
     if(ent->getGroup45a3f0()->type9b4350()==4&&si_d1e888->f8==10&&(si_d1e888->type==2||si_d1e888->type==7)&&si_d1eaac){
      SiV6e*v=si_cefc4c->u462e10b();
      for(unsigned i=0;i<v->size9b9260();i++){
       if((*v)[i]->h8->type==0xf){
        if(si_dist40a3f0(ent->getPosition45a4a0(),*(*v)[i])<=5&&(rng.chance(0x42)||si_dist40a3f0(ent->getPosition45a4a0(),si_cefc4c->getPlayer4630f0()->getPosition45a4a0())>20))ret=5000;
        break;
       }
      }
     }
     do{ent->f40++;ent->clr45b0b0();return (ret);}while(false);
    }
   }
   if(goal.x!=-1&&(*si_cfd44c.atPoint9ced70(goal))->u45d310())do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   SiP old(goal);
   int range=6;
   const SiP&b8=ent->getPosition45a4a0();
   SiCell*c;
   if(rng.chance(50)){
    for(int x=b8.x-1;x>=b8.x-range&&x>=0;x--){c=*si_cfd44c.at9ceda0((x),(b8.y));if(c->u45d310()){goal.set40a010((x),(b8.y));if(findPathToGoal5b8d20())do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}if(!c->isPassableFor66ab30(SiHE())||c->getEntity45d250().isValid()&&c->getEntity45d250()->ai45b590()&&c->getEntity45d250()->ai45b590()->f4==6)break;}
    for(int x=b8.x+ent->def->f9c;x<=b8.x+ent->def->f9c+range&&x<si_cfd44c.width9fcd80();x++){c=*si_cfd44c.at9ceda0((x),(b8.y));if(c->u45d310()){goal.set40a010((x),(b8.y));if(findPathToGoal5b8d20())do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}if(!c->isPassableFor66ab30(SiHE())||c->getEntity45d250().isValid()&&c->getEntity45d250()->ai45b590()&&c->getEntity45d250()->ai45b590()->f4==6)break;}
    for(int y=b8.y-1;y>=b8.y-range&&y>=0;y--){c=*si_cfd44c.at9ceda0((b8.x),(y));if(c->u45d310()){goal.set40a010((b8.x),(y));if(findPathToGoal5b8d20())do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}if(!c->isPassableFor66ab30(SiHE())||c->getEntity45d250().isValid()&&c->getEntity45d250()->ai45b590()&&c->getEntity45d250()->ai45b590()->f4==6)break;}
    for(int y=b8.y+ent->def->f9c;y<=b8.y+ent->def->f9c+range&&y<si_cfd44c.height9b8f00();y++){c=*si_cfd44c.at9ceda0((b8.x),(y));if(c->u45d310()){goal.set40a010((b8.x),(y));if(findPathToGoal5b8d20())do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}if(!c->isPassableFor66ab30(SiHE())||c->getEntity45d250().isValid()&&c->getEntity45d250()->ai45b590()&&c->getEntity45d250()->ai45b590()->f4==6)break;}
   }else{
    for(int x=b8.x-1,y=b8.y-1;x>=b8.x-range/2&&x>=0&&y>=0;x--,y--){c=*si_cfd44c.at9ceda0((x),(y));if(c->u45d310()){goal.set40a010((x),(y));if(findPathToGoal5b8d20())do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}if(!c->isPassableFor66ab30(SiHE())||c->getEntity45d250().isValid()&&c->getEntity45d250()->ai45b590()&&c->getEntity45d250()->ai45b590()->f4==6)break;}
    for(int x=b8.x+1,y=b8.y-1;x<=b8.x+ent->def->f9c+range/2&&x<si_cfd44c.width9fcd80()&&y>=0;x++,y--){c=*si_cfd44c.at9ceda0((x),(y));if(c->u45d310()){goal.set40a010((x),(y));if(findPathToGoal5b8d20())do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}if(!c->isPassableFor66ab30(SiHE())||c->getEntity45d250().isValid()&&c->getEntity45d250()->ai45b590()&&c->getEntity45d250()->ai45b590()->f4==6)break;}
    for(int x=b8.x-1,y=b8.y+1;x>=b8.x-range/2&&x>=0&&y<si_cfd44c.height9b8f00();x--,y++){c=*si_cfd44c.at9ceda0((x),(y));if(c->u45d310()){goal.set40a010((x),(y));if(findPathToGoal5b8d20())do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}if(!c->isPassableFor66ab30(SiHE())||c->getEntity45d250().isValid()&&c->getEntity45d250()->ai45b590()&&c->getEntity45d250()->ai45b590()->f4==6)break;}
    for(int x=b8.x+1,y=b8.y+1;x<=b8.x+ent->def->f9c+range/2&&x<si_cfd44c.width9fcd80()&&y<si_cfd44c.height9b8f00();x++,y++){c=*si_cfd44c.at9ceda0((x),(y));if(c->u45d310()){goal.set40a010((x),(y));if(findPathToGoal5b8d20())do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}if(!c->isPassableFor66ab30(SiHE())||c->getEntity45d250().isValid()&&c->getEntity45d250()->ai45b590()&&c->getEntity45d250()->ai45b590()->f4==6)break;}
   }
   goal=old;
  }
  if(goal.x==-1||ent->getPosition45a4a0().eq409b90(goal))u5b91e0();
  do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
  break;
 case 7:{
  bool isT3=ent->getAiType45a2a0()==3;
  int cap=ent->u5c8e20(0);
  if(cap&&!isT3){
   SiP pt=u5ba650(3,1);
   if(pt.x!=-1){
    SiPropInfo*pi=(*si_cfd44c.atPoint9ced70(pt))->getProp45d550()->u45cb30();
    SiHI as=ent->u5cbc80();
    do{if(si_msg5111e0(((0x25a)),((&as->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    if(!si_cefc4c->u463be0()[0xd].empty9b86e0()){
     string msg=pi->u65cc80()+" accepting "+as->getName571db0(0,0)+" ("+si_intToString(as->u457ca0())+"%)";
     do{if(si_msg5111e0((0x1d6),(&string("MONITOR")),(&msg),(0),(SiHE()),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     SiVMk&mk=si_cefc4c->u463ec0()[0];
     for(unsigned i=0;i<mk.size9b9260();i++){if(mk[i]->p8.eq409b90(pt))goto L7a;}
     mk.push_back9b7cf0(si_cefaa8->createC793190());
     mk.back9b6540()->u6c20b0(0,pt,3);
     if(!si_cefc4c->isVisible4631c0(pt))si_cec034->u987de0();
    L7a:;
    }
    if(si_containsRecord9db330(pi->v40,0xe)){
     do{if(si_msg5111e0(((0x1cb)),((&as->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     SiP p(ent->getPosition45a4a0());
     if((*si_cfd44c.atPoint9ced70(p))->getItem45d8f0().isValid()){
      SiV7 v(1,p);
      if(!si_cefc4c->u71ec60(p,v))(*si_cfd44c.atPoint9ced70(p))->getItem45d8f0()->remove57dbe0(0,0,true,true);
     }
     as->u57a0f0(p,0,0);
    }else if(as->getEffect457b70(0x56)){
     do{if(si_msg5111e0(0xcd,&as->getName571db0(0,0),0,0,SiHE(),SiHE(),&pt,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     int r=as->def9b4350()->f1a8;
     as->remove57dbe0(0,0,true,true);
     if(r==0){}
     else{
      SiHE me=ent;
      si_cefc4c->addRecord777a20(si_cefaa8->createA7930e0(new SiExpl(SiHE(),r,pt,SiHE(),SiP(-1),SiP(-1))));
      if(!me.operator->())return 100;
     }
    }else{
     SiVHI5&v=si_cf3a10[(*si_cfd44c.atPoint9ced70(pt))->getProp45d550()->u44ab40()];
     as->u57a520((*si_cfd44c.atPoint9ced70(pt))->getProp45d550(),0);
     v.push_back9b80b0(as);
    }
    do{ent->f40++;ent->clr45b0b0();return (300);}while(false);
   }
  }
  if(cap>=ent->u5ca210()){
   if(isT3)goto L7b;
   if(goal.x!=-1&&(*si_cfd44c.atPoint9ced70(goal))->u66b1c0(3,0))do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   else goal=-1;
   if(si_cefc4c->u716a60(ent->getPosition45a4a0(),3,ent.operator->(),&path24)){goal=path24.back9e8c10();do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
   else goto L7b;
  }else if(!si_cefb0d&&!(u459090()&&u4590f0()->u458950(0x13))){
   SiVArea areas;
   if(!isT3){
    SiVVP&mv=si_cefc4c->u463be0();
    for(unsigned i=0;i<mv[0x10].size9b9260();i++){
     SiArea a;
     si_cfd44c.getRect9b4430(mv[0x10][i]->u4184d0(),0xf,a);
     areas.push_back9b4610(a);
    }
    si_appendVector9d9140(areas,si_d2b274);
   }
   SiVPl h49;
   si_sweep4faaf0(ent->getPosition45a4a0(),h49);
   h49.push_back9b32e0(ent->getPosition45a4a0());
   for(unsigned i=0;i<h49.size9b9a50();i++){
    if((*si_cfd44c.atPoint9ced70(h49[i]))->getItem45d8f0().isValid()&&(isT3&&(*si_cfd44c.atPoint9ced70(h49[i]))->getItem45d8f0()->u457e70()||!isT3&&si_containsEntity9d31e0(si_d33d74,(*si_cfd44c.atPoint9ced70(h49[i]))->getItem45d8f0()))){
     if(!isT3&&si_anyAreaContains436d30(areas,h49[i])){}
     else{
      do{if(si_msg5111e0(((0x259)),((&(*si_cfd44c.atPoint9ced70(h49[i]))->getItem45d8f0()->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      (*si_cfd44c.atPoint9ced70(h49[i]))->getItem45d8f0()->u57a190(ent,4,0,0);
      u5b7340(h49[i]);
      do{ent->f40++;ent->clr45b0b0();return (300);}while(false);
     }
    }
   }
   if(goal.x!=-1&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0().isValid()&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0()->u457e70()){
    if(!isT3&&si_anyAreaContains436d30(areas,goal)){}
    else do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
    goal.x=-1;
   }
   if(isT3){
    SiQ cX,h59;
    si_cfd44c.getBoundsB9b79c0(ent->getPosition45a4a0(),4,ent->def->f9c+4,cX,h59);
    SiP best(-1,-1);
    int c0=100000;
    const SiP&k24=ent->getPosition45a4a0();
    int d9;for(int x=cX.x;x<=h59.x;x++)for(int y=cX.y;y<=h59.y;y++){
     if((*si_cfd44c.at9ceda0(x,y))->getItem45d8f0().isValid()&&(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u457e70()&&(*si_cfd44c.at9ceda0(x,y))->isPassableFor66ab30(ent)){
      d9=si_dist40a3f0(k24,SiP(x,y));
      if(d9<=c0){c0=d9;best.set40a010(x,y);}
     }
    }
    if(best.x!=-1){goal=best;do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
   }else if(!si_d33d74.empty9b86e0()){
    SiQ t;
    int tries=0;
    do{
     if(tries==10)goto L7b;
     SiHI pick;
     if(fa4.x1!=-1){
      SiVHI5 cand;
      for(unsigned i=0;i<si_d33d74.size9b9260();i++){
       if(fa4.contains40b750(si_d33d74[i]->u575920())&&!si_anyAreaContains436d30(areas,si_d33d74[i]->u575920()))cand.push_back9b80b0(si_d33d74[i]);
      }
      if(cand.empty9b86e0())goto L7b;
      else pick=si_randomRecord9dafb0(cand);
     }else{
      bool found=false;
      si_shuffle9d9fc0(si_d33d74);
      for(unsigned i=0;i<si_d33d74.size9b9260();i++){
       if(!si_anyAreaContains436d30(areas,si_d33d74[i]->u575920())){pick=si_d33d74[i];found=true;break;}
      }
      if(!found)goto L7b;
     }
     if(!pick.operator->()||pick->u457b50().isValid()&&!pick->u457b50().operator->()){
      si_logError404f10("EntityAI::takeTurn()","AI_MOVE_RECYCLER found bad item record");
      si_removeEntity9d2f00(si_d33d74,pick);
      do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
     }
     static_cast<SiP&>(t)=pick->u575920();
     tries++;
    }while(si_dist40a3f0(ent->getPosition45a4a0(),t)>25);
    goal=t;
    do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   }
  }
 L7b:
  if(goal.x==-1||ent->getPosition45a4a0().eq409b90(goal))u5b91e0();
  do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
  break;
 }
 case 8:{
  int cap=ent->u5c8e20(0);
  SiVPf*pts2=si_cefc4c->u464630();
  if(cap){
   int idx=si_fn4373f0(ent->getPosition45a4a0(),*pts2);
   if(idx!=-1){
    if((*si_cfd44c.atPoint9ced70((*pts2)[idx]))->getProp45d550().isNull9b65d0()||(*si_cfd44c.atPoint9ced70((*pts2)[idx]))->getProp45d550()->height9b8f00()!=si_cefbe0)do{ent->f40++;ent->clr45b0b0();return (200);}while(false);
    else{
     SiHI it=ent->u5cbc80();
     do{if(si_msg5111e0(((0x25b)),((&it->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     it->remove57dbe0(0,0,true,true);
    }
    break;
   }
  }
  if(cap>=ent->u5ca210()){
   if(goal.x!=-1&&si_fn9d0ce0(*pts2,goal))do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   else goal=si_randomPoint9d5350(*pts2);
   do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
  }else if(!si_cefb0d){
   SiVPl k30;
   si_sweep4faaf0(ent->getPosition45a4a0(),k30);
   k30.push_back9b32e0(ent->getPosition45a4a0());
   bool any=false;
   for(unsigned i=0;i<k30.size9b9a50();i++){
    if((*si_cfd44c.atPoint9ced70(k30[i]))->getItem45d8f0().isValid()&&si_containsEntity9d31e0(si_d33d74,(*si_cfd44c.atPoint9ced70(k30[i]))->getItem45d8f0())&&!si_anyAreaContains436d30(si_d2b274,k30[i])){
     do{if(si_msg5111e0(((0x259)),((&(*si_cfd44c.atPoint9ced70(k30[i]))->getItem45d8f0()->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     (*si_cfd44c.atPoint9ced70(k30[i]))->getItem45d8f0()->u57a190(ent,4,0,0);
     u5b7340(k30[i]);
     any=true;
    }
   }
   if(any)do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
   if(goal.x!=-1&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0().isValid()&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0()->u457e70()&&!si_anyAreaContains436d30(si_d2b274,goal))do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   if(!si_d33d74.empty9b86e0()){
    SiHI pick;
    for(int i=0;i<15;i++){
     pick=si_randomRecord9dafb0(si_d33d74);
     if(!pick.operator->()||pick->u457b50().isValid()&&!pick->u457b50().operator->()){
      si_logError404f10("EntityAI::takeTurn()","retrieve found bad item record");
      si_removeEntity9d2f00(si_d33d74,pick);
      do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
     }
     if(si_anyAreaContains436d30(si_d2b274,pick->u575920()))continue;
     goal=pick->u575920();
     do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
    }
   }
  }
  int k27=si_fn4373f0(ent->getPosition45a4a0(),*pts2);
  if(k27!=-1){
   do{if(si_msg5111e0(((0x25d)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
   si_fn454260(ent->getPosition45a4a0(),0xb7);
   ent->u637bb0();
   return 100;
  }
  if(goal.x==-1||!si_fn9d0ce0(*pts2,goal))goal=si_randomPoint9d5350(*pts2);
  do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
  break;
 }
 case 9:
  if(!fb4.operator->()){
   si_logError404f10("EntityAI::takeTurn()","returning drone missing associatedEntity but didn't self-destruct");
   do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
  }
  if(ent->u5c8820(fb4)){
   if(ent->def->name=="Swarm Drone"){
    SiHI h=fb4->u5d2380(0xa7);
    if(h.isValid())h->u44fc60(h->u45cb30()+1);
   }
   do{if(si_msg5111e0(((0x25f)),((0)),(0),(0),((fb4)),((ent)),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
   si_fn454260(fb4->getPosition45a4a0(),0xbe);
   ent->u637bb0();
   return 100;
  }
  if(goal.ne409bd0(fb4->getPosition45a4a0()))goal=fb4->getPosition45a4a0();
  do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
  break;
 case 10:
  if(ent->u5d55e0()){
   int fac=ent->getGroup45a3f0()->type9b4350();
   if(fac==4)fac=3;
   if(!v6c.empty9b86e0()){
    if(!(*si_cfd44c.atPoint9ced70(v6c[0]))->u45dcf0())v6c.clear9b3560();
    else if(v6c[0].distanceTo409fb0(ent->getPosition45a4a0())<=1&&(*si_cfd44c.atPoint9ced70(v6c[0]))->getProp45d550()->u44b020()->u65cf50(fac)){
     if(si_cefc4c->u4631f0(ent))(*si_cfd44c.atPoint9ced70(v6c[0]))->getProp45d550()->u65f170();
     (*si_cfd44c.atPoint9ced70(v6c[0]))->getProp45d550()->u44b020()->f10=fac;
     do{if(si_msg5111e0((ent->u45aaa0(si_cefc4c->getPlayer4630f0())?0x261:0x262),(&(*si_cfd44c.atPoint9ced70(v6c[0]))->getProp45d550()->getName45c5b0()),(0),(0),(ent),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
    }else if(v6c[0].eq409b90(ent->getPosition45a4a0()))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
    else{
     goal=v6c[0];
     do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
    }
   }
   SiQ loC,hi6;
   si_cfd44c.getBoundsB9b79c0(ent->getPosition45a4a0(),4,4,loC,hi6);
   SiP aBest(-1,-1);
   int c_=100000;
   const SiP&k50=ent->getPosition45a4a0();
   int d;for(int x=loC.x;x<=hi6.x;x++)for(int y=loC.y;y<=hi6.y;y++){
    if((*si_cfd44c.at9ceda0(x,y))->u45dcf0()&&(*si_cfd44c.at9ceda0(x,y))->getProp45d550()->pdef9b8f00()->f154&&(*si_cfd44c.at9ceda0(x,y))->getProp45d550()->u44b020()->u65cf50(fac)){
     d=si_dist40a3f0(k50,SiP(x,y));
     if(d<=c_){c_=d;aBest.set40a010(x,y);}
    }
   }
   if(aBest.x!=-1){v6c.push_back9b32e0(aBest);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}
  }
  if(goal.x==-1||ent->getPosition45a4a0().eq409b90(goal))u5b91e0();
  do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
  break;
 case 11:
  if(u459090()&&p11c->u458950(0x16)){
   SiRec*r=p11c->u458950(0x16);
   if(!r->f18.operator->())u459150(r);
   else if(!ent->u5c8820(r->f18)){
    if(goal.ne409bd0(r->f18->getPosition45a4a0()))goal=r->f18->getPosition45a4a0();
    do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   }else{
    SiVHI5 items;
    r->f18->u5cb8b0(items);
    if(items.empty9b86e0())u459150(r);
    else{
     int bestX=-1;
     for(unsigned i=0;i<items.size9b9260();i++)if(items[i]->u577790()>bestX)bestX=items[i]->u577790();
     for(unsigned i=0;i<items.size9b9260();i++)if(items[i]->u577790()!=bestX)si_eraseStep9d6440(items,i);
     SiHI pick=si_randomRecord9dafb0(items);
     do{if(si_msg5111e0(((0x26c)),((&pick->getName571db0(0,0))),(0),(0),((ent)),((r->f18)),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     if(si_d25450.on&&r->f18->def9b4350()->f120>=3&&r->f18->ai45b590()->f8>=6&&si_cefc4c->u4631f0(ent))si_d25450.u69e700(0x1c,0,0.0f);
     if(pick->u457e90()){
      do{if(si_msg5111e0(0x45,&pick->getName571db0(0,0),0,0,ent,SiHE(),&r->f18->u45a4c0(),false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      pick->remove57dbe0(0,1,true,true);
     }else{
      r->f18->u642940(pick,0,0,0,0);
      si_cefc4c->u464870(pick);
     }
     return 100;
    }
   }
  }
  if(fb4.isValid()){
   if(ent->u5c8820(fb4)&&si_cefc4c->getTurn464270()>=fec+0xc&&si_cefc4c->getTurn464270()>=(fb4->ai?fb4->ai->fec:si_cf4b98)+0xc){
    int r=u5bac50();
    do{ent->f40++;ent->clr45b0b0();return (r);}while(false);
   }else if(goal.ne409bd0(fb4->getPosition45a4a0()))goal=fb4->getPosition45a4a0();
   do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
  }else if(fcc==1&&ent->u5c8e20(0)<ent->u5ca210()){
   if(si_d1e860.u46f4b0(1)&&ent->isInGroup5cb6b0(si_cefc4c->u463890(3))||si_d1e860.u46f4b0(2)&&!ent->isInGroup5cb6b0(si_cefc4c->u463890(3))){
    SiP pt=u5ba650(2,1);
    if(pt.x!=-1){
     ent->u5de7b0();
     fcc=0;
     do{if(si_msg5111e0(((0x266)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     do{ent->f40++;ent->clr45b0b0();return (300);}while(false);
    }else{
     if(goal.x==-1||!(*si_cfd44c.atPoint9ced70(goal))->u66b1c0(2,1)){
      if(si_cefc4c->u716a60(ent->getPosition45a4a0(),2,ent.operator->(),&path24))goal=path24.back9e8c10();
      else{fcc=-1;goto L11;}
     }
     do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
    }
   }else fcc=-1;
  }
 L11:
  if(goal.x==-1||ent->getPosition45a4a0().eq409b90(goal))u5b91e0();
  do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
  break;
 case 12:
  if(v6c.size9b9a50()<2){
   f4=3;
   f8=2;
   if(ent->getGroup45a3f0()->type9b4350()!=4)ent->changeFaction5dc780(si_cefc4c->u463890(4),0);
   do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
  }
  if(v6c[1].x==-1){
   if(!vf0.empty9b86e0()){
    v6c[1].x=1;
    do{if(si_msg5111e0(((0x26d)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    if(si_cefc4c->u4631f0(ent)){
     si_cec054->u8196c0(ent);
     if(si_d28e40)si_cec054->u49ac90(ent->getPosition45a4a0(),1,si_d28e40);
    }
   }else if(si_cefc4c->getTurn464270()%5==0&&(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->u66b1c0(0,0)&&(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->getProp45d550()->u45cb30()->f28>=0&&!(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->getProp45d550()->u457b10()&&(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->getProp45d550()->u45cb30()->b11&&si_cefc4c->isReachable465230(ent->u5c7d30(),ent->getPosition45a4a0(),v6c.front9b7060())){
    v6c[1].x=1;
    do{if(si_msg5111e0(((0x272)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    if(si_cefc4c->u4631f0(ent)){
     si_cec054->u8196c0(ent);
     if(si_d28e40)si_cec054->u49ac90(ent->getPosition45a4a0(),1,si_d28e40);
    }
   }else{
    if(goal.x==-1||ent->getPosition45a4a0().eq409b90(goal)){
     int tries=0;
     do{u5b91e0();tries++;}while(path24.size9b9a50()>si_bba394&&tries<25);
    }
    do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
   }
  }
  if(v6c[1].x==1){
   bool done=false;
   if(!(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->u66b1c0(0,0)||(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->getProp45d550()->u45cb30()->f28<0||(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->getProp45d550()->u457b10()){
    done=true;
   }else if(si_adjacent4373c0(ent->getPosition45a4a0(),v6c.front9b7060())){
    SiVI40&rec=(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->getProp45d550()->u45cb30()->v40;
    if(si_containsRecord9db330(rec,1)){
     do{if(si_msg5111e0(((0x274)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     do{if(si_msg5111e0(((0x275)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     si_fn9d51d0(rec,1);
     si_removeEntity9d2f00(si_cefc4c->u463be0()[1],(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->getProp45d550());
     ent->changeFaction5dc780(si_cefc4c->u463890(1),1);
     si_cf4d30++;
     if(si_cf4d30==3)si_cf45d8.u77fbc0(0xb6);
     return 100;
    }else if(u459090()&&u4590f0()->u458950(0x1d)){
     do{if(si_msg5111e0(((0x270)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     u4591c0(0x1d);
     done=true;
    }else if(u459090()&&u4590f0()->u458950(0x1e)){
     si_clearDijkstra4faf40();
     si_cfe568.u40ca20(ent->getPosition45a4a0(),0x32,&si_d1e85c,0);
     if(si_d15e58.empty9b86e0())do{if(si_msg5111e0(((0x26f)),((&string("NO HAULERS IN RANGE."))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     else{
      for(unsigned i=0;i<si_d15e58.size9b9a50();i++){
       SiAI*ai=(*si_cfd44c.atPoint9ced70(si_d15e58[i]))->getEntity45d250()->ai45b590();
       ai->u459520(SiP(-1));
       SiVPf*v=ai->u458ef0();
       if(v->empty9b86e0()){
        v->push_back9b32e0(ent->getPosition45a4a0());
        v->push_back9b32e0(ai->ent->getPosition45a4a0());
       }else (*v)[0].op40a030(ent->getPosition45a4a0());
       ai->u459520((*v)[0]);
      }
      string msg="CALLING "+si_toUpper4083a0(si_countString407a80(si_d15e58.size9b9a50(),"HAULER"))+".";
      do{if(si_msg5111e0(((0x26f)),((&msg)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     }
     u4591c0(0x1e);
     done=true;
    }else{
     (*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->getProp45d550()->u45cb30()->f28=-1;
     if((*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->u66b1c0(0,0)&&(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->getProp45d550()->u45cb30()->b11){
      if(si_cf6428.u684250(v6c.front9b7060(),0))do{if(si_msg5111e0(((0x273)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     }else if(si_cf6428.u686c60(ent->getPosition45a4a0(),-1,0x61,0x7a)){
      do{if(si_msg5111e0(((0x26e)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      do{si_cf1080.u451400(1);if((0x127)!=-1&&!(si_d28fb0&&1&&1))si_sound4541b0(0x127,0,0);do{if(si_msg5111e0(((0x324)),((&("ALERT: Hostiles spotted, dispatching reinforcements to "+(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->getProp45d550()->u45cb30()->u65cc80()+"."))),(0),(0),((SiHE())),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);si_cec0b4->end7b4f10();}while(false);
      if(si_cefb48)si_cefb48->say49e250(0x2b,0,"");
      if(si_d25450.on&&si_dist40a3f0(ent->getPosition45a4a0(),si_cefc4c->getPlayer4630f0()->getPosition45a4a0())<=30){
       if(!si_d254e0||si_cefc4c->getTurn464270()-si_d254e0>20)si_d254e0=si_cefc4c->getTurn464270();
       else{
        si_d254e0=0;
        si_d25450.u69e700(0x2c,si_cefc4c->getPlayer4630f0()->u5d15a0(0)>=80,0.0f);
       }
      }
     }
     do{if(si_msg5111e0(((0x271)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     si_cf6428.u68d6d0(true);
     si_cf6428.wake68d480();
     done=true;
     si_cf45d8.u77fbc0(0x3e);
     if(!rec.empty9b86e0()){
      for(unsigned i=0;i<rec.size9b9260();i++)si_removeEntity9d2f00(si_cefc4c->u463be0()[rec[i]],(*si_cfd44c.atPoint9ced70(v6c.front9b7060()))->getProp45d550());
      rec.clear9bac80();
      do{if(si_msg5111e0(((0x276)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     }
    }
   }else{
    if(goal.ne409bd0(v6c.front9b7060()))goal=v6c.front9b7060();
    do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   }
   if(done){
    f4=3;
    f8=2;
    ent->changeFaction5dc780(si_cefc4c->u463890(4),0);
   }
  }
  break;
 case 13:
  if(rng.chance(20)){
   SiP t(-1);
   SiVPl cells;
   si_sweep4faaf0(ent->getPosition45a4a0(),cells);
   for(unsigned i=0;i<cells.size9b9a50();i++){
    if((*si_cfd44c.atPoint9ced70(cells[i]))->getProp45d550().isValid()&&(*si_cfd44c.atPoint9ced70(cells[i]))->getProp45d550()->pdef9b8f00()->ff4==2&&(*si_cfd44c.atPoint9ced70(cells[i]))->getProp45d550()->pdef9b8f00()->f120==0&&!(*si_cfd44c.atPoint9ced70(cells[i]))->getProp45d550()->u457b10()){t=cells[i];break;}
   }
   if(t.x!=-1){
    do{if(si_msg5111e0((0x263),(&(*si_cfd44c.atPoint9ced70(t))->getProp45d550()->getName45c5b0()),(0),(0),(ent),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    do{ent->f40++;ent->clr45b0b0();return (300);}while(false);
   }
  }
  if(goal.x==-1||ent->getPosition45a4a0().eq409b90(goal))u5b91e0();
  do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
  break;
 case 14:{
  if(!ent->u5d5520(0)){
   SiArea a;
   si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),10,a);
   u459470(a);
  }
  if(v6c[4].x!=-1&&si_cefc4c->u4642d0()>=v6c[4].x){
   v6c[0].x=si_cefc4c->u74b2c0(v6c[1]);
   v6c[2].x=-1;
   v6c[5].x=1;
   v6c[4].x=rng.chance(25)?-1:si_cefc4c->u4642d0()+rng.rangeInt(500.0f,1500.0f);
  }
  SiGrid*g=si_d22744[v6c[0].x];
  if(v6c[5].x){
   SiVPl cells;
   si_sweep4faaf0(ent->getPosition45a4a0(),cells);
   cells.push_back9b32e0(ent->getPosition45a4a0());
   for(unsigned i=0;i<cells.size9b9a50();i++){
    if((*si_cfd44c.atPoint9ced70(cells[i]))->getProp45d550().isValid()&&(*si_cfd44c.atPoint9ced70(cells[i]))->getProp45d550()->height9b8f00()==si_cefbd8&&g->contains9b43b0(cells[i].sub409b30(v6c[1]))&&*g->atPoint9ced70(cells[i].sub409b30(v6c[1]))==0){
     do{if(si_msg5111e0((0x27c),(&string("deconstructs")),(&(*si_cfd44c.atPoint9ced70(cells[i]))->getProp45d550()->getName45c5b0()),(0),(ent),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     (*si_cfd44c.atPoint9ced70(cells[i]))->getProp45d550()->u45ce10(1,0,1,SiHE());
     do{ent->f40++;ent->clr45b0b0();return (200);}while(false);
    }
   }
   if(goal.x!=-1&&g->contains9b43b0(goal.sub409b30(v6c[1]))&&*g->atPoint9ced70(goal.sub409b30(v6c[1]))==0&&(*si_cfd44c.atPoint9ced70(goal))->getProp45d550().isValid()&&(*si_cfd44c.atPoint9ced70(goal))->getProp45d550()->height9b8f00()==si_cefbd8)do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
   for(int i=0;i<50;i++){
    g->getRandom9cf0c0(goal);
    if(*g->atPoint9ced70(goal)==0){
     goal.op409a30(v6c[1]);
     if((*si_cfd44c.atPoint9ced70(goal))->getProp45d550().isValid()&&(*si_cfd44c.atPoint9ced70(goal))->getProp45d550()->height9b8f00()==si_cefbd8)do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
    }
   }
   for(int x=0,X=v6c[1].x;x<g->width9fcd80();x++,X++){
    for(int y=0,myY=v6c[1].y;y<g->height9b8f00();y++,myY++){
     if(*g->at9ceda0(x,y)==0&&(*si_cfd44c.at9ceda0(X,myY))->getProp45d550().isValid()&&(*si_cfd44c.at9ceda0(X,myY))->getProp45d550()->height9b8f00()==si_cefbd8){goal.set40a010(X,myY);do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);}
    }
   }
   v6c[5].x=0;
  }
  if(v6c[3].x!=-1){
   if((*si_cfd44c.atPoint9ced70(v6c[3]))->getProp45d550().isValid()&&(*si_cfd44c.atPoint9ced70(v6c[3]))->getProp45d550()->height9b8f00()==si_cefbd8){
    if(ent->getPosition45a4a0().eq409b90(v6c[3])||ent->u5c87f0(v6c[3])){
     SiHP pp=(*si_cfd44c.atPoint9ced70(v6c[3]))->getProp45d550();
     do{if(si_msg5111e0((0x27c),(&string("tweaks")),(&pp->getName45c5b0()),(0),(ent),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     pp->u65e2d0();
     v6c[3].x=-1;
     do{ent->f40++;ent->clr45b0b0();return (200);}while(false);
    }else{
     goal=v6c[3];
     do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
    }
   }else v6c[3].x=-1;
  }
  SiVPl k51;
  si_sweep4faaf0(ent->getPosition45a4a0(),k51);
  k51.push_back9b32e0(ent->getPosition45a4a0());
  for(unsigned i=0;i<k51.size9b9a50();i++){
   if(g->contains9b43b0(k51[i].sub409b30(v6c[1]))&&*g->atPoint9ced70(k51[i].sub409b30(v6c[1]))!=0&&(*si_cfd44c.atPoint9ced70(k51[i]))->u4550b0()){
    if((*si_cfd44c.atPoint9ced70(k51[i]))->getProp45d550().isValid()){
     if((*si_cfd44c.atPoint9ced70(k51[i]))->getProp45d550()->height9b8f00()!=si_cefbd8)*g->atPoint9ced70(k51[i].sub409b30(v6c[1]))=0;
    }else if((*si_cfd44c.atPoint9ced70(k51[i]))->getEntity45d250().isNull9b65d0()||(*si_cfd44c.atPoint9ced70(k51[i]))->getEntity45d250()==ent){
     SiHP np=si_cefaa8->createE793360(si_cefbd8);
     (*si_cfd44c.atPoint9ced70(k51[i]))->u45df50(np);
     np->u45cc50(k51[i]);
     do{if(si_msg5111e0((0x27c),(&string("builds")),(&np->getName45c5b0()),(0),(ent),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     do{ent->f40++;ent->clr45b0b0();return (200);}while(false);
    }
   }
  }
  if(goal.x!=-1&&g->contains9b43b0(goal.sub409b30(v6c[1]))&&*g->atPoint9ced70(goal.sub409b30(v6c[1]))!=0&&(*si_cfd44c.atPoint9ced70(goal))->u4550b0()&&((*si_cfd44c.atPoint9ced70(goal))->getProp45d550().isNull9b65d0()||(*si_cfd44c.atPoint9ced70(goal))->getProp45d550()->height9b8f00()!=si_cefbd8))do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
  if(si_cefc4c->u4642d0()>v6c[2].x){
   for(int i=0;i<50;i++){
    g->getRandom9cf0c0(goal);
    if(*g->atPoint9ced70(goal)!=0){
     goal.op409a30(v6c[1]);
     if((*si_cfd44c.atPoint9ced70(goal))->u4550b0()&&((*si_cfd44c.atPoint9ced70(goal))->getProp45d550().isNull9b65d0()||(*si_cfd44c.atPoint9ced70(goal))->getProp45d550()->height9b8f00()!=si_cefbd8))do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
    }
   }
   for(int x=0,X=v6c[1].x;x<g->width9fcd80();x++,X++){
    for(int y=0,k54=v6c[1].y;y<g->height9b8f00();y++,k54++){
     if(*g->at9ceda0(x,y)!=0&&(*si_cfd44c.at9ceda0(X,k54))->u4550b0()&&((*si_cfd44c.at9ceda0(X,k54))->getProp45d550().isNull9b65d0()||(*si_cfd44c.at9ceda0(X,k54))->getProp45d550()->height9b8f00()!=si_cefbd8)){goal.set40a010(X,k54);do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);}
    }
   }
   v6c[2].x=rng.rangeInt(50.0f,100.0f);
  }
  for(int i=0;i<50;i++){
   g->getRandom9cf0c0(goal);
   if(*g->atPoint9ced70(goal)!=0&&(*si_cfd44c.atPoint9ced70(goal.add409b60(v6c[1])))->getProp45d550().isValid()&&(*si_cfd44c.atPoint9ced70(goal.add409b60(v6c[1])))->getProp45d550()->height9b8f00()==si_cefbd8){
    goal=v6c[3]=goal.add409b60(v6c[1]);
    do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
   }
  }
  do{ent->f40++;ent->clr45b0b0();return (500);}while(false);
 }
  break;
 case 15:{
  SiP&me=ent->getPosition45a4a0();
  if(ent->u45a920()<ent->u5ca670()){
   SiVPl k57;
   si_sweep4faaf0(ent->getPosition45a4a0(),k57);
   k57.push_back9b32e0(ent->getPosition45a4a0());
   for(unsigned i=0;i<k57.size9b9a50();i++){
    if((*si_cfd44c.atPoint9ced70(k57[i]))->getItem45d8f0().isValid()){
     SiHI it=(*si_cfd44c.atPoint9ced70(k57[i]))->getItem45d8f0();
     if(!it->u457880()){
      int n=si_minInt9cdb30(it->u9b6bf0(),ent->u5ca670());
      ent->u5deb40(n);
      if(n>=it->u9b6bf0())it->remove57dbe0(0,1,true,true);
      else it->u450460(it->u9b6bf0()-n);
      do{if(si_msg5111e0(((0x27d)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      do{ent->f40++;ent->clr45b0b0();return (300);}while(false);
     }else if(it->u457f90()==9&&it->u45cb30()>0){
      int n=si_minInt9cdb30(it->u45cb30(),ent->u5ca670());
      ent->u5deb40(n);
      it->u44fc60(it->u45cb30()-n);
      do{if(si_msg5111e0(((0x27e)),((&it->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      do{ent->f40++;ent->clr45b0b0();return (300);}while(false);
     }
    }
   }
   if(goal.x!=-1&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0().isValid()&&(!(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0()->u457880()||(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0()->u457f90()==9&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0()->u45cb30()>0)&&(*si_cfd44c.atPoint9ced70(goal))->isPassableFor66ab30(ent))do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   SiQ aR,hiC;
   si_cfd44c.getBoundsB9b79c0(ent->getPosition45a4a0(),4,ent->def->f9c+4,aR,hiC);
   SiP d6(-1,-1);
   int bd=100000;
   int dVal;for(int x=aR.x;x<=hiC.x;x++)for(int y=aR.y;y<=hiC.y;y++){
    if((*si_cfd44c.at9ceda0(x,y))->getItem45d8f0().isValid()&&(!(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u457880()||(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u457f90()==9&&(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u45cb30()>0)&&(*si_cfd44c.at9ceda0(x,y))->isPassableFor66ab30(SiHE())){
     dVal=si_dist40a3f0(me,SiP(x,y));
     if(dVal<=bd){bd=dVal;d6.set40a010(x,y);}
    }
   }
   if(d6.x!=-1){goal=d6;do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}
  }
  if(goal.x==-1||me.eq409b90(goal))u5b91e0();
  do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
 }
  break;
 case 16:{
  SiP p(ent->getPosition45a4a0());
  SiP dB(p);
  dB.x+=ent->getSize45a360();
  if(f34==0){
   if(!ent->isXomCandidate5d51a0()||ent->u5d1280(0)){
    f34=1;
    string msg="ANNOUNCEMENT: Tunneling progress halted along "+si_cefc4c->u463060(ent->getPosition45a4a0())+" route. "+ent->name416f40()+" no longer operational.";
    do{si_cf1080.u451400(1);if((-1)!=-1&&!(si_d28fb0&&1&&1))si_sound4541b0(-1,0,0);do{if(si_msg5111e0(((0x324)),((&msg)),(0),(0),((SiHE())),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);si_cec0b4->end7b4f10();}while(false);
    do{si_logPhrase5141b0(0x1c9,0,0,0,SiHE(),0);}while(false);
   }
  }
  if(!ent->isXomCandidate5d51a0()||dB.x>=si_cfd44c.width9fcd80()-4)do{ent->f40++;ent->clr45b0b0();return (500);}while(false);
  for(int x=p.x;x<p.x+ent->getSize45a360();x++){
   for(int y=p.y;y<p.y+ent->getSize45a360();y++){
    if((*si_cfd44c.at9ceda0(x,y))->getItem45d8f0().isValid()){
     (*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->remove57dbe0(0,0,true,true);
     if(!ent.operator->())return 100;
    }
   }
  }
  bool blocked=false;
  for(int y=dB.y;y<dB.y+ent->getSize45a360();y++){
   if((*si_cfd44c.at9ceda0(dB.x,y))->getEntity45d250().isValid()){
    blocked=true;
    if((*si_cfd44c.at9ceda0(dB.x,y))->getEntity45d250()->u45aaa0(ent))do{ent->f40++;ent->clr45b0b0();return (100);}while(false);
   }else if((*si_cfd44c.at9ceda0(dB.x,y))->terr9fcd80()!=si_cefb9c&&(*si_cfd44c.at9ceda0(dB.x,y))->terr9fcd80()!=si_cefb88&&!(*si_cfd44c.at9ceda0(dB.x,y))->isMachinePart45dcd0())blocked=true;
   else if((*si_cfd44c.at9ceda0(dB.x,y))->getProp45d550().isValid()&&!(*si_cfd44c.at9ceda0(dB.x,y))->getProp45d550()->isPassableFor65e1d0(ent))blocked=true;
  }
  if(blocked){
   int sz=ent->getSize45a360();
   int cnt=0;
   SiVE8 vec;
   for(int y=dB.y;y<dB.y+sz;y++){
    if(!ent.operator->()){
     si_logError404f10("EnityAI::takeTurn()","AI_MOVE_BOREBOT died while removing obstacles");
     return 100;
    }
    if((*si_cfd44c.at9ceda0(dB.x,y))->getItem45d8f0().isValid()){
     do{if(si_msg5111e0(((0xb9)),((&(*si_cfd44c.at9ceda0(dB.x,y))->getItem45d8f0()->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     (*si_cfd44c.at9ceda0(dB.x,y))->getItem45d8f0()->remove57dbe0(0,0,true,true);
    }
    if((*si_cfd44c.at9ceda0(dB.x,y))->getEntity45d250().isValid()){
     SiHE e=(*si_cfd44c.at9ceda0(dB.x,y))->getEntity45d250();
     if(e->isPlayer5c7600())do{if(si_msg5111e0(((0xb6)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     else do{if(si_msg5111e0((e->u45aaa0(si_cefc4c->getPlayer4630f0())?0xb7:0xb8),(&e->name416f40()),(0),(0),(ent),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     si_cefc4c->addRecord777a20(si_cefaa8->createA7930e0(new SiShoot(ent,0,SiP(dB.x,y),*(SiP*)&si_d2e20c,cnt,vec,0,SiHE())));
    }
    if((*si_cfd44c.at9ceda0(dB.x,y))->terr9fcd80()!=si_cefb9c&&(*si_cfd44c.at9ceda0(dB.x,y))->terr9fcd80()!=si_cefb88&&!(*si_cfd44c.at9ceda0(dB.x,y))->isMachinePart45dcd0()){
     do{if(si_msg5111e0((0xb9),(&(*si_cfd44c.at9ceda0(dB.x,y))->u45d140()),(0),(0),(ent),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     if(!(*si_cfd44c.at9ceda0(dB.x,y))->u4550b0())si_cefc4c->addRecord777a20(si_cefaa8->createA7930e0(new SiShoot(ent,0,SiP(dB.x,y),*(SiP*)&si_d2e20c,cnt,vec,0,SiHE())));
     else (*si_cfd44c.at9ceda0(dB.x,y))->u66a050(si_cefb9c->f0,2,0);
    }
    if((*si_cfd44c.at9ceda0(dB.x,y))->getProp45d550().isValid()&&!(*si_cfd44c.at9ceda0(dB.x,y))->getProp45d550()->isPassableFor65e1d0(ent)){
     do{if(si_msg5111e0((0xb9),(&(*si_cfd44c.at9ceda0(dB.x,y))->getProp45d550()->getName45c5b0()),(0),(0),(ent),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     si_cefc4c->addRecord777a20(si_cefaa8->createA7930e0(new SiShoot(ent,0,SiP(dB.x,y),*(SiP*)&si_d2e20c,cnt,vec,0,SiHE())));
    }
   }
   if(!ent.operator->()){
    si_logError404f10("EnityAI::takeTurn()","AI_MOVE_BOREBOT died while removing obstacles");
    return 100;
   }
   int d=si_dist40a3f0(ent->u45a4c0(),si_cefc4c->getPlayer4630f0()->getPosition45a4a0());
   if(d<=10)si_d2f1c8.shake4b38f0((11-d)*50,0xcc);
   do{ent->f40++;ent->clr45b0b0();return (100);}while(false);
  }
  goal=dB;
  do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
 }
  break;
 case 17:{
  SiVAr*areas=si_cefc4c->u4646b0();
  if(areas->empty9b86e0()){
   f4=0x19;
   u459540(SiP(si_cefc4c->u464650()->x2,si_cefc4c->u464650()->y1));
   do{ent->f40++;ent->clr45b0b0();return (100);}while(false);
  }
  if(ent->u5d2a00(0xd1)){
   int lo4=-1;
   SiP cur(goal.x!=-1?goal:ent->getPosition45a4a0());
   for(unsigned i=0;i<areas->size9b5100();i++){
    if((*areas)[i].contains40b750(cur)){lo4=i;break;}
   }
   if(lo4==-1){
    goal.x=-1;
    SiVIn dist8;
    SiVPl pts;
    for(unsigned i=0;i<areas->size9b5100();i++){
     SiArea&a=(*areas)[i];
     SiQ p;
     for(int t=0;t<10;t++){
      static_cast<SiP&>(p)=a.randomPoint40be90();
      if((*si_cfd44c.atPoint9ced70(p))->isPassableFor66ab30(SiHE())&&!(*si_cfd44c.atPoint9ced70(p))->u45db70()&&!(*si_cfd44c.atPoint9ced70(p))->isMachinePart45dcd0()){
       int cost;
       if(si_cefc4c->u716940i(ent->getPosition45a4a0(),p,ent.operator->(),&cost)){
        pts.push_back9b32e0(p);
        dist8.push_back9b9d30(cost);
        goto L17a;
       }
       break;
      }
     }
     pts.push_back9b3020(SiP(-1));
     dist8.push_back9b9280(9999);
    L17a:;
    }
    SiVIn aA;
    aA.push_back9b9280(0);
    for(int i=1;i<areas->size9b5100();i++){
     if(dist8[i]>=dist8[aA.back9b6540()])aA.push_back9b9d30(i);
     else{
      for(unsigned j=0;j<dist8.size9b9260();j++){
       if(dist8[i]<dist8[aA[j]]){si_insertAt9dbdc0(aA,j,i);break;}
      }
     }
    }
    int n=-1;
    for(int i=0;i<aA.size9b9260();i++){
     if(dist8[aA[i]]==9999||i>0&&dist8[aA[i]]>dist8[aA[0]]*1.5)break;
     n++;
    }
    if(n!=-1){
     if(n>0)si_fn9d9190(aA,0,n);
     lo4=aA[0];
     goal=pts[lo4];
    }
    if(lo4==-1)do{ent->f40++;ent->clr45b0b0();return (500);}while(false);
   }
   if((*areas)[lo4].contains40b750(ent->getPosition45a4a0())&&!(*si_cfd44c.atPoint9ced70(ent->getPosition45a4a0()))->u45db70()&&!(*si_cfd44c.atPoint9ced70(ent->getPosition45a4a0()))->isMachinePart45dcd0()){
    si_cefc4c->u71ef30(ent->getPosition45a4a0(),1);
    for(unsigned i=0;i<ent->v134.size9b9260();i++){
     if(ent->v134[i]->u457f90()==0xd1){
      ent->u642940(ent->v134[i],0,0,0,0);
      do{ent->f40++;ent->clr45b0b0();return (si_b95fc0);}while(false);
     }
    }
   }else if(ent->u5d1280(0)){
    do{if(si_msg5111e0(((0x285)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    ent->die633790(!si_cefc4c->u4631f0(ent),10,SiHE(),1,0,0,0,0);
    return 100;
   }else{
    if(goal.x==-1){
     for(int t=0;t<10;t++){
      SiP r=(*areas)[lo4].randomPoint40be90();
      if((*si_cfd44c.atPoint9ced70(r))->isPassableFor66ab30(SiHE())&&!(*si_cfd44c.atPoint9ced70(r))->u45db70()&&!(*si_cfd44c.atPoint9ced70(r))->isMachinePart45dcd0()){goal=r;break;}
     }
    }
    do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);
   }
  }else{
   SiHI it=(*si_cfd44c.atPoint9ced70(ent->getPosition45a4a0()))->getItem45d8f0();
   if(it.isValid()&&it->u457f90()==0xd1){
    for(unsigned i=0;i<areas->size9b5100();i++){
     if((*areas)[i].contains40b750(ent->getPosition45a4a0())){
      si_cefc4c->bomb744aa0(ent);
      do{ent->f40++;ent->clr45b0b0();return (100);}while(false);
     }
    }
   }
   if(ent->u5d1280(0)||ent->u5ca210()<si_cefc00->f4c){
    do{if(si_msg5111e0(((0x285)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    ent->die633790(!si_cefc4c->u4631f0(ent),10,SiHE(),1,0,0,0,0);
    return 100;
   }else{
    SiVPl loA(1,ent->getPosition45a4a0());
    si_sweep4faaf0(ent->getPosition45a4a0(),loA);
    for(unsigned i=0;i<loA.size9b9a50();i++){
     if((*si_cfd44c.atPoint9ced70(loA[i]))->getItem45d8f0().isValid()&&(*si_cfd44c.atPoint9ced70(loA[i]))->getItem45d8f0()->u457f90()==0xd1){
      do{if(si_msg5111e0(((0x280)),((&(*si_cfd44c.atPoint9ced70(loA[i]))->getItem45d8f0()->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      (*si_cfd44c.atPoint9ced70(loA[i]))->getItem45d8f0()->u57a190(ent,4,0,0);
      do{ent->f40++;ent->clr45b0b0();return (si_b95fac);}while(false);
     }
    }
    if(goal.x!=-1&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0().isValid()&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0()->u457f90()==0xd1)do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);
    SiArea a;
    si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),5,a);
    for(int x=a.x1;x<=a.x2;x++)for(int y=a.y1;y<=a.y2;y++){
     if((*si_cfd44c.at9ceda0(x,y))->getItem45d8f0().isValid()&&(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u457f90()==0xd1){goal.set40a010(x,y);do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);}
    }
    a=*si_cefc4c->u464650();
    for(int x=a.x1;x<=a.x2;x++)for(int y=a.y1;y<=a.y2;y++){
     if((*si_cfd44c.at9ceda0(x,y))->getItem45d8f0().isValid()&&(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u457f90()==0xd1){goal.set40a010(x,y);do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);}
    }
    a.u40b300(0,0x55,0xc7,0xc7);
    for(int y=a.y2;y>=a.y1;y--)for(int x=a.x2;x>=a.x1;x--){
     if((*si_cfd44c.at9ceda0(x,y))->getItem45d8f0().isValid()&&(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0()->u457f90()==0xd1){goal.set40a010(x,y);do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);}
    }
    if(!si_cefc4c->u464650()->contains40b750(goal))goal=si_cefc4c->u464650()->randomPoint40be90();
    do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);
   }
  }
 }
  break;
 case 18:{
  for(unsigned i=0;i<v6c.size9b9a50();i++){
   if((*si_cfd44c.atPoint9ced70(v6c[i]))->getItem45d8f0().isNull9b65d0()){
    if((*si_cfd44c.atPoint9ced70(v6c[i]))->getEntity45d250().isValid()&&(*si_cfd44c.atPoint9ced70(v6c[i]))->getEntity45d250()->getTarget45a760()&&(*si_cfd44c.atPoint9ced70(v6c[i]))->getEntity45d250()->u5cbc80().isValid())continue;
    si_eraseStep9d7300(v6c,i);
   }
  }
  if(v6c.empty9b86e0()){
   f4=0x17;
   do{ent->f40++;ent->clr45b0b0();return (100);}while(false);
  }
  SiVPl cells;
  si_sweep4faaf0(ent->getPosition45a4a0(),cells);
  cells.push_back9b32e0(ent->getPosition45a4a0());
  if(si_fn9d0ce0(cells,v6c[0])){
   SiHI m14=(*si_cfd44c.atPoint9ced70(v6c[0]))->getEntity45d250().isValid()&&(*si_cfd44c.atPoint9ced70(v6c[0]))->getEntity45d250()->getTarget45a760()?(*si_cfd44c.atPoint9ced70(v6c[0]))->getEntity45d250()->u5cbc80():SiHI();
   SiHI h2=m14.isValid()?m14:(*si_cfd44c.atPoint9ced70(v6c[0]))->getItem45d8f0();
   do{if(si_msg5111e0(((0x259)),((&h2->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
   h2->u57a190(ent,4,0,0);
   if(m14.isNull9b65d0())si_eraseAt9d5190(v6c,0);
   do{ent->f40++;ent->clr45b0b0();return (300);}while(false);
  }
  goal=v6c[0];
  do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
 }
  break;
 case 19:
  if(v6c.empty9b86e0()||(*si_cfd44c.atPoint9ced70(v6c[0]))->getProp45d550().isNull9b65d0()||(*si_cfd44c.atPoint9ced70(v6c[0]))->getProp45d550()->u457b10()){
  L19:
   SiSquad*sq=si_cf6428.u683310(ent);
   if(sq)si_cf6428.u68cd80(sq);
   else f4=0x17;
   do{ent->f40++;ent->clr45b0b0();return (100);}while(false);
  }
  if(si_adjacent4373c0(ent->getPosition45a4a0(),v6c[0])){
   for(unsigned i=0;i<ent->v134.size9b9260();i++){
    if(ent->v134[i]->u457f90()==0x7c){
     do{if(si_msg5111e0(((0x27a)),((&ent->v134[i]->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     si_cefc4c->u464940()->push_back9b9280(static_cast<SiShot46*&&>(new SiShot46(v6c[0],ent->v134[i]->u457820(),ent->v134[i]->u45cb30())));
     ent->v134[i]->remove57dbe0(0,0,true,true);
     do{ent->f40++;ent->clr45b0b0();return (200);}while(false);
    }
   }
   v6c.clear9b3560();
   goto L19;
  }
  goal=v6c[0];
  do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
  break;
 case 20:{
  if(v6c.empty9b86e0()||!si_cefc4c->u462ea0(v6c[0])||si_cefc4c->getZone462e30(v6c[0])->h14.isValid()&&(!si_cefc4c->getZone462e30(v6c[0])->h14.operator->()||si_cefc4c->getZone462e30(v6c[0])->h14->u457b10())){
   v6c.clear9b3560();
   SiQ t;
   if(!si_cf6428.findCargoDispatchTarget68a8b0(ent->getPosition45a4a0(),t)){
    f4=2;
    setPatrolRandom5b3430(ent->getPosition45a4a0());
    break;
   }else v6c.push_back9b32e0(t);
  }
  if(!si_cf6514&&!fa0&&!path24.empty9b86e0()&&path24.back9e8c10().eq409b90(goal)&&path24.size9b9a50()<=20&&si_cefc4c->getZone462e30(v6c[0])->h14.isValid()&&si_d1e888->type!=0xd&&(si_cf462c!=10||ent->getName45a280()!="Sauler")){
   fa0=1;
   if(rng.chance(si_b939b4[si_d1e860.getDepthIndex()].f0)&&!si_cefc4c->u464450()){
    int trapId;
    int m27;
    if(si_findByName9d7710(si_cf35b0,"Dirty Bomb Trap",trapId)&&si_findByName9d7de0(si_d2c408,"FAC_RES_Cargo_Ambush",m27)){
     int cnt=0;
     for(int i=0;i<(int)path24.size9b9a50()-5;i+=3){
      if((*si_cfd44c.atPoint9ced70(path24[i]))->u45d6a0()&&si_cefc4c->placeProp6c67b0(trapId,path24[i],-1,9,-1)){
       cnt++;
       (*si_cfd44c.atPoint9ced70(path24[i]))->getProp45d550()->u665b10(m27,0);
       if(cnt==1)si_cf6518=path24[i];
       if(cnt==2)break;
      }
     }
     if(cnt){
      si_cf6514=1;
      si_cf6510=si_cefc4c->getZone462e30(v6c[0])->h14;
     }
    }
   }
  }
  SiVPl cells;
  si_sweep4faaf0(ent->getPosition45a4a0(),cells);
  cells.push_back9b32e0(ent->getPosition45a4a0());
  for(unsigned i=0;i<cells.size9b9a50();i++){
   if(cells[i].eq409b90(v6c[0])){
    SiVHE5 fol;
    if(getFollowers580a90(fol,3)){
     for(int j=fol.size9b9260()-1;j>=0;j--)fol[j]->ai45b590()->getFollowers580a90(fol,0xf);
    }
    for(unsigned j=0;j<fol.size9b9260();j++){
     fol[j]->ai45b590()->u4582d0(0x17);
     fol[j]->ai45b590()->u459520(v6c[0]);
    }
    if(si_cf462c!=10||ent->getName45a280()!="Sauler"){
     si_cf64fc.reset9b7270();
     si_cf6500.clear9b73d0();
    }
    do{if(si_msg5111e0(((si_cefc4c->getZone462e30(cells[i])->h14.isValid()?0x248:0x245)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    ent->u637bb0();
    return 100;
   }
  }
  goal=v6c[0];
  do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
 }
  break;
 case 21:
  if(goal.ne409bd0(v6c.front9b7060()))goal=v6c.front9b7060();
  if(ent->getPosition45a4a0().eq409b90(goal)||si_adjacent4373c0(ent->getPosition45a4a0(),goal)){
   SiVHIl items;
   ent->u5cb830(items);
   if(!items.empty9b86e0()){
    SiQ p;
    if(si_cefc4c->u71bc10(goal,p)){
     do{if(si_msg5111e0(((0x239)),((&items.front9b7060()->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     if(si_d1e888->type==0xd){
      si_cefc4c->getItems4655e0()->push_back9b80b0(items.front9b7060());
      si_cefc4c->getItemPositions465600()->push_back9b32e0(p);
     }
     items.front9b7060()->u57a0f0(p,1,0);
     si_eraseAt9da940(items,0);
     if(v6c.size9b9a50()>1)v6c.erase9b3450(v6c.begin9c1270());
    }
   }
   if(items.empty9b86e0()||v6c.empty9b86e0()){
    f4=0x19;
    u459540(SiP(-1));
    SiVPP ids(*si_cefc4c->u462e10());
    si_shuffle9d8f80(ids);
    for(unsigned i=0;i<ids.size9b9260();i++){
     if(si_cefc4c->u716940(ent->getPosition45a4a0(),*ids[i],0,0)){u459540(*ids[i]);break;}
    }
    if(v6c[0].x==-1)u459540(*(*si_cefc4c->u462e10())[0]);
   }
   do{ent->f40++;ent->clr45b0b0();return (100);}while(false);
  }else do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
  break;
 case 23:{
  SiVPl cells;
  si_sweep4faaf0(ent->getPosition45a4a0(),cells);
  cells.push_back9b32e0(ent->getPosition45a4a0());
  for(unsigned i=0;i<cells.size9b9a50();i++){
   if((*si_cfd44c.atPoint9ced70(cells[i]))->isMachinePart45dcd0()||si_cefc4c->u462ea0(cells[i])){
    SiVHE5 fol;
    if(getFollowers580a90(fol,0xf)){
     for(unsigned j=0;j<fol.size9b9260();j++){
      if(fol[j]->ai45b590()->getF4_9b8f00()!=0x17)fol[j]->ai45b590()->u4582d0(0x17);
     }
    }
    do{if(si_msg5111e0(((si_cefc4c->getZone462e30(cells[i])->h14.isValid()?0x248:0x245)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    if(ent==si_cf68b8){
     switch(si_cf68b4->f110){
     case 0:
      do{}while(false);
      si_cf68b8.reset9b7270();
      si_cf68b4=0;
      si_cf68c0.u45f0a0();
      break;
     case 1:
      si_cf68b8.reset9b7270();
      si_cf68c0.u45f0a0();
      si_cf695c.u45f0a0();
      si_cf6974.u45f0a0();
      break;
     case 2:
      if(si_cf6888.u6997f0(10)){
       si_cf697c.u45f0a0();
       do{}while(false);
      }else{
       si_cf697c.u45f070(si_cf1f80);
       do{}while(false);
      }
      si_cf6888.u699960();
      return 100;
     case 3:
      si_cf68b8.reset9b7270();
      si_cf68c0.set690d40(1,1);
      si_cf69bc.u45f070(si_cf1f90);
      break;
     case 4:
      si_cf68b8.reset9b7270();
      si_cf68c0.u45f070(ent->u5d5250()?si_cfc1b4:si_cf1fa0);
      break;
     case 5:
      do{}while(false);
      si_cf68b8.reset9b7270();
      si_cf68b4=0;
      si_cf68c0.u45f0a0();
      break;
     case 6:
      si_cf68b8.reset9b7270();
      si_cf68c0.u45f070(si_cf1fc0);
      break;
     case 7:
      si_cf68b8.reset9b7270();
      si_cf68b4=0;
      break;
     case 8:
      do{}while(false);
      si_cf68ac.set690d40(-1,-1);
      si_cf68b8.reset9b7270();
      si_cf68c0.u45f0a0();
     }
    }
    ent->u637bb0();
    return 100;
   }
  }
  if(goal.x==-1||!si_cefc4c->u462ea0(goal)){
   SiZone*best=0;
   SiZone*e9=0;
   int m31=1000000;
   int bd2=1000000;
   SiVZ*zs=si_cefc4c->u462e10z();
   for(unsigned i=0;i<zs->size9b9260();i++){
    if(!(*zs)[i]->bc){
     if(!best||si_dist40a3f0(ent->getPosition45a4a0(),*(*zs)[i])<m31){
      best=(*zs)[i];
      m31=si_dist40a3f0(ent->getPosition45a4a0(),*(*zs)[i]);
     }
     if((*zs)[i]->h14.isValid()&&(!e9||si_dist40a3f0(ent->getPosition45a4a0(),*(*zs)[i])<bd2)){
      e9=(*zs)[i];
      bd2=si_dist40a3f0(ent->getPosition45a4a0(),*(*zs)[i]);
     }
    }
   }
   if(si_bba058[ent->getFaction45a2c0()]>=6&&ent->getGroup45a3f0()->type9b4350()!=0xb&&e9)goal=*e9;
   else if(best)goal=*best;
   else{
    SiArea a;
    si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),0xf,a);
    u459470(a);
    do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
   }
  }
  if(ent==si_cf68b8&&si_cf68b4->f110==7&&!si_cf6a4c){
   do{}while(false);
   si_cf6a4c=true;
   for(int k=0;k<2;k++){
    SiVSq ids;
    for(int n=3;n>0;n--)ids.push_back9b9d30(si_d2601c.pick9ba470());
    SiArea a;
    si_cfd44c.getRect9b4430(goal,0xf,a);
    SiQ g_;
    int out;
    if(si_cf6428.findDispatchExit(g_,0,10,1,k==0?ent->getPosition45a4a0():si_cefc4c->getPlayer4630f0()->getPosition45a4a0(),out,0,0)){
     for(unsigned j=0;j<ids.size9b9260();j++){
      SiHE e=si_cefc4c->placeEntity6c58c0(ids[j],g_,0xb,0,k?0x22:0x17,0xe,0);
      if(e.isValid()){
       e->u45b2a0();
       switch(e->name416f40()[0]){
       case 'K':e->u45b070(string("KI-DR0N3 \"Flydakka\""));break;
       case 'T':e->u45b070(string("TH-DR0N3 \"Hotstuff\""));break;
       case 'A':e->u45b070(string("EM-DR0N3 \"Zapster\""));break;
       case 'E':e->u45b070(string("EX-DR0N3 \"Pwner\""));
       }
       if(k==0){
        e->ai45b590()->setFollowEntity5b2f80(ent,0);
        e->ai45b590()->u451930(0);
       }else{
        e->ai45b590()->u459470(a);
        e->ai45b590()->chase5b4710(si_cefc4c->getPlayer4630f0(),1,0,0,0);
       }
      }
     }
    }
   }
  }
  do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
 }
  break;
 case 24:{
  SiVPl cells;
  si_sweep4faaf0(ent->getPosition45a4a0(),cells);
  cells.push_back9b32e0(ent->getPosition45a4a0());
  for(unsigned i=0;i<cells.size9b9a50();i++){
   if((*si_cfd44c.atPoint9ced70(cells[i]))->isMachinePart45dcd0()){
    do{if(si_msg5111e0(((0x245)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    addEarlyExiter5bd450(cells[i]);
    ent->u637bb0();
    return 100;
   }
  }
  if(goal.x==-1||!(*si_cfd44c.atPoint9ced70(goal))->isMachinePart45dcd0()){
   SiZone*best=0;
   int m34=1000000;
   SiVZ*zs=si_cefc4c->u462e10z();
   if(zs->size9b9260()==1)best=(*zs)[0];
   else{
    for(unsigned i=0;i<zs->size9b9260();i++){
     if(!(*zs)[i]->bc&&(*zs)[i]->h8->inRange46ecb0()&&(!best||si_dist40a3f0(ent->getPosition45a4a0(),*(*zs)[i])<m34)){
      best=(*zs)[i];
      m34=si_dist40a3f0(ent->getPosition45a4a0(),*(*zs)[i]);
     }
    }
   }
   if(best)goal=*best;
  }
  do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
 }
  break;
 case 25:
  if(v6c.empty9b86e0()){
   si_logError404f10("EntityAI::takeTurn()::AI_MOVE_EXIT","no waypoint/exit set");
   do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
  }
  if(!si_cfd44c.contains9b43b0(v6c[0])){
   si_logError404f10("EntityAI::takeTurn()::AI_MOVE_EXIT","invalid waypoint/exit set");
   do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
  }
  if(ent->getPosition45a4a0().eq409b90(v6c[0])||(*si_cfd44c.atPoint9ced70(v6c[0]))->getEntity45d250().isValid()&&si_adjacent4373c0(ent->getPosition45a4a0(),v6c[0])){
   if(si_d1e888->f8==4&&ent->getName45a280()=="7R-MNS"){
    do{si_logPhrase5141b0(0xd0,0,0,0,SiHE(),0);}while(false);
    si_cf45d8.u77fbc0(0x150);
    if(!si_cefc4c->u4631f0(ent))si_message49c610(0x320,SiHE(),&string("A triumphal shout echoes through the corridors."),0);
   }else if(ent->getName45a280()=="VL-GR5"&&!ent->isHostileTo45aa70(si_cefc4c->getPlayer4630f0())){
    SiQ p;
    if(si_cefc4c->u71bc10(ent->getPosition45a4a0(),p)){
     int id;
     si_findByName9d7a40(si_d2d1c4,"Multinova Projection Cannon",id);
     SiHI e4=si_cefaa8->createD7932b0(id);
     e4->u57a0f0(p,0,0);
     e4->u579c80();
     do{si_logPhrase5141b0(0x1de,0,0,0,SiHE(),0);}while(false);
     if(si_cefc4c->u4631f0(ent)){
      string msg=ent->name416f40()+" drops Multinova Projection Cannon: \"You know, I like your style and I think you could put this MPC to good use. It's yours!\"";
      si_message49c610(0x320,SiHE(),&msg,0);
     }
    }
   }else if(ent->getFaction45a2c0()==0x5b&&si_d1e888->type==0x17)si_cf45d8.u77fbc0(0x14d);
   bool tr=false;
   SiVPl m38;
   si_sweep4faaf0(ent->getPosition45a4a0(),m38);
   for(unsigned i=0;i<m38.size9b9a50();i++){
    if((*si_cfd44c.atPoint9ced70(m38[i]))->getProp45d550().isValid()&&(*si_cfd44c.atPoint9ced70(m38[i]))->getProp45d550()->tag45c590()=="EXT_Transfer_Station"){tr=true;break;}
   }
   do{if(si_msg5111e0(((tr?0x246:0x245)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
   if(tr)si_fn454260(ent->getPosition45a4a0(),0x92);
   if(b7c)addEarlyExiter5bd450(v6c[0]);
   ent->u637bb0();
   return 100;
  }
  goal=v6c[0];
  do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
  break;
 case 26:
  if(!si_cefc4c->u4631f0(ent)){
   ent->u637bb0();
   return 100;
  }
  if(goal.x==-1||ent->getPosition45a4a0().eq409b90(goal)){
   si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),0x14,a80);
   for(int i=0;i<20;i++){
    goal=a80.randomPoint40be90();
    if((*si_cfd44c.atPoint9ced70(goal))->isPassableFor66ab30(ent)&&!si_cefc4c->isVisible4631c0(goal)&&findPathToGoal5b8d20())return 1;
   }
  }
  do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);
  break;
 case 27:
  while(!v6c.empty9b86e0()&&ent->getPosition45a4a0().eq409b90(v6c.front9b7060()))si_eraseAt9d5190(v6c,0);
  if(v6c.empty9b86e0()){
   if(ent->getName45a280()=="VL-GR5")u459470(si_cfd44c.getArea9b4400());
   else if(ent->getFaction45a2c0()==0x5a){
    SiArea a(0,0,si_cfd44c.width9fcd80()/2,si_cfd44c.height9b8f00());
    u459470(a);
   }else{
    SiArea a;
    si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),0xf,a);
    u459470(a);
   }
   do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
  }
  goal=v6c.front9b7060();
  do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
  break;
 case 28:
  if(a80.contains40b750(ent->getPosition45a4a0())&&!vf0.empty9b86e0()){
   for(unsigned i=0;i<vf0.size9b9260();i++){
    if(si_dist40a3f0(ent->getPosition45a4a0(),vf0[i]->e->getPosition45a4a0())<=15){
     SiQ p;
     if(!u5b66c0(p))return 100;
     else do{}while(false);
    }
   }
  }
  if(goal.x==-1||ent->getPosition45a4a0().eq409b90(goal))u5b91e0();
  do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
  break;
 case 29:
  if(a80.contains40b750(ent->getPosition45a4a0())&&!vf0.empty9b86e0()){
   for(unsigned i=0;i<vf0.size9b9260();i++){
    if(si_dist40a3f0(ent->getPosition45a4a0(),vf0[i]->e->getPosition45a4a0())<=15){
     SiQ p;
     if(!findPatrolSpot5b6850(p))return 100;
     else{
      do{}while(false);
      SiArea a;
      si_cfd44c.getRect9b4430(p,0xc,a);
      SiQ q;
      int m51=0;
      int nLo=0;
      for(int k=si_d2c650.randomInRange40c130();k>0;k--){
       for(int t=0;t<15;t++){
        static_cast<SiP&>(q)=a.randomPoint40be90();
        if(si_cefc4c->u74d420(q,q)&&!si_fn9d0ce0(si_cf69ec,q)){
         SiSpawnDef*d=si_d29da4.pick9ba470();
         if(d->name.find("Stasis")!=string::npos||d->name.find("Shield")!=string::npos){
          if(m51==2)continue;
          m51++;
         }
         si_cf69ec.push_back9b32e0(q);
         si_cf69fc.push_back9b9d30(d->f0);
         nLo++;
         break;
        }
       }
      }
      do{}while(false);
     }
     break;
    }
   }
  }
  if(goal.x==-1||ent->getPosition45a4a0().eq409b90(goal))u5b91e0();
  do{if(!ally114&&rng.chance(f48))do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);}while(false);
  break;
 case 30:{
  int idx=si_indexOfEntity9d3110(si_cf69dc,ent);
  if(idx==-1){}else{
  if(ent->getPosition45a4a0().eq409b90(si_cf69ec[idx])){
   if(si_d25de0[si_cf69fc[idx]]->name.find("Stealth")!=string::npos&&(*si_cfd44c.atPoint9ced70(ent->getPosition45a4a0()))->getProp45d550().isValid())do{if(si_msg5111e0(((0x285)),((0)),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
   string nm(ent->name416f40());
   SiP pos3(ent->getPosition45a4a0());
   ent->u637bb0();
   bool done=false;
   if(si_d25de0[si_cf69fc[idx]]->name.find("Stealth")!=string::npos){
    done=true;
    if((*si_cfd44c.atPoint9ced70(pos3))->getProp45d550().isNull9b65d0()){
     si_cefc4c->u6c6b90(pos3,"",0,0xb);
     int fac;
     if(si_findByName9d7de0(si_d2c408,"Stealth_Turret_Detector",fac)){
      const int range=6;
      SiArea a;
      si_cfd44c.getRect9b4430(pos3,range,a);
      SiQ q;
      for(int k=0;k<5;k++){
       for(int t=0;t<15;t++){
        static_cast<SiP&>(q)=a.randomPoint40be90();
        if((*si_cfd44c.atPoint9ced70(q))->fitsProp45d570(0)&&si_dist40a3f0(pos3,q)<=range){
         si_cefc4c->u6c6b90(q,"",fac,-1);
         break;
        }
       }
      }
     }
     if(si_cefc4c->isVisible4631c0(pos3)){
      string m=nm+" installs Stealth Turret.";
      do{if(si_msg5111e0((0x320),(&m),(0),(0),(SiHE()),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     }
    }
   }else{
    SiHE e=si_cefc4c->placeEntity6c58c0(si_d25de0[si_cf69fc[idx]],si_cf69ec[idx],0xb,0,0x22,0xe,0);
    if(e.isValid()){
     done=true;
     si_fn454260(e->getPosition45a4a0(),0xc2);
     do{if(si_msg5111e0((e->isHostileTo45aa70(si_cefc4c->getPlayer4630f0())?0x28e:0x28d),(&nm),(0),(0),(e),(SiHE()),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    }
   }
   if(done){
    si_eraseAt9da940(si_cf69dc,idx);
    si_eraseAt9d5190(si_cf69ec,idx);
    si_removeVectorElement9de6f0(si_cf69fc,idx);
    if(si_cf69ec.empty9b86e0())si_cf69d8=2;
   }
   return 100;
  }else if(goal.ne409bd0(si_cf69ec[idx]))goal=si_cf69ec[idx];
  do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);
  }
 }
  break;
 case 31:{
  if(getEntity459570(si_cefc4c->getPlayer4630f0())){
   SiVHE2*mem=ent->getGroup45a3f0()->members416f40();
   for(unsigned i=0;i<mem->size9b9260();i++){
    if((*mem)[i]!=ent)(*mem)[i]->ai45b590()->chase5b4710(si_cefc4c->getPlayer4630f0(),1,0,0,0);
   }
   if(si_cf68b4&&ent.operator->()&&si_cf68b8==ent)si_cf68f0->u672f20(ent,0x13,0,"");
  }
  if(!si_cefc4c->u463400(ent)||rng.chance(0x21)){
   SiVHE5 list;
   ent->u5c8880(list);
   if(!list.empty9b86e0()){
    si_shuffle9d9fc0(list);
    for(unsigned i=0;i<list.size9b9260();i++){
     if(si_cf6888.u69ba80(list[i])){
      SiHI it=ent->u5d2a90(0xc7);
      if(it.isValid()){
       SiHE e=list[i];
       e->removeEffectsA639730(0);
       int lvl=5;
       int t=e->ai45b590()->get8_9b4350();
       if(e->getGroup45a3f0()->type9b4350()!=0xb)e->changeFaction5dc780(si_cefc4c->u463890(0xb),0);
       e->setAI64ecf0(new SiAI(e,3,t>8?t:8));
       do{if(si_msg5111e0((0xc6),(&it->getName571db0(0,0)),(&si_intToString(lvl)),(0),(ent),(e),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
       si_fn454260(ent->getPosition45a4a0(),0xe0);
       e->u639530(0x39,lvl+1);
       e->u5fd900(5,0);
       e->u63c660();
       e->ai45b590()->u44cea0(0xc);
       e->ai45b590()->u451930(0x32);
       si_cf6adc.push_back9b80b0(e);
       si_cf6afc.push_back9b80b0(e);
       e->ai45b590()->setFollowEntity5b2f80(ent,0);
       if(rng.chance(10))si_cefc4c->u6c65a0(e,"Borg_Talk",0);
       if(si_cf68b4&&ent.operator->()&&si_cf68b8==ent)si_cf68f0->u672f20(ent,0x12,0,"");
       do{ent->f40++;ent->clr45b0b0();return (100);}while(false);
      }
      break;
     }
    }
   }
  }
  if(fb4.operator->()){
   if(!si_cf6888.u69ba80(fb4)||si_dist40a3f0(ent->getPosition45a4a0(),fb4->getPosition45a4a0())>10||si_cefc4c->u4633c0(fb4->getPosition45a4a0())&&si_dist40a3f0(si_cefc4c->getPlayer4630f0()->getPosition45a4a0(),fb4->getPosition45a4a0())<=10)fb4.reset9b7270();
   else{
    if(si_fn9daf80(3,fb4->getGroup45a3f0()->type9b4350(),4)&&(fb4->ai45b590()->get8_9b4350()<6||fb4->ai45b590()->vf0.empty9b86e0()))si_d225a0.u672b80(fb4,0xc8);
    goal=fb4->getPosition45a4a0();
    do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   }
  }
  if(si_cefc4c->getTurn464270()%2==0){
   int bd=0;
   SiArea a;
   si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),8,a);
   for(int x=a.x1;x<=a.x2;x++)for(int y=a.y1;y<=a.y2;y++){
    if((*si_cfd44c.at9ceda0(x,y))->getEntity45d250().isValid()&&!si_cefc4c->u463380(x,y)&&si_cf6888.u69ba80((*si_cfd44c.at9ceda0(x,y))->getEntity45d250())){
     int d;
     if(si_cefc4c->u716940i(ent->getPosition45a4a0(),SiP(x,y),ent.operator->(),&d)&&(!bd||d<bd)){
      bd=d;
      fb4=(*si_cfd44c.at9ceda0(x,y))->getEntity45d250();
     }
    }
   }
   if(fb4.operator->()){
    goal=fb4->getPosition45a4a0();
    do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   }
  }
  if(a80.contains40b750(goal)&&si_dist40a3f0(si_cefc4c->getPlayer4630f0()->getPosition45a4a0(),goal)<=20){
   do{*(SiP*)&a80=si_cfd44c.getRandom9cf050();}while(!(*si_cfd44c.atPoint9ced70(*(SiP*)&a80))->u4550b0());
   si_cfd44c.getRect9b4430(*(SiP*)&a80,0x14,a80);
   u459410(a80);
  }
  if(goal.x==-1||ent->getPosition45a4a0().eq409b90(goal))u5b91e0();
  do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
 }
  break;
 case 32:{
  if(ent->u45aaa0(si_cefc4c->getPlayer4630f0())){
   SiP t(-1);
   if(!si_d1d9c0.getTarget872e40(ent,t)&&ent->u45a940()<=50&&rng.chance(25)){
    SiArea a;
    si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),10,a);
    for(int x=a.x1;x<=a.x2;x++)for(int y=a.y1;y<=a.y2;y++){
     if((*si_cfd44c.at9ceda0(x,y))->getEntity45d250().isValid()&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->getFaction45a2c0()==5&&(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->getGroup45a3f0()->type9b4350()==4&&si_cefc4c->isReachable465230(10,ent->getPosition45a4a0(),SiP(x,y)))t.set40a010(x,y);
    }
   }
   if(t.x!=-1){
    SiQ q;SiVPl g6;SiVX v2;SiVX cB;
    bool fail=!si_cefc4c->u7170a0(ent,t,g6,v2,cB,q,0,4,1,1);
    if(!fail){
     int ok5=1;
     SiVHIl pTo;
     ent->u5d6a80(pTo,t,-1);
     if(pTo.empty9b86e0())goto L32a;
     for(unsigned m=0;m<pTo.size9b9260();m++)if(pTo[m]->def9b4350()->f1a0)goto L32a;
     int total=0;
     for(unsigned m=0;m<pTo.size9b9260();m++)total+=pTo[m]->u5788e0();
     if(total>ent->u45a8d0())ent->u5ded70(ent->u45a8d0());
     total=0;
     for(unsigned m=0;m<pTo.size9b9260();m++)total+=pTo[m]->u5789c0();
     if(total>ent->u45a920())ent->u5deb40(total);
     ent->f40++;ent->clr45b0b0();
     b110=true;
     SiVE8 v;
     if(ent==si_cefc4c->getEntity463110()&&(*si_cfd44c.atPoint9ced70(t))->getEntity45d250().isValid()&&si_cefb48)si_cefb48->say49e250(0x2a,0,(*si_cfd44c.atPoint9ced70(t))->getEntity45d250()->name416f40());
     int a_;
     si_cefc4c->addRecord777a20(si_cefaa8->createA7930e0(new SiShoot(ent,ok5,t,q,a_,v,0,SiHE())));
     return a_;
    }
   L32a:;
   }
  }
  if(fd4.operator->()&&(*si_cfd44c.atPoint9ced70(ent->getPosition45a4a0()))->getItem45d8f0()==fd4){
   if(fd4->u457880()>=6){
    int avail=ent->u5c8d80(si_ba7ac8[ent->u5d1390()]);
    avail-=ent->u5c8cb0();
    if(fd4->u457b30()<=avail){
     SiVI2 slotsD;
     ent->u5c93d0(slotsD);
     bool ok=false;
     int cost=0;
     if(slotsD[fd4->u4578a0()]>=fd4->u4578c0())ok=true;
     else{
      SiVHI5 inv;
      ent->u5cb8b0(inv);
      SiHI up=si_findUpgrade4fe3f0(fd4,inv,ent);
      if(up.isValid()){
       if(up->def9b4350()->b1ac){
        do{if(si_msg5111e0(((0x300)),((&up->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
        up->remove57dbe0(0,0,3,1);
        cost+=si_b95fb8;
        ok=true;
       }else{
        SiHI a;
        SiHI pct;
        if(ent->u45a810()>=up->u4578c0())a=up;
        else{
         pct=up;
         SiVHI5 inv2;
         ent->u5cb830(inv2);
         si_removeEntity9d2f00(inv2,up);
         SiHI q12=si_findUpgrade4fe3f0(up,inv2,ent);
         if(q12.isValid()){a=up;pct=q12;}
        }
        SiQ newP;
        if(si_cefc4c->u71bc10(ent->getPosition45a4a0(),newP)){
         if(pct.isValid()){
          do{if(si_msg5111e0(((0x301)),((&pct->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
          pct->u57a0f0(newP,1,0);
          cost+=si_b95fc0;
         }
         if(a.isValid()){
          do{if(si_msg5111e0(((0x2ff)),((&a->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
          a->u57a190(ent,4,0,1);
          cost+=si_b95fb8;
         }
         ok=true;
        }
       }
      }else if(ent->u45a810()>=fd4->u4578c0()){
       do{if(si_msg5111e0(((0x2fe)),((&fd4->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
       if(fd4->name457860()=="L-Cannon"){
        if(si_cefb48)si_cefb48->say49e250(0x73,0,"");
        else if(fd4->u457920()>si_d1e888->getDepthIndex()&&si_cefb48)si_cefb48->say49e250(0x16,0,fd4->getName571db0(0,0));
       }
       fd4->u57a190(ent,4,0,0);
       fd4.reset9b7270();
       do{ent->f40++;ent->clr45b0b0();return (si_b95fac);}while(false);
      }
     }
     if(ok){
      fd4->u57a190(ent,fd4->u4578a0(),0,0);
      if(si_cf462c==7)si_d2c658.add4729d0(0x44b,1,si_empty_b91de7,-1);
      do{if(si_msg5111e0(((0x302)),((&fd4->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      if(fd4->u457920()>si_d1e888->getDepthIndex()){
       if(si_cefb48)si_cefb48->say49e250(0x16,0,fd4->getName571db0(0,0));
       if((fd4->u457880()==0x15&&fd4->def9b4350()->f128!=3||fd4->u457880()==0x17)&&si_cefb48)si_cefb48->say49e250(0x17,0,fd4->getName571db0(0,0));
       if(fd4->u457880()==0x18&&si_cefb48)si_cefb48->say49e250(0x18,0,fd4->getName571db0(0,0));
      }
      if(fd4->u4578a0()==3&&ent->u5cba50()==1&&si_cefb48)si_cefb48->say49e250(0x1d,0,fd4->getName571db0(0,0));
      u5b57a0(fd4,0);
      goal.x=-1;
      cost+=si_b95fb0;
      fd4.reset9b7270();
      do{ent->f40++;ent->clr45b0b0();return (cost);}while(false);
     }else goto L32b;
    }else if(ent->u45a810()>=fd4->u4578c0()){
     do{if(si_msg5111e0(((0x2fe)),((&fd4->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
     if(fd4->u457920()>si_d1e888->getDepthIndex()&&si_cefb48)si_cefb48->say49e250(0x16,0,fd4->getName571db0(0,0));
     fd4->u57a190(ent,4,0,0);
     fd4.reset9b7270();
     do{ent->f40++;ent->clr45b0b0();return (si_b95fac);}while(false);
    }else{
    L32b:
     SiVHI5 inv3;
     ent->u5cb830(inv3);
     SiHI up=si_findUpgrade4fe3f0(fd4,SiVHI5(inv3),ent);
     if(up.isValid()){
      fd4->u57a190(ent,4,0,1);
      if((*si_cfd44c.atPoint9ced70(ent->getPosition45a4a0()))->getItem45d8f0().isNull9b65d0()){
       up->u57a0f0(ent->getPosition45a4a0(),1,0);
       do{if(si_msg5111e0(((0x301)),((&up->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      }
      do{if(si_msg5111e0(((0x2fe)),((&fd4->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
      if(fd4->u457920()>si_d1e888->getDepthIndex()&&si_cefb48)si_cefb48->say49e250(0x16,0,fd4->getName571db0(0,0));
      fd4.reset9b7270();
      do{ent->f40++;ent->clr45b0b0();return (si_b95fbc);}while(false);
     }
    }
   }
   fd4.reset9b7270();
  }
  if(si_cf462c==7&&rng.chance(5)){
   SiHI curBest;
   SiHI other;
   SiHI cur;
   int bestv;
   for(unsigned i=0;i<ent->v134.size9b9260();i++){
    cur=ent->v134[i];
    if(cur->u4578a0()==3&&cur->u4578c0()==1){
     if(cur->getType44aec0()<=3){
      if(cur->u457880()==0x18){
       int v=cur->u457920()+cur->u457ca0()/40;
       if(curBest.isNull9b65d0()||v>bestv){curBest=cur;bestv=v;}
      }
     }else if(other.isNull9b65d0()){
      if(cur->u457880()==0x18)goto L32c;
      other=cur;
     }
    }
   }
   if(curBest.isValid()&&other.isValid()){
    curBest->u57a190(ent,4,0,1);
    do{if(si_msg5111e0(((0x303)),((&other->getName571db0(0,0))),(0),(0),((ent)),((SiHE())),0,false))si_cec058->bubble8758d0(true);si_cec0b4->end7b4f10();}while(false);
    other->u57a190(ent,other->u4578a0(),0,0);
    u5b57a0(other,0);
    if(si_cf462c==7)si_d2c658.add4729d0(0x44b,1,si_empty_b91df3,-1);
    do{ent->f40++;ent->clr45b0b0();return (si_b95fbc);}while(false);
   }
  }
 L32c:
  if(goal.x!=-1&&fd4.operator->()&&(*si_cfd44c.atPoint9ced70(goal))->getItem45d8f0()==fd4){
   if(si_cefc4c->u464410(goal)){
    fd4.reset9b7270();
    goal.x=-1;
   }else do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);
  }
  if(si_cf462c==7||si_cf462c==6&&rng.chance(33)){
   int hN=ent->u5c8d80(si_ba7ac8[ent->u5d1390()]);
   hN-=ent->u5c8cb0();
   bool aD=ent->u5c8fc0(3,0);
   SiVI2 slots;
   ent->u5c93d0(slots);
   int aT=ent->u45a810();
   int range=ent->u5c7d30();
   SiArea bB;
   si_cfd44c.getRect9b4430(ent->getPosition45a4a0(),range,bB);
   SiHI k1;
   SiHI best;
   int bestScore=0;
   SiVHI5 curInv;
   ent->u5cb8b0(curInv);
   SiVHI5 eA;
   SiPlan jD(ent,2);
   int hubVal;
   for(int x=bB.x1;x<=bB.x2;x++)for(int y=bB.y1;y<=bB.y2;y++){
    if((*si_cfd44c.at9ceda0(x,y))->getItem45d8f0().isValid()){
     k1=(*si_cfd44c.at9ceda0(x,y))->getItem45d8f0();
     if((si_cf462c!=7||k1->def9b4350()->b274)&&!si_containsEntity9d31e0(si_cf46b4,k1)&&!si_cefc4c->u464410(SiP(x,y))&&(!f58.operator->()||si_dist40a3f0(SiP(x,y),f58->getPosition45a4a0())<=20)&&((*si_cfd44c.at9ceda0(x,y))->getEntity45d250().isNull9b65d0()||!(*si_cfd44c.at9ceda0(x,y))->getEntity45d250()->u5d1280(0))&&si_cefc4c->isReachable465230(range,ent->getPosition45a4a0(),SiP(x,y))){
      bool take=false;
      bool up7=false;
      if(k1->u457880()<6){
       switch(k1->u457880()){
       case 0:take=ent->u45a940()<=0x42;break;
       case 3:take=ent->u45a880()<=0x5a;break;
       case 2:take=true;
       }
      }else if(k1->u457d70()&&!k1->getEffect457b70(0x56)){
       if(k1->u4578a0()==1||k1->u457b30()<=hN||k1->u4578c0()<=aT||!aD&&k1->u4578a0()==3){
        if(slots[k1->u4578a0()]>=k1->u4578c0())take=true;
        else if(rng.chance(50)){
         if(si_findUpgrade4fe3f0(k1,SiVHI5(curInv),ent).isValid()){take=true;up7=true;}
        }
       }
      }
      if(take){
       hubVal=jD.score581e70(k1,up7);
       if(hubVal>bestScore){best=k1;bestScore=hubVal;}
      }
      if(!take&&k1->u457880()>=6)eA.push_back9b80b0(k1);
     }
    }
   }
   if(best.isValid()){
    goal=best->u575920();
    do{}while(false);
    fd4=best;
    if(si_cefb48)si_cefb48->say49e250(0x1f,0,fd4->getName571db0(0,0));
    do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
   }else{
    SiVHI5 inv2;
    ent->u5cb830(inv2);
    jD.u581b80(3);
    bool q42=false;
    for(unsigned i=0;i<eA.size9b9260();i++){
     k1=eA[i];
     if(k1->u4578c0()>aT){
      if(si_findUpgrade4fe3f0(k1,SiVHI5(inv2),ent).isNull9b65d0())continue;
      else q42=true;
     }
     hubVal=jD.score581e70(k1,q42);
     if(hubVal>bestScore){best=k1;bestScore=hubVal;}
    }
    if(best.isValid()){
     goal=best->u575920();
     do{}while(false);
     fd4=best;
     if(si_cefb48)si_cefb48->say49e250(0x1f,0,fd4->getName571db0(0,0));
     do{do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);}while(false);
    }
   }
  }
  if(f58.operator->())goto L15e5c;
  else if(goal.x==-1||ent->getPosition45a4a0().eq409b90(goal))u5b93a0();
  do{if(goal.x!=-1){int t;if(!move5b76c0(&t)||u5b7400(&t))return t;}}while(false);
 }
  break;
 }
 do{ent->f40++;ent->clr45b0b0();return (rng.rangeInt(-10.0f,10.0f)+100);}while(false);
}
