// NOTE: CMap::input (0x827ed0, CMap vtable slot 4) as FcCMap::input on private borrowed views; placeholder names/layouts throughout.
// Self-contained: every Fc*/fc_* name is private to this file (stubs pair by the address in the name).
// Lives in src/util so it links last (it declares many callees without throw(); see AGENTS.md nothrow notes).
// Local names were chosen for their stack-slot hash bucket (docs/local-name-buckets.txt), not for meaning.
#include <string>
#include <vector>
using namespace std;
struct FcPos{int x,y;FcPos();explicit FcPos(int);FcPos(const FcPos&)throw();FcPos operator-(const FcPos&)const;void scale40a300(int);FcPos&operator=(const FcPos&);bool operator!=(const FcPos&);void set40a090(const FcPos&,const FcPos&);FcPos(const FcPos&,const FcPos&);bool operator==(const FcPos&);FcPos&operator+=(const FcPos&);bool adjacent409dd0(const FcPos&);void set409ff0(int);};
struct FcPosN{int x,y;FcPosN(int,int);};
struct FcColor{unsigned char r,g,b;FcColor(float,float,float);FcColor operator*(float);};struct FcRGB{float r,g,b;};extern FcRGB fc_b9e678[];extern char fc_b99c08[];extern const float fc_c371b8;
struct FcRect{int x,y,w,h;FcRect();};
struct FcEvent{int command;FcPos pos;FcEvent(int);};
struct FcHolder{char pad[0x2c];FcHolder();~FcHolder();};
struct FcDef{char pad0[8];string name8;int x24;char pad28[0x70-0x28];int x70;char pad74[0x94-0x74];int x94;char pad98[0xec-0x98];int ec;char padf0[0x15c-0xf0];bool x15c;char pad15d[0x1a0-0x15d];struct FcExpl*x1a0;char pad1a4[0x1ac-0x1a4];bool x1ac;struct FcRec*getRecord56f3c0();};
struct FcEff{int type,value;};
struct FcEffDef;struct FcRecList{bool hasData4563e0(FcEffDef*);};
struct FcExpl{int x0;char pad4[0x30-4];int x30;};struct FcGM2{void addItemAttachCount778560(int,int,int);};extern FcGM2 fc_d25628;extern int fc_d254f0;
struct FcHRec{int id;};
struct FcItem{int u4580a0();int u4580c0();void setCount450460(int);int u5789c0();int u9b6bf0();int u457c80();int u457cd0();void u458360(int);int u4578a0();void u458560();FcRecList*u44a7d0();void u57c090(FcEffDef*,int);void addEffect4585a0(FcPosN*);int u45cb30();void setCharges44fc60(int);const FcPos*u575920();int u457820();bool u457d70();int u457fd0();void remove57dbe0(int,int,int,int);void u57a0f0(FcPos&,int,int);void u4585c0(int);int effectValue457be0(int);int range457fb0();int type457880();bool active457cf0();int kind457f90();int getType44aec0();FcDef*def9b4350();bool u458220();FcEff*effect457b70(int);int u577fb0();bool u457e90();string name571db0(bool,bool);};
struct FcHI{int id;bool operator==(FcHI)const;FcHI();bool null9b65d0()const;FcItem*operator->()const;bool valid9b7230()const;};
struct FcPart{void drawStatus4a8e70(int);void u890710(bool);};struct FcParts{void u896a80(FcHI);FcPart*find894e70(FcHI);void toggle8993e0(FcPart*,bool);};extern FcParts*fc_cec088;
struct FcTool{bool u415ee0();int kind457dd0();};
struct FcKeys{bool isDown439510(int);};extern FcKeys fc_d338cc;
struct FcEntity;struct FcPathing{bool u45b5e0(const FcPos&,const FcPos&,FcEntity*,int*);};extern FcPathing*fc_cefc2c;
struct FcScan{void load884f60(const FcPos&,int);};extern FcScan*fc_cec078;
class RNG{public:bool chance(int);int rangeInt(float,float);float rangeFloat(float,float);};extern RNG rng;
struct FcRange{int randomInRange40c130();};extern FcRange fc_d2e838,fc_cf08e4;
struct FcStats2{string outputScoresheet474a20(int);bool add4729d0(unsigned,int,string,int);int count472c70(unsigned);};extern FcStats2 fc_d2c658;
struct FcXom{bool active;void u69e700(int,int,float);void u69ec90();void u69ecb0(int);};extern FcXom fc_d25450;
struct FcHE;struct FcHGroup;struct FcGroup;struct FcAI{char pad[0x130];FcAI(FcHE,int,int);void setFollowEntity5b2f80(FcHE,int);FcPos*pos462e10();};
struct FcEntity{int u45a810();bool isXomCandidate5d51a0();bool u5d5df0();bool u5c8820(FcHE);bool u5c87f0(FcPos&);bool u5d6610();void u5d6a80(vector<FcHI>&,const FcPos&,int);int u5c7fc0(FcHE);int u5c7ff0(int);bool u5d9340(int,int);void polymindUnpossess5d93d0(int);int u490840();void u5de870(int,int);int u45a880();void u5cb8b0(vector<FcHI>&);void u5daf90(int);void u5d6c30(vector<FcHI>&);bool u5ced30();void u45b2a0();int u45a6e0();bool teleport63b5a0(int,int);float u45a720();int u5c7f10();void changeFaction5dc780(FcHGroup,int);void setAI64ecf0(FcAI*);int u5c92e0(int);int u5ca670();void u5deb40(int);FcHI u5d2b40(string)throw();bool u45a780();const string&getName45a280();void alertGroup639ec0(FcHE,int);void destroyItems63a0d0();int u45a920();void u45b1e0(int);void u5ddac0(FcPos&,int);bool u5d5520(int);bool u5d5460(int);int target45a760();FcPos pos45a4c0();FcPos&getPosition45a4a0();void changePos5dccb0(const FcPos&,bool);int getSize45a360();void u637bb0();void die633790(int,int,FcHE,int,int,int,int,int);FcAI*ai45b590();bool isHostileTo45aa70(FcHE);int getFaction45a2c0();FcHGroup getGroup45a3f0();FcHI item5d2380(int);bool u5d1280(int);int mode5cad50();vector<FcHI>*inventory45ab00();int u5df740(int);vector<FcPos>*shape45d1a0();bool allowed5c84f0(const FcPos&);bool blocked5c8710(const FcPos&);int u5d15a0(int);bool other5c85a0(const FcPos&,bool);bool u5ddf50(const FcPos&,struct FcHolder&,bool*);int u5db260(int);int move63d8a0(FcPos&,int,int);bool u45aaa0(FcHE);FcHI u5d5d40();int u5d1390();int u5cab90();void*u5cb9b0(int);int takeDamage5e5520(int,void*,void*,int,int,int,int,bool,FcHE,int,int,int,int,bool);void u5fdab0();void teleport63b1c0();int u5ca260();FcDef*def9b4350();void u64e7e0(FcHI);int u45b300(int);FcHI item5d24e0(int);void setFaction5dcc70(int,int);string&name416f40();};
struct FcHE{int id;bool operator!=(FcHE)const;FcHE();FcEntity*operator->()const throw();bool valid9b7230()const;bool null9b65d0()const;void reset9b7270();};
struct FcHGroup{int id;FcGroup*operator->()const;};
struct FcGroup{vector<FcHE>*members416f40();int type9b4350();};

struct FcBox{int a,b,c,d;FcBox(int,int,int,int);};
struct FcLocation{bool inRange46ecb0();};
struct FcHMach{int id;FcLocation*operator->()const;};
struct FcMachine{char pad0[8];FcHMach handle;char padc;bool announced;char pade[0x14-0xe];FcHE h14,h18;};
struct FcCharArray{void zero9d28b0();};
struct FcRec{char pad0[0x24];int x24;int kind;char pad2c[0x9c-0x2c];int x9c;char pada0[0x148-0xa0];vector<int>x148;char pad158[0x1ac-0x158];string x1ac;};
struct FcRec2{char pad0[8];int x8;};struct FcTerrain{char pad0[0x58];bool x58;};extern vector<FcRec2*>fc_cf0fa8;extern vector<FcTerrain*>fc_cfb844;extern int fc_ce9ff4;extern int*fc_cefb9c,*fc_cefb88,*fc_cf4700;
struct FcGD{int u789090();bool u46f4b0(int);const string&getEntryText46f6d0(const string&);};extern FcGD fc_d1e860;bool fc_contains9db330(vector<int>&,int);int fc_u6c10f0(const FcPos&);extern const float fc_ba850c,fc_ba8508,fc_ba8510;
struct FcPropDef;struct FcMap{vector<FcPos*>*u463f60();void u72a1e0(FcPos&,int);bool u4633c0(FcPos&);bool u7168e0(FcPos&,FcPos&,FcEntity*,vector<FcPos>&);int u4642d0();bool u715920();bool u463380(int,int);int u716f20(FcHE,FcPos&);bool u7178d0(FcHE,FcPos&,char*,FcPos&,char*,int);bool u4631f0(FcHE);FcPos u71b5b0(FcHE,int);void u9ebbb0(int);vector<FcPos>&u464060();void u74bec0(FcPos&);void u464d00(FcHI,int);void bomb744aa0(FcHE);void u7289f0(FcHI,int);FcHRec addRecord777a20(FcHRec);void u464cd0(FcHI);void u728fa0(FcHI);void u464f60(FcHI);bool placeProp6c67b0(FcPropDef*,FcPos&,int,int,int);int&u464590();void u72f6b0();int getTurn464270();bool u463e90(FcPos&);void u734db0(FcHE);bool u74d200(int);FcHI giveItem6c52b0(const string&,FcHE,int,int);bool findPropSpotNear71c3c0(FcPos&,FcPos&,FcPropDef*);void addPoint465320(FcPos&);vector<vector<FcPos> >&u459070();char pad0[0x10];vector<FcMachine*>machines;char pad20[0x4c-0x20];vector<FcHGroup>groups;char pad5c[0x66c-0x5c];bool u71ec60(const FcPos&,vector<FcPos>);FcHE player;char pad670[0x674-0x670];FcCharArray known;char pad675[0xb3c-0x675];FcPos repairPos;bool repairFlag;int repairSum;bool busy71bbd0();FcHGroup group463890(int);void reveal726840(const FcBox&,bool);void announce71dd30(FcHMach);FcHE entity463110();bool findPlaceableNear71c150(FcPos&,FcPos&,int);void update71cf70();FcHE place6c58c0(FcRec*,const FcPos&,int,int,int,int,int);FcHE getPlayer4630f0();void*u4636d0();void*u463710();void hostile72e4c0(FcHE,int);void u774390(int,int);bool test71cfb0();bool u463160(const FcPos&);bool isVisible4631c0(const FcPos&);bool u71bc10(const FcPos&,FcPos&);void u464840(FcHI);void u4647a0(const FcPos&,int);};extern FcMap*fc_cefc4c;
struct FcPropDef{char pad0[0x68];int x68;char pad6c[0x78-0x6c];bool x78;char pad79[0x8c-0x79];int x8c;char pad90[0xf8-0x90];int xf8;bool xfc;char padfd[0x140-0xfd];int x140;};struct FcPropX{char pad0[0x18];vector<void*>x18;char pad28[8];bool x30;int x34;};
struct FcDoorRec{char pad0[8];FcHE x8;FcHE xc;int x10;bool u65cf50(int);bool u65cf80();};
struct FcProp{bool u45cb90(int);void u65f170();FcDoorRec*u44b020();int u45c630();int u665a70(int,int);const string&u45c590();void u45cd50();bool u45cb50();bool u45cb10();int idx44ab40();FcPropX*u45cb30();bool u470b30();void u65f270(FcPos&);void u45ce10(int,int,int,FcHE);void u45cc50(FcPos&);void u65e500();void setIdx451400(int);void set448080(int);int u457af0();void u45cd10(int);void set452270(int);void u45cca0(const FcColor&);void u45cc70(const FcColor&);FcPos&pos4184d0();bool u45cad0();int u45c800(int);void u45cee0(FcPosN*);FcPropDef*def9b8f00();int u457b10();bool isPassableFor65e1d0(FcHE);const string&name45c5b0();};
struct FcHProp{int id;FcHProp();void reset9b7270();bool operator==(FcHProp)const;bool null9b65d0()const;bool operator!=(FcHProp)const;FcProp*operator->()const;bool valid9b7230()const;};
extern vector<vector<FcHProp> >fc_d31640;extern vector<vector<FcPos> >fc_d2f32c;extern vector<int>fc_d2f0f8,fc_d2a2cc;extern FcRange fc_d2d478;struct FcSound{void updatePropMute454520(FcHProp);};extern FcSound fc_d2d2a0;
void fc_shuffle9d7350(vector<FcPos>&);void fc_eraseAt9d5190(vector<FcPos>&,int);bool fc_between9d4c40(int,int,int);void fc_clearObjects9d0670(vector<void*>&);string fc_intToStringSigned405560(int);extern const char fc_b9645e[];
struct FcTimer{FcPos pos;unsigned time;FcTimer(FcPos&);};extern const char fc_b9645f[],fc_b96469[];extern int fc_ba6a28[],fc_ba69e0[];extern int fc_d1f32c;int fc_randomOf9d9c10(int*,unsigned);void fc_getAdjacentCells4fab80(FcPos&,vector<FcPos>&);void fc_sound454260(FcPos&,int);struct FcHack{void open939b50(FcHProp);};extern FcHack*fc_cec0f8;
bool fc_logPhrase5141b0(int,const string*,const string*,const string*,FcHE,int);int fc_stringToInt405610(const string&);extern const float fc_ba8504;
struct FcIGrid{int*atPoint9ced70(FcPos&);};extern FcIGrid originalTerrain;extern int*TERRAIN_CAVE_WALL,*caveinThirdTerrain;extern bool fc_d28e47,fc_d28e46,fc_b96a78[];extern int fc_b96bb4[],fc_caf234[];extern const float fc_ba8518;extern const char fc_b9646a[],fc_b9646b[],fc_b96473[],fc_b9648e[];
void fc_translateRotated446dd0(FcPos&,int,int,int);void fc_offsetDiagonal827d90(FcPos&,int,int,int);extern int fc_cf4a70,fc_cf4a74,fc_cf4a7c,fc_cf4a90,fc_cf4a94;extern bool fc_cf4a78,fc_d28c8a;extern vector<FcPos>fc_cf4a80;extern FcRange fc_d386b8,fc_d30550,fc_d35b7c;struct FcShift{void shift872ef0(int,int,bool);void saveScreenshot873ba0(string);};extern string fc_d1e864;string fc_getLocationName4fd600(int);void fc_openWorldMap997000();
extern vector<FcEffDef*>fc_d2c408;bool fc_findByName9d7de0(vector<FcEffDef*>&,const string&,FcEffDef*&);extern vector<int>fc_cf4830;extern bool fc_d28e04,fc_d28e05,fc_d1d9c4,fc_d1da38,fc_d1d9f8;extern int fc_d28d34,fc_d1d9f4;extern FcPos fc_d1d9fc,fc_d1da30,fc_d1da20,fc_d1da28;struct FcWay:FcPos{int a,b;};extern vector<FcWay>fc_d1da10;extern FcHI fc_d1da44;extern FcHE fc_d1d9f0;extern bool fc_b96384[];bool fc_containsEntity9d31e0(vector<FcHE>&,FcHE);void fc_insert9d8fc0(vector<FcHI>&,int,FcHI);void fc_insertAt9dbdc0(vector<int>&,int,int);void fc_insert9d8fc0(vector<FcHE>&,int,FcHE);void fc_eraseStep9d6440(vector<FcHE>&,int&);void fc_eraseStep9d6440(vector<FcHI>&,int&);int fc_indexOf9d3110(vector<FcHE>*,FcHE);extern bool fc_cefb3e;extern int fc_cf473c;FcHI fc_randomRecord9dafb0(vector<FcHI>&);void fc_addUnique9d30e0(vector<FcHI>&,FcHI);void fc_removeEntity9d2f00(vector<FcHI>&,FcHI);extern bool fc_d28e07;extern int fc_d28f8c;extern const float fc_ba8544,fc_ba8540,fc_ba8530;extern const char fc_b964bb[],fc_b964c5[],fc_b964c6[],fc_b964c7[];extern vector<int>fc_cf4a04;extern int fc_b989a0[];int fc_maxInt9cdb60(int,int);int fc_minInt9cdb30(int,int);void fc_clampMax9cf5a0(int&,int);extern const char fc_b964b3[];extern FcDef*fc_cefbec,*fc_cefbe8;extern const float fc_c36e30,fc_c36ff0;extern const char fc_b964b2[];extern const char fc_b964a7[];extern int fc_d1eb40;extern const char fc_b964a6[];struct FcArea2{bool contains40b750(const FcPos&);};extern FcArea2 fc_d1eaf8;extern const char fc_b9648f[];
extern int*TERRAIN_EARTH,*fc_cefb84;struct FcItemTag{void openForPos8abac0(FcPos&,int);};extern FcItemTag*fc_cec0a0;extern int fc_b96600[];extern bool fc_d28e06,fc_d28d3b;extern int fc_d28e6c;void fc_logError404f10(string,string);extern bool fc_d1d9e4,fc_d1d9e5,fc_d28e49;extern bool fc_d28d24,fc_d28e3d;extern FcHE fc_d1da3c;extern unsigned fc_d1da40;int fc_pointsFn4374c0(FcPos&,FcPos&);bool fc_pointsFn4373c0(FcPos&,FcPos&);
struct FcCell{bool u45dbf0();int u45d0e0();bool u45db70();bool isEdge45dc30();bool canCaveIn66af50();bool isDoor45dda0();void u66ce10(int,int,int,int);void u66b690(int,int);bool u45dcf0();void removeProp66c100(int,int);void u45df50(FcHProp);bool u45d310();void*getEffect45d350(int);void u45dfb0(int);int u45d180();void u66b700(int,int);FcHProp getProp45d550();string&name45d140();bool isPassableFor66ab30(FcHE);bool solid4550b0();FcHI getItem45d8f0();bool isMachinePart45dcd0();FcHE getEntity45d250();void u66a050(int,int,int);};
struct FcArea{int x1,y1,x2,y2;FcArea();void randomPoint40be30(FcPos*);};
struct FcGrid{void getRect9b4430(const FcPos&,int,FcArea&);FcCell**at9ceda0(int,int);bool contains9b43b0(const FcPos&);int height9b8f00();int width9fcd80();FcCell**atPoint9ced70(FcPos&);};extern FcGrid fc_cfd44c;
struct FcXCon{bool hasAnyLabel();bool hasActiveLabel(int);void reset48e590();void u8142d0(unsigned,bool);void u49adc0(int);virtual~FcXCon();virtual void v1();virtual void v2();virtual void v3();virtual bool input(FcEvent*);bool hidden4175f0();bool contains417440(const FcPos&);int height4174c0();int width44b0d0();};
struct FcPhraseA{char pad[0x20];FcPhraseA(int,string*,string*,string*,FcHE,FcHE);};
struct FcPhraseC{char pad[0x20];FcPhraseC(string,string*,string*,string*,FcHE,FcHE);};
struct FcPhraseB{char pad[0x28];FcPhraseB(int,string*,string*,string*,FcHE,FcHE);};
struct FcMsgs{void add7b1880(FcPhraseA*);void add7b1880(FcPhraseC*);};extern FcMsgs*fc_cec0f4;
struct FcLog{int push5121f0(FcPhraseB*);};extern FcLog fc_cf1080;
struct FcBubble{void bubble8758d0(bool);};extern FcBubble*fc_cec058;
struct FcLogMsgs{void scrollToEnd7b4f10();void reset48e590();};extern FcLogMsgs*fc_cec0b4;
struct FcStats{int field48e040();};extern FcStats*fc_cec130;extern void*fc_cec134;
struct FcEffects{bool active4b31a0();void stop969500();};extern FcEffects*fc_cec138;
struct FcPanel:FcXCon{bool shown48e740();};extern FcPanel*fc_cec0b0;extern FcXCon*fc_cec08c;
struct FcMouse{bool u41a6e0();FcPos topLeft40a970();};extern FcMouse*fc_cefa94;
struct FcFlags{void u46df70();bool u77f260(int);void u77fbc0(int);bool active46dd50();bool field46dd90();void set46ddb0(bool);void addSuspicion77ee70(float,int,FcHE);};extern FcFlags fc_cf45d8;
struct FcExplode;struct FcGM{FcHRec createA7930e0(FcExplode*);FcHProp create793360(FcPropDef*);void reset470be0();bool show793450(int,bool,const string*,bool,bool);void u78d700(int,int);};extern FcGM*fc_cefaa8;
struct FcGraph{FcTool*tool416230();void setMarked4162e0(unsigned,bool);bool get416200(int);};extern FcGraph*fc_cefa8c;
struct FcHandle{void reset9b7270();};extern FcHandle fc_d1eadc;
struct FcType{char pad[0x80];FcType(FcXCon*,const FcRect&,int,const string&,int,void(*)(const string&),int,int,int);};
struct FcSprite{char pad[0x6c];FcSprite(FcXCon*);};
struct FcInputBox{void set4514e0(void(*)(bool));void setUnknown95_48d360(bool);};
struct FcCommand{char pad[0x7c];FcInputBox*input;};extern FcCommand*fc_cec10c;
struct FcRex{int u4189e0();};extern FcRex fc_d223f0;
extern FcXCon*fc_cec054;
extern bool fc_cefa5f,fc_cefacc,fc_cefacd,fc_d28e4d,fc_d28e27,fc_d28d15,fc_d1da78,fc_d257d6,fc_d28d27,fc_d28e4a,fc_d28e3c,fc_d28d30,fc_d28e08;
extern int fc_cefc90,fc_cf462c,fc_cf4718,fc_d25740,fc_d25744,fc_d25748,fc_caf128,fc_caf2b0,fc_cefbbc,fc_d1da7c;
extern unsigned fc_caed20,fc_d1da74;
extern vector<FcRec*>fc_d25de0;extern vector<int>fc_d22590;extern int fc_caf138,fc_caf13c,fc_caf140;extern bool fc_caed26;extern string fc_d31c00[];
extern FcPos fc_d015d8[];extern vector<int>fc_cf4ce8;extern bool fc_d28e24,fc_d28e79,fc_ba0984[],fc_ba0968[],fc_d28e7a,fc_d28e48,fc_d28e7e;extern int fc_d255cc;extern bool fc_d255d0,fc_d28fa3,fc_d28fa4;extern const float fc_b96240,fc_c36ec8,fc_c36ffc;struct FcMapInfo{int a,type;};struct FcHLoc{int id;FcMapInfo*operator->()const;};extern FcHLoc fc_d1e888;extern vector<FcPropDef*>fc_cf35b0;
bool fc_findByName9d7710(vector<FcPropDef*>&,const string&,FcPropDef*&);
struct FcSpan{int min,max;FcSpan();void set40a010(int,int);};
struct FcLine{char pad[0x2c];FcLine(int,int,int,int);~FcLine();void next4102a0(FcPos&);};
void fc_rotate501fc0(const FcPos*,const FcPos*,float,FcPos*);int fc_distance40a3f0(const FcPos&,const FcPos&);FcPos fc_randomPoint9d5350(vector<FcPos>&);
extern const float fc_c37228,fc_c36fc0;
extern const char fc_b9645d[];
struct FcWL{char pad[0x24];FcWL();~FcWL();void add9ba310(int,int);int&pick9ba470();};extern int fc_ba0bb8[][2];
extern const char fc_b96447[],fc_b96451[],fc_b96452[],fc_b96453[];extern int fc_cf49fc;extern char fc_d2e20c;
struct FcFx{void init503b20(void*,int,const FcPos&,void*,int,int,int,int,int);};struct FcFxPool{FcFx*alloc508610();};extern FcFxPool*fc_cefc50;
extern int fc_cefb38,fc_d1d9c0,fc_d28d2c,fc_d28fc0,fc_d28e0c,fc_d28e10,fc_d28e14,fc_cefc68;extern int fc_d28e70;extern bool fc_d28d28,fc_cf4780;
extern const char fc_bffc18[],fc_bffc08[];
bool fc_between9daf80(int,int,int);
struct FcHI fc_popRandom9d8030(vector<struct FcHI>&);void fc_line40ff30(const FcPos&,const FcPos&,vector<FcPos>&);struct FcHE;void fc_message49c610(int,FcHE,const string&,int);extern const float fc_c36e10,fc_ba0be0;
void fc_removeAt9de6f0(vector<unsigned>&,int);
string fc_rotate406040(const string&);
void fc_logMessage404cb0(string);
int fc_halfDiff437190(int,int);
void opq4c_scrollType8ff120(bool);
void fc_typed81a8e0(const string&);
int fc_indexOf9d3110(vector<FcHE>*,FcHE);
void fc_toggleFont7f46e0();
int fc_sound4541b0(int,int,int);
void fc_warn7b1750(int,const string*,const string*,const string*,FcHE,FcHE,const FcPos*);
string fc_intToString4051f0(int);
bool fc_contains9d0ce0(vector<FcPos>&,FcPos);
bool fc_lookup9d7980(const string&,int*);
bool fc_showMessage5111e0(int,const string*,const string*,const string*,FcHE,FcHE,int,int);
void fc_openEvolve4b5780(int,FcHMach,int);
struct FcExplode{char pad[0x40];FcExplode(FcHE,FcExpl*,const FcPos&,FcHE,const FcPos&,const FcPos&);};
struct FcCon034:FcXCon{char padx[0x78-4];bool x78;char pad79[0xb0-0x79];int xb0;bool u987b10(int);};struct FcPanelC8{int u48f100();void u7b8340(const FcPos&);void endOrder7b8290();void beginOrder();void reset48f2b0();};extern FcPanelC8*fc_cec0c8;struct FcPanelCC{void beginSelect();void reset48f920();};extern FcPanelCC*fc_cec0cc;struct FcPanelC4{void reset48e590();};extern FcPanelC4*fc_cec0c4;extern int fc_cebd5c,fc_d28d64;extern FcCon034*fc_cec034;struct FcInfo{void u8b4500(FcHE,FcHProp,FcHE,const FcPos*,int,bool);};extern FcInfo*fc_cec118;struct FcPartRemove{void open8aab40();};extern FcPartRemove*fc_cec094;extern FcHProp fc_d1da04;
struct FcRow:FcXCon{void clearRow428ac0(int,int,int);void u4aa510();};struct FcInv{FcRow*u8a1fd0(FcHI,bool);};
struct FcCMap:FcXCon{char pad0[0x70];FcHE marked;bool unmark;char pad79[0xd8-0x79];bool locked;char padd9[0xec-0xd9];bool xec;char paded[0x1c4-0xed];unsigned x1c4;char pad1c8[0x1f0-0x1c8];unsigned scanReset;int scanMode;unsigned scanTime;char pad1fc[0x200-0x1fc];int x200;char pad204[0x2cc-0x204];vector<FcTimer>timers;char pad2dc[0x4c8-0x2dc];FcPos pos4c8,pos4d0;char pad4d8[0x50c-0x4d8];vector<FcWay>path50c;char pad51c[0x540-0x51c];bool b540;char pad541[0x58c-0x541];FcPos allyPos;unsigned allyTime,allyReset;FcPos stealthPos;unsigned stealthTime,stealthReset;FcHProp doorProp;unsigned doorTime,doorReset;char pad5b8[0x5cc-0x5b8];unsigned warnTime,warnReset;unsigned warn2Time,warn2Reset;unsigned caveTime;unsigned hazardTime,hazardReset,itemTime,itemReset;char pad5f0[0x628-0x5f0];unsigned foldTime,foldReset;unsigned warpTime,warpReset;unsigned teleTime,teleReset;char pad640[0x64c-0x640];unsigned moveBlock;unsigned moveBlock2;unsigned equipTime;unsigned doorMsgTime;unsigned useTime,useTime2;unsigned armTime;unsigned lastMove;char pad66c[0x67c-0x66c];unsigned blockUntil;int mode;int x684;vector<FcHE>list688;int x698;vector<FcHI>list69c;int x6ac;char pad6b0[0x6fc-0x6b0];FcPos pos6fc;char pad704[0x718-0x704];int x718;char pad71c[0x730-0x71c];vector<FcPos>path730;vector<int>times740;char pad750[0x760-0x750];int walkDir;unsigned walkStart,walkTime;bool skipRefresh;char pad76d[0x770-0x76d];int walkSteps;vector<FcPos>walkPath;FcPos pos784;FcPos pos78c;char pad794[0x7ac-0x794];unsigned lastWizard;char pad7b0[0x7f0-0x7b0];unsigned lastReveal;char pad7f4[0x83c-0x7f4];bool showA;bool showB;char pad83e[0x851-0x83e];bool showC;char pad852[0x89c-0x852];vector<unsigned>history;
 bool input(FcEvent*);bool base429d00(FcEvent*);void refresh49ad30();bool busy49aa00();void center8069e0(FcPos,bool);void u8080a0();void u808290();void u8081d0();bool pick805190(FcPos*);void center805020(FcPos&);bool action824020(FcHE,int);bool u805de0(FcHE,bool);bool u8062d0();void third8231f0(FcHE,const FcPos&);bool u49ab60();bool confirm805520(const FcPos&);bool u8052f0(const FcPos&);void u49aee0();void fire821450(FcHE);bool pickTarget827170(FcHE);bool dropOnTarget8275d0(FcHE);void u827950();void u49ac70();bool u806f30(int);void label810270(int,FcHE,int,int);void items8119c0(FcHI,int,int,int);void u827850(int);void u8212e0();void u827cf0();void buildAllyPaths819a60();bool u49b0c0(int);void setSelected8278f0(int);void u49ac50();void u8051f0(FcPos&,FcPos&);void u807e60(int);int u805360(FcHE,vector<FcWay>&,FcPos&);bool look820dc0(int,int);void u826920(FcHE);void u826e50(FcHE,bool,bool);int equipAll81a0e0(int);void u49b5b0();void scan813c80(int);void u49ada0(unsigned);void cleanUp8144d0();void useExit825e00();void warpMouse806e70(const FcPos&,bool);void removeMarker49b400(FcPos&);void showTimer8176a0(int,FcPos&,int,int);void last824c40(FcHE,FcPos&,int,bool);bool interact825a60(FcHE,FcPos&,bool);};
