// NOTE: CInfo::trigger (0x8b5250, CInfo vtable slot 11) on private placeholder views; placeholder names/layouts throughout.
// Tg prefix = private placeholder types (tango/victor). Locals renamed to hit exe frame offsets (name buckets).
// Draft and notes: scratch/victor/NOTES.md.
#include <string>
using namespace std;
struct TgPos{int x,y;};
struct TgColor{unsigned char r,g,b;TgColor(const TgColor&);};extern TgColor*tg_cf44c0;
class XConsole{public:virtual ~XConsole();virtual void resize(int,int);virtual bool mouseEnter();virtual void mouseLeave();virtual bool input(void*);virtual void inputMouse(int,int);virtual void update();virtual void render();
 int getHeight4174c0();int width44b0d0();void putChar418110(int,int,int,TgColor);char pad04[0x60-0x04];};
struct TgRect{int l,t,r,b;TgRect(int,int,int,int);TgRect(const TgRect&)throw();};
class Console:public XConsole{public:Console(XConsole*,TgRect,int,bool,int);void animate48c3f0(string);virtual ~Console();virtual void render();virtual void open();virtual void close();virtual int getFrame();virtual void trigger(const string&,int);int u60;struct TgEngine*engine;void*title;int printWrapped418260(int,int,int,int,const string&);};
struct TgEntity;struct TgItem;struct TgProp;
struct TgPosM;struct TgHE{int id;TgEntity*operator->()const;bool isValid()const;bool operator==(TgHE)const;};
struct TgHI{int id;TgItem*operator->()const;TgItem*ptr9b65b0()const throw();bool isValid()const;};
struct TgHP{int id;TgProp*operator->()const;bool isValid()const;};
struct TgVecU{int pv0,pv1,pv2,pv3;TgVecU();~TgVecU();void push_back9b9280(int&&);int&operator[](unsigned)throw();int&front9b7060();unsigned size9b9260()const;bool empty9b86e0()const;};
struct TgVecHI{int pv0,pv1,pv2,pv3;TgVecHI();~TgVecHI();unsigned size9b9260()const;TgHI&operator[](unsigned);bool empty9b86e0()const;TgHI&back9b6540();TgHI&front9b7060();void pop_back9e8cd0();void push_back9b80b0(const TgHI&);TgVecHI&operator=(const TgVecHI&);void clear9b73d0();};
void tg_eraseAt9da940(TgVecHI&,int);void tg_insert9d8fc0(TgVecHI&,unsigned,TgHI);void tg_eraseStep9d6440(TgVecHI&,unsigned&);
struct TgAI{int u459300();};
struct TgEntDef{string getName459a40();string getSuffix459e00();char pad0[0xe4];int fe4;char padE8[0xfc-0xe8];TgVecU vfc;char pad10c[0x170-0x10c];string name170;char pad18c[0x210-0x18c];int f210;int f214;};
struct TgEntity{int nested457820();bool u5cd5d0();bool u5c80a0();void u5cd490(TgVecU&);TgAI*ai45b590();void u5cb8b0(TgVecHI&);int u5ccb50(TgHI);bool isPlayer5c7600();double u5d7bc0();int u5ccab0();bool u5c7f70();void u5cb830(TgVecHI&);int getFaction45a2c0();int u5cca00();int u5c7fc0(TgHE);int u5d1390();int u44a7d0();int u45a700();bool u5d1280(int);int u5cad50();int u490840();int u5ca260();int u45a990();int u5ca840();int getTarget45a760();bool u45ade0();bool u45aaa0(TgHE);int u45aa50();int u45aa30();TgEntDef*def9b4350();int u45a340();int u5cccc0();int u5c8cb0();int u5d1ee0();int u5c8d40(int,int);int u5d1d70();int u5d15a0(int);int u5c8e20(int);int u5ca210();int u5d1070();float u5ca4f0();float u5d1e40();int u5ca6c0();int u45a920();int u5ca960();int u5ca8d0();int u5d1da0();int u5c7d30();int u5c7d80(int);TgHI u5d2380(int);int u5d22a0(int);int u45a3c0();int u5c7e40();int u5cb570(int,bool);int u5d2150(int,int);double u5d7bf0(int);};
struct TgArt{int a;bool empty9b81b0();};struct TgRange{string rangeToString40c2b0(string);};struct TgExpl{char pad0[0x2c];int f2c;int f30;int f34;int f38;int f3c;int f40;TgRange p44;char pad48[0x58-0x48];int f58;int f5c;int f60;int f64;};struct TgItemDef{char pad0[0x24];string name24;char pad40[0x54-0x40];int f54;char pad58[0x70-0x58];int f70;char pad74[0x7c-0x74];TgArt art7c;char pad80[0x94-0x80];int f94;char pad98[0xec-0x98];int fec;char padF0[0xfc-0xf0];bool bfc;char padFD[0x120-0xfd];int f120;int f124;int f128;int f12c;char pad130[0x134-0x130];int f134;int f138;TgVecU v13c;int f14c;int f150;int f154;int f158;char pad15c[0x164-0x15c];bool b164;char pad165[0x1a0-0x165];struct TgExpl*f1a0;char pad1a4[0x1a8-0x1a4];int f1a8;bool b1ac;char pad1ad[0x1f4-0x1ad];TgVecU v1f4;int f204;char pad208[0x284-0x208];int f284;string desc288;void describe55f080(string&);string getSuffix457650();};
struct TgItem{TgItemDef*def9b4350();string getName571db0(int,int);const string&u457860();TgItemDef*defnt9b4350()throw();int u4580a0();int u5788e0();int u5789c0();int u578a70();int u458100();int u578b10();int u4580e0();int u458160();int u4580c0();int u458140();int u458120();int u577c90();int u457f50();int u457f30();float u577d80();int u577df0();int u577e60();int u577f30();int u457f70();int u577bd0();int u457ed0();int u457f10();float u457df0();int u457e10();int u577b10();bool u457cf0();int u458240();int u458260();int u45a3a0();int u577fb0();int u577fd0();int u578070();bool u458220();int u457f90();bool u457d30();bool u457d50();bool u457db0();int u44ab90();int turnsLeft577ad0();bool u577940();int u577790();int getType44aec0();int getEffect457b70(int);int getEffectValue457be0(int);TgHE u457b50();int u457900();bool u415ee0();int u9b6bf0();int u457c80();bool u5773d0(int,int);int u457b30();int u457880();bool u4578e0();int u4578c0();bool hasName4579d0();string name4579f0();int u4578a0();int nested457820();string u573860(bool,int);};
struct TgPropDef{char pad0[0x60];struct TgPropRes*f60;char pad64[0x80-0x64];int f80;int f84;int f88;TgExpl*f8c;char pad90[0xa8-0x90];int ia8[7];char padC4[0xf4-0xc4];int ff4;int ff8;bool bfc;char padFD[0x124-0xfd];string s124;};
struct TgEntX{char pad0[0x1ac];string s1ac;};struct TgPropRes{char pad0[0x20];int a20[7];};struct TgProc{int f0;int f4;int f8;TgItemDef*fc;TgEntX*f10;int f14;TgVecHI v18;char pad28[0x34-0x28];TgVecU v34;};
struct TgTerm{char pad0[0x28];int f28;int f2c;bool b30;int f34;TgProc*f38;int f3c;TgVecU v40;};
struct TgProp{TgPropDef*def9b8f00();const string&u45c590();const string&getName45c5b0();int u45c630();int u45c800(int);int u45c870(int);bool u45cb50();int u457b10();int u44ab40();TgTerm*u45cb30();};
struct TgVecHP{int pv0,pv1,pv2,pv3;TgHP&front9b7060();};struct TgVecVHP{int pv0,pv1,pv2,pv3;TgVecHP&operator[](unsigned);};extern TgVecVHP tg_d31640;
struct TgMap{TgHE getPlayer4630f0();int getEntityValue465660(TgHE);int getTurn464270();bool u463e90(TgPosM&);int u464960(TgVecHP&);};extern TgMap*tg_cefc4c;
class TgText:public Console{public:TgText(XConsole*,int,int,int,const string&,int);void show4ae410();int v;};
class TgSpecial:public Console{public:TgSpecial(XConsole*,int,int,int,int,const string&,int);void show4ae4f0();int a,b;};
class TgLine:public Console{public:TgLine(XConsole*,int,int,bool,string,string);void set4aeac0(TgHI,int);int item;int prop;};
struct TgPosM{int x,y;void set40a010(int,int);};
class TgButton:public Console{public:TgButton(XConsole*,int,int,int,const string&);void animate4ae610();int v;};
struct TgHE2{int id;TgHE2();};
struct TgHP2{int id;TgHP2();};
class TgTitle:public Console{public:TgTitle(XConsole*,int,TgHE,TgHP2,int);TgTitle(XConsole*,int,TgHE2,TgHI,bool);void highlight4ae300();char pad6c[4];};
struct TgPos2{int x,y;TgPos2(int,int);TgPos2(int);};
class TgCText:public Console{public:TgCText(XConsole*,const TgPos2&,const string&,int,int,int);void setColor48c3c0(int);char pad6c[0x88-0x6c];};
class TgInfo:public Console{public:virtual void trigger(const string&,int);void add4aedc0(TgLine*);
 char pad6c[0x98-0x6c];TgHE h98;TgHI h9c;TgHP ha0;TgPosM pA4;bool bAC;char padAD[0xbc-0xad];TgPosM pBC;TgPosM pC4;TgPosM pCC;TgPosM pD4;int iDC;int iE0,iE4;Console*e8;};
