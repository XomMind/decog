// Serialization records and EntityAI header-inline accessors (0x458c70-0x459335).
// NOTE: class layouts are partial; padding members, member names and most method names are placeholders.
#include <string>
#include <vector>
#include <ostream>
using namespace std;

class SaveStream;	// NOTE: placeholder name

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool operator==(HEntity other) const;
};

class HProp	// NOTE: placeholder layout
{
	int	ID;
public:
	HProp();
	void unserialize(SaveStream *stream);	// NOTE: placeholder name (0x9cfaf0)
	void serialize(ostream &out);			// NOTE: placeholder name (0x9cfa90)
};

class HExplosive	// NOTE: placeholder layout
{
	int	ID;
public:
	HExplosive();
};

void readLogField10(SaveStream *stream, void *field);	// NOTE: placeholder name (0x4096f0)
void readLogWidth(SaveStream *stream, int *field);	// NOTE: placeholder name (0x9d8480)
void readLogField30(SaveStream *stream, void *field);	// NOTE: placeholder name (0x9cf520)
void readExplosives(SaveStream *stream, vector<HExplosive> *v);	// NOTE: placeholder name (0x9d07e0)
void writeLogField30(ostream &out, void *field);	// NOTE: placeholder name (0x9cf540)
void writeLogWidth(ostream &out, int *field);	// NOTE: placeholder name (0x9d3b60)
void writeExplosives(ostream &out, vector<HExplosive> *v);	// NOTE: placeholder name (0x9d0840)
void writeString(ostream &out, string s);	// NOTE: placeholder name (0x409650)
template <class T> T randomElement(vector<T> &v);	// NOTE: placeholder name (0x9d5d00)

class PropExplosiveRecord	// NOTE: placeholder name
{
public:
	PropExplosiveRecord(SaveStream *stream);	// 0x458c70
	void serialize(ostream &out);			// NOTE: placeholder name (0x458d20)

	int					field0;		// NOTE: placeholder name
	int					field4;		// NOTE: placeholder name
	HProp				prop;		// NOTE: placeholder name
	vector<HExplosive>	explosives;	// NOTE: placeholder name
};

PropExplosiveRecord::PropExplosiveRecord(SaveStream *stream)
{
	readLogField30(stream,this);
	readLogWidth(stream,&field4);
	prop.unserialize(stream);
	readExplosives(stream,&explosives);
}

void PropExplosiveRecord::serialize(ostream &out)
{
	writeLogField30(out,this);
	writeLogWidth(out,&field4);
	prop.serialize(out);
	writeExplosives(out,&explosives);
}

class StringRecord	// NOTE: placeholder name
{
public:
	StringRecord(SaveStream *stream);	// NOTE: placeholder name (0x458d80)
	void serialize(ostream &out);		// NOTE: placeholder name (0x458e10)

	int		field0;	// NOTE: placeholder name
	int		field4;	// NOTE: placeholder name
	string	text;	// NOTE: placeholder name
};

StringRecord::StringRecord(SaveStream *stream)
{
	readLogWidth(stream,&field0);
	readLogWidth(stream,&field4);
	readLogField10(stream,&text);
}

void StringRecord::serialize(ostream &out)
{
	writeLogWidth(out,&field0);
	writeLogWidth(out,&field4);
	writeString(out,text);
}

struct EntityRecord	// NOTE: placeholder
{
	HEntity getOwner();	// 0x458e90

	char	pad00[0x50];
	HEntity	owner;		// NOTE: placeholder name
};

HEntity EntityRecord::getOwner()
{
	return owner;
}

class EntityPart4588f0	// NOTE: placeholder name (dtor 0x4588f0)
{
public:
	EntityPart4588f0() throw();	// 0x4588d0
	~EntityPart4588f0();
	void *unknown458950(int ID);	// NOTE: placeholder name
	bool unknown4589b0(int ID);	// NOTE: placeholder name
	bool unknown458a10(int ID);	// NOTE: placeholder name

	char pad[0x10];
};

struct MapRecord	// NOTE: placeholder name
{
	int unknown00;
};

struct AIOrder	// NOTE: placeholder name
{
	int unknown00;
	int type;
};

