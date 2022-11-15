#include "Game.hpp"

int Being::id_count = 0;
GraphicManager* Being::pGraMan = NULL;
GraphicManager* GraphicManager::instance = NULL;

Game::Game() :
// criar elementos do jogo
window(800, 960),
level1(&window, GraphicManager::getInstance()),
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
	
	int result = menu.execute();

	switch (result)
	{
	case 0:
		level1.execute();
		break;
	case 1:
		std::cout << "Sem level 2 ainda" << std::endl;
	case 2:
		std::cout << "Sem leaderboard ainda" << std::endl;
	default:
		break;
	}
	
	//level1.execute();
}