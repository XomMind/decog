// CEvolve::update (exe 0x98dbc0, vtable slot 6): evolution screen state machine and map transition.
// NOTE: class is declared here as D2Evolve6 (placeholder name); layouts are partial, names are placeholders.
#include <string>
#include <vector>
#include <limits>
#include <stdlib.h>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(const Pos &pos) throw();
	bool test_409cb0(int a, int b);	// NOTE: placeholder name
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;
	Rect(const Rect &rect);	// 0x40a720
	int x2();	// 0x40ac20
	int y2();	// 0x40ac40
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &color) throw();
	bool operator!=(XColor color);
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
	int getHeight();
	void setHidden(bool hidden_);
	XColor getBack(int x, int y);
	void removeSubconsole(XConsole *console);
	void setPos(const Pos &pos);
	void resetBack_418450() throw();

	char pad04[0x60 - 0x04];
};

class D2vQueue { public: bool hasItems(); };	// NOTE: placeholder name

class Console : public XConsole
{
public:
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void render();
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);

	int unknown60;
	D2vQueue *engine;
	void *title;
};

class D2vEngine { public: void update(); };	// NOTE: placeholder name

class D2vMain : public Console	// NOTE: placeholder name (CEvolveMain, size 0xa8)
{
public:
	D2vMain(XConsole *parent, const Rect &rect, int count);
	char pad6c[0x74 - 0x6c];
	int slots[4];
	char pad84[0xa8 - 0x84];
};
class D2vAnalyzing : public Console { public: D2vAnalyzing(XConsole *parent, const Rect &rect); };	// NOTE: placeholder name
class D2vSequencing : public Console { public: D2vSequencing(XConsole *parent, const Rect &rect); char pad6c[0x90 - 0x6c]; };	// NOTE: placeholder name
class D2vQuantum : public Console { public: D2vQuantum(XConsole *parent, const Rect &rect); };	// NOTE: placeholder name
class D2vAnomaly : public Console { public: D2vAnomaly(XConsole *parent, bool first); char pad6c[0x78 - 0x6c]; };	// NOTE: placeholder name

class D2vEntity;
class D2vItem;

class D2vHE	// NOTE: placeholder name (HEntity)
{
public:
	int ID;
	D2vHE() throw();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	bool operator!=(D2vHE other) const;	// 0x9b6510
	D2vEntity *operator->() const;	// 0x9b6570
};

class D2vHI	// NOTE: placeholder name (item handle)
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
	D2vItem *operator->() const;	// 0x9b65b0
	void resetField();	// 0x9b7270
};

struct D2vStatsRec	// NOTE: placeholder layout
{
	char pad0[0x1af];
	bool flag1af;
};

struct D2vGenRec	// NOTE: placeholder layout
{
	char pad0[0x1cc];
	int rooms[4];
};

class D2vItem
{
public:
	int f_9b4b50();	// NOTE: placeholder name (GetCachedSize fold)
	D2vHE unknown457b50();
	int getType();
	D2vStatsRec *stats_9b4350();	// NOTE: placeholder name
	int getNestedField();
	int nested_4578a0();	// NOTE: placeholder name
	int getWidth_9fcd80();
	int getEffect(int type);
	D2vHE owner_45a260();
	string &name_457860();
	int getEffectValue(int type);
};

class D2vSnap { public: void init(D2vHE entity, int mode); };	// NOTE: placeholder name
class D2vNode : public D2vSnap	// NOTE: placeholder name (OpR1g_Node, size 0x38)
{
public:
	D2vNode(bool flag) throw();
	~D2vNode();
	int pad0[5];
	vector<D2vItem *> items;
	int pad24[5];
};

class D2vAI { public: bool unknown4590b0(int type); };	// NOTE: placeholder name

class D2vEntity
{
public:
	int getRoomCount(int type);
	D2vGenRec *gen_9b4350();	// NOTE: placeholder name
	int *unknown45a840();
	void unknown45b100(int *slots);
	int unknown5ca260(int a);
	void unknown5dea60(int a);
	int unknown5cab30();
	void setField_4514c0(int a);
	void set_5b6d00(int a);
	vector<int> *unknown4646b0();	// NOTE: placeholder name
	bool isPlayer();
	Pos *getPosition();
	int getWidth_9fcd80();
	D2vHE unknown45a260();
	bool unknown5c83d0(Pos *pos, int range);
	bool unknown5d1280(int a);
	int getTarget();
	D2vAI *unknown45b590();
	string &getName();
	int getSize();
	bool unknown45ad20(const string &key);
	int getFaction();
	Pos unknown45a4c0();
	int unknown45a880();
	bool unknown5d2a00(int type);
};

struct D2vMarker { int id; };	// NOTE: placeholder name
struct D2vSlot : D2vMarker	// NOTE: placeholder name (size 0x14)
{
	D2vSlot(int id, int a, D2vHE e1, int b, D2vHE e2) throw();
	char pad04[0x14 - 0x04];
};

struct D2vSwap	// NOTE: placeholder name
{
	D2vHI h0;
	D2vHI h4;
	D2vItem *item8;
	D2vItem *itemc;
	bool isPlayerSwap();
};

class D2vCell	// NOTE: placeholder name
{
public:
	bool getField_45e360();
	vector<D2vHE> *getFore_416f40();
};
class D2vHCell { public: int ID; D2vCell *get230(); };	// NOTE: placeholder name

class D2vRes { public: void *release_resources(); };
class D2vHRes { public: int ID; D2vRes *get234(); };
class D2vMap	// NOTE: placeholder name (0xcefc4c)
{
public:
	D2vHE getPlayer();
	D2vHE getEntity671();
	void unknown735620();
	int unknown4638e0(int a, int b);
	D2vHE unknown7152d0(int a, const string &name);
	bool unknown4631f0(D2vHE entity);
	D2vHCell unknown463890(int index);
	vector<int> *unknown4646b0();
	vector<struct D2vRecord *> *getRecords_462e10();	// NOTE: placeholder name
	int unknown71abf0(int a);
	bool initilize();
	int getTurn();
	int unknown463d40();
	int unknown463e30();
	D2vMap();
	~D2vMap();
	char pad0[0x65c];
	D2vHRes resources;
	char pad660[0xc68 - 0x660];
};
extern D2vMap *d2v_cefc4c;

