// Console trigger() methods etc. matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members and names are placeholders.
#include "../util/rng.h"
#include "../consoles/console.h"
void logWarning(string location, string message);	// NOTE: placeholder name (0x404e50)

extern RNG rng;	// NOTE: placeholder name (0xd30908)

class CTitle : public Console
{
public:
	virtual void trigger(const string &command, int value);

	XConsole *ascii;	// NOTE: placeholder name
	bool finished;	// NOTE: placeholder name
};

void CTitle::trigger(const string &command, int value)
{
	if (command == "remove_ascii")
	{
		if (ascii == NULL)
		{
			logError("CTitle::trigger()","ascii layer already removed");
			return;
		}
		removeSubconsole(ascii);
		ascii = NULL;
	}
	else if (command == "finished")
	{
		finished = true;
	}
}

struct GalleryData	// NOTE: placeholder name
{
	char pad[0x74];
	int supporterIndex;	// NOTE: placeholder name
};

struct GallerySupporter	// NOTE: placeholder name
{
	string name;
	char pad[0x38 - sizeof(string)];
};
extern GallerySupporter gallerySupporters[];	// NOTE: placeholder name (0xd035d8)

class CGalleryName : public Console	// NOTE: placeholder name
{
public:
	CGalleryName(XConsole *parent, int x, int y, int width, int height, int unknown);	// 0x496950
	void setText(int unknown1, int unknown2, const string &text);	// 0x4181d0, NOTE: placeholder name
	void unknown4969a0();	// NOTE: placeholder name

	int unknown6c;
};

class CGalleryText : public Console
{
public:
	virtual void trigger(const string &command, int value);
	GalleryData *getGalleryData() { return (GalleryData*)getParent(); };	// NOTE: placeholder name
};

void CGalleryText::trigger(const string &command, int value)
{
	if (command == "show_name")
	{
		if (getGalleryData()->supporterIndex == -1)
		{
			logError("CGalleryText::trigger()","gallerySupporterIndex is -1");
			return;
		}
		CGalleryName *name = new CGalleryName(this,1,0,getWidth()-2,1,4);
		name->setText(0,0,gallerySupporters[getGalleryData()->supporterIndex].name);
		name->unknown4969a0();
	}
}

struct LogMsg	// NOTE: placeholder name
{
	int pad0;
	string text;
};

class CLogMsgConsole : public Console	// NOTE: placeholder name
{
public:
	void setText(const string &text);	// 0x7b3ce0, NOTE: placeholder name
};

class CLogMsgs : public Console	// NOTE: placeholder name
{
public:
	void renewLastMessage();
	vector<LogMsg*> *getMessages();	// 0x48e4e0, NOTE: placeholder name

	char pad[0x74 - sizeof(Console)];
	int index;	// NOTE: placeholder name
	vector<CLogMsgConsole*> consoles;	// NOTE: placeholder name
};

void CLogMsgs::renewLastMessage()
{
	if (index == getMessages()->size() - 1)
	{
		if (consoles.empty())
		{
			logWarning("CLogMsgs::renewLastMessage()","console messages empty");
			return;
		}
		if (getMessages()->empty())
		{
			logWarning("CLogMsgs::renewLastMessage()","log messages empty");
			return;
		}
		consoles.back()->setText(getMessages()->back()->text);
	}
}

struct Particle	// NOTE: placeholder name
{
	char pad[0x10];
	Pos pos;
	Pos *getPos() { return &pos; };	// 0x462e10
};

class CEvolveRow : public Console	// NOTE: placeholder name
{
public:
	void setPosition(int x, int y);	// 0x417a90, NOTE: placeholder name
};

class CEvolveSequencing : public Console
{
public:
	virtual void trigger(const string &command, Particle *value);
	bool contains(Pos *pos);	// 0x4173d0, NOTE: placeholder name

	vector<CEvolveRow*> rows;	// NOTE: placeholder name
};

