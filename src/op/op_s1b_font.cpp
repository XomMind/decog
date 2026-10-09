// op_s1b: font data loading (0x42e850-0x42f530)
#include <string>
#include "../engine/xcolor.h"
using namespace std;

struct SDL_PixelFormat
{
	void *palette;	// +0x00
	unsigned char BitsPerPixel;	// +0x04
	unsigned char BytesPerPixel;	// +0x05
	unsigned char Rloss;	// +0x06
	unsigned char Gloss;
	unsigned char Bloss;
	unsigned char Aloss;
	unsigned char Rshift;	// +0x0a
	unsigned char Gshift;
	unsigned char Bshift;
	unsigned char Ashift;	// +0x0d
	unsigned int Rmask;	// +0x10
	unsigned int Gmask;
	unsigned int Bmask;
	unsigned int Amask;
};

struct SDL_Surface
{
	unsigned int flags;	// +0x00
	SDL_PixelFormat *format;	// +0x04
	int w;	// +0x08
	int h;	// +0x0c
	unsigned short pitch;	// +0x10
	void *pixels;	// +0x14
};

extern "C" int SDL_UpperBlit(SDL_Surface *src, void *srcrect, SDL_Surface *dst, void *dstrect);
extern "C" void SDL_FreeSurface(SDL_Surface *surface);
extern "C" unsigned int SDL_MapRGB(SDL_PixelFormat *format, unsigned char r, unsigned char g, unsigned char b);
extern "C" int SDL_SetColorKey(SDL_Surface *surface, unsigned int flag, unsigned int key);

void logError(string location, string message);	// NOTE: placeholder name (0x404f10)
string intToString(int value);	// 0x4051f0
SDL_Surface *OpR1a_createSurface(int width, int height, bool alpha);	// NOTE: placeholder name (0x413e80)

struct XBitmap;	// NOTE: placeholder name (same object as SDL_Surface, see setBitmap)

class XResourceMgr
{
public:
	SDL_Surface *getSurfaceFromFile(const string &path);	// 0x4159a0
};
extern XResourceMgr *opS1b_resMgr;	// NOTE: placeholder name (0xcefa88)

extern XColor &COLOR_BLACK;	// 0xcfe674, NOTE: placeholder name
extern XColor &COLOR_WHITE;	// 0xcfabbc, NOTE: placeholder name
extern XColor opS1b_fontColorA;	// NOTE: placeholder name (0xd22488)
extern XColor opS1b_fontColorB;	// NOTE: placeholder name (0xcefd14)
extern string opS1b_fontDir;	// NOTE: placeholder name (0xd2246c)
extern const int OPS1B_FONT_TYPE_WIDTH[];	// 0xb8cf08 {1,2,2,4}, NOTE: placeholder name

class OpS1b_FontSet	// NOTE: placeholder name
{
public:
	int type;
	int pad4;
	int rows;	// +0x08
};

class XFontData
{
public:
	bool loadCharmap(OpS1b_FontSet *fontSet_, string file, int columns, int rows);
	void setBitmap(XBitmap *bitmap_, int columns, int rows);	// NOTE: placeholder name (0x42efa0)

	string name;
	OpS1b_FontSet *fontSet;	// +0x1c
	XFontData *autoscaleSource;	// +0x20
	int autoscaleFactor;	// +0x24
	SDL_Surface *bitmap;	// +0x28
	int charWidth;	// +0x2c
	int charHeight;	// +0x30
	int bytesPerPixel;	// +0x34
	int rowPadding;	// +0x38
	XColor colorKey;	// +0x3c
	unsigned int colorKeyValue;	// +0x40
	unsigned int colorMask;	// +0x44
	unsigned int colorMaskInverse;	// +0x48
};

bool XFontData::loadCharmap(OpS1b_FontSet *fontSet_, string file, int columns, int rows)
{
	fontSet = fontSet_;
	name.assign(file.begin(),file.begin() + file.rfind('.',string::npos));
	string path = opS1b_fontDir.empty() ? file : opS1b_fontDir + "/" + file;
	SDL_Surface *image = opS1b_resMgr->getSurfaceFromFile(path);
	if (image == NULL)
	{
		logError("XFontData::loadCharmap()","Unable to read font \"" + file + "\"");
		SDL_FreeSurface(image);
		return false;
	}
	if (image->w % columns != 0 || image->h % rows != 0)
	{
		logError("XFontData::loadCharmap()","Font \"" + file + "\" image dimensions are not a multiple of the specified columns/rows (" + intToString(columns) + "x" + intToString(rows) + ")");
		SDL_FreeSurface(image);
		return false;
	}
	setBitmap((XBitmap *)image,columns,rows);
	return true;
}

