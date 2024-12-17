#include"../../header/Gameplay/Cell/CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		CellModel::CellModel(sf::Vector2i position)
		{
			reset();
			this->position = position;
		}

		CellModel::~CellModel() = default;

		CellState CellModel::getCellState()
		{
			return cell_state;
		}

		void CellModel::setCellState(CellState state)
		{
			cell_state = state;
		}

		CellValue CellModel::getCellValue()
		{
			return cell_value;
		}

		void CellModel::setCellValue(CellValue value)
		{
			cell_value = value;
		}

		void CellModel::reset()
		{
			cell_state = CellState::HIDDEN;
			cell_value = CellValue::EMPTY;
			mines_around = 0;
		}

		sf::Vector2i CellModel::getCellPosition()
		{
			return position;
		}

		void CellModel::setCellPosition(sf::Vector2i position)
		{
			this->position = position;
		}

		int CellModel::getMinesAround()
		{
			return mines_around;
		}

		void CellModel::setMinesAround(int mine_count)
		{
			mines_around = mine_count;
		}
	}
}