// NOTE: placeholder class, field, and operation names; partial layout.
class Push_46de70
{
public:
	char unknown0[0x1ec];
	int field1ec;
	int operate();
};

int Push_46de70::operate()
{
	if (field1ec == 0xee6b2800)
	{
	field1ec = 1;
	}
	field1ec = (field1ec + 1);
	return field1ec - 1;
}

// NOTE: placeholder class, field, and operation names; partial layout.
class Push_46dec0
{
public:
	char unknown0[0x1f0];
	int field1f0;
	int operate();
};

int Push_46dec0::operate()
{
	if (field1f0 == 0xee6b2800)
	{
	field1f0 = 1;
	}
	field1f0 = (field1f0 + 1);
	return field1f0 - 1;
}

struct Value_49ab00 { int value; };
// NOTE: placeholder class, field, and operation names; partial layout.
class Push_49ab00
{
public:
	int field0;
	char unknown4[0x7f0];
	Value_49ab00 field7f4;
	Value_49ab00 operate();
};

Value_49ab00 Push_49ab00::operate()
{
	return field7f4;
}

// NOTE: placeholder class, field, and operation names; partial layout.
class Push_49be20
{
public:
	int field0;
	int field4;
	int field8;
	int fieldc;
	unsigned char field10;
	char unknown11[0x3];
	int field14;
	int field18;
	Push_49be20 & operate(int arg0, int arg1, int arg2, int arg3, unsigned char arg4, int arg5, int arg6);
};

Push_49be20 & Push_49be20::operate(int arg0, int arg1, int arg2, int arg3, unsigned char arg4, int arg5, int arg6)
{
	field0 = arg0;
	field4 = arg1;
	field8 = arg2;
	fieldc = arg3;
	field10 = arg4;
	field14 = arg5;
	field18 = arg6;
	return *this;
}

struct Value_4ab6b0 { int value; };
// NOTE: placeholder class, field, and operation names; partial layout.
class Push_4ab6b0
{
public:
	int field0;
	char unknown4[0x74];
	Value_4ab6b0 field78;
	Value_4ab6b0 operate();
};

Value_4ab6b0 Push_4ab6b0::operate()
{
	return field78;
}

struct Value_4aeb30 { int value; };
// NOTE: placeholder class, field, and operation names; partial layout.
class Push_4aeb30
{
public:
	int field0;
	char unknown4[0x6c];
	Value_4aeb30 field70;
	Value_4aeb30 operate();
};

Value_4aeb30 Push_4aeb30::operate()
{
	return field70;
}

struct Value_4afcc0 { int value; };
// NOTE: placeholder class, field, and operation names; partial layout.
class Push_4afcc0
{
public:
	int field0;
	char unknown4[0x88];
	Value_4afcc0 field8c;
	Value_4afcc0 operate();
};

Value_4afcc0 Push_4afcc0::operate()
{
	return field8c;
}

struct Value_4b1460 { int value; };
// NOTE: placeholder class, field, and operation names; partial layout.
class Push_4b1460
{
public:
	int field0;
	char unknown4[0x7c];
	Value_4b1460 field80;
	Value_4b1460 operate();
};

Value_4b1460 Push_4b1460::operate()
{
	return field80;
}

struct Value_4b1b30 { int value; };
// NOTE: placeholder class, field, and operation names; partial layout.
class Push_4b1b30
{
public:
	int field0;
	char unknown4[0x70];
	Value_4b1b30 field74;
	Value_4b1b30 operate();
};

Value_4b1b30 Push_4b1b30::operate()
{
	return field74;
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_4977a0_Atb8
{
	int call7d8610(int value0);
};

class Calls_4977a0
{
public:
	char unknown0[0xb8];
	Calls_4977a0_Atb8 * fieldb8;
	char unknownbc[0x4];
	int fieldc0;
	void delegate(int arg0);
};

void Calls_4977a0::delegate(int arg0)
{
	fieldc0 = fieldb8->call7d8610(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_497f20_At8c
{
	int call7d8610(int value0);
};

class Calls_497f20
{
public:
	char unknown0[0x8c];
	Calls_497f20_At8c * field8c;
	char unknown90[0x4];
	int field94;
	void delegate(int arg0);
};

void Calls_497f20::delegate(int arg0)
{
	field94 = field8c->call7d8610(arg0);
}

// NOTE: placeholder names; partial layout and inferred delegate signatures.
struct Calls_498470_Atac
{
	int call7d8610(int value0);
};

class Calls_498470
{
public:
	char unknown0[0xac];
	Calls_498470_Atac * fieldac;
	char unknownb0[0x4];
	int fieldb4;
	void delegate(int arg0);
};

void Calls_498470::delegate(int arg0)
{
	fieldb4 = fieldac->call7d8610(arg0);
}
