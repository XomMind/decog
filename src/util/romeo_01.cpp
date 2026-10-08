// romeo_01: KcCMap::render = CMap::render 0x83dfa0 (size 0x2a078), drafted by kilo/mike/oscar, frame layout by romeo.
// Lives in src/util/ (sorts last in the link). Notes: scratch/romeo/NOTES.md, scratch/oscar/83dfa0_NOTES.md.
// NOTE: CMap::render (0x83dfa0, CMap vtable slot 7) on private placeholder views; placeholder names/layouts throughout.
// Kc prefix = kilo private types. Draft: see scratch/kilo/83dfa0_NOTES.md.
#include <string>
using namespace std;
struct KcColor{unsigned char r,g,b;KcColor(int,int,int);KcColor(float,float,float);void scale412bd0(float);KcColor();KcColor(unsigned char);KcColor(const KcColor&);KcColor&operator=(KcColor);KcColor operator*(float);KcColor operator+(KcColor);bool operator!=(KcColor);bool operator==(KcColor);KcColor&operator*=(float);
 static KcColor lerp(KcColor,KcColor,float);static KcColor addAlpha(KcColor,KcColor,float);static KcColor overlay(KcColor,KcColor);static KcColor scale(KcColor,float);static KcColor add(KcColor,KcColor);static KcColor grayscale413940(KcColor);string toString4121c0();};
struct KcPos{int x,y;KcPos();KcPos(const KcPos&,const KcPos&);KcPos(int,int);explicit KcPos(int);KcPos(const KcPos&);KcPos&operator=(const KcPos&);void set40a090(const KcPos&,const KcPos&);bool contains409d70(int,int,int,int);KcPos add409b60(const KcPos&)const;void move40a2a0(int,int);void sub409a30(const KcPos&);void set40a010(int,int);bool eq409bd0(const KcPos&);bool eq409b90(const KcPos&);bool eq409cb0(int,int);bool ne409cf0(int,int);void set409ff0(int);void sub409a70(const KcPos&);KcPos sub409b30(const KcPos&)const;};
struct KcVPos;struct KcVEnt;struct KcArea2{int x1,y1,x2,y2;bool u40b700(int,int);KcArea2();KcArea2(const KcArea2&);bool contains40b750(const KcPos&);void getBorder40bac0(KcVPos&);};struct KcVPos;struct KcVTrail;struct KcEntity;struct KcItem;struct KcProp;struct KcGroup;struct KcAI;
struct KcHE{int id;KcHE();int id9fcd80();KcEntity*operator->()const;bool isValid()const;bool isNull9b65d0()const;void reset9b7270();bool operator==(KcHE)const;bool operator!=(KcHE)const;};
struct KcHI{int id;KcItem*operator->()const;bool isValid()const;bool isNull9b65d0()const;void reset9b7270();};
struct KcHP{int id;KcProp*operator->()const;KcProp*get9b64f0()const;bool isValid()const;bool isNull9b65d0()const;};
struct KcHG{int id;KcGroup*operator->()const;};
struct KcGroup{int type9b4350();KcVEnt&u416f40();int indexOf45e1a0(KcHE);};
struct KcInfo{char pad0[0x10];int i10;};
struct KcPropDef{};
struct KcPD4;struct KcPD3{char pad[0x20];int a20[10];};struct KcPropDef2{char pad0[0x60];KcPD3*p60;char pad64[0xa0-0x64];int ia0;char pada4[4];int ia8[10];char padd0[0x15c-0xd0];KcPD4*p15c;};
struct KcPD4{char pad[0x70];int i70;};struct KcSAInfo{int i0;string name;};struct KcSAItem{KcSAInfo*u9fcd80();};struct KcVSA{int pv0,pv1,pv2,pv3;unsigned size9b9260()const;KcSAItem*&at9b81f0(unsigned);};struct KcSAList{KcVSA*u9c0790();};struct KcTrait{KcSAInfo*info;};struct KcVTraits{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9260()const;KcTrait*&at9b81f0(unsigned);};struct KcProp{int u45c650();KcColor color65dbb0();bool isTrap45cb70();const string&name45c5b0();KcSAList*u45c9b0();KcVTraits&u45c7e0();bool u45cad0();bool u45caf0();const string&name45c590();bool u45cb10();int u457b10();KcPropDef2*def9b8f00();int u44ab40();KcPos&pos4184d0();KcColor color65e040();KcInfo*info44b020();bool isPassable65e1d0(KcHE);bool u470b30();int u45c630();};
struct KcItemDef{char pad0[0x94];int i94;char pad98[0x24c-0x98];bool b24c;char pad24d[0x275-0x24d];bool b275;};
struct KcItem{KcHE u457b50();KcPos&u575920();int u577a90();bool u458220();int kind457f90();int range457fb0();int ascii457a30();KcItemDef*def9b4350();bool u458030();int getEffect457b70(int);int nested457820();const string&name457860();int u4580c0();KcColor&color5755f0(int);};
struct KcPart{int u458950(int);};struct KcAI{KcPos*getPos462e10();int u9b8f00();KcVPos&u4968a0();KcArea2*u4b5730();KcVPos&u458ef0();KcVPos&u4549b0();bool u459090();KcPart*u4590f0();bool u4595f0();int u458f30();unsigned*u459010();bool u581a00(int);int type9b4350();};
struct KcEntDef{char pad0[0xac];int iac;char padb0[0x21c-0xb0];int i21c;};
struct KcVHX;struct KcVInt;struct KcEntity{KcPos u45a4c0();KcVPos&u45d1a0();KcEntDef*def9b4350();bool u5d2a00(int);int getAiType45a2a0();int getSize();bool isHostileTo(KcHE);int u5cb9b0(int);bool u45aaa0(KcHE);int u5cab90();int getTarget();KcHI item5d2380(int);const string&getName45a280();int u45a8d0();int u45a990();int u5ca840();int getAsciiDefault5c79d0();bool u5c85a0(const KcPos&,int);int u5d1390();KcHP u5d5d40();int u5d2090(int);int u5d22a0(int);KcPos&getPosition();bool u5cd3e0();int getAscii5c7a10(const KcPos&);KcColor&color5c7630();bool u45abb0();unsigned u459300();bool u45ac00();bool u45aff0();bool isPlayer();int rel5c7fc0(KcHE);KcAI*ai45b590();KcHG getGroup();unsigned*u4aec60();int getFaction();int u45acb0(int);bool u5d52b0();bool u5d4100();bool u5d4490(KcHE);int u5d15a0(int);int u5d2150(int,int);int u5c7d30();void u5d6c30(KcVHX&);void u5c9190(int,KcVHX&,int);void u5d7700(KcVHX&,KcVInt&);KcVTrail&u45a740();KcPos u5c80f0(const KcPos&);};
struct KcPD3;struct KcCellDef{char pad0[0x44];KcColor c44;KcColor back47;char pad4a[0x50-0x4a];KcPD3*p50;char pad54[0x68-0x54];int i68;};
struct KcCell{int highlighter4ab670();bool u45d310();bool u4550b0();bool u45db50();int u45a6e0();bool canCaveIn66af50();int u457b10();KcHI getItem();KcHE getEntity();bool u45d700();int getAscii66a830();KcColor getColor66a680();bool u45d1e0();KcHP getProp();KcCellDef*def9fcd80();bool isDoor();KcPos&u45d1a0();bool u66b120();bool isEdge45dc30();bool isMachinePart45dcd0();bool u45db70();bool isShortcut45dc50();bool isPassable66ab30(KcHE);};
struct KcS14{int a;int b;KcHE h8;bool isActive72ec10();int getValue461cf0(int);KcColor getColor72eb70();};
struct KcS34{int ch;int i4;KcColor fore8;KcColor backb;bool be;char padf[0x10-0xf];int i10;char pad14[0x2c-0x14];unsigned t2c;};
struct KcGridC{char pad[4];unsigned char*at9cec50(int,int);bool&at9d2770(const KcPos&);};
struct KcGridI{char pad[4];int width9fcd80();int height9b8f00();int*at9ceda0(int,int);int*atPoint9ced70(const KcPos&);};struct KcGridI2{char pad0[0xc];int i0c;int i10,i14,i18;int*at9ceda0(int,int);int*atPoint9ced70(const KcPos&);};
struct KcGridS14{char pad[4];KcS14*at9cdf20(int,int);KcS14*atPoint9d2930(const KcPos&);};
struct KcGridS34{char pad[4];KcS34*at9d2c30(int,int);};
struct KcGridCell{void getBounds9b7a40(const KcPos&,int,KcPos&,KcPos&);bool contains9b43b0(const KcPos&);void getRect9b4430(const KcPos&,int,KcArea2&);int width9fcd80();int height9b8f00();KcCell**at9ceda0(int,int);KcCell**atPoint9ced70(const KcPos&);bool inBounds9b45c0(int,int);};extern KcGridCell kc_cfd44c;
struct KcVHE{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;};
struct KcVU{int pv0,pv1,pv2,pv3;void clear9bac80();unsigned size9b9260()const;void push_back9b9d30(const unsigned&);void push_back9b9280(unsigned&&);unsigned&at9b81f0(unsigned);};
struct KcVI{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;void clear9bac80();unsigned size9b9260()const;int&at9b81f0(unsigned);};
struct KcVEnt{int pv0,pv1,pv2,pv3;void clear9b73d0();bool empty9b86e0()const;unsigned size9b9260()const;KcHE&at9b81f0(unsigned);};
struct KcMark{KcHE e;int t;};
struct KcVMark{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9a50()const;KcMark&at9e7c10(unsigned);};
struct KcSubCon;struct KcLabel{char pad0[4];KcSubCon*con4;char pad8[0x30-8];bool b30;bool b31;char pad32[2];KcLabel(int,KcSubCon*,int,unsigned,const KcPos&,KcHE,KcHE,KcHE,const KcPos&);};
struct KcVLabel{int pv0,pv1,pv2,pv3;KcLabel*&back9b6540();void push_back9b9280(KcLabel*&&);};
struct KcVSet{int pv0,pv1,pv2,pv3;};
struct KcMarkers{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9260()const;KcHP&at9b81f0(unsigned);};struct KcMarkersHolder{KcMarkers&at9b8070(unsigned);};
struct KcRect{int x1,y1,x2,y2;};struct KcVRect{bool empty9b86e0()const;unsigned size9b5100()const;KcRect&at9b8070(unsigned);};
struct KcVPts{unsigned size9b9a50()const;KcPos&at9e7c10(unsigned);};
struct KcVPos{int pv0,pv1,pv2,pv3;KcVPos();KcVPos(const KcVPos&);~KcVPos();void push_back9b32e0(const KcPos&);void clear9b3560();bool empty9b86e0()const;void push_back9b3020(KcPos&&);unsigned size9b9a50()const;KcPos&at9e7c10(unsigned);KcPos&back9e8c10();KcPos&front9b7060();};
struct KcCellX{bool u461250();};struct KcGridX{KcCellX*at9d2c30(int,int);};
struct KcRec{int i0;string name;char pad20[0x148-0x20];int x148;};struct KcVRec{KcRec*&at9b81f0(unsigned);};extern KcVRec kc_d25de0;
struct KcMapInfo{int a,type;char pad8[0x60-8];bool b60;};struct KcHLoc{int id;KcMapInfo*operator->()const;};extern KcHLoc kc_d1e888;
struct KcGameData{const string&text46f6d0(const string&);bool isFlag46fb60();bool u789580(KcHE);};extern KcGameData kc_d1e860;
int kc_stringToInt405610(const string&);
bool kc_containsRecord9db330(int*,int);
float kc_pulse4372b0(float,float,unsigned,unsigned);
bool kc_blinkSince437340(int,unsigned);
float kc_minf9cd050(float,float);
struct KcVGrid{int pv0,pv1,pv2,pv3;KcGridI2*&at9b81f0(unsigned);};
struct KcBox{KcPos a,b;KcBox(const KcPos&,int);};
struct KcVbRef{unsigned*p;unsigned o;KcVbRef();operator bool()const;};
struct KcVBool{int pv0,pv1,pv2,pv3,pv4;KcVBool(unsigned,bool);~KcVBool();KcVbRef at9b38a0(unsigned);};
extern KcVPos kc_d01b28,kc_d1e234;
struct KcVE8{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9a50()const;const KcPos&at9b32b0(unsigned)const;};extern KcVE8 kc_d35860,kc_d1daec;
void kc_eraseStep9d7300(KcVE8&,unsigned&);
extern KcVI kc_d02b64,kc_cf4a04;void kc_eraseAt9ce6d0(KcVI&,unsigned&);extern int kc_b94908[];extern bool kc_d25450;extern int kc_d255fc,kc_cefc04;
struct KcRng{bool chance406cc0(float);bool chance406c90(int);int rangeInt406d70(float,float);};extern KcRng rng;
struct KcRange{int x,y;KcRange(int,int);int random40c130();};
void kc_eraseAt9d5190(KcVPos&,int);void kc_eraseAt9ce6d0(KcVU&,unsigned&);
float kc_fade437250(float,int,int);
struct KcE14{KcPos pos;int ch;int type;int t10;};struct KcVE14{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b96e0()const;const KcE14&at9b9700(unsigned)const;};
struct KcE12{KcPos pos;unsigned t8;};struct KcVE12{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b4760()const;KcE12&at9b4780(unsigned);};void kc_eraseStep9e2a40(KcVE12&,unsigned&);
struct KcHT{KcHI h;int t;};struct KcVHT{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9a50()const;KcHT&at9e7c10(unsigned);};
void kc_append9d7f20(KcVPos&,KcVPos&);int kc_minInt9cdb30(int,int);struct KcCfg2{char pad[0x78];int i78;};extern KcCfg2*kc_cefbe4;extern int kc_d01618;
struct KcE16{KcPos pos;bool b8;unsigned tc;};struct KcVE16{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b5100()const;KcE16&at9b8070(unsigned);};void kc_eraseStep9e2a90(KcVE16&,unsigned&);
struct KcBlastDef{char pad0[0x38];int i38;char pad3c[0x70-0x3c];int i70;};struct KcBlast{KcBlastDef*def;KcPos pos;unsigned t;};struct KcVBlast{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b5100()const;KcBlast&at9b8070(unsigned);};void kc_eraseStep9e2ae0(KcVBlast&,unsigned&);extern KcColor kc_cf40ac[];
struct KcVInt{int pv0,pv1,pv2,pv3;KcVInt(unsigned,unsigned);bool empty9b86e0()const;KcVInt();KcVInt(unsigned,const int&);int&front9b7060();int&back9b6540();void push_back9b9280(int&&);~KcVInt();void push_back9b9d30(const int&);unsigned size9b9260()const;int&at9b81f0(unsigned);};
struct KcVPtsM{int pv0,pv1,pv2,pv3;KcPos&front9b7060();unsigned size9b9a50()const;KcPos&at9e7c10(unsigned);};struct KcVVPts{int pv0,pv1,pv2,pv3;unsigned size9b5100()const;KcVPtsM&at9b8070(unsigned);};
struct KcEffect;struct KcEngine{void update50fff0();void render5100b0();KcEffect*new50fb50();};
struct KcCon;struct KcSubCon;
struct KcArea{int x,y,w,h;KcArea();KcArea(int,int,int,int);KcArea(const KcPos&,int,int);bool containsRect40aa70(const KcArea&);bool touches40aef0(const KcArea&);void intersect40ab30(const KcArea&,KcArea&);};
extern KcPos kc_d1ec6c;
struct KcRng2{bool chance406c90(int);};
bool kc_eq9ccb50(const string&,const char*);void kc_surrounding4faaf0(const KcPos&,KcVPos&);extern int kc_d28d48;extern KcVPos kc_d2ec1c;extern KcVU kc_cfc20c;
extern KcVPos kc_cf2800;extern KcVU kc_d32ecc;extern int kc_d28e9c;
//MIKE decls
extern KcCon*kc_cec054;extern const float kc_c37088;
void kc_rotate406640(float,float,float,float,float,float*,float*);bool kc_traceSubcell4106d0(const KcPos&,const KcPos&,KcVPos&,KcVInt&,int);void kc_insertAt9dbdc0(KcVInt&,int,int);extern const double kc_c36da8;
void kc_todo(int);struct KcNoise;struct KcNoiseHost{KcNoise*u454d50();};extern KcCellDef*caveinThirdTerrain,*kc_cefba8,*kc_cefbac;extern bool kc_d28e80;struct KcFilt{int i0;};struct KcVFilt{int pv0,pv1,pv2,pv3;KcVFilt(const KcVFilt&);~KcVFilt();KcVFilt&operator=(const KcVFilt&);bool empty9b86e0()const;unsigned size9b5100()const;KcFilt&at9b8070(unsigned);};extern KcVFilt kc_d28d90,kc_d28da0,kc_d1d45c;extern const double kc_c37080,kc_c370f0;extern bool kc_cefb16;void kc_decode4712a0(string&);extern string kc_d25664;struct KcVHeavy;struct KcVAll{int pv0,pv1,pv2,pv3;KcVAll();~KcVAll();bool empty9b86e0()const;};struct KcRec24{~KcRec24();};struct KcRandObj{KcHE u45a260();};KcRandObj*kc_randomRec9d5d00(KcVAll&);struct KcPool24{void getAll9d0c30(KcVAll&);KcRec24*release9d0bc0(KcHE);};extern KcPool24 kc_d21720;extern bool kc_cefb28,kc_cefb3e,kc_cefb27,kc_cefb29,kc_cefb2b,kc_cefb2c;struct KcCE20Item{int idx;int i4;bool b8;char pad9[3];};struct KcCE20{char pad[0x28];int i28;KcCE20Item*p2c;};extern KcCE20*kc_cec020;struct KcVGI{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;KcGridI*&back9b6540();};extern KcVGI kc_d22744;struct KcIntPair{int a,b;};extern KcIntPair kc_b90290[];extern KcGridI kc_cf6488;struct KcCF68{char pad[0x110];int i110;};extern KcCF68*kc_cf68b4;extern KcHE kc_cf6984,kc_cf69a8,kc_cf68b8;extern KcColor*kc_d20b78,*kc_d1dae0,*kc_d29d68;struct KcVStr2{int pv0,pv1,pv2,pv3;KcVStr2();~KcVStr2();void push_back9b06f0(const string&);};int kc_findString9ceb50(KcVStr2&,string);extern KcVPos kc_cf69ec;extern KcVI kc_cf69fc;extern bool kc_cefad3;extern int kc_cf4a68;extern const char kc_empty_b964d6[];struct KcVVI2{int pv0,pv1,pv2,pv3;unsigned size9b5100()const;KcVI&at9b8070(unsigned);};extern KcVVI2 kc_cf4a58;struct KcD2{char pad[0x24];string name;};struct KcVD2{int pv0,pv1,pv2,pv3;KcD2*&at9b81f0(unsigned);};extern KcVD2 kc_d2d1c4;struct KcVHeavy{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;KcVHeavy();KcVHeavy(const KcVEnt&);~KcVHeavy();unsigned size9b9260()const;KcHE&at9b81f0(unsigned);void push_back9b80b0(const KcHE&);};void kc_eraseStep9d6440(KcVHeavy&,unsigned&);extern const float kc_c370f8;extern bool kc_cefb14;extern int kc_cf6428;extern string kc_d293c0[];void kc_padLeft408090(string&,int,char);string kc_intToStringSigned405560(int);struct KcVF;extern KcVF kc_cf4634;extern const double kc_c36ca0;extern KcGridCell kc_cf447c;bool kc_terrainFlag448b80(const KcPos&);extern const char*kc_cea004;extern KcColor*kc_cfc174,*kc_d31574;extern KcColor kc_d2cf08[][10];extern int kc_b96118[],kc_b96130[];extern bool kc_cefaeb,kc_cefaec;extern int kc_cefad8;struct KcFovCb;extern KcFovCb kc_d25624,kc_d39710;extern const float kc_ba6b08,kc_ba6b0c,kc_ba6b10;extern KcColor*kc_d1d46c,*kc_d30824,*kc_d32df8,*kc_d2061c,*kc_d33ac4,*kc_d323c4;struct KcVCave{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b5ec0()const;KcVPtsM&at9b5ee0(unsigned);};extern KcVCave kc_cf126c;struct KcRectC{int x1,y1,x2,y2;bool contains40a9a0(int,int);};struct KcVRectC{int pv0,pv1,pv2,pv3;unsigned size9b5100()const;KcRectC&at9b8070(unsigned);};extern KcVRectC kc_d222f0;struct KcCnt{int x1,y1,x2,y2;int i10;bool contains40a9a0(int,int);};struct KcVCnt{int pv0,pv1,pv2,pv3;unsigned size9b9260()const;KcCnt*&at9b81f0(unsigned);};extern KcVCnt kc_cf3a00;extern bool kc_cefae9;struct KcMG{int pv0,pv1,pv2,pv3;KcVI v10;unsigned size9b9260()const;int&at9b81f0(unsigned);};struct KcVMG{int pv0,pv1,pv2,pv3;unsigned size9b9260()const;KcMG*&at9b81f0(unsigned);};extern KcVMG kc_d39f1c;extern KcMarkersHolder kc_d31640;void kc_machinePoints83dae0(KcMG*,KcVPos&);void kc_conduitPath83dbc0(KcMG*,KcVPos&);extern KcColor*kc_d29758,*kc_cfe5a0;struct KcHackDef{int i0;string name;int i20;int i24;};struct KcVHack{int pv0,pv1,pv2,pv3;KcHackDef*&at9b81f0(unsigned);};extern KcVHack kc_d21afc,kc_cf35b0;bool kc_containsPt9d0ce0(KcVPtsM&,KcPos);struct KcArr2{char pad[12];int*at9ceda0(int,int);};struct KcArrC{char pad[12];KcColor*at9d4730(int,int);KcColor*atPoint9d4700(const KcPos&);};struct KcBuild{int i0;char pad4[8];KcVPtsM vc;};struct KcVBuild{int pv0,pv1,pv2,pv3;unsigned size9b9260()const;KcBuild*&at9b81f0(unsigned);};extern KcVBuild kc_cf44b0;extern bool kc_cefaea;extern bool kc_cefae8,kc_cefadf,kc_cefade,kc_cefadd;extern KcColor*kc_d15d98,*kc_cf63b0;struct KcPD4;int kc_atten500500(KcPD4*,const KcPos&,const KcPos&);int kc_indexOfPoint9d53a0(KcVPos&,KcPos);struct KcArea2;extern KcArea2 kc_d35b84;extern void*kc_cefc48;bool kc_hasPtr4328a0();extern bool kc_cefc5c,kc_cefacd,kc_cefb10,kc_cefb12,kc_cefb13,kc_cefb19,kc_cefb1b,kc_cefb15;extern const float kc_c37108,kc_ba6be8,kc_ba6bec;extern KcColor*kc_d25f70;extern int kc_d1e1c8,kc_d1e1cc;string kc_pointToString40a4a0(const KcPos&);struct KcGlyph{int i0;int i4;};struct KcGlyphGrid{KcGlyph**atPoint9ced70(const KcPos&);};struct KcFontCell{int width9fcd80();int height9b8f00();KcColor*fore416f40();KcColor*back416f60();};struct KcFontX{KcGlyphGrid*u418570();KcFontCell*u417780(const KcPos&);};struct KcRoot{KcFontX*get4ab670();};extern KcRoot kc_d223f0;struct KcVStr{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b0650()const;string&at9b06a0(unsigned);};extern KcVStr kc_d2d4c8;struct KcDbgObj{char pad[0x24];int i24;int i28;};struct KcVDbg{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;KcDbgObj*&front9b7060();};extern KcVDbg kc_d3977c;extern KcVPos kc_d2d4f4;extern int kc_d28e2c,kc_d28e88;extern bool kc_d1d9e6,kc_d28e8c;extern const double kc_c37060;extern KcColor*kc_d32efc,*kc_d32968,*kc_d1e048;void kc_addUnique9d3020(KcVPos&,KcPos);struct KcSubCon;struct KcVSub{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9260()const;KcSubCon*&at9b81f0(unsigned);void clear9bac80();void push_back9b9d30(KcSubCon*const&);};struct KcLbl7f0{KcPos pos;string name;int i24;};struct KcV7f0{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9260()const;KcLbl7f0*&at9b81f0(unsigned);};extern KcColor*kc_d30264;extern const float kc_ba6ae0,kc_ba6ae4;extern unsigned kc_d1d9e8;extern KcPos kc_d1d9dc;struct KcVVP3{int pv0,pv1,pv2,pv3;unsigned size9b5100()const;KcVPtsM&at9b8070(unsigned);};struct KcVVP2{int pv0,pv1,pv2,pv3;KcVPtsM&at9b8070(unsigned);};struct KcColCol{KcColor c;char pad[3];};extern KcColCol kc_cfc1c8[],kc_cfc1cb[];extern KcColor*kc_cf0d3c,*kc_d28fd8,*kc_d230f4,*kc_d1f254,*kc_d2a2dc;extern const float kc_ba6af0,kc_ba6af4,kc_ba6ae8,kc_ba6aec,kc_ba6b74,kc_ba6b78,kc_ba6b7c,kc_ba6b80,kc_ba6ad4,kc_ba6ad8,kc_ba6adc,kc_c36fc8;extern const double kc_c36cf8;struct KcHI2{int id;KcItem*get9b65b0();int id9fcd80();};struct KcTurnObj{int u9b8f00();int type9b4350();int u45e590();KcHE u45e610();KcHI2 u45e650();};struct KcHQ{int id;KcTurnObj*get9b73b0();};struct KcVQ{int pv0,pv1,pv2,pv3;unsigned size9b9260()const;KcHQ&at9b81f0(unsigned);};struct KcTurnQ{int u672ad0(KcHE);KcVQ*u9c0790();};extern KcTurnQ kc_d225a0;extern KcColor*kc_d338bc;extern const double kc_c37100;double kc_maxDouble9e2c10(double,double);extern KcHI2 kc_d1da44;extern KcHE kc_d1da3c;extern unsigned kc_d1da40;struct KcBlastArea{int top44afb0();int h418900();int bottom9b6c30();int left9b6bf0();int right9b6c10();int&operator()(int,int);};struct KcBlastInfo{char pad[0x3c];int i3c;int i40;};extern KcCon*kc_cec11c,*kc_cec0f8;extern KcColor*kc_d2981c;extern const double kc_c37110;extern bool kc_d28e44,kc_d28e45,kc_d28e3d,kc_d28c8a;extern KcColor*kc_cf6b24,*kc_d22130,*kc_d1dae8,*kc_d338c8,*kc_cf766c,*kc_cf13fc,*kc_d21944;extern const float kc_c37120,kc_c3711c,kc_c36fbc,kc_c36fc0,kc_c37118,kc_c370ac,kc_c37038;struct KcPD{bool u77f260(int);bool hasCompanion780790();bool u46dd50();};extern KcPD kc_cf45d8;bool kc_isOdd406340(int);struct KcSpot{KcPos p;KcPos off;unsigned t10;int last;int i18;bool b1c;char pad1d[3];int i20;};struct KcVSpot{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9260()const;KcSpot*&at9b81f0(unsigned);};void kc_clearObjects9d0670(KcVSpot&);extern KcColor*kc_cf27e8;struct KcVPosPtrs{int pv0,pv1,pv2,pv3;KcVPosPtrs();~KcVPosPtrs();void push_back9b9280(KcVPos*&&);unsigned size9b9260()const;KcVPos*&at9b81f0(unsigned);};extern KcColor*kc_d2ea1c,*kc_cefdcc;struct KcVColor{int pv0,pv1,pv2,pv3;KcVColor();~KcVColor();void push_back9b3c80(KcColor&&);KcColor&at9b3e50(unsigned);void push_back9b3e70(const KcColor&);};extern KcColor*kc_d32dfc,*kc_cfbec8;struct KcVVPts2{int pv0,pv1,pv2,pv3;unsigned size9b5100()const;KcVPtsM&at9b8070(unsigned);void clear9b58f0();};struct KcVInts{int pv0,pv1,pv2,pv3;int&at9b81f0(unsigned);};struct KcVVI{int pv0,pv1,pv2,pv3;KcVInts&at9b8070(unsigned);void clear9b8eb0();};extern KcColor*kc_d316f4;extern const float kc_c36f20;extern int kc_d28ea0;extern const double kc_c36f90,kc_c36cb0;extern const float kc_c37124;void kc_line40ff30(const KcPos&,const KcPos&,KcVPos&);void kc_fillInts9e2be0(int*,int,int);
struct KcCellBuf{void applyFilters417230();};struct KcGrid7a40{KcCellBuf*at9cdf20(int,int);void getRect9b4430(const KcPos&,int,KcArea2&);void getBounds9b7a40(const KcPos&,int,KcPos&,KcPos&);};struct KcRange2{int lo,hi;KcRange2();};bool kc_between9daf80(int,int,int);
struct KcE460{bool b0;char pad1[3];KcVPos v4;unsigned t14;};struct KcV460{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9260()const;KcE460*&at9b81f0(unsigned);};void kc_delStep9e2b60(KcV460&,unsigned&);
struct KcNoise{char pad[0x20];float sample4217d0(int,int);void update4218e0();float sample421770(const KcPos&);};extern KcColor*kc_d33d88,*kc_cfd448;extern const float kc_c37128;extern const double kc_c36e78;
struct KcE420{int type;KcVPos v4;};struct KcV420{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9260()const;KcE420*&at9b81f0(unsigned);void clear9bac80();};
bool kc_anyPositive9d54c0(KcVI&);extern KcColor*kc_cfd4cc,*kc_d21b44,*kc_d25f60;
struct KcVA{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b5100()const;KcArea2&at9b8070(unsigned);void clear9b4710();};struct KcVI404{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;int&at9b81f0(unsigned);int&back9b6540();void clear9bac80();};
struct KcFovCb{};extern KcFovCb kc_d2f210;struct KcFov{int u40ca20(const KcPos&,int,KcFovCb*,int);bool findPath40c9a0(const KcPos&,const KcPos&,void*,int,KcVPos&);};extern KcFov kc_cfe568;void kc_clearDijkstra4faf40();extern KcVPos kc_d15e58;
void kc_eraseRange9d53f0(KcVPos&,int,int);extern KcColor*kc_d35be0;extern const float kc_c36fec;
struct KcE124{KcPos pos;unsigned t8;bool bc;};struct KcV124{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9260()const;KcE124*&at9b81f0(unsigned);};
struct KcE31c{KcHE h0;KcPos p4;unsigned tc;};struct KcV31c{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9260()const;KcE31c*&at9b81f0(unsigned);};
struct KcE32c{KcPos pos;int i8;bool bc;unsigned t10;};struct KcV32c{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9260()const;KcE32c*&at9b81f0(unsigned);};
struct KcE35c{KcPos pos;int i8;unsigned tc;};struct KcV35c{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9260()const;KcE35c*&at9b81f0(unsigned);};
void kc_delStep9de640(KcV124&,unsigned&);void kc_delStep9de640(KcV31c&,unsigned&);void kc_delStep9de640(KcV32c&,unsigned&);void kc_delStep9de640(KcV35c&,unsigned&);
extern KcColor*kc_cf273c,*kc_d22fb8,*kc_d306ac,*kc_d2f34c,*kc_d20438;
extern KcColor*kc_d33d8c;
extern bool kc_d28e69,kc_d28e83;extern KcColor*kc_d29014;
extern KcVPos kc_d31da4,kc_d2d28c,kc_d2a8a0,kc_d01bd8;extern int kc_cf4a70,kc_cf4a74,kc_cf4a90,kc_cf4a94,kc_cf4718;extern KcColor*kc_cf45d0,*kc_d2d288,*kc_cf1b0c,*kc_cefcf8,*kc_d01a44;extern const float kc_ba6b58,kc_ba6b54;extern const double kc_c36f30;
double kc_angle40a680(const KcPos&,const KcPos&);bool kc_angleInArc4065d0(int,int,int);
struct KcO6478{int type;KcHE h4;bool u45e820();};struct KcVO6478{int pv0,pv1,pv2,pv3;unsigned size9b9260()const;KcO6478*&at9b81f0(unsigned);};extern KcVO6478 kc_cf6478;extern KcHE kc_cf64fc;
struct KcBeam{char pad[0x10];KcVPos v10;KcVI v20;unsigned t30;};struct KcVBeam{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;unsigned size9b9260()const;KcBeam*&at9b81f0(unsigned);};
struct KcFxObj{virtual void v0();virtual void v1();virtual void v2();virtual void v3();};struct KcHFx{int id;KcFxObj*operator->()const;};struct KcVHFx{int pv0,pv1,pv2,pv3;unsigned size9b9260()const;KcHFx&at9b81f0(unsigned);};
struct KcFxMgr{void u5088e0();};extern KcFxMgr*kc_cefc50;struct KcTeamB{char pad0[8];int i8;bool check7abf80();};extern KcTeamB*kc_cf4ac8;
void kc_eraseStep9d6440(KcVEnt&,unsigned&);extern KcVPos kc_d3862c;extern bool kc_cf4a00;extern int kc_d255ac;
extern KcColor*kc_cf6ed4,*kc_d22fcc,*kc_d2d1d4,*kc_cf0c8c,*kc_cf44ac,*kc_d32970;extern const float kc_c37138,kc_c36e30,kc_ba6b6c,kc_ba6b70,kc_ba6b50;extern const double kc_c37130;
struct KcVHX{int pv0,pv1,pv2,pv3;KcVHX();~KcVHX();bool empty9b86e0()const;unsigned size9b9260()const;KcHE&at9b81f0(unsigned);};bool kc_addUnique9d30e0(KcVHX&,KcHE);
struct KcVVP{int pv0,pv1,pv2,pv3;KcVVP();~KcVVP();void push_back9b5610(KcVPos&&);KcVPos&at9b8070(unsigned);};struct KcBox4{int x1,y1,x2,y2;KcBox4(int,int,int,int);};
struct KcSys94{bool u41a6e0();KcPos topLeft40a970();};extern KcSys94*kc_cefa94;extern KcColor*kc_d02da4,*kc_cefd50,*kc_cf63b4;extern const float kc_ba6af8,kc_ba6afc;
struct KcVF{int pv0,pv1,pv2,pv3;bool empty9b86e0()const;float&front9b7060();unsigned size9b9260()const;float&at9b81f0(unsigned);};struct KcUI84{char pad[0x8c];KcVF v8c;};extern KcUI84*kc_cec084;
struct KcEngine;struct KcEffect{void init50de10(KcEngine*,int,const KcPos&,const KcColor&,int,int,int);};extern KcEngine*kc_cefc64;extern KcColor kc_cfbec0;
void kc_lookup9d45a0(const string&,int&);string kc_intToString4051f0(int);string&kc_padRight4080d0(string&,int,char);extern int kc_caf128,kc_caf12c;extern bool kc_d28d15;extern KcColor*kc_d1ecd4,*kc_d20cfc;extern const float kc_c3713c;int kc_distance406480(int,int,int,int);
extern bool kc_d28d16,kc_d28e6a;extern KcCellDef*caveinWallTerrain;extern KcColor*kc_d21e58,*kc_d2ae2c,*kc_d30424;extern const float kc_ba6b00,kc_ba6b04;extern const double kc_c36f58,kc_c36cc0;
struct KcTrail{KcPos pos;unsigned t8;};struct KcVTrail{int pv0,pv1,pv2,pv3;unsigned size9b9260()const;KcTrail*&at9b81f0(unsigned);};void kc_deleteObject9d8f20(KcVTrail&,int);
struct KcSquad{KcVEnt&u416f40();};struct KcHS{int id;KcSquad*operator->()const;};struct KcVHS{int pv0,pv1,pv2,pv3;unsigned size9b9260()const;KcHS&at9b81f0(unsigned);};
struct KcSq{KcHE h0;KcHE h4;unsigned t8;};struct KcVSq{int pv0,pv1,pv2,pv3;unsigned size9b9260()const;KcSq*&at9b81f0(unsigned);};
void kc_sound4541b0(int,int,int);
extern int kc_d28d40,kc_cefa78;extern KcColor*kc_d01c00,*kc_cefd54,*kc_d216f0,*kc_cf44c4;extern const float kc_ba6bf0;extern const double kc_c36cf8;
struct KcZone{char pad[8];int i8;char padc;bool bd;void u6c16d0(string);};
struct KcMap{char pad0[0x34];int i34;char pad38[0x4c-0x38];KcVHS v4c;char pad5c[0xf4-0x5c];KcVPos vf4;char pad104[0x1d8-0x104];bool b1d8;char pad1d9[0x3d4-0x1d9];KcGridI*p3d4;char pad3d8[0x538-0x3d8];KcVPos v538;char pad548[0x594-0x548];KcVEnt v594;char pad5a4[0x61c-0x5a4];KcVEnt v61c;KcVEnt v62c;char pad63c[0x66c-0x63c];KcHE player;char pad670[0x674-0x670];KcGridC known;char pad678[0x690-0x678];KcGridI a690;char pad694[0x69c-0x694];KcGridI a69c;char pad6a0[0x6d8-0x6a0];KcVGrid v6d8;KcGridI2*p6e8;char pad6ec[0x710-0x6ec];KcVSet v710;KcVSet v720;KcVSet v730;KcGridS14 a740;char pad744[0x74c-0x744];int i74c;char pad750[0x7c4-0x750];KcGridS34 a7c4;char pad7c8[0x7f0-0x7c8];KcV7f0 v7f0;KcVBeam v800;char pad810[0x81c-0x810];KcVEnt v81c;char pad82c[0xa30-0x82c];KcVHFx va30;char pada40[0xb80-0xa40];KcGridI*pb80;char padb84[0xbb4-0xb84];int xbb4;
 bool contains9e2970(KcVSet*,KcHE);bool contains9e2970(KcVSet*,KcHI);bool contains9e2970(KcVSet*,KcHP);void add9e29b0(KcVSet*,KcHE);void add9e29b0(KcVSet*,KcHI);void add9e29b0(KcVSet*,KcHP);
 KcMarkersHolder*u463be0();KcGridX*u463e70();KcHE getPlayer4630f0();int getTurn464270();KcVPts*u463a70();KcVRect*u4646b0();KcHG u463890(int);int getMaxItemRange71c930();bool u465200(const KcPos&,const KcPos&);KcVPts*u464060();bool isVisible463190(int,int);bool isVisible4631c0(const KcPos&);KcPos*u464610();bool isReachable465230(int,KcPos&,KcPos&);int u715fe0(int,const KcPos&,int,bool);int value465660(KcHE);bool u7178d0(KcHE,const KcPos&,char*,KcPos&,char*,int);int u4638e0(int);bool u4631f0(KcHE);KcVPos&u465ad0();KcVPos&u465af0();KcVEnt&u4644b0();int u464000();int u464020();int u717d60();int u717dd0();bool u7168e0(const KcPos&,const KcPos&,KcEntity*,KcVPos&);KcVI&u465a90();KcVVP3&u465ab0();KcHE getEntity463110();int u4636d0();int u463710();KcBlastArea*u465a30();bool u463380(int,int);KcVEnt&u4635a0();KcV420&u463df0();void u734d60(const KcPos&);void u4647a0(const KcPos&,int);void u4647d0(const KcPos&);KcZone*getZone462e30(const KcPos&);void announce71dd30(int);bool u715a70();KcHE u464040();bool u463e90(const KcPos&);KcVSq&u4643f0();void u7170a0(KcHE,const KcPos&,KcVPos&,KcVInt&,KcVInt&,KcPos&,int,int,int,int);};
