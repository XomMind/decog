// Map (world object at 0xcefc4c): header-inline vector/list accessors 0x464b90-0x4651e0.
//	Continues cc_r2_01 (same class, same layout); the exe lays these out in declaration order (LTCG).
// NOTE: class layout is partial; padding members, member names and method names are placeholders.
#include <vector>
using namespace std;

class Prop;
class Item;

class HItem
{
	int	ID;
public:
	HItem();
	Item *operator->() const;	// 0x9b65b0
};

class HProp
{
	int	ID;
public:
	HProp();
	Prop *operator->() const;	// 0x9b64f0
};

class XBuffer;	// NOTE: placeholder name

struct PropExtra	// NOTE: placeholder name
{
	bool unknown456540();	// NOTE: placeholder name
};

struct ItemExtra	// NOTE: placeholder name
{
	bool unknown4565a0();	// NOTE: placeholder name
};

struct ItemType	// NOTE: placeholder name
{
	char pad[0x40];
	int unknown40;	// NOTE: placeholder name
};

class Prop
{
public:
	PropExtra *unknown45c9b0();	// NOTE: placeholder name
};

class Item
{
public:
	ItemType *unknown9b4350();	// NOTE: placeholder name
	ItemExtra *unknown44a7d0();	// NOTE: placeholder name
};

int findItemIndex(vector<HItem> &v, HItem item);						// 0x9d3110
void eraseItemAt(vector<HItem> &v, int index);							// 0x9da940
template <class T> void removeVectorElement(vector<T> &v, int index);	// NOTE: placeholder name (0x9de6f0 for int)
bool eraseProp(vector<HProp> &v, HProp prop);							// 0x9d2f00
bool unknown9d30e0(vector<HProp> &v, HProp prop);						// NOTE: placeholder name
bool unknown9d31e0(vector<HProp> &v, HProp prop);						// NOTE: placeholder name
bool unknown9d3160(vector<HProp> &v, HProp prop);						// NOTE: placeholder name
bool unknown9d30e0i(vector<HItem> &v, HItem item);						// NOTE: placeholder name
bool unknown9d31e0i(vector<HItem> &v, HItem item);						// NOTE: placeholder name
bool eraseItem(vector<HItem> &v, HItem item);							// 0x9d2f00
bool unknown9d3160i(vector<HItem> &v, HItem item);						// NOTE: placeholder name

class Map	// NOTE: placeholder name
{
public:
	void unknown464b40(int index);					// 0x464b40
	void unknown464b90(HItem item);					// NOTE: placeholder name
	void unknown464bd0(int index);					// NOTE: placeholder name
	void unknown464c10(HItem item);					// NOTE: placeholder name
	bool unknown464c50();							// NOTE: placeholder name
	void unknown464cd0(HProp prop);					// NOTE: placeholder name
	void unknown464d00(HProp prop, int offset);		// NOTE: placeholder name
	void unknown464d50(HProp prop);					// NOTE: placeholder name
	void unknown464d80(HProp prop);					// NOTE: placeholder name
	void unknown464db0(HProp prop);					// NOTE: placeholder name
	void unknown464de0(HProp prop);					// NOTE: placeholder name
	void unknown464e10(int value);					// NOTE: placeholder name
	void unknown464e30(HProp prop);					// NOTE: placeholder name
	void unknown464e60(HProp prop);					// NOTE: placeholder name
	void unknown464ed0(HProp prop);					// NOTE: placeholder name
	void unknown464f30(HProp prop);					// NOTE: placeholder name
	void unknown464f60(HItem item);					// NOTE: placeholder name
	void unknown464fd0(HItem item);					// NOTE: placeholder name
	void unknown465030(HItem item);					// NOTE: placeholder name
	void unknown465060(HItem item);					// NOTE: placeholder name
	void unknown4650c0(HItem item);					// NOTE: placeholder name
	void unknown465100();							// NOTE: placeholder name
	void unknown465120(int value);					// NOTE: placeholder name
	void unknown465140();							// NOTE: placeholder name
	void unknown465160(int value);					// NOTE: placeholder name
	void unknown465180(HProp prop);					// NOTE: placeholder name
	void unknown4651b0(HProp prop);					// NOTE: placeholder name
	void unknown4651e0(int value);					// NOTE: placeholder name

