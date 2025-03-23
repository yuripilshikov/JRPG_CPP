#pragma once

#include <map>
#include <string>
#include <memory>
#include <stack>
#include <SDL.h>

#include "IState.h"

class Game;

class StateMachine
{
public:
	StateMachine(Game* game);
	void Update(float elapsedTime, char currentAction);
	void Render(SDL_Renderer* renderer);
	void Change(std::string stateName);
	void Add(std::string name, std::shared_ptr<IState> state);
	void Push(std::string name);
	void Pop();
private:
	std::map<std::string, std::shared_ptr<IState>> m_states;
	std::stack<std::shared_ptr<IState>> m_stateStack;
	std::shared_ptr<IState> m_currentState;
	Game* m_game;
};

