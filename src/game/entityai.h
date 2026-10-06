#ifndef GAME_ENTITYAI_H
#define GAME_ENTITYAI_H
#include "../pathing/gamedecl.h"

// NOTE: partial Beta 17.1 layouts and descriptive placeholder member names.
// Unrecovered fields are opaque; this is not a complete allocatable game object.
struct AITargetRecord
{
	HEntity entity;
	int unknown04;
	int score;
};

struct AIOrder
{
	int unknown00;
	int type;
	HEntity subject;
};

class EntityAI
{
	char unknown00[0x56];
	bool preserveMemory;
	char unknown57[0x85];
	vector<HEntity> remembered;
	int rememberedTurn;
	vector<AITargetRecord *> targets;
	char unknown100[8];
	int targetCounter;
	char unknown10c[8];
	AIOrder *order;
public:
	// NOTE: placeholder names; addresses and behavior are recovered from the EXE.
	void addTarget(HEntity entity, int mode, int score, int unknown, int unknown2);
	void addTargetScore(HEntity entity, int amount);
	void prioritizeTarget(HEntity entity);
	void adjustTargetForOrder3(HEntity source, HEntity target);
	void adjustTargetForOrder4(HEntity source, HEntity target);
	void clearMemory();
	void clearMemoryUnlessPreserved();
};
#endif
