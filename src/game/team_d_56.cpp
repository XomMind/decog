// team_d_56: BS member 0x6c2b60 (pick an unused map vec on a given side and a spot in it).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();						// NOTE: placeholder name (0x453b40)
	Point(const Point &p) throw();	// 0x46ca50
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor (0x46ca50)
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(int x_, int y_, int w, int h);
	bool containsPos(const Point &p);	// NOTE: placeholder name (0x40aa00)
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	int getWidth();							// NOTE: folded getter
	int getHeight();						// NOTE: folded getter
	bool inBounds(int x, int y);			// NOTE: placeholder name (0x9b45c0)
	T *at(int x, int y);					// NOTE: placeholder name (0x9ceda0)
	T *atPoint(const Point &p);				// NOTE: placeholder name (0x9ced70)
};
extern Array2D<int> originalTerrain;	// 0xd378c0

struct MapArea56	// NOTE: placeholder name and layout
{
	vector<Point>	points;		// +0x00
	char			pad10[0x40 - 0x10];
	int				unknown40;	// NOTE: placeholder name
	char			pad44[0x50 - 0x44];
	bool			unknown50;	// NOTE: placeholder name (taken)
};
extern vector<MapArea56> areas56_cf126c;	// NOTE: placeholder name

struct TerrainRec56	// NOTE: placeholder name and layout
{
	char	pad00[0x58];
	bool	unknown58;	// NOTE: placeholder name
};
extern vector<TerrainRec56 *> terrains56_cfb844;	// NOTE: placeholder name
extern int *p_cefb9c;	// NOTE: placeholder name
extern int int56_ced224;	// NOTE: placeholder name

class WeightedInts56	// NOTE: placeholder name (OpR5h_WL<int>)
{
public:
	vector<int>	values;
	vector<int>	weights;
	int			total;

	WeightedInts56();				// 0x9bab50
	~WeightedInts56();				// 0x700dd0
	void add(int value, int weight);
	bool pick(int *out);
	void remove(int value);
};

bool OpX5_containsRecord(vector<int> &v, int value);	// NOTE: placeholder name
template <class T> int OpQ5_randomIndex(vector<T> &v);	// NOTE: placeholder name
Point OpU8a_randomPoint(vector<Point> &v);	// NOTE: placeholder name (0x9d5350)

class BS
{
public:
	char		padc00[0xc58];
	vector<int>	usedAreas;	// +0xc58, NOTE: placeholder name

	Point unknown6c2b60(bool flag, int side, int *outIndex);	// NOTE: placeholder name
};

Point BS::unknown6c2b60(bool flag, int side, int *outIndex)
{
	*outIndex = -1;
	Array2D<int> *room = &originalTerrain;
	Rect vec(0,0,room->getWidth(),room->getHeight());
	switch (side)
	{
		break;
	case 6:
		if (flag)
			goto right;
left:
		vec.width /= 3;
		break;
	case 2:
		if (flag)
			goto left;
right:
		vec.x += vec.width / 3 * 2;
		vec.width /= 3;
		break;
	case 0:
		if (flag)
			goto down;
up:
		vec.height /= 3;
		break;
		break;
	case 4:
		if (flag)
			goto up;
down:
		vec.y += vec.height / 3 * 2;
		vec.height /= 3;
		break;
	}
	vector<int> parts;
	for (int i = 0; i < areas56_cf126c.size(); i++)
	{
		if (!areas56_cf126c[i].unknown50 && !OpX5_containsRecord(usedAreas,i))
		{
			for (unsigned int j = 0; j < areas56_cf126c[i].points.size(); j++)
			{
				if (!vec.containsPos(areas56_cf126c[i].points[j]))
					goto next;
			}
			parts.push_back(i);
		}
next:
		;
	}
	if (parts.empty())
	{
		for (int k = 0; k < areas56_cf126c.size(); k++)
		{
			if (!areas56_cf126c[k].unknown50 && !OpX5_containsRecord(usedAreas,k))
			{
				for (unsigned int m = 0; m < areas56_cf126c[k].points.size(); m++)
				{
					if (vec.containsPos(areas56_cf126c[k].points[m]))
					{
						parts.push_back(k);
						break;
					}
				}
			}
		}
	}
	if (parts.empty())
	{
		for (int n = 0; n < areas56_cf126c.size(); n++)
		{
			if (!areas56_cf126c[n].unknown50 && !OpX5_containsRecord(usedAreas,n))
				parts.push_back(n);
		}
	}
	if (parts.empty())
	{
		for (int o = 0; o < areas56_cf126c.size(); o++)
			parts.push_back(o);
	}
	WeightedInts56 first;
	for (unsigned int q = 0; q < parts.size(); q++)
		first.add(parts[q],int56_ced224 - areas56_cf126c[parts[q]].unknown40);
	if (first.pick(outIndex))
		first.remove(*outIndex);
	else
		*outIndex = OpQ5_randomIndex(areas56_cf126c);
	usedAreas.push_back(*outIndex);
	Point pick;
	int attempt = 0;
	do
	{
		pick = OpU8a_randomPoint(areas56_cf126c[*outIndex].points);
		if (room->inBounds(pick.x - 1,pick.y) && terrains56_cfb844[*room->at(pick.x - 1,pick.y)]->unknown58
			&& room->inBounds(pick.x + 1,pick.y) && terrains56_cfb844[*room->at(pick.x + 1,pick.y)]->unknown58
			&& room->inBounds(pick.x,pick.y - 1) && terrains56_cfb844[*room->at(pick.x,pick.y - 1)]->unknown58
			&& room->inBounds(pick.x,pick.y + 1) && terrains56_cfb844[*room->at(pick.x,pick.y + 1)]->unknown58
			&& *room->atPoint(pick) == *p_cefb9c)
			break;
	}
	while (++attempt < 50);
	return pick;
}