extern KcMap*kc_cefc4c;
struct KcCfg{char pad0[0xd4];int d4;int d8;};extern KcCfg*kc_cefb9c;
struct KcKeys{bool isDown439510(int);};extern KcKeys kc_d338cc;
struct KcBubble{void bubble8758d0(bool);};extern KcBubble*kc_cec058;
struct KcLogMsgs{void scrollToEnd7b4f10();};extern KcLogMsgs*kc_cec0b4;
struct KcGM{void u78d700(int,int);void showOnce793450(int,bool,int,int,int);};extern KcGM*kc_cefaa8;
struct KcStats{bool add4729d0(unsigned,int,string,int);};extern KcStats kc_d2c658;
struct KcVecI{int&at9b81f0(unsigned);};extern KcVecI kc_cf4830;
bool kc_showMessage5111e0(int,const string*,const string*,const string*,KcHE,KcHE,int,int);
float kc_pulse4371a0(float,float,int,int);
float kc_pulse437200(float,float,int,int);
bool kc_blink437320(int);bool kc_inRange9e2b30(unsigned,unsigned,unsigned);
int kc_maxInt9cdb60(int,int);
int kc_distance40a3f0(const KcPos&,const KcPos&);
bool kc_containsEntity9d31e0(KcVHE*,KcHE);
int kc_indexOfEntity9d3110(KcVHE*,KcHE);
void kc_eraseAt9da940(KcVHE&,int);
void kc_removeAt9de6f0(KcVI&,int);
void kc_removeAt9de6f0(KcVU&,int);
float sin(float);
extern unsigned kc_caed20;
extern bool kc_d28d30,kc_d28d39,kc_d28d3a,kc_cefb3c,kc_d1da70;
extern int kc_cf27f4,kc_cf27f8,kc_cec050,kc_caf164,kc_d1da7c,kc_d28f9c,kc_cf462c,caveinInstabilityIncrease;struct KcLoc{int idx;};extern KcLoc*kc_cf4700;extern unsigned kc_d1da74;extern bool kc_cefafc,kc_cefafe,kc_cefb08,kc_d28e81,kc_cec14e,kc_cec14d;extern KcPos kc_cf69c4;
extern KcColor*kc_d1f3a4,*kc_d01d4c,*kc_cfe674,*kc_cf27fc,*kc_d22854,*kc_d37a8c,*kc_d1e1c4,*kc_d35c3c,*kc_d3842c,*kc_d15dac,*kc_d21f58,*kc_d01bd4,*kc_cf1f24,*kc_d1e054,*kc_d25f64,*kc_d21af8,*kc_d2585c,*kc_cf1604,*kc_d31578,*kc_d386cc,*kc_d201bc,*kc_d3872c,*kc_d226c8,*kc_cf44c0,*kc_d31bfc,*kc_d316fc,*kc_d2a89c,*kc_cfe5a4,*kc_d29784,*kc_cf281c,*kc_cf270c,*kc_d2f1a8,*kc_d16310,*kc_d39580;
extern KcColor*kc_d2175c,*kc_d33d84,*kc_cf65d4,*kc_d32cf0,*kc_d21f54,*kc_d29d90,*kc_d223e4,*kc_d1629c,*kc_d35bbc,*kc_d386c8,*kc_d20618,*kc_d38644,*kc_d201c4,*kc_d2b284,*kc_cfabbc,*kc_d31db4,*kc_d38474,*kc_d3a20c,*kc_d221b0,*kc_d38544,*kc_cfc180,*kc_d20b70,*kc_d204ac,*kc_d230f0;extern KcColor kc_d3296c,kc_d29804,kc_d329a4[];
extern char kc_d2e20c;
extern const double kc_c37068,kc_c36e68,kc_c36cc8,kc_c36db0,kc_c36fd8,kc_c36df8,kc_c36e08,kc_c36e00,kc_c37150,kc_c36ce8,kc_c36cd0,kc_c36ca0,kc_c36c98,kc_c36cb8,kc_c36de8;
extern const float kc_c36dd0,kc_c36eb4,kc_c36f8c,kc_c37158,kc_ba6ba4,kc_ba6ba8,kc_ba6bac,kc_ba6bb0,kc_ba6bb4,kc_ba6bb8,kc_ba6bbc,kc_ba6bf4,kc_ba6bf8,kc_ba6bfc,kc_ba6c00,kc_ba6c04,kc_ba6c08,kc_ba6c0c,kc_ba6b84,kc_ba6b88,kc_ba6b8c,kc_ba6b90,kc_c36edc,kc_ba6b14,kc_ba6b18,kc_ba6b1c,kc_ba6b5c,kc_ba6b60,kc_c36ecc,kc_c36f88,kc_c3714c,kc_ba6b3c,kc_ba6b40,kc_ba6b34,kc_ba6b38,kc_ba6b50,kc_ba6b4c,kc_c37148,kc_ba6b64,kc_ba6b68,kc_ba6b20,kc_ba6b24,kc_ba6b28,kc_ba6b2c,kc_ba6b30,kc_ba6b08,kc_ba6b0c,kc_ba6b10,kc_ba6b94,kc_ba6b98,kc_ba6bc0,kc_ba6bc4,kc_ba6bc8,kc_ba6bcc,kc_ba6bd0,kc_ba6bd4,kc_ba6bd8,kc_ba6bdc,kc_ba6be0,kc_c37144,kc_ba6be4,kc_c36ec8,kc_c36f50,kc_c37140,kc_ba6b44,kc_ba6b48;
struct KcCon{virtual~KcCon();int getHeight4174c0();int width44b0d0();void copy429fe0(KcSubCon*,const KcPos&,KcArea&);void removeSubconsole428b20(KcCon*);void putCell4181a0(int,int,void*);bool isHidden();void clear();void setFore(KcColor);void setBack(KcColor);void setFore417f80(int,int,KcColor);void setBack417fc0(int,int,KcColor,bool);void setChar417f50(int,int,int);KcColor getBack(int,int);KcColor getFore(int,int);void putChar418110(int,int,int,KcColor);void putChar418150(int,int,int,KcColor,KcColor,bool);void setBackRow429c20(int,int,int,KcColor);void setForeRow429a30(int,int,int,KcColor);void print4181d0(int,int,const string&);void setBgColor418410(KcColor);void setFgColor4183d0(KcColor);void setPos417a90(int,int);void printAligned418220(int,int,int,const string&);void resetBack418450();int getChar(int,int);};
struct KcCon2:KcCon{bool u48f210();bool u48f0a0();bool u48f0c0();int u48f100();KcVEnt&u48f0e0();KcHE u48f120();};struct KcCon3{int u48e040();int u48c360();};extern KcCon3*kc_cec130;extern KcCon2*kc_cec0c8;
struct KcCMap;struct KcModeLabel:KcCon{char pad4[0x6c-4];int i6c;KcModeLabel(KcCMap*,int);void u7f48e0();};struct KcCon4{bool u48f8b0();};extern KcCon4*kc_cec0cc;struct KcPanel{int getHighlighter4ab670();bool u4ab570();bool u4ab4a0();bool u4ab690();};extern KcPanel*kc_cec090,*kc_cec094,*kc_cec098,*kc_cec09c,*kc_cec0a0;extern KcCon*kc_cec0f4;
#define LOOPXY for(int x=from.x,sx=kc_maxInt9cdb60(scroll.x,0);x<=to.x&&sx<kc_cf27f4;x++,sx++)for(int y=from.y,sy=kc_maxInt9cdb60(scroll.y,0);y<=to.y&&sy<kc_cf27f8;y++,sy++)
#define LOOPYX for(int y=from.y,sy=kc_maxInt9cdb60(scroll.y,0);y<=to.y&&sy<kc_cf27f8;y++,sy++)for(int x=from.x,sx=kc_maxInt9cdb60(scroll.x,0);x<=to.x&&sx<kc_cf27f4;x++,sx++)
#define BG(x,y) (kc_cefb3c&&getBack(x,y)==*kc_cfe674?KcColor(kc_d29804):getBack(x,y))
#define BGP(p) (kc_cefb3c&&getBack417750(p)==*kc_cfe674?KcColor(kc_d29804):getBack417750(p))
#define CELL(x,y) (*kc_cfd44c.at9ceda0(x,y))
struct KcSubCon:KcCon{KcSubCon(KcCon*,int,int,int,int,int,bool,int);void animate48c3f0(string);void animate48c3c0(int);char pad4[0x64-4];KcEngine*engine64;char pad68[0x6c-0x68];void*cell4176e0(int,int);};
struct KcCMap:KcCon{char pad4[0x64-4];KcNoiseHost*p64;char pad68[4];KcPos scroll;KcHE h74;int i78;KcVVPts v78;int i8c;unsigned t90;int i94;KcVPos v98;KcVU va8;KcVI vb8;KcSubCon*pc8;char padcc[0xd0-0xcc];bool bd0;char padd1[0xd4-0xd1];unsigned td4;bool bd8;char padd9[0xdc-0xd9];unsigned tdc;KcSubCon*pe0;KcPos pe4;bool bec;char paded[0xf0-0xed];unsigned tf0;KcHE hf4;unsigned tf8;bool bfc;char padfd[0x100-0xfd];KcVPos v100;char pad110[0x124-0x110];KcV124 v124;int i134;KcVPos v138;int i148;KcPos p14c;KcPos p154;unsigned t15c;int i160;int i164;KcVVPts2 v168;KcVVI v178;KcVA v188;KcVU v198;KcVSpot v1a8;unsigned t1b8,t1bc,t1c0;char pad1c4[0x1d8-0x1c4];KcVLabel v1d8;char pad1e8[0x1f0-0x1e8];unsigned t1f0;int i1f4;char pad1f8[0x214-0x1f8];unsigned i214;KcVEnt v218;unsigned t228;KcVHE v22c;KcVI v23c;KcVU v24c;KcVHE v25c;KcVU v26c;KcVVP2 v27c;KcVI v28c;KcVMark v29c;KcVMark v2ac;KcVE14 v2bc;KcVE12 v2cc;KcVHT v2dc;KcVPos v2ec;KcVI v2fc;KcVI v30c;KcV31c v31c;KcV32c v32c;KcVE16 v33c;KcVBlast v34c;KcV35c v35c;char pad36c[0x374-0x36c];int i374;unsigned t378;bool b37c;bool b37d;char pad37e[0x380-0x37e];unsigned t380;char pad384[0x38c-0x384];KcPos p38c;unsigned t394;unsigned t398;KcPos p39c;int i3a4;KcVPos v3a8;KcVU v3b8;KcVPos v3c8;int i3d8;unsigned t3dc;bool b3e0;char pad3e1[3];KcVA v3e4;KcVPos v3f4;KcVI404 v404;int i414;int i418;unsigned t41c;KcV420 v420;KcVI v430;KcVI v440;unsigned t450;unsigned t454;KcHE h458;unsigned t45c;KcV460 v460;KcNoise n470;KcVPos v490;KcVU v4a0;unsigned t4b0;KcVSub v4b4;bool b4c4;char pad4c5[3];KcPos p4c8;char pad4d0[0x4d8-0x4d0];bool b4d8;char pad4d9[3];KcVPos v4dc;KcVI v4ec;KcVI v4fc;KcVA v50c;char pad51c[4];KcVI v520;KcVPos v530;char pad540[4];KcVPos v544;int i554;KcSubCon*p558;KcHE h55c;unsigned t560;char pad564[0x58c-0x564];KcPos p58c;unsigned t594;char pad598[0x59c-0x598];KcPos p59c;unsigned t5a4;char pad5a8[0x5ac-0x5a8];KcHP h5ac;unsigned t5b0;char pad5b4[0x5c4-0x5b4];KcHE h5c4;unsigned t5c8;unsigned t5cc;char pad5d0[0x5d4-0x5d0];unsigned t5d4;char pad5d8[0x5f0-0x5d8];unsigned t5f0;char pad5f4[0x600-0x5f4];KcVEnt v600;char pad610[0x680-0x610];int i680;int i684;char pad688[0x6b0-0x688];KcBlastInfo*p6b0;char pad6b4[4];KcPos p6b8;char pad6c0[0x6d0-0x6c0];KcBlastArea a6d0;char pad6d1[0x6fc-0x6d1];int i6fc;char pad700[0x708-0x700];KcVVP3 v708;char pad718[0x7a8-0x718];KcModeLabel*p7a8;char pad7ac[0x7f8-0x7ac];bool b7f8;char pad7f9;bool b7fa;char pad7fb;KcArr2 a7fc;KcArr2 a808;KcArrC a814;KcArrC a820;KcArrC a82c;bool b838;bool b839;bool b83a;bool b83b;bool b83c;bool b83d;bool b83e;bool b83f;KcVSub v840;bool b850;bool b851;char pad852[2];KcVSub v854;KcSubCon*p864;unsigned t868;int i86c;bool b870;char pad871[3];KcVSub v874;bool b884;char pad885[3];KcVSub v888;bool b898;char pad899[0x8ac-0x899];bool b8ac;bool b8ad;bool b8ae;bool b8af;char pad8b0;bool b8b1;char pad8b2[2];KcSubCon*p8b4;bool b8b8;char pad8b9[3];KcSubCon*p8bc;unsigned t8c0;
 void render();void u819cb0();void u429ea0();void u86e310();KcPos clampToView83d9b0(const KcPos&);bool hasAnyLabel49b490();void u8680b0();bool u49aa60();bool inBounds417360(int,int);bool inBounds4173d0(const KcPos&);KcColor getBack417750(const KcPos&);KcColor getFore417720(const KcPos&);int u806420(KcHE,KcHI*,int*);bool u8052f0(const KcPos&);bool pick805190(KcPos*);bool u8050a0();void view8051f0(KcPos*,KcPos*);void label810270(int,KcHE,bool,int);void items8119c0(KcHI,int,int,int);void label813050(bool,int,KcHP,bool,int,int,int);void u808510(const KcPos&,int,KcVPos&);void labelAccess80e3a0(int,const KcPos&);bool hasPosLabel49b220(int,const KcPos&);bool hasEntLabel49b1a0(int,KcHE);KcGrid7a40*buf4184d0();};
