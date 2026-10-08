// op_v4d: std (VS2010) template instances over placeholder element types in 0x9e0000-0x9f5000.
// NOTE: placeholder names; one OpV4d_* element type per exe function instance
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;

struct Point
{
	int x;
	int y;

	Point() throw();	// 0x453b40
	Point(const Point &p);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor() throw();	// 0x411d40
	XColor(const XColor &color) throw();	// 0x411e30
	XColor &operator=(XColor color);
};

struct HEntity
{
	int ID;
	bool operator==(HEntity e) const;	// 0x9b6620
};

struct XCell
{
	int a, b, c, d, e;
	XCell();
	XCell(const XCell &cell);
	XCell &operator=(const XCell &cell);
};

struct E16_40a720
{
	int a, b, c, d;
	E16_40a720() throw();
	E16_40a720(const E16_40a720 &o) throw();
};

struct OpU8c_Rec24
{
	char pad[0x24];
	OpU8c_Rec24(const OpU8c_Rec24 &o) throw();	// 0x9f4b50
};

struct OpV4d_P4 { int a; };
struct OpV4d_P4b { int a; };
struct OpV4d_P4c { int a; };
struct OpV4d_E28 { int a, b, c, d, e, f, g; };
bool operator<(const OpV4d_E28 &a, const OpV4d_E28 &b);

struct OpV4d_T4a { int a; OpV4d_T4a(); OpV4d_T4a(const OpV4d_T4a &o); };
struct OpV4d_T4b { int a; OpV4d_T4b(); OpV4d_T4b(const OpV4d_T4b &o); };
struct OpV4d_T4c { int a; OpV4d_T4c(); OpV4d_T4c(const OpV4d_T4c &o); };
struct OpV4d_T4d { int a; OpV4d_T4d(); OpV4d_T4d(const OpV4d_T4d &o); };
struct OpV4d_T4e { int a; OpV4d_T4e(); OpV4d_T4e(const OpV4d_T4e &o); };
struct OpV4d_T4f { int a; OpV4d_T4f(); OpV4d_T4f(const OpV4d_T4f &o); };
struct OpV4d_C16a { int a, b, c, d; OpV4d_C16a(const OpV4d_C16a &o) throw(); };
struct OpV4d_C16b { int a, b, c, d; OpV4d_C16b(); OpV4d_C16b(const OpV4d_C16b &o); };

typedef bool (*OpV4d_PredP4)(const OpV4d_P4 &, const OpV4d_P4 &);
typedef bool (*OpV4d_PredP4c)(const OpV4d_P4c &, const OpV4d_P4c &);
typedef bool (*OpV4d_PredV4b)(OpV4d_P4b, OpV4d_P4b);
typedef bool (*OpV4d_PredStr)(const string &, const string &);

void OpV4d_cycleCells(XCell &a, XCell &b, XCell &c, XCell &d)	// NOTE: placeholder name
{
	XCell temp(a);
	a = b;
	b = c;
	c = d;
	d = temp;
}

template void std::_Sort<OpV4d_P4 **, int>(OpV4d_P4 **, OpV4d_P4 **, int);
template void std::_Sort<OpV4d_E28 *, int>(OpV4d_E28 *, OpV4d_E28 *, int);
template void std::_Sort<OpV4d_P4 *, int, OpV4d_PredP4>(OpV4d_P4 *, OpV4d_P4 *, int, OpV4d_PredP4);
template void std::_Sort<OpV4d_P4c *, int, OpV4d_PredP4c>(OpV4d_P4c *, OpV4d_P4c *, int, OpV4d_PredP4c);
template void std::_Sort<string *, int, OpV4d_PredStr>(string *, string *, int, OpV4d_PredStr);
template HEntity *std::_Unique<HEntity *>(HEntity *, HEntity *);
template OpV4d_P4 *std::_Lower_bound<OpV4d_P4 *, OpV4d_P4, int, OpV4d_PredP4>(OpV4d_P4 *, OpV4d_P4 *, const OpV4d_P4 &, OpV4d_PredP4, int *);
template OpV4d_P4b *std::_Lower_bound<OpV4d_P4b *, OpV4d_P4b, int, OpV4d_PredV4b>(OpV4d_P4b *, OpV4d_P4b *, const OpV4d_P4b &, OpV4d_PredV4b, int *);
template void std::_Reverse<OpV4d_P4 *>(OpV4d_P4 *, OpV4d_P4 *, bidirectional_iterator_tag);
template void std::_Reverse<OpV4d_E28 *>(OpV4d_E28 *, OpV4d_E28 *, bidirectional_iterator_tag);

