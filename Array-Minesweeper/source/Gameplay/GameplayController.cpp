#include"../../header/Gameplay/GameplayController.h"
#include"../../header/Global/ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;

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

}