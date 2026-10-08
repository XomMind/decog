// team_d_69: members 0x50c890 (waveform value) and 0x50ced0 (fire the emitter rules matching a trigger)
// of the particle class (callers 0x50de10/0x50e890).
// NOTE: names and layouts are placeholders (same waveform table as team_d_67's 0x502ba0, with the
// noise field taken from the engine object at 0xcefc64).
struct OpR1b_Point
{
	int x;
	int y;
};

class OpR1b_NoiseField	// NOTE: placeholder name
{
public:
	float sample(OpR1b_Point *pos);	// 0x421770
};

struct Engine69	// NOTE: placeholder name and layout (0xcefc64)
{
	char				pad00[0x34];
	OpR1b_NoiseField	noise;	// +0x34
};
extern Engine69 *engine69_cefc64;	// NOTE: placeholder name

#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p) throw();	// 0x46ca50
	Point subtract(const Point &p) const;	// NOTE: placeholder name (PushCoord::subtract)
};

class RNG
{
public:
	bool chance(int percent);
	int rangeInt(float lo, float hi);
};
extern RNG rng;

class Cell
{
public:
	bool unknown66b460();	// NOTE: placeholder name
	bool unknown66b4b0();	// NOTE: placeholder name
	bool unknown66b510();	// NOTE: placeholder name
	bool unknown66b560();	// NOTE: placeholder name
	bool unknown66b5b0();	// NOTE: placeholder name
};

class CellGrid69	// NOTE: placeholder name (0xcfd44c)
{
public:
	bool contains(const Point &p);	// NOTE: folded (OpR5h_Grid::contains)
	Cell **atPoint(Point &p);		// NOTE: folded (OpX5_Array2D<int>::atPoint)
};
extern CellGrid69 cells69_cfd44c;	// NOTE: placeholder name

class CMap69	// NOTE: placeholder name (0xcec054)
{
public:
	const Point &unknown458ef0();	// NOTE: placeholder name (trivial getter)
};
extern CMap69 *cmap69_cec054;	// NOTE: placeholder name

class Area69	// NOTE: placeholder name (Predicate_454c20)
{
public:
	bool test(const Point &p);
};

struct Mode69	// NOTE: placeholder name and layout (E48_0: a 0x48-byte emitter rule)
{
	int		unknown00;
	int		trigger;	// +0x04
	float	delay;		// +0x08 (waveform base)
	int		wave;		// +0x0c
	float	param;		// +0x10
	int		chance;		// +0x14
	int		unknown18;
	int		count;		// +0x1c (negative: random 1..-count)
	int		max;		// +0x20
	char	pad24[0x48 - 0x24];
};

struct RuleState69	// NOTE: placeholder name (vector folded with vector<Point>)
{
	unsigned int	timer;
	int				fired;
};

struct Def69	// NOTE: placeholder name and layout
{
	char			pad000[0xcc];
	vector<Mode69>	rules;
};

extern unsigned int step69_cefa78;	// NOTE: placeholder name

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
float OpT8b_Fn9d5ac0(float low, float high, float value);	// NOTE: placeholder name (clamp)
float maxf(float a, float b);
float sin(float x);
#include <math.h>

class Particle69	// NOTE: placeholder name and layout
{
public:
	Def69			*def;		// +0x00
	Area69			*area;		// +0x04
	unsigned int	start;		// +0x08
	unsigned int	end;		// +0x0c
	OpR1b_Point		pos;		// +0x10
	char			pad18[0x84 - 0x18];
	vector<RuleState69>	states;	// +0x84

	bool unknown5098e0(const Mode69 &rule, Point pos);	// NOTE: placeholder name
	float unknown50c890(const Mode69 &mode);	// NOTE: placeholder name (waveform value)
	bool unknown50ced0(int trigger, const Point &pos);	// NOTE: placeholder name
};

#define PI69 3.1415927410125732		// NOTE: (double)3.14159265f
#define TWO_PI69 6.2831854820251465		// NOTE: (double)6.2831853f
#define HALF_PI69 1.5707963705062866	// NOTE: (double)1.57079633f

