// CEvolve::CEvolve (exe 0x98c180): evolution screen constructor (slot allocation, stats, circuits art).
// NOTE: class is declared here as D2Evolve (placeholder name) so this TU's vtable/dtor COMDATs do not
//	collide with other partial CEvolve declarations; layouts are partial, names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos();	// 0x40a6e0
	Pos(int v);	// 0x409990
	Pos &operator=(const Pos &pos);	// 0x40a720
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

	void setHidden(bool hidden_);
	void resetBack_418450() throw();

	char pad04[0x60 - 0x04];
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

	int unknown60;
	void *engine;
	void *title;
};

class ConsoleArt : public Console
{
public:
	ConsoleArt(XConsole *parent, const string &file, int x, int y, bool hidden, int layer, int frame, const Pos &offset_, int width, int height);
	char pad6c[0x84 - 0x6c];
};

class D2eItem
{
public:
	int getType();
	int getEffect(int type);
	int unknown4578a0();	// NOTE: placeholder name
	int unknown4578c0();	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	bool isValid() const;
	D2eItem *operator->() const;
};

class HProp
{
public:
	int ID;
	bool isNull() const;
	D2eItem *operator->() const;
};

class D2ePart	// NOTE: placeholder name (CParts entry)
{
public:
	HItem item4b1b30();	// NOTE: placeholder name
	HProp target4b1b50();	// NOTE: placeholder name
	int slot416230();	// NOTE: placeholder name
	void unknown49ac50();	// NOTE: placeholder name
};

class D2eParts	// NOTE: placeholder name (0xcec088)
{
public:
	vector<D2ePart*> *list4a9ad0();
};
extern D2eParts *d2e_cec088;

class D2eEntity
{
public:
	HItem unknown5d2380(int type);
	vector<HItem> *getInventoryList();
	int *unknown45a840();
	int getSlotTotal();
	int unknown5c92e0(int type);
	int unknown5ca210() throw();
	int unknown5c8e20(int type) throw();
	void unknown45b100(int *slots);
	int unknown45a880();
	void unknown45b150(int amount);
	void unknown5de800();
};

class HEntity
{
public:
	int ID;
	HEntity() throw();
	D2eEntity *operator->() const throw();
};

class D2eMap	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer() throw();
	bool unknown4641b0();
	bool unknown4641d0();
	bool unknown4641f0();
	bool unknown464210();
	bool unknown464230();
	bool unknown464250();
};
extern D2eMap *d2e_cefc4c;

class D2eLocation	// NOTE: placeholder name
{
public:
	int unknown0;
	int type;
	int unknown8;
	int unknown46ed20();	// NOTE: placeholder name
};

class HLocation	// NOTE: placeholder name
{
public:
	int ID;
	D2eLocation *operator->() const;
};
extern HLocation d2e_d1e888;
extern vector<HLocation> d2e_d1e88c;

class D2eRex
{
public:
	XConsole *getHighlighter_4ab670();
	int unknown418980();
	int unknown4189a0();
};
extern D2eRex d2e_d223f0;

class D2eMixer { public: void haltAll(); };
extern D2eMixer *d2e_cefa90;
class D2eSound { public: void unknown4544e0(); void unknown5003b0(); };
extern D2eSound d2e_d2d2a0;
extern XConsole *d2e_cec034;
class D2eGraph { public: void pushFrame(int a, XConsole *console, int c, bool d); };
extern D2eGraph *d2e_cefa8c;
class D2eCMap { public: void unknown8142d0(unsigned int a, bool b); };
extern D2eCMap *d2e_cec054;
struct D2ePoint { int x; int y; };
extern vector<D2ePoint> d2e_d2ec1c;
extern vector<Console*> d2e_cfc20c;
class D2eEnd { public: int unknown96cc00(); };
extern D2eEnd *d2e_cec138;
class D2eUI { public: void bubble8758d0(bool flag); };
extern D2eUI *d2e_cec058;
class D2eLog { public: void scrollToEnd_7b4f10(); };
extern D2eLog *d2e_cec0b4;
class D2ePlayerData
{
public:
	void unknown77fbc0(int id);
	bool isSlotEmpty(unsigned int index);
	bool isTypeAllowed(int type);
};
extern D2ePlayerData d2e_cf45d8;
class D2eTally { public: void unknown6998a0(unsigned int index, int amount, bool set); };
extern D2eTally d2e_cf6888;
class D2eStats
{
public:
	vector<int> *current;
	bool add4729d0(unsigned int id, int value, string text, int extra);
	void add472b90(unsigned int id, int value);
	int unknown472c70(int id);
};
extern D2eStats d2e_d2c658;
class D2eBuilder	// NOTE: placeholder name (0xd25450)
{
public:
	bool active;
	char pad01[0x118 - 0x01];
	int unknown118;
	int unknown11c;
	HItem findXom();
};
extern D2eBuilder d2e_d25450;
class D2eGM { public: void unknown793690(); };
extern D2eGM *d2e_cefaa8;
struct D2eRecord { char pad[0x4c]; int unknown4c; };
extern vector<D2eRecord*> d2e_d389c4;

