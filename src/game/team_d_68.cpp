// team_d_68: animated blend alpha (0x5012f0) and blend modes (0x5019c0) of the effect-tile class
// whose definition data hangs off +0xb4 (the 0x503b20/0x508360 effect family).
// NOTE: names and layouts are placeholders; XColor's static blend helpers carry their exe names.
struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &c);
	XColor &operator=(XColor c);
	static XColor add(XColor a, XColor b);
	static XColor subtract(XColor a, XColor b);
	static XColor multiply(XColor a, XColor b);
	static XColor scale(XColor a, float value);
	static XColor lerp(XColor a, XColor b, float alpha);
	static XColor addAlpha(XColor a, XColor b, float alpha);
	static XColor subtractAlpha(XColor a, XColor b, float alpha);
	static XColor screen(XColor a, XColor b);
	static XColor colorDodge(XColor a, XColor b);
	static XColor colorBurn(XColor a, XColor b);
	static XColor burn(XColor a, XColor b);
	static XColor overlay(XColor a, XColor b);
	static XColor shiftHue(XColor a, int shift);
};
extern XColor col68_d02364;	// NOTE: placeholder name
extern XColor &col68_cfe674;	// NOTE: placeholder name
extern XColor &col68_d1ecd4;	// NOTE: placeholder name
extern XColor &col68_cfabbc;	// NOTE: placeholder name

struct Point68	// NOTE: placeholder name
{
	int x;
	int y;
};

class NoiseField68	// NOTE: placeholder name (OpR1b_NoiseField)
{
public:
	float sample(Point68 *pos);
};

struct NoiseOwner68	// NOTE: placeholder name and layout
{
	char			pad00[0x44];
	NoiseField68	noise;	// +0x44
};

class OpV4c_View
{
public:
	const int *getConst(Point68 *p);
};

class Item68	// NOTE: placeholder name (OpU2_Item)
{
public:
	XColor *unknown5755f0(bool force);	// NOTE: placeholder name
};

class HItem68	// NOTE: placeholder name
{
	int ID;
public:
	bool isValid() const;
	Item68 *operator->() const;
	operator Item68 *() const;	// NOTE: folded with operator->
};

class Source68	// NOTE: placeholder name (OpR2b_Obj500d50)
{
public:
	XColor getColor();				// NOTE: placeholder name
	XColor unknown454580();			// NOTE: placeholder name
};

struct Data68	// NOTE: placeholder name and layout
{
	char			pad00[0x0c];
	OpV4c_View		*view;		// +0x0c
	char			pad10[0x1c - 0x10];
	HItem68			item1c;		// +0x1c
	HItem68			item20;		// +0x20
	char			pad24[0x60 - 0x24];
	Source68		*source;	// +0x60
};

struct AlphaMode68	// NOTE: placeholder name and layout
{
	int		blend;		// +0x00
	int		unknown04;
	float	base;		// +0x08
	int		type;		// +0x0c
	float	param;		// +0x10
};

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
float OpT8b_Fn9d5ac0(float low, float high, float value);	// NOTE: placeholder name (clamp)
float maxf(float a, float b);
float sin(float x);
#include <math.h>

class Blender68	// NOTE: placeholder name and layout
{
public:
	int				unknown00;
	NoiseOwner68	*owner;		// +0x04
	unsigned int	start;		// +0x08
	unsigned int	end;		// +0x0c
	Point68			pos;		// +0x10
	char			pad18[8];
	Point68			pos20;		// +0x20
	char			pad28[0x90 - 0x28];
	XColor			color;		// +0x90
	char			pad93[0xb4 - 0x93];
	Data68			*data;		// +0xb4

	float unknown5012f0(AlphaMode68 *mode);	// NOTE: placeholder name
	void unknown5019c0(const XColor &back, AlphaMode68 *mode, const XColor &fore);	// NOTE: placeholder name
};

#define PI68 3.1415927410125732		// NOTE: (double)3.14159265f
#define TWO_PI68 6.2831854820251465		// NOTE: (double)6.2831853f
#define HALF_PI68 1.5707963705062866	// NOTE: (double)1.57079633f

