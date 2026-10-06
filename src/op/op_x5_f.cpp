// op_x5_f: small console/grid helpers around 0x997000 and 0x9d3470 of COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../engine/xcolor.h"
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p);	// 0x46ca50
};

struct XEvent;	// NOTE: placeholder name

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(XEvent *event) = 0;
	virtual void inputKey(int key, int mode);	// NOTE: placeholder name
	virtual void update() = 0;
	virtual void render() = 0;	// NOTE: placeholder name

	bool isHidden();	// NOTE: placeholder name
};

//==================================================================
// CWorldMap (0xcec070): shown if hidden (0x997000)
//==================================================================

class OpX5F_WorldMap : public XConsole	// NOTE: placeholder name (CWorldMap)
{
public:
	virtual void open();	// NOTE: placeholder name (0x993810)
};
extern OpX5F_WorldMap *opx5f_cec070;	// NOTE: placeholder name (0xcec070)

void opx5f_openWorldMapIfHidden()	// NOTE: placeholder name (0x997000)
{
	if (opx5f_cec070->isHidden())
		opx5f_cec070->open();
}

//==================================================================
// 2D array of points (0x9d3470)
//==================================================================

class OpX5F_PointGrid	// NOTE: placeholder name
{
public:
	void resize(int width_, int height_);	// NOTE: placeholder name (0x9ed730)
	void fill(Point p);	// NOTE: placeholder name (0x9ed6e0)
	void resizeAndFill(int width_, int height_, Point p);	// NOTE: placeholder name (0x9d3470)

	int width;
	int height;
	Point *data;
};

void OpX5F_PointGrid::resizeAndFill(int width_, int height_, Point p)
{
	resize(width_,height_);
	fill(p);
}
