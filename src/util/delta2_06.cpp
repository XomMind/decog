// CHack::unknown940ad0 (exe 0x940ad0): applies a hacking result (lock/overload/scramble, trace detection,
// feedback, machine lockout). Returns true when the machine locked.
// NOTE: class is declared here as D2Hack (placeholder name); layouts are partial, names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_);	// 0x46ca20
};

struct D2hPoint { int x; int y; };

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

	Pos getPos();
	int getWidth_44b0d0();

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	virtual ~Console();
	virtual void render();
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);
	void unknown48c3c0(int value);	// NOTE: placeholder name

	int unknown60;
	void *engine;
	void *title;
};

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);
	char pad6c[0x88 - 0x6c];
};

class D2Hack;

class CHackTrace : public Console
{
public:
	CHackTrace(D2Hack *hack, int y);
	void setPercent(int percent);
	char pad6c[0x74 - 0x6c];
};

struct D2hInfo { char pad[0xf8]; int type; };	// NOTE: placeholder layout
struct D2hData { char pad00[0xc]; int security; char pad10[0x28 - 0x10]; int unknown28; int unknown2c; };	// NOTE: placeholder layout

class D2hMachine	// NOTE: placeholder name (machine prop)
{
public:
	D2hInfo *getInfo_9b8f00();
	D2hData *getData_45cb30();
	int getValue_457b10();
	void setValue_452270(int value);
	const D2hPoint *getPosition_4184d0();
};

class HProp
{
public:
	int ID;
	D2hMachine *operator->() const;	// 0x9b64f0
};

class D2hItem
{
public:
	int unknown457f90();
	bool unknown457cf0();
	string getName(int a, int b);	// 0x571db0
	void remove57dbe0(int a, int b, int c, int d);
};

class HItem
{
public:
	int ID;
	bool isValid() const;
	D2hItem *operator->() const;	// 0x9b65b0
};

class D2hEntity
{
public:
	int unknown5c7f40();
	HItem unknown5d2c50();
	vector<HItem> *getInventoryList();
	void unknown5defa0(int a, bool b);
};

class HEntity
{
public:
	int ID;
	HEntity() throw();
	D2hEntity *operator->() const;
};

class D2hMap { public: HEntity getPlayer(); };
extern D2hMap *d2h_cefc4c;

class D2hLocation { public: int unknown0; int type; };
class HLocation { public: int ID; D2hLocation *operator->() const; };
extern HLocation d2h_d1e888;

class D2hMachines { public: void unknown8fe7f0(int result); };	// NOTE: placeholder name (CMachine at 0xcec0fc)
extern D2hMachines *d2h_cec0fc;

class D2hShell	// NOTE: placeholder name (CShell at 0xcec100)
{
public:
	vector<int> *unknown463a70();
	void unknown90ec30(string text);
};
extern D2hShell *d2h_cec100;

class D2hOvermind
{
public:
	void unknown682770(int a, int b);
	void unknown68c960(const D2hPoint *pos);
	int dispatch684250(const D2hPoint *pos, int flag);
};
extern D2hOvermind d2h_cf6428;

class D2hGameData
{
public:
	const string &getEntryText(const string &key);
	int unknown46f4e0();
};
extern D2hGameData d2h_d1e860;

class D2hStats { public: bool add4729d0(unsigned int id, int value, string text, int extra); };
extern D2hStats d2h_d2c658;
class D2hFlag { public: void set451400(int value); };
extern D2hFlag d2h_cf1080;
class D2hPlayerData { public: void unknown77fbc0(int id); };
extern D2hPlayerData d2h_cf45d8;
class D2hUI { public: void bubble8758d0(bool flag); };
extern D2hUI *d2h_cec058;
class D2hLog { public: void scrollToEnd_7b4f10(); };
extern D2hLog *d2h_cec0b4;
struct D2hDebug { int unknown0; int unknown4; };
extern D2hDebug *d2h_cec024;
struct D2hDispatch { int unknown0; int chance; };
extern D2hDispatch d2h_b936e0[];

class RNG { public: bool chance(int percent); };
extern RNG rng;

extern string d2h_d01740[];
extern int d2h_b9b988[], d2h_b9ba14[], d2h_b9ba24[];
extern int d2h_cebdbc;
extern bool d2h_cefb3e;
extern const char empty_b9989e[], empty_b9989f[], empty_b998ae[], empty_b998af[], empty_b998be[], empty_b998bf[], empty_b998ce[], empty_b998cf[];

int stringToInt(const string &text);
int OpX5_maxInt(int a, int b);
void OpV4c_Fn9d06d0(int *value, int amount, int max);
bool OpT8b_Fn9daf80(int lo, int v, int hi);
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);
bool opS2_showMessage_5111e0(int id, string *a, string *b, string *c, HEntity subject, HEntity object, const D2hPoint *at, bool log);
bool opS2_logPhrase_5141b0(int id, const string *a, const string *b, const string *c, HEntity subject, const D2hPoint *at);

class D2Hack : public Console
{
public:
	virtual bool input(void *event);
	virtual void close();

