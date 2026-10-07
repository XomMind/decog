// team_c_38: Scorekeeper scoresheet data snapshot (0x4852a0): copies the run's state (header, parts, favorites, route,
//	history, messages, options...) into the scoresheet data block that the text scoresheet and protobuf read
// NOTE: class/member names are placeholders (f<offset>); helper classes and globals are private placeholders
#include <string>
#include <vector>
using namespace std;

string intToString(int value);
string opR1d_436e70(int unknown1, int unknown2, int unknown3);	// NOTE: placeholder name (date/time string)
string opw8_countString(int count, const string &noun);	// NOTE: placeholder name
int OpX5_minInt(int a, int b);
int OpX5_maxInt(int a, int b);
int OpT8a_sumVector(vector<int> &v);
int OpS8b_Fn9d43f0(vector<int> &v, int first, int last);	// NOTE: placeholder name
int OpS8b_Fn9d4500(vector<int> &v);	// NOTE: placeholder name
void OpS8b_Fn9d4560(char *dst, char *src, unsigned int size);	// NOTE: placeholder name
bool OpV4c_Fn9d3f40(int *list, unsigned int count);	// NOTE: placeholder name
void OpU8a_insertString(vector<string> &v, int index, string s);	// NOTE: placeholder name
class HEntity { public: int ID; bool operator==(HEntity other) const; struct C38_Location *get23c(); };	// NOTE: placeholder layout
template <class T> void OpQ5_eraseStep(vector<T> &v, unsigned int &index);
bool OpU8a_containsEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name
template <class T> void OpX5_insertAt(vector<T> &v, int index, T value);
extern string gameStrings_d2f508[], gameStrings_cf6f30[], gameStrings_cfaca0[], gameStrings_d37ec0[], gameStrings_cfb0c8[], gameStrings_d20b98[], gameStrings_d307d0[];	// global_string_arrays.cpp

struct C38_Exit { int map; bool known; bool reached; int count; };	// NOTE: placeholder layout
struct C38_Location { char pad0[4]; int f4; int f8; char padc[0x25 - 0xc]; bool f25; char pad26[0x40 - 0x26]; vector<HEntity> exits; vector<HEntity> visited; };	// NOTE: placeholder layout
struct C38_Snapshot { char pad[0xc8]; void unknown483d30(HEntity player, bool isDump); };	// NOTE: placeholder (cogmind state block)
struct C38_Stats { vector<int> *values; vector<vector<int> *> maps; vector< vector<string> > lists; void update472db0(); int delegate(int index); void sort472cc0(vector<int> &list); void collectStats_472e90(); };	// NOTE: placeholder (OpR1h_Stats)
struct C38_Named { char pad0[0x24]; string f24; char pad40[0x44 - 0x40]; int f44; int f48; char pad4c[0x23b - 0x4c]; bool f23b; string getPrefixedName(int *count); string unknown55e9c0(bool flag, int &count); };	// NOTE: placeholder
struct C38_Tri { vector<int> items; char pad10[0x10]; vector<int> counts; C38_Tri(const C38_Tri &o); ~C38_Tri(); void merge(); string getName7787b0(int index); bool empty() const; };	// NOTE: placeholder (OpR1g_Triple)
struct C38_Entity { string unknown5c9c30(); };
class C38_PlayerHandle { public: int ID; C38_Entity *operator->() const; };
struct C38_Rec { char pad0[8]; HEntity f8; char padc; bool fd; bool fe; char padf[0x1c - 0xf]; int f1c; };	// NOTE: placeholder
struct C38_Map { C38_PlayerHandle getPlayer(); vector<C38_Rec *> *getRecords(); int getTurn(); void unknown735620(); };	// NOTE: placeholder (Map)
struct C38_Event { int f0; int f4; int f8; string getText514060(); };	// NOTE: placeholder
struct C38_EventType { char pad0[0x28]; bool f28; };
struct C38_Source { char pad0[0x48]; bool f48; };
struct C38_Msg { C38_Source *f0; string f4; };	// NOTE: placeholder
struct C38_Log { vector<C38_Msg *> *get_mutable(); };
struct C38_Record20 { char pad0[0x20]; string f20; };
struct C38_Fab { char pad0[8]; string f8; char pad24[0x2c - 0x24]; int f2c; int f30; };
struct C38_Machine { char pad0[0x1ac]; string f1ac; };
struct C38_Lists { char pad0[0x10]; vector< vector<int> > f10; };
struct C38_GameData { int unknown46f530(); };
struct C38_GM { unsigned int unknown470aa0(int a); };
struct C38_Meta { int getLoreCollectionPercent(); int getGalleryCollectionPercent(); int percent(); };
struct C38_Config { string getName(); string colorFiltersToString(int which); };
struct C38_Flags { string f0; bool getField(); };	// NOTE: placeholder (PlayerData)

