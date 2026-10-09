// op_u8c: matched functions in 0x9ee000-0x9fa000
#include <string>
#include <vector>
#include <istream>
#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;

	Point();
	Point(const Point &p) throw();	// 0x46ca50
	Point &operator=(const Point &p);	// 0x46ca50
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();	// 0x411e30
	XColor &operator=(XColor color);	// 0x411f10
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(const Rect &rect);	// 0x40a720
	Rect &operator=(const Rect &rect);	// NOTE: folded with the copy ctor (0x40a720)
};

struct E8_9b3130	// NOTE: placeholder name; element of the vectors copied by vector::operator= 0x9b3130 (distinct from lead/stl_a.cpp E8_0)
{
	char pad[8];
	E8_9b3130 &operator=(const E8_9b3130 &e);	// NOTE: the exe assigns these elements with a call (_Copy_impl 0x9efd30); copies stay inline (construct 0x9f05e0)
};

struct OpU8c_Area	// NOTE: placeholder name
{
	Point first;
	Point second;

	OpU8c_Area(const OpU8c_Area &a);	// 0x40b130
};

class AsciiImage
{
public:
	~AsciiImage();
	AsciiImage &operator=(const AsciiImage &image);	// 0x9d7c20

	vector<void*> layers;
};

struct OpU8c_Blob1c	// NOTE: placeholder name
{
	char pad[0x1c];

	OpU8c_Blob1c &operator=(const OpU8c_Blob1c &o);
};

struct OpR6_KA_12_0	// NOTE: placeholder name, same layout as in op_r6_ka.cpp
{
	int m0;
	int m4;
	int m8;
	OpR6_KA_12_0 &operator=(const OpR6_KA_12_0 &o);
};

void OpT8a_readInts(istream &in, vector<int> &v);	// NOTE: placeholder name, defined in op_t8a.cpp
template <class T> void readBinary(istream &stream, T *value);	// 0x9d8480 (int), NOTE: placeholder name

struct OpU8c_IntLists	// NOTE: placeholder name
{
	vector<int> list0;
	vector<int> list1;
	int value;

	OpU8c_IntLists(istream &in);
};

OpU8c_IntLists::OpU8c_IntLists(istream &in)	// 0x9f58d0
{
	OpT8a_readInts(in,list0);
	OpT8a_readInts(in,list1);
	readBinary(in,&value);
}

struct OpU8c_Rec84	// NOTE: placeholder name
{
	char flag0;
	int unknown04;
	int unknown08;
	int unknown0c;
	int unknown10;
	Point point14;
	Point point1c;
	Point point24;
	vector<OpR6_KA_12_0> list2c;
	Point point3c;
	Point point44;
	Point point4c;
	Point point54;
	Point point5c;
	Point point64;
	Point point6c;
	Point point74;
	Point point7c;

	OpU8c_Rec84(const OpU8c_Rec84 &o);
};

OpU8c_Rec84::OpU8c_Rec84(const OpU8c_Rec84 &o)	// 0x9f47e0
	: flag0		(o.flag0)
	, unknown04	(o.unknown04)
	, unknown08	(o.unknown08)
	, unknown0c	(o.unknown0c)
	, unknown10	(o.unknown10)
	, point14	(o.point14)
	, point1c	(o.point1c)
	, point24	(o.point24)
	, list2c	(o.list2c)
	, point3c	(o.point3c)
	, point44	(o.point44)
	, point4c	(o.point4c)
	, point54	(o.point54)
	, point5c	(o.point5c)
	, point64	(o.point64)
	, point6c	(o.point6c)
	, point74	(o.point74)
	, point7c	(o.point7c)
{
}

struct OpU8c_RecAC	// NOTE: placeholder name
{
	char flag0;
	int unknown04;
	int unknown08;
	int unknown0c;
	int unknown10;
	string name14;
	string name30;
	char flag4c;
	string name50;
	int unknown6c;
	vector<OpR6_KA_12_0> list70;
	int unknown80;
	char flag84;
	Point point88;
	Point point90;
	Point point98;
	Point pointA0;
	int unknownA8;

