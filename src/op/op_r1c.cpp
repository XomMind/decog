// op_r1c: XConsole / XRoot / protobuf-runtime helpers in 0x42a3c0-0x434ad0, Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Pos
{
	int x;
	int y;
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
	bool operator==(XColor color);
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect() throw();	// NOTE: folded default ctor
	Rect(const Rect &rect);
	Rect &operator=(const Rect &rect);	// NOTE: folded with the copy ctor (0x40a720)
	void set(int x_, int y_, int width_, int height_);	// NOTE: placeholder name (0x40a840)
};

struct XCell	// NOTE: placeholder name
{
	int font;
	int ch;
	int glyph;
	XColor fore;
	XColor back;
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	int	width;
	int	height;
	T	*data;

	int getWidth();
	int getHeight();
	T *get(int x, int y);
};

class OpR1c_Console	// NOTE: placeholder name (XConsole)
{
public:
	void *vftable;
	OpR1c_Console *parent;
	Array2D<XCell> buffer;

	void copyColorsTo(OpR1c_Console *dest, Pos &destPos, Rect *rect);	// 0x42a3c0, NOTE: placeholder name
};

void OpR1c_Console::copyColorsTo(OpR1c_Console *dest, Pos &destPos, Rect *rect)
{
	Array2D<XCell> *destBuf = &dest->buffer;
	Rect srcRect;
	int x, y, dx, destY;
	XCell *fromCell, *toCell;
	if (rect)
		srcRect = *rect;
	else
		srcRect.set(0,0,buffer.getWidth(),buffer.getHeight());
	if (destPos.x < 0)
	{
		if (srcRect.width < -destPos.x)
			return;
		srcRect.x = -destPos.x + srcRect.x;
		srcRect.width = srcRect.width - -destPos.x;
		destPos.x = 0;
	}
	if (destPos.y < 0)
	{
		if (srcRect.height < -destPos.y)
			return;
		srcRect.y = -destPos.y + srcRect.y;
		srcRect.height = srcRect.height - -destPos.y;
		destPos.y = 0;
	}
	if (destPos.x + srcRect.width > destBuf->getWidth())
		srcRect.width = destBuf->getWidth() - destPos.x;
	if (destPos.y + srcRect.height > destBuf->getHeight())
		srcRect.height = destBuf->getHeight() - destPos.y;
	for (x = srcRect.x, dx = destPos.x; x < srcRect.x + srcRect.width; x++, dx++)
	{
		for (y = srcRect.y, destY = destPos.y; y < srcRect.y + srcRect.height; y++, destY++)
		{
			fromCell = buffer.get(x,y);
			toCell = destBuf->get(dx,destY);
			toCell->fore = fromCell->fore;
			toCell->back = fromCell->back;
		}
	}
}

//==================================================================
// more shared declarations
//==================================================================

extern "C" int SDL_ShowCursor(int toggle);
extern "C" void SDL_WarpMouse(unsigned short x, unsigned short y);

extern XColor &COLOR_BLACK;	// 0xcfe674, NOTE: placeholder name
extern XColor &COLOR_WHITE;	// 0xcfabbc, NOTE: placeholder name

int minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)

class OpR1c_Rex	// NOTE: placeholder name (REX, object at 0xd223f0)
{
public:
	int unknown44a630();	// NOTE: placeholder name (ICF'd getter of +0x14)
	int unknown418900();	// NOTE: placeholder name (ICF'd getter of +0x18)
	int unknown4189c0();	// NOTE: placeholder name
	int unknown4189e0();	// NOTE: placeholder name
	void unknown426b90();	// NOTE: placeholder name
};
extern OpR1c_Rex rex;	// 0xd223f0

class XFontData
{
public:
	void generateAutoscaled();
};

class OpR1c_FontSet	// NOTE: placeholder name
{
public:
	void generateAutoscaledAll();	// 0x431de0, NOTE: placeholder name

	char pad00[0x1c];
	vector<XFontData*> fonts;
};

void OpR1c_FontSet::generateAutoscaledAll()
{
	for (unsigned int i = 0; i < fonts.size(); i++)
		fonts[i]->generateAutoscaled();
}

