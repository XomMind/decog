// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_40b100_At8
{
	int call409990(int value0);
};

class Calls_40b100
{
public:
	char unknown0[0x8];
	Calls_40b100_At8 field8;
	int call409990(int value0);
	Calls_40b100 & delegate();
};

Calls_40b100 & Calls_40b100::delegate()
{
	call409990(-1);
	field8.call409990(-1);
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_40b160_At8
{
	int call46ca50(int value0);
};

class Calls_40b160
{
public:
	char unknown0[0x8];
	Calls_40b160_At8 field8;
	int call46ca50(int value0);
	Calls_40b160 & delegate(int arg0, int arg1);
};

Calls_40b160 & Calls_40b160::delegate(int arg0, int arg1)
{
	call46ca50(arg0);
	field8.call46ca50(arg1);
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_40b300_At8
{
	int call40a010(int value0, int value1);
};

class Calls_40b300
{
public:
	char unknown0[0x8];
	Calls_40b300_At8 field8;
	int call40a010(int value0, int value1);
	int delegate(int arg0, int arg1, int arg2, int arg3);
};

int Calls_40b300::delegate(int arg0, int arg1, int arg2, int arg3)
{
	call40a010(arg0, arg1);
	return field8.call40a010(arg2, arg3);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_40b330_At8
{
	int call46ca50(int value0);
};

class Calls_40b330
{
public:
	char unknown0[0x8];
	Calls_40b330_At8 field8;
	int call46ca50(int value0);
	int delegate(int arg0, int arg1);
};

int Calls_40b330::delegate(int arg0, int arg1)
{
	call46ca50(arg0);
	return field8.call46ca50(arg1);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_40b3f0_At8
{
	int call46ca50(int value0);
};

class Calls_40b3f0
{
public:
	char unknown0[0x8];
	Calls_40b3f0_At8 field8;
	int call46ca50(int value0);
	int delegate(int arg0);
};

int Calls_40b3f0::delegate(int arg0)
{
	call46ca50(arg0);
	return field8.call46ca50(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_40b420_At8
{
	int call40a370(int value0);
};

class Calls_40b420
{
public:
	char unknown0[0x8];
	Calls_40b420_At8 field8;
	int call40a370(int value0);
	int delegate(int arg0);
};

int Calls_40b420::delegate(int arg0)
{
	call40a370(arg0);
	return field8.call40a370(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_40b450_At8
{
	int call40a330(int value0);
};

class Calls_40b450
{
public:
	char unknown0[0x8];
	Calls_40b450_At8 field8;
	int call40a330(int value0);
	int delegate(int arg0);
};

int Calls_40b450::delegate(int arg0)
{
	call40a330(arg0);
	return field8.call40a330(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_40c7b0_At8
{
	int call40bef0();
	int call40a010(int value0, int value1);
};

class Calls_40c7b0
{
public:
	char unknown0[0x8];
	Calls_40c7b0_At8 field8;
	int call40bef0();
	int call40a010(int value0, int value1);
	Calls_40c7b0 & delegate(int arg0, int arg1, int arg2, int arg3);
};

Calls_40c7b0 & Calls_40c7b0::delegate(int arg0, int arg1, int arg2, int arg3)
{
	call40bef0();
	field8.call40bef0();
	call40a010(arg0, arg1);
	field8.call40a010(arg2, arg3);
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_40c800
{
public:
	int call40c840(int value0);
	Calls_40c800 & delegate(int arg0);
};

Calls_40c800 & Calls_40c800::delegate(int arg0)
{
	call40c840(arg0);
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_410d90
{
public:
	int call9af040();
	Calls_410d90 & delegate();
};

Calls_410d90 & Calls_410d90::delegate()
{
	call9af040();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_410db0_At1c
{
	int call9b1c30();
};

class Calls_410db0
{
public:
	char unknown0[0x1c];
	Calls_410db0_At1c * field1c;
	void delegate();
};

void Calls_410db0::delegate()
{
	if (field1c != 0)
	{
	field1c->call9b1c30();
	}
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_415c60_At4
{
	int call453b40();
	int call409ff0(int value0);
};

class Calls_415c60
{
public:
	int field0;
	Calls_415c60_At4 field4;
	Calls_415c60 & delegate(int arg0);
};

Calls_415c60 & Calls_415c60::delegate(int arg0)
{
	field0 = arg0;
	field4.call453b40();
	field4.call409ff0(0xffffd8f0);
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_415ca0_At4
{
	int call453b40();
	int call40a010(int value0, int value1);
};

class Calls_415ca0
{
public:
	int field0;
	Calls_415ca0_At4 field4;
	Calls_415ca0 & delegate(int arg0, int arg1, int arg2);
};

Calls_415ca0 & Calls_415ca0::delegate(int arg0, int arg1, int arg2)
{
	field0 = arg0;
	field4.call453b40();
	field4.call40a010(arg1, arg2);
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_416ad0_At3c
{
	int call411d40();
};

class Calls_416ad0
{
public:
	char unknown0[0x1c];
	int field1c;
	int field20;
	int field24;
	int field28;
	char unknown2c[0x10];
	Calls_416ad0_At3c field3c;
	int call9aefb0(int value0);
	Calls_416ad0 & delegate(int arg0, int arg1, int arg2, int arg3);
};

Calls_416ad0 & Calls_416ad0::delegate(int arg0, int arg1, int arg2, int arg3)
{
	call9aefb0(arg1);
	field1c = arg0;
	field20 = arg2;
	field24 = arg3;
	field28 = 0;
	field3c.call411d40();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_416b20
{
public:
	int call416b40();
	int call9af350();
	int delegate();
};

int Calls_416b20::delegate()
{
	call416b40();
	return call9af350();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4176e0_At8
{
	int call9cdf20(int value0, int value1);
};

class Calls_4176e0
{
public:
	char unknown0[0x8];
	Calls_4176e0_At8 field8;
	int delegate(int arg0, int arg1);
};

int Calls_4176e0::delegate(int arg0, int arg1)
{
	return field8.call9cdf20(arg0, arg1);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_417780_At8
{
	int call9d2930(int value0);
};

class Calls_417780
{
public:
	char unknown0[0x8];
	Calls_417780_At8 field8;
	int delegate(int arg0);
};

int Calls_417780::delegate(int arg0)
{
	return field8.call9d2930(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4225c0_At28
{
	int call9af040();
};

struct Calls_4225c0_At44
{
	int call9b8e80();
};

class Calls_4225c0
{
public:
	char unknown0[0x28];
	Calls_4225c0_At28 field28;
	char unknown29[0x1b];
	Calls_4225c0_At44 field44;
	int call9af040();
	Calls_4225c0 & delegate();
};

Calls_4225c0 & Calls_4225c0::delegate()
{
	call9af040();
	field28.call9af040();
	field44.call9b8e80();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_425ab0_At10
{
	int call9b8e80();
};

struct Calls_425ab0_At20
{
	int call9b8e80();
};

struct Calls_425ab0_At30
{
	int call9b8e80();
};

class Calls_425ab0
{
public:
	char unknown0[0x10];
	Calls_425ab0_At10 field10;
	char unknown11[0xf];
	Calls_425ab0_At20 field20;
	char unknown21[0xf];
	Calls_425ab0_At30 field30;
	Calls_425ab0 & delegate();
};

Calls_425ab0 & Calls_425ab0::delegate()
{
	field10.call9b8e80();
	field20.call9b8e80();
	field30.call9b8e80();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_425b50_At1c
{
	int call9b8e80();
};

struct Calls_425b50_At38
{
	int call9b8e80();
};

struct Calls_425b50_At48
{
	int call9b8e80();
};

struct Calls_425b50_At58
{
	int call9b8e80();
};

struct Calls_425b50_At68
{
	int call9b8e80();
};

struct Calls_425b50_At78
{
	int call9b8e80();
};

class Calls_425b50
{
public:
	char unknown0[0x1c];
	Calls_425b50_At1c field1c;
	char unknown1d[0x1b];
	Calls_425b50_At38 field38;
	char unknown39[0xf];
	Calls_425b50_At48 field48;
	char unknown49[0xf];
	Calls_425b50_At58 field58;
	char unknown59[0xf];
	Calls_425b50_At68 field68;
	char unknown69[0xf];
	Calls_425b50_At78 field78;
	int call9af040();
	Calls_425b50 & delegate();
};

Calls_425b50 & Calls_425b50::delegate()
{
	call9af040();
	field1c.call9b8e80();
	field38.call9b8e80();
	field48.call9b8e80();
	field58.call9b8e80();
	field68.call9b8e80();
	field78.call9b8e80();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_426b60
{
public:
	int call426a60(int value0);
	int call426950(int value0, int value1);
	int delegate(int arg0, int arg1);
};

int Calls_426b60::delegate(int arg0, int arg1)
{
	call426a60(arg0);
	return call426950(arg0, arg1);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_432460
{
public:
	char unknown0[0x40];
	int field40;
	int calla59f60(int value0, int value1);
	void delegate(int arg0, int arg1);
};

void Calls_432460::delegate(int arg0, int arg1)
{
	if (field40 != 0)
	{
	calla59f60(arg0, arg1);
	}
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_447e20_At10
{
	int call453b40();
};

class Calls_447e20
{
public:
	int field0;
	char unknown4[0xc];
	Calls_447e20_At10 field10;
	Calls_447e20 & delegate();
};

Calls_447e20 & Calls_447e20::delegate()
{
	field0 = 0xc2f04c;
	field10.call453b40();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_447e50_At10
{
	int call46ca50(int value0);
};

class Calls_447e50
{
public:
	int field0;
	int field4;
	int field8;
	int fieldc;
	Calls_447e50_At10 field10;
	Calls_447e50 & delegate(int arg0, int arg1, int arg2);
};

Calls_447e50 & Calls_447e50::delegate(int arg0, int arg1, int arg2)
{
	field0 = 0xc2f04c;
	field4 = arg0;
	field8 = 0;
	fieldc = arg1;
	field10.call46ca50(arg2);
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_448160_At4
{
	int call9b8e80();
};

class Calls_448160
{
public:
	int field0;
	Calls_448160_At4 field4;
	Calls_448160 & delegate();
};

Calls_448160 & Calls_448160::delegate()
{
	field0 = 0;
	field4.call9b8e80();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_448a10_Atc
{
	int call9b8e80();
};

struct Calls_448a10_At1c
{
	int call9b8e80();
};

struct Calls_448a10_At38
{
	int call40bef0();
};

class Calls_448a10
{
public:
	char unknown0[0xc];
	Calls_448a10_Atc fieldc;
	char unknownd[0xf];
	Calls_448a10_At1c field1c;
	char unknown1d[0x1b];
	Calls_448a10_At38 field38;
	Calls_448a10 & delegate();
};

Calls_448a10 & Calls_448a10::delegate()
{
	fieldc.call9b8e80();
	field1c.call9b8e80();
	field38.call40bef0();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_448aa0_At14
{
	int call40bef0();
};

struct Calls_448aa0_At1c
{
	int call40bef0();
};

struct Calls_448aa0_At24
{
	int call40bef0();
};

struct Calls_448aa0_At2c
{
	int call9b8e80();
};

struct Calls_448aa0_At3c
{
	int call40bef0();
};

struct Calls_448aa0_At44
{
	int call40bef0();
};

struct Calls_448aa0_At4c
{
	int call40bef0();
};

struct Calls_448aa0_At54
{
	int call40bef0();
};

struct Calls_448aa0_At5c
{
	int call40bef0();
};

struct Calls_448aa0_At64
{
	int call40bef0();
};

struct Calls_448aa0_At6c
{
	int call40bef0();
};

struct Calls_448aa0_At74
{
	int call40bef0();
};

struct Calls_448aa0_At7c
{
	int call40bef0();
};

class Calls_448aa0
{
public:
	char unknown0[0x14];
	Calls_448aa0_At14 field14;
	char unknown15[0x7];
	Calls_448aa0_At1c field1c;
	char unknown1d[0x7];
	Calls_448aa0_At24 field24;
	char unknown25[0x7];
	Calls_448aa0_At2c field2c;
	char unknown2d[0xf];
	Calls_448aa0_At3c field3c;
	char unknown3d[0x7];
	Calls_448aa0_At44 field44;
	char unknown45[0x7];
	Calls_448aa0_At4c field4c;
	char unknown4d[0x7];
	Calls_448aa0_At54 field54;
	char unknown55[0x7];
	Calls_448aa0_At5c field5c;
	char unknown5d[0x7];
	Calls_448aa0_At64 field64;
	char unknown65[0x7];
	Calls_448aa0_At6c field6c;
	char unknown6d[0x7];
	Calls_448aa0_At74 field74;
	char unknown75[0x7];
	Calls_448aa0_At7c field7c;
	Calls_448aa0 & delegate();
};

Calls_448aa0 & Calls_448aa0::delegate()
{
	field14.call40bef0();
	field1c.call40bef0();
	field24.call40bef0();
	field2c.call9b8e80();
	field3c.call40bef0();
	field44.call40bef0();
	field4c.call40bef0();
	field54.call40bef0();
	field5c.call40bef0();
	field64.call40bef0();
	field6c.call40bef0();
	field74.call40bef0();
	field7c.call40bef0();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_448c00_At10
{
	int call9af040();
};

struct Calls_448c00_At2c
{
	int call9af040();
};

struct Calls_448c00_At50
{
	int call453b40();
};

class Calls_448c00
{
public:
	char unknown0[0x10];
	Calls_448c00_At10 field10;
	char unknown11[0x1b];
	Calls_448c00_At2c field2c;
	char unknown2d[0x23];
	Calls_448c00_At50 field50;
	int call4588d0();
	Calls_448c00 & delegate();
};

Calls_448c00 & Calls_448c00::delegate()
{
	call4588d0();
	field10.call9af040();
	field2c.call9af040();
	field50.call453b40();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_448e60_At1c
{
	int call9af040();
};

struct Calls_448e60_At44
{
	int call9b8e80();
};

struct Calls_448e60_At54
{
	int call9b8e80();
};

struct Calls_448e60_At64
{
	int call9b8e80();
};

struct Calls_448e60_At8c
{
	int call9b8e80();
};

struct Calls_448e60_At9c
{
	int call9b8e80();
};

struct Calls_448e60_Atac
{
	int call9b8e80();
};

class Calls_448e60
{
public:
	char unknown0[0x1c];
	Calls_448e60_At1c field1c;
	char unknown1d[0x27];
	Calls_448e60_At44 field44;
	char unknown45[0xf];
	Calls_448e60_At54 field54;
	char unknown55[0xf];
	Calls_448e60_At64 field64;
	char unknown65[0x27];
	Calls_448e60_At8c field8c;
	char unknown8d[0xf];
	Calls_448e60_At9c field9c;
	char unknown9d[0xf];
	Calls_448e60_Atac fieldac;
	int call9af040();
	Calls_448e60 & delegate();
};

Calls_448e60 & Calls_448e60::delegate()
{
	call9af040();
	field1c.call9af040();
	field44.call9b8e80();
	field54.call9b8e80();
	field64.call9b8e80();
	field8c.call9b8e80();
	field9c.call9b8e80();
	fieldac.call9b8e80();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4492b0_Atc
{
	int call40bef0();
};

struct Calls_4492b0_At30
{
	int call40bef0();
};

struct Calls_4492b0_At48
{
	int call9b8e80();
};

struct Calls_4492b0_At70
{
	int call9b8e80();
};

struct Calls_4492b0_At80
{
	int call9b8e80();
};

struct Calls_4492b0_At90
{
	int call40bef0();
};

class Calls_4492b0
{
public:
	char unknown0[0xc];
	Calls_4492b0_Atc fieldc;
	char unknownd[0x23];
	Calls_4492b0_At30 field30;
	char unknown31[0x17];
	Calls_4492b0_At48 field48;
	char unknown49[0x27];
	Calls_4492b0_At70 field70;
	char unknown71[0xf];
	Calls_4492b0_At80 field80;
	char unknown81[0xf];
	Calls_4492b0_At90 field90;
	Calls_4492b0 & delegate();
};

Calls_4492b0 & Calls_4492b0::delegate()
{
	fieldc.call40bef0();
	field30.call40bef0();
	field48.call9b8e80();
	field70.call9b8e80();
	field80.call9b8e80();
	field90.call40bef0();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4493c0_At1c
{
	int call9af040();
};

struct Calls_4493c0_At40
{
	int call9b8e80();
};

struct Calls_4493c0_At58
{
	int call9d2670();
};

struct Calls_4493c0_At64
{
	int call9d2670();
};

struct Calls_4493c0_At70
{
	int call9d2670();
};

class Calls_4493c0
{
public:
	char unknown0[0x1c];
	Calls_4493c0_At1c field1c;
	char unknown1d[0x23];
	Calls_4493c0_At40 field40;
	char unknown41[0x17];
	Calls_4493c0_At58 field58;
	char unknown59[0xb];
	Calls_4493c0_At64 field64;
	char unknown65[0xb];
	Calls_4493c0_At70 field70;
	char unknown71[0xf];
	int field80;
	int call9af040();
	Calls_4493c0 & delegate();
};

Calls_4493c0 & Calls_4493c0::delegate()
{
	call9af040();
	field1c.call9af040();
	field40.call9b8e80();
	field58.call9d2670();
	field64.call9d2670();
	field70.call9d2670();
	field80 = 0;
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4533e0_At10
{
	int call9af370(int value0);
};

class Calls_4533e0
{
public:
	char unknown0[0x10];
	Calls_4533e0_At10 field10;
	int delegate(int arg0);
};

int Calls_4533e0::delegate(int arg0)
{
	return field10.call9af370(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_453400_At2c
{
	int call9af370(int value0);
};

class Calls_453400
{
public:
	char unknown0[0x2c];
	Calls_453400_At2c field2c;
	int delegate(int arg0);
};

int Calls_453400::delegate(int arg0)
{
	return field2c.call9af370(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_453420_At48
{
	int call9af370(int value0);
};

class Calls_453420
{
public:
	char unknown0[0x48];
	Calls_453420_At48 field48;
	int delegate(int arg0);
};

int Calls_453420::delegate(int arg0)
{
	return field48.call9af370(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_453bc0_At4
{
	int call9b6590();
};

class Calls_453bc0
{
public:
	int field0;
	Calls_453bc0_At4 field4;
	char unknown5[0x3];
	int field8;
	int fieldc;
	Calls_453bc0 & delegate();
};

Calls_453bc0 & Calls_453bc0::delegate()
{
	field0 = 0xc2ef00;
	field4.call9b6590();
	field8 = 0;
	fieldc = 0;
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_454d70_At4
{
	int call46ca50(int value0);
};

class Calls_454d70
{
public:
	char unknown0[0x4];
	Calls_454d70_At4 field4;
	int delegate(int arg0);
};

int Calls_454d70::delegate(int arg0)
{
	return field4.call46ca50(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_454fe0_At10
{
	int call9af040();
};

class Calls_454fe0
{
public:
	char unknown0[0x10];
	Calls_454fe0_At10 field10;
	int call9b8e80();
	Calls_454fe0 & delegate();
};

Calls_454fe0 & Calls_454fe0::delegate()
{
	call9b8e80();
	field10.call9af040();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4557d0_At8
{
	int call453b40();
};

struct Calls_4557d0_At10
{
	int call453b40();
};

struct Calls_4557d0_At18
{
	int call453b40();
};

struct Calls_4557d0_At20
{
	int call9cfd10();
};

class Calls_4557d0
{
public:
	int field0;
	char unknown4[0x4];
	Calls_4557d0_At8 field8;
	char unknown9[0x7];
	Calls_4557d0_At10 field10;
	char unknown11[0x7];
	Calls_4557d0_At18 field18;
	char unknown19[0x7];
	Calls_4557d0_At20 field20;
	Calls_4557d0 & delegate();
};

Calls_4557d0 & Calls_4557d0::delegate()
{
	field0 = 0;
	field8.call453b40();
	field10.call453b40();
	field18.call453b40();
	field20.call9cfd10();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_455820_At8
{
	int call46ca50(int value0);
};

struct Calls_455820_At10
{
	int call46ca50(int value0);
};

struct Calls_455820_At18
{
	int call46ca50(int value0);
};

struct Calls_455820_At20
{
	int call9cfd10();
};

class Calls_455820
{
public:
	int field0;
	int field4;
	Calls_455820_At8 field8;
	char unknown9[0x7];
	Calls_455820_At10 field10;
	char unknown11[0x7];
	Calls_455820_At18 field18;
	char unknown19[0x7];
	Calls_455820_At20 field20;
	Calls_455820 & delegate(int arg0, int arg1, int arg2, int arg3, int arg4);
};

Calls_455820 & Calls_455820::delegate(int arg0, int arg1, int arg2, int arg3, int arg4)
{
	field0 = arg0;
	field4 = arg1;
	field8.call46ca50(arg2);
	field10.call46ca50(arg3);
	field18.call46ca50(arg4);
	field20.call9cfd10();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_455950_At30
{
	int call9f5b70(int value0);
};

class Calls_455950
{
public:
	char unknown0[0x30];
	Calls_455950_At30 field30;
	int delegate(int arg0);
};

int Calls_455950::delegate(int arg0)
{
	return field30.call9f5b70(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_455bd0_At8
{
	int call40bef0();
	int call45f040(int value0);
};

class Calls_455bd0
{
public:
	char unknown0[0x8];
	Calls_455bd0_At8 field8;
	int call40bef0();
	int call45f040(int value0);
	Calls_455bd0 & delegate(int arg0);
};

Calls_455bd0 & Calls_455bd0::delegate(int arg0)
{
	call40bef0();
	field8.call40bef0();
	call45f040(arg0);
	field8.call45f040(arg0);
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_455dd0_At4
{
	int call9af040();
};

struct Calls_455dd0_At24
{
	int call9af040();
};

class Calls_455dd0
{
public:
	char unknown0[0x4];
	Calls_455dd0_At4 field4;
	char unknown5[0x1f];
	Calls_455dd0_At24 field24;
	Calls_455dd0 & delegate();
};

Calls_455dd0 & Calls_455dd0::delegate()
{
	field4.call9af040();
	field24.call9af040();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_456200_At1c
{
	int call9af040();
};

struct Calls_456200_At3c
{
	int call9af040();
};

class Calls_456200
{
public:
	char unknown0[0x1c];
	Calls_456200_At1c field1c;
	char unknown1d[0x1f];
	Calls_456200_At3c field3c;
	int call9af040();
	Calls_456200 & delegate();
};

Calls_456200 & Calls_456200::delegate()
{
	call9af040();
	field1c.call9af040();
	field3c.call9af040();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_456230_At3c
{
	int call9af350();
};

struct Calls_456230_At1c
{
	int call9af350();
};

class Calls_456230
{
public:
	char unknown0[0x1c];
	Calls_456230_At1c field1c;
	char unknown1d[0x1f];
	Calls_456230_At3c field3c;
	int call9af350();
	int delegate();
};

int Calls_456230::delegate()
{
	field3c.call9af350();
	field1c.call9af350();
	return call9af350();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_456260
{
public:
	int call9b8e80();
	int call518b30();
	Calls_456260 & delegate();
};

Calls_456260 & Calls_456260::delegate()
{
	call9b8e80();
	call518b30();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_456980
{
public:
	int call453b40();
	Calls_456980 & delegate();
};

Calls_456980 & Calls_456980::delegate()
{
	call453b40();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_457920_At8
{
	int call457130();
};

class Calls_457920
{
public:
	char unknown0[0x8];
	Calls_457920_At8 * field8;
	int delegate();
};

int Calls_457920::delegate()
{
	return field8->call457130();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_459380
{
public:
	char unknown0[0x4];
	int field4;
	char unknown8[0x8];
	int field10;
	int call459540(int value0);
	void delegate(int arg0);
};

void Calls_459380::delegate(int arg0)
{
	call459540(arg0);
	field10 = 0xffffffff;
	field4 = 1;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4593b0_At6c
{
	int call9b32e0(int value0);
};

class Calls_4593b0
{
public:
	char unknown0[0x6c];
	Calls_4593b0_At6c field6c;
	int delegate(int arg0);
};

int Calls_4593b0::delegate(int arg0)
{
	return field6c.call9b32e0(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4593d0_At6c
{
	int call9b3130(int value0);
};

class Calls_4593d0
{
public:
	char unknown0[0x6c];
	Calls_4593d0_At6c field6c;
	int delegate(int arg0);
};

int Calls_4593d0::delegate(int arg0)
{
	return field6c.call9b3130(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_459410_At80
{
	int call40b130(int value0);
};

class Calls_459410
{
public:
	char unknown0[0x10];
	int field10;
	char unknown14[0x6c];
	Calls_459410_At80 field80;
	void delegate(int arg0);
};

void Calls_459410::delegate(int arg0)
{
	field80.call40b130(arg0);
	field10 = 0xffffffff;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_459440_At80
{
	int call40b330(int value0, int value1);
};

class Calls_459440
{
public:
	char unknown0[0x10];
	int field10;
	char unknown14[0x6c];
	Calls_459440_At80 field80;
	void delegate(int arg0, int arg1);
};

void Calls_459440::delegate(int arg0, int arg1)
{
	field80.call40b330(arg0, arg1);
	field10 = 0xffffffff;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_459470_At80
{
	int call40b130(int value0);
};

struct Calls_459470_At90
{
	int call9b3560();
};

class Calls_459470
{
public:
	char unknown0[0x4];
	int field4;
	char unknown8[0x8];
	int field10;
	char unknown14[0x6c];
	Calls_459470_At80 field80;
	char unknown81[0xf];
	Calls_459470_At90 field90;
	int delegate(int arg0);
};

int Calls_459470::delegate(int arg0)
{
	field80.call40b130(arg0);
	field10 = 0xffffffff;
	field4 = 3;
	return field90.call9b3560();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4594c0_At90
{
	int call9b3130(int value0);
};

class Calls_4594c0
{
public:
	char unknown0[0x10];
	int field10;
	char unknown14[0x7c];
	Calls_4594c0_At90 field90;
	void delegate(int arg0);
};

void Calls_4594c0::delegate(int arg0)
{
	field90.call9b3130(arg0);
	field10 = 0xffffffff;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_459520_At10
{
	int call46ca50(int value0);
};

class Calls_459520
{
public:
	char unknown0[0x10];
	Calls_459520_At10 field10;
	int delegate(int arg0);
};

int Calls_459520::delegate(int arg0)
{
	return field10.call46ca50(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_459540_At6c
{
	int call9b3560();
	int call9b32e0(int value0);
};

class Calls_459540
{
public:
	char unknown0[0x6c];
	Calls_459540_At6c field6c;
	int delegate(int arg0);
};

int Calls_459540::delegate(int arg0)
{
	field6c.call9b3560();
	return field6c.call9b32e0(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_45a010
{
public:
	char unknown0[0x8];
	int field8;
	int call46ca50(int value0);
	Calls_45a010 & delegate(int arg0, int arg1);
};

Calls_45a010 & Calls_45a010::delegate(int arg0, int arg1)
{
	call46ca50(arg0);
	field8 = arg1;
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_45c2e0_At8
{
	int call9b6590();
};

struct Calls_45c2e0_Atc
{
	int call9b6590();
};

class Calls_45c2e0
{
public:
	int field0;
	int field4;
	Calls_45c2e0_At8 field8;
	char unknown9[0x3];
	Calls_45c2e0_Atc fieldc;
	char unknownd[0x3];
	int field10;
	int field14;
	int field18;
	int field1c;
	Calls_45c2e0 & delegate(int arg0, int arg1);
};

Calls_45c2e0 & Calls_45c2e0::delegate(int arg0, int arg1)
{
	field0 = arg0;
	field4 = arg1;
	field8.call9b6590();
	fieldc.call9b6590();
	field10 = 3;
	field14 = 0;
	field18 = 0;
	field1c = 0;
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_45e530
{
public:
	char unknown0[0x8];
	int field8;
	int fieldc;
	int call9b6590();
	Calls_45e530 & delegate(int arg0, int arg1);
};

Calls_45e530 & Calls_45e530::delegate(int arg0, int arg1)
{
	call9b6590();
	field8 = arg0;
	fieldc = arg1;
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_45f020
{
public:
	int call45f0a0();
	Calls_45f020 & delegate();
};

Calls_45f020 & Calls_45f020::delegate()
{
	call45f0a0();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_45f0c0_At10
{
	int call9b8e80();
};

struct Calls_45f0c0_At20
{
	int call9b8e80();
};

struct Calls_45f0c0_At30
{
	int call9b8e80();
};

struct Calls_45f0c0_At44
{
	int call9af040();
};

class Calls_45f0c0
{
public:
	char unknown0[0x10];
	Calls_45f0c0_At10 field10;
	char unknown11[0xf];
	Calls_45f0c0_At20 field20;
	char unknown21[0xf];
	Calls_45f0c0_At30 field30;
	char unknown31[0x13];
	Calls_45f0c0_At44 field44;
	int call9b8e80();
	Calls_45f0c0 & delegate();
};

Calls_45f0c0 & Calls_45f0c0::delegate()
{
	call9b8e80();
	field10.call9b8e80();
	field20.call9b8e80();
	field30.call9b8e80();
	field44.call9af040();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_45faa0
{
public:
	int call45fac0();
	Calls_45faa0 & delegate();
};

Calls_45faa0 & Calls_45faa0::delegate()
{
	call45fac0();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_45fe00_At10
{
	int call9b8e80();
};

struct Calls_45fe00_At20
{
	int call9b8e80();
};

struct Calls_45fe00_At30
{
	int call9b8e80();
};

struct Calls_45fe00_At48
{
	int call9b8e80();
};

struct Calls_45fe00_At58
{
	int call9b8e80();
};

struct Calls_45fe00_At6c
{
	int call9b6590();
};

struct Calls_45fe00_At70
{
	int call9b8e80();
};

struct Calls_45fe00_At84
{
	int call9b8e80();
};

class Calls_45fe00
{
public:
	char unknown0[0x10];
	Calls_45fe00_At10 field10;
	char unknown11[0xf];
	Calls_45fe00_At20 field20;
	char unknown21[0xf];
	Calls_45fe00_At30 field30;
	char unknown31[0x17];
	Calls_45fe00_At48 field48;
	char unknown49[0xf];
	Calls_45fe00_At58 field58;
	char unknown59[0xf];
	int field68;
	Calls_45fe00_At6c field6c;
	char unknown6d[0x3];
	Calls_45fe00_At70 field70;
	char unknown71[0x13];
	Calls_45fe00_At84 field84;
	Calls_45fe00 & delegate();
};

Calls_45fe00 & Calls_45fe00::delegate()
{
	field10.call9b8e80();
	field20.call9b8e80();
	field30.call9b8e80();
	field48.call9b8e80();
	field58.call9b8e80();
	field68 = 0;
	field6c.call9b6590();
	field70.call9b8e80();
	field84.call9b8e80();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_45ff70
{
public:
	char unknown0[0x10];
	int field10;
	int call40a720(int value0);
	Calls_45ff70 & delegate(int arg0, int arg1);
};

Calls_45ff70 & Calls_45ff70::delegate(int arg0, int arg1)
{
	call40a720(arg0);
	field10 = arg1;
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_460010
{
public:
	char unknown0[0x8];
	int field8;
	int fieldc;
	int call46ca50(int value0);
	Calls_460010 & delegate(int arg0, int arg1, int arg2);
};

Calls_460010 & Calls_460010::delegate(int arg0, int arg1, int arg2)
{
	call46ca50(arg0);
	field8 = arg1;
	fieldc = arg2;
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_460720_At8
{
	int call9b8e80();
};

struct Calls_460720_At18
{
	int call453b40();
};

struct Calls_460720_At20
{
	int call453b40();
};

class Calls_460720
{
public:
	char unknown0[0x8];
	Calls_460720_At8 field8;
	char unknown9[0xf];
	Calls_460720_At18 field18;
	char unknown19[0x7];
	Calls_460720_At20 field20;
	int call9b6590();
	Calls_460720 & delegate();
};

Calls_460720 & Calls_460720::delegate()
{
	call9b6590();
	field8.call9b8e80();
	field18.call453b40();
	field20.call453b40();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_460860_At8
{
	int call9b8e80();
};

struct Calls_460860_At18
{
	int call9b8e80();
};

struct Calls_460860_At28
{
	int call9b8e80();
};

class Calls_460860
{
public:
	int field0;
	int field4;
	Calls_460860_At8 field8;
	char unknown9[0xf];
	Calls_460860_At18 field18;
	char unknown19[0xf];
	Calls_460860_At28 field28;
	Calls_460860 & delegate(int arg0, int arg1);
};

Calls_460860 & Calls_460860::delegate(int arg0, int arg1)
{
	field0 = arg0;
	field4 = arg1;
	field8.call9b8e80();
	field18.call9b8e80();
	field28.call9b8e80();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_460d00_At4
{
	int call46ca50(int value0);
};

class Calls_460d00
{
public:
	int field0;
	Calls_460d00_At4 field4;
	char unknown5[0x7];
	int fieldc;
	Calls_460d00 & delegate(int arg0, int arg1, int arg2);
};

Calls_460d00 & Calls_460d00::delegate(int arg0, int arg1, int arg2)
{
	field0 = arg0;
	field4.call46ca50(arg1);
	fieldc = arg2;
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_460e00_At4
{
	int call9b6590();
	int call9cfaf0(int value0);
};

class Calls_460e00
{
public:
	char unknown0[0x4];
	Calls_460e00_At4 field4;
	char unknown5[0x3];
	int field8;
	int call9b6590();
	int call9cfaf0(int value0);
	Calls_460e00 & delegate(int arg0);
};

Calls_460e00 & Calls_460e00::delegate(int arg0)
{
	call9b6590();
	field4.call9b6590();
	call9cfaf0(arg0);
	field4.call9cfaf0(arg0);
	field8 = 0;
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_461390_At8
{
	int call453b40();
};

class Calls_461390
{
public:
	char unknown0[0x8];
	Calls_461390_At8 field8;
	int call9b6590();
	Calls_461390 & delegate();
};

Calls_461390 & Calls_461390::delegate()
{
	call9b6590();
	field8.call453b40();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4614b0_At8
{
	int call9aefb0(int value0);
};

class Calls_4614b0
{
public:
	char unknown0[0x8];
	Calls_4614b0_At8 field8;
	char unknown9[0x1b];
	int field24;
	int call46ca50(int value0);
	Calls_4614b0 & delegate(int arg0, int arg1, int arg2);
};

Calls_4614b0 & Calls_4614b0::delegate(int arg0, int arg1, int arg2)
{
	call46ca50(arg0);
	field8.call9aefb0(arg1);
	field24 = arg2;
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_461700_At4
{
	int call9b8e80();
};

class Calls_461700
{
public:
	int field0;
	Calls_461700_At4 field4;
	Calls_461700 & delegate(int arg0);
};

Calls_461700 & Calls_461700::delegate(int arg0)
{
	field0 = arg0;
	field4.call9b8e80();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_461f50_Atc
{
	int call411e30(int value0);
};

class Calls_461f50
{
public:
	char unknown0[0x8];
	int field8;
	Calls_461f50_Atc fieldc;
	int call46ca50(int value0);
	Calls_461f50 & delegate(int arg0, int arg1, int arg2);
};

Calls_461f50 & Calls_461f50::delegate(int arg0, int arg1, int arg2)
{
	call46ca50(arg0);
	field8 = arg1;
	fieldc.call411e30(arg2);
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_465a10_Atbe8
{
	int call9cff40(int value0);
};

class Calls_465a10
{
public:
	char unknown0[0xbe8];
	Calls_465a10_Atbe8 fieldbe8;
	int delegate(int arg0);
};

int Calls_465a10::delegate(int arg0)
{
	return fieldbe8.call9cff40(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_466470_At31
{
	int call9b8210();
};

class Calls_466470
{
public:
	char unknown0[0x31];
	Calls_466470_At31 field31;
	int call4666c0();
	Calls_466470 & delegate();
};

Calls_466470 & Calls_466470::delegate()
{
	call4666c0();
	field31.call9b8210();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4664a0_At31
{
	int call9b8250();
};

class Calls_4664a0
{
public:
	char unknown0[0x31];
	Calls_4664a0_At31 field31;
	int call466650();
	int delegate();
};

int Calls_4664a0::delegate()
{
	field31.call9b8250();
	return call466650();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4664c0_At31
{
	int call9b8270();
};

class Calls_4664c0
{
public:
	char unknown0[0x31];
	Calls_4664c0_At31 field31;
	int call4666c0();
	Calls_4664c0 & delegate();
};

Calls_4664c0 & Calls_4664c0::delegate()
{
	call4666c0();
	field31.call9b8270();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4664f0_At31
{
	int call9b82b0();
};

class Calls_4664f0
{
public:
	char unknown0[0x31];
	Calls_4664f0_At31 field31;
	int call466650();
	int delegate();
};

int Calls_4664f0::delegate()
{
	field31.call9b82b0();
	return call466650();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_466510_At31
{
	int call9b82d0();
};

class Calls_466510
{
public:
	char unknown0[0x31];
	Calls_466510_At31 field31;
	int call4666c0();
	Calls_466510 & delegate();
};

Calls_466510 & Calls_466510::delegate()
{
	call4666c0();
	field31.call9b82d0();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_466540_At31
{
	int call9b8310();
};

class Calls_466540
{
public:
	char unknown0[0x31];
	Calls_466540_At31 field31;
	int call466650();
	int delegate();
};

int Calls_466540::delegate()
{
	field31.call9b8310();
	return call466650();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_466560_At31
{
	int call9b7350();
};

class Calls_466560
{
public:
	char unknown0[0x31];
	Calls_466560_At31 field31;
	int call4666c0();
	Calls_466560 & delegate();
};

Calls_466560 & Calls_466560::delegate()
{
	call4666c0();
	field31.call9b7350();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_466590_At31
{
	int call9b7390();
};

class Calls_466590
{
public:
	char unknown0[0x31];
	Calls_466590_At31 field31;
	int call466650();
	int delegate();
};

int Calls_466590::delegate()
{
	field31.call9b7390();
	return call466650();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4665b0_At31
{
	int call9b71d0();
};

class Calls_4665b0
{
public:
	char unknown0[0x31];
	Calls_4665b0_At31 field31;
	int call4666c0();
	Calls_4665b0 & delegate();
};

Calls_4665b0 & Calls_4665b0::delegate()
{
	call4666c0();
	field31.call9b71d0();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4665e0_At31
{
	int call9b7210();
};

class Calls_4665e0
{
public:
	char unknown0[0x31];
	Calls_4665e0_At31 field31;
	int call466650();
	int delegate();
};

int Calls_4665e0::delegate()
{
	field31.call9b7210();
	return call466650();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_466600_At31
{
	int call9b70f0();
};

class Calls_466600
{
public:
	char unknown0[0x31];
	Calls_466600_At31 field31;
	int call4666c0();
	Calls_466600 & delegate();
};

Calls_466600 & Calls_466600::delegate()
{
	call4666c0();
	field31.call9b70f0();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_466630_At31
{
	int call9b7130();
};

class Calls_466630
{
public:
	char unknown0[0x31];
	Calls_466630_At31 field31;
	int call466650();
	int delegate();
};

int Calls_466630::delegate()
{
	field31.call9b7130();
	return call466650();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_466670_At31
{
	int call9b7290();
};

class Calls_466670
{
public:
	char unknown0[0x31];
	Calls_466670_At31 field31;
	int call4666c0();
	Calls_466670 & delegate();
};

Calls_466670 & Calls_466670::delegate()
{
	call4666c0();
	field31.call9b7290();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4666a0_At31
{
	int call9b72d0();
};

class Calls_4666a0
{
public:
	char unknown0[0x31];
	Calls_4666a0_At31 field31;
	int call466650();
	int delegate();
};

int Calls_4666a0::delegate()
{
	field31.call9b72d0();
	return call466650();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_4666c0
{
public:
	int call46cb90();
	Calls_4666c0 & delegate();
};

Calls_4666c0 & Calls_4666c0::delegate()
{
	call46cb90();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4666e0_At31
{
	int call9b72f0();
};

class Calls_4666e0
{
public:
	char unknown0[0x31];
	Calls_4666e0_At31 field31;
	int call4666c0();
	Calls_4666e0 & delegate();
};

Calls_4666e0 & Calls_4666e0::delegate()
{
	call4666c0();
	field31.call9b72f0();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_466710_At31
{
	int call9b7330();
};

class Calls_466710
{
public:
	char unknown0[0x31];
	Calls_466710_At31 field31;
	int call466650();
	int delegate();
};

int Calls_466710::delegate()
{
	field31.call9b7330();
	return call466650();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_46cb90_At10
{
	int call9b8e80();
};

struct Calls_46cb90_At20
{
	int call9b8e80();
};

class Calls_46cb90
{
public:
	char unknown0[0x10];
	Calls_46cb90_At10 field10;
	char unknown11[0xf];
	Calls_46cb90_At20 field20;
	int call9b8e80();
	Calls_46cb90 & delegate();
};

Calls_46cb90 & Calls_46cb90::delegate()
{
	call9b8e80();
	field10.call9b8e80();
	field20.call9b8e80();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_46cc60_At10
{
	int call9bac80();
};

struct Calls_46cc60_At20
{
	int call9bac80();
};

class Calls_46cc60
{
public:
	char unknown0[0x10];
	Calls_46cc60_At10 field10;
	char unknown11[0xf];
	Calls_46cc60_At20 field20;
	int call9bac80();
	int delegate();
};

int Calls_46cc60::delegate()
{
	call9bac80();
	field10.call9bac80();
	return field20.call9bac80();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_46d360_At4
{
	int call9b6590();
	int call9cfaf0(int value0);
};

class Calls_46d360
{
public:
	char unknown0[0x4];
	Calls_46d360_At4 field4;
	char unknown5[0x3];
	int field8;
	int fieldc;
	int call9b6590();
	int call9cfaf0(int value0);
	Calls_46d360 & delegate(int arg0);
};

Calls_46d360 & Calls_46d360::delegate(int arg0)
{
	call9b6590();
	field4.call9b6590();
	call9cfaf0(arg0);
	field4.call9cfaf0(arg0);
	fieldc = 0;
	field8 = 0;
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_46d3c0_At4
{
	int call9cfa90(int value0);
};

class Calls_46d3c0
{
public:
	char unknown0[0x4];
	Calls_46d3c0_At4 field4;
	int call9cfa90(int value0);
	int delegate(int arg0);
};

int Calls_46d3c0::delegate(int arg0)
{
	call9cfa90(arg0);
	return field4.call9cfa90(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_46df70_At4a8
{
	int call9b3560();
};

class Calls_46df70
{
public:
	char unknown0[0x498];
	int field498;
	char unknown49c[0x8];
	int field4a4;
	Calls_46df70_At4a8 field4a8;
	char unknown4a9[0xf];
	int field4b8;
	int field4bc;
	void delegate();
};

void Calls_46df70::delegate()
{
	field498 = 0xffffffff;
	field4a4 = 0;
	field4a8.call9b3560();
	field4b8 = 0;
	field4bc = 0;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_46e740_At14
{
	int call9bac80();
};

struct Calls_46e740_At24
{
	int call9bac80();
};

class Calls_46e740
{
public:
	char unknown0[0x4];
	int field4;
	char unknown8[0xc];
	Calls_46e740_At14 field14;
	char unknown15[0xf];
	Calls_46e740_At24 field24;
	int delegate();
};

int Calls_46e740::delegate()
{
	field4 = 0;
	field14.call9bac80();
	return field24.call9bac80();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_46eb20_Atc
{
	int call9b8e80();
};

struct Calls_46eb20_At30
{
	int call9b8e80();
};

struct Calls_46eb20_At40
{
	int call9b8e80();
};

struct Calls_46eb20_At50
{
	int call9b8e80();
};

class Calls_46eb20
{
public:
	char unknown0[0xc];
	Calls_46eb20_Atc fieldc;
	char unknownd[0x23];
	Calls_46eb20_At30 field30;
	char unknown31[0xf];
	Calls_46eb20_At40 field40;
	char unknown41[0xf];
	Calls_46eb20_At50 field50;
	int call9b6590();
	Calls_46eb20 & delegate();
};

Calls_46eb20 & Calls_46eb20::delegate()
{
	call9b6590();
	fieldc.call9b8e80();
	field30.call9b8e80();
	field40.call9b8e80();
	field50.call9b8e80();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_471250_Atc
{
	int call9af040();
};

struct Calls_471250_At28
{
	int call9af040();
};

class Calls_471250
{
public:
	int field0;
	int field4;
	int field8;
	Calls_471250_Atc fieldc;
	char unknownd[0x1b];
	Calls_471250_At28 field28;
	Calls_471250 & delegate(int arg0, int arg1);
};

Calls_471250 & Calls_471250::delegate(int arg0, int arg1)
{
	field0 = arg0;
	field4 = arg1;
	field8 = 0;
	fieldc.call9af040();
	field28.call9af040();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_472c70_At0
{
	int call472440(int value0);
};

class Calls_472c70
{
public:
	Calls_472c70_At0 * field0;
	int delegate(int arg0);
};

int Calls_472c70::delegate(int arg0)
{
	return field0->call472440(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_48c3c0
{
public:
	int call7ad6a0(int value0, int value1, int value2, int value3, int value4);
	int delegate(int arg0);
};

int Calls_48c3c0::delegate(int arg0)
{
	return call7ad6a0(arg0, 0x30, 0, 0, 0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_48e8b0
{
public:
	char unknown0[0x7c];
	int field7c;
	int call428b20(int value0);
	void delegate();
};

void Calls_48e8b0::delegate()
{
	if (field7c != 0)
	{
	call428b20(field7c);
	field7c = 0;
	}
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_48f7a0_At64
{
	int call50ff30();
};

class Calls_48f7a0
{
public:
	char unknown0[0x64];
	Calls_48f7a0_At64 * field64;
	int call417cf0();
	int call7b9ab0();
	int delegate();
};

int Calls_48f7a0::delegate()
{
	field64->call50ff30();
	call417cf0();
	return call7b9ab0();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_492c00_At70
{
	int call7c2cd0();
};

struct Calls_492c00_At74
{
	int call7c2cd0();
};

class Calls_492c00
{
public:
	char unknown0[0x6c];
	int field6c;
	Calls_492c00_At70 * field70;
	Calls_492c00_At74 * field74;
	int call492ad0();
	int delegate(int arg0);
};

int Calls_492c00::delegate(int arg0)
{
	field6c = arg0;
	call492ad0();
	field70->call7c2cd0();
	return field74->call7c2cd0();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_4968e0
{
public:
	char unknown0[0x1d0];
	int field1d0;
	int call428b20(int value0);
	void delegate();
};

void Calls_4968e0::delegate()
{
	if (field1d0 != 0)
	{
	call428b20(field1d0);
	field1d0 = 0;
	}
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_49b650_At78c
{
	int call46ca50(int value0);
};

class Calls_49b650
{
public:
	char unknown0[0x78c];
	Calls_49b650_At78c field78c;
	int delegate(int arg0);
};

int Calls_49b650::delegate(int arg0)
{
	return field78c.call46ca50(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_49cd70
{
public:
	char unknown0[0x6c];
	int field6c;
	int call428b20(int value0);
	void delegate();
};

void Calls_49cd70::delegate()
{
	if (field6c != 0)
	{
	call428b20(field6c);
	field6c = 0;
	}
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_4a8fc0
{
public:
	int call4a8fe0(int value0);
	int delegate();
};

int Calls_4a8fc0::delegate()
{
	return call4a8fe0(1);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_4a9120
{
public:
	int call4a8fe0(int value0);
	int call890710(int value0);
	int call890c90();
	int delegate();
};

int Calls_4a9120::delegate()
{
	call4a8fe0(0);
	call890710(0);
	return call890c90();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_4a9210
{
public:
	char unknown0[0x74];
	int field74;
	int call4a9120();
	int delegate(int arg0);
};

int Calls_4a9210::delegate(int arg0)
{
	field74 = arg0;
	return call4a9120();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_4a9bb0
{
public:
	char unknown0[0xbc];
	int fieldbc;
	int call428b20(int value0);
	void delegate();
};

void Calls_4a9bb0::delegate()
{
	if (fieldbc != 0)
	{
	call428b20(fieldbc);
	fieldbc = 0;
	}
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4a9c60_At100
{
	int call9b7270();
};

class Calls_4a9c60
{
public:
	char unknown0[0xfc];
	int fieldfc;
	Calls_4a9c60_At100 field100;
	int delegate();
};

int Calls_4a9c60::delegate()
{
	fieldfc = 0;
	return field100.call9b7270();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_4aa510
{
public:
	int call4aa3d0();
	int call4aa560();
	int delegate();
};

int Calls_4aa510::delegate()
{
	call4aa3d0();
	return call4aa560();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4aa790_Atc4
{
	int call9b7270();
};

class Calls_4aa790
{
public:
	char unknown0[0xc0];
	int fieldc0;
	Calls_4aa790_Atc4 fieldc4;
	int delegate();
};

int Calls_4aa790::delegate()
{
	fieldc0 = 0;
	return fieldc4.call9b7270();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_4aa7c0
{
public:
	char unknown0[0x9c];
	int field9c;
	int call428b20(int value0);
	void delegate();
};

void Calls_4aa7c0::delegate()
{
	if (field9c != 0)
	{
	call428b20(field9c);
	field9c = 0;
	}
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_4ae410
{
public:
	char unknown0[0x6c];
	int field6c;
	int call48c3c0(int value0);
	int delegate();
};

int Calls_4ae410::delegate()
{
	return call48c3c0(field6c);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_4ae4f0
{
public:
	char unknown0[0x70];
	int field70;
	int call48c3c0(int value0);
	int delegate();
};

int Calls_4ae4f0::delegate()
{
	return call48c3c0(field70);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_4b0df0
{
public:
	char unknown0[0xa4];
	int fielda4;
	int call428b20(int value0);
	void delegate();
};

void Calls_4b0df0::delegate()
{
	call428b20(fielda4);
	fielda4 = 0;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_4b1b90
{
public:
	char unknown0[0xb8];
	int fieldb8;
	int call428b20(int value0);
	void delegate();
};

void Calls_4b1b90::delegate()
{
	call428b20(fieldb8);
	fieldb8 = 0;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4b3cf0_At8
{
	int call9b8e80();
};

struct Calls_4b3cf0_At18
{
	int call9b8e80();
};

struct Calls_4b3cf0_At28
{
	int call9b8e80();
};

struct Calls_4b3cf0_At38
{
	int call9b8e80();
};

class Calls_4b3cf0
{
public:
	char unknown0[0x8];
	Calls_4b3cf0_At8 field8;
	char unknown9[0xf];
	Calls_4b3cf0_At18 field18;
	char unknown19[0xf];
	Calls_4b3cf0_At28 field28;
	char unknown29[0xf];
	Calls_4b3cf0_At38 field38;
	Calls_4b3cf0 & delegate();
};

Calls_4b3cf0 & Calls_4b3cf0::delegate()
{
	field8.call9b8e80();
	field18.call9b8e80();
	field28.call9b8e80();
	field38.call9b8e80();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4b9ed0_At14
{
	int call9b8e80();
};

class Calls_4b9ed0
{
public:
	char unknown0[0x14];
	Calls_4b9ed0_At14 field14;
	int call40a6e0();
	Calls_4b9ed0 & delegate();
};

Calls_4b9ed0 & Calls_4b9ed0::delegate()
{
	call40a6e0();
	field14.call9b8e80();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4bf280_At14
{
	int call9af040();
};

struct Calls_4bf280_At30
{
	int call9af040();
};

struct Calls_4bf280_At50
{
	int call9af040();
};

struct Calls_4bf280_At70
{
	int call9b8e80();
};

struct Calls_4bf280_At88
{
	int call40bef0();
};

struct Calls_4bf280_At90
{
	int call40bef0();
};

struct Calls_4bf280_At98
{
	int call40bef0();
};

struct Calls_4bf280_Ata0
{
	int call40bef0();
};

class Calls_4bf280
{
public:
	char unknown0[0x14];
	Calls_4bf280_At14 field14;
	char unknown15[0x1b];
	Calls_4bf280_At30 field30;
	char unknown31[0x1f];
	Calls_4bf280_At50 field50;
	char unknown51[0x1f];
	Calls_4bf280_At70 field70;
	char unknown71[0x17];
	Calls_4bf280_At88 field88;
	char unknown89[0x7];
	Calls_4bf280_At90 field90;
	char unknown91[0x7];
	Calls_4bf280_At98 field98;
	char unknown99[0x7];
	Calls_4bf280_Ata0 fielda0;
	Calls_4bf280 & delegate();
};

Calls_4bf280 & Calls_4bf280::delegate()
{
	field14.call9af040();
	field30.call9af040();
	field50.call9af040();
	field70.call9b8e80();
	field88.call40bef0();
	field90.call40bef0();
	field98.call40bef0();
	fielda0.call40bef0();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4c1430_At2c
{
	int call9af350();
};

struct Calls_4c1430_At10
{
	int call9af350();
};

class Calls_4c1430
{
public:
	char unknown0[0x10];
	Calls_4c1430_At10 field10;
	char unknown11[0x1b];
	Calls_4c1430_At2c field2c;
	int call446ff0();
	int delegate();
};

int Calls_4c1430::delegate()
{
	field2c.call9af350();
	field10.call9af350();
	return call446ff0();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4c9b00_At10
{
	int call40bef0();
};

struct Calls_4c9b00_At18
{
	int call40bef0();
};

struct Calls_4c9b00_At24
{
	int call40bef0();
};

struct Calls_4c9b00_At2c
{
	int call40bef0();
};

class Calls_4c9b00
{
public:
	char unknown0[0x10];
	Calls_4c9b00_At10 field10;
	char unknown11[0x7];
	Calls_4c9b00_At18 field18;
	char unknown19[0xb];
	Calls_4c9b00_At24 field24;
	char unknown25[0x7];
	Calls_4c9b00_At2c field2c;
	Calls_4c9b00 & delegate();
};

Calls_4c9b00 & Calls_4c9b00::delegate()
{
	field10.call40bef0();
	field18.call40bef0();
	field24.call40bef0();
	field2c.call40bef0();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4cb8d0_At10
{
	int call40b100();
};

class Calls_4cb8d0
{
public:
	char unknown0[0x10];
	Calls_4cb8d0_At10 field10;
	int call453b40();
	Calls_4cb8d0 & delegate();
};

Calls_4cb8d0 & Calls_4cb8d0::delegate()
{
	call453b40();
	field10.call40b100();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4ccd70_At10
{
	int call9b8e80();
};

struct Calls_4ccd70_At20
{
	int call9b8e80();
};

struct Calls_4ccd70_At30
{
	int call9b8e80();
};

struct Calls_4ccd70_At48
{
	int call453b40();
};

class Calls_4ccd70
{
public:
	char unknown0[0x10];
	Calls_4ccd70_At10 field10;
	char unknown11[0xf];
	Calls_4ccd70_At20 field20;
	char unknown21[0xf];
	Calls_4ccd70_At30 field30;
	char unknown31[0x17];
	Calls_4ccd70_At48 field48;
	int call9b8e80();
	Calls_4ccd70 & delegate();
};

Calls_4ccd70 & Calls_4ccd70::delegate()
{
	call9b8e80();
	field10.call9b8e80();
	field20.call9b8e80();
	field30.call9b8e80();
	field48.call453b40();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4cd540_At10
{
	int call9b8e80();
};

class Calls_4cd540
{
public:
	char unknown0[0x10];
	Calls_4cd540_At10 field10;
	int call9b8e80();
	Calls_4cd540 & delegate();
};

Calls_4cd540 & Calls_4cd540::delegate()
{
	call9b8e80();
	field10.call9b8e80();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_577fb0
{
public:
	int call457be0(int value0);
	int delegate();
};

int Calls_577fb0::delegate()
{
	return call457be0(0x6b);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_57a0c0
{
public:
	char unknown0[0xc];
	int fieldc;
	int call579f50(int value0, int value1);
	void delegate();
};

void Calls_57a0c0::delegate()
{
	call579f50(1, 0);
	fieldc = 0xa;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_5de7b0
{
public:
	int call5de640(int value0, int value1);
	int delegate();
};

int Calls_5de7b0::delegate()
{
	call5de640(0, 0xd2ed7c);
	call5de640(1, 0xd316a0);
	call5de640(2, 0xd32990);
	return call5de640(3, 0xd31510);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_71cf70_At830
{
	int call9b3560();
};

struct Calls_71cf70_At840
{
	int call9b3560();
};

struct Calls_71cf70_At850
{
	int call9b73d0();
};

class Calls_71cf70
{
public:
	char unknown0[0x830];
	Calls_71cf70_At830 field830;
	char unknown831[0xf];
	Calls_71cf70_At840 field840;
	char unknown841[0xf];
	Calls_71cf70_At850 field850;
	int delegate();
};

int Calls_71cf70::delegate()
{
	field830.call9b3560();
	field840.call9b3560();
	return field850.call9b73d0();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_7908a0_At4
{
	int call9af040();
};

struct Calls_7908a0_At20
{
	int call9b8e80();
};

struct Calls_7908a0_At30
{
	int call9b8e80();
};

class Calls_7908a0
{
public:
	char unknown0[0x4];
	Calls_7908a0_At4 field4;
	char unknown5[0x1b];
	Calls_7908a0_At20 field20;
	char unknown21[0xf];
	Calls_7908a0_At30 field30;
	Calls_7908a0 & delegate();
};

Calls_7908a0 & Calls_7908a0::delegate()
{
	field4.call9af040();
	field20.call9b8e80();
	field30.call9b8e80();
	return *this;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_79c7b0_At28
{
	int call9af350();
};

struct Calls_79c7b0_Atc
{
	int call9af350();
};

class Calls_79c7b0
{
public:
	char unknown0[0xc];
	Calls_79c7b0_Atc fieldc;
	char unknownd[0x1b];
	Calls_79c7b0_At28 field28;
	int delegate();
};

int Calls_79c7b0::delegate()
{
	field28.call9af350();
	return fieldc.call9af350();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_7b46b0_At78
{
	int call9bac80();
};

class Calls_7b46b0
{
public:
	char unknown0[0x60];
	int field60;
	char unknown64[0x14];
	Calls_7b46b0_At78 field78;
	int call417ba0(int value0);
	int call428e80();
	int delegate();
};

int Calls_7b46b0::delegate()
{
	field60 = 0;
	call417ba0(1);
	call428e80();
	return field78.call9bac80();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_7d7970_At64
{
	int call50fff0();
};

class Calls_7d7970
{
public:
	char unknown0[0x64];
	Calls_7d7970_At64 * field64;
	int call417bc0();
	int call7d7880();
	int delegate();
};

int Calls_7d7970::delegate()
{
	call417bc0();
	call7d7880();
	return field64->call50fff0();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_7f2100_At64
{
	int call50fff0();
};

class Calls_7f2100
{
public:
	char unknown0[0x64];
	Calls_7f2100_At64 * field64;
	int call417bc0();
	int call7f2010();
	int delegate();
};

int Calls_7f2100::delegate()
{
	call417bc0();
	call7f2010();
	return field64->call50fff0();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_819cb0_At27c
{
	int call9b58f0();
};

struct Calls_819cb0_At28c
{
	int call9bac80();
};

class Calls_819cb0
{
public:
	char unknown0[0x27c];
	Calls_819cb0_At27c field27c;
	char unknown27d[0xf];
	Calls_819cb0_At28c field28c;
	int delegate();
};

int Calls_819cb0::delegate()
{
	field27c.call9b58f0();
	return field28c.call9bac80();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_87b2d0
{
public:
	char unknown0[0x60];
	int field60;
	char unknown64[0xc];
	int field70;
	int call87bd50(int value0);
	int delegate();
};

int Calls_87b2d0::delegate()
{
	field60 = 1;
	field70 = 0;
	return call87bd50(1);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
class Calls_882d60
{
public:
	char unknown0[0x60];
	int field60;
	char unknown64[0xc];
	int field70;
	int call417ba0(int value0);
	int call428e80();
	void delegate();
};

void Calls_882d60::delegate()
{
	field60 = 0;
	call417ba0(1);
	call428e80();
	field70 = 0;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_88ba90_At78
{
	int call9af350();
};

class Calls_88ba90
{
public:
	char unknown0[0x78];
	Calls_88ba90_At78 field78;
	int call48c2b0();
	int delegate();
};

int Calls_88ba90::delegate()
{
	field78.call9af350();
	return call48c2b0();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_88e340_At70
{
	int call9af350();
};

class Calls_88e340
{
public:
	char unknown0[0x70];
	Calls_88e340_At70 field70;
	int call48c2b0();
	int delegate();
};

int Calls_88e340::delegate()
{
	field70.call9af350();
	return call48c2b0();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_8fb9f0_At80
{
	int call9af350();
};

class Calls_8fb9f0
{
public:
	char unknown0[0x80];
	Calls_8fb9f0_At80 field80;
	int call48c2b0();
	int delegate();
};

int Calls_8fb9f0::delegate()
{
	field80.call9af350();
	return call48c2b0();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_960b60_At64
{
	int call50ff30();
};

class Calls_960b60
{
public:
	char unknown0[0x60];
	int field60;
	Calls_960b60_At64 * field64;
	int delegate();
};

int Calls_960b60::delegate()
{
	field60 = 4;
	return field64->call50ff30();
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_96cc00_At7c
{
	int call9bac80();
};

class Calls_96cc00
{
public:
	char unknown0[0x74];
	int field74;
	char unknown78[0x4];
	Calls_96cc00_At7c field7c;
	int call428e80();
	int call9650c0(int value0);
	int delegate();
};

int Calls_96cc00::delegate()
{
	call428e80();
	call9650c0(field74);
	return field7c.call9bac80();
}
