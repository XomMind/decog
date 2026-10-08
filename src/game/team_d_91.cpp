// team_d_91: PlayerData::loadPartSlots (0x77f680): rebuilds the per-category part slot lists from the
// parts UI and, when restoring, trims slots to the saved per-category counts.
// NOTE: layouts are partial; member names other than loadPartSlots are placeholders. Slot91::Slot91 is a
// local copy of 0x46d1b0 (Push_46d1b0::operate, mapped elsewhere); it, HProp::HProp and the folded handle
// getter are declared throw() so the new expressions get no EH state, as in the exe. The restore loop's
// locals are named v/i/idx for their stack-slot order.
// NOTE: the handle, HProp and Slot91 helpers use file-unique names (Handle91, HProp91) so that the full build
// links them to stubs; with real definitions LTCG cannot prove the new expressions nothrow.
#include <vector>
#include <string>
using namespace std;

void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)
void OpS8c_copyInts(int *src, int *dst, unsigned int count);
template <class T> void removeVectorElement(vector<T> &v, int index);
template <class T> int OpQ5_randomIndex(vector<T> &v);	// NOTE: placeholder name

class PartItem91	// NOTE: placeholder name (Item); distinct so vector<PartItem91 *>::push_back gets its own pairing
{
public:
	void *getEffect(int type);
};

class HItem
{
public:
	int ID;
	PartItem91 *operator->() const;
};

class Handle91	// NOTE: as in team_c_07.cpp (folded handle getter)
{
public:
	void *get224() const throw();	// 0x9b65b0
};

class HProp91
{
public:
	int ID;
	HProp91() throw();
};

struct Slot91	// NOTE: placeholder name (0x14-byte part slot)
{
	int		index;	// +0x00
	PartItem91	*item;	// +0x04
	int		unknown08;
	PartItem91	*item2;	// +0x0c
	int		unknown10;

	Slot91(int index_, PartItem91 *item_, int a, PartItem91 *item2_, int b) throw();
	bool isFirstEmpty();	// NOTE: placeholder name (OpR1g_PropPair::isFirstEmpty)
};

Slot91::Slot91(int index_, PartItem91 *item_, int a, PartItem91 *item2_, int b) throw()
{
	index = index_;
	item = item_;
	unknown08 = a;
	item2 = item2_;
	unknown10 = b;
}

struct Part91	// NOTE: placeholder name and layout
{
	char	pad00[0x6c];
	HItem	item6c;		// +0x6c
	char	pad70[4];
	HItem	item74;		// +0x74
	char	pad78[4];
	int		category;	// +0x7c
};

class CParts
{
public:
	vector<Part91 *> *getFieldAddress();	// NOTE: placeholder name (Sweep_4a9ad0::getFieldAddress)
};
extern CParts *parts91_cec088;	// NOTE: placeholder name
extern vector<int> list91_d3391c;	// NOTE: placeholder name

class PlayerData	// NOTE: placeholder layout
{
public:
	char						pad000[0x178];
	vector< vector<Slot91 *> >	slots;	// +0x178

	void clearMarkers();	// NOTE: placeholder name (Unknown46d8b0::clearMarkers)
	void unknown77f2f0(vector<PartItem91 *> &list, int *counts);	// NOTE: placeholder name
	void loadPartSlots(bool restoring, int *counts);
};

void PlayerData::loadPartSlots(bool restoring, int *counts)
{
	clearMarkers();
	vector<Slot91 *> center;
	for (int i = 0; i < 4; i++)
		slots.push_back(center);
	vector<Part91 *> *adj = parts91_cec088->getFieldAddress();
	for (unsigned int x = 0, n = 0; x < adj->size(); x++, n++)
	{
		if (x && (*adj)[x]->category != (*adj)[x - 1]->category)
			n = 0;
		slots[(*adj)[x]->category].push_back(restoring ? new Slot91(n,(PartItem91 *)((Handle91 *)&(*adj)[x]->item6c)->get224(),HProp91().ID,(PartItem91 *)((Handle91 *)&(*adj)[x]->item74)->get224(),HProp91().ID) : new Slot91(n,0,(*adj)[x]->item6c.ID,0,(*adj)[x]->item74.ID));
	}
	list91_d3391c.clear();
	if (restoring && counts)
	{
		int c[4];
		OpS8c_copyInts(counts,c,4);
		for (int t = 0; t < 4; t++)
		{
			while (c[t] < 0)
			{
				bool removed = false;
				for (unsigned int u = 0; u < slots[t].size(); u++)
				{
					if (slots[t][u]->item == 0 && slots[t][u]->item2 == 0)
					{
						removeVectorElement((vector<int> &)slots[t],u);
						c[t]++;
						removed = true;
						break;
					}
				}
				if (!removed)
				{
					int idx = OpQ5_randomIndex(slots[t]);
					int i = 0;
					while (slots[t][idx]->isFirstEmpty() || slots[t][idx]->item2 != 0 || slots[t][idx]->item->getEffect(0x6c))
					{
						idx = OpQ5_randomIndex(slots[t]);
						if (++i > 5000)
							logFatal("PlayerData::loadPartSlots()","impossible to remove enough slots to satisfy reqs");
					}
					vector<PartItem91 *> v;
					v.push_back(slots[t][idx]->item);
					do
					{
						unknown77f2f0(v,c);
					} while (!v.empty());
				}
			}
		}
	}
}