bool FcCMap::input(FcEvent*event){
 if(hidden4175f0()||fc_cefa5f)return false;
 if(base429d00(event))return true;
 if(fc_cec134||fc_cec130&&fc_cec130->field48e040()==10)return false;
 if(fc_cec138&&fc_cec138->active4b31a0()&&event->command==0x12){
  fc_cec138->stop969500();
  fc_cec0f4->add7b1880(new FcPhraseA(196,0,0,0,FcHE(),FcHE()));
  return false;
 }
 if(event->command==0xcc||event->command==0xcf||event->command==0xd8||event->command==0x117||event->command==0x127||event->command==0x11a||event->command==0x12a||event->command==0x156)return false;
 if(fc_cec0b0->shown48e740()&&event->pos.x!=-10000&&fc_cec0b0->contains417440(fc_cefa94->topLeft40a970()))return false;
 if(fc_cefc90==2&&event->pos.x!=-10000&&fc_cec08c->contains417440(fc_cefa94->topLeft40a970()))return false;
 if(fc_between9daf80(0xd4,event->command,0xe7)||fc_between9daf80(0x16a,event->command,0x173))return false;
 if(skipRefresh)skipRefresh=false;else refresh49ad30();
 if(fc_cefc4c->busy71bbd0()){refresh49ad30();return false;}
 history.push_back((unsigned int)event->command);
 while(history.size()>50)fc_removeAt9de6f0(history,0);
 if(fc_caed20<blockUntil&&!fc_d28e4d)return false;
 if(fc_caf2b0!=32&&!fc_cf45d8.active46dd50()&&fc_caed20>=540000){if(fc_caf2b0-64!=fc_d25de0.size())fc_cefbbc=1;fc_caf2b0=32;}
 int facing;
 FcHE player=fc_cefc4c->player;
 switch(event->command){
 case 0x2e:
  if(fc_cefacc&&(fc_cf462c!=8||fc_cefacd)){
   if(!fc_cefacd&&!fc_cf45d8.field46dd90()){
    if(lastWizard&&fc_caed20<lastWizard+2000){
     fc_cf45d8.set46ddb0(true);
     fc_cefaa8->reset470be0();
     fc_d25740--;
     switch(fc_cf4718){
     case 1:fc_d25744--;break;
     case 2:fc_d25748--;break;
     }
     fc_d1eadc.reset9b7270();
     fc_cefa8c->setMarked4162e0(6,true);
     fc_logMessage404cb0(fc_rotate406040("Npgvingvat jvmneq zbqr sbe pheerag eha"));
     do{if(fc_cf1080.push5121f0(new FcPhraseB(810,0,0,0,FcHE(),FcHE())))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
    }else{
     lastWizard=fc_caed20;
     fc_cec0f4->add7b1880(new FcPhraseA(223,0,0,0,FcHE(),FcHE()));
    }
   }else if(fc_cefacd||fc_cf45d8.active46dd50()){
    const int w=60;
    const int h=4;
    FcRect area;
    area.x=fc_halfDiff437190(w/fc_caf128,width44b0d0());
    area.y=fc_halfDiff437190(h,height4174c0());
    area.w=w;
    area.h=h;
    new FcType(fc_cec054,area,0,fc_bffc18+fc_rotate406040("Q R O H T")+fc_bffc08,0,fc_typed81a8e0,0,-1,0);
    fc_cec10c->input->set4514e0(opq4c_scrollType8ff120);
    fc_cec10c->input->setUnknown95_48d360(true);
   }
  }
  return true;
 case 0x2f:case 0x30:
  if(player.valid9b7230()){
   FcHE target=player;
   if(!busy49aa00()){
    if(unmark){marked.reset9b7270();unmark=false;}
    else if(fc_d28e27){
     if(!marked.operator->()||marked->target45a760())marked.reset9b7270();
     vector<FcHE>*list=fc_cefc4c->group463890(0)->members416f40();
     int index=marked.valid9b7230()?fc_indexOf9d3110(list,marked):0;
     if(list->size()==1||marked.valid9b7230()&&index==-1)marked.reset9b7270();
     else if(event->command==0x2f){
      while(1){
       index++;
       if(index>=list->size()){marked.reset9b7270();break;}
       else if(!(*list)[index]->target45a760()){marked=(*list)[index];target=marked;break;}
      }
     }else{
      if(marked.null9b65d0())index=list->size();
      while(1){
       if(--index==0){marked.reset9b7270();break;}
       else if(!(*list)[index]->target45a760()){marked=(*list)[index];target=marked;break;}
      }
     }
    }
   }
   center8069e0(target->pos45a4c0(),false);
  }
  return true;
 case 0x32:
  if(!fc_d28d15)goto font;
  return true;
 case 0x33:
  if(fc_d28d15)goto font;
  return true;
 case 0x31:
 font:
  fc_toggleFont7f46e0();
  fc_d1da74=fc_caed20;
  fc_d1da78=fc_d28d15;
  fc_d1da7c=fc_d28d15?400:1000;
  fc_sound4541b0(fc_d28d15?54:55,0,0);
  if(fc_d28d15){fc_d257d6=true;fc_d22590[4]=1;fc_cefaa8->show793450(5,true,0,false,false);}
  return true;
 case 0x34:
  u8080a0();
  return true;
 case 0x35:
  u8081d0();
  return true;
 case 0x36:
  fc_d28d27=!fc_d28d27;
  fc_warn7b1750(fc_d28d27?199:200,&string("Part auto-activation"),0,0,FcHE(),FcHE(),0);
  return true;
 case 0x37:
  fc_d28e4a=!fc_d28e4a;
  fc_warn7b1750(fc_d28e4a?200:199,&string("Mouse warping"),0,0,FcHE(),FcHE(),0);
  return true;
 case 0x38:
  fc_d28e3c=!fc_d28e3c;
  fc_warn7b1750(fc_d28e3c?199:200,&string("Cursor forced centering"),0,0,FcHE(),FcHE(),0);
  return true;
 case 0x39:
  if(fc_d223f0.u4189e0()<=10&&!fc_d28d30)fc_warn7b1750(219,&fc_intToString4051f0(fc_d223f0.u4189e0()),0,0,FcHE(),FcHE(),0);
  else{new FcSprite(this);fc_cefaa8->u78d700(1,0);}
  return true;
 case 0x3a:
  fc_d28e08=!fc_d28e08;
  fc_warn7b1750(fc_d28e08?199:200,&string("Auto-Waiting"),0,0,FcHE(),FcHE(),0);
  return true;
 case 0x3b:
  if(player.valid9b7230()){
   FcPos pick;
   if(pick805190(&pick))center8069e0(pick,true);
  }
  return true;
 }
 if(fc_cefa8c->get416200(6)){
  switch(event->command){
  case 0x50:
   fc_cefc4c->reveal726840(FcBox(0,0,fc_cfd44c.width9fcd80()-1,fc_cfd44c.height9b8f00()-1),fc_caed20-lastReveal<2000);
   lastReveal=fc_caed20;
   for(int i=0;i<fc_cefc4c->machines.size();i++){
    if(fc_cefc4c->machines[i]->h14.null9b65d0()&&fc_cefc4c->machines[i]->h18.null9b65d0()){fc_cefc4c->announce71dd30(fc_cefc4c->machines[i]->handle);fc_cefc4c->machines[i]->announced=true;}
   }
   return true;
  case 0x51:
   fc_cefc4c->known.zero9d28b0();
   return true;
  case 0x52:
   showB=!showB;
   return true;
  case 0x53:
   u808290();
   return true;
  case 0x54:
   showC=!showC;
   return true;
  case 0x55:
   showA=!showA;
   return true;
  case 0x56:
   for(int i=0;i<fc_cefc4c->machines.size();i++){
    if(fc_cefc4c->machines[i]->handle->inRange46ecb0()){fc_openEvolve4b5780(0,fc_cefc4c->machines[i]->handle,0);break;}
   }
   return true;
  case 0x57:
   if(player.valid9b7230()){
    FcPos pick;
    if(pick805190(&pick)){
     FcPos old(player->getPosition45a4a0());
     player->changePos5dccb0(pick,true);
     if(fc_cefc4c->entity463110().valid9b7230()&&fc_cefc4c->entity463110()->getPosition45a4a0().adjacent409dd0(old)&&fc_cefc4c->findPlaceableNear71c150(pick,pick,fc_cefc4c->entity463110()->getSize45a360()))fc_cefc4c->entity463110()->changePos5dccb0(pick,true);
     fc_cefc4c->update71cf70();
    }
   }
   return true;
  case 0x58:{
   FcPos pick;
   if(pick805190(&pick)&&(*fc_cfd44c.atPoint9ced70(pick))->getEntity45d250().valid9b7230())(*fc_cfd44c.atPoint9ced70(pick))->getEntity45d250()->u637bb0();
   return true;}
  case 0x59:{
   FcPos pick;
   if(pick805190(&pick)&&(*fc_cfd44c.atPoint9ced70(pick))->getEntity45d250().valid9b7230())(*fc_cfd44c.atPoint9ced70(pick))->getEntity45d250()->die633790(0,10,FcHE(),1,0,0,0,0);
   return true;}
  case 0x5a:{
   FcPos pick;
   if(pick805190(&pick)&&fc_caf138!=-1){
    if(fc_caed26){
     int faction=fc_caf13c;
     if(faction==3&&fc_d25de0[fc_caf138]->kind==8)faction=4;
     FcHE entity=fc_cefc4c->place6c58c0(fc_d25de0[fc_caf138],pick,faction,0,fc_d25de0[fc_caf138]->kind!=73?34:32,14,0);
     if(entity.valid9b7230()){
      if(faction==2)entity->ai45b590()->setFollowEntity5b2f80(fc_cefc4c->getPlayer4630f0(),0);
      else if(entity->isHostileTo45aa70(fc_cefc4c->getPlayer4630f0()))fc_cefc4c->hostile72e4c0(fc_cefc4c->getPlayer4630f0(),1);
     }
    }else(*fc_cfd44c.atPoint9ced70(pick))->u66a050(fc_caf138,2,0);
   }
   return true;}
  case 0x5b:{
   FcPos pick;
   if(pick805190(&pick)&&(*fc_cfd44c.atPoint9ced70(pick))->getEntity45d250().valid9b7230()){
    FcHE entity=(*fc_cfd44c.atPoint9ced70(pick))->getEntity45d250();
    int faction=fc_caf140;
    if(faction==3&&entity->getFaction45a2c0()==8)faction=4;
    if(entity->getGroup45a3f0()->type9b4350()!=faction){
     entity->setFaction5dcc70(faction,0);
     if(faction==2)entity->ai45b590()->setFollowEntity5b2f80(fc_cefc4c->getPlayer4630f0(),0);
     fc_cec0f4->add7b1880(new FcPhraseC(entity->name416f40()+" faction set to "+fc_d31c00[fc_caf140],0,0,0,FcHE(),FcHE()));
    }
   }
   return true;}
  }
 }
 switch(mode){
 case 7:
  switch(event->command){
  case 0x5c:facing=0;goto scroll;
  case 0x5d:facing=1;goto scroll;
  case 0x5e:facing=2;goto scroll;
  case 0x5f:facing=3;goto scroll;
  case 0x60:facing=4;goto scroll;
  case 0x61:facing=5;goto scroll;
  case 0x62:facing=6;goto scroll;
  case 0x63:facing=7;
  scroll:{
   FcPos center;
   center805020(center);
   FcPos last(center);
   int steps=fc_d28e70;
   if(fc_d28d15)steps/=2;
   for(int i=0;i<steps;i++)last+=fc_d015d8[facing];
   if(fc_cfd44c.contains9b43b0(last))center8069e0(last,true);
   fc_cefaa8->show793450(86,true,0,false,false);
   return true;}
  case 0x6c:facing=0;goto walk;
  case 0x6d:facing=1;goto walk;
  case 0x6e:facing=2;goto walk;
  case 0x6f:facing=3;goto walk;
  case 0x70:facing=4;goto walk;
  case 0x71:facing=5;goto walk;
  case 0x72:facing=6;goto walk;
  case 0x73:facing=7;
  walk:
   if(player.null9b65d0())return true;
   else if(fc_cefc4c->u4636d0()&&!fc_d28d28)fc_cec0f4->add7b1880(new FcPhraseA(55,0,0,0,FcHE(),FcHE()));
   else if(fc_cefc4c->u463710()&&fc_d28d28)fc_cec0f4->add7b1880(new FcPhraseA(56,0,0,0,FcHE(),FcHE()));
   else if(player->item5d2380(193).valid9b7230()||player->item5d2380(216).valid9b7230())fc_cec0f4->add7b1880(new FcPhraseA(57,0,0,0,FcHE(),FcHE()));
   else{walkDir=facing;walkStart=fc_caed20;walkTime=fc_caed20;skipRefresh=true;}
   return true;
  case 0x64:facing=0;goto move;
  case 0x65:facing=1;goto move;
  case 0x66:facing=2;goto move;
  case 0x67:facing=3;goto move;
  case 0x68:facing=4;goto move;
  case 0x69:facing=5;goto move;
  case 0x6a:facing=6;goto move;
  case 0x6b:facing=7;
  move:
   if(player.null9b65d0())return true;
   else{
    if(locked&&fc_d28e24)return false;
    if(facing==0){
     FcTool*tool=fc_cefa8c->tool416230();
     if(tool&&tool->u415ee0()){
      switch(tool->kind457dd0()){
      case 0x108:fc_cf4ce8[0]++;break;
      case 0x111:fc_cf4ce8[1]++;break;
      case 0x6b:fc_cf4ce8[3]++;break;
      }
     }
    }
    if(player->u5d1280(0)){
     int mode=player->mode5cad50();
     if(fc_d28e79&&fc_ba0984[fc_cefb38]&&(mode==1||mode==2)){
      vector<FcHI>*inventory=player->inventory45ab00();
      for(int i=0;i<inventory->size();i++){
       if((*inventory)[i]->getType44aec0()==1&&fc_ba0984[(*inventory)[i]->def9b4350()->ec]&&(*inventory)[i]->u458220()){
        FcPart*part=fc_cec088->find894e70((*inventory)[i]);
        if(part)fc_cec088->toggle8993e0(part,false);
       }
      }
     }else fc_cec0f4->add7b1880(new FcPhraseA(fc_ba0968[fc_cefb38]?131:132,0,0,0,FcHE(),FcHE()));
     return false;
    }
    if(player->getSize45a360()>1){
     if(fc_d28e7a&&fc_d1d9c0!=5){
      bool changed=player->u5df740(fc_d1d9c0)!=5;
      fc_d1d9c0=5;
      if(changed)return false;
     }
     int v=player->getSize45a360();
     FcPos&self=player->getPosition45a4a0();
     FcPos next(self,fc_d015d8[facing]);
     vector<FcPos>line;
     int num;
     vector<FcPos>*slots=player->shape45d1a0();
     for(int i=0;i<slots->size();i++){
      FcPos cell((*slots)[i],fc_d015d8[facing]);
      if(!fc_contains9d0ce0(*slots,cell))line.push_back(cell);
     }
     for(int i=0;i<line.size();i++)if(!fc_cfd44c.contains9b43b0(line[i]))return false;
     if(fc_caed20<moveBlock)return false;
     if(!player->allowed5c84f0(next))return false;
     if(player->blocked5c8710(next)){
      if(!u49ab60())fc_warn7b1750(138,0,0,0,player,FcHE(),0);
      return true;
     }
     if(fc_d28d2c&&fc_caed20<lastMove+fc_d28d2c)return true;
     if(fc_d338cc.isDown439510(fc_d28fc0)&&walkDir!=facing){input(&FcEvent(event->command+8));return true;}
     int tmp=player->u5d15a0(0);
     if(tmp>=fc_d28e0c){
      if(fc_caed20<warnTime+(tmp>=fc_d28e10?fc_d28e14:500))return true;
      else if(fc_caed20>warnReset+10000){
       warnReset=fc_caed20;
       warnTime=fc_caed20;
       fc_sound4541b0(60,0,0);
       fc_cec0f4->add7b1880(new FcPhraseA(tmp>=fc_d28e10?155:154,0,0,0,FcHE(),FcHE()));
       refresh49ad30();
       return true;
      }
      warnReset=fc_caed20;
     }
     if(player->other5c85a0(next,false)){
      FcHolder holder;
      bool old=false;
      if(!player->u5ddf50(next,holder,&old)){
       if(!u49ab60())fc_cec0f4->add7b1880(new FcPhraseA(old?137:136,0,0,0,FcHE(),FcHE()));
       return false;
      }
     }
     if(fc_cefc2c->u45b5e0(self,next,player.operator->(),&num)){}
     else{
      if(!u49ab60())fc_warn7b1750(138,0,0,0,player,FcHE(),0);
      refresh49ad30();
      return true;
     }
     if(confirm805520(next))return true;
     int x2=1;
     FcPos first(next);
     switch(player->u5db260(x2)){
     case 0:{
      if(fc_d28e48&&!u8052f0(player->getPosition45a4a0())){
       if(fc_caed20<hazardTime+500)return true;
       else if(fc_caed20>hazardReset+3000){
        hazardReset=fc_caed20;
        hazardTime=fc_caed20;
        fc_sound4541b0(60,0,0);
        fc_cec0f4->add7b1880(new FcPhraseA(158,0,0,0,FcHE(),FcHE()));
        refresh49ad30();
        return true;
       }
       hazardReset=fc_caed20;
      }
      if(fc_d28e7e&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->effect457b70(131)){
       if(fc_caed20<itemTime+500)return true;
       else if(fc_caed20>itemReset+3000){
        itemReset=fc_caed20;
        itemTime=fc_caed20;
        fc_sound4541b0(60,0,0);
        fc_warn7b1750(159,&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->name571db0(false,false),0,0,player,FcHE(),0);
        refresh49ad30();
        return true;
       }
       itemReset=fc_caed20;
      }
      int result=player->move63d8a0(first,x2,0);
      if(!player.operator->())return true;
      cleanUp8144d0();
      bool state=false;
      if(player->getPosition45a4a0()==first){
       if((*fc_cfd44c.atPoint9ced70(first))->isMachinePart45dcd0()&&walkPath.empty()){useExit825e00();return true;}
       if(fc_cec078)fc_cec078->load884f60(first,0);
       if(fc_cefa94->u41a6e0()||fc_d28e3c)warpMouse806e70(self,true);
      }else state=true;
      fc_cefc4c->u774390(state?14:x2>1?2:1,result);
      break;}
     case 1:
      fc_warn7b1750(0,&fc_intToString4051f0(fc_cefc68),0,0,player,FcHE(),0);
      fc_cefaa8->show793450(50,true,0,false,false);
      refresh49ad30();
      if(fc_d28e08){
       fc_cec0f4->add7b1880(new FcPhraseA(2,0,0,0,FcHE(),FcHE()));
       fc_cefc4c->u774390(0,-1);
      }
      break;
     }
     return true;
    }
    if(fc_cf4780&&walkDir==8&&walkPath.empty()&&action824020(player,facing))return true;
    if(fc_d28e7a&&fc_d1d9c0!=5){
     bool changed=player->u5df740(fc_d1d9c0)!=5;
     fc_d1d9c0=5;
     if(changed)return false;
    }
    FcPos&location=player->getPosition45a4a0();
    FcPos begin(location,fc_d015d8[facing]);
    int attempt;
    if(!fc_cfd44c.contains9b43b0(begin))return false;
    if(fc_caed20<moveBlock)return false;
    bool added=false;
    if(walkSteps==0||walkDir==8&&walkPath.empty()){
     if((*fc_cfd44c.atPoint9ced70(begin))->getEntity45d250().valid9b7230()){
      if(player->u45aaa0((*fc_cfd44c.atPoint9ced70(begin))->getEntity45d250())){
       if((*fc_cfd44c.atPoint9ced70(begin))->getEntity45d250()->target45a760()==1||(*fc_cfd44c.atPoint9ced70(begin))->getEntity45d250()->target45a760()==3){
        do{if(fc_showMessage5111e0(130,0,0,0,(*fc_cfd44c.atPoint9ced70(begin))->getEntity45d250(),FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        (*fc_cfd44c.atPoint9ced70(begin))->getEntity45d250()->u5fdab0();
        fc_cefc4c->u774390(15,-1);
        refresh49ad30();
        return true;
       }
      }else if(player->u5d5d40().valid9b7230()){
       if(!fc_d28fa3&&(*fc_cfd44c.atPoint9ced70(begin))->getEntity45d250().valid9b7230()&&player->u5d5d40()->kind457f90()!=119&&((*fc_cfd44c.atPoint9ced70(begin))->getEntity45d250()->target45a760()!=0||!player->isHostileTo45aa70((*fc_cfd44c.atPoint9ced70(begin))->getEntity45d250()))){
        if(allyPos.x==-1||allyPos!=begin){
         ally:
         allyPos=begin;
         allyTime=fc_caed20;
         allyReset=fc_caed20;
         fc_sound4541b0(60,0,0);
         fc_cec0f4->add7b1880(new FcPhraseA((*fc_cfd44c.atPoint9ced70(begin))->getEntity45d250()->target45a760()?152:150,0,0,0,FcHE(),FcHE()));
         refresh49ad30();
         return true;
        }else if(fc_caed20<allyTime+500)return true;
        else if(fc_caed20>allyReset+3000)goto ally;
        allyReset=fc_caed20;
       }
       if(!fc_d28fa4&&(*fc_cfd44c.atPoint9ced70(begin))->getEntity45d250().valid9b7230()&&player->u5d1390()==4){
        if(stealthPos.x==-1||stealthPos!=begin){
         stealth:
         stealthPos=begin;
         stealthTime=fc_caed20;
         stealthReset=fc_caed20;
         fc_sound4541b0(60,0,0);
         fc_cec0f4->add7b1880(new FcPhraseA(151,0,0,0,FcHE(),FcHE()));
         fc_cefaa8->show793450(46,true,0,false,false);
         refresh49ad30();
         return true;
        }else if(fc_caed20<stealthTime+500)return true;
        else if(fc_caed20>stealthReset+3000)goto stealth;
        stealthReset=fc_caed20;
       }
       if(u805de0(player,false))return true;
       if(u8062d0())return true;
       third8231f0(player,begin);
       refresh49ad30();
       return true;
      }
     }
    }
    if(0){}
    if(fc_d28d2c&&fc_caed20<lastMove+fc_d28d2c)return true;
    if(fc_d338cc.isDown439510(fc_d28fc0)&&walkDir!=facing){input(&FcEvent(event->command+8));return true;}
    bool failed=false;
    if((player->u5cab90()>=fc_b96240&&fc_cefc4c->u463710()&&rng.rangeFloat(0,fc_c36ec8)<=(double)player->u5cab90()/fc_b96240||fc_d25450.active&&fc_d255cc&&(!fc_d255d0||rng.chance(50)))&&!player->blocked5c8710(begin)){
     int tries=0;
     int newDir;
     for(;;){
      do newDir=rng.rangeInt(0,fc_c36ffc);while(newDir==facing);
      facing=newDir;
      begin.set40a090(location,fc_d015d8[facing]);
      if(fc_cfd44c.contains9b43b0(begin)&&(*fc_cfd44c.atPoint9ced70(begin))->isPassableFor66ab30(player)&&!(*fc_cfd44c.atPoint9ced70(begin))->isMachinePart45dcd0())break;
      tries++;
      if(tries>=100)return false;
     }
     failed=true;
     if(fc_d255cc)fc_d255d0=true;
     else{
      fc_warn7b1750(91,0,0,0,player,FcHE(),0);
      fc_d2c658.add4729d0(452,1,fc_b96447,-1);
      fc_d2c658.add4729d0(463,1,fc_b96451,-1);
      switch(player->u5d1390()){
      case 1:
       if(rng.chance(10)){
        FcHI item;
        vector<FcHI>*inventory=player->inventory45ab00();
        for(int i=0;i<inventory->size();i++){
         if((*inventory)[i]->type457880()==10&&(*inventory)[i]->active457cf0()){item=(*inventory)[i];break;}
        }
        do{if(fc_showMessage5111e0(367,&item->name571db0(false,false),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        added=true;
       }
       break;
      case 4:
       if(rng.chance(10)){
        bool wall=false;
        FcArea area;
        fc_cfd44c.getRect9b4430(player->getPosition45a4a0(),1,area);
        for(int x=area.x1;x<=area.x2;x++){
         for(int y=area.y1;y<=area.y2;y++){
          if(!(*fc_cfd44c.at9ceda0(x,y))->solid4550b0()){wall=true;break;}
         }
        }
        do{if(fc_showMessage5111e0(366,&string(wall?"wall":"ceiling"),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        int hits=fc_d2e838.randomInRange40c130();
        for(int i=0;i<hits;i++){
         if(!player->u5cb9b0(0))break;
         player->takeDamage5e5520(0,0,0,fc_cf08e4.randomInRange40c130(),4,0,0,0,FcHE(),-1,8,0,0,0);
        }
        if(fc_d25450.active&&!fc_d255cc)fc_d25450.u69e700(17,0,0);
        fc_sound4541b0(173,0,0);
        fc_sound4541b0(174,0,0);
       }
       break;
      }
     }
     if(!fc_cfd44c.contains9b43b0(begin))return false;
    }
    FcPos point(begin);
    int count=1;
    retry:
    if(player->allowed5c84f0(point)){
     if(!failed&&fc_cf49fc&&fc_cefc4c->test71cfb0()){player->teleport63b1c0();return true;}
     if(!failed&&!u49ab60()){
      if(player->item5d2380(192).valid9b7230()&&(player->blocked5c8710(point)||player->other5c85a0(point,false))){
       int cx=player->item5d2380(192)->range457fb0()+1;
       FcPos prev(point);
       int x2=1;
       vector<FcPos>kind(1,prev);
       bool adj=false;
       while(x2<cx){
        prev+=fc_d015d8[facing];
        x2++;
        kind.push_back(prev);
        if(!fc_cfd44c.contains9b43b0(prev))break;
        if(!player->blocked5c8710(prev)&&!player->other5c85a0(prev,false)){adj=true;break;}
       }
       if(!adj)fc_cec0f4->add7b1880(new FcPhraseA(163,0,0,0,FcHE(),FcHE()));
       else if(fc_caed20<foldTime+500)return true;
       else if(fc_caed20>foldReset+10000){
        foldReset=fc_caed20;
        foldTime=fc_caed20;
        fc_sound4541b0(60,0,0);
        fc_cec0f4->add7b1880(new FcPhraseA(164,0,0,0,FcHE(),FcHE()));
        return true;
       }else{
        string name=player->other5c85a0(point,false)?(*fc_cfd44c.atPoint9ced70(point))->getEntity45d250()->name416f40():(*fc_cfd44c.atPoint9ced70(point))->getProp45d550().valid9b7230()&&!(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->isPassableFor65e1d0(player)?(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->name45c5b0():(*fc_cfd44c.atPoint9ced70(point))->name45d140();
        player->move63d8a0(prev,x2,1);
        if(!player.operator->())return true;
        cleanUp8144d0();
        if(fc_cec078)fc_cec078->load884f60(prev,0);
        if(fc_cefa94->u41a6e0()||fc_d28e3c)warpMouse806e70(prev,true);
        for(int i=0;i<kind.size();i++)if(!fc_cefc4c->u463160(kind[i]))fc_cefc4c->u4647a0(kind[i],1);
        do{if(fc_showMessage5111e0(224,&name,0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        fc_d2c658.add4729d0(1023,1,fc_b96452,-1);
        if(fc_d2c658.count472c70(1023)==5)fc_cf45d8.u77fbc0(224);
        fc_sound4541b0(261,0,0);
        int first;
        if(fc_lookup9d7980("Spacefold",&first))fc_cefc50->alloc508610()->init503b20(fc_cefc50,first,player->getPosition45a4a0(),&fc_d2e20c,0,0,0,9,0);
        int total=kind.size();
        if(player->u45b300(player->u5ca260()*total/100)==2)return true;
        fc_cefc4c->u774390(1,100);
       }
       return true;
      }
      if(player->item5d2380(193).valid9b7230()&&!player->blocked5c8710(point)&&!player->other5c85a0(point,false)){
       FcPos adj(point);
       vector<FcPos>kind(1,adj);
       for(;;){
        FcPos next(adj);
        next+=fc_d015d8[facing];
        if(!fc_cfd44c.contains9b43b0(next)||player->blocked5c8710(next)||player->other5c85a0(next,false))break;
        adj=next;
        kind.push_back(adj);
       }
       if(kind.size()>1){
        if(fc_caed20<warpTime+500)return true;
        else if(fc_caed20>warpReset+10000){
         warpReset=fc_caed20;
         warpTime=fc_caed20;
         fc_sound4541b0(60,0,0);
         fc_cec0f4->add7b1880(new FcPhraseA(165,0,0,0,FcHE(),FcHE()));
         return true;
        }else{
         player->move63d8a0(adj,kind.size(),1);
         if(!player.operator->())return true;
         cleanUp8144d0();
         if(fc_cec078)fc_cec078->load884f60(adj,0);
         if(fc_cefa94->u41a6e0()||fc_d28e3c)warpMouse806e70(adj,true);
         for(int i=0;i<kind.size();i++)if(!fc_cefc4c->u463160(kind[i]))fc_cefc4c->u4647a0(kind[i],1);
         do{if(fc_showMessage5111e0(225,&fc_intToString4051f0(kind.size()),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
         fc_d2c658.add4729d0(1024,1,fc_b96453,-1);
         if(fc_d2c658.count472c70(1024)==10)fc_cf45d8.u77fbc0(225);
         fc_sound4541b0(262,0,0);
         int fx;
         if(fc_lookup9d7980("Microwarp_Path",&fx)){
          for(int i=0;i<kind.size();i++)if(fc_cefc4c->isVisible4631c0(kind[i]))fc_cefc50->alloc508610()->init503b20(fc_cefc50,fx,kind[i],&fc_d2e20c,0,0,0,9,0);
         }
         int first=kind.size()*player->item5d2380(193)->range457fb0();
         if(player->u45b300(first)==2)return true;
         fc_cefc4c->u774390(1,100);
         return true;
        }
       }
      }
      if(player->item5d2380(216).valid9b7230()){
       if(fc_caed20<teleTime+500)return true;
       else if(fc_caed20>teleReset+10000){
        teleReset=fc_caed20;
        teleTime=fc_caed20;
        fc_sound4541b0(60,0,0);
        fc_cec0f4->add7b1880(new FcPhraseA(166,0,0,0,FcHE(),FcHE()));
        return true;
       }else{
        FcHI attempt=player->item5d24e0(216);
        int clean=attempt->effectValue457be0(117);
        bool id=false;
        FcPropDef*edges=0;
        if(fc_d1e888->type==34&&fc_findByName9d7710(fc_cf35b0,"COM_Teleport_Inhibitor",edges)){
         for(int x=0;x<fc_cfd44c.width9fcd80();x++){
          for(int y=0;y<fc_cfd44c.height9b8f00();y++){
           if((*fc_cfd44c.at9ceda0(x,y))->getProp45d550().valid9b7230()&&(*fc_cfd44c.at9ceda0(x,y))->getProp45d550()->def9b8f00()==edges&&!(*fc_cfd44c.at9ceda0(x,y))->getProp45d550()->u457b10())goto inhibited;
          }
         }
         edges=0;
        }
        inhibited:
        if(edges){
         do{if(fc_showMessage5111e0(234,&attempt->name571db0(false,false),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
         if(fc_d25450.active&&clean==2)fc_d25450.u69e700(60,0,0);
         id=true;
        }else{
         vector<FcPos>first;
         FcPos other(player->getPosition45a4a0());
         FcPos res=point-other;
         res.scale40a300(20);
         FcPos temp(other,res);
         FcSpan room;
         vector<FcPos>frontier;
         FcPos dest;
         int weight;
         int len;
         for(int pass=0;pass<2;pass++){
          if(pass!=0)room.set40a010(5,(int)(attempt->range457fb0()*0.8));
          else room.set40a010((int)(attempt->range457fb0()*0.8),(int)(attempt->range457fb0()*1.2));
          for(int tries=0;tries<100;tries++){
           weight=rng.rangeInt(fc_c37228,fc_c36fc0);
           if(weight<0)weight+=360;
           fc_rotate501fc0(&other,&temp,weight,&point);
           FcLine line(other.x,other.y,point.x,point.y);
           do{
            line.next4102a0(dest);
            len=fc_distance40a3f0(other,dest);
            if(len>room.max||!fc_cfd44c.contains9b43b0(dest))break;
            if(len>=room.min&&!player->blocked5c8710(dest)&&(!player->other5c85a0(dest,false)||(*fc_cfd44c.atPoint9ced70(dest))->getEntity45d250()->def9b4350()->x24==1||(*fc_cfd44c.atPoint9ced70(dest))->getEntity45d250()->def9b4350()->x24==3))frontier.push_back(dest);
           }while(1);
           if(!frontier.empty())break;
          }
          if(!frontier.empty())break;
         }
         if(frontier.empty()){
          do{if(fc_showMessage5111e0(233,&attempt->name571db0(false,false),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
          id=true;
         }else{
          FcPos title=fc_randomPoint9d5350(frontier);
          do{if(fc_showMessage5111e0(230,&attempt->name571db0(false,false),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
          fc_d2c658.add4729d0(1022,1,fc_b9645d,-1);
          fc_cf45d8.u77fbc0(134);
          fc_sound4541b0(266,0,0);
          FcPos open;
          if(clean==1){attempt->u4585c0(119);player->u64e7e0(attempt);fc_cec088->find894e70(attempt)->u890710(true);}
          if(clean==1&&rng.chance(2)){
           if(!fc_cefc4c->u71bc10(other,open))attempt->remove57dbe0(1,1,0,1);
           else{
            do{if(fc_showMessage5111e0(231,&attempt->name571db0(false,false),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
            fc_cefc4c->u464840(attempt);
            attempt->u57a0f0(open,0,1);
           }
           if(fc_d25450.active)fc_d25450.u69e700(61,0,0);
          }else{
           if(clean==2)attempt->remove57dbe0(1,0,0,1);
           FcWL table;
           for(int i=0;i<5;i++)table.add9ba310(i,fc_ba0bb8[i][clean-1]);
           int outcome=table.pick9ba470();
           vector<int>center;
           switch(outcome){
           break;
           case 1:center.push_back(0);break;
           case 2:center.push_back(0);center.push_back(0);break;
           case 3:center.push_back(0);center.push_back(1);break;
           case 4:center.push_back(2);break;
           }
           if(!center.empty()){
            vector<FcHI>parts;
            vector<FcHI>*inventory=player->inventory45ab00();
            for(int i=0;i<inventory->size();i++){
             if((*inventory)[i]->getType44aec0()<=3&&((*inventory)[i]->def9b4350()->x70!=0||(*inventory)[i]->def9b4350()->x94==2)&&(*inventory)[i]->kind457f90()!=7&&(*inventory)[i]->kind457f90()!=0xd8&&(!(*inventory)[i]->u577fb0()||!fc_ba0984[(*inventory)[i]->def9b4350()->ec])&&!(*inventory)[i]->effect457b70(0x6c))parts.push_back((*inventory)[i]);
            }
            for(int i=0;i<center.size()&&!parts.empty();i++){
             FcHI part=fc_popRandom9d8030(parts);
             open.set409ff0(-1);
             if(center[i]!=2&&!part->def9b4350()->x1ac&&!part->effect457b70(0x6e)&&!part->u457e90()){
              FcArea area;
              fc_cfd44c.getRect9b4430(center[i]==0?title:other,5,area);
              for(int tries=0;tries<20;tries++){
               area.randomPoint40be30(&open);
               if(fc_cefc4c->u71bc10(open,open))goto placed;
              }
              open.set409ff0(-1);
             }
             placed:
             if(open.x==-1){
              do{if(fc_showMessage5111e0(232,&part->name571db0(false,false),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
              part->remove57dbe0(1,1,0,1);
             }else{
              do{if(fc_showMessage5111e0(231,&part->name571db0(false,false),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
              fc_cefc4c->u464840(part);
              part->u57a0f0(open,0,1);
              first.push_back(open);
             }
            }
           }
          }
          if((*fc_cfd44c.atPoint9ced70(title))->getEntity45d250().valid9b7230()){
           if(fc_cefc4c->isVisible4631c0(title)){string text=(*fc_cfd44c.atPoint9ced70(title))->getEntity45d250()->name416f40()+" ripped apart by twisting subspace fabric.";fc_message49c610(800,FcHE(),text,0);}
           (*fc_cfd44c.atPoint9ced70(title))->getEntity45d250()->die633790(0,10,FcHE(),1,0,0,0,0);
          }
          if(fc_d25450.active)fc_d25450.u69ec90();
          player->move63d8a0(title,1,1);
          if(!player.operator->())return true;
          cleanUp8144d0();
          if(fc_cec078)fc_cec078->load884f60(title,0);
          if(fc_cefa94->u41a6e0()||fc_d28e3c)warpMouse806e70(title,true);
          if(fc_d25450.active)fc_d25450.u69ecb0(57+(clean!=2));
          int cx;
          if(fc_lookup9d7980("Teleport_Rough",&cx))if(fc_cefc4c->isVisible4631c0(title))fc_cefc50->alloc508610()->init503b20(fc_cefc50,cx,title,&fc_d2e20c,0,0,0,9,0);
          for(int i=0;i<first.size();i++)if(fc_cefc4c->isVisible4631c0(first[i]))fc_cefc50->alloc508610()->init503b20(fc_cefc50,cx,first[i],&fc_d2e20c,0,0,0,9,0);
          vector<FcPos>bottom;
          fc_line40ff30(other,title,bottom);
          if(!bottom.empty())bottom.pop_back();
          if(!bottom.empty())bottom.pop_back();
          for(int i=0;i<first.size();i++){
           fc_line40ff30(other,first[i],bottom);
           if(!bottom.empty())bottom.pop_back();
           if(!bottom.empty())bottom.pop_back();
          }
          if(fc_lookup9d7980("Teleport_Rough_Path",&cx)){
           for(int i=0;i<bottom.size();i++){
            FcPos p(bottom[i]);
            p.x+=rng.rangeInt(fc_c36e10,1);
            p.y+=rng.rangeInt(fc_c36e10,1);
            if(fc_cfd44c.contains9b43b0(p)&&fc_cefc4c->isVisible4631c0(p))fc_cefc50->alloc508610()->init503b20(fc_cefc50,cx,p,&fc_d2e20c,0,0,0,9,0);
           }
          }
          fc_cefc4c->u774390(1,100);
         }
        }
        if(id){
         if(clean==1){
          attempt->effect457b70(119)->value*=fc_ba0be0;
          fc_cec088->toggle8993e0(fc_cec088->find894e70(attempt),true);
         }
         int fx;
         if(fc_lookup9d7980("Teleport_Rough_Fail",&fx))fc_cefc50->alloc508610()->init503b20(fc_cefc50,fx,player->getPosition45a4a0(),&fc_d2e20c,0,0,0,9,0);
         fc_sound4541b0(267,0,0);
         fc_cefc4c->u774390(17,100);
        }
        return true;
       }
      }
      if(fc_cf4700&&fc_d1e860.u46f4b0(1)){
       if(fc_contains9db330(fc_d25de0[*fc_cf4700]->x148,3)&&fc_u6c10f0(point)!=-1&&!(*fc_cfd44c.atPoint9ced70(point))->u45d310()&&(*fc_cfd44c.atPoint9ced70(point))->getEntity45d250().null9b65d0()&&player->u5d5520(1)){
        FcPos pos(point);
        bool flag=fc_cf0fa8[fc_ce9ff4]->x8==*fc_cefb9c;
        if(!fc_cfb844[fc_cf0fa8[fc_ce9ff4]->x8]->x58&&(*fc_cfd44c.atPoint9ced70(pos))->getItem45d8f0().valid9b7230()){
         vector<FcPos>cells(1,pos);
         if(!fc_cefc4c->u71ec60(pos,cells))(*fc_cfd44c.atPoint9ced70(pos))->getItem45d8f0()->remove57dbe0(0,0,1,1);
        }
        if((*fc_cfd44c.atPoint9ced70(pos))->getEffect45d350(6)){
         (*fc_cfd44c.atPoint9ced70(pos))->u45dfb0(6);
         do{if(fc_showMessage5111e0(781,0,0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        }else{
         (*fc_cfd44c.atPoint9ced70(pos))->u66a050(fc_cf0fa8[fc_ce9ff4]->x8,1,0);
         do{if(fc_showMessage5111e0(780,&(*fc_cfd44c.atPoint9ced70(pos))->name45d140(),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        }
        vector<FcHE>*members=fc_cefc4c->groups[4]->members416f40();
        for(int i=0;i<members->size();i++){
         if((*members)[i]->ai45b590()&&*(*members)[i]->ai45b590()->pos462e10()==pos)(*members)[i]->ai45b590()->pos462e10()->x=-1;
        }
        if(flag){
         fc_cf45d8.addSuspicion77ee70(fc_ba850c,3,FcHE());
         fc_cefc4c->u774390(17,25);
         return true;
        }else{
         fc_cf45d8.addSuspicion77ee70(fc_ba8508,2,FcHE());
         fc_cefc4c->u774390(17,100);
         return true;
        }
       }
       if(fc_contains9db330(fc_d25de0[*fc_cf4700]->x148,4)&&(*fc_cfd44c.atPoint9ced70(point))->u45d310()&&player->u5d5460(1)){
        (*fc_cfd44c.atPoint9ced70(point))->u66a050(*fc_cefb88,5,0);
        vector<FcHE>*members=fc_cefc4c->groups[4]->members416f40();
        for(int i=0;i<members->size();i++){
         if((*members)[i]->ai45b590()&&*(*members)[i]->ai45b590()->pos462e10()==point)(*members)[i]->ai45b590()->pos462e10()->x=-1;
        }
        if(rng.chance(50))(*fc_cfd44c.atPoint9ced70(point))->u66b700(0,(*fc_cfd44c.atPoint9ced70(point))->u45d180());
        do{if(fc_showMessage5111e0(782,0,0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        fc_cf45d8.addSuspicion77ee70(fc_ba8510,4,FcHE());
        fc_cefc4c->u774390(17,100);
        return true;
       }
      }
     }
     if((*fc_cfd44c.atPoint9ced70(point))->getProp45d550().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->idx44ab40()!=-1&&fc_d31640[(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->idx44ab40()].front()->u45cb30()&&count==1&&player->item5d2380(164).valid9b7230()){
      if(u49ab60())refresh49ad30();
      else if((*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->def9b8f00()->xf8<=4&&!fc_d2f32c[(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->idx44ab40()].empty()){
       int range=player->item5d2380(164)->range457fb0();
       if(range>player->u45a920()){fc_warn7b1750(1,&fc_intToString4051f0(range),0,0,player,FcHE(),0);return true;}
       int idx=(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->idx44ab40();
       fc_shuffle9d7350(fc_d2f32c[idx]);
       for(int i=0;i<fc_d2f32c[idx].size();i++){
        FcPos spot(fc_d2f32c[idx][i]);
        FcPos dest2(-1);
        if((*fc_cfd44c.atPoint9ced70(spot))->getEntity45d250().valid9b7230()){
         if(!fc_cefc4c->findPlaceableNear71c150(spot,dest2,(*fc_cfd44c.atPoint9ced70(spot))->getEntity45d250()->getSize45a360())){
          if(i==fc_d2f32c[idx].size()-1){fc_warn7b1750(138,&(*fc_cfd44c.atPoint9ced70(spot))->getEntity45d250()->name416f40(),0,0,player,FcHE(),0);return true;}
          else continue;
         }else{
          (*fc_cfd44c.atPoint9ced70(spot))->getEntity45d250()->u5ddac0(dest2,0);
          dest2.x=-1;
         }
        }
        if(dest2.x==-1){
         if((*fc_cfd44c.atPoint9ced70(spot))->getProp45d550().valid9b7230()){
          if((*fc_cfd44c.atPoint9ced70(spot))->u45dcf0())(*fc_cfd44c.atPoint9ced70(spot))->removeProp66c100(0,4);
          else{
           bool moved=false;
           if((*fc_cfd44c.atPoint9ced70(spot))->getProp45d550()->u470b30()){
            FcPos spot2;
            if(fc_cefc4c->findPropSpotNear71c3c0(spot,spot2,(*fc_cfd44c.atPoint9ced70(spot))->getProp45d550()->def9b8f00())){(*fc_cfd44c.atPoint9ced70(spot))->getProp45d550()->u65f270(spot2);moved=true;}
           }
           if(!moved)(*fc_cfd44c.atPoint9ced70(spot))->getProp45d550()->u45ce10(1,0,1,FcHE());
          }
         }
         FcHProp chance=fc_d31640[idx].front();
         int ay=chance->def9b8f00()->xf8;
         FcPropDef*desc;
         fc_findByName9d7710(fc_cf35b0,string("Repaired_Machine_")+fc_b99c08[ay],desc);
         FcHProp col=fc_cefaa8->create793360(desc);
         (*fc_cfd44c.atPoint9ced70(spot))->u45df50(col);
         col->u45cc50(spot);
         col->u65e500();
         col->setIdx451400(chance->idx44ab40());
         col->set448080(chance->u457af0());
         fc_d31640[chance->idx44ab40()].push_back(col);
         fc_eraseAt9d5190(fc_d2f32c[idx],i);
         if((*fc_cfd44c.atPoint9ced70(spot))->getItem45d8f0().valid9b7230()){
          vector<FcPos>cells;
          if(!fc_cefc4c->u71ec60(spot,cells))(*fc_cfd44c.atPoint9ced70(spot))->getItem45d8f0()->remove57dbe0(0,0,1,1);
         }
         if(desc->x68)fc_cefc4c->addPoint465320(spot);
         player->u45b1e0(range);
         fc_cefc4c->u774390(17,200);
         do{if(fc_showMessage5111e0(119,&chance->name45c5b0(),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
         fc_sound4541b0(227,0,0);
         if(fc_d2f32c[idx].empty()){
          for(int j=0;j<fc_d31640[idx].size();j++){
           fc_d31640[idx][j]->set452270(0);
           fc_d31640[idx][j]->u45cd10(0);
           if(j==0)fc_d31640[idx][j]->u45cca0(FcColor(fc_b9e678[ay].r,fc_b9e678[ay].g,fc_b9e678[ay].b));
           else if(!fc_d31640[idx][j]->def9b8f00()->xfc)fc_d31640[idx][j]->u45cc70(FcColor(fc_b9e678[ay].r,fc_b9e678[ay].g,fc_b9e678[ay].b)*fc_c371b8);
          }
          fc_d2a2cc[idx]=1;
          fc_cefc4c->u459070()[ay].push_back(chance->pos4184d0());
          if(chance->u45cad0())fc_d2d2a0.updatePropMute454520(chance);
          do{if(fc_showMessage5111e0(120,&chance->name45c5b0(),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
          fc_d2c658.add4729d0(609,1,fc_b9645e,-1);
          fc_sound4541b0(228,0,0);
          fc_cf45d8.u77fbc0(128);
         }
        }
        break;
       }
      }
      else if((*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->u45cb30()){
       if((*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->def9b8f00()->xf8==0){
        FcHProp prop=(*fc_cfd44c.atPoint9ced70(point))->getProp45d550();
        if(prop->u45c800(9))goto hack;
        int id=player->item5d2380(164)->range457fb0();
        if(id>player->u45a920()){fc_warn7b1750(1,&fc_intToString4051f0(id),0,0,player,FcHE(),0);return true;}
        int value;
        do value=fc_d2d478.randomInRange40c130();while(fc_between9d4c40(-5,value,5));
        prop->u45cee0(new FcPosN(fc_d2f0f8[9],value));
        fc_clearObjects9d0670(prop->u45cb30()->x18);
        if(!prop->u45cb30()->x30){prop->u45cb30()->x30=true;prop->u45cb30()->x34=0;}
        player->u45b1e0(id);
        fc_cefc4c->u774390(17,200);
        do{if(fc_showMessage5111e0(121,&prop->name45c5b0(),&fc_intToStringSigned405560(value),0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        fc_sound4541b0(229,0,0);
       }else{
        fc_warn7b1750(90,0,0,0,player,FcHE(),0);
       }
      }
      return true;
     }
     if((*fc_cfd44c.atPoint9ced70(point))->getProp45d550().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->idx44ab40()!=-1&&(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->u45c630()!=-1&&!(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->isPassableFor65e1d0(FcHE())&&count==1&&player->item5d2380(165).valid9b7230()){
      if(u49ab60())refresh49ad30();
      else if(u805de0(player,true))return true;
      else{
       FcHProp g2=(*fc_cfd44c.atPoint9ced70(point))->getProp45d550();
       FcHI res=player->item5d2380(165);
       int id=g2->u45c630()/5-g2->u665a70(10,1);
       do{if(fc_showMessage5111e0(210,&g2->name45c5b0(),&res->name571db0(false,false),0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
       timers.push_back(FcTimer(point));
       if(id==0){
        do{if(fc_showMessage5111e0(211,&g2->name45c5b0(),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        if(!g2->u457b10())fc_d2c658.add4729d0(610,1,fc_b9645f,-1);
        if(g2->u45c630()>=40&&(g2->name45c5b0().find("Sealed",0)!=string::npos||g2->name45c5b0().find("Blast",0)!=string::npos))fc_cf45d8.u77fbc0(10);
        else if(g2->u45c590()=="HUB_Network_Hub")fc_cf45d8.u77fbc0(133);
        vector<FcPos>adj(1,g2->pos4184d0());
        fc_getAdjacentCells4fab80(g2->pos4184d0(),adj);
        int col=g2->idx44ab40();
        for(int i=0;i<adj.size();i++){
         if((*fc_cfd44c.atPoint9ced70(adj[i]))->getProp45d550().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(adj[i]))->getProp45d550()->idx44ab40()==col){
          (*fc_cfd44c.atPoint9ced70(adj[i]))->getProp45d550()->u45ce10(1,0,1,player);
          if(fc_d2a2cc[col]==0)(*fc_cfd44c.atPoint9ced70(adj[i]))->u66b690(fc_randomOf9d9c10(fc_d28d30?fc_ba6a28:fc_ba69e0,17),fc_d1f32c);
         }
        }
       }else{
        removeMarker49b400(point);
        showTimer8176a0(4,point,res->range457fb0()*id,0);
       }
       fc_sound454260(player->getPosition45a4a0(),230);
       player->alertGroup639ec0(FcHE(),0);
       player->destroyItems63a0d0();
       fc_cefc4c->u774390(17,res->range457fb0()*100);
      }
      return true;
     }
     if((*fc_cfd44c.atPoint9ced70(point))->getProp45d550().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->idx44ab40()!=-1&&count==1&&player->item5d2380(198).valid9b7230()){
      if(u49ab60())refresh49ad30();
      else{
       FcHProp prop=(*fc_cfd44c.atPoint9ced70(point))->getProp45d550();
       FcHI tool=player->item5d2380(198);
       if(prop->def9b8f00()->x8c==0)fc_warn7b1750(70,&prop->name45c5b0(),0,0,FcHE(),FcHE(),0);
       else if(prop->u457b10()==1)fc_warn7b1750(69,&prop->name45c5b0(),0,0,FcHE(),FcHE(),0);
       else if(prop->u45cb50())fc_warn7b1750(68,&prop->name45c5b0(),0,0,FcHE(),FcHE(),0);
       else if(prop->u45c590()=="SEC_L2_Power_Cell")fc_warn7b1750(71,&prop->name45c5b0(),0,0,FcHE(),FcHE(),0);
       else if(player->u45a920()<tool->range457fb0())fc_warn7b1750(1,&fc_intToString4051f0(tool->range457fb0()),0,0,FcHE(),FcHE(),0);
       else{
        vector<FcHProp>&group=fc_d31640[(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->idx44ab40()];
        for(int i=0;i<group.size();i++)group[i]->u45cd50();
        player->u45b1e0(tool->range457fb0());
        do{if(fc_showMessage5111e0(204,&prop->name45c5b0(),&tool->name571db0(false,false),0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        fc_d2c658.add4729d0(598,1,fc_b96469,-1);
        fc_sound454260(player->getPosition45a4a0(),221);
        fc_cefc4c->u774390(16,-1);
       }
      }
      return true;
     }
     if((*fc_cfd44c.atPoint9ced70(point))->getProp45d550().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->u45cb10()&&count==1){
      hack:
      if(u49ab60())refresh49ad30();
      else fc_cec0f8->open939b50((*fc_cfd44c.atPoint9ced70(point))->getProp45d550());
      return true;
     }else if(player->blocked5c8710(point)){
      if(!u49ab60()){
       if(fc_cf4700&&fc_contains9db330(fc_d25de0[*fc_cf4700]->x148,1)&&(*fc_cfd44c.atPoint9ced70(point))->getProp45d550().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->idx44ab40()!=-1&&fc_d1e860.u46f4b0(1)&&fc_cefc4c->u74d200((*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->idx44ab40())){
        do{if(fc_showMessage5111e0(778,&(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->name45c5b0(),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        if(fc_d1e860.u46f4b0(1))fc_cf45d8.addSuspicion77ee70(fc_ba8504,1,FcHE());
       }else fc_warn7b1750(138,0,0,0,player,FcHE(),0);
      }
      refresh49ad30();
      return true;
     }else if(player->other5c85a0(point,false)){
      fc_cefc4c->u734db0((*fc_cfd44c.atPoint9ced70(point))->getEntity45d250());
      if(fc_cec134)return true;
      if((*fc_cfd44c.atPoint9ced70(point))->getEntity45d250()->getName45a280()=="Sigix Exoskeleton"&&fc_stringToInt405610(fc_d1e860.getEntryText46f6d0("usedCoreResetMatrix_g"))){last824c40(player,point,0,0);return true;}
      int x=133;
      bool clean=false;
      bool w=player->u5d1390()==4&&!player->u45a780();
      if(player->u45aaa0((*fc_cfd44c.atPoint9ced70(point))->getEntity45d250())||fc_cf45d8.u77f260(100)&&((*fc_cfd44c.atPoint9ced70(point))->getEntity45d250()->getGroup45a3f0()->type9b4350()==3||(*fc_cfd44c.atPoint9ced70(point))->getEntity45d250()->getGroup45a3f0()->type9b4350()==4)){
       int pick=player->u5d15a0(0);
       if(pick>=fc_d28e0c){
        if(fc_caed20<warnTime+(pick>=fc_d28e10?fc_d28e14:500))return true;
        else if(fc_caed20>warnReset+10000){
         warnReset=fc_caed20;
         warnTime=fc_caed20;
         fc_sound4541b0(60,0,0);
         fc_cec0f4->add7b1880(new FcPhraseA(154+(pick>=fc_d28e10),0,0,0,FcHE(),FcHE()));
         refresh49ad30();
         return true;
        }
        warnReset=fc_caed20;
       }else if(player->u5d1390()==4&&player->u45a780()){
        if(fc_caed20<warn2Time+500)return true;
        else if(fc_caed20>warn2Reset+10000){
         warn2Reset=fc_caed20;
         warn2Time=fc_caed20;
         fc_sound4541b0(60,0,0);
         fc_cec0f4->add7b1880(new FcPhraseA(156,0,0,0,FcHE(),FcHE()));
         refresh49ad30();
         return true;
        }
        warn2Reset=fc_caed20;
       }
       if((*fc_cfd44c.atPoint9ced70(point))->getEntity45d250()->getSize45a360()==1){
        if(!(*fc_cfd44c.atPoint9ced70(point))->getEntity45d250()->target45a760()){
         if(count>1&&(*fc_cfd44c.atPoint9ced70(point))->getEntity45d250()->u5d1390()!=4)goto w;
         if((*fc_cfd44c.atPoint9ced70(point))->getEntity45d250()->u5d1280(0))goto w;
         goto stepMove;
        }else{
         if((*fc_cfd44c.atPoint9ced70(point))->getEntity45d250()->target45a760())goto interact;
         else{
          if(w)goto w;
          x=134;
         }
        }
       }else{
        if(w)goto w;
        else x=135;
       }
      }else if((*fc_cfd44c.atPoint9ced70(point))->getEntity45d250()->target45a760()){
       interact:
       if(interact825a60(player,point,w))goto w;
       return true;
      }else if(w){
       w:
       point+=fc_d015d8[facing];
       count++;
       goto retry;
      }else if((*fc_cfd44c.atPoint9ced70(point))->getEntity45d250()->getFaction45a2c0()==1&&(*fc_cfd44c.atPoint9ced70(point))->getEntity45d250()->getGroup45a3f0()->type9b4350()==4&&player->u5d2b40("IN-MT5's Pitchfork \"Insurrection\"").valid9b7230()){
       FcHE ally=(*fc_cfd44c.atPoint9ced70(point))->getEntity45d250();
       ally->changeFaction5dc780(fc_cefc4c->group463890(2),0);
       ally->setAI64ecf0(new FcAI(ally,3,8));
       ally->ai45b590()->setFollowEntity5b2f80(player,0);
       if(ally->u5c92e0(3)>0)fc_cefc4c->giveItem6c52b0("Shield Trident",ally,1,0);
       ally->u5deb40(ally->u5ca670());
       FcHI part=player->u5d2b40("IN-MT5's Pitchfork \"Insurrection\"");
       do{if(fc_showMessage5111e0(197,&part->name571db0(false,false),0,0,player,ally,0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
       do{fc_logPhrase5141b0(98,&part->name571db0(false,false),&ally->name416f40(),0,FcHE(),0);}while(0);
       fc_cf45d8.u77fbc0(352);
       part->effect457b70(68)->value--;
       if(!part->effectValue457be0(68)){
        do{if(fc_showMessage5111e0(401,&part->name571db0(false,false),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        part->remove57dbe0(1,0,0,1);
       }else{
        FcRow*row=reinterpret_cast<FcInv*>(fc_cec08c)->u8a1fd0(part,false);
        if(row){
         row->clearRow428ac0(7,0,row->width44b0d0()-7);
         row->u4aa510();
        }
       }
      }else if(player->u5d5d40().null9b65d0()&&(!walkSteps||walkDir==8&&walkPath.empty())){
       last824c40(player,point,facing,failed);
       return true;
      }
      if(walkDir==8&&walkPath.empty())fc_warn7b1750(x,0,0,0,player,FcHE(),0);
      refresh49ad30();
      return true;
     }
     int pick=player->u5d15a0(0);
     if(pick>=fc_d28e0c){
      if(fc_caed20<warnTime+(pick>=fc_d28e10?fc_d28e14:500))return true;
      else if(fc_caed20>warnReset+10000){
       warnReset=fc_caed20;
       warnTime=fc_caed20;
       fc_sound4541b0(60,0,0);
       fc_cec0f4->add7b1880(new FcPhraseA(154+(pick>=fc_d28e10),0,0,0,FcHE(),FcHE()));
       refresh49ad30();
       return true;
      }
      warnReset=fc_caed20;
     }else if(player->u5d1390()==4&&player->u45a780()){
      if(fc_caed20<warn2Time+500)return true;
      else if(fc_caed20>warn2Reset+10000){
       warn2Reset=fc_caed20;
       warn2Time=fc_caed20;
       fc_sound4541b0(60,0,0);
       fc_cec0f4->add7b1880(new FcPhraseA(156,0,0,0,FcHE(),FcHE()));
       refresh49ad30();
       return true;
      }
      warn2Reset=fc_caed20;
     }
     if(fc_d28e47&&!failed){
      if((*fc_cfd44c.atPoint9ced70(point))->canCaveIn66af50()){
       if(fc_caed20<caveTime+500)return true;
       else if(!caveTime){
        float risk=player->u45a720();
        if(risk<2.0&&(*originalTerrain.atPoint9ced70(point)==*TERRAIN_CAVE_WALL||*originalTerrain.atPoint9ced70(point)==*caveinThirdTerrain))risk+=0.4;
        else risk+=1.0;
        if(risk>=2.0){
         caveTime=fc_caed20;
         fc_cefaa8->show793450(49,true,0,false,false);
         fc_sound4541b0(60,0,0);
         fc_cec0f4->add7b1880(new FcPhraseA(157,0,0,0,FcHE(),FcHE()));
         refresh49ad30();
         return true;
        }
       }
      }else caveTime=0;
     }
     if((*fc_cfd44c.atPoint9ced70(point))->isDoor45dda0()&&(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->u44b020()->u65cf50(0)&&!failed){
      if(player->u5d5d40().valid9b7230()&&player->u5d5d40()->kind457f90()==0x77){
       FcHProp door=(*fc_cfd44c.atPoint9ced70(point))->getProp45d550();
       fc_d2c658.add4729d0(587,1,fc_b9646a,-1);
       do{if(fc_showMessage5111e0(525,&door->name45c5b0(),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
       if(rng.chance(player->u5c7f10()/2+10)){
        FcWL table;
        for(int i=0;i<3;i++)table.add9ba310(i,fc_b96bb4[i]);
        switch(table.pick9ba470()){
        case 0:
         if(door->u44b020()->u65cf80())goto forced;
         fc_d2c658.add4729d0(588,1,fc_b9646b,-1);
         do{if(fc_showMessage5111e0(526,&door->name45c5b0(),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
         (*fc_cfd44c.atPoint9ced70(point))->u66ce10(0,0,0,0);
         break;
        case 1:
         forced:
         if(fc_cf4700&&(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->u44b020()->x10==3&&fc_contains9db330(fc_d25de0[*fc_cf4700]->x148,7))fc_cf45d8.addSuspicion77ee70(fc_ba8518,6,FcHE());
         fc_d2c658.add4729d0(589,1,fc_b96473,-1);
         do{if(fc_showMessage5111e0(527,&door->name45c5b0(),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
         (*fc_cfd44c.atPoint9ced70(point))->removeProp66c100(0,4);
         fc_sound4541b0(108,0,0);
         break;
        case 2:
         if(fc_b96a78[door->def9b8f00()->x140])goto forced;
         if(fc_cf4700&&(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->u44b020()->x10==3&&fc_contains9db330(fc_d25de0[*fc_cf4700]->x148,7))fc_cf45d8.addSuspicion77ee70(fc_ba8518,6,FcHE());
         fc_d2c658.add4729d0(590,1,fc_b9648e,-1);
         do{if(fc_showMessage5111e0(528,&door->name45c5b0(),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
         (*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->u44b020()->x10=0;
         (*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->u44b020()->xc=player;
         fc_sound4541b0(109,0,0);
         fc_cf45d8.u77fbc0(5);
         break;
        }
        u49aee0();
       }
       fc_cefc4c->u774390(16,-1);
       refresh49ad30();
       return true;
      }
      int mode=player->u5d1390();
      if(mode==0&&(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->def9b8f00()->x140==14);
      else{
       int chance=fc_caf234[mode];
       if((*fc_cfd44c.atPoint9ced70(point))->getProp45d550()->def9b8f00()->x140==11)chance=100-chance;
       if(player->u45a780())chance=100;
       if(chance){
        if(doorProp.null9b65d0()||doorProp!=(*fc_cfd44c.atPoint9ced70(point))->getProp45d550()){
         door:
         doorProp=(*fc_cfd44c.atPoint9ced70(point))->getProp45d550();
         doorTime=fc_caed20;
         doorReset=fc_caed20;
         fc_sound4541b0(60,0,0);
         fc_cec0f4->add7b1880(new FcPhraseA(153,0,0,0,FcHE(),FcHE()));
         refresh49ad30();
         return true;
        }else if(fc_caed20<doorTime+500)return true;
        else if(fc_caed20>doorReset+3000)goto door;
        doorReset=fc_caed20;
       }
      }
     }
     bool clean=false;
     if(fc_d28e46&&!walkSteps){fc_d28e46=false;clean=true;}
     bool old=fc_cefc2c->u45b5e0(location,point,player.operator->(),&attempt);
     if(clean)fc_d28e46=true;
     if(old)goto stepMove;
    }
    if(walkDir==8&&walkPath.empty())fc_warn7b1750(138,0,0,0,player,FcHE(),0);
    refresh49ad30();
    return true;
    stepMove:
    if(walkDir!=8&&walkSteps!=0){
     bool stop=false;
     if(walkDir%2==0){
      int id=walkDir/2;
      FcPos prev(player->getPosition45a4a0());
      FcPos cx(prev);
      fc_translateRotated446dd0(cx,id,0,-1);
      FcPos x2(cx);
      fc_translateRotated446dd0(x2,id,-1,1);
      FcPos res(prev);
      fc_translateRotated446dd0(res,id,-1,1);
      if(fc_cfd44c.contains9b43b0(x2)&&fc_cfd44c.contains9b43b0(res)&&(!(*fc_cfd44c.atPoint9ced70(x2))->solid4550b0()&&(*fc_cfd44c.atPoint9ced70(res))->solid4550b0()||(*fc_cfd44c.atPoint9ced70(res))->u45db70()&&(!(*fc_cfd44c.atPoint9ced70(res))->isEdge45dc30()||fc_cefc4c->u463e90(res))))stop=true;
      if(!stop){
       x2.FcPos::FcPos(cx);
       fc_translateRotated446dd0(x2,id,1,1);
       res.FcPos::FcPos(prev);
       fc_translateRotated446dd0(res,id,1,1);
       if(fc_cfd44c.contains9b43b0(x2)&&fc_cfd44c.contains9b43b0(res)&&(!(*fc_cfd44c.atPoint9ced70(x2))->solid4550b0()&&(*fc_cfd44c.atPoint9ced70(res))->solid4550b0()||(*fc_cfd44c.atPoint9ced70(res))->u45db70()&&(!(*fc_cfd44c.atPoint9ced70(res))->isEdge45dc30()||fc_cefc4c->u463e90(res))))stop=true;
      }
     }else{
      FcPos prev(player->getPosition45a4a0());
      FcPos cx(prev);
      fc_offsetDiagonal827d90(cx,walkDir,-1,0);
      FcPos x2(cx);
      fc_offsetDiagonal827d90(x2,walkDir,1,1);
      FcPos res(prev);
      fc_offsetDiagonal827d90(res,walkDir,1,1);
      if(fc_cfd44c.contains9b43b0(x2)&&fc_cfd44c.contains9b43b0(res)&&!(*fc_cfd44c.atPoint9ced70(x2))->solid4550b0()&&(*fc_cfd44c.atPoint9ced70(res))->solid4550b0()||(*fc_cfd44c.atPoint9ced70(res))->u45db70()&&(!(*fc_cfd44c.atPoint9ced70(res))->isEdge45dc30()||fc_cefc4c->u463e90(res)))stop=true;
      if(!stop){
       x2.FcPos::FcPos(cx);
       fc_offsetDiagonal827d90(x2,walkDir,1,2);
       res.FcPos::FcPos(prev);
       fc_offsetDiagonal827d90(res,walkDir,1,2);
       if(fc_cfd44c.contains9b43b0(x2)&&fc_cfd44c.contains9b43b0(res)&&!(*fc_cfd44c.atPoint9ced70(x2))->solid4550b0()&&(*fc_cfd44c.atPoint9ced70(res))->solid4550b0()||(*fc_cfd44c.atPoint9ced70(res))->u45db70()&&(!(*fc_cfd44c.atPoint9ced70(res))->isEdge45dc30()||fc_cefc4c->u463e90(res)))stop=true;
      }
     }
     if(stop){refresh49ad30();return true;}
    }
    if(confirm805520(point))return true;
    switch(player->u5db260(count)){
    case 0:{
     if(fc_d28e48&&!u8052f0(player->getPosition45a4a0())){
      if(fc_caed20<hazardTime+500)return true;
      else if(fc_caed20>hazardReset+3000){
       hazardReset=fc_caed20;
       hazardTime=fc_caed20;
       fc_sound4541b0(60,0,0);
       fc_cec0f4->add7b1880(new FcPhraseA(158,0,0,0,FcHE(),FcHE()));
       refresh49ad30();
       return true;
      }
      hazardReset=fc_caed20;
     }
     if(fc_d28e7e&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->effect457b70(131)){
      if(fc_caed20<itemTime+500)return true;
      else if(fc_caed20>itemReset+3000){
       itemReset=fc_caed20;
       itemTime=fc_caed20;
       fc_sound4541b0(60,0,0);
       fc_warn7b1750(159,&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->name571db0(false,false),0,0,player,FcHE(),0);
       refresh49ad30();
       return true;
      }
      itemReset=fc_caed20;
     }
     bool clean=fc_cefc4c->getPlayer4630f0()->u45a6e0()==0;
     if(player->item5d2380(217).valid9b7230()){
      if(fc_cf4a70==-1){
       fc_cf4a70=fc_d386b8.randomInRange40c130();
       fc_cf4a74=fc_d30550.randomInRange40c130();
       fc_cf4a78=false;
       fc_cf4a7c=fc_cefc4c->getTurn464270()+fc_d35b7c.randomInRange40c130();
       fc_cf4a80.clear();
       fc_cf4a90=360;
       fc_cf4a94=0;
      }
      fc_cf4a70--;
      if(!fc_cf4a78&&fc_cf4a70<=fc_cf4a74){
       fc_cec054->u49adc0(500);
       fc_cf4a78=true;
       fc_sound4541b0(265,0,0);
      }
      if(fc_cf4a70==0){
       FcHI phase=player->item5d2380(217);
       if(player->teleport63b5a0(phase->range457fb0(),phase->u457fd0())){fc_cf45d8.u46df70();return true;}
      }
     }
     int result=player->move63d8a0(point,count,0);
     if(added)result*=2;
     if(!player.operator->())return true;
     cleanUp8144d0();
     bool state=false;
     if(player->getPosition45a4a0()==point){
      if(count>1){
       for(int i=1;i<count&&i<walkPath.size();i++)fc_eraseAt9d5190(walkPath,0);
      }
      if((*fc_cfd44c.atPoint9ced70(point))->isMachinePart45dcd0()&&walkPath.empty()){useExit825e00();return true;}
      reinterpret_cast<FcShift*>(&fc_d1d9c0)->shift872ef0(facing,count,clean);
      if(fc_d22590[6]==0&&!fc_d28c8a&&fc_d28d15&&fc_d2c658.count472c70(1007)%100==0&&fc_d1e888->type!=1){
       fc_cefaa8->show793450(6,true,0,false,false);
       fc_d22590[6]=0;
      }
      if(fc_d22590[7]==0&&fc_d28c8a&&fc_d28d15&&fc_d2c658.count472c70(1007)%100==0&&fc_d1e888->type!=1){
       fc_cefaa8->show793450(7,true,0,false,false);
       fc_d22590[7]=0;
      }
      if(fc_cec078)fc_cec078->load884f60(point,0);
      if(fc_cefa94->u41a6e0()||fc_d28e3c)warpMouse806e70(location,true);
     }else state=true;
     fc_cefc4c->u774390(state?14:(count>1)+1,result);
     break;}
    case 1:
     fc_warn7b1750(0,&fc_intToString4051f0(fc_cefc68),0,0,player,FcHE(),0);
     fc_cefaa8->show793450(50,true,0,false,false);
     refresh49ad30();
     if(fc_d28e08){
      fc_cec0f4->add7b1880(new FcPhraseA(2,0,0,0,FcHE(),FcHE()));
      fc_cefc4c->u774390(0,-1);
     }
     break;
    }
    return true;
   }
  case 0x74:facing=0;goto action;
  case 0x75:facing=1;goto action;
  case 0x76:facing=2;goto action;
  case 0x77:facing=3;goto action;
  case 0x78:facing=4;goto action;
  case 0x79:facing=5;goto action;
  case 0x7a:facing=6;goto action;
  case 0x7b:facing=7;
  action:
   if(player.null9b65d0())return true;
   else{action824020(player,facing);return true;}
  case 0x7c:
   fc_cf4780=!fc_cf4780;
   return true;
  case 0x7d:
   if(player.null9b65d0())return true;
   else{
    if(walkDir!=8&&walkSteps>0||!walkPath.empty())refresh49ad30();
    return true;
   }
  case 0x7e:
   if(player.null9b65d0())return true;
   else{
    FcPos&pos=player->getPosition45a4a0();
    if((*fc_cfd44c.atPoint9ced70(pos))->isDoor45dda0()&&!(*fc_cfd44c.atPoint9ced70(pos))->getProp45d550()->u44b020()->u65cf80()){
     if(doorMsgTime&&fc_caed20<doorMsgTime+5000){
      bool closed=(*fc_cfd44c.atPoint9ced70(pos))->getProp45d550()->u45cb90(14);
      (*fc_cfd44c.atPoint9ced70(pos))->u66ce10(1,1,0,0);
      if(closed){
       fc_cf45d8.u77fbc0(6);
       do{fc_logPhrase5141b0(24,0,0,0,FcHE(),0);}while(0);
      }
     }else{
      fc_cec0f4->add7b1880(new FcPhraseA(160,0,0,0,FcHE(),FcHE()));
      doorMsgTime=fc_caed20;
     }
    }else if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->type457880()==5&&fc_cf4830[(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->u457820()]){
     FcHI item=(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0();
     if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->u45dcf0()){
      do{if(fc_showMessage5111e0(523,&item->name571db0(false,false),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
      (*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->u66ce10(1,0,0,0);
     }else{
      if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getProp45d550().valid9b7230()){
       if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getProp45d550()->def9b8f00()->x78)(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getProp45d550()->u45ce10(1,0,1,FcHE());
       else{
        do{if(fc_showMessage5111e0(524,&item->name571db0(false,false),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        goto itemDone;
       }
      }
      FcDef*x2=item->def9b4350();
      int value=item->effectValue457be0(75);
      if(!value)value=-1;
      item->remove57dbe0(0,1,1,1);
      FcPropDef*cx;
      if(fc_findByName9d7710(fc_cf35b0,x2->name8,cx)){
       bool placed=fc_cefc4c->placeProp6c67b0(cx,player->getPosition45a4a0(),-1,0,value);
       if(placed){
        fc_sound4541b0(209,0,0);
        (*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getProp45d550()->u65f170();
        (*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getProp45d550()->u44b020()->x8=fc_cefc4c->getPlayer4630f0();
        (*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getProp45d550()->u44b020()->xc=fc_cefc4c->getPlayer4630f0();
        do{if(fc_showMessage5111e0(522,&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getProp45d550()->name45c5b0(),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        fc_d2c658.add4729d0(594,1,fc_b9648f,-1);
        switch(fc_d1e888->type){
        case 8:case 11:case 21:
         fc_cefc4c->u464590()++;
         break;
        case 10:
         if(fc_d1eaf8.contains40b750(player->getPosition45a4a0())&&!fc_stringToInt405610(fc_d1e860.getEntryText46f6d0("recScraplabLockedDown_g")))fc_cefc4c->u72f6b0();
         break;
        case 20:
         if(player->getPosition45a4a0().x<=100)fc_cefc4c->u464590()++;
         break;
        case 23:
         if(player->getPosition45a4a0().x<75)fc_cefc4c->u464590()++;
         break;
        }
       }
      }
     }
     itemDone:
     fc_cefc4c->u774390(16,-1);
    }else if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->kind457f90()==167&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->u457d70()&&fc_cf4830[(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->u457820()]){
     FcHI item=(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0();
     if(!item->u45cb30())fc_warn7b1750(64,&item->name571db0(false,false),0,0,FcHE(),FcHE(),item->u575920());
     else{
      bool found=false;
      vector<FcHI>*inventory=fc_cefc4c->getPlayer4630f0()->inventory45ab00();
      for(int i=0;i<inventory->size();i++){
       if((*inventory)[i]->def9b4350()==item->def9b4350()&&(*inventory)[i]->getType44aec0()!=4&&(*inventory)[i]->u457d70()){found=true;break;}
      }
      if(!found)fc_warn7b1750(65,&item->name571db0(false,false),0,0,FcHE(),FcHE(),item->u575920());
      else{
       FcRec*x2=item->def9b4350()->getRecord56f3c0();
       FcHE cx;
       FcPos id;
       bool res=false;
       do{
        if(fc_cefc4c->findPlaceableNear71c150(player->getPosition45a4a0(),id,x2->x9c))cx=fc_cefc4c->place6c58c0(x2,id,0,0,34,14,0);
        if(cx.null9b65d0()){fc_warn7b1750(66,&x2->x1ac,0,0,FcHE(),FcHE(),item->u575920());break;}
        cx->u45b2a0();
        item->setCharges44fc60(item->u45cb30()-1);
        do{if(fc_showMessage5111e0(643,&item->name571db0(false,false),0,0,cx,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        fc_d2c658.add4729d0(977,1,fc_b964a6,-1);
        if(cx->def9b4350()->x15c&&fc_d1e888->type==11&&(fc_stringToInt405610(fc_d1e860.getEntryText46f6d0("scrAttackedLocals_g"))||fc_stringToInt405610(fc_d1e860.getEntryText46f6d0("scrCivilWar_g"))))fc_d1eb40++;
        res=true;
       }while(item.operator->()&&item->u45cb30());
       if(res){
        fc_sound454260(player->getPosition45a4a0(),189);
        fc_cefc4c->u774390(17,-1);
       }
      }
     }
    }else if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->kind457f90()==203&&fc_cf4830[(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->u457820()]){
     FcHI item=(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0();
     FcEffDef*state;
     if(!fc_findByName9d7de0(fc_d2c408,"Deploy_Turret",state));
     else if(item->u44a7d0()&&item->u44a7d0()->hasData4563e0(state))fc_warn7b1750(76,&item->def9b4350()->getRecord56f3c0()->x1ac,0,0,FcHE(),FcHE(),0);
     else{
      fc_warn7b1750(75,&item->def9b4350()->getRecord56f3c0()->x1ac,0,0,FcHE(),FcHE(),0);
      item->u57c090(state,0);
      fc_cefc4c->u464f60(item);
      item->u4585c0(1);
      item->addEffect4585a0(new FcPosN(fc_d2f0f8[1],0));
     }
    }else if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->kind457f90()==206&&fc_cf4830[(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->u457820()]){
     FcHI item=(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0();
     FcEffDef*eff;
     if(!fc_findByName9d7de0(fc_d2c408,"Activate_Botcube",eff));
     else if(item->u44a7d0()&&item->u44a7d0()->hasData4563e0(eff))fc_warn7b1750(81,&item->name571db0(false,false),0,0,FcHE(),FcHE(),0);
     else{
      fc_warn7b1750(80,&item->name571db0(false,false),0,0,FcHE(),FcHE(),0);
      item->u57c090(eff,0);
      fc_cefc4c->u464f60(item);
      item->u4585c0(1);
      item->addEffect4585a0(new FcPosN(fc_d2f0f8[1],1));
     }
    }else if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->kind457f90()==140){
     FcHI item=(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0();
     if(armTime&&fc_caed20<armTime+5000){
      do{if(fc_showMessage5111e0(218,&item->name571db0(false,false),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
      do{fc_logPhrase5141b0(102,&item->name571db0(false,false),0,0,FcHE(),0);}while(0);
      FcExpl*blast=item->def9b4350()->x1a0;
      fc_d25628.addItemAttachCount778560(item->u457820(),1,0);
      item->remove57dbe0(0,0,1,1);
      if(!blast);
      else{
       if(fc_d25450.active&&blast->x30>=500)fc_d254f0=blast->x0;
       fc_cefc4c->addRecord777a20(fc_cefaa8->createA7930e0(new FcExplode(FcHE(),blast,player->getPosition45a4a0(),FcHE(),FcPos(-1),FcPos(-1))));
      }
     }else{
      fc_warn7b1750(161,&item->name571db0(false,false),0,0,FcHE(),FcHE(),0);
      armTime=fc_caed20;
     }
    }else if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->kind457f90()==208||(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->effect457b70(86)&&player->item5d2380(197).valid9b7230())){
     FcHI item=(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0();
     if(item->u45cb30()>=0){
      do{if(fc_showMessage5111e0(220,&item->name571db0(false,false),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
      fc_cefc4c->u464cd0(item);
      item->u458560();
      fc_sound454260(player->getPosition45a4a0(),220);
      fc_cefc4c->u774390(16,-1);
     }else if(armTime&&fc_caed20<armTime+5000){
      do{if(fc_showMessage5111e0(219,&item->name571db0(false,false),&fc_intToString4051f0(item->kind457f90()==208?item->range457fb0():8),0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
      if(item->kind457f90()==208)fc_d25628.addItemAttachCount778560(item->u457820(),1,0);
      fc_cefc4c->u728fa0(item);
      if(!item->effect457b70(88))item->addEffect4585a0(new FcPosN(fc_d2f0f8[88],1));
      fc_d2c658.add4729d0(600,1,fc_b964a7,-1);
      fc_sound454260(player->getPosition45a4a0(),219);
      fc_cefc4c->u774390(16,-1);
     }else{
      fc_warn7b1750(162,&item->name571db0(false,false),0,0,FcHE(),FcHE(),0);
      armTime=fc_caed20;
     }
    }else if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->kind457f90()==209&&fc_cf4830[(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->u457820()]){
     fc_cefc4c->bomb744aa0(player);
     fc_cefc4c->u774390(17,-1);
    }else if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&!(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->u4578a0()&&player->item5d2380(197).valid9b7230()){
     FcHI item=(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0();
     FcHI tool=player->item5d2380(197);
     if(!fc_cf4830[item->u457820()])fc_warn7b1750(67,0,0,0,FcHE(),FcHE(),0);
     else if(!item->u457d70())fc_warn7b1750(69,&item->name571db0(false,false),0,0,FcHE(),FcHE(),0);
     else if(player->u45a920()<tool->range457fb0())fc_warn7b1750(1,&fc_intToString4051f0(tool->range457fb0()),0,0,FcHE(),FcHE(),0);
     else{
      do{if(fc_showMessage5111e0(204,&item->name571db0(false,false),&tool->name571db0(false,false),0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
      player->u45b1e0(tool->range457fb0());
      fc_cefc4c->u7289f0(item,player->getGroup45a3f0()->type9b4350());
      fc_d2c658.add4729d0(598,1,fc_b964b2,-1);
      fc_sound454260(player->getPosition45a4a0(),221);
      fc_cefc4c->u774390(16,-1);
     }
    }else if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->kind457f90()==204&&fc_cf4830[(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->u457820()]){
     FcHI item=(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0();
     if(!item->effect457b70(124))fc_warn7b1750(77,&item->name571db0(false,false),0,0,FcHE(),FcHE(),0);
     else if(useTime&&fc_caed20<useTime+5000){
      do{if(fc_showMessage5111e0(208,&item->name571db0(false,false),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
      do{fc_logPhrase5141b0(55,&item->name571db0(false,false),0,0,FcHE(),0);}while(0);
      if(fc_d1e888->type==3)fc_cf45d8.u77fbc0(289);
      item->u4585c0(124);
      fc_cefc4c->u74bec0(player->getPosition45a4a0());
      fc_cefc4c->u774390(17,-1);
     }else{
      string text("About to release subatomizers! Confirm decision");
      fc_warn7b1750(125,&text,0,0,FcHE(),FcHE(),0);
      useTime=fc_caed20;
     }
    }else if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->kind457f90()==205&&fc_cf4830[(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->u457820()]){
     FcHI item=(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0();
     if(!item->effect457b70(124))fc_warn7b1750(78,&item->name571db0(false,false),0,0,FcHE(),FcHE(),0);
     else if(fc_d1e888->type!=16&&fc_d1e888->type!=17&&fc_d1e888->type!=18)fc_warn7b1750(79,&item->name571db0(false,false),0,0,FcHE(),FcHE(),0);
     else if(useTime2&&fc_caed20<useTime2+5000){
      do{if(fc_showMessage5111e0(209,&item->name571db0(false,false),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
      do{fc_logPhrase5141b0(56,&item->name571db0(false,false),0,0,FcHE(),0);}while(0);
      string text=item->name571db0(false,false)+" narrowcast message: \"Please hold, a Derelict Rescue Squad will be with you shortly.\"";
      fc_message49c610(800,FcHE(),text,0);
      item->u4585c0(124);
      fc_cefc4c->u464d00(item,rng.rangeInt(fc_c36e30,fc_c36ff0));
      fc_sound4541b0(281,0,0);
      fc_cefc4c->u774390(17,-1);
     }else{
      string text="About to activate "+item->name571db0(false,false)+"! Confirm decision";
      fc_warn7b1750(125,&text,0,0,FcHE(),FcHE(),0);
      useTime2=fc_caed20;
     }
    }else if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->kind457f90()==124){
     int x2=(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->u457820();
     FcHI cx;
     bool w=false;
     bool clean=false;
     if(fc_cf4a04[5]){
      vector<FcHI>*inventory=fc_cefc4c->player->inventory45ab00();
      for(int i=0;i<inventory->size();i++){
       if((*inventory)[i]->u457820()==x2){
        if((*inventory)[i]->u45cb30()>=99)w=true;
        else if((*inventory)[i]->getType44aec0()!=2)clean=true;
        else if(cx.null9b65d0()||(*inventory)[i]->u45cb30()<cx->u45cb30())cx=(*inventory)[i];
       }
      }
     }
     if(cx.null9b65d0()){
      if(w)fc_cec0f4->add7b1880(new FcPhraseA(84,0,0,0,FcHE(),FcHE()));
      else if(clean)fc_cec0f4->add7b1880(new FcPhraseA(83,0,0,0,FcHE(),FcHE()));
      else if(fc_cf4a04[5])fc_cec0f4->add7b1880(new FcPhraseA(86,0,0,0,FcHE(),FcHE()));
      else fc_cec0f4->add7b1880(new FcPhraseA(85,0,0,0,FcHE(),FcHE()));
     }else{
      FcHI next=(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0();
      int amount=fc_maxInt9cdb60(1,next->u45cb30()*fc_b989a0[fc_cf4a04[5]]/100);
      int room=99-cx->u45cb30();
      fc_clampMax9cf5a0(amount,room);
      cx->setCharges44fc60(cx->u45cb30()+amount);
      fc_cec088->u896a80(cx);
      do{if(fc_showMessage5111e0(677,&cx->name571db0(false,false),&fc_intToString4051f0(amount),0,FcHE(),FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
      fc_d2c658.add4729d0(887,amount,fc_b964b3,-1);
      next->remove57dbe0(0,0,1,1);
     }
    }else if((*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0()->def9b4350()==fc_cefbec){
     FcHI best;
     bool have=false;
     vector<FcHI>*inventory=fc_cefc4c->player->inventory45ab00();
     for(int i=0;i<inventory->size();i++){
      if((*inventory)[i]->active457cf0()&&(*inventory)[i]->def9b4350()==fc_cefbe8){
       have=true;
       if((*inventory)[i]->u9b6bf0()<(*inventory)[i]->u457c80()&&(best.null9b65d0()||(*inventory)[i]->u9b6bf0()<best->u9b6bf0()))best=(*inventory)[i];
      }
     }
     if(!have)fc_cec0f4->add7b1880(new FcPhraseA(87,0,0,0,FcHE(),FcHE()));
     else if(best.null9b65d0())fc_cec0f4->add7b1880(new FcPhraseA(88,0,0,0,FcHE(),FcHE()));
     else{
      FcHI floor=(*fc_cfd44c.atPoint9ced70(player->getPosition45a4a0()))->getItem45d8f0();
      int amount=fc_minInt9cdb30(floor->u9b6bf0(),best->u457cd0());
      best->u458360(amount);
      fc_sound454260(player->getPosition45a4a0(),188);
      do{if(fc_showMessage5111e0(390,&floor->name571db0(false,false),&best->name571db0(false,false),&fc_intToString4051f0(amount),player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
      fc_cf45d8.u77fbc0(127);
      FcPart*part=fc_cec088->find894e70(best);
      if(part)part->drawStatus4a8e70(0);
      floor->remove57dbe0(0,0,1,1);
      fc_cefc4c->u774390(17,-1);
     }
    }else if(player->u5ced30())fc_cec0f4->add7b1880(new FcPhraseA(140,0,0,0,FcHE(),FcHE()));
    else if(!(*fc_cfd44c.atPoint9ced70(pos))->isMachinePart45dcd0())fc_cec0f4->add7b1880(new FcPhraseA(139,0,0,0,FcHE(),FcHE()));
    else if(player->u5d1280(0)){fc_cec0f4->add7b1880(new FcPhraseA(131,0,0,0,FcHE(),FcHE()));return false;}
    else if(confirm805520(pos))return false;
    else useExit825e00();
   }
   return true;
  case 0x80:
   if(scanTime){
    if(fc_caed20>scanTime+10000)u49b5b0();
    if(fc_caed20<=scanReset+10000){
     bool forward=fc_cefa8c->tool416230()->kind457dd0()==5;
     if(forward){
      if(scanMode==5)scanMode=0;
      else scanMode++;
     }else{
      if(scanMode==0)scanMode=5;
      else scanMode--;
     }
     scanReset=0;
     fc_cec054->u8142d0(18,false);
     scan813c80(142);
     scanTime=fc_caed20;
     return true;
    }
   }
   if(fc_d28e07||fc_d28c8a)return true;
  case 0x7f:
   if(fc_d28f8c&&fc_caed20<lastMove+fc_d28f8c)return true;
   else if(fc_caed20<moveBlock2)return true;
   else{
    FcHE p=fc_cefc4c->getPlayer4630f0();
    if((*fc_cfd44c.atPoint9ced70(p->getPosition45a4a0()))->getItem45d8f0().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(p->getPosition45a4a0()))->getItem45d8f0()->type457880()==3){
     FcHI w=(*fc_cfd44c.atPoint9ced70(p->getPosition45a4a0()))->getItem45d8f0();
     int cx=w->u9b6bf0();
     int clean=fc_minInt9cdb30(8,cx);
     int x2=0;
     if(p->u490840()<p->u5ca260()){
      int room=p->u5ca260()-p->u490840();
      int need=room/3+(room%3!=0);
      x2=clean<=need?clean:need;
      cx-=x2;
      room=x2*3;
      if(room>p->u5ca260()-p->u490840())room=p->u5ca260()-p->u490840();
      p->u5de870(room,0);
      if(fc_cf462c==5){
       fc_d2c658.add4729d0(1090,room,fc_b964bb,-1);
       fc_d2c658.add4729d0(1091,room,fc_b964c5,-1);
      }
      fc_sound4541b0(314,0,0);
      if(fc_cefc4c->repairPos!=p->getPosition45a4a0()||!fc_cefc4c->repairFlag){
       fc_cefc4c->repairPos.FcPos::FcPos(p->getPosition45a4a0());
       fc_cefc4c->repairFlag=true;
       fc_cefc4c->repairSum=room;
      }else fc_cefc4c->repairSum+=room;
      if(p->u45a880()==100||cx<=0){
       string text=fc_intToString4051f0(fc_cefc4c->repairSum);
       if(cx<=0)text+=", depleted";
       do{if(fc_showMessage5111e0(764,&string("core"),&text,0,FcHE(),FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
       fc_cefc4c->repairPos.set409ff0(-1);
       u49ada0(fc_caed20+2000);
      }
     }else{
      vector<FcHI>ay;
      p->u5cb8b0(ay);
      vector<FcHI>res;
      vector<FcHI>edges;
      int kind=0;
      for(int i=0;i<ay.size();i++){
       if(ay[i]->u9b6bf0()<ay[i]->u457c80()&&ay[i]->u457d70())res.push_back(ay[i]);
      }
      if(res.empty()){
       fc_cec0f4->add7b1880(new FcPhraseA(224,0,0,0,FcHE(),FcHE()));
       fc_cefc4c->repairPos.set409ff0(-1);
      }else{
       do{
        FcHI tmp=fc_randomRecord9dafb0(res);
        int amount=fc_minInt9cdb30(3,tmp->u457c80()-tmp->u9b6bf0());
        tmp->u458360(amount);
        cx--;
        x2++;
        kind+=amount;
        fc_addUnique9d30e0(edges,tmp);
        if(tmp->u9b6bf0()==tmp->u457c80())fc_removeEntity9d2f00(res,tmp);
       }while(x2<clean&&cx>0&&!res.empty());
       if(fc_cf462c==5){
        fc_d2c658.add4729d0(1090,kind,fc_b964c6,-1);
        fc_d2c658.add4729d0(1092,kind,fc_b964c7,-1);
       }
       fc_sound4541b0(314,0,0);
       if(fc_cefc4c->repairPos!=p->getPosition45a4a0()||fc_cefc4c->repairFlag){
        fc_cefc4c->repairPos.FcPos::FcPos(p->getPosition45a4a0());
        fc_cefc4c->repairFlag=false;
        fc_cefc4c->repairSum=kind;
       }else fc_cefc4c->repairSum+=kind;
       if(res.empty()||cx<=0){
        string text=fc_intToString4051f0(fc_cefc4c->repairSum);
        if(cx<=0)text+=", depleted";
        do{if(fc_showMessage5111e0(764,&string("part"),&text,0,FcHE(),FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
        fc_cefc4c->repairPos.set409ff0(-1);
        u49ada0(fc_caed20+2000);
       }
       for(int i=0;i<edges.size();i++){
        FcPart*part=fc_cec088->find894e70(edges[i]);
        if(part)part->drawStatus4a8e70(0);
       }
      }
     }
     if(cx<=0)w->remove57dbe0(0,0,1,1);
     else w->setCount450460(cx);
     if(x2){
      fc_cefc4c->u774390(17,-1);
      return true;
     }
    }else if(fc_cf4700){
     if(fc_d1e860.u46f4b0(1)){
      if(fc_d25de0[*fc_cf4700]->x24==3)fc_cf45d8.addSuspicion77ee70(fc_ba8544,17,FcHE());
      else fc_cf45d8.addSuspicion77ee70(fc_ba8540,16,FcHE());
     }
     p->u5daf90(23);
     if(fc_contains9db330(fc_d25de0[*fc_cf4700]->x148,13)&&fc_contains9d0ce0(fc_cefc4c->u464060(),p->getPosition45a4a0()))fc_cf45d8.addSuspicion77ee70(fc_ba8530,12,FcHE());
     vector<FcHI>list;
     p->u5d6c30(list);
     if(!list.empty()){
      int sum=0;
      for(int i=0;i<list.size();i++)sum+=list[i]->u5789c0();
      if(sum>p->u45a920())p->u5deb40(fc_maxInt9cdb60(1,sum/3));
     }
    }
    fc_cefc4c->u774390(0,-1);
   }
   return true;
  case 0x81:
   u826920(player);
   return true;
  case 0x82:
   u826e50(player,false,true);
   return true;
  case 0x83:
   if(player.null9b65d0())return true;
   {
    if(fc_cf462c==11){
     if(!fc_cf4700)fc_cec0f4->add7b1880(new FcPhraseA(228,0,0,0,FcHE(),FcHE()));
     else if(!player->u5d9340(0,0))fc_cec0f4->add7b1880(new FcPhraseA(229,0,0,0,FcHE(),FcHE()));
     else if(equipTime&&fc_caed20<equipTime+5000)player->polymindUnpossess5d93d0(0);
     else{
      fc_warn7b1750(230,&fc_d25de0[*fc_cf4700]->x1ac,0,0,FcHE(),FcHE(),0);
      equipTime=fc_caed20;
     }
    }else if(!player->u5cb9b0(1))fc_cec0f4->add7b1880(new FcPhraseA(28,0,0,0,FcHE(),FcHE()));
    else if(equipTime&&fc_caed20<equipTime+5000){
     fc_sound4541b0(185,0,0);
     int equipped=equipAll81a0e0(5);
     if(equipped)do{fc_logPhrase5141b0(105,&fc_intToString4051f0(equipped),0,0,FcHE(),0);}while(0);
     if(fc_cefb3e)fc_cefc4c->u9ebbb0(0);
    }else if(fc_cf473c)fc_cec0f4->add7b1880(new FcPhraseA(24,0,0,0,FcHE(),FcHE()));
    else{
     fc_cec0f4->add7b1880(new FcPhraseA(29,0,0,0,FcHE(),FcHE()));
     equipTime=fc_caed20;
    }
    return true;
   }
  case 0x84:
   if(!fc_cefa94->u41a6e0()&&!fc_d28e04){
    fc_cec0f4->add7b1880(new FcPhraseA(201,0,0,0,FcHE(),FcHE()));
    return true;
   }
   if(fc_d28e04&&!fc_cefa94->u41a6e0()){
    fc_cec034->x78=true;
    fc_cec034->input(&FcEvent(11));
    if(fc_d28e05)fc_d1d9c4=true;
   }
  case 0x85:{
   if(player.null9b65d0())return true;
   if(event->command==0x85&&(u805de0(player,false)||u8062d0()))return true;
   setSelected8278f0(8);
   x698=-1;
   x6ac=-1;
   fc_cec054->u8142d0(18,false);
   if(event->command==0x85&&marked.operator->()){
    u49ac50();
    center8069e0(player->pos45a4c0(),false);
   }
   vector<FcHI>closed;
   vector<int>areas;
   list69c.clear();
   vector<int>choices;
   FcPos edges;
   FcPos ay;
   u8051f0(edges,ay);
   vector<FcHE>distance;
   vector<int>prefix;
   list688.clear();
   vector<int>clean;
   bool kind=false;
   for(int y=edges.y;y<=ay.y;y++){
    for(int x=edges.x;x<=ay.x;x++){
     if(fc_cefc4c->u463380(x,y)){
      if((*fc_cfd44c.at9ceda0(x,y))->getEntity45d250().valid9b7230()&&(*fc_cfd44c.at9ceda0(x,y))->getEntity45d250()!=player&&!player->u45aaa0((*fc_cfd44c.at9ceda0(x,y))->getEntity45d250())&&!fc_containsEntity9d31e0(distance,(*fc_cfd44c.at9ceda0(x,y))->getEntity45d250())){
       distance.push_back((*fc_cfd44c.at9ceda0(x,y))->getEntity45d250());
       if(distance.back()->isHostileTo45aa70(player)&&distance.back()->isXomCandidate5d51a0())kind=true;
      }
      if((*fc_cfd44c.at9ceda0(x,y))->getItem45d8f0().valid9b7230())closed.push_back((*fc_cfd44c.at9ceda0(x,y))->getItem45d8f0());
     }
    }
   }
   if(!closed.empty()){
    for(int i=0;i<closed.size();i++)areas.push_back(-fc_distance40a3f0(player->pos45a4c0(),*closed[i]->u575920()));
    list69c.push_back(closed.front());
    choices.push_back(areas.front());
    for(int i=1;i<closed.size();i++){
     if(areas[i]<=choices.back()){
      list69c.push_back(closed[i]);
      choices.push_back(areas[i]);
     }else{
      for(int j=0;j<choices.size();j++){
       if(areas[i]>choices[j]){
        fc_insert9d8fc0(list69c,j,closed[i]);
        fc_insertAt9dbdc0(choices,j,areas[i]);
        break;
       }
      }
     }
    }
    x6ac=-1;
   }
   if(!distance.empty()&&event->command==0x85&&player->u5d5df0()){
    for(int i=0;i<distance.size();i++){
     if(!player->u5c8820(distance[i]))fc_eraseStep9d6440(distance,i);
    }
    if(fc_d1d9fc.x!=-1){
     if(!player->u5c87f0(fc_d1d9fc)||fc_d1da04.valid9b7230()&&(*fc_cfd44c.atPoint9ced70(fc_d1d9fc))->getProp45d550()!=fc_d1da04){
      fc_d1d9fc.x=-1;
      fc_d1da04.reset9b7270();
     }
    }
    if(fc_d1d9f0.operator->()&&!player->u5c8820(fc_d1d9f0))fc_d1d9f0.reset9b7270();
   }
   if(!distance.empty()){
    if(event->command==0x85&&kind){
     vector<FcHE>backup(distance);
     for(int i=0;i<distance.size();i++){
      if(!distance[i]->isXomCandidate5d51a0())fc_eraseStep9d6440(distance,i);
     }
     if(distance.empty())distance=backup;
    }
    for(int i=0;i<distance.size();i++)prefix.push_back(-fc_distance40a3f0(player->pos45a4c0(),distance[i]->pos45a4c0()));
    list688.push_back(distance.front());
    clean.push_back(prefix.front());
    for(int i=1;i<distance.size();i++){
     if(prefix[i]<=clean.back()){
      list688.push_back(distance[i]);
      clean.push_back(prefix[i]);
     }else{
      for(int j=0;j<clean.size();j++){
       if(prefix[i]>clean[j]){
        fc_insert9d8fc0(list688,j,distance[i]);
        fc_insertAt9dbdc0(clean,j,prefix[i]);
        break;
       }
      }
     }
    }
   }
   if(event->command==0x85){
    x684=1;
    u807e60(1);
    if(fc_d28d34)x1c4=fc_caed20+fc_d28d34;
    if(fc_d1da38)fc_d1da38=false;
    else{
     bool aimed=false;
     if(!fc_d1da10.empty()&&player->u5d6610()){
      if(player->getPosition45a4a0()!=fc_d1da30){
       fc_d1da10.clear();
       fc_d1da30.set409ff0(-1);
      }
      for(int i=0;i<fc_d1da10.size();i++){
       if(!fc_cfd44c.contains9b43b0(fc_d1da10[i])){
        fc_d1da10.clear();
        fc_d1da30.set409ff0(-1);
        break;
       }
      }
      vector<FcHI>weapons;
      player->u5d6a80(weapons,FcPos(1),1);
      if(u805360(player,fc_d1da10,fc_d1da20)>weapons.front()->u4580a0()){
       fc_d1da10.clear();
       fc_d1da30.set409ff0(-1);
      }
      if(!fc_d1da10.empty()){
       for(int i=0;i<fc_d1da10.size();i++){
        FcPos open(i!=0?fc_d1da10[i-1]:player->getPosition45a4a0());
        FcPos to(fc_d1da10[i]);
        if(i!=0&&fc_b96384[fc_cefc4c->u716f20(player,open)]||!fc_cefc4c->u7178d0(player,open,&fc_d2e20c,to,&fc_d2e20c,1)){
         fc_warn7b1750(179,0,0,0,player,FcHE(),0);
         goto aimDone;
        }
       }
       if(fc_b96384[fc_cefc4c->u716f20(player,fc_d1da10.back())])fc_warn7b1750(179,0,0,0,player,FcHE(),0);
       else{
        pos4c8.FcPos::FcPos(fc_d1da20);
        pos4d0.FcPos::FcPos(fc_d1da28);
        if(weapons.front()->u4580c0()&&weapons.front()==fc_d1da44)path50c=fc_d1da10;
        b540=true;
        warpMouse806e70(pos4c8,!fc_d28e4a);
        if(fc_cec078)fc_cec078->load884f60(pos4c8,1);
        aimed=true;
       }
      }
      aimDone:;
     }
     if(!aimed){
      if(fc_d1d9fc.x!=-1&&fc_cefc4c->isVisible4631c0(fc_d1d9fc)&&(fc_d1da04.null9b65d0()||(*fc_cfd44c.atPoint9ced70(fc_d1d9fc))->getProp45d550()==fc_d1da04)){
       warpMouse806e70(fc_d1d9fc,!fc_d28e4a);
       if(fc_cec078)fc_cec078->load884f60(fc_d1d9fc,1);
      }else if(fc_d1d9f0.operator->()&&fc_cefc4c->u4631f0(fc_d1d9f0)&&fc_cefc4c->getPlayer4630f0()->u5c7fc0(fc_d1d9f0)==fc_cefc4c->getPlayer4630f0()->u5c7ff0(fc_d1d9f4)&&(!fc_d1d9f8||!fc_cefc4c->getPlayer4630f0()->u45aaa0(fc_d1d9f0))){
       x698=fc_indexOf9d3110(&list688,fc_d1d9f0);
       if(x698==-1){
        list688.push_back(fc_d1d9f0);
        x698=list688.size()-1;
       }
       FcPos aim=fc_cefc4c->u71b5b0(fc_d1d9f0,0);
       if(aim.x!=-1){
        warpMouse806e70(aim,!fc_d28e4a);
        if(fc_cec078)fc_cec078->load884f60(aim,1);
       }
      }else if(!fc_d28e4a||fc_d28c8a)input(&FcEvent(166));
      else if(fc_cefa94->u41a6e0())warpMouse806e70(player->pos45a4c0(),false);
     }
    }
   }else{
    x684=0;
    if(u8052f0(player->pos45a4c0()))warpMouse806e70(player->pos45a4c0(),false);
    else{
     FcPos center;
     center805020(center);
     warpMouse806e70(center,false);
    }
   }
   return true;}
  case 0x86:
   if(player.valid9b7230())fc_cec118->u8b4500(player,FcHProp(),FcHE(),&FcPos(-1),0,0);
   return true;
  case 0x87:case 0x88:
   if(player.valid9b7230()){
    if(fc_d28c8a&&event->command==0x87)fc_cec094->open8aab40();
    else look820dc0(1,0);
   }
   return true;
  case 0x89:
   if(player.null9b65d0())return true;
   else{
    if(fc_cefc4c->u715920()){
     if(fc_cec034->u987b10(0))fc_cec0c8->beginOrder();
    }else{
     fc_cec0f4->add7b1880(new FcPhraseA(184,0,0,0,FcHE(),FcHE()));
     if(fc_cebd5c==2)fc_cec034->u987b10(fc_cec034->xb0);
    }
   }
   return true;
  case 0x8a:
   buildAllyPaths819a60();
   return true;
  case 0x8b:
   if(player.null9b65d0())return true;
   else{
    if(fc_cec034->u987b10(1))fc_cec0cc->beginSelect();
   }
   return true;
  case 0x8c:case 0x8d:case 0x8e:case 0x8f:
   if(u49b0c0(event->command-0x88)){
    if(fc_cec054->hasAnyLabel()){
     if(!hasActiveLabel(event->command-0x88)){
      fc_cec054->u8142d0(18,false);
      scan813c80(event->command);
      x200=-1;
     }else{
      fc_cec054->u8142d0(18,true);
      if(event->command==0x8e)u49b5b0();
     }
    }
   }else scan813c80(event->command);
   return true;
  case 0x91:case 0x92:
   if(scanTime){
    if(fc_caed20>scanTime+10000)u49b5b0();
    if(fc_caed20<=scanReset+10000){
     if(event->command==0x91){
      if(scanMode==5)scanMode=0;
      else scanMode++;
     }else{
      if(scanMode==0)scanMode=5;
      else scanMode--;
     }
     switch(fc_cefa8c->tool416230()->kind457dd0()){
     case 0x2d:case 0x3d:
      switch(fc_d28d64){
      case 0:fc_cec0c8->reset48f2b0();break;
      case 1:fc_cec0cc->reset48f920();break;
      case 3:fc_cec0c4->reset48e590();break;
      }
      break;
     case 0x10d:case 0x10e:
      fc_cec0b4->reset48e590();
      break;
     }
     scanReset=0;
     fc_cec054->u8142d0(18,false);
     scan813c80(142);
     scanTime=fc_caed20;
    }
   }
   return true;
  case 0x90:
   u8142d0(18,false);
   return true;
  case 0x93:
   if(!fc_d28c8a){
    fc_cec0f4->add7b1880(new FcPhraseA(204,0,0,0,FcHE(),FcHE()));
    return true;
   }
   if(pos78c.x!=-1){
    if(pos78c!=player->getPosition45a4a0()){
     warpMouse806e70(pos78c,true);
     goto aimMode;
    }else fc_cec0f4->add7b1880(new FcPhraseA(203,0,0,0,FcHE(),FcHE()));
   }else fc_cec0f4->add7b1880(new FcPhraseA(202,0,0,0,FcHE(),FcHE()));
   return true;
  case 0x94:
   u827cf0();
   return true;
  case 0x95:{
   string name=fc_d1e864+"_";
   name+=fc_getLocationName4fd600(1);
   int id=fc_d1e860.u789090();
   if(id>=2)name+=fc_intToString4051f0(id);
   name+="_mapturn_";
   name+=fc_intToString4051f0(fc_cefc4c->u4642d0());
   reinterpret_cast<FcShift*>(&fc_d1d9c0)->saveScreenshot873ba0(name);
   return true;}
  case 0x96:{
   string sheet=fc_d2c658.outputScoresheet474a20(1);
   fc_warn7b1750(207,&sheet,0,0,FcHE(),FcHE(),0);
   return true;}
  case 0x97:
   fc_openWorldMap997000();
   return true;
  case 0x99:
   if(player.null9b65d0())return true;
   else{
    FcPos tgt;
    FcPos prev(-1);
    if(pick805190(&tgt)){
     if(player->getPosition45a4a0()!=tgt){
      if(player->item5d2380(192).valid9b7230()&&tgt.adjacent409dd0(player->getPosition45a4a0())&&(player->blocked5c8710(tgt)||player->other5c85a0(tgt,false))){
       int jumpDir=fc_pointsFn4374c0(player->getPosition45a4a0(),tgt);
       input(&FcEvent(jumpDir+100));
      }else if(fc_d28d24&&fc_cefc4c->u4633c0(tgt)&&((*fc_cfd44c.atPoint9ced70(tgt))->u45d0e0()==*TERRAIN_CAVE_WALL||(*fc_cfd44c.atPoint9ced70(tgt))->u45d0e0()==*caveinThirdTerrain||(*fc_cfd44c.atPoint9ced70(tgt))->u45d0e0()==*TERRAIN_EARTH||(*fc_cfd44c.atPoint9ced70(tgt))->u45d0e0()==*fc_cefb84||(*fc_cfd44c.atPoint9ced70(tgt))->isEdge45dc30()&&!fc_cefc4c->u463e90(tgt))){
       if(fc_cf4700&&fc_contains9db330(fc_d25de0[*fc_cf4700]->x148,4)&&(*fc_cfd44c.atPoint9ced70(tgt))->u45d0e0()==*fc_cefb84){
        int digDir=fc_pointsFn4374c0(player->getPosition45a4a0(),tgt);
        input(&FcEvent(digDir+100));
        fc_cf4ce8[2]+=4;
       }else{
        fc_d1da38=true;
        input(&FcEvent(0x85));
       }
      }else if((*fc_cfd44c.atPoint9ced70(tgt))->getProp45d550().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(tgt))->getProp45d550()->idx44ab40()!=-1&&fc_pointsFn4373c0(player->getPosition45a4a0(),tgt)&&(fc_d31640[(*fc_cfd44c.atPoint9ced70(tgt))->getProp45d550()->idx44ab40()].front()->u45cb30()&&player->item5d2380(164).valid9b7230()||(*fc_cfd44c.atPoint9ced70(tgt))->getProp45d550()->u45c630()!=-1&&player->item5d2380(165).valid9b7230()||player->item5d2380(198).valid9b7230())){
       int useDir=fc_pointsFn4374c0(player->getPosition45a4a0(),tgt);
       input(&FcEvent(useDir+100));
       fc_cf4ce8[2]+=4;
      }else if((*fc_cfd44c.atPoint9ced70(tgt))->getProp45d550().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(tgt))->getProp45d550()->u45cb10()&&player->getSize45a360()==1){
       if(fc_pointsFn4373c0(player->getPosition45a4a0(),tgt))fc_cec0f8->open939b50((*fc_cfd44c.atPoint9ced70(tgt))->getProp45d550());
       else if(!fc_d28c8a&&!fc_d28e3d){
        walkPath.clear();
        if(fc_cefc4c->u7168e0(tgt,player->getPosition45a4a0(),player.operator->(),walkPath)){
         prev.FcPos::FcPos(tgt);
         tgt.FcPos::FcPos(walkPath[1]);
         goto travel;
        }
       }
      }else if(fc_cf4780&&(*fc_cfd44c.atPoint9ced70(tgt))->getEntity45d250().valid9b7230()&&fc_pointsFn4373c0(player->getPosition45a4a0(),tgt)){
       action824020(player,fc_pointsFn4374c0(player->getPosition45a4a0(),tgt));
       return true;
      }else if((*fc_cfd44c.atPoint9ced70(tgt))->getEntity45d250().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(tgt))->getEntity45d250()->target45a760()&&fc_pointsFn4373c0(player->getPosition45a4a0(),tgt)){
       interact825a60(player,tgt,false);
       return true;
      }else if((*fc_cfd44c.atPoint9ced70(tgt))->getEntity45d250().valid9b7230()&&fc_cefc4c->isVisible4631c0(tgt)&&!player->u45aaa0((*fc_cfd44c.atPoint9ced70(tgt))->getEntity45d250())&&!fc_cf45d8.u77f260(100)){
       if(!fc_cefa94->u41a6e0()&&(*fc_cfd44c.atPoint9ced70(tgt))->getEntity45d250()!=fc_d1da3c)fc_d1da40=fc_caed20;
       if(fc_cf462c==11&&fc_pointsFn4373c0(player->getPosition45a4a0(),tgt)&&(!fc_cf4700||fc_cf4780&&fc_contains9db330(fc_d25de0[*fc_cf4700]->x148,9))){
        int attackDir=fc_pointsFn4374c0(player->getPosition45a4a0(),tgt);
        input(&FcEvent(attackDir+100));
        fc_cf4ce8[2]+=4;
       }else{
        fc_d1da38=true;
        input(&FcEvent(0x85));
       }
      }else if(!fc_d28c8a&&!fc_d28e3d){
       if(fc_cefc4c->u4636d0()&&!fc_d28d28||fc_cefc4c->u463710()&&fc_d28d28||player->item5d2380(193).valid9b7230()||player->item5d2380(216).valid9b7230()){
        int stepDir=fc_pointsFn4374c0(player->getPosition45a4a0(),tgt);
        input(&FcEvent(stepDir+100));
        fc_cf4ce8[2]+=4;
       }else{
        travel:
        walkPath.clear();
        if(fc_cefc4c->u7168e0(player->getPosition45a4a0(),tgt,player.operator->(),walkPath)){
         fc_eraseAt9d5190(walkPath,0);
         if(prev.x!=-1)walkPath.push_back(prev);
         walkStart=fc_caed20;
         walkTime=fc_caed20;
         skipRefresh=true;
         pos784.FcPos::FcPos(player->getPosition45a4a0());
         pos78c.FcPos::FcPos(tgt);
        }else if(fc_cf4700&&fc_contains9db330(fc_d25de0[*fc_cf4700]->x148,1)&&(*fc_cfd44c.atPoint9ced70(tgt))->getProp45d550().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(tgt))->getProp45d550()->idx44ab40()!=-1&&fc_d1e860.u46f4b0(1)&&fc_cefc4c->u74d200((*fc_cfd44c.atPoint9ced70(tgt))->getProp45d550()->idx44ab40())){
         do{if(fc_showMessage5111e0(778,&(*fc_cfd44c.atPoint9ced70(tgt))->getProp45d550()->name45c5b0(),0,0,player,FcHE(),0,0))fc_cec058->bubble8758d0(true);fc_cec0b4->scrollToEnd7b4f10();}while(0);
         if(fc_d1e860.u46f4b0(1))fc_cf45d8.addSuspicion77ee70(fc_ba8504,1,FcHE());
        }
       }
      }
     }else{
      if((*fc_cfd44c.atPoint9ced70(tgt))->isDoor45dda0())input(&FcEvent(126));
      else if((*fc_cfd44c.atPoint9ced70(tgt))->isMachinePart45dcd0())input(&FcEvent(126));
      else if((*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0().valid9b7230()&&!player->u45a810())u826e50(player,true,false);
      else u826920(player);
     }
    }
   }
   return true;
  case 0x9b:
   fc_d1d9e4=true;
   return true;
  case 0x9a:{
   if(player.null9b65d0()||fc_d28c8a)return true;
   FcPos tgt;
   if(pick805190(&tgt)&&player->getPosition45a4a0()==tgt)u826e50(player,false,false);
   else{
    fc_d1da38=true;
    input(&FcEvent(0x85));
   }
   return true;}
  case 0x9c:{
   if(player.null9b65d0()||fc_d28c8a)return true;
   if(fc_d1d9e5){
    fc_d1d9e5=false;
    return true;
   }
   if(!fc_d1d9e4)return true;
   FcPos tgt;
   if(pick805190(&tgt)){
    if(fc_d28e49&&player->getPosition45a4a0()!=tgt&&fc_cefc4c->u4633c0(tgt)&&((*fc_cfd44c.atPoint9ced70(tgt))->u45d0e0()==*TERRAIN_CAVE_WALL||(*fc_cfd44c.atPoint9ced70(tgt))->u45d0e0()==*caveinThirdTerrain||(*fc_cfd44c.atPoint9ced70(tgt))->u45d0e0()==*TERRAIN_EARTH||(*fc_cfd44c.atPoint9ced70(tgt))->u45d0e0()==*fc_cefb84||(*fc_cfd44c.atPoint9ced70(tgt))->isEdge45dc30()&&!fc_cefc4c->u463e90(tgt))){
     fc_d1da38=true;
     input(&FcEvent(0x85));
     return true;
    }
    if(player->getPosition45a4a0()==tgt&&fc_cefc4c->u4633c0(tgt)&&(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0().valid9b7230()&&((*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->type457880()==5&&fc_cf4830[(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->u457820()]||(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->kind457f90()==167&&(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->u457d70()&&fc_cf4830[(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->u457820()]||!(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->u4578a0()&&player->item5d2380(197).valid9b7230()||(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->kind457f90()==203&&fc_cf4830[(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->u457820()]||(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->kind457f90()==204&&fc_cf4830[(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->u457820()]||(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->kind457f90()==205&&fc_cf4830[(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->u457820()]||(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->kind457f90()==206&&fc_cf4830[(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->u457820()]||(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->kind457f90()==140||(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->kind457f90()==208||(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->effect457b70(86)||(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->kind457f90()==209||(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->kind457f90()==124||(*fc_cfd44c.atPoint9ced70(tgt))->getItem45d8f0()->def9b4350()==fc_cefbec)){
     input(&FcEvent(126));
     return true;
    }
    if(!fc_cefc4c->isVisible4631c0(tgt)){
     path730.clear();
     times740.clear();
     FcPos center;
     center805020(center);
     fc_line40ff30(center,tgt,path730);
     int open=5;
     int ay=fc_caed20+5;
     for(int i=0;i<path730.size();i++,ay+=5)times740.push_back(ay);
     return true;
    }
   }
   look820dc0(0,0);
   return true;}
  case 0x9d:
   if(player.null9b65d0()||fc_d28c8a)return true;
   else{
    FcPos tgt;
    if(pick805190(&tgt)&&player->getPosition45a4a0()!=tgt){
     int lookDir=fc_pointsFn4374c0(player->getPosition45a4a0(),tgt);
     input(&FcEvent(lookDir+116));
    }
   }
   return true;
  case 0x9e:
   if(fc_d28c8a)return true;
   u8212e0();
   return true;
  case 0x9f:
   if(fc_d28c8a)return true;
   look820dc0(0,1);
   return true;
  default:return false;
  }
 case 8:
  switch(event->command){
  case 0xa0:
   if(fc_d28c8a)return true;
   switch(x684){
   case 1:{
    FcPos tgt;
    bool id=true;
    if(player->u5d6610()&&pick805190(&tgt)&&(!fc_cefc4c->isVisible4631c0(tgt)||(*fc_cfd44c.atPoint9ced70(tgt))->isPassableFor66ab30(player)&&(*fc_cfd44c.atPoint9ced70(tgt))->getEntity45d250().null9b65d0()&&!(*fc_cfd44c.atPoint9ced70(tgt))->u45dbf0())&&!pickTarget827170(player))id=false;
    if(id)fire821450(player);
    break;}
    break;
   case 2:
    allyOrder:
    if(pos6fc.x!=-1&&(fc_b96600[fc_cec0c8->u48f100()]!=2||fc_cefc4c->isVisible4631c0(pos6fc)))fc_cec0c8->u7b8340(pos6fc);
    break;
   case 3:{
    FcPos tgt;
    if(pick805190(&tgt))fc_cec0a0->openForPos8abac0(tgt,0);
    break;}
   }
   return true;
  case 0xa1:
   if(fc_d28c8a)return true;
   if(x684==1)goto drop;
   else if(x684==3)goto fireAt;
   else if(!look820dc0(0,0)&&x684==2){
    fc_cec0c8->endOrder7b8290();
    goto drop;
   }
   return true;
  case 0xa2:
   if(fc_d28c8a)return true;
   look820dc0(0,1);
   return true;
  case 0xa3:
   if(x684==0||x684==3)u8142d0(18,false);
   drop:
   if(x684!=1||!dropOnTarget8275d0(player)){
    u827950();
    fc_sound4541b0(42,0,0);
    if(fc_d28e06){
     u49ac70();
     input(&FcEvent(47));
    }
   }
   return true;
  case 0xa4:
   if(fc_d28c8a)warpMouse806e70(player->getPosition45a4a0(),false);
   return true;
  case 0xa5:
   if(fc_d28c8a&&u806f30(1))u827950();
   return true;
  case 0xa6:case 0xa7:
   if(x684==3){
    if(!fc_cefc4c->u463f60()->empty()){
     if(x698==-1||x698>=fc_cefc4c->u463f60()->size())x698=0;
     else if(event->command==0xa6){
      x698++;
      if(x698==fc_cefc4c->u463f60()->size())x698=0;
     }else{
      if(x698==0)x698=fc_cefc4c->u463f60()->size()-1;
      else x698--;
     }
     if(!fc_between9daf80(0,x698,fc_cefc4c->u463f60()->size()-1))fc_logError404f10("CMap::input()","map comment lastTarget out of bounds?");
     else{
      FcPos mark(*(*fc_cefc4c->u463f60())[x698]);
      center8069e0(mark,true);
      warpMouse806e70(mark,true);
      x718=-1;
     }
    }
    return true;
   }
   for(int i=0;i<list688.size();i++){
    if(!list688[i].operator->())fc_eraseStep9d6440(list688,i);
   }
   if(list688.empty()){
    fc_cec0f4->add7b1880(new FcPhraseA(x684==1&&player->u5d5df0()?108:107,0,0,0,FcHE(),FcHE()));
    if(fc_d28c8a)warpMouse806e70(player->getPosition45a4a0(),false);
   }else{
    if(x698==-1||x698>=list688.size())x698=0;
    else if(event->command==0xa6){
     x698++;
     if(x698==list688.size())x698=0;
    }else{
     if(x698==0)x698=list688.size()-1;
     else x698--;
    }
    FcPos aim=fc_cefc4c->u71b5b0(list688[x698],0);
    if(aim.x!=-1){
     warpMouse806e70(aim,true);
     x718=-1;
     if(fc_cec078)fc_cec078->load884f60(aim,1);
     if(x684==0&&fc_d28d3b&&!xec){
      u8142d0(18,false);
      label810270(0,list688[x698],0,0);
     }
    }
   }
   return true;
  case 0xa8:case 0xa9:
   if(x684==2||x684==3)return false;
   for(int i=0;i<list69c.size();i++){
    if(!list69c[i].operator->()||!fc_cefc4c->isVisible4631c0(*list69c[i]->u575920()))fc_eraseStep9d6440(list69c,i);
   }
   if(list69c.empty()){
    fc_cec0f4->add7b1880(new FcPhraseA(109,0,0,0,FcHE(),FcHE()));
    if(fc_d28c8a)warpMouse806e70(player->getPosition45a4a0(),false);
   }else{
    if(x6ac==-1||x6ac>=list69c.size())x6ac=0;
    else if(event->command==0xa8){
     x6ac++;
     if(x6ac==list69c.size())x6ac=0;
    }else{
     if(x6ac==0)x6ac=list69c.size()-1;
     else x6ac--;
    }
    warpMouse806e70(*list69c[x6ac]->u575920(),true);
    x718=-1;
    if(fc_cec078)fc_cec078->load884f60(*list69c[x6ac]->u575920(),1);
    if(x684==0&&fc_d28d3b){
     u8142d0(18,false);
     items8119c0(list69c[x6ac],0,0,0);
    }
   }
   return true;
  case 0xaa:
   look820dc0(0,0);
   return true;
  case 0xab:
   switch(x684){
   break;
   case 0:u8212e0();break;
   case 2:goto allyOrder;
   }
   return true;
  case 0xac:
   switch(x684){
   case 1:pickTarget827170(player);break;break;
   case 2:goto allyOrder;
   }
   return true;
  case 0xad:
   switch(x684){
   case 1:fire821450(player);break;
   case 0:x684=1;u807e60(1);break;
   }
   return true;
  case 0xae:facing=0;goto step;
  case 0xaf:facing=1;goto step;
  case 0xb0:facing=2;goto step;
  case 0xb1:facing=3;goto step;
  case 0xb2:facing=4;goto step;
  case 0xb3:facing=5;goto step;
  case 0xb4:facing=6;goto step;
  case 0xb5:facing=7;
   step:
   if(fc_d338cc.isDown439510(fc_d28fc0))goto multi;
   else u827850(facing);
   return true;
  case 0xb6:facing=0;goto multi;
  case 0xb7:facing=1;goto multi;
  case 0xb8:facing=2;goto multi;
  case 0xb9:facing=3;goto multi;
  case 0xba:facing=4;goto multi;
  case 0xbb:facing=5;goto multi;
  case 0xbc:facing=6;goto multi;
  case 0xbd:facing=7;
   multi:
   for(int i=0;i<fc_d28e6c;i++)u827850(facing);
   return true;
  case 0xbe:{
   if(!fc_d28c8a){
    fc_cec0f4->add7b1880(new FcPhraseA(204,0,0,0,FcHE(),FcHE()));
    return true;
   }
   aimMode:
   FcPos tgt;
   FcPos prev(-1);
   if(pick805190(&tgt)&&player->getPosition45a4a0()!=tgt){
    if(event->command==0xbe)input(&FcEvent(163));
    if((*fc_cfd44c.atPoint9ced70(tgt))->getProp45d550().valid9b7230()&&(*fc_cfd44c.atPoint9ced70(tgt))->getProp45d550()->u45cb10()){
     if(fc_pointsFn4373c0(player->getPosition45a4a0(),tgt))fc_cec0f8->open939b50((*fc_cfd44c.atPoint9ced70(tgt))->getProp45d550());
     else{
      walkPath.clear();
      if(fc_cefc4c->u7168e0(tgt,player->getPosition45a4a0(),player.operator->(),walkPath)){
       prev.FcPos::FcPos(tgt);
       tgt.FcPos::FcPos(walkPath[1]);
       goto travel2;
      }
     }
    }else if(fc_cefc4c->u4636d0()&&!fc_d28d28||fc_cefc4c->u463710()&&fc_d28d28||player->item5d2380(193).valid9b7230()||player->item5d2380(216).valid9b7230()){
     if(walkPath.empty()||walkPath.back()!=tgt){
      pos78c.FcPos::FcPos(tgt);
      if(fc_cefc4c->u7168e0(player->getPosition45a4a0(),tgt,player.operator->(),walkPath))fc_eraseAt9d5190(walkPath,0);
      else return true;
     }
     int stepDir=fc_pointsFn4374c0(player->getPosition45a4a0(),walkPath[0]);
     input(&FcEvent(stepDir+100));
    }else{
     travel2:
     walkPath.clear();
     if(fc_cefc4c->u7168e0(player->getPosition45a4a0(),tgt,player.operator->(),walkPath)){
      fc_eraseAt9d5190(walkPath,0);
      if(prev.x!=-1)walkPath.push_back(prev);
      walkStart=fc_caed20;
      walkTime=fc_caed20;
      skipRefresh=true;
      pos784.FcPos::FcPos(player->getPosition45a4a0());
      pos78c.FcPos::FcPos(tgt);
     }
    }
   }
   return true;}
  case 0xbf:
   if(x684!=3)u827cf0();
   else u827950();
   return true;
  case 0xc0:{
   if(x684!=3)u827cf0();
   FcPos tgt;
   if(pick805190(&tgt))fc_cec0a0->openForPos8abac0(tgt,1);
   return true;}
  case 0xc1:{
   fireAt:
   FcPos tgt;
   if(pick805190(&tgt))fc_cefc4c->u72a1e0(tgt,0);
   return true;}
   return false;
  }
 }
 return false;
}
FcPosN::FcPosN(int a,int b){x=a;y=b;}
