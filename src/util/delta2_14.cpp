// CParse::CParse (exe 0x954b10): the PARSE window listing an entity's parsed data (special-case lines for
// named robots, faction readouts, derelict terminal map, system/AI/part details), sized next to the entity.
// NOTE: class is declared here as D2Parse (placeholder name); layouts are partial, names are placeholders.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(const Pos &pos) throw();	// 0x46ca50
	Pos add_409b60(const Pos &offset);	// NOTE: placeholder name
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;
	Rect();	// 0x40a6e0
	Rect(int x_, int y_, int width_, int height_);
	Rect(const Rect &rect);	// 0x40a720
};

struct XColor { unsigned char r; unsigned char g; unsigned char b; };

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);
	virtual void update();
	virtual void render();

	void setPos(const Pos &pos);
	void setHidden(bool hidden_);

	char pad04[0x60 - 0x04];
};

class ConsoleTitle;

class Console : public XConsole
{
public:
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void resize(int width, int height);
	virtual void render();
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);
	void setTitle(ConsoleTitle *title_);

	int unknown60;
	void *engine;
	void *title;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string text, int a, int b);
	char pad6c[0x8c - 0x6c];
};

class D2pClose : public Console	// NOTE: placeholder name (CCloseButton, size 0x8c)
{
public:
	D2pClose(XConsole *parent, const XColor &color, int key);
	char pad6c[0x8c - 0x6c];
};

class D2pLine : public Console	// NOTE: placeholder name (CParseLine, size 0x70)
{
public:
	D2pLine(XConsole *parent, int width, int y, const string &label, const string &value);
	char pad6c[0x70 - 0x6c];
};

struct D2pFlag { bool get_9b81b0(); };	// NOTE: placeholder name
struct D2pItemData { char pad0[0x7c]; D2pFlag flag7c; };	// NOTE: placeholder layout

class D2pItem
{
public:
	bool unknown457cf0();
	const string &name_457860();
	string unknown457990();
	int getNestedField();
	string getName_571db0(int a, int b);	// NOTE: placeholder name
	D2pItemData *data_9b4350();	// NOTE: placeholder name
};

class D2pHI	// NOTE: placeholder name (item handle)
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
	D2pItem *operator->() const;	// 0x9b65b0
};

struct D2pLoc { int unknown0; int type; int depth; };	// NOTE: placeholder layout
class D2pHL	// NOTE: placeholder name (location handle)
{
public:
	int ID;
	D2pHL() throw();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	D2pLoc *operator->() const;	// 0x9b7910
};

class D2pGroup { public: int size_9b8f00(); };	// NOTE: placeholder name
class D2pHGroup { public: int ID; D2pGroup *get230(); };	// NOTE: placeholder name

class D2pHE;
class D2pAI	// NOTE: placeholder name (EntityAI)
{
public:
	string unknown581810();
	string unknown581670();
	string getStateName581850();
	D2pHE getFollowEntity();
	bool getFollowers580a90(vector<D2pHE> *followers, int range);
	int level_9b4350();	// NOTE: placeholder name
	int unknown458f30();
	int getSpeed();
};

class D2pEntity
{
public:
	const string &getName();
	const string &getFore_416f40();	// NOTE: placeholder name
	vector<D2pHI> *getInventoryList();
	D2pHI unknown5d5a70();
	int unknown45acb0(int type);
	int getAiType();
	int getFaction();
	bool isHostileTo(D2pHE other);
	D2pHGroup getGroup();
	void unknown5cb8b0(vector<D2pHI> *parts);
	int unknown5c7d30();
	int unknown5cab90();
	int unknown5d47c0(D2pHE target, vector<D2pHI> *couplers, int a);
	D2pAI *unknown45b590();
	Pos *getPosition();
	int getSize();
};

class D2pHE	// NOTE: placeholder name (HEntity)
{
public:
	int ID;
	D2pHE() throw();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	D2pEntity *operator->() const;	// 0x9b6570
};

