// op_x1_input: XInput::handleEvent (0x427320), dispatches one SDL event to modifier flags, mouse buttons,
// hotspots and the key handler (called from REX::run) (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct OpXI_SDLEvent	// NOTE: SDL 1.2 event union (0x14 bytes)
{
	unsigned char type;
	unsigned char which;
	unsigned char button;	// button.button
	unsigned char state;
	unsigned short x;	// button.x
	unsigned short y;	// button.y
	int sym;	// key.keysym.sym
	int mod;
	int unicode;
};

struct OpXI_Key	// NOTE: placeholder name (TeamA21_KeyInput, 0x30 bytes: the frame needs the trailing slot)
{
	OpXI_Key(unsigned char type, OpXI_SDLEvent event);	// 0x426f30
	~OpXI_Key();	// NOTE: placeholder name (folded string-member dtor)

	int unknown00;
	string text;
	bool isKey;	// +0x20
	int code;	// +0x24
	bool shift;
	bool ctrl;
	bool alt;
	bool down;	// +0x2b
	int unknown2c;	// NOTE: placeholder name
};

struct OpXI_Rect	// NOTE: placeholder name (the declared ctor puts the getRect() temporary in the late pool, as in the exe)
{
	OpXI_Rect() throw();
	int x;
	int y;
	int w;
	int h;
};
struct OpXI_Event	// NOTE: placeholder name (0xc bytes)
{
	OpXI_Event(int id);	// NOTE: placeholder name (0x415c60)
	OpXI_Event(int id, int x, int y);	// NOTE: placeholder name (0x415ca0)
	int id;
	int x;
	int y;
};

class OpXI_Console	// NOTE: placeholder name (XConsole)
{
public:
	virtual ~OpXI_Console();
	virtual void resize(int width, int height);
	virtual bool isActive();
	virtual void refresh();
	virtual bool input(const OpXI_Event &event);
	OpXI_Rect getRect();	// 0x428710
};

class OpXI_KeyHandler	// NOTE: placeholder name
{
public:
	virtual ~OpXI_KeyHandler();
	virtual void unknown04();
	virtual void unknown08();
	virtual void unknown0c();
	virtual void unknown10();
	virtual void key(int code, int type);	// NOTE: placeholder name (slot 5)
};

struct OpXI_Hotspot	// NOTE: placeholder name
{
	int id;
	char pad04[0x20 - 0x04];
	bool highlight;	// +0x20
	bool contains(OpXI_Key *key);	// NOTE: placeholder name (0x415e30)
};

class OpXI_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	bool inside(const OpXI_Rect &rect);	// NOTE: placeholder name (0x41a730)
	void setPos(int x, int y);	// NOTE: placeholder name (0x41a800)
};
extern OpXI_Mouse *opXI_mouse_cefa94;	// NOTE: placeholder name

class OpXI_Rex	// NOTE: placeholder name (REX at 0xd223f0)
{
public:
	int toCellX_418a00(int x);	// NOTE: placeholder name
	int toCellY_418a30(int y);	// NOTE: placeholder name
	OpXI_Console *getHighlighter();	// NOTE: placeholder name (0x4ab670)
};
extern OpXI_Rex opXI_rex;	// NOTE: placeholder name

struct OpXI_Paused { bool paused; };	// NOTE: placeholder name
extern OpXI_Paused *opXI_cefa9c;	// NOTE: placeholder name
extern unsigned int opXI_tickCount;	// NOTE: placeholder name (0xcaed20)
extern unsigned char opXI_flags_cec14c[4];	// NOTE: placeholder name (shift, ctrl, alt, caps)
extern bool opXI_mouseDown_cefa74[2];	// NOTE: placeholder name
extern bool opXI_cefa5f;	// NOTE: placeholder name
extern unsigned char *opXI_keys_cefa84;	// NOTE: placeholder name (SDL_GetKeyState)
extern int opXI_remap_cec458[];	// NOTE: placeholder name
extern int opXI_punctuation_caecf8[];	// NOTE: placeholder name

bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (in range)
bool OpS8b_Fn9d43b0(int *values, unsigned int count, int value);	// NOTE: placeholder name (contains)

class XInput	// NOTE: placeholder name (object at 0xcefa8c)
{
public:
	void handleEvent_427320(unsigned char type, OpXI_SDLEvent event);	// NOTE: placeholder name

	vector<vector<OpXI_Hotspot *> > layers;	// +0x00
	vector<bool> active;	// +0x10
	vector<bool> blocked;	// +0x24
	bool resetBlocked;	// +0x38
	char pad39[0x4c - 0x39];
	OpXI_KeyHandler *keyHandler;	// +0x4c
	OpXI_Console *modal;	// +0x50
	int modalId;	// +0x54
	bool modalClicked;	// +0x58
	bool (*modalFilter)();	// +0x5c
	bool (*filter)(OpXI_Key *key);	// +0x60
	bool noHover;	// +0x64
	char pad65[0x6c - 0x65];
	int lastId;	// +0x6c
	int previousId;	// +0x70
	unsigned int lastEventTick;	// +0x74
	void (*onEvent)();	// +0x78
	OpXI_Hotspot *current;	// +0x7c
	vector<unsigned int> pressTime;	// +0x80
	vector<unsigned int> pressDuration;	// +0x90
};

