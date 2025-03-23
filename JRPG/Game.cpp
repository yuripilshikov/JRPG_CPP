#include "Game.h"
#include <algorithm>
#include "MainMenuState.h"
#include "PlayingState.h"

Game::Game() : m_window(nullptr), m_renderer(nullptr), m_SM(this), m_isRunning(false), m_tickCount(0), currentAction(0)
{
	
}

bool Game::Initialize()
{
	// Init SDL
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	m_window = SDL_CreateWindow("JRPG Game", 100, 100, 1024, 768, 0);
	if (!m_window)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// Init StateMachine
	m_SM.Add("MainMenu", std::make_shared<MainMenuState>(this));	
	m_SM.Add("Playing", std::make_shared<PlayingState>(this));
	m_SM.Push("MainMenu");
	m_isRunning = true;
	return true;
}

void Game::RunLoop()
{
	while (m_isRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
		currentAction = 0;
	}
}

void Game::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Game::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_isRunning = false;
			break;

			// для "одиночных" нажатий
		//case SDL_KEYDOWN:
		//	switch (event.key.keysym.sym)
		//	{
		//	case SDLK_1: 
		//		currentAction = '1';
		//		break;
		//	}
		}
	}

	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_ESCAPE])
	{
		m_isRunning = false;
	}
	else if (state[SDL_SCANCODE_1]) // для "непрерывных" нажатий
	{
		currentAction = '1';
		m_SM.Change("Playing");
	}

	
}

void Game::UpdateGame()
{
	// wait for 16 ms
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), m_tickCount + 16));
	float deltaTime = (SDL_GetTicks() - m_tickCount) / 1000.0f;

	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}

	m_SM.Update(deltaTime, currentAction);

}

void Game::GenerateOutput()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 255, 255);

	SDL_RenderClear(m_renderer);

	// generate output
	SDL_SetRenderDrawColor(m_renderer, 200, 200, 200, 255);
	
	m_SM.Render(m_renderer);
	
	SDL_RenderPresent(m_renderer);
}