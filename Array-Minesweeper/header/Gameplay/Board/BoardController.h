#pragma once
#include"SFML/Graphics.hpp"
#include"../../header/Gameplay/Cell/CellController.h"

namespace Gameplay
{
	namespace Board
	{
		class BoardView;

		class BoardController
		{
		private:
			BoardView* board_view;
			Cell::CellController* cell;
		
			void createBoard();
			void initializeCells();
			void resetBoard();
			void deleteBoard();
			void destroy();
			

		public:
			static const int number_of_rows_ = 9;
			static const int number_of_colums = 9;
			static const int mines_count = 8;

			BoardController();
			~BoardController();

			void initialize();
			void update();
			void render();
			void reset();

		};
	}
}