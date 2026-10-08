// team_d_59: explosion propagation (0x514ee0/0x515790 setup over the arc, 0x514950/0x515250 per-ray line walk;
// the 0x5157xx/0x5152xx pair is the fixed-damage variant).
// NOTE: names and layouts are placeholders.
struct Point
{
	int x;
	int y;

	Point();							// NOTE: placeholder name (0x453b40)
	Point(const Point &p) throw();		// 0x46ca50
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor (0x46ca50)
	bool operator==(const Point &p) const;	// 0x409b90
	void set(int x_, int y_);			// NOTE: placeholder name (0x40a010)
	void scale(int length);				// NOTE: placeholder name (0x40a300)
	Point add(const Point &p) const;	// NOTE: placeholder name (PushCoord::add)
};

struct FloatRange59	// NOTE: placeholder name
{
	float lo;
	float hi;

	FloatRange59(float lo_, float hi_);	// NOTE: placeholder name (0x40c490)
	bool contains(float v);				// NOTE: placeholder name (0x40c730)
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	void getBounds(const Point &p, int radius, Point *min, Point *max);	// NOTE: placeholder name (0x9b7a40)
	int getWidth();
	int getHeight();
	class Cell **at(int x, int y);	// NOTE: folded with OpX5_Array2D<int>::at
};
extern CellGrid cells_cfd44c;

class Cell
{
public:
	bool unknown45d480();	// NOTE: placeholder name
	void unknown670f90(int *value, float slope);	// NOTE: placeholder name
};

// NOTE: line-walk state kept in globals in the exe (0xd3c3a0-0xd3c3dc); placeholder names
extern int lineDX59_d3c3dc;
extern int lineDY59_d3c3d8;
extern int lineAX59_d3c3d4;
extern int lineAY59_d3c3d0;
extern int lineSX59_d3c3cc;
extern int lineSY59_d3c3c8;
extern int lineX59_d3c3c4;
extern int lineY59_d3c3c0;
extern float lineSlope59_d3c3bc;
extern int lineSteps59_d3c3b8;
extern int lineValue59_d3c3b4;
extern int lineFalloff59_d3c3b0;
extern int linePrev59_d3c3ac;
extern bool lineBlockable59_d3c3a8;
extern int lineErrA59_d3c3a4;
extern int lineErrB59_d3c3a0;	// NOTE: placeholder name
// NOTE: the fixed-damage line walk keeps its own copies (0xd3c330-0xd3c36c); placeholder names
extern int lineDX59_d3c36c;
extern int lineDY59_d3c368;
extern int lineAX59_d3c364;
extern int lineAY59_d3c360;
extern int lineSX59_d3c35c;
extern int lineSY59_d3c358;
extern int lineX59_d3c354;
extern int lineY59_d3c350;
extern float lineSlope59_d3c34c;
extern int lineSteps59_d3c348;
extern int lineValue59_d3c344;
extern int lineFalloff59_d3c340;
extern int linePrev59_d3c33c;
extern bool lineBlockable59_d3c338;
extern int lineErrA59_d3c334;
extern int lineErrB59_d3c330;

class IntView59	// NOTE: placeholder name
{
public:
	void init(int w, int h, int fill);				// NOTE: placeholder name (0x9cffc0)
	void resizeView(int x, int y, int w, int h, bool clear);	// NOTE: placeholder name (0x9d0050)
	int &operator()(const Point &p);				// 0x9cfd90
	int &operator()(int x, int y);
};

struct ExplosionRec59	// NOTE: placeholder name and layout
{
	char	pad00[0x34];
	int		unknown34;	// NOTE: placeholder name (falloff variance)
	int		falloff;	// +0x38
	int		radius;		// +0x3c
	int		arc;		// +0x40
	char	pad44[0x54 - 0x44];
	bool	unknown54;	// NOTE: placeholder name
};

class RNG
{
public:
	int rangeInt(float low, float high);
};
extern RNG rng;

float OpY1_angle(int x1, int y1, int x2, int y2);	// NOTE: placeholder name
float angleBetween_40a680(const Point &a, const Point &b);	// NOTE: placeholder name
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
int OpX5_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)
#include <stdlib.h>

class Blast59	// NOTE: placeholder name
{
public:
	ExplosionRec59	*rec;		// +0x00
	int				damage;		// +0x04
	Point			origin;		// +0x08
	Point			target;		// +0x10
	Point			alt;		// +0x18
	IntView59		view;		// +0x20