class OpR1c_Mouse	// NOTE: placeholder name (XMouse)
{
public:
	void setCursorHidden(bool hidden);	// 0x432170, NOTE: placeholder name
	void setCell(int x_, int y_);	// 0x4322a0, NOTE: placeholder name
	void saveCursorBackground();	// 0x41a9e0
	void updateHoveredConsole();	// 0x4321d0

	int x;
	int y;
	char padding08[0x10 - 0x08];
	int mouseX;
	int mouseY;
	bool cursorHidden;
	char padding19[0x1c - 0x19];
	void *cursorSurface;
};

void OpR1c_Mouse::setCursorHidden(bool hidden)
{
	cursorHidden = hidden;
	if (cursorSurface)
	{
		if (cursorHidden)
			rex.unknown426b90();
		else
			saveCursorBackground();
	}
	else
		SDL_ShowCursor(!cursorHidden);
}

void OpR1c_Mouse::setCell(int x_, int y_)
{
	x = x_;
	y = y_;
	mouseX = rex.unknown44a630() + rex.unknown4189c0() * (x + 1) - 1;
	mouseY = rex.unknown418900() + rex.unknown4189e0() * (y + 1) - 1;
	SDL_WarpMouse((unsigned short)mouseX,(unsigned short)mouseY);
	updateHoveredConsole();
}

extern const int opr1c_thresholds_b91b7c[5];	// NOTE: placeholder name

int opr1c_getThresholdIndex(int value)	// 0x433260, NOTE: placeholder name
{
	if (value < opr1c_thresholds_b91b7c[0])
		return 0;
	for (int i = 4; i >= 0; i--)
	{
		if (value >= opr1c_thresholds_b91b7c[i])
			return i + 1;
	}
	return 0;
}

int opr1c_getCircularDistance(int a, int b)	// 0x433e20, NOTE: placeholder name
{
	if (a == b)
		return 0;
	int distance = abs(b - a);
	int rest = 8 - distance;
	return minInt(distance,rest);
}

int opr1c_scaleRepeated(int value, int count, float factor)	// 0x4343d0, NOTE: placeholder name
{
	int result = value;
	count -= 2;
	while (count > 0)
	{
		result = (int)(result * factor);
		count--;
	}
	return result;
}

//==================================================================
// small free functions around the console/UI colour tables
//==================================================================

extern XColor opr1c_color_d29804;	// NOTE: placeholder name
extern bool opr1c_colorIsBlack_cefb3c;	// NOTE: placeholder name

void opr1c_setColor_4347a0(XColor color)	// NOTE: placeholder name
{
	opr1c_color_d29804 = color;
	opr1c_colorIsBlack_cefb3c = opr1c_color_d29804 == COLOR_BLACK;
}

extern const int opr1c_percents_ba6c18[3];	// NOTE: placeholder name

int opr1c_getPercentTier(int value, int max)	// 0x4347e0, NOTE: placeholder name
{
	if (value <= 0 || max <= 0)
		return 0;
	int percent = value * 100 / max;
	for (int i = 0; i < 3; i++)
	{
		if (percent < opr1c_percents_ba6c18[i])
			return i;
	}
	return 3;
}

int opr1c_getInversePercentTier(int value, int max)	// 0x434840, NOTE: placeholder name
{
	return -(opr1c_getPercentTier(value,max) - 3);
}

int opr1c_getScoreTier(int score)	// 0x434860, NOTE: placeholder name
{
	if (score >= 75)
		return 3;
	else if (score >= 40)
		return 2;
	else if (score >= 20)
		return 1;
	else
		return 0;
}

extern XColor &opr1c_colorTier3_d25e0c;	// NOTE: placeholder name
extern XColor &opr1c_colorTier2_cf281c;	// NOTE: placeholder name
extern XColor &opr1c_colorTier1_d23094;	// NOTE: placeholder name
extern XColor &opr1c_colorTier0_d2f34c;	// NOTE: placeholder name

