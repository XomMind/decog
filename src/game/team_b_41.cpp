// team_b_41: CParts equip result messages (0x89cda0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
using namespace std;
string intToString(int value);
class HProp { public: int ID; HProp(); };
struct TeamB_EquipRecord { char pad[0x1ac]; bool special; };	// NOTE: placeholder layout
class TeamB_EquipItem	// NOTE: placeholder name (Item)
{
public:
	int getType();
	TeamB_EquipRecord *getRecord_44a7f0();	// NOTE: placeholder name
	void *getEffect(int type);
	string getName_571db0(int a, int b);	// NOTE: placeholder name
};
class HItem { public: int ID; TeamB_EquipItem *operator->() const; };
class TeamB_EquipEntity;
class HEntity { public: int ID; TeamB_EquipEntity *operator->() const; };
class TeamB_EquipEntity	// NOTE: placeholder name (Entity)
{
public:
	int unknown5dbb60(HItem item, int a, bool b, bool c);	// NOTE: placeholder name
	int unknown5db3c0(HItem item, int a, int b);	// NOTE: placeholder name
	int unknown5cb7f0();	// NOTE: placeholder name
	void unknown45b1b0(int value);	// NOTE: placeholder name
	int unknown642940(HItem item, int a, int b, bool c, int d);	// NOTE: placeholder name
};
class TeamB_EquipWorld { public: HEntity getPlayer(); bool unknown464350(); void unknown774390(int a, int b); };	// NOTE: placeholder name (Map)
extern TeamB_EquipWorld *teamb_equipWorld_cefc4c;	// NOTE: placeholder name
struct TeamB_EquipSlot { char pad[0x6c]; HItem item; char pad70[0x78 - 0x70]; bool flag78; int getField_416230(); };	// NOTE: placeholder layout
bool teamb_logMessage3_5111e0(int id, const string *text, const string *b, int c, HEntity d, HProp e, const void *at, int flag);	// NOTE: placeholder name
void teamb_msg89c_7b1750(int type, const string &a, const string *b, const string *c, HEntity e, HProp p, int d);	// NOTE: placeholder name (0x7b1750)
class TeamB_MsgConsole89c { public: void unknown8758d0(bool flag); };	// NOTE: placeholder name
extern TeamB_MsgConsole89c *teamb_msgConsole89c_cec058;	// NOTE: placeholder name
class TeamB_LogMsgs89c { public: void scrollToEnd(); };	// NOTE: placeholder name (CLogMsgs)
extern TeamB_LogMsgs89c *teamb_logMsgs89c_cec0b4;	// NOTE: placeholder name
class TeamB_EquipHelp { public: void showOnce(int id, int a, int b, int c, int d); };	// NOTE: placeholder name
extern TeamB_EquipHelp *teamb_equipHelp_cefaa8;	// NOTE: placeholder name
extern string teamb_slotNames_d378d0[];	// NOTE: placeholder name
extern int teamb_storage_cefc68;	// NOTE: placeholder name
class TeamB_PartsEquip	// NOTE: placeholder name (CParts)
{
public:
	char pad[0x140];
	string text140;
	char pad15c[0x1a0 - 0x15c];
	string text1a0;
	int unknown8982e0(TeamB_EquipSlot *slot);	// NOTE: placeholder name
	int unknown898350(TeamB_EquipSlot *slot);	// NOTE: placeholder name
	int equip89cda0(TeamB_EquipSlot *slot);
};
int TeamB_PartsEquip::equip89cda0(TeamB_EquipSlot *slot)	// 0x89cda0 (local names follow docs/local-name-buckets.txt)
{
	HEntity player = teamb_equipWorld_cefc4c->getPlayer();
	int value = slot->item->getType() <= 3 ? player->unknown5dbb60(slot->item,0,true,true) : player->unknown5db3c0(slot->item,0,0);
	switch (value)
	{
		case 0:
			do
			{
				if (teamb_logMessage3_5111e0(slot->item->getRecord_44a7f0()->special == 0 && slot->item->getEffect(0x6e) == NULL ? 0xf : 0x10,&slot->item->getName_571db0(0,0),0,0,player,HProp(),0,0))
					teamb_msgConsole89c_cec058->unknown8758d0(true);
				teamb_logMsgs89c_cec0b4->scrollToEnd();
			} while (0);
			if (!teamb_equipWorld_cefc4c->unknown464350())
				player->unknown45b1b0(player->unknown5cb7f0());
			teamb_equipWorld_cefc4c->unknown774390(8,player->unknown642940(slot->item,1,1,slot->flag78,0));
			break;
		case 9:
			teamb_msg89c_7b1750(0x15,slot->item->getName_571db0(0,0),0,0,player,HProp(),0);
			break;
		case 10:
			teamb_msg89c_7b1750(0x16,text1a0,0,0,player,HProp(),0);
			break;
		case 0x1b:
			teamb_msg89c_7b1750(0x10,text140,0,0,player,HProp(),0);
			break;
		case 0x1c:
			teamb_msg89c_7b1750(0x12,string(unknown8982e0(slot) > 1 ? "slots" : "slot"),0,0,player,HProp(),0);
			break;
		case 0x1d:
			teamb_msg89c_7b1750(0x13,string(teamb_slotNames_d378d0[slot->getField_416230()]) + (unknown898350(slot) > 1 ? " slots" : " slot"),0,0,player,HProp(),0);
			break;
		case 0x1e:
			teamb_msg89c_7b1750(0x11,slot->item->getName_571db0(0,0),0,0,player,HProp(),0);
			break;
		case 0xb:
			teamb_msg89c_7b1750(0x17,slot->item->getName_571db0(0,0),0,0,player,HProp(),0);
			break;
		case 0xc:
			teamb_msg89c_7b1750(0x19,slot->item->getName_571db0(0,0),0,0,player,HProp(),0);
			break;
		case 0xd:
			teamb_msg89c_7b1750(0x1a,slot->item->getName_571db0(0,0),0,0,player,HProp(),0);
			break;
		case 0xe:
			teamb_msg89c_7b1750(0x1b,slot->item->getName_571db0(0,0),0,0,player,HProp(),0);
			break;
		case 0x22:
			teamb_msg89c_7b1750(0x1e,slot->item->getName_571db0(0,0),0,0,player,HProp(),0);
			break;
		case 1:
			teamb_msg89c_7b1750(0,intToString(teamb_storage_cefc68),0,0,player,HProp(),0);
			teamb_equipHelp_cefaa8->showOnce(0x32,1,0,0,0);
			break;
	}
	return value;
}
