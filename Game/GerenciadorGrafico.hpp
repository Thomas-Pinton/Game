#pragma once

#include "Gerenciador.hpp"
#include "Janela.hpp"

class GerenciadorGrafico : public Gerenciador
{
private:
	Janela* window;
public:
	void setJanela(Janela* pW);
	GerenciadorGrafico();
	void imprime();
	void imprimeLista(std::list<Entidade*> l);
	void imprimeLista(std::list<Jogador*> l);
};