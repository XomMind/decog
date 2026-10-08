// op_gm_784410: GameData122::unknown784410 (0x784410, called by GM::readyGame): seeds a new run (random or
// fixed seed, logged to generated/seeds.txt), builds the world's location graph (main depth chain plus the
// branch maps), assigns map records to locations and resets the per-run game data (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts; callees use file-unique names so they stay stubs.
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Loc784;

class HL784	// NOTE: placeholder name (location handle)
{
public:
	int ID;
	HL784();	// 0x9b6590
	Loc784 *operator->() const;	// 0x9b7910
	void reset();	// NOTE: placeholder name (0x9b7270)
};

struct Loc784	// NOTE: placeholder layout (map location node)
{
	int		unknown00;
	int		type;
	int		depth;
	vector<HL784>	links;
	int		id;
	int		value;
	bool	flag24;
	bool	known;
	char	pad26[0x30 - 0x26];
	vector<int>	records;

	void init(int type_, int depth_, int value_, bool flag_);	// 0x46eb70
	int getDepth();	// 0x46ed20
};

class Factory784	// NOTE: placeholder name (0xcefaa8)
{
public:
	HL784 createB();	// 0x793120
};

struct Range784	// NOTE: placeholder name
{
	int x;
	int y;
	int randomInRange();	// 0x40c130
	bool contains(int value);	// 0x40c190
};

struct Pos784	// NOTE: placeholder name
{
	int x;
	int y;
	Pos784(int v);	// 0x409990
	Pos784 &operator=(const Pos784 &p);	// 0x40a030
	void set(int v);	// 0x409ff0
};

struct Rect784	// NOTE: placeholder name
{
	int x;
	int y;
	int w;
	int h;
	Rect784(const Pos784 &p);	// 0x40a7a0
};

struct Bounds784	// NOTE: placeholder name
{
	int x1;
	int y1;
	int x2;
	int y2;
	void set(const Rect784 &r);	// 0x40b3a0
};

struct Triple784	// NOTE: placeholder name (0x30 bytes)
{
	vector<int> a;
	vector<int> b;
	vector<int> c;
	Triple784();	// 0x46cb90
	~Triple784();	// 0x9b7080
};

struct Grid784	// NOTE: placeholder name
{
	char pad0[0xc];
	void init(int w, int h, int value);	// 0x9cf690
};

struct Obj784;	// NOTE: placeholder element type
struct Pt784 { int x; int y; };	// NOTE: placeholder element type
struct Q784 { int a; int b; int c; int d; };	// NOTE: placeholder element type

class WLInt784	// NOTE: placeholder name (weighted list of ints)
{
public:
	vector<int> values;
	vector<int> weights;
	int total;

	WLInt784(const int *w, int count);	// 0x9ba790
	~WLInt784();	// 0x700dd0
	int &pick() throw();	// 0x9ba470
	void remove(int value);	// 0x9bab80
};

class WLLoc784	// NOTE: placeholder name (weighted list of locations)
{
public:
	vector<HL784> values;
	vector<int> weights;
	int total;

	WLLoc784();	// 0x9ba440
	~WLLoc784();	// 0x787710
	void reset();	// 0x9c1be0
	void add(HL784 value, int weight);	// 0x9ba0d0
	unsigned int size();	// 0x9b81d0
	HL784 &pick();	// 0x9ba470
};

struct Rec784	// NOTE: placeholder layout (0xd21afc records)
{
	char pad0[0x28];
	Range784 range;
	int count;
	char pad34[0x80 - 0x34];
	vector<int> weights;
};

struct Rec2_784	// NOTE: placeholder layout (0xd2c408 records)
{
	char pad0[0xc0];
	vector<int> list;
};

struct Rec3_784	// NOTE: placeholder layout (0xcf7560 entries)
{
	int unknown00;
	string key;
	string text;
};

struct Flags784 { bool a; bool b; bool c; };	// NOTE: placeholder name

class PlayerData784	// NOTE: placeholder name (0xcf45d8)
{
public:
	void unknown779860();	// NOTE: placeholder name
};

