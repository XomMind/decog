// op_r5c: CParts console methods and neighbours (0x894e20-0x8f9230), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
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

	Pos(int x_, int y_) throw();
	Pos(int v) throw();	// 0x409990
	Pos(const Pos &pos);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(int x_, int y_, int width_, int height_) throw();	// 0x456940
	Rect(const Rect &rect);
};

class OpR5c_Engine;

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);	// NOTE: placeholder name
	virtual void update();
	virtual void render();	// NOTE: placeholder name

	vector<XConsole*> *getSubconsoles();	// NOTE: placeholder name
	void setPos(const Pos &pos);
	void setChar_417f50(int x, int y, int ch);	// NOTE: placeholder name
	int getHeight() throw();
	void removeSubconsole(XConsole *console);
	bool contains(const Pos &pos);
	Pos getPos() throw();

	char pad04[0x60 - 0x04];
	int unknown60;
	OpR5c_Engine *engine;
};

class ConsoleTitle;

class OpR5c_Engine	// NOTE: placeholder name
{
public:
	bool unknown50fbf0(int index, const Pos &pos);	// NOTE: placeholder name
	void stopAll();	// NOTE: placeholder name (0x50ff30)
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void resize(int width, int height);
	void animate(string name);
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);	// NOTE: placeholder name

	ConsoleTitle *title;
};

extern unsigned int opr5c_tickCount;	// NOTE: placeholder name (0xcaed20)

void opr5c_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)
bool isBetween(int low, int value, int high);

class OpR5c_Item;
class OpR5c_Entity;

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
	bool isNull() const;
	OpR5c_Entity *operator->() const;	// 0x9b6570
	bool operator==(HEntity other) const;
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
	bool isNull() const;
	OpR5c_Item *operator->() const;	// 0x9b65b0
	bool operator==(HItem other) const;	// 0x9b78e0
};

struct OpR5c_ItemData	// NOTE: placeholder name
{
	char pad00[0x128];
	int unknown128;	// NOTE: placeholder name
	char pad12c[0x1a0 - 0x12c];
	struct OpR5c_ItemSub *unknown1a0;	// NOTE: placeholder name
	char pad1a4[0x1b0 - 0x1a4];
	bool unknown1b0;	// NOTE: placeholder name
};

struct OpR5c_ItemSub	// NOTE: placeholder name
{
	char pad00[0x2c];
	int unknown2c;	// NOTE: placeholder name
};

class OpR5c_Item	// NOTE: placeholder name (Item)
{
public:
	int getField457820();	// NOTE: placeholder name (folded getter)
	int getField4578a0();	// NOTE: placeholder name (folded getter)
	int getField457880();	// NOTE: placeholder name (folded getter)
	int unknown457f90();	// NOTE: placeholder name
	int unknown457fd0();	// NOTE: placeholder name
	OpR5c_ItemData *getData();	// NOTE: placeholder name (folded +8 getter)
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
	int getField44ab90();	// NOTE: placeholder name (folded getter)
	bool unknown4578e0();	// NOTE: placeholder name
	void unknown451400(int value);	// NOTE: placeholder name (ICF'd trivial setter)
	int getField4578c0();	// NOTE: placeholder name (folded getter)
};

class OpR5c_Entity	// NOTE: placeholder name (Entity)
{
public:
	int unknown5dc440(HItem item);	// NOTE: placeholder name
	void unknown64da50(HItem item);	// NOTE: placeholder name
};

class OpR5c_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer();	// NOTE: placeholder name (0x4630f0)
	int getTurn();	// NOTE: placeholder name (0x464270)
};
extern OpR5c_World *opr5c_world;	// NOTE: placeholder name

class OpR5c_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	Pos getPos_40a970();	// NOTE: placeholder name
};
extern OpR5c_Mouse *opr5c_mouse;	// NOTE: placeholder name

class OpR5c_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void setTarget_44cea0(Console *target);	// NOTE: placeholder name (folded setter)
};
extern OpR5c_KeyMap *opr5c_keyMap;	// NOTE: placeholder name

class OpR5c_PartManage	// NOTE: placeholder name (CPartmanage at 0xcec098)
{
public:
	int getField4ab670();	// NOTE: placeholder name (folded getter)
};
extern OpR5c_PartManage *opr5c_partManage;	// NOTE: placeholder name

