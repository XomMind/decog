// team_d_117: EntityAI member 0x5b9cb0 (callers EntityAI::takeTurn and EntityAI::unknown5b4530): a robot
// reacts to a sighting record - an alarm-capable robot either raises its group (and its allies' group), marking
// the alerted robots on the map and logging the alarm, or reports a jammed/suppressed alarm; otherwise it may
// pass the alert to its commander. Returns false only for a missing record.
// NOTE: class layouts are partial; names other than EntityAI are placeholders. Local names follow the
// stack-slot hash order.
#include <string>
#include <vector>
using namespace std;

template <class T> void OpQ5_eraseStep(vector<T> &list, int &index);	// NOTE: placeholder name

struct Pos
{
	int x;
	int y;
};

class Entity;

class HEntity
{
public:
	int ID;
	Entity *operator->() const;
};

class HProp
{
public:
	int ID;
	HProp();
};

class AI117	// NOTE: placeholder name (the robot's AI state)
{
public:
	void unknown5b4710(HEntity target, int a, int b, int c, bool *engaged);	// NOTE: placeholder name
};

class Group117	// NOTE: placeholder name (Group104's class)
{
public:
	bool unknown6719c0(bool quiet, HEntity e, HEntity target, bool *alerted, vector<HEntity> *out, const Pos *pos, int range);	// NOTE: placeholder name
	int getType117();	// NOTE: placeholder name (folded getter Array2D::getHeight)
};

class HGroup
{
public:
	int ID;
	HGroup();
	Group117 *operator->();	// NOTE: OpC_Handle::get230
};

struct EntityEffect;

class Entity	// NOTE: placeholder layout
{
public:
	char	pad00[0x28];
	HGroup	group;	// +0x28

	EntityEffect *unknown45acb0(int type);	// NOTE: placeholder name
	AI117 *getAI117();	// NOTE: placeholder name (folded getter ManualUI::unknown45b590)
	HGroup getGroup();
	const Pos &getPosition();
	int getFaction();
};

class EntityPart4588f0	// NOTE: placeholder name
{
public:
	void *unknown458950(int id);	// NOTE: placeholder name
};

class BS
{
public:
	int getTurn();
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	bool unknown463400(HEntity e);	// NOTE: placeholder name
	HGroup unknown463890(int i);	// NOTE: placeholder name
};
extern BS *world117_cefc4c;	// NOTE: placeholder name

class MapView117	// NOTE: placeholder name (CMap at 0xcec054)
{
public:
	void addPosMark(const Pos &pos, int value, bool flag);	// NOTE: placeholder name
	bool unknown49ac90(const Pos &pos, bool a, int b);	// NOTE: placeholder name
	void unknown8197f0(const Pos &pos, bool flag);	// NOTE: placeholder name
};
extern MapView117 *mapView117_cec054;	// NOTE: placeholder name
extern int marker117_d28e40;	// NOTE: placeholder name
extern int difficulty117_cf4718;	// NOTE: placeholder name

class ConsoleA117	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA117 *consoleA117_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs117_cec0b4;	// NOTE: placeholder name

bool showMessage117(int id, const void *text, const void *b, int c, HEntity d, HProp e, const void *at, int flag);	// NOTE: placeholder name (0x5111e0)

class Stats117	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	vector<int>	*current;

	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern Stats117 stats117_d2c658;	// NOTE: placeholder name

class PlayerData117	// NOTE: placeholder name (PlayerData at 0xcf45d8)
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern PlayerData117 playerData117_cf45d8;	// NOTE: placeholder name

struct Sighting117	// NOTE: placeholder name and layout
{
	HEntity	source;		// +0x00
	char	pad04[8];
	int		nextTurn;	// +0x0c
};

class EntityAI	// NOTE: placeholder layout
{
public:
	HEntity				self;		// +0x000
	int					unknown04;
	int					unknown08;
	char				pad00c[0x4c - 0xc];
	int					unknown4c;
	char				pad050[0x58 - 0x50];
	HEntity				unknown58;
	char				pad05c[0xb4 - 0x5c];
	HEntity				commander;	// +0x0b4
	char				pad0b8[0x100 - 0xb8];
	int					unknown100;
	char				pad104[0x11c - 0x104];
	EntityPart4588f0	*part;		// +0x11c

