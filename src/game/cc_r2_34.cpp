// cc_r2_34: STL helper instantiations (std::_Cons_val / _Dest_val / _Move / _Umove) for various
// game element types, plus one vector<MapRecord*> stream writer.
// NOTE: all element types are placeholders named after the address of their copy constructor.
#include <vector>
#include <string>
#include <ostream>

using namespace std;

struct E16_9f4d50 { char pad[0x10]; E16_9f4d50(const E16_9f4d50 &); };		// NOTE: placeholder name
struct E20_9f4ae0 { char pad[0x20]; E20_9f4ae0(const E20_9f4ae0 &); ~E20_9f4ae0(); };	// NOTE: placeholder name
struct E60_448c40 { char pad[0x60]; E60_448c40(const E60_448c40 &); };		// NOTE: placeholder name
struct E16_9e9920 { char pad[0x10]; E16_9e9920(const E16_9e9920 &); };		// NOTE: placeholder name
struct E16_9b35b0 { char pad[0x10]; E16_9b35b0(const E16_9b35b0 &); ~E16_9b35b0(); };	// NOTE: placeholder name
struct E16_40a720 { char pad[0x10]; E16_40a720(const E16_40a720 &); };		// NOTE: placeholder name
struct E34_9f4960 { char pad[0x34]; E34_9f4960(const E34_9f4960 &); };		// NOTE: placeholder name
struct E54_9f4a00 { char pad[0x54]; E54_9f4a00(const E54_9f4a00 &); };		// NOTE: placeholder name
struct E40_4ccdc0 { char pad[0x40]; ~E40_4ccdc0(); };							// NOTE: placeholder name
struct E24_9f4b50 { char pad[0x24]; E24_9f4b50(const E24_9f4b50 &); };		// NOTE: placeholder name
struct E16_9e9cb0 { char pad[0x10]; E16_9e9cb0(const E16_9e9cb0 &); };		// NOTE: placeholder name
struct E16_9f5990 { char pad[0x10]; E16_9f5990(const E16_9f5990 &); };		// NOTE: placeholder name
struct E4_9e8350 { int a; };												// NOTE: placeholder name
struct E16_40b130 { char pad[0x10]; E16_40b130(const E16_40b130 &); };		// NOTE: placeholder name
struct EV16_9f05a0 { char pad[0x10]; EV16_9f05a0 &operator=(const EV16_9f05a0 &); };	// NOTE: placeholder name
struct E8_9f05e0 { int a; int b; };											// NOTE: placeholder name

