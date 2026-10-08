// op_s2_5141b0: record a phrase (combat-log style message) and mirror it to the Discord webhook (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct Point;

struct HEntity
{
	int ID;
	bool operator!=(HEntity other) const;	// 0x9b6510
};

struct OpS2P_PhraseDef	// NOTE: placeholder name (phrase table entry)
{
	char pad00[0x20];
	int condition;	// NOTE: placeholder name: 1 = player only, 2 = entity known, 3 = location visible
	int limit;	// NOTE: placeholder name: max times shown, -1 = never
	char pad28;
	bool noWebhook;	// NOTE: placeholder name
};
extern vector<OpS2P_PhraseDef *> opS2P_phraseDefs;	// NOTE: placeholder name (0xcf08c4)
extern vector<int> opS2P_phraseCounts;	// NOTE: placeholder name (0xcf4800)

class OpS2P_Map	// NOTE: placeholder name (BS)
{
public:
	HEntity getPlayer();	// 0x4630f0
	bool unknown4631f0(HEntity entity);	// NOTE: placeholder name
	bool isVisible(const Point &p);	// 0x4631c0
	int getTurn();	// 0x464270
};
extern OpS2P_Map *opS2P_map;	// NOTE: placeholder name (0xcefc4c)

class OpS2P_GameData	// NOTE: placeholder name (0xd1e860)
{
public:
	int unknown46f530();	// NOTE: placeholder name
};
extern OpS2P_GameData opS2P_gameData;	// NOTE: placeholder name

struct OpR1d_Phrase	// NOTE: placeholder name
{
	OpR1d_Phrase(int id, int turn, int unknown, const string *a, const string *b, const string *c);	// 0x455270
	string getText514060();	// NOTE: placeholder name
	int pad00;
	int turn;	// NOTE: placeholder name
	int speaker;	// NOTE: placeholder name: index into opS2P_entities, -1 = none
	char pad0c[0x1c - 0xc];
};
extern vector<OpR1d_Phrase *> opS2P_phrases;	// NOTE: placeholder name (0xcf4d00)

struct OpS2P_Speaker	// NOTE: placeholder name
{
	string getText();	// NOTE: placeholder name (0x46ed40)
};
class OpS2P_HSpeaker	// NOTE: placeholder name
{
	int ID;
public:
	OpS2P_Speaker *get23c();	// NOTE: placeholder name
};
extern vector<OpS2P_HSpeaker> opS2P_entities;	// NOTE: placeholder name (0xd1e88c)
extern string opS2P_noSpeaker;	// NOTE: placeholder name (0xd21b9c)

class OpS2P_Webhook	// NOTE: placeholder name (DiscordWebhook)
{
public:
	void addComment(string text);	// 0x4f9f50
	char pad00[0x34];
	bool enabled;	// NOTE: placeholder name
};
extern OpS2P_Webhook *opS2P_webhook;	// NOTE: placeholder name (0xcefb5c)

extern int opS2P_cf47b8;	// NOTE: placeholder name
extern int opS2P_cf47bc;	// NOTE: placeholder name

string intToString(int value);	// 0x4051f0

bool opS2_logPhrase_5141b0(int id, const string *a, const string *b, const string *c, HEntity subject, const Point *at)	// NOTE: placeholder name
{
	if (opS2P_phraseDefs[id]->limit != 0 && (opS2P_phraseCounts[id] >= opS2P_phraseDefs[id]->limit || opS2P_phraseDefs[id]->limit == -1))
		return false;
	switch (opS2P_phraseDefs[id]->condition)
	{
		break;
	case 1:
		if (subject != opS2P_map->getPlayer())
			return false;
		else
			break;
	case 2:
		if (!opS2P_map->unknown4631f0(subject))
			return false;
		else
			break;
	case 3:
		if (!opS2P_map->isVisible(*at))
			return false;
	}
	opS2P_phrases.push_back(new OpR1d_Phrase(id,opS2P_map->getTurn(),opS2P_gameData.unknown46f530(),a,b,c));
	opS2P_phraseCounts[id]++;
	if (opS2P_webhook && !opS2P_phraseDefs[id]->noWebhook && opS2P_webhook->enabled)
	{
		OpR1d_Phrase *phrase = opS2P_phrases.back();
		if (id == 9 && opS2P_cf47b8 == 15 && opS2P_cf47bc == 20)
			return true;
		opS2P_webhook->addComment(intToString(phrase->turn) + "  **|  " + (phrase->speaker != -1 ? opS2P_entities[phrase->speaker].get23c()->getText() : opS2P_noSpeaker) + "  |**  " + phrase->getText514060());
	}
	return true;
}
