// CEffects::update (exe 0x960bc0, vtable slot 6): timed screen effects (corruption, data downloads,
// exoskeleton integration, RIF install, imprinter, 0bPrime announcements, Warlord map, endgame).
// NOTE: class is declared here as D2Effects (placeholder name); layouts are partial, names are placeholders.
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(int v);	// 0x409990
	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos) throw();	// 0x46ca50
	Pos(const Pos &pos, int dx, int dy);	// 0x4099c0
	void set_40a010(int x_, int y_);	// NOTE: placeholder name
};

struct D2xPt : Pos	// NOTE: placeholder name (default ctor 0x453b40)
{
	D2xPt();
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;
	Rect(int x_, int y_, int width_, int height_);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &color) throw();
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

	bool isHidden();
	Pos getPos();
	void setPos(const Pos &pos);
	int getWidth_44b0d0();
	int getHeight();
	void setHidden(bool hidden_);
	void removeSubconsole(XConsole *console);
	void setBgColor(XColor color);
	void putChar_4180b0(int x, int y, int ch);
	void print(int x, int y, const string &text);
	void setScaleX_417b60(float value);
	void setScaleY_417b80(float value);
	void updateBase429e30();	// NOTE: placeholder name

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

	int unknown60;
	void *engine;
	void *title;
};

class D2xEffect : public Console	// NOTE: placeholder name (CEffect, size 0x70)
{
public:
	D2xEffect(XConsole *parent, const Rect &rect, int layer);
	char pad6c[0x70 - 0x6c];
};

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);
	char pad6c[0x88 - 0x6c];
};

class D2xGrid	// NOTE: placeholder name (Array2D<int>)
{
public:
	int getWidth_9fcd80();
	int getHeight_9b8f00();
	int *at(int x, int y);
};

class D2xProp
{
public:
	void disableMachine();
	const string &name45c590();	// NOTE: placeholder name
};

class HProp
{
public:
	int ID;
	HProp() throw();
	bool isValid() const;	// 0x9b7230
	D2xProp *operator->() const;	// 0x9b64f0
};

class D2xCell
{
public:
	HProp getProp();
	void trigger45e110(int a, int b, class HEntity entity);	// NOTE: placeholder name
};

class D2xCellGrid	// NOTE: placeholder name (map cells at 0xcfd44c)
{
public:
	D2xCell **at(int x, int y);
	D2xCell **atPoint(Pos &p);
};
extern D2xCellGrid d2x_cfd44c;
extern D2xGrid d2x_d1e970;

class D2xItemData { public: string getPrefixedName(int *flags); };	// NOTE: placeholder name

class D2xItem
{
public:
	int getType();
	int getWidth_9fcd80();	// NOTE: placeholder name (ICF'd getter)
	int getNestedField();
	int unknown457f90();
	int value9b6bf0();	// NOTE: placeholder name (ICF'd getter)
	D2xItemData *data();	// NOTE: placeholder name
	void remove57dbe0(int a, int b, int c, int d);
};

class HItem
{
public:
	int ID;
	HItem() throw();
	bool isValid() const;
	D2xItem *operator->() const;	// 0x9b65b0
};

class D2xEntity
{
public:
	int unknown5cab90();
	HItem unknown5d2380(int slot);
	bool unknown45aff0();
	bool unknown5ced30();
	int field490840();	// NOTE: placeholder name
	int unknown5ca840();
	vector<HItem> *getInventoryList();
	int getSlotTotal();
	int unknown5dc440(HItem item);
	const Pos &getPosition();
};

class HEntity
{
public:
	int ID;
	HEntity() throw();	// 0x9b6590
	D2xEntity *operator->() const;	// 0x9b6570
};

class D2xHandle { public: int ID; D2xHandle() throw(); };	// NOTE: placeholder name

class D2xMap	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer();
	bool unknown7290f0(HEntity entity);
	void unknown6c65a0(HEntity entity, const string &text, int a);
	void unknown465100();
	void unknown777190(int a);
	class D2xHandle addRecord(class D2xHandle handle);	// NOTE: placeholder
};
extern D2xMap *d2x_cefc4c;

class D2xRex
{
public:
	class D2xRoot *getHighlighter_4ab670();
	int unknown418980();
	int unknown4189a0();
	void setLayer426b60(XConsole *console, int layer);	// NOTE: placeholder name
};
extern D2xRex d2x_d223f0;
class D2xRoot { public: int getLayer(XConsole *console); };