XColor opr1c_getScoreColor(int score)	// 0x4348a0, NOTE: placeholder name
{
	if (score >= 75)
		return opr1c_colorTier3_d25e0c;
	else if (score >= 40)
		return opr1c_colorTier2_cf281c;
	else if (score >= 20)
		return opr1c_colorTier1_d23094;
	else
		return opr1c_colorTier0_d2f34c;
}

extern const float opr1c_floats_ba3b1c[10];	// NOTE: placeholder name
extern const float opr1c_float_ba3b44;	// NOTE: placeholder name

float opr1c_getFloatByIndex(int index)	// 0x4343a0, NOTE: placeholder name
{
	float result;
	if (index >= 11)
		result = opr1c_float_ba3b44;
	else
		result = opr1c_floats_ba3b1c[index];
	return result;
}

extern bool opr1c_flag_caed25;	// NOTE: placeholder name

int opr1c_getValueIfFlag(int value)	// 0x432ac0, NOTE: placeholder name
{
	return opr1c_flag_caed25 ? value : -1;
}

extern void *opr1c_ptr_cebd5c;	// NOTE: placeholder name

bool opr1c_hasPtr_cebd5c()	// 0x4328a0, NOTE: placeholder name
{
	return opr1c_ptr_cebd5c ? true : false;
}

struct OpR1c_IntColor	// NOTE: placeholder name
{
	void set(int value_, const XColor &color_);	// 0x434410, NOTE: placeholder name

	int value;
	XColor color;
};

void OpR1c_IntColor::set(int value_, const XColor &color_)
{
	value = value_;
	color = color_;
}

//==================================================================
// colour table initialisers (dynamic init of colour globals)
//==================================================================
extern XColor &opr1c_ref_cf13fc;	// NOTE: placeholder name
extern XColor &opr1c_ref_cf39f4;	// NOTE: placeholder name
extern XColor &opr1c_ref_cf44c0;	// NOTE: placeholder name
extern XColor &opr1c_ref_cfd4c8;	// NOTE: placeholder name
extern XColor &opr1c_ref_d1ecd4;	// NOTE: placeholder name
extern XColor &opr1c_ref_d22130;	// NOTE: placeholder name
extern XColor &opr1c_ref_d32efc;	// NOTE: placeholder name
extern XColor &opr1c_ref_d338c8;	// NOTE: placeholder name
extern XColor opr1c_color_d2ed1c;	// NOTE: placeholder name
extern XColor opr1c_color_d2ed1f;	// NOTE: placeholder name
extern XColor opr1c_color_d2ed22;	// NOTE: placeholder name
extern XColor opr1c_color_d2ed25;	// NOTE: placeholder name
extern XColor opr1c_color_d2ed28;	// NOTE: placeholder name
extern XColor opr1c_color_d2ed2b;	// NOTE: placeholder name
extern XColor opr1c_color_d2ed2e;	// NOTE: placeholder name
extern XColor opr1c_color_d2ed31;	// NOTE: placeholder name
extern XColor opr1c_color_d2ed34;	// NOTE: placeholder name
extern XColor opr1c_color_d2ed37;	// NOTE: placeholder name

void opr1c_initColors_433e60()	// 0x433e60, NOTE: placeholder name
{
	opr1c_color_d2ed1c = opr1c_ref_d1ecd4;
	opr1c_color_d2ed1f = opr1c_ref_d338c8;
	opr1c_color_d2ed22 = opr1c_ref_d22130;
	opr1c_color_d2ed25 = opr1c_ref_cf39f4;
	opr1c_color_d2ed28 = opr1c_ref_cf13fc;
	opr1c_color_d2ed2b = opr1c_ref_cf13fc;
	opr1c_color_d2ed2e = opr1c_ref_cf13fc;
	opr1c_color_d2ed31 = opr1c_ref_d32efc;
	opr1c_color_d2ed34 = opr1c_ref_cfd4c8;
	opr1c_color_d2ed37 = opr1c_ref_cf44c0;
}