class OpR5c_PartRemove	// NOTE: placeholder name (CPartremove at 0xcec094)
{
public:
	bool getField4ab570();	// NOTE: placeholder name (folded getter)
};
extern OpR5c_PartRemove *opr5c_partRemove;	// NOTE: placeholder name

class CInventory
{
public:
	void unknown8a5680();
};
extern CInventory *inventory;	// 0xcec08c

class OpR5c_PartsRows : public Console	// NOTE: placeholder name
{
public:
	void refreshRows();	// NOTE: placeholder name (0x4a2f80)
};

class CModeReport : public Console
{
public:
	CModeReport(XConsole *parent, const Rect &rect, string text);

	char pad6c[0x70 - 0x6c];
};

class CPartAnimation : public Console
{
public:
	CPartAnimation(XConsole *parent, const string &name, bool multislot, int key, int type);	// 0x4a8330
};

void opr5c_findAnimation(const string &name, int *index);	// NOTE: placeholder name (0x9d45a0)
class CPart;
void opr5c_moveElement(vector<CPart*> &v, unsigned int from, unsigned int to);	// NOTE: placeholder name (0x9e2ce0)
void opr5c_eraseRange(vector<CPart*> &v, int first, int last);	// NOTE: placeholder name (0x9e25a0)
void opr5c_insertAt(vector<CPart*> &v, int index, CPart *value);	// NOTE: placeholder name (0x9dbdc0)
void opr5c_removeAt(vector<CPart*> &v, int index);	// NOTE: placeholder name (0x9de6f0)
bool unknown4328a0();	// NOTE: placeholder name
extern int opr5c_partsMode;	// NOTE: placeholder name (0xd28d68)
extern string gameStrings_d30828[];
extern string gameStrings_d1e368[];

//==================================================================
// CParts
//==================================================================

class CPart : public Console
{
public:
	CPart(XConsole *parent, int y, HItem item_, bool unknown70_, HItem unknown74_, int unknown7c_, int key_);	// 0x4a8bd0
	void unknown4a8f90(bool flag);	// NOTE: placeholder name
	void unknown4a9120();	// NOTE: placeholder name
	void unknown4a9210(HItem value);	// NOTE: placeholder name (stores the linked item at +0x74)
	void unknown890710(int value);	// NOTE: placeholder name
	void unknown49ac50();	// NOTE: placeholder name

	HItem item;
	bool unknown70;	// NOTE: placeholder name
	char pad71[0x74 - 0x71];
	HItem unknown74;	// NOTE: placeholder name
	char pad78[0x7c - 0x78];
	int unknown7c;	// NOTE: placeholder name
	int key;	// NOTE: placeholder name
	char pad84[0x88 - 0x84];
	bool unknown88;	// NOTE: placeholder name
	char pad89[0xa4 - 0x89];
};

class CParts : public Console
{
public:
	virtual ~CParts();	// 0x4a9950
	virtual void close();	// 0x894e20
	CPart *unknown894e70(HItem item);	// NOTE: placeholder name
	CPart *unknown894ee0();	// NOTE: placeholder name
	bool unknown894f70();	// NOTE: placeholder name
	void unknown897290(HItem item, int key);	// NOTE: placeholder name
	void unknown89adf0(CPart *part);	// NOTE: placeholder name
	void unknown4a9c90(CPart *part);	// NOTE: placeholder name
	void unknown89d610(HItem item, int type);	// NOTE: placeholder name
	bool unknown89d780();	// NOTE: placeholder name
	void unknown8968b0(int mode);	// NOTE: placeholder name
	void unknown4a9bb0();	// NOTE: placeholder name
	void unknown8966a0();	// NOTE: placeholder name
	void unknown896820(HItem item);	// NOTE: placeholder name
	CPart *unknown896a80(HItem item);	// NOTE: placeholder name
	void unknown896ab0(int type);	// NOTE: placeholder name
	void unknown896b40();	// NOTE: placeholder name
	bool unknown896b90(HItem item, unsigned int index, int key);	// NOTE: placeholder name
	bool unknown896c20(int type);	// NOTE: placeholder name
	void unknown896cc0();	// NOTE: placeholder name
	void unknown896d80();	// NOTE: placeholder name
	void unknown896e20();	// NOTE: placeholder name
	void unknown896ee0();	// NOTE: placeholder name
	void unknown896fa0();	// NOTE: placeholder name
	void unknown897040();	// NOTE: placeholder name
	void unknown8970d0();	// NOTE: placeholder name
	void unknown897160(int type);	// NOTE: placeholder name
	int unknown8982e0(CPart *part);	// NOTE: placeholder name
	int unknown898350(CPart *part);	// NOTE: placeholder name
	int unknown8983e0(HItem item);	// NOTE: placeholder name
	int unknown898470(int value);	// NOTE: placeholder name
	bool unknown8984f0(int value);	// NOTE: placeholder name
	int unknown8985d0(int value);	// NOTE: placeholder name
	int unknown8986c0(int value);	// NOTE: placeholder name
	void unknown8987b0(HItem item, vector<HItem> *out);	// NOTE: placeholder name
	void unknown898860(HItem item, vector<HItem> *list);	// NOTE: placeholder name

