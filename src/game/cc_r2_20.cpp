// Entity header-inline accessors and mutators (0x45adb0-0x45b437) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members, member names and most method names are placeholders.
#include <string>
#include <vector>
using namespace std;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool operator==(HEntity entity) const;	// 0x9b78e0
};

class HProp	// NOTE: placeholder layout
{
	int	ID;
public:
	HProp();
};

int minInt(int a, int b);	// 0x9cdb30

void unknown9d0690(int *value, int delta, int limit);	// NOTE: placeholder name

struct EntityEffectDef	// NOTE: placeholder name
{
	int type;	// NOTE: placeholder name
};

struct EntityData4563c0	// NOTE: placeholder name
{
	EntityEffectDef *def;	// NOTE: placeholder name
};

class EntityPart4563c0	// NOTE: placeholder name (dtor 0x4563c0)
{
public:
	~EntityPart4563c0();
	int unknown456430(int a);	// NOTE: placeholder name
	bool unknown456600();		// NOTE: placeholder name
};

class AsciiImage	// NOTE: placeholder layout
{
public:
	AsciiImage() throw();
	~AsciiImage();
	bool unknown4589b0(int ID);	// NOTE: placeholder name
	bool unknown458a10(int ID);	// NOTE: placeholder name

	char pad[0x10];
};

template <class T> void eraseAt(vector<T> &v, unsigned int index);	// NOTE: placeholder name (0x9d8f20)

class Entity
{
public:
	int unknown45adb0(int a);				// NOTE: placeholder name
	bool unknown45ade0();					// NOTE: placeholder name
	bool unknown45ae30();					// NOTE: placeholder name
	AsciiImage *unknown45ae50();			// NOTE: placeholder name
	void unknown45aeb0(int ID);				// NOTE: placeholder name
	void unknown45af20(int ID);				// NOTE: placeholder name
	HEntity unknown45af90();				// NOTE: placeholder name
	int unknown45afb0();					// NOTE: placeholder name
	vector<int> *unknown45afd0();			// NOTE: placeholder name
	bool unknown45aff0();					// NOTE: placeholder name
	HEntity *unknown45b010(vector<HEntity *> *list, HEntity entity);	// NOTE: placeholder name
	void unknown45b070(const char *newName);	// NOTE: placeholder name
	void unknown45b0b0();					// NOTE: placeholder name
	void unknown45b0d0(int a, int b, int c);	// NOTE: placeholder name
	void unknown45b100(int *values);		// NOTE: placeholder name
	void unknown45b150(int value);			// NOTE: placeholder name
	void unknown45b180(int value);			// NOTE: placeholder name
	void unknown45b1b0(int value);			// NOTE: placeholder name
	void unknown45b1e0(int value);			// NOTE: placeholder name
	void unknown45b210(int value);			// NOTE: placeholder name
	void unknown45b240(int value);			// NOTE: placeholder name
	void unknown45b270(int value);			// NOTE: placeholder name
	void unknown45b2a0();					// NOTE: placeholder name
	void unknown45b2c0(int a, int b, int c, int d, bool e);	// NOTE: placeholder name
	void unknown45b300(int a);				// NOTE: placeholder name
	void unknown45b340(EntityData4563c0 *effect);	// NOTE: placeholder name
	void unknown45b360(int type);			// NOTE: placeholder name
	void unknown45b3d0(EntityData4563c0 *effect);	// NOTE: placeholder name

	int unknown5ca400();					// NOTE: placeholder name
	int unknown5ca670();					// NOTE: placeholder name
	int unknown5cab30();					// NOTE: placeholder name
	void projectileImpact(int a, int b, int c, int d, float e, int f, bool g, int h, int *i);	// 0x5f1010
	void takeDamage(int a, int b, int c, int d, int e, int f, int g, int h, HProp i, int j, int k, int l, int m, int n);	// 0x5e5520

