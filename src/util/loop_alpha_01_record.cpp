// Clone the unsigned-vector implementation for the constructor-array callbacks.
#define vector LA1PrivateVector
#define _Vector_val LA1PrivateVectorVal
#define _Vector_iterator LA1PrivateVectorIterator
#define _Vector_const_iterator LA1PrivateVectorConstIterator
#include <vector>
#undef vector
#undef _Vector_val
#undef _Vector_iterator
#undef _Vector_const_iterator
// NOTE: partial record layout and private aliases of real member construction/cleanup.
struct LA1Obj;
struct LA1Elem48 { char pad[48]; };
struct LA1Elem16 { char pad[16]; };
struct LA1Elem8 { char pad[8]; };
struct LA1Handle4 { int id; LA1Handle4() throw(); };
struct LA1Point8 { int x,y; LA1Point8() throw(); };
struct LA1Rect16 { int x,y,w,h; LA1Rect16() throw(); };
struct LA1Buf12 { int width,height; void *data; LA1Buf12() throw(); ~LA1Buf12() throw(); };
struct LA1String28 { char layout[28]; LA1String28() throw(); ~LA1String28() throw(); };
template<class T> struct LA1Vector { char layout[16]; LA1Vector() throw(); ~LA1Vector() throw(); };
struct LA1Map16 { char layout[16]; LA1Map16(); ~LA1Map16() throw(); };
struct LA1Record46ef00	// NOTE: placeholder name
{
	LA1Record46ef00();
	~LA1Record46ef00();
	bool hasHandleAt(int key);	// NOTE: placeholder name
	bool hasAnyObjects();	// NOTE: placeholder name
	bool hasObjectID(int id);	// NOTE: placeholder name
	bool isLastOfType3();	// NOTE: placeholder name
	bool isFlagEnabledA();	// NOTE: placeholder name
	bool isFlagEnabledB();	// NOTE: placeholder name
	bool isFlagEnabledC();	// NOTE: placeholder name
	int getTier();	// NOTE: placeholder name
	const LA1String28 &getEntryText(const LA1String28 &key);	// NOTE: placeholder name (0x46f6d0)

	char			pad0[0x4];
	LA1String28	s4;
	char			pad20[0x4];
	LA1Handle4	prop24;
	LA1Handle4	prop28;
	LA1Vector<LA1Handle4>	v2c;
	LA1Vector<LA1Elem48>	v3c;
	LA1Vector<int>	v4c;
	char			pad5c[0x4];
	LA1Vector<int>	v60;
	LA1Vector<int>	v70;
	LA1Vector<LA1Vector<LA1Obj*> >	v80;
	LA1Vector<LA1Vector<LA1Obj*> >	v90;
	LA1Vector<LA1String28>	va0;
	LA1Vector<int>	vb0;
	LA1Vector<int>	vc0;
	LA1Vector<LA1String28>	vd0;
	LA1Vector<int>	ve0;
	LA1Vector<int>	vf0;
	LA1Map16	map100;
	LA1Buf12	buf110;
	std::LA1PrivateVector<unsigned int>	arr11c[15];
	LA1Vector<int>	v20c;
	LA1Vector<LA1Handle4>	v21c;
	LA1Vector<LA1String28>	v22c;
	LA1Vector<int>	v23c;
	char			pad24c[0x30];
	LA1Handle4	prop27c;
	char			pad280[0x8];
	LA1Rect16	rect288;
	LA1Rect16	rect298;
	char			pad2a8[0x8];
	int		i2b0;
	char			pad2b4[0x30];
	LA1Vector<int>	v2e4;
	int		i2f4;
	char			pad2f8[0x20];
	LA1Vector<LA1String28>	v318;
	LA1Vector<int>	v328;
	char			pad338[0x4];
	LA1Vector<int>	v33c;
	char			pad34c[0x4];
	LA1Point8	point350;
	char			pad358[0x20];
	LA1Handle4	prop378;
	char			pad37c[0x4];
	LA1Handle4	prop380;
	LA1Handle4	prop384;
	char			pad388[0x18];
	LA1Vector<LA1Handle4>	v3a0;
	LA1Vector<LA1Point8>	v3b0;
	LA1Vector<LA1Point8>	v3c0;
	LA1Vector<int>	v3d0;
	LA1Vector<int>	v3e0;
	char			pad3f0[0x1c];
	LA1Point8	point40c;
	LA1Vector<LA1Elem8>	v414;
	LA1Vector<int>	v424;
	LA1Vector<int>	v434;
	LA1Vector<LA1String28>	v444;

};

LA1Record46ef00::LA1Record46ef00()
{
}
