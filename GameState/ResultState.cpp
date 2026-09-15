#include "ResultState.h"
#include "MainMenuState.h"
#include "GameManager.h"
#include <iostream>
#include <string>


void ResultState::OnEnter(GameManager* manager) {
	std::cout << "Result: 結果画面" << std::endl;
	std::cout << "Any Keyでメニューに戻ります。" << std::endl;
}

void ResultState::OnUpdate(GameManager* manager, float deltaTime) {
	std::string tmp;
	std::cout << "入力してください: ";
	std::getline(std::cin, tmp);
	manager->ChangeState(std::make_unique<MainMenuState>());
}

void ResultState::OnExit(GameManager* manager) {
	std::cout << "Result: 終了" << std::endl;
}

const std::string ResultState::GetName() const {
	return "ResultState";
}
