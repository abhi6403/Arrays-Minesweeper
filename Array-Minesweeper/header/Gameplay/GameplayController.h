#pragma once
namespace Gameplay
{
	class GameplayController
	{
	private:

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void reset();
	};
}