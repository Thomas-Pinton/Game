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
	std::cout << "Executando menu" << std::endl;
	menu.execute();
	std::cout << "Finished executing menu" << std::endl;
	//level1.execute();
}