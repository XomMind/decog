// team_b_53: CMap off-screen marker clamp (0x83d9b0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names (local names follow docs/local-name-buckets.txt).
struct Point { int x; int y; Point(); Point(const Point &p); };
struct TeamB_ViewArea { Point min; Point max; TeamB_ViewArea(); };	// NOTE: placeholder name (Area)
class XConsole { public: virtual ~XConsole(); int getHeight(); int getWidth_44b0d0();	/* NOTE: placeholder name */ };
class TeamB_CMapClamp : public XConsole	// NOTE: placeholder name (CMap)
{
public:
	char pad04[0x6c - 4];
	Point offset;
	void getViewBounds_8051f0(Point &min, Point &max);	// NOTE: placeholder name
	Point clampToView83d9b0(const Point &p);
};
Point TeamB_CMapClamp::clampToView83d9b0(const Point &p)	// 0x83d9b0
{
	int base = 2;
	TeamB_ViewArea area;
	getViewBounds_8051f0(area.min,area.max);
	Point pt;
	if (p.x < area.min.x)
	{
		pt.x = 2;
		goto vertical;
	}
	else if (p.x > area.max.x)
	{
		pt.x = getWidth_44b0d0() - 3;
vertical:
		if (p.y < area.min.y + 2)
			pt.y = 2;
		else if (p.y > area.max.y - 2)
			pt.y = getHeight() - 3;
		else
			pt.y = p.y + offset.y;
	}
	else if (p.y < area.min.y)
	{
		pt.y = 2;
		goto horizontal;
	}
	else
	{
		pt.y = getHeight() - 3;
horizontal:
		if (p.x < area.min.x + 2)
			pt.x = 2;
		else if (p.x > area.max.x - 2)
			pt.x = getWidth_44b0d0() - 3;
		else
			pt.x = p.x + offset.x;
	}

	return pt;
}
