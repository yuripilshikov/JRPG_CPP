#pragma once

#include <SDL.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

#include "StateMachine.h"


class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void terminate() { m_isRunning = false; }

private:
	//void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	StateMachine m_SM;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	bool m_isRunning;
	Uint32 m_tickCount;

	char currentAction;
};