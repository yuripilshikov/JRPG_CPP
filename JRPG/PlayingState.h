#pragma once
#include "IState.h"

class Game;

class PlayingState :  public IState
{
public:
	PlayingState(Game* game) : IState(game) {}
	virtual void Update(float deltaTime, char currentAction) override;
	virtual void Render(SDL_Renderer* renderer) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};

