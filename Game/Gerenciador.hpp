#pragma once

#include <iostream>
#include <list>
#include "Jogador.hpp"

class Gerenciador
{
protected:
	static std::list<Entidade*> staticEntities;
	static std::list<Entidade*> movingEntities;
	static std::list<Jogador*> players;
public:
	Gerenciador() 
	{
	}
	void addStaticEntity(Entidade* pE) {
		staticEntities.push_back(pE);
	}
	void addMovingEntity(Entidade* pE) {
		movingEntities.push_back(pE);
	}
	void addPlayer(Jogador* pP) {
		players.push_back(pP);
	}
};
