// team_c_21: CCommandsBasic::CCommandsBasic (0x7c1e60): the basic mouse-command help window for each HUD area
// NOTE: class layouts are partial (copied from op_w5.cpp so the vftable COMDAT is identical)
#include <string>
#include <vector>
using namespace std;

struct Pos { int x; int y; };
struct XColor { unsigned char r, g, b; };
struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(int x_, int y_, int width_, int height_) throw();
	Rect(const Rect &rect);
};

class XConsole
{
public:
	virtual ~XConsole();

	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);	// NOTE: placeholder name
	virtual void update();
	virtual void render();	// NOTE: placeholder name

	int getWidth();
	void print(int x, int y, const string &text);	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class Engine;

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();

	virtual void resize(int width, int height);	// 0x7ad4a0
	virtual bool input(void *event);
	virtual void update();
	virtual void render();	// NOTE: placeholder name
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	int unknown60;
	Engine *engine;
	void *title;
};

class CCommandsBasic : public Console
{
public:
	CCommandsBasic(XConsole *parent, int x, int y, int width, int type);
	virtual void open();	// NOTE: placeholder name
};

extern int opC_flag_cefc90;	// NOTE: placeholder name

CCommandsBasic::CCommandsBasic(XConsole *parent, int x, int y, int width, int type)
	: Console(parent,width,1,x,y,0,false,-1)
{
	vector<string> lines;
	switch (type)
	{
	case 0:
		lines.push_back("Left-click");
		lines.push_back(" - On enemy to target and fire");
		lines.push_back(" - On self to pick up item");
		lines.push_back(" - On position to move");
		lines.push_back("");
		lines.push_back("Right-click");
		lines.push_back(" - On self, robot, item, or machine for info");
		lines.push_back(" - Out of sight to pan map (or hold shift and move cursor)");
		lines.push_back(" - Hold to set view centerpoint (maintained on move)");
		lines.push_back(" - To close/cancel");
		lines.push_back("");
		lines.push_back("Scroll wheel with Shift to zoom");
		lines.push_back("");
		lines.push_back("Shift-right-click on ally to issue order");
		lines.push_back("");
		lines.push_back("Scroll wheel to wait");
		lines.push_back("");
		lines.push_back("Enter to center on self");
		lines.push_back("");
		lines.push_back("Escape / ? / F1 for help/options");
		break;
	case 1:
		lines.push_back("Click to expand/shrink");
		lines.push_back("Scroll wheel to scroll");
		break;
	case 2:
		lines.push_back("Left-click to order");
		lines.push_back("Right-click for info");
		lines.push_back("Scroll wheel to scroll");
		lines.push_back("Hover over [ALL] to show pending orders");
		lines.push_back("");
		lines.push_back("Change console: F5~F8");
		break;
	case 3:
		lines.push_back("Left-click to toggle intel");
		lines.push_back("Scroll wheel to scroll");
		lines.push_back("");
		lines.push_back("Change console: F5~F8");
		break;
	case 4:
		lines.push_back("Scroll wheel to scroll");
		lines.push_back("(auto-scrolls with log)");
		break;
	case 5:
		lines.push_back("Scroll wheel to scroll");
		break;
	case 6:
		lines.push_back("Left-click to activate/deactivate");
		lines.push_back("Right-click for info");
		lines.push_back("");
		lines.push_back("Drag & Drop");
		lines.push_back(" - Between slots to reorganize parts");
		lines.push_back(" - To inventory to detach");
		lines.push_back(" - To map to drop");
		lines.push_back("");
		lines.push_back("Data Visualization");
		lines.push_back(" (c) Coverage: Relative coverage given current loadout");
		lines.push_back(" (e) Energy: Energy generation/consumption");
		lines.push_back(" (w) Integrity: Remaining integrity (%)");
		lines.push_back(" (q) Info: Essential stat summary");
		if (opC_flag_cefc90)
		{
			for (int i = 0; i < 10; i++)
				lines.push_back("");
			lines.push_back("Left-click < INVENTORY > to open/close inventory, then:");
			lines.push_back("");
		}
		else
			break;
	case 7:
		lines.push_back("Left-click to attach");
		lines.push_back("Right-click for info");
		lines.push_back("Scroll wheel to scroll");
		lines.push_back("");
		lines.push_back("Drag & Drop");
		lines.push_back(" - To parts list to attach/swap");
		lines.push_back(" - To map to drop");
	}
	resize(getWidth(),lines.size());
	for (unsigned int j = 0; j < lines.size(); j++)
		print(0,j,lines[j]);
}
