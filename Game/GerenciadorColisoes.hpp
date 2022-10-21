#pragma once

#include "Coordenada.hpp"
#include "Jogador.hpp"
#include "Janela.hpp"
#include <list>

/*

Implementando o tipo de colis�o padr�o (comparar todos os elemento 1 a 1)

� poss�vel, no futuro, para otimizar o jogo, 
realizar um sistema de colis�es que divide o espa�o e compara elementos dentro daque espa�o

*/

class GerenciadorColisoes
{
private:
	std::list<Entidade*> staticEntities;
	std::list<Entidade*> movingEntities;
	std::list<Jogador*> players;
public:
	GerenciadorColisoes() :
		staticEntities(),
		movingEntities()
	{}

	// posso ter uma fun��o gen�rica addEntity que tem sobrecarga de par�metros (a depender do tipo de entidade)
	void addStaticEntity(Entidade* pE) {
		staticEntities.push_back(pE);
	}
	void addMovingEntity(Entidade* pE) {
		movingEntities.push_back(pE);
	}
	void addPlayer(Jogador* pP) {
		players.push_back(pP);
	}

	void checaColisoes(Janela* janela);
	Coordenada<float> checaColisao(Entidade* e1, Entidade* e2);
};

