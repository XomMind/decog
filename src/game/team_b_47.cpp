// team_b_47: inventory item label without the [inv] suffix (0x8f8e90) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
using namespace std;
string intToString(int value);
class TeamB_LabelItem2	// NOTE: placeholder name (Item)
{
public:
	int unknown457c80();	// NOTE: placeholder name
	int getValue_9b6bf0() const;	// NOTE: placeholder name
	string getName_571db0(int a, int b);	// NOTE: placeholder name
};
class HItem { public: int ID; TeamB_LabelItem2 *operator->() const; };
string teamb_itemLabel8f8e90(HItem item)	// 0x8f8e90
{
	return item->getName_571db0(0,0) + " (" + intToString(item->getValue_9b6bf0()) + "/" + intToString(item->unknown457c80()) + ")";
}