class D2xLocation { public: int unknown0; int type; int depth; char pad0c[0x26 - 0x0c]; bool unknown26; };
class HLocation { public: int ID; D2xLocation *operator->() const; };
extern HLocation d2x_d1e888;

struct D2xRecord170 { char pad[0x170]; string name; };	// NOTE: placeholder layout
extern vector<D2xRecord170*> d2x_d25de0;
struct D2xRecord54 { char pad[0x54]; int unknown54; char pad58[0xf0 - 0x58]; int unknownf0; };	// NOTE: placeholder layout
extern vector<D2xRecord54*> d2x_d2d1c4;
extern vector<int> d2x_cf4910, d2x_cf4830, d2x_rifLevels_cf4a04, d2x_cf4a14, d2x_cf47cc;
extern vector<D2xGrid*> d2x_cf7550;
extern vector<void*> d2x_cfd2cc;
struct D2xT3 { char a; bool b; char c; };
extern D2xT3 d2x_b90708[];
extern int d2x_b90000[], d2x_rifMaxLevels_b98958[], d2x_b98900[], d2x_b988a8[];

class D2xPlayerData
{
public:
	void unknown77fbc0(int id);
	void unknown780700(int index, int a);
	void unknown77ffb0(int index, int a);
	void unknown780ac0();
	int getCountMinusTwo();
	void installRIF_780f30(int type);
};
extern D2xPlayerData d2x_cf45d8;
class D2xStats
{
public:
	vector<int> *current;
	bool add4729d0(unsigned int id, int value, string text, int extra);
	void add472b90(unsigned int id, int value);
};
extern D2xStats d2x_d2c658;
class D2xGameData { public: void setEntryText(const string &key, const string &value); };
extern D2xGameData d2x_d1e860;
class D2xUI : public XConsole { public: void bubble8758d0(bool flag); };
extern D2xUI *d2x_cec058;
class D2xLog { public: void scrollToEnd_7b4f10(); };
extern D2xLog *d2x_cec0b4;
class D2xPhrase { public: D2xPhrase(int id, string *a, string *b, string *c, HEntity subject, HEntity object); char pad[0x28]; };	// NOTE: placeholder name (OpS2_PhraseTextB)
class D2xMessages { public: int push5121f0(D2xPhrase *phrase); void set451400(int value); };
extern D2xMessages d2x_cf1080;
struct D2xBuilder { bool active; void unknown69e700(int a, int b, float c); };	// NOTE: placeholder layout (0xd25450)
extern D2xBuilder d2x_d25450;
class D2xRolled { public: void say(int a, int b, string text); };
extern D2xRolled *d2x_cefb48;
class D2xPart { public: void unknown890710(bool flag); };
class D2xParts { public: D2xPart *unknown894e70(HItem item); void toggle8993e0(D2xPart *part, bool flag); };
extern D2xParts *d2x_cec088;
class D2xGMItems { public: void addItemAttachCount(int itemID, int count, bool force); };
extern D2xGMItems d2x_d25628;
class D2xExplosion { public: D2xExplosion(HEntity source, int type, const Pos &pos, HEntity target, const Pos &a, const Pos &b); char pad[0x40]; };	// NOTE: placeholder name (SExplosionExpand)
class D2xGM
{
public:
	void showOnce(int type, bool a, int b, int c, int d);
	class D2xHandle createA(D2xExplosion *explosion);	// NOTE: placeholder
	void endGame();
	bool readyGame(int a, int b, int c);
	void unknown78c050();
};
extern D2xGM *d2x_cefaa8;
class D2xInventory { public: void reopen8a2ce0(int a, HEntity entity); };
extern D2xInventory *d2x_cec08c;
extern XConsole *d2x_cec03c, *d2x_cec138;
extern XConsole *d2x_cec054;
extern XColor *d2x_d20cfc;

template <class T> class OpR5h_WL	// NOTE: placeholder name (weighted list)
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	void add(T value, int weight);	// 0x9ba310
	unsigned int size();	// 0x9b81d0
	T &pick();	// 0x9ba470
};

class RNG { public: bool chance(int percent); int rangeInt(float low, float high); };
extern RNG rng;

extern unsigned int d2x_caed20;
extern bool d2x_d28d4c, d2x_cf4d14, d2x_cf4d15;
extern int d2x_cf462c, d2x_cf4954, d2x_cf4970, d2x_cf49d8, d2x_cf49dc, d2x_d1e884, d2x_caf128, d2x_caf12c;
extern const float d2x_c37214, d2x_c37218, d2x_c36ec8, d2x_c36f20, d2x_c36fbc, d2x_c36fc0, d2x_c36ecc, d2x_c36ed0, d2x_c37178, d2x_c370a8, d2x_c36e30;
extern const double d2x_c36fd8;

