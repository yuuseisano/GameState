#include "InGameState.h"
#include "ResultState.h"
#include "GameManager.h"
#include <iostream>
#include <string>
#include <random>

void InGameState::OnEnter(GameManager* manager) {
	std::cout << "InGame: ゲーム開始。Enterを押すたびに1～10を抽選します。" << std::endl;
	std::cout << "1が出たらResultへ移動します。" << std::endl;
}

void InGameState::OnUpdate(GameManager* manager, float deltaTime) {
	std::string input;
	std::cout << "Enterで抽選 (任意の文字を入力してEnterでも抽選されます)。結果を見るにはEnterのみでOK: ";
	std::getline(std::cin, input); // Enter待ち。空行でも抽選扱いにする

	// 乱数生成
	static std::random_device rd;
	static std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 10);
	int roll = dist(mt);

	std::cout << "抽選結果: " << roll << std::endl;
	if (roll == 1) {
		manager->ChangeState(std::make_unique<ResultState>());
	}
	// それ以外は InGame のまま（次の Update で再度待機）
}

void InGameState::OnExit(GameManager* manager) {
	std::cout << "InGame: 終了" << std::endl;
}

const std::string InGameState::GetName() const {
	return "InGameState";
}
