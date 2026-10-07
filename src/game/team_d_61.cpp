// team_d_61: background blending (0x509530 blend modes, 0x508e30 animated blend alpha).
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
extern XColor col_d349ec;	// defined in team_d_04.cpp


struct Point61	// NOTE: placeholder name
{
	int x;
	int y;
};

class NoiseField61	// NOTE: placeholder name (OpR1b_NoiseField)
{
public:
	float sample(Point61 *pos);
};

struct NoiseOwner61	// NOTE: placeholder name and layout
{
	char			pad00[0x34];
	NoiseField61	noise;	// +0x34
};

struct AlphaMode61	// NOTE: placeholder name and layout (the full blend mode record)
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
bool blink_437320(unsigned int period);	// NOTE: placeholder name
#include <math.h>

class Blender61	// NOTE: placeholder name
{
public:
	int				unknown00;
	NoiseOwner61	*owner;		// +0x04
	unsigned int	start;		// +0x08
	unsigned int	end;		// +0x0c
	Point61			pos;		// +0x10

	float unknown508e30(AlphaMode61 *mode);	// NOTE: placeholder name
	void unknown509530(const XColor &back, AlphaMode61 *mode, const XColor &fore);	// NOTE: placeholder name
};

#define PI61 3.1415927410125732		// NOTE: (double)3.14159265f
#define TWO_PI61 6.2831854820251465		// NOTE: (double)6.2831853f
#define HALF_PI61 1.5707963705062866	// NOTE: (double)1.57079633f

float Blender61::unknown508e30(AlphaMode61 *mode)
{
	switch (mode->type)
	{
	case 0:
		return mode->base;
	case 1:
		return OpT8b_Fn9d5ac0(0.0f,1.0f,(tickCount - start) * mode->param + mode->base);
	case 2:
		return sin((float)((float)((int)(float)(tickCount - start) % (int)mode->param) / mode->param * PI61)) * mode->base;
	case 3:
		return maxf(0.0f,sin((float)((float)((int)(float)(tickCount - start) % (int)mode->param) / mode->param * TWO_PI61))) * mode->base;
	case 4:
		return mode->base / 2.0 + mode->base / 2.0 * sin((float)((float)((int)(float)(tickCount - start) % (int)(mode->param / 2.0)) / (mode->param / 2.0) * PI61));
	case 5:
		return sin((float)((tickCount % (unsigned int)mode->param) / mode->param * PI61)) * mode->base;
	case 6:
		return blink_437320((int)mode->param);
	case 7:
		return owner->noise.sample(&pos) * (mode->param - mode->base) + mode->base;
	case 8:
		return (float)(tickCount - start) / (float)(end - start) * mode->base;
	case 9:
		return mode->base - (float)(tickCount - start) / (float)(end - start) * mode->base;
	case 10:
		return sin((float)((float)(tickCount - start) / (float)(end - start) * HALF_PI61)) * mode->base;
	case 11:
		return mode->base + (1.0 - mode->base) * sin((float)((float)(tickCount - start) / (float)(end - start) * HALF_PI61));
	case 12:
		return sin((float)((float)(tickCount - start) / (float)(end - start) * PI61)) * mode->base;
	case 13:
		return mode->base + (1.0 - mode->base) * sin((float)((float)(tickCount - start) / (float)(end - start) * PI61));
	case 14:
		return mode->base - sin((float)((float)(tickCount - start) / (float)(end - start) * HALF_PI61)) * mode->base;
	case 15:
		return mode->base + (1.0 - mode->base) * sin((1.0 - (float)(tickCount - start) / (float)(end - start)) * HALF_PI61);
	}
	return 1.0f;
}

void Blender61::unknown509530(const XColor &back, AlphaMode61 *mode, const XColor &fore)
{
	switch (mode->blend)
	{
	case 0:
		col_d349ec = back;
		break;
	case 1:
		col_d349ec = fore;
		break;
	case 2:
		col_d349ec = XColor::add(back,fore);
		break;
	case 3:
		col_d349ec = XColor::subtract(back,fore);
		break;
	case 4:
		col_d349ec = XColor::multiply(back,fore);
		break;
	case 5:
		col_d349ec = XColor::scale(back,unknown508e30(mode));
		break;
	case 6:
		col_d349ec = XColor::lerp(back,fore,unknown508e30(mode));
		break;
	case 7:
		col_d349ec = XColor::addAlpha(back,fore,unknown508e30(mode));
		break;
	case 8:
		col_d349ec = XColor::subtractAlpha(back,fore,unknown508e30(mode));
		break;
	case 9:
		col_d349ec = XColor::screen(back,fore);
		break;
	case 10:
		col_d349ec = XColor::colorDodge(back,fore);
		break;
	case 11:
		col_d349ec = XColor::colorBurn(back,fore);
		break;
	case 12:
		col_d349ec = XColor::burn(back,fore);
		break;
	case 13:
		col_d349ec = XColor::overlay(back,fore);
		break;
	case 14:
		col_d349ec = XColor::shiftHue(back,(int)(unknown508e30(mode) * 360.0));
		break;
	default:
		col_d349ec = back;
		break;
	}
}
