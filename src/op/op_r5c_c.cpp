// op_r5c_c: CTransmission console (0x8f3e50-0x8f5810), Beta 17.1.
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
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;
};

class ConsoleTitle;
class OpR5c_Item;

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

	bool isHidden();
	int getWidth44b0d0();	// NOTE: placeholder name (0x44b0d0)
	int getHeight();
	void print(int x, int y, const string &text);
	void printAligned(int x, int y, int align, const string &text);
	void clear(int x, int y, int width, int height);
	void clear();
	void setHidden(bool hidden_);
	void setScaleX_417b60(float value);	// NOTE: placeholder name
	void setScaleY_417b80(float value);	// NOTE: placeholder name
	float getScaleX();
	void setBack_417fc0(int x, int y, XColor color, int mode);	// NOTE: placeholder name
	int getChar(int x, int y);
	void printWrapped_418260(int x, int y, int width, int height, const string &text);	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);
	void unknown429f10(int a, int b);	// NOTE: placeholder name
	void deleteSubconsoles();
	XConsole *getParent();	// 0x9b8f00
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)

	char pad04[0x60 - 0x04];
};

class OpR5c_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class OpR5c_Engine	// NOTE: placeholder name (Engine)
{
public:
	bool update();	// NOTE: placeholder name (0x50fff0)
	void stopAll();	// NOTE: placeholder name (0x50ff30)
	OpR5c_EngineItem *unknown50fb50(OpR5c_Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void render();
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);

	int unknown60;
	OpR5c_Engine *engine;
};

class Entity	// NOTE: placeholder layout
{
public:
	int getFaction();	// 0x45a2c0
	string *getName416f40();	// NOTE: placeholder name (folded +0xc getter)
	class OpR5c_AI *getAI();	// NOTE: placeholder name (folded getter 0x45b590)
	bool isHostileTo(class HEntity e);	// 0x45aa70
	class OpR5c_Inventory *getInventory();	// NOTE: placeholder name
	Pos &getPosition();	// 0x45a4a0
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity() throw();	// 0x9b6590
	bool isValid() const;
	Entity *operator->() const;	// 0x9b6570
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp() throw();	// 0x9b6590
	bool isValid() const;
	OpR5c_Item *operator->() const;	// 0x9b65b0
};

struct XEvent	// NOTE: placeholder name
{
	int type;
	Pos mouse;
};

class OpR5c_SpecialCommands	// NOTE: placeholder name (CSpecialCommands at 0xcec0ac)
{
public:
	void setTimer();	// 0x4acb40
};
extern OpR5c_SpecialCommands *opr5c_specialCommands;	// NOTE: placeholder name (0xcec0ac)

class OpR5c_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void unknown416640();	// NOTE: placeholder name
	void unknown4162e0(int command, int value);	// NOTE: placeholder name
};
extern OpR5c_KeyMap *opr5c_keyMap;	// NOTE: placeholder name (0xcefa8c)

class OpR5c_AudioMixer	// NOTE: placeholder name (0xcefa90)
{
public:
	void unknown419bf0(int handle);	// NOTE: placeholder name
};
extern OpR5c_AudioMixer *opr5c_audioMixer;	// NOTE: placeholder name (0xcefa90)

extern bool opr5c_consoleInputBlocked;	// NOTE: placeholder name (0xcefa5f)
extern unsigned int opr5c_tickCount;	// NOTE: placeholder name (0xcaed20)
extern Pos opr5c_cfbec0;	// NOTE: placeholder name
extern string opr5c_string_cf4acc;	// NOTE: placeholder name
extern string opr5c_string_cf0c70;	// NOTE: placeholder name

struct OpR5c_TransmissionData	// NOTE: placeholder name (element of the table at 0xcf3a20)
{
	char pad00[0x04];
	string name;	// NOTE: placeholder name
	char pad20[0x2c - 0x20];
	vector<string> pages;	// NOTE: placeholder name
	char pad3c[0x5c - 0x3c];
	int unknown5c;	// NOTE: placeholder name
	string unknown60;	// NOTE: placeholder name
	string unknown7c;	// NOTE: placeholder name
};
extern vector<OpR5c_TransmissionData*> opr5c_transmissions;	// NOTE: placeholder name (0xcf3a20)

bool showMessage(int type, const string &text, int a, int b, HEntity entity, HProp prop, int c, int d);	// 0x5111e0

class OpR5c_Messages	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(int flag);	// NOTE: placeholder name
};
extern OpR5c_Messages *opr5c_messages;	// NOTE: placeholder name (0xcec058)

class OpR5c_LogMsgs	// NOTE: placeholder name (CLogMsgs at 0xcec0b4)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpR5c_LogMsgs *opr5c_logMsgs;	// NOTE: placeholder name (0xcec0b4)

