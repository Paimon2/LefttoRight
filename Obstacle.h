#pragma once
#include <vector>
#include "GLFunctions.h"
#include "Character.h"
extern void drawAllObstacles();
extern int checkCollision(int x, int y, int x1, int y1);
class Obstacle {
private:
	int x, y, width, height, type;
public:
	GLuint texture;
	Obstacle();
	~Obstacle();
	int getX() { return x; }
	int getY() { return y; }
	int getW() { return width; }
	int getH() { return height; }
	void setX(int val) { x = val; }
	void setY(int val) { y = val; }
	void setW(int val) { width = val; }
	void setH(int val) { height = val; }
};

extern std::vector<Obstacle> obstacles;