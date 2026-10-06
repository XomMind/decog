// op_r5d: item lookup and CMachine/CMachineTarget/CShell consoles in 0x8f9230-0x90c700 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

class OpR5d_ItemType;	// NOTE: placeholder name
class OpR5d_OtherType;	// NOTE: placeholder name

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos, int dx, int dy);	// 0x4099c0
	Pos(const Pos &pos) throw();	// 0x46ca50
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();	// 0x40a6e0
	Rect(int x_, int y_, int width_, int height_) throw();	// 0x456940
	Rect(const Rect &rect);	// 0x40a720
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Pos mouse;
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool isActive();
	virtual void refresh();
	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int modifier);	// NOTE: placeholder name
	virtual void update();
	virtual void render();

	bool isHidden();
	void setHidden(bool hidden);
	XConsole *getParent();	// 0x9b8f00
	int getWidth();	// 0x44b0d0
	Pos localToAbs(Pos pos);
	void deleteSubconsoles();
	void removeSubconsole(XConsole *console);
	void unknown429f10(int a, int b);	// NOTE: placeholder name
	bool input429d00(XEvent *event);	// NOTE: placeholder name (XConsole::input body)
	float getScaleX();
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)
	void unknown417b60(float value);	// NOTE: placeholder name (scale x)
	void unknown417b80(float value);	// NOTE: placeholder name (scale y)

	char pad04[0x60 - 0x04];
};

class OpR5d_Engine	// NOTE: placeholder name (Engine)
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
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);
	bool unknown7ad420();	// NOTE: placeholder name
	void setTitle(class ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)

	int unknown60;
	OpR5d_Engine *engine;
	void *title;
};

class OpR5d_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void unknown44cea0(XConsole *console);	// NOTE: placeholder name
};
extern OpR5d_KeyMap *opR5d_keyMap;	// NOTE: placeholder name (0xcefa8c)

class OpR5d_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	void setPos(const Pos &pos);	// NOTE: placeholder name (0x41a910)
};
extern OpR5d_Mouse *opR5d_mouse;	// NOTE: placeholder name (0xcefa94)

class OpR5d_Stats	// NOTE: placeholder name (object at 0xd2c658)
{
public:
	bool unknown4729d0(unsigned int id, int value, string text, int flag);	// NOTE: placeholder name
};
extern OpR5d_Stats opR5d_stats;	// NOTE: placeholder name (0xd2c658)

class OpR5d_PlayerData	// NOTE: placeholder name (object at 0xcf45d8)
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern OpR5d_PlayerData opR5d_playerData;	// NOTE: placeholder name (0xcf45d8)

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern int opR5d_cefc54;	// NOTE: placeholder name
extern bool opR5d_inputBlocked;	// NOTE: placeholder name (0xcefa5f)
extern bool opR5d_option_d28c8a;	// NOTE: placeholder name

void opW5_showHelp(int topic);	// NOTE: placeholder name (0x490970)
string intToString(int value);

struct OpW2_WeaponRef	// NOTE: placeholder name
{
	int type;
	int index;
	bool flag8;	// NOTE: placeholder name
	bool unknown45b980(int a, int b);	// NOTE: placeholder name
};

class Item	// NOTE: placeholder layout
{
public:
	string getName_571db0(int a, int b);	// NOTE: placeholder name
	int getType_457820();					// NOTE: placeholder name
	int unknown457c80();					// NOTE: placeholder name
	int getAmount_9b6bf0();					// NOTE: placeholder name (folded getter)
	bool unknown4579d0();					// NOTE: placeholder name
	string unknown4579f0();					// NOTE: placeholder name
	bool unknown5776c0();					// NOTE: placeholder name
	bool unknown577700();					// NOTE: placeholder name
	bool unknown577640();					// NOTE: placeholder name
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	HItem() throw();						// 0x9b6590
	Item *operator->() const;				// 0x9b65b0
	bool isNull() const;					// 0x9b65d0
};

class HItemList : public vector<HItem>	// NOTE: placeholder layout
{
};

