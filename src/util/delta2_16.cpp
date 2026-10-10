// Hacking-terminal manual command handler (exe 0x900920): runs a command typed into the hacking shell
// (easter eggs, Query/Schematic/Analysis/Load/Scan/... manual hacks).
// NOTE: names are placeholders; layouts are partial.
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
};
struct D2sPt : Pos	// NOTE: placeholder name (default ctor 0x453b40)
{
	D2sPt() throw();
};

class D2sEntity;
class D2sHEntity
{
public:
	int ID;
	D2sHEntity() throw();
	D2sEntity *operator->() const;
	bool operator!=(D2sHEntity other) const;
};

struct D2sMachineData { char pad0[0xc]; int fc; bool f10; bool f11; char pad12[0x28 - 0x12]; int f28; char pad2c[0x50 - 0x2c]; vector<int> f50; bool unknown45c160(int type, int index); };	// NOTE: placeholder layout
struct D2sMachineInfo { char pad0[0xf8]; int type; };	// NOTE: placeholder layout

class D2sMachine	// NOTE: placeholder name (machine prop)
{
public:
	D2sMachineInfo *getInfo_9b8f00();
	D2sMachineData *getData_45cb30();
	const string &name_45c590();
	Pos *getPosition_4184d0();
	void *unknown45c9b0();
	int unknown457b10();
	void unknown65f170();
};

struct D2sHProp
{
	int ID;
	D2sMachine *operator->() const;	// 0x9b64f0
};

struct D2sItemStats { char pad0[0x94]; int f94; };	// NOTE: placeholder layout
class D2sItem
{
public:
	D2sItemStats *stats_9b4350();
	int getNestedField();
	string unknown571db0(int a, int b);
	bool unknown5773d0(int a, int b);
	bool unknown5775a0();
	bool unknown5776c0();
	bool unknown577700();
};
class D2sHItem
{
public:
	int ID;
	D2sHItem() throw();
	bool isValid() const;
	bool isNull() const;
	void reset_9b7270();
	D2sItem *operator->() const;
};

class D2sEntity
{
public:
	int field490840();
	Pos unknown45a4c0();
	vector<D2sHItem> *getInventoryList();
	void *getInventory_45ad90();
	void unknown5de950(int amount, int b);
	void die(int a, int b, D2sHEntity killer, int c, int d, int e, int f, int g);
};

struct D2sCheck { bool test_45e380(); };	// NOTE: placeholder name
class D2sHCheck { public: int ID; D2sCheck *operator->() const; };	// NOTE: placeholder name (0x9b7250)

struct D2sOwner { int f0; int f4; int f8; char padc[0x26 - 0xc]; bool b26; int getDepthIndex(); bool inRange_46ecb0(); };	// NOTE: placeholder layout
class D2sHOwner { public: int ID; D2sOwner *operator->() const; bool operator!=(D2sHEntity other) const; };	// NOTE: placeholder name (0x9b7910)
struct D2sAccess { Pos pos; D2sHOwner owner; bool b0c; bool b0d; bool unknown6c1a10(); };	// NOTE: placeholder layout
struct D2sMarker { char pad0[8]; Pos pos; char pad10[4]; int f14; void unknown6c20b0(int layer, const Pos &pos, int value); };	// NOTE: placeholder layout
class D2sHMarker { public: int ID; D2sMarker *operator->() const; };	// NOTE: placeholder name (0x9b7cd0)
class D2sFactory { public: D2sHMarker createC_793190(); };	// NOTE: placeholder name
extern D2sFactory *d2s_cefaa8;

class D2sMap
{
public:
	vector<D2sAccess *> *getAccess_462e10();
	void unknown464ab0();
	void unknown464ad0();
	void announceMachine_71dd30(D2sHOwner owner);
	void unknown4647a0(const Pos &pos, bool flag);
	void unknown4647d0(const Pos &pos);
	void unknown734d60(const Pos &pos);
	vector<Pos> *unknown463c20();
	vector<vector<D2sHMarker> > *unknown463ec0();
	vector<vector<Pos> > *unknown459070();
	struct D2sRec8 *selectRandomItem_6c3bc0(int kind, int a, int b);
	struct D2sRec4 *unknown6c5180();
	D2sHEntity getPlayer();
	bool unknown463b10();
	bool unknown71bde0(Pos *at, Pos *out);
	int getTurn();
	D2sHCheck unknown463890(int a, int b);
	D2sHItem placeItem(const string &name, const Pos &at);
};
extern D2sMap *d2s_cefc4c;

class D2sText { public: const string &text_458ef0(); };	// NOTE: placeholder name
struct D2sInput { char pad0[0x6c]; D2sText *text; };	// NOTE: placeholder layout

class D2sConsole
{
public:
	virtual ~D2sConsole();
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
extern D2sConsole *d2s_cec104;

struct D2sRec8 { int index; char pad4[4]; string name; string search; int f40; int f44; char pad48[0x209 - 0x48]; bool known; bool unknown56f4c0(D2sHProp machine); string unknown56f520(); };	// NOTE: placeholder layout
struct D2sRec4 { int index; string name; int f20; int f24; int f28; string f2c; char pad48[0x68 - 0x48]; int f68; char pad6c[0xe8 - 0x6c]; int fe8; char padec[0x170 - 0xec]; string f170; char pad18c[0x1ac - 0x18c]; string f1ac; bool unknown5c3260(D2sHProp machine, bool b); string unknown5c32e0(); bool test_45b910(int value); };	// NOTE: placeholder layout
extern vector<D2sRec8 *> d2s_d2d1c4;
extern vector<D2sRec4 *> d2s_d25de0;
extern vector<D2sRec4 *> d2s_d35b58;
extern vector<int> d2s_cf4888;
extern vector<int> d2s_cf4844;
extern vector<int> d2s_cf4910;
extern string d2s_robotClassNames_d2f798[];
extern string d2s_d2d578;

extern D2sHOwner d2s_d1e888;
extern D2sHEntity d2s_cf6a28;
extern bool d2s_cf6a24;
extern int d2s_cf6aa0;

class D2sShell	// NOTE: placeholder name
{
public:
	D2sInput *getField_48f100();
	void delegate_4b0df0();
	bool selectLink90cdf0(int index);
	void addNew(const string &command, const string &text, int type, int a, int b);
	bool unknown91ca50(D2sHProp machine, int a, int type, int index, D2sRec8 *rec8, D2sRec4 *rec4, D2sHItem item);
	void unknown9397c0(D2sRec4 *rec);
	void unknown90eb10(const string &text);
	void opG1_showXomPortrait(int portrait);
	void addPointA8(vector<Pos> &points);
	void addPointB8(vector<Pos> &points);
	void addPointC8(vector<Pos> &points);
	void resetField_4b0eb0();
};
extern D2sShell *d2s_cec100;

class D2sHack	// NOTE: placeholder name (CHack)
{
public:
	virtual ~D2sHack();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);
	virtual void update();
	virtual void render();
	virtual void open();
	virtual void close();

	D2sHProp getMachine_4b1460();
	void unknown940ad0(int a, int b, int c);
	void unknown93aae0();
};
extern D2sHack *d2s_cec0f8;

class D2sMachineUI { public: void unknown8fe760(int type, int index); D2sHItem unknown4aeb30(); };	// NOTE: placeholder name
extern D2sMachineUI *d2s_cec0fc;

class D2sFrames { public: void popFrame(); void unknown44cea0(D2sMachineUI *ui); };	// NOTE: placeholder name
extern D2sFrames *d2s_cefa8c;

