// Entity::projectileImpact (0x5f1010, 50 KB) on private placeholder types (zulu; Heni's semantic draft
// native/giants/5f1010_Entity_projectileImpact.cpp was the starting point for meaning).
// NOTE: placeholder names/layouts throughout: Zu*/zu_* are private, callees carry their exe address in the name.
// Lives in src/util/ (sorts last in the link) because it declares many private throw() aliases and nothrow helper
// ctors (ZuEff/ZuStatus/ZuTimer/ZuAtk, defined here so LTCG proves the `new` sites nothrow) that must not change
// nothrow inference for other files. Local names come from a bucket solver (scratch/zulu), hence the odd names.
#include <string>
using namespace std;
struct ZuVecI;struct ZuVecPt;struct ZuAtk;struct ZuEntity;struct ZuItem;struct ZuAI;struct ZuPos;struct ZuRange2;struct ZuTimer;struct ZuEvent;struct ZuStatus;struct ZuStatusList;struct ZuRec;
struct ZuHME{int id;ZuHME();};struct ZuHG{int id;};
struct ZuPos{int x,y;ZuPos();ZuPos(int);ZuPos(int,int);ZuPos(const ZuPos&)throw();ZuPos&operator=(const ZuPos&);bool contains40c190(int);int random40c130();bool operator!=(const ZuPos&)const;bool operator==(const ZuPos&)const;ZuPos(const ZuPos&,const ZuPos&);ZuPos&operator+=(const ZuPos&);};
struct ZuVecPt{int a,b,c,d;ZuVecPt();~ZuVecPt();unsigned size9b9a50()const throw();ZuPos&at9e7c10(unsigned);void clear9b3560();bool empty9b86e0()const;void push_back9b32e0(const ZuPos&);void push_back9b3020(ZuPos&&);};
struct ZuVecPos{int a,b,c,d;void push_back9b3020(ZuPos&&);};
struct ZuHE{int id;ZuHE()throw();bool operator!=(ZuHE)const;ZuEntity*operator->()const throw();bool operator==(ZuHE)const;bool isValid9b7230()const;bool isNull9b65d0()const;};
struct ZuHI{int id;ZuHI()throw();ZuItem*operator->()const;bool isValid9b7230()const;bool isNull9b65d0()const;void reset9b7270();};
struct ZuGroup;struct ZuHG2{int id;ZuGroup*operator->()const;};struct ZuPulled;struct ZuEffParams;struct ZuVecPt;
struct ZuVecHI{int a,b,c,d;ZuVecHI();~ZuVecHI();bool empty9b86e0()const;unsigned size9b9260()const throw();ZuHI&at9b81f0(unsigned);ZuHI&front9b7060();void push_back9b80b0(const ZuHI&);};
struct ZuGVec{int a,b,c,d;int&at9b81f0(unsigned);};
struct ZuVVI{int a,b,c,d;ZuGVec&at9b8070(unsigned);};
struct ZuSoundSet{char p0[0x50];ZuVVI v50;};
struct ZuEntDef{int f0;char p4[0x24-4];int f24;int f28;char p2c[0x48-0x2c];int f48;char p4c[0x90-0x4c];ZuSoundSet*f90;int f94;int f98;int f9c;char pa0[0xac-0xa0];int fac;string getName459c30();};
struct ZuRange{int x,y;int random40c130();};
struct ZuItemDef{char p0[0x24];string name;char p40[4];int f44;char p48[0xf0-0x48];int ff0;int ff4;char pf8[0x118-0xf8];int f118;int f11c;ZuPos f120;int f128;int f12c;int f130;int f134;int f138;char p13c[0x150-0x13c];int f150;int f154;int f158;int f15c;char p160[5];bool b165;char p166[0x16c-0x166];int f16c;int f170;string s174;char p190[0x1a0-0x190];int f1a0;int f1a4;int f1a8;bool b1ac;char p1ad[3];bool b1b0;char p1b1[0x278-0x1b1];int*f278;int f27c;int f280;};
struct ZuItemDef3{char p0[0x174];string s174;};
struct ZuItemDef2{char p0[0x70];int f70;};
struct ZuVecEff{int a,b,c,d;ZuVecEff(const ZuVecEff&);~ZuVecEff();bool empty9b86e0()const;};
struct ZuExpl{char p0[0x2c];int f2c;int f30;char p34[0x44-0x34];ZuPos f44;ZuPos f4c;int f54;int f58;int f5c;int f60;int f64;char p68[0x78-0x68];int f78;char p7c[0x9c-0x7c];ZuVecEff v9c;};
struct ZuEffList{int a,b,c,d,e;ZuEffList(ZuVecEff);~ZuEffList();};
struct ZuEff{void*type;int value;ZuEff(void*,int);};
ZuEff::ZuEff(void*type_,int value_){type=type_;value=value_;}
struct ZuVoidVec{int a,b,c,d;void*&at9b81f0(unsigned)throw();};extern ZuVoidVec zu_d2f0f8;
struct ZuAI{bool u581140();void u5b39b0(ZuHE);int get9b4350();bool u459090();ZuStatusList*u4590f0();};
struct ZuEntity{
	int f0;ZuHE self;ZuEntDef*data;char pc[0x28-0xc];ZuHG2 group28;int f2c;ZuVecPt f30;char p40[0x50-0x40];int f50;char p54[0x70-0x54];int f70;char p74[0x8c-0x74];int f8c;char p90[0xb4-0x90];int fb4;int fb8;int fbc;bool fc0;char pc1[0xc8-0xc1];int fc8;char pcc[0xd4-0xcc];int fd4;char pd8[0xec-0xd8];ZuEffList*fec;char pf0[0x134-0xf0];ZuVecHI items134;ZuAI*ai;
	void projectileImpact(ZuHE attacker,int a2,void*records,ZuItemDef*weapon,float f5,ZuPos*p6,bool b7,ZuExpl*expl,int*dmg);
	bool isPlayer5c7600();ZuEff*u45ac40(int);void u45b340(ZuEff*);const string&name416f40();const ZuPos&getPosition45a4a0()throw();
	bool u45aaa0(ZuHE);int u5c7f10();void u5fdab0();void u6335e0();void die633790(bool,int,ZuHE,bool,int,int,int,int);
	void u5e5340(bool,bool,int,bool,int,const string&);void u642940(ZuHI,bool,bool,bool,int);int getSize45a360();void u5c93d0(ZuVecI*);ZuVecHI*getInventoryList45ab00();ZuHI u5e3cb0(bool,int,ZuVecI*,bool,bool);int takeDamage5e5520(int,ZuItemDef*,ZuExpl*,int,int,int,int,bool,ZuHE,int,int,int,int,int);const string&getName45a280();void u637bb0();int u45a810();bool u5c84f0(const ZuPos&);bool u5c85a0(const ZuPos&,bool);bool u5c8710(const ZuPos&);bool checkTriggers5fdd30();bool u5cb680(ZuHG);int u45acb0(int);int u45a8d0();int u45a340();int u5d22a0(int);int u5d2150(int,int);int u5d2090(int);bool u5e2e60(int*,int);bool u5c8020();ZuHI u5d2380(int);int u5d1390();void u45b1b0(int);void u5fd550(ZuHI,int);void u5cb8b0(ZuVecHI*);bool u5c8820(ZuHE);int u5d15a0(bool);ZuPos u5c80f0(const ZuPos&);void u5c89d0(ZuVecPt*);int u5c7d30();void changePos5dccb0(const ZuPos&,bool);void u5ddac0(const ZuPos&,int);
};

struct ZuMap{void u735720(ZuHE,ZuHE,bool);ZuHE getPlayer4630f0();ZuHG u463890(int);ZuHE u7345f0(ZuHE,ZuHE,bool);void setA7c4654f0(ZuHE);};
extern ZuMap*zu_cefc4c;
struct ZuEntity2:ZuEntity{};
bool zu_show5111e0(int,const string*,const string*,const string*,ZuHE,ZuHE,const ZuPos*,int);
struct ZuBubble{void bubble8758d0(bool);};extern ZuBubble*zu_cec058;struct ZuLogMsgs{void scrollToEnd7b4f10();};extern ZuLogMsgs*zu_cec0b4;
#define MSG(t,a,b,c,s,o,p,x) do{if(zu_show5111e0(t,a,b,c,s,o,p,x))zu_cec058->bubble8758d0(1);zu_cec0b4->scrollToEnd7b4f10();}while(0)
void zu_logPhrase5141b0(int,const string*,const string*,const string*,ZuHE,int);
void zu_sound454260(const ZuPos&,int);void zu_sound4541b0(int,int,int);
struct ZuRng{bool chance406c90(int);int rangeInt406d70(float,float)throw();};extern ZuRng rng;
extern bool zu_b95758[];
struct ZuStats{ZuGVec*vals;bool add4729d0(unsigned,int,string,int);void add472b90(unsigned,int);};extern ZuStats zu_d2c658;
struct ZuPlayerData{bool isSlotEmpty46de40(int);bool hasCompanion780790();void u77fbc0(int);void u77ffb0(int,int);};extern ZuPlayerData zu_cf45d8;
struct ZuMapView{void u49aee0();void u8197f0(const ZuPos&,bool);};extern ZuMapView*zu_cec054;
extern ZuHE zu_cf69a8;
struct ZuEntityX:ZuEntity{void changeFaction5dc780(ZuHG,bool);};
struct ZuItemDef;struct ZuEffI;struct ZuItem{int u577ad0();bool get415ee0();int getEffectValue457be0(int);bool u457cf0();bool u457e90();int get9b6bf0();void set450460(int);void u458310(int);int u457900();int u457880();int u457fb0();int u457f90();int u457b30();void u57dbe0(int,int,int,int);int u457820();int getType44aec0();int u4578c0();int u577fb0();bool u57a190(ZuHE,int,bool,bool);ZuEffI*getEffect457b70(int);ZuItemDef*def9b4350();int u4578a0();string getName571db0(int,int);void setBroken5795b0(int,bool);void setActive5791a0(bool);void setActivateOkayTurn4583b0(int);};
struct ZuWL{int a[9];ZuWL();~ZuWL();void add9ba310(int,int);int&pick9ba470();};
struct ZuStatus{int f0,f4;ZuVecPos v8;int f18;ZuStatus(int);};
ZuStatus::ZuStatus(int t){f0=t;}
struct ZuStatusList{ZuStatus*u458950(int);ZuStatus*u57f140(ZuStatus*);};
struct ZuAI2{int get9b8f00();void u5b5220();void setFollow5b2f80(ZuHE,int);bool u5b3890(ZuHE,int);bool u459090();ZuStatusList*u4590f0();};
struct ZuEntityH:ZuEntity{ZuAI2*getAI45b590();int getTarget45a760();int getAiType45a2a0();int getFaction45a2c0();ZuHG getGroup45a3f0();
	void u5cb930(ZuVecHI*);void u45b210(int);bool u45ae30();ZuStatusList*u45ae50();bool isHostileTo45aa70(ZuHE);void u5fd900(int,int);ZuPos u45a4c0();void removeEffects639730(bool);};