void XInput::handleEvent_427320(unsigned char type, OpXI_SDLEvent event)
{
	if (onEvent)
		onEvent();
	lastEventTick = opXI_tickCount;
	if (resetBlocked)
	{
		blocked.assign(active.size(),false);
		resetBlocked = false;
	}
	unsigned char flag = type == 2;
	switch (event.sym)
	{
		case 303:
		case 304:
			opXI_flags_cec14c[0] = flag;
			return;
		case 305:
		case 306:
			opXI_flags_cec14c[1] = flag;
			return;
		case 307:
		case 308:
			opXI_flags_cec14c[2] = flag;
			return;
		case 301:
			opXI_flags_cec14c[3] = flag;
			return;
	}
	if (type == 5 || type == 6)
	{
		int button = 2;
		switch (event.button)
		{
			case 1:
				button = 0;
				break;
			case 3:
				button = 1;
				break;
		}
		if (button != 2)
		{
			opXI_mouseDown_cefa74[button] = type == 5;
			if (type == 5)
				pressTime[button] = opXI_tickCount;
			else if (opXI_tickCount >= pressTime[button])
				pressDuration[button] = opXI_tickCount - pressTime[button];
			else
				pressDuration[button] = 0;
		}
	}
	OpXI_Key key(type,event);
	if (filter && !key.isKey && filter(&key))
		return;
	if (modal && key.code == 1 && key.down && !opXI_mouse_cefa94->inside(modal->getRect()) && (!modalFilter || !modalFilter()))
	{
		modal->input(OpXI_Event(modalId));
		modalClicked = true;
		opXI_cefa5f = false;
		return;
	}
	else if (modalClicked && key.code == 1 && !key.down)
	{
		modalClicked = false;
		return;
	}
	int top = opXI_cefa9c->paused ? 0 : layers.size() - 1;
	for (int layer = 0; layer <= top; layer++)
	{
		if (active[layer] && !blocked[layer])
		{
			for (unsigned int i = 0; i < layers[layer].size(); i++)
			{
				if (layers[layer][i]->contains(&key))
				{
					current = layers[layer][i];
					if (current->highlight)
						opXI_rex.getHighlighter()->input(OpXI_Event(current->id));
					else if (noHover)
						break;
					else
					{
						opXI_mouse_cefa94->setPos(opXI_rex.toCellX_418a00(event.x),opXI_rex.toCellY_418a30(event.y));
						opXI_rex.getHighlighter()->input(OpXI_Event(current->id,opXI_rex.toCellX_418a00(event.x),opXI_rex.toCellY_418a30(event.y)));
					}
					previousId = lastId;
					lastId = current->id;
					break;
				}
			}
		}
	}
	opXI_cefa5f = false;
	current = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (opXI_flags_cec14c[i] && !opXI_keys_cefa84[i * 2 + 0x130] && !opXI_keys_cefa84[i * 2 + 0x12f])
			opXI_flags_cec14c[i] = false;
	}
	if (keyHandler && key.isKey && key.down)
	{
		if (opXI_flags_cec14c[0] && OpT8b_Fn9daf80('a',key.code,'z'))
			key.code -= 0x20;
		int sym = opXI_remap_cec458[key.code];
		if (OpT8b_Fn9daf80('A',sym,'Z'))
			keyHandler->key(sym,1);
		else if (OpT8b_Fn9daf80('a',sym,'z'))
		{
			if (opXI_flags_cec14c[0])
				keyHandler->key(sym - 0x20,1);
			else
				keyHandler->key(sym,0);
		}
		else if (OpT8b_Fn9daf80('0',sym,'9'))
			keyHandler->key(sym,2);
		else if (OpT8b_Fn9daf80(0x100,sym,0x109))
			keyHandler->key(sym - 0xd0,2);
		else if (OpT8b_Fn9daf80(' ',sym,'/') || OpT8b_Fn9daf80(':',sym,'@') || OpT8b_Fn9daf80('[',sym,'`') || OpT8b_Fn9daf80('{',sym,'~'))
			keyHandler->key(sym,OpS8b_Fn9d43b0(opXI_punctuation_caecf8,10,sym) ? 3 : 4);
		else
		{
			switch (sym)
			{
				case 8:
					keyHandler->key(8,5);
					break;
				case 13:
					keyHandler->key(opXI_flags_cec14c[1] ? 0x86 : 0xd,5);
					break;
				case 27:
					keyHandler->key(0x1b,5);
					break;
				case 127:
					keyHandler->key(0x7f,5);
					break;
				case 276:
					keyHandler->key(0x80,5);
					break;
				case 275:
					keyHandler->key(0x81,5);
					break;
				case 273:
					keyHandler->key(0x82,5);
					break;
				case 274:
					keyHandler->key(0x83,5);
					break;
				case 278:
					keyHandler->key(0x84,5);
					break;
				case 279:
					keyHandler->key(0x85,5);
					break;
				case 9:
					keyHandler->key(0x87,5);
					break;
			}
		}
	}
}
