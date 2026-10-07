// team_d_58: CCommands::input (0x7d0aa0, vtable slot 4 of CCommands).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <vector>
#include <string>
using namespace std;

struct KeyEvent58	// NOTE: placeholder name (12-byte input event)
{
	int key;
	int unknown04;
	int unknown08;

	KeyEvent58(int k);	// NOTE: placeholder name (0x415c60)
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

	bool isHidden();	// NOTE: placeholder name

	char pad4[0x5c];
};

class Console : public XConsole
{
public:
	virtual ~Console();
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	int unknown60;
	void *engine;
	void *title;
};

class CHelp58	// NOTE: placeholder name (0xc4-byte console, constructor 0x7d8d60)
{
public:
	CHelp58();
	char pad[0xc4];
};

class CMenu58	// NOTE: placeholder name (0xa0-byte console, constructor 0x7f2610)
{
public:
	CMenu58(int page);
	char pad[0xa0];
};

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern bool inputBlocked58_cefa5f;	// NOTE: placeholder name

class CCommands : public Console
{
public:
	virtual bool input(void *event);

	int					unknown6c;	// NOTE: placeholder name
	char				pad070[0xa0 - 0x70];
	vector<XConsole *>	pages;		// +0xa0, NOTE: placeholder name
	char				pad0b0[0x144 - 0xb0];
	unsigned int		readyTick;	// +0x144, NOTE: placeholder name

	void unknown7d1050(int index);	// NOTE: placeholder name
	void unknown7d1740();	// NOTE: placeholder name
	void unknown7d17d0();	// NOTE: placeholder name
	void unknown7d1840();	// NOTE: placeholder name
	void unknown7d18d0();	// NOTE: placeholder name
};

bool CCommands::input(void *event)
{
	if (tickCount < readyTick)
		return false;
	if (isHidden() || inputBlocked58_cefa5f)
		return false;
	if (XConsole::input(event))
		return true;
	switch (*(int *)event)
	{
	case 0x15:
	case 0x16:
	case 0x17:
	case 0x18:
	case 0x19:
	case 0x1a:
	case 0x1b:
		unknown7d1050(*(int *)event - 0x15);
		return true;
	case 0x1c:
		new CHelp58();
		return true;
	case 0x1d:
		new CMenu58(0);
		return true;
	case 0x1e:
		new CMenu58(1);
		return true;
	case 0x1f:
		if (unknown6c == 0 && !pages.empty())
			pages[0]->input(&KeyEvent58(0x14));
		return true;
	case 0x20:
		if (unknown6c == 0 && !pages.empty())
			pages[1]->input(&KeyEvent58(0x14));
		return true;
	case 0x21:
		unknown7d1740();
		return true;
	case 0x22:
		unknown7d17d0();
		return true;
	case 0x23:
		unknown7d1840();
		return true;
	case 0x24:
		unknown7d18d0();
		return true;
	case 0x25:
		close();
		return true;
	}
	return false;
}
