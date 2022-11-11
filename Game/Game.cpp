#include "Game.hpp"

int Being::id_count = 0;
GraphicManager* Being::pGraMan = NULL;
GraphicManager* GraphicManager::instance = NULL;

Game::Game() :
// criar elementos do jogo
window(800, 1500),
level1(&window, GraphicManager::getInstance())
{
	grapMan = GraphicManager::getInstance();
	grapMan->setWindow(&window);
}

Game::~Game()
{
	delete grapMan->getInstance();
}

void Game::execute()
{
	level1.execute();
}