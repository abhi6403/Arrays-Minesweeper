#include"../../header/Gameplay/Board/BoardService.h"
namespace Gameplay
{
	namespace Board
	{
		BoardService::BoardService()
		{
			board_controller = nullptr;
		}

		BoardService::~BoardService()
		{
			destroy();
		}

		void BoardService::initialize()
		{
			board_controller = new BoardController();
			board_controller->initialize();
		}

		void BoardService::update()
		{
			board_controller->update();
		}

		void BoardService::render()
		{
			board_controller->render();
		}

		void BoardService::destroy()
		{
			delete(board_controller);
		}

		void BoardService::resetBoard()
		{
			board_controller->reset();
		}

		int BoardService::getMinesCount()
		{
			return board_controller->getMinesCount();
		}
	}
}