class GameData122	// NOTE: placeholder name and layout (GameData at 0xd1e860)
{
public:
	unsigned int	seedHash;
	string	seed;	// +0x04
	bool	randomSeed;	// +0x20
	HL784	start;	// +0x24
	HL784	cur;	// +0x28
	vector<HL784>	path;	// +0x2c
	vector<Triple784>	list3c;
	vector<int>		list4c;
	int				unknown5c;
	vector<int>		list60;
	vector<int>		list70;
	vector<vector<int> >	list80;
	vector<vector<int> >	list90;
	char			padA0[0x100 - 0xa0];
	map<string,string>	textEntries;	// +0x100
	Grid784			grid110;
	vector<Obj784 *>	objects[15];	// +0x11c
	vector<int>		list20c;
	vector<HL784>	list21c;
	vector<string>	list22c;
	vector<int>		list23c;
	bool			flag24c;
	bool			flag24d;
	int				unknown250;
	int				unknown254;
	int				unknown258;
	bool			flag25c;
	bool			flag25d;
	int				exiScenario;	// +0x260
	int				unknown264;
	int				unknown268;
	bool			flag26c;
	int				unknown270;
	int				unknown274;
	int				unknown278;
	HL784			loc27c;
	int				unknown280;
	int				unknown284;
	Bounds784		bounds288;
	Bounds784		bounds298;
	int				unknown2a8;
	int				unknown2ac;
	int				unknown2b0;
	int				unknown2b4;
	bool			flag2b8;
	int				unknown2bc;
	int				unknown2c0;
	int				unknown2c4;
	int				unknown2c8;
	int				unknown2cc;
	int				unknown2d0;
	int				unknown2d4;
	int				unknown2d8;
	int				unknown2dc;
	int				unknown2e0;
	vector<int>		list2e4;
	int				unknown2f4;
	int				unknown2f8;
	int				unknown2fc;
	int				unknown300;
	int				unknown304;
	int				unknown308;
	int				unknown30c;
	int				unknown310;
	int				unknown314;
	vector<string>	list318;
	vector<int>		list328;
	bool			flag338;
	bool			flag339;
	vector<int>		list33c;
	int				unknown34c;
	Pos784			pos350;
	int				unknown358;
	bool			flag35c;
	int				unknown360;
	bool			flag364;
	int				unknown368;
	int				unknown36c;
	int				unknown370;
	bool			flag374;
	HL784			loc378;
	int				unknown37c;
	HL784			loc380;
	HL784			loc384;
	int				unknown388;
	bool			flag38c;
	bool			flag38d;
	bool			flag38e;
	int				unknown390;
	int				unknown394;
	int				unknown398;
	bool			flag39c;
	vector<HL784>	list3a0;
	vector<Pt784>	list3b0;
	vector<Pt784>	list3c0;
	vector<int>		list3d0;
	vector<int>		list3e0;
	int				unknown3f0;
	int				unknown3f4;
	int				unknown3f8;
	int				unknown3fc;
	int				unknown400;
	int				unknown404;
	int				unknown408;
	Pos784			pos40c;
	vector<Q784>	list414;
	vector<int>		list424;
	vector<int>		list434;

	void setEntryText(const string &key, const string &text);	// 0x46f700
	void unknown783ae0(bool reset);	// NOTE: placeholder name
	void unknown784410();	// NOTE: placeholder name
};

string gm784_intToString(int value);	// 0x4051f0
unsigned int gm784_hashSeedString(const string &seedText);	// 0x436c70
string gm784_randomString(vector<string> &v);	// 0x9d3280
void gm784_insert(vector<HL784> &v, int index, HL784 value);	// 0x9d8fc0
int gm784_minInt(int a, int b);	// 0x9cdb30
bool gm784_findNode(int type, int ID, HL784 node, HL784 *result);	// 0x470180
void gm784_collectNodes(int type, int sub, HL784 node, vector<HL784> &matches, vector<HL784> &visited);	// 0x46ff70
void gm784_eraseStep(vector<HL784> &v, int &index);	// 0x9d6440
void gm784_clearObjects(vector<Obj784 *> &v);	// 0x9d3f80
void gm784_appendVector(vector<HL784> &dest, vector<HL784> &src);	// 0x9d49c0
HL784 gm784_randomRecord(vector<HL784> &v);	// 0x9dafb0
bool gm784_containsInt(vector<int> &v, int value);	// 0x9db330