struct ZuGroup{int get9b4350();};
struct ZuItemDefH:ZuItemDef{int get457330(int)throw();};
struct ZuAudio{bool enabled;char p1[0x9b];int f9c;bool u69edf0();void u69ee30(int,int,int);bool placeEntityNear6bd410(ZuRange2*,ZuPos*,ZuHE,bool,bool);void u69e700(int,int,float);};extern ZuAudio zu_d25450;
struct ZuMapH:ZuMap{bool u748a00(int,ZuItemDef*);ZuHE getEntity671_463110();void u74b060(const ZuPos&,int,int);void u6c65a0(ZuHE,const string&,int);void u464e10(ZuAtk*);void u730f40(ZuHE);void setA74_4654d0(bool);void impact749ee0(ZuHE,ZuPulled*,const ZuPos&,bool);bool findPlaceable71c150(const ZuPos&,ZuPos&,int);bool isReachable465230(int,const ZuPos&,const ZuPos&);void u464a00(ZuTimer*);bool isVisible4631c0(const ZuPos&);ZuHME addRecord777a20(ZuHME);bool u4631f0(ZuHE);void u4651b0(ZuHE);int getTurn464270();};
extern ZuRange zu_d22268,zu_d305d8;int zu_distance40a3f0(const ZuPos&,const ZuPos&);
string zu_intToString4051f0(int);void zu_eraseStep9d6440(ZuVecHI&,unsigned&);string zu_countString407a80(int,const string&);
struct ZuRec{char p0[0x28];int f28;char p2c[0x4c-0x2c];int f4c;};
struct ZuVecRec{int a,b,c,d;unsigned size9b9260()const throw();ZuRec*&at9b81f0(unsigned);};extern ZuVecRec zu_cfd2cc;
struct ZuGameData{int getDepthIndex();const string&getEntryText46f6d0(const string&);void setEntryText46f700(const string&,const string&);};extern ZuGameData zu_d1e860;
struct ZuEvent{int a[16];ZuEvent(ZuHE,ZuRec*,const ZuPos&,ZuHE,const ZuPos&,const ZuPos&);};
struct ZuFactory{ZuHME createA7930e0(ZuEvent*);};extern ZuFactory*zu_cefaa8;
struct ZuRange2{int a,b;ZuRange2();void set40a010(int,int);};
struct ZuTimer{int f0;int f4,f8;int fc;ZuTimer(ZuHE,const ZuPos&,int);};
ZuTimer::ZuTimer(ZuHE e,const ZuPos&p,int t){f0=e.id;f4=p.x;f8=p.y;fc=t;}
bool zu_lookup9d7980(const string&,int*);
struct ZuFx{void init503b20(int,const ZuPos&,const ZuPos*,const ZuPos*,const ZuPos*,ZuEffParams*,int,int);};struct ZuFxPool{ZuFx*new508610(ZuFxPool*);};extern ZuFxPool*zu_cefc50;extern ZuPos zu_d2e20c;
struct ZuVecHE{int a,b,c,d;ZuVecHE();~ZuVecHE();unsigned size9b9260()const throw();ZuHE&at9b81f0(unsigned);ZuHE&front9b7060();void push_back9b7cf0(ZuHE&&);void push_back9b80b0(const ZuHE&);};
void zu_shuffle9d9fc0(ZuVecHE&);void zu_moveElement9da1f0(ZuVecHE&,int,int);
struct ZuVecI{int a,b,c,d;ZuVecI();~ZuVecI();void push_back9b9d30(const int&);bool empty9b86e0()const;unsigned size9b9260()const throw();int&at9b81f0(unsigned);void push_back9b9280(int&&);};
bool zu_anyPositive9d54c0(ZuVecI&);void zu_shuffle9d8f80(ZuVecI&);extern int zu_cf462c;
bool zu_trace4106d0(const ZuPos&,const ZuPos&,ZuVecPt&,ZuVecI&,int);void zu_shuffle9d7350(ZuVecPt&);bool zu_inVector9d0ce0(ZuVecPt&,ZuPos);
void zu_appendRange9d9890(ZuVecPt&,ZuVecPt&,int,int);void zu_fillIndices9d98e0(ZuVecPt&,ZuVecI&);
struct ZuArea{int a,b,c,d;ZuArea();ZuPos randomPoint40be90();void getBorder40bac0(ZuVecPt&);void grow40bc10(int);};
struct ZuPropType{char p0[0x8c];int f8c;};
struct ZuDispatch;struct ZuPropData{char p0[0x38];ZuDispatch*f38;string u65cc80();};
struct ZuProp{int getState457b10();ZuPropData*getData45cb30();bool isPassableFor65e1d0(ZuHE);void u45ceb0(ZuHE,bool);const ZuPos&getPos4184d0();ZuPropType*get9b8f00();int u45c630();void u45ce10(bool,int,bool,ZuHE);};
struct ZuHP{int id;ZuHP();ZuProp*operator->()const;bool isValid9b7230()const;bool isNull9b65d0()const;};
struct ZuPulled{int a[7];int f1c;ZuPulled(int,const ZuPos&);};
struct ZuEffParams{int a[25];ZuEffParams(int,ZuHE,int,int,float,ZuHE,ZuHE,int,ZuHE,int,int,ZuPulled*);};
struct ZuAtk{int a,b,c;ZuAtk(ZuHE,ZuHE);};
ZuAtk::ZuAtk(ZuHE x,ZuHE y){a=x.id;b=y.id;c=0;}
struct ZuOvermind{bool u68fc40();};extern ZuOvermind zu_cf6428;
struct ZuLoc{int f0;int f4;};struct ZuHLoc{int id;ZuLoc*operator->()const;};extern ZuHLoc zu_d1e888;
int zu_stringToInt405610(const string&);
struct ZuMsgLog{void set451400(int);};extern ZuMsgLog zu_cf1080;
extern ZuHE zu_cf68b8;extern int zu_cf6954,zu_cf68b4;
struct ZuTQ{void u6728c0(ZuHE);};extern ZuTQ zu_d225a0;
struct ZuCf68f0{void u672f20(ZuHE,int,int,string);};extern ZuCf68f0*zu_cf68f0;
void zu_sound4542a0(const ZuPos&,int,int);
struct ZuShake{void shake4b38f0(int,int);};extern ZuShake zu_d2f1c8;
void zu_message49c610(int,ZuHE,const string&,int);
bool zu_turn51da30(void*,int,ZuHE,ZuHE,ZuHE,int,int);
struct ZuHP;bool zu_4569a0(int,ZuHE,ZuHE,ZuHP,ZuHI,int,const string*,ZuEffList*,ZuHE,ZuHP,ZuHI,int);
extern bool zu_d28f98;extern int zu_caed20;extern ZuGVec zu_cf4910;extern const float zu_b9764c;extern float zu_b949b8[],zu_b949a8[];extern int zu_cf49bc[];
bool zu_inRange9daf80(int,int,int);void zu_addCapped9d06d0(int*,int,int);int zu_minInt9cdb30(int,int);
extern string zu_d1f3d4;extern string zu_d323f8[];extern int zu_d1f3f0;
void zu_sound454160(const ZuPos&,int,int);
extern ZuPos zu_d015d8[];extern int zu_b962e8[],zu_b96308[];extern ZuPos zu_cfd420;
void zu_eraseAt9d5190(ZuVecPt&,int);ZuPos zu_randomPoint9d5350(ZuVecPt&);void zu_bresenham40ff30(const ZuPos&,const ZuPos&,ZuVecPt*);void zu_logWarning404e50(string,string);
struct ZuObj717{void u45b6b0(ZuHE,const ZuPos&);};
struct ZuVVPt{int a,b,c,d;ZuVecPt&at9b8070(unsigned);};
struct ZuMapK{ZuVVPt*getMarkers459070();bool u7168e0(const ZuPos&,const ZuPos&,ZuEntity*,ZuVecPt*);const ZuPos&u462f60(ZuHP);ZuObj717*u717be0();};
struct ZuAlarm{int a,b,c,d,e,f;};extern ZuAlarm zu_b93fc8[],zu_b93fcc[],zu_b93fd0[];
extern bool zu_cf65bf,zu_d28fb0;extern int zu_cf4718;
struct ZuDispatch{int a[18];ZuDispatch(ZuHP,int,int,int,int,int,int,ZuHE,int,const ZuPos&,int,int);};
struct ZuRolled{bool say49e250(int,bool,string);};extern ZuRolled*zu_cefb48;int zu_dir4374c0(const ZuPos&,const ZuPos&);
struct ZuCPart{void u890710(int);ZuHI getItem4aeed0();void set450570(int);};
struct ZuVecCP{int a,b,c,d;unsigned size9b9260()const throw();ZuCPart*&at9b81f0(unsigned);};
struct ZuCParts{ZuVecCP*getParts4a9ad0();ZuCPart*u894e70(ZuHI);};extern ZuCParts*zu_cec088;
void zu_logError404f10(string,string);ZuHI zu_randomItem9dafb0(ZuVecHI&);int zu_maxInt9cdb60(int,int);extern int zu_cf4730;
struct ZuSpawnTracker{bool spawn7aa280(unsigned,bool,string);};struct ZuSpawnState{int f0;int a[10];int f2c;ZuSpawnTracker*f30;};extern ZuSpawnState*zu_cf4ac8;
struct ZuCell{bool u45d480();bool u45d4e0();bool u45d500();int getArmor66ae70();ZuHP getProp45d550();ZuHI getItem45d8f0();void u45e110(int,int,ZuHE);ZuHE getEntity45d250();bool canPlace66ad20(int);};
struct ZuGrid{bool contains9b43b0(const ZuPos&);ZuCell**at9ceda0(int,int);ZuCell**atPoint9ced70(ZuPos&);void getRect9b4430(const ZuPos&,int,ZuArea*);};extern ZuGrid zu_cfd44c;
extern int zu_b97e60[][4];extern bool zu_b9651c[];void zu_shuffle9d9fc0(ZuVecHI&);extern int zu_ba5ea4[];

