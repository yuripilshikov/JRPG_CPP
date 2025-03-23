#include "PlayingState.h"
#include "Generator.h"
#include <iostream>

PlayingState::PlayingState(Game* game) : IState(game)
{
	m_entities.push_back(Entity(10, 10, 'x'));
	m_player = &(m_entities.front());
	Generator::GenerateRandomMap(map, 20, 20);
}

void PlayingState::Update(float deltaTime, char currentAction)
{
	if (currentAction != 0)
	{
		switch (currentAction)
		{
		case 'W':
			m_player->Move(0, -1);
			break;
		case 'S':
			m_player->Move(0, 1);
			break;
		case 'A':
			m_player->Move(-1, 0);
			break;
		case 'D':
			m_player->Move(1, 0);
			break;
		}
	}
}

void PlayingState::Render(SDL_Renderer* renderer)
{
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

	for (auto e : m_entities)
	{
		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
		SDL_Rect r = { e.getX() * 32, e.getY() * 32, 32, 32 };
		SDL_RenderFillRect(renderer, &r);
	}

}

void PlayingState::OnEnter()
{
}

void PlayingState::OnExit()
{
}
