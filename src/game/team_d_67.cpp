// team_d_67: members 0x5031d0 and 0x502ba0 of the effect-instance class initialized by 0x503b20 (fires the
// definition's emitter rules matching a trigger; waveform value of a rule).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p) throw();	// 0x46ca50
};

class RNG
{
public:
	bool chance(int percent);
	int rangeInt(float lo, float hi);
};
extern RNG rng;

class OpR5h_Grid	// NOTE: placeholder name (0xcfd44c)
{
public:
	bool contains(const Point &p);
};
extern OpR5h_Grid cells67_cfd44c;	// NOTE: placeholder name

struct Rule67	// NOTE: placeholder name (E3c_0)
{
	int		unknown00;
	int		trigger;	// +0x04
	float	delay;		// +0x08 (also the waveform base)
	int		wave;		// +0x0c
	float	param;		// +0x10
	int		chance;		// +0x14
	int		count;		// +0x18 (negative: random 1..-count)
	int		max;		// +0x1c
	char	pad20[0x3c - 0x20];
};

struct RuleState67	// NOTE: placeholder name (vector folded with vector<Point>)
{
	unsigned int	timer;
	int				fired;
};

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

struct NoiseOwner67	// NOTE: placeholder name and layout
{
	char				pad00[0x44];
	OpR1b_NoiseField	noise;	// +0x44
};

float OpT8b_Fn9d5ac0(float low, float high, float value);	// NOTE: placeholder name (clamp)
float maxf(float a, float b);
float sin(float x);
#include <math.h>

struct Def67	// NOTE: placeholder name and layout
{
	char			pad000[0xb8];
	vector<Rule67>	rules;
};

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern unsigned int step67_cefa78;	// NOTE: placeholder name

class Effect67	// NOTE: placeholder name and layout
{
public:
	Def67					*def;
	NoiseOwner67			*owner;		// +0x04
	unsigned int			start;		// +0x08
	unsigned int			end;		// +0x0c
	OpR1b_Point				pos;		// +0x10
	char					pad18[0x34 - 0x18];
	float					unknown34;
	char					pad38[0x94 - 0x38];
	vector<RuleState67>		states;

	bool unknown5020a0(const Rule67 &rule, Point pos);	// NOTE: placeholder name
	float unknown502ba0(const Rule67 &mode);			// NOTE: placeholder name (waveform value)
	void unknown5031d0(int trigger, const Point &pos);			// NOTE: placeholder name
};

#define PI67 3.1415927410125732		// NOTE: (double)3.14159265f
#define TWO_PI67 6.2831854820251465		// NOTE: (double)6.2831853f
#define HALF_PI67 1.5707963705062866	// NOTE: (double)1.57079633f

float Effect67::unknown502ba0(const Rule67 &mode)
{
	switch (mode.wave)
	{
	case 0:
		return mode.delay;
	case 1:
		return OpT8b_Fn9d5ac0(0.0f,1.0f,(tickCount - start) * mode.param + mode.delay);
	case 2:
		return sin((float)((float)((int)(float)(tickCount - start) % (int)mode.param) / mode.param * PI67)) * mode.delay;
	case 3:
		return maxf(0.0f,sin((float)((float)((int)(float)(tickCount - start) % (int)mode.param) / mode.param * TWO_PI67))) * mode.delay;
	case 4:
		return mode.delay / 2.0 + mode.delay / 2.0 * sin((float)((float)((int)(float)(tickCount - start) % (int)(mode.param / 2.0)) / (mode.param / 2.0) * PI67));
	case 5:
		return owner->noise.sample(&pos) * (mode.param - mode.delay) + mode.delay;
	case 6:
		return (float)(tickCount - start) / (float)(end - start) * mode.delay;
	case 7:
		return mode.delay - (float)(tickCount - start) / (float)(end - start) * mode.delay;
	case 8:
		return sin((float)((float)(tickCount - start) / (float)(end - start) * HALF_PI67)) * mode.delay;
	case 9:
		return (mode.param - mode.delay) * sin((float)((float)(tickCount - start) / (float)(end - start) * HALF_PI67)) + mode.delay;
	case 10:
		return sin((float)((float)(tickCount - start) / (float)(end - start) * PI67)) * mode.delay;
	case 11:
		return (mode.param - mode.delay) * sin((float)((float)(tickCount - start) / (float)(end - start) * PI67)) + mode.delay;
	case 12:
		return mode.delay - sin((float)((float)(tickCount - start) / (float)(end - start) * HALF_PI67)) * mode.delay;
	case 13:
		return mode.delay + (mode.param - mode.delay) * sin((1.0 - (float)(tickCount - start) / (float)(end - start)) * HALF_PI67);
	}
	return 1.0f;
}

void Effect67::unknown5031d0(int trigger, const Point &pos)
{
	if (!cells67_cfd44c.contains(pos))
		return;
	for (unsigned int i = 0; i < def->rules.size(); i++)
	{
		const Rule67 &r = def->rules[i];
		if (r.trigger == trigger && (!r.max || states[i].fired < r.max) && (!r.chance || rng.chance(r.chance)))
		{
			switch (trigger)
			{
			case 0:
				if (states[i].timer == 0 && r.delay <= tickCount - start)
				{
fire:
					states[i].timer = 1;
					int count = r.count < 0 ? rng.rangeInt(1,-r.count) : r.count;
					for (int j = 0; j < count && (!r.max || states[i].fired < r.max); j++)
					{
						if (unknown5020a0(r,pos))
							states[i].fired++;
					}
				}
				break;
			case 1:
				if (states[i].timer == 0 && unknown34 >= 0.0)
					goto fire;
				break;
			case 2:
				{
					states[i].timer += step67_cefa78;
					float score = unknown502ba0(r);
					while (score <= states[i].timer && (!r.max || states[i].fired < r.max))
					{
						int count = r.count < 0 ? rng.rangeInt(1,-r.count) : r.count;
						for (int j = 0; j < count && (!r.max || states[i].fired < r.max); j++)
						{
							if (unknown5020a0(r,pos))
								states[i].fired++;
						}
						states[i].timer -= score;
					}
				}
				break;
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				{
					int count = r.count < 0 ? rng.rangeInt(1,-r.count) : r.count;
					for (int j = 0; j < count && (!r.max || states[i].fired < r.max); j++)
					{
						if (unknown5020a0(r,pos))
							states[i].fired++;
					}
				}
				break;
			}
		}
	}
}
