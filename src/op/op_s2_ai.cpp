// op_s2_ai: entity / AI helper methods in 0x57ef00-0x582600
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
	bool unknown409b90(const Point &other) const;	// NOTE: placeholder name (0x409b90)
};

class OpS2_AiF;

class OpS2_Group	// NOTE: placeholder name
{
public:
	int unknown9b4350();	// NOTE: placeholder name
};

class OpS2_HGroup	// NOTE: placeholder name
{
public:
	int ID;
	OpS2_Group *operator->() const;	// 0x9b7250
};

struct OpS2_EntityPart	// NOTE: placeholder name
{
	char pad0[0x24];
	int m24;	// +0x24
};

class OpS2_HEntity;

class OpS2_Entity	// NOTE: placeholder name
{
public:
	char pad0[8];
	OpS2_EntityPart *m8;	// +0x08
	const Point &getPosition();	// 0x45a4a0
	bool isPlayer();	// 0x5c7600
	OpS2_HGroup getGroup();	// 0x45a3f0
	bool isXomCandidate();	// 0x5d51a0
	const string &getName();	// 0x45a280
	bool unknown45aaa0(OpS2_HEntity target);	// NOTE: placeholder name (0x45aaa0)
	int unknown5d1390();	// NOTE: placeholder name (0x5d1390)
	OpS2_AiF *getAI();	// 0x45b590
};

class OpS2_HEntity	// NOTE: placeholder name
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
	OpS2_Entity *operator->() const;	// 0x9b6570
	bool operator==(OpS2_HEntity other) const;	// 0x9b78e0
};

class OpS2_Options	// NOTE: placeholder name
{
public:
	bool unknown46f4b0(int index);	// NOTE: placeholder name
};
extern OpS2_Options opS2_options;	// NOTE: placeholder name (0xd1e860)

class OpS2_RecLists	// NOTE: placeholder name
{
public:
	OpS2_HEntity *getEntity459570(OpS2_HEntity h);	// NOTE: placeholder name
};

class OpS2_PartAI	// NOTE: placeholder name
{
public:
	bool unknown458a40();	// NOTE: placeholder name
};

//--------------------------------------------------------------

class OpS2_AiA	// NOTE: placeholder name
{
public:
	OpS2_HEntity owner;	// +0x00
	char pad4[0xd8 - 4];
	int m0d8;	// +0xd8

	int getSpeed();	// 0x581530
};

int OpS2_AiA::getSpeed()
{
	if (owner->m8->m24 == 3 && opS2_options.unknown46f4b0(2))
	{
		return m0d8 * 2;
	}
	else
	{
		return m0d8;
	}
}

class OpS2_AiB	// NOTE: placeholder name
{
public:
	char pad0[0x56];
	bool m56;	// +0x56

	bool unknown5814f0(OpS2_HEntity h);	// 0x5814f0
	OpS2_HEntity *getEntity459570(OpS2_HEntity h);	// NOTE: placeholder name
};

bool OpS2_AiB::unknown5814f0(OpS2_HEntity h)
{
	return !m56 && getEntity459570(h) == NULL;
}

class OpS2_AiC	// NOTE: placeholder name
{
public:
	OpS2_HEntity owner;	// +0x00
	int m4;	// +0x04
	char pad8[0x6c - 8];
	vector<Point> m6c;	// +0x6c

	bool atTarget();	// 0x581580
};

bool OpS2_AiC::atTarget()
{
	return m4 == 1 && owner->getPosition().unknown409b90(m6c.front());
}

class OpS2_AiD	// NOTE: placeholder name
{
public:
	OpS2_HEntity owner;	// +0x00
	char pad4[0x11c - 4];
	OpS2_PartAI *m11c;	// +0x11c

	bool unknown5810e0();	// 0x5810e0
};

bool OpS2_AiD::unknown5810e0()
{
	if (m11c != NULL && owner->getGroup()->unknown9b4350() == 2)
	{
		return m11c->unknown458a40();
	}
	else
	{
		return false;
	}
}

