// Lead cluster c065: serialization records and small helpers around 0x5166d0-0x518bf0.
// NOTE: all class names, member names and layouts are placeholders recovered from the load order.
#include <string>
#include <vector>
#include <istream>
#include <ostream>
using namespace std;

class SaveStream;	// NOTE: placeholder name

class HExplosive	// NOTE: placeholder layout
{
	int	ID;
public:
	HExplosive();
};

extern vector<int> c065_list_d35b58;	// NOTE: placeholder name (0xd35b58)
extern vector<int> c065_list_cf3a20;	// NOTE: placeholder name (0xcf3a20)
extern vector<int> c065_list_d25de0;	// NOTE: placeholder name (0xd25de0)
extern vector<int> c065_list_cfd2ec;	// NOTE: placeholder name (0xcfd2ec)
extern vector<int> c065_list_d2d1c4;	// NOTE: placeholder name (0xd2d1c4)
extern vector<int> c065_list_d2c408;	// NOTE: placeholder name (0xd2c408)

void readLogWidth(SaveStream *stream, int *field);					// NOTE: placeholder name (0x9d8480)
void readLogField10(SaveStream *stream, void *field);				// NOTE: placeholder name (0x4096f0)
void readLogField30(SaveStream *stream, void *field);				// NOTE: placeholder name (0x9cf520)
void writeLogWidth(ostream &out, int *field);						// NOTE: placeholder name (0x9d3b60)
void c065_read9d4ec0(SaveStream *stream, void *field);				// NOTE: placeholder name (0x9d4ec0)
void c065_read9d6580(SaveStream *stream, void *field, int flag);	// NOTE: placeholder name (0x9d6580)
void c065_read9d66c0(SaveStream *stream, void *field, vector<int> *list);	// NOTE: placeholder name (0x9d66c0)
void c065_read9d67d0(SaveStream *stream, void *field, vector<int> *list);	// NOTE: placeholder name (0x9d67d0)
void c065_read9d68c0(SaveStream *stream, void *field, vector<int> *list);	// NOTE: placeholder name (0x9d68c0)
void c065_read9d69b0(SaveStream *stream, void *field, vector<int> *list);	// NOTE: placeholder name (0x9d69b0)

class C065_Rec5166d0	// NOTE: placeholder name
{
public:
	C065_Rec5166d0(SaveStream *stream);	// 0x5166d0

	int					field0;		// NOTE: placeholder name
	string				text;		// NOTE: placeholder name
	int					field20[7];	// NOTE: placeholder name
	vector<HExplosive>	listA;		// NOTE: placeholder name
	int					field4c;	// NOTE: placeholder name
	vector<HExplosive>	listB;		// NOTE: placeholder name
};

C065_Rec5166d0::C065_Rec5166d0(SaveStream *stream)
{
	readLogWidth(stream,&field0);
	readLogField10(stream,&text);
	c065_read9d4ec0(stream,&field20);
	c065_read9d6580(stream,&listA,0);
	readLogField30(stream,&field4c);
	c065_read9d66c0(stream,&listB,&c065_list_cfd2ec);
}

class C065_Rec516960	// NOTE: placeholder name
{
public:
	C065_Rec516960(SaveStream *stream);	// 0x516960

	int		field0;		// NOTE: placeholder name
	bool	field4;		// NOTE: placeholder name
	int		field8;		// NOTE: placeholder name
	int		fieldc;		// NOTE: placeholder name
	int		field10;	// NOTE: placeholder name
	int		field14;	// NOTE: placeholder name
};

C065_Rec516960::C065_Rec516960(SaveStream *stream)
{
	readLogWidth(stream,&field0);
	readLogField30(stream,&field4);
	c065_read9d67d0(stream,&field8,&c065_list_d35b58);
	c065_read9d68c0(stream,&fieldc,&c065_list_cf3a20);
	readLogWidth(stream,&field10);
	c065_read9d69b0(stream,&field14,&c065_list_d25de0);
}

struct RNG	// NOTE: placeholder
{
	bool chance(int percent);	// 0xb54b30 region
};

extern RNG rng_d20d00;	// NOTE: placeholder name (0xd20d00)

void c065_read9d6cd0(SaveStream *stream, void *field, int flag);	// NOTE: placeholder name (0x9d6cd0)
void c065_shuffle(vector<HExplosive>::iterator first, vector<HExplosive>::iterator last);	// NOTE: placeholder name (0x9d6e10)

class C065_Rec517880	// NOTE: placeholder name
{
public:
	C065_Rec517880(SaveStream *stream);	// 0x517880

	string				text;		// NOTE: placeholder name
	int					field1c;	// NOTE: placeholder name
	bool				field20;	// NOTE: placeholder name
	vector<HExplosive>	list;		// NOTE: placeholder name
};

