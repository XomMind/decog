// team_d_31: scrap engine helper 0x6040d0 (inherit special part properties from the consumed parts).
// NOTE: names and layouts are placeholders.
#include <vector>
using namespace std;

struct PartRec31	// NOTE: placeholder name and layout (part record)
{
	char		pad000[0x104];
	int			unknown104;
	char		pad108[0x11c - 0x108];
	int			unknown11c;
	char		pad120[0x128 - 0x120];
	int			unknown128;
	char		pad12c[0x13c - 0x12c];
	vector<int>	unknown13c;
	char		pad14c[0x15c - 0x14c];
	int			unknown15c;
};
extern vector<PartRec31 *> partRecords31_d2d1c4;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

extern int int_ba3be4;	// NOTE: placeholder name
extern int int_ba3b18;	// NOTE: placeholder name
int OpU8a_randomRec(vector<int> &v);	// NOTE: placeholder name (0x9d5d00)

void OpD_inheritPartTraits_6040d0(vector<int> &sources, PartRec31 *rec, bool flag)	// NOTE: placeholder name
{
	if (!flag || rng.chance(int_ba3be4))
	{
		rec->unknown104 = 0;
		rec->unknown11c = 0;
		rec->unknown15c = 0;
	}
	vector<int> types;
	if (rec->unknown13c.empty())
	{
		for (unsigned int i = 0; i < sources.size(); i++)
		{
			if (partRecords31_d2d1c4[sources[i]]->unknown104 >= 1)
			{
				types.push_back(0x11);
				break;
			}
		}
	}
	for (unsigned int j = 0; j < sources.size(); j++)
	{
		if (partRecords31_d2d1c4[sources[j]]->unknown11c)
		{
			types.push_back(0x17);
			break;
		}
	}
	if (flag && rec->unknown128 == 1)
	{
		for (unsigned int k = 0; k < sources.size(); k++)
		{
			if (partRecords31_d2d1c4[sources[k]]->unknown15c)
			{
				types.push_back(0x1f);
				break;
			}
		}
	}
	if (!types.empty() && rng.chance(100 - int_ba3b18))
	{
		switch (OpU8a_randomRec(types))
		{
		case 0x11:
			rec->unknown104 = partRecords31_d2d1c4[OpU8a_randomRec(sources)]->unknown104;
			break;
		case 0x17:
			rec->unknown11c = partRecords31_d2d1c4[OpU8a_randomRec(sources)]->unknown11c;
			break;
		case 0x1f:
			rec->unknown15c = partRecords31_d2d1c4[OpU8a_randomRec(sources)]->unknown15c;
			break;
		}
	}
	if (rec->unknown104 && !rec->unknown13c.empty())
		rec->unknown104 = 0;
	if (rec->unknown104 && rec->unknown11c)
	{
		if (rng.chance(50))
			rec->unknown104 = 0;
		else
			rec->unknown11c = 0;
	}
	if (rec->unknown15c && rec->unknown128 != 1 && rec->unknown128 != 3)
		rec->unknown15c = 0;
}
