#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glut32.lib")
#define IBM
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <thread>
#include <iostream>
#include <ctime>
#include "Callbacks.h"
#include "Obstacle.h"
#include "World.h"
#include "SOIL2/include/SOIL2.h"
#include "Character.h"
#include "GLFunctions.h"
#include "glew_include/GL/glew.h"
#include "glut-3.7.6-bin/glut.h"


World mainWorld;

GLuint enemyT;
GLuint tempTexture;
GLuint background;
GLuint dirt;


int movementSpeed = 1;
bool inDebugMode = 1;
Character mainCharacter;
int GLWindowWidth = 1366;
int GLWindowHeight = 768;
int GLWindowHandle = 0;
int GLErrorCode = 0;

void resetGame() {
	//mainCharacter.jump();
	
	mainCharacter.isMainChar = 1;
	shouldDisplayRedCharacter = 1;
	mainCharacter.reset();
	mainWorld.worldCam.reset();
	
}

void loadTextures() {
	enemyT = loadTexture("enemy.png");
	dirt = loadTexture("dirt.png");
	mainCharacter.texture = loadTexture("character.png");
	background = loadTexture("background.jpg");
	tempTexture = loadTexture("grass.png");
	std::cout << SOIL_last_result();
}


void InitGL(int argc, char* argv[])
{
	//std::cout << "Initialise OpenGL..." << std::endl;

	glutInit(&argc, argv);
	int iScreenWidth = glutGet(GLUT_SCREEN_WIDTH);
	int iScreenHeight = glutGet(GLUT_SCREEN_HEIGHT);

	glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowPosition((iScreenWidth - GLWindowWidth) / 2,
		(iScreenHeight - GLWindowHeight) / 2);
	glutInitWindowSize(GLWindowWidth, GLWindowHeight);

	GLWindowHandle = glutCreateWindow("Left to Right");


	// Register GLUT callbacks
	glutDisplayFunc(renderSceneGL);
	glutIdleFunc(idlingGL);
	glutReshapeFunc(resizeGL);
	glutMouseFunc(mouseGL);
	glutMotionFunc(motionGL);
	glutKeyboardFunc(keyboardFuncGL);
	glutKeyboardUpFunc(keyboardUpFuncGL);
	//glutIgnoreKeyRepeat(keybL);

	// Setup initial GL State
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClearDepth(1.0f);
	glShadeModel(GL_SMOOTH);
	//std::cout << "Initialise OpenGL: Success!" << std::endl;
}

int main(int argc, char* argv[]) {
	InitGL(argc, argv);
	loadTextures();
	resetGame();
	srand(time(nullptr));
	timet = glutGet(GLUT_ELAPSED_TIME);
	mainWorld.generateRandomWorld();
	//glutSetCursor(GLUT_CURSOR_TOP_LEFT_CORNER);
	
	glutMainLoop();
	
	

	return 1;
}

