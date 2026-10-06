// op_x4b: functions in 0x6c1000-0x6c6000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	int right_40ac20() const;	// NOTE: placeholder name
	int bottom_40ac40() const;	// NOTE: placeholder name
};

class OpX4b_NoiseField	// NOTE: placeholder name
{
public:
	OpX4b_NoiseField();	// 0x421650
	~OpX4b_NoiseField();	// 0x421750
	void init(int dimensions, float scale, int seed_);	// 0x421680
	float sampleFbmXY(int x, int y);	// 0x421820
	float sampleFbm(const Point &pos);	// 0x421880
	void setOctaves(int octaves_);	// NOTE: placeholder name (0x450460)

	int field0;
	int field4;
	int field8;
	int fieldC;
	int field10;
	int field14;
	int field18;
	int field1c;
};

class OpX4b_Cell	// NOTE: placeholder name
{
public:
	void unknown66b700(int a, int b);	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	T &operator()(int x, int y);	// 0x9ceda0
	int ID;
};
extern Array2D<OpX4b_Cell *> opx4b_cells;	// NOTE: placeholder name (0xcfd44c)

class OpX4b_Terrain	// NOTE: placeholder name
{
public:
	void unknown6c38a0(Rect *rect, const vector<Point> *points, float threshold, int value);	// NOTE: placeholder name
};

void OpX4b_Terrain::unknown6c38a0(Rect *rect, const vector<Point> *points, float threshold, int value)
{
	float step;
	float noiseValue;
	if (threshold == 0.0f)
	{
	}
	else
	{
		OpX4b_NoiseField noise;
		noise.init(2,0.0f,0);
		noise.setOctaves(8);
		step = threshold / 17.0;
		if (rect)
		{
			for (int x = rect->x; x <= rect->right_40ac20(); x++)
			{
				for (int y = rect->y; y <= rect->bottom_40ac40(); y++)
				{
					noiseValue = noise.sampleFbmXY(x,y);
					if (noiseValue < threshold)
						opx4b_cells(x,y)->unknown66b700((int)(noiseValue / step),value);
				}
			}
		}
		else
		{
			for (unsigned int i = 0; i < points->size(); i++)
			{
				noiseValue = noise.sampleFbm((*points)[i]);
				if (noiseValue < threshold)
					opx4b_cells((*points)[i])->unknown66b700((int)(noiseValue / step),value);
			}
		}
	}
}
