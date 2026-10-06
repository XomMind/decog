// op_v1: misc functions in 0x409000-0x5b7000
#include <string>
#include <map>
#include <vector>
using namespace std;

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)

class OpV1_Condition	// NOTE: placeholder name
{
public:
	bool compareInt(int value);
	bool compareString(const string &value);

	char unknown00[0x20];
	int op;
	string text;
};

bool OpV1_Condition::compareInt(int value)
{
	switch (op)
	{
		case 0: return value == stringToInt(text);
		case 1: return value != stringToInt(text);
		case 2: return value <= stringToInt(text);
		case 3: return value >= stringToInt(text);
		case 4: return value < stringToInt(text);
		case 5: return value > stringToInt(text);
		case 6: return (value % stringToInt(text)) != 0;
		case 7: return (value % stringToInt(text)) == 0;
	}
	return false;
}

bool OpV1_Condition::compareString(const string &value)
{
	switch (op)
	{
		case 0: return value == text;
		case 1: return value != text;
		case 2: return stringToInt(value) <= stringToInt(text);
		case 3: return stringToInt(value) >= stringToInt(text);
		case 4: return stringToInt(value) < stringToInt(text);
		case 5: return stringToInt(value) > stringToInt(text);
		case 6: return (stringToInt(value) % stringToInt(text)) != 0;
		case 7: return (stringToInt(value) % stringToInt(text)) == 0;
	}
	return false;
}

//==================================================================
// Polymind suspicion widget width
//==================================================================

string floatToString(float value, int unknown1, int unknown2);	// NOTE: placeholder name (0x405760)
int opR1d_434b90(int value) throw();	// NOTE: placeholder name
extern string OpV1_gameStrings_d21e90[];	// NOTE: placeholder name
extern float OpV1_cf46f8;	// NOTE: placeholder name

class OpV1_Suspicion	// NOTE: placeholder name
{
public:
	int getRequiredWidth();
};

int OpV1_Suspicion::getRequiredWidth()
{
	return string("Suspicion").size() + 6 + OpV1_gameStrings_d21e90[opR1d_434b90((int)OpV1_cf46f8)].size() + floatToString(OpV1_cf46f8,1,1).size();
}

//==================================================================
// location name
//==================================================================

string intToString(int value);	// NOTE: placeholder name
extern string OpV1_names_cfb0c8[];	// NOTE: placeholder name
extern string OpV1_names_cfaca0[];	// NOTE: placeholder name

class OpV1_Location	// NOTE: placeholder name
{
public:
	string getName();

	int depth;
	int location;
};

string OpV1_Location::getName()
{
	if (depth >= 0)
	{
		return OpV1_names_cfb0c8[depth];
	}
	else
	{
		return intToString(depth) + "/" + OpV1_names_cfaca0[location];
	}
}

//==================================================================
// game data string entries
//==================================================================

char opw8_randomChar(const string &chars);	// NOTE: placeholder name (0x4085b0)
bool OpU8a_containsString(vector<string> &v, string s);	// NOTE: placeholder name (0x9d3fe0)
void OpV1_eraseAt(vector<string> &v, int index);	// NOTE: placeholder name

class OpV1_GameData	// NOTE: placeholder name
{
public:
	map<string,string>::iterator getEntryIterator(const string &key);	// NOTE: placeholder name
	string &getEntryText(const string &key);	// NOTE: placeholder name
	void setEntryText(const string &key, const string &text);	// NOTE: placeholder name
	void addToEntry(const string &key, int amount);	// NOTE: placeholder name
	string generateID();	// NOTE: placeholder name

	char pad0[0x100];
	map<string,string> entries;
	char pad110[0x334];
	vector<string> recentIDs;
};

map<string,string>::iterator OpV1_GameData::getEntryIterator(const string &key)
{
	map<string,string>::iterator it = entries.find(key);
	if (it == entries.end())
	{
		return entries.insert(pair<const string,string>(key,string("0"))).first;
	}
	else
	{
		return it;
	}
}

string &OpV1_GameData::getEntryText(const string &key)
{
	return getEntryIterator(key)->second;
}

void OpV1_GameData::setEntryText(const string &key, const string &text)
{
	map<string,string>::iterator it = entries.find(key);
	if (it == entries.end())
	{
		entries.insert(pair<const string,string>(key,text));
	}
	else
	{
		it->second = text;
	}
}

void OpV1_GameData::addToEntry(const string &key, int amount)
{
	map<string,string>::iterator it = getEntryIterator(key);
	it->second = intToString(stringToInt(it->second) + amount);
}

