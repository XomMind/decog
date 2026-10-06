#ifndef XROOT_H
#define XROOT_H

#include "engine/xconsole.h"

//==================================================================
// XRoot: the root console every other console hangs from (vtable @ 0xc2eeb0)
//==================================================================
// Layout (sizeof 0x84), names are placeholders:
//	+0x00	XConsole
//	+0x60	int frameCount			wraps after 100000 (0x42ded0)
//	+0x64	Array2D<XCell> lastFrame	(type of the element not yet confirmed)
//	+0x70	vector<vector<XConsole*> > layers
//	+0x80	bool unknown80

class XRoot : public XConsole
{
public:
	XRoot(int width, int height);
	virtual ~XRoot();

	virtual bool input(XEvent *event);
	virtual void update();
	virtual void render();

	Array2D<XCell> *getBuffer() { return &buffer; };	// 0x4184d0
	Array2D<XCell> *getLastFrame() { return &lastFrame; };	// 0x418570

	bool addToLayer(XConsole *console, int layer);	// 0x42da30
	void removeFromLayer(XConsole *console);	// 0x42dcc0
	int getLayer(XConsole *console);	// 0x42dd70
	void removeEmptyLayers();	// 0x42de00

	int frameCount;
	Array2D<XCell> lastFrame;
	vector<vector<XConsole*> > layers;
	bool unknown80;
};

#endif // XROOT_H
