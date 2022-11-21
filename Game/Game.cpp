#include "Game.hpp"

int Being::id_count = 0;
GraphicManager* Being::pGraMan = NULL;
GraphicManager* GraphicManager::instance = NULL;

Game::Game() :
// criar elementos do jogo
// window(800, 960), (old window size)
window(800, 1200),
// window poderia ser criada no graphic manager
level1(&window),
level2(&window),
menu()
{
	grapMan = GraphicManager::getInstance();
	grapMan->setWindow(&window);
	Being::pGraMan = grapMan;
}

Game::~Game()
{
	delete grapMan->getInstance();
}

void Game::execute()
{
	std::cout << "Executando menu" << std::endl;
	//int result;
	//while (grapMan->getWindow()->config.isOpen())
	//{
		int result = menu.execute();

		switch (result)
		{
		case 0:
			level1.execute();
			break;
		case 1:
			level2.execute();
			break;
		case 3:
			std::cout << "Sem leaderboard ainda" << std::endl;
			break;
		default:
			break;
		}
	//}
	
	//level1.execute();
}