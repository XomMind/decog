// Batch 10: assorted game methods matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members and names are placeholders.
#include <string>
#include <vector>
#include "../util/stringutil.h"
using namespace std;

void logError(string location, string message);	// NOTE: placeholder name

bool vectorContains(vector<int> &values, int value);	// NOTE: placeholder name (0x9d51d0)
extern vector<int> networkThreadTypes;	// NOTE: placeholder name (0xd16178)

class Network
{
public:
	static void threadQuitting(int threadType);
};

void Network::threadQuitting(int threadType)
{
	if (!vectorContains(networkThreadTypes,threadType))
	{
		logError("Network::threadQuitting()","threadType not found: " + intToString(threadType));
	}
}

void logInfo(string location, string message);	// NOTE: placeholder name (0x405090)

// NOTE: placeholder names for the global containers cleared at game end
struct GlobalPool1 { void clearAll(bool deleteItems); };	// 0x9d34b0
struct GlobalPool2 { void clearAll(bool deleteItems); };	// 0x9d35d0
struct GlobalPool3 { void clearAll(bool deleteItems); };	// 0x9d3860
struct GlobalPool4 { void clearAll(bool deleteItems); };	// 0x9d1890
struct GlobalPool5 { void clearAll(bool deleteItems); };	// 0x9d08a0
struct GlobalPool6 { void clearAll(bool deleteItems); };	// 0x9d0d30
struct GlobalPool7 { void clearAll(bool deleteItems); };	// 0x9d0350
struct GlobalPool8 { void clearAll(bool deleteItems); };	// 0x9d1600
extern GlobalPool1 globalPool1;	// 0xd20404
extern GlobalPool2 globalPool2;	// 0xd33888
extern GlobalPool3 globalPool3;	// 0xd2f288
extern GlobalPool4 globalPool4;	// 0xd208d4
extern GlobalPool5 globalPool5;	// 0xd21720
extern GlobalPool6 globalPool6;	// 0xd1e720
extern GlobalPool7 globalPool7;	// 0xd2a298
extern GlobalPool8 globalPool8;	// 0xcfac14

class EndObjA { public: ~EndObjA(); };	// NOTE: placeholder name (dtor 0x7130c0)
class EndObjB { public: ~EndObjB(); };	// NOTE: placeholder name (dtor 0x4548e0)
extern EndObjA *endObjA;	// 0xcefc4c
extern EndObjB *endObjB;	// 0xcefc50
extern bool gameActive;	// NOTE: placeholder name (0xcefbc6)

class SoundMgr	// NOTE: placeholder name
{
public:
	void unknown4544e0();	// NOTE: placeholder name
	void unknown5003b0();	// NOTE: placeholder name
};
extern SoundMgr soundMgr;	// 0xd2d2a0

class EndTarget1 { public: void unknown96cc00(); };	// NOTE: placeholder name
class EndTarget2 { public: void unknown7fe7a0(); };	// NOTE: placeholder name
class EndTarget3 { public: void unknown882d60(); };	// NOTE: placeholder name
class CMission { public: void unknown987e30(); void unknown987fd0(); };	// NOTE: placeholder name
class EndTarget5 { public: void unknown4724e0(); };	// NOTE: placeholder name
class EndTarget6 { public: void unknown410e50(int value); };	// NOTE: placeholder name
extern EndTarget1 *endTarget1;	// 0xcec138
extern EndTarget2 *endTarget2;	// 0xcec054
extern EndTarget3 *endTarget3;	// 0xcec074
extern CMission *cmission;	// 0xcec034
extern EndTarget5 endTarget5;	// 0xd2c658
extern EndTarget6 *endTarget6;	// 0xcefa64

class GM
{
public:
	void endGame();
	void processSoundGroups();
	unsigned int getSessionTimeTotal();

	int pad0;
	int pad4;
	unsigned int sessionStartTime;	// NOTE: placeholder name
	unsigned int sessionIdleTime;	// NOTE: placeholder name
};

void GM::endGame()
{
	logInfo("GM::endGame()","Ending game");
	globalPool1.clearAll(true);
	globalPool2.clearAll(true);
	globalPool3.clearAll(true);
	globalPool4.clearAll(true);
	globalPool5.clearAll(true);
	globalPool6.clearAll(true);
	globalPool7.clearAll(true);
	globalPool8.clearAll(true);
	delete endObjA;	endObjA = NULL;
	delete endObjB;	endObjB = NULL;
	gameActive = false;
	soundMgr.unknown4544e0();
	soundMgr.unknown5003b0();
	endTarget1->unknown96cc00();
	endTarget2->unknown7fe7a0();
	endTarget3->unknown882d60();
	cmission->unknown987e30();
	cmission->unknown987fd0();
	endTarget5.unknown4724e0();
	endTarget6->unknown410e50(2);
}

