// alpha2_01: input manager SDL event handler (0x427320), called from REX::run.
// NOTE: placeholder names / placeholder layout throughout.
#include <string>
#include <vector>
using namespace std;

struct A2Ev_SDLEvent	// NOTE: SDL 1.2 event union (0x14 bytes)
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

struct A2Ev_Rect
{
	A2Ev_Rect();
	int x;
	int y;
	int width;
	int height;
};

struct A2Ev_Message	// NOTE: placeholder name (0xc bytes)
{
	A2Ev_Message(int id);	// 0x415c60
	A2Ev_Message(int id, int x, int y);	// 0x415ca0
	int id;
	int px;
	int py;
};

class A2Ev_Console	// NOTE: placeholder name
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void message(const A2Ev_Message &msg);	// slot 4
	A2Ev_Rect getRect();	// 0x428710
};

class A2Ev_Focus	// NOTE: placeholder name
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void keyInput(int key, int kind);	// slot 5
};

struct A2Ev_KeyInput	// NOTE: placeholder name (0x2c bytes)
{
	A2Ev_KeyInput(unsigned char type, A2Ev_SDLEvent event);	// 0x426f30
	~A2Ev_KeyInput();	// 0x9e78d0
	bool equals_415e30(const A2Ev_KeyInput &other);

	int id;
	string text;
	bool isKey;
	int code;
	bool shift;
	bool ctrl;
	bool alt;
	bool down;
	int unknown2c;
};

class A2Ev_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	bool inside_41a730(const A2Ev_Rect &rect);
	void setPosition_41a800(int x, int y);
};

class A2Ev_Rex	// NOTE: placeholder name (0xd223f0)
{
public:
	int unknown418a00(int x);
	int unknown418a30(int y);
	A2Ev_Console *getHighlighter_4ab670();
};

struct A2Ev_Timer
{
	bool paused;
};

extern A2Ev_Mouse *a2ev_mouse_cefa94;
extern A2Ev_Rex a2ev_rex_d223f0;
extern A2Ev_Timer *a2ev_timer_cefa9c;
extern unsigned int a2ev_tickCount_caed20;
extern bool a2ev_modifiers_cec14c[4];
extern bool a2ev_mouseDown_cefa74[2];
extern bool a2ev_consoleInputBlocked_cefa5f;
extern unsigned char *a2ev_keyState_cefa84;
extern int a2ev_keyMap_cec458[];
extern int a2ev_punct_caecf8[];
bool OpS8b_Fn9d43b0(int *values, unsigned int count, int value);
bool OpT8b_Fn9daf80(int low, int value, int high);

class A2Ev_Input	// NOTE: placeholder name (object at 0xcefa8c)
{
public:
	void handleEvent(unsigned char type, A2Ev_SDLEvent event);

	vector<vector<A2Ev_KeyInput *> > bindings;	// +0x00
	vector<bool> enabled;	// +0x10
	vector<bool> blocked;	// +0x24
	bool dirty;	// +0x38
	char pad39[0x4c - 0x39];
	A2Ev_Focus *focus;	// +0x4c
	A2Ev_Console *console;	// +0x50
	int consoleMessage;	// +0x54
	bool consoleClicked;	// +0x58
	bool (*consoleClickFilter)();	// +0x5c
	bool (*mouseFilter)(A2Ev_KeyInput *input);	// +0x60
	bool commandsOnly;	// +0x64
	char pad65[0x6c - 0x65];
	int lastCommand;	// +0x6c
	int previousCommand;	// +0x70
	unsigned int lastEventTime;	// +0x74
	void (*onEvent)();	// +0x78
	A2Ev_KeyInput *current;	// +0x7c
	vector<unsigned int> pressTime;	// +0x80
	vector<unsigned int> holdTime;	// +0x90
};

