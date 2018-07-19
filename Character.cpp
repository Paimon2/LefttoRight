#include "Character.h"
#include "Obstacle.h"
#include "Main.h"
#include "Callbacks.h"
#include "Helpers.h"
#include <iostream>
#include "../2DPlatformer/GLFunctions.h"

Character::Character()
{
	isGravityBeingApplied = 0;
	dropSpeed = 22;
	isJumping = 0;
	jumpState = 0;
	jump_speed = 22;
	x = 700;
	y = 680;
	isMainChar = 0;
	width = 40;
	height = 40;
}

void Character::reset()
{

	isGravityBeingApplied = 0;
	dropSpeed = 22;
	isJumping = 0;
	jumpState = 0;
	jump_speed = 22;
	x = 700;
	y = 680;
	/*Do not reset isMainChar*/
	width = 40;
	height = 40;
}
Character::~Character()
{
}

void Character::draw()
{

	if (isJumping) {
		if (jumpState == 0) {/*We are going up; speed decreases as we go up*/
			if (!checkCollision(x, y - jump_speed, -40, -40)) {
				y -= jump_speed;
				isMainChar ? mainWorld.worldCam.y += jump_speed : y -= jump_speed;
			}
			else {
				jumpState = 1;
			}
			jump_speed--;
		}
		if (jump_speed == 0) {/*Gravity pulls the character back*/ jumpState = 1; }
		if (jumpState == 1) {/*Going back down; speed increases as we go down*/

			if (!checkCollision(x, y + jump_speed, -40, -40)) {
				//if (y > original_y) {
				y += jump_speed;
				isMainChar ? mainWorld.worldCam.y -= jump_speed : y += jump_speed;
				jump_speed++;
			}
			else {
				/*if (jump_speed > 30) {
				resetGame(); // fall damage
				}*/
				isJumping = 0; jumpState = 0; jump_speed = 22;
			}





		}
		if (jumpState == 1 && y == original_y) { isJumping = 0; jumpState = 0; jump_speed = 22; isMainChar ? mainWorld.worldCam.y = CAMERA_ORIGINAL_Y : y = CAMERA_ORIGINAL_Y; }

	}

	// For now, draw a quad. TODO FIX LATER
	shouldDisplayRedCharacter ? glColor3f(1, 0, 0) : glColor3f(1, 1, 0);
	glViewport(0, 0, 1024, 768);

	shouldDisplayRedCharacter ? drawTexture(texture, x, y, -40, -40, 0, red) : drawTexture(texture, x, y, -40, -40, 0, NULL);
	///glRecti(x, y, x + 40, y + 40);
}

void Character::applyGravity()
{
	if (!isJumping) { /*Prevents double calls*/
		if (!checkCollision(x, y + dropSpeed, -40, -40)) {
			jumpState = 1;
			isJumping = 1;
		}
	}
}

void Character::reposition()
{
}

void Character::jump()
{
	if (!isJumping) {
		original_y = y;
		isJumping = 1;
	}

}

void Character::moveRight()
{


	for (int i = 0; i < 5; i++) {
		if (!checkCollision(x - 1, y, -40, -40)) {
			if (isMainChar) {
				mainWorld.worldCam.x--;
			}
			else {
				x++;
			}
			
		}

	}
}

void Character::moveLeft()
{
	for (int i = 0; i < 5; i++) {
		if (!checkCollision(x + 1, y, -40, -40)) {
			if (isMainChar) {
				mainWorld.worldCam.x++;
			}
			else {
				x--;
			}
		}
	}
}