class Entity	// NOTE: placeholder layout
{
public:
	HItemList *getInventoryList();			// 0x45ab00
	bool unknown5cbec0();					// NOTE: placeholder name
	bool unknown5cc550(vector<int> &list);	// NOTE: placeholder name
	bool unknown5cbf30();					// NOTE: placeholder name
	bool unknown5cbfa0();					// NOTE: placeholder name
	bool unknown5cc010();					// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity() throw();						// 0x9b6590
	Entity *operator->() const throw();		// 0x9b6570
};

struct OpR5d_PropData	// NOTE: placeholder name
{
	char pad00[0x11];
	bool unknown11;	// NOTE: placeholder name
	char pad12[0x18 - 0x12];
	vector<int> unknown18;	// NOTE: placeholder name
	char pad28[0x38 - 0x28];
	int unknown38;	// NOTE: placeholder name
	int unknown3c;	// NOTE: placeholder name
	char pad40[0x80 - 0x40];
	int unknown80;	// NOTE: placeholder name
	int pad84;
	int unknown88;	// NOTE: placeholder name
};

class OpR5d_Prop	// NOTE: placeholder name
{
public:
	OpR5d_PropData *unknown45cb30();	// NOTE: placeholder name (folded getter)
	const Pos &getPosition_4184d0();	// NOTE: placeholder name (folded getter)
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp() throw();						// 0x9b6590
	OpR5d_Prop *operator->() const;			// 0x9b64f0
	bool isValid() const;					// 0x9b7230
};

class Map
{
public:
	HEntity getPlayer() throw();			// 0x4630f0
};

class BS : public Map
{
public:
	int unknown71adc0(HEntity attacker, HProp target, OpW2_WeaponRef *weapon, int type, int index, OpR5d_ItemType *itemType, OpR5d_OtherType *other, HItem item, bool flag);	// NOTE: placeholder name
	bool unknown463b10();	// NOTE: placeholder name
};
extern BS *opR5d_world;	// NOTE: placeholder name (0xcefc4c)

struct OpR5d_Node	// NOTE: placeholder name
{
	int pad0;
	int type;
};

class OpR5d_HNode	// NOTE: placeholder name
{
public:
	int ID;
	OpR5d_Node *operator->() const;	// 0x9b7910
};
extern OpR5d_HNode opR5d_rootNode;	// NOTE: placeholder name (0xd1e888)

class OpR5d_Dijkstra	// NOTE: placeholder name (object at 0xcfe568)
{
public:
	void run(const Pos &start, int range, int *table, int *flag);	// NOTE: placeholder name (0x40ca20)
};
extern OpR5d_Dijkstra opR5d_dijkstra;	// NOTE: placeholder name (0xcfe568)
extern int opR5d_d297a8[];	// NOTE: placeholder name
extern int opR5d_cfd428[];	// NOTE: placeholder name
extern vector<Pos> opR5d_d15e58;	// NOTE: placeholder name (dijkstra result cells)
void clearDijkstraResults();	// 0x4faf40

extern vector<int> opR5d_cf4844;	// NOTE: placeholder name
extern vector<int> opR5d_cf4888;	// NOTE: placeholder name
extern vector<int> opR5d_cf4910;	// NOTE: placeholder name
extern int opR5d_cf4854;	// NOTE: placeholder name
extern int opR5d_cf4898;	// NOTE: placeholder name
extern int opR5d_cf6428;	// NOTE: placeholder name
extern int opR5d_cf4738;	// NOTE: placeholder name
extern bool opR5d_b9b178[][6];	// NOTE: placeholder name
extern int opR5d_d21e48;	// NOTE: placeholder name (Rect at 0xd21e48)
extern int opR5d_d21e4c;	// NOTE: placeholder name
extern int opR5d_d21e50;	// NOTE: placeholder name
extern int opR5d_d21e54;	// NOTE: placeholder name
int minInt(int a, int b);	// 0x9cdb30

extern vector<OpR5d_ItemType *> opR5d_itemTypes;	// NOTE: placeholder name (0xcf4830)

//==================================================================
// item lookup by display name
//==================================================================

