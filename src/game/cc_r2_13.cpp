// Info window (CInfo) and its compare variant (CInfoCompare / CInfoCompareData): small accessors
// and constructors around 0x4aeb50-0x4aeff0.
// NOTE: class layouts are partial; padding members, member names and method names are placeholders.
#include "../consoles/console.h"

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool operator==(HEntity other) const;
	bool isValid() const;
};


class HProp	// NOTE: placeholder layout
{
	int	ID;
};
struct Point	// NOTE: placeholder layout
{
	int x;
	int y;
	Point(int value);	// 0x409990
};

class XMouse	// NOTE: placeholder name (global at 0xcefa94)
{
public:
	Pos getPos();	// 0x40a970, NOTE: placeholder name
};
extern XMouse *mouse;	// NOTE: placeholder name

class CInfoEntry : public Console	// NOTE: placeholder name
{
public:
	int getType() { return type; };	// NOTE: placeholder name
	HEntity getHandle();	// 0x4aeb30, NOTE: placeholder name
	bool unknown417440(const Pos &pos);	// NOTE: placeholder name

	int type;	// NOTE: placeholder name
	HEntity handle;	// NOTE: placeholder name
};

class CInfo : public Console
{
public:
	virtual ~CInfo();

	HEntity getUnknown98();	// NOTE: placeholder name
	HEntity getUnknown9c();	// NOTE: placeholder name
	Pos *getUnknownB4();	// NOTE: placeholder name
	Pos *getUnknownBC();	// NOTE: placeholder name
	Pos *getUnknownC4();	// NOTE: placeholder name
	Pos *getUnknownCC();	// NOTE: placeholder name
	Pos *getUnknownD4();	// NOTE: placeholder name
	int getUnknownDC();	// NOTE: placeholder name
	CInfoEntry *unknown4aecc0();	// NOTE: placeholder name
	bool unknown4aed70();	// NOTE: placeholder name
	void unknown4aedc0(CInfoEntry *entry);	// NOTE: placeholder name
	void unknown8b4500(HEntity a, HProp b, HEntity c, Pos *pos, int d, bool e);	// NOTE: placeholder name

	char pad6c[0x84 - 0x6c];
	vector<CInfoEntry *> entries;	// NOTE: placeholder name
	char pad94[0x98 - 0x94];
	HEntity unknown98;	// NOTE: placeholder name
	HEntity unknown9c;	// NOTE: placeholder name
	char padA0[0xac - 0xa0];
	bool unknownAC;	// NOTE: placeholder name
	char padAD[0xb4 - 0xad];
	Pos unknownB4;	// NOTE: placeholder name
	Pos unknownBC;	// NOTE: placeholder name
	Pos unknownC4;	// NOTE: placeholder name
	Pos unknownCC;	// NOTE: placeholder name
	Pos unknownD4;	// NOTE: placeholder name
	int unknownDC;	// NOTE: placeholder name
};

class ItemUI : public CInfo	// NOTE: placeholder name (global at 0xcec11c)
{
public:
	void unknown4aee10(int itemID);	// NOTE: placeholder name
};

class CInfoCompare : public Console
{
public:
	virtual ~CInfoCompare();

	HEntity getTarget();	// NOTE: placeholder name

	HEntity target;	// NOTE: placeholder name
};

extern int unknown_cebf38[];	// NOTE: placeholder name

class CInfoCompareData : public Console
{
public:
	CInfoCompareData(XConsole *parent, int y, string &text, int mode_);	// NOTE: placeholder parameter names
	void unknown4aeff0();	// NOTE: placeholder name
	void unknown48c3c0(int value);	// NOTE: placeholder name

	int mode;	// NOTE: placeholder name
};

CInfo::~CInfo()
{
}

HEntity CInfo::getUnknown98()
{
	return unknown98;
}

HEntity CInfo::getUnknown9c()
{
	return unknown9c;
}

Pos *CInfo::getUnknownB4()
{
	return &unknownB4;
}

Pos *CInfo::getUnknownBC()
{
	return &unknownBC;
}

Pos *CInfo::getUnknownC4()
{
	return &unknownC4;
}

Pos *CInfo::getUnknownCC()
{
	return &unknownCC;
}

Pos *CInfo::getUnknownD4()
{
	return &unknownD4;
}

int CInfo::getUnknownDC()
{
	return unknownDC;
}

CInfoEntry *CInfo::unknown4aecc0()
{
	Pos pos = mouse->getPos();
	for (unsigned int i = 0; i < entries.size(); i++)
	{
		if (entries[i]->getHandle().isValid() && entries[i]->unknown417440(pos))
			return entries[i];
	}
	return NULL;
}

bool CInfo::unknown4aed70()
{
	return unknownAC && unknown98.isValid();
}

void CInfo::unknown4aedc0(CInfoEntry *entry)
{
	if (entry->getType() != 0x192 || entry->getHandle().isValid())
		entries.push_back(entry);
}

void ItemUI::unknown4aee10(int itemID)
{
	if (!isHidden() && unknown9c == *(HEntity *)&itemID)
		unknown8b4500(HEntity(),*(HProp *)&itemID,HEntity(),(Pos *)&Point(-1),0,false);
}

CInfoCompare::~CInfoCompare()
{
}

HEntity CInfoCompare::getTarget()
{
	return target;
}

CInfoCompareData::CInfoCompareData(XConsole *parent, int y, string &text, int mode_)
	: Console(parent,10,1,2,y,0,false,-1)
	, mode (mode_)
{
	if (mode == 2)
	{
		text.insert(text.begin(),1,'(');
		text += ")";
	}
	printAligned(getWidth() - 2,0,2,text);
}

void CInfoCompareData::unknown4aeff0()
{
	unknown48c3c0(unknown_cebf38[mode]);
}
