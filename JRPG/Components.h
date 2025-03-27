#pragma once
#include <SDL.h>

// collider is the same as transform (to make things easy)
struct Transform
{
	float x, y;
	float size;
};

struct Velocity
{
	float vx, vy;
};

struct Renderable
{
	SDL_Color color;
};
