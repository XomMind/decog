// claude_a: Entity::unknown5c9b10 (moved here from op_w8.cpp). The exe has no EH frame although the function owns a
// vector<bool>: every callee is nothrow. Most TUs declare HItem::operator-> without throw(), which makes LTCG keep an
// EH frame, so the handle and item getters use names private to this file (stubbed, paired by address).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
using namespace std;

class ClaudeA_Item	// NOTE: placeholder name (Item)
{
public:
	int unknown44aec0() throw();	// NOTE: placeholder name (ICF'd trivial getter)
	int unknown4578a0() throw();	// NOTE: placeholder name
};

class ClaudeA_HItem	// NOTE: placeholder name (HItem)
{
public:
	int ID;
	ClaudeA_Item *operator->() const throw();	// 0x9b65b0
};

bool opw8_contains(const vector<bool> &values, bool value) throw();	// NOTE: placeholder name (0x9d7670)

class Entity
{
public:
	char pad00[0x78];
	int slots[4];						// +0x78 NOTE: placeholder name
	char pad88[0x134 - 0x88];
	vector<ClaudeA_HItem> parts;		// +0x134 NOTE: placeholder name

	bool unknown5c9b10();	// NOTE: placeholder name
};

bool Entity::unknown5c9b10()
{
	vector<bool> filled(4,false);
	for (int i = 0; i < 4; i++)
		filled[i] = slots[i] == 0;
	filled[2] = true;
	for (unsigned int j = 0; j < parts.size(); j++)
	{
		if (parts[j]->unknown44aec0() <= 3)
			filled[parts[j]->unknown4578a0()] = true;
	}
	return opw8_contains(filled,false);
}
