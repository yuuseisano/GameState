#include "StartupState.h"
#include "TitleState.h"
#include "GameManager.h"
#include <iostream>
#include <thread>
#include <chrono>

void StartupState::OnEnter(GameManager* manager) {
	std::cout << "Startup: 初期化処理を実行します..." << std::endl;
	// 簡易な初期化待機（実プロジェクトでは実際の初期化処理を行う）
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	// 初期化が終わったらタイトル画面へ遷移
	manager->ChangeState(std::make_unique<TitleState>());
}

void StartupState::OnUpdate(GameManager* manager, float deltaTime) {
	// この状態では OnEnter で遷移するので何もしない
}

void StartupState::OnExit(GameManager* manager) {
	std::cout << "Startup: 初期化完了、Titleへ移動します" << std::endl;
}

const std::string StartupState::GetName() const {
	return "StartupState";
}
