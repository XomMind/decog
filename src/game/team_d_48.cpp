// team_d_48: Entity::setAI 0x64ecf0 (replace the AI; drop feed links from the old controller).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <string>
using namespace std;

class Entity;
class EntityAI;

class HEntity
{
	int ID;
public:
	HEntity();
	Entity *operator->() const;
};

class HProp
{
	int ID;
public:
	HProp();
};

class AIData48	// NOTE: placeholder name (AI state of an entity, 0x45b590 result)
{
public:
	void setField451440(HEntity e);	// NOTE: placeholder name
};

struct PartData48	// NOTE: placeholder name and layout
{
	char	pad00[0x18];
	HEntity	owner;	// +0x18
};

class Part48	// NOTE: placeholder name (EntityPart4588f0)
{
public:
	PartData48 *unknown458950(int id);	// NOTE: placeholder name
};

class EntityAI
{
public:
	~EntityAI();
	bool unknown459090();			// NOTE: placeholder name
	Part48 *unknown4590f0();		// NOTE: placeholder name
	HEntity getOwner();				// 0x458e90
	void setField451440(HEntity e);	// NOTE: placeholder name
};

class Entity
{
public:
	char		pad000[4];
	HEntity		self;		// +0x04
	char		pad008[0x144 - 0x08];
	EntityAI	*ai;		// +0x144

	AIData48 *getAI();				// 0x45b590
	const string &getName();		// NOTE: placeholder name (folded getter 0x416f40)
	void setAI(EntityAI *newAI);	// NOTE: placeholder name (0x64ecf0)
};

class Map48	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	bool unknown463510(HEntity e);	// NOTE: placeholder name
	int unknown463540(HEntity e);	// NOTE: placeholder name
	bool unknown4635c0(HEntity e);	// NOTE: placeholder name
	int unknown4635f0(HEntity e);	// NOTE: placeholder name
	void unknown72e790(int value);	// NOTE: placeholder name
};
extern Map48 *world48;	// NOTE: placeholder name (0xcefc4c)
extern string feedName48_cfc9d8;	// NOTE: placeholder name
extern string feedName48_d2a414;	// NOTE: placeholder name

class ConsoleA	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA *consoleA_cec058;	// NOTE: placeholder name
class CLogMsgs
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern CLogMsgs *logMsgs_cec0b4;	// NOTE: placeholder name
bool logMessageSS_5111e0(int id, const string &text, const string &text2, int b, HEntity e, HEntity d, int f, int g);	// NOTE: placeholder name (0x5111e0)

void Entity::setAI(EntityAI *newAI)
{
	if (ai->unknown459090())
	{
		PartData48 *data = ai->unknown4590f0()->unknown458950(7);
		if (data)
			data->owner->getAI()->setField451440(HEntity());
	}
	if (world48->unknown463510(self))
	{
		string text = "Feed link from " + self->getName() + " lost";
		do { if (logMessageSS_5111e0(0x1d6,string(feedName48_cfc9d8),text,0,HEntity(),HEntity(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
		world48->unknown72e790(world48->unknown463540(self));
	}
	else if (world48->unknown4635c0(self))
	{
		string text = "Feed link from " + self->getName() + " lost";
		do { if (logMessageSS_5111e0(0x1d6,string(feedName48_d2a414),text,0,HEntity(),HEntity(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
		world48->unknown72e790(world48->unknown4635f0(self));
	}
	HEntity owner = ai->getOwner();
	delete ai;
	ai = newAI;
	ai->setField451440(owner);
}
