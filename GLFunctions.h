#pragma once
#include "glew_include/GL/glew.h"
extern void drawTexture(GLuint file,
	float x,
	float y,
	float w,
	float h,
	float angle,
	float *color);
extern GLuint loadTexture(const char * filename);
extern void renderText(int x, int y, void * font, const char * text);
extern void PMGL();
