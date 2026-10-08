// op_overmind_dispatch: Overmind::unknown6827d0 (0x6827d0), registers a dispatched party, broadcasts the
// squad composition from the dispatching access point and handles hacked access points (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

class OpOM_AI	// NOTE: placeholder name (EntityAI)
{
public:
	void setFollowEntity(class HEntity e, int flag);	// NOTE: placeholder name (0x5b2f80)
};
class OpOM_Faction { public: int ID; };	// NOTE: placeholder name
class Entity
{
public:
	const string &getName_416f40();	// NOTE: placeholder name (folded getter)
	int getAiType();	// 0x45a2a0
	Point unknown45a4c0();	// NOTE: placeholder name
	OpOM_AI *getAI_45b590();	// NOTE: placeholder name
	void changeFaction(OpOM_Faction faction, int a, int b);	// NOTE: placeholder name (0x5dc780)
};
class HEntity
{
public:
	int ID;
	Entity *operator->() const;	// 0x9b6570
};

struct OpOM_Record	// NOTE: placeholder name (machine record)
{
	char pad00[0x28];
	int unknown28;	// +0x28
	char pad2c[0x3c - 0x2c];
	int resets;	// +0x3c, NOTE: placeholder name
	vector<int> flags;	// +0x40, NOTE: placeholder name
	string unknown65cc80();	// NOTE: placeholder name
};
class OpOM_Prop	// NOTE: placeholder name (Prop)
{
public:
	OpOM_Record *getRecord_45cb30();	// NOTE: placeholder name (folded getter)
	void *getBuffer_4184d0();	// NOTE: placeholder name (folded getter)
};
class OpOM_HProp	// NOTE: placeholder name (HProp)
{
public:
	int ID;
	bool isValid() const;	// 0x9b65e0
	OpOM_Prop *get22c() const;	// NOTE: placeholder name (0x9b64f0)
};
class HProp { public: int ID; HProp(); };

struct OpOM_Access	// NOTE: placeholder name (access point)
{
	Point pos;
	char pad08[0x14 - 0x08];
	OpOM_HProp prop;	// +0x14
};

class Party	// NOTE: placeholder layout
{
public:
	int type;
	HEntity leader;	// +0x04
	void collectFollowers673630(vector<HEntity> &out);	// NOTE: placeholder name
	void pickArea673780();	// NOTE: placeholder name
};

class OpOM_Marker	// NOTE: placeholder name
{
public:
	void unknown6c20b0(int type, const Point &p, int value);	// NOTE: placeholder name
};
class OpOM_MarkerHandle	// NOTE: placeholder name
{
public:
	int ID;
	OpOM_Marker *get240() const;	// NOTE: placeholder name
};
class OpOM_Factory	// NOTE: placeholder name (0xcefaa8)
{
public:
	OpOM_MarkerHandle createC();	// NOTE: placeholder name (0x793190)
};
extern OpOM_Factory *opOM_factory_cefaa8;	// NOTE: placeholder name

class OpOM_World	// NOTE: placeholder name (BS at 0xcefc4c)
{
public:
	void *unknown463e50();	// NOTE: placeholder name
	vector<vector<OpOM_HProp> > *unknown463be0();	// NOTE: placeholder name
	vector<vector<OpOM_MarkerHandle> > *unknown463ec0();	// NOTE: placeholder name
	OpOM_Faction unknown463890();	// NOTE: placeholder name
	HEntity getPlayer();	// 0x4630f0
};
extern OpOM_World *opOM_world;	// NOTE: placeholder name

class OpOM_Mission	// NOTE: placeholder name (CMission at 0xcec034)
{
public:
	void unknown987de0();	// NOTE: placeholder name
};
extern OpOM_Mission *opOM_mission_cec034;	// NOTE: placeholder name

class OpOM_MessageLog	// NOTE: placeholder name (0xcf1080)
{
public:
	void setUnknown(int value);	// NOTE: placeholder name (0x451400)
};
extern OpOM_MessageLog opOM_messageLog_cf1080;	// NOTE: placeholder name
class OpOM_ConsoleA	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpOM_ConsoleA *opOM_consoleA_cec058;	// NOTE: placeholder name
class OpOM_LogMsgs	// NOTE: placeholder name (CLogMsgs at 0xcec0b4)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpOM_LogMsgs *opOM_logMsgs_cec0b4;	// NOTE: placeholder name
extern bool opOM_option_d28fb0;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);	// 0x406c90
};
extern RNG rng;

extern string opOM_partyTypeNames_cf25d8[];	// NOTE: placeholder name

string intToString(int value);	// 0x4051f0
bool opOM_log_5111e0(int id, const string &text, string *a, string *b, HProp c, HProp d, int e, int f);	// NOTE: placeholder name
void opOM_playSound_4541b0(int id, int a, int b);	// NOTE: placeholder name
void opOM_highlight_454260(OpOM_Access *access, int color);	// NOTE: placeholder name (opR1d_454260)
int OpT8a_findString(vector<string> &v, string s);
bool OpU8a_containsEntity(vector<OpOM_HProp> &v, OpOM_HProp e);	// NOTE: placeholder name
int OpU8a_indexOfEntity(vector<OpOM_HProp> &v, OpOM_HProp e);	// NOTE: placeholder name
bool opOM_removeValue_9d51d0(vector<int> &v, int value);	// NOTE: placeholder name (OpS8b_Fn9d51d0)
void opOM_eraseAt_9da940(vector<OpOM_HProp> &v, int index);	// NOTE: placeholder name (OpQ5_eraseAt)

