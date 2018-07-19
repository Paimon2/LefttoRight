#include "glew_include/GL/glew.h"
#include "glut-3.7.6-bin/glut.h"
#include <cmath>
#include "SOIL2/include/SOIL2.h"
#include "GLFunctions.h"
#include <string>







void PMGL(){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0, 1024, 768, 0, 0, 1);
glMatrixMode(GL_MODELVIEW);
}
void drawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}



void drawTexture(GLuint file, float x, float y, float w, float h, float angle, float * color)
{
	
		PMGL();
		

		glColor3f(1, 1, 1);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, file);
		glTranslatef(x, y, 0.0f); //Translate back to the original location.
		glRotatef(angle, 0.0f, 0.0f, 1.0f);                  //Rotate.
		glTranslatef(-x, -y, 0.0f);   //Translate to the origin
		if (color != NULL)
			glColor4f(color[1], color[2], color[3], 0.5);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDepthFunc(GL_LEQUAL);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		// Draw a textured quad
		glBegin(GL_QUADS);
		glTexCoord2i(0, 0); glVertex2i(x, y);
		glTexCoord2i(0, 1); glVertex2i(x, y + h);
		glTexCoord2i(1, 1); glVertex2i(x + w, y + h);
		glTexCoord2i(1, 0); glVertex2i(x + w, y);
		glEnd();


		glDisable(GL_TEXTURE_2D);
		glPopMatrix();


		//glMatrixMode(GL_PROJECTION);
		//glPopMatrix();
	
}

GLuint loadTexture(const char * filename) {
	GLuint tex_2d = SOIL_load_OGL_texture
	(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	return tex_2d;
}

void renderText(int x, int y, void * font, const char * text)
{
	glRasterPos2i(x, y);

	for (int i = 0; i < strlen(text); i++)
	{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
	}
	
}



