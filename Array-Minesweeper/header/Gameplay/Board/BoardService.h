#pragma once
#include "../../header/Gameplay/Board/BoardController.h"
#include"../../header/Gameplay/Cell/CellController.h"
#include"../../header/UI/UIElement/ButtonView.h"`

namespace Gameplay
{
	using namespace Cell;
	using namespace UI::UIElement;

	namespace Board
	{
		class BoardService
		{
		private:
			BoardController* board_controller;

			void destroy();

		public:
			BoardService();
			~BoardService();

			void initialize();
			void update();
			void render();

			void resetBoard();
			void showBoard();
			void flagAllMines();
			void processCellInput(CellController* cell_controller, ButtonType button_type);

			int getMinesCount();

			void setBoardState(BoardState state);
			BoardState getBoardState();
		};
	}
}