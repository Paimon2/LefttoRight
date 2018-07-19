#pragma once
#include "glew_include/GL/glew.h"
#include "Obstacle.h"
#include "Character.h"
#include "Main.h"


inline bool yesOrNo(float probabilityOfYes) {
	return rand() % 100 < (probabilityOfYes * 100);
}

static float white[] = { 1, 1, 1 };
static float red[] = { 0, 1, 0 };

inline bool valueInRange(int value, int min, int max)
{
	return (value >= min) && (value <= max);
}


inline int	CoordGUIInRect(float mouse_x, float mouse_y, float x, float y, float w, float h)
{
	return ((mouse_x >= x && mouse_x < (x + w)) && mouse_y >= y && mouse_y < (y + h));
}

inline int	CoordGUIInRectFlippedAll(float mouse_x, float mouse_y, float x, float y, float w, float h)
{
	return ((mouse_x <= x && mouse_x >(x - w)) && mouse_y <= y && mouse_y >(y - h));
}

inline int	CoordGUIInRectFlippedX(float mouse_x, float mouse_y, float x, float y, float w, float h)
{
	return ((mouse_x <= x && mouse_x > (x - w)) && mouse_y >= y && mouse_y < (y + h));
}

inline int	CoordGUIInRectFlippedY(float mouse_x, float mouse_y, float x, float y, float w, float h)
{
	return ((mouse_x >= x && mouse_x < (x + w)) && mouse_y <= y && mouse_y >(y - h));
}

inline int checkCollide1(int rect1_x, int rect1_y, int rect2_x, int rect2_y, int rect1_w, int rect1_h, int rect2_w, int rect2_h)
{


	return (
		CoordGUIInRect(rect1_x, rect1_y, rect2_x, rect2_y, rect2_w, rect2_h) ||
		CoordGUIInRectFlippedAll(rect1_x + rect1_w, rect1_y + rect1_h, rect2_x + rect2_w, rect2_y + rect2_h, rect2_w, rect2_h) ||
		CoordGUIInRectFlippedX(rect1_x + rect1_w, rect1_y + rect1_h, rect2_x + rect2_w, rect2_y + rect2_h, rect2_w, rect1_h) ||
		CoordGUIInRectFlippedY(rect1_x + rect1_w, rect1_y + rect1_h, rect2_x + rect2_w, rect2_y + rect2_h, rect1_w, rect2_h));
}


struct Rect {
	int x;
	int y;
	int width;
	int height;
};



static Rect obstacleToRect(Obstacle toRect) {
	Rect tempRect;
	tempRect.x = mainWorld.worldCam.x + toRect.getX();
	tempRect.y = mainWorld.worldCam.y + toRect.getY();
	tempRect.width = toRect.getW();
	tempRect.height = toRect.getH();
	return tempRect;
}

static Rect characterToRect(Character toRect) {
	Rect tempRect;
	tempRect.x = toRect.x;
	tempRect.y = toRect.y;
	tempRect.width = toRect.width;
	tempRect.height = toRect.height;
	return tempRect;
}

static bool CheckCollisionRects(Rect one, Rect two)
{
	/*bool xOverlap = valueInRange(one.x, two.x, two.x - two.width) ||
		valueInRange(two.x, one.x, one.x - one.width);

	bool yOverlap = valueInRange(one.y, two.y, two.y - two.height) ||
		valueInRange(two.y, one.y, one.y - one.height);

	return (xOverlap && yOverlap);*/
	return (CoordGUIInRect(one.x, one.y, two.x, two.y, 40, 40) ||
		CoordGUIInRectFlippedAll(one.x, one.y, two.x, two.y, 40, 40) ||
		CoordGUIInRectFlippedX(one.x, one.y, two.x, two.y, 40, 40) ||
		CoordGUIInRectFlippedY(one.x, one.y, two.x, two.y, 40, 40));
}