template <class T> class OpR5h_WL	// NOTE: placeholder name (weighted list)
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL(const int *w, int count);	// 0x9ba790
	T &pick();	// 0x9ba470
};

extern int d2e_cf4718, d2e_cf471c, d2e_cf4728, d2e_cf462c, d2e_cf4748, d2e_d1e8bc, d2e_cf4624, d2e_d1eb10;
extern int d2e_cf4720, d2e_cf4724, d2e_cf472c, d2e_cf4730, d2e_cf4734, d2e_cf4738, d2e_cf473c, d2e_cf4740;
extern int d2e_cf4954, d2e_cf49dc, d2e_cf4ba4, d2e_cf4ba8, d2e_cf4bac, d2e_cf4bb0;
extern int d2e_d338c0, d2e_d338c4;
extern bool d2e_cf4d17;
extern float d2e_cf46f8;
extern const float d2e_ba853c, d2e_ba682c, d2e_ba6840;
extern string d2e_d378d0[];
extern string d2e_d29018[];
extern const int d2e_b95a1c[], d2e_b95a2c[];
extern Pos d2e_d21db0;
extern const char empty_b99c05[], empty_b99c06[], empty_b99c07[];

void OpX5_fillInts(int *p, unsigned int count, int value);
void OpS8c_copyInts(int *src, int *dst, unsigned int count);
D2ePart *d2e_popRandom(vector<D2ePart*> &v);
int OpU8b_removeAll(vector<int> &v, int value);
void OpS8d_appendInts(vector<int> &v, int *values, unsigned int count);
void OpC_clampMin(int *v, int m);
bool opS2_showMessage_5111e0(int id, string *a, string *b, string *c, HEntity subject, HEntity object, const D2ePoint *at, bool log);
bool opS2_logPhrase_5141b0(int id, const string *a, const string *b, const string *c, HEntity subject, const D2ePoint *at);
int opr1c_scaleRepeated(int value, int count, float factor);
void opw8_unknown789ac0();
string intToString(int value);

class D2Evolve : public Console
{
public:
	D2Evolve(int count, HLocation location, bool flag);
	virtual bool input(void *event);
	virtual void close();

	unsigned int unknown98c130();	// NOTE: placeholder name

	HLocation location;
	int count;
	int unknown74;
	bool unknown78;
	void *unknown7c;
	int unknown80[4];
	int unknown90[4];
	Pos unknowna0;
	char pada8[0xb0 - 0xa8];
	ConsoleArt *art;
	char padb4[0xb8 - 0xb4];
	Pos unknownb8;
	char padc0[0xc8 - 0xc0];
	unsigned int unknownc8;
	bool unknowncc;
	bool flag;
};
extern D2Evolve *d2e_cec140;