string OpR5d_getItemDescription8f9230(HItem item)	// NOTE: placeholder name
{
	string result;
	if (opR5d_itemTypes[item->getType_457820()])
		result = item->getName_571db0(0,0) + " (" + intToString(item->getAmount_9b6bf0()) + "/" + intToString(item->unknown457c80()) + ")";
	else
		result = item->getName_571db0(0,0);
	if (item->unknown4579d0())
	{
		result += " {" + item->unknown4579f0() + "}";
		if (result.size() > 0x30)
			result.erase(result.begin() + 0x30,result.end());
	}
	return result;
}

HItem OpR5d_findItem8f96a0(const string &name)	// NOTE: placeholder name
{
	HItemList *inventory = opR5d_world->getPlayer()->getInventoryList();
	HItem item;
	for (unsigned int i = 0; i < inventory->size(); i++)
	{
		if ((*inventory)[i]->unknown5776c0() && OpR5d_getItemDescription8f9230((*inventory)[i]) == name)
		{
			if (item.isNull() || (*inventory)[i]->unknown577640())
				item = (*inventory)[i];
		}
	}
	return item;
}

string OpR5d_getItemName8f9830(HItem item)	// NOTE: placeholder name
{
	string name = item->getName_571db0(0,0);
	return name;
}

HItem OpR5d_findItem8f98c0(const string &name)	// NOTE: placeholder name
{
	HItemList *inventory = opR5d_world->getPlayer()->getInventoryList();
	for (unsigned int i = 0; i < inventory->size(); i++)
	{
		if ((*inventory)[i]->unknown577700() && OpR5d_getItemName8f9830((*inventory)[i]) == name)
			return (*inventory)[i];
	}
	return HItem();
}

//==================================================================
// CMachineTarget / CMachine
//==================================================================

class OpR5d_Shell : public Console	// NOTE: placeholder name (CShell at 0xcec100)
{
public:
	void unknown939890();	// NOTE: placeholder name
	void unknown90cdf0(int index);	// NOTE: placeholder name
	bool unknown91ca50(HProp prop, OpW2_WeaponRef *record, int type, int index, OpR5d_ItemType *itemType, OpR5d_OtherType *other, HItem item);	// NOTE: placeholder name
};
extern OpR5d_Shell *opR5d_cec100;	// NOTE: placeholder name

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);
	char pad6c[0x8c - 0x6c];
};

class CMachine;
extern CMachine *opR5d_cec0fc;
extern string opR5d_d2d508[];	// NOTE: placeholder name
void opR5d_unknown8f9ee0(int type);	// NOTE: placeholder name	// NOTE: placeholder name (CMachine)
extern Console *opR5d_cec0f8;	// NOTE: placeholder name

class CMachineTarget : public Console
{
public:
	CMachineTarget(XConsole *parent, int y, bool unknown6c_, HProp prop, OpW2_WeaponRef *record_, int key_);
	bool input8fbaa0(XEvent *event);	// NOTE: placeholder name (CMachineTarget vtable slot 4)
	void unknown8fba20();	// NOTE: placeholder name
	void unknown4afab0(int state);	// NOTE: placeholder name (sets unknown7c)
	OpW2_WeaponRef *getRecord_45a760();	// NOTE: placeholder name (folded getter)

	bool unknown6c;	// NOTE: placeholder name
	OpW2_WeaponRef *record;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
	int key;	// NOTE: placeholder name
	int state;	// NOTE: placeholder name
	string label;	// NOTE: placeholder name
};

class CMachine : public Console
{
public:
	CMachine(XConsole *parent, HProp prop_);
	virtual void open();
	virtual void close();
	void unknown8fd5d0();	// NOTE: placeholder name
	void unknown8fd610(int a, int b, HItem c, int d);	// NOTE: placeholder name
	void unknown8fe630();	// NOTE: placeholder name
	void unknown8fe6e0(bool flag);	// NOTE: placeholder name
	void unknown8fe760(int a, int b);	// NOTE: placeholder name
	void unknown8fe7f0(int type);	// NOTE: placeholder name
	void update8fd1e0();	// NOTE: placeholder name (CMachine vtable slot 6)
	bool input8fe920(XEvent *event);	// NOTE: placeholder name (CMachine vtable slot 4)
	void inputAscii8fe9a0(int key, int modifier);	// NOTE: placeholder name (CMachine vtable slot 5)
	HProp getProp_4aeb30();	// NOTE: placeholder name
	OpR5d_ItemType *unknown4afce0();	// NOTE: placeholder name
	OpR5d_OtherType *unknown4afd50();	// NOTE: placeholder name
	HItem getUnknown8c_4afcc0();	// NOTE: placeholder name
	CMachineTarget *getSelected_45ab90();	// NOTE: placeholder name (folded getter)

