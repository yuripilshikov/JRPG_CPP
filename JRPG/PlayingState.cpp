#include "PlayingState.h"
#include "Generator.h"
#include <iostream>



PlayingState::PlayingState(Game* game) : IState(game)
{
	// create game objects (todo move to special factory or something like)
	GameObject gameObject;
	gameObject.add_component(new Transform{ 100, 100, 32 });
	gameObject.add_component(new Velocity{ 0, 0 });
	gameObject.add_component(new Renderable{ SDL_Color{255, 255, 255, 255} });

	m_gameObjects.push_back(gameObject);
			
	m_player = &(m_gameObjects.front());

	Generator::GenerateRandomMap(map, 20, 20);	
}

void PlayingState::Update(float deltaTime, char currentAction)
{
	input_system.input(m_player, m_gameObjects, m_game);
	movement_system.update(m_gameObjects);
}

void PlayingState::Render(SDL_Renderer* renderer)
{
	// todo move to render system
	for (int y = 0; y < 20; ++y)
	{
		for (int x = 0; x < 20; ++x)
		{
			char m = map[y * 20 + x];
			if(m == '.') SDL_SetRenderDrawColor(renderer, 0x1f, 0x1f, 0, 0xff);
			else if(m == '~') SDL_SetRenderDrawColor(renderer, 0x0f, 0x0f, 0, 0xff);
			else if(m == '#') SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
			SDL_Rect temp = { x * 32, y * 32, 32, 32 };
			SDL_RenderFillRect(renderer, &temp);
		}
	}


	SDL_RenderDrawLine(renderer, 10, 10, 100, 100);

	render_system.render(renderer, m_gameObjects);

	/*for (auto e : m_entities)
	{
		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
		SDL_Rect r = { e.getX(), e.getY(), 32, 32 };
		SDL_RenderFillRect(renderer, &r);
	}*/

}

void PlayingState::OnEnter()
{
}

void PlayingState::OnExit()
{
}