class D2vHL;
struct D2vLoc { int unknown0; int type; int depth; char padc[0x1c - 0xc]; int seed; char pad20[0x25 - 0x20]; bool known; char pad26[0x40 - 0x26]; vector<D2vHL> list40; vector<D2vHL> list50; bool patrols; int getDepthIndex(); D2vHI find_46ee80(int type); };	// NOTE: placeholder layout
class D2vHL { public: int ID; D2vLoc *get23c(); D2vLoc *get23c_nt() throw(); bool operator==(D2vHL other) const; };	// NOTE: placeholder name

class D2vStats { public: bool add4729d0(unsigned int id, int amount, string text, int extra); void add472b90(unsigned int id, int value); };	// NOTE: placeholder name
extern D2vStats d2v_d2c658;
class D2vGraph { public: void popFrame(); };
extern D2vGraph *d2v_cefa8c;
struct D2vCefb48 { char pad0[0x20]; int type; int slot; };
extern D2vCefb48 *d2v_cefb48;
class D2vRex { public: int unknown418980(); XConsole *getHighlighter_4ab670(); };
extern D2vRex d2v_d223f0;
extern int d2v_d25e80, d2v_d25e84;
extern unsigned int d2v_caed20;
extern int d2v_bcded4[];
extern int d2v_ba7aec[], d2v_ba7afc[];
extern D2vHL d2v_d1e888;
extern XColor *d2v_d20cfc;
extern vector<D2vHI> d2v_cf4944;
struct D2vFlag24 { char pad0[0x24]; bool flag24; };
struct D2vCf4ac8 { int unknown0; D2vHI map; char pad8[0x30 - 0x8]; D2vFlag24 *unknown30; };
extern D2vCf4ac8 *d2v_cf4ac8;
extern int d2v_cefb70, d2v_d33a3c;
extern vector<D2vHE> d2v_cf4aa8;
extern vector<int> d2v_cf4ab8, d2v_d33a40;
class D2vPlayerData { public: void loadPartSlots(int a, int *slots); bool getField_46dd90(); void unknown77fbc0(int id); bool unknown77f260(int a); };
extern D2vPlayerData d2v_cf45d8;
extern vector<vector<D2vMarker *> > d2v_cf4750;
extern vector<D2vSwap *> d2v_cf4760;
extern D2vNode d2v_d338e4;
extern D2vEntity *d2v_d338e8;
extern vector<D2vHI> d2v_cf4a38, d2v_cf4a48;
class D2vPool { public: D2vItem *release(D2vHE entity); void clearAll(bool all); };
extern D2vPool d2v_d2a298;
extern vector<D2vItem *> d2v_d3392c, d2v_d3393c, d2v_d338f8;
extern vector<D2vNode> d2v_d3394c[];
extern vector<D2vSnap *> d2v_d1e97c[];
extern vector<int> d2v_d1ea6c;
struct D2vTotals { char pad0[0x1a8]; int total; int getTotal459ef0(); };
extern vector<D2vTotals *> d2v_d25de0;
extern int d2v_cefb74;
extern int d2v_d1eac0;

