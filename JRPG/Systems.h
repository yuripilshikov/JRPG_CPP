#pragma once

#include <vector>
#include "GameObject.h"
#include "Components.h"
#include "Game.h"

#include <iostream>


class MovementSystem
{
public:
	void update(std::vector<GameObject>& gameObjects)
	{
		for (auto& gameObject : gameObjects)
		{
			Transform* transform = gameObject.get_component<Transform>();
			Velocity* velocity = gameObject.get_component<Velocity>();

			if (transform && velocity)
			{
				transform->x += velocity->vx;
				transform->y += velocity->vy;
			}
		}
	}
};

class RenderSystem
{
public:
	void render(SDL_Renderer* renderer, std::vector<GameObject>& gameObjects)
	{
		for (auto& gameObject : gameObjects)
		{
			Transform* transform = gameObject.get_component<Transform>();
			Renderable* renderable = gameObject.get_component<Renderable>();
			if (transform && renderable)
			{
				SDL_SetRenderDrawColor(renderer, 0, renderable->color.g, 0, 255);

				SDL_Rect rect = { static_cast<int>(transform->x), static_cast<int>(transform->y), transform->size, transform->size };

				SDL_RenderFillRect(renderer, &rect);
				
			}
		}
	}
};

class InputSystem
{
public:
	void input(GameObject* player, std::vector<GameObject>& gameObjects, Game* game)
	{
		SDL_Event ev;
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT) {
				game->terminate();
			}

			if (ev.type == SDL_MOUSEBUTTONDOWN)
			{
				// todo
			}
		}
		const Uint8* state = SDL_GetKeyboardState(NULL);
		if (state[SDL_SCANCODE_ESCAPE])
		{
			game->terminate();
		}
		else if (state[SDL_SCANCODE_W])
		{
			player->get_component<Velocity>()->vy = -1;
		}
		else if (state[SDL_SCANCODE_S])
		{
			player->get_component<Velocity>()->vy = 1;
		}
		else if (state[SDL_SCANCODE_A])
		{
			player->get_component<Velocity>()->vx = -1;
		}
		else if (state[SDL_SCANCODE_D])
		{
			player->get_component<Velocity>()->vx = 1;
		}
	}
};