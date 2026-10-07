// team_d_26: ASCII image layer copy (0x437d90).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
// The layer grid's default constructor is defined here with a placeholder body so that LTCG can prove
// it cannot throw, as in the exe (no exception state for the new-expression; its temporaries remain).
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

class LayerCell	// NOTE: placeholder name (OpU1_Cell)
{
public:
	void setFont(int font);
};

class LayerGrid	// NOTE: placeholder name (OpS7_CellGrid; default constructor folded with OpX5_Array2D's)
{
public:
	LayerGrid();
	LayerGrid &operator=(const LayerGrid &other);
	void resize(int width_, int height_);
	void copyFrom(int x, int y, LayerGrid &src, int srcX, int srcY, int w, int h);
	int getHeight();
	int getWidth();
	LayerCell *at(int x, int y);

	int width;
	int height;
	void *cells;
};

LayerGrid::LayerGrid()	// NOTE: placeholder body
{
	width = 0;
	height = 0;
	cells = 0;
}

class OpD_AsciiLayers	// NOTE: placeholder name (AsciiImage layer list)
{
public:
	bool unknown437d90(vector<LayerGrid *> &src, int font, Point *origin, int w, int h);	// NOTE: placeholder name

	vector<LayerGrid *> layers;	// NOTE: placeholder name
};

bool OpD_AsciiLayers::unknown437d90(vector<LayerGrid *> &src, int font, Point *origin, int w, int h)
{
	for (unsigned int i = 0; i < src.size(); i++)
	{
		layers.push_back(new LayerGrid);
		LayerGrid *grid = layers.back();
		if (origin->x == -1)
			*grid = *src[i];
		else
		{
			grid->resize(w,h);
			grid->copyFrom(0,0,*src[i],origin->x,origin->y,w,h);
		}
		for (int y = 0; y < grid->getHeight(); y++)
		{
			for (int x = 0; x < grid->getWidth(); x++)
				grid->at(x,y)->setFont(font);
		}
	}
	return true;
}
