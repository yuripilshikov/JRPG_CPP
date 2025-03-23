#pragma once
#include "IState.h"
class MainMenuState : public IState
{
public:
	MainMenuState(Game* game) : IState(game) {}
	virtual void Update(float deltaTime, char currentAction) override;
	virtual void Render(SDL_Renderer* renderer) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};

