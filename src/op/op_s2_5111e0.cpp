// op_s2_5111e0: queue a message from the message table to the log (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct Point;

class HEntity	// class, as src/op/op_s2.cpp declares it (OpS2_PhraseTextB ctor mangling)
{
public:
	int ID;
	HEntity() throw();	// 0x9b6590
	bool operator!=(HEntity other) const;	// 0x9b6510
};

struct OpS2M_MessageDef	// NOTE: placeholder name (message table entry)
{
	char pad00[0x20];
	int condition;	// NOTE: placeholder name: 1 = player only, 2 = entity known, 3 = location visible
	char pad24[0x47 - 0x24];
	bool flag47;	// NOTE: placeholder name
};
extern vector<OpS2M_MessageDef *> opS2M_messageDefs;	// NOTE: placeholder name (0xd2b4d8)

class OpS2M_Map	// NOTE: placeholder name (BS)
{
public:
	HEntity getPlayer();	// 0x4630f0
	bool unknown4631f0(HEntity entity);	// NOTE: placeholder name
	bool isVisible(const Point &p);	// 0x4631c0
};
extern OpS2M_Map *opS2M_map;	// NOTE: placeholder name (0xcefc4c)

struct OpS2_PhraseTextB	// NOTE: placeholder name
{
	OpS2_PhraseTextB(int index, string *a, string *b, string *c, HEntity d, HEntity e);	// 0x510f80
	char pad00[0x28];
};

class OpS2M_MessageLog	// NOTE: placeholder name
{
public:
	int push(OpS2_PhraseTextB *text);	// 0x5121f0
};
extern OpS2M_MessageLog opS2M_log_d2f75c;	// NOTE: placeholder name (0xd2f75c)
extern OpS2M_MessageLog opS2M_log_cf1080;	// NOTE: placeholder name (0xcf1080)

extern int opS2M_d28d18;	// NOTE: placeholder name
extern int opS2M_cfe5e4;	// NOTE: placeholder name
extern int opS2M_cea000;	// NOTE: placeholder name
extern int opS2M_cefb78;	// NOTE: placeholder name

bool opS2_showMessage_5111e0(int id, string *a, string *b, string *c, HEntity subject, HEntity object, const Point *at, bool log)	// NOTE: placeholder name
{
	switch (opS2M_messageDefs[id]->condition)
	{
		break;
	case 1:
		if (subject != opS2M_map->getPlayer())
			return false;
		else
			break;
	case 2:
		if (!opS2M_map->unknown4631f0(subject))
			return false;
		else
			break;
	case 3:
		if (!opS2M_map->isVisible(*at))
			return false;
	}
	if (log)
	{
		if (opS2M_d28d18 >= 0 && opS2M_messageDefs[id]->flag47 && opS2M_cfe5e4 && opS2M_cfe5e4 != opS2M_cea000)
		{
			opS2M_cfe5e4 = opS2M_cefb78;
			opS2M_log_d2f75c.push(new OpS2_PhraseTextB(0x2e2,0,0,0,HEntity(),HEntity()));
		}
		opS2M_log_d2f75c.push(new OpS2_PhraseTextB(id,a,b,c,subject,object));
	}
	else
		opS2M_log_cf1080.push(new OpS2_PhraseTextB(id,a,b,c,subject,object));
	return true;
}
