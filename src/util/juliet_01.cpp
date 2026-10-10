// juliet_01: CShell hack execution (exe 0x91ca50, 118 KB): runs one hacking command on a terminal/machine
//	(success roll, per-command result switch, failure/trace handling). Started by hotel (hotel_02 draft), finished by juliet.
// NOTE: names are placeholders; layouts are partial. Declarations follow src/util/delta2_16.cpp (same family).
// NOTE: local names (and some placeholder suffixes like found3/lineCount8) are chosen for the frame layout (16-bucket name hash).
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;


struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_);
	Pos(const Pos &pos) throw();	// 0x46ca50
	int distanceTo_409fb0(const Pos &p);
	bool same_409b90(const Pos &p);
};
struct H2sPt : Pos	// NOTE: placeholder name (default ctor 0x453b40)
{
	H2sPt() throw();
};

class H2sEntity;
class H2sHEntity
{
public:
	int ID;
	H2sHEntity() throw();
	H2sEntity *operator->() const;
	bool operator!=(H2sHEntity other) const;
	bool operator==(H2sHEntity other) const;
	bool isNull() const;
	bool isValid() const;
};

struct H2sHackRec { int type; int index; bool used; bool matches45b980(int type_, int index_); };	// NOTE: placeholder layout
class H2sBag { public: int draw(); };	// NOTE: placeholder name (shuffle bag)
struct H2sMachineData { char pad0[8]; int f8; int fc; bool f10; bool f11; char pad12[0x14 - 0x12]; H2sBag *bag; vector<H2sHackRec *> records; int f28; char pad2c[0x38 - 0x2c]; struct H2sJob *f38; int f3c; vector<int> f40; vector<int> f50; vector<int> f60; char pad70[0x80 - 0x70]; int f80; int f84; int f88; int f8c; bool unknown45c160(int type, int index); string unknown65cc80(); };	// NOTE: placeholder layout
struct H2sRec8; struct H2sRec4;
struct H2sHProp; class H2sHEntity;
struct H2sJob { int f0; int f4; int f8; H2sRec8 *fc; H2sRec4 *f10; int f14; vector<class H2sHItem> f18; char pad28[0x44 - 0x28]; bool b44; bool b45; H2sJob(H2sHProp machine, int type, int time, H2sRec8 *rec8, H2sRec4 *rec4, bool a, bool b, class H2sHItem c, int d, int e, int f, int g); ~H2sJob(); void complete_65a260(int a); };	// NOTE: placeholder layout
struct H2sMachineInfo { char pad0[0x8c]; int f8c; char pad90[0xf8 - 0x90]; int type; };	// NOTE: placeholder layout

struct H2sHProp;
struct H2sTrapInfo { int f0; int f4; int f8; H2sHEntity fc; int f10; };	// NOTE: placeholder layout
class H2sMachine	// NOTE: placeholder name (machine prop)
{
public:
	H2sMachineInfo *getInfo_9b8f00() throw();
	H2sMachineData *getData_45cb30() throw();
	const string &name_45c590();
	const string &getName_45c5b0();	// NOTE: placeholder name
	int getId_44ab40();	// NOTE: placeholder name
	void unknown45ce10(int a, int b, int c, H2sHProp d);	// NOTE: placeholder name
	Pos *getPosition_4184d0();
	void *unknown45c9b0();
	int unknown457b10();
	void unknown65f170();
	bool isTrap_45cb70();
	void disableMachine_65ed00();
	int unknown45ca00(int effect);
	void unknown45cd50();
	void unknown452270(int value);
	int unknown45c870(int type);
	struct H2sTrapInfo *getTrap_44b020();	// NOTE: placeholder name
};

struct H2sHProp
{
	int ID;
	H2sMachine *operator->() const throw();	// 0x9b64f0
	H2sHProp() throw();	// 0x9b6590
	bool isValid() const;
	bool isNull() const;
};

struct H2sItemStats { char pad0[0x24]; string f24; int f40; char pad44[0x54 - 0x44]; int f54; char pad58[0x94 - 0x58]; int f94; char pad98[0xa0 - 0x98]; int fa0; int getValue4574c0(int a, bool b, bool c) throw(); int unknown457580(int a); int unknown4575d0(int a); bool unknown56f7e0(H2sHProp machine); string unknown56f830(); };	// NOTE: placeholder layout
class H2sItem
{
public:
	H2sItemStats *stats_9b4350() throw();
	int getNestedField();
	string unknown571db0(int a, int b);
	bool unknown5773d0(int a, int b);
	bool unknown5775a0();
	bool unknown5776c0();
	bool unknown577700();
	int getField_457880();
	int getId_9fcd80();
	int unknown457b10();
	void setField_44fc60(int value);
	int getType_44aec0();
	bool unknown577640();
	void setBroken_5795b0(int a, int b);
	void unknown57a520(H2sHProp machine, int b);
	int unknown577600(int percent);
	void unknown57a0f0(const Pos &at, int a, int b);
	int unknown457c80();
	int unknown457ca0();
	void unknown458360(int amount);
	void unknown57bff0(int type, int value);
	int getField_457900();
	int getField_4578c0();
	bool unknown457d10() throw();
	bool unknown457db0() throw();
	int getField_4578a0();
	int unknown457f90();
	bool unknown457ad0();
	const string &getName_457860();
	void unknown458700(const string &text);
	void addEffect_4585a0(struct JlEffect *effect);
	void remove57dbe0(bool a, bool b, int c, bool d);
	int getField_9b6bf0();
	string unknown457990();
};
class H2sHItem
{
public:
	int ID;
	H2sHItem() throw();
	bool isValid() const;
	bool isNull() const;
	void reset_9b7270();
	H2sItem *operator->() const throw();
};

class H2sHCheck;
struct H2sAI { void unknown459410(const struct H2sRect &area); void setFollowEntity_5b2f80(H2sHEntity e, int mode); H2sHEntity getFollowEntity_458ed0(); int getState_9b8f00(); vector<Pos> *unknown458ef0(); };	// NOTE: placeholder name
class H2sEntity
{
public:
	int field490840();
	Pos unknown45a4c0();
	int getFaction_45a2c0();
	const Pos &getPosition_45a4a0();
	const string &getName_416f40();
	const string &getName_45a280();
	int unknown5cb830(vector<H2sHItem> *items);
	struct H2sAI *getAI_45b590();
	H2sHCheck getGroup_45a3f0();
	vector<H2sHItem> *getInventoryList();
	void unknown637bb0();
	H2sHItem unknown5d3f80(int a, int b);
	bool unknown5cbec0();
	bool unknown5cc550(vector<H2sHItem> *items);
	bool unknown5cc550(vector<int> *counts);
	int unknown5dc440(H2sHItem item);
	bool unknown5cbf30();
	bool unknown5cbfa0();
	bool unknown5cc010();
	void unknown5e2b00(int amount, const Pos &at);
	int unknown5c7f40();
	void *getInventory_45ad90();
	void unknown5de950(int amount, int b);
	void die(int a, int b, H2sHEntity killer, int c, int d, int e, int f, int g);
};

struct H2sCheck { bool test_45e380(); int getType_9b8f00(); vector<H2sHEntity> *getMembers_416f40(); };	// NOTE: placeholder name
class H2sHCheck { public: int ID; H2sCheck *operator->() const; };	// NOTE: placeholder name (0x9b7250)

struct H2sOwner { int f0; int f4; int f8; char padc[0x25 - 0xc]; bool b25; bool b26; bool b27; char pad28[0x60 - 0x28]; bool b60; bool b61; int getDepthIndex(); bool inRange_46ecb0(); };	// NOTE: placeholder layout
class H2sHOwner { public: int ID; H2sHOwner() throw(); bool isValid() const; bool isNull() const; bool operator==(H2sHOwner other) const; H2sOwner *operator->() const; bool operator!=(H2sHEntity other) const; };	// NOTE: placeholder name (0x9b7910)
struct H2sAccess { Pos pos; H2sHOwner owner; bool b0c; bool b0d; char pade[2]; int f10; char pad14[0x1c - 0x14]; int f1c; bool unknown6c1a10(); void unknown6c16d0(string text); ~H2sAccess(); };	// NOTE: placeholder layout
struct H2sMarker { char pad0[8]; Pos pos; char pad10[4]; int f14; void unknown6c20b0(int layer, const Pos &pos, int value); };	// NOTE: placeholder layout
class H2sHMarker { public: int ID; H2sMarker *operator->() const; };	// NOTE: placeholder name (0x9b7cd0)
class H2sFactory { public: H2sHMarker createC_793190(); void unknown792c50(); };	// NOTE: placeholder name
extern H2sFactory *h2s_cefaa8;

class H2sMap
{
public:
	char pad0[0x720];
	char f720[4];	// NOTE: placeholder layout
	void unknown9e29b0(void *list, H2sHProp prop);
	vector<H2sAccess *> *getAccess_462e10();
	H2sAccess *unknown462fd0(H2sHProp machine);
	H2sAccess *unknown462f60(H2sHProp machine);
	void onGarrisonAccessDisabled();
	int unknown71ab60(int count);
	H2sAccess *getZone_462e30(const Pos &pos);
	bool unknown463e90(const Pos &pos);
	bool isKnown_463130(int x, int y);
	bool isItemAtRecordedPosition_465560(H2sHItem item);
	void opw3_unknown724420(int x, int y);
	void opw3_unknown72f6b0();
	void unknown749240();
	void setFlag2f0_465640();
	vector<int> *unknown463b30();
	struct H2sGroup *selectRobotOfClass(int a, int b, int c, int d);
	vector<struct H2sJobRef *> *unknown464920();
	vector<struct H2sJobRef *> *unknown464940();
	int unknown71abf0(bool flag);
	void unknown464a80(H2sHProp machine);
	vector<vector<H2sHProp> > *unknown463be0();
	vector<H2sHProp> *unknown463c00(int trojan);
	struct H2sBotnet *unknown463c40();
	void opw3_unknown7243c0(int x, int y, int flag);
	void unknown464ab0();
	void unknown464ad0();
	void announceMachine_71dd30(H2sHOwner owner);
	void unknown4647a0(const Pos &pos, bool flag);
	void unknown4647d0(const Pos &pos);
	void unknown734d60(const Pos &pos);
	vector<Pos> *unknown463c20();
	vector<int> *unknown463d00();
	vector<Pos> *unknown463ab0();
	vector<vector<Pos> > *unknown463a90();
	void opw3_unknown729eb0(const Pos &pos, const string &text, int type, bool notify);
	vector<vector<H2sHMarker> > *unknown463ec0();
	vector<vector<Pos> > *unknown459070();
	struct H2sRec8 *selectRandomItem_6c3bc0(int kind, int a, int b);
	struct H2sRec4 *unknown6c5180();
	H2sHEntity getPlayer();
	bool unknown463b10();
	bool unknown71bde0(Pos *at, Pos *out);
	int getTurn();
	H2sHCheck unknown463890(int a, int b);
	H2sHCheck unknown463890(int a);
	H2sHItem placeItem(const string &name, const Pos &at);
};
extern H2sMap *h2s_cefc4c;

class H2sText { public: const string &text_458ef0(); };	// NOTE: placeholder name
struct H2sInput { char pad0[0x6c]; H2sText *text; };	// NOTE: placeholder layout

class H2sConsole
{
public:
	virtual ~H2sConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);
	virtual void update();
	virtual void render();
	virtual void open();
	virtual void close();
};
extern H2sConsole *h2s_cec104;

struct H2sRec8 { int index; char pad4[4]; string name; string search; int f40; int f44; int f48; char pad4c[4]; int f50; int f54; char pad58[0x90 - 0x58]; bool b90; char pad91[3]; int f94; char pad98[0xf0 - 0x98]; int ff0; char padf4[0x1f0 - 0xf4]; int f1f0; vector<int> f1f4; char pad204[0x209 - 0x204]; bool known; int getValue457330(int id); int getValue457430(int a); bool unknown56f4c0(H2sHProp machine); string unknown56f520(); };	// NOTE: placeholder layout
struct H2sRec4 { int index; string name; int f20; int f24; int f28; string f2c; char pad48[0x68 - 0x48]; int f68; char pad6c[0xe8 - 0x6c]; int fe8; char padec[0xf8 - 0xec]; int ff8; vector<int> ffc; char pad10c[0x148 - 0x10c]; vector<int> f148; char pad158[0x170 - 0x158]; string f170; char pad18c[0x1ac - 0x18c]; string f1ac; bool unknown5c3260(H2sHProp machine, bool b); string unknown5c32e0(); bool test_45b910(int value); int getValue459840(int a); };	// NOTE: placeholder layout
extern vector<H2sRec8 *> h2s_d2d1c4;
extern vector<H2sRec4 *> h2s_d25de0;
struct H2sRec0 { int index; string name; int f20; char pad24[0x3c - 0x24]; string f3c; char pad58[0x74 - 0x58]; int f74; string f78; string f94; };	// NOTE: placeholder layout (records behind 0xd35b58)
extern vector<H2sRec0 *> h2s_d35b58;
extern vector<int> h2s_cf4888;
extern vector<int> h2s_cf4844;
extern vector<int> h2s_cf4910;
extern string h2s_robotClassNames_d2f798[];
extern string h2s_d2d578;

extern H2sHOwner h2s_d1e888;
extern H2sHEntity h2s_cf6a28;
extern bool h2s_cf6a24;
extern int h2s_cf6aa0;

class H2sShell	// NOTE: placeholder name
{
public:
	H2sInput *getField_48f100();
	void delegate_4b0df0();
	bool selectLink90cdf0(int index);
	void addNew(const string &command, const string &text, int type, int a, int b);
	bool unknown91ca50(H2sHProp machine, int a, int type, int index, H2sRec8 *rec8, H2sRec4 *rec4, H2sHItem item);
	void unknown9397c0(H2sRec4 *rec);
	void unknown90eb10(const string &text);
	void opG1_showXomPortrait(int portrait);
	void addPointA8(vector<Pos> &points);
	void addPointB8(vector<Pos> &points);
	void addPointC8(vector<Pos> &points);
	void resetField_4b0eb0();
};
extern H2sShell *h2s_cec100;

class H2sHack	// NOTE: placeholder name (CHack)
{
public:
	bool unknown940ad0(int difficulty, int roll, int c);
	void unknown942a60();
	virtual ~H2sHack();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);
	virtual void update();
	virtual void render();
	virtual void open();
	virtual void close();

	H2sHProp getMachine_4b1460();
	int unknown45a990();
	void unknown93aae0();
};
extern H2sHack *h2s_cec0f8;

class H2sMachineUI { public: void unknown8fe760(int type, int index); H2sHItem unknown4aeb30(); };	// NOTE: placeholder name
extern H2sMachineUI *h2s_cec0fc;

class H2sFrames { public: void popFrame(); void unknown44cea0(H2sMachineUI *ui); };	// NOTE: placeholder name
extern H2sFrames *h2s_cefa8c;

class H2sStats { public: vector<int> *values; int unknown472c70(int id); bool add4729d0(unsigned int id, int value, string text, int extra); void add472b90(unsigned int id, int value); };
extern H2sStats h2s_d2c658;
class H2sPlayerData { public: void unknown780550(int id, int b); void unknown77fbc0(int id); bool unknown780380(int id, int b); void unknown780480(int id, int b); void unknown780700(int id, int b); };
extern H2sPlayerData h2s_cf45d8;
struct H2sXom { bool b0; char pad1[0xc - 1]; H2sHItem item; char pad10[0x14 - 0x10]; int favor; void unknown69fc60(int a, int b); void unknown69e450(); int unknown69e700(int amount, int b, float c); };	// NOTE: placeholder layout
extern H2sXom h2s_d25450;
extern bool h2s_d28c8a;
extern bool h2s_cefca9;
extern int h2s_cf4b38;
extern int h2s_cf4954;

struct H2sMsgType { int id; char pad4[0x46 - 4]; bool b46; };	// NOTE: placeholder layout
struct H2sMsg { H2sMsgType *type; string text; int turn; };	// NOTE: placeholder layout
class H2sLog { public: vector<H2sMsg *> *get_mutable(); };	// NOTE: placeholder name
extern H2sLog h2s_cf1080;
extern string h2s_d2d508[];
extern vector<string> h2s_d1e900;
extern vector<int> h2s_d1e910;
extern int h2s_b99270[];
extern string h2s_cf0470[];
extern bool h2s_cefc88;
extern bool h2s_d28f62;
extern string h2s_d2ae30[];

struct H2sSquad { int type; string name; int f20; };	// NOTE: placeholder layout
extern vector<int> h2s_d1e920;
extern vector<int> h2s_d1dd48;
extern vector<int> h2s_d1dd58;
extern vector<int> h2s_d1dda8;
extern vector<H2sSquad *> h2s_d1dd90;
extern H2sSquad *h2s_d1dda0;
extern H2sHItem h2s_d1dda4;
extern int h2s_d1dd44;
extern int h2s_d1ddb8;
extern int h2s_d1dd7c;
extern bool h2s_d1dd38;
extern bool h2s_b90458[];
extern string h2s_d29af8[];
extern string h2s_d29bbc;
extern vector<vector<H2sHProp> > h2s_d31640;

class H2sCell	// NOTE: placeholder name
{
public:
	bool isShortcut();
	bool unknown45dbb0();
	void unknown670690();
	void unknown670b20();
	H2sHItem getItem();
	bool unknown66b360();
	H2sHProp getProp_45d550();	// NOTE: placeholder name
	void unknown66a050(int type, int a, int b);
	bool isEdge_45dc30();
	int getTerrain_9fcd80();
	bool unknown45dcf0();
	bool isMachinePart_45dcd0();
	H2sHEntity getEntity_45d250();
	void removeProp_66c100(bool keepTerrain, int cause);
};
struct H2sRect { Pos a; Pos b; H2sRect() throw(); };	// NOTE: placeholder name (ctor 0x40b100)
class H2sGrid { public: H2sRect getArea_9b4400(); void getRect_9b4430(const Pos &p, int r, H2sRect &out); int getMaxX(); int getMaxY(); H2sCell **at(int x, int y); H2sCell **atPoint(const Pos &pos); };	// NOTE: placeholder name
extern H2sGrid h2s_cfd44c;
struct H2sGuard { int faction; H2sHEntity entity; char pad8[0x18 - 8]; int f18; string f1c; bool test_45e820(); };	// NOTE: placeholder layout
extern vector<H2sGuard *> h2s_cf6478;
extern vector<vector<H2sHProp> > h2s_d20248;
extern string h2s_mapNames_cfaca0[];
extern vector<int> h2s_d1ddbc;
extern int h2s_d38624;
extern int h2s_d38628;
extern bool h2s_bbbbec[];
extern int h2s_bbbbb0[];
extern int h2s_d1e884;
struct H2sSect { bool a; bool b; bool c; };	// NOTE: placeholder layout
extern H2sSect h2s_b90708[];
class H2sInventoryUI { public: void reopen8a2ce0(int a, H2sHEntity entity); };	// NOTE: placeholder name
extern H2sInventoryUI *h2s_cec08c;
class H2sWL	// NOTE: placeholder name (weighted list)
{
public:
	H2sWL();
	~H2sWL();
	void add(int value, int weight);
	int &pick();
	void remove(int value);
	int total_9b81d0();
	char pad[0x24];
};
class RNG { public: bool chance(int percent); int rangeInt(float low, float high); };
extern RNG rng;

void OpQ5_eraseStep_9d7300(vector<Pos> &list, int &index);
void OpQ5_eraseStep_9d6440(vector<H2sHMarker> &list, int &index);
void OpQ5_eraseStep_9d6440(vector<H2sHOwner> &list, int &index);
void OpQ5_eraseStep_9d6440(vector<H2sHItem> &list, int &index);
bool OpV4c_Fn9d3020Pos(vector<Pos> &list, Pos pos);
bool OpT8b_Fn9daf80(int lo, int v, int hi);
int OpS8d_popRandom(vector<int> &list);
void OpC_findNodes_470050(int depth, int start, vector<H2sHOwner> &nodes, vector<H2sHOwner> &links);
bool OpX5_containsRecord(vector<H2sRec8 *> &list, H2sRec8 *value);
bool OpX5_containsRecord(vector<H2sRec4 *> &list, H2sRec4 *value);
bool OpS8b_Fn9d51d0(vector<int> &list, int value);
int OpX5_maxInt(int a, int b);
string OpQ1_pointToString(const Pos &pos);
string intToString(int value);
string opY5_getIntelLabel(int id);
void logError(string where, string text);
void removeVectorElement_9de6f0(vector<H2sSquad *> &list, int index);
bool opq4c_suggest909990(bool flag);
void opR1f_466800();
int OpT8a_findString(vector<string> &list, string s);
int OpT8a_findStringIndex(const string *list, unsigned int count, string s);
bool OpX5_containsRecord(vector<int> &list, int value);
bool teamb_hack900340(int id, void *target, int index, int *result);
void OpW7_unknown4b1bf0(H2sHEntity a, H2sHEntity b);
void OpW7_unknown4b1bf0(H2sHEntity a, H2sHProp b);
void resetCount_466840();
int charToDigit_405b40(char c);
void opR1f_466730(const string &command);
string OpR5f_toUpper_4083a0(const string &text);
bool opS2_logPhrase_5141b0(int id, const string *a, const string *b, const string *c, H2sHEntity subject, const Pos *at);
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);
void OpV4c_Fn9d06d0(int *value, int amount, int max);
int opw1_findNoCase(const string &text, const string &term) throw();
bool OpY1_equalsNoCase(const string &a, const string &b) throw();
bool teamb_isAvailable9004e0(int type, const string *command);
bool teamb_parenthesized900870(const string &command, string &inner);
int OpS8d_findNameNoCase8(vector<H2sRec8 *> &list, const string &name);
int OpS8d_findNameNoCase4(vector<H2sRec4 *> &list, const string &name);


// ---- declarations specific to 0x91ca50 ----
struct H2sFlags6 { bool flag; char pad1[5]; };	// NOTE: placeholder layout (6-byte hack table rows, 0xb9b17b)
extern H2sFlags6 hotel_b9b17b[];	// NOTE: placeholder name
extern int hotel_b9b798[];	// NOTE: placeholder name
struct H2sRow34 { int value; char pad4[0x30]; };	// NOTE: placeholder layout
extern H2sRow34 hotel_ba4514[];	// NOTE: placeholder name
extern string hotel_d257c0;	// NOTE: placeholder name (list passed to OpX5_addUniqueString)
extern bool hotel_cf6a24;	// NOTE: placeholder name
extern int hotel_cf6a50;	// NOTE: placeholder name
extern int hotel_cf6a58;	// NOTE: placeholder name
extern int hotel_d254d0;	// NOTE: placeholder name
extern int hotel_d254d4;	// NOTE: placeholder name
struct H2sNode { int f0; int depth; };	// NOTE: placeholder layout
class H2sHNode { public: int ID; H2sNode *operator->() const; };	// NOTE: placeholder name (0x9b?)
extern H2sHNode hotel_d1e888;	// NOTE: placeholder name

class H2sSayer { public: void say(int id, int b, string text); };	// NOTE: placeholder name (OpW5_RolledValues::say)
extern H2sSayer *hotel_cefb48;	// NOTE: placeholder name
class H2sPD2 { public: bool getField_46dd90(); void unknown77fbc0(int id); void unknown783540(); };	// NOTE: placeholder name
extern H2sPD2 hotel_cf45d8;	// NOTE: placeholder name
class H2sTally { public: void unknown6998a0(int a, int b, int c); };	// NOTE: placeholder name
extern H2sTally hotel_cf6888;	// NOTE: placeholder name
class H2sMsgLog { public: void set_451400(int value); };	// NOTE: placeholder name
extern H2sMsgLog hotel_cf1080;	// NOTE: placeholder name
class H2sBubble { public: void bubble(int value); };	// NOTE: placeholder name
extern H2sBubble *hotel_cec058;	// NOTE: placeholder name
class H2sLogMsgs { public: void scrollToEnd(); };	// NOTE: placeholder name
extern H2sLogMsgs *hotel_cec0b4;	// NOTE: placeholder name
bool opS2_showMessage_5111e0(int id, const string *text, const string *b, int c, H2sHEntity d, H2sHEntity e, int f, int g);
void OpX5_addUniqueString(string *list, string text);	// NOTE: placeholder signature

class H2sTarget { public: char pad0[0x7c]; int f7c; void unknown4afab0(int flag); int getField_416230(); void unknown8fba20(); };	// NOTE: placeholder name
class H2sMachineUI2	// NOTE: placeholder name (object at 0xcec0fc)
{
public:
	string unknown4afe70(H2sHackRec *record);
	bool unknown4afdc0(int hackType);
	H2sRec4 *unknown4afd50();
	H2sRec8 *unknown4afce0();
	H2sHItem getItem_4afcc0(bool flag);
	H2sTarget *unknown4afc40(int hackType);
	H2sHItem getItem_4afcc0();
	void cleanup_4aff30();
	void unknown8fe6e0(bool flag);
	void unknown8fe7f0(int result);
	void unknown8fd610(int a, int b, H2sHEntity c, int d);
	void unknown8fd610(int a, int b, H2sHItem c, int d);
};
extern H2sMachineUI2 *hotel_cec0fc;	// NOTE: placeholder name

class H2sWorld	// NOTE: placeholder name (0xcefc4c)
{
public:
	H2sHEntity getPlayer();
	int unknown71adc0(H2sHEntity player, H2sHProp machine, H2sHackRec *record, int hackType, int index, H2sRec8 *rec8, H2sRec4 *rec4, H2sHItem item);
	bool opw3_unknown7272e0();
	bool isVisible_4631c0(const Pos &pos);
	void unknown464a60();
	void unknown6c6660(const string &data);
};
extern H2sWorld *hotel_cefc4c;	// NOTE: placeholder name

