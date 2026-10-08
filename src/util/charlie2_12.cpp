// Console cell effects (0x7ad6a0; callers: map labels, timers, console animate): spawns an engine effect on the
// console cells picked by a pattern id (all cells, non-blank cells, borders, rows, columns, center lines, wipes...),
// or at a console anchor for pattern ids above 47.
// NOTE: placeholder names and layouts throughout (C2F*, c2f_<address>).
#include <ctype.h>

struct C2FPos { int x, y; C2FPos(); C2FPos(int v); C2FPos(int nx, int ny); C2FPos(const C2FPos &o); void add409a30(const C2FPos &d); };
struct C2FColor { unsigned char r, g, b; C2FColor(const C2FColor &o); bool operator!=(C2FColor o); };
struct C2FEffect { void init50de10(); };
struct C2FEngine { C2FEffect *f50fb50(C2FEngine *engine, int type, const C2FPos &from, C2FPos *data, C2FPos *to, C2FPos *toData, int layer); };
struct C2FCell { bool f66b460(); bool f66b4b0(); bool f66b510(); bool f66b560(); bool f66b5b0(); };
struct C2FMap { C2FCell **at(int x, int y); };
struct C2FView { const C2FPos &f458ef0(); void f8051f0(C2FPos &a, C2FPos &b); };
extern C2FMap c2f_cfd44c;
extern C2FView *c2f_cec054;
extern C2FPos c2f_cfbec0;
extern C2FColor c2f_d29804;
extern C2FColor &c2f_d20cfc;
int c2f_maxInt(int a, int b);
bool c2f_between(int lo, int v, int hi);
bool c2f_isEven(int v);

class Console
{
public:
	int c2f_getWidth();
	int c2f_getHeight();
	int c2f_getChar(int x, int y);
	C2FColor c2f_getBack(int x, int y);
	C2FPos c2f_getPos();
	C2FPos c2f_getAnchor(int anchor);
	void unknown7ad6a0(int effect, int pattern, int anchor2, int start, int end);
	char pad00[0x64];
	C2FEngine *engine;
	Console *title;
};

#define C2F_FX(con, p) do { (con)->engine->f50fb50((con)->engine, effect, p, &c2f_cfbec0, 0, 0, 9)->init50de10(); } while (0)
#define C2F_FX2(p, q) do { engine->f50fb50(engine, effect, p, &c2f_cfbec0, &q, &c2f_cfbec0, 9)->init50de10(); } while (0)