string OpV1_GameData::generateID()
{
	string id;
	do
	{
		string numbers("123456789");
		string letters("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		id += opw8_randomChar(numbers);
		id.push_back(opw8_randomChar(letters));
	}
	while (OpU8a_containsString(recentIDs,id));
	recentIDs.push_back(id);
	if (recentIDs.size() >= 10)
		OpV1_eraseAt(recentIDs,0);
	return id;
}

//==================================================================
// node graph collection
//==================================================================

class OpV1_Node;	// NOTE: placeholder name

class OpV1_Handle	// NOTE: placeholder name
{
public:
	int ID;
	OpV1_Node *operator->() const;	// 0x9b7910
};

class OpV1_Node	// NOTE: placeholder name
{
public:
	int unknown00;
	int type;
	int sub;
	vector<OpV1_Handle> children;
};

bool OpV1_addUnique(vector<OpV1_Handle> &v, OpV1_Handle h);	// NOTE: placeholder name (0x9d30e0)
bool OpV1_contains(vector<OpV1_Handle> &v, OpV1_Handle h);	// NOTE: placeholder name

void OpV1_collectNodes(int type, int sub, OpV1_Handle node, vector<OpV1_Handle> &matches, vector<OpV1_Handle> &visited)	// NOTE: placeholder name
{
	if (node->type == type && (sub == -1 || node->sub == sub))
		OpV1_addUnique(matches,node);
	visited.push_back(node);
	for (unsigned int i = 0; i < node->children.size(); i++)
	{
		if (!OpV1_contains(visited,node->children[i]))
			OpV1_collectNodes(type,sub,node->children[i],matches,visited);
	}
}

//==================================================================
// colour slot table initializer
//==================================================================

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
	bool operator==(XColor color);

	void add(XColor color);	// NOTE: placeholder name
	void subtract(XColor color);	// NOTE: placeholder name
	void multiply(XColor color);	// NOTE: placeholder name
	void lerp(XColor color, float coef);	// NOTE: placeholder name
	void addAlpha(XColor color, float alpha);	// NOTE: placeholder name
	void screen(XColor color);	// NOTE: placeholder name
	void colorDodge(XColor color);	// NOTE: placeholder name
	void colorBurn(XColor color);	// NOTE: placeholder name
	void burn(XColor color);	// NOTE: placeholder name
	void overlay(XColor color);	// NOTE: placeholder name
};

struct OpV1_IntColor	// NOTE: placeholder name
{
	void set(int value_, const XColor &color_);	// NOTE: placeholder name (0x434410)

	int value;
	XColor color;
};

extern OpV1_IntColor opv1_slot_d01618;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01620;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01628;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01630;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01638;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01640;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01648;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01650;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01658;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01660;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01668;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01670;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01678;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01680;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01688;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01690;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01698;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d016a0;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d016a8;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d016b0;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d016b8;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d016c0;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d016c8;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d016d0;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d016d8;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d016e0;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d016e8;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d016f0;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d016f8;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01700;	// NOTE: placeholder name
extern OpV1_IntColor opv1_slot_d01708;	// NOTE: placeholder name
extern XColor &opv1_ref_cefdd4;	// NOTE: placeholder name
extern XColor &opv1_ref_cf0d3c;	// NOTE: placeholder name
extern XColor &opv1_ref_cf281c;	// NOTE: placeholder name
extern XColor &opv1_ref_cf2970;	// NOTE: placeholder name
extern XColor &opv1_ref_cf63b0;	// NOTE: placeholder name
extern XColor &opv1_ref_cfabbc;	// NOTE: placeholder name
extern XColor &opv1_ref_cfd2fc;	// NOTE: placeholder name
extern XColor &opv1_ref_d20618;	// NOTE: placeholder name
extern XColor &opv1_ref_d20b78;	// NOTE: placeholder name
extern XColor &opv1_ref_d21b20;	// NOTE: placeholder name
extern XColor &opv1_ref_d223c4;	// NOTE: placeholder name
extern XColor &opv1_ref_d23094;	// NOTE: placeholder name
extern XColor &opv1_ref_d25e0c;	// NOTE: placeholder name
extern XColor &opv1_ref_d25f60;	// NOTE: placeholder name
extern XColor &opv1_ref_d25f74;	// NOTE: placeholder name
extern XColor &opv1_ref_d2ac94;	// NOTE: placeholder name
extern XColor &opv1_ref_d2b284;	// NOTE: placeholder name
extern XColor &opv1_ref_d2c418;	// NOTE: placeholder name
extern XColor &opv1_ref_d2f34c;	// NOTE: placeholder name
extern XColor &opv1_ref_d32dfc;	// NOTE: placeholder name
extern XColor &opv1_ref_d3579c;	// NOTE: placeholder name
extern XColor &opv1_ref_d35be0;	// NOTE: placeholder name
extern XColor &opv1_ref_d38644;	// NOTE: placeholder name
extern XColor opv1_color_d216f8;	// NOTE: placeholder name
extern XColor opv1_color_d216fb;	// NOTE: placeholder name
extern XColor opv1_color_d216fe;	// NOTE: placeholder name
extern XColor opv1_color_d21701;	// NOTE: placeholder name
extern XColor opv1_color_d21704;	// NOTE: placeholder name
extern XColor opv1_color_d21707;	// NOTE: placeholder name
extern XColor opv1_color_d2170a;	// NOTE: placeholder name
extern XColor opv1_color_d2170d;	// NOTE: placeholder name
extern XColor opv1_color_d21710;	// NOTE: placeholder name
extern XColor opv1_color_d21713;	// NOTE: placeholder name
extern XColor opv1_color_d21716;	// NOTE: placeholder name