class TgArtAnim:public Console{public:TgArtAnim(XConsole*,TgArt*,int,int,bool,int,int,int,const TgPos2&,int,int);void u4b29b0();char pad6c[0x88-0x6c];};
extern TgInfo*tg_cec124;struct TgCellRes{char pad0[0x20];int a20[7];};struct TgCellDef{char pad0[0x50];TgCellRes*f50;char pad54[0x68-0x54];int f68;char pad6c[0xb8-0x6c];string sb8;};extern TgCellDef*caveinWallTerrain;struct TgCell{bool u4550b0();bool u45dbb0();TgCellDef*def9fcd80();const string&name45d140();bool isEdge45dc30();bool isShortcut45dc50();void*getEffect45d350(int);bool u45db70();};struct TgCells{TgCell**atPoint9ced70(TgPosM&);};extern TgCells tg_cfd44c;extern const float tg_c370a0;extern const char tg_e_b98f17[],tg_e_b98f13[],tg_e_b98f1f[],tg_e_b98f1b[],tg_e_b98f2f[],tg_e_b98f3e[],tg_e_b98f3f[];extern const char tg_e_b98e9b[],tg_e_b98e9a[],tg_e_b98ea7[],tg_e_b98ea6[],tg_e_b98eb2[],tg_e_b98eb3[],tg_e_b98ebe[],tg_e_b98ebf[],tg_e_b98ece[],tg_e_b98ecd[],tg_e_b98ecf[],tg_e_b98ede[],tg_e_b98edd[],tg_e_b98edf[],tg_e_b98eed[],tg_e_b98eee[],tg_e_b98eef[],tg_e_b98ef7[],tg_e_b98f01[],tg_e_b98f02[],tg_e_b98f03[],tg_e_b98f0b[],tg_e_b98f07[],tg_e_b98f0f[];extern string tg_d39f30[];extern const char tg_e_b98da1[],tg_e_b98da2[],tg_e_b98da3[],tg_e_b98db5[],tg_e_b98db6[],tg_e_b98db7[],tg_e_b98dc3[],tg_e_b98e05[],tg_e_b98e06[],tg_e_b98e07[],tg_e_b98e1f[],tg_e_b98e2b[],tg_e_b98e37[],tg_e_b98e5d[],tg_e_b98e5e[],tg_e_b98e5f[],tg_e_b98e83[],tg_e_b98e99[];void tg_logError404f10(string,string);string tg_toUpper4083a0(const string&);extern int tg_cebf0c,tg_cebfe0,tg_cebf20,tg_cebfb8,tg_cebf14,tg_cebf74,tg_cebf48,tg_cebf10,tg_cebf54,tg_cebfec,tg_cebef0,tg_cebfe4,tg_cebf04;extern const char tg_e_b98d7f[],tg_e_b98d7e[],tg_e_b98d8b[],tg_e_b98d8a[],tg_e_b98d95[],tg_e_b98d96[],tg_e_b98d97[];extern bool tg_d28d25;extern int tg_cebd5c;struct TgRec{string s0;string s1c;};extern TgRec tg_d035d8[];extern const char tg_e_b98bcb[],tg_e_b98bde[],tg_e_b98bdf[],tg_e_b98c83[],tg_e_b98c9b[],tg_e_b98cb3[],tg_e_b98ccb[],tg_e_b98ce3[],tg_e_b98cfb[],tg_e_b98d13[],tg_e_b98d2b[],tg_e_b98d43[],tg_e_b98d5b[],tg_e_b98d67[],tg_e_b98d72[],tg_e_b98d73[];struct TgPt{int x,y;TgPt(const TgPt&);};extern TgPt tg_d2e20c;struct TgFx{void init50de10(TgEngine*,int,const TgPos2&,const TgPt&,const TgPos2&,const TgPt&,int);};struct TgEngine{TgFx*u50fb50();};extern int tg_cf0db0,tg_cf0db4;string tg_truncate408490(const string&,int);extern const char tg_e_b98b83[],tg_e_b98b92[],tg_e_b98b93[],tg_e_b98bb6[],tg_e_b98bb7[],tg_e_b98bca[];extern const char tg_e_b98a7e[],tg_e_b98a7d[],tg_e_b98a91[],tg_e_b98a7f[],tg_e_b98a93[],tg_e_b98a92[],tg_e_b98a9f[],tg_e_b98aab[],tg_e_b98ab7[],tg_e_b98ac3[],tg_e_b98acf[],tg_e_b98ae7[],tg_e_b98adb[],tg_e_b98afb[],tg_e_b98b0e[],tg_e_b98b0f[],tg_e_b98b22[],tg_e_b98b47[],tg_e_b98b23[],tg_e_b98b6f[];void tg_clampMax9cf5a0(int*,int);void tg_fn9d06d0(int*,int,int);extern string tg_d1e058[];extern const char tg_e_b989ee[],tg_e_b989f6[],tg_e_b989ef[],tg_e_b989f7[],tg_e_b989fe[],tg_e_b989ff[],tg_e_b98a07[],tg_e_b98a27[],tg_e_b98a32[],tg_e_b98a33[],tg_e_b98a6e[],tg_e_b98a6d[],tg_e_b98a6f[];extern int tg_cebfe8;extern const float tg_c370a4;extern string tg_cf6648[],tg_d31b68[];extern int tg_b96178[],tg_b9654c[];extern const char tg_e_b987e7[],tg_e_b987f7[],tg_e_b987f6[],tg_e_b98813[],tg_e_b98823[],tg_e_b98837[],tg_e_b98846[],tg_e_b98845[],tg_e_b98847[],tg_e_b98853[],tg_e_b9886f[],tg_e_b98882[],tg_e_b98883[],tg_e_b98897[],tg_e_b988a6[],tg_e_b988a7[],tg_e_b989e2[],tg_e_b989d7[],tg_e_b989e3[];string tg_intToStringSigned405560(int);extern const float tg_c370a8;extern const char tg_e_b9844b[],tg_e_b9844a[],tg_e_b98452[],tg_e_b98451[],tg_e_b98453[],tg_e_b98777[],tg_e_b98776[],tg_e_b98795[],tg_e_b98787[],tg_e_b98796[],tg_e_b98797[],tg_e_b987a7[],tg_e_b987bd[],tg_e_b987be[],tg_e_b987bf[],tg_e_b987d2[],tg_e_b987d1[],tg_e_b987d3[],tg_e_b987e6[];extern const float tg_c370b0,tg_c36e30,tg_c370ac;extern string tg_d01b48[];extern const char tg_e_b97aa7[],tg_e_b97ab7[],tg_e_b97ab6[],tg_e_b97ac9[],tg_e_b97aca[],tg_e_b97acb[],tg_e_b97ae5[],tg_e_b97ae6[],tg_e_b97c0e[],tg_e_b97ae7[],tg_e_b97c0f[],tg_e_b98422[],tg_e_b9841b[],tg_e_b98423[],tg_e_b9842b[],tg_e_b9842a[],tg_e_b98432[],tg_e_b98439[],tg_e_b98433[],tg_e_b9843a[],tg_e_b98449[],tg_e_b9843b[];extern const float tg_c36fc0,tg_c37030;extern const char tg_e_b97a5f[],tg_e_b97a4f[],tg_e_b97a6f[],tg_e_b97a7a[],tg_e_b97a79[],tg_e_b97a9b[],tg_e_b97a7b[];string tg_floatToString405760(float,int,int);extern const char tg_e_b97a11[],tg_e_b97a07[],tg_e_b97a13[],tg_e_b97a12[],tg_e_b97a2f[],tg_e_b97a2e[],tg_e_b97a4e[];extern bool tg_ba0968[],tg_b9651c[];extern string tg_d227b0[];extern int tg_cebf6c,tg_cebfcc,tg_cebf24,tg_cebefc,tg_cebfb0,tg_cebf00,tg_cebf34,tg_cebfa8,tg_cebfd4,tg_cebfbc,tg_cebf30,tg_cebf5c,tg_cebfd8,tg_cebf60,tg_cebf2c,tg_cebf70,tg_cebf58,tg_cebef8,tg_cebf88,tg_cebf90,tg_cebf50,tg_cebef4;extern const char tg_e_b979df[],tg_e_b979f6[],tg_e_b979f7[];extern const char tg_e_b979a9[],tg_e_b979ab[],tg_e_b979aa[],tg_e_b979b9[],tg_e_b979bb[],tg_e_b979ba[],tg_e_b979cb[],tg_e_b979de[];extern int tg_cebf64,tg_cebf44;extern const char tg_e_b9794e[],tg_e_b9795e[],tg_e_b9794f[],tg_e_b9795f[],tg_e_b9796e[],tg_e_b9796d[],tg_e_b9796f[];extern const float tg_c36fbc;extern const char tg_e_b978fe[],tg_e_b978ff[],tg_e_b9790f[],tg_e_b9793d[],tg_e_b9793e[],tg_e_b9794d[],tg_e_b9793f[];extern string tg_d293c0[],tg_d378d0[];extern const char tg_e_b978c6[],tg_e_b978c7[],tg_e_b978e6[],tg_e_b978e7[],tg_e_b978fd[];void tg_lookupColor9d45a0(const string&,int&);
void tg_loadInfoAnims4acbf0();
int tg_percentTier4347e0(int,int);int tg_barWidth8b51f0(float,float);
string intToString(int);
extern int tg_cf4c24;extern int tg_cebf98[],tg_cebf78[];
extern int tg_cebfc0,tg_cebf8c,tg_cebf1c;
int tg_invPercentTier434840(int,int);extern const float tg_c36ec8;
extern const char tg_e_b9650a[],tg_e_b9650b[],tg_e_b96511[],tg_e_b96512[],tg_e_b96513[],tg_e_b96525[],tg_e_b96526[],tg_e_b96527[];
struct TgVec{int pv0,pv1,pv2,pv3;int&operator[](unsigned);};extern TgVec tg_cf4830;extern TgVec tg_d25790;extern TgVec tg_cf4844;int tg_countNonNull9de8f0(TgVec&);
extern const char tg_e_b96535[],tg_e_b96536[],tg_e_b96537[],tg_e_b9653f[];
extern int tg_cf4854,tg_cf4898,tg_cf48dc;
extern const char tg_e_b96545[],tg_e_b96546[],tg_e_b96547[],tg_e_b9656d[];
extern int tg_cf4920;int tg_maxInt9cdb60(int,int);string tg_floatToStringSigned4059d0(float,int,int);extern const double tg_c36cd0;
extern const char tg_e_b9656e[],tg_e_b9656f[],tg_e_b9657d[],tg_e_b9657e[],tg_e_b9657f[];
extern const char tg_e_b965bb[],tg_e_b965a3[],tg_e_b965c2[],tg_e_b965c1[],tg_e_b965cd[],tg_e_b965c3[],tg_e_b965ce[];
extern int tg_cebfa4;extern const float tg_c37034,tg_c36fec,tg_c36ed4,tg_c36f20;extern const double tg_c36ca0;
int tg_countNonNull9de8f0(TgVecU&);int tg_minInt9cdb30(int,int);int tg_round406360(float);extern string tg_d29980[];
extern const char tg_e_b965cf[],tg_e_b965db[],tg_e_b965da[],tg_e_b965e9[],tg_e_b965e3[],tg_e_b965eb[],tg_e_b965ea[],tg_e_b965f2[],tg_e_b965f1[],tg_e_b965ff[],tg_e_b965f3[],tg_e_b969fb[],tg_e_b969fa[],tg_e_b96a01[],tg_e_b96a02[];
extern const char tg_e_b96a03[],tg_e_b96a0b[],tg_e_b96a0a[],tg_e_b96a1a[],tg_e_b96a13[],tg_e_b96a23[],tg_e_b96a1b[],tg_e_b96a31[],tg_e_b96a32[],tg_e_b96a33[];
int tg_halfDiff437190(int,int);extern int tg_cebf94,tg_cebfb4,tg_cebfc8,tg_cebfc4,tg_cec964;
struct TgVecE{int pv0,pv1,pv2,pv3;};extern TgVecE tg_cf4aa8;bool tg_containsEntity9d31e0(TgVecE&,TgHE);int tg_indexOfEntity9d3110(TgVecE&,TgHE);
struct TgVecI{int pv0,pv1,pv2,pv3;int&operator[](unsigned);};extern TgVecI tg_cf4ab8;string tg_countString407a80(int,const string&);extern string tg_d39e90[];
extern const char tg_e_b96a3a[],tg_e_b96a3b[],tg_e_b96a43[],tg_e_b96a47[],tg_e_b96a4b[],tg_e_b96a4f[],tg_e_b96a56[],tg_e_b96a5b[],tg_e_b96a57[];
extern string tg_d1f330[],tg_d2c470[],tg_d2e148[],tg_cf67e0[],tg_cf2740[];extern int tg_cebff0[],tg_cebed8[];extern int tg_cebf28,tg_cebf70,tg_cebfdc,tg_cefb38;extern bool tg_d28d16;
extern const char tg_e_b96a66[],tg_e_b96a67[],tg_e_b96a77[],tg_e_b96a87[],tg_e_b97666[],tg_e_b97667[],tg_e_b97677[],tg_e_b97696[],tg_e_b97687[],tg_e_b97697[],tg_e_b976b7[];
extern const char tg_e_b976c6[],tg_e_b976c7[],tg_e_b976e2[],tg_e_b976d3[],tg_e_b976e3[],tg_e_b97712[],tg_e_b97713[];
extern int tg_caf164;
extern const char tg_e_b97723[],tg_e_b9772f[],tg_e_b9773d[],tg_e_b9773e[],tg_e_b9773f[],tg_e_b9774f[];
struct TgFac{bool b[10];};extern TgFac tg_b96637[],tg_b96638[];
extern const char tg_e_b9775d[],tg_e_b9775e[],tg_e_b9775f[],tg_e_b9777e[],tg_e_b9777f[],tg_e_b97791[],tg_e_b97792[],tg_e_b97793[],tg_e_b977a6[];
extern const char tg_e_b977a7[],tg_e_b977b3[],tg_e_b977bd[],tg_e_b977be[],tg_e_b977bf[],tg_e_b977cb[];
void tg_clampMin9cf5c0(int*,int);extern string tg_d2a5a8[];
extern const char tg_e_b977db[],tg_e_b977da[],tg_e_b977eb[],tg_e_b977fd[],tg_e_b977fe[],tg_e_b977ff[],tg_e_b9780f[],tg_e_b97832[],tg_e_b97833[],tg_e_b97846[];
struct TgComp{char pad[0x24];string name;};struct TgVecComp{int pv0,pv1,pv2,pv3;TgComp*&operator[](unsigned);};extern TgVecComp tg_d2d1c4;extern TgVec tg_cf4910;
extern const char tg_e_b97847[],tg_e_b9785a[],tg_e_b9785b[],tg_e_b9788d[],tg_e_b9788e[],tg_e_b9788f[],tg_e_b978ab[],tg_e_b978ba[],tg_e_b978bb[];
extern const char tg_e_b96501[],tg_e_b96502[],tg_e_b96503[],tg_e_b96509[];

#define TXT(par,x,yy,al,s,col) aE=new TgText(par,x,yy,al,s,col);aE->show4ae410();

