// Item counter/effect helpers, effect lists and small serialization records (0x4584c0-0x458c64).
// NOTE: class layouts are partial; padding members, member names and most method names are placeholders.
#include <string>
#include <vector>
#include <ostream>
using namespace std;

class SaveStream;	// NOTE: placeholder name

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;

	Point();								// 0x453b40
	Point(const Point &p);					// 0x46ca50
	void unserialize(SaveStream *stream);	// NOTE: placeholder name (0x40a330)
	void serialize(ostream &out);			// NOTE: placeholder name (0x40a370)
};

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
};

class HItem	// NOTE: placeholder layout
{
	int	ID;
public:
	HItem();
	bool isValid() const;
};

class HProp	// NOTE: placeholder layout
{
	int	ID;
public:
	HProp() throw();
	bool isNull() const;
	void unserialize(SaveStream *stream);	// NOTE: placeholder name (0x9cfaf0)
	void serialize(ostream &out);			// NOTE: placeholder name (0x9cfa90)
};

class HExplosive	// NOTE: placeholder layout
{
	int	ID;
public:
	HExplosive();
};

void readLogWidth(SaveStream *stream, int *field);	// NOTE: placeholder name (0x9d8480)
void writeLogWidth(ostream &out, int *field);		// NOTE: placeholder name (0x9d3b60)

template <class T> void deleteVector(vector<T*> &v);			// NOTE: placeholder name (0x9d0710 for this instance)
template <class T> void eraseAt(vector<T> &v, unsigned int index);	// NOTE: placeholder name (0x9d8f20)

struct MapInfo	// NOTE: placeholder name
{
	int ID;
};

struct MapRecord	// NOTE: placeholder name
{
	MapInfo *info;
};

struct EntityData4588f0	// NOTE: placeholder name
{
	int ID;
};

struct ItemEffectType	// NOTE: placeholder name
{
	int	ID;	// NOTE: placeholder name
};

struct ItemEffect	// NOTE: placeholder name
{
	ItemEffectType	*type;	// NOTE: placeholder name
	int				state;	// NOTE: placeholder name
};

struct ItemTrait	// NOTE: placeholder name
{
	int unknown00;
	int state;	// NOTE: placeholder name
};

struct ItemType	// NOTE: placeholder name
{
	char	pad00[0xf0];
	int		unknownF0;	// NOTE: placeholder name
	int		unknownF4;	// NOTE: placeholder name
};

class ItemEffectList	// NOTE: placeholder name
{
public:
	~ItemEffectList();					// 0x4563c0
	bool unknown4567f0(int id, bool flag);	// NOTE: placeholder name

	vector<ItemEffect *>	effects;	// NOTE: placeholder name
};

class Item
{
public:
	bool unknown4584c0();					// NOTE: placeholder name
	void unknown4584f0();					// NOTE: placeholder name
	bool unknown458530();					// NOTE: placeholder name
	void unknown458560();					// NOTE: placeholder name
	void unknown458580();					// NOTE: placeholder name
	void addEffect(ItemEffect *effect);		// NOTE: placeholder name
	void unknown4585c0(int id);				// NOTE: placeholder name
	void unknown458630(ItemTrait *trait);	// NOTE: placeholder name
	void unknown458690(int a, bool b);		// NOTE: placeholder name
	void unknown458700(const string &s);		// NOTE: placeholder name

	char					pad00[8];
	ItemType				*type;
	char					pad0c[0x44 - 0xc];
	int						unknown44;		// NOTE: placeholder name
	vector<ItemEffect *>	effects;		// NOTE: placeholder name
	ItemEffectList			*unknown58;		// NOTE: placeholder name
	string					unknown5c;		// NOTE: placeholder name
};

bool Item::unknown4584c0()
{
	unknown44 = unknown44 - 1;
	return unknown44;
}

void Item::unknown4584f0()
{
	unknown44 = type->unknownF0 == 0xd0 ? type->unknownF4 : 8;
}

bool Item::unknown458530()
{
	unknown44 = unknown44 - 1;
	return unknown44 == 0;
}

void Item::unknown458560()
{
	unknown44 = -1;
}

void Item::unknown458580()
{
	unknown44 = unknown44 + 1;
}

void Item::addEffect(ItemEffect *effect)
{
	effects.push_back(effect);
}

void Item::unknown4585c0(int id)
{
	for (unsigned int i = 0; i < effects.size(); i++)
	{
		if (effects[i]->type->ID == id)
		{
			eraseAt(effects, i);
			return;
		}
	}
}

void Item::unknown458630(ItemTrait *trait)
{
	for (unsigned int i = 0; i < effects.size(); i++)
	{
		if (effects[i] == (ItemEffect *)trait)
		{
			eraseAt(effects, i);
			return;
		}
	}
}

void Item::unknown458690(int a, bool b)
{
	if (unknown58 && unknown58->unknown4567f0(a, b))
	{
		delete unknown58;
		unknown58 = NULL;
	}
}

void Item::unknown458700(const string &s)
{
	unknown5c = s;
}

class EntityPart4588f0	// NOTE: placeholder name (dtor 0x4588f0)
{
public:
	EntityPart4588f0();	// 0x4588d0
	~EntityPart4588f0();
	EntityData4588f0 *unknown458950(int ID);	// NOTE: placeholder name
	bool unknown4589b0(EntityData4588f0 *record);	// NOTE: placeholder name
	bool unknown458a10(int ID);			// NOTE: placeholder name
	bool unknown458a40();				// NOTE: placeholder name

