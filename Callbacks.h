#pragma once
extern int timet;
extern bool shouldDisplayRedCharacter;
extern void InitGL(int argc, char* argv[]);
extern void renderSceneGL();
extern void idlingGL();
extern void keyRepeatGL(unsigned char c, int x, int y);
extern void keyboardFuncGL(unsigned char c, int x, int y);
extern void keyboardUpFuncGL(unsigned char c, int x, int y);
extern void mouseGL(int button, int state, int x, int y);
extern void motionGL(int x, int y);
extern void resizeGL(int w, int h);