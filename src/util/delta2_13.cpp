// CHack::trigger (exe 0x93ad00, vtable slot 11): builds the hacking window sections (utilities, system,
// status, detection, and the Derelict/lab/A0/archive/Zhirov special terminals).
// NOTE: class is declared here as D2Hack11 (placeholder name); layouts are partial, names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos) throw();	// 0x46ca50
	int randomInRange_40c130();	// NOTE: placeholder name
	bool test_409cf0(int a, int b);	// NOTE: placeholder name
};

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

	int getWidth_44b0d0();
	int getHeight();
	void print(int x, int y, const string &text);
	string getString(const Pos &pos, unsigned int length);
	int getChar(int x, int y);
	void resetBack_418450() throw();

	char pad04[0x60 - 0x04];
};

class D2kEffect { public: void init_50de10(); };	// NOTE: placeholder name
class D2kEngine	// NOTE: placeholder name
{
public:
	D2kEffect *unknown50fb50(D2kEngine *engine, int effect, const Pos &from, const Pos &color, const Pos *to, const Pos *color2, int layer);
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void render();
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);
	void unknown48c3c0(int value);	// NOTE: placeholder name

	int unknown60;
	D2kEngine *engine;
	void *title;
};

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);
	char pad6c[0x88 - 0x6c];
};

class D2kMachineUI : public Console	// NOTE: placeholder name (CMachine, size 0x98)
{
public:
	D2kMachineUI(XConsole *parent, struct D2kHProp machine);
	char pad6c[0x98 - 0x6c];
};

class D2kTrace : public Console	// NOTE: placeholder name (CHackTrace, size 0x74)
{
public:
	D2kTrace(XConsole *hack, int y);
	void setPercent(int percent);
	char pad6c[0x74 - 0x6c];
};

struct D2kInfo { char pad[0xf8]; int type; };	// NOTE: placeholder layout
struct D2kData { char pad00[0x10]; bool limited; char pad11[0x3c - 0x11]; int keyTurn; };	// NOTE: placeholder layout

class D2kMachine	// NOTE: placeholder name (machine prop)
{
public:
	D2kInfo *getInfo_9b8f00();
	D2kData *getData_45cb30();
	const string &name_45c590();
	int index_44ab40();
	int unknown45c870(int type);
	Pos *getPosition_4184d0();
};

struct D2kHProp
{
	int ID;
	D2kMachine *operator->() const;	// 0x9b64f0
};

class D2kItem
{
public:
	int unknown457f90();
	bool unknown457cf0();
	string unknown573860(int a, int b);
};

class D2kHItem
{
public:
	int ID;
	D2kItem *operator->() const;	// 0x9b65b0
};

class D2kEntity { public: vector<D2kHItem> *getInventoryList(); };
class D2kHEntity
{
public:
	int ID;
	D2kHEntity() throw();
	D2kEntity *operator->() const;
};

class D2kMap
{
public:
	D2kHEntity getPlayer();
	void unknown71aa80(D2kHProp machine, int *count);
	void unknown71a940(int *count);
	int getTurn();
	int unknown463ca0();
};
extern D2kMap *d2k_cefc4c;

class D2kGameData
{
public:
	const string &getEntryText(const string &key);
	bool unknown46f4b0(int a);
};
extern D2kGameData d2k_d1e860;

struct D2kNode { int index; int unknown4; string name; };	// NOTE: placeholder layout
extern D2kNode *d2k_cf4700;
struct D2kRecord { char pad0[0x148]; vector<int> list148; };	// NOTE: placeholder layout
extern vector<D2kRecord *> d2k_d25de0;
extern vector<vector<D2kHProp> > d2k_d31640;
extern int d2k_b9b988[];
extern bool d2k_cf49e4;
extern Pos d2k_d2e20c;
extern XConsole *d2k_cec034;
class D2kStats { public: void add472b90(unsigned int id, int value); };
extern D2kStats d2k_d2c658;
class D2kPlayerData { public: void unknown77fbc0(int id); };
extern D2kPlayerData d2k_cf45d8;

class RNG { public: bool chance(int percent); int rangeInt(float low, float high); };
extern RNG rng;

