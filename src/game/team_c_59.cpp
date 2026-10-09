// team_c_59: special-mode data adjustments (0x778930, PlayerData): RPGLIKE / BattleRoyale / Gauntlet-style mode tweaks to
//	robot and item definitions (part transfer text, Protomatter/Welding Torch descriptions, hacking abilities)
// NOTE: names are placeholders; PlayerData layout is partial
#include <string>
#include <vector>
using namespace std;

string intToString(int value);
void OpX5_fillInts(int *values, int count, int value);	// NOTE: placeholder name
template <class T> bool OpQ5_findByName(vector<T *> &v, const string &name, T *&result);	// NOTE: placeholder name
template <class T> void OpQ5_eraseStep(vector<T> &v, unsigned int &index);	// NOTE: placeholder name
struct C59_Item	// NOTE: placeholder (item record)
{
	char pad0[8];
	string f8;
	char pad24[0x44 - 0x24];
	int f44;
	int f48;
	int f4c;
	char pad50[4];
	int f54;
	char pad58[0x70 - 0x58];
	int f70;
	bool f74;
	char pad75[0xf0 - 0x75];
	int ff0;
	int ff4;
	char padf8[0x1ac - 0xf8];
	bool f1ac;
	char pad1ad[0x20c - 0x1ad];
	int f20c;
	vector<int> f210;
	char pad220[0x288 - 0x220];
	string f288;
};
struct C59_Robot	// NOTE: placeholder (robot record)
{
	int f0;
	string f4;
	int f20;
	int f24;
	int f28;
	char pad2c[0x78 - 0x2c];
	int f78;
	char pad7c[0x94 - 0x7c];
	int f94;
	int f98;
	int f9c;
	char pada0[4];
	int fa4;
	char pada8[0x13c - 0xa8];
	int f13c;
	int f140;
	char pad144[4];
	vector<int> f148;
	char pad158[0x160 - 0x158];
	vector< vector<int *> > f160;
	char pad170[0x1c8 - 0x170];
	int f1c8;
	int f1cc[4];
};
struct C59_Map { char pad0[0x4c]; int f4c; };
struct OpV4d_Trivial;
void OpV4d_deleteMapRecords(vector<OpV4d_Trivial *> &v);	// NOTE: placeholder name

extern vector<C59_Robot *> c59_d25de0;	// NOTE: placeholder names below
extern vector<C59_Item *> c59_d2d1c4;
extern C59_Map *c59_cefc00;
extern bool c59_cefacd, c59_cefacc;
extern const float c59_ba7ed0;
extern int c59_caf440, c59_caf444, c59_caf448, c59_caf44c, c59_cefb4c;

class PlayerData	// NOTE: placeholder layout (partial)
{
public:
	char pad0[0x54];
	int f54;
	char pad58[0x148 - 0x58];
	int f148;

	void unknown778930();
};

