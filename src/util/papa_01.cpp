// Entity::turnUpdate (0x610430, 137 KB) on private placeholder types (papa; started by alex-november).
// NOTE: placeholder names/layouts throughout: Nv*/nv_* are private, callees carry their exe address in the name.
// Lives in src/util/ (sorts last in the link) because it declares many private throw() aliases and nothrow helpers
// (NvXGroup/NvRegion/NvEffPair ctors, defined here so LTCG proves the `new` sites nothrow) that must not change
// nothrow inference for other files. Local names come from a bucket solver (scratch/papa/lay.sh), hence the odd names.
#include <string>
using namespace std;
struct NvPos{NvPos add409b60(const NvPos&);bool eq409cb0(int,int);int x,y;NvPos();NvPos(int,int);NvPos(int)throw();bool contains40c190(int);NvPos&operator=(const NvPos&);bool ne409bd0(const NvPos&)const;};
struct NvVecPt;struct NvExplDef;struct NvEffList;struct NvEffX;struct NvVecHE6;struct NvTimerInfo;struct NvEntity;struct NvItem;struct NvPoint;struct NvHE;struct NvRec;struct NvRecI;struct NvEffPair;struct NvVecHE3;struct NvHG;
struct NvRecI;typedef NvRecI NvItemDef;struct NvW7c{char pad[4];bool u9b81b0();};
struct NvItem{int u45a3a0();void u578090();int u457af0();bool hasName4579d0();void u458700(const string&);int u457f10();bool takeDamage57ab10(int,int,int,int,NvHE,int,int);int u457ef0();bool u457ad0();void setBroken5795b0(int,int);int u578f20(NvVecPt&,int*);int u457920();bool u457d50();bool u457ff0();int u457fb0t()throw();int nested4578c0t()throw();void u57bff0(int,int);int u577fb0();void u57a5d0(int,int);int u9b6bf0t()throw();int u457cd0();int u457ca0();void u4585c0(int);bool u458220();bool u4584c0();void u458630(NvEffPair*);void u458580();int nested457900();int getWidth9fcd80();bool u415ee0();bool u577530();void u458390(int);int u577600(int);int u457a30();int u577a90();void setActive5791a0(bool);void u458310(int);void u44fc60(int);NvHE u457b50();void u4582f0();NvEffPair*getEffect457b70(int);int getEffectValue457be0(int);const string&u457860();void addEffect4585a0(NvEffPair*);int u457fd0();int u577bd0();int u457e10();float u457df0();int u457c80();bool u457d10();void u458340();void u5797c0();void set450460(int);void u57a0f0(const NvPos&,int,int);int nested4578c0();NvPos&u575920();void u57a190(NvHE,int,int,int);bool u457e90();void remove57dbe0(bool,int,int,int);void u458360(int);string getName571db0(int,int);bool u457cf0();int u9b6bf0();int u577790();int u457fb0();int getType44aec0();int nested457820();int nested4578a0();int nested457880();NvItemDef*def9b4350();int u457f90();bool u457d70();int u45cb30();};
struct NvHI{int id;NvHI();bool eq9b78e0t(NvHI)const throw();void reset9b7270();bool operator==(NvHI)const;NvItem*get9b65b0t()const throw();bool operator!=(NvHI)const;bool isNull9b65d0()const throw();NvItem*operator->()const;bool isValid9b7230()const;};
struct NvEntity;struct NvHE{int id;NvHE()throw();bool isNull9b65d0()const throw();bool isValid9b7230()const throw();bool operator!=(NvHE)const;bool operator==(NvHE)const;NvEntity*operator->()const throw();};
struct NvHP;struct NvHRec{int id;NvHRec();};struct NvCellInfo{char pad[0x5c];int f5c;};struct NvCell{int u45a6e0();void u66d470(NvHE,int,int,int);bool u45dbf0();NvCellInfo*u9fcd80();void u670b60(int);bool u45d940();bool u45de70();bool u45da30();bool u45dcf0();void removeProp66c100(int,int);void u66ce10(int,int,int,int);bool u45d230();int u44aec0();void u45de40();bool u45da50();void u66b740(NvCell*);bool u45ddf0();bool isEdge45dc30();bool isShortcut45dc50();bool u66b120();void*getEffect45d350(int);void u45dfb0(int);void u66a050(int,int,int);bool canPlaceEntity66ad20(int);bool hasBlockingObject45d7b0();NvHI getItem45d8f0();bool getField4550b0();bool u45db70();void trigger45e110(int,int,NvHE);NvHE getEntity45d250();NvHP getProp45d550();};
struct NvVHI{char pad[16];unsigned size9b9260()const;NvHI&at9b81f0(unsigned);};
struct NvVPos{char pad[16];unsigned size9b9a50()const throw();NvPos&at9e7c10(unsigned)throw();NvPos&front9b7060();};
struct NvVecI{char pad[16];NvVecI(unsigned,unsigned);NvVecI(unsigned,const int&);~NvVecI();int&at9b81f0(unsigned)throw();int&back9b6540()throw();};
struct NvGVec{char pad[16];unsigned size9b9260()const throw();void clear9bac80();void push_back9b9d30(const int&);void push_back9b9280(int&&);int&at9b81f0(unsigned)throw();int&back9b6540()throw();};
extern NvGVec nv_cf4bf0,nv_cf4c00,nv_cf4c10,nv_cf4c28;extern int nv_cf4c24,nv_cf4c20;
struct NvStats{NvGVec*vals;int get472c70(int);bool add4729d0(unsigned,int,string,int);};extern NvStats nv_d2c658;
struct NvPlayerData{bool u46dd90();bool u780380(int,int);bool u77ffb0(int,int);void u780810(NvHE,int,int);void unlock77fbc0(int);bool isSlotEmpty46de40(int);};extern NvPlayerData nv_cf45d8;
struct NvGameData{const string&getEntryText46f6d0(const string&);void setEntryText46f700(const string&,const string&);bool u46f4b0(int);};extern NvGameData nv_d1e860;
struct NvLoc{int f0;int f4;int f8;int u46ed20();};struct NvHLoc{int id;NvLoc*operator->()const;};extern NvHLoc nv_d1e888;
struct NvVecPt;struct NvIntGrid2;struct NvS34Grid;struct NvVVMarker;struct NvVMk;struct NvMk;
struct NvVGrp;struct NvMap{void u71f700(const NvPos&,int);NvHE u715c70();bool u463750();int u463690();void u72e4c0(NvHE,int);void u721600();void u724480();void u724a10();void u724cf0();void u724f00();int u717dd0();int u464020();int u463710();void u465380();NvHE getEntity463110t()throw();int getTurn464270t()throw();float u7163d0(int,int);void u71cf70();bool u4633c0(const NvPos&);bool isVisible463190(int,int);bool u72a900(int,const NvPos&,const NvPos&);NvVecPt*u463ad0();NvGVec*u463af0();void u7471d0(NvHE);void u747400b(NvHE,NvHI,int,int);const NvPos&u4184d0();NvPos u71d000(int);NvHE u6c5dc0(const string&,const NvPos&,int,int,int,int,int);void u6c65a0(NvHE,const string&,int);NvVGrp*u463950();NvHE placeEntity6c58c0b(int,const NvPos&,int,int,int,int,int);bool u74d420(const NvPos&,NvPos&);bool u71bc10(const NvPos&,NvPoint*);void opw3_7243c0(int,int,int);void u744800(int);char pad0[0x720];int f720;NvIntGrid2*u463830();NvS34Grid*u463e70();bool u463e90(const NvPos&);bool isKnown463130(int,int);NvVVMarker*u463ec0();NvVMk*u462e10();bool u463ee0(int,const NvPos&);void opw3_724420(int,int);void u9e29b0(int*,NvHP);void u734d60(const NvPoint&);void u4647a0(const NvPoint&,int);NvMk*getZone462e30(const NvPoint&);void announceMachine71dd30(int);bool u729de0();NvVecHE3*u4636b0();bool u463400(NvHE);NvHG u463890(int);int u71ac50(NvHE);int u714b50();int u463d40();NvHE placeEntity6c58c0(NvRec*,const NvPos&,int,int,int,int,int);bool u4631f0(NvHE);NvHI u6c5400(NvRecI*,const NvPos&);NvHI u71e7c0(const NvPos&,int,int);bool u463380(int,int);bool findPlaceableNear71c150(NvPos&,NvPos&,int);void u734560(NvHE,int,int);bool isReachable465230(int,const NvPos&,const NvPos&);NvHRec addRecord777a20(NvHRec);void zap7273e0(const NvPoint&,NvHE);void u464750(int);bool isVisible4631c0(const NvPos&);NvHE getEntity463110();NvHI u6c51d0(NvRecI*,NvHE,int,int);bool u72a290(NvPos,int,int);NvHE getPlayer4630f0();void u747400(NvHE,NvHE,int,int);bool u72a4d0(int,NvPos,int,int);int getTurn464270();int u4642d0();};extern NvMap*nv_cefc4c;
int nv_threshold433260(int);int nv_sum9cdbd0(NvVecI&)throw();int nv_minInt9cdb30(int,int)throw();
struct NvVEntRec;struct NvCf6428{int v;NvVEntRec*u45ee50();};extern NvCf6428 nv_cf6428;extern int nv_cf645c;extern unsigned char nv_cf6468;
extern bool nv_d28d16;extern int nv_cf462c;struct NvLocP{int idx;};extern NvLocP*nv_cf4700;
struct NvRec2{int f0;int f4;};struct NvVRec2{char pad[16];NvRec2*&front9b7060()throw();NvRec2*&at9b81f0(unsigned)throw();};struct NvVVRec{char pad[16];unsigned size9b5100()const throw();NvVRec2&at9b8070(unsigned)throw();};
struct NvRec{char pad0[0x28];int f28;char pad2c[0x44-0x2c];int f44;char pad48[0x54-0x48];int f54;char pad58[0x68-0x58];int f68;char pad6c[0x9c-0x6c];int f9c;char pada0[0x13a-0xa0];bool b13a;bool b13b;char pad13c[0x160-0x13c];NvVVRec v160;};struct NvVRec{char pad[16];unsigned size9b9260()const throw();NvRec*&at9b81f0(unsigned)throw();};extern NvVRec nv_d25de0;
struct NvTriple{void add46cd30(int,int,int);string getName7787b0(int);};extern NvTriple nv_cf4784;
struct NvVTriple{char pad[16];NvTriple&back9b8ae0()throw();};extern NvVTriple nv_d1e89c;
extern int nv_cf47b4,nv_cf47b8,nv_cf47bc;extern NvGVec nv_cf4770,nv_cf47a4,nv_cf46e4;
void nv_logPhrase5141b0(int,const string&,int,int,NvHE,int);bool nv_between9daf80(int,int,int);int nv_maxInt9cdb60(int,int)throw();
struct NvCec07c{char pad0[0xac];int fac;};extern NvCec07c*nv_cec07c;
extern const char nv_be64d8[];void nv_fn510360(string&);struct NvMsgLog{void set451400(int);};extern NvMsgLog nv_cf1080;void nv_sound4541b0(int,int,int);
bool nv_show5111e0(int,const string*,const string*,const string*,NvHE,NvHE,int,int);
struct NvBubble{void bubble8758d0(bool);};extern NvBubble*nv_cec058;struct NvLogMsgs{void scrollToEnd7b4f10();};extern NvLogMsgs*nv_cec0b4;
struct NvVecE{char pad[16];bool empty9b86e0()const;};extern NvVecE nv_cf4a14;
struct NvVecU{char pad[16];NvVecU();~NvVecU();bool empty9b86e0()const throw();unsigned size9b9260()const throw();int&at9b81f0(unsigned)throw();void push_back9b9d30(const int&);void push_back9b9280(int&&);};bool nv_containsRecord9db330(NvVecU*,int);void nv_fn9d51d0(NvVecU&,int);extern float nv_cf46f8;
struct NvEntDef{char pad0[0x28];int f28;char pad2c[0x110-0x2c];int f110;};

struct NvEntDef2{char pad0[0x48];int f48;char pad4c[0x15c-0x4c];bool b15c;char pad15d[3];NvVVRec v160;};
struct NvRect{int x1,y1,x2,y2;NvRect();void randomPoint40be30(NvPos*);bool contains40b750(const NvPos&);};
struct NvCell;struct NvGrid{int getWidth9fcd80();int getHeight9b8f00();NvCell**atPoint9ced70(const NvPos&)throw();NvCell**at9ceda0(int,int)throw();void getRect9b4430(const NvPos&,int,NvRect&);};extern NvGrid nv_cfd44c;
#define CELL(x,y) (*nv_cfd44c.at9ceda0(x,y))
struct NvRng{float rangeFloat406e20(float,float);bool chance406c90(int);int rangeInt406d70(float,float);};extern NvRng rng;struct NvRange{int random40c130();};extern NvRange nv_d2b4ec,nv_d1dafc;
int nv_distance406480(NvPos,int,int);int nv_distance406480b(int,int,int,int);
extern int nv_cf46a4,nv_cf46a8,nv_cf46ac,nv_caf130;
struct NvVecI2{char pad[16];bool empty9b86e0()const throw();int&front9b7060()throw();unsigned size9b9260()const throw();int&at9b81f0(unsigned)throw();int&back9b6540()throw();void push_back9b9d30(const int&);void push_back9b9280(int&&);};
extern NvVecI2 nv_d1ec84,nv_d1ec94;void nv_removeAt9de6f0(NvVecI2&,int);
struct NvReq{int f0;unsigned f4;int f8;int fc;};struct NvVReq{char pad[16];bool empty9b86e0()const throw();unsigned size9b9260()const throw();NvReq*&at9b81f0(unsigned)throw();};
struct NvRecI{int f0;char pad4[4];string s8;string name24;int f40;int f44;int f48;int f4c;int f50;int f54;char pad58[0x70-0x58];int f70;char pad74[0x7c-0x74];NvW7c v7c;char pad80[0x94-0x80];int f94;char pad98[0xec-0x98];int fec;int ff0;char padf4[0x190-0xf4];int f190;char pad194[0x1a8-0x194];NvExplDef*x1a8;bool b1ac;char pad1ad[0x1af-0x1ad];bool b1af;char pad1b0[0x1b4-0x1b0];string s1b4;char pad1d0[0x20a-0x1d0];bool b20a;char pad20b[0x220-0x20b];int f220;char pad224[0x24c-0x224];bool b24c;char pad24d[0x250-0x24d];NvVecU v250;NvVReq v260;bool b270;bool b271;bool getFlag4570c0(int);int getValue457330(int);int u457410();NvRec*getRecord56f3c0();};
struct NvVRecP{char pad[16];unsigned size9b9260()const throw();NvRecI*&at9b81f0(unsigned)throw();};extern NvVRecP nv_d2d1c4;
bool nv_show5111e0b(int,const string&,const string*,const string*,NvHE,NvHE,int,int);
struct NvEffPair{void*type;int value;NvEffPair(void*,int);};
NvEffPair::NvEffPair(void*type_,int value_){type=type_;value=value_;}
struct NvPoint:NvPos{NvPoint();NvPoint&operator=(const NvPoint&)throw();bool test409b90(const NvPos&);NvPoint(int,int);NvPoint(const NvPos&);NvPoint(const NvPoint&)throw();};
struct NvVPt{char pad[16];unsigned size9b9a50()const throw();NvPos&at9e7c10(unsigned)throw();};
struct NvVoidVec{char pad[16];void*&at9b81f0(unsigned)throw();};extern NvVoidVec nv_d2f0f8;
struct NvTQ{void u672b80(NvHE,int);};extern NvTQ nv_d225a0;
bool nv_lookup9d7980(const string&,int*);
struct NvFx{void init503b20(int,const NvPos&,const NvPos*,int,int,int,int,int);};struct NvFxPool{NvFx*new508610(NvFxPool*);};extern NvFxPool*nv_cefc50;extern NvPos nv_d2e20c;
struct NvPropDef{char pad0[0x8c];int f8c;char pad90[0xf8-0x90];int ff8;char padfc[0x140-0xfc];int f140;char pad144[0x154-0x144];NvRecI*f154;};
struct NvHackInfo{char pad[0xc];NvHE hc;int f10;int f14;bool u65cf50(int);};struct NvTerm{char pad[8];bool b8;};struct NvMach{char pad[0x50];NvGVec v50;char pad60[0x7c-0x60];int f7c;NvTerm*u45c1c0(int);};struct NvProp{NvMach*u45cb30();int u457b10();int u44ab40();NvHackInfo*u44b020();bool u45cbd0();const NvPoint&u4184d0();void u65f170();NvPropDef*def9b8f00()throw();bool isTrap45cb70();const string&getName45c5b0();void u45ce10(int,int,int,NvHE);};
struct NvHP{int id;NvHP();bool isNull9b65d0()const throw();bool isValid9b7230()const throw();NvProp*operator->()const throw();};
bool nv_show5111e0c(int,const string*,const string*,const string*,NvHE,NvHE,const NvPoint&,int);
extern NvRange nv_d2a4f4,nv_d1f38c;
void nv_dummy(int);
extern const char nv_be65f8[];void nv_logPhrase5141b0b(int,const string*,int,int,NvHE,int);
struct NvVecHE3{char pad[16];bool empty9b86e0()const throw();unsigned size9b9260()const throw();NvHE&at9b81f0(unsigned)throw();};void nv_eraseAt9da940(NvVecHE3&,int);
extern NvGVec nv_cf4a04;extern int nv_b989c8[],nv_b989bc[];extern bool nv_b95758[];string nv_intToString4051f0(int);
struct NvVecXG{char pad[16];NvVecXG()throw();};struct NvXGroup{int f0;int f4;NvVecXG v8;NvHE h18;NvXGroup(int);};NvXGroup::NvXGroup(int a):f0(a),f4(-1){}
struct NvVPos2{char pad[16];void push_back9b3020(NvPos&&);};struct NvAIEnt{int f0;int f4;NvVPos2 v8;};
struct NvAIL{NvAIEnt*u57f140(NvXGroup*);};struct NvAI2{NvAIL*u4590f0();};
bool nv_isAtLeast456bf0(float,float);int nv_round406360(float);struct NvXom{bool u69edf0();void u69ee30(int,int,int);bool u69eba0(NvHI);bool b0;void u69e700(int,int,float);};extern NvXom nv_d25450;
bool nv_strEq9ccb50(const string&,const char*);extern const char nv_be65e0[];
extern int nv_cf49f4,nv_cf49f8;extern bool nv_d28d09;extern NvGVec nv_d22590;extern const double nv_c36dc0;
struct NvMapView{NvTimerInfo*u49b050();void u49abf0();void showTimer8176a0(int,const NvPos&,int,int);void u44e360(NvHI);const NvPos&u458ef0();bool inBounds4173d0(const NvPos&);void u8195a0(const NvPos&,int,int);void label813050(int,NvHP,int,int,int);void labelAccess80e3a0(int,const NvPoint&);void addMemoryLabel812950(const NvPoint&,int);void u8195e0(NvHI);void u49ad30();void u49adc0(int);};extern NvMapView*nv_cec054;
struct NvWL{char pad[0x24];NvWL();~NvWL();bool u9b81b0();int total9b81d0();void remove9bab80(int);void add9ba310(int,int);int&pick9ba470();};
struct NvRegion;struct NvAI{int u9b8f00();NvHI u4592c0t()throw();NvHI u4592c0();NvRegion**u459070();void setFollowEntity5b2f80(NvHE,int);NvAIL*u4590f0();bool u458eb0();int u458f30();};
struct NvVecHE5;struct NvGroup{NvVecHE5*u416f40();int type9b4350()throw();};struct NvHG{int id;NvHG();NvGroup*operator->()const throw();};
struct NvVecRP{char pad[16];NvVecRP();~NvVecRP();void push_back9b9d30(NvRec*const&);};
NvRecI*nv_randomRec9d5d00(NvVRecP*);NvRec*nv_randomRec9d5d00b(NvVecRP*);
extern const float nv_c36e30,nv_c370a8;extern string nv_d2f798[];
struct NvVecHI{char pad[16];NvVecHI();~NvVecHI();void push_back9b7cf0(const NvHI&);unsigned size9b9260()const throw();NvHI&at9b81f0(unsigned)throw();};void nv_shuffle9d9fc0(NvVecHI&);
struct NvVecPosL{char pad[16];NvVecPosL();~NvVecPosL();unsigned size9b9a50()const throw();bool empty9b86e0()const throw();NvPos&at9e7c10(unsigned)throw();};
void nv_appendUnique9d80a0(NvVecPosL&,NvVPt*);bool nv_fn9d3020(NvVecPosL&,NvPoint);int nv_fn6c10f0(const NvPos&);
struct NvCPart{void putChar4180b0(int,int,int);void refreshLabel890cf0();void u890710(int);void u4a8fc0();void moveLabel890c90();void drawStatus4a8e70(int);void u4a9120();};struct NvVecCP{char pad[16];NvVecCP();~NvVecCP();unsigned size9b9260()const throw();NvCPart*&at9b81f0(unsigned)throw();};struct NvCParts{bool isLinked4a9b10(NvHI);bool findParts4a9a40(NvHI,NvVecCP&);void u89d610(NvHI,int);void u896ab0(int);void u896b40();NvCPart*u896a80(NvHI);void u896820(NvHI);NvCPart*u894e70(NvHI);void toggle8993e0(NvCPart*,int);};extern NvCParts*nv_cec088;
struct NvCRow{int cleanup44b0d0();void clearRow428ac0(int,int,int);void u4aa510();};struct NvInvUI{NvCRow*u8a1fd0(NvHI,bool);void reopen8a2ce0b(int,NvHI);void reopen8a2ce0(int,NvHE);};extern NvInvUI*nv_cec08c;
struct NvCE{char pad0[8];int f8;};struct NvVCE{char pad[16];NvCE*&at9b81f0(unsigned)throw();};extern NvVCE nv_cf0fa8;extern int nv_ce9ff4;
struct NvCE2{char pad0[0x58];bool b58;};struct NvVCE2{char pad[16];NvCE2*&at9b81f0(unsigned)throw();};extern NvVCE2 nv_cfb844;
struct NvVecHE{char pad[16];NvVecHE();~NvVecHE();void push_back9b80b0(const NvHE&);unsigned size9b9260()const throw();NvHE&at9b81f0(unsigned)throw();};
struct NvVecHI2{char pad[16];NvVecHI2();~NvVecHI2();unsigned size9b9260()const throw();NvHI&at9b81f0(unsigned)throw();};
void nv_addUnique9d30e0(NvVecHE&,NvHE);void nv_addUnique9d30e0b(NvVecHI2&,NvHI);
struct NvIntGrid{int*atPoint9ced70(const NvPos&)throw();};extern NvIntGrid originalTerrain;extern int*caveinEarthTerrain;
#define CELLP(p) (*nv_cfd44c.atPoint9ced70(p))
struct NvExplDef;struct NvVExplDef{char pad[16];};extern NvVExplDef nv_cfd2cc;bool nv_findByName9d7be0(NvVExplDef&,const string&,NvExplDef*&);
struct NvExpl{char pad[0x40];NvExpl(NvHE,NvExplDef*,const NvPos&,NvHE,const NvPos&,const NvPos&);};
struct NvHMk;struct NvGM{NvHMk createC793190();void showOnce793450(int,int,int,int,int);NvHRec createA7930e0(NvExpl*);};extern NvGM*nv_cefaa8;
bool nv_show5111e0d(int,const string&,const string*,const string*,NvHE,NvHE,const NvPos&,int);
extern const float nv_c36ed0,nv_c36fec,nv_c36edc,nv_c36ecc;void nv_sound454260(const NvPos&,int);
struct NvVecHI3{char pad[16];NvVecHI3(const NvVecHI3&);NvHI&back9b6540()throw();void pop_back9e8cd0();NvHI&front9b7060()throw();NvVecHI3();~NvVecHI3();void push_back9b7cf0(const NvHI&);void push_back9b80b0(const NvHI&);unsigned size9b9260()const throw();NvHI&at9b81f0(unsigned)throw();bool empty9b86e0()const throw();};
extern NvGVec nv_cf4830;extern int nv_cf4d6c;extern const char nv_be664c[],nv_be665c[],nv_be65f4[];
struct NvVecU2{char pad[16];bool empty9b86e0()const throw();NvVecU2();~NvVecU2();void push_back9b9d30i(const int&);void clear9bac80();void push_back9b9d30(const unsigned&);void push_back9b9280(int&&);unsigned size9b9260()const throw();int&at9b81f0(unsigned)throw();};int nv_popRandom9de500(NvVecU2&);
extern NvGVec nv_cf4844,nv_cf4a98;extern int nv_caf164;extern NvRange nv_d2b4cc;extern const char nv_be6660[],nv_be6664[];void nv_logPhrase5141b0c(int,const string&,const string*,int,NvHE,int);
struct NvVecPt{char pad[16];NvPoint&front9b7060()throw();NvVecPt();NvVecPt(const NvVecPt&);unsigned size9b9a50()const throw();~NvVecPt();void push_back9b3020(NvPos&&);void push_back9b32e0(const NvPos&);bool empty9b86e0()const throw();NvPoint&at9e7c10(unsigned)throw();};int nv_randomIndex9d9230(NvVecPt&);
struct Point;namespace std{template<class _Ty,class _Ax> class vector;template<> class vector<Point,allocator<Point> >{public:char pad[16];vector();~vector();void push_back9b3020(NvPos&&);void push_back9b32e0(const NvPos&);bool empty9b86e0()const throw();NvPoint&at9e7c10(unsigned)throw();};}
typedef std::vector<Point,std::allocator<Point> > NvVecPtA;int nv_randomIndex9d9230(NvVecPtA&);

