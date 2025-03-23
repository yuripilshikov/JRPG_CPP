#pragma once
#include "IState.h"
#include "Entity.h"

#include <vector>

class Game;

class PlayingState :  public IState
{
public:
	PlayingState(Game* game);
	virtual void Update(float deltaTime, char currentAction) override;
	virtual void Render(SDL_Renderer* renderer) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	// specific for playing state
	char map[20 * 20]{ 0 };
	std::vector<Entity> m_entities;
	Entity* m_player;	
};

