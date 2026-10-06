// op_t6: functions in 0x7ed000-0x895000 of COGMIND.exe (Beta 17.1). Names are placeholders unless stated.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

class Push_40a010	// NOTE: placeholder name (see src/match_push)
{
public:
	int field0;
	int field4;
	void operate(int arg0, int arg1);
};

class Predicate_409cb0	// NOTE: placeholder name (see src/match_push)
{
public:
	int field0;
	int field4;
	bool test(int arg0, int arg1);
};

extern int OpT6_screenWidth;	// 0xcf27f4 NOTE: placeholder name
extern int OpT6_screenHeight;	// 0xcf27f8 NOTE: placeholder name

class OpT6_Console	// NOTE: placeholder name (offset +0x6c/+0x70: XConsole position)
{
public:
	char pad[0x6c];
	int x;
	int y;

	void centerPush_805020(Push_40a010 *out);	// NOTE: placeholder name
	bool centerPredicate_805060(Predicate_409cb0 *out);	// NOTE: placeholder name
};

void OpT6_Console::centerPush_805020(Push_40a010 *out)
{
	out->operate(OpT6_screenWidth / 2 - x, OpT6_screenHeight / 2 - y);
}

bool OpT6_Console::centerPredicate_805060(Predicate_409cb0 *out)
{
	return out->test(OpT6_screenWidth / 2 - x, OpT6_screenHeight / 2 - y);
}

//==================================================================
// CAudioLog / CAudioLogs / CMap
//==================================================================

class XConsole	// NOTE: partial (see src/engine/xconsole.h)
{
public:
	XConsole *getParent();	// 0x9b8f00
};

class CAudioLogs
{
public:
	CAudioLogs(XConsole *parent);	// 0x499160

	char pad[0x9c];
	void removeLog(class CAudioLog *log);	// NOTE: placeholder name
};

extern unsigned int OpT6_tickCount;	// 0xcaed20 NOTE: placeholder name

class CAudioLog	// NOTE: partial layout (see op_w5.cpp)
{
public:
	void unknown7f4f10();	// NOTE: placeholder name

	char pad[0x94];
	unsigned int endTime;	// NOTE: placeholder name
};

void CAudioLog::unknown7f4f10()
{
	if (endTime != 0 && OpT6_tickCount >= endTime)
		((CAudioLogs *)((XConsole *)this)->getParent())->removeLog(this);
}

class CMap : public XConsole	// NOTE: partial layout (see src/game/misc_small.cpp)
{
public:
	void unknown819900();	// NOTE: placeholder name

	char pad[0x36c];
	CAudioLogs *audioLog;	// NOTE: placeholder name
};

void CMap::unknown819900()
{
	if (audioLog != NULL)
		return;
	audioLog = new CAudioLogs(this);
}

//==================================================================
// misc
//==================================================================

class OpS_Graph	// NOTE: placeholder name (see op_s1a.cpp)
{
public:
	void setMarked(unsigned int index, bool marked);
};
extern OpS_Graph *opT6_graph;	// 0xcefa8c NOTE: placeholder name

class OpT6_Select	// NOTE: placeholder name
{
public:
	void setSelected_8278f0(int selected_);	// NOTE: placeholder name

	char pad[0x680];
	int selected;
};

void OpT6_Select::setSelected_8278f0(int selected_)
{
	selected = selected_;
	for (int i = 7; i <= 8; i++)
		opT6_graph->setMarked(i,false);
	opT6_graph->setMarked(selected,true);
}

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	int mouseX;
	int mouseY;
};

class OpT6_Parts	// NOTE: placeholder name (CParts, 0xcec088)
{
public:
	virtual void virtual0();	// NOTE: placeholder name
	virtual void virtual1();	// NOTE: placeholder name
	virtual void virtual2();	// NOTE: placeholder name
	virtual void virtual3();	// NOTE: placeholder name
	virtual bool input(XEvent *event);

	void resetField();	// 0x4a9cd0
};
extern OpT6_Parts *opT6_parts;	// 0xcec088 NOTE: placeholder name
extern bool opT6_d28d1c;	// NOTE: placeholder name

class OpT6_Screen	// NOTE: placeholder name
{
public:
	void unknown819ce0();	// NOTE: placeholder name

	char pad[0x754];
	unsigned int lastTime;
};

void OpT6_Screen::unknown819ce0()
{
	if (opT6_d28d1c && OpT6_tickCount >= lastTime + 10000)
	{
		opT6_parts->resetField();
		opT6_parts->input(&XEvent(0x113));
		lastTime = OpT6_tickCount;
	}
}

//==================================================================
// Console animations
//==================================================================

class Console	// NOTE: partial (see src/engine/xconsole.h)
{
public:
	void animate(string name);	// NOTE: placeholder parameter name
};

extern int OpT6_d28d68;	// NOTE: placeholder name

class OpT6_Button : public Console	// NOTE: placeholder name
{
public:
	void unknown889fc0();	// NOTE: placeholder name
	bool unknown88b750();	// NOTE: placeholder name

	char pad[0x60 - sizeof(Console)];
	int unknown60;
	char pad64[0x6c - 0x64];
	int state;
	unsigned int unknown70;
};

