#include "GerenciadorMovimento.hpp"

GerenciadorMovimento::GerenciadorMovimento()
{
}
void GerenciadorMovimento::atualizaPosicoes(float deltaTime)
{
	std::list<Entidade*>::iterator i;
	std::list<Jogador*>::iterator k;

	for (i = movingEntities.begin(); i != movingEntities.end(); i++)
		(*i)->atualizaPosicao(deltaTime);

	for (k = players.begin(); k != players.end(); k++)
	{
		(*k)->checkKeys();
		(*k)->atualizaPosicao(deltaTime);
	}


}