#pragma once

#include <iostream>
#include <list>
#include "Jogador.hpp"
#include "Tile.hpp"
#include "Janela.hpp"

class Gerenciador
{
protected:
	static std::list<Ente*> staticEntities;
	
	
public:
	// momentâneo
	static std::list<Jogador*> players;
	static std::list<Entidade*> movingEntities;

	Gerenciador();

	Gerenciador(Janela* window);

	void addStaticEntity(Ente* pE);

	void addMovingEntity(Entidade* pE);

	void addPlayer(Jogador* pP);

};