extern PlayerData784 gm784_cf45d8;
extern Factory784 *gm784_cefaa8;
extern bool gm784_cefaee;
extern bool gm784_cefad1;
extern bool gm784_cefaef;
extern string gm784_d28ce8;	// fixed seed text
extern int gm784_d035d4;	// seed length limit
extern vector<string> gm784_d204dc;	// seed word lists
extern vector<string> gm784_d2c444;
extern int gm784_caf130;
extern int gm784_cf462c;
extern bool gm784_d1e880;	// gameData.randomSeed
extern HL784 gm784_d1e884;	// gameData.start
extern bool gm784_cf474c;
extern bool gm784_d257e9;
extern bool gm784_d257e4;
extern bool gm784_d257e5;
extern bool gm784_d257ec;
extern int gm784_d25740;
extern int gm784_cf4724;
extern int gm784_cf4740;
extern int gm784_cf4718;
extern vector<Rec784 *> gm784_d21afc;
extern vector<Rec2_784 *> gm784_d2c408;
extern vector<Rec3_784 *> gm784_cf7560;
extern const int gm784_b943c0[];
extern const int gm784_b94390[];
extern const int gm784_b9393c[];
extern const int gm784_b943a8[];
extern const int gm784_b99adc[];
extern int gm784_ba6620[];
extern Range784 gm784_cf1f30[];
extern Flags784 gm784_ba6650[];
extern string gm784_cfe140[];
extern string gm784_d2d4ac;
extern vector<HL784> gm784_d323c8;
extern int gm784_cef67c;
extern int gm784_cec454;