	void unknown514950(int ox, int oy, int x, int y);	// NOTE: placeholder name
	void unknown514ee0();	// NOTE: placeholder name
	void unknown515250(int ox, int oy, int x, int y);	// NOTE: placeholder name (line walk without damage variance)
	void unknown515790();	// NOTE: placeholder name (setup without damage variance)
};

void Blast59::unknown514ee0()
{
	Point point;
	Point value;
	cells_cfd44c.getBounds(origin,rec->radius,&point,&value);
	view.init(cells_cfd44c.getWidth(),cells_cfd44c.getHeight(),0);
	view.resizeView(point.x,point.y,value.x - point.x + 1,value.y - point.y + 1,true);
	if (rec->arc && target.x != -1)
	{
		if (origin == target)
			origin = alt;
		Point vec;
		float closest;
		vec.set(origin.x - target.x,origin.y - target.y);
		vec.scale(0x32);
		Point pt = origin.add(vec);
		float current = angleBetween_40a680(origin,pt);
		FloatRange59 area(current - rec->arc / 2,current + rec->arc / 2);
		float mode = 0;
		if (area.lo < 0.0)
			mode = -area.lo;
		else if (area.hi > 360.0)
			mode = 360.0 - area.hi;
		if (mode != 0)
		{
			area.lo += mode;
			area.hi += mode;
		}
		for (int x = point.x; x <= value.x; x++)
		{
			for (int y = point.y; y <= value.y; y++)
			{
				closest = OpY1_angle(origin.x,origin.y,x,y) + mode;
				if (closest < 0.0)
					closest += 360.0;
				else if (closest > 360.0)
					closest -= 360.0;
				if (area.contains(closest))
					unknown514950(origin.x,origin.y,x,y);
			}
		}
	}
	else
	{
		for (int x2 = point.x; x2 <= value.x; x2++)
		{
			for (int y2 = point.y; y2 <= value.y; y2++)
				unknown514950(origin.x,origin.y,x2,y2);
		}
	}
	view(origin) = rec->unknown34 ? OpX5_maxInt(0,rng.rangeInt((float)-rec->unknown34,(float)rec->unknown34) + damage) : damage;
}

