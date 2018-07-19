#pragma once
#include "glew_include/GL/glew.h"
#include "glut-3.7.6-bin/glut.h"

class Character {
private:
	float dropSpeed;
	float angle;
	/*For jumping*/
	bool isJumping;
	int jumpState; // 0 = going up, 1 = going down;
	int original_y;
	int original_jump_speed;
	int jump_speed;
public:
	bool isMainChar;
	bool isGravityBeingApplied;
	GLuint texture;
	int x, y, width, height;
	Character();
	~Character();
	void draw();
	void reset();
	void applyGravity();
	void reposition();
	void jump();
	void moveRight();
	void moveLeft();
};
