// 7c6d30 (CCommands::open, the Manual/Options/Commands window) shared core declarations. READ ONLY for part workers.
// NOTE: placeholder names/layouts throughout (RTTI class names are real).
#include <string>
#include <vector>
using namespace std;

struct Pos	// NOTE: placeholder layout
{
	int x;
	int y;
	Pos(int x_, int y_);	// 0x46ca20
};

struct CcoPoint	// NOTE: placeholder name: a Point-like local, default ctor 0x453b40 = (-1,-1)
{
	int x;
	int y;
	CcoPoint();	// 0x453b40
	CcoPoint &operator=(const Pos &p);	// 0x46ca50 (folded with Point's copy ctor)
	CcoPoint &operator+=(const CcoPoint &p);	// 0x409a30
	void translate(int dx, int dy);	// 0x40a2a0
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &color) throw();	// 0x411e30
};

struct Rect;

class XConsole
{
public:
	virtual ~XConsole();

	bool isHidden();	// 0x4175f0
	bool isVisible();	// 0x417610
	void setHidden(bool hidden_);	// 0x417ba0
	Pos getPos();	// 0x417480
	int getHeight();	// 0x4174c0
	int width_44b0d0();	// NOTE: placeholder name (ICF'd getter 0x44b0d0 = the console width)
	void clear(const Rect &area);	// 0x417c40
	void removeSubconsole(XConsole *console);	// 0x428b20
	void putChar(int x, int y, int ch, XColor color);	// NOTE: placeholder name (0x418110)
	void print(int x, int y, const string &text);	// 0x4181d0
	void printAligned(int x, int y, int align, const string &text);	// 0x418220
	int printWrapped_418260(int x, int y, int width, int height, const string &text);	// NOTE: placeholder name (0x418260)
	void setCharRow(int x, int y, int width, int ch);	// NOTE: placeholder name (0x4297f0)

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);	// 0x48c060
	virtual void open();	// NOTE: placeholder name

	Rect getRect();	// 0x48c380
	void drawBorder_7c6510(Console *source, const Pos *pos, int width, int height);	// NOTE: placeholder name (0x7c6510)

	int unknown60;
	void *engine;
	void *title;
};

struct Rect	// NOTE: placeholder layout
{
	int x;
	int y;
	int w;
	int h;
	Rect(const Rect &rect);
};

//==================================================================
// CCommands (global pointer at 0xcec03c); ctor 0x7c6850
//==================================================================

class CCommands : public Console
{
public:
	virtual void open();	// 0x7c6d30

	void unknown7d14d0(int section);	// NOTE: placeholder name
	void addGallerySection(const CcoPoint &origin, const string &title, vector<int> &items);	// NOTE: placeholder name (0x7d5cf0)
	int unknown48c3c0(int value);	// NOTE: placeholder name (0x48c3c0)

	int ID;	// 0x6c
	vector<Console*> tabButtons;	// 0x70
	vector<Console*> list80;	// 0x80
	vector<Console*> list90;	// 0x90
	vector<Console*> lista0;	// 0xa0
	bool unknownb0;	// 0xb0
	vector<Console*> listb4;	// 0xb4
	Console *unknownc4;	// 0xc4
	Console *unknownc8;	// 0xc8
	Console *unknowncc;	// 0xcc
	Console *unknownd0;	// 0xd0
	vector<Console*> sectionButtons;	// 0xd4
	int page;	// 0xe4
	vector<Console*> liste8;	// 0xe8
	Console *unknownf8;	// 0xf8
	int unknownfc;	// 0xfc
	int unknown100;	// 0x100
	Console *unknown104;	// 0x104
	Console *unknown108;	// 0x108
	vector<Console*> list10c;	// 0x10c
	vector<Console*> optionButtons;	// 0x11c
	vector<Console*> optionValues;	// 0x12c
	Console *unknown13c;	// 0x13c
	int unknown140;	// 0x140
	unsigned int unknown144;	// 0x144
	int unknown148;	// 0x148
	vector<Console*> list14c;	// 0x14c
	void *unknown15c;	// 0x15c (AsciiImage)
	vector<Console*> list160;	// 0x160
	vector<Console*> list170;	// 0x170
	vector<Console*> list180;	// 0x180
	Console *unknown190;	// 0x190
	Console *unknown194;	// 0x194
	Console *unknown198;	// 0x198
	vector<Console*> list19c;	// 0x19c
	vector<Console*> list1ac;	// 0x1ac
	vector<Console*> list1bc;	// 0x1bc
	Console *unknown1cc;	// 0x1cc
	Console *unknown1d0;	// 0x1d0
};

extern char cco_flag_d257d5;	// NOTE: placeholder name (0xd257d5)
// Part 1 declarations for 0x7c6d30 CCommands::open
class CcoP1Hud : public Console	// 0x492810 (CCommandsHud)
{
public:
	CcoP1Hud(XConsole *parent, int x, int y, int width, const string &text, int color, int color2);	// 0x492810
	char pad[0x6c - sizeof(Console)];
};

class CcoP1Button : public Console	// 0x492700 (CCommandsButton)
{
public:
	CcoP1Button(XConsole *parent, int x, int y, int ID_, bool alternate);	// 0x492700
	char pad[0x78 - sizeof(Console)];
};

class CcoP1InterfaceMsg : public XConsole	// NOTE: placeholder name (0xcec0f4)
{
public:
	void hide();	// 0x7b1cc0
};

class CcoP1Log : public XConsole	// NOTE: placeholder name (CLog at 0xcec0b0)
{
public:
	bool getUnknown80();	// NOTE: placeholder name (0x48e740)
	bool unknown7b60e0();	// NOTE: placeholder name (0x7b60e0)
};

class CcoP1Push : public XConsole	// NOTE: placeholder name (0xcec054)
{
public:
	bool operate();	// NOTE: placeholder name (0x49aa00)
};

class CcoP1Graph	// NOTE: placeholder name (0xcefa8c)
{
public:
	void pushFrame(int a, XConsole *console, int c, bool d);	// 0x416790
};

void cco1_initMenuAnimations();	// NOTE: placeholder name (0x490cb0)
bool cco1_hasPtr_cebd5c();	// NOTE: placeholder name (0x4328a0)
int cco1_centerOffset(int inner, int outer);	// NOTE: placeholder name (0x437190)

extern CcoP1InterfaceMsg *cco1_cec0f4;	// NOTE: placeholder name (0xcec0f4)
extern CcoP1Log *cco1_cec0b0;	// NOTE: placeholder name (0xcec0b0)
extern Console *cco1_cec0d0;	// NOTE: placeholder name (0xcec0d0)
extern Console *cco1_cec0d4;	// NOTE: placeholder name (0xcec0d4)
extern Console *cco1_cec0d8;	// NOTE: placeholder name (0xcec0d8)
extern Console *cco1_cec0dc;	// NOTE: placeholder name (0xcec0dc)
extern Console *cco1_cec0e0;	// NOTE: placeholder name (0xcec0e0)
extern Console *cco1_cec0e4;	// NOTE: placeholder name (0xcec0e4)
extern Console *cco1_cec0e8;	// NOTE: placeholder name (0xcec0e8)
extern Console *cco1_cec0ec;	// NOTE: placeholder name (0xcec0ec)
extern Console *cco1_cec0c8;	// NOTE: placeholder name (0xcec0c8)
extern Console *cco1_cec0cc;	// NOTE: placeholder name (0xcec0cc)
extern Console *cco1_cec0b8;	// NOTE: placeholder name (0xcec0b8)
extern Console *cco1_cec0c0;	// NOTE: placeholder name (0xcec0c0)
extern CcoP1Push *cco1_cec054;	// NOTE: placeholder name (0xcec054)
extern Console *cco1_cec058;	// NOTE: placeholder name (0xcec058)
extern Console *cco1_cec05c;	// NOTE: placeholder name (0xcec05c)
extern Console *cco1_cec060;	// NOTE: placeholder name (0xcec060)
extern Console *cco1_cec068;	// NOTE: placeholder name (0xcec068)
extern Console *cco1_cec06c;	// NOTE: placeholder name (0xcec06c)
extern Console *cco1_cec074;	// NOTE: placeholder name (0xcec074)
extern Console *cco1_cec078;	// NOTE: placeholder name (0xcec078)
extern Console *cco1_cec07c;	// NOTE: placeholder name (0xcec07c)
extern Console *cco1_cec084;	// NOTE: placeholder name (0xcec084)
extern Console *cco1_cec088;	// NOTE: placeholder name (0xcec088)
extern Console *cco1_cec08c;	// NOTE: placeholder name (0xcec08c)
extern CcoP1Graph *cco1_cefa8c;	// NOTE: placeholder name (0xcefa8c)
extern int cco1_cefc90;	// NOTE: placeholder name (0xcefc90)
extern bool cco1_d28c8a;	// NOTE: placeholder name (0xd28c8a)
extern int cco1_cebd5c;	// NOTE: placeholder name (0xcebd5c)
extern int cco1_d28d64;	// NOTE: placeholder name (0xd28d64)
extern int cco1_d01a24;	// NOTE: placeholder name (0xd01a24)
extern string cco1_gameStrings_d382f0[];	// 0xd382f0
extern int cco1_fontCellWidth;	// 0xcaf128
extern int cco1_d323c0;	// NOTE: placeholder name (0xd323c0)
extern XColor *cco1_d2175c;	// NOTE: placeholder name (0xd2175c)
extern bool cco1_d28d26;	// NOTE: placeholder name (0xd28d26)
extern int cco1_cef81c;	// NOTE: placeholder name (0xcef81c)
extern int cco1_cef820;	// NOTE: placeholder name (0xcef820)
extern int cco1_cef94c;	// NOTE: placeholder name (0xcef94c)
extern int cco1_cef95c;	// NOTE: placeholder name (0xcef95c)
extern int cco1_cef87c;	// NOTE: placeholder name (0xcef87c)
extern int cco1_cef8e0;	// NOTE: placeholder name (0xcef8e0)
extern int cco1_cef964;	// NOTE: placeholder name (0xcef964)
extern unsigned char cco1_d28d6c;	// NOTE: placeholder name (0xd28d6c)
extern unsigned int cco1_tickCount;	// NOTE: placeholder name (0xcaed20)
// part 2 (case 0) declarations for 0x7c6d30 CCommands::open
class CcoP2Basic : public Console	// 0x7c1e60 ctor (CCommandsBasic)
{
public:
	CcoP2Basic(XConsole *parent, int x, int y, int width, int type);	// 0x7c1e60
	char pad[0x6c - sizeof(Console)];
};

