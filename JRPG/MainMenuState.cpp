#include "MainMenuState.h"
#include <iostream>

void MainMenuState::Update(float deltaTime, char currentAction)
{
	if (currentAction)
	{
		std::cout << currentAction << std::endl;
	}


}

void MainMenuState::Render(SDL_Renderer* renderer)
{
	SDL_RenderDrawLine(renderer, 10, 10, 100, 100);
}

void MainMenuState::OnEnter()
{

}

void MainMenuState::OnExit()
{

}
