// op_xconsole_blit: XConsole::blit, draws a console's cells onto an SDL surface (COGMIND.exe Beta 17.1).
// Each changed cell (compared against the previous frame, if given) gets its background filled and
// its glyph blitted from the font bitmap; glyph pixels are recoloured in place whenever the cached
// colour for that glyph differs from the cell's foreground. Three variants: a single font set, mixed
// fonts per cell, and mixed fonts with multi-cell glyphs (wide/quad/oct) resolved via the root's
// per-cell owner map.
#include <string>
#include <vector>
#include "engine/xcolor.h"
using namespace std;

typedef unsigned char Uint8;
typedef unsigned short Uint16;
typedef unsigned int Uint32;

struct SDL_PixelFormat
{
	void *palette;	// +0x00
	Uint8 BitsPerPixel;	// +0x04
	Uint8 BytesPerPixel;	// +0x05
	Uint8 Rloss;
	Uint8 Gloss;
	Uint8 Bloss;
	Uint8 Aloss;
	Uint8 Rshift;
	Uint8 Gshift;
	Uint8 Bshift;
	Uint8 Ashift;
	Uint32 Rmask;	// +0x10
	Uint32 Gmask;
	Uint32 Bmask;
	Uint32 Amask;	// +0x1c
};

struct SDL_Surface
{
	Uint32 flags;	// +0x00
	SDL_PixelFormat *format;	// +0x04
	int w;	// +0x08
	int h;	// +0x0c
	Uint16 pitch;	// +0x10
	void *pixels;	// +0x14
};

struct SDL_Rect
{
	short x;
	short y;
	Uint16 w;
	Uint16 h;
};

extern "C" Uint32 SDL_MapRGB(SDL_PixelFormat *format, Uint8 r, Uint8 g, Uint8 b);
extern "C" int SDL_FillRect(SDL_Surface *dst, SDL_Rect *dstrect, Uint32 color);
extern "C" int SDL_UpperBlit(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect);

string intToString(int value);	// 0x4051f0
void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)

struct XColorFilter	// NOTE: placeholder name
{
	int type;
	int amount;
	float value;
	XColor color;
};
extern vector<XColorFilter> colorFilters;	// NOTE: placeholder name (0xd1d45c)

struct XCell	// NOTE: placeholder name
{
	int font;
	int ch;
	int glyph;
	XColor fore;	// +0x0c
	XColor back;	// +0x0f

	bool operator!=(const XCell &cell);	// 0x416eb0
	void applyFilters();	// 0x417230
};

// per-cell record of the root: which part of a multi-cell glyph a cell shows
struct XCellOwner	// NOTE: placeholder name and layout
{
	int unknown0;	// NOTE: placeholder name
	int part;	// +0x04, NOTE: placeholder name
	int fontType;	// +0x08, NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *data;

	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
	T *get(int x, int y) throw();	// 0x9cdf20 / 0x9ceda0
	T *getData_9b4350();	// NOTE: placeholder name (folded getter)
};

class XFontData	// NOTE: placeholder layout (see op_s1b_font.cpp)
{
public:
	string name;
	void *fontSet;	// +0x1c
	XFontData *autoscaleSource;	// +0x20
	int autoscaleFactor;	// +0x24
	SDL_Surface *bitmap;	// +0x28
	int charWidth;	// +0x2c
	int charHeight;	// +0x30
	int bytesPerPixel;	// +0x34
	int rowPadding;	// +0x38
	XColor colorKey;	// +0x3c
	Uint32 colorKeyValue;	// +0x40
	Uint32 colorMask;	// +0x44
	Uint32 colorMaskInverse;	// +0x48
};

class XFontSet	// NOTE: placeholder name
{
public:
	string name;
	vector<XFontData*> fonts;	// +0x1c
	int charWidth;	// +0x2c
	int charHeight;	// +0x30
};

class XConsole
{
public:
	virtual ~XConsole();

	void blit(SDL_Surface *surface, Array2D<XCell> *previous);

	XConsole *parent;
	Array2D<XCell> buffer;	// +0x08
	int font;	// +0x14
	char pad18[0x60 - 0x18];
};

class XRoot : public XConsole
{
public:
	char pad60[0x64 - 0x60];
	Array2D<XCellOwner*> owners;	// +0x64, NOTE: placeholder name
};