template void std::vector<OpV4d_T4a>::insert<OpV4d_T4a *>(std::vector<OpV4d_T4a>::const_iterator, OpV4d_T4a *, OpV4d_T4a *);
template void std::vector<OpV4d_T4b>::insert<OpV4d_T4b *>(std::vector<OpV4d_T4b>::const_iterator, OpV4d_T4b *, OpV4d_T4b *);
template void std::vector<OpV4d_T4c>::insert<OpV4d_T4c *>(std::vector<OpV4d_T4c>::const_iterator, OpV4d_T4c *, OpV4d_T4c *);
template void std::vector<OpV4d_T4d>::insert<OpV4d_T4d *>(std::vector<OpV4d_T4d>::const_iterator, OpV4d_T4d *, OpV4d_T4d *);
template void std::vector<OpV4d_T4e>::_Assign<OpV4d_T4e *>(OpV4d_T4e *, OpV4d_T4e *, input_iterator_tag);
template void std::vector<OpV4d_T4f>::_Construct<OpV4d_T4f *>(OpV4d_T4f *, OpV4d_T4f *, input_iterator_tag);
template std::vector<OpV4d_T4a>::vector(OpV4d_T4a *, OpV4d_T4a *);
template void std::allocator<OpV4d_C16a>::construct(OpV4d_C16a *, OpV4d_C16a &&);
template void std::allocator<OpU8c_Rec24>::construct(OpU8c_Rec24 *, OpU8c_Rec24 &&);
template void std::_Uninit_def_fill_n<Point *, unsigned int, Point, allocator<Point>, Point>(Point *, unsigned int, const Point *, allocator<Point> &, Point *, _Nonscalar_ptr_iterator_tag);
template void std::_Uninit_def_fill_n<E16_40a720 *, unsigned int, E16_40a720, allocator<E16_40a720>, E16_40a720>(E16_40a720 *, unsigned int, const E16_40a720 *, allocator<E16_40a720> &, E16_40a720 *, _Nonscalar_ptr_iterator_tag);
template XColor *std::_Move<XColor *, XColor *>(XColor *, XColor *, XColor *, _Nonscalar_ptr_iterator_tag);
template OpV4d_C16b *std::move<OpV4d_C16b *, OpV4d_C16b *>(OpV4d_C16b *, OpV4d_C16b *, OpV4d_C16b *);
template vector<OpV4d_T4a>::iterator std::rotate<vector<OpV4d_T4a>::iterator>(vector<OpV4d_T4a>::iterator, vector<OpV4d_T4a>::iterator, vector<OpV4d_T4a>::iterator);
template vector<string>::iterator std::rotate<vector<string>::iterator>(vector<string>::iterator, vector<string>::iterator, vector<string>::iterator);
template vector<bool>::iterator std::rotate<vector<bool>::iterator>(vector<bool>::iterator, vector<bool>::iterator, vector<bool>::iterator);

unsigned int OpV4d_handleCounter;	// NOTE: placeholder name, 0xcefa6c

struct OpV4d_Handle	// NOTE: placeholder name
{
	unsigned int index : 16;
	unsigned int generation : 16;

	void OpV4d_assign(unsigned int index_);
};

void OpV4d_Handle::OpV4d_assign(unsigned int index_)
{
	OpV4d_handleCounter++;
	if (OpV4d_handleCounter > 0xffff)
		OpV4d_handleCounter = 1;
	index = index_;
	generation = OpV4d_handleCounter;
}

// Private handle type: vector<HProp>::const_iterator::operator== is paired with another exe copy (via the mapped
// operator!= 0x9b8e00), but this function calls the one at 0x9f6380.
class OpV4d_HProp	// NOTE: placeholder name (HProp)
{
public:
	int ID;
	bool operator<(OpV4d_HProp o) const;	// 0x9f5830
	bool operator!=(OpV4d_HProp o) const;	// 0x9b6510
};

class OpU5_Map	// NOTE: placeholder name
{
public:
	void unknown9e29b0(vector<OpV4d_HProp> *list, OpV4d_HProp prop);	// NOTE: placeholder name
};

void OpU5_Map::unknown9e29b0(vector<OpV4d_HProp> *list, OpV4d_HProp prop)
{
	vector<OpV4d_HProp>::iterator it = lower_bound(list->begin(),list->end(),prop);
	if (it == list->end() || *it != prop)
		list->insert(it,prop);
}

struct MapRecord
{
	int pad0[9];
	string name;
};

struct OpV4d_Trivial { int a; };

void OpV4d_deleteMapRecords(vector<OpV4d_Trivial *> &records)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < records.size(); i++)
		delete records[i];
}

int OpV4d_findMapRecord(vector<MapRecord *> &records, const string &name)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->name == name)
			return i;
	}
	return -1;
}