template void std::_Cons_val<allocator<E16_9f4d50>, E16_9f4d50, const E16_9f4d50 &>(allocator<E16_9f4d50> &, E16_9f4d50 *, const E16_9f4d50 &);
template void std::_Cons_val<allocator<E20_9f4ae0>, E20_9f4ae0, const E20_9f4ae0 &>(allocator<E20_9f4ae0> &, E20_9f4ae0 *, const E20_9f4ae0 &);
template void std::_Dest_val<allocator<E20_9f4ae0>, E20_9f4ae0>(allocator<E20_9f4ae0> &, E20_9f4ae0 *);
template void std::_Cons_val<allocator<E20_9f4ae0>, E20_9f4ae0, E20_9f4ae0>(allocator<E20_9f4ae0> &, E20_9f4ae0 *, E20_9f4ae0 &&);
template void std::_Cons_val<allocator<E60_448c40>, E60_448c40, E60_448c40>(allocator<E60_448c40> &, E60_448c40 *, E60_448c40 &&);
template void std::_Cons_val<allocator<E60_448c40>, E60_448c40, const E60_448c40 &>(allocator<E60_448c40> &, E60_448c40 *, const E60_448c40 &);
template void std::_Cons_val<allocator<E16_9e9920>, E16_9e9920, E16_9e9920>(allocator<E16_9e9920> &, E16_9e9920 *, E16_9e9920 &&);
template void std::_Cons_val<allocator<E16_9b35b0>, E16_9b35b0, E16_9b35b0>(allocator<E16_9b35b0> &, E16_9b35b0 *, E16_9b35b0 &&);
template void std::_Cons_val<allocator<E16_9b35b0>, E16_9b35b0, const E16_9b35b0 &>(allocator<E16_9b35b0> &, E16_9b35b0 *, const E16_9b35b0 &);
template void std::_Dest_val<allocator<E16_9b35b0>, E16_9b35b0>(allocator<E16_9b35b0> &, E16_9b35b0 *);
template void std::_Cons_val<allocator<E16_40a720>, E16_40a720, E16_40a720>(allocator<E16_40a720> &, E16_40a720 *, E16_40a720 &&);
template void std::_Cons_val<allocator<E16_40a720>, E16_40a720, const E16_40a720 &>(allocator<E16_40a720> &, E16_40a720 *, const E16_40a720 &);
template void std::_Cons_val<allocator<E34_9f4960>, E34_9f4960, const E34_9f4960 &>(allocator<E34_9f4960> &, E34_9f4960 *, const E34_9f4960 &);
template void std::_Cons_val<allocator<E54_9f4a00>, E54_9f4a00, const E54_9f4a00 &>(allocator<E54_9f4a00> &, E54_9f4a00 *, const E54_9f4a00 &);
template void std::_Dest_val<allocator<E40_4ccdc0>, E40_4ccdc0>(allocator<E40_4ccdc0> &, E40_4ccdc0 *);
template void std::_Cons_val<allocator<E24_9f4b50>, E24_9f4b50, E24_9f4b50>(allocator<E24_9f4b50> &, E24_9f4b50 *, E24_9f4b50 &&);
template void std::_Cons_val<allocator<E24_9f4b50>, E24_9f4b50, const E24_9f4b50 &>(allocator<E24_9f4b50> &, E24_9f4b50 *, const E24_9f4b50 &);
template void std::_Cons_val<allocator<E4_9e8350>, E4_9e8350, E4_9e8350>(allocator<E4_9e8350> &, E4_9e8350 *, E4_9e8350 &&);
template void std::_Cons_val<allocator<E16_9e9cb0>, E16_9e9cb0, E16_9e9cb0>(allocator<E16_9e9cb0> &, E16_9e9cb0 *, E16_9e9cb0 &&);
template void std::_Cons_val<allocator<E16_9f5990>, E16_9f5990, E16_9f5990>(allocator<E16_9f5990> &, E16_9f5990 *, E16_9f5990 &&);
template void std::_Cons_val<allocator<E8_9f05e0>, E8_9f05e0, E8_9f05e0>(allocator<E8_9f05e0> &, E8_9f05e0 *, E8_9f05e0 &&);

template E4_9e8350 *std::_Move<E4_9e8350 *, E4_9e8350 *>(E4_9e8350 *, E4_9e8350 *, E4_9e8350 *);
template EV16_9f05a0 *std::_Move<EV16_9f05a0 *, EV16_9f05a0 *>(EV16_9f05a0 *, EV16_9f05a0 *, EV16_9f05a0 *);
template E16_9f5990 *vector<E16_9f5990>::_Umove<E16_9f5990 *>(E16_9f5990 *, E16_9f5990 *, E16_9f5990 *);
template E16_40b130 *vector<E16_40b130>::_Umove<E16_40b130 *>(E16_40b130 *, E16_40b130 *, E16_40b130 *);
template E16_40b130 *vector<E16_40b130>::_Umove<_Vector_const_iterator<_Vector_val<E16_40b130, allocator<E16_40b130> > > >(_Vector_const_iterator<_Vector_val<E16_40b130, allocator<E16_40b130> > >, _Vector_const_iterator<_Vector_val<E16_40b130, allocator<E16_40b130> > >, E16_40b130 *);
template int *vector<int>::_Umove<_Vector_const_iterator<_Vector_val<int, allocator<int> > > >(_Vector_const_iterator<_Vector_val<int, allocator<int> > >, _Vector_const_iterator<_Vector_val<int, allocator<int> > >, int *);

class MapRecord
{
public:
	void unknown455b60(ostream &os);	// NOTE: placeholder name
};

void unknown_9e40e0(ostream &os, vector<MapRecord *> &records)	// NOTE: placeholder name
{
	unsigned int count = records.size();
	os.write((const char *)&count, 4);
	for (unsigned int i = 0; i < count; i++)
	{
		records[i]->unknown455b60(os);
	}
}