string intToString(int value);
int stringToInt(const string &text);
string OpY1_intToStringSigned(int value);
string OpR5f_toUpper_4083a0(const string &text);
bool OpT8b_Fn9daf80(int lo, int v, int hi);
bool OpX5_containsRecord(vector<int> &list, int value);
bool OpU8a_lookup1(const string &name, int *id);
bool opS2_logPhrase_5141b0(int id, const string *a, const string *b, const string *c, D2kHEntity subject, const Pos *at);

class D2Hack11 : public Console
{
public:
	virtual void trigger(const string &command, int value);

	void unknown942780(int x);	// NOTE: placeholder name

	bool unknown6c;
	int unknown70;
	void *closeButton;
	bool unknown78;
	int y;
	D2kHProp machine;
	int chance;
	int percent;
	XConsole *label;
	D2kTrace *trace;
	int unknown94;
	int linked;
};

void D2Hack11::trigger(const string &command, int value)
{
	if (command == "utilities")
	{
		Console *readout = new CText(this, Pos(2, y), "Utilities", 0, 0, -1);
		readout->animate("A_CHack_Header");
		y += 2;
		bool flag = machine->getInfo_9b8f00()->type == 1;
		vector<D2kHItem> *inventory = d2k_cefc4c->getPlayer()->getInventoryList();
		int listed = 0;
		int active = 0;
		int disabled = 0;
		for (unsigned int i = 0; i < inventory->size(); i++)
		{
			if (OpT8b_Fn9daf80(0x79, (*inventory)[i]->unknown457f90(), 0x7a) && listed < 15)
			{
				if ((*inventory)[i]->unknown457cf0())
				{
					readout = new CText(this, Pos(2, y), (*inventory)[i]->unknown573860(0, 0), 0, 0, -1);
					readout->animate("A_CHack_Text");
					readout = new CText(this, Pos(getWidth_44b0d0() - 3 - string(" ACTIVE ").size(), y), " ACTIVE ", 0, 0, -1);
					readout->animate("A_CHack_Label_Active");
					y++;
				}
				else
				{
					readout = new CText(this, Pos(2, y), (*inventory)[i]->unknown573860(0, 0), 0, 0, -1);
					readout->animate("A_CHack_Text_Grayed");
					readout = new CText(this, Pos(getWidth_44b0d0() - 3 - string(" INACTIVE ").size(), y), " INACTIVE ", 0, 0, -1);
					readout->animate("A_CHack_Label_Inactive");
					y++;
				}
				listed++;
			}
			else if (flag && (*inventory)[i]->unknown457f90() == 0x7b)
			{
				if ((*inventory)[i]->unknown457cf0())
					active++;
				else
					disabled++;
				listed++;
			}
		}
		if (listed == 0)
		{
			readout = new CText(this, Pos(2, y), "(None)", 0, 0, -1);
			readout->animate("A_CHack_Text");
			y++;
		}
		else
		{
			if (active)
			{
				string count = " " + intToString(active) + " ";
				readout = new CText(this, Pos(2, y), "Authchips (Active)", 0, 0, -1);
				readout->animate("A_CHack_Text");
				readout = new CText(this, Pos(getWidth_44b0d0() - 3 - count.size(), y), count, 0, 0, -1);
				readout->animate("A_CHack_Label_Active");
				y++;
			}
			if (disabled)
			{
				string count = " " + intToString(disabled) + " ";
				readout = new CText(this, Pos(2, y), "Authchips (Inactive)", 0, 0, -1);
				readout->animate("A_CHack_Text_Grayed");
				readout = new CText(this, Pos(getWidth_44b0d0() - 3 - count.size(), y), count, 0, 0, -1);
				readout->animate("A_CHack_Label_Inactive");
				y++;
			}
		}
		y++;
	}
	else if (command == "system")
	{
		Console *readout = new CText(this, Pos(2, y), "System", 0, 0, -1);
		readout->animate("A_CHack_Header");
		y += 2;
		readout = new CText(this, Pos(2, y), machine->getData_45cb30()->limited ? machine->name_45c590() + " (Limited)" : machine->name_45c590(), 0, 0, -1);
		readout->animate("A_CHack_Text");
		y++;
		y++;
	}
	else if (command == "status")
	{
		Console *readout = new CText(this, Pos(2, y), "Status", 0, 0, -1);
		readout->animate("A_CHack_Header");
		y += 2;
		int y0 = y;
		if (d2k_cf4700 && machine->getInfo_9b8f00()->type == 0 && OpX5_containsRecord(d2k_d25de0[d2k_cf4700->index]->list148, 10) && d2k_d1e860.unknown46f4b0(1))
		{
			string node = d2k_cf4700->name;
			if (node.rfind(" ") != string::npos)
				node.erase(node.begin(), node.begin() + node.rfind(" ") + 1);
			node = OpR5f_toUpper_4083a0(node);
			node.insert(0, "Node:");
			node += "_";
			for (int i = 0; i < 6; i++)
				node += intToString(rng.rangeInt(0, 9));
			print(2, y, node);
			y++;
		}
		d2k_cefc4c->unknown71aa80(machine, &linked);
		if (linked != 0)
		{
			print(2, y, "Linking terminal botnet (" + intToString(linked) + ")...");
			y++;
		}
		int count;
		d2k_cefc4c->unknown71a940(&count);
		if (count != 0)
		{
			print(2, y, "Linking operator network (" + intToString(count) + ")...");
			y++;
		}
		if (machine->getInfo_9b8f00()->type == 0)
		{
			if (machine->getData_45cb30()->keyTurn != 0)
			{
				if (d2k_cefc4c->getTurn() <= machine->getData_45cb30()->keyTurn)
					print(2, y, "Applying dynamic key...");
				else
					print(2, y, "Applying dynamic key... expired");
				y++;
			}
			if (d2k_cefc4c->unknown463ca0())
			{
				print(2, y, "SKIM NETWORK SIZE: " + intToString(d2k_cefc4c->unknown463ca0()) + "/" + intToString(5));
				y++;
			}
		}
		for (unsigned int i = 0; i < d2k_d31640[machine->index_44ab40()].size(); i++)
		{
			if (d2k_d31640[machine->index_44ab40()][i]->name_45c590().find("Repaired_Machine_") != string::npos)
			{
				print(2, y, "TOP QUALITY MACHINERY AT YOUR SERVICE");
				y++;
				break;
			}
		}
		int shift = machine->unknown45c870(9);
		if (shift != 0)
		{
			print(2, y, "RECONFIGURATION EFFECTIVENESS: " + OpY1_intToStringSigned(shift) + "%");
			y++;
		}
		print(2, y, "Scanning nodes...");
		y++;
		print(2, y, "Network defenses at " + intToString(100 - d2k_b9b988[stringToInt(d2k_d1e860.getEntryText("hubNetworkHubDisabled_g"))]) + "%...");
		y++;
		print(2, y, "Building attack tree...");
		y++;
		print(2, y, "Bypassing authorization...");
		y++;
		if (machine->getInfo_9b8f00()->type == 5 && stringToInt(d2k_d1e860.getEntryText("installedRif_g")))
			print(2, y, "Leveraging RIF...");
		y++;
		if (d2k_cf49e4 && machine->getInfo_9b8f00()->type < 6)
			print(2, y, "Leveraging 0b10 backdoors...");
		y++;
		int effect;
		OpU8a_lookup1("Type_GR3_Vert_E", &effect);
		for (int x = 2; x <= getWidth_44b0d0() - 3; x++)
			engine->unknown50fb50(engine, effect, Pos(x, y0), d2k_d2e20c, &Pos(x, y - 1), &Pos(d2k_d2e20c), 9)->init_50de10();
		y++;
	}
	else if (command == "detection")
	{
		if (chance == -1)
		{
			Console *readout = new CText(this, Pos(2, y), "System tracing...", 0, 0, -1);
			readout->animate("A_CHack_Text");
			y++;
			new D2kMachineUI(d2k_cec034, machine);
			readout = new CText(this, Pos(2, y), "Estimated Progress:", 0, 0, -1);
			readout->animate("A_CHack_Text");
			y++;
			trace = new D2kTrace(this, y);
			y += 2;
			trace->setPercent(percent);
		}
		else
		{
			Console *readout = new CText(this, Pos(2, y), "Chance of Detection: ", 0, 0, -1);
			readout->animate("A_CHack_Text");
			unknown942780(readout->getWidth_44b0d0() + 2);
			new D2kMachineUI(d2k_cec034, machine);
		}
	}
	else if (command == "der_system")
	{
		Console *readout = new CText(this, Pos(2, y), "System", 0, 0, -1);
		readout->animate("A_CHack_Header");
		y += 2;
		readout = new CText(this, Pos(2, y), machine->name_45c590() + " (Local)", 0, 0, -1);
		readout->animate("A_CHack_Text");
		y++;
		y++;
	}
	else if (command == "der_status")
	{
		Console *readout = new CText(this, Pos(2, y), "Status", 0, 0, -1);
		readout->animate("A_CHack_Header");
		y += 2;
		readout = new CText(this, Pos(2, y), "Accessing entry node...", 0, 0, -1);
		readout->animate("A_CHack_Text");
		y++;
		y++;
	}
	else if (command == "der_code")
	{
		int wd = getWidth_44b0d0() - 4;
		string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		int height = 9;
		int y0 = y;
		for (int i = 0; i < 9; i++)
		{
			string line;
			for (int j = 0; j < wd; j++)
				line += abc[rng.rangeInt(0, abc.size() - 1)];
			print(2, y, line);
			y++;
		}
		int effect;
		OpU8a_lookup1("Type_GR3_Vert_E", &effect);
		for (int x = 2; x <= getWidth_44b0d0() - 3; x++)
			engine->unknown50fb50(engine, effect, Pos(x, y0), d2k_d2e20c, &Pos(x, y - 1), &Pos(d2k_d2e20c), 9)->init_50de10();
		y++;
	}
	else if (command == "der_connected")
	{
		int wd = getWidth_44b0d0() - 4;
		int height = 9;
		int length = 12;
		int streak = 0;
		for (int ty = y - 10; ty < y - 1; ty++)
		{
			if (rng.chance(streak * 15 + 50))
			{
				int x = rng.rangeInt(1, wd - 12) + 2;
				string code = getString(Pos(x + 1, ty), 10);
				code.insert(code.begin(), ' ');
				code += ' ';
				Console *readout = new CText(this, Pos(x, ty), code, 0, 0, -1);
				readout->animate("A_CHack_Der_Highlight");
				streak = 0;
			}
			else
				streak++;
		}
		Console *readout = new CText(this, Pos(2, y), "Connection established...", 0, 0, -1);
		readout->animate("A_CHack_Text");
		y++;
		y++;
		new D2kMachineUI(d2k_cec034, machine);
	}
	else if (command == "lab_system")
	{
		Console *readout = new CText(this, Pos(2, y), "System", 0, 0, -1);
		readout->animate("A_CHack_Header");
		y += 2;
		readout = new CText(this, Pos(2, y), machine->name_45c590() + " (Local)", 0, 0, -1);
		readout->animate("A_CHack_Text");
		y++;
		y++;
	}
	else if (command == "lab_status")
	{
		Console *readout = new CText(this, Pos(2, y), "Status", 0, 0, -1);
		readout->animate("A_CHack_Header");
		y += 2;
		readout = new CText(this, Pos(2, y), "Establishing connection...", 0, 0, -1);
		readout->animate("A_CHack_Text");
		y++;
		readout = new CText(this, Pos(2, y), "Decrypting stream...", 0, 0, -1);
		readout->animate("A_CHack_Text");
		y++;
		if (stringToInt(d2k_d1e860.getEntryText("datDataConduitDownloaded_g")))
		{
			readout = new CText(this, Pos(2, y), "Found relevant data record, applying...", 0, 0, -1);
			readout->animate("A_CHack_Text");
			y++;
			if (machine->name_45c590() == "A0 Command")
			{
				d2k_d2c658.add472b90(0x3f, -999999);
				d2k_cf45d8.unknown77fbc0(0x19e);
			}
			do
			{
				opS2_logPhrase_5141b0(0x1ea, 0, 0, 0, D2kHEntity(), 0);
			} while (0);
		}
		else
		{
			do
			{
				opS2_logPhrase_5141b0(0x1eb, 0, 0, 0, D2kHEntity(), 0);
			} while (0);
		}
		y++;
	}
	else if (command == "lab_connected")
	{
		int wd = getWidth_44b0d0() - 4;
		int height = 9;
		Pos lengths(5, 9);
		int streak = 0;
		string highlightAnim = stringToInt(d2k_d1e860.getEntryText("datDataConduitDownloaded_g")) ? "A_CHack_Lab_HL_Okay" : "A_CHack_Lab_HL_Fail";
		for (int ty = y - 10; ty < y - 1; ty++)
		{
			if (rng.chance(streak * 15 + 50))
			{
				int count = lengths.randomInRange_40c130();
				int x = rng.rangeInt(0, wd - count) + 2;
				string code = getString(Pos(x, ty), count);
				Console *readout = new CText(this, Pos(x, ty), code, 0, 0, -1);
				readout->animate(highlightAnim);
				streak = 0;
			}
			else
				streak++;
		}
		Console *readout = new CText(this, Pos(2, y), stringToInt(d2k_d1e860.getEntryText("datDataConduitDownloaded_g")) ? "Decryption complete." : "Decryption failed.", 0, 0, -1);
		readout->animate("A_CHack_Text");
		y++;
		y++;
		new D2kMachineUI(d2k_cec034, machine);
	}
	else if (command == "ac0_status")
	{
		Console *readout = new CText(this, Pos(2, y), "Status", 0, 0, -1);
		readout->animate("A_CHack_Header");
		y += 2;
		readout = new CText(this, Pos(2, y), "Establishing connection...", 0, 0, -1);
		readout->animate("A_CHack_Text");
		y++;
		readout = new CText(this, Pos(2, y), "Brute forcing decryption...", 0, 0, -1);
		readout->animate("A_CHack_Text");
		y++;
		y++;
	}
	else if (command == "ac0_code")
	{
		int wd = getWidth_44b0d0() - 4;
		int height = 9;
		int effect;
		OpU8a_lookup1("CHack_AC0_StageA", &effect);
		for (int i = 0, ty = y; i < 9; i++, ty++, y++)
		{
			for (int x = 2; x <= getWidth_44b0d0() - 3; x++)
				engine->unknown50fb50(engine, effect, Pos(x, ty), d2k_d2e20c, 0, 0, 9)->init_50de10();
		}
		y++;
	}
	else if (command == "ac0_connected")
	{
		int wd = getWidth_44b0d0() - 4;
		int height = 9;
		int effect1;
		OpU8a_lookup1("CHack_AC0_StageB_1", &effect1);
		int effect0;
		OpU8a_lookup1("CHack_AC0_StageB_0", &effect0);
		for (int i = 0, ty = y - 10; i < 9; i++, ty++)
		{
			for (int x = 2; x <= getWidth_44b0d0() - 3; x++)
				engine->unknown50fb50(engine, getChar(x, ty) == '1' ? effect1 : effect0, Pos(x, ty), d2k_d2e20c, 0, 0, 9)->init_50de10();
		}
		Console *readout = new CText(this, Pos(2, y), "Decryption complete.", 0, 0, -1);
		readout->animate("A_CHack_Text");
		y++;
		y++;
		new D2kMachineUI(d2k_cec034, machine);
	}
	else if (command == "arc_status")
	{
		Console *readout = new CText(this, Pos(2, y), "Status", 0, 0, -1);
		readout->animate("A_CHack_Header");
		y += 2;
		readout = new CText(this, Pos(2, y), "Establishing connection...", 0, 0, -1);
		readout->animate("A_CHack_Text");
		y++;
		if (stringToInt(d2k_d1e860.getEntryText("zhirovInHideout_g")) || machine->getPosition_4184d0()->test_409cf0(0x19, 0x20))
		{
			readout = new CText(this, Pos(2, y), "Archive compromised, assessing...", 0, 0, -1);
			readout->animate("A_CHack_Text");
			y++;
			do
			{
				opS2_logPhrase_5141b0(0x1ae, 0, 0, 0, D2kHEntity(), 0);
			} while (0);
		}
		else
		{
			readout = new CText(this, Pos(2, y), "Archive under local attack...", 0, 0, -1);
			readout->animate("A_CHack_Text");
			y++;
			readout = new CText(this, Pos(2, y), "Reading partially decrypted memory...", 0, 0, -1);
			readout->animate("A_CHack_Text");
			y++;
			d2k_d2c658.add472b90(0x3c, -999999);
			do
			{
				opS2_logPhrase_5141b0(0x1ad, 0, 0, 0, D2kHEntity(), 0);
			} while (0);
		}
		y++;
	}
	else if (command == "arc_code")
	{
		int wd = getWidth_44b0d0() - 4;
		int height = 20;
		int effect;
		OpU8a_lookup1(stringToInt(d2k_d1e860.getEntryText("zhirovInHideout_g")) || machine->getPosition_4184d0()->test_409cf0(0x19, 0x20) ? "CHack_ARC_StageA" : "CHack_ARC_StageA2", &effect);
		for (int i = 0, ty = y; i < 20; i++, ty++, y++)
		{
			for (int x = 2; x <= getWidth_44b0d0() - 3; x++)
				engine->unknown50fb50(engine, effect, Pos(x, ty), d2k_d2e20c, 0, 0, 9)->init_50de10();
		}
		y++;
	}
	else if (command == "arc_connected")
	{
		int wd = getWidth_44b0d0() - 4;
		int height = 20;
		int effect;
		if (stringToInt(d2k_d1e860.getEntryText("zhirovInHideout_g")) || machine->getPosition_4184d0()->test_409cf0(0x19, 0x20))
		{
			OpU8a_lookup1("A_CHack_ARC_StageB", &effect);
			Pos lengths(5, 12);
			for (int ty = y - 21; ty < y - 1; ty++)
			{
				for (int n = rng.rangeInt(5, 7); n > 0; n--)
				{
					int count = lengths.randomInRange_40c130();
					int x = rng.rangeInt(0, wd - count) + 2;
					string code = getString(Pos(x, ty), count);
					Console *readout = new CText(this, Pos(x, ty), code, 0, 0, -1);
					readout->unknown48c3c0(effect);
				}
			}
			Console *readout = new CText(this, Pos(2, y), "Data damaged beyond repair.", 0, 0, -1);
			readout->animate("A_CHack_Text");
			y++;
		}
		else
		{
			OpU8a_lookup1("CHack_ARC_StageB2", &effect);
			for (int ty = y - 21; ty < y - 1; ty++)
			{
				for (int x = 2; x <= getWidth_44b0d0() - 3; x++)
					engine->unknown50fb50(engine, effect, Pos(x, ty), d2k_d2e20c, 0, 0, 9)->init_50de10();
			}
			Console *readout = new CText(this, Pos(2, y), "Stream ended.", 0, 0, -1);
			readout->animate("A_CHack_Text");
			y++;
		}
		y++;
		new D2kMachineUI(d2k_cec034, machine);
	}
	else if (command == "zhack_system")
	{
		Console *readout = new CText(this, Pos(2, y), "System", 0, 0, -1);
		readout->animate("A_CHack_Header");
		y += 2;
		readout = new CText(this, Pos(2, y), machine->name_45c590(), 0, 0, -1);
		readout->animate("A_CHack_Text");
		y++;
		y++;
	}
	else if (command == "zhack_inject")
	{
		Console *readout = new CText(this, Pos(2, y), "Status", 0, 0, -1);
		readout->animate("A_CHack_Header");
		y += 2;
		int count = getHeight() - 6 - y;
		Console *panel = new Console(this, getWidth_44b0d0() - 4, count, 2, y, 0, false, -1);
		panel->animate("A_CHack_ZHack_Dots");
		bool line = false;
		for (int i = 0; i < count; i++, y++)
		{
			if (rng.chance(line ? 66 : 50))
			{
				panel = new Console(this, rng.rangeInt(6, getWidth_44b0d0() - 4), 1, 2, y, 0, false, -1);
				panel->animate("A_CHack_ZHack_Line");
				panel->resetBack_418450();
				line = true;
			}
			else
				line = false;
		}
		y++;
	}
	else if (command == "zhack_override")
	{
		Console *readout = new CText(this, Pos(2, y), " SYSTEM OVERRIDE ", 0, 0, -1);
		readout->animate("A_CHack_ZHack_Override");
		new D2kMachineUI(d2k_cec034, machine);
	}
}