void ZuEntity::projectileImpact(ZuHE attacker,int a2,void*records,ZuItemDef*weapon,float f5,ZuPos*p6,bool b7,ZuExpl*expl,int*dmg)
{
	bool aa=isPlayer5c7600();
	if(ai&&attacker.operator->()&&(!weapon||weapon->ff0!=0x77)){
		ai->u5b39b0(attacker);
		zu_cefc4c->u735720(attacker,self,1);
	}
	if(weapon){
		switch(weapon->ff0){
		case 0x72:
			if(!u45ac40(0x32))u45b340(new ZuEff(zu_d2f0f8.at9b81f0(0x32),1));
			MSG(aa?0x39:0x3a,0,0,0,self,ZuHE(),0,0);
			if(attacker.operator->()&&attacker->isPlayer5c7600())
				do{zu_logPhrase5141b0(0x68,&name416f40(),0,0,ZuHE(),0);}while(0);
			zu_sound454260(getPosition45a4a0(),0x117);
			break;
		case 0x77:
			if(attacker.operator->()&&attacker->isPlayer5c7600()){
				bool resolved=false;
				if(data->fac==0){
					bool allied=u45aaa0(zu_cefc4c->getPlayer4630f0());
					if(f70==3||f70==4||(allied&&f70==1)){
						resolved=true;
						int chance=allied?100:attacker->u5c7f10()/2+50;
						if(rng.chance406c90(chance)){
							if(allied){
								MSG(0x82,0,0,0,self,ZuHE(),0,0);
								u5fdab0();
							}else{
								MSG(0x8b,0,0,0,self,ZuHE(),0,0);
								if(zu_b95758[data->f48])
									do{zu_logPhrase5141b0(0x15,&name416f40(),0,0,ZuHE(),0);}while(0);
								u5fdab0();
								((ZuEntityX*)this)->changeFaction5dc780(zu_cefc4c->u463890(1),1);
								zu_sound4541b0(0x6b,0,0);
								zu_d2c658.add4729d0(0x37a,1,string(""),-1);
								zu_cf45d8.u77fbc0(0x63);
							}
							if(a2==0)zu_cec054->u49aee0();
							return;
						}else
							MSG(0x83,0,0,0,self,ZuHE(),0,0);
					}
				}
				if(!resolved){
					int ch=weapon->ff4;
					if(ai&&ai->get9b4350()<2)ch+=20;
					if(rng.chance406c90(ch)){
						if(data->fac==2||self==zu_cf69a8)
							MSG(0x1f1,0,0,0,self,ZuHE(),0,0);
						else{
							ZuHE hacked=zu_cefc4c->u7345f0(attacker,self,weapon->f44==0x1d);
							if(hacked.isValid9b7230()){
								MSG(0x1e2,0,0,0,hacked,ZuHE(),&getPosition45a4a0(),0);
								zu_sound4541b0(0x69,0,0);
							}else
								zu_cefc4c->setA7c4654f0(self);
						}
					}else{
						MSG(0x1f0,&weapon->name,0,0,self,ZuHE(),0,0);
						zu_sound4541b0(0x66,0,0);
					}
				}
			}
			break;
		case 0x78:
			if(attacker.operator->()){
				switch(weapon->ff4){
				case 0:
					if(attacker->isPlayer5c7600())
						MSG(0x1fa,0,0,0,self,ZuHE(),0,0);
					else
						MSG(0x1fb,0,0,0,self,ZuHE(),&attacker->getPosition45a4a0(),0);
					break;
				case 1:
					break;
				case 2:
					if(attacker->isPlayer5c7600())
						MSG(0x1ff,0,0,0,self,ZuHE(),0,0);
					else
						MSG(0x200,0,0,0,self,attacker,0,0);
					break;
				case 3:
					if((data->f24==0&&data->f28!=0)||!rng.chance406c90(((ZuItemDefH*)weapon)->get457330(0x7e)))
						goto hackDone;
					else
						goto hackStart;
				}
				if(data->fac==2||((ZuEntityH*)this)->getTarget45a760()!=0||self==zu_cf69a8){
					if(attacker->isPlayer5c7600()&&weapon->ff4!=1)
						MSG(0x1f1,0,0,0,self,ZuHE(),0,0);
				}else if(((ZuEntityH*)this)->getAiType45a2a0()==1&&((ZuHG2&)((ZuEntityH*)this)->getGroup45a3f0())->get9b4350()==3&&(
					((ZuEntityH*)this)->getFaction45a2c0()==6||((ZuEntityH*)this)->getFaction45a2c0()==0xd||((ZuEntityH*)this)->getFaction45a2c0()==0xe||
					((ZuEntityH*)this)->getFaction45a2c0()==0x10||((ZuEntityH*)this)->getFaction45a2c0()==0x11||((ZuEntityH*)this)->getFaction45a2c0()==0x12||
					((ZuEntityH*)this)->getFaction45a2c0()==0x15||((ZuEntityH*)this)->getFaction45a2c0()==0x16||((ZuEntityH*)this)->getFaction45a2c0()==0x17||
					((ZuEntityH*)this)->getFaction45a2c0()==0x18||((ZuEntityH*)this)->getFaction45a2c0()==0x1a||((ZuEntityH*)this)->getFaction45a2c0()==0x1c)){
				hackStart:
					ZuWL a8;
					if(weapon->ff4!=3)
						for(int i=0;i<0x49;i++)a8.add9ba310(i,zu_b97e60[i][weapon->ff4]);
					if(weapon->ff4==2||weapon->ff4==3)
						for(int j=0;j<0xb;j++)a8.add9ba310(j,zu_ba5ea4[j]);
				pickHack:
					int aI=a8.pick9ba470();
					while(aI==0x3e&&!attacker->isPlayer5c7600())aI=a8.pick9ba470();
					ZuHE tgt=self;
					ZuStatus*a7=0;
					switch(aI){
					case 0x3a:
						if(((ZuEntityH*)tgt.operator->())->getAI45b590()->u459090()&&((ZuEntityH*)tgt.operator->())->getAI45b590()->u4590f0()->u458950(0x3a)){
							MSG(0x1fc,&string("Found active disruption routine."),0,0,tgt,ZuHE(),0,0);
							goto hackDone;
						}else{
							((ZuEntityH*)tgt.operator->())->getAI45b590()->u4590f0()->u57f140(new ZuStatus(0x3a));
							MSG(0x1fc,&string("Initiated network disruption routine."),0,0,tgt,ZuHE(),0,0);
							((ZuMapH*)zu_cefc4c)->u4651b0(tgt);
						}
						break;
					case 0x3b:{
						ZuHI ps;
						ZuVecHI items;
						((ZuEntityH*)tgt.operator->())->u5cb930(&items);
						for(unsigned i=0;i<items.size9b9260();i++){
							if(items.at9b81f0(i)->u4578a0()==0){
								ps=items.at9b81f0(i);
								goto tweak;
							}
						}
						if(weapon->ff4!=1)
							MSG(0x1fd,&string("Unable to locate active power source."),0,0,tgt,ZuHE(),0,0);
						goto hackDone;
					tweak:
						MSG(0x1fc,&string("Tweaking power source heat flow."),0,0,self,ZuHE(),0,0);
						if(rng.chance406c90(0x32)){
							MSG(0x1f6,&string("[name] %2 breaks down."),&ps->getName571db0(0,0),0,tgt,ZuHE(),0,0);
							ps->setBroken5795b0(-2,0);
						}
						((ZuEntityH*)tgt.operator->())->u45b210(0xfa);
						}
						break;
					case 0x3c:
						if(((ZuEntityH*)tgt.operator->())->u45ae30()&&((ZuEntityH*)tgt.operator->())->u45ae50()->u458950(0x3c)){
							if(weapon->ff4!=1)
								MSG(0x1fd,&string("Found active overload routine."),0,0,tgt,ZuHE(),0,0);
							goto hackDone;
						}else{
							ZuHI ps;
							ZuVecHI items;
							((ZuEntityH*)tgt.operator->())->u5cb930(&items);
							for(unsigned i=0;i<items.size9b9260();i++){
								if(items.at9b81f0(i)->u4578a0()==0&&items.at9b81f0(i)->def9b4350()->f1a8!=0){
									ps=items.at9b81f0(i);
									goto overload;
								}
							}
							if(weapon->ff4!=1)
								MSG(0x1fd,&string("Unable to locate active power source."),0,0,tgt,ZuHE(),0,0);
							goto hackDone;
						overload:
							int aA=zu_d22268.random40c130();
							a7=((ZuEntityH*)tgt.operator->())->u45ae50()->u57f140(new ZuStatus(0x3c));
							a7->f4=((ZuMapH*)zu_cefc4c)->getTurn464270()+aA;
							a7->f18=attacker.id;
							string msg5="Initiated overload sequence, T-"+zu_intToString4051f0(aA)+" to critical power.";
							MSG(0x1fc,&msg5,0,0,tgt,ZuHE(),0,0);
						}
						break;
					case 0x3d:
						if(((ZuEntityH*)tgt.operator->())->u45ae30()&&((ZuEntityH*)tgt.operator->())->u45ae50()->u458950(0x3d)){
							if(weapon->ff4!=1)
								MSG(0x1fd,&string("Found active resonance routine."),0,0,tgt,ZuHE(),0,0);
							goto hackDone;
						}else{
							ZuHI ps;
							ZuVecHI items;
							((ZuEntityH*)tgt.operator->())->u5cb930(&items);
							for(unsigned i=0;i<items.size9b9260();i++){
								if(items.at9b81f0(i)->u4578a0()==0&&items.at9b81f0(i)->def9b4350()->f1a8!=0){
									ps=items.at9b81f0(i);
									goto resonance;
								}
							}
							if(weapon->ff4!=1)
								MSG(0x1fd,&string("Unable to locate active power source."),0,0,tgt,ZuHE(),0,0);
							goto hackDone;
						resonance:
							a7=((ZuEntityH*)tgt.operator->())->u45ae50()->u57f140(new ZuStatus(0x3d));
							a7->f18=attacker.id;
							string msg9("Amplifying resonance, compromised power stability.");
							MSG(0x1fc,&msg9,0,0,tgt,ZuHE(),0,0);
						}
						break;
					case 0x3e:
						MSG(0x1fc,&string("Installed hostile record filter."),0,0,tgt,ZuHE(),0,0);
						if(((ZuEntityH*)tgt.operator->())->getAI45b590()->u5b3890(zu_cefc4c->getPlayer4630f0(),0))
							MSG(0x1fc,&string("Deleted hostile record."),0,0,tgt,ZuHE(),0,0);
						a7=((ZuEntityH*)tgt.operator->())->getAI45b590()->u4590f0()->u57f140(new ZuStatus(0x3e));
						a7->f4=((ZuMapH*)zu_cefc4c)->getTurn464270()+10;
						break;
					case 0x3f:{
						ZuVecHI w;
						((ZuEntityH*)tgt.operator->())->u5cb930(&w);
						for(unsigned i=0;i<w.size9b9260();i++)
							if(w.at9b81f0(i)->u4578a0()!=3)zu_eraseStep9d6440(w,i);
						if(w.empty9b86e0()){
							if(weapon->ff4!=1)
								MSG(0x1fd,&string("Unable to locate active weapons."),0,0,tgt,ZuHE(),0,0);
							goto hackDone;
						}
						string msg="Deactivating "+zu_countString407a80(w.size9b9260(),"weapon system")+".";
						MSG(0x1fc,&msg,0,0,tgt,ZuHE(),0,0);
						for(unsigned k=0;k<w.size9b9260();k++){
							w.at9b81f0(k)->setActive5791a0(0);
							w.at9b81f0(k)->setActivateOkayTurn4583b0(((ZuMapH*)zu_cefc4c)->getTurn464270()+0x14);
						}
						}
						break;
					case 0x40:{
						int dur=zu_d305d8.random40c130();
						string msg="Initiating full reboot, ETC: "+zu_intToString4051f0(dur)+".";
						MSG(0x1fc,&msg,0,0,tgt,ZuHE(),0,0);
						if(((ZuEntityH*)zu_cefc4c->getPlayer4630f0().operator->())->isHostileTo45aa70(tgt))zu_cf45d8.u77fbc0(0x6a);
						zu_sound4541b0(0x6a,0,0);
						((ZuEntityH*)tgt.operator->())->u5fd900(1,dur);
						}
						break;
					case 0x41:
						MSG(0x1fc,&string("Shutting down primary systems."),0,0,tgt,ZuHE(),0,0);
						((ZuEntityH*)tgt.operator->())->getAI45b590()->u5b5220();
						((ZuEntityH*)tgt.operator->())->u5fd900(2,0);
						zu_sound454260(tgt->getPosition45a4a0(),0x136);
						break;
					case 0x44:
						if(zu_distance40a3f0(((ZuEntityH*)tgt.operator->())->u45a4c0(),zu_cefc4c->getPlayer4630f0()->getPosition45a4a0())>5){
							string msg="System outside max range to establish control ("+zu_intToString4051f0(5)+").";
							MSG(0x1fd,&msg,0,0,tgt,ZuHE(),0,0);
							goto hackDone;
						}
					case 0x42:case 0x46:{
						int oldFaction=((ZuHG2&)((ZuEntityH*)tgt.operator->())->getGroup45a3f0())->get9b4350();
						tgt->u5fdab0();
						((ZuEntityH*)tgt.operator->())->removeEffects639730(0);
						((ZuEntityX*)tgt.operator->())->changeFaction5dc780(zu_cefc4c->u463890(attacker->isPlayer5c7600()?(aI==0x42)+1:(attacker->u45aaa0(zu_cefc4c->getPlayer4630f0())?2:((ZuHG2&)((ZuEntityH*)attacker.operator->())->getGroup45a3f0())->get9b4350())),1);
						if(((ZuMapH*)zu_cefc4c)->u4631f0(tgt))zu_sound4541b0(0x6b,0,0);
						switch(aI){
						case 0x42:
							MSG(0x1fc,&string("Rewriting IFF filter."),0,0,tgt,ZuHE(),0,0);
							a7=((ZuEntityH*)tgt.operator->())->getAI45b590()->u4590f0()->u57f140(new ZuStatus(0x42));
							a7->f4=((ZuMapH*)zu_cefc4c)->getTurn464270()+10;
							a7->v8.push_back9b3020(ZuPos(oldFaction));
							break;
						case 0x44:
							MSG(0x1fc,&string("Hijacking control node."),0,0,tgt,ZuHE(),0,0);
							a7=((ZuEntityH*)tgt.operator->())->getAI45b590()->u4590f0()->u57f140(new ZuStatus(0x44));
							a7->v8.push_back9b3020(ZuPos(oldFaction));
							((ZuEntityH*)tgt.operator->())->getAI45b590()->setFollow5b2f80(zu_cefc4c->getPlayer4630f0(),0);
							break;
						case 0x46:{
							MSG(0x1fc,&string("Rerouting network defenses."),0,0,tgt,ZuHE(),0,0);
							MSG(0x1fc,&string("Erasing system data."),0,0,tgt,ZuHE(),0,0);
							string msg="Installing primary routines, ETC: "+zu_intToString4051f0(6)+".";
							MSG(0x1fc,&msg,0,0,tgt,ZuHE(),0,0);
							((ZuEntityH*)tgt.operator->())->u5fd900(1,6);
							}
							break;
						}
						}
						break;
					case 0:
						if(u45ac40(0x13)||data->f28==0){
							if(weapon->ff4!=3)
								MSG(0x1fd,&string("System resists sunder attempts."),0,0,tgt,ZuHE(),0,0);
							goto hackDone;
						}
						MSG(aa||u45aaa0(zu_cefc4c->getPlayer4630f0())?0xba:0xbb,0,0,0,tgt,ZuHE(),0,0);
						if(attacker.operator->()&&attacker->isPlayer5c7600())
							zu_d2c658.add4729d0(0x208,items134.size9b9260(),string(""),-1);
						u6335e0();
						die633790(b7,0xa,attacker,1,0,0,0,0);
						return;
					case 1:{
						if(u45ac40(0x13)){
							if(weapon->ff4!=3)
								MSG(0x1fd,&string("System resists disarm attempts."),0,0,tgt,ZuHE(),0,0);
							goto hackDone;
						}
						ZuVecHI w;
						if(!fc0){
							((ZuEntityH*)tgt.operator->())->u5cb930(&w);
							for(unsigned i=0;i<w.size9b9260();i++)
								if(w.at9b81f0(i)->u4578a0()!=3||!zu_b9651c[((ZuItemDef2*)w.at9b81f0(i)->def9b4350())->f70]||w.at9b81f0(i)->getEffect457b70(0x6d))
									zu_eraseStep9d6440(w,i);
						}
						if(w.empty9b86e0()){
							if(weapon->ff4!=3)
								MSG(0x1fd,&string("Unable to locate transposition target."),0,0,tgt,ZuHE(),0,0);
							goto hackDone;
						}
						zu_shuffle9d9fc0(w);
						string name=w.front9b7060()->getName571db0(0,0);
						if(((ZuMapH*)zu_cefc4c)->u4631f0(self)){
							string msg=aa?name+" transposed to ground.":name416f40()+" "+name+" transposed to ground.";
							MSG(0x320,&msg,0,0,ZuHE(),ZuHE(),0,0);
							u5e5340(0,aa,4,1,0x1f,"-"+name);
						}
						u642940(w.front9b7060(),aa,1,0,2);
						}
						break;
					case 2:case 3:{
						ZuHE src=aI==3?attacker:tgt;
						ZuPos posRef=src->getPosition45a4a0();
						ZuHE aD=aI==3?tgt:attacker;
						int level6=zu_d1e860.getDepthIndex();
						ZuRec*best=0;
						for(unsigned i=0;i<zu_cfd2cc.size9b9260();i++)
							if(zu_cfd2cc.at9b81f0(i)->f4c!=0&&(best==0||zu_cfd2cc.at9b81f0(i)->f28<=level6))
								best=zu_cfd2cc.at9b81f0(i);
						if(!best)goto hackDone;
						if(((ZuMapH*)zu_cefc4c)->u4631f0(src)){
							string msg=src->isPlayer5c7600()?string("A concussive blast radiates outward."):"A concussive blast radiates from "+src->name416f40()+".";
							MSG(0x320,&msg,0,0,ZuHE(),ZuHE(),0,0);
						}
						((ZuMapH*)zu_cefc4c)->addRecord777a20(zu_cefaa8->createA7930e0(new ZuEvent(aD,best,posRef,ZuHE(),ZuPos(-1),ZuPos(-1))));
						}
						break;
					case 4:case 5:case 6:{
						if(getSize45a360()>1){
							if(weapon->ff4!=3)
								MSG(0x1fd,&string("System size prevents spacial translocation."),0,0,tgt,ZuHE(),0,0);
							goto hackDone;
						}
						bool far5=aI==5;
						ZuRange2 nRange;
						switch(aI){
						case 4:nRange.set40a010(5,10);break;
						case 5:nRange.set40a010(0x32,0x4b);break;
						case 6:nRange.set40a010(0x4b,0x64);break;
						}
						ZuHE b0=tgt;
						if(aI==6)((ZuMapH*)zu_cefc4c)->u464a00(new ZuTimer(b0,b0->getPosition45a4a0(),rng.rangeInt406d70(12.0f,30.0f)));
						ZuPos cd=b0->getPosition45a4a0();
						bool ok=zu_d25450.placeEntityNear6bd410(&nRange,0,b0,aI==5,1);
						if(ok){
							if(((ZuMapH*)zu_cefc4c)->isVisible4631c0(cd)){
								string msg1=b0->isPlayer5c7600()?string("Form shifts and blurs."):b0->name416f40()+" form shifts and blurs.";
								MSG(weapon->ff4==3?0x320:0x1fc,&msg1,0,0,zu_cefc4c->getPlayer4630f0(),ZuHE(),0,0);
								int fx;
								if(zu_lookup9d7980("Xom_Disappear",&fx))zu_cefc50->new508610(zu_cefc50)->init503b20(fx,cd,&zu_d2e20c,0,0,0,9,0);
							}
							if(((ZuMapH*)zu_cefc4c)->u4631f0(b0)){
								string msgA=b0->isPlayer5c7600()?string("Form resolidifies at new position."):b0->name416f40()+" form resolidifies at new position.";
								MSG(0x320,&msgA,0,0,ZuHE(),ZuHE(),0,0);
								int fx;
								if(zu_lookup9d7980("Xom_Appear",&fx))zu_cefc50->new508610(zu_cefc50)->init503b20(fx,b0->getPosition45a4a0(),&zu_d2e20c,0,0,0,9,0);
							}
						}
						}
						break;
					case 7:case 8:{
						if(!attacker.operator->())goto hackDone;
						if(((ZuEntityH*)attacker.operator->())->getSize45a360()>1&&weapon->ff4!=3){
							MSG(0x1fd,&string("System size prevents spacial translocation."),0,0,tgt,ZuHE(),0,0);
							goto hackDone;
						}
						ZuPos centerC=attacker->getPosition45a4a0();
						ZuPos dist(10,0x14);
						bool aB=aI==8;
						ZuPos dest;
						ZuArea area;
						zu_cfd44c.getRect9b4430(centerC,dist.y,&area);
						for(int tries=300;tries>0;tries--){
							dest=area.randomPoint40be90();
							if((*zu_cfd44c.atPoint9ced70(dest))->canPlace66ad20(1)&&dist.contains40c190(zu_distance40a3f0(centerC,ZuPos(dest)))&&
								(!aB||!((ZuMapH*)zu_cefc4c)->isReachable465230(0x10,tgt->getPosition45a4a0(),dest)))
								goto found78;
						}
						if(weapon->ff4!=3)
							MSG(0x1fd,&string("System translocation search failed."),0,0,tgt,ZuHE(),0,0);
						goto hackDone;
					found78:
						ZuHE b5=attacker;
						centerC=b5->getPosition45a4a0();
						bool ok=zu_d25450.placeEntityNear6bd410(0,&dest,b5,0,1);
						if(ok){
							if(((ZuMapH*)zu_cefc4c)->isVisible4631c0(centerC)){
								string myMsg=b5->isPlayer5c7600()?string("Form shifts and blurs."):b5->name416f40()+" form shifts and blurs.";
								MSG(weapon->ff4==3?0x320:0x1fc,&myMsg,0,0,zu_cefc4c->getPlayer4630f0(),ZuHE(),0,0);
								int fx;
								if(zu_lookup9d7980("Xom_Disappear",&fx))zu_cefc50->new508610(zu_cefc50)->init503b20(fx,centerC,&zu_d2e20c,0,0,0,9,0);
							}
							if(((ZuMapH*)zu_cefc4c)->u4631f0(b5)){
								string ct=b5->isPlayer5c7600()?string("Form resolidifies at new position."):b5->name416f40()+" form resolidifies at new position.";
								MSG(0x320,&ct,0,0,ZuHE(),ZuHE(),0,0);
								int fx;
								if(zu_lookup9d7980("Xom_Appear",&fx))zu_cefc50->new508610(zu_cefc50)->init503b20(fx,b5->getPosition45a4a0(),&zu_d2e20c,0,0,0,9,0);
							}
						}
						}
						break;
					case 9:{
						if(((ZuEntityH*)tgt.operator->())->getSize45a360()>1&&weapon->ff4!=3){
							MSG(0x1fd,&string("System size prevents spacial transposition."),0,0,tgt,ZuHE(),0,0);
							goto hackDone;
						}
						ZuVecHE ents6;
						ZuArea area;
						int range=((ZuEntityH*)attacker.operator->())->u5c7d30();
						zu_cfd44c.getRect9b4430(tgt->getPosition45a4a0(),range,&area);
						for(int x=area.a;x<=area.c;x++)
							for(int y=area.b;y<=area.d;y++)
								if((*zu_cfd44c.at9ceda0(x,y))->getEntity45d250().isValid9b7230()&&((ZuEntityH*)(*zu_cfd44c.at9ceda0(x,y))->getEntity45d250().operator->())->getSize45a360()==1&&
									(*zu_cfd44c.at9ceda0(x,y))->getEntity45d250()!=attacker&&((ZuMapH*)zu_cefc4c)->isReachable465230(range,attacker->getPosition45a4a0(),ZuPos(x,y)))
									ents6.push_back9b7cf0((*zu_cfd44c.at9ceda0(x,y))->getEntity45d250());
						zu_shuffle9d9fc0(ents6);
						ents6.push_back9b80b0(attacker);
						ZuPos h1;
						for(unsigned i=0;i<ents6.size9b9260();i++)
							if(((ZuMapH*)zu_cefc4c)->findPlaceable71c150(ents6.at9b81f0(i)->getPosition45a4a0(),h1,1))
								goto found9;
						if(weapon->ff4!=3)
							MSG(0x1fd,&string("Transposition failed."),0,0,tgt,ZuHE(),0,0);
						goto hackDone;
					found9:
						ZuPos bN=ents6.front9b7060()->getPosition45a4a0();
						ZuPos cur;
						((ZuEntityH*)ents6.front9b7060().operator->())->changePos5dccb0(h1,1);
						zu_moveElement9da1f0(ents6,0,ents6.size9b9260()-1);
						for(unsigned j=0;j<ents6.size9b9260();j++){
							cur=ents6.at9b81f0(j)->getPosition45a4a0();
							((ZuEntityH*)ents6.at9b81f0(j).operator->())->u5ddac0(bN,0);
							bN=cur;
						}
						for(unsigned k=0;k<ents6.size9b9260();k++){
							if(((ZuMapH*)zu_cefc4c)->u4631f0(ents6.at9b81f0(k))){
								string e5=ents6.at9b81f0(k)->isPlayer5c7600()?string("Form resolidifies at new position."):ents6.at9b81f0(k)->name416f40()+" form resolidifies at new position.";
								MSG(0x320,&e5,0,0,ZuHE(),ZuHE(),0,0);
								int fx;
								if(zu_lookup9d7980("Xom_Appear",&fx))zu_cefc50->new508610(zu_cefc50)->init503b20(fx,ents6.at9b81f0(k)->getPosition45a4a0(),&zu_d2e20c,0,0,0,9,0);
							}
						}
						}
						break;
					case 10:{
						ZuVecI slots;
						((ZuEntityH*)attacker.operator->())->u5c93d0(&slots);
						if(!zu_anyPositive9d54c0(slots)||u45ac40(0x13)||fc0||zu_cf462c==2)goto pickHack;
						ZuVecI aP;
						for(int i=0;i<4;i++)aP.push_back9b9280(+i);
						zu_shuffle9d8f80(aP);
						ZuVecHI a9;
						for(unsigned j=0;j<aP.size9b9260();j++){
							if(slots.at9b81f0(aP.at9b81f0(j))!=0){
								ZuVecHI*inv=((ZuEntityH*)tgt.operator->())->getInventoryList45ab00();
								for(unsigned k=0;k<inv->size9b9260();k++)
									if(inv->at9b81f0(k)->u4578a0()==aP.at9b81f0(j)&&inv->at9b81f0(k)->getType44aec0()<=3&&inv->at9b81f0(k)->u4578c0()==1&&
										zu_b9651c[((ZuItemDef2*)inv->at9b81f0(k)->def9b4350())->f70]&&!inv->at9b81f0(k)->getEffect457b70(0x6d)&&!inv->at9b81f0(k)->getEffect457b70(0x6c)&&
										inv->at9b81f0(k)->u577fb0()==0)
										a9.push_back9b80b0(inv->at9b81f0(k));
								if(!a9.empty9b86e0())break;
							}
						}
						if(a9.empty9b86e0())goto pickHack;
						zu_shuffle9d9fc0(a9);
						for(unsigned m=0;m<a9.size9b9260();m++){
							if(attacker->isPlayer5c7600())zu_cf45d8.u77ffb0(a9.at9b81f0(m)->u457820(),0);
							if(a9.at9b81f0(m)->u57a190(attacker,a9.at9b81f0(m)->u4578a0(),1,0)){
								if(((ZuMapH*)zu_cefc4c)->u4631f0(attacker)){
									string en=a9.at9b81f0(m)->getName571db0(0,0)+" transposed from "+tgt->name416f40();
									en+=attacker->isPlayer5c7600()?string("."):" to "+attacker->name416f40()+".";
									MSG(0x320,&en,0,0,ZuHE(),ZuHE(),0,0);
									int fx;
									if(zu_lookup9d7980("Xom_Appear",&fx))zu_cefc50->new508610(zu_cefc50)->init503b20(fx,attacker->getPosition45a4a0(),&zu_d2e20c,0,0,0,9,0);
								}
								break;
							}
						}
						}
						break;
					}
					if(zu_d25450.enabled&&attacker->isPlayer5c7600()){
						switch(weapon->ff4){
						case 0:
							zu_d25450.u69e700(0x31,0,0.0f);
							break;
						case 1:
							break;
						case 2:case 3:
							zu_d25450.u69e700(0x32,0,0.0f);
							break;
						}
					}
				}else{
					if(attacker->isPlayer5c7600()&&weapon->ff4!=1)
						MSG(0x1fe,0,0,0,self,ZuHE(),0,0);
				}
			}
		hackDone:
			break;
		case 0x7d:
			if(u45ac40(0x16))
				MSG(u45aaa0(zu_cefc4c->getPlayer4630f0())?0x1e9:0x1ea,0,0,0,self,ZuHE(),0,0);
			else if(((ZuEntityH*)this)->getTarget45a760()>=6||u45ac40(0x39)||!rng.chance406c90(weapon->ff4))
				MSG(u45aaa0(zu_cefc4c->getPlayer4630f0())?0x1ec:0x1eb,0,0,0,self,ZuHE(),0,0);
			else if(attacker.operator->()){
				int gN=((ZuHG2&)((ZuEntityH*)attacker.operator->())->getGroup45a3f0())->get9b4350()<=2?1:((ZuHG2&)((ZuEntityH*)attacker.operator->())->getGroup45a3f0())->get9b4350();
				if(group28->get9b4350()!=gN){
					MSG(u45aaa0(zu_cefc4c->getPlayer4630f0())?0x1ee:0x1ed,0,0,0,self,ZuHE(),0,0);
					if(attacker->isPlayer5c7600())
						do{zu_logPhrase5141b0(0x64,&name416f40(),&((ZuItemDef3*)weapon)->s174,0,ZuHE(),0);}while(0);
					else
						do{zu_logPhrase5141b0(0x65,&attacker->name416f40(),&name416f40(),&((ZuItemDef3*)weapon)->s174,ZuHE(),0);}while(0);
					((ZuEntityH*)this)->removeEffects639730(0);
					((ZuMapH*)zu_cefc4c)->u730f40(self);
					((ZuEntityX*)this)->changeFaction5dc780(zu_cefc4c->u463890(gN),1);
					u5fdab0();
					if(((ZuMapH*)zu_cefc4c)->u4631f0(self))zu_sound4541b0(0x6b,0,0);
					if(attacker->isPlayer5c7600())zu_d2c658.add4729d0(0x3b5,1,string(""),-1);
				}else
					MSG(u45aaa0(zu_cefc4c->getPlayer4630f0())?0x1ec:0x1eb,0,0,0,self,ZuHE(),0,0);
			}
			return;
		case 0x73:
			f50=0;
			if(attacker.operator->()){
				((ZuMapH*)zu_cefc4c)->u464e10(new ZuAtk(attacker,self));
				MSG(aa?0x29:u45aaa0(zu_cefc4c->getPlayer4630f0())?0x2a:0x2b,&weapon->name,0,0,self,ZuHE(),0,0);
				if(aa&&attacker.operator->()&&((ZuHG2&)((ZuEntityH*)attacker.operator->())->getGroup45a3f0())->get9b4350()==3&&
					((ZuEntityH*)attacker.operator->())->getFaction45a2c0()==0x14&&zu_cf6428.u68fc40()){
					MSG(0x2c,&weapon->name,0,0,attacker,ZuHE(),0,0);
					bool gi=false;
					if(zu_d1e888->f4==0x20&&zu_stringToInt405610(zu_d1e860.getEntryText46f6d0("secScannedCogmind_g"))==0){
						zu_d1e860.setEntryText46f700("secScannedCogmind_g","1");
						zu_d1e860.setEntryText46f700("resScannedCogmind_g","1");
						do{
							zu_cf1080.set451400(1);
							if(0)zu_sound4541b0(-1,0,0);
							MSG(0x324,&string("ALERT: Modified LRC-V3 signature confirmed."),0,0,ZuHE(),ZuHE(),0,0);
							zu_cec0b4->scrollToEnd7b4f10();
						}while(0);
						zu_d2c658.add472b90(0x46,-999999);
						zu_cf45d8.u77fbc0(0x19b);
						gi=true;
						if(zu_d25450.enabled)zu_d25450.u69e700(0x56,0,0.0f);
					}else if(zu_stringToInt405610(zu_d1e860.getEntryText46f6d0("resScannedCogmind_g"))==0){
						zu_d1e860.setEntryText46f700("resScannedCogmind_g","1");
						do{
							zu_cf1080.set451400(1);
							if(0)zu_sound4541b0(-1,0,0);
							MSG(0x324,&string("ALERT: Encountered unknown unique technology, formulating response."),0,0,ZuHE(),ZuHE(),0,0);
							zu_cec0b4->scrollToEnd7b4f10();
						}while(0);
						zu_d2c658.add472b90(0x46,-999999);
						gi=true;
						if(zu_d25450.enabled)zu_d25450.u69e700(0x55,0,0.0f);
					}
					if(gi)
						do{zu_logPhrase5141b0(0x7a,0,0,0,ZuHE(),0);}while(0);
				}
			}
			return;
		case 0x75:
			f50=0;
			fbc=0xc8;
			MSG(aa?0x2d:u45aaa0(zu_cefc4c->getPlayer4630f0())?0x2e:0x2f,&weapon->name,0,0,self,ZuHE(),0,0);
			zu_sound4542a0(getPosition45a4a0(),0xc6,0x15);
			break;
		case 0xca:{
			ZuHE i8=self;
			if(u45a340()<=2&&f8c<=0x32&&data->f28!=0&&rng.chance406c90(0x14)){
				if(((ZuMapH*)zu_cefc4c)->u4631f0(self)){
					string msg=name416f40()+" slowly implodes.";
					MSG(0x320,&msg,0,0,ZuHE(),ZuHE(),0,0);
				}
				fb4-=0x14;
				die633790(b7,0xa,attacker,1,0,0,0,1);
				return;
			}
			if(u45a340()<=3&&getSize45a360()==1&&attacker.operator->()&&!u5c8820(attacker)){
				int j4=0xf;
				if(attacker==zu_cf68b8){
					if(((ZuEntityH*)zu_cf68b8.operator->())->getAI45b590()->get9b8f00()==0x17)
						j4=0;
					else{
						int k5=u5d15a0(0);
						int aN=zu_cf68b8->u5d15a0(0);
						if(k5<aN)j4=j4*((double)aN/k5);
					}
				}
				if(j4!=0&&rng.chance406c90(j4)){
					ZuPos myPos=getPosition45a4a0();
					ZuPos dir=attacker->u5c80f0(myPos);
					ZuVecPt line;
					ZuVecI lo;
					zu_trace4106d0(myPos,dir,line,lo,9);
					for(int i=1;i<(int)line.size9b9a50()-1;i++)
						if((*zu_cfd44c.atPoint9ced70(line.at9e7c10(i)))->u45d480()||(*zu_cfd44c.atPoint9ced70(line.at9e7c10(i)))->getEntity45d250().isValid9b7230())
							goto pushArea;
					if(1){
						ZuPulled*nG=new ZuPulled(2,myPos);
						((char*)nG)[0x1e]=1;
						if(b7){
							((ZuMapH*)zu_cefc4c)->setA74_4654d0(1);
							((ZuMapH*)zu_cefc4c)->impact749ee0(attacker,nG,dir,1);
							delete nG;
							((ZuMapH*)zu_cefc4c)->setA74_4654d0(0);
						}else{
							int fx;
							if(zu_lookup9d7980("Forcegen_Object_"+zu_intToString4051f0(2),&fx))
								zu_cefc50->new508610(zu_cefc50)->init503b20(fx,myPos,&zu_d2e20c,&dir,&zu_d2e20c,new ZuEffParams(0,attacker,0,0x270f,0.0f,ZuHE(),ZuHE(),0,ZuHE(),0,0,nG),9,0);
						}
						zu_d225a0.u6728c0(attacker);
						if(attacker==zu_cf68b8)zu_cf6954=((ZuMapH*)zu_cefc4c)->getTurn464270();
						return;
					}
				}
			}
		pushArea:
			ZuPos centerVal=((ZuEntityH*)this)->u45a4c0();
			ZuArea area;
			zu_cfd44c.getRect9b4430(centerVal,1,&area);
			ZuVecPt aK;
			ZuVecPt spots4;
			ZuVecI kinds;
			ZuVecPt path;
			bool a_=false;
			if(attacker==zu_cf68b8&&attacker.operator->()){
				ZuVecPt fp;
				attacker->u5c89d0(&fp);
				for(unsigned i=0;i<fp.size9b9a50();i++)
					if((*zu_cfd44c.atPoint9ced70(fp.at9e7c10(i)))->getProp45d550().isValid9b7230()&&(*zu_cfd44c.atPoint9ced70(fp.at9e7c10(i)))->getProp45d550()->get9b8f00()->f8c!=0){
						a_=true;
						break;
					}
			}
			for(int r=0;r<0xf&&spots4.size9b9a50()<0xa;r++){
				aK.clear9b3560();
				area.getBorder40bac0(aK);
				zu_shuffle9d7350(aK);
				for(unsigned m=0;m<aK.size9b9a50();m++){
					if(!zu_cfd44c.contains9b43b0(aK.at9e7c10(m))||zu_distance40a3f0(centerVal,aK.at9e7c10(m))>0xf)continue;
					int kind=-1;
					if((*zu_cfd44c.atPoint9ced70(aK.at9e7c10(m)))->u45d4e0()&&(*zu_cfd44c.atPoint9ced70(aK.at9e7c10(m)))->getArmor66ae70()!=-1)
						kind=0;
					else if((*zu_cfd44c.atPoint9ced70(aK.at9e7c10(m)))->getProp45d550().isValid9b7230()&&(*zu_cfd44c.atPoint9ced70(aK.at9e7c10(m)))->u45d500()&&
						(*zu_cfd44c.atPoint9ced70(aK.at9e7c10(m)))->getProp45d550()->u45c630()!=-1&&(!a_||(*zu_cfd44c.atPoint9ced70(aK.at9e7c10(m)))->getProp45d550()->get9b8f00()->f8c==0))
						kind=1;
					else if((*zu_cfd44c.atPoint9ced70(aK.at9e7c10(m)))->getEntity45d250().isValid9b7230()&&((ZuEntityH*)(*zu_cfd44c.atPoint9ced70(aK.at9e7c10(m)))->getEntity45d250().operator->())->getSize45a360()==1&&
						(*zu_cfd44c.atPoint9ced70(aK.at9e7c10(m)))->getEntity45d250()!=attacker)
						kind=2;
					else if((*zu_cfd44c.atPoint9ced70(aK.at9e7c10(m)))->getItem45d8f0().isValid9b7230()&&((*zu_cfd44c.atPoint9ced70(aK.at9e7c10(m)))->getItem45d8f0()->u457b30()!=0||
						(*zu_cfd44c.atPoint9ced70(aK.at9e7c10(m)))->getItem45d8f0()->u4578a0()==1))
						kind=3;
					if(kind!=-1){
						ZuVecPt as;
						ZuVecI st;
						zu_trace4106d0(aK.at9e7c10(m),getPosition45a4a0(),as,st,9);
						for(int i=1;i<(int)as.size9b9a50()-1;i++)
							if((*zu_cfd44c.atPoint9ced70(as.at9e7c10(i)))->u45d480()||((*zu_cfd44c.atPoint9ced70(as.at9e7c10(i)))->getEntity45d250().isValid9b7230()&&
								(*zu_cfd44c.atPoint9ced70(as.at9e7c10(i)))->getEntity45d250()!=self)||(kind==2&&zu_inVector9d0ce0(path,as.at9e7c10(i))))
								goto skipAdd;
						spots4.push_back9b32e0(aK.at9e7c10(m));
						kinds.push_back9b9d30(kind);
						zu_appendRange9d9890(as,path,1,as.size9b9a50()-2);
					skipAdd:;
					}
				}
				area.grow40bc10(1);
			}
			if(spots4.empty9b86e0()){
				if(attacker.operator->())
					MSG(0xe5,0,0,0,attacker,ZuHE(),0,0);
			}else{
				ZuVecI idx;
				zu_fillIndices9d98e0(spots4,idx);
				zu_shuffle9d8f80(idx);
				ZuVecPt dirs;
				for(unsigned i=0;i<spots4.size9b9a50();i++)dirs.push_back9b3020(u5c80f0(spots4.at9e7c10(i)));
				int m5=attacker==zu_cf68b8?5:3;
				int fxs[4];
				for(int j=0;j<4;j++)zu_lookup9d7980("Forcegen_Object_"+zu_intToString4051f0(j),&fxs[j]);
				int count=0;
				for(unsigned k=0;k<idx.size9b9260()&&count<m5;k++){
					int newKind=kinds.at9b81f0(idx.at9b81f0(k));
					ZuPos p=spots4.at9e7c10(idx.at9b81f0(k));
					ZuPos d=dirs.at9e7c10(idx.at9b81f0(k));
					switch(newKind){
					case 0:
						if(!(*zu_cfd44c.atPoint9ced70(p))->u45d4e0())continue;
						break;
					case 1:
						if((*zu_cfd44c.atPoint9ced70(p))->getProp45d550().isNull9b65d0()||!(*zu_cfd44c.atPoint9ced70(p))->u45d500())continue;
						break;
					case 2:
						if((*zu_cfd44c.atPoint9ced70(p))->getEntity45d250().isNull9b65d0()||((ZuEntityH*)(*zu_cfd44c.atPoint9ced70(p))->getEntity45d250().operator->())->getSize45a360()!=1||
							(*zu_cfd44c.atPoint9ced70(p))->getEntity45d250()==attacker)continue;
						break;
					case 3:
						if((*zu_cfd44c.atPoint9ced70(p))->getItem45d8f0().isNull9b65d0())continue;
					}
					count++;
					ZuPulled*b8=new ZuPulled(newKind,p);
					switch(newKind){
					case 0:
						(*zu_cfd44c.atPoint9ced70(p))->u45e110(0,0,attacker);
						break;
					case 1:
						(*zu_cfd44c.atPoint9ced70(p))->getProp45d550()->u45ce10(0,0,0,attacker);
						break;
					case 2:
						break;
					case 3:
						(*zu_cfd44c.atPoint9ced70(p))->getItem45d8f0()->u57dbe0(0,0,1,1);
					}
					if(aa&&zu_cf68b4!=0&&attacker.operator->()&&zu_cf68b8==attacker)
						zu_cf68f0->u672f20(attacker,8,0,string(""));
					if(b7){
						((ZuMapH*)zu_cefc4c)->setA74_4654d0(1);
						((ZuMapH*)zu_cefc4c)->impact749ee0(attacker,b8,d,1);
						delete b8;
						((ZuMapH*)zu_cefc4c)->setA74_4654d0(0);
					}else
						zu_cefc50->new508610(zu_cefc50)->init503b20(fxs[newKind],p,&zu_d2e20c,&d,&zu_d2e20c,new ZuEffParams(0,attacker,0,0x270f,0.0f,ZuHE(),ZuHE(),0,ZuHE(),0,0,b8),9,0);
				}
			}
			if(!i8.operator->())return;
			}
			break;
		}
	}else{
		switch(expl->f78){
		case 0x75:
			f50=0;
			fbc=0xc8;
			MSG(aa?0x2d:u45aaa0(zu_cefc4c->getPlayer4630f0())?0x2e:0x2f,&weapon->name,0,0,self,ZuHE(),0,0);
			zu_sound4542a0(getPosition45a4a0(),0xc6,0x15);
		}
	}
	if(weapon&&((ZuItemDefH*)weapon)->get457330(0x3f)){
		if(attacker.operator->()&&!u45ac40(0x13)){
			ZuHI src;
			ZuVecHI*inv=((ZuEntityH*)attacker.operator->())->getInventoryList45ab00();
			for(unsigned i=0;i<inv->size9b9260();i++)
				if(inv->at9b81f0(i)->def9b4350()==weapon&&inv->at9b81f0(i)->u457cf0()){
					src=inv->at9b81f0(i);
					break;
				}
			if(src.operator->()){
				ZuHI part;
				if(attacker->isPlayer5c7600()){
					ZuVecCP*parts=zu_cec088->getParts4a9ad0();
					for(unsigned j=0;j<parts->size9b9260();j++)
						if(parts->at9b81f0(j)->getItem4aeed0().isValid9b7230()&&parts->at9b81f0(j)->getItem4aeed0()->u457cf0()&&parts->at9b81f0(j)->getItem4aeed0()->u4578a0()==0){
							part=parts->at9b81f0(j)->getItem4aeed0();
							break;
						}
				}else{
					for(unsigned k=0;k<inv->size9b9260();k++)
						if(inv->at9b81f0(k)->u4578a0()==0&&inv->at9b81f0(k)->u457cf0()){
							part=inv->at9b81f0(k);
							break;
						}
				}
				if(part.operator->()){
					if(attacker->isPlayer5c7600())
						MSG(0x46,&part->getName571db0(0,0),0,0,attacker,ZuHE(),0,0);
					part->u57dbe0(1,1,1,1);
					int n=rng.rangeInt406d70(2.0f,4.0f);
					ZuVecI nW;
					nW.push_back9b9280(7);
					for(int t=0;t<n;t++){
						ZuHI it=u5e3cb0(0,-1,&nW,1,1);
						if(it.isNull9b65d0())break;
						if(((ZuItemDef2*)it->def9b4350())->f70<=1)continue;
						if(!b7){
							int fx;
							zu_lookup9d7980("Part_Sabotaged",&fx);
							if(fx!=0)zu_cefc50->new508610(zu_cefc50)->init503b20(fx,((ZuEntityH*)this)->u45a4c0(),&zu_d2e20c,0,0,0,9,0);
						}
						MSG(aa?0x47:u45aaa0(zu_cefc4c->getPlayer4630f0())?0x48:0x49,&it->getName571db0(0,0),0,0,self,ZuHE(),&((ZuEntityH*)this)->u45a4c0(),0);
						if(aa)zu_d2c658.add4729d0(0x206,1,string(""),-1);
						if(it->u457e90()||fc0){
							MSG(0x45,&it->getName571db0(0,0),0,0,self,ZuHE(),&((ZuEntityH*)this)->u45a4c0(),0);
							it->u57dbe0(aa,1,1,1);
						}else{
							it->u458310(rng.rangeInt406d70(it->get9b6bf0()/6,it->get9b6bf0()/2));
							if(zu_cf462c!=2||aa)u642940(it,aa,1,0,2);
						}
					}
					((ZuEntityH*)attacker.operator->())->takeDamage5e5520(7,weapon,0,src->def9b4350()->f120.random40c130(),src->def9b4350()->f128,0,0,b7,ZuHE(),1,8,0,0,0);
				}
			}
		}
		return;
	}
	if(weapon&&((ZuItemDefH*)weapon)->get457330(0x7b)){
		if(attacker.operator->()){
			int ns=1;
			if(group28->get9b4350()!=ns){
				MSG(0x1ef,&weapon->name,0,0,attacker,self,0,0);
				do{zu_logPhrase5141b0(0x67,&attacker->name416f40(),&name416f40(),0,self,0);}while(0);
				u45b340(new ZuEff(zu_d2f0f8.at9b81f0(0x7b),((ZuItemDefH*)weapon)->get457330(0x7b)));
				((ZuEntityH*)this)->removeEffects639730(0);
				((ZuMapH*)zu_cefc4c)->u730f40(self);
				((ZuEntityX*)this)->changeFaction5dc780(zu_cefc4c->u463890(ns),1);
				u5fdab0();
				((ZuMapH*)zu_cefc4c)->u6c65a0(self,"Master_Drone_Early_Exit",0);
				((ZuEntityH*)attacker.operator->())->u637bb0();
			}else
				zu_logError404f10("Entity::projectileImpact()","dominating ally?");
		}
		return;
	}
	if(weapon&&((ZuItemDefH*)weapon)->get457330(0x40)&&!u45ac40(0x13)&&attacker.operator->()&&
		rng.chance406c90(((ZuItemDefH*)weapon)->get457330(0x40)+(((ZuEntityH*)attacker.operator->())->getFaction45a2c0()==0x3a?0x1e:0))&&!items134.empty9b86e0()){
		ZuHI pK;
		if(((ZuEntityH*)attacker.operator->())->getName45a280()=="Thief_7"){
			ZuVecHI cands;
			for(unsigned i=0;i<items134.size9b9260();i++)
				if(((ZuItemDef2*)items134.at9b81f0(i)->def9b4350())->f70!=0&&items134.at9b81f0(i)->u457880()!=1&&!items134.at9b81f0(i)->getEffect457b70(0x6c))
					cands.push_back9b80b0(items134.at9b81f0(i));
			if(!cands.empty9b86e0()){
				ZuVecHI pd;
				for(unsigned j=0;j<items134.size9b9260();j++)
					if(items134.at9b81f0(j)->getEffect457b70(0x63))pd.push_back9b80b0(items134.at9b81f0(j));
				if(!pd.empty9b86e0())
					pK=zu_randomItem9dafb0(pd);
				else if(rng.chance406c90(0xf))
					pK=zu_randomItem9dafb0(cands);
				else{
					pK=cands.at9b81f0(0);
					for(unsigned k=1;k<cands.size9b9260();k++)
						if(cands.at9b81f0(k)->u457900()>pK->u457900())pK=cands.at9b81f0(k);
				}
			}
		}else{
			ZuVecI ex;
			ex.push_back9b9280(7);
			pK=u5e3cb0(1,-1,&ex,1,1);
			if(pK.isValid9b7230()&&(((ZuItemDef2*)pK->def9b4350())->f70<=1||pK->getEffect457b70(0x6c)))pK.reset9b7270();
		}
		if(pK.isValid9b7230()){
			bool q3=pK->getType44aec0()==4;
			if(q3)
				MSG(aa?0x4d:u45aaa0(zu_cefc4c->getPlayer4630f0())?0x4e:0x4f,&pK->getName571db0(0,0),0,0,self,ZuHE(),&((ZuEntityH*)this)->u45a4c0(),0);
			else
				MSG(aa?0x4a:u45aaa0(zu_cefc4c->getPlayer4630f0())?0x4b:0x4c,&pK->getName571db0(0,0),0,0,self,ZuHE(),&((ZuEntityH*)this)->u45a4c0(),0);
			if(aa)zu_d2c658.add4729d0(0x207,1,string(""),-1);
			if(!q3&&(pK->def9b4350()->b1ac||pK->getEffect457b70(0x6e)||pK->u457e90()||fc0))
				pK->u57dbe0(1,1,1,1);
			else{
				pK->set450460(zu_maxInt9cdb60(1,pK->get9b6bf0()*0x5a/100));
				if(zu_cf462c!=2||aa){
					if(attacker.operator->()&&((ZuEntityH*)attacker.operator->())->u45a810()>=pK->u4578c0()&&
						!(aa&&zu_cf4730!=0&&(pK->u457fb0()==7||pK->u457fb0()==0x8f))&&
						!(zu_cf462c==9&&pK->u4578a0()==3&&pK->def9b4350()->f1a0!=0)){
						if(aa&&zu_cec088->u894e70(pK))zu_cec088->u894e70(pK)->set450570(2);
						pK->u57a190(attacker,4,aa||attacker->isPlayer5c7600(),0);
						if(aa&&attacker.operator->()&&((ZuEntityH*)attacker.operator->())->getName45a280()=="Thief_7")
							do{zu_logPhrase5141b0(0x135,&pK->getName571db0(0,0),0,0,ZuHE(),0);}while(0);
						if(aa&&pK->u457f90()==0xd6&&zu_cf45d8.hasCompanion780790())
							zu_cf4ac8->f30->spawn7aa280(0x26,0,string(""));
					}else
						u642940(pK,aa||attacker->isPlayer5c7600(),1,0,2);
				}
				if(!b7){
					int fx;
					zu_lookup9d7980("Part_Sabotaged",&fx);
					if(fx!=0)zu_cefc50->new508610(zu_cefc50)->init503b20(fx,((ZuEntityH*)this)->u45a4c0(),&zu_d2e20c,0,0,0,9,0);
				}
			}
			return;
		}
	}
	if(weapon&&((ZuItemDefH*)weapon)->get457330(0x42)){
		zu_sound454260(getPosition45a4a0(),0xa1);
		int dist=zu_distance40a3f0(getPosition45a4a0(),zu_cefc4c->getPlayer4630f0()->getPosition45a4a0());
		if(dist<=10)zu_d2f1c8.shake4b38f0((0xb-dist)*0x32,0);
		if(!items134.empty9b86e0()){
			int n=rng.rangeInt406d70(2.0f,3.0f);
			int destroyed=0;
			int dropped5=0;
			for(int i=0;i<n;i++){
				ZuHI it=u5e3cb0(0,-1,0,1,1);
				if(it.isNull9b65d0())break;
				if(((ZuItemDef2*)it->def9b4350())->f70>1){
					MSG(aa?0xb2:u45aaa0(zu_cefc4c->getPlayer4630f0())?0xb3:0xb4,&it->getName571db0(0,0),0,0,self,ZuHE(),&((ZuEntityH*)this)->u45a4c0(),0);
					if(i==0){
						it->u57dbe0(aa,1,1,1);
						destroyed++;
					}else if(it->u457e90()||fc0){
						MSG(0x45,&it->getName571db0(0,0),0,0,self,ZuHE(),&((ZuEntityH*)this)->u45a4c0(),0);
						it->u57dbe0(aa,1,1,1);
						destroyed++;
					}else{
						it->set450460(zu_maxInt9cdb60(1,it->get9b6bf0()/2));
						if(zu_cf462c!=2||aa){
							u642940(it,aa||attacker->isPlayer5c7600(),1,0,2);
							dropped5++;
						}
					}
				}
			}
			if(destroyed!=0||dropped5!=0){
				if(aa){
					string msg=zu_countString407a80(destroyed,"part")+" destroyed";
					if(dropped5!=0)msg+=", "+zu_intToString4051f0(dropped5)+" dropped";
					do{zu_logPhrase5141b0(0x18b,&msg,0,0,ZuHE(),0);}while(0);
				}
				if(!b7){
					int fx;
					zu_lookup9d7980("Part_Sabotaged",&fx);
					if(fx!=0)zu_cefc50->new508610(zu_cefc50)->init503b20(fx,((ZuEntityH*)this)->u45a4c0(),&zu_d2e20c,0,0,0,9,0);
				}
			}
		}
	}
	if(weapon&&((ZuItemDefH*)weapon)->get457330(0x43)){
		if(aa&&zu_d25450.enabled&&zu_d25450.u69edf0()){
			zu_d25450.u69ee30(0,0,1);
			return;
		}
		die633790(b7,0xa,attacker,1,0,0,0,0);
		return;
	}
	if(weapon){
		bool sy=false;
		switch(weapon->ff0){
		case 0xc3:
			if(u45ac40(0x13))break;
			if(rng.chance406c90(weapon->ff4))
				sy=true;
			else if(zu_d25450.enabled&&data->f28==0x21&&++zu_d25450.f9c==4)
				zu_d25450.u69e700(0x41,0,0.0f);
			break;
		case 0xd6:
			if(u45ac40(0x13))break;
			if(zu_cf45d8.hasCompanion780790()&&zu_cf4ac8->f0!=0&&rng.chance406c90(3)&&attacker.operator->()&&((ZuEntityH*)attacker.operator->())->u45a8d0()>=0xc8)
				sy=true;
		}
		if(sy){
			if(weapon->ff0==0xd6){
				((ZuEntityH*)attacker.operator->())->u45b1b0(0xc8);
				if(zu_cf45d8.hasCompanion780790())zu_cf4ac8->f30->spawn7aa280(0x17,0,data->getName459c30());
			}
			MSG(aa||u45aaa0(zu_cefc4c->getPlayer4630f0())?0xba:0xbb,0,0,0,self,ZuHE(),&((ZuEntityH*)this)->u45a4c0(),0);
			if(attacker.operator->()&&attacker->isPlayer5c7600())
				zu_d2c658.add4729d0(0x208,items134.size9b9260(),string(""),-1);
			u6335e0();
			bool t_=((ZuEntityH*)attacker.operator->())->isHostileTo45aa70(self);
			bool special=data->f28==0x21;
			die633790(b7,0xa,attacker,1,0,0,0,0);
			if(weapon->ff0==0xc3&&attacker.operator->()&&attacker->isPlayer5c7600()){
				if(t_)zu_cf45d8.u77fbc0(0xde);
				if(special)zu_cf45d8.u77fbc0(0xdf);
			}
			return;
		}
	}
	if(weapon&&weapon->ff0==0xd6&&zu_cf4ac8&&zu_cf4ac8->f2c==data->f48&&((ZuEntityH*)zu_cefc4c->getPlayer4630f0().operator->())->isHostileTo45aa70(self)&&rng.chance406c90(10)){
		if(zu_cf45d8.hasCompanion780790())zu_cf4ac8->f30->spawn7aa280(0x16,0,data->getName459c30());
		string msg=name416f40()+" is pierced by a surge of energy.";
		zu_message49c610(0x320,ZuHE(),msg,0);
		die633790(b7,0xa,attacker,1,0,0,0,0);
		return;
	}
	if(weapon&&weapon->ff0==0xc4&&!u45ac40(0x16)){
		ZuVecHI parts;
		u5cb8b0(&parts);
		for(unsigned i=0;i<parts.size9b9260();i++)
			if((parts.at9b81f0(i)->u457880()!=0xc&&parts.at9b81f0(i)->u457880()!=0xd)||parts.at9b81f0(i)->u577ad0()>0||parts.at9b81f0(i)->get415ee0())
				zu_eraseStep9d6440(parts,i);
		if(!parts.empty9b86e0()){
			ZuHI pick=zu_randomItem9dafb0(parts);
			u5fd550(pick,rng.rangeInt406d70(10.0f,weapon->ff4));
			MSG(aa?0x18c:((ZuEntityH*)this)->isHostileTo45aa70(zu_cefc4c->getPlayer4630f0())?0x18e:0x18d,&pick->getName571db0(0,0),0,0,self,ZuHE(),0,0);
			if(aa){
				ZuCPart*vC=zu_cec088->u894e70(pick);
				if(vC)vC->u890710(0);
			}
		}
	}
	if(data->f28==0x60&&weapon&&weapon->name.find("L-Cannon",0)!=string::npos&&((ZuMapH*)zu_cefc4c)->u748a00(0,weapon))return;
	int aG=weapon?weapon->f128:expl->f2c;
	switch(aG){
	case 0xa:
		return;
	}
	bool aH=false;
	int a4;
	if(aG==9)
		a4=0;
	else if(weapon){
		ZuPos range=weapon->f120;
		if(attacker.operator->()){
			if(weapon->b1b0&&!weapon->b165&&((ZuEntityH*)attacker.operator->())->u5d22a0(0x66)){
				int bonus=((ZuEntityH*)attacker.operator->())->u5d22a0(0x66);
				range.x+=range.x*bonus/100;
				range.y+=range.y*bonus/100;
				aH=true;
			}else if(a2==0){
				range.y+=((ZuEntityH*)attacker.operator->())->u5d2150(0x6a,0)*range.y/100;
				zu_addCapped9d06d0(&range.x,((ZuEntityH*)attacker.operator->())->u5d2090(0x5a)/2,range.y);
			}else if(weapon->f44==0x16||weapon->f44==0x17){
				range.x+=((ZuEntityH*)attacker.operator->())->u5d22a0(0x69)*range.x/100;
				if(range.x>range.y)range.y=range.x;
			}
		}
		a4=range.random40c130()*f5;
	}else
		a4=*dmg;
	zu_d1f3d4=zu_d323f8[aG];
	zu_d1f3f0=a4;
	if(records){
		ZuHE w3=self;
		if(zu_turn51da30(records,0x14,self,ZuHE(),ZuHE(),0,0)&&!w3.operator->())return;
		if(attacker.operator->()&&zu_turn51da30(records,0x15,attacker,ZuHE(),ZuHE(),0,0)&&!w3.operator->())return;
		if(zu_turn51da30(records,0x18,self,ZuHE(),ZuHE(),0,0)&&!w3.operator->())return;
	}else if(expl&&!expl->v9c.empty9b86e0()){
		ZuHE w9=self;
		ZuEffList*list=new ZuEffList(expl->v9c);
		bool r7=zu_4569a0(0x1a,attacker,self,ZuHP(),ZuHI(),0,0,list,self,ZuHP(),ZuHI(),0);
		delete list;
		if(r7&&!w9.operator->())return;
	}
	if(fec){
		ZuHE wC=self;
		if(zu_4569a0(0xe,self,ZuHE(),ZuHP(),ZuHI(),0,a2==0?&weapon->name:&weapon->s174,fec,self,ZuHP(),ZuHI(),0)&&!wC.operator->())return;
		if(a2==0&&zu_4569a0(0xf,self,ZuHE(),ZuHP(),ZuHI(),0,&weapon->name,fec,self,ZuHP(),ZuHI(),0)&&!wC.operator->())return;
		else if(a2!=0&&zu_4569a0(0x10,self,ZuHE(),ZuHP(),ZuHI(),0,&weapon->s174,fec,self,ZuHP(),ZuHI(),0)&&!wC.operator->())return;
	}
	if(aG==9)return;
	if(zu_d28f98)fd4=zu_caed20;
	if(weapon&&attacker==zu_cefc4c->getPlayer4630f0()){
		if(zu_cf4910.at9b81f0(data->f0)!=0)a4=a4*0x6e/100;
		if(ai&&ai->u459090()&&ai->u4590f0()->u458950(0x38))a4=a4*zu_b9764c;
	}
	if(attacker.operator->()&&weapon&&(weapon->f44==0x14||weapon->f44==0x15)&&!weapon->b165&&!aH)
		a4+=((ZuEntityH*)attacker.operator->())->u5d2150(0x67,0)*a4/100;
	if(attacker.operator->()&&weapon&&(attacker->isPlayer5c7600()||attacker==((ZuMapH*)zu_cefc4c)->getEntity671_463110())&&
		(zu_inRange9daf80(0x14,weapon->f44,0x17)||zu_inRange9daf80(0x1a,weapon->f44,0x1c))&&!weapon->b165&&data->f24!=0){
		int best=0;
		for(unsigned i=0;i<attacker->items134.size9b9260();i++)
			if(attacker->items134.at9b81f0(i)->u457cf0()&&attacker->items134.at9b81f0(i)->u457f90()==0x68&&attacker->items134.at9b81f0(i)->u457fb0()>best&&
				attacker->items134.at9b81f0(i)->getEffect457b70(0x74)&&attacker->items134.at9b81f0(i)->getEffectValue457be0(0x74)==data->f48)
				best=attacker->items134.at9b81f0(i)->u457fb0();
		if(best!=0)a4+=a4*best/100;
	}
	if(aG<7&&zu_cf49bc[aG]!=0&&attacker.operator->()&&attacker->isPlayer5c7600())
		a4+=a4*zu_cf49bc[aG]/100;
	if(!((ZuEntityH*)this)->u5e2e60(&a4,aG))return;
	if(weapon&&weapon->f16c!=0&&!aa)((ZuMapH*)zu_cefc4c)->u74b060(f30.at9e7c10(0),weapon->f16c,100);
	int heat=weapon?weapon->f12c:expl->f58;
	if(attacker.operator->()&&weapon&&weapon->f118==1){
		if(weapon->f44==0x14||weapon->f44==0x16)
			heat+=((ZuEntityH*)attacker.operator->())->u5d2090(0x70)+((ZuEntityH*)attacker.operator->())->u5d2090(0x71);
		else if(weapon->f44==0x15||weapon->f44==0x17)
			heat+=((ZuEntityH*)attacker.operator->())->u5d2090(0x71);
	}
	if(heat>0&&!aa&&attacker.operator->()&&attacker->isPlayer5c7600()&&((ZuEntityH*)this)->u5c8020()){
		zu_d2c658.add472b90(0x6a,heat*zu_b949b8[data->f24]);
		if(zu_d2c658.vals->at9b81f0(0x6a)<=-1000)zu_cf45d8.u77fbc0(0xca);
	}
	fb4+=heat;
	int a1=weapon?1:expl->f44.random40c130();
	int aC=0;
	if(weapon&&weapon->f138!=0&&!u45ac40(0x14)){
		aC=rng.chance406c90(weapon->f138+(attacker.operator->()&&weapon->f134!=2?((ZuEntityH*)attacker.operator->())->u5d2150(0x5f,0):0))?weapon->f134:0;
		if(aC!=0){
			if(aa)zu_d2c658.add4729d0(0x16d,1,string(""),-1);
			if(((ZuEntityH*)this)->u5d2380(0x4b).isValid9b7230()){
				aC=0;
				if(aa)zu_d2c658.add4729d0(0x16e,1,string(""),-1);
			}else if(aC==0xc&&u45ac40(0x15))
				aC=0;
		}
	}
	if(attacker.operator->()){
		if(attacker->isPlayer5c7600()){
			if(aa){
				zu_d2c658.add4729d0(0x1e0,a4,string(""),-1);
				zu_d2c658.add4729d0(0x1e1,1,string(""),-1);
			}else{
				zu_d2c658.add4729d0(0x1b1,a4,string(""),-1);
				if(!weapon||weapon->f44!=0x19)
					zu_d2c658.add4729d0(expl?0x1b4:a2==0?0x1b5:weapon->f44==0x14||weapon->f44==0x16?0x1b2:0x1b3,a4,string(""),-1);
				zu_d2c658.add4729d0(aG+0x1b7,a4,string(""),-1);
				if(((ZuEntityH*)this)->u5c8020()){
					zu_d2c658.add472b90(0x6a,a4*zu_b949a8[data->f24]);
					if(zu_d2c658.vals->at9b81f0(0x6a)<=-1000)zu_cf45d8.u77fbc0(0xca);
				}
			}
		}else{
			if(attacker->u45aaa0(zu_cefc4c->getPlayer4630f0()))attacker->fc8+=a4;
			if(attacker->group28->get9b4350()<=2){
				zu_d2c658.add4729d0(0x3af,a4,string(""),-1);
				if(attacker==((ZuMapH*)zu_cefc4c)->getEntity671_463110())zu_d2c658.add4729d0(0x451,a4,string(""),-1);
			}
		}
	}
	a4/=a1;
	do{
		switch(((ZuEntityH*)this)->takeDamage5e5520(a2==0?7:weapon?weapon->f44==0x14||weapon->f44==0x16?8:9:0xa,weapon,expl,a4,aG,aC,
			weapon?weapon->f150:expl->f5c,b7,attacker,0,zu_dir4374c0(*p6,f30.at9e7c10(0)),
			weapon?weapon->f154:expl&&aa?expl->f60:0,
			a1==1?weapon?zu_minInt9cdb30(attacker.operator->()&&attacker->u45ac40(0x1f)&&rng.chance406c90(0x32)?0:weapon->f158+(weapon->f158!=0&&weapon->f15c!=0&&f5>1.0?1:0),6):expl->f64:0,0)){
		case 0:
			if(weapon){
				int xC=0;
				int s2=0;
				switch(weapon->f27c){
					break;
				case 1:
					xC=weapon->f280;
					break;
				case 2:
					xC=data->f90->v50.at9b8070(2).at9b81f0(*weapon->f278);
					s2=data->f90->v50.at9b8070(3).at9b81f0(*weapon->f278);
				}
				if(xC)zu_sound454160(((ZuEntityH*)this)->u45a4c0(),xC,0x12);
				if(s2)zu_sound454160(((ZuEntityH*)this)->u45a4c0(),s2,0x12);
			}
			break;
		case 1:
			return;
		case 2:
			return;
		}
	}while(--a1);
	if(expl&&expl->f4c.y!=0&&data->f9c==1&&attacker.operator->()&&((ZuEntityH*)this)->u5d1390()!=0){
		int z6=expl->f4c.random40c130()+(2-data->f9c);
		if(z6>0){
			ZuPos origin;
			if(*p6!=f30.at9e7c10(0))
				origin=*p6;
			else if(zu_cfd420.x!=-1&&zu_cfd420!=f30.at9e7c10(0))
				origin=zu_cfd420;
			else{
				if(f30.at9e7c10(0)==attacker->getPosition45a4a0()){
					zu_logWarning404e50("Entity::projectileImpact()","force origin is shooter");
					goto kbDone;
				}
				ZuVecPt line;
				zu_bresenham40ff30(f30.at9e7c10(0),attacker->getPosition45a4a0(),&line);
				origin=line.at9e7c10(1);
			}
			for(int dir=zu_dir4374c0(origin,f30.at9e7c10(0)),pct5=0x32,k6=z6;k6>0;k6--){
				ZuPos next(f30.at9e7c10(0),zu_d015d8[dir]);
				if(((ZuEntityH*)this)->u5c84f0(next)){
					ZuHE z7=self;
					ZuHE hit;
					int bX=0;
					int c0=expl->f30;
					if(((ZuEntityH*)this)->u5c85a0(next,0)){
						hit=(*zu_cfd44c.atPoint9ced70(next))->getEntity45d250();
						if(((ZuEntityH*)hit.operator->())->getSize45a360()==1&&((ZuEntityH*)hit.operator->())->u5d1390()&&
							rng.chance406c90((((ZuEntityH*)hit.operator->())->u45a340()-data->f98)*10+pct5)){
							ZuVecPt aFp;
							aFp.push_back9b32e0(ZuPos(next)+=zu_d015d8[zu_b962e8[dir]]);
							aFp.push_back9b32e0(ZuPos(next)+=zu_d015d8[dir]);
							aFp.push_back9b32e0(ZuPos(next)+=zu_d015d8[zu_b96308[dir]]);
							for(int m=aFp.size9b9a50()-1;m>=0;m--)
								if(!((ZuEntityH*)hit.operator->())->u5c84f0(aFp.at9e7c10(m))||((ZuEntityH*)hit.operator->())->u5c8710(aFp.at9e7c10(m))||((ZuEntityH*)hit.operator->())->u5c85a0(aFp.at9e7c10(m),0))
									zu_eraseAt9d5190(aFp,m);
							if(!aFp.empty9b86e0()){
								u5ddac0(zu_randomPoint9d5350(aFp),0);
								((ZuEntityH*)hit.operator->())->checkTriggers5fdd30();
							}
							bX=c0;
							if(hit.operator->()&&((ZuEntityH*)hit.operator->())->u45a340()>1)bX/=((ZuEntityH*)hit.operator->())->u45a340();
						}
					}
					if(!((ZuEntityH*)this)->u5c85a0(next,0)){
						if(!((ZuEntityH*)this)->u5c8710(next)){
							MSG(aa?0xa2:0xa3,0,0,0,self,ZuHE(),0,0);
							u5ddac0(next,0);
							ZuObj717*ang=((ZuMapK*)zu_cefc4c)->u717be0();
							if(ang)ang->u45b6b0(self,getPosition45a4a0());
							if(!((ZuEntityH*)this)->checkTriggers5fdd30())return;
						}else if((*zu_cfd44c.atPoint9ced70(next))->getProp45d550().isValid9b7230()&&!(*zu_cfd44c.atPoint9ced70(next))->getProp45d550()->isPassableFor65e1d0(self)&&
							(*zu_cfd44c.atPoint9ced70(next))->getProp45d550()->u45c630()!=-1&&(*zu_cfd44c.atPoint9ced70(next))->getProp45d550()->u45c630()<=c0){
							(*zu_cfd44c.atPoint9ced70(next))->getProp45d550()->u45ceb0(attacker,b7);
							if(!z7.operator->())return;
							u5ddac0(next,0);
							ZuObj717*art=((ZuMapK*)zu_cefc4c)->u717be0();
							if(art)art->u45b6b0(self,getPosition45a4a0());
							if(!((ZuEntityH*)this)->checkTriggers5fdd30())return;
						}
					}
					if(bX!=0&&hit.operator->())
						((ZuEntityH*)hit.operator->())->takeDamage5e5520(0xa,weapon,expl,bX,4,0,0,b7,attacker,0,8,0,0,0);
					if(!z7.operator->())return;
				}
			}
		}
	}
kbDone:
	if((group28->get9b4350()==3||group28->get9b4350()==4)&&attacker.operator->()&&((ZuEntityH*)attacker.operator->())->u5cb680(zu_cefc4c->u463890(3))&&
		((ZuEntityH*)this)->getTarget45a760()==0&&!(ai->u459090()&&ai->u4590f0()->u458950(1))){
		bool cs=ai->get9b4350()>=6;
		int lvl=cs?2:1;
		if(rng.chance406c90(zu_b93fcc[lvl].a)&&!zu_cf65bf){
			ZuHP b9;
			unsigned theBestDist;
			ZuVVPt*markers=((ZuMapK*)zu_cefc4c)->getMarkers459070();
			for(unsigned i=0;i<markers->at9b8070(5).size9b9a50();i++){
				if(zu_distance40a3f0(getPosition45a4a0(),markers->at9b8070(5).at9e7c10(i))<=zu_b93fc8[lvl].a&&
					(*zu_cfd44c.atPoint9ced70(markers->at9b8070(5).at9e7c10(i)))->getProp45d550()->getState457b10()==0&&
					(*zu_cfd44c.atPoint9ced70(markers->at9b8070(5).at9e7c10(i)))->getProp45d550()->getData45cb30()->f38==0){
					ZuVecPt path;
					if(((ZuMapK*)zu_cefc4c)->u7168e0(getPosition45a4a0(),((ZuMapK*)zu_cefc4c)->u462f60((*zu_cfd44c.atPoint9ced70(markers->at9b8070(5).at9e7c10(i)))->getProp45d550()),self.operator->(),&path)&&
						path.size9b9a50()-1<=zu_b93fc8[lvl].a&&(b9.isNull9b65d0()||path.size9b9a50()-1<theBestDist)){
						theBestDist=path.size9b9a50();
						b9=(*zu_cfd44c.atPoint9ced70(markers->at9b8070(5).at9e7c10(i)))->getProp45d550();
					}
				}
			}
			if(b9.isValid9b7230()){
				bool at5=ai->u581140();
				bool ats=u45acb0(0x20)?false:at5;
				if(!ats){
					if(at5&&u45acb0(0x20))
						MSG(0x241,0,0,0,self,ZuHE(),0,0);
					else
						MSG(cs?0x242:0x23f,0,0,0,self,ZuHE(),0,0);
					do{
						zu_cf1080.set451400(1);
						if(1&&!(zu_d28fb0&&1&&1))zu_sound4541b0(0x127,0,0);
						MSG(0x324,&("ALERT: Activating "+b9->getData45cb30()->u65cc80()+"."),0,0,ZuHE(),ZuHE(),0,0);
						zu_cec0b4->scrollToEnd7b4f10();
					}while(0);
					do{zu_logPhrase5141b0(0x6a,0,0,0,ZuHE(),0);}while(0);
					b9->getData45cb30()->f38=new ZuDispatch(b9,0x70,zu_b93fd0[lvl].a,0,0,0,0,ZuHE(),lvl,getPosition45a4a0(),1,0);
					if(zu_cf4718!=0&&((ZuMapH*)zu_cefc4c)->u4631f0(self)&&!((ZuMapH*)zu_cefc4c)->isVisible4631c0(b9->getPos4184d0()))
						zu_cec054->u8197f0(b9->getPos4184d0(),1);
					if(attacker->isPlayer5c7600()&&zu_cf45d8.isSlotEmpty46de40(0x41)&&((ZuMapH*)zu_cefc4c)->u4631f0(self))
						zu_cf45d8.u77fbc0(0x41);
				}else{
					zu_d2c658.add4729d0(0x241,1,string(""),-1);
					MSG(cs?0x243:0x240,0,0,0,self,ZuHE(),0,0);
					if(zu_d2c658.vals->at9b81f0(0x241)==10)zu_cf45d8.u77fbc0(0x72);
				}
			}
		}
	}
	if(zu_cefb48&&attacker.operator->()&&attacker==((ZuMapH*)zu_cefc4c)->getEntity671_463110()&&aa){
		int col=0x77;
		if(!expl)
			col=0x3a;
		else if(expl->f2c!=3)
			col=0x3b;
		if(col!=0x77&&zu_cefb48)zu_cefb48->say49e250(col,0,string(""));
	}
}