void opv1_initColorSlots_434440()	// NOTE: placeholder name
{
	opv1_slot_d01618.set(0x25,opv1_ref_d3579c);
	opv1_slot_d01620.set(0x24,opv1_ref_d25e0c);
	opv1_slot_d01628.set(0x24,opv1_ref_d20618);
	opv1_slot_d01630.set(0x25,opv1_ref_d2b284);
	opv1_slot_d01638.set(0x26,opv1_ref_d35be0);
	opv1_slot_d01640.set(0x26,opv1_ref_d2f34c);
	opv1_slot_d01648.set(0x2a,opv1_ref_cf281c);
	opv1_slot_d01650.set(0x2a,opv1_ref_d23094);
	opv1_slot_d01658.set(0x2a,opv1_ref_d2f34c);
	opv1_slot_d01660.set(0x3d,opv1_ref_d2f34c);
	opv1_slot_d01668.set(0x3d,opv1_ref_d25f60);
	opv1_slot_d01670.set(0x3d,opv1_ref_d21b20);
	opv1_slot_d01678.set(0x3d,opv1_ref_d223c4);
	opv1_slot_d01680.set(0x3d,opv1_ref_cf63b0);
	opv1_slot_d01688.set(0x21,opv1_ref_d3579c);
	opv1_slot_d01690.set(0x21,opv1_ref_cfd2fc);
	opv1_slot_d01698.set(0x21,opv1_ref_d25e0c);
	opv1_slot_d016a0.set(0x21,opv1_ref_cf281c);
	opv1_slot_d016a8.set(0x21,opv1_ref_d2f34c);
	opv1_slot_d016b0.set(0x21,opv1_ref_d32dfc);
	opv1_slot_d016b8.set(0x5b,opv1_ref_d2b284);
	opv1_slot_d016c0.set(0x5d,opv1_ref_cfd2fc);
	opv1_slot_d016c8.set(0x5b,opv1_ref_d23094);
	opv1_slot_d016d0.set(0x5d,opv1_ref_d21b20);
	opv1_slot_d016d8.set(0x5d,opv1_ref_d2f34c);
	opv1_slot_d016e0.set(0x7c,opv1_ref_d3579c);
	opv1_slot_d016e8.set(0x2f,opv1_ref_d25f60);
	opv1_slot_d016f0.set(0x2f,opv1_ref_d2f34c);
	opv1_slot_d016f8.set(0x2f,opv1_ref_cf281c);
	opv1_slot_d01700.set(0x2f,opv1_ref_d3579c);
	opv1_slot_d01708.set(0x2f,opv1_ref_d3579c);
	opv1_color_d216f8 = opv1_ref_cfabbc;
	opv1_color_d216fb = opv1_ref_cf2970;
	opv1_color_d216fe = opv1_ref_cfd2fc;
	opv1_color_d21701 = opv1_ref_cefdd4;
	opv1_color_d21704 = opv1_ref_d3579c;
	opv1_color_d21707 = opv1_ref_d38644;
	opv1_color_d2170a = opv1_ref_d20b78;
	opv1_color_d2170d = opv1_ref_d25f74;
	opv1_color_d21710 = opv1_ref_d2ac94;
	opv1_color_d21713 = opv1_ref_d2c418;
	opv1_color_d21716 = opv1_ref_cf0d3c;
}

//==================================================================
// cell background blending
//==================================================================

class OpV1_Cell	// NOTE: placeholder name
{
public:
	void blendBack(XColor color, int flag);	// NOTE: placeholder name

	char pad00[0xf];
	XColor back;
};

void OpV1_Cell::blendBack(XColor color, int flag)
{
	switch (flag & 0xff)
	{
		case 0: break;
		case 1: back = color; break;
		case 2: back.add(color); break;
		case 3: back.subtract(color); break;
		case 4: back.multiply(color); break;
		case 5: back.lerp(color,(flag >> 8) / 255.0); break;
		case 6: back.addAlpha(color,(flag >> 8) / 255.0); break;
		case 7: back.screen(color); break;
		case 8: back.colorDodge(color); break;
		case 9: back.colorBurn(color); break;
		case 10: back.burn(color); break;
		case 11: back.overlay(color); break;
	}
}