	unsigned int unknown6c;	// NOTE: placeholder name
	HProp prop;	// NOTE: placeholder name
	bool unknown74;	// NOTE: placeholder name
	vector<CMachineTarget *> targets;	// NOTE: placeholder name
	CMachineTarget *selected;	// NOTE: placeholder name
	HItem unknown8c;	// NOTE: placeholder name
	int unknown90;	// NOTE: placeholder name
	int unknown94;	// NOTE: placeholder name
};

void CMachineTarget::unknown8fba20()
{
	unknown74 = opR5d_world->unknown71adc0(opR5d_world->getPlayer(),opR5d_cec0fc->getProp_4aeb30(),record,0x70,0,opR5d_cec0fc->unknown4afce0(),opR5d_cec0fc->unknown4afd50(),opR5d_cec0fc->getUnknown8c_4afcc0(),0);
}

bool CMachineTarget::input8fbaa0(XEvent *event)
{
	if (isHidden() || opR5d_inputBlocked)
		return false;
	if (input429d00(event))
		return true;
	switch (event->type)
	{
		case 0xf6:
			if (state == 0)
				opR5d_cec0fc->inputAscii(key,0);
			return true;
		case 0xf7:
			if (state == 0)
				opW5_showHelp(record ? record->type + 0xd7 : 0x146);
			return true;
	}
	return false;
}

void CMachine::open()
{
	unknown60 = 1;
	opR5d_keyMap->unknown44cea0(this);
	animate("CMachine_Border");
	animate("CMachine_Content");
	if (prop->unknown45cb30()->unknown11)
		animate("A_CMachine_ZHack");
	unknown417b60(1.0f);
	unknown417b80(1.0f);
}

void CMachine::close()
{
	unknown60 = 4;
	unknown429f10(0,0);
	animate("A_CMachine_HaltStatic");
	engine->stopAll();
	deleteSubconsoles();
	unknown6c = tickCount;
	animate("A_BlockFadeVisSilent");
}

extern CMachine *opR5d_cec088;	// NOTE: placeholder name
extern XConsole *opR5d_cec034;	// NOTE: placeholder name

void CMachine::unknown8fd5d0()
{
	unknown60 = 0;
	opR5d_keyMap->unknown44cea0((XConsole*)opR5d_cec088);
	opR5d_cec034->removeSubconsole(this);
}

void CMachine::unknown8fd610(int a, int b, HItem c, int d)
{
	prop->unknown45cb30()->unknown80 = a;
	prop->unknown45cb30()->unknown88 = b;
	unknown8c = c;
	for (unsigned int i = 0; i < targets.size(); i++)
	{
		if (targets[i]->record->type == d)
		{
			targets[i]->unknown8fba20();
			if (targets[i]->state == 0)
				targets[i]->state = 1;
			targets[i]->unknown4afab0(0);
			break;
		}
	}
}

void CMachine::unknown8fe630()
{
	for (int i = 0; i < (int)targets.size() - 1; i++)
	{
		if (targets[i]->state == 0)
		{
			targets[i]->unknown8fba20();
			if (targets[i]->state == 0)
				targets[i]->state = 1;
			targets[i]->unknown4afab0(0);
		}
	}
}

void CMachine::unknown8fe6e0(bool flag)
{
	if (unknown74)
	{
		opR5d_stats.unknown4729d0(0x2f5,1,"",-1);
		opR5d_playerData.unknown77fbc0(0x51);
		unknown74 = false;
		prop->unknown45cb30()->unknown3c = 0;
		if (!flag)
			unknown8fe630();
	}
}

