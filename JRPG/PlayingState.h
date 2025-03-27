#pragma once
#include "IState.h"

#include "GameObject.h"
#include "Components.h"
#include "Systems.h"

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
	//std::vector<Entity> m_entities;
	//Entity* m_player;	

	MovementSystem movement_system;
	RenderSystem render_system;
	InputSystem input_system;

	std::vector<GameObject> m_gameObjects;
	GameObject* m_player;
};