void logMessage(string message);	// NOTE: placeholder name (0x404cb0)

struct SoundGroup	// NOTE: placeholder name
{
	int pad0;
	string name;
	int pad20;
	int channelCount;
};

class AudioMixer	// NOTE: placeholder name
{
public:
	int reserveChannels(int count);	// 0x419c70
	int groupChannels(int first,int last,int tag);	// 0x419e70
};
extern AudioMixer *audioMixer;	// 0xcefa90

class SoundGroupList	// NOTE: placeholder name (container at 0xd35870)
{
public:
	unsigned int size();	// 0x9b9260
	SoundGroup *&operator[](unsigned int i);	// 0x9b81f0
};
extern SoundGroupList soundGroups;	// 0xd35870
extern bool audioDisabled;	// NOTE: placeholder name (0xd28cbc)


void GM::processSoundGroups()
{
	if (audioDisabled)
	{
		logMessage("Skipping sound channel creation");
		return;
	}
	int total = 0;
	for (unsigned int i = 0; i < soundGroups.size(); i++)
		total += soundGroups[i]->channelCount;
	int allocated = audioMixer->reserveChannels(total);
	if (allocated != total)
	{
		logError("GM::processSoundGroups()","Unable to reserve " + intToString(total) + " channels for sound groups, disabling audio");
		audioDisabled = true;
	}
	if (!audioDisabled)
	{
		int start = 0;
		int got;
		for (unsigned int i = 0; i < soundGroups.size(); i++)
		{
			got = audioMixer->groupChannels(start,start+soundGroups[i]->channelCount-1,i);
			if (got != soundGroups[i]->channelCount)
			{
				logError("GM::processSoundGroups()","Unable to group channels for sound group " + soundGroups[i]->name + ", disabling audio");
				audioDisabled = true;
				return;
			}
			start += got;
		}
	}
}

//==================================================================
// CMap::updatePredictedExplosion
//==================================================================
struct Point	// NOTE: placeholder layout
{
	int x;
	int y;
};

class Entity;
class HEntity	// NOTE: placeholder layout
{
	int ID;
public:
	Entity *operator->() const;	// 0x9b6570
};

// NOTE: the exe folds this getter (0x9b4350, returns the field at +8) with the protobuf one, so it needs a name from that set
namespace Protobuf
{
	class PingRequest
	{
	public:
		virtual int GetCachedSize() const;
	};
}

class HExplosive	// NOTE: placeholder name
{
	int ID;
public:
	Protobuf::PingRequest *operator->() const;	// 0x9b65b0
};

struct ExplosionData	// NOTE: placeholder name
{
	char pad[0x30];
	int unknown30;	// NOTE: placeholder name
};

class Explosive	// NOTE: placeholder name
{
public:
	char pad[0x1a0];
	ExplosionData *explosion;	// NOTE: placeholder name
};

class Entity
{
public:
	void getExplosives(vector<HExplosive> *out, const Point &p, int radius);	// NOTE: placeholder name (0x5d6a80)
	const Point &getPosition();	// 0x45a4a0
};

class World	// NOTE: placeholder name
{
public:
	char pad[0x66c];
	HEntity player;	// NOTE: placeholder name
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	bool isInBounds(const Point &p);	// NOTE: placeholder name (0x9b43b0)
};

struct PredictedExplosion	// NOTE: placeholder name
{
	ExplosionData *data;
	int value;
	char pad[0x1c];
	void set(ExplosionData *data_,int value_,const Point &target,const Point &origin,const Point &target2);	// 0x455880
	void update(ExplosionData *data_);	// 0x515ab0
};

extern CellGrid cells;	// 0xcfd44c
extern World *world;	// 0xcefc4c
extern bool predictExplosions;	// NOTE: placeholder name (0xd28d32)

class CMap
{
public:
	void updatePredictedExplosion();

	char pad0[0x4c4];
	bool hasTarget;	// NOTE: placeholder name
	Point target;	// NOTE: placeholder name
	char pad4d0[8];
	bool aiming;	// NOTE: placeholder name
	char pad4d9[0x680 - 0x4d9];
	int mode;	// NOTE: placeholder name
	char pad684[0x6b0 - 0x684];
	PredictedExplosion predicted;	// NOTE: placeholder name
};

