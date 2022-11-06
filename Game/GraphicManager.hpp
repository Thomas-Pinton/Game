#pragma once

#include "Window.hpp"
#include "Being.hpp"

class GerenciadorGrafico
{
private:
	Janela* window;
public:
	void setJanela(Janela* pW);
	GerenciadorGrafico();

	//void imprime();
	void imprimeEnte(Ente* pE);
	//void imprimeLista(std::list<Ente*> l);
	//void imprimeLista(std::list<Entidade*> l);
	//void imprimeLista(std::list<Jogador*> l);

	void clear();
	void display();
};