extern XColor &opr1c_ref_cf2810;	// NOTE: placeholder name
extern XColor &opr1c_ref_cf281c;	// NOTE: placeholder name
extern XColor &opr1c_ref_cf44c4;	// NOTE: placeholder name
extern XColor &opr1c_ref_cfbecc;	// NOTE: placeholder name
extern XColor &opr1c_ref_cfc174;	// NOTE: placeholder name
extern XColor &opr1c_ref_cfd4cc;	// NOTE: placeholder name
extern XColor &opr1c_ref_d20a74;	// NOTE: placeholder name
extern XColor &opr1c_ref_d23094;	// NOTE: placeholder name
extern XColor &opr1c_ref_d25e0c;	// NOTE: placeholder name
extern XColor &opr1c_ref_d28fc8;	// NOTE: placeholder name
extern XColor &opr1c_ref_d2b284;	// NOTE: placeholder name
extern XColor &opr1c_ref_d33acc;	// NOTE: placeholder name
extern XColor &opr1c_ref_d38430;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1ce;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1d1;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1d4;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1d7;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1da;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1dd;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1e0;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1e3;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1e6;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1e9;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1ec;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1ef;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1f2;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1f5;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1f8;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1fb;	// NOTE: placeholder name
extern XColor opr1c_color_cfc1fe;	// NOTE: placeholder name
extern XColor opr1c_color_cfc201;	// NOTE: placeholder name
extern XColor opr1c_color_cfc204;	// NOTE: placeholder name
extern XColor opr1c_color_cfc207;	// NOTE: placeholder name

void opr1c_initColors_433f60()	// 0x433f60, NOTE: placeholder name
{
	opr1c_color_cfc1ce = opr1c_color_cfc1d1 = opr1c_ref_d20a74;
	opr1c_color_cfc1d4 = opr1c_ref_d28fc8;
	opr1c_color_cfc1d7 = opr1c_ref_d2b284;
	opr1c_color_cfc1da = opr1c_ref_cf2810;
	opr1c_color_cfc1dd = opr1c_ref_d33acc;
	opr1c_color_cfc1e0 = opr1c_ref_cf44c4;
	opr1c_color_cfc1e3 = opr1c_ref_cf281c;
	opr1c_color_cfc1e6 = opr1c_ref_cfd4cc;
	opr1c_color_cfc1e9 = opr1c_ref_d23094;
	opr1c_color_cfc1ec = opr1c_color_cfc1ef = opr1c_ref_cfbecc;
	opr1c_color_cfc1f2 = opr1c_color_cfc1f5 = opr1c_ref_d38430;
	opr1c_color_cfc1f8 = opr1c_color_cfc1fb = opr1c_ref_d25e0c;
	opr1c_color_cfc1fe = opr1c_color_cfc201 = opr1c_ref_d20a74;
	opr1c_color_cfc204 = opr1c_color_cfc207 = opr1c_ref_cfc174;
}

extern XColor &opr1c_ref_cf27e8;	// NOTE: placeholder name
extern XColor &opr1c_ref_cfc180;	// NOTE: placeholder name
extern XColor &opr1c_ref_d1dae0;	// NOTE: placeholder name
extern XColor &opr1c_ref_d20438;	// NOTE: placeholder name
extern XColor &opr1c_ref_d2043c;	// NOTE: placeholder name
extern XColor &opr1c_ref_d204ac;	// NOTE: placeholder name
extern XColor &opr1c_ref_d29758;	// NOTE: placeholder name
extern XColor &opr1c_ref_d35be0;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5a8;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5ab;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5ae;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5b1;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5b4;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5b7;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5ba;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5bd;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5c0;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5c3;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5c6;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5c9;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5cc;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5cf;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5d2;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5d5;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5d8;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5db;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5de;	// NOTE: placeholder name
extern XColor opr1c_color_cfe5e1;	// NOTE: placeholder name

