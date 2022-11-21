#include "GerenciadorMovimento.hpp"

GerenciadorMovimento::GerenciadorMovimento()
{
}
void GerenciadorMovimento::atualizaPosicoes(float deltaTime)
{
	std::list<Entity*>::iterator i;
	std::list<Player*>::iterator k;

	for (i = enemies.begin(); i != enemies.end(); i++)
		(*i)->updatePosition(deltaTime);

	for (k = players.begin(); k != players.end(); k++)
	{
		(*k)->checkKeys();
		(*k)->updatePosition(deltaTime);
	}


}