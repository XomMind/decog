// hotel_01: CMission::CMission (0x96cc30, 108 KB): registers every input domain/command, then creates
//	the top-level game consoles (Beta 17.1).
// NOTE: class layouts are partial; names of globals/classes prefixed hotel_/Hotel_ are placeholders
//	(they stay stubs and pair with the exe by address). RTTI class names are real.
#include <string>
#include <vector>
using namespace std;

struct Hotel_Color	// NOTE: placeholder name (private XColor stand-in, keeps the vector instance private)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(int x_, int y_, int width_, int height_) throw();	// 0x456940
	Rect(const Rect &rect) throw();	// 0x40a720
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

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void resize(int width, int height);
	virtual bool input(void *event);
	virtual void update();
	virtual void render();
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	int unknown60;
	void *engine;
	void *title;
};

void logMessage(string message);
void logInfo(string location, string message);
void OpX5_fillInts(int *p, unsigned int count, int value);

struct OpR1a_Record	// NOTE: placeholder name (input command binding)
{
	int id;	// +0x00
	string name;	// +0x04
	bool flag20;	// +0x20
	int value24;	// +0x24
	bool flag28;
	bool flag29;
	bool flag2a;
	bool flag2b;
	bool flag2c;
	bool flag2d;

	OpR1a_Record(int id_, string name_, bool flag20_, int value24_, bool flag28_, bool flag29_, bool flag2a_, bool flag2b_, bool flag2c_, bool flag2d_);
};

class Hotel_CommandMgr	// NOTE: placeholder name (object behind 0xcefa8c)
{
public:
	void addCommand(int domain, int command);	// 0x416390
	unsigned int addNode();	// 0x416250
	void setMarked(unsigned int domain, bool marked);	// 0x4162e0
};
extern Hotel_CommandMgr *hotel_cefa8c;	// NOTE: placeholder name

class Hotel_Rex	// NOTE: placeholder name (REX at 0xd223f0)
{
public:
	XConsole *getRoot_4ab670();	// NOTE: placeholder name (folded getter)
	int getHeight_4189a0();	// NOTE: placeholder name (folded getter)
};
extern Hotel_Rex hotel_d223f0;	// NOTE: placeholder name

class Hotel_Keyboard	// NOTE: placeholder name (0xd338cc)
{
public:
	void init_438ad0();	// NOTE: placeholder name
};
extern Hotel_Keyboard hotel_d338cc;	// NOTE: placeholder name

class Hotel_Keys	// NOTE: placeholder name (0xd28c54)
{
public:
	void init_439650();	// NOTE: placeholder name
};
extern Hotel_Keys hotel_d28c54;	// NOTE: placeholder name

class Hotel_Pair	// NOTE: placeholder name (0xd2f1c8)
{
public:
	void unknown4b38a0();	// NOTE: placeholder name
};
extern Hotel_Pair hotel_d2f1c8;	// NOTE: placeholder name

class Hotel_JLog	// NOTE: placeholder name (0xcefa64)
{
public:
	int end_410e50(int type);	// NOTE: placeholder name
};
extern Hotel_JLog *hotel_cefa64;	// NOTE: placeholder name

// console classes created here (constructors defined elsewhere)
#define HOTEL_CONSOLE(name, size)	\
	class name : public Console	\
	{	\
	public:	\
		name(XConsole *parent);	\
		char pad6c[size - 0x6c];	\
	};
HOTEL_CONSOLE(CCommands, 0x1d4)
HOTEL_CONSOLE(CMap, 0x8c4)
HOTEL_CONSOLE(CWorldMap, 0xbc)
HOTEL_CONSOLE(CMapFine, 0xfc)
HOTEL_CONSOLE(CHud, 0x74)
HOTEL_CONSOLE(CAllies, 0xb0)
HOTEL_CONSOLE(CIntel, 0xfc)
HOTEL_CONSOLE(CMulticonsoleButtons, 0x80)
HOTEL_CONSOLE(CFovEnemies, 0x74)
HOTEL_CONSOLE(CHack, 0xa0)
HOTEL_CONSOLE(CInterfaceMsg, 0x8c)
HOTEL_CONSOLE(CEffects, 0x1b8)

class CLog : public Console
{
public:
	CLog(XConsole *parent, int mode);
	char pad6c[0x8c - 0x6c];
};

class CMainUiButtonHolder : public Console
{
public:
	CMainUiButtonHolder(XConsole *parent, int index, int width);	// NOTE: placeholder parameter names
	char pad6c[0x70 - 0x6c];
};

class CInfo : public Console
{
public:
	CInfo(XConsole *parent, bool flag, int layer);	// NOTE: placeholder parameter names
	char pad6c[0xfc - 0x6c];
};

class CMission : public Console
{
public:
	CMission();
	virtual ~CMission();
	virtual bool input(void *event);
	virtual void update();
	virtual void render();

	void unknown988270();	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
	bool unknown78;	// NOTE: placeholder name
	bool unknown79;	// NOTE: placeholder name
	int unknown7c;	// NOTE: placeholder name
	int unknown80[12];	// NOTE: placeholder name
	int unknownb0;	// NOTE: placeholder name
};

extern int hotel_d28d64;	// NOTE: placeholder name
extern bool hotel_cefacd;	// NOTE: placeholder name
extern bool hotel_d28d1d;	// NOTE: placeholder name
extern bool hotel_d28fbd;	// NOTE: placeholder name
extern int hotel_cebd5c;	// NOTE: placeholder name
extern int hotel_d33be0;	// NOTE: placeholder name
extern int hotel_d33be4;	// NOTE: placeholder name
extern int hotel_d33be8;	// NOTE: placeholder name
extern int hotel_d33bec;	// NOTE: placeholder name
extern Hotel_Color *hotel_cfe674;	// NOTE: placeholder name
extern vector<Hotel_Color> hotel_d2b4bc;	// NOTE: placeholder name