C065_Rec517880::C065_Rec517880(SaveStream *stream)
{
	readLogWidth(stream,&field1c);
	readLogField30(stream,&field20);
	c065_read9d6cd0(stream,&list,0);
	if (rng_d20d00.chance(10))
		c065_shuffle(list.begin(),list.end());
}

void c065_read9d6e60(SaveStream *stream, void *field);	// NOTE: placeholder name (0x9d6e60)
void c065_read9d6f10(SaveStream *stream, void *field);	// NOTE: placeholder name (0x9d6f10)

class C065_Rec517960	// NOTE: placeholder name
{
public:
	C065_Rec517960(SaveStream *stream);	// 0x517960

	int		field0;		// NOTE: placeholder name
	int		field4;		// NOTE: placeholder name
	int		field8;		// NOTE: placeholder name
	int		fieldc;		// NOTE: placeholder name
	bool	field10;	// NOTE: placeholder name
	bool	field11;	// NOTE: placeholder name
	char	pad12[2];
	int		field14;	// NOTE: placeholder name
	int		field18;	// NOTE: placeholder name
};

C065_Rec517960::C065_Rec517960(SaveStream *stream)
{
	readLogWidth(stream,&field0);
	readLogWidth(stream,&field4);
	readLogWidth(stream,&field8);
	readLogWidth(stream,&fieldc);
	readLogField30(stream,&field10);
	readLogField30(stream,&field11);
	if (rng_d20d00.chance(50))
	{
		c065_read9d6e60(stream,&field14);
		c065_read9d6f10(stream,&field18);
	}
	else
	{
		c065_read9d6f10(stream,&field18);
		c065_read9d6e60(stream,&field14);
	}
}

void c065_read9d6fc0(SaveStream *stream, void *field, vector<int> *list);	// NOTE: placeholder name (0x9d6fc0)
void c065_write9da000(ostream &out, int value);							// NOTE: placeholder name (0x9da000)

class C065_Rec517a40	// NOTE: placeholder name
{
public:
	C065_Rec517a40(SaveStream *stream);	// 0x517a40

	int	field0;	// NOTE: placeholder name
	int	field4;	// NOTE: placeholder name
	int	field8;	// NOTE: placeholder name
};

C065_Rec517a40::C065_Rec517a40(SaveStream *stream)
{
	readLogWidth(stream,&field0);
	c065_read9d6fc0(stream,&field4,&c065_list_d2d1c4);
	readLogWidth(stream,&field8);
}

class C065_Rec517a90	// NOTE: placeholder name
{
public:
	void serialize(ostream &out);	// 0x517a90

	int	field0;	// NOTE: placeholder name
	int	field4;	// NOTE: placeholder name
	int	field8;	// NOTE: placeholder name
};

void C065_Rec517a90::serialize(ostream &out)
{
	writeLogWidth(out,&field0);
	c065_write9da000(out,field4);
	writeLogWidth(out,&field8);
}

class C065_Rec517da0	// NOTE: placeholder name
{
public:
	void read(SaveStream *stream);	// 0x517da0

	int		field0;		// NOTE: placeholder name
	string	text4;		// NOTE: placeholder name
	int		field20;	// NOTE: placeholder name
	string	text24;		// NOTE: placeholder name
};

void C065_Rec517da0::read(SaveStream *stream)
{
	readLogWidth(stream,&field0);
	readLogField10(stream,&text4);
	readLogWidth(stream,&field20);
	readLogField10(stream,&text24);
}

class Map;	// NOTE: placeholder name
extern Map *world;	// NOTE: placeholder name (0xcefc4c)
extern int c065_turnBase;	// NOTE: placeholder name (0xcf47fc)

class Map	// NOTE: placeholder name
{
public:
	int getTurn();			// NOTE: placeholder name (0x464270)
	int unknown463e50();	// NOTE: placeholder name
};

class C065_Rec518870	// NOTE: placeholder name
{
public:
	void init();	// 0x518870

	int	field0;	// NOTE: placeholder name
	int	field4;	// NOTE: placeholder name
	int	field8;	// NOTE: placeholder name
};

void C065_Rec518870::init()
{
	if (!world)
	{
		field4 = 0;
		field8 = 0;
	}
	else
	{
		field4 = world->getTurn();
		field8 = c065_turnBase;
	}
}

void c065_read9d6aa0(SaveStream *stream, void *field, vector<int> *list);	// NOTE: placeholder name (0x9d6aa0)

class C065_Rec5188c0	// NOTE: placeholder name
{
public:
	C065_Rec5188c0(SaveStream *stream);	// 0x5188c0