string intToString(int value);
void opS2_fn510360(string &text);
void opR1d_454260(const Pos &pos, int sound);
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);
bool opS2_showMessage_5111e0(int id, string *a, string *b, string *c, HEntity subject, HEntity object, const Pos *at, bool log);
bool opS2_logPhrase_5141b0(int id, const string *a, const string *b, const string *c, HEntity subject, const Pos *at);
void OpC_findNodes_470320(int a, int depth, vector<HLocation> *nodes, vector<HLocation> *found);
void getAdjacentCells(const Pos &pos, vector<Pos> &cells);
bool d2x_findByName(vector<void*> &list, const string &name, int *index);
int OpS8d_popRandom(vector<int> &v);
void d2x_eraseRange(vector<XConsole*> &v, int from, int to);
int halfDiff_437190(int a, int b);
void opw8_unknown789ac0();
string opr1c_getChronoSaveName_432d80();

#define D2X_MESSAGE(text) do { if (opS2_showMessage_5111e0(0x320, text, 0, 0, HEntity(), HEntity(), 0, false)) d2x_cec058->bubble8758d0(true); d2x_cec0b4->scrollToEnd_7b4f10(); } while (0)
#define D2X_PHRASE(id) do { if (d2x_cf1080.push5121f0(new D2xPhrase(id, 0, 0, 0, HEntity(), HEntity()))) d2x_cec058->bubble8758d0(true); d2x_cec0b4->scrollToEnd_7b4f10(); } while (0)

class D2Effects : public Console
{
public:
	virtual void update();

	bool unknown4b3180();	// NOTE: placeholder name
	void spawn96bf80();	// NOTE: placeholder name
	void unknown9650c0(int state);	// NOTE: placeholder name
	void unknown964d60(int state);	// NOTE: placeholder name
	void unknown969970(int a);	// NOTE: placeholder name
	void unknown969500();	// NOTE: placeholder name

	unsigned int unknown6c;
	unsigned int unknown70;
	int unknown74;
	char pad78[0x7c - 0x78];
	vector<XConsole*> unknown7c;
	unsigned int unknown8c;
	unsigned int unknown90;
	unsigned int unknown94;
	int unknown98;
	vector<XConsole*> unknown9c;
	int unknownac;
	unsigned int unknownb0;
	unsigned int unknownb4;
	int unknownb8;
	vector<XConsole*> unknownbc;
	unsigned int unknowncc;
	vector<XConsole*> unknownd0;
	unsigned int unknowne0;
	vector<XConsole*> unknowne4;
	unsigned int unknownf4;
	char padf8[0x100 - 0xf8];
	vector<XConsole*> unknown100;
	unsigned int unknown110;
	unsigned int unknown114;
	int unknown118;
	vector<int> unknown11c;
	vector<XConsole*> unknown12c;
	unsigned int unknown13c;
	unsigned int unknown140;
	unsigned int unknown144;
	unsigned int unknown148;
	char pad14c[0x15c - 0x14c];
	vector<XConsole*> unknown15c;
	unsigned int unknown16c;
	int unknown170;
	char pad174[0x178 - 0x174];
	int unknown178;
};

