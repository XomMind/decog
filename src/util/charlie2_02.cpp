// PlayerData reset for a new run (0x779af0, called from GM::readyGame on the PlayerData global at 0xcf45d8).
// NOTE: placeholder names and layouts throughout (C2PD*); helper vector types are private views whose
// methods stay stubs and pair with the exe's (folded) STL bodies by address.
#include <string>
#include <vector>
using namespace std;

class RNG { public: int rangeInt(float, float); };
extern RNG rng;

struct C2PDVec	// NOTE: placeholder (int/pointer vector view, 0x10 bytes)
{
	int pad[4];
	void clear();
	void push_back(const float &v);
	void assign(unsigned n, const int &v);
	int &operator[](unsigned i);
};
struct C2PDVecH { int pad[4]; void clear(); };	// NOTE: placeholder (vector<HEntity>)
struct C2PDVecS { int pad[4]; void clear(); };	// NOTE: placeholder (vector<string>)
typedef vector<unsigned> C2PDUVec;
struct C2PDVecV { int pad[4]; void assign(unsigned n, const C2PDUVec &v); };
struct C2PDHandle { int id; void reset(); };
struct C2PDCalls { int pad[0xc]; void reset46cc60(); };
struct C2PDPush { char pad[8]; void operate(int v); };
struct C2PDObjD8 { ~C2PDObjD8(); };
struct C2PDObj128 { ~C2PDObj128(); };
struct C2PDObj4F0 { ~C2PDObj4F0(); };

struct C2PDRecA { int f0; string name; char p20[0xc]; int level; };
struct C2PDRecB { char p0[0x94]; int f94; };
struct C2PDRecC { char p0[0xb4]; int fb4, fb8; char pbc[0x1c8 - 0xbc]; int f1c8; char p1cc[0x1dc - 0x1cc];
	int f1dc; int f1e0; int f1e4, f1e8, f1ec, f1f0; char p1f4[0x21c - 0x1f4]; int f21c, f220, f224, f228; };
struct C2PDRecU { char p0[0x78]; int f78; char p7c[0x94 - 0x7c]; int f94, f98, f9c, fa0, fa4; };
struct C2PDList { unsigned size() const; void *&operator[](unsigned i); };

struct C2PDGameData { void setEntryText(const string &key, const string &value); };
struct C2PDStats { bool add4729d0(unsigned id, int value, string text, int extra); };
struct C2PDOptions { bool get470b30(); };

extern C2PDGameData c2pd_d1e860;
extern C2PDStats c2pd_d2c658;
extern C2PDOptions *c2pd_cefaa8;
extern C2PDList c2pd_d25de0, c2pd_d257b0, c2pd_cf09a8, c2pd_cf08c4, c2pd_d2d1c4, c2pd_d35b58, c2pd_cf3a20;
extern int c2pd_ba76bc[], c2pd_ba7ab4[], c2pd_ba652c[], c2pd_ba6538[], c2pd_ba659c[];
extern int c2pd_ba64d8[7][3];
extern float c2pd_ba0498[];
extern const float c2pd_c36fb4, c2pd_c36fb8, c2pd_c36fb0;
extern string c2pd_d2f4a0[], c2pd_cf2820[];
extern int c2pd_d28d0c, c2pd_cefb48, c2pd_cf462c, c2pd_caf440, c2pd_caf444, c2pd_caf448, c2pd_caf44c, c2pd_cefb4c,
	c2pd_caf2b8, c2pd_d25744, c2pd_d25748, c2pd_d1e8bc;
extern bool c2pd_cefacd;
extern const char c2pd_bb95b2b[], c2pd_bf5cf8[], c2pd_bf5d00[], c2pd_bf5d0c[], c2pd_bf5d10[], c2pd_bf5d14[],
	c2pd_bf5d24[], c2pd_bf5d28[], c2pd_bf5d2c[], c2pd_bf5d3c[], c2pd_bf5d40[], c2pd_bf5d44[], c2pd_bf5d54[],
	c2pd_bf5d68[], c2pd_bf5d80[];

string c2pd_date436e70(bool b, __int64 t);
string c2pd_text436bc0();
string c2pd_text465db0();
string intToString(int v);
void logMessage(string message);
bool c2pd_find9d7530(C2PDList &list, const string &name, C2PDRecU *&out);
int c2pd_index9d7b80(C2PDList &list, string &name);
int c2pd_count9de8f0(C2PDVec &v);
void c2pd_clear9e2c40(C2PDVec &v);
void c2pd_clear9d8e70(C2PDVec &v);
void c2pd_clear9ed890(C2PDVec &v);
void c2pd_fill9e2be0(int *p, int n, int v);

