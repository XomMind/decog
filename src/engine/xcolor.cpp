#include "xcolor.h"
#include <math.h>
#include "util/stringutil.h"
#include "util/mathutil.h"

// NOTE: placeholder name; parses "RRGGBB" (0x405d20)
bool hexToRgb(const std::string &hex, unsigned char *r, unsigned char *g, unsigned char *b);

XColor::XColor()
	: r	(0)
	, g	(0)
	, b	(0)
{}

XColor::XColor(unsigned char value)
	: r	(value)
	, g	(value)
	, b	(value)
{}

XColor::XColor(int r_, int g_, int b_)
	: r	(r_)
	, g	(g_)
	, b	(b_)
{}

XColor::XColor(float h, float s, float v)
{
	setHSV(h,s,v);
}

XColor::XColor(const std::string &hex)
{
	hexToRgb(hex,&r,&g,&b);
}

XColor::XColor(const XColor &color)
	: r	(color.r)
	, g	(color.g)
	, b	(color.b)
{}

void XColor::read(std::istream &stream)
{
	stream.read((char*)&r,1);
	stream.read((char*)&g,1);
	stream.read((char*)&b,1);
}

void XColor::write(std::ostream &stream)
{
	stream.write((char*)&r,1);
	stream.write((char*)&g,1);
	stream.write((char*)&b,1);
}

XColor &XColor::operator=(XColor color)
{
	r = color.r;
	g = color.g;
	b = color.b;
	return *this;
}

bool XColor::operator==(XColor color)
{
	return r == color.r && g == color.g && b == color.b;
}

bool XColor::operator!=(XColor color)
{
	return r != color.r || g != color.g || b != color.b;
}

XColor XColor::operator+(XColor color)
{
	return XColor(minInt(r + color.r,255),minInt(g + color.g,255),minInt(b + color.b,255));
}

XColor XColor::operator*(float value)
{
	return XColor(clampInt(0,(int)(r * value),255),clampInt(0,(int)(g * value),255),clampInt(0,(int)(b * value),255));
}

XColor &XColor::operator*=(float value)
{
	r = clampInt(0,(int)(r * value),255);
	g = clampInt(0,(int)(g * value),255);
	b = clampInt(0,(int)(b * value),255);
	return *this;
}

bool XColor::nonzero()
{
	return r != 0 || g != 0 || b != 0;
}

void XColor::set(unsigned char r_, unsigned char g_, unsigned char b_)
{
	r = r_;
	g = g_;
	b = b_;
}

void XColor::set(const XColor &color)
{
	r = color.r;
	g = color.g;
	b = color.b;
}

void XColor::setHSV(float h, float s, float v)
{
	int i;
	float f, p, q, t;
	if (s == 0.0f)
	{
		r = g = b = (unsigned char)(v * 255.0 + 0.5);
	}
	else
	{
		while (h < 0.0) h += 360.0;
		while (h >= 360.0) h -= 360.0;
		h /= 60.0;
		i = (int)floor(h);
		f = h - i;
		p = v * (1.0f - s);
		q = v * (1.0f - s * f);
		t = v * (1.0f - s * (1.0f - f));
		switch (i)
		{
			case 0:
				r = (unsigned char)(v * 255.0 + 0.5);
				g = (unsigned char)(t * 255.0 + 0.5);
				b = (unsigned char)(p * 255.0 + 0.5);
				break;
			case 1:
				r = (unsigned char)(q * 255.0 + 0.5);
				g = (unsigned char)(v * 255.0 + 0.5);
				b = (unsigned char)(p * 255.0 + 0.5);
				break;
			case 2:
				r = (unsigned char)(p * 255.0 + 0.5);
				g = (unsigned char)(v * 255.0 + 0.5);
				b = (unsigned char)(t * 255.0 + 0.5);
				break;
			case 3:
				r = (unsigned char)(p * 255.0 + 0.5);
				g = (unsigned char)(q * 255.0 + 0.5);
				b = (unsigned char)(v * 255.0 + 0.5);
				break;
			case 4:
				r = (unsigned char)(t * 255.0 + 0.5);
				g = (unsigned char)(p * 255.0 + 0.5);
				b = (unsigned char)(v * 255.0 + 0.5);
				break;
			default:
				r = (unsigned char)(v * 255.0 + 0.5);
				g = (unsigned char)(p * 255.0 + 0.5);
				b = (unsigned char)(q * 255.0 + 0.5);
				break;
		}
	}
}

void XColor::add(XColor color)
{
	r = minInt(r + color.r,255);
	g = minInt(g + color.g,255);
	b = minInt(b + color.b,255);
}

void XColor::subtract(XColor color)
{
	r = maxInt(r - color.r,0);
	g = maxInt(g - color.g,0);
	b = maxInt(b - color.b,0);
}

void XColor::multiply(XColor color)
{
	r = r * color.r / 255;
	g = g * color.g / 255;
	b = b * color.b / 255;
}

void XColor::scale(float value)
{
	r = clampInt(0,(int)(r * value),255);
	g = clampInt(0,(int)(g * value),255);
	b = clampInt(0,(int)(b * value),255);
}

void XColor::lerp(XColor color, float coef)
{
	r = (unsigned char)(r + (color.r - r) * coef);
	g = (unsigned char)(g + (color.g - g) * coef);
	b = (unsigned char)(b + (color.b - b) * coef);
}