void Console::unknown7ad6a0(int effect, int pattern, int anchor2, int start, int end)
{
	if (pattern <= 0x2f)
	{
		switch (pattern)
		{
		case 1:
			for (int x = start; x < c2f_getWidth() + end; x++)
				for (int y = start; y < c2f_getHeight() + end; y++)
					C2F_FX(this, C2FPos(x, y));
			break;
		case 2:
			for (int i = 0; i < title->c2f_getWidth(); i++)
				C2F_FX(title, C2FPos(i, 0));
			break;
		case 3:
			for (int x = start; x < c2f_getWidth() + end; x++)
				for (int y = start; y < c2f_getHeight() + end; y++)
					if (c2f_getChar(x, y) != ' ')
						C2F_FX(this, C2FPos(x, y));
			break;
		case 4:
			for (int i = 0; i < title->c2f_getWidth(); i++)
				if (title->c2f_getChar(i, 0) != ' ')
					C2F_FX(title, C2FPos(i, 0));
			break;
		case 5:
			for (int x = start; x < c2f_getWidth() + end; x++)
				for (int y = start; y < c2f_getHeight() + end; y++)
					if (isalpha(c2f_getChar(x, y)) || isdigit(c2f_getChar(x, y)))
						C2F_FX(this, C2FPos(x, y));
			break;
		case 6:
			for (int x = start; x < c2f_getWidth() + end; x++)
				for (int y = start; y < c2f_getHeight() + end; y++)
					if ((c2f_getChar(x, y) != ' ' || c2f_getBack(x, y) != c2f_d29804) && c2f_getBack(x, y) != c2f_d20cfc)
						C2F_FX(this, C2FPos(x, y));
			break;
		case 7:
			for (int x = start; x < c2f_getWidth() + end; x++)
				for (int y = start; y < c2f_getHeight() + end; y++)
					if (c2f_getChar(x, y) == ' ')
						C2F_FX(this, C2FPos(x, y));
			break;
		case 8:
			for (int x = start; x < c2f_getWidth() + end; x++)
				for (int y = start; y < c2f_getHeight() + end; y++)
					if (c2f_getBack(x, y) != c2f_d29804 && c2f_getBack(x, y) != c2f_d20cfc)
						C2F_FX(this, C2FPos(x, y));
			break;
		case 9:
		{
			C2FPos first;
			C2FPos last;
			C2FPos offset = c2f_cec054->f458ef0();
			c2f_cec054->f8051f0(first, last);
			first.add409a30(start);
			last.add409a30(end);
			for (int x = c2f_maxInt(offset.x, start), cx = first.x; x < c2f_getWidth() + end && cx <= last.x; x++, cx++)
				for (int y = c2f_maxInt(offset.y, start), cy = first.y; y < c2f_getHeight() + end && cy <= last.y; y++, cy++)
					if ((*c2f_cfd44c.at(cx, cy))->f66b460())
						C2F_FX(this, C2FPos(x, y));
			break;
		}
		case 10:
		{
			C2FPos first;
			C2FPos last;
			C2FPos offset = c2f_cec054->f458ef0();
			c2f_cec054->f8051f0(first, last);
			first.add409a30(start);
			last.add409a30(end);
			for (int x = c2f_maxInt(offset.x, start), cx = first.x; x < c2f_getWidth() + end && cx <= last.x; x++, cx++)
				for (int y = c2f_maxInt(offset.y, start), cy = first.y; y < c2f_getHeight() + end && cy <= last.y; y++, cy++)
					if ((*c2f_cfd44c.at(cx, cy))->f66b4b0())
						C2F_FX(this, C2FPos(x, y));
			break;
		}
		case 11:
		{
			C2FPos first;
			C2FPos last;
			C2FPos offset = c2f_cec054->f458ef0();
			c2f_cec054->f8051f0(first, last);
			first.add409a30(start);
			last.add409a30(end);
			for (int x = c2f_maxInt(offset.x, start), cx = first.x; x < c2f_getWidth() + end && cx <= last.x; x++, cx++)
				for (int y = c2f_maxInt(offset.y, start), cy = first.y; y < c2f_getHeight() + end && cy <= last.y; y++, cy++)
					if ((*c2f_cfd44c.at(cx, cy))->f66b510())
						C2F_FX(this, C2FPos(x, y));
			break;
		}
		case 12:
		{
			C2FPos first;
			C2FPos last;
			C2FPos offset = c2f_cec054->f458ef0();
			c2f_cec054->f8051f0(first, last);
			first.add409a30(start);
			last.add409a30(end);
			for (int x = c2f_maxInt(offset.x, start), cx = first.x; x < c2f_getWidth() + end && cx <= last.x; x++, cx++)
				for (int y = c2f_maxInt(offset.y, start), cy = first.y; y < c2f_getHeight() + end && cy <= last.y; y++, cy++)
					if ((*c2f_cfd44c.at(cx, cy))->f66b560())
						C2F_FX(this, C2FPos(x, y));
			break;
		}
		case 13:
		{
			C2FPos first;
			C2FPos last;
			C2FPos offset = c2f_cec054->f458ef0();
			c2f_cec054->f8051f0(first, last);
			first.add409a30(start);
			last.add409a30(end);
			for (int x = c2f_maxInt(offset.x, start), cx = first.x; x < c2f_getWidth() + end && cx <= last.x; x++, cx++)
				for (int y = c2f_maxInt(offset.y, start), cy = first.y; y < c2f_getHeight() + end && cy <= last.y; y++, cy++)
					if ((*c2f_cfd44c.at(cx, cy))->f66b5b0())
						C2F_FX(this, C2FPos(x, y));
			break;
		}
		case 14:
			for (int x = start; x < c2f_getWidth() + end; x++)
			{
				C2F_FX(this, C2FPos(x, 0));
				C2F_FX(this, C2FPos(x, c2f_getHeight() - 1));
			}
			for (int y = start ? start : 1; y < c2f_getHeight() + (end ? end : -1); y++)
			{
				C2F_FX(this, C2FPos(0, y));
				C2F_FX(this, C2FPos(c2f_getWidth() - 1, y));
			}
			break;
		case 15:
			if (c2f_between(0, start, c2f_getWidth() - 1))
				for (int i = 0; i < c2f_getHeight(); i++)
					C2F_FX(this, C2FPos(start, i));
			break;
		case 16:
			if (c2f_between(0, start, c2f_getHeight() - 1))
				for (int i = 0; i < c2f_getWidth(); i++)
					C2F_FX(this, C2FPos(i, start));
			break;
		case 17:
			for (int x = start; x < c2f_getWidth() + end; x++)
				C2F_FX(this, C2FPos(x, 0));
			break;
		case 18:
			for (int x = start; x < title->c2f_getPos().x; x++)
				C2F_FX(this, C2FPos(x, 0));
			for (int x = title->c2f_getPos().x + title->c2f_getWidth(); x < c2f_getWidth() + end; x++)
				C2F_FX(this, C2FPos(x, 0));
			break;
		case 19:
			for (int x = start; x < c2f_getWidth() + end; x++)
				C2F_FX(this, C2FPos(x, c2f_getHeight() - 1));
			break;
		case 20:
			for (int y = start; y < c2f_getHeight() + end; y++)
				C2F_FX(this, C2FPos(0, y));
			break;
		case 21:
			for (int y = start; y < c2f_getHeight() + end; y++)
				C2F_FX(this, C2FPos(c2f_getWidth() - 1, y));
			break;
		case 22:
		case 23:
			for (int y = start; y < c2f_getHeight() + end; y++)
				C2F_FX(this, C2FPos(c2f_getWidth() / 2, y));
			break;
		case 24:
			for (int y = start; y < c2f_getHeight() + end; y++)
				C2F_FX(this, C2FPos(c2f_getWidth() / 2 + 1, y));
			break;
		case 25:
		case 26:
			for (int x = start; x < c2f_getWidth() + end; x++)
				C2F_FX(this, C2FPos(x, c2f_getHeight() / 2));
			break;
		case 27:
			for (int x = start; x < c2f_getWidth() + end; x++)
				C2F_FX(this, C2FPos(x, c2f_getHeight() / 2 + 1));
			break;
		case 28:
			for (int x = 0; x < c2f_getWidth(); x++)
				for (int y = 0; y < c2f_getHeight(); y++)
					if (c2f_getChar(x, y) == start)
						C2F_FX(this, C2FPos(x, y));
			break;
		case 29:
			for (int y = 0; y < c2f_getHeight(); y++)
				for (int x = 0; x < c2f_getWidth(); x++)
					if (c2f_getChar(x, y) == start)
					{
						C2F_FX(this, C2FPos(x, y));
						goto done29;
					}
		done29:
			break;
		case 30:
			for (int y = c2f_getHeight() - 1; y >= 0; y--)
				for (int x = c2f_getWidth() - 1; x >= 0; x--)
					if (c2f_getChar(x, y) == start)
					{
						C2F_FX(this, C2FPos(x, y));
						goto done30;
					}
		done30:
			break;
		case 31:
			for (int y = 0; y < c2f_getHeight(); y++)
				for (int x = 0; x < c2f_getWidth(); x++)
					if (c2f_getChar(x, y) == start)
						C2F_FX(this, C2FPos(x, y));
			break;
		case 32:
			for (int y = 0; y < c2f_getHeight(); y++)
				for (int x = 0; x < c2f_getWidth(); x++)
					if (c2f_getChar(x, y) != start)
						C2F_FX(this, C2FPos(x, y));
					else
						goto done32;
		done32:
			break;
		case 33:
			for (int y = 0; y < c2f_getHeight(); y++)
				for (int x = 0; x < c2f_getWidth(); x++)
					if (c2f_getChar(x, y) == start)
						C2F_FX(this, C2FPos(x, y));
					else
						goto done33;
		done33:
			break;
		case 34:
			for (int y = c2f_getHeight() - 1; y >= 0; y--)
				for (int x = c2f_getWidth() - 1; x >= 0; x--)
					if (c2f_getChar(x, y) != start)
						C2F_FX(this, C2FPos(x, y));
					else
						goto done34;
		done34:
			break;
		case 35:
			for (int y = c2f_getHeight() - 1; y >= 0; y--)
				for (int x = c2f_getWidth() - 1; x >= 0; x--)
					if (c2f_getChar(x, y) == start)
						C2F_FX(this, C2FPos(x, y));
					else
						goto done35;
		done35:
			break;
		case 36:
			for (int x = start; x < c2f_getWidth() + end; x++)
				C2F_FX2(C2FPos(x, 0), C2FPos(x, c2f_getHeight() - 1));
			break;
		case 37:
			for (int x = start; x < c2f_getWidth() + end; x++)
				C2F_FX2(C2FPos(x, c2f_getHeight() - 1), C2FPos(x, 0));
			break;
		case 38:
			for (int y = start; y < c2f_getHeight() + end; y++)
				C2F_FX2(C2FPos(0, y), C2FPos(c2f_getWidth() - 1, y));
			break;
		case 39:
			for (int y = start; y < c2f_getHeight() + end; y++)
				C2F_FX2(C2FPos(c2f_getWidth() - 1, y), C2FPos(0, y));
			break;
		case 40:
			for (int x = start; x < c2f_getWidth() + end; x++)
				C2F_FX2(C2FPos(x, 1), C2FPos(x, c2f_getHeight() - 2));
			break;
		case 41:
			for (int x = start; x < c2f_getWidth() + end; x++)
				C2F_FX2(C2FPos(x, c2f_getHeight() - 2), C2FPos(x, 1));
			break;
		case 42:
			for (int y = start; y < c2f_getHeight() + end; y++)
				C2F_FX2(C2FPos(1, y), C2FPos(c2f_getWidth() - 2, y));
			break;
		case 43:
			for (int y = start; y < c2f_getHeight() + end; y++)
				C2F_FX2(C2FPos(c2f_getWidth() - 2, y), C2FPos(1, y));
			break;
		case 44:
			if (c2f_isEven(c2f_getWidth()))
				for (int y = start; y < c2f_getHeight() + end; y++)
					C2F_FX2(C2FPos(c2f_getWidth() / 2, y), C2FPos(0, y));
			else
				for (int y = start; y < c2f_getHeight() + end; y++)
					C2F_FX2(C2FPos(c2f_getWidth() / 2, y), C2FPos(0, y));
			break;
		case 45:
			if (c2f_isEven(c2f_getWidth()))
				for (int y = start; y < c2f_getHeight() + end; y++)
					C2F_FX2(C2FPos(c2f_getWidth() / 2 + 1, y), C2FPos(c2f_getWidth() - 1, y));
			else
				for (int y = start; y < c2f_getHeight() + end; y++)
					C2F_FX2(C2FPos(c2f_getWidth() / 2, y), C2FPos(c2f_getWidth() - 1, y));
			break;
		case 46:
			if (c2f_isEven(c2f_getWidth()))
				for (int x = start; x < c2f_getWidth() + end; x++)
					C2F_FX2(C2FPos(x, c2f_getHeight() / 2), C2FPos(x, 0));
			else
				for (int x = start; x < c2f_getWidth() + end; x++)
					C2F_FX2(C2FPos(x, c2f_getHeight() / 2), C2FPos(x, 0));
			break;
		case 47:
			if (c2f_isEven(c2f_getWidth()))
				for (int x = start; x < c2f_getWidth() + end; x++)
					C2F_FX2(C2FPos(x, c2f_getHeight() / 2 + 1), C2FPos(x, c2f_getHeight() - 1));
			else
				for (int x = start; x < c2f_getWidth() + end; x++)
					C2F_FX2(C2FPos(x, c2f_getHeight() / 2), C2FPos(x, c2f_getHeight() - 1));
			break;
		}
	}
	else if (anchor2)
		do { engine->f50fb50(engine, effect, c2f_getAnchor(pattern), &c2f_cfbec0, &c2f_getAnchor(anchor2), &c2f_cfbec0, 9)->init50de10(); } while (0);
	else
		do { engine->f50fb50(engine, effect, c2f_getAnchor(pattern), &c2f_cfbec0, 0, 0, 9)->init50de10(); } while (0);
}
