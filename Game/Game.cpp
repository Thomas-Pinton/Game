#include "Game.hpp"

GraphicManager* Being::pGraMan = NULL;
GraphicManager* GraphicManager::instance = NULL;
StateManager* Manager::StateManager::instance = NULL;

Game::Game() :
// criar elementos do jogo
// window(800, 960), (old window size)
window(800, 1200)
// window poderia ser criada no graphic manager
{
	grapMan = GraphicManager::getInstance();
	grapMan->setWindow(&window);
	Being::pGraMan = grapMan;
	pStateMan = Manager::StateManager::getInstance();
	pStateMan->push(new Menu());
}

Game::~Game()
{
	delete grapMan;
	delete pStateMan;
}

void Game::execute()
{
	while (window.config.isOpen())
	{
		pStateMan->execute();
	}		
}