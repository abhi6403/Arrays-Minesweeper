#include "../../header/Gameplay/Board/BoardController.h"
#include"../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include"../../header/Gameplay/Cell/CellModel.h"
#include"../../header/UI/UIElement/ButtonView.h"
#include"../../header/Global/ServiceLocator.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		using namespace UI::UIElement;
		using namespace Global;
		using namespace Sound;

		BoardController::BoardController() : random_engine(random_device())
		{
			board_view = new BoardView(this);
			createBoard();
		}

		BoardController::~BoardController()
		{
			destroy();
		}

		void BoardController::createBoard()
		{
			for (int a = 0; a < number_of_rows_; a++)
			{
				for (int b = 0; b < number_of_colums; b++)
				{
					board[a][b] = new CellController(sf::Vector2i(a, b));
				}
			}
		}

		void BoardController::populateCells()
		{
			for (int a = 0; a < number_of_rows_; a++)
			{
				for (int b = 0; b < number_of_colums; b++)
				{
					CellValue value = static_cast<CellValue>(countMinesAround(sf::Vector2i(2, b)));
					board[a][b]->setCellValue(value);
				}
			}
		}
		void BoardController::initialize()
		{
			board_view->initialize();
			initializeCells();
		}

		void BoardController::update()
		{
			board_view->update();

			for (int row = 0; row < number_of_rows_; ++row)
			{
				for (int col = 0; col < number_of_colums; ++col)
				{
					board[row][col]->update();
				}
			}
		}

		void BoardController::render()
		{
			board_view->render();

			for (int row = 0; row < number_of_rows_; ++row)
			{
				for (int col = 0; col < number_of_colums; ++col)
				{
					board[row][col]->render();
				}
			}
		}
		
		void BoardController::reset()
		{
			flagged_cell = 0;
			resetBoard();
		}

		void BoardController::resetBoard()
		{
			for (int row = 0; row < number_of_rows_; ++row)
			{
				for (int col = 0; col < number_of_colums; ++col)
				{
					board[row][col]->reset();
				}
			}
		}

		void BoardController::deleteBoard()
		{
			for (int a = 0; a < number_of_rows_; a++)
			{
				for (int b = 0; b < number_of_colums; b++)
				{
					delete board[a][b];
				}
			}
		}

		void BoardController::destroy()
		{
			deleteBoard();
			delete(board_view);
		}

		void BoardController::initializeCells()
		{
			float cell_width = board_view->getCellWidth();
			float cell_height = board_view->getCellHeight();

			for (int a = 0; a < number_of_rows_; a++)
			{
				for (int b = 0; b < number_of_colums; b++)
				{
					board[a][b]->initialize(cell_width, cell_height);
				}
			}
		}

		int BoardController::getMinesCount()
		{
			return mines_count - flagged_cell;
		}

		int BoardController::countMinesAround(sf::Vector2i cell_position)
		{
			int mines_around = 0;

			for (int a = -1; a < 2; a++)
			{
				for (int b = -1; b < 2; b++)
				{
					if ((a == 0 && b == 0) || !isValidCellPosition(sf::Vector2i(cell_position.x + a, cell_position.y + b)))continue;

					if (board[a + cell_position.x][b + cell_position.y]->getCellValue() == CellValue::MINE)mines_around++;
				}
			}
			
			return mines_around;
		}

		bool BoardController::isValidCellPosition(sf::Vector2i cell_position)
		{
			return (cell_position.x >= 0 && cell_position.y >= 0 && cell_position.x < number_of_colums && cell_position.y < number_of_rows_);
		}

		void BoardController::openCell(sf::Vector2i cell_position)
		{
			if (board[cell_position.x][cell_position.y]->canOpenCell())
			{
				if (board_state == BoardState::FIRST_CELL)
				{
					populateBoard(cell_position);
					board_state = BoardState::PLAYING;
				}
				processCellValue(cell_position);
				board[cell_position.x][cell_position.y]->openCell();
			}
		}

		void BoardController::openAllCells()
		{
			if (board_state == BoardState::FIRST_CELL)
			{
				populateBoard(sf::Vector2i(0, 0));
			}

			for (int a = 0; a < number_of_rows_; ++a)
			{
				for (int b = 0; b < number_of_colums; ++b)
				{
					board[a][b]->openCell();
				}
			}
		}

		void BoardController::processCellValue(sf::Vector2i cell_position)
		{
			switch (board[cell_position.x][cell_position.y]->getCellValue())
			{
			case::Gameplay::Cell::CellValue::EMPTY:
				break;
			case::Gameplay::Cell::CellValue::MINE:
				break;
			default:
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
				break;
			}
		}
		void BoardController::populateBoard(sf::Vector2i cell_position)
		{
			populateMines(cell_position);
			populateCells();
		}

		void BoardController::populateMines(sf::Vector2i cell_position)
		{
			std::uniform_int_distribution<int>x_distribution(0, number_of_colums - 1);
			std::uniform_int_distribution<int>y_distribution(0, number_of_rows_ - 1);

			for (int a = 0; a < mines_count; a++)
			{
				int i = static_cast<int>(x_distribution(random_engine));
				int j = static_cast<int>(y_distribution(random_engine));

				if (board[i][j]->getCellValue() == CellValue::MINE || (cell_position.x == i && cell_position.y == j))a--;
				else board[i][j]->setCellValue(CellValue::MINE);
			}
			
		}

		void BoardController::processCellInput(CellController* cell_controller, ButtonType button_type)
		{
			switch (button_type)
			{
			case UI::UIElement::LEFT_MOUSE_BUTTON:
				openCell(cell_controller->getCellPosition());
				break;
			case UI::UIElement::RIGHT_MOUSE_BUTTON:
				flagCell(cell_controller->getCellPosition());
				break;
			default:
				break;
			}
		}

		void BoardController::flagCell(sf::Vector2i cell_position)
		{
			switch (board[cell_position.x][cell_position.y]->getCellState())
			{
			case::Gameplay::Cell::CellState::FLAGGED:
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::FLAG);
				flagged_cell--; 
				break;
			case::Gameplay::Cell::CellState::HIDDEN:
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::FLAG);
				flagged_cell++; 
				break;
			}

			board[cell_position.x][cell_position.y]->flagCell();
		}

		BoardState BoardController::getBoardState()
		{
			return board_state;
		}

		void BoardController::setBoardState(BoardState state)
		{
			board_state = state;
		}
	}
}