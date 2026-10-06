// Prop/Cell/trap-state small methods (0x45ce80-0x45d5f8).
// NOTE: class layouts are partial; padding members and names are placeholders
//	unless already bound by matched callers.
#include <string>
#include <vector>
using namespace std;

class HProp
{
	int	ID;
public:
	HProp();
	bool isValid() const;
	bool isNull() const;
	class Prop *operator->() const;
};

class HEntity
{
	int	ID;
public:
	HEntity();
};

class HItem
{
	int	ID;
public:
	HItem();
};

struct PropData	// NOTE: placeholder name; partial record
{
	char	unknown00[0x5c];
	bool	unknown5c;		// NOTE: placeholder name
	char	unknown5d[7];
	int		unknown64;		// NOTE: placeholder name
	char	unknown68[0x5c];
	bool	unknownc4;		// NOTE: placeholder name
	char	unknownc5[0x7b];
	int		unknown140;		// NOTE: placeholder name
};

class Prop
{
public:
	void unknown45ce80(int value, bool flag);	// NOTE: placeholder name
	void unknown45ceb0(int value, bool flag);	// NOTE: placeholder name
	bool unknown470b30();						// NOTE: placeholder name
	bool unknown45c610();						// NOTE: placeholder name
	PropData *getData();						// NOTE: placeholder name (0x9b8f00)
	void unknown65f520(int a, int b, int c, int d, int e, int f, int g, int h, int i);	// NOTE: placeholder name
};

struct Point
{
	int x;
	int y;
};

struct CellEffect;

struct CellTerrainRecord	// NOTE: partial record
{
	int		ID;
	string	unknown04;		// NOTE: placeholder name
	string	unknown20;		// NOTE: placeholder name
	int		unknown3c;
	int		unknown40;
	string	unknown44;		// NOTE: placeholder name
};

template <class T> void deleteVector(vector<T*> &v) throw();	// NOTE: placeholder name (0x9d0670 for this instance)

class Cell
{
public:
	~Cell();
	int unknown45d0e0();				// NOTE: placeholder name
	string &unknown45d100();			// NOTE: placeholder name
	string &unknown45d120();			// NOTE: placeholder name
	string &unknown45d140();			// NOTE: placeholder name
	string &unknown45d180();			// NOTE: placeholder name
	Point &unknown45d1a0();			// NOTE: placeholder name (position)
	int unknown45d1c0();				// NOTE: placeholder name
	bool unknown45d1e0();				// NOTE: placeholder name
	bool unknown45d230();				// NOTE: placeholder name
	bool unknown45d270();				// NOTE: placeholder name
	bool unknown45d2d0();				// NOTE: placeholder name
	bool unknown45d310();				// NOTE: placeholder name
	bool unknown45d330();				// NOTE: placeholder name
	int unknown45d430();				// NOTE: placeholder name
	bool unknown45d480();				// NOTE: placeholder name
	bool unknown45d4e0();				// NOTE: placeholder name
	bool unknown45d500();				// NOTE: placeholder name
	bool fitsProp(void *propData);		// NOTE: placeholder name (bound by matched callers)
	bool isMachinePart();				// NOTE: placeholder name (0x45dcd0)
	bool unknown45db70();				// NOTE: placeholder name
	bool unknown45db90();				// NOTE: placeholder name

	CellTerrainRecord	*terrain;			// +0x00
	char				unknown04[8];
	int					unknown0c;			// +0x0c, -1 = none
	char				unknown10[4];
	string				name;				// +0x14
	Point				position;			// +0x30
	bool				open;				// +0x38
	bool				blocked;			// +0x39
	bool				unknown3a;			// +0x3a NOTE: placeholder name
	char				unknown3b;
	int					caveinInstability;	// +0x3c
	int					unknown40;			// +0x40 NOTE: placeholder name
	HProp				prop;				// +0x44
	HEntity				entity;				// +0x48
	vector<HItem>		items;				// +0x4c
	vector<CellEffect *>	effects;		// +0x5c
};

class UnknownRecordList45c	// NOTE: placeholder name
{
public:
	~UnknownRecordList45c();				// 0x458720 scalar deleting dtor
	bool unknown4567f0(int ID, bool flag);	// NOTE: placeholder name

	vector<int> list;
};

struct UnknownEntry45c;	// NOTE: placeholder name

class UnknownPart45c060	// NOTE: placeholder name
{
public:
	~UnknownPart45c060();	// 0x45c060; 0x45cfd0 scalar deleting dtor
};

