// team_c_41: end-of-run achievement checks (0x472e90): awards score/collection/stat-based achievements
// NOTE: member names are placeholders (f<offset>); helper classes and globals are private placeholders
#include <string>
#include <vector>
using namespace std;

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
bool OpX5_containsRecord(vector<int> &v, int value);	// NOTE: placeholder name
bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (in range)
int OpT8a_sumVector(vector<int> &v);

struct C41_Player { bool unknown77fbc0(int type); void unknown77fea0(bool flag); bool isSlotEmpty(unsigned int index); };	// NOTE: placeholder (PlayerData)
struct C41_Meta { int getLoreCollectionPercent(); int getGalleryCollectionPercent(); int percent(); };	// NOTE: placeholder (GameMetaData)
struct C41_GameData { const string &getEntryText(const string &key); };	// NOTE: placeholder
struct C41_Rec { char pad0[0x44]; int f44; int f48; };	// NOTE: placeholder
struct C41_Def { char pad0[0x1c8]; int f1c8; int f1cc; int f1d0; int f1d4; int f1d8; };	// NOTE: placeholder
struct C41_Kind { char pad0[0x4c]; int f4c; };	// NOTE: placeholder
struct C41_Loc { int f0; int f4; bool inRange(); };	// NOTE: placeholder
class C41_HLoc { public: int ID; C41_Loc *operator->() const; };	// NOTE: placeholder

extern int c41_d25740, c41_cf4b38;	// NOTE: placeholder names below
extern bool c41_cf4d14, c41_cf4d15, c41_cf4d16, c41_cf4d18;
extern C41_Player c41_cf45d8;
extern C41_Meta c41_d25628;
extern C41_GameData c41_d1e860;
extern vector<int> c41_d257b0, c41_cf09a8, c41_d25750, c41_cf4c28;
extern vector<C41_Rec *> c41_d2d1c4;
extern vector<C41_Def *> c41_d25de0;
extern vector<C41_Kind *> c41_d389c4;
extern vector<C41_HLoc> c41_d1e88c;

struct C38_Stats	// NOTE: placeholder layout (OpR1h_Stats)
{
	vector<int> *values;
	char pad4[0x110 - 4];
	int f110;
	int f114;
	int f118;
	char pad11c[0x158 - 0x11c];
	vector<int> f158;
	char pad168[0x1a8 - 0x168];
	int f1a8;

	void collectStats_472e90();
};