	int	field0;		// NOTE: placeholder name
	int	field4;		// NOTE: placeholder name
	int	field8;		// NOTE: placeholder name
	int	fieldc;		// NOTE: placeholder name
	int	field10;	// NOTE: placeholder name
};

C065_Rec5188c0::C065_Rec5188c0(SaveStream *stream)
{
	c065_read9d6aa0(stream,&field0,&c065_list_d2c408);
	readLogWidth(stream,&field4);
	readLogWidth(stream,&field8);
	readLogWidth(stream,&fieldc);
	readLogWidth(stream,&field10);
}

class C065_Rec518940	// NOTE: placeholder name
{
public:
	void serialize(ostream &out);	// 0x518940

	int	field0;		// NOTE: placeholder name
	int	field4;		// NOTE: placeholder name
	int	field8;		// NOTE: placeholder name
	int	fieldc;		// NOTE: placeholder name
	int	field10;	// NOTE: placeholder name
};

void C065_Rec518940::serialize(ostream &out)
{
	c065_write9da000(out,field0);
	writeLogWidth(out,&field4);
	writeLogWidth(out,&field8);
	writeLogWidth(out,&fieldc);
	writeLogWidth(out,&field10);
}

class C065_Rec518b30	// NOTE: placeholder name
{
public:
	void updateTurn();	// 0x518b30

	char	pad00[0x10];
	int		turn;	// NOTE: placeholder name
};

void C065_Rec518b30::updateTurn()
{
	turn = !world->unknown463e50() ? 0 : world->getTurn();
}

class C065_Sub456170	// NOTE: placeholder name
{
public:
	C065_Sub456170(C065_Sub456170 *other) throw();	// 0x456170
	char pad[0x14];
};

class C065_Rec518b70	// NOTE: placeholder name
{
public:
	void copyFrom(C065_Rec518b70 *other);	// 0x518b70

	vector<C065_Sub456170 *>	items;	// NOTE: placeholder name
	int							turn;	// NOTE: placeholder name
};

void C065_Rec518b70::copyFrom(C065_Rec518b70 *other)
{
	turn = other->turn;
	for (unsigned int i = 0; i < other->items.size(); i++)
	{
		C065_Sub456170 *item = new C065_Sub456170(other->items[i]);
		items.push_back(item);
	}
}

struct C065_Idx	// NOTE: placeholder name
{
	char	pad00[0x24];
	int		index;	// NOTE: placeholder name
};

extern string c065_namesA[];		// NOTE: placeholder name (0xd38648)
extern vector<string> c065_namesB;	// NOTE: placeholder name (0xd1d9b0)

class C065_Rec5169f0	// NOTE: placeholder name
{
public:
	string &getName();	// 0x5169f0

	char		pad00[8];
	C065_Idx	*a;		// NOTE: placeholder name
	C065_Idx	*b;		// NOTE: placeholder name
	char		pad10[4];
	C065_Idx	*c;		// NOTE: placeholder name
};

string &C065_Rec5169f0::getName()
{
	return c ? c065_namesA[c->index] : c065_namesB[a ? a->index : b->index];
}

void c065_fn4351e0(void *p);	// NOTE: placeholder name (0x4351e0)

struct C065_Sub58	// NOTE: placeholder name
{
	char	pad00[0x58];
	int		m58;
};

struct C065_Sub3c	// NOTE: placeholder name
{
	char	pad00[0x3c];
	int		m3c;
};

struct C065_Sub18c	// NOTE: placeholder name
{
	char	pad00[0x18c];
	int		m18c;
};

class C065_Rec517130	// NOTE: placeholder name
{
public:
	int *getTarget();	// 0x517130

	char			pad00[8];
	C065_Sub58		*a;	// NOTE: placeholder name
	C065_Sub3c		*b;	// NOTE: placeholder name
	char			pad10[4];
	C065_Sub18c		*c;	// NOTE: placeholder name
};

int *C065_Rec517130::getTarget()
{
	if (a)
		c065_fn4351e0(&a->m58);
	else if (b)
		c065_fn4351e0(&b->m3c);
	int *result;
	int *target;
	result = a ? &a->m58 : (target = b ? &b->m3c : &c->m18c);
	return result;
}

class C065_Rec5171d0	// NOTE: placeholder name
{
public:
	string getLabel();	// 0x5171d0
	string getLabel2();	// 0x517230

	char	pad00[8];
	void	*a;	// NOTE: placeholder name
	void	*b;	// NOTE: placeholder name
};

string C065_Rec5171d0::getLabel()
{
	return a ? "Record" : b ? "Dialogue" : "Analysis";
}

string C065_Rec5171d0::getLabel2()
{
	return a ? "Records" : b ? "Dialogue" : "Analyses";
}