extern C38_Map *c38_cefc4c;	// NOTE: placeholder names below
extern C38_Stats c38_d2c658;
extern C38_Flags c38_cf45d8;
extern int c38_cf4718, c38_cf462c, c38_cf4b38, c38_cf4c24, c38_cf4c20, c38_cf4d10, c38_cf4614, c38_cebd5c, c38_cefab4, c38_cefab8, c38_cf4cf8, c38_cf4cfc, c38_d25660, c38_cf45f4;
extern int c38_d25740, c38_d25744, c38_d25748, c38_d2574c, c38_bbc218[], c38_cf471c[];
extern string c38_d21928, c38_d29ab4, gameStrings_cefd78[];
extern string c38_cf4b3c, c38_cf45f8, c38_d25664, c38_d1e864, c38_d2d490;
extern char c38_d25680[];
extern C38_Tri c38_cf4784;
extern vector<C38_Tri> c38_d1e89c;
extern vector<int> c38_cf4bf0, c38_cf4c00, c38_cf4c10, c38_cf4c28, c38_cf4bd0, c38_cf4858, c38_cf4868, c38_cf4878, c38_cf489c, c38_cf48ac, c38_cf48bc, c38_cf48e0, c38_cf48f0, c38_cf4900, c38_cf47ec, c38_cf4644, c38_cf4654, c38_d25750, c38_cf4ce8, c38_cf4cd8;
extern vector<string> c38_cf4bc0, c38_cf4c38, c38_cf4c88;
extern vector<int> c38_cf4c48, c38_cf4c58, c38_cf4c68, c38_cf4c78, c38_cf4c98, c38_cf4ca8, c38_cf4cb8, c38_cf4cc8;
extern vector<C38_Named *> c38_d2d1c4;
extern vector<HEntity> c38_d1e88c;
extern vector<C38_Event *> c38_cf4d00;
extern vector<C38_EventType *> c38_cf08c4;
extern C38_Log c38_cf1080;
extern vector<C38_Machine *> c38_d25de0;
extern C38_Lists *c38_cf68a8;
extern vector<C38_Record20 *> c38_cf09a8;
extern vector<C38_Fab *> c38_cf4be0;
extern C38_GameData c38_d1e860;
extern bool c38_d1e880, c38_d28d30, c38_d28c8a, c38_d28fbd, c38_d28c88, c38_d28c89, c38_d28d16;
extern C38_GM *c38_cefaa8;
extern C38_Meta c38_d25628;
extern C38_Config c38_d28c68;