class C2PlayerData	// NOTE: placeholder layout (PlayerData at 0xcf45d8)
{
public:
	string	s00;
	int		i1c;
	string	s20;
	int		i3c;
	C2PDHandle h40;
	int		i44;
	bool	b48;
	int		i4c;
	bool	b50;
	int		mode;	// +0x54
	int		i58;
	C2PDVec	v5c, v6c, v7c;
	int		i8c, i90, i94, i98, i9c, ia0;
	C2PDVec	va4;
	bool	bb4;
	int		ib8, ibc, ic0, ic4;
	bool	bc8;
	int		icc, id0, id4;
	C2PDObjD8 *pd8;
	C2PDVecH vdc;
	C2PDVec	vec;
	C2PDVecH vfc;
	C2PDVec	v10c;
	int		i11c;
	float	f120;
	int		i124;
	C2PDObj128 *p128;
	C2PDVec	v12c;
	char	p13c[4];
	int		difficulty;	// +0x140
	int		i144;
	char	p148[0x158 - 0x148];
	int		i158;
	char	p15c[0x175 - 0x15c];
	bool	b175;
	char	p176[0x188 - 0x176];
	C2PDVec	v188, v198;
	bool	b1a8;
	C2PDCalls c1ac;
	int		i1dc, i1e0, i1e4, i1e8, i1ec, i1f0;
	C2PDVec	v1f4, v204, v214;
	int		i224;
	C2PDVec	v228, v238, v248, v258;
	int		i268;
	C2PDVec	v26c;
	int		i27c;
	C2PDVec	v280, v290, v2a0, v2b0;
	int		i2c0;
	C2PDVec	v2c4, v2d4, v2e4, v2f4;
	int		i304;
	C2PDVec	v308, v318, v328, v338;
	int		i348;
	C2PDVec	v34c, v35c;
	C2PDVecH v36c;
	int		i37c, i380, i384, i388, i38c, i390, i394, i398, i39c, i3a0, i3a4;
	bool	b3a8;
	int		a3ac[7], a3c8[7], a3e4[7];
	int		i400, i404, i408;
	bool	b40c;
	int		i410, i414;
	bool	b418;
	int		i41c, i420, i424;
	bool	b428;
	C2PDVec	v42c, v43c, v44c;
	int		i45c;
	C2PDVecH v460, v470;
	C2PDVecV v480;
	int		i490, i494, i498, i49c;
	bool	b4a0;
	int		i4a4;
	char	p4a8[0x4b8 - 0x4a8];
	int		i4b8, i4bc;
	C2PDVec	v4c0;
	C2PDVecH v4d0;
	C2PDVec	v4e0;
	C2PDObj4F0 *p4f0;
	string	s4f4, s510, s52c;
	int		i548;
	C2PDVec	v54c;
	int		i55c, i560;
	string	s564;
	bool	b580;
	int		i584, i588, i58c, i590, i594, i598;
	C2PDVec	v59c;
	int		i5ac, i5b0, i5b4, i5b8, i5bc, i5c0, i5c4, i5c8, i5cc, i5d0, i5d4, i5d8, i5dc, i5e0, i5e4;
	C2PDVecS v5e8;
	C2PDVec	v5f8, v608, v618, v628, v638;
	int		i648, i64c;
	C2PDVec	v650;
	C2PDVecS v660;
	C2PDVec	v670, v680, v690, v6a0;
	C2PDVecS v6b0;
	C2PDVec	v6c0, v6d0, v6e0, v6f0, v700, v710;
	int		i720, i724;
	C2PDVec	v728;
	int		i738;
	bool	b73c, b73d, b73e, b73f, b740;
	int		i744, i748, i74c, i750, i754, i758, i75c;
	char	p760[0x780 - 0x760];
	int		i780, i784, i788, i78c, i790, i794, i798;
	C2PDPush push79c;
	int		i7a4, i7a8, i7ac, i7b0, i7b4, i7b8;

	bool isFlagActive();
	void clearMarkers();
	void reset779af0();
};

