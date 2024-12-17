#pragma once

namespace Gameplay
{
	enum class GameResult
	{
		NONE,
		WON,
		LOST,
	};
	class GameplayController
	{
	private:
		float max_duration = 60.f;
		float remaining_time;
		const float game_over_time = 11.f;

		bool isTimeOut();

		GameResult game_result = GameResult::NONE;
	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void reset();
		void endGame(GameResult result);
		void gameLost();
		void gameWon();
		void showCredits();

		void updateRemainingTime();
		float getRemainingTime();
		void beginGameOverTimer();

		int getMinesCount();
	};
}