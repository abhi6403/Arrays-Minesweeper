#pragma once
#include "../../header/Gameplay/GameplayController.h"

namespace Gameplay
{
	class GameplayService
	{
	private:
		GameplayController* gameplay_controller;

	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();

		void startGame();
		float getRemainingTime();

		int getMinesCount();
	};
}