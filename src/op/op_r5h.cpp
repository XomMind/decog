// op_r5h: CEnding map-area flood fill (0x998590), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
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

	XColor(const XColor &color) throw();
	bool operator!=(XColor color);
};

struct XCell
{
	XColor *getBack();
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);
	void getAdjacent(const Point &p, vector<Point> &adjacent);	// NOTE: placeholder name (0x9ce500)
	int getWidth();
	int getHeight();
};

class OpR5h_IntGrid	// NOTE: placeholder name (Array2D<int>)
{
public:
	OpR5h_IntGrid(int width, int height, int value);	// NOTE: placeholder name (0x9ced10)
	~OpR5h_IntGrid();	// NOTE: placeholder name (0x9cec20)

	int &operator()(const Point &p);	// NOTE: placeholder name (0x9ced70)

	int pad[3];
};

class OpR5h_AsciiImage
{
public:
	vector<Array2D<XCell>*> layers;
};

class OpR5h_ConsoleArt	// NOTE: placeholder name (ConsoleArt)
{
public:
	void unknown48c460(int anim, const Point &pos);	// NOTE: placeholder name

	char pad[0x6c];
	OpR5h_AsciiImage image;
};

class CEnding
{
public:
	void unknown998590(Point p);	// NOTE: placeholder name

	char pad[0x1a8];
	OpR5h_ConsoleArt *unknown1a8;	// NOTE: placeholder name
};

extern XColor *opr5h_cfe674;	// NOTE: placeholder name
extern XColor *opr5h_d20cfc;	// NOTE: placeholder name
bool opr5h_findAnimation_9d45a0(const string &name, int *index);	// NOTE: placeholder name
void opr5h_erasePoints_9d53f0(vector<Point> &v, int from, int to);	// NOTE: placeholder name

void CEnding::unknown998590(Point p)
{
	int animation;
	opr5h_findAnimation_9d45a0("Warlord_Map_Area",&animation);
	Array2D<XCell> *layer = unknown1a8->image.layers[2];
	OpR5h_IntGrid done(layer->getWidth(),layer->getHeight(),0);
	vector<Point> queue;
	vector<Point> next;
	int size;
	queue.push_back(p);
	done(queue[0]) = 1;
	unknown1a8->unknown48c460(animation,queue[0]);
	do
	{
		size = queue.size();
		for (int i = 0; i < size; i++)
		{
			vector<Point> adjacent;
			layer->getAdjacent(queue[i],adjacent);
			for (unsigned int j = 0; j < adjacent.size(); j++)
			{
				if (done(adjacent[j]) == 0 && (*(*layer)(adjacent[j]).getBack()) != *opr5h_cfe674 && (*(*layer)(adjacent[j]).getBack()) != *opr5h_d20cfc)
				{
					queue.push_back(adjacent[j]);
					done(adjacent[j]) = 1;
					unknown1a8->unknown48c460(animation,adjacent[j]);
				}
			}
		}
		if (size != 0)
			opr5h_erasePoints_9d53f0(queue,0,size - 1);
	} while (!queue.empty());
}
