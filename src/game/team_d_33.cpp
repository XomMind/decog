// team_d_33: scrap engine naming helper 0x604c20 (build the name of a constructed part).
// NOTE: names and layouts are placeholders.
#include <vector>
#include <string>
using namespace std;

struct PartRec33	// NOTE: placeholder name and layout (part record)
{
	char			pad000[0x24];
	string			name;			// +0x24
	char			pad040[0x44 - 0x40];
	int				unknown44;		// NOTE: placeholder name (slot type)
	char			pad048[0x50 - 0x48];
	int				unknown50;		// NOTE: placeholder name (weight)
	char			pad054[0x128 - 0x54];
	int				unknown128;		// NOTE: placeholder name
	char			pad12c[0x23c - 0x12c];
	vector<string>	unknown23c;		// NOTE: placeholder name (name pool)
};
extern vector<PartRec33 *> partRecords33_d2d1c4;	// NOTE: placeholder name
extern string prefixes_cefdd8[][6];	// NOTE: placeholder name

class WeightedStrings33	// NOTE: placeholder name (OpR5h_WL<string>)
{
public:
	vector<string>	values;
	vector<int>		weights;
	int				total;

	WeightedStrings33();	// 0x9b9ee0
	~WeightedStrings33();	// 0x55c900
	void add(string value, int weight);	// 0x9ba310 instance
	bool empty();			// NOTE: placeholder name (folded)
	string &pick();			// NOTE: placeholder name
};

struct PartRec120;	// the record type src/game/team_d_120.cpp defines OpD_baseName_604420 with
string OpD_baseName_604420(PartRec120 *rec);	// NOTE: placeholder name (0x604420, src/game/team_d_120.cpp)
string OpU8a_randomString(vector<string> &v);	// NOTE: placeholder name (0x9d3280)

void OpD_namePart_604c20(vector<int> &sources, PartRec33 *rec)	// NOTE: placeholder name
{
	string text = rec->name;
	rec->name = OpD_baseName_604420((PartRec120 *)rec);
	if (!rec->name.empty())
		rec->name += " ";
	vector<string> parts;
	for (int i = 0; i < 6; i++)
	{
		if (!prefixes_cefdd8[rec->unknown128][i].empty())
			parts.push_back(prefixes_cefdd8[rec->unknown128][i]);
	}
	rec->name += OpU8a_randomString(parts);
	WeightedStrings33 pool;
	for (unsigned int j = 0; j < sources.size(); j++)
	{
		for (unsigned int k = 0; k < partRecords33_d2d1c4[sources[j]]->unknown23c.size(); k++)
			pool.add(partRecords33_d2d1c4[sources[j]]->unknown23c[k],partRecords33_d2d1c4[sources[j]]->unknown50);
	}
	if (!pool.empty())
		rec->name += " " + pool.pick();
	rec->name += rec->name.size() <= 0x1a ? " Construct/" : " Con/";
	switch (rec->unknown44)
	{
	case 0x14:
		rec->name += "G";
		break;
	case 0x15:
		rec->name += "C";
		break;
	case 0x16:
		rec->name += "G";
		break;
	case 0x17:
		rec->name += "C";
		break;
	case 0x18:
		rec->name += "L";
		break;
	default:
		rec->name += "X";
		break;
	}
}