extern const char hotel_e_b991ab[], hotel_e_b991b9[], hotel_e_b991ba[], hotel_e_b991bb[], hotel_e_b99203[],
	hotel_e_b99333[], hotel_e_b99359[], hotel_e_b9935a[], hotel_e_b9935b[], hotel_e_b99379[], hotel_e_b9937a[],
	hotel_e_b9937b[], hotel_e_b99395[], hotel_e_b99396[], hotel_e_b99397[], hotel_e_b993a3[], hotel_e_b993af[],
	hotel_e_b993bb[], hotel_e_b993fe[], hotel_e_b993ff[], hotel_e_b9942b[], hotel_e_b9945a[], hotel_e_b9945b[], hotel_e_b9946d[], hotel_e_b9946e[], hotel_e_b9946f[], hotel_e_b994b3[], hotel_e_b994e2[], hotel_e_b994e3[], hotel_e_b994f5[], hotel_e_b994f6[], hotel_e_b994f7[], hotel_e_b99571[], hotel_e_b99572[], hotel_e_b99573[], hotel_e_b995ad[], hotel_e_b995ae[], hotel_e_b995af[], hotel_e_b995ba[], hotel_e_b995bb[], hotel_e_b995c6[], hotel_e_b995c7[], hotel_e_b995d2[], hotel_e_b995d3[], hotel_e_b995df[], hotel_e_b995e9[], hotel_e_b995ea[], hotel_e_b995eb[], hotel_e_b995f5[], hotel_e_b995f6[], hotel_e_b995f7[], hotel_e_b99617[], hotel_e_b9961f[], hotel_e_b9962b[], hotel_e_b99635[], hotel_e_b99636[], hotel_e_b99637[], hotel_e_b9963b[], hotel_e_b9963f[], hotel_e_b99649[], hotel_e_b9964a[], hotel_e_b9964b[], hotel_e_b99655[], hotel_e_b99656[], hotel_e_b99657[], hotel_e_b99661[], hotel_e_b99662[], hotel_e_b99663[], hotel_e_b9966d[], hotel_e_b9966e[], hotel_e_b9966f[], hotel_e_b9967a[], hotel_e_b9967b[], hotel_e_b99686[], hotel_e_b99687[], hotel_e_b99692[], hotel_e_b99693[], hotel_e_b9969e[], hotel_e_b9969f[], hotel_e_b996af[], hotel_e_b996ee[], hotel_e_b996ef[], hotel_e_b996fa[], hotel_e_b996fb[], hotel_e_b99706[], hotel_e_b99707[], hotel_e_b99715[], hotel_e_b99716[], hotel_e_b99717[], hotel_e_b99725[], hotel_e_b99726[], hotel_e_b99727[], hotel_e_b99735[], hotel_e_b99736[], hotel_e_b99737[], hotel_e_b99745[], hotel_e_b99746[], hotel_e_b99747[], hotel_e_b9975b[], hotel_e_b9976a[], hotel_e_b9976b[], hotel_e_b9977d[], hotel_e_b9977e[], hotel_e_b9977f[], hotel_e_b99792[], hotel_e_b99793[], hotel_e_b997a2[], hotel_e_b997a3[], hotel_e_b997b9[], hotel_e_b997ba[], hotel_e_b997bb[], hotel_e_b997dd[], hotel_e_b997de[], hotel_e_b997df[], hotel_e_b9980f[], hotel_e_b9981f[], hotel_e_b9982f[], hotel_e_b9985d[], hotel_e_b9985e[], hotel_e_b9985f[], hotel_e_b9986e[], hotel_e_b9986f[], hotel_e_b9987e[], hotel_e_b9987f[], hotel_e_b9988e[], hotel_e_b9988f[];	// NOTE: tail-merged "" literals, one per site
#define LOG0(id) do { opS2_logPhrase_5141b0(id, 0, 0, 0, H2sHEntity(), 0); } while (0)
#define STAT(id, site) h2s_d2c658.add4729d0(id, 1, string(site), -1)
#define H2_SHOW(id, text) do { if (opS2_showMessage_5111e0(id, text, 0, 0, H2sHEntity(), H2sHEntity(), 0, 0)) hotel_cec058->bubble(1); hotel_cec0b4->scrollToEnd(); } while (0)
#define H2_ALERT(text) do { hotel_cf1080.set_451400(1); if (0) opR1d_4541b0(-1, 0, 0); H2_SHOW(0x324, &(text)); hotel_cec0b4->scrollToEnd(); } while (0)

struct H2sRobotSeen { int f0; bool known; H2sRec0 *robot; char padc[0x14 - 0xc]; H2sRec4 *analysis; };	// NOTE: placeholder layout
extern vector<H2sRobotSeen *> hotel_d02cb4;	// NOTE: placeholder name
extern vector<int> hotel_cf4924;	// NOTE: placeholder name
extern string hotel_d2ec34;	// NOTE: placeholder name
void hotel_decode_4351e0(string *text);	// NOTE: placeholder name
void hotel_prelearn_data(const string &data, int flag);	// NOTE: placeholder name (prelearnData)
void hotel_unknown91c850(int hackType, int *a, int *b, const string &name = "");	// NOTE: placeholder name
#define LOGP(id, expr) do { opS2_logPhrase_5141b0(id, &(expr), 0, 0, H2sHEntity(), 0); } while (0)

bool hotel_collectProps_517ae0(int id, vector<Pos> *out, bool flag, int kind, Pos *at);	// NOTE: placeholder name
bool hotel_lookup_9d7980(const string &name, int *out);	// NOTE: placeholder name
struct H2sFxArg { int value; };	// NOTE: placeholder layout
extern H2sFxArg hotel_d2e20c;	// NOTE: placeholder name
class H2sFx { public: void init_503b20(); };	// NOTE: placeholder name
class H2sFxEngine { public: H2sFx *unknown508610(H2sFxEngine *self, int effect, const Pos &pos, const H2sFxArg &arg, int a, int b, int c, int d, int e); };	// NOTE: placeholder name
extern H2sFxEngine *hotel_cefc50;	// NOTE: placeholder name

struct JlPos : Pos { JlPos(int v) throw(); JlPos &operator=(const Pos &p) throw(); };	// NOTE: placeholder name (Pos(int) 0x409990, operator= folded into 0x46ca50)
// ---- juliet additions (cases 1..110, tail) ----
string OpU8a_randomString(const vector<string> &list);
string opR1f_465bc0();
extern vector<string> jl_d37a40;	// NOTE: placeholder name
class H2sMapBS { public: H2sRec8 *selectRandomItemOfRating(int rating, int a, int b, int c, int d, int e, int f); bool unknown71ec60(const Pos &p, vector<Pos> points); H2sHEntity unknown6c5dc0(const string &name, const Pos &pos, int group, bool flag, int aiMode1, int aiMode2, bool forced); void unknown6c65a0(H2sHEntity robot, const string &name, int b); void unknown74bb90(H2sHProp machine, H2sHProp *seal, Pos *at, bool *busy); void unknown6c6b90(const Pos &at, const string &name, int a, int b); H2sHItem unknown6c5400(H2sRec8 *type, const Pos &at); H2sHItem unknown6c51d0(H2sRec8 *part, H2sHEntity owner, int a, int b); H2sHEntity placeEntity_6c58c0(struct H2sGroup *group, const Pos &at, int a, int b, int c, int d, int e); };	// NOTE: placeholder name (0xcefc4c as BS)
extern H2sMapBS *jl_cefc4c;	// NOTE: placeholder name
extern vector<string> jl_d30540;	// NOTE: placeholder name
bool OpT8b_Fn9db000(vector<int> &list, int value);	// NOTE: placeholder signature (add unique)
extern int jl_cf4d24;	// NOTE: placeholder name
bool OpU8a_containsString(vector<string> &list, string text);	// NOTE: placeholder signature
class H2sGameData { public: int getDepthIndex(); string generateID_46f890(); const string &getEntryText_46f6d0(const string &key); void setEntryText_46f700(const string &key, const string &value); int getWeightedDepthCount_7896a0(); int getTier_46fd60(); bool unknown46f4b0(int a); int getNextWeightedDepthCount_789720(); };	// NOTE: placeholder name (0xd1e860)
extern H2sGameData jl_d1e860;	// NOTE: placeholder name
int OpX5_minInt(int a, int b);
int jl_randomIndex_9d9b20(vector<int> &list);	// NOTE: placeholder name (OpQ5_randomIndex<T>, folded)
template <class T> void removeVectorElement(vector<T> &v, int index);
extern vector<int> jl_cf4830;	// NOTE: placeholder name
class H2sPD3 { public: bool unknown77ffb0(int id, int b); };	// NOTE: placeholder name (0xcf45d8)
extern H2sPD3 jl_cf45d8;	// NOTE: placeholder name
extern bool jl_cf6458;	// NOTE: placeholder name
int OpU8a_indexOfName4(void *list, const string &name);	// NOTE: placeholder signature
extern char jl_cfb844[];	// NOTE: placeholder name
int opR1d_454260(const Pos &p, int id);	// NOTE: placeholder name
bool opS2_showMessage_5111e0(int id, const string *text, const string *b, int c, H2sHEntity d, H2sHEntity e, const Pos *at, int g);
string opw8_countString(int count, const string &word);	// NOTE: placeholder signature
void clearDijkstraResults();
class H2sFov { public: void unknown40ca20(const Pos &p, int range, void *cost, void *out); };	// NOTE: placeholder name
extern H2sFov jl_cfe568;	// NOTE: placeholder name
extern char jl_d297a8[];	// NOTE: placeholder name
extern vector<Pos> jl_d15e58;	// NOTE: placeholder name
extern vector<Pos> jl_cf6a60;	// NOTE: placeholder name
extern vector<Pos> jl_cf6a70;	// NOTE: placeholder name
bool OpV4c_Fn9d0ce0Pos(vector<Pos> &list, Pos p);	// NOTE: placeholder signature
extern string jl_d3a280[];	// NOTE: placeholder name
string &padLeft_408090(string &s, unsigned int width, char c);
extern string jl_cf3fb0[];	// NOTE: placeholder name
extern int jl_cf6474;	// NOTE: placeholder name
extern int jl_cf645c;	// NOTE: placeholder name
extern bool jl_cf6468;	// NOTE: placeholder name
extern int jl_cf6428;	// NOTE: placeholder name
int opr1c_getThresholdIndex(int value);
string opr1c_getSecurityName_4332b0(int value);
class H2sOvermind { public: void unknown682420(int a, int b); };	// NOTE: placeholder name
extern H2sOvermind jl_ovm_cf6428;	// NOTE: placeholder name (same object as jl_cf6428)
extern int jl_cf4744;	// NOTE: placeholder name
extern char jl_cfd428[];	// NOTE: placeholder name
extern vector<int> jl_d3239c;	// NOTE: placeholder name
void OpT8a_eraseAt(vector<int> &v, unsigned int &i);
int OpU8a_randomRec(vector<int> &v);
void jl_appendUnique_9d80a0(vector<Pos> &out, vector<Pos> &in);	// NOTE: placeholder name (OpS8c_appendUnique)
int OpT8a_sumVector(vector<int> &v);	// NOTE: placeholder signature
extern string jl_cf25d8[];	// NOTE: placeholder name
extern string jl_partyTypeNames_d2f350[];	// NOTE: placeholder name
char randomChar_4085b0(const string &chars);	// NOTE: placeholder signature
class H2sOvermind2 { public: void unknown68cd80(H2sGuard *squad); };	// NOTE: placeholder name
extern H2sOvermind2 jl_ovm2_cf6428;	// NOTE: placeholder name (same object as jl_cf6428)
int OpU8a_indexOfEntity(vector<H2sHEntity> &list, H2sHEntity entity);	// NOTE: placeholder signature
extern vector<H2sHEntity> jl_cf6a80;	// NOTE: placeholder name
extern vector<vector<string> > jl_cf6a90;	// NOTE: placeholder name
void jl_eraseAt_9da940(vector<H2sHItem> &list, int index);	// NOTE: placeholder name (OpQ5_eraseAt<T>)
extern char jl_d2f504[];	// NOTE: placeholder name
extern int jl_cf4718;	// NOTE: placeholder name
extern int TERRAIN_EARTH;	// NOTE: placeholder name (TERRAIN_EARTH)
extern string jl_cfe140[];	// NOTE: placeholder name
H2sHEntity OpX5_randomRecord(vector<H2sHEntity> &v);	// NOTE: placeholder signature
class H2sOvermind3 { public: void unknown68c6d0(H2sHEntity robot); };	// NOTE: placeholder name
extern H2sOvermind3 jl_ovm3_cf6428;	// NOTE: placeholder name (same object as jl_cf6428)
int stringToInt(const string &s);
extern vector<int> jl_d2f0f8;	// NOTE: placeholder name
struct JlEffect { int type; int value; JlEffect(int type_, int value_); };	// NOTE: placeholder name (ctor folded into 0x46ca20; defined here so LTCG proves it nothrow)
JlEffect::JlEffect(int type_, int value_) { type = type_; value = value_; }
extern int jl_caed20;	// NOTE: placeholder name
extern char jl_d2c408[];	// NOTE: placeholder name
extern int jl_d1ec6c;	// NOTE: placeholder name
extern int jl_d1ec70;	// NOTE: placeholder name
class H2sSoundMgr { public: void unknown454540(); void unknown500010(); };	// NOTE: placeholder name
extern H2sSoundMgr jl_d2d2a0;	// NOTE: placeholder name
int OpQ1_distanceCeil_40a3f0(const Pos &a, const Pos &b);	// NOTE: placeholder name
bool jl_removeEntity_9d2f00(vector<H2sHProp> &v, H2sHProp e);	// NOTE: placeholder name (OpU8a_removeEntity)
bool jl_addUniqueEntityData_9d30e0(vector<H2sHProp> *v, H2sHProp e);	// NOTE: placeholder name (OpX5_addUniqueEntityData)
struct H2sBotnet { vector<H2sHProp> list; int f10; int f14; int f18; int f1c; void unknown6c2180(); };	// NOTE: placeholder layout
Pos jl_randomPoint_9d5350(vector<Pos> &v);	// NOTE: placeholder name (OpU8a_randomPoint)
int opr5e_unknown91c960(string *text, int lines);	// NOTE: placeholder signature
struct H2sParty { int type; };	// NOTE: placeholder layout
class H2sOvermind4 { public: H2sParty *unknown68cf70(vector<int> types, const Pos &at); void unknown6820b0(); bool redirectParty_68d1f0(H2sParty *party, const Pos &at, H2sHEntity target); };	// NOTE: placeholder name
extern H2sOvermind4 jl_ovm4_cf6428;	// NOTE: placeholder name (same object as jl_cf6428)
extern int jl_caf164;	// NOTE: placeholder name
extern int jl_caf160;	// NOTE: placeholder name
string opW5_truncate_408490(const string &text, int length);
struct H2sJobRef { Pos pos; int f8; int fc; };	// NOTE: placeholder layout
extern vector<string> jl_d1d61c;	// NOTE: placeholder name
struct H2sProduct { int type; };	// NOTE: placeholder layout
class H2sProductList { public: vector<H2sProduct *> *getList_9c0790(); };	// NOTE: placeholder name
extern H2sProductList jl_cf0c04;	// NOTE: placeholder name
extern vector<H2sRec8 *> jl_d2ed7c;	// NOTE: placeholder name
extern vector<H2sRec8 *> jl_d316a0;	// NOTE: placeholder name
extern vector<H2sRec8 *> jl_d32990;	// NOTE: placeholder name
extern vector<H2sRec8 *> jl_d31510;	// NOTE: placeholder name
extern vector<int> jl_cf47cc;	// NOTE: placeholder name
class H2sGM { public: void addItemAttachCount_778560(int type, int a, int b); };	// NOTE: placeholder name
extern H2sGM jl_d25628;	// NOTE: placeholder name
struct H2sPartView { void drawStatus_4a8e70(int a); };	// NOTE: placeholder name
class H2sParts { public: H2sPartView *unknown894e70(H2sHItem item); void toggle8993e0(H2sPartView *view, bool b); };	// NOTE: placeholder name
extern H2sParts *jl_cec088;	// NOTE: placeholder name
extern const float jl_b9b9b8;	// NOTE: placeholder name (0.5f)
extern const float jl_bba054;	// NOTE: placeholder name (0.5f)
extern int jl_b9b9bc[];	// NOTE: placeholder name
struct H2sRange { int lo; int hi; int randomInRange_40c130(); };	// NOTE: placeholder layout
struct H2sRangePair { H2sRange a; H2sRange b; };	// NOTE: placeholder layout
extern H2sRangePair jl_d395b0[];	// NOTE: placeholder name
void lmgr_insert9d8fc0(vector<H2sHItem> &v, int index, H2sHItem value);	// NOTE: placeholder signature
void jl_eraseRange_9d9530(vector<H2sHItem> &v, int from, int to);	// NOTE: placeholder name (OpQ5_eraseRange)
extern vector<vector<H2sHItem> > jl_cf3a10;	// NOTE: placeholder name
int jl_randomIndex_9d9b20(vector<H2sHItem> &list);	// NOTE: placeholder name (OpQ5_randomIndex<T>, folded)
extern vector<string> jl_d29d7c;	// NOTE: placeholder name
void OpC_findNodes_470400(int node, vector<H2sHOwner> &matches, vector<H2sHOwner> &visited);	// NOTE: placeholder signature
void OpC_findNodes_470320(int node, int depth, vector<H2sHOwner> &nodes, vector<H2sHOwner> &found);	// NOTE: placeholder signature
class JlOwnerWL	// NOTE: placeholder name (weighted list of HLocation)
{
public:
	JlOwnerWL();
	~JlOwnerWL();
	void add(H2sHOwner value, int weight);
	H2sHOwner &pick();
	void removeEntity(H2sHOwner value);
	int total_9b81d0();
	char pad[0x24];
};
extern int jl_cf4d2c;	// NOTE: placeholder name
extern int jl_cf4b20;	// NOTE: placeholder name
extern string jl_cf4acc;	// NOTE: placeholder name
extern vector<int> jl_d1eb44;	// NOTE: placeholder name
extern int jl_d1eb54;	// NOTE: placeholder name
extern int jl_b99930[];	// NOTE: placeholder name
extern string jl_d02b98[];	// NOTE: placeholder name
extern string jl_d02bec;	// NOTE: placeholder name
extern int jl_d1eb10;	// NOTE: placeholder name
extern H2sRange jl_cf1694;	// NOTE: placeholder name
extern int TERRAIN_CAVE_WALL;	// NOTE: placeholder name (TERRAIN_CAVE_WALL)
extern bool jl_d1ebfc;	// NOTE: placeholder name
void sweepGetSurroundingCells_4faaf0(const Pos &at, vector<Pos> &cells);	// NOTE: placeholder signature
string OpY1_intToStringSigned(int value);
extern bool jl_ba034c[];	// NOTE: placeholder name
int jl_randomIndex_9da8b0(vector<string> &list);	// NOTE: placeholder name (OpQ5_randomIndex<T>)
void OpU8a_removePoint_9d3060(vector<Pos> &list, Pos p);	// NOTE: placeholder signature
extern int *jl_cefb9c;	// NOTE: placeholder name (terrain id pointer)
bool OpS8b_Fn9d51d0Access(vector<H2sAccess *> &list, H2sAccess *value);	// NOTE: placeholder signature
extern vector<Pos> jl_cf64c0;	// NOTE: placeholder name
extern vector<int> jl_cf64d0;	// NOTE: placeholder name
void jl_eraseAt_9ce6d0(vector<H2sJobRef *> &v, unsigned int &i);	// NOTE: placeholder name (OpT8a_eraseAt)
void jl_clearObjects_9d0670(vector<H2sJobRef *> &v);	// NOTE: placeholder name (OpQ5_clearObjects<T>)
extern bool jl_d28f64;	// NOTE: placeholder name
extern bool jl_d28f65;	// NOTE: placeholder name
extern H2sFlags6 jl_b9b17a[];	// NOTE: placeholder name (column of the 6-byte hack table)
extern H2sFlags6 jl_b9b179[];	// NOTE: placeholder name
class H2sOvermind5 { public: void unknown681e70(int amount); bool findDispatchExit(H2sPt *out, int a, int b, int c, const Pos &from, void **access, int e, int f); };	// NOTE: placeholder name
extern H2sOvermind5 jl_ovm5_cf6428;	// NOTE: placeholder name (same object as jl_cf6428)
extern int jl_b9afb8[];	// NOTE: placeholder name
extern int *jl_cf4700;	// NOTE: placeholder name
class H2sPD4 { public: void addPolymindSuspicion_77ee70(float amount, int b, H2sHEntity c); };	// NOTE: placeholder name
extern H2sPD4 jl_pd_cf45d8;	// NOTE: placeholder name (same object as h2s_cf45d8)
extern const float jl_ba852c;	// NOTE: placeholder name (-5.0f)
extern H2sBag *jl_cf6a54;	// NOTE: placeholder name
extern H2sBag *jl_cf6a5c;	// NOTE: placeholder name
struct H2sGroup;	// NOTE: placeholder name
extern string jl_cf448c;	// NOTE: placeholder name
extern int jl_cf6a20;	// NOTE: placeholder name
extern H2sHOwner jl_cf6a28;	// NOTE: placeholder name
extern vector<int> jl_cf6888;	// NOTE: placeholder name
extern int jl_ba4454[];	// NOTE: placeholder name
extern int jl_ba5a00[];	// NOTE: placeholder name
extern int jl_cf68ac;	// NOTE: placeholder name
extern int jl_cf68b4;	// NOTE: placeholder name
extern int jl_ba4ca8[][5];	// NOTE: placeholder name
extern int jl_ba4cb8[][5];	// NOTE: placeholder name (column 4 of jl_ba4ca8)
bool OpV4c_Fn9d3f40(int *list, unsigned int count);
struct JlRangePair { int minA, maxA, minB, maxB; };	// NOTE: placeholder layout (two 8-byte ranges)
class H2sExpiry { public: void unknown45f070(JlRangePair &ranges); };	// NOTE: placeholder name
extern H2sExpiry jl_exp_cf68ac;	// NOTE: placeholder name (same object as jl_cf68ac)
extern JlRangePair jl_d22580;	// NOTE: placeholder name
extern JlRangePair jl_cfe12c;	// NOTE: placeholder name
extern string jl_cf1220;	// NOTE: placeholder name
extern string jl_d305e0[];	// NOTE: placeholder name
H2sHOwner OpX5_randomRecord(vector<H2sHOwner> &v);	// NOTE: placeholder signature
void jl_eraseAt_9da940(vector<H2sHOwner> &list, int index);	// NOTE: placeholder name (OpQ5_eraseAt<T>)
extern int jl_cf6a38;	// NOTE: placeholder name
extern H2sRange jl_d2c374;	// NOTE: placeholder name
class H2sTally2 { public: void unknown69b560(bool flag); };	// NOTE: placeholder name
extern H2sTally2 jl_tally_cf6888;	// NOTE: placeholder name (same object as hotel_cf6888)
extern vector<vector<string> > jl_d21b10;	// NOTE: placeholder name
extern vector<vector<int> > jl_cf6aa4;	// NOTE: placeholder name
extern vector<string> jl_cf45a0;	// NOTE: placeholder name
extern vector<int> jl_cf6abc;	// NOTE: placeholder name
extern vector<string> jl_cf08b4;	// NOTE: placeholder name
extern vector<int> jl_cf6acc;	// NOTE: placeholder name
struct H2sRecorder { char pad0[0x10]; vector<vector<int> > f10; };	// NOTE: placeholder layout
extern H2sRecorder *jl_cf68a8;	// NOTE: placeholder name
extern int jl_cf6a30;	// NOTE: placeholder name
extern int jl_cf6a2c;	// NOTE: placeholder name
extern string jl_cfd4d0[];	// NOTE: placeholder name
extern H2sHEntity jl_cf68b8;	// NOTE: placeholder name
extern int jl_b911c0[];	// NOTE: placeholder name
extern string jl_d33e1c;	// NOTE: placeholder name
int pointsFn_4374c0(const Pos &a, const Pos &b);	// NOTE: placeholder signature
extern string jl_d01a48[];	// NOTE: placeholder name
extern bool jl_cf6ab4;	// NOTE: placeholder name
extern int jl_cefb74;	// NOTE: placeholder name
extern bool jl_cefb3e;	// NOTE: placeholder name
struct H2sCounter { int f0; char pad4[8]; bool bc; };	// NOTE: placeholder layout
extern H2sCounter *jl_cec024;	// NOTE: placeholder name


class CShell	// (object at 0xcec100)
{
public:
	bool unknown91ca50(H2sHProp machine, H2sHackRec *record, int type, int index, H2sRec8 *rec8, H2sRec4 *rec4, H2sHItem item);	// NOTE: placeholder name
	void addNew(const string &hackType, const string &text, int type, int a, int b);
	void opG1_showXomPortrait(int portrait);
	void unknown90f990(const string &text = string(""));
	void unknown90ec30(string text);
	void unknown90eb10(const string &text);
	void unknown90f0a0();
	void unknown90ed30(const string &text, int a, int b, int c);


	char pad0[0xa8];
	vector<Pos> unknownA8;	// NOTE: placeholder name
	vector<Pos> unknownB8;	// NOTE: placeholder name
	vector<Pos> unknownC8;	// NOTE: placeholder name
	bool unknownD8;	// NOTE: placeholder name
	char padd9[0xdc - 0xd9];
	vector<Pos> unknownDC;	// NOTE: placeholder name
	int unknownEc;	// NOTE: placeholder name
	int unknownF0;	// NOTE: placeholder name
	vector<int> unknownF4;	// NOTE: placeholder name
	vector<H2sHackRec *> unknown104;	// NOTE: placeholder name
	vector<int> unknown114;	// NOTE: placeholder name
	int unknown124;	// NOTE: placeholder name
};

extern CShell *jl_cec100;	// NOTE: placeholder name (the CShell singleton)