class REX
{
public:
	struct FontSetInfo	// NOTE: placeholder name (0x40 bytes)
	{
		int type;
		int columns;	// +0x04, NOTE: placeholder name
		char pad08[0x20 - 0x08];
		vector<vector<XColor> > colors;	// +0x20, NOTE: placeholder name; cached glyph colour per glyph and part
		vector<vector<bool> > dirty;	// +0x30, NOTE: placeholder name
	};

	XConsole *getRoot_4ab670();	// NOTE: placeholder name (folded getter)

	char pad0[0x14];
	int x;	// +0x14, NOTE: placeholder name
	int y;	// +0x18, NOTE: placeholder name
	char pad1c[0x9c - 0x1c];
	vector<FontSetInfo> fontSets;	// +0x9c
	char padac[0xd0 - 0xac];
	XFontSet *currentFontSet;	// +0xd0
	bool mixedFonts;	// +0xd4, NOTE: placeholder name
};
extern REX rex;	// 0xd223f0

class XScreenShake	// NOTE: placeholder name
{
public:
	bool boundary(bool *output);	// NOTE: placeholder name (0x42e550)

	unsigned int endTime;	// NOTE: placeholder name; +0x00
	bool stopped;	// NOTE: placeholder name; +0x04
	int offsetX;	// NOTE: placeholder name; +0x08
	int offsetY;	// NOTE: placeholder name; +0x0c
};
extern XScreenShake screenShake_d16188;	// NOTE: placeholder name

extern SDL_Surface *screenSurface;	// NOTE: placeholder name (0xcefa80)
extern const int FONT_TYPE_WIDTH[];	// 0xb8cf18 {1,2,2,4}, NOTE: placeholder name