extern void *hotel_cec038;	// NOTE: placeholder name
extern CCommands *hotel_cec03c;	// NOTE: placeholder name
extern void *hotel_cec040;	// NOTE: placeholder name
extern void *hotel_cec124;	// NOTE: placeholder name
extern void *hotel_cec128;	// NOTE: placeholder name
extern void *hotel_cec044;	// NOTE: placeholder name
extern void *hotel_cec048;	// NOTE: placeholder name
extern void *hotel_cec04c;	// NOTE: placeholder name
extern void *hotel_cec050;	// NOTE: placeholder name
extern CMap *hotel_cec054;	// NOTE: placeholder name
extern CWorldMap *hotel_cec070;	// NOTE: placeholder name
extern CMapFine *hotel_cec058;	// NOTE: placeholder name
extern CHud *hotel_cec074;	// NOTE: placeholder name
extern CLog *hotel_cec0b0;	// NOTE: placeholder name
extern CLog *hotel_cec0c0;	// NOTE: placeholder name
extern CAllies *hotel_cec0c8;	// NOTE: placeholder name
extern CLog *hotel_cec0b8;	// NOTE: placeholder name
extern CIntel *hotel_cec0cc;	// NOTE: placeholder name
extern CMulticonsoleButtons *hotel_cec0d0;	// NOTE: placeholder name
extern CMainUiButtonHolder *hotel_cec0d4;	// NOTE: placeholder name
extern CMainUiButtonHolder *hotel_cec0d8;	// NOTE: placeholder name
extern CMainUiButtonHolder *hotel_cec0dc;	// NOTE: placeholder name
extern CMainUiButtonHolder *hotel_cec0e0;	// NOTE: placeholder name
extern CMainUiButtonHolder *hotel_cec0e4;	// NOTE: placeholder name
extern CMainUiButtonHolder *hotel_cec0e8;	// NOTE: placeholder name
extern CMainUiButtonHolder *hotel_cec0ec;	// NOTE: placeholder name
extern CFovEnemies *hotel_cec0f0;	// NOTE: placeholder name
extern CHack *hotel_cec0f8;	// NOTE: placeholder name
extern void *hotel_cec0fc;	// NOTE: placeholder name
extern void *hotel_cec100;	// NOTE: placeholder name
extern void *hotel_cec104;	// NOTE: placeholder name
extern void *hotel_cec108;	// NOTE: placeholder name
extern void *hotel_cec10c;	// NOTE: placeholder name
extern void *hotel_cec110;	// NOTE: placeholder name
extern void *hotel_cec114;	// NOTE: placeholder name
extern CInfo *hotel_cec118;	// NOTE: placeholder name
extern CInfo *hotel_cec11c;	// NOTE: placeholder name
extern CInfo *hotel_cec120;	// NOTE: placeholder name
extern void *hotel_cec134;	// NOTE: placeholder name
extern void *hotel_cec130;	// NOTE: placeholder name
extern void *hotel_cec12c;	// NOTE: placeholder name
extern CInterfaceMsg *hotel_cec0f4;	// NOTE: placeholder name
extern CEffects *hotel_cec138;	// NOTE: placeholder name

