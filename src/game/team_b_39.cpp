// team_b_39: Pay2Buy purchase handler (0x877150) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
#include "../util/rng.h"
extern RNG rng;	// 0xd30908
int stringToInt(const string &text);
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name
int ops7_clamp_9cdc80(int min, int value, int max);
struct Point { int x; int y; Point(const Point &p); };
class HProp { public: int ID; HProp(); };
struct TeamB_ShopType { int index; char pad04[0x24 - 4]; string name; char pad40[0x4c - 0x40]; int size; char pad50[0xf0 - 0x50]; int slot; };	// NOTE: placeholder layout
struct TeamB_ShopOffer { int kind; TeamB_ShopType *type; int cost; };	// NOTE: placeholder layout
extern vector<TeamB_ShopType *> teamb_shopTypes_d2d1c4;	// NOTE: placeholder name
class TeamB_ShopEntity;
class TeamB_HShopEntity { public: int ID; TeamB_ShopEntity *operator->() const; };	// NOTE: placeholder name (HEntity)
class TeamB_ShopItem;
class TeamB_HShopItem { public: int ID; TeamB_ShopItem *operator->() const; };	// NOTE: placeholder name (HItem)
class TeamB_ShopItem	// NOTE: placeholder name (Item)
{
public:
	void unknown458390(int a);	// NOTE: placeholder name
	int getNestedField();
	int getSlot_4578a0();	// NOTE: placeholder name
	void unknown57a190(TeamB_HShopEntity owner, int slot, int a, int b);	// NOTE: placeholder name
	void unknown57a0f0(Point &pos, int a, int b);	// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};
class TeamB_ShopEntity	// NOTE: placeholder name (Entity)
{
public:
	int unknown5db5f0(TeamB_HShopItem item, bool ignoreSlots, bool ignoreStorage, bool quiet);	// NOTE: placeholder name
	int unknown5dc440(TeamB_HShopItem item);	// NOTE: placeholder name
	int unknown45a810();	// NOTE: placeholder name
	const Point &getPosition();
};
class TeamB_ShopWorld	// NOTE: placeholder name (Map/BS)
{
public:
	void setUnknownB18(int value);	// NOTE: placeholder name
	vector<TeamB_ShopOffer *> *unknown463fc0();	// NOTE: placeholder name
	TeamB_ShopType *selectRandomItemOfRating(int rating, int a, int b, int c, int d, int e, int f);	// NOTE: placeholder name
	TeamB_HShopEntity getPlayer();
	bool unknown71bc10(Point &a, Point &b);	// NOTE: placeholder name
};
extern TeamB_ShopWorld *teamb_shopWorld_cefc4c;	// NOTE: placeholder name
class TeamB_ShopList { public: int unknown45a990(); void unknown7b2870(); };	// NOTE: placeholder name (CList)
extern TeamB_ShopList *teamb_shopList_cec130;	// NOTE: placeholder name
template <class T> class TeamB_ShopWL	// NOTE: placeholder name (OpR5h_WL)
{
public:
	TeamB_ShopWL();
	~TeamB_ShopWL();
	void add(T value, int weight);
	T &pick();
	char pad[0x24];
};
class TeamB_ShopLocation { public: int unknown46ed20(); };	// NOTE: placeholder name
class TeamB_HShopLocation { public: int ID; TeamB_ShopLocation *operator->() const; };	// NOTE: placeholder name
extern TeamB_HShopLocation teamb_shopLocation_d1e888;	// NOTE: placeholder name
class TeamB_ShopFactory { public: TeamB_HShopItem createD(TeamB_ShopType *type); };	// NOTE: placeholder name (OpU5s2_Factory)
extern TeamB_ShopFactory *teamb_shopFactory_cefaa8;	// NOTE: placeholder name
class TeamB_ShopPlayerData { public: void unknown77ffb0(int type, int a); };	// NOTE: placeholder name (PlayerData)
extern TeamB_ShopPlayerData teamb_shopPlayerData_cf45d8;	// NOTE: placeholder name
class TeamB_ShopParts { public: int unknown894e70(TeamB_HShopItem item, int a); void unknown8993e0(int index); };	// NOTE: placeholder name (CParts)
extern TeamB_ShopParts *teamb_shopParts_cec088;	// NOTE: placeholder name
class TeamB_ShopInventory { public: void reopen(int mode, TeamB_HShopItem item); };	// NOTE: placeholder name (CInventory)
extern TeamB_ShopInventory *teamb_shopInventory_cec08c;	// NOTE: placeholder name
bool teamb_logMessage2_5111e0(int id, const string *text, const string *b, int c, HProp d, HProp e, const Point *at, int flag);	// NOTE: placeholder name
class TeamB_MsgConsole877 { public: void unknown8758d0(bool flag); };	// NOTE: placeholder name
extern TeamB_MsgConsole877 *teamb_msgConsole877_cec058;	// NOTE: placeholder name
class TeamB_LogMsgs877 { public: void scrollToEnd(); };	// NOTE: placeholder name (CLogMsgs)
extern TeamB_LogMsgs877 *teamb_logMsgs877_cec0b4;	// NOTE: placeholder name
extern int teamb_credits_cf4630;	// NOTE: placeholder name
extern int teamb_jackpot_cf4674;	// NOTE: placeholder name
extern int teamb_jackpotCount_cf4678;	// NOTE: placeholder name
extern vector<int> teamb_jackpotTypes_cf467c;	// NOTE: placeholder name
extern vector<int> teamb_purchases_cf4654;	// NOTE: placeholder name
extern vector<int> teamb_purchaseTypes_cf4644;	// NOTE: placeholder name
void teamb_refreshShop_8779a0();	// NOTE: placeholder name
#define TEAMB_SHOPMSG(text) do { if (teamb_logMessage2_5111e0(0x325,&text,0,0,HProp(),HProp(),0,0)) teamb_msgConsole877_cec058->unknown8758d0(true); teamb_logMsgs877_cec0b4->scrollToEnd(); } while (0)
void teamb_buy877150(void *source, const string &value)	// 0x877150 (local names follow docs/local-name-buckets.txt)
{
	teamb_shopWorld_cefc4c->setUnknownB18(teamb_shopList_cec130->unknown45a990());
	if (value.empty())
	{
		teamb_shopList_cec130->unknown7b2870();
		return;
	}
	int index = stringToInt(value);
	vector<TeamB_ShopOffer *> &arr = *teamb_shopWorld_cefc4c->unknown463fc0();
	teamb_credits_cf4630 -= arr[index]->cost;
	TeamB_ShopType *data = NULL;
	string msg;
	switch (arr[index]->kind)
	{
		case 0:
		{
			bool winner = false;
			if (teamb_jackpot_cf4674 != 0 && (++teamb_jackpotCount_cf4678 >= 0x21 || rng.chance(3)))
			{
				winner = true;
				teamb_jackpot_cf4674 = 0;
				data = teamb_shopTypes_d2d1c4[teamb_jackpotTypes_cf467c.back()];
				msg = "WE HAVE A WINNER!";
				TEAMB_SHOPMSG(msg);
			}
			if (data == NULL)
			{
				TeamB_ShopWL<int> list;
				list.add(-1,10);
				list.add(0,10);
				list.add(1,25);
				list.add(2,40);
				list.add(3,15);
				int level = ops7_clamp_9cdc80(1,teamb_shopLocation_d1e888->unknown46ed20() + list.pick(),9);
				bool first = rng.chance(25);
				for (int i = 0; i < 30; i++)
				{
					if (first)
						data = teamb_shopWorld_cefc4c->selectRandomItemOfRating(level,0,1,0x1f,0x12,0x2a,0);
					if (data == NULL)
						data = teamb_shopWorld_cefc4c->selectRandomItemOfRating(level,0,2,0x1f,0x12,0x2a,0);
					if (data == NULL)
						data = teamb_shopWorld_cefc4c->selectRandomItemOfRating(level,0,0,0x1f,0x12,0x2a,0);
					if (data->slot == 7 || data->slot == 0x8f)
						data = NULL;
					else
						break;
				}
				msg = "You open your loot box...";
				TEAMB_SHOPMSG(msg);
			}
			if (data == NULL)
				msg = "It's empty?!";
			else
			{
				msg = "Congratulations on your very own " + data->name + "!";
				teamb_purchases_cf4654.push_back(-1);
			}
			TEAMB_SHOPMSG(msg);
			break;
		}
		case 1:
			data = arr[index]->type;
			msg = "Purchased: " + data->name;
			TEAMB_SHOPMSG(msg);
			teamb_purchases_cf4654.push_back(arr[index]->cost);
			break;
	}
	if (data != NULL)
	{
		teamb_purchaseTypes_cf4644.push_back(data->index);
		TeamB_HShopItem item = teamb_shopFactory_cefaa8->createD(data);
		item->unknown458390(0);
		teamb_shopPlayerData_cf45d8.unknown77ffb0(item->getNestedField(),0);
		if (teamb_shopWorld_cefc4c->getPlayer()->unknown5db5f0(item,false,true,false) == 0)
		{
			item->unknown57a190(teamb_shopWorld_cefc4c->getPlayer(),item->getSlot_4578a0(),1,1);
			if (teamb_shopWorld_cefc4c->getPlayer()->unknown5dc440(item) == 0)
				teamb_shopParts_cec088->unknown8993e0(teamb_shopParts_cec088->unknown894e70(item,0));
		}
		else if (teamb_shopWorld_cefc4c->getPlayer()->unknown45a810() >= data->size)
		{
			item->unknown57a190(teamb_shopWorld_cefc4c->getPlayer(),4,1,1);
			teamb_shopInventory_cec08c->reopen(5,item);
		}
		else
		{
			Point pos(teamb_shopWorld_cefc4c->getPlayer()->getPosition());
			if (teamb_shopWorld_cefc4c->unknown71bc10(pos,pos))
				item->unknown57a0f0(pos,0,0);
			else
				item->unknown57dbe0(0,0,1,1);
		}
	}
	opR1d_4541b0(0x137,0,0);
	teamb_shopList_cec130->unknown7b2870();
	teamb_refreshShop_8779a0();
}
