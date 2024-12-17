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

		void BoardService::processCellInput(CellController* cell_controller, ButtonType button_type)
		{
			board_controller->processCellInput(cell_controller, button_type);
		}

		void BoardService::setBoardState(BoardState state)
		{
			board_controller->setBoardState(state);
		}

		BoardState BoardService::getBoardState()
		{
			return board_controller->getBoardState();
		}

		void BoardService::showBoard()
		{
			board_controller->showBoard();
		}
	}
}