#include "Generator.h"
#include <stdlib.h>


void Generator::GenerateRandomMap(char* map, unsigned int width, unsigned int height)
{
	unsigned int size = width * height;
	int* temp = new int[size];
	int* temp1 = new int[size];

	for (unsigned int i = 0; i < size; ++i)
	{
		temp[i] = rand() % 2;
	}

	for (unsigned int i = 0; i < 3; ++i)
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			for (unsigned int x = 0; x < width; ++x)
			{
				countNeighbors(temp, x, y, width, height) > 3 ? temp1[y * width + x] = 1 : temp1[y * width + x] = 0;
			}
		}

		for (unsigned int i = 0; i < size; ++i)
		{
			temp[i] = temp1[i];
		}
	}

	for (int i = 0; i < size; ++i)
	{
		map[i] = (temp[i] == 1 ? '.' : '~');
	}

	// add borders
	for (int yy = 0; yy < height; ++yy)
	{
		for (int xx = 0; xx < width; ++xx)
		{
			if (xx == 0 || xx == width - 1 || yy == 0 || yy == height - 1) map[yy * width + xx] = '#';
		}
	}

	delete[] temp;
	delete[] temp1;
}

unsigned int Generator::countNeighbors(int* map, int x, int y, unsigned int width, unsigned int height)
{
	unsigned int count = 0;
	for (int yy = y - 1; yy <= y + 1; ++yy)
	{
		for (int xx = x - 1; xx <= x + 1; ++xx)
		{
			if (xx == yy) continue;
			if (xx < 0 || yy < 0 || xx >= width || yy >= height) continue;
			if (map[yy * width + xx] == 1) ++count;
		}
	}
	return count;

}