void C2PlayerData::reset779af0()
{
	s00 = c2pd_date436e70(false, 0);
	i1c = rng.rangeInt(c2pd_c36fb4, c2pd_c36fb8);
	s20 = c2pd_text436bc0();
	i3c = 0;
	h40.reset();
	i44 = 0;
	b48 = false;
	i4c = 0;
	b50 = c2pd_cefaa8->get470b30();
	i58 = c2pd_ba76bc[difficulty];
	v5c.clear();
	for (int i = 0; i < 31; i++)
		v5c.push_back(c2pd_ba0498[i]);
	v6c.clear();
	v7c.clear();
	i8c = 0;
	i90 = 0;
	i94 = 31;
	i98 = 11;
	i9c = 0;
	ia0 = 0;
	va4.clear();
	bb4 = false;
	difficulty = c2pd_d28d0c;
	ib8 = 1;
	ibc = c2pd_ba7ab4[difficulty];
	if (mode == 5)
		c2pd_d2c658.add4729d0(0x426, c2pd_ba7ab4[difficulty], c2pd_bb95b2b, -1);
	ic0 = 0;
	ic4 = c2pd_ba7ab4[difficulty];
	bc8 = false;
	icc = 0;
	id0 = 15;
	id4 = 20;
	delete pd8;
	pd8 = 0;
	c2pd_cefb48 = 0;
	vdc.clear();
	vec.clear();
	vfc.clear();
	v10c.assign(15, 0);
	i11c = 50;
	f120 = 0;
	i124 = 0;
	delete p128;
	p128 = 0;
	if (c2pd_cf462c == 11)
	{
		C2PDRecU *cogmind;
		c2pd_find9d7530(c2pd_d25de0, c2pd_bf5cf8, cogmind);
		cogmind->f9c = c2pd_caf440;
		cogmind->f98 = c2pd_caf444;
		cogmind->f94 = c2pd_caf448;
		cogmind->fa4 = c2pd_caf44c;
		cogmind->f78 = c2pd_cefb4c;
		c2pd_caf2b8 = 0x40;
	}
	v12c.assign(25, 0);
	c2pd_d1e860.setEntryText(c2pd_bf5d00, c2pd_d2f4a0[difficulty]);
	c2pd_d1e860.setEntryText(c2pd_bf5d14, difficulty == 0 ? c2pd_bf5d0c : c2pd_bf5d10);
	c2pd_d1e860.setEntryText(c2pd_bf5d2c, difficulty == 1 ? c2pd_bf5d24 : c2pd_bf5d28);
	c2pd_d1e860.setEntryText(c2pd_bf5d44, difficulty == 2 ? c2pd_bf5d3c : c2pd_bf5d40);
	if (mode != 0)
		c2pd_d1e860.setEntryText(c2pd_bf5d54, c2pd_cf2820[mode]);
	logMessage(c2pd_bf5d68 + intToString(difficulty));
	switch (difficulty)
	{
	case 1:
		if (!isFlagActive())
			c2pd_d25744++;
		break;
	case 2:
		if (!isFlagActive())
			c2pd_d25748++;
		c2pd_d1e8bc = 11;
		break;
	}
	b175 = false;
	clearMarkers();
	c2pd_clear9e2c40(v188);
	v198.assign(18, -1);
	b1a8 = false;
	c1ac.reset46cc60();
	i1dc = 0;
	i1e0 = 16;
	i1e4 = 20;
	i1e8 = 0;
	i1ec = 1;
	i1f0 = 1;
	v1f4.clear();
	v204.assign(c2pd_cf09a8.size(), 0);
	for (unsigned i = 0; i < c2pd_d257b0.size(); i++)
	{
		if (((C2PDRecA *)c2pd_d257b0[i])->level <= difficulty)
		{
			int index = c2pd_index9d7b80(c2pd_cf09a8, ((C2PDRecA *)c2pd_d257b0[i])->name);
			if (index == -1)
				;
			else
				v204[index] = 1;
		}
	}
	v214.clear();
	i224 = 0;
	v228.assign(c2pd_cf08c4.size(), 0);
	v238.clear();
	v248.clear();
	v258.clear();
	i268 = 0;
	v258.assign(c2pd_d2d1c4.size(), 0);
	for (unsigned j = 0; j < c2pd_d2d1c4.size(); j++)
	{
		if (((C2PDRecB *)c2pd_d2d1c4[j])->f94 == 0)
			v258[j] = 1;
	}
	i268 = c2pd_count9de8f0(v258);
	v26c.assign(c2pd_d2d1c4.size(), 0);
	i27c = 0;
	v280.clear();
	v290.clear();
	v2a0.clear();
	v2b0.assign(c2pd_d25de0.size(), 0);
	i2c0 = 0;
	v2c4.clear();
	v2d4.clear();
	v2e4.clear();
	v2f4.assign(c2pd_d2d1c4.size(), 0);
	i304 = 0;
	v308.clear();
	v318.clear();
	v328.clear();
	v338.assign(c2pd_d25de0.size(), 0);
	i348 = 0;
	v34c.assign(c2pd_d35b58.size(), 0);
	v35c.assign(c2pd_cf3a20.size(), 0);
	v36c.clear();
	i37c = ((C2PDRecC *)c2pd_d25de0[0])->f1dc;
	if (i144)
		i37c = 800;
	else if (mode == 5)
		i37c = 600;
	i380 = ((C2PDRecC *)c2pd_d25de0[0])->fb4 + c2pd_ba652c[difficulty];
	i384 = ((C2PDRecC *)c2pd_d25de0[0])->fb8 + c2pd_ba6538[difficulty];
	i388 = ((C2PDRecC *)c2pd_d25de0[0])->f21c;
	i38c = ((C2PDRecC *)c2pd_d25de0[0])->f220;
	i390 = ((C2PDRecC *)c2pd_d25de0[0])->f228;
	i394 = ((C2PDRecC *)c2pd_d25de0[0])->f1c8;
	if (i158)
		i394 = 0;
	else
	{
		switch (mode)
		{
		case 2:
			i394 = 10;
			break;
		case 5:
			i394 = 0;
			break;
		case 11:
			i394 = 0;
			break;
		}
	}
	i398 = ((C2PDRecC *)c2pd_d25de0[0])->f1e4;
	i39c = ((C2PDRecC *)c2pd_d25de0[0])->f1ec;
	if (mode == 11)
		i39c = 0;
	i3a0 = 0;
	if (mode == 11)
		i39c = 0;
	i3a4 = 0;
	b3a8 = false;
	for (int k = 0; k < 7; k++)
		a3ac[k] = c2pd_ba64d8[k][difficulty];
	c2pd_fill9e2be0(a3c8, 7, 0);
	c2pd_fill9e2be0(a3e4, 7, 0);
	i400 = ((C2PDRecC *)c2pd_d25de0[0])->f1e8;
	i404 = i144 ? 20 : ((C2PDRecC *)c2pd_d25de0[0])->f1f0;
	i408 = c2pd_ba659c[difficulty];
	b40c = false;
	i410 = 0;
	i414 = 0;
	b418 = false;
	i41c = 0;
	i420 = 0;
	i424 = 0;
	b428 = false;
	v42c.assign(19, 0);
	v43c.clear();
	v44c.clear();
	i45c = 0;
	v460.clear();
	v470.clear();
	v480.assign(4, C2PDUVec());
	i490 = 0;
	i494 = 0;
	i498 = -1;
	i49c = 0;
	b4a0 = false;
	i4a4 = 0;
	i4b8 = 0;
	i4bc = 0;
	v4c0.assign(c2pd_d2d1c4.size(), 0);
	v4d0.clear();
	v4e0.clear();
	delete p4f0;
	p4f0 = 0;
	s4f4 = c2pd_bf5d80;
	s510 = c2pd_text465db0();
	s52c = c2pd_text465db0();
	i548 = 0;
	v54c.assign(c2pd_d25de0.size(), 0);
	i55c = rng.rangeInt(0, c2pd_c36fb0);
	i560 = 28;
	s564.clear();
	b580 = c2pd_cefacd;
	i584 = 0;
	i588 = 0;
	i58c = 0;
	i590 = 0;
	i594 = 0;
	i598 = 0;
	v59c.assign(4, 0);
	i5ac = 0;
	i5b0 = 0;
	i5b4 = 0;
	i5b8 = 0;
	i5bc = 0;
	i5c0 = 0;
	i5c4 = 0;
	i5c8 = 0;
	i5cc = 0;
	i5d0 = 0;
	i5d4 = 0;
	i5d8 = 0;
	i5dc = 0;
	i5e0 = 0;
	i5e4 = 0;
	v5e8.clear();
	v5f8.clear();
	c2pd_clear9d8e70(v608);
	v618.clear();
	v628.clear();
	v638.clear();
	i648 = 0;
	i64c = 0;
	v650.assign(c2pd_d2d1c4.size(), 0);
	v660.clear();
	v670.clear();
	v680.clear();
	v690.clear();
	v6a0.clear();
	v6b0.clear();
	v6c0.clear();
	v6d0.clear();
	v6e0.clear();
	v6f0.clear();
	v700.clear();
	v710.assign(4, 0);
	i720 = 0;
	i724 = 0;
	c2pd_clear9ed890(v728);
	i738 = 0;
	b73c = mode != 11;
	b73d = mode != 11;
	b73e = false;
	b73f = true;
	b740 = true;
	i744 = 0;
	i748 = 0;
	i74c = 0;
	i750 = 0;
	i754 = 0;
	i758 = 0;
	i75c = 0;
	i780 = 0;
	i784 = 0;
	i788 = 0;
	i78c = 0;
	i790 = 0;
	i794 = 0;
	i798 = 0;
	push79c.operate(-1);
	i7a4 = 0;
	i7a8 = 0;
	i7ac = 0;
	i7b0 = 0;
	i7b4 = 0;
	i7b8 = 0;
}