void C38_Stats::collectStats_472e90()
{
	if (c41_d25740 >= 50)
		c41_cf45d8.unknown77fbc0(244);
	if (f110 >= 5000)
		c41_cf45d8.unknown77fbc0(245);
	if (f110 >= 10000)
		c41_cf45d8.unknown77fbc0(246);
	if (f110 >= 20000)
		c41_cf45d8.unknown77fbc0(247);
	if (f110 >= 30000)
		c41_cf45d8.unknown77fbc0(248);
	if (f110 >= 40000)
		c41_cf45d8.unknown77fbc0(249);
	if (f110 >= 50000)
		c41_cf45d8.unknown77fbc0(250);
	if (f110 >= 75000)
		c41_cf45d8.unknown77fbc0(251);
	if (f110 >= 100000)
		c41_cf45d8.unknown77fbc0(252);
	if (f110 >= 150000)
		c41_cf45d8.unknown77fbc0(253);
	int center = c41_d25628.getLoreCollectionPercent();
	if (center >= 25)
		c41_cf45d8.unknown77fbc0(254);
	if (center >= 50)
		c41_cf45d8.unknown77fbc0(255);
	if (center >= 75)
		c41_cf45d8.unknown77fbc0(256);
	if (center >= 100)
		c41_cf45d8.unknown77fbc0(257);
	int adj = c41_d25628.getGalleryCollectionPercent();
	if (adj >= 25)
		c41_cf45d8.unknown77fbc0(258);
	if (adj >= 50)
		c41_cf45d8.unknown77fbc0(259);
	if (adj >= 75)
		c41_cf45d8.unknown77fbc0(260);
	if (adj >= 100)
		c41_cf45d8.unknown77fbc0(261);
	if (c41_d257b0.size() == c41_cf09a8.size() - 1)
		c41_cf45d8.unknown77fbc0(279);
	c41_cf45d8.unknown77fea0(true);
	if ((*values)[440] >= 30000)
		c41_cf45d8.unknown77fbc0(312);
	if ((*values)[442] >= 30000)
		c41_cf45d8.unknown77fbc0(313);
	if ((*values)[439] >= 30000)
		c41_cf45d8.unknown77fbc0(314);
	if ((*values)[23] >= 10000)
		c41_cf45d8.unknown77fbc0(347);
	if (c41_cf4b38 <= 9)
	{
		if (c41_cf4b38 <= 9)
		{
			c41_cf45d8.unknown77fbc0(c41_cf4b38 + 438);
			if (!OpX5_containsRecord(c41_d25750,0))
				c41_cf45d8.unknown77fbc0(280);
		}
		if ((*values)[47] != 0 && stringToInt(c41_d1e860.getEntryText("zioAttackedLocals_g")) == 0)
			c41_cf45d8.unknown77fbc0(448);
		if (stringToInt(c41_d1e860.getEntryText("secScannedCogmind_g")))
			c41_cf45d8.unknown77fbc0(450);
		if ((*values)[45] != 0)
			c41_cf45d8.unknown77fbc0(449);
		if (c41_cf4d14 && f158[0] == c41_d25de0[0]->f1cc && f158[1] == c41_d25de0[0]->f1d0 && f158[3] == c41_d25de0[0]->f1d8)
			c41_cf45d8.unknown77fbc0(453);
		if ((*values)[1028] == 0)
			c41_cf45d8.unknown77fbc0(454);
		if ((*values)[2] == 0)
			c41_cf45d8.unknown77fbc0(457);
		if ((*values)[1006] < 2000)
			c41_cf45d8.unknown77fbc0(459);
		if ((*values)[1006] < 1000)
			c41_cf45d8.unknown77fbc0(460);
		if (f114 * 100 / f118 < 5)
			c41_cf45d8.unknown77fbc0(461);
		if (c41_cf45d8.isSlotEmpty(469))
		{
			bool col = false;
			for (unsigned int cols = 0; cols < c41_d2d1c4.size(); cols++)
			{
				if (c41_cf4c28[cols] != 0 && c41_d2d1c4[cols]->f48 == 1)
				{
					if (c41_d2d1c4[cols]->f44 != 13)
						goto skip469;
					else
						col = true;
				}
			}
			if (col)
				c41_cf45d8.unknown77fbc0(469);
		}
skip469:
		if ((*values)[223] >= 200)
		{
			vector<int> col;
			vector<int> cols;
			col.push_back(472);
			cols.push_back(11);
			col.push_back(471);
			cols.push_back(10);
			col.push_back(470);
			cols.push_back(9);
			for (unsigned int current = 0; current < col.size(); current++)
			{
				if (c41_cf45d8.isSlotEmpty(col[current]))
				{
					bool distanceSq = false;
					for (unsigned int distances = 0; distances < c41_d2d1c4.size(); distances++)
					{
						if (c41_cf4c28[distances] != 0 && c41_d2d1c4[distances]->f48 == 1)
						{
							if (c41_d2d1c4[distances]->f44 != cols[current])
								goto next;
							else
								distanceSq = true;
						}
					}
					if (distanceSq)
						c41_cf45d8.unknown77fbc0(col[current]);
				}
next:;
			}
		}
		if ((*values)[223] >= 400)
		{
			c41_cf45d8.unknown77fbc0(473);
			if (c41_cf4d15 && f158[2] <= 4)
				c41_cf45d8.unknown77fbc0(474);
			if ((*values)[223] >= 600)
				c41_cf45d8.unknown77fbc0(475);
		}
		if ((*values)[84] != 0)
			c41_cf45d8.unknown77fbc0(451);
		if (c41_cf4d16)
			c41_cf45d8.unknown77fbc0(476);
		if ((*values)[117] == 0)
			c41_cf45d8.unknown77fbc0(468);
		if ((*values)[82] / c41_d389c4[82]->f4c >= 3)
			c41_cf45d8.unknown77fbc0(452);
		if (c41_cf45d8.isSlotEmpty(455) && (*values)[710] == 0 && (*values)[223] >= 200)
		{
			bool col = false;
			for (unsigned int cols = 1; cols < c41_d1e88c.size(); cols++)
			{
				if (!c41_d1e88c[cols]->inRange() && c41_d1e88c[cols]->f4 != 12)
				{
					col = true;
					break;
				}
			}
			if (!col)
				c41_cf45d8.unknown77fbc0(455);
		}
		if ((*values)[1028] == 1 && stringToInt(c41_d1e860.getEntryText("comMaincDestroyed_g")) != 0 && stringToInt(c41_d1e860.getEntryText("comPlayerSurrenderedBefore_g")) == 0 && (*values)[37] == 0)
			c41_cf45d8.unknown77fbc0(456);
		if ((*values)[1033] == 0)
			c41_cf45d8.unknown77fbc0(458);
		if ((*values)[197] == c41_d25de0[0]->f1c8)
			c41_cf45d8.unknown77fbc0(462);
		if (c41_cf4b38 <= 9 && f1a8 >= 200 && c41_d1e88c.back()->f4 == 5)
			c41_cf45d8.unknown77fbc0(463);
		if (c41_cf45d8.isSlotEmpty(464) && (*values)[223] >= 100)
		{
			for (int col = 131, cols = 20; col <= 140; col++, cols++)
			{
				if ((*values)[col] > 0 && !OpT8b_Fn9daf80(26,cols,28))
					goto skip464;
			}
			c41_cf45d8.unknown77fbc0(464);
		}
skip464:
		if ((*values)[613] == 0 && c41_cf4d18)
			c41_cf45d8.unknown77fbc0(465);
		if ((*values)[25] != 0)
			c41_cf45d8.unknown77fbc0(466);
		if (OpT8a_sumVector(c41_d25750) >= 25)
			c41_cf45d8.unknown77fbc0(478);
	}
	int behaviour = c41_d25628.percent();
	if (behaviour >= 25)
		c41_cf45d8.unknown77fbc0(276);
	if (behaviour >= 50)
		c41_cf45d8.unknown77fbc0(277);
	if (behaviour >= 75)
		c41_cf45d8.unknown77fbc0(278);
}