	bool unknown458a90();	// NOTE: placeholder name
	bool unknown581140();	// NOTE: placeholder name
	bool isSpotterOfThree();
	bool unknown5b9cb0(Sighting117 *seen);	// NOTE: placeholder name
};

bool EntityAI::unknown5b9cb0(Sighting117 *seen)
{
	if (!seen)
		return false;
	if (world117_cefc4c->getTurn() >= seen->nextTurn)
	{
		bool jammed = part && part->unknown458950(1) ? true : (self->unknown45acb0(0x20) ? false : unknown581140());
		if (unknown458a90())
		{
			if (!jammed)
			{
				if (commander.operator->())
				{
					commander->getAI117()->unknown5b4710(seen->source,1,0,1,0);
					do
					{
						if (showMessage117(0x23a,0,0,0,self,HProp(),0,0))
							consoleA117_cec058->unknown8758d0(true);
						logMsgs117_cec0b4->scrollToEnd();
					} while (0);
					unknown04 = 9;
					unknown08 = 0;
				}
			}
			else
			{
				stats117_d2c658.add4729d0(0x241,1,"",-1);
				do
				{
					if (showMessage117(0x23b,0,0,0,self,HProp(),0,0))
						consoleA117_cec058->unknown8758d0(true);
					logMsgs117_cec0b4->scrollToEnd();
				} while (0);
				if ((*stats117_d2c658.current)[0x241] == 10)
					playerData117_cf45d8.unknown77fbc0(0x72);
			}
		}
		else if (!jammed)
		{
			bool found = false;
			vector<HEntity> v;
			bool x = self->group->unknown6719c0(false,self,seen->source,&found,&v,0,-1);
			if (self->getGroup()->getType117() == 4 && world117_cefc4c->unknown463890(3)->unknown6719c0(false,self,seen->source,&found,&v,0,-1))
				x = true;
			if (x)
				seen->nextTurn = world117_cefc4c->getTurn() + 15;
			if (world117_cefc4c->getTurn() >= unknown100 && unknown08 < 6 && found && !unknown58.operator->())
			{
				unknown100 = world117_cefc4c->getTurn() + 15;
				for (int i = 0; i < v.size(); i++)
				{
					if (world117_cefc4c->unknown4631f0(v[i]))
						OpQ5_eraseStep(v,i);
				}
				if (!v.empty())
				{
					stats117_d2c658.add4729d0(0x240,1,"",-1);
					do
					{
						if (showMessage117(difficulty117_cf4718 ? 0x232 : 0x231,0,0,0,self,HProp(),0,0))
							consoleA117_cec058->unknown8758d0(true);
						logMsgs117_cec0b4->scrollToEnd();
					} while (0);
					if (world117_cefc4c->unknown4631f0(self))
					{
						mapView117_cec054->addPosMark(self->getPosition(),unknown4c,false);
						if (self->getFaction() == 0xc && marker117_d28e40)
							mapView117_cec054->unknown49ac90(self->getPosition(),true,marker117_d28e40);
						if (difficulty117_cf4718)
						{
							for (unsigned int j = 0; j < v.size(); j++)
								mapView117_cec054->unknown8197f0(v[j]->getPosition(),false);
						}
					}
				}
			}
		}
		else if (unknown08 < 6 && world117_cefc4c->unknown463400(self) && !isSpotterOfThree())
		{
			bool fail = false;
			bool ok = self->group->unknown6719c0(true,self,seen->source,&fail,0,0,-1);
			if (self->getGroup()->getType117() == 4 && world117_cefc4c->unknown463890(3)->unknown6719c0(true,self,seen->source,&fail,0,0,-1))
				ok = true;
			if (fail)
			{
				if (part && part->unknown458950(1))
				{
					do
					{
						if (showMessage117(0x234,0,0,0,self,HProp(),0,0))
							consoleA117_cec058->unknown8758d0(true);
						logMsgs117_cec0b4->scrollToEnd();
					} while (0);
				}
				else
				{
					stats117_d2c658.add4729d0(0x241,1,"",-1);
					stats117_d2c658.add4729d0(0x242,1,"",-1);
					do
					{
						if (showMessage117(0x233,0,0,0,self,HProp(),0,0))
							consoleA117_cec058->unknown8758d0(true);
						logMsgs117_cec0b4->scrollToEnd();
					} while (0);
					if ((*stats117_d2c658.current)[0x242] == 10)
						playerData117_cf45d8.unknown77fbc0(0x72);
				}
			}
		}
	}
	return true;
}
