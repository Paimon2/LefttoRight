#include "AI.h"
#include "Helpers.h"

std::vector<AiEntity> npcs;

AiEntity::AiEntity(AiMode mode_, Vector2i pos, int health_)
{
	entity.reset();
	direction = 2;
	mode = mode_;
	//position = pos;
	health = health_;
	
}

AiEntity::~AiEntity()
{
}

void AiEntity::changeMode(AiMode mode)
{
}

void AiEntity::runTick()
{
	bool collisionC = 0;
	/*Move the NPC entity*/
	entity.applyGravity();

	if (mode == AM_followPlayer) {

	}

	if (mode == AM_followAttackPlayer) {
		throw std::logic_error("Function not implemented: " __FILE__);
	}
	if (mode == AM_followDefendPlayer) {
		throw std::logic_error("Function not implemented: " __FILE__);
	}
	if (mode == AM_attackPlayerDefensively) {
		throw std::logic_error("Function not implemented: " __FILE__);
	}
	if (mode == AM_wanderAround) {

		

		if (yesOrNo(0.001)) { /*0.001% chance of changing direction each frame*/
			direction == 2 ? direction = 1 : direction = 2;
		}

		if (direction == 1) {
			/*AI entity is going left*/
			entity.moveRight();
		}



		if (direction == 2) {
			/*AI entity is going right*/
			
			entity.moveLeft();

		}


		if (!checkCollision((direction == 2 ? entity.x + 1 : entity.x - 1), entity.y - 14, -40, -40)) /*if we move 2 spaces and there is nothing below us, we should jump or not go that way*/
		{
			entity.jump();

		}

		if (collisionC) {

			if (!checkCollision(entity.x, entity.y - 14, -40, -40)) {
				entity.jump();
			}

			else {
				direction == 2 ? direction = 1 : direction = 2;
			}


		}

		

	}
}