	bool unknown4b1480();	// NOTE: placeholder name
	void unknown942780(int x);	// NOTE: placeholder name
	bool unknown940ad0(int a, int b, int result);	// NOTE: placeholder name

	bool unknown6c;
	int unknown70;
	void *closeButton;
	bool unknown78;
	int y;
	HProp machine;
	int chance;
	int percent;
	XConsole *label;
	CHackTrace *trace;
};

bool D2Hack::unknown940ad0(int a, int b, int result)
{
	if (machine->getInfo_9b8f00()->type >= 6)
		return false;
	switch (result)
	{
	case 2:
	{
		machine->getData_45cb30()->unknown28 = -1;
		d2h_cec0fc->unknown8fe7f0(result);
		y += 2;
		CText *text = new CText(this, Pos(2, y), " " + d2h_d01740[machine->getInfo_9b8f00()->type] + " SHUTDOWN ", 0, 0, -1);
		text->animate("A_CHack_Locked");
		return false;
	}
	case 3:
	{
		if (d2h_d1e888->type == 10)
			d2h_cf6428.unknown682770(0x1a, 0);
		else
		{
			int value = machine->getValue_457b10();
			if (d2h_cec100->unknown463a70()->back() == 0x6e)
				machine->setValue_452270(1);
			if (d2h_d1e888->type == 13)
				d2h_cf6428.unknown68c960(machine->getPosition_4184d0());
			else
				d2h_cf6428.dispatch684250(machine->getPosition_4184d0(), 0);
			machine->setValue_452270(value);
		}
		machine->getData_45cb30()->unknown28 = -1;
		d2h_cec0fc->unknown8fe7f0(result);
		y += 2;
		CText *text = new CText(this, Pos(2, y), " " + d2h_d01740[machine->getInfo_9b8f00()->type] + " OVERLOADED ", 0, 0, -1);
		text->animate("A_CHack_Locked");
		text->unknown48c3c0(d2h_cebdbc);
		return false;
	}
	case 4:
	{
		machine->getData_45cb30()->unknown28 = -1;
		d2h_cec0fc->unknown8fe7f0(result);
		y += 2;
		CText *text = new CText(this, Pos(2, y), " " + d2h_d01740[machine->getInfo_9b8f00()->type] + " SCRAMBLED ", 0, 0, -1);
		text->animate("A_CHack_Locked");
		return false;
	}
	case 5:
		return false;
	}
	if (machine->getData_45cb30()->security == 0)
		return false;
	if (!unknown4b1480())
	{
		int prev = chance;
		if (result == 1)
			chance = 100;
		if (b > a)
		{
			int increase = OpX5_maxInt(0, b - a - (d2h_cefc4c->getPlayer()->unknown5c7f40() + d2h_b9b988[stringToInt(d2h_d1e860.getEntryText("hubNetworkHubDisabled_g"))])) / 2;
			OpV4c_Fn9d06d0(&chance, increase, 100);
			machine->getData_45cb30()->unknown2c += increase;
			if (d2h_cefb3e)
				d2h_cec024->unknown4 = chance;
		}
		if (chance != prev)
			unknown942780(label->getPos().x);
		if (!rng.chance(chance))
			return false;
		chance = -1;
		d2h_d2c658.add4729d0(0x2f6, 1, empty_b9989e, -1);
		CText *text = new CText(this, Pos(label->getPos().x + label->getWidth_44b0d0() + 1, y), " DETECTED ", 0, 0, -1);
		text->animate("A_CHack_Label_Detected");
		y += 2;
		text = new CText(this, Pos(2, y), "Estimated Trace Progress", 0, 0, -1);
		text->animate("A_CHack_Text");
		y += 1;
		trace = new CHackTrace(this, y);
		y += 2;
		if (b <= a)
			percent = 0;
		else
			percent = b - a;
		trace->setPercent(percent);
	}
	else
	{
		if (result == 1)
			percent = 100;
		else if (b <= a)
			percent += OpX5_maxInt(15, 50 - (d2h_cefc4c->getPlayer()->unknown5c7f40() + d2h_b9b988[stringToInt(d2h_d1e860.getEntryText("hubNetworkHubDisabled_g"))]));
		else
			percent += OpX5_maxInt(25, 50 - (d2h_cefc4c->getPlayer()->unknown5c7f40() + d2h_b9b988[stringToInt(d2h_d1e860.getEntryText("hubNetworkHubDisabled_g"))]) + (b - a) / 3);
		if (percent > 100)
			percent = 100;
		trace->setPercent(percent);
	}
	if (percent >= 100)
	{
		d2h_d2c658.add4729d0(0x2f7, 1, empty_b9989f, -1);
		machine->getData_45cb30()->unknown28 = -1;
		d2h_cec0fc->unknown8fe7f0(result);
		CText *caption = NULL;
		string name;
		bool hit = false;
		if (result != 1)
		{
			if (rng.chance(d2h_b9ba14[machine->getData_45cb30()->security]))
			{
				HItem item = d2h_cefc4c->getPlayer()->unknown5d2c50();
				if (item.isValid())
				{
					d2h_d2c658.add4729d0(0x2fb, 1, empty_b998ae, -1);
					name = item->getName(0, 0);
				}
				else
				{
					d2h_d2c658.add4729d0(0x2f8, 1, empty_b998af, -1);
					d2h_d2c658.add4729d0(0x2f9, 1, empty_b998be, -1);
					hit = true;
					string message = "Feedback: System corruption (+1%)";
					caption = new CText(this, Pos(2, y), message, 0, 0, -1);
					caption->animate("A_CHack_Feedback");
					y += 1;
					message += ".";
					do
					{
						if (opS2_showMessage_5111e0(0x201, &message, 0, 0, HEntity(), HEntity(), machine->getPosition_4184d0(), false))
							d2h_cec058->bubble8758d0(true);
						d2h_cec0b4->scrollToEnd_7b4f10();
					} while (0);
					d2h_cec100->unknown90ec30(message);
					d2h_cefc4c->getPlayer()->unknown5defa0(1, false);
				}
			}
			vector<HItem> *inventory = d2h_cefc4c->getPlayer()->getInventoryList();
			for (unsigned int i = 0; i < inventory->size(); i++)
			{
				if (OpT8b_Fn9daf80(0x79, (*inventory)[i]->unknown457f90(), 0x7a) && (*inventory)[i]->unknown457cf0() && rng.chance(d2h_b9ba24[machine->getData_45cb30()->security]))
				{
					HItem item = d2h_cefc4c->getPlayer()->unknown5d2c50();
					if (item.isValid())
					{
						d2h_d2c658.add4729d0(0x2fb, 1, empty_b998bf, -1);
						name = item->getName(0, 0);
					}
					else
					{
						d2h_d2c658.add4729d0(0x2f8, 1, empty_b998ce, -1);
						d2h_d2c658.add4729d0(0x2fa, 1, empty_b998cf, -1);
						string message = "Feedback: " + (*inventory)[i]->getName(0, 0) + " fried";
						do
						{
							opS2_logPhrase_5141b0(0x84, &(*inventory)[i]->getName(0, 0), 0, 0, HEntity(), 0);
						} while (0);
						(*inventory)[i]->remove57dbe0(1, 1, 1, 1);
						hit = true;
						caption = new CText(this, Pos(2, y), message, 0, 0, -1);
						caption->animate("A_CHack_Feedback");
						message += ".";
						do
						{
							if (opS2_showMessage_5111e0(0x201, &message, 0, 0, HEntity(), HEntity(), machine->getPosition_4184d0(), false))
								d2h_cec058->bubble8758d0(true);
							d2h_cec0b4->scrollToEnd_7b4f10();
						} while (0);
						d2h_cec100->unknown90ec30(message);
						y += 1;
						i--;
					}
				}
			}
		}
		if (hit)
			animate("A_CHack_FeedbackSnd");
		if (!name.empty())
		{
			string message = (hit ? "Additional hit blocked by " : "Feedback blocked by ") + name;
			caption = new CText(this, Pos(2, y), message, 0, 0, -1);
			caption->animate("A_CHack_FeedbackBlocked");
			message += ".";
			do
			{
				if (opS2_showMessage_5111e0(0x201, &message, 0, 0, HEntity(), HEntity(), machine->getPosition_4184d0(), false))
					d2h_cec058->bubble8758d0(true);
				d2h_cec0b4->scrollToEnd_7b4f10();
			} while (0);
			d2h_cec100->unknown90ec30(message);
			y += 1;
		}
		if (caption != NULL)
			y += 1;
		caption = new CText(this, Pos(2, y), " " + d2h_d01740[machine->getInfo_9b8f00()->type] + " LOCKED ", 0, 0, -1);
		caption->animate("A_CHack_Locked");
		if (result == 1)
		{
			if (d2h_cf6428.dispatch684250(machine->getPosition_4184d0(), 1))
			{
				string message = "ALERT: Unauthorized use of fabrication network. Dispatching investigation squad.";
				do
				{
					d2h_cf1080.set451400(1);
					if (0)
						opR1d_4541b0(-1, 0, 0);
					do
					{
						if (opS2_showMessage_5111e0(0x324, &message, 0, 0, HEntity(), HEntity(), 0, false))
							d2h_cec058->bubble8758d0(true);
						d2h_cec0b4->scrollToEnd_7b4f10();
					} while (0);
					d2h_cec0b4->scrollToEnd_7b4f10();
				} while (0);
				d2h_cec100->unknown90ec30(message);
			}
		}
		else
		{
			switch (d2h_d1e888->type)
			{
			case 10:
				d2h_cf6428.unknown682770(0x1a, 0);
				break;
			case 13:
				d2h_cf6428.unknown68c960(machine->getPosition_4184d0());
				break;
			default:
				if (rng.chance(d2h_b936e0[d2h_d1e860.unknown46f4e0()].chance))
				{
					d2h_cf6428.dispatch684250(machine->getPosition_4184d0(), 0);
					d2h_cf45d8.unknown77fbc0(0x40);
				}
			}
		}
		return true;
	}
	else
		return false;
}
