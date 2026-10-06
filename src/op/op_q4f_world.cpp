// op_q4f: CWorldMap* consoles in 0x9934e0-0x9aefb0, Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos) throw();	// 0x46ca50
	Pos &operator=(const Pos &pos);
};

struct Point
{
	int x;
	int y;

	Point(int x_, int y_);	// 0x46ca20
	Point(int v);	// 0x409990
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(const Rect &rect);	// 0x40a720
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

	bool isHidden();
	void setHidden(bool hidden_);
	int getHeight();
	int getWidth();	// 0x44b0d0
	Rect getRect();
	Pos localToAbs(Pos pos);
	void removeSubconsole(XConsole *console);
	void deleteSubconsoles();
	void print(int x, int y, const string &text);
	void resetBack_418450();	// NOTE: placeholder name
	void setScaleX_417b60(float value);	// NOTE: placeholder name
	void setScaleY_417b80(float value);	// NOTE: placeholder name
	float getScaleX();
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)
	void unknown429f10(int a, int b);	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class OpQ4f_Engine	// NOTE: placeholder name (Engine)
{
public:
	bool update();	// NOTE: placeholder name (0x50fff0)
	void stopAll();	// NOTE: placeholder name (0x50ff30)
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);	// NOTE: placeholder name

	void animate(string name);

	int unknown60;
	OpQ4f_Engine *engine;
	void *title;
};

class OpQ4f_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void unknown416640();	// NOTE: placeholder name
	void registerConsole(int command, Console *console, int unknown1, int unknown2);	// NOTE: placeholder name (0x416790)
	void unknown4162e0(int command, int value);	// NOTE: placeholder name
};
extern OpQ4f_KeyMap *opq4f_keyMap;	// NOTE: placeholder name (0xcefa8c)

class OpQ4f_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	bool isIn(const Rect &rect);	// NOTE: placeholder name (0x41a730)
	bool getField_41a6e0();	// NOTE: placeholder name
	void setPos_41a910(const Pos &pos);	// NOTE: placeholder name
};
extern OpQ4f_Mouse *opq4f_mouse;	// NOTE: placeholder name (0xcefa94)

class OpQ4f_MapView : public XConsole	// NOTE: placeholder name (0xcec054)
{
public:
	void unknown429fe0(Console *console, const Point &pos, int flag);	// NOTE: placeholder name
};
extern OpQ4f_MapView *opq4f_cec054;	// NOTE: placeholder name

class OpQ4f_PlayerData	// NOTE: placeholder name (object at 0xcf45d8)
{
public:
	void unknown77fbc0(int value);	// NOTE: placeholder name
};
extern OpQ4f_PlayerData opq4f_playerData_cf45d8;	// NOTE: placeholder name

extern bool opq4f_inputBlocked;	// NOTE: placeholder name (0xcefa5f)
extern unsigned int opq4f_tickCount;	// NOTE: placeholder name (0xcaed20)
extern vector<int> opq4f_flags_d22590;	// NOTE: placeholder name
extern int opq4f_cf27ec;	// NOTE: placeholder name
extern int opq4f_cf27f0;	// NOTE: placeholder name
bool opq4f_unknown4328a0();	// NOTE: placeholder name
int opq4f_centerOffset_437190(int a, int b);	// NOTE: placeholder name ((b - a) / 2)

struct OpQ4f_MapNode	// NOTE: placeholder name (world map node)
{
	int unknown00;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
	char unknown08[0x27 - 0x08];	// NOTE: placeholder name
	bool unknown27;	// NOTE: placeholder name
	char unknown28[0x29 - 0x28];	// NOTE: placeholder name
	bool unknown29;	// NOTE: placeholder name
	bool unknown2a;	// NOTE: placeholder name
	char unknown2b[0x2f - 0x2b];	// NOTE: placeholder name
	bool unknown2f;	// NOTE: placeholder name
};

class HItem
{
protected:
	int ID;
public:
	bool isValid() const;	// 0x9b7230
};

