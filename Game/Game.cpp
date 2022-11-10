#include "Game.hpp"

int Being::id_count = 0;
GraphicManager* Being::pGraMan = NULL;

Game::Game() :
// criar elementos do jogo
window(800, 1500),
grapMan(&window),
level1(&window, &grapMan)
{
}

void Game::execute()
{
	level1.execute();
}