void opr1c_initColors_434140()	// 0x434140, NOTE: placeholder name
{
	opr1c_color_cfe5a8 = opr1c_ref_cfc180;
	opr1c_color_cfe5ab = opr1c_ref_d29758;
	opr1c_color_cfe5ae = opr1c_ref_cf27e8;
	opr1c_color_cfe5b1 = opr1c_ref_cf27e8;
	opr1c_color_cfe5b4 = opr1c_ref_cf27e8;
	opr1c_color_cfe5b7 = opr1c_ref_d20438;
	opr1c_color_cfe5ba = opr1c_ref_cf27e8;
	opr1c_color_cfe5bd = opr1c_ref_d204ac;
	opr1c_color_cfe5c0 = opr1c_ref_cf27e8;
	opr1c_color_cfe5c3 = opr1c_ref_d204ac;
	opr1c_color_cfe5c6 = opr1c_ref_d204ac;
	opr1c_color_cfe5c9 = opr1c_ref_d204ac;
	opr1c_color_cfe5cc = opr1c_ref_d204ac;
	opr1c_color_cfe5cf = opr1c_ref_d204ac;
	opr1c_color_cfe5d2 = opr1c_ref_cfc180;
	opr1c_color_cfe5d5 = opr1c_ref_cfc180;
	opr1c_color_cfe5d8 = opr1c_ref_d204ac;
	opr1c_color_cfe5db = opr1c_ref_d35be0;
	opr1c_color_cfe5de = opr1c_ref_d2043c;
	opr1c_color_cfe5e1 = opr1c_ref_d1dae0;
}

struct OpR1c_Dice	// NOTE: placeholder name
{
	void split(int total);	// NOTE: placeholder name (0x40c840 via 0x40c800)
	char pad00[0x10];
};
extern OpR1c_Dice opr1c_cfcd20[10];	// NOTE: placeholder name

void opr1c_initDice_433d80()	// 0x433d80, NOTE: placeholder name
{
	opr1c_cfcd20[0].split(200);
	opr1c_cfcd20[1].split(300);
	opr1c_cfcd20[2].split(325);
	opr1c_cfcd20[3].split(350);
	opr1c_cfcd20[4].split(375);
	opr1c_cfcd20[5].split(400);
	opr1c_cfcd20[6].split(400);
	opr1c_cfcd20[7].split(400);
	opr1c_cfcd20[8].split(400);
	opr1c_cfcd20[9].split(400);
}

extern XColor &opr1c_ref_d1ecd4;	// NOTE: placeholder name
extern XColor &opr1c_ref_d20a74;	// NOTE: placeholder name
extern XColor &opr1c_ref_d20b78;	// NOTE: placeholder name
extern XColor &opr1c_ref_d21b44;	// NOTE: placeholder name
extern XColor &opr1c_ref_d25f60;	// NOTE: placeholder name
extern XColor &opr1c_ref_d31574;	// NOTE: placeholder name
extern XColor &opr1c_ref_d32dfc;	// NOTE: placeholder name
extern XColor &opr1c_ref_d338bc;	// NOTE: placeholder name
extern XColor &opr1c_ref_d35bbc;	// NOTE: placeholder name
extern XColor &opr1c_ref_d38644;	// NOTE: placeholder name
extern XColor &opr1c_ref_d386c8;	// NOTE: placeholder name
extern XColor opr1c_color_d329a4;	// NOTE: placeholder name
extern XColor opr1c_color_d329a7;	// NOTE: placeholder name
extern XColor opr1c_color_d329aa;	// NOTE: placeholder name
extern XColor opr1c_color_d329ad;	// NOTE: placeholder name
extern XColor opr1c_color_d329b0;	// NOTE: placeholder name
extern XColor opr1c_color_d329b3;	// NOTE: placeholder name
extern XColor opr1c_color_d329b6;	// NOTE: placeholder name
extern XColor opr1c_color_d329b9;	// NOTE: placeholder name
extern XColor opr1c_color_d329bc;	// NOTE: placeholder name
extern XColor opr1c_color_d329bf;	// NOTE: placeholder name
extern XColor opr1c_color_d329c2;	// NOTE: placeholder name
extern XColor opr1c_color_d329c5;	// NOTE: placeholder name
extern XColor opr1c_color_d329c8;	// NOTE: placeholder name
extern XColor opr1c_color_d329cb;	// NOTE: placeholder name