void CMachine::unknown8fe760(int a, int b)
{
	for (unsigned int i = 0; i < targets.size(); i++)
	{
		if (targets[i]->record && targets[i]->record->unknown45b980(a,b))
		{
			targets[i]->unknown4afab0(2);
		}
	}
}

void CMachine::unknown8fe7f0(int type)
{
	unknown429f10(0,0);
	engine->stopAll();
	deleteSubconsoles();
	targets.clear();
	unknown94 = type;
	switch (unknown94)
	{
		case 0:
		case 1:
			animate("A_CMachine_Lock_1");
			break;
		case 2:
			animate("A_CMachine_Shutdown_1");
			break;
		case 3:
			animate("A_CMachine_Forced_1");
			break;
		case 4:
			animate("A_CMachine_Severed_1");
			break;
		case 6:
			animate("A_CMachine_Crashed_1");
			break;
	}
	unknown90 = 1;
}

bool CMachine::input8fe920(XEvent *event)
{
	if (isHidden() || opR5d_inputBlocked)
		return false;
	if (input429d00(event))
		return true;
	switch (event->type)
	{
		case 0xff:
			if (unknown60 != 4)
				opR5d_cec0f8->close();
			return true;
	}
	return false;
}

void CMachine::update8fd1e0()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
			break;	// NOTE: stray break before the first case (dead jmp in the exe)
		case 1:
			if (!engine->update())
				unknown60 = 3;
			break;
		case 3:
			if (unknown90 == 1)
			{
				if (!engine->update())
				{
					switch (unknown94)
					{
						case 0:
						case 1:
						case 3:
						{
							string anim(unknown94 == 3 ? "A_CMachine_Forced_2_" : "A_CMachine_Lock_2_");
							switch (opR5d_cefc54)
							{
								case 0:
									anim += "Std";
									break;
								case 1:
									anim += "Imp";
									break;
								case 2:
									anim += "RIF";
									break;
								case 3:
									anim += "UFD";
									break;
								case 4:
									anim += "Res";
									break;
								case 5:
									anim += "Pol";
									break;
								case 6:
									anim += "IdM";
									break;
							}
							animate(anim);
							break;
						}
						case 2:
							animate("A_CMachine_Shutdown_2");
							break;
						case 4:
							animate("A_CMachine_Severed_2");
							break;
						case 6:
							animate("A_CMachine_Crashed_2");
							break;
					}
					unknown90 = 2;
				}
			}
			else
				engine->update();
			break;
		case 4:
			engine->update();
			if (getScaleX() != 0.0f)
			{
				if (tickCount - unknown6c >= 500)
				{
					unknown417b60(0.0f);
					unknown417b80(0.0f);
				}
				else
				{
					unknown417b60(1.0 - (tickCount - unknown6c) / 500.0);
					unknown417b80(1.0 - (tickCount - unknown6c) / 500.0);
					break;
				}
			}
			engine->stopAll();
			unknown60 = 0;
			setHidden(true);
			unknown8fd5d0();
			return;
	}
	updateBase429e30();
}