class CcoP2MenuButton : public Console	// CGamemenuButton
{
public:
	CcoP2MenuButton(XConsole *parent, int x, int y, int key_, int index_);	// 0x495760
	void setColors();	// 0x4959c0
	char pad[0x88 - sizeof(Console)];
};

class CcoP2SaveloadButton : public Console	// CGamemenuSaveloadButton
{
public:
	CcoP2SaveloadButton(XConsole *parent, int y, int type_, bool hasSave_);	// 0x495aa0
	void setHighlight();	// 0x496180
	char pad[0x8c - sizeof(Console)];
};

struct CcoP2Cf45d8	// NOTE: placeholder name/layout (global object at 0xcf45d8)
{
	bool isFlagActive();	// 0x46dd50
	bool unknown77e7c0();	// NOTE: placeholder name (0x77e7c0)
};

extern CcoP2Cf45d8 cco2_cf45d8;	// 0xcf45d8
extern Pos cco2_d323bc;	// 0xd323bc NOTE: placeholder name
extern int cco2_d323c0;	// 0xd323c0 (= cco2_d323bc.y) NOTE: placeholder name
extern XConsole *cco2_cec054;	// 0xcec054
extern XConsole *cco2_cec0b0;	// 0xcec0b0
extern XConsole *cco2_cec0c8;	// 0xcec0c8
extern XConsole *cco2_cec0cc;	// 0xcec0cc
extern XConsole *cco2_cec0b8;	// 0xcec0b8
extern XConsole *cco2_cec0c0;	// 0xcec0c0
extern XConsole *cco2_cec078;	// 0xcec078
extern XConsole *cco2_cec088;	// 0xcec088
extern XConsole *cco2_cec08c;	// 0xcec08c
extern int cco2_caf128;	// 0xcaf128
extern int cco2_cebd5c;	// 0xcebd5c
extern int cco2_d28d64;	// 0xd28d64
extern int cco2_cefc90;	// 0xcefc90
extern int cco2_cefab4;	// 0xcefab4
extern int cco2_cf4718;	// 0xcf4718
extern bool cco2_d28de1;	// 0xd28de1
extern bool cco2_d28de2;	// 0xd28de2
extern bool cco2_d28de3;	// 0xd28de3

bool cco2_hasPtr_4328a0();	// 0x4328a0 (opr1c_hasPtr_cebd5c)
int cco2_halfDiff_437190(int a, int b);	// 0x437190
int cco2_sound_4541b0(unsigned int sound, int loopsB, int loops);	// 0x4541b0 (opR1d_4541b0)
// Part 3 (case 1) declarations for 0x7c6d30 CCommands::open.
class CcoP3Adv : public Console	// NOTE: placeholder name (CCommandsAdvanced, ctor 0x4929b0's sibling)
{
public:
	CcoP3Adv(XConsole *parent, int x, int y, int width, int mode_);	// 0x? CCommandsAdvanced::CCommandsAdvanced
	char pad6c[0x70 - sizeof(Console)];
};

class CcoP3Page : public Console	// NOTE: placeholder name (CCommandsAdvancedPage)
{
public:
	CcoP3Page(XConsole *parent, int x, int y);	// 0x4929b0
	int get_4ab670();	// NOTE: placeholder name (folded getter 0x4ab670)
	char pad6c[0x78 - sizeof(Console)];
};

class CcoP3Con : public Console	// NOTE: placeholder name (cast target for Console methods)
{
public:
	int delegate_48c3c0(int value);	// NOTE: placeholder name (0x48c3c0)
};

bool cco3_hasPtr();	// NOTE: placeholder name (0x4328a0)
int cco3_centerOffset(int inner, int outer);	// NOTE: placeholder name (0x437190)
void cco3_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)

extern Pos cco3_d323bc;	// 0xd323bc NOTE: placeholder name
extern int cco3_cebd5c;	// 0xcebd5c NOTE: placeholder name
extern int cco3_caf128;	// 0xcaf128 NOTE: placeholder name (cell width)
extern int cco3_cefab4;	// 0xcefab4 NOTE: placeholder name
extern int cco3_cf27f4;	// 0xcf27f4 NOTE: placeholder name
extern int cco3_cefc90;	// 0xcefc90 NOTE: placeholder name
extern int cco3_cef780;	// 0xcef780 NOTE: placeholder name
extern int cco3_d28d64;	// 0xd28d64 NOTE: placeholder name
extern XConsole *cco3_cec054;	// 0xcec054
extern XConsole *cco3_cec078;	// 0xcec078
extern XConsole *cco3_cec088;	// 0xcec088
extern XConsole *cco3_cec08c;	// 0xcec08c
extern XConsole *cco3_cec0b0;	// 0xcec0b0
extern XConsole *cco3_cec0b8;	// 0xcec0b8
extern XConsole *cco3_cec0c0;	// 0xcec0c0
extern XConsole *cco3_cec0c8;	// 0xcec0c8
extern XConsole *cco3_cec0cc;	// 0xcec0cc
// Part 4 (0x7c6d30 CCommands::open, offsets 0x433c-0x4e40) declarations.
class CcoP4Highlighted : public Console	// NOTE: placeholder name/layout (type of CCommands::unknownc4)
{
public:
	int getHighlighter_4ab670();	// 0x4ab670 (ICF'd getter of +0x6c, OpW6_Rex::getHighlighter)
};

class CcoP4ManualButton : public Console	// 0x492c40 (CManualButton), size 0x78
{
public:
	CcoP4ManualButton(XConsole *parent, int y, int mode_);	// 0x492c40
	char pad[0x78 - sizeof(Console)];
};

struct CcoP4ManualSection;	// NOTE: placeholder name
extern vector<CcoP4ManualSection*> cco4_manualSections;	// NOTE: placeholder name (0xcf39dc)
extern int cco4_d323c0;	// NOTE: placeholder name (0xd323c0)

string cco4_intToString(int value);	// 0x4051f0 (intToString)
void cco4_logError(string location, string message);	// 0x404f10 (logError)
// Part 5 (inner case 3: Options page) declarations for 0x7c6d30 CCommands::open.
class CcoP5OptionButton : public Console	// NOTE: placeholder name (COptionButton)
{
public:
	CcoP5OptionButton(XConsole *parent, int y, int key_, int option_);	// 0x493250
	char pad[0x7c - sizeof(Console)];
};

class CcoP5OptionValue : public Console	// NOTE: placeholder name (COptionValue)
{
public:
	CcoP5OptionValue(XConsole *parent, int x, int y, int option_);	// 0x493510
	char pad[0x70 - sizeof(Console)];
};

class CcoP5Rex	// NOTE: placeholder layout (REX at 0xd223f0)
{
public:
	int unknown4189a0();	// 0x4189a0 (screen height in cells)
};

class CcoP5Frame : public Console	// NOTE: placeholder name: Console viewed for drawFrame
{
public:
	void drawFrame(Rect *area, XColor color, bool thin, bool lines);	// 0x7b0640
};