void KcCMap::render(){
 if(isHidden())return;
 if(i374!=5&&kc_caed20>=t378){
  i374=5;
  do{if(kc_showMessage5111e0(0x208,0,0,0,kc_cefc4c->player,KcHE(),0,0))kc_cec058->bubble8758d0(true);kc_cec0b4->scrollToEnd7b4f10();}while(0);
  if(b37c&&!kc_d28d30)kc_cefaa8->u78d700(0,0);
 }
 clear();
 setFore(*kc_d1f3a4);
 setBack(*kc_d01d4c);
 KcPos a2;
 bool a0=pick805190(&a2);
 KcHE a1=kc_cefc4c->player;
 KcGridC*aH=&kc_cefc4c->known;
 KcGridI*aVisible=&kc_cefc4c->a69c;
 KcGridI2*a6=kc_cefc4c->p6e8;
 int aA=kc_cefc4c->p6e8->i0c;
 KcGridS14*b5=&kc_cefc4c->a740;
 int a8=kc_cefc4c->i74c;
 KcGridS34*e5=&kc_cefc4c->a7c4;
 bool aC=false;
 if(kc_d28d39&&kc_caed20>=t1b8){t1b8=kc_caed20+750;aC=true;}
 bool tick2=false;
 if(kc_d28d39&&kc_caed20>=t1bc){t1bc=kc_caed20+1750;tick2=true;}
 bool tick3=false;
 if(kc_d28d3a&&kc_caed20>=t1c0){t1c0=kc_caed20+1000;tick3=true;}
 float fade=0;
 int fadeMode=0;
 if(b37d){
  if(kc_d338cc.isDown439510(0x60)||!u8050a0()){
   if(kc_caed20<t380+400)fadeMode=1;else fadeMode=2;
  }else{
   b37d=false;
   if(kc_caed20<t380+400){
    float v=1.0f-1.0f*sin((float)((kc_caed20-t380)/kc_c37068*kc_c36e68));
    t380=kc_caed20;
    fade=v;
   }else{t380=kc_caed20;fadeMode=1;}
  }
 }else{
  if(kc_d338cc.isDown439510(0x60)||!u8050a0()){b37d=true;t380=kc_caed20;fadeMode=1;}
  else if(kc_caed20<t380+400)fadeMode=1;
 }
 if(fadeMode!=0){
  switch(fadeMode){
  case 1:
   fade=1.0f*sin((float)((kc_caed20-t380)/kc_c37068*kc_c36e68));
   if(fade==0)fade=kc_c36dd0;
   break;
  case 2:
   fade=1;
   break;
  }
 }
 float aG=kc_cefb3c?kc_c36cc8:kc_c36db0;
 int bN=kc_d28d30?kc_cefb9c->d8:kc_cefb9c->d4;
 KcHI held=a1->item5d2380(0xd3);
 bool heldActive=held.isValid()?held->u458220():false;
 int aB=kc_cfd44c.atPoint9ced70(a1->getPosition())[0]->getItem().isValid()&&kc_cfd44c.atPoint9ced70(a1->getPosition())[0]->getItem()->kind457f90()==0xce?kc_cfd44c.atPoint9ced70(a1->getPosition())[0]->getItem()->range457fb0():0;
 KcHE a7;
 KcColor a_;
 KcColor c6;
 KcPos from3;
 KcPos toN;
 KcCell*cell;float fp;KcColor*aI;int a9;KcVEnt*g_;int aT;
 view8051f0(&from3,&toN);
 for(int xC=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);xC<=toN.x&&sx<kc_cf27f4;xC++,sx++){
  for(int y=from3.y,b9=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&b9<kc_cf27f8;y++,b9++){
   if(aH&&!*aH->at9cec50(xC,y)){
    if(b5->at9cdf20(xC,y)->a==a8){
     if(b5->at9cdf20(xC,y)->isActive72ec10()){b5->at9cdf20(xC,y)->a=0;setFore417f80(sx,b9,*kc_cfe674);}
     else{setChar417f50(sx,b9,b5->at9cdf20(xC,y)->getValue461cf0(1));setFore417f80(sx,b9,b5->at9cdf20(xC,y)->getColor72eb70());}
    }else setFore417f80(sx,b9,*kc_cfe674);
    setBack417fc0(sx,b9,*kc_cfe674,true);
    goto next1;
   }
   cell=*kc_cfd44c.at9ceda0(xC,y);
   setBack417fc0(sx,b9,kc_d3296c,true);
   if(*aVisible->at9ceda0(xC,y)!=0){
    if(cell->getEntity().isValid()&&cell->getEntity()->u5cd3e0()){
     a7=cell->getEntity();
     setChar417f50(sx,b9,a7->getAscii5c7a10(KcPos(xC,y)));
     setFore417f80(sx,b9,a7->color5c7630());
     if(a7->u45abb0())setFore417f80(sx,b9,KcColor::lerp(getBack(sx,b9),*kc_cf27fc,kc_pulse4371a0(kc_ba6ba4,kc_ba6ba8,1000,kc_caed20-a7->u459300())));
     if(a7->u45ac00())setFore417f80(sx,b9,getFore(sx,b9)*kc_ba6bac);
     if(a7->u45aff0())setBack417fc0(sx,b9,KcColor::addAlpha(getBack(sx,b9),*kc_d22854,kc_pulse4371a0(kc_ba6c08,kc_ba6c0c,1000,0)),true);
     if(!v29c.empty9b86e0()){
      for(unsigned i=0;i<v29c.size9b9a50();i++){
       if(v29c.at9e7c10(i).e==a7){setFore417f80(sx,b9,KcColor::lerp(getFore(sx,b9),*kc_d37a8c,kc_pulse437200(kc_ba6bb0,kc_ba6bb4,200,v29c.at9e7c10(i).t)));break;}
      }
     }
     if(!v2ac.empty9b86e0()){
      for(unsigned i=0;i<v2ac.size9b9a50();i++){
       if(v2ac.at9e7c10(i).e==a7){setBack417fc0(sx,b9,KcColor::lerp(getBack(sx,b9),*kc_d1e1c4,kc_pulse437200(kc_ba6bb8,kc_ba6bbc,200,v2ac.at9e7c10(i).t)),true);break;}
      }
     }
     if(!a7->isPlayer()){
      if(aC&&a7->rel5c7fc0(kc_cefc4c->player)!=1&&a7->ai45b590()->type9b4350()>=2&&!kc_cefc4c->contains9e2970(&kc_cefc4c->v710,a7)&&kc_cec050==0){
       label810270(a7->rel5c7fc0(kc_cefc4c->player),a7,a7->rel5c7fc0(kc_cefc4c->player)==2,0);
       v1d8.back9b6540()->b30=true;
       kc_cefc4c->add9e29b0(&kc_cefc4c->v710,a7);
      }
      if(!kc_cefc4c->u463be0()->at9b8070(4).empty9b86e0()&&a7->getGroup()->type9b4350()==3&&kc_cefc4c->u715fe0(4,KcPos(xC,y),10,true))
       setBack417fc0(sx,b9,KcColor::addAlpha(getBack(sx,b9),*kc_d35c3c,kc_pulse4371a0(kc_ba6bf8,kc_ba6bfc,1000,0)),true);
      else if(a7->getGroup()->type9b4350()==3){
       for(unsigned i=0;i<kc_cefc4c->v62c.size9b9260();i++){
        if(kc_cefc4c->v62c.at9b81f0(i).operator->()&&kc_distance40a3f0(kc_cefc4c->v62c.at9b81f0(i)->getPosition(),cell->u45d1a0())<=3){
         setBack417fc0(sx,b9,KcColor::addAlpha(getBack(sx,b9),*kc_d35c3c,kc_pulse4371a0(kc_ba6bf8,kc_ba6bfc,1000,0)),true);
         goto marked;
        }
       }
       for(unsigned i=0;i<kc_cefc4c->v61c.size9b9260();i++){
        if(kc_cefc4c->v61c.at9b81f0(i).operator->()&&kc_distance40a3f0(kc_cefc4c->v61c.at9b81f0(i)->getPosition(),cell->u45d1a0())<=3){
         setBack417fc0(sx,b9,KcColor::addAlpha(getBack(sx,b9),*kc_d3842c,kc_pulse4371a0(kc_ba6c00,kc_ba6c04,1000,0)),true);
         goto marked;
        }
       }
      }
      marked:
      bool dimmable=true;
      if(*a7->ai45b590()->u459010()>=1){
       unsigned&t=*a7->ai45b590()->u459010();
       if(t==1){t=kc_caed20;kc_d2c658.add4729d0(0x243,1,"",-1);}
       if(kc_caed20>=t+1900)t=0;
       else if(kc_blink437320(250))putChar418110(sx,b9,'!',*kc_d15dac);
      }else if(!v22c.empty9b86e0()&&kc_containsEntity9d31e0(&v22c,a7)){
       int idx=kc_indexOfEntity9d3110(&v22c,a7);
       if(kc_caed20>=v24c.at9b81f0(idx)+1900){kc_eraseAt9da940(v22c,idx);kc_removeAt9de6f0(v23c,idx);kc_removeAt9de6f0(v24c,idx);}
       else if(kc_blink437320(250)){
        switch(v23c.at9b81f0(idx)){
        case 1:case 2:putChar418110(sx,b9,'X',*kc_d21f58);break;
        case 3:putChar418110(sx,b9,'M',*kc_d01bd4);break;
        case 4:putChar418110(sx,b9,'X',*kc_cf1f24);break;
        }
       }
      }else if(kc_cf4700!=0&&!v25c.empty9b86e0()&&kc_containsEntity9d31e0(&v25c,a7)){
       int idx=kc_indexOfEntity9d3110(&v25c,a7);
       if(kc_caed20>=v26c.at9b81f0(idx)+900){kc_eraseAt9da940(v25c,idx);kc_removeAt9de6f0(v26c,idx);}
       else if(kc_blink437320(250))putChar418110(sx,b9,'?',*kc_d1e054);
      }else if(*a7->u4aec60()!=0){
       kc_cefaa8->showOnce793450(0x3e,true,0,0,0);
       unsigned&t=*a7->u4aec60();
       if(t==1)t=kc_caed20;
       bool known=!(kc_cefc4c->value465660(a7)-1);
       if(!known&&kc_caed20>=t+1900)t=0;
       else if(kc_blink437320(250)){putChar418110(sx,b9,'?',known?*kc_d25f64:*kc_d21af8);dimmable=false;}
       if(!known)kc_cefaa8->showOnce793450(0x3f,true,0,0,0);
      }else if(a7->getFaction()==0x48&&kc_blink437320(250))setFore417f80(sx,b9,kc_d329a4[a7->u45acb0(0x28)]);
      if(a7->u5d52b0()&&dimmable)setFore417f80(sx,b9,getFore(sx,b9)*kc_c36eb4);
      if(a7->ai45b590()->u581a00(0)&&kc_blink437320(500))setFore417f80(sx,b9,*kc_cfe674);
     }
    }else{
     if(b5->at9cdf20(xC,y)->a==a8){
      if(b5->at9cdf20(xC,y)->isActive72ec10()||!b5->at9cdf20(xC,y)->h8.operator->()||*aVisible->at9ceda0(xC,y)!=0)b5->at9cdf20(xC,y)->a=0;
      else{setChar417f50(sx,b9,b5->at9cdf20(xC,y)->getValue461cf0(1));setFore417f80(sx,b9,b5->at9cdf20(xC,y)->getColor72eb70());}
      goto next1;
     }
     else if(cell->u45d700()){
      KcHI item=cell->getItem();
      setChar417f50(sx,b9,item->ascii457a30());
      if(heldActive&&item->def9b4350()->b24c&&kc_blink437320(1000))setFore417f80(sx,b9,*kc_d2585c);
      else if(aB&&item->def9b4350()->b275&&kc_blink437320(1000)&&KcPos(xC,y).contains409d70(a1->getPosition().x-aB/2,a1->getPosition().y-aB/2,aB,aB)&&*a6->at9ceda0(xC,y)==aA&&kc_cefc4c->u7178d0(KcHE(),KcPos(xC,y),&kc_d2e20c,a1->getPosition(),&kc_d2e20c,0))
       setFore417f80(sx,b9,*kc_cf1604);
      else if((item->u458030()||item->getEffect457b70(0x56))&&kc_cf4830.at9b81f0(item->nested457820())!=0)setFore417f80(sx,b9,kc_blink437320(1000)?item->color5755f0(0):*kc_d31578);
      else if(kc_cf4830.at9b81f0(item->nested457820())==0&&item->def9b4350()->i94!=0)setFore417f80(sx,b9,KcColor::lerp(item->color5755f0(0),*kc_d386cc,kc_pulse4371a0(kc_ba6b84,kc_ba6b88,1000,0)));
      else if(item->def9b4350()->i94!=0)setFore417f80(sx,b9,KcColor::lerp(item->color5755f0(0),*kc_d201bc,kc_pulse4371a0(kc_ba6b8c,kc_ba6b90,2000,0)));
      else if(item->getEffect457b70(0x53))setFore417f80(sx,b9,kc_blink437320(1000)?item->color5755f0(0):*kc_d3872c);
      else setFore417f80(sx,b9,item->color5755f0(0));
      if(tick3&&!kc_cefc4c->contains9e2970(&kc_cefc4c->v730,item)&&kc_cec050==0){items8119c0(item,0,0,0);kc_cefc4c->add9e29b0(&kc_cefc4c->v730,item);}
     }else{
      setChar417f50(sx,b9,cell->getAscii66a830());
      setFore417f80(sx,b9,cell->getColor66a680());
      if(cell->u45d1e0())setBack417fc0(sx,b9,cell->getProp()->color65e040(),true);
      else if(cell->def9fcd80()->back47!=*kc_cfe674)setBack417fc0(sx,b9,cell->def9fcd80()->back47,true);
      if(tick2&&cell->isDoor()&&!kc_cefc4c->contains9e2970(&kc_cefc4c->v720,cell->getProp())&&kc_cec050==0){
       label813050(kc_cefc4c->u4638e0(cell->getProp()->info44b020()->i10)==0,0,cell->getProp(),kc_cefc4c->u4638e0(cell->getProp()->info44b020()->i10)==2,0,0,0);
       kc_cefc4c->add9e29b0(&kc_cefc4c->v720,cell->getProp());
      }
     }
    }
   }else{
    if(b5->at9cdf20(xC,y)->a==a8){
     if(b5->at9cdf20(xC,y)->isActive72ec10()||!b5->at9cdf20(xC,y)->h8.operator->()||*aVisible->at9ceda0(xC,y)!=0)b5->at9cdf20(xC,y)->a=0;
     else{setChar417f50(sx,b9,b5->at9cdf20(xC,y)->getValue461cf0(1));setFore417f80(sx,b9,b5->at9cdf20(xC,y)->getColor72eb70());}
     goto next1;
    }
    else if(e5->at9d2c30(xC,y)->ch!=' '){
     setChar417f50(sx,b9,e5->at9d2c30(xC,y)->ch);
     setFore417f80(sx,b9,e5->at9d2c30(xC,y)->fore8);
     setBack417fc0(sx,b9,e5->at9d2c30(xC,y)->backb,true);
     if(e5->at9d2c30(xC,y)->t2c!=0){
      if(kc_caed20>=e5->at9d2c30(xC,y)->t2c+1000)e5->at9d2c30(xC,y)->t2c=0;
      else if(kc_cefb3c)setBack417fc0(sx,b9,KcColor::lerp(kc_d29804,*kc_d226c8,1.0f-1.0f*sin((float)((kc_caed20-e5->at9d2c30(xC,y)->t2c)/kc_c36fd8*kc_c36e68))),true);
      else setBack417fc0(sx,b9,KcColor::scale(*kc_d226c8*kc_ba6bf4,1.0f-1.0f*sin((float)((kc_caed20-e5->at9d2c30(xC,y)->t2c)/kc_c36fd8*kc_c36e68))),true);
     }
     if(*kc_cefc4c->a690.at9ceda0(xC,y)==0&&e5->at9d2c30(xC,y)->i10==kc_caf164){
      a_=getFore(sx,b9);
      setFore417f80(sx,b9,KcColor::overlay(KcColor((unsigned char)(a_.r*kc_c36df8+a_.g*kc_c36e08+a_.b*kc_c36e00)/2),*kc_cf44c0));
      if(e5->at9d2c30(xC,y)->be){
       a_=getBack(sx,b9);
       setBack417fc0(sx,b9,KcColor::overlay(KcColor((unsigned char)(a_.r*kc_c36df8+a_.g*kc_c36e08+a_.b*kc_c36e00)/2),*kc_cf44c0),true);
      }
      goto next1;
     }
    }else setFore417f80(sx,b9,*kc_cfe674);
   }
   if(*aVisible->at9ceda0(xC,y)==0&&!kc_d1da70){
    if(kc_cefb3c&&getChar(sx,b9)==bN)a_=getFore(sx,b9)*kc_c36f8c;
    else a_=getFore(sx,b9);
    if(fade!=0){
     if(b37d)setFore417f80(sx,b9,KcColor::lerp(a_*kc_c37158,a_*aG,fade));
     else setFore417f80(sx,b9,KcColor::lerp(a_*aG,a_*kc_c37158,fade));
    }else setFore417f80(sx,b9,a_*kc_c37158);
    if(e5->at9d2c30(xC,y)->be){
     a_=getBack(sx,b9);
     if(fade!=0){
      if(b37d)setBack417fc0(sx,b9,KcColor::lerp(a_*kc_c37158,a_*aG,fade),true);
      else setBack417fc0(sx,b9,KcColor::lerp(a_*aG,a_*kc_c37158,fade),true);
     }else setBack417fc0(sx,b9,a_*kc_c37158,true);
    }
   }
  next1:;}
 }
 if(kc_d1da70||kc_cefafc||kc_cefafe||kc_cefb08){}else{
  if(kc_caed20<kc_d1da74+kc_d1da7c){
   KcGridX*flash=kc_cefc4c->u463e70();
   for(int y=from3.y,c8=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&c8<kc_cf27f8;y++,c8++)for(int oldX=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);oldX<=toN.x&&sx<kc_cf27f4;oldX++,sx++) if(flash->at9d2c30(oldX,y)->u461250())setFore417f80(sx,c8,KcColor::scale(getFore(sx,c8),kc_pulse4372b0(kc_c36edc,1,kc_d1da74,kc_d1da7c)));
  }
  if(i214!=0&&kc_d28f9c!=0&&kc_caed20<=i214+2500&&(kc_d28f9c==1||kc_d28f9c==2)&&kc_blinkSince437340(500,i214)){
   KcPos p=kc_cefc4c->getPlayer4630f0()->getPosition().add409b60(scroll);
   if(inBounds4173d0(p)){
    setFore417f80(p.x,p.y,*kc_d31bfc);
    if(kc_d28f9c==2)setChar417f50(p.x,p.y,'X');
   }
  }
  if(kc_cf462c==6){
   KcGridI*heat=kc_cefc4c->pb80;
   for(int y=from3.y,dD=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&dD<kc_cf27f8;y++,dD++)for(int gN=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);gN<=toN.x&&sx<kc_cf27f4;gN++,sx++) if(*heat->at9ceda0(gN,y)!=0)setBack417fc0(sx,dD,KcColor::addAlpha(kc_cefb3c&&getBack(sx,dD)==*kc_cfe674?KcColor(kc_d29804):getBack(sx,dD),*kc_d316fc,kc_pulse4371a0(kc_ba6b14,*heat->at9ceda0(gN,y)*kc_ba6b1c+kc_ba6b18,4000,0)),true);
  }
  if(kc_cf4700!=0){
   if(kc_containsRecord9db330(&kc_d25de0.at9b81f0(kc_cf4700->idx)->x148,8)&&!kc_blink437320(1000)&&kc_cefc4c->player->item5d2380(0xa2).isValid()){
    for(int y=from3.y,eD=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&eD<kc_cf27f8;y++,eD++)for(int j4=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);j4<=toN.x&&sx<kc_cf27f4;j4++,sx++) if(*a6->at9ceda0(j4,y)==aA&&CELL(j4,y)->getEntity().isValid()&&!CELL(j4,y)->getEntity()->isPlayer()&&u806420(CELL(j4,y)->getEntity(),0,0))setFore417f80(sx,eD,*kc_d2a89c);
   }
   if(kc_containsRecord9db330(&kc_d25de0.at9b81f0(kc_cf4700->idx)->x148,9)&&!kc_blink437320(1000)&&kc_cefc4c->player->u5d2a00(0xa2)&&kc_cefc4c->player->item5d2380(0xa2).isNull9b65d0()){
    for(int y=from3.y,g5=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&g5<kc_cf27f8;y++,g5++)for(int k5=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);k5<=toN.x&&sx<kc_cf27f4;k5++,sx++) if(*a6->at9ceda0(k5,y)==aA&&CELL(k5,y)->getEntity().isValid()&&!CELL(k5,y)->getEntity()->isPlayer()&&CELL(k5,y)->getEntity()->getAiType45a2a0()==1&&CELL(k5,y)->getEntity()->getSize()==1&&CELL(k5,y)->getEntity()->isHostileTo(kc_cefc4c->player)&&CELL(k5,y)->getEntity()->ai45b590()->u458f30()==0&&CELL(k5,y)->getEntity()->u5cb9b0(1))setFore417f80(sx,g5,*kc_cfe5a4);
   }
   if(kc_containsRecord9db330(&kc_d25de0.at9b81f0(kc_cf4700->idx)->x148,0xe)&&!kc_blink437320(1000)&&kc_cefc4c->player->item5d2380(0x77).isValid()){
    for(int y=from3.y,kA=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&kA<kc_cf27f8;y++,kA++)for(int nG=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);nG<=toN.x&&sx<kc_cf27f4;nG++,sx++) if(*a6->at9ceda0(nG,y)==aA&&CELL(nG,y)->getEntity().isValid()&&!CELL(nG,y)->getEntity()->isPlayer()&&CELL(nG,y)->getEntity()->u45aaa0(kc_cefc4c->player)&&CELL(nG,y)->getEntity()->u5cab90()&&!CELL(nG,y)->getEntity()->getTarget()&&kc_cefc4c->isReachable465230(0x270f,kc_cefc4c->player->getPosition(),CELL(nG,y)->getEntity()->getPosition()))setFore417f80(sx,kA,*kc_d2a89c);
   }
   if(kc_containsRecord9db330(&kc_d25de0.at9b81f0(kc_cf4700->idx)->x148,0xf)&&!kc_blink437320(1000)&&kc_cefc4c->player->item5d2380(0x77).isValid()){
    for(int y=from3.y,k_=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&k_<kc_cf27f8;y++,k_++)for(int nW=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);nW<=toN.x&&sx<kc_cf27f4;nW++,sx++) if(*a6->at9ceda0(nW,y)==aA&&CELL(nW,y)->getEntity().isValid()&&!CELL(nW,y)->getEntity()->isPlayer()&&CELL(nW,y)->getEntity()->def9b4350()->iac==0){
     KcHE ns=CELL(nW,y)->getEntity();
     int rel=ns->rel5c7fc0(kc_cefc4c->getPlayer4630f0());
     if(ns->getTarget()==3||ns->getTarget()==4||rel==2&&ns->getTarget()==1)setFore417f80(sx,k_,*kc_d2a89c);
     else if(rel==0&&ns->getTarget()==0&&kc_cefc4c->isReachable465230(0x270f,kc_cefc4c->player->getPosition(),ns->getPosition()))setFore417f80(sx,k_,*kc_cfe5a4);
    }
   }
  }
  if(kc_cefc4c->getTurn464270()<=i3a4){
   const int period=1000;
   const int frames=25;
   for(unsigned i=0;i<v3a8.size9b9a50();i++){
    if(v3b8.at9b81f0(i)!=0&&*aVisible->atPoint9ced70(v3a8.at9e7c10(i))==0){
     KcPos p=v3a8.at9e7c10(i).add409b60(scroll);
     if(inBounds4173d0(p)){
      if(kc_caed20>=v3b8.at9b81f0(i)+period){setChar417f50(p.x,p.y,kc_d28d30?0x103:'?');setFore417f80(p.x,p.y,*kc_d29784);}
      else{setChar417f50(p.x,p.y,(kc_caed20-v3b8.at9b81f0(i))%frames%26+'A');setFore417f80(p.x,p.y,*kc_cf281c);}
     }
    }
   }
  }
{  KcHI sensor=kc_cefc4c->getPlayer4630f0()->item5d2380(0x18);
  if(sensor.isValid()&&!kc_cefc4c->b1d8&&(kc_d1e888->type!=0x22||!kc_stringToInt405610(kc_d1e860.text46f6d0("comPlayerSurrendered_g"))))sensor.reset9b7270();
  bool pK=kc_cefb3c?false:kc_d28e81||kc_cec14e&&kc_cec14d;
  float lo=kc_cefb3c?kc_ba6b5c*kc_c37150:kc_ba6b5c;
  float nHi=kc_cefb3c?kc_ba6b60*kc_c37150:kc_ba6b60;
  for(int q3=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);q3<=toN.x;q3++,sx++){
   for(int y=from3.y,m6=kc_maxInt9cdb60(scroll.y,0);y<=toN.y;y++,m6++){
    if(*a6->at9ceda0(q3,y)==aA&&CELL(q3,y)->canCaveIn66af50()){
     setBack417fc0(sx,m6,KcColor::addAlpha(kc_cefb3c&&getBack(sx,m6)==*kc_cfe674?KcColor(kc_d29804):getBack(sx,m6),*kc_cf270c,kc_pulse4371a0(lo,nHi,2000,0)),true);
     if(pK)setBack417fc0(sx,m6,getBack(sx,m6)*kc_c36ecc,true);
    }
   }
  }
  if(sensor.isValid()&&sensor->u577a90()>=1){
   KcPos vP;
   KcVPts*pts=kc_cefc4c->u463a70();
   float scale=kc_c36f88;
   float base0=kc_c3714c;
   for(unsigned i=0;i<pts->size9b9a50();i++){
    if(*a6->atPoint9ced70(pts->at9e7c10(i))==aA&&u8052f0(pts->at9e7c10(i))){
     vP=pts->at9e7c10(i).add409b60(scroll);
     setBack417fc0(vP.x,vP.y,KcColor::addAlpha(kc_cefb3c&&getBack417750(vP)==*kc_cfe674?KcColor(kc_d29804):getBack417750(vP),*kc_cf270c,kc_pulse4371a0(lo,kc_minf9cd050(kc_maxInt9cdb60(0,kc_cfd44c.atPoint9ced70(pts->at9e7c10(i))[0]->u457b10()-caveinInstabilityIncrease)*scale+base0,base0),2000,0)),true);
     if(pK)setBack417fc0(vP.x,vP.y,getBack(vP.x,vP.y)*kc_c36ecc,true);
    }
   }
  }}
  if(kc_cf69c4.x!=-1&&u8052f0(kc_cf69c4)&&kc_blink437320(1000))setBack417fc0(kc_cf69c4.x+scroll.x,kc_cf69c4.y+scroll.y,*kc_d2f1a8,true);
  if(kc_d1e888->type==0x21){
   if(kc_cefc4c->u4646b0()->empty9b86e0()){
    KcPos*vC=kc_cefc4c->u464610();
    KcVPos pts;
    for(int i=0;i<=125;i++)pts.push_back9b3020(KcPos(kc_maxInt9cdb60(0,vC->x-1),i));
    for(int i=vC->x;i<=105;i++)pts.push_back9b3020(KcPos(i,125));
    for(int i=125;i<=224;i++)pts.push_back9b3020(KcPos(106,i));
    for(unsigned i=0;i<pts.size9b9a50();i++){
     pts.at9e7c10(i).sub409a30(scroll);
     if(inBounds4173d0(pts.at9e7c10(i)))setBack417fc0(pts.at9e7c10(i).x,pts.at9e7c10(i).y,KcColor::addAlpha(kc_cefb3c&&getBack417750(pts.at9e7c10(i))==*kc_cfe674?KcColor(kc_d29804):getBack417750(pts.at9e7c10(i)),*kc_d16310,kc_pulse4371a0(kc_ba6b3c,kc_ba6b40,2000,0)),true);
    }
   }else if(kc_stringToInt405610(kc_d1e860.text46f6d0("frgUfdAttacked_g"))&&kc_cefc4c->getTurn464270()-kc_stringToInt405610(kc_d1e860.text46f6d0("frgUfdAttacked_g"))>=35&&!kc_stringToInt405610(kc_d1e860.text46f6d0("scrAttackedLocals_g"))){
    KcVRect*zones=kc_cefc4c->u4646b0();
    KcPos p8;
    for(unsigned i=0;i<zones->size9b5100();i++)
     for(int x=zones->at9b8070(i).x1;x<=zones->at9b8070(i).x2;x++)
      for(int y=zones->at9b8070(i).y1;y<=zones->at9b8070(i).y2;y++){
       p8.set40a010(x,y);
       p8.sub409a30(scroll);
       if(inBounds4173d0(p8))setBack417fc0(p8.x,p8.y,KcColor::addAlpha(kc_cefb3c&&getBack417750(p8)==*kc_cfe674?KcColor(kc_d29804):getBack417750(p8),*kc_d39580,kc_pulse4371a0(kc_ba6b34,kc_ba6b38,4000,0)),true);
      }
   }
  }
  if(h74.isValid()){
   if(!h74.operator->()||h74->getTarget())h74.reset9b7270();
   else{
    KcPos p=h74->getPosition().add409b60(scroll);
    int idx=kc_cefc4c->u463890(0)->indexOf45e1a0(h74);
    if(idx!=-1){
     float hiD=kc_cefb3c?kc_ba6b50*kc_c36ce8:kc_ba6b50;
     KcPos at(h74->getPosition());
     KcGridI2*g=kc_cefc4c->v6d8.at9b81f0(idx);
     int aK=kc_cefc4c->v6d8.at9b81f0(idx)->i0c;
     for(int y=from3.y,nX=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&nX<kc_cf27f8;y++,nX++)for(int t_=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);t_<=toN.x&&sx<kc_cf27f4;t_++,sx++) if(*g->at9ceda0(t_,y)==aK)setBack417fc0(sx,nX,KcColor::addAlpha(BG(sx,nX),*kc_d33d84,kc_pulse4371a0(kc_ba6b4c,hiD,2000,0)),true);
     if(inBounds4173d0(p)){
      for(int x=p.x,y=0;y<kc_cf27f8;y++)setBack417fc0(x,y,KcColor::addAlpha(BG(x,y),*kc_d33d84,kc_pulse4371a0(kc_ba6b4c,hiD,2000,0)),true);
      for(int x=0,y=p.y;x<kc_cf27f4;x++)setBack417fc0(x,y,KcColor::addAlpha(BG(x,y),*kc_d33d84,kc_pulse4371a0(kc_ba6b4c,hiD,2000,0)),true);
     }
    }
   }
  }
  if(kc_cefc4c->p3d4!=0){
   const int interval=20;
   float odds=kc_c37148;
   KcRange w3(500,2000);
   if(kc_caed20>=t4b0){
    KcGridI*g=kc_cefc4c->p3d4;
    for(int y=from3.y,ok=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&ok<kc_cf27f8;y++,ok++)for(int w9=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);w9<=toN.x&&sx<kc_cf27f4;w9++,sx++) if(*aVisible->at9ceda0(w9,y)!=0&&*g->at9ceda0(w9,y)!=0&&rng.chance406cc0(odds)){
     v490.push_back9b3020(KcPos(w9,y));
     v4a0.push_back9b9280(w3.random40c130()+kc_caed20);
    }
    t4b0=kc_caed20+interval;
   }
   KcColor*aD=kc_d2175c;
   KcPos pD;
   for(unsigned i=0;i<v490.size9b9a50();i++){
    if(kc_caed20>=v4a0.at9b81f0(i)||*aVisible->atPoint9ced70(v490.at9e7c10(i))==0){kc_eraseAt9d5190(v490,i);kc_eraseAt9ce6d0(v4a0,i);}
    else{
     pD.set40a090(v490.at9e7c10(i),scroll);
     if(inBounds4173d0(pD))setBack417fc0(pD.x,pD.y,KcColor::addAlpha(BGP(pD),*aD,kc_fade437250(1,v4a0.at9b81f0(i)-w3.y,w3.y)),true);
    }
   }
  }
  if(kc_blink437320(2000)){
   float lo=kc_cefb3c?kc_ba6b64*kc_c37150:kc_ba6b64;
   float hi=kc_cefb3c?kc_ba6b68*kc_c37150:kc_ba6b68;
   KcMarkersHolder*wC=kc_cefc4c->u463be0();
   for(unsigned i=0;i<wC->at9b8070(16).size9b9260();i++){
    KcBox box(wC->at9b8070(16).at9b81f0(i)->pos4184d0(),15);
    box.a.sub409a30(scroll);
    box.b.sub409a30(scroll);
    KcVPos pts;
    for(int x=box.a.x;x<=box.b.x;x++){
     if(inBounds417360(x,box.a.y))pts.push_back9b3020(KcPos(x,box.a.y));
     if(inBounds417360(x,box.b.y))pts.push_back9b3020(KcPos(x,box.b.y));
    }
    for(int y=box.a.y+1;y<box.b.y;y++){
     if(inBounds417360(box.a.x,y))pts.push_back9b3020(KcPos(box.a.x,y));
     if(inBounds417360(box.b.x,y))pts.push_back9b3020(KcPos(box.b.x,y));
    }
    for(unsigned j=0;j<pts.size9b9a50();j++)setBack417fc0(pts.at9e7c10(j).x,pts.at9e7c10(j).y,KcColor::addAlpha(BGP(pts.at9e7c10(j)),*kc_cf65d4,kc_pulse4371a0(lo,hi,2000,0)),true);
   }
  }
  kc_d1e234.clear9b3560();
  if(kc_cefc4c->getPlayer4630f0()->item5d2380(0x12).isValid()){
   KcVBool seen(kc_d01b28.size9b9a50(),false);
   if(!kc_d25450||kc_d255fc==0){
    KcPos gi(a1->getPosition());
    int dist;
    for(int y=from3.y,r1=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&r1<kc_cf27f8;y++,r1++)for(int z6=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);z6<=toN.x&&sx<kc_cf27f4;z6++,sx++) if(CELL(z6,y)->getProp().isValid()&&CELL(z6,y)->getProp()->u457b10()!=1&&CELL(z6,y)->getProp()->def9b8f00()->ia0!=0&&!kc_cefc4c->isVisible463190(z6,y)){
     dist=kc_distance40a3f0(gi,KcPos(z6,y));
     if(dist<=kc_cefc04){
      int type=CELL(z6,y)->getProp()->def9b8f00()->ia0;
      setBack417fc0(sx,r1,KcColor::addAlpha(BG(sx,r1),*kc_d32cf0,kc_pulse4371a0(kc_ba6b20,kc_b94908[type]*kc_ba6b28+kc_ba6b24,2000,0)),true);
      kc_d1e234.push_back9b3020(KcPos(z6,y));
     }
    }
   }
   if(!kc_d01b28.empty9b86e0()){
    KcPos p;
    for(unsigned i=0;i<kc_d01b28.size9b9a50();i++){
     if(!seen.at9b38a0(i)){
      if(kc_cefc4c->isVisible4631c0(kc_d01b28.at9e7c10(i))){kc_eraseAt9d5190(kc_d01b28,i);kc_eraseAt9ce6d0(kc_d02b64,i);}
      else{
       p=kc_d01b28.at9e7c10(i).add409b60(scroll);
       if(inBounds4173d0(p))setBack417fc0(p.x,p.y,KcColor::addAlpha(BGP(p),*kc_d32cf0,kc_pulse4371a0(kc_ba6b20,kc_d02b64.at9b81f0(i)*kc_ba6b28+kc_ba6b24,2000,0)),true);
      }
     }
    }
   }
  }
  if(kc_cefc4c->getPlayer4630f0()->item5d2380(0xe).isValid()&&(!kc_d35860.empty9b86e0()||!kc_d1daec.empty9b86e0())){
   KcPos p;
   KcVE8*ang;
   for(int k=0;k<2;k++){
    ang=k?&kc_d1daec:&kc_d35860;
    for(unsigned i=0;i<ang->size9b9a50();i++){
     if(kc_cefc4c->isVisible4631c0(ang->at9b32b0(i)))kc_eraseStep9d7300(*ang,i);
     else{
      p=ang->at9b32b0(i).add409b60(scroll);
      if(inBounds4173d0(p))setBack417fc0(p.x,p.y,KcColor::addAlpha(BGP(p),k?*kc_d21f54:*kc_d29d90,kc_pulse4371a0(kc_ba6b2c,kc_ba6b30,2000,0)),true);
     }
    }
   }
  }
  if(kc_cefc4c->getPlayer4630f0()->item5d2380(0xc9).isValid()&&i134!=0x24){
   KcPos ppos(a1->getPosition());
   KcPos p;
   for(int y=from3.y,s0=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&s0<kc_cf27f8;y++,s0++)for(int z7=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);z7<=toN.x&&sx<kc_cf27f4;z7++,sx++) if(CELL(z7,y)->u45db50()&&kc_distance40a3f0(ppos,KcPos(z7,y))<=16){
    p.set40a010(z7,y);
    p.sub409a30(scroll);
    setBack417fc0(p.x,p.y,KcColor::addAlpha(BGP(p),*kc_d223e4,kc_pulse4371a0(kc_ba6b08,CELL(z7,y)->u45a6e0()*kc_ba6b10+kc_ba6b0c,4000,0)),true);
   }
  }
  if(kc_cf4700!=0){
   if(kc_containsRecord9db330(&kc_d25de0.at9b81f0(kc_cf4700->idx)->x148,1)){
    for(int y=from3.y,u6=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&u6<kc_cf27f8;y++,u6++)for(int aFp=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);aFp<=toN.x&&sx<kc_cf27f4;aFp++,sx++) if(*aVisible->at9ceda0(aFp,y)!=0&&CELL(aFp,y)->getProp().isValid()&&CELL(aFp,y)->getProp()->u44ab40()!=-1&&!kc_containsRecord9db330(&kc_cefc4c->xbb4,CELL(aFp,y)->getProp()->u44ab40()))
     setBack417fc0(sx,u6,KcColor::addAlpha(BG(sx,u6),*kc_d1629c,kc_pulse4371a0(kc_ba6b94,kc_ba6b98,4000,0)),true);
   }
   if(kc_containsRecord9db330(&kc_d25de0.at9b81f0(kc_cf4700->idx)->x148,4)){
    for(int y=from3.y,w8=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&w8<kc_cf27f8;y++,w8++)for(int at5=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);at5<=toN.x&&sx<kc_cf27f4;at5++,sx++) if(CELL(at5,y)->u45d310())setBack417fc0(sx,w8,KcColor::addAlpha(BG(sx,w8),*kc_d1629c,kc_pulse4371a0(kc_ba6b94,kc_ba6b98,4000,0)),true);
   }
   if(kc_containsRecord9db330(&kc_d25de0.at9b81f0(kc_cf4700->idx)->x148,0xd)){
    KcVPts*pts=kc_cefc4c->u464060();
    for(unsigned i=0;i<pts->size9b9a50();i++){
     if(u8052f0(pts->at9e7c10(i))&&kc_distance40a3f0(kc_cefc4c->getPlayer4630f0()->getPosition(),pts->at9e7c10(i))<=20){
      KcPos p=pts->at9e7c10(i).add409b60(scroll);
      setBack417fc0(p.x,p.y,KcColor::addAlpha(BGP(p),*kc_d1629c,kc_pulse4371a0(kc_ba6b94,kc_ba6b98,4000,0)),true);
     }
    }
   }
  }
  if(!v2bc.empty9b86e0()){
   for(unsigned i=0;i<v2bc.size9b96e0();i++){
    if(*aVisible->atPoint9ced70(v2bc.at9b9700(i).pos)!=0&&u8052f0(v2bc.at9b9700(i).pos)&&kc_cfd44c.atPoint9ced70(v2bc.at9b9700(i).pos)[0]->u4550b0()){
     KcPos p=v2bc.at9b9700(i).pos.add409b60(scroll);
     setChar417f50(p.x,p.y,v2bc.at9b9700(i).ch);
     KcColor ats;
     switch(v2bc.at9b9700(i).type){
     case 5:ats=*kc_d35bbc;break;
     case 6:ats=*kc_d386c8;break;
     case 7:ats=*kc_d20618;break;
     case 8:ats=*kc_d38644;break;
     case 9:ats=*kc_d201c4;break;
     case 10:ats=*kc_d2b284;break;
     default:ats=*kc_cfabbc;break;
     }
     setFore417f80(p.x,p.y,KcColor::scale(ats,kc_pulse437200(kc_ba6bc0,kc_ba6bc4,200,v2bc.at9b9700(i).t10)));
    }
   }
  }
  if(!v2cc.empty9b86e0()){
   for(unsigned i=0;i<v2cc.size9b4760();i++){
    if(kc_caed20>v2cc.at9b4780(i).t8+200)kc_eraseStep9e2a40(v2cc,i);
    else{
     KcPos p=v2cc.at9b4780(i).pos.add409b60(scroll);
     if(inBounds4173d0(p)){
      KcColor c=kc_cefb3c?KcColor::lerp(kc_d29804,*kc_d31db4,kc_fade437250(kc_ba6bc8,v2cc.at9b4780(i).t8,200)):KcColor::scale(*kc_d31db4,kc_fade437250(kc_ba6bc8,v2cc.at9b4780(i).t8,200));
      setBack417fc0(p.x,p.y,c,true);
     }
    }
   }
  }
  if(!v2dc.empty9b86e0()){
   for(unsigned i=0;i<v2dc.size9b9a50();i++){
    KcHI it=v2dc.at9e7c10(i).h;
    if(it.operator->()){
     KcVPos pts;
     if(it->u457b50().isNull9b65d0())pts.push_back9b32e0(it->u575920());
     else kc_append9d7f20(pts,it->u457b50()->u45d1a0());
     for(unsigned j=0;j<pts.size9b9a50();j++){
      if(kc_cefc4c->isVisible4631c0(pts.at9e7c10(j))&&u8052f0(pts.at9e7c10(j))){
       KcPos p=pts.at9e7c10(j).add409b60(scroll);
       setBack417fc0(p.x,p.y,KcColor::addAlpha(BGP(p),*kc_d38474,kc_pulse437200(kc_ba6bcc,kc_ba6bd0,300,v2dc.at9e7c10(i).t)),true);
      }
     }
    }
   }
  }
  if(!v2ec.empty9b86e0()){
   const int maxAge=100;
   for(unsigned i=0;i<v2ec.size9b9a50();i++){
    if(*aVisible->atPoint9ced70(v2ec.at9e7c10(i))!=0&&u8052f0(v2ec.at9e7c10(i))&&kc_cfd44c.atPoint9ced70(v2ec.at9e7c10(i))[0]->u4550b0()){
     KcPos p=v2ec.at9e7c10(i).add409b60(scroll);
     setChar417f50(p.x,p.y,kc_d28d30?kc_cefbe4->i78:kc_d01618);
     float his=(kc_ba6bd8-kc_ba6bd4)*(kc_minInt9cdb30(v2fc.at9b81f0(i),maxAge)/kc_c36cd0)+kc_ba6bd4;
     setFore417f80(p.x,p.y,KcColor::scale(*kc_d3a20c,kc_pulse437200(kc_ba6bc0,his,200,v30c.at9b81f0(i))));
     setBack417fc0(p.x,p.y,KcColor::addAlpha(BGP(p),*kc_d3a20c,kc_pulse437200(kc_ba6bdc,kc_ba6be0,200,v30c.at9b81f0(i))),true);
    }
   }
  }
  if(!v33c.empty9b86e0()){
   for(unsigned i=0;i<v33c.size9b5100();i++){
    if(kc_caed20>=v33c.at9b8070(i).tc+2400||kc_cefc4c->isVisible4631c0(v33c.at9b8070(i).pos))kc_eraseStep9e2a90(v33c,i);
    else if(kc_blink437320(200)&&u8052f0(v33c.at9b8070(i).pos)){
     KcPos p=v33c.at9b8070(i).pos.add409b60(scroll);
     setBack417fc0(p.x,p.y,v33c.at9b8070(i).b8?*kc_d221b0:*kc_d38544,true);
    }
   }
  }
  if(!v34c.empty9b86e0()){
   for(unsigned i=0;i<v34c.size9b5100();i++){
    if(!kc_cefc4c->isVisible4631c0(v34c.at9b8070(i).pos)){
     int size=v34c.at9b8070(i).def->i70>21?3:1;
     if(kc_caed20>v34c.at9b8070(i).t+600){kc_eraseStep9e2ae0(v34c,i);continue;}
     int stepA=600/(size+1);
     int wD=(kc_caed20-v34c.at9b8070(i).t)/stepA;
     KcPos curC=v34c.at9b8070(i).pos.add409b60(scroll);
     KcColor h1=kc_cefb3c?kc_cf40ac[v34c.at9b8070(i).def->i38]*kc_c37144:kc_cf40ac[v34c.at9b8070(i).def->i38];
     if(size>1)h1.scale412bd0(1+(size-1)*kc_c36df8);
     KcColor fill=kc_cefb3c?KcColor::lerp(kc_d29804,h1,kc_fade437250(kc_ba6be4,v34c.at9b8070(i).t,600)):KcColor::scale(h1,kc_fade437250(kc_ba6be4,v34c.at9b8070(i).t,600));
     KcPos a(curC.x-wD,curC.y-wD);
     KcPos at8(curC.x+wD,curC.y+wD);
     for(int x=a.x,e19=v34c.at9b8070(i).pos.x-wD;x<=at8.x;x++,e19++)
      for(int y=a.y,g22=v34c.at9b8070(i).pos.y-wD;y<=at8.y;y++,g22++)
       if(inBounds417360(x,y)&&kc_cfd44c.inBounds9b45c0(e19,g22)&&(CELL(e19,g22)->getProp().isNull9b65d0()||!CELL(e19,g22)->getProp()->u45cb10()))setBack417fc0(x,y,fill,true);
    }
   }
  }
  if(kc_d1e888->type==0x15&&!kc_stringToInt405610(kc_d1e860.text46f6d0("datDataConduitDisabled_g"))||kc_d1e888->type==0xd||kc_d1e888->type==8){
   int interval=10;
   float dur=kc_c36ec8;
   switch(kc_d1e888->type){
   case 8:interval=50;dur=kc_c36f50;break;
   case 0x15:interval=75;dur=kc_c37140;break;
   case 0xd:interval=125;dur=kc_c37140;break;
   }
   if(kc_caed20-t90>dur)t90=kc_caed20;
   if(kc_caed20-t90>interval){
    int n=(kc_caed20-t90)/interval;
    KcVInt g31;
    for(int k=0;k<n;k++){
     if(i94==i8c)i94=0;
     else i94++;
     g31.push_back9b9d30(i94);
    }
    for(unsigned k=0;k<g31.size9b9260();k++)
     for(unsigned j=0;j<v78.size9b5100();j++)
      if(g31.at9b81f0(k)<v78.at9b8070(j).size9b9a50()&&v78.at9b8070(j).at9e7c10(g31.at9b81f0(k)).x!=-1){
       v98.push_back9b32e0(v78.at9b8070(j).at9e7c10(g31.at9b81f0(k)));
       va8.push_back9b9d30(kc_caed20);
      }
    t90+=g31.size9b9260()*interval;
   }
   if(!v98.empty9b86e0()){
    KcColor col(*kc_cfc180);
    float pJ;int g45;int y;
    switch(kc_d1e888->type){
    case 8:col=*kc_d20b70;break;
    case 0x15:col=*kc_d20b70;break;
    case 0xd:col=*kc_d204ac;break;
    }
    for(unsigned k=0;k<v98.size9b9a50();k++){
     pJ=(kc_caed20-va8.at9b81f0(k))/dur;
     if(pJ>kc_c36ca0){kc_eraseAt9d5190(v98,k);kc_eraseAt9ce6d0(va8,k);}
     else if(*aVisible->atPoint9ced70(v98.at9e7c10(k))!=0&&u8052f0(v98.at9e7c10(k))){
      g45=v98.at9e7c10(k).x+scroll.x;
      y=v98.at9e7c10(k).y+scroll.y;
      setFore417f80(g45,y,KcColor::lerp(getFore(g45,y),col,sin((float)(pJ*kc_c36c98))));
     }
    }
   }
  }
  if(kc_d1e888->type==0x22&&!kc_stringToInt405610(kc_d1e860.text46f6d0("comConduitDisabled_g"))){
   int g49;
   int y;
   for(unsigned i=0;i<v78.at9b8070(0).size9b9a50();i++){
    if(*aVisible->atPoint9ced70(v78.at9b8070(0).at9e7c10(i))!=0&&u8052f0(v78.at9b8070(0).at9e7c10(i))){
     g49=v78.at9b8070(0).at9e7c10(i).x+scroll.x;
     y=v78.at9b8070(0).at9e7c10(i).y+scroll.y;
     setFore417f80(g49,y,KcColor::lerp(getFore(g49,y),*kc_cfabbc,kc_pulse4371a0(0,1,2000,0)));
    }
   }
   const int g51=50;
   float dur=kc_c36ec8;
   if(kc_caed20-t90>1000)t90=kc_caed20;
   if(kc_caed20-t90>g51){
    int n=(kc_caed20-t90)/g51;
    KcVPos pts2;
    for(unsigned j=1;j<vb8.size9b9260();j++){
     for(int k=0;k<n;k++){
      if(vb8.at9b81f0(j)==-1){
       if(n>=1&&rng.chance406c90(2))vb8.at9b81f0(j)=-1;
       else continue;
      }
      vb8.at9b81f0(j)++;
      if(vb8.at9b81f0(j)==v78.at9b8070(j).size9b9a50())vb8.at9b81f0(j)=-1;
      else pts2.push_back9b32e0(v78.at9b8070(j).at9e7c10(vb8.at9b81f0(j)));
     }
    }
    for(unsigned j=0;j<pts2.size9b9a50();j++){
     if(pts2.at9e7c10(j).x!=-1){v98.push_back9b32e0(pts2.at9e7c10(j));va8.push_back9b9d30(kc_caed20);}
    }
    t90+=n*g51;
   }
   if(!v98.empty9b86e0()){
    float t;
    for(unsigned k=0;k<v98.size9b9a50();k++){
     t=(kc_caed20-va8.at9b81f0(k))/dur;
     if(t>kc_c36ca0){kc_eraseAt9d5190(v98,k);kc_eraseAt9ce6d0(va8,k);}
     else if(*aVisible->atPoint9ced70(v98.at9e7c10(k))!=0&&u8052f0(v98.at9e7c10(k))){
      g49=v98.at9e7c10(k).x+scroll.x;
      y=v98.at9e7c10(k).y+scroll.y;
      setFore417f80(g49,y,KcColor::lerp(getFore(g49,y),*kc_cfabbc,sin((float)(t*kc_c36c98))));
     }
    }
   }
  }
  if(kc_d1e888->type==0x23&&kc_stringToInt405610(kc_d1e860.text46f6d0("ac0RanGateTestB_g"))&&!kc_stringToInt405610(kc_d1e860.text46f6d0("ac0GateDisabled_g"))){
   const int frames=3;
   const int half=4;
   const int sizeVal=9;
   if(pc8==0){
    pc8=new KcSubCon(this,sizeVal,sizeVal,0,0,2,true,-1);
    pc8->animate48c3f0("A_AC0_SingularityGate");
   }else pc8->engine64->update50fff0();
   KcPos h5=kc_d1ec6c.add409b60(scroll);
   h5.move40a2a0(-half,-half);
   KcArea area(h5,sizeVal,sizeVal);
   bool i1=false;
   if(KcArea(0,0,width44b0d0(),getHeight4174c0()).containsRect40aa70(area)){
    copy429fe0(pc8,KcPos(0,0),area);
    i1=true;
   }else if(KcArea(0,0,width44b0d0(),getHeight4174c0()).touches40aef0(area)){
    KcArea clip;
    KcArea(0,0,width44b0d0(),getHeight4174c0()).intersect40ab30(area,clip);
    copy429fe0(pc8,KcPos(h5.x<0?-h5.x:0,h5.y<0?-h5.y:0),clip);
    i1=true;
   }
   if(i1){
    pc8->engine64->render5100b0();
    for(int iVal=0,x=area.x;x<area.x+area.w;iVal++,x++)
     for(int h49=0,y=area.y;y<area.y+area.h;h49++,y++)
      if(inBounds417360(x,y)&&*aVisible->at9ceda0(x-scroll.x,y-scroll.y)!=0)putCell4181a0(x,y,pc8->cell4176e0(iVal,h49));
   }
  }else if(pc8!=0){
   if(pc8!=0){removeSubconsole428b20(pc8);pc8=0;}
  }
  if(kc_d1e888->type==0x1d&&(kc_stringToInt405610(kc_d1e860.text46f6d0("extAcquiredA7DataCore_g"))||kc_stringToInt405610(kc_d1e860.text46f6d0("datDataConduitDownloaded_g")))){
   KcVPos h59;
   for(int x=0;x<kc_cfd44c.width9fcd80();x++)
    for(int y=0;y<kc_cfd44c.height9b8f00();y++)
     if(CELL(x,y)->getProp().isValid()&&kc_eq9ccb50(CELL(x,y)->getProp()->name45c590(),"LAB_Scan_Trigger")){
      h59.push_back9b3020(KcPos(x,y));
      kc_surrounding4faaf0(KcPos(x,y),h59);
     }
   float aN=kc_cefb3c?kc_ba6b44*kc_c37150:kc_ba6b44;
   float hi=kc_cefb3c?kc_ba6b48*kc_c37150:kc_ba6b48;
   for(unsigned i=0;i<h59.size9b9a50();i++){
    if(kc_cefc4c->isVisible4631c0(h59.at9e7c10(i))){
     h59.at9e7c10(i).sub409a30(scroll);
     if(inBounds417360(h59.at9e7c10(i).x,h59.at9e7c10(i).y))setBack417fc0(h59.at9e7c10(i).x,h59.at9e7c10(i).y,KcColor::addAlpha(BGP(h59.at9e7c10(i)),*kc_d230f0,kc_pulse4371a0(aN,hi,1000,0)),true);
    }
   }
  }
  if(kc_d28d48==2){
   const int dur=400;
   int hub;int y;
   for(unsigned i=0;i<kc_d2ec1c.size9b9a50();i++){
    if(kc_caed20>=kc_cfc20c.at9b81f0(i)+dur||*aVisible->atPoint9ced70(kc_d2ec1c.at9e7c10(i))==0){kc_eraseAt9d5190(kc_d2ec1c,i);kc_eraseAt9ce6d0(kc_cfc20c,i);}
    else if(u8052f0(kc_d2ec1c.at9e7c10(i))){
     hub=kc_d2ec1c.at9e7c10(i).x+scroll.x;
     y=kc_d2ec1c.at9e7c10(i).y+scroll.y;
     setFore417f80(hub,y,KcColor::lerp(KcColor(0,0x30,0),getFore(hub,y),1.0f*sin((float)((kc_caed20-kc_cfc20c.at9b81f0(i))/kc_c37068*kc_c36e68))));
    }
   }
  }
  if(!kc_cf2800.empty9b86e0()){
   bool g7=a1->item5d2380(0xd).isValid()&&a1->item5d2380(0xd)->u577a90()!=0;
   KcColor gX(*kc_d38644);
   float minA=kc_cefb3c?kc_c36cb8:kc_c36de8;
   float theStep=(1-minA)/kc_cefc4c->i34;
   KcColor k24;
   int k27;int y;
   for(unsigned i=0;i<kc_cf2800.size9b9a50();i++){
    if(kc_caed20>=kc_d32ecc.at9b81f0(i)+kc_d28e9c||*aVisible->atPoint9ced70(kc_cf2800.at9e7c10(i))==0){kc_eraseAt9d5190(kc_cf2800,i);kc_eraseAt9ce6d0(kc_d32ecc,i);}
    else if(u8052f0(kc_cf2800.at9e7c10(i))){
     k27=kc_cf2800.at9e7c10(i).x+scroll.x;
     y=kc_cf2800.at9e7c10(i).y+scroll.y;
     k24=gX*(kc_cfd44c.atPoint9ced70(kc_cf2800.at9e7c10(i))[0]->highlighter4ab670()*theStep+minA);
     if(kc_cefb3c)setBack417fc0(k27,y,KcColor::lerp(kc_d29804,k24,1.0f-1.0f*sin((float)((double)(kc_caed20-kc_d32ecc.at9b81f0(i))/kc_d28e9c*kc_c36e68))),true);
     else setBack417fc0(k27,y,KcColor::scale(k24,1.0f-1.0f*sin((float)((double)(kc_caed20-kc_d32ecc.at9b81f0(i))/kc_d28e9c*kc_c36e68))),true);
    }
   }
  }
  if(kc_cefc4c->getMaxItemRange71c930()){
   float r7=kc_cefb3c?kc_ba6c08*kc_c37150:kc_ba6c08;
   float hA=kc_cefb3c?kc_ba6c0c*kc_c37150:kc_ba6c0c;
   int range=kc_cefc4c->getMaxItemRange71c930();
   KcArea2 k30;
   int rC;int atB;
   kc_cfd44c.getRect9b4430(kc_cefc4c->player->getPosition(),range,k30);
   for(int x=k30.x1;x<=k30.x2;x++)
    for(int y=k30.y1;y<=k30.y2;y++)
     if(CELL(x,y)->getEntity().isValid()&&!CELL(x,y)->getEntity()->isPlayer()&&kc_cefc4c->isVisible463190(x,y)&&!CELL(x,y)->getEntity()->getTarget()&&u8052f0(KcPos(x,y))&&kc_cefc4c->u465200(kc_cefc4c->player->u45a4c0(),KcPos(x,y))&&kc_distance40a3f0(kc_cefc4c->player->getPosition(),KcPos(x,y))<=range){
      rC=x+scroll.x;
      atB=y+scroll.y;
      setBack417fc0(rC,atB,KcColor::addAlpha(BG(rC,atB),*kc_d22854,kc_pulse4371a0(r7,hA,1000,0)),true);
     }
  }
  if(h55c.operator->()&&kc_caed20<t560+900&&kc_blink437320(250)&&kc_cefc4c->u4631f0(h55c)){
   KcVPos&pts=h55c->u45d1a0();
   for(unsigned i=0;i<pts.size9b9a50();i++)
    if(*aVisible->atPoint9ced70(pts.at9e7c10(i))!=0&&u8052f0(pts.at9e7c10(i)))putChar418110(pts.at9e7c10(i).x+scroll.x,pts.at9e7c10(i).y+scroll.y,0x21,*kc_d01c00);
  }else if(p58c.x!=-1&&kc_caed20<t594+900&&kc_blink437320(250)){
   if(*aVisible->atPoint9ced70(p58c)!=0&&u8052f0(p58c))putChar418110(p58c.x+scroll.x,p58c.y+scroll.y,0x21,*kc_d01c00);
  }else if(p59c.x!=-1&&kc_caed20<t5a4+900&&kc_blink437320(250)){
   if(*aVisible->atPoint9ced70(p59c)!=0&&u8052f0(p59c))putChar418110(p59c.x+scroll.x,p59c.y+scroll.y,0x21,*kc_d01c00);
  }else if(h5ac.operator->()&&kc_caed20<t5b0+900&&kc_blink437320(250)){
   KcPos p=h5ac->pos4184d0();
   if(*aVisible->atPoint9ced70(p)!=0&&u8052f0(p))putChar418110(p.x+scroll.x,p.y+scroll.y,0x21,*kc_d01c00);
  }else if(h5c4.operator->()&&kc_caed20<t5c8+900&&kc_blink437320(250)){
   if(*aVisible->atPoint9ced70(h5c4->getPosition())!=0){
    KcPos p=h5c4->getPosition();
    if(u8052f0(p))putChar418110(p.x+scroll.x,p.y+scroll.y,0x21,*kc_cefd54);
   }
  }
  if(kc_inRange9e2b30(t5cc,kc_caed20,t5cc+500)||kc_inRange9e2b30(t5d4,kc_caed20,t5d4+500)){
   KcPos p=kc_cefc4c->getPlayer4630f0()->getPosition();
   if(*aVisible->atPoint9ced70(p)!=0&&u8052f0(p))putChar418110(p.x+scroll.x,p.y+scroll.y,0x21,*kc_d01c00);
  }
  if(kc_inRange9e2b30(t5f0,kc_caed20,t5f0+3000)&&kc_blink437320(250)){
   for(unsigned i=0;i<v600.size9b9260();i++){
    if(v600.at9b81f0(i).operator->()){
     KcPos p=v600.at9b81f0(i)->getPosition();
     if(*aVisible->atPoint9ced70(p)!=0&&u8052f0(p))putChar418110(p.x+scroll.x,p.y+scroll.y,0x21,*kc_d01c00);
    }
   }
  }
  if(h458.operator->()&&kc_caed20<t45c+900&&kc_blink437320(250)&&kc_cefc4c->u4631f0(h458)){
   KcVPos&pts=h458->u45d1a0();
   for(unsigned i=0;i<pts.size9b9a50();i++)
    if(*aVisible->atPoint9ced70(pts.at9e7c10(i))!=0&&u8052f0(pts.at9e7c10(i)))putChar418110(pts.at9e7c10(i).x+scroll.x,pts.at9e7c10(i).y+scroll.y,0x21,*kc_d216f0);
  }
  if(kc_d28d40){
   KcArea2 area;
   view8051f0((KcPos*)&area.x1,(KcPos*)&area.x2);
   for(unsigned i=0;i<kc_cefc4c->v4c.size9b9260();i++){
    KcVEnt&members=kc_cefc4c->v4c.at9b81f0(i)->u416f40();
    for(unsigned j=0;j<members.size9b9260();j++){
     KcVTrail&trail=members.at9b81f0(j)->u45a740();
     KcColor col=kc_cf462c==4&&members.at9b81f0(j)->getFaction()==0x48?kc_d329a4[members.at9b81f0(j)->u45acb0(0x28)]:members.at9b81f0(j)->color5c7630();
     for(unsigned k=0;k<trail.size9b9260();k++){
      if(kc_caed20<trail.at9b81f0(k)->t8+kc_d28d40){
       if(kc_cefc4c->isVisible4631c0(trail.at9b81f0(k)->pos)&&area.contains40b750(trail.at9b81f0(k)->pos)){
        KcPos p=trail.at9b81f0(k)->pos.add409b60(scroll);
        if(kc_cefb3c)setBack417fc0(p.x,p.y,KcColor::lerp(kc_d29804,col*kc_ba6bf0,1.0f-1.0f*sin((float)((double)(kc_caed20-trail.at9b81f0(k)->t8)/kc_d28d40*kc_c36e68))),true);
        else setBack417fc0(p.x,p.y,KcColor::scale(col*kc_ba6bf0,1.0f-1.0f*sin((float)((double)(kc_caed20-trail.at9b81f0(k)->t8)/kc_d28d40*kc_c36e68))),true);
       }
      }else{kc_deleteObject9d8f20(trail,k);k--;}
     }
    }
   }
  }
{  KcVSq&sq=kc_cefc4c->u4643f0();
  for(unsigned i=0;i<sq.size9b9260();i++){
   KcPos iA=sq.at9b81f0(i)->h0->u5c80f0(sq.at9b81f0(i)->h4->getPosition());
   KcVPos pathX;
   KcVInt oldA;
   KcVInt k50;
   KcPos newP;
   kc_cefc4c->u7170a0(sq.at9b81f0(i)->h0,sq.at9b81f0(i)->h4->getPosition(),pathX,oldA,k50,newP,0,4,1,1);
   const int is=1000;
   KcColor c1(kc_d29804);
   KcColor c2(*kc_cf44c4);
   int nA=kc_minInt9cdb30((int)((double)(kc_caed20%is)/kc_c36fd8*pathX.size9b9a50()),pathX.size9b9a50()-1);
   int sx;
   int bC;
   if(nA==0){
    if(kc_cefc4c->isVisible4631c0(pathX.at9e7c10(nA))&&!kc_cfd44c.atPoint9ced70(pathX.at9e7c10(nA))[0]->u66b120()){
     sx=pathX.at9e7c10(nA).x+scroll.x;
     bC=pathX.at9e7c10(nA).y+scroll.y;
     if(inBounds417360(sx,bC))setBack417fc0(sx,bC,c2*(float)(k50.at9b81f0(nA)/kc_c36cf8),true);
    }
   }else{
    for(int k=0;k<=nA;k++){
     if(kc_cefc4c->isVisible4631c0(pathX.at9e7c10(k))&&!kc_cfd44c.atPoint9ced70(pathX.at9e7c10(k))[0]->u66b120()){
      sx=pathX.at9e7c10(k).x+scroll.x;
      bC=pathX.at9e7c10(k).y+scroll.y;
      if(inBounds417360(sx,bC))setBack417fc0(sx,bC,KcColor::lerp(c1,c2,(float)((double)k/nA*(k50.at9b81f0(k)/kc_c36cf8))),true);
     }
    }
   }
   for(int k=nA+1;k<pathX.size9b9a50();k++){
    if(kc_cefc4c->isVisible4631c0(pathX.at9e7c10(k))&&!kc_cfd44c.atPoint9ced70(pathX.at9e7c10(k))[0]->u66b120()){
     sx=pathX.at9e7c10(k).x+scroll.x;
     bC=pathX.at9e7c10(k).y+scroll.y;
     if(inBounds417360(sx,bC))setBack417fc0(sx,bC,KcColor::lerp(c2,c1,(float)((double)(k-(nA+1))/(pathX.size9b9a50()-(float)(nA+1))*(k50.at9b81f0(k)/kc_c36cf8))),true);
    }
   }
   if(sq.at9b81f0(i)->h4->isPlayer()){
    if(sq.at9b81f0(i)->t8==0){
     if(kc_caed20%is<=kc_cefa78){
      kc_sound4541b0(kc_caed20/is%2?0xba:0xbb,0,0);
      sq.at9b81f0(i)->t8=kc_caed20+is;
     }
    }else if(kc_caed20>=sq.at9b81f0(i)->t8){
     kc_sound4541b0(kc_caed20/is%2?0xba:0xbb,0,0);
     sq.at9b81f0(i)->t8+=is;
    }
   }
  }}
  if(bd0){
   if(kc_d28d16){
    KcVInt lvA(10,0);
    KcVInt k51(10,0);
    KcVHX k54;
    KcVHX hxB;
    a1->u5d6c30(k54);
    a1->u5c9190(3,hxB,1);
    if(!k54.empty9b86e0())a1->u5d7700(k54,lvA);
    if(!hxB.empty9b86e0())a1->u5d7700(hxB,k51);
    if(!k54.empty9b86e0()||!hxB.empty9b86e0()){
     KcPropDef2*pd;KcCellDef*pct;
     for(int y=from3.y,atX=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&atX<kc_cf27f8;y++,atX++)for(int k57=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);k57<=toN.x&&sx<kc_cf27f4;k57++,sx++){
      if(*aVisible->at9ceda0(k57,y)!=0){
       if(CELL(k57,y)->getProp().isValid()&&!CELL(k57,y)->getProp()->isPassable65e1d0(KcHE())){
        pd=CELL(k57,y)->getProp()->def9b8f00();
        for(int i=0;i<10;i++)
         if(lvA.at9b81f0(i)!=0&&lvA.at9b81f0(i)*pd->ia8[i]/100*pd->p60->a20[i]/100>=CELL(k57,y)->getProp()->u45c630()){setFore417f80(sx,atX,*kc_d21e58*kc_pulse437200(kc_ba6b00,kc_ba6b04,2000,td4));goto nextCell;}
        for(int i=0;i<10;i++)
         if(k51.at9b81f0(i)!=0&&k51.at9b81f0(i)*pd->ia8[i]/100*pd->p60->a20[i]/100>=CELL(k57,y)->getProp()->u45c630()){setFore417f80(sx,atX,*kc_d2ae2c*kc_pulse437200(kc_ba6b00,kc_ba6b04,2000,td4));goto nextCell;}
       }
       if(!CELL(k57,y)->u4550b0()){
        pct=CELL(k57,y)->isEdge45dc30()&&!kc_cefc4c->u463e90(KcPos(k57,y))?caveinWallTerrain:CELL(k57,y)->def9fcd80();
        for(int i=0;i<10;i++)
         if(lvA.at9b81f0(i)!=0&&lvA.at9b81f0(i)*pct->p50->a20[i]/100>=pct->i68){setFore417f80(sx,atX,*kc_d21e58*kc_pulse437200(kc_ba6b00,kc_ba6b04,2000,td4));goto nextCell;}
        for(int i=0;i<10;i++)
         if(k51.at9b81f0(i)!=0&&k51.at9b81f0(i)*pct->p50->a20[i]/100>=pct->i68){setFore417f80(sx,atX,*kc_d2ae2c*kc_pulse437200(kc_ba6b00,kc_ba6b04,2000,td4));goto nextCell;}
       }
      }
      nextCell:;
     }
    }
   }
   if(kc_cec084->v8c.empty9b86e0()){
    KcColor dark(0x20,0,0);
    KcGridI2*g=kc_cefc4c->p6e8;
    int gid=kc_cefc4c->p6e8->i0c;
    for(int y=from3.y,e20=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&e20<kc_cf27f8;y++,e20++)for(int lo4=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);lo4<=toN.x&&sx<kc_cf27f4;lo4++,sx++){
     if(*g->at9ceda0(lo4,y)==gid&&getBack(sx,e20)==kc_d29804)setBack417fc0(sx,e20,dark,true);
    }
   }else if(kc_cec084->v8c.front9b7060()==kc_c36f58){
    KcArea2 r;
    kc_cfd44c.getRect9b4430(a1->getPosition(),1,r);
    KcPos p;
    for(int x=r.x1;x<=r.x2;x++)
     for(int y=r.y1;y<=r.y2;y++){
      p.set40a010(x,y);
      p.sub409a30(scroll);
      if(inBounds4173d0(p))setBack417fc0(p.x,p.y,*kc_d30424*kc_c36eb4,true);
     }
   }else{
    int period=20;
    int k0=kc_caed20-td4;
    int dB=kc_d28e6a?k0/period:10000;
    int frac=k0%period;
    int loA;
    kc_lookup9d45a0("CMap_Volley_Front",loA);
    KcVF&vols=kc_cec084->v8c;
    int m14=vols.size9b9260()-1;
    KcPos pp=a1->getPosition();
    KcGridI2*d_=kc_cefc4c->p6e8;
    int e4=kc_cefc4c->p6e8->i0c;
    int k4;
    for(int y=from3.y,e27=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&e27<kc_cf27f8;y++,e27++){
     int dy=abs(pp.y-y);
     float f=dy<dB?1.0:(dy==dB?(double)frac/period:0.0);
     if(f==0)continue;
     bool c7=dy==dB;
     for(int m27=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);m27<=toN.x&&sx<kc_cf27f4;m27++,sx++){
      if(*d_->at9ceda0(m27,y)==e4){
       k4=kc_distance406480(pp.x,pp.y,m27,y);
       if(k4<=m14){
        setBack417fc0(sx,e27,*kc_d30424*(float)(vols.at9b81f0(k4)*kc_c36cc0+kc_c36de8)*f,true);
        if(c7&&loA)kc_cefc64->new50fb50()->init50de10(kc_cefc64,loA,KcPos(sx,e27),kc_cfbec0,0,0,9);
       }
      }
     }
    }
   }
  }
  if(bec){
   KcPos a3;
   KcPos q6;
   int slack=a1->u5d2150(0x1e,0);
   KcColor bA(0x20,0,0);
   KcColor cB(0x10,0,0);
   const int dur=400;
   int r4;
   int d;
   if(a0&&(!kc_cefa94->u41a6e0()||i680==8)&&*aVisible->atPoint9ced70(a2)!=0&&kc_cfd44c.atPoint9ced70(a2)[0]->getEntity().isValid()&&kc_cfd44c.atPoint9ced70(a2)[0]->getEntity()!=a1){
    KcHE e=kc_cfd44c.atPoint9ced70(a2)[0]->getEntity();
    KcVPos&aW=e->u45d1a0();
    KcVPos&cells2=e->u45d1a0();
    r4=e->u5c7d30();
    KcColor a4(0x20,0x20,0x20);
    KcColor c2(0x10,0x10,0x10);
    KcColor c3(0,0x20,0);
    KcColor a5(0,0x10,0);
    KcColor c5;
    KcColor*pA;
    KcColor*aR;
    switch(a1->rel5c7fc0(e)){
    case 0:pA=&bA;aR=&cB;c5=*kc_d02da4;break;
    case 1:pA=&a4;aR=&c2;c5=*kc_cefd50;break;
    case 2:pA=&c3;aR=&a5;c5=*kc_cf63b4;break;
    }
    if(e!=hf4){tf0=kc_caed20;hf4=e;}
    unsigned bD=kc_caed20-tf0;
    if(bD<dur){
     float s=1.0f+(1.0f-1.0f*sin((float)(bD*kc_c36e68/kc_c37068)));
     *pA*=s;
     *aR*=s;
    }
    KcBox4 bB(kc_maxInt9cdb60(from3.x,aW.at9e7c10(0).x-r4),kc_maxInt9cdb60(from3.y,aW.at9e7c10(0).y-r4),kc_minInt9cdb30(toN.x,aW.back9e8c10().x+r4),kc_minInt9cdb30(toN.y,aW.back9e8c10().y+r4));
    for(int y=bB.y1,e30=bB.y1+scroll.y;y<=bB.y2&&e30<kc_cf27f8;y++,e30++)
     for(int m31=bB.x1,sx=bB.x1+scroll.x;m31<=bB.x2&&sx<kc_cf27f4;m31++,sx++){
      if(*aVisible->at9ceda0(m31,y)!=0){
       a3.set40a010(m31,y);
       for(unsigned i=0;i<cells2.size9b9a50();i++){
        d=kc_distance40a3f0(cells2.at9e7c10(i),a3);
        if(d<=r4&&kc_cefc4c->isReachable465230(r4,cells2.at9e7c10(i),a3)){
         if(d<=r4-slack)setBack417fc0(sx,e30,*pA,true);
         else if(getBack(sx,e30)!=*pA)setBack417fc0(sx,e30,*aR,true);
        }
       }
      }
     }
    for(unsigned i=0;i<aW.size9b9a50();i++){
     if(*aVisible->atPoint9ced70(aW.at9e7c10(i))!=0){
      q6.set40a010(aW.at9e7c10(i).x+scroll.x,aW.at9e7c10(i).y+scroll.y);
      setBack417fc0(q6.x,q6.y,KcColor::addAlpha(getBack(q6.x,q6.y),c5,kc_pulse4371a0(kc_ba6af8,kc_ba6afc,1000,0)),true);
     }
    }
   }else{
    hf4.reset9b7270();
    unsigned el2=kc_caed20-tf0;
    if(el2<dur){
     float s2=1.0f+(1.0f-1.0f*sin((float)(el2*kc_c36e68/kc_c37068)));
     bA*=s2;
     cB*=s2;
    }
    KcHE m34;
    KcVHX ents5;
    KcVInt m38;
    KcVVP paths;
    for(int x=0;x<aVisible->width9fcd80();x++)
     for(int y=0;y<aVisible->height9b8f00();y++){
      if(*aVisible->at9ceda0(x,y)!=0&&CELL(x,y)->getEntity().isValid()){
       m34=CELL(x,y)->getEntity();
       if(m34->isHostileTo(a1)&&m34->getTarget()<6&&kc_addUnique9d30e0(ents5,m34)){
        m38.push_back9b9280(m34->u5c7d30());
        paths.push_back9b5610(KcVPos(m34->u45d1a0()));
       }
      }
     }
    if(!ents5.empty9b86e0()){
     for(int y=from3.y,e37=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&e37<kc_cf27f8;y++,e37++)for(int m51=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);m51<=toN.x&&sx<kc_cf27f4;m51++,sx++){
      if(*aVisible->at9ceda0(m51,y)!=0){
       a3.set40a010(m51,y);
       for(unsigned i=0;i<ents5.size9b9260();i++)
        for(unsigned j=0;j<paths.at9b8070(i).size9b9a50();j++){
         d=kc_distance40a3f0(paths.at9b8070(i).at9e7c10(j),a3);
         if(d<=m38.at9b81f0(i)&&kc_cefc4c->isReachable465230(m38.at9b81f0(i),paths.at9b8070(i).at9e7c10(j),a3)){
          if(d<=m38.at9b81f0(i)-slack){setBack417fc0(sx,e37,bA,true);break;}
          else if(getBack(sx,e37)!=bA)setBack417fc0(sx,e37,cB,true);
         }
        }
      }
     }
     for(unsigned i=0;i<ents5.size9b9260();i++){
      KcVPos&cs=ents5.at9b81f0(i)->u45d1a0();
      for(unsigned j=0;j<cs.size9b9a50();j++){
       if(cs.at9e7c10(j).eq409bd0(a2)){
        q6.set40a010(cs.at9e7c10(j).x+scroll.x,cs.at9e7c10(j).y+scroll.y);
        if(inBounds4173d0(q6))setBack417fc0(q6.x,q6.y,KcColor::addAlpha(getBack(q6.x,q6.y),*kc_d02da4,kc_pulse4371a0(kc_ba6af8,kc_ba6afc,1000,0)),true);
       }
      }
     }
    }
   }
  }
  if(bd8){
   if(!a0){
    if(pe0){removeSubconsole428b20(pe0);pe0=0;}
    pe4.set409ff0(-1);
   }else{
    if(pe4.eq409bd0(a2)){
     pe4=a2;
     if(pe0){removeSubconsole428b20(pe0);pe0=0;}
     pe0=new KcSubCon(this,width44b0d0()*kc_caf128,getHeight4174c0()*kc_caf12c,0,0,kc_d28d15?1:0,false,-1);
    }
    pe0->setBgColor418410(kc_d29804);
    int vStep=10;
    int el=kc_caed20-tdc;
    int curCur=el/vStep;
    int e6;
    kc_lookup9d45a0("CMap_Ruler_Unknown",e6);
    int fxB;
    kc_lookup9d45a0("CMap_Ruler_Unknown_10",fxB);
    int e7=2;
    int tail=6;
    float eB=kc_c3713c;
    KcColor g0;
    int r6;
    int cX;
    float as;
    for(int myY=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);myY<=toN.x&&sx<kc_cf27f4;myY++,sx++)
     for(int y=from3.y,e50=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&e50<kc_cf27f8;y++,e50++){
      r6=kc_distance40a3f0(pe4,KcPos(myY,y));
      if(r6==0||r6>99)pe0->setBackRow429c20(sx*2,e50,2,*kc_d20cfc);
      else{
       if(r6==curCur)as=eB;
       else if(r6<curCur&&r6>=curCur-tail)as=eB-sin((float)((double)(r6-curCur)/tail*kc_c36e68))*eB;
       else if(r6>curCur&&r6<=curCur-e7)as=eB-sin((float)((double)(curCur-r6)/e7*kc_c36e68))*eB;
       else as=1;
       if(getFore(sx,e50)!=getBack(sx,e50)){
        bool ten=!(r6%10);
        cX=r6;
        if(!ten)cX=cX%10;
        if(r6<=curCur+e7){
         pe0->print4181d0(sx*2,e50,kc_padRight4080d0(kc_intToString4051f0(cX),2,0x20));
         if(ten)g0=*kc_d1ecd4;
         else{g0=getFore(sx,e50);g0*=as;}
         pe0->setForeRow429a30(sx*2,e50,2,g0);
         g0=getBack(sx,e50);
         pe0->setBackRow429c20(sx*2,e50,2,g0);
        }else pe0->setBackRow429c20(sx*2,e50,2,*kc_d20cfc);
       }else{
        bool ten2=!(r6%10);
        cX=r6;
        if(!ten2)cX=cX%10;
        pe0->print4181d0(sx*2,e50,kc_padRight4080d0(kc_intToString4051f0(cX),2,0x20));
        g0=ten2?KcColor(0x23,0x23,0x23):KcColor(0x19,0x19,0x19);
        pe0->setBackRow429c20(sx*2,e50,2,g0);
        if(el<40){
         pe0->engine64->new50fb50()->init50de10(pe0->engine64,ten2?fxB:e6,KcPos(sx*2,e50),kc_cfbec0,0,0,9);
         pe0->engine64->new50fb50()->init50de10(pe0->engine64,ten2?fxB:e6,KcPos(sx*2+1,e50),kc_cfbec0,0,0,9);
        }
       }
      }
     }
   }
  }
  else if(pe0){removeSubconsole428b20(pe0);pe0=0;}
  if(!kc_cefc4c->v800.empty9b86e0()){
   KcVBeam&beams=kc_cefc4c->v800;
   float ex8=kc_c37138;
   KcColor u0(*kc_cf6ed4);
   KcColor cHead(*kc_d30424);
   float maxW=kc_c36e30;
   for(unsigned i=0;i<beams.size9b9260();i++){
    if(beams.at9b81f0(i)->t30!=0&&kc_caed20<beams.at9b81f0(i)->t30+ex8){
     float f=(ex8-(kc_caed20-beams.at9b81f0(i)->t30))/ex8;
     for(unsigned j=0;j<beams.at9b81f0(i)->v10.size9b9a50();j++){
      KcPos p=beams.at9b81f0(i)->v10.at9e7c10(j);
      p.sub409a30(scroll);
      if(inBounds4173d0(p)){
       bool head=j==beams.at9b81f0(i)->v10.size9b9a50()-1;
       setBack417fc0(p.x,p.y,(head?cHead:u0)*(head?1.0:beams.at9b81f0(i)->v20.at9b81f0(j)/maxW)*f,true);
      }
     }
    }
   }
  }
  if(!kc_cefc4c->v81c.empty9b86e0()){
   const int period=1500;
   if(kc_blink437320(period)){
    KcVEnt&es=kc_cefc4c->v81c;
    for(unsigned i=0;i<es.size9b9260();i++){
     if(!es.at9b81f0(i).operator->()||!kc_cefc4c->u4631f0(es.at9b81f0(i))){kc_eraseStep9d6440(es,i);continue;}
     KcVPos&path=es.at9b81f0(i)->ai45b590()->u4549b0();
     KcColor c(*kc_d22fcc);
     const int maxLen=8;
     int speed=es.at9b81f0(i)->u5d15a0(0);
     int stepT=800/speed;
     int n5=kc_minInt9cdb30(path.size9b9a50(),stepT);
     for(int k=0;k<n5;k++){
      if(!kc_cefc4c->isVisible4631c0(path.at9e7c10(k)))break;
      KcPos p=path.at9e7c10(k);
      p.sub409a30(scroll);
      if(inBounds4173d0(p))setBack417fc0(p.x,p.y,KcColor::addAlpha(BGP(p),c,(float)(kc_c37130-kc_caed20%period)/kc_c37130),true);
     }
    }
   }
  }
  for(unsigned i=0;i<kc_cefc4c->va30.size9b9260();i++)kc_cefc4c->va30.at9b81f0(i)->v3();
  kc_cefc50->u5088e0();
  if(kc_cefc4c->u715a70()){
   KcPos mp(-1);
   if(kc_cfd44c.atPoint9ced70(a1->getPosition())[0]->isMachinePart45dcd0())mp=a1->getPosition();
   else{
    KcVPos around;
    kc_surrounding4faaf0(a1->getPosition(),around);
    for(unsigned i=0;i<around.size9b9a50();i++)
     if(kc_cfd44c.atPoint9ced70(around.at9e7c10(i))[0]->isMachinePart45dcd0()){mp=around.at9e7c10(i);break;}
   }
   if(mp.x!=-1){
    float lo=kc_cefb3c?kc_ba6b6c*kc_c37150:kc_ba6b6c;
    float hi=kc_cefb3c?kc_ba6b70*kc_c37150:kc_ba6b70;
    KcArea2 r;
    kc_cfd44c.getRect9b4430(mp,7,r);
    KcPos p5;
    for(int x=r.x1;x<=r.x2;x++)
     for(int y=r.y1;y<=r.y2;y++)
      if(*kc_cefc4c->known.at9cec50(x,y)&&CELL(x,y)->isPassable66ab30(KcHE())&&kc_distance406480(mp.x,mp.y,x,y)<=7){
       p5.set40a010(x,y);
       p5.sub409a30(scroll);
       if(inBounds4173d0(p5))setBack417fc0(p5.x,p5.y,KcColor::addAlpha(BGP(p5),*kc_d2d1d4,kc_pulse4371a0(lo,hi,2000,0)),true);
      }
   }
  }
{  KcColor tint(*kc_cfe674);
  if(kc_cf4a00)tint=*kc_cf0c8c;
  else if(kc_d255ac)tint=*kc_cf44ac;
  else if(kc_d1e860.isFlag46fb60())tint=*kc_d32970;
  if(tint!=*kc_cfe674){
   float hi2=kc_cefb3c?kc_ba6b50*kc_c36ce8:kc_ba6b50;
   KcPos pp=a1->getPosition();
   KcPos p7;
   for(unsigned i=0;i<kc_d3862c.size9b9a50();i++){
    p7=pp.add409b60(kc_d3862c.at9e7c10(i)).add409b60(scroll);
    if(inBounds4173d0(p7))setBack417fc0(p7.x,p7.y,KcColor::addAlpha(BGP(p7),tint,kc_pulse4371a0(kc_ba6b4c,hi2,2000,0)),true);
   }
  }}
  if(kc_cf4ac8&&kc_cf4ac8->check7abf80()){
   float nLo=kc_cefb3c?kc_ba6b50*kc_c36ce8:kc_ba6b50;
   KcPos pp=a1->getPosition();
   KcPos p9;
   for(unsigned i=0;i<kc_d31da4.size9b9a50();i++){
    p9=pp.add409b60(kc_d31da4.at9e7c10(i)).add409b60(scroll);
    if(inBounds4173d0(p9))setBack417fc0(p9.x,p9.y,KcColor::addAlpha(BGP(p9),*kc_cf45d0,kc_pulse4371a0(kc_ba6b4c,nLo,2000,0)),true);
   }
  }
  if(kc_cf4a70!=-1&&kc_cefc4c->player->item5d2380(0xd9).isValid()){
   float ok5=kc_cefb3c?kc_ba6b58*kc_c36ce8:kc_ba6b58;
   KcPos pp=a1->getPosition();
   KcPos gA;
   for(unsigned i=0;i<kc_d2d28c.size9b9a50();i++){
    gA=pp.add409b60(kc_d2d28c.at9e7c10(i)).add409b60(scroll);
    if(inBounds4173d0(gA)){
     KcColor c=kc_cf4a90!=0x168&&kc_angleInArc4065d0(kc_cf4a94,kc_cf4a90,(int)kc_angle40a680(pp,pp.add409b60(kc_d2d28c.at9e7c10(i))))?*kc_d2d288:*kc_cf1b0c;
     if(kc_cf4a70<=kc_cf4a74&&kc_blink437320(1000))c*=kc_c37144;
     setBack417fc0(gA.x,gA.y,KcColor::addAlpha(BGP(gA),c,kc_pulse4371a0(kc_ba6b54,ok5,2000,0)),true);
    }
   }
  }
  if(kc_d1e860.u789580(KcHE())){
   float old=kc_cefb3c?kc_ba6b50*kc_c36ce8:kc_ba6b50;
   KcPos pp=a1->getPosition();
   KcPos gC;
   for(unsigned i=0;i<kc_d2a8a0.size9b9a50();i++){
    gC=pp.add409b60(kc_d2a8a0.at9e7c10(i)).add409b60(scroll);
    if(inBounds4173d0(gC))setBack417fc0(gC.x,gC.y,KcColor::addAlpha(BGP(gC),*kc_cefcf8,kc_pulse4371a0(kc_ba6b4c,old,2000,0)),true);
   }
  }
  if(kc_cf4a04.at9b81f0(11)!=0&&kc_cefc4c->player->u5d4100()){
   float pTo=kc_cefb3c?kc_ba6b50*kc_c36ce8:kc_ba6b50;
   KcPos pp=a1->getPosition();
   KcPos gD;
   for(unsigned i=0;i<kc_d01bd8.size9b9a50();i++){
    gD=pp.add409b60(kc_d01bd8.at9e7c10(i)).add409b60(scroll);
    if(inBounds4173d0(gD))setBack417fc0(gD.x,gD.y,KcColor::addAlpha(BGP(gD),*kc_d01a44,kc_pulse4371a0(kc_ba6b4c,pTo,2000,0)),true);
   }
  }
  if(kc_cf4a04.at9b81f0(12)!=0||kc_d1e888->b60){
   bool flag=kc_d1e888->b60;
   for(unsigned i=0;i<kc_cf6478.size9b9260();i++){
    if(kc_cf6478.at9b81f0(i)->type==2&&!kc_cf6478.at9b81f0(i)->u45e820()){
     KcVPos&path=kc_cf6478.at9b81f0(i)->h4->ai45b590()->u4549b0();
     if(!path.empty9b86e0()&&(flag||kc_distance40a3f0(kc_cefc4c->getPlayer4630f0()->getPosition(),kc_cf6478.at9b81f0(i)->h4->getPosition())<=24&&kc_cf6478.at9b81f0(i)->h4->ai45b590()->u4595f0()&&kc_cefc4c->getPlayer4630f0()->u5d4490(kc_cf6478.at9b81f0(i)->h4))){
      bool aim=u8050a0();
      const int on=2000;
      const int off=3000;
      const int q12=5000;
      if(kc_caed20%q12>on||!aim){
       unsigned tVal=kc_caed20%q12-on;
       KcColor c;
       c=*kc_cf44c4;
       if(aim)c*=1.0f*sin((float)(tVal/kc_c36f30*kc_c36c98));
       KcPos p;
       for(unsigned j=0;j<path.size9b9a50();j++){
        p=path.at9e7c10(j).add409b60(scroll);
        if(inBounds4173d0(p))setBack417fc0(p.x,p.y,c,true);
       }
      }
     }
    }
   }
  }
  if(kc_cf64fc.operator->()&&(kc_cefc4c->getPlayer4630f0()->item5d2380(0x16).isValid()||kc_cefc4c->getPlayer4630f0()->item5d2380(0x17).isValid()||kc_cf4718==2)&&kc_cf64fc->getGroup()->type9b4350()==3){
   KcVPos&path=kc_cf64fc->ai45b590()->u4549b0();
   if(!path.empty9b86e0()){
    bool b3=u8050a0();
    const int on2=2000;
    const int off2=3000;
    const int q42=5000;
    if(kc_caed20%q42>on2||!b3){
     unsigned t2=kc_caed20%q42-on2;
     KcColor c2(*kc_cf6ed4);
     if(b3)c2*=1.0f*sin((float)(t2/kc_c36f30*kc_c36c98));
     KcPos p2;
     for(unsigned j=0;j<path.size9b9a50();j++){
      p2=path.at9e7c10(j).add409b60(scroll);
      if(inBounds4173d0(p2))setBack417fc0(p2.x,p2.y,c2,true);
     }
    }
   }
  }
  if(kc_cf462c==10&&kc_cefc4c->u464040().operator->()&&(kc_cefc4c->getPlayer4630f0()->item5d2380(0x16).isValid()||kc_cefc4c->getPlayer4630f0()->item5d2380(0x17).isValid())&&kc_cefc4c->u464040()->getGroup()->type9b4350()==3){
   KcVPos&path=kc_cefc4c->u464040()->ai45b590()->u4549b0();
   if(!path.empty9b86e0()){
    bool aim3=u8050a0();
    const int on3=2000;
    const int q48=3000;
    const int q49=5000;
    if(kc_caed20%q49>on3||!aim3){
     unsigned rb1=kc_caed20%q49-on3;
     KcColor c3(*kc_cf44c4);
     if(aim3)c3*=1.0f*sin((float)(rb1/kc_c36f30*kc_c36c98));
     KcPos rb4;
     for(unsigned j=0;j<path.size9b9a50();j++){
      rb4=path.at9e7c10(j).add409b60(scroll);
      if(inBounds4173d0(rb4))setBack417fc0(rb4.x,rb4.y,c3,true);
     }
    }
   }
  }
  if(kc_d28e69&&!v100.empty9b86e0()){
   float hi7=kc_cefb3c?kc_ba6b50*kc_c36ce8:kc_ba6b50;
   for(unsigned i=0;i<v100.size9b9a50();i++)
    if(inBounds4173d0(v100.at9e7c10(i)))setBack417fc0(v100.at9e7c10(i).x,v100.at9e7c10(i).y,KcColor::addAlpha(BGP(v100.at9e7c10(i)),*kc_d29014,kc_pulse4371a0(kc_ba6b4c,hi7,2000,0)),true);
  }
  if(kc_d1e888->type!=0xd){
   if(kc_d28e83){
    KcVEnt&es=kc_cefc4c->v594;
    for(unsigned i=0;i<es.size9b9260();i++){
     if(es.at9b81f0(i).operator->()&&es.at9b81f0(i)->getGroup()->type9b4350()==3){
      bool seen=*aVisible->atPoint9ced70(es.at9b81f0(i)->getPosition());
      if(!seen){
       KcArea2 r;
       kc_cfd44c.getRect9b4430(es.at9b81f0(i)->getPosition(),1,r);
       for(int x=r.x1;x<=r.x2;x++)
        for(int y=r.y1;y<=r.y2;y++)
         if(kc_cefc4c->a740.at9cdf20(x,y)->a==kc_cefc4c->i74c&&kc_cefc4c->a740.at9cdf20(x,y)->h8==es.at9b81f0(i)){seen=true;goto found;}
      }
      found:
      if(seen){
       KcVPos area;
       u808510(es.at9b81f0(i)->getPosition().add409b60(scroll),0x14,area);
       float hi8=kc_cefb3c?kc_ba6b50*kc_c36ce8:kc_ba6b50;
       for(unsigned j=0;j<area.size9b9a50();j++)
        if(inBounds4173d0(area.at9e7c10(j)))setBack417fc0(area.at9e7c10(j).x,area.at9e7c10(j).y,KcColor::addAlpha(BGP(area.at9e7c10(j)),*kc_d33d8c,kc_pulse4371a0(kc_ba6b4c,hi8,2000,0)),true);
      }
     }
    }
   }else if(a0){
    KcHE tgt;
    if(*aVisible->atPoint9ced70(a2)!=0&&kc_cfd44c.atPoint9ced70(a2)[0]->getEntity().isValid()&&kc_cfd44c.atPoint9ced70(a2)[0]->getEntity()->getFaction()==0x1a&&kc_cfd44c.atPoint9ced70(a2)[0]->getEntity()->getGroup()->type9b4350()==3)tgt=kc_cfd44c.atPoint9ced70(a2)[0]->getEntity();
    else if(kc_cefc4c->a740.atPoint9d2930(a2)->a==kc_cefc4c->i74c&&kc_cefc4c->a740.atPoint9d2930(a2)->h8.operator->()&&kc_cefc4c->a740.atPoint9d2930(a2)->h8->getFaction()==0x1a&&kc_cefc4c->a740.atPoint9d2930(a2)->h8->getGroup()->type9b4350()==3)tgt=kc_cefc4c->a740.atPoint9d2930(a2)->h8;
    if(tgt.isValid()){
     if(tf8==0)tf8=kc_caed20;
     else if(kc_caed20-tf8>=1000){
      KcVPos area2;
      u808510(a2.add409b60(scroll),0x14,area2);
      float hi9=kc_cefb3c?kc_ba6b50*kc_c36ce8:kc_ba6b50;
      for(unsigned j=0;j<area2.size9b9a50();j++)
       if(inBounds4173d0(area2.at9e7c10(j)))setBack417fc0(area2.at9e7c10(j).x,area2.at9e7c10(j).y,KcColor::addAlpha(BGP(area2.at9e7c10(j)),*kc_d33d8c,kc_pulse4371a0(kc_ba6b4c,hi9,2000,0)),true);
     }
    }else tf8=0;
   }
  }
  if(!v124.empty9b86e0()){
   for(unsigned i=0;i<v124.size9b9260();i++){
    int rc1=v124.at9b81f0(i)->bc?500:500;
    int age=kc_caed20-v124.at9b81f0(i)->t8;
    if(age>=rc1)kc_delStep9de640(v124,i);
    else{
     float fade=kc_fade437250(1.0f,v124.at9b81f0(i)->t8,rc1);
     int base1=v124.at9b81f0(i)->bc?10:15;
     int radius=(int)(base1-base1*fade);
     KcVPos rd9;
     u808510(v124.at9b81f0(i)->pos.add409b60(scroll),radius,rd9);
     KcColor re9=(v124.at9b81f0(i)->bc?*kc_cf273c:*kc_d22fb8)*fade;
     for(unsigned j=0;j<rd9.size9b9a50();j++)
      if(inBounds4173d0(rd9.at9e7c10(j)))setBack417fc0(rd9.at9e7c10(j).x,rd9.at9e7c10(j).y,re9,true);
    }
   }
  }
  if(!v31c.empty9b86e0()){
   for(unsigned i=0;i<v31c.size9b9260();i++){
    if(kc_caed20>v31c.at9b81f0(i)->tc+2000)kc_delStep9de640(v31c,i);
    else{
     if(v31c.at9b81f0(i)->h0.operator->()&&kc_cefc4c->u4631f0(v31c.at9b81f0(i)->h0))v31c.at9b81f0(i)->p4=v31c.at9b81f0(i)->h0->getPosition();
     if(kc_blink437320(250)){
      KcPos p=v31c.at9b81f0(i)->p4.add409b60(scroll);
      if(inBounds4173d0(p))putChar418150(p.x,p.y,0x21,*kc_cfe674,*kc_d306ac,true);
     }
    }
   }
  }
  if(!v32c.empty9b86e0()){
   const int rh3=750;
   const int grow=500;
   for(unsigned i=0;i<v32c.size9b9260();i++){
    KcColor&cIn=v32c.at9b81f0(i)->bc?*kc_d204ac:*kc_d20438;
    KcColor&d9=v32c.at9b81f0(i)->bc?*kc_d2f34c:*kc_cf281c;
    int age=kc_caed20-v32c.at9b81f0(i)->t10;
    if(age>=rh3)kc_delStep9de640(v32c,i);
    else{
     float d2=(float)v32c.at9b81f0(i)->i8;
     if(age<grow){
      float aY=kc_fade437250(1.0f,v32c.at9b81f0(i)->t10,grow);
      int b1=(int)(d2-d2*aY);
      KcVPos ring;
      u808510(v32c.at9b81f0(i)->pos.add409b60(scroll),b1,ring);
      KcColor c=d9*aY;
      for(unsigned j=0;j<ring.size9b9a50();j++)
       if(inBounds4173d0(ring.at9e7c10(j)))setBack417fc0(ring.at9e7c10(j).x,ring.at9e7c10(j).y,c,true);
     }
     float g=kc_pulse437200(0.0f,1.0f,rh3,v32c.at9b81f0(i)->t10);
     KcVPos disc;
     u808510(v32c.at9b81f0(i)->pos.add409b60(scroll),(int)d2,disc);
     KcColor c2=cIn*g;
     for(unsigned j=0;j<disc.size9b9a50();j++)
      if(inBounds4173d0(disc.at9e7c10(j)))setBack417fc0(disc.at9e7c10(j).x,disc.at9e7c10(j).y,c2,true);
    }
   }
  }
  if(!v35c.empty9b86e0()){
   const int life2=750;
   const int grow2=500;
   KcColor&baseTmp=*kc_cf281c;
   for(unsigned i=0;i<v35c.size9b9260();i++){
    int age=kc_caed20-v35c.at9b81f0(i)->tc;
    if(age>=life2)kc_delStep9de640(v35c,i);
    else{
     const KcPos&c=v35c.at9b81f0(i)->pos.add409b60(scroll);
     int r=v35c.at9b81f0(i)->i8;
     float jA=kc_pulse437200(0.0f,1.0f,life2,v35c.at9b81f0(i)->tc);
     KcVPos ring5;
     u808510(c,r,ring5);
     KcColor col=baseTmp*jA;
     for(unsigned j=0;j<ring5.size9b9a50();j++)
      if(inBounds4173d0(ring5.at9e7c10(j)))setBack417fc0(ring5.at9e7c10(j).x,ring5.at9e7c10(j).y,col,true);
     if(age<grow2){
      jA=kc_pulse437200(0.0f,1.0f,grow2,v35c.at9b81f0(i)->tc);
      col=baseTmp*jA;
      r--;
      for(int x=c.x-r;x<=c.x+r;x++)
       if(inBounds417360(x,c.y))setBack417fc0(x,c.y,col,true);
      for(int y=c.y-r;y<=c.y+r;y++)
       if(inBounds417360(c.x,y))setBack417fc0(c.x,y,col,true);
     }
    }
   }
  }
  if(t398){
   const int rj5=500;
   int age=kc_caed20-t398;
   if(age>=rj5){
    t398=0;
    for(unsigned i=0;i<v3b8.size9b9260();i++)
     if(v3b8.at9b81f0(i)==0)v3b8.at9b81f0(i)=kc_caed20;
   }else{
    float maxR=kc_c36fec;
    KcColor&col=*kc_d35be0;
    float f=kc_fade437250(1.0f,t398,rj5);
    int ex9=(int)(maxR-maxR*f);
    KcVPos ring2;
    u808510(p39c.add409b60(scroll),ex9,ring2);
    KcColor to8=col*f;
    for(unsigned j=0;j<ring2.size9b9a50();j++)
     if(inBounds4173d0(ring2.at9e7c10(j))){
      setChar417f50(ring2.at9e7c10(j).x,ring2.at9e7c10(j).y,0x2e);
      setBack417fc0(ring2.at9e7c10(j).x,ring2.at9e7c10(j).y,to8,true);
     }
    for(unsigned k=0;k<v3b8.size9b9260();k++)
     if(v3b8.at9b81f0(k)==0&&kc_distance40a3f0(p39c,v3a8.at9e7c10(k))<=ex9){
      v3b8.at9b81f0(k)=kc_caed20;
      kc_sound4541b0(0x130,0,0);
     }
   }
  }
  if(!v3c8.empty9b86e0()){
   const int step=20;
   if(kc_caed20>=t3dc+step){
    unsigned el=kc_caed20-t3dc;
    int n=el/step*i3d8;
    t3dc=kc_caed20-el%step;
    if(n!=0){
     if(n>v3c8.size9b9a50())n=v3c8.size9b9a50();
     int fxK=0;
     kc_lookup9d45a0(b3e0?"CMap_MAP_WALLS_Known":"CMap_MAP_EARTH_Known",fxK);
     int tos=0;
     kc_lookup9d45a0(b3e0?"CMap_MAP_WALLS_Unknown":"CMap_MAP_EARTH_Unknown",tos);
     for(int i=0;i<n;i++){
      if(kc_cfd44c.atPoint9ced70(v3c8.at9e7c10(i))[0]->isShortcut45dc50()){
       kc_cefc4c->u734d60(v3c8.at9e7c10(i));
       labelAccess80e3a0(1,v3c8.at9e7c10(i));
      }
      kc_cefc4c->u4647a0(v3c8.at9e7c10(i),1);
      int fx=aH->at9d2770(v3c8.at9e7c10(i))?fxK:tos;
      v3c8.at9e7c10(i).sub409a30(scroll);
      if(inBounds4173d0(v3c8.at9e7c10(i)))kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,v3c8.at9e7c10(i),kc_cfbec0,0,0,9);
     }
     kc_eraseRange9d53f0(v3c8,0,n-1);
    }
   }
  }
  if(!v404.empty9b86e0()){
   const int step3=100;
   if(kc_caed20>=t41c+step3){
    unsigned el3=kc_caed20-t41c;
    int h2=el3/step3*i418;
    t41c=kc_caed20-el3%step3;
    int fxKnown=0;
    kc_lookup9d45a0("CMap_MAP_ROUTE_Known",fxKnown);
    int u10=0;
    kc_lookup9d45a0("CMap_MAP_ROUTE_Unknown",u10);
    int e2=0;
    kc_lookup9d45a0("CMap_MAP_ROUTE_Box",e2);
    int u20=0;
    kc_lookup9d45a0("CMap_MAP_ROUTE_Node",u20);
    const int radius9=12;
    while(h2!=0){
     for(unsigned i=0;i<v3e4.size9b5100();i++){
      if(v404.at9b81f0(i)==i414){
       KcArea2&box=v3e4.at9b8070(i);
       kc_clearDijkstra4faf40();
       kc_cfe568.u40ca20(v3f4.at9e7c10(i),radius9,&kc_d2f210,0);
       for(unsigned j=0;j<kc_d15e58.size9b9a50();j++){
        if(box.contains40b750(kc_d15e58.at9e7c10(j))){
         if(kc_cfd44c.atPoint9ced70(kc_d15e58.at9e7c10(j))[0]->isShortcut45dc50()){
          kc_cefc4c->u734d60(kc_d15e58.at9e7c10(j));
          labelAccess80e3a0(1,kc_d15e58.at9e7c10(j));
         }
         if(!aH->at9d2770(kc_d15e58.at9e7c10(j))&&kc_cfd44c.atPoint9ced70(kc_d15e58.at9e7c10(j))[0]->isMachinePart45dcd0()){
          KcZone*z=kc_cefc4c->getZone462e30(kc_d15e58.at9e7c10(j));
          if(kc_cf4718==2)kc_cefc4c->announce71dd30(z->i8);
          z->bd=true;
          z->u6c16d0("FOUND");
          labelAccess80e3a0(1,kc_d15e58.at9e7c10(j));
         }
         kc_cefc4c->u4647d0(kc_d15e58.at9e7c10(j));
         int fx=aH->at9d2770(kc_d15e58.at9e7c10(j))?fxKnown:u10;
         kc_d15e58.at9e7c10(j).sub409a30(scroll);
         if(inBounds4173d0(kc_d15e58.at9e7c10(j)))kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,kc_d15e58.at9e7c10(j),kc_cfbec0,0,0,9);
        }
       }
       KcVPos up7;
       KcArea2 b2(box);
       ((KcPos*)&b2.x1)->sub409a30(scroll);
       ((KcPos*)&b2.x2)->sub409a30(scroll);
       b2.getBorder40bac0(up7);
       for(unsigned k=0;k<up7.size9b9a50();k++)
        if(inBounds4173d0(up7.at9e7c10(k)))kc_cefc64->new50fb50()->init50de10(kc_cefc64,e2,up7.at9e7c10(k),kc_cfbec0,0,0,9);
       if(inBounds4173d0(v3f4.at9e7c10(i).add409b60(scroll)))kc_cefc64->new50fb50()->init50de10(kc_cefc64,u20,v3f4.at9e7c10(i).add409b60(scroll),kc_cfbec0,0,0,9);
      }
     }
     h2--;
     i414++;
     if(i414>v404.back9b6540()){
      v3e4.clear9b4710();
      v3f4.clear9b3560();
      v404.clear9bac80();
      break;
     }
    }
   }
  }
  if(!v420.empty9b86e0()){
   const int step4=20;
   if(kc_caed20>=t450+step4){
    unsigned el4=kc_caed20-t450;
    for(unsigned i=0;i<v420.size9b9260();i++){
     int adv=el4/step4*v430.at9b81f0(i);
     t450=kc_caed20-el4%step4;
     v440.at9b81f0(i)+=adv;
    }
   }
   KcPos c_;
   for(unsigned i=0;i<v420.size9b9260();i++){
    if(v430.at9b81f0(i)!=0){
     KcColor k1;
     KcColor head;
     switch(v420.at9b81f0(i)->type){
     case 13:k1=*kc_cfd4cc;head=*kc_d21b44;break;
     case 16:case 17:case 18:k1=*kc_cfd4cc;head=*kc_d21b44;break;
     case 24:k1=*kc_cf6ed4;head=*kc_d35bbc;break;
     case 25:k1=*kc_d2175c;head=*kc_d25f60;break;
     default:k1=*kc_d22fcc;head=*kc_d35be0;break;
     }
     KcVPos&path=v420.at9b81f0(i)->v4;
     for(int j=0;j<v440.at9b81f0(i)&&j<path.size9b9a50();j++){
      c_=path.at9e7c10(j).add409b60(scroll);
      if(inBounds4173d0(c_))setBack417fc0(c_.x,c_.y,k1,true);
     }
     if(v440.at9b81f0(i)<path.size9b9a50()){
      c_=path.at9e7c10(v440.at9b81f0(i)).add409b60(scroll);
      if(inBounds4173d0(c_))setBack417fc0(c_.x,c_.y,head,true);
     }
     if(v440.at9b81f0(i)>=path.size9b9a50())v430.at9b81f0(i)=0;
    }
   }
   if(!kc_anyPositive9d54c0(v430)){
    v420.clear9bac80();
    v430.clear9bac80();
    v440.clear9bac80();
    t454=kc_caed20;
   }
  }else if(!kc_cefc4c->u463df0().empty9b86e0()){
   if(!u8050a0()){
    KcPos p;
    KcV420&upX=kc_cefc4c->u463df0();
    for(unsigned i=0;i<upX.size9b9260();i++){
     KcColor c;
     switch(upX.at9b81f0(i)->type){
     case 13:c=*kc_cf44c4;break;
     case 16:case 17:case 18:c=*kc_cfd4cc;break;
     case 24:c=*kc_cf6ed4;break;
     case 25:c=*kc_d2175c;break;
     default:c=*kc_d22fcc;break;
     }
     KcVPos&path2=upX.at9b81f0(i)->v4;
     for(unsigned j=0;j<path2.size9b9a50();j++){
      p=path2.at9e7c10(j).add409b60(scroll);
      if(inBounds4173d0(p))setBack417fc0(p.x,p.y,c,true);
     }
    }
    t454=kc_caed20;
   }else{
    const int on=2000;
    const int off=3000;
    const int vUp=5000;
    unsigned el=kc_caed20-t454;
    if(el%vUp>on){
     unsigned start=el-el%vUp+on;
     KcPos p;
     KcV420&vv2=kc_cefc4c->u463df0();
     for(unsigned i=0;i<vv2.size9b9260();i++){
      KcColor c;
      switch(vv2.at9b81f0(i)->type){
      case 13:c=*kc_cf44c4;break;
      case 16:case 17:case 18:c=*kc_cfd4cc;break;
      case 24:c=*kc_cf6ed4;break;
      case 25:c=*kc_d2175c;break;
      default:c=*kc_d22fcc;break;
      }
      c*=1.0f*sin((float)((el-start)/kc_c36f30*kc_c36c98));
      KcVPos&ww3=vv2.at9b81f0(i)->v4;
      for(unsigned j=0;j<ww3.size9b9a50();j++){
       p=ww3.at9e7c10(j).add409b60(scroll);
       if(inBounds4173d0(p))setBack417fc0(p.x,p.y,c,true);
      }
     }
    }
   }
  }
  if(!kc_cefc4c->u4635a0().empty9b86e0()){
   const int on=2000;
   const int off=3000;
   const int z18=5000;
   if(kc_caed20%z18>on){
    unsigned start=kc_caed20-kc_caed20%z18+on;
    KcColor e3=*kc_d33d88*kc_pulse437200(0.0f,1.0f,off,start);
    KcVEnt&es=kc_cefc4c->u4635a0();
    KcPos p6;
    for(unsigned i=0;i<es.size9b9260();i++){
     p6=es.at9b81f0(i)->getPosition().add409b60(scroll);
     KcVPos area;
     u808510(p6,0x14,area);
     for(unsigned j=0;j<area.size9b9a50();j++)
      if(inBounds4173d0(area.at9e7c10(j)))setBack417fc0(area.at9e7c10(j).x,area.at9e7c10(j).y,e3,true);
     if(inBounds4173d0(p6))setBack417fc0(p6.x,p6.y,e3,true);
    }
   }
  }
{  KcVEnt&grp=kc_cefc4c->u463890(1)->u416f40();
  for(unsigned i=0;i<grp.size9b9260();i++){
   if(grp.at9b81f0(i)->ai45b590()->u459090()&&(grp.at9b81f0(i)->ai45b590()->u4590f0()->u458950(0x43)||grp.at9b81f0(i)->ai45b590()->u4590f0()->u458950(0x44))&&*aVisible->atPoint9ced70(grp.at9b81f0(i)->getPosition())!=0){
    const int a=500;
    const int z26=2000;
    const int z37=2500;
    if(kc_caed20%z37>a){
     unsigned st=kc_caed20-kc_caed20%z37+a;
     KcColor col=*kc_cfd448*kc_pulse437200(0.0f,1.0f,z26,st);
     KcPos p1=grp.at9b81f0(i)->getPosition().add409b60(scroll);
     KcVPos area_;
     u808510(p1,5,area_);
     for(unsigned j=0;j<area_.size9b9a50();j++)
      if(inBounds4173d0(area_.at9e7c10(j)))setBack417fc0(area_.at9e7c10(j).x,area_.at9e7c10(j).y,col,true);
     if(inBounds4173d0(p1))setBack417fc0(p1.x,p1.y,col,true);
    }
   }
  }}
  if(!v460.empty9b86e0()){
   n470.update4218e0();
   const int dur=600;
   KcPos p;
   bool z43;
   for(unsigned i=0;i<v460.size9b9260();i++){
    z43=v460.at9b81f0(i)->b0;
    float f=kc_pulse4372b0(kc_c37128,kc_c36eb4,v460.at9b81f0(i)->t14,dur);
    if(kc_caed20-v460.at9b81f0(i)->t14>=dur)kc_delStep9e2b60(v460,i);
    else{
     KcVPos&path=v460.at9b81f0(i)->v4;
     for(unsigned j=0;j<path.size9b9a50();j++){
      p=path.at9e7c10(j).add409b60(scroll);
      KcColor c((float)(n470.sample421770(path.at9e7c10(j))*kc_c36e78),1.0f,1.0f);
      if(inBounds4173d0(p)){
       if(z43)setFore417f80(p.x,p.y,KcColor::lerp(getFore417720(p),c,*aVisible->atPoint9ced70(path.at9e7c10(j))!=0?f:f*kc_c36db0));
       else setBack417fc0(p.x,p.y,KcColor::lerp(getBack417750(p),c,f)*kc_c36f88,true);
      }
     }
    }
   }
  }
  if(i134){
   if(kc_cefc4c->player->getPosition().eq409bd0(p14c)||scroll.eq409bd0(p154)&&i134!=4){
    v138.clear9b3560();
    i134=0;
   }
   switch(i134){
   case 1:{
    int speed=kc_maxInt9cdb60(15,50-(i148-kc_cefc4c->player->def9b4350()->i21c)*3);
    KcRange2 zz5;
    zz5.lo=i160==-1?kc_cefc4c->player->def9b4350()->i21c:i160+1;
    zz5.hi=kc_cefc4c->player->def9b4350()->i21c+(kc_caed20-t15c)/speed;
    if(zz5.hi>i148)zz5.hi=i148;
    if(zz5.hi>=zz5.lo){
     i160=zz5.hi;
     int fx=0;
     kc_lookup9d45a0("CMap_Anim_Sight_Range",fx);
     if(fx){
      KcPos c=p14c.add409b60(p154);
      buf4184d0()->getBounds9b7a40(c,i148,from3,toN);
      for(int x=from3.x;x<=toN.x;x++)
       for(int y=from3.y;y<=toN.y;y++)
        if(kc_between9daf80(zz5.lo,kc_distance406480(c.x,c.y,x,y),zz5.hi))kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,KcPos(x,y),kc_cfbec0,0,0,9);
     }
     if(zz5.hi==i148)i134=0;
    }
   }break;
   case 10:{
    int fx;
    kc_lookup9d45a0("CMap_Sensor_Wall_Structural_Scanner",fx);
    int aAdj=3;
    int hs=10;
    int el=kc_caed20-t15c;
    int i6=(int)(el/((double)hs/aAdj));
    bool g2=false;
    if(i160==-1)i160-=aAdj;
    if(i6>i160+aAdj){
     KcVInt aInv;
     int a=i6-i6%aAdj;
     if(a<360)aInv.push_back9b9d30(a);
     else g2=true;
     while(a-aInv.size9b9260()*aAdj>i160)kc_insertAt9dbdc0(aInv,0,aInv.front9b7060()-aAdj);
     for(unsigned k=0;k<aInv.size9b9260();k++){
      float rx;
      float h7;
      kc_rotate406640(p14c.x,p14c.y,p14c.x,p14c.y-kc_cefc4c->player->u5c7d30(),aInv.at9b81f0(k),&rx,&h7);
      KcPos h_((int)rx,(int)h7);
      KcVPos line5;
      KcVInt cells7;
      float maxD=kc_c36e30;
      KcPos off(kc_cefc4c->player->u5c7d30(),kc_cefc4c->player->u5c7d30());
      kc_traceSubcell4106d0(p14c.add409b60(off),h_.add409b60(off),line5,cells7,(int)maxD);
      int last=line5.size9b9a50()-1;
      for(unsigned m=0;m<line5.size9b9a50();m++){
       line5.at9e7c10(m).sub409a70(off);
       if(!kc_cfd44c.contains9b43b0(line5.at9e7c10(m))||!kc_cefc4c->isVisible4631c0(line5.at9e7c10(m))){last=m-1;break;}
       else if(!kc_cfd44c.atPoint9ced70(line5.at9e7c10(m))[0]->u4550b0()||kc_cfd44c.atPoint9ced70(line5.at9e7c10(m))[0]->u45db70()){
        if(inBounds4173d0(line5.at9e7c10(m).add409b60(p154))&&fx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,line5.at9e7c10(m).add409b60(p154),kc_cfbec0,0,0,9);
        if(kc_cfd44c.atPoint9ced70(line5.at9e7c10(m))[0]->isEdge45dc30()&&kc_cefc4c->u463e90(line5.at9e7c10(m))&&!hasPosLabel49b220(7,line5.at9e7c10(m)))labelAccess80e3a0(1,line5.at9e7c10(m));
       }
      }
      int start3=rng.rangeInt406d70(0.0f,(float)(line5.size9b9a50()*kc_c36da8));
      for(int m2=start3;m2<=last;m2++){
       if(inBounds4173d0(line5.at9e7c10(m2).add409b60(p154))){
        if(kc_cefb3c)setBack417fc0(line5.at9e7c10(m2).x+p154.x,line5.at9e7c10(m2).y+p154.y,KcColor::lerp(kc_d29804,*kc_cf44c0,(float)((float)(m2-start3)/(last-start3)*cells7.at9b81f0(m2)/maxD)),true);
        else setBack417fc0(line5.at9e7c10(m2).x+p154.x,line5.at9e7c10(m2).y+p154.y,KcColor::scale(*kc_cf44c0,(float)((float)(m2-start3)/(last-start3)*cells7.at9b81f0(m2)/maxD)),true);
       }
      }
     }
     if(g2){
      v138.clear9b3560();
      i134=0;
     }
    }
   }break;
   case 2:case 6:{
    KcColor c=kc_cefb3c?kc_d29804*kc_c37088:KcColor(0,0x10,0);
    for(unsigned i=0;i<v138.size9b9a50();i++)
     if(inBounds4173d0(v138.at9e7c10(i)))setBack417fc0(v138.at9e7c10(i).x,v138.at9e7c10(i).y,c,true);
    if(i134==6){
     int fx;
     kc_lookup9d45a0("CMap_Sensor_Terr_Front",fx);
     int step=20;
     int el=kc_caed20-t15c;
     int u5=el/step;
     int j_=p14c.x+p154.x+u5;
     bool ex=false;
     KcVInt k8;
     KcPos aP;
     if(j_>p14c.x+p154.x+i148)ex=true;
     else if(j_>i160){
      bool found=false;
      for(unsigned i=0;i<v138.size9b9a50();i++){
       if(v138.at9e7c10(i).x==j_){
        if(inBounds4173d0(v138.at9e7c10(i))&&fx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,v138.at9e7c10(i),kc_cfbec0,0,0,9);
        aP.set40a010(p14c.x+p154.x-u5,v138.at9e7c10(i).y);
        if(inBounds4173d0(aP)&&fx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,aP,kc_cfbec0,0,0,9);
        found=true;
       }else if(found)break;
      }
      k8.push_back9b9d30(j_);
     }
     if(i160==-1)i160=p14c.x+p154.x;
     for(int x=j_-1;x>i160;x--){
      bool found2=false;
      for(unsigned i=0;i<v138.size9b9a50();i++){
       if(v138.at9e7c10(i).x==x){
        if(inBounds4173d0(v138.at9e7c10(i))&&fx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,v138.at9e7c10(i),kc_cfbec0,0,0,9);
        aP.set40a010(p14c.x+p154.x-u5+(j_-x),v138.at9e7c10(i).y);
        if(inBounds4173d0(aP)&&fx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,aP,kc_cfbec0,0,0,9);
        found2=true;
       }else if(found2)break;
      }
      k8.push_back9b9d30(x);
     }
     i160=j_;
     for(unsigned k=0;k<k8.size9b9260();k++){
      KcVInt xs;
      xs.push_back9b9280(k8.at9b81f0(k)-p154.x);
      xs.push_back9b9280(p14c.x-(xs.back9b6540()-p14c.x));
      for(unsigned m=0;m<xs.size9b9260();m++){
       if(!kc_between9daf80(0,xs.at9b81f0(m),kc_cfd44c.width9fcd80()-1))continue;
       int propFx=0;
       int hX=0;
       int doorFx=0;
       for(int y=0;y<kc_cfd44c.height9b8f00();y++){
        if(*kc_cefc4c->known.at9cec50(xs.at9b81f0(m),y)&&inBounds417360(xs.at9b81f0(m)+p154.x,y+p154.y)){
         if(!CELL(xs.at9b81f0(m),y)->u4550b0()||CELL(xs.at9b81f0(m),y)->u45db70()||CELL(xs.at9b81f0(m),y)->getProp().isValid()&&!CELL(xs.at9b81f0(m),y)->getProp()->u470b30()){
          if(kc_distance40a3f0(p14c,KcPos(xs.at9b81f0(m),y))<=i148){
           if(CELL(xs.at9b81f0(m),y)->getProp().isValid()){
            if(propFx==0)kc_lookup9d45a0("CMap_Sensor_Terr_Prop",propFx);
            if(propFx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,propFx,KcPos(xs.at9b81f0(m)+p154.x,y+p154.y),kc_cfbec0,0,0,9);
           }else{
            if(hX==0)kc_lookup9d45a0("CMap_Sensor_Terr_Wall",hX);
            if(hX)kc_cefc64->new50fb50()->init50de10(kc_cefc64,hX,KcPos(xs.at9b81f0(m)+p154.x,y+p154.y),kc_cfbec0,0,0,9);
            if(CELL(xs.at9b81f0(m),y)->u45db70()&&(!CELL(xs.at9b81f0(m),y)->isEdge45dc30()||kc_cefc4c->u463e90(KcPos(xs.at9b81f0(m),y)))){
             if(doorFx==0)kc_lookup9d45a0("A_CMap_Sensor_Terr_Door",doorFx);
             v1d8.push_back9b9280(new KcLabel(3,new KcSubCon(kc_cec054,5,3,xs.at9b81f0(m)+p154.x,y+p154.y,kc_d28d15?1:0,false,-1),1,kc_caed20+1000,KcPos(-1,-1),KcHE(),KcHE(),KcHE(),KcPos(xs.at9b81f0(m),y)));
             v1d8.back9b6540()->con4->resetBack418450();
             if(doorFx)v1d8.back9b6540()->con4->animate48c3c0(doorFx);
            }
           }
          }
         }
        }
       }
      }
     }
     if(ex){
      v138.clear9b3560();
      i134=0;
     }
    }else{
     int fx;
     kc_lookup9d45a0("CMap_Sensor_Robot_Front",fx);
     int step=15;
     int el=kc_caed20-t15c;
     int up=el/step;
     int row=p14c.y+p154.y-i148+up-1;
     bool iD=false;
     KcVInt rows;
     if(row>p14c.y+p154.y+i148)iD=true;
     else if(row>i160){
      bool found=false;
      for(unsigned i=0;i<v138.size9b9a50();i++){
       if(v138.at9e7c10(i).y==row){
        if(inBounds4173d0(v138.at9e7c10(i))&&fx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,v138.at9e7c10(i),kc_cfbec0,0,0,9);
        found=true;
        KcVPos line;
        kc_line40ff30(v138.at9e7c10(i),KcPos(p14c.x+p154.x,row),line);
        for(int j=1;j<line.size9b9a50()*kc_c36cc8;j++){
         if(inBounds4173d0(line.at9e7c10(j))){
          if(kc_cefb3c)setBack417fc0(line.at9e7c10(j).x,line.at9e7c10(j).y,KcColor::lerp(kc_d29804,*kc_cf44c0,(float)(line.size9b9a50()*kc_c36cc8-j)/(float)(line.size9b9a50()*kc_c36cc8)),true);
          else setBack417fc0(line.at9e7c10(j).x,line.at9e7c10(j).y,KcColor::scale(*kc_cf44c0,(float)(line.size9b9a50()*kc_c36cc8-j)/(float)(line.size9b9a50()*kc_c36cc8)),true);
         }
        }
       }else if(found)break;
      }
      rows.push_back9b9d30(row);
     }
     if(i160==-1)i160=p14c.y+p154.y-i148;
     for(int y=row-1;y>i160;y--){
      bool found2=false;
      for(unsigned i=0;i<v138.size9b9a50();i++){
       if(v138.at9e7c10(i).y==y){
        if(inBounds4173d0(v138.at9e7c10(i))&&fx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,v138.at9e7c10(i),kc_cfbec0,0,0,9);
        found2=true;
       }else if(found2)break;
      }
      rows.push_back9b9d30(y);
     }
     i160=row;
     for(unsigned k=0;k<rows.size9b9260();k++){
      int aPct=rows.at9b81f0(k)-p154.y;
      if(!kc_between9daf80(0,aPct,kc_cfd44c.height9b8f00()-1))continue;
      int fxs[3];
      kc_fillInts9e2be0(fxs,3,0);
      string i9[3]={"A_CMap_S_Label_Ent_Hostile","A_CMap_S_Label_Ent_Neutral","A_CMap_S_Label_Ent_Friendly"};
      int rel;
      for(int x=0;x<kc_cfd44c.width9fcd80();x++){
       if(CELL(x,aPct)->getEntity().isValid()&&CELL(x,aPct)->getEntity()!=kc_cefc4c->player&&kc_cefc4c->u4631f0(CELL(x,aPct)->getEntity())&&kc_distance40a3f0(p14c,KcPos(x,aPct))<=i148&&!hasEntLabel49b1a0(0,CELL(x,aPct)->getEntity())){
        rel=kc_cefc4c->player->rel5c7fc0(CELL(x,aPct)->getEntity());
        if(fxs[rel]==0)kc_lookup9d45a0(i9[rel],fxs[rel]);
        v1d8.push_back9b9280(new KcLabel(0,new KcSubCon(kc_cec054,0xc,1,x+p154.x,aPct+p154.y,kc_d28d15?1:0,false,-1),1,kc_caed20+2000,KcPos(1,0),CELL(x,aPct)->getEntity(),KcHE(),KcHE(),KcPos(CELL(x,aPct)->getEntity()->getSize()-1,0)));
        if(fxs[rel])v1d8.back9b6540()->con4->animate48c3c0(fxs[rel]);
       }
      }
      if(kc_maxInt9cdb60(kc_cefc4c->player->item5d2380(0xd).isValid()?4:0,kc_cefc4c->player->u5d22a0(0xc))>=2){
       for(int x=0;x<kc_cfd44c.width9fcd80();x++){
        if(kc_cefc4c->a740.at9cdf20(x,aPct)->a==kc_cefc4c->i74c&&kc_cefc4c->a740.at9cdf20(x,aPct)->h8.operator->()&&kc_distance40a3f0(p14c,KcPos(x,aPct))<=i148&&!hasEntLabel49b1a0(0,kc_cefc4c->a740.at9cdf20(x,aPct)->h8)){
         rel=kc_cefc4c->player->rel5c7fc0(kc_cefc4c->a740.at9cdf20(x,aPct)->h8);
         if(fxs[rel]==0)kc_lookup9d45a0(i9[rel],fxs[rel]);
         v1d8.push_back9b9280(new KcLabel(0,new KcSubCon(kc_cec054,0xc,1,x+p154.x,aPct+p154.y,kc_d28d15?1:0,false,-1),1,kc_caed20+2000,KcPos(1,0),kc_cefc4c->a740.at9cdf20(x,aPct)->h8,KcHE(),KcHE(),KcPos(kc_cefc4c->a740.at9cdf20(x,aPct)->h8->getSize()-1,0)));
         if(fxs[rel])v1d8.back9b6540()->con4->animate48c3c0(fxs[rel]);
         v1d8.back9b6540()->b31=true;
        }
       }
      }
     }
     if(iD){
      v138.clear9b3560();
      i134=0;
     }
    }
   }break;
   case 4:{
    const int fadeIn=500;
    const int hold=1000;
    const int d5=200;
    unsigned far3=kc_caed20-t15c;
    int extra=(u8050a0()?1:3)*kc_d28ea0;
    if(far3>=extra+fadeIn+hold+d5)i134=0;
    else if(far3<fadeIn)break;
    else{
     float far7;
     if(far3<fadeIn+hold){
      far3-=fadeIn;
      far7=far3/kc_c36fd8;
     }else if(far3<extra+fadeIn+hold)far7=1.0f;
     else{
      far3-=extra+fadeIn+hold;
      far7=1-far3/kc_c36f90;
     }
     KcColor base5=*kc_d38644;
     float loB=kc_c37124;
     float step=(1.0f-loB)/kc_cefc4c->i34;
     float re39;
     for(int farC=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);farC<=toN.x&&sx<kc_cf27f4;farC++,sx++)
      for(int y=from3.y,fp6=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&fp6<kc_cf27f8;y++,fp6++){
       if(CELL(farC,y)->highlighter4ab670()>0){
        re39=CELL(farC,y)->highlighter4ab670()*step+loB;
        re39*=far7;
        if(re39>kc_c36cb0){
         if(kc_cefb3c)setBack417fc0(sx,fp6,KcColor::lerp(kc_d29804,base5,1.0f*sin((float)(re39*kc_c36e68))),true);
         else setBack417fc0(sx,fp6,KcColor::scale(base5,1.0f*sin((float)(re39*kc_c36e68))),true);
        }
       }
      }
    }
   }break;
   case 32:{
    const int dur=100;
    if(kc_caed20>=t15c+600){
     v188.clear9b4710();
     v198.clear9bac80();
     i134=0;
     break;
    }
    for(unsigned i=0;i<v188.size9b5100();i++){
     if(kc_inRange9e2b30(v198.at9b81f0(i),kc_caed20,v198.at9b81f0(i)+dur)){
      float a=dur-(kc_caed20-v198.at9b81f0(i))/dur;
      KcColor far_=*kc_d2175c;
      if(kc_cefb3c)KcColor::lerp(kc_d29804,far_,a);
      else KcColor::scale(far_,a);
      for(int x=v188.at9b8070(i).x1;x<=v188.at9b8070(i).x2;x++)
       for(int y=v188.at9b8070(i).y1;y<=v188.at9b8070(i).y2;y++)
        setBack417fc0(x,y,far_,true);
     }
    }
   }break;
   case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:{
    if(kc_caed20>=t15c+2000){
     v168.clear9b58f0();
     v178.clear9b8eb0();
     i134=0;
     break;
    }
    float dur=kc_c36f20;
    if(kc_caed20<=t15c+dur){
     float maxD=kc_c36e30;
     KcColor fars;
     switch(i134){
     case 13:fars=*kc_d2175c;break;
     case 14:fars=*kc_d2175c;break;
     case 15:fars=*kc_d33d88;break;
     case 16:fars=*kc_d33d88;break;
     case 17:fars=*kc_d316f4;break;
     case 18:fars=*kc_cfd4cc;break;
     case 19:fars=*kc_cf44c4;break;
     case 20:fars=*kc_cf6ed4;break;
     }
     for(unsigned i=0;i<v168.size9b5100();i++){
      int start=v168.at9b8070(i).size9b9a50()*((kc_caed20-t15c)/dur);
      for(int j=start;j<v168.at9b8070(i).size9b9a50();j++){
       if(inBounds4173d0(v168.at9b8070(i).at9e7c10(j).add409b60(p154)))
        setBack417fc0(v168.at9b8070(i).at9e7c10(j).x+p154.x,v168.at9b8070(i).at9e7c10(j).y+p154.y,kc_cefb3c?KcColor::lerp(kc_d29804,fars,(float)(j-start)/(v168.at9b8070(i).size9b9a50()-1-start)*v178.at9b8070(i).at9b81f0(j)/maxD):KcColor::scale(fars,(float)(j-start)/(v168.at9b8070(i).size9b9a50()-1-start)*v178.at9b8070(i).at9b81f0(j)/maxD),true);
      }
     }
    }
   }break;
   case 11:{
    int step=20;
    int el=kc_caed20-t15c;
    int oldD=el/step;
    if(i164==-1){
     for(int x=kc_maxInt9cdb60(0,kc_cefc4c->p6e8->i10-kc_cefc4c->p6e8->i18);x<=kc_cefc4c->p6e8->i10;x++)
      for(int y=kc_maxInt9cdb60(0,kc_cefc4c->p6e8->i14-kc_cefc4c->p6e8->i18);y<=kc_minInt9cdb30(kc_cfd44c.height9b8f00()-1,kc_cefc4c->p6e8->i14+kc_cefc4c->p6e8->i18);y++)
       if(kc_cefc4c->u463380(x,y)){
        i164=x+p154.x;
        goto foundLeft;
       }
    }
foundLeft:
    int gTmp=-1;
    for(int x=kc_minInt9cdb30(kc_cfd44c.width9fcd80()-1,kc_cefc4c->p6e8->i10+kc_cefc4c->p6e8->i18);x>=kc_cefc4c->p6e8->i10;x--)
     for(int y=kc_maxInt9cdb60(0,kc_cefc4c->p6e8->i14-kc_cefc4c->p6e8->i18);y<=kc_minInt9cdb30(kc_cfd44c.height9b8f00()-1,kc_cefc4c->p6e8->i14+kc_cefc4c->p6e8->i18);y++)
      if(kc_cefc4c->u463380(x,y)){
       gTmp=x+p154.x;
       goto foundRight;
      }
foundRight:
    gTmp++;
    int iC=i164+oldD;
    bool iN=false;
    KcVInt jB;
    if(iC>=gTmp)iN=true;
    else if(iC>i160)jB.push_back9b9d30(iC);
    if(i160==-1)i160=iC;
    for(int x=iC-1;x>i160;x--)jB.push_back9b9d30(x);
    bool unused4=false;
    for(unsigned k=0;k<jB.size9b9260();k++){
     int bkgFx;
     kc_lookup9d45a0("CMap_Anim_TrapScan_Bkg",bkgFx);
     int gain;
     kc_lookup9d45a0("CMap_Anim_TrapScan_Trap",gain);
     int x=jB.at9b81f0(k)-p154.x;
     for(int sy=0,goal=sy-scroll.y;sy<getHeight4174c0();sy++,goal++){
      if(inBounds417360(jB.at9b81f0(k),sy)&&kc_cfd44c.inBounds9b45c0(x,goal)&&kc_cefc4c->u463380(x,goal)&&CELL(x,goal)->u4550b0()){
       if(CELL(x,goal)->isDoor()){
        if(gain)kc_cefc64->new50fb50()->init50de10(kc_cefc64,gain,KcPos(jB.at9b81f0(k),sy),kc_cfbec0,0,0,9);
       }else if(!CELL(x,goal)->u45d1e0()){
        if(jB.at9b81f0(k)==iC)putChar418110(jB.at9b81f0(k),sy,0x80,*kc_d25f60);
        if(bkgFx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,bkgFx,KcPos(jB.at9b81f0(k),sy),kc_cfbec0,0,0,9);
       }
      }
     }
    }
    i160=iC;
    if(iN)i134=0;
   }break;
   case 21:case 22:case 23:case 24:{
    int step=30;
    int el=kc_caed20-t15c;
    int hVal=el/step;
    int row=p14c.y+p154.y-i148+hVal-1;
    bool i_=false;
    KcVInt rows;
    if(row>p14c.y+p154.y+i148)i_=true;
    else if(row>i160&&row>=0&&row<getHeight4174c0())rows.push_back9b9d30(row);
    if(i160==-1)i160=p14c.y+p154.y-i148;
    for(int y=row-1;y>i160;y--)
     if(y>=0&&y<getHeight4174c0())rows.push_back9b9d30(y);
    if(!rows.empty9b86e0()){
     int frontFx;
     kc_lookup9d45a0(i134==21?"CMap_A_Shield_Front_TH":i134==22?"CMap_A_Shield_Front_Corr":i134==23?"CMap_A_Shield_Front_25":"CMap_A_Shield_Front_50",frontFx);
     int guardFx;
     kc_lookup9d45a0(i134==21?"CMap_A_Shield_Guard_TH":i134==22?"CMap_A_Shield_Guard_Corr":i134==23?"CMap_A_Shield_Guard_25":"CMap_A_Shield_Guard_50",guardFx);
     for(unsigned k=0;k<rows.size9b9260();k++){
      KcPos hit3=p14c.add409b60(p154);
      int y=rows.at9b81f0(k)-p154.y;
      for(int sx=kc_maxInt9cdb60(0,hit3.x-i148),x=p14c.x-i148;sx<kc_minInt9cdb30(width44b0d0(),hit3.x+i148);sx++,x++){
       if(kc_distance406480(hit3.x,hit3.y,sx,rows.at9b81f0(k))<=i148){
        if(frontFx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,frontFx,KcPos(sx,rows.at9b81f0(k)),kc_cfbec0,0,0,9);
        if(guardFx&&kc_cfd44c.inBounds9b45c0(x,y)&&CELL(x,y)->getEntity().isValid()&&CELL(x,y)->getEntity()!=kc_cefc4c->player&&CELL(x,y)->getEntity()->u45aaa0(kc_cefc4c->player)&&kc_cefc4c->u465200(kc_cefc4c->player->getPosition(),CELL(x,y)->getEntity()->getPosition()))
         kc_cefc64->new50fb50()->init50de10(kc_cefc64,guardFx,KcPos(sx,rows.at9b81f0(k)),kc_cfbec0,0,0,9);
       }
      }
     }
    }
    i160=row;
    if(i_)i134=0;
   }break;
   case 25:{
    int fx;
    kc_lookup9d45a0("CMap_Anim_PD_Front",fx);
    int step=50;
    int el=kc_caed20-t15c;
    int w1=el/step;
    int row=p14c.y+p154.y-i148+w1-1;
    bool j8=false;
    KcPos kX;
    if(row>p14c.y+p154.y)j8=true;
    else if(row>i160){
     bool found=false;
     for(unsigned i=0;i<v138.size9b9a50();i++){
      if(v138.at9e7c10(i).y==row){
       if(inBounds4173d0(v138.at9e7c10(i))&&fx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,v138.at9e7c10(i),kc_cfbec0,0,0,9);
       kX.set40a010(v138.at9e7c10(i).x,p14c.y+p154.y+i148-w1+1);
       if(inBounds4173d0(kX)&&fx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,kX,kc_cfbec0,0,0,9);
       found=true;
      }else if(found)break;
     }
    }
    if(i160==-1)i160=p14c.y+p154.y-i148;
    for(int y=row-1;y>i160;y--){
     bool found2=false;
     for(unsigned i=0;i<v138.size9b9a50();i++){
      if(v138.at9e7c10(i).y==y){
       if(inBounds4173d0(v138.at9e7c10(i))&&fx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,v138.at9e7c10(i),kc_cfbec0,0,0,9);
       kX.set40a010(v138.at9e7c10(i).x,p14c.y+p154.y+i148-w1+(row-y));
       if(inBounds4173d0(kX)&&fx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,kX,kc_cfbec0,0,0,9);
       found2=true;
      }else if(found2)break;
     }
    }
    i160=row;
    if(j8){
     v138.clear9b3560();
     i134=0;
     int lvl=kc_cefc4c->player->u5d2090(0x48);
     int glowFx;
     kc_lookup9d45a0(lvl<100?"CMap_Anim_PD_Glow_100":lvl<200?"CMap_Anim_PD_Glow_200":"CMap_Anim_PD_Glow_ETC",glowFx);
     if(glowFx){
      KcPos c=p14c.add409b60(p154);
      buf4184d0()->getBounds9b7a40(c,i148,from3,toN);
      for(int x=from3.x;x<=toN.x;x++)
       for(int y=from3.y;y<=toN.y;y++)
        if(kc_distance406480(c.x,c.y,x,y)<=i148)kc_cefc64->new50fb50()->init50de10(kc_cefc64,glowFx,KcPos(x,y),kc_cfbec0,0,0,9);
     }
    }
   }break;
   case 34:case 35:{
    i134=0;
   }break;
   case 36:{
    const int dur=800;
    int el=kc_caed20-t15c;
    if(el>dur)i134=0;
    else{
     KcVInt inFx(9u,0u);
     KcVInt outFx(9u,0u);
     int nCur;
     for(int i=1;i<=9;i++){
      kc_lookup9d45a0("CMap_Anim_Latent_Inn_"+kc_intToString4051f0(i),inFx.at9b81f0(i-1));
      kc_lookup9d45a0("CMap_Anim_Latent_Out_"+kc_intToString4051f0(i),outFx.at9b81f0(i-1));
     }
     float fade=kc_fade437250(1.0f,t15c,dur);
     for(int pass=0;pass<2;pass++){
      const int&r=pass==0?i148:16;
      nCur=r-r*fade;
      KcVPos ring;
      u808510(p14c.add409b60(scroll),nCur,ring);
      KcColor c=(pass==0?*kc_d32dfc:*kc_cfbec8)*fade;
      for(unsigned j=0;j<ring.size9b9a50();j++)
       if(inBounds4173d0(ring.at9e7c10(j)))setBack417fc0(ring.at9e7c10(j).x,ring.at9e7c10(j).y,c,true);
      int&k6=pass==0?i160:i164;
      if(nCur>k6){
       KcVInt&b4=pass==0?inFx:outFx;
       KcPos c2=p14c.add409b60(p154);
       buf4184d0()->getBounds9b7a40(c2,r,from3,toN);
       KcPos q;
       for(int x=from3.x;x<=toN.x;x++)
        for(int y=from3.y;y<=toN.y;y++){
         q.set40a010(x-p154.x,y-p154.y);
         if(kc_cfd44c.contains9b43b0(q)&&(*kc_cfd44c.atPoint9ced70(q))->u45db50()&&kc_between9daf80(k6+1,kc_distance406480(c2.x,c2.y,x,y),nCur)){
          int v=(*kc_cfd44c.atPoint9ced70(q))->u45a6e0();
          kc_cefc64->new50fb50()->init50de10(kc_cefc64,b4.at9b81f0(v-1),KcPos(x,y),kc_cfbec0,0,0,9);
         }
        }
       k6=nCur;
      }
     }
     if(nCur>=16)i134=0;
    }
   }break;
   case 37:case 38:{
    const int dur=400;
    int el=kc_caed20-t15c;
    if(el>dur)i134=0;
    else{
     float fade=kc_fade437250(1.0f,t15c,dur);
     int cur=i148-i148*fade;
     KcVPos hit7;
     u808510(p14c.add409b60(scroll),cur,hit7);
     KcVColor cols;
     cols.push_back9b3c80(KcColor(i134==38?*kc_d2ea1c:*kc_d21b44)*fade);
     cols.push_back9b3c80(KcColor(i134==38?*kc_cefdcc:*kc_cfd4cc)*fade);
     for(unsigned i=0;i<hit7.size9b9a50();i++){
      if(inBounds4173d0(hit7.at9e7c10(i))){
       KcPos p=hit7.at9e7c10(i).sub409b30(scroll);
       if(kc_cfd44c.contains9b43b0(p))setBack417fc0(hit7.at9e7c10(i).x,hit7.at9e7c10(i).y,cols.at9b3e50(kc_cefc4c->isVisible4631c0(p)?0:1),true);
      }
     }
     if(cur>=i148)i134=0;
    }
   }break;
   case 8:{
    const int half=400;
    int el=kc_caed20-t15c;
    if(el>half*2){
     i134=0;
     break;
    }
    int r;
    float n2;
    if(el<=half){
     r=i148*el/half;
     n2=1.0f;
    }else{
     r=i148-i148*((el-half)/kc_c37068);
     n2=kc_fade437250(1.0f,t15c+half,half);
    }
    KcColor cVal=*kc_cf27e8*n2;
    KcVPos ring5;
    u808510(p14c.add409b60(scroll),r,ring5);
    for(unsigned i=0;i<ring5.size9b9a50();i++){
     if(inBounds4173d0(ring5.at9e7c10(i))){
      KcPos p=ring5.at9e7c10(i).sub409b30(scroll);
      if(kc_cfd44c.contains9b43b0(p))setBack417fc0(ring5.at9e7c10(i).x,ring5.at9e7c10(i).y,cVal,true);
     }
    }
    if(el>half){
     cVal*=kc_c36eb4;
     ring5.clear9b3560();
     u808510(p14c.add409b60(scroll),i148,ring5);
     for(unsigned i=0;i<ring5.size9b9a50();i++){
      if(inBounds4173d0(ring5.at9e7c10(i))){
       KcPos p=ring5.at9e7c10(i).sub409b30(scroll);
       if(kc_cfd44c.contains9b43b0(p))setBack417fc0(ring5.at9e7c10(i).x,ring5.at9e7c10(i).y,cVal,true);
      }
     }
     if(i160==-1||i160>r){
      i164=i160==-1?i148+1:i160;
      i160=r;
      int fx;
      kc_lookup9d45a0("CMap_Anim_Seismic",fx);
      KcPos q;
      KcVPosPtrs lists8;
      int dist;
      lists8.push_back9b9280(&kc_d01b28);
      lists8.push_back9b9280(&kc_d1e234);
      for(unsigned k=0;k<lists8.size9b9260();k++){
       KcVPos*l=lists8.at9b81f0(k);
       for(unsigned j=0;j<l->size9b9a50();j++){
        dist=kc_distance40a3f0(p14c,l->at9e7c10(j));
        if(dist>=r&&dist<i164){
         q=l->at9e7c10(j).add409b60(scroll);
         if(inBounds4173d0(q))kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,q,kc_cfbec0,0,0,9);
        }
       }
      }
     }
    }
   }break;
   }
  }
  if(!v1a8.empty9b86e0()){
   bool cleanup=false;
   int hitC;
   kc_lookup9d45a0("CMap_Sensor_Wall_Spotter",hitC);
   for(unsigned i=0;i<v1a8.size9b9260();i++){
    KcSpot*hit_=v1a8.at9b81f0(i);
    int hits=3;
    int speed=10;
    int el=kc_caed20-hit_->t10;
    int jC=(int)(el/((double)speed/hits));
    if(hit_->last==-1)hit_->last-=hits;
    if(jC>hit_->last+hits){
     KcVInt hops;
     int a=jC-jC%hits;
     if(a<360)hops.push_back9b9d30(a);
     else{
      cleanup=true;
      break;
     }
     while(a-hops.size9b9260()*hits>hit_->last)kc_insertAt9dbdc0(hops,0,hops.front9b7060()-hits);
     for(unsigned k=0;k<hops.size9b9260();k++){
      if(hit_->b1c)hops.at9b81f0(k)+=hit_->i18;
      else{
       hops.at9b81f0(k)=hit_->i18-hops.at9b81f0(k);
       if(hops.at9b81f0(k)<0)hops.at9b81f0(k)+=360;
      }
     }
     for(unsigned k=0;k<hops.size9b9260();k++){
      float rx;
      float m3;
      kc_rotate406640(hit_->p.x,hit_->p.y,hit_->p.x,hit_->p.y-hit_->i20,hops.at9b81f0(k),&rx,&m3);
      KcPos n1((int)rx,(int)m3);
      KcVPos line7;
      KcVInt cells0;
      float maxD=kc_c36e30;
      KcPos off(hit_->i20,hit_->i20);
      kc_traceSubcell4106d0(hit_->p.add409b60(off),n1.add409b60(off),line7,cells0,(int)maxD);
      int last=line7.size9b9a50()-1;
      for(unsigned m=0;m<line7.size9b9a50();m++){
       line7.at9e7c10(m).sub409a70(off);
       if(!kc_cfd44c.contains9b43b0(line7.at9e7c10(m))||!kc_cefc4c->isVisible4631c0(line7.at9e7c10(m))){last=m-1;break;}
       else if(!kc_cfd44c.atPoint9ced70(line7.at9e7c10(m))[0]->u4550b0()||kc_cfd44c.atPoint9ced70(line7.at9e7c10(m))[0]->u45db70()){
        if(inBounds4173d0(line7.at9e7c10(m).add409b60(hit_->off))&&hitC)kc_cefc64->new50fb50()->init50de10(kc_cefc64,hitC,line7.at9e7c10(m).add409b60(hit_->off),kc_cfbec0,0,0,9);
       }
      }
      int newStart=rng.rangeInt406d70(0.0f,(float)(line7.size9b9a50()*kc_c36da8));
      for(int m2=newStart;m2<=last;m2++){
       if(inBounds4173d0(line7.at9e7c10(m2).add409b60(hit_->off))){
        if(kc_cefb3c)setBack417fc0(line7.at9e7c10(m2).x+hit_->off.x,line7.at9e7c10(m2).y+hit_->off.y,KcColor::lerp(kc_d29804,*kc_d30424,(float)((float)(m2-newStart)/(last-newStart)*cells0.at9b81f0(m2)/maxD)),true);
        else setBack417fc0(line7.at9e7c10(m2).x+hit_->off.x,line7.at9e7c10(m2).y+hit_->off.y,KcColor::scale(*kc_d30424,(float)((float)(m2-newStart)/(last-newStart)*cells0.at9b81f0(m2)/maxD)),true);
       }
      }
     }
    }
   }
   if(cleanup)kc_clearObjects9d0670(v1a8);
  }
  if(p558&&p558){
   removeSubconsole428b20(p558);
   p558=0;
  }
  if(!v544.empty9b86e0()){
   bool alt=kc_cec14e&&kc_cec14d;
   int sx;
   int sy;
   KcColor bases;
   switch(i554){
   case 0:bases=alt?*kc_cf6b24:(kc_cefb3c?KcColor(0,0x30,0):KcColor(0,0x18,0));break;
   case 1:bases=kc_cefb3c?*kc_cf44c0:*kc_d2175c;break;
   case 2:bases=kc_cefb3c?*kc_d30424:*kc_cf6ed4;break;
   }
   if(i554==0){
    KcColor c;
    for(int i=1;i<v544.size9b9a50();i++){
     sx=v544.at9e7c10(i).x+scroll.x;
     sy=v544.at9e7c10(i).y+scroll.y;
     if(inBounds417360(sx,sy)){
      c=bases;
      if(kc_d28e44&&i>=41){
      if(i>=66)c=alt?*kc_d22130:(kc_cefb3c?KcColor(0.0f,1.0f,kc_c37120):KcColor(0.0f,1.0f,kc_c3711c));
      else if(i>=61)c=alt?*kc_d1dae8:(kc_cefb3c?KcColor(kc_c36fbc,1.0f,kc_c37120):KcColor(kc_c36fbc,1.0f,kc_c3711c));
      else if(i>=56)c=alt?*kc_d338c8:(kc_cefb3c?KcColor(kc_c36fc0,1.0f,kc_c37120):KcColor(kc_c36fc0,1.0f,kc_c3711c));
      else if(i>=51)c=alt?*kc_cf766c:(kc_cefb3c?KcColor(kc_c37118,1.0f,kc_c37120):KcColor(kc_c37118,1.0f,kc_c3711c));
      else if(i>=46)c=alt?*kc_cf13fc:(kc_cefb3c?KcColor(kc_c370ac,1.0f,kc_c37120):KcColor(kc_c370ac,1.0f,kc_c3711c));
      else if(i>=41)c=alt?*kc_d21944:(kc_cefb3c?KcColor(kc_c37038,1.0f,kc_c37120):KcColor(kc_c37038,1.0f,kc_c3711c));
      }
      if(a1->getSize()>1){
       int size=a1->getSize();
       for(int kind=sx,a=0;a<size;kind++,a++)
        for(int y=sy,msg1=0;msg1<size;y++,msg1++)
         if(inBounds417360(kind,y))setBack417fc0(kind,y,c,true);
      }else if(i==1&&kc_cfd44c.contains9b43b0(v544.at9e7c10(i))&&a1->u5c85a0(v544.at9e7c10(i),0)&&(*kc_cfd44c.atPoint9ced70(v544.at9e7c10(i)))->getEntity()->getTarget()==0&&!a1->u45aaa0((*kc_cfd44c.atPoint9ced70(v544.at9e7c10(i)))->getEntity())&&a1->u5d1390()!=4&&a1->u5d5d40().isNull9b65d0()&&!kc_cf45d8.u77f260(100))
       setBack417fc0(sx,sy,alt?*kc_d204ac:*kc_d30424,true);
      else setBack417fc0(sx,sy,c,true);
      if(i+(kc_d28c8a?1:2)>=v544.size9b9a50())break;
     }
    }
    if(alt&&kc_d28e45&&v544.size9b9a50()>2){
     string tu=" "+kc_intToString4051f0(kc_cefc4c->getPlayer4630f0()->u5d15a0(0)*v544.size9b9a50())+" TU ";
     bool bs=v544.at9e7c10(v544.size9b9a50()-2).x<=v544.back9e8c10().x;
     int len=tu.size();
     if(kc_isOdd406340(len))len++;
     KcPos pos=v544.back9e8c10().add409b60(scroll);
     if(!bs&&len>pos.x*2)bs=true;
     p558=new KcSubCon(this,len,1,bs?pos.x+1:pos.x-len/2,pos.y,0,false,0x32);
     p558->setBgColor418410(*kc_cf13fc);
     p558->setFore(*kc_cfe674);
     p558->print4181d0(0,0,tu);
    }
   }else if(!kc_d28e3d){
    sx=v544.front9b7060().x+scroll.x;
    sy=v544.front9b7060().y+scroll.y;
    if(inBounds417360(sx,sy))setBack417fc0(sx,sy,bases,true);
   }
  }
  if(p6b0&&a0&&p4c8.eq409b90(a2)&&kc_cec11c->isHidden()&&kc_cec0f8->isHidden()){
   KcBlastArea*area=&a6d0;
   KcPos g52=p6b8;
   float maxV=kc_c36ec8;
   int pI=1500;
   int msg5=30;
   int fx;
   kc_lookup9d45a0("CMap_Expl_Victim",fx);
   KcPos lo(99999);
   KcPos newHi(-1);
   bool anyHit=false;
   for(int y=area->top44afb0(),h25=area->top44afb0()+scroll.y;y<=area->bottom9b6c30()&&h25<kc_cf27f8;y++,h25++){
    if(h25<0)continue;
    float f=kc_caed20/pI%2&&kc_caed20%pI/msg5==y-area->top44afb0()?1-abs(area->top44afb0()+area->h418900()/2-y)*kc_c37110/(area->h418900()/2)+kc_c36de8:0;
    for(int msg9=area->left9b6bf0(),sx=area->left9b6bf0()+scroll.x;msg9<=area->right9b6c10()&&sx<kc_cf27f4;msg9++,sx++){
     if((*area)(msg9,y)!=0&&inBounds417360(sx,h25)&&(!aH||*aH->at9cec50(msg9,y))&&!CELL(msg9,y)->u66b120()){
      if(f!=0){
       setBack417fc0(sx,h25,*kc_d2981c*f,true);
       if(getChar(sx,h25)!='.'&&fx)kc_cefc64->new50fb50()->init50de10(kc_cefc64,fx,KcPos(sx,h25),kc_cfbec0,0,0,9);
      }else setBack417fc0(sx,h25,*kc_cf6b24*(kc_minf9cd050((*area)(msg9,y),maxV)/maxV)+kc_d29804,true);
      if(sx<lo.x)lo.x=sx;
      else if(sx>newHi.x)newHi.x=sx;
      if(h25<lo.y)lo.y=h25;
      else if(h25>newHi.y)newHi.y=h25;
     }
    }
    if(f!=0)anyHit=true;
   }
   if(anyHit){
    if(!bfc){
     kc_sound4541b0(0x3d,0,0);
     bfc=true;
    }
   }else bfc=false;
   if(p6b0->i40==0){
    KcColor col=*kc_d2175c*kc_c36eb4;
    KcPos msgA;
    KcPos b;
    b.set409ff0(-1);
    bool left;
    bool kB;
    bool c9;
    if(kc_cefc4c->player->getPosition().x<=p6b8.x){
     left=true;
     msgA.x=p6b8.x+scroll.x+p6b0->i3c+1;
     if(msgA.x<width44b0d0())b.x=0;
    }else{
     left=false;
     if((msgA.x=p6b8.x+scroll.x-(p6b0->i3c+1))>=0)b.x=0;
    }
    if(b.x!=-1){
     c9=kB=true;
     if((msgA.y=p6b8.y+scroll.y-p6b0->i3c)<0){
      c9=false;
      msgA.y=0;
     }
     b.y=p6b8.y+scroll.y+p6b0->i3c;
     if(b.y>getHeight4174c0()-1){
      kB=false;
      b.y=getHeight4174c0()-1;
     }
     b.x=msgA.x;
     for(int y=msgA.y;y<=b.y;y++){
      if(y==msgA.y&&c9)putChar418110(msgA.x,y,left?0x89:0x88,col);
      else if(y==b.y&&kB)putChar418110(msgA.x,y,left?0x8a:0x87,col);
      else putChar418110(msgA.x,y,0x80,col);
     }
    }
    b.set409ff0(-1);
    bool nDef;
    if(kc_cefc4c->player->getPosition().y<=p6b8.y){
     nDef=true;
     msgA.y=p6b8.y+scroll.y+p6b0->i3c+1;
     if(msgA.y<getHeight4174c0())b.y=0;
    }else{
     nDef=false;
     if((msgA.y=p6b8.y+scroll.y-(p6b0->i3c+1))>=0)b.y=0;
    }
    if(b.y!=-1){
     c9=kB=true;
     if((msgA.x=p6b8.x+scroll.x-p6b0->i3c)<0){
      c9=false;
      msgA.x=0;
     }
     b.x=p6b8.x+scroll.x+p6b0->i3c;
     if(b.x>width44b0d0()-1){
      kB=false;
      b.x=width44b0d0()-1;
     }
     b.y=msgA.y;
     for(int x=msgA.x;x<=b.x;x++){
      if(x==msgA.x&&c9)putChar418110(x,msgA.y,nDef?0x87:0x88,col);
      else if(x==b.x&&kB)putChar418110(x,msgA.y,nDef?0x8a:0x89,col);
      else putChar418110(x,msgA.y,0x81,col);
     }
    }
   }
  }else bfc=false;
  if(a0&&p4c8.eq409b90(a2)&&kc_cec11c->isHidden()&&kc_cec0f8->isHidden()){
   int sx;
   int sy;
   float f;
   if(!v530.empty9b86e0()){
    for(unsigned i=0;i<v530.size9b9a50();i++){
     sx=v530.at9e7c10(i).x+scroll.x;
     sy=v530.at9e7c10(i).y+scroll.y;
     if(inBounds417360(sx,sy))setBack417fc0(sx,sy,*kc_d2175c,true);
    }
   }
   for(unsigned i=0;i<v4dc.size9b9a50();i++){
    sx=v4dc.at9e7c10(i).x+scroll.x;
    sy=v4dc.at9e7c10(i).y+scroll.y;
    if(inBounds417360(sx,sy)){
     if(kc_containsRecord9db330((int*)&v520,i))setBack417fc0(sx,sy,*kc_d386c8,true);
     else if(v4ec.at9b81f0(i)!=0&&i<v4ec.size9b9260()-1)setBack417fc0(sx,sy,KcColor::lerp(getBack(sx,sy),*kc_cf0d3c,kc_pulse4371a0(kc_ba6af0,kc_ba6af4,1000,0)),true);
     else{
      f=kc_minInt9cdb30(v4fc.at9b81f0(i),9)/kc_c36cf8;
      setBack417fc0(sx,sy,KcColor::add(getBack(sx,sy),(b4d8?*kc_d2981c:*kc_d204ac)*f),true);
      if(i+1==v4dc.size9b9a50())setBack417fc0(sx,sy,KcColor::addAlpha(getBack(sx,sy),*kc_d28fd8,kc_pulse4371a0(kc_ba6ae8,kc_ba6aec,1000,0)),true);
     }
    }
   }
   if(!v50c.empty9b86e0()&&b4c4){
    for(unsigned i=0;i<v50c.size9b5100();i++){
     sx=v50c.at9b8070(i).x1+scroll.x;
     sy=v50c.at9b8070(i).y1+scroll.y;
     if(inBounds417360(sx,sy)){
      bool last=i==v50c.size9b5100()-1&&v50c.size9b5100()==kc_d1da44.get9b65b0()->u4580c0();
      setBack417fc0(sx,sy,KcColor::addAlpha(getBack(sx,sy),last?*kc_d230f4:*kc_d1f254,kc_pulse4371a0(last?kc_ba6b7c:kc_ba6b74,last?kc_ba6b80:kc_ba6b78,1500,-i*(1500/(int)v50c.size9b5100()))),true);
     }
    }
   }
  }else if(a0&&(!kc_cefa94->u41a6e0()||i680==8)){
   KcPos p(a2.x+scroll.x,a2.y+scroll.y);
   setBack417fc0(p.x,p.y,KcColor::addAlpha(getBack(p.x,p.y),*kc_d2a2dc,kc_pulse4371a0(kc_ba6ad4,kc_ba6ad8,1000,0)),true);
   if(*aVisible->atPoint9ced70(a2)!=0&&(*kc_cfd44c.atPoint9ced70(a2))->getEntity().isValid()&&(*kc_cfd44c.atPoint9ced70(a2))->getEntity()->getSize()>1){
    KcVPos&cells=(*kc_cfd44c.atPoint9ced70(a2))->getEntity()->u45d1a0();
    for(unsigned i=0;i<cells.size9b9a50();i++){
     if(cells.at9e7c10(i).eq409bd0(a2)&&*aVisible->atPoint9ced70(cells.at9e7c10(i))!=0){
      p.set40a010(cells.at9e7c10(i).x+scroll.x,cells.at9e7c10(i).y+scroll.y);
      if(inBounds4173d0(p))setBack417fc0(p.x,p.y,KcColor::addAlpha(getBack(p.x,p.y),*kc_d2a2dc,kc_pulse4371a0(kc_ba6ad4,kc_ba6adc,1000,0)),true);
     }
    }
   }
  }
  fp=kc_c36fc8;
  if(kc_caed20<kc_d1da40+fp&&kc_d1da3c.operator->()&&kc_cefc4c->u4631f0(kc_d1da3c)){
   KcVPos&cells=kc_d1da3c->u45d1a0();
   for(unsigned i=0;i<cells.size9b9a50();i++){
    if(kc_cefc4c->isVisible4631c0(cells.at9e7c10(i))){
     KcPos p=cells.at9e7c10(i).add409b60(scroll);
     if(inBounds4173d0(p))setBack417fc0(p.x,p.y,KcColor::lerp(getBack417750(p),*kc_d204ac,(float)(fp-(kc_caed20-kc_d1da40))/fp),true);
    }
   }
  }
  if(!v28c.empty9b86e0()){
   if(!kc_d338cc.isDown439510(0x6f)&&(kc_cec0c8->isHidden()||!kc_cec0c8->u48f210()))u819cb0();
   else{
    const int period=1000;
    for(unsigned i=0;i<v28c.size9b9260();i++){
     int sx;
     int sy;
     if(v27c.at9b8070(i).size9b9a50()==1){
      sx=v27c.at9b8070(i).front9b7060().x+scroll.x;
      sy=v27c.at9b8070(i).front9b7060().y+scroll.y;
      if(inBounds417360(sx,sy))setBack417fc0(sx,sy,KcColor::lerp(kc_d29804,kc_cfc1cb[v28c.at9b81f0(i)].c,kc_pulse4371a0(0.0f,1.0f,period,0)),true);
     }else{
      const KcColor&c0=kc_cfc1c8[v28c.at9b81f0(i)].c;
      const KcColor&c1=kc_cfc1cb[v28c.at9b81f0(i)].c;
      int old0=kc_minInt9cdb30((kc_caed20%period/kc_c36fd8)*v27c.at9b8070(i).size9b9a50(),v27c.at9b8070(i).size9b9a50()-1);
      if(old0==0){
       sx=v27c.at9b8070(i).at9e7c10(old0).x+scroll.x;
       sy=v27c.at9b8070(i).at9e7c10(old0).y+scroll.y;
       if(inBounds417360(sx,sy))setBack417fc0(sx,sy,c1,true);
      }else{
       for(int k=0;k<=old0;k++){
        sx=v27c.at9b8070(i).at9e7c10(k).x+scroll.x;
        sy=v27c.at9b8070(i).at9e7c10(k).y+scroll.y;
        if(inBounds417360(sx,sy))setBack417fc0(sx,sy,KcColor::lerp(c0,c1,(float)k/old0),true);
       }
      }
      for(int k=old0+1;k<v27c.at9b8070(i).size9b9a50();k++){
       sx=v27c.at9b8070(i).at9e7c10(k).x+scroll.x;
       sy=v27c.at9b8070(i).at9e7c10(k).y+scroll.y;
       if(inBounds417360(sx,sy))setBack417fc0(sx,sy,KcColor::lerp(c1,c0,(float)(k-(old0+1))/(v27c.at9b8070(i).size9b9a50()-(float)(old0+1))),true);
      }
     }
    }
   }
  }
  if(i6fc!=-1){
   int idx=kc_cec0c8->u48f100();
   const KcColor&c0=kc_cfc1c8[idx].c;
   const KcColor&old4=kc_cfc1cb[idx].c;
   int rf21;int sy;
   for(unsigned i=0;i<v708.size9b5100();i++)
    for(int j=0;j<v708.at9b8070(i).size9b9a50();j++){
     rf21=v708.at9b8070(i).at9e7c10(j).x+scroll.x;
     sy=v708.at9b8070(i).at9e7c10(j).y+scroll.y;
     if(inBounds417360(rf21,sy))setBack417fc0(rf21,sy,KcColor::lerp(c0,old4,(float)j/(v708.at9b8070(i).size9b9a50()-1)),true);
    }
  }
  if(u49aa60()||kc_cec130&&kc_cec130->u48e040()==11&&kc_cec130->u48c360()==3){
   KcVEnt&ents=kc_cec0c8->u48f0e0();
   for(unsigned i=0;i<ents.size9b9260();i++){
    KcVPos&cells=ents.at9b81f0(i)->u45d1a0();
    for(unsigned j=0;j<cells.size9b9a50();j++)
     if(inBounds4173d0(cells.at9e7c10(j).add409b60(scroll)))setBack417fc0(cells.at9e7c10(j).x+scroll.x,cells.at9e7c10(j).y+scroll.y,KcColor::addAlpha(getBack417750(cells.at9e7c10(j).add409b60(scroll)),*kc_d30264,kc_pulse4371a0(kc_ba6ae0,kc_ba6ae4,1000,0)),true);
   }
  }else{
   KcHE h=kc_cec0c8->u48f120();
   if(h.isValid()){
    KcVPos&cells=h->u45d1a0();
    for(unsigned j=0;j<cells.size9b9a50();j++)
     if(inBounds4173d0(cells.at9e7c10(j).add409b60(scroll)))setBack417fc0(cells.at9e7c10(j).x+scroll.x,cells.at9e7c10(j).y+scroll.y,KcColor::addAlpha(getBack417750(cells.at9e7c10(j).add409b60(scroll)),*kc_d30264,kc_pulse4371a0(kc_ba6ae0,kc_ba6ae4,1000,0)),true);
   }
  }
  a9=1000;
  aI=kc_d22fcc;
  if(kc_caed20<kc_d1d9e8+1000){
   KcPos p=kc_cefc4c->getPlayer4630f0()->getPosition().add409b60(scroll).sub409b30(kc_d1d9dc);
   if(inBounds4173d0(p)){
    if(kc_d1d9dc.eq409cb0(0,0)){
     KcArea2 r;
     buf4184d0()->getRect9b4430(p,1,r);
     for(int x=r.x1;x<=r.x2;x++)
      for(int y=r.y1;y<=r.y2;y++)
       if(p.ne409cf0(x,y))setBack417fc0(x,y,KcColor::addAlpha(BG(x,y),*aI,kc_fade437250(1.0f,kc_d1d9e8,1000)),true);
    }else{
     for(int x=p.x,y=0;y<kc_cf27f8;y++)setBack417fc0(x,y,KcColor::addAlpha(BG(x,y),*aI,kc_fade437250(1.0f,kc_d1d9e8,1000)),true);
     for(int x=0,y=p.y;x<kc_cf27f4;x++)setBack417fc0(x,y,KcColor::addAlpha(BG(x,y),*aI,kc_fade437250(1.0f,kc_d1d9e8,1000)),true);
    }
   }
  }
  if(kc_d1d9dc.ne409cf0(0,0)&&kc_d28e2c&&(!kc_d28c8a||kc_d1d9e6)){
   int off=kc_d28e2c;
   const int old8=400;
   int oldH=off+old8;
   if(kc_caed20%oldH>off){
    KcColor c=*kc_d1ecd4;
    KcPos p=kc_cefc4c->getPlayer4630f0()->getPosition().add409b60(scroll).sub409b30(kc_d1d9dc);
    if(inBounds4173d0(p)){
     unsigned oldT=kc_caed20%oldH-off;
     float f=1.0f*sin((float)(oldT/kc_c37068*kc_c36c98));
     setBack417fc0(p.x,p.y,c*f,true);
    }
   }
  }
  if(!v218.empty9b86e0()){
   const int dur=600;
   if(kc_caed20>t228+dur)v218.clear9b73d0();
   else{
    KcVPos oldP;
    KcArea2 r;
    for(unsigned i=0;i<v218.size9b9260();i++)
     for(unsigned j=0;j<v218.at9b81f0(i)->u45d1a0().size9b9a50();j++){
      kc_cfd44c.getRect9b4430(v218.at9b81f0(i)->u45d1a0().at9e7c10(j),1,r);
      for(int x=r.x1;x<=r.x2;x++)
       for(int y=r.y1;y<=r.y2;y++)
        if(CELL(x,y)->getEntity().isNull9b65d0()||!kc_containsEntity9d31e0((KcVHE*)&v218,CELL(x,y)->getEntity()))kc_addUnique9d3020(oldP,KcPos(x,y));
     }
    KcColor c=kc_cefb3c?KcColor::lerp(kc_d29804,*kc_d204ac,kc_fade437250(1.0f,t228,dur)):KcColor::scale(*kc_d204ac,kc_fade437250(1.0f,t228,dur));
    for(unsigned i=0;i<oldP.size9b9a50();i++){
     KcPos p=oldP.at9e7c10(i).add409b60(scroll);
     if(inBounds4173d0(p))setBack417fc0(p.x,p.y,c,true);
    }
   }
  }
  kc_cefc64->render5100b0();
  if(!v4b4.empty9b86e0()){
   for(unsigned i=0;i<v4b4.size9b9260();i++)
    if(v4b4.at9b81f0(i))removeSubconsole428b20(v4b4.at9b81f0(i));
   v4b4.clear9bac80();
  }
  if(!kc_cefc4c->v7f0.empty9b86e0()&&kc_d28e88){
   int off=kc_d28e88;
   const int pAdd=800;
   int pOld=off+pAdd;
   bool any=hasAnyLabel49b490();
   if(kc_caed20%pOld>off){
    KcColor c1=*kc_d32efc;
    KcColor c2=*kc_d32968;
    for(unsigned i=0;i<kc_cefc4c->v7f0.size9b9260();i++){
     KcPos p=kc_cefc4c->v7f0.at9b81f0(i)->pos.add409b60(scroll);
     if(inBounds4173d0(p)){
      unsigned pos2=kc_caed20%pOld-off;
      float f=1.0f*sin((float)(pos2/kc_c37060*kc_c36c98));
      setFore417f80(p.x,p.y,c1*f);
      setBack417fc0(p.x,p.y,c2*f,true);
      if(kc_d28e8c&&!any&&i680!=8&&!bd8){
       KcColor pos6=kc_cefc4c->v7f0.at9b81f0(i)->i24?*kc_cf13fc:*kc_d1e048;
       KcColor bc=*kc_d32968;
       KcSubCon*sc=new KcSubCon(this,kc_cefc4c->v7f0.at9b81f0(i)->name.size(),1,p.x+1,p.y,kc_d28d15?1:0,false,-1);
       sc->setFore(pos6*f);
       sc->print4181d0(0,0,kc_cefc4c->v7f0.at9b81f0(i)->name);
       sc->setBgColor418410(bc*f);
       v4b4.push_back9b9d30(sc);
      }
     }
    }
   }
  }
  u8680b0();
  if(kc_d28d15||kc_hasPtr4328a0())u86e310();
  if(kc_cefc5c&&kc_d28d15){
   if(p8bc&&kc_caed20>=t8c0+25){
    if(p8bc){
     removeSubconsole428b20(p8bc);
     p8bc=0;
    }
   }else if(rng.chance406cc0(kc_c37108)){
    KcVEnt&ents=kc_cefc4c->u463890(1)->u416f40();
    for(unsigned i=0;i<ents.size9b9260();i++){
     if(ents.at9b81f0(i)->getFaction()==9&&kc_cefc4c->isVisible4631c0(ents.at9b81f0(i)->getPosition())&&u8052f0(ents.at9b81f0(i)->getPosition())){
      p8bc=new KcSubCon(this,4,2,ents.at9b81f0(i)->getPosition().x+scroll.x,ents.at9b81f0(i)->getPosition().y+scroll.y,0,false,-1);
      p8bc->setBgColor418410(*kc_cfe674);
      p8bc->setFore(ents.at9b81f0(i)->color5c7630());
      p8bc->print4181d0(0,0,"BOT ");
      p8bc->print4181d0(0,1,"NET!");
      t8c0=kc_caed20;
      break;
     }
    }
   }
  }
  g_=&kc_cefc4c->u463890(0)->u416f40();
  for(int i=g_->size9b9260()-1;i>=0;i--){
   if(!u8052f0(g_->at9b81f0(i)->getPosition())&&g_->at9b81f0(i)->getTarget()==0){
    KcPos p=clampToView83d9b0(g_->at9b81f0(i)->getPosition());
    putChar418110(p.x,p.y,g_->at9b81f0(i)->getAsciiDefault5c79d0(),*kc_cfe674);
    setBack417fc0(p.x,p.y,g_->at9b81f0(i)->color5c7630()*kc_pulse4371a0(kc_ba6be8,kc_ba6bec,2000,0),true);
   }
  }
  if(kc_cf462c==7){
   if(kc_cefc4c->getEntity463110().isValid()){
    KcHE e=kc_cefc4c->getEntity463110();
    if(!kc_cefc4c->isVisible4631c0(e->getPosition())){
     KcPos p;
     if(!u8052f0(e->getPosition()))p=clampToView83d9b0(e->getPosition());
     else{
      p=e->getPosition();
      p.sub409a30(scroll);
     }
     putChar418110(p.x,p.y,0x40,*kc_cfe674);
     setBack417fc0(p.x,p.y,*kc_d25f70*kc_pulse4371a0(kc_ba6be8,kc_ba6bec,2000,0),true);
    }
   }
  }
  if(p38c.x!=-1){
   if(kc_caed20>t394+10000)p38c.x=-1;
   else if(!u8052f0(p38c)){
    KcPos p=clampToView83d9b0(p38c);
    putChar418110(p.x,p.y,0x5e,*kc_cfe674);
    setBack417fc0(p.x,p.y,*kc_d20618*kc_pulse4371a0(kc_ba6be8,kc_ba6bec,2000,0),true);
   }
  }
  aT=9;
  if(kc_cec0c8->u48f0a0()||kc_cec0c8->u48f0c0())aT=0;
  else if(i680==8&&i684==3)aT=1;
  else if(kc_cec0cc->u48f8b0())aT=2;
  else if(kc_cec090->getHighlighter4ab670()==1)aT=3;
  else if(kc_cec094->u4ab570())aT=4;
  else if(kc_cec098->u4ab4a0())aT=5;
  else if(kc_cec09c->u4ab570())aT=6;
  else if(kc_cec0a0->u4ab690()&&kc_cec0a0->getHighlighter4ab670()!=2)aT=7;
  else if(kc_caed20<=t1f0+10000&&i1f4)aT=8;
  if(aT==9){
   if(p7a8&&p7a8){
    removeSubconsole428b20(p7a8);
    p7a8=0;
   }
   kc_cec0f4->setPos417a90(kc_d1e1c8,kc_d1e1cc);
  }else{
   if(p7a8&&p7a8->i6c!=aT&&p7a8){
    removeSubconsole428b20(p7a8);
    p7a8=0;
   }
   if(!p7a8)p7a8=new KcModeLabel(this,aT);
   p7a8->u7f48e0();
   kc_cec0f4->setPos417a90(kc_d1e1c8,kc_d1e1cc+1);
  }
  if(kc_cefacd||kc_cf45d8.u46dd50()){
   setFore(*kc_d1f3a4);
   setBack(*kc_d01d4c);
   KcArea2 view;
   view8051f0((KcPos*)&view.x1,(KcPos*)&view.x2);
   if(kc_cefb10&&a0){
    print4181d0(0,getHeight4174c0()-1,kc_pointToString40a4a0(a2));
    KcPos sp(a2.x+scroll.x,a2.y+scroll.y);
    printAligned418220(width44b0d0()-1,getHeight4174c0()-1,2,kc_pointToString40a4a0(sp));
   }
   if(kc_cefb12){
    string s="FOV enemies = "+kc_intToString4051f0(kc_cefc4c->u4636d0());
    print4181d0(0,getHeight4174c0()-2,s);
    s="FOV threats = "+kc_intToString4051f0(kc_cefc4c->u463710());
    printAligned418220(width44b0d0()-1,getHeight4174c0()-2,2,s);
   }
   if(kc_cefb13&&a0&&!v544.empty9b86e0())print4181d0(0,getHeight4174c0()-3,"Path = "+kc_intToString4051f0(v544.size9b9a50()));
   if(kc_cefb19){
    KcPos m=kc_cefa94->topLeft40a970();
    print4181d0(0,0,"Coord = "+kc_pointToString40a4a0(m));
    print4181d0(0,1,"glyphAreaIndex = "+kc_intToString4051f0((*kc_d223f0.get4ab670()->u418570()->atPoint9ced70(m))->i4));
    KcFontCell*fc=kc_d223f0.get4ab670()->u417780(m);
    print4181d0(0,2,"Font = "+kc_intToString4051f0(fc->width9fcd80()));
    print4181d0(0,3,"Ascii = "+kc_intToString4051f0(fc->height9b8f00()));
    print4181d0(0,4,"Glyph = "+kc_intToString4051f0(fc->width9fcd80()));
    print4181d0(0,5,"Fgd = "+fc->fore416f40()->toString4121c0());
    print4181d0(0,6,"Bkg = "+fc->back416f60()->toString4121c0());
   }
   if(!kc_d2d4c8.empty9b86e0()){
    for(unsigned i=0,y=2;i<kc_d2d4c8.size9b0650();i++,y++)print4181d0(0,y,kc_d2d4c8.at9b06a0(i));
   }
   if(kc_cefb1b&&!kc_d3977c.empty9b86e0())setBack417fc0(kc_d3977c.front9b7060()->i24+scroll.x,kc_d3977c.front9b7060()->i28+scroll.y,*kc_cfc180,true);
   if(b7f8){
    KcBlastArea*a=kc_cefc4c->u465a30();
    float lo_=kc_c36f88;
    float posB=1.0f;
    float maxV=kc_c36ec8;
    for(int posN=a->left9b6bf0(),sx=a->left9b6bf0()+scroll.x;posN<=a->right9b6c10();posN++,sx++)
     for(int y=a->top44afb0(),h33=a->top44afb0()+scroll.y;y<=a->bottom9b6c30();y++,h33++)
      if((*a)(posN,y)!=0)setBack417fc0(sx,h33,*kc_d35bbc*(kc_minf9cd050((*a)(posN,y),maxV)/maxV*(posB-lo_)+lo_),true);
   }
   if(kc_cefb15){
    KcPos p;
    for(unsigned i=0;i<kc_d2d4f4.size9b9a50();i++){
     p=kc_d2d4f4.at9e7c10(i).add409b60(scroll);
     if(inBounds4173d0(p))setBack417fc0(p.x,p.y,*kc_d20438,true);
    }
   }
   if(b7fa){
    if(kc_cefae8){
     for(int pts6=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);pts6<=toN.x&&sx<kc_cf27f4;pts6++,sx++)for(int y=from3.y,h48=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&h48<kc_cf27f8;y++,h48++)
      if(*a7fc.at9ceda0(pts6,y)!=0&&getBack(sx,h48)==kc_d29804)setBack417fc0(sx,h48,*a814.at9d4730(pts6,y),true);
    }else if(kc_cefadf){
     for(int ptsB=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);ptsB<=toN.x&&sx<kc_cf27f4;ptsB++,sx++)for(int y=from3.y,hi1=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&hi1<kc_cf27f8;y++,hi1++)
      if(CELL(ptsB,y)->u4550b0()&&*a808.at9ceda0(ptsB,y)!=0&&getBack(sx,hi1)==kc_d29804)setBack417fc0(sx,hi1,*kc_d15d98*(*a808.at9ceda0(ptsB,y)/kc_c36cd0),true);
    }else{
     for(int ptsN=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);ptsN<=toN.x&&sx<kc_cf27f4;ptsN++,sx++)for(int y=from3.y,k15=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&k15<kc_cf27f8;y++,k15++){
      if(*a7fc.at9ceda0(ptsN,y)!=0){
       if(getBack(sx,k15)==kc_d29804)setBack417fc0(sx,k15,*kc_d21b44*(*a7fc.at9ceda0(ptsN,y)/kc_c36cd0),true);
      }else if(kc_cefade&&CELL(ptsN,y)->u4550b0()&&getBack(sx,k15)==kc_d29804)setBack417fc0(sx,k15,*kc_cf63b0,true);
     }
    }
   }
   if(kc_cefadd){
    KcVPos qq42;
    KcVInt m5;
    KcPos pp=kc_cefc4c->getPlayer4630f0()->getPosition();
    KcVPos path;
    KcPos lo;
    KcPos m7;
    int m0;
    kc_cfd44c.getBounds9b7a40(pp,0x19,lo,m7);
    for(int y=lo.y;y<=m7.y;y++)
     for(int x=lo.x;x<=m7.x;x++){
      if(CELL(x,y)->getProp().isValid()&&CELL(x,y)->getProp().get9b64f0()->u457b10()==0&&CELL(x,y)->getProp().get9b64f0()->u45cad0()&&!CELL(x,y)->getProp().get9b64f0()->u45caf0()){
       m0=kc_atten500500(CELL(x,y)->getProp().get9b64f0()->def9b8f00()->p15c,KcPos(x,y),pp);
       if(m0!=0){
        int idx=kc_indexOfPoint9d53a0(qq42,pp);
        if(idx==-1){
         qq42.push_back9b32e0(pp);
         m5.push_back9b9d30(m0);
        }else if(m0>m5.at9b81f0(idx))m5.at9b81f0(idx)=m0;
        path.clear9b3560();
        kc_cfd44c.getRect9b4430(KcPos(x,y),CELL(x,y)->getProp().get9b64f0()->def9b8f00()->p15c->i70,kc_d35b84);
        kc_cfe568.findPath40c9a0(KcPos(x,y),pp,kc_cefc48,0,path);
        kc_eraseAt9d5190(path,0);
        for(unsigned k=0;k<path.size9b9a50();k++){
         m0=kc_atten500500(CELL(x,y)->getProp().get9b64f0()->def9b8f00()->p15c,KcPos(x,y),path.at9e7c10(k));
         if(m0!=0){
          idx=kc_indexOfPoint9d53a0(qq42,path.at9e7c10(k));
          if(idx==-1){
           qq42.push_back9b32e0(path.at9e7c10(k));
           m5.push_back9b9d30(m0);
          }else if(m0>m5.at9b81f0(idx))m5.at9b81f0(idx)=m0;
         }
        }
       }
      }
     }
    for(unsigned i=0;i<qq42.size9b9a50();i++){
     KcPos p=qq42.at9e7c10(i).add409b60(scroll);
     if(inBounds4173d0(p)&&getBack(p.x,p.y)==kc_d29804)setBack417fc0(p.x,p.y,*kc_d21b44*(m5.at9b81f0(i)/kc_c36cd0),true);
    }
   }
   if(b838){
    KcVI&types=kc_cefc4c->u465a90();
    KcVVP3&areas=kc_cefc4c->u465ab0();
    for(unsigned i=0;i<areas.size9b5100();i++){
     KcColor c=*kc_cfc180;
     switch(types.at9b81f0(i)){
     case 0x12e:c=*kc_d29758;break;
     case 0x130:c=*kc_cfe5a0;break;
     default:
      switch(kc_d21afc.at9b81f0(types.at9b81f0(i))->i24){
      case 0:c=*kc_d201c4;break;
      case 1:c=*kc_d2981c;break;
      case 2:c=*kc_cf27e8;break;
      case 3:c=*kc_d204ac;break;
      }
     }
     for(unsigned j=0;j<areas.at9b8070(i).size9b9a50();j++)
      if(view.contains40b750(areas.at9b8070(i).at9e7c10(j)))setBack417fc0(areas.at9b8070(i).at9e7c10(j).x+scroll.x,areas.at9b8070(i).at9e7c10(j).y+scroll.y,c,true);
    }
    if(a0){
     for(unsigned i=0;i<areas.size9b5100();i++){
      if(kc_containsPt9d0ce0(areas.at9b8070(i),a2)){
       printAligned418220(width44b0d0()/2,0,1,types.at9b81f0(i)==0x12e?string("(empty)"):types.at9b81f0(i)==0x130?string("(failed)"):kc_d21afc.at9b81f0(types.at9b81f0(i))->name);
       break;
      }
     }
    }
    for(int qq46=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);qq46<=toN.x&&sx<kc_cf27f4;qq46++,sx++)for(int y=from3.y,k38=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&k38<kc_cf27f8;y++,k38++){
     if(CELL(qq46,y)->getProp().isValid()&&!CELL(qq46,y)->getProp().get9b64f0()->isTrap45cb70()){
      bool ra11=false;
      bool pG=CELL(qq46,y)->getProp().get9b64f0()->u470b30();
      bool here=a2.eq409cb0(qq46,y);
      if(here)printAligned418220(width44b0d0()/2,getHeight4174c0()-1,1,CELL(qq46,y)->getProp().get9b64f0()->name45c5b0());
      if(CELL(qq46,y)->getProp().get9b64f0()->u45c9b0()){
       if(here){
        KcVSA*sa=CELL(qq46,y)->getProp().get9b64f0()->u45c9b0()->u9c0790();
        for(unsigned k=0;k<sa->size9b9260();k++)printAligned418220(width44b0d0()/2,getHeight4174c0()-(k+2),1,"(SA: "+sa->at9b81f0(k)->u9fcd80()->name+")");
       }
       ra11=true;
      }else if(!CELL(qq46,y)->getProp().get9b64f0()->u45c7e0().empty9b86e0()){
       if(here){
        KcVTraits&tr=CELL(qq46,y)->getProp().get9b64f0()->u45c7e0();
        for(unsigned k=0;k<tr.size9b9260();k++)printAligned418220(width44b0d0()/2,getHeight4174c0()-(k+2),1,"(Trait: "+tr.at9b81f0(k)->info->name+")");
       }
       ra11=true;
      }else if(pG&&here)printAligned418220(width44b0d0()/2,getHeight4174c0()-2,1,"(no SA/traits)");
      if(ra11||pG)setBack417fc0(sx,k38,KcColor::addAlpha(getBack(sx,k38),!ra11&&pG?*kc_d35bbc:ra11?*kc_d35be0:*kc_d2ea1c,kc_pulse4371a0(kc_c36eb4,1.0f,1000,0)),true);
     }
    }
   }
   if(b839&&!kc_cf126c.empty9b86e0()){
    int hue=0;
    int step=360/kc_cf126c.size9b5ec0();
    KcPos pRef;
    for(unsigned i=0;i<kc_cf126c.size9b5ec0();i++){
     KcColor ra15((float)hue,1.0f,1.0f);
     KcVPtsM&cave=kc_cf126c.at9b5ee0(i);
     for(unsigned j=0;j<cave.size9b9a50();j++){
      pRef=cave.at9e7c10(j).add409b60(scroll);
      if(inBounds4173d0(pRef))setBack417fc0(pRef.x,pRef.y,ra15,true);
     }
     hue+=step;
    }
    if(a0){
     for(unsigned i=0;i<kc_cf126c.size9b5ec0();i++){
      if(kc_containsPt9d0ce0(kc_cf126c.at9b5ee0(i),a2)){
       printAligned418220(width44b0d0()/2,0,1,"Cave "+kc_intToString4051f0(i));
       break;
      }
     }
    }
   }
   if(b83c&&kc_cefc4c->i34){
    KcColor cC=*kc_d38644;
    float lo8=kc_c36f88;
    float st=(1.0f-lo8)/kc_cefc4c->i34;
    for(int ra19=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);ra19<=toN.x&&sx<kc_cf27f4;ra19++,sx++)for(int y=from3.y,k43=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&k43<kc_cf27f8;y++,k43++)
     if(CELL(ra19,y)->highlighter4ab670())setBack417fc0(sx,k43,cC*(abs(CELL(ra19,y)->highlighter4ab670())*st+lo8),true);
   }
   if(b83a){
    for(int ra22=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);ra22<=toN.x&&sx<kc_cf27f4;ra22++,sx++)for(int y=from3.y,m46=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&m46<kc_cf27f8;y++,m46++){
     for(unsigned k=0;k<kc_d222f0.size9b5100();k++){
      if(kc_d222f0.at9b8070(k).contains40a9a0(ra22,y)){
       setBack417fc0(sx,m46,*kc_cf27e8,true);
       goto nextCell83a;
      }
     }
     for(unsigned k=0;k<kc_cf3a00.size9b9260();k++){
      if(kc_cf3a00.at9b81f0(k)->contains40a9a0(ra22,y)){
       putChar418150(sx,m46,(kc_cf3a00.at9b81f0(k)->i10>=10?kc_minInt9cdb30(kc_cf3a00.at9b81f0(k)->i10,99)/10:kc_cf3a00.at9b81f0(k)->i10)+0x30,kc_cf3a00.at9b81f0(k)->i10>=10?*kc_cfabbc:*kc_d35bbc,*kc_d204ac,true);
       break;
      }
     }
nextCell83a:;
    }
   }
   if(kc_cefae9){
    for(int ra26=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);ra26<=toN.x&&sx<kc_cf27f4;ra26++,sx++)for(int y=from3.y,myE=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&myE<kc_cf27f8;y++,myE++)
     if(*a820.at9d4730(ra26,y)!=*kc_cfe674)setBack417fc0(sx,myE,*a820.at9d4730(ra26,y),true);
    if(a0){
     KcMG*grp=0;
     string label="Machine Group ";
     int cD;
     for(unsigned i=0;i<kc_d39f1c.size9b9260();i++)
      for(unsigned j=0;j<kc_d39f1c.at9b81f0(i)->size9b9260();j++)
       for(unsigned k=0;k<kc_d31640.at9b8070(kc_d39f1c.at9b81f0(i)->at9b81f0(j)).size9b9260();k++){
        if(a2.eq409b90(kc_d31640.at9b8070(kc_d39f1c.at9b81f0(i)->at9b81f0(j)).at9b81f0(k).get9b64f0()->pos4184d0())){
         cD=i;
         label+=kc_intToString4051f0(cD)+": ";
         grp=kc_d39f1c.at9b81f0(cD);
         goto foundGrp;
        }
       }
foundGrp:
     if(grp){
      KcVPos pts;
      kc_machinePoints83dae0(grp,pts);
      for(unsigned i=0;i<pts.size9b9a50();i++)setBack417fc0(pts.at9e7c10(i).x,pts.at9e7c10(i).y,*kc_cfabbc,true);
      pts.clear9b3560();
      label+=" link x"+kc_intToString4051f0(grp->v10.size9b9260());
      for(unsigned i=0;i<grp->v10.size9b9260();i++)kc_machinePoints83dae0(kc_d39f1c.at9b81f0(grp->v10.at9b81f0(i)),pts);
      for(unsigned i=0;i<pts.size9b9a50();i++)setBack417fc0(pts.at9e7c10(i).x,pts.at9e7c10(i).y,*kc_cfabbc,true);
      pts.clear9b3560();
      kc_conduitPath83dbc0(grp,pts);
      for(unsigned i=0;i<pts.size9b9a50();i++)setBack417fc0(pts.at9e7c10(i).x,pts.at9e7c10(i).y,*kc_cfabbc,true);
      pts.clear9b3560();
      printAligned418220(width44b0d0()/2,0,1,label);
     }
    }
   }
   if(kc_cefaea){
    for(int ra33=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);ra33<=toN.x&&sx<kc_cf27f4;ra33++,sx++)for(int y=from3.y,ok_=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&ok_<kc_cf27f8;y++,ok_++)
     if(*a82c.at9d4730(ra33,y)!=*kc_cfe674)setBack417fc0(sx,ok_,*a82c.at9d4730(ra33,y),true);
    if(a0&&*a82c.atPoint9d4700(a2)!=*kc_cfe674){
     for(unsigned i=0;i<kc_cf44b0.size9b9260();i++){
      if(kc_cf44b0.at9b81f0(i)){
       for(unsigned j=0;j<kc_cf44b0.at9b81f0(i)->vc.size9b9a50();j++){
        if(kc_cf44b0.at9b81f0(i)->vc.at9e7c10(j).eq409b90(a2)){
         string s="Machine Build "+kc_intToString4051f0(i)+": "+kc_cf35b0.at9b81f0(kc_cf44b0.at9b81f0(i)->i0)->name;
         printAligned418220(width44b0d0()/2,0,1,s);
         for(unsigned k=0;k<kc_cf44b0.at9b81f0(i)->vc.size9b9a50();k++){
          KcPos p(kc_cf44b0.at9b81f0(i)->vc.at9e7c10(k).x+scroll.x,kc_cf44b0.at9b81f0(i)->vc.at9e7c10(k).y+scroll.y);
          if(inBounds4173d0(p))setBack417fc0(p.x,p.y,*kc_cfabbc,true);
         }
         goto doneBuild;
        }
       }
      }
     }
    }
   }