void CMap::updatePredictedExplosion()
{
	predicted.data = NULL;
	if (predictExplosions && mode == 8 && aiming)
	{
		if ((!hasTarget || !cells.isInBounds(target)) && 1)
		{
			logError("CMap::updatePredictedExplosion()","Possible invalid target, aborting");
			return;
		}
		vector<HExplosive> explosives;
		world->player->getExplosives(&explosives,target,-1);
		for (unsigned int i = 0; i < explosives.size(); i++)
		{
			ExplosionData *explosion = ((Explosive *)explosives[i]->Protobuf::PingRequest::GetCachedSize())->explosion;
			if (explosion)
			{
				if (predicted.data == NULL)
					predicted.set(explosion,explosion->unknown30,target,world->player->getPosition(),target);
				else
					predicted.update(explosion);
			}
		}
	}
}

//==================================================================
// PlayerData::addPolymindSuspicion
//==================================================================
class HItem	// NOTE: placeholder layout
{
	int ID;
public:
	bool isValid() const;
};

class EntityRecord	// NOTE: placeholder name
{
public:
	void unknown580dd0();	// NOTE: placeholder name
};

class SuspectEntity	// NOTE: placeholder name
{
public:
	EntityRecord *getRecord();	// 0x45b590
};

class HSuspect	// NOTE: placeholder name
{
	int ID;
public:
	SuspectEntity *operator->() const;	// 0x9b6570
};

struct SuspectEntry	// NOTE: placeholder name
{
	int pad0;
	HSuspect entity;
};

class SuspectList	// NOTE: placeholder name (0xcf6478)
{
public:
	unsigned int size();	// 0x9b9260
	SuspectEntry *&operator[](unsigned int i);	// 0x9b81f0
};

class CMapPoly	// NOTE: placeholder name, the object at 0xcec054
{
public:
	void unknown808020(HItem item);	// NOTE: placeholder name
	void unknown49adc0(int value);	// NOTE: placeholder name
	int unknown8054b0(int value);	// NOTE: placeholder name
};

class PolyObj	// NOTE: placeholder name, the object at 0xcefaa8
{
public:
	void unknown793690();	// NOTE: placeholder name
};

class WorldPoly	// NOTE: placeholder name, the object at 0xcefc4c
{
public:
	bool unknown464080();	// NOTE: placeholder name
	void unknown465930(int value);	// NOTE: placeholder name
};

class StatTracker	// NOTE: placeholder name, the object at 0xd2c658
{
public:
	void unknown4729d0(int id,int value,string text,int flag);	// NOTE: placeholder name
	void unknown472b90(int id,int value);	// NOTE: placeholder name
	int unknown472c90(int id);	// NOTE: placeholder name
};

void unknown4541b0(int a,int b,int c);	// NOTE: placeholder name
void unknown789ac0();	// NOTE: placeholder name

extern int polymindDisabled;	// NOTE: placeholder name (0xcf6475)
extern SuspectList suspects;	// 0xcf6478
extern CMapPoly *cmapPoly;	// 0xcec054
extern PolyObj *polyObj;	// 0xcefaa8
extern WorldPoly *worldPoly;	// 0xcefc4c
extern StatTracker statTracker;	// 0xd2c658
extern float suspicionValues[];	// NOTE: placeholder name (0xba8578)
extern int suspicionLimits[];	// NOTE: placeholder name (0xba85e8)
extern const int suspicionMin;	// NOTE: placeholder name (0xba87a8)
extern int suspicionScale;	// NOTE: placeholder name (0xcf4714)

class PlayerData
{
public:
	void addPolymindSuspicion(float amount, int type, HItem item);

	char pad0[0x120];
	float suspicion;	// NOTE: placeholder name
	int pad124;
	int polymindActive;	// NOTE: placeholder name
	vector<int> suspicionCounts;	// NOTE: placeholder name
};

void PlayerData::addPolymindSuspicion(float amount, int type, HItem item)
{
	if (polymindDisabled)
	{
		return;
	}
	float oldSuspicion = suspicion;
	suspicion += amount;
	if (suspicion >= 100.0)
	{
		suspicion = 100.0f;
	}
	else
	{
		if (suspicion < 0.0)
			suspicion = 0;
		if (item.isValid())
			cmapPoly->unknown808020(item);
	}
	if (suspicion == 100.0)
	{
		if (oldSuspicion < 100.0)
		{
			unknown4541b0(0x66,0,0);
			cmapPoly->unknown49adc0(1000);
			polyObj->unknown793690();
			unknown789ac0();
		}
	}
	else if (oldSuspicion >= 100.0)
	{
		polyObj->unknown793690();
		unknown789ac0();
	}
	if (oldSuspicion >= 80.0 && suspicion < 80.0)
	{
		for (unsigned int i = 0; i < suspects.size(); i++)
			suspects[i]->entity->getRecord()->unknown580dd0();
	}
	if (suspicionValues[type] != 0.0)
	{
		if (amount > 0.0)
		{
			logError("PlayerData::addPolymindSuspicion()","suspicion value for scored unsuspicious activity > 0");
			return;
		}
		if (type == 0x12)
			statTracker.unknown4729d0(0x45a,(int)(suspicionValues[type]*suspicionScale),"",-1);
		else
			statTracker.unknown4729d0(0x45a,(int)suspicionValues[type],"",-1);
		suspicionCounts[type]++;
		if (suspicionLimits[type] == 0 || suspicionCounts[type] <= suspicionLimits[type])
			statTracker.unknown472b90(0x13,(int)suspicionValues[type]);
	}
	if (polymindActive && worldPoly->unknown464080() && suspicion < suspicionMin && cmapPoly->unknown8054b0(0) == 0)
	{
		statTracker.unknown4729d0(0x45b,1,"",-1);
		if (statTracker.unknown472c90(0x45b)/50 <= 20)
			statTracker.unknown472b90(0x13,50);
		worldPoly->unknown465930(0);
	}
}