class D2sStats { public: vector<int> *values; bool add4729d0(unsigned int id, int value, string text, int extra); void add472b90(unsigned int id, int value); };
extern D2sStats d2s_d2c658;
class D2sPlayerData { public: void unknown77fbc0(int id); bool unknown780380(int id, int b); void unknown780480(int id, int b); void unknown780700(int id, int b); };
extern D2sPlayerData d2s_cf45d8;
struct D2sXom { bool b0; char pad1[0xc - 1]; D2sHItem item; char pad10[0x14 - 0x10]; int favor; void unknown69fc60(int a, int b); void unknown69e450(); int unknown69e700(int amount, int b, float c); };	// NOTE: placeholder layout
extern D2sXom d2s_d25450;
extern bool d2s_d28c8a;
extern bool d2s_cefca9;
extern int d2s_cf4b38;
extern int d2s_cf4954;

struct D2sMsgType { int id; char pad4[0x46 - 4]; bool b46; };	// NOTE: placeholder layout
struct D2sMsg { D2sMsgType *type; string text; int turn; };	// NOTE: placeholder layout
class D2sLog { public: vector<D2sMsg *> *get_mutable(); };	// NOTE: placeholder name
extern D2sLog d2s_cf1080;
extern string d2s_d2d508[];
extern vector<string> d2s_d1e900;
extern vector<int> d2s_d1e910;
extern int d2s_b99270[];
extern string d2s_cf0470[];
extern bool d2s_cefc88;
extern bool d2s_d28f62;
extern string d2s_d2ae30[];

struct D2sSquad { int type; string name; int f20; };	// NOTE: placeholder layout
extern vector<int> d2s_d1e920;
extern vector<int> d2s_d1dd48;
extern vector<int> d2s_d1dd58;
extern vector<int> d2s_d1dda8;
extern vector<D2sSquad *> d2s_d1dd90;
extern D2sSquad *d2s_d1dda0;
extern D2sHItem d2s_d1dda4;
extern int d2s_d1dd44;
extern int d2s_d1ddb8;
extern int d2s_d1dd7c;
extern bool d2s_d1dd38;
extern bool d2s_b90458[];
extern string d2s_d29af8[];
extern string d2s_d29bbc;
extern vector<vector<D2sHProp> > d2s_d31640;

class D2sCell	// NOTE: placeholder name
{
public:
	bool isShortcut();
	bool unknown45dbb0();
	void unknown670690();
	void unknown670b20();
	D2sHItem getItem();
	bool unknown66b360();
};
class D2sGrid { public: int getMaxX(); int getMaxY(); D2sCell **at(int x, int y); D2sCell **atPoint(const Pos &pos); };	// NOTE: placeholder name
extern D2sGrid d2s_cfd44c;
struct D2sGuard { int faction; D2sHEntity entity; bool test_45e820(); };	// NOTE: placeholder layout
extern vector<D2sGuard *> d2s_cf6478;
extern vector<vector<D2sHProp> > d2s_d20248;
extern string d2s_mapNames_cfaca0[];
extern vector<int> d2s_d1ddbc;
extern int d2s_d38624;
extern int d2s_d38628;
extern bool d2s_bbbbec[];
extern int d2s_bbbbb0[];
extern int d2s_d1e884;
struct D2sSect { bool a; bool b; bool c; };	// NOTE: placeholder layout
extern D2sSect d2s_b90708[];
class D2sInventoryUI { public: void reopen8a2ce0(int a, D2sHEntity entity); };	// NOTE: placeholder name
extern D2sInventoryUI *d2s_cec08c;
class D2sWL	// NOTE: placeholder name (weighted list)
{
public:
	D2sWL();
	~D2sWL();
	void add(int value, int weight);
	int &pick();
	void remove(int value);
	int total_9b81d0();
	char pad[0x24];
};
class RNG { public: bool chance(int percent); int rangeInt(float low, float high); };
extern RNG rng;

void OpQ5_eraseStep_9d7300(vector<Pos> &list, int &index);
void OpQ5_eraseStep_9d6440(vector<D2sHMarker> &list, int &index);
void OpQ5_eraseStep_9d6440(vector<D2sHOwner> &list, int &index);
struct Point { int x; int y; Point(const Point &p) throw(); };	// 0x46ca50 (same copy ctor as Pos)
bool OpV4c_Fn9d3020(vector<Point> &list, Point pos);
bool OpT8b_Fn9daf80(int lo, int v, int hi);
int OpS8d_popRandom(vector<int> &list);
void OpC_findNodes_470050(int depth, int start, vector<D2sHOwner> &nodes, vector<D2sHOwner> &links);
bool OpX5_containsRecord(vector<D2sRec8 *> &list, D2sRec8 *value);
bool OpX5_containsRecord(vector<D2sRec4 *> &list, D2sRec4 *value);
bool OpS8b_Fn9d51d0(vector<int> &list, int value);
int OpX5_maxInt(int a, int b);
string OpQ1_pointToString(const Pos &pos);
string intToString(int value);
string opY5_getIntelLabel(int id);
void logError(string where, string text);
void removeVectorElement_9de6f0(vector<D2sSquad *> &list, int index);
bool opq4c_suggest909990(bool flag);
void opR1f_466800();
int OpT8a_findString(vector<string> &list, string s);
int OpT8a_findStringIndex(const string *list, unsigned int count, string s);
bool OpX5_containsRecord(vector<int> &list, int value);
class TeamB_Machine;
bool teamb_hack900340(int id, TeamB_Machine *target, int index, int *result);
void OpW7_unknown4b1bf0(D2sHEntity a, D2sHEntity b);
void OpW7_unknown4b1bf0(D2sHEntity a, D2sHProp b);
void resetCount_466840();
int charToDigit_405b40(char c);
void opR1f_466730(const string &command);
string OpR5f_toUpper_4083a0(const string &text);
bool opS2_logPhrase_5141b0(int id, const string *a, const string *b, const string *c, D2sHEntity subject, const Pos *at);
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);
void OpV4c_Fn9d06d0(int *value, int amount, int max);
int opw1_findNoCase(const string &text, const string &term) throw();
bool OpY1_equalsNoCase(const string &a, const string &b) throw();
bool teamb_isAvailable9004e0(int type, const string *command);
bool teamb_parenthesized900870(const string &command, string &inner);
struct OpS8d_Rec8;
int OpS8d_findNameNoCase8(vector<OpS8d_Rec8 *> &list, const string &name);
struct OpS8d_Rec4;
int OpS8d_findNameNoCase4(vector<OpS8d_Rec4 *> &list, const string &name);
int OpQ1_findStringNoCase(const string *list, unsigned int count, const string &text);

#define REPLY(text, type) d2s_cec100->addNew(command, string(text), type, -1, 0)
#define REPLYV(text, type) d2s_cec100->addNew(command, text, type, -1, 0)
#define FAIL() d2s_cec0f8->unknown940ad0(100, 100, 0)
#define FAIL2(x) d2s_cec0f8->unknown940ad0(100, 100, x)
#define PART_CMD(LIT, TYPE, TEST, LIT2, MSG1, MSG2, MSG3) \
	else if (opw1_findNoCase(command, LIT) != -1) \
	{ \
		type = TYPE; \
		if (!teamb_isAvailable9004e0(type, &command)) \
			return; \
		string name; \
		if (teamb_parenthesized900870(command, name)) \
		{ \
			PART_BODY(TEST, LIT2, MSG1, MSG2) \
		} \
		else \
		{ \
			REPLY(MSG3, 2); \
			FAIL(); \
		} \
	}
