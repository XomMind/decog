// op_r1c_root: XRoot construction and input dispatch (Beta 17.1).
// NOTE: names of everything but XRoot/XConsole/REX are placeholders.
#include "engine/xconsole.h"

struct XRootCellRecord	// NOTE: placeholder name
{
	int frame;
	int subcell;
	int fontType;
	XConsole *owner;

	XRootCellRecord() throw();	// 0x40a6e0
};

struct OpR1a_Record	// NOTE: placeholder name
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

class XCommandMgr	// NOTE: placeholder name (0xcefa8c)
{
public:
	void addCommand(int domain, int command);	// 0x416390
	void unknown416250();	// NOTE: placeholder name
	void unknown4162e0(int domain, bool flag);	// NOTE: placeholder name
};
extern XCommandMgr *commandMgr;	// 0xcefa8c, NOTE: placeholder name

class OpR1c_Dispatcher	// NOTE: placeholder name (0xcefa9c)
{
public:
	void unknown416900();	// NOTE: placeholder name
};
extern OpR1c_Dispatcher *opr1c_dispatcher;	// 0xcefa9c, NOTE: placeholder name

class OpR1c_Rex	// NOTE: placeholder name (REX at 0xd223f0)
{
public:
	void unknown4240c0();	// NOTE: placeholder name
	void unknown424130();	// NOTE: placeholder name
	void unknown425e50();	// NOTE: placeholder name
	bool unknown418c80();	// NOTE: placeholder name
	void toggleFullscreen();	// 0x424210
};
extern OpR1c_Rex opr1c_rex;	// 0xd223f0

extern void (*opr1c_inputHook)(XEvent *event);	// 0xd2252c, NOTE: placeholder name
extern bool opr1c_flag_d22529;	// NOTE: placeholder name
extern bool opr1c_inputBlocked;	// 0xcefa5f, NOTE: placeholder name

class XRoot : public XConsole
{
public:
	XRoot(int width, int height, bool noCommands);	// 0x42d420, NOTE: placeholder parameter name
	virtual ~XRoot();	// 0x4184f0
	virtual bool input(XEvent *event);	// 0x42d930
	virtual void update();
	virtual void render();

	bool unknown429d00(XEvent *event);	// NOTE: placeholder name

	int frameCount;	// +0x60, NOTE: placeholder name
	Array2D<XRootCellRecord*> records;	// +0x64, NOTE: placeholder name
	vector<vector<XConsole*> > layers;	// +0x70, NOTE: placeholder name
	bool unknown80;	// NOTE: placeholder name
};

XRoot::XRoot(int width, int height, bool noCommands)
	: XConsole(NULL,width,height,0,0,0,false,-1)
	, frameCount	(0)
	, unknown80		(false)
{
	records.resize(width,height,0);
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			XRootCellRecord *record = new XRootCellRecord();
			*records.get(x,y) = record;
		}
	}
	if (!noCommands)
	{
		commandMgr->unknown416250();
		commandMgr->addCommand(0,(int)new OpR1a_Record(0,"next_fontset",true,0x118,false,true,false,true,true,false));
		commandMgr->addCommand(0,(int)new OpR1a_Record(1,"prev_fontset",true,0x119,false,true,false,true,true,false));
		commandMgr->addCommand(0,(int)new OpR1a_Record(2,"screenshot",true,0x13c,false,false,false,true,true,false));
		commandMgr->addCommand(0,(int)new OpR1a_Record(2,"screenshot",true,0x13c,false,true,false,true,true,false));
		commandMgr->addCommand(0,(int)new OpR1a_Record(2,"screenshot",true,0x125,false,false,false,true,true,false));
		commandMgr->addCommand(0,(int)new OpR1a_Record(3,"pause",true,0x13,false,false,false,true,true,false));
		commandMgr->addCommand(0,(int)new OpR1a_Record(4,"fullscreen",true,0xd,false,false,true,false,true,false));
		commandMgr->unknown4162e0(0,true);
	}
}

bool XRoot::input(XEvent *event)
{
	if (opr1c_inputHook)
		opr1c_inputHook(event);
	if (!opr1c_flag_d22529)
	{
		if (isHidden() || opr1c_inputBlocked)
			return false;
		if (unknown429d00(event))
			return true;
	}
	switch (event->type)
	{
		case 0:
			opr1c_rex.unknown4240c0();
			return true;
		case 1:
			opr1c_rex.unknown424130();
			return true;
		case 2:
			opr1c_rex.unknown425e50();
			return true;
		case 3:
			if (unknown80)
				opr1c_dispatcher->unknown416900();
			return true;
		case 4:
			if (!opr1c_rex.unknown418c80())
				opr1c_rex.toggleFullscreen();
			return true;
		default:
			return false;
	}
}
