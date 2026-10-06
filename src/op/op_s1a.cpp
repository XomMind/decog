// op_s1a: functions in 0x409000-0x422000 matched against COGMIND.exe (Beta 17.1).
// NOTE: names are placeholders unless stated otherwise.
#include "../pathing/bresenham2d.h"

// fills cells with each cell the line passes through and steps with the number of subcell steps spent in each
bool OpS_traceSubcellLine(int x0, int y0, int x1, int y1, vector<Point> &cells, vector<int> &steps, int subcells)	// NOTE: placeholder name (0x4104f0)
{
	if (x0 < 0 || y0 < 0 || x1 < 0 || y1 < 0 || (x0 == x1 && y0 == y1))
		return false;

	Bresenham2DStepperSubcell stepper(Point(x0,y0),subcells / 2,Point(x1,y1),subcells / 2,subcells);
	Point current(x0,y0);
	Point end(x1,y1);
	cells.push_back(current);
	steps.push_back(1);
	Point cell;
	Point subPt;
	do
	{
		stepper.next(cell,subPt);
		if (cell != current)
		{
			cells.push_back(cell);
			current = cell;
			steps.push_back(1);
		}
		else
			steps.back()++;
	} while (current != end || steps.back() < subcells / 2);
	return true;
}

//==================================================================
// graph-like container with per-node adjacency lists (0x416060-0x416340)
//==================================================================

void OpS_fillBool(bool *values, unsigned int count, bool value);	// NOTE: placeholder name (0x9cdcc0)
extern bool OpS_flags_cec14c[4];	// NOTE: placeholder name (0xcec14c)
extern int OpS_indices_cec458[323];	// NOTE: placeholder name (0xcec458)

class OpS_Frame	// NOTE: placeholder name
{
public:
	vector<bool> marked;
	bool hasState;
	int unknown18;
	int unknown1c;
	int unknown20;
	int unknown24;
	int unknown28;
	int unknown2c;

	OpS_Frame(const vector<bool> &marked_, bool hasState_, int unknown18_, int unknown1c_, int unknown20_, int unknown24_, int unknown28_, int unknown2c_);
};

void OpS_deleteBack(vector<OpS_Frame*> &frames);	// NOTE: placeholder name (0x9cdcf0)

class OpS_Graph	// NOTE: placeholder name
{
public:
	vector< vector<unsigned int> > adjacency;
	vector<bool> visited;
	vector<bool> marked;
	bool unknown38;
	vector<OpS_Frame*> frames;
	int unknown4c;
	int unknown50;
	int unknown54;
	bool unknown58;
	int unknown5c;
	int unknown60;
	bool unknown64;
	int unknown68;
	int unknown6c;
	int unknown70;
	int unknown74;
	int unknown78;
	int unknown7c;
	vector<unsigned int> unknown80;
	vector<unsigned int> unknown90;

	OpS_Graph();
	unsigned int addNode();
	void setUnknown60(int value);	// NOTE: placeholder name (0x416770)
	void setUnknown68(int value);	// NOTE: placeholder name (0x452320)
	void pushFrame();
	void pushFrame(int index, int value, int other, bool flag);
	void setMarked(unsigned int index, bool marked);
	void clearMarked(bool skipFirst);
	void popFrame();
};

OpS_Graph::OpS_Graph()
	: unknown38(false)
	, unknown4c(0)
	, unknown50(0)
	, unknown54(-1)
	, unknown58(false)
	, unknown5c(0)
	, unknown60(0)
	, unknown64(false)
	, unknown68(0)
	, unknown6c(-1)
	, unknown70(-1)
	, unknown74(0)
	, unknown78(0)
	, unknown7c(0)
{
	OpS_fillBool(OpS_flags_cec14c,4,false);
	for (int i = 0; i < 323; i++)
		OpS_indices_cec458[i] = i;
	unsigned int value80 = 0;
	unknown80.assign(2,value80);
	unsigned int value90 = 0;
	unknown90.assign(2,value90);
}

unsigned int OpS_Graph::addNode()
{
	adjacency.push_back(vector<unsigned int>());
	visited.push_back(false);
	marked.push_back(false);
	return adjacency.size() - 1;
}

OpS_Frame::OpS_Frame(const vector<bool> &marked_, bool hasState_, int unknown18_, int unknown1c_, int unknown20_, int unknown24_, int unknown28_, int unknown2c_)
	: marked(marked_)
	, hasState(hasState_)
	, unknown18(unknown18_)
	, unknown1c(unknown1c_)
	, unknown20(unknown20_)
	, unknown24(unknown24_)
	, unknown28(unknown28_)
	, unknown2c(unknown2c_)
{
}

void OpS_Graph::pushFrame()
{
	frames.push_back(new OpS_Frame(visited,unknown4c != 0,unknown4c,unknown50,unknown54,unknown5c,unknown60,unknown68));
}

void OpS_Graph::setMarked(unsigned int index, bool marked_)
{
	visited[index] = marked_;
	if (marked_)
	{
		marked[index] = true;
		unknown38 = true;
	}
}

void OpS_Graph::clearMarked(bool skipFirst)
{
	for (unsigned int i = skipFirst != 0; i < adjacency.size(); i++)
		setMarked(i,false);
}

void OpS_Graph::pushFrame(int index, int value, int other, bool flag)
{
	frames.push_back(new OpS_Frame(visited,true,unknown4c,unknown50,unknown54,unknown5c,unknown60,unknown68));
	clearMarked(true);
	setMarked(index,true);
	setUnknown60(value);
	if (other != -1)
	{
		unknown50 = value;
		unknown54 = other;
	}
	else
		unknown50 = 0;
	setUnknown68(flag ? value : 0);
}

void OpS_Graph::popFrame()
{
	visited = frames.back()->marked;
	if (frames.back()->hasState)
		setUnknown60(frames.back()->unknown18);
	unknown50 = frames.back()->unknown1c;
	unknown54 = frames.back()->unknown20;
	unknown5c = frames.back()->unknown24;
	unknown60 = frames.back()->unknown28;
	unknown68 = frames.back()->unknown2c;
	OpS_deleteBack(frames);
}

//==================================================================
// character cell layout (0x416960-0x416aca)
//==================================================================

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor() throw();	// 0x411d40
};

extern const int OpS_sizes_b8cef8[];	// NOTE: placeholder name (0xb8cef8)

class OpS_Layout	// NOTE: placeholder name
{
public:
	int type;
	int width;
	int height;
	int unknownc;
	vector<int> cells;
	vector<int> unknown1c;
	vector< vector<XColor> > colors;
	vector< vector<bool> > flags;

	void resetAttributes();
	void setCell(int index, int x, int y);
	void setCells(int first, int last, int x, int y);
};

void OpS_Layout::resetAttributes()
{
	XColor color;
	vector<XColor> row(OpS_sizes_b8cef8[type],color);
	colors.assign(width * height,row);
	flags.assign(width * height,vector<bool>(OpS_sizes_b8cef8[type],true));
}

void OpS_Layout::setCell(int index, int x, int y)
{
	cells[index] = y * width + x;
}

void OpS_Layout::setCells(int first, int last, int x, int y)
{
	for (int i = first; i <= last; i++)
	{
		setCell(i,x,y);
		x++;
		if (x == width)
		{
			x = 0;
			y++;
		}
	}
}
