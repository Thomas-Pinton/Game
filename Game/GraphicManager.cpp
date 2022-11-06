#include "GraphicManager.hpp"

GerenciadorGrafico::GerenciadorGrafico()
{
	window = NULL;
}

void GerenciadorGrafico::setJanela(Janela* pW)
{
	window = pW;
}

void GerenciadorGrafico::imprimeEnte(Ente* pE)
{
	window->config.draw(pE->rectangle);
}
/*
void GerenciadorGrafico::imprime() 
{
	// Clear screen
	window->config.clear();

	imprimeLista(staticEntities);
	imprimeLista(movingEntities);
	imprimeLista(players);

	window->config.display();
}

// posso criar uma lista minha, com template, que tem uma função imprime lista

void GerenciadorGrafico::imprimeLista(std::list<Ente*> l)
{
	std::list <Ente*>::iterator i;

	for (i = l.begin(); i != l.end(); i++) {
		window->config.draw((*i)->rectangle);
	}
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
*/
void GerenciadorGrafico::clear()
{
	window->config.clear();
}
void GerenciadorGrafico::display()
{
	window->config.display();
}