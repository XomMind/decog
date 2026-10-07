// team_a_14: destructors of two large records destroyed through ICF-folded scalar deleting destructors
// (??_GOpR6_KCD_24_0 / ??_GOpR6_KCD_20_1 in the mapping are aliases).
// NOTE: class names and layouts are placeholders.
#include <string>
#include <vector>
using namespace std;

struct OpV4d_Trivial;
void OpV4d_deleteMapRecords(vector<OpV4d_Trivial*> &v) throw();	// NOTE: placeholder name

class AsciiImage
{
public:
	char pad[0xc0];
	~AsciiImage();
};

struct Record_456c50	// NOTE: placeholder name (destroyed through the ??_G at 0x9e73f0)
{
	char pad0[8];
	string unknown8;
	string unknown24;
	char pad40[0x7c - 0x40];
	AsciiImage image;
	vector<unsigned int> unknown13c;
	char pad14c[0x174 - 0x14c];
	string unknown174;
	char pad190[0x1b4 - 0x190];
	string unknown1b4;
	vector<OpV4d_Trivial *> unknown1d0;
	vector<unsigned int> unknown1e0;
	char pad1f0[0x1f4 - 0x1f0];
	vector<unsigned int> unknown1f4;
	char pad204[0x210 - 0x204];
	vector<unsigned int> unknown210;
	char pad220[0x23c - 0x220];
	vector<string> unknown23c;
	char pad24c[0x250 - 0x24c];
	vector<unsigned int> unknown250;
	vector<OpV4d_Trivial *> unknown260;
	char pad270[0x288 - 0x270];
	string unknown288;
	~Record_456c50();
};

Record_456c50::~Record_456c50()
{
	OpV4d_deleteMapRecords(unknown1d0);
	OpV4d_deleteMapRecords(unknown260);
}

struct Record_4596f0	// NOTE: placeholder name (destroyed through the ??_G at 0x9e73c0)
{
	int pad0;
	string unknown4;
	char pad20[0x2c - 0x20];
	string unknown2c;
	char pad48[0x4c - 0x48];
	string unknown4c;
	char pad68[0xc4 - 0x68];
	vector<OpV4d_Trivial *> unknownC4;
	vector<unsigned int> unknownD4;
	char padE4[0xfc - 0xe4];
	vector<unsigned int> unknownFc;
	char pad10c[0x148 - 0x10c];
	vector<unsigned int> unknown148;
	char pad158[0x160 - 0x158];
	vector<vector<OpV4d_Trivial *> > unknown160;
	string unknown170;
	string unknown18c;
	char pad1a8[0x1ac - 0x1a8];
	string unknown1ac;
	~Record_4596f0();
};

Record_4596f0::~Record_4596f0()
{
	OpV4d_deleteMapRecords(unknownC4);
	for (unsigned int i = 0; i < unknown160.size(); i++)
		OpV4d_deleteMapRecords(unknown160[i]);
}