	char						pad00[0xc];
	string						name;			// NOTE: placeholder name
	char						pad28[0x50 - 0x28];
	int							unknown50;		// NOTE: placeholder name
	int							unknown54;		// NOTE: placeholder name
	int							unknown58;		// NOTE: placeholder name
	char						pad5c[0x78 - 0x5c];
	int							slots[4];		// NOTE: placeholder name
	char						pad88[4];
	int							unknown8c;		// NOTE: placeholder name
	int							unknown90;		// NOTE: placeholder name
	int							unknown94;		// NOTE: placeholder name
	int							unknown98;		// NOTE: placeholder name
	char						pad9c[0xbc - 0x9c];
	void						*unknownBC;		// NOTE: placeholder name
	bool						unknownC0;		// NOTE: placeholder name
	char						padC1[0xdc - 0xc1];
	vector<EntityData4563c0 *>	unknownDC;		// NOTE: placeholder name
	EntityPart4563c0			*unknownEC;		// NOTE: placeholder name
	AsciiImage					*unknownF0;		// NOTE: placeholder name
	char						padF4[0x114 - 0xf4];
	HEntity						unknown114;		// NOTE: placeholder name
	char						pad118[4];
	int							unknown11c;		// NOTE: placeholder name
	char						pad120[4];
	vector<int>					unknown124;		// NOTE: placeholder name
};

int Entity::unknown45adb0(int a)
{
	if (unknownEC)
		return unknownEC->unknown456430(a);
	return 0;
}

bool Entity::unknown45ade0()
{
	return unknownEC && unknownEC->unknown456600();
}

bool Entity::unknown45ae30()
{
	return unknownF0;
}

AsciiImage *Entity::unknown45ae50()
{
	if (!unknownF0)
	{
		AsciiImage *image = new AsciiImage();
		unknownF0 = image;
	}
	return unknownF0;
}

void Entity::unknown45aeb0(int ID)
{
	if (unknownF0->unknown4589b0(ID))
	{
		delete unknownF0;
		unknownF0 = NULL;
	}
}

void Entity::unknown45af20(int ID)
{
	if (unknownF0 && unknownF0->unknown458a10(ID))
	{
		delete unknownF0;
		unknownF0 = NULL;
	}
}

HEntity Entity::unknown45af90()
{
	return unknown114;
}

int Entity::unknown45afb0()
{
	return unknown11c;
}

vector<int> *Entity::unknown45afd0()
{
	return &unknown124;
}

bool Entity::unknown45aff0()
{
	return unknownBC;
}

HEntity *Entity::unknown45b010(vector<HEntity *> *list, HEntity entity)
{
	for (unsigned int i = 0; i < list->size(); i++)
	{
		if ((*list)[i]->operator==(entity))
			return (*list)[i];
	}
	return NULL;
}

void Entity::unknown45b070(const char *newName)
{
	name = newName;
}

void Entity::unknown45b0b0()
{
	unknown50 = 0;
}

void Entity::unknown45b0d0(int a, int b, int c)
{
	unknown50 = a;
	unknown54 = b;
	unknown58 = c;
}

void Entity::unknown45b100(int *values)
{
	for (int i = 0; i < 4; i++)
		slots[i] += values[i];
}

void Entity::unknown45b150(int value)
{
	unknown8c += value;
}

void Entity::unknown45b180(int value)
{
	unknown9d0690(&unknown98,value,unknown5cab30());
}

void Entity::unknown45b1b0(int value)
{
	unknown9d0690(&unknown90,value,0);
}

void Entity::unknown45b1e0(int value)
{
	unknown9d0690(&unknown94,value,0);
}

void Entity::unknown45b210(int value)
{
	unknown98 += value;
}

void Entity::unknown45b240(int value)
{
	unknown94 = minInt(value,unknown5ca670());
}

void Entity::unknown45b270(int value)
{
	unknown90 = minInt(value,unknown5ca400());
}

void Entity::unknown45b2a0()
{
	unknownC0 = true;
}

void Entity::unknown45b2c0(int a, int b, int c, int d, bool e)
{
	projectileImpact(a,1,0,0,1.0f,c,e,b,&d);
}

void Entity::unknown45b300(int a)
{
	takeDamage(0,0,0,a,7,0,0,0,HProp(),1,8,0,0,1);
}

void Entity::unknown45b340(EntityData4563c0 *effect)
{
	unknownDC.push_back(effect);
}

void Entity::unknown45b360(int type)
{
	for (unsigned int i = 0; i < unknownDC.size(); i++)
	{
		if (unknownDC[i]->def->type == type)
		{
			eraseAt(unknownDC,i);
			return;
		}
	}
}

void Entity::unknown45b3d0(EntityData4563c0 *effect)
{
	for (unsigned int i = 0; i < unknownDC.size(); i++)
	{
		if (unknownDC[i] == effect)
		{
			eraseAt(unknownDC,i);
			return;
		}
	}
}