void opr1c_initColors_434910()	// 0x434910, NOTE: placeholder name
{
	opr1c_color_d329a4 = opr1c_ref_d35bbc;
	opr1c_color_d329a7 = opr1c_ref_d1ecd4;
	opr1c_color_d329aa = opr1c_ref_d386c8;
	opr1c_color_d329ad = COLOR_WHITE;
	opr1c_color_d329b0 = opr1c_ref_d21b44;
	opr1c_color_d329b3 = opr1c_ref_d21b44;
	opr1c_color_d329b6 = opr1c_ref_d338bc;
	opr1c_color_d329b9 = opr1c_ref_d32dfc;
	opr1c_color_d329bc = opr1c_ref_d20a74;
	opr1c_color_d329bf = opr1c_ref_d31574;
	opr1c_color_d329c2 = opr1c_ref_d20b78;
	opr1c_color_d329c5 = opr1c_ref_d38644;
	opr1c_color_d329c8 = opr1c_ref_d20b78;
	opr1c_color_d329cb = opr1c_ref_d25f60;
}

//==================================================================
// build number helpers
//==================================================================

void logError(string location, string message);	// NOTE: placeholder name (0x404f10)
string intToString(int value);	// 0x4051f0
string &padLeft(string &str, unsigned int width, char c);	// NOTE: placeholder name (0x408090)
extern string gameString_cf33fc;	// NOTE: placeholder name

string opr1c_convertBuildno_432720(const string &build)	// 0x432720, NOTE: placeholder name
{
	string text = build;
	if (build.empty())
	{
		logError("convertBuildno()","build record empty, storing value of current build");
		text = gameString_cf33fc;
	}
	text.pop_back();
	text = text + padLeft(intToString(build.back() - 'a'),2,'0');
	return text;
}

extern bool opr1c_flag_caed25;	// NOTE: placeholder name

string opr1c_getExtension_4328b0()	// 0x4328b0, NOTE: placeholder name
{
	return opr1c_flag_caed25 ? string() + ".xd" : string() + ".xt";
}

//==================================================================
// save file names
//==================================================================

extern string gameString_cfd42c;	// NOTE: placeholder name (CUSTOM_FILE_PATH)

string opr1c_getSaveName_432af0(int version, bool error)	// 0x432af0, NOTE: placeholder name
{
	return gameString_cfd42c + "user/" + "save_v" + intToString(version) + (error ? ".err" : ".sav");
}

string opr1c_getSaveName_432c70(string version)	// 0x432c70, NOTE: placeholder name
{
	return gameString_cfd42c + "user/" + "save_v" + version + ".sav";
}

string opr1c_getChronoSaveName_432d80()	// 0x432d80, NOTE: placeholder name
{
	return gameString_cfd42c + "user/" + "save_v" + intToString(94) + "_chrono" + ".sav";
}

string opr1c_getManualSaveName_432f20(const string &name)	// 0x432f20, NOTE: placeholder name
{
	return gameString_cfd42c + "user/" + "save_v" + intToString(94) + "_manual_" + name + ".sav";
}

string opr1c_getFatalSaveName_433100()	// 0x433100, NOTE: placeholder name
{
	return gameString_cfd42c + "user/" + "save_v" + intToString(94) + "-fatal.sav";
}

//==================================================================
// security level names
//==================================================================

extern const int opr1c_thresholds_b91b78[6];	// NOTE: placeholder name
extern const int opr1c_thresholds_b91b7c_hi[6];	// NOTE: placeholder name (0xb91b7c)

string opr1c_getSecurityName_4332b0(int value)	// 0x4332b0, NOTE: placeholder name
{
	int rank = opr1c_getThresholdIndex(value);
	if (rank == 0)
		return "Low Security";
	string name = intToString(rank);
	if (rank == 5)
		name += 'X';
	else
	{
		int span = (opr1c_thresholds_b91b7c_hi[rank] - opr1c_thresholds_b91b78[rank]) / 26;
		string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int letterIndex = (value - opr1c_thresholds_b91b78[rank]) / span;
		while (letterIndex >= alphabet.size())
			letterIndex--;
		name += "-";
		name += alphabet[letterIndex];
	}
	return name;
}
