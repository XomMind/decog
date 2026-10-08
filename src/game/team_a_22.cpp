// team_a_22: prefab art layer transforms (rotate 0x447010, horizontal flip 0x447840) matched against COGMIND.exe (Beta 17.1).
// NOTE: placeholder names; the grid helpers they call are template instances defined elsewhere.
#include <vector>
#include "engine/xcolor.h"
using namespace std;

struct XCell	// NOTE: placeholder layout (0x14 bytes)
{
	int font;
	int ch;
	int glyph;
	XColor fore;
	XColor back;

	XCell();	// 0x427e80
	XCell(const XCell &cell);	// 0x416da0
	XCell &operator=(const XCell &cell);	// 0x416e40
	int getChar_9b8f00();	// NOTE: placeholder name (folded +4 getter)
	void setChar(int ch_);	// 0x427fd0
};

class TeamA22_ArtGrid	// NOTE: placeholder name (Array2D<XCell>)
{
public:
	int getWidth();
	int getHeight();
	XCell *at(int x, int y);
	void expand(XCell value, int left, int right, int top, int bottom);	// NOTE: placeholder name
	void contract(int left, int right, int top, int bottom);	// NOTE: placeholder name
};
void ops7_rotateGrid_9cf450(TeamA22_ArtGrid *grid);	// NOTE: placeholder name
int abs(int value);
bool OpT8b_Fn9daf80(int min, int value, int max);	// NOTE: placeholder name (isBetween)

class TeamA22_ArtLayers	// NOTE: placeholder name (prefab art layers)
{
public:
	void rotate_447010(bool rotateGlyphs);	// NOTE: placeholder name
	void flipHorizontal_447840(bool mirrorGlyphs);	// NOTE: placeholder name

	vector<TeamA22_ArtGrid *> layers;
};

// rotates every layer by 90 degrees (padding non-square layers to a square first), optionally rotating the
// line-drawing glyphs as well
void TeamA22_ArtLayers::rotate_447010(bool rotateGlyphs)
{
	XCell cell;
	for (unsigned int i = 0; i < layers.size(); i++)
	{
		TeamA22_ArtGrid *layer = layers[i];
		if (layer->getWidth() == layer->getHeight())
			ops7_rotateGrid_9cf450(layers[i]);
		else
		{
			bool horiz = layer->getWidth() > layer->getHeight();
			int delta = abs(layer->getWidth() - layer->getHeight());
			if (horiz)
				layer->expand(cell,0,0,0,delta);
			else
				layer->expand(cell,0,delta,0,0);
			ops7_rotateGrid_9cf450(layers[i]);
			if (horiz)
				layer->contract(delta,0,0,0);
			else
				layer->contract(0,0,0,delta);
		}
		if (rotateGlyphs)
		{
			for (int x = 0; x < layer->getWidth(); x++)
			{
				for (int y = 0; y < layer->getHeight(); y++)
				{
					if (OpT8b_Fn9daf80(0x80,layer->at(x,y)->getChar_9b8f00(),0xae))
					{
						switch (layer->at(x,y)->getChar_9b8f00())
						{
						case 0x80: layer->at(x,y)->setChar(0x81); break;
						case 0x81: layer->at(x,y)->setChar(0x80); break;
						case 0x83: layer->at(x,y)->setChar(0x84); break;
						case 0x84: layer->at(x,y)->setChar(0x85); break;
						case 0x85: layer->at(x,y)->setChar(0x86); break;
						case 0x86: layer->at(x,y)->setChar(0x83); break;
						case 0x87: layer->at(x,y)->setChar(0x88); break;
						case 0x88: layer->at(x,y)->setChar(0x89); break;
						case 0x89: layer->at(x,y)->setChar(0x8a); break;
						case 0x8a: layer->at(x,y)->setChar(0x87); break;
						case 0x8c: layer->at(x,y)->setChar(0x8d); break;
						case 0x8d: layer->at(x,y)->setChar(0x8c); break;
						case 0x8f: layer->at(x,y)->setChar(0x90); break;
						case 0x90: layer->at(x,y)->setChar(0x91); break;
						case 0x91: layer->at(x,y)->setChar(0x92); break;
						case 0x92: layer->at(x,y)->setChar(0x8f); break;
						case 0x93: layer->at(x,y)->setChar(0x94); break;
						case 0x94: layer->at(x,y)->setChar(0x95); break;
						case 0x95: layer->at(x,y)->setChar(0x96); break;
						case 0x96: layer->at(x,y)->setChar(0x93); break;
						case 0x98: layer->at(x,y)->setChar(0x9e); break;
						case 0x99: layer->at(x,y)->setChar(0x9f); break;
						case 0x9a: layer->at(x,y)->setChar(0xa0); break;
						case 0x9b: layer->at(x,y)->setChar(0xa1); break;
						case 0x9c: layer->at(x,y)->setChar(0x9d); break;
						case 0x9d: layer->at(x,y)->setChar(0x9c); break;
						case 0x9e: layer->at(x,y)->setChar(0x9b); break;
						case 0x9f: layer->at(x,y)->setChar(0x9a); break;
						case 0xa0: layer->at(x,y)->setChar(0x99); break;
						case 0xa1: layer->at(x,y)->setChar(0x98); break;
						case 0xa2: layer->at(x,y)->setChar(0xa4); break;
						case 0xa3: layer->at(x,y)->setChar(0xa5); break;
						case 0xa4: layer->at(x,y)->setChar(0xa6); break;
						case 0xa5: layer->at(x,y)->setChar(0xa7); break;
						case 0xa6: layer->at(x,y)->setChar(0xa9); break;
						case 0xa7: layer->at(x,y)->setChar(0xa8); break;
						case 0xa8: layer->at(x,y)->setChar(0xa3); break;
						case 0xa9: layer->at(x,y)->setChar(0xa2); break;
						case 0xab: layer->at(x,y)->setChar(0xac); break;
						case 0xac: layer->at(x,y)->setChar(0xae); break;
						case 0xad: layer->at(x,y)->setChar(0xab); break;
						case 0xae: layer->at(x,y)->setChar(0xad); break;
						}
					}
				}
			}
		}
	}
}