struct NvMk:NvPoint{NvHLoc h8;char c;bool bd;char pade[6];NvHP h14;NvHP h18;};struct NvVMk{char pad[16];unsigned size9b9260()const throw();NvMk*&at9b81f0(unsigned)throw();};
struct NvMarker{char pad[8];NvPos pos8;void u6c20b0(int,const NvPoint&,int);};struct NvHMk{int id;NvMarker*operator->()const throw();};
struct NvVMarker{char pad[16];unsigned size9b9260()const throw();NvHMk&at9b81f0(unsigned)throw();void push_back9b7cf0(const NvHMk&);NvHMk&back9b6540()throw();};
struct NvVVMarker{char pad[16];NvVMarker&at9b8070(unsigned)throw();};
struct NvIntGrid2{int*at9ceda0(int,int)throw();};struct NvS34{char pad[0x10];int f10;char pad14[0x10];int f24;};struct NvS34Grid{NvS34*at9d2c30(int,int)throw();};
struct NvEntRec{int f0;NvHE h4;};struct NvVEntRec{char pad[16];unsigned size9b9260()const throw();NvEntRec*&at9b81f0(unsigned)throw();};
struct NvMission{void u987de0();};extern NvMission*nv_cec034;
extern const int nv_ba0aa0[10][4],nv_ba0b40[4],nv_ba0b50[4];extern int nv_cf4744,nv_caf15c;extern const float nv_ba0a88;extern bool nv_b90480[];extern string nv_cf25d8[],nv_cfaca0[];
extern const char nv_be6670[],nv_be667c[],nv_be6684[],nv_be66a0[],nv_be66a8[],nv_be66b4[],nv_be66bc[],nv_be66c8[],nv_be66d0[],nv_be66dc[],nv_be66e4[],nv_be66f8[];
void nv_fn9d0690(int*,int,int);extern const char nv_be6c5c[],nv_be6c68[],nv_be6c70[],nv_be6c7c[];void nv_addUnique9d30e0c(NvVecHI3&,NvHI);extern int nv_cf68b4;extern NvHE nv_cf68b8;struct NvPlan{bool u672dd0(NvHE,int);void u672f20(NvHE,int,int,string);};extern NvPlan*nv_cf68f0;
struct NvComp{void u7ace20(NvHE);};extern NvComp*nv_cefc14;extern int nv_cefbb8;extern const float nv_c37178,nv_c36ed8;int nv_randomRec9d5d00d(NvVRec*);void nv_deleteObjects9d9bb0(NvVecU2&);extern bool nv_cefaef;extern int nv_cefaf4,nv_cf4b38;
bool nv_show5111e0e(int,const string*,const string*,const string*,NvHE,NvHE,const NvPos&,int);extern const char nv_be6bfc[],nv_be6c34[],nv_be6c4c[],nv_be6c50[],nv_be6c54[];extern int nv_d255e4,nv_cefb38,nv_cf4bb4,nv_cf4bb8,nv_cf4bbc;bool nv_fn9d51d0b(NvVecU2&,int);NvHI nv_findUpgrade4fd9e0(NvHI,NvVecHI3&,int);extern int nv_cf49ec,nv_cf4840,nv_d1eb10;extern const float nv_b96218[];extern int nv_b96248[];void nv_shuffle9d8f80(NvVecU2&);extern const char nv_be6b98[],nv_be6be4[],nv_be6be8[];extern const int nv_b960ec,nv_b960f4;extern const float nv_c36ecc;extern NvGVec nv_cf48cc;
struct NvVecIP{char pad[16];NvVecIP();~NvVecIP();unsigned size9b9260()const throw();NvItem*&at9b81f0(unsigned)throw();};struct NvPool{int getAll9d0c30(NvVecIP&);};extern NvPool nv_d2a298;extern int nv_b961e8[];extern const int nv_b96104,nv_b96108;extern const float nv_c36ec8,nv_c36eac,nv_c370ac,nv_c36ff0;extern const char nv_be6b94[];extern NvRange nv_d395a4,nv_d2c464,nv_cfb688;extern int nv_b961b4[];extern const int nv_b961cc_arr[];int nv_randomRec9d5d00c(NvVecU2&);extern const float nv_c37034,nv_c36fbc,nv_c37038,nv_c370a4,nv_c36ed4;struct NvEffX{int f0;int f4;char pad8[0x18-8];NvHE h18;};struct NvEffList{NvEffX*u458950(int);};
struct NvVecHE6{char pad[16];NvVecHE6();~NvVecHE6();unsigned size9b9260()const throw();NvHE&at9b81f0(unsigned)throw();};void nv_shuffle9d9fc0c(NvVecHE6&);
struct NvPosA{int x,y;NvPosA&operator=(const NvPos&);};struct NvF28{void u409ff0(int);};struct NvTimerInfo{char pad[0x14];NvPosA p14;NvHE h1c;char pad20[0x28-0x20];NvF28 f28;char pad29[0x30-0x29];bool b30;};extern int nv_d28d50,nv_d28d54,nv_d28d58,nv_d28d5c,nv_d1da50,nv_d1da54,nv_d1da58,nv_d1da5c;extern bool nv_d1da49,nv_d1da4a,nv_d1da4b,nv_d1da4c;
struct NvPhrase{char pad[0x20];NvPhrase(int,string*,string*,string*,NvHE,NvHE);};struct NvMsgUI{void add7b1880(NvPhrase*);};extern NvMsgUI*nv_cec0f4;
#define NVCAP (u45ac40(0x1e)?nv_b961cc:nv_b96200)
extern const char nv_be6b8c[];string nv_countString407a80(int,const string&);extern const float nv_ba09d4;extern int nv_caf2a0;void nv_clampMax9cf5a0(int&,int);void nv_shuffle9d7350(NvVecPt&);void nv_insert9d8fc0(NvVecHI3&,unsigned,NvHI);extern int nv_b95a0c[];extern int nv_d25564;extern NvRange nv_d035c8;extern const int nv_b961cc,nv_b96200;struct NvRolled{void say49e250(int,int,string);};extern NvRolled*nv_cefb48;extern const float nv_bba054,nv_ba09dc,nv_bba1dc,nv_c36eb4;extern bool nv_cf4980;extern int nv_cf4954;
struct NvRegion{int f0;int f4;NvHE h8;NvHE hc;NvPoint p10;NvRegion(int,int,NvHE,NvHE,const NvPos&);};NvRegion::NvRegion(int a,int b,NvHE c,NvHE d,const NvPos&p):f0(a),f4(b),h8(c),hc(d),p10(static_cast<const NvPoint&>(p)){}extern const float nv_ba0bb0;extern const double nv_c36cb0,nv_c36cd0;struct NvVVI{char pad[16];NvGVec&at9b8070(unsigned)throw();};extern NvVVI nv_cf4a58;extern int nv_cf4a68;extern unsigned nv_ba3bf8[];void nv_removeAt9de6f0c(NvGVec&,int);void nv_eraseStep9d6440(NvVecHI3&,unsigned&);void nv_clampInt9cdc50(int,int&,int);extern int nv_ba3acc[];void nv_shuffle9d9fc0b(NvVecHI3&);bool nv_addUnique9db000(NvVecU2&,int);bool nv_containsRecord9db330b(NvVecU2*,int);int nv_clamp9cdc80(int,int,int);void nv_eraseAt9da940b(NvVecHI3&,int);extern const char nv_be6b58[],nv_be6b5c[],nv_be6b6c[],nv_be6b84[],nv_be6b88[];extern NvGVec nv_d25790;bool nv_teamb69d230();extern const char nv_be6b00[],nv_be6b04[],nv_be6b08[],nv_be6b44[];struct NvWLI{char pad[0x24];NvWLI();~NvWLI();void add9ba0d0(NvHI,int);bool u9b81b0();NvHI&pick9ba470();};extern NvVecHI3 nv_cf4a48;NvHI nv_randomRecord9dafb0(NvVecHI3&);void nv_removeEntity9d2f00(NvVecHI3&,NvHI);extern const char nv_be6af0[];extern bool nv_b96a78[];struct NvVHP{char pad[16];unsigned size9b9260()const throw();NvHP&at9b81f0(unsigned)throw();};struct NvVVHP{char pad[16];unsigned size9b5100()const throw();NvVHP&at9b8070(unsigned)throw();};extern NvVVHP nv_d20248;extern const char nv_be6adc[];extern NvGVec nv_d1e910;extern const char nv_be6ac8[];bool nv_collectProps517ae0(int,NvVecPt*,int,int,int);void nv_eraseAt9d5190(NvVecPt&,int);void nv_eraseAt9ce6d0(NvGVec&,unsigned&);extern const float nv_ba0a8c;extern const char nv_be6a4c[],nv_be6a54[],nv_be6a5c[],nv_be6a74[],nv_be6a8c[],nv_be6aa4[],nv_be6ab0[];extern int nv_d1eb60,nv_b90f38[];extern NvRange nv_cf1f1c;extern int nv_cf119c;extern const char nv_be69dc[],nv_be6a00[],nv_be6a14[],nv_be6a38[];int nv_distanceCeil40a3f0(const NvPos&,const NvPos&);
struct NvVecHE5{char pad[16];bool empty9b86e0()const throw();unsigned size9b9260()const throw();NvHE&at9b81f0(unsigned)throw();};struct NvVGrp{char pad[16];unsigned size9b9260()const throw();NvHG&at9b81f0(unsigned)throw();};bool nv_anyNonZero9d7f70(NvVecU2&);extern const char nv_be686c[],nv_be6874[],nv_be68ec[],nv_be68f8[],nv_be6924[],nv_be693c[],nv_be696c[],nv_be6984[],nv_be69bc[],nv_be69d4[];
bool operator!=(const string&,const char*);struct NvVecRI{char pad[16];NvVecRI();~NvVecRI();void push_back9b9d30(NvRecI*const&);unsigned size9b9260()const throw();NvRecI*&at9b81f0(unsigned)throw();};void nv_removeAt9de6f0(NvVecRI&,int);
extern int nv_cebc4c,nv_d28d68;struct NvVbRef{int p;int o;NvVbRef(const NvVbRef&);bool toBool9b3ad0()const;NvVbRef&assign9b3a70(bool);};struct NvVecB{char pad[20];NvVecB();void push_back9b3920(bool);NvVecB(unsigned,bool);~NvVecB();NvVbRef at9b38a0(unsigned);};bool nv_fn9d9b60(const NvVecB&);extern const char nv_be685c[],nv_be6880[];void nv_message49c610(int,NvHE,const string*,int);extern const char nv_be6834[],nv_be6840[],nv_be6858[];bool nv_findByName9d7530(NvVRec&,const string&,NvRec*&);extern NvWL nv_d02b74,nv_cf2974;extern NvVecHE nv_cf4aa8;extern NvGVec nv_cf4ab8;void nv_logPhrase5141b0d(int,const string&,const string*,const string*,NvHE,int);extern const char nv_be6810[],nv_be6824[];extern int nv_d1eb40;NvRecI*nv_777cf0();bool nv_findByName9d7a40(NvVRecP&,const string&,NvRecI*&);struct NvUniq{bool addUnique49b830(NvHP);};extern NvUniq nv_d1d9c0;void nv_7b1750(int,const string&,int,int,NvHE,NvHE,int);extern NvGVec nv_cf47cc;struct NvGM2{void addItemAttachCount778560(int,int,int);};extern NvGM2 nv_d25628;void nv_logError404f10(string,string);string nv_pointToString40a4a0(const NvPos&);extern const char nv_be67f0[],nv_be67c8[],nv_be67f8[];extern const float nv_ba0b60;void nv_moveElement9da1f0(NvVecHI3&,unsigned,int);void nv_clearDijkstra4faf40();struct NvFov{void u40ca20(const NvPos&,int,int*,int);};extern NvFov nv_cfe568;extern int nv_cfe5e8;extern NvVecPt nv_d15e58;
void nv_logWarning404e50(string,string);extern const char nv_be673c[],nv_be67b4[];bool nv_nextLineStep40ff60(const NvPoint&,const NvPos&,NvPoint*);int nv_commonNeighbors4fac50(const NvPos&,const NvPos&,NvVecPt&);
struct NvVecF{char pad[16];NvVecF();~NvVecF();void push_back9b84b0(float&&);bool empty9b86e0()const throw();float&at9b81f0(unsigned)throw();};float nv_distance40a450(const NvPos&,const NvPos&);void nv_eraseStep9d7300(NvVecPt&,unsigned&);int nv_fn9d7d70(NvVecF&);
void nv_surrounding4faaf0(const NvPos&,NvVecPt&);void nv_fn9d06d0(int*,int,int);int nv_stringToInt405610(const string&);extern const char nv_be6700[],nv_be671c[],nv_be6720[],nv_be6768[];
struct NvEntity{char pad0[4];NvHE self;NvEntDef*f8;char padc[0x28-0xc];NvHG h28;char pad2c[0x30-0x2c];NvVPos v30;char pad40[0x44-0x40];NvPos p44;int i4c;char pad50[0x70-0x50];int i70;char pad74[0x78-0x74];int a78[4];char pad88[0x90-0x88];int i90;int i94;int i98;NvVecI2 v9c;bool bac;char padad[3];int ib0;char padb4[0xc0-0xb4];bool bc0;char padc1[0xf0-0xc1];NvEffList*ff0;int ff4;char padf8[0x134-0xf8];NvVHI parts;NvAI*ai144;
 bool isPlayer5c7600();void die633790(bool,int,NvHE,int,int,int,int,int);void pickUp5dfd80();int u5cad50();int u5c8fc0(int,int);int u5cab90();void u5e5340(int,int,int,int,int,const string&);bool u5cbdf0(int,int,int);void fire63a3e0(int,NvHE);void u6399e0(int,int);void u5fd550(NvHI,int);int u5ca840();int u5cb930(NvVecHI3&);NvHI u5d1150(NvHE);NvHI u5d1150b(NvHI);void u45aeb0(NvEffX*);void u5c8880(NvVecHE6&);void u5d2430(int,NvVecHI3&);NvHI u5d24e0(int);NvHI u5e3cb0b(int,int,NvVecU2&,int,int);int u45a880();int u45a8f0();int u45a940();NvAI*ai45b590t()throw();int u5cab30();bool u5d4ff0(bool,NvHI);NvHI u5d4dd0(bool,NvHI);void u5e2b00(int,const NvPos&);void checkEffectScrapEngine605040(NvHI);int u5c92e0(int);int u5d1390();bool u5dc680(NvHI);bool u5cd220(NvHI);void u5c93d0(NvVecU2&);int getTarget45a760();int u5dc440(NvHI);int u5cb8b0(NvVecHI3&);void u45b2a0();const string&getName45a280();NvHI u5d56d0(NvRecI*);void u45b1e0(int);int u5deb40(int);bool u5e2590(NvHI,const NvPos&,int);bool u45aaa0(NvHE);int u5ca210();int u5cccc0();int u5c8e20(int);int getSlotTotal45a860();bool u5ccef0();int u5cca00();
 void u5cede0(int*,int*);NvHI u5d2380(int);void u5d3700();int u5ca960();int u5d2090(int)throw();int u5d1070()throw();int u5ca400()throw();int u45a920()throw();int u5ca670()throw();int u5c7d30()throw();int u5c7d80(int)throw();int u45a3c0()throw();int u5c7e40()throw();int u5d22a0(int)throw();int u5d2150(int,int)throw();int u5cb570(int,int)throw();int u5d7b00(int)throw();int u5c7ee0()throw();int u5c7f10()throw();int u5c7f40()throw();
 int u45acb0(int)throw();void u5de870(int,int);NvEntDef2*def9b4350()throw();NvPos u45a4c0();void u5ded70(int);int getFaction45a2c0();void u5defa0(int,int);bool u5c7f70();void u639950(int*,NvHE,int);void u45b210(int);void u45b1b0(int);void u45b180(int);bool isHostileTo45aa70(NvHE);NvEffPair*u45ac40(int);void u45b340(NvEffPair*);void setField4514c0(int);NvVPt*u45d1a0();int u45a810();bool u5d4490(NvHE);void u5d47c0(NvHE,NvVecHE&,int);void u5fdab0();void removeEffectsA639730(int);void changeFaction5dc780(NvHG,int);bool u5cb680(NvHG);int getAiType45a2a0();void u5fd900(int,int);NvAI*ai45b590();void u64e7e0(NvHI);int u5ca8d0();NvHI u5d25e0(int);double u5ca4f0();bool checkFragile603030(NvHI);bool u603280(NvHI);int getField490840();int u5ca260();void u5dea60(int,int);NvVHI*getInventoryList45ab00();const string&name416f40();NvHG getGroup45a3f0();void u637bb0();void u6396a0(const string&,int);NvPos&getPosition45a4a0();int getSize45a360();void u5ddac0(const NvPos&,int);int takeDamage5e5520(int,int,int,int,int,int,int,bool,NvHE,int,int,int,int,int);NvHI u5e3cb0(int,int,NvVecU&,int,int);void u642940(NvHI,bool,int,int,int);
 void turnUpdate();};
