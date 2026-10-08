// CPartInfo bar/status redraw (0x88bab0; callers CPart::drawStatus, CInventoryItem::drawBar, CPartInfo ctor and
// others): draws the integrity/energy/heat/... bar of the parent's item for the current info mode (0xd28d68).
// NOTE: placeholder names and layouts (C2I*, c2i_<address>).
#include <string>
using namespace std;

struct C2IColor	// NOTE: placeholder (XColor, 3 bytes)
{
	unsigned char r, g, b;
	C2IColor(const C2IColor &o);
	C2IColor operator*(float f);
};
struct C2IHandle { int id; C2IHandle(); bool isValid() const; };
struct C2IEntity
{
	int f5ccab0();
	int f5ccb50(struct C2IItemHandle item);
	C2IHandle f5d2380(int slot);
};
struct C2IEntityHandle { int id; C2IEntityHandle(); C2IEntity *operator->() const; };
struct C2IMap { C2IEntityHandle getPlayer(); };
struct C2IVecColor { int f0, f1, f2, f3; C2IVecColor(); ~C2IVecColor(); unsigned size() const; C2IColor &operator[](unsigned i); };
struct C2IItem
{
	int getNestedField457820();
	int f4578a0();
	int f4578c0();
	int size457b10();
	int f457ca0();
	bool f457cf0();
	float f457df0();
	int f457e10();
	int f457b30();
	int f457f90();
	int f457fb0();
	int f457fd0();
	C2IColor *f577260();
	int f577790();
	int f577b10();
	int f577bd0();
	int f577c90();
	float f577d80();
	int f577df0();
	int f577e60();
	int f5788e0();
	int f5789c0();
	int f578a70();
	void describe5759b0(string &text, C2IVecColor &colors);
};
struct C2IItemHandle { int id; C2IItem *operator->(); };
struct C2IIntVec { int &operator[](unsigned i); };
struct C2IIntList { int sum40c820(); };

class C2IConsole	// NOTE: placeholder (XConsole/Console)
{
public:
	C2IConsole *getParent();
	int getWidth44b0d0();
	void clear();
	void setFore(C2IColor color);
	void setFore417f80(int x, int y, C2IColor color);
	void putChar418110(int x, int y, int ch, C2IColor color);
	void print(int x, int y, const string &text);
	void printAligned(int x, int y, int align, const string &text);
	void animate(string name);
};
class C2IOwner : public C2IConsole { public: char p00[0x6c]; C2IItemHandle item; };
class C2IOther : public C2IConsole { public: char p00[0x6c]; C2IItemHandle item; };

class C2IPartInfo : public C2IConsole	// NOTE: placeholder layout (CPartInfo)
{
public:
	char p00[0x6c];
	bool owner;		// +0x6c
	int mode70;		// +0x70
	int value74;	// +0x74
	string text78;	// +0x78
	int state94;	// +0x94
	void draw88bab0(bool quiet);
};

extern int c2i_d28d68;
extern bool c2i_d28d16, c2i_d28e58, c2i_d28e59, c2i_d28e5a;
extern int c2i_bcc2e0[];
extern C2IIntVec c2i_cf4830;
extern C2IColor *c2i_cf44c0;
extern C2IColor c2i_d2cf08[][10];
extern int c2i_cea008[][16], c2i_cea088[][16], c2i_cea108[16], c2i_cea188[16], c2i_cea208[][16], c2i_cea288[][16],
	c2i_cea308[][16], c2i_cea388[][16], c2i_cea408[][16], c2i_cea508[][16], c2i_cea588[][16], c2i_cea608[][16],
	c2i_cea688[][16], c2i_cea708[][16];
extern const float c2i_bcc2b4, c2i_bcc2ec, c2i_bcc2f0, c2i_bcc2e8, c2i_bcc2c0;
extern const float c2i_bcc2b8[], c2i_bcc2c8[], c2i_bcc2d0[], c2i_bcc2d8[];
extern C2IMap *c2i_cefc4c;
extern C2IIntList c2i_cfcd20;
int c2i_getItemState(C2IItemHandle item);
float minf(float a, float b);
float maxf(float a, float b);
int c2i_maxInt(int a, int b);
int c2i_minInt(int a, int b);
int c2i_clamp9cdc80(int lo, int v, int hi);
string intToString(int v);
string &c2i_padLeft408090(string &s, int width, char c);
extern const char c2i_c0191c[], c2i_c01920[], c2i_c0192c[], c2i_c01930[], c2i_c01934[], c2i_c01940[], c2i_c01948[], c2i_c0194c[], c2i_c01958[], c2i_c01960[], c2i_c01964[], c2i_c01968[], c2i_c0196c[], c2i_c01978[], c2i_c0197c[], c2i_c01988[], c2i_c0198c[], c2i_c01998[], c2i_c019a0[], c2i_c019a4[], c2i_c019b0[], c2i_c019b8[], c2i_c019bc[], c2i_c019c8[];

