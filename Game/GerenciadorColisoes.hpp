#pragma once

#include "Coordenada.hpp"
#include "Jogador.hpp"
#include <list>

/*

Implementando o tipo de colisão padrão (comparar todos os elemento 1 a 1)

É possível, no futuro, para otimizar o jogo, 
realizar um sistema de colisões que divide o espaço e compara elementos dentro daque espaço

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

	void addStaticEntity(Entidade* pE) {
		staticEntities.push_back(pE);
	}
	void addMovingEntity(Entidade* pE) {
		movingEntities.push_back(pE);
	}
	void addPlayer(Jogador* pP) {
		players.push_back(pP);
	}

	void checaColisoes(const int WIDTH, const int HEIGHT);
	Coordenada<float> checaColisao(Entidade* e1, Entidade* e2);
};