class HEntity : public HItem
{
public:
	OpQ4f_MapNode *node_9b7910() const;	// NOTE: placeholder name (map node handle operator->)
};

//==================================================================
// CWorldMapInfo / CWorldMapPiece / CWorldMap
//==================================================================

class CWorldMapInfo : public Console
{
public:
	virtual bool input(void *event);
	void clearInfo(HEntity entity_);	// NOTE: placeholder name
	void setInfo(HEntity node);
};

class CWorldMap;
extern CWorldMap *opq4f_cec070;	// NOTE: placeholder name (0xcec070)

class CWorldMapPiece : public Console
{
public:
	virtual void update();

	HEntity node;	// NOTE: placeholder name
	Console *highlight;	// NOTE: placeholder name
};

class OpQ4f_WorldMapItem	// NOTE: placeholder name (CWorldMap element at +0xac)
{
	int pad[16];
};

class CWorldMap : public Console
{
public:
	CWorldMap(XConsole *parent);
	virtual ~CWorldMap();	// defined in op_w7
	virtual bool input(void *event);
	virtual void update();
	virtual void open();
	virtual void close();

	CWorldMapInfo *getInfo_4b6440();	// NOTE: placeholder name

	unsigned int unknown6c;	// NOTE: placeholder name
	vector<HEntity> nodes;	// NOTE: placeholder name
	vector<Console*> unknown80;	// NOTE: placeholder name
	unsigned int unknown90;	// NOTE: placeholder name
	int unknown94;	// NOTE: placeholder name
	vector<Console*> unknown98;	// NOTE: placeholder name
	CWorldMapInfo *info;	// NOTE: placeholder name
	vector<OpQ4f_WorldMapItem> unknownac;	// NOTE: placeholder name

	void unknown993fa0();	// NOTE: placeholder name
};

extern vector<HEntity> opq4f_nodes_d1e88c;	// NOTE: placeholder name
void opq4f_eraseAt_9d6440(vector<HEntity> &v, unsigned int &i);	// NOTE: placeholder name
void opq4f_eraseNode_9da940(vector<HEntity> &v, unsigned int i);	// NOTE: placeholder name
extern Rect opq4f_worldMapRect_d3238c;	// NOTE: placeholder name

bool CWorldMapInfo::input(void *event)
{
	if (isHidden() || opq4f_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (*(int*)event)
	{
		case 0x185:
			opq4f_cec070->close();
			return true;
		default:
			return false;
	}
}

void CWorldMapPiece::update()
{
	if (isHidden())
		return;
	engine->update();
	if (node.isValid() && opq4f_cec070->getInfo_4b6440())
	{
		bool inside = opq4f_mouse->isIn(getRect());
		if (inside)
		{
			if (!highlight)
			{
				if (node.node_9b7910()->unknown27)
				{
					highlight = new Console(this,5,5,-1,-1,2,false,-1);
					highlight->resetBack_418450();
					highlight->animate("A_CWorldMap_Highlight");
				}
				else
				{
					highlight = new Console(this,3,3,-1,-1,2,false,-1);
					highlight->resetBack_418450();
					highlight->animate("A_CWorldMap_Highlight2");
				}
				opq4f_cec070->getInfo_4b6440()->setInfo(node);
			}
		}
		else if (highlight)
		{
			opq4f_cec070->getInfo_4b6440()->clearInfo(node);
			removeSubconsole(highlight);
			highlight = NULL;
		}
	}
	updateBase429e30();
}

CWorldMap::CWorldMap(XConsole *parent)
	: Console(parent,opq4f_worldMapRect_d3238c,2,true,15)
{
}

void CWorldMap::open()
{
	setHidden(false);
	opq4f_cec054->setHidden(true);
	setScaleX_417b60(1.0f);
	setScaleY_417b80(1.0f);
	opq4f_keyMap->registerConsole(0x1e,this,0x185,1);
	opq4f_flags_d22590[0x4b] = 1;
	unknown60 = 3;
	opq4f_cec054->unknown429fe0(this,opq4f_unknown4328a0() ? Point(opq4f_cf27ec,opq4f_cf27f0) : Point(0),0);
	animate("A_CWorldMap_Wipe");
	unknown80.clear();
	unknown90 = -1;
	unknown94 = 0;
	unknown98.clear();
	info = NULL;
	nodes = opq4f_nodes_d1e88c;
	for (unsigned int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i].node_9b7910()->unknown2f)
		{
			opq4f_eraseAt_9d6440(nodes,i);
		}
		else if (nodes[i].node_9b7910()->type == 0xc)
		{
			opq4f_eraseNode_9da940(nodes,i);
			if (i < nodes.size())
			{
				opq4f_eraseAt_9d6440(nodes,i);
				if (i + 1 < nodes.size())
				{
					if (nodes[i + 1].node_9b7910()->type == 0xd)
						nodes[i].node_9b7910()->unknown29 = true;
					else if (nodes[i + 1].node_9b7910()->type == 0xe)
						nodes[i].node_9b7910()->unknown2a = true;
				}
			}
			i--;
		}
	}
	if (nodes.size() < 2)
	{
		string text = "No Route Data";
		Console *label = new Console(this,text.size(),1,opq4f_centerOffset_437190(text.size(),getWidth()),getHeight() / 2,2,false,-1);
		label->print(0,0,text);
		label->animate("A_CWorldMap_None");
	}
	else
	{
		unknown993fa0();
	}
}