#define OPOM_LOG(id,text,a) do { if (opOM_log_5111e0(id,text,a,0,HProp(),HProp(),0,0)) opOM_consoleA_cec058->unknown8758d0(true); opOM_logMsgs_cec0b4->scrollToEnd(); } while (0)	// NOTE: placeholder macro
#define OPOM_ALERT(sound,text) do { opOM_messageLog_cf1080.setUnknown(1); if ((sound) != -1 && !(opOM_option_d28fb0 && (sound) != 0 && (sound) != 1)) opOM_playSound_4541b0(sound,0,0); OPOM_LOG(0x324,text,0); opOM_logMsgs_cec0b4->scrollToEnd(); } while (0)	// NOTE: placeholder macro

class Overmind	// NOTE: placeholder layout
{
public:
	bool unknown6827d0(Party *party, OpOM_Access *access);	// NOTE: placeholder name
	void unknown684250(void *buffer, int flag);	// NOTE: placeholder name

	char pad00[0x50];
	vector<Party *> parties;	// +0x50, NOTE: placeholder name
	char pad60[0x118 - 0x60];
	vector<Point> usedAccess;	// +0x118, NOTE: placeholder name
};
extern Overmind overmind_cf6428;	// NOTE: placeholder name

bool Overmind::unknown6827d0(Party *party, OpOM_Access *access)
{
	parties.push_back(party);
	if (access && access->prop.isValid())
		opOM_highlight_454260(access,0x7f);
	if (access && access->prop.get22c() && opOM_world->unknown463e50())
	{
		vector<vector<OpOM_HProp> > *lists = opOM_world->unknown463be0();
		if (!(*lists)[18].empty())
		{
			vector<HEntity> entities;
			party->collectFollowers673630(entities);
			vector<string> tags;
			vector<int> hits;
			tags.push_back(entities.front()->getName_416f40());
			hits.push_back(1);
			for (unsigned int i = 1; i < entities.size(); i++)
			{
				int index = OpT8a_findString(tags,entities[i]->getName_416f40());
				if (index != -1)
					hits[index]++;
				else
				{
					tags.push_back(entities[i]->getName_416f40());
					hits.push_back(1);
				}
			}
			string text = access->prop.get22c()->getRecord_45cb30()->unknown65cc80() + " dispatching " + opOM_partyTypeNames_cf25d8[party->type] + " squad: ";
			for (unsigned int j = 0; j < tags.size(); j++)
			{
				if (j != 0)
					text += ", ";
				if (hits[j] == 1)
					text += tags[j];
				else
					text += intToString(hits[j]) + "x " + tags[j];
			}
			OPOM_LOG(0x1d6,string("BROADCAST"),&text);
			vector<OpOM_MarkerHandle> &list = (*opOM_world->unknown463ec0())[10];
			list.push_back(opOM_factory_cefaa8->createC());
			list.back().get240()->unknown6c20b0(10,party->leader->unknown45a4c0(),-1);
			opOM_mission_cec034->unknown987de0();
		}
		if (party->leader->getAiType() == 1)
		{
			if (OpU8a_containsEntity((*lists)[20],access->prop) || OpU8a_containsEntity((*lists)[21],access->prop))
			{
				party->pickArea673780();
				int index = OpU8a_indexOfEntity((*lists)[20],access->prop);
				if (index != -1)
				{
					opOM_removeValue_9d51d0((*lists)[20][index].get22c()->getRecord_45cb30()->flags,20);
					opOM_eraseAt_9da940((*lists)[20],index);
				}
				index = OpU8a_indexOfEntity((*lists)[21],access->prop);
				if (index != -1)
				{
					OpOM_Record *record = (*lists)[21][index].get22c()->getRecord_45cb30();
					record->resets++;
					if (record->resets > 1 && rng.chance((record->resets - 1) * 25))
					{
						record->resets = 0;
						opOM_removeValue_9d51d0(record->flags,21);
						opOM_eraseAt_9da940((*lists)[21],index);
						record->unknown28 = -1;
						unknown684250(access->prop.get22c()->getBuffer_4184d0(),0);
						string alert = "ALERT: " + record->unknown65cc80() + " system reset, remote access revoked.";
						OPOM_ALERT(-1,alert);
					}
				}
			}
			if (OpU8a_containsEntity((*lists)[22],access->prop))
			{
				vector<HEntity> followers;
				party->collectFollowers673630(followers);
				for (unsigned int i = 0; i < followers.size(); i++)
				{
					followers[i]->changeFaction(opOM_world->unknown463890(),2,1);
					followers[i]->getAI_45b590()->setFollowEntity(opOM_world->getPlayer(),0);
				}
				party = NULL;
				int found = OpU8a_indexOfEntity((*lists)[22],access->prop);
				opOM_removeValue_9d51d0((*lists)[22][found].get22c()->getRecord_45cb30()->flags,22);
				opOM_eraseAt_9da940((*lists)[22],found);
				usedAccess.push_back(access->pos);
				overmind_cf6428.unknown684250(access->prop.get22c()->getBuffer_4184d0(),0);
				usedAccess.clear();
				access->prop.get22c()->getRecord_45cb30()->unknown28 = -1;
				return false;
			}
		}
	}
	return true;
}