//==================================================================
// GM::getSessionTimeTotal
//==================================================================
string unsignedToString(unsigned int value);	// NOTE: placeholder name (0x405290)

// NOTE: the exe folds this getter (0x48e040) with the protobuf one, so it needs a name from that set
namespace Protobuf
{
	class Stats_Combat
	{
	public:
		virtual int GetCachedSize() const;
	};
}

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern Protobuf::Stats_Combat *sessionTimeSource;	// NOTE: placeholder name (0xcefa8c)

unsigned int GM::getSessionTimeTotal()
{
	if (sessionStartTime > tickCount)
	{
		logError("GM::getSessionTimeTotal()","sessionStartTime " + unsignedToString(sessionStartTime) + " greater than tick count (" + unsignedToString(tickCount) + ")");
		return 0;
	}
	if (sessionIdleTime > tickCount - sessionStartTime)
	{
		logError("GM::getSessionTimeTotal()","sessionIdleTime (" + unsignedToString(sessionIdleTime) + ") greater than recorded elapsed time (" + unsignedToString(tickCount - sessionStartTime) + ")");
		return 0;
	}
	if (tickCount - sessionTimeSource->Protobuf::Stats_Combat::GetCachedSize() > 10000)
	{
		unsigned int excess = tickCount - sessionTimeSource->Protobuf::Stats_Combat::GetCachedSize() + sessionIdleTime - 10000;
		return tickCount - sessionStartTime - excess;
	}
	else
	{
		return tickCount - sessionStartTime - sessionIdleTime;
	}
}

//==================================================================
// MessageLog::unserialize
//==================================================================
void logWarning(string location, string message);	// NOTE: placeholder name (0x404e50)
void logNote(string location, string message);	// NOTE: placeholder name (0x404fd0)

class SaveStream;	// NOTE: placeholder name

class MessageList	// NOTE: placeholder name
{
public:
	unsigned int size();	// 0x9b9260
	char pad[0x10];
};

void readMessageList(SaveStream *stream, MessageList *list, int flag);	// NOTE: placeholder name (0x9d60d0)
void removeMessage(MessageList *list, int index);	// NOTE: placeholder name (0x9d6210)
void readLogField10(SaveStream *stream, void *field);	// NOTE: placeholder name (0x4096f0)
void readLogWidth(SaveStream *stream, int *field);	// NOTE: placeholder name (0x9d8480)
void readLogField30(SaveStream *stream, void *field);	// NOTE: placeholder name (0x9cf520)

extern int logWindowWidth;	// NOTE: placeholder name (0xcebd64)

class MessageLog
{
public:
	void unserialize(SaveStream *stream, int limit);

	MessageList messages;	// NOTE: placeholder name
	char field10[0x2c - 0x10];	// NOTE: placeholder name
	int width;	// NOTE: placeholder name
	char field30[4];	// NOTE: placeholder name
};

void MessageLog::unserialize(SaveStream *stream, int limit)
{
	readMessageList(stream,&messages,0);
	if (limit != 0)
	{
		if (limit < 2)
		{
			logNote("MessageLog::unserialize()","limit too low! (" + intToString(limit) + ")");
		}
		else
		{
			while (messages.size() > limit)
				removeMessage(&messages,0);
		}
	}
	readLogField10(stream,field10);
	readLogWidth(stream,&width);
	readLogField30(stream,field30);
	if (width != logWindowWidth)
	{
		if (width < logWindowWidth)
			logWarning("MessageLog::unserialize()","Some saved log messages may be too long for narrower log window and be cut off (new messages will use updated width). This will only impact the current game.");
		else
			logWarning("MessageLog::unserialize()","Saved multi-line log messages will retain their original layout despite wider log window (new messages will use updated width). This will only impact the current game.");
		width = logWindowWidth;
	}
}
