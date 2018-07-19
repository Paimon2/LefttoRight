#pragma once
#include "Camera.h"
#include <vector>


class World {
public:
	Camera worldCam;
	World();
	~World();
	void generateRandomWorld();
};

