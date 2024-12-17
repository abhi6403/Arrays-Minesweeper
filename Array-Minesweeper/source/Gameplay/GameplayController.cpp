#include"../../header/Gameplay/GameplayController.h"
#include"../../header/Global/ServiceLocator.h"
#include"../../header/Main/GameService.h"
#include"../../header/Gameplay/Board/BoardService.h"
#include"../../header/Time/TimeService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Main;
	using namespace Board;
	using namespace Cell;
	using namespace UI::UIElement;
	using namespace Time;

	GameplayController::GameplayController()
	{
		
	}

	GameplayController::~GameplayController()
	{

	}

	void GameplayController::initialize()
	{

	}

	void GameplayController::update()
	{
		updateRemainingTime();
		if (isTimeOut())
		{
			endGame(GameResult::LOST);
		}
	}

	bool GameplayController::isTimeOut()
	{
		return (remaining_time <= 1);
	}

	void GameplayController::render()
	{

	}

	void GameplayController::updateRemainingTime()
	{
		if (game_result == GameResult::WON)
			return;

		remaining_time -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void GameplayController::reset()
	{
		game_result = GameResult::NONE;
		remaining_time = max_duration;
		ServiceLocator::getInstance()->getBoardService()->resetBoard();
	}

	int GameplayController::getMinesCount()
	{
		return ServiceLocator::getInstance()->getBoardService()->getMinesCount();
	}

	float GameplayController::getRemainingTime()
	{
		return remaining_time;
	}

	void GameplayController::endGame(GameResult result)
	{
		switch (result)
		{
		case Gameplay::GameResult::WON:
			gameWon();
			break;
		case Gameplay::GameResult::LOST:
			gameLost();
			break;
		default:
			break;
		}
	}

	void GameplayController::beginGameOverTimer()
	{
		remaining_time = game_over_time;
	}

	void GameplayController::gameLost()
	{
		if (game_result == GameResult::NONE)
		{
			game_result = GameResult::LOST;
			beginGameOverTimer();
			ServiceLocator::getInstance()->getBoardService()->showBoard();
			ServiceLocator::getInstance()->getBoardService()->setBoardState(Board::BoardState::COMPLETED);
		}
		else
		{
			showCredits();
		}
	}

	void GameplayController::gameWon()
	{
		game_result = GameResult::WON;
		ServiceLocator::getInstance()->getBoardService()->flagAllMines();
		ServiceLocator::getInstance()->getBoardService()->setBoardState(Board::BoardState::COMPLETED);
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::GAME_WON);
	}

	void GameplayController::showCredits()
	{
		GameService::setGameState(GameState::CREDITS);
	}
}