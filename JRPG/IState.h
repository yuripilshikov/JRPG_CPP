#pragma once
#include <SDL.h>

class Game;

class IState
{
public:
	IState(Game* game);
	virtual void Update(float deltaTime, char currentAction) {};
	virtual void Render(SDL_Renderer* renderer) {};
	virtual void OnEnter() {};
	virtual void OnExit() {};
protected:
	Game* m_game;
};

