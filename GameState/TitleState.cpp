#include "TitleState.h"
#include "MainMenuState.h"
#include "GameManager.h"
#include <iostream>
#include <string>

void TitleState::OnEnter(GameManager* manager) {
    std::cout << "タイトル画面" << std::endl;
    std::cout << "Enterでメニューに進みます。" << std::endl;
}

void TitleState::OnUpdate(GameManager* manager, float deltaTime) {
    std::string tmp;
    std::cout << "入力してください: ";
    std::getline(std::cin, tmp);
    manager->ChangeState(std::make_unique<MainMenuState>());
}

void TitleState::OnExit(GameManager* manager) {
    std::cout << "Title: 終了" << std::endl;
}

const std::string TitleState::GetName() const {
    return "TitleState";
}
