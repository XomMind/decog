// team_c_26: CCommandsAdvanced::CCommandsAdvanced (0x7c2d60)
// NOTE: placed in src/util so it links after every other TU (under /LTCG an earlier position changes EH-state inference in op_w6)
// NOTE: class layouts are partial (copied from team_c_21 so the vftable COMDATs agree); global names are placeholders
#include <string>
#include <vector>
using namespace std;

struct Pos { int x; int y; };
struct XColor
{
	unsigned char r, g, b;
	XColor(const XColor &c);
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
	void printAligned(int x, int y, int align, const string &text);	// NOTE: placeholder name
	void setCharRow(int x, int y, int width, int ch, XColor fore);	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class Engine;

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();

	virtual void resize(int width, int height);	// 0x7ad4a0 (overrides XConsole::resize 0x4289a0)
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

class CCommandsAdvanced : public Console
{
public:
	CCommandsAdvanced(XConsole *parent, int x, int y, int width, int mode_);
	virtual void open();

	int mode;	// NOTE: placeholder name
};

bool opr1c_hasPtr_cebd5c();	// NOTE: placeholder name (0x4328a0)
extern bool flag_cefb3c;	// NOTE: placeholder name
extern XColor color_d29804;	// NOTE: placeholder name
extern XColor &ptr_cfe674;	// NOTE: placeholder name

CCommandsAdvanced::CCommandsAdvanced(XConsole *parent, int x, int y, int width, int mode_)
	: Console(parent,width,1,x,y,0,false,-1)
{
	mode = mode_;
	string str;
	vector<string> list;
	vector<string> rows;
	switch (mode)
	{
	case 0:
		str = "Map";
		list.push_back("Alt-Move Keys \\ Accent + Move Keys");
		rows.push_back("Shift Map View (vi requires +Shift");
		list.push_back("");
		rows.push_back("  outside Mapshift Mode)");
		list.push_back("Enter \\ Alt-KP5 \\ CMB");
		rows.push_back("Center on Self (Repeat Cycles through Drones)");
		list.push_back("Shift-Move Cursor");
		rows.push_back("Pan Map");
		list.push_back("v \\ Ctrl-CMB");
		rows.push_back("Show Volley Range");
		if (!opr1c_hasPtr_cebd5c())
		{
			list.push_back("Shift-Alt-o (Hold)");
			rows.push_back("Show Orders");
		}
		list.push_back("1~4");
		rows.push_back("Label Hostiles/Friendlies/Parts/Exits");
		list.push_back("Ctrl-Alt (Hold)");
		rows.push_back("Highlight Path to Cursor");
		list.push_back("x");
		rows.push_back("Examine (Look) Mode");
		list.push_back("z \\ Shift-Wheel");
		rows.push_back("Zoom Map");
		list.push_back("m");
		rows.push_back("Map Intel Overlays");
		list.push_back("Backspace \\ F9");
		rows.push_back("Show World Map");
		break;
	case 1:
		str = "Movement";
		list.push_back("KP# \\ LMB \\ Arrows \\ vi-keys");
		rows.push_back("Move (Arrows: +Shift/Ctrl for Diagonal)");
		list.push_back("Shift-KP# \\ r-Arrows \\ r-vi");
		rows.push_back("Run (r/Esc Cancels)");
		list.push_back("< \\ > \\ LMB");
		rows.push_back("Up Stairs / To Branch / Trigger/Install Trap");
		break;
	case 2:
		str = "Control";
		list.push_back("KP5 \\ . \\ Wheel");
		rows.push_back("Wait");
		list.push_back("g \\ LMB");
		rows.push_back("Get Item");
		list.push_back("a \\ Ctrl-LMB");
		rows.push_back("Get Item and Attach (Repeat if Slots Full)");
		list.push_back("f \\ LMB");
		rows.push_back("Fire (+Ctrl to Force)");
		list.push_back("Ctrl-Shift + Movement Keys");
		rows.push_back("Force Melee");
		list.push_back("s \\ RMB");
		rows.push_back("Status");
		list.push_back("o \\ Shift-RMB");
		rows.push_back("Order Ally");
		list.push_back("o \\ KP5 \\ Enter \\ LMB");
		rows.push_back("Confirm Order Target");
		list.push_back("Spacebar");
		rows.push_back("Special Commands");
		break;
	case 3:
		str = "Look/Target";
		list.push_back("Movement Keys");
		rows.push_back("Move Cursor (KB Mode Only)");
		list.push_back("Tab \\ -/= \\ KP-/+");
		rows.push_back("Cycle Targets (+Shift Reverses Tab)");
		list.push_back("Ctrl-Tab \\ Ctrl-KP-/+");
		rows.push_back("Cycle Items (+Shift Reverses Tab)");
		list.push_back("d \\ KP0 \\ RMB \\ Ctrl-RMB");
		rows.push_back("Data (Info)");
		if (opr1c_hasPtr_cebd5c())
		{
			list.push_back("s");
			rows.push_back("Set View Centerpoint (KB Mode Only)");
		}
		list.push_back("KP5 \\ Enter \\ LMB");
		rows.push_back("Set Guided Weapon Waypoint");
		if (opr1c_hasPtr_cebd5c())
		{
			list.push_back("c/r");
			rows.push_back("Add/Remove Map Comment");
		}
		break;
	case 4:
		str = "General";
		list.push_back("Esc \\ ? \\ F1");
		rows.push_back("Help/Options");
		list.push_back("Ctrl-Shift-Alt-s");
		rows.push_back("Save & Quit");
		list.push_back("Spacebar + s \\ Shift-Alt-s");
		rows.push_back("Dump Current Stats");
		list.push_back("Alt-F10");
		rows.push_back("Self-Destruct/Restart");
		list.push_back("F2");
		rows.push_back("Toggle Keyboard Mode");
		list.push_back("F3");
		rows.push_back("Toggle ASCII Mode");
		if (opr1c_hasPtr_cebd5c())
		{
			list.push_back("Alt-Enter");
			rows.push_back("Toggle Fullscreen");
		}
		list.push_back("F12 \\ PrtScn");
		rows.push_back("Screenshot");
		break;
	case 5:
		str = "Control";
		list.push_back("KP-/+ \\ Wheel");
		rows.push_back("Scroll");
		list.push_back("PgUp/Dn");
		rows.push_back("Page Up/Down");
		list.push_back("End");
		rows.push_back("End");
		list.push_back("F4 \\ LMB/RMB");
		rows.push_back("Expand/Shrink");
		list.push_back("Spacebar + z \\ Shift-Alt-z");
		rows.push_back("Add Note to Log");
		break;
	case 6:
		str = "Control";
		list.push_back("-/= \\ Wheel");
		rows.push_back("Scroll");
		list.push_back("o + Shift-0~5 \\ RMB");
		rows.push_back("Info");
		list.push_back("o + 0~5 \\ LMB");
		rows.push_back("Order");
		list.push_back("Shift-Alt-o (Hold)");
		rows.push_back("Show Orders");
		list.push_back("F5~F8");
		rows.push_back("Multiconsole Mode");
		break;
	case 7:
		str = "Control";
		list.push_back("m");
		rows.push_back("Map Intel Mode Toggle");
		list.push_back("-/= \\ Wheel");
		rows.push_back("Scroll");
		list.push_back("0~5 \\ LMB");
		rows.push_back("Toggle Intel");
		list.push_back("m \\ Esc");
		rows.push_back("Cancel Map Intel Mode");
		list.push_back("F5~F8");
		rows.push_back("Multiconsole Mode");
		break;
	case 8:
		str = "Control";
		list.push_back("F5~F8");
		rows.push_back("Multiconsole Mode");
		list.push_back("");
		rows.push_back("");
		break;
	case 9:
		str = "Control";
		list.push_back("-/= \\ Wheel");
		rows.push_back("Scroll");
		list.push_back("F5~F8");
		rows.push_back("Multiconsole Mode");
		break;
	case 10:
		str = "Parts";
		list.push_back("Shift-a~z \\ RMB");
		rows.push_back("Info");
		list.push_back("Ctrl-a~z \\ LMB");
		rows.push_back("Toggle State");
		list.push_back("Ctrl-Shift-a~z/1~0");
		rows.push_back("Swap/Reassign");
		list.push_back("/ + a~z \\ Ctrl-RMB");
		rows.push_back("Inventory Swap/Attach");
		list.push_back("Alt-a~z \\ Ctrl-LMB");
		rows.push_back("Detach");
		list.push_back("d + a~z/1~0");
		rows.push_back("Modal Remove/Drop (KB Mode)");
		list.push_back("Spacebar + p \\ Shift-Alt-p");
		rows.push_back("Purge All Parts");
		list.push_back(";");
		rows.push_back("Cycle Propulsion Mode");
		list.push_back("\"");
		rows.push_back("Toggle Utilities w/Upkeep");
		list.push_back("'");
		rows.push_back("Toggle All Weapons");
		list.push_back("p");
		rows.push_back("Modal Part Management");
		break;
	case 11:
		str = "Visualization";
		list.push_back("c");
		rows.push_back("Coverage (Toggle for Vuln.)");
		list.push_back("e");
		rows.push_back("Energy (Toggle for Heat)");
		list.push_back("w");
		rows.push_back("Integrity (Toggle for Mass)");
		list.push_back("q");
		rows.push_back("Info (Toggle for Matter)");
		break;
	case 12:
		str = "Inventory";
		list.push_back("i");
		rows.push_back("Open/Close Inventory");
		list.push_back("Ctrl-1~0 \\ LMB");
		rows.push_back("Attach");
		list.push_back("Drag to Parts List");
		rows.push_back("Attach");
		list.push_back("Shift-1~0 \\ RMB");
		rows.push_back("Info");
		list.push_back("Alt-1~0 \\ Drag to Map");
		rows.push_back("Drop");
		break;
	case 13:
		str = "Control";
		list.push_back("]/[ \\ Wheel");
		rows.push_back("Scroll (+Ctrl for Page)");
		list.push_back("t");
		rows.push_back("Type Sort (Repeat Reverses)");
		break;
	case 14:
		str = "Items";
		list.push_back("Ctrl-1~0 \\ LMB");
		rows.push_back("Attach");
		list.push_back("Drag to Parts List");
		rows.push_back("Attach");
		list.push_back("Shift-1~0 \\ RMB");
		rows.push_back("Info");
		list.push_back("Alt-1~0 \\ Drag to Map");
		rows.push_back("Drop");
		list.push_back("/ + 1~0 \\ Ctrl-RMB");
		rows.push_back("Swap");
		break;
	}
	resize(getWidth(),list.size() + 1);
	int center = getWidth() / 2;
	if (mode == 5)
		center += 5;
	print(center + 2,0,str);
	setCharRow(center - 0x15,0,0x16,0x81,flag_cefb3c ? color_d29804 : ptr_cfe674);
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (!list[i].empty())
			printAligned(center - 2,i + 1,2,list[i]);
		print(center + 2,i + 1,rows[i]);
	}
}
