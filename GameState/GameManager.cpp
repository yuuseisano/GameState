#include "GameManager.h"
#include "GameState.h"

GameManager::GameManager() : isRunning(true), gameTime(0.0f)
{
}

void GameManager::ChangeState(std::unique_ptr<GameState> newState) {
	if (currentState) {
		currentState->OnExit(this);
	}
	currentState = std::move(newState);
	if (currentState) {
		currentState->OnEnter(this);
	}
}
void GameManager::Update(float deltaTime) {
	gameTime += deltaTime;
	if (currentState) {
		currentState->OnUpdate(this, deltaTime);
	}
}

bool GameManager::HasState() const {
	return static_cast<bool>(currentState);
}