void C2IPartInfo::draw88bab0(bool quiet)
{
	C2IItemHandle item = owner ? ((C2IOwner *)getParent())->item : ((C2IOther *)getParent())->item;
	if (c2i_d28d68 != mode70 || c2i_getItemState(item) != state94)
	{
		mode70 = c2i_d28d68;
		value74 = -1;
		text78.clear();
		state94 = c2i_getItemState(item);
	}
	int valid = c2i_d28d16 && c2i_d28e58;
	if (valid && c2i_d28d68 == 0 && c2i_d28e59)
		valid = 0;
	int offset = c2i_bcc2e0[0] - c2i_bcc2e0[valid];
	switch (c2i_d28d68)
	{
	case 0:
	{
		int v;
		if (c2i_cf4830[item->getNestedField457820()] == 0)
		{
			v = -2;
			if (v != value74)
			{
				value74 = v;
				clear();
				setFore(*c2i_cf44c0);
				printAligned(getWidth44b0d0() - 1, 0, 2, c2i_c0191c);
			}
			break;
		}
		{
			if (owner)
			{
				int total = c2i_cefc4c->getPlayer()->f5ccab0();
				total += item->f577790();
				v = item->f577790() * 100 / total;
			}
			else
				v = c2i_cefc4c->getPlayer()->f5ccb50(item);
			if (value74 != v)
			{
				value74 = v;
				clear();
				if (v > 0)
				{
					int len = c2i_maxInt(1, (int)(minf((float)v, c2i_bcc2b4) / c2i_bcc2b4 * c2i_bcc2e0[valid]));
					int row = owner ? 21 : 7;
					int *color = owner ? c2i_cea088[valid] : c2i_cea008[valid];
					for (int x = c2i_bcc2e0[0] - 1 - offset; len > 0; x--, len--)
						putChar418110(x, 0, '|', c2i_d2cf08[row][color[x]]);
					if (!quiet)
						animate(c2i_c01920);
					if (valid)
					{
						setFore(c2i_d2cf08[row][color[0]] * (owner ? c2i_bcc2f0 : c2i_bcc2ec));
						print(c2i_bcc2e0[0] - offset, 0, c2i_padLeft408090(intToString(v) + c2i_c0192c, 4, ' '));
					}
				}
			}
		}
		break;
	}
	case 1:
	{
		int v;
		if (c2i_cf4830[item->getNestedField457820()] == 0)
		{
			v = -2;
			if (v != value74)
			{
				value74 = v;
				clear();
				setFore(*c2i_cf44c0);
				printAligned(getWidth44b0d0() - 1, 0, 2, c2i_c01930);
			}
			break;
		}
		{
			switch (item->f4578a0())
			{
			case 0:
				v = item->f577bd0();
				break;
			case 1:
				v = (int)(100.0 / item->f577c90() * item->f577d80() + item->f457df0());
				break;
			case 2:
				v = (int)item->f457df0();
				break;
			case 3:
				v = item->f5788e0();
				break;
			}
			if (v != value74)
			{
				value74 = v;
				clear();
				if (v > 0)
				{
					int len = c2i_minInt(c2i_bcc2e0[valid], (int)maxf(1, v / c2i_bcc2b8[valid]));
					int row;
					int *color;
					float bright;
					if (!item->f457cf0())
					{
						row = 0x15;
						color = c2i_cea308[valid];
						bright = c2i_bcc2f0;
					}
					else if (item->f4578a0() == 0)
					{
						row = 10;
						color = c2i_cea208[valid];
						bright = c2i_bcc2ec;
					}
					else
					{
						row = c2i_d28e5a ? 2 : 13;
						color = c2i_cea288[valid];
						bright = c2i_bcc2ec;
					}
					for (int x = c2i_bcc2e0[0] - 1 - offset; len > 0; x--, len--)
						putChar418110(x, 0, '|', c2i_d2cf08[row][color[x]]);
					if (!quiet)
						animate(c2i_c01934);
				if (valid)
				{
					setFore(c2i_d2cf08[row][color[0]] * bright);
					print(c2i_bcc2e0[0] - offset, 0, v > 9999 ? c2i_c01940 : c2i_padLeft408090(intToString(v), 4, ' '));
				}
				}
			}
		}
		break;
	}
	case 2:
	{
		int pct;
		if (c2i_cf4830[item->getNestedField457820()] == 0)
		{
			pct = -2;
			if (pct != value74)
			{
				value74 = pct;
				clear();
				setFore(*c2i_cf44c0);
				printAligned(getWidth44b0d0() - 1, 0, 2, c2i_c01948);
			}
			break;
		}
		{
			pct = c2i_clamp9cdc80(1, item->f457ca0(), 100);
			int v = item->size457b10();
			if (value74 != v)
			{
				value74 = v;
				clear();
				if (pct > 0)
				{
					int len = c2i_maxInt(1, (int)(pct / 100.0 * c2i_bcc2e0[valid]));
					for (int x = c2i_bcc2e0[0] - 1 - offset; len > 0; x--, len--)
						putChar418110(x, 0, '|', *item->f577260() * c2i_bcc2e8);
					if (!quiet)
						animate(c2i_c0194c);
					if (valid)
					{
						setFore(*item->f577260() * c2i_bcc2e8);
						print(c2i_bcc2e0[0] - offset, 0, v > 9999 ? c2i_c01958 : c2i_padLeft408090(intToString(v), 4, ' '));
					}
				}
			}
		}
		break;
	}
	case 3:
	{
		if (c2i_cf4830[item->getNestedField457820()] == 0)
		{
			if (text78 != c2i_c01960)
			{
				text78 = c2i_c01964;
				clear();
				setFore(*c2i_cf44c0);
				printAligned(getWidth44b0d0() - 1, 0, 2, c2i_c01968);
			}
			break;
		}
		{
			string desc;
			C2IVecColor colors;
			item->describe5759b0(desc, colors);
			if (text78 != desc)
			{
				text78 = desc;
				clear();
				printAligned(getWidth44b0d0() - 1, 0, 2, desc);
				unsigned i;
				int x;
				for (i = 0, x = getWidth44b0d0() - colors.size(); i < colors.size(); i++, x++)
				{
					if (x >= 0)
						setFore417f80(x, 0, colors[i]);
				}
				if (!quiet)
					animate(c2i_c0196c);
			}
		}
		break;
	}
	case 4:
	{
		int v;
		if (c2i_cf4830[item->getNestedField457820()] == 0)
		{
			v = -2;
			if (v != value74)
			{
				value74 = v;
				clear();
				setFore(*c2i_cf44c0);
				printAligned(getWidth44b0d0() - 1, 0, 2, c2i_c01978);
			}
			break;
		}
		{
			v = (int)((double)(item->f577790() * item->f4578c0()) / item->size457b10() * 100.0);
			if (v != value74)
			{
				value74 = v;
				clear();
				if (v > 0)
				{
					int len = c2i_minInt(c2i_bcc2e0[0], (int)maxf(1, v / c2i_bcc2c0));
					int row = owner ? 21 : 0;
					int *color = owner ? c2i_cea188 : c2i_cea108;
					for (int x = c2i_bcc2e0[0] - 1; len > 0; x--, len--)
						putChar418110(x, 0, '|', c2i_d2cf08[row][color[x]]);
					if (!quiet)
						animate(c2i_c0197c);
				}
			}
		}
		break;
	}
	case 5:
	{
		int v;
		if (c2i_cf4830[item->getNestedField457820()] == 0)
		{
			v = -2;
			if (v != value74)
			{
				value74 = v;
				clear();
				setFore(*c2i_cf44c0);
				printAligned(getWidth44b0d0() - 1, 0, 2, c2i_c01988);
			}
			break;
		}
		{
			switch (item->f4578a0())
			{
			case 0:
				v = item->f577b10();
				break;
			case 1:
				v = (int)(100.0 / item->f577c90() * item->f577df0() + item->f577b10());
				break;
			case 2:
				v = item->f457f90() == 1 ? (item->f457fd0() && c2i_cefc4c->getPlayer()->f5d2380(6).isValid() ? 2 : 1) * item->f457fb0() : item->f577b10();
				break;
			case 3:
				v = item->f578a70() / (c2i_cfcd20.sum40c820() / 100);
				break;
			}
			if (v != value74)
			{
				value74 = v;
				clear();
				if (v > 0)
				{
					int len = c2i_minInt(c2i_bcc2e0[valid], (int)maxf(1, v / c2i_bcc2c8[valid]));
					int row;
					int *color;
					float bright;
					if (!item->f457cf0())
					{
						row = 0x15;
						color = c2i_cea308[valid];
						bright = c2i_bcc2f0;
					}
					else if (item->f457f90() == 1)
					{
						row = 4;
						color = c2i_cea408[valid];
						bright = c2i_bcc2ec;
					}
					else
					{
						row = 2;
						color = c2i_cea388[valid];
						bright = c2i_bcc2ec;
					}
					for (int x = c2i_bcc2e0[0] - 1 - offset; len > 0; x--, len--)
						putChar418110(x, 0, '|', c2i_d2cf08[row][color[x]]);
					if (!quiet)
						animate(c2i_c0198c);
				if (valid)
				{
					setFore(c2i_d2cf08[row][color[0]] * bright);
					print(c2i_bcc2e0[0] - offset, 0, v > 9999 ? c2i_c01998 : c2i_padLeft408090(intToString(v), 4, ' '));
				}
				}
			}
		}
		break;
	}
	case 6:
	{
		int v;
		if (c2i_cf4830[item->getNestedField457820()] == 0)
		{
			v = -2;
			if (v != value74)
			{
				value74 = v;
				clear();
				setFore(*c2i_cf44c0);
				printAligned(getWidth44b0d0() - 1, 0, 2, c2i_c019a0);
			}
			break;
		}
		{
			switch (item->f4578a0())
			{
			case 0:
				v = item->f457b30();
				break;
			case 1:
				v = item->f577e60();
				break;
			case 2:
				v = item->f457f90() == 0x22 ? item->f457fb0() : item->f457b30();
				break;
			case 3:
				v = item->f457b30();
				break;
			}
			if (v != value74)
			{
				value74 = v;
				clear();
				if (v > 0)
				{
					int len = c2i_minInt(c2i_bcc2e0[valid], (int)maxf(1, v / c2i_bcc2d0[valid]));
					int row;
					int *color;
					float bright;
					if (item->f4578a0() == 1 || item->f457f90() == 0x22)
					{
						if (item->f457cf0())
						{
							row = 4;
							color = c2i_cea588[valid];
							bright = c2i_bcc2ec;
						}
						else
						{
							row = 0x15;
							color = c2i_cea608[valid];
							bright = c2i_bcc2f0;
						}
					}
					else
					{
						row = 0x16;
						color = c2i_cea508[valid];
						bright = c2i_bcc2ec;
					}
					for (int x = c2i_bcc2e0[0] - 1 - offset; len > 0; x--, len--)
						putChar418110(x, 0, '|', c2i_d2cf08[row][color[x]]);
					if (!quiet)
						animate(c2i_c019a4);
				if (valid)
				{
					setFore(c2i_d2cf08[row][color[0]] * bright);
					print(c2i_bcc2e0[0] - offset, 0, v > 9999 ? c2i_c019b0 : c2i_padLeft408090(intToString(v), 4, ' '));
				}
				}
			}
		}
		break;
	}
	case 7:
	{
		int v;
		if (c2i_cf4830[item->getNestedField457820()] == 0)
		{
			v = -2;
			if (v != value74)
			{
				value74 = v;
				clear();
				setFore(*c2i_cf44c0);
				printAligned(getWidth44b0d0() - 1, 0, 2, c2i_c019b8);
			}
			break;
		}
		{
			switch (item->f4578a0())
			{
			case 0:
			case 1:
			case 2:
				v = item->f457e10();
				break;
			case 3:
				v = item->f5789c0();
				break;
			}
			if (v != value74)
			{
				value74 = v;
				clear();
				if (v > 0)
				{
					int len = c2i_minInt(c2i_bcc2e0[valid], (int)maxf(1, v / c2i_bcc2d8[valid]));
					int row;
					int *color;
					float bright;
					if (item->f457cf0())
					{
						row = 0x10;
						color = c2i_cea688[valid];
						bright = c2i_bcc2ec;
					}
					else
					{
						row = 0x15;
						color = c2i_cea708[valid];
						bright = c2i_bcc2f0;
					}
					for (int x = c2i_bcc2e0[0] - 1 - offset; len > 0; x--, len--)
						putChar418110(x, 0, '|', c2i_d2cf08[row][color[x]]);
					if (!quiet)
						animate(c2i_c019bc);
				if (valid)
				{
					setFore(c2i_d2cf08[row][color[0]] * bright);
					print(c2i_bcc2e0[0] - offset, 0, v > 9999 ? c2i_c019c8 : c2i_padLeft408090(intToString(v), 4, ' '));
				}
				}
			}
		}
		break;
	}
	}
}