void Blast59::unknown514950(int x0, int y0, int x1, int y1)
{
	lineDX59_d3c3dc = x1 - x0;
	lineDY59_d3c3d8 = y1 - y0;
	lineAX59_d3c3d4 = (lineDX59_d3c3dc < 0 ? -lineDX59_d3c3dc : lineDX59_d3c3dc) << 1;
	lineAY59_d3c3d0 = (lineDY59_d3c3d8 < 0 ? -lineDY59_d3c3d8 : lineDY59_d3c3d8) << 1;
	lineSX59_d3c3cc = lineDX59_d3c3dc < 0 ? -1 : lineDX59_d3c3dc > 0;
	lineSY59_d3c3c8 = lineDY59_d3c3d8 < 0 ? -1 : lineDY59_d3c3d8 > 0;
	lineX59_d3c3c4 = x0;
	lineY59_d3c3c0 = y0;
	lineSlope59_d3c3bc = OpX5_minInt(abs(lineDX59_d3c3dc),abs(lineDY59_d3c3d8)) == 0 ? 1.01 : (double)OpX5_minInt(abs(lineDX59_d3c3dc),abs(lineDY59_d3c3d8)) / OpX5_maxInt(abs(lineDX59_d3c3dc),abs(lineDY59_d3c3d8)) * 0.41f + 1.01f;
	lineSteps59_d3c3b8 = (int)((rec->radius + 1) / lineSlope59_d3c3bc);
	lineValue59_d3c3b4 = rec->unknown34 ? OpX5_maxInt(0,rng.rangeInt((float)-rec->unknown34,(float)rec->unknown34) + damage) : damage;
	lineFalloff59_d3c3b0 = rec->falloff;
	linePrev59_d3c3ac = lineValue59_d3c3b4;
	lineBlockable59_d3c3a8 = !rec->unknown54;
	if (lineAX59_d3c3d4 >= lineAY59_d3c3d0)
	{
		lineErrA59_d3c3a4 = lineAY59_d3c3d0 - (lineAX59_d3c3d4 >> 1);
		for (;;)
		{
			if (lineBlockable59_d3c3a8 && (*cells_cfd44c.at(lineX59_d3c3c4,lineY59_d3c3c0))->unknown45d480())
			{
				view(lineX59_d3c3c4,lineY59_d3c3c0) = OpX5_maxInt(view(lineX59_d3c3c4,lineY59_d3c3c0),linePrev59_d3c3ac);
				(*cells_cfd44c.at(lineX59_d3c3c4,lineY59_d3c3c0))->unknown670f90(&lineValue59_d3c3b4,lineSlope59_d3c3bc);
			}
			else
				view(lineX59_d3c3c4,lineY59_d3c3c0) = OpX5_maxInt(view(lineX59_d3c3c4,lineY59_d3c3c0),lineValue59_d3c3b4);
			linePrev59_d3c3ac = lineValue59_d3c3b4;
			lineSteps59_d3c3b8--;
			lineValue59_d3c3b4 -= lineFalloff59_d3c3b0;
			if (lineSteps59_d3c3b8 < 0)
				return;
			if (lineValue59_d3c3b4 <= 0)
				return;
			if (lineX59_d3c3c4 == x1)
				return;
			if (lineErrA59_d3c3a4 >= 0)
			{
				lineY59_d3c3c0 += lineSY59_d3c3c8;
				lineErrA59_d3c3a4 -= lineAX59_d3c3d4;
			}
			lineX59_d3c3c4 += lineSX59_d3c3cc;
			lineErrA59_d3c3a4 += lineAY59_d3c3d0;
		}
	}
	else
	{
		lineErrB59_d3c3a0 = lineAX59_d3c3d4 - (lineAY59_d3c3d0 >> 1);
		for (;;)
		{
			if (lineBlockable59_d3c3a8 && (*cells_cfd44c.at(lineX59_d3c3c4,lineY59_d3c3c0))->unknown45d480())
			{
				view(lineX59_d3c3c4,lineY59_d3c3c0) = OpX5_maxInt(view(lineX59_d3c3c4,lineY59_d3c3c0),linePrev59_d3c3ac);
				(*cells_cfd44c.at(lineX59_d3c3c4,lineY59_d3c3c0))->unknown670f90(&lineValue59_d3c3b4,lineSlope59_d3c3bc);
			}
			else
				view(lineX59_d3c3c4,lineY59_d3c3c0) = OpX5_maxInt(view(lineX59_d3c3c4,lineY59_d3c3c0),lineValue59_d3c3b4);
			linePrev59_d3c3ac = lineValue59_d3c3b4;
			lineSteps59_d3c3b8--;
			lineValue59_d3c3b4 -= lineFalloff59_d3c3b0;
			if (lineSteps59_d3c3b8 < 0)
				return;
			if (lineValue59_d3c3b4 <= 0)
				return;
			if (lineY59_d3c3c0 == y1)
				return;
			if (lineErrB59_d3c3a0 >= 0)
			{
				lineX59_d3c3c4 += lineSX59_d3c3cc;
				lineErrB59_d3c3a0 -= lineAY59_d3c3d0;
			}
			lineY59_d3c3c0 += lineSY59_d3c3c8;
			lineErrB59_d3c3a0 += lineAX59_d3c3d4;
		}
	}
}

void Blast59::unknown515790()
{
	Point point;
	Point value;
	cells_cfd44c.getBounds(origin,rec->radius,&point,&value);
	view.init(cells_cfd44c.getWidth(),cells_cfd44c.getHeight(),0);
	view.resizeView(point.x,point.y,value.x - point.x + 1,value.y - point.y + 1,true);
	if (rec->arc && target.x != -1)
	{
		if (origin == target)
			origin = alt;
		Point vec;
		float closest;
		vec.set(origin.x - target.x,origin.y - target.y);
		vec.scale(0x32);
		Point pt = origin.add(vec);
		float current = angleBetween_40a680(origin,pt);
		FloatRange59 area(current - rec->arc / 2,current + rec->arc / 2);
		float mode = 0;
		if (area.lo < 0.0)
			mode = -area.lo;
		else if (area.hi > 360.0)
			mode = 360.0 - area.hi;
		if (mode != 0)
		{
			area.lo += mode;
			area.hi += mode;
		}
		for (int x = point.x; x <= value.x; x++)
		{
			for (int y = point.y; y <= value.y; y++)
			{
				closest = OpY1_angle(origin.x,origin.y,x,y) + mode;
				if (closest < 0.0)
					closest += 360.0;
				else if (closest > 360.0)
					closest -= 360.0;
				if (area.contains(closest))
					unknown514950(origin.x,origin.y,x,y);
			}
		}
	}
	else
	{
		for (int x2 = point.x; x2 <= value.x; x2++)
		{
			for (int y2 = point.y; y2 <= value.y; y2++)
				unknown515250(origin.x,origin.y,x2,y2);
		}
	}
	view(origin) = damage;
}

