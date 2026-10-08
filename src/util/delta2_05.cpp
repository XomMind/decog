// CEnding::render (exe 0x9ab840, vtable slot 7): ending sequence rendering (map reveal, dust, terminal, warlord map).
// NOTE: class is declared here as D2Ending (placeholder name) so this TU's COMDATs do not collide with
//	op_q4f_ending.cpp's CEnding; layouts are partial, member names are placeholders.
#include <string>
#include <vector>
#include <math.h>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos, int dx, int dy);	// 0x4099c0
	Pos(const Pos &pos) throw();
	Pos &operator+=(const Pos &pos);	// 0x409a30
	int randomInRange_40c130();
};

struct D2nPt : Pos	// NOTE: placeholder name (default ctor 0x453b40; Pos() itself is 0x40a6e0)
{
	D2nPt();
};

struct Area
{
	int x;
	int y;
	int x2;
	int y2;
	void randomPoint_40be30(Pos *p);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &color) throw();
	void scale(float f);
	void lerp(XColor color, float f);
};

struct XCell
{
	XColor *getFore();
	XColor *getBack();
	int getChar_9b8f00();	// NOTE: placeholder name (ICF'd getter)
};

class D2nGrid	// NOTE: placeholder name (Array2D<XCell>)
{
public:
	int getWidth_9fcd80();
	int getHeight_9b8f00();
	XCell *at(int x, int y);
	XCell *atPoint(Pos &p);
	Area getArea();
};

struct D2nImage	// NOTE: placeholder name (AsciiImage)
{
	vector<D2nGrid*> layers;
};

class D2nEngine { public: void render(); };

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

	bool isHidden();
	void setBgColor(XColor color);
	void setFore(XColor color);
	XCell *cellAt_4176e0(int x, int y);
	void setChar_417f50(int x, int y, int ch);
	void setFore_417f80(int x, int y, XColor color);
	void setBack_417fc0(int x, int y, XColor color, int mode);
	void putCell_4181a0(int x, int y, XCell *cell);
	void print(int x, int y, const string &text);
	void setBackRow_d2n(int x, int y, int width, XColor color) throw();	// 0x429c20 setBackRow (private nothrow alias)
	bool inBounds(const Pos &pos);
	Pos getPos();
	void setPos(const Pos &pos);
	int getX_48e040();	// NOTE: placeholder name (ICF'd getter)
	void render_429ea0();	// NOTE: placeholder name

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

	void addEffect_48c460(int anim, const Pos &pos);

	int unknown60;
	D2nEngine *engine;
	void *title;
};

class RNG
{
public:
	bool chance(int percent);
	int rangeInt(float low, float high);
};
extern RNG rng;

class D2nStats { public: int unknown472c70(int id); };
extern D2nStats d2n_d2c658;

class D2Ending : public Console
{
public:
	virtual bool input(void *event);
	virtual void close();
	virtual void render();

	bool unknown6c;
	int phase;
	unsigned int startTime;
	vector<int> unknown78;
	D2nImage unknown88;
	vector<Pos> unknown98;
	int index;
	vector<bool> seen;
	vector<int> unknownc0;
	unsigned int unknownd0;
	D2nImage unknownd4;
	unsigned int unknowne4;
	bool unknowne8;
	char padec[0x15c - 0xec];
	D2nImage unknown15c;
	vector<Pos> unknown16c;
	char pad17c[0x188 - 0x17c];
	Console *unknown188;
	vector<Pos> unknown18c;
	unsigned int unknown19c;
	unsigned int unknown1a0;
	char pad1a4[0x1c4 - 0x1a4];
	vector<XConsole*> unknown1c4;
};