class D2vGameData { public: const string &getEntryText(const string &key); void setEntryText(const string &key, const string &value); int getDepthIndex(); bool isFlagEnabledA(); bool isFlagEnabledB(); };
extern D2vGameData d2v_d1e860;
struct D2vItemData { char pad0[0x24]; string name; };	// NOTE: placeholder layout
extern vector<D2vItemData *> d2v_d2d1c4;
extern int d2v_cf4d70, d2v_d1eaf8, d2v_d1eafc, d2v_d1eb00, d2v_d1eb04;
extern bool d2v_d1eacc;
class D2vMapCell { public: D2vHI getItem(); };	// NOTE: placeholder name
class D2vCellGrid { public: D2vMapCell **at(int x, int y); };	// NOTE: placeholder name
extern D2vCellGrid d2v_cfd44c;
string intToString(int value);
int stringToInt(const string &text);
string opR1d_4550d0(int count);
void opS2_logPhrase_5141b0(int id, const string &text, int a, int b, D2vHE entity, int c);
extern string d2v_mapNames_cfaca0[];
extern vector<int> d2v_cf4d00;
extern int d2v_cf4d10;
extern void *d2v_d338e0;
struct D2vRecord	// NOTE: placeholder layout
{
	char pad0[0x8];
	D2vHL location;
	char padc;
	bool flagd;
	bool flage;
	char padf[0x1c - 0xf];
	int type;
	vector<int> list20;
	vector<int> list30;
	vector<int> list40;
	vector<int> list50;
};
void d2v_appendA(vector<int> &dest, vector<int> &src);
void d2v_appendB(vector<int> &dest, vector<int> &src);
void d2v_appendC(vector<int> &dest, vector<int> &src);
extern vector<int> d2v_d33a50, d2v_d33a60, d2v_d33a70, d2v_d33a80;
extern bool d2v_d1eb98, d2v_cefbc6, d2v_cefc71;
extern vector<int> d2v_d1ea9c;
class D2vPoolA { public: void clearAll(bool all); };	// NOTE: placeholder names (object pools)
class D2vPoolB { public: void clearAll(bool all); };
class D2vPoolC { public: void clearAll(bool all); };
class D2vPoolD { public: void clearAll(bool all); };
class D2vPoolE { public: void clearAll(bool all); };
class D2vPoolF { public: void clearAll(bool all); };
extern D2vPoolA d2v_d20404;
extern D2vPoolB d2v_d2f288;
extern D2vPoolC d2v_d208d4;
extern D2vPoolD d2v_d21720;
extern D2vPoolE d2v_d1e720;
extern D2vPoolF d2v_cfac14;
class D2vAnimPool { public: D2vAnimPool(); ~D2vAnimPool(); char pad0[0x68]; };	// NOTE: placeholder name
extern D2vAnimPool *d2v_cefc50;
class D2vOvermind { public: void clear674a80(); void resetSurgicalTimer(); };	// NOTE: placeholder name
extern D2vOvermind d2v_cf6428;
struct D2vCec068 { char pad0[0x70]; int unknown70; };
extern D2vCec068 *d2v_cec068;
class D2vCMap : public Console { public: void unknown7fe7a0(); void reset_7f5fd0(int a); void unknown8069e0(Pos pos, bool flag); };	// NOTE: placeholder name
extern D2vCMap *d2v_cec054;
class D2vMission : public Console { public: void unknown987fd0(); void unknown987ea0(); void unknown988270(); void unknown987b10(int a); };	// NOTE: placeholder name
extern D2vMission *d2v_cec034;
extern vector<D2vHL> d2v_d1e88c;
class D2vTri { public: D2vTri(); ~D2vTri(); int a, b, c, d, e, f, g, h, i, j, k, l; };	// NOTE: placeholder name
extern vector<D2vTri> d2v_d1e89c;
struct D2vStatSet : vector<int> { D2vStatSet(); char pad10[0x10]; };	// NOTE: placeholder name (size 0x20)
extern vector<D2vStatSet *> d2v_d2c65c;
void logFatal(string module, string message);
void logError(string module, string message);
void logWarning(string module, string message);
extern int d2v_cf64a8, d2v_cf47fc, d2v_cf462c, d2v_cf64e0, d2v_d28d64;
struct D2vLocInfo { char pad0[3]; bool flag3; char pad4[2]; };	// NOTE: placeholder layout (size 6)
extern D2vLocInfo d2v_b90180[];
struct D2vSpawnInfo { int low; int high; int unknown8; int unknownc; char pad10[0x28 - 0x10]; };	// NOTE: placeholder layout
extern D2vSpawnInfo d2v_b939a0[];
class D2vClock { public: void start_416920(); };
extern D2vClock *d2v_cefa9c;
extern Console *d2v_cec074, *d2v_cec078, *d2v_cec07c, *d2v_cec084, *d2v_cec08c;
extern void *d2v_cec0b0;
class D2vParts : public Console { public: void open_894120(int a); };	// NOTE: placeholder name
extern D2vParts *d2v_cec088;
void unknown4b3540(XConsole *console);
Pos unknown4b33b0();
class D2vMapAnim : public Console { public: D2vMapAnim(); char pad6c[0x74 - 0x6c]; };	// NOTE: placeholder name
extern bool d2v_cf4d14, d2v_cf4d15;
extern int d2v_cf471c[];
extern string d2v_d29820[], d2v_d38dd0[], d2v_d378d0[];
class D2vBubble { public: void bubble(int a); };	// NOTE: placeholder name
extern D2vBubble *d2v_cec058;
class D2vLog { public: void scrollToEnd_7b4f10(); };	// NOTE: placeholder name
extern D2vLog *d2v_cec0b4;
bool opS2_showMessage_5111e0(int id, const string *text, int a, int b, D2vHE e1, D2vHE e2, int c, int d);
#define D2V_SHOW(id, text) do { if (opS2_showMessage_5111e0(id, text, 0, 0, D2vHE(), D2vHE(), 0, 0)) d2v_cec058->bubble(1); d2v_cec0b4->scrollToEnd_7b4f10(); } while (0)
#define D2V_MESSAGE(text) D2V_SHOW(0x323, text)
class D2vSound { public: void unknown451400(int a); };	// NOTE: placeholder name
extern D2vSound d2v_cf1080;
void opR1d_4541b0(int a, int b, int c);
#define D2V_ALERT(text) do { d2v_cf1080.unknown451400(0); if (0) opR1d_4541b0(-1, 0, 0); D2V_SHOW(0x324, &string(text)); d2v_cec0b4->scrollToEnd_7b4f10(); } while (0)
string opw8_countString(int count, const string &noun);
string OpY1_intToStringSigned(int value);
string OpR5f_toUpper_4083a0(const string &text);
bool OpS8d_anyNegative(int *values, unsigned int count);
struct D2vBuilder { bool active; void unknown69e700(int a, int b, float value); };	// NOTE: placeholder name
extern D2vBuilder d2v_d25450;
class D2vOnce { public: void showOnce(int id, bool flag, int a, int b, int c); };	// NOTE: placeholder name
extern D2vOnce *d2v_cefaa8;
extern const float d2v_c36ecc;
string OpY1_floatToStringSigned(float value, int a, int b);
string floatToString(float value, int a, int b);
extern int d2v_d1eb68, d2v_d1eb6c, d2v_d1eb54, d2v_cf4b20;
extern D2vHI d2v_d1ebd8;
class RNG { public: bool chance(int percent); int rangeInt(float low, float high); };
class D2vRNG { public: D2vRNG() throw(); ~D2vRNG(); int seed(int value) throw(); int rangeInt(float low, float high) throw(); int pad0[0x9cc / 4]; };	// NOTE: placeholder name (RNG)
extern RNG rng;
extern const float d2v_c36e30, d2v_c36fbc;

void OpS8c_copyInts(int *dest, int *src, unsigned int count);
int OpV4c_Fn9d0ca0(int *values, unsigned int count);
bool OpV4c_Fn9d3f40(int *values, unsigned int count);
int OpX5_minInt(int a, int b);
void d2v_eraseStep(vector<D2vHI> &list, unsigned int &index);
void d2v_eraseAt(vector<D2vHE> &list, int index);
void d2v_eraseAtInt(vector<int> &list, unsigned int &index);
void d2v_deleteAndStep(vector<D2vSwap *> &list, unsigned int &index);
bool d2v_containsEntity(vector<D2vHE> &list, D2vHE entity);
int d2v_randomIndex(vector<struct D2vTotals *> &list);
bool d2v_addUnique(vector<int> &list, int value);
int OpQ1_distanceCeil(Pos *a, Pos *b);
void opW5_message(int id, D2vHE entity, const string &text, int extra);