	char pad6c[0x70 - 0x6c];
	unsigned int unknown70;	// NOTE: placeholder name
	vector<CPart*> parts;	// NOTE: placeholder name
	OpR5c_PartsRows *partsRows;	// NOTE: placeholder name
	char pad88[0xac - 0x88];
	int unknownAC;	// NOTE: placeholder name
	char padB0[0xb8 - 0xb0];
	unsigned int unknownB8;	// NOTE: placeholder name
	CModeReport *modeReport;	// NOTE: placeholder name
	char padC0[0x104 - 0xc0];
	int unknown104;	// NOTE: placeholder name
	vector<vector<Pos> > unknown108;	// NOTE: placeholder name
};

void CParts::close()
{
	unknown60 = 4;
	unknown70 = opr5c_tickCount;
	animate("A_BlockFadeInterior");
	opr5c_keyMap->setTarget_44cea0(NULL);
}

CPart *CParts::unknown894e70(HItem item)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item == item)
			return parts[i];
	}
	return NULL;
}

CPart *CParts::unknown894ee0()
{
	Pos pos = opr5c_mouse->getPos_40a970();
	if (!contains(pos))
		return NULL;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->contains(pos))
			return parts[i];
	}
	return NULL;
}

bool CParts::unknown894f70()
{
	switch (opr5c_partManage->getField4ab670())
	{
	case 5:
		return false;
	case 6:
		return true;
	}
	if (unknownB8 == 0)
		return false;
	if (opr5c_tickCount > unknownB8 + 5000)
	{
		if (opr5c_partRemove->getField4ab570())
			unknownB8 = opr5c_tickCount;
		else
		{
			unknownB8 = 0;
			return false;
		}
	}
	return unknownB8 + 5000 >= opr5c_tickCount;
}

void CParts::unknown8966a0()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item.isValid() && !parts[i]->unknown70 && parts[i]->unknown88 && parts[i]->item->getField44ab90() <= opr5c_world->getTurn())
		{
			if (parts[i]->item->getField4578a0() == 0)
			{
				HEntity player = opr5c_world->getPlayer();
				HItem item = parts[i]->item;
				if (!player->unknown5dc440(item))
					player->unknown64da50(item);
				opr5c_playSound(0x23,0,0);
			}
			else
				opr5c_playSound(0x25,0,0);
			parts[i]->unknown890710(1);
		}
	}
}

void CParts::unknown896820(HItem item)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item == item && parts[i]->unknown70)
			parts[i]->unknown4a9120();
	}
}

CPart *CParts::unknown896a80(HItem item)
{
	CPart *part = unknown894e70(item);
	if (part)
		part->unknown4a9120();
	return part;
}

void CParts::unknown896ab0(int type)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item.isValid() && parts[i]->item->getField457820() == type)
			parts[i]->unknown4a9120();
	}
}

void CParts::unknown896b40()
{
	for (unsigned int i = 0; i < parts.size(); i++)
		parts[i]->unknown4a8f90(false);
}

bool CParts::unknown896b90(HItem item, unsigned int index, int key)
{
	return parts[index]->item.isNull() && parts[index]->unknown7c == item->getField4578a0() && (key == 0x20 || parts[index]->key == key);
}

bool CParts::unknown896c20(int type)
{
	bool found = false;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item.isValid() && parts[i]->item->getField457820() == type)
		{
			parts[i]->unknown4a8f90(false);
			found = true;
		}
	}
	return found;
}

