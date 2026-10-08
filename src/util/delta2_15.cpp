// CInfoCompare::trigger (exe 0x8ec880, vtable slot 11): builds the item comparison column (stat deltas between the
// current item and the previously viewed one).
// NOTE: class is declared here as D2Compare (placeholder name); layouts are partial, names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(const Pos &pos) throw();	// 0x46ca50
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);
	virtual void update();
	virtual void render();

	Pos getPos();
	void setPos(int x, int y);
	int getHeight();

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	virtual ~Console();
	virtual void render();
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	int unknown60;
	void *engine;
	void *title;
};

class D2cButton : public Console	// NOTE: placeholder name (CInfoButton, size 0x70)
{
public:
	D2cButton(XConsole *parent, int x, int y, int width, const string &text);
	void animateFrame_4ae610();
	char pad6c[0x70 - 0x6c];
};

class D2cData : public Console	// NOTE: placeholder name (CInfoCompareData, size 0x70)
{
public:
	D2cData(XConsole *parent, int row, const string &text, int state);
	void unknown4aeff0();
	char pad6c[0x70 - 0x6c];
};

struct D2cRange	// NOTE: placeholder name
{
	bool test_409bd0(const D2cRange &other);
	string rangeToString_40c2b0(string separator);
	int pad0[5];
};

struct D2cWeapon	// NOTE: placeholder layout
{
	char pad0[0x2c];
	int f2c;
	int f30;
	int f34;
	int f38;
	int f3c;
	int f40;
	D2cRange range;
	int f58;
	int f5c;
	int f60;
	int f64;
};

struct D2cStats	// NOTE: placeholder layout
{
	char pad0[0x94];
	int f94;
	char pad98[0xec - 0x98];
	int fec;
	char padf0[0x11c - 0xf0];
	int f11c;
	int f120;
	int f124;
	int f128;
	int f12c;
	int f130;
	int f134;
	int f138;
	vector<int> list13c;
	int f14c;
	int f150;
	int f154;
	int f158;
	char pad15c[0x1a0 - 0x15c];
	D2cWeapon *weapon;
};

struct D2cFlags { bool f[9]; };	// NOTE: placeholder layout
extern D2cFlags d2c_ba0380[];

class D2cEntity { public: double unknown5d7bc0(); };
class D2cHE { public: int ID; bool isValid() const; D2cEntity *operator->() const; };

class D2cItem
{
public:
	bool hasName_4579d0();
	int nested_457880();
	int getNestedField();
	int unknown457b30();
	int unknown457920();
	D2cStats *stats_9b4350();
	int unknown9b6bf0();
	int unknown577790();
	double unknown457df0();
	int unknown457e10();
	int unknown577b10();
	int unknown577bd0();
	int unknown457ed0();
	int unknown457f10();
	int unknown577c90();
	int unknown457f30();
	int unknown457f50();
	D2cHE unknown457b50();
	bool unknown458220();
	double unknown577d80();
	int unknown577df0();
	int unknown577e60();
	int unknown577f30();
	int unknown457f70();
	int unknown4580a0();
	int unknown5788e0();
	int unknown5789c0();
	int unknown578a70();
	int unknown458100();
	int unknown578b10();
	int unknown4580e0();
	int unknown458160();
	int unknown4580c0();
	const string &name_457860();
	int unknown458120();
	int unknown457f90();
	int unknown45cb30();
	int unknown457fb0();
};

class D2cHI { public: int ID; D2cItem *operator->() const; };	// NOTE: placeholder name (0x9b65b0)

class D2cInfo { public: D2cHI getUnknown9c(); };	// NOTE: placeholder name (CInfo)
extern D2cInfo *d2c_cec124, *d2c_cec11c;
extern int d2c_d32e00, d2c_d32e04;
extern vector<int> d2c_d25790, d2c_cf4830;
extern string d2c_d2a7d8[], d2c_d323f8[], d2c_d1e058[], d2c_d33e38[];
extern int d2c_b96178[], d2c_b9654c[], d2c_ba2c18[];
extern const float d2c_ba09e0, d2c_ba0a88, d2c_ba0b60;

void logError(string location, string message);
string intToString(int value);
string OpY1_intToStringSigned(int value);
string OpY1_floatToStringSigned(float value, int a, int b);
void OpV4c_Fn9d06d0(int *value, int amount, int max);

#define D2C_INT(expr, mark, good) if ((amount = expr) != 0) { entry = new D2cData(this, level, OpY1_intToStringSigned(amount) + (mark ? "*" : ""), good); entry->unknown4aeff0(); }
#define D2C_FLT(expr, mark) x2 = expr; if (x2 != 0) { entry = new D2cData(this, level, OpY1_floatToStringSigned(x2, 0, 1) + (mark ? "*" : ""), x2 > 0.0); entry->unknown4aeff0(); }

