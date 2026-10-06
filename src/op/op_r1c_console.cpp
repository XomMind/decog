// op_r1c_console: XStartupProgress and other XConsole subclasses in 0x42a3c0-0x434ad0, Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Pos
{
	int x;
	int y;
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor operator*(float value);
};

struct XEvent;

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool isActive();
	virtual void refresh();
	virtual bool input(XEvent *event) = 0;
	virtual void mouseMoved(int x, int y);
	virtual void update() = 0;
	virtual void render() = 0;

	int getWidth();
	int getHeight();
	void setFore(XColor color);
	void clearRow(int x, int y, int width);
	void print(int x, int y, const string &text);

	char pad04[0x60 - 0x04];
};

class REX
{
public:
	void renderRoot();	// 0x426c00
};
extern REX rex;	// 0xd223f0

//==================================================================
// XStartupProgress
//==================================================================

class XStartupProgress : public XConsole
{
public:
	virtual ~XStartupProgress();
	virtual bool input(XEvent *event);
	virtual void update();
	virtual void render();

	void addLine(const string &line, bool draw);	// 0x42e610, NOTE: placeholder name

	XColor color;
	Pos range;
	float progress;
	vector<string> lines;	// NOTE: placeholder name
};

void XStartupProgress::addLine(const string &line, bool draw)
{
	int i = 0;
	int y = getHeight() - 1;
	for (; i < lines.size(); i++, y--)
		clearRow(0,y,getWidth());
	lines.push_back(line);
	while (lines.size() > getHeight())
		lines.erase(lines.begin());
	for (int li = lines.size() - 1, row = getHeight() - 1, fade = 0; li >= 0; li--, row--, fade++)
	{
		if (progress != 0)
		{
			if (fade > range.y)
			{
				break;
			}
			else
			{
				if (fade <= range.x)
					setFore(color);
				else
					setFore(color * (1 - (fade - range.x) * progress));
			}
		}
		print(0,row,lines[li]);
	}
	if (draw)
		rex.renderRoot();
}