void CParts::unknown896cc0()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item.isValid() && parts[i]->item->unknown457f90() == 1 && parts[i]->item->unknown457fd0())
			parts[i]->unknown4a8f90(false);
	}
}

void CParts::unknown896d80()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item.isValid() && parts[i]->item->getData()->unknown1b0)
			parts[i]->unknown4a8f90(false);
	}
}

void CParts::unknown896e20()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item.isValid() && (parts[i]->item->getField457880() == 0x14 || parts[i]->item->getField457880() == 0x15))
			parts[i]->unknown4a8f90(false);
	}
}

void CParts::unknown896ee0()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item.isValid() && (parts[i]->item->getField457880() == 0x16 || parts[i]->item->getField457880() == 0x17))
			parts[i]->unknown4a8f90(false);
	}
}

void CParts::unknown896fa0()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item.isValid() && isBetween(0x1a,parts[i]->item->getField457880(),0x1c))
			parts[i]->unknown4a8f90(false);
	}
}

void CParts::unknown897040()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item.isValid() && parts[i]->item->getField457880() >= 0x1a)
			parts[i]->unknown4a8f90(true);
	}
}

void CParts::unknown8970d0()
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item.isValid() && parts[i]->item->unknown457f90() == 0xc9)
			parts[i]->unknown4a8f90(true);
	}
}

void CParts::unknown897160(int type)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item.isValid() && parts[i]->item->getField4578a0() == 3 && ((type == 0x17 && parts[i]->item->getData()->unknown1a0 && parts[i]->item->getData()->unknown1a0->unknown2c == 2) || parts[i]->item->getData()->unknown128 == type - 0x15))
			parts[i]->unknown4a8f90(false);
	}
}

int CParts::unknown8982e0(CPart *part)
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown74 == part->item)
			count++;
	}
	return count;
}

int CParts::unknown898350(CPart *part)
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown74.isValid() && parts[i]->item == part->item)
			count++;
	}
	return count;
}

int CParts::unknown8983e0(HItem item)
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown74.isValid() && parts[i]->item == item)
			count++;
	}
	return count;
}

int CParts::unknown898470(int value)
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown74.isValid() && parts[i]->unknown7c == value)
			count++;
	}
	return count;
}

bool CParts::unknown8984f0(int value)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown7c == value)
		{
			for (unsigned int j = i; j < parts.size(); j++)
			{
				if (parts[j]->unknown7c != value)
					break;
				if (parts[j]->unknown74.isValid() && parts[j]->item.isNull())
					return true;
			}
			break;
		}
	}
	return false;
}

int CParts::unknown8985d0(int value)
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown7c == value)
		{
			for (unsigned int j = i; j < parts.size(); j++)
			{
				if (parts[j]->unknown7c != value)
					break;
				if (parts[j]->unknown74.isValid() && parts[j]->item.isNull())
					count++;
			}
			break;
		}
	}
	return count;
}

int CParts::unknown8986c0(int value)
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown7c == value)
		{
			for (unsigned int j = i; j < parts.size(); j++)
			{
				if (parts[j]->unknown7c != value)
					break;
				if (parts[j]->item.isNull() && parts[j]->unknown74.isNull())
					count++;
			}
			break;
		}
	}
	return count;
}

void CParts::unknown8987b0(HItem item, vector<HItem> *out)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item == item && parts[i]->unknown74.isValid())
		{
			out->push_back(parts[i]->unknown74);
			parts[i]->unknown49ac50();
		}
	}
}

void CParts::unknown898860(HItem item, vector<HItem> *list)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item == item)
		{
			parts[i]->unknown4a9210(list->front());
			list->erase(list->begin());
			if (list->empty())
				break;
		}
	}
}

void CParts::unknown8968b0(int mode)
{
	if (mode == 0 && opr5c_partsMode == 0)
		mode = 4;
	else if (mode == 1 && opr5c_partsMode == 1)
		mode = 5;
	else if (mode == 2 && opr5c_partsMode == 2)
		mode = 6;
	else if (mode == 3 && opr5c_partsMode == 3)
		mode = 7;
	if (opr5c_partsMode != mode)
	{
		opr5c_partsMode = mode;
		unknown896b40();
		inventory->unknown8a5680();
		partsRows->refreshRows();
		opr5c_playSound(0x29,0,0);
		unknown4a9bb0();
		string *names = unknown4328a0() ? gameStrings_d30828 : gameStrings_d1e368;
		modeReport = new CModeReport(this,Rect(partsRows->getPos().x - 1 - names[opr5c_partsMode].size(),getHeight() - 1,names[opr5c_partsMode].size(),1),names[opr5c_partsMode]);
	}
}