void OpT6_Button::unknown889fc0()
{
	unknown60 = 4;
	unknown70 = OpT6_tickCount;
	animate("A_BlockFadeInterior");
}

bool OpT6_Button::unknown88b750()
{
	if (state == 0 || state == 1 || state == 2 || state == 3)
	{
	}
	else if (OpT6_d28d68 == state)
		return false;
	animate("A_ButtonHover_Begin_PART_HOV_OK");
	return true;
}

class OpT6_ConBase	// NOTE: placeholder name (XConsole)
{
public:
	virtual void virtual0();	// NOTE: placeholder name
	virtual void virtual1();	// NOTE: placeholder name
	virtual bool isActive();
	virtual void refresh();

	OpT6_ConBase *getParent();	// 0x9b8f00
};

class OpT6_Flagged	// NOTE: placeholder name
{
public:
	bool unknown88e070();	// NOTE: placeholder name
	void unknown88e0d0();	// NOTE: placeholder name

	OpT6_ConBase *getParent();	// 0x9b8f00
	char pad[0x6c];
	bool flag;
};

bool OpT6_Flagged::unknown88e070()
{
	return flag ? getParent()->isActive() : getParent()->isActive();
}

void OpT6_Flagged::unknown88e0d0()
{
	flag ? getParent()->refresh() : getParent()->refresh();
}

struct OpT6_Record	// NOTE: placeholder name
{
	int unknown0;
	string name;
};
extern vector<OpT6_Record*> opT6_records;	// 0xcf09a8 NOTE: placeholder name

bool OpT6_compareNames_7f10e0(unsigned int a, unsigned int b)	// NOTE: placeholder name
{
	return opT6_records[a]->name < opT6_records[b]->name;
}

struct OpT6_Pos	// NOTE: placeholder name
{
	int x;
	int y;
};

class OpT6_Rex	// NOTE: placeholder name (0xd223f0)
{
public:
	int unknown418980();	// NOTE: placeholder name
	int unknown4189a0();	// NOTE: placeholder name
};
extern OpT6_Rex opT6_rex;	// 0xd223f0 NOTE: placeholder name

class OpT6_Mouse	// NOTE: placeholder name (XMouse, 0xcefa94)
{
public:
	void setCell(int x_, int y_);	// 0x4322a0
};
extern OpT6_Mouse *opT6_mouse;	// 0xcefa94 NOTE: placeholder name
extern bool opT6_d28c8a;	// NOTE: placeholder name
extern bool opT6_d28e4a;	// NOTE: placeholder name
extern int opT6_fontCellWidth;	// 0xcaf128 NOTE: placeholder name
extern int opT6_fontCellHeight;	// 0xcaf12c NOTE: placeholder name
extern int opT6_cf27ec;	// NOTE: placeholder name
extern int opT6_cf27f0;	// NOTE: placeholder name

class OpT6_PosConsole	// NOTE: placeholder name
{
public:
	void warpMouse_806e70(const OpT6_Pos &pos, bool flag);	// NOTE: placeholder name

	char pad[0x6c];
	int x;
	int y;
};

void OpT6_PosConsole::warpMouse_806e70(const OpT6_Pos &pos, bool flag)
{
	int cy_;
	if (flag || opT6_d28c8a)
	{
		if (opT6_d28e4a && !opT6_d28c8a && !flag)
			return;
		int cx_ = (pos.x + x) * opT6_fontCellWidth + opT6_cf27ec;
		if (cx_ < 0 || cx_ > opT6_rex.unknown418980())
			return;
		cy_ = (pos.y + y) * opT6_fontCellHeight + opT6_cf27f0;
		if (cy_ < 0 || cy_ > opT6_rex.unknown4189a0())
			return;
		opT6_mouse->setCell(cx_,cy_);
	}
}

//==================================================================
// vector cleanup
//==================================================================

struct OpQ5_T9d4840	// NOTE: placeholder name (see op_q5_ser.cpp)
{
	char pad0[8];
	bool flag;	// NOTE: placeholder name
};

struct OpQ5_T9d4950;	// NOTE: placeholder name (see op_q5_ser.cpp)

template <class T> void OpQ5_deleteObjectAndStep(vector<T*> &v, int &index);	// NOTE: placeholder name
template <class T> void OpQ5_deleteObject(vector<T*> &v, int index);	// NOTE: placeholder name

extern unsigned int opT6_d28f78;	// NOTE: placeholder name

class OpT6_Lists	// NOTE: placeholder name
{
public:
	void cleanUp_8144d0();	// NOTE: placeholder name
	void trim_876760();	// NOTE: placeholder name

	char pad0[0x90];
	vector<OpQ5_T9d4950*> trimmed;	// NOTE: placeholder name
	char pad1[0x1d8 - 0xa0];
	vector<OpQ5_T9d4840*> entries;	// NOTE: placeholder name
};

void OpT6_Lists::cleanUp_8144d0()
{
	for (int i = 0; (unsigned int)i < entries.size(); i++)
	{
		if (!entries[i]->flag)
			OpQ5_deleteObjectAndStep(entries,i);
	}
}

void OpT6_Lists::trim_876760()
{
	while (trimmed.size() > opT6_d28f78)
		OpQ5_deleteObject(trimmed,0);
}