template <class T> void opr5c_appendVector(vector<T> &a, vector<T> &b);	// NOTE: placeholder name (0x9db8c0)
void opr5c_unknown4351e0(string &text);	// NOTE: placeholder name
void opr5c_replace407e00(string &text, string from, string to);	// NOTE: placeholder name
string opr5c_unknown510110(const string &text, int a);	// NOTE: placeholder name
void opr5c_findAnimation(const string &name, int *index);	// NOTE: placeholder name (0x9d45a0)


class OpR5c_AI	// NOTE: placeholder name (EntityAI)
{
public:
	bool unknown458fb0(HEntity e);	// NOTE: placeholder name
	void addTarget(HEntity e, int a, int b, int c, int d);	// NOTE: placeholder name
};

class OpR5c_Inventory;

class OpR5c_Item	// NOTE: placeholder name (Item)
{
public:
	void unknown579c80();	// NOTE: placeholder name
};

class OpR5c_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer();	// NOTE: placeholder name (0x4630f0)
	HEntity getEntity671();	// NOTE: placeholder name (0x463110)
	void unknown6c6660(string &name);	// NOTE: placeholder name
	HProp placeItem(const string &itemName, const Pos &p);	// NOTE: placeholder name
};
extern OpR5c_World *opr5c_world;	// NOTE: placeholder name (0xcefc4c)

class OpR5c_PopupMgr	// NOTE: placeholder name (0xcefb48)
{
public:
	bool say(int ID, bool force, string name);	// NOTE: placeholder name

	char pad00[0x28];
	bool unknown28;	// NOTE: placeholder name
};
extern OpR5c_PopupMgr *opr5c_popupMgr;	// NOTE: placeholder name (0xcefb48)

class OpR5c_GameData	// NOTE: placeholder name (0xd1e860)
{
public:
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
};
extern OpR5c_GameData opr5c_gameData;	// NOTE: placeholder name (0xd1e860)

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
extern string opr5c_string_d2ec34;	// NOTE: placeholder name
bool opr5c_unknown5141b0(int id, string *name, int a, int b, HEntity e, int c);	// NOTE: placeholder name
bool opr5c_unknown4569a0(int id, HEntity a, HEntity b, HProp c, HProp item, int d, string *name, OpR5c_Inventory *e, HEntity f, HProp g, HProp h, int i);	// NOTE: placeholder name
bool opr5c_unknown797e60(string &name, int flag);	// NOTE: placeholder name
void opr5c_message(int type, HEntity entity, const string &text, int value);	// NOTE: placeholder name (opW5_message)

//==================================================================
// CTransmission
//==================================================================

class OpR5c_Transmission : public Console	// NOTE: placeholder name (CTransmission, vtable 0xc35b88)
{
public:
	void update8f4e70();	// NOTE: placeholder name (vtable slot 6)
	void close8f5000();	// NOTE: placeholder name (vtable slot 9)
	bool input8f5810(XEvent *event);	// NOTE: placeholder name (vtable slot 4)
	string getName8f4d40();	// NOTE: placeholder name
	void unknown8f4af0();	// NOTE: placeholder name
	void unknown8f5090();	// NOTE: placeholder name
	void unknown8f3e50();	// NOTE: placeholder name

	char pad68[0x6c - 0x68];
	unsigned int unknown6c;	// NOTE: placeholder name
	char pad70[0x74 - 0x70];
	unsigned int unknown74;	// NOTE: placeholder name
	unsigned int unknown78;	// NOTE: placeholder name
	vector<string> pages;	// NOTE: placeholder name
	HEntity entity;	// NOTE: placeholder name
	int unknown90;	// NOTE: placeholder name
	XConsole *unknown94;	// NOTE: placeholder name
	int unknown98;	// NOTE: placeholder name
};

void OpR5c_Transmission::update8f4e70()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
		break;	// NOTE: reproduces a dead jump before the first case
		case 1:
			if (!engine->update())
				unknown60 = 3;
			break;
			break;	// NOTE: reproduces a dead jump
		case 4:
			engine->update();
			if (getScaleX() != 0)
			{
				if (opr5c_tickCount - unknown6c >= 500)
				{
					setScaleX_417b60(0);
					setScaleY_417b80(0);
				}
				else
				{
					setScaleX_417b60(1.0 - (double)(opr5c_tickCount - unknown6c) / 500.0);
					setScaleY_417b80(1.0 - (double)(opr5c_tickCount - unknown6c) / 500.0);
					break;
				}
			}
			engine->stopAll();
			unknown60 = 0;
			setHidden(true);
			unknown8f4af0();
			opr5c_specialCommands->setTimer();
			opr5c_keyMap->unknown416640();
			unknown8f5090();
			getParent()->removeSubconsole(this);
			return;
	}
	updateBase429e30();
}