	vector<EntityData4588f0 *> records;		// NOTE: placeholder name
};

class AsciiImage	// NOTE: placeholder layout
{
public:
	AsciiImage();

	vector<EntityData4588f0 *> unknown00;	// NOTE: placeholder name
};

EntityPart4588f0::EntityPart4588f0()
{
}

AsciiImage::AsciiImage()
{
}

EntityPart4588f0::~EntityPart4588f0()
{
	deleteVector(records);
}

EntityData4588f0 *EntityPart4588f0::unknown458950(int ID)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->ID == ID)
			return records[i];
	}
	return NULL;
}

bool EntityPart4588f0::unknown4589b0(EntityData4588f0 *record)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i] == record)
		{
			eraseAt(records, i);
			return records.empty();
		}
	}
	return false;
}

bool EntityPart4588f0::unknown458a10(int ID)
{
	return unknown4589b0(unknown458950(ID));
}

bool EntityPart4588f0::unknown458a40()
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->ID == 0x42)
			return true;
	}
	return false;
}

class EntityAI
{
public:
	bool unknown458a90();	// NOTE: placeholder name

	char	pad00[8];
	int		state;
	char	pad0c[0xb4 - 0xc];
	HItem	unknownB4;		// NOTE: placeholder name
};

bool EntityAI::unknown458a90()
{
	return state == 3 && unknownB4.isValid();
}

struct Region458750	// NOTE: placeholder name
{
	Region458750(int a_, int b_, int c_, int d_, const Point &p_);

	int		a;	// NOTE: placeholder name
	int		b;	// NOTE: placeholder name
	int		c;	// NOTE: placeholder name
	int		d;	// NOTE: placeholder name
	Point	p;	// NOTE: placeholder name
};

Region458750::Region458750(int a_, int b_, int c_, int d_, const Point &p_)
	: a	(a_)
	, b	(b_)
	, c	(c_)
	, d	(d_)
	, p	(p_)
{
}

struct PropPairRecord	// NOTE: placeholder name
{
	PropPairRecord(SaveStream *stream);	// 0x4587a0
	void serialize(ostream &out);		// NOTE: placeholder name (0x458830)

	int		field0;	// NOTE: placeholder name
	int		field4;	// NOTE: placeholder name
	HProp	propA;	// NOTE: placeholder name
	HProp	propB;	// NOTE: placeholder name
	Point	pos;	// NOTE: placeholder name
};

PropPairRecord::PropPairRecord(SaveStream *stream)
{
	readLogWidth(stream, &field0);
	readLogWidth(stream, &field4);
	propA.unserialize(stream);
	propB.unserialize(stream);
	pos.unserialize(stream);
}

void PropPairRecord::serialize(ostream &out)
{
	writeLogWidth(out, &field0);
	writeLogWidth(out, &field4);
	propA.serialize(out);
	propB.serialize(out);
	pos.serialize(out);
}

struct ExplosiveGroup	// NOTE: placeholder name
{
	ExplosiveGroup(int ID_);

	int					ID;			// NOTE: placeholder name
	int					unknown04;	// NOTE: placeholder name
	vector<HExplosive>	explosives;	// NOTE: placeholder name
	HProp				prop;		// NOTE: placeholder name
};

ExplosiveGroup::ExplosiveGroup(int ID_)
	: ID		(ID_)
	, unknown04	(-1)
{
}

struct Triple458ad0	// NOTE: placeholder name
{
	Triple458ad0(int a_, int b_, int c_);

	int a;	// NOTE: placeholder name
	int b;	// NOTE: placeholder name
	int c;	// NOTE: placeholder name
	int d;	// NOTE: placeholder name
};

Triple458ad0::Triple458ad0(int a_, int b_, int c_)
{
	a = a_;
	b = b_;
	c = c_;
	d = 0;
}

struct PropRecord458b10	// NOTE: placeholder name
{
	PropRecord458b10(SaveStream *stream);	// 0x458b10
	void serialize(ostream &out);			// NOTE: placeholder name (0x458b70)

	HProp	prop;	// NOTE: placeholder name
	int		field4;	// NOTE: placeholder name
	int		field8;	// NOTE: placeholder name
	int		fieldC;	// NOTE: placeholder name
};

PropRecord458b10::PropRecord458b10(SaveStream *stream)
{
	prop.unserialize(stream);
	readLogWidth(stream, &field4);
	readLogWidth(stream, &field8);
	readLogWidth(stream, &fieldC);
}

void PropRecord458b10::serialize(ostream &out)
{
	prop.serialize(out);
	writeLogWidth(out, &field4);
	writeLogWidth(out, &field8);
	writeLogWidth(out, &fieldC);
}

struct PropPoints458bd0	// NOTE: placeholder name
{
	PropPoints458bd0(HProp a_, HProp b_, const Point &p);

	bool			flag;	// NOTE: placeholder name
	HProp			a;		// NOTE: placeholder name
	HProp			b;		// NOTE: placeholder name
	vector<Point>	points;	// NOTE: placeholder name
};

PropPoints458bd0::PropPoints458bd0(HProp a_, HProp b_, const Point &p)
	: flag	(true)
	, a		(a_)
	, b		(b_)
{
	if (b.isNull() && p.x != -1)
		points.push_back(p);
}