void GameData122::unknown784410()
{
	gm784_cf45d8.unknown779860();
	if (gm784_cefaee || gm784_d28ce8 == "0")
	{
		randomSeed = true;
		do
		{
			seed = gm784_randomString(gm784_d2c444) + gm784_randomString(gm784_d2c444) + gm784_randomString(gm784_d204dc);
		}
		while (seed.size() > gm784_d035d4 - 2);
	}
	else
	{
		randomSeed = false;
		seed = gm784_d28ce8;
	}
	seedHash = gm784_hashSeedString(seed);
	if (gm784_cefaee || gm784_cefad1)
	{
		ofstream file((string() + "generated/seeds.txt").c_str(), ios::out | ios::app);
		file << "\n" << seed;
		file.close();
	}
	rng.seed(seedHash);

	if (gm784_caf130 == 6)
	{
		gm784_d1e884 = gm784_cefaa8->createB();
		gm784_d1e884->init(0, 0, 8, false);
		gm784_d1e884->known = true;
	}
	else if (gm784_cf462c == 6)
	{
		gm784_d1e884 = gm784_cefaa8->createB();
		gm784_d1e884->init(0x25, 5, 8, false);
		gm784_d1e884->known = true;
	}
	else
	{
		vector<HL784> entries;
		gm784_d1e884 = gm784_cefaa8->createB();
		gm784_d1e884->init(1, 11, 8, false);
		entries.push_back(gm784_d1e884);
		HL784 next = gm784_d1e884;
		HL784 door, old, child;

		cur = gm784_cefaa8->createB();
		cur->init(2, 10, 8, false);
		gm784_insert(entries, 0, cur);
		next->links.push_back(cur);
		next = cur;
		door = cur;

		cur = gm784_cefaa8->createB();
		cur->init(2, 9, 8, false);
		gm784_insert(entries, 0, cur);
		next->links.push_back(cur);
		next = cur;
		old = cur;

		cur = gm784_cefaa8->createB();
		cur->init(2, 8, 8, false);
		gm784_insert(entries, 0, cur);
		next->links.push_back(cur);
		next = cur;
		child = cur;

		cur = gm784_cefaa8->createB();
		cur->init(3, 7, 8, false);
		gm784_insert(entries, 0, cur);
		next->links.push_back(cur);
		next = cur;

		cur = gm784_cefaa8->createB();
		cur->init(3, 6, 8, false);
		gm784_insert(entries, 0, cur);
		next->links.push_back(cur);
		next = cur;

		cur = gm784_cefaa8->createB();
		cur->init(3, 5, 8, false);
		gm784_insert(entries, 0, cur);
		next->links.push_back(cur);
		next = cur;

		cur = gm784_cefaa8->createB();
		cur->init(3, 4, 8, false);
		gm784_insert(entries, 0, cur);
		next->links.push_back(cur);
		next = cur;

		cur = gm784_cefaa8->createB();
		cur->init(4, 3, 8, false);
		gm784_insert(entries, 0, cur);
		next->links.push_back(cur);
		next = cur;

		cur = gm784_cefaa8->createB();
		cur->init(4, 2, 8, false);
		gm784_insert(entries, 0, cur);
		next->links.push_back(cur);
		next = cur;

		cur = gm784_cefaa8->createB();
		cur->init(5, 1, 8, false);
		gm784_insert(entries, 0, cur);
		next->links.push_back(cur);
		next = cur;

		cur = gm784_cefaa8->createB();
		cur->init(6, 0, 8, false);
		gm784_insert(entries, 0, cur);
		next->links.push_back(cur);
		next = cur;

		cur = gm784_cefaa8->createB();
		cur->init(7, 10, 8, false);
		entries[10]->links.push_back(cur);
		cur->links.push_back(entries[9]);
		HL784 end = cur;

		cur = gm784_cefaa8->createB();
		cur->init(7, 9, 8, false);
		entries[9]->links.push_back(cur);
		cur->links.push_back(entries[8]);
		HL784 branch = cur;

		int loc = rng.rangeInt(9, 10);
		if (loc == 10)
		{
			end->links.push_back(gm784_cefaa8->createB());
			cur = end->links.back();
			cur->init(8, 10, 8, false);
			cur->links.push_back(branch);
		}
		else
		{
			branch->links.push_back(gm784_cefaa8->createB());
			cur = branch->links.back();
			cur->init(8, 9, 8, false);
			cur->links.push_back(gm784_cefaa8->createB());
			cur = cur->links.back();
			cur->init(7, 8, 8, false);
			cur->links.push_back(entries[8]);
		}

		loc = rng.rangeInt(7, 9);
		cur = gm784_cefaa8->createB();
		cur->init(9, loc, 8, false);
		entries[loc]->links.push_back(cur);
		cur->links.push_back(entries[loc - 1]);
		cur->links.push_back(gm784_cefaa8->createB());
		cur = cur->links.back();
		cur->init(10, loc, 8, false);
		cur->links.push_back(entries[loc - 2]);
		HL784 parent = cur;

		cur = gm784_cefaa8->createB();
		cur->init(11, loc, 8, false);
		cur->links.push_back(entries[gm784_minInt(6, loc - 2)]);
		parent->links.push_back(cur);

		cur = gm784_cefaa8->createB();
		cur->init(15, 10, 8, false);
		door->links.push_back(cur);
		end->links.push_back(cur);
		cur->links.push_back(child);
		cur->links.push_back(parent);

		vector<int> orders(4);
		orders[0] = gm784_d1e880 && !gm784_cf474c && !gm784_d257e9 ? 7 : rng.rangeInt(7, 6);
		orders[1] = orders[0] == 7 ? 6 : 7;
		orders[2] = rng.rangeInt(5, 4);
		orders[3] = orders[2] == 5 ? 4 : 5;
		for (int i = 20; i <= 23; i++)
		{
			loc = orders[i - 20];
			int type = loc <= 5 ? 17 : 16;
			cur = gm784_cefaa8->createB();
			cur->init(type, loc, 6, true);
			entries[loc]->links.push_back(cur);
			cur->links.push_back(gm784_cefaa8->createB());
			cur = cur->links.back();
			cur->init(type, loc, 6, false);
			cur->links.push_back(entries[loc - 1]);
			cur->links.push_back(gm784_cefaa8->createB());
			cur = cur->links.back();
			cur->init(i, loc, 8, false);
			if (i == 20)
			{
				cur->links.push_back(gm784_cefaa8->createB());
				HL784 side = cur->links.back();
				side->init(19, loc, 6, false);
				side->links.push_back(gm784_cefaa8->createB());
				side = side->links.back();
				side->init(18, loc - 1, 2, false);
				side->links.push_back(entries[loc - 1]);
			}
			cur->links.push_back(gm784_cefaa8->createB());
			cur = cur->links.back();
			cur->init(18, loc - 1, 2, false);
			cur->links.push_back(entries[loc - 1]);
		}

		loc = rng.rangeInt(6, 4);
		cur = gm784_cefaa8->createB();
		cur->init(24, loc, 8, false);
		entries[loc]->links.push_back(cur);
		cur->links.push_back(entries[loc - 1]);
		cur->links.push_back(gm784_cefaa8->createB());
		cur = cur->links.back();
		cur->init(25, loc, 8, false);
		cur->links.push_back(entries[loc - 1]);
		cur->links.push_back(gm784_cefaa8->createB());
		cur = cur->links.back();
		cur->init(26, loc, 8, false);
		cur->links.push_back(entries[loc - 1]);
		cur->links.push_back(gm784_cefaa8->createB());
		cur = cur->links.back();
		cur->init(27, loc, 8, false);
		cur->links.push_back(entries[loc - 1]);

		loc = rng.rangeInt(4, 3);
		cur = gm784_cefaa8->createB();
		cur->init(28, loc, 8, false);
		entries[loc]->links.push_back(cur);
		cur->links.push_back(entries[loc - 1]);
		cur->links.push_back(gm784_cefaa8->createB());
		cur = cur->links.back();
		cur->init(29, loc, 8, false);
		cur->links.push_back(entries[loc - 1]);

		int room = rng.rangeInt(3, 2);
		int width = room == 3 ? 2 : 3;
		int open = width == 3 ? 30 : rng.rangeInt(30, 31);
		for (int j = 30; j <= 31; j++)
		{
			loc = j == 30 ? room : width;
			cur = gm784_cefaa8->createB();
			cur->init(j, loc, 8, false);
			entries[loc]->links.push_back(cur);
			cur->links.push_back(entries[loc - 1]);
			if (j == open)
			{
				cur->links.push_back(gm784_cefaa8->createB());
				cur = cur->links.back();
				cur->init(32, loc, 8, false);
				cur->links.push_back(entries[loc - 1]);
				cur = entries[loc]->links.back();
				cur->links.push_back(gm784_cefaa8->createB());
				cur = cur->links.back();
				cur->init(33, loc, 8, false);
				cur->links.push_back(entries[loc - 1]);
			}
		}

		cur = gm784_cefaa8->createB();
		cur->init(34, 1, 8, false);
		entries[1]->links.push_back(cur);
		cur->links.push_back(entries[0]);
		cur->links.push_back(gm784_cefaa8->createB());
		cur = cur->links.back();
		cur->init(35, 1, 8, false);
		cur->links.push_back(entries[0]);
	}

	cur = start;
	path.clear();
	path.push_back(cur);
	list3c.clear();
	list3c.push_back(Triple784());
	list4c.clear();
	unknown5c = 10;
	list60.clear();
	list70.assign(302u, 0);
	list80.assign(11, vector<int>());

	WLLoc784 areas;
	vector<HL784> queue;
	vector<HL784> other;
	for (unsigned int i = 0; i < gm784_d21afc.size(); i++)
	{
		if (gm784_d21afc[i]->count < 0)
		{
			if (gm784_d21afc[i]->weights[13] != 0)
			{
				int k = -gm784_d21afc[i]->count;
				while (k != 0)
				{
					int d = gm784_d21afc[i]->range.y != 0 ? gm784_d21afc[i]->range.randomInRange() : rng.rangeInt(0, 10);
					list80[d].push_back(i);
					k--;
				}
			}
			else
			{
				areas.reset();
				for (int t = 0; t < 38; t++)
				{
					if (gm784_d21afc[i]->weights[t] != 0)
					{
						queue.clear();
						other.clear();
						gm784_collectNodes(t, -1, gm784_d1e884, queue, other);
						if (gm784_d21afc[i]->range.y != 0)
						{
							for (int q = 0; q < queue.size(); q++)
							{
								if (!gm784_d21afc[i]->range.contains(queue[q]->getDepth()))
									gm784_eraseStep(queue, q);
							}
						}
						for (unsigned int q = 0; q < queue.size(); q++)
							areas.add(queue[q], gm784_d21afc[i]->weights[t]);
					}
				}
				int k = -gm784_d21afc[i]->count;
				while (k != 0 && areas.size() != 0)
				{
					HL784 h = areas.pick();
					h->records.push_back(i);
					k--;
				}
			}
		}
	}

	list90.assign(gm784_d2c408.size(), vector<int>());
	for (unsigned int i = 0; i < gm784_d2c408.size(); i++)
		list90[i].assign(gm784_d2c408[i]->list.size(), 0);
	unknown783ae0(true);
	textEntries.clear();
	for (unsigned int i = 0; i < gm784_cf7560.size(); i++)
		setEntryText(gm784_cf7560[i]->key, gm784_cf7560[i]->text);
	grid110.init(19, 38, 0);
	for (int i = 0; i < 15; i++)
		gm784_clearObjects(objects[i]);
	list20c.assign(15u, 0);
	list21c.clear();
	list22c.clear();
	list23c.assign(11u, 0u);

	flag24c = false;
	flag24d = false;
	unknown250 = 0;
	unknown254 = 0;
	unknown258 = 0;
	bool found = gm784_d1e880 && !gm784_d257e4 && gm784_d25740 >= 6;
	if (gm784_cf4724 == 0 && gm784_cf4740 == 0 && gm784_cf462c != 4 && rng.chance(found ? 33 : 5))
	{
		flag24c = true;
		flag24d = found;
	}
	flag25c = false;
	flag25d = false;
	exiScenario = 0;
	bool ok = gm784_d1e880 && !gm784_d257e5 && gm784_d25740 >= 4;
	if (!flag24c && gm784_cf4724 == 0 && gm784_cf4740 == 0 && gm784_cf462c != 4 && rng.chance(ok ? 25 : 5))
	{
		flag25c = true;
		flag25d = ok;
	}
	if (ok || flag25c || gm784_caf130 != 7 || gm784_cf462c == 6)
		exiScenario = 0;
	else
	{
		HL784 h;
		gm784_findNode(8, -1, gm784_d1e884, &h);
		vector<HL784> hits;
		vector<HL784> visited;
		gm784_collectNodes(7, -1, gm784_d1e884, hits, visited);
		int last = 0;
		for (unsigned int i = 0; i < hits.size(); i++)
		{
			if (gm784_containsInt(hits[i]->records, 16))
			{
				last = hits[i]->depth;
				break;
			}
		}
		if (h->depth == last)
			exiScenario = 0;
		else
		{
			WLInt784 scenarios(gm784_b943c0, 4);
			exiScenario = scenarios.pick();
			if (gm784_cf462c == 8 && (exiScenario == 2 || exiScenario == 3))
				exiScenario = 0;
		}
	}
	setEntryText("exiScenario_g", gm784_intToString(exiScenario));

	unknown264 = -1;
	unknown268 = 0;
	flag26c = false;
	unknown270 = 0;
	unknown274 = 0;
	unknown278 = 0;
	loc27c.reset();
	if (rng.chance(15) && gm784_caf130 != 6)
	{
		int type = rng.chance(50) ? 16 : 17;
		vector<HL784> hits;
		vector<HL784> visited;
		gm784_collectNodes(type, -1, start, hits, visited);
		for (int i = 0; i < hits.size(); i++)
		{
			if (hits[i]->flag24)
				gm784_eraseStep(hits, i);
		}
		loc27c = gm784_randomRecord(hits);
	}
	unknown280 = 0;
	unknown284 = 0;
	bounds288.set(Pos784(-1));
	bounds298.set(Pos784(-1));
	unknown2a8 = 0;
	unknown2ac = rng.rangeInt(40, 160);
	unknown2b0 = 0;
	unknown2b4 = rng.rangeInt(20, 40);
	flag2b8 = false;
	unknown2bc = 0;
	unknown2c0 = 0;
	unknown2c4 = 0;
	unknown2c8 = 0;
	unknown2cc = 0;
	unknown2d0 = 0;
	unknown2d4 = 0;
	unknown2d8 = 0;
	unknown2dc = 0;
	unknown2e0 = 0;
	list2e4.assign(11u, 0u);
	unknown2f4 = 20;
	if (gm784_caf130 != 6)
	{
		HL784 h;
		gm784_findNode(11, -1, start, &h);
		if (h->depth == 7)
			unknown2f4 = 35;
	}
	unknown2f4 += gm784_ba6620[gm784_cf4718];
	unknown2f8 = 0;
	unknown2fc = 0;
	unknown300 = -1;
	unknown304 = 0;
	unknown308 = 0;
	unknown30c = 0;
	unknown310 = 0;
	unknown314 = 0;
	list318.clear();
	list328.assign(11u, 0);
	WLInt784 parts(gm784_b94390, 6);
	WLInt784 options(gm784_b9393c, 3);
	int counter = options.pick();
	while (counter != 0)
	{
		int value = parts.pick();
		parts.remove(value);
		int pos = gm784_cf1f30[value].randomInRange();
		while (list328[pos] != 0)
			pos = gm784_cf1f30[value].randomInRange();
		list328[pos] = value;
		counter--;
	}
	flag338 = false;
	flag339 = false;
	list33c.assign(11u, 0);
	WLInt784 traps(gm784_b943a8, 6);
	for (int i = 4; i <= 9; i++)
	{
		list33c[i] = traps.pick();
		if (list33c[i] != 0)
			traps.remove(list33c[i]);
	}
	unknown34c = 0;
	pos350 = Pos784(-1);
	unknown358 = 0;
	flag35c = false;
	unknown360 = 0;
	flag364 = false;
	unknown368 = rng.rangeInt(450, 600);
	if (!gm784_d257ec && gm784_d1e880)
		unknown368 = 700;
	unknown36c = 0;
	unknown370 = rng.rangeInt(0, 2);
	flag374 = false;
	loc378.reset();
	unknown37c = -1;
	loc380.reset();
	loc384.reset();
	unknown388 = 0;
	flag38c = false;
	flag38d = false;
	flag38e = false;
	WLInt784 tags(gm784_b99adc, 6);
	unknown390 = tags.pick();
	for (int i = 4; i < 6; i++)
		tags.remove(i);
	unknown394 = tags.pick();
	unknown398 = 0;
	flag39c = false;
	list3a0.clear();
	list3b0.clear();
	list3c0.clear();
	list3d0.clear();
	list3e0.clear();
	unknown3f0 = -1;
	unknown3f4 = 0;
	unknown3f8 = -1;
	unknown3fc = 0;
	unknown400 = 0;
	unknown404 = -1;
	unknown408 = 0;
	pos40c.set(-1);
	list414.clear();
	list424.clear();
	list434.clear();
	if (rng.chance(90))
		setEntryText("zhirovInHideout_g", "1");
	if (gm784_cefaef)
	{
		gm784_d323c8.clear();
		gm784_cef67c = 0;
		gm784_cec454 = 0;
		for (int i = 2; i < 38; i++)
		{
			if (!gm784_ba6650[i].a && i != 6 && (gm784_d2d4ac.empty() || gm784_cfe140[i] == gm784_d2d4ac))
			{
				vector<HL784> hits;
				vector<HL784> visited;
				gm784_collectNodes(i, -1, gm784_d1e884, hits, visited);
				gm784_appendVector(gm784_d323c8, hits);
			}
		}
	}
}