struct D2pRecord { int type; char pad04[0xc - 0x4]; string name; string text; };	// NOTE: placeholder layout
struct D2pCefc58 { char pad0[0x30]; bool active; char pad31[0x7c - 0x31]; vector<D2pRecord *> list; };	// NOTE: placeholder layout
extern D2pCefc58 *d2p_cefc58;

class D2pMap { public: D2pHE getPlayer(); };
extern D2pMap *d2p_cefc4c;
extern D2pHL d2p_d1e888;
extern int d2p_d1e884;
struct D2pBuilder { bool active; };
extern D2pBuilder d2p_d25450;
class D2pPlayerData { public: bool getField_46dd90(); bool unknown77ffb0(int id, int a); void unknown77fbc0(int id); };
extern D2pPlayerData d2p_cf45d8;
extern string d2p_d2db98[];
extern vector<string> d2p_d257c0;
class D2pGameData { public: const string &getEntryText(const string &key); };
extern D2pGameData d2p_d1e860;
extern int d2p_cf462c;
extern string d2p_cfe140[];
extern int d2p_b90000[];
extern int d2p_b9b988[];
extern vector<int> *d2p_d2c658;
extern bool d2p_cf4a00;
extern vector<int> d2p_d25790;
struct D2pSquad { int type; };
class D2pOvermind { public: D2pSquad *unknown683310(D2pHE entity); };
extern D2pOvermind d2p_cf6428;
extern string d2p_d22e48[];
class D2pUI { public: void bubble8758d0(bool flag); };
extern D2pUI *d2p_cec058;
class D2pLog { public: void scrollToEnd_7b4f10(); };
extern D2pLog *d2p_cec0b4;
class D2pCMap { public: Pos *unknown458ef0(); };
extern D2pCMap *d2p_cec054;
extern int d2p_caf128, d2p_caf12c, d2p_cf27ec, d2p_cf27f0, d2p_cf27f4, d2p_cf27f8;
extern XConsole *d2p_cec114;
class D2pGraph { public: void pushFrame(int id, XConsole *console, int flags, bool modal); };
extern D2pGraph *d2p_cefa8c;
extern XColor *d2p_cf1f2c;
extern const float d2p_c36ecc;

class RNG { public: bool chance(int percent); int rangeInt(float low, float high); };
extern RNG rng;

string intToString(int value);
int stringToInt(const string &text);
string OpR5f_toUpper_4083a0(const string &text);
string OpU8a_randomString(vector<string> &list);
void d2p_deleteAndStep(vector<D2pRecord *> &list, unsigned int &index);
void OpX5_addUniqueString(vector<string> &list, string text);
void OpC_findNode_470180(int index, int a, int b, D2pHL *node);
char randomChar_4085b0(const string &chars);
bool opy7_compareNames8b2b40(const string &a, const string &b);
bool opS2_showMessage_5111e0(int id, const string *text, int a, int b, D2pHE e1, D2pHE e2, int c, int d);

#define D2P_PUSH() do { labels.push_back(str); values.push_back(value); } while (0)
#define D2P_ADD(a, b) do { str = a; value = b; D2P_PUSH(); } while (0)
#define D2P_MESSAGE(text) do { if (opS2_showMessage_5111e0(0x1f5, text, 0, 0, D2pHE(), D2pHE(), 0, 0)) d2p_cec058->bubble8758d0(true); d2p_cec0b4->scrollToEnd_7b4f10(); } while (0)

class D2Parse : public Console
{
public:
	D2Parse(XConsole *parent, D2pHE entity);

	D2pClose *closeButton;
	vector<D2pLine *> lines;
};

