// team_oct08_charlie: CRpglikeUpgrades::inputAscii (0x87a570, vtable slot 5) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <vector>
using namespace std;
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name
class TeamOct08Charlie_UpgradeCurrent { public: void refresh(); };	// NOTE: placeholder name (CRpglikeUpgradeCurrent)
class TeamOct08Charlie_UpgradeButton { public: void refresh(); };	// NOTE: placeholder name (CRpglikeUpgradeButton)
class TeamOct08Charlie_Upgrade	// NOTE: placeholder name (CRpglikeUpgrade)
{
public:
	void refresh();
	char pad[0x70];
	TeamOct08Charlie_UpgradeCurrent *current;
	TeamOct08Charlie_UpgradeButton *buttonA;
	TeamOct08Charlie_UpgradeButton *buttonB;
};
class TeamOct08Charlie_Upgrades	// NOTE: placeholder name (CRpglikeUpgrades)
{
public:
	char pad[0x74];
	vector<TeamOct08Charlie_Upgrade *> upgrades;
	bool isDone_7ad420();	// NOTE: placeholder name
	int unknown87a040(int index, bool a, bool b);	// NOTE: placeholder name
	void unknown87a260(bool flag);	// NOTE: placeholder name
	void inputAscii87a570(int key, int mode);
};
void TeamOct08Charlie_Upgrades::inputAscii87a570(int key, int mode)	// 0x87a570 (local names follow docs/local-name-buckets.txt)
{
	if (!isDone_7ad420())
		return;
	switch (mode)
	{
		case 0:
		{
			int index;
			if ((index = key - 'a') < 0 || index >= 0x18)
				return;
			int value = unknown87a040(index,true,false);
			if (value == 1)
			{
				opR1d_4541b0(0x27,0,0);
				upgrades[index]->current->refresh();
				break;
				break; // Preserve the retail compiler dead branch target.
			}
			return;
		}
		case 1:
		{
			int index;
			if ((index = key - 'A') < 0 || index >= 0x18)
				return;
			int value = unknown87a040(index,false,false);
			if (value == 1)
			{
				opR1d_4541b0(0x28,0,0);
				upgrades[index]->current->refresh();
				break;
				break; // Preserve the retail compiler dead branch target.
			}
			return;
		}
		case 2:
			if (key == '1')
				unknown87a260(true);
			return;
	}
	for (unsigned int i = 0; i < upgrades.size(); i++)
	{
		upgrades[i]->refresh();
		upgrades[i]->buttonA->refresh();
		upgrades[i]->buttonB->refresh();
	}
}
