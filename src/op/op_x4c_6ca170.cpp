// op_x4c: BS::unknown6ca170 (0x6ca170), Beta 17.1. NOTE: class/method names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	int randomInRange_40c130();	// NOTE: placeholder name
};

class ItemDef
{
public:
	char pad0[0x64];
	int unknown64;
};
template <class T> int OpQ5_randomIndex(vector<T> &v);	// NOTE: placeholder name (0x9d9b20)

class BS
{
public:
	ItemDef *selectRandomItem(int chanceType, int rating, int category);	// 0x6c3bc0
	ItemDef *selectRandomItemOfRating(int level, int mode, int chanceType, int rating, int category, int unknown, int attempt);	// 0x6c40e0
	bool unknown6ca170(const Point &range, int picks, int count, int chanceType, vector<ItemDef *> *items, vector<int> *counts, int unknown);	// NOTE: placeholder name
};

bool BS::unknown6ca170(const Point &range, int picks, int count, int chanceType, vector<ItemDef *> *items, vector<int> *counts, int unknown)
{
	for (int i = 0; i < count; i++)
	{
		int rating = ((Point &)range).randomInRange_40c130();
		items->push_back(rating == -1 ? selectRandomItem(chanceType,0x1f,0x12) : selectRandomItemOfRating(rating,0,chanceType,0x1f,0x12,unknown,0));
		if (items->back() == 0)
			items->pop_back();
	}
	if (items->empty())
		return false;
	counts->assign(items->size(),0);
	for (int j = 0; j < picks; j++)
	{
		int index = OpQ5_randomIndex(*items);
		if ((*items)[index]->unknown64 == 0 || (*counts)[index] < (*items)[index]->unknown64)
			(*counts)[index]++;
	}
	return true;
}
