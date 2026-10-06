// op_x5_b_c: CSpecialCommands layout 0x8b0450, Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);	// 0x46ca20
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor operator*(float f);	// NOTE: placeholder name (0x412050)
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();	// 0x40a6e0
	Rect(int x_, int y_, int width_, int height_);	// 0x456940
	Rect(const Rect &rect);	// 0x40a720
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

	int getHeight();
	int getWidth44b0d0();	// NOTE: placeholder name (0x44b0d0)
	Pos getPos();
	void setPos(int x, int y);
	void setBackAll_418410(XColor color);	// NOTE: placeholder name
	void setCharRow(int x, int y, int width, int ch);
	void print(int x, int y, const string &text);
	XColor getFore(int x, int y);
	XColor getBack(int x, int y);
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	void setBack_417fc0(int x, int y, XColor color, int mode);	// NOTE: placeholder name
	void unknown429fe0(XConsole *console, const Pos &pos, const Rect &rect) throw();	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	void unknown48c3c0(int value);	// NOTE: placeholder name

	int unknown60;
	void *engine;
	char pad68[0x6c - 0x68];
};

class CSpecialCommand : public Console
{
public:
	CSpecialCommand(XConsole *parent, int x, int y, int type_);	// 0x4ac960

	int type;	// NOTE: placeholder name
	int key;	// NOTE: placeholder name
};

int opx5b_centerOffset(int inner, int outer);	// NOTE: placeholder name (0x437190)
int opx5b_playSound(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name (0x4541b0)
extern bool opx5b_asciiEnabled;	// NOTE: placeholder name (0xd28d15)
extern int opx5b_cf27ec;	// NOTE: placeholder name
extern int opx5b_cf27f0;	// NOTE: placeholder name
extern int opx5b_cf27f4;	// NOTE: placeholder name
extern int opx5b_cf27f8;	// NOTE: placeholder name
extern int opx5b_caf128;	// NOTE: placeholder name
extern int opx5b_ceca70;	// NOTE: placeholder name
extern XColor *opx5b_COLOR_BLACK;	// NOTE: placeholder name (0xcfe674)
extern Console *opx5b_cec034;	// NOTE: placeholder name
extern Console *opx5b_mapView;	// NOTE: placeholder name (0xcec054)

//==================================================================
// CSpecialCommands
//==================================================================

class OpY7_SpecialCommands : public Console	// NOTE: placeholder name (CSpecialCommands at 0xcec0ac)
{
public:
	void unknown8b0450();	// NOTE: placeholder name
	void unknown8b0e80(int command);	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
	bool unknown6d;	// NOTE: placeholder name
	unsigned int unknown70;	// NOTE: placeholder name
	vector<Console*> unknown74;	// NOTE: placeholder name
	vector<Console*> unknown84;	// NOTE: placeholder name
	vector<Console*> unknown94;	// NOTE: placeholder name
	int unknownA4;	// NOTE: placeholder name
	Console *unknownA8;	// NOTE: placeholder name
	unsigned int unknownAC;	// NOTE: placeholder name
};

void OpY7_SpecialCommands::unknown8b0450()
{
	unknown6d = true;
	opx5b_playSound(0x2e,0,0);
	Rect center2;
	center2.width = opx5b_cf27f4 * opx5b_caf128;
	center2.height = 12;
	center2.x = opx5b_cf27ec;
	if (opx5b_asciiEnabled)
		center2.y = opx5b_centerOffset(center2.height,opx5b_cf27f8) + opx5b_cf27f0;
	else
		center2.y = opx5b_centerOffset(center2.height,opx5b_cf27f8 / 2) + opx5b_cf27f0;
	setPos(center2.x,center2.y);
	resize(center2.width,center2.height);
	setBackAll_418410(*opx5b_COLOR_BLACK);
	int fullRect = opx5b_centerOffset(0x2c,getWidth44b0d0());
	unknown74.push_back(new Console(this,getWidth44b0d0(),1,0,0,0,false,-1));
	unknown74.back()->setCharRow(0,0,unknown74.back()->getWidth44b0d0(),0x81);
	unknown74.back()->print(fullRect - 1,0," Special Commands ");
	unknown74.back()->unknown48c3c0(opx5b_ceca70);
	unknown74.push_back(new Console(this,getWidth44b0d0(),1,0,getHeight() - 1,0,false,-1));
	unknown74.back()->setCharRow(0,0,unknown74.back()->getWidth44b0d0(),0x81);
	unknown74.back()->unknown48c3c0(opx5b_ceca70);
	for (int i = 0, x = fullRect, y = 2; i < 0xc; i++, y++)
	{
		unknown84.push_back(new CSpecialCommand(this,x,y,i));
		if (i == 5)
		{
			unknownA4 = y + 2;
			x += 0x19;
			y = 1;
		}
	}
	unknown8b0e80(0xc);
	opx5b_mapView->render();
	int p = (opx5b_asciiEnabled != 0) + 1;
	Rect upper(0,0,opx5b_mapView->getWidth44b0d0(),(center2.y - opx5b_cf27f0) / p);
	Rect offset = upper;
	offset.y = opx5b_cf27f0;
	unknown94.push_back(new Console(opx5b_cec034,offset,(opx5b_asciiEnabled != 0) + 2,false,0x18));
	opx5b_mapView->unknown429fe0(unknown94.back(),Pos(0,0),upper);
	Rect half(0,center2.height / p + upper.height,upper.width,opx5b_mapView->getHeight() - center2.height / p - upper.height);
	Rect e = half;
	e.y = getPos().y + getHeight();
	unknown94.push_back(new Console(opx5b_cec034,e,(opx5b_asciiEnabled != 0) + 2,false,0x18));
	opx5b_mapView->unknown429fe0(unknown94.back(),Pos(0,0),half);
	for (unsigned int i = 0; i < unknown94.size(); i++)
	{
		Console *console = unknown94[i];
		for (int x = 0; x < console->getWidth44b0d0(); x++)
		{
			for (int y = 0; y < console->getHeight(); y++)
			{
				console->setFore_417f80(x,y,console->getFore(x,y) * 0.5f);
				console->setBack_417fc0(x,y,console->getBack(x,y) * 0.5f,1);
			}
		}
	}
}
