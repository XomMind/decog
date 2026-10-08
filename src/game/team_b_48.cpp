// team_b_48: CMap equip-all from inventory (0x81a0e0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
class HProp { public: int ID; HProp(); };
class TeamB_EquipAllItem	// NOTE: placeholder name (Item)
{
public:
	int getType();
	void *getEffect(int type);
	int delegate_577fb0();	// NOTE: placeholder name
	void reset578800();	// NOTE: placeholder name
	string getName_571db0(int a, int b);	// NOTE: placeholder name
};
class HItem { public: int ID; TeamB_EquipAllItem *operator->() const; };
class TeamB_EquipAllEntity;
class HEntity { public: int ID; TeamB_EquipAllEntity *operator->() const; };
class TeamB_EquipAllEntity	// NOTE: placeholder name (Entity)
{
public:
	vector<HItem> *getInventoryList();
	int unknown642940(HItem item, int a, int b, bool c, int d);	// NOTE: placeholder name
};
class TeamB_EquipAllWorld { public: HEntity getPlayer(); };	// NOTE: placeholder name (Map)
extern TeamB_EquipAllWorld *teamb_equipAllWorld_cefc4c;	// NOTE: placeholder name
class TeamB_EquipAllSlot { public: void setField_450570(int flag); };	// NOTE: placeholder name
class TeamB_EquipAllParts { public: TeamB_EquipAllSlot *unknown894e70(HItem item); };	// NOTE: placeholder name (CParts)
extern TeamB_EquipAllParts *teamb_equipAllParts_cec088;	// NOTE: placeholder name
class TeamB_EquipAllPlayerData { public: bool unknown77fbc0(int type); };	// NOTE: placeholder name (PlayerData)
extern TeamB_EquipAllPlayerData teamb_equipAllPlayerData_cf45d8;	// NOTE: placeholder name
bool teamb_logMessage4_5111e0(int id, const string *text, const string *b, int c, HEntity d, HProp e, const void *at, int flag);	// NOTE: placeholder name
class TeamB_MsgConsole81a { public: void unknown8758d0(bool flag); };	// NOTE: placeholder name
extern TeamB_MsgConsole81a *teamb_msgConsole81a_cec058;	// NOTE: placeholder name
class TeamB_LogMsgs81a { public: void scrollToEnd(); };	// NOTE: placeholder name (CLogMsgs)
extern TeamB_LogMsgs81a *teamb_logMsgs81a_cec0b4;	// NOTE: placeholder name
class TeamB_CMapEquipAll	// NOTE: placeholder name (CMap)
{
public:
	int equipAll81a0e0(int flag);
};
int TeamB_CMapEquipAll::equipAll81a0e0(int flag)	// 0x81a0e0 (local names follow docs/local-name-buckets.txt)
{
	HEntity player = teamb_equipAllWorld_cefc4c->getPlayer();
	vector<HItem> items = *player->getInventoryList();
	int total = 0;
	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i].operator->() != NULL && items[i]->getType() <= 3 && items[i]->getEffect(0x6c) == NULL)
		{
			if (items[i]->delegate_577fb0())
				items[i]->reset578800();
			do
			{
				if (teamb_logMessage4_5111e0(0x13,&items[i]->getName_571db0(0,0),0,0,player,HProp(),0,0))
					teamb_msgConsole81a_cec058->unknown8758d0(true);
				teamb_logMsgs81a_cec0b4->scrollToEnd();
			} while (0);
			TeamB_EquipAllSlot *slot = teamb_equipAllParts_cec088->unknown894e70(items[i]);
			if (slot != NULL)
				slot->setField_450570(flag);
			player->unknown642940(items[i],1,1,false,0);
			total++;
		}
	}
	if (total != 0 && flag)
		teamb_equipAllPlayerData_cf45d8.unknown77fbc0(0x21);
	return total;
}