class C38_Sheet	// NOTE: placeholder layout (scoresheet data, Scorekeeper+0x34)
{
public:
	int f0;
	bool f4;
	bool f5;
	bool f6;
	string f8;
	string f24;
	string f40;
	string f5c;
	string f78;
	string f94;
	string fb0;
	vector<int> fcc;
	int fdc;
	C38_Snapshot fe0;
	int f1a8;
	vector< vector<string> > f1ac;
	vector< vector<int> > f1bc;
	vector<int> f1cc;
	vector<string> f1dc;
	vector<int> f1ec;
	int f1fc;
	vector<string> f200;
	vector<string> f210;
	vector<string> f220;
	vector<int> f230;
	vector<string> f240;
	int f250;
	vector<int> f254;
	vector<string> f264;
	vector<int> f274;
	vector<int> f284;
	vector< vector<int> > f294;
	vector<string> f2a4;
	vector< vector<C38_Exit> > f2b4;
	vector<int> f2c4;
	vector<int> f2d4;
	vector<string> f2e4;
	vector<string> f2f4;
	vector<string> f304;
	vector<int> f314;
	vector<int> f324;
	vector<string> f334;
	vector<int> f344;
	vector<int> f354;
	vector<string> f364;
	vector<int> f374;
	vector<int> f384;
	vector<int> f394;
	vector<int> f3a4;
	vector<string> f3b4;
	vector<int> f3c4;
	vector<int> f3d4;
	vector<int> f3e4;
	vector<int> f3f4;
	vector<string> f404;
	vector<int> f414;
	vector<int> f424;
	vector< vector<int> > f434;
	vector<string> f444;
	vector<string> f454;
	vector<string> f464;
	vector<string> f474;
	vector<int> f484;
	vector<string> f494;
	vector<int> f4a4;
	vector<int> f4b4;
	string f4c4;
	bool f4e0;
	unsigned int f4e4;
	unsigned int f4e8;
	string f4ec;
	string f508;
	int f524;
	int f528;
	string f52c;
	int f548;
	int f54c;
	int f550;
	int f554;
	int f558;
	int f55c;
	vector<int> f560;
	int f570;
	int f574;
	int f578;
	bool f57c;
	int f580;
	bool f584;
	bool f585;
	int f588;
	bool f58c;
	int f590;
	string f594;
	int f5b0;
	int f5b4;
	int f5b8;
	bool f5bc;
	string f5c0;
	string f5dc;
	int f5f8;
	string f5fc;
	char f618[0x20];
	string f638;
	int f654;
	int f658;

	void snapshot_4852a0(bool isDump);	// NOTE: placeholder name
};

