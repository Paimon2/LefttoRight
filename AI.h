#pragma once
#include "AI.h"
#include "Character.h"
#include "Vectors.h"
#include <vector>

enum AiMode {
	AM_followPlayer = 1,
	AM_followAttackPlayer = 2,
	AM_followDefendPlayer = 3,
	AM_attackPlayerDefensively = 4,
	AM_wanderAround = 5,
};

class AiEntity {
public:
	short direction; // 1 = left, 2 = right
	AiMode mode;
	int health;
	Character entity;
	AiEntity(AiMode mode_, Vector2i pos, int health);
	~AiEntity();
	void changeMode(AiMode mode);
	void runTick();
};

extern std::vector<AiEntity> npcs;