void NvEntity::turnUpdate(){
	bool b5=isPlayer5c7600();
	NvHE aG=self;
	if(p44.ne409bd0(v30.front9b7060())){p44=v30.front9b7060();i4c=0;}else i4c++;
	if(b5){
		int a3=u5ca210();
		int b=u5cccc0();
		nv_d2c658.add4729d0(0xbc,b,"",-1);
		nv_d2c658.add4729d0(0xbd,b,"",-1);
		if(b>nv_cf4c24){
			nv_cf4c24=b;
			nv_cf4bf0.clear9bac80();
			nv_cf4c00.clear9bac80();
			for(int i=0;i<4;i++)nv_cf4c00.push_back9b9d30(a78[i]);
			nv_cf4c10.clear9bac80();
			nv_cf4c20=a3;
			for(unsigned i=0;i<parts.size9b9260();i++){
				if(parts.at9b81f0(i)->getType44aec0()!=4)nv_cf4bf0.push_back9b9280(parts.at9b81f0(i)->nested457820());
				else nv_cf4c10.push_back9b9280(parts.at9b81f0(i)->nested457820());
			}
		}
		if(b>=50)nv_cf45d8.unlock77fbc0(0x110);
		if(b>=100)nv_cf45d8.unlock77fbc0(0x111);
		if(b>=150)nv_cf45d8.unlock77fbc0(0x112);
		if(b>=200)nv_cf45d8.unlock77fbc0(0x113);
		for(unsigned i=0;i<parts.size9b9260();i++){
			if(parts.at9b81f0(i)->getType44aec0()!=4)nv_cf4c28.at9b81f0(parts.at9b81f0(i)->nested457820())++;
		}
		if(nv_d1e860.u46f4b0(1)&&nv_d1e888->f4!=0x23){
			int t=nv_threshold433260(nv_cf6428.v);
			nv_d2c658.add4729d0(0x20c,t,"",-1);
			if(nv_cf645c)nv_d2c658.add4729d0((nv_cf6468!=0)+0x213,1,"",-1);
			else nv_d2c658.add4729d0(t+0x20d,1,"",-1);
		}
		nv_d2c658.add4729d0(0xc5,a3,"",-1);
		nv_d2c658.add4729d0(0xc6,a3,"",-1);
		int c=u5c8e20(0);
		nv_d2c658.add4729d0(0xc7,c,"",-1);
		if(c>=30)nv_cf45d8.unlock77fbc0(0xe8);
		nv_d2c658.add4729d0(0xc8,c,"",-1);
		if(nv_cefc4c->getTurn464270()%11==0||nv_cefc4c->u4642d0()==1){
			NvVecI counts(5u,0u);
			for(unsigned i=0;i<parts.size9b9260();i++){
				if(parts.at9b81f0(i)->getType44aec0()==4&&parts.at9b81f0(i)->nested4578a0()!=5){
					if(parts.at9b81f0(i)->def9b4350()->b1af)counts.back9b6540()++;
					else counts.at9b81f0(parts.at9b81f0(i)->nested4578a0())++;
				}
			}
			nv_d2c658.add4729d0(0x97,nv_sum9cdbd0(counts),"",-1);
			for(int i=0;i<4;i++)nv_d2c658.add4729d0(i+0x98,counts.at9b81f0(i),"",-1);
		}
		if(nv_d1e888->f4!=1){
			if(nv_cefc4c->getTurn464270()%10==0||nv_cefc4c->u4642d0()==1){
				int n=0;
				NvVecI slots(0x1f,0);
				for(unsigned i=0;i<parts.size9b9260();i++){
					if(parts.at9b81f0(i)->getType44aec0()<=3){
						n++;
						slots.at9b81f0(nv_minInt9cdb30(parts.at9b81f0(i)->nested457880(),0x1d))++;
					}
				}
				int gN=getSlotTotal45a860();
				nv_d2c658.add4729d0(0xa3,n*100/gN,"",-1);
				for(int i=6,h5=0xa4;i<=0x1d;i++,h5++)nv_d2c658.add4729d0(h5,slots.at9b81f0(i)*100/gN,"",-1);
				if(c>=15&&n>c&&nv_cf45d8.isSlotEmpty46de40(0xe9)&&u5ccef0())nv_cf45d8.unlock77fbc0(0xe9);
			}
			for(unsigned i=0;i<parts.size9b9260();i++){
				if(parts.at9b81f0(i)->getType44aec0()<=3)goto skipC0;
			}
			nv_d2c658.add4729d0(0xc0,1,"",-1);
skipC0:;
		}
		if(nv_cefc4c->getTurn464270()%13==0||nv_cefc4c->u4642d0()==1){
			int n=0;
			for(unsigned i=0;i<parts.size9b9260();i++){
				if(parts.at9b81f0(i)->nested457880()==5)n++;
				else if(parts.at9b81f0(i)->u457f90()==0xa6&&parts.at9b81f0(i)->u457d70())n+=parts.at9b81f0(i)->u45cb30();
			}
			nv_d2c658.add4729d0(0x255,n,"",-1);
		}
		if(!nv_d28d16&&nv_cefc4c->getTurn464270()%21==0&&nv_cf45d8.isSlotEmpty46de40(0x89)&&u5cca00()<=2)nv_cf45d8.unlock77fbc0(0x89);
		if(nv_d1e888->f8<0xb){
			if(nv_cf462c==0xb){
				nv_cf4784.add46cd30(nv_cf4700==0?0:nv_d25de0.at9b81f0(nv_cf4700->idx)->f28,0x14,1);
				nv_d1e89c.back9b8ae0().add46cd30(nv_cf4700==0?0:nv_d25de0.at9b81f0(nv_cf4700->idx)->f28,0x14,1);
			}else if(nv_cefc4c->getTurn464270()>nv_cf47b4+0x12){
				bool ok=true;
				for(int i=4;i<=8;i++){
					if(nv_cefc4c->getTurn464270()-nv_cf4770.at9b81f0(i)<=0x14){ok=false;break;}
				}
				if(ok){
					int xC,y;
					u5cede0(&xC,&y);
					int aA=nv_cefc4c->getTurn464270()-nv_cf47b4;
					nv_cf4784.add46cd30(xC,y,aA);
					nv_cf47b4=nv_cefc4c->getTurn464270();
					nv_d1e89c.back9b8ae0().add46cd30(xC,y,nv_minInt9cdb30(aA,nv_cefc4c->u4642d0()));
					if((nv_cf47b8!=xC||nv_cf47bc!=y)&&nv_cf47a4.back9b6540()>=300){
						nv_cf47b8=xC;
						nv_cf47bc=y;
						do{nv_logPhrase5141b0(9,nv_cf4784.getName7787b0(-1),0,0,NvHE(),0);}while(0);
					}
				}
			}
		}
		int nSpecial=0;
#define SPC(S,ID) if(u5d2380(S).isValid9b7230()){nv_d2c658.add4729d0(ID,1,"",-1);nSpecial++;}
		SPC(0xa,0x3bd)SPC(0xb,0x3be)SPC(0xd,0x3bf)SPC(0xe,0x3c0)SPC(0xf,0x3c1)SPC(0x10,0x3c2)SPC(0x18,0x3c3)SPC(0x19,0x3c4)SPC(0x12,0x3c5)SPC(0x98,0x3c6)
		if(u5d2380(0x16).isValid9b7230()||u5d2380(0x17).isValid9b7230()){nv_d2c658.add4729d0(0x3c7,1,"",-1);nSpecial++;}
		SPC(0x1a,0x3c8)SPC(0x1c,0x3c9)SPC(0x1e,0x3ca)SPC(0x20,0x3cb)SPC(0x14,0x3cc)SPC(0x13,0x3cd)SPC(0x1f,0x3ce)
		if(nSpecial){
			nv_d2c658.add4729d0(0x3bc,1,"",-1);
			if(nSpecial>=5)nv_cf45d8.unlock77fbc0(0x6f);
			if(nSpecial>=10)nv_cf45d8.unlock77fbc0(0xa6);
		}
		if(u5d2380(0xa1).isValid9b7230())nv_d2c658.add4729d0(0xce,1,"",-1);
		if(nv_cefc4c->getTurn464270()%10==0){
			nv_d2c658.add4729d0(0x461,u5ca960(),"",-1);
			nv_d2c658.add4729d0(0x462,u5d2090(2),"",-1);
			nv_d2c658.add4729d0(0x463,u5d1070(),"",-1);
			if(nv_d2c658.vals->at9b81f0(0x463)>=75)nv_cf45d8.unlock77fbc0(0xec);
			nv_d2c658.add4729d0(0x464,u5ca400(),"",-1);
			if(nv_cf45d8.isSlotEmpty46de40(0xed)&&nv_d2c658.vals->at9b81f0(0x464)>=1500){
				for(unsigned i=0;i<parts.size9b9260();i++){
					if(nv_between9daf80(0x43,parts.at9b81f0(i)->u457f90(),0x47)&&parts.at9b81f0(i)->u457cf0()){nv_cf45d8.unlock77fbc0(0xed);break;}
				}
			}
			nv_d2c658.add4729d0(0x465,u45a920(),"",-1);
			nv_d2c658.add4729d0(0x466,u5ca670(),"",-1);
			nv_d2c658.add4729d0(0x467,u5c7d30(),"",-1);
			nv_d2c658.add4729d0(0x468,u5c7d80(0),"",-1);
			nv_d2c658.add4729d0(0x469,u45a3c0(),"",-1);
			nv_d2c658.add4729d0(0x46a,u5c7e40(),"",-1);
			nv_d2c658.add4729d0(0x46b,u5d2090(0x13),"",-1);
			nv_d2c658.add4729d0(0x46c,u5d22a0(0x14),"",-1);
			nv_d2c658.add4729d0(0x46d,u5d2150(0x1e,0),"",-1);
			nv_d2c658.add4729d0(0x46e,u5d2090(0x21),"",-1);
			nv_d2c658.add4729d0(0x46f,u5d22a0(0x22),"",-1);
			int v=u5d22a0(6);
			nv_d2c658.add4729d0(0x470,v?v:0,"",-1);
			nv_d2c658.add4729d0(0x471,u5d2090(0x29),"",-1);
			nv_d2c658.add4729d0(0x472,u5d2090(0x2a),"",-1);
			v=0;
			for(unsigned i=0;i<parts.size9b9260();i++){
				if(parts.at9b81f0(i)->u457f90()==0x2b&&parts.at9b81f0(i)->u457cf0())v+=parts.at9b81f0(i)->u9b6bf0()/2+(parts.at9b81f0(i)->u9b6bf0()%2!=0);
			}
			nv_d2c658.add4729d0(0x473,v,"",-1);
			v=0;
			for(unsigned i=0;i<parts.size9b9260();i++){
				if(parts.at9b81f0(i)->nested457880()==0x12&&parts.at9b81f0(i)->getType44aec0()!=4)v+=parts.at9b81f0(i)->u577790();
			}
			nv_d2c658.add4729d0(0x475,v,"",-1);
			for(int i=0;i<7;i++)nv_d2c658.add4729d0(i+0x476,100-u5cb570(i,1),"",-1);
			if(nv_d2c658.vals->at9b81f0(0x479)>=100)nv_cf45d8.unlock77fbc0(0xe5);
			nv_d2c658.add4729d0(0x47d,u5d22a0(0x39),"",-1);
			nv_d2c658.add4729d0(0x47e,u5d22a0(0x3a),"",-1);
			nv_d2c658.add4729d0(0x47f,u5d22a0(0x3b),"",-1);
			nv_d2c658.add4729d0(0x480,u5d22a0(0x3c),"",-1);
			nv_d2c658.add4729d0(0x481,u5d22a0(0x3d),"",-1);
			nv_d2c658.add4729d0(0x482,u5d2090(0x48),"",-1);
			nv_d2c658.add4729d0(0x483,u5d22a0(0x49),"",-1);
			nv_d2c658.add4729d0(0x486,nv_minInt9cdb30(u5d2090(0x50),0x1e),"",-1);
			nv_d2c658.add4729d0(0x487,nv_minInt9cdb30(u5d2090(0x51),0x32),"",-1);
			nv_d2c658.add4729d0(0x488,nv_maxInt9cdb60(u5d22a0(0x52),u5d22a0(0x61)),"",-1);
			if(nv_cec07c){
				nv_d2c658.add4729d0(0x489,nv_cec07c->fac,"",-1);
				if(nv_cec07c->fac>=75)nv_cf45d8.unlock77fbc0(0xae);
			}
			nv_d2c658.add4729d0(0x48a,u5d7b00(1),"",-1);
			if(nv_d2c658.vals->at9b81f0(0x48a)>=40)nv_cf45d8.unlock77fbc0(0x8c);
			nv_d2c658.add4729d0(0x48b,u5d2090(0x5a),"",-1);
			nv_d2c658.add4729d0(0x48c,u5d2090(0x5d),"",-1);
			nv_d2c658.add4729d0(0x48d,u5d2150(0x5f,0),"",-1);
			nv_d2c658.add4729d0(0x48e,nv_maxInt9cdb60(u5d2150(0x60,0),u5d22a0(0x61)),"",-1);
			nv_d2c658.add4729d0(0x48f,u5d22a0(0x62),"",-1);
			nv_d2c658.add4729d0(0x490,u5c7ee0(),"",-1);
			nv_d2c658.add4729d0(0x491,u5d2150(0x64,0),"",-1);
			nv_d2c658.add4729d0(0x492,u5d2150(0x65,0),"",-1);
			nv_d2c658.add4729d0(0x493,u5d2150(0x67,0),"",-1);
			nv_d2c658.add4729d0(0x494,u5d22a0(0x69),"",-1);
			nv_d2c658.add4729d0(0x495,u5d22a0(0x6a),"",-1);
			nv_d2c658.add4729d0(0x499,u5d2090(0x70)+u5d2090(0x71),"",-1);
			nv_d2c658.add4729d0(0x49b,u5c7f10(),"",-1);
			if(nv_d2c658.vals->at9b81f0(0x49b)>=100)nv_cf45d8.unlock77fbc0(0xb3);
			if(nv_cf462c==8&&nv_cf46e4.at9b81f0(4)==0&&nv_d2c658.vals->at9b81f0(0x49b)>=40){
				string msg(nv_be64d8);
				nv_fn510360(msg);
				do{
					nv_cf1080.set451400(3);
					if(0)nv_sound4541b0(-1,0,0);
					do{if(nv_show5111e0(0x324,&msg,0,0,NvHE(),NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					nv_cec0b4->scrollToEnd7b4f10();
				}while(0);
				nv_cf46e4.at9b81f0(4)=1;
			}
			nv_d2c658.add4729d0(0x49c,u5c7f40(),"",-1);
			if(!nv_cf4a14.empty9b86e0()){
				v=0;
				NvVecU seen;
				int w=0;
				for(unsigned i=0;i<parts.size9b9260();i++){
					if(parts.at9b81f0(i)->u457cf0()&&parts.at9b81f0(i)->u457f90()==0x7c){
						v+=parts.at9b81f0(i)->u45cb30();
						if(!nv_containsRecord9db330(&seen,parts.at9b81f0(i)->nested457820())){
							seen.push_back9b9280(parts.at9b81f0(i)->nested457820());
							if(parts.at9b81f0(i)->u457fb0()==2)w+=4;
							else w++;
						}
					}
				}
				if(v){
					nv_d2c658.add4729d0(0x49d,w,"",-1);
					nv_d2c658.add4729d0(0x49e,v,"",-1);
				}
			}
			v=0;
			for(unsigned i=0;i<parts.size9b9260();i++){
				if(parts.at9b81f0(i)->u457f90()==0x7b&&parts.at9b81f0(i)->u457d70())v++;
			}
			nv_d2c658.add4729d0(0x49f,v,"",-1);
			nv_d2c658.add4729d0(0x4a0,u5d2090(0xa6),"",-1);
		}
		if(nv_cf4700)nv_d2c658.add4729d0(0x459,(int)nv_cf46f8,"",-1);
	}else if(nv_cf462c==7&&self==nv_cefc4c->getEntity463110()&&(nv_cefc4c->getTurn464270()-nv_cf46a4)%10==0){
		nv_cf46a4=nv_cefc4c->getTurn464270();
		u5cede0(&nv_cf46a8,&nv_cf46ac);
	}
	if(nv_caf130!=6&&i70==0){
		if(u45acb0(0xe))u5de870(u45acb0(0xe),0);
		if(u45acb0(0xf)){
			int pct=u45acb0(0xf);
			int u4;
			int bN;
			for(unsigned i=0;i<parts.size9b9260();i++){
				if(parts.at9b81f0(i)->getType44aec0()<=3&&parts.at9b81f0(i)->u457cf0())parts.at9b81f0(i)->u458360(pct);
			}
			if(!nv_d1ec84.empty9b86e0()&&nv_cefc4c->getTurn464270()>=nv_d1ec94.front9b7060()){
				if(nv_cefc4c->getTurn464270()>nv_d1ec94.front9b7060()){
					int d=nv_cefc4c->getTurn464270()-nv_d1ec94.front9b7060();
					for(unsigned i=1;i<nv_d1ec94.size9b9260();i++)nv_d1ec94.at9b81f0(i)+=d;
				}
				NvHI i8=nv_cefc4c->u6c51d0(nv_d2d1c4.at9b81f0(nv_d1ec84.front9b7060()),self,1,0);
				if(i8.isValid9b7230()){
					do{if(nv_show5111e0b(0x7a,i8->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
				}
				nv_removeAt9de6f0(nv_d1ec84,0);
				nv_removeAt9de6f0(nv_d1ec94,0);
			}
			NvVVRec*recs=&def9b4350()->v160;
			NvVecU found6;
			for(unsigned i=0;i<recs->size9b5100();i++){
				u4=recs->at9b8070(i).front9b7060()->f0;
				bN=recs->at9b8070(i).front9b7060()->f4;
				for(unsigned j=0;j<parts.size9b9260();j++){
					if(parts.at9b81f0(j)->nested457820()==u4&&--bN==0)break;
				}
				if(bN!=0)found6.push_back9b9d30(u4);
			}
			for(unsigned i=0;i<nv_d1ec84.size9b9260();i++)nv_fn9d51d0(found6,nv_d1ec84.at9b81f0(i));
			if(!found6.empty9b86e0()){
				for(unsigned i=0;i<found6.size9b9260();i++){
					nv_d1ec84.push_back9b9d30(found6.at9b81f0(i));
					nv_d1ec94.push_back9b9280(nv_maxInt9cdb60(nv_cefc4c->getTurn464270(),nv_d1ec94.empty9b86e0()?0:nv_d1ec94.back9b6540())+10);
				}
			}
		}
		if(u45acb0(0x18)){
			int vC=u45acb0(0x18);
			int r=vC/2;
			NvPos nPos=u45a4c0();
			NvRect rc7;
			nv_cfd44c.getRect9b4430(nPos,r,rc7);
			for(int x=rc7.x1;x<rc7.x2;x++)for(int y=rc7.y1;y<rc7.y2;y++){
				if(CELL(x,y)->getEntity45d250().isValid9b7230()&&CELL(x,y)->getEntity45d250()!=self&&nv_distance406480(nPos,x,y)<=r&&nv_cefc4c->u72a290(nPos,x,y))
					CELL(x,y)->getEntity45d250()->u5ded70(vC-nv_distance406480(nPos,x,y));
			}
		}
		if(u45acb0(0x19)){
			int k5=u45acb0(0x19);
			int aN=10;
			NvPos posVal=u45a4c0();
			NvRect rc4;
			nv_cfd44c.getRect9b4430(posVal,aN,rc4);
			for(int x=rc4.x1;x<rc4.x2;x++)for(int y=rc4.y1;y<rc4.y2;y++){
				if(CELL(x,y)->getEntity45d250().isValid9b7230()&&CELL(x,y)->getEntity45d250()!=self&&!CELL(x,y)->getEntity45d250()->u45acb0(0x19)&&::rng.chance406c90(k5)&&nv_distance406480(posVal,x,y)<=aN&&nv_cefc4c->u72a290(posVal,x,y)){
					int dmg=!CELL(x,y)->getEntity45d250()->isPlayer5c7600()&&CELL(x,y)->getEntity45d250()->getFaction45a2c0()!=0x49?nv_d2b4ec.random40c130():nv_d1dafc.random40c130();
					dmg=CELL(x,y)->getEntity45d250()->u5cb570(3,1)*dmg/100;
					CELL(x,y)->getEntity45d250()->u5defa0(dmg,1);
					if(u5c7f70())u639950(&CELL(x,y)->getEntity45d250()->ff4,nv_cefc4c->getPlayer4630f0(),dmg);
				}
			}
		}
		if(u45acb0(0x1a)){
			int lo=u45acb0(0x1a);
			int bX=10;
			NvPos a_=u45a4c0();
			NvRect aB;
			nv_cfd44c.getRect9b4430(a_,bX,aB);
			for(int x=aB.x1;x<aB.x2;x++)for(int y=aB.y1;y<aB.y2;y++){
				if(CELL(x,y)->getEntity45d250().isValid9b7230()&&CELL(x,y)->getEntity45d250()!=self&&nv_distance406480(a_,x,y)<=bX&&nv_cefc4c->u72a290(a_,x,y))
					CELL(x,y)->getEntity45d250()->u45b210(nv_maxInt9cdb60(0,lo-nv_distance406480(a_,x,y)*10));
			}
		}
		if(u45acb0(0x1b)){
			int nG=u45acb0(0x1b);
			int c0=10;
			NvPos bC=u45a4c0();
			NvRect b9;
			nv_cfd44c.getRect9b4430(bC,c0,b9);
			for(int x=b9.x1;x<b9.x2;x++)for(int y=b9.y1;y<b9.y2;y++){
				if(CELL(x,y)->getEntity45d250().isValid9b7230()&&CELL(x,y)->getEntity45d250()!=self&&nv_distance406480(bC,x,y)<=c0&&nv_cefc4c->u72a290(bC,x,y)){
					int e=nv_maxInt9cdb60(0,nG-nv_distance406480(bC,x,y)*2);
					CELL(x,y)->getEntity45d250()->u45b1b0(e);
					CELL(x,y)->getEntity45d250()->u45b180(e);
				}
			}
		}
		if(u45acb0(0x1d)){
			nv_cefc4c->u747400(self,NvHE(),1,1);
			if(aG.operator->()==0)return;
		}
		if(f8->f28==0x48){
			int mode=u45acb0(0x28);
			switch(mode){
			case 0:{
				int nW=150;
				int dB=10;
				NvPos c7=u45a4c0();
				NvRect c3;
				nv_cfd44c.getRect9b4430(c7,dB,c3);
				for(int x=c3.x1;x<c3.x2;x++)for(int y=c3.y1;y<c3.y2;y++){
					if(CELL(x,y)->getEntity45d250().isValid9b7230()&&isHostileTo45aa70(CELL(x,y)->getEntity45d250())&&nv_distance406480(c7,x,y)<=dB&&nv_cefc4c->u72a290(c7,x,y))
						CELL(x,y)->getEntity45d250()->u45b210(nv_maxInt9cdb60(0,nW-nv_distance406480(c7,x,y)*10));
				}
				break;}
			case 1:{
				int ns=10;
				int e4=10;
				NvPos cX=u45a4c0();
				NvRect c8;
				nv_cfd44c.getRect9b4430(cX,e4,c8);
				for(int x=c8.x1;x<c8.x2;x++)for(int y=c8.y1;y<c8.y2;y++){
					if(CELL(x,y)->getEntity45d250().isValid9b7230()&&isHostileTo45aa70(CELL(x,y)->getEntity45d250())&&::rng.chance406c90(ns)&&nv_distance406480(cX,x,y)<=e4&&nv_cefc4c->u72a290(cX,x,y)){
						int dmg=CELL(x,y)->getEntity45d250()->isPlayer5c7600()?nv_d1dafc.random40c130():nv_d2b4ec.random40c130();
						dmg=CELL(x,y)->getEntity45d250()->u5cb570(3,1)*dmg/100;
						CELL(x,y)->getEntity45d250()->u5defa0(dmg,1);
						if(u5c7f70())u639950(&CELL(x,y)->getEntity45d250()->ff4,nv_cefc4c->getPlayer4630f0(),dmg);
					}
				}
				break;}
			case 2:{
				int pK=5;
				NvRect a0;
				NvPos pos=u45a4c0();
				nv_cfd44c.getRect9b4430(pos,pK,a0);
				for(int x=a0.x1;x<a0.x2;x++)for(int y=a0.y1;y<a0.y2;y++){
					if(CELL(x,y)->getEntity45d250().isValid9b7230()&&isHostileTo45aa70(CELL(x,y)->getEntity45d250())&&::rng.chance406c90(0xf)&&nv_distance406480(pos,x,y)<=pK&&nv_cefc4c->u72a4d0(pK*2,pos,x,y)){
						NvHE target=CELL(x,y)->getEntity45d250();
						int dmg=target->isPlayer5c7600()?nv_d2a4f4.random40c130():nv_d1f38c.random40c130();
						dmg=target->u5cb570(3,1)*dmg/100;
						nv_cefc4c->zap7273e0(NvPoint(pos),target);
						do{if(nv_show5111e0c(target->isPlayer5c7600()?0x2e9:0x2ea,0,0,0,self,target,NvPoint(x,y),0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						target->u5defa0(dmg,1);
					}
				}
				break;}
			case 3:{
				int link=0;
				int dur=6;
				if(i4c<dur-1){
					int q3=3;
					NvRect a6;
					NvPos pos=u45a4c0();
					nv_cfd44c.getRect9b4430(pos,q3,a6);
					for(int x=a6.x1;x<a6.x2;x++)for(int y=a6.y1;y<a6.y2;y++){
						if(CELL(x,y)->getEntity45d250().isValid9b7230()&&isHostileTo45aa70(CELL(x,y)->getEntity45d250())&&(!CELL(x,y)->getEntity45d250()->u45acb0(0x29)||nv_cefc4c->getTurn464270()>=CELL(x,y)->getEntity45d250()->u45acb0(0x29)+dur)&&nv_distance406480(pos,x,y)<=q3&&nv_cefc4c->u72a4d0(q3*2,pos,x,y)){
							NvHE target=CELL(x,y)->getEntity45d250();
							NvEffPair*a4=target->u45ac40(0x29);
							if(a4==0){
								a4=new NvEffPair(nv_d2f0f8.at9b81f0(0x29),1);
								u45b340(a4);
							}
							a4->value=nv_cefc4c->getTurn464270()+dur;
							nv_d225a0.u672b80(target,dur*100);
							if(target->isPlayer5c7600())nv_cefc4c->u464750(dur*100);
							do{if(nv_show5111e0c(target->isPlayer5c7600()?0x2eb:0x2ec,0,0,0,self,target,NvPoint(x,y),0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							target->setField4514c0(0);
							NvVPt*cells=target->u45d1a0();
							for(unsigned i=0;i<cells->size9b9a50();i++){
								if(nv_cefc4c->isVisible4631c0(cells->at9e7c10(i))&&(link!=0||nv_lookup9d7980("Anomaly_Ice",&link)))
									nv_cefc50->new508610(nv_cefc50)->init503b20(link,cells->at9e7c10(i),&nv_d2e20c,0,0,0,9,0);
							}
						}
					}
				}
				break;}
			case 4:{
				int t_=5;
				NvRect aW;
				NvPos pos=u45a4c0();
				nv_cfd44c.getRect9b4430(pos,t_,aW);
				for(int x=aW.x1;x<aW.x2;x++)for(int y=aW.y1;y<aW.y2;y++){
					if(CELL(x,y)->getProp45d550().isValid9b7230()&&nv_distance406480(pos,x,y)<=t_&&CELL(x,y)->getProp45d550()->def9b8f00()->f8c!=0&&!CELL(x,y)->getProp45d550()->isTrap45cb70()){
						do{if(nv_show5111e0c(0x2ed,&CELL(x,y)->getProp45d550()->getName45c5b0(),0,0,self,NvHE(),NvPoint(x,y),0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						CELL(x,y)->getProp45d550()->u45ce10(0,1,0,NvHE());
						if(aG.operator->()==0)return;
					}
				}
				break;}
//CASE5
			case 5:
				if(::rng.chance406c90(0xf)){
					NvExplDef*expl;
					nv_findByName9d7be0(nv_cfd2cc,"Anomaly_Unstable",expl);
					do{if(nv_show5111e0(0x2ee,0,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					nv_cefc4c->addRecord777a20(nv_cefaa8->createA7930e0(new NvExpl(NvHE(),expl,u45a4c0(),NvHE(),NvPos(-1),NvPos(-1))));
					if(aG.operator->()==0)return;
				}
				break;
			case 6:{
				bool any=false;
				int aR=5;
				NvRect aY;
				NvPos pos=u45a4c0();
				nv_cfd44c.getRect9b4430(pos,aR,aY);
				for(int x=aY.x1;x<aY.x2;x++)for(int y=aY.y1;y<aY.y2;y++){
					if(CELL(x,y)->getEntity45d250().isValid9b7230()&&isHostileTo45aa70(CELL(x,y)->getEntity45d250())&&::rng.chance406c90(10)&&nv_distance406480(pos,x,y)<=aR&&nv_cefc4c->u72a4d0(aR*2,pos,x,y)){
						NvHE target=CELL(x,y)->getEntity45d250();
						nv_cefc4c->zap7273e0(NvPoint(pos),target);
						do{if(nv_show5111e0c(target->isPlayer5c7600()?0x2ef:0x2f0,0,0,0,target,NvHE(),NvPoint(x,y),0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						target->takeDamage5e5520(0,0,0,::rng.rangeInt406d70(nv_c36ed0,nv_c36fec),7,0,0,1,NvHE(),0,8,0,0,0);
						if(target.operator->()){
							if(aG.operator->()==0)return;
							int n=::rng.rangeInt406d70(nv_c36edc,nv_c36ecc);
							NvVecU excl;
							excl.push_back9b9280(7);
							for(int i=0,tries=0;i<n;i++,tries++){
								NvHI part=target->u5e3cb0(0,-1,excl,1,0);
								if(part.isNull9b65d0())break;
								if(part->def9b4350()->f70<=1)continue;
								if(target->isPlayer5c7600()&&part->nested4578a0()==0){
									if(tries>=0x14)break;
									else{i--;continue;}
								}
								do{if(nv_show5111e0d(0x2f1,part->getName571db0(0,0),0,0,target,NvHE(),u45a4c0(),0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								if(isPlayer5c7600())nv_d2c658.add4729d0(0x206,1,"",-1);
								if(part->u457e90()||bc0){
									do{if(nv_show5111e0d(0x45,part->getName571db0(0,0),0,0,target,NvHE(),u45a4c0(),0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
									part->remove57dbe0(target->isPlayer5c7600(),1,1,1);
								}else target->u642940(part,target->isPlayer5c7600(),1,0,2);
							}
						}
						any=true;
					}
				}
				if(any)nv_sound454260(pos,0x126);
				break;}
			case 7:{
				int bD=u45a810();
				if(bD==0)break;
				int a2=10;
				NvVecHI items;
				NvRect b1;
				NvPos pos=u45a4c0();
				nv_cfd44c.getRect9b4430(pos,a2,b1);
				for(int x=b1.x1;x<b1.x2;x++)for(int y=b1.y1;y<b1.y2;y++){
					if(CELL(x,y)->getItem45d8f0().isValid9b7230()&&CELL(x,y)->getItem45d8f0()->nested457880()>=6&&nv_distance406480(pos,x,y)<=a2)items.push_back9b7cf0(CELL(x,y)->getItem45d8f0());
				}
				nv_shuffle9d9fc0(items);
				for(unsigned i=0;i<items.size9b9260();i++){
					if(bD>=items.at9b81f0(i)->nested4578c0()&&nv_cefc4c->isReachable465230(a2*2,pos,items.at9b81f0(i)->u575920())){
						do{if(nv_show5111e0d(0x2f2,items.at9b81f0(i)->getName571db0(0,0),0,0,self,NvHE(),items.at9b81f0(i)->u575920(),0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						items.at9b81f0(i)->u57a190(self,4,0,0);
						break;
					}
				}
				break;}
			case 8:{
				int aE=3;
				NvVecPosL unused;
				NvRect bs;
				NvPos pos=u45a4c0();
				nv_cfd44c.getRect9b4430(pos,aE,bs);
				for(int x=bs.x1;x<bs.x2;x++)for(int y=bs.y1;y<bs.y2;y++){
					if(nv_distance406480(pos,x,y)<=aE&&(!CELL(x,y)->getField4550b0()||CELL(x,y)->u45db70()))CELL(x,y)->trigger45e110(0,1,NvHE());
				}
				break;}
			case 9:{
				NvVecHE ents3;
				NvVecHI2 w3;
				int d9=10;
				NvRect d8;
				NvPos vPos=u45a4c0();
				nv_cfd44c.getRect9b4430(vPos,d9,d8);
				for(int x=d8.x1;x<d8.x2;x++)for(int y=d8.y1;y<d8.y2;y++){
					if(CELL(x,y)->getEntity45d250().isValid9b7230()&&CELL(x,y)->getEntity45d250()!=self&&::rng.chance406c90(5)&&nv_distance406480(vPos,x,y)<=d9&&nv_cefc4c->u72a4d0(d9*2,vPos,x,y))nv_addUnique9d30e0(ents3,CELL(x,y)->getEntity45d250());
					if(CELL(x,y)->getItem45d8f0().isValid9b7230()&&::rng.chance406c90(5)&&nv_distance406480(vPos,x,y)<=d9&&nv_cefc4c->u72a4d0(d9*2,vPos,x,y))nv_addUnique9d30e0b(w3,CELL(x,y)->getItem45d8f0());
				}
				if(::rng.chance406c90(5))ents3.push_back9b80b0(self);
				int link=0;
				NvPos range6(0xf,0x1e);
				NvRect area_;
				NvPos e7;
				for(unsigned i=0;i<ents3.size9b9260();i++){
					nv_cfd44c.getRect9b4430(ents3.at9b81f0(i)->getPosition45a4a0(),range6.y,area_);
					int tries=0;
					do{
						NvVecPosL tmp;
						area_.randomPoint40be30(&e7);
						if(CELLP(e7)->canPlaceEntity66ad20(ents3.at9b81f0(i)->getSize45a360())&&(*::originalTerrain.atPoint9ced70(e7)!=*::caveinEarthTerrain||!ents3.at9b81f0(i)->isPlayer5c7600())&&(tries>100||range6.contains40c190(tmp.size9b9a50()))){tries=-1;break;}
						tries++;
					}while(tries<500);
					if(tries!=-1)continue;
					do{if(nv_show5111e0(ents3.at9b81f0(i)->isPlayer5c7600()?0x2f3:0x2f4,0,0,0,ents3.at9b81f0(i),NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					ents3.at9b81f0(i)->u5ddac0(e7,1);
					nv_cefc4c->u734560(ents3.at9b81f0(i),-2,0);
					if(nv_cefc4c->isVisible4631c0(e7)&&(link!=0||nv_lookup9d7980("Anomaly_Warp",&link)))
						nv_cefc50->new508610(nv_cefc50)->init503b20(link,e7,&nv_d2e20c,0,0,0,9,0);
				}
				for(unsigned j=0;j<w3.size9b9260();j++){
					nv_cfd44c.getRect9b4430(w3.at9b81f0(j)->u575920(),range6.y,area_);
					int tries=0;
					do{
						NvVecPosL tmp;
						area_.randomPoint40be30(&e7);
						if(CELLP(e7)->hasBlockingObject45d7b0()&&(tries>100||range6.contains40c190(tmp.size9b9a50()))){tries=-1;break;}
						tries++;
					}while(tries<500);
					if(tries!=-1)continue;
					do{if(nv_show5111e0d(0x2f5,w3.at9b81f0(j)->getName571db0(0,0),0,0,NvHE(),NvHE(),w3.at9b81f0(j)->u575920(),0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					w3.at9b81f0(j)->u57a0f0(e7,0,0);
					if(nv_cefc4c->isVisible4631c0(e7)&&(link!=0||nv_lookup9d7980("Anomaly_Warp",&link)))
						nv_cefc50->new508610(nv_cefc50)->init503b20(link,e7,&nv_d2e20c,0,0,0,9,0);
				}
				break;}
			case 10:
				if(ai144->u458eb0()){
					int link=0;
					if(::rng.chance406c90(5)){
						NvWL w9;
						for(unsigned i=0;i<nv_d25de0.size9b9260();i++){
							if(nv_d25de0.at9b81f0(i)->b13a)w9.add9ba310(i,10-nv_d25de0.at9b81f0(i)->f68);
						}
						NvRec*rec=nv_d25de0.at9b81f0(w9.pick9ba470());
						NvHE wC=nv_cefc4c->placeEntity6c58c0(rec,getPosition45a4a0(),getGroup45a3f0()->type9b4350(),0,0x22,0xe,0);
						if(wC.isValid9b7230()){
							do{if(nv_show5111e0d(0x2f6,wC->name416f40(),0,0,self,NvHE(),wC->getPosition45a4a0(),0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							if(nv_cefc4c->u4631f0(wC)&&(link!=0||nv_lookup9d7980("Anomaly_Chaotic",&link)))
								nv_cefc50->new508610(nv_cefc50)->init503b20(link,wC->getPosition45a4a0(),&nv_d2e20c,0,0,0,9,0);
						}
					}
					if(::rng.chance406c90(0xf)){
						NvRecI*r;
						do{r=nv_randomRec9d5d00(&nv_d2d1c4);}while(r->f44<=4&&r->f54==0);
						NvHI z6=nv_cefc4c->u6c5400(r,getPosition45a4a0());
						if(z6.isValid9b7230()){
							do{if(nv_show5111e0d(0x2f6,z6->getName571db0(0,0),0,0,self,NvHE(),z6->u575920(),0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							if(nv_cefc4c->isVisible4631c0(z6->u575920())&&(link!=0||nv_lookup9d7980("Anomaly_Chaotic",&link)))
								nv_cefc50->new508610(nv_cefc50)->init503b20(link,z6->u575920(),&nv_d2e20c,0,0,0,9,0);
						}
					}
				}
				break;
			case 11:
				if(::rng.chance406c90(0x21)){
					int amt=::rng.rangeInt406d70(nv_c36e30,nv_c370a8);
					if(CELLP(getPosition45a4a0())->getItem45d8f0().isValid9b7230()&&CELLP(getPosition45a4a0())->getItem45d8f0()->nested457880()==0)
						CELLP(getPosition45a4a0())->getItem45d8f0()->set450460(CELLP(getPosition45a4a0())->getItem45d8f0()->u9b6bf0()+amt);
					else nv_cefc4c->u71e7c0(getPosition45a4a0(),amt,0);
				}
				break;
			case 12:
				if(ai144->u458f30()&&nv_cefc4c->getTurn464270()>=u45acb0(0x2a)+10){
					NvPoint p(getPosition45a4a0());
					string a7(name416f40());
					int eB=h28->type9b4350();
					u637bb0();
					NvVecRP recs3;
					for(unsigned i=0;i<nv_d25de0.size9b9260();i++){
						if(nv_d25de0.at9b81f0(i)->b13b)recs3.push_back9b9d30(nv_d25de0.at9b81f0(i));
					}
					NvRec*rec;
					do{rec=nv_randomRec9d5d00b(&recs3);}while(!nv_cefc4c->findPlaceableNear71c150(p,p,rec->f9c));
					NvHE z7=nv_cefc4c->placeEntity6c58c0(rec,p,eB,0,0x22,0xe,0);
					if(z7.isValid9b7230()){
						z7->u6396a0("Anomaly_Polymorph_Check",0);
						do{if(nv_show5111e0(0x2f7,&a7,&string(nv_d2f798[z7->getFaction45a2c0()]),0,z7,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						int link=0;
						NvVPt*cells=z7->u45d1a0();
						for(unsigned k=0;k<cells->size9b9a50();k++){
							if(nv_cefc4c->isVisible4631c0(cells->at9e7c10(k))&&(link!=0||nv_lookup9d7980("Anomaly_Polymorph",&link)))
								nv_cefc50->new508610(nv_cefc50)->init503b20(link,cells->at9e7c10(k),&nv_d2e20c,0,0,0,9,0);
						}
					}
					return;
				}
				break;
			case 13:{
				NvVecPosL pts;
				bool cA=false;
				int a5=10;
				NvRect d1;
				NvPos pos=u45a4c0();
				nv_cfd44c.getRect9b4430(pos,a5,d1);
				for(int x=d1.x1;x<d1.x2;x++)for(int y=d1.y1;y<d1.y2;y++){
					if(CELL(x,y)->getEntity45d250().isValid9b7230()&&CELL(x,y)->getEntity45d250()!=self&&nv_distance406480(pos,x,y)<=a5&&nv_cefc4c->u72a4d0(a5*2,pos,x,y)){
						NvHE aFp=CELL(x,y)->getEntity45d250();
						if(!aFp->isPlayer5c7600()&&aFp->getField490840()<aFp->u5ca260()){
							aFp->u5dea60(aFp->u5ca260(),0);
							nv_appendUnique9d80a0(pts,aFp->u45d1a0());
						}
						bool aX=false;
						NvVHI*inv=aFp->getInventoryList45ab00();
						for(unsigned i=0;i<inv->size9b9260();i++){
							if(inv->at9b81f0(i)->u9b6bf0()<inv->at9b81f0(i)->u457c80()||inv->at9b81f0(i)->u457d10()){
								inv->at9b81f0(i)->u458340();
								bool at5=inv->at9b81f0(i)->u457d10();
								if(at5)inv->at9b81f0(i)->u5797c0();
								nv_fn9d3020(pts,NvPoint(x,y));
								if(aFp->isPlayer5c7600()){
									cA=true;
									if(inv->at9b81f0(i)->getType44aec0()<=3){
										NvCPart*ats=nv_cec088->u894e70(inv->at9b81f0(i));
										ats->drawStatus4a8e70(0);
										if(at5)ats->u4a9120();
									}else aX=true;
								}
							}
						}
						if(aX)nv_cec08c->reopen8a2ce0(4,NvHE());
						if(cA){
							do{if(nv_show5111e0(0x2f8,0,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						}
					}
					if(CELL(x,y)->getItem45d8f0().isValid9b7230()&&nv_distance406480(pos,x,y)<=a5&&nv_cefc4c->u72a4d0(a5*2,pos,x,y)&&(CELL(x,y)->getItem45d8f0()->u9b6bf0()<CELL(x,y)->getItem45d8f0()->u457c80()||CELL(x,y)->getItem45d8f0()->u457d10())){
						CELL(x,y)->getItem45d8f0()->u458340();
						CELL(x,y)->getItem45d8f0()->u5797c0();
						nv_fn9d3020(pts,NvPoint(x,y));
					}
					if(nv_fn6c10f0(NvPos(x,y))!=-1){
						NvPoint p(x,y);
						if(CELLP(p)->getEffect45d350(6))CELLP(p)->u45dfb0(6);
						else if(nv_cfb844.at9b81f0(nv_cf0fa8.at9b81f0(nv_ce9ff4)->f8)->b58||CELLP(p)->getEntity45d250().isNull9b65d0())CELLP(p)->u66a050(nv_cf0fa8.at9b81f0(nv_ce9ff4)->f8,1,0);
						nv_fn9d3020(pts,p);
					}
				}
				if(!pts.empty9b86e0()){
					int link=0;
					if(nv_lookup9d7980("Anomaly_Paradox",&link)){
						for(unsigned k=0;k<pts.size9b9a50();k++){
							if(nv_cefc4c->isVisible4631c0(pts.at9e7c10(k)))nv_cefc50->new508610(nv_cefc50)->init503b20(link,pts.at9e7c10(k),&nv_d2e20c,0,0,0,9,0);
						}
					}
				}
				break;}
			}
		}
	}
	i98+=u5ca8d0();
	if(nv_cefc4c->u463d40())i98+=nv_cefc4c->u463d40();
	if(!v9c.empty9b86e0()){
		i98+=v9c.front9b7060();
		nv_removeAt9de6f0(v9c,0);
	}
	if(b5){
		NvHI h=u5d25e0(0x88);
		int a=0;
		int bRef;
		if(h.isValid9b7230()&&(nv_cf49f4==0||h->u457fb0()<nv_cf49f4)){
			a=h->u457fb0();
			bRef=h->u457fd0();
		}else if(nv_cf49f4!=0){
			a=nv_cf49f4;
			bRef=nv_cf49f8;
		}
		if(a!=0&&i98>a){
			int n=(i98-a)/bRef;
			i90+=n;
			i98=a;
			nv_d2c658.add4729d0(0x1e9,n,"",-1);
			if(nv_d2c658.get472c70(0x1e9)>=2500)nv_cf45d8.unlock77fbc0(0xe3);
		}
	}
	if(b5&&nv_d28d09&&nv_d22590.at9b81f0(0x34)==0&&u5ca4f0()-u5d1070()>=nv_c36dc0)nv_cefaa8->showOnce793450(0x34,1,0,0,0);
	if(getFaction45a2c0()==0){
		for(unsigned i=0;i<parts.size9b9260();i++){
			if(parts.at9b81f0(i)->u457cf0()&&parts.at9b81f0(i)->u577bd0()&&parts.at9b81f0(i)->u457e10()){
				bool ok=i94>=parts.at9b81f0(i)->u457e10();
				if(ok)i94-=parts.at9b81f0(i)->u457e10();
				else{
					NvCPart*e19=nv_cec088->u894e70(parts.at9b81f0(i));
					if(e19){
						do{nv_cec088->toggle8993e0(e19,1);}while(parts.at9b81f0(i)->u457cf0());
					}
				}
			}
		}
		for(unsigned j=0;j<parts.size9b9260();j++){
			if(parts.at9b81f0(j)->u457cf0()&&parts.at9b81f0(j)->u577bd0()&&(checkFragile603030(parts.at9b81f0(j))||u603280(parts.at9b81f0(j)))){
				if(isPlayer5c7600()){
					nv_cec054->u49ad30();
					nv_cec054->u49adc0(1000);
				}
				break;
			}
		}
	}
	i90+=u5d1070();
	bool aC=false;
	float e5=(float)i90;
	for(unsigned k=0;k<parts.size9b9260();k++){
		if(parts.at9b81f0(k)->u457cf0()&&(!parts.at9b81f0(k)->u577bd0()||!parts.at9b81f0(k)->u457e10())){
			bool ok=nv_isAtLeast456bf0(e5,parts.at9b81f0(k)->u457df0())&&i94>=parts.at9b81f0(k)->u457e10();
			if(ok){
				e5-=parts.at9b81f0(k)->u457df0();
				i94-=parts.at9b81f0(k)->u457e10();
			}else{
				parts.at9b81f0(k)->u4582f0();
				if(b5){
					NvCPart*g22=nv_cec088->u894e70(parts.at9b81f0(k));
					if(g22){
						do{nv_cec088->toggle8993e0(g22,1);}while(parts.at9b81f0(k)->u457cf0());
					}
					aC=true;
				}else u64e7e0(parts.at9b81f0(k));
			}
		}
	}
	i90=nv_round406360(e5);
	if(b5&&aC&&nv_d25450.b0&&u5ca400()>=750&&nv_cefc4c->u714b50()>=30)nv_d25450.u69e700(5,0,0.0f);
	if(b5){
		for(unsigned k=0;k<parts.size9b9260();k++){
			if(parts.at9b81f0(k)->getType44aec0()<=3&&parts.at9b81f0(k)->getEffect457b70(0x76)&&parts.at9b81f0(k)->getEffectValue457be0(0x77)<parts.at9b81f0(k)->getEffectValue457be0(0x76)&&parts.at9b81f0(k)->u457d70()){
				int cost=parts.at9b81f0(k)->getEffectValue457be0(0x78);
				if(i90>=cost&&i90-cost>=u5ca400()/2){
					i90-=cost;
					if(parts.at9b81f0(k)->getEffect457b70(0x77)){
						parts.at9b81f0(k)->getEffect457b70(0x77)->value++;
						if(parts.at9b81f0(k)->getEffectValue457be0(0x77)==parts.at9b81f0(k)->getEffectValue457be0(0x76)){
							do{if(nv_show5111e0b(0x63,parts.at9b81f0(k)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							if(nv_cf45d8.isSlotEmpty46de40(0x125)&&nv_strEq9ccb50(parts.at9b81f0(k)->u457860(),nv_be65e0))nv_cf45d8.unlock77fbc0(0x125);
							nv_sound4541b0(0xfa,0,0);
						}
					}else parts.at9b81f0(k)->addEffect4585a0(new NvEffPair(nv_d2f0f8.at9b81f0(0x77),1));
				}
			}
		}
	}
	int aH=i90-u5ca400();
	if(aH>0){
		i90-=aH;
		u5ded70(aH);
	}
	if(b5&&(nv_cf4a04.at9b81f0(0x10)!=0||nv_cf4a04.at9b81f0(0x11)!=0)){
		NvVecHE3*list=nv_cefc4c->u4636b0();
		if(!list->empty9b86e0()){
			for(int i=list->size9b9260()-1;i>=0;i--){
				if(list->at9b81f0(i).operator->()==0)nv_eraseAt9da940(*list,i);
				else if(list->at9b81f0(i)->getGroup45a3f0()->type9b4350()==3&&nv_cefc4c->u463400(list->at9b81f0(i))){
					NvHE e=list->at9b81f0(i);
					int g31=0x13;
					if(nv_cf4a04.at9b81f0(0x11)!=0&&e->u45ac40(0x27)==0&&u5d4490(e)){
						e->u45b340(new NvEffPair(nv_d2f0f8.at9b81f0(0x27),1));
						NvVecHE g45;
						u5d47c0(e,g45,0);
						for(unsigned j=0;j<g45.size9b9260();j++){
							if(::rng.chance406c90(nv_b989c8[nv_cf4a04.at9b81f0(0x11)])){g31=0x11;break;}
						}
					}else if(nv_cf4a04.at9b81f0(0x10)!=0&&e->u45ac40(0x26)==0&&u5d4490(e)){
						e->u45b340(new NvEffPair(nv_d2f0f8.at9b81f0(0x26),1));
						NvVecHE g49;
						u5d47c0(e,g49,0);
						for(unsigned j=0;j<g49.size9b9260();j++){
							if(::rng.chance406c90(nv_b989bc[nv_cf4a04.at9b81f0(0x10)])){g31=0x10;break;}
						}
					}
					if(g31!=0x13){
						int g51=e->getGroup45a3f0()->type9b4350();
						e->u5fdab0();
						e->removeEffectsA639730(0);
						e->changeFaction5dc780(nv_cefc4c->u463890((g31==0x10)+1),1);
						nv_sound4541b0(0x6b,0,0);
						if(g31==0x11){
							do{if(nv_show5111e0b(0x2aa,nv_intToString4051f0(6),0,0,e,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							if(nv_b95758[e->def9b4350()->f48]){
								do{nv_logPhrase5141b0(0x8f,e->name416f40(),0,0,NvHE(),0);}while(0);
							}
							nv_cf45d8.u780810(e,0x49,0x325);
							if(nv_cefc4c->getPlayer4630f0()->u5cb680(nv_cefc4c->u463890(g51)))nv_cf45d8.unlock77fbc0(0x6c);
							if(e->getFaction45a2c0()==0x19&&e->getAiType45a2a0()==1)nv_cf45d8.unlock77fbc0(0x12b);
							e->u5fd900(1,6);
						}else{
							do{if(nv_show5111e0(0x2a9,0,0,0,e,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							nv_cf45d8.u780810(e,0x49,0x324);
							NvAIEnt*h49=e->ai45b590()->u4590f0()->u57f140(new NvXGroup(0x42));
							h49->f4=nv_cefc4c->getTurn464270()+10;
							h49->v8.push_back9b3020(NvPos(g51));
						}
					}
				}
			}
		}
	}
	int a1=nv_cefc4c->u71ac50(self);
	if(a1!=0){
		if(::rng.chance406c90(a1)){
			int h59=h28->type9b4350();
			removeEffectsA639730(0);
			changeFaction5dc780(nv_cefc4c->u463890(2),1);
			if(nv_cefc4c->u4631f0(self)){
				nv_sound4541b0(0x6b,0,0);
				do{if(nv_show5111e0(0x2ac,0,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
			}
			nv_cf45d8.u780810(self,0x49,0x379);
			if(nv_d2c658.get472c70(0x379)==10)nv_cf45d8.unlock77fbc0(0xbc);
			NvAIEnt*hiD=ai144->u4590f0()->u57f140(new NvXGroup(0x42));
			hiD->f4=nv_cefc4c->getTurn464270()+0x14;
			hiD->v8.push_back9b3020(NvPos(h59));
			if(nv_d1e860.u46f4b0(1)&&nv_d1e888->f4!=0x23&&nv_d1e888->f4!=0x22&&::rng.chance406c90(0x14)&&nv_cefc4c->u729de0()){
				string msg(nv_be65f8);
				do{
					nv_cf1080.set451400(1);
					if(0)nv_sound4541b0(-1,0,0);
					do{if(nv_show5111e0(0x324,&msg,0,0,NvHE(),NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					nv_cec0b4->scrollToEnd7b4f10();
				}while(0);
				do{nv_logPhrase5141b0b(0x90,0,0,0,NvHE(),0);}while(0);
			}
		}
		u45b340(new NvEffPair(nv_d2f0f8.at9b81f0(0x24),1));
	}
	NvHI fp;
	for(unsigned i=0;i<parts.size9b9260();i++){
		if(parts.at9b81f0(i)->u457cf0()&&parts.at9b81f0(i)->u457f90()){
			NvHI part=parts.at9b81f0(i);
			if((getFaction45a2c0()==0||getFaction45a2c0()==0x30)&&part->nested4578a0()==2&&(checkFragile603030(part)||u603280(part))){
				if(isPlayer5c7600()){
					nv_cec054->u49ad30();
					nv_cec054->u49adc0(1000);
				}
				continue;
			}
			switch(part->u457f90()){
			case 0xc:case 0xd:
				if(b5)u5d3700();
				break;
			case 0x1f:
				if(nv_d1e888->f4==0x22){
					do{if(nv_show5111e0b(0x29e,part->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					if(isPlayer5c7600())nv_sound4541b0(0xa5,0,0);
					part->remove57dbe0(1,0,1,1);
				}
				break;
			case 0x94:
				if(b5&&::rng.chance406c90(part->u457fb0())){
					for(unsigned j=0;j<parts.size9b9260();j++){
						if(nv_cf4830.at9b81f0(parts.at9b81f0(j)->nested457820())==0&&parts.at9b81f0(j)->def9b4350()->f94!=3){
							nv_cf45d8.u77ffb0(parts.at9b81f0(j)->nested457820(),0);
							do{if(nv_show5111e0(0x5e,&part->getName571db0(0,0),&parts.at9b81f0(j)->getName571db0(0,0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							nv_cec08c->reopen8a2ce0(4,NvHE());
							nv_cf4d6c++;
							if(nv_cf4d6c==10)nv_cf45d8.unlock77fbc0(0xe7);
							break;
						}
					}
				}
				break;
			case 0x95:
				if(b5){
					bool any=false;
					for(unsigned j=0;j<parts.size9b9260();j++){
						if(nv_cf4830.at9b81f0(parts.at9b81f0(j)->nested457820())==0&&parts.at9b81f0(j)->def9b4350()->f94!=3){
							nv_cf45d8.u77ffb0(parts.at9b81f0(j)->nested457820(),0);
							string msg=parts.at9b81f0(j)->getName571db0(0,0)+nv_be664c;
							do{if(nv_show5111e0b(0x5f,msg,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							nv_cf4d6c++;
							any=true;
						}
					}
					if(any)nv_cec08c->reopen8a2ce0(4,NvHE());
					NvVecHI3 found;
					int bB=u5c7d30();
					NvRect d7;
					NvPos pos=u45a4c0();
					nv_cfd44c.getRect9b4430(pos,bB,d7);
					for(int x=d7.x1;x<=d7.x2;x++)for(int y=d7.y1;y<=d7.y2;y++){
						if(nv_cefc4c->u463380(x,y)){
							if(CELL(x,y)->getItem45d8f0().isValid9b7230()&&nv_cf4830.at9b81f0(CELL(x,y)->getItem45d8f0()->nested457820())==0&&CELL(x,y)->getItem45d8f0()->def9b4350()->f94!=3)found.push_back9b7cf0(CELL(x,y)->getItem45d8f0());
							if(CELL(x,y)->getEntity45d250().isValid9b7230()){
								NvVHI*inv=CELL(x,y)->getEntity45d250()->getInventoryList45ab00();
								for(unsigned k=0;k<inv->size9b9260();k++){
									if(nv_cf4830.at9b81f0(inv->at9b81f0(k)->nested457820())==0&&inv->at9b81f0(k)->getType44aec0()<=3&&inv->at9b81f0(k)->def9b4350()->f94!=3)found.push_back9b80b0(inv->at9b81f0(k));
								}
							}
						}
					}
					for(unsigned k=0;k<found.size9b9260();k++){
						if(nv_cf4830.at9b81f0(found.at9b81f0(k)->nested457820())==0){
							nv_cf45d8.u77ffb0(found.at9b81f0(k)->nested457820(),0);
							string msg=found.at9b81f0(k)->getName571db0(0,0);
							if(found.at9b81f0(k)->u457b50().isValid9b7230())msg+=nv_be665c+found.at9b81f0(k)->u457b50()->name416f40()+nv_be65f4;
							do{if(nv_show5111e0b(0x5f,msg,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							nv_cf4d6c++;
						}
						nv_cec054->u8195e0(found.at9b81f0(k));
					}
					if(any||!found.empty9b86e0()){
						nv_sound4541b0(0xf0,0,0);
						if(nv_cf4d6c>=10)nv_cf45d8.unlock77fbc0(0xe7);
					}
				}
				break;
			case 0x96:
				if(b5){
					if(nv_cefc4c->getTurn464270()>=part->u45cb30()){
						part->u44fc60(nv_cefc4c->getTurn464270()+nv_d2b4cc.random40c130());
						int best=nv_caf164;
						NvVecU2 a9;
						NvVecU2 cands;
						NvReq*hub4;
						for(unsigned r=0;r<nv_d2d1c4.size9b9260();r++){
							if(!nv_d2d1c4.at9b81f0(r)->v260.empty9b86e0()&&nv_cf4844.at9b81f0(r)==0){
								a9.clear9bac80();
								for(unsigned k=0;k<nv_d2d1c4.at9b81f0(r)->v260.size9b9260();k++){
									cands.clear9bac80();
									hub4=nv_d2d1c4.at9b81f0(r)->v260.at9b81f0(k);
									switch(hub4->f0){
									case 0:
										switch(hub4->f4){
										case 0:
											for(unsigned k24=0;k24<nv_cf4a98.size9b9260();k24++){
												if(nv_cf4a98.at9b81f0(k24)!=0&&nv_d2d1c4.at9b81f0(k24)->ff0==hub4->f8&&k24!=r)cands.push_back9b9d30(k24);
											}
											break;
										case 1:
											for(unsigned k27=0;k27<nv_cf4a98.size9b9260();k27++){
												if(nv_cf4a98.at9b81f0(k27)!=0&&nv_d2d1c4.at9b81f0(k27)->getValue457330(hub4->f8)&&k27!=r)cands.push_back9b9d30(k27);
											}
											break;
										}
										break;
									case 1:
										for(unsigned k30=0;k30<nv_cf4a98.size9b9260();k30++){
											if(nv_cf4a98.at9b81f0(k30)!=0&&nv_containsRecord9db330(&nv_d2d1c4.at9b81f0(k30)->v250,hub4->f4)&&k30!=r)cands.push_back9b9d30(k30);
										}
										break;
									case 2:
										if(nv_cf4a98.at9b81f0(hub4->f4)!=0)cands.push_back9b9d30(hub4->f4);
										break;
									}
									if(cands.size9b9260()>=hub4->fc){
										for(int n=0;n<hub4->fc;n++)a9.push_back9b9280(nv_popRandom9de500(cands));
									}else goto nextR;
								}
								best=r;
								break;
							}
nextR:;
						}
						if(best!=nv_caf164){
							if(nv_cf45d8.u780380(best,8))nv_cec08c->reopen8a2ce0(4,NvHE());
							string list;
							for(unsigned n=0;n<a9.size9b9260();n++){
								if(n!=0)list+=nv_be6660;
								list+=nv_cf4830.at9b81f0(a9.at9b81f0(n))!=0?nv_d2d1c4.at9b81f0(a9.at9b81f0(n))->name24:string(nv_be6664);
							}
							do{if(nv_show5111e0(0x124,&part->getName571db0(0,0),&nv_d2d1c4.at9b81f0(best)->name24,&list,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							if(nv_d2d1c4.at9b81f0(best)->f54==0){
								do{nv_logPhrase5141b0c(0x5c,part->getName571db0(0,0),&nv_d2d1c4.at9b81f0(best)->name24,0,NvHE(),0);}while(0);
							}
							if(nv_d2d1c4.at9b81f0(best)->b20a)nv_cf45d8.unlock77fbc0(0x12a);
							nv_sound4541b0(nv_d2d1c4.at9b81f0(best)->f54?0xf8:0xf9,0,0);
							nv_cec054->u49adc0(500);
						}
					}
					int his=u5c7d30();
					NvRect g4;
					NvPos pos=u45a4c0();
					nv_cfd44c.getRect9b4430(pos,his,g4);
					for(int x=g4.x1;x<=g4.x2;x++)for(int y=g4.y1;y<=g4.y2;y++){
						if(nv_cefc4c->u463380(x,y)){
							if(CELL(x,y)->getItem45d8f0().isValid9b7230()&&nv_cf4a98.at9b81f0(CELL(x,y)->getItem45d8f0()->nested457820())==0&&nv_cf4830.at9b81f0(CELL(x,y)->getItem45d8f0()->nested457820())!=0)nv_cf4a98.at9b81f0(CELL(x,y)->getItem45d8f0()->nested457820())=1;
							if(CELL(x,y)->getEntity45d250().isValid9b7230()){
								NvVHI*inv=CELL(x,y)->getEntity45d250()->getInventoryList45ab00();
								for(unsigned k=0;k<inv->size9b9260();k++){
									if(nv_cf4a98.at9b81f0(inv->at9b81f0(k)->nested457820())==0&&nv_cf4830.at9b81f0(inv->at9b81f0(k)->nested457820())!=0)nv_cf4a98.at9b81f0(inv->at9b81f0(k)->nested457820())=1;
								}
							}
						}
					}
				}
				break;
			case 0x97:
				if(ib0!=0&&::rng.rangeInt406d70(0.0f,nv_ba0a88)<=part->u457fb0()){
					nv_fn9d0690(&ib0,1,0);
					if(b5){
						do{if(nv_show5111e0(0x60,&part->getName571db0(0,0),&nv_intToString4051f0(ib0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						nv_d2c658.add4729d0(0x1c2,1,"",-1);
						if(nv_d2c658.get472c70(0x1c2)==5)nv_cf45d8.unlock77fbc0(0x17);
						if(part->u9b6bf0()<=3){
							do{if(nv_show5111e0(0x61,&part->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							part->remove57dbe0(1,0,7,1);
							nv_cec054->u49adc0(2000);
						}else{
							part->u458310(3);
							NvCPart*k50=nv_cec088->u894e70(part);
							if(k50)k50->drawStatus4a8e70(1);
						}
						if(ib0==0)nv_cec054->u49adc0(2000);
					}
				}
				break;
			case 0x98:
				if(part->u577a90()>=nv_ba0b40[part->u457fb0()]&&nv_d1e860.u46f4b0(1)&&nv_d1e888->f4!=0x23&&::rng.chance406c90(nv_ba0b50[part->u457fb0()])&&(isPlayer5c7600()||u45aaa0(nv_cefc4c->getPlayer4630f0())&&nv_cefc4c->u463400(self))){
					NvVecPtA pts[10];
					NvIntGrid2*b3=nv_cefc4c->u463830();
					NvS34Grid*k51=nv_cefc4c->u463e70();
					int g0=part->u457fb0();
					NvRect rc8;
					nv_cfd44c.getRect9b4430(v30.at9e7c10(0),0x19,rc8);
					for(int x=rc8.x1;x<=rc8.x2;x++)for(int y=rc8.y1;y<=rc8.y2;y++){
						if(CELL(x,y)->u45ddf0()&&nv_ba0aa0[0][g0]&&k51->at9d2c30(x,y)->f24==nv_caf164)pts[0].push_back9b3020(NvPos(x,y));
						if(CELL(x,y)->isEdge45dc30()&&CELL(x,y)->isShortcut45dc50()&&nv_ba0aa0[1][g0]&&!nv_cefc4c->u463e90(NvPos(x,y)))pts[1].push_back9b3020(NvPos(x,y));
						if(*b3->at9ceda0(x,y)==0){
							if(CELL(x,y)->getItem45d8f0().isValid9b7230()&&nv_ba0aa0[2][g0]&&CELL(x,y)->getItem45d8f0()->nested457880()>=6&&k51->at9d2c30(x,y)->f10==nv_caf164&&k51->at9d2c30(x,y)->f24==nv_caf15c)pts[2].push_back9b3020(NvPos(x,y));
							if(CELL(x,y)->u66b120()&&!nv_cefc4c->isKnown463130(x,y)){
								NvVVMarker*k54=nv_cefc4c->u463ec0();
								for(unsigned k=0;k<k54->at9b8070(0).size9b9260();k++){
									if(k54->at9b8070(0).at9b81f0(k)->pos8.eq409cb0(x,y))goto nextY;
								}
								if(nv_ba0aa0[3][g0])pts[3].push_back9b3020(NvPos(x,y));
								if(nv_ba0aa0[4][g0]&&CELL(x,y)->getProp45d550()->def9b8f00()->ff8==5)pts[4].push_back9b3020(NvPos(x,y));
							}
						}
nextY:;
					}
					if(nv_ba0aa0[9][g0]){
						NvVMk*k57=nv_cefc4c->u462e10();
						for(unsigned k=0;k<k57->size9b9260();k++){
							if(!k57->at9b81f0(k)->bd&&k57->at9b81f0(k)->h14.isNull9b65d0()&&k57->at9b81f0(k)->h18.isNull9b65d0()&&rc8.contains40b750(*k57->at9b81f0(k))&&!nv_b90480[k57->at9b81f0(k)->h8->f4])pts[9].push_back9b32e0(*k57->at9b81f0(k));
						}
					}
					NvVEntRec*ents4=nv_cf6428.u45ee50();
					for(unsigned k=0;k<ents4->size9b9260();k++){
						switch(ents4->at9b81f0(k)->f0){
						case 2:
							if(nv_ba0aa0[5][g0]&&rc8.contains40b750(ents4->at9b81f0(k)->h4->getPosition45a4a0()))pts[5].push_back9b32e0(ents4->at9b81f0(k)->h4->getPosition45a4a0());
							break;
						case 4:
							if(nv_ba0aa0[6][g0]&&rc8.contains40b750(ents4->at9b81f0(k)->h4->getPosition45a4a0()))pts[6].push_back9b32e0(ents4->at9b81f0(k)->h4->getPosition45a4a0());
							break;
						case 6:
							if(nv_ba0aa0[7][g0]&&rc8.contains40b750(ents4->at9b81f0(k)->h4->getPosition45a4a0()))pts[7].push_back9b32e0(ents4->at9b81f0(k)->h4->getPosition45a4a0());
							break;
						case 0:
							if(nv_ba0aa0[8][g0]&&rc8.contains40b750(ents4->at9b81f0(k)->h4->getPosition45a4a0())&&!nv_cefc4c->u463ee0(2,ents4->at9b81f0(k)->h4->getPosition45a4a0()))pts[8].push_back9b32e0(ents4->at9b81f0(k)->h4->getPosition45a4a0());
							break;
						}
					}
					NvWL e2;
					for(int k=0;k<10;k++){
						if(!pts[k].empty9b86e0())e2.add9ba310(k,nv_ba0aa0[k][g0]);
					}
					if(nv_cf4744!=0)e2.remove9bab80(0);
					if(e2.total9b81d0()){
						int lo4=e2.pick9ba470();
						int loA=nv_randomIndex9d9230(pts[lo4]);
						switch(lo4){
						case 0:{
							NvPoint p(pts[lo4].at9e7c10(loA));
							CELLP(p)->getProp45d550()->u65f170();
							nv_cefc4c->opw3_724420(p.x,p.y);
							nv_cec054->label813050(1,CELLP(p)->getProp45d550(),0,0,0);
							nv_cefc4c->u9e29b0(&nv_cefc4c->f720,CELLP(p)->getProp45d550());
							string m14=CELLP(p)->getProp45d550()->getName45c5b0()+nv_be6670;
							do{if(nv_show5111e0(0x1d6,&string(nv_be667c),&m14,0,NvHE(),NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							break;}
						case 1:{
							NvPoint p(pts[lo4].at9e7c10(loA));
							nv_cefc4c->u734d60(p);
							nv_cefc4c->u4647a0(p,1);
							nv_cec054->labelAccess80e3a0(1,p);
							string m27(nv_be6684);
							do{if(nv_show5111e0(0x1d6,&string(nv_be66a0),&m27,0,NvHE(),NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							break;}
						case 2:{
							NvPoint p(pts[lo4].at9e7c10(loA));
							nv_cefc4c->u4647a0(p,0);
							nv_cec054->addMemoryLabel812950(p,6);
							string m31=CELLP(p)->getItem45d8f0()->getName571db0(0,0)+nv_be66a8;
							do{if(nv_show5111e0(0x1d6,&string(nv_be66b4),&m31,0,NvHE(),NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							break;}
						case 3:case 4:{
							NvPoint p(pts[lo4].at9e7c10(loA));
							NvVMarker&m34=nv_cefc4c->u463ec0()->at9b8070(0);
							m34.push_back9b7cf0(nv_cefaa8->createC793190());
							m34.back9b6540()->u6c20b0(0,p,CELLP(p)->getProp45d550()->def9b8f00()->ff8);
							nv_cec034->u987de0();
							string m38=CELLP(p)->getProp45d550()->getName45c5b0()+nv_be66bc;
							do{if(nv_show5111e0(0x1d6,&string(nv_be66c8),&m38,0,NvHE(),NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							break;}
						case 5:case 6:case 7:case 8:{
							int gA,m51;
							switch(lo4){
							case 5:gA=4;m51=2;break;
							case 6:gA=6;m51=4;break;
							case 7:gA=8;m51=6;break;
							case 8:gA=2;m51=0;
							}
							NvPoint p9(pts[lo4].at9e7c10(loA));
							NvVMarker&myY=nv_cefc4c->u463ec0()->at9b8070(gA);
							myY.push_back9b7cf0(nv_cefaa8->createC793190());
							myY.back9b6540()->u6c20b0(gA,p9,-1);
							nv_cec034->u987de0();
							string nLo=nv_cf25d8[m51]+nv_be66d0;
							do{if(nv_show5111e0(0x1d6,&string(nv_be66dc),&nLo,0,NvHE(),NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							break;}
						case 9:{
							NvMk*ok5=nv_cefc4c->getZone462e30(pts[lo4].at9e7c10(loA));
							nv_cefc4c->announceMachine71dd30(ok5->h8.id);
							nv_cefc4c->u4647a0(*ok5,1);
							ok5->bd=1;
							nv_cec054->labelAccess80e3a0(1,*ok5);
							string old=nv_cfaca0[ok5->h8->f4]+nv_be66e4;
							do{if(nv_show5111e0(0x1d6,&string(nv_be66f8),&old,0,NvHE(),NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							break;}
						}
						part->setActive5791a0(1);
						nv_d2c658.add4729d0(0x3d3,1,"",-1);
						if(nv_d2c658.vals->at9b81f0(0x3d3)==0x32)nv_cf45d8.unlock77fbc0(0xa9);
						nv_d2c658.add4729d0(lo4+0x3d4,1,"",-1);
					}
				}
				break;
			case 0x1b:
				if(nv_d1e888->f4==0x21&&part->u577a90()&&part->u577a90()%part->u457fb0()==0&&isPlayer5c7600()){
					NvIntGrid2*pTo=nv_cefc4c->u463830();
					NvS34Grid*q12=nv_cefc4c->u463e70();
					for(int x=0;x<nv_cfd44c.getWidth9fcd80();x++)for(int y=0;y<nv_cfd44c.getHeight9b8f00();y++){
						if(CELL(x,y)->getItem45d8f0().isValid9b7230()&&CELL(x,y)->getItem45d8f0()->nested457880()>=6&&!CELL(x,y)->getItem45d8f0()->def9b4350()->b271&&q12->at9d2c30(x,y)->f24==nv_caf15c){
							nv_cf45d8.u77ffb0(CELL(x,y)->getItem45d8f0()->nested457820(),0);
							nv_cefc4c->opw3_7243c0(x,y,0);
						}
					}
					if(!nv_stringToInt405610(nv_d1e860.getEntryText46f6d0(nv_be6700))){
						nv_d1e860.setEntryText46f700(nv_be6720,nv_be671c);
						nv_cefc4c->u744800(1);
						do{
							nv_cf1080.set451400(1);
							if(0)nv_sound4541b0(-1,0,0);
							do{if(nv_show5111e0(0x324,&string(nv_be6768),0,0,NvHE(),NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							nv_cec0b4->scrollToEnd7b4f10();
						}while(0);
						do{nv_logPhrase5141b0b(0x205,0,0,0,NvHE(),0);}while(0);
					}
				}
				break;
			case 0x99:
				if(i90>=part->u457fd0()&&i94<u5ca670()){
					bool ok=true;
					if(ai144!=0&&(i94>=u5ca670()/2||i90<u5ca400()/2))ok=false;
					if(ok&&!u5deb40(part->u457fb0()))u45b1b0(part->u457fd0());
				}
				break;
			case 0x9a:
				if(i94!=0&&i90<u5ca400()){
					i94--;
					nv_fn9d06d0(&i90,part->u457fb0(),u5ca400());
				}
				break;
			case 0x9b:
				if(i98>0)u5ded70(i98/part->u457fb0());
				break;
			case 0x9c:{
				bool any=part->u457fd0();
				NvRect rc0;
				int c_=part->u457fb0();
				nv_cfd44c.getRect9b4430(v30.at9e7c10(0),c_,rc0);
				for(int x=rc0.x1;x<=rc0.x2;x++)for(int y=rc0.y1;y<=rc0.y2;y++){
					if(CELL(x,y)->getItem45d8f0().isValid9b7230()&&CELL(x,y)->getItem45d8f0()->nested457880()==0&&(any||nv_cefc4c->u463380(x,y))&&nv_distance406480b(v30.at9e7c10(0).x,v30.at9e7c10(0).y,x,y)<=c_&&!u5e2590(CELL(x,y)->getItem45d8f0(),NvPos(x,y),0))break;
				}
				break;}
			case 0x9d:{
				int range=part->u457fb0();
				nv_clearDijkstra4faf40();
				nv_cfe568.u40ca20(getPosition45a4a0(),range*2+2,&nv_cfe5e8,0);
				if(nv_d15e58.empty9b86e0()){
					nv_logWarning404e50(nv_be67b4,nv_be673c);
				}else{
					if(CELLP(getPosition45a4a0())->u45d230()){
						int amt=nv_maxInt9cdb60(CELLP(getPosition45a4a0())->u44aec0(),1);
						CELLP(getPosition45a4a0())->u45de40();
						if(CELLP(getPosition45a4a0())->getItem45d8f0().isValid9b7230()&&CELLP(getPosition45a4a0())->getItem45d8f0()->nested457880()==0)
							CELLP(getPosition45a4a0())->getItem45d8f0()->set450460(CELLP(getPosition45a4a0())->getItem45d8f0()->u9b6bf0()+amt);
						else nv_cefc4c->u71e7c0(getPosition45a4a0(),amt,0);
					}
					NvVecPt path2(nv_d15e58);
					NvPoint cur;
					for(unsigned k=1;k<path2.size9b9a50();k++){
						if(CELLP(path2.at9e7c10(k))->u45d230()&&nv_nextLineStep40ff60(NvPoint(path2.at9e7c10(k)),getPosition45a4a0(),&cur)){
							bool ok=true;
							if(!CELLP(cur)->u45da50()){
								ok=false;
								NvVecPt q42;
								if(nv_commonNeighbors4fac50(path2.at9e7c10(k),cur,q42)){
									NvVecF dists;
									for(unsigned q48=0;q48<q42.size9b9a50();q48++){
										if(CELLP(q42.at9e7c10(q48))->u45da50())dists.push_back9b84b0(nv_distance40a450(q42.at9e7c10(q48),getPosition45a4a0()));
										else nv_eraseStep9d7300(q42,q48);
									}
									if(!dists.empty9b86e0()){
										int best=nv_fn9d7d70(dists);
										if(dists.at9b81f0(best)<nv_distance40a450(path2.at9e7c10(k),getPosition45a4a0())){
											cur=q42.at9e7c10(best);
											ok=true;
										}
									}
								}
							}
							if(ok){
								CELLP(path2.at9e7c10(k))->u66b740(CELLP(cur));
								if(cur.test409b90(getPosition45a4a0())){
									int amt=nv_maxInt9cdb60(CELLP(cur)->u44aec0(),1);
									CELLP(cur)->u45de40();
									if(CELLP(cur)->getItem45d8f0().isValid9b7230()&&CELLP(cur)->getItem45d8f0()->nested457880()==0)
										CELLP(cur)->getItem45d8f0()->set450460(CELLP(cur)->getItem45d8f0()->u9b6bf0()+amt);
									else nv_cefc4c->u71e7c0(cur,amt,0);
								}
							}
						}
					}
				}
				break;}
				break;
			case 0x9f:{
				bool any=false;
				NvVecPt cells;
				nv_surrounding4faaf0(getPosition45a4a0(),cells);
				cells.push_back9b32e0(getPosition45a4a0());
				for(unsigned k=0;k<cells.size9b9a50();k++){
					if(CELLP(cells.at9e7c10(k))->getItem45d8f0().isValid9b7230()&&CELLP(cells.at9e7c10(k))->getItem45d8f0()->nested457880()!=0&&CELLP(cells.at9e7c10(k))->getItem45d8f0()->nested457880()!=3){
						NvHI q49=CELLP(cells.at9e7c10(k))->getItem45d8f0();
						int vA=q49->u577600(part->u457fb0());
						if(vA!=0){
							nv_cec054->u8195a0(cells.at9e7c10(k),q49->u457a30(),8);
							q49->remove57dbe0(1,0,1,1);
							nv_cefc4c->u71e7c0(cells.at9e7c10(k),vA,0);
							any=true;
						}
					}
				}
				if(any)nv_sound454260(getPosition45a4a0(),0xa8);
				break;}
				break;
			case 0xa1:
				if(fp.isNull9b65d0()||part->u457fb0()>fp->u457fb0())fp=part;
				break;
			case 0xa2:
				if(::rng.rangeInt406d70(0.0f,nv_ba0b60)<=part->u457fb0()){
					NvVecHI3 rb1;
					for(unsigned j=0;j<parts.size9b9260();j++){
						if(parts.at9b81f0(j)->u457d10()&&nv_cf4830.at9b81f0(parts.at9b81f0(j)->nested457820())!=0)rb1.push_back9b80b0(parts.at9b81f0(j));
					}
					for(unsigned j=0;j<rb1.size9b9260();j++){
						if(rb1.at9b81f0(j)->getType44aec0()!=4)nv_moveElement9da1f0(rb1,j,0);
					}
					if(!rb1.empty9b86e0()){
						for(unsigned j=0;j<rb1.size9b9260();j++){
							if(rb1.at9b81f0(j)->u577530()){
								rb1.at9b81f0(j)->u5797c0();
								if(b5){
									do{if(nv_show5111e0(0x72,&rb1.at9b81f0(j)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
									nv_d2c658.add4729d0(0xdc,1,"",-1);
									nv_d2c658.add4729d0(0xdd,1,"",-1);
									nv_sound4541b0(0xda,0,0);
									nv_cec054->u49adc0(2000);
									if(rb1.at9b81f0(j)->getType44aec0()==4)nv_cec08c->reopen8a2ce0b(5,rb1.at9b81f0(j));
									else{
										nv_cec088->u896a80(rb1.at9b81f0(j));
										if(rb1.at9b81f0(j)->nested4578c0()>1)nv_cec088->u896820(rb1.at9b81f0(j));
									}
								}
								goto doneA2;
							}
						}
						if(b5){
							do{if(nv_show5111e0(0x73,&rb1.front9b7060()->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							nv_cec054->u49adc0(2000);
						}
					}
doneA2:;
				}
				break;
			case 0xa3:
				if(::rng.rangeInt406d70(0.0f,nv_ba0b60)<=part->u457fb0()){
					NvVecHI3 rb4;
					for(unsigned j=0;j<parts.size9b9260();j++){
						if(parts.at9b81f0(j)->u415ee0()&&nv_cf4830.at9b81f0(parts.at9b81f0(j)->nested457820())!=0)rb4.push_back9b80b0(parts.at9b81f0(j));
					}
					for(unsigned j=0;j<rb4.size9b9260();j++){
						if(rb4.at9b81f0(j)->getType44aec0()!=4)nv_moveElement9da1f0(rb4,j,0);
					}
					if(!rb4.empty9b86e0()){
						for(unsigned j=0;j<rb4.size9b9260();j++){
							bool rc1=false;
							for(unsigned rd9=0;rd9<parts.size9b9260();rd9++){
								if(parts.at9b81f0(rd9)->nested457820()==rb4.at9b81f0(j)->nested457820()&&parts.at9b81f0(rd9)!=rb4.at9b81f0(j)){rc1=true;break;}
							}
							if(rc1){
								if(b5){
									do{if(nv_show5111e0(0x75,&part->getName571db0(0,0),&rb4.at9b81f0(j)->getName571db0(0,0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
									nv_d2c658.add4729d0(0xdc,1,"",-1);
									nv_d2c658.add4729d0(0xde,1,"",-1);
									if(nv_d2c658.get472c70(0xde)==3)nv_cf45d8.unlock77fbc0(0xe4);
									nv_sound4541b0(0xda,0,0);
								}
								rb4.at9b81f0(j)->u458390(0);
								if(b5){
									nv_cec054->u49adc0(2000);
									if(rb4.at9b81f0(j)->getType44aec0()==4)nv_cec08c->reopen8a2ce0b(5,rb4.at9b81f0(j));
									else{
										nv_cec088->u896a80(rb4.at9b81f0(j));
										if(rb4.at9b81f0(j)->nested4578c0()>1)nv_cec088->u896820(rb4.at9b81f0(j));
									}
								}
								goto doneA3;
							}
						}
						if(b5){
							do{if(nv_show5111e0(0x76,&rb4.front9b7060()->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							nv_cec054->u49adc0(2000);
						}
					}
doneA3:;
				}
				break;
			case 0xa6:
				if(part->u458220()){
					if(b5&&part->u45cb30()){
						NvPoint re9;
						if(nv_cefc4c->u71bc10(getPosition45a4a0(),&re9)){
							NvEffPair*rh3=part->getEffect457b70(0x51);
							if(rh3==0){
								nv_logError404f10(nv_be67f8,getName45a280()+nv_be67f0+nv_pointToString40a4a0(getPosition45a4a0())+nv_be67c8+part->u457860());
							}else{
								NvHI rif=nv_cefc4c->u6c5400(nv_d2d1c4.at9b81f0(rh3->value),re9);
								if(rif.isValid9b7230()){
									if(!part->u4584c0())part->u458630(rh3);
									do{if(nv_show5111e0(0x65,&part->getName571db0(0,0),&rif->getName571db0(0,0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
									nv_cec088->u896a80(part)->moveLabel890c90();
								}
							}
						}
					}
				}else{
					NvHI rj5;
					if(b5&&CELLP(getPosition45a4a0())->getItem45d8f0().isValid9b7230()&&CELLP(getPosition45a4a0())->getItem45d8f0()->nested457880()==5&&CELLP(getPosition45a4a0())->getItem45d8f0()->def9b4350()->u457410()!=0xb&&u5d56d0(CELLP(getPosition45a4a0())->getItem45d8f0()->def9b4350()).isValid9b7230())
						rj5=CELLP(getPosition45a4a0())->getItem45d8f0();
					if(rj5.isValid9b7230()||CELLP(getPosition45a4a0())->u45dcf0()&&!CELLP(getPosition45a4a0())->getProp45d550()->u44b020()->u65cf50(h28->type9b4350())&&((!b5&&!u45aaa0(nv_cefc4c->getPlayer4630f0()))?true:CELLP(getPosition45a4a0())->getProp45d550()->u45cbd0())&&(!b5||i94>=5)){
						NvHP prop;
						if(rj5.isNull9b65d0())prop=CELLP(getPosition45a4a0())->getProp45d550();
						if(rj5.isNull9b65d0()&&prop->def9b8f00()->f154==0){
							if(b5&&nv_d1d9c0.addUnique49b830(prop))nv_7b1750(0x3e,prop->getName45c5b0(),0,0,NvHE(),NvHE(),0);
						}else if(rj5.isValid9b7230()||::rng.chance406c90(part->nested457900()*10+0x28)){
							NvRecI*d=rj5.isValid9b7230()?rj5->def9b4350():prop->def9b8f00()->f154;
							int at=d->u457410()==0xb?prop->u44b020()->f14:0;
							if(prop.isValid9b7230())CELLP(prop->u4184d0())->removeProp66c100(0,4);
							int to8=nv_caf164;
							if(d->u457410()!=0xb&&b5){
								NvHI h=u5d56d0(d);
								if(h.isValid9b7230()){
									NvEffPair*e=h->getEffect457b70(0x51);
									if(e==0)h->addEffect4585a0(new NvEffPair(nv_d2f0f8.at9b81f0(0x51),d->f0));
									h->u458580();
									to8=d->f0;
									if(b5)nv_cec088->u896a80(h)->moveLabel890c90();
								}
							}
							NvHI gC;
							if(to8==nv_caf164){
								if(u45a810()>=d->f4c)gC=nv_cefc4c->u6c51d0(d,self,0,0);
								else gC=nv_cefc4c->u6c5400(d,getPosition45a4a0());
							}
							if(gC.isValid9b7230()||to8!=nv_caf164){
								if(at!=0&&gC.isValid9b7230()){
									NvEffPair*e=gC->getEffect457b70(0x4b);
									e->value=at;
									if(gC->u457b50()==self){
										NvCRow*tos=nv_cec08c->u8a1fd0(gC,0);
										if(tos){
											tos->clearRow428ac0(7,0,tos->cleanup44b0d0()-7);
											tos->u4aa510();
										}
									}
								}
								if(rj5.isValid9b7230()){
									do{if(nv_show5111e0(0x64,&part->getName571db0(0,0),&rj5->getName571db0(0,0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								}else if(gC.isValid9b7230()){
									do{if(nv_show5111e0(b5?0x66:(u45aaa0(nv_cefc4c->getPlayer4630f0())?0x6a:0x6e),&gC->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								}else{
									do{if(nv_show5111e0(b5?0x69:(u45aaa0(nv_cefc4c->getPlayer4630f0())?0x6d:0x71),&nv_d2d1c4.at9b81f0(to8)->name24,&part->getName571db0(0,0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								}
								if(b5&&rj5.isNull9b65d0()){
									if(gC.isValid9b7230())nv_cf47cc.push_back9b9280(gC->getWidth9fcd80());
									nv_d25628.addItemAttachCount778560(gC.isValid9b7230()?gC->nested457820():to8,1,0);
									nv_d2c658.add4729d0(0x251,1,"",-1);
									if(nv_d2c658.vals->at9b81f0(0x251)==0x1e)nv_cf45d8.unlock77fbc0(0xef);
								}
								if(rj5.isValid9b7230()){
									rj5->remove57dbe0(0,0,1,1);
									nv_sound454260(getPosition45a4a0(),0xd0);
								}else{
									if(b5)u45b1e0(5);
									nv_sound454260(getPosition45a4a0(),0xcf);
								}
							}
						}else{
							if(::rng.chance406c90(1)){
								do{if(nv_show5111e0(b5?0x68:(u45aaa0(nv_cefc4c->getPlayer4630f0())?0x6c:0x70),&CELLP(prop->u4184d0())->getProp45d550()->getName45c5b0(),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								CELLP(prop->u4184d0())->u66ce10(0,0,0,0);
								if(aG.operator->()==0)return;
							}else{
								do{if(nv_show5111e0(b5?0x67:(u45aaa0(nv_cefc4c->getPlayer4630f0())?0x6b:0x6f),&CELLP(prop->u4184d0())->getProp45d550()->getName45c5b0(),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							}
						}
					}
				}
				break;
			case 0xa7:{
				if(!b5||!part->u45cb30())break;
				NvCPart*u10=nv_cec088->u894e70(part);
				NvRec*rec=part->def9b4350()->getRecord56f3c0();
				NvHE aT;
				NvPoint p;
				if(nv_cefc4c->findPlaceableNear71c150(getPosition45a4a0(),p,rec->f9c))aT=nv_cefc4c->placeEntity6c58c0(rec,p,0,0,0x22,0xe,0);
				if(aT.isNull9b65d0())break;
				aT->u45b2a0();
				do{if(nv_show5111e0(0x283,&part->getName571db0(0,0),0,0,aT,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
				part->u44fc60(part->u45cb30()-1);
				if(!part->u45cb30())nv_cec088->toggle8993e0(u10,0);
				u10->u4a8fc0();
				nv_sound454260(getPosition45a4a0(),0xbd);
				nv_d2c658.add4729d0(0x3d1,1,"",-1);
				if(aT->def9b4350()->b15c&&nv_d1e888->f4==0xb&&(nv_stringToInt405610(nv_d1e860.getEntryText46f6d0(nv_be6810))||nv_stringToInt405610(nv_d1e860.getEntryText46f6d0(nv_be6824))))nv_d1eb40++;
				}break;
			case 0xa8:
				if(part->u577a90()>=part->u457fb0()&&nv_caf130!=6){
					NvRecI*r=nv_777cf0();
					if(r!=0&&nv_cf462c!=2){
						NvHI u20;
						if(u45a810()>=r->f4c)u20=nv_cefc4c->u6c51d0(r,self,0,0);
						else u20=nv_cefc4c->u6c5400(r,getPosition45a4a0());
						if(u20.isValid9b7230()){
							if(b5){
								u20->addEffect4585a0(new NvEffPair(nv_d2f0f8.at9b81f0(0x69),1));
								do{if(nv_show5111e0(0x295,&part->getName571db0(0,0),&u20->getName571db0(0,0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							}else{
								do{if(nv_show5111e0(0x296,&u20->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							}
							nv_sound454260(getPosition45a4a0(),0xe7);
						}
					}
					part->setActive5791a0(1);
				}
				break;
			case 0xa9:
				if(part->u577a90()>=part->u457fb0()){
					NvRecI*r=0;
					nv_findByName9d7a40(nv_d2d1c4,part->def9b4350()->s1b4,r);
					if(r!=0){
						NvHI up7;
						if(u45a810()>=1)up7=nv_cefc4c->u6c51d0(r,self,0,0);
						else up7=nv_cefc4c->u6c5400(r,getPosition45a4a0());
						if(up7.isValid9b7230()){
							do{if(nv_show5111e0(0x294,&part->getName571db0(0,0),&up7->getName571db0(0,0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							if(b5)nv_d2c658.add4729d0(0x254,1,"",-1);
							nv_sound454260(getPosition45a4a0(),0xc1);
						}
					}
					part->setActive5791a0(1);
				}
				break;
			case 0xaa:
				if(part->u577a90()>=part->u457fb0()&&nv_caf130!=6){
					NvRec*rec=0;
					nv_findByName9d7530(nv_d25de0,nv_be6834,rec);
					if(rec!=0){
						NvHE upX;
						NvPoint p;
						int gD=nv_stringToInt405610(nv_d1e860.getEntryText46f6d0(nv_be6840))?2:5;
						if(nv_cefc4c->findPlaceableNear71c150(getPosition45a4a0(),p,rec->f9c))upX=nv_cefc4c->placeEntity6c58c0(rec,p,gD,0,0x22,0xe,0);
						if(upX.isValid9b7230()){
							upX->ai45b590()->setFollowEntity5b2f80(self,0);
							do{if(nv_show5111e0((gD!=2)+0x288,&part->getName571db0(0,0),0,0,upX,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							if(b5)nv_d2c658.add4729d0(0x3b4,1,"",-1);
							nv_sound454260(getPosition45a4a0(),0x102);
						}
					}
					part->setActive5791a0(1);
				}
				break;
			case 0xab:
				if(f8->f110!=0&&part->u577a90()>=part->u457fb0()){
					int vUp=nv_d02b74.pick9ba470();
					NvHE vv2=nv_cefc4c->placeEntity6c58c0b(vUp,getPosition45a4a0(),h28->type9b4350(),0,0x22,0xe,0);
					if(vv2.isValid9b7230()){
						vv2->u45b2a0();
						nv_sound454260(getPosition45a4a0(),0xbf);
						do{if(nv_show5111e0(0xce,&part->getName571db0(0,0),&vv2->name416f40(),0,vv2,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						if(b5){
							do{nv_logPhrase5141b0d(0x35,part->getName571db0(0,0),&vv2->name416f40(),&string(nv_be6858),NvHE(),0);}while(0);
							nv_cf4aa8.push_back9b80b0(vv2);
							nv_cf4ab8.push_back9b9d30(nv_cefc4c->getTurn464270()+100);
						}
					}
					part->setActive5791a0(1);
				}
				break;
			case 0xac:
				if(f8->f110!=5&&part->u577a90()>=part->u457fb0()){
					NvPos h2(-1);
					if(!nv_cefc4c->u74d420(getPosition45a4a0(),h2)){
						part->u4582f0();
						if(part->u457e10())u5deb40(part->u457e10());
						break;
					}
					int ww3=nv_cf2974.pick9ba470();
					NvHE hs=nv_cefc4c->placeEntity6c58c0b(ww3,h2,h28->type9b4350(),0,0x22,0xe,0);
					if(hs.isValid9b7230()){
						nv_sound454260(hs->getPosition45a4a0(),0xc2);
						if(b5){
							do{if(nv_show5111e0(0x28b,0,0,0,hs,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							do{nv_logPhrase5141b0(0x5b,hs->name416f40(),0,0,hs,0);}while(0);
							nv_d2c658.add4729d0(0x3b3,1,"",-1);
						}else{
							do{if(nv_show5111e0((isHostileTo45aa70(nv_cefc4c->getPlayer4630f0())!=0)+0x28d,&name416f40(),0,0,hs,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						}
					}
					part->setActive5791a0(1);
				}
				break;
			case 0xad:
				if(part->u577a90()>=part->u457fb0()){
					NvRec*rec=0;
					nv_findByName9d7530(nv_d25de0,part->def9b4350()->s1b4,rec);
					if(rec!=0){
						bool special=nv_strEq9ccb50(part->u457860(),nv_be685c);
						int count=0;
						NvHE z18;
						NvPoint p;
						for(int k=0;k<part->u457fd0();k++){
							if(nv_cefc4c->findPlaceableNear71c150(getPosition45a4a0(),p,rec->f9c))z18=nv_cefc4c->placeEntity6c58c0(rec,p,2,0,0x22,0xe,0);
							if(z18.isValid9b7230()){
								z18->ai45b590()->setFollowEntity5b2f80(self,0);
								if(nv_cefc4c->u4631f0(z18)){
									if(special)nv_message49c610(0x320,NvHE(),&string(nv_be6880),0);
									else do{if(nv_show5111e0(0xce,&part->getName571db0(0,0),&z18->name416f40(),0,z18,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								}
								count++;
							}
						}
						if(count!=0){
							nv_sound454260(getPosition45a4a0(),0xe8);
							if(b5){
								if(special){
									do{nv_logPhrase5141b0c(0x36,part->getName571db0(0,0),&z18->name416f40(),0,NvHE(),0);}while(0);
									nv_cf45d8.unlock77fbc0(0x128);
								}else{
									do{nv_logPhrase5141b0d(0x35,part->getName571db0(0,0),&z18->name416f40(),&nv_intToString4051f0(count),NvHE(),0);}while(0);
								}
							}
						}
					}
					part->remove57dbe0(1,0,0,1);
				}
				break;
			case 0xae:{
				if(nv_cf462c==2&&b5)break;
				NvHI found;
				for(unsigned j=0;j<parts.size9b9260();j++){
					if(parts.at9b81f0(j)->getType44aec0()<=3&&parts.at9b81f0(j)->getEffect457b70(0x52)){found=parts.at9b81f0(j);break;}
				}
				if(found.isNull9b65d0()){
					NvVecU2 counts;
					for(int k=0;k<4;k++)counts.push_back9b9d30i(a78[k]);
					for(unsigned j=0;j<parts.size9b9260();j++){
						if(parts.at9b81f0(j)->getType44aec0()<=3)counts.at9b81f0(parts.at9b81f0(j)->nested4578a0())-=parts.at9b81f0(j)->nested4578c0();
					}
					if(nv_anyNonZero9d7f70(counts)){
						NvRec*rec;
						nv_findByName9d7530(nv_d25de0,nv_be686c,rec);
						NvVecRI cands;
						for(unsigned k=0;k<rec->v160.size9b5100();k++){
							if(nv_d2d1c4.at9b81f0(rec->v160.at9b8070(k).at9b81f0(0)->f0)->s8!=nv_be6874)cands.push_back9b9d30(nv_d2d1c4.at9b81f0(rec->v160.at9b8070(k).at9b81f0(0)->f0));
						}
						for(unsigned j=0;j<parts.size9b9260();j++){
							for(unsigned z26=0;z26<cands.size9b9260();z26++){
								if(parts.at9b81f0(j)->getType44aec0()<=3&&parts.at9b81f0(j)->def9b4350()==cands.at9b81f0(z26)){nv_removeAt9de6f0(cands,z26);break;}
							}
						}
						for(unsigned z37=0;z37<cands.size9b9260();z37++){
							if(cands.at9b81f0(z37)->s8!=nv_be68ec&&counts.at9b81f0(cands.at9b81f0(z37)->f48)>=cands.at9b81f0(z37)->f4c){
								if(b5)nv_cf45d8.u77ffb0(cands.at9b81f0(z37)->f0,0);
								found=nv_cefc4c->u6c51d0(cands.at9b81f0(z37),self,1,0);
								found->setActive5791a0(0);
								found->set450460(1);
								found->addEffect4585a0(new NvEffPair(nv_d2f0f8.at9b81f0(0x52),1));
								if(b5){
									NvCPart*z43=nv_cec088->u894e70(found);
									if(z43==0){
										nv_logError404f10(nv_be6924,nv_be68f8+found->u457860());
										break;
									}
									z43->u890710(0);
									if(nv_d28d68==0||nv_d28d68==4){
										nv_cec088->u896b40();
										if(nv_cec08c!=0)nv_cec08c->reopen8a2ce0(4,NvHE());
									}
								}
								do{if(nv_show5111e0(b5?0xbe:0xbf,&found->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								break;
							}
						}
					}
				}
				if(found.isValid9b7230()){
					found->u458360(nv_cebc4c);
					if(found->u457ca0()==100){
						found->u4585c0(0x52);
						nv_cf47cc.push_back9b9280(found->getWidth9fcd80());
						nv_d25628.addItemAttachCount778560(found->nested457820(),1,0);
						if(b5){
							NvCPart*zz5=nv_cec088->u894e70(found);
							if(zz5==0){
								nv_logError404f10(nv_be696c,nv_be693c+found->u457860());
								break;
							}
							if(!u5dc440(found))nv_cec088->toggle8993e0(zz5,0);
							else zz5->u4a9120();
							zz5->drawStatus4a8e70(0);
							if(nv_d28d68==0||nv_d28d68==4){
								nv_cec088->u896b40();
								if(nv_cec08c!=0)nv_cec08c->reopen8a2ce0(4,NvHE());
							}
							nv_sound4541b0(0xf1,0,0);
						}
						do{if(nv_show5111e0(b5?0xc0:0xc1,&found->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					}else if(b5){
						NvCPart*aAdj=nv_cec088->u894e70(found);
						if(aAdj==0){
							nv_logError404f10(nv_be69bc,nv_be6984+found->u457860());
							break;
						}
						aAdj->drawStatus4a8e70(0);
					}
				}else if(b5&&nv_cf45d8.isSlotEmpty46de40(0x15f)){
					NvRec*rec;
					nv_findByName9d7530(nv_d25de0,nv_be69d4,rec);
					NvVecB seen(rec->v160.size9b5100(),1);
					NvVecHI3 aInv;
					u5cb8b0(aInv);
					for(unsigned j=0;j<aInv.size9b9260();j++){
						for(unsigned k=0;k<rec->v160.size9b5100();k++){
							if(aInv.at9b81f0(j)->nested457820()==rec->v160.at9b8070(k).front9b7060()->f0&&seen.at9b38a0(k).toBool9b3ad0()){seen.at9b38a0(k).assign9b3a70(0);break;}
						}
					}
					if(!nv_fn9d9b60(seen))nv_cf45d8.unlock77fbc0(0x15f);
				}
				}break;
			case 0xaf:{
				int range=part->u457fb0();
				nv_clearDijkstra4faf40();
				nv_cfe568.u40ca20(getPosition45a4a0(),range*2+2,&nv_cf119c,0);
				if(nv_d15e58.empty9b86e0()){
					nv_logWarning404e50(nv_be6a00,nv_be69dc);
				}else{
					NvVecPt aPct(nv_d15e58);
					NvPoint cur;
					for(unsigned k=1;k<aPct.size9b9a50();k++){
						if(CELLP(aPct.at9e7c10(k))->getItem45d8f0().isValid9b7230()){
							NvHI far3=CELLP(aPct.at9e7c10(k))->getItem45d8f0();
							int i6=nv_maxInt9cdb60(1,far3->u457c80()/100);
							if(i6>=far3->u9b6bf0()){
								if(nv_cefc4c->isVisible4631c0(aPct.at9e7c10(k))){
									string msg=far3->getName571db0(0,0)+nv_be6a14;
									do{if(nv_show5111e0(0x320,&msg,0,0,NvHE(),NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								}
								far3->remove57dbe0(0,1,1,1);
							}else{
								far3->u458310(i6);
								if(nv_nextLineStep40ff60(NvPoint(aPct.at9e7c10(k)),getPosition45a4a0(),&cur)){
									bool ok=true;
									if(!CELLP(cur)->u45d940()){
										ok=false;
										NvVecPt far7;
										if(nv_commonNeighbors4fac50(aPct.at9e7c10(k),cur,far7)){
											NvVecF dists;
											for(unsigned farC=0;farC<far7.size9b9a50();farC++){
												if(CELLP(far7.at9e7c10(farC))->u45d940())dists.push_back9b84b0(nv_distance40a450(far7.at9e7c10(farC),getPosition45a4a0()));
												else nv_eraseStep9d7300(far7,farC);
											}
											if(!dists.empty9b86e0()){
												int best=nv_fn9d7d70(dists);
												if(dists.at9b81f0(best)<nv_distance40a450(aPct.at9e7c10(k),getPosition45a4a0())){
													cur=far7.at9e7c10(best);
													ok=true;
												}
											}
										}
									}
									if(ok)far3->u57a0f0(cur,0,0);
								}
							}
						}
						if(CELLP(aPct.at9e7c10(k))->u45d230()&&CELLP(aPct.at9e7c10(k))->u45de70()&&nv_nextLineStep40ff60(NvPoint(aPct.at9e7c10(k)),getPosition45a4a0(),&cur)){
							bool ok2=true;
							if(!CELLP(cur)->u45da30()){
								ok2=false;
								NvVecPt far_;
								if(nv_commonNeighbors4fac50(aPct.at9e7c10(k),cur,far_)){
									NvVecF dists;
									for(unsigned fars=0;fars<far_.size9b9a50();fars++){
										if(CELLP(far_.at9e7c10(fars))->u45da30())dists.push_back9b84b0(nv_distance40a450(far_.at9e7c10(fars),getPosition45a4a0()));
										else nv_eraseStep9d7300(far_,fars);
									}
									if(!dists.empty9b86e0()){
										int best=nv_fn9d7d70(dists);
										if(dists.at9b81f0(best)<nv_distance40a450(aPct.at9e7c10(k),getPosition45a4a0())){
											cur=far_.at9e7c10(best);
											ok2=true;
										}
									}
								}
							}
							if(ok2)CELLP(aPct.at9e7c10(k))->u66b740(CELLP(cur));
						}
					}
				}
				break;}
			case 0xb0:
				if(part->u577a90()&&part->u577a90()%5==0&&nv_d1e888->f4!=8){
					int range_=part->u457fb0();
					NvVGrp*gTmp=nv_cefc4c->u463950();
					int link=0;
					for(unsigned g=0;g<gTmp->size9b9260();g++){
						NvVecHE5*ents=gTmp->at9b81f0(g)->u416f40();
						for(unsigned k=0;k<ents->size9b9260();k++){
							if(ents->at9b81f0(k)->getFaction45a2c0()==0x3c&&!ents->at9b81f0(k)->getTarget45a760()&&nv_distanceCeil40a3f0(getPosition45a4a0(),ents->at9b81f0(k)->getPosition45a4a0())<=range_){
								ents->at9b81f0(k)->u5fd900(6,0);
								if(!ents->at9b81f0(k)->u45ac40(0x1c))ents->at9b81f0(k)->u45b340(new NvEffPair(nv_d2f0f8.at9b81f0(0x1c),1));
								do{if(nv_show5111e0(0x207,0,0,0,ents->at9b81f0(k),NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								if((link!=0||nv_lookup9d7980(nv_be6a38,&link))&&nv_cec054->inBounds4173d0(ents->at9b81f0(k)->getPosition45a4a0().add409b60(nv_cec054->u458ef0())))
									nv_cefc50->new508610(nv_cefc50)->init503b20(link,ents->at9b81f0(k)->getPosition45a4a0(),&nv_d2e20c,0,0,0,9,0);
								nv_sound454260(ents->at9b81f0(k)->getPosition45a4a0(),0x103);
							}
						}
					}
				}
				break;
			case 0xb1:
				if(part->u577a90()){
					if(part->u577a90()%5==0){
						int rangeTmp=part->u457fb0();
						NvVGrp*i9=nv_cefc4c->u463950();
						int link=0;
						for(unsigned g=0;g<i9->size9b9260();g++){
							NvVecHE5*ents=i9->at9b81f0(g)->u416f40();
							if(!ents->empty9b86e0()){
								for(int k=ents->size9b9260()-1;k>=0;k--){
									if(ents->at9b81f0(k)->getFaction45a2c0()==0x25&&!ents->at9b81f0(k)->getTarget45a760()&&nv_cefc4c->u463400(ents->at9b81f0(k))&&(ents->at9b81f0(k)->isHostileTo45aa70(self)||nv_strEq9ccb50(ents->at9b81f0(k)->name416f40(),nv_be6a4c)&&ents->at9b81f0(k)->getGroup45a3f0()->type9b4350()!=2)&&nv_distanceCeil40a3f0(getPosition45a4a0(),ents->at9b81f0(k)->getPosition45a4a0())<=rangeTmp){
										NvHE e=ents->at9b81f0(k);
										e->removeEffectsA639730(0);
										e->changeFaction5dc780(nv_cefc4c->u463890(2),1);
										e->ai45b590()->setFollowEntity5b2f80(self,0);
										if(nv_strEq9ccb50(e->name416f40(),nv_be6a54)){
											nv_cefc4c->u6c65a0(e,nv_be6a5c,0);
											nv_cefc4c->u6c65a0(e,nv_be6a74,0);
										}else nv_cefc4c->u6c65a0(e,nv_be6a8c,0);
										do{nv_logPhrase5141b0b(0x123,0,0,0,NvHE(),0);}while(0);
										nv_cf45d8.unlock77fbc0(0x175);
										nv_cec054->u49adc0(1000);
									}
								}
							}
						}
					}
					if(nv_d1e888->f4==0xf&&part->getEffectValue457be0(0x6a)<3&&part->u577a90()%15==0&&::rng.chance406c90(5)&&!nv_cefc4c->isVisible4631c0(nv_cefc4c->u4184d0())){
						NvVecHE5*ents=nv_cefc4c->u463890(2)->u416f40();
						for(unsigned k=0;k<ents->size9b9260();k++){
							if(ents->at9b81f0(k)->getFaction45a2c0()==0x25&&!ents->at9b81f0(k)->getTarget45a760())goto endB1;
						}
						{NvPos e1=nv_cefc4c->u71d000(0);
						if(e1.x!=-1){
							NvHE e=nv_cefc4c->u6c5dc0(nv_be6aa4,e1,2,0,0x22,0xe,0);
							if(e.isValid9b7230()){
								e->ai45b590()->setFollowEntity5b2f80(self,0);
								nv_cefc4c->u6c65a0(e,nv_be6ab0,0);
								NvEffPair*gain=part->getEffect457b70(0x6a);
								if(gain)gain->value++;
								else part->addEffect4585a0(new NvEffPair(nv_d2f0f8.at9b81f0(0x6a),1));
							}
						}}
					}
endB1:;
				}
				break;
			case 0xb2:
				if(nv_d1eb60==-1&&nv_b90f38[nv_d1e888->f4]!=0)nv_d1eb60=nv_cefc4c->getTurn464270()+nv_cf1f1c.random40c130();
				break;
			case 0xb3:
				if(part->u9b6bf0()<part->u457c80()&&(part->u457fb0()>=10||part->u457fb0()<10&&part->u577a90()%(10-part->u457fb0()+1)==0)){
					int before=part->u9b6bf0();
					if(part->u457fb0()>=10){
						part->set450460(part->u9b6bf0()+part->u457fb0()-9);
						if(part->u9b6bf0()>part->u457c80())part->set450460(part->u457c80());
					}else part->set450460(part->u9b6bf0()+1);
					if(isPlayer5c7600()&&part->u9b6bf0()>before)nv_d2c658.add4729d0(0x178,part.get9b65b0t()->u9b6bf0t()-before,"",-1);
					NvCPart*goal=nv_cec088->u894e70(part);
					if(goal)goal->drawStatus4a8e70(0);
				}
				break;
			case 0xb4:
				if(part->u9b6bf0()<part->u457c80()&&CELLP(getPosition45a4a0())->getItem45d8f0().isValid9b7230()&&CELLP(getPosition45a4a0())->getItem45d8f0()->nested457880()>=6&&CELLP(getPosition45a4a0())->getItem45d8f0()->u9b6bf0()>=part->u457fb0()){
					NvHI bA=CELLP(getPosition45a4a0())->getItem45d8f0();
					int c2=part->u457fb0();
					if(bA->nested457880()==0x12)c2=c2/nv_ba0a8c;
					int amt=nv_minInt9cdb30(bA->u9b6bf0()/c2,part->u457cd0());
					part->u458360(amt);
					nv_sound454260(getPosition45a4a0(),0xbc);
					if(b5){
						do{if(nv_show5111e0(0x189,&part->getName571db0(0,0),&bA->getName571db0(0,0),&nv_intToString4051f0(amt),self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						NvCPart*hVal=nv_cec088->u894e70(part);
						if(hVal)hVal->drawStatus4a8e70(0);
					}else{
						do{if(nv_show5111e0(u45aaa0(nv_cefc4c->getPlayer4630f0())?0x18a:0x18b,&part->getName571db0(0,0),&bA->getName571db0(0,0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					}
					bA->remove57dbe0(0,0,1,1);
				}
				break;
			case 0xb5:
				nv_cefc4c->u7471d0(self);
				break;
			case 0xb6:
				nv_cefc4c->u747400b(self,part,0,0);
				break;
			case 0xb7:
				if(part->u9b6bf0()>1){
					part->u458310(1);
					switch(part->u9b6bf0()){
					case 10:
						do{if(nv_show5111e0(0x118,&part->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						break;
					case 2:
						do{if(nv_show5111e0(0x119,0,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						break;
					}
					NvCPart*hit3=nv_cec088->u894e70(part);
					if(hit3)hit3->drawStatus4a8e70(1);
					if(part->u9b6bf0()==1)nv_cec054->u44e360(part);
				}
				break;
			case 0xb8:{
				bool remove3;
				int aK=u5c7d30();
				NvRect aJ;
				nv_cfd44c.getRect9b4430(getPosition45a4a0(),aK,aJ);
				for(int x=aJ.x1;x<=aJ.x2;x++)for(int y=aJ.y1;y<=aJ.y2;y++){
					if(CELL(x,y)->u45dbf0()&&CELL(x,y)->u9fcd80()->f5c<=2&&nv_distanceCeil40a3f0(getPosition45a4a0(),NvPos(x,y))<=aK&&(b5?nv_cefc4c->isVisible463190(x,y):nv_cefc4c->u72a900(aK,getPosition45a4a0(),NvPos(x,y))))
						CELL(x,y)->u670b60(0);
				}
				NvVecPt*pts=nv_cefc4c->u463ad0();
				NvGVec*k4=nv_cefc4c->u463af0();
				NvHP x8;
				for(unsigned k=0;k<pts->size9b9a50();k++){
					if(nv_distanceCeil40a3f0(getPosition45a4a0(),pts->at9e7c10(k))<=aK&&(b5?nv_cefc4c->isVisible4631c0(pts->at9e7c10(k)):nv_cefc4c->isReachable465230(aK,getPosition45a4a0(),pts->at9e7c10(k)))){
						x8=CELLP(pts->at9e7c10(k))->getProp45d550();
						remove3=false;
						if(x8.isNull9b65d0()||!x8->u45cb30()||x8->u457b10())remove3=true;
						else{
							NvTerm*t=x8->u45cb30()->u45c1c0(5);
							if(t==0&&k4->at9b81f0(k)==0x27)remove3=true;
							else{
								NvVecPt found;
								if(!nv_collectProps517ae0(x8->u44ab40(),&found,0,2,0))remove3=true;
								else{
									if(t)t->b8=1;
									if(b5){
										do{if(nv_show5111e0(0xd4,&part->getName571db0(0,0),&CELLP(found.front9b7060())->getProp45d550()->getName45c5b0(),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
										do{nv_logPhrase5141b0(0x5a,CELLP(found.front9b7060())->getProp45d550()->getName45c5b0(),0,0,NvHE(),0);}while(0);
									}else{
										do{if(nv_show5111e0(0xd5,&CELLP(found.front9b7060())->getProp45d550()->getName45c5b0(),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
									}
									nv_sound454260(found.front9b7060(),0x7e);
									int link;
									if(nv_lookup9d7980(nv_be6ac8,&link)){
										for(unsigned hitC=0;hitC<found.size9b9a50();hitC++){
											if(nv_cefc4c->isVisible4631c0(found.at9e7c10(hitC)))nv_cefc50->new508610(nv_cefc50)->init503b20(link,found.at9e7c10(hitC),&nv_d2e20c,0,0,0,9,0);
											CELLP(found.at9e7c10(hitC))->getProp45d550()->u45ce10(1,0,1,NvHE());
										}
									}
									remove3=true;
								}
							}
						}
						if(remove3){
							nv_eraseAt9d5190(*pts,k);
							nv_eraseAt9ce6d0(*k4,k);
						}
					}
				}
				}break;
			case 0xb9:{
				bool j4;
				NvVecPt*pts=nv_cefc4c->u463ad0();
				NvGVec*xB=nv_cefc4c->u463af0();
				NvHP xN;
				for(unsigned k=0;k<pts->size9b9a50();k++){
					if(nv_distanceCeil40a3f0(getPosition45a4a0(),pts->at9e7c10(k))<=10&&(b5?nv_cefc4c->isVisible4631c0(pts->at9e7c10(k)):nv_cefc4c->isReachable465230(10,getPosition45a4a0(),pts->at9e7c10(k)))){
						xN=CELLP(pts->at9e7c10(k))->getProp45d550();
						j4=false;
						if(xN.isNull9b65d0()||!xN->u45cb30()||xN->u457b10())j4=true;
						else{
							NvTerm*t=xN->u45cb30()->u45c1c0(5);
							if(t==0&&xB->at9b81f0(k)==0x27)j4=true;
							else{
								NvVecPt found;
								if(!nv_collectProps517ae0(xN->u44ab40(),&found,0,2,0))j4=true;
								else{
									xN->u45cb30()->f7c++;
									if(xN->u45cb30()->f7c<part->u457fb0()+1){
										if(xN->u45cb30()->f7c==1){
											if(b5){
												do{if(nv_show5111e0(0xd6,&part->getName571db0(0,0),&nv_intToString4051f0(part->u457fb0()),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
												nv_sound4541b0(0xde,0,0);
											}else{
												do{if(nv_show5111e0(0xd8,0,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
											}
										}
										if(b5){
											nv_cec054->showTimer8176a0(3,pts->at9e7c10(k),part->u457fb0()+1-xN->u45cb30()->f7c,0);
											NvCPart*hops=nv_cec088->u894e70(part);
											if(hops)hops->refreshLabel890cf0();
										}
									}else{
										if(t)t->b8=1;
										else{
											nv_d1e910.at9b81f0(xB->at9b81f0(k))++;
											xN->u45cb30()->v50.push_back9b9d30(xB->at9b81f0(k));
										}
										if(b5){
											do{if(nv_show5111e0(0xd7,&part->getName571db0(0,0),&CELLP(found.front9b7060())->getProp45d550()->getName45c5b0(),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
											do{nv_logPhrase5141b0(0x5a,CELLP(found.front9b7060())->getProp45d550()->getName45c5b0(),0,0,NvHE(),0);}while(0);
											nv_sound4541b0(0xdf,0,0);
										}else{
											do{if(nv_show5111e0(0xd9,&CELLP(found.front9b7060())->getProp45d550()->getName45c5b0(),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
										}
										nv_sound454260(found.front9b7060(),0x7e);
										int link;
										if(nv_lookup9d7980(nv_be6adc,&link)){
											for(unsigned iVal=0;iVal<found.size9b9a50();iVal++){
												if(nv_cefc4c->isVisible4631c0(found.at9e7c10(iVal)))nv_cefc50->new508610(nv_cefc50)->init503b20(link,found.at9e7c10(iVal),&nv_d2e20c,0,0,0,9,0);
												CELLP(found.at9e7c10(iVal))->getProp45d550()->u45ce10(1,0,1,NvHE());
											}
										}
										j4=true;
									}
								}
							}
						}
						if(j4){
							nv_eraseAt9d5190(*pts,k);
							nv_eraseAt9ce6d0(*xB,k);
						}
					}
				}
				}break;
			case 0xba:
				if(b5){
					int msg1=h28->type9b4350();
					int range8=part->u457fb0();
					int link=0;
					for(unsigned a=0;a<nv_d20248.size9b5100();a++){
						for(unsigned b=0;b<nv_d20248.at9b8070(a).size9b9260();b++){
							if(nv_d20248.at9b8070(a).at9b81f0(b)->u45cbd0()&&nv_d20248.at9b8070(a).at9b81f0(b)->u44b020()->u65cf50(msg1)&&nv_cefc4c->u4633c0(nv_d20248.at9b8070(a).at9b81f0(b)->u4184d0())&&nv_distanceCeil40a3f0(getPosition45a4a0(),nv_d20248.at9b8070(a).at9b81f0(b)->u4184d0())<=range8){
								NvHP p=nv_d20248.at9b8070(a).at9b81f0(b);
								NvPoint pos2(p->u4184d0());
								if(nv_b96a78[p->def9b8f00()->f140]){
									nv_d2c658.add4729d0(0x250,1,"",-1);
									do{if(nv_show5111e0(0x20f,&p->getName45c5b0(),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
									CELLP(pos2)->removeProp66c100(0,4);
									nv_sound4541b0(0x6c,0,0);
								}else{
									nv_d2c658.add4729d0(0x250,1,"",-1);
									do{if(nv_show5111e0(0x210,&p->getName45c5b0(),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
									CELLP(pos2)->getProp45d550()->u44b020()->f10=0;
									CELLP(pos2)->getProp45d550()->u44b020()->hc=self;
									nv_sound4541b0(0x6d,0,0);
								}
								if((link!=0||nv_lookup9d7980(nv_be6af0,&link))&&nv_cec054->inBounds4173d0(pos2.add409b60(nv_cec054->u458ef0())))
									nv_cefc50->new508610(nv_cefc50)->init503b20(link,pos2,&nv_d2e20c,0,0,0,9,0);
							}
						}
					}
				}
				break;
			case 0xbb:
				if(b5&&part->u577a90()>10&&::rng.chance406c90(10)){
					NvPos g2(part->u457fb0(),part->u457fd0());
					NvPoint dD(getPosition45a4a0());
					NvRect i1;
					nv_cfd44c.getRect9b4430(dD,g2.y,i1);
					NvPoint iC;
					bool found=false;
					bool g7=false;
retryBB:
					for(int t=0;t<2000;t++){
						i1.randomPoint40be30(&iC);
						if(g2.contains40c190(nv_distanceCeil40a3f0(dD,iC))&&CELLP(iC)->canPlaceEntity66ad20(1)){found=true;break;}
					}
					if(!found){
						if(g7){
							nv_logError404f10(nv_be6b44,nv_be6b08+nv_intToString4051f0(g2.x)+nv_be6b04+nv_intToString4051f0(g2.y)+nv_be6b00);
							break;
						}
						g2.x=1;
						g7=true;
						goto retryBB;
					}
					NvWLI gX;
					if(::rng.chance406c90(100)){
						for(unsigned j=0;j<parts.size9b9260();j++){
							if(parts.at9b81f0(j)!=part&&parts.at9b81f0(j)->getType44aec0()<=3&&parts.at9b81f0(j)->u457f90()!=7&&parts.at9b81f0(j)->u457f90()!=0xb7&&parts.at9b81f0(j)->u457f90()!=0xd6&&!parts.at9b81f0(j)->getEffect457b70(0x6c)&&!parts.at9b81f0(j)->u577fb0()&&parts.at9b81f0(j)->def9b4350()->f94!=2)
								gX.add9ba0d0(parts.at9b81f0(j),100/parts.at9b81f0(j)->nested4578c0());
						}
					}
					NvHI jB;
					NvHI e0;
					if(!gX.u9b81b0()){
						jB=gX.pick9ba470();
						jB->u4585c0(0x6e);
						jB->u57a5d0(9,1);
						nv_cf4a48.push_back9b80b0(jB);
					}
					if(jB.isValid9b7230()&&::rng.chance406c90(0x50)){
						int slot=jB.isValid9b7230()?jB->nested4578a0():4;
						NvVecHI3 cands;
						NvVecU2 msg5;
						u5c93d0(msg5);
						for(int pass=0;pass<2;pass++){
							for(unsigned msg9=0;msg9<nv_cf4a48.size9b9260();msg9++){
								if(jB!=nv_cf4a48.at9b81f0(msg9)&&(pass!=0||nv_cf4a48.at9b81f0(msg9)->nested4578a0()==slot)&&msg5.at9b81f0(nv_cf4a48.at9b81f0(msg9)->nested4578a0())>=nv_cf4a48.at9b81f0(msg9)->nested4578c0())cands.push_back9b80b0(nv_cf4a48.at9b81f0(msg9));
							}
							if(!cands.empty9b86e0())break;
						}
						if(!cands.empty9b86e0()){
							e0=nv_randomRecord9dafb0(cands);
							nv_removeEntity9d2f00(nv_cf4a48,e0);
							e0->u57a190(self,e0->nested4578a0(),1,0);
							if(!u5dc440(e0))nv_cec088->toggle8993e0(nv_cec088->u894e70(e0),1);
						}
					}
					do{if(nv_show5111e0(0xe2,&part->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					if(jB.isValid9b7230()){
						do{if(nv_show5111e0(0xe3,&jB->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					}
					if(e0.isValid9b7230()){
						do{if(nv_show5111e0(0xe4,&e0->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						if(nv_cf45d8.u77ffb0(e0->nested457820(),1)){
							nv_cec088->u896ab0(e0->nested457820());
							for(unsigned j=0;j<parts.size9b9260();j++){
								if(parts.at9b81f0(j)->nested457820()==e0->nested457820()&&parts.at9b81f0(j)->getType44aec0()==4){nv_cec08c->reopen8a2ce0(4,NvHE());break;}
							}
						}
					}
					u5ddac0(iC,1);
					nv_cefc4c->u71cf70();
					nv_cefc4c->u734560(self,-2,0);
					nv_d2c658.add4729d0(0x3fe,1,"",-1);
					nv_cf45d8.unlock77fbc0(0x86);
					nv_cec054->u49ad30();
					nv_cec054->u49adc0(1000);
					part->setActive5791a0(1);
					for(unsigned j=0;j<v30.size9b9a50();j++){
						if(nv_cefc4c->isVisible4631c0(v30.at9e7c10(j)))nv_cefc50->new508610(nv_cefc50)->init503b20(part->def9b4350()->f190,v30.at9e7c10(j),&nv_d2e20c,0,0,0,9,0);
					}
					nv_sound4541b0(0x10c,0,0);
					NvVecPt jC;
					nv_surrounding4faaf0(dD,jC);
					for(unsigned j=0;j<jC.size9b9a50();j++){
						if(CELLP(jC.at9e7c10(j))->getProp45d550().isValid9b7230()&&CELLP(jC.at9e7c10(j))->getProp45d550()->def9b8f00()->f8c!=0)CELLP(jC.at9e7c10(j))->getProp45d550()->u45ce10(0,1,0,NvHE());
					}
				}
				break;
			case 0xbc:
				if(b5&&::rng.chance406c90(1)){
					NvVecHI3 nInv;
					u5cb8b0(nInv);
					for(unsigned j=0;j<nInv.size9b9260();j++){
						if(nInv.at9b81f0(j)->getEffect457b70(0x6c)||nInv.at9b81f0(j)->u457f90()==7||nInv.at9b81f0(j)->u457f90()==0xb7||nInv.at9b81f0(j)->u457f90()==0xd6||nInv.at9b81f0(j)->u457f90()==0xbc||nInv.at9b81f0(j)->u457f90()==0xda||nInv.at9b81f0(j)->u577fb0()||nv_cec088->isLinked4a9b10(nInv.at9b81f0(j)))nv_eraseStep9d6440(nInv,j);
					}
					if(nInv.empty9b86e0())break;
					NvWLI eD;
					for(unsigned j=0;j<nInv.size9b9260();j++)eD.add9ba0d0(nInv.at9b81f0(j),nInv.at9b81f0(j)->getEffect457b70(0x80)?0x32:0x64);
					NvHI pick4=eD.pick9ba470();
					int slot=pick4->nested4578a0();
					for(unsigned j=0;j<nInv.size9b9260();j++){
						if(nInv.at9b81f0(j)->nested4578a0()!=slot)nv_eraseStep9d6440(nInv,j);
					}
					int c4=pick4->nested457900();
					const int aD=6;
					NvWL e_;
					e_.add9ba310(-1,nv_maxInt9cdb60(1,(c4-aD)*10+0x21));
					e_.add9ba310(0,0x21);
					e_.add9ba310(1,nv_maxInt9cdb60(1,(aD-c4)*10+0x21));
					c4+=e_.pick9ba470();
					nv_clampInt9cdc50(1,c4,9);
					NvVecRI recs;
					for(unsigned r=0;r<nv_d2d1c4.size9b9260();r++){
						if(nv_d2d1c4.at9b81f0(r)->f48==slot&&nv_d2d1c4.at9b81f0(r)->f50==c4&&nv_d2d1c4.at9b81f0(r)->f220!=0)recs.push_back9b9d30(nv_d2d1c4.at9b81f0(r));
					}
					int total1=0;
					for(unsigned j=0;j<nInv.size9b9260();j++)total1+=nInv.at9b81f0(j)->nested4578c0();
					nv_removeEntity9d2f00(nInv,pick4);
					total1+=u5c92e0(slot);
					NvVecHI3 inv2;
					u5cb8b0(inv2);
					for(unsigned j=0;j<inv2.size9b9260();j++){
						if(!inv2.at9b81f0(j)->getEffect457b70(0x80)||inv2.at9b81f0(j)==pick4||inv2.at9b81f0(j)->nested4578a0()!=slot)nv_eraseStep9d6440(inv2,j);
					}
					bool a8=false;
					int x_=5;
					NvRecI*rec;
					for(int tries=0;tries<0x19;tries++){
						NvWL msgA;
						rec=0;
						switch(slot){
						case 0:
							if(false){}if(false){}if(false){}
							break;
						case 1:
							if(::rng.chance406c90(0x5f)){
								if(x_==5)x_=u5d1390();
								int want=x_+9;
								for(unsigned nDef=0;nDef<recs.size9b9260();nDef++){
									if(recs.at9b81f0(nDef)->f44==want&&recs.at9b81f0(nDef)->f0!=pick4->nested457820())msgA.add9ba310((int)recs.at9b81f0(nDef),nv_ba3acc[recs.at9b81f0(nDef)->f220]);
								}
								if(!msgA.u9b81b0())rec=(NvRecI*)msgA.pick9ba470();
							}
						case 3:
							if(rec==0&&::rng.chance406c90(0x42)&&!inv2.empty9b86e0()){
								if(::rng.chance406c90(0x32)){
									NvVecHI3 old0(inv2);
									nv_shuffle9d9fc0b(old0);
									do{
										rec=old0.back9b6540()->def9b4350();
										if(rec->f0!=pick4->nested457820())break;
										else{
											rec=0;
											old0.pop_back9e8cd0();
										}
									}while(!old0.empty9b86e0());
								}
								if(rec==0){
									NvVecU2 old4;
									for(unsigned j=0;j<inv2.size9b9260();j++)nv_addUnique9db000(old4,inv2.at9b81f0(j)->nested457880());
									for(unsigned old8=0;old8<recs.size9b9260();old8++){
										if(nv_containsRecord9db330b(&old4,recs.at9b81f0(old8)->f44)&&recs.at9b81f0(old8)->f0!=pick4->nested457820())msgA.add9ba310((int)recs.at9b81f0(old8),nv_ba3acc[recs.at9b81f0(old8)->f220]);
									}
									if(!msgA.u9b81b0())rec=(NvRecI*)msgA.pick9ba470();
								}
							}
							if(rec==0)break;
							goto haveRec;
						case 2:
							if(::rng.chance406c90(0x32)){
								NvVecHI3 d5;
								u5cb8b0(d5);
								int flag=0x12;
								NvVecU2 flags;
								flags.push_back9b9280(0xd);
								flags.push_back9b9280(0xc);
								for(unsigned oldD=0;oldD<flags.size9b9260();oldD++){
									bool oldH=false;
									for(unsigned j=0;j<d5.size9b9260();j++){
										if(d5.at9b81f0(j)->def9b4350()->getFlag4570c0(flags.at9b81f0(oldD))){oldH=true;break;}
									}
									if(!oldH){flag=flags.at9b81f0(oldD);break;}
								}
								if(flag!=0x12){
									for(unsigned oldP=0;oldP<recs.size9b9260();oldP++){
										if(recs.at9b81f0(oldP)->getFlag4570c0(flag)&&recs.at9b81f0(oldP)->f0!=pick4->nested457820())msgA.add9ba310((int)recs.at9b81f0(oldP),nv_ba3acc[recs.at9b81f0(oldP)->f220]);
									}
									if(!msgA.u9b81b0())rec=(NvRecI*)msgA.pick9ba470();
								}
							}
							if(rec==0)break;
							goto haveRec;
						}
						for(unsigned oldT=0;oldT<recs.size9b9260();oldT++){
							if(recs.at9b81f0(oldT)->f0!=pick4->nested457820())msgA.add9ba310((int)recs.at9b81f0(oldT),nv_ba3acc[recs.at9b81f0(oldT)->f220]);
						}
						if(!msgA.u9b81b0())rec=(NvRecI*)msgA.pick9ba470();
haveRec:
						if(rec==0)break;
						if(total1>=rec->f4c)break;
						else rec=0;
					}
					if(rec==0)break;
					if(rec->f50<pick4->nested457900()||slot==1&&rec->f44-9!=x_)a8=true;
					nv_d2c658.add4729d0(0xd0,nv_maxInt9cdb60(pick4.get9b65b0t()->nested4578c0t(),rec->f4c),"",-1);
					string names=pick4->getName571db0(0,0);
					int thePct=nv_clamp9cdc80(1,pick4->u457ca0(),100);
					int count=nv_maxInt9cdb60(1,pick4->nested4578c0()/rec->f4c);
					pick4->remove57dbe0(1,0,0,1);
					pick4.reset9b7270();
					if(u5c92e0(slot)<rec->f4c*count){
						nv_shuffle9d9fc0b(nInv);
						for(int j=nInv.size9b9260()-2;j>=0;j--){
							if(nInv.at9b81f0(j)->nested4578c0()>1)nv_moveElement9da1f0(nInv,j,nInv.at9b81f0(j)->nested4578c0()-1);
						}
						do{
							names+=nv_be6b58;
							names+=nInv.front9b7060()->getName571db0(0,0);
							nInv.front9b7060()->remove57dbe0(1,0,0,1);
							nv_eraseAt9da940b(nInv,0);
						}while(u5c92e0(slot)<rec->f4c*count);
					}
					for(int n=0;n<count;n++){
						NvHI oldX=nv_cefc4c->u6c51d0(rec,self,1,0);
						if(oldX.isNull9b65d0()){
							nv_logError404f10(nv_be6b6c,nv_be6b5c);
						}else{
							if(thePct<100){
								oldX->set450460(nv_maxInt9cdb60(1,oldX->u457c80()*thePct/100));
								int pOld=oldX->u457cd0();
								nv_d2c658.add4729d0(0xd1,part.get9b65b0t()->u457fb0t()*pOld/100,"",-1);
								oldX->u458360(part->u457fb0()*pOld/100);
								NvCPart*pos6=nv_cec088->u894e70(oldX);
								pos6->drawStatus4a8e70(0);
							}
							oldX->u57bff0(0x80,1);
							oldX->u57bff0(0x6e,1);
							NvVecCP pAdd;
							if(nv_cec088->findParts4a9a40(oldX,pAdd)){
								for(unsigned c=0;c<pAdd.size9b9260();c++){
									pAdd.at9b81f0(c)->putChar4180b0(0,0,0x66);
									pAdd.at9b81f0(c)->u890710(0);
								}
							}
							if(u5dc680(oldX)&&!u5cd220(oldX))nv_cec088->toggle8993e0(nv_cec088->u894e70(oldX),1);
							nv_cec088->u89d610(oldX,10);
							if(n==0){
								string posB=oldX->getName571db0(0,0);
								if(count>1)posB+=nv_be6b88+nv_intToString4051f0(count)+nv_be6b84;
								do{if(nv_show5111e0(0xcf,&part->getName571db0(0,0),&names,&posB,NvHE(),NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								nv_sound4541b0(0x116,0,0);
								if(nv_d25790.at9b81f0(oldX->nested457820())==0&&!nv_cf45d8.u46dd90()&&!oldX->def9b4350()->v7c.u9b81b0())nv_d25790.at9b81f0(oldX->nested457820())=-1;
								if(nv_d25450.b0&&!nv_teamb69d230())nv_d25450.u69e700(0x35,a8!=0,0.0f);
								nv_cec054->u49adc0(1000);
							}
						}
					}
				}
				break;
			case 0xc7:
				if(b5&&part->u9b6bf0()<part->u457c80()&&nv_cefc4c->getTurn464270()%2==0){
					int before=part->u9b6bf0();
					float posN=nv_cefc4c->u7163d0(0,1)*2;
					posN/=nv_ba0bb0;
					if(posN>nv_c36cb0){
						int amt=nv_maxInt9cdb60(1,(int)(part->u457c80()*posN/nv_c36cd0));
						if(amt>0){
							part->set450460(nv_minInt9cdb30(part->u9b6bf0()+amt,part->u457c80()));
							nv_d2c658.add4729d0(0x178,part.get9b65b0t()->u9b6bf0t()-before,"",-1);
							NvCPart*pts2=nv_cec088->u894e70(part);
							if(pts2)pts2->drawStatus4a8e70(0);
						}
					}
				}
				break;
			case 0xd3:
				if(b5){
					if(part->u458220()&&CELLP(getPosition45a4a0())->getItem45d8f0().isValid9b7230()&&CELLP(getPosition45a4a0())->getItem45d8f0()->def9b4350()->b24c){
						NvHI pts6=CELLP(getPosition45a4a0())->getItem45d8f0();
						int kindB=pts6->nested4578a0();
						nv_cf4a58.at9b8070(kindB).push_back9b9280(pts6->nested457820());
						do{if(nv_show5111e0(0x120,&part->getName571db0(0,0),&pts6->getName571db0(0,0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						nv_sound4541b0(0xf2,0,0);
						nv_d2c658.add4729d0(0xcb,1,"",-1);
						pts6->remove57dbe0(1,0,1,1);
						nv_cf4a68=nv_cefc4c->getTurn464270();
						if(nv_cf4a58.at9b8070(kindB).size9b9260()>nv_ba3bf8[kindB])nv_removeAt9de6f0c(nv_cf4a58.at9b8070(kindB),0);
						nv_cec054->u49abf0();
					}
					checkEffectScrapEngine605040(part);
				}
				break;
			}
		}
	}
	if(fp.isValid9b7230()){
		bool ptsB=fp->u457fb0();
		NvVecHI3 items;
		for(unsigned k=0;k<v30.size9b9a50();k++){
			if(CELLP(v30.at9e7c10(k))->getItem45d8f0().isValid9b7230())items.push_back9b7cf0(CELLP(v30.at9e7c10(k))->getItem45d8f0());
		}
		if(!items.empty9b86e0()){
			NvHI ptsN;
			NvHI got;
			for(unsigned k=0;k<items.size9b9260();k++){
				ptsN=items.at9b81f0(k);
				if(u5d4ff0(ptsB,ptsN)){
					if(b5){
						do{if(nv_show5111e0(0x55,&fp->getName571db0(0,0),&ptsN->getName571db0(0,0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						if(nv_cefb48!=0&&nv_cefb48!=0)nv_cefb48->say49e250(0x22,0,"");
						nv_cf47cc.push_back9b9280(ptsN->getWidth9fcd80());
						nv_d25628.addItemAttachCount778560(ptsN->nested457820(),1,0);
					}else{
						do{if(nv_show5111e0((isHostileTo45aa70(nv_cefc4c->getPlayer4630f0())!=0)+0x56,&ptsN->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					}
					nv_sound454260(getPosition45a4a0(),0xd9);
					ptsN->u57a190(self,3,1,0);
					continue;
				}
					got=u5d4dd0(ptsB,ptsN);
					if(got.isValid9b7230()){
						NvHI x;
						if(x.isNull9b65d0()){
							int hA=(int)(got->u457c80()*(b5?nv_bba054:nv_ba09dc));
							int qq42=nv_minInt9cdb30(ptsN->u9b6bf0(),(b5?1:2)*10);
							qq42=nv_minInt9cdb30(qq42,hA-got->u9b6bf0());
							got->u458360(qq42);
							if(b5){
								do{if(nv_show5111e0(0x52,&fp->getName571db0(0,0),&ptsN->getName571db0(0,0),&got->getName571db0(0,0),self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								nv_sound4541b0(0xd7,0,0);
								if(nv_cefb48!=0&&nv_cefb48!=0)nv_cefb48->say49e250(0x21,0,"");
								NvCPart*qq46=nv_cec088->u894e70(got);
								if(qq46)qq46->drawStatus4a8e70(0);
								nv_d2c658.add4729d0(0x178,qq42,"",-1);
								nv_d2c658.add4729d0(0xcf,1,"",-1);
							}else{
								do{if(nv_show5111e0((isHostileTo45aa70(nv_cefc4c->getPlayer4630f0())!=0)+0x53,&ptsN->getName571db0(0,0),&got->getName571db0(0,0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								nv_sound454260(getPosition45a4a0(),0xd8);
							}
							int a=0;
							int b=0;
							if(ptsN->u457ff0()&&ptsN->u45cb30()){
								switch(ptsN->u457f90()){
								case 8:b=ptsN->u45cb30();break;
								case 9:a=ptsN->u45cb30();break;
								}
							}
							ptsN->remove57dbe0(0,0,1,1);
							u5e2b00(a,getPosition45a4a0());
							if(b!=0)u5ded70(b);
							if(!b5&&self!=nv_cefc4c->getEntity463110()&&getField490840()<u5ca260()){
								int heal=nv_minInt9cdb30((int)(qq42*::rng.rangeFloat406e20(nv_c36eb4,1.0f)),(int)(u5ca260()*nv_bba1dc)-getField490840());
								u5de870(heal,0);
							}
						}
					
				}
			}
		}
		if(ai144!=0&&*ai144->u459070()==0&&::rng.chance406c90(10))*ai144->u459070()=new NvRegion(2,nv_cefc4c->getTurn464270t()+0x14,NvHE(),NvHE(),NvPos(-1));
	}
	if(b5&&nv_cf4980&&i94<100&&u5ca260()>=500&&u5ca670()>=300){
		u5deb40(200);
		nv_cf4954-=10;
		if(getField490840()>u5ca260())u5dea60(u5ca260(),0);
		do{if(nv_show5111e0(0xfe,&nv_intToString4051f0(200),&nv_intToString4051f0(10),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
	}
	if(b5){
		if(CELLP(getPosition45a4a0())->getItem45d8f0().isValid9b7230()&&CELLP(getPosition45a4a0())->getItem45d8f0()->nested457880()>=6){
			for(unsigned k=0;k<parts.size9b9260();k++){
				if(parts.at9b81f0(k)->u457f90()==0x9e&&parts.at9b81f0(k)->getType44aec0()==3&&parts.at9b81f0(k)->getEffectValue457be0(0x46)==1&&parts.at9b81f0(k)->u457d70()&&(parts.at9b81f0(k)->getEffectValue457be0(0x47)==-1||parts.at9b81f0(k)->u457cf0()&&parts.at9b81f0(k)->getEffectValue457be0(0x47)<parts.at9b81f0(k)->def9b4350()->getValue457330(0x47))){
					NvHI p=parts.at9b81f0(k);
					NvHI ra11=CELLP(getPosition45a4a0())->getItem45d8f0();
					int total=p->u45cb30()+nv_maxInt9cdb60(1,(int)(ra11->u9b6bf0()*::rng.rangeFloat406e20(1.0-nv_ba09d4,1.0+nv_ba09d4)));
					int n=total/p->u457fb0();
					if(n!=0){
						p->u44fc60(total-p->u457fb0()*n);
						int ra15=p->def9b4350()->getValue457330(0x47);
						NvEffPair*e=p->getEffect457b70(0x47);
						if(e->value==-1){
							e->value=n;
							if(!u5dc440(p))nv_cec088->toggle8993e0(nv_cec088->u894e70(p),1);
						}else e->value+=n;
						if(e->value>=ra15){
							p->u44fc60(0);
							e->value=ra15;
						}
						do{if(nv_show5111e0(0x59,&p->getName571db0(0,0),&ra11->getName571db0(0,0),&nv_countString407a80(n,nv_be6b8c),self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						nv_sound4541b0(0xd3,0,0);
						if(p->u9b6bf0()<p->u457c80()){
							p->u458360(nv_d035c8.random40c130()*n);
							nv_cec088->u894e70(p)->drawStatus4a8e70(0);
						}
					}else{
						p->u44fc60(total);
						do{if(nv_show5111e0(0x58,&p->getName571db0(0,0),&ra11->getName571db0(0,0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						nv_sound4541b0(0xd2,0,0);
					}
					ra11->remove57dbe0(0,0,1,1);
					break;
				}
			}
		}
		for(unsigned k=0;k<parts.size9b9260();k++){
			if(parts.at9b81f0(k)->u457f90()==0x9e&&parts.at9b81f0(k)->getType44aec0()==3&&parts.at9b81f0(k)->getEffectValue457be0(0x46)==2&&parts.at9b81f0(k)->u457d70()&&(parts.at9b81f0(k)->getEffectValue457be0(0x47)==-1||parts.at9b81f0(k)->u457cf0()&&parts.at9b81f0(k)->getEffectValue457be0(0x47)<parts.at9b81f0(k)->def9b4350()->getValue457330(0x47))){
				NvHI p=parts.at9b81f0(k);
				NvVecPt b7;
				int c5=p->u578f20(b7,&nv_caf2a0);
				nv_clampMax9cf5a0(c5,0x19);
				nv_d2c658.add4729d0(0x20a,c5,"",-1);
				if(nv_d2c658.get472c70(0x20a)>=1000)nv_cf45d8.unlock77fbc0(0xd4);
				nv_shuffle9d7350(b7);
				int b_;
				int got=0;
				for(unsigned c=0;c<b7.size9b9a50()&&c5!=0;c++){
					b_=CELLP(b7.at9e7c10(c))->u45a6e0();
					if(b_>c5){
						got+=c5;
						c5=0;
					}else{
						got+=b_;
						c5-=b_;
					}
					CELLP(b7.at9e7c10(c))->u66d470(self,b_,0,0);
				}
				int total=p->u45cb30()+got;
				int n=total/p->u457fb0();
				if(n!=0){
					p->u44fc60(total-p->u457fb0()*n);
					int ra22=p->def9b4350()->getValue457330(0x47);
					NvEffPair*e=p->getEffect457b70(0x47);
					if(e->value==-1){
						e->value=n;
						if(!u5dc440(p))nv_cec088->toggle8993e0(nv_cec088->u894e70(p),1);
					}else e->value+=n;
					if(e->value>=ra22){
						p->u44fc60(0);
						e->value=ra22;
					}
					do{if(nv_show5111e0(0x5a,&p->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					nv_sound4541b0(0xd4,0,0);
				}else p->u44fc60(total);
			}
		}
	}
	for(unsigned k=0;k<parts.size9b9260();k++){
		if(parts.at9b81f0(k)->u457f90()==0x9e&&parts.at9b81f0(k)->getEffectValue457be0(0x46)<0&&parts.at9b81f0(k)->u457d70()&&parts.at9b81f0(k)->getEffectValue457be0(0x47)==-1){
			NvHI p=parts.at9b81f0(k);
			int kB=-parts.at9b81f0(k)->getEffectValue457be0(0x46);
			NvHI m5=CELLP(getPosition45a4a0())->getItem45d8f0();
			if(m5.isNull9b65d0()||m5->nested457820()!=kB){
				m5.reset9b7270();
				for(unsigned ra26=0;ra26<parts.size9b9260();ra26++){
					if(parts.at9b81f0(ra26)->nested457820()==kB){m5=parts.at9b81f0(ra26);break;}
				}
			}
			if(m5.isValid9b7230()){
				int ra33=p->def9b4350()->getValue457330(0x47);
				NvEffPair*e=p->getEffect457b70(0x47);
				e->value=ra33;
				if(b5){
					if(p->getType44aec0()!=4&&!u5dc440(p)){
						NvCPart*ra37=nv_cec088->u894e70(p);
						if(ra37)nv_cec088->toggle8993e0(ra37,1);
					}
					do{if(nv_show5111e0(0x5b,&p->getName571db0(0,0),&m5->getName571db0(0,0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
				}else{
					do{if(nv_show5111e0((isHostileTo45aa70(nv_cefc4c->getPlayer4630f0())!=0)+0x5c,&p->getName571db0(0,0),&m5->getName571db0(0,0),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
				}
				nv_sound454260(getPosition45a4a0(),0xd5);
				m5->remove57dbe0(1,0,1,1);
			}
		}
	}
	if(b5){
		NvVecHI3 sorted;
		for(unsigned k=0;k<parts.size9b9260();k++){
			if(parts.at9b81f0(k)->u457cf0()&&parts.at9b81f0(k)->u457f90()==0xa0){
				if(sorted.empty9b86e0()||parts.at9b81f0(k)->u457fb0()<=sorted.back9b6540()->u457fb0())sorted.push_back9b80b0(parts.at9b81f0(k));
				else{
					for(unsigned ra42=0;ra42<sorted.size9b9260();ra42++){
						if(parts.at9b81f0(k)->u457fb0()>sorted.at9b81f0(ra42)->u457fb0()){nv_insert9d8fc0(sorted,ra42,parts.at9b81f0(k));break;}
					}
				}
			}
		}
		if(!sorted.empty9b86e0()){
			for(unsigned ra46=0;ra46<sorted.size9b9260();ra46++){
				int rb12=sorted.at9b81f0(ra46)->u45cb30();
				if(rb12!=0){
					int amt=nv_minInt9cdb30(rb12,sorted.at9b81f0(ra46)->u457fb0()/10);
					int rb16=u5deb40(amt);
					amt-=rb16;
					sorted.at9b81f0(ra46)->u44fc60(rb12-amt);
				}
			}
			if(CELLP(getPosition45a4a0())->getItem45d8f0().isValid9b7230()&&CELLP(getPosition45a4a0())->getItem45d8f0()->nested457880()!=0&&CELLP(getPosition45a4a0())->getItem45d8f0()->nested457880()!=3){
				NvHI rb30=CELLP(getPosition45a4a0())->getItem45d8f0();
				for(unsigned rb34=0;rb34<sorted.size9b9260();rb34++){
					if(sorted.at9b81f0(rb34)->u458220()){
						if(rb30.operator->()==0)break;
						int rb38=rb30->u577600(sorted.at9b81f0(rb34)->u457fb0());
						int rc32;
						if(rc32=sorted.at9b81f0(rb34)->nested457900()*50-sorted.at9b81f0(rb34)->u45cb30()){
							if(rc32<rb38)rb38=rc32;
							sorted.at9b81f0(rb34)->u44fc60(sorted.at9b81f0(rb34)->u45cb30()+rb38);
							do{if(nv_show5111e0(0x51,&sorted.at9b81f0(rb34)->getName571db0(0,0),&rb30->getName571db0(0,0),&nv_intToString4051f0(rb38),self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							nv_sound4541b0(0xd6,0,0);
							if(nv_cefb48!=0&&rb30->u457920()>nv_d1e888->u46ed20()&&nv_cefb48!=0)nv_cefb48->say49e250(rb30.eq9b78e0t(nv_cefc4c->getEntity463110t()->ai45b590t()->u4592c0t())?0x1b:0x1c,0,rb30->getName571db0(0,0));
							int b=0;
							int a=0;
							if(rb30->u457ff0()&&rb30->u45cb30()){
								switch(rb30->u457f90()){
								case 8:b=rb30->u45cb30();break;
								case 9:a=rb30->u45cb30();break;
								}
							}
							rb30->remove57dbe0(1,0,1,1);
							u5e2b00(a,getPosition45a4a0());
							if(b!=0)u5ded70(b);
							nv_d2c658.add4729d0(0xd8,1,"",-1);
							nv_d2c658.add4729d0(0xd9,rb38,"",-1);
						}
					}
				}
			}
		}
	}
	if(getFaction45a2c0()==0||getFaction45a2c0()==0x30){
		for(unsigned k=0;k<parts.size9b9260();k++){
			if(parts.at9b81f0(k)->u457d50()&&parts.at9b81f0(k)->getType44aec0()<=3&&(fp.isValid9b7230()||::rng.chance406c90(nv_b95a0c[parts.at9b81f0(k)->nested4578a0()]))){
				parts.at9b81f0(k)->u5797c0();
				if(b5){
					do{if(nv_show5111e0(0x74,&parts.at9b81f0(k)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					nv_sound4541b0(0x60,0,0);
					nv_cec054->u49adc0(2000);
					nv_cec088->u896a80(parts.at9b81f0(k));
					if(parts.at9b81f0(k)->nested4578c0()>1)nv_cec088->u896820(parts.at9b81f0(k));
				}
			}
		}
	}
	int h1=u5cab30();
	nv_fn9d0690(&i98,u5ca960(),h1);
	if(nv_cefc4c->u463d40()<0)nv_fn9d0690(&i98,-nv_cefc4c->u463d40(),h1);
	if(nv_d25450.b0&&nv_d25564!=0&&isPlayer5c7600())h1=nv_minInt9cdb30(-0x29a,h1);
	if(i98>=NVCAP&&u5d2380(2).isValid9b7230()&&i98>u5d22a0(0x28)){
		NvVecHI3 list;
		u5d2430(2,list);
		nv_shuffle9d9fc0b(list);
		int dA=nv_maxInt9cdb60(NVCAP,u5d22a0(0x28));
		for(unsigned k=0;i98>dA&&k<list.size9b9260();k++){
			nv_fn9d0690(&i98,list.at9b81f0(k)->u457fb0(),h1);
			if(list.at9b81f0(k)->u9b6bf0()<=2){
				do{if(nv_show5111e0(0x190,&list.at9b81f0(k)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
				list.at9b81f0(k)->remove57dbe0(1,0,6,1);
			}else{
				list.at9b81f0(k)->u458310(2);
				if(b5){
					NvCPart*rc36=nv_cec088->u894e70(list.at9b81f0(k));
					if(rc36)rc36->drawStatus4a8e70(1);
				}
			}
		}
	}
	if(i98>NVCAP){
		if(u5d2380(4).isValid9b7230()&&i98>u5d22a0(0x28)){
			NvVecHI3 list;
			u5d2430(4,list);
			int dX=nv_maxInt9cdb60(NVCAP,u5d22a0(0x28));
			int rd30=(i98-dX)/list.size9b9260();
			i98=nv_minInt9cdb30(NVCAP,dX);
			for(unsigned k=0;k<list.size9b9260();k++){
				int rd34=rd30/list.at9b81f0(k)->u457fb0();
				if(rd34!=0){
					if(list.at9b81f0(k)->u9b6bf0()<=rd34){
						do{if(nv_show5111e0(0x190,&list.at9b81f0(k)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						list.at9b81f0(k)->remove57dbe0(1,0,6,1);
					}else{
						list.at9b81f0(k)->u458310(rd34);
						if(b5){
							NvCPart*rd38=nv_cec088->u894e70(list.at9b81f0(k));
							if(rd38)rd38->drawStatus4a8e70(1);
						}
					}
				}
			}
		}
		if(i98>NVCAP&&u5d2380(5).isValid9b7230()&&i98>u5d22a0(0x28)){
			NvHI hC=u5d24e0(5);
			int re35;
			int aI=nv_maxInt9cdb60(NVCAP,u5d22a0(0x28));
			int y8=nv_maxInt9cdb60(1,(i98-aI)/hC->u457fb0());
			NvVecU2 slots;
			slots.push_back9b9280(5);
			slots.push_back9b9280(4);
			int aP=0;
			do{
								if(y8>5){
					re35=5;
					y8-=5;
				}else{
					re35=y8;
					y8=0;
				}
				NvHI m7=u5e3cb0b(0,-1,slots,0,0);
				if(m7.isNull9b65d0()){
					if(aP==0)goto skip5;
					else break;
				}else if(m7->u9b6bf0()<=re35){
					do{if(nv_show5111e0(0x190,&m7->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					m7->remove57dbe0(1,1,6,1);
				}else{
					m7->u458310(re35);
					if(b5){
						NvCPart*re39=nv_cec088->u894e70(m7);
						if(re39)re39->drawStatus4a8e70(1);
					}
				}
				aP++;
			}while(y8!=0);
			i98=nv_minInt9cdb30(NVCAP,aI);
skip5:;
		}
	}
	if(b5){
		nv_d2c658.add4729d0(0x1e6,i98,"",-1);
		nv_d2c658.add4729d0(0x1e7,i98,"",-1);
		if(i98>=500)nv_cf45d8.unlock77fbc0(4);
	}
	if(b5){
		bool rf21=false;
		if(nv_d28d50!=0){
			if(i98<nv_d28d50)nv_d1da49=0;
			else if(!nv_d1da49&&!rf21&&nv_cefc4c->getTurn464270()>=nv_d1da50){
				nv_cec0f4->add7b1880(new NvPhrase(0x5c,0,0,0,NvHE(),NvHE()));
				nv_sound4541b0(0x5d,0,0);
				nv_d1da49=1;
				nv_d1da50=nv_cefc4c->getTurn464270()+15;
				rf21=true;
			}
		}
		if(nv_d28d54!=0){
			if(u45a880()>nv_d28d54)nv_d1da4a=0;
			else if(!nv_d1da4a&&!rf21&&nv_cefc4c->getTurn464270()>=nv_d1da54){
				nv_cec0f4->add7b1880(new NvPhrase(0x5d,0,0,0,NvHE(),NvHE()));
				nv_sound4541b0(0x5c,0,0);
				nv_d1da4a=1;
				nv_d1da54=nv_cefc4c->getTurn464270()+15;
				rf21=true;
			}
		}
		if(nv_d28d58!=0){
			if(u45a8f0()>nv_d28d58)nv_d1da4b=0;
			else if(!nv_d1da4b&&!rf21&&nv_cefc4c->getTurn464270()>=nv_d1da58){
				nv_cec0f4->add7b1880(new NvPhrase(0x5e,0,0,0,NvHE(),NvHE()));
				nv_sound4541b0(0x5d,0,0);
				nv_d1da4b=1;
				nv_d1da58=nv_cefc4c->getTurn464270()+15;
				rf21=true;
			}
		}
		if(nv_d28d5c!=0){
			if(!u5ca670()||u45a940()>nv_d28d5c)nv_d1da4c=0;
			else if(!nv_d1da4c&&!rf21&&nv_cefc4c->getTurn464270()>=nv_d1da5c){
				nv_cec0f4->add7b1880(new NvPhrase(0x5f,0,0,0,NvHE(),NvHE()));
				nv_sound4541b0(0x5d,0,0);
				nv_d1da4c=1;
				nv_d1da5c=nv_cefc4c->getTurn464270()+15;
				rf21=true;
			}
		}
	}
	if(ff0!=0&&i70==0){
		if(ff0->u458950(0x3c)){
			NvEffX*rf25=ff0->u458950(0x3c);
			if(nv_cefc4c->getTurn464270()>=rf25->f4){
				NvHI rf29=u5d1150(NvHE());
				if(rf29.isValid9b7230()){
					NvExplDef*x=rf29->def9b4350()->x1a8;
					do{if(nv_show5111e0(0x1a2,&rf29->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					if(nv_cefc4c->getPlayer4630f0()->isHostileTo45aa70(self)&&rf25->h18==nv_cefc4c->getPlayer4630f0())nv_cf45d8.unlock77fbc0(0x6b);
					rf29->remove57dbe0(0,0,1,1);
					nv_cefc4c->addRecord777a20(nv_cefaa8->createA7930e0(new NvExpl(NvHE(),x,u45a4c0(),NvHE(),NvPos(-1),NvPos(-1))));
					if(aG.operator->()==0)return;
				}
				u45aeb0(rf25);
			}else{
				nv_cec054->showTimer8176a0(2,getPosition45a4a0(),rf25->f4-nv_cefc4c->getTurn464270(),0);
				nv_cec054->u49b050()->h1c=self;
				nv_cec054->u49b050()->p14=NvPos(1,0);
				nv_cec054->u49b050()->f28.u409ff0(0);
				nv_cec054->u49b050()->b30=1;
			}
		}
		if(ff0!=0&&ff0->u458950(0x3d)){
			NvHI a=u5d1150(NvHE());
			if(a.isValid9b7230()){
				NvHI b=u5d1150b(a);
				NvHE rf32;
				NvVecHE6 ents5;
				u5c8880(ents5);
				nv_shuffle9d9fc0c(ents5);
				for(unsigned k=0;k<ents5.size9b9260();k++){
					b=ents5.at9b81f0(k)->u5d1150(NvHE());
					if(b.isValid9b7230()){
						rf32=ents5.at9b81f0(k);
						break;
					}
				}
				if(b.isValid9b7230()){
					nv_cefc4c->u465380();
					if(rf32.isNull9b65d0())rf32=self;
					NvExplDef*x=b->def9b4350()->x1a8;
					do{if(nv_show5111e0((rf32->isPlayer5c7600()!=0)+0x1a3,&b->getName571db0(0,0),0,0,rf32,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					NvEffX*g5=ff0->u458950(0x3d);
					if(nv_cefc4c->getPlayer4630f0()->isHostileTo45aa70(rf32)&&g5->h18==nv_cefc4c->getPlayer4630f0())nv_cf45d8.unlock77fbc0(0x6b);
					bool iA=(a->u457b50()->isPlayer5c7600()||b->u457b50()->isPlayer5c7600())&&g5->h18==nv_cefc4c->getPlayer4630f0();
					b->remove57dbe0(1,1,1,1);
					nv_cefc4c->addRecord777a20(nv_cefaa8->createA7930e0(new NvExpl(NvHE(),x,u45a4c0(),NvHE(),NvPos(-1),NvPos(-1))));
					if(aG.operator->()==0)return;
					x=a->def9b4350()->x1a8;
					do{if(nv_show5111e0((isPlayer5c7600()!=0)+0x1a3,&a->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					if(nv_cefc4c->getPlayer4630f0()->isHostileTo45aa70(self)&&g5->h18==nv_cefc4c->getPlayer4630f0())nv_cf45d8.unlock77fbc0(0x6b);
					a->remove57dbe0(0,0,1,1);
					nv_cefc4c->addRecord777a20(nv_cefaa8->createA7930e0(new NvExpl(NvHE(),x,u45a4c0(),NvHE(),NvPos(-1),NvPos(-1))));
					if(aG.operator->()==0)return;
					if(g5!=0)u45aeb0(g5);
					if(iA&&nv_d25450.b0)nv_d25450.u69e700(0x1f,0,0.0f);
				}
			}
		}
	}
	for(unsigned k=0;k<parts.size9b9260();k++){
		if(parts.at9b81f0(k)->u457cf0()&&parts.at9b81f0(k)->nested4578a0()==0){
			if(parts.at9b81f0(k)->u458220()&&::rng.chance406c90(parts.at9b81f0(k)->u457f10())){
				do{if(nv_show5111e0(0x179,&parts.at9b81f0(k)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
				if(parts.at9b81f0(k)->takeDamage57ab10(parts.at9b81f0(k)->u457c80()*nv_d395a4.random40c130()/100,1,0,0,NvHE(),0,0)){
					k--;
					continue;
				}else{
					u5fd550(parts.at9b81f0(k),nv_d2c464.random40c130()+1);
					if(b5){
						NvCPart*rf36=nv_cec088->u894e70(parts.at9b81f0(k));
						if(rf36)rf36->u890710(0);
					}
				}
			}
			if(i98>300&&::rng.chance406c90((i98-300)/5)&&!::rng.chance406c90(parts.at9b81f0(k)->u457ef0())){
				if(u5d24e0(6).isValid9b7230()){
					do{if(nv_show5111e0(0x142,&u5d24e0(6)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
				}else{
					u5fd550(parts.at9b81f0(k),nv_cfb688.random40c130()+1);
					if(b5){
						NvCPart*rg21=nv_cec088->u894e70(parts.at9b81f0(k));
						if(rg21)rg21->u890710(0);
					}
					do{if(nv_show5111e0(0x143,&parts.at9b81f0(k)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					if(b5){
						nv_d2c658.add4729d0(0x1ea,1,"",-1);
						nv_d2c658.add4729d0(0x1eb,1,"",-1);
					}
				}
			}
		}
	}
	if(b5){
		if(i98>=nv_b961cc&&i98>=u5d22a0(0x28)){
			int is=u5ca840();
			int bonus=u5d22a0(6)/10;
			if(bonus!=0)bonus+=15;
			if(::rng.chance406c90(nv_b961b4[is])){
				NvVecU2 rg25;
				for(int t=0;t<7;t++){
					if(i98>=(&nv_b961cc)[t])rg25.push_back9b9280(+t);
				}
				if(!rg25.empty9b86e0()){
					int pick=nv_randomRec9d5d00c(rg25);
					switch(pick){
					case 0:
						if(i90==0)break;
						if(::rng.chance406c90(bonus)){
							if(b5){
								do{if(nv_show5111e0(0x144,&u5d2380(6)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							}
						}else{
							int drain=nv_maxInt9cdb60(1,::rng.rangeInt406d70(nv_c36e30,nv_c37034)*i90/100);
							u45b1b0(drain);
							do{if(nv_show5111e0(0x145,&nv_intToString4051f0(drain),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							if(b5){
								nv_d2c658.add4729d0(0x1ea,1,"",-1);
								nv_d2c658.add4729d0(0x1ec,1,"",-1);
							}
						}
						break;
					case 1:{
						bool rg29=false;
						NvVecHI3 rh21;
						if(u5cb930(rh21)){
							for(int j=rh21.size9b9260()-1;j>=0;j--){
								if(rh21.at9b81f0(j)->u457ad0()||rh21.at9b81f0(j)->nested4578a0()!=2&&rh21.at9b81f0(j)->nested4578a0()!=3||rh21.at9b81f0(j)->def9b4350()->f94==2)nv_eraseAt9da940b(rh21,j);
							}
							if(!rh21.empty9b86e0()){
								nv_shuffle9d9fc0b(rh21);
								int rh25=::rng.rangeInt406d70(1,nv_minInt9cdb30(3,rh21.size9b9260()));
								for(int n=0;n<rh25;n++){
									if(::rng.chance406c90(bonus)&&u5d2380(6).isValid9b7230()){
										if(b5){
											do{if(nv_show5111e0(0x146,&u5d2380(6)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
										}
									}else{
										NvHI p=nv_randomRecord9dafb0(rh21);
										u5fd550(p,::rng.rangeInt406d70(nv_c370a4,nv_c36fbc));
										if(b5){
											NvCPart*rh29=nv_cec088->u894e70(p);
											if(rh29)rh29->u890710(0);
										}
										if(!rg29){
											do{if(nv_show5111e0(0x147,0,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
											rg29=true;
										}
										do{if(nv_show5111e0(0x148,&p->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
										if(b5){
											nv_d2c658.add4729d0(0x1ea,1,"",-1);
											nv_d2c658.add4729d0(0x1ed,1,"",-1);
										}
									}
								}
							}
						}
						}break;
					case 2:
						if(i94==0)break;
						if(::rng.chance406c90(bonus)){
							if(b5){
								do{if(nv_show5111e0(0x149,&u5d2380(6)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							}
						}else{
							int drain=nv_maxInt9cdb60(1,::rng.rangeInt406d70(nv_c36e30,nv_c37034)*i94/100);
							u45b1e0(drain);
							do{if(nv_show5111e0(0x14a,&nv_intToString4051f0(drain),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							if(b5){
								nv_d2c658.add4729d0(0x1ea,1,"",-1);
								nv_d2c658.add4729d0(0x1ee,1,"",-1);
							}
						}
						break;
					case 3:{
						bool rh41=false;
						NvVecHI3 rh45;
						if(u5cb930(rh45)){
							for(int j=rh45.size9b9260()-1;j>=0;j--){
								if(rh45.at9b81f0(j)->u457ad0()||rh45.at9b81f0(j)->nested457880()>=0x1a||rh45.at9b81f0(j)->u577fb0()||rh45.at9b81f0(j)->getEffect457b70(0x55)||rh45.at9b81f0(j)->def9b4350()->f94==2)nv_eraseAt9da940b(rh45,j);
							}
							if(!rh45.empty9b86e0()){
								if(::rng.chance406c90(bonus)){
									if(b5){
										do{if(nv_show5111e0(0x14b,&u5d2380(6)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
									}
								}else{
									NvHI p=nv_randomRecord9dafb0(rh45);
									do{if(nv_show5111e0(0x13e,&p->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
									p->setBroken5795b0(-2,1);
									if(!rh41){
										do{if(nv_show5111e0(0x14c,0,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
										rh41=true;
										if(nv_d25450.b0&&nv_d25450.u69eba0(p))nv_d25450.u69e700(1,0,0.0f);
									}
									if(b5){
										nv_d2c658.add4729d0(0x1ea,1,"",-1);
										nv_d2c658.add4729d0(0x1ef,1,"",-1);
									}
								}
							}
						}
						}break;
					case 4:case 5:{
						NvVecHI3 inv;
						if(u5cb8b0(inv)){
							nv_shuffle9d9fc0b(inv);
							int rh49=nv_minInt9cdb30(pick==4?1: ::rng.rangeInt406d70(1,nv_c36ed4),inv.size9b9260());
							for(int n=0;n<rh49;n++){
								if(::rng.chance406c90(bonus)){
									if(b5){
										do{if(nv_show5111e0(0x14d,&u5d2380(6)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
									}
								}else{
									NvHI p=inv.at9b81f0(n);
									int ri50=p->u9b6bf0();
									if(ri50>1){
										int ri54=nv_maxInt9cdb60(1,::rng.rangeInt406d70(nv_c37034,nv_c37038)*ri50/100);
										do{if(nv_show5111e0((pick!=4)+0x14e,&p->getName571db0(0,0),&nv_intToString4051f0(ri54),0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
										p->takeDamage57ab10(nv_minInt9cdb30(p->u9b6bf0()-1,ri54),1,0,0,NvHE(),0,0);
										if(b5){
											nv_d2c658.add4729d0(0x1ea,1,"",-1);
											nv_d2c658.add4729d0((pick!=4)+0x1f0,1,"",-1);
										}
									}
								}
							}
						}
						}break;
					case 6:
						if(::rng.chance406c90(bonus)){
							if(b5){
								do{if(nv_show5111e0(0x150,&u5d2380(6)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							}
						}else{
							bool newBig=u45a880()>=0x14;
							int nA=::rng.rangeInt406d70(nv_c36e30,nv_c36fec)*u5ca260()/100;
							do{if(nv_show5111e0(0x151,&nv_intToString4051f0(nA),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							if(b5){
								nv_d2c658.add4729d0(0x1f2,1,"",-1);
								nv_d2c658.add4729d0(0x1ea,1,"",-1);
							}
							if(takeDamage5e5520(3,0,0,nA,1,0,0,!nv_cefc4c->u4631f0(self),NvHE(),1,8,0,0,1)>=1)return;
							else if(b5&&nv_d25450.b0&&newBig&&u45a880()<0x14)nv_d25450.u69e700(3,0,0.0f);
						}
						break;
					}
				}
			}
		}
	}else{
		if(!u45ac40(0x1e)&&i98>=nv_b96200&&i98>=u5d22a0(0x28)){
			int ri58=u5ca840();
			if(::rng.chance406c90(nv_b961e8[ri58])){
				NvVecU2 rj32;
				for(int t=0;t<7;t++){
					if(i98>=(&nv_b96200)[t])rj32.push_back9b9280(+t);
				}
				if(!rj32.empty9b86e0()){
					int pick=nv_randomRec9d5d00c(rj32);
					switch(pick){
					case 0:{
						int rj36=::rng.rangeInt406d70(nv_b96104,nv_b96108-1);
						u45b210(rj36);
						do{if(nv_show5111e0(u45aaa0(nv_cefc4c->getPlayer4630f0())?0x152:0x153,&nv_intToString4051f0(rj36),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						}break;
					case 1:{
						NvVecHI3 tVal;
						if(u5cb930(tVal)){
							string names;
							for(int j=tVal.size9b9260()-1;j>=0;j--){
								if(tVal.at9b81f0(j)->u457ad0()||tVal.at9b81f0(j)->nested4578a0()!=2&&tVal.at9b81f0(j)->nested4578a0()!=3)nv_eraseAt9da940b(tVal,j);
							}
							if(!tVal.empty9b86e0()){
								nv_shuffle9d9fc0b(tVal);
								int uu23=::rng.rangeInt406d70(1,nv_minInt9cdb30(3,tVal.size9b9260()));
								for(int n=0;n<uu23;n++){
									NvHI p=nv_randomRecord9dafb0(tVal);
									u5fd550(p,::rng.rangeInt406d70(nv_c370a4,nv_c36fbc));
								}
								if(!names.empty()){
									do{if(nv_show5111e0(u45aaa0(nv_cefc4c->getPlayer4630f0())?0x154:0x155,&names,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								}
							}
						}
						}break;
					case 2:{
						NvVecHI3 uu27;
						if(u5cb930(uu27)){
							for(int j=uu27.size9b9260()-1;j>=0;j--){
								if(uu27.at9b81f0(j)->u457ad0()||uu27.at9b81f0(j)->nested457880()>=0x1a||uu27.at9b81f0(j)->u577fb0()||uu27.at9b81f0(j)->def9b4350()->f94==2)nv_eraseAt9da940b(uu27,j);
							}
							if(!uu27.empty9b86e0()){
								NvHI p=nv_randomRecord9dafb0(uu27);
								do{if(nv_show5111e0(u45aaa0(nv_cefc4c->getPlayer4630f0())?0x156:0x157,&p->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								p->setBroken5795b0(-2,0);
							}
						}
						}break;
					case 3:case 4:{
						NvVecHI3 inv;
						if(u5cb8b0(inv)){
							string names;
							nv_shuffle9d9fc0b(inv);
							int uu52=nv_minInt9cdb30(pick==3?1: ::rng.rangeInt406d70(1,nv_c36ed4),inv.size9b9260());
							for(int n=0;n<uu52;n++){
								NvHI p=inv.at9b81f0(n);
								int pG=nv_maxInt9cdb60(1,(pick==3?::rng.rangeInt406d70(nv_c370a8,nv_c36ec8): ::rng.rangeInt406d70(nv_c370ac,nv_c36eac))*p->u9b6bf0()/100);
								if(!names.empty())names+=nv_be6b94;
								names+=p->getName571db0(0,0);
								p->takeDamage57ab10(pG,1,0,0,NvHE(),0,0);
							}
							if(!names.empty()){
								do{if(nv_show5111e0(pick==3?(u45aaa0(nv_cefc4c->getPlayer4630f0())?0x158:0x159):(u45aaa0(nv_cefc4c->getPlayer4630f0())?0x15a:0x15b),&names,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							}
						}
						}break;
					case 5:{
						int uu56=::rng.rangeInt406d70(nv_c36fec,nv_c36ff0)*u5ca260()/100;
						do{if(nv_show5111e0(u45aaa0(nv_cefc4c->getPlayer4630f0())?0x15c:0x15d,&nv_intToString4051f0(uu56),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						if(takeDamage5e5520(3,0,0,uu56,1,0,0,!nv_cefc4c->u4631f0(self),NvHE(),1,8,0,0,1)>=1)return;
						}break;
					}
				}
			}
		}
	}
	if(b5){
		int vCur=u5cab90();
		nv_d2c658.add4729d0(0x1c0,vCur,"",-1);
		if(vCur>=10)nv_cf45d8.unlock77fbc0(0x14);
		if(vCur>=50)nv_cf45d8.unlock77fbc0(0x15);
		nv_d2c658.add4729d0(0x1c1,vCur,"",-1);
		if(vCur!=0&&nv_cefc4c->getTurn464270()>=nv_cf49ec){
			NvVecU2 vv12;
			for(int t=0;t<=9;t++){
				if(nv_b96218[t]!=0&&vCur>=nv_b96248[t])vv12.push_back9b9280(+t);
			}
			nv_shuffle9d8f80(vv12);
			for(unsigned k=0;k<vv12.size9b9260();k++){
				if(::rng.rangeFloat406e20(0,nv_c36ec8)<=(double)vCur/nv_b96218[vv12.at9b81f0(k)]){
					int vv16=vv12.at9b81f0(k);
					switch(vv16){
					case 0:{
						string h0(nv_be6b98);
						string myMsg;
						int n=::rng.rangeInt406d70(nv_c36fec,nv_c36ff0);
						for(int i=0;i<n;i++)myMsg+=h0[::rng.rangeInt406d70(0,h0.size()-1)];
						do{if(nv_show5111e0(0x15f,&myMsg,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						nv_d2c658.add4729d0(0x1c4,1,"",-1);
						nv_d2c658.add4729d0(0x1c5,1,"",-1);
						}break;
					case 1:{
						if(i94==0)break;
						int drain=nv_minInt9cdb30(i94,::rng.rangeInt406d70(nv_c36ed0,nv_c36e30));
						u45b1e0(drain);
						do{if(nv_show5111e0(0x162,&nv_intToString4051f0(drain),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						nv_d2c658.add4729d0(0x1c4,1,"",-1);
						nv_d2c658.add4729d0(0x1c6,1,"",-1);
						}break;
					case 2:{
						int vv42=::rng.rangeInt406d70(nv_b960ec,nv_b960f4-1);
						u45b210(vv42);
						do{if(nv_show5111e0(0x163,&nv_intToString4051f0(vv42),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						nv_d2c658.add4729d0(0x1c4,1,"",-1);
						nv_d2c658.add4729d0(0x1c7,1,"",-1);
						nv_cec054->u49adc0(1000);
						}break;
					case 3:{
						if(i90==0)break;
						int drain=nv_maxInt9cdb60(1,::rng.rangeInt406d70(nv_c36fec,nv_c36ff0)*i90/100);
						u45b1b0(drain);
						do{if(nv_show5111e0(0x164,&nv_intToString4051f0(drain),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						nv_d2c658.add4729d0(0x1c4,1,"",-1);
						nv_d2c658.add4729d0(0x1c8,1,"",-1);
						}break;
					case 4:{
						if(nv_cf462c==0xb)break;
						NvVecHI3 inv;
						if(CELLP(getPosition45a4a0())->hasBlockingObject45d7b0()&&u5cb8b0(inv)&&nv_cefc4c->u463710()){
							for(unsigned j=0;j<inv.size9b9260();j++){
								if(inv.at9b81f0(j)->def9b4350()->b1ac||inv.at9b81f0(j)->getEffect457b70(0x6e)||inv.at9b81f0(j)->getEffect457b70(0x6c)||inv.at9b81f0(j)->u457f90()==7||inv.at9b81f0(j)->u457f90()==8||inv.at9b81f0(j)->u457f90()==9||inv.at9b81f0(j)->u577fb0())nv_eraseStep9d6440(inv,j);
							}
							if(!inv.empty9b86e0()){
								NvHI p=nv_randomRecord9dafb0(inv);
								do{if(nv_show5111e0(0x160,&p->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								u5e5340(0,1,3,0,0x1f,nv_be6be4+p->getName571db0(0,0));
								u642940(p,1,1,0,4);
								nv_d2c658.add4729d0(0x1c4,1,"",-1);
								nv_d2c658.add4729d0(0x1c9,1,"",-1);
								nv_cec054->u49adc0(1000);
							}
						}
						}break;
					case 5:{
						NvVecHI3 inv;
						if(u5cb8b0(inv)){
							int already=0;
							for(unsigned j=0;j<inv.size9b9260();j++){
								if(inv.at9b81f0(j)->getEffect457b70(0x6e)){
									already++;
									nv_eraseStep9d6440(inv,j);
								}else if(inv.at9b81f0(j)->def9b4350()->b1ac||inv.at9b81f0(j)->getEffect457b70(0x6c)||inv.at9b81f0(j)->u457f90()==7)nv_eraseStep9d6440(inv,j);
							}
							if(!inv.empty9b86e0()){
								NvHI p=nv_randomRecord9dafb0(inv);
								p->addEffect4585a0(new NvEffPair(nv_d2f0f8.at9b81f0(0x6e),1));
								do{if(nv_show5111e0(0x161,&p->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
								if(nv_d25450.b0&&p->u457af0()>=5)nv_d25450.u69e700(6,0,0.0f);
								NvVecCP pJ;
								if(nv_cec088->findParts4a9a40(p,pJ)){
									nv_cec088->u89d610(p,0xb);
									for(unsigned c=0;c<pJ.size9b9260();c++){
										pJ.at9b81f0(c)->putChar4180b0(0,0,0x66);
										pJ.at9b81f0(c)->u890710(0);
									}
								}
								nv_d2c658.add4729d0(0x1c4,1,"",-1);
								nv_d2c658.add4729d0(0x1ca,1,"",-1);
								nv_cec054->u49adc0(1000);
							}
						}
						}break;
					case 6:case 7:{
						int count=vv16==6?::rng.rangeInt406d70(1,nv_c36ecc): ::rng.rangeInt406d70(nv_c36ecc,nv_c36ed0);
						NvVecU2 vv46;
						for(int n=0;n<count;n++){
							int r=nv_caf164;
							int tries=0;
							do{
								r=::rng.rangeInt406d70(0,nv_d2d1c4.size9b9260()-1);
								if(nv_cf4830.at9b81f0(r)!=0&&!nv_d2d1c4.at9b81f0(r)->b270&&nv_cf4844.at9b81f0(r)==0&&nv_cf48cc.at9b81f0(r)==0&&!u5cbdf0(r,0,0)&&!nv_containsRecord9db330b(&vv46,r)){
									vv46.push_back9b9d30i(r);
									break;
								}
								tries++;
							}while(tries<0x32);
						}
						for(unsigned k=0;k<vv46.size9b9260();k++)nv_cf4830.at9b81f0(vv46.at9b81f0(k))=0;
						NvVecIP wRef;
						if(nv_d2a298.getAll9d0c30(wRef)){
							for(unsigned k=0;k<wRef.size9b9260();k++){
								if(wRef.at9b81f0(k)->hasName4579d0()&&nv_containsRecord9db330b(&vv46,wRef.at9b81f0(k)->nested457820()))wRef.at9b81f0(k)->u458700(string());
							}
						}
						nv_cf4840-=vv46.size9b9260();
						do{if(nv_show5111e0((vv16!=6)+0x165,0,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						nv_d2c658.add4729d0(0x1c4,1,"",-1);
						nv_d2c658.add4729d0((vv16!=6)+0x1cb,1,"",-1);
						}break;
					case 8:
						if(nv_d1e888->f4==0xb&&nv_d1eb10!=0||nv_d1e888->f4==0x21&&nv_stringToInt405610(nv_d1e860.getEntryText46f6d0(nv_be6be8)))break;
						else fire63a3e0(0,NvHE());
						break;
					case 9:
						u6399e0(0xf,0);
						break;
					}
					nv_cf49ec=nv_cefc4c->getTurn464270()+15;
					break;
				}
			}
		}
	}
	for(unsigned k=0;k<parts.size9b9260();k++){
		if(parts.at9b81f0(k)->u457cf0()&&parts.at9b81f0(k)->u45a3a0()&&parts.at9b81f0(k)->u9b6bf0()>1&&::rng.chance406c90(parts.at9b81f0(k)->u45a3a0())&&!parts.at9b81f0(k)->takeDamage57ab10(1,3,0,0,NvHE(),0,0)&&parts.at9b81f0(k)->u9b6bf0()==1&&!parts.at9b81f0(k)->u457ad0()&&!parts.at9b81f0(k)->u577fb0()){
			do{if(nv_show5111e0(0x193,&parts.at9b81f0(k)->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
			parts.at9b81f0(k)->setBroken5795b0(-2,1);
		}
	}
	if(aG.operator->()==0){
		nv_logError404f10(nv_be6c34,nv_be6bfc);
		return;
	}
	pickUp5dfd80();
	if(b5&&nv_d255e4!=0&&i4c>=2)nv_cefc4c->u71f700(getPosition45a4a0(),3);
	if(b5&&nv_cefc4c->getTurn464270()%25==0){
		NvHE ww43=nv_cefc4c->u715c70();
		if(ww43.isValid9b7230()){
			bool any=false;
			for(unsigned k=0;k<parts.size9b9260();k++){
				if(nv_cf4830.at9b81f0(parts.at9b81f0(k)->nested457820())==0&&!parts.at9b81f0(k)->def9b4350()->b271){
					nv_cf45d8.u77ffb0(parts.at9b81f0(k)->nested457820(),0);
					any=true;
					do{if(nv_show5111e0(0x264,&parts.at9b81f0(k)->getName571db0(0,0),0,0,ww43,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
				}
			}
			if(any)nv_cec08c->reopen8a2ce0(4,NvHE());
		}
	}
	if(b5){
		if(nv_cefc4c->u463750()||nv_cefc4c->u463690()!=u5c7d30())nv_cefc4c->u72e4c0(self,1);
		nv_cefc4c->u721600();
		nv_cefc4c->u724480();
		nv_cefc4c->u724a10();
		nv_cefc4c->u724cf0();
		nv_cefc4c->u724f00();
	}
	for(unsigned k=0;k<parts.size9b9260();k++){
		if(parts.at9b81f0(k)->def9b4350()->fec!=0&&parts.at9b81f0(k)->getType44aec0()!=4)parts.at9b81f0(k)->u578090();
	}
	if(b5){
		if(u5cad50()==2){
			switch(nv_cefb38){
			case 1:case 2:
				nv_d2c658.add4729d0(0x1f4,1,"",-1);
				nv_cf4bb4++;
				nv_d2c658.add4729d0(0x1f5,nv_cf4bb4,"",-1);
				break;
			case 3:
				nv_d2c658.add4729d0(0x1f7,1,"",-1);
				nv_cf4bb8++;
				nv_d2c658.add4729d0(0x1f8,nv_cf4bb8,"",-1);
				break;
			case 4:
				nv_d2c658.add4729d0(0x1fa,1,"",-1);
				nv_cf4bbc++;
				nv_d2c658.add4729d0(0x1fb,nv_cf4bbc,"",-1);
				break;
			}
		}else{
			nv_cf4bb4=0;
			nv_cf4bb8=0;
			nv_cf4bbc=0;
		}
	}
	if(f8->f28==0x47&&!getTarget45a760()){
		bool ok1;
		int range=u5c7d30();
		NvRect gs;
		nv_cfd44c.getRect9b4430(getPosition45a4a0(),range,gs);
		NvVecHI3 items9;
		for(int x=gs.x1;x<=gs.x2;x++)for(int y=gs.y1;y<=gs.y2;y++){
			if(CELL(x,y)->getItem45d8f0().isValid9b7230()&&CELL(x,y)->getItem45d8f0()->nested4578a0()<4&&CELL(x,y)->getItem45d8f0()->nested457880()!=0x19&&CELL(x,y)->getItem45d8f0()->nested457880()!=0x1d&&CELL(x,y)->getItem45d8f0()->nested457880()!=0x1e&&!CELL(x,y)->getItem45d8f0()->u415ee0()&&nv_cefc4c->isReachable465230(range,getPosition45a4a0(),NvPos(x,y)))
				items9.push_back9b7cf0(CELL(x,y)->getItem45d8f0());
			else if(CELL(x,y)->getEntity45d250().isValid9b7230()&&CELL(x,y)->getEntity45d250()->getFaction45a2c0()==0x48&&CELL(x,y)->getEntity45d250()->u45acb0(0x28)==7&&nv_cefc4c->isReachable465230(range,getPosition45a4a0(),NvPos(x,y))){
				NvVHI*inv=CELL(x,y)->getEntity45d250()->getInventoryList45ab00();
				for(unsigned aDist=0;aDist<inv->size9b9260();aDist++){
					if(inv->at9b81f0(aDist)->getType44aec0()==4&&inv->at9b81f0(aDist)->nested4578a0()<4&&inv->at9b81f0(aDist)->nested457880()!=0x19&&inv->at9b81f0(aDist)->nested457880()!=0x1d&&inv->at9b81f0(aDist)->nested457880()!=0x1e&&!inv->at9b81f0(aDist)->u415ee0())items9.push_back9b80b0(inv->at9b81f0(aDist));
				}
			}
		}
		nv_shuffle9d9fc0b(items9);
		NvVecU2 ww47;
		u5c93d0(ww47);
		NvVecU2 r7;
		for(int t=0;t<4;t++){
			if(!u5c8fc0(t,0))r7.push_back9b9280(+t);
		}
		NvVecHI3 hi;
		NvVecB flags;
		for(unsigned j=0;j<items9.size9b9260();j++){
			ok1=false;
			if(!r7.empty9b86e0()&&nv_containsRecord9db330b(&r7,items9.at9b81f0(j)->nested4578a0())&&ww47.at9b81f0(items9.at9b81f0(j)->nested4578a0())>=items9.at9b81f0(j)->nested4578c0()){
				nv_fn9d51d0b(r7,items9.at9b81f0(j)->nested4578a0());
				ww47.at9b81f0(items9.at9b81f0(j)->nested4578a0())-=items9.at9b81f0(j)->nested4578c0();
				ok1=true;
			}else if(::rng.chance406c90(0x14)){
				if(ww47.at9b81f0(items9.at9b81f0(j)->nested4578a0())>=items9.at9b81f0(j)->nested4578c0()){
					ww47.at9b81f0(items9.at9b81f0(j)->nested4578a0())-=items9.at9b81f0(j)->nested4578c0();
					ok1=true;
				}else if(::rng.chance406c90(0x32)){
					NvVecHI3 k0;
					u5cb8b0(k0);
					NvHI up=nv_findUpgrade4fd9e0(items9.at9b81f0(j),k0,0);
					NvPoint aLine;
					if(up.isValid9b7230()&&nv_cefc4c->u71bc10(getPosition45a4a0(),&aLine)){
						do{if(nv_show5111e0(0x2e5,&up->getName571db0(0,0),0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
						up->u57a0f0(aLine,1,0);
						ok1=true;
					}
				}
			}
			if(ok1){
				hi.push_back9b80b0(items9.at9b81f0(j));
				if(items9.at9b81f0(j)->u457b50().isValid9b7230()){
					items9.at9b81f0(j)->u57a190(self,items9.at9b81f0(j)->nested4578a0(),0,0);
					flags.push_back9b3920(1);
				}else{
					nv_cec054->u8195a0(items9.at9b81f0(j)->u575920(),items9.at9b81f0(j)->u457a30(),3);
					items9.at9b81f0(j)->u57a190(self,items9.at9b81f0(j)->nested4578a0(),0,0);
					flags.push_back9b3920(0);
				}
			}
		}
		if(!hi.empty9b86e0()){
			string aSeen;
			string rC;
			for(unsigned aUsed=0;aUsed<hi.size9b9260();aUsed++){
				if(flags.at9b38a0(aUsed).toBool9b3ad0()){
					if(!rC.empty())rC+=nv_be6c4c;
					rC+=hi.at9b81f0(aUsed)->getName571db0(0,0);
				}else{
					if(!aSeen.empty())aSeen+=nv_be6c50;
					aSeen+=hi.at9b81f0(aUsed)->getName571db0(0,0);
				}
			}
			if(!aSeen.empty()){
				do{if(nv_show5111e0(0x2e6,&aSeen,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
			}
			if(!rC.empty()){
				do{if(nv_show5111e0(0x2e7,&rC,0,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
			}
		}
		int kA=nv_cefc4c->u717dd0();
		int j0=nv_cefc4c->u464020();
		if(j0<kA){
			bool first=false;
			for(unsigned k=0;k<parts.size9b9260();k++){
				if(parts.at9b81f0(k)->nested4578a0()==0&&!parts.at9b81f0(k)->u457d10()){
					if(!first)first=true;
					else if(::rng.chance406c90(5)){
						NvHE e=nv_cefc4c->u6c5dc0(nv_be6c54,getPosition45a4a0(),h28->type9b4350(),0,0x22,0xe,0);
						if(e.isValid9b7230()){
							do{if(nv_show5111e0(0x2e8,0,0,0,self,e,0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
							parts.at9b81f0(k)->u57a190(e,parts.at9b81f0(k)->nested4578a0(),0,0);
							k--;
							j0++;
							if(j0>=kA)break;
						}
					}
				}
			}
		}
	}
	if(nv_cf462c==6&&CELLP(getPosition45a4a0())->getItem45d8f0().isValid9b7230()&&CELLP(getPosition45a4a0())->getItem45d8f0()->nested457880()==3){
		NvHI actsD=CELLP(getPosition45a4a0())->getItem45d8f0();
		int g8=actsD->u9b6bf0();
		int used=0;
		if(getField490840()<u5ca260()){
			int base1=u5ca260()-getField490840();
			if(g8*3<=base1){
				base1=g8*3;
				used=g8;
				g8=0;
			}else{
				g8-=base1/3+base1%3;
				used=base1*3;
			}
			u5de870(base1,0);
			if(b5){
				nv_d2c658.add4729d0(0x442,base1,"",-1);
				nv_d2c658.add4729d0(0x443,base1,"",-1);
			}
			string s=nv_intToString4051f0(base1);
			if(g8==0)s+=nv_be6c5c;
			do{if(nv_show5111e0(b5?0x2fc:0x2fd,&string(nv_be6c68),&s,0,self,NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
		}else{
			NvVecHI3 inv;
			u5cb8b0(inv);
			NvVecHI3 e9;
			NvVecHI3 c9;
			int total=0;
			for(unsigned j=0;j<inv.size9b9260();j++){
				if(inv.at9b81f0(j)->u9b6bf0()<inv.at9b81f0(j)->u457c80()&&!inv.at9b81f0(j)->u457d10()&&!inv.at9b81f0(j)->u415ee0())e9.push_back9b80b0(inv.at9b81f0(j));
			}
			if(!e9.empty9b86e0()){
				do{
					int amt;
					for(unsigned j=0;j<e9.size9b9260()&&g8!=0;j++){
						amt=nv_minInt9cdb30(3,e9.at9b81f0(j)->u457c80()-e9.at9b81f0(j)->u9b6bf0());
						e9.at9b81f0(j)->u458360(amt);
						g8--;
						used++;
						total+=amt;
						nv_addUnique9d30e0c(c9,e9.at9b81f0(j));
						if(e9.at9b81f0(j)->u9b6bf0()==e9.at9b81f0(j)->u457c80())nv_eraseStep9d6440(e9,j);
					}
				}while(g8!=0&&!e9.empty9b86e0());
				if(b5){
					nv_d2c658.add4729d0(0x442,total,"",-1);
					nv_d2c658.add4729d0(0x444,total,"",-1);
					string s=nv_intToString4051f0(total);
					if(g8==0)s+=nv_be6c70;
					do{if(nv_show5111e0(0x2fc,&string(nv_be6c7c),&s,0,NvHE(),NvHE(),0,0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
					for(unsigned base8=0;base8<c9.size9b9260();base8++){
						NvCPart*best0=nv_cec088->u894e70(c9.at9b81f0(base8));
						if(best0)best0->drawStatus4a8e70(0);
					}
				}
			}
		}
		if(g8==0)actsD->remove57dbe0(0,0,1,1);
		else actsD->set450460(g8);
	}
	if(nv_cf68b4!=0&&self.operator->()&&nv_cf68b8==self&&nv_cf68f0->u672dd0(self,5)&&ai144->u9b8f00()!=0x17)nv_cf68f0->u672f20(self,5,1,"");
	if(nv_cefc14!=0)nv_cefc14->u7ace20(self);
	if(b5&&nv_cefbb8!=0&&::rng.chance406c90(10)){
		nv_cefbb8=0;
		NvVecU2 tmp;
		for(int n=::rng.rangeInt406d70(nv_c36ed8,nv_c37178);n>0;n--)nv_addUnique9db000(tmp,nv_randomRec9d5d00d(&nv_d25de0));
		nv_deleteObjects9d9bb0(tmp);
	}
	if(u5cab90()>=100&&(!b5||!nv_cefaef||nv_cefaf4==0)){
		if(nv_d25450.b0&&b5){
			nv_d25450.u69e700(0x7b,0,0.0f);
			if(nv_d25450.u69edf0()){
				nv_d25450.u69ee30(0,1,1);
				goto endDie;
			}
		}
		if(b5)nv_cf4b38=0xb;
		else if(h28->type9b4350()<=2)nv_d2c658.add4729d0(0x3b1,1,"",-1);
		do{if(nv_show5111e0e(u45aaa0(nv_cefc4c->getPlayer4630f0())?0x8e:0x8f,0,0,0,self,NvHE(),u45a4c0(),0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
		die633790(!nv_cefc4c->u4631f0(self),0xa,NvHE(),2,0,0,0,0);
endDie:;
	}else if(bac){
		if(h28->type9b4350()<=2)nv_d2c658.add4729d0(0x3b2,1,"",-1);
		do{if(nv_show5111e0e(u45aaa0(nv_cefc4c->getPlayer4630f0())?0x91:0x92,0,0,0,self,NvHE(),u45a4c0(),0))nv_cec058->bubble8758d0(1);nv_cec0b4->scrollToEnd7b4f10();}while(0);
		die633790(!nv_cefc4c->u4631f0(self),0xa,NvHE(),3,0,0,0,0);
	}
}