extern CcoP5Rex cco5_d223f0;	// 0xd223f0
extern int cco5_d323c0;	// 0xd323c0 NOTE: placeholder name
extern int cco5_cefab4;	// 0xcefab4 NOTE: placeholder name (screen width in font cells)
extern int cco5_caf128;	// 0xcaf128 NOTE: placeholder name (font cell size)
extern XConsole *cco5_cec078;	// 0xcec078
extern XConsole *cco5_cec088;	// 0xcec088
extern XColor *cco5_d316f4;	// 0xd316f4
int cco5_playSound(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name (0x4541b0)
// Part 6 (0x7c6d30 inner case 4: the News/Updates page) declarations.
class CcoP6Box : public Console	// NOTE: placeholder name (Unknown_c34b98, vtable 0xc34b98)
{
public:
	CcoP6Box(XConsole *parent, int x, int y, int width, int height, int value);	// 0x4962a0
	int unknown6c;
};

class CcoP6Rex	// NOTE: placeholder name/layout (REX at 0xd223f0)
{
public:
	int height_4189a0();	// NOTE: placeholder name (0x4189a0)
};

extern CcoP6Rex cco6_d223f0;	// 0xd223f0
extern Pos cco6_d323bc;	// 0xd323bc NOTE: placeholder name
extern CcoPoint cco6_d21754;	// 0xd21754 NOTE: placeholder name
extern string cco6_d2571c;	// 0xd2571c NOTE: placeholder name (news text)
extern string cco6_d21928;	// 0xd21928 NOTE: placeholder name (version prefix)
extern string cco6_cf33fc;	// 0xcf33fc NOTE: placeholder name (current version/build)
extern string cco6_d256e0;	// 0xd256e0 NOTE: placeholder name (latest version)
extern string cco6_d256fc;	// 0xd256fc NOTE: placeholder name (latest build)
extern bool cco6_d28d05;	// 0xd28d05 NOTE: placeholder name (news/updates option)
extern bool cco6_d25738;	// 0xd25738 NOTE: placeholder name
extern bool cco6_d25718;	// 0xd25718 NOTE: placeholder name

string cco6_convertBuildno_432720(const string &build);	// 0x432720
float cco6_stringToFloat_405ab0(const string &str);	// 0x405ab0
// Part 7 (inner case 5: credits page) declarations for 0x7c6d30 CCommands::open.
class CcoP7Label : public Console	// NOTE: placeholder name (Unknown_c34bcc, ctor 0x496320)
{
public:
	CcoP7Label(XConsole *parent, int x, int y, int width, int height, int value);	// 0x496320
	char pad[0x70 - sizeof(Console)];
};

class CcoP7Button : public Console	// NOTE: placeholder name (CCommandsButton, ctor 0x492700)
{
public:
	CcoP7Button(XConsole *parent, int x, int y, int ID_, bool alternate);	// 0x492700
	char pad[0x78 - sizeof(Console)];
};

bool cco7_hasPtr_4328a0();	// NOTE: placeholder name (0x4328a0)
extern XConsole *cco7_cec054;	// NOTE: placeholder name (0xcec054, the map console)
extern int cco7_caf128;	// NOTE: placeholder name (0xcaf128, font cell width)
extern int cco7_cefab4;	// NOTE: placeholder name (0xcefab4)
extern Pos cco7_d323bc;	// NOTE: placeholder name (0xd323bc)
extern int cco7_d323c0;	// NOTE: placeholder name (0xd323c0 = cco7_d323bc.y)
extern string cco7_d39e3c;	// NOTE: placeholder name (0xd39e3c)
extern int cco7_cef948;	// NOTE: placeholder name (0xcef948, a color)
extern const int cco7_bca2dc[];	// NOTE: placeholder name (0xbca2dc)
extern const int cco7_bca6ec[];	// NOTE: placeholder name (0xbca6ec)
extern const int cco7_bca964[];	// NOTE: placeholder name (0xbca964)
extern const int cco7_bcabbc[];	// NOTE: placeholder name (0xbcabbc)
extern const int cco7_bcac44[];	// NOTE: placeholder name (0xbcac44)
extern const int cco7_bcad24[];	// NOTE: placeholder name (0xbcad24)
extern const int cco7_bcaeb4[];	// NOTE: placeholder name (0xbcaeb4)
// Part 8 (inner case 6) declarations for 0x7c6d30 CCommands::open.
struct CcoP8Point	// NOTE: placeholder layout (Point)
{
	int x;
	int y;
	CcoP8Point(const CcoP8Point &p);	// 0x46ca50
};

class CcoP8Label : public Console	// 0x496400 ctor (Unknown_c34c34); NOTE: placeholder name
{
public:
	CcoP8Label(XConsole *parent, int x, int y, int index);	// 0x496400
	char pad[0x70 - sizeof(Console)];
};

class CcoP8Effect	// NOTE: placeholder name
{
public:
	void init_50de10();	// 0x50de10 NOTE: placeholder name
};

class CcoP8Engine	// NOTE: placeholder name
{
public:
	CcoP8Effect *unknown50fb50(CcoP8Engine *engine, int anim, Pos *a, CcoP8Point *b, Pos *c, CcoP8Point *d, int value);	// 0x50fb50 NOTE: placeholder name
};

extern int cco8_d323bc;	// 0xd323bc NOTE: placeholder name
extern int cco8_d323c0;	// 0xd323c0 NOTE: placeholder name
extern XConsole *cco8_cec054;	// 0xcec054
extern int cco8_caf128;	// 0xcaf128 NOTE: placeholder name
extern XColor *cco8_cf44c0;	// 0xcf44c0 NOTE: placeholder name
extern string cco8_d20a78[];	// 0xd20a78 NOTE: placeholder name
extern string cco8_d30558[];	// 0xd30558 NOTE: placeholder name
extern CcoP8Point cco8_d2e20c;	// 0xd2e20c NOTE: placeholder name
bool cco8_lookup_9d45a0(const string &name, int *value);	// 0x9d45a0 NOTE: placeholder name
// Function skeleton for 0x7c6d30 CCommands::open. READ ONLY for part workers.
// Each part's test file defines the CCO_Pn macros it fills (a quoted .inc file name); undefined parts stay empty.
void CCommands::open()
{
	cco_flag_d257d5 = 1;
	if (isHidden())
	{
		unknown60 = 1;
		cco1_initMenuAnimations();
		if (!cco1_cec0f4->isHidden())
			cco1_cec0f4->hide();
		if (cco1_cec0b0->getUnknown80())
			cco1_cec0b0->unknown7b60e0();
		cco1_cec0b0->setHidden(true);
		cco1_cec0d0->setHidden(true);
		cco1_cec0d4->setHidden(!(cco1_cefc90 && cco1_cec0d0->isVisible()));
		cco1_cec0d8->setHidden(!cco1_cec0d0->isVisible());
		cco1_cec0dc->setHidden(!cco1_cec0d0->isVisible());
		if (cco1_cec0e0)
			cco1_cec0e0->setHidden(true);
		cco1_cec0e4->setHidden(!(!cco1_d28c8a && cco1_cec0d0->isVisible()));
		cco1_cec0e8->setHidden(!(cco1_cec0d0->isVisible() && cco1_cebd5c == 2));
		cco1_cec0ec->setHidden(!(cco1_cec0d0->isVisible() && cco1_cebd5c == 2));
		cco1_cec0c8->setHidden(true);
		cco1_cec0cc->setHidden(true);
		cco1_cec0b8->setHidden(true);
		cco1_cec0c0->setHidden(true);
		cco1_cec054->setHidden(true);
		cco1_cec058->setHidden(true);
		cco1_cec074->setHidden(true);
		cco1_cec078->setHidden(true);
		cco1_cec07c->setHidden(true);
		cco1_cec084->setHidden(true);
		cco1_cec088->setHidden(true);
		cco1_cec08c->setHidden(true);
		if (cco1_cec05c)
			cco1_cec05c->setHidden(true);
		if (cco1_cec060)
			cco1_cec060->setHidden(true);
		if (cco1_cec068)
			cco1_cec068->setHidden(true);
		if (cco1_cec06c)
			cco1_cec06c->setHidden(true);
		setHidden(false);
		cco1_cefa8c->pushFrame(2, this, -1, false);
		drawBorder_7c6510((Console *)cco1_cec0b0, cco1_cebd5c == 2 ? &Pos(0, 0) : NULL, 0, 0);
		switch (cco1_d28d64)
		{
		case 0:
			drawBorder_7c6510(cco1_cec0c8, cco1_cebd5c == 2 ? &Pos(cco1_d01a24, 0) : NULL, 0, 0);
			break;
		case 1:
			drawBorder_7c6510(cco1_cec0cc, cco1_cebd5c == 2 ? &Pos(cco1_d01a24, 0) : NULL, 0, 0);
			break;
		case 2:
			drawBorder_7c6510(cco1_cec0b8, cco1_cebd5c == 2 ? &Pos(cco1_d01a24, 0) : NULL, 0, 0);
			break;
		case 3:
			drawBorder_7c6510(cco1_cec0c0, cco1_cebd5c == 2 ? &Pos(cco1_d01a24, 0) : NULL, 0, 0);
			break;
		}
		if (cco1_hasPtr_cebd5c())
		{
			clear(cco1_cec088->getRect());
			drawBorder_7c6510(cco1_cec088, &cco1_cec078->getPos(), 0, cco1_cec088->getHeight() + cco1_cec078->getHeight());
			if (!cco1_cefc90)
				drawBorder_7c6510(cco1_cec08c, NULL, 0, 0);
		}
		else
		{
			drawBorder_7c6510(cco1_cec078, NULL, 0, 0);
			if (cco1_cec054->operate())
				drawBorder_7c6510(cco1_cec084, NULL, 0, 0);
			else
				drawBorder_7c6510(cco1_cec07c, NULL, 0, 0);
			drawBorder_7c6510(cco1_cec088, NULL, 0, 0);
			drawBorder_7c6510(cco1_cec08c, NULL, 0, 0);
		}
		int width = 0;
		for (int i = 0; i <= 6; i++)
		{
			if (i != 0)
				width += 3;
			width += cco1_gameStrings_d382f0[i].size();
		}
		for (int i = 0, x = cco1_centerOffset(width, cco1_cec054->width_44b0d0() * cco1_fontCellWidth), y = cco1_d323c0; i <= 6; i++)
		{
			if (i != 0)
			{
				x += 1;
				putChar(x, y, 0x5c, *cco1_d2175c);
				x += 2;
			}
			tabButtons.push_back(new CcoP1Button(this, x, y, i, false));
			x += tabButtons.back()->width_44b0d0();
		}
		CcoPoint anchor;
		anchor = cco1_cec074->getPos();
		if (!cco1_d28d26)
		{
			new CcoP1Hud(this, anchor.x, anchor.y + 1, cco1_cec074->width_44b0d0(), " ( remaining core integrity )", cco1_cef820, cco1_cef81c);
			new CcoP1Hud(this, anchor.x, anchor.y + 2, cco1_cec074->width_44b0d0(), " ( available energy )", cco1_cef94c, cco1_cef95c);
			new CcoP1Hud(this, anchor.x, anchor.y + 3, cco1_cec074->width_44b0d0(), " ( available matter )", cco1_cef87c, cco1_cef8e0);
		}
		else
		{
			new CcoP1Hud(this, anchor.x, anchor.y + 1, cco1_cec074->width_44b0d0(), " ( remaining core integrity )", cco1_cef964, 0);
			new CcoP1Hud(this, anchor.x, anchor.y + 2, cco1_cec074->width_44b0d0(), " ( available energy )", cco1_cef964, 0);
			new CcoP1Hud(this, anchor.x, anchor.y + 3, cco1_cec074->width_44b0d0(), " ( available matter )", cco1_cef964, 0);
		}
		new CcoP1Hud(this, anchor.x, anchor.y + 4, cco1_cec074->width_44b0d0(), " ( system corruption level )", cco1_cef964, 0);
		new CcoP1Hud(this, anchor.x, anchor.y + 5, cco1_cec074->width_44b0d0(), " ( temperature/heat level )", cco1_cef964, 0);
		new CcoP1Hud(this, anchor.x, anchor.y + 6, cco1_cec074->width_44b0d0(), " ( movement type and speed )", cco1_cef964, 0);
		new CcoP1Hud(this, anchor.x, anchor.y + 8, cco1_cec074->width_44b0d0() / 2, " ( time elapsed )", cco1_cef964, 0);
		new CcoP1Hud(this, cco1_cec078->width_44b0d0() + anchor.x, anchor.y + 8, cco1_cec074->width_44b0d0() / 2, " ( current location )", cco1_cef964, 0);
		if (!cco1_hasPtr_cebd5c())
		{
			anchor = cco1_cec078->getPos();
			new CcoP1Hud(this, anchor.x + 1, anchor.y + 1, cco1_cec078->width_44b0d0() - 2, "( object data )", cco1_cef964, 0);
			if (cco1_cec054->operate())
			{
				anchor = cco1_cec084->getPos();
				new CcoP1Hud(this, anchor.x + 1, anchor.y + 1, cco1_cec084->width_44b0d0() - 2, "( target range, weapons,", cco1_cef964, 0);
				new CcoP1Hud(this, anchor.x + 1, anchor.y + 2, cco1_cec084->width_44b0d0() - 2, "  time/resource costs )", cco1_cef964, 0);
			}
			else
			{
				anchor = cco1_cec07c->getPos();
				new CcoP1Hud(this, anchor.x + 1, anchor.y + 1, cco1_cec07c->width_44b0d0() - 2, "( modified avoidance rate,", cco1_cef964, 0);
				new CcoP1Hud(this, anchor.x + 1, anchor.y + 2, cco1_cec07c->width_44b0d0() - 2, "  hover or \\ to open )", cco1_cef964, 0);
			}
		}
		if (ID >= 2)
			ID = cco1_d28d6c != 0;
		unknown144 = cco1_tickCount + 20;
	}
	else
		unknown60 = 2;
	switch (ID)
	{
	case 0:
{
	for (unsigned int i = 0; i < listb4.size(); i++)
		if (listb4[i])
			removeSubconsole(listb4[i]);
	listb4.clear();
	if (unknownc4)
	{
		removeSubconsole(unknownc4);
		unknownc4 = NULL;
	}
	if (unknownc8)
	{
		removeSubconsole(unknownc8);
		unknownc8 = NULL;
	}
	if (unknowncc)
	{
		removeSubconsole(unknowncc);
		unknowncc = NULL;
	}
	if (unknownd0)
	{
		removeSubconsole(unknownd0);
		unknownd0 = NULL;
	}
	for (unsigned int i = 0; i < sectionButtons.size(); i++)
		if (sectionButtons[i])
			removeSubconsole(sectionButtons[i]);
	sectionButtons.clear();
	for (unsigned int i = 0; i < liste8.size(); i++)
		if (liste8[i])
			removeSubconsole(liste8[i]);
	liste8.clear();
	if (unknown104)
	{
		removeSubconsole(unknown104);
		unknown104 = NULL;
	}
	if (unknown108)
	{
		removeSubconsole(unknown108);
		unknown108 = NULL;
	}
	for (unsigned int i = 0; i < list10c.size(); i++)
		if (list10c[i])
			removeSubconsole(list10c[i]);
	list10c.clear();
	for (unsigned int i = 0; i < optionButtons.size(); i++)
		if (optionButtons[i])
			removeSubconsole(optionButtons[i]);
	optionButtons.clear();
	for (unsigned int i = 0; i < optionValues.size(); i++)
		if (optionValues[i])
			removeSubconsole(optionValues[i]);
	optionValues.clear();
	if (unknown13c)
	{
		removeSubconsole(unknown13c);
		unknown13c = NULL;
	}
	for (unsigned int i = 0; i < list14c.size(); i++)
		if (list14c[i])
			removeSubconsole(list14c[i]);
	list14c.clear();
	for (unsigned int i = 0; i < list160.size(); i++)
		if (list160[i])
			removeSubconsole(list160[i]);
	list160.clear();
	for (unsigned int i = 0; i < list170.size(); i++)
		if (list170[i])
			removeSubconsole(list170[i]);
	list170.clear();
	for (unsigned int i = 0; i < list180.size(); i++)
		if (list180[i])
			removeSubconsole(list180[i]);
	list180.clear();
	if (unknown190)
	{
		removeSubconsole(unknown190);
		unknown190 = NULL;
	}
	if (unknown194)
	{
		removeSubconsole(unknown194);
		unknown194 = NULL;
	}
	if (unknown198)
	{
		removeSubconsole(unknown198);
		unknown198 = NULL;
	}
	for (unsigned int i = 0; i < list19c.size(); i++)
		if (list19c[i])
			removeSubconsole(list19c[i]);
	list19c.clear();
	for (unsigned int i = 0; i < list1ac.size(); i++)
		if (list1ac[i])
			removeSubconsole(list1ac[i]);
	list1ac.clear();
	for (unsigned int i = 0; i < list1bc.size(); i++)
		if (list1bc[i])
			removeSubconsole(list1bc[i]);
	list1bc.clear();
	if (unknown1cc)
	{
		removeSubconsole(unknown1cc);
		unknown1cc = NULL;
	}
	if (list80.empty())
	{
		CcoPoint pos;
		pos = cco2_d323bc;
		pos.translate(3, 2);
		list80.push_back(new CcoP2Basic(this, pos.x, pos.y, cco2_cec054->width_44b0d0() * cco2_caf128 - 5, 0));
		pos = cco2_cec0b0->getPos();
		pos.translate(3, 2);
		if (cco2_cebd5c == 2)
			pos.y += cco2_cec0b0->getHeight() - 1;
		list80.push_back(new CcoP2Basic(this, pos.x, pos.y, cco2_cec0b0->width_44b0d0() - 5, 1));
		switch (cco2_d28d64)
		{
		case 0:
			pos = cco2_cec0c8->getPos();
			pos.translate(3, 2);
			if (cco2_cebd5c == 2)
				pos.y += cco2_cec0c8->getHeight() - 1;
			list80.push_back(new CcoP2Basic(this, pos.x, pos.y, cco2_cec0c8->width_44b0d0() - 5, 2));
			break;
		case 1:
			pos = cco2_cec0cc->getPos();
			pos.translate(3, 2);
			if (cco2_cebd5c == 2)
				pos.y += cco2_cec0cc->getHeight() - 1;
			list80.push_back(new CcoP2Basic(this, pos.x, pos.y, cco2_cec0c8->width_44b0d0() - 5, 3));
			break;
		case 2:
			pos = cco2_cec0b8->getPos();
			pos.translate(3, 2);
			if (cco2_cebd5c == 2)
				pos.y += cco2_cec0b8->getHeight() - 1;
			list80.push_back(new CcoP2Basic(this, pos.x, pos.y, cco2_cec0b8->width_44b0d0() - 5, 4));
			break;
		case 3:
			pos = cco2_cec0c0->getPos();
			pos.translate(3, 2);
			if (cco2_cebd5c == 2)
				pos.y += cco2_cec0c0->getHeight() - 1;
			list80.push_back(new CcoP2Basic(this, pos.x, pos.y, cco2_cec0c0->width_44b0d0() - 5, 5));
			break;
		}
		pos = cco2_hasPtr_4328a0() ? cco2_cec078->getPos() : cco2_cec088->getPos();
		pos.translate(3, 2);
		list80.push_back(new CcoP2Basic(this, pos.x, pos.y, cco2_cec088->width_44b0d0() - 5, 6));
		if (cco2_cefc90 == 0)
		{
			pos = cco2_cec08c->getPos();
			pos.translate(3, 2);
			list80.push_back(new CcoP2Basic(this, pos.x, pos.y, cco2_cec08c->width_44b0d0() - 5, 7));
		}
	}
	else
	{
		list80[0]->setHidden(false);
		unknown60 = 3;
	}
	int x = cco2_halfDiff_437190(cco2_hasPtr_4328a0() ? 0x4f : 0x17, cco2_cefab4 * cco2_caf128);
	int y = cco2_d323c0 + 0x19;
	for (int i = 0; i < 3; i++)
	{
		if (!(cco2_d28de1 && i == 1) && !(cco2_d28de2 && i == 2))
		{
			list90.push_back(new CcoP2MenuButton(this, x, y, i + 0x61, i));
			if (unknown60 == 3)
				((CcoP2MenuButton *)list90.back())->setColors();
			if (cco2_hasPtr_4328a0())
				x += 0x1d;
			else
				y += 7;
		}
	}
	if (!cco2_cf45d8.isFlagActive() && cco2_cf4718 != 0 && !cco2_d28de3)
	{
		unknownb0 = cco2_cf45d8.unknown77e7c0();
		for (int i = 0, y = cco2_d323c0 + 4; i < 2; i++, y += 6)
		{
			lista0.push_back(new CcoP2SaveloadButton(this, y, i, unknownb0));
			if (unknown60 == 3)
				((CcoP2SaveloadButton *)lista0.back())->setHighlight();
		}
	}
	cco2_sound_4541b0(0x31, 0, 0);
}
		break;
	case 1:
for (unsigned int i = 0; i < list80.size(); i++)
	if (list80[i] != NULL)
		removeSubconsole(list80[i]);
list80.clear();
for (unsigned int i = 0; i < list90.size(); i++)
	if (list90[i] != NULL)
		removeSubconsole(list90[i]);
list90.clear();
for (unsigned int i = 0; i < lista0.size(); i++)
	if (lista0[i] != NULL)
		removeSubconsole(lista0[i]);
lista0.clear();
if (unknownd0 != NULL)
{
	removeSubconsole(unknownd0);
	unknownd0 = NULL;
}
for (unsigned int i = 0; i < sectionButtons.size(); i++)
	if (sectionButtons[i] != NULL)
		removeSubconsole(sectionButtons[i]);
sectionButtons.clear();
for (unsigned int i = 0; i < liste8.size(); i++)
	if (liste8[i] != NULL)
		removeSubconsole(liste8[i]);
liste8.clear();
if (unknown104 != NULL)
{
	removeSubconsole(unknown104);
	unknown104 = NULL;
}
if (unknown108 != NULL)
{
	removeSubconsole(unknown108);
	unknown108 = NULL;
}
for (unsigned int i = 0; i < list10c.size(); i++)
	if (list10c[i] != NULL)
		removeSubconsole(list10c[i]);
list10c.clear();
for (unsigned int i = 0; i < optionButtons.size(); i++)
	if (optionButtons[i] != NULL)
		removeSubconsole(optionButtons[i]);
optionButtons.clear();
for (unsigned int i = 0; i < optionValues.size(); i++)
	if (optionValues[i] != NULL)
		removeSubconsole(optionValues[i]);
optionValues.clear();
if (unknown13c != NULL)
{
	removeSubconsole(unknown13c);
	unknown13c = NULL;
}
for (unsigned int i = 0; i < list14c.size(); i++)
	if (list14c[i] != NULL)
		removeSubconsole(list14c[i]);
list14c.clear();
for (unsigned int i = 0; i < list160.size(); i++)
	if (list160[i] != NULL)
		removeSubconsole(list160[i]);
list160.clear();
for (unsigned int i = 0; i < list170.size(); i++)
	if (list170[i] != NULL)
		removeSubconsole(list170[i]);
list170.clear();
for (unsigned int i = 0; i < list180.size(); i++)
	if (list180[i] != NULL)
		removeSubconsole(list180[i]);
list180.clear();
if (unknown190 != NULL)
{
	removeSubconsole(unknown190);
	unknown190 = NULL;
}
if (unknown194 != NULL)
{
	removeSubconsole(unknown194);
	unknown194 = NULL;
}
if (unknown198 != NULL)
{
	removeSubconsole(unknown198);
	unknown198 = NULL;
}
for (unsigned int i = 0; i < list19c.size(); i++)
	if (list19c[i] != NULL)
		removeSubconsole(list19c[i]);
list19c.clear();
for (unsigned int i = 0; i < list1ac.size(); i++)
	if (list1ac[i] != NULL)
		removeSubconsole(list1ac[i]);
list1ac.clear();
for (unsigned int i = 0; i < list1bc.size(); i++)
	if (list1bc[i] != NULL)
		removeSubconsole(list1bc[i]);
list1bc.clear();
if (unknown1cc != NULL)
{
	removeSubconsole(unknown1cc);
	unknown1cc = NULL;
}
if (listb4.empty())
{
	CcoPoint pos;
	pos = cco3_d323bc;
	pos.translate(1, 2);
	listb4.push_back(new CcoP3Adv(this, pos.x, pos.y, cco3_cec054->width_44b0d0() * cco3_caf128 - cco3_caf128, 0));
	int y = pos.y + listb4.back()->getHeight() + 1;
	for (int i = 1; i <= (cco3_hasPtr() ? 2 : 4); i++)
	{
		listb4.push_back(new CcoP3Adv(this, pos.x, y, listb4.back()->width_44b0d0(), i));
		y = y + listb4.back()->getHeight() + 1;
	}
	pos = cco3_cec0b0->getPos();
	pos.translate(1, 2);
	if (cco3_cebd5c == 2)
		pos.y = pos.y + cco3_cec0b0->getHeight() - 1;
	listb4.push_back(new CcoP3Adv(this, pos.x, pos.y, cco3_cec0b0->width_44b0d0() - 2, 5));
	switch (cco3_d28d64)
	{
	case 0:
		pos = cco3_cec0c8->getPos();
		pos.translate(1, 2);
		if (cco3_cebd5c == 2)
			pos.y = pos.y + cco3_cec0c8->getHeight() - 1;
		listb4.push_back(new CcoP3Adv(this, pos.x, pos.y, cco3_cec0c8->width_44b0d0() - 2, 6));
		break;
	case 1:
		pos = cco3_cec0cc->getPos();
		pos.translate(1, 2);
		if (cco3_cebd5c == 2)
			pos.y = pos.y + cco3_cec0cc->getHeight() - 1;
		listb4.push_back(new CcoP3Adv(this, pos.x, pos.y, cco3_cec0cc->width_44b0d0() - 2, 7));
		break;
	case 2:
		pos = cco3_cec0b8->getPos();
		pos.translate(1, 2);
		if (cco3_cebd5c == 2)
			pos.y = pos.y + cco3_cec0b0->getHeight() - 1;
		listb4.push_back(new CcoP3Adv(this, pos.x, pos.y, cco3_cec0b8->width_44b0d0() - 2, 8));
		break;
	case 3:
		pos = cco3_cec0c0->getPos();
		pos.translate(1, 2);
		if (cco3_cebd5c == 2)
			pos.y = pos.y + cco3_cec0c0->getHeight() - 1;
		listb4.push_back(new CcoP3Adv(this, pos.x, pos.y, cco3_cec0c0->width_44b0d0() - 2, 9));
		break;
	}
	pos = cco3_hasPtr() ? cco3_cec078->getPos() : cco3_cec088->getPos();
	pos.translate(1, 2);
	listb4.push_back(new CcoP3Adv(this, pos.x, pos.y, cco3_cec088->width_44b0d0() - 2, 10));
	y = pos.y + listb4.back()->getHeight() + 1;
	listb4.push_back(new CcoP3Adv(this, pos.x, y, cco3_cec088->width_44b0d0() - 2, 11));
	if (cco3_cefc90 != 0)
	{
		y = y + listb4.back()->getHeight() + 1;
		listb4.push_back(new CcoP3Adv(this, pos.x, y, cco3_cec088->width_44b0d0() - 2, 12));
	}
	else
	{
		pos = cco3_cec08c->getPos();
		pos.translate(1, 2);
		listb4.push_back(new CcoP3Adv(this, pos.x, pos.y, cco3_cec08c->width_44b0d0() - 2, 13));
		y = pos.y + listb4.back()->getHeight() + 1;
		listb4.push_back(new CcoP3Adv(this, pos.x, y, cco3_cec08c->width_44b0d0() - 2, 14));
	}
	int line = 0;
	if (cco3_hasPtr())
	{
		unknownc4 = new CcoP3Page(this, cco3_centerOffset(0x12, cco3_cefab4 * cco3_caf128), cco3_d323bc.y + 0x1f);
		line = cco3_d323bc.y + 0x21;
		unknowncc = new Console(this, cco3_cefab4 * cco3_caf128, 1, 0, line, 0, true, -1);
		unknowncc->print(cco3_centerOffset(0x60, cco3_cf27f4 * cco3_caf128) + 0x12, 0, "Remember to look in other windows for their relevant commands");
		static_cast<CcoP3Con *>(unknowncc)->delegate_48c3c0(cco3_cef780);
	}
	else
		line = cco3_d323bc.y + 0x30;
	unknownc8 = new Console(this, cco3_cefab4 * cco3_caf128, 1, 0, line, 0, false, -1);
	unknownc8->print(cco3_centerOffset(0x60, cco3_cf27f4 * cco3_caf128), 0, "KP = Keypad/Numpad");
	unknownc8->print(cco3_centerOffset(0x60, cco3_cf27f4 * cco3_caf128) + 0x19, 0, "LMB/CMB/RMB = Left/Center/Right Mouse Button");
	unknownc8->print(cco3_centerOffset(0x60, cco3_cf27f4 * cco3_caf128) + 0x4d, 0, "Wheel = Mouse Wheel");
	static_cast<CcoP3Con *>(unknownc8)->delegate_48c3c0(cco3_cef780);
	cco3_playSound(0x2f, 0, 0);
}
else
{
	int count = unknownc4 == NULL ? 5 : (static_cast<CcoP3Page *>(unknownc4)->get_4ab670() == 1 ? 3 : 2);
	for (int i = 0; i < count; i++)
		listb4[i]->setHidden(false);
	if (unknownc4 != NULL)
		unknownc4->setHidden(false);
	if (unknownc4 != NULL && static_cast<CcoP3Page *>(unknownc4)->get_4ab670() == 2)
		unknowncc->setHidden(false);
	else
		unknownc8->setHidden(false);
	unknown60 = 3;
}
		break;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		if (!list80.empty())
			list80[0]->setHidden(true);
		else if (!listb4.empty())
		{
			int count = unknownc4 == NULL ? 5 : (static_cast<CcoP4Highlighted*>(unknownc4)->getHighlighter_4ab670() == 1 ? 3 : 2);
			for (int i = 0; i < count; i++)
				listb4[i]->setHidden(true);
			if (unknownc4 != NULL)
			{
				unknownc4->setHidden(true);
				unknowncc->setHidden(true);
			}
			unknownc8->setHidden(true);
		}
		for (int i = 0; i < list90.size(); i++)
			if (list90[i] != NULL)
				removeSubconsole(list90[i]);
		list90.clear();
		for (int i = 0; i < lista0.size(); i++)
			if (lista0[i] != NULL)
				removeSubconsole(lista0[i]);
		lista0.clear();
		switch (ID)
		{
		case 2:
			for (int i = 0; i < list10c.size(); i++)
				if (list10c[i] != NULL)
					removeSubconsole(list10c[i]);
			list10c.clear();
			for (int i = 0; i < optionButtons.size(); i++)
				if (optionButtons[i] != NULL)
					removeSubconsole(optionButtons[i]);
			optionButtons.clear();
			for (int i = 0; i < optionValues.size(); i++)
				if (optionValues[i] != NULL)
					removeSubconsole(optionValues[i]);
			optionValues.clear();
			if (unknown13c != NULL)
			{
				removeSubconsole(unknown13c);
				unknown13c = NULL;
			}
			for (int i = 0; i < list14c.size(); i++)
				if (list14c[i] != NULL)
					removeSubconsole(list14c[i]);
			list14c.clear();
			for (int i = 0; i < list160.size(); i++)
				if (list160[i] != NULL)
					removeSubconsole(list160[i]);
			list160.clear();
			for (int i = 0; i < list170.size(); i++)
				if (list170[i] != NULL)
					removeSubconsole(list170[i]);
			list170.clear();
			for (int i = 0; i < list180.size(); i++)
				if (list180[i] != NULL)
					removeSubconsole(list180[i]);
			list180.clear();
			if (unknown190 != NULL)
			{
				removeSubconsole(unknown190);
				unknown190 = NULL;
			}
			if (unknown194 != NULL)
			{
				removeSubconsole(unknown194);
				unknown194 = NULL;
			}
			if (unknown198 != NULL)
			{
				removeSubconsole(unknown198);
				unknown198 = NULL;
			}
			for (int i = 0; i < list19c.size(); i++)
				if (list19c[i] != NULL)
					removeSubconsole(list19c[i]);
			list19c.clear();
			for (int i = 0; i < list1ac.size(); i++)
				if (list1ac[i] != NULL)
					removeSubconsole(list1ac[i]);
			list1ac.clear();
			for (int i = 0; i < list1bc.size(); i++)
				if (list1bc[i] != NULL)
					removeSubconsole(list1bc[i]);
			list1bc.clear();
			if (unknown1cc != NULL)
			{
				removeSubconsole(unknown1cc);
				unknown1cc = NULL;
			}
			if (cco4_manualSections.size() > 26)
				cco4_logError("CCommands::open()", "Too many manual topics (" + cco4_intToString(cco4_manualSections.size()) + " > 26)");
			for (int i = 0, y = cco4_d323c0 + 4; i < cco4_manualSections.size() && i < 26; i++, y++)
				sectionButtons.push_back(new CcoP4ManualButton(this, y, i + 'a'));
			unknown7d14d0(page);
			unknownfc = 0;
			break;
		case 3:
{
	if (unknownd0)
	{
		removeSubconsole(unknownd0);
		unknownd0 = NULL;
	}
	for (unsigned int i = 0; i < sectionButtons.size(); i++)
		if (sectionButtons[i])
			removeSubconsole(sectionButtons[i]);
	sectionButtons.clear();
	for (unsigned int j = 0; j < liste8.size(); j++)
		if (liste8[j])
			removeSubconsole(liste8[j]);
	liste8.clear();
	if (unknown104)
	{
		removeSubconsole(unknown104);
		unknown104 = NULL;
	}
	if (unknown108)
	{
		removeSubconsole(unknown108);
		unknown108 = NULL;
	}
	for (unsigned int k = 0; k < list14c.size(); k++)
		if (list14c[k])
			removeSubconsole(list14c[k]);
	list14c.clear();
	for (unsigned int l = 0; l < list160.size(); l++)
		if (list160[l])
			removeSubconsole(list160[l]);
	list160.clear();
	for (unsigned int m = 0; m < list170.size(); m++)
		if (list170[m])
			removeSubconsole(list170[m]);
	list170.clear();
	for (unsigned int n = 0; n < list180.size(); n++)
		if (list180[n])
			removeSubconsole(list180[n]);
	list180.clear();
	if (unknown190)
	{
		removeSubconsole(unknown190);
		unknown190 = NULL;
	}
	if (unknown194)
	{
		removeSubconsole(unknown194);
		unknown194 = NULL;
	}
	if (unknown198)
	{
		removeSubconsole(unknown198);
		unknown198 = NULL;
	}
	for (unsigned int o = 0; o < list19c.size(); o++)
		if (list19c[o])
			removeSubconsole(list19c[o]);
	list19c.clear();
	for (unsigned int p = 0; p < list1ac.size(); p++)
		if (list1ac[p])
			removeSubconsole(list1ac[p]);
	list1ac.clear();
	for (unsigned int q = 0; q < list1bc.size(); q++)
		if (list1bc[q])
			removeSubconsole(list1bc[q]);
	list1bc.clear();
	if (unknown1cc)
	{
		removeSubconsole(unknown1cc);
		unknown1cc = NULL;
	}
	int y = cco5_d323c0 + 2;
	int x = cco5_cefab4 * cco5_caf128 / 2 - 40;
	int row = 0;
	int key = 0x61;
	list10c.push_back(new Console(this, 0x21, 1, x, y, 0, false, -1));
	list10c.back()->setCharRow(0, 0, list10c.back()->width_44b0d0(), 0x81);
	list10c.back()->print(4, 0, " General ");
	y++;
	for (int opt0 = 0; opt0 <= 6; opt0++, y++, row++)
	{
		optionButtons.push_back(new CcoP5OptionButton(this, y, key + row, opt0));
		optionValues.push_back(new CcoP5OptionValue(this, x + 0x1d, y, opt0));
	}
	y++;
	list10c.push_back(new Console(this, 0x21, 1, x, y, 0, false, -1));
	list10c.back()->setCharRow(0, 0, list10c.back()->width_44b0d0(), 0x81);
	list10c.back()->print(4, 0, " Audio ");
	y++;
	for (int opt1 = 7; opt1 <= 12; opt1++, y++, row++)
	{
		optionButtons.push_back(new CcoP5OptionButton(this, y, key + row, opt1));
		optionValues.push_back(new CcoP5OptionValue(this, x + 0x1d, y, opt1));
	}
	y++;
	list10c.push_back(new Console(this, 0x21, 1, x, y, 0, false, -1));
	list10c.back()->setCharRow(0, 0, list10c.back()->width_44b0d0(), 0x81);
	list10c.back()->print(4, 0, " Interface ");
	y++;
	for (int opt2 = 13; opt2 <= 21; opt2++, y++, row++)
	{
		optionButtons.push_back(new CcoP5OptionButton(this, y, key + row, opt2));
		optionValues.push_back(new CcoP5OptionValue(this, x + 0x1d, y, opt2));
	}
	y++;
	list10c.push_back(new Console(this, 0x21, 1, x, y, 0, false, -1));
	list10c.back()->setCharRow(0, 0, list10c.back()->width_44b0d0(), 0x81);
	list10c.back()->print(4, 0, " Behavior ");
	y++;
	for (int opt3 = 22; opt3 <= 24; opt3++, y++, row++)
	{
		optionButtons.push_back(new CcoP5OptionButton(this, y, key + row, opt3));
		optionValues.push_back(new CcoP5OptionValue(this, x + 0x1d, y, opt3));
	}
	y++;
	if (cco5_d223f0.unknown4189a0() >= 50)
		unknown13c = new Console(this, 0x4d, 5, x, y, 0, false, -1);
	else
	{
		unknown13c = new Console(this, cco5_cec088->width_44b0d0(), cco5_d223f0.unknown4189a0() - cco5_cec078->getPos().y, cco5_cec078->getPos().x, cco5_cec078->getPos().y, 0, false, -1);
		((CcoP5Frame *)unknown13c)->drawFrame(NULL, *cco5_d316f4, true, false);
		new Console(unknown13c, unknown13c->width_44b0d0() - 6, unknown13c->getHeight() - 5, 3, 3, 0, false, -1);
	}
	y = cco5_d323c0 + 2;
	x = cco5_cefab4 * cco5_caf128 / 2 + 4;
	row = 0;
	key = 0x41;
	list10c.push_back(new Console(this, 0x21, 1, x, y, 0, false, -1));
	list10c.back()->setCharRow(0, 0, list10c.back()->width_44b0d0(), 0x81);
	list10c.back()->print(4, 0, " Player ");
	y++;
	for (int opt4 = 25; opt4 <= 30; opt4++, y++, row++)
	{
		optionButtons.push_back(new CcoP5OptionButton(this, y, key + row, opt4));
		optionValues.push_back(new CcoP5OptionValue(this, x + 0x1d, y, opt4));
	}
	y++;
	list10c.push_back(new Console(this, 0x21, 1, x, y, 0, false, -1));
	list10c.back()->setCharRow(0, 0, list10c.back()->width_44b0d0(), 0x81);
	list10c.back()->print(4, 0, " Visualization ");
	y++;
	for (int opt5 = 31; opt5 <= 44; opt5++, y++, row++)
	{
		optionButtons.push_back(new CcoP5OptionButton(this, y, key + row, opt5));
		optionValues.push_back(new CcoP5OptionValue(this, x + 0x1d, y, opt5));
	}
	y++;
	list10c.push_back(new Console(this, 0x21, 1, x, y, 0, false, -1));
	list10c.back()->setCharRow(0, 0, list10c.back()->width_44b0d0(), 0x81);
	list10c.back()->print(4, 0, " Alarms ");
	y++;
	for (int opt6 = 45; opt6 <= 49; opt6++, y++, row++)
	{
		optionButtons.push_back(new CcoP5OptionButton(this, y, key + row, opt6));
		optionValues.push_back(new CcoP5OptionValue(this, x + 0x1d, y, opt6));
	}
	y++;
	cco5_playSound(0x31, 0, 0);
}
			break;
		case 4:
			{
			if (unknownd0)
			{
				removeSubconsole(unknownd0);
				unknownd0 = 0;
			}
			for (unsigned int i = 0; i < sectionButtons.size(); i++)
				if (sectionButtons[i])
					removeSubconsole(sectionButtons[i]);
			sectionButtons.clear();
			for (unsigned int i = 0; i < liste8.size(); i++)
				if (liste8[i])
					removeSubconsole(liste8[i]);
			liste8.clear();
			if (unknown104)
			{
				removeSubconsole(unknown104);
				unknown104 = 0;
			}
			if (unknown108)
			{
				removeSubconsole(unknown108);
				unknown108 = 0;
			}
			for (unsigned int i = 0; i < list10c.size(); i++)
				if (list10c[i])
					removeSubconsole(list10c[i]);
			list10c.clear();
			for (unsigned int i = 0; i < optionButtons.size(); i++)
				if (optionButtons[i])
					removeSubconsole(optionButtons[i]);
			optionButtons.clear();
			for (unsigned int i = 0; i < optionValues.size(); i++)
				if (optionValues[i])
					removeSubconsole(optionValues[i]);
			optionValues.clear();
			if (unknown13c)
			{
				removeSubconsole(unknown13c);
				unknown13c = 0;
			}
			for (unsigned int i = 0; i < list160.size(); i++)
				if (list160[i])
					removeSubconsole(list160[i]);
			list160.clear();
			for (unsigned int i = 0; i < list170.size(); i++)
				if (list170[i])
					removeSubconsole(list170[i]);
			list170.clear();
			for (unsigned int i = 0; i < list180.size(); i++)
				if (list180[i])
					removeSubconsole(list180[i]);
			list180.clear();
			if (unknown190)
			{
				removeSubconsole(unknown190);
				unknown190 = 0;
			}
			if (unknown194)
			{
				removeSubconsole(unknown194);
				unknown194 = 0;
			}
			if (unknown198)
			{
				removeSubconsole(unknown198);
				unknown198 = 0;
			}
			for (unsigned int i = 0; i < list19c.size(); i++)
				if (list19c[i])
					removeSubconsole(list19c[i]);
			list19c.clear();
			for (unsigned int i = 0; i < list1ac.size(); i++)
				if (list1ac[i])
					removeSubconsole(list1ac[i]);
			list1ac.clear();
			for (unsigned int i = 0; i < list1bc.size(); i++)
				if (list1bc[i])
					removeSubconsole(list1bc[i]);
			list1bc.clear();
			if (unknown1cc)
			{
				removeSubconsole(unknown1cc);
				unknown1cc = 0;
			}
				CcoPoint origin;
				origin = cco6_d323bc;
				origin += cco6_d21754;
				list14c.push_back(new CcoP6Box(this, origin.x, origin.y, 0x60, cco6_d223f0.height_4189a0() - 0x10, 0));
				list14c.back()->printWrapped_418260(0, 0, 0x60, cco6_d223f0.height_4189a0() - 0x10,
					cco6_d2571c.empty() ? string("(No news on record, activate News/Updates in the Options menu to check on startup)") : cco6_d2571c);
				origin.y = cco6_d223f0.height_4189a0() - 0xc;
				list14c.push_back(new CcoP6Box(this, origin.x, origin.y, 0x60, 1, 1));
				list14c.back()->print(0, 0, "Version: " + cco6_d21928 + "." + cco6_cf33fc);
				origin.y += 2;
				string latest;
				bool known = false;
				if (!cco6_d28d05)
					latest = "Unknown (activate News/Updates in the Options menu to check on startup)";
				else if (cco6_d256e0.empty())
					latest = "Unable to connect to www.gridsagegames.com for news/version check";
				else
				{
					latest = cco6_d256e0 + "." + cco6_d256fc;
					known = true;
				}
				list14c.push_back(new CcoP6Box(this, origin.x, origin.y, 0x60, 1, 1));
				list14c.back()->print(0, 0, "Latest Version: " + latest);
				if (known)
				{
					origin.y += 2;
					string current = cco6_convertBuildno_432720(cco6_cf33fc);
					string newest = cco6_convertBuildno_432720(cco6_d256fc);
					if (cco6_stringToFloat_405ab0(current) > cco6_stringToFloat_405ab0(newest))
					{
						list14c.push_back(new CcoP6Box(this, origin.x, origin.y, 0x60, 1, 1));
						list14c.back()->print(0, 0, "You're playing a prerelease version. Have fun but if you encounter issues please report them!");
					}
					else if (newest == current)
					{
						list14c.push_back(new CcoP6Box(this, origin.x, origin.y, 0x60, 1, 1));
						list14c.back()->print(0, 0, "This version of Cogmind appears to be up to date. Have fun!");
					}
					else
					{
						list14c.push_back(new CcoP6Box(this, origin.x, origin.y, 0x60, 1, 2));
						list14c.back()->print(0, 0, "A newer version of Cogmind is available for download.");
						origin.y += 1;
						list14c.push_back(new CcoP6Box(this, origin.x, origin.y, 0x60, 1, 2));
						list14c.back()->print(0, 0, "Use your download link (in the original purchase email) to get the latest release.");
					}
				}
				origin.y = cco6_d223f0.height_4189a0() - 4;
				list14c.push_back(new CcoP6Box(this, origin.x, origin.y, 0x60, 1, 3));
				list14c.back()->print(0, 0, "(You can deactivate update and news checks via the Options menu.)");
				cco6_d25738 = true;
				cco6_d25718 = true;
			}
			break;
		case 5:
{
	if (unknownd0)
	{
		removeSubconsole(unknownd0);
		unknownd0 = NULL;
	}
	for (int i = 0; i < sectionButtons.size(); i++)
		if (sectionButtons[i])
			removeSubconsole(sectionButtons[i]);
	sectionButtons.clear();
	for (int i = 0; i < liste8.size(); i++)
		if (liste8[i])
			removeSubconsole(liste8[i]);
	liste8.clear();
	if (unknown104)
	{
		removeSubconsole(unknown104);
		unknown104 = NULL;
	}
	if (unknown108)
	{
		removeSubconsole(unknown108);
		unknown108 = NULL;
	}
	for (int i = 0; i < list10c.size(); i++)
		if (list10c[i])
			removeSubconsole(list10c[i]);
	list10c.clear();
	for (int i = 0; i < optionButtons.size(); i++)
		if (optionButtons[i])
			removeSubconsole(optionButtons[i]);
	optionButtons.clear();
	for (int i = 0; i < optionValues.size(); i++)
		if (optionValues[i])
			removeSubconsole(optionValues[i]);
	optionValues.clear();
	if (unknown13c)
	{
		removeSubconsole(unknown13c);
		unknown13c = NULL;
	}
	for (int i = 0; i < list14c.size(); i++)
		if (list14c[i])
			removeSubconsole(list14c[i]);
	list14c.clear();
	for (int i = 0; i < list19c.size(); i++)
		if (list19c[i])
			removeSubconsole(list19c[i]);
	list19c.clear();
	for (int i = 0; i < list1ac.size(); i++)
		if (list1ac[i])
			removeSubconsole(list1ac[i]);
	list1ac.clear();
	for (int i = 0; i < list1bc.size(); i++)
		if (list1bc[i])
			removeSubconsole(list1bc[i]);
	list1bc.clear();
	if (unknown1cc)
	{
		removeSubconsole(unknown1cc);
		unknown1cc = NULL;
	}

	int where = cco7_hasPtr_4328a0() ? 1 : 0;
	CcoPoint corner;
	corner = cco7_d323bc;
	corner.x += (cco7_cec054->width_44b0d0() * cco7_caf128 - 0x60) / 2;
	corner.y += cco7_bca2dc[where];
	list160.push_back(new CcoP7Label(this, corner.x, corner.y, 0x60, 1, 0));
	list160.back()->printAligned(list160.back()->width_44b0d0() / 2, 0, 1, "Thanks for playing COGMIND, a roguelike by Grid Sage Games!");
	corner.y = cco7_d323c0 + cco7_bca6ec[where];
	list160.push_back(new CcoP7Label(this, corner.x, corner.y, 0x60, 1, 0));
	list160.back()->printAligned(list160.back()->width_44b0d0() / 2, 0, 1, "Get more information about the game at www.gridsagegames.com/cogmind/");
	corner.y = cco7_d323c0 + cco7_bca964[where];
	list160.push_back(new CcoP7Label(this, corner.x, corner.y, 0x60, 1, 3));
	list160.back()->printAligned(list160.back()->width_44b0d0() / 2, 0, 1, "(c) All Rights Reserved by Josh Ge and Grid Sage Games 2012-2024");

	vector<int> items;
	items.push_back(0);
	items.push_back(1);
	items.push_back(2);
	items.push_back(3);
	corner = cco7_d323bc;
	corner.x += cco7_cefab4 * cco7_caf128 / 2 - 0x17;
	corner.y += cco7_bcabbc[where];
	addGallerySection(corner, "JOSH GE", items);
	items.clear();
	items.push_back(5);
	corner = cco7_d323bc;
	corner.x += cco7_cefab4 * cco7_caf128 / 2 + 0x17;
	corner.y += cco7_bcac44[where];
	addGallerySection(corner, "KACPER WOZNIAK", items);
	items.clear();
	items.push_back(6);
	corner = cco7_d323bc;
	corner.x += cco7_cefab4 * cco7_caf128 / 2 + 0x17;
	corner.y += cco7_bcad24[where];
	addGallerySection(corner, "WILL GLYNN", items);
	corner = cco7_d323bc;
	corner.x += cco7_cefab4 * cco7_caf128 / 2 + 0x17;
	corner.x -= cco7_d39e3c.size() / 2;
	corner.y += cco7_bcaeb4[where];
	unknown194 = new CcoP7Button(this, corner.x, corner.y, 9, true);
	corner.y += 2;
	unknown198 = new CcoP7Button(this, corner.x, corner.y, 10, true);
	unknown48c3c0(cco7_cef948);
}
			break;
		case 6:
{
if (unknownd0 != NULL)
{
	removeSubconsole(unknownd0);
	unknownd0 = NULL;
}
for (unsigned int i = 0; i < sectionButtons.size(); i++)
	if (sectionButtons[i] != NULL)
		removeSubconsole(sectionButtons[i]);
sectionButtons.clear();
for (unsigned int i = 0; i < liste8.size(); i++)
	if (liste8[i] != NULL)
		removeSubconsole(liste8[i]);
liste8.clear();
if (unknown104 != NULL)
{
	removeSubconsole(unknown104);
	unknown104 = NULL;
}
if (unknown108 != NULL)
{
	removeSubconsole(unknown108);
	unknown108 = NULL;
}
for (unsigned int i = 0; i < list10c.size(); i++)
	if (list10c[i] != NULL)
		removeSubconsole(list10c[i]);
list10c.clear();
for (unsigned int i = 0; i < optionButtons.size(); i++)
	if (optionButtons[i] != NULL)
		removeSubconsole(optionButtons[i]);
optionButtons.clear();
for (unsigned int i = 0; i < optionValues.size(); i++)
	if (optionValues[i] != NULL)
		removeSubconsole(optionValues[i]);
optionValues.clear();
if (unknown13c != NULL)
{
	removeSubconsole(unknown13c);
	unknown13c = NULL;
}
for (unsigned int i = 0; i < list14c.size(); i++)
	if (list14c[i] != NULL)
		removeSubconsole(list14c[i]);
list14c.clear();
for (unsigned int i = 0; i < list160.size(); i++)
	if (list160[i] != NULL)
		removeSubconsole(list160[i]);
list160.clear();
for (unsigned int i = 0; i < list170.size(); i++)
	if (list170[i] != NULL)
		removeSubconsole(list170[i]);
list170.clear();
for (unsigned int i = 0; i < list180.size(); i++)
	if (list180[i] != NULL)
		removeSubconsole(list180[i]);
list180.clear();
if (unknown190 != NULL)
{
	removeSubconsole(unknown190);
	unknown190 = NULL;
}
if (unknown194 != NULL)
{
	removeSubconsole(unknown194);
	unknown194 = NULL;
}
if (unknown198 != NULL)
{
	removeSubconsole(unknown198);
	unknown198 = NULL;
}
unknown1cc = NULL;
int x = cco8_d323bc;
x = x + cco8_cec054->width_44b0d0() * cco8_caf128 / 2 - 26;
int y = cco8_d323c0 + 4;
for (int i = 0; i < 4; i++)
{
	list1ac.push_back(new Console(this, 1, 1, x, y, 0, false, -1));
	list1ac.back()->putChar(0, 0, '-', *cco8_cf44c0);
	list19c.push_back(new CcoP8Label(this, x - 2 - (cco8_d20a78[i].size() + 1), y, i));
	list1bc.push_back(new Console(this, 0x47, 5, x + 2, y, 0, false, -1));
	int lines = list1bc.back()->printWrapped_418260(0, 0, list1bc.back()->width_44b0d0(), list1bc.back()->getHeight(), cco8_d30558[i]);
	int anim;
	cco8_lookup_9d45a0("Type_GR3_Vert_E", &anim);
	for (int j = 0; j < list1bc.back()->width_44b0d0(); j++)
		((CcoP8Engine *)list1bc.back()->engine)->unknown50fb50((CcoP8Engine *)list1bc.back()->engine, anim, &Pos(j, 0), &cco8_d2e20c, &Pos(j, lines - 1), &CcoP8Point(cco8_d2e20c), 9)->init_50de10();
	y = y + lines + 1;
}
}
			break;
		}
		break;
	}
}
