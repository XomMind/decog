// alpha2_12: CPartLabel constructor (0x4a3020): the small value label shown beside a part in the parts list
//	(integrity, charges, turns, ...), built per label type.
// NOTE: placeholder names / placeholder layout throughout; private aliases for mapped callees.
#include <string>
#include <vector>
using std::string;
using std::vector;

struct A2LColor
{
	unsigned char r, g, b, a;
	A2LColor(const A2LColor &other) throw();	// 0x411e30
};
struct A2LItem
{
	int unknown457ca0() throw();
	int unknown4580c0() throw();
	int unknown458260() throw();
	int unknown4582a0() throw();
	int getEffectValue_457be0(int effect) throw();
	int unknown45cb30() throw();
	int turnsLeft_577ad0() throw();
	int unknown577fd0();
	int unknown578070() throw();
	int unknown578e90(bool flag);
	int unknown578f20(bool a, bool b);
};
struct A2LHI	// HItem
{
	int id;
	A2LItem *get_9b65b0() const throw();
};
struct A2LMap
{
	vector<int> &list_463d80() throw();
	int getTurn_464270() throw();
	int unknown4644d0() throw();
	int capacity_7161e0();
};
struct A2LMapView
{
	int unknown8054b0(bool flag);
};
extern A2LMap *a2l_map_cefc4c;
extern A2LMapView *a2l_mapView_cec054;
extern A2LColor &a2l_color_cfe674;
extern int a2l_widths_bcc540[];
extern string a2l_prefixes_cfb1e0[];
extern string a2l_animations_d02da8[];
extern int a2l_value_d25464;
string a2l_intToString_4051f0(int value);

class A2LConsole	// Console
{
public:
	A2LConsole(void *parent, int width, int height, int x, int y, int font, bool hidden, int layer);	// 0x48c060
	virtual ~A2LConsole();
	void setFore_417b00(A2LColor color);
	void print_4181d0(int x, int y, const string &text);
	void animate_48c3f0(string name);
	char pad4[0x6c - 4];
};

class A2LLabel : public A2LConsole	// CPartLabel
{
public:
	A2LLabel(void *parent, A2LHI item, int x, int type_);
	virtual ~A2LLabel();
	int getMode_4a6cb0();
	int getItemValue_4a7db0(A2LHI item);

	int type;	// +0x6c
	int value;	// +0x70
};