void C38_Sheet::snapshot_4852a0(bool isDump)
{
	C38_Event *center;
	int allies;
	int base;
	if (c38_cefc4c->getPlayer().operator->())
		fe0.unknown483d30(*(HEntity *)&c38_cefc4c->getPlayer(),isDump);
	if (!isDump)
		c38_d2c658.update472db0();
	f0 = c38_cf45d8.getField() ? 3 : c38_cf4718;
	f4 = (*c38_d2c658.values)[74];
	f5 = (*c38_d2c658.values)[89];
	f6 = (*c38_d2c658.values)[102];
	f8 = c38_d21928;
	f24 = c38_cf45d8.getField() ? c38_d29ab4 : gameStrings_cefd78[c38_cf4718];
	f40 = c38_cf462c != 0 ? string(gameStrings_d2f508[c38_cf462c]) : string();
	string amount = opR1d_436e70(0,0,0);
	f5c = string(amount.begin(),amount.begin() + amount.find('-'));
	f78 = string(amount.begin() + amount.find('-') + 1,amount.end());
	f94 = c38_d28c68.getName();
	if (isDump)
	{
		fb0 = "(";
		if (!c38_cf4784.empty())
			fb0 += c38_cf4784.getName7787b0(-1) + " build in progress, ";
		fb0 += "the current situation is... ";
		fb0 += c38_cefc4c->getPlayer()->unknown5c9c30() + ")";
	}
	else
		fb0 = c38_cf4b3c.empty() ? gameStrings_cf6f30[c38_cf4b38] : c38_cf4b3c;
	fcc.assign(7,0);
	for (int cols = 0; cols <= 6; cols++)
		fcc[cols] = c38_d2c658.delegate(cols) * c38_bbc218[cols];
	fdc = OpT8a_sumVector(fcc);
	if (!isDump)
		c38_d2c658.collectStats_472e90();
	f1a8 = c38_cf4c24;
	f1ac.clear();
	f1bc.clear();
	c38_d2c658.sort472cc0(c38_cf4bf0);
	for (int cols = 0; cols < 4; cols++)
	{
		f1ac.push_back(vector<string>());
		f1bc.push_back(vector<int>());
		for (unsigned int distanceSq = 0; distanceSq < c38_cf4bf0.size(); distanceSq++)
		{
			if (c38_d2d1c4[c38_cf4bf0[distanceSq]]->f48 == cols)
			{
				f1bc[cols].push_back(0);
				f1ac[cols].push_back(c38_d2d1c4[c38_cf4bf0[distanceSq]]->getPrefixedName(&f1bc[cols].back()));
			}
		}
	}
	f1cc = c38_cf4c00;
	f1dc.clear();
	f1ec.clear();
	c38_d2c658.sort472cc0(c38_cf4c10);
	for (unsigned int cols = 0; cols < c38_cf4c10.size(); cols++)
	{
		f1ec.push_back(0);
		f1dc.push_back(c38_d2d1c4[c38_cf4c10[cols]]->unknown55e9c0(!isDump,f1ec.back()));
	}
	f1fc = c38_cf4c20;
	f200.assign(4,string());
	f210.assign(31,string());
	vector<int> areas(4u,0);
	vector<int> active(31u,0);
	for (unsigned int cols = 0; cols < c38_d2d1c4.size(); cols++)
	{
		base = c38_d2d1c4[cols]->f48;
		if (base < 4 && c38_cf4c28[cols] > areas[base])
		{
			f200[base] = c38_d2d1c4[cols]->f23b ? string("Constructs") : c38_d2d1c4[cols]->getPrefixedName(0);
			areas[base] = c38_cf4c28[cols];
		}
		allies = OpX5_minInt(c38_d2d1c4[cols]->f44,29);
		if (allies > 3 && c38_cf4c28[cols] > active[allies])
		{
			f210[allies] = c38_d2d1c4[cols]->f23b ? string("Constructs") : c38_d2d1c4[cols]->getPrefixedName(0);
			active[allies] = c38_cf4c28[cols];
		}
	}
	f220.clear();
	f230.clear();
	if (!c38_cf4784.empty())
	{
		C38_Tri cols(c38_cf4784);
		cols.merge();
		int distanceSq = OpT8a_sumVector(cols.counts);
		int behaviour;
		for (unsigned int distances = 0; distances < cols.items.size(); distances++)
		{
			behaviour = cols.counts[distances] * 100 / distanceSq;
			if (behaviour <= 2)
				break;
			f220.push_back(cols.getName7787b0(distances));
			f230.push_back(behaviour);
		}
	}
	f240.clear();
	for (unsigned int cols = 0; cols < c38_d1e89c.size(); cols++)
	{
		if (c38_d1e89c[cols].empty())
		{
			if (!f240.empty())
				f240.push_back(f240.back());
			else
				f240.push_back(string());
		}
		else
		{
			c38_d1e89c[cols].merge();
			f240.push_back(c38_d1e89c[cols].getName7787b0(0));
		}
	}
	(*c38_d2c658.values)[206] = (*c38_d2c658.values)[206] > 0 ? OpX5_maxInt(1,(*c38_d2c658.values)[206] * 100 / c38_cefc4c->getTurn()) : 0;
	for (unsigned int cols = 0; cols < c38_d2c658.maps.size(); cols++)
	{
		int distanceSq = (*c38_d2c658.maps[cols])[206];
		(*c38_d2c658.maps[cols])[206] = (*c38_d2c658.maps[cols])[206] > 0 ? OpX5_maxInt(1,(*c38_d2c658.maps[cols])[206] * 100 / (*c38_d2c658.maps[cols])[1006]) : 0;
	}
	f264 = c38_cf4bc0;
	f274 = c38_cf4bd0;
	int a1 = OpS8b_Fn9d43f0(*c38_d2c658.values,525,532);
	for (int cols = 525; cols <= 532; cols++)
		(*c38_d2c658.values)[cols] = a1 != 0 ? (*c38_d2c658.values)[cols] * 100 / a1 : 0;
	for (unsigned int cols = 0; cols < c38_d2c658.maps.size(); cols++)
	{
		a1 = OpS8b_Fn9d43f0(*c38_d2c658.maps[cols],525,532);
		for (int distanceSq = 525; distanceSq <= 532; distanceSq++)
			(*c38_d2c658.maps[cols])[distanceSq] = a1 != 0 ? (*c38_d2c658.maps[cols])[distanceSq] * 100 / a1 : 0;
	}
	f2a4.clear();
	f2b4.clear();
	vector< vector<HEntity> > adj;
	vector< vector<HEntity> > col;
	for (unsigned int cols = 0; cols < c38_d1e88c.size(); cols++)
	{
		adj.push_back(c38_d1e88c[cols].get23c()->exits);
		col.push_back(c38_d1e88c[cols].get23c()->visited);
	}
	vector<C38_Rec *> *bonus = c38_cefc4c->getRecords();
	for (unsigned int cols = 0; cols < bonus->size(); cols++)
	{
		if ((*bonus)[cols]->f1c != 4)
		{
			if ((*bonus)[cols]->fd)
				adj.back().push_back((*bonus)[cols]->f8);
			if ((*bonus)[cols]->fe)
				col.back().push_back((*bonus)[cols]->f8);
		}
	}
	for (unsigned int cols = 0; cols < adj.size(); cols++)
	{
		string distanceSq;
		distanceSq += "-" + intToString(c38_d1e88c[cols].get23c()->f8) + "/" + gameStrings_cfaca0[c38_d1e88c[cols].get23c()->f4];
		f2b4.push_back(vector<C38_Exit>());
		if (adj[cols].size() > (cols == adj.size() - 1 && c38_cf4b38 > 9 ? 0 : 1))
		{
			distanceSq += " (discovered " + opw8_countString(adj[cols].size(),"exit") + ": ";
			for (unsigned int distances = 0; distances < adj[cols].size(); distances++)
			{
				f2b4.back().push_back(C38_Exit());
				int enemies = 1;
				for (unsigned int found = distances + 1; found < adj[cols].size(); found++)
				{
					if (adj[cols][distances] == adj[cols][found])
					{
						enemies++;
						OpQ5_eraseStep(adj[cols],found);
					}
				}
				if (distances != 0)
					distanceSq += " / ";
				bool facing = OpU8a_containsEntity(col[cols],adj[cols][distances]);
				f2b4.back().back().map = adj[cols][distances].get23c()->f4;
				f2b4.back().back().reached = facing;
				if (adj[cols][distances].get23c()->f25)
				{
					if (facing)
						distanceSq += "*";
					distanceSq += gameStrings_d37ec0[adj[cols][distances].get23c()->f4];
					if (enemies > 1)
						distanceSq += " x" + intToString(enemies);
					f2b4.back().back().known = true;
					f2b4.back().back().count = enemies;
				}
				else
				{
					distanceSq += facing ? "[*" : "[";
					if (isDump)
						distanceSq += "???";
					else
					{
						distanceSq += gameStrings_d37ec0[adj[cols][distances].get23c()->f4];
						if (enemies > 1)
							distanceSq += " x" + intToString(enemies);
					}
					distanceSq += "]";
					f2b4.back().back().known = false;
					f2b4.back().back().count = enemies;
				}
			}
			distanceSq += ")";
		}
		f2a4.push_back(distanceSq);
	}
	if (c38_cf4b38 <= 9)
		f2a4.push_back(gameStrings_cfb0c8[c38_cf4b38]);
	f2c4.clear();
	f2d4.clear();
	f2e4.clear();
	for (int cols = 0; cols < c38_cf4d00.size(); cols++)
	{
		center = c38_cf4d00[cols];
		f2c4.push_back(center->f4);
		f2d4.push_back(center->f8);
		if (!isDump || !c38_cf08c4[center->f0]->f28 || cols < c38_cf4d10)
			f2e4.push_back(center->getText514060());
	}
	if (!isDump && c38_cf4b38 > 9)
	{
		f2c4.push_back(c38_cefc4c->getTurn());
		f2d4.push_back(c38_d1e860.unknown46f530());
		f2e4.push_back(fb0);
	}
	f2f4.clear();
	vector<C38_Msg *> *bottom = c38_cf1080.get_mutable();
	if (!bottom->empty())
	{
		for (int cols = bottom->size() - 1, behaviour = 0; cols >= 0 && behaviour < 20; cols--, behaviour++)
		{
			if ((*bottom)[cols]->f0 == NULL || (*bottom)[cols]->f0->f48)
				continue;
			if ((*bottom)[cols]->f4.empty() || (*bottom)[cols]->f4 == " ")
				break;
			OpU8a_insertString(f2f4,0,(*bottom)[cols]->f4);
		}
	}
	f304.clear();
	f314 = c38_cf4868;
	f324.clear();
	for (unsigned int cols = 0; cols < c38_cf4858.size(); cols++)
	{
		f304.push_back(c38_d2d1c4[c38_cf4858[cols]]->f24);
		f324.push_back(c38_cf4878[cols]);
	}
	f334.clear();
	f344 = c38_cf48ac;
	f354.clear();
	for (unsigned int cols = 0; cols < c38_cf489c.size(); cols++)
	{
		f334.push_back(c38_d25de0[c38_cf489c[cols]]->f1ac);
		f354.push_back(c38_cf48bc[cols]);
	}
	f364 = c38_cf4c38;
	f374 = c38_cf4c48;
	f384 = c38_cf4c58;
	f394 = c38_cf4c68;
	f3a4 = c38_cf4c78;
	f3b4 = c38_cf4c88;
	f3c4 = c38_cf4c98;
	f3d4 = c38_cf4ca8;
	f3e4 = c38_cf4cb8;
	f3f4 = c38_cf4cc8;
	f404.clear();
	f414 = c38_cf48f0;
	f424.clear();
	for (unsigned int cols = 0; cols < c38_cf48e0.size(); cols++)
	{
		f404.push_back(c38_d2d1c4[c38_cf48e0[cols]]->f24);
		f424.push_back(c38_cf4900[cols]);
	}
	f434.clear();
	if (c38_cf68a8 != NULL)
		f434 = c38_cf68a8->f10;
	f444 = c38_d2c658.lists[5];
	f454.clear();
	vector<int> child;
	for (unsigned int cols = 0; cols < c38_cf47ec.size(); cols++)
	{
		if (child.empty() || c38_cf09a8[c38_cf47ec[cols]]->f20 > c38_cf09a8[child.back()]->f20)
			child.push_back(c38_cf47ec[cols]);
		else
		{
			for (unsigned int distanceSq = 0; distanceSq < child.size(); distanceSq++)
			{
				if (c38_cf09a8[c38_cf47ec[cols]]->f20 < c38_cf09a8[child[distanceSq]]->f20)
				{
					OpX5_insertAt(child,distanceSq,c38_cf47ec[cols]);
					break;
				}
			}
		}
	}
	for (unsigned int cols = 0; cols < child.size(); cols++)
		f454.push_back(c38_cf09a8[child[cols]]->f20);
	f464.clear();
	if (OpV4c_Fn9d3f40(c38_cf471c,12))
	{
		for (int distanceSq = 0; distanceSq < 12; distanceSq++)
		{
			if (c38_cf471c[distanceSq] != 0)
				f464.push_back(gameStrings_d20b98[distanceSq]);
		}
	}
	f474.clear();
	for (unsigned int cols = 0; cols < c38_cf4644.size(); cols++)
		f474.push_back(c38_d2d1c4[c38_cf4644[cols]]->f24);
	f484 = c38_cf4654;
	if (c38_cf462c == 7)
	{
		vector<int> distanceSq;
		distanceSq.push_back(370);
		distanceSq.push_back(433);
		distanceSq.push_back(223);
		vector<int> behaviour;
		behaviour.push_back(1102);
		behaviour.push_back(1105);
		behaviour.push_back(1107);
		vector<int> distances;
		distances.push_back(1103);
		distances.push_back(1106);
		distances.push_back(1108);
		for (unsigned int enemies = 0; enemies < distanceSq.size(); enemies++)
		{
			int facing;
			if (facing = (*c38_d2c658.values)[distanceSq[enemies]] + (*c38_d2c658.values)[behaviour[enemies]])
				(*c38_d2c658.values)[distances[enemies]] = (*c38_d2c658.values)[behaviour[enemies]] * 100 / facing;
			for (unsigned int found = 0; found < c38_d2c658.maps.size(); found++)
			{
				if (facing = (*c38_d2c658.maps[found])[distanceSq[enemies]] + (*c38_d2c658.maps[found])[behaviour[enemies]])
					(*c38_d2c658.maps[found])[distances[enemies]] = (*c38_d2c658.maps[found])[behaviour[enemies]] * 100 / facing;
			}
		}
	}
	f494.clear();
	f4a4.clear();
	f4b4.clear();
	for (unsigned int cols = 0; cols < c38_cf4be0.size(); cols++)
	{
		f494.push_back(c38_cf4be0[cols]->f8);
		f4a4.push_back(c38_cf4be0[cols]->f30);
		f4b4.push_back(c38_cf4be0[cols]->f2c);
	}
	if (!isDump)
		c38_cefc4c->unknown735620();
	f4c4 = c38_d1e864;
	f4e0 = !c38_d1e880;
	f4e4 = c38_cefaa8->unknown470aa0(0);
	f4e8 = c38_d2574c + (isDump ? f4e4 / 60 : 0);
	f4ec = string(c38_cf45d8.f0.begin(),c38_cf45d8.f0.begin() + c38_cf45d8.f0.find('-'));
	f508 = string(c38_cf45d8.f0.begin() + c38_cf45d8.f0.find('-') + 1,c38_cf45d8.f0.end());
	f524 = c38_cf4cd8.size() - 1;
	f528 = c38_cf4614;
	f52c = gameStrings_d307d0[c38_cf4718];
	f548 = c38_d25740;
	f54c = c38_d25740 - c38_d25744 - c38_d25748;
	f550 = c38_d25744;
	f554 = c38_d25748;
	f558 = c38_cf4b38 <= 9 ? c38_cf4b38 : -1;
	f55c = OpT8a_sumVector(c38_d25750);
	f560 = c38_d25750;
	f570 = c38_d25628.getLoreCollectionPercent();
	f574 = c38_d25628.getGalleryCollectionPercent();
	f578 = c38_d25628.percent();
	f57c = c38_cf45d8.getField();
	f580 = c38_cebd5c;
	f584 = !c38_d28d30;
	f585 = c38_d28c8a;
	f588 = OpS8b_Fn9d4500(c38_cf4ce8);
	f58c = c38_d28fbd;
	f590 = c38_d28c88 ? (c38_d28c89 != 0) + 1 : 0;
	f594 = c38_d2d490;
	f5b0 = c38_cefab4;
	f5b4 = c38_cefab8;
	f5b8 = c38_cf4cfc != 0 ? c38_cf4cf8 * 100 / c38_cf4cfc : 0;
	f5bc = c38_d28d16;
	f5c0 = c38_d28c68.colorFiltersToString(77);
	f5dc = c38_d28c68.colorFiltersToString(78);
	f5f8 = 0;
	f5fc = c38_cf45f8;
	OpS8b_Fn9d4560(c38_d25680,f618,32);
	f638 = c38_d25664;
	f654 = c38_d25660;
	f658 = c38_cf45f4;
}
