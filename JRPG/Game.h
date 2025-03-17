#pragma once

#include <SDL.h>
#include <memory>

#include "World.h"

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	bool m_isRunning;
	Uint32 m_tickCount;

	std::shared_ptr<World> world;
};

// page 66