// team_c_12: std::iter_swap and vector iterator difference instances over placeholder element types
// NOTE: all element types are placeholders (distinct names keep the COMDATs unique to this file)
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct OpC_Sw16 { int a, b, c, d; OpC_Sw16(const OpC_Sw16 &o); OpC_Sw16 &operator=(const OpC_Sw16 &o); };
struct OpC_SwPt { int x, y; OpC_SwPt(const OpC_SwPt &o); OpC_SwPt &operator=(const OpC_SwPt &o); };
struct OpC_Sw12 { int a, b, c; OpC_Sw12(const OpC_Sw12 &o); OpC_Sw12 &operator=(const OpC_Sw12 &o); };
struct OpC_Sw16b { int a, b, c, d; OpC_Sw16b(const OpC_Sw16b &o); OpC_Sw16b &operator=(const OpC_Sw16b &o); };
struct OpC_Sw4 { int v; OpC_Sw4(const OpC_Sw4 &o); OpC_Sw4 &operator=(const OpC_Sw4 &o); };
struct OpC_SwV { vector<int> v; };
template void std::iter_swap<OpC_Sw16 *, OpC_Sw16 *>(OpC_Sw16 *, OpC_Sw16 *);
template void std::iter_swap<OpC_SwPt *, OpC_SwPt *>(OpC_SwPt *, OpC_SwPt *);
template void std::iter_swap<OpC_Sw12 *, OpC_Sw12 *>(OpC_Sw12 *, OpC_Sw12 *);
template void std::iter_swap<OpC_Sw16b *, OpC_Sw16b *>(OpC_Sw16b *, OpC_Sw16b *);
template void std::iter_swap<OpC_Sw4 *, OpC_Sw4 *>(OpC_Sw4 *, OpC_Sw4 *);
template void std::iter_swap<OpC_SwV *, OpC_SwV *>(OpC_SwV *, OpC_SwV *);
template void std::iter_swap<vector<char> *, vector<char> *>(vector<char> *, vector<char> *);

struct OpC_It8 { int x, y; };
struct OpC_It4 { int v; };
template vector<OpC_It8>::iterator::difference_type vector<OpC_It8>::iterator::operator-(const vector<OpC_It8>::const_iterator &) const;
template vector<OpC_It4>::iterator::difference_type vector<OpC_It4>::iterator::operator-(const vector<OpC_It4>::const_iterator &) const;

// vector::_Tidy over 1- and 3-byte elements, basic_string<unsigned short>::max_size (folded bodies)
struct OpC_B1 { char c; };
struct OpC_B3 { unsigned char r, g, b; };
template void vector<OpC_B1>::_Tidy();
template void vector<OpC_B3>::_Tidy();
template basic_string<unsigned short>::size_type basic_string<unsigned short>::max_size() const;

// deleteVector<T>: delete the contents, then clear (0x9cead0)
struct OpC_VObj;	// NOTE: placeholder name
template <class T> void OpC_deleteVectorContents(vector<T*> &v);	// NOTE: placeholder name (0x9ce9e0)
template <class T> void OpC_deleteVector(vector<T*> &v)	// NOTE: placeholder name (0x9cead0)
{
	OpC_deleteVectorContents(v);
	v.clear();
}
template void OpC_deleteVector<OpC_VObj>(vector<OpC_VObj*> &v);
