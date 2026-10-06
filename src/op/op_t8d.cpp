// op_t8d: std (VS2010) template instances 0x9ee000-0x9f6000 over placeholder element types
// NOTE: placeholder names; OpT8d_* element types stand for unrecovered game types of that size/kind
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Point
{
	int x;
	int y;

	Point() throw();	// 0x453b40
	Point(const Point &p);	// 0x46ca50
	Point &operator=(const Point &p);	// 0x46ca50 (ICF with the copy ctor)
};

class HEntity
{
public:
	int ID;
	bool operator==(HEntity other) const;	// 0x9b78e0
};

struct OpT8d_H4	// NOTE: placeholder name; 4-byte class type with operator< (0x9f5830)
{
	int m0;
	bool operator<(OpT8d_H4 o) const;
};

struct OpT8d_Area	// NOTE: placeholder name; two Points, copy ctor 0x40b130
{
	Point a;
	Point b;
	OpT8d_Area(const OpT8d_Area &o);	// 0x40b130
};

typedef vector<Point>::iterator OpT8d_PointIt;
typedef vector<OpT8d_H4>::iterator OpT8d_H4It;
typedef vector<OpT8d_H4 *>::iterator OpT8d_PtrIt;
typedef vector<string>::iterator OpT8d_StrIt;
typedef vector<bool>::iterator OpT8d_BoolIt;
typedef vector<OpT8d_Area>::iterator OpT8d_AreaIt;
typedef vector<vector<bool> >::iterator OpT8d_VBIt;
typedef int (*OpT8d_ShuffleFn)(int);

template string *std::_Lower_bound<string *, string, int>(string *, string *, const string &, int *);	// 0x9ee070
template void std::random_shuffle<OpT8d_PointIt, OpT8d_ShuffleFn>(OpT8d_PointIt, OpT8d_PointIt, OpT8d_ShuffleFn &);	// 0x9ee140
template void std::vector<OpT8d_H4>::insert<OpT8d_H4It>(vector<OpT8d_H4>::const_iterator, OpT8d_H4It, OpT8d_H4It);	// 0x9ee190
template void std::random_shuffle<OpT8d_PtrIt, OpT8d_ShuffleFn>(OpT8d_PtrIt, OpT8d_PtrIt, OpT8d_ShuffleFn &);	// 0x9ee1d0
template OpT8d_PointIt std::rotate<OpT8d_PointIt>(OpT8d_PointIt, OpT8d_PointIt, OpT8d_PointIt);	// 0x9ee220
template void std::vector<OpT8d_Area>::insert<OpT8d_AreaIt>(vector<OpT8d_Area>::const_iterator, OpT8d_AreaIt, OpT8d_AreaIt);	// 0x9ee2c0
template void std::vector<Point>::_Assign<OpT8d_PointIt>(OpT8d_PointIt, OpT8d_PointIt, input_iterator_tag);	// 0x9ee300
template void std::vector<OpT8d_H4>::_Construct<OpT8d_H4It>(OpT8d_H4It, OpT8d_H4It, input_iterator_tag);	// 0x9ee4d0
template void std::_Sort<OpT8d_H4 *, int>(OpT8d_H4 *, OpT8d_H4 *, int);	// 0x9ee570
template HEntity *std::_Unique<HEntity *>(HEntity *, HEntity *);	// 0x9ee660
template void std::random_shuffle<OpT8d_H4It, OpT8d_ShuffleFn>(OpT8d_H4It, OpT8d_H4It, OpT8d_ShuffleFn &);	// 0x9ee720
template OpT8d_H4 *std::_Lower_bound<OpT8d_H4 *, OpT8d_H4, int, bool (*)(const OpT8d_H4 &, const OpT8d_H4 &)>(OpT8d_H4 *, OpT8d_H4 *, const OpT8d_H4 &, bool (*)(const OpT8d_H4 &, const OpT8d_H4 &), int *);	// 0x9ee770
template void std::random_shuffle<OpT8d_StrIt, OpT8d_ShuffleFn>(OpT8d_StrIt, OpT8d_StrIt, OpT8d_ShuffleFn &);	// 0x9ee800
template void std::vector<string>::insert<OpT8d_StrIt>(vector<string>::const_iterator, OpT8d_StrIt, OpT8d_StrIt);	// 0x9ee850
template void std::random_shuffle<OpT8d_BoolIt, OpT8d_ShuffleFn>(OpT8d_BoolIt, OpT8d_BoolIt, OpT8d_ShuffleFn &);	// 0x9ee890
template void std::_Sort<string *, int>(string *, string *, int);	// 0x9eed10
template void std::_Reverse<OpT8d_H4 **>(OpT8d_H4 **, OpT8d_H4 **, bidirectional_iterator_tag);	// 0x9ef0b0
template void std::vector<OpT8d_H4 *>::insert<OpT8d_PtrIt>(vector<OpT8d_H4 *>::const_iterator, OpT8d_PtrIt, OpT8d_PtrIt);	// 0x9ef0f0
template OpT8d_StrIt std::rotate<OpT8d_StrIt>(OpT8d_StrIt, OpT8d_StrIt, OpT8d_StrIt);	// 0x9ef130
template OpT8d_BoolIt std::rotate<OpT8d_BoolIt>(OpT8d_BoolIt, OpT8d_BoolIt, OpT8d_BoolIt);	// 0x9ef1d0
template OpT8d_PtrIt std::rotate<OpT8d_PtrIt>(OpT8d_PtrIt, OpT8d_PtrIt, OpT8d_PtrIt);	// 0x9ef5c0
template void std::_Sort<OpT8d_H4 **, int, bool (*)(OpT8d_H4 *, OpT8d_H4 *)>(OpT8d_H4 **, OpT8d_H4 **, int, bool (*)(OpT8d_H4 *, OpT8d_H4 *));	// 0x9ef660
template vector<OpT8d_H4 *>::vector(OpT8d_PtrIt, OpT8d_PtrIt);	// 0x9ef760
template void std::_Sort<OpT8d_H4 *, int, bool (*)(OpT8d_H4, OpT8d_H4)>(OpT8d_H4 *, OpT8d_H4 *, int, bool (*)(OpT8d_H4, OpT8d_H4));	// 0x9ef7f0
template OpT8d_H4 *std::_Lower_bound<OpT8d_H4 *, OpT8d_H4, int, bool (*)(OpT8d_H4, OpT8d_H4)>(OpT8d_H4 *, OpT8d_H4 *, const OpT8d_H4 &, bool (*)(OpT8d_H4, OpT8d_H4), int *);	// 0x9ef8f0
template void std::_Sort<string *, int, bool (*)(const string &, const string &)>(string *, string *, int, bool (*)(const string &, const string &));	// 0x9ef980
template void std::vector<vector<bool> >::insert<OpT8d_VBIt>(vector<vector<bool> >::const_iterator, OpT8d_VBIt, OpT8d_VBIt);	// 0x9efb10
