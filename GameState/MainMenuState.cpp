#include "MainMenuState.h"
#include "InGameState.h"
#include "TitleState.h"
#include "GameManager.h"
#include <iostream>
#include <string>

void MainMenuState::OnEnter(GameManager* manager) {
	std::cout << "MainMenu: メニュー画面" << std::endl;
	std::cout << "選択: 1 - ゲーム開始, その他 - タイトルに戻る" << std::endl;
}

void MainMenuState::OnUpdate(GameManager* manager, float deltaTime) {
	std::string input;
	std::cout << "入力してください: ";
	std::getline(std::cin, input);

	if (input == "1") {
		manager->ChangeState(std::make_unique<InGameState>());
	}
	else {
		manager->ChangeState(std::make_unique<TitleState>());
	}
}

void MainMenuState::OnExit(GameManager* manager) {
	std::cout << "MainMenu: 終了" << std::endl;
}

const std::string MainMenuState::GetName() const {
	return "MainMenuState";
}