	OpU8c_RecAC(const OpU8c_RecAC &o);
};

OpU8c_RecAC::OpU8c_RecAC(const OpU8c_RecAC &o)	// 0x9f4660
	: flag0		(o.flag0)
	, unknown04	(o.unknown04)
	, unknown08	(o.unknown08)
	, unknown0c	(o.unknown0c)
	, unknown10	(o.unknown10)
	, name14	(o.name14)
	, name30	(o.name30)
	, flag4c	(o.flag4c)
	, name50	(o.name50)
	, unknown6c	(o.unknown6c)
	, list70	(o.list70)
	, unknown80	(o.unknown80)
	, flag84	(o.flag84)
	, point88	(o.point88)
	, point90	(o.point90)
	, point98	(o.point98)
	, pointA0	(o.pointA0)
	, unknownA8	(o.unknownA8)
{
}

struct OpU8c_RectList	// NOTE: placeholder name
{
	Rect rect;
	int unknown10;
	vector<OpR6_KA_12_0> list14;

	OpU8c_RectList(const OpU8c_RectList &o);
};

OpU8c_RectList::OpU8c_RectList(const OpU8c_RectList &o)	// 0x9f4920
	: rect		(o.rect)
	, unknown10	(o.unknown10)
	, list14	(o.list14)
{
}

struct OpU8c_Rec30	// NOTE: placeholder name
{
	char flag0;
	int unknown04;
	int unknown08;
	int unknown0c;
	Point point10;
	Point point18;
	int unknown20;
	Point point24;
	Point point2c;

	OpU8c_Rec30(const OpU8c_Rec30 &o);
};

OpU8c_Rec30::OpU8c_Rec30(const OpU8c_Rec30 &o)	// 0x9f4960
	: flag0		(o.flag0)
	, unknown04	(o.unknown04)
	, unknown08	(o.unknown08)
	, unknown0c	(o.unknown0c)
	, point10	(o.point10)
	, point18	(o.point18)
	, unknown20	(o.unknown20)
	, point24	(o.point24)
	, point2c	(o.point2c)
{
}

struct OpU8c_Lists	// NOTE: placeholder name
{
	vector<E8_9b3130> list0;
	vector<OpR6_KA_12_0> list10;
	vector<E8_9b3130> list20;
	vector<OpR6_KA_12_0> list30;
	int unknown40;
	char flag44;
	char flag45;
	Point point48;
	char flag50;

	OpU8c_Lists(const OpU8c_Lists &o);
};

OpU8c_Lists::OpU8c_Lists(const OpU8c_Lists &o)	// 0x9f4a00
	: list0		(o.list0)
	, list10	(o.list10)
	, list20	(o.list20)
	, list30	(o.list30)
	, unknown40	(o.unknown40)
	, flag44	(o.flag44)
	, flag45	(o.flag45)
	, point48	(o.point48)
	, flag50	(o.flag50)
{
}

struct OpU8c_ListPair	// NOTE: placeholder name
{
	vector<E8_9b3130> list0;
	vector<OpR6_KA_12_0> list10;

	OpU8c_ListPair(const OpU8c_ListPair &o);
};

OpU8c_ListPair::OpU8c_ListPair(const OpU8c_ListPair &o)	// 0x9f4ae0
	: list0		(o.list0)
	, list10	(o.list10)
{
}

struct OpU8c_Rec24	// NOTE: placeholder name
{
	Point point0;
	int unknown08;
	int unknown0c;
	OpU8c_Area area10;
	int unknown20;

	OpU8c_Rec24(const OpU8c_Rec24 &o);
};

