// team_d_63: particle cell painter 0x50da50 (draw one particle cell's glyph, foreground and background).
// NOTE: names and layouts are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &c);
};

class FrameCell63	// NOTE: placeholder name (OpX5_S14)
{
public:
	int getChar();			// NOTE: placeholder name (folded getter)
	XColor *getFore();
	XColor *getBack();
};

class Frame63	// NOTE: placeholder name (OpX5_Array2D<OpX5_S14>)
{
public:
	FrameCell63 *atPoint(Point &p);
};

class XConsole63	// NOTE: placeholder name
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual void v9();
	virtual int getMode();	// NOTE: placeholder name (slot 10)

	void setChar_417f50(int x, int y, int ch);
	void setFore_417f80(int x, int y, XColor color);
	void setBack_417fc0(int x, int y, XColor color, int mode);

	char				pad04[0x6c - 0x04];
	vector<Frame63 *>	frames;	// +0x6c
};

struct Context63	// NOTE: placeholder name and layout
{
	XConsole63	*con;
	char		pad04[0x0c - 0x04];
	int			offX;	// +0x0c
	int			offY;	// +0x10
};

struct Particle63	// NOTE: placeholder name and layout
{
	char		pad00[0x48];
	int			frame;		// +0x48
	vector<int>	chars;		// +0x4c
	char		pad5c[0x60 - 0x5c];
	int			foreFrame;	// +0x60
	XColor		fore;		// +0x64
	char		pad67[0x74 - 0x67];
	int			backFrame;	// +0x74
	XColor		back;		// +0x78
	char		pad7b[0x8c - 0x7b];
	XColor		fore2;		// +0x8c
	char		pad8f[0xa0 - 0x8f];
	XColor		back2;		// +0xa0
	char		pada3[0xb4 - 0xa3];
	int			charMode;	// +0xb4
	int			ch;			// +0xb8
	int			foreMode;	// +0xbc
	XColor		fore3;		// +0xc0
	char		padc3[0xc4 - 0xc3];
	int			backMode;	// +0xc4
	XColor		back3;		// +0xc8
};

bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (in range)

class Painter63	// NOTE: placeholder name
{
public:
	Particle63	*particle;	// +0x00
	Context63	*ctx;		// +0x04
	char		pad08[0x20 - 0x08];
	Point		pos;		// +0x20

	void unknown50da50(Point &p);	// NOTE: placeholder name
};

void Painter63::unknown50da50(Point &p)
{
	int px = p.x + ctx->offX;
	int py = p.y + ctx->offY;
	if (particle->charMode)
	{
		switch (particle->charMode)
		{
		case 1:
			switch (particle->frame)
			{
			case 1:
				ctx->con->setChar_417f50(px,py,particle->chars.front());
				break;
			default:
				if (ctx->con->getMode() != 1)
					particle->charMode = 0;
				else if (particle->frame - 0xf >= ctx->con->frames.size())
					particle->charMode = 0;
				else
					ctx->con->setChar_417f50(px,py,ctx->con->frames[particle->frame - 0xf]->atPoint(pos)->getChar());
				break;
			}
			break;
		default:
			ctx->con->setChar_417f50(px,py,particle->ch);
			break;
		}
	}
	if (particle->foreMode)
	{
		switch (particle->foreMode)
		{
		case 1:
			if (OpT8b_Fn9daf80(0xf,particle->foreFrame,0x16))
				ctx->con->setFore_417f80(px,py,*ctx->con->frames[(particle->foreFrame - 0xf) % 4]->atPoint(p)->getFore());
			else
				ctx->con->setFore_417f80(px,py,particle->fore);
			break;
		case 2:
			ctx->con->setFore_417f80(px,py,particle->fore2);
			break;
		default:
			ctx->con->setFore_417f80(px,py,particle->fore3);
			break;
		}
	}
	if (particle->backMode)
	{
		switch (particle->backMode)
		{
		case 1:
			if (OpT8b_Fn9daf80(0xf,particle->backFrame,0x16))
				ctx->con->setBack_417fc0(px,py,*ctx->con->frames[(particle->backFrame - 0xf) % 4]->atPoint(p)->getBack(),1);
			else
				ctx->con->setBack_417fc0(px,py,particle->back,1);
			break;
		case 2:
			ctx->con->setBack_417fc0(px,py,particle->back2,1);
			break;
		default:
			ctx->con->setBack_417fc0(px,py,particle->back3,1);
			break;
		}
	}
}
