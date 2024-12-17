#include"../../header/Gameplay/GameplayController.h"
#include"../../header/Global/ServiceLocator.h"
#include"../../header/Main/GameService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Main;

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

	void GameplayController::reset()
	{
		remaining_time = max_duration;
		ServiceLocator::getInstance()->getBoardService()->resetBoard();
	}

	void GameplayController::updateRemainingTime()
	{
		remaining_time -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	float GameplayController::getRemainingTime()
	{
		return remaining_time;
	}

	void GameplayController::beginGameOverTimer()
	{
		remaining_time = game_over_time;
	}

	int GameplayController::getMinesCount()
	{
		return ServiceLocator::getInstance()->getBoardService()->getMinesCount();
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

	}

	void GameplayController::showCredits()
	{
		GameService::setGameState(GameState::CREDITS);
	}
}