void XColor::addAlpha(XColor color, float alpha)
{
	color.scale(alpha);
	add(color);
}

void XColor::screen(XColor color)
{
	r = 255 - (255 - r) * (255 - color.r) / 255;
	g = 255 - (255 - g) * (255 - color.g) / 255;
	b = 255 - (255 - b) * (255 - color.b) / 255;
}

void XColor::colorDodge(XColor color)
{
	r = clampInt(0,r != 255 ? color.r * 255 / (255 - r) : 255,255);
	g = clampInt(0,g != 255 ? color.g * 255 / (255 - g) : 255,255);
	b = clampInt(0,b != 255 ? color.b * 255 / (255 - b) : 255,255);
}

void XColor::colorBurn(XColor color)
{
	r = clampInt(0,color.r > 0 ? 255 - (255 - r) * 255 / color.r : 0,255);
	g = clampInt(0,color.g > 0 ? 255 - (255 - g) * 255 / color.g : 0,255);
	b = clampInt(0,color.b > 0 ? 255 - (255 - b) * 255 / color.b : 0,255);
}

void XColor::burn(XColor color)
{
	r = clampInt(0,r + color.r - 255,255);
	g = clampInt(0,g + color.g - 255,255);
	b = clampInt(0,b + color.b - 255,255);
}

void XColor::overlay(XColor color)
{
	r = clampInt(0,color.r <= 128 ? 2 * color.r * r / 255 : 255 - 2 * (255 - color.r) * (255 - r) / 255,255);
	g = clampInt(0,color.g <= 128 ? 2 * color.g * g / 255 : 255 - 2 * (255 - color.g) * (255 - g) / 255,255);
	b = clampInt(0,color.b <= 128 ? 2 * color.b * b / 255 : 255 - 2 * (255 - color.b) * (255 - b) / 255,255);
}

void XColor::grayscale()
{
	r = g = b = (unsigned char)(r * 0.3 + g * 0.59 + b * 0.11);
}

void XColor::desaturate(float amount)
{
	unsigned char grey = (unsigned char)(r * 0.3 + g * 0.6 + b * 0.1);
	r = (unsigned char)(r + (grey - r) * amount);
	g = (unsigned char)(g + (grey - g) * amount);
	b = (unsigned char)(b + (grey - b) * amount);
}

void XColor::shiftHue(int degrees)
{
	float h, s, v;
	getHSV(&h,&s,&v);
	h = (float)(((int)h + degrees) % 360);
	setHSV(h,s,v);
}

void XColor::cycle(int amount)
{
	if (r == g && g == b) return;
	r = (r + amount) % 255;
	g = (g + amount) % 255;
	b = (b + amount) % 255;
}

void XColor::invert()
{
	r = 255 - r;
	g = 255 - g;
	b = 255 - b;
}

void XColor::getHSV(float *h, float *s, float *v)
{
	// NOTE: local names chosen to reproduce the original frame layout (VS2010 orders
	//	/Od locals by a hash of their names)
	float fRed = r / 255.0;
	float green = g / 255.0;
	float bPct = b / 255.0;
	float min = minf(fRed,minf(green,bPct));
	float maxVal = maxf(fRed,maxf(green,bPct));
	if (min == maxVal)
	{
		*s = 0;
		*h = 0;
		*v = min;
		return;
	}
	float delta = (fRed == min) ? green - bPct : ((bPct == min) ? fRed - green : bPct - fRed);
	float sector = (fRed == min) ? 3 : ((bPct == min) ? 1 : 5);
	*h = (sector - delta / (maxVal - min)) * 60.0;
	*s = (maxVal - min) / maxVal;
	*v = maxVal;
}

XColor XColor::add(XColor c1, XColor c2)
{
	c1.add(c2);
	return c1;
}

XColor XColor::subtract(XColor c1, XColor c2)
{
	c1.subtract(c2);
	return c1;
}

XColor XColor::multiply(XColor c1, XColor c2)
{
	c1.multiply(c2);
	return c1;
}

XColor XColor::scale(XColor c1, float value)
{
	c1.scale(value);
	return c1;
}

XColor XColor::lerp(XColor c1, XColor c2, float coef)
{
	c1.lerp(c2,coef);
	return c1;
}

XColor XColor::addAlpha(XColor c1, XColor c2, float alpha)
{
	c2.scale(alpha);
	c1.add(c2);
	return c1;
}

XColor XColor::subtractAlpha(XColor c1, XColor c2, float alpha)
{
	c2.scale(alpha);
	c1.subtract(c2);
	return c1;
}

XColor XColor::screen(XColor c1, XColor c2)
{
	c1.screen(c2);
	return c1;
}

XColor XColor::colorDodge(XColor c1, XColor c2)
{
	c1.colorDodge(c2);
	return c1;
}

XColor XColor::colorBurn(XColor c1, XColor c2)
{
	c1.colorBurn(c2);
	return c1;
}

XColor XColor::burn(XColor c1, XColor c2)
{
	c1.burn(c2);
	return c1;
}

XColor XColor::overlay(XColor c1, XColor c2)
{
	c1.overlay(c2);
	return c1;
}

XColor XColor::shiftHue(XColor c1, int degrees)
{
	c1.shiftHue(degrees);
	return c1;
}

XColor XColor::grayscale(XColor c1)
{
	c1.grayscale();
	return c1;
}