template <class T> class D2vWL	// NOTE: placeholder name (weighted list)
{
public:
	vector<T> values;
	vector<int> weights;
	int total;
	D2vWL(vector<int> &weights_);
	~D2vWL();
	T &pick();
};

class D2Evolve6 : public Console
{
public:
	virtual void update();
	virtual void close();

	unsigned int unknown98c130();	// NOTE: placeholder name

	D2vHL location;
	int count;
	int unknown74;
	bool unknown78;
	D2vMain *unknown7c;
	int unknown80[4];
	int unknown90[4];
	Rect unknowna0;
	XConsole *art;
	Console *secondary;
	Rect unknownb8;
	unsigned int unknownc8;
	bool unknowncc;
	bool flag;
};

void D2Evolve6::update()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
		break;
	case 3:
		((D2vEngine *)engine)->update();
		if (unknown78)
		{
			if (unknown7c)
			{
				d2v_cefc4c->getPlayer()->unknown45b100(unknown7c->slots);
				OpS8c_copyInts(unknown7c->slots, unknown90, 4);
				D2vHE player = d2v_cefc4c->getEntity671();
				if (player.isValid())
				{
					for (int n = OpV4c_Fn9d0ca0(unknown7c->slots, 4); n > 0; n--)
					{
						int count = 0;
						vector<int> weights(4u, 0);
						for (int i = 0; i < 4; i++)
						{
							weights[i] = d2v_ba7aec[i];
							if (i != 2)
							{
								int amount = (player->getRoomCount(i) - player->gen_9b4350()->rooms[i]) * -d2v_ba7afc[i];
								amount = OpX5_minInt(amount, weights[i]);
								weights[i] -= amount;
								count += amount;
							}
						}
						weights[2] += count;
						if (player->getRoomCount(0) >= player->getRoomCount(1) - 1)
							weights[0] = 1;
						for (int i = 0; i < 4; i++)
						{
							if (weights[i] <= 0)
								weights[i] = 1;
						}
						D2vWL<int> list(weights);
						int slot = list.pick();
						player->unknown45a840()[slot]++;
						d2v_cefb48->type = slot;
						d2v_d2c658.add4729d0(0x446, 1, "", -1);
						d2v_d2c658.add4729d0(slot + 0x447, 1, "", -1);
					}
					int heat = this->count * 150;
					player->unknown5dea60(player->unknown5ca260(0));
					player->setField_4514c0(player->unknown5cab30());
					player->set_5b6d00(0);
				}
			}
			else if (d2v_cefb48)
				d2v_cefb48->type = 4;
			close();
		}
		else if (!unknown7c)
		{
			Rect rect(unknowna0);
			rect.x -= art->getPos().x;
			rect.y -= art->getPos().y;
			rect.x--;
			rect.y--;
			rect.width /= 2;
			rect.width += 2;
			rect.height += 2;
			int y0 = rect.y;
			int y2 = rect.y + rect.height - 1;
			int x0, x2;
			for (int x = rect.x; x <= rect.x2(); x++)
			{
				if (art->getBack(x, y0) != *d2v_d20cfc || art->getBack(x, y2) != *d2v_d20cfc)
					goto ready;
			}
			x0 = rect.x;
			x2 = rect.x + rect.width - 1;
			for (int y = rect.y; y <= rect.y2(); y++)
			{
				if (art->getBack(x0, y) != *d2v_d20cfc || art->getBack(x2, y) != *d2v_d20cfc)
					goto ready;
			}
			break;
		ready:
			unknown7c = new D2vMain(this, unknowna0, unknown74);
			unknownb8.x = d2v_d25e80;
			unknownb8.x += (d2v_d223f0.unknown418980() - 0xa0) / 2 / 2;
			unknownb8.y = d2v_d25e84;
			unknownb8.width = 0x19;
			unknownb8.height = getHeight() - unknownb8.y;
			secondary = new Console(this, unknownb8, 2, false, -1);
			secondary->animate("A_CEvolveSecondary");
			secondary->resetBack_418450();
		}
		else if (secondary && !secondary->engine->hasItems())
		{
			if (secondary)
			{
				removeSubconsole(secondary);
				secondary = 0;
			}
			switch (d2v_bcded4[d2v_d1e888.get23c()->depth])
			{
			case 0:
				new D2vAnalyzing(this, unknownb8);
				break;
			case 1:
				new D2vSequencing(this, unknownb8);
				break;
			case 2:
				new D2vQuantum(this, unknownb8);
				break;
			}
		}
		else if (unknownc8 && d2v_caed20 >= unknownc8)
		{
			new D2vAnomaly(this, !unknowncc);
			unknownc8 = unknown98c130();
			unknowncc = true;
		}
		break;
	case 4:
	{
		unknown60 = 0;
		d2v_cefa8c->popFrame();
		setHidden(true);
		d2v_cec034->setHidden(false);
		d2v_cefc4c->unknown735620();
		vector<D2vHI> &vec = d2v_cf4944;
		for (unsigned int i = 0; i < vec.size(); i++)
		{
			if (vec[i].operator->() && vec[i]->f_9b4b50() == -1)
			{
				if (vec[i]->unknown457b50().isValid() && vec[i]->unknown457b50()->isPlayer() && vec[i]->getType() == 4)
					continue;
				d2v_d2c658.add4729d0(0x9d, 1, "", -1);
				d2v_d2c658.add4729d0(vec[i]->stats_9b4350()->flag1af ? 0xa2 : vec[i]->nested_4578a0() + 0x9e, 1, "", -1);
				d2v_eraseStep(vec, i);
			}
		}
		switch (d2v_d1e888.get23c()->type)
		{
		case 11:
			if (d2v_cefc4c->unknown4638e0(0, 10) == 2)
			{
				D2vHE optimus = d2v_cefc4c->unknown7152d0(10, "Optimus");
				if (optimus.isValid() && (d2v_cefc4c->unknown4631f0(optimus) || OpQ1_distanceCeil(d2v_cefc4c->getPlayer()->getPosition(), optimus->getPosition()) <= 7))
					opW5_message(0x320, D2vHE(), string("Optimus: \"Good luck, agent. We are one.\""), 0);
			}
			break;
		}
		d2v_d33a3c = d2v_cf4ac8 && d2v_cf4ac8->map.operator->() ? d2v_cf4ac8->map->getWidth_9fcd80() : d2v_cefb70;
		for (unsigned int i = 0; i < d2v_cf4aa8.size(); i++)
		{
			if (!d2v_cf4aa8[i].operator->())
			{
				d2v_eraseAt(d2v_cf4aa8, i);
				d2v_eraseAtInt(d2v_cf4ab8, i);
			}
			else
				d2v_d33a40.push_back(d2v_cf4aa8[i]->getWidth_9fcd80());
		}
		d2v_cf45d8.loadPartSlots(1, unknown90);
		if (OpV4c_Fn9d3f40(unknown90, 4))
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0, id = d2v_cf4750[i].back()->id + 1; j < unknown90[i]; j++, id++)
					d2v_cf4750[i].push_back(static_cast<D2vMarker *&&>(new D2vSlot(id, 0, D2vHE(), 0, D2vHE())));
			}
		}
		for (unsigned int i = 0; i < d2v_cf4760.size(); i++)
		{
			if (!d2v_cf4760[i]->isPlayerSwap())
				d2v_deleteAndStep(d2v_cf4760, i);
			else
			{
				d2v_cf4760[i]->item8 = d2v_cf4760[i]->h0.operator->();
				d2v_cf4760[i]->itemc = d2v_cf4760[i]->h4.operator->();
				d2v_cf4760[i]->h0.resetField();
				d2v_cf4760[i]->h4.resetField();
			}
		}
		d2v_d338e4.init(d2v_cefc4c->getPlayer(), 0);
		d2v_cf4944.clear();
		d2v_d3392c.clear();
		for (unsigned int i = 0; i < d2v_cf4a38.size(); i++)
			d2v_d3392c.push_back(d2v_d2a298.release(d2v_cf4a38[i]->owner_45a260()));
		d2v_cf4a38.clear();
		d2v_d3393c.clear();
		for (unsigned int i = 0; i < d2v_cf4a48.size(); i++)
			d2v_d3393c.push_back(d2v_d2a298.release(d2v_cf4a48[i]->owner_45a260()));
		d2v_cf4a48.clear();
		int level = location.get23c()->type == 12 ? 20 : 7;
		for (int i = 0; i < 15; i++)
		{
			if (d2v_cefc4c->unknown463890(i).get230()->getField_45e360())
			{
				vector<D2vHE> *members = d2v_cefc4c->unknown463890(i).get230()->getFore_416f40();
				for (unsigned int j = 0; j < members->size(); j++)
				{
					if ((*members)[j] != d2v_d338e8->unknown45a260() && (*members)[j]->unknown5c83d0(d2v_d338e8->getPosition(), level)
						&& !(*members)[j]->unknown5d1280(0) && (*members)[j]->getTarget() < 6 && (*members)[j]->getTarget() != 5
						&& !(*members)[j]->unknown45b590()->unknown4590b0(0x42) && !(*members)[j]->unknown45b590()->unknown4590b0(0x43)
						&& !(*members)[j]->unknown45b590()->unknown4590b0(0x44))
					{
						if (location.get23c()->type != 12)
						{
							if ((*members)[j]->getName() == "AZ-K3N")
								opW5_message(0x320, D2vHE(), string("AZ-K3N: \"You go on ahead without me. I'm going to hang out here a little longer.\""), 0);
							else
							{
								D2vNode node(false);
								d2v_d3394c[i].push_back(node);
								d2v_d3394c[i].back().init((*members)[j], 0);
							}
						}
						else if ((*members)[j]->getSize() == 1 && !d2v_containsEntity(d2v_cf4aa8, (*members)[j]))
						{
							d2v_d1e97c[i].push_back(static_cast<D2vSnap *&&>(new D2vNode(true)));
							d2v_d1e97c[i].back()->init((*members)[j], 1);
							d2v_d1ea6c[i]++;
						}
					}
				}
			}
		}
		if (!d2v_cf45d8.getField_46dd90())
		{
			for (int n = rng.rangeInt(d2v_c36e30, d2v_c36fbc); n > 0; n--)
			{
				int index = d2v_randomIndex(d2v_d25de0);
				if (d2v_d25de0[index]->total != d2v_d25de0[index]->getTotal459ef0())
				{
					d2v_cefb74 = 1;
					break;
				}
			}
		}
		switch (d2v_d1e888.get23c()->type)
		{
		case 8:
			if (d2v_d1eac0 == 0 || d2v_d1eac0 == 1)
			{
				vector<int> prototypes;
				for (unsigned int i = 0; i < d2v_d338f8.size(); i++)
				{
					if (d2v_d338f8[i]->getEffect(0x63))
						d2v_addUnique(prototypes, d2v_d338f8[i]->getNestedField());
				}
				for (int i = 0; i < 15; i++)
				{
					for (unsigned int j = 0; j < d2v_d3394c[i].size(); j++)
					{
						for (unsigned int k = 0; k < d2v_d3394c[i][j].items.size(); k++)
						{
							if (d2v_d3394c[i][j].items[k]->getEffect(0x63))
								d2v_addUnique(prototypes, d2v_d3394c[i][j].items[k]->getNestedField());
						}
					}
				}
				for (unsigned int i = 0; i < d2v_d3392c.size(); i++)
				{
					if (d2v_d3392c[i]->getEffect(0x63))
						d2v_addUnique(prototypes, d2v_d3392c[i]->getNestedField());
				}
				for (unsigned int i = 0; i < d2v_d3393c.size(); i++)
				{
					if (d2v_d3393c[i]->getEffect(0x63))
						d2v_addUnique(prototypes, d2v_d3393c[i]->getNestedField());
				}
				if (!prototypes.empty())
				{
					d2v_d1e860.setEntryText("exiPrototypesTaken_g", intToString(prototypes.size()));
					string text;
					if (prototypes.size() == 1)
						text = "Left Exiles lab with " + d2v_d2d1c4[prototypes.front()]->name;
					else
					{
						text = "Stole " + opR1d_4550d0(prototypes.size()) + " prototypes: ";
						for (unsigned int i = 0; i < prototypes.size(); i++)
						{
							if (i != 0)
								text += ", ";
							text += d2v_d2d1c4[prototypes[i]]->name;
						}
					}
					do
					{
						opS2_logPhrase_5141b0(0x133, text, 0, 0, D2vHE(), 0);
					} while (0);
				}
			}
			break;
		case 15:
			if (d2v_cf4d70 >= 20 && (*d2v_d2c65c.back())[0x402] >= 75)
				d2v_cf45d8.unknown77fbc0(0x11a);
			break;
		case 10:
		{
			if (!stringToInt(d2v_d1e860.getEntryText("recScraplabLockedDown_g")))
			{
				bool stolen = false;
				for (unsigned int i = 0; i < d2v_d338f8.size(); i++)
				{
					if (d2v_d338f8[i]->name_457860() == "SUBCON Basin")
					{
						stolen = true;
						break;
					}
				}
				if (!stolen && stringToInt(d2v_d1e860.getEntryText("recScraplabMentionedBasin_g")))
				{
					for (int x = d2v_d1eaf8; x <= d2v_d1eb00; x++)
					{
						for (int y = d2v_d1eafc; y <= d2v_d1eb04; y++)
						{
							if ((*d2v_cfd44c.at(x, y))->getItem().isValid() && (*d2v_cfd44c.at(x, y))->getItem()->name_457860() == "SUBCON Basin"
								&& (*d2v_cfd44c.at(x, y))->getItem()->getEffectValue(0x7c))
								goto checked;
						}
					}
					stolen = true;
				}
			checked:
				if (stolen)
					d2v_d1e860.setEntryText("recStoleSubconBasin_g", intToString(1));
			}
			vector<D2vHE> *members = d2v_cefc4c->unknown463890(9).get230()->getFore_416f40();
			for (unsigned int i = 0; i < members->size(); i++)
			{
				d2v_d1e97c[9].push_back(static_cast<D2vSnap *&&>(new D2vNode(true)));
				d2v_d1e97c[9].back()->init((*members)[i], 2);
				d2v_d1ea6c[9]++;
			}
			break;
		}
		case 14:
		{
			vector<D2vHE> *members = d2v_cefc4c->unknown463890(9).get230()->getFore_416f40();
			for (unsigned int i = 0; i < members->size(); i++)
			{
				if ((*members)[i]->unknown45ad20("DSF_Warlord_Ready"))
				{
					d2v_d1e97c[9].push_back(static_cast<D2vSnap *&&>(new D2vNode(true)));
					d2v_d1e97c[9].back()->init((*members)[i], 3);
					d2v_d1ea6c[9]++;
				}
			}
			break;
		}
		case 21:
		{
			vector<D2vHE> *members = d2v_cefc4c->unknown463890(4).get230()->getFore_416f40();
			for (unsigned int i = 0; i < members->size(); i++)
			{
				if ((*members)[i]->getFaction() == 0x59)
				{
					if ((*members)[i]->getPosition()->test_409cb0(9, 11))
						goto hostile;
					break;
				}
			}
			d2v_d1e860.setEntryText("datHostileToDataMiner_g", intToString(1));
		hostile:
			break;
		}
		case 30:
		case 31:
			if (d2v_d1eacc)
				d2v_cf45d8.unknown77fbc0(0x155);
			break;
		case 33:
			if (d2v_cefc4c->unknown4646b0()->empty() && !stringToInt(d2v_d1e860.getEntryText("scrOptimusDestroyed_g")))
				d2v_d2c658.add472b90(0x4d, -999999);
			break;
		}
		string text;
		if (location.get23c()->type == d2v_d1e888.get23c()->type)
			text += "another " + d2v_mapNames_cfaca0[location.get23c()->type] + " area";
		else
			text = d2v_mapNames_cfaca0[location.get23c()->type];
		do
		{
			opS2_logPhrase_5141b0(1, text, 0, 0, D2vHE(), 0);
		} while (0);
		d2v_cf4d10 = d2v_cf4d00.size();
		d2v_d338e0 = d2v_cefc4c->resources.get234()->release_resources();
		vector<D2vRecord *> *events = d2v_cefc4c->getRecords_462e10();
		for (unsigned int i = 0; i < events->size(); i++)
		{
			if ((*events)[i]->location == location)
			{
				d2v_appendA(d2v_d33a50, (*events)[i]->list20);
				d2v_appendA(d2v_d33a60, (*events)[i]->list30);
				d2v_appendB(d2v_d33a70, (*events)[i]->list40);
				d2v_appendC(d2v_d33a80, (*events)[i]->list50);
			}
		}
		if (d2v_d1e888.get23c()->type != 13)
			d2v_d1eb98 = false;
		d2v_d1ea9c[d2v_d1e860.getDepthIndex()] += d2v_cefc4c->unknown71abf0(0);
		for (unsigned int i = 0; i < events->size(); i++)
		{
			if ((*events)[i]->type != 4)
			{
				if ((*events)[i]->flagd)
					d2v_d1e888.get23c()->list40.push_back((*events)[i]->location);
				if ((*events)[i]->flage)
					d2v_d1e888.get23c()->list50.push_back((*events)[i]->location);
			}
		}
		d2v_d20404.clearAll(true);
		d2v_d2f288.clearAll(true);
		d2v_d208d4.clearAll(true);
		d2v_d21720.clearAll(true);
		d2v_d1e720.clearAll(true);
		d2v_d2a298.clearAll(true);
		d2v_cfac14.clearAll(true);
		delete d2v_cefc4c;
		d2v_cefc4c = 0;
		delete d2v_cefc50;
		d2v_cefc50 = 0;
		d2v_cefbc6 = false;
		d2v_cf6428.clear674a80();
		if (d2v_cec068)
			d2v_cefc71 = d2v_cec068->unknown70;
		d2v_cec054->unknown7fe7a0();
		d2v_cec034->unknown987fd0();
		d2v_cefc4c = new D2vMap();
		D2vHL previous = d2v_d1e888;
		d2v_d1e888 = location;
		d2v_d1e88c.push_back(location);
		d2v_d1e89c.push_back(D2vTri());
		d2v_d2c65c.push_back(new D2vStatSet());
		int attempts = 0;
		while (true)
		{
			attempts++;
			if (d2v_cefc4c->initilize())
				break;
			else
			{
				if (attempts >= 1000)
					logFatal("CEvolve", "Failed to reinitialize BS");
				else if (attempts == 25)
					logError("CEvolve", "Unusual number of mapgen fails!");
				else if (attempts < 4)
					logWarning("CEvolve", "Guaranteed content unconfirmed, regenerating");
				d2v_d20404.clearAll(true);
				d2v_d2f288.clearAll(true);
				d2v_d208d4.clearAll(true);
				d2v_d21720.clearAll(true);
				d2v_d1e720.clearAll(true);
				d2v_d2a298.clearAll(true);
				d2v_cfac14.clearAll(true);
				delete d2v_cefc4c;
				d2v_cefc4c = 0;
				d2v_cf6428.clear674a80();
				d2v_cefc4c = new D2vMap();
				D2vRNG seeder;
				seeder.seed(d2v_d1e888.get23c_nt()->seed);
				d2v_d1e888.get23c_nt()->seed = seeder.rangeInt(1.0f, (float)numeric_limits<int>::max());
			}
		}
		d2v_cefc50 = new D2vAnimPool();
		d2v_cf6428.resetSurgicalTimer();
		d2v_cf64a8 = d2v_cf47fc;
		if (d2v_b90180[location.get23c()->type].flag3 && d2v_b939a0[location.get23c()->getDepthIndex()].unknownc != 0 && d2v_cf462c != 4 && d2v_cf462c != 2)
			d2v_cf64e0 = d2v_cefc4c->getTurn() + rng.rangeInt(d2v_b939a0[location.get23c()->getDepthIndex()].low, d2v_b939a0[location.get23c()->getDepthIndex()].high);
		d2v_cec054->reset_7f5fd0(0);
		d2v_cefa9c->start_416920();
		d2v_cec074->open();
		if (!d2v_cec0b0)
			d2v_cec034->unknown987ea0();
		if (!d2v_cec088)
			d2v_cec034->unknown988270();
		d2v_cec034->unknown987b10(d2v_d28d64);
		d2v_cec078->open();
		d2v_cec07c->open();
		d2v_cec084->open();
		unknown4b3540(d2v_cec034);
		d2v_cec088->open_894120(0);
		d2v_cec08c->setPos(unknown4b33b0());
		d2v_cec08c->open();
		d2v_cec054->unknown8069e0(d2v_cefc4c->getPlayer()->unknown45a4c0(), false);
		Console *anim = new D2vMapAnim();
		anim->open();
		if (OpV4c_Fn9d3f40(unknown90, 4))
		{
			for (int i = 0; i < 4; i++)
			{
				d2v_d2c658.add4729d0(0x6b, unknown90[i], "", -1);
				d2v_d2c658.add4729d0(i + 0x6c, unknown90[i], "", -1);
			}
			if (unknown90[0] > 0 || unknown90[1] > 0 || unknown90[3] > 0)
				d2v_cf4d14 = false;
			if (d2v_cefc4c->getPlayer()->getRoomCount(2) > 4)
				d2v_cf4d15 = false;
			for (int i = 0; i < 12; i++)
			{
				if (d2v_cf471c[i] != 0 && !d2v_d29820[i].empty())
					D2V_MESSAGE(&d2v_d29820[i]);
			}
			string results;
			string desc;
			if (d2v_cf471c[0] != 0)
			{
				results = "RESULTS=";
				desc = "Devolved, losing " + opw8_countString(-OpV4c_Fn9d0ca0(unknown90, 4), "slot") + ": ";
				for (int i = 0, num = 0; i < 4; i++)
				{
					if (unknown90[i] != 0)
					{
						if (num != 0)
						{
							results += ",";
							desc += ", ";
						}
						results += intToString(unknown90[i]) + "x" + d2v_d38dd0[i];
						desc += d2v_d378d0[i] + " x" + intToString(unknown90[i]);
						num++;
					}
				}
			}
			else
			{
				results = "PARAMETERS=";
				desc = "Evolved " + opw8_countString(OpV4c_Fn9d0ca0(unknown90, 4), "slot");
				if (OpS8d_anyNegative(unknown90, 4))
					desc += " (calibrated)";
				desc += ": ";
				for (int i = 0, num = 0; i < 4; i++)
				{
					if (unknown90[i] != 0)
					{
						if (num != 0)
						{
							results += ",";
							desc += ", ";
						}
						results += d2v_d38dd0[i] + OpY1_intToStringSigned(unknown90[i]);
						if (unknown90[i] < 0)
							desc += "-";
						desc += d2v_d378d0[i] + " x" + intToString(abs(unknown90[i]));
						num++;
					}
				}
			}
			D2V_MESSAGE(&results);
			do
			{
				opS2_logPhrase_5141b0(2, desc, 0, 0, D2vHE(), 0);
			} while (0);
			if (d2v_d25450.active && unknown90[3] > 0)
			{
				int bonus = 0;
				int num = d2v_cefc4c->getPlayer()->getRoomCount(3);
				for (int k = num, j = 0; k > 2 && j < unknown90[3]; k--, j++)
					bonus += k - 2;
				d2v_d25450.unknown69e700(7, 3, (float)bonus);
			}
			d2v_cefaa8->showOnce(0x4c, true, 0, 0, 0);
			if (d2v_cefb48 && !OpS8d_anyNegative(unknown90, 4))
			{
				do
					d2v_cefb48->slot = rng.rangeInt(0, d2v_c36ecc);
				while (unknown90[d2v_cefb48->slot] == 0);
			}
			if (d2v_cf4ac8)
				d2v_cf4ac8->unknown30->flag24 = unknown90[3] > 0;
		}
		else if (d2v_cefb48)
			d2v_cefb48->slot = 4;
		string line = "LOCATION=" + (d2v_d1e888.get23c()->known ? OpR5f_toUpper_4083a0(d2v_mapNames_cfaca0[d2v_d1e888.get23c()->type]) : string("UNKNOWN"));
		D2V_MESSAGE(&line);
		if (d2v_cefc4c->unknown463d40())
		{
			string heat = "AMBIENT_HEAT=" + OpY1_intToStringSigned(d2v_cefc4c->unknown463d40());
			D2V_MESSAGE(&heat);
		}
		D2V_MESSAGE(&string("GOAL=ESCAPE"));
		if (d2v_cefc4c->unknown463e30())
		{
			int lost = d2v_cefc4c->unknown463e30();
			string message = intToString(lost) + (lost == 1 ? " ally" : " allies") + " did not survive the journey.";
			D2V_MESSAGE(&message);
		}
		if (d2v_d25450.active && d2v_d1e888.get23c()->type == 13 && d2v_cefc4c->getPlayer()->unknown45a880() <= 20)
			d2v_d25450.unknown69e700(0x48, 0, 0);
		if (d2v_cf462c != 11 || !d2v_cf45d8.unknown77f260(100))
		{
			if (previous.get23c()->type == 1)
				D2V_ALERT("ALERT: A rogue bot has emerged from the scrapyard. Terminate on contact.");
			else if (d2v_d1e888.get23c()->type == 0x22)
				D2V_ALERT("ALERT: Rogue bot within command proximity. Terminate immediately.");
		}
		if (d2v_d1e888.get23c()->type == 7 && d2v_d1e888.get23c()->find_46ee80(8).isValid())
			opW5_message(0x320, D2vHE(), string("Something is scanning the area."), 0);
		if (d2v_d25450.active)
		{
			string quip;
			switch (d2v_d1e888.get23c()->type)
			{
			case 8:
				quip = "I love this gang.";
				break;
			case 11:
				quip = rng.chance(50) ? "I have a feeling that chaos is soon to play out on its own here." : "Chaos is in the air, and without my help? Amazing!";
				break;
			case 20:
				quip = "Some robots deserve peace and quiet. Not you, of course. You're not even a robot.";
				break;
			case 21:
				quip = "Nerd alert. I'll sit this one out.";
				break;
			case 23:
				quip = rng.chance(50) ? "I sense a wave of fun already headed in this general direction." : "Warlord's base? Or a cradle of chaos? Perhaps it's both.";
				break;
			case 22:
				quip = "A pressing matter diverts X0-1V1's attention.";
				break;
			}
			if (!quip.empty())
			{
				if (d2v_d1e888.get23c()->type != 0x16)
				{
					quip.insert(0, "X0-1V1: \"");
					quip += "\"";
				}
				D2V_SHOW(0x2b5, &quip);
			}
		}
		if (d2v_d1ebd8.isValid() && (d2v_d1e888.get23c()->type == 0x1e || d2v_d1e888.get23c()->type == 0x1f || d2v_d1e888.get23c()->type == 5))
			D2V_ALERT("ALERT: Research battle spillover possible. Maintaining heightened patrol presence.");
		if (d2v_d1e888.get23c()->patrols)
			D2V_MESSAGE(&string("Referencing patrol navigation protocols."));
		if (d2v_d1e860.isFlagEnabledA())
			D2V_SHOW(0x2b2, 0);
		if (d2v_d1e860.isFlagEnabledB() && d2v_cefc4c->getPlayer()->unknown5d2a00(0xd2))
		{
			string multiplier;
			string bonus;
			if (d2v_d1eb68 == d2v_d1eb6c)
				multiplier = "+0";
			else
				multiplier = OpY1_floatToStringSigned((float)((d2v_d1eb68 - d2v_d1eb6c) / 100.0), 2, 2);
			bonus = floatToString((float)((d2v_d1eb68 + 100) / 100.0), 2, 2);
			string message = "Encrypted Comm Update: Reported force multiplier " + multiplier + " (" + bonus + ").";
			message += "\nPerformance level: ";
			if (d2v_d1eb68 >= 40)
				message += "S";
			else if (d2v_d1eb68 >= 30)
				message += "A";
			else if (d2v_d1eb68 >= 20)
				message += "B";
			else if (d2v_d1eb68 >= 10)
				message += "C";
			else
				message += "D";
			message += "-Tier.";
			D2V_MESSAGE(&message);
			if (d2v_d1eb68 >= 40)
				d2v_cf45d8.unknown77fbc0(0x152);
			d2v_d1eb6c = d2v_d1eb68;
		}
		if (stringToInt(d2v_d1e860.getEntryText("garCommArraySupport_g")))
			d2v_d2c658.add4729d0(0x398, d2v_d1eb68, "", -1);
		if (d2v_cf4b20 != 0 && !stringToInt(d2v_d1e860.getEntryText("scrAttackedLocals_g")) && !stringToInt(d2v_d1e860.getEntryText("scrOptimusDestroyed_g")))
			d2v_d2c658.add4729d0(0x397, d2v_d1eb54, "", -1);
		if (previous.get23c()->type == 12 || (previous.get23c()->type == 13 && d2v_d1e88c.size() > 3 && location.get23c()->depth == d2v_d1e88c[d2v_d1e88c.size() - 3].get23c()->depth))
			d2v_cefaa8->showOnce(0x4d, true, 0, 0, 0);
		if (previous.get23c()->type == 2 && previous.get23c()->depth == 9 && location.get23c()->type == 2 && location.get23c()->depth == 8)
			d2v_cefaa8->showOnce(0x4e, true, 0, 0, 0);
		d2v_d223f0.getHighlighter_4ab670()->removeSubconsole(this);
		return;
	}
	}
	Console::update();
}