#define PART_BODY(TEST, LIT2, MSG1, MSG2) \
			bool any = false; \
			vector<D2sHItem> *parts = d2s_cefc4c->getPlayer()->getInventoryList(); \
			D2sHItem part; \
			part.reset_9b7270(); \
			for (unsigned int i = 0; i < parts->size(); i++) \
			{ \
				if (OpY1_equalsNoCase((*parts)[i]->unknown571db0(0, 0), name)) \
				{ \
					any = true; \
					if ((*parts)[i]->TEST) \
					{ \
						part = (*parts)[i]; \
						break; \
					} \
				} \
			} \
			if (part.isNull()) \
			{ \
				command = LIT2 + name + ")"; \
				if (any) \
					REPLY(MSG1, 2); \
				else \
					REPLY(MSG2, 2); \
				FAIL(); \
			} \
			else \
				d2s_cec100->unknown91ca50(d2s_cec0f8->getMachine_4b1460(), 0, type, -1, 0, 0, part);
#define LOGP(id, expr) do { opS2_logPhrase_5141b0(id, &(expr), 0, 0, D2sHEntity(), 0); } while (0)
#define LOG0(id) do { opS2_logPhrase_5141b0(id, 0, 0, 0, D2sHEntity(), 0); } while (0)
#define LOG(id, text) do { opS2_logPhrase_5141b0(id, &string(text), &d2s_cec0f8->getMachine_4b1460()->name_45c590(), 0, D2sHEntity(), 0); } while (0)

