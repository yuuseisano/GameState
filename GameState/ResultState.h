#pragma once

#include "GameState.h"
#include <string>

class GameManager;

class ResultState : public GameState
{
public:
    void OnEnter(GameManager* manager) override;
    void OnUpdate(GameManager* manager, float deltaTime) override;
    void OnExit(GameManager* manager) override;
    const std::string GetName() const override;
};

