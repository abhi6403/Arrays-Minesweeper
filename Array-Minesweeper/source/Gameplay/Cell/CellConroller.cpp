#include"../../header/Gameplay/Cell/CellController.h"
#include"../../header/Gameplay/Cell/CellView.h"

namespace Gameplay
{
	namespace Cell
	{
		CellController::CellController()
		{
			cell_view = new CellView(this);
		}

		CellController::~CellController()
		{
			destroy();
		}

		void CellController::initialize()
		{
			cell_view->initialize();
		}

		void CellController::render()
		{
			cell_view->render();
		}

		void CellController::update()
		{
			cell_view->update();
		}

		void CellController::destroy()
		{
			delete(cell_view);
		}

		void CellController::reset()
		{
			cell_view->reset();
		}
	}
}