CMission::CMission()
	: Console(hotel_d223f0.getRoot_4ab670(),1,1,0,0,0,true,-1)
	, unknown6c	(0)
	, unknown70	(0)
	, unknown74	(0)
	, unknown78	(false)
	, unknownb0	(hotel_d28d64)
{
	logInfo("CMission()","Creating CMission");
	unknown79 = false;
	unknown7c = 0;
	OpX5_fillInts(unknown80,12,0);

	logMessage("Initializing input domains and commands");
	hotel_cefa8c->addCommand(0,(int)new OpR1a_Record(5,"button_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(7,"New Game",true,0x123,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(8,"Save Game",true,0x121,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(9,"Save & Quit (1)",true,0x73,true,true,true,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(9,"Save & Quit (2)",true,0x11d,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(10,"Load Game",true,0x122,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(11,"Toggle Keyboard Mode",true,0x11b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(12,"Toggle FPS Display",true,0x11c,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(13,"Toggle FPS Cap",true,0x11c,true,true,false,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(14,"Toggle Audio",true,0x124,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(15,"Volume Down",true,0x2d,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(16,"Volume Up",true,0x3d,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(17,"Toggle Tactical HUD",true,0x120,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(18,"Toggle Commands (1)",true,0x11a,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(18,"Toggle Commands (2)",true,0x3f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(18,"Toggle Commands (3)",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(1,(int)new OpR1a_Record(19,"Clear/Previous Message",true,0x30,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(1,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(20,"com_select_m",false,1,false,false,false,false,true,false));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(21,"Basic Commands",true,0x31,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(22,"Advanced Commands",true,0x32,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(23,"Manual",true,0x33,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(24,"Options",true,0x34,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(25,"News",true,0x35,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(26,"Credits",true,0x36,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(27,"Records",true,0x37,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(28,"Gallery",true,0x38,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(29,"Supporters",true,0x39,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(30,"Patrons",true,0x30,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(31,"Save Game",true,0x121,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(32,"Load Game",true,0x122,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(33,"com_nextpage",false,5,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(33,"Next Page (1)",true,0x112,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(33,"Next Page (2)",true,0x119,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(33,"Next Page (3)",true,0x10e,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(33,"Next Page (4)",true,0x102,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(33,"Next Page (5)",true,0x20,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(34,"com_prevpage",false,4,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(34,"Previous Page (1)",true,0x111,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(34,"Previous Page (2)",true,0x118,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(34,"Previous Page (3)",true,0x10d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(34,"Previous Page (4)",true,0x108,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(35,"Next Manual Topic (1)",true,0x113,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(35,"Next Manual Topic (2)",true,0x106,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(36,"Previous Manual Topic (1)",true,0x114,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(36,"Previous Manual Topic (2)",true,0x104,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(37,"Close (1)",true,0x11a,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(37,"Close (2)",true,0x3f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(37,"Close (3)",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(2,(int)new OpR1a_Record(37,"close",false,3,false,false,false,true,true,false));
	hotel_cefa8c->setMarked(2,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(38,"records_select_m",false,1,false,false,false,false,true,false));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(39,"Next Row (1)",true,0x113,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(39,"Next Row (2)",true,0x112,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(39,"Next Row (3)",true,0x10e,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(39,"Next Row (4)",true,0x102,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(39,"Next Row (5)",true,0x106,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(41,"records_nextpage",false,5,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(41,"Next Page (1)",true,0x119,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(41,"Next Page (2)",true,0x20,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(40,"Previous Row (1)",true,0x114,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(40,"Previous Row (2)",true,0x111,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(40,"Previous Row (3)",true,0x10d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(40,"Previous Row (4)",true,0x108,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(40,"Previous Row (5)",true,0x104,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(42,"records_prevpage",false,4,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(42,"Previous Page (1)",true,0x118,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(42,"Previous Page (2)",true,0x20,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(43,"First",true,0x116,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(44,"Last",true,0x117,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(45,"Close",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(3,(int)new OpR1a_Record(45,"records_close",false,3,false,false,false,true,true,false));
	hotel_cefa8c->setMarked(3,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(46,"debug_console",true,0x64,true,false,true,true,true,false));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(47,"Center on Self (1)",true,0x105,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(47,"Center on Self (2)",true,0xd,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(47,"Center on Self (3)",true,0x10f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(47,"center_self_m",false,2,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(48,"Cycle Map Center Reverse (1)",true,0x105,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(48,"Cycle Map Center Reverse (2)",true,0xd,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(48,"Cycle Map Center Reverse (3)",true,0x10f,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(48,"center_self_m",false,2,true,false,false,true,true,false));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(49,"Zoom Map",true,0x7a,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(50,"Zoom Map In",false,4,true,false,false,true,true,false));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(51,"Zoom Map Out",false,5,true,false,false,true,true,false));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(52,"Show Volley Range",true,0x76,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(52,"tog_v_rng_m",false,2,false,true,false,true,true,false));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(53,"Show Ruler",true,0x78,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(54,"Toggle Part Autoactivate",true,0x123,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(55,"Toggle Mouse Warping",true,0x125,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(56,"Toggle Cursor Centering",true,0x11d,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(57,"Toggle ASCII Mode",true,0x11c,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(58,"Toggle Autowaiting for Energy",true,0x11e,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(4,(int)new OpR1a_Record(59,"center_pos",false,1,true,false,false,true,true,false));
	hotel_cefa8c->setMarked(4,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(60,"break",true,0x62,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(61,"reload_mappcl",true,0x125,false,true,false,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(62,"reload_guipcl",true,0x125,true,true,false,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(63,"follow_entity",true,0x66,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(64,"toggle_ambience",true,0x6d,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(65,"show_ambience",true,0x61,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(66,"tog_pitch",true,0x116,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(67,"pitch_up",true,0x115,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(68,"pitch_down",true,0x7f,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(69,"show_encount",true,0x65,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(70,"show_caves",true,0x6a,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(71,"show_halls",true,0x68,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(72,"show_paths",true,0x70,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(73,"show_pings",true,0x67,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(74,"show_heat",true,0x78,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(75,"tog_overmap",true,0x6f,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(76,"tog_achievs",true,0x7a,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(77,"new_year",true,0x79,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(78,"tog_devnotes",true,0x71,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(5,(int)new OpR1a_Record(79,"toggle_ambience_one",false,2,false,false,true,true,true,false));
	hotel_cefa8c->setMarked(5,hotel_cefacd);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(6,(int)new OpR1a_Record(80,"fill_kmap",true,0x6b,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(6,(int)new OpR1a_Record(81,"clear_kmap",true,0x63,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(6,(int)new OpR1a_Record(82,"show_traps",true,0x74,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(6,(int)new OpR1a_Record(83,"show_fov_overlays",true,0x76,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(6,(int)new OpR1a_Record(84,"show_time",true,0x69,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(6,(int)new OpR1a_Record(85,"show_desire",true,0x72,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(6,(int)new OpR1a_Record(86,"next_depth",true,0x6e,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(6,(int)new OpR1a_Record(87,"teleport",false,3,false,false,true,true,true,false));
	hotel_cefa8c->addCommand(6,(int)new OpR1a_Record(88,"destroy",false,3,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(6,(int)new OpR1a_Record(89,"kill",false,1,true,true,true,true,true,false));
	hotel_cefa8c->addCommand(6,(int)new OpR1a_Record(90,"place_entity",false,1,false,false,true,true,true,false));
	hotel_cefa8c->addCommand(6,(int)new OpR1a_Record(91,"assign_faction",false,1,true,false,true,true,true,false));
	hotel_cefa8c->setMarked(6,hotel_cefacd);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(92,"Mapjump North (1)",true,0x108,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(92,"Mapjump North (2)",true,0x111,false,false,true,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(92,"Mapjump North (3)",true,0x6b,true,false,true,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(93,"Mapjump Northeast (1)",true,0x109,false,false,true,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(93,"Mapjump Northeast (3)",true,0x75,true,false,true,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(94,"Mapjump East (1)",true,0x106,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(94,"Mapjump East (2)",true,0x113,false,false,true,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(94,"Mapjump East (3)",true,0x6c,true,false,true,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(95,"Mapjump Southeast (1)",true,0x103,false,false,true,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(95,"Mapjump Southeast (3)",true,0x6e,true,false,true,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(96,"Mapjump South (1)",true,0x102,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(96,"Mapjump South (2)",true,0x112,false,false,true,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(96,"Mapjump South (3)",true,0x6a,true,false,true,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(97,"Mapjump Southwest (1)",true,0x101,false,false,true,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(97,"Mapjump Southwest (3)",true,0x62,true,false,true,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(98,"Mapjump West (1)",true,0x104,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(98,"Mapjump West (2)",true,0x114,false,false,true,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(98,"Mapjump West (3)",true,0x68,true,false,true,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(99,"Mapjump Northwest (1)",true,0x107,false,false,true,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(99,"Mapjump Northwest (3)",true,0x79,true,false,true,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(100,"Move North (1)",true,0x108,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(100,"Move North (2)",true,0x111,false,false,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(100,"Move North (3)",true,0x6b,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(101,"Move Northeast (1)",true,0x109,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(101,"Move Northeast (2)",true,0x113,true,false,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(101,"Move Northeast (3)",true,0x75,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(102,"Move East (1)",true,0x106,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(102,"Move East (2)",true,0x113,false,false,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(102,"Move East (3)",true,0x6c,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(103,"Move Southeast (1)",true,0x103,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(103,"Move Southeast (2)",true,0x113,false,true,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(103,"Move Southeast (3)",true,0x6e,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(104,"Move South (1)",true,0x102,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(104,"Move South (2)",true,0x112,false,false,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(104,"Move South (3)",true,0x6a,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(105,"Move Southwest (1)",true,0x101,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(105,"Move Southwest (2)",true,0x114,false,true,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(105,"Move Southwest (3)",true,0x62,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(106,"Move West (1)",true,0x104,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(106,"Move West (2)",true,0x114,false,false,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(106,"Move West (3)",true,0x68,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(107,"Move Northwest (1)",true,0x107,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(107,"Move Northwest (2)",true,0x114,true,false,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(107,"Move Northwest (3)",true,0x79,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(108,"Run North (1)",true,0x108,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(109,"Run Northeast (1)",true,0x109,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(110,"Run East (1)",true,0x106,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(111,"Run Southeast (1)",true,0x103,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(112,"Run South (1)",true,0x102,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(113,"Run Southwest (1)",true,0x101,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(114,"Run West (1)",true,0x104,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(115,"Run Northwest (1)",true,0x107,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(116,"Force Melee North (1)",true,0x108,true,true,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(116,"Force Melee North (2)",true,0x111,true,true,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(117,"Force Melee Northeast",true,0x109,true,true,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(118,"Force Melee East (1)",true,0x106,true,true,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(118,"Force Melee East (2)",true,0x113,true,true,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(119,"Force Melee Southeast",true,0x103,true,true,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(120,"Force Melee South (1)",true,0x102,true,true,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(120,"Force Melee South (2)",true,0x112,true,true,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(121,"Force Melee Southwest",true,0x101,true,true,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(122,"Force Melee West (1)",true,0x104,true,true,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(122,"Force Melee West (2)",true,0x114,true,true,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(123,"Force Melee Northwest",true,0x107,true,true,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(124,"Toggle Force Melee",true,0x65,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(125,"Cancel Run (1)",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(126,"Stair/Trap Interaction (1)",true,0x3c,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(126,"Stair/Trap Interaction (2)",true,0x3e,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(127,"Wait (1)",true,0x105,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(127,"Wait (2)",true,0x2e,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(128,"wait_m",false,4,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(128,"wait_m2",false,5,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(129,"Get Item",true,0x67,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(130,"Get Item and Attach",true,0x61,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(131,"Go Naked",true,0x70,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(132,"Examine (Look) Mode",true,0x78,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(133,"Fire",true,0x66,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(134,"Status",true,0x73,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(135,"Data (Info) (1)",true,0x64,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(136,"Data (Info) (2)",true,0x100,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(137,"Order Ally",true,0x6f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(138,"Show Orders",true,0x6f,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(139,"Map Intel Toggle Mode",true,0x6d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(140,"Label Hostiles",true,0x31,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(141,"Label Friendlies",true,0x32,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(142,"Label Parts",true,0x33,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(143,"Label Exits",true,0x34,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(145,"Next Label Category (1)",true,9,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(145,"Next Label Category (2)",true,0x3d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(145,"Next Label Category (3)",true,0x10e,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(146,"Previous Label Category (1)",true,9,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(146,"Previous Label Category (2)",true,0x2d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(146,"Previous Label Category (3)",true,0x10d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(147,"Go via Pathfind",true,0x67,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(148,"Map Comments",true,0x63,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(149,"Output Map",true,0x6d,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(150,"Output Stat Dump",true,0x73,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(152,"Special Mode UI",true,0x39,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(151,"Show World Map (1)",true,0x122,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(151,"Show World Map (2)",true,8,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(153,"move",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(154,"fast_attach_m",false,1,false,true,false,true,true,false));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(155,"rmb_prep",false,3,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(156,"default_info",false,3,false,false,false,false,true,false));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(157,"fmelee_m",false,1,true,true,false,true,true,false));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(158,"secondary_m",false,3,true,false,false,true,true,false));
	hotel_cefa8c->addCommand(7,(int)new OpR1a_Record(159,"rmb_ctrl_m",false,3,false,true,false,true,true,false));
	hotel_cefa8c->setMarked(7,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(160,"targ_conf",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(161,"targ_rmb",false,3,false,false,false,false,true,false));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(162,"targ_rmb_ctrl",false,3,false,true,false,true,true,false));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(163,"Cancel (1)",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(163,"Cancel (2)",true,0x78,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(164,"Center Cursor (1)",true,8,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(164,"Center Cursor (2)",true,0x10f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(165,"Set View Centerpoint",true,0x73,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(166,"Next Target (1)",true,9,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(166,"Next Target (2)",true,0x3d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(166,"Next Target (3)",true,0x10e,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(167,"Previous Target (1)",true,9,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(167,"Previous Target (2)",true,0x2d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(167,"Previous Target (3)",true,0x10d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(168,"Next Item (1)",true,9,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(168,"Next Item (2)",true,0x10e,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(169,"Previous Item (1)",true,9,true,true,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(169,"Previous Item (2)",true,0x10d,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(170,"Data (Info) (1)",true,0x64,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(170,"Data (Info) (2)",true,0x100,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(171,"Order Ally",true,0x6f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(172,"Set Guided Waypoint (1)",true,0xd,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(172,"Set Guided Waypoint (2)",true,0x105,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(173,"Fire",true,0x66,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(174,"Move North (1)",true,0x108,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(174,"Move North (2)",true,0x111,false,false,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(174,"Move North (3)",true,0x6b,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(175,"Move Northeast (1)",true,0x109,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(175,"Move Northeast (2)",true,0x113,true,false,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(175,"Move Northeast (3)",true,0x75,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(176,"Move East (1)",true,0x106,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(176,"Move East (2)",true,0x113,false,false,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(176,"Move East (3)",true,0x6c,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(177,"Move Southeast (1)",true,0x103,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(177,"Move Southeast (2)",true,0x113,false,true,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(177,"Move Southeast (3)",true,0x6e,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(178,"Move South (1)",true,0x102,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(178,"Move South (2)",true,0x112,false,false,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(178,"Move South (3)",true,0x6a,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(179,"Move Southwest (1)",true,0x101,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(179,"Move Southwest (2)",true,0x114,false,true,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(179,"Move Southwest (3)",true,0x62,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(180,"Move West (1)",true,0x104,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(180,"Move West (2)",true,0x114,false,false,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(180,"Move West (3)",true,0x68,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(181,"Move Northwest (1)",true,0x107,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(181,"Move Northwest (2)",true,0x114,true,false,false,true,false,true));
	if (hotel_d28d1d) {} else {
		hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(181,"Move Northwest (3)",true,0x79,false,false,false,true,false,true));
	}
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(182,"Jump North",true,0x108,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(183,"Jump Northeast",true,0x109,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(184,"Jump East",true,0x106,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(185,"Jump Southeast",true,0x103,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(186,"Jump South",true,0x102,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(187,"Jump Southwest",true,0x101,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(188,"Jump West",true,0x104,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(189,"Jump Northwest",true,0x107,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(190,"Go via Pathfind",true,0x67,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(191,"Close Map Comments",true,0x63,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(192,"Add Map Comment",true,0x63,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(8,(int)new OpR1a_Record(193,"Remove Map Comment",true,0x72,false,false,false,true,false,true));
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(9,(int)new OpR1a_Record(194,"Line Up (Log)",true,0x10d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(9,(int)new OpR1a_Record(195,"Line Down (Log)",true,0x10e,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(9,(int)new OpR1a_Record(196,"Line Up (Calc)",true,0x3d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(9,(int)new OpR1a_Record(197,"Line Down (Calc)",true,0x2d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(9,(int)new OpR1a_Record(198,"log_scrollup",false,4,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(9,(int)new OpR1a_Record(199,"log_scrolldn",false,5,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(9,(int)new OpR1a_Record(200,"Page Up",true,0x118,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(9,(int)new OpR1a_Record(201,"Page Down",true,0x119,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(9,(int)new OpR1a_Record(202,"End",true,0x117,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(9,(int)new OpR1a_Record(203,"Expand/Shrink",true,0x11d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(9,(int)new OpR1a_Record(204,"log_lmb_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(9,(int)new OpR1a_Record(205,"log_rmb_m",false,3,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(9,(int)new OpR1a_Record(206,"Cancel (1)",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(9,(int)new OpR1a_Record(206,"Cancel (2)",true,0x121,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(9,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(10,(int)new OpR1a_Record(207,"mcon_select_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(10,(int)new OpR1a_Record(208,"Show Allies",true,0x11e,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(10,(int)new OpR1a_Record(209,"Show Intel",true,0x11f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(10,(int)new OpR1a_Record(210,"Show Extended Log",true,0x120,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(10,(int)new OpR1a_Record(211,"Show Calculations",true,0x121,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(10,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(212,"Line Up",true,0x3d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(212,"ally_up2",false,5,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(213,"Line Down",true,0x2d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(213,"ally_down2",false,4,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(216,"ally_order_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(217,"ally_info_m",false,3,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(218,"Order Ally 0",true,0x30,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(219,"Order Ally 1",true,0x31,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(220,"Order Ally 2",true,0x32,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(221,"Order Ally 3",true,0x33,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(222,"Order Ally 4",true,0x34,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(223,"Order Ally 5",true,0x35,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(218,"Order Ally 0 KP",true,0x100,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(219,"Order Ally 1 KP",true,0x101,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(220,"Order Ally 2 KP",true,0x102,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(221,"Order Ally 3 KP",true,0x103,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(222,"Order Ally 4 KP",true,0x104,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(223,"Order Ally 5 KP",true,0x105,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(224,"Ally 0 Info",true,0x29,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(225,"Ally 1 Info",true,0x21,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(226,"Ally 2 Info",true,0x40,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(227,"Ally 3 Info",true,0x23,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(228,"Ally 4 Info",true,0x24,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(229,"Ally 5 Info",true,0x25,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(230,"Order All Repairs",true,0x72,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(231,"Cancel (1)",true,0x6f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(231,"Cancel (2)",true,0x6d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(231,"Cancel (3)",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(231,"Cancel (4)",true,0x11e,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(11,(int)new OpR1a_Record(231,"Cancel (5)",true,0x11f,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(11,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(232,"info_select_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(233,"Schematics (Parts)",true,0x70,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(234,"Schematics (Robots)",true,0x72,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(235,"Studies (Parts)",true,0x6c,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(236,"Analysis (Robots)",true,0x61,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(237,"Traits (Robots)",true,0x74,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(238,"Rename (Robots)",true,0x6e,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(239,"More (Robots/Items)",true,0x6d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(240,"Context Help (1)",true,0xd,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(240,"Context Help (2)",true,0x10f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(241,"Help Previous (1)",true,0x111,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(241,"Help Previous (2)",true,0x108,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(241,"Help Previous (3)",true,0x6b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(242,"Help Next (1)",true,0x112,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(242,"Help Next (2)",true,0x102,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(242,"Help Next (3)",true,0x6a,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(243,"Close (1)",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(243,"Close (2)",true,0x73,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(243,"Close (3)",true,0x64,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(243,"Close (4)",true,0x100,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(12,(int)new OpR1a_Record(243,"info_close6",false,3,false,false,false,true,true,false));
	hotel_cefa8c->setMarked(12,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(13,(int)new OpR1a_Record(244,"analysis_select_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(13,(int)new OpR1a_Record(245,"Close (1)",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(13,(int)new OpR1a_Record(245,"Close (2)",true,0x61,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(13,(int)new OpR1a_Record(245,"Close (3)",true,0x74,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(13,(int)new OpR1a_Record(245,"Close (4)",true,0x6d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(13,(int)new OpR1a_Record(245,"Close (5)",true,0x69,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(13,(int)new OpR1a_Record(245,"Close (6)",true,0x20,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(13,(int)new OpR1a_Record(245,"analysis_close2",false,3,false,false,false,true,true,false));
	hotel_cefa8c->setMarked(13,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(14,(int)new OpR1a_Record(246,"hack_select_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(14,(int)new OpR1a_Record(247,"hack_info_m",false,3,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(14,(int)new OpR1a_Record(248,"Toggle Keyboard Mode",true,0x11b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(14,(int)new OpR1a_Record(249,"hack_scrollup",false,4,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(14,(int)new OpR1a_Record(249,"Scroll Up",true,0x111,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(14,(int)new OpR1a_Record(250,"hack_scrolldn",false,5,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(14,(int)new OpR1a_Record(250,"Scroll Down",true,0x112,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(14,(int)new OpR1a_Record(251,"Page Up",true,0x118,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(14,(int)new OpR1a_Record(252,"Page Down",true,0x119,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(14,(int)new OpR1a_Record(253,"First",true,0x116,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(14,(int)new OpR1a_Record(254,"Last",true,0x117,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(14,(int)new OpR1a_Record(255,"Close",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(14,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(15,(int)new OpR1a_Record(256,"type_select_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(15,(int)new OpR1a_Record(257,"Close",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(15,(int)new OpR1a_Record(257,"type_close2",false,3,false,false,false,true,true,false));
	hotel_cefa8c->setMarked(15,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(16,(int)new OpR1a_Record(258,"code_select_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(16,(int)new OpR1a_Record(259,"Return (1)",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(16,(int)new OpR1a_Record(259,"Return (2)",true,8,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(16,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(17,(int)new OpR1a_Record(260,"trans_adv1",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(17,(int)new OpR1a_Record(260,"trans_adv2",false,4,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(17,(int)new OpR1a_Record(260,"trans_adv3",false,5,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(17,(int)new OpR1a_Record(260,"Continue (1)",true,0x20,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(17,(int)new OpR1a_Record(260,"Continue (2)",true,0xd,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(17,(int)new OpR1a_Record(260,"Continue (3)",true,0x112,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(17,(int)new OpR1a_Record(260,"Continue (4)",true,0x102,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(17,(int)new OpR1a_Record(260,"Continue (5)",true,0x10f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(17,(int)new OpR1a_Record(260,"Continue (6)",true,0x119,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(17,(int)new OpR1a_Record(261,"Close",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(17,(int)new OpR1a_Record(261,"trans_close2",false,3,false,false,false,true,true,false));
	hotel_cefa8c->setMarked(17,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(18,(int)new OpR1a_Record(262,"list_select_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(18,(int)new OpR1a_Record(263,"list_info_m",false,3,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(18,(int)new OpR1a_Record(264,"list_scrollup",false,5,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(18,(int)new OpR1a_Record(264,"Scroll Up",true,0x112,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(18,(int)new OpR1a_Record(265,"list_scrolldn",false,4,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(18,(int)new OpR1a_Record(265,"Scroll Down",true,0x111,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(18,(int)new OpR1a_Record(266,"Page Up",true,0x118,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(18,(int)new OpR1a_Record(267,"Page Down",true,0x119,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(18,(int)new OpR1a_Record(268,"First",true,0x116,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(18,(int)new OpR1a_Record(269,"Last",true,0x117,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(18,(int)new OpR1a_Record(270,"Close",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(18,(int)new OpR1a_Record(271,"Close Special Mode UI",true,0x39,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(18,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(272,"Show Autopairs",true,0x61,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(273,"Reswap",true,0x72,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(274,"Detach-Drop",true,0x2c,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(275,"Sort Parts",true,0x3a,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(276,"Cycle Propulsion Mode",true,0x3b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(277,"Toggle Upkeep Utilities",true,0x22,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(278,"Toggle All Weapons",true,0x27,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(279,"part_select_m",false,1,false,false,false,false,true,false));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(280,"part_remove_m",false,1,false,true,false,true,true,false));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(281,"part_info_m",false,3,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(282,"part_dad_m1",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(282,"part_dad_m2",false,1,true,false,false,true,true,false));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(283,"part_swap_m",false,3,false,true,false,true,true,false));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(284,"Vis. Coverage/Vulnerability",true,0x63,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(285,"Vis. Energy/Heat",true,0x65,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(286,"Vis. Integrity/Mass",true,0x77,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(287,"Vis. Info/Matter",true,0x71,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(19,(int)new OpR1a_Record(288,"RIF Abilities",true,0x69,true,false,true,true,false,true));
	hotel_cefa8c->setMarked(19,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(289,"Open/Close",true,0x69,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(290,"Line Down",true,0x5d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(290,"inv_up2",false,5,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(291,"Line Up",true,0x5b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(291,"inv_down2",false,4,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(293,"Page Down",true,0x5d,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(293,"inv_pgdn2",false,5,false,true,false,true,true,false));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(292,"Page Up",true,0x5b,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(292,"inv_pgup2",false,4,false,true,false,true,true,false));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(294,"Sort Type",true,0x74,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(295,"inv_select_m",false,1,false,false,false,false,true,false));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(296,"inv_info_m",false,3,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(297,"inv_drop_m",false,1,false,true,false,true,true,false));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(298,"inv_dad_m1",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(298,"inv_dad_m2",false,1,true,false,false,true,true,false));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(299,"inv_swap_m",false,3,false,true,false,true,true,false));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(300,"Item 1 Info",true,0x21,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(301,"Item 2 Info",true,0x40,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(302,"Item 3 Info",true,0x23,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(303,"Item 4 Info",true,0x24,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(304,"Item 5 Info",true,0x25,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(305,"Item 6 Info",true,0x5e,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(306,"Item 7 Info",true,0x26,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(307,"Item 8 Info",true,0x2a,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(308,"Item 9 Info",true,0x28,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(309,"Item 0 Info",true,0x29,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(310,"Equip Item 1",true,0x31,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(311,"Equip Item 2",true,0x32,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(312,"Equip Item 3",true,0x33,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(313,"Equip Item 4",true,0x34,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(314,"Equip Item 5",true,0x35,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(315,"Equip Item 6",true,0x36,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(316,"Equip Item 7",true,0x37,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(317,"Equip Item 8",true,0x38,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(318,"Equip Item 9",true,0x39,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(319,"Equip Item 0",true,0x30,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(310,"Equip Item 1 KP",true,0x101,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(311,"Equip Item 2 KP",true,0x102,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(312,"Equip Item 3 KP",true,0x103,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(313,"Equip Item 4 KP",true,0x104,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(314,"Equip Item 5 KP",true,0x105,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(315,"Equip Item 6 KP",true,0x106,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(316,"Equip Item 7 KP",true,0x107,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(317,"Equip Item 8 KP",true,0x108,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(318,"Equip Item 9 KP",true,0x109,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(319,"Equip Item 0 KP",true,0x100,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(320,"Drop Item 1",true,0x31,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(321,"Drop Item 2",true,0x32,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(322,"Drop Item 3",true,0x33,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(323,"Drop Item 4",true,0x34,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(324,"Drop Item 5",true,0x35,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(325,"Drop Item 6",true,0x36,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(326,"Drop Item 7",true,0x37,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(327,"Drop Item 8",true,0x38,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(328,"Drop Item 9",true,0x39,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(329,"Drop Item 0",true,0x30,false,false,true,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(330,"Swap Item 1",true,0x21,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(331,"Swap Item 2",true,0x40,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(332,"Swap Item 3",true,0x23,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(333,"Swap Item 4",true,0x24,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(334,"Swap Item 5",true,0x25,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(335,"Swap Item 6",true,0x5e,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(336,"Swap Item 7",true,0x26,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(337,"Swap Item 8",true,0x2a,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(338,"Swap Item 9",true,0x28,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(20,(int)new OpR1a_Record(339,"Swap Item 0",true,0x29,false,true,false,true,false,true));
	hotel_cefa8c->setMarked(20,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(21,(int)new OpR1a_Record(340,"dragdrop_ok_m",false,1,false,false,false,false,true,false));
	hotel_cefa8c->addCommand(21,(int)new OpR1a_Record(340,"dragdrop_ok_m",false,1,true,false,false,false,true,false));
	hotel_cefa8c->addCommand(21,(int)new OpR1a_Record(341,"Cancel",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(21,(int)new OpR1a_Record(341,"dragdrop_quit",false,3,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(21,(int)new OpR1a_Record(341,"dragdrop_quit",false,3,true,false,false,true,true,false));
	hotel_cefa8c->addCommand(21,(int)new OpR1a_Record(341,"dragdrop_quit",false,3,false,true,false,true,true,false));
	hotel_cefa8c->addCommand(21,(int)new OpR1a_Record(341,"dragdrop_quit",false,3,false,false,true,true,true,false));
	hotel_cefa8c->addCommand(21,(int)new OpR1a_Record(341,"dragdrop_quit",false,3,true,true,false,true,true,false));
	hotel_cefa8c->addCommand(21,(int)new OpR1a_Record(341,"dragdrop_quit",false,3,true,true,true,true,true,false));
	hotel_cefa8c->setMarked(21,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(22,(int)new OpR1a_Record(342,"swap_select_m",false,1,false,false,false,false,true,false));
	hotel_cefa8c->addCommand(22,(int)new OpR1a_Record(343,"Start/Cancel (1)",true,0x2f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(22,(int)new OpR1a_Record(343,"Start/Cancel (2)",true,0x10b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(22,(int)new OpR1a_Record(344,"Cancel",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(22,(int)new OpR1a_Record(344,"swap_cancel2",false,3,false,false,false,true,true,false));
	hotel_cefa8c->setMarked(22,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(23,(int)new OpR1a_Record(345,"Direct Drop",true,0x2c,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(23,(int)new OpR1a_Record(346,"Line Down",true,0x5d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(23,(int)new OpR1a_Record(347,"Line Up",true,0x5b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(23,(int)new OpR1a_Record(348,"Page Down",true,0x5d,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(23,(int)new OpR1a_Record(349,"Page Up",true,0x5b,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(23,(int)new OpR1a_Record(350,"Cancel",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(23,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(24,(int)new OpR1a_Record(351,"Part Management",true,0x70,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(24,(int)new OpR1a_Record(352,"Toggle State",true,0x74,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(24,(int)new OpR1a_Record(353,"Attach",true,0x61,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(24,(int)new OpR1a_Record(354,"Info",true,0x69,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(24,(int)new OpR1a_Record(355,"Remove",true,0x72,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(24,(int)new OpR1a_Record(356,"Drop",true,0x64,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(24,(int)new OpR1a_Record(357,"Line Down",true,0x5d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(24,(int)new OpR1a_Record(358,"Line Up",true,0x5b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(24,(int)new OpR1a_Record(359,"Page Down",true,0x5d,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(24,(int)new OpR1a_Record(360,"Page Up",true,0x5b,false,true,false,true,false,true));
	hotel_cefa8c->addCommand(24,(int)new OpR1a_Record(361,"Cancel",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(24,(int)new OpR1a_Record(361,"partmanage_cancel2",false,3,false,false,false,true,true,false));
	hotel_cefa8c->setMarked(24,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(362,"Start/Cancel",true,0x60,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(363,"Cancel",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(364,"Jump North (1)",true,0x108,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(364,"Jump North (2)",true,0x111,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(364,"Jump North (3)",true,0x6b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(365,"Jump Northeast (1)",true,0x109,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(365,"Jump Northeast (3)",true,0x75,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(366,"Jump East (1)",true,0x106,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(366,"Jump East (2)",true,0x113,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(366,"Jump East (3)",true,0x6c,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(367,"Jump Southeast (1)",true,0x103,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(367,"Jump Southeast (3)",true,0x6e,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(368,"Jump South (1)",true,0x102,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(368,"Jump South (2)",true,0x112,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(368,"Jump South (3)",true,0x6a,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(369,"Jump Southwest (1)",true,0x101,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(369,"Jump Southwest (3)",true,0x62,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(370,"Jump West (1)",true,0x104,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(370,"Jump West (2)",true,0x114,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(370,"Jump West (3)",true,0x68,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(371,"Jump Northwest (1)",true,0x107,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(25,(int)new OpR1a_Record(371,"Jump Northwest (3)",true,0x79,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(25,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(26,(int)new OpR1a_Record(372,"Start/Cancel Item Tag",true,0x74,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(26,(int)new OpR1a_Record(373,"Start/Cancel Log Note",true,0x7a,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(26,(int)new OpR1a_Record(374,"Cancel",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(26,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(27,(int)new OpR1a_Record(375,"Start/Cancel Search",true,0x66,true,false,true,true,false,true));
	hotel_cefa8c->addCommand(27,(int)new OpR1a_Record(376,"Scroll Up",true,0x10d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(27,(int)new OpR1a_Record(376,"search_up2",false,4,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(27,(int)new OpR1a_Record(377,"Scroll Down",true,0x10e,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(27,(int)new OpR1a_Record(377,"search_down2",false,5,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(27,(int)new OpR1a_Record(378,"Page Up",true,0x118,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(27,(int)new OpR1a_Record(378,"search_pgup2",false,4,false,true,false,true,true,false));
	hotel_cefa8c->addCommand(27,(int)new OpR1a_Record(379,"Page Down",true,0x119,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(27,(int)new OpR1a_Record(379,"search_pgdn2",false,5,false,true,false,true,true,false));
	hotel_cefa8c->addCommand(27,(int)new OpR1a_Record(380,"First",true,0x116,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(27,(int)new OpR1a_Record(381,"Last",true,0x117,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(27,(int)new OpR1a_Record(382,"Cancel",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(27,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(28,(int)new OpR1a_Record(383,"Open/Close Menu",true,0x20,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(28,(int)new OpR1a_Record(384,"specialcommands_select_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(28,(int)new OpR1a_Record(385,"Cancel",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(28,true);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(29,(int)new OpR1a_Record(386,"Close (1)",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(29,(int)new OpR1a_Record(386,"Close (2)",true,0xd,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(29,(int)new OpR1a_Record(386,"Close (3)",true,0x111,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(29,(int)new OpR1a_Record(386,"Close (4)",true,0x112,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(29,(int)new OpR1a_Record(386,"Close (5)",true,0x10f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(29,(int)new OpR1a_Record(386,"help_close",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(29,(int)new OpR1a_Record(386,"help_close",false,3,false,false,false,true,true,false));
	hotel_cefa8c->setMarked(29,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(387,"Next Area (1)",true,0x111,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(387,"Next Area (2)",true,0x118,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(387,"Next Area (3)",true,0x10d,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(387,"Next Area (4)",true,0x108,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(387,"Next Area (5)",true,0x6b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(388,"Previous Area (1)",true,0x112,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(388,"Previous Area (2)",true,0x119,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(388,"Previous Area (3)",true,0x10e,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(388,"Previous Area (4)",true,0x102,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(388,"Previous Area (5)",true,0x6a,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(389,"Close (1)",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(389,"Close (2)",true,0x122,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(389,"Close (3)",true,8,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(389,"wmap_close",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(30,(int)new OpR1a_Record(389,"wmap_close",false,3,false,false,false,true,true,false));
	hotel_cefa8c->setMarked(30,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(31,(int)new OpR1a_Record(390,"Skip (1)",true,0x20,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(31,(int)new OpR1a_Record(390,"Skip (2)",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(31,(int)new OpR1a_Record(391,"intro_skip_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(31,(int)new OpR1a_Record(391,"intro_skip_m",false,3,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(31,(int)new OpR1a_Record(392,"intro_restart",true,0x72,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(31,(int)new OpR1a_Record(393,"intro_reload",true,0x70,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(31,(int)new OpR1a_Record(394,"difficulty_1",true,0x31,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(31,(int)new OpR1a_Record(395,"difficulty_2",true,0x32,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(31,(int)new OpR1a_Record(396,"difficulty_3",true,0x33,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(31,(int)new OpR1a_Record(397,"difficulty_confirm (1)",true,0xd,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(31,(int)new OpR1a_Record(397,"difficulty_confirm (2)",true,0x10f,false,false,false,true,true,false));
	hotel_cefa8c->setMarked(31,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(32,(int)new OpR1a_Record(399,"Close (1)",true,0x20,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(32,(int)new OpR1a_Record(399,"Close (2)",true,0x1b,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(32,(int)new OpR1a_Record(399,"Close (3)",true,0xd,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(32,(int)new OpR1a_Record(399,"Close (4)",true,0x10f,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(32,(int)new OpR1a_Record(398,"overmap_exit1",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(32,(int)new OpR1a_Record(398,"overmap_exit2",false,3,false,false,false,true,true,false));
	hotel_cefa8c->setMarked(32,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(400,"evol_confrm_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(401,"Confirm (1)",true,0xd,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(401,"Confirm (2)",true,0x10f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(402,"Previous Slot (1)",true,0x111,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(402,"Previous Slot (2)",true,0x108,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(402,"Previous Slot (3)",true,0x6b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(403,"Next Slot (1)",true,0x112,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(403,"Next Slot (2)",true,0x102,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(403,"Next Slot (3)",true,0x6a,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(404,"Increment (1)",true,0x113,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(404,"Increment (2)",true,0x106,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(404,"Increment (3)",true,0x6c,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(405,"Decrement (1)",true,0x114,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(405,"Decrement (2)",true,0x104,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(33,(int)new OpR1a_Record(405,"Decrement (3)",true,0x68,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(33,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(34,(int)new OpR1a_Record(406,"rpg_confrm_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(34,(int)new OpR1a_Record(407,"Confirm (1)",true,0xd,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(34,(int)new OpR1a_Record(407,"Confirm (2)",true,0x10f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(34,(int)new OpR1a_Record(408,"Previous (1)",true,0x111,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(34,(int)new OpR1a_Record(408,"Previous (2)",true,0x108,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(34,(int)new OpR1a_Record(409,"Next (1)",true,0x112,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(34,(int)new OpR1a_Record(409,"Next (2)",true,0x102,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(34,(int)new OpR1a_Record(410,"Increment (1)",true,0x113,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(34,(int)new OpR1a_Record(410,"Increment (2)",true,0x106,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(34,(int)new OpR1a_Record(411,"Decrement (1)",true,0x114,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(34,(int)new OpR1a_Record(411,"Decrement (2)",true,0x104,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(34,(int)new OpR1a_Record(412,"Close (1)",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(34,(int)new OpR1a_Record(412,"Close (2)",true,0x39,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(34,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(35,(int)new OpR1a_Record(413,"game_confrm_m",false,1,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(35,(int)new OpR1a_Record(414,"Load (1)",true,0x6c,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(35,(int)new OpR1a_Record(414,"Load (2)",true,0x6c,true,false,false,true,false,true));
	hotel_cefa8c->addCommand(35,(int)new OpR1a_Record(415,"Restart (1)",true,0xd,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(35,(int)new OpR1a_Record(415,"Restart (2)",true,0x20,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(35,(int)new OpR1a_Record(415,"Restart (3)",true,0x10f,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(35,(int)new OpR1a_Record(416,"Quit",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->setMarked(35,false);
	hotel_cefa8c->addNode();
	hotel_cefa8c->addCommand(36,(int)new OpR1a_Record(417,"Skip (1)",true,0x20,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(36,(int)new OpR1a_Record(417,"Skip (2)",true,0x1b,false,false,false,true,false,true));
	hotel_cefa8c->addCommand(36,(int)new OpR1a_Record(418,"ending_next",true,0x113,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(36,(int)new OpR1a_Record(419,"ending_UI",true,0x111,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(36,(int)new OpR1a_Record(420,"ending_stars",true,0x114,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(36,(int)new OpR1a_Record(421,"ending_dust",true,0x64,false,false,false,true,true,false));
	hotel_cefa8c->addCommand(36,(int)new OpR1a_Record(422,"ending_pcl",true,0x70,false,false,false,true,true,false));
	hotel_cefa8c->setMarked(36,false);

	if (hotel_d28fbd)
	{
		hotel_d338cc.init_438ad0();
		hotel_d28c54.init_439650();
	}

	logMessage("Creating top-level consoles");
	hotel_cec038 = NULL;
	logMessage("...CCommands");
	hotel_cec03c = new CCommands(this);
	hotel_cec040 = NULL;
	hotel_cec124 = NULL;
	hotel_cec128 = NULL;
	hotel_cec044 = NULL;
	hotel_cec048 = NULL;
	hotel_cec04c = NULL;
	hotel_cec050 = NULL;
	logMessage("...CMap");
	hotel_cec054 = new CMap(this);
	hotel_cec070 = new CWorldMap(this);
	hotel_cec058 = new CMapFine(this);
	logMessage("...CHud");
	hotel_cec074 = new CHud(this);
	logMessage("...CLog");
	hotel_cec0b0 = new CLog(this,0);
	logMessage("...CCalcs");
	hotel_cec0c0 = new CLog(this,2);
	logMessage("...CAllies");
	hotel_cec0c8 = new CAllies(this);
	logMessage("...CExtendedLog");
	hotel_cec0b8 = new CLog(this,1);
	logMessage("...CIntel");
	hotel_cec0cc = new CIntel(this);
	logMessage("...CMulticonsoleButtons");
	hotel_cec0d0 = new CMulticonsoleButtons(this);
	hotel_cec0d4 = new CMainUiButtonHolder(this,0,8);
	hotel_cec0d8 = new CMainUiButtonHolder(this,1,8);
	hotel_cec0dc = new CMainUiButtonHolder(this,2,8);
	hotel_cec0e0 = (hotel_cebd5c == 2) ? new CMainUiButtonHolder(this,3,0xd) : NULL;
	hotel_cec0e4 = new CMainUiButtonHolder(this,4,8);
	hotel_cec0e8 = new CMainUiButtonHolder(this,5,8);
	hotel_cec0ec = new CMainUiButtonHolder(this,6,8);
	hotel_cec0f0 = new CFovEnemies(this);
	logMessage("...CHack");
	hotel_cec0f8 = new CHack(this);
	hotel_cec0fc = NULL;
	hotel_cec100 = NULL;
	hotel_cec104 = NULL;
	hotel_cec108 = NULL;
	hotel_cec10c = NULL;
	hotel_cec110 = NULL;
	hotel_cec114 = NULL;
	logMessage("...CStatus");
	hotel_cec118 = new CInfo(this,true,0xf);
	logMessage("...CInfo");
	hotel_cec11c = new CInfo(this,false,0xf);
	hotel_cec120 = new CInfo(this,false,0x14);
	hotel_cec134 = NULL;
	hotel_cec130 = NULL;
	hotel_cec12c = NULL;
	logMessage("...CInterfaceMsg");
	hotel_cec0f4 = new CInterfaceMsg(this);
	logMessage("...CEffects");
	hotel_cec138 = new CEffects(this);

	unknown988270();

	if (hotel_d33be4 + hotel_d33bec < hotel_d223f0.getHeight_4189a0())
	{
		Rect rect(hotel_d33be0,hotel_d33be4 + hotel_d33bec,hotel_d33be8,hotel_d223f0.getHeight_4189a0() - (hotel_d33be4 + hotel_d33bec));
		new Console(this,rect,0,false,-1);
	}

	logMessage("Loading inline colors");
	for (int i = 0; i <= 9; i++)
		hotel_d2b4bc.push_back(*hotel_cfe674);
	hotel_d2f1c8.unknown4b38a0();
	hotel_cefa64->end_410e50(2);
}
