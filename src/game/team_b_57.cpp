// team_b_57: Entity part destruction roll (0x63c120) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
class RNG { public: bool chance(int percent); };
extern RNG rng;	// 0xd30908
class HProp { public: int ID; HProp(); };
class HEntity { public: int ID; };
class TeamB_RollItem	// NOTE: placeholder name (Item)
{
public:
	bool unknown458220();	// NOTE: placeholder name
	int getSlot_4578a0();	// NOTE: placeholder name
	int unknown457f70();	// NOTE: placeholder name
	string getName_571db0(int a, int b);	// NOTE: placeholder name
	bool unknown57ab10(int a, int b, int c, int d, HProp e, int f, int g);	// NOTE: placeholder name
};
class HItem { public: int ID; TeamB_RollItem *operator->() const; };
bool teamb_logMessage6_5111e0(int id, const string *text, const string *b, int c, HEntity d, HProp e, const void *at, int flag);	// NOTE: placeholder name
class TeamB_MsgConsole63c { public: void unknown8758d0(bool flag); };	// NOTE: placeholder name
extern TeamB_MsgConsole63c *teamb_msgConsole63c_cec058;	// NOTE: placeholder name
class TeamB_LogMsgs63c { public: void scrollToEnd(); };	// NOTE: placeholder name (CLogMsgs)
extern TeamB_LogMsgs63c *teamb_logMsgs63c_cec0b4;	// NOTE: placeholder name
class TeamB_Stats63c { public: bool add4729d0(unsigned int id, int value, string text, int extra) throw(); };	// NOTE: placeholder name
extern TeamB_Stats63c teamb_stats63c_d2c658;	// NOTE: placeholder name
class TeamB_RollEntity	// NOTE: placeholder name (Entity)
{
public:
	int pad0;
	HEntity self;
	char pad8[0x134 - 8];
	vector<HItem> parts;
	bool isPlayer();
	int rollDestroy63c120();
};
int TeamB_RollEntity::rollDestroy63c120()	// 0x63c120
{
	int count = 0;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->unknown458220() && parts[i]->getSlot_4578a0() == 1)
		{
			count++;
			if (rng.chance(parts[i]->unknown457f70()))
			{
				string name = parts[i]->getName_571db0(0,0);
				if (parts[i]->unknown57ab10(1,1,0,0,HProp(),0,0))
				{
					do
					{
						if (teamb_logMessage6_5111e0(0x18f,&name,0,0,self,HProp(),0,0))
							teamb_msgConsole63c_cec058->unknown8758d0(true);
						teamb_logMsgs63c_cec0b4->scrollToEnd();
					} while (0);
					if (isPlayer())
						teamb_stats63c_d2c658.add4729d0(0x3fa,1,"",-1);
				}
			}
		}
	}
	return count;
}
