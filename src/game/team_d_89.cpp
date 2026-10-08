// team_d_89: member 0x783ae0 (called from Entity::equipPart): regenerates the hacking code lists (random
// codes with fixed known codes in the low slots) and clears their used flags.
// NOTE: class name and layout are placeholders.
#include <vector>
#include <string>
using namespace std;

char randomChar_4085b0(string &s);	// NOTE: placeholder name
template <class T> void OpQ5_eraseRange(vector<T> &v, int first, int last);	// NOTE: placeholder name
extern string prefix89_cf4db4;	// NOTE: placeholder name

class Codes89	// NOTE: placeholder name and layout
{
public:
	char			pad00[0xa0];
	vector<string>	codes;		// +0xa0
	vector<int>		usedB0;		// +0xb0
	vector<int>		usedC0;		// +0xc0
	vector<string>	codes2;		// +0xd0
	vector<int>		usedE0;		// +0xe0
	vector<int>		usedF0;		// +0xf0

	void unknown783ae0(bool reset);	// NOTE: placeholder name
};

void Codes89::unknown783ae0(bool reset)
{
	string str = "ACEFGHJKLMNPRTWX34679";
	int count = 4;
	if (reset)
		codes.clear();
	else
		OpQ5_eraseRange(codes,0xd,codes.size() - 1);
	for (int i = reset ? 0 : 0xd; i < 0x27; i++)
	{
		codes.push_back(prefix89_cf4db4);
		for (int j = 0; j < count; j++)
			codes.back() += randomChar_4085b0(str);
	}
	usedB0.assign(0x27u,0);
	if (reset)
	{
		codes[0] = prefix89_cf4db4 + "vjkh5135h09ag";
		codes[1] = prefix89_cf4db4 + "vbjklaq51";
		codes[2] = prefix89_cf4db4 + "vluq5qzf0";
		codes[3] = prefix89_cf4db4 + "b09824lka";
		codes[4] = prefix89_cf4db4 + "blkvzlkjw";
		codes[5] = prefix89_cf4db4 + "bljkeqwrs";
		codes[6] = prefix89_cf4db4 + "poesgdacz";
		codes[7] = prefix89_cf4db4 + "vczxk21345kl31";
		codes[0xc] = prefix89_cf4db4 + "vksjhdaksyzcl";
		codes[8] = prefix89_cf4db4 + "vzfqelkr1chah";
		codes[9] = prefix89_cf4db4 + "vb09835lkfsa3";
		codes[0xa] = prefix89_cf4db4 + "bvlkjgfqoiu5i";
		codes[0xb] = prefix89_cf4db4 + "lkjtql5ljsagr";
	}
	codes[0xe] = prefix89_cf4db4 + "1234";
	codes[0xf] = prefix89_cf4db4 + "IAMDERELICT";
	codes[0x14] = codes[0x10];
	codes[0x15] = codes[0x11];
	codes[0x16] = codes[0x12];
	codes[0x17] = codes[0x13];
	codes2.clear();
	for (int k = 0; k < 0x1c; k++)
	{
		codes2.push_back(prefix89_cf4db4);
		for (int m = 0; m < count; m++)
			codes2.back() += randomChar_4085b0(str);
	}
	usedE0.assign(0x1cu,0);
	if (reset)
		usedC0.assign(0x27u,0);
	else
	{
		for (int n = 0xd; n < 0x27; n++)
			usedC0[n] = 0;
	}
	usedF0.assign(0x1cu,0);
}
