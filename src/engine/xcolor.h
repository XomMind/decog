#ifndef XCOLOR_H
#define XCOLOR_H

#include <string>
#include <iostream>
#include "util/stringutil.h"

//==================================================================
// XColor
//==================================================================
// 3-byte RGB color (no alpha), reconstructed from 0x411d40-0x413960.
// The blend/compositing set mirrors libtcod's TCODColor and TCOD_bkgnd_flag_t
//	(see XConsole's cell background blending at 0x428120).
// Method names are placeholders unless stated otherwise; XColor::set() is
//	attested by its error strings, but that overload was stripped from the exe.

// NOTE: placeholder names; int helpers live with the math utilities (0x9cdb30-0x9cdc80)
int minInt(int a, int b);
int maxInt(int a, int b);
int clampInt(int min, int value, int max);

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor() throw();
	XColor(unsigned char value);
	XColor(int r_, int g_, int b_);
	XColor(float h, float s, float v);
	XColor(const std::string &hex);
	XColor(const XColor &color) throw();

	void read(std::istream &stream);	// NOTE: placeholder name
	void write(std::ostream &stream);	// NOTE: placeholder name

	XColor &operator=(XColor color);
	bool operator==(XColor color);
	bool operator!=(XColor color);
	XColor operator+(XColor color);
	XColor operator*(float value);
	XColor &operator*=(float value);
	bool nonzero();	// NOTE: placeholder name
	std::string toString()	// NOTE: placeholder name
	{
		return std::string() + "(" + intToString(r) + "," + intToString(g) + "," + intToString(b) + ")";
	};

	void set(unsigned char r_, unsigned char g_, unsigned char b_);
	void set(const XColor &color);
	void setHSV(float h, float s, float v);	// NOTE: placeholder name

	// blending (cases of the console background flag)
	void add(XColor color);	// NOTE: placeholder names from here on
	void subtract(XColor color);
	void multiply(XColor color);
	void scale(float value);
	void lerp(XColor color, float coef);
	void addAlpha(XColor color, float alpha);
	void screen(XColor color);
	void colorDodge(XColor color);
	void colorBurn(XColor color);
	void burn(XColor color);
	void overlay(XColor color);

	void grayscale();
	void desaturate(float amount);
	void shiftHue(int degrees);
	void cycle(int amount);
	void invert();
	void getHSV(float *h, float *s, float *v);

	static XColor add(XColor c1, XColor c2);
	static XColor subtract(XColor c1, XColor c2);
	static XColor multiply(XColor c1, XColor c2);
	static XColor scale(XColor c1, float value);
	static XColor lerp(XColor c1, XColor c2, float coef);
	static XColor addAlpha(XColor c1, XColor c2, float alpha);
	static XColor subtractAlpha(XColor c1, XColor c2, float alpha);
	static XColor screen(XColor c1, XColor c2);
	static XColor colorDodge(XColor c1, XColor c2);
	static XColor colorBurn(XColor c1, XColor c2);
	static XColor burn(XColor c1, XColor c2);
	static XColor overlay(XColor c1, XColor c2);
	static XColor shiftHue(XColor c1, int degrees);
	static XColor grayscale(XColor c1);
};

#endif // XCOLOR_H