float Particle69::unknown50c890(const Mode69 &mode)
{
	switch (mode.wave)
	{
	case 0:
	case 1:
		return mode.delay;
	case 2:
		return OpT8b_Fn9d5ac0(0.0f,1.0f,(tickCount - start) * mode.param + mode.delay);
	case 3:
		return sin((float)((float)((int)(float)(tickCount - start) % (int)mode.param) / mode.param * PI69)) * mode.delay;
	case 4:
		return maxf(0.0f,sin((float)((float)((int)(float)(tickCount - start) % (int)mode.param) / mode.param * TWO_PI69))) * mode.delay;
	case 5:
		return mode.delay / 2.0 + mode.delay / 2.0 * sin((float)((float)((int)(float)(tickCount - start) % (int)(mode.param / 2.0)) / (mode.param / 2.0) * PI69));
	case 6:
		return engine69_cefc64->noise.sample(&pos) * (mode.param - mode.delay) + mode.delay;
	case 7:
		return (float)(tickCount - start) / (float)(end - start) * mode.delay;
	case 8:
		return mode.delay - (float)(tickCount - start) / (float)(end - start) * mode.delay;
	case 9:
		return sin((float)((float)(tickCount - start) / (float)(end - start) * HALF_PI69)) * mode.delay;
	case 10:
		return (mode.param - mode.delay) * sin((float)((float)(tickCount - start) / (float)(end - start) * HALF_PI69)) + mode.delay;
	case 11:
		return sin((float)((float)(tickCount - start) / (float)(end - start) * PI69)) * mode.delay;
	case 12:
		return (mode.param - mode.delay) * sin((float)((float)(tickCount - start) / (float)(end - start) * PI69)) + mode.delay;
	case 13:
		return mode.delay - sin((float)((float)(tickCount - start) / (float)(end - start) * HALF_PI69)) * mode.delay;
	case 14:
		return mode.delay + (mode.param - mode.delay) * sin((1.0 - (float)(tickCount - start) / (float)(end - start)) * HALF_PI69);
	}
	return 1.0f;
}


bool Particle69::unknown50ced0(int trigger, const Point &pos)
{
	if (!area->test(pos))
		return false;
	bool found = false;
	for (unsigned int i = 0; i < def->rules.size(); i++)
	{
		const Mode69 &r = def->rules[i];
		if (r.trigger == trigger && (!r.max || states[i].fired < r.max) && (!r.chance || rng.chance(r.chance)))
		{
			switch (trigger)
			{
			case 0:
				if (states[i].timer == 0 && r.delay <= tickCount - start)
				{
					states[i].timer = 1;
					int count = r.count < 0 ? rng.rangeInt(1,-r.count) : r.count;
					for (int j = 0; j < count && (!r.max || states[i].fired < r.max); j++)
					{
						if (unknown5098e0(r,pos))
						{
							states[i].fired++;
							if (r.wave == 1)
								found = true;
						}
					}
				}
				break;
			case 1:
				{
					states[i].timer += step69_cefa78;
					unsigned int step = unknown50c890(r);
					while (states[i].timer >= step && (!r.max || states[i].fired < r.max))
					{
						int count = r.count < 0 ? rng.rangeInt(1,-r.count) : r.count;
						for (int j = 0; j < count && (!r.max || states[i].fired < r.max); j++)
						{
							if (unknown5098e0(r,pos))
							{
								states[i].fired++;
								if (r.wave == 1)
									found = true;
							}
						}
						states[i].timer -= step;
					}
				}
				break;
			case 2:
			case 3:
			case 4:
			case 5:
				{
					if (r.delay != 0.0)
					{
						Point p = ((Point *)&this->pos)->subtract(cmap69_cec054->unknown458ef0());
						if (!cells69_cfd44c.contains(p))
							goto next;
						switch ((int)r.delay)
						{
						case 1:
							if (!(*cells69_cfd44c.atPoint(p))->unknown66b460())
								goto next;
							break;
						case 2:
							if (!(*cells69_cfd44c.atPoint(p))->unknown66b4b0())
								goto next;
							break;
						case 3:
							if (!(*cells69_cfd44c.atPoint(p))->unknown66b510())
								goto next;
							break;
						case 4:
							if (!(*cells69_cfd44c.atPoint(p))->unknown66b560())
								goto next;
							break;
						case 5:
							if (!(*cells69_cfd44c.atPoint(p))->unknown66b5b0())
								goto next;
							break;
						}
					}
					int count = r.count < 0 ? rng.rangeInt(1,-r.count) : r.count;
					for (int j = 0; j < count && (!r.max || states[i].fired < r.max); j++)
					{
						if (unknown5098e0(r,pos))
						{
							states[i].fired++;
							if (r.wave == 1)
								found = true;
						}
					}
				}
				break;
			}
		}
next:;
	}
	return found;
}