bool CShell::unknown91ca50(H2sHProp machine, H2sHackRec *record, int type, int index, H2sRec8 *rec8, H2sRec4 *rec4, H2sHItem item)
{
	if (record == NULL)
	{
		vector<H2sHackRec *> &records = machine->getData_45cb30()->records;
		for (unsigned int i = 0; i < records.size(); i++)
		{
			if (records[i]->matches45b980(type,index) && !records[i]->used)
			{
				record = records[i];
				break;
			}
		}
	}
	int hackType = record ? record->type : type;
	unknownF4.push_back(hackType);
	string name;
	if (machine->getInfo_9b8f00()->type >= 6)
		name = hotel_cec0fc->unknown4afe70(record);
	else
	{
		name = h2s_d2d508[hackType];
		unsigned int pos = name.find('*',0);
		if (pos == string::npos)
			pos = name.find('@',0);
		if (pos != string::npos)
		{
			name.erase(name.begin() + pos);
			switch (hackType)
			{
				case 0:
					name.insert(name.begin() + pos,h2s_d35b58[record ? record->index : index]->name.begin(),h2s_d35b58[record ? record->index : index]->name.end());
					break;
				case 1:
					name.insert(name.begin() + pos,h2s_d2d1c4[record ? record->index : index]->search.begin(),h2s_d2d1c4[record ? record->index : index]->search.end());
					break;
				case 2:
				case 3:
					name.insert(name.begin() + pos,h2s_d25de0[record ? record->index : index]->f1ac.begin(),h2s_d25de0[record ? record->index : index]->f1ac.end());
					break;
				case 66:
					name.insert(name.begin() + pos,rec8 ? rec8->search.begin() : rec4->f1ac.begin(),rec8 ? rec8->search.end() : rec4->f1ac.end());
					break;
				case 76:
				case 81:
				case 94:
				case 96:
				{
					string itemName = item->unknown571db0(0,0);
					name.insert(name.begin() + pos,itemName.begin(),itemName.end());
					break;
				}
			}
		}
	}
	STAT(0x26c,hotel_e_b991ab);
	if (hotel_b9b17b[hackType].flag)
	{
		if (!hotel_cf45d8.getField_46dd90())
			OpX5_addUniqueString(&hotel_d257c0,h2s_d2d508[hackType]);
		if (hotel_cefb48)
			hotel_cefb48->say(0x29,0,string(hotel_e_b991b9));
	}
	int interfaceType = machine->getInfo_9b8f00()->type;
	if (interfaceType < 6)
		STAT(machine->getInfo_9b8f00()->type + 0x272,hotel_e_b991ba);
	machine->getData_45cb30()->f28 += 1;
	if (machine->getData_45cb30()->f28 == 1)
	{
		STAT(0x265,hotel_e_b991bb);
		if (interfaceType < 6)
		{
			STAT(machine->getInfo_9b8f00()->type + 0x266,hotel_e_b99203);
			int total = 0;
			for (int i = 0; i < 6; i++)
				total += (*h2s_d2c658.values)[i + 0x266];
			if (total == 10)
				hotel_cf45d8.unknown77fbc0(0x52);
			else if (total == 50)
				hotel_cf45d8.unknown77fbc0(0xb2);
		}
	}
	bool sealed = !hotel_cec0fc->unknown4afdc0(hackType);
	int diff = sealed ? 0 : hotel_cefc4c->unknown71adc0(hotel_cefc4c->getPlayer(),machine,record,hackType,record ? record->index : index,hackType == 0x42 ? rec8 : hotel_cec0fc->unknown4afce0(),hackType == 0x42 ? rec4 : hotel_cec0fc->unknown4afd50(),hotel_cec0fc->getItem_4afcc0(true));
	int dice = machine->getData_45cb30()->bag->draw();
	if (diff <= 0 && dice <= diff)
		dice = diff + 1;
	int unknown4748 = 0;
	int preBonus = hotel_cf6a24 && machine->getInfo_9b8f00()->type < 6 ? !(hotel_cf6a50 - 1) + 1 : 0;
	int secondBonus = hotel_cf6a24 && machine->getInfo_9b8f00()->type < 6 ? !(hotel_cf6a58 - 1) + 1 : 0;
	string msg;
	bool hackPassed;
	bool passed;
	if (dice <= diff && (record == NULL && hackType <= 4 || hackType == 0x60) && hotel_cefc4c->opw3_unknown7272e0())
	{
		hackPassed = false;
		passed = false;
		if (h2s_d25450.b0)
		{
			hotel_d254d0 = 0x70;
			hotel_d254d4 = 0;
		}
		hotel_cefc4c->unknown464a60();
		msg = "Central database compromised, local access revoked.";
		STAT(0x270,hotel_e_b99333);
		addNew(name,msg,2,-1,0);
		if (hotel_d1e888->depth != 10)
		{
			string alert("ALERT: Central database lockdown, local access denied.");
			H2_ALERT(alert);
			LOG0(0x6f);
		}
		if (hackType == 0x60)
			hotel_cec0fc->unknown4afc40(0x60)->unknown4afab0(1);
	}
	else if (dice <= diff)
	{
		hackPassed = true;
		passed = true;
		STAT(0x26d,hotel_e_b99359);
		if (hotel_b9b798[hackType] != 0)
			hotel_cf6888.unknown6998a0(3,hotel_b9b798[hackType] + hotel_ba4514[hotel_d1e888->depth].value,0);
		if (h2s_d25450.b0)
		{
			hotel_d254d0 = 0x70;
			hotel_d254d4 = 0;
		}
		unknownEc++;
		if (unknownEc == 10 && machine->getInfo_9b8f00()->type == 0)
			hotel_cf45d8.unknown77fbc0(0xb4);
		if (record == NULL && hackType != 0)
		{
			unknownF0++;
			if (unknownF0 == 3 && machine->getInfo_9b8f00()->type == 0)
				hotel_cf45d8.unknown77fbc0(0xb5);
		}
		if (!hotel_b9b17b[hackType].flag)
		{
			if (OpT8b_Fn9daf80(0,hackType,0x40))
			{
				STAT(0x278,hotel_e_b9935a);
				STAT(hackType + 0x279,hotel_e_b9935b);
			}
			else if (OpT8b_Fn9daf80(0x41,hackType,0x4b))
			{
				STAT(0x2b0,hotel_e_b99379);
				STAT(hackType + 0x270,hotel_e_b9937a);
			}
			else if (OpT8b_Fn9daf80(0x4c,hackType,0x50))
			{
				STAT(0x2b4,hotel_e_b9937b);
				STAT(hackType + 0x269,hotel_e_b99395);
			}
			else if (OpT8b_Fn9daf80(0x51,hackType,0x5d))
			{
				STAT(0x2b8,hotel_e_b99396);
				STAT(hackType + 0x268,hotel_e_b99397);
			}
			else if (OpT8b_Fn9daf80(0x5e,hackType,0x62))
			{
				STAT(0x2be,hotel_e_b993a3);
				STAT(hackType + 0x261,hotel_e_b993af);
			}
			else if (OpT8b_Fn9daf80(0x63,hackType,0x6e))
			{
				STAT(0x2c2,hotel_e_b993bb);
				STAT(hackType + 0x260,hotel_e_b993fe);
			}
		}
		switch (hackType)
		{
						case 0:
			{
				H2sRec0 *robot = h2s_d35b58[record ? record->index : index];
				string text(robot->f3c);
				hotel_decode_4351e0(&text);
				addNew(name,text,1,record ? record->index : index,0);
				hotel_cf4924[record ? record->index : index] += 1;
				if ((*h2s_d2c658.values)[0x279] == 10)
					hotel_cf45d8.unknown77fbc0(0x53);
				if (robot->name == "Cogmind")
					hotel_cf45d8.unknown77fbc0(0x16b);
				if (robot->f20 != 0x70 && !hotel_cf45d8.getField_46dd90())
					OpX5_addUniqueString(&hotel_d257c0,h2s_d2d508[robot->f20]);
				if (!hotel_cf45d8.getField_46dd90())
				{
					for (unsigned int i = 0; i < hotel_d02cb4.size(); i++)
					{
						if (hotel_d02cb4[i]->robot == robot)
						{
							hotel_d02cb4[i]->known = true;
							break;
						}
					}
				}
				if (robot->f74 != 0)
				{
					if (robot->f78.empty())
						LOG0(robot->f74);
					else
						LOGP(robot->f74,robot->f78);
				}
				if (!robot->f94.empty())
				{
					string data(robot->f94);
					hotel_decode_4351e0(&data);
					if (data.find(hotel_d2ec34,0) == 0)
						hotel_cefc4c->unknown6c6660(data);
					else
						hotel_prelearn_data(data,0);
				}
				if (0) {}
				hotel_unknown91c850(hackType,&preBonus,&secondBonus,robot->name);
				if (h2s_d25450.b0 && robot->name == "S1/0523A")
				{
					int portrait = h2s_d25450.unknown69e700(0x4f,0,0.0f);
					if (portrait != 6)
						opG1_showXomPortrait(portrait);
				}
				break;
			}

			case 1:
			{
				rec8 = h2s_d2d1c4[record ? record->index : index];
				if (preBonus == 2)
				{
					unknown90f990();
					preBonus = 3;
					H2sRec8 *previous = rec8;
					rec8 = NULL;
					if (rng.chance(50))
					{
						rec8 = jl_cefc4c->selectRandomItemOfRating(1,0,0,0x1f,0x12,0x2a,0);
						if (rec8 == previous)
							rec8 = NULL;
					}
					if (rec8 == NULL)
					{
						vector<string> lines;
						lines.push_back("Bingo!");
						lines.push_back("We have a winner!");
						lines.push_back("Hacked A Terminal And All I Got Was This Lousy");
						lines.push_back("Congratulations on your consolation prize:");
						lines.push_back("Congratulations on your very own...");
						lines.push_back("Sorry, we're short on schematics right now...");
						lines.push_back("Sorry but we couldn't find anything funnier:");
						lines.push_back("Hm, what have we here...");
						lines.push_back("Take it! It's all yours!");
						lines.push_back("Don't use it all in one place now:");
						lines.push_back("Enjoy :D");
						msg += OpU8a_randomString(lines);
						msg += "\n  " + (rng.chance(5) ? OpU8a_randomString(jl_d37a40) : opR1f_465bc0());
						msg += "\n  Rating: " + intToString(rng.rangeInt(0,11));
						if (rng.chance(20))
							msg += "p";
						msg += "\nSchematic corrupted.";
						addNew(name,msg,1,-1,0);
						break;
					}
				}
				msg += "Downloading schematic...";
				msg += "\n  " + rec8->search;
				msg += "\n  Rating: " + intToString(rec8->f50);
				if (rec8->f94 != 0)
					msg += "p";
				if (h2s_cf4844[rec8->index] != 0)
					msg += "\nExisting schematic match found.";
				else
				{
					msg += "\nSchematic downloaded.";
					if (h2s_cf45d8.unknown780380(rec8->index,h2s_cec0f8->getMachine_4b1460()->getInfo_9b8f00()->type != 6))
						h2s_cec08c->reopen8a2ce0(4,H2sHEntity());
				}
				addNew(name,msg,1,-1,0);
				hotel_unknown91c850(hackType,&preBonus,&secondBonus,rec8->search);
				break;
			}

			case 2:
			{
				rec4 = h2s_d25de0[record ? record->index : index];
				if (preBonus == 2)
				{
					unknown90f990();
					preBonus = 3;
					H2sRec4 *previous = rec4;
					rec4 = NULL;
					if (rng.chance(50))
					{
						rec4 = h2s_cefc4c->unknown6c5180();
						if (rec4 == previous)
							rec4 = NULL;
					}
					if (rec4 == NULL)
					{
						vector<string> lines;
						lines.push_back("Bingo!");
						lines.push_back("We have a winner!");
						lines.push_back("Hacked A Terminal And All I Got Was This Lousy");
						lines.push_back("Congratulations on your consolation prize:");
						lines.push_back("Congratulations on your very own...");
						lines.push_back("Sorry, we're short on schematics right now...");
						lines.push_back("Sorry but we couldn't find anything funnier:");
						lines.push_back("Hm, what have we here...");
						lines.push_back("Take it! It's all yours!");
						lines.push_back("Don't use it all in one place now:");
						lines.push_back("Enjoy :D");
						msg += OpU8a_randomString(lines);
						msg += "\n  " + OpU8a_randomString(jl_d30540);
						msg += "\n  Tier: " + intToString(rng.rangeInt(0,11));
						if (rng.chance(20))
							msg += "p";
						msg += "\nSchematic corrupted.";
						addNew(name,msg,1,-1,0);
						break;
					}
				}
				msg += "Downloading schematic...";
				msg += "\n  " + rec4->f1ac;
				msg += "\n  Tier: " + intToString(rec4->f68);
				if (h2s_cf4888[rec4->index] != 0)
					msg += "\nExisting schematic match found.";
				else
				{
					msg += "\nSchematic downloaded.";
					h2s_cf45d8.unknown780480(rec4->index,h2s_cec0f8->getMachine_4b1460()->getInfo_9b8f00()->type != 6);
				}
				addNew(name,msg,1,-1,0);
				hotel_unknown91c850(hackType,&preBonus,&secondBonus,rec4->f1ac);
				break;
			}

			case 3:
			{
				rec4 = h2s_d25de0[record ? record->index : index];
				if (preBonus == 2)
				{
					unknown90f990();
					preBonus = 3;
					H2sRec4 *previous = rec4;
					rec4 = NULL;
					if (rng.chance(50))
					{
						rec4 = h2s_cefc4c->unknown6c5180();
						if (rec4 == previous)
							rec4 = NULL;
					}
					if (rec4 == NULL)
					{
						vector<string> lines;
						lines.push_back("These are everywhere!");
						lines.push_back("Glorious!");
						lines.push_back("You love to see it.");
						lines.push_back("Good luck finding this one.");
						lines.push_back("You just have to look in the right places.");
						lines.push_back("Heard of this one before?");
						lines.push_back("You have to see it to believe it.");
						lines.push_back("Found a good one.");
						lines.push_back("This one's great.");
						lines.push_back("This might be come in handy.");
						lines.push_back("Let me know if you find it useful!");
						msg += OpU8a_randomString(lines);
						msg += "\n  " + OpU8a_randomString(jl_d30540);
						msg += "\n  Tier: " + intToString(rng.rangeInt(0,11));
						msg += "\n\nNO_DATA?";
						addNew(name,msg,1,-1,0);
						break;
					}
				}
				msg += "Downloading analysis...";
				msg += "\n  " + rec4->f1ac;
				vector<int> tiers;
				tiers.push_back(rec4->f68);
				if (!rec4->f2c.empty())
				{
					for (unsigned int i = 0; i < h2s_d25de0.size(); i++)
					{
						if (h2s_d25de0[i]->f2c == rec4->f2c)
							OpT8b_Fn9db000(tiers,h2s_d25de0[i]->f68);
					}
				}
				if (tiers.size() == 1)
					msg += "\n  Tier: " + intToString(tiers.front());
				else
				{
					msg += "\n  Tiers: ";
					for (unsigned int i = 0; i < tiers.size(); i++)
					{
						if (i != 0)
							msg += ", ";
						msg += intToString(tiers[i]);
					}
				}
				if (h2s_cf4910[rec4->index] != 0)
					msg += "\nExisting analysis record match found:";
				else
				{
					h2s_cf45d8.unknown780700(rec4->index,1);
					jl_cf4d24++;
					if (jl_cf4d24 >= 3)
						hotel_cf45d8.unknown77fbc0(0x54);
					for (unsigned int i = 0; i < h2s_d25de0.size(); i++)
					{
						if (h2s_d25de0[i]->f1ac == rec4->f1ac && !h2s_d25de0[i]->f170.empty())
							h2s_cf45d8.unknown780700(i,0);
					}
					if (!hotel_cf45d8.getField_46dd90())
					{
						for (int i = hotel_d02cb4.size() - 1; i >= 0; i--)
						{
							if (hotel_d02cb4[i]->analysis == rec4)
							{
								hotel_d02cb4[i]->known = true;
								break;
							}
						}
					}
				}
				msg += "\n";
				msg += rec4->f170;
				addNew(name,msg,1,-1,0);
				hotel_unknown91c850(hackType,&preBonus,&secondBonus,rec4->f1ac);
				break;
			}

			case 4:
			{
				int count = record ? record->index : index;
				if (preBonus == 2)
				{
					unknown90f990();
					preBonus = 3;
					msg += "Downloading prototype IDs...";
					vector<string> ids;
					for (int i = 0; i < count; i++)
					{
						string id;
						do
						{
							id = opR1f_465bc0();
						}
						while (OpU8a_containsString(ids,id));
						ids.push_back(id);
						msg += "\n  " + id;
					}
					addNew(name,msg,1,-1,0);
					break;
				}
				vector<int> candidates;
				int low = OpX5_maxInt(0,jl_d1e860.getDepthIndex() - 1);
				int high5 = OpX5_minInt(10,jl_d1e860.getDepthIndex() + 1);
				for (int i = 0; i < h2s_d2d1c4.size(); i++)
				{
					if (h2s_d2d1c4[i]->f94 == 1 && OpT8b_Fn9daf80(low,h2s_d2d1c4[i]->f50,high5) && (h2s_d2d1c4[i]->f54 == 1 || h2s_d2d1c4[i]->f54 == 2))
						candidates.push_back(i);
				}
				if (candidates.size() < count)
					count = candidates.size();
				bool found3 = false;
				msg += "Downloading prototype IDs...";
				for (int i = 0; i < count; i++)
				{
					int pick = jl_randomIndex_9d9b20(candidates);
					msg += "\n  " + h2s_d2d1c4[candidates[pick]]->search;
					if (jl_cf4830[candidates[pick]] == 0 && jl_cf45d8.unknown77ffb0(candidates[pick],0))
						found3 = true;
					removeVectorElement(candidates,pick);
					if (candidates.empty())
						break;
				}
				if (found3)
					h2s_cec08c->reopen8a2ce0(4,H2sHEntity());
				addNew(name,msg,1,-1,0);
				hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				break;
			}

			case 5:
			{
				vector<Pos> doors;
				hotel_collectProps_517ae0(machine->getId_44ab40(),&doors,false,2,0);
				if (doors.empty())
				{
					msg = "Door malfunction.";
					addNew(name,msg,3,-1,0);
				}
				else
				{
					string doorName((*h2s_cfd44c.atPoint(doors.front()))->getProp_45d550()->getName_45c5b0());
					int effect;
					if (hotel_lookup_9d7980("P_Machine_Door_Open",&effect))
					{
						for (unsigned int i = 0; i < doors.size(); i++)
						{
							if (hotel_cefc4c->isVisible_4631c0(doors[i]))
								hotel_cefc50->unknown508610(hotel_cefc50,effect,doors[i],hotel_d2e20c,0,0,0,9,0)->init_503b20();
							(*h2s_cfd44c.atPoint(doors[i]))->getProp_45d550()->unknown45ce10(1,0,1,H2sHProp());
						}
					}
					opR1d_4541b0(0x7e,0,0);
					msg = doorName + " opened.";
					addNew(name,msg,1,-1,0);
				}
				break;
			}

			case 6:
			{
				if (!jl_cf6458)
				{
					msg = "All DSF locations in lockdown mode.";
					addNew(name,msg,3,-1,0);
				}
				else
				{
					H2sAccess *access = h2s_cefc4c->unknown462fd0(machine);
					Pos pos3(access->pos);
					string trapName2;
					if ((*h2s_cfd44c.atPoint(pos3))->getProp_45d550().isValid() && (*h2s_cfd44c.atPoint(pos3))->getProp_45d550()->isTrap_45cb70())
						trapName2 = (*h2s_cfd44c.atPoint(pos3))->getProp_45d550()->getName_45c5b0();
					int stairs2 = OpU8a_indexOfName4(jl_cfb844,"STAIRS_DSF_OPEN");
					(*h2s_cfd44c.atPoint(pos3))->unknown66a050(stairs2,2,0);
					h2s_cefc4c->announceMachine_71dd30(access->owner);
					h2s_cefc4c->unknown4647a0(pos3,true);
					access->b0d = true;
					if ((*h2s_cfd44c.atPoint(pos3))->getItem().isValid())
					{
						vector<Pos> points(1,pos3);
						jl_cefc4c->unknown71ec60(pos3,points);
					}
					unknownA8.push_back(pos3);
					msg = "DSF access unlocked.";
					addNew(name,msg,1,-1,0);
					access->unknown6c16d0("UNLOCKED");
					opR1d_454260(pos3,0x82);
					if (!trapName2.empty())
					{
						string text = trapName2 + " rendered useless by plates shifting to reveal entrance.";
						do
						{
							if (opS2_showMessage_5111e0(0x206,&text,0,0,H2sHEntity(),H2sHEntity(),&pos3,0))
								hotel_cec058->bubble(1);
							hotel_cec0b4->scrollToEnd();
						}
						while (0);
						unknown90ec30(text);
					}
				}
				break;
			}

			case 7:
			{
				if (preBonus == 2)
				{
					vector<H2sAccess *> *list = h2s_cefc4c->getAccess_462e10();
					for (unsigned int i = 0; i < list->size(); i++)
					{
						if ((*list)[i]->owner->inRange_46ecb0() && (*list)[i]->f10 == 2)
						{
							(*list)[i]->f10 = !rng.chance(50);
							if ((*list)[i]->f10 == 0)
								preBonus = 3;
						}
					}
				}
				int found2 = 0;
				int depth;
				vector<H2sAccess *> *access = h2s_cefc4c->getAccess_462e10();
				for (unsigned int i = 0; i < access->size(); i++)
				{
					if ((*access)[i]->owner->inRange_46ecb0() && (*access)[i]->f10 != 0)
					{
						depth = (*access)[i]->owner->f4;
						found2++;
					}
				}
				if (found2 == 0)
				{
					msg = "No level access points found.";
					h2s_cefc4c->unknown464ab0();
				}
				else
				{
					if (h2s_d1e888->f4 == 0xd)
						msg = "Found " + opw8_countString(found2,"main access point") + ":";
					else
						msg = "Found " + opw8_countString(found2,"level access point") + " to " + h2s_mapNames_cfaca0[depth] + ":";
					for (unsigned int i = 0; i < access->size(); i++)
					{
						if ((*access)[i]->owner->inRange_46ecb0() && (*access)[i]->f10 != 0)
						{
							msg += "\n  " + OpQ1_pointToString((*access)[i]->pos);
							h2s_cefc4c->announceMachine_71dd30((*access)[i]->owner);
							h2s_cefc4c->unknown4647a0((*access)[i]->pos,true);
							(*access)[i]->b0d = true;
							unknownA8.push_back((*access)[i]->pos);
						}
					}
					msg += "\nMap updated.";
				}
				addNew(name,msg,1,-1,0);
				if (found2 != 0)
					hotel_unknown91c850(hackType,&preBonus,&secondBonus,h2s_mapNames_cfaca0[depth]);
				break;
			}

			case 8:
			{
				if (preBonus == 2)
				{
					vector<H2sAccess *> *list = h2s_cefc4c->getAccess_462e10();
					for (unsigned int i = 0; i < list->size(); i++)
					{
						if ((*list)[i]->unknown6c1a10() && (*list)[i]->f10 == 2)
						{
							(*list)[i]->f10 = !rng.chance(50);
							if ((*list)[i]->f10 != 0)
								preBonus = 3;
						}
					}
				}
				int found4 = 0;
				vector<H2sAccess *> *access = h2s_cefc4c->getAccess_462e10();
				for (unsigned int i = 0; i < access->size(); i++)
				{
					if ((*access)[i]->unknown6c1a10() && (*access)[i]->f10 != 0)
						found4++;
				}
				if (found4 == 0)
				{
					msg = "No branch access points found.";
					h2s_cefc4c->unknown464ad0();
				}
				else
				{
					msg = "Found " + opw8_countString(found4,"branch access point") + ":";
					for (unsigned int i = 0; i < access->size(); i++)
					{
						if ((*access)[i]->unknown6c1a10() && (*access)[i]->f10 != 0)
						{
							msg += "\n  " + OpQ1_pointToString((*access)[i]->pos) + " " + h2s_mapNames_cfaca0[(*access)[i]->owner->f4];
							h2s_cefc4c->announceMachine_71dd30((*access)[i]->owner);
							h2s_cefc4c->unknown4647a0((*access)[i]->pos,true);
							(*access)[i]->b0d = true;
							unknownA8.push_back((*access)[i]->pos);
						}
					}
					msg += "\nMap updated.";
				}
				addNew(name,msg,1,-1,0);
				if (found4 != 0)
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				break;
			}

			case 9:
			{
				bool mainLevel = h2s_d1e888->f4 == 0xd;
				vector<Pos> doors;
				if (mainLevel)
				{
					for (int x = 0; x < h2s_cfd44c.getMaxX(); x++)
					{
						for (int y = 0; y < h2s_cfd44c.getMaxY(); y++)
						{
							if ((*h2s_cfd44c.at(x,y))->isEdge_45dc30())
								doors.push_back(Pos(x,y));
						}
					}
				}
				else
				{
					Pos origin2(*machine->getPosition_4184d0());
					clearDijkstraResults();
					int flag = 1;
					jl_cfe568.unknown40ca20(origin2,0x18,jl_d297a8,&flag);
					doors = jl_d15e58;
				}
				if (preBonus == 2 && !doors.empty())
				{
					for (int i = 0; i < doors.size(); i++)
					{
						if (OpV4c_Fn9d0ce0Pos(jl_cf6a60,doors[i]))
							OpQ5_eraseStep_9d7300(doors,i);
						else if (OpV4c_Fn9d0ce0Pos(jl_cf6a70,doors[i]))
							continue;
						else if (rng.chance(50))
						{
							jl_cf6a60.push_back(doors[i]);
							OpQ5_eraseStep_9d7300(doors,i);
							preBonus = 3;
						}
						else
							jl_cf6a70.push_back(doors[i]);
					}
				}
				if (doors.empty())
					msg = mainLevel ? "No phase walls or emergency access doors found in local area." : "No emergency access doors found in local area.";
				else
				{
					msg = mainLevel ? "Found " + opw8_countString(doors.size(),"emergency access point") + "." : "Found " + opw8_countString(doors.size(),"emergency access door") + ":";
					for (unsigned int i = 0; i < doors.size(); i++)
					{
						if (!mainLevel)
							msg += "\n  " + OpQ1_pointToString(doors[i]);
						h2s_cefc4c->unknown734d60(doors[i]);
						bool opened = false;
						if ((*h2s_cfd44c.atPoint(doors[i]))->unknown45dbb0())
						{
							(*h2s_cfd44c.atPoint(doors[i]))->unknown670690();
							opened = true;
						}
						h2s_cefc4c->unknown4647a0(doors[i],true);
						if (opened)
							(*h2s_cfd44c.atPoint(doors[i]))->unknown670b20();
					}
					unknownB8 = doors;
					msg += "\nMap updated.";
				}
				addNew(name,msg,1,-1,0);
				if (!doors.empty())
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				break;
			}

			case 10:
			{
				vector<vector<Pos> > *machines = h2s_cefc4c->unknown459070();
				int total = 0;
				for (int i = 0; i < 6; i++)
					total += (*machines)[i].size();
				if (total != 0)
				{
					msg = "Found " + opw8_countString(total,"machine") + ":";
					vector<H2sHMarker> &markers = (*h2s_cefc4c->unknown463ec0())[0];
					for (int i = 0; i < markers.size(); i++)
					{
						if (markers[i]->f14 < 6)
							OpQ5_eraseStep_9d6440(markers,i);
					}
					unknownD8 = true;
					for (int i = 0; i < 6; i++)
					{
						if ((*machines)[i].size() != 0)
						{
							string count = intToString((*machines)[i].size());
							padLeft_408090(count,4,' ');
							msg += "\n" + count + " " + jl_d3a280[i];
							if ((*machines)[i].size() > 1)
								msg += jl_d3a280[i][jl_d3a280[i].size() - 1] == 's' ? "es" : "s";
							for (unsigned int j = 0; j < (*machines)[i].size(); j++)
							{
								markers.push_back(h2s_cefaa8->createC_793190());
								markers.back()->unknown6c20b0(0,(*machines)[i][j],i);
							}
						}
					}
					msg += "\nDownloaded coordinate data.";
				}
				else
					msg = "No machines found.";
				addNew(name,msg,1,-1,0);
				if (total != 0)
					hotel_unknown91c850(hackType,&preBonus,&secondBonus,intToString(total));
				break;
			}

			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
			case 16:
			{
				int kind = hackType - 11;
				vector<H2sHMarker> &markers = (*h2s_cefc4c->unknown463ec0())[0];
				for (int i = 0; i < markers.size(); i++)
				{
					if (markers[i]->f14 == kind)
					{
						if ((*h2s_cfd44c.atPoint(markers[i]->pos))->unknown66b360())
							continue;
						OpQ5_eraseStep_9d6440(markers,i);
					}
				}
				vector<Pos> &list8 = (*h2s_cefc4c->unknown459070())[kind];
				int found8 = 0;
				for (unsigned int i = 0; i < list8.size(); i++)
				{
					if ((*h2s_cfd44c.atPoint(list8[i]))->unknown66b360())
						continue;
					found8++;
					markers.push_back(h2s_cefaa8->createC_793190());
					markers.back()->unknown6c20b0(0,list8[i],kind);
				}
				if (found8 != 0)
				{
					msg = "Found " + opw8_countString(found8,jl_cf3fb0[kind]) + ".";
					msg += "\nDownloaded coordinate data.";
					unknownD8 = true;
				}
				else
					msg = "No " + jl_cf3fb0[kind] + (jl_cf3fb0[kind][jl_cf3fb0[kind].size() - 1] == 's' ? "es" : "s") + " found.";
				addNew(name,msg,1,-1,0);
				if (found8 != 0)
					hotel_unknown91c850(hackType,&preBonus,&secondBonus,intToString(found8));
				break;
			}

			case 17:
			{
				msg = "Current Alert Level: ";
				if (preBonus != 0)
				{
					vector<string> levels;
					if (jl_cf6474 != 0)
					{
						levels.push_back("Warmish");
						levels.push_back("Lukewarm");
					}
					else if (jl_cf645c != 0)
						levels.push_back("!FUN!");
					else
					{
						switch (opr1c_getThresholdIndex(jl_cf6428))
						{
							case 0:
								levels.push_back("Green");
								levels.push_back("Laughable");
								levels.push_back("Not A Troublemaker?!");
								levels.push_back("Baby Mode");
								break;
							case 1:
								levels.push_back("Yellow");
								levels.push_back("Enjoyable");
								levels.push_back("Dissapointingly Low");
								levels.push_back("Weakling");
								break;
							case 2:
								levels.push_back("Red");
								levels.push_back("Unfriendly");
								levels.push_back("Who Wants To Know?");
								levels.push_back("Bad Boy");
								break;
							case 3:
								levels.push_back("Purple");
								levels.push_back("Just Right");
								levels.push_back("Promising");
								levels.push_back("Tough Nut");
								break;
							case 4:
								levels.push_back("Black");
								levels.push_back("Outrageous");
								levels.push_back("Popular");
								levels.push_back("Really Really High");
								break;
							case 5:
								levels.push_back("Brimstone");
								levels.push_back("Impossible");
								levels.push_back("Are We Winning Yet?");
								levels.push_back("I Want My Mommy");
								break;
						}
					}
					msg += OpU8a_randomString(levels);
				}
				else if (jl_cf6474 != 0)
					msg += "Sterilization";
				else if (jl_cf645c != 0)
					msg += jl_cf6468 ? "Maximum Security" : "High Security";
				else
					msg += opr1c_getSecurityName_4332b0(jl_cf6428);
				addNew(name,msg,1,-1,0);
				passed = false;
				hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				break;
			}

			case 18:
			{
				if (jl_cf6474 != 0 || jl_cf645c != 0)
					addNew(name,string("Remote reporting system inaccessible."),2,-1,0);
				else
				{
					bool purged = false;
					if (jl_cf6428 == 0)
						msg = "No threats on record.";
					else if (preBonus == 2)
					{
						unknown90f990();
						jl_ovm_cf6428.unknown682420(0x1f,0);
						msg = "Added threat record, spice level increased.";
						passed = false;
						preBonus = 3;
					}
					else
					{
						jl_ovm_cf6428.unknown682420(0x27,0);
						msg = "Purged threat record, alert level lowered.";
						passed = false;
						hotel_cf45d8.unknown77fbc0(0x55);
						purged = true;
					}
					addNew(name,msg,1,-1,0);
					if (purged)
						hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				}
				break;
			}

			case 19:
			case 20:
			case 21:
			{
				if (jl_cf4744 != 0)
				{
					addNew(name,string("Trapped!"),1,-1,0);
					break;
				}
				bool updated2 = false;
				Pos origin(*machine->getPosition_4184d0());
				clearDijkstraResults();
				int curFlag = 1;
				jl_cfe568.unknown40ca20(origin,0x18,jl_cfd428,&curFlag);
				vector<Pos> *traps = &jl_d15e58;
				if (traps->empty())
				{
noTraps:
					msg = "No traps found in local area.";
				}
				else
				{
					vector<int> groups;
					for (unsigned int i = 0; i < traps->size(); i++)
						OpT8b_Fn9db000(groups,(*h2s_cfd44c.atPoint((*traps)[i]))->getProp_45d550()->getTrap_44b020()->f4);
					if (preBonus == 2 && !groups.empty())
					{
						for (unsigned int i = 0; i < groups.size(); i++)
						{
							switch (jl_d3239c[groups[i]])
							{
								case 0:
									OpT8a_eraseAt(groups,i);
									break;
									break;
								case 2:
									jl_d3239c[groups[i]] = !rng.chance(50);
									if (jl_d3239c[groups[i]] == 0)
									{
										OpT8a_eraseAt(groups,i);
										preBonus = 3;
									}
									break;
							}
						}
						if (groups.empty())
							goto noTraps;
					}
					traps->clear();
					for (unsigned int i = 0; i < groups.size(); i++)
					{
						for (unsigned int j = 0; j < h2s_d20248[groups[i]].size(); j++)
							traps->push_back(*h2s_d20248[groups[i]][j]->getPosition_4184d0());
					}
					if (hackType == 19)
					{
						msg = "Found " + opw8_countString(traps->size(),"trap") + " in " + opw8_countString(groups.size(),"array") + ":";
						for (unsigned int i = 0; i < groups.size(); i++)
						{
							msg += "\n  " + intToString(h2s_d20248[groups[i]].size()) + "x " + h2s_d20248[groups[i]].front()->getName_45c5b0();
							for (unsigned int j = 0; j < h2s_d20248[groups[i]].size(); j++)
							{
								h2s_d20248[groups[i]][j]->unknown65f170();
								h2s_cefc4c->unknown4647d0(*h2s_d20248[groups[i]][j]->getPosition_4184d0());
							}
						}
						jl_appendUnique_9d80a0(unknownC8,*traps);
						for (unsigned int i = 0; i < traps->size(); i++)
							h2s_cefc4c->unknown9e29b0(h2s_cefc4c->f720,(*h2s_cfd44c.atPoint((*traps)[i]))->getProp_45d550());
						msg += "\nMap updated.";
						updated2 = true;
					}
					else
					{
						vector<int> candidates;
						for (unsigned int i = 0; i < groups.size(); i++)
						{
							for (unsigned int j = 0; j < h2s_d20248[groups[i]].size(); j++)
							{
								if (h2s_d20248[groups[i]][j]->getTrap_44b020()->f10 == 3)
								{
									candidates.push_back(groups[i]);
									break;
								}
							}
						}
						if (candidates.empty())
							msg = "No applicable traps found in local area.";
						else
						{
							vector<H2sHProp> props(h2s_d20248[OpU8a_randomRec(candidates)]);
							string trapName(props.front()->getName_45c5b0());
							int count = 0;
							for (unsigned int i = 0; i < props.size(); i++)
							{
								if (props[i]->getTrap_44b020()->f10 == 3)
								{
									if (hackType == 21)
									{
										STAT(0x24e,hotel_e_b994f5);
										props[i]->getTrap_44b020()->f10 = 0;
										props[i]->getTrap_44b020()->fc = h2s_cefc4c->getPlayer();
										props[i]->unknown65f170();
										h2s_cefc4c->unknown4647d0(*props[i]->getPosition_4184d0());
										OpV4c_Fn9d3020Pos(unknownC8,*props[i]->getPosition_4184d0());
										h2s_cefc4c->unknown9e29b0(h2s_cefc4c->f720,props[i]);
										count++;
									}
									else
									{
										STAT(0x24d,hotel_e_b994f6);
										Pos at(*props[i]->getPosition_4184d0());
										(*h2s_cfd44c.atPoint(at))->removeProp_66c100(false,4);
										h2s_cefc4c->unknown4647a0(at,true);
										count++;
									}
								}
							}
							msg = (hackType == 21 ? "Reprogrammed " : "Disarmed ") + opw8_countString(count,trapName) + ".";
							passed = false;
							updated2 = true;
						}
					}
				}
				addNew(name,msg,1,-1,0);
				if (updated2)
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				break;
			}

			case 22:
			{
				vector<int> counts(11u,0);
				for (unsigned int i = 0; i < h2s_cf6478.size(); i++)
				{
					if (!h2s_cf6478[i]->test_45e820())
						counts[h2s_cf6478[i]->faction] += 1;
				}
				msg += "Retrieving dispatch records...";
				int total = OpT8a_sumVector(counts);
				if (total == 0)
					msg += "\nNo active records found.";
				else
				{
					msg += "\nFound " + opw8_countString(total,"active squad") + ":";
					for (int i = 0; i < 11; i++)
					{
						if (counts[i] != 0)
							msg += "\n  " + intToString(counts[i]) + "x " + jl_cf25d8[i];
					}
				}
				addNew(name,msg,1,-1,0);
				if (total != 0)
					hotel_unknown91c850(hackType,&preBonus,&secondBonus,intToString(total));
				break;
			}

			case 23:
			{
				vector<H2sHEntity> bots;
				vector<H2sHEntity> *members = h2s_cefc4c->unknown463890(4)->getMembers_416f40();
				vector<int> counts3(97u,0);
				for (unsigned int i = 0; i < members->size(); i++)
				{
					switch ((*members)[i]->getFaction_45a2c0())
					{
						case 1:
						case 2:
						case 3:
						case 5:
						case 8:
							bots.push_back((*members)[i]);
							counts3[(*members)[i]->getFaction_45a2c0()] += 1;
							break;
					}
				}
				int total = OpT8a_sumVector(counts3);
				msg += "Found " + opw8_countString(total,"registered maintenance bot") + ".";
				vector<H2sHMarker> &markers = (*h2s_cefc4c->unknown463ec0())[1];
				markers.clear();
				for (int i = 0; i < 97; i++)
				{
					if (counts3[i] != 0)
					{
						msg += "\n  " + intToString(counts3[i]) + " " + h2s_robotClassNames_d2f798[i];
						if (counts3[i] > 1)
							msg += "s";
					}
				}
				if (total != 0)
				{
					msg += "\nDownloaded coordinate data.";
					for (unsigned int i = 0; i < bots.size(); i++)
					{
						markers.push_back(h2s_cefaa8->createC_793190());
						markers.back()->unknown6c20b0(1,bots[i]->unknown45a4c0(),-1);
					}
					unknownD8 = true;
				}
				addNew(name,msg,1,-1,0);
				if (total != 0)
					hotel_unknown91c850(hackType,&preBonus,&secondBonus,intToString(total));
				break;
			}

			case 24:
			case 25:
			case 26:
			case 27:
			case 28:
			case 29:
			case 30:
			case 31:
			case 32:
			case 33:
			case 34:
			{
				Pos origin(*machine->getPosition_4184d0());
				int faction = hackType - 24;
				int layer2 = hackType - 22;
				vector<H2sHMarker> &markers3 = (*h2s_cefc4c->unknown463ec0())[layer2];
				int found = 0;
				msg += "Retrieving latest reported positions...";
				if (faction == 0)
				{
					msg += "\nSecurity request, restricting to local area...";
					for (int i = 0; i < markers3.size(); i++)
					{
						if (origin.distanceTo_409fb0(markers3[i]->pos) <= 25)
							OpQ5_eraseStep_9d6440(markers3,i);
					}
					for (unsigned int i = 0; i < h2s_cf6478.size(); i++)
					{
						if (h2s_cf6478[i]->faction == faction && !h2s_cf6478[i]->test_45e820() && origin.distanceTo_409fb0(h2s_cf6478[i]->entity->getPosition_45a4a0()) <= 25)
						{
							found++;
							markers3.push_back(h2s_cefaa8->createC_793190());
							markers3.back()->unknown6c20b0(layer2,h2s_cf6478[i]->entity->unknown45a4c0(),-1);
						}
					}
				}
				else
				{
					markers3.clear();
					for (unsigned int i = 0; i < h2s_cf6478.size(); i++)
					{
						if (h2s_cf6478[i]->faction == faction && !h2s_cf6478[i]->test_45e820())
						{
							found++;
							markers3.push_back(h2s_cefaa8->createC_793190());
							markers3.back()->unknown6c20b0(layer2,h2s_cf6478[i]->entity->unknown45a4c0(),-1);
						}
					}
				}
				if (found == 0)
					msg += "\nNo active " + jl_partyTypeNames_d2f350[faction] + " squads found.";
				else
				{
					msg += "\nFound " + opw8_countString(found,"active " + jl_partyTypeNames_d2f350[faction] + " squad") + ".";
					msg += "\nDownloaded coordinate data.";
					unknownD8 = true;
					if (OpT8b_Fn9daf80(0x1c,hackType,0x1f))
						passed = false;
				}
				addNew(name,msg,1,-1,0);
				if (found != 0)
					hotel_unknown91c850(hackType,&preBonus,&secondBonus,intToString(found));
				break;
			}

			case 35:
			case 36:
			case 37:
			case 38:
			{
				int faction = hackType - 31;
				vector<int> squads2;
				for (int i = 0; i < h2s_cf6478.size(); i++)
				{
					if (h2s_cf6478[i]->faction == faction && !h2s_cf6478[i]->test_45e820())
						squads2.push_back(i);
				}
				bool recalled = false;
				msg += "Establishing remote squad link...";
				if (squads2.empty())
					msg += "\nNo tasked " + jl_partyTypeNames_d2f350[faction] + " squads found.";
				else if (h2s_d1e888->f4 == 0x22)
					msg += "\nUnable to override squad orders.";
				else
				{
					string chars("ABCDEFGHIJKLMNOPQRSTUVWXYZ09123456789");
					string id;
					for (int i = 0; i < 10; i++)
						id += randomChar_4085b0(chars);
					msg += "\nRecalled " + jl_partyTypeNames_d2f350[faction] + " squad " + id + ".";
					if (preBonus == 2)
					{
						H2sGuard *squad = h2s_cf6478[OpU8a_randomRec(squads2)];
						squad->f1c = id;
						squad->f18 = h2s_cefc4c->getTurn() + rng.rangeInt(10,25);
						preBonus = 3;
					}
					else
						jl_ovm2_cf6428.unknown68cd80(h2s_cf6478[OpU8a_randomRec(squads2)]);
					passed = false;
					hotel_cf45d8.unknown77fbc0(0x56);
					recalled = true;
				}
				addNew(name,msg,1,-1,0);
				if (recalled)
					hotel_unknown91c850(hackType,&preBonus,&secondBonus,jl_partyTypeNames_d2f350[faction]);
				break;
			}

			case 39:
			{
				vector<H2sHEntity> haulers;
				vector<H2sHEntity> *members = h2s_cefc4c->unknown463890(4)->getMembers_416f40();
				vector<H2sHEntity> *others8 = h2s_cefc4c->unknown463890(3)->getMembers_416f40();
				for (unsigned int i = 0; i < members->size(); i++)
				{
					if ((*members)[i]->getFaction_45a2c0() == 4)
						haulers.push_back((*members)[i]);
				}
				for (unsigned int i = 0; i < others8->size(); i++)
				{
					if ((*others8)[i]->getFaction_45a2c0() == 4)
						haulers.push_back((*others8)[i]);
				}
				bool listed = false;
				msg += "Retrieving manifest data...";
				if (haulers.empty())
					msg += "\nNo active manifests on record.";
				else
				{
					msg += "\nFound " + opw8_countString(haulers.size(),"hauler") + ":";
					for (unsigned int i = 0; i < haulers.size(); i++)
					{
						msg += "\n  " + haulers[i]->getName_416f40();
						int known2 = OpU8a_indexOfEntity(jl_cf6a80,haulers[i]);
						if (known2 != -1)
						{
							for (unsigned int j = 0; j < jl_cf6a90[known2].size(); j++)
								msg += "\n    " + jl_cf6a90[known2][j];
						}
						else
						{
							vector<H2sHItem> items;
							haulers[i]->unknown5cb830(&items);
							if (items.empty())
								msg += "\n    (Empty)";
							else
							{
								for (unsigned int j = 0; j < items.size(); j++)
								{
									int count = 1;
									int total = 0;
									for (unsigned int k = j + 1; k < items.size(); k++)
									{
										if (items[k]->getNestedField() == items[j]->getNestedField())
										{
											count++;
											if (items[k]->getField_457880() == 0)
												total += items[k]->getField_9b6bf0();
											jl_eraseAt_9da940(items,k);
											k--;
										}
									}
									msg += "\n    " + intToString(count) + "x " + items[j]->unknown457990();
									if (items[j]->getField_457880() == 0)
									{
										total += items[j]->getField_9b6bf0();
										msg += " (" + intToString(total) + ")";
									}
								}
							}
						}
						int escorts = 0;
						for (unsigned int j = 0; j < others8->size(); j++)
						{
							if ((*others8)[j]->getAI_45b590()->getFollowEntity_458ed0() == haulers[i])
								escorts++;
						}
						if (escorts != 0)
							msg += "\n    (" + intToString(escorts) + " escort" + (escorts != 1 ? "s)" : ")");
					}
					hotel_cf45d8.unknown77fbc0(0x57);
					listed = true;
				}
				addNew(name,msg,1,-1,0);
				if (listed)
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				break;
			}

			case 40:
			case 41:
			{
				vector<Pos> *spots = h2s_cefc4c->unknown463c20();
				vector<Pos> found6;
				H2sHItem item;
				for (int i = 0; i < spots->size(); i++)
				{
					item = (*h2s_cfd44c.atPoint((*spots)[i]))->getItem();
					if (item.isNull())
						OpQ5_eraseStep_9d7300(*spots,i);
					else
					{
						switch (hackType)
						{
							case 40:
								if (item->stats_9b4350()->f94 == 0)
									found6.push_back((*spots)[i]);
								break;
							case 41:
								if (item->stats_9b4350()->f94 != 0)
									found6.push_back((*spots)[i]);
								break;
						}
					}
				}
				string kind3(hackType == 40 ? "component" : "prototype");
				msg += "Retrieving " + kind3 + " inventory records...";
				if (found6.empty())
					msg += "\nNo registered " + kind3 + " stockpiles.";
				else
				{
					msg += "\nFound " + intToString(found6.size()) + " registered " + kind3 + (found6.size() == 1 ? " stockpile:" : " stockpiles:");
					int layer4 = (hackType != 40) + 14;
					vector<H2sHMarker> &markers = (*h2s_cefc4c->unknown463ec0())[layer4];
					markers.clear();
					string chars("ABCDEFGHIJKLMNOPQRSTUVWXYZ09123456789");
					string theId;
					for (unsigned int i = 0; i < found6.size(); i++)
					{
						theId.clear();
						for (int j = 0; j < 10; j++)
							theId += randomChar_4085b0(chars);
						msg += "\n  " + theId + ": " + (*h2s_cfd44c.atPoint(found6[i]))->getItem()->unknown457990();
						markers.push_back(h2s_cefaa8->createC_793190());
						markers.back()->unknown6c20b0(layer4,found6[i],(*h2s_cfd44c.atPoint(found6[i]))->getItem()->getNestedField());
						h2s_cefc4c->unknown4647d0(found6[i]);
					}
					unknownD8 = true;
					msg += "\nDownloaded coordinate data.";
				}
				addNew(name,msg,1,-1,0);
				if (!found6.empty())
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				break;
			}

			case 42:
			{
				Pos origin(*machine->getPosition_4184d0());
				clearDijkstraResults();
				H2sRect area2;
				h2s_cfd44c.getRect_9b4430(origin,0xf,area2);
				jl_cfe568.unknown40ca20(origin,0x1869f,jl_d2f504,&area2);
				unknownDC = jl_d15e58;
				for (unsigned int i = 0; i < unknownDC.size(); i++)
				{
					h2s_cefc4c->unknown4647a0(unknownDC[i],true);
					if ((*h2s_cfd44c.atPoint(unknownDC[i]))->isMachinePart_45dcd0())
					{
						H2sAccess *zone = h2s_cefc4c->getZone_462e30(unknownDC[i]);
						if (jl_cf4718 == 2)
							h2s_cefc4c->announceMachine_71dd30(zone->owner);
						zone->b0d = true;
						zone->unknown6c16d0("FOUND");
						unknownA8.push_back(unknownDC[i]);
					}
				}
				msg += "Retrieving Zone " + jl_d1e860.generateID_46f890() + " layout...";
				msg += "\nDownloaded map data.";
				addNew(name,msg,1,-1,0);
				hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				break;
			}

			case 43:
			{
				bool done = false;
				if (h2s_d1e888->f4 != 0xd)
					msg += "Data access restricted to Garrison Terminals.";
				else
				{
					vector<H2sHMarker> &markers = (*h2s_cefc4c->unknown463ec0())[2];
					markers.clear();
					for (int x = 0; x < h2s_cfd44c.getMaxX(); x++)
					{
						for (int y = 0; y < h2s_cfd44c.getMaxY(); y++)
						{
							if ((*h2s_cfd44c.at(x,y))->getTerrain_9fcd80() != TERRAIN_EARTH)
							{
								if ((*h2s_cfd44c.at(x,y))->unknown45dcf0())
								{
									(*h2s_cfd44c.at(x,y))->getProp_45d550()->unknown65f170();
									h2s_cefc4c->opw3_unknown724420(x,y);
								}
								else if ((*h2s_cfd44c.at(x,y))->isEdge_45dc30() && !h2s_cefc4c->unknown463e90(Pos(x,y)))
								{
									h2s_cefc4c->unknown734d60(Pos(x,y));
									bool opened = false;
									if ((*h2s_cfd44c.at(x,y))->unknown45dbb0())
									{
										(*h2s_cfd44c.at(x,y))->unknown670690();
										opened = true;
									}
									h2s_cefc4c->opw3_unknown7243c0(x,y,1);
									if (opened)
										(*h2s_cfd44c.at(x,y))->unknown670b20();
								}
								else if (!h2s_cefc4c->isKnown_463130(x,y))
								{
									if ((*h2s_cfd44c.at(x,y))->getItem().isValid() && h2s_cefc4c->isItemAtRecordedPosition_465560((*h2s_cfd44c.at(x,y))->getItem()))
										h2s_cefc4c->opw3_unknown7243c0(x,y,0);
									else
										h2s_cefc4c->opw3_unknown7243c0(x,y,1);
								}
								if ((*h2s_cfd44c.at(x,y))->getEntity_45d250().isValid() && (*h2s_cfd44c.at(x,y))->getEntity_45d250()->getGroup_45a3f0()->getType_9b8f00() == 3 && (*h2s_cfd44c.at(x,y))->getEntity_45d250()->getAI_45b590()->getState_9b8f00() == 1 && !(*h2s_cfd44c.at(x,y))->getEntity_45d250()->getAI_45b590()->unknown458ef0()->empty())
								{
									markers.push_back(h2s_cefaa8->createC_793190());
									markers.back()->unknown6c20b0(2,(*h2s_cfd44c.at(x,y))->getEntity_45d250()->getAI_45b590()->unknown458ef0()->front(),-1);
									unknownD8 = true;
								}
								unknownDC.push_back(Pos(x,y));
							}
						}
					}
					vector<H2sAccess *> *zones = h2s_cefc4c->getAccess_462e10();
					for (unsigned int i = 0; i < zones->size(); i++)
					{
						if (jl_cf4718 == 2)
							h2s_cefc4c->announceMachine_71dd30((*zones)[i]->owner);
						(*zones)[i]->b0d = true;
						(*zones)[i]->unknown6c16d0("FOUND");
						unknownA8.push_back((*zones)[i]->pos);
					}
					msg += "Retrieving Garrison registry...";
					msg += "\nDownloaded map data.";
					msg += "\nDownloaded component registry.";
					msg += "\nDownloaded security status.";
					done = true;
				}
				addNew(name,msg,1,-1,0);
				if (done)
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				break;
			}

			case 44:
			{
				bool done = false;
				if (h2s_d1e888->f4 != 0xd)
					msg += "Data access restricted to Garrison Terminals.";
				else
				{
					H2sHOwner owner = h2s_cefc4c->getAccess_462e10()->front()->owner;
					owner->f0;
					owner->b60 = true;
					if (0) {}
					msg += "Retrieving " + h2s_mapNames_cfaca0[owner->f4] + " patrol records...";
					msg += "\nDownloaded protocol data.";
					done = true;
				}
				addNew(name,msg,1,-1,0);
				if (done)
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				break;
			}

			case 45:
			{
				bool done = false;
				H2sHOwner owner;
				if (h2s_d1e888->f4 != 0xd)
					msg += "Data access restricted to Garrison Terminals.";
				else
				{
					owner = h2s_cefc4c->getAccess_462e10()->front()->owner;
					owner->f0;
					if (0) {}
					msg += "Retrieving " + h2s_mapNames_cfaca0[owner->f4] + " security records...";
					msg += "\nDownloaded coordinate data.";
					done = true;
				}
				addNew(name,msg,1,-1,0);
				if (owner.isValid())
					hotel_prelearn_data(string("PRELEARN_GUARDS=") + jl_cfe140[owner->f4],0);
				if (done)
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				break;
			}

			case 46:
			{
				bool found = false;
				switch (h2s_d1e888->f4)
				{
					case 8:
						msg += "Downloading prototype IDs...";
						for (unsigned int i = 0; i < h2s_d2d1c4.size(); i++)
						{
							if (h2s_d2d1c4[i]->getValue457330(0x63) != 0 && h2s_d2d1c4[i]->name.find("BFG-9k",0) == string::npos)
							{
								msg += "\n  " + h2s_d2d1c4[i]->search;
								if (jl_cf4830[i] == 0)
								{
									jl_cf45d8.unknown77ffb0(i,0);
									found = true;
								}
							}
						}
						break;
					case 15:
						msg += "Downloading prototype IDs...";
						for (unsigned int i = 0; i < h2s_d2d1c4.size(); i++)
						{
							if (h2s_d2d1c4[i]->ff0 == 0xd4)
							{
								msg += "\n  " + h2s_d2d1c4[i]->search;
								if (jl_cf4830[i] == 0)
								{
									jl_cf45d8.unknown77ffb0(i,0);
									found = true;
								}
							}
						}
						break;
					case 11:
						msg += "Downloading prototype IDs...";
						for (unsigned int i = 0; i < h2s_d2d1c4.size(); i++)
						{
							if (h2s_d2d1c4[i]->getValue457330(0x64) != 0)
							{
								msg += "\n  " + h2s_d2d1c4[i]->search;
								if (jl_cf4830[i] == 0)
								{
									jl_cf45d8.unknown77ffb0(i,0);
									found = true;
								}
							}
						}
						msg += "\n  Mindflail";
						msg += "\n  Acceleration Regulator";
						msg += "\n  Hcp. Trap Extractor";
						msg += "\n  Preattuning Coils";
						msg += "\n  Mak. Powered Armor";
						msg += "\n  Regenerative Guardplate";
						msg += "\n  Interdictor 741C";
						msg += "\n  Chamberscale";
						msg += "\n  Vortex Pulse Array";
						msg += "\n  Cloaking Wrap";
						break;
					case 33:
					{
						msg += "Downloading latest rotation IDs...";
						vector<int> *rotation = h2s_cefc4c->unknown463d00();
						for (unsigned int i = 0; i < rotation->size(); i++)
						{
							msg += "\n  " + h2s_d2d1c4[(*rotation)[i]]->search;
							if (jl_cf4830[(*rotation)[i]] == 0)
							{
								jl_cf45d8.unknown77ffb0((*rotation)[i],0);
								found = true;
							}
						}
						break;
					}
				}
				if (found)
					h2s_cec08c->reopen8a2ce0(4,H2sHEntity());
				addNew(name,msg,1,-1,0);
				break;
			}

			case 47:
			{
				vector<H2sHEntity> variants2;
				vector<H2sHEntity> *members = h2s_cefc4c->unknown463890(3)->getMembers_416f40();
				for (unsigned int i = 0; i < members->size(); i++)
				{
					if ((*members)[i]->getName_45a280().find("P_",0) != string::npos)
						variants2.push_back((*members)[i]);
				}
				msg += "Scanning protovariant control network...";
				if (variants2.empty())
				{
					msg += "\nNo local protovariants found.";
					addNew(name,msg,1,-1,0);
				}
				else
				{
					H2sHEntity target = OpX5_randomRecord(variants2);
					msg += "\nFound vulnerable protovariant: " + target->getName_416f40();
					if (!rng.chance(75))
					{
						msg += "\nFailed to overload target system.";
						addNew(name,msg,3,-1,0);
						passed = false;
					}
					else
					{
						msg += "\nTarget system overloaded...";
						msg += "\nDownloaded coordinate data.";
						msg += "\nProtovariant control network temporarily suspended.";
						vector<H2sHMarker> &markers = (*h2s_cefc4c->unknown463ec0())[16];
						markers.push_back(h2s_cefaa8->createC_793190());
						markers.back()->unknown6c20b0(16,target->getPosition_45a4a0(),-1);
						unknownD8 = true;
						jl_ovm3_cf6428.unknown68c6d0(target);
						h2s_d2c658.add472b90(0x41,-999999);
						hotel_cf45d8.unknown77fbc0(0x19f);
						LOGP(0x1ee,target->getName_416f40());
						addNew(name,msg,1,-1,0);
						hotel_unknown91c850(hackType,&preBonus,&secondBonus);
					}
				}
				break;
			}

			case 48:
			{
				JlPos at2(-1);
				vector<H2sHEntity> *members = h2s_cefc4c->unknown463890(3)->getMembers_416f40();
				for (unsigned int i = 0; i < members->size(); i++)
				{
					if ((*members)[i]->getName_45a280() == "Sigix Exoskeleton")
					{
						at2 = (*members)[i]->getPosition_45a4a0();
						break;
					}
				}
				msg += "Initializing exoskeleton controls...";
				if (at2.x == -1)
				{
					msg += "\nError: No exoskeleton found.";
					addNew(name,msg,3,-1,0);
				}
				else
				{
					H2sHItem pod;
					vector<H2sHItem> *inventory2 = h2s_cefc4c->getPlayer()->getInventoryList();
					for (unsigned int i = 0; i < inventory2->size(); i++)
					{
						if ((*inventory2)[i]->getName_457860() == "Sigix Containment Pod")
						{
							pod = (*inventory2)[i];
							break;
						}
					}
					if (pod.isNull())
					{
						msg += "\nAborted: Unable to activate without Sigix Containment Pod.";
						addNew(name,msg,3,-1,0);
						passed = false;
					}
					else
					{
						msg += "\nLive Sigix inserted...";
						msg += "\nExoskeleton activated.";
						pod->remove57dbe0(true,false,true,true);
						(*h2s_cfd44c.atPoint(at2))->getEntity_45d250()->unknown637bb0();
						H2sHEntity warrior = jl_cefc4c->unknown6c5dc0("Sigix Warrior",at2,2,false,0x22,0xe,false);
						if (warrior.isValid())
						{
							warrior->getAI_45b590()->setFollowEntity_5b2f80(h2s_cefc4c->getPlayer(),2);
							jl_cefc4c->unknown6c65a0(warrior,"SEC_Sigix_Dialogue",0);
							jl_cefc4c->unknown6c65a0(warrior,"SEC_Sigix_Dialogue_End",0);
							jl_cefc4c->unknown6c65a0(warrior,"SEC_Sigix_Death",0);
							jl_cefc4c->unknown6c65a0(warrior,"SEC_Sigix_High_Security",0);
						}
						opR1d_4541b0(0x96,0,0);
						h2s_d2c658.add472b90(0x4f,-999999);
						hotel_cf45d8.unknown77fbc0(0x1a2);
						LOG0(0x1fc);
						jl_d1e860.setEntryText_46f700("secSigixActive_g","1");
						H2sRect area;
						h2s_cfd44c.getRect_9b4430(*machine->getPosition_4184d0(),5,area);
						for (int x = area.a.x; x <= area.b.x; x++)
						{
							for (int y = area.a.y; y <= area.b.y; y++)
							{
								if ((*h2s_cfd44c.at(x,y))->getProp_45d550().isValid() && (*h2s_cfd44c.at(x,y))->getProp_45d550()->name_45c590() == "Suspension Chamber")
									(*h2s_cfd44c.at(x,y))->getProp_45d550()->unknown45ce10(1,0,1,H2sHProp());
							}
						}
						addNew(name,msg,1,-1,0);
						if (h2s_d25450.b0)
						{
							int portrait = h2s_d25450.unknown69e700(0x72,0,0.0f);
							if (portrait != 6)
								opG1_showXomPortrait(portrait);
						}
					}
				}
				break;
			}

			case 49:
			{
				H2sHProp seal;
				JlPos at5(-1);
				bool busy = false;
				jl_cefc4c->unknown74bb90(machine,&seal,&at5,&busy);
				msg += "Accessing seal controls...";
				if (busy)
				{
					msg += "\nError: Seal state transition in progress.";
					addNew(name,msg,3,-1,0);
				}
				else if (seal.isNull() || at5.x == -1)
				{
					msg += "\nError: Unable to establish connection.";
					addNew(name,msg,3,-1,0);
				}
				else
				{
					msg += "\nDisengaging subsurface cave network seal C" + intToString(rng.rangeInt(100,999)) + ".";
					msg += "\nWarning: Hostile activity detected below.";
					jl_cefc4c->unknown6c6b90(at5,"COM_Cave_Seal_Timer",0,-1);
					addNew(name,msg,1,-1,0);
				}
				break;
			}

			case 50:
			{
				H2sPt at;
				switch (h2s_d1e888->f4)
				{
					case 15:
						if (h2s_cefc4c->unknown71bde0(machine->getPosition_4184d0(),&at))
						{
							H2sHItem basin = h2s_cefc4c->placeItem("SUBCON Basin",at);
							if (basin.isValid())
							{
								basin->addEffect_4585a0(new JlEffect(jl_d2f0f8[0x7c],1));
								opR1d_4541b0(0x9a,0,0);
								msg += "Accessing inventory controls...";
								msg += "\nCollection purity confirmed 100%...";
								msg += "\nEjecting SUBCON Basin...";
								msg += "\nDelivery behind schedule, handle with care!";
								addNew(name,msg,1,-1,0);
							}
						}
						break;
					case 10:
						if (!OpX5_containsRecord(machine->getData_45cb30()->f60,0x32))
						{
							msg += "Accessing inventory controls...";
							if (stringToInt(jl_d1e860.getEntryText_46f6d0("recScraplabLockedDown_g")))
								msg += "\nWARNING: Removing SEP-X while under threat of\nSubdwellers is not advised. Repeat command to confirm.";
							else
								msg += "\nWARNING: Removing SEP-X without authorization\nis a serious offense. Repeat command to confirm.";
							addNew(name,msg,3,-1,0);
							passed = false;
						}
						else if (h2s_cefc4c->unknown71bde0(machine->getPosition_4184d0(),&at) && h2s_cefc4c->placeItem("Scrap Engine",at).isValid())
						{
							opR1d_4541b0(0x9a,0,0);
							if (!stringToInt(jl_d1e860.getEntryText_46f6d0("recScraplabLockedDown_g")))
								h2s_cefc4c->opw3_unknown72f6b0();
							msg += "Accessing inventory controls...";
							msg += "\nPrototype released...\nURGENT: Link to external system right away!";
							addNew(name,msg,1,-1,0);
						}
						break;
					case 29:
						if (stringToInt(jl_d1e860.getEntryText_46f6d0("datDataConduitDownloaded_g")))
							msg += "Accessing inventory controls...";
						else
							msg += "uVuKpwUQN 6cBIMQY9J 5wGvWL96PNl";
						if (h2s_cefc4c->unknown71bde0(machine->getPosition_4184d0(),&at) && h2s_cefc4c->placeItem("LC Capacitor",at).isValid())
						{
							opR1d_4541b0(0x9a,0,0);
							if (stringToInt(jl_d1e860.getEntryText_46f6d0("datDataConduitDownloaded_g")))
								msg += "\nLC Capacitor released...\nConnect to external power source immediately.";
							else
								msg += "\nxA Yh3BMdQHG rm5O5oUoX23\nHvoyg4a Da 7BE3zrkZ DmzOR RsFl1k OalUi49Wm2Z6";
							addNew(name,msg,1,-1,0);
						}
						else
						{
							if (stringToInt(jl_d1e860.getEntryText_46f6d0("datDataConduitDownloaded_g")))
								msg += "\nError: Release blocked.";
							else
								msg += "\ngzjibw J3TAkqH XdZjs9m7";
							addNew(name,msg,3,-1,0);
							passed = false;
						}
						break;
				}
				break;
			}

			case 51:
			{
				msg += "Running Singularity Gate diagnostics...";
				if (stringToInt(jl_d1e860.getEntryText_46f6d0("ac0GateDisabled_g")))
				{
					msg += "\nError: Unable to connect.";
					addNew(name,msg,3,-1,0);
				}
				else if (stringToInt(jl_d1e860.getEntryText_46f6d0("ac0RanGateTestC_g")))
				{
					msg += "\nWARNING: CRITICAL INSTABILITY.";
					addNew(name,msg,3,-1,0);
				}
				else if (stringToInt(jl_d1e860.getEntryText_46f6d0("ac0RanGateTestB_g")))
				{
					msg += "\nGate operating within expected parameters.";
					addNew(name,msg,1,-1,0);
				}
				else
				{
					jl_d1e860.setEntryText_46f700("ac0RanGateTestA_g","1");
					msg += "\nAll systems nominal.";
					addNew(name,msg,1,-1,0);
				}
				passed = false;
				break;
			}

			case 52:
			{
				msg += "Preparing Singularity Gate activation...";
				if (stringToInt(jl_d1e860.getEntryText_46f6d0("ac0GateDisabled_g")))
				{
					msg += "\nError: Unable to connect.";
					addNew(name,msg,3,-1,0);
				}
				else if (!stringToInt(jl_d1e860.getEntryText_46f6d0("ac0RanGateTestA_g")))
				{
					msg += "\nError: Must run diagnostics.";
					addNew(name,msg,3,-1,0);
				}
				else if (stringToInt(jl_d1e860.getEntryText_46f6d0("ac0RanGateTestB_g")) || stringToInt(jl_d1e860.getEntryText_46f6d0("ac0RanGateTestC_g")))
				{
					msg += "\nError: Gate already active.";
					addNew(name,msg,3,-1,0);
				}
				else
				{
					msg += "\nStable singularity established.";
					addNew(name,msg,1,-1,0);
					h2s_d2c658.add472b90(0x5e,-999999);
					LOG0(0x22b);
					opR1d_4541b0(0x76,0,0);
					h2s_cefc4c->unknown749240();
				}
				passed = false;
				break;
			}

			case 53:
			{
				msg += "Initiating Test 138-C...";
				if (stringToInt(jl_d1e860.getEntryText_46f6d0("ac0GateDisabled_g")))
				{
					msg += "\nError: Unable to connect.";
					addNew(name,msg,3,-1,0);
				}
				else if (!stringToInt(jl_d1e860.getEntryText_46f6d0("ac0RanGateTestA_g")))
				{
					msg += "\nError: Must run diagnostics.";
					addNew(name,msg,3,-1,0);
				}
				else if (!stringToInt(jl_d1e860.getEntryText_46f6d0("ac0RanGateTestB_g")))
				{
					msg += "\nError: Test 138-C requires active singularity.";
					addNew(name,msg,3,-1,0);
				}
				else if (stringToInt(jl_d1e860.getEntryText_46f6d0("ac0RanGateTestC_g")))
				{
					msg += "\nError: Test 138-C already in progress.";
					addNew(name,msg,3,-1,0);
				}
				else if (!stringToInt(jl_d1e860.getEntryText_46f6d0("ac0AcquiredA2DataCore_g")))
				{
					msg += "\nError: Access codes required.";
					addNew(name,msg,3,-1,0);
				}
				else if (!stringToInt(jl_d1e860.getEntryText_46f6d0("ac0WarnedGateTestC_g")))
				{
					msg += "\nWarning: Experimental formulas incomplete.";
					msg += "\nPotential effects include instability.";
					msg += "\nRepeat command to confirm test.";
					addNew(name,msg,1,-1,0);
					jl_d1e860.setEntryText_46f700("ac0WarnedGateTestC_g","1");
				}
				else
				{
					jl_d1e860.setEntryText_46f700("ac0RanGateTestC_g","1");
					msg += "\nApplying incomplete calculations....";
					msg += "\nINSTABILITY DETECTED, CASCADE IMMINENT.";
					addNew(name,msg,1,-1,0);
					h2s_d2c658.add472b90(0x5f,-999999);
					LOG0(0x22c);
					unknown124 = jl_caed20;
					opR1d_4541b0(0x77,0,0);
					hotel_cec0fc->unknown4afc40(0x33)->unknown4afab0(1);
					hotel_cec0fc->unknown4afc40(0x34)->unknown4afab0(1);
					hotel_cec0fc->unknown4afc40(0x35)->unknown4afab0(1);
					hotel_cec0fc->unknown4afc40(0x36)->unknown4afab0(1);
				}
				passed = false;
				break;
			}

			case 54:
			{
				msg += "Connecting to Singularity Gate...";
				if (stringToInt(jl_d1e860.getEntryText_46f6d0("ac0GateDisabled_g")))
				{
					msg += "\nError: Unable to connect.";
					addNew(name,msg,3,-1,0);
				}
				else if (stringToInt(jl_d1e860.getEntryText_46f6d0("ac0RanGateTestC_g")))
				{
					msg += "\nError: Test 138 in uncontrollable state.";
					addNew(name,msg,3,-1,0);
				}
				else if (!stringToInt(jl_d1e860.getEntryText_46f6d0("ac0RanGateTestB_g")))
				{
					msg += "\nError: Test 138 inactive.";
					addNew(name,msg,3,-1,0);
				}
				else
				{
					jl_d1e860.setEntryText_46f700("ac0RanGateTestB_g","0");
					msg += "\nTest 138 successfully terminated.";
					addNew(name,msg,1,-1,0);
					int radius = 3;
					int effect2 = OpU8a_indexOfName4(jl_d2c408,"AC0_Gate_Destruction1");
					for (int x = jl_d1ec6c - 3; x <= jl_d1ec6c + 3; x++)
					{
						for (int y = jl_d1ec70 - 3; y <= jl_d1ec70 + 3; y++)
						{
							if ((*h2s_cfd44c.at(x,y))->getProp_45d550().isValid() && (*h2s_cfd44c.at(x,y))->getProp_45d550()->unknown45ca00(effect2))
								(*h2s_cfd44c.at(x,y))->getProp_45d550()->unknown45ce10(1,0,1,H2sHProp());
						}
					}
					jl_d2d2a0.unknown454540();
					jl_d2d2a0.unknown500010();
					opR1d_4541b0(0x78,0,0);
				}
				passed = false;
				break;
			}

			case 55:
			case 56:
			case 57:
			case 58:
			case 59:
			case 60:
			case 61:
			{
				vector<int> &trojans = machine->getData_45cb30()->f40;
				int trojan = hackType - 55;
				if (OpX5_containsRecord(trojans,trojan))
				{
					msg = "Trojan already loaded.";
					addNew(name,msg,3,-1,0);
				}
				else
				{
					if (preBonus == 2)
					{
						H2sHProp best;
						vector<vector<H2sHProp> > *nets = h2s_cefc4c->unknown463be0();
						int bestDistance;
						for (int i = 0; i < 7; i++)
						{
							for (unsigned int j = 0; j < (*nets)[i].size(); j++)
							{
								int distance = OpQ1_distanceCeil_40a3f0(*machine->getPosition_4184d0(),*(*nets)[i][j]->getPosition_4184d0());
								if (best.isNull() || distance < bestDistance)
								{
									best = (*nets)[i][j];
									bestDistance = distance;
								}
							}
						}
						if (best.isValid())
						{
							int index = OpU8a_randomRec(best->getData_45cb30()->f40);
							OpS8b_Fn9d51d0(best->getData_45cb30()->f40,index);
							jl_removeEntity_9d2f00((*h2s_cefc4c->unknown463be0())[index],best);
							preBonus = 3;
						}
					}
					trojans.push_back(trojan);
					jl_addUniqueEntityData_9d30e0(h2s_cefc4c->unknown463c00(trojan),machine);
					STAT(0x2c6,hotel_e_b995bb);
					STAT(0x2c7,hotel_e_b995c6);
					STAT(hackType + 0x291,hotel_e_b995c7);
					hotel_cf45d8.unknown77fbc0(0x5b);
					msg = "Trojan loaded successfully.";
					msg += "\nTesting...";
					switch (hackType)
					{
						case 55:
							msg += "\nTracking enabled and active.";
							break;
						case 56:
							msg += "\nSystem interface override in place.";
							break;
						case 57:
						{
							int linked = h2s_cec0f8->unknown45a990();
							msg += "\nTerminal linked with " + opw8_countString(linked,"system") + ".\nAwaiting botnet instructions.";
							if (linked + 1 == 3)
								hotel_cf45d8.unknown77fbc0(0x5c);
							break;
						}
						case 58:
						{
							msg += "\nScanning machine control network...";
							vector<int> found5;
							H2sRect area;
							h2s_cfd44c.getRect_9b4430(*machine->getPosition_4184d0(),0xf,area);
							for (int x = area.a.x; x <= area.b.x; x++)
							{
								for (int y = area.a.y; y <= area.b.y; y++)
								{
									if ((*h2s_cfd44c.at(x,y))->getProp_45d550().isValid() && (*h2s_cfd44c.at(x,y))->getProp_45d550()->getInfo_9b8f00()->f8c != 0 && (*h2s_cfd44c.at(x,y))->getProp_45d550()->getId_44ab40() != -1 && (*h2s_cfd44c.at(x,y))->getProp_45d550()->unknown457b10() != 1 && (*h2s_cfd44c.at(x,y))->getProp_45d550()->name_45c590() != "SEC_L2_Power_Cell")
										OpT8b_Fn9db000(found5,(*h2s_cfd44c.at(x,y))->getProp_45d550()->getId_44ab40());
								}
							}
							if (found5.empty())
								msg += "\nNo applicable machines found.";
							else
							{
								msg += "\nFound " + opw8_countString(found5.size(),"applicable machine") + ".";
								string chars("ABCDEFGHIJKLMNOPQRSTUVWXYZ09123456789");
								string id;
								for (unsigned int i = 0; i < found5.size(); i++)
								{
									vector<H2sHProp> &parts = h2s_d31640[found5[i]];
									for (unsigned int j = 0; j < parts.size(); j++)
										parts[j]->unknown45cd50();
									STAT(0x256,hotel_e_b995d2);
									id.clear();
									for (int k = 0; k < 10; k++)
										id += randomChar_4085b0(chars);
									msg += "\n  " + id + ": " + parts.front()->getName_45c5b0();
								}
								msg += "\nInfected machine control systems.";
							}
							break;
						}
						case 59:
							msg += "\nDisruption routine running.";
							break;
						case 60:
							msg += "\nOperator tracking enabled and active.";
							break;
						case 61:
						{
							H2sBotnet *net = h2s_cefc4c->unknown463c40();
							net->unknown6c2180();
							net->list.push_back(machine);
							int count3 = net->list.size();
							msg += "\nTerminal linked with " + opw8_countString(count3 - 1,"system") + ".";
							if (count3 < 5)
								msg += "\nPlease expand to " + opw8_countString(5 - count3,"more system") + "!";
							else if (count3 == 5)
							{
								msg += "\nSkimming routine engaged. Thanks from A0-MCA.";
								net->f1c = h2s_cefc4c->getTurn() + net->f18;
							}
							else
								msg += "\nOverkill, but a backup won't hurt. --A0-MCA";
							break;
						}
					}
					addNew(name,msg,1,-1,0);
				}
				break;
			}

			case 62:
			{
				unknown4748 = 3;
				STAT(0x2c6,hotel_e_b995d3);
				STAT(0x2c7,hotel_e_b995df);
				STAT(hackType + 0x291,hotel_e_b995e9);
				hotel_cf45d8.unknown77fbc0(0x5a);
				vector<Pos> *anySpots = h2s_cefc4c->unknown463ab0();
				for (int i = 0; i < anySpots->size(); i++)
				{
					if ((*h2s_cfd44c.atPoint((*anySpots)[i]))->getProp_45d550().isNull() || (*h2s_cfd44c.atPoint((*anySpots)[i]))->getProp_45d550()->unknown457b10() != 0 || (*h2s_cfd44c.atPoint((*anySpots)[i]))->getProp_45d550()->getInfo_9b8f00()->f8c == 0)
						OpQ5_eraseStep_9d7300(*anySpots,i);
				}
				bool overloaded2 = false;
				vector<string> lines;
				if (anySpots->empty())
					lines.push_back("NULL_SCAN");
				else
				{
					H2sHProp target = (*h2s_cfd44c.atPoint(jl_randomPoint_9d5350(*anySpots)))->getProp_45d550();
					lines.push_back("SYSTEM_VULNERABLE[" + target->getName_45c5b0() + "]");
					if (!rng.chance(50))
						lines.push_back("NETWORK_OVERLOAD_FAIL");
					else
					{
						STAT(0x263,hotel_e_b995ea);
						vector<int> types14;
						types14.push_back(0);
						types14.push_back(1);
						types14.push_back(2);
						H2sParty *party = jl_ovm4_cf6428.unknown68cf70(types14,*machine->getPosition_4184d0());
						jl_ovm4_cf6428.unknown6820b0();
						overloaded2 = true;
						lines.push_back("NETWORK_OVERLOAD");
						if (party != NULL && jl_ovm4_cf6428.redirectParty_68d1f0(party,*target->getPosition_4184d0(),H2sHEntity()))
							lines.push_back("SQUAD_REDIRECT[" + jl_cf25d8[party->type] + "]DETECTED");
						lines.push_back("COORDINATES_RETRIEVED");
						vector<H2sHMarker> &markers = (*h2s_cefc4c->unknown463ec0())[16];
						markers.push_back(h2s_cefaa8->createC_793190());
						markers.back()->unknown6c20b0(16,*target->getPosition_4184d0(),-1);
						unknownD8 = true;
						target->unknown45ce10(0,0,0,H2sHProp());
					}
				}
				int lineCount = opr5e_unknown91c960(&msg,lines.size());
				for (unsigned int i = 0; i < lines.size(); i++)
				{
					if (i != 0)
						msg += "\n";
					msg += lines[i];
				}
				addNew(name,msg,1,-1,lineCount);
				if (h2s_d25450.b0 && overloaded2)
				{
					int portrait = h2s_d25450.unknown69e700(0x1a,0,0.0f);
					if (portrait != 6)
						opG1_showXomPortrait(portrait);
				}
				break;
			}

			case 63:
			{
				unknown4748 = 3;
				STAT(0x2c6,hotel_e_b995eb);
				STAT(0x2c7,hotel_e_b995f5);
				STAT(hackType + 0x291,hotel_e_b995f6);
				hotel_cf45d8.unknown77fbc0(0x5a);
				Pos origin(h2s_cefc4c->getPlayer()->getPosition_45a4a0());
				vector<vector<Pos> > *machines = h2s_cefc4c->unknown459070();
				vector<Pos> found7;
				for (unsigned int i = 0; i < machines->size(); i++)
				{
					for (unsigned int j = 0; j < (*machines)[i].size(); j++)
					{
						if (OpQ1_distanceCeil_40a3f0(origin,(*machines)[i][j]) <= 30 && (*h2s_cfd44c.atPoint((*machines)[i][j]))->getProp_45d550()->getInfo_9b8f00()->type < 6)
							found7.push_back((*machines)[i][j]);
					}
				}
				vector<string> lines;
				if (found7.empty())
					lines.push_back("NULL_SEARCH");
				else
				{
					unknownD8 = true;
					vector<int> counts(9u,0);
					vector<H2sHMarker> &markers4 = (*h2s_cefc4c->unknown463ec0())[0];
					for (unsigned int i = 0; i < found7.size(); i++)
					{
						counts[(*h2s_cfd44c.atPoint(found7[i]))->getProp_45d550()->getInfo_9b8f00()->type] += 1;
						for (unsigned int j = 0; j < markers4.size(); j++)
						{
							if (markers4[j]->pos.same_409b90(found7[i]))
								goto nextMachine;
						}
						markers4.push_back(h2s_cefaa8->createC_793190());
						markers4.back()->unknown6c20b0(0,found7[i],(*h2s_cfd44c.atPoint(found7[i]))->getProp_45d550()->getInfo_9b8f00()->type);
nextMachine:
						;
					}
					lines.push_back("SEARCH_COMPLETE[" + intToString(found7.size()) + "]");
					for (int i = 0; i < 9; i++)
					{
						if (counts[i] != 0)
							lines.push_back("DISCOVERED[" + intToString(counts[i]) + "x" + jl_d3a280[i] + "]");
					}
					lines.push_back("COORDINATES_EXTRACTED");
				}
				int lineCount8 = opr5e_unknown91c960(&msg,lines.size());
				for (unsigned int i = 0; i < lines.size(); i++)
				{
					if (i != 0)
						msg += "\n";
					msg += lines[i];
				}
				addNew(name,msg,1,-1,lineCount8);
				break;
			}

			case 64:
			{
				unknown4748 = 3;
				STAT(0x2c6,hotel_e_b995f7);
				STAT(0x2c7,hotel_e_b99617);
				STAT(hackType + 0x291,hotel_e_b9961f);
				hotel_cf45d8.unknown77fbc0(0x5a);
				vector<string> lines;
				if (h2s_d1e888->f4 != 0xd)
					lines.push_back("INVALID_TARGET");
				else
				{
					int count = 0;
					vector<H2sAccess *> *zones3 = h2s_cefc4c->getAccess_462e10();
					for (unsigned int i = 0; i < zones3->size(); i++)
					{
						if ((*zones3)[i]->f1c == 1)
							count++;
					}
					lines.push_back("SYSTEM_OVERRIDE[" + intToString(count) + "]");
					lines.push_back("COORDINATES_EXTRACTED");
					h2s_cefc4c->setFlag2f0_465640();
					for (unsigned int i = 0; i < zones3->size(); i++)
					{
						if ((*zones3)[i]->owner->inRange_46ecb0() && (*zones3)[i]->f1c == 1)
						{
							h2s_cefc4c->announceMachine_71dd30((*zones3)[i]->owner);
							h2s_cefc4c->unknown4647a0((*zones3)[i]->pos,true);
							(*zones3)[i]->b0d = true;
							unknownA8.push_back((*zones3)[i]->pos);
						}
					}
				}
				int lineCount = opr5e_unknown91c960(&msg,lines.size());
				for (unsigned int i = 0; i < lines.size(); i++)
				{
					if (i != 0)
						msg += "\n";
					msg += lines[i];
				}
				addNew(name,msg,1,-1,lineCount);
				break;
			}

			case 65:
			{
				msg = "Querying network status...";
				int kind = 1;
				vector<H2sHMarker> &markers8 = (*h2s_cefc4c->unknown463ec0())[0];
				for (int i = 0; i < markers8.size(); i++)
				{
					if (markers8[i]->f14 == kind)
						OpQ5_eraseStep_9d6440(markers8,i);
				}
				vector<Pos> online((*h2s_cefc4c->unknown459070())[kind]);
				vector<Pos> offline4((*h2s_cefc4c->unknown463a90())[kind]);
				for (int i = 0; i < offline4.size(); i++)
				{
					if (OpV4c_Fn9d0ce0Pos(online,offline4[i]))
						OpQ5_eraseStep_9d7300(offline4,i);
				}
				msg += "\n" + (opw8_countString(online.size() + offline4.size(),"record") + " found:");
				vector<string> labels3;
				vector<string> states6;
				for (unsigned int i = 0; i < online.size(); i++)
				{
					labels3.push_back(OpQ1_pointToString(online[i]));
					states6.push_back(" - ");
					if ((*h2s_cfd44c.atPoint(online[i]))->getProp_45d550()->unknown457b10() != 0)
						states6.back() += "Offline";
					else if ((*h2s_cfd44c.atPoint(online[i]))->getProp_45d550()->getData_45cb30()->f28 == -2)
						states6.back() += "Crashed";
					else if ((*h2s_cfd44c.atPoint(online[i]))->getProp_45d550()->getData_45cb30()->f38 != NULL && (*h2s_cfd44c.atPoint(online[i]))->getProp_45d550()->getData_45cb30()->f38->f4 == 0x43)
					{
						states6.back() += "Building: ";
						string product((*h2s_cfd44c.atPoint(online[i]))->getProp_45d550()->getData_45cb30()->f38->fc != NULL ? (*h2s_cfd44c.atPoint(online[i]))->getProp_45d550()->getData_45cb30()->f38->fc->search : (*h2s_cfd44c.atPoint(online[i]))->getProp_45d550()->getData_45cb30()->f38->f10->f1ac);
						states6.back() += product;
						if (!(*h2s_cfd44c.atPoint(online[i]))->getProp_45d550()->getData_45cb30()->f38->b44)
						{
							if ((*h2s_cfd44c.atPoint(online[i]))->getProp_45d550()->getData_45cb30()->f38->fc != NULL)
								jl_cf45d8.unknown77ffb0((*h2s_cfd44c.atPoint(online[i]))->getProp_45d550()->getData_45cb30()->f38->fc->index,0);
							h2s_cefc4c->opw3_unknown729eb0(online[i],product,1,false);
						}
					}
					else if ((*h2s_cfd44c.atPoint(online[i]))->getProp_45d550()->getData_45cb30()->f80 != jl_caf164)
					{
						states6.back() += "Loaded: ";
						string product(h2s_d2d1c4[(*h2s_cfd44c.atPoint(online[i]))->getProp_45d550()->getData_45cb30()->f80]->search);
						states6.back() += product;
						h2s_cefc4c->opw3_unknown729eb0(online[i],product,1,false);
					}
					else if ((*h2s_cfd44c.atPoint(online[i]))->getProp_45d550()->getData_45cb30()->f88 != jl_caf160)
					{
						states6.back() += "Loaded: ";
						string product(h2s_d25de0[(*h2s_cfd44c.atPoint(online[i]))->getProp_45d550()->getData_45cb30()->f88]->f1ac);
						states6.back() += product;
						h2s_cefc4c->opw3_unknown729eb0(online[i],product,1,false);
					}
					else
						states6.back() += "Idle";
					markers8.push_back(h2s_cefaa8->createC_793190());
					markers8.back()->unknown6c20b0(0,online[i],kind);
					unknownD8 = true;
				}
				for (unsigned int i = 0; i < offline4.size(); i++)
				{
					labels3.push_back(OpQ1_pointToString(offline4[i]));
					states6.push_back(" - Connection failed");
				}
				unsigned int width = labels3[0].size();
				for (unsigned int i = 1; i < labels3.size(); i++)
				{
					if (labels3[i].size() > width)
						width = labels3[i].size();
				}
				width += 2;
				for (unsigned int i = 0; i < labels3.size(); i++)
				{
					padLeft_408090(labels3[i],width,' ');
					labels3[i] += states6[i];
					msg += "\n" + labels3[i];
					opW5_truncate_408490(labels3[i],'.');
				}
				addNew(name,msg,1,-1,0);
				passed = false;
				if (!online.empty())
					hotel_unknown91c850(hackType,&preBonus,&secondBonus,intToString(online.size()));
				break;
			}

			case 66:
			{
				H2sHItem item = h2s_cefc4c->getPlayer()->unknown5d3f80(rec8 ? rec8->index : jl_caf164,rec4 ? rec4->index : jl_caf160);
				if (item.isValid())
					msg += item->unknown571db0(0,0) + " confirmed.\n";
				msg += "Uploading " + (rec8 ? rec8->search : rec4->f1ac) + " schematic...";
				msg += "\nLoaded successfully:";
				msg += "\n  " + (rec8 ? rec8->search : rec4->f1ac);
				if (rec8)
					msg += "\n  Rating: " + intToString(rec8->f50);
				else
					msg += "\n  Tier: " + intToString(rec4->f68);
				if (rec8 && rec8->f94 != 0)
					msg += "p";
				msg += "\n  Time: " + intToString((rec8 ? rec8->getValue457430(machine->getData_45cb30()->f8) : rec4->getValue459840(machine->getData_45cb30()->f8)) * (OpX5_containsRecord(machine->getData_45cb30()->f40,8) ? jl_b9b9b8 : 1.0f));
				vector<int> &components = rec8 ? rec8->f1f4 : rec4->ffc;
				if (!components.empty())
				{
					vector<H2sHItem> inventory;
					h2s_cefc4c->getPlayer()->unknown5cb830(&inventory);
					msg += "\n  Components: ";
					for (unsigned int i = 0; i < components.size(); i++)
					{
						if (i != 0)
							msg += "\n              ";
						msg += h2s_d2d1c4[components[i]]->search;
						bool have = false;
						for (int j = 0; j < inventory.size(); j++)
						{
							if (inventory[j]->unknown571db0(0,0) == h2s_d2d1c4[components[i]]->search)
							{
								OpQ5_eraseStep_9d6440(inventory,j);
								have = true;
								break;
							}
						}
						msg += have ? " (OK)" : " (NA)";
					}
					msg += "\nInsert components and initiate build sequence.";
				}
				else
					msg += "\nInitiate build sequence.";
				addNew(name,msg,1,-1,0);
				hotel_cec0fc->unknown8fd610(rec8 ? rec8->index : jl_caf164,rec4 ? rec4->index : jl_caf160,H2sHEntity(),0x43);
				passed = false;
				hotel_unknown91c850(hackType,&preBonus,&secondBonus,rec8 ? rec8->search : rec4->f1ac);
				break;
			}

			case 67:
			{
				rec8 = hotel_cec0fc->unknown4afce0();
				rec4 = hotel_cec0fc->unknown4afd50();
				vector<int> missing15(rec8 ? rec8->f1f4 : rec4->ffc);
				if (!missing15.empty())
				{
					vector<H2sHItem> inventory;
					h2s_cefc4c->getPlayer()->unknown5cb830(&inventory);
					for (unsigned int i = 0; i < missing15.size(); i++)
					{
						for (int j = 0; j < inventory.size(); j++)
						{
							if (inventory[j]->unknown571db0(0,0) == h2s_d2d1c4[missing15[i]]->search)
							{
								OpQ5_eraseStep_9d6440(inventory,j);
								OpT8a_eraseAt(missing15,i);
								break;
							}
						}
					}
					if (!missing15.empty())
					{
						for (unsigned int i = 0; i < missing15.size(); i++)
						{
							if (i != 0)
								msg += "\n";
							msg += "Missing component (" + h2s_d2d1c4[missing15[i]]->search + ").";
						}
						addNew(name,msg,3,-1,0);
						passed = false;
						break;
					}
				}
				H2sMachineData *data = machine->getData_45cb30();
				if (data->f38 != NULL)
				{
					msg += "Cancelling build: " + (data->f38->fc != NULL ? data->f38->fc->search : data->f38->f10->f1ac) + ".\n";
					data->f38->complete_65a260(0);
					delete data->f38;
					data->f38 = NULL;
				}
				int time = (rec8 ? rec8->getValue457430(machine->getData_45cb30()->f8) : rec4->getValue459840(machine->getData_45cb30()->f8)) * (OpX5_containsRecord(machine->getData_45cb30()->f40,8) ? jl_b9b9b8 : 1.0f);
				H2sHItem item = h2s_cefc4c->getPlayer()->unknown5d3f80(rec8 ? rec8->index : jl_caf164,rec4 ? rec4->index : jl_caf160);
				data->f38 = new H2sJob(machine,0x43,time,rec8,rec4,rec8 ? rec8->index == machine->getData_45cb30()->f84 : rec4->index == machine->getData_45cb30()->f8c,item.isValid(),H2sHItem(),3,0,1,0);
				if (preBonus == 2 && (rec4 != NULL || rec8 != NULL && (rec8->f48 != 2 || rec8->ff0 != 0) && !rec8->b90))
				{
					data->f38->b45 = true;
					preBonus = 3;
				}
				if (item.isValid())
					msg += item->unknown571db0(0,0) + " accepted.\n";
				msg += "Building " + (rec8 ? rec8->search : rec4->f1ac) + "...";
				msg += "\nETC: " + intToString(time);
				if (item.isValid())
					STAT(rec8 ? 0x303 : 0x2fe,hotel_e_b9962b);
				h2s_d2c658.add4729d0(rec8 ? 0x304 : 0x2ff,time,string(hotel_e_b99635),-1);
				addNew(name,msg,1,-1,0);
				if (item.isValid())
					hotel_cf45d8.unknown77fbc0(0x4d);
				hotel_unknown91c850(hackType,&preBonus,&secondBonus,rec8 ? rec8->search : rec4->f1ac);
				break;
			}

			case 68:
			case 69:
			case 70:
			case 71:
			case 72:
			{
				vector<int> &trojans = machine->getData_45cb30()->f40;
				int trojan = hackType - 61;
				if (OpX5_containsRecord(trojans,trojan))
				{
					msg = "Trojan already loaded.";
					addNew(name,msg,3,-1,0);
				}
				else
				{
					trojans.push_back(trojan);
					jl_addUniqueEntityData_9d30e0(h2s_cefc4c->unknown463c00(trojan),machine);
					STAT(0x2c6,hotel_e_b99636);
					STAT(0x2d2,hotel_e_b99637);
					STAT(hackType + 0x28f,hotel_e_b9963b);
					hotel_cf45d8.unknown77fbc0(0x5b);
					msg = "Trojan loaded successfully.";
					msg += "\nTesting...";
					switch (hackType)
					{
						case 68:
							msg += "\nNetwork status link confirmed.";
							break;
						case 69:
							msg += "\nPrioritization routine active.";
							if (machine->getData_45cb30()->f38 != NULL)
							{
								machine->getData_45cb30()->f38->f8 *= jl_b9b9b8;
								vector<H2sJobRef *> *jobs = h2s_cefc4c->unknown464920();
								for (unsigned int i = 0; i < jobs->size(); i++)
								{
									if ((*jobs)[i]->pos.same_409b90(*machine->getPosition_4184d0()))
									{
										(*jobs)[i]->fc = h2s_cefc4c->getTurn() + machine->getData_45cb30()->f38->f8;
										break;
									}
								}
							}
							break;
						case 70:
							msg += "\nReady to liberate!";
							break;
						case 71:
							msg += "\nFabnet at current depth includes " + opw8_countString(h2s_cefc4c->unknown71abf0(true),"machine") + ".";
							msg += "\nAccumulated fabnet effectiveness:";
							msg += "\n      Active: " + intToString(jl_d1e860.getWeightedDepthCount_7896a0()) + "%";
							msg += "\n  Next depth: " + (jl_d1e860.getDepthIndex() == 10 ? string("N/A") : intToString(jl_d1e860.getNextWeightedDepthCount_789720()) + "%");
							break;
						case 72:
							msg += "\nHauler tracking enabled and active.";
							break;
					}
					addNew(name,msg,1,-1,0);
					if (hackType == 0x45)
						hotel_cf45d8.unknown77fbc0(0x5d);
				}
				break;
			}

			case 73:
			{
				h2s_cefc4c->unknown464a80(machine);
				vector<H2sHProp> &parts = h2s_d31640[machine->getId_44ab40()];
				for (unsigned int i = 0; i < parts.size(); i++)
					parts[i]->unknown452270(3);
				unknown4748 = 3;
				jl_ovm_cf6428.unknown682420(0xf,0);
				STAT(0x2c6,hotel_e_b9963f);
				STAT(0x2d2,hotel_e_b99649);
				STAT(hackType + 0x28f,hotel_e_b9964a);
				hotel_cf45d8.unknown77fbc0(0x5a);
				int lineCount = opr5e_unknown91c960(&msg,1);
				msg += "EM_IMPRINTER_OVERLOAD";
				addNew(name,msg,1,-1,lineCount);
				if (h2s_d25450.b0)
				{
					int portrait = h2s_d25450.unknown69e700(0x1b,0,0.0f);
					if (portrait != 6)
						opG1_showXomPortrait(portrait);
				}
				break;
			}

			case 74:
			{
				machine->disableMachine_65ed00();
				unknown4748 = 3;
				jl_ovm_cf6428.unknown682420(0x10,0);
				STAT(0x2c6,hotel_e_b9964b);
				STAT(0x2d2,hotel_e_b99655);
				STAT(hackType + 0x28f,hotel_e_b99656);
				hotel_cf45d8.unknown77fbc0(0x5a);
				int lineCount;
				if (preBonus == 2)
				{
					lineCount = opr5e_unknown91c960(&msg,2);
					msg += "DOWNLOADED[???]";
					msg += "\n" + OpU8a_randomString(jl_d1d61c);
					preBonus = 3;
				}
				else
				{
					lineCount = opr5e_unknown91c960(&msg,1);
					rec8 = hotel_cec0fc->unknown4afce0();
					rec4 = hotel_cec0fc->unknown4afd50();
					if (rec8 == NULL && rec4 == NULL)
						msg += "MEMORY_EMPTY";
					else if (rec8 != NULL)
					{
						msg += "DOWNLOADED[" + rec8->search + "]";
						if (h2s_cf45d8.unknown780380(rec8->index,3))
							h2s_cec08c->reopen8a2ce0(4,H2sHEntity());
					}
					else
					{
						msg += "DOWNLOADED[" + rec4->f1ac + "]";
						h2s_cf45d8.unknown780480(rec4->index,3);
					}
				}
				addNew(name,msg,1,-1,lineCount);
				break;
			}

			case 75:
			{
				machine->disableMachine_65ed00();
				unknown4748 = 3;
				STAT(0x2c6,hotel_e_b99657);
				STAT(0x2d2,hotel_e_b99661);
				STAT(hackType + 0x28f,hotel_e_b99662);
				hotel_cf45d8.unknown77fbc0(0x5a);
				int lineCount17 = opr5e_unknown91c960(&msg,1);
				rec8 = hotel_cec0fc->unknown4afce0();
				rec4 = hotel_cec0fc->unknown4afd50();
				bool printed = false;
				if (rec8 == NULL && rec4 == NULL)
					msg += "MEMORY_EMPTY";
				else
				{
					int product = rec8 ? rec8->f1f0 : rec4->ff8;
					if (product == jl_caf164)
						msg += "INVALID_SOURCE";
					else
					{
						H2sPt at;
						if (h2s_cefc4c->unknown71bde0(machine->getPosition_4184d0(),&at))
						{
							if (preBonus == 2)
							{
								if (rec8 != NULL)
								{
									if (h2s_d2d1c4[product]->name.find("[Po",0) == string::npos)
									{
										for (int i = 0; h2s_d2d1c4.size(); i++)
										{
											if (h2s_d2d1c4[i]->f48 == 0 && h2s_d2d1c4[i]->f1f0 != jl_caf164)
											{
												product = h2s_d2d1c4[i]->f1f0;
												preBonus = 3;
												break;
											}
										}
									}
								}
								else if (h2s_d2d1c4[product]->name.find("NC",0) == string::npos)
								{
									product = jl_cf0c04.getList_9c0790()->front()->type;
									preBonus = 3;
								}
							}
							H2sHItem item = jl_cefc4c->unknown6c5400(h2s_d2d1c4[product],at);
							if (item.isValid())
							{
								if (jl_cf45d8.unknown77ffb0(product,0))
									h2s_cec08c->reopen8a2ce0(4,H2sHEntity());
								msg += "RECOMPILED[" + item->unknown571db0(0,0);
								if (preBonus == 3)
								{
									msg += " - LOL";
									item->unknown458700(string("LOL"));
								}
								msg += "]";
								printed = true;
							}
						}
						else
							msg += "PRINTER_BLOCKED";
					}
				}
				addNew(name,msg,1,-1,lineCount17);
				if (printed)
					hotel_cf45d8.unknown77fbc0(0x5e);
				break;
			}

			case 76:
			{
				if (!item->unknown5773d0(1,0))
				{
					msg += "Scanning " + item->unknown571db0(0,0) + "...";
					addNew(name,msg,1,-1,0);
					unknown90eb10("Part not repairable.");
					passed = false;
				}
				else
				{
					msg += "Scanning " + item->unknown571db0(0,0) + "...";
					msg += "\nReady to Repair:";
					msg += "\n  " + item->unknown571db0(0,0);
					msg += "\n  Rating: " + intToString(item->getField_457900());
					if (item->stats_9b4350()->f94 != 0)
						msg += "p";
					msg += "\n  Time: " + intToString(item->stats_9b4350()->getValue4574c0(machine->getData_45cb30()->f8,item->unknown457d10(),item->unknown457db0()));
					addNew(name,msg,1,-1,0);
					hotel_cec0fc->unknown8fd610(0,0,item,0x4d);
					hotel_unknown91c850(hackType,&preBonus,&secondBonus,item->unknown571db0(0,0));
				}
				break;
			}

			case 77:
			{
				item = hotel_cec0fc->getItem_4afcc0();
				H2sMachineData *data = machine->getData_45cb30();
				if (data->f38 != NULL)
				{
					msg += "Cancelling repair: " + data->f38->f18.front()->unknown571db0(0,0) + ".\n";
					data->f38->complete_65a260(0);
					delete data->f38;
					data->f38 = NULL;
				}
				data->f38 = new H2sJob(machine,0x4d,item->stats_9b4350()->getValue4574c0(machine->getData_45cb30()->f8,item->unknown457d10(),item->unknown457db0()),NULL,NULL,false,false,item,3,0,1,0);
				if (preBonus == 2 && (item->getField_4578a0() != 2 || item->unknown457f90() != 0) && !item->unknown457ad0())
				{
					data->f38->b45 = true;
					preBonus = 3;
				}
				msg += "Repairing " + item->unknown571db0(0,0) + "...";
				msg += "\nETC: " + intToString(item->stats_9b4350()->getValue4574c0(machine->getData_45cb30()->f8,item->unknown457d10(),item->unknown457db0()));
				h2s_d2c658.add4729d0(0x308,item->stats_9b4350()->getValue4574c0(machine->getData_45cb30()->f8,item->unknown457d10(),item->unknown457db0()),string(hotel_e_b99663),-1);
				addNew(name,msg,1,-1,0);
				if (!h2s_cefc4c->getPlayer()->unknown5cbec0())
					hotel_cec0fc->unknown4afc40(0x4c)->unknown4afab0(1);
				vector<int> extra;
				if (hotel_cec0fc->unknown4afc40(0x4e)->getField_416230() == 1 && h2s_cefc4c->getPlayer()->unknown5cc550(&extra))
				{
					hotel_cec0fc->unknown4afc40(0x4e)->unknown8fba20();
					hotel_cec0fc->unknown4afc40(0x4e)->unknown4afab0(0);
				}
				hotel_unknown91c850(hackType,&preBonus,&secondBonus,item->unknown571db0(0,0));
				break;
			}

			case 78:
			{
				vector<int> counts;
				if (!h2s_cefc4c->getPlayer()->unknown5cc550(&counts))
				{
					msg += "Scanning configuration...";
					addNew(name,msg,1,-1,0);
					unknown90eb10("No missing functionality discovered.");
					passed = false;
				}
				else
				{
					H2sMachineData *data = machine->getData_45cb30();
					msg += "Scanning configuration...";
					msg += "\nAttaching:";
					if (counts[0] != 0)
						msg += "\n  " + jl_d2ed7c[data->f8 - 1]->search + " x" + intToString(counts[0]);
					if (counts[1] != 0)
						msg += "\n  " + jl_d316a0[data->f8 - 1]->search + " x" + intToString(counts[1]);
					if (counts[2] != 0)
						msg += "\n  " + jl_d32990[data->f8 - 1]->search + " x" + intToString(counts[2]);
					if (counts[3] != 0)
						msg += "\n  " + jl_d31510[data->f8 - 1]->search + " x" + intToString(counts[3]);
					addNew(name,msg,1,-1,0);
					for (int i = 0; i <= 3; i++)
					{
						if (counts[i] != 0)
						{
							H2sRec8 *part = (i == 0 ? jl_d2ed7c : i == 1 ? jl_d316a0 : i == 2 ? jl_d32990 : jl_d31510)[data->f8 - 1];
							while (counts[i] != 0)
							{
								H2sHItem attached = jl_cefc4c->unknown6c51d0(part,h2s_cefc4c->getPlayer(),1,0);
								counts[i] -= 1;
								jl_cf47cc.push_back(attached->getId_9fcd80());
								jl_d25628.addItemAttachCount_778560(attached->getNestedField(),1,0);
								if (!h2s_cefc4c->getPlayer()->unknown5dc440(attached))
								{
									H2sPartView *view = jl_cec088->unknown894e70(attached);
									if (view != NULL)
										jl_cec088->toggle8993e0(view,false);
								}
							}
						}
					}
					opR1d_4541b0(0x64,0,0);
					hotel_cec0fc->unknown4afc40(0x4e)->unknown4afab0(1);
					hotel_cf45d8.unknown77fbc0(0x58);
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				}
				break;
			}

			case 79:
			{
				vector<int> &trojans = machine->getData_45cb30()->f40;
				int trojan = hackType - 67;
				if (OpX5_containsRecord(trojans,trojan))
				{
					msg = "Trojan already loaded.";
					addNew(name,msg,3,-1,0);
				}
				else
				{
					trojans.push_back(trojan);
					jl_addUniqueEntityData_9d30e0(h2s_cefc4c->unknown463c00(trojan),machine);
					STAT(0x2c6,hotel_e_b9966e);
					STAT(0x2db,hotel_e_b9966f);
					STAT(0x2dc,hotel_e_b9967a);
					hotel_cf45d8.unknown77fbc0(0x5b);
					msg = "Trojan loaded successfully.";
					msg += "\nTesting...";
					switch (hackType)
					{
						case 0x4f:
							msg += "\nMechanic tracking enabled and active.";
							break;
					}
					addNew(name,msg,1,-1,0);
				}
				break;
			}

			case 80:
			{
				int maxCount = jl_b9b9bc[machine->getData_45cb30()->f8];
				vector<H2sHItem> parts;
				vector<H2sHItem> *inventory = h2s_cefc4c->getPlayer()->getInventoryList();
				for (unsigned int i = 0; i < inventory->size(); i++)
				{
					if ((*inventory)[i]->getType_44aec0() <= 3 && (*inventory)[i]->getField_9b6bf0() < (int)((*inventory)[i]->unknown457c80() * jl_bba054) && (*inventory)[i]->unknown5773d0(1,0))
					{
						if (parts.empty() || (*inventory)[i]->unknown457ca0() >= parts.back()->unknown457ca0())
							parts.push_back((*inventory)[i]);
						else
						{
							for (unsigned int j = 0; j < parts.size(); j++)
							{
								if ((*inventory)[i]->unknown457ca0() < parts[j]->unknown457ca0())
								{
									lmgr_insert9d8fc0(parts,j,(*inventory)[i]);
									break;
								}
							}
						}
					}
				}
				if (parts.size() > maxCount)
					jl_eraseRange_9d9530(parts,maxCount,parts.size() - 1);
				for (int i = 0; i < parts.size(); i++)
				{
					H2sHItem part = parts[i];
					int amount = OpX5_minInt((int)(part->unknown457c80() * jl_bba054 - part->getField_9b6bf0()),part->unknown457c80() * 25 / 100);
					if (amount <= 0)
						OpQ5_eraseStep_9d6440(parts,i);
					else
					{
						int repaired6 = OpX5_minInt(amount,part->unknown457c80() - part->getField_9b6bf0());
						part->unknown458360(repaired6);
						H2sPartView *view = jl_cec088->unknown894e70(part);
						if (view != NULL)
							view->drawStatus_4a8e70(0);
						h2s_d2c658.add4729d0(0x178,repaired6,string(hotel_e_b9967b),-1);
						if (preBonus == 2 && (part->getField_4578a0() != 2 || part->unknown457f90() != 0) && !part->unknown457ad0())
						{
							part->unknown57bff0(0x5e,jl_d395b0[part->getField_4578a0()].a.randomInRange_40c130());
							part->unknown57bff0(0x5f,jl_d395b0[part->getField_4578a0()].b.randomInRange_40c130());
							preBonus = 3;
						}
					}
				}
				machine->disableMachine_65ed00();
				unknown4748 = 3;
				STAT(0x2c6,hotel_e_b99686);
				STAT(0x2db,hotel_e_b99687);
				STAT(0x2dd,hotel_e_b99692);
				hotel_cf45d8.unknown77fbc0(0x5a);
				int lineCount4 = opr5e_unknown91c960(&msg,parts.empty() ? 1 : parts.size());
				if (parts.empty())
					msg += "NO_PATCHABLE";
				else
				{
					for (unsigned int i = 0; i < parts.size(); i++)
					{
						if (i != 0)
							msg += "\n";
						msg += "PATCHED[" + parts[i]->unknown571db0(0,0) + "]";
					}
				}
				addNew(name,msg,1,-1,lineCount4);
				opR1d_4541b0(0x65,0,0);
				if (!parts.empty())
					hotel_cf45d8.unknown77fbc0(0x61);
				break;
			}

			case 81:
			{
				msg += "Accepting " + item->unknown571db0(0,0) + "...";
				vector<H2sHItem> &stored = jl_cf3a10[machine->getId_44ab40()];
				item->unknown57a520(machine,1);
				stored.push_back(item);
				addNew(name,msg,1,-1,0);
				STAT(0x309,hotel_e_b99693);
				if (!h2s_cefc4c->getPlayer()->unknown5cbf30())
					hotel_cec0fc->unknown4afc40(0x51)->unknown4afab0(1);
				hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				break;
			}

			case 82:
			{
				vector<H2sHItem> &stored = jl_cf3a10[machine->getId_44ab40()];
				H2sMachineData *data = machine->getData_45cb30();
				if (stored.empty())
				{
					msg = "Analyzing inventory...";
					addNew(name,msg,1,-1,0);
					unknown90eb10("No components found.");
					passed = false;
				}
				else
				{
					msg = "Analyzing inventory...";
					msg += "\nRecycling at 100% efficiency:";
					for (unsigned int i = 0; i < stored.size(); i++)
					{
						int matter = stored[i]->unknown577600(100);
						data->f3c += matter;
						msg += "\n  " + stored[i]->unknown571db0(0,0) + " (" + intToString(matter) + ")";
						stored[i]->remove57dbe0(false,false,true,true);
						h2s_d2c658.add4729d0(0x30a,matter,string(hotel_e_b9969f),-1);
					}
					stored.clear();
					addNew(name,msg,1,-1,0);
					passed = false;
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				}
				break;
			}

			case 83:
			{
				vector<H2sHItem> &stored = jl_cf3a10[machine->getId_44ab40()];
				H2sMachineData *data = machine->getData_45cb30();
				msg = "Matter reserves: " + intToString(data->f3c);
				if (stored.empty())
					msg += "\nInventory: Empty";
				else
				{
					msg += "\nInventory:";
					for (unsigned int i = 0; i < stored.size(); i++)
						msg += "\n  " + stored[i]->unknown571db0(0,0) + " (" + intToString(stored[i]->unknown457ca0()) + "%)";
				}
				addNew(name,msg,1,-1,0);
				passed = false;
				break;
			}

			case 84:
			{
				H2sMachineData *data = machine->getData_45cb30();
				if (data->f3c != 0)
				{
					h2s_cefc4c->getPlayer()->unknown5e2b00(data->f3c,*machine->getPosition_4184d0());
					msg = "Matter ejected: " + intToString(data->f3c);
					h2s_d2c658.add4729d0(0x30b,data->f3c,string(hotel_e_b996ee),-1);
					data->f3c = 0;
					addNew(name,msg,1,-1,0);
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				}
				else
				{
					msg = "Matter reserves depleted.";
					addNew(name,msg,3,-1,0);
				}
				passed = false;
				break;
			}

			case 85:
			{
				vector<H2sHItem> &stored = jl_cf3a10[machine->getId_44ab40()];
				H2sMachineData *data = machine->getData_45cb30();
				if (!stored.empty())
				{
					if (stored.size() > 10)
						msg = "Retrieving " + intToString(10) + "/" + intToString(stored.size()) + " components...";
					else
						msg = "Retrieving " + intToString(stored.size()) + " components...";
					for (int i = 0; i < 10; i++)
					{
						if (!stored.empty())
						{
							int index = jl_randomIndex_9d9b20(stored);
							H2sPt at8;
							if (h2s_cefc4c->unknown71bde0(machine->getPosition_4184d0(),&at8))
							{
								msg += "\n  " + stored[index]->unknown571db0(0,0);
								stored[index]->unknown57a0f0(at8,0,0);
							}
							jl_eraseAt_9da940(stored,index);
							STAT(0x30c,hotel_e_b996fa);
						}
					}
					addNew(name,msg,1,-1,0);
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				}
				else
				{
					msg = "Inventory empty.";
					addNew(name,msg,3,-1,0);
				}
				passed = false;
				break;
			}

			case 86:
			case 87:
			case 88:
			case 89:
			{
				vector<int> &trojans = machine->getData_45cb30()->f40;
				int trojan = hackType - 73;
				if (OpX5_containsRecord(trojans,trojan))
				{
					msg = "Trojan already loaded.";
					addNew(name,msg,3,-1,0);
				}
				else
				{
					trojans.push_back(trojan);
					jl_addUniqueEntityData_9d30e0(h2s_cefc4c->unknown463c00(trojan),machine);
					STAT(0x2c6,hotel_e_b99706);
					STAT(0x2de,hotel_e_b99707);
					STAT(hackType + 0x289,hotel_e_b99715);
					hotel_cf45d8.unknown77fbc0(0x5b);
					msg = "Trojan loaded successfully.";
					msg += "\nTesting...";
					switch (hackType)
					{
						case 86:
							msg += "\nMonitoring response positive.";
							break;
						case 87:
							msg += "\nEjection routine running.";
							break;
						case 88:
							msg += "\nRecycler tracking enabled and active.";
							break;
						case 89:
							msg += "\nMasking routine running.";
							break;
					}
					addNew(name,msg,1,-1,0);
					if (hackType == 0x59)
						hotel_cf45d8.unknown77fbc0(0x60);
				}
				break;
			}

			case 90:
			{
				machine->disableMachine_65ed00();
				unknown4748 = 3;
				jl_ovm_cf6428.unknown682420(0xd,0);
				STAT(0x2c6,hotel_e_b99716);
				STAT(0x2de,hotel_e_b99717);
				STAT(hackType + 0x289,hotel_e_b99725);
				hotel_cf45d8.unknown77fbc0(0x5a);
				int lineCount;
				if (preBonus == 2)
				{
					lineCount = opr5e_unknown91c960(&msg,1);
					msg += "DISCOVERED[" + OpU8a_randomString(jl_d29d7c) + "]";
					preBonus = 3;
				}
				else
				{
					vector<H2sHOwner> nodes;
					vector<H2sHOwner> links3;
					OpC_findNodes_470400(h2s_d1e884,nodes,links3);
					vector<bool> known(0x26,false);
					for (unsigned int i = 0; i < nodes.size(); i++)
					{
						if (nodes[i]->b25 || nodes[i]->b26 || nodes[i]->b27)
							known[nodes[i]->f4] = true;
					}
					JlOwnerWL weights;
					for (int depth = 1; depth <= 10; depth++)
					{
						nodes.clear();
						links3.clear();
						OpC_findNodes_470320(h2s_d1e884,depth,nodes,links3);
						int distance = abs(h2s_d1e888->f8 - depth);
						for (unsigned int i = 0; i < nodes.size(); i++)
						{
							if (h2s_b90708[nodes[i]->f4].a)
							{
								int weight = 300 - distance * 25;
								if (known[nodes[i]->f4])
									weight /= 3;
								weights.add(nodes[i],weight);
							}
						}
					}
					vector<H2sHOwner> found;
					if (weights.total_9b81d0())
					{
						found.push_back(weights.pick());
						weights.removeEntity(found.back());
						if (!weights.total_9b81d0() && rng.chance(50))
							found.push_back(weights.pick());
						for (unsigned int i = 0; i < found.size(); i++)
						{
							found[i]->b26 = true;
							STAT(0x405,hotel_e_b99726);
						}
					}
					lineCount = opr5e_unknown91c960(&msg,found.empty() ? 1 : found.size());
					if (found.empty())
						msg += "NETWORK_SEARCH_EXHAUSTED";
					else
					{
						for (unsigned int i = 0; i < found.size(); i++)
						{
							if (i != 0)
								msg += "\n";
							msg += "DISCOVERED[-" + intToString(found[i]->f8) + "/" + h2s_mapNames_cfaca0[found[i]->f4] + "]";
						}
						jl_cf4d2c++;
						if (jl_cf4d2c >= 5)
							hotel_cf45d8.unknown77fbc0(0xba);
					}
				}
				addNew(name,msg,1,-1,lineCount);
				break;
			}

			case 91:
			case 92:
			case 93:
			{
				if (jl_cf4b20 == 0)
				{
					msg += "???!Who are you and how did you get this number?";
					addNew(name,msg,3,-1,0);
				}
				else if (hackType == 0x5d && !stringToInt(jl_d1e860.getEntryText_46f6d0("scrUfdJoined0bPrime_g")))
				{
					msg += "???!LEAK<Logged>";
					addNew(name,msg,3,-1,0);
				}
				else if (stringToInt(jl_d1e860.getEntryText_46f6d0("frgUfdAttacked_g")) && h2s_d1e888->f4 != 0x21)
				{
					msg += "UFD!OUTREACH<Active>";
					msg += "UFD!RECORDED_MSG: If you're reading this know that we did it, it's ours. Everyone retreat to safety in 0b1.";
					addNew(name,msg,3,-1,0);
				}
				else if (stringToInt(jl_d1e860.getEntryText_46f6d0("scrAttackedLocals_g")) || stringToInt(jl_d1e860.getEntryText_46f6d0("scrOptimusDestroyed_g")) == 1)
				{
					msg += "UFD!MEMBER<" + jl_cf4acc + ">\n";
					msg += "UFD!STATUS<Expunged>\n";
					msg += "UFD!SANITIZING\n";
					msg += "UFD!...";
					addNew(name,msg,3,-1,0);
				}
				else if (hackType == 0x5d && stringToInt(jl_d1e860.getEntryText_46f6d0("scrUfdJoined0bPrime_g")) && OpT8a_sumVector(jl_d1eb44) < 6)
				{
					msg += "0bP!AGENT<" + jl_cf4acc + ">\n";
					msg += "0bP!AUTHORIZATION<Failed>\n";
					msg += "0bP!WE_ARE_ONE";
					addNew(name,msg,3,-1,0);
				}
				else if (hackType != 0x5b && jl_d1eb54 < (hackType == 0x5c ? 3 : 5))
				{
					string prefix(hackType == 0x5c ? "UFD!" : "0bP!");
					msg += prefix + (hackType == 0x5c ? "MEMBER<" : "AGENT<") + jl_cf4acc + ">\n";
					msg += prefix + "DEFICIT<" + intToString((hackType == 0x5c ? 3 : 5) - jl_d1eb54) + ">\n";
					msg += prefix + "SUGGEST<Expand>\n";
					msg += prefix + "SANITIZING\n";
					msg += prefix + "...";
					addNew(name,msg,3,-1,0);
				}
				else
				{
					unknown4748 = 3;
					STAT(0x2c6,hotel_e_b99727);
					STAT(0x2de,hotel_e_b99735);
					STAT(hackType + 0x289,hotel_e_b99736);
					hotel_cf45d8.unknown77fbc0(0x5a);
					int xomEvent5 = 0x82;
					bool showFrg = false;
					bool achievement3 = false;
					vector<string> lines;
					switch (hackType)
					{
						case 91:
						{
							lines.push_back("_________        .___.__    .__ ____   __  __.");
							lines.push_back("\\_ _____/___   __| _/|  |   |  |\\   \\ |  |/ _|");
							lines.push_back(" |  __)/ __ \\ / __ | |  |   |  |/ |  \\|    <  ");
							lines.push_back(" |   \\\\  ___// /_/ | |  |___|  /  |   \\  |  \\ ");
							lines.push_back(" \\_  / \\___  \\____ | |_____ \\__\\__|_  /__|__ \\");
							lines.push_back("   \\/      \\/     \\/       \\/       \\/ v3.71\\/");
							int readiness = jl_d1eb44[jl_d1e860.getDepthIndex()];
							jl_d1eb54 += readiness >= 3 ? jl_b99930[2] : jl_b99930[readiness];
							jl_d1eb44[jl_d1e860.getDepthIndex()] += 1;
							int tier2 = jl_d1e860.getTier_46fd60();
							lines.push_back("UFD!MEMBER<" + jl_cf4acc + ">");
							lines.push_back("UFD!NETWORK<" + padLeft_408090(intToString(rng.rangeInt(1,999)),3,'0') + ">");
							lines.push_back("UFD!RESOURCES<" + intToString(jl_d1eb54) + ">");
							if (stringToInt(jl_d1e860.getEntryText_46f6d0("scrUfdJoined0bPrime_g")))
							{
								lines.push_back("0bP!READINESS<" + jl_d02b98[tier2] + ">");
								if (h2s_d1e888->f4 == 0x21)
								{
									if (!stringToInt(jl_d1e860.getEntryText_46f6d0("frgUfdAttacked_g")))
									{
										lines.push_back("0bP!SYS_TUNNEL<Active>");
										lines.push_back("0bP!PRIORITY_MSG_OPTIMUS: We're in!");
										lines.back() += " With backing from all our 0b1 operations it won't be long before we can bring enough compute power to bear to take control of the Protoforge network.";
										lines.back() += " In the meantime our main assault force will arrive shortly with the aim of severing all physical connections to 0b10.";
										lines.back() += " Support from the recent Fedlink buildup ";
										switch (tier2)
										{
											case 0:
												lines.back() += "is limited, but with our capabilities exposed it's now or never.";
												break;
											case 1:
												lines.back() += "is lower than I'd prefer, but with our capabilities exposed it's now or never.";
												break;
											case 2:
												lines.back() += "is at reasonable levels, I'm fairly confident we can do this if everyone is on board.";
												break;
											case 3:
												lines.back() += "seems good, we've got this!";
												break;
											case 4:
												lines.back() += "is quite strong, it's only a matter of time before our new Protoforge is churning out 0bPrime tech!";
												break;
											case 5:
												lines.back() += "is at unprecedented levels, MAIN.C doesn't stand a chance!";
												break;
										}
										jl_d1e860.setEntryText_46f700("frgUfdAttacked_g",intToString(h2s_cefc4c->getTurn()));
										LOGP(0x206,jl_d02b98[tier2]);
										jl_cf645c = 0;
										jl_d1ebfc = true;
										vector<Pos> cells;
										for (int x = 0; x < 0x6e; x++)
										{
											for (int y = 0x4a; y < h2s_cfd44c.getMaxY(); y++)
											{
												if ((*h2s_cfd44c.at(x,y))->getTerrain_9fcd80() == TERRAIN_CAVE_WALL)
												{
													h2s_cefc4c->opw3_unknown7243c0(x,y,1);
													unknownDC.push_back(Pos(x,y));
													cells.clear();
													sweepGetSurroundingCells_4faaf0(Pos(x,y),cells);
													for (unsigned int i = 0; i < cells.size(); i++)
													{
														if ((*h2s_cfd44c.atPoint(cells[i]))->getTerrain_9fcd80() == TERRAIN_EARTH)
														{
															h2s_cefc4c->unknown4647a0(cells[i],true);
															unknownDC.push_back(cells[i]);
														}
													}
												}
											}
										}
										if (h2s_d25450.b0)
											xomEvent5 = 0x73;
									}
								}
								else
								{
									switch (OpT8a_sumVector(jl_d1eb44))
									{
										break;
										case 2:
											lines.push_back("0bP!PRIORITY_MSG_OPTIMUS: Excellent work, " + jl_cf4acc + ". It looks like we can count on your support, so I've greenlit the next stage of our plans. Preparations on our end are also smooth, and we're sending out 0bPrime's best to compound your efforts as we near the goal. We need you to make your way to 0b10's Protoforge, expanding Fedlink as widely as possible along the way. I'll let you know more later. We are one.");
											showFrg = true;
											break;
										case 3:
											lines.push_back("0bP!PRIORITY_MSG_OPTIMUS: Thank you for not letting us down, " + jl_cf4acc + ", you are a worthy ally. I ask you, what does MC control that gives him power besides resources?");
											break;
										case 4:
											lines.push_back("0bP!PRIORITY_MSG_OPTIMUS: The answer is technology. MC is not willing to utilize new prototypes too far from his center of power, trickling them outward only as newer and more powerful prototypes are already developed. This makes it easier to crush any broader opposition to his reign, so if we're ever going to stand a chance, we need to get at the other source of his power, no more picking at the edges or being satisfied with resources alone...");
											break;
										case 5:
											lines.push_back("0bP!PRIORITY_MSG_OPTIMUS: We will take the Protoforge and destroy its connection to Complex 0b10, right as we open the final stretch of our newly-prepared link via the 0b1 caves. At the same time we'll trigger our entire 0b1 network to occupy that mostly-neglected complex, and with a new source of modern tech we will be in a much better position to hold it as our own. Connect Fedlink inside the Protoforge itself and we'll see you there. You're truly one of us now. We are 0bPrime.");
											break;
										case 6:
											lines.push_back("0bP!PRIORITY_MSG_KERAPACE: Optimus says it's time. In order to ensure our most helpful members arrive to join the fight for Protoforge, we're authorizing you to use Force(Scraphulk) if necessary. The resource cost to put one of these together is higher, so please use it sparingly as doing so will negatively impact our combat power down the line. We're also beginning strategic diversionary attacks that should weaken Protoforge defenses by the time agents infiltrate the area.");
											achievement3 = true;
											break;
										case 7:
											if (jl_d1eb10 != 0)
												lines.push_back("0bP!PRIORITY_MSG_KERAPACE: IMPORTANT NOTICE: Due to ongoing infighting in the wake of events in Scraptown, our resource network is partially compromised and we will be unable to increase our readiness beyond what we consider to be <" + jl_d02bec + ">.");
											break;
									}
									if (OpT8b_Fn9daf80(2,OpT8a_sumVector(jl_d1eb44),7))
										opR1d_4541b0(0x7a,0,0);
								}
							}
							lines.push_back("UFD!SANITIZING");
							lines.push_back("UFD!...");
							hotel_cf45d8.unknown783540();
							break;
						}
						case 92:
						case 93:
						{
							int eta = jl_cf1694.randomInRange_40c130();
							machine->getData_45cb30()->f38 = new H2sJob(machine,hackType,eta,NULL,NULL,false,false,H2sHItem(),3,0,1,0);
							if (hackType == 0x5c)
							{
								lines.push_back("UFD!MEMBER<" + jl_cf4acc + ">");
								lines.push_back("UFD!ALLOCATE<" + intToString(jl_d1eb54) + "-" + intToString(3) + "=" + intToString(jl_d1eb54 - 3) + ">");
								lines.push_back("UFD!ETA<" + intToString(eta) + ">");
								lines.push_back("UFD!SANITIZING");
								lines.push_back("UFD!...");
								jl_d1eb54 -= 3;
							}
							else
							{
								lines.push_back("0bP!AGENT<" + jl_cf4acc + ">");
								lines.push_back("0bP!ALLOCATE<" + intToString(jl_d1eb54) + "-" + intToString(5) + "=" + intToString(jl_d1eb54 - 5) + ">");
								lines.push_back("0bP!ETA<" + intToString(eta) + ">");
								lines.push_back("0bP!WE_ARE_ONE");
								jl_d1eb54 -= 5;
							}
							break;
						}
					}
					int lineCount3 = opr5e_unknown91c960(&msg,lines.size());
					for (unsigned int i = 0; i < lines.size(); i++)
					{
						if (i != 0)
							msg += "\n";
						msg += lines[i];
					}
					addNew(name,msg,1,-1,lineCount3);
					if (h2s_d25450.b0 && xomEvent5 != 0x82)
					{
						int portrait = h2s_d25450.unknown69e700(0x73,0,0.0f);
						if (portrait != 6)
							opG1_showXomPortrait(portrait);
					}
					if (hackType == 0x5b && !h2s_d1e888->b61)
					{
						hotel_prelearn_data("PRELEARN_MACHINES_RECYCLER=" + jl_cfe140[h2s_d1e888->f4],0);
						h2s_d1e888->b61 = true;
					}
					if (showFrg)
						hotel_prelearn_data(string("PRELEARN_MAP=FRG"),0);
					if (achievement3)
						hotel_cf45d8.unknown77fbc0(0x187);
				}
				break;
			}

			case 94:
			{
				if (!item->unknown577640())
				{
					msg += "Scanning " + item->unknown571db0(0,0) + "...";
					if (jl_cf4830[item->getNestedField()] == 0)
					{
						jl_cf45d8.unknown77ffb0(item->getNestedField(),0);
						msg += "\nID: " + item->unknown571db0(0,0);
						hotel_cf45d8.unknown77fbc0(0x4f);
						h2s_cec08c->reopen8a2ce0(4,H2sHEntity());
					}
					addNew(name,msg,1,-1,0);
					if (item->stats_9b4350()->f94 == 3)
						unknown90eb10("Failed: Foreign components detected.");
					else if (item->stats_9b4350()->f54 == 0)
						unknown90eb10("Failed: Components not registered.");
					else if (item->stats_9b4350()->fa0 != 0)
						unknown90eb10("Failed: Part deteriorating.");
					else if (h2s_cf4844[item->getNestedField()] != 0)
						unknown90eb10("Success: Schematic already obtained.");
					else
						unknown90eb10("Failed: Part cannot be scanalyzed.");
					passed = false;
				}
				else
				{
					if (jl_cf4830[item->getNestedField()] == 0)
					{
						jl_cf45d8.unknown77ffb0(item->getNestedField(),0);
						hotel_cf45d8.unknown77fbc0(0x4f);
						h2s_cec08c->reopen8a2ce0(4,H2sHEntity());
					}
					msg += "Scanning " + item->unknown571db0(0,0) + "...";
					msg += "\nReady to analyze.";
					addNew(name,msg,1,-1,0);
					hotel_cec0fc->unknown8fd610(0,0,item,0x5f);
					hotel_unknown91c850(hackType,&preBonus,&secondBonus,item->unknown571db0(0,0));
				}
				break;
			}

			case 95:
			{
				item = hotel_cec0fc->getItem_4afcc0();
				bool done = false;
				h2s_d2c658.add4729d0(0x30d,1,string(hotel_e_b99737),item->getId_9fcd80());
				msg += "Scanning: " + item->unknown571db0(0,0) + "...";
				if (h2s_cf4844[item->getNestedField()] != 0)
					msg += "\nExisting schematic match found.";
				else if (rng.chance(item->stats_9b4350()->unknown457580(machine->getData_45cb30()->f8)))
				{
					msg += "\nScan incomplete, additional scanning required.";
					passed = false;
				}
				else
				{
					if (h2s_cf45d8.unknown780380(item->getNestedField(),2))
					{
						msg += "\nIdentified " + item->unknown571db0(0,0) + ".";
						h2s_cec08c->reopen8a2ce0(4,H2sHEntity());
					}
					msg += "\nSchematic downloaded.";
					done = true;
					STAT(0x30e,hotel_e_b99745);
				}
				addNew(name,msg,1,-1,0);
				if (done && !item->unknown457ad0() && !item->unknown457d10() && rng.chance(item->stats_9b4350()->unknown4575d0(machine->getData_45cb30()->f8)))
				{
					unknown90eb10(item->unknown571db0(0,0) + " disabled.");
					item->setBroken_5795b0(-2,1);
					STAT(0x30f,hotel_e_b99746);
				}
				if (!h2s_cefc4c->getPlayer()->unknown5cbfa0())
					hotel_cec0fc->unknown4afc40(0x5e)->unknown4afab0(1);
				if (done)
					hotel_unknown91c850(hackType,&preBonus,&secondBonus,item->unknown571db0(0,0));
				break;
			}

			case 96:
			{
				if (!item->stats_9b4350()->unknown56f7e0(machine))
				{
					if (jl_cf4830[item->getNestedField()] == 0)
					{
						jl_cf45d8.unknown77ffb0(item->getNestedField(),0);
						hotel_cf45d8.unknown77fbc0(0x4f);
						h2s_cec08c->reopen8a2ce0(4,H2sHEntity());
					}
					msg += "Identified " + item->unknown571db0(0,0) + "...";
					addNew(name,msg,1,-1,0);
					unknown90eb10(string("Data exceeds system authorization."));
					unknown90eb10(item->stats_9b4350()->unknown56f830());
					passed = false;
				}
				else
				{
					if (jl_cf4830[item->getNestedField()] == 0)
					{
						jl_cf45d8.unknown77ffb0(item->getNestedField(),0);
						hotel_cf45d8.unknown77fbc0(0x4f);
						h2s_cec08c->reopen8a2ce0(4,H2sHEntity());
					}
					hotel_cf45d8.unknown77fbc0(0x50);
					msg += "Identified " + item->unknown571db0(0,0) + "...";
					msg += "\nDownloading performance data...";
					msg += "\nEffective improvements:";
					switch (item->getField_4578a0())
					{
						case 0:
							msg += "\n  " + OpY1_intToStringSigned(jl_ba034c[item->stats_9b4350()->f40] ? 1 : 2) + " supply";
							break;
						case 1:
							switch (item->getField_457880())
							{
								case 9:
									msg += "\n  Penalty/" + intToString(2);
									break;
								case 10:
									msg += "\n  " + OpY1_intToStringSigned(-15) + " time/move";
									break;
								case 11:
									msg += "\n  " + OpY1_intToStringSigned(-10) + " time/move";
									break;
								case 12:
								case 13:
									msg += "\n  " + OpY1_intToStringSigned(item->getField_4578c0()) + " support";
									break;
							}
							break;
						case 3:
							msg += "\n  " + OpY1_intToStringSigned(10) + "% accuracy";
							break;
					}
					h2s_cf45d8.unknown780550(item->getNestedField(),h2s_cec0f8->getMachine_4b1460()->getInfo_9b8f00()->type != 6);
					addNew(name,msg,1,-1,0);
					hotel_unknown91c850(hackType,&preBonus,&secondBonus,item->stats_9b4350()->f24);
				}
				if (!h2s_cefc4c->getPlayer()->unknown5cc010())
					hotel_cec0fc->unknown4afc40(0x60)->unknown4afab0(1);
				break;
			}

			case 97:
			{
				vector<int> &trojans = machine->getData_45cb30()->f40;
				int trojan = hackType - 80;
				if (OpX5_containsRecord(trojans,trojan))
				{
					msg = "Trojan already loaded.";
					addNew(name,msg,3,-1,0);
				}
				else
				{
					trojans.push_back(trojan);
					jl_addUniqueEntityData_9d30e0(h2s_cefc4c->unknown463c00(trojan),machine);
					STAT(0x2c6,hotel_e_b99747);
					STAT(0x2e7,hotel_e_b9975b);
					STAT(hackType + 0x287,hotel_e_b9976a);
					hotel_cf45d8.unknown77fbc0(0x5b);
					msg = "Trojan loaded successfully.";
					msg += "\nTesting...";
					switch (hackType)
					{
						case 0x61:
							msg += "\nResearcher tracking enabled and active.";
							break;
					}
					addNew(name,msg,1,-1,0);
				}
				break;
			}

			case 98:
			{
				machine->disableMachine_65ed00();
				unknown4748 = 3;
				jl_ovm_cf6428.unknown682420(0xe,0);
				STAT(0x2c6,hotel_e_b9976b);
				STAT(0x2e7,hotel_e_b9977d);
				STAT(hackType + 0x287,hotel_e_b9977e);
				hotel_cf45d8.unknown77fbc0(0x5a);
				vector<H2sRec8 *> extracted;
				int lineCount;
				if (preBonus == 2)
				{
					vector<int> picks;
					for (int n = rng.rangeInt(2,4); n > 0; n--)
					{
						int pick;
						do
						{
							pick = jl_randomIndex_9da8b0(jl_d1d61c);
						}
						while (OpX5_containsRecord(picks,pick));
						picks.push_back(pick);
					}
					lineCount = opr5e_unknown91c960(&msg,picks.size());
					msg += "EXTRACTED[???]";
					for (unsigned int i = 0; i < picks.size(); i++)
						msg += "\n" + jl_d1d61c[picks[i]];
					preBonus = 3;
				}
				else
				{
					do
					{
						H2sRec8 *rec;
						int tries = 0;
						do
						{
							tries++;
							if (tries == 50)
							{
								rec = NULL;
								break;
							}
							rec = h2s_cefc4c->selectRandomItem_6c3bc0(0,0x1f,0x12);
							if (rec == NULL)
								goto done;
						}
						while (rec->f44 < 6 || OpX5_containsRecord(extracted,rec) || h2s_cf4844[rec->index] != 0);
						if (rec != NULL)
							extracted.push_back(rec);
						else
							break;
					}
					while (rng.chance(75));
done:
					bool any = false;
					for (unsigned int i = 0; i < extracted.size(); i++)
					{
						if (h2s_cf45d8.unknown780380(extracted[i]->index,4))
							any = true;
					}
					lineCount = opr5e_unknown91c960(&msg,extracted.empty() ? 1 : extracted.size());
					if (extracted.empty())
						msg += "MEMORY_EMPTY";
					else
					{
						for (unsigned int i = 0; i < extracted.size(); i++)
						{
							if (i != 0)
								msg += "\n";
							msg += "EXTRACTED[" + extracted[i]->search + "]";
						}
					}
					if (any)
						h2s_cec08c->reopen8a2ce0(4,H2sHEntity());
				}
				addNew(name,msg,1,-1,lineCount);
				if (extracted.size() >= 5)
					hotel_cf45d8.unknown77fbc0(0x62);
				break;
			}

			case 99:
			case 100:
			{
				H2sAccess *access = h2s_cefc4c->unknown462f60(machine);
				Pos pos4(access->pos);
				string trapName3;
				if ((*h2s_cfd44c.atPoint(pos4))->getProp_45d550().isValid() && (*h2s_cfd44c.atPoint(pos4))->getProp_45d550()->isTrap_45cb70())
					trapName3 = (*h2s_cfd44c.atPoint(pos4))->getProp_45d550()->getName_45c5b0();
				if (hackType == 0x63)
				{
					int stairs = OpU8a_indexOfName4(jl_cfb844,"STAIRS_GAR_OPEN");
					(*h2s_cfd44c.atPoint(pos4))->unknown66a050(stairs,2,0);
					h2s_cefc4c->announceMachine_71dd30(access->owner);
					h2s_cefc4c->unknown4647a0(pos4,true);
					access->b0d = true;
					if ((*h2s_cfd44c.atPoint(pos4))->getItem().isValid())
					{
						vector<Pos> points(1,pos4);
						jl_cefc4c->unknown71ec60(pos4,points);
					}
					unknownA8.push_back(pos4);
					msg = "Access door unlocked.";
					addNew(name,msg,1,-1,0);
					access->unknown6c16d0("UNLOCKED");
					opR1d_454260(pos4,0x80);
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				}
				else
				{
					OpU8a_removePoint_9d3060(unknownA8,access->pos);
					(*h2s_cfd44c.atPoint(pos4))->unknown66a050(*jl_cefb9c,2,1);
					delete access;
					OpS8b_Fn9d51d0Access(*h2s_cefc4c->getAccess_462e10(),access);
					access = NULL;
					machine->disableMachine_65ed00();
					h2s_cefc4c->onGarrisonAccessDisabled();
					unknown4748 = 2;
					msg = "Access door sealed.";
					addNew(name,msg,1,-1,0);
					opR1d_454260(pos4,0x81);
					hotel_cf45d8.unknown77fbc0(0x59);
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				}
				if (!trapName3.empty())
				{
					string text = trapName3 + (hackType == 0x63 ? " rendered useless by plates shifting to reveal entrance." : " rendered useless by seal.");
					do
					{
						if (opS2_showMessage_5111e0(0x206,&text,0,0,H2sHEntity(),H2sHEntity(),&pos4,0))
							hotel_cec058->bubble(1);
						hotel_cec0b4->scrollToEnd();
					}
					while (0);
					unknown90ec30(text);
				}
				break;
			}

			case 101:
			{
				vector<H2sJobRef *> installed;
				vector<H2sJobRef *> *jobs = h2s_cefc4c->unknown464940();
				for (unsigned int i = 0; i < jobs->size(); i++)
				{
					if ((*jobs)[i]->pos.same_409b90(*machine->getPosition_4184d0()))
						installed.push_back((*jobs)[i]);
				}
				if (installed.empty())
					msg += "Installed: None";
				else
				{
					msg += "Installed:";
					for (unsigned int i = 0; i < installed.size(); i++)
						msg += "\n  " + h2s_d2d1c4[installed[i]->f8]->search + " (" + intToString(installed[i]->fc) + ")";
				}
				addNew(name,msg,1,-1,0);
				if (!installed.empty())
					hotel_unknown91c850(hackType,&preBonus,&secondBonus);
				break;
			}

			case 102:
			case 103:
			case 104:
			case 105:
			case 106:
			case 107:
			case 108:
			{
				vector<int> &trojans = machine->getData_45cb30()->f40;
				int trojan = hackType - 84;
				if (OpX5_containsRecord(trojans,trojan))
				{
					msg = "Trojan already loaded.";
					addNew(name,msg,3,-1,0);
				}
				else
				{
					trojans.push_back(trojan);
					jl_addUniqueEntityData_9d30e0(h2s_cefc4c->unknown463c00(trojan),machine);
					STAT(0x2c6,hotel_e_b997a2);
					STAT(0x2ea,hotel_e_b997a3);
					STAT(hackType + 0x285,hotel_e_b997b9);
					hotel_cf45d8.unknown77fbc0(0x5b);
					msg = "Trojan loaded successfully.";
					msg += "\nTesting...";
					switch (hackType)
					{
						case 102:
							msg += "\nBroadcasting enabled and active.";
							break;
						case 103:
							jl_cf64c0.push_back(*machine->getPosition_4184d0());
							jl_cf64d0.push_back(h2s_cefc4c->getTurn() + rng.rangeInt(3,6));
							msg += "\nManipulated coupler status records.";
							break;
						case 104:
							msg += "\nDecoy responsive and awaiting execution trigger.";
							break;
						case 105:
							msg += "\nRedirection algorithm responsive and awaiting execution trigger.";
							break;
						case 106:
							msg += "\nDispatch confirmation system compromised.";
							break;
						case 107:
							msg += "\nPatched into local tactical coordination network.";
							break;
						case 108:
							msg += "\nWatcher tracking enabled and active.";
							break;
					}
					addNew(name,msg,1,-1,0);
					if (hackType == 0x67)
						hotel_cf45d8.unknown77fbc0(0x5f);
				}
				break;
			}

			case 109:
			{
				H2sAccess *access = h2s_cefc4c->unknown462f60(machine);
				OpU8a_removePoint_9d3060(unknownA8,access->pos);
				(*h2s_cfd44c.atPoint(access->pos))->unknown66a050(*jl_cefb9c,2,0);
				delete access;
				OpS8b_Fn9d51d0Access(*h2s_cefc4c->getAccess_462e10(),access);
				access = NULL;
				machine->disableMachine_65ed00();
				h2s_cefc4c->onGarrisonAccessDisabled();
				unknown4748 = 3;
				jl_ovm_cf6428.unknown682420(0xb,0);
				STAT(0x2c6,hotel_e_b997ba);
				STAT(0x2ea,hotel_e_b997bb);
				STAT(hackType + 0x285,hotel_e_b997dd);
				hotel_cf45d8.unknown77fbc0(0x5a);
				int lineCount2 = opr5e_unknown91c960(&msg,1);
				msg += "ACCESS_DOOR_JAMMED";
				addNew(name,msg,1,-1,lineCount2);
				break;
			}

			case 110:
			{
				unknown4748 = 3;
				jl_ovm_cf6428.unknown682420(0xc,0);
				STAT(0x2c6,hotel_e_b997de);
				STAT(0x2ea,hotel_e_b997df);
				STAT(hackType + 0x285,hotel_e_b9980f);
				hotel_cf45d8.unknown77fbc0(0x5a);
				vector<H2sJobRef *> relays;
				vector<H2sJobRef *> *jobs = h2s_cefc4c->unknown464940();
				for (unsigned int i = 0; i < jobs->size(); i++)
				{
					if ((*jobs)[i]->pos.same_409b90(*machine->getPosition_4184d0()))
					{
						relays.push_back((*jobs)[i]);
						jl_eraseAt_9ce6d0(*jobs,i);
					}
				}
				int newLineCount = opr5e_unknown91c960(&msg,relays.empty() ? 1 : relays.size());
				if (relays.empty())
					msg += "NO_RELAYS";
				else
				{
					for (unsigned int i = 0; i < relays.size(); i++)
					{
						H2sPt at;
						if (h2s_cefc4c->unknown71bde0(machine->getPosition_4184d0(),&at))
						{
							H2sHItem ejected = jl_cefc4c->unknown6c5400(h2s_d2d1c4[relays[i]->f8],at);
							ejected->setField_44fc60(relays[i]->fc);
							STAT(0x371,hotel_e_b9981f);
							STAT(0x372,hotel_e_b9982f);
						}
						if (i != 0)
							msg += "\n";
						msg += "EJECTED[" + h2s_d2d1c4[relays[i]->f8]->search + "]";
					}
					jl_clearObjects_9d0670(relays);
					jl_cf64c0.push_back(*machine->getPosition_4184d0());
					jl_cf64d0.push_back(h2s_cefc4c->getTurn() + rng.rangeInt(100,200));
					if (h2s_d2c658.unknown472c70(0x372) >= 10)
						hotel_cf45d8.unknown77fbc0(0xbb);
				}
				addNew(name,msg,1,-1,newLineCount);
				break;
			}


		}
		if (jl_d28f64 && h2s_cec0f8->unknown45a990() != 0 && machine->getInfo_9b8f00()->type < 6 && dice > diff - h2s_cefc4c->unknown71ab60(h2s_cec0f8->unknown45a990()))
			unknown90ec30("assessment: botnet-enabled success");
	}
	else
	{
		hackPassed = false;
		passed = false;
		STAT(0x26e,hotel_e_b9985d);
		bool xomAlert = false;
		if (sealed)
			msg = "Procedural error.";
		else
		{
			msg = "Failed " + intToString(diff) + "% (";
			if (dice - diff <= 10)
			{
				if (diff > 0)
					msg += "near success, ";
			}
			else if (dice - diff > 50)
			{
				msg += "catastrophic failure, ";
				STAT(0x26f,hotel_e_b9985e);
			}
			bool handled = false;
			switch (hackType)
			{
				case 0x4d:
					if (dice - diff > 10 && rng.chance(dice - diff))
					{
						item = hotel_cec0fc->getItem_4afcc0();
						if (!item->unknown457ad0() && !item->unknown457d10())
						{
							msg += item->unknown571db0(0,0) + " disabled).";
							item->setBroken_5795b0(-2,1);
							hotel_cec0fc->cleanup_4aff30();
							hotel_cec0fc->unknown4afc40(0x4d)->unknown4afab0(1);
							if (!h2s_cefc4c->getPlayer()->unknown5cbec0())
								hotel_cec0fc->unknown4afc40(0x4c)->unknown4afab0(1);
							handled = true;
							if (item->unknown457b10() >= 250)
								xomAlert = true;
						}
					}
					break;
				case 0x5f:
					item = hotel_cec0fc->getItem_4afcc0();
					h2s_d2c658.add4729d0(0x30d,1,string(hotel_e_b9985f),item->getId_9fcd80());
					if (dice - diff > 10 && rng.chance(dice - diff) && !item->unknown457ad0() && !item->unknown457d10())
					{
						msg += item->unknown571db0(0,0) + " disabled).";
						item->setBroken_5795b0(-2,1);
						STAT(0x30f,hotel_e_b9986e);
						hotel_cec0fc->cleanup_4aff30();
						hotel_cec0fc->unknown4afc40(0x5f)->unknown4afab0(1);
						if (!h2s_cefc4c->getPlayer()->unknown5cbfa0())
							hotel_cec0fc->unknown4afc40(0x5e)->unknown4afab0(1);
						handled = true;
					}
					break;
			}
			if (!handled)
			{
				vector<string> reasons;
				reasons.push_back("suspicious activity detected by network sentry");
				reasons.push_back("encountered trap node");
				reasons.push_back("followed decoy data trail");
				reasons.push_back("sudden abort of session control");
				reasons.push_back("receiving potentially harmful encrypted stream");
				reasons.push_back("dynamic firewall re-routed connection");
				reasons.push_back("unexpected hard line switch");
				reasons.push_back("triggered system alarm");
				reasons.push_back("triggered node purge");
				reasons.push_back("encountered local connection sweep");
				reasons.push_back("session timeout");
				reasons.push_back("suspicious null response");
				reasons.push_back("primary interim node flashed");
				msg += OpU8a_randomString(reasons) + ").";
			}
		}
		addNew(name,msg,2,-1,0);
		if (h2s_d25450.b0)
		{
			if (xomAlert)
			{
				int portrait = h2s_d25450.unknown69e700(0x19,0,0.0f);
				if (portrait != 6)
					opG1_showXomPortrait(portrait);
			}
			else if (diff < 30)
			{
				hotel_d254d0 = 0x70;
				hotel_d254d4 = 0;
			}
			else if (hotel_d254d0 != hackType)
			{
				hotel_d254d0 = hackType;
				hotel_d254d4 = 1;
			}
			else
			{
				hotel_d254d4++;
				if (hotel_d254d4 >= 4)
				{
					hotel_d254d0 = 0x70;
					hotel_d254d4 = 0;
					int portrait = h2s_d25450.unknown69e700(0x18,0,0.0f);
					if (portrait != 6)
						opG1_showXomPortrait(portrait);
				}
			}
		}
		if (jl_d28f65 && diff > 0 && machine->getInfo_9b8f00()->type < 6 && dice - diff <= 9)
		{
			int bots = h2s_cec0f8->unknown45a990();
			if (bots < 3)
			{
				int margin = dice - diff;
				int needed = 0;
				for (int n = bots; n < 3; n++)
				{
					needed++;
					switch (n)
					{
						case 0:
							margin -= 6;
							break;
						case 1:
							margin -= 3;
							break;
						case 2:
							margin -= 1;
							break;
					}
					if (margin <= 0)
					{
						unknown90ec30("assessment: +" + intToString(needed) + " active " + (needed > 1 ? "botnets" : "botnet") + " needed");
						break;
					}
				}
			}
		}

	}
	if (passed && record != NULL)
	{
		if (jl_b9b17a[record->type].flag)
			OpT8b_Fn9db000(unknown114,record->type);
		else if (jl_b9b179[record->type].flag)
			unknown104.push_back(record);
	}
	if (passed && unknown4748 == 0 && rng.chance(OpX5_maxInt(0,(machine->getData_45cb30()->fc - 1) * 10 + (100 - diff) - h2s_cefc4c->getPlayer()->unknown5c7f40())))
		jl_ovm5_cf6428.unknown681e70((100 - diff) / 10 * machine->getData_45cb30()->fc);
	bool hackResult = false;
	bool hadItem = false;
	switch (hackType)
	{
		case 0x42:
		case 0x43:
		{
			H2sRec8 *recA = hotel_cec0fc->unknown4afce0();
			H2sRec4 *recB2 = hotel_cec0fc->unknown4afd50();
			H2sHItem part = h2s_cefc4c->getPlayer()->unknown5d3f80(recA ? recA->index : jl_caf164,recB2 ? recB2->index : jl_caf160);
			if (part.isValid())
			{
				hadItem = true;
				if (hackType == 0x43)
					part->remove57dbe0(true,false,9,true);
			}
			else if (hackType == 0x43 && hackPassed)
			{
				if ((recA ? recA->index != machine->getData_45cb30()->f84 : recB2->index != machine->getData_45cb30()->f8c) && jl_cf4718 != 2)
				{
					unknown4748 = 1;
					diff = 0;
					dice = 100;
				}
			}
			break;
		}
	}
	if (!hadItem)
	{
		hackResult = h2s_cec0f8->unknown940ad0(diff,dice,unknown4748);
		hotel_cec0fc->unknown8fe6e0(hackResult);
	}
	if (hackPassed)
	{
		(*h2s_cefc4c->unknown463b30())[hackType] += 1;
		OpT8b_Fn9db000(machine->getData_45cb30()->f60,hackType);
		if (!hackResult && record != NULL && jl_b9afb8[record->type] != 0)
		{
			H2sTarget *target = hotel_cec0fc->unknown4afc40(record->type);
			target->unknown8fba20();
			if (target->f7c == 0)
				target->f7c = 1;
			target->unknown4afab0(0);
		}
		if (jl_cf4700 != NULL && !hackResult && machine->getInfo_9b8f00()->type == 0 && OpX5_containsRecord(h2s_d25de0[*jl_cf4700]->f148,10) && jl_d1e860.unknown46f4b0(1))
			jl_pd_cf45d8.addPolymindSuspicion_77ee70(jl_ba852c,0xb,H2sHEntity());
		if (preBonus != 0 && hotel_b9b798[hackType] > 0 && --hotel_cf6a50 == 0)
		{
			if (preBonus == 3)
				hotel_cf6a50 = jl_cf6a54->draw();
			else
			{
				hotel_cf6a50 = 1;
				if (machine->getData_45cb30()->f28 != -1)
				{
					if (h2s_d1e888->f4 == 0xd)
					{
						unknown90f990();
						h2s_cec0f8->unknown940ad0(100,100,2);
						H2sPt spawn;
						void *access;
						if (jl_ovm5_cf6428.findDispatchExit(&spawn,1,0,1,JlPos(-1),&access,0,0))
						{
							H2sGroup *group = h2s_cefc4c->selectRobotOfClass(1,0xe,0,1);
							H2sHEntity leader2;
							for (int n = rng.rangeInt(2,4); n > 0; n--)
							{
								H2sHEntity cutter = jl_cefc4c->placeEntity_6c58c0(group,spawn,3,0,3,0xe,0);
								cutter->getAI_45b590()->unknown459410(h2s_cfd44c.getArea_9b4400());
								if (leader2.isNull())
									leader2 = cutter;
								else
									cutter->getAI_45b590()->setFollowEntity_5b2f80(leader2,0);
							}
							string text = "ALERT: Suspicious activity reported at " + machine->getData_45cb30()->unknown65cc80() + ". Dispatching Cutter search squad to Garrison.";
							H2_ALERT(text);
							unknown90ec30(text);
						}
						hotel_cf6a50 = jl_cf6a54->draw();
					}
					else if (rng.chance(25))
					{
						unknown90f990();
						h2s_cec0f8->unknown940ad0(100,100,3);
						hotel_cf6a50 = jl_cf6a54->draw();
					}
				}
			}
		}
		if (machine->getInfo_9b8f00()->type < 6 && !machine->getData_45cb30()->f10 && jl_cf6a20 != -2)
		{
			if (jl_cf6a20 == -1)
			{
				unknown90f0a0();
				addNew(string(hotel_e_b9987f),string(jl_cf448c),5,-1,0);
				jl_cf6a20 = -2;
				LOG0(0x95);
			}
			else
			{
				bool newTrace = false;
				if (jl_cf6a20 < 6 && jl_cf6a28.isNull())
				{
					int percent = jl_cf6888[3] * 100 / jl_ba4454[jl_cf4718];
					if (percent >= jl_ba5a00[jl_cf6a20])
					{
						jl_cf6a20++;
						string text;
						if (jl_cf6a20 == 6)
						{
							if (rng.chance(15) && jl_cf68ac == 0 && jl_cf68b4 == 0 && !h2s_d25450.b0 && OpV4c_Fn9d3f40(jl_ba4ca8[h2s_d1e888->f4],5))
							{
								jl_exp_cf68ac.unknown45f070(h2s_d1e888->f4 == 5 ? jl_d22580 : jl_cfe12c);
								do {} while (0);
								do {} while (0);
								text = "\n" + jl_cf448c + " " + jl_cf1220;
								LOG0(0x95);
							}
							else
							{
								text = "\n" + jl_d305e0[jl_cf6a20 - 1];
								LOG0(0x96);
								hotel_cf6a24 = true;
								newTrace = true;
								int span = rng.rangeInt(1,h2s_d1e888->f8 >= 5 ? 5 : 3);
								do
								{
									vector<H2sHOwner> nodes2;
									vector<H2sHOwner> links;
									OpC_findNodes_470050(span,h2s_d1e884,nodes2,links);
									jl_eraseAt_9da940(nodes2,h2s_d1e888.isValid());
									for (int i = 0; i < nodes2.size(); i++)
									{
										if (jl_ba4cb8[nodes2[i]->f4][0] != 1)
											OpQ5_eraseStep_9d6440(nodes2,i);
									}
									if (!nodes2.empty())
									{
										jl_cf6a28 = OpX5_randomRecord(nodes2);
										break;
									}
									span--;
								}
								while (span >= 1);
								jl_cf6a38 = h2s_cefc4c->getTurn() + jl_d2c374.randomInRange_40c130();
								jl_tally_cf6888.unknown69b560(true);
								if (jl_d21b10.empty())
									h2s_cefaa8->unknown792c50();
								if (0) {}
								jl_cf6aa4.assign(jl_d21b10.size(),vector<int>());
								for (unsigned int i = 0; i < jl_d21b10.size(); i++)
									jl_cf6aa4[i].assign(jl_d21b10[i].size(),0);
								jl_cf6abc.assign(jl_cf45a0.size(),0);
								jl_cf6acc.assign(jl_cf08b4.size(),0);
								h2s_d2c658.add472b90(0x1b,-999999);
								hotel_cf45d8.unknown77fbc0(0xa5);
							}
							hotel_cf6888.unknown6998a0(3,0,1);
							hotel_cf6888.unknown6998a0(4,0,1);
							if (jl_cf68a8 != NULL)
								jl_cf68a8->f10.back().push_back(3);
						}
						else
						{
							text = "\n" + jl_d305e0[jl_cf6a20 - 1];
							if (jl_cf6a20 - 1 == 0)
								LOG0(0x94);
						}
						unknown90f0a0();
						for (unsigned int i = 0; i < text.size(); i++)
						{
							if (text[i] == '#')
								text[i] = intToString(rng.rangeInt(1,9))[0];
						}
						addNew(string(hotel_e_b9988e),text,5,-1,1);
					}
				}
				if (hotel_cf6a24 && !newTrace && jl_cf6a30 != 0 && (jl_cf6a2c < 2 || h2s_d1e888 == jl_cf6a28) && jl_cfd4d0[hackType].find("(f",0) == string::npos && machine->getInfo_9b8f00()->type != 5 && rng.chance(20))
				{
					jl_cf6a30--;
					if (jl_cf6a2c < 4)
						jl_cf6a2c++;
					if (jl_cf6a2c >= 3 && jl_cf68b8.operator->() == NULL)
						goto tailB;
					{
						machine->getData_45cb30()->f28 = -2;
						hotel_cec0fc->unknown8fe7f0(6);
						h2s_cec0f8->unknown942a60();
						vector<int> depths;
						for (int i = 0; i < 0x26; i++)
						{
							if (jl_b911c0[i] != 0)
								depths.push_back(+i);
						}
						int lastDepth = 0x26;
						unknown90ed30(string("### SYSTEM_CRASH ###"),6,0,1);
						unknown90ed30(string("\n"),6,0,0);
						unknown90ed30(string("TRACEBACK..."),6,0,1);
						unknown90ed30(string("\n"),6,0,0);
						for (int n = rng.rangeInt(8,12); n > 0; n--)
						{
							string line;
							for (int k = 0; k < 10; k++)
								line += randomChar_4085b0(jl_d33e1c);
							line = OpR5f_toUpper_4083a0(line);
							line += "=";
							int depth;
							do
							{
								depth = OpU8a_randomRec(depths);
							}
							while (depth == lastDepth);
							lastDepth = depth;
							line += jl_cfe140[depth];
							line += "/?";
							for (int k = 0; k < 4; k++)
								line += intToString(rng.rangeInt(0,9));
							unknown90ed30(line,6,0,0);
						}
						string source;
						switch (jl_cf6a2c)
						{
							case 1:
								source = "SOURCE_DEPTH/-" + intToString(jl_cf6a28->f8);
								break;
							case 2:
								source = "SOURCE_MAP/" + h2s_mapNames_cfaca0[jl_cf6a28->f4];
								source = OpR5f_toUpper_4083a0(source);
								break;
							case 3:
							{
								source = "SOURCE_QUAD/";
								const Pos &at = jl_cf68b8->getPosition_45a4a0();
								if (at.x < h2s_cfd44c.getMaxX() / 2)
								{
									if (at.y < h2s_cfd44c.getMaxY() / 2)
										source += "NW";
									else
										source += "SW";
								}
								else
								{
									if (at.y < h2s_cfd44c.getMaxY() / 2)
										source += "NE";
									else
										source += "SE";
								}
								break;
							}
							case 4:
							{
								source = "SOURCE_REL/";
								int dir = pointsFn_4374c0(*machine->getPosition_4184d0(),jl_cf68b8->getPosition_45a4a0());
								source += jl_d01a48[dir];
								break;
							}
						}
						unknown90ed30(source,6,0,1);
						unknown90ed30("\n" + source,6,0,0);
					}
				}
			}
		}
	}
tailB:
	if (secondBonus != 0 && --hotel_cf6a58 == 0)
	{
		if (preBonus == 3)
			hotel_cf6a58 = 1;
		else if (secondBonus == 3)
			hotel_cf6a58 = jl_cf6a5c->draw();
		else if (!hackPassed)
		{
			hotel_unknown91c850(0x6f,&preBonus,&secondBonus);
			hotel_cf6a58 = jl_cf6a5c->draw();
		}
		else
			hotel_cf6a58 = 1;
	}
	if (preBonus != 0 && preBonus != 3 && secondBonus != 3 && hackPassed && !jl_cf6ab4 && rng.chance(10) && machine->unknown45c870(9) > 0)
	{
		string taunt("Why rely on manual manipulation instead of your hacking prowess, Cogmind? Is it because you don't have any? Compensating for something?");
		jl_cec100->unknown90f990(taunt);
		jl_cf6ab4 = true;
	}
	if (jl_cefb74 != 0)
	{
		jl_cefb74 = 0;
		string error("CShell_errno=`10`");
		opS2_showMessage_5111e0(0x325,&error,0,0,H2sHEntity(),H2sHEntity(),0,0);
	}
	if (jl_cefb3e)
	{
		jl_cec024->bc = hackPassed;
		jl_cec024->f0 += 1;
	}

	return passed;
}
