// team_d_120: free function 0x604420 (caller OpD_namePart_604c20 in team_d_33.cpp): chooses the descriptive
// prefix of a fabricated weapon name ("Gui.", "Spread", "Hvy.", "Cycling", ...) from the record's special
// properties or, weighted, from how it compares with other parts of its slot and type.
// NOTE: record layouts are partial; names are placeholders. The parameter type differs from team_d_33's
// declaration (PartRec33), so that caller links to a stub; the address mapping is unaffected.
// NOTE: the pushes of literal names bind to push_back(const string&) and the ternary one to the rvalue overload,
// as in the exe; the last weight is written x / -2. Locals are named for their stack-slot hash order.
#include <string>
#include <vector>
using namespace std;

bool OpU8a_anyPositive(vector<int> &v);	// NOTE: placeholder name (0x9d54c0)
int OpS8b_Fn9d4500(vector<int> &v);	// NOTE: placeholder name (weighted pick)

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

struct IntRange120	// NOTE: placeholder name
{
	int lo;
	int hi;

	int middle();
};

struct PartRec120	// NOTE: placeholder name and layout (part record)
{
	char			pad000[0x44];
	int				type;			// +0x044
	char			pad048[0x4c - 0x48];
	int				count;			// +0x04c
	char			pad050[0xac - 0x50];
	int				unknownac;		// +0x0ac
	char			pad0b0[0x104 - 0xb0];
	int				unknown104;		// +0x104
	char			pad108[0x114 - 0x108];
	int				unknown114;		// +0x114
	int				unknown118;		// +0x118
	int				unknown11c;		// +0x11c
	IntRange120		damage;			// +0x120
	int				subType;		// +0x128
	char			pad12c[0x130 - 0x12c];
	int				unknown130;		// +0x130
	char			pad134[0x13c - 0x134];
	vector<int>		unknown13c;		// +0x13c
	char			pad14c[0x15c - 0x14c];
	int				unknown15c;		// +0x15c
};
extern vector<PartRec120 *> partRecords120_d2d1c4;	// NOTE: placeholder name

string OpD_baseName_604420(PartRec120 *rec)	// NOTE: placeholder name
{
	if (rec->unknown104 > 0)
		return rec->unknown104 == 1 ? "Warp" : "Gui.";
	if (rec->unknown11c)
		return "Spread";
	switch (rec->unknown118)
	{
	case 0:
	case 1:
		break;
	case 2:
		return "Shotgun";
	case 3:
		return rng.chance(50) ? "Gatling" : "Burst";
	case 4:
		return rng.chance(50) ? "Burst" : "Flak";
	default:
		return "Flak";
	}
	vector<string> parts;
	vector<int> vec;
	parts.push_back("Hyp.");
	vec.push_back(0);
	if (rec->unknown13c.size() > 1)
		vec.back() = rec->unknown13c.size() * 5;
	parts.push_back("Hvy.");
	vec.push_back(0);
	if (rec->count > 1)
		vec.back() = rec->count * 4;
	parts.push_back("Prc.");
	vec.push_back(0);
	if (rec->unknown130)
		vec.back() = rec->unknown130 / 2;
	parts.push_back("Hpw.");
	vec.push_back(0);
	int type = rec->type;
	int kind = rec->subType;
	int total = 0;
	int n = 0;
	int avg = 0;
	int cnt = 0;
	for (unsigned int i = 0; i < partRecords120_d2d1c4.size(); i++)
	{
		if (partRecords120_d2d1c4[i]->type == type && partRecords120_d2d1c4[i]->subType == kind)
		{
			total += partRecords120_d2d1c4[i]->damage.middle() / partRecords120_d2d1c4[i]->count;
			n++;
			avg += partRecords120_d2d1c4[i]->unknownac;
			cnt++;
		}
	}
	if (rec->damage.middle() / rec->count > total / n)
		vec.back() = rec->damage.middle() / rec->count - total / n;
	parts.push_back("Com.");
	vec.push_back(0);
	if (rec->unknownac < avg / cnt / 2)
		vec.back() = avg / cnt / 2 - rec->unknownac;
	parts.push_back("Cld.");
	vec.push_back(0);
	if (rec->unknown15c)
		vec.back() = 10;
	parts.push_back(rng.chance(50) ? "Cycling" : "Rapid");
	vec.push_back(0);
	if (rec->unknown114 <= -10)
		vec.back() = rec->unknown114 / -2;
	if (OpU8a_anyPositive(vec))
	{
		int idx = OpS8b_Fn9d4500(vec);
		if (vec[idx] >= 6)
			return parts[idx];
	}
	return "";
}