class OpS2_AiE	// NOTE: placeholder name
{
public:
	OpS2_HEntity owner;	// +0x00
	char pad4[4];
	int m8;	// +0x08
	int mc;	// +0x0c

	void unknown5823b0();	// 0x5823b0
};

void OpS2_AiE::unknown5823b0()
{
	m8 = owner->unknown5d1390();
	if (m8 != 6)
	{
		mc = m8 + 9;
	}
	else
	{
		mc = -1;
	}
}

class OpS2_AiF	// NOTE: placeholder name
{
public:
	char pad0[0x58];
	OpS2_HEntity target;	// +0x58

	bool unknown580ba0(OpS2_HEntity h);	// 0x580ba0
};

bool OpS2_AiF::unknown580ba0(OpS2_HEntity h)
{
	if (target.operator->() != NULL)
	{
		if (target == h)
		{
			return true;
		}
		else if (target->getAI() != NULL)
		{
			return target->getAI()->unknown580ba0(h);
		}
	}
	return false;
}

struct OpS2_Rec	// NOTE: placeholder name
{
	OpS2_HEntity ent;	// +0x00
	int m4;	// +0x04
};

class OpS2_Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	OpS2_HEntity getPlayer();	// 0x4630f0
};
extern OpS2_Map *opS2_world;	// NOTE: placeholder name (0xcefc4c)

struct OpS2_Area	// NOTE: placeholder name
{
	Point a;
	Point b;
	OpS2_Area();	// 0x40b100
};

class OpS2_Cells	// NOTE: placeholder name (0xcfd44c)
{
public:
	void getRect(const Point &p, int radius, OpS2_Area &out);	// NOTE: placeholder name (0x9b4430)
};
extern OpS2_Cells opS2_cells;	// NOTE: placeholder name

class OpS2_AiG	// NOTE: placeholder name
{
public:
	char pad0[0xf0];
	vector<OpS2_Rec *> m0f0;	// +0xf0

	bool anyXomCandidate();	// 0x580c10
	bool anySmallGroup();	// 0x580c80
	bool anyHostileXom();	// 0x580d00
	bool unknown580dd0();	// 0x580dd0
	void unknown459470(OpS2_Area &area);	// NOTE: placeholder name (0x459470)
	void unknown5b3890(OpS2_HEntity h, int flag);	// NOTE: placeholder name (0x5b3890)
};

bool OpS2_AiG::anyXomCandidate()
{
	for (unsigned int i = 0; i < m0f0.size(); i++)
	{
		if (m0f0[i]->ent->isXomCandidate())
		{
			return true;
		}
	}
	return false;
}

bool OpS2_AiG::anySmallGroup()
{
	for (unsigned int i = 0; i < m0f0.size(); i++)
	{
		if (m0f0[i]->ent->getGroup()->unknown9b4350() <= 1)
		{
			return true;
		}
	}
	return false;
}

bool OpS2_AiG::anyHostileXom()
{
	for (unsigned int i = 0; i < m0f0.size(); i++)
	{
		if (m0f0[i]->ent->isPlayer() || (m0f0[i]->ent->unknown45aaa0(opS2_world->getPlayer()) && m0f0[i]->ent->isXomCandidate()))
		{
			return true;
		}
	}
	return false;
}

bool OpS2_AiG::unknown580dd0()
{
	for (unsigned int i = 0; i < m0f0.size(); i++)
	{
		if (m0f0[i]->ent->isPlayer() && m0f0[i]->m4 == -1)
		{
			OpS2_Area area;
			opS2_cells.getRect(m0f0[i]->ent->getPosition(),0xf,area);
			unknown459470(area);
			unknown5b3890(m0f0[i]->ent,0);
			return true;
		}
	}
	return false;
}

class OpS2_Spotter	// NOTE: placeholder name
{
public:
	OpS2_HEntity owner;	// +0x00
	char pad4[4];
	int m8;	// +0x08

	bool isSpotterOfThree();	// 0x57ef20
};

bool OpS2_Spotter::isSpotterOfThree()
{
	return m8 == 3 && owner->getName() == "N-01 Spotter" && owner->getGroup()->unknown9b4350() == 3;
}
