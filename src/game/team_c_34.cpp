// team_c_34: CEnding::update (0x998880): steps the ending cutscene, one stage per CEnding::f70 value
// NOTE: class/member names are placeholders (f<offset>); helper classes and globals are private placeholders
#include <string>
#include <vector>
using namespace std;

struct Point { int x; int y; Point(); Point(int x_, int y_); Point(const Point &p); Point(const Point &p, int dx, int dy); void set(int x_, int y_); void assign(const Point &p); Point operator+(const Point &p) const; };	// NOTE: placeholder
struct Pos : Point { Pos(int v); };	// NOTE: placeholder
struct XColor { unsigned char r; unsigned char g; unsigned char b; XColor(const XColor &c); bool operator!=(XColor c); };
struct C34_Area { Point min; Point max; C34_Area(int x1, int y1, int x2, int y2); int width(); int height(); };	// NOTE: placeholder (0x40b670/0x40b690)
struct C34_Box { char pad[16]; C34_Box(int x1, int y1, int x2, int y2); int width(); int height(); };	// NOTE: placeholder (OpQ1_Box)
struct Y8_10_00_0 { char pad[16]; };
struct C34_Cell { XColor *getBack(); int getChar(); };	// NOTE: placeholder
struct C34_Grid { int getWidth(); int getHeight(); C34_Cell *at(int x, int y); };	// NOTE: placeholder (Array2D<XCell>)
struct C34_Image { vector<C34_Grid *> layers; ~C34_Image(); void load(const string &file, int font, const Pos &offset, int width, int height); };	// NOTE: placeholder (AsciiImage)
struct C34_Engine { void update(); void unknown50ff80(C34_Engine *other); };	// NOTE: placeholder
struct C34_Screen { class XConsole *getConsole(); int unknown418980(); };	// NOTE: placeholder (0xd223f0)
struct C34_Entry { char pad[0x34]; int f34; char pad38[0x68 - 0x38]; int f68; };
struct OpQ5_U9d7710 { char pad[0x15c]; C34_Entry *f15c; };
struct C34_GameData { const string &getEntryText(const string &name); };
struct C34_Flags { int delegate(int id); };

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
	void clear();
	void clear(int x, int y, int width, int height);
	void setForeAll_4183d0(XColor color);
	void setBackAll_418410(XColor color);
	void resetBack_418450();
	void setBack(int x, int y, int width, int height, XColor color);
	void setChar_417f50(int x, int y, int c);
	void print(int x, int y, const string &text);
	int getWidth();
	int getHeight();
	Pos getPos();
	void setPos(int x, int y);
	void setHidden(bool hidden);
	void removeSubconsole(XConsole *console);
	void deleteSubconsoles();
	void unknown429f10(int a, int b);
	void unknown429fe0(XConsole *console, const Point &pos, int flag);
	void setDuration(int v);	// NOTE: placeholder (folded setter)

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);
	void addEffect_48c460(int id, const Point &pos);
	void addEffect_48c4a0(int id, const Point &a, const Point &b);
	void stopAll_48c650();

	int f60;
	C34_Engine *f64;
	void *f68;
};

class ConsoleArt : public Console
{
public:
	ConsoleArt(XConsole *parent, const string &file, int x, int y, bool hidden, int layer, int frame, const Point &offset, int width, int height);
	vector<C34_Grid *> f6c;
	char pad7c[0x84 - 0x7c];
};

class CText : public Console { public: CText(XConsole *parent, const Point &pos, const string &text, int font, int maxWidth, int layer); char pad6c[0x88 - 0x6c]; };
class CTorRepairValue : public Console { public: CTorRepairValue(XConsole *parent, const Point &pos, int type, int layer); char pad6c[0x74 - 0x6c]; };
class CTorShieldValue : public Console { public: CTorShieldValue(XConsole *parent, const Point &pos, int type, int layer); char pad6c[0x74 - 0x6c]; };
class CEndingFade : public Console { public: CEndingFade(XConsole *parent, unsigned int duration, bool shake, bool planet, int layer); char pad6c[0xa0 - 0x6c]; };
class CSurrenderPriority : public Console { public: CSurrenderPriority(XConsole *parent, int index, const Point &pos, int layer); char pad6c[0x84 - 0x6c]; };
class CCycleCounter : public Console { public: CCycleCounter(XConsole *parent, const Point &pos, unsigned int time, int layer); char pad6c[0x70 - 0x6c]; };
class C34_Fleet : public Console { public: C34_Fleet(XConsole *parent, int index, const Point &pos, int layer); char pad6c[0x80 - 0x6c]; };	// NOTE: placeholder (0x997140)	// NOTE: placeholder (0x997140)

class CGameover : public Console { };
extern CGameover *c34_cec144;	// NOTE: placeholder names below
extern XColor *c34_cfe674, *c34_d20cfc;
extern XColor c34_d29804;
extern C34_Area c34_d22318, c34_d2f118, c34_d1da98, c34_d21dc0;
extern Point c34_d31b48, c34_d20ce8, c34_d0155c, c34_cefd70;
extern Point c34_cfb870[];
extern C34_Screen c34_d223f0;
extern C34_GameData c34_d1e860;
extern C34_Flags c34_d2c658;
extern string gameStrings_d2e9c8[];
extern string gameStrings_d2a8b0[];
extern string c34_d2f154, c34_d32154;
extern vector<OpQ5_U9d7710 *> c34_cf35b0;
extern unsigned int c34_caed20;
extern int c34_cf4b38, c34_cf49fc, c34_cf462c, c34_cf39d4;
extern unsigned int c34_bce8d8[], c34_bce924, c34_bce928, c34_bce930, c34_bce950, c34_bce960, c34_bce974, c34_bce9a0;
extern bool c34_bce9b0[], c34_bce818[];
extern int c34_bce830[];
extern int c34_d28c94[];
int halfDiff_437190(int a, int b);
bool OpU8a_lookup1(const string &name, int *value);
void opR1d_4541b0(int a, int b, int c);
string intToString(int v);
int stringToInt(const string &s);
void opY3_playSound(C34_Entry *entry, int a, int volume, int b, int c);
void opC_initLayouts_4b6c40();
bool OpV4c_Fn9d3020(vector<Point> &v, Point p);
template <class T> void OpV4c_shuffle(vector<T> &v);
template <class T> bool OpQ5_findByName(vector<T *> &v, const string &name, T *&out);

class CEnding : public Console
{
public:
	virtual void update();
	void removeConsoles();
	void unknown998590(Point p);
	void unknown9aaf70();

	bool f6c;
	int f70;
	unsigned int f74;
	vector<Console *> f78;
	C34_Image f88;
	vector<Point> f98;
	int fa8;
	vector<bool> fac;
	vector<int> fc0;
	unsigned int fd0;
	C34_Image fd4;
	int fe4;
	bool fe8;
	Console *fec;
	Console *ff0;
	ConsoleArt *ff4;
	ConsoleArt *ff8;
	ConsoleArt *ffc;
	ConsoleArt *f100;
	ConsoleArt *f104;
	vector<ConsoleArt *> f108;
	vector<Console *> f118;
	Console *f128;
	vector<ConsoleArt *> f12c;
	vector<Console *> f13c;
	Console *f14c;
	Console *f150;
	Console *f154;
	ConsoleArt *f158;
	C34_Image f15c;
	vector<Point> f16c;
	ConsoleArt *f17c;
	Console *f180;
	ConsoleArt *f184;
	ConsoleArt *f188;
	vector<Point> f18c;
	unsigned int f19c;
	int f1a0;
	ConsoleArt *f1a4;
	ConsoleArt *f1a8;
	Console *f1ac;
	ConsoleArt *f1b0;
	vector<ConsoleArt *> f1b4;
	vector<Console *> f1c4;
	bool f1d4;
	ConsoleArt *f1d8;
	ConsoleArt *f1dc;
	Console *f1e0;
	vector<Console *> f1e4;
};

