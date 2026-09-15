#include <iostream>
#include "GameManager.h"
#include "StartupState.h"

int main() {
	GameManager manager;
	manager.ChangeState(std::make_unique<StartupState>());

	// 各状態の OnUpdate が入力待ちでブロッキングする設計なので
	// ここでは状態が無くなる（ChangeState(nullptr)）まで Update を呼び続ける
	while (manager.HasState()) {
		manager.Update(0.0f);
	}
	return 0;
}