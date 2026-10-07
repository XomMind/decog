// team_d_22: CLore item list fill (0x7ebba0).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
using namespace std;

struct LoreEntry;	// NOTE: placeholder name
extern vector<LoreEntry *> loreEntries_d02cb4;	// NOTE: placeholder name

class CLore;

class CLoreItem	// NOTE: placeholder layout
{
public:
	CLoreItem(CLore *parent, int row, LoreEntry *entry);
	char pad[0x70];
};

template <class T> void OpX5_insertAt(vector<T> &v, int index, T value);	// NOTE: placeholder name

class CLore	// NOTE: placeholder layout
{
public:
	void unknown7ebba0(int count, int start, int y, bool insert);	// NOTE: placeholder name

	char pad[0x70];
	vector<CLoreItem *> items;	// +0x70, NOTE: placeholder name
};

void CLore::unknown7ebba0(int count, int start, int y, bool insert)
{
	for (int i = 0, idx = start, row = y; i < count && idx < loreEntries_d02cb4.size(); idx++, row++, i++)
	{
		if (insert)
			OpX5_insertAt(items,i,new CLoreItem(this,row,loreEntries_d02cb4[idx]));
		else
			items.push_back(new CLoreItem(this,row,loreEntries_d02cb4[idx]));
	}
}