void PlayerData::unknown778930()
{
	switch (f54)
	{
		case 5:
		{
			OpX5_fillInts(c59_d25de0[0]->f1cc,4,1);
			for (unsigned int center = 0; center < c59_d25de0.size(); center++)
			{
				for (unsigned int col = 0; col < c59_d25de0[center]->f160.size(); col++)
				{
					if (c59_d2d1c4[*c59_d25de0[center]->f160[col][0]]->ff0 == 7)
					{
						c59_d25de0[center]->f1c8 += c59_d2d1c4[*c59_d25de0[center]->f160[col][0]]->ff4;
						OpV4d_deleteMapRecords((vector<OpV4d_Trivial *> &)c59_d25de0[center]->f160[col]);
						OpQ5_eraseStep(c59_d25de0[center]->f160,col);
					}
				}
			}
			for (int center = c59_d2d1c4.size() - 1; center >= 0; center--)
			{
				if (c59_d2d1c4[center]->f8 == "SUBCON Basin")
				{
					c59_d2d1c4[center]->f4c = 2;
					break;
				}
			}
			c59_cefc00->f4c = 3;
			for (unsigned int center = 0; center < c59_d2d1c4.size(); center++)
			{
				switch (c59_d2d1c4[center]->ff0)
				{
					case 57:
						c59_d2d1c4[center]->f70 = 2;
						c59_d2d1c4[center]->f74 = true;
					case 7:
						c59_d2d1c4[center]->f54 = 0;
						c59_d2d1c4[center]->f210.clear();
						c59_d2d1c4[center]->f20c = 0;
						break;
				}
				if (c59_d2d1c4[center]->f44 == 18)
					c59_d2d1c4[center]->f288 = "Unlike other parts in RPGLIKE mode that transfer " + intToString(80) + "% of incoming damage to your core, all Armor type parts instead transfer only " + intToString(40) + "%.";
			}
			break;
		}
		case 6:
		{
			for (unsigned int col = 0; col < c59_d2d1c4.size(); col++)
			{
				if (c59_d2d1c4[col]->f44 == 18)
					c59_d2d1c4[col]->f288 = "Unlike other parts in BattleRoyale mode that transfer " + intToString(50) + "% of incoming damage to your core, all Armor type parts instead transfer only " + intToString(25) + "%.";
			}
			C59_Item *center;
			if (OpQ5_findByName(c59_d2d1c4,"Protomatter",center))
				center->f288 = "Used to restore integrity of core and attached parts at a rate of 1 protomatter per 3 integrity. Protomatter at your current location is automatically applied each turn as available and necessary.";
			break;
		}
		case 8:
		{
			C59_Item *center;
			if (OpQ5_findByName(c59_d2d1c4,"Welding Torch",center))
				center->f288 = "If you want me to be able to seal doors shut, the answer is YES.";
			if (!c59_cefacd)
				c59_cefacc = false;
			break;
		}
		case 11:
		{
			C59_Item *center;
			if (OpQ5_findByName(c59_d2d1c4,"Protomatter",center))
				center->f288 = "Used as fuel to take control of other robots.";
			for (unsigned int cols = 0; cols < c59_d25de0.size(); cols++)
			{
				if (c59_d25de0[cols]->f13c != 0)
				{
					if (c59_d25de0[cols]->f140 == 0)
						c59_d25de0[cols]->f140 = (int)(c59_d25de0[cols]->f13c * c59_ba7ed0);
					switch (c59_d25de0[cols]->f24)
					{
						case 1:
							switch (c59_d25de0[cols]->f28)
							{
								case 1:
									c59_d25de0[cols]->f148.push_back(0);
									c59_d25de0[cols]->f148.push_back(1);
									break;
								case 2:
									c59_d25de0[cols]->f148.push_back(3);
									break;
								case 3:
									c59_d25de0[cols]->f148.push_back(4);
									break;
								case 5:
									c59_d25de0[cols]->f148.push_back(5);
									c59_d25de0[cols]->f148.push_back(6);
									break;
								case 7:
									c59_d25de0[cols]->f148.push_back(7);
									break;
								case 8:
									c59_d25de0[cols]->f148.push_back(8);
									c59_d25de0[cols]->f148.push_back(9);
									break;
								case 9:
									c59_d25de0[cols]->f148.push_back(10);
									c59_d25de0[cols]->f148.push_back(11);
									c59_d25de0[cols]->f148.push_back(12);
									break;
								case 21:
								case 26:
								case 28:
									c59_d25de0[cols]->f148.push_back(13);
									break;
								case 25:
									c59_d25de0[cols]->f148.push_back(14);
									c59_d25de0[cols]->f148.push_back(15);
									break;
								
							}
							break;
						case 3:
							switch (c59_d25de0[cols]->f28)
							{
								case 1:
									c59_d25de0[cols]->f148.push_back(2);
									break;
								case 8:
									c59_d25de0[cols]->f148.push_back(8);
									break;
							}
							break;
						case 0:
							if (c59_d25de0[cols]->f4 == "Zion_Hero_07")
								c59_d25de0[cols]->f148.push_back(15);
							break;
					}
				}
			}
			C59_Robot *col;
			OpQ5_findByName(c59_d25de0,"Cogmind",col);
			c59_caf440 = col->f9c;
			c59_caf444 = col->f98;
			c59_caf448 = col->f94;
			c59_caf44c = col->fa4;
			c59_cefb4c = col->f78;
			break;
		}
	}
	if (f148 != 0)
	{
		for (unsigned int center = 0; center < c59_d2d1c4.size(); center++)
		{
			if (c59_d2d1c4[center]->ff0 != 7)
				c59_d2d1c4[center]->f1ac = true;
		}
	}
}