D2Evolve::D2Evolve(int count, HLocation location, bool flag)
	: Console(d2e_d223f0.getHighlighter_4ab670(), d2e_d223f0.unknown418980() / 2, d2e_d223f0.unknown4189a0(), 0, 0, 2, false, -1),
	location(location), count(count), unknown78(false), unknown7c(NULL), art(NULL), unknownc8(unknown98c130()), unknowncc(false), flag(flag)
{
	d2e_cec140 = this;
	d2e_cefa90->haltAll();
	d2e_d2d2a0.unknown4544e0();
	d2e_d2d2a0.unknown5003b0();
	d2e_cec034->setHidden(true);
	d2e_cefa8c->pushFrame(0x21, this, -1, false);
	d2e_cec054->unknown8142d0(0x12, false);
	d2e_d2ec1c.clear();
	d2e_cfc20c.clear();
	d2e_cec138->unknown96cc00();
	unknown60 = 3;
	unknown74 = d2e_d1e888->type == 1 && d2e_cf4718 == 2 ? 1 : (d2e_cf471c ? this->count * -1 : (d2e_cf4728 ? this->count : this->count * 2));
	if (this->flag)
	{
		unknown74 = this->count * 2;
		if (unknown74 != 0)
			d2e_d1e8bc = this->location->unknown8;
	}
	if (d2e_cf462c == 5 || d2e_cf462c == 11)
		unknown74 = 0;
	if (unknown74 < 0 || (unknown74 != 0 && d2e_cf4748 != 0) || d2e_cefc4c->getPlayer()->unknown5d2380(0xbf).isValid())
	{
		OpX5_fillInts(unknown80, 4, 0);
		vector<HItem> *inventory = d2e_cefc4c->getPlayer()->getInventoryList();
		for (unsigned int i = 0; i < inventory->size(); i++)
		{
			if ((*inventory)[i]->getType() <= 3 && (*inventory)[i]->getEffect(0x6c))
				unknown80[(*inventory)[i]->unknown4578a0()] += (*inventory)[i]->unknown4578c0();
		}
		for (int i = 0; i < 4; i++)
			OpC_clampMin(&unknown80[i], 1);
		vector<D2ePart*> *parts = d2e_cec088->list4a9ad0();
		for (unsigned int i = 0; i < parts->size(); i++)
		{
			if ((*parts)[i]->item4b1b30().isValid())
			{
				if ((*parts)[i]->target4b1b50().isNull() || !(*parts)[i]->target4b1b50()->getEffect(0x6c))
					unknown80[(*parts)[i]->slot416230()]++;
			}
		}
	}
	else
		OpS8c_copyInts(d2e_cefc4c->getPlayer()->unknown45a840(), unknown80, 4);
	OpX5_fillInts(unknown90, 4, 0);
	if (d2e_cefc4c->getPlayer()->getSlotTotal() + unknown74 > 26)
	{
		int old = unknown74;
		unknown74 = 26 - d2e_cefc4c->getPlayer()->getSlotTotal();
		int lost = old - unknown74;
		vector<int> lostSlots;
		if (lost > 0)
		{
			vector<D2ePart*> candidates;
			vector<D2ePart*> *parts = d2e_cec088->list4a9ad0();
			for (unsigned int i = 0; i < parts->size(); i++)
			{
				if ((*parts)[i]->item4b1b30().isValid())
					candidates.push_back((*parts)[i]);
			}
			while (lost != 0 && !candidates.empty())
			{
				D2ePart *part = d2e_popRandom(candidates);
				part->unknown49ac50();
				lost--;
				lostSlots.push_back(part->slot416230());
				do
				{
					if (opS2_showMessage_5111e0(0x128, &d2e_d378d0[part->slot416230()], 0, 0, HEntity(), HEntity(), 0, false))
						d2e_cec058->bubble8758d0(true);
					d2e_cec0b4->scrollToEnd_7b4f10();
				} while (0);
			}
		}
		if (d2e_d25450.active && d2e_d25450.unknown118 && lost > 0)
		{
			do
			{
				d2e_d25450.unknown118--;
				lost--;
				lostSlots.push_back(3);
				do
				{
					if (opS2_showMessage_5111e0(0x128, &d2e_d378d0[3], 0, 0, HEntity(), HEntity(), 0, false))
						d2e_cec058->bubble8758d0(true);
					d2e_cec0b4->scrollToEnd_7b4f10();
				} while (0);
			} while (d2e_d25450.unknown118 && lost);
			if (!d2e_d25450.unknown118)
				d2e_d25450.unknown11c = 0;
		}
		if (!lostSlots.empty())
		{
			string text = lostSlots.size() > 1 ? "Temporary slots" : "Temporary slot";
			text += " became permanent: ";
			int n = 0;
			do
			{
				if (++n > 1)
					text += ", ";
				int slot = lostSlots.front();
				int entries = OpU8b_removeAll(lostSlots, slot);
				text += d2e_d378d0[slot];
				if (entries > 1)
					text += " x" + intToString(entries);
			} while (!lostSlots.empty());
			for (unsigned int i = 0; i < lostSlots.size(); i++)
			{
				int slot = lostSlots[i];
				int entries = OpU8b_removeAll(lostSlots, lostSlots[i]);
				text += d2e_d378d0[slot];
				i -= entries;
			}
			do
			{
				opS2_logPhrase_5141b0(5, &text, 0, 0, HEntity(), 0);
			} while (0);
		}
	}
	d2e_cf4624 = (int)(100.0 - (double)d2e_cefc4c->getPlayer()->unknown5c92e0(4) / d2e_cefc4c->getPlayer()->getSlotTotal() * 100.0);
	d2e_d2c658.add4729d0(0xc9, d2e_cefc4c->getPlayer()->unknown5ca210(), empty_b99c05, -1);
	d2e_d2c658.add4729d0(0xca, d2e_cefc4c->getPlayer()->unknown5c8e20(0), empty_b99c06, -1);
	switch (d2e_d1e888->type)
	{
	case 11:
		if (d2e_d1eb10)
			d2e_cf45d8.unknown77fbc0(0x17c);
		if (d2e_d25450.active && d2e_d25450.findXom().isValid())
			d2e_cf45d8.unknown77fbc0(0x14c);
		break;
	case 12:
		if (d2e_cf45d8.isSlotEmpty(0x12f) && d2e_d1e88c.size() >= 2)
		{
			for (unsigned int i = d2e_d1e88c.size() - 2; i != 0; i--)
			{
				if (d2e_d1e88c[i]->type == 12)
				{
					d2e_cf45d8.unknown77fbc0(0x12f);
					break;
				}
			}
		}
		break;
	case 13:
		if (d2e_cf45d8.isSlotEmpty(0x13c) && d2e_d1e88c.size() >= 2)
		{
			for (unsigned int i = d2e_d1e88c.size() - 2; i != 0; i--)
			{
				if (d2e_d1e88c[i]->type == 13 && d2e_d1e88c[i]->unknown8 == d2e_d1e888->unknown8)
				{
					d2e_cf45d8.unknown77fbc0(0x13c);
					break;
				}
			}
		}
		break;
	case 27:
		if ((*d2e_d2c658.current)[0x25f] >= 4)
		{
			d2e_cf45d8.unknown77fbc0(0x15e);
			d2e_cf6888.unknown6998a0(0xd, 1, false);
		}
		break;
	}
	if (d2e_cefc4c->unknown4641b0())
		d2e_cf45d8.unknown77fbc0(0x130);
	if (d2e_cefc4c->unknown4641d0())
		d2e_cf45d8.unknown77fbc0(0x13d);
	if (d2e_cefc4c->unknown4641f0())
		d2e_cf45d8.unknown77fbc0(0x158);
	if (d2e_cefc4c->unknown464210())
		d2e_cf45d8.unknown77fbc0(0x163);
	if (d2e_cefc4c->unknown464230())
		d2e_cf45d8.unknown77fbc0(0x16e);
	if (d2e_cefc4c->unknown464250())
		d2e_cf45d8.unknown77fbc0(0x18c);
	if (d2e_cf4d17)
	{
		vector<HItem> *inventory = d2e_cefc4c->getPlayer()->getInventoryList();
		for (unsigned int i = 0; i < inventory->size(); i++)
		{
			if ((*inventory)[i]->getType() <= 3)
			{
				d2e_cf4d17 = false;
				break;
			}
		}
	}
	if (d2e_cf471c && this->location->unknown8 != d2e_d1e888->unknown8)
	{
		int bonus = (this->location->unknown46ed20() - 5) * d2e_d389c4[7]->unknown4c;
		d2e_d2c658.add472b90(7, bonus);
	}
	if (unknown74 < 0)
	{
		int count = d2e_cefc4c->getPlayer()->getSlotTotal();
		int targets[4];
		OpX5_fillInts(targets, 4, 0);
		OpR5h_WL<int> pool(d2e_b95a1c, 4);
		vector<int> list;
		OpS8d_appendInts(list, d2e_cefc4c->getPlayer()->unknown45a840(), 4);
		vector<D2ePart*> *items = d2e_cec088->list4a9ad0();
		for (unsigned int i = 0; i < items->size(); i++)
		{
			if ((*items)[i]->item4b1b30().isValid())
				list[(*items)[i]->slot416230()]--;
		}
		while (unknown74 != 0)
		{
			int type = pool.pick();
			if (list[type] + targets[type] > 1)
			{
				targets[type]--;
				unknown74++;
			}
		}
		d2e_cefc4c->getPlayer()->unknown45b100(targets);
		OpS8c_copyInts(targets, unknown90, 4);
		unknown78 = true;
	}
	if (d2e_cf462c == 11)
	{
		d2e_cf46f8 = d2e_ba853c;
		d2e_cefaa8->unknown793690();
		opw8_unknown789ac0();
	}
	if (unknown74 != 0 && d2e_cf4748 != 0)
	{
		int targets[4];
		OpX5_fillInts(targets, 4, 0);
		OpR5h_WL<int> pool(d2e_b95a2c, 4);
		while (unknown74 != 0)
		{
			targets[pool.pick()]++;
			d2e_d2c658.add472b90(0x12, -999999);
			unknown74--;
		}
		d2e_cefc4c->getPlayer()->unknown45b100(targets);
		OpS8c_copyInts(targets, unknown90, 4);
		unknown78 = true;
	}
	if (unknown74 != 0)
	{
		animate("A_CEvolve_Bkg");
		unknowna0 = d2e_d21db0;
		unknowna0.x += (d2e_d223f0.unknown418980() - 160) / 2 / 2;
		unknowna0.y += (d2e_d223f0.unknown4189a0() - 60) / 2;
		art = new ConsoleArt(this, string() + "data/art/" + "evolve_circuits", unknowna0.x + d2e_d338c0, unknowna0.y + d2e_d338c4, false, 10, 0, Pos(-1), 0, 0);
		art->resetBack_418450();
		for (int i = 0; i < 4; i++)
		{
			string anim = "A_CEvolve_Circuits_In_";
			anim += d2e_d29018[i][0];
			art->animate(anim);
		}
	}
	else
		unknown78 = true;
	if (this->count != 0 && (d2e_d1e888->type != 1 || this->flag))
	{
		HEntity player = d2e_cefc4c->getPlayer();
		if (player->unknown45a880() < 10)
			d2e_cf45d8.unknown77fbc0(2);
		if (!d2e_cf471c && d2e_cf462c != 5)
		{
			int amount = this->count * 150;
			d2e_cf4954 += amount;
			player->unknown45b150(amount);
			d2e_cf49dc += this->count * 3;
		}
		d2e_cf4ba4 = 0;
		d2e_cf4ba8 = 0;
		d2e_cf4bac = 0;
		d2e_cf4bb0 = 0;
		player->unknown5de800();
		d2e_d2c658.add4729d0(0, this->count, empty_b99c07, -1);
		if (d2e_cf4720)
			d2e_d2c658.add472b90(8, -999999);
		if (d2e_cf4724)
			d2e_d2c658.add472b90(9, -999999);
		if (d2e_cf4728)
		{
			for (int i = 0; i < this->count; i++)
				d2e_d2c658.add472b90(10, -999999);
		}
		if (d2e_cf472c)
			d2e_d2c658.add472b90(11, -999999);
		if (d2e_cf4730)
			d2e_d2c658.add472b90(12, -999999);
		if (d2e_cf4734)
			d2e_d2c658.add472b90(13, -999999);
		if (d2e_cf4738)
			d2e_d2c658.add472b90(14, opr1c_scaleRepeated(d2e_d389c4[14]->unknown4c, d2e_d1e888->unknown46ed20() + 1, d2e_ba682c));
		if (d2e_cf473c)
			d2e_d2c658.add472b90(15, -999999);
		if (d2e_cf4740)
			d2e_d2c658.add472b90(16, -999999);
		if (d2e_cf45d8.isTypeAllowed(d2e_d1e888->type))
			d2e_d2c658.add472b90(17, -999999);
		if (!d2e_d2c658.unknown472c70(2))
			d2e_d2c658.add472b90(20, opr1c_scaleRepeated(d2e_d389c4[20]->unknown4c, d2e_d1e888->unknown46ed20() + 1, d2e_ba6840));
	}
}
