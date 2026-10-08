// team_d_96: Item member 0x578090 (called from Entity::turnUpdate): advances an item's two-stage activation
// state (sounds, messages, stats, part UI refresh).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;
};

class HProp
{
public:
	int ID;
	HProp();
};

class Entity;

class HEntity
{
public:
	int ID;
	bool isValid() const;	// NOTE: folded with HItem::isValid
	Entity *operator->() const;
};

class Entity
{
public:
	int unknown5cb220();				// NOTE: placeholder name
	int getTarget();
	int unknown5cad50();				// NOTE: placeholder name
	Point &getPosition();
	bool isPlayer();
	bool isHostileTo(HEntity e);
};

struct ItemData96	// NOTE: placeholder name and layout
{
	char	pad000[0xec];
	int		mode;	// +0xec
};

struct Effect96	// NOTE: placeholder name and layout
{
	int		unknown00;
	int		state;	// +0x04
};

class Map
{
public:
	HEntity getPlayer();
};
extern Map *world96_cefc4c;	// NOTE: placeholder name

class CMap
{
public:
	void unknown807f70(HEntity e, int mode);	// NOTE: placeholder name
};
extern CMap *cmap96_cec054;	// NOTE: placeholder name

class CParts
{
public:
	void unknown896b40();	// NOTE: placeholder name
};
extern CParts *parts96_cec088;	// NOTE: placeholder name

class ItemUI
{
public:
	void unknown4aee10(int id);	// NOTE: placeholder name
};
extern ItemUI *itemUI96_cec11c;	// NOTE: placeholder name

class OpR1h_Stats
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);
};
extern OpR1h_Stats stats96_d2c658;	// NOTE: placeholder name
extern vector< vector<int> * > statLists96_d2c65c;	// NOTE: placeholder name

class PlayerData
{
public:
	void unknown77fbc0(int id);			// NOTE: placeholder name
	bool isSlotEmpty(unsigned int index);	// NOTE: placeholder name (Unknown46d8b0::isSlotEmpty)
};
extern PlayerData playerData96_cf45d8;	// NOTE: placeholder name

class ConsoleA96	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA96 *consoleA96_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs96_cec0b4;	// NOTE: placeholder name

bool showMessage96(int id, const string *text, const string *b, int c, HEntity d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)
int opR1d_454260(const Point &p, int id);	// NOTE: placeholder name
extern bool flags96_ba0968[];	// NOTE: placeholder name
extern int modes96_ba0970[];	// NOTE: placeholder name
extern string names96_d25f78[];	// NOTE: placeholder name
extern int uiMode96_d28d68;	// NOTE: placeholder name

class Item	// NOTE: placeholder layout
{
public:
	int			unknown00;
	int			unknown04;	// +0x04
	ItemData96	*data;		// +0x08
	char		pad0c[4];
	HEntity		owner;		// +0x10
	char		pad14[0x44 - 0x14];
	int			unknown44;	// +0x44 (stage)

	int unknown577fb0();			// NOTE: placeholder name (Calls_577fb0::delegate)
	void reset578800();						// NOTE: placeholder name
	Effect96 *getEffect(int type);
	void unknown458630(Effect96 *effect);	// NOTE: placeholder name
	void unknown578090();					// NOTE: placeholder name
};

void Item::unknown578090()
{
	int duration = flags96_ba0968[data->mode] ? (owner.isValid() ? owner->unknown5cb220() : modes96_ba0970[data->mode]) : modes96_ba0970[data->mode];
	switch (unknown577fb0())
	{
	case 1:
		if (owner.isValid() && owner->getTarget())
		{
			reset578800();
			break;
		}
		unknown44++;
		if (unknown44 == duration + 1)
		{
			if (owner.isValid() && owner->unknown5cad50() != 2)
			{
				switch (data->mode)
				{
				case 1:
				case 2:
					opR1d_454260(owner->getPosition(),0xe9);
					break;
				case 3:
					opR1d_454260(owner->getPosition(),0xeb);
					break;
				case 4:
					opR1d_454260(owner->getPosition(),0xed);
					break;
				}
				if (owner->isPlayer())
				{
					do
					{
						if (showMessage96(0x93,&names96_d25f78[data->mode],0,0,owner,HProp(),0,0))
							consoleA96_cec058->unknown8758d0(true);
						logMsgs96_cec0b4->scrollToEnd();
					} while (0);
					switch (data->mode)
					{
					case 1:
					case 2:
						stats96_d2c658.add4729d0(0x1f3,1,"",-1);
						playerData96_cf45d8.unknown77fbc0(0x2d);
						if (playerData96_cf45d8.isSlotEmpty(0x9d))
						{
							int count = 0;
							for (unsigned int i = 0; i < statLists96_d2c65c.size(); i++)
							{
								if ((*statLists96_d2c65c[i])[0x1f3] != 0)
									count++;
							}
							if (count >= 5)
								playerData96_cf45d8.unknown77fbc0(0x9d);
						}
						break;
					case 3:
						stats96_d2c658.add4729d0(0x1f6,1,"",-1);
						break;
					case 4:
						stats96_d2c658.add4729d0(0x1f9,1,"",-1);
						break;
					}
				}
				else
				{
					do
					{
						if (showMessage96(owner->isHostileTo(world96_cefc4c->getPlayer()) ? 0x95 : 0x94,&names96_d25f78[data->mode],0,0,owner,HProp(),0,0))
							consoleA96_cec058->unknown8758d0(true);
						logMsgs96_cec0b4->scrollToEnd();
					} while (0);
					cmap96_cec054->unknown807f70(owner,data->mode);
				}
			}
			getEffect(0x6b)->state = 2;
			unknown44 = 0;
			if (owner.isValid() && owner->isPlayer() && (uiMode96_d28d68 == 0 || uiMode96_d28d68 == 4))
				parts96_cec088->unknown896b40();
		}
		itemUI96_cec11c->unknown4aee10(unknown04);
		break;
	case 3:
		if (owner.isValid() && owner->getTarget())
		{
			reset578800();
			break;
		}
		unknown44--;
		if (unknown44 == duration && owner.isValid() && owner->isPlayer() && (uiMode96_d28d68 == 0 || uiMode96_d28d68 == 4))
			parts96_cec088->unknown896b40();
		if (unknown44 == 1)
		{
			unknown458630(getEffect(0x6b));
			unknown44 = 0;
		}
		if (owner.isValid() && !owner->unknown5cad50())
		{
			switch (data->mode)
			{
			case 1:
			case 2:
				opR1d_454260(owner->getPosition(),0xea);
				break;
			case 3:
				opR1d_454260(owner->getPosition(),0xec);
				break;
			case 4:
				opR1d_454260(owner->getPosition(),0xee);
				break;
			}
			if (owner->isPlayer())
			{
				do
				{
					if (showMessage96(0x96,&names96_d25f78[data->mode],0,0,owner,HProp(),0,0))
						consoleA96_cec058->unknown8758d0(true);
					logMsgs96_cec0b4->scrollToEnd();
				} while (0);
			}
			else
			{
				do
				{
					if (showMessage96(owner->isHostileTo(world96_cefc4c->getPlayer()) ? 0x98 : 0x97,&names96_d25f78[data->mode],0,0,owner,HProp(),0,0))
						consoleA96_cec058->unknown8758d0(true);
					logMsgs96_cec0b4->scrollToEnd();
				} while (0);
			}
		}
		itemUI96_cec11c->unknown4aee10(unknown04);
		break;
	}
}
