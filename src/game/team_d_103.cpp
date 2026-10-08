// team_d_103: effect-tile draw 0x508360 (caller OpR2b_EffectMgr::unknown5088e0): blends the effect's
// foreground/background colors into the map console cell under it (same class as team_d_68's blend helpers).
// NOTE: class layouts are partial; names are placeholders. The local names x/pt/y1 follow the stack-slot
// hash order.
struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &c);
	static XColor scale(XColor a, float value);
};
extern XColor col103_d02364;	// NOTE: placeholder name (blend result, see team_d_68)

struct Point
{
	int x;
	int y;
};

class XConsole
{
public:
	const Point &unknown458ef0();	// NOTE: placeholder name (folded getter)
	void setChar_417f50(int x, int y, int c);	// NOTE: placeholder name
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	void setBack_417fc0(int x, int y, XColor color, int mode);	// NOTE: placeholder name
	XColor getFore(int x, int y);
	XColor getBack(int x, int y);
};
extern XConsole *mapConsole103_cec054;	// NOTE: placeholder name
extern int screenWidth103_cf27f4;	// NOTE: placeholder name
extern int screenHeight103_cf27f8;	// NOTE: placeholder name

class BS
{
public:
	bool isVisible(const Point &p);
};
extern BS *world103_cefc4c;	// NOTE: placeholder name

struct AlphaMode103	// NOTE: placeholder name (see team_d_68)
{
	int		blend;
};

struct EffectDef103	// NOTE: placeholder name and layout
{
	char			pad00[0x48];
	int				drawChar;	// +0x48
	char			pad4c[0x64 - 0x4c];
	AlphaMode103	foreMode;	// +0x64
	XColor			fore1;		// +0x68
	char			pad6b[0x78 - 0x6b];
	AlphaMode103	backMode;	// +0x78
	XColor			back1;		// +0x7c
	char			pad7f[0x8c - 0x7f];
	AlphaMode103	foreBlend;	// +0x8c
	XColor			fore2;		// +0x90
	char			pad93[0xa0 - 0x93];
	AlphaMode103	backBlend;	// +0xa0
	XColor			back2;		// +0xa4
	char			pada7[0xb4 - 0xa7];
	bool			fullFore;	// +0xb4
};

class EffectTile103	// NOTE: placeholder name and layout (Blender68's class)
{
public:
	EffectDef103	*def;		// +0x00
	char			pad04[4];
	int				active;		// +0x08
	char			pad0c[4];
	Point			pos;		// +0x10
	char			pad18[0x34 - 0x18];
	float			strength;	// +0x34
	char			pad38[0x78 - 0x38];
	int				alpha;		// +0x78
	char			pad7c[0x88 - 0x7c];
	int				glyph;		// +0x88

	void unknown5019c0(const XColor &back, AlphaMode103 *mode, const XColor &fore);	// NOTE: placeholder name
	void unknown508360();	// NOTE: placeholder name
};

void EffectTile103::unknown508360()
{
	if (active == 0)
		return;
	if (strength < 0.0)
		return;
	if (!world103_cefc4c->isVisible(pos))
		return;
	const Point &pt = mapConsole103_cec054->unknown458ef0();
	int x = pos.x + pt.x;
	int y1 = pos.y + pt.y;
	if (x < 0 || x >= screenWidth103_cf27f4 || y1 < 0 || y1 >= screenHeight103_cf27f8)
		return;
	if (def->drawChar)
		mapConsole103_cec054->setChar_417f50(x,y1,glyph);
	if (def->fullFore)
		unknown5019c0(def->fore1,&def->foreBlend,def->fore2);
	else
		unknown5019c0(XColor::scale(def->fore1,alpha / 9.0),&def->foreBlend,XColor::scale(def->fore2,alpha / 9.0));
	unknown5019c0(mapConsole103_cec054->getFore(x,y1),&def->foreMode,col103_d02364);
	mapConsole103_cec054->setFore_417f80(x,y1,col103_d02364);
	unknown5019c0(XColor::scale(def->back1,alpha / 9.0),&def->backBlend,XColor::scale(def->back2,alpha / 9.0));
	unknown5019c0(mapConsole103_cec054->getBack(x,y1),&def->backMode,col103_d02364);
	mapConsole103_cec054->setBack_417fc0(x,y1,col103_d02364,1);
}