void A2Ev_Input::handleEvent(unsigned char type, A2Ev_SDLEvent event)
{
	if (onEvent != NULL)
		onEvent();
	lastEventTime = a2ev_tickCount_caed20;
	if (dirty)
	{
		blocked.assign(enabled.size(),false);
		dirty = false;
	}
	bool state = type == 2 ? true : false;
	switch (event.sym)
	{
		case 303:
		case 304:
			a2ev_modifiers_cec14c[0] = state;
			return;
		case 305:
		case 306:
			a2ev_modifiers_cec14c[1] = state;
			return;
		case 307:
		case 308:
			a2ev_modifiers_cec14c[2] = state;
			return;
		case 301:
			a2ev_modifiers_cec14c[3] = state;
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
			a2ev_mouseDown_cefa74[button] = type == 5;
			if (type == 5)
				pressTime[button] = a2ev_tickCount_caed20;
			else if (a2ev_tickCount_caed20 >= pressTime[button])
				holdTime[button] = a2ev_tickCount_caed20 - pressTime[button];
			else
				holdTime[button] = 0;
		}
	}
	A2Ev_KeyInput input(type,event);
	if (mouseFilter != NULL && !input.isKey && mouseFilter(&input))
		return;
	if (console != NULL && input.code == 1 && input.down && !a2ev_mouse_cefa94->inside_41a730(console->getRect()) && (consoleClickFilter == NULL || !consoleClickFilter()))
	{
		console->message(A2Ev_Message(consoleMessage));
		consoleClicked = true;
		a2ev_consoleInputBlocked_cefa5f = false;
		return;
	}
	else if (consoleClicked && input.code == 1 && !input.down)
	{
		consoleClicked = false;
		return;
	}
	int end = a2ev_timer_cefa9c->paused ? 0 : bindings.size() - 1;
	for (int i = 0; i <= end; i++)
	{
		if (enabled[i] && !blocked[i])
		{
			for (unsigned int j = 0; j < bindings[i].size(); j++)
			{
				if (bindings[i][j]->equals_415e30(input))
				{
					current = bindings[i][j];
					if (current->isKey)
						a2ev_rex_d223f0.getHighlighter_4ab670()->message(A2Ev_Message(current->id));
					else if (commandsOnly)
						break;
					else
					{
						a2ev_mouse_cefa94->setPosition_41a800(a2ev_rex_d223f0.unknown418a00(event.x),a2ev_rex_d223f0.unknown418a30(event.y));
						a2ev_rex_d223f0.getHighlighter_4ab670()->message(A2Ev_Message(current->id,a2ev_rex_d223f0.unknown418a00(event.x),a2ev_rex_d223f0.unknown418a30(event.y)));
					}
					previousCommand = lastCommand;
					lastCommand = current->id;
					break;
				}
			}
		}
	}
	a2ev_consoleInputBlocked_cefa5f = false;
	current = NULL;
	for (int k = 0; k < 3; k++)
	{
		if (a2ev_modifiers_cec14c[k] && !a2ev_keyState_cefa84[k * 2 + 304] && !a2ev_keyState_cefa84[k * 2 + 303])
			a2ev_modifiers_cec14c[k] = false;
	}
	if (focus != NULL && input.isKey && input.down)
	{
		if (a2ev_modifiers_cec14c[0] && OpT8b_Fn9daf80('a',input.code,'z'))
			input.code -= 32;
		int key = a2ev_keyMap_cec458[input.code];
		if (OpT8b_Fn9daf80('A',key,'Z'))
			focus->keyInput(key,1);
		else if (OpT8b_Fn9daf80('a',key,'z'))
		{
			if (a2ev_modifiers_cec14c[0])
				focus->keyInput(key - 32,1);
			else
				focus->keyInput(key,0);
		}
		else if (OpT8b_Fn9daf80('0',key,'9'))
			focus->keyInput(key,2);
		else if (OpT8b_Fn9daf80(256,key,265))
			focus->keyInput(key - 208,2);
		else if (OpT8b_Fn9daf80(' ',key,'/') || OpT8b_Fn9daf80(':',key,'@') || OpT8b_Fn9daf80('[',key,'`') || OpT8b_Fn9daf80('{',key,'~'))
			focus->keyInput(key,OpS8b_Fn9d43b0(a2ev_punct_caecf8,10,key) ? 3 : 4);
		else
		{
			switch (key)
			{
				case 8:
					focus->keyInput(8,5);
					break;
				case 13:
					focus->keyInput(a2ev_modifiers_cec14c[1] ? 134 : 13,5);
					break;
				case 27:
					focus->keyInput(27,5);
					break;
				case 127:
					focus->keyInput(127,5);
					break;
				case 276:
					focus->keyInput(128,5);
					break;
				case 275:
					focus->keyInput(129,5);
					break;
				case 273:
					focus->keyInput(130,5);
					break;
				case 274:
					focus->keyInput(131,5);
					break;
				case 278:
					focus->keyInput(132,5);
					break;
				case 279:
					focus->keyInput(133,5);
					break;
				case 9:
					focus->keyInput(135,5);
					break;
			}
		}
	}
}