void CWorldMap::update()
{
	if (isHidden())
		return;

	switch (unknown60)
	{
		case 0:
			break;
		case 1:
			if (!engine->update())
				unknown60 = 3;
			break;
		case 3:
			engine->update();
			break;
		case 4:
			engine->update();
			if (getScaleX() != 0.0f)
			{
				if (opq4f_tickCount - unknown6c >= 500)
				{
					setScaleX_417b60(0.0f);
					setScaleY_417b80(0.0f);
				}
				else
				{
					setScaleX_417b60(1.0f - (opq4f_tickCount - unknown6c) / 500.0);
					setScaleY_417b80(1.0f - (opq4f_tickCount - unknown6c) / 500.0);
					break;
				}
			}
			engine->stopAll();
			unknown60 = 0;
			setHidden(true);
			opq4f_keyMap->unknown416640();
			setHidden(true);
			unknown60 = 0;
			break;
	}
	updateBase429e30();
}

void CWorldMap::close()
{
	if (unknown60 == 4)
		return;
	unknown60 = 4;
	unknown429f10(0,0);
	deleteSubconsoles();
	opq4f_keyMap->unknown4162e0(0x1e,0);
	opq4f_cec054->setHidden(false);
	unknown6c = opq4f_tickCount;
	animate("A_BlockFadeVis");
	opq4f_playerData_cf45d8.unknown77fbc0(1);
}

bool CWorldMap::input(void *event)
{
	if (isHidden() || opq4f_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (*(int*)event)
	{
		case 0x183:
			if (opq4f_mouse->getField_41a6e0() && unknown90 != -1)
			{
				if (unknown90 < unknown80.size() - 1)
					unknown90 = unknown90 + 1;
				else
					unknown90 = 0;
				opq4f_mouse->setPos_41a910(unknown80[unknown90]->localToAbs(Pos(0,0)));
			}
			return true;
		case 0x184:
			if (opq4f_mouse->getField_41a6e0() && unknown90 != -1)
			{
				if (unknown90 != 0)
					unknown90 = unknown90 - 1;
				else
					unknown90 = unknown80.size() - 1;
				opq4f_mouse->setPos_41a910(unknown80[unknown90]->localToAbs(Pos(0,0)));
			}
			return false;
		case 0x185:
			if (unknown60 != 4)
				close();
			return true;
		default:
			return false;
	}
}
