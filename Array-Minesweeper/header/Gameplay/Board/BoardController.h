#pragma once
#include"SFML/Graphics.hpp"
#include"../../header/Gameplay/Cell/CellController.h"
#include "../../header/UI/UIElement/ButtonView.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		using namespace UI::UIElement;

		class BoardView;

		class BoardController
		{
		private:
			BoardView* board_view;
		
			void createBoard();
			void initializeCells();
			void resetBoard();
			void deleteBoard();
			void destroy();
			

		public:
			static const int number_of_rows_ = 9;
			static const int number_of_colums = 9;
			static const int mines_count = 8;
			int flagged_cell;

			Cell::CellController* board[number_of_rows_][number_of_colums];

			BoardController();
			~BoardController();

			void initialize();
			void update();
			void render();
			void reset();
			void flagCell(sf::Vector2i cell_position);
			int getMinesCount();
			void openCell(sf::Vector2i cell_position);
			void processCellInput(CellController* cell_controller, ButtonType button_type);

		};
	}
}