doneBuild:;
   if(kc_cefaeb){
    kc_clearDijkstra4faf40();
    kc_cfe568.u40ca20(kc_cefc4c->getPlayer4630f0()->getPosition(),999,&kc_d25624,0);
    if(!kc_d15e58.empty9b86e0()){
     for(unsigned i=0;i<kc_d15e58.size9b9a50();i++){
      KcPos p(kc_d15e58.at9e7c10(i),scroll);
      if(inBounds4173d0(p))setBack417fc0(p.x,p.y,*kc_d25f60,true);
     }
    }
   }
   if(kc_cefaec){
    kc_clearDijkstra4faf40();
    kc_cfe568.u40ca20(kc_cefc4c->getPlayer4630f0()->getPosition(),999,&kc_d39710,0);
    if(!kc_d15e58.empty9b86e0()){
     for(unsigned i=0;i<kc_d15e58.size9b9a50();i++){
      KcPos p(kc_d15e58.at9e7c10(i),scroll);
      if(inBounds4173d0(p))setBack417fc0(p.x,p.y,*kc_d25f60,true);
     }
    }
   }
   if(kc_cefad8&&i134!=36){
    KcPos pp=a1->getPosition();
    KcPos ra37;
    for(int y=from3.y,pUp=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&pUp<kc_cf27f8;y++,pUp++)for(int ra42=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);ra42<=toN.x&&sx<kc_cf27f4;ra42++,sx++){
     if(CELL(ra42,y)->u45db50()&&kc_distance40a3f0(pp,KcPos(ra42,y))<=kc_cefad8){
      ra37.set40a010(ra42,y);
      ra37.sub409a30(scroll);
      setBack417fc0(ra37.x,ra37.y,KcColor::addAlpha(BGP(ra37),*kc_d223e4,kc_pulse4371a0(kc_ba6b08,CELL(ra42,y)->u45a6e0()*kc_ba6b10+kc_ba6b0c,4000,0)),true);
      setChar417f50(ra37.x,ra37.y,kc_minInt9cdb30(CELL(ra42,y)->u45a6e0(),9)+0x30);
     }
    }
   }
   if(b83b){
    KcColor c1;
    KcColor ra46;
    int phase=kc_caed20%1250/250;
    int type;
    switch(phase){
    case 0:type=2;c1=*kc_d1d46c;ra46=*kc_cf44c4;break;
    case 1:type=4;c1=*kc_d30824;ra46=*kc_d32df8;break;
    case 2:type=5;c1=*kc_d2061c;ra46=*kc_d33ac4;break;
    case 3:type=6;c1=*kc_d323c4;ra46=*kc_cfd4cc;break;
    default:type=7;c1=*kc_d30424;ra46=*kc_cf6ed4;break;
    }
    for(unsigned i=0;i<kc_cf6478.size9b9260();i++){
     if(kc_cf6478.at9b81f0(i)->type==type&&kc_cf6478.at9b81f0(i)->h4->ai45b590()->u9b8f00()==3){
      KcVPos&pts=kc_cf6478.at9b81f0(i)->h4->ai45b590()->u4968a0();
      if(!pts.empty9b86e0()){
       for(unsigned j=0;j<pts.size9b9a50();j++)
        if(view.contains40b750(pts.at9e7c10(j)))setBack417fc0(pts.at9e7c10(j).x+scroll.x,pts.at9e7c10(j).y+scroll.y,(*kc_cfd44c.atPoint9ced70(pts.at9e7c10(j)))->u4550b0()?c1:ra46,true);
      }else{
       KcArea2*r=kc_cf6478.at9b81f0(i)->h4->ai45b590()->u4b5730();
       if(view.contains40b750(*(KcPos*)&r->x1)||view.contains40b750(*(KcPos*)&r->x2)||view.u40b700(r->x1,r->y2)||view.u40b700(r->y1,r->x2)){
        for(int x=r->x1;x<=r->x2;x++)
         for(int y=r->y1;y<=r->y2;y++)
          if(view.u40b700(x,y))setBack417fc0(x+scroll.x,y+scroll.y,CELL(x,y)->u4550b0()?c1:ra46,true);
       }
      }
     }
    }
    for(unsigned i=0;i<kc_cf6478.size9b9260();i++){
     if((kc_cf6478.at9b81f0(i)->type==2||kc_cf6478.at9b81f0(i)->type==1||kc_cf6478.at9b81f0(i)->type==3)&&kc_cf6478.at9b81f0(i)->h4->ai45b590()->u9b8f00()==2){
      const KcColor&col=kc_cf6478.at9b81f0(i)->type==2?*kc_d1d46c:kc_cf6478.at9b81f0(i)->type==1?*kc_d30824:*kc_cf44c0;
      KcVPos&rb12=kc_cf6478.at9b81f0(i)->h4->ai45b590()->u458ef0();
      if(rb12.size9b9a50()>=2){
       KcVPos line;
       if(kc_cefc4c->u7168e0(rb12.at9e7c10(0),rb12.at9e7c10(1),kc_cf6478.at9b81f0(i)->h4.operator->(),line)){
        for(unsigned k=0;k<line.size9b9a50();k++)
         if(view.contains40b750(line.at9e7c10(k)))setBack417fc0(line.at9e7c10(k).x+scroll.x,line.at9e7c10(k).y+scroll.y,col,true);
       }
      }
     }
    }
   }
   if(b83d){
    for(int rb16=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);rb16<=toN.x&&sx<kc_cf27f4;rb16++,sx++)for(int y=from3.y,q23=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&q23<kc_cf27f8;y++,q23++){
     if(CELL(rb16,y)->getProp().isValid()&&CELL(rb16,y)->getProp().get9b64f0()->isTrap45cb70()){
      setBack417fc0(sx,q23,KcColor::addAlpha(getBack(sx,q23),*kc_cfc174,kc_pulse4371a0(0.0f,1.0f,1500,0)),true);
      if(CELL(rb16,y)->getProp().get9b64f0()->u470b30()){
       setChar417f50(sx,q23,CELL(rb16,y)->getProp().get9b64f0()->u45c650());
       setFore417f80(sx,q23,CELL(rb16,y)->getProp().get9b64f0()->color65dbb0());
      }
     }
    }
   }
   if(b83e){
    int sx;int sy;
    for(unsigned i=0;i<kc_cefc4c->v538.size9b9a50();i++){
     sx=kc_cefc4c->v538.at9e7c10(i).x+scroll.x;
     sy=kc_cefc4c->v538.at9e7c10(i).y+scroll.y;
     if(inBounds417360(sx,sy))setBack417fc0(sx,sy,KcColor::addAlpha(getBack(sx,sy),*kc_cfc174,kc_pulse4371a0(0.0f,1.0f,1500,0)),true);
    }
   }
   if(!v840.empty9b86e0()){
    for(unsigned i=0;i<v840.size9b9260();i++)
     if(v840.at9b81f0(i))removeSubconsole428b20(v840.at9b81f0(i));
    v840.clear9bac80();
   }
   if(b83f){
    for(int rb30=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);rb30<=toN.x&&sx<kc_cf27f4;rb30++,sx++)for(int y=from3.y,q37=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&q37<kc_cf27f8;y++,q37++){
     if(CELL(rb30,y)->getEntity().isValid()&&CELL(rb30,y)->getEntity()->ai45b590()&&CELL(rb30,y)->getEntity()->ai45b590()->type9b4350()>=2){
      int v=b850?CELL(rb30,y)->getEntity()->u45a8d0():CELL(rb30,y)->getEntity()->u45a990();
      KcSubCon*sc=new KcSubCon(this,kc_intToString4051f0(v).size(),1,sx+1,q37,0,false,-1);
      sc->print4181d0(0,0,kc_intToString4051f0(v));
      sc->setBgColor418410(b850?*kc_d31574:kc_d2cf08[kc_b96118[CELL(rb30,y)->getEntity()->u5ca840()]][kc_b96130[CELL(rb30,y)->getEntity()->u5ca840()]]);
      v840.push_back9b9d30(sc);
     }
    }
   }
   if(!v854.empty9b86e0()){
    for(unsigned i=0;i<v854.size9b9260();i++)
     if(v854.at9b81f0(i))removeSubconsole428b20(v854.at9b81f0(i));
    v854.clear9bac80();
   }
   if(b851){
    for(int rb34=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);rb34<=toN.x&&sx<kc_cf27f4;rb34++,sx++)for(int y=from3.y,rc4=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&rc4<kc_cf27f8;y++,rc4++){
     if(CELL(rb34,y)->getEntity().isValid()){
      int t=kc_d225a0.u672ad0(CELL(rb34,y)->getEntity());
      KcSubCon*sc=new KcSubCon(this,kc_intToString4051f0(t).size(),1,sx+1,rc4,0,false,-1);
      sc->print4181d0(0,0,kc_intToString4051f0(t));
      sc->setBgColor418410(*kc_d35bbc);
      v854.push_back9b9d30(sc);
     }
    }
    KcVQ*q=kc_d225a0.u9c0790();
    int base6=q->at9b81f0(0).get9b73b0()->u9b8f00();
    int rb38;
    for(int y=0,k=0;y<getHeight4174c0()&&k<q->size9b9260();k++,y++){
     rb38=base6-q->at9b81f0(k).get9b73b0()->u9b8f00();
     string s;
     switch(q->at9b81f0(k).get9b73b0()->type9b4350()){
     case 0:
      s=" *** TURN "+kc_intToString4051f0(q->at9b81f0(k).get9b73b0()->u45e590())+" | "+kc_intToString4051f0(rb38)+" ";
      break;
     case 1:
      if(q->at9b81f0(k).get9b73b0()->u45e610().operator->())s=" "+kc_intToString4051f0(q->at9b81f0(k).get9b73b0()->u45e610().id9fcd80())+" | "+q->at9b81f0(k).get9b73b0()->u45e610()->getName45a280()+" | "+kc_intToString4051f0(rb38)+" ";
      break;
     case 2:
      if(q->at9b81f0(k).get9b73b0()->u45e650().get9b65b0())s=" "+kc_intToString4051f0(q->at9b81f0(k).get9b73b0()->u45e650().id9fcd80())+" | "+q->at9b81f0(k).get9b73b0()->u45e650().get9b65b0()->name457860()+" | "+kc_intToString4051f0(rb38)+" ";
      break;
     }
     if(!s.empty()){
      KcSubCon*sc=new KcSubCon(this,s.size(),1,0,y,0,false,-1);
      sc->print4181d0(0,0,s);
      KcColor c=*kc_d35bbc;
      if(rb38>0)c=*kc_d338bc;
      else c*=kc_maxDouble9e2c10(kc_c36cb8,1-rb38/kc_c37100*kc_c36cb8);
      sc->setBgColor418410(c);
      v854.push_back9b9d30(sc);
     }else y--;
    }
   }
   if(p864&&p864){
    removeSubconsole428b20(p864);
    p864=0;
   }
   if(kc_cefb14){
    const int dur=2000;
    bool show=false;
    if(kc_cf6428!=i86c){
     i86c=kc_cf6428;
     t868=kc_caed20;
     show=true;
    }else if(kc_caed20<t868+dur)show=true;
    if(show){
     KcPos p=kc_cefc4c->getPlayer4630f0()->getPosition();
     p.sub409a30(scroll);
     p864=new KcSubCon(this,kc_intToString4051f0(i86c).size(),1,p.x+1,p.y,0,false,-1);
     p864->print4181d0(0,0,kc_intToString4051f0(i86c));
     p864->setBgColor418410(*kc_cfabbc);
    }
   }
   if(!v874.empty9b86e0()){
    for(unsigned i=0;i<v874.size9b9260();i++)
     if(v874.at9b81f0(i))removeSubconsole428b20(v874.at9b81f0(i));
    v874.clear9bac80();
   }
   if(b870){
    unsigned maxLen=0;
    for(int i=0;i<31;i++)
     if(kc_d293c0[i].size()>maxLen)maxLen=kc_d293c0[i].size();
    for(int y=0,i=6;y<getHeight4174c0()&&i<31;i++,y++){
     string s=kc_d293c0[i];
     kc_padLeft408090(s,maxLen,0x20);
     int d1=(int)((kc_cf4634.at9b81f0(i)-kc_c36ca0)*kc_c36cd0);
     string t="  "+kc_intToStringSigned405560(d1)+"%";
     kc_padRight4080d0(t,7,0x20);
     s+=t;
     KcSubCon*sc=new KcSubCon(this,s.size(),1,0,y,0,false,-1);
     sc->print4181d0(0,0,s);
     sc->setBgColor418410(*kc_d2175c);
     sc->setFgColor4183d0(d1>0?*kc_d338bc:*kc_d25f60);
     v874.push_back9b9d30(sc);
    }
   }
   if(b898&&kc_cefc4c->p3d4){
    KcGridI*g=kc_cefc4c->p3d4;
    for(int y=from3.y,rd3=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&rd3<kc_cf27f8;y++,rd3++)for(int rc32=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);rc32<=toN.x&&sx<kc_cf27f4;rc32++,sx++)
     if(*g->at9ceda0(rc32,y)!=0)setBack417fc0(sx,rd3,KcColor::addAlpha(BG(sx,rd3),*kc_d2981c,kc_pulse4371a0(kc_c36f8c,kc_c36eb4,4000,2000)),true);
   }
   if(!v888.empty9b86e0()){
    for(unsigned i=0;i<v888.size9b9260();i++)
     if(v888.at9b81f0(i))removeSubconsole428b20(v888.at9b81f0(i));
    v888.clear9bac80();
   }
   if(b884){
    for(unsigned i=0;i<kc_cefc4c->vf4.size9b9a50();i++){
     if((*kc_cfd44c.atPoint9ced70(kc_cefc4c->vf4.at9e7c10(i)))->u457b10()&&u8052f0(kc_cefc4c->vf4.at9e7c10(i))){
      int n=(*kc_cfd44c.atPoint9ced70(kc_cefc4c->vf4.at9e7c10(i)))->u457b10();
      KcSubCon*rc36=new KcSubCon(this,kc_intToString4051f0(n).size(),1,scroll.x+kc_cefc4c->vf4.at9e7c10(i).x,scroll.y+kc_cefc4c->vf4.at9e7c10(i).y,0,false,-1);
      rc36->setFore(*kc_cfabbc);
      rc36->setBack(kc_d29804);
      rc36->print4181d0(0,0,kc_intToString4051f0(n));
      v888.push_back9b9d30(rc36);
     }
    }
   }
   if(b8ac&&kc_cf447c.width9fcd80()==kc_cfd44c.width9fcd80()&&kc_cf447c.height9b8f00()==kc_cfd44c.height9b8f00()){
    for(int rd30=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);rd30<=toN.x&&sx<kc_cf27f4;rd30++,sx++)for(int y=from3.y,re0=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&re0<kc_cf27f8;y++,re0++)
     if(kc_terrainFlag448b80(KcPos(rd30,y)))setBack417fc0(rd30+scroll.x,y+scroll.y,*kc_d204ac,true);
   }
   if(!b8b1){
    if(p8b4){
     removeSubconsole428b20(p8b4);
     p8b4=0;
    }
   }else if(!p8b4){
    p8b4=new KcSubCon(this,width44b0d0()*2,getHeight4174c0(),0,0,0,false,-1);
    p8b4->setBgColor418410(*kc_cfe674);
    p8b4->setFore(*kc_cfabbc);
    p8b4->print4181d0(0,0,kc_cea004);
   }
   if(b8ad){
    if(!v854.empty9b86e0()){
     for(unsigned i=0;i<v854.size9b9260();i++)
      if(v854.at9b81f0(i))removeSubconsole428b20(v854.at9b81f0(i));
     v854.clear9bac80();
    }
    string a="Abominations: "+kc_intToString4051f0(kc_cefc4c->u464000());
    string rd34="   Anomalies: "+kc_intToString4051f0(kc_cefc4c->u464020());
    KcSubCon*sc=new KcSubCon(this,a.size(),1,0,0,0,false,-1);
    sc->setBgColor418410(kc_cefc4c->u464000()>=kc_cefc4c->u717d60()?*kc_d35bbc:kc_cefc4c->u464000()>=kc_cefc4c->u717d60()/2?*kc_d338bc:*kc_d25f60);
    sc->print4181d0(0,0,a);
    v854.push_back9b9d30(sc);
    sc=new KcSubCon(this,rd34.size(),1,0,1,0,false,-1);
    sc->setBgColor418410(kc_cefc4c->u464020()>=kc_cefc4c->u717dd0()?*kc_d35bbc:kc_cefc4c->u464020()>=kc_cefc4c->u717dd0()/2?*kc_d338bc:*kc_d25f60);
    sc->print4181d0(0,0,rd34);
    v854.push_back9b9d30(sc);
   }
   if(b8b8&&kc_cf45d8.hasCompanion780790()){
    if(!v854.empty9b86e0()){
     for(unsigned i=0;i<v854.size9b9260();i++)
      if(v854.at9b81f0(i))removeSubconsole428b20(v854.at9b81f0(i));
     v854.clear9bac80();
    }
    string s="Affinity: "+kc_intToString4051f0(kc_cf4ac8->i8);
    KcSubCon*sc=new KcSubCon(this,s.size(),1,0,0,0,false,-1);
    sc->setBgColor418410(*kc_d25f60);
    sc->print4181d0(0,0,s);
    v854.push_back9b9d30(sc);
   }
   if(b8ae){
    KcVHeavy d3(kc_cefc4c->u4644b0());
    for(unsigned i=0;i<d3.size9b9260();i++)
     if(!d3.at9b81f0(i).operator->())kc_eraseStep9d6440(d3,i);
    if(!v854.empty9b86e0()){
     for(unsigned i=0;i<v854.size9b9260();i++)
      if(v854.at9b81f0(i))removeSubconsole428b20(v854.at9b81f0(i));
     v854.clear9bac80();
    }
    string s9="Heavies: "+kc_intToString4051f0(d3.size9b9260());
    KcSubCon*cN=new KcSubCon(this,s9.size(),1,0,0,0,false,-1);
    cN->setBgColor418410(*kc_d35bbc);
    cN->print4181d0(0,0,s9);
    v854.push_back9b9d30(cN);
    KcVHeavy sentries;
    KcVHeavy behemoths;
    KcVEnt&aE=kc_cefc4c->u463890(3)->u416f40();
    for(unsigned i=0;i<aE.size9b9260();i++){
     switch(aE.at9b81f0(i)->getFaction()){
     case 0x15:sentries.push_back9b80b0(aE.at9b81f0(i));break;
     case 0x1c:behemoths.push_back9b80b0(aE.at9b81f0(i));break;
     }
    }
    s9="Sentries: "+kc_intToString4051f0(sentries.size9b9260());
    cN=new KcSubCon(this,s9.size(),1,0,1,0,false,-1);
    cN->setBgColor418410(*kc_d338bc);
    cN->print4181d0(0,0,s9);
    v854.push_back9b9d30(cN);
    s9="Behemoths: "+kc_intToString4051f0(behemoths.size9b9260());
    cN=new KcSubCon(this,s9.size(),1,0,2,0,false,-1);
    cN->setBgColor418410(*kc_d21b44);
    cN->print4181d0(0,0,s9);
    v854.push_back9b9d30(cN);
    KcPos oldPos;
    KcArea2 rh1;
    KcPos q;
    for(unsigned i=0;i<d3.size9b9260();i++){
     oldPos=d3.at9b81f0(i)->getPosition();
     kc_cfd44c.getRect9b4430(oldPos,0x14,rh1);
     for(int x=rh1.x1;x<=rh1.x2;x++)
      for(int y=rh1.y1;y<=rh1.y2;y++){
       if(kc_distance406480(oldPos.x,oldPos.y,x,y)<=20){
        q.set40a010(x,y);
        q.sub409a30(scroll);
        if(inBounds4173d0(q))setBack417fc0(q.x,q.y,KcColor::addAlpha(getBack417750(q),*kc_d30424,kc_pulse4371a0(kc_c370f8,1.0f,1500,0)),true);
       }
      }
     q=oldPos.add409b60(scroll);
     if(inBounds4173d0(q))setBack417fc0(q.x,q.y,KcColor::addAlpha(getBack417750(q),*kc_d35bbc,kc_pulse4371a0(kc_c370f8,1.0f,3000,0)),true);
    }
    for(unsigned i=0;i<behemoths.size9b9260();i++){
     KcVPos&cells=behemoths.at9b81f0(i)->u45d1a0();
     for(unsigned j=0;j<cells.size9b9a50();j++){
      oldPos=cells.at9e7c10(j);
      q=oldPos.add409b60(scroll);
      if(inBounds4173d0(q))setBack417fc0(q.x,q.y,KcColor::addAlpha(getBack417750(q),*kc_d21b44,kc_pulse4371a0(kc_c370f8,1.0f,3000,0)),true);
     }
    }
    for(unsigned i=0;i<sentries.size9b9260();i++){
     oldPos=sentries.at9b81f0(i)->getPosition();
     q=oldPos.add409b60(scroll);
     if(inBounds4173d0(q))setBack417fc0(q.x,q.y,KcColor::addAlpha(getBack417750(q),*kc_d338bc,kc_pulse4371a0(kc_c370f8,1.0f,3000,0)),true);
    }
   }
   if(b8af){
    if(!v854.empty9b86e0()){
     for(unsigned i=0;i<v854.size9b9260();i++)
      if(v854.at9b81f0(i))removeSubconsole428b20(v854.at9b81f0(i));
     v854.clear9bac80();
    }
    int y=20;
    string s="last turn: "+kc_intToString4051f0(kc_cf4a68)+kc_empty_b964d6;
    KcSubCon*sc=new KcSubCon(this,s.size(),1,0,y,0,false,-1);
    y++;
    sc->setBgColor418410(*kc_d338bc);
    sc->print4181d0(0,0,s);
    v854.push_back9b9d30(sc);
    for(unsigned i=0;i<kc_cf4a58.size9b5100();i++)
     for(unsigned j=0;j<kc_cf4a58.at9b8070(i).size9b9260();j++,y++){
      s=kc_d2d1c4.at9b81f0(kc_cf4a58.at9b8070(i).at9b81f0(j))->name;
      sc=new KcSubCon(this,s.size(),1,0,y,0,false,-1);
      sc->setBgColor418410(*kc_d25f60);
      sc->print4181d0(0,0,s);
      v854.push_back9b9d30(sc);
     }
   }
   if(kc_cefad3){
    KcPos wc=kc_cefc4c->getPlayer4630f0()->getPosition();
    for(int g=1;g<=2;g++){
     KcVEnt&ents=kc_cefc4c->u463890(g)->u416f40();
     for(unsigned i=0;i<ents.size9b9260();i++)wc.sub409a30(ents.at9b81f0(i)->getPosition());
     wc.x/=ents.size9b9260()+1;
     wc.y/=ents.size9b9260()+1;
    }
    KcVHeavy near;
    for(int g=1;g<=2;g++){
     KcVEnt&ents=kc_cefc4c->u463890(g)->u416f40();
     for(unsigned i=0;i<ents.size9b9260();i++)
      if(kc_distance40a3f0(ents.at9b81f0(i)->getPosition(),wc)<=15)near.push_back9b80b0(ents.at9b81f0(i));
    }
    if(!v854.empty9b86e0()){
     for(unsigned i=0;i<v854.size9b9260();i++)
      if(v854.at9b81f0(i))removeSubconsole428b20(v854.at9b81f0(i));
     v854.clear9bac80();
    }
    string s="weightedCenter: "+kc_pointToString40a4a0(wc);
    KcSubCon*aX=new KcSubCon(this,s.size(),1,0,0,0,false,-1);
    aX->setBgColor418410(*kc_d35bbc);
    aX->print4181d0(0,0,s);
    v854.push_back9b9d30(aX);
    s="Concentration Count: "+kc_intToString4051f0(near.size9b9260());
    aX=new KcSubCon(this,s.size(),1,0,1,0,false,-1);
    aX->setBgColor418410(*kc_d338bc);
    aX->print4181d0(0,0,s);
    v854.push_back9b9d30(aX);
    KcPos b_=wc;
    b_.sub409a30(scroll);
    if(inBounds4173d0(b_))setBack417fc0(b_.x,b_.y,KcColor::addAlpha(getBack417750(b_),*kc_d30424,kc_pulse4371a0(kc_c370f8,1.0f,1500,0)),true);
   }
   if(kc_cefb28&&kc_cefb3e){
    if(!v854.empty9b86e0()){
     for(unsigned i=0;i<v854.size9b9260();i++)
      if(v854.at9b81f0(i))removeSubconsole428b20(v854.at9b81f0(i));
     v854.clear9bac80();
    }
    for(int i=0;i<kc_cec020->i28;i++){
     KcCE20Item*it=&kc_cec020->p2c[i];
     KcSubCon*sc=new KcSubCon(this,kc_d2d1c4.at9b81f0(it->idx)->name.size(),1,0,i,0,false,-1);
     sc->setBgColor418410(it->b8?*kc_d25f60:*kc_d20b70);
     sc->print4181d0(0,0,kc_d2d1c4.at9b81f0(it->idx)->name);
     v854.push_back9b9d30(sc);
    }
   }
   if(kc_cefb27&&!kc_d22744.empty9b86e0()){
    KcGridI*g=kc_d22744.back9b6540();
    for(int x=0;x<g->width9fcd80();x++)
     for(int y=0;y<g->width9fcd80();y++){
      setFore417f80(x,y,*g->at9ceda0(x,y)?*kc_d20b70:*kc_cfe674);
      setBack417fc0(x,y,*g->at9ceda0(x,y)?*kc_d20b70:*kc_cfe674,true);
     }
   }
   if(kc_cefb29){
    int sz=kc_b90290[kc_d1e888->type].a;
    for(int x=0;x<kc_cf6488.width9fcd80();x++)
     for(int y=0;y<kc_cf6488.height9b8f00();y++)
      if(*kc_cf6488.at9ceda0(x,y)==0)
       for(int a=0;a<sz;a++)
        for(int b=0;b<sz;b++){
         KcPos p(x*sz+a,y*sz+b);
         p.sub409a30(scroll);
         if(inBounds4173d0(p))setBack417fc0(p.x,p.y,KcColor::addAlpha(getBack417750(p),*kc_cf44c0,kc_pulse4371a0(kc_c370f8,1.0f,1500,0)),true);
        }
   }
   if(kc_cefb2b&&kc_cf68b4){
    KcPos p(-1);
    if(kc_cf68b4->i110==2){
     if(kc_cf6984.isValid())p=kc_cf6984->getPosition();
     else if(kc_cf69a8.isValid())p=kc_cf69a8->getPosition();
     else if(kc_cf68b8.isValid())p=kc_cf68b8->getPosition();
    }else if(kc_cf68b8.isValid())p=kc_cf68b8->getPosition();
    if(p.x!=-1){
     KcPos q=p.add409b60(scroll);
     if(inBounds4173d0(q))setBack417fc0(q.x,q.y,KcColor::addAlpha(getBack417750(q),*kc_d20b78,kc_pulse4371a0(kc_c370f8,1.0f,1500,0)),true);
     else{
      q=clampToView83d9b0(p);
      setBack417fc0(q.x,q.y,*kc_d20b78*kc_pulse4371a0(kc_c370f8,1.0f,1500,0),true);
     }
    }
   }
   if(kc_cefb2c){
    KcVStr2 names;
    KcVColor cols;
    names.push_back9b06f0("Bullet Turret");
    cols.push_back9b3e70(*kc_d20618);
    names.push_back9b06f0("Laser Turret");
    cols.push_back9b3e70(*kc_d2981c);
    names.push_back9b06f0("Shock Turret");
    cols.push_back9b3e70(*kc_d1dae0);
    names.push_back9b06f0("Launcher Turret");
    cols.push_back9b3e70(*kc_d204ac);
    names.push_back9b06f0("Blast Turret");
    cols.push_back9b3e70(*kc_cfabbc);
    names.push_back9b06f0("Thermic Turret");
    cols.push_back9b3e70(*kc_d29d68);
    names.push_back9b06f0("Nova Turret");
    cols.push_back9b3e70(*kc_cf27e8);
    names.push_back9b06f0("Stealth Turret");
    cols.push_back9b3e70(*kc_cfe5a0);
    names.push_back9b06f0("Hammer Turret");
    cols.push_back9b3e70(*kc_d20b70);
    names.push_back9b06f0("Stasis Turret");
    cols.push_back9b3e70(*kc_d201c4);
    names.push_back9b06f0("Shield Turret");
    cols.push_back9b3e70(*kc_d201c4);
    for(unsigned i=0;i<kc_cf69ec.size9b9a50();i++){
     KcPos p=kc_cf69ec.at9e7c10(i).add409b60(scroll);
     if(inBounds4173d0(p)){
      int idx=kc_findString9ceb50(names,kc_d25de0.at9b81f0(kc_cf69fc.at9b81f0(i))->name);
      KcColor rd38=idx==-1?*kc_d20b78:cols.at9b3e50(idx);
      setBack417fc0(p.x,p.y,KcColor::addAlpha(getBack417750(p),rd38,kc_pulse4371a0(kc_c370f8,1.0f,1500,0)),true);
     }
    }
   }
   if(kc_cec14e&&a0&&(*kc_cfd44c.atPoint9ced70(a2))->getEntity().isValid()&&(*kc_cfd44c.atPoint9ced70(a2))->getEntity()->ai45b590()){
    KcVPos&path=(*kc_cfd44c.atPoint9ced70(a2))->getEntity()->ai45b590()->u4549b0();
    KcPos p;
    for(unsigned i=0;i<path.size9b9a50();i++){
     p=path.at9e7c10(i).add409b60(scroll);
     if(inBounds4173d0(p))setBack417fc0(p.x,p.y,*kc_cf44c0,true);
    }
    if(kc_blink437320(1000)){
     p=*(*kc_cfd44c.atPoint9ced70(a2))->getEntity()->ai45b590()->getPos462e10();
     if(p.x!=-1){
      p.sub409a30(scroll);
      if(inBounds4173d0(p))setBack417fc0(p.x,p.y,*kc_d30424,true);
     }
    }
   }
   if(kc_cefb16){
    KcPos p=kc_cefc4c->getPlayer4630f0()->getPosition();
    KcVPos&re31=kc_cefc4c->u465ad0();
    if(!re31.empty9b86e0()){
     if(re31.size9b9a50()>=4)p=re31.at9e7c10(re31.size9b9a50()-4);
     else p=re31.front9b7060();
    }
    p.sub409a30(scroll);
    if(inBounds4173d0(p))setBack417fc0(p.x,p.y,*kc_d20438,true);
    KcVPos&b=kc_cefc4c->u465af0();
    if(!b.empty9b86e0()){
     int n=3;
     for(int i=0;i<n;i++){
      int back=i*2+6;
      if(b.size9b9a50()>=back)p=b.at9e7c10(b.size9b9a50()-back);
      else p=b.front9b7060();
      p.sub409a30(scroll);
      if(inBounds4173d0(p))setBack417fc0(p.x,p.y,*kc_d204ac,true);
     }
    }
   }
   if(rng.chance406cc0(kc_c36f88)){
    string code("341q183s&n2q4&9o2n&np86&737q463n9n7r");
    kc_decode4712a0(code);
    if(kc_d25664==code){
     KcVAll all;
     kc_d21720.getAll9d0c30(all);
     if(!all.empty9b86e0())delete kc_d21720.release9d0bc0(kc_randomRec9d5d00(all)->u45a260());
    }
   }
  }
  u429ea0();
  switch(i374){
   break;
  case 0:
   for(int x=0;x<width44b0d0();x++)
    for(int y=0;y<getHeight4174c0();y++){
     KcColor b=getBack(x,y);
     setBack417fc0(x,y,getFore(x,y),true);
     setFore417f80(x,y,b);
    }
   break;
  case 1:
   for(int x=0;x<width44b0d0();x++)
    for(int y=0;y<getHeight4174c0();y++){
     if(getBack(x,y)!=kc_d29804)setFore417f80(x,y,getBack(x,y));
     else setBack417fc0(x,y,getFore(x,y),true);
    }
   break;
  case 2:{
   KcNoise*n=p64->u454d50();
   float f;
   n->update4218e0();
   for(int x=0;x<width44b0d0();x++)
    for(int y=0;y<getHeight4174c0();y++){
     f=n->sample4217d0(x,y);
     setFore417f80(x,y,getFore(x,y)*f);
     setBack417fc0(x,y,getBack(x,y)*f,true);
    }
  }break;
  case 3:
   for(int x=0;x<width44b0d0();x++)
    for(int y=0;y<getHeight4174c0();y++){
     setFore417f80(x,y,KcColor::grayscale413940(getFore(x,y)));
     setBack417fc0(x,y,KcColor::grayscale413940(getBack(x,y)),true);
    }
   break;
  case 4:
   for(int re35=from3.x,sx=kc_maxInt9cdb60(scroll.x,0);re35<=toN.x&&sx<kc_cf27f4;re35++,sx++)for(int y=from3.y,rh2=kc_maxInt9cdb60(scroll.y,0);y<=toN.y&&rh2<kc_cf27f8;y++,rh2++){
    if(aH&&*aH->at9cec50(re35,y)&&(CELL(re35,y)->def9fcd80()==caveinWallTerrain||CELL(re35,y)->def9fcd80()==caveinThirdTerrain||CELL(re35,y)->def9fcd80()==kc_cefba8||CELL(re35,y)->def9fcd80()==kc_cefbac)){
     setFore417f80(sx,rh2,*kc_cfe674);
     setBack417fc0(sx,rh2,*kc_cfe674,true);
    }
   }
   break;
  }
  if(kc_d28e80){
   bool flagTmp=false;
   for(unsigned i=0;i<kc_d28d90.size9b5100();i++)
    if(kc_d28d90.at9b8070(i).i0==4){
     flagTmp=true;
     break;
    }
   if(!flagTmp)
    for(unsigned i=0;i<kc_d28da0.size9b5100();i++)
     if(kc_d28da0.at9b8070(i).i0==4){
      flagTmp=true;
      break;
     }
   KcColor c=kc_cefb3c?kc_d29804*(!kc_d338cc.isDown439510(0x60)&&u8050a0()?kc_c37080:kc_c370f0):caveinWallTerrain->c44*(!kc_d338cc.isDown439510(0x60)&&u8050a0()?kc_c36de8:kc_c36cb8);
   if(!flagTmp){
    if(scroll.x>0)
     for(int y=kc_maxInt9cdb60(scroll.y,0);y<kc_minInt9cdb30(kc_cfd44c.height9b8f00()+scroll.y,getHeight4174c0());y++)setBack417fc0(scroll.x-1,y,c,true);
    if(scroll.y>0)
     for(int x=kc_maxInt9cdb60(scroll.x-1,0);x<kc_minInt9cdb30(kc_cfd44c.width9fcd80()+scroll.x,width44b0d0());x++)setBack417fc0(x,scroll.y-1,c,true);
    if(kc_cfd44c.width9fcd80()+scroll.x<width44b0d0())
     for(int y=kc_maxInt9cdb60(scroll.y-1,0);y<kc_minInt9cdb30(kc_cfd44c.height9b8f00()+scroll.y,getHeight4174c0());y++)setBack417fc0(kc_cfd44c.width9fcd80()+scroll.x,y,c,true);
    if(kc_cfd44c.height9b8f00()+scroll.y<getHeight4174c0())
     for(int x=kc_maxInt9cdb60(scroll.x-1,0);x<kc_minInt9cdb30(scroll.x+kc_cfd44c.width9fcd80()+1,width44b0d0());x++)setBack417fc0(x,kc_cfd44c.height9b8f00()+scroll.y,c,true);
   }else{
    if(scroll.x>0)
     for(int y=kc_maxInt9cdb60(scroll.y,0);y<kc_minInt9cdb30(kc_cfd44c.height9b8f00()+scroll.y,getHeight4174c0());y++)putChar418150(scroll.x-1,y,0x80,*kc_cfe674,c,true);
    if(scroll.y>0){
     for(int x=kc_maxInt9cdb60(scroll.x-1,0);x<kc_minInt9cdb30(kc_cfd44c.width9fcd80()+scroll.x,width44b0d0());x++)putChar418150(x,scroll.y-1,0x81,*kc_cfe674,c,true);
     if(scroll.x>0)putChar418150(scroll.x-1,scroll.y-1,0x88,*kc_cfe674,c,true);
    }
    if(kc_cfd44c.width9fcd80()+scroll.x<width44b0d0()){
     for(int y=kc_maxInt9cdb60(scroll.y-1,0);y<kc_minInt9cdb30(kc_cfd44c.height9b8f00()+scroll.y,getHeight4174c0());y++)putChar418150(kc_cfd44c.width9fcd80()+scroll.x,y,0x80,*kc_cfe674,c,true);
     if(scroll.y>0)putChar418150(kc_cfd44c.width9fcd80()+scroll.x,scroll.y-1,0x89,*kc_cfe674,c,true);
    }
    if(kc_cfd44c.height9b8f00()+scroll.y<getHeight4174c0()){
     for(int x=kc_maxInt9cdb60(scroll.x-1,0);x<kc_minInt9cdb30(scroll.x+kc_cfd44c.width9fcd80()+1,width44b0d0());x++)putChar418150(x,kc_cfd44c.height9b8f00()+scroll.y,0x81,*kc_cfe674,c,true);
     if(scroll.x>0)putChar418150(scroll.x-1,kc_cfd44c.height9b8f00()+scroll.y,0x87,*kc_cfe674,c,true);
     if(kc_cfd44c.width9fcd80()+scroll.x<width44b0d0())putChar418150(kc_cfd44c.width9fcd80()+scroll.x,kc_cfd44c.height9b8f00()+scroll.y,0x8a,*kc_cfe674,c,true);
    }
   }
  }
 }
 if(!kc_d28d90.empty9b86e0()){
  KcVFilt saved(kc_d1d45c);
  kc_d1d45c=kc_d28d90;
  int w=width44b0d0();
  int h=getHeight4174c0();
  KcGrid7a40*to1=buf4184d0();
  for(int x=0;x<w;x++)
   for(int y=0;y<h;y++)
    to1->at9cdf20(x,y)->applyFilters417230();
  kc_d1d45c=saved;
 }
}
