#pragma once

// Later, it will be implemented as SQLite database (and game will get data 
// from it as if it needed. Now, it will "live" in memory.

const unsigned int mapWidth = 10;
const unsigned int mapHeight = 10;

struct World
{
	int map[mapHeight][mapWidth];
	int playerX, playerY;

	World() : playerX(2), playerY(2)
	{
		int* iter = map[0];
		for (unsigned int i = 0; i < mapHeight * mapWidth; ++i)
		{
			*iter = 1;
			++iter;
		}
	}
};