CMachineTarget::CMachineTarget(XConsole *parent, int y, bool unknown6c_, HProp prop, OpW2_WeaponRef *record_, int key_)
	: Console(parent,opR5d_d21e50 - 6,1,3,y,0,false,-1)
	, unknown6c(unknown6c_)
	, record(record_)
	, key(key_)
	, state(0)
{
	if (record)
	{
		if (prop->unknown45cb30()->unknown11)
		{
			state = 1;
		}
		else if (record->flag8 && opR5d_b9b178[record->type][0])
		{
			state = 2;
		}
		else
		{
			switch (record->type)
			{
				case 1:
					if (opR5d_cf4844[record->index])
						state = 1;
					break;
				case 2:
					if (opR5d_cf4888[record->index])
						state = 1;
					break;
				case 3:
					if (opR5d_cf4910[record->index])
						state = 1;
					break;
				case 9:
					if (opR5d_rootNode->type != 0xd)
					{
						Pos pos(prop->getPosition_4184d0());
						clearDijkstraResults();
						int flag = 1;
						opR5d_dijkstra.run(pos,0x18,opR5d_d297a8,&flag);
						if (opR5d_d15e58.empty())
							state = 1;
					}
					break;
				case 18:
					if (!opR5d_cf6428)
						state = 1;
					break;
				case 19:
				case 20:
				case 21:
				{
					Pos pos(prop->getPosition_4184d0());
					clearDijkstraResults();
					int flag = 1;
					opR5d_dijkstra.run(pos,0x18,opR5d_cfd428,&flag);
					if (opR5d_d15e58.empty())
						state = 1;
					break;
				}
				case 66:
					if (opR5d_cf4854 + opR5d_cf4898 == 0)
						state = 1;
					break;
				case 76:
					if (!opR5d_world->getPlayer()->unknown5cbec0())
						state = 1;
					break;
				case 78:
				{
					vector<int> list;
					if (!opR5d_world->getPlayer()->unknown5cc550(list))
						state = 1;
					break;
				}
				case 67:
					if (!opR5d_cec0fc->unknown4afce0() && !opR5d_cec0fc->unknown4afd50())
						state = 1;
					else if (opR5d_cec0fc->getProp_4aeb30()->unknown45cb30()->unknown38)
						state = 2;
					break;
				case 77:
				case 95:
					state = 1;
					break;
				case 81:
					if (!opR5d_world->getPlayer()->unknown5cbf30())
						state = 1;
					break;
				case 94:
					if (!opR5d_world->getPlayer()->unknown5cbfa0())
						state = 1;
					break;
				case 96:
					if (!opR5d_world->getPlayer()->unknown5cc010() || opR5d_world->unknown463b10())
						state = 1;
					break;
			}
		}
	}
	else if (opR5d_cf4738)
	{
		state = 1;
	}
	if (!record || state == 1)
		unknown74 = 0;
	else
		unknown74 = prop.isValid() ? opR5d_world->unknown71adc0(opR5d_world->getPlayer(),prop,record,0x70,0,opR5d_cec0fc->unknown4afce0(),opR5d_cec0fc->unknown4afd50(),HItem(),0) : -1;
	animate("A_CMachineTarget_Delay");
}

CMachine::CMachine(XConsole *parent, HProp prop_)
	: Console(parent,Rect(opR5d_d21e48,opR5d_d21e4c,opR5d_d21e50,opR5d_d21e54 + minInt(prop_->unknown45cb30()->unknown18.size(),0x19) + 1),0,false,0xf)
	, prop(prop_)
	, unknown74(false)
	, selected(NULL)
	, unknown90(0)
	, unknown94(0)
{
	setTitle(new ConsoleTitle(this,"/ T A R G E T /",0,0));
	opR5d_cec0fc = this;
	open();
}

void CMachine::inputAscii8fe9a0(int key, int modifier)
{
	if (!unknown7ad420())
		return;
	switch (modifier)
	{
		case 1:
			key += 0x20;
			for (unsigned int i = 0; i < targets.size(); i++)
			{
				if (targets[i]->key == key && targets[i]->state == 0)
				{
					opR5d_mouse->setPos(Pos(targets[i]->localToAbs(Pos(0,0)),7,0));
					targets[i]->input(&XEvent(0xf7));
					break;
				}
			}
			break;
		case 0:
			for (unsigned int i = 0; i < targets.size(); i++)
			{
				if (targets[i]->key == key)
				{
					if (targets[i]->state == 0)
					{
						if (targets[i]->record == 0)
						{
							opR5d_cec100->unknown939890();
						}
						else if (opR5d_d2d508[targets[i]->record->type].find('@',0) != string::npos)
						{
							selected = targets[i];
							opR5d_unknown8f9ee0(selected->record->type);
						}
						else if (opR5d_cec100->unknown91ca50(prop,targets[i]->record,0x70,-1,0,0,HItem()))
						{
							if (!targets.empty())
								targets[i]->unknown4afab0(2);
						}
					}
					break;
				}
			}
			break;
		case 2:
			if (opR5d_option_d28c8a)
			{
				int number = key - 0x30;
				opR5d_cec100->unknown90cdf0(number);
			}
			break;
	}
}
