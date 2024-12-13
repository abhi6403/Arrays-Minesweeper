#pragma once

namespace Gameplay
{
	namespace Cell
	{
		class CellModel
		{
		private:

		public:
			CellModel();
			~CellModel();

			void initialize();
			void update();
			void render();
		};
	}
}