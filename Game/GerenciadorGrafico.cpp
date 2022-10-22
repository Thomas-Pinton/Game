#include "GerenciadorGrafico.hpp"

GerenciadorGrafico::GerenciadorGrafico()
{
	window = NULL;
}

void GerenciadorGrafico::setJanela(Janela* pW)
{
	window = pW;
}

void GerenciadorGrafico::imprime() 
{
	// Clear screen
	window->config.clear();

	imprimeLista(staticEntities);
	imprimeLista(movingEntities);
	imprimeLista(players);

	window->config.display();
}

void GerenciadorGrafico::imprimeLista(std::list<Entidade*> l)
{
	std::list <Entidade*>::iterator i;

	for (i = l.begin(); i != l.end(); i++) {
		window->config.draw((*i)->rectangle);
	}
}

void GerenciadorGrafico::imprimeLista(std::list<Jogador*> l)
{
	std::list <Jogador*>::iterator i;

	for (i = l.begin(); i != l.end(); i++) {
		window->config.draw((*i)->rectangle);
	}
}