class EntityAI
{
public:
	HEntity unknown458e70();					// NOTE: placeholder name
	HEntity getFollowEntity();					// NOTE: placeholder name (0x458ed0)
	bool unknown458eb0();						// NOTE: placeholder name
	vector<int> *unknown458ef0();				// NOTE: placeholder name
	bool unknown458f10();						// NOTE: placeholder name
	unsigned int unknown458f30();				// NOTE: placeholder name
	HEntity unknown458f50();					// NOTE: placeholder name
	bool unknown458fb0(HEntity e);				// NOTE: placeholder name
	void *unknown459010();						// NOTE: placeholder name
	bool unknown459030();						// NOTE: placeholder name
	void *unknown459050();						// NOTE: placeholder name
	void *unknown459070();						// NOTE: placeholder name
	bool unknown459090();						// NOTE: placeholder name
	bool unknown4590b0(int ID);					// NOTE: placeholder name
	EntityPart4588f0 *unknown4590f0();			// NOTE: placeholder name
	void unknown459150(int ID);					// NOTE: placeholder name
	void unknown4591c0(int ID);					// NOTE: placeholder name
	void unknown459230();						// NOTE: placeholder name
	int unknown459280();						// NOTE: placeholder name
	HEntity unknown4592c0();					// NOTE: placeholder name
	int unknown4592e0();						// NOTE: placeholder name
	int unknown459300();						// NOTE: placeholder name
	void unknown459320();						// NOTE: placeholder name

	char					pad00[0x38];
	int						unknown38;			// NOTE: placeholder name
	char					pad3c[4];
	HEntity					unknown40;			// NOTE: placeholder name
	char					pad44[0x56 - 0x44];
	bool					unknown56;			// NOTE: placeholder name
	char					pad57;
	HEntity					followEntity;		// NOTE: placeholder name
	char					pad5c[0x6c - 0x5c];
	vector<int>				unknown6c;			// NOTE: placeholder name
	char					pad7c[0xbc - 0x7c];
	int						unknownBC;			// NOTE: placeholder name
	char					padc0[0xd0 - 0xc0];
	int						unknownD0;			// NOTE: placeholder name
	HEntity					unknownD4;			// NOTE: placeholder name
	char					padd8[0xf0 - 0xd8];
	vector<HEntity *>		candidates;			// NOTE: placeholder name
	char					pad100[0x108 - 0x100];
	char					unknown108[8];		// NOTE: placeholder name
	bool					unknown110;			// NOTE: placeholder name
	char					pad111[3];
	AIOrder					*order;	// NOTE: placeholder name
	char					unknown118[4];		// NOTE: placeholder name
	EntityPart4588f0		*part;				// NOTE: placeholder name
};

HEntity EntityAI::unknown458e70()
{
	return unknown40;
}

HEntity EntityAI::getFollowEntity()
{
	return followEntity;
}

bool EntityAI::unknown458eb0()
{
	return unknown56;
}

vector<int> *EntityAI::unknown458ef0()
{
	return &unknown6c;
}

bool EntityAI::unknown458f10()
{
	return candidates.empty();
}

unsigned int EntityAI::unknown458f30()
{
	return candidates.size();
}

HEntity EntityAI::unknown458f50()
{
	return candidates.empty() ? HEntity() : *randomElement(candidates);
}

bool EntityAI::unknown458fb0(HEntity e)
{
	for (unsigned int i = 0; i < candidates.size(); i++)
	{
		if (*candidates[i] == e)
			return true;
	}
	return false;
}

void *EntityAI::unknown459010()
{
	return unknown108;
}

bool EntityAI::unknown459030()
{
	return unknown110;
}

void *EntityAI::unknown459050()
{
	return order;
}

void *EntityAI::unknown459070()
{
	return unknown118;
}

bool EntityAI::unknown459090()
{
	return part;
}

bool EntityAI::unknown4590b0(int ID)
{
	if (!part)
		return false;
	return part->unknown458950(ID);
}

EntityPart4588f0 *EntityAI::unknown4590f0()
{
	if (!part)
	{
		EntityPart4588f0 *newPart = new EntityPart4588f0();
		part = newPart;
	}
	return part;
}

void EntityAI::unknown459150(int ID)
{
	if (part && part->unknown4589b0(ID))
	{
		delete part;
		part = NULL;
	}
}

void EntityAI::unknown4591c0(int ID)
{
	if (part && part->unknown458a10(ID))
	{
		delete part;
		part = NULL;
	}
}

void EntityAI::unknown459230()
{
	delete part;
	part = NULL;
}

int EntityAI::unknown459280()
{
	return order ? order->type : 11;
}

HEntity EntityAI::unknown4592c0()
{
	return unknownD4;
}

int EntityAI::unknown4592e0()
{
	return unknownBC;
}

int EntityAI::unknown459300()
{
	return unknownD0;
}

void EntityAI::unknown459320()
{
	unknown38 = -1;
}
