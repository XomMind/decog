//==================================================================
// XRoot layers and visibility-gated console dispatch (Beta 17.1)
//==================================================================
#include "engine/xconsole.h"

// The shared xroot.h declares removeFromLayer as void; the binary returns bool.
// Keep this partial declaration local rather than changing the shared header.
// Compositor state: a per-cell record of the last console that wrote the cell
// this frame. Its fields are only partly understood, so names are placeholders.
struct XRootCellRecord	// NOTE: placeholder name
{
	int frame;
	int subcell;
	int fontType;
	XConsole *owner;
};


class XRoot : public XConsole
{
public:
	XRoot(int width, int height);
	virtual ~XRoot();	// Existing destructor body at 0x4184f0.
	virtual void update();
	virtual void render();

	bool addToLayer(XConsole *console, int layer);
	bool removeFromLayer(XConsole *console);
	int getLayer(XConsole *console);
	void removeEmptyLayers();

	void composite();	// 0x42ded0

	int frameCount;	// +0x60, NOTE: placeholder name
	Array2D<XRootCellRecord*> records;	// +0x64, NOTE: placeholder name
	vector<vector<XConsole*> > layers;	// +0x70, NOTE: placeholder name
};

template <class T> void removeVectorElement(vector<T> &v, int index);	// NOTE: placeholder name

// Membership is not unique. Explicit layers bypass parent lookup; a negative layer
// places a root child at zero, or a child one layer after the first stored parent.
// Each successful insertion overwrites console->layer, without removing old entries.
bool XRoot::addToLayer(XConsole *console, int layer)
{
	if (layer >= 0)
	{
		if (layer < layers.size())
			layers[layer].push_back(console);
		else
		{
			vector<XConsole*> emptyLayer;	// NOTE: placeholder name
			for (int i = layers.size(); i <= layer; i++)
				layers.push_back(emptyLayer);
			layers.back().push_back(console);
		}
		console->layer = layer;
		return true;
	}
	if (console->parent == this)
	{
		if (layers.empty())
		{
			vector<XConsole*> emptyLayer;	// NOTE: placeholder name
			layers.push_back(emptyLayer);
			layers.back().push_back(console);
		}
		else
			layers[0].push_back(console);
		console->layer = 0;
		return true;
	}
	else
	{
		for (unsigned int i = 0; i < layers.size(); i++)
		{
			for (unsigned int j = 0; j < layers[i].size(); j++)
			{
				if (layers[i][j] == console->parent)
				{
					if (i == layers.size() - 1)
					{
						vector<XConsole*> emptyLayer;	// NOTE: placeholder name
						layers.push_back(emptyLayer);
						layers.back().push_back(console);
					}
					else
						layers[i + 1].push_back(console);
					console->layer = i + 1;
					return true;
				}
			}
		}
		return false;
	}
}

// Remove only the first occurrence, in ascending layer/member order. Metadata is
// not reset and empty layers remain until removeEmptyLayers is called explicitly.
bool XRoot::removeFromLayer(XConsole *console)
{
	for (unsigned int i = 0; i < layers.size(); i++)
	{
		for (unsigned int j = 0; j < layers[i].size(); j++)
		{
			if (layers[i][j] == console)
			{
				removeVectorElement(layers[i],j);
				return true;
			}
		}
	}
	return false;
}

// Search actual membership rather than the potentially stale +0x58 metadata.
int XRoot::getLayer(XConsole *console)
{
	for (unsigned int i = 0; i < layers.size(); i++)
	{
		for (unsigned int j = 0; j < layers[i].size(); j++)
		{
			if (layers[i][j] == console)
				return i;
		}
	}
	return -1;
}

// Trim trailing empty layers only: interior holes and existing layer numbers stay.
void XRoot::removeEmptyLayers()
{
	if (!layers.empty())
	{
		for (int i = layers.size() - 1; i >= 0; i--)
		{
			if (layers[i].empty())
				layers.pop_back();
			else
				break;
		}
	}
}

// Only the root's own hidden flag gates traversal, not recursive isVisible().
// The qualified base calls traverse subconsoles via their virtual update/render;
// these methods neither iterate layers nor filter individual hidden children.
void XRoot::update()
{
	if (isHidden())
		return;
	XConsole::update();
}

void XRoot::render()
{
	if (isHidden())
		return;
	XConsole::render();
}