void XFontData::setBitmap(XBitmap *bitmap_, int columns, int rows)
{
	bitmap = (SDL_Surface *)bitmap_;
	charWidth = bitmap->w / columns;
	charHeight = bitmap->h / rows;
	int w;
	int h;
	int x;
	int y;
	bool hasAlpha = false;
	h = charHeight * fontSet->rows;
	if (bitmap->format->BytesPerPixel == 4)
	{
		for (x = 0; x < bitmap->w; x++)
		{
			for (y = 0; y < bitmap->h; y++)
			{
				unsigned char *pixel = (unsigned char *)bitmap->pixels + bitmap->pitch * y + bitmap->format->BytesPerPixel * x;
				int p;	// NOTE: unused in the exe too (it only reserves a stack slot); name picked to match the slot order
				unsigned char alpha = pixel[bitmap->format->Ashift / 8];
				if (alpha < 255)
				{
					hasAlpha = true;
					goto alphaDone;
				}
			}
		}
alphaDone:;
	}
	else if (bitmap->format->BytesPerPixel != 3)
	{
		SDL_Surface *converted = OpR1a_createSurface(bitmap->w,h,false);
		SDL_UpperBlit(bitmap,NULL,converted,NULL);
		SDL_FreeSurface(bitmap);
		bitmap = converted;
	}
	if (!hasAlpha)
	{
		unsigned char *first = (unsigned char *)bitmap->pixels;
		if (opS1b_fontColorA != opS1b_fontColorB)
			colorKey = opS1b_fontColorA;
		else
		{
			colorKey.r = first[bitmap->format->Rshift / 8];
			colorKey.g = first[bitmap->format->Gshift / 8];
			colorKey.b = first[bitmap->format->Bshift / 8];
		}
		if (colorKey == COLOR_BLACK || colorKey == COLOR_WHITE)
		{
			bool invert = colorKey == COLOR_WHITE;
			if (bitmap->format->BytesPerPixel != 4)
			{
				SDL_Surface *converted = OpR1a_createSurface(bitmap->w,h,true);
				SDL_UpperBlit(bitmap,NULL,converted,NULL);
				SDL_FreeSurface(bitmap);
				bitmap = converted;
			}
			for (x = 0; x < bitmap->w; x++)
			{
				for (y = 0; y < bitmap->h; y++)
				{
					unsigned char *pixel = (unsigned char *)bitmap->pixels + bitmap->pitch * y + bitmap->format->BytesPerPixel * x;
					unsigned char c = pixel[bitmap->format->Rshift / 8];
					pixel[bitmap->format->Ashift / 8] = invert ? 255 - c : c;
					pixel[bitmap->format->Rshift / 8] = 255;
					pixel[bitmap->format->Gshift / 8] = 255;
					pixel[bitmap->format->Bshift / 8] = 255;
				}
			}
		}
		else
		{
			SDL_Surface *converted = OpR1a_createSurface(bitmap->w,h,false);
			SDL_UpperBlit(bitmap,NULL,converted,NULL);
			SDL_FreeSurface(bitmap);
			bitmap = converted;
		}
	}
	bytesPerPixel = bitmap->format->BytesPerPixel;
	w = charWidth / OPS1B_FONT_TYPE_WIDTH[fontSet->type];
	rowPadding = bytesPerPixel == 4 ? (bitmap->pitch - w * bytesPerPixel) / 4 : bitmap->pitch - w * bytesPerPixel;
	colorKeyValue = SDL_MapRGB(bitmap->format,colorKey.r,colorKey.g,colorKey.b);
	colorMask = bitmap->format->Rmask | bitmap->format->Gmask | bitmap->format->Bmask;
	colorMaskInverse = ~colorMask;
	colorKeyValue = colorKeyValue & colorMask;
	if (bytesPerPixel == 3)
		SDL_SetColorKey(bitmap,0x5000,colorKeyValue);
}