void OpR5c_Transmission::close8f5000()
{
	if (unknown60 == 4)
		return;
	unknown60 = 4;
	unknown429f10(0,0);
	deleteSubconsoles();
	if (unknown98 != -1)
		opr5c_audioMixer->unknown419bf0(unknown98);
	opr5c_keyMap->unknown4162e0(0x11,0);
	unknown6c = opr5c_tickCount;
	animate("A_BlockFadeVis");
}

bool OpR5c_Transmission::input8f5810(XEvent *event)
{
	if (isHidden() || opr5c_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	switch (event->type)
	{
		case 0x104:
			if (unknown78 == opr5c_transmissions[unknown74]->pages.size() + pages.size() - 1)
				close();
			else
			{
				unknown78++;
				unknown8f3e50();
			}
			return true;
		case 0x105:
			close();
			return true;
	}
	return false;
}

string OpR5c_Transmission::getName8f4d40()
{
	return entity->getFaction() == 0x4d ? string("Optimus") : *entity->getName416f40();
}

void OpR5c_Transmission::unknown8f4af0()
{
	vector<string> lines(opr5c_transmissions[unknown74]->pages);
	opr5c_appendVector(lines,pages);
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string text = lines[i];
		opr5c_unknown4351e0(text);
		opr5c_replace407e00(text,opr5c_string_cf4acc,opr5c_string_cf0c70);
		opr5c_unknown510110(text,0);
		if (i == 0)
			text.insert(0,getName8f4d40() + ": ");
		do
		{
			if (showMessage(0x322,text,0,0,HEntity(),HProp(),0,0))
				opr5c_messages->unknown8758d0(1);
			opr5c_logMsgs->scrollToEnd();
		} while (false);
	}
}

void OpR5c_Transmission::unknown8f5090()
{
	if (!opr5c_transmissions[unknown74]->unknown7c.empty())
	{
		string text = opr5c_transmissions[unknown74]->unknown7c;
		opr5c_unknown4351e0(text);
		if (text.find(opr5c_string_d2ec34,0) == 0)
			opr5c_world->unknown6c6660(text);
		else
			opr5c_unknown797e60(text,0);
	}
	if (opr5c_transmissions[unknown74]->unknown5c)
	{
		if (opr5c_transmissions[unknown74]->unknown60.empty())
		{
			do
			{
				opr5c_unknown5141b0(opr5c_transmissions[unknown74]->unknown5c,NULL,0,0,HEntity(),0);
			} while (false);
		}
		else
		{
			do
			{
				opr5c_unknown5141b0(opr5c_transmissions[unknown74]->unknown5c,&opr5c_transmissions[unknown74]->unknown60,0,0,HEntity(),0);
			} while (false);
		}
	}
	if (entity->isHostileTo(opr5c_world->getPlayer()) && !entity->getAI()->unknown458fb0(opr5c_world->getPlayer()))
		entity->getAI()->addTarget(opr5c_world->getPlayer(),1,0,1,0);
	opr5c_unknown4569a0(0x3a,entity,HEntity(),HProp(),HProp(),0,0,entity->getInventory(),entity,HProp(),HProp(),0);
	if (opr5c_popupMgr)
	{
		bool unattacked = (opr5c_transmissions[unknown74]->name == "EX-DEC_EXI" || opr5c_transmissions[unknown74]->name == "EX-DEC_WAR") && !stringToInt(opr5c_gameData.unknown46f6d0("exiAttackedLocals_g"));
		if (unattacked)
			opr5c_popupMgr->unknown28 = true;
		else if (opr5c_transmissions[unknown74]->name == "OPTIMUS_SCR4")
			opr5c_popupMgr->say(0x6d,false,"");
		else if (opr5c_transmissions[unknown74]->name == "WARLORD_RES")
			opr5c_popupMgr->say(0x68,false,"");
		else if (opr5c_transmissions[unknown74]->name == "IMPRINTER_BEFORE")
			opr5c_popupMgr->say(0x6e,false,"");
		else if (opr5c_transmissions[unknown74]->name == "WARLORD_WAR")
			opr5c_popupMgr->say(0x70,false,"");
		else if (opr5c_transmissions[unknown74]->name == "SIGIX_QUA")
			opr5c_popupMgr->say(0x71,false,"");
		else if (opr5c_transmissions[unknown74]->name == "MAINC_A")
		{
			if (opr5c_popupMgr->unknown28 && opr5c_world->getEntity671().isValid())
			{
				bool said = opr5c_popupMgr->say(0x76,false,"");
				HProp item = opr5c_world->placeItem("Meganuke",opr5c_world->getEntity671()->getPosition());
				if (item.isValid())
				{
					opr5c_message(0x320,HEntity(),string("Player 2 drops a Meganuke."),0);
					item->unknown579c80();
				}
			}
			else
				opr5c_popupMgr->say(0x75,false,"");
		}
	}
}
