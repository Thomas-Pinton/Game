#include "Level.hpp"

Level::Level(Window* pW, GraphicManager* pGM)
	: entities(),
	pWindow(pW),
	colMan(pW),
	tileMap(NULL)
{
	pGraMan = NULL;

	pGraMan = GraphicManager::getInstance();
	Being::pGraMan = GraphicManager::getInstance();

	Player* player1 = new Player;

	player1->setSize({ 32, 32 });
	player1->setPosition({ 50, 50 });

	pP = player1;

	entities.addEntity(player1);
	colMan.players.push_back(player1);
}

Level::~Level()
{
}

void Level::print()
{
	pGraMan->clear();

	entities.printEntities();

	pGraMan->display();

	pGraMan->updateDeltaTime();
}

void Level::manageColisions()
{
	colMan.checkColisions();
}