void CEnding::update()
{
	if (isHidden())
		return;
	f64->update();
	if ((c34_bce8d8[f70] != 0 && c34_caed20 - f74 >= c34_bce8d8[f70]) || (c34_bce8d8[f70] == 0 && fac[f70]))
	{
	f70 = f70 + 1;
	while (!(c34_bce9b0[f70 * 0xa + c34_cf4b38]))
	{
		f70 = f70 + 1;
	}
	f74 = c34_caed20;
	switch (f70)
	{
	case 1:
		f78.push_back(new CText(this, Point(1, 2), " ANOMALY / SYNCHRONIZING ", 2, 0, 10));
		f78.back()->resetBack_418450();
		f78.back()->animate("A_CEnding_Text");
		break;
	case 2:
		f78.push_back(new CText(this, Point(1, 4), " TOR / LINKING ", 2, 0, 10));
		f78.back()->resetBack_418450();
		f78.back()->animate("A_CEnding_Text");
		opR1d_4541b0(114, 0, 0);
		break;
	case 3:
		f78.push_back(new CText(this, Point(1, 6), " SURFACE_DATA / IMPORTING ", 2, 0, 10));
		f78.back()->resetBack_418450();
		f78.back()->animate("A_CEnding_Text");
		c34_cec144->setHidden(1);
		setBackAll_418410(c34_d29804);
		f88.load(string() + "data/art/" + "ending/tauceti_surface", 4, Pos(-1), 0, 0);
		fd4.load(string() + "data/art/" + "ending/tauceti_tor", 4, Pos(-1), 0, 0);
		fa8 = 0;
		f98.push_back(Point(69, 29));
		f98.push_back(Point(68, 29));
		f98.push_back(Point(67, 29));
		f98.push_back(Point(66, 29));
		f98.push_back(Point(65, 29));
		f98.push_back(Point(64, 29));
		f98.push_back(Point(63, 29));
		f98.push_back(Point(62, 29));
		f98.push_back(Point(61, 29));
		f98.push_back(Point(60, 29));
		f98.push_back(Point(59, 29));
		f98.push_back(Point(58, 29));
		if (c34_cf49fc != 0 && !c34_d2c658.delegate(84) && c34_cf462c != 7)
	{
		f98.push_back(Point(58, 38));
		f98.push_back(Point(58, 37));
		f98.push_back(Point(58, 36));
		f98.push_back(Point(57, 35));
		f98.push_back(Point(57, 34));
		f98.push_back(Point(56, 33));
		f98.push_back(Point(55, 32));
		f98.push_back(Point(54, 31));
		f98.push_back(Point(53, 31));
		f98.push_back(Point(52, 30));
		f98.push_back(Point(51, 30));
	}
	else
	{
		f98.push_back(Point(57, 29));
		f98.push_back(Point(56, 29));
		f98.push_back(Point(55, 29));
		f98.push_back(Point(54, 29));
		f98.push_back(Point(53, 29));
		f98.push_back(Point(52, 29));
		f98.push_back(Point(51, 29));
	}
		f98.push_back(Point(50, 29));
		f98.push_back(Point(49, 29));
		f98.push_back(Point(48, 29));
		f98.push_back(Point(47, 29));
		f98.push_back(Point(46, 29));
		f98.push_back(Point(45, 29));
		f98.push_back(Point(44, 29));
		f98.push_back(Point(43, 29));
		f98.push_back(Point(42, 29));
		f98.push_back(Point(41, 29));
		f98.push_back(Point(40, 29));
		f98.push_back(Point(39, 29));
		f98.push_back(Point(38, 29));
		f98.push_back(Point(37, 29));
		f98.push_back(Point(36, 29));
		f98.push_back(Point(35, 29));
		f98.push_back(Point(34, 29));
		f98.push_back(Point(33, 29));
		f98.push_back(Point(32, 29));
		f98.push_back(Point(31, 29));
		f98.push_back(Point(30, 29));
		f98.push_back(Point(29, 28));
		f98.push_back(Point(28, 28));
		f98.push_back(Point(27, 27));
		f98.push_back(Point(26, 26));
		f98.push_back(Point(25, 25));
		f98.push_back(Point(25, 24));
		f98.push_back(Point(25, 23));
		f98.push_back(Point(25, 22));
		f98.push_back(Point(25, 21));
		f98.push_back(Point(25, 20));
		f98.push_back(Point(25, 19));
		f98.push_back(Point(25, 18));
		f98.push_back(Point(25, 17));
		f98.push_back(Point(24, 17));
		f98.push_back(Point(23, 17));
		f98.push_back(Point(23, 16));
		f98.push_back(Point(23, 15));
		f98.push_back(Point(23, 14));
		f98.push_back(Point(23, 13));
		f98.push_back(Point(23, 12));
		f98.push_back(Point(23, 11));
		f98.push_back(Point(24, 11));
		f98.push_back(Point(24, 10));
		f98.push_back(Point(25, 10));
		f98.push_back(Point(25, 9));
		f98.push_back(Point(25, 8));
		f98.push_back(Point(25, 7));
		f98.push_back(Point(25, 6));
		f98.push_back(Point(25, 5));
		f98.push_back(Point(25, 4));
		f98.push_back(Point(25, 3));
		fc0.assign(c34_d223f0.unknown418980() / 2, 0);
		fd0 = c34_caed20;
		opR1d_4541b0(113, 0, 0);
		break;
	case 4:
		fc0.assign(c34_d223f0.unknown418980() / 2, 4);
		for (unsigned int center = 0; center < f78.size(); center++)
	{
		if (f78[center] != 0)
	{
		removeSubconsole(f78[center]);
	}
	}
		f78.clear();
		break;
	case 5:
		opR1d_4541b0(115, 0, 0);
		break;
	case 6:
	{
		Console * adj = new Console(this, 1, 45, c34_d2f118.min.x, c34_d2f118.min.y + 15, 4, 0, 5);
		adj->animate("A_TorUI_Frame");
		adj->animate("A_TorUI_Sfx");
		adj = new Console(this, 1, 60, c34_d2f118.max.x, c34_d2f118.min.y, 4, 0, 5);
		adj->animate("A_TorUI_Frame");
		adj = new Console(this, 1, 60, c34_d1da98.min.x, c34_d1da98.min.y, 4, 0, 5);
		adj->animate("A_TorUI_Frame");
		adj = new Console(this, 1, 45, c34_d1da98.max.x, c34_d1da98.min.y + 15, 4, 0, 5);
		adj->animate("A_TorUI_Frame");
		adj = new Console(this, c34_d21dc0.width(), 1, c34_d21dc0.min.x, c34_d21dc0.min.y, 4, 0, 5);
		adj->animate("A_TorUI_MsgDivider");
		adj = new Console(this, c34_d21dc0.width(), 1, c34_d21dc0.min.x, c34_d21dc0.max.y, 4, 0, 5);
		adj->animate("A_TorUI_MsgDivider");
		adj = new Console(this, c34_d2f118.width() - 2, 1, c34_d2f118.min.x + 1, c34_d2f118.min.y + 15, 4, 0, 5);
		adj->animate("A_TorUI_Divider");
		adj = new Console(this, c34_d2f118.width() - 2, 1, c34_d2f118.min.x + 1, c34_d2f118.min.y + 28, 4, 0, 5);
		adj->animate("A_TorUI_Divider");
		adj = new Console(this, c34_d2f118.width() - 2, 1, c34_d2f118.min.x + 1, c34_d2f118.min.y + 37, 4, 0, 5);
		adj->animate("A_TorUI_Divider");
		adj = new Console(this, c34_d2f118.width() - 2, 1, c34_d2f118.min.x + 1, c34_d2f118.min.y + 49, 4, 0, 5);
		adj->animate("A_TorUI_Divider");
		adj = new Console(this, c34_d1da98.width() - 2, 1, c34_d1da98.min.x + 1, c34_d1da98.min.y + 15, 4, 0, 5);
		adj->animate("A_TorUI_Divider");
		adj = new Console(this, c34_d1da98.width() - 2, 1, c34_d1da98.min.x + 1, c34_d1da98.min.y + 30, 4, 0, 5);
		adj->animate("A_TorUI_Divider");
		adj = new Console(this, c34_d1da98.width() - 2, 1, c34_d1da98.min.x + 1, c34_d1da98.min.y + 39, 4, 0, 5);
		adj->animate("A_TorUI_Divider");
		string center("INITIALIZING");
		fec = new Console(this, center.size(), 1, halfDiff_437190(center.size(), getWidth()), c34_d21dc0.min.y + 2, 4, 0, 6);
		fec->print(0, 0, center);
		fec->animate("A_TorUI_Msg");
		ConsoleArt * behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_dot_border", c34_d2f118.min.x, c34_d2f118.min.y, 0, -1, -1, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->setBackAll_418410(c34_d29804);
		behaviour->animate("A_TorUI_DotBorder");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_radar", c34_d2f118.min.x + 1, c34_d2f118.min.y + 1, 0, -1, -1, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->setBackAll_418410(c34_d29804);
		behaviour->animate("A_TorUI_Radar");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_dot_border", c34_d1da98.min.x + 1, c34_d1da98.min.y, 0, -1, -1, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->setBackAll_418410(c34_d29804);
		behaviour->animate("A_TorUI_DotBorder");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_sysmap_bkg", c34_d1da98.min.x + 3, c34_d1da98.min.y + 1, 0, -1, -1, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->setBackAll_418410(c34_d29804);
		behaviour->animate("A_TorUI_SysmapBkg");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_sysmap", c34_d1da98.min.x + 5, c34_d1da98.min.y + 3, 0, -1, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		int col;
		OpU8a_lookup1("TorUI_Sysmap_Delay", &col);
		behaviour->addEffect_48c460(col, Point(2, 0));
		behaviour->addEffect_48c460(col, Point(0, 3));
		behaviour->addEffect_48c460(col, Point(6, 5));
		behaviour->addEffect_48c460(col, Point(2, 8));
		center = "    SENSOR    ";
		adj = new Console(this, center.size(), 1, c34_d2f118.min.x + 1, c34_d2f118.min.y + 16, 4, 0, 6);
		adj->print(0, 0, center);
		adj->animate("A_TorUI_Header");
		center = "    SHIELD    ";
		adj = new Console(this, center.size(), 1, c34_d2f118.min.x + 1, c34_d2f118.min.y + 38, 4, 0, 6);
		adj->print(0, 0, center);
		adj->animate("A_TorUI_Header");
		center = "    STATUS    ";
		adj = new Console(this, center.size(), 1, c34_d1da98.min.x + 1, c34_d1da98.min.y + 16, 4, 0, 6);
		adj->print(0, 0, center);
		adj->animate("A_TorUI_Header");
		center = "    THRUST    ";
		adj = new Console(this, center.size(), 1, c34_d1da98.min.x + 1, c34_d1da98.min.y + 40, 4, 0, 6);
		adj->print(0, 0, center);
		adj->animate("A_TorUI_Header");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_sliders", c34_d2f118.min.x, c34_d2f118.min.y + 29, 0, 6, -1, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_ThickBox_Sliders");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_sliders", c34_d2f118.min.x, c34_d2f118.min.y + 29, 0, 6, -1, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_SlidersBkg");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_sliders", c34_d2f118.min.x, c34_d2f118.min.y + 29, 0, 6, 2, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_Sliders");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_dotbox_box", c34_d2f118.min.x, c34_d2f118.min.y + 50, 0, 6, -1, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_ThickBox_DotBox");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_dotbox_dots", c34_d2f118.min.x + 1, c34_d2f118.min.y + 51, 0, 6, -1, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_DotBoxDots");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_barbox_box", c34_d1da98.min.x, c34_d1da98.min.y + 31, 0, 6, -1, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_ThickBox_BarBox");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_barbox_bars", c34_d1da98.min.x + 1, c34_d1da98.min.y + 32, 0, 6, -1, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_BarBoxBars");
		for (int cols = 0, current = 58; cols < 4; cols++, current -= 2)
	{
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_thrust_horz", c34_d1da98.min.x, c34_d1da98.min.y + current, 0, 6, -1, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_ThrustH_Edge_" + intToString(cols));
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_thrust_hbar", c34_d1da98.min.x + 1, c34_d1da98.min.y + current + 1, 0, 6, -1, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_ThrustH_Bar");
	}
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_shield_int", c34_d2f118.min.x + 5, c34_d2f118.min.y + 40, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_ShieldInt");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_shield_ext", c34_d2f118.min.x + 4, c34_d2f118.min.y + 39, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_ShieldExt");
		new CTorShieldValue(this, Point(c34_d2f118.min.x + 1, c34_d2f118.min.y + 48), 0, 6);
		new CTorShieldValue(this, Point(c34_d2f118.min.x + 11, c34_d2f118.min.y + 48), 1, 6);
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_sensors", c34_d2f118.min.x, c34_d2f118.min.y + 18, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_Sensors");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_status", c34_d1da98.min.x, c34_d1da98.min.y + 18, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_Status");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_thrust_base", c34_d1da98.min.x + 2, c34_d1da98.min.y + 51, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_ThrustBase");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_thrust_lft", c34_d1da98.min.x, c34_d1da98.min.y + 43, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_ThrustLft");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_thrust_rgt", c34_d1da98.min.x + 14, c34_d1da98.min.y + 43, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_ThrustRgt");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/tor_thrust_bars", c34_d1da98.min.x + 3, c34_d1da98.min.y + 42, 0, 6, -1, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_ThrustBars");
		clear();
	}
	break;
	case 7:
	{
		if (fec != 0)
	{
		removeSubconsole(fec);
		fec = 0;
	}
		string center("APPLYING SUBSPACE REPAIRS");
		fec = new Console(this, center.size(), 1, halfDiff_437190(center.size(), getWidth()), c34_d21dc0.min.y + 2, 4, 0, 6);
		fec->print(0, 0, center);
		fec->animate("A_TorUI_Msg");
		ff0 = new CTorRepairValue(this, Point(halfDiff_437190(gameStrings_d2e9c8[0].size() + 5, getWidth()), c34_d21dc0.min.y + 5), 0, 6);
		ff4 = new ConsoleArt(this, string() + "data/art/" + "ending/tor_status_damage", c34_d1da98.min.x, c34_d1da98.min.y + 18, 0, 6, 0, Pos(-1), 0, 0);
		ff4->setForeAll_4183d0(*c34_cfe674);
		ff4->resetBack_418450();
		ff4->animate("A_TorUI_StatusDamage");
		int col;
		OpU8a_lookup1("TorUI_StatusRepair_Core", &col);
		ff4->addEffect_48c460(col, Point(0, 0));
		ff8 = new ConsoleArt(this, string() + "data/art/" + "ending/tor_repair_core_path", c34_d31b48.x + 40, c34_d31b48.y + 18, 0, 6, 0, Pos(-1), 0, 0);
		ff8->setForeAll_4183d0(*c34_cfe674);
		ff8->resetBack_418450();
		OpU8a_lookup1("TorUI_RepairCore_Path", &col);
		ff8->addEffect_48c460(col, Point(23, 0));
		ff8->animate("TorUI_RepairCore_Path_S");
		ffc = new ConsoleArt(this, string() + "data/art/" + "ending/tor_repair_core", c34_d31b48.x + 32, c34_d31b48.y + 26, 0, 6, 0, Pos(-1), 0, 0);
		ffc->setForeAll_4183d0(*c34_cfe674);
		ffc->resetBack_418450();
		ffc->animate("A_TorUI_Repair_Core_A");
		ffc->animate("A_TorUI_Repair_Core_B");
		f100 = new ConsoleArt(this, string() + "data/art/" + "ending/tor_repair_core_dmg", c34_d31b48.x + 32, c34_d31b48.y + 26, 0, 6, 0, Pos(-1), 0, 0);
		f100->setForeAll_4183d0(*c34_cfe674);
		f100->resetBack_418450();
		f100->animate("A_TorUI_RepairDmg_Core_A");
		f100->animate("A_TorUI_RepairDmg_Core_B");
	}
	break;
	case 8:
	{
		if (ff0 != 0)
	{
		removeSubconsole(ff0);
		ff0 = 0;
	}
		ff0 = new CTorRepairValue(this, Point(halfDiff_437190(gameStrings_d2e9c8[1].size() + 5, getWidth()), c34_d21dc0.min.y + 5), 1, 6);
		int center;
		OpU8a_lookup1("TorUI_StatusRepair_Power", &center);
		ff4->addEffect_48c460(center, Point(0, 2));
		if (ff8 != 0)
	{
		removeSubconsole(ff8);
		ff8 = 0;
	}
		ff8 = new ConsoleArt(this, string() + "data/art/" + "ending/tor_repair_power_path", c34_d31b48.x + 31, c34_d31b48.y + 20, 0, 6, 0, Pos(-1), 0, 0);
		ff8->setForeAll_4183d0(*c34_cfe674);
		ff8->resetBack_418450();
		ff8->animate("A_TorUI_RepairPow_Path");
		if (ffc != 0)
	{
		removeSubconsole(ffc);
		ffc = 0;
	}
		ffc = new ConsoleArt(this, string() + "data/art/" + "ending/tor_repair_power", c34_d31b48.x + 29, c34_d31b48.y + 28, 0, 6, 0, Pos(-1), 0, 0);
		ffc->setForeAll_4183d0(*c34_cfe674);
		ffc->resetBack_418450();
		ffc->animate("A_TorUI_Repair_Power_A");
		ffc->animate("A_TorUI_Repair_Power_B");
		if (f100 != 0)
	{
		removeSubconsole(f100);
		f100 = 0;
	}
		f100 = new ConsoleArt(this, string() + "data/art/" + "ending/tor_repair_power_dmg", c34_d31b48.x + 29, c34_d31b48.y + 28, 0, 6, 0, Pos(-1), 0, 0);
		f100->setForeAll_4183d0(*c34_cfe674);
		f100->resetBack_418450();
		f100->animate("A_TorUI_RepairDmg_Power_A");
		f100->animate("A_TorUI_RepairDmg_Power_B");
	}
	break;
	case 9:
	{
		if (ff0 != 0)
	{
		removeSubconsole(ff0);
		ff0 = 0;
	}
		ff0 = new CTorRepairValue(this, Point(halfDiff_437190(gameStrings_d2e9c8[2].size() + 5, getWidth()), c34_d21dc0.min.y + 5), 2, 6);
		int center;
		OpU8a_lookup1("TorUI_StatusRepair_Hull", &center);
		ff4->addEffect_48c460(center, Point(0, 5));
		ff4->addEffect_48c460(center, Point(0, 6));
		ff4->addEffect_48c460(center, Point(0, 7));
		ff4->addEffect_48c460(center, Point(0, 8));
		if (ff8 != 0)
	{
		removeSubconsole(ff8);
		ff8 = 0;
	}
		ff8 = new ConsoleArt(this, string() + "data/art/" + "ending/tor_repair_hull_path", c34_d31b48.x + 23, c34_d31b48.y + 13, 0, 6, 0, Pos(-1), 0, 0);
		ff8->setForeAll_4183d0(*c34_cfe674);
		ff8->resetBack_418450();
		OpU8a_lookup1("TorUI_RepairHull_Path", &center);
		ff8->addEffect_48c460(center, Point(40, 10));
		ff8->addEffect_48c460(center, Point(40, 11));
		ff8->addEffect_48c460(center, Point(40, 12));
		ff8->addEffect_48c460(center, Point(40, 13));
		ff8->animate("TorUI_RepairHull_Path_S");
		if (ffc != 0)
	{
		removeSubconsole(ffc);
		ffc = 0;
	}
		ffc = new ConsoleArt(this, string() + "data/art/" + "ending/tor_repair_hull", c34_d31b48.x + 32, c34_d31b48.y + 19, 0, 6, 0, Pos(-1), 0, 0);
		ffc->setForeAll_4183d0(*c34_cfe674);
		ffc->resetBack_418450();
		ffc->animate("A_TorUI_RepairHull_A");
		ffc->animate("A_TorUI_RepairHull_B");
		if (f100 != 0)
	{
		removeSubconsole(f100);
		f100 = 0;
	}
		f100 = new ConsoleArt(this, string() + "data/art/" + "ending/tor_repair_hull_dmg", c34_d31b48.x + 32, c34_d31b48.y + 19, 0, 6, 0, Pos(-1), 0, 0);
		f100->setForeAll_4183d0(*c34_cfe674);
		f100->resetBack_418450();
		f100->animate("A_TorUI_RepairDmgHull_A");
		f100->animate("A_TorUI_RepairDmgHull_B");
	}
	break;
	case 10:
	{
		if (fec != 0)
	{
		removeSubconsole(fec);
		fec = 0;
	}
		string center((c34_cf4b38 == 2 ? "SEARCHING FLEET RENDEZVOUS POINTS" : "SEARCHING DATABASE"));
		fec = new Console(this, center.size(), 1, halfDiff_437190(center.size(), getWidth()), c34_d21dc0.min.y + 2, 4, 0, 6);
		fec->print(0, 0, center);
		fec->animate("A_TorUI_Msg");
		if (ff0 != 0)
	{
		removeSubconsole(ff0);
		ff0 = 0;
	}
		if (ff4 != 0)
	{
		removeSubconsole(ff4);
		ff4 = 0;
	}
		if (ff8 != 0)
	{
		removeSubconsole(ff8);
		ff8 = 0;
	}
		if (ffc != 0)
	{
		removeSubconsole(ffc);
		ffc = 0;
	}
		if (f100 != 0)
	{
		removeSubconsole(f100);
		f100 = 0;
	}
		f104 = new ConsoleArt(this, string() + "data/art/" + "ending/tor_starmap", c34_d22318.min.x, c34_d22318.min.y, 0, 7, 0, Pos(-1), 0, 0);
		f104->setForeAll_4183d0(*c34_cfe674);
		f104->resetBack_418450();
		f104->animate("A_TorUI_Starmap");
	}
	break;
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	{
		string center;
		Point col;
		switch (f70)
	{
	case 11:
		center = "m";
		col.set(9, 8);
		break;
	case 12:
		center = "l";
		col.set(26, 35);
		break;
	case 13:
		center = "s";
		col.set(11, 32);
		break;
	case 14:
		center = "m";
		col.set(36, 30);
		break;
	case 15:
		center = "s";
		col.set(33, 14);
	}
		ConsoleArt * adj = new ConsoleArt(this, string() + "data/art/" + "ending/tor_starlabel_" + center, c34_d22318.min.x + col.x, c34_d22318.min.y + col.y, 0, 8, 0, Pos(-1), 0, 0);
		adj->setForeAll_4183d0(*c34_cfe674);
		adj->resetBack_418450();
		adj->animate("A_TorUI_Starlabel");
		f108.push_back(adj);
		for (unsigned int current = 0; current < f118.size(); current++)
	{
		if (f118[current] != 0)
	{
		removeSubconsole(f118[current]);
	}
	}
		f118.clear();
		Console * behaviour = new Console(this, 1, c34_d22318.height(), c34_d22318.min.x + col.x, c34_d22318.min.y, 4, 0, 6);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_Starcross_Vert");
		f118.push_back(behaviour);
		int cols;
		OpU8a_lookup1("A_TorUI_Starcross_TargV", &cols);
		behaviour->addEffect_48c460(cols, Point(0, col.y));
		behaviour = new Console(this, c34_d22318.width(), 1, c34_d22318.min.x, c34_d22318.min.y + col.y, 4, 0, 6);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		behaviour->animate("A_TorUI_Starcross_Horz");
		f118.push_back(behaviour);
		OpU8a_lookup1("A_TorUI_Starcross_TargH", &cols);
		behaviour->addEffect_48c460(cols, Point(col.x, 0));
	}
	break;
	case 16:
	{
		ConsoleArt * adj = new ConsoleArt(this, string() + "data/art/" + "ending/tor_rendezvous_mark", c34_d22318.min.x, c34_d22318.min.y, 0, 8, 0, Pos(-1), 0, 0);
		adj->setForeAll_4183d0(*c34_cfe674);
		adj->resetBack_418450();
		adj->animate("A_TorUI_Rendezvous_Mark");
		adj = new ConsoleArt(this, string() + "data/art/" + "ending/tor_rendezvous_line", c34_d22318.min.x + 9, c34_d22318.min.y + 11, 0, 8, 0, Pos(-1), 0, 0);
		adj->setForeAll_4183d0(*c34_cfe674);
		adj->resetBack_418450();
		adj->animate("A_TorUI_Rendezvous_Line");
		adj = new ConsoleArt(this, string() + "data/art/" + "ending/tor_rendezvous_label", c34_d22318.min.x + 25, c34_d22318.min.y + 11, 0, 8, 0, Pos(-1), 0, 0);
		adj->setForeAll_4183d0(*c34_cfe674);
		adj->resetBack_418450();
		adj->animate("A_TorUI_Rendezvous_Labl");
		C34_Image center;
		center.load(string() + "data/art/" + "ending/tor_starmap", 4, Pos(-1), 0, 0);
		Console *behaviour;
		C34_Grid *clean = center.layers.front();
		for (int col = 0; col < clean->getWidth(); col++)
	{
		for (int cols = 0; cols < clean->getHeight(); cols++)
	{
		if (clean->at(col, cols)->getChar() != 32)
	{
		behaviour = new Console(this, 2, 1, c34_d22318.min.x + col, c34_d22318.min.y + cols, 4, 0, 8);
		behaviour->resetBack_418450();
		behaviour->animate((clean->at(col, cols)->getChar() == 46 ? "A_TorUI_Rendezvous_Pt1" : "A_TorUI_Rendezvous_Pt2"));
	}
	}
	}
		behaviour = new Console(this, 7, c34_d22318.height(), c34_d22318.min.x + 1, c34_d22318.min.y, 4, 0, 8);
		behaviour->animate("A_TorUI_Rendezvous_List");
	}
	break;
	case 17:
	{
		if (fec != 0)
	{
		removeSubconsole(fec);
		fec = 0;
	}
		string center("CEDING CONTROL TO PILOT");
		fec = new Console(this, center.size(), 1, halfDiff_437190(center.size(), getWidth()), c34_d21dc0.min.y + 2, 4, 0, 6);
		fec->print(0, 0, center);
		fec->animate("A_TorUI_Msg");
		if (ff0 != 0)
	{
		removeSubconsole(ff0);
		ff0 = 0;
	}
		if (ff4 != 0)
	{
		removeSubconsole(ff4);
		ff4 = 0;
	}
		if (ff8 != 0)
	{
		removeSubconsole(ff8);
		ff8 = 0;
	}
		if (ffc != 0)
	{
		removeSubconsole(ffc);
		ffc = 0;
	}
		if (f100 != 0)
	{
		removeSubconsole(f100);
		f100 = 0;
	}
		Console * adj = new Console(this, 46, 1, c34_d22318.min.x + 1, c34_d22318.min.y + 1, 4, 0, 5);
		f13c.push_back(adj);
		adj->animate("A_TorUI_Combat_Divider");
		adj->animate("A_TorUI_Combat_Sfx");
		center = "              COMBAT DIAGNOSTICS              ";
		adj = new Console(this, center.size(), 1, c34_d22318.min.x + 1, c34_d22318.min.y + 2, 4, 0, 6);
		f13c.push_back(adj);
		adj->print(0, 0, center);
		adj->animate("A_TorUI_Combat_Header");
		adj = new Console(this, 22, 1, c34_d22318.min.x + 1, c34_d22318.min.y + 32, 4, 0, 5);
		f13c.push_back(adj);
		adj->animate("A_TorUI_Combat_Divider");
		center = "       TRACKING       ";
		adj = new Console(this, center.size(), 1, c34_d22318.min.x + 1, c34_d22318.min.y + 33, 4, 0, 6);
		f13c.push_back(adj);
		adj->print(0, 0, center);
		adj->animate("A_TorUI_Combat_Header");
		adj = new Console(this, 23, 1, c34_d22318.min.x + 24, c34_d22318.min.y + 22, 4, 0, 5);
		f13c.push_back(adj);
		adj->animate("A_TorUI_Combat_Divider");
		center = "        PAYLOAD        ";
		adj = new Console(this, center.size(), 1, c34_d22318.min.x + 24, c34_d22318.min.y + 23, 4, 0, 6);
		f13c.push_back(adj);
		adj->print(0, 0, center);
		adj->animate("A_TorUI_Combat_Header");
		ConsoleArt * behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_box_stability", c34_d22318.min.x + 1, c34_d22318.min.y + 5, 0, 5, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		behaviour->animate("A_TorUI_Combat_Box");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_box_maneuvering", c34_d22318.min.x + 8, c34_d22318.min.y + 7, 0, 5, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		behaviour->animate("A_TorUI_Combat_Box");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_box_tracking", c34_d22318.min.x + 13, c34_d22318.min.y + 7, 0, 5, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		behaviour->animate("A_TorUI_Combat_Box");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_box_targeting", c34_d22318.min.x + 1, c34_d22318.min.y + 18, 0, 5, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		behaviour->animate("A_TorUI_Combat_Box");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_box_weapons", c34_d22318.min.x + 1, c34_d22318.min.y + 23, 0, 5, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		behaviour->animate("A_TorUI_Combat_Box");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_box_cloaking", c34_d22318.min.x + 24, c34_d22318.min.y + 16, 0, 5, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		behaviour->animate("A_TorUI_Combat_Box");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_stability", c34_d22318.min.x + 2, c34_d22318.min.y + 6, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		behaviour->animate("A_TorUI_Combat_Inter_Stability");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_maneuvering", c34_d22318.min.x + 9, c34_d22318.min.y + 8, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		behaviour->animate("A_TorUI_Combat_Inter_Maneuvering");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_tracking", c34_d22318.min.x + 14, c34_d22318.min.y + 8, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		behaviour->animate("A_TorUI_Combat_Inter_Tracking");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_targeting", c34_d22318.min.x + 2, c34_d22318.min.y + 19, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		behaviour->animate("A_TorUI_Combat_Inter_Targeting");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_weapons", c34_d22318.min.x + 2, c34_d22318.min.y + 24, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		behaviour->animate("A_TorUI_Combat_Inter_Weapons");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_cloaking", c34_d22318.min.x + 25, c34_d22318.min.y + 17, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		behaviour->animate("A_TorUI_Combat_Inter_Cloaking");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_paths", c34_d22318.min.x + 4, c34_d22318.min.y + 4, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		int col;
		OpU8a_lookup1("A_TorUI_Combat_Path_Stability", &col);
		behaviour->addEffect_48c460(col, Point(0, 0));
		OpU8a_lookup1("A_TorUI_Combat_Path_Maneuvering", &col);
		behaviour->addEffect_48c460(col, Point(6, 2));
		OpU8a_lookup1("A_TorUI_Combat_Path_Tracking", &col);
		behaviour->addEffect_48c460(col, Point(14, 8));
		OpU8a_lookup1("A_TorUI_Combat_Path_Targeting", &col);
		behaviour->addEffect_48c460(col, Point(16, 16));
		OpU8a_lookup1("A_TorUI_Combat_Path_Weapons", &col);
		behaviour->addEffect_48c460(col, Point(18, 23));
		OpU8a_lookup1("A_TorUI_Combat_Path_Cloaking", &col);
		behaviour->addEffect_48c460(col, Point(23, 11));
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_systems", c34_d22318.min.x + 31, c34_d22318.min.y + 4, 0, 6, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		OpU8a_lookup1("A_TorUI_Combat_Systems", &col);
		behaviour->addEffect_48c460(col, Point(0, 0));
		OpU8a_lookup1("A_TorUI_Combat_SysOK_Stability", &col);
		behaviour->addEffect_48c460(col, Point(0, 0));
		OpU8a_lookup1("A_TorUI_Combat_SysOK_Maneuvering", &col);
		behaviour->addEffect_48c460(col, Point(0, 0));
		OpU8a_lookup1("A_TorUI_Combat_SysOK_Tracking", &col);
		behaviour->addEffect_48c460(col, Point(0, 0));
		OpU8a_lookup1("A_TorUI_Combat_SysOK_Targeting", &col);
		behaviour->addEffect_48c460(col, Point(0, 0));
		OpU8a_lookup1("A_TorUI_Combat_SysOK_Weapons", &col);
		behaviour->addEffect_48c460(col, Point(0, 0));
		OpU8a_lookup1("A_TorUI_Combat_SysOK_Cloaking", &col);
		behaviour->addEffect_48c460(col, Point(0, 0));
		adj = new Console(this, 22, 15, c34_d22318.min.x + 1, c34_d22318.min.y + 35, 4, 0, 6);
		f13c.push_back(adj);
		adj->animate("A_TorUI_Combat_Tracking");
		for (int cols = 0, clean = 25, current = 24, allies = 25, count = 26; cols < 3; cols++, clean += 8, current += 8, allies += 8, count += 8)
	{
		adj = new Console(this, 5, 1, c34_d22318.min.x + clean, c34_d22318.min.y + 25, 4, 0, 6);
		f13c.push_back(adj);
		adj->animate("A_TorUI_Payload_Status");
		behaviour = new ConsoleArt(this, string() + "data/art/" + "ending/combat_box_payload", c34_d22318.min.x + current, c34_d22318.min.y + 26, 0, 5, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		behaviour->animate("A_TorUI_Combat_Box");
		behaviour = new ConsoleArt(this, string() + "data/art/" + (cols < 2 ? "ending/combat_payload" : "ending/combat_payload_empty"), c34_d22318.min.x + allies, c34_d22318.min.y + 27, 0, 7, 0, Pos(-1), 0, 0);
		behaviour->setForeAll_4183d0(*c34_cfe674);
		behaviour->resetBack_418450();
		f12c.push_back(behaviour);
		behaviour->animate((cols < 2 ? "A_TorUI_Payload" : "A_TorUI_Payload_Empty"));
		adj = new Console(this, 5, 1, c34_d22318.min.x + count, c34_d22318.min.y + 49, 4, 0, 6);
		f13c.push_back(adj);
		adj->print(0, 0, "00" + intToString(cols));
		adj->setChar_417f50(3, 0, 196);
		adj->setChar_417f50(4, 0, 217);
		adj->animate("A_TorUI_Payload_Num");
	}
	}
	break;
	case 18:
	{
		string center;
		switch (c34_cf4b38)
		{
		case 0:
			center = "DESTINATION: EPSILON ERIDANI";
			break;
		case 2:
			center = "DESTINATION: C6153-B";
			break;
		case 3:
			center = "ENTERING ORBIT";
			break;
		}
		f128 = new Console(this, center.size(), 1, halfDiff_437190(center.size(), getWidth()), c34_d21dc0.min.y + 5, 4, 0, 6);
		f128->print(0, 0, center);
		if (c34_cf4b38 == 2)
	{
		f128->setChar_417f50(f128->getWidth() - 1, 0, 225);
	}
		f128->animate("A_TorUI_Msg");
		if (c34_cf4b38 == 0)
	{
		for (unsigned int current = 0; current < f108.size(); current++)
	{
		if (f108[current] != 0)
	{
		removeSubconsole(f108[current]);
	}
	}
		f108.clear();
		for (unsigned int current = 0; current < f118.size(); current++)
	{
		if (f118[current] != 0)
	{
		removeSubconsole(f118[current]);
	}
	}
		f118.clear();
		ConsoleArt * cols = new ConsoleArt(this, string() + "data/art/" + "ending/tor_starlabel_t", c34_d22318.min.x + 33, c34_d22318.min.y + 14, 0, 8, 0, Pos(-1), 0, 0);
		cols->setForeAll_4183d0(*c34_cfe674);
		cols->resetBack_418450();
		cols->animate("A_TorUI_Starlabel_Targ");
		f108.push_back(cols);
	}
		if (c34_cf4b38 == 3)
	{
		ConsoleArt * cols = new ConsoleArt(this, string() + "data/art/" + "ending/combat_payload_arm", c34_d22318.min.x + 26, c34_d22318.min.y + 28, 0, 8, 0, Pos(-1), 0, 0);
		cols->setForeAll_4183d0(*c34_cfe674);
		cols->resetBack_418450();
		f12c.push_back(cols);
		cols->animate("A_TorUI_Payload_Arm");
		Console * current = new Console(this, 7, 1, c34_d22318.min.x + 24, c34_d22318.min.y + 25, 4, 0, 8);
		f13c.push_back(current);
		current->print(0, 0, " ARMING");
		current->animate("A_TorUI_Payload_Arm_Txt");
	}
		vector<int> col;
		col.push_back(2);
		col.push_back(1);
		col.push_back(3);
		col.push_back(0);
		for (int cols = 0; cols < 4; cols++)
	{
		Console * adj = new Console(this, 1, 1, c34_d1da98.min.x + 3, c34_d1da98.min.y + col[cols] * 2 + 53, 4, 0, 7);
		adj->setForeAll_4183d0(*c34_cfe674);
		adj->resetBack_418450();
		f13c.push_back(adj);
		adj->animate("A_TorUI_ThrustNum_" + intToString(col[cols]));
		adj = new Console(this, 10, 1, c34_d1da98.min.x + 5, c34_d1da98.min.y + col[cols] * 2 + 53, 4, 0, 7);
		adj->setForeAll_4183d0(*c34_cfe674);
		adj->resetBack_418450();
		f13c.push_back(adj);
		adj->animate("A_TorUI_ThrustBar_" + intToString(col[cols]));
		adj = new Console(this, 3, 8, c34_d1da98.min.x + (col[cols] * 3) + 2, c34_d1da98.min.y + 42, 4, 0, 7);
		adj->setForeAll_4183d0(*c34_cfe674);
		adj->resetBack_418450();
		f13c.push_back(adj);
		adj->animate("A_TorUI_ThrustLvl_" + intToString(col[cols]));
	}
	}
	break;
	case 19:
	{
		unknown429f10(0, 0);
		deleteSubconsoles();
		CEndingFade * center = new CEndingFade(this, c34_bce924, 1, 0, -1);
		unknown429fe0(center, Point(0, 0), 0);
		clear();
		c34_cec144->setHidden(0);
	}
	break;
	case 20:
		f150 = new Console(c34_d223f0.getConsole(), getWidth(), getHeight(), 0, 0, 4, 0, -1);
		f150->setBackAll_418410(c34_d29804);
		unknown429f10(0, 0);
		f154 = new CEndingFade(c34_d223f0.getConsole(), c34_bce928, 1, 0, -1);
		unknown429fe0(f154, Point(0, 0), 0);
		animate("A_TorUI_Space_Sfx");
		for (unsigned int center = 0; center < f12c.size(); center++)
	{
		if (f12c[center] != 0)
	{
		removeSubconsole(f12c[center]);
	}
	}
		f12c.clear();
		for (unsigned int center = 0; center < f13c.size(); center++)
	{
		if (f13c[center] != 0)
	{
		removeSubconsole(f13c[center]);
	}
	}
		f13c.clear();
		break;
	case 21:
		c34_d223f0.getConsole()->removeSubconsole(f150);
		f150 = 0;
		c34_d223f0.getConsole()->removeSubconsole(f154);
		f154 = 0;
		f150 = new Console(this, getWidth(), getHeight(), 0, 0, 4, 0, 10);
		f150->setBackAll_418410(c34_d29804);
		break;
	case 22:
	{
		if (f150 != 0)
	{
		removeSubconsole(f150);
		f150 = 0;
	}
		f158 = new ConsoleArt(this, string() + "data/art/" + "ending/planet0", c34_d22318.min.x, c34_d22318.min.y, 0, 7, 0, Pos(-1), 0, 0);
		f14c = new CEndingFade(this, c34_bce930, 0, 0, 10);
		clear(c34_d21dc0.min.x, c34_d21dc0.min.y + 1, c34_d21dc0.width(), c34_d21dc0.height() - 2);
		if (fec != 0)
	{
		removeSubconsole(fec);
		fec = 0;
	}
		string center("ORBITING");
		fec = new Console(this, center.size(), 1, halfDiff_437190(center.size(), getWidth()), c34_d21dc0.min.y + 2, 4, 0, 6);
		fec->print(0, 0, center);
		fec->animate("A_TorUI_Msg");
		if (f128 != 0)
	{
		removeSubconsole(f128);
		f128 = 0;
	}
	}
	break;
	case 23:
	{
		if (f14c != 0)
	{
		removeSubconsole(f14c);
		f14c = 0;
	}
		ConsoleArt * center = new ConsoleArt(this, string() + "data/art/" + "ending/planet0_zoom", c34_d22318.min.x + 12, c34_d22318.min.y + 16, 0, 8, 0, Pos(-1), 0, 0);
		center->setForeAll_4183d0(*c34_cfe674);
		center->resetBack_418450();
		f12c.push_back(center);
		center->animate("A_TorUI_Planet_Zoom");
		f158->animate("A_TorUI_Planet_Dark");
	}
	break;
	case 24:
	{
		for (unsigned int col = 0; col < f12c.size(); col++)
	{
		if (f12c[col] != 0)
	{
		removeSubconsole(f12c[col]);
	}
	}
		f12c.clear();
		if (f158 != 0)
	{
		removeSubconsole(f158);
		f158 = 0;
	}
		f158 = new ConsoleArt(this, string() + "data/art/" + "ending/planet1", c34_d22318.min.x, c34_d22318.min.y, 0, 7, 0, Pos(-1), 0, 0);
		f158->animate("A_TorUI_Planet_Dark");
		ConsoleArt * center = new ConsoleArt(this, string() + "data/art/" + "ending/planet1_zoom", c34_d22318.min.x + 17, c34_d22318.min.y + 24, 0, 8, 0, Pos(-1), 0, 0);
		center->setForeAll_4183d0(*c34_cfe674);
		center->resetBack_418450();
		f12c.push_back(center);
		center->animate("A_TorUI_Planet_Zoom");
	}
	break;
	case 25:
	{
		for (unsigned int col = 0; col < f12c.size(); col++)
	{
		if (f12c[col] != 0)
	{
		removeSubconsole(f12c[col]);
	}
	}
		f12c.clear();
		if (f158 != 0)
	{
		removeSubconsole(f158);
		f158 = 0;
	}
		f158 = new ConsoleArt(this, string() + "data/art/" + "ending/planet2", c34_d22318.min.x, c34_d22318.min.y, 0, 7, 0, Pos(-1), 0, 0);
		f158->animate("A_TorUI_Planet_Scan");
		ConsoleArt * center = new ConsoleArt(this, string() + "data/art/" + "ending/planet2_base", c34_d22318.min.x, c34_d22318.min.y, 0, 8, 0, Pos(-1), 0, 0);
		center->setForeAll_4183d0(*c34_cfe674);
		center->resetBack_418450();
		f12c.push_back(center);
		center->animate("A_TorUI_Planet_Base");
	}
	break;
	case 26:
	{
		ConsoleArt *center;
		for (int col = 3; col >= 0; col--)
	{
		Point adj;
		switch (col)
	{
	case 3:
		adj.set(10, 12);
		break;
	case 2:
		adj.set(11, 13);
		break;
	case 1:
		adj.set(13, 15);
		break;
	case 0:
		adj.set(16, 18);
	}
		center = new ConsoleArt(this, string() + "data/art/" + "ending/planet2_target" + intToString(col), c34_d22318.min.x + adj.x, c34_d22318.min.y + adj.y, 0, 8, 0, Pos(-1), 0, 0);
		center->setForeAll_4183d0(*c34_cfe674);
		center->resetBack_418450();
		f12c.push_back(center);
		center->animate("A_TorUI_Planet_Targ_" + intToString(col));
	}
		animate("A_TorUI_Planet_Targ_Sfx");
	}
	break;
	case 27:
		for (unsigned int center = 0; center < f12c.size(); center++)
	{
		if (f12c[center] != 0)
	{
		removeSubconsole(f12c[center]);
	}
	}
		f12c.clear();
		if (f158 != 0)
	{
		removeSubconsole(f158);
		f158 = 0;
	}
		f15c.load(string() + "data/art/" + "ending/planet0", 4, Pos(-1), 0, 0);
		f16c.clear();
		f16c.push_back(Point(39, 51));
		f16c.push_back(Point(39, 50));
		f16c.push_back(Point(39, 49));
		f16c.push_back(Point(38, 48));
		f16c.push_back(Point(38, 47));
		f16c.push_back(Point(37, 46));
		f16c.push_back(Point(37, 45));
		f16c.push_back(Point(36, 44));
		f16c.push_back(Point(36, 43));
		f16c.push_back(Point(36, 42));
		f16c.push_back(Point(35, 41));
		f16c.push_back(Point(35, 40));
		f16c.push_back(Point(35, 39));
		f16c.push_back(Point(34, 38));
		f16c.push_back(Point(33, 37));
		f16c.push_back(Point(33, 36));
		f16c.push_back(Point(32, 35));
		f16c.push_back(Point(32, 34));
		f16c.push_back(Point(31, 33));
		f16c.push_back(Point(30, 32));
		f16c.push_back(Point(30, 31));
		f16c.push_back(Point(29, 30));
		f16c.push_back(Point(28, 29));
		f16c.push_back(Point(27, 28));
		f16c.push_back(Point(26, 27));
		f16c.push_back(Point(25, 26));
		f16c.push_back(Point(24, 26));
		f16c.push_back(Point(23, 25));
		f16c.push_back(Point(22, 25));
		animate("A_TorUI_Bomb_Prep_Sfx");
		break;
	case 28:
	{
		string center("NCB LAUNCHED");
		f128 = new Console(this, center.size(), 1, halfDiff_437190(center.size(), getWidth()), c34_d21dc0.min.y + 5, 4, 0, 6);
		f128->print(0, 0, center);
		f128->animate("A_TorUI_Msg");
		animate("A_TorUI_Bomb_Launch_Sfx");
	}
	break;
	case 29:
	{
		if (f128 != 0)
	{
		removeSubconsole(f128);
		f128 = 0;
	}
		string center("IMPACT CONFIRMED");
		f128 = new Console(this, center.size(), 1, halfDiff_437190(center.size(), getWidth()), c34_d21dc0.min.y + 5, 4, 0, 6);
		f128->print(0, 0, center);
		f128->animate("A_TorUI_Msg");
		int col;
		OpU8a_lookup1("TorUI_Planet_Explosion", &col);
		addEffect_48c460(col, Point(c34_d22318.min.x + 22, c34_d22318.min.y + 25));
	}
	break;
	case 30:
	{
		unknown429f10(0, 0);
		removeConsoles();
		deleteSubconsoles();
		CEndingFade * center = new CEndingFade(this, c34_bce950, 0, 1, -1);
		f64->unknown50ff80(center->f64);
		unknown429fe0(center, Point(0, 0), 0);
		clear();
		c34_cec144->setHidden(0);
	}
	break;
	case 31:
	{
		if (fec != 0)
	{
		removeSubconsole(fec);
		fec = 0;
	}
		string center("REASSESSING SITUATION");
		fec = new Console(this, center.size(), 1, halfDiff_437190(center.size(), getWidth()), c34_d21dc0.min.y + 2, 4, 0, 6);
		fec->print(0, 0, center);
		fec->animate("A_TorUI_Msg");
		center = "LIFTOFF ABORTED";
		f128 = new Console(this, center.size(), 1, halfDiff_437190(center.size(), getWidth()), c34_d21dc0.min.y + 5, 4, 0, 6);
		f128->print(0, 0, center);
		f128->animate("A_TorUI_Msg_Blink");
	}
	break;
	case 32:
		removeConsoles();
		deleteSubconsoles();
		opR1d_4541b0(116, 0, 0);
		fa8 = f98.size() - 1;
		break;
	case 33:
		animate("A_CEnding_Surface_Close");
		break;
	case 34:
	{
		f17c = new ConsoleArt(this, string() + "data/art/" + "ending/tor_singularity", c34_d31b48.x, c34_d31b48.y, 0, 6, 0, Pos(-1), 0, 0);
		f158 = new ConsoleArt(this, string() + "data/art/" + "ending/planet0", c34_d22318.min.x, c34_d22318.min.y, 0, 7, 0, Pos(-1), 0, 0);
		f14c = new CEndingFade(this, c34_bce960, 1, 0, 10);
		f14c->setDuration(c34_bce960 >> 1);
		string center("EMERGENCY BURN");
		fec = new Console(this, center.size(), 1, halfDiff_437190(center.size(), getWidth()), c34_d21dc0.min.y + 2, 4, 0, 6);
		fec->print(0, 0, center);
		fec->animate("A_TorUI_Msg_Blink");
		animate("A_TorUI_Singularity_Sfx");
	}
	break;
	case 35:
	{
		if (f14c != 0)
	{
		removeSubconsole(f14c);
		f14c = 0;
	}
		if (fec != 0)
	{
		removeSubconsole(fec);
		fec = 0;
	}
		string center("SUBSPACE DISTURBANCE DETECTED");
		fec = new Console(this, center.size(), 1, halfDiff_437190(center.size(), getWidth()), c34_d21dc0.min.y + 2, 4, 0, 6);
		fec->print(0, 0, center);
		fec->animate("A_TorUI_Msg");
		if (f158 != 0)
	{
		removeSubconsole(f158);
		f158 = 0;
	}
		f158 = new ConsoleArt(this, string() + "data/art/" + "ending/planet_green", c34_d22318.min.x, c34_d22318.min.y, 0, 7, 1, Pos(-1), 0, 0);
		f158->setForeAll_4183d0(*c34_cfe674);
		f158->resetBack_418450();
		int col;
		OpU8a_lookup1("TorUI_Planet_Line_E", &col);
		f158->addEffect_48c460(col, Point(23, 3));
		f158->addEffect_48c460(col, Point(24, 3));
		f158->addEffect_48c460(col, Point(23, 47));
		f158->addEffect_48c460(col, Point(24, 47));
		OpU8a_lookup1("A_TorUI_Planet_LineH", &col);
		f158->addEffect_48c460(col, Point(23, 25));
		animate("A_TorUI_Planet_Line_Sfx");
	}
	break;
	case 36:
	{
		if (f158 != 0)
	{
		removeSubconsole(f158);
		f158 = 0;
	}
		f158 = new ConsoleArt(this, string() + "data/art/" + "ending/planet_green", c34_d22318.min.x, c34_d22318.min.y, 0, 7, 0, Pos(-1), 0, 0);
		f158->animate("A_TorUI_Planet_Green");
		f184 = new ConsoleArt(this, string() + "data/art/" + "ending/planet_green_labels", c34_d22318.min.x, c34_d22318.min.y, 0, 7, 0, Pos(-1), 0, 0);
		f184->setForeAll_4183d0(*c34_cfe674);
		f184->resetBack_418450();
		f184->animate("A_TorUI_Planet_Gr_Label");
		if (fec != 0)
	{
		removeSubconsole(fec);
		fec = 0;
	}
		string center("EVENT IMMINENT");
		fec = new Console(this, center.size(), 1, halfDiff_437190(center.size(), getWidth()), c34_d21dc0.min.y + 2, 4, 0, 6);
		fec->print(0, 0, center);
		fec->animate("A_TorUI_Msg_Delay800");
	}
	break;
	case 37:
		if (f184 != 0)
	{
		removeSubconsole(f184);
		f184 = 0;
	}
		f17c->setBack(16, 8, c34_d22318.width(), c34_d22318.height(), *c34_d20cfc);
		f15c.load(string() + "data/art/" + "ending/planet0", 4, Pos(-1), 0, 0);
		f158->stopAll_48c650();
		f158->animate("A_TorUI_Planet_Gr_Erase");
		animate("A_TorUI_Planet_Alrt_Sfx");
		break;
	case 38:
	{
		if (f158 != 0)
	{
		removeSubconsole(f158);
		f158 = 0;
	}
		vector<Point> center;
		C34_Grid *adj = f15c.layers.front();
		for (int cols = 0; cols < adj->getWidth(); cols++)
	{
		for (int current = 0; current < adj->getHeight(); current++)
	{
		if (*adj->at(cols, current)->getBack() != *c34_cfe674)
	{
		OpV4c_Fn9d3020(center, Point(cols, current));
		break;
	}
	}
	}
		for (int cols = 0; cols < adj->getHeight(); cols++)
	{
		for (int current = 0; current < adj->getWidth(); current++)
	{
		if (*adj->at(current, cols)->getBack() != *c34_cfe674)
	{
		OpV4c_Fn9d3020(center, Point(current, cols));
		break;
	}
	}
	}
		for (int cols = 0; cols < adj->getHeight(); cols++)
	{
		for (int current = adj->getWidth() - 1; current >= 0; current--)
	{
		if (*adj->at(current, cols)->getBack() != *c34_cfe674)
	{
		OpV4c_Fn9d3020(center, Point(current, cols));
		break;
	}
	}
	}
		for (int cols = 0; cols < adj->getWidth(); cols++)
	{
		for (int current = adj->getHeight() - 1; current >= 0; current--)
	{
		if (*adj->at(cols, current)->getBack() != *c34_cfe674)
	{
		OpV4c_Fn9d3020(center, Point(cols, current));
		break;
	}
	}
	}
		int col;
		OpU8a_lookup1("TorUI_Singularity_E", &col);
		for (unsigned int cols = 0; cols < center.size(); cols++)
	{
		addEffect_48c460(col, Point(c34_d22318.min.x + center[cols].x, c34_d22318.min.y + center[cols].y));
	}
	}
	break;
	case 39:
	{
		unknown429f10(0, 0);
		removeConsoles();
		deleteSubconsoles();
		CEndingFade * center = new CEndingFade(this, c34_bce974, 0, 0, -1);
		unknown429fe0(center, Point(0, 0), 0);
		clear();
		c34_cec144->setHidden(0);
	}
	break;
	case 40:
	{
		f188 = new ConsoleArt(this, string() + "data/art/" + "ending/warlord_map", c34_d20ce8.x, c34_d20ce8.y, 0, 6, 0, Pos(-1), 0, 0);
		f188->setForeAll_4183d0(*c34_cfe674);
		f188->resetBack_418450();
		f18c.clear();
		int center = (f188->getWidth() / 7) * 7;
		int col = (f188->getHeight() / 3) * 3;
		for (int cols = 0; cols < center; cols += 7)
	{
		for (int current = 0; current < col; current += 3)
	{
		if (f188->f6c[0]->at(cols, current)->getChar() != 32)
	{
		f18c.push_back(Point(cols, current));
	}
	}
	}
		OpV4c_shuffle(f18c);
		f19c = c34_caed20;
		f1a0 = -1;
	}
	break;
	case 41:
	{
		f1a4 = new ConsoleArt(this, string() + "data/art/" + "ending/warlord_map", c34_d20ce8.x, c34_d20ce8.y, 0, 7, 1, Pos(-1), 0, 0);
		f1a4->setForeAll_4183d0(*c34_cfe674);
		f1a4->resetBack_418450();
		int center;
		OpU8a_lookup1("Warlord_Map_Trace_E", &center);
		for (int col = 14; col <= 20; col++)
	{
		f1a4->addEffect_48c460(center, Point(col, 16));
	}
		OpU8a_lookup1("Warlord_Map_Trace_S", &center);
		f1a4->addEffect_48c460(center, Point(0, 0));
		Console * adj = new Console(this, c34_d2f154.size(), 1, halfDiff_437190(c34_d2f154.size(), getWidth()), 2, 4, 0, -1);
		adj->print(0, 0, c34_d2f154);
		adj->animate("A_Warlord_Map_Title");
	}
	break;
	case 42:
	{
		f1a8 = new ConsoleArt(this, string() + "data/art/" + "ending/warlord_map", c34_d20ce8.x, c34_d20ce8.y, 0, 8, 2, Pos(-1), 0, 0);
		f1a8->setForeAll_4183d0(*c34_cfe674);
		f1a8->resetBack_418450();
		unknown998590(Point(0, 0));
		unknown998590(Point(15, 25));
		unknown998590(Point(43, 28));
		int center;
		OpU8a_lookup1("Warlord_Map_Area_S", &center);
		f1a8->addEffect_48c460(center, Point(0, 0));
	}
	break;
	case 43:
	{
		unknown998590(Point(15, 4));
		unknown998590(Point(43, 4));
		unknown998590(Point(43, 19));
		int center;
		OpU8a_lookup1("Warlord_Map_Area_S", &center);
		f1a8->addEffect_48c460(center, Point(0, 0));
	}
	break;
	case 44:
	{
		unknown998590(Point(0, 4));
		unknown998590(Point(73, 4));
		int center;
		OpU8a_lookup1("Warlord_Map_Dot", &center);
		f1a8->addEffect_48c460(center, Point(70, 16));
		f1a8->addEffect_48c460(center, Point(71, 16));
		f1a8->addEffect_48c460(center, Point(72, 16));
		int col;
		OpU8a_lookup1("Warlord_Map_Area_S", &col);
		f1a8->addEffect_48c460(col, Point(0, 0));
	}
	break;
	case 45:
	{
		f1ac = new Console(this, getWidth(), 2, 0, 2, 4, 0, 6);
		int center;
		OpU8a_lookup1("Surrender_Title", &center);
		for (int col = c34_d0155c.x + c34_cf39d4, behaviour = c34_d32154.size(); behaviour > 0; col++, behaviour--)
	{
		f1ac->addEffect_48c460(center, Point(col, 0));
	}
		f1ac->print(c34_d0155c.x + c34_cf39d4, 0, c34_d32154);
		OpU8a_lookup1("Surrender_Title_Line", &center);
		for (int col = 0; col < getWidth(); col++)
	{
		f1ac->addEffect_48c460(center, Point(col, 1));
	}
		f1b0 = new ConsoleArt(this, string() + "data/art/" + "ending/mainc", c34_d0155c.x, c34_d0155c.y, 0, 7, 0, Pos(-1), 0, 0);
		f1b0->setForeAll_4183d0(*c34_cfe674);
		f1b0->resetBack_418450();
		OpU8a_lookup1("Surrender_Bkg_Number", &center);
		vector<Point> adj;
		adj.push_back(Point(38, 2));
		adj.push_back(Point(68, 2));
		for (unsigned int col = 0; col < adj.size(); col++)
	{
		for (int cols = adj[col].x, behaviour = 0; behaviour < 3; cols++, behaviour++)
	{
		for (int current = adj[col].y, clean = 0; clean < 3; current++, clean++)
	{
		f1b0->addEffect_48c460(center, Point(cols, current));
	}
	}
	}
		OpU8a_lookup1("Surrender_Bkg_Scan_E", &center);
		for (int col = 0; col < f1b0->getWidth(); col++)
	{
		f1b0->addEffect_48c4a0(center, Point(col, 5), Point(col, 6));
	}
		OpU8a_lookup1("Warlord_Map_Trace_S", &center);
		f1b0->addEffect_48c460(center, Point(0, 0));
	}
	break;
	case 46:
	{
		vector<C34_Area> center;
		center.push_back(C34_Area(18, 6, 32, 10));
		center.push_back(C34_Area(3, 14, 17, 28));
		center.push_back(C34_Area(18, 14, 32, 30));
		center.push_back(C34_Area(46, 10, 60, 24));
		center.push_back(C34_Area(46, 25, 60, 35));
		center.push_back(C34_Area(61, 25, 75, 31));
		int col;
		OpU8a_lookup1("Surrender_Fgd_Scan_E", &col);
		for (unsigned int cols = 0; cols < center.size(); cols++)
	{
		f1b4.push_back(new ConsoleArt(this, string() + "data/art/" + "ending/mainc", c34_d0155c.x + center[cols].min.x, c34_d0155c.y + center[cols].min.y, 0, 8, 1, center[cols].min, center[cols].width(), center[cols].height()));
		f1b4.back()->setForeAll_4183d0(*c34_cfe674);
		f1b4.back()->resetBack_418450();
		for (int current = 0; current < f1b4.back()->getWidth(); current++)
	{
		f1b4.back()->addEffect_48c4a0(col, Point(current, 0), Point(current, 1));
	}
	}
		OpU8a_lookup1("Warlord_Map_Trace_S", &col);
		f1b4[0]->addEffect_48c460(col, Point(0, 0));
	}
	break;
	case 47:
	{
		OpQ5_U9d7710 *center;
		for (int col = 0, cols = c34_d0155c.y + 36; col < 35; col++, cols++)
	{
		if (!gameStrings_d2a8b0[col].empty())
		{
			bool current = true;
			string distanceSq(gameStrings_d2a8b0[col]);
			if (distanceSq[0] == '!')
			{
				distanceSq.erase(distanceSq.begin());
				if (stringToInt(c34_d1e860.getEntryText(distanceSq)))
					continue;
			}
			else if (!stringToInt(c34_d1e860.getEntryText(distanceSq)))
				continue;
		}
		f1c4.push_back(new CSurrenderPriority(this, col, Point(c34_d0155c.x + 3, cols), 8));
	}
		if (OpQ5_findByName(c34_cf35b0, "Operations Mainframe", center) && center->f15c != 0)
	{
		int col = (((center->f15c->f68 * 0x64) / 100) * c34_d28c94[center->f15c->f34]) / 10;
		opY3_playSound(center->f15c, 12, col, 0, -1);
	}
		break;
	}
	break;
	case 49:
		opC_initLayouts_4b6c40();
		f1d8 = new ConsoleArt(this, string() + "data/art/" + "ending/ufd_title", 0, 0, 0, 6, 0, Pos(-1), 0, 0);
		f1d8->setForeAll_4183d0(*c34_cfe674);
		f1d8->resetBack_418450();
		f1d8->animate("A_UFD_Map_Title");
		f1d8->setPos(halfDiff_437190(f1d8->getWidth(), getWidth()), 2);
		f1dc = new ConsoleArt(this, string() + "data/art/" + "ending/ufd_map", c34_cefd70.x, c34_cefd70.y, 0, 6, 0, Pos(-1), 0, 0);
		f1dc->setForeAll_4183d0(*c34_cfe674);
		f1dc->resetBack_418450();
		f1dc->animate("A_UFD_Map_Bkg");
		opR1d_4541b0(123, 0, 0);
		break;
	case 50:
	{
		string center("CYCLE");
		Console * adj = new Console(this, center.size(), 1, f1d8->getPos().x + 4, f1d8->getPos().y + 2, 4, 0, -1);
		adj->print(0, 0, center);
		adj->animate("A_UFD_Cycle_Label");
		f1e0 = new CCycleCounter(this, Point(adj->getPos(), 6, 0), c34_caed20 + c34_bce9a0, 6);
		for (int col = 0; col < 17; col++)
	{
		Point behaviour;
		behaviour.assign(c34_cefd70 + c34_cfb870[col]);
		if (c34_bce818[col])
		{
			behaviour.x += c34_bce830[col];
			behaviour.x -= 25;
			behaviour.x += 1;
		}
		else
			behaviour.x -= c34_bce830[col];
		f1e4.push_back(new C34_Fleet(this, col, behaviour, 6));
	}
		break;
	}
	break;
	case 52:
		if (c34_cf4b38 == 8 || c34_cf4b38 == 9)
			unknown9aaf70();
		else
			close();
		break;
	}
	}
	Console::update();
}