void CEvolveSequencing::trigger(const string &command, Particle *value)
{
	if (command == "faded")
	{
		int y = value->getPos()->y;
		int x;
		if (!contains(value->getPos()) || rows[y] == NULL)
		{
			logError("CEvolveSequencing::trigger()","Particle not where expected");
			return;
		}
		do
		{
			x = rng.rangeInt(0,getWidth() - rows[y]->getWidth());
		}
		while (x == rows[y]->getPos().x);
		rows[y]->setPosition(x,y);
		rows[y]->animate("A_CEvolveSequencing_Mov");
	}
	else if (command == "finished")
	{
		int y = value->getPos()->y;
		if (!contains(value->getPos()) || rows[y] == NULL)
		{
			logError("CEvolveSequencing::trigger()","Particle not where expected");
			return;
		}
		if (rows[y] != NULL)
		{
			removeSubconsole(rows[y]);
			rows[y] = NULL;
		}
	}
}

struct CmdPos	// NOTE: placeholder name
{
	int x;
	int y;

	CmdPos();	// 0x453b40
	CmdPos &operator=(const CmdPos &pos);	// 0x46ca50
	void add(int x_, int y_);	// 0x40a2a0, NOTE: placeholder name
};
extern CmdPos advancedCommandsPos;	// NOTE: placeholder name (0xd323bc)

class CCommandButton : public Console	// NOTE: placeholder name
{
public:
	CCommandButton(XConsole *parent, int x, int y, int width, int index);	// 0x7c2d60

	int index;
};

class CCommandPage : public XConsole	// NOTE: placeholder name
{
public:
	int getPage() { return page; };	// NOTE: placeholder name
	void setPage(int page_);	// 0x492c00

	char pad[0x6c - sizeof(XConsole)];
	int page;
};

template <class T> void removeVectorElement(vector<T> &v, int index);	// NOTE: placeholder name
template <class T> void appendVector(vector<T> &v, vector<T> &add);	// NOTE: placeholder name (0x9d0300)

extern XConsole *mainConsole;	// NOTE: placeholder name (0xcec054)
extern int fontCellSize;	// NOTE: placeholder name (0xcaf128)

class CCommands : public Console
{
public:
	void setAdvancedCommandsPage(int page);

	char pad[0xb4 - sizeof(Console)];
	vector<CCommandButton*> buttons;	// NOTE: placeholder name
	CCommandPage *pageIndicator;	// NOTE: placeholder name
	XConsole *prevArrow;	// NOTE: placeholder name
	XConsole *nextArrow;	// NOTE: placeholder name
};

// NOTE: local names (e.g. "total") are chosen to reproduce the original stack slot layout
void CCommands::setAdvancedCommandsPage(int page)
{
	if (pageIndicator == NULL || pageIndicator->getPage() == page)
	{
		logError("CCommands::setAdvancedCommandsPage()","page already set");
		return;
	}
	int y;
	int afirst;
	bool asecond = (page == 1);
	for (int count = asecond ? 2 : 3; count;)
	{
		removeSubconsole(buttons.front());
		removeVectorElement(buttons,0);
		count--;
	}
	vector<CCommandButton*> oldButtons(buttons);
	buttons.clear();
	afirst = asecond ? 0 : 3;
	CmdPos total;
	total = advancedCommandsPos;
	total.add(1,2);
	buttons.push_back(new CCommandButton(this,total.x,total.y,mainConsole->getWidth() * fontCellSize - fontCellSize,afirst));
	y = total.y + buttons.back()->getHeight() + 1;
	for (int i = afirst + 1; i <= (asecond ? 2 : 4); i++)
	{
		buttons.push_back(new CCommandButton(this,total.x,y,buttons.back()->getWidth(),i));
		y = y + buttons.back()->getHeight() + 1;
	}
	for (unsigned int j = 0; j < buttons.size(); j++)
		buttons[j]->open();
	appendVector(buttons,oldButtons);
	pageIndicator->setPage(page);
	prevArrow->setHidden(!asecond);
	nextArrow->setHidden(asecond);
}