A2LLabel::A2LLabel(void *parent, A2LHI item, int x, int type_)
	: A2LConsole(parent,a2l_widths_bcc540[type_],1,x,0,0,false,-1)
{
	type = type_;
	value = 0;
	string text = a2l_prefixes_cfb1e0[type];
	switch (type)
	{
		case 0:
			value = item.get_9b65b0()->unknown457ca0();
			text += value > 99 ? string("**") : value > 9 ? a2l_intToString_4051f0(value) : "0" + a2l_intToString_4051f0(value);
			text += "% ";
			break;
		case 1:
			value = item.get_9b65b0()->turnsLeft_577ad0();
			text += value > 9 ? string("*") : a2l_intToString_4051f0(value);
			text += " ";
			break;
		case 4:
			text += (item.get_9b65b0()->unknown4580c0() > 9 ? string("*") : a2l_intToString_4051f0(item.get_9b65b0()->unknown4580c0())) + " ";
			break;
		case 5:
			value = item.get_9b65b0()->unknown458260();
			text += value > 9 ? string("*") : a2l_intToString_4051f0(value);
			text += " ";
			break;
		case 10:
			value = item.get_9b65b0()->unknown578e90(false);
			text += a2l_intToString_4051f0(value);
			text += "%";
			break;
		case 15:
		case 16:
			value = item.get_9b65b0()->unknown4582a0();
			text += value > 99 ? string("**") : value > 9 ? a2l_intToString_4051f0(value) : "0" + a2l_intToString_4051f0(value);
			text += " ";
			break;
		case 17:
			value = item.get_9b65b0()->unknown4582a0();
			text += value > 999 ? string("***") : value > 99 ? a2l_intToString_4051f0(value) : value > 9 ? "0" + a2l_intToString_4051f0(value) : "00" + a2l_intToString_4051f0(value);
			text += " ";
			break;
		case 8:
			value = a2l_map_cefc4c->list_463d80().size();
			text += value > 9 ? string("*") : a2l_intToString_4051f0(value);
			text += " (";
			if (value == 8)
				text += "MAX)";
			else
			{
				int capacity = a2l_map_cefc4c->capacity_7161e0();
				text += capacity > 999 ? string("***") : capacity > 99 ? a2l_intToString_4051f0(capacity) : capacity > 9 ? "0" + a2l_intToString_4051f0(capacity) : "00" + a2l_intToString_4051f0(capacity);
				text += ") ";
			}
			break;
		case 18:
			value = a2l_mapView_cec054->unknown8054b0(true);
			text += value > 9 ? string("*") : a2l_intToString_4051f0(value);
			text += " ";
			break;
		case 19:
			value = getMode_4a6cb0();
			text += value == 0 ? string("L") : value == 6 ? string("H") : a2l_intToString_4051f0(value);
			text += " ";
			break;
		case 20:
			value = a2l_map_cefc4c->getTurn_464270();
			break;
		case 21:
			value = item.get_9b65b0()->unknown578f20(false,false);
			text += value > 999 ? string("***") : value > 99 ? a2l_intToString_4051f0(value) : value > 9 ? "0" + a2l_intToString_4051f0(value) : "00" + a2l_intToString_4051f0(value);
			text += " ";
			break;
		case 22:
			value = item.get_9b65b0()->getEffectValue_457be0(68);
			text += value > 9 ? string("*") : a2l_intToString_4051f0(value);
			text += " ";
			break;
		case 24:
			value = item.get_9b65b0()->getEffectValue_457be0(71);
			text += value > 99 ? string("**") : value > 9 ? a2l_intToString_4051f0(value) : "0" + a2l_intToString_4051f0(value == -1 ? 0 : value);
			text += " ";
			break;
		case 25:
			value = item.get_9b65b0()->getEffectValue_457be0(118) - item.get_9b65b0()->getEffectValue_457be0(119);
			text += value > 99 ? string("**") : value > 9 ? a2l_intToString_4051f0(value) : value == 0 ? string("OK") : "0" + a2l_intToString_4051f0(value);
			text += " ";
			break;
		case 26:
			value = getItemValue_4a7db0(item);
			if (value == -1)
				text += "??? ";
			else
			{
				text += value > 999 ? string("***") : value > 99 ? a2l_intToString_4051f0(value) : value > 9 ? "0" + a2l_intToString_4051f0(value) : "00" + a2l_intToString_4051f0(value);
				text += " ";
			}
			break;
		case 27:
		case 30:
		case 33:
			value = item.get_9b65b0()->unknown577fd0();
			text += a2l_intToString_4051f0(value);
			text += " ";
			break;
		case 29:
		case 32:
		case 35:
			value = item.get_9b65b0()->unknown578070();
			text += a2l_intToString_4051f0(value);
			text += " ";
			break;
		case 38:
			value = a2l_map_cefc4c->unknown4644d0();
			text += value > 9 ? string("*") : a2l_intToString_4051f0(value);
			text += " ";
			break;
		case 39:
			value = item.get_9b65b0()->unknown45cb30();
			text += value > 999 ? string("***") : value > 99 ? a2l_intToString_4051f0(value) : value > 9 ? "0" + a2l_intToString_4051f0(value) : "00" + a2l_intToString_4051f0(value);
			text += " ";
			break;
		case 41:
			value = a2l_value_d25464;
			text += value > 99 ? string("**") : value > 9 ? a2l_intToString_4051f0(value) : "0" + a2l_intToString_4051f0(value);
			break;
	}
	setFore_417b00(a2l_color_cfe674);
	print_4181d0(0,0,text);
	animate_48c3f0(a2l_animations_d02da8[type]);
}