// Traverse layers back-to-front, retaining the first opaque cell and blending
// lower cells through its owner's foreground/background scales. Large-font
// subcells repeat source coordinates; default backgrounds are transparent.
// Frame stamps reset after 100000 to avoid carrying stale ownership forward.
void XRoot::composite()
{
	// NOTE: placeholder local names preserve VS2010's name-hashed stack order.
	Array2D<XCell> *buffer;
	int memberI;
	int layerIdx1;
	int tx;
	int offsetX;
	XRootCellRecord *entry;
	int offsetY4;
	int fontType9;
	XCell *rootCell7;
	int totalHeight;
	int subcell;
	XConsole *sub;
	XCell saved1;
	int startX;
	int sourceHeight;
	int width;
	int sourceX;
	int localY;
	int targetY;
	XConsole *lastOwner;
	int sy;
	int consoleWidth;
	width = getWidth();
	totalHeight = getHeight();

	frameCount++;
	if (frameCount > 100000)
	{
		for (tx = 0; tx < width; tx++)
		{
			for (targetY = 0; targetY < totalHeight; targetY++)
				(*records.get(tx,targetY))->frame = 0;
		}
		frameCount = 1;
	}
	for (layerIdx1 = layers.size() - 1; layerIdx1 >= 0; layerIdx1--)
	{
		for (memberI = layers[layerIdx1].size() - 1; memberI >= 0; memberI--)
		{
			if (layers[layerIdx1][memberI]->isVisible())
			{
				sub = layers[layerIdx1][memberI];
				if (sub->getVisibleArea(&startX,&sy,&offsetX,&offsetY4))
				{
					consoleWidth = sub->getWidth();
					sourceHeight = sub->getHeight();
					fontType9 = sub->fontType;
					buffer = &sub->buffer;
					for (localY = sy, targetY = offsetY4; localY < sourceHeight && targetY < totalHeight; localY++, targetY++)
					{
						if (targetY < 0)
						{
							localY--;
							continue;
						}
						for (sourceX = startX, tx = offsetX; sourceX < consoleWidth && tx < width; sourceX++, tx++)
						{
							if (tx < 0)
							{
								sourceX--;
								continue;
							}
							if (fontType9)
							{
								subcell = (tx - offsetX) % FONT_TYPE_WIDTH[fontType9];
								if (fontType9 >= 2 && (targetY - offsetY4) % 2)
									subcell += FONT_TYPE_WIDTH[fontType9];
							}
							else
								subcell = 0;
							if (buffer->get(sourceX,localY)->back == COLOR_DEFAULT_BACK)
							{
								if (fontType9 && (subcell == 0 || (subcell == 2 && fontType9 == 2) || subcell == 4))
									tx += FONT_TYPE_WIDTH[fontType9] - 1;
								continue;
							}
							entry = *records.get(tx,targetY);
							if (entry->frame != frameCount)
							{
								*this->buffer.get(tx,targetY) = *buffer->get(sourceX,localY);
								entry->owner = sub;
								entry->frame = frameCount;
								entry->subcell = subcell;
								entry->fontType = fontType9;
							}
							else if (entry->owner->isUnscaled())
								entry->owner = sub;
							else
							{
								saved1 = *this->buffer.get(tx,targetY);
								lastOwner = entry->owner;
								*this->buffer.get(tx,targetY) = *buffer->get(sourceX,localY);
								rootCell7 = this->buffer.get(tx,targetY);
								rootCell7->back.lerp(saved1.back,lastOwner->scaleY);
								if (saved1.ch == ' ')
								{
									rootCell7->fore.lerp(saved1.back,lastOwner->scaleY);
									if (rootCell7->ch != ' ')
									{
										entry->subcell = subcell;
										entry->fontType = fontType9;
									}
								}
								else
								{
									if (rootCell7->ch == ' ')
									{
										rootCell7->font = saved1.font;
										rootCell7->ch = saved1.ch;
										rootCell7->glyph = saved1.glyph;
										rootCell7->fore = XColor::lerp(rootCell7->back,saved1.fore,lastOwner->scaleX);
									}
									else if (rootCell7->ch == saved1.ch && rootCell7->font == saved1.font)
										rootCell7->fore.lerp(saved1.fore,lastOwner->scaleX);
									else if (lastOwner->scaleX < 0.5)
									{
										rootCell7->fore.lerp(rootCell7->back,lastOwner->scaleX * 2);
										entry->subcell = subcell;
										entry->fontType = fontType9;
									}
									else
									{
										rootCell7->font = saved1.font;
										rootCell7->ch = saved1.ch;
										rootCell7->glyph = saved1.glyph;
										rootCell7->fore = XColor::lerp(rootCell7->back,saved1.fore,(lastOwner->scaleX - 0.5) * 2);
									}
								}
								*this->buffer.get(tx,targetY) = *rootCell7;
								entry->owner = sub;
							}
							if (fontType9 && subcell % FONT_TYPE_WIDTH[fontType9] < FONT_TYPE_WIDTH[fontType9] - 1)
								sourceX--;
						}
						if (fontType9 >= 2 && (targetY - offsetY4) % 2 == 0)
							localY--;
					}
				}
			}
		}
	}
}
