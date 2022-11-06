#include "Game.hpp"

int Being::id_count = 0;

Game::Game() :
// criar elementos do jogo
window(800, 1500),
level1(&window)
{
	// criar tambem os outros gerenciadores, que ainda n�o foram implementados
}

void Game::execute()
{
	level1.execute(&window);
}