void Blast59::unknown515250(int x0, int y0, int x1, int y1)
{
	lineDX59_d3c36c = x1 - x0;
	lineDY59_d3c368 = y1 - y0;
	lineAX59_d3c364 = (lineDX59_d3c36c < 0 ? -lineDX59_d3c36c : lineDX59_d3c36c) << 1;
	lineAY59_d3c360 = (lineDY59_d3c368 < 0 ? -lineDY59_d3c368 : lineDY59_d3c368) << 1;
	lineSX59_d3c35c = lineDX59_d3c36c < 0 ? -1 : lineDX59_d3c36c > 0;
	lineSY59_d3c358 = lineDY59_d3c368 < 0 ? -1 : lineDY59_d3c368 > 0;
	lineX59_d3c354 = x0;
	lineY59_d3c350 = y0;
	lineSlope59_d3c34c = OpX5_minInt(abs(lineDX59_d3c36c),abs(lineDY59_d3c368)) == 0 ? 1.01 : (double)OpX5_minInt(abs(lineDX59_d3c36c),abs(lineDY59_d3c368)) / OpX5_maxInt(abs(lineDX59_d3c36c),abs(lineDY59_d3c368)) * 0.41f + 1.01f;
	lineSteps59_d3c348 = (int)((rec->radius + 1) / lineSlope59_d3c34c);
	lineValue59_d3c344 = damage;
	lineFalloff59_d3c340 = rec->falloff;
	linePrev59_d3c33c = lineValue59_d3c344;
	lineBlockable59_d3c338 = !rec->unknown54;
	if (lineAX59_d3c364 >= lineAY59_d3c360)
	{
		lineErrA59_d3c334 = lineAY59_d3c360 - (lineAX59_d3c364 >> 1);
		for (;;)
		{
			if (lineBlockable59_d3c338 && (*cells_cfd44c.at(lineX59_d3c354,lineY59_d3c350))->unknown45d480())
			{
				view(lineX59_d3c354,lineY59_d3c350) = OpX5_maxInt(view(lineX59_d3c354,lineY59_d3c350),linePrev59_d3c33c);
				(*cells_cfd44c.at(lineX59_d3c354,lineY59_d3c350))->unknown670f90(&lineValue59_d3c344,lineSlope59_d3c34c);
			}
			else
				view(lineX59_d3c354,lineY59_d3c350) = OpX5_maxInt(view(lineX59_d3c354,lineY59_d3c350),lineValue59_d3c344);
			linePrev59_d3c33c = lineValue59_d3c344;
			lineSteps59_d3c348--;
			lineValue59_d3c344 -= lineFalloff59_d3c340;
			if (lineSteps59_d3c348 < 0)
				return;
			if (lineValue59_d3c344 <= 0)
				return;
			if (lineX59_d3c354 == x1)
				return;
			if (lineErrA59_d3c334 >= 0)
			{
				lineY59_d3c350 += lineSY59_d3c358;
				lineErrA59_d3c334 -= lineAX59_d3c364;
			}
			lineX59_d3c354 += lineSX59_d3c35c;
			lineErrA59_d3c334 += lineAY59_d3c360;
		}
	}
	else
	{
		lineErrB59_d3c330 = lineAX59_d3c364 - (lineAY59_d3c360 >> 1);
		for (;;)
		{
			if (lineBlockable59_d3c338 && (*cells_cfd44c.at(lineX59_d3c354,lineY59_d3c350))->unknown45d480())
			{
				view(lineX59_d3c354,lineY59_d3c350) = OpX5_maxInt(view(lineX59_d3c354,lineY59_d3c350),linePrev59_d3c33c);
				(*cells_cfd44c.at(lineX59_d3c354,lineY59_d3c350))->unknown670f90(&lineValue59_d3c344,lineSlope59_d3c34c);
			}
			else
				view(lineX59_d3c354,lineY59_d3c350) = OpX5_maxInt(view(lineX59_d3c354,lineY59_d3c350),lineValue59_d3c344);
			linePrev59_d3c33c = lineValue59_d3c344;
			lineSteps59_d3c348--;
			lineValue59_d3c344 -= lineFalloff59_d3c340;
			if (lineSteps59_d3c348 < 0)
				return;
			if (lineValue59_d3c344 <= 0)
				return;
			if (lineY59_d3c350 == y1)
				return;
			if (lineErrB59_d3c330 >= 0)
			{
				lineX59_d3c354 += lineSX59_d3c35c;
				lineErrB59_d3c330 -= lineAY59_d3c360;
			}
			lineY59_d3c350 += lineSY59_d3c358;
			lineErrB59_d3c330 += lineAX59_d3c364;
		}
	}
}
