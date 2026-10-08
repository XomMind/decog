// team_b_56: Entity fragile-part check (0x603030) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names (local names follow docs/local-name-buckets.txt).
#include <string>
using namespace std;
class RNG { public: bool chance(float percent); };
extern RNG rng;	// 0xd30908
class HProp { public: int ID; HProp(); };
class HEntity { public: int ID; bool operator==(HEntity other) const; };
struct TeamB_FragileEffect { int type; int value; };	// NOTE: placeholder layout
class TeamB_FragileItem	// NOTE: placeholder name (Item)
{
public:
	bool unknown457d10();	// NOTE: placeholder name
	TeamB_FragileEffect *getEffect(int type);
	int getEffectValue(int type);
	void unknown458630(TeamB_FragileEffect *effect);	// NOTE: placeholder name
	string getName_571db0(int a, int b);	// NOTE: placeholder name
	void setBroken(int a, bool b);
};
class HItem { public: int ID; TeamB_FragileItem *operator->() const; };
class TeamB_FragileWorld { public: HEntity getEntity671(); };	// NOTE: placeholder name (BS)
extern TeamB_FragileWorld *teamb_fragileWorld_cefc4c;	// NOTE: placeholder name
class TeamB_RolledValues { public: void say(int id, int a, string text); };	// NOTE: placeholder name (OpW5_RolledValues)
extern TeamB_RolledValues *teamb_rolled_cefb48;	// NOTE: placeholder name
extern int opw8_cf462c;	// NOTE: placeholder name (game mode)
bool teamb_logMessage5_5111e0(int id, const string *text, const string *b, int c, HEntity d, HProp e, const void *at, int flag);	// NOTE: placeholder name
class TeamB_MsgConsole603 { public: void unknown8758d0(bool flag); };	// NOTE: placeholder name
extern TeamB_MsgConsole603 *teamb_msgConsole603_cec058;	// NOTE: placeholder name
class TeamB_LogMsgs603 { public: void scrollToEnd(); };	// NOTE: placeholder name (CLogMsgs)
extern TeamB_LogMsgs603 *teamb_logMsgs603_cec0b4;	// NOTE: placeholder name
class TeamB_FragileEntity	// NOTE: placeholder name (Entity)
{
public:
	int pad0;
	HEntity self;
	int getFaction();
	bool isPlayer();
	bool checkFragile603030(HItem item);
};
bool TeamB_FragileEntity::checkFragile603030(HItem item)	// 0x603030
{
	if (item->unknown457d10())
		return false;
	if (item->getEffect(0x5e) != NULL && (getFaction() == 0 || getFaction() == 0x30))
	{
		if (item->getEffectValue(0x5f) != 0)
		{
			TeamB_FragileEffect *effect = item->getEffect(0x5f);
			effect->value--;
			if (effect->value == 0)
				item->unknown458630(effect);
		}
		else
		{
			float pct = item->getEffectValue(0x5e) / 10.0;
			if (rng.chance(pct))
			{
				do
				{
					if (teamb_logMessage5_5111e0(isPlayer() ? 0x181 : 0x182,&item->getName_571db0(0,0),0,0,self,HProp(),0,0))
						teamb_msgConsole603_cec058->unknown8758d0(true);
					teamb_logMsgs603_cec0b4->scrollToEnd();
				} while (0);
				item->setBroken(-2,true);
				if (opw8_cf462c == 7 && self == teamb_fragileWorld_cefc4c->getEntity671() && teamb_rolled_cefb48 != NULL)
					teamb_rolled_cefb48->say(0x23,0,item->getName_571db0(0,0));
				return true;
			}
		}
	}
	return false;
}
