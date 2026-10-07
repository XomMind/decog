// team_a_16: Layout_455c10::fillMask (0x455c10).
// NOTE: names and layout are placeholders. The nested block and the split n/k declarations reproduce the exe's stack layout.
#include <vector>
using namespace std;

struct Point
{
	int	x;
	int	y;
	int randomInRange_40c130();
};

template <class T> void OpS8c_shuffle(vector<T> &v);	// NOTE: placeholder name

struct Span_455c10	// NOTE: placeholder name
{
	int low;
	int high;
	Point count;
};

class Layout_455c10	// NOTE: placeholder name
{
public:
	char pad0[0x5c];
	vector<int> cells;
	char pad6c[0x8c - 0x6c];
	vector<Span_455c10 *> spans;
	void fillMask(vector<bool> &mask);
};

void Layout_455c10::fillMask(vector<bool> &mask)
{
	mask.assign(cells.size(),true);
	if (!spans.empty())
	{
		for (unsigned int i = 0; i < spans.size(); i++)
		{
			vector<int> indexes;
			for (int j = spans[i]->low; j <= spans[i]->high; j++)
			{
				mask[j] = false;
				indexes.push_back(j);
			}
			OpS8c_shuffle(indexes);
			{
				int n;
				int k = 0;
				for (n = spans[i]->count.randomInRange_40c130(); n > 0; k++, n--)
					mask[indexes[k]] = true;
			}
		}
	}
}
