//==================================================================
// STL instantiations (allocator<T> members, vector<T>::_Ucopy, implicit copy constructors)
// cc_r2_35: cluster 0x9fc8a0-0x9fcdc9
//==================================================================

#include <string>
#include <vector>
#include <memory>

using namespace std;

struct MapRecord;

// NOTE: placeholder names (Elem_<exe address of the element's copy ctor / dtor>)
struct Elem_9fca10												// 0x24 bytes
{
	int			a;
	int			b;
	string		s;
};

struct Elem_9fca50												// 0x40 bytes
{
	int			a;
	string		s;
	int			b;
	string		t;
};

struct Elem_46cbc0
{
	char		pad[0x30];
	Elem_46cbc0(const Elem_46cbc0 &);
};

#define DESTROY_ELEM(a) struct Elem_##a { int pad; ~Elem_##a(); };
DESTROY_ELEM(9b3da0)
DESTROY_ELEM(425ae0)
DESTROY_ELEM(9ffeb0)
DESTROY_ELEM(9ffee0)
DESTROY_ELEM(4b9f00)
DESTROY_ELEM(4c1430)
DESTROY_ELEM(9fff40)
DESTROY_ELEM(9fff70)
DESTROY_ELEM(a00000)
DESTROY_ELEM(46e690)
DESTROY_ELEM(9fffa0)
DESTROY_ELEM(9fffd0)
DESTROY_ELEM(a00030)
DESTROY_ELEM(a00060)
DESTROY_ELEM(a00090)

#define CONSTRUCT_ELEM(a, n) struct Elem_##a { char pad[n]; Elem_##a(const Elem_##a &); };
CONSTRUCT_ELEM(9c3af0, 0x10)
CONSTRUCT_ELEM(9b3730, 0x14)
CONSTRUCT_ELEM(9c2320, 0x40)
CONSTRUCT_ELEM(9c5cd0, 0x10)
CONSTRUCT_ELEM(9c61e0, 0x10)

struct cc_r2_35_vector : vector<MapRecord *>
{
	MapRecord **ucopy(MapRecord * const *first, MapRecord * const *last, MapRecord **dest);
};

MapRecord **cc_r2_35_vector::ucopy(MapRecord * const *first, MapRecord * const *last, MapRecord **dest)
{
	return _Ucopy(first, last, dest);
}

void cc_r2_35_instantiate(Elem_9fca10 &e1, Elem_9fca50 &e2, Elem_46cbc0 &e3)
{
	Elem_9fca10 c1(e1);
	Elem_9fca50 c2(e2);
	allocator<Elem_9fca50> a2;
	a2.construct(&e2, (const Elem_9fca50 &)e2);
	allocator<Elem_46cbc0> a3;
	a3.construct(&e3, (const Elem_46cbc0 &)e3);
	_Construct(&e2, (const Elem_9fca50 &)e2);
	_Construct(&e3, (const Elem_46cbc0 &)e3);

	allocator<vector<string> > d0;			d0.destroy(NULL);
	allocator<Elem_9b3da0> d1;				d1.destroy(NULL);
	allocator<vector<bool> > d2;			d2.destroy(NULL);
	allocator<Elem_425ae0> d3;				d3.destroy(NULL);
	allocator<Elem_9ffeb0> d4;				d4.destroy(NULL);
	allocator<Elem_9ffee0> d5;				d5.destroy(NULL);
	allocator<Elem_4b9f00> d6;				d6.destroy(NULL);
	allocator<Elem_4c1430> d7;				d7.destroy(NULL);
	allocator<Elem_9fff40> d8;				d8.destroy(NULL);
	allocator<Elem_9fff70> d9;				d9.destroy(NULL);
	allocator<Elem_a00000> d10;				d10.destroy(NULL);
	allocator<Elem_46e690> d11;				d11.destroy(NULL);
	allocator<Elem_9fffa0> d12;				d12.destroy(NULL);
	allocator<Elem_9fffd0> d13;				d13.destroy(NULL);
	allocator<vector<int> > d14;			d14.destroy(NULL);
	allocator<Elem_a00030> d15;				d15.destroy(NULL);
	allocator<Elem_a00060> d16;				d16.destroy(NULL);
	allocator<Elem_a00090> d17;				d17.destroy(NULL);

	allocator<Elem_9c3af0> c4;				c4.construct(NULL, *(const Elem_9c3af0 *)NULL);
	allocator<Elem_9b3730> c5;				c5.construct(NULL, *(const Elem_9b3730 *)NULL);
	allocator<Elem_9c2320> c6;				c6.construct(NULL, *(const Elem_9c2320 *)NULL);
	allocator<Elem_9c5cd0> c7;				c7.construct(NULL, *(const Elem_9c5cd0 *)NULL);
	allocator<Elem_9c61e0> c8;				c8.construct(NULL, *(const Elem_9c61e0 *)NULL);
}
