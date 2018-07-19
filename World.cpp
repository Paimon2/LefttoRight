#include "World.h"
#include "Obstacle.h"
#include "Main.h"

World::World()
{
	Camera tempCam;
	worldCam = tempCam;
}

World::~World()
{
	
}



void World::generateRandomWorld()
{
	/*for (int i = 1; i < 16; i++) {
		int j = 140;
		j -= 40;
		Obstacle o;
		o.texture = tempTexture;
		o.setX(i * 40);
		o.setY(i * 40);
		o.setH(20);
		o.setW(20);
		obstacles.push_back(o);
	}*/

	for (int i = 0; i < 1000; i++) {
		// Generate dirt
		Obstacle dirtTile;
		dirtTile.texture = dirt;
		dirtTile.setX(i * 20);
		dirtTile.setY(768);
		dirtTile.setH(400);
		dirtTile.setW(20);
		obstacles.push_back(dirtTile);

		// Generate grass
		Obstacle grassTile;
		grassTile.texture = tempTexture;
		grassTile.setX(i * 20);
		grassTile.setY(730);
		grassTile.setH(20);
		grassTile.setW(20);
		obstacles.push_back(grassTile);
	}
}