void XConsole::blit(SDL_Surface *surface, Array2D<XCell> *previous)
{
	int width = buffer.getWidth();
	int height = buffer.getHeight();
	if (!colorFilters.empty())
	{
		for (int x = 0; x < width; x++)
		{
			for (int y = 0; y < height; y++)
				buffer.get(x,y)->applyFilters();
		}
	}

	// NOTE: locals are declared up front in the order the exe's frame layout requires
	if (rex.fontSets.size() == 1)
	{
		SDL_Surface *fontSurface;
		int glyph;
		XCell *newCell;
		XCell *prevCellPtr;
		int quakeDY;
		int charW;
		SDL_Rect srcRect;
		int fontColumns;
		vector<vector<bool> > *dirty;
		Uint32 invMask;
		int xOff;
		vector<vector<XColor> > *colorCache;
		Uint32 maskColor;
		bool shake;
		int charHeight;
		SDL_Rect dst;
		int x;
		int y;
		Uint8 bpp;
		int linePadding;
		int quakeDX;
		Uint32 bgPixel;
		Uint32 fgPixel;
		int yOff;
		XFontData *fontRec;
		Uint32 transPixel;

		fontRec = rex.currentFontSet->fonts[font];
		colorCache = &rex.fontSets[font].colors;
		dirty = &rex.fontSets[font].dirty;
		fontSurface = fontRec->bitmap;
		fontColumns = rex.fontSets[font].columns;
		charW = fontRec->charWidth;
		charHeight = fontRec->charHeight;
		XColor keyColor = fontRec->colorKey;
		transPixel = fontRec->colorKeyValue;
		maskColor = fontRec->colorMask;
		invMask = fontRec->colorMaskInverse;
		bgPixel = 0;
		fgPixel = 0;
		bpp = fontSurface->format->BytesPerPixel;
		newCell = buffer.getData_9b4350();
		prevCellPtr = previous ? previous->getData_9b4350() : NULL;
		linePadding = bpp == 4 ? (fontSurface->pitch - bpp * charW) / 4 : fontSurface->pitch - bpp * charW;
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = charW;
		srcRect.h = charHeight;
		xOff = surface == screenSurface ? rex.x : 0;
		yOff = surface == screenSurface ? rex.y : 0;
		if (screenShake_d16188.boundary(&shake))
			previous = NULL;
		quakeDX = shake ? charW * screenShake_d16188.offsetX : 0;
		quakeDY = shake ? charHeight * screenShake_d16188.offsetY : 0;

		if (width * charW + xOff > surface->w)
			logFatal("XConsole::blit()","Console does not fit on target surface (" + intToString(xOff) + " + " + intToString(width) + "*" + intToString(charW) + " > " + intToString(surface->w) + ")");
		if (height * charHeight + yOff > surface->h)
			logFatal("XConsole::blit()","Console does not fit on target surface (" + intToString(yOff) + " + " + intToString(height) + "*" + intToString(charHeight) + " > " + intToString(surface->h) + ")");

		for (x = 0; x < width; x++)
		{
			for (y = 0; y < height; y++)
			{
				if (previous ? *newCell != *prevCellPtr : true)
				{
					dst.x = x * charW + xOff;
					dst.y = y * charHeight + yOff;
					dst.w = charW;
					dst.h = charHeight;
					if (shake)
					{
						dst.x += quakeDX;
						dst.y += quakeDY;
					}
					bgPixel = SDL_MapRGB(surface->format,newCell->back.r,newCell->back.g,newCell->back.b);
					SDL_FillRect(surface,&dst,bgPixel);
					if (newCell->ch != ' ' && newCell->fore != newCell->back)
					{
						glyph = newCell->glyph;
						XColor fore = newCell->fore;
						if (fontSurface->format->Amask == 0 && fore == keyColor)
						{
							if (fore.r < 255)
								fore.r++;
							else
								fore.r--;
						}
						srcRect.x = (glyph % fontColumns) * charW;
						srcRect.y = (glyph / fontColumns) * charHeight;
						if ((*dirty)[glyph][0] || (*colorCache)[glyph][0] != fore)
						{
							(*colorCache)[glyph][0] = fore;
							(*dirty)[glyph][0] = false;
							fgPixel = SDL_MapRGB(fontSurface->format,fore.r,fore.g,fore.b) & maskColor;
							if (bpp == 4)
							{
								Uint32 *pixels = (Uint32 *)((Uint8 *)fontSurface->pixels + srcRect.x * bpp + srcRect.y * fontSurface->pitch);
								int row = charHeight;
								while (row--)
								{
									int col = charW;
									while (col--)
									{
										*pixels &= invMask;
										*pixels |= fgPixel;
										pixels++;
									}
									pixels += linePadding;
								}
							}
							else
							{
								Uint8 *pixels = (Uint8 *)fontSurface->pixels + srcRect.x * bpp + srcRect.y * fontSurface->pitch;
								int row = charHeight;
								while (row--)
								{
									int col = charW;
									while (col--)
									{
										if ((*(Uint32 *)pixels & maskColor) != transPixel)
										{
											*(Uint32 *)pixels &= invMask;
											*(Uint32 *)pixels |= fgPixel;
										}
										pixels += 3;
									}
									pixels += linePadding;
								}
							}
						}
						SDL_UpperBlit(fontSurface,&srcRect,surface,&dst);
					}
				}
				newCell++;
				prevCellPtr++;
			}
		}
	}
	else if (rex.mixedFonts)
	{
		SDL_Surface *fontSurface;
		int glyph;
		XCell *newCell;
		XCell *prevCellPtr;
		int quakeDY;
		int charW;
		SDL_Rect srcRect;
		vector<XFontData*> *fonts;
		int xOff;
		bool shake;
		int charHeight;
		REX::FontSetInfo *fsi;
		SDL_Rect dst;
		int x;
		int y;
		int quakeDX;
		Uint32 bgPixel;
		Uint32 fgPixel;
		int yOff;
		vector<REX::FontSetInfo> *fsets;
		XFontData *fontRec;

		fonts = &rex.currentFontSet->fonts;
		fsets = &rex.fontSets;
		charW = rex.currentFontSet->charWidth;
		charHeight = rex.currentFontSet->charHeight;
		bgPixel = 0;
		fgPixel = 0;
		fontRec = NULL;
		newCell = buffer.getData_9b4350();
		prevCellPtr = previous ? previous->getData_9b4350() : NULL;
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = charW;
		srcRect.h = charHeight;
		xOff = surface == screenSurface ? rex.x : 0;
		yOff = surface == screenSurface ? rex.y : 0;
		if (screenShake_d16188.boundary(&shake))
			previous = NULL;
		quakeDX = shake ? charW * screenShake_d16188.offsetX : 0;
		quakeDY = shake ? charHeight * screenShake_d16188.offsetY : 0;

		if (width * charW + xOff > surface->w)
			logFatal("XConsole::blit()","Console does not fit on target surface (" + intToString(xOff) + " + " + intToString(width) + "*" + intToString(charW) + " > " + intToString(surface->w) + ")");
		if (height * charHeight + yOff > surface->h)
			logFatal("XConsole::blit()","Console does not fit on target surface (" + intToString(yOff) + " + " + intToString(height) + "*" + intToString(charHeight) + " > " + intToString(surface->h) + ")");

		for (x = 0; x < width; x++)
		{
			for (y = 0; y < height; y++)
			{
				if (previous ? *newCell != *prevCellPtr : true)
				{
					dst.x = x * charW + xOff;
					dst.y = y * charHeight + yOff;
					dst.w = charW;
					dst.h = charHeight;
					if (shake)
					{
						dst.x += quakeDX;
						dst.y += quakeDY;
					}
					bgPixel = SDL_MapRGB(surface->format,newCell->back.r,newCell->back.g,newCell->back.b);
					SDL_FillRect(surface,&dst,bgPixel);
					if (newCell->ch != ' ' && newCell->fore != newCell->back)
					{
						if (fontRec != (*fonts)[newCell->font])
						{
							fontRec = (*fonts)[newCell->font];
							fontSurface = fontRec->bitmap;
							fsi = &(*fsets)[newCell->font];
						}
						glyph = newCell->glyph;
						XColor fore = newCell->fore;
						if (fontSurface->format->Amask == 0 && fore == fontRec->colorKey)
						{
							if (fore.r < 255)
								fore.r++;
							else
								fore.r--;
						}
						srcRect.x = (glyph % fsi->columns) * charW;
						srcRect.y = (glyph / fsi->columns) * charHeight;
						if (fsi->dirty[glyph][0] || fsi->colors[glyph][0] != fore)
						{
							fsi->colors[glyph][0] = fore;
							fsi->dirty[glyph][0] = false;
							fgPixel = SDL_MapRGB(fontSurface->format,fore.r,fore.g,fore.b) & fontRec->colorMask;
							if (fontRec->bytesPerPixel == 4)
							{
								Uint32 *pixels = (Uint32 *)((Uint8 *)fontSurface->pixels + srcRect.x * fontRec->bytesPerPixel + srcRect.y * fontSurface->pitch);
								int row = charHeight;
								while (row--)
								{
									int col = charW;
									while (col--)
									{
										*pixels &= fontRec->colorMaskInverse;
										*pixels |= fgPixel;
										pixels++;
									}
									pixels += fontRec->rowPadding;
								}
							}
							else
							{
								Uint8 *pixels = (Uint8 *)fontSurface->pixels + srcRect.x * fontRec->bytesPerPixel + srcRect.y * fontSurface->pitch;
								int row = charHeight;
								while (row--)
								{
									int col = charW;
									while (col--)
									{
										if ((*(Uint32 *)pixels & fontRec->colorMask) != fontRec->colorKeyValue)
										{
											*(Uint32 *)pixels &= fontRec->colorMaskInverse;
											*(Uint32 *)pixels |= fgPixel;
										}
										pixels += 3;
									}
									pixels += fontRec->rowPadding;
								}
							}
						}
						SDL_UpperBlit(fontSurface,&srcRect,surface,&dst);
					}
				}
				newCell++;
				prevCellPtr++;
			}
		}
	}
	else
	{
		SDL_Surface *fontSurface;
		Array2D<XCellOwner*> *rootCells;
		int glyph;
		XCell *newCell;
		int quakeDY;
		int charW;
		SDL_Rect srcRect;
		int part;
		vector<XFontData*> *fonts;
		int xOff;
		int cH;
		bool shake;
		int cwidth;
		int charHeight;
		REX::FontSetInfo *fsi;
		SDL_Rect dst;
		int x;
		int y;
		int quakeDX;
		Uint32 bgPixel;
		Uint32 fgPixel;
		int yOff;
		vector<REX::FontSetInfo> *fsets;
		XFontData *fontRec;

		rootCells = &((XRoot *)rex.getRoot_4ab670())->owners;
		fonts = &rex.currentFontSet->fonts;
		fsets = &rex.fontSets;
		cwidth = rex.currentFontSet->charWidth;
		cH = rex.currentFontSet->charHeight;
		bgPixel = 0;
		fgPixel = 0;
		fontRec = NULL;
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = cwidth;
		srcRect.h = cH;
		xOff = surface == screenSurface ? rex.x : 0;
		yOff = surface == screenSurface ? rex.y : 0;
		if (screenShake_d16188.boundary(&shake))
			previous = NULL;
		quakeDX = shake ? cwidth * screenShake_d16188.offsetX : 0;
		quakeDY = shake ? cH * screenShake_d16188.offsetY : 0;

		if (width * cwidth + xOff > surface->w)
			logFatal("XConsole::blit()","Console does not fit on target surface (" + intToString(xOff) + " + " + intToString(width) + "*" + intToString(cwidth) + " > " + intToString(surface->w) + ")");
		if (height * cH + yOff > surface->h)
			logFatal("XConsole::blit()","Console does not fit on target surface (" + intToString(yOff) + " + " + intToString(height) + "*" + intToString(cH) + " > " + intToString(surface->h) + ")");

		for (x = 0; x < width; x++)
		{
			for (y = 0; y < height; y++)
			{
				newCell = buffer.get(x,y);
				if (previous ? *newCell != *previous->get(x,y) : true)
				{
					dst.x = x * cwidth + xOff;
					dst.y = y * cH + yOff;
					dst.w = cwidth;
					dst.h = cH;
					if (shake)
					{
						dst.x += quakeDX;
						dst.y += quakeDY;
					}
					bgPixel = SDL_MapRGB(surface->format,newCell->back.r,newCell->back.g,newCell->back.b);
					SDL_FillRect(surface,&dst,bgPixel);
					if (newCell->ch != ' ' && newCell->fore != newCell->back)
					{
						if (fontRec != (*fonts)[newCell->font])
						{
							fontRec = (*fonts)[newCell->font];
							charW = fontRec->charWidth;
							charHeight = fontRec->charHeight;
							fontSurface = fontRec->bitmap;
							fsi = &(*fsets)[newCell->font];
						}
						glyph = newCell->glyph;
						XColor fore = newCell->fore;
						if (fontSurface->format->Amask == 0 && fore == fontRec->colorKey)
						{
							if (fore.r < 255)
								fore.r++;
							else
								fore.r--;
						}
						srcRect.x = (glyph % fsi->columns) * charW;
						srcRect.y = (glyph / fsi->columns) * charHeight;
						part = (*rootCells->get(x,y))->part;
						if (part != 0)
						{
							switch ((*rootCells->get(x,y))->fontType)
							{
								case 1:
									srcRect.x += cwidth;
									break;
								case 2:
									srcRect.x += (part % FONT_TYPE_WIDTH[2]) * cwidth;
									srcRect.y += (part / FONT_TYPE_WIDTH[2]) * cH;
									break;
								case 3:
									srcRect.x += (part % FONT_TYPE_WIDTH[3]) * cwidth;
									srcRect.y += (part / FONT_TYPE_WIDTH[3]) * cH;
									break;
							}
						}
						if (fsi->colors[glyph][part] != fore || fsi->dirty[glyph][part])
						{
							fsi->colors[glyph][part] = fore;
							fsi->dirty[glyph][part] = false;
							fgPixel = SDL_MapRGB(fontSurface->format,fore.r,fore.g,fore.b) & fontRec->colorMask;
							if (fontRec->bytesPerPixel == 4)
							{
								Uint32 *pixels = (Uint32 *)((Uint8 *)fontSurface->pixels + srcRect.x * fontRec->bytesPerPixel + srcRect.y * fontSurface->pitch);
								int row = cH;
								while (row--)
								{
									int col = cwidth;
									while (col--)
									{
										*pixels &= fontRec->colorMaskInverse;
										*pixels |= fgPixel;
										pixels++;
									}
									pixels += fontRec->rowPadding;
								}
							}
							else
							{
								Uint8 *pixels = (Uint8 *)fontSurface->pixels + srcRect.x * fontRec->bytesPerPixel + srcRect.y * fontSurface->pitch;
								int row = cH;
								while (row--)
								{
									int col = cwidth;
									while (col--)
									{
										if ((*(Uint32 *)pixels & fontRec->colorMask) != fontRec->colorKeyValue)
										{
											*(Uint32 *)pixels &= fontRec->colorMaskInverse;
											*(Uint32 *)pixels |= fgPixel;
										}
										pixels += 3;
									}
									pixels += fontRec->rowPadding;
								}
							}
						}
						SDL_UpperBlit(fontSurface,&srcRect,surface,&dst);
					}
				}
			}
		}
	}
}
