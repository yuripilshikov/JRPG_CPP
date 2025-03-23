#include "StateMachine.h"

#include <iostream>


StateMachine::StateMachine(Game* game) : m_game(game)
{
}

void StateMachine::Update(float elapsedTime, char currentAction)
{
	if (!m_stateStack.empty())
	{
		m_stateStack.top()->Update(elapsedTime, currentAction);
	}
	else
	{
		std::cerr << "Update:: No states in stack\n";
	}
}

void StateMachine::Render(SDL_Renderer* renderer)
{
	if (!m_stateStack.empty())
	{
		m_stateStack.top()->Render(renderer);
	}
	else
	{
		std::cerr << "Render:: No states in stack\n";
	}
}

void StateMachine::Change(std::string stateName)
{
	if(m_currentState)
		m_currentState->OnExit();
	m_currentState = m_states.at(stateName);

	while (!m_stateStack.empty()){m_stateStack.pop(); }

	m_currentState->OnEnter();
	m_stateStack.push(m_currentState);
}

void StateMachine::Add(std::string name, std::shared_ptr<IState> state)
{
	m_states.insert(std::pair<std::string, std::shared_ptr<IState>>(name, state));
}

void StateMachine::Push(std::string name)
{
	m_stateStack.push(m_states.at(name));
}

void StateMachine::Pop()
{
	m_stateStack.pop();
}
