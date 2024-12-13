#pragma once
#include "../../header/Gameplay/Board/BoardView.h"
namespace Gameplay
{
	namespace Board
	{
		class BoardController
		{
		private:
			BoardView* board_view;
		
			void createBoard();
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