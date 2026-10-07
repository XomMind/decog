// team_d_66: member 0x783060 of the object behind the +0x4f4 name / +0x548 flag (Scrapyard UFD registration:
// announces the new member, opens the reading-room door).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

class Prop;
class Entity;

class HProp
{
public:
	int ID;
	HProp();
	bool isValid() const;	// NOTE: folded with HItem::isValid
	Prop *operator->() const;	// NOTE: folded with OpC_Handle::get22c
};

class HEntity
{
public:
	int ID;
	bool isValid() const;	// NOTE: folded with HItem::isValid
	Entity *operator->() const;
};

class Prop
{
public:
	const string &getName();	// NOTE: placeholder name (Push_45c590::operate)
	void unknown45ce10(bool a, int b, bool c, HProp p);	// NOTE: placeholder name
};

class Entity
{
public:
	int getFaction();
};

class Cell
{
public:
	HEntity getEntity();
	HProp getProp();
};

class CellGrid66	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **at(int x, int y);	// NOTE: folded with OpX5_Array2D<int>::at
};
extern CellGrid66 cells66_cfd44c;	// NOTE: placeholder name

struct Area66	// NOTE: placeholder name
{
	int x1;
	int y1;
	int x2;
	int y2;
};
extern vector<Area66> areas66_d22fa8;	// NOTE: placeholder name
extern vector<int> list66_cfc1a4;		// NOTE: placeholder name
int OpS8b_Fn9d4660(vector<int> &v, int value);

class BS
{
public:
	void unknown742270(bool flag);	// NOTE: placeholder name
	void unknown6c65a0(HEntity e, const string &text, int value);
};
extern BS *world66_cefc4c;	// NOTE: placeholder name

class OpV1_GameData
{
public:
	void setEntryText(const string &key, const string &text);
};
extern OpV1_GameData gameData66_d1e860;	// NOTE: placeholder name

struct Location66	// NOTE: placeholder name and layout
{
	int unknown00;
	int type;
};

class HLoc66	// NOTE: placeholder name
{
	int ID;
public:
	Location66 *operator->() const;
};
extern HLoc66 location66_d1e888;	// NOTE: placeholder name

class DataLoader66	// NOTE: placeholder name (0xcefaa8)
{
public:
	void unknown793690();	// NOTE: placeholder name
};
extern DataLoader66 *dataLoader66_cefaa8;	// NOTE: placeholder name

void opw8_unknown789ac0();
void opR1d_4541b0(int id, int a, int b);
string opR1f_465db0();

class OpR1h_Stats
{
public:
	void add472b90(unsigned int id, int value);
};
extern OpR1h_Stats stats66_d2c658;	// NOTE: placeholder name

class MessageLog66	// NOTE: placeholder name (0xcf1080)
{
public:
	void unknown451400(int value);	// NOTE: placeholder name (folded with a protobuf SetCachedSize)
};
extern MessageLog66 messageLog66_cf1080;	// NOTE: placeholder name

class Popups66	// NOTE: placeholder name (OpW5_RolledValues at 0xcefb48)
{
public:
	bool say(int ID, bool force, string name);
};
extern Popups66 *popups66_cefb48;	// NOTE: placeholder name

class ConsoleA66	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA66 *consoleA66_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs66_cec0b4;	// NOTE: placeholder name

bool showMessage66(int id, const string &text, const string *b, int c, HProp d, HProp e, const struct Point *at, int flag);	// NOTE: placeholder name (0x5111e0)
void message66_5141b0(int id, const string *a, const string *b, int c, HProp d, int e);	// NOTE: placeholder name

class Owner66	// NOTE: placeholder name and layout
{
public:
	char	pad000[0x4f4];
	string	unknown4f4;
	char	pad510[0x548 - 0x510];
	int		unknown548;

	void unknown783060();	// NOTE: placeholder name
};

void Owner66::unknown783060()
{
	if (unknown548)
		return;
	unknown548 = 1;
	gameData66_d1e860.setEntryText("scrUfdRegistered_g","1");
	gameData66_d1e860.setEntryText("garCommArraySupport_g","0");
	dataLoader66_cefaa8->unknown793690();
	opw8_unknown789ac0();
	do
	{
		message66_5141b0(0xf8,&unknown4f4,0,0,HProp(),0);
	} while (0);
	stats66_d2c658.add472b90(0x2a,-999999);
	string msg = "ANNOUNCEMENT: Welcome to our newest member, " + unknown4f4 + "! Open the gate!";
	do
	{
		messageLog66_cf1080.unknown451400(1);
		if (0)
			opR1d_4541b0(-1,0,0);
		do
		{
			if (showMessage66(0x324,msg,0,0,HProp(),HProp(),0,0))
				consoleA66_cec058->unknown8758d0(true);
			logMsgs66_cec0b4->scrollToEnd();
		} while (0);
		logMsgs66_cec0b4->scrollToEnd();
	} while (0);
	if (location66_d1e888->type == 0xb)
		world66_cefc4c->unknown742270(true);
	if (popups66_cefb48)
		popups66_cefb48->say(0x6c,false,opR1f_465db0());
	if ((*cells66_cfd44c.at(0x3f,7))->getEntity().isValid() && (*cells66_cfd44c.at(0x3f,7))->getEntity()->getFaction() == 0x2a)
		world66_cefc4c->unknown6c65a0((*cells66_cfd44c.at(0x3f,7))->getEntity(),"SCR_Name_Changer_Seen",0);
	int doorIndex = OpS8b_Fn9d4660(list66_cfc1a4,0x30);
	if (doorIndex != -1)
	{
		Area66 *area = &areas66_d22fa8[doorIndex];
		for (int x = area->x1; x <= area->x2; x++)
		{
			for (int y = area->y1; y <= area->y2; y++)
			{
				if ((*cells66_cfd44c.at(x,y))->getProp().isValid() && (*cells66_cfd44c.at(x,y))->getProp()->getName() == "SCR_Reading_Room_Door")
				{
					(*cells66_cfd44c.at(x,y))->getProp()->unknown45ce10(true,0,true,HProp());
					break;
				}
			}
		}
	}
}