OpU8c_Rec24::OpU8c_Rec24(const OpU8c_Rec24 &o)	// 0x9f4b50
	: point0	(o.point0)
	, unknown08	(o.unknown08)
	, unknown0c	(o.unknown0c)
	, area10	(o.area10)
	, unknown20	(o.unknown20)
{
}

struct OpU8c_Rec35	// NOTE: placeholder name
{
	int unknown00;
	int unknown04;
	int unknown08;
	int unknown0c;
	int unknown10;
	vector<OpR6_KA_12_0> list14;
	vector<OpR6_KA_12_0> list24;
	char flag34;

	OpU8c_Rec35(const OpU8c_Rec35 &o);
};

OpU8c_Rec35::OpU8c_Rec35(const OpU8c_Rec35 &o)	// 0x9f4bb0
	: unknown00	(o.unknown00)
	, unknown04	(o.unknown04)
	, unknown08	(o.unknown08)
	, unknown0c	(o.unknown0c)
	, unknown10	(o.unknown10)
	, list14	(o.list14)
	, list24	(o.list24)
	, flag34	(o.flag34)
{
}

struct OpU8c_Rec60	// NOTE: placeholder name
{
	int unknown00;
	Rect rect04;
	vector<E8_9b3130> list14;
	int unknown24;
	vector<E8_9b3130> list28;
	vector<int> list38;
	vector<int> list48;
	int unknown58;
	vector<int> list5c;

	OpU8c_Rec60 &operator=(const OpU8c_Rec60 &o);
};

OpU8c_Rec60 &OpU8c_Rec60::operator=(const OpU8c_Rec60 &o)	// 0x9f4c70
{
	unknown00 = o.unknown00;
	rect04 = o.rect04;
	list14 = o.list14;
	unknown24 = o.unknown24;
	list28 = o.list28;
	list38 = o.list38;
	list48 = o.list48;
	unknown58 = o.unknown58;
	list5c = o.list5c;
	return *this;
}

struct OpU8c_RectInts	// NOTE: placeholder name
{
	Rect rect;
	int unknown10;
	vector<int> list14;

	OpU8c_RectInts &operator=(const OpU8c_RectInts &o);
};

OpU8c_RectInts &OpU8c_RectInts::operator=(const OpU8c_RectInts &o)	// 0x9f4d10
{
	rect = o.rect;
	unknown10 = o.unknown10;
	list14 = o.list14;
	return *this;
}

struct OpU8c_ImageRec : public AsciiImage	// NOTE: placeholder name
{
	OpU8c_Blob1c blob10;
	OpU8c_Blob1c blob2c;
	int unknown48;
	int unknown4c;
	Point point50;
	int unknown58;
	char flag5c;

	OpU8c_ImageRec &operator=(const OpU8c_ImageRec &o);
};

OpU8c_ImageRec &OpU8c_ImageRec::operator=(const OpU8c_ImageRec &o)	// 0x9f4d70
{
	AsciiImage::operator=(o);
	blob10 = o.blob10;
	blob2c = o.blob2c;
	unknown48 = o.unknown48;
	unknown4c = o.unknown4c;
	point50 = o.point50;
	unknown58 = o.unknown58;
	flag5c = o.flag5c;
	return *this;
}

struct OpU8c_ColorRec	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	float value;
	XColor color;

	OpU8c_ColorRec &operator=(const OpU8c_ColorRec &o);
};

OpU8c_ColorRec &OpU8c_ColorRec::operator=(const OpU8c_ColorRec &o)	// 0x9f4610
{
	unknown0 = o.unknown0;
	unknown4 = o.unknown4;
	value = o.value;
	color = o.color;
	return *this;
}

template void std::_Fill(XColor *, XColor *, const XColor &);	// 0x9f2b30
template XColor *std::_Copy_backward(XColor *, XColor *, XColor *, std::_Nonscalar_ptr_iterator_tag);	// 0x9f2b70
template vector<XColor> &vector<XColor>::operator=(const vector<XColor> &);	// 0x9f5650
