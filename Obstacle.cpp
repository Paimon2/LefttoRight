#include "Obstacle.h"
#include "Helpers.h"
#include "Main.h"
#include <iostream>
#include <algorithm>
#include "GLFunctions.h"
#include <iterator>
std::vector<Obstacle> obstacles;

void drawAllObstacles() {
	//int p = cameraX;
	for (int i = 0; i < obstacles.size(); i++ /*old approach for iterating through vector...*/) {
		if (i > (static_cast<int>(mainCharacter.x))) { break; }
		//drawTexture(obstacles.at(i).texture, obstacles.at(i).getX(), obstacles.at(i).getY(), obstacles.at(i).getW(), obstacles.at(i).getH(), 0);
		glColor3f(1, 1, 1);
		glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		PMGL();
		//glRecti(cameraX + obstacles.at(i).getX(), cameraY + obstacles.at(i).getY(), cameraX + obstacles.at(i).getX() + 40, cameraY + obstacles.at(i).getY() + 40);
		drawTexture(obstacles.at(i).texture, mainWorld.worldCam.x + obstacles.at(i).getX(), mainWorld.worldCam.y + obstacles.at(i).getY(), -40, -40, 0, NULL);
		glColor3f(0, 1, 1);
		char tpr[12];
		sprintf(tpr, "%d", i);
		renderText(mainWorld.worldCam.x + obstacles.at(i).getX(), mainWorld.worldCam.y + obstacles.at(i).getY(), GLUT_BITMAP_HELVETICA_18, tpr);
	}
}

int checkCollision(int x, int y, int width, int height) {
	Rect chrc;
	chrc.x = x;
	chrc.y = y;
	chrc.width = width;
	chrc.height = height;
	for (int i = 0; i < obstacles.size(); i++ /*old way of iterating through vector...*/) {
		if (i > (mainWorld.worldCam.x + 200)) { break; }
		Rect obst = obstacleToRect(obstacles.at(i));
		if (CheckCollisionRects(chrc, obst)) { return i; }
	}
	return 0;
}

Obstacle::Obstacle()
{
}

Obstacle::~Obstacle()
{
}
