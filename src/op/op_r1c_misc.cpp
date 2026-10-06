// op_r1c_misc: XConsole helpers built on the engine header, Beta 17.1.
// NOTE: class names other than XConsole/REX are placeholders.
#include "engine/xconsole.h"

class OpR1b_SurfaceWrapper	// NOTE: placeholder name (0x413d50 ctor, 0x413d80 dtor)
{
public:
	void *surface;

	OpR1b_SurfaceWrapper(int width, int height, bool flag);
	~OpR1b_SurfaceWrapper();
	void save(string file);	// NOTE: placeholder name (0x413e00)
};

class OpR1c_ConsoleExt : public XConsole	// NOTE: placeholder name
{
public:
	void blit(void *surface, int flag);	// 0x42a5b0
	void saveScreenshot(string file);	// 0x42d2c0, NOTE: placeholder name
};

class OpR1c_Rex	// NOTE: placeholder name (REX object at 0xd223f0)
{
public:
	int getCellWidth();	// 0x4189c0, NOTE: placeholder name
	int getCellHeight();	// 0x4189e0, NOTE: placeholder name
};
extern OpR1c_Rex opr1c_rex;	// 0xd223f0, NOTE: placeholder name

void OpR1c_ConsoleExt::saveScreenshot(string file)
{
	file += ".png";
	OpR1b_SurfaceWrapper image(getWidth() * (opr1c_rex.getCellWidth() * FONT_TYPE_WIDTH[fontType]),getHeight() * (opr1c_rex.getCellHeight() * FONT_TYPE_HEIGHT[fontType]),true);
	blit(image.surface,0);
	image.save(file);
}

//==================================================================
// per-font-set charmap
//==================================================================

extern vector<vector<int>*> fontCharmaps;	// 0xd20ae8, NOTE: placeholder name

struct OpR1c_FontParams	// NOTE: placeholder name
{
	int type;
	int width;
	int height;
	int unknownc;
};

class OpR1c_FontSetInfo	// NOTE: placeholder name (REX::FontSetInfo, 0x40 bytes)
{
public:
	void init(OpR1c_FontParams *params);	// 0x42e7d0, NOTE: placeholder name
	void unknown416960();	// NOTE: placeholder name

	int type;
	int width;
	int height;
	int unknownc;
	vector<int> charmap;
	char pad20[0x40 - 0x20];
};

void OpR1c_FontSetInfo::init(OpR1c_FontParams *params)
{
	type = params->type;
	width = params->width;
	height = params->height;
	unknownc = params->unknownc;
	charmap.assign(width * height,0);
	unknown416960();
	fontCharmaps.push_back(&charmap);
}

//==================================================================
// desktop resolution check for font sets
//==================================================================

class OpR1c_RexDesktop	// NOTE: placeholder name (REX at 0xd223f0)
{
public:
	int getDesktopWidth();	// 0x418980, NOTE: placeholder name
	int getDesktopHeight();	// 0x4189a0, NOTE: placeholder name
	int getMaxWidth();	// 0x9b6bf0 (ICF'd getter of +0x1c), NOTE: placeholder name
	int getMaxHeight();	// 0x44afb0 (ICF'd getter of +0x20), NOTE: placeholder name
	bool checkFontSetFits(int width, int height, int mode, bool *keep);	// 0x42f530, NOTE: placeholder name
};

void logMessage(string message);	// NOTE: placeholder name (0x404cb0)

bool OpR1c_RexDesktop::checkFontSetFits(int width, int height, int mode, bool *keep)
{
	if (getDesktopWidth() * width > getMaxWidth() || getDesktopHeight() * height > getMaxHeight())
	{
		switch (mode)
		{
			case 0:
				logMessage("   (set removed, resolution exceeds desktop)");
				return false;
			case 1:
				logMessage("   (set resolution exceeds desktop, but including for other potential applications)");
				*keep = true;
				return true;
		}
	}
	return true;
}