void CParts::unknown89d610(HItem item, int type)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item == item)
			new CPartAnimation(parts[i],item->getName(0,0),parts[i]->unknown70,parts[i]->key,type);
	}
}

bool CParts::unknown89d780()
{
	if (unknown104)
	{
		int index;
		opr5c_findAnimation("CPart_Sort_Ascii",&index);
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			parts[i]->setPos(unknown108[i].back());
			for (unsigned int j = 0; j < parts[i]->getSubconsoles()->size(); j++)
			{
				if ((*parts[i]->getSubconsoles())[j]->engine->unknown50fbf0(index,Pos(0)))
					(*parts[i]->getSubconsoles())[j]->engine->stopAll();
			}
		}
		unknown104 = 0;
		return true;
	}
	else
		return false;
}

void CParts::unknown897290(HItem item, int key)
{
	if (key == 0x20 && unknown8984f0(item->getField4578a0()))
	{
		vector<CPart*> chain;
		unsigned int from;
		for (from = 0; from < parts.size(); from++)
		{
			if (parts[from]->unknown7c == item->getField4578a0())
			{
				for (unsigned int j = from; j < parts.size(); j++)
				{
					if (parts[j]->unknown7c != item->getField4578a0())
						break;
					chain.push_back(parts[j]);
				}
				break;
			}
		}
		for (int k = chain.size() - 1; k >= 0; k--)
		{
			if (chain[k]->unknown74.isValid() && chain[k]->item.isNull())
				opr5c_moveElement(chain,k,chain.size() - 1);
		}
		Pos at = parts[from]->getPos();
		int keyChar = parts[from]->key;
		for (unsigned int m = 0; m < chain.size(); m++)
		{
			chain[m]->key = keyChar;
			chain[m]->setChar_417f50(1,0,keyChar - 0x20);
			chain[m]->setPos(at);
			keyChar++;
			at.y++;
		}
		opr5c_eraseRange(parts,from,from + chain.size() - 1);
		for (int n = chain.size() - 1; n >= 0; n--)
			opr5c_insertAt(parts,from,chain[n]);
	}
	for (unsigned int index = 0; index < parts.size(); index++)
	{
		if (unknown896b90(item,index,key))
		{
			if (item->unknown4578e0())
			{
				int slots = 1;
				for (unsigned int next = index + 1; next < parts.size(); next++)
				{
					if (unknown896b90(item,next,0x20))
						slots++;
					else
						break;
				}
				if (slots < item->getField4578c0())
				{
					unsigned int first;
					for (first = 0; first < parts.size(); first++)
					{
						if (parts[first]->unknown7c == item->getField4578a0())
							break;
					}
					for (unsigned int a = first; a < parts.size(); a++)
					{
						if (parts[a]->unknown7c != item->getField4578a0())
							break;
						if (parts[a]->item.isNull())
						{
							for (unsigned int b = a + 1; b < parts.size(); b++)
							{
								if (parts[b]->item.isValid())
								{
									if (parts[b]->unknown7c != item->getField4578a0())
										break;
									unknown4a9c90(parts[b]);
									unknown89adf0(parts[a]);
									break;
								}
							}
						}
					}
					for (unsigned int c = first; c < parts.size(); c++)
					{
						if (parts[c]->item.isNull())
						{
							index = c;
							break;
						}
					}
				}
			}
			for (int s = 0; s < item->getField4578c0(); s++)
			{
				opr5c_insertAt(parts,index + s,new CPart(this,parts[index + s]->getPos().y,item,s > 0,parts[index + s]->unknown74,parts[index + s]->unknown7c,parts[index + s]->key));
				parts[index + s]->unknown890710(0);
				if (parts[index + s + 1])
				{
					removeSubconsole(parts[index + s + 1]);
					parts[index + s + 1] = NULL;
				}
				opr5c_removeAt(parts,index + s + 1);
			}
			if (opr5c_partsMode == 0 || opr5c_partsMode == 4)
				unknown896b40();
			item->unknown451400(-2);
			return;
		}
	}
}