class D2Compare : public Console
{
public:
	virtual void trigger(const string &command, int value);

	D2cHI previous;
};

void D2Compare::trigger(const string &command, int value)
{
	if (command == "show_compare")
	{
		D2cHI current = d2c_cec124 ? d2c_cec124->getUnknown9c() : d2c_cec11c->getUnknown9c();
		if (!previous.operator->())
		{
			logError("CInfoCompare::trigger()", "previousItem no longer exists");
			return;
		}
		if (!current.operator->())
		{
			logError("CInfoCompare::trigger()", "currentItem no longer exists");
			return;
		}
		if (!d2c_cec124)
		{
			int y = d2c_d32e04;
			if (current->hasName_4579d0())
				y++;
			if (getPos().y != y)
				setPos(d2c_d32e00, y);
		}
		D2cButton *elem = new D2cButton(this, 1, getHeight() - 1, 0x11, "REVERSE");
		elem->animateFrame_4ae610();
		int tag = current->nested_457880();
		int mode = previous->nested_457880();
		string s;
		int level = 1;
		if ((d2c_cec124 ? d2c_d25790[current->getNestedField()] == 0 : d2c_cf4830[current->getNestedField()] == 0)
			|| (d2c_cec124 ? d2c_d25790[previous->getNestedField()] == 0 : d2c_cf4830[previous->getNestedField()] == 0))
			return;
		int amount;
		float x2;
		D2cData *entry;
		if (d2c_ba0380[tag].f[0] && d2c_ba0380[mode].f[0])
			D2C_INT(current->unknown457b30() - previous->unknown457b30(), 0, amount > 0)
		level = 2;
		if (d2c_ba0380[tag].f[1] && d2c_ba0380[mode].f[1])
		{
			if ((amount = current->unknown457920() - previous->unknown457920()) != 0 && current->stats_9b4350()->f94 != 2 && previous->stats_9b4350()->f94 != 2)
			{
				s = OpY1_intToStringSigned(amount);
				if (current->stats_9b4350()->f94 != 0 || previous->stats_9b4350()->f94 != 0)
					s = "* " + s;
				entry = new D2cData(this, level, s, amount <= 0);
				entry->unknown4aeff0();
			}
			level++;
			D2C_INT(current->unknown9b6bf0() - previous->unknown9b6bf0(), 0, amount <= 0)
			level++;
			D2C_INT(current->unknown577790() - previous->unknown577790(), 0, amount <= 0)
			level++;
			level += 3;
		}
		else if (d2c_ba0380[tag].f[1])
			level += 7;
		if (d2c_ba0380[tag].f[2] && d2c_ba0380[mode].f[2])
		{
			D2C_FLT(current->unknown457df0() - previous->unknown457df0(), 0)
			level++;
			D2C_INT(current->unknown457e10() - previous->unknown457e10(), 0, amount > 0)
			level++;
			D2C_INT(current->unknown577b10() - previous->unknown577b10(), previous->unknown457b50().isValid() && previous->unknown458220(), amount > 0)
			level++;
			level += 2;
		}
		else if (d2c_ba0380[tag].f[2])
			level += 5;
		if (d2c_ba0380[tag].f[3] && d2c_ba0380[mode].f[3])
		{
			D2C_INT(current->unknown577bd0() - previous->unknown577bd0(), previous->unknown457b50().isValid() && previous->unknown458220(), amount <= 0)
			level++;
			D2C_INT(current->unknown457ed0() - previous->unknown457ed0(), 0, amount <= 0)
			level++;
			D2C_INT((100 - current->unknown457f10()) - (100 - previous->unknown457f10()), 0, amount <= 0)
			level++;
			level += 2;
		}
		else if (d2c_ba0380[tag].f[3])
			level += 5;
		if (d2c_ba0380[tag].f[4] && d2c_ba0380[mode].f[4])
		{
			D2C_INT(current->unknown577c90() - previous->unknown577c90(), previous->nested_457880() == 10 && previous->unknown457b50().isValid() && previous->unknown458220(), amount > 0)
			level++;
			if (tag > 11 && mode > 11)
			{
				D2C_INT(current->unknown457f30() - previous->unknown457f30(), 0, amount > 0)
			}
			else if (tag <= 11 && mode <= 11)
				D2C_INT(current->unknown457f50() - previous->unknown457f50(), 0, amount > 0)
			level++;
			bool mark = previous->nested_457880() >= 12 && previous->unknown457b50().isValid() && previous->unknown458220();
			D2C_FLT(current->unknown577d80() - previous->unknown577d80(), mark)
			level++;
			D2C_INT(current->unknown577df0() - previous->unknown577df0(), mark, amount > 0)
			level++;
			D2C_INT(current->unknown577e60() - previous->unknown577e60(), mark, amount <= 0)
			level++;
			D2C_INT(current->unknown577f30() - previous->unknown577f30(), 0, amount > 0)
			level++;
			if ((tag == 10 || tag == 9) && (mode == 10 || mode == 9) && current->unknown457f70() == 0 && previous->unknown457f70() == 0)
			{
				if (current->stats_9b4350()->fec != previous->stats_9b4350()->fec)
				{
					entry = new D2cData(this, level, string(d2c_d2a7d8[previous->stats_9b4350()->fec]), 2);
					entry->unknown4aeff0();
				}
			}
			else
				D2C_INT(current->unknown457f70() - previous->unknown457f70(), 0, amount > 0)
			level++;
			level += 2;
		}
		else if (d2c_ba0380[tag].f[4])
			level += 9;
		if (d2c_ba0380[tag].f[5] && d2c_ba0380[mode].f[5])
		{
			bool big = tag >= 26 || mode >= 26;
			if (!big)
			{
				D2C_INT(current->unknown4580a0() - previous->unknown4580a0(), 0, amount <= 0)
				level++;
			}
			else if (tag < 26)
				level++;
			D2C_INT(current->unknown5788e0() - previous->unknown5788e0(), previous->unknown457b50().isValid() && previous->unknown458220(), amount > 0)
			level++;
			D2C_INT(current->unknown5789c0() - previous->unknown5789c0(), 0, amount > 0)
			level++;
			D2C_INT(current->unknown578a70() - previous->unknown578a70(), previous->unknown457b50().isValid() && previous->unknown458220(), amount > 0)
			level++;
			if (!big)
			{
				D2C_INT(current->unknown458100() - previous->unknown458100(), 0, amount > 0)
				level++;
			}
			else if (tag < 26)
				level++;
			D2C_INT(current->unknown578b10() - previous->unknown578b10(), 0, amount <= 0)
			level++;
			D2C_INT(current->unknown4580e0() - previous->unknown4580e0(), 0, amount > 0)
			level++;
			if (!big)
			{
				D2C_INT((100 - current->unknown458160()) - (100 - previous->unknown458160()), 0, amount <= 0)
				level++;
				int curCount = current->unknown4580c0() == 0 ? 0 : current->unknown4580c0();
				int prevCount = previous->unknown4580c0() == 0 ? 0 : previous->unknown4580c0();
				if (curCount != 0)
				{
					if (curCount != prevCount)
					{
						amount = curCount - prevCount;
						s = OpY1_intToStringSigned(amount);
						entry = new D2cData(this, level, s, amount <= 0);
						entry->unknown4aeff0();
					}
				}
				else if (current->stats_9b4350()->f11c != previous->stats_9b4350()->f11c)
				{
					amount = current->stats_9b4350()->f11c - previous->stats_9b4350()->f11c;
					entry = new D2cData(this, level, OpY1_intToStringSigned(amount), amount > 0);
					entry->unknown4aeff0();
				}
				level++;
			}
			else if (tag < 26)
				level += 2;
			level += 2;
		}
		else if (d2c_ba0380[tag].f[5])
			level += tag < 26 ? 11 : 7;
		if (d2c_ba0380[tag].f[6] && current->stats_9b4350()->f128 != 9 && current->name_457860().find("Latent Energy Streamer") == string::npos
			&& d2c_ba0380[mode].f[6] && previous->stats_9b4350()->f128 != 9 && previous->name_457860().find("Latent Energy Streamer") == string::npos)
		{
			bool clean = tag >= 26 || mode >= 26;
			if (!clean)
			{
				level--;
				D2C_INT(current->unknown458120() - previous->unknown458120(), 0, amount <= 0)
				level++;
			}
			float y0 = current->unknown457b50().isValid() && current->unknown458220() ? current->unknown457b50()->unknown5d7bc0() : 1.0;
			int first = (int)(current->stats_9b4350()->f120 * y0);
			int top2 = (int)(current->stats_9b4350()->f124 * y0);
			float multiplier = previous->unknown457b50().isValid() && previous->unknown458220() ? previous->unknown457b50()->unknown5d7bc0() : 1.0;
			int bottom = (int)(previous->stats_9b4350()->f120 * multiplier);
			int h2 = (int)(previous->stats_9b4350()->f124 * multiplier);
			if (first != bottom || top2 != h2)
			{
				int state = 3;
				if (first >= bottom && top2 >= h2)
				{
					state = 0;
					s = "+" + intToString(first - bottom) + "/+" + intToString(top2 - h2);
				}
				else if (first <= bottom && top2 <= h2)
				{
					state = 1;
					s = intToString(first - bottom) + "/" + intToString(top2 - h2);
				}
				else
				{
					s = intToString(bottom) + "-" + intToString(h2);
					state = 2;
				}
				if (multiplier != 1)
					s += "*";
				entry = new D2cData(this, level, s, state);
				entry->unknown4aeff0();
			}
			level++;
			if (current->stats_9b4350()->f128 != previous->stats_9b4350()->f128)
			{
				s = d2c_d323f8[previous->stats_9b4350()->f128];
				entry = new D2cData(this, level, s, 2);
				entry->unknown4aeff0();
			}
			level++;
			if (current->stats_9b4350()->f134 != previous->stats_9b4350()->f134 && current->stats_9b4350()->f134 != 0 && previous->stats_9b4350()->f134 != 0)
			{
				s = d2c_d1e058[previous->stats_9b4350()->f134];
				if (s.size() >= 6)
					s.erase(s.begin() + 6, s.end());
				entry = new D2cData(this, level, s, 2);
				entry->unknown4aeff0();
			}
			else
				D2C_INT(current->stats_9b4350()->f138 - previous->stats_9b4350()->f138, 0, amount <= 0)
			level++;
			if (!clean)
			{
				int hits = current->stats_9b4350()->list13c.size();
				int ranks = previous->stats_9b4350()->list13c.size();
				if (hits != 0 || ranks != 0)
				{
					bool curInf = hits == 1 && current->stats_9b4350()->list13c.front() == -1;
					bool prevInf = ranks == 1 && previous->stats_9b4350()->list13c.front() == -1;
					if (!curInf && prevInf)
					{
						entry = new D2cData(this, level, string("-Inf."), 1);
						entry->unknown4aeff0();
					}
					else if (hits != ranks)
					{
						s = curInf ? string("+Inf.") : OpY1_intToStringSigned(hits - ranks);
						entry = new D2cData(this, level, s, !curInf && ranks > hits);
						entry->unknown4aeff0();
					}
				}
				level++;
				int res = current->stats_9b4350()->f158;
				if (res && current->unknown458220())
					OpV4c_Fn9d06d0(&res, 1, 6);
				int old = previous->stats_9b4350()->f158;
				if (old && previous->unknown458220())
					OpV4c_Fn9d06d0(&old, 1, 6);
				if (res != 0)
				{
					if (res != old)
					{
						amount = d2c_b96178[res] - d2c_b96178[old];
						s = OpY1_intToStringSigned(amount);
						if (previous->unknown458220())
							s += "*";
						entry = new D2cData(this, level, s, 2);
						entry->unknown4aeff0();
					}
				}
				else if (current->stats_9b4350()->f154 != previous->stats_9b4350()->f154)
				{
					amount = d2c_b9654c[current->stats_9b4350()->f154] - d2c_b9654c[previous->stats_9b4350()->f154];
					entry = new D2cData(this, level, OpY1_intToStringSigned(amount), 2);
					entry->unknown4aeff0();
				}
				level++;
			}
			else if (tag < 26)
				level += 2;
			D2C_INT(current->stats_9b4350()->f150 - previous->stats_9b4350()->f150, 0, amount <= 0)
			level++;
			D2C_INT(current->stats_9b4350()->f12c - previous->stats_9b4350()->f12c, 0, amount <= 0)
			level++;
			level += 2;
		}
		else if (d2c_ba0380[tag].f[6] && current->stats_9b4350()->f128 != 9 && current->name_457860().find("Latent Energy Streamer") == string::npos)
			level += tag >= 26 ? 6 : 9;
		if ((d2c_ba0380[tag].f[7] || current->name_457860().find("Latent Energy Streamer") != string::npos)
			&& (d2c_ba0380[mode].f[7] || previous->name_457860().find("Latent Energy Streamer") != string::npos))
		{
			level--;
			D2C_INT(current->unknown458120() - previous->unknown458120(), 0, amount <= 0)
			level++;
			D2cWeapon *vec = current->stats_9b4350()->weapon;
			D2cWeapon *p = previous->stats_9b4350()->weapon;
			D2C_INT(vec->f3c - p->f3c, 0, amount <= 0)
			level++;
			int first = vec->f30 - vec->f34;
			int y2 = vec->f30 + vec->f34;
			int to = p->f30 - p->f34;
			int v = p->f30 + p->f34;
			if (first != to || y2 != v)
			{
				int state = 3;
				if (first >= to && y2 >= v)
				{
					state = 0;
					s = "+" + intToString(first - to) + "/+" + intToString(y2 - v);
				}
				else if (first <= to && y2 <= v)
				{
					state = 1;
					s = intToString(first - to) + "/" + intToString(y2 - v);
				}
				else
				{
					s = intToString(to) + "-" + intToString(v);
					state = 2;
				}
				entry = new D2cData(this, level, s, state);
				entry->unknown4aeff0();
			}
			level++;
			D2C_INT(vec->f38 - p->f38, 0, amount > 0)
			level++;
			if (vec->range.test_409bd0(p->range))
			{
				s = p->range.rangeToString_40c2b0("-");
				entry = new D2cData(this, level, s, 2);
				entry->unknown4aeff0();
			}
			level++;
			if (vec->f2c != p->f2c)
			{
				s = d2c_d323f8[p->f2c];
				entry = new D2cData(this, level, s, 2);
				entry->unknown4aeff0();
			}
			level++;
			if (vec->f64 != 0)
			{
				if (vec->f64 != p->f64)
				{
					amount = d2c_b96178[vec->f64] - d2c_b96178[p->f64];
					entry = new D2cData(this, level, OpY1_intToStringSigned(amount), 2);
					entry->unknown4aeff0();
				}
			}
			else if (vec->f60 != p->f60)
			{
				amount = d2c_b9654c[vec->f60] - d2c_b9654c[p->f60];
				entry = new D2cData(this, level, OpY1_intToStringSigned(amount), 2);
				entry->unknown4aeff0();
			}
			level++;
			D2C_INT(vec->f5c - p->f5c, 0, amount <= 0)
			level++;
			D2C_INT(vec->f58 - p->f58, 0, amount <= 0)
			level++;
			level += 2;
		}
		else if (d2c_ba0380[tag].f[7] || current->name_457860().find("Latent Energy Streamer") != string::npos)
			level += 10;
		if (current->unknown457f90() && previous->unknown457f90() && current->unknown457f90() == previous->unknown457f90())
		{
			if (current->unknown457f90() == 0x7c)
			{
				if (current->getNestedField() == previous->getNestedField())
				{
					amount = current->unknown45cb30() - previous->unknown45cb30();
					s = OpY1_intToStringSigned(amount);
					entry = new D2cData(this, level, s, amount <= 0);
					entry->unknown4aeff0();
				}
			}
			else if (current->unknown457fb0() != previous->unknown457fb0())
			{
				switch (d2c_ba2c18[current->unknown457f90()])
				{
				case 0:
					D2C_INT(current->unknown457fb0() - previous->unknown457fb0(), 0, amount <= 0)
					break;
				case 1:
					D2C_INT(current->unknown457fb0() - previous->unknown457fb0(), 0, amount > 0)
					break;
				case 2:
					switch (current->unknown457f90())
					{
					case 0x29:
						D2C_INT((100 - 100 / current->unknown457fb0()) - (100 - 100 / previous->unknown457fb0()), 0, amount <= 0)
						break;
					case 0x3f:
					case 0x44:
					case 0x45:
					case 0x46:
					case 0x47:
						amount = current->unknown457fb0() - previous->unknown457fb0();
						s = OpY1_intToStringSigned(amount) + " en";
						entry = new D2cData(this, level, s, amount > 0);
						entry->unknown4aeff0();
						break;
					case 0x48:
						amount = current->unknown457fb0() - previous->unknown457fb0();
						s = OpY1_floatToStringSigned(amount / d2c_ba09e0, 1, 2);
						entry = new D2cData(this, level, s, amount <= 0);
						entry->unknown4aeff0();
						break;
						break;
						break;
					case 0x97:
						amount = current->unknown457fb0() - previous->unknown457fb0();
						s = OpY1_floatToStringSigned(amount / d2c_ba0a88 * 100.0, 1, 2);
						entry = new D2cData(this, level, s, amount <= 0);
						entry->unknown4aeff0();
						break;
					case 0x98:
						s = d2c_d33e38[previous->unknown457fb0()];
						entry = new D2cData(this, level, s, 2);
						entry->unknown4aeff0();
						break;
					case 0xa2:
					case 0xa3:
						amount = current->unknown457fb0() - previous->unknown457fb0();
						s = OpY1_floatToStringSigned(amount / d2c_ba0b60 * 100.0, 1, 2);
						entry = new D2cData(this, level, s, amount <= 0);
						entry->unknown4aeff0();
						break;
					}
					break;
				}
			}
		}
	}
}
