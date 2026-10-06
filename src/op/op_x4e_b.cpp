// op_x4e_b: CMapModeLabel::unknown7f48e0 (0x7f48e0) of COGMIND.exe (Beta 17.1). Names are placeholders unless stated.
#include <string>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	static XColor addAlpha(XColor a, XColor b, float alpha);	// 0x4137b0
};

class XConsole
{
public:
	virtual ~XConsole();

	int getWidth();
	void printAligned(int x, int y, int align, const string &text);	// NOTE: placeholder name
	void setFore(XColor color) throw();
	void setBack(int x, int y, int width, int height, XColor color);
	void setCharRow_4183a0(int x, int y, int width);	// NOTE: placeholder name

	char pad04[0x6c - 0x04];
};

class CAllies	// NOTE: partial
{
public:
	bool getField_48f0a0();	// NOTE: placeholder name (folded getter)
};

class CMap	// NOTE: partial
{
public:
	int getField_49b550();	// NOTE: placeholder name (folded getter)
};

class OpX4e_ModeHolder	// NOTE: placeholder name (folded getter 0x4ab670)
{
public:
	int getMode_4ab670();	// NOTE: placeholder name
};

class CMapModeLabel : public XConsole
{
public:
	void unknown7f48e0();	// NOTE: placeholder name

	int mode;	// NOTE: placeholder name
};

float opR1d_4371a0(float a, float b, int period, int offset);	// NOTE: placeholder name

extern XColor *opX4e_colorD01720;	// NOTE: placeholder name
extern XColor opX4e_colorD29804;	// NOTE: placeholder name
extern XColor *opX4e_colorD20cfc;	// NOTE: placeholder name
extern XColor *opX4e_colorD35be0;	// NOTE: placeholder name
extern float opX4e_ba6c10;	// NOTE: placeholder name (0.0f)
extern int opX4e_d01a1c;	// NOTE: placeholder name
extern int opX4e_cebd5c;	// NOTE: placeholder name
extern CAllies *opX4e_allies;	// NOTE: placeholder name (0xcec0c8)
extern CMap *opX4e_mapView;	// NOTE: placeholder name (0xcec054)
extern OpX4e_ModeHolder *opX4e_cec098;	// NOTE: placeholder name
extern OpX4e_ModeHolder *opX4e_cec0a0;	// NOTE: placeholder name (CItemTag)
extern void *opX4e_cec10c;	// NOTE: placeholder name
extern string opX4e_labelCategories_d2aca8[];	// NOTE: placeholder name

void CMapModeLabel::unknown7f48e0()
{
	XColor color = XColor::addAlpha(opX4e_colorD29804,*opX4e_colorD01720,opR1d_4371a0(opX4e_ba6c10,0.35f,2000,0));
	int split = getWidth();
	if (opX4e_cebd5c == 2)
	{
		if ((mode == 0 && opX4e_allies->getField_48f0a0()) || mode == 2)
		{
			split = opX4e_d01a1c / 2;
			setBack(split,0,getWidth() - split,1,*opX4e_colorD20cfc);
		}
	}
	setCharRow_4183a0(0,0,split);
	setBack(0,0,split,1,color);
	setFore(*opX4e_colorD35be0);
	switch (mode)
	{
	case 0: printAligned(split / 2,0,1,"Order Mode (o)"); break;
	case 1: printAligned(split / 2,0,1,"Comment Mode (c/r or LMB/RMB to add/remove)"); break;
	case 2: printAligned(split / 2,0,1,"Map Intel Mode (m)"); break;
	case 3: printAligned(split / 2,0,1,"Swap Mode (/)"); break;
	case 4: printAligned(split / 2,0,1,"Drop Mode (d)"); break;
	case 5:
		{
			string text;
			switch (opX4e_cec098->getMode_4ab670())
			{
			case 1: text = "(t)oggle, (a)ttach, (i)nfo, (r)emove, (d)rop"; break;
			case 2: text = "Toggle Mode, select a~z"; break;
			case 3: text = "Attach Mode, select 1~0"; break;
			case 4: text = "Info Mode, select a~z/1~0"; break;
			case 5: text = "Remove Mode, select a~z"; break;
			case 6: text = "Drop Mode, select a~z/1~0"; break;
			}
			printAligned(split / 2,0,1,text);
		}
		break;
	case 6: printAligned(split / 2,0,1,"Mapshift Mode (accent)"); break;
	case 7:
		if (opX4e_cec0a0->getMode_4ab670() == 0)
			printAligned(split / 2,0,1,opX4e_cec10c ? "Tag Mode" : "Tag Mode (select inventory item with 0~1 or LMB)");
		else
			printAligned(split / 2,0,1,"Log Note Mode");
		break;
	case 8:
		printAligned(split / 2,0,1,"Label Category: " + opX4e_labelCategories_d2aca8[opX4e_mapView->getField_49b550()] + " (Tab, -/=, KP+/-)");
		break;
	}
}
