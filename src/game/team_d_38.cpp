// team_d_38: map generation prop placement helper 0x6ca780 (pick a prop and a wall side to place it against).
// NOTE: names and layouts are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p) throw();		// 0x46ca50
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor (0x46ca50)
};

struct Rect38	// NOTE: placeholder name
{
	int x;
	int y;
	int width;
	int height;

	Point center() const;	// NOTE: placeholder name (PushBounds::center)
};

class Shape38	// NOTE: placeholder name
{
public:
	int getWidth();		// NOTE: folded getter
	int getHeight();	// NOTE: folded getter
};

struct PropRec38	// NOTE: placeholder name and layout (prop record)
{
	char				pad000[0x3c];
	vector<Shape38 *>	shapes;		// +0x3c
	char				pad04c[0x54 - 0x4c];
	bool				unknown54;	// NOTE: placeholder name (may rotate)
	bool				unknown55;	// NOTE: placeholder name
	char				pad056[0xf8 - 0x56];
	int					unknownf8;	// NOTE: placeholder name (category)
};
extern vector<PropRec38 *> props38_cf35b0;	// NOTE: placeholder name
extern int edgeChances38_b9f2f0[][3];	// NOTE: placeholder name

class Map38	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	vector<vector<Point> > *unknown459070();	// NOTE: placeholder name (trivial getter)
};
extern Map38 *world38;	// NOTE: placeholder name (0xcefc4c)

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
template <class T> int OpQ5_randomIndex(vector<T> &v);	// NOTE: placeholder name
template <class T> void removeVectorElement(vector<T> &v, int index);
bool OpT8b_Fn9d9b60(const vector<bool> &v);	// NOTE: placeholder name (any set)
bool opt4_isEdgeClear6c9cb0(int side, Point *pos, int length, int margin, Rect38 *r);	// NOTE: placeholder name

bool OpD_placeWallProp_6ca780(vector<vector<int> > &candidates, int mode, Rect38 *area, int margin, int unused, int *propIndex, Point *outPos, int *outSide)	// NOTE: placeholder name
{
	int value;
	for (int i = 0; i < 50; i++)
	{
		value = OpQ5_randomIndex(candidates[mode]);
		*propIndex = candidates[mode][value];
		if (props38_cf35b0[*propIndex]->unknownf8 == 5)
		{
			vector<Point> &distances = (*world38->unknown459070())[5];
			for (unsigned int j = 0; j < distances.size(); j++)
			{
				if (OpQ1_distanceCeil_40a3f0(area->center(),distances[j]) <= 0x32)
					goto next;
			}
		}
		break;
next:
		;
	}
	int w = props38_cf35b0[*propIndex]->shapes.front()->getWidth();
	int y = props38_cf35b0[*propIndex]->shapes.front()->getHeight();
	vector<bool> open(4,false);
	open[2] = area->width >= w + margin * 2 && area->height >= y + margin * 2;
	open[0] = open[2] && props38_cf35b0[*propIndex]->unknown54;
	if (props38_cf35b0[*propIndex]->unknown54)
		open[1] = open[3] = area->width >= y + margin * 2 && area->height >= w + margin * 2;
	else
		open[1] = open[3] = false;
	if (!OpT8b_Fn9d9b60(open))
		return false;
	do
	{
		*outSide = OpQ5_randomIndex(open);
	}
	while (!open[*outSide]);
	if (mode == 2)
	{
		*outPos = area->center();
		outPos->x -= w / 2;
		outPos->y -= y / 2;
	}
	else
	{
		switch (*outSide)
		{
		case 0:
			outPos->x = rng.chance(50) ? area->x + margin : OpX5_maxInt(area->x + margin,area->x + area->width - margin - w);
			outPos->y = area->y + area->height - margin - y;
			break;
		case 1:
			outPos->x = area->x + margin;
			outPos->y = rng.chance(50) ? area->y + margin : OpX5_maxInt(area->y + margin,area->y + area->height - margin - w);
			break;
		case 2:
			outPos->x = rng.chance(50) ? area->x + margin : OpX5_maxInt(area->x + margin,area->x + area->width - margin - w);
			outPos->y = area->y + margin;
			break;
		case 3:
			outPos->x = area->x + area->width - margin - y;
			outPos->y = rng.chance(50) ? area->y + margin : OpX5_maxInt(area->y + margin,area->y + area->height - margin - w);
			break;
		}
	}
	bool ok = props38_cf35b0[*propIndex]->unknown55 || rng.chance(edgeChances38_b9f2f0[props38_cf35b0[*propIndex]->unknownf8][mode]);
	if (!ok || opt4_isEdgeClear6c9cb0(*outSide,outPos,w,y,area))
	{
		removeVectorElement(candidates[mode],value);
		return true;
	}
	else
		return false;
}