void TgInfo::trigger(const string&command,int value){
 if(command=="show_info"){
  tg_loadInfoAnims4acbf0();
  string aH;string a8;
  int y=1;
  TgText*aE;TgLine*b3;TgSpecial*special;int aX;int wVal;int val;float aI;TgTitle*title;
  if(h98.isValid()){
   if(!h98.operator->()){close();return;}
   if(h98==tg_cefc4c->getPlayer4630f0()){
    y++;
    TXT(this,2,y,0,string("Overview"),tg_cebfc0)
    y++;
    int core=h98->u5cccc0();
    int b0=tg_cf4c24?tg_cf4c24:core;
    aX=tg_cebf98[tg_percentTier4347e0(core,b0)];
    aH="0";
    b3=new TgLine(this,y,0,true,core?tg_e_b96502:aH,tg_e_b96501);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Rating"),tg_cebf8c)
    if(core){TXT(b3,0x15,0,2,intToString(core),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)core,(float)b0);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    int as=h98->u5c8cb0();
    int d_=h98->u5d1ee0();
    string b4;
    if(as<=d_){b4=" OK ";aX=tg_cebf78[0];}
    else{int over=h98->u5c8d40(as,d_);b4=" OVERWEIGHTx"+intToString(over)+" ";aX=tg_cebf78[over>3?3:over];}
    aH=tg_e_b96503;
    a8=tg_e_b96509;
    b3=new TgLine(this,y,1,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Mass"),tg_cebf8c)
    if(1){TXT(b3,0x15,0,2,intToString(as)+" / "+intToString(d_),tg_cebf1c)}
    if(!b4.empty()){special=new TgSpecial(b3,0x17,0,1,0,b4,aX);special->show4ae4f0();}
    y++;
    int speed=h98->u5d1d70();
    string b_="("+intToString(h98->u5d15a0(0))+")";
    aH=tg_e_b9650a;
    a8=tg_e_b9650b;
    b3=new TgLine(this,y,2,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Speed"),tg_cebf8c)
    if(1){TXT(b3,0x15,0,2,intToString(speed)+"%",tg_cebf1c)}
    if(!b_.empty()){special=new TgSpecial(b3,0x17,0,2,0,b_,tg_cebf8c);special->show4ae4f0();}
    y++;
    int aJ=h98->u5cca00();
    aX=tg_cebf98[tg_invPercentTier434840(aJ,100)];
    aH=tg_e_b96511;
    b3=new TgLine(this,y,3,true,1?tg_e_b96513:aH,tg_e_b96512);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Core Exposure"),tg_cebf8c)
    if(1){TXT(b3,0x15,0,2,intToString(aJ)+"%",tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)aJ,tg_c36ec8);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    int inv=h98->u5c8e20(0);
    int invMax=h98->u5ca210();
    aX=tg_cebf98[tg_percentTier4347e0(inv,invMax)];
    aH=tg_e_b96525;
    b3=new TgLine(this,y,4,true,1?tg_e_b96527:aH,tg_e_b96526);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Inventory"),tg_cebf8c)
    if(1){TXT(b3,0x15,0,2,intToString(inv)+" / "+intToString(invMax),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)inv,(float)invMax);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    aH=tg_e_b96535;
    a8=tg_e_b96536;
    b3=new TgLine(this,y,5,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Parts Database"),tg_cebf8c)
    if(1){TXT(b3,0x15,0,2,intToString(tg_countNonNull9de8f0(tg_cf4830)),tg_cebf1c)}
    if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
    y++;
    aH=tg_e_b96537;
    a8=tg_e_b9653f;
    b3=new TgLine(this,y,6,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Schematics"),tg_cebf8c)
    if(1){TXT(b3,0x15,0,2,intToString(tg_cf4854+tg_cf4898),tg_cebf1c)}
    if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
    y++;
    if(tg_cf4854||tg_cf4898){
     y--;
     TgButton*btn=NULL;int b5=0x18;
     if(tg_cf4854){btn=new TgButton(this,b5,y,1,"PARTS");btn->animate4ae610();b5+=btn->width44b0d0();}
     if(tg_cf4898){
      if(btn){b3->putChar418110(b5,0,0x2f,*tg_cf44c0);b5+=3;}
      btn=new TgButton(this,b5,y,2,"ROBOTS");btn->animate4ae610();
     }
     y++;
     pBC.set40a010(0,y);
    }
    aH=tg_e_b96545;
    a8=tg_e_b96546;
    b3=new TgLine(this,y,7,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Studies"),tg_cebf8c)
    if(1){TXT(b3,0x15,0,2,intToString(tg_cf48dc),tg_cebf1c)}
    if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
    y++;
    if(tg_cf48dc){
     y--;
     TgButton*btn=NULL;int e5=0x18;
     btn=new TgButton(this,e5,y,4,"LIST");btn->animate4ae610();e5+=btn->width44b0d0();
     y++;
     pC4.set40a010(0,y);
    }
    aH=tg_e_b96547;
    a8=tg_e_b9656d;
    b3=new TgLine(this,y,8,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Analyses"),tg_cebf8c)
    if(1){TXT(b3,0x15,0,2,intToString(tg_cf4920),tg_cebf1c)}
    if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
    y++;
    if(tg_cf4920){
     y--;
     TgButton*btn=NULL;int gN=0x18;
     btn=new TgButton(this,gN,y,5,"ANALYSES");btn->animate4ae610();gN+=btn->width44b0d0();
     y++;
     pCC.set40a010(0,y);
    }
    y++;
    TXT(this,2,y,0,string("Energy"),tg_cebfc0)
    y++;
    int a2=h98->u5d1070();
    int cC=(int)h98->u5ca4f0();
    int enMax=tg_maxInt9cdb60(a2,cC);
    aX=tg_cebf98[tg_percentTier4347e0(a2,enMax)];
    aH="+0";
    b3=new TgLine(this,y,9,true,a2?tg_e_b9656f:aH,tg_e_b9656e);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Supply"),tg_cebf8c)
    if(a2){TXT(b3,0x15,0,2,"+"+intToString(a2),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)a2,(float)enMax);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    aX=tg_cebf98[tg_invPercentTier434840(cC,enMax)];
    aH="-0";
    b3=new TgLine(this,y,10,true,cC?tg_e_b9657e:aH,tg_e_b9657d);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Upkeep"),tg_cebf8c)
    if(cC){TXT(b3,0x15,0,2,"-"+intToString(cC),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)cC,(float)enMax);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    float d3=h98->u5d1e40();
    string a0="("+tg_floatToStringSigned4059d0(-d3*speed/tg_c36cd0,1,1)+")";
    if(a0=="(-0.0)")a0.clear();
    aH="-0";
    a8=tg_e_b9657f;
    b3=new TgLine(this,y,0xb,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Movement"),tg_cebf8c)
    if(d3!=0){TXT(b3,0x15,0,2,tg_floatToStringSigned4059d0(-d3,0,1),tg_cebf1c)}
    if(!a0.empty()){special=new TgSpecial(b3,0x17,0,2,0,a0,tg_cebf8c);special->show4ae4f0();}
    y++;
    y++;
    TXT(this,2,y,0,string("Matter"),tg_cebfc0)
    y++;
    int dN=h98->u5ca6c0();
    int mMax=h98->u45a920();
    aX=tg_cebf98[tg_invPercentTier434840(dN,mMax)];
    aH="-0";
    b3=new TgLine(this,y,0xc,true,dN?tg_e_b965bb:aH,tg_e_b965a3);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Upkeep"),tg_cebf8c)
    if(dN){TXT(b3,0x15,0,2,"-"+intToString(dN),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)dN,(float)mMax);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    y++;
    TXT(this,2,y,0,string("Heat"),tg_cebfc0)
    y++;
    int e6=h98->u5ca960();
    int a1=h98->u5ca8d0();
    int b7=tg_maxInt9cdb60(e6,a1);
    aX=tg_cebf98[tg_percentTier4347e0(e6,b7)];
    aH="-0";
    b3=new TgLine(this,y,0xd,true,e6?tg_e_b965c2:aH,tg_e_b965c1);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Dissipation"),tg_cebf8c)
    if(e6){TXT(b3,0x15,0,2,"-"+intToString(e6),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)e6,(float)b7);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    aX=tg_cebf98[tg_invPercentTier434840(a1,b7)];
    aH="+0";
    b3=new TgLine(this,y,0xe,true,a1?tg_e_b965cd:aH,tg_e_b965c3);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Generation"),tg_cebf8c)
    if(a1){TXT(b3,0x15,0,2,"+"+intToString(a1),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)a1,(float)b7);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    int aC=h98->u5d1da0();
    string dC="("+tg_floatToStringSigned4059d0((float)aC*speed/tg_c36cd0,1,1)+")";
    if(dC=="(+0.0)")dC.clear();
    aH="+0";
    a8=tg_e_b965ce;
    b3=new TgLine(this,y,0xf,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Movement"),tg_cebf8c)
    if(aC){TXT(b3,0x15,0,2,"+"+intToString(aC),tg_cebf1c)}
    if(!dC.empty()){special=new TgSpecial(b3,0x17,0,2,0,dC,tg_cebf8c);special->show4ae4f0();}
    y++;
    y++;
    TXT(this,2,y,0,string("Scanning"),tg_cebfc0)
    y++;
    aX=tg_cebfa4;
    int h7=h98->u5c7d30();
    aH=tg_e_b965cf;
    b3=new TgLine(this,y,0x10,true,1?tg_e_b965db:aH,tg_e_b965da);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Visual"),tg_cebf8c)
    if(1){TXT(b3,0x15,0,2,intToString(h7),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)h7,tg_c37034);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    int c5=h98->u5c7d80(0);
    aH="0";
    b3=new TgLine(this,y,0x11,true,c5?tg_e_b965e9:aH,tg_e_b965e3);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Robots"),tg_cebf8c)
    if(c5){TXT(b3,0x15,0,2,intToString(c5),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)c5,tg_c36fec);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    int aA=tg_maxInt9cdb60(h98->u5d2380(0xd).isValid()?4:0,h98->u5d22a0(0xc));
    aH="+0";
    b3=new TgLine(this,y,0x12,true,aA?tg_e_b965eb:aH,tg_e_b965ea);
    add4aedc0(b3);
    TXT(b3,2,0,0,string(" Detail"),tg_cebf8c)
    if(aA){TXT(b3,0x15,0,2,"+"+intToString(aA),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)aA,tg_c36ed4);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    int a7=h98->u45a3c0();
    aH="0";
    b3=new TgLine(this,y,0x13,true,a7?tg_e_b965f2:aH,tg_e_b965f1);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Terrain"),tg_cebf8c)
    if(a7){TXT(b3,0x15,0,2,"+"+intToString(a7),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)a7,tg_c36fc0);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    int dens=h98->u5c7e40();
    aH="0";
    b3=new TgLine(this,y,0x14,true,dens?tg_e_b965ff:aH,tg_e_b965f3);
    add4aedc0(b3);
    TXT(b3,2,0,0,string(" Density"),tg_cebf8c)
    if(dens){TXT(b3,0x15,0,2,intToString(dens),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)dens,tg_c36f20);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    y++;
    TXT(this,2,y,0,string("Resistances"),tg_cebfc0)
    y++;
    TgVecU res;
    for(int i=0;i<7;i++)res.push_back9b9280(100-h98->u5cb570(i,!bAC));
    TgVecU mods;
    mods.push_back9b9280(h98->u5d2150(0x67,0));
    mods.push_back9b9280(h98->u5d22a0(0x69));
    mods.push_back9b9280(tg_round406360((h98->u5d7bf0(5)-tg_c36ca0)*tg_c36cd0));
    int aD=getHeight4174c0()-5-tg_maxInt9cdb60(1,tg_countNonNull9de8f0(mods))-y+1;
    int a6=tg_minInt9cdb30(aD,tg_countNonNull9de8f0(res));
    iDC=tg_countNonNull9de8f0(res)-a6;
    if(iDC==1){a6++;iDC=0;}
    bool aB=false;
    for(int i8=0,n=0;i8<7&&n<a6;i8++){
     if(res[i8]){
      aX=tg_cebf98[res[i8]<0?0:3];
      string rs=(res[i8]>=0?intToString(res[i8]):"-"+intToString(-res[i8]))+"%";
      if(res[i8]<0)res[i8]=-res[i8];
      aH="0%";
      b3=new TgLine(this,y,0x2a,true,res[i8]?tg_e_b969fb:aH,tg_e_b969fa);
      add4aedc0(b3);
      TXT(b3,2,0,0,string(tg_d29980[i8]),tg_cebf8c)
      if(res[i8]){TXT(b3,0x15,0,2,rs,tg_cebf1c)}
      wVal=tg_barWidth8b51f0((float)res[i8],tg_c36ec8);
      if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
      y++;
      aB=true;
      n++;
     }
    }
    if(!aB){
     aH=tg_e_b96a01;
     a8=tg_e_b96a02;
     b3=new TgLine(this,y,0x192,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("None"),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b96a03,tg_cebf1c)}
     if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
     y++;
    }
    if(iDC){
     TgButton*btn=new TgButton(this,4,y,0x10,"MORE ("+intToString(iDC)+")");
     btn->animate4ae610();
     pD4.set40a010(0,y+1);
     y++;
    }
    y++;
    TXT(this,2,y,0,string("Modifiers"),tg_cebfc0)
    y++;
    aB=false;
    aX=tg_cebfa4;
    if(mods[0]){
     aH="0%";
     b3=new TgLine(this,y,0x15,true,mods[0]?tg_e_b96a0b:aH,tg_e_b96a0a);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Energy"),tg_cebf8c)
     if(mods[0]){TXT(b3,0x15,0,2,intToString(mods[0])+"%",tg_cebf1c)}
     wVal=tg_barWidth8b51f0((float)mods[0],tg_c36ec8);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
     aB=true;
    }
    if(mods[1]){
     aH="0%";
     b3=new TgLine(this,y,0x16,true,mods[1]?tg_e_b96a1a:aH,tg_e_b96a13);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Kinetic"),tg_cebf8c)
     if(mods[1]){TXT(b3,0x15,0,2,intToString(mods[1])+"%",tg_cebf1c)}
     wVal=tg_barWidth8b51f0((float)mods[1],tg_c36ec8);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
     aB=true;
    }
    if(mods[2]){
     aH="0%";
     b3=new TgLine(this,y,0x17,true,mods[2]?tg_e_b96a23:aH,tg_e_b96a1b);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Melee"),tg_cebf8c)
     if(mods[2]){TXT(b3,0x15,0,2,intToString(mods[2])+"%",tg_cebf1c)}
     wVal=tg_barWidth8b51f0((float)mods[2],tg_c36ec8);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
     aB=true;
    }
    if(!aB){
     aH=tg_e_b96a31;
     a8=tg_e_b96a32;
     b3=new TgLine(this,y,0x192,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("None"),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b96a33,tg_cebf1c)}
     if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
     y++;
    }
   }
   else{
    y++;
    title=new TgTitle(this,y,h98,TgHP2(),0);
    title->highlight4ae300();
    y+=title->getHeight4174c0();
    if(!bAC&&!h98->getTarget45a760()){
     int trans=tg_cefc4c->getEntityValue465660(h98);
     if(trans&&!h98->u45ade0())trans=0;
     if(trans){
      string ts="(transmission)";
      TgCText*ct=new TgCText(this,TgPos2(tg_halfDiff437190(ts.size(),width44b0d0()),y),ts,0,0,-1);
      ct->setColor48c3c0(trans==1?tg_cebf94:tg_cebfb4);
      y++;
     }
     else if(h98->u45aaa0(tg_cefc4c->getPlayer4630f0())){
      if(tg_containsEntity9d31e0(tg_cf4aa8,h98)){
       int idx=tg_indexOfEntity9d3110(tg_cf4aa8,h98);
       int turns5=tg_cf4ab8[idx]-tg_cefc4c->getTurn464270();
       string ds="("+tg_countString407a80(turns5,"turn")+" to disintegration)";
       TgCText*g6=new TgCText(this,TgPos2(tg_halfDiff437190(ds.size(),width44b0d0()),y),ds,0,0,-1);
       g6->setColor48c3c0(tg_cebfc8);
       y++;
      }
      else{
      int dmg=h98->u45aa50();
      int j4=h98->u45aa30();
      if(dmg||j4){
       string ks="("+intToString(dmg)+" damage, "+tg_countString407a80(j4,"kill")+")";
       TgCText*a3=new TgCText(this,TgPos2(tg_halfDiff437190(ks.size(),width44b0d0()),y),ks,0,0,-1);
       a3->setColor48c3c0(tg_cebfc4);
       y++;
      }
      }
     }
    }
    y++;
    TXT(this,2,y,0,string("Overview"),tg_cebfc0)
    y++;
    aH=tg_e_b96a3a;
    a8=tg_e_b96a3b;
    b3=new TgLine(this,y,0x18,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Class"),tg_cebf8c)
    if(0){TXT(b3,0x15,0,2,tg_e_b96a43,tg_cebf1c)}
    if(!h98->def9b4350()->getName459a40().empty()){special=new TgSpecial(b3,0x17,0,2,0,h98->def9b4350()->getName459a40(),tg_cebf8c);special->show4ae4f0();}
    y++;
    aH=tg_e_b96a47;
    a8=tg_e_b96a4b;
    b3=new TgLine(this,y,0x19,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Size"),tg_cebf8c)
    if(0){TXT(b3,0x15,0,2,tg_e_b96a4f,tg_cebf1c)}
    if(!tg_d39e90[h98->u45a340()].empty()){special=new TgSpecial(b3,0x17,0,2,0,tg_d39e90[h98->u45a340()],tg_cebf8c);special->show4ae4f0();}
    y++;
    int cd=h98->u5cccc0();
    aX=tg_cebf98[tg_invPercentTier434840(cd,tg_cec964)];
    aH=tg_e_b96a56;
    b3=new TgLine(this,y,0x1a,true,cd?tg_e_b96a5b:aH,tg_e_b96a57);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Rating"),tg_cebf8c)
    if(cd){TXT(b3,0x15,0,2,intToString(cd),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)cd,(float)tg_cec964);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    int dA=bAC?1:tg_cefc4c->getPlayer4630f0()->u5c7fc0(h98);
    string aP;
    int aG=0x1b;
    if(bAC)aP=" N/A ";
    else if(!h98->getTarget45a760())aP=tg_d1f330[dA];
    else{aP=tg_d2c470[h98->getTarget45a760()];aG=h98->getTarget45a760()+0x1b;}
    aX=!h98->getTarget45a760()?tg_cebff0[dA]:(h98->getTarget45a760()==1||h98->getTarget45a760()==2?tg_cebf28:tg_cebf70);
    aH=tg_e_b96a66;
    a8=tg_e_b96a67;
    b3=new TgLine(this,y,aG,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("ID"),tg_cebf8c)
    if(0){TXT(b3,0x15,0,2,tg_e_b96a77,tg_cebf1c)}
    if(!aP.empty()){special=new TgSpecial(b3,0x17,0,1,0,aP,aX);special->show4ae4f0();}
    y++;
    int a_=h98->u5d1390();
    int mvMode=h98->u44a7d0();
    string mvs=(a_==1&&h98->u45a700()&&(mvMode==1||mvMode==7)?(mvMode==1?"Running":"Weaving"):tg_d2e148[a_])+" ("+(tg_d28d16?intToString(h98->u5d15a0(0))+")":intToString(h98->u5d1d70())+"%)");
    if(h98->getTarget45a760()||h98->u5d1280(0)){
     mvs="Immobile";
     if(h98->u5cad50()==2)mvs+=" ("+tg_cf67e0[tg_cefb38]+") ";
    }
    aH=tg_e_b96a87;
    a8=tg_e_b97666;
    b3=new TgLine(this,y,0x24,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Movement"),tg_cebf8c)
    if(0){TXT(b3,0x15,0,2,tg_e_b97667,tg_cebf1c)}
    if(!mvs.empty()){special=new TgSpecial(b3,0x17,0,2,0,mvs,tg_cebf8c);special->show4ae4f0();}
    y++;
    int dX=h98->u490840();
    aX=tg_cebf98[tg_percentTier4347e0(dX,h98->u5ca260())];
    aH=tg_e_b97677;
    b3=new TgLine(this,y,0x25,true,dX?tg_e_b97696:aH,tg_e_b97687);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Core Integrity"),tg_cebf8c)
    if(dX){TXT(b3,0x15,0,2,intToString(dX),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)dX,(float)h98->u5ca260());
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    string h_;
    if(h98->u45a990()<0){
     h_=h98->u45a990()<-100?" FREEZING ":" FRIGID ";
     aX=tg_cebfdc;
    }
    else{
     int heat=h98->u5ca840();
     h_=" "+tg_cf2740[heat]+" ";
     aX=tg_cebed8[heat];
    }
    aH=tg_e_b97697;
    a8=tg_e_b976b7;
    b3=new TgLine(this,y,0x26,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Core Temp"),tg_cebf8c)
    if(0){TXT(b3,0x15,0,2,tg_e_b976c6,tg_cebf1c)}
    if(!h_.empty()){special=new TgSpecial(b3,0x17,0,1,0,h_,aX);special->show4ae4f0();}
    y++;
    int expo=h98->u5cca00();
    aX=tg_cebf98[tg_invPercentTier434840(expo,100)];
    aH=tg_e_b976c7;
    b3=new TgLine(this,y,0x27,true,1?tg_e_b976e2:aH,tg_e_b976d3);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Core Exposure"),tg_cebf8c)
    if(1){TXT(b3,0x15,0,2,intToString(expo)+"%",tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)expo,tg_c36ec8);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    string gi=intToString(h98->def9b4350()->f210)+"-"+intToString(h98->def9b4350()->f214);
    aH=tg_e_b976e3;
    a8=tg_e_b97712;
    b3=new TgLine(this,y,0x28,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Salvage Potential"),tg_cebf8c)
    if(0){TXT(b3,0x15,0,2,tg_e_b97713,tg_cebf1c)}
    if(!gi.empty()){special=new TgSpecial(b3,0x17,0,2,0,gi,tg_cebf8c);special->show4ae4f0();}
    y++;
    y++;
    TXT(this,2,y,0,string("Armament"),tg_cebfc0)
    y++;
    TgVecHI a9;
    h98->u5cb8b0(a9);
    for(int i=a9.size9b9260()-1;i>=0;i--)
     if(a9[i]->u4578a0()!=3)tg_eraseAt9da940(a9,i);
    if(a9.empty9b86e0()){
     aH=tg_e_b97723;
     a8=tg_e_b9772f;
     b3=new TgLine(this,y,0x192,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("None"),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b9773d,tg_cebf1c)}
     if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
     y++;
    }
    else{
    if(!a9.empty9b86e0()){
     TgVecHI sorted;
     sorted.push_back9b80b0(a9.back9b6540());
     a9.pop_back9e8cd0();
     while(!a9.empty9b86e0()){
      if(sorted.back9b6540()->nested457820()<a9.back9b6540()->nested457820()){
       sorted.push_back9b80b0(a9.back9b6540());
       a9.pop_back9e8cd0();
      }
      else for(unsigned j=0;j<sorted.size9b9260();j++){
       if(a9.back9b6540()->nested457820()<=sorted[j]->nested457820()){
        tg_insert9d8fc0(sorted,j,a9.back9b6540());
        a9.pop_back9e8cd0();
        break;
       }
      }
     }
     a9=sorted;
    }
    TgVecU counts;
    for(unsigned i=0;i<a9.size9b9260();i++){
     counts.push_back9b9280(1);
     for(unsigned j=i+1;j<a9.size9b9260();j++){
      if(a9[i]->nested457820()==a9[j]->nested457820()){
       counts[i]++;
       tg_eraseStep9d6440(a9,j);
      }
     }
    }
    for(unsigned i=0;i<a9.size9b9260();i++){
     string nm=a9[i]->u573860(0,0);
     if(tg_d28d16)nm+=" ("+intToString(h98->u5ccb50(a9[i]))+"%)";
     if(counts[i]>1)nm+=" x"+intToString(counts[i]);
     aH=tg_e_b9773e;
     a8=tg_e_b9773f;
     b3=new TgLine(this,y,0x192,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string(nm),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b9774f,tg_cebf1c)}
     if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
     y++;
     if(tg_cf4830[a9[i]->nested457820()]){
      b3->set4aeac0(a9[i],tg_caf164);
      add4aedc0(b3);
     }
    }
    }
    bool showInv=!bAC&&h98->u5c7f70();
    if(showInv){
     int cap=h98->u5ca210();
     if(cap){
      a9.clear9b73d0();
      h98->u5cb830(a9);
      if(!a9.empty9b86e0()||h98->getFaction45a2c0()==8||tg_b96637[h98->getFaction45a2c0()].b[0]||tg_b96638[h98->getFaction45a2c0()].b[0]){
       y++;
       TXT(this,2,y,0,"Inventory ("+intToString(h98->u5c8e20(0))+"/"+intToString(cap)+")",tg_cebfc0)
       y++;
       if(a9.empty9b86e0()){
        aH=tg_e_b9775d;
        a8=tg_e_b9775e;
        b3=new TgLine(this,y,0x192,false,aH,a8);
        add4aedc0(b3);
        TXT(b3,2,0,0,string("Empty"),tg_cebf8c)
        if(0){TXT(b3,0x15,0,2,tg_e_b9775f,tg_cebf1c)}
        if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
        y++;
       }
       else{
       TgVecU cnt;
       for(unsigned i=0;i<a9.size9b9260();i++){
        cnt.push_back9b9280(1);
        for(unsigned j=i+1;j<a9.size9b9260();j++){
         if(a9[i]->u573860(0,0)==a9[j]->u573860(0,0)){
          cnt[i]++;
          tg_eraseStep9d6440(a9,j);
         }
        }
       }
       for(unsigned i=0;i<a9.size9b9260();i++){
        string nm=a9[i]->u573860(0,0);
        if(cnt[i]>1)nm+=" x"+intToString(cnt[i]);
        aH=tg_e_b9777e;
        a8=tg_e_b9777f;
        b3=new TgLine(this,y,0x192,false,aH,a8);
        add4aedc0(b3);
        TXT(b3,2,0,0,string(nm),tg_cebf8c)
        if(0){TXT(b3,0x15,0,2,tg_e_b97791,tg_cebf1c)}
        if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
        y++;
        if(tg_cf4830[a9[i]->nested457820()]){
         b3->set4aeac0(a9[i],tg_caf164);
         add4aedc0(b3);
        }
       }
       }
      }
      if(h98->getFaction45a2c0()==8){
       int sup=h98->ai45b590()->u459300();
       string ss="(Supplies: ";
       ss+=sup<=0?"Depleted":intToString(sup);
       ss+=")";
       aH=tg_e_b97792;
       a8=tg_e_b97793;
       b3=new TgLine(this,y,0x29,false,aH,a8);
       add4aedc0(b3);
       TXT(b3,2,0,0,string(ss),tg_cebf8c)
       if(0){TXT(b3,0x15,0,2,tg_e_b977a6,tg_cebf1c)}
       if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
       y++;
      }
     }
    }
    y++;
    TXT(this,2,y,0,string("Components"),tg_cebfc0)
    y++;
    a9.clear9b73d0();
    h98->u5cb8b0(a9);
    for(int i=a9.size9b9260()-1;i>=0;i--)
     if(a9[i]->u4578a0()==3)tg_eraseAt9da940(a9,i);
    if(a9.empty9b86e0()){
     aH=tg_e_b977a7;
     a8=tg_e_b977b3;
     b3=new TgLine(this,y,0x192,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("N/A"),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b977bd,tg_cebf1c)}
     if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
     y++;
    }
    else{
    if(!a9.empty9b86e0()){
     TgVecHI sorted;
     sorted.push_back9b80b0(a9.back9b6540());
     a9.pop_back9e8cd0();
     while(!a9.empty9b86e0()){
      if(sorted.back9b6540()->nested457820()<a9.back9b6540()->nested457820()){
       sorted.push_back9b80b0(a9.back9b6540());
       a9.pop_back9e8cd0();
      }
      else for(unsigned j=0;j<sorted.size9b9260();j++){
       if(a9.back9b6540()->nested457820()<=sorted[j]->nested457820()){
        tg_insert9d8fc0(sorted,j,a9.back9b6540());
        a9.pop_back9e8cd0();
        break;
       }
      }
     }
     a9=sorted;
    }
    TgVecU counts;
    for(unsigned i=0;i<a9.size9b9260();i++){
     counts.push_back9b9280(1);
     for(unsigned j=i+1;j<a9.size9b9260();j++){
      if(a9[i]->nested457820()==a9[j]->nested457820()){
       counts[i]++;
       tg_eraseStep9d6440(a9,j);
      }
     }
    }
    for(unsigned i=0;i<a9.size9b9260();i++){
     string nm=a9[i]->u573860(0,0)+" ("+intToString(h98->u5ccb50(a9[i]))+"%)";
     if(counts[i]>1)nm+=" x"+intToString(counts[i]);
     aH=tg_e_b977be;
     a8=tg_e_b977bf;
     b3=new TgLine(this,y,0x192,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string(nm),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b977cb,tg_cebf1c)}
     if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
     y++;
     if(tg_cf4830[a9[i]->nested457820()]){
      b3->set4aeac0(a9[i],tg_caf164);
      add4aedc0(b3);
     }
    }
    }
    y++;
    TXT(this,2,y,0,string("Resistances"),tg_cebfc0)
    y++;
    TgVecU res;
    for(int i=0;i<7;i++)res.push_back9b9280(100-h98->u5cb570(i,!bAC));
    TgVecU aK;
    h98->u5cd490(aK);
    int b9=getHeight4174c0()-3-tg_maxInt9cdb60(1,aK.size9b9260())-y+1;
    tg_clampMin9cf5c0(&b9,1);
    if(bAC)b9--;
    int c9=tg_minInt9cdb30(b9,tg_countNonNull9de8f0(res)+aK.size9b9260());
    iDC=tg_countNonNull9de8f0(res)+aK.size9b9260()-c9;
    if(iDC==1){c9++;iDC=0;}
    int n=0;
    for(int i=0;i<7&&n<c9;i++){
     if(res[i]){
      aX=tg_cebf98[res[i]<0?0:3];
      string rs=(res[i]>=0?intToString(res[i]):"-"+intToString(-res[i]))+"%";
      if(res[i]<0)res[i]=-res[i];
      aH="0%";
      b3=new TgLine(this,y,0x2a,true,res[i]?tg_e_b977db:aH,tg_e_b977da);
      add4aedc0(b3);
      TXT(b3,2,0,0,string(tg_d29980[i]),tg_cebf8c)
      if(res[i]){TXT(b3,0x15,0,2,rs,tg_cebf1c)}
      wVal=tg_barWidth8b51f0((float)res[i],tg_c36ec8);
      if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
      y++;
      n++;
     }
    }
    if(!aK.empty9b86e0())
     for(unsigned i=0;i<aK.size9b9260()&&n<c9;i++){
      aH=tg_e_b977eb;
      a8="IMMUNE";
      b3=new TgLine(this,y,aK[i]+0x2b,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string(tg_d2a5a8[aK[i]]),tg_cebf8c)
      if(0){TXT(b3,0x15,0,2,tg_e_b977fd,tg_cebf1c)}
      if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
      y++;
      n++;
     }
    if(n==0){
     aH=tg_e_b977fe;
     a8=tg_e_b977ff;
     b3=new TgLine(this,y,0x192,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("N/A"),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b9780f,tg_cebf1c)}
     if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
     y++;
    }
    if(iDC){
     TgButton*btn=new TgButton(this,4,y,0x10,"MORE ("+intToString(iDC)+")");
     btn->animate4ae610();
     pD4.set40a010(0,y+1);
     y++;
    }
    if(bAC){
     y++;
     string fab="Fabrication";
     if(h98->def9b4350()->fe4>1)fab+=" (x"+intToString(h98->def9b4350()->fe4)+")";
     TXT(this,2,y,0,string(fab),tg_cebfc0)
     y++;
     aH=tg_e_b97832;
     a8=tg_e_b97833;
     b3=new TgLine(this,y,0x33,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Time"),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b97846,tg_cebf1c)}
     if(!h98->def9b4350()->getSuffix459e00().empty()){special=new TgSpecial(b3,0x17,0,2,0,h98->def9b4350()->getSuffix459e00(),tg_cebf8c);special->show4ae4f0();}
     y++;
     if(h98->def9b4350()->vfc.empty9b86e0()){
      aH=tg_e_b97847;
      a8=tg_e_b9785a;
      b3=new TgLine(this,y,0x34,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Components"),tg_cebf8c)
      if(0){TXT(b3,0x15,0,2,tg_e_b9785b,tg_cebf1c)}
      if(!string("None").empty()){special=new TgSpecial(b3,0x17,0,2,0,string("None"),tg_cebf8c);special->show4ae4f0();}
      y++;
     }
     else{
      aH=tg_e_b9788d;
      a8=tg_e_b9788e;
      b3=new TgLine(this,y,0x34,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Components"),tg_cebf8c)
      if(0){TXT(b3,0x15,0,2,tg_e_b9788f,tg_cebf1c)}
      if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
      y++;
      for(unsigned i=0;i<h98->def9b4350()->vfc.size9b9260();i++){
       string cn=" "+tg_d2d1c4[h98->def9b4350()->vfc[i]]->name;
       aH=tg_e_b978ab;
       a8=tg_e_b978ba;
       b3=new TgLine(this,y,0x34,false,aH,a8);
       add4aedc0(b3);
       TXT(b3,2,0,0,string(cn),tg_cebf8c)
       if(0){TXT(b3,0x15,0,2,tg_e_b978bb,tg_cebf1c)}
       if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
       y++;
      }
     }
    }
    bool fp=tg_cf4910[h98->nested457820()]&&!h98->def9b4350()->name170.empty();
    bool e9=h98->u5cd5d0();
    bool h1=h98->u5c80a0();
    if(fp||e9||h1){
     y++;
     TgButton*btn=NULL;int k5=2;
     if(fp){btn=new TgButton(this,k5,y,0xd,"ANALYSIS");btn->animate4ae610();k5+=btn->width44b0d0();}
     if(e9){
      if(btn){putChar418110(k5+1,y,0x2f,*tg_cf44c0);k5+=3;}
      btn=new TgButton(this,k5,y,0xe,"TRAITS");btn->animate4ae610();k5+=btn->width44b0d0();
     }
     if(h1){
      if(btn){putChar418110(k5+1,y,0x2f,*tg_cf44c0);k5+=3;}
      btn=new TgButton(this,k5,y,0xf,"NAME");btn->animate4ae610();
     }
     y++;
     pCC.set40a010(0,y+1);
    }
   }
  }
  else if(h9c.isValid()){
   if(!h9c.operator->()){close();return;}
   Console*art;
   if(getHeight4174c0()<0x32)art=e8=new Console(this,TgRect(0x31,1,0x32,0xc),0,0,-1);
   else art=this;
   if(h9c->def9b4350()->art7c.empty9b81b0()||(this==tg_cec124?tg_d25790[h9c->nested457820()]==0:tg_cf4830[h9c->nested457820()]==0)){
    art->animate48c3f0(getHeight4174c0()<0x32?"A_CInfo_Art_NA_Modal":"A_CInfo_Art_NA_Normal");
    string msg=h9c->def9b4350()->art7c.empty9b81b0()?"No Image Data":"No Analysis Data";
    TgCText*hN=new TgCText(art,TgPos2(tg_halfDiff437190(msg.size(),width44b0d0()),6),msg,0,0,-1);
    hN->animate48c3f0("A_CInfo_Art_NA_Text");
   }
   else{
    tg_lookupColor9d45a0("A_CInfo_Art",aX);
    TgArtAnim*aa=new TgArtAnim(art,&h9c->def9b4350()->art7c,1,y,0,aX,-1,-1,TgPos2(-1),0,0);
    aa->u4b29b0();
   }
   if(getHeight4174c0()<0x32)art->animate48c3f0("A_4_Border_Art");
   else y+=10;
   y++;
   title=new TgTitle(this,y,TgHE2(),h9c,this==tg_cec124);
   title->highlight4ae300();
   y++;
   if(h9c->hasName4579d0()){
    string nm="{"+h9c->name4579f0()+"}";
    TgCText*aW=new TgCText(this,TgPos2(tg_halfDiff437190(nm.size(),width44b0d0()),y),nm,0,0,-1);
    aW->setColor48c3c0(tg_cebfc4);
    y++;
   }
   y++;
   TXT(this,2,y,0,string("Overview"),tg_cebfc0)
   y++;
   aH=tg_e_b978c6;
   a8=tg_e_b978c7;
   b3=new TgLine(this,y,0x35,false,aH,a8);
   add4aedc0(b3);
   TXT(b3,2,0,0,string("Type"),tg_cebf8c)
   if(0){TXT(b3,0x15,0,2,tg_e_b978e6,tg_cebf1c)}
   if(!tg_d293c0[h9c->u457880()].empty()){special=new TgSpecial(b3,0x17,0,2,0,tg_d293c0[h9c->u457880()],tg_cebf8c);special->show4ae4f0();}
   y++;
   string slotX;int lo=0x36;
   if(h9c->u4578a0()!=5){
    slotX=tg_d378d0[h9c->u4578a0()];
    if(h9c->u4578e0())slotX+=" x"+intToString(h9c->u4578c0());
   }
   else if(h9c->u457880()==4||h9c->u457880()==5){
    slotX="Inventory";
    if(h9c->u4578e0())slotX+=" x"+intToString(h9c->u4578c0());
    lo=0x37;
   }
   aH=tg_e_b978e7;
   a8="N/A";
   b3=new TgLine(this,y,lo,false,aH,a8);
   add4aedc0(b3);
   TXT(b3,2,0,0,string("Slot"),tg_cebf8c)
   if(0){TXT(b3,0x15,0,2,tg_e_b978fd,tg_cebf1c)}
   if(!slotX.empty()){special=new TgSpecial(b3,0x17,0,2,0,slotX,tg_cebf8c);special->show4ae4f0();}
   y++;
   if((this==tg_cec124?tg_d25790[h9c->nested457820()]:tg_cf4830[h9c->nested457820()])||h9c->u4578a0()==5){
    switch(h9c->u4578a0()){
    case 1:
     aH=tg_e_b978fe;
     a8="N/A";
     b3=new TgLine(this,y,0x39,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Mass"),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b978ff,tg_cebf1c)}
     if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
     y++;
     break;
    case 5:
     aH=tg_e_b9790f;
     a8="N/A";
     b3=new TgLine(this,y,0x38,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Mass"),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b9793d,tg_cebf1c)}
     if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
     y++;
     break;
    default:
     val=h9c->u457b30();
     aX=tg_cebf98[tg_invPercentTier434840(val,0xf)];
     aH=tg_e_b9793e;
     b3=new TgLine(this,y,0x38,true,val?tg_e_b9794d:aH,tg_e_b9793f);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Mass"),tg_cebf8c)
     if(val){TXT(b3,0x15,0,2,intToString(val),tg_cebf1c)}
     wVal=tg_barWidth8b51f0((float)val,tg_c36fbc);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
    }
   }
   if(h9c->getEffect457b70(0x4a)){
    int cur=h9c->getEffectValue457be0(0x49);
    int max=h9c->getEffectValue457be0(0x4a);
    aX=tg_cebf98[tg_percentTier4347e0(cur,max)];
    aH=tg_e_b9794e;
    b3=new TgLine(this,y,0x3e,true,1?tg_e_b9795e:aH,tg_e_b9794f);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Battery"),tg_cebf8c)
    if(1){TXT(b3,0x15,0,2,intToString(cur)+" / "+intToString(max),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)cur,(float)max);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
   }
   if(h9c->getEffect457b70(0x4b)){
    int fs=h9c->getEffectValue457be0(0x4b);
    aX=tg_cebf98[tg_percentTier4347e0(fs,100)];
    aH=tg_e_b9795f;
    b3=new TgLine(this,y,0x3f,true,1?tg_e_b9796e:aH,tg_e_b9796d);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Field Strength"),tg_cebf8c)
    if(1){TXT(b3,0x15,0,2,intToString(fs)+"%",tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)fs,tg_c36ec8);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
   }
   if((this==tg_cec124?tg_d25790[h9c->nested457820()]:tg_cf4830[h9c->nested457820()])&&h9c->u4578a0()!=5){
    TgHE aN=h9c->u457b50();
    int nG=h9c->u457900();
    string tag;
    string kind;
    int nW=0x3a;
    if(h9c->u415ee0()){tag=" FAULTY PROTOTYPE ";aX=tg_cebf64;nW=0x3b;}
    else if(h9c->def9b4350()->f94){
     switch(h9c->def9b4350()->f94){
     case 1:tag=" PROTOTYPE ";break;
     case 2:tag=" CONSTRUCT ";nW=0x3c;break;
     case 3:tag=" ALIEN ";
     }
     aX=tg_cebf44;
    }
    else kind="Standard";
    aH=tg_e_b9796f;
    a8=kind;
    b3=new TgLine(this,y,nW,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Rating"),tg_cebf8c)
    if(nG){TXT(b3,0x15,0,2,h9c->def9b4350()->f94==2?string("?"):intToString(nG),tg_cebf1c)}
    if(!tag.empty()){special=new TgSpecial(b3,0x17,0,1,0,tag,aX);special->show4ae4f0();}
    y++;
    int cov=h9c->u9b6bf0();
    int aS=h9c->u457c80();
    if(cov==-1)cov=aS=0x32;
    aX=tg_cebf98[tg_percentTier4347e0(cov,aS)];
    string cs;
    if(h9c->u9b6bf0()==-1)cs="**";
    else{
     cs=intToString(cov)+" /";
     if(h9c->u5773d0(1,1))cs+=" ";
     else cs+="*";
     cs+=intToString(aS);
    }
    aH=tg_e_b979a9;
    b3=new TgLine(this,y,0x3d,true,1?tg_e_b979ab:aH,tg_e_b979aa);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Integrity"),tg_cebf8c)
    if(1){TXT(b3,0x15,0,2,cs,tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)cov,(float)aS);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    int b2=h9c->u577790();
    if(aN.isValid()&&b2){
     int pct;
     if(h9c->getType44aec0()==4){int tot=aN->u5ccab0();tot+=b2;pct=b2*100/tot;}
     else pct=aN->u5ccb50(h9c);
     string ns=intToString(b2);
     if(!pct&&tg_d28d16){
      int num=b2;int j_=aN->u5ccab0();
      for(int d=2;d<10;d++){if(num%d==0&&j_%d==0){num/=d;j_/=d;d=1;}}
      if(num>1){j_/=num;num=1;}
      ns+=" ("+intToString(num)+"/"+intToString(j_)+")";
     }
     else ns+=" ("+intToString(pct)+"%)";
     aX=tg_cebf98[tg_invPercentTier434840(pct,100)];
     aH=tg_e_b979b9;
     b3=new TgLine(this,y,0x40,true,1?tg_e_b979bb:aH,tg_e_b979ba);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Coverage"),tg_cebf8c)
     if(1){TXT(b3,0x15,0,2,ns,tg_cebf1c)}
     wVal=tg_barWidth8b51f0((float)pct,tg_c36ec8);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
    }
    else{
     aH=tg_e_b979cb;
     a8=tg_e_b979de;
     b3=new TgLine(this,y,0x40,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Coverage"),tg_cebf8c)
     if(1){TXT(b3,0x15,0,2,intToString(b2),tg_cebf1c)}
     if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
     y++;
    }
    if(h9c->u4578a0()!=5){
     string st;
     if(h9c->u457cf0()){
      if(h9c->u458240()){st=" UNSTABLE "+intToString(h9c->u458260())+" ";aX=tg_cebf6c;nW=0x45;}
      else if(h9c->u45a3a0()){st=" DETERIORATING ";aX=tg_cebfcc;nW=0x46;}
      else if(h9c->def9b4350()->fec&&h9c->u577fb0()){
       int base=tg_ba0968[h9c->def9b4350()->fec]?0:h9c->def9b4350()->fec-2;
       switch(h9c->u577fb0()){
       case 1:st=" "+tg_d227b0[h9c->def9b4350()->fec]+" "+intToString(h9c->u577fd0())+" ";aX=tg_cebf24;nW=base+0x47;break;
       case 2:st=" "+tg_d227b0[h9c->def9b4350()->fec]+" ";aX=tg_cebefc;nW=base+0x4a;break;
       case 3:st=" "+tg_d227b0[h9c->def9b4350()->fec]+" -"+intToString(h9c->u578070())+" ";aX=tg_cebfb0;nW=base+0x4d;
       }
      }
      else if(h9c->u458220()){
       if(h9c->u457f90()==0xa0||h9c->u457f90()==0xd3){st=" COLLECTING ";aX=tg_cebf00;nW=0x50;}
       else if(h9c->u457f90()==0xa6){st=" DROP ";aX=tg_cebf34;nW=0x51;}
       else{st=" OVERLOAD ";aX=tg_cebfa8;nW=h9c->u4578a0()==1?0x53:0x52;}
      }
      else if(h9c->getEffectValue457be0(0x44)){st=" DISPOSABLE "+intToString(h9c->getEffectValue457be0(0x44))+" ";aX=tg_cebfd4;nW=0x54;}
      else if(h9c->getEffectValue457be0(0x45)){st=" THROWABLE ";aX=tg_cebfbc;nW=0x55;}
      else if((!tg_b9651c[h9c->def9b4350()->f70]||h9c->getEffect457b70(0x6d))&&aN.isValid()&&!aN->isPlayer5c7600()){st=" INTEGRATED ";aX=tg_cebf30;nW=0x44;}
      else if(h9c->def9b4350()->b1ac){st=" FRAGILE ";aX=tg_cebf5c;nW=0x43;}
      else{st=" ACTIVE ";aX=tg_cebfd8;nW=0x41;}
     }
     else if(h9c->getEffect457b70(0x52)){st=" INTEGRATING ";aX=tg_cebf60;nW=0x56;}
     else if(h9c->u457d30()){st=" NON-FUNCTIONAL ";aX=tg_cebf2c;nW=0x57;}
     else if(h9c->u457d50()){st=" MALFUNCTIONING ";aX=tg_cebf70;nW=0x58;}
     else if(h9c->getEffect457b70(0x56)){st=" RIGGED ";aX=tg_cebf58;nW=0x59;}
     else if(h9c->u457db0()){st=" CORRUPTED ";aX=tg_cebef8;nW=0x5a;}
     else if(h9c->u44ab90()>tg_cefc4c->getTurn464270()){st=" DISABLED "+intToString(h9c->turnsLeft577ad0())+" ";aX=tg_cebf70;nW=0x5b;}
     else if(h9c->u577940()){st=" CHARGING ";aX=tg_cebf88;nW=0x5c;}
     else if((!tg_b9651c[h9c->def9b4350()->f70]||h9c->getEffect457b70(0x6d))&&aN.isValid()&&!aN->isPlayer5c7600()){st=" INTEGRATED ";aX=tg_cebf90;nW=0x44;}
     else if(h9c->def9b4350()->b1ac){st=" FRAGILE ";aX=tg_cebf50;nW=0x43;}
     else{st=" INACTIVE ";aX=tg_cebef4;nW=0x42;}
     aH=tg_e_b979df;
     a8=tg_e_b979f6;
     b3=new TgLine(this,y,nW,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("State"),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b979f7,tg_cebf1c)}
     if(!st.empty()){special=new TgSpecial(b3,0x17,0,1,0,st,aX);special->show4ae4f0();}
     y++;
    }
    if(h9c->u4578a0()!=3||h9c->u457880()==0x1e){
     y++;
     TXT(this,2,y,0,string("Active Upkeep"),tg_cebfc0)
     y++;
     aI=h9c->u457df0();
     aX=tg_cebf98[tg_invPercentTier434840((int)aI,0x14)];
     aH="-0";
     b3=new TgLine(this,y,0x5d,true,aI!=0?tg_e_b97a11:aH,tg_e_b97a07);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Energy"),tg_cebf8c)
     if(aI!=0){TXT(b3,0x15,0,2,"-"+tg_floatToString405760(aI,0,1),tg_cebf1c)}
     wVal=tg_barWidth8b51f0(aI,tg_c36fec);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
     val=h9c->u457e10();
     aX=tg_cebf98[tg_invPercentTier434840(val,0x14)];
     aH="-0";
     b3=new TgLine(this,y,0x5e,true,val?tg_e_b97a13:aH,tg_e_b97a12);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Matter"),tg_cebf8c)
     if(val){TXT(b3,0x15,0,2,"-"+intToString(val),tg_cebf1c)}
     wVal=tg_barWidth8b51f0((float)val,tg_c36fec);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
     val=h9c->u577b10();
     aX=tg_cebf98[tg_invPercentTier434840(val,0x14)];
     aH="+0";
     b3=new TgLine(this,y,0x5f,true,val?tg_e_b97a2f:aH,tg_e_b97a2e);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Heat"),tg_cebf8c)
     if(val){TXT(b3,0x15,0,2,"+"+intToString(val)+(h9c->u4578a0()==0&&aN.isValid()&&h9c->u458220()?"*":tg_e_b97a4e),tg_cebf1c)}
     wVal=tg_barWidth8b51f0((float)val,tg_c36fec);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
    }
    switch(h9c->u4578a0()){
    case 0:
     y++;
     TXT(this,2,y,0,string("Power"),tg_cebfc0)
     y++;
     aX=tg_cebfa4;
     val=h9c->u577bd0();
     aH="+0";
     b3=new TgLine(this,y,0x60,true,val?tg_e_b97a5f:aH,tg_e_b97a4f);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Supply"),tg_cebf8c)
     if(val){TXT(b3,0x15,0,2,"+"+intToString(val)+(aN.isValid()&&h9c->u458220()?"*":tg_e_b97a6f),tg_cebf1c)}
     wVal=tg_barWidth8b51f0((float)val,tg_c36fc0);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
     val=h9c->u457ed0();
     aH="0";
     b3=new TgLine(this,y,0x61,true,val?tg_e_b97a7a:aH,tg_e_b97a79);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Storage"),tg_cebf8c)
     if(val){TXT(b3,0x15,0,2,intToString(val),tg_cebf1c)}
     wVal=tg_barWidth8b51f0((float)val,tg_c37030);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
     val=h9c->u457f10();
     aX=tg_cebf98[tg_percentTier4347e0(100-val,100)];
     aH="N/A";
     b3=new TgLine(this,y,0x62,true,val?tg_e_b97a9b:aH,tg_e_b97a7b);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Stability"),tg_cebf8c)
     if(val){TXT(b3,0x15,0,2,intToString(100-val)+"%",tg_cebf1c)}
     wVal=tg_barWidth8b51f0((float)(val?100-val:0),tg_c36ec8);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
     break;
    case 1:
     y++;
     TXT(this,2,y,0,string("Propulsion"),tg_cebfc0)
     y++;
     val=h9c->u577c90();
     aX=tg_cebf98[tg_invPercentTier434840(val,0x96)];
     aH=tg_e_b97aa7;
     b3=new TgLine(this,y,0x63,true,val?tg_e_b97ab7:aH,tg_e_b97ab6);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Time/Move"),tg_cebf8c)
     if(val){TXT(b3,0x15,0,2,intToString(val)+(h9c->u457880()==0xa&&aN.isValid()&&h9c->u458220()?"*":tg_e_b97ac9),tg_cebf1c)}
     wVal=tg_barWidth8b51f0((float)val,tg_c370b0);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
     if(h9c->u457880()<=0xb){
      val=h9c->u457f50();
      aH=tg_e_b97aca;
      a8=tg_e_b97acb;
      b3=new TgLine(this,y,0x65,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Drag"),tg_cebf8c)
      if(1){TXT(b3,0x15,0,2,intToString(val),tg_cebf1c)}
      if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
      y++;
     }
     else{
     val=h9c->u457f30();
     aH=tg_e_b97ae5;
     a8=tg_e_b97ae6;
     b3=new TgLine(this,y,0x64,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string(" Mod/Extra"),tg_cebf8c)
     if(1){TXT(b3,0x15,0,2,intToString(val),tg_cebf1c)}
     if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
     y++;
     }
     {
     aI=h9c->u577d80();
     aX=tg_cebf98[tg_invPercentTier434840((int)aI,0xa)];
     bool star=h9c->u457880()>=0xc&&aN.isValid()&&h9c->u458220();
     aH="-0";
     b3=new TgLine(this,y,0x66,true,aI!=0?tg_e_b97c0e:aH,tg_e_b97ae7);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Energy"),tg_cebf8c)
     if(aI!=0){TXT(b3,0x15,0,2,"-"+tg_floatToString405760(aI,0,1)+(star?"*":tg_e_b97c0f),tg_cebf1c)}
     wVal=tg_barWidth8b51f0(aI,tg_c36e30);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
     val=h9c->u577df0();
     aX=tg_cebf98[tg_invPercentTier434840(val,0xa)];
     aH="+0";
     b3=new TgLine(this,y,0x67,true,val?tg_e_b98422:aH,tg_e_b9841b);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Heat"),tg_cebf8c)
     if(val){TXT(b3,0x15,0,2,"+"+intToString(val)+(star?"*":tg_e_b98423),tg_cebf1c)}
     wVal=tg_barWidth8b51f0((float)val,tg_c36e30);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
     val=h9c->u577e60();
     aX=tg_cebf98[tg_percentTier4347e0(val,0x14)];
     aH="0";
     b3=new TgLine(this,y,0x68,true,val?tg_e_b9842b:aH,tg_e_b9842a);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Support"),tg_cebf8c)
     if(val){TXT(b3,0x15,0,2,intToString(val)+(star?"*":tg_e_b98432),tg_cebf1c)}
     wVal=tg_barWidth8b51f0((float)val,tg_c36fec);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
     val=h9c->u577f30();
     aX=tg_cebf98[tg_invPercentTier434840(val,0x3c)];
     aH="0";
     b3=new TgLine(this,y,0x69,true,val?tg_e_b98439:aH,tg_e_b98433);
     add4aedc0(b3);
     TXT(b3,2,0,0,string(" Penalty"),tg_cebf8c)
     if(val){TXT(b3,0x15,0,2,intToString(val),tg_cebf1c)}
     wVal=tg_barWidth8b51f0((float)val,tg_c370ac);
     if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
     y++;
     if(h9c->def9b4350()->fec){
      int base=tg_ba0968[h9c->def9b4350()->fec]?0:h9c->def9b4350()->fec-2;
      val=h9c->def9b4350()->fec;
      aH=val?" ":"N/A";
      a8=tg_e_b9843a;
      b3=new TgLine(this,y,base+0x6b,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Special"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,string(" "),tg_cebf1c)}
      if(!(val?tg_d01b48[val]:string()).empty()){special=new TgSpecial(b3,0x17,0,2,0,val?tg_d01b48[val]:string(),tg_cebf8c);special->show4ae4f0();}
      y++;
     }
     else{
      val=h9c->u457f70();
      aX=tg_cebf98[tg_invPercentTier434840(val,100)];
      aH="N/A";
      b3=new TgLine(this,y,0x6a,true,val?tg_e_b98449:aH,tg_e_b9843b);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Burnout"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,intToString(val)+"%",tg_cebf1c)}
      wVal=tg_barWidth8b51f0((float)val,tg_c36ec8);
      if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
      y++;
     }
     break;
     }
     break;
    case 3:
     if(h9c->u457880()==0x1e)break;
     if(h9c->u457880()<0x1a){
      y++;
      TXT(this,2,y,0,string("Shot"),tg_cebfc0)
      y++;
      val=h9c->u4580a0();
      aX=tg_cebf98[tg_percentTier4347e0(val,0x14)];
      aH="0";
      b3=new TgLine(this,y,0x6e,true,val?tg_e_b9844b:aH,tg_e_b9844a);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Range"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,intToString(val),tg_cebf1c)}
      wVal=tg_barWidth8b51f0((float)val,tg_c36fec);
      if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
      y++;
      val=h9c->u5788e0();
      aX=tg_cebf98[tg_invPercentTier434840(val,0x32)];
      aH="-0";
      b3=new TgLine(this,y,0x6f,true,val?tg_e_b98452:aH,tg_e_b98451);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Energy"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,"-"+intToString(val)+(aN.isValid()&&h9c->u458220()?"*":tg_e_b98453),tg_cebf1c)}
      wVal=tg_barWidth8b51f0((float)val,tg_c370a8);
      if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
      y++;
      val=h9c->u5789c0();
      aX=tg_cebf98[tg_invPercentTier434840(val,0x19)];
      aH="-0";
      b3=new TgLine(this,y,0x70,true,val?tg_e_b98777:aH,tg_e_b98776);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Matter"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,"-"+intToString(val),tg_cebf1c)}
      wVal=tg_barWidth8b51f0((float)val,tg_c37034);
      if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
      y++;
      val=h9c->u578a70();
      aX=tg_cebf98[tg_invPercentTier434840(val,100)];
      aH="+0";
      b3=new TgLine(this,y,0x71,true,val?tg_e_b98795:aH,tg_e_b98787);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Heat"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,"+"+intToString(val)+(aN.isValid()&&h9c->u458220()?"*":tg_e_b98796),tg_cebf1c)}
      wVal=tg_barWidth8b51f0((float)val,tg_c36ec8);
      if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
      y++;
      val=h9c->u458100();
      aH="0";
      a8=tg_e_b98797;
      b3=new TgLine(this,y,0x72,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Recoil"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,intToString(val),tg_cebf1c)}
      if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
      y++;
      val=h9c->u578b10();
      aH="0%";
      a8=tg_e_b987a7;
      b3=new TgLine(this,y,0x73,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Targeting"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,tg_intToStringSigned405560(val)+"%",tg_cebf1c)}
      if(!string(tg_e_b987bd).empty()){special=new TgSpecial(b3,0x17,0,2,0,string(tg_e_b987be),tg_cebf8c);special->show4ae4f0();}
      y++;
      val=h9c->u4580e0();
      aH="0";
      a8=tg_e_b987bf;
      b3=new TgLine(this,y,0x74,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Delay"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,tg_intToStringSigned405560(val),tg_cebf1c)}
      if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
      y++;
      val=h9c->u458160();
      aX=tg_cebf98[tg_percentTier4347e0(100-val,100)];
      aH="N/A";
      b3=new TgLine(this,y,0x75,true,val?tg_e_b987d2:aH,tg_e_b987d1);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Stability"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,intToString(100-val)+"%",tg_cebf1c)}
      wVal=tg_barWidth8b51f0((float)(val?100-val:0),tg_c36ec8);
      if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
      y++;
      if(h9c->u4580c0()){
       val=h9c->u4580c0();
       aH=val?intToString(val):string("N/A");
       a8=tg_e_b987d3;
       b3=new TgLine(this,y,0x77,false,aH,a8);
       add4aedc0(b3);
       TXT(b3,2,0,0,string("Waypoints"),tg_cebf8c)
       if(val){TXT(b3,0x15,0,2,intToString(val),tg_cebf1c)}
       if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
       y++;
      }
      else{
      val=h9c->u458140();
      aH=val?intToString(val):string("N/A");
      a8=tg_e_b987e6;
      b3=new TgLine(this,y,0x76,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Arc"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,intToString(val),tg_cebf1c)}
      if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
      y++;
      }
      TgExpl*expl=h9c->def9b4350()->f1a0;
      if(h9c->def9b4350()->name24.find("Potential Cannon")!=string::npos||h9c->def9b4350()->name24.find("YOLO Cannon")!=string::npos||h9c->def9b4350()->name24.find("Firepult")!=string::npos||h9c->def9b4350()->name24.find("Plasma Storm")!=string::npos||h9c->def9b4350()->name24.find("Blast Cannon")!=string::npos||h9c->def9b4350()->name24.find("RU-N14's Throwing Claymores")!=string::npos||h9c->def9b4350()->name24.find("Voltaic Drivehammer")!=string::npos)expl=0;
      if(expl){
       y++;
       TXT(this,2,y,0,string("Explosion"),tg_cebfc0)
       y++;
       if(h9c->u458120()>1){
        y--;
        string cnt=" x"+intToString(h9c->u458120())+" ";
        aX=tg_cebfe8;
        special=new TgSpecial(this,0x18,y,1,0,cnt,aX);special->show4ae4f0();
        y++;
       }
       val=expl->f3c;
       if(!expl->f40){
        aX=tg_cebfa4;
        aH=tg_e_b987e7;
        b3=new TgLine(this,y,0x78,true,val?tg_e_b987f7:aH,tg_e_b987f6);
        add4aedc0(b3);
        TXT(b3,2,0,0,string("Radius"),tg_cebf8c)
        if(val){TXT(b3,0x15,0,2,intToString(val),tg_cebf1c)}
        wVal=tg_barWidth8b51f0((float)val,tg_c370a4);
        if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
        y++;
       }
       else{
        string dir="Directional ("+intToString(expl->f40)+" deg)";
        aH=tg_e_b98813;
        a8=tg_e_b98823;
        b3=new TgLine(this,y,0x79,false,aH,a8);
        add4aedc0(b3);
        TXT(b3,2,0,0,string("Radius"),tg_cebf8c)
        if(val){TXT(b3,0x15,0,2,intToString(val),tg_cebf1c)}
        if(!dir.empty()){special=new TgSpecial(b3,0x17,0,2,0,dir,tg_cebf8c);special->show4ae4f0();}
        y++;
       }
       val=expl->f30;
       aH=tg_e_b98837;
       b3=new TgLine(this,y,0x7a,true,val?tg_e_b98846:aH,tg_e_b98845);
       add4aedc0(b3);
       TXT(b3,2,0,0,string("Damage"),tg_cebf8c)
       if(val){TXT(b3,0x15,0,2,intToString(val-expl->f34)+"-"+intToString(val+expl->f34),tg_cebf1c)}
       wVal=tg_barWidth8b51f0((float)val,tg_c36ec8);
       if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
       y++;
       val=expl->f38;
       aH="-0";
       a8=tg_e_b98847;
       b3=new TgLine(this,y,0x7b,false,aH,a8);
       add4aedc0(b3);
       TXT(b3,2,0,0,string(" Falloff"),tg_cebf8c)
       if(val){TXT(b3,0x15,0,2,"-"+intToString(val),tg_cebf1c)}
       if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
       y++;
       aH=tg_e_b98853;
       a8=tg_e_b9886f;
       b3=new TgLine(this,y,0x7c,false,aH,a8);
       add4aedc0(b3);
       TXT(b3,2,0,0,string(" Chunks"),tg_cebf8c)
       if(1){TXT(b3,0x15,0,2,expl->p44.rangeToString40c2b0("-"),tg_cebf1c)}
       if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
       y++;
       aH=tg_e_b98882;
       a8=tg_e_b98883;
       b3=new TgLine(this,y,expl->f2c+0x9c,false,aH,a8);
       add4aedc0(b3);
       TXT(b3,2,0,0,string("Type"),tg_cebf8c)
       if(0){TXT(b3,0x15,0,2,tg_e_b98897,tg_cebf1c)}
       if(!tg_d29980[expl->f2c].empty()){special=new TgSpecial(b3,0x17,0,2,0,tg_d29980[expl->f2c],tg_cebf8c);special->show4ae4f0();}
       y++;
       if(expl->f64){
        val=expl->f64;
        string ht=tg_cf6648[val]+" (+"+intToString(tg_b96178[val])+")";
        aH=" ";
        a8=tg_e_b988a6;
        b3=new TgLine(this,y,0x7e,false,aH,a8);
        add4aedc0(b3);
        TXT(b3,2,0,0,string("Heat Transfer"),tg_cebf8c)
        if(val){TXT(b3,0x15,0,2,string(" "),tg_cebf1c)}
        if(!ht.empty()){special=new TgSpecial(b3,0x17,0,2,0,ht,tg_cebf8c);special->show4ae4f0();}
        y++;
       }
       else{
        val=expl->f60;
        string sp=tg_d31b68[val]+" ("+intToString(tg_b9654c[val])+"%)";
        aH=val?" ":"N/A";
        a8=tg_e_b988a7;
        b3=new TgLine(this,y,0x7d,false,aH,a8);
        add4aedc0(b3);
        TXT(b3,2,0,0,string("Spectrum"),tg_cebf8c)
        if(val){TXT(b3,0x15,0,2,string(" "),tg_cebf1c)}
        if(!(val?sp:string()).empty()){special=new TgSpecial(b3,0x17,0,2,0,val?sp:string(),tg_cebf8c);special->show4ae4f0();}
        y++;
       }
       val=expl->f5c;
       aH="0%";
       b3=new TgLine(this,y,0x7f,true,val?tg_e_b989e2:aH,tg_e_b989d7);
       add4aedc0(b3);
       TXT(b3,2,0,0,string("Disruption"),tg_cebf8c)
       if(val){TXT(b3,0x15,0,2,intToString(val)+"%",tg_cebf1c)}
       wVal=tg_barWidth8b51f0((float)val,tg_c370a8);
       if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
       y++;
       val=expl->f58;
       aH="+0";
       a8=tg_e_b989e3;
       b3=new TgLine(this,y,0x80,false,aH,a8);
       add4aedc0(b3);
       TXT(b3,2,0,0,string("Salvage"),tg_cebf8c)
       if(val){TXT(b3,0x15,0,2,tg_intToStringSigned405560(val),tg_cebf1c)}
       if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
       y++;
      }
      else{
       if(h9c->def9b4350()->f128==9)break;
       y++;
       TXT(this,2,y,0,string("Projectile"),tg_cebfc0)
       y++;
       if(h9c->u458120()>1||h9c->def9b4350()->b164){
        y--;
        string pc=" ";
        if(h9c->u458120()>1)pc+="x"+intToString(h9c->u458120())+" ";
        if(h9c->def9b4350()->b164)pc+="WIDE ";
        aX=tg_cebfe8;
        special=new TgSpecial(this,0x18,y,1,0,pc,aX);special->show4ae4f0();
        y++;
       }
       float b8=aN.isValid()&&h9c->u458220()?aN->u5d7bc0():1.0;
       int dmin=(int)(h9c->def9b4350()->f120*b8);
       int pK=(int)(h9c->def9b4350()->f124*b8);
       string dmg=intToString(dmin)+"-"+intToString(pK);
       if(b8!=1)dmg+="*";
       aX=tg_cebfa4;
       aH=tg_e_b989ee;
       b3=new TgLine(this,y,0x81,true,1?tg_e_b989f6:aH,tg_e_b989ef);
       add4aedc0(b3);
       TXT(b3,2,0,0,string("Damage"),tg_cebf8c)
       if(1){TXT(b3,0x15,0,2,dmg,tg_cebf1c)}
       wVal=tg_barWidth8b51f0((float)((dmin+pK)/2),tg_c36ec8);
       if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
       y++;
       aH=tg_e_b989f7;
       a8=tg_e_b989fe;
       b3=new TgLine(this,y,h9c.ptr9b65b0()->defnt9b4350()->f128+0x9c,false,aH,a8);
       add4aedc0(b3);
       TXT(b3,2,0,0,string("Type"),tg_cebf8c)
       if(0){TXT(b3,0x15,0,2,tg_e_b989ff,tg_cebf1c)}
       if(!tg_d29980[h9c->def9b4350()->f128].empty()){special=new TgSpecial(b3,0x17,0,2,0,tg_d29980[h9c->def9b4350()->f128],tg_cebf8c);special->show4ae4f0();}
       y++;
       val=h9c->def9b4350()->f138;
       tg_clampMax9cf5a0(&val,100);
       aH="0%";
       a8=tg_e_b98a07;
       b3=new TgLine(this,y,h9c.ptr9b65b0()->defnt9b4350()->f134+0x82,false,aH,a8);
       add4aedc0(b3);
       TXT(b3,2,0,0,string("Critical"),tg_cebf8c)
       if(val){TXT(b3,0x15,0,2,intToString(val)+"%",tg_cebf1c)}
       if(!(val?tg_d1e058[h9c->def9b4350()->f134]:string()).empty()){special=new TgSpecial(b3,0x17,0,2,0,val?tg_d1e058[h9c->def9b4350()->f134]:string(),tg_cebf8c);special->show4ae4f0();}
       y++;
       val=h9c->def9b4350()->v13c.size9b9260();
       string bX;
       string bC;
       if(val==1&&h9c->def9b4350()->v13c.front9b7060()==-1){bX="*";bC="Unlimited";}
       else{
        bX="x"+intToString(val);
        for(int i=0;i<val;i++){
         if(i)bC+=" / ";
         bC+=intToString(h9c->def9b4350()->v13c[i]);
        }
       }
       aH="x0";
       a8=tg_e_b98a27;
       b3=new TgLine(this,y,0x8f,false,aH,a8);
       add4aedc0(b3);
       TXT(b3,2,0,0,string("Penetration"),tg_cebf8c)
       if(val){TXT(b3,0x15,0,2,bX,tg_cebf1c)}
       if(!bC.empty()){special=new TgSpecial(b3,0x17,0,2,0,bC,tg_cebf8c);special->show4ae4f0();}
       y++;
       if(h9c->def9b4350()->f158){
        val=h9c->def9b4350()->f158;
        if(h9c->u458220())tg_fn9d06d0(&val,1,6);
        string ht=tg_cf6648[val]+" (+"+intToString(tg_b96178[val])+(h9c->u458220()?"*)":")");
        aH=" ";
        a8=tg_e_b98a32;
        b3=new TgLine(this,y,0x91,false,aH,a8);
        add4aedc0(b3);
        TXT(b3,2,0,0,string("Heat Transfer"),tg_cebf8c)
        if(val){TXT(b3,0x15,0,2,string(" "),tg_cebf1c)}
        if(!ht.empty()){special=new TgSpecial(b3,0x17,0,2,0,ht,tg_cebf8c);special->show4ae4f0();}
        y++;
       }
       else{
        val=h9c->def9b4350()->f154;
        string sp=tg_d31b68[val]+" ("+intToString(tg_b9654c[val])+"%)";
        aH=val?" ":"N/A";
        a8=tg_e_b98a33;
        b3=new TgLine(this,y,0x90,false,aH,a8);
        add4aedc0(b3);
        TXT(b3,2,0,0,string("Spectrum"),tg_cebf8c)
        if(val){TXT(b3,0x15,0,2,string(" "),tg_cebf1c)}
        if(!(val?sp:string()).empty()){special=new TgSpecial(b3,0x17,0,2,0,val?sp:string(),tg_cebf8c);special->show4ae4f0();}
        y++;
       }
       val=h9c->def9b4350()->f150;
       aH="0%";
       b3=new TgLine(this,y,0x92,true,val?tg_e_b98a6e:aH,tg_e_b98a6d);
       add4aedc0(b3);
       TXT(b3,2,0,0,string("Disruption"),tg_cebf8c)
       if(val){TXT(b3,0x15,0,2,intToString(val)+"%",tg_cebf1c)}
       wVal=tg_barWidth8b51f0((float)val,tg_c370a8);
       if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
       y++;
       val=h9c->def9b4350()->f12c;
       aH="+0";
       a8=tg_e_b98a6f;
       b3=new TgLine(this,y,0x93,false,aH,a8);
       add4aedc0(b3);
       TXT(b3,2,0,0,string("Salvage"),tg_cebf8c)
       if(val){TXT(b3,0x15,0,2,tg_intToStringSigned405560(val),tg_cebf1c)}
       if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
       y++;
      }
     }
     else{
      y++;
      TXT(this,2,y,0,string("Attack"),tg_cebfc0)
      y++;
      val=h9c->u5788e0();
      aX=tg_cebf98[tg_invPercentTier434840(val,0x32)];
      aH="-0";
      b3=new TgLine(this,y,0x94,true,val?tg_e_b98a7e:aH,tg_e_b98a7d);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Energy"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,"-"+intToString(val),tg_cebf1c)}
      wVal=tg_barWidth8b51f0((float)val,tg_c370a8);
      if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
      y++;
      val=h9c->u5789c0();
      aX=tg_cebf98[tg_invPercentTier434840(val,0x19)];
      aH="-0";
      b3=new TgLine(this,y,0x95,true,val?tg_e_b98a91:aH,tg_e_b98a7f);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Matter"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,"-"+intToString(val),tg_cebf1c)}
      wVal=tg_barWidth8b51f0((float)val,tg_c37034);
      if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
      y++;
      val=h9c->u578a70();
      aX=tg_cebf98[tg_invPercentTier434840(val,100)];
      aH="+0";
      b3=new TgLine(this,y,0x96,true,val?tg_e_b98a93:aH,tg_e_b98a92);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Heat"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,"+"+intToString(val),tg_cebf1c)}
      wVal=tg_barWidth8b51f0((float)val,tg_c36ec8);
      if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
      y++;
      val=h9c->u578b10();
      aH="0%";
      a8=tg_e_b98a9f;
      b3=new TgLine(this,y,0x97,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Targeting"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,tg_intToStringSigned405560(val)+"%",tg_cebf1c)}
      if(!string(tg_e_b98aab).empty()){special=new TgSpecial(b3,0x17,0,2,0,string(tg_e_b98ab7),tg_cebf8c);special->show4ae4f0();}
      y++;
      val=h9c->u4580e0();
      aH="0";
      a8=tg_e_b98ac3;
      b3=new TgLine(this,y,0x98,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Delay"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,tg_intToStringSigned405560(val),tg_cebf1c)}
      if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
      y++;
      if(h9c->def9b4350()->f128==9)break;
      y++;
      TXT(this,2,y,0,string("Hit"),tg_cebfc0)
      y++;
      int dmin=h9c->def9b4350()->f120;
      int pd=h9c->def9b4350()->f124;
      string dmg=intToString(dmin)+"-"+intToString(pd);
      aX=tg_cebfa4;
      aH=tg_e_b98acf;
      b3=new TgLine(this,y,0x99,true,1?tg_e_b98ae7:aH,tg_e_b98adb);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Damage"),tg_cebf8c)
      if(1){TXT(b3,0x15,0,2,dmg,tg_cebf1c)}
      wVal=tg_barWidth8b51f0((float)((dmin+pd)/2),tg_c36ec8);
      if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
      y++;
      aH=tg_e_b98afb;
      a8=tg_e_b98b0e;
      b3=new TgLine(this,y,h9c.ptr9b65b0()->defnt9b4350()->f128+0x9c,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Type"),tg_cebf8c)
      if(0){TXT(b3,0x15,0,2,tg_e_b98b0f,tg_cebf1c)}
      if(!tg_d29980[h9c->def9b4350()->f128].empty()){special=new TgSpecial(b3,0x17,0,2,0,tg_d29980[h9c->def9b4350()->f128],tg_cebf8c);special->show4ae4f0();}
      y++;
      val=h9c->def9b4350()->f138;
      aH="0%";
      a8=tg_e_b98b22;
      b3=new TgLine(this,y,h9c.ptr9b65b0()->defnt9b4350()->f134+0x82,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Critical"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,intToString(val)+"%",tg_cebf1c)}
      if(!(val?tg_d1e058[h9c->def9b4350()->f134]:string()).empty()){special=new TgSpecial(b3,0x17,0,2,0,val?tg_d1e058[h9c->def9b4350()->f134]:string(),tg_cebf8c);special->show4ae4f0();}
      y++;
      val=h9c->def9b4350()->f150;
      aH="0%";
      b3=new TgLine(this,y,0x9a,true,val?tg_e_b98b47:aH,tg_e_b98b23);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Disruption"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,intToString(val)+"%",tg_cebf1c)}
      wVal=tg_barWidth8b51f0((float)val,tg_c370a8);
      if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
      y++;
      val=h9c->def9b4350()->f12c;
      aH="+0";
      a8=tg_e_b98b6f;
      b3=new TgLine(this,y,0x9b,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string("Salvage"),tg_cebf8c)
      if(val){TXT(b3,0x15,0,2,tg_intToStringSigned405560(val),tg_cebf1c)}
      if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
      y++;
     }
    }
    if(h9c->u457f90()&&h9c->u457f90()!=0x2e&&h9c->u457f90()!=0xc9&&h9c->u457f90()!=0x9e&&h9c->u457f90()!=0xd6&&!h9c->def9b4350()->bfc){
     y++;
     TXT(this,2,y,0,string("Effect"),tg_cebfc0)
     y++;
     string eff;
     h9c->def9b4350()->describe55f080(eff);
     if(h9c->def9b4350()->f284==1){
      if(!bAC||this==tg_cec124||y<getHeight4174c0()-6){
       eff=tg_truncate408490(eff,tg_cf0db0-5);
       aH=tg_e_b98b83;
       a8=tg_e_b98b92;
       b3=new TgLine(this,y,0x192,false,aH,a8);
       add4aedc0(b3);
       TXT(b3,2,0,0,string(eff),tg_cebf8c)
       if(0){TXT(b3,0x15,0,2,tg_e_b98b93,tg_cebf1c)}
       if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
       y++;
      }
      TgButton*btn=new TgButton(this,4,y,0x10,"MORE");btn->animate4ae610();
      pCC.set40a010(0,y+1);
      y++;
     }
     else{
      int lines=printWrapped418260(2,y,tg_cf0db0-5,tg_cf0db4-2-y,eff);
      if(lines==1){
       aH=tg_e_b98bb6;
       a8=tg_e_b98bb7;
       b3=new TgLine(this,y,0x192,false,aH,a8);
       add4aedc0(b3);
       TXT(b3,2,0,0,string(eff),tg_cebf8c)
       if(0){TXT(b3,0x15,0,2,tg_e_b98bca,tg_cebf1c)}
       if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
       y++;
      }
      else{
       tg_lookupColor9d45a0("Type_GR3_Vert_E",aX);
       for(int x=2;x<=tg_cf0db0-4;x++)engine->u50fb50()->init50de10(engine,aX,TgPos2(x,y),tg_d2e20c,TgPos2(x,y+lines-1),TgPt(tg_d2e20c),9);
       y+=lines;
      }
     }
    }
   }
   if(bAC&&this!=tg_cec124&&(h9c->def9b4350()->f54||tg_cf4844[h9c->nested457820()])){
    y++;
    string fab="Fabrication";
    if(h9c->def9b4350()->f204>1)fab+=" (x"+intToString(h9c->def9b4350()->f204)+")";
    TXT(this,2,y,0,string(fab),tg_cebfc0)
    y++;
    string suf=h9c->def9b4350()->getSuffix457650();
    aH=tg_e_b98bcb;
    a8=tg_e_b98bde;
    b3=new TgLine(this,y,0xa6,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Time"),tg_cebf8c)
    if(0){TXT(b3,0x15,0,2,tg_e_b98bdf,tg_cebf1c)}
    if(!suf.empty()){special=new TgSpecial(b3,0x17,0,2,0,suf,tg_cebf8c);special->show4ae4f0();}
    y++;
    if(h9c->def9b4350()->v1f4.empty9b86e0()){
     aH=tg_e_b98c83;
     a8=tg_e_b98c9b;
     b3=new TgLine(this,y,0xa7,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Components"),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b98cb3,tg_cebf1c)}
     if(!string("None").empty()){special=new TgSpecial(b3,0x17,0,2,0,string("None"),tg_cebf8c);special->show4ae4f0();}
     y++;
    }
    else{
     aH=tg_e_b98ccb;
     a8=tg_e_b98ce3;
     b3=new TgLine(this,y,0xa7,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Components"),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b98cfb,tg_cebf1c)}
     if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
     y++;
     for(unsigned i=0;i<h9c->def9b4350()->v1f4.size9b9260();i++){
      string cn=" "+tg_d2d1c4[h9c->def9b4350()->v1f4[i]]->name;
      aH=tg_e_b98d13;
      a8=tg_e_b98d2b;
      b3=new TgLine(this,y,0xa7,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string(cn),tg_cebf8c)
      if(0){TXT(b3,0x15,0,2,tg_e_b98d43,tg_cebf1c)}
      if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
      y++;
     }
    }
   }
   if(!bAC||this==tg_cec124){
    y++;
    string desc;
    if(this!=tg_cec124&&!tg_cf4830[h9c->nested457820()]){
     switch(h9c->def9b4350()->f94){
     case 0:desc="All previously known information about this item was lost from the database.";break;
     case 1:desc="This is an unidentified prototype. Attaching it before proper analysis will identify its functions, but also carries the risk of negative side-effects if it is a faulty version.";break;
     case 2:desc="This is an unidentified construct. Parse the user to identify its functions.";break;
     case 3:desc="This is an unidentified alien artifact. Its properties are discovered by attaching it.";
     }
    }
    else if(h9c->u457880()<=3)desc=h9c->def9b4350()->desc288;
    else{
     string q3=h9c->u573860(this==tg_cec124,0);
     if(q3.find("Faulty ")!=string::npos){
      unsigned p=q3.find("Faulty ");
      q3.erase(q3.begin()+p,q3.begin()+p+7);
     }
     string d2=h9c->def9b4350()->desc288;
     if(!tg_d28d16&&h9c->def9b4350()->f1a8){
      unsigned q=d2.find("If triggered by chain reaction");
      if(q!=string::npos){
       d2.erase(d2.begin()+q,d2.end());
       if(d2.size()<6)d2="?";
      }
     }
     if(d2!="?"){
      if(q3!=h9c->getName571db0(0,0)){desc=q3;desc+=": ";}
      desc+=d2;
     }
     else if(q3!=h9c->getName571db0(0,0))desc="("+q3+")";
    }
    if(this!=tg_cec124&&tg_cf4830[h9c->nested457820()]){
     int own=-2;
     if(tg_d28d25&&!h9c->def9b4350()->art7c.empty9b81b0()){
      own=-1;
      for(int i=0;i<0x548;i++){
       if(tg_d035d8[i].s1c==h9c->u457860()){
        if(!tg_d035d8[i].s0.empty())own=i;
        break;
       }
      }
     }
     if(own!=-2){
      if(!desc.empty())desc+="\n\n";
      if(own==-1)desc+="<unclaimed>";
      else desc+="[ "+tg_d035d8[own].s0+" ]";
      desc+=tg_d25790[h9c->nested457820()]?" <in gallery>":" <uncollected>";
     }
    }
    if(!desc.empty()){
     if((h9c->def9b4350()->f284==2||h9c->def9b4350()->f284==3&&!tg_cebd5c)&&(this==tg_cec124||tg_cf4830[h9c->nested457820()])){
      desc=tg_truncate408490(desc,tg_cf0db0-5);
      b3=new TgLine(this,y,0x192,false,tg_e_b98d67,tg_e_b98d5b);
      add4aedc0(b3);
      TXT(b3,1,0,0,string(desc),tg_cebf8c)
      y++;
      TgButton*btn=new TgButton(this,3,y,0x10,"MORE");btn->animate4ae610();
      pCC.set40a010(0,y+1);
      y++;
     }
     else{
      int lines=printWrapped418260(2,y,tg_cf0db0-5,tg_cf0db4-2-y,desc);
      if(lines==1){
       b3=new TgLine(this,y,0x192,false,tg_e_b98d73,tg_e_b98d72);
       add4aedc0(b3);
       TXT(b3,1,0,0,string(desc),tg_cebf8c)
       y++;
      }
      else{
       tg_lookupColor9d45a0("Type_GR3_Vert_E",aX);
       for(int x=2;x<=tg_cf0db0-4;x++)engine->u50fb50()->init50de10(engine,aX,TgPos2(x,y),tg_d2e20c,TgPos2(x,y+lines-1),TgPt(tg_d2e20c),9);
       y+=lines;
      }
     }
    }
   }
  }
  else if(ha0.isValid()){
   if(!ha0.operator->()){close();return;}
   if(!ha0->def9b8f00()->ff4){tg_logError404f10("CInfo::trigger()","cannot display info for non-machine props ("+ha0->u45c590()+")");close();return;}
   y++;
   string nm=ha0->def9b8f00()->ff4==1&&!ha0->def9b8f00()->bfc?ha0->u45c590():ha0->getName45c5b0();
   TgCText*aY=new TgCText(this,TgPos2(tg_halfDiff437190(nm.size(),width44b0d0()-1)+1,y),nm,0,0,-1);
   aY->setColor48c3c0(tg_cebf0c);
   y++;
   y++;
   TXT(this,2,y,0,string("Overview"),tg_cebfc0)
   y++;
   val=ha0->u45c630();
   string b1;
   if(val==-1){b1="**";val=0x32;}
   else b1=intToString(val);
   aX=tg_cebf98[tg_percentTier4347e0(val,0x32)];
   aH="0";
   b3=new TgLine(this,y,0xa8,true,val?tg_e_b98d7f:aH,tg_e_b98d7e);
   add4aedc0(b3);
   TXT(b3,2,0,0,string("Armor"),tg_cebf8c)
   if(val){TXT(b3,0x15,0,2,b1,tg_cebf1c)}
   wVal=tg_barWidth8b51f0((float)val,tg_c370a8);
   if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
   y++;
   if(ha0->u45c800(10)){
    val=ha0->u45c870(10);
    int a5=ha0->u45c630()/5;
    b1=intToString(val)+" / "+intToString(a5);
    aX=tg_cebf98[tg_percentTier4347e0(val,a5)];
    aH="0";
    b3=new TgLine(this,y,0xa9,true,val?tg_e_b98d8b:aH,tg_e_b98d8a);
    add4aedc0(b3);
    TXT(b3,2,0,0,string(" Dismantling"),tg_cebf8c)
    if(val){TXT(b3,0x15,0,2,b1,tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)val,(float)a5);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
   }
   bool hasX=tg_cefc4c->getPlayer4630f0()->u5d2380(0x1a).isValid();
   TgProc*proc=NULL;
   if(!ha0->def9b8f00()->s124.empty()){
    string st;
    int sy;
    if(ha0->u45cb50()){st=" DETONATE ";aX=tg_cebfe0;sy=0xc7;}
    else switch(ha0->u457b10()){
    case 4:st=" COMPROMISED ";aX=tg_cebf20;sy=0xc8;break;
    case 3:st=" OVERLOAD ";aX=tg_cebfb8;sy=0xc9;break;
    case 2:if(hasX){st=" UNSTABLE "+intToString(tg_cefc4c->u464960(tg_d31640[ha0->u44ab40()]))+" ";aX=tg_cebf14;sy=0xca;break;}
    case 0:
     if(ha0->def9b8f00()->ff4==1){
      TgTerm*t=tg_d31640[ha0->u44ab40()].front9b7060()->u45cb30();
      if(t->f38){
       proc=t->f38;
       switch(proc->f4){
       case 0x43:case 0x4d:st=" PROCESSING T-"+intToString(proc->f8)+" ";aX=tg_cebf74;sy=0xcb;break;
       case 0x5c:case 0x5d:st="(0r_vp+ t="+intToString(proc->f8)+" ";aX=tg_cebf48;sy=0xcc;break;
       case 0x70:
        if(!proc->v34.empty9b86e0()){
         st=" TRANSMITTING ";
         if(tg_cefc4c->getPlayer4630f0()->u5d2380(0xc).isValid()||tg_cefc4c->getPlayer4630f0()->u5d2380(0xd).isValid())st+="T-"+intToString(proc->v34.front9b7060())+" ";
         aX=tg_cebf10;sy=0xcd;
        }
        else{
         st=" REDEPLOYING ";
         if(tg_cefc4c->getPlayer4630f0()->u5d2380(0xc).isValid()||tg_cefc4c->getPlayer4630f0()->u5d2380(0xd).isValid())st+="T-"+intToString(proc->f8)+" ";
         aX=tg_cebf10;sy=0xce;
        }
       }
       break;
      }
      if(t->f28==-1){st=" LOCKED ";aX=tg_cebf54;sy=0xcf;break;}
      else if(t->f28==-2){st=" CRASHED ";aX=tg_cebfec;sy=0xd0;break;}
      else if(t->b30){st=" TRACING "+intToString(t->f34)+" ";aX=tg_cebef0;sy=0xd1;break;}
     }
     st=" ACTIVE ";aX=tg_cebfe4;sy=0xc5;break;
    case 1:st=" "+tg_toUpper4083a0(ha0->def9b8f00()->s124)+" ";aX=tg_cebf04;sy=0xc6;
    }
    aH=tg_e_b98d95;
    a8=tg_e_b98d96;
    b3=new TgLine(this,y,sy,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("State"),tg_cebf8c)
    if(0){TXT(b3,0x15,0,2,tg_e_b98d97,tg_cebf1c)}
    if(!st.empty()){special=new TgSpecial(b3,0x17,0,1,0,st,aX);special->show4ae4f0();}
    y++;
   }
   if(proc){
    switch(proc->f4){
    case 0x43:
     aH=tg_e_b98da1;
     a8=tg_e_b98da2;
     b3=new TgLine(this,y,0x192,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Building..."),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b98da3,tg_cebf1c)}
     if(!tg_truncate408490(proc->fc?proc->fc->name24:proc->f10->s1ac,0x18).empty()){special=new TgSpecial(b3,0x17,0,2,0,tg_truncate408490(proc->fc?proc->fc->name24:proc->f10->s1ac,0x18),tg_cebf8c);special->show4ae4f0();}
     y++;
     break;
    case 0x4d:
     aH=tg_e_b98db5;
     a8=tg_e_b98db6;
     b3=new TgLine(this,y,0x192,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Repairing..."),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b98db7,tg_cebf1c)}
     if(!tg_truncate408490(proc->v18.front9b7060()->getName571db0(0,0),0x18).empty()){special=new TgSpecial(b3,0x17,0,2,0,tg_truncate408490(proc->v18.front9b7060()->getName571db0(0,0),0x18),tg_cebf8c);special->show4ae4f0();}
     y++;
    }
   }
   if(ha0->def9b8f00()->ff4==1){
    if(!tg_d31640[ha0->u44ab40()].front9b7060()->u45cb30()){
     aH=tg_e_b98dc3;
     a8=tg_e_b98e05;
     b3=new TgLine(this,y,0xaa,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Trojans"),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b98e06,tg_cebf1c)}
     if(!string("Disabled").empty()){special=new TgSpecial(b3,0x17,0,2,0,string("Disabled"),tg_cebf8c);special->show4ae4f0();}
     y++;
    }
    else if(tg_d31640[ha0->u44ab40()].front9b7060()->u45cb30()->v40.empty9b86e0()){
     aH=tg_e_b98e07;
     a8=tg_e_b98e1f;
     b3=new TgLine(this,y,0xaa,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Trojans"),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b98e2b,tg_cebf1c)}
     if(!string("None").empty()){special=new TgSpecial(b3,0x17,0,2,0,string("None"),tg_cebf8c);special->show4ae4f0();}
     y++;
    }
    else{
     TgVecU&tr=tg_d31640[ha0->u44ab40()].front9b7060()->u45cb30()->v40;
     for(unsigned i=0;i<tr.size9b9260();i++){
      aH=tg_e_b98e37;
      a8=tg_e_b98e5d;
      b3=new TgLine(this,y,tr[i]+0xab,false,aH,a8);
      add4aedc0(b3);
      TXT(b3,2,0,0,string(i==0?"Trojans":" "),tg_cebf8c)
      if(0){TXT(b3,0x15,0,2,tg_e_b98e5e,tg_cebf1c)}
      if(!tg_d39f30[tr[i]].empty()){special=new TgSpecial(b3,0x17,0,2,0,tg_d39f30[tr[i]],tg_cebf8c);special->show4ae4f0();}
      y++;
     }
    }
    if(!ha0->def9b8f00()->ff8&&!ha0->u457b10()&&ha0->u45c800(9)){
     aH=tg_e_b98e5f;
     a8=tg_e_b98e83;
     b3=new TgLine(this,y,0xc4,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string("Reconfiguration"),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b98e99,tg_cebf1c)}
     if(!(tg_intToStringSigned405560(ha0->u45c870(9))+"%").empty()){special=new TgSpecial(b3,0x17,0,2,0,tg_intToStringSigned405560(ha0->u45c870(9))+"%",tg_cebf8c);special->show4ae4f0();}
     y++;
    }
   }
   y++;
   TXT(this,2,y,0,string("Resistances"),tg_cebfc0)
   y++;
   for(int i=0;i<7;i++){
    int res=(int)(tg_c36cd0-ha0->def9b8f00()->ia8[i]/tg_c36cd0*ha0->def9b8f00()->f60->a20[i]/tg_c36cd0*tg_c36cd0);
    aX=tg_cebf98[res<0?0:3];
    string rs=(res>=0?intToString(res):"-"+intToString(-res))+"%";
    if(res<0)res=-res;
    aH="0%";
    b3=new TgLine(this,y,0xd2,true,res?tg_e_b98e9b:aH,tg_e_b98e9a);
    add4aedc0(b3);
    TXT(b3,2,0,0,string(tg_d29980[i]),tg_cebf8c)
    if(res){TXT(b3,0x15,0,2,rs,tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)res,tg_c36ec8);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
   }
   if(ha0->def9b8f00()->f8c){
    y++;
    TXT(this,2,y,0,string("Explosive Potential"),tg_cebfc0)
    y++;
    TgExpl*theEx=ha0->def9b8f00()->f8c;
    val=100-ha0->def9b8f00()->f80;
    aX=tg_cebf98[tg_percentTier4347e0(val,100)];
    aH="0%";
    b3=new TgLine(this,y,0xd3,true,val?tg_e_b98ea7:aH,tg_e_b98ea6);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Stability"),tg_cebf8c)
    if(val){TXT(b3,0x15,0,2,intToString(val)+"%",tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)val,tg_c36ec8);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    string dl=intToString(ha0->def9b8f00()->f84)+"-"+intToString(ha0->def9b8f00()->f88);
    aH=tg_e_b98eb2;
    a8=tg_e_b98eb3;
    b3=new TgLine(this,y,0xd4,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Delay"),tg_cebf8c)
    if(0){TXT(b3,0x15,0,2,tg_e_b98ebe,tg_cebf1c)}
    if(!dl.empty()){special=new TgSpecial(b3,0x17,0,2,0,dl,tg_cebf8c);special->show4ae4f0();}
    y++;
    aX=tg_cebfa4;
    val=theEx->f3c;
    aH=tg_e_b98ebf;
    b3=new TgLine(this,y,0x78,true,val?tg_e_b98ece:aH,tg_e_b98ecd);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Radius"),tg_cebf8c)
    if(val){TXT(b3,0x15,0,2,intToString(val),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)val,tg_c370a4);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    val=theEx->f30;
    aH=tg_e_b98ecf;
    b3=new TgLine(this,y,0x7a,true,val?tg_e_b98ede:aH,tg_e_b98edd);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Damage"),tg_cebf8c)
    if(val){TXT(b3,0x15,0,2,intToString(val-theEx->f34)+"-"+intToString(val+theEx->f34),tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)val,tg_c36ec8);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    val=theEx->f38;
    aH="-0";
    a8=tg_e_b98edf;
    b3=new TgLine(this,y,0x7b,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string(" Falloff"),tg_cebf8c)
    if(val){TXT(b3,0x15,0,2,"-"+intToString(val),tg_cebf1c)}
    if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
    y++;
    aH=tg_e_b98eed;
    a8=tg_e_b98eee;
    b3=new TgLine(this,y,0x7c,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string(" Chunks"),tg_cebf8c)
    if(1){TXT(b3,0x15,0,2,theEx->p44.rangeToString40c2b0("-"),tg_cebf1c)}
    if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
    y++;
    aH=tg_e_b98eef;
    a8=tg_e_b98ef7;
    b3=new TgLine(this,y,theEx->f2c+0x9c,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Type"),tg_cebf8c)
    if(0){TXT(b3,0x15,0,2,tg_e_b98f01,tg_cebf1c)}
    if(!tg_d29980[theEx->f2c].empty()){special=new TgSpecial(b3,0x17,0,2,0,tg_d29980[theEx->f2c],tg_cebf8c);special->show4ae4f0();}
    y++;
    val=theEx->f60;
    string jD=tg_d31b68[val]+" ("+intToString(tg_b9654c[val])+"%)";
    aH=val?" ":"N/A";
    a8=tg_e_b98f02;
    b3=new TgLine(this,y,0x7d,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Spectrum"),tg_cebf8c)
    if(val){TXT(b3,0x15,0,2," ",tg_cebf1c)}
    if(!(val?jD:string()).empty()){special=new TgSpecial(b3,0x17,0,2,0,val?jD:string(),tg_cebf8c);special->show4ae4f0();}
    y++;
    val=theEx->f64;
    string ht=tg_cf6648[val]+" (+"+intToString(tg_b96178[val])+")";
    aH=val?" ":"N/A";
    a8=tg_e_b98f03;
    b3=new TgLine(this,y,0x7e,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Heat Transfer"),tg_cebf8c)
    if(val){TXT(b3,0x15,0,2," ",tg_cebf1c)}
    if(!(val?ht:string()).empty()){special=new TgSpecial(b3,0x17,0,2,0,val?ht:string(),tg_cebf8c);special->show4ae4f0();}
    y++;
    val=theEx->f5c;
    aH="0%";
    b3=new TgLine(this,y,0x7f,true,val?tg_e_b98f0b:aH,tg_e_b98f07);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Disruption"),tg_cebf8c)
    if(val){TXT(b3,0x15,0,2,intToString(val)+"%",tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)val,tg_c370a8);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
    val=theEx->f58;
    aH="+0";
    a8=tg_e_b98f0f;
    b3=new TgLine(this,y,0x80,false,aH,a8);
    add4aedc0(b3);
    TXT(b3,2,0,0,string("Salvage"),tg_cebf8c)
    if(val){TXT(b3,0x15,0,2,tg_intToStringSigned405560(val),tg_cebf1c)}
    if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
    y++;
   }
  }
  else{
   if((*tg_cfd44c.atPoint9ced70(pA4))->u4550b0()&&!(*tg_cfd44c.atPoint9ced70(pA4))->u45dbb0()){close();return;}
   y++;
   TgCell*cB=*tg_cfd44c.atPoint9ced70(pA4);
   TgCellDef*t_=cB->def9fcd80();
   string c0=(*tg_cfd44c.atPoint9ced70(pA4))->name45d140();
   if(cB->isEdge45dc30()){
    if(tg_cefc4c->u463e90(pA4)){
     if(cB->isShortcut45dc50())c0="Emergency Access";
     else c0="Phase Wall";
     if(cB->getEffect45d350(6))c0.insert(0,"Broken ");
    }
    else t_=caveinWallTerrain;
   }
   else if(cB->u45db70()&&cB->getEffect45d350(6))c0.insert(0,"Broken ");
   TgCText*eX=new TgCText(this,TgPos2(tg_halfDiff437190(c0.size(),width44b0d0()-1)+1,y),c0,0,0,-1);
   eX->setColor48c3c0(tg_cebf0c);
   y++;
   y++;
   TXT(this,2,y,0,string("Overview"),tg_cebfc0)
   y++;
   val=t_->f68;
   string arm;
   if(val==-1){arm="**";val=0x41;}
   else arm=intToString(val);
   aX=tg_cebf98[tg_percentTier4347e0(val,0x41)];
   aH="0";
   b3=new TgLine(this,y,0xd5,true,val?tg_e_b98f17:aH,tg_e_b98f13);
   add4aedc0(b3);
   TXT(b3,2,0,0,string("Armor"),tg_cebf8c)
   if(val){TXT(b3,0x15,0,2,arm,tg_cebf1c)}
   wVal=tg_barWidth8b51f0((float)val,tg_c370a0);
   if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
   y++;
   y++;
   TXT(this,2,y,0,string("Resistances"),tg_cebfc0)
   y++;
   for(int i=0;i<7;i++){
    int res=(int)(tg_c36cd0-t_->f50->a20[i]/tg_c36cd0*tg_c36cd0);
    aX=tg_cebf98[res<0?0:3];
    string rs=(res>=0?intToString(res):"-"+intToString(-res))+"%";
    if(res<0)res=-res;
    aH="0%";
    b3=new TgLine(this,y,0xd6,true,res?tg_e_b98f1f:aH,tg_e_b98f1b);
    add4aedc0(b3);
    TXT(b3,2,0,0,string(tg_d29980[i]),tg_cebf8c)
    if(res){TXT(b3,0x15,0,2,rs,tg_cebf1c)}
    wVal=tg_barWidth8b51f0((float)res,tg_c36ec8);
    if(wVal){special=new TgSpecial(b3,0x17,0,0,wVal,string(),aX);special->show4ae4f0();}
    y++;
   }
   if(t_->sb8!="?"){
    y++;
    string d=t_->sb8;
    int lines=printWrapped418260(2,y,tg_cf0db0-5,tg_cf0db4-2-y,d);
    if(lines==1){
     aH=tg_e_b98f2f;
     a8=tg_e_b98f3e;
     b3=new TgLine(this,y,0x192,false,aH,a8);
     add4aedc0(b3);
     TXT(b3,2,0,0,string(d),tg_cebf8c)
     if(0){TXT(b3,0x15,0,2,tg_e_b98f3f,tg_cebf1c)}
     if(!string().empty()){special=new TgSpecial(b3,0x17,0,2,0,string(),tg_cebf8c);special->show4ae4f0();}
     y++;
    }
    else{
     tg_lookupColor9d45a0("Type_GR3_Vert_E",aX);
     for(int x=2;x<=tg_cf0db0-4;x++)engine->u50fb50()->init50de10(engine,aX,TgPos2(x,y),tg_d2e20c,TgPos2(x,y+lines-1),TgPt(tg_d2e20c),9);
     y+=lines;
    }
   }
  }
 }
}
