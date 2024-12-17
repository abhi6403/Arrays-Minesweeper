#pragma once
#include"SFML/Graphics.hpp"
#include"../../header/Gameplay/Cell/CellController.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include <random>

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		using namespace UI::UIElement;

		class BoardView;

		enum class BoardState
		{
			FIRST_CELL,
			PLAYING,
			COMPLETED,
		};

		class BoardController
		{
		private:
			BoardView* board_view;
			BoardState board_state;
		
			void createBoard();
			void initializeCells();
			void resetBoard();
			void deleteBoard();
			void destroy();
			void populateCells();
			void openAllCells();
			void openEmptyCells(sf::Vector2i cell_position);
			void processEmptyCell(sf::Vector2i cell_position);
			void processMineCell(sf::Vector2i cell_position);
			void processCellValue(sf::Vector2i cell_position);
			void populateBoard(sf::Vector2i cell_position);
			void populateMines(sf::Vector2i cell_position);
			void flagCell(sf::Vector2i cell_position);
			void openCell(sf::Vector2i cell_position);
			
			
			int countMinesAround(sf::Vector2i cell_position);

			bool isValidCellPosition(sf::Vector2i cell_position);

		public:
			static const int number_of_rows_ = 15;
			static const int number_of_colums = 15;
			static const int mines_count = 10;
			int flagged_cell;

			std::default_random_engine random_engine;
			std::random_device random_device;

			Cell::CellController* board[number_of_rows_][number_of_colums];

			BoardController();
			~BoardController();

			void initialize();
			void update();
			void render();
			void showBoard();
			void reset();
			int getMinesCount();
			
			void setBoardState(BoardState state);
			BoardState getBoardState();
			
			void processCellInput(CellController* cell_controller, ButtonType button_type);

		};
	}
}