	char					pad000[0x320];
	int						unknown320;				// NOTE: placeholder name
	char					pad324[0x340 - 0x324];
	vector<HItem>			items340;				// NOTE: placeholder name
	vector<int>				values350;				// NOTE: placeholder name
	vector<int>				values360;				// NOTE: placeholder name
	vector<HItem>			items370;				// NOTE: placeholder name
	vector<int>				values380;				// NOTE: placeholder name
	vector<HItem>			items390;				// NOTE: placeholder name
	vector<int>				values3a0;				// NOTE: placeholder name
	char					pad3b0[0x480 - 0x3b0];
	vector<HProp>			props480;				// NOTE: placeholder name
	vector<HProp>			props490;				// NOTE: placeholder name
	vector<XBuffer *>		buffers4a0;				// NOTE: placeholder name
	vector<HProp>			props4b0;				// NOTE: placeholder name
	vector<HProp>			props4c0;				// NOTE: placeholder name
	vector<int>				values4d0;				// NOTE: placeholder name
	vector<HProp>			props4e0;				// NOTE: placeholder name
	vector<HProp>			props4f0;				// NOTE: placeholder name
	vector<HItem>			items500;				// NOTE: placeholder name
	vector<HItem>			items510;				// NOTE: placeholder name
	char					pad520[0x55c - 0x520];
	int						unknown55c;				// NOTE: placeholder name
	char					pad560[0x570 - 0x560];
	int						unknown570;				// NOTE: placeholder name
	char					pad574[0x614 - 0x574];
	int						unknown614;				// NOTE: placeholder name
	int						unknown618;				// NOTE: placeholder name
	vector<HProp>			props61c;				// NOTE: placeholder name
	vector<HProp>			props62c;				// NOTE: placeholder name
	char					pad63c[0x648 - 0x63c];
	vector<int>				values648;				// NOTE: placeholder name
};

class BS	// NOTE: placeholder name (the world object; same object as Map above)
{
public:
	void unknown464c70(int itemID);					// NOTE: placeholder name

	char					pad000[0x390];
	vector<HItem>			items390;				// NOTE: placeholder name
	vector<int>				values3a0;				// NOTE: placeholder name
};

void Map::unknown464b90(HItem item)
{
	int index = findItemIndex(items340,item);
	if (index != -1)
		unknown464b40(index);
}

void Map::unknown464bd0(int index)
{
	eraseItemAt(items370,index);
	removeVectorElement(values380,index);
}

void Map::unknown464c10(HItem item)
{
	int index = findItemIndex(items370,item);
	if (index != -1)
		unknown464bd0(index);
}

bool Map::unknown464c50()
{
	return items390.size();
}

void BS::unknown464c70(int itemID)
{
	int index = findItemIndex(items390,*(HItem *)&itemID);
	if (index != -1)
	{
		eraseItemAt(items390,index);
		removeVectorElement(values3a0,index);
	}
}

void Map::unknown464cd0(HProp prop)
{
	eraseProp(props480,prop);
}

void Map::unknown464d00(HProp prop, int offset)
{
	props490.push_back(prop);
	buffers4a0.push_back((XBuffer *)(unknown320 + offset));
}

void Map::unknown464d50(HProp prop)
{
	unknown9d30e0(props4b0,prop);
}

void Map::unknown464d80(HProp prop)
{
	eraseProp(props4b0,prop);
}

void Map::unknown464db0(HProp prop)
{
	unknown9d30e0(props4c0,prop);
}

void Map::unknown464de0(HProp prop)
{
	eraseProp(props4c0,prop);
}

void Map::unknown464e10(int value)
{
	values4d0.push_back(value);
}

void Map::unknown464e30(HProp prop)
{
	unknown9d30e0(props4e0,prop);
}

void Map::unknown464e60(HProp prop)
{
	if (prop->unknown45c9b0() && prop->unknown45c9b0()->unknown456540() && !unknown9d31e0(props4f0,prop))
		props4f0.push_back(prop);
}

void Map::unknown464ed0(HProp prop)
{
	if (!(prop->unknown45c9b0() && prop->unknown45c9b0()->unknown456540()))
		return;
	eraseProp(props4f0,prop);
}

void Map::unknown464f30(HProp prop)
{
	unknown9d3160(props4f0,prop);
}

void Map::unknown464f60(HItem item)
{
	if (item->unknown44a7d0() && item->unknown44a7d0()->unknown4565a0() && !unknown9d31e0i(items500,item))
		items500.push_back(item);
}

void Map::unknown464fd0(HItem item)
{
	if (!(item->unknown44a7d0() && item->unknown44a7d0()->unknown4565a0()))
		return;
	eraseItem(items500,item);
}

void Map::unknown465030(HItem item)
{
	unknown9d3160i(items500,item);
}

void Map::unknown465060(HItem item)
{
	if (item->unknown9b4350()->unknown40 == 0x24 && !unknown9d31e0i(items510,item))
		items510.push_back(item);
}

void Map::unknown4650c0(HItem item)
{
	if (item->unknown9b4350()->unknown40 == 0x24)
		eraseItem(items510,item);
}

void Map::unknown465100()
{
	unknown55c = 0;
}

void Map::unknown465120(int value)
{
	unknown570 = value;
}

void Map::unknown465140()
{
	unknown614 = unknown320 + 100;
}

void Map::unknown465160(int value)
{
	unknown618 = value;
}

void Map::unknown465180(HProp prop)
{
	unknown9d30e0(props61c,prop);
}

void Map::unknown4651b0(HProp prop)
{
	unknown9d30e0(props62c,prop);
}

void Map::unknown4651e0(int value)
{
	values648.push_back(value);
}
