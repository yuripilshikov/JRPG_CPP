#pragma once
class Generator
{
public:
	static void GenerateRandomMap(char* map, unsigned int width, unsigned int height);
	static unsigned int countNeighbors(int* map, int x, int y, unsigned int width, unsigned int height);
};