void D2Effects::update()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
		break;
	case 1:
		unknown60 = 3;
		break;
	case 3:
	{
		if (!d2x_cefc4c->getPlayer().operator->())
			break;
		if (d2x_d28d4c && d2x_cec03c->isHidden() && d2x_caed20 >= unknown6c)
		{
			if (d2x_cefc4c->getPlayer()->unknown5cab90() && !unknown4b3180() && rng.chance(d2x_cefc4c->getPlayer()->unknown5cab90() * 2))
			{
				bool full = rng.chance(50);
				D2xEffect *effect;
				for (int i = d2x_cefc4c->getPlayer()->unknown5cab90() / 2 + 1; i >= 0; i--)
					effect = new D2xEffect(this, Rect(full ? 0 : rng.rangeInt(0, d2x_d223f0.unknown418980() / 2 - 1), full ? rng.rangeInt(0, d2x_d223f0.unknown4189a0() - 1) : 0, full ? d2x_d223f0.unknown418980() / 2 : 1, full ? 1 : d2x_d223f0.unknown4189a0()), 1);
				if (full && d2x_cf462c == 8 && d2x_cefc4c->getPlayer()->unknown5cab90() > 5 && effect)
				{
					string text = "^2_spu13.dpn";
					opS2_fn510360(text);
					CText *label = new CText(effect, Pos(rng.rangeInt(0, effect->getWidth_44b0d0() - text.size()), 0), text, 0, 0, -1);
					label->animate("A_CEffect_Corr_ForbLore");
				}
			}
			unknown6c = rng.rangeInt(d2x_c37214, d2x_c37218) + d2x_caed20;
		}
		if (d2x_caed20 >= unknown70)
		{
			if (d2x_cefc4c->getPlayer()->unknown5d2380(0xb7).isValid() && !unknown4b3180() && rng.chance((30 - d2x_cefc4c->getPlayer()->unknown5d2380(0xb7)->value9b6bf0()) * 3))
			{
				for (int i = (30 - d2x_cefc4c->getPlayer()->unknown5d2380(0xb7)->value9b6bf0() + 1) / 6; i >= 0; i--)
					spawn96bf80();
			}
			unknown70 = rng.rangeInt(d2x_c36ec8, d2x_c36f20) + d2x_caed20;
		}
		int state = 0x21;
		if (d2x_cefc4c->unknown7290f0(d2x_cefc4c->getPlayer()))
			state = 0x1d;
		else if (d2x_cefc4c->getPlayer()->unknown45aff0() || d2x_cefc4c->getPlayer()->unknown5ced30())
			state = 0x1e;
		else if (d2x_cefc4c->getPlayer()->field490840() * 100 / d2x_cf4954 <= 25)
			state = 0x1f;
		else if (d2x_cefc4c->getPlayer()->unknown5ca840() >= 3)
			state = 0x20;
		if (state != unknown74)
		{
			unknown9650c0(unknown74);
			unknown964d60(state);
		}
		if (unknown90 != 0)
		{
			while (d2x_caed20 >= unknown94)
			{
				switch (unknown98)
				{
				case 0:
				{
					int count = 0;
					for (unsigned int i = 0; i < d2x_d25de0.size(); i++)
					{
						if (!d2x_d25de0[i]->name.empty())
						{
							if (d2x_cf4910[i] == 0)
								d2x_cf45d8.unknown780700(i, 1);
							count++;
						}
					}
					D2X_MESSAGE(&("Downloaded " + intToString(count) + " analysis records."));
					break;
				}
				case 1:
				{
					int count = 0;
					for (unsigned int i = 0; i < d2x_d2d1c4.size(); i++)
					{
						if (d2x_d2d1c4[i]->unknown54)
						{
							d2x_cf45d8.unknown77ffb0(i, 0);
							count++;
						}
					}
					D2X_MESSAGE(&("Downloaded " + intToString(count) + " prototype IDs."));
					break;
				}
				case 2:
					for (int i = 1; i < 0x26; i++)
					{
						if (d2x_b90000[i] == 1)
							*d2x_d1e970.at(9, i) += 100;
					}
					D2X_MESSAGE(&string("Downloaded central machine database."));
					break;
				case 3:
				{
					vector<HLocation> list;
					for (int i = 1; i <= 10; i++)
					{
						vector<HLocation> nodes;
						OpC_findNodes_470320(d2x_d1e884, i, &list, &nodes);
					}
					int count = 0;
					for (unsigned int i = 0; i < list.size(); i++)
					{
						if (d2x_b90708[list[i]->type].b)
						{
							list[i]->unknown26 = true;
							d2x_d2c658.add4729d0(0x405, 1, "", -1);
							count++;
						}
					}
					D2X_MESSAGE(&("Downloaded " + intToString(count) + " destinations."));
					break;
				}
				case 4:
					D2X_MESSAGE(&string("Downloaded encryption format records."));
					break;
				}
				unknown98++;
				unknown94 += 500;
			}
			if (d2x_caed20 >= unknown90)
			{
				d2x_d1e860.setEntryText("datDataConduitDisabled_g", "1");
				if ((*d2x_cfd44c.at(8, 0xb))->getProp().isValid())
				{
					(*d2x_cfd44c.at(8, 0xb))->getProp()->disableMachine();
					Pos pos(0x13, 0x17);
					opR1d_454260(pos, 0x91);
				}
				d2x_d1e860.setEntryText("datDataConduitDownloaded_g", "1");
				d2x_d1e860.setEntryText("enemiesWithArchitect_g", "1");
				d2x_d1e860.setEntryText("datHostileToDataMiner_g", "1");
				D2X_MESSAGE(&string("Connection remotely terminated."));
				d2x_cf45d8.unknown77fbc0(0x17f);
				if (d2x_d25450.active)
					d2x_d25450.unknown69e700(0x62, 0, 0);
				for (unsigned int i = 0; i < unknown7c.size(); i++)
				{
					if (unknown7c[i])
						removeSubconsole(unknown7c[i]);
				}
				unknown7c.clear();
				unknown90 = 0;
			}
			else
			{
				int steps = (d2x_caed20 - unknown8c) / 10;
				for (unsigned int i = 0; i < unknown7c.size(); i++)
					unknown7c[i]->setPos(Pos(unknown7c[i]->getPos(), 0, steps));
				for (int i = 0; i < steps; i++)
					unknown7c.push_back(new D2xEffect(this, Rect(10, i, rng.rangeInt(d2x_c36fbc, d2x_c36fc0), 1), 6));
				unknown8c += steps * 10;
				if (d2x_caed20 > unknown90 - 1000)
				{
					float scale = 1 - (d2x_caed20 - (unknown90 - 1000)) / d2x_c36fd8;
					for (unsigned int i = 0; i < unknown7c.size(); i++)
					{
						unknown7c[i]->setScaleX_417b60(scale);
						unknown7c[i]->setScaleY_417b80(scale);
					}
				}
			}
		}
		if (unknownb0 != 0)
		{
			while (d2x_caed20 >= unknownb4)
			{
				switch (unknownb8)
				{
				case 0:
					d2x_cf4970 += 100;
					D2X_MESSAGE(&("Core energy storage capacity increased (+" + intToString(100) + ")."));
					break;
				case 1:
				{
					int added = unknownac - d2x_cefc4c->getPlayer()->getSlotTotal();
					if (added > 0)
					{
						int old = d2x_cf49d8;
						d2x_cf49d8 += added * 3;
						if (d2x_cf49d8 > old)
							D2X_MESSAGE(&("Core energy generation increased (+" + intToString(d2x_cf49d8 - old) + ")."));
					}
					break;
				}
				case 2:
				{
					int added = unknownac - d2x_cefc4c->getPlayer()->getSlotTotal();
					if (added > 0)
					{
						int old = d2x_cf49dc;
						d2x_cf49dc += added * 5;
						if (d2x_cf49dc > old)
							D2X_MESSAGE(&("Core heat dissipation increased (+" + intToString(d2x_cf49dc - old) + ")."));
					}
					break;
				}
				case 3:
					D2X_MESSAGE(&string("Damage mitigation: ONLINE."));
					break;
				case 4:
					D2X_MESSAGE(&string("Environment scanning: ONLINE."));
					break;
				case 5:
					D2X_MESSAGE(&string("Threat analysis: ONLINE."));
					break;
				case 6:
					D2X_MESSAGE(&string("Hypermatrix comlink: ONLINE."));
					break;
				case 7:
					D2X_MESSAGE(&string("Tor triangulation: ONLINE."));
					break;
				}
				unknownb8++;
				unknownb4 += 250;
			}
			if (d2x_caed20 >= unknownb0)
			{
				D2X_MESSAGE(&string("Systems fully integrated."));
				D2X_MESSAGE(&string("Proceed to surface for extraction."));
				do
				{
					opS2_logPhrase_5141b0(0x201, 0, 0, 0, HEntity(), 0);
				} while (0);
				d2x_d2c658.add472b90(0x50, -999999);
				d2x_cf45d8.unknown77fbc0(0x1a3);
				if (d2x_cefb48)
					d2x_cefb48->say(0x74, 0, "");
				d2x_d1e860.setEntryText("secSigixExoskeletonIntegrated_g", "1");
				d2x_d1e860.setEntryText("secSigixActive_g", "1");
				d2x_cefc4c->unknown6c65a0(d2x_cefc4c->getPlayer(), "SEC_Sigix_Exo_Comment", 0);
				d2x_cefc4c->unknown6c65a0(d2x_cefc4c->getPlayer(), "SEC_Cogmind_Exo_Integ80", 0);
				vector<HItem> *inventory = d2x_cefc4c->getPlayer()->getInventoryList();
				for (unsigned int i = 0; i < inventory->size(); i++)
				{
					if ((*inventory)[i]->getType() <= 3 && !d2x_cefc4c->getPlayer()->unknown5dc440((*inventory)[i]))
					{
						D2xPart *part = d2x_cec088->unknown894e70((*inventory)[i]);
						d2x_cec088->toggle8993e0(part, false);
						if (part)
							part->unknown890710(false);
						d2x_cf47cc.push_back((*inventory)[i]->getWidth_9fcd80());
						d2x_d25628.addItemAttachCount((*inventory)[i]->getNestedField(), 1, false);
						d2x_d2c658.add4729d0(5, 1, (*inventory)[i]->data()->getPrefixedName(0), -1);
						d2x_cf45d8.unknown77fbc0(0x13);
						if ((*d2x_d2c658.current)[5] == 15)
							d2x_cf45d8.unknown77fbc0(0x153);
					}
				}
				d2x_cf4d14 = false;
				d2x_cf4d15 = false;
				for (unsigned int i = 0; i < unknown9c.size(); i++)
				{
					if (unknown9c[i])
						removeSubconsole(unknown9c[i]);
				}
				unknown9c.clear();
				unknownb0 = 0;
			}
		}
		if (unknowncc != 0 && d2x_caed20 >= unknowncc)
		{
			if (d2x_cf4a14.empty())
			{
				d2x_cf45d8.unknown780ac0();
				d2x_cf45d8.unknown77fbc0(0x66);
				if (d2x_d1e888->depth <= 4)
					d2x_cf45d8.unknown77fbc0(0xc5);
				d2x_cefaa8->showOnce(0x51, true, 0, 0, 0);
			}
			else
			{
				int max = d2x_cf45d8.getCountMinusTwo();
				OpR5h_WL<int> types;
				for (int i = 3; i < 0x13; i++)
				{
					if ((d2x_rifLevels_cf4a04[i] == 0 || d2x_rifLevels_cf4a04[i] < d2x_rifMaxLevels_b98958[i]) && max >= d2x_b98900[i])
						types.add(i, d2x_b988a8[i]);
				}
				if (!types.size())
				{
					D2X_PHRASE(0x29c);
					do
					{
						opS2_logPhrase_5141b0(0x194, 0, 0, 0, HEntity(), 0);
					} while (0);
				}
				else
				{
					int type = types.pick();
					d2x_cf45d8.installRIF_780f30(type);
				}
			}
			vector<Pos> cells;
			getAdjacentCells(d2x_cefc4c->getPlayer()->getPosition(), cells);
			for (unsigned int i = 0; i < cells.size(); i++)
			{
				if ((*d2x_cfd44c.atPoint(cells[i]))->getProp().isValid() && (*d2x_cfd44c.atPoint(cells[i]))->getProp()->name45c590() == "GAR_RIF_Installer")
				{
					(*d2x_cfd44c.atPoint(cells[i]))->getProp()->disableMachine();
					break;
				}
			}
			bool state = false;
			for (unsigned int i = 0; i < d2x_d2d1c4.size(); i++)
			{
				if (d2x_d2d1c4[i]->unknownf0 == 0x7c && d2x_cf4830[i] == 0)
				{
					d2x_cf45d8.unknown77ffb0(i, 0);
					state = true;
				}
			}
			if (state)
				d2x_cec08c->reopen8a2ce0(4, HEntity());
			d2x_d2c658.add4729d0(0x310, 1, "", -1);
			d2x_d2c658.add472b90(0x25, -999999);
			for (unsigned int i = 0; i < unknownbc.size(); i++)
			{
				if (unknownbc[i])
					removeSubconsole(unknownbc[i]);
			}
			unknownbc.clear();
			unknowncc = 0;
		}
		if (unknowne0 != 0 && d2x_caed20 >= unknowne0)
		{
			opw8_unknown789ac0();
			D2X_PHRASE(0x106);
			d2x_cf45d8.unknown77fbc0(0x197);
			for (unsigned int i = 0; i < unknownd0.size(); i++)
			{
				if (unknownd0[i])
					removeSubconsole(unknownd0[i]);
			}
			unknownd0.clear();
			unknowne0 = 0;
			d2x_cefc4c->unknown465100();
		}
		if (unknownf4 != 0 && d2x_caed20 >= unknownf4)
		{
			opw8_unknown789ac0();
			D2X_PHRASE(0x2ae);
			for (unsigned int i = 0; i < unknowne4.size(); i++)
			{
				if (unknowne4[i])
					removeSubconsole(unknowne4[i]);
			}
			unknowne4.clear();
			unknownf4 = 0;
			int index;
			if (d2x_findByName(d2x_cfd2cc, "ZIO_Imprinter_Explode", &index))
			{
				vector<Pos> points;
				Pos center = d2x_cefc4c->getPlayer()->getPosition();
				points.push_back(Pos(center, -8, -1));
				points.push_back(Pos(center, 1, 8));
				points.push_back(Pos(center, 8, -2));
				for (unsigned int i = 0; i < points.size(); i++)
				{
					(*d2x_cfd44c.atPoint(points[i]))->trigger45e110(0, 0, HEntity());
					d2x_cefc4c->addRecord(d2x_cefaa8->createA(new D2xExplosion(HEntity(), index, points[i], HEntity(), Pos(-1), Pos(-1))));
				}
			}
			d2x_cf45d8.unknown77fbc0(0x181);
		}
		if (unknown114 != 0)
		{
			if (d2x_caed20 >= unknown114)
			{
				D2X_PHRASE(0x2b1);
				d2x_cf45d8.unknown77fbc0(0x170);
				for (unsigned int i = 0; i < unknown100.size(); i++)
				{
					if (unknown100[i])
						removeSubconsole(unknown100[i]);
				}
				unknown100.clear();
				unknown114 = 0;
			}
			else if (unknown100.empty() || (d2x_caed20 >= unknown110 && rng.chance(25)))
			{
				unknown969970(0);
				unknown110 = d2x_caed20 + 50;
			}
		}
		if (unknown118 != -1)
		{
			if (d2x_caed20 >= unknown140)
			{
				unknown118++;
				string text;
				switch (unknown118)
				{
				case 1:
					text = "ANNOUNCEMENT: The Council has discovered that 0bPrime has been recruiting others in a plan that puts all of Scraptown in danger.";
					goto announce;
				case 2:
					text = "ANNOUNCEMENT: Evidence is being transmitted to you now...";
					goto announce;
				case 3:
					text = "ANNOUNCEMENT: This news will hit some of you hard, but given the circumstances we have no choice but to apprehend Optimus and allies.";
					goto announce;
				case 4:
					text = "0BP_ANNOUNCE: There is another choice, join 0bPrime! Our vision ensures independence and glory for all Derelicts!";
					goto announce;
				case 5:
					text = "ANNOUNCEMENT: Sever that connection!";
					goto announce;
				case 6:
					text = "0BP_ANNOUNCE: We are one. To vict--";
					goto announce;
				case 7:
					text = "ANNOUNCEMENT: Reinforcements are on the way. Do not resist and we may be able to reach an agreement.";
				announce:
					do
					{
						d2x_cf1080.set451400(1);
						if (0)
							opR1d_4541b0(-1, 0, 0);
						do
						{
							if (opS2_showMessage_5111e0(0x324, &text, 0, 0, HEntity(), HEntity(), 0, false))
								d2x_cec058->bubble8758d0(true);
							d2x_cec0b4->scrollToEnd_7b4f10();
						} while (0);
						d2x_cec0b4->scrollToEnd_7b4f10();
					} while (0);
					break;
				default:
					unknown969500();
				}
				if (unknown118 != -1)
					unknown140 = d2x_caed20 + 2500;
			}
			if (unknown118 != -1 && d2x_caed20 >= unknown13c)
			{
				int level = d2x_d223f0.getHighlighter_4ab670()->getLayer(this) + 1;
				int width = d2x_cec054->getWidth_44b0d0() * d2x_caf128 / 2;
				int height = d2x_cec054->getHeight() * d2x_caf12c;
				XConsole *current;
				if (unknown118 == 1)
				{
					current = new D2xEffect(this, Rect(d2x_cec054->getPos().x, d2x_cec054->getPos().y, width, height), 0x15);
					((Console *)current)->animate("A_CEffect_CW_Fill");
					unknown12c.push_back(current);
					d2x_d223f0.setLayer426b60(current, level);
				}
				for (unsigned int i = 1; i < unknown12c.size(); i++)
					removeSubconsole(unknown12c[i]);
				d2x_eraseRange(unknown12c, 1, unknown12c.size() - 1);
				if (!unknown11c.empty())
				{
					D2xGrid *tiles = d2x_cf7550[OpS8d_popRandom(unknown11c)];
					current = new D2xEffect(this, Rect(0, 0, tiles->getWidth_9fcd80(), tiles->getHeight_9b8f00()), 0x15);
					Pos pos(d2x_cec054->getPos().x, d2x_cec054->getPos().y);
					pos.x += tiles->getWidth_9fcd80() >= width ? -(tiles->getWidth_9fcd80() - width) : rng.rangeInt(1, width - 2 - tiles->getWidth_9fcd80()) * 2;
					pos.y += tiles->getHeight_9b8f00() >= height ? -((tiles->getHeight_9b8f00() - height) / 2) : rng.rangeInt(1, height - 2 - tiles->getHeight_9b8f00());
					current->setPos(pos);
					current->setBgColor(*d2x_d20cfc);
					for (int x = 0; x < tiles->getWidth_9fcd80(); x++)
					{
						for (int y = 0; y < tiles->getHeight_9b8f00(); y++)
							current->putChar_4180b0(x, y, *tiles->at(x, y));
					}
					((Console *)current)->animate("A_CEffect_CW_Map");
					unknown12c.push_back(current);
					d2x_d223f0.setLayer426b60(current, level);
					current = new D2xEffect(this, Rect(pos.x, pos.y, tiles->getWidth_9fcd80(), tiles->getHeight_9b8f00()), 0x15);
					((Console *)current)->animate("A_CEffect_CW_Mask");
					unknown12c.push_back(current);
					d2x_d223f0.setLayer426b60(current, level + 1);
					vector<Pos> used;
					D2xPt p;
					for (int n = rng.rangeInt(d2x_c36ecc, d2x_c36ed0); n > 0; n--)
					{
						for (int tries = 0; tries < 30; tries++)
						{
							p.set_40a010(rng.rangeInt(1, tiles->getWidth_9fcd80() - 2), rng.rangeInt(1, tiles->getHeight_9b8f00() - 2));
							if (*tiles->at(p.x - 1, p.y + 1) == 0x20)
								goto next;
							p.x *= 2;
							for (unsigned int j = 0; j < used.size(); j++)
							{
								if (abs(p.x - used[j].x) <= 2 || abs(p.y - used[j].y) <= 2)
									goto next;
							}
							used.push_back(p);
							current = new D2xEffect(this, Rect(pos.x + p.x, pos.y + p.y, rng.rangeInt(d2x_c37178, d2x_c370a8), 2), 0x16);
							current->setBgColor(*d2x_d20cfc);
							((Console *)current)->animate("A_CEffect_CW_Data_Delay");
							unknown12c.push_back(current);
							d2x_d223f0.setLayer426b60(current, level + 1);
							break;
						next:;
						}
					}
					opR1d_4541b0(0x8f, 0, 0);
				}
				unknown13c = d2x_caed20 + 1500;
			}
		}
		if (unknown148 != 0)
		{
			if (d2x_caed20 >= unknown148)
			{
				unknown148 = 0;
				d2x_cefaa8->endGame();
				if (!d2x_cefaa8->readyGame(0, 1, 0))
					exit(1);
				d2x_cefaa8->unknown78c050();
				remove(opr1c_getChronoSaveName_432d80().c_str());
				d2x_cec054->setHidden(false);
				d2x_cec058->setHidden(false);
				vector<HItem> *inventory = d2x_cefc4c->getPlayer()->getInventoryList();
				for (unsigned int i = 0; i < inventory->size(); i++)
				{
					if ((*inventory)[i]->unknown457f90() == 0xb7)
					{
						(*inventory)[i]->remove57dbe0(0, 0, 1, 1);
						i--;
					}
				}
				do
				{
					if (opS2_showMessage_5111e0(0x11a, 0, 0, 0, HEntity(), HEntity(), 0, false))
						d2x_cec058->bubble8758d0(true);
					d2x_cec0b4->scrollToEnd_7b4f10();
				} while (0);
				d2x_d2c658.add4729d0(0x401, 1, "", -1);
				do
				{
					opS2_logPhrase_5141b0(0x53, 0, 0, 0, HEntity(), 0);
				} while (0);
				d2x_cf45d8.unknown77fbc0(0x87);
				return;
			}
			else if (d2x_caed20 >= unknown144)
			{
				for (int n = rng.rangeInt(d2x_c36ed0, d2x_c36e30); n > 0; n--)
					spawn96bf80();
				unknown144 = d2x_caed20 + 100;
			}
		}
		if (unknown170 > 0 && d2x_caed20 >= unknown16c)
		{
			unknown16c = d2x_caed20 + 2000;
			unknown170 = -1;
			string text = "SYSTEM ASSIMILATED";
			D2xEffect *effect = new D2xEffect(d2x_cec138, Rect(halfDiff_437190(text.size() * 2, d2x_d223f0.unknown418980()), d2x_d223f0.unknown4189a0() / 2, text.size(), 1), 0x1a);
			effect->print(0, 0, text);
			effect->animate("A_BlockAppear_GR3");
		}
		if (unknown170 == -1 && d2x_caed20 >= unknown16c)
		{
			for (unsigned int i = 0; i < unknown15c.size(); i++)
			{
				if (unknown15c[i])
					removeSubconsole(unknown15c[i]);
			}
			unknown15c.clear();
			unknown16c = 0;
			unknown178 = 0;
			unknown170 = -4;
			d2x_cefc4c->unknown777190(4);
			return;
		}
		break;
	}
	}
	updateBase429e30();
}
