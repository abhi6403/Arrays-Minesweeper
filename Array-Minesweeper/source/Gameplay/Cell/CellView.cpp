#include "../../header/Gameplay/Cell/CellView.h"
#include"../../header/Global/Config.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include"../../header/Gameplay/Cell/CellModel.h"
#include"../../header/UI/UIElement/ButtonView.h"

namespace Gameplay
{
	namespace Cell
	{
		using namespace UI::UIElement;
		using namespace Global;

		CellView::CellView(CellController* controller)
		{
			cell_controller = controller;
			cell_button = new ButtonView();
		}

		CellView::~CellView()
		{
			delete(cell_button);
		}

		void CellView::initialize(float width, float height)
		{
			initializeButtonImage(width, height);
		}

		void CellView::initializeButtonImage(float width, float height)
		{
			cell_button->initialize("Cell", Config::cells_texture_path, width * slice_count, height, getCellScreenPosition());
		}

		void CellView::update()
		{
			cell_button->update();
		}

		void CellView::render()
		{
			setCellTexture();
			cell_button->render();
		}

		void CellView::reset()
		{

		}

		void CellView::setCellTexture()
		{
			int index = static_cast<int>(cell_controller->getCellValue());

			switch (cell_controller->getCellState())
			{
			case::Gameplay::Cell::CellState::HIDDEN:
				cell_button->setTextureRect(sf::IntRect(10 * tile_size, 0, tile_size, tile_size));
				break;

			case::Gameplay::Cell::CellState::OPEN:
				cell_button->setTextureRect(sf::IntRect(index * tile_size, 0, tile_size, tile_size));
				break;

			case::Gameplay::Cell::CellState::FLAGGED:
				cell_button->setTextureRect(sf::IntRect(11 * tile_size, 0, tile_size, tile_size));
				break;
			}
		}

		sf::Vector2f CellView::getCellScreenPosition()
		{
			float x_screen_position = cell_left_offset;
			float y_screen_position = cell_top_offset;

			return sf::Vector2f(x_screen_position, y_screen_position);
		}
	}
}