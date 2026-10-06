// NOTE: placeholder names and partial layout.
class Predicate_409b90
{
public:
	int field0;
	int field4;
	bool test(const Predicate_409b90 & arg0);
};

bool Predicate_409b90::test(const Predicate_409b90 & arg0)
{
	return (field0 == arg0.field0) && (field4 == arg0.field4);
}

// NOTE: placeholder names and partial layout.
class Predicate_409bd0
{
public:
	int field0;
	int field4;
	bool test(const Predicate_409bd0 & arg0);
};

bool Predicate_409bd0::test(const Predicate_409bd0 & arg0)
{
	return (field0 != arg0.field0) || (field4 != arg0.field4);
}

// NOTE: placeholder names and partial layout.
class Predicate_409cb0
{
public:
	int field0;
	int field4;
	bool test(int arg0, int arg1);
};

bool Predicate_409cb0::test(int arg0, int arg1)
{
	return (arg0 == field0) && (arg1 == field4);
}

// NOTE: placeholder names and partial layout.
class Predicate_409cf0
{
public:
	int field0;
	int field4;
	bool test(int arg0, int arg1);
};

bool Predicate_409cf0::test(int arg0, int arg1)
{
	return (arg0 != field0) || (arg1 != field4);
}

// NOTE: placeholder names and partial layout.
class Predicate_409d30
{
public:
	int field0;
	int field4;
	bool test();
};

bool Predicate_409d30::test()
{
	return (field0 < 0) || (field4 < 0);
}

// NOTE: placeholder names and partial layout.
class Predicate_40a7e0
{
public:
	int field0;
	int field4;
	int field8;
	int fieldc;
	bool test(const Predicate_40a7e0 & arg0);
};

bool Predicate_40a7e0::test(const Predicate_40a7e0 & arg0)
{
	return (field0 == arg0.field0) && (field4 == arg0.field4) && (field8 == arg0.field8) && (fieldc == arg0.fieldc);
}

// NOTE: placeholder names and partial layout.
class Predicate_40b700
{
public:
	int field0;
	int field4;
	int field8;
	int fieldc;
	bool test(int arg0, int arg1);
};

bool Predicate_40b700::test(int arg0, int arg1)
{
	return (arg0 >= field0) && (arg0 <= field8) && (arg1 >= field4) && (arg1 <= fieldc);
}

// NOTE: placeholder names and partial layout.
class Predicate_454c20
{
public:
	int field0;
	int field4;
	int field8;
	bool test(const Predicate_454c20 & arg0);
};

bool Predicate_454c20::test(const Predicate_454c20 & arg0)
{
	return (arg0.field0 >= 0) && (arg0.field0 <= field4) && (arg0.field4 >= 0) && (arg0.field4 <= field8);
}

// NOTE: placeholder names and partial layout.
class Predicate_45b910
{
public:
	char unknown0[0x34];
	int field34;
	bool test(int arg0);
};

bool Predicate_45b910::test(int arg0)
{
	return (field34 == 0x26) || (field34 == arg0);
}

// NOTE: placeholder names and partial layout.
class Predicate_45e380
{
public:
	char unknown0[0x20];
	int field20;
	int field24;
	bool test(int arg0);
};

bool Predicate_45e380::test(int arg0)
{
	return (field20 >= arg0) || (field24 != 0);
}

// NOTE: placeholder names and partial layout.
class Predicate_45e820
{
public:
	char unknown0[0x8];
	int field8;
	char unknownc[0xc];
	int field18;
	bool test();
};

bool Predicate_45e820::test()
{
	return (field8 == -2) && (field18 == 0);
}

// NOTE: placeholder names and partial layout.
class Predicate_49aa60
{
public:
	char unknown0[0x680];
	int field680;
	int field684;
	bool test();
};

bool Predicate_49aa60::test()
{
	return (field680 == 8) && (field684 == 2);
}

// NOTE: placeholder names and partial layout.
class Predicate_49aaa0
{
public:
	char unknown0[0x680];
	int field680;
	int field684;
	bool test();
};

bool Predicate_49aaa0::test()
{
	return (field680 == 8) && (field684 == 3);
}

// NOTE: placeholder names and partial layout.
class Predicate_49b570
{
public:
	char unknown0[0x1f4];
	int field1f4;
	int field1f8;
	bool test();
};

bool Predicate_49b570::test()
{
	return (field1f4 == 0) && (field1f8 == 0);
}

// NOTE: placeholder names and partial layout.
class Predicate_71cfb0
{
public:
	char unknown0[0x320];
	int field320;
	int field324;
	char unknown328[0x538];
	int field860;
	int field864;
	bool test();
};

bool Predicate_71cfb0::test()
{
	return (field320 >= field860) || (field324 >= field864);
}