extern unsigned int d2n_caed20;
extern unsigned int d2n_bce8e4, d2n_bce8e8, d2n_bce958;
extern int d2n_bce948, d2n_bce978;
extern XColor d2n_d29804;
extern XColor *d2n_d386c8, *d2n_d2f170, *d2n_cfabbc, *d2n_d204ac, *d2n_d35bbc, *d2n_cf6ed4;
extern const float d2n_c36f78, d2n_c36eb4, d2n_c36f64, d2n_c36ecc;
extern Pos d2n_d22318;
extern Pos d2n_d01b38;
extern Pos d2n_d0155c;
extern bool d2n_cf4a00;
extern int d2n_cf462c, d2n_cf4b38;

class D2nRex { public: int unknown418980(); int unknown4189a0(); };
extern D2nRex d2n_d223f0;

int d2n_randomIndex(vector<int> &v);
void d2n_insertAt(vector<XConsole*> &v, int index, XConsole *value);
int halfDiff_437190(int a, int b);
bool blink_437320(int period);
bool OpU8a_lookup1(const string &name, int *index);
int ops7_clamp_9cdc80(int low, int value, int high);
string intToString(int value);

void D2Ending::render()
{
	if (isHidden())
		return;
	setBgColor(d2n_d29804);
	if (phase == 3)
	{
		const int step = 20;
		int limit = d2n_d223f0.unknown418980() / 2 * 4 / (d2n_bce8e4 / 20);
		limit *= 3;
		unsigned int delta = d2n_caed20 - unknownd0;
		int id;
		while (delta >= 20)
		{
			for (int i = 0, tries = limit * 2; i < limit && tries != 0; i++, tries--)
			{
				id = d2n_randomIndex(unknownc0);
				if (unknownc0[id] < 4)
					unknownc0[id]++;
				else
					i--;
			}
			delta -= 20;
			unknownd0 += 20;
		}
	}
	if ((phase >= 3 && phase < 6) || phase == 0x20 || phase == 0x21)
	{
		if (phase == 4)
		{
			unsigned int step = d2n_bce8e8 / (unknown98.size() - 1);
			unsigned int delta = d2n_caed20 - startTime;
			index = delta / step;
			if (index >= unknown98.size())
				index = unknown98.size() - 1;
		}
		else if (phase == 0x20)
		{
			unsigned int step = d2n_bce958 / (unknown98.size() - 1);
			unsigned int delta = d2n_caed20 - startTime;
			index = unknown98.size() - 1 - delta / step;
			index = ops7_clamp_9cdc80(0, index, unknown98.size() - 1);
		}
		bool near = unknown98[index].y <= 17;
		D2nGrid *map = unknown88.layers.front();
		D2nPt offset;
		float total;
		offset.x = map->getWidth_9fcd80() > d2n_d223f0.unknown418980() / 2 ? -halfDiff_437190(d2n_d223f0.unknown418980() / 2, map->getWidth_9fcd80()) : halfDiff_437190(map->getWidth_9fcd80(), d2n_d223f0.unknown418980() / 2);
		offset.y = halfDiff_437190(map->getHeight_9b8f00(), d2n_d223f0.unknown4189a0());
		for (int x = offset.x < 0 ? -offset.x : 0, px = offset.x < 0 ? 0 : offset.x; px < d2n_d223f0.unknown418980() / 2 && x < map->getWidth_9fcd80(); x++, px++)
		{
			if (unknownc0[px] != 0)
			{
				for (int y = 0, py = offset.y; y < map->getHeight_9b8f00(); y++, py++)
				{
					putCell_4181a0(px, py, map->at(x, y));
					if (unknownc0[px] < 4)
					{
						switch (unknownc0[px])
						{
						case 1:
							total = d2n_c36f78;
							break;
						case 2:
							total = d2n_c36eb4;
							break;
						case 3:
							total = d2n_c36f64;
							break;
						}
						cellAt_4176e0(px, py)->getFore()->lerp(*d2n_d386c8, total);
						cellAt_4176e0(px, py)->getBack()->lerp(*d2n_d2f170, total);
					}
					else if (near)
					{
						cellAt_4176e0(px, py)->getFore()->scale(d2n_c36f64);
						cellAt_4176e0(px, py)->getBack()->scale(d2n_c36f64);
					}
				}
			}
		}
		if (near)
		{
			D2nGrid *overlay = unknownd4.layers.front();
			int ox = offset.x + 20;
			for (int x = 0, px = ox < 0 ? 0 : ox; x < overlay->getWidth_9fcd80(); x++, px++)
			{
				for (int y = 0, py = offset.y; y < overlay->getHeight_9b8f00(); y++, py++)
				{
					if (overlay->at(x, y)->getChar_9b8f00() != 0x20)
						putCell_4181a0(px, py, overlay->at(x, y));
				}
			}
		}
		if ((phase == 4 || phase == 5 || phase == 0x20) && d2n_caed20 >= unknowne4)
		{
			for (int n = rng.chance(10) ? 2 : 1; n != 0; n--)
			{
				D2nPt loc;
				Area zone = map->getArea();
				unsigned int val = d2n_caed20 % 3000 / 300;
				int width = map->getWidth_9fcd80() / 10;
				zone.x = width * val;
				zone.x2 = zone.x + width - 1;
				do
				{
					zone.randomPoint_40be30(&loc);
				} while (map->atPoint(loc)->getChar_9b8f00() != 0x20 || map->at(loc.x + 1, loc.y)->getChar_9b8f00() != 0x20 || map->at(loc.x + 2, loc.y)->getChar_9b8f00() != 0x20 || map->at(loc.x + 3, loc.y)->getChar_9b8f00() != 0x20);
				int anim;
				switch (rng.rangeInt(1.0f, d2n_c36ecc))
				{
				case 1:
					OpU8a_lookup1("CEnding_Dust_E_Strong", &anim);
					break;
				case 2:
					OpU8a_lookup1("CEnding_Dust_E_Normal", &anim);
					break;
				case 3:
					OpU8a_lookup1("CEnding_Dust_E_Faint", &anim);
					break;
				}
				loc += offset;
				if (inBounds(loc))
					addEffect_48c460(anim, loc);
			}
			unknowne4 = d2n_d01b38.randomInRange_40c130() + d2n_caed20;
		}
		if (phase != 3)
		{
			Pos pos(offset.x + unknown98[index].x, offset.y + unknown98[index].y);
			setChar_417f50(pos.x, pos.y, d2n_cf4a00 ? 0x58 : 0x40);
			setFore_417f80(pos.x, pos.y, *d2n_cfabbc);
			int k = -1;
			if (d2n_d2c658.unknown472c70(0x54) && index + k >= 0)
			{
				Pos pos2(offset.x + unknown98[index + k].x, offset.y + unknown98[index + k].y);
				setChar_417f50(pos2.x, pos2.y, 0x58);
				setFore_417f80(pos2.x, pos2.y, *d2n_cfabbc);
				k--;
			}
			if (d2n_cf462c == 7 && index + k >= 0)
			{
				Pos pos3(offset.x + unknown98[index + k].x, offset.y + unknown98[index + k].y);
				setChar_417f50(pos3.x, pos3.y, 0x40);
				setFore_417f80(pos3.x, pos3.y, *d2n_cfabbc);
			}
			if (!unknowne8 && index == unknown98.size() - 1)
			{
				int terminal;
				OpU8a_lookup1("CEnding_Tor_Terminal", &terminal);
				addEffect_48c460(terminal, Pos(offset, 0x18, 2));
				addEffect_48c460(terminal, Pos(offset, 0x1a, 2));
				unknowne8 = true;
			}
		}
	}
	if (phase == 0x1b || phase == 0x1c || phase == 0x1d || phase == 0x1e || phase == 0x25 || phase == 0x26 || phase == 0x27)
	{
		D2nGrid *art = unknown15c.layers.front();
		for (int x = 0, px = d2n_d22318.x; x < art->getWidth_9fcd80(); x++, px++)
		{
			for (int y = 0, py = d2n_d22318.y; y < art->getHeight_9b8f00(); y++, py++)
				putCell_4181a0(px, py, art->at(x, y));
		}
	}
	if ((phase == 0x1b || phase == 0x1c) && blink_437320(500))
	{
		setChar_417f50(d2n_d22318.x + unknown16c.back().x, d2n_d22318.y + unknown16c.back().y, 0x2b);
		setFore_417f80(d2n_d22318.x + unknown16c.back().x, d2n_d22318.y + unknown16c.back().y, *d2n_d204ac);
		setBack_417fc0(d2n_d22318.x + unknown16c.back().x, d2n_d22318.y + unknown16c.back().y, d2n_d29804, 1);
	}
	if (phase == 0x1c)
	{
		int duration = d2n_bce948 - 400;
		int current = d2n_caed20 - startTime;
		int count = (int)(log10(1.0 + (float)(current * 9.0 / duration)) * 26.0);
		if (count < unknown16c.size())
		{
			setChar_417f50(d2n_d22318.x + unknown16c[count].x, d2n_d22318.y + unknown16c[count].y, 0x2a);
			setFore_417f80(d2n_d22318.x + unknown16c[count].x, d2n_d22318.y + unknown16c[count].y, *d2n_d35bbc);
			int remaining = d2n_bce948 - current;
			setFore(*d2n_d204ac);
			print(d2n_d22318.x + unknown16c[count].x + 1, d2n_d22318.y + unknown16c[count].y, "<" + intToString(remaining));
			setFore_417f80(d2n_d22318.x + unknown16c[count].x + 1, d2n_d22318.y + unknown16c[count].y, *d2n_cf6ed4);
			setBackRow_d2n(d2n_d22318.x + unknown16c[count].x + 2, d2n_d22318.y + unknown16c[count].y, intToString(remaining).size(), *d2n_cf6ed4);
		}
		for (int i = 0; i < count; i++)
		{
			setChar_417f50(d2n_d22318.x + unknown16c[i].x, d2n_d22318.y + unknown16c[i].y, 0xf9);
			setFore_417f80(d2n_d22318.x + unknown16c[i].x, d2n_d22318.y + unknown16c[i].y, *d2n_cfabbc);
		}
	}
	if (phase == 0x28)
	{
		unsigned int step = (d2n_bce978 - 250) / unknown18c.size();
		unsigned int delta = d2n_caed20 - unknown19c;
		int open;
		OpU8a_lookup1("Warlord_Map_Box", &open);
		int closed;
		OpU8a_lookup1("Warlord_Map_Box_S", &closed);
		while (delta >= step)
		{
			unknown1a0++;
				if (unknown1a0 >= unknown18c.size())
					break;
			Pos &pt = unknown18c[unknown1a0];
			for (int x = pt.x; x < pt.x + 7; x++)
			{
				for (int y = pt.y; y < pt.y + 3; y++)
					unknown188->addEffect_48c460(open, Pos(x, y));
			}
			unknown188->addEffect_48c460(closed, pt);
			delta -= step;
			unknown19c += step;
		}
	}
	if (d2n_cf4b38 == 8 && !unknown1c4.empty())
	{
		vector<XConsole*> copy(unknown1c4);
		unknown1c4.clear();
		unknown1c4.push_back(copy[0]);
		for (unsigned int i = 1; i < copy.size(); i++)
		{
			if (copy[i]->getX_48e040() <= unknown1c4.back()->getX_48e040())
				unknown1c4.push_back(copy[i]);
			else
			{
				for (unsigned int j = 0; j < unknown1c4.size(); j++)
				{
					if (copy[i]->getX_48e040() > unknown1c4[j]->getX_48e040())
					{
						d2n_insertAt(unknown1c4, j, copy[i]);
						break;
					}
				}
			}
		}
		for (unsigned int i = 0, y = d2n_d0155c.y + 0x24; i < unknown1c4.size(); i++, y++)
			unknown1c4[i]->setPos(Pos(unknown1c4[i]->getPos().x, y));
	}
	engine->render();
	render_429ea0();
}
