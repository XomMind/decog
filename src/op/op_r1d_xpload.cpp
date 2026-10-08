// op_r1d_xpload: AsciiImage::load (0x437580), reader for the game's obfuscated REXPaint (.x) art files
// (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts except where stated. Local names are chosen for their
// stack slots (kind = char mask, color = color mask, mode = version, num = layer count, tmp/tmp2 = size).
#include <string>
#include <vector>
#include "../util/rng.h"
#include "../thirdparty/zfstream.h"
using namespace std;

struct Pos
{
	int x;
	int y;
};

struct XColor;

class XCell
{
public:
	XCell(int font);	// 0x427ef0
	XCell(const XCell &cell) throw();
	void read(istream &in);	// 0x416e00
	int getChar_416f20();	// NOTE: placeholder name (folded trivial getter)
	void setChar(int c);	// 0x427fd0
	XColor *getFore();	// 0x416f40
	XColor *getBack();	// 0x416f60

	char pad00[0x14];
};

class OpR1dX_CellGrid	// NOTE: placeholder name (an image layer: 2D array of XCell)
{
public:
	OpR1dX_CellGrid();	// NOTE: folded ctor
	void resize(int width, int height, XCell fill);	// NOTE: placeholder name
	XCell *at(int x, int y);	// NOTE: placeholder name
	int getWidth();	// NOTE: placeholder name (folded getter)
	int getHeight();	// NOTE: placeholder name (folded getter)
	void contract(int left, int right, int top, int bottom);	// NOTE: placeholder name

	int width;
	int height;
	XCell *cells;
};

// Defined here with a trivial body so LTCG can prove the `new` below nothrow (no EH states, extra slot kept).
inline OpR1dX_CellGrid::OpR1dX_CellGrid() {}

class AsciiImage
{
public:
	bool load(const string &file, int font, Pos *offset, int width, int height);

	vector<OpR1dX_CellGrid *> layers;
};

template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name
template <class T> void removeVectorElement(vector<T> &v, T index);	// NOTE: placeholder name
void logNotice(string location, string message);	// 0x404d20
void opR1d_4369a0(XColor *color, int mask);	// NOTE: placeholder name
extern int opR1d_xpMask_caf5c8[][100][100];	// NOTE: placeholder name

bool AsciiImage::load(const string &file, int font, Pos *offset, int width, int height)
{
	gzifstream in((file + ".x").c_str(),ios::binary);
	if (in.is_open())
	{
		int mode;
		readBinary(in,&mode);
		mode = -mode;
		if (mode != 1)
			return false;
		RNG z;
		int res;
		readBinary(in,&res);
		z.seed(res);
		int val;
		int index;
		for (int i = 0; i < 10; i++)
		{
			val = z.rangeInt(10000.0f,20000.0f);
			readBinary(in,&val);
		}
		int num;
		readBinary(in,&num);
		num -= z.rangeInt(1.0f,1000.0f);
		if (num >= 10000)
			num -= 10000;
		else
		{
			logNotice("AsciiImage::load()","Ignoring protected file: " + file + ".x");
			return false;
		}
		int tmp;
		readBinary(in,&tmp);
		tmp -= z.rangeInt(-10000.0f,10000.0f);
		int tmp2;
		readBinary(in,&tmp2);
		tmp2 -= z.rangeInt(-10000.0f,10000.0f);
		int kind = z.rangeInt(0.0f,5.0f);
		int color = z.rangeInt(0.0f,5.0f);
		for (int l = 0; l < num; l++)
		{
			for (int j = 0; j < 10; j++)
			{
				val = z.rangeInt(-10000.0f,10000.0f);
				readBinary(in,&val);
			}
			vector<int> rows(tmp2,0);
			for (int r = 0; r < tmp2; r++)
				rows[r] = r;
			layers.push_back(new OpR1dX_CellGrid());
			OpR1dX_CellGrid *layer = layers.back();
			layer->resize(tmp,tmp2,XCell(font));
			while (!rows.empty())
			{
						index = z.rangeInt(0.0f,(float)(rows.size() - 1));
				val = rows[index];
				for (int x = 0; x < tmp; x++)
				{
					layer->at(x,val)->read(in);
					layer->at(x,val)->setChar(layer->at(x,val)->getChar_416f20() - opR1d_xpMask_caf5c8[kind][x % 100][val % 100]);
					opR1d_4369a0(layer->at(x,val)->getFore(),opR1d_xpMask_caf5c8[color][x % 100][val % 100]);
					opR1d_4369a0(layer->at(x,val)->getBack(),opR1d_xpMask_caf5c8[color][x % 100][val % 100]);
				}
				removeVectorElement(rows,index);
			}
			if (offset->x != -1)
				layer->contract(offset->x,layer->getWidth() - width - offset->x,offset->y,layer->getHeight() - height - offset->y);
		}
		return true;
	}
	else
		return false;
}