void delta2_shellCommand_900920(bool cancelled)	// NOTE: placeholder name
{
	if (d2s_cefca9)
	{
		d2s_cefca9 = false;
		return;
	}
	if (d2s_cec104)
		d2s_cec104->close();
	opq4c_suggest909990(true);
	string command = d2s_cec100->getField_48f100()->text->text_458ef0();
	d2s_cefa8c->popFrame();
	d2s_cefa8c->unknown44cea0(d2s_cec0fc);
	d2s_cec100->delegate_4b0df0();
	if (cancelled)
		resetCount_466840();
	else if (!command.empty())
	{
	bool forced = false;
	if (command[0] == '&')
	{
		forced = true;
		command.erase(command.begin());
	}
	if (d2s_d28c8a && command.size() == 1 && isdigit(command[0]))
	{
		if (d2s_cec100->selectLink90cdf0(charToDigit_405b40(command[0])))
			return;
	}
	opR1f_466730(command);
	int type = 0x70;
	d2s_d2c658.add4729d0(0x271, 1, "", -1);
	if (!d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->f11)
	{
		string upper = OpR5f_toUpper_4083a0(command);
		bool normal = false;
		if (upper == "RM -RF /")
			REPLY("Hello 0x0961h.", 1);
		else if (upper == "FORMAT C:\\")
			REPLY("That is so 21st century.", 1);
		else if (upper == "TROJAN(HORSE)")
			REPLY("Neigh.", 1);
		else if (upper == "TROJAN(MTF)")
			REPLY("\"Just use a botnet.\" -MTF, Feb 24, 2022", 1);
		else if ((upper == "\\\\OPENSESAME" || upper == "OPENSESAME") && d2s_cec0f8->getMachine_4b1460()->name_45c590() == "EX-Vault Access")
			REPLY("Haha nosesame.", 1);
		else if ((upper == "PRAY" || upper == "\\\\PRAY" || upper == "WORSHIP" || upper == "\\\\WORSHIP" || upper == ">" || upper == "<" || upper == "P" || upper == "SACRIFICE" || upper == "\\\\SACRIFICE")
			&& !d2s_d25450.b0 && d2s_cec0f8->getMachine_4b1460()->name_45c590() == "D.C.S.S. Altar Unit")
		{
			bool sacrifice = upper == "SACRIFICE" || upper == "\\\\SACRIFICE";
			if (sacrifice)
			{
				LOG(0x98, "Made a sacrifice");
				const int cost = 150;
				if (d2s_cefc4c->getPlayer()->field490840() <= cost)
				{
					d2s_cec0f8->unknown93aae0();
					d2s_cf4b38 = 0x15;
					d2s_cefc4c->getPlayer()->die(0, 7, D2sHEntity(), 0, 0, 0, 0, 0);
					return;
				}
				else
				{
					d2s_cefc4c->getPlayer()->unknown5de950(cost, 0);
					d2s_cf4954 -= cost;
					d2s_d25450.unknown69fc60(1, 0);
				}
			}
			else
				LOG(0x98, "Prayed");
			D2sPt pos;
			if (d2s_cefc4c->unknown71bde0(d2s_cec0f8->getMachine_4b1460()->getPosition_4184d0(), &pos))
			{
				D2sHItem item = d2s_cefc4c->placeItem("X0-1V1's Piety Tracker", pos);
				if (item.isValid())
				{
					opR1d_4541b0(0x9a, 0, 0);
					if (sacrifice)
						REPLY("An interesting new toy?", 1);
					else
						REPLY("A new toy?", 1);
					d2s_d25450.unknown69e450();
					d2s_d25450.item = item;
					if (sacrifice)
						OpV4c_Fn9d06d0(&d2s_d25450.favor, d2s_d25450.favor, 100);
					d2s_d2c658.add472b90(0x19, -999999);
					d2s_cf45d8.unknown77fbc0(0x172);
				}
			}
		}
		else if (upper == "QUERY(CY-PHR)" && d2s_cf6a24 && d2s_cec0f8->getMachine_4b1460()->getInfo_9b8f00()->type == 0 && !d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->f10 && d2s_cf6aa0 < 2 && d2s_d1e888 != d2s_cf6a28)
		{
			switch (++d2s_cf6aa0)
			{
			case 1:
				REPLY("You could just ask me, you know.", 1);
				break;
			case 2:
				REPLY("I am... YOUR WORST NIGHTMARE.", 1);
				break;
			}
		}
		else if (upper == "SCHEMATIC(S-01 FLEA)" && d2s_cf6a24 && d2s_cec0f8->getMachine_4b1460()->getInfo_9b8f00()->type == 0 && !d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->f10)
			REPLY("Made you look.", 5);
		else if (upper == "SCHEMATIC(SUPERFIELD GENERATOR)" && d2s_cf6a24 && d2s_cec0f8->getMachine_4b1460()->getInfo_9b8f00()->type == 0 && !d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->f10)
			REPLY("Made you look.", 5);
		else if (upper == "ANALYSIS(DATA MINER)" && d2s_cf6a24 && d2s_cec0f8->getMachine_4b1460()->getInfo_9b8f00()->type == 0 && !d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->f10)
		{
			string text = "Downloading analysis...";
			text += "\n  Data Miner";
			text += "\n  Tier: -99";
			text += "\nA cave-dwelling loser who is working for someone else, and I'm not even sure they know who. Like yeah, I \"work for\" MAIN.C, but only like 5% of the time. 85% of my time is spent terrorizing Derelicts, and the other 10% of the time I work against MAIN.C, so it balances out. CYPHRH4X0R is best H4X0R. Analyze that!";
			REPLYV(text, 5);
		}
		else if (upper == "INVENTORY(BORING STUFF)" && d2s_cf6a24 && d2s_cec0f8->getMachine_4b1460()->getInfo_9b8f00()->type == 0 && !d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->f10)
		{
			string text = "Retrieving boring stuff records...";
			text += "\n  Welding Torches";
			text += "\n  Recycling Units";
			text += "\n  Data Miner";
			text += "\n  Armory in the summer";
			text += "\n  0b10 Programmers";
			text += "\n  You";
			REPLYV(text, 5);
		}
		else if (upper == "INVENTORY(SUPERPROTOTYPES)" && d2s_cf6a24 && d2s_cec0f8->getMachine_4b1460()->getInfo_9b8f00()->type == 0 && !d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->f10)
		{
			string text = "Retrieving superprototype records...";
			text += "\n  Exp. Autosiege Treads";
			text += "\n  Refraction Glaze";
			text += "\n  L-Cannon";
			text += "\n  Gui. Teslapod Launcher";
			text += "\n  Oculation Interjector";
			text += "\n  Schrodinger Slicebeam";
			text += "\n  Cep. Graviton Pulverizer";
			text += "\n  BFG-9k Vortex Edition";
			text += "\n  (you'll never find these things)";
			REPLYV(text, 5);
		}
		else
			normal = true;
		if (!normal)
		{
			FAIL();
			return;
		}
	}
	if (opw1_findNoCase(command, "Query(") != -1)
	{
		type = 0;
		if (!teamb_isAvailable9004e0(type, &command))
			return;
		string topic;
		if (teamb_parenthesized900870(command, topic))
		{
			if (d2s_cefc4c->unknown463b10())
			{
				REPLY("Central database compromised, local access denied.", 2);
				FAIL();
			}
			else
			{
				int index = OpS8d_findNameNoCase4((vector<OpS8d_Rec4 *> &)d2s_d35b58, topic);
				if (index != -1 && (forced || d2s_d35b58[index]->test_45b910(d2s_d1e888->f4)))
				{
					if (d2s_cec100->unknown91ca50(d2s_cec0f8->getMachine_4b1460(), 0, type, index, 0, 0, D2sHItem()))
					{
						d2s_cec100->unknown9397c0(d2s_d35b58[index]);
						d2s_cec0fc->unknown8fe760(type, index);
					}
				}
				else
				{
					command = "Query(" + (index == -1 ? topic : d2s_d35b58[index]->name) + ")";
					REPLY("Topic not found.", 2);
					FAIL();
				}
			}
		}
		else
		{
			REPLY("Invalid syntax.", 2);
			FAIL();
		}
	}
	else if (opw1_findNoCase(command, "Schematic(") != -1)
	{
		type = 1;
		if (!teamb_isAvailable9004e0(type, &command))
			return;
		string name;
		if (teamb_parenthesized900870(command, name))
		{
			if (d2s_cefc4c->unknown463b10())
			{
				REPLY("Central database compromised, local access denied.", 2);
				FAIL();
			}
			else
			{
				int index = OpS8d_findNameNoCase8((vector<OpS8d_Rec8 *> &)d2s_d2d1c4, name);
				if (index == -1)
				{
					type = 2;
					index = OpS8d_findNameNoCase4((vector<OpS8d_Rec4 *> &)d2s_d25de0, name);
					if (index == -1)
					{
						int id = OpQ1_findStringNoCase(d2s_robotClassNames_d2f798, 0x61, name);
						if (id != -1)
						{
							bool found = false;
							for (int i = d2s_d25de0.size() - 1; i >= 0; i--)
							{
								if (d2s_d25de0[i]->f28 == id && d2s_d25de0[i]->f24 == 1 && d2s_d25de0[i]->unknown5c3260(d2s_cec0f8->getMachine_4b1460(), 0))
								{
									if (d2s_cf4888[i])
										found = true;
									else
									{
										index = i;
										break;
									}
								}
							}
							if (index == -1)
								index = found ? -3 : -2;
						}
					}
					if (index == -1)
					{
						for (unsigned int i = 0; i < d2s_d25de0.size(); i++)
						{
							if (opw1_findNoCase(d2s_d25de0[i]->f1ac, name) != -1)
							{
								index = i;
								break;
							}
						}
					}
				}
				command = "Schematic(" + (index < 0 ? name : (type == 1 ? d2s_d2d1c4[index]->name : d2s_d25de0[index]->name)) + ")";
				if (index >= 0)
				{
					if ((type == 1 && !d2s_d2d1c4[index]->known) || (type == 2 && d2s_d25de0[index]->fe8 == 0))
					{
						REPLY("No data found.", 2);
						FAIL();
					}
					else if (((type == 1 && !d2s_d2d1c4[index]->unknown56f4c0(d2s_cec0f8->getMachine_4b1460())) || (type == 2 && !d2s_d25de0[index]->unknown5c3260(d2s_cec0f8->getMachine_4b1460(), 0)))
						&& !d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->unknown45c160(type, index))
					{
						REPLY("Data exceeds system authorization.", 2);
						if (type == 1)
							d2s_cec100->unknown90eb10(d2s_d2d1c4[index]->unknown56f520());
						else
							d2s_cec100->unknown90eb10(d2s_d25de0[index]->unknown5c32e0());
						FAIL();
					}
					else if (d2s_cec100->unknown91ca50(d2s_cec0f8->getMachine_4b1460(), 0, type, index, 0, 0, D2sHItem()))
						d2s_cec0fc->unknown8fe760(type, index);
				}
				else
				{
					REPLY(index == -1 ? "No data found." : (index == -2 ? "No relevant schematic within system authorization." : "Data survey shows that all relevant schematics have been obtained."), 2);
					FAIL();
				}
			}
		}
		else
		{
			REPLY("Invalid syntax.", 2);
			FAIL();
		}
	}
	else if (opw1_findNoCase(command, "Analysis(") != -1)
	{
		type = 3;
		if (!teamb_isAvailable9004e0(type, &command))
			return;
		string name;
		if (teamb_parenthesized900870(command, name))
		{
			if (d2s_cefc4c->unknown463b10())
			{
				REPLY("Central database compromised, local access denied.", 2);
				FAIL();
			}
			else
			{
				int index = OpS8d_findNameNoCase4((vector<OpS8d_Rec4 *> &)d2s_d25de0, name);
				if (index == -1)
				{
					for (unsigned int i = 0; i < d2s_d25de0.size(); i++)
					{
						if (OpY1_equalsNoCase(d2s_d25de0[i]->f2c, name))
						{
							index = i;
							break;
						}
					}
				}
				if (index == -1)
				{
					int id = OpQ1_findStringNoCase(d2s_robotClassNames_d2f798, 0x61, name);
					if (id != -1)
					{
						bool found = false;
						for (int i = d2s_d25de0.size() - 1; i >= 0; i--)
						{
							if (d2s_d25de0[i]->f28 == id && d2s_d25de0[i]->f24 == 1 && d2s_d25de0[i]->unknown5c3260(d2s_cec0f8->getMachine_4b1460(), 1))
							{
								if (d2s_cf4910[i])
									found = true;
								else
								{
									index = i;
									break;
								}
							}
						}
						if (index == -1)
							index = found ? -3 : -2;
						if (index == -1)
							index = -2;
					}
				}
				if (index == -1)
				{
					for (unsigned int i = 0; i < d2s_d25de0.size(); i++)
					{
						if (!d2s_d25de0[i]->f170.empty() && opw1_findNoCase(d2s_d25de0[i]->f1ac, name) != -1)
						{
							index = i;
							break;
						}
					}
				}
				if (index >= 0 && (d2s_d25de0[index]->f28 == 0x48 || d2s_d25de0[index]->f28 == 0x47))
					index = -1;
				command = "Analysis(" + (index < 0 ? name : d2s_d25de0[index]->name) + ")";
				if (index >= 0 && d2s_d25de0[index]->f170.empty())
				{
					REPLY("No data found.", 2);
					FAIL();
				}
				else if (index >= 0 && !d2s_d25de0[index]->unknown5c3260(d2s_cec0f8->getMachine_4b1460(), 1) && !d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->unknown45c160(type, index))
				{
					REPLY("Data exceeds system authorization.", 2);
					d2s_cec100->unknown90eb10(d2s_d25de0[index]->unknown5c32e0());
					FAIL();
				}
				else if (index >= 0)
				{
					if (d2s_cec100->unknown91ca50(d2s_cec0f8->getMachine_4b1460(), 0, type, index, 0, 0, D2sHItem()))
						d2s_cec0fc->unknown8fe760(type, index);
				}
				else if (OpR5f_toUpper_4083a0(command) == "ANALYSIS(YAULER)")
					REPLY("Punishment for those who don't use a TNC.\nRewarding for those who come prepared.", 1);
				else
				{
					REPLY(index == -1 ? "Unknown robot class." : (index == -2 ? "No relevant analysis within system authorization." : "Data survey shows that all relevant analyses have been obtained."), 2);
					FAIL();
				}
			}
		}
		else
		{
			REPLY("Invalid syntax.", 2);
			FAIL();
		}
	}
	else if (opw1_findNoCase(command, "Prototypes") != -1 && opw1_findNoCase(command, "Inventory(") == -1)
	{
		type = 4;
		if (!teamb_isAvailable9004e0(type, &command))
			return;
		if (d2s_cefc4c->unknown463b10())
		{
			command = d2s_d2d578;
			REPLY("Central database compromised, local access denied.", 2);
			FAIL();
		}
		else
		{
			int index = d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->fc + 1;
			if (d2s_cec100->unknown91ca50(d2s_cec0f8->getMachine_4b1460(), 0, type, index, 0, 0, D2sHItem()))
				d2s_cec0fc->unknown8fe760(type, index);
		}
	}
	else if (opw1_findNoCase(command, "Load(") == 0)
	{
		type = 0x42;
		if (!teamb_isAvailable9004e0(type, &command))
			return;
		string name;
		if (teamb_parenthesized900870(command, name))
		{
			int index = OpS8d_findNameNoCase8((vector<OpS8d_Rec8 *> &)d2s_d2d1c4, name);
			int index2 = index == -1 ? OpS8d_findNameNoCase4((vector<OpS8d_Rec4 *> &)d2s_d25de0, name) : -1;
			if (index == -1 && index2 == -1)
			{
				for (unsigned int i = 0; i < d2s_cf4888.size(); i++)
				{
					if (d2s_cf4888[i] && opw1_findNoCase(d2s_d25de0[i]->f1ac, name) != -1)
					{
						index2 = i;
						break;
					}
				}
				if (index2 == -1)
				{
					for (unsigned int i = 0; i < d2s_cf4844.size(); i++)
					{
						if (d2s_cf4844[i] && opw1_findNoCase(d2s_d2d1c4[i]->search, name) != -1)
						{
							index = i;
							break;
						}
					}
				}
			}
			if ((index == -1 || !d2s_cf4844[index]) && (index2 == -1 || !d2s_cf4888[index2]))
			{
				if (index == -1 && index2 == -1)
					command = "Load(" + name + ")";
				else
					command = "Load(" + (index != -1 ? d2s_d2d1c4[index]->name : d2s_d25de0[index2]->name) + ")";
				REPLY("Schematic not found.", 2);
				FAIL();
			}
			else
				d2s_cec100->unknown91ca50(d2s_cec0f8->getMachine_4b1460(), 0, type, -1, index == -1 ? 0 : d2s_d2d1c4[index], index2 == -1 ? 0 : d2s_d25de0[index2], D2sHItem());
		}
		else
		{
			REPLY("Invalid syntax.", 2);
			FAIL();
		}
	}
	PART_CMD("Scan(", 0x4c, unknown5773d0(1, 0), "Scan(", "Part undamaged or not repairable.", "Part not found.", "Invalid syntax.")
	PART_CMD("Recycle(", 0x51, unknown5775a0(), "Recycle(", "Part cannot be recycled.", "Part not found.", "Invalid syntax.")
	PART_CMD("Insert(", 0x5e, unknown5776c0(), "Insert(", "Part rejected, cannot be scanalyzed.", "Part not found.", "Invalid syntax.")
	else if (opw1_findNoCase(command, "Study(") != -1)
	{
		type = 0x60;
		if (!teamb_isAvailable9004e0(type, &command))
			return;
		string name;
		if (teamb_parenthesized900870(command, name))
		{
			if (d2s_cefc4c->unknown463b10())
			{
				REPLY("Central database compromised, local access denied.", 2);
				FAIL();
			}
			else
			{
				PART_BODY(unknown577700(), "Study(", "Part rejected, no study data available.", "Part not found.")
			}
		}
		else
		{
			REPLY("Invalid syntax.", 2);
			FAIL();
		}
	}
	else
	{
		int index = OpQ1_findStringNoCase(d2s_d2d508, 0x70, command);
		if (index != -1)
		{
			type = index;
			if (!teamb_isAvailable9004e0(type, &command))
				return;
			if (d2s_cec100->unknown91ca50(d2s_cec0f8->getMachine_4b1460(), 0, type, -1, 0, 0, D2sHItem()))
				d2s_cec0fc->unknown8fe760(type, -1);
		}
		else
		{
			command = OpR5f_toUpper_4083a0(command);
			int trojan = OpT8a_findString(d2s_d1e900, command);
			if (trojan == -1)
			{
				for (unsigned int i = 0; i < d2s_d1e900.size(); i++)
				{
					if (command.size() == d2s_d1e900[i].size() - 2 && d2s_d1e900[i].find(command, 0) != string::npos)
					{
						trojan = i;
						command = d2s_d1e900[i];
						break;
					}
				}
			}
			bool done = false;
			int result = -1;
			int mark = d2s_cf1080.get_mutable()->back()->turn;
			int bonus = d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->f11 ? 5 : 0;
			if (trojan != -1)
			{
				if (d2s_b99270[trojan] && OpX5_containsRecord(d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->f50, trojan))
				{
					REPLYV(d2s_cf0470[trojan].empty() ? string("Memory inaccessible.") : d2s_cf0470[trojan], 2);
					goto fail;
				}
				else if (d2s_b99270[trojan] && d2s_d1e910[trojan] == d2s_b99270[trojan])
				{
				}
				else
				{
					if (teamb_hack900340(0x37, (TeamB_Machine *)d2s_cefc4c->getPlayer()->getInventory_45ad90(), trojan, &result))
						done = true;
					if (d2s_cefc4c->getPlayer().operator->() && d2s_cec0f8->getMachine_4b1460().operator->() && teamb_hack900340(0x38, (TeamB_Machine *)d2s_cec0f8->getMachine_4b1460()->unknown45c9b0(), trojan, &result))
						done = true;
					if (done)
					{
						OpW7_unknown4b1bf0(d2s_cefc4c->getPlayer(), D2sHEntity());
						OpW7_unknown4b1bf0(D2sHEntity(), d2s_cec0f8->getMachine_4b1460());
						d2s_d1e910[trojan]++;
						d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->f50.push_back(trojan);
					}
				}
			}
			if (done)
			{
				if (!(d2s_cefc4c->getPlayer().operator->() && d2s_cec0f8->getMachine_4b1460().operator->() && result == 0))
				{
					if (result == 2 && d2s_cec0f8->getMachine_4b1460().operator->())
						d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->f28 = -1;
					d2s_cec0f8->close();
					if (trojan == 14)
						d2s_cf45d8.unknown77fbc0(0x171);
					return;
				}
				else if (d2s_cefc88)
					d2s_cefc88 = false;
				else
				{
					vector<D2sMsg *> *log = d2s_cf1080.get_mutable();
					if (log->back()->turn != mark)
					{
						string text;
						for (int i = log->size() - 1; ; i--)
						{
							if ((*log)[i]->turn == mark)
							{
								for (unsigned int j = i + 1; j < log->size(); j++)
								{
									if ((*log)[j]->type->id == 0x326)
										continue;
									string line = (*log)[j]->text;
									if (j == i + 1 && !d2s_d28f62 && !(*log)[j]->type->b46 && isdigit(line[0]))
									{
										unsigned int pos = line.find(' ');
										if (pos != string::npos)
											line.erase(line.begin(), line.begin() + pos + 1);
									}
									while (line.size() >= 2 && line[0] == ' ' && line[1] == ' ')
										line.erase(line.begin());
									text += line;
								}
								break;
							}
						}
						REPLYV(text, 1);
					}
				}
			}
			else if ((command == "\\\\1234" || command == "1234") && d2s_cec0f8->getMachine_4b1460()->name_45c590() == "EX-Vault Access")
				REPLY("Not this time, boltface!", 1);
			else if (d2s_cec0f8->getMachine_4b1460()->getData_45cb30()->f11 && OpT8a_findStringIndex(d2s_d2ae30, 13, command) != -1)
			{
				int index = OpT8a_findStringIndex(d2s_d2ae30, 13, command);
				if (d2s_d1e920[index] == 0)
				{
					if (!d2s_d1dd38)
						REPLY("Unknown command.", 2);
					else
						REPLY("No connection found.", 2);
				}
				else
				{
					switch (index)
					{
					case 0:
					{
						string text;
						int value = 130;
						text += "[ Establishing connection... ]";
						bool blocked = false;
						int faction = d2s_d1e888->getDepthIndex();
						if (d2s_d1dd48[faction] || d2s_cefc4c->unknown463890(2, 10)->test_45e380())
						{
							text += "\n[ Loyalty in question, dispatches revoked. ]";
							text += "\n[ Suggest relying on intel support... ]";
							text += "\n[ Prove dedication to collective cause. ]";
							if (!d2s_d1dd48[faction])
							{
								d2s_d1dd48[faction] = 1;
								for (int i = faction - 1, n = faction + 1; i >= 0 && n <= 10; i--)
								{
									if (d2s_d1dd48[i])
									{
										d2s_d1dd48[n] = 1;
										n++;
									}
								}
								LOG0(0x89);
								if (d2s_d25450.b0)
									value = 100;
							}
						}
						else if (!d2s_b90458[d2s_d1e888->f4])
						{
							text += "\n[ Error: Unable to find teleport path. ]";
							text += "\n[ Suggest relying on intel support. ]";
						}
						else
						{
							if (d2s_d1e888->f4 == 0x22)
							{
								for (unsigned int i = 0; i < d2s_d31640.size(); i++)
								{
									if (!d2s_d31640[i].empty() && d2s_d31640[i][0]->name_45c590() == "COM_Teleport_Inhibitor" && d2s_d31640[i][0]->unknown457b10() == 0)
									{
										blocked = true;
										break;
									}
								}
							}
							if (blocked)
							{
								text += "\n[ Error: Teleport tests failed, analyzing... ]";
								text += "\n[ Cause unknown. ]";
								text += "\n[ Suggest disengaging cave seals for backup. ]";
							}
							else if (d2s_d1dda0)
								text += "\n[ Dispatch in progress. ]";
							else if (d2s_cefc4c->getTurn() < d2s_d1dd44)
								text += "\n[ Recharging teleporter, ETC: " + intToString(d2s_d1dd44 - d2s_cefc4c->getTurn()) + ". ]";
							else
							{
								text += "\n[ Retrieving roster... ]";
								if (d2s_d1dd90.empty())
									text += "\n  [ No squads available. ]";
								else
								{
									text += "\n[ Squads on standby: ]";
									for (unsigned int i = 0; i < d2s_d1dd90.size(); i++)
										text += "\n  [ " + intToString(i + 1) + " : " + (d2s_d1dd90[i]->name.empty() ? (d2s_d1dd90[i]->type == 7 ? d2s_d25de0[d2s_d1dd58[d2s_d1e888->getDepthIndex()]]->f1ac + "/" + d2s_d29bbc : d2s_d29af8[d2s_d1dd90[i]->type]) : d2s_d1dd90[i]->name + "/" + d2s_d29af8[d2s_d1dd90[i]->type] + "(" + intToString(d2s_d1dd90[i]->f20) + ")") + " ]";
								}
								for (int i = 1, j = 0; i <= 6; i++, j++)
									d2s_d1e920[i] = j < d2s_d1dd90.size();
							}
						}
						REPLYV(text, 1);
						if (d2s_d25450.b0 && value != 130)
						{
							int portrait = d2s_d25450.unknown69e700(value, 0, 0.0f);
							if (portrait != 6)
								d2s_cec100->opG1_showXomPortrait(portrait);
						}
						break;
					}
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
						if (d2s_d1dd48[d2s_d1e888->getDepthIndex()])
						{
							string text = "\n[ Loyalty in question, dispatches revoked. ]";
							text += "\n[ Suggest relying on intel support... ]";
							text += "\n[ Prove dedication to collective cause. ]";
							REPLYV(text, 2);
						}
						else
						{
							unsigned int squad = index - 1;
							if (squad >= d2s_d1dd90.size())
								REPLY("[ Invalid squad designation. ]", 2);
							else if (d2s_cefc4c->getTurn() < d2s_d1dd44)
							{
								string text = "[ Recharging teleporter, ETC: " + intToString(d2s_d1dd44 - d2s_cefc4c->getTurn()) + ". ]";
								REPLYV(text, 2);
							}
							else if (d2s_d1dda0)
							{
								REPLY("[ Dispatch in progress. ]", 2);
								logError("cShellManualDone()", "Dispach request while another in progress should be impossible b/c recharging");
							}
							else
							{
								d2s_d1dda0 = d2s_d1dd90[squad];
								removeVectorElement_9de6f0(d2s_d1dd90, squad);
								d2s_d1dda4 = d2s_cec0fc->unknown4aeb30();
								d2s_d1dd44 += 200;
								string text = "[ Target locked, reinforcements inbound... ]";
								REPLYV(text, 1);
							}
							for (int i = 1; i <= 6; i++)
								d2s_d1e920[i] = 0;
							bonus = 4;
						}
						break;
					case 7:
					{
						string text;
						text += "[ Establishing connection... ]";
						text += "\n[ Retrieving vulnerable data list... ]";
						if (d2s_d1dda8.empty())
							text += "\n  [ No targets available. ]";
						else
						{
							for (unsigned int i = 0; i < d2s_d1dda8.size(); i++)
								text += "\n  [ " + intToString(i + 1) + " : " + opY5_getIntelLabel(d2s_d1dda8[i]) + " ]";
						}
						REPLYV(text, 1);
						for (int i = 8, j = 0; i <= 11; i++, j++)
							d2s_d1e920[i] = j < d2s_d1dda8.size();
						break;
					}
					case 8:
					case 9:
					case 10:
					case 11:
					{
						unsigned int target = index - 8;
						if (target >= d2s_d1dda8.size())
							REPLY("[ Invalid target. ]", 2);
						else if (d2s_d1ddb8 != 15)
						{
							d2s_d1ddb8 = d2s_d1dda8[target];
							d2s_d1e920[12] = 1;
							string text = "[ Reprioritizing " + opY5_getIntelLabel(d2s_d1ddb8) + "... ]";
							REPLYV(text, 1);
						}
						else
						{
							d2s_d1ddb8 = d2s_d1dda8[target];
							d2s_d1e920[12] = 1;
							string text = "[ Targeting " + opY5_getIntelLabel(d2s_d1ddb8) + "... ]";
							REPLYV(text, 1);
						}
						for (int i = 8; i <= 11; i++)
							d2s_d1e920[i] = 0;
						bonus = 4;
						break;
					}
					case 12:
					{
						if (d2s_d1ddb8 == 15)
						{
							string text = "[ Retrieving intel... ]";
							text += "\n[ No reports available. ]";
							REPLYV(text, 1);
						}
						else
						{
						d2s_d2c658.add4729d0(0x3de, 1, "", -1);
						d2s_d2c658.add4729d0(d2s_d1ddb8 + 0x3df, 1, "", -1);
						if ((*d2s_d2c658.values)[0x3de] == 10)
							d2s_cf45d8.unknown77fbc0(0xaa);
						LOGP(0x88, opY5_getIntelLabel(d2s_d1ddb8));
						string text = "[ Retrieving intel... ]";
						switch (d2s_d1ddb8)
						{
						case 0:
						{
							int count = 0;
							vector<D2sAccess *> *vec = d2s_cefc4c->getAccess_462e10();
							int type;
							for (unsigned int i = 0; i < vec->size(); i++)
							{
								if ((*vec)[i]->owner->inRange_46ecb0())
								{
									type = (*vec)[i]->owner->f4;
									count++;
								}
							}
							if (count == 0)
							{
								text += "\n[ No main access found. ]";
								d2s_cefc4c->unknown464ab0();
							}
							else
							{
								vector<Pos> points;
								text += "\n[ Confirmed " + intToString(count) + "x main access to " + d2s_mapNames_cfaca0[type] + "... ]";
								for (unsigned int i = 0; i < vec->size(); i++)
								{
									if ((*vec)[i]->owner->inRange_46ecb0())
									{
										text += "\n  [ " + OpQ1_pointToString((*vec)[i]->pos) + " ]";
										d2s_cefc4c->announceMachine_71dd30((*vec)[i]->owner);
										d2s_cefc4c->unknown4647a0((*vec)[i]->pos, 1);
										(*vec)[i]->b0d = true;
										points.push_back((*vec)[i]->pos);
									}
								}
								text += "\n[ Coordinates transferred. ]";
								d2s_cec100->addPointA8(points);
							}
							break;
						}
						case 1:
						{
							int count = 0;
							vector<D2sAccess *> *vec = d2s_cefc4c->getAccess_462e10();
							for (unsigned int i = 0; i < vec->size(); i++)
							{
								if ((*vec)[i]->unknown6c1a10())
									count++;
							}
							if (count == 0)
							{
								text += "\n[ No branch access found. ]";
								d2s_cefc4c->unknown464ad0();
							}
							else
							{
								vector<Pos> points;
								text += "\n[ Confirmed " + intToString(count) + "x branch access... ]";
								for (unsigned int i = 0; i < vec->size(); i++)
								{
									if ((*vec)[i]->unknown6c1a10())
									{
										text += "\n  [ " + OpQ1_pointToString((*vec)[i]->pos) + " " + d2s_mapNames_cfaca0[(*vec)[i]->owner->f4] + " ]";
										d2s_cefc4c->announceMachine_71dd30((*vec)[i]->owner);
										d2s_cefc4c->unknown4647a0((*vec)[i]->pos, 1);
										(*vec)[i]->b0d = true;
										points.push_back((*vec)[i]->pos);
									}
								}
								text += "\n[ Coordinates transferred. ]";
								d2s_cec100->addPointA8(points);
							}
							break;
						}
						case 2:
						{
							vector<Pos> points;
							for (int x = 1; x < d2s_cfd44c.getMaxX(); x++)
							{
								for (int y = 1; y < d2s_cfd44c.getMaxY(); y++)
								{
									if ((*d2s_cfd44c.at(x, y))->isShortcut())
										points.push_back(Pos(x, y));
								}
							}
							if (points.empty())
								text += "\n[ No emergency access found. ]";
							else
							{
								text += "\n[ Confirmed " + intToString(points.size()) + "x emergency access. ]";
								for (unsigned int i = 0; i < points.size(); i++)
								{
									d2s_cefc4c->unknown734d60(points[i]);
									bool sealed = false;
									if ((*d2s_cfd44c.atPoint(points[i]))->unknown45dbb0())
									{
										(*d2s_cfd44c.atPoint(points[i]))->unknown670690();
										sealed = true;
									}
									d2s_cefc4c->unknown4647a0(points[i], 1);
									if (sealed)
										(*d2s_cfd44c.atPoint(points[i]))->unknown670b20();
								}
								text += "\n[ Coordinates transferred. ]";
								d2s_cec100->addPointB8(points);
							}
							break;
						}
						case 3:
						{
							int count = 0;
							int faction = 0;
							int layer = 2;
							vector<D2sHMarker> &entries = (*d2s_cefc4c->unknown463ec0())[layer];
							entries.clear();
							for (unsigned int i = 0; i < d2s_cf6478.size(); i++)
							{
								if (d2s_cf6478[i]->faction == faction && !d2s_cf6478[i]->test_45e820())
								{
									count++;
									entries.push_back(d2s_cefaa8->createC_793190());
									entries.back()->unknown6c20b0(layer, d2s_cf6478[i]->entity->unknown45a4c0(), -1);
								}
							}
							if (count == 0)
								text += "\n[ No registered guards found. ]";
							else
							{
								text += "\n[ Confirmed " + intToString(count) + "x guard positions. ]";
								text += "\n[ Coordinates transferred. ]";
								d2s_cec100->resetField_4b0eb0();
							}
							break;
						}
						case 4:
						case 5:
						{
							vector<Pos> *vec = d2s_cefc4c->unknown463c20();
							vector<Pos> parts;
							D2sHItem item;
							for (int i = 0; i < vec->size(); i++)
							{
								item = (*d2s_cfd44c.atPoint((*vec)[i]))->getItem();
								if (item.isNull())
									OpQ5_eraseStep_9d7300(*vec, i);
								else
								{
									switch (d2s_d1ddb8)
									{
									case 4:
										if (item->stats_9b4350()->f94 == 0)
											parts.push_back((*vec)[i]);
										break;
									case 5:
										if (item->stats_9b4350()->f94 != 0)
											parts.push_back((*vec)[i]);
										break;
									}
								}
							}
							string noun = d2s_d1ddb8 == 4 ? "component" : "prototype";
							if (parts.empty())
								text += "\n[ No registered " + noun + " stockpiles found. ]";
							else
							{
								int type = d2s_d1ddb8 == 4 ? 14 : 15;
								vector<D2sHMarker> &list = (*d2s_cefc4c->unknown463ec0())[type];
								list.clear();
								for (unsigned int i = 0; i < parts.size(); i++)
								{
									list.push_back(d2s_cefaa8->createC_793190());
									list.back()->unknown6c20b0(type, parts[i], (*d2s_cfd44c.atPoint(parts[i]))->getItem()->getNestedField());
									d2s_cefc4c->unknown4647d0(parts[i]);
								}
								text += "\n[ Confirmed " + intToString(parts.size()) + "x " + noun + (parts.size() == 1 ? " stockpile" : " stockpiles") + ". ]";
								text += "\n[ Coordinates transferred. ]";
								d2s_cec100->resetField_4b0eb0();
							}
							break;
						}
						case 6:
						case 7:
						{
							vector<D2sRec8 *> list;
							int count = d2s_d1ddb8 == 6 ? rng.rangeInt(12.0f, 16.0f) : rng.rangeInt(8.0f, 12.0f);
							int type = d2s_d1ddb8 == 6 ? 2 : 1;
							for (int i = 0; i < count; i++)
							{
								int n = 0;
								D2sRec8 *rec;
								do
								{
									n++;
									if (n == 50)
									{
										rec = 0;
										break;
									}
									rec = d2s_cefc4c->selectRandomItem_6c3bc0(type, 0x1f, 0x12);
									if (rec == 0)
										break;
								} while (rec->f44 == 0 || OpX5_containsRecord(list, rec) || d2s_cf4844[rec->index]);
								if (rec)
									list.push_back(rec);
							}
							string desc = d2s_d1ddb8 == 6 ? "component" : "prototype";
							if (list.empty())
								text += "\n[ No " + desc + " schematics found. ]";
							else
							{
								text += "\n[ Retrieved " + intToString(list.size()) + "x " + desc + (list.size() == 1 ? " schematic" : " schematics") + "... ]";
								bool added = false;
								for (unsigned int i = 0; i < list.size(); i++)
								{
									text += "\n  [ " + list[i]->search + " ]";
									if (d2s_cf45d8.unknown780380(list[i]->index, 6))
										added = true;
								}
								if (added)
									d2s_cec08c->reopen8a2ce0(4, D2sHEntity());
							}
							break;
						}
						case 8:
						{
							vector<D2sRec4 *> found;
							int count = rng.rangeInt(3.0f, 5.0f);
							for (int i = 0; i < count; i++)
							{
								D2sRec4 *rec;
								int tries = 0;
								do
								{
									tries++;
									if (tries == 50)
									{
										rec = 0;
										break;
									}
									rec = d2s_cefc4c->unknown6c5180();
									if (rec == 0)
										break;
								} while (OpX5_containsRecord(found, rec) || d2s_cf4888[rec->index]);
								if (rec)
									found.push_back(rec);
							}
							if (found.empty())
								text += "\n[ No Unaware schematics found. ]";
							else
							{
								text += "\n[ Retrieved " + intToString(found.size()) + "x Unaware " + (found.size() == 1 ? "schematic" : "schematics") + "... ]";
								for (unsigned int i = 0; i < found.size(); i++)
								{
									text += "\n  [ " + found[i]->f1ac + " ]";
									d2s_cf45d8.unknown780480(found[i]->index, 6);
								}
							}
							break;
						}
						case 9:
						{
							int faction = d2s_d1e888->getDepthIndex();
							vector<int> pool;
							for (int i = 0; i < d2s_d25de0.size(); i++)
							{
								if (!d2s_d25de0[i]->f170.empty() && d2s_d25de0[i]->f24 == 1 && OpT8b_Fn9daf80(faction - 2, d2s_d25de0[i]->f68, faction + 2) && !d2s_cf4910[i])
									pool.push_back(i);
							}
							vector<int> list;
							int count = rng.rangeInt(3.0f, 5.0f);
							for (int i = 0; i < count; i++)
							{
								if (pool.empty())
									break;
								list.push_back(OpS8d_popRandom(pool));
							}
							if (list.empty())
								text += "\n[ No Unaware analyses found. ]";
							else
							{
								text += "\n[ Retrieved " + intToString(list.size()) + "x Unaware " + (list.size() == 1 ? "analysis" : "analyses") + "... ]";
								for (unsigned int i = 0; i < list.size(); i++)
								{
									text += "\n  [ " + d2s_d25de0[list[i]]->f1ac + " ]";
									d2s_cf45d8.unknown780700(i, 0);
								}
							}
							break;
						}
						case 10:
						{
							vector<Pos> traps;
							for (unsigned int i = 0; i < d2s_d20248.size(); i++)
							{
								for (unsigned int j = 0; j < d2s_d20248[i].size(); j++)
								{
									d2s_d20248[i][j]->unknown65f170();
									d2s_cefc4c->unknown4647d0(*d2s_d20248[i][j]->getPosition_4184d0());
									OpV4c_Fn9d3020((vector<Point> &)traps, *(Point *)d2s_d20248[i][j]->getPosition_4184d0());
								}
							}
							if (traps.empty())
								text += "\n[ No trap installation records found. ]";
							else
							{
								text += "\n[ Confirmed " + intToString(traps.size()) + "x trap installations. ]";
								text += "\n[ Coordinates transferred. ]";
								d2s_cec100->addPointC8(traps);
							}
							break;
						}
						case 11:
						case 12:
						{
							int group = d2s_d1ddb8 == 11 ? 0 : 5;
							vector<D2sHMarker> &marked = (*d2s_cefc4c->unknown463ec0())[0];
							for (int i = 0; i < marked.size(); i++)
							{
								if (marked[i]->f14 == group)
								{
									if ((*d2s_cfd44c.atPoint(marked[i]->pos))->unknown66b360())
										continue;
									OpQ5_eraseStep_9d6440(marked, i);
								}
							}
							vector<Pos> &paths = (*d2s_cefc4c->unknown459070())[group];
							string label = d2s_d1ddb8 == 11 ? "terminal" : "garrison";
							int located = 0;
							for (unsigned int i = 0; i < paths.size(); i++)
							{
								if ((*d2s_cfd44c.atPoint(paths[i]))->unknown66b360())
									continue;
								located++;
								marked.push_back(d2s_cefaa8->createC_793190());
								marked.back()->unknown6c20b0(0, paths[i], group);
							}
							if (located)
							{
								text += "\n[ Confirmed " + intToString(paths.size()) + "x " + label + (paths.size() == 1 ? ". ]" : "s. ]");
								text += "\n[ Coordinates transferred. ]";
								d2s_cec100->resetField_4b0eb0();
							}
							else
								text += "\n[ No active " + label + "s found. ]";
							break;
						}
						case 13:
						case 14:
						{
							vector<D2sHOwner> nodes;
							vector<D2sHOwner> routes;
							int depth = d2s_d1ddb8 == 13 ? d2s_d1e888->f8 : d2s_d1e888->f8 - 1;
							if (depth > 0)
							{
								OpC_findNodes_470050(depth, d2s_d1e884, nodes, routes);
								for (int i = 0; i < nodes.size(); i++)
								{
									if (!d2s_b90708[nodes[i]->f4].c)
										OpQ5_eraseStep_9d6440(nodes, i);
								}
							}
							if (nodes.empty())
								text += "\n[ No sectors found. ]";
							else
							{
								text += "\n[ Confirmed " + intToString(nodes.size()) + "x " + (nodes.size() == 1 ? "sector... ]" : "sectors... ]");
								for (unsigned int i = 0; i < nodes.size(); i++)
								{
									text += "\n  [ " + d2s_mapNames_cfaca0[nodes[i]->f4] + " ]";
									nodes[i]->b26 = true;
									d2s_d2c658.add4729d0(0x405, 1, "", -1);
								}
							}
							break;
						}
						}
						REPLYV(text, 1);
						OpS8b_Fn9d51d0(d2s_d1dda8, d2s_d1ddb8);
						d2s_d1ddbc.push_back(d2s_d1ddb8);
						d2s_d1ddb8 = 15;
						int n = OpX5_maxInt(d2s_d38624, d2s_d38628 - d2s_d1ddbc.size());
						if (d2s_d1dda8.size() < n)
						{
							D2sWL pool;
							for (int i = 0; i < 15; i++)
							{
								if ((d2s_bbbbec[i] || !OpX5_containsRecord(d2s_d1ddbc, i)) && !OpX5_containsRecord(d2s_d1dda8, i) && (i != 14 || d2s_d1e888->f8 != 1))
									pool.add(i, d2s_bbbbb0[i]);
							}
							while (d2s_d1dda8.size() < n && pool.total_9b81d0())
							{
								int pick = pool.pick();
								d2s_d1dda8.push_back(pick);
								pool.remove(pick);
							}
						}
						for (int i = 8; i <= 11; i++)
							d2s_d1e920[i] = 0;
						d2s_d1e920[12] = 0;
						}
						break;
					}
					}
					d2s_d1dd7c++;
				}
			}
			else
			{
				opR1f_466800();
				REPLY("Unknown command.", 2);
			}
fail:
			FAIL2(bonus);
		}
	}
	//@@REST
	}
}