class UnknownHolder45cee0	// NOTE: placeholder name
{
public:
	~UnknownHolder45cee0();	// 0x45c4a0
	void unknown45cee0(UnknownEntry45c *entry);			// NOTE: placeholder name
	void unknown45cf00(UnknownEntry45c *entry);			// NOTE: placeholder name
	void unknown45cf60(int ID, bool flag);	// NOTE: placeholder name

	char					unknown00[0x20];
	vector<UnknownEntry45c *>	list;	// +0x20
	UnknownRecordList45c	*records;	// +0x30
	char					unknown34[0x10];
	UnknownPart45c060		*part;		// +0x44
	char					unknown48[4];
	char					*buffer;	// +0x4c
};

template <class T> void eraseAt(vector<T> &v, unsigned int index);	// NOTE: placeholder name (0x9d8f20)

class BattleState	// NOTE: placeholder layout
{
public:
	virtual ~BattleState();
	virtual int getType();			// NOTE: placeholder name
	virtual void update();			// NOTE: placeholder name
	virtual void unknown3() = 0;	// NOTE: placeholder name
};

extern int unknown_ce9ff0;

class STrapTrigger : public BattleState
{
public:
	~STrapTrigger();
	virtual int getType();
	virtual void update();
};

UnknownHolder45cee0::~UnknownHolder45cee0()
{
	deleteVector(list);
	delete records;
	delete part;
	delete buffer;
}

void Prop::unknown45ce80(int value, bool flag)
{
	unknown65f520(0, 1, 1, 0, 5, value, 1, 0, flag);
}

void Prop::unknown45ceb0(int value, bool flag)
{
	unknown65f520(0, 4, 1, 0, 0, value, flag, 0, 0);
}

void UnknownHolder45cee0::unknown45cee0(UnknownEntry45c *entry)
{
	list.push_back(entry);
}

void UnknownHolder45cee0::unknown45cf00(UnknownEntry45c *entry)
{
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (list[i] == entry)
		{
			eraseAt(list, i);
			return;
		}
	}
}

void UnknownHolder45cee0::unknown45cf60(int ID, bool flag)
{
	if (records && records->unknown4567f0(ID, flag))
	{
		delete records;
		records = NULL;
	}
}

STrapTrigger::~STrapTrigger()
{
}

int STrapTrigger::getType()
{
	return unknown_ce9ff0;
}

bool Cell::fitsProp(void *propData)
{
	return prop.isNull() && !isMachinePart() &&
		((open && !unknown45db70()) || (propData != NULL && ((PropData *)propData)->unknown5c && ((PropData *)propData)->unknownc4 && ((PropData *)propData)->unknown140 == 16));
}

Cell::~Cell()
{
	deleteVector(effects);
}

int Cell::unknown45d0e0()
{
	return terrain->ID;
}

string &Cell::unknown45d100()
{
	return terrain->unknown04;
}

string &Cell::unknown45d120()
{
	return terrain->unknown20;
}

string &Cell::unknown45d140()
{
	return name.empty() ? terrain->unknown20 : name;
}

string &Cell::unknown45d180()
{
	return terrain->unknown44;
}

Point &Cell::unknown45d1a0()
{
	return position;
}

int Cell::unknown45d1c0()
{
	return *(int *)((char *)terrain + 0x4c);
}

bool Cell::unknown45d1e0()
{
	return prop.isValid() && !prop->unknown470b30();
}

bool Cell::unknown45d230()
{
	return unknown0c != -1;
}

bool Cell::unknown45d270()
{
	return unknown3a && (prop.isNull() || prop->unknown45c610());
}

bool Cell::unknown45d2d0()
{
	return unknown3a && !open;
}

bool Cell::unknown45d310()
{
	return *((bool *)terrain + 0x7c);
}

bool Cell::unknown45d330()
{
	return *((bool *)terrain + 0x7d);
}

int Cell::unknown45d430()
{
	return (unknown45db70() && unknown45db90()) ? 0 : *(int *)((char *)terrain + 0x54);
}

bool Cell::unknown45d480()
{
	return !unknown3a || (prop.isValid() && prop->getData()->unknown64 == 4);
}

bool Cell::unknown45d4e0()
{
	return !unknown3a;
}

bool Cell::unknown45d500()
{
	return prop.isValid() && prop->getData()->unknown64 == 4;
}