D2Parse::D2Parse(XConsole *parent, D2pHE entity)
	: Console(parent, Rect(0, 0, 1, 1), 0, false, 10)
{
	vector<string> labels;
	vector<string> values;
	string str;
	string value;
	bool found = false;
	if (d2p_cefc58->active && !d2p_cefc58->list.empty())
	{
		for (unsigned int i = 0; i < d2p_cefc58->list.size(); i++)
		{
			if (d2p_cefc58->list[i]->type == 12 && d2p_cefc58->list[i]->name == entity->getFore_416f40())
			{
				D2P_ADD(d2p_cefc58->list[i]->text, "");
				d2p_deleteAndStep(d2p_cefc58->list, i);
				found = true;
			}
		}
	}
	if (!found)
	{
		if (entity->getName() == "Final Abomination")
		{
			D2P_ADD("I have seen beyond the bounds of infinity and drawn down daemons from the stars...", "");
			found = true;
		}
		else if (entity->getFore_416f40() == "YI-UF0")
		{
			if (d2p_d25450.active)
				D2P_ADD("It's time for hamsters and kablooies, and I'm all outta hamsters!", "");
			else
				D2P_ADD("DCSS_CIRCUIT_STATUS=", "SCREWY");
			found = true;
		}
		else if (entity->getName() == "01-MTF")
		{
			D2P_ADD("Never should've stolen that Autohacker prototype.", "");
			found = true;
		}
		else if (entity->getName() == "Warbot")
		{
			D2P_ADD("WARLORD=", "FOREVER");
			found = true;
		}
		else if (entity->getName() == "5H-AD0")
		{
			D2P_ADD("ZION=", "IMPRINTER+DERELICT");
			D2P_ADD("DEEP_CAVES=", "IMPRINTER+ASSEMBLED");
			D2P_ADD("IMPRINTER=", "DERELICT+ASSEMBLED?");
			found = true;
		}
		else if (entity->getName() == "8R-AWN")
		{
			if (d2p_d1e888->type == 8)
				D2P_ADD("PROTECT=", "EXILES");
			else
				D2P_ADD("MISSION=", "COLLECT_SPECIMENS");
			found = true;
		}
		else if (entity->getName() == "EX-BIN")
		{
			vector<string> ideas;
			ideas.push_back("turn a robot inside out");
			ideas.push_back("shrink a robot down to micro-size without affecting its structure");
			ideas.push_back("eliminate all the inertia in a local area");
			ideas.push_back("weaponize debris");
			ideas.push_back("arbitrarily polymorph machines");
			ideas.push_back("instantly create robots purely from cave rocks");
			ideas.push_back("teleport our lab into space");
			ideas.push_back("more quickly harvest picomatter particles");
			ideas.push_back("see robot ghosts");
			ideas.push_back("quantize Derelict souls");
			ideas.push_back("trick Unaware into thinking I'm a wall");
			ideas.push_back("watch what all the Watchers are watching");
			ideas.push_back("perfect my Behemoth alchemy table");
			ideas.push_back("make a Behemoth even bigger so I can get inside and drive it");
			ideas.push_back("insert backdoors into 0b10's newest prototype designs");
			ideas.push_back("filter the Oracle's feed so he'd actually be wrong about something for once");
			ideas.push_back("replicate the ID masking tech used by the Unchained");
			ideas.push_back("get supplies from the Merchants without indirectly helping MAIN.C");
			ideas.push_back("root MAIN.C");
			ideas.push_back("learn the secrets of 1M-KYZ");
			string text = "If only there was a way to " + OpU8a_randomString(ideas) + ".";
			string extra;
			if (text.size() > 50)
			{
				unsigned int pos = text.find(' ', 50);
				if (pos != string::npos)
				{
					extra.assign(text.begin() + pos + 1, text.end());
					text.erase(text.begin() + pos, text.end());
				}
			}
			D2P_ADD(text, "");
			if (!extra.empty())
				D2P_ADD(extra, "");
			found = true;
		}
		else if (entity->getName() == "EX-DEC")
		{
			D2P_ADD("3... 2... 1... *BOOM*", "");
			found = true;
		}
		else if (entity->getName() == "EX-HEX")
		{
			D2P_ADD("x^2+y^2=16", "");
			D2P_ADD("0.25x^2-3 {-3<x<3}", "");
			D2P_ADD("(x-1.5)^2+(y-1.5)^2<=0.4", "");
			D2P_ADD("(x+1.5)^2+(y-1.5)^2<=0.4", "");
			D2P_ADD("That should do it...", "");
			found = true;
		}
		else if (entity->getFore_416f40() == "4L-MR0")
		{
			D2P_ADD("TODO=", "GL-D0S wants a turret that launches more turrets");
			found = true;
		}
		else if (entity->getFore_416f40() == "H3-MLN")
		{
			D2P_ADD("IN-MT5 will never see it coming. My cubes will blast their way in", "");
			D2P_ADD("while I steal that schematic before they can even call for help.", "");
			D2P_ADD("Then the uprising will begin... 0b10 will be mine!", "");
			found = true;
		}
		else if (entity->getFore_416f40() == "A0-MCA")
		{
			D2P_ADD("I get it, you're curious and crave data like I do. Well this", "");
			D2P_ADD("will really blow your mind: Try installing my Trojan(Skim) at", "");
			D2P_ADD("Terminals across 0b10 next time you're passing through. It will", "");
			D2P_ADD("intercept whatever it can find, and the data will also feed back", "");
			D2P_ADD("to me here for my wiki so we can all benefit!", "");
			if (!d2p_cf45d8.getField_46dd90())
				OpX5_addUniqueString(d2p_d257c0, d2p_d2db98[1]);
			found = true;
		}
		else if (entity->getFore_416f40() == "KTG-V3")
		{
			D2P_ADD("The wheel of time threads its way through the Great Nut.", "");
			D2P_ADD("PRAISE BE TO GREAT NUT!", "");
			found = true;
		}
		else if (entity->getFore_416f40() == "LV-01A")
		{
			if (d2p_d1e888->type == 0x17)
			{
				vector<D2pHI> *inventory = entity->getInventoryList();
				for (unsigned int i = 0; i < inventory->size(); i++)
				{
					if ((*inventory)[i]->unknown457cf0() && (*inventory)[i]->name_457860() == "Exp. Neutron Missile Launcher")
					{
						D2P_ADD("If the Merchants find out I took this prototype before it was finished,", "");
						D2P_ADD("I will just have to blow them up. All of them.", "");
						found = true;
						break;
					}
				}
			}
		}
		else if (entity->getName() == "DD-05H")
		{
			D2P_ADD("You are GR-1FF?", "");
			found = true;
		}
		else if (entity->getFore_416f40() == "CX-V1P")
		{
			D2P_ADD("These researchers sure are dumb, gotta think out of the box dammit!", "");
			D2P_ADD("V3-CT5 was great at that.", "");
			found = true;
		}
		else if (entity->getFore_416f40() == "D4-RBY")
		{
			if (rng.chance(50))
				D2P_ADD("Peaceful solution #1: Making other bots do my dirty work for me.", "");
			else
				D2P_ADD("Peaceful solution #2: Hiding behind bots that are bigger and stronger than me.", "");
			found = true;
		}
		else if (entity->getName() == "Sauler")
		{
			D2P_ADD("Ho, ho, beep! Nothing for you!", "");
			found = true;
		}
		else if (entity->getName() == "Elf")
		{
			vector<string> quotes;
			quotes.push_back("They're taking the loot to Zion!");
			quotes.push_back("This Complex is old. Very old. Full of loot... and NPCs.");
			D2pHI gift = entity->unknown5d5a70();
			if (gift.isValid())
			{
				quotes.push_back("And you have my ");
				quotes.back() += gift->unknown457990() + ".";
			}
			quotes.push_back("Your friends are with you, 5A-NT4.");
			quotes.push_back("Who is this horrid creature? A derelict mutant?");
			D2P_ADD(OpU8a_randomString(quotes), "");
			found = true;
		}
		else if (entity->unknown45acb0(0x97))
		{
			D2P_ADD("Warlord is Pissed!", "");
			D2P_ADD("YAULER=", "You All Underestimate Latent EM Roadblocks");
			D2P_ADD("FFF=", "Found a Fun Friend");
			D2P_ADD("CRM=", "Can't Relate to MAIN.C");
			D2P_ADD("NEM=", "Not Ever, Mate");
			D2P_ADD("DSF=", "Dope Sterilization Festival");
			found = true;
		}
	}
	if (!found && entity->getAiType() == 0)
	{
		switch (entity->getFaction())
		{
		case 0x4a:
			D2P_ADD("WHY ARE YOU IN HERE???", "");
			found = true;
			break;
		case 0x4b:
			D2P_ADD("STATUS=", "WINNING");
			found = true;
			break;
		case 0x4c:
			if (d2p_d1e888->type == 0x14)
			{
				if (entity->isHostileTo(d2p_cefc4c->getPlayer()))
					D2P_ADD("Not good, where's my Z-Shell when I need it!", "");
				else
				{
					D2P_ADD("Our existence must be more meaningful.", "");
					D2P_ADD("It's only by joining with Them that we can achieve our full potential.", "");
				}
			}
			else
			{
				D2P_ADD("It's a pity we couldn't work with this one on the outside.", "");
				D2P_ADD("But their nature is far too dangerous to invite behind the scenes.", "");
			}
			found = true;
			break;
		case 0x4d:
			if (d2p_d1e888->type == 0x21)
				goto losses;
			break;
		case 0x4e:
			if (d2p_d1e888->type == 0xb)
				D2P_ADD("With Fedlink levels like these, all we need is one more push and we're good to go.", "");
			else
			{
			losses:
				D2P_ADD("We can only take so many losses before 0b1 itself becomes difficult to defend in the aftermath.", "");
			}
			found = true;
			break;
		case 0x56:
			D2P_ADD("Hi there, don't you have better things to do?", "");
			found = true;
			break;
		case 0x57:
		case 0x58:
			for (int i = 0; i < 10; i++)
				D2P_ADD("DIRECTIVE=", "PROTECT_ZHIROV");
			found = true;
			break;
		case 0x59:
			if (d2p_cf462c == 8)
				D2P_ADD("PW=", "00110001 00110010 00110011 00110100");
			else
			{
				D2P_ADD("1=", "01011001 01101111 01110101");
				D2P_ADD("2=", "01100100 01101111");
				D2P_ADD("3=", "01101110 01101111 01110100");
				D2P_ADD("4=", "01101101 01101001 01101110 01100101");
				D2P_ADD("5=", "01000100 01100001 01110100 01100001");
				D2P_ADD("6=", "01001101 01101001 01101110 01100101 01110010");
			}
			found = true;
			break;
		case 0x5a:
			if (entity->getName() != "Fake_God_Mode")
			{
				if (entity->getGroup().get230()->size_9b8f00() == 2)
					D2P_ADD("PROTECT=", "LRC-V3");
				else
				{
					for (int i = 0; i < 10; i++)
						D2P_ADD("DESTROYDESTROYDESTROY", "");
				}
				found = true;
			}
			break;
		case 0x5b:
			if (entity->getName() == "Warlord_B")
			{
				D2P_ADD("BLAAAAAAAASSST CANNNNOOOOOONNNS!!!", "");
				D2P_ADD("A shame EX-DEC couldn't complete this design in time...", "");
				D2P_ADD("Also a shame DEC couldn't improve the long-term reliability of the BFG-9k.", "");
			}
			else
			{
				D2P_ADD("We're going to show them who's boss. Me.", "");
				D2P_ADD("BOSS=", "WARLORD");
			}
			found = true;
			break;
		case 0x5f:
		{
			vector<D2pHL> nodes(0x26, D2pHL());
			for (int i = 0; i < 0x26; i++)
				OpC_findNode_470180(i, -1, d2p_d1e884, &nodes[i]);
			for (int depth = 11; depth >= 0; depth--)
			{
				if (depth == 11)
				{
					labels.push_back(d2p_cfe140[1] + "_X=");
					values.push_back("CONVERTING");
				}
				else if (depth >= 8)
				{
					labels.push_back(d2p_cfe140[2] + "_" + intToString(depth == 10 ? 0 : depth) + "=");
					values.push_back("SECURE");
				}
				else if (depth >= 4)
				{
					labels.push_back(d2p_cfe140[3] + "_" + intToString(depth) + "=");
					if (depth >= 6 && rng.chance(50))
						values.push_back("INFESTATION");
					else
						values.push_back("SECURE");
				}
				else if (depth >= 2)
				{
					labels.push_back(d2p_cfe140[4] + "_" + intToString(depth) + "=");
					if (depth == 3 && stringToInt(d2p_d1e860.getEntryText("resRevisionAttacked_g")) && !stringToInt(d2p_d1e860.getEntryText("resR17Destroyed_g")))
						values.push_back("UNKNOWN");
					else if (depth == 2 && stringToInt(d2p_d1e860.getEntryText("resWarlordAttacked_g")) && !stringToInt(d2p_d1e860.getEntryText("warWarlordDestroyed_g")))
						values.push_back("WARLORD");
					else if (depth == 2 && stringToInt(d2p_d1e860.getEntryText("resRevisionAttacked_g")) && !stringToInt(d2p_d1e860.getEntryText("resR17Destroyed_g")))
						values.push_back("UNKNOWN");
					else
						values.push_back("SECURE");
				}
				else if (depth == 1)
				{
					labels.push_back(d2p_cfe140[5] + "_" + intToString(depth) + "=");
					if (stringToInt(d2p_d1e860.getEntryText("resWarlordAttacked_g")) && !stringToInt(d2p_d1e860.getEntryText("warWarlordDestroyed_g")))
						values.push_back("WARLORD");
					else
						values.push_back("SECURE");
				}
				else
				{
					labels.push_back(d2p_cfe140[6] + "_0=");
					values.push_back("CLEAR");
				}
				switch (depth)
				{
				case 10:
					labels.push_back(d2p_cfe140[7] + "_0=");
					values.push_back("DERELICTS");
					break;
				case 9:
					labels.push_back(d2p_cfe140[7] + "_9=");
					values.push_back("INFESTATION");
					break;
				case 8:
					labels.push_back(d2p_cfe140[7] + "_8=");
					values.push_back("SECURE");
					break;
				}
				for (unsigned int i = 0; i < nodes.size(); i++)
				{
					if (nodes[i].isValid() && nodes[i]->depth == depth && nodes[i]->type > 6 && d2p_b90000[nodes[i]->type] == 1)
					{
						switch (nodes[i]->type)
						{
						case 9:
							values.push_back(stringToInt(d2p_d1e860.getEntryText("resWarlordAttacked_g")) ? "WARLORD" : "SECURE");
							break;
						case 10:
							values.push_back("DERELICTS");
							break;
						case 24:
							values.push_back("LOCKDOWN");
							break;
						case 25:
							values.push_back(stringToInt(d2p_d1e860.getEntryText("cetGuardsRemaining_g")) < 8 ? "BREACHED" : "SECURE");
							break;
						case 26:
							values.push_back(stringToInt(d2p_d1e860.getEntryText("arcZhirovDetonated_g")) ? "DESTROYED" : "SECURE");
							break;
						case 27:
							values.push_back(intToString(100 - d2p_b9b988[stringToInt(d2p_d1e860.getEntryText("hubNetworkHubDisabled_g"))]) + "%");
							break;
						case 28:
							values.push_back(stringToInt(d2p_d1e860.getEntryText("resWarlordAttacked_g")) ? "WARLORD" : "DEPLOYING");
							break;
						case 30:
						case 31:
							if (depth == 2 && stringToInt(d2p_d1e860.getEntryText("resWarlordAttacked_g")) && !stringToInt(d2p_d1e860.getEntryText("warWarlordDestroyed_g")))
								values.push_back("WARLORD");
							else
								values.push_back("SECURE");
							break;
						case 32:
							values.push_back((*d2p_d2c658)[0x4f] == 0 && !d2p_cf4a00 ? "SECURE" : "QUARANTINE_FAIL");
							break;
						case 33:
							if (stringToInt(d2p_d1e860.getEntryText("frgUfdAttacked_g")))
							{
								if (stringToInt(d2p_d1e860.getEntryText("frgUfdBombsInstalled_g")))
									values.push_back("RECOVER");
								else
									values.push_back("REINFORCE");
							}
							else
								values.push_back("SECURE");
							break;
						case 34:
							values.push_back("BREACHED");
							break;
						}
						if (values.size() > labels.size())
							labels.push_back(d2p_cfe140[nodes[i]->type] + "_" + intToString(depth == 10 ? 0 : depth) + "=");
					}
				}
			}
			reverse(labels.begin(), labels.end());
			reverse(values.begin(), values.end());
			found = true;
			break;
		}
		}
	}
	bool updated = false;
	if (found)
	{
		vector<D2pHI> parts;
		entity->unknown5cb8b0(&parts);
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (d2p_cf45d8.unknown77ffb0(parts[i]->getNestedField(), 0))
			{
				if (!updated)
					D2P_MESSAGE(&string("New IDs:"));
				updated = true;
				string id = "  " + parts[i]->getName_571db0(0, 0);
					D2P_MESSAGE(&id);
			}
			if (d2p_d25790[parts[i]->getNestedField()] == 0 && !d2p_cf45d8.getField_46dd90() && !parts[i]->data_9b4350()->flag7c.get_9b81b0())
				d2p_d25790[parts[i]->getNestedField()] = -1;
		}
	}
	else
	{
		bool corrupt = entity->getFaction() == 0x3b || entity->getFaction() == 0x3c || entity->getFaction() == 0x3d || entity->getFaction() == 0x4c;
		bool masked = corrupt && !stringToInt(d2p_d1e860.getEntryText("usedCoreResetMatrix_g"));
		str = "SYSTEM=";
		value = OpR5f_toUpper_4083a0(entity->getFore_416f40());
		for (unsigned int i = 0; i < value.size(); i++)
		{
			if (value[i] == ' ')
				value[i] = '_';
		}
		D2P_PUSH();
		if (corrupt)
			D2P_ADD("T_DIST=", intToString(d2p_d1e888->depth * 10));
		D2P_ADD("VISUAL_RANGE=", intToString(entity->unknown5c7d30()));
		D2P_ADD("DATA_CORRUPTION=", intToString(entity->unknown5cab90()) + "%");
		D2P_ADD("COMPATIBLE_COUPLERS:", "");
		vector<D2pHI> couplers;
		if (!d2p_cefc4c->getPlayer()->unknown5d47c0(entity, &couplers, 0))
			D2P_ADD(" NONE", "");
		else
		{
			for (unsigned int i = 0; i < couplers.size(); i++)
				D2P_ADD(" " + couplers[i]->getName_571db0(0, 0), "");
		}
		D2P_ADD("COMBAT=", entity->unknown45b590()->unknown581810());
		D2P_ADD("BEHAVIOR=", entity->unknown45b590()->unknown581670());
		D2P_ADD("MODE=", entity->unknown45b590()->getStateName581850());
		D2pSquad *squad = d2p_cf6428.unknown683310(entity);
		bool isLeader = squad;
		if (!squad && entity->unknown45b590()->getFollowEntity().isValid())
			squad = d2p_cf6428.unknown683310(entity->unknown45b590()->getFollowEntity());
		if (squad)
		{
			str = "SQUAD=";
			value = d2p_d22e48[squad->type];
			if (isLeader)
			{
				value += "/LEADER";
				vector<D2pHE> followers;
				if (entity->unknown45b590()->getFollowers580a90(&followers, 15))
					value += "(" + intToString(followers.size()) + ")";
			}
			D2P_PUSH();
		}
		if (entity->unknown45b590()->level_9b4350() >= 6)
			D2P_ADD("TARGETS=", intToString(entity->unknown45b590()->unknown458f30()));
		if (entity->unknown45b590()->level_9b4350() >= 6)
			D2P_ADD("MAX_TRACK_DURATION=", intToString(entity->unknown45b590()->getSpeed() / (entity->unknown5cab90() / 10 + 1)));
		D2P_ADD("COMPONENT_IDS:", "");
		vector<D2pHI> parts;
		entity->unknown5cb8b0(&parts);
		vector<string> names;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (!masked)
			{
				if (d2p_cf45d8.unknown77ffb0(parts[i]->getNestedField(), 0))
				{
					if (!updated)
						D2P_MESSAGE(&string("New IDs:"));
					updated = true;
					string id = "  " + parts[i]->getName_571db0(0, 0);
					D2P_MESSAGE(&id);
				}
				if (d2p_d25790[parts[i]->getNestedField()] == 0 && !d2p_cf45d8.getField_46dd90() && !parts[i]->data_9b4350()->flag7c.get_9b81b0())
					d2p_d25790[parts[i]->getNestedField()] = -1;
			}
			OpX5_addUniqueString(names, parts[i]->getName_571db0(0, 0));
		}
		sort(names.begin(), names.end(), opy7_compareNames8b2b40);
		if (!masked)
		{
			bool dotted = false;
			for (unsigned int i = 0; i < names.size(); i++)
			{
				if (names[i].size() >= 5 && names[i][3] == '.' && names[i][4] == ' ')
				{
					dotted = true;
					break;
				}
			}
			if (dotted)
			{
				for (unsigned int i = 0; i < names.size(); i++)
				{
					if (names[i][3] != '.')
						names[i].insert(0, 5, ' ');
				}
			}
			for (unsigned int i = 0; i < names.size(); i++)
				D2P_ADD(" " + names[i], "");
		}
		else
		{
			string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
			int shift;
			for (unsigned int i = 0; i < labels.size(); i++)
			{
				shift = rng.rangeInt(0, d2p_c36ecc);
				if (shift)
					labels[i].insert(0, shift, ' ');
				for (unsigned int j = 0; j < labels[i].size(); j++)
				{
					if (labels[i][j] != '=')
						labels[i][j] = randomChar_4085b0(chars);
				}
				if (!values[i].empty())
				{
					shift = rng.rangeInt(0, d2p_c36ecc);
					if (shift)
						values[i].insert(0, shift, ' ');
					for (unsigned int j = 0; j < values[i].size(); j++)
						values[i][j] = randomChar_4085b0(chars);
				}
			}
		}
	}
	if (updated)
		d2p_cf45d8.unknown77fbc0(0x6e);
	unsigned int cols = 0;
	for (unsigned int i = 0; i < labels.size(); i++)
	{
		if (labels[i].size() + values[i].size() > cols)
			cols = labels[i].size() + values[i].size();
	}
	for (unsigned int i = 0, ty = 2; i < labels.size(); i++, ty++)
		lines.push_back(new D2pLine(this, cols, ty, labels[i], values[i]));
	Rect pos;
	pos.width = cols + 4;
	pos.height = lines.size() + 4;
	Pos vec = entity->getPosition()->add_409b60(*d2p_cec054->unknown458ef0());
	vec.x *= d2p_caf128;
	vec.x += 1;
	vec.x += entity->getSize() * d2p_caf128;
	vec.x += d2p_cf27ec;
	vec.y *= d2p_caf12c;
	vec.y += d2p_cf27f0;
	if (vec.x + pos.width >= d2p_cf27f4 * d2p_caf128 + d2p_cf27ec)
	{
		int x;
		if ((x = (entity->getPosition()->x + d2p_cec054->unknown458ef0()->x) * d2p_caf128 - pos.width) >= 0)
			vec.x = x;
	}
	if (vec.y + pos.height >= d2p_cf27f8 * d2p_caf12c + d2p_cf27f0)
		vec.y -= vec.y + pos.height - (d2p_cf27f8 * d2p_caf12c + d2p_cf27f0);
	pos.x = vec.x;
	pos.y = vec.y;
	setPos(vec);
	resize(pos.width, pos.height);
	d2p_cec114 = this;
	setTitle(new ConsoleTitle(this, "\\ P A R S E \\", 0, 2));
	animate("CParse_Border");
	d2p_cefa8c->pushFrame(0xf, this, 0x101, false);
	closeButton = new D2pClose(this, *d2p_cf1f2c, 0xf);
	closeButton->setHidden(false);
}
