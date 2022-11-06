#include "Game.hpp"

int Ente::id_count = 0;

Jogo::Jogo() :
// criar elementos do jogo
window(800, 1500),
level1(&window)
{
	// criar tambem os outros gerenciadores, que ainda não foram implementados
}

void Jogo::executar()
{
	level1.executar(&window);
}