// mirrors every layer left-to-right, optionally swapping the line-drawing glyphs that have a mirrored twin
void TeamA22_ArtLayers::flipHorizontal_447840(bool mirrorGlyphs)
{
	int w = layers.front()->getWidth();
	int h = layers.front()->getHeight();
	XCell cell;
	for (unsigned int i = 0; i < layers.size(); i++)
	{
		TeamA22_ArtGrid *layer = layers[i];
		for (int x = 0, x2 = w - 1; x < w / 2; x++, x2--)
		{
			for (int y = 0; y < h; y++)
			{
				cell = *layer->at(x,y);
				*layer->at(x,y) = *layer->at(x2,y);
				*layer->at(x2,y) = cell;
			}
		}
		if (mirrorGlyphs)
		{
			for (int x = 0; x < layer->getWidth(); x++)
			{
				for (int y = 0; y < layer->getHeight(); y++)
				{
					if (OpT8b_Fn9daf80(0x80,layer->at(x,y)->getChar_9b8f00(),0xae))
					{
						switch (layer->at(x,y)->getChar_9b8f00())
						{
						case 0x83: layer->at(x,y)->setChar(0x85); break;
						case 0x85: layer->at(x,y)->setChar(0x83); break;
						case 0x87: layer->at(x,y)->setChar(0x8a); break;
						case 0x88: layer->at(x,y)->setChar(0x89); break;
						case 0x89: layer->at(x,y)->setChar(0x88); break;
						case 0x8a: layer->at(x,y)->setChar(0x87); break;
						case 0x8f: layer->at(x,y)->setChar(0x91); break;
						case 0x91: layer->at(x,y)->setChar(0x8f); break;
						case 0x93: layer->at(x,y)->setChar(0x96); break;
						case 0x94: layer->at(x,y)->setChar(0x95); break;
						case 0x95: layer->at(x,y)->setChar(0x94); break;
						case 0x96: layer->at(x,y)->setChar(0x93); break;
						case 0x98: layer->at(x,y)->setChar(0x9b); break;
						case 0x99: layer->at(x,y)->setChar(0x9a); break;
						case 0x9a: layer->at(x,y)->setChar(0x99); break;
						case 0x9b: layer->at(x,y)->setChar(0x98); break;
						case 0xa2: layer->at(x,y)->setChar(0xa8); break;
						case 0xa3: layer->at(x,y)->setChar(0xa9); break;
						case 0xa4: layer->at(x,y)->setChar(0xa7); break;
						case 0xa5: layer->at(x,y)->setChar(0xa6); break;
						case 0xa6: layer->at(x,y)->setChar(0xa5); break;
						case 0xa7: layer->at(x,y)->setChar(0xa4); break;
						case 0xa8: layer->at(x,y)->setChar(0xa2); break;
						case 0xa9: layer->at(x,y)->setChar(0xa3); break;
						case 0xac: layer->at(x,y)->setChar(0xad); break;
						case 0xad: layer->at(x,y)->setChar(0xac); break;
						}
					}
				}
			}
		}
	}
}
