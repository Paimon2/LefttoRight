#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "Obstacle.h"
#include <ctime>
#include "Helpers.h"
#include "Main.h"
#include "AI.h"
#include <ctime>
#include "../2DPlatformer/GLFunctions.h"
#include "glew_include/GL/glew.h"
#include "glut-3.7.6-bin/glut.h"


bool keystates[256];
double fps;
bool shouldDisplayRedCharacter = 0;
int frame = 0, timet, timeb;

AiEntity testZombie(AM_wanderAround, { 700, 650 }, 100);


void renderSceneGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	


	/*POINT pp;
	GetCursorPos(&pp);
	mainCharacter.x = pp.x;
	mainCharacter.y = pp.y;*/
	
	
	
	
	glColor3f(0, 0, 0);

	
	
	glViewport(0, 0, 1024, 768);
	
	drawTexture(background, 0, 0, 1024, 768, 0, NULL);
	drawAllObstacles();

	//glRecti(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	//drawTexture(background, -1, 0, GLWindowWidth, GLWindowHeight, 0);
	mainCharacter.draw();
	drawTexture(enemyT, mainWorld.worldCam.x + testZombie.entity.x, mainWorld.worldCam.y + testZombie.entity.y, -40, -40, 0, NULL);
	testZombie.runTick();
	//glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'a');
	
	
	
	//PMGL();
	if (inDebugMode) {
		char fps_char[16];
		sprintf(fps_char, "%4.2f FPS", fps);
		if (fps > 40) { glColor3f(0, 1, 0); }
		else if (fps > 20) { glColor3f(1, 1, 0); }
		else { glColor3f(1, 0, 0); }
		renderText(10, 20, GLUT_BITMAP_HELVETICA_12, fps_char);
	}

	
		glutSwapBuffers();
		glutPostRedisplay();
	
	
}


void idlingGL() {
	if (mainWorld.worldCam.y >= 4294960000) {
		mainWorld.worldCam.y = CAMERA_ORIGINAL_Y;
	}

	mainCharacter.applyGravity();

	std::cout << "Camera X: " << mainWorld.worldCam.x << std::endl;
	std::cout << "Camera Y: " << mainWorld.worldCam.y << std::endl;
	std::cout << "Character X: " << mainCharacter.x << std::endl;
	std::cout << "Character Y: " << mainCharacter.y << std::endl;

	int p = checkCollision(mainCharacter.x, mainCharacter.y - 5, -40, -40);
	if (p) {
		std::cout << "collision with obstacle: " << p << " " << rand() % 10 + 0 << std::endl;
	//	mainWorld.worldCam.reset();
		
		
		
	}

	//mainCharacter.applyGravity();
	if (mainCharacter.y > glutGet(GLUT_WINDOW_HEIGHT) + 200) { resetGame(); }

	if (keystates[' '] || keystates[GLUT_KEY_UP]) {
		mainCharacter.jump();
	}
	if (keystates['w'] || keystates['W'] || keystates[GLUT_KEY_LEFT]) {
		mainCharacter.moveRight();
	}
	if (keystates[GLUT_KEY_RIGHT] || keystates['a'] || keystates['A'] || keystates['s'] || keystates['S']) {
		mainCharacter.moveLeft();
	}

	if (inDebugMode) {
		frame++;
		timet = glutGet(GLUT_ELAPSED_TIME);

		if (timet - timeb > 1000) {
			fps = frame * 1000.0 / (timet - timeb);
			timeb = timet;
			frame = 0;
			shouldDisplayRedCharacter = 0;
		}
	}
	
	
	glutPostRedisplay();
}

void keyRepeatGL(unsigned char c, int x, int y) {
}

void keyboardFuncGL(unsigned char c, int x, int y) {
	
	if (c == 'y') {
		inDebugMode ? inDebugMode = 0 : inDebugMode = 1;
	}
	if (c == 'r') {
		resetGame();
	}
	keystates[c] = true;
	return;
}

void keyboardUpFuncGL(unsigned char c, int x, int y) {
	keystates[c] = false;
}



void mouseGL(int button, int state, int x, int y) {
	
}
void motionGL(int x, int y) {

}
void resizeGL(int w, int h) {

	int nw = w;
	int nh = h;
	if (w < 1024) { nw = 1024;  glutReshapeWindow(1024, nh); }
	if (h < 768) { nh = 768;  glutReshapeWindow(nw, 768); }

	if (h == 0)                                        // Prevent a divide-by-zero error
	{
		h = 1;                                      // Making Height Equal One
	}

	GLWindowWidth = w;
	GLWindowHeight = h;

	glViewport(0, 0, 1024, 768);
	glutReshapeWindow(1024, 768);
	// Setup the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(60.0, (GLdouble)GLWindowWidth / (GLdouble)GLWindowHeight, 0.1, 100.0);

	glutPostRedisplay();
}