float Blender68::unknown5012f0(AlphaMode68 *mode)
{
	switch (mode->type)
	{
	case 0:
		return mode->base;
	case 1:
		return *data->view->getConst(&pos20) == 0 ? 0.0 : (double)*data->view->getConst(&pos) / *data->view->getConst(&pos20);
	case 2:
		return OpT8b_Fn9d5ac0(0.0f,1.0f,(tickCount - start) * mode->param + mode->base);
	case 3:
		return sin((float)((float)((int)(float)(tickCount - start) % (int)mode->param) / mode->param * PI68)) * mode->base;
	case 4:
		return maxf(0.0f,sin((float)((float)((int)(float)(tickCount - start) % (int)mode->param) / mode->param * TWO_PI68))) * mode->base;
	case 5:
		return mode->base / 2.0 + mode->base / 2.0 * sin((float)((float)((int)(float)(tickCount - start) % (int)(mode->param / 2.0)) / (mode->param / 2.0) * PI68));
	case 6:
		return owner->noise.sample(&pos) * (mode->param - mode->base) + mode->base;
	case 7:
		return (float)(tickCount - start) / (float)(end - start) * mode->base;
	case 8:
		return mode->base - (float)(tickCount - start) / (float)(end - start) * mode->base;
	case 9:
		return sin((float)((float)(tickCount - start) / (float)(end - start) * HALF_PI68)) * mode->base;
	case 10:
		return mode->base + (1.0 - mode->base) * sin((float)((float)(tickCount - start) / (float)(end - start) * HALF_PI68));
	case 11:
		return sin((float)((float)(tickCount - start) / (float)(end - start) * PI68)) * mode->base;
	case 12:
		return mode->base + (1.0 - mode->base) * sin((float)((float)(tickCount - start) / (float)(end - start) * PI68));
	case 13:
		return mode->base - sin((float)((float)(tickCount - start) / (float)(end - start) * HALF_PI68)) * mode->base;
	case 14:
		return mode->base + (1.0 - mode->base) * sin((1.0 - (float)(tickCount - start) / (float)(end - start)) * HALF_PI68);
	}
	return 1.0f;
}

void Blender68::unknown5019c0(const XColor &back, AlphaMode68 *mode, const XColor &fore)
{
	switch (mode->blend)
	{
	case 0:
		col68_d02364 = back;
		break;
	case 1:
		col68_d02364 = fore;
		break;
	case 2:
		col68_d02364 = XColor::add(back,fore);
		break;
	case 3:
		col68_d02364 = XColor::subtract(back,fore);
		break;
	case 4:
		col68_d02364 = XColor::multiply(back,fore);
		break;
	case 5:
		col68_d02364 = XColor::scale(back,unknown5012f0(mode));
		break;
	case 6:
		col68_d02364 = XColor::lerp(back,fore,unknown5012f0(mode));
		break;
	case 7:
		col68_d02364 = XColor::addAlpha(back,fore,unknown5012f0(mode));
		break;
	case 8:
		col68_d02364 = XColor::subtractAlpha(back,fore,unknown5012f0(mode));
		break;
	case 9:
		col68_d02364 = XColor::screen(back,fore);
		break;
	case 10:
		col68_d02364 = XColor::colorDodge(back,fore);
		break;
	case 11:
		col68_d02364 = XColor::colorBurn(back,fore);
		break;
	case 12:
		col68_d02364 = XColor::burn(back,fore);
		break;
	case 13:
		col68_d02364 = XColor::overlay(back,fore);
		break;
	case 14:
		col68_d02364 = XColor::shiftHue(back,(int)(unknown5012f0(mode) * 360.0));
		break;
	case 15:
		col68_d02364 = data->item1c.isValid() ? (data->item1c ? *data->item1c->unknown5755f0(0) : col68_cfe674) : (data->item20.isValid() ? *data->item20->unknown5755f0(0) : col68_d1ecd4);
		break;
	case 16:
		col68_d02364 = data->source ? data->source->getColor() : col68_cfabbc;
		break;
	case 17:
		col68_d02364 = data->source ? data->source->unknown454580() : col68_d1ecd4;
		break;
	case 18:
		col68_d02364 = color;
		break;
	case 19:
		col68_d02364 = color;
		break;
	default:
		col68_d02364 = back;
		break;
	}
}
