// team_d_111: blended tile render 0x50f530 (caller OpR2b_Engine::render; the class of team_d_61's blend helpers):
// blends the tile's foreground/background colors into its console cell, taking the source colors either from
// the definition (optionally scaled by the tile's alpha) or, for modes 15+, from one of the owner's layers.
// NOTE: class layouts are partial; names are placeholders.
// NOTE: the screen y local is named y1 for its stack-slot hash order.
#include <vector>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &c);
	XColor &operator=(XColor c);
	static XColor scale(XColor a, float value);
};
extern XColor col111_d349ec;	// NOTE: placeholder name (blend result, see team_d_61)

struct Point
{
	int x;
	int y;
};

class XCell
{
public:
	XColor *getFore();
	XColor *getBack();
};

class Layer111	// NOTE: placeholder name (OpX5_Array2D<OpX5_S14>)
{
public:
	XCell *atPoint(Point &p);
};

class XConsole
{
public:
	void setChar_417f50(int x, int y, int c);	// NOTE: placeholder name
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	void setBack_417fc0(int x, int y, XColor color, int mode);	// NOTE: placeholder name
	XColor getFore(int x, int y);
	XColor getBack(int x, int y);
};

class Engine111 : public XConsole	// NOTE: placeholder name and layout
{
public:
	char				pad00[0x6c];
	vector<Layer111 *>	layers;		// +0x6c
};

struct Owner111	// NOTE: placeholder name and layout
{
	Engine111	*console;	// +0x00
	char		pad04[8];
	Point		offset;		// +0x0c
};

struct AlphaMode111	// NOTE: placeholder name (see team_d_61)
{
	int		blend;
};

struct TileDef111	// NOTE: placeholder name and layout
{
	char			pad00[0x48];
	int				drawChar;	// +0x48
	char			pad4c[0x60 - 0x4c];
	AlphaMode111	foreMode;	// +0x60
	XColor			fore1;		// +0x64
	char			pad67[0x74 - 0x67];
	AlphaMode111	backMode;	// +0x74
	XColor			back1;		// +0x78
	char			pad7b[0x88 - 0x7b];
	AlphaMode111	foreBlend;	// +0x88
	XColor			fore2;		// +0x8c
	char			pad8f[0x9c - 0x8f];
	AlphaMode111	backBlend;	// +0x9c
	XColor			back2;		// +0xa0
	char			pada3[0xb0 - 0xa3];
	bool			fullFore;	// +0xb0
};

class Blender111	// NOTE: placeholder name and layout (Blender61's class)
{
public:
	TileDef111	*def;		// +0x00
	Owner111	*owner;		// +0x04
	int			active;		// +0x08
	char		pad0c[4];
	Point		pos;		// +0x10
	char		pad18[0x34 - 0x18];
	float		strength;	// +0x34
	char		pad38[0x68 - 0x38];
	Point		pos68;		// +0x68
	char		pad70[0x78 - 0x70];
	int			alpha;		// +0x78
	int			glyph;		// +0x7c

	void unknown509530(const XColor &back, AlphaMode111 *mode, const XColor &fore);	// NOTE: placeholder name
	void render();	// NOTE: placeholder name
};

void Blender111::render()
{
	if (active == 0)
		return;
	if (strength < 0.0)
		return;
	int x = pos.x + owner->offset.x;
	int y1 = pos.y + owner->offset.y;
	if (def->drawChar)
		owner->console->setChar_417f50(x,y1,glyph);
	if (def->foreMode.blend >= 15)
	{
		if ((def->foreMode.blend - 15) / 4 % 2 == 0)
			col111_d349ec = *owner->console->layers[(def->foreMode.blend - 15) % 4]->atPoint(def->foreMode.blend <= 0x16 ? pos : pos68)->getFore();
		else
			col111_d349ec = *owner->console->layers[(def->foreMode.blend - 15) % 4]->atPoint(def->foreMode.blend <= 0x16 ? pos : pos68)->getBack();
		unknown509530(col111_d349ec,&def->foreBlend,def->fore2);
	}
	else
	{
		if (def->fullFore)
			unknown509530(def->fore1,&def->foreBlend,def->fore2);
		else
			unknown509530(XColor::scale(def->fore1,alpha / 9.0),&def->foreBlend,XColor::scale(def->fore2,alpha / 9.0));
		unknown509530(owner->console->getFore(x,y1),&def->foreMode,col111_d349ec);
	}
	owner->console->setFore_417f80(x,y1,col111_d349ec);
	if (def->backMode.blend >= 15)
	{
		if ((def->backMode.blend - 15) / 4 % 2 == 0)
			col111_d349ec = *owner->console->layers[(def->backMode.blend - 15) % 4]->atPoint(def->backMode.blend <= 0x16 ? pos : pos68)->getFore();
		else
			col111_d349ec = *owner->console->layers[(def->backMode.blend - 15) % 4]->atPoint(def->backMode.blend <= 0x16 ? pos : pos68)->getBack();
		unknown509530(col111_d349ec,&def->backBlend,def->back2);
	}
	else
	{
		unknown509530(XColor::scale(def->back1,alpha / 9.0),&def->backBlend,XColor::scale(def->back2,alpha / 9.0));
		unknown509530(owner->console->getBack(x,y1),&def->backMode,col111_d349ec);
	}
	owner->console->setBack_417fc0(x,y1,